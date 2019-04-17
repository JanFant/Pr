#include "scm.h"
extern  func_ext1();
// АП
//  Результат трансляции схемы D:\md\pti\pr\scm\scheme\scm.tpr

#define PBLENGTH 8192
#ifndef SIMUL_MODE
char EEPROMType = 2;/*0 - absent, 1 - external, 2 - internal, 3 - misc*/
#else
char *SchemaName = "D:\md\pti\pr\scm\scheme\scm.tpr";
#endif
extern void InitInternalParametr(void);
extern void reInit_Signals(void);
#define NEW_TEPROL
#include "spaps.h"
#include <Mem.h>

void UpdateTakt(void);
#define CONTROL
#include <signals.h>
#define PBSTART ((uspaint8 *)SignalBuffer)

uspaint8 *SignalBuffer;
#ifdef SIMUL_MODE
  uspaint8 *IntEEPROMBuffer;
#else
  extern uspaint8 IntEEPROMBuffer[];
#endif

//__int8 *ExtEEPROMBuffer;
uspaint8 *InternalBuf;
uspaint8 *SpaEEPROMBuf;
unsigned char EEPROMChanged;
// static ssbool FirstEnterFlag={0,0};
#ifndef SIMUL_MODE
static unsigned int InvertionFailureCounter = 0;
extern unsigned char* EEPROMInSignal;
extern unsigned char* EEPROMOutSignal;
void UpdateEEPROM(unsigned char* EEPROMInSignal, unsigned char* EEPROMOutSignal);
extern unsigned char WHICH_SIDE;
void LoadSignals(void);
void SplitEEPROMs(void);
void InvertSignals(void);
void InitSignals(void);
void CheckSignals(void);
void watch_dg(void);
unsigned int CycleStopped = 1;
#else
#include <neweprom.h>

extern "C" void __declspec(dllexport) __stdcall GetAddress(TStringList *sl);
extern "C" void __declspec(dllexport) __stdcall NewTakt(float ImportTakt);
extern "C" void __declspec(dllexport) __stdcall NewSysTime(unsigned long);
extern "C" void __declspec(dllexport) __stdcall simulmain(DVE_Parametrs *Par);
extern "C" void __declspec(dllexport) __stdcall CheckSignals(DVE_Parametrs *Par);
extern "C" void __declspec(dllexport) __stdcall InitSignals();
extern "C" void __declspec(dllexport) __stdcall SplitEEPROMs(DVE_Parametrs *Par);
extern "C" void __declspec(dllexport) __stdcall GetMainHinst(HINSTANCE,__int8*,__int8*,__int8*,__int8*);
void(__stdcall *PutErrors)( char*,char**);
char (__stdcall *Set_Eeprom)(char filenum, int fileoffs, void* value, int size, int type);
char (__stdcall *Get_Eeprom)(char filenum, int fileoffs, void* value, int size, int type);
long (__stdcall *GetFSize)( char filenum );
void (__stdcall *GetBranch)( char*,void*,int,int,int );

void UnloadSignals();
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fwdreason, LPVOID lpvReserved)
{return 1;}
DVE_Par *NewPar, *MyPar;
DVE_Parametrs *AllParams, *EEPROMParams;
float takt;// время в секундах
__int16 itakt;// время в миллисекундах
__int16 dtakt;// время в десятках миллисекунд
unsigned long sys_time;// системное время в милисекундах, от запуска или сброса
void __stdcall NewTakt(float ImportTakt)
{
  takt = ImportTakt; 
  itakt = takt*1000; 
  dtakt = itakt/10; 
}

void __stdcall NewSysTime(unsigned long st)
{ 
  sys_time = st; 
}

void ParExchange(char* Name, int Type, void* Adres, char* Commentary, char InOut)
{
   static char state = 0;

   if( state == 1 && !InOut )
    state = 2;
   else
    if( !state && InOut == 1 )
     state = 1;
    else
     if( state == 2 && InOut == 1 )
       state = 3;



   DVE_Par *tpar = NULL, *tpar1 = NULL;
   NewPar = new DVE_Par();
   if( Name[0] >= '0' && Name[0] <= '9' )
    {
      NewPar->Name[0] = '_';
      strncpy(NewPar->Name+1, Name, 30);
      NewPar->Name[31] = 0;
    }
   else
    {
      strncpy(NewPar->Name, Name, 31);
      NewPar->Name[31] = 0;
    }

   if( state == 2 )
    {
      // все необходимые параметры уже созданы и уложены в AllPars
      // и теперь можно разрулить синонимы
      AnsiString ts = AnsiString(NewPar->Name);
      tpar = AllParams->FindParam(ts.c_str());
      if( tpar )
       {
         if( ts.Pos("syn_") )
         {
           ts = ts.SubString(ts.Pos("syn_")+4, 1024);
         }
         else
          {
         if( ts.Pos('_') == 1 )
          ts = "syn" + ts;
         else
           ts = "syn_" + ts;
          }

         tpar1 = AllParams->FindParam(ts.c_str());
         if( tpar1 && tpar1->Offset != tpar->Offset )
          {
//            ofstream FileStrm("Syn_errs.log", ios::app);
//            FileStrm << tpar->Name << " " << tpar1->Name << endl;
            tpar1->Offset = tpar->Offset;
          }
       }
    }

   strncpy(NewPar->Comment, Commentary, 255); NewPar->Comment[255] = 0;
   NewPar->Type = Type;
   NewPar->Offset = Adres;
   switch( Type )
    {
      case _LONG: case _REAL:  NewPar->Length = 5; break;
      case _INT:   NewPar->Length = 3; break;
      case _BYTE: case _LOGIC: NewPar->Length = 2; break;
    }

   MyPar = DVE_CreateParams(NewPar, AllParams->ArrayParams);
   if( MyPar != NULL )
    {
      if( MyPar->Type != Type )
       ShowMessage(AnsiString("Несовпадение типа параметра ") + AnsiString(Name) + AnsiString(" в схеме ") + AnsiString(SchemaName));
      else
       if( Adres != MyPar->Offset )
        if( !InOut )
         switch( Type )
          {
            case _REAL:  *(psfloat)Adres << *MyPar; break;
            case _INT:   *(psint)Adres   << *MyPar; break;
            case _LONG:  *(pslong)Adres  << *MyPar; break;
            case _LOGIC: *(psbool)Adres  << *MyPar; break;
            case _BYTE:  *(pschar)Adres  << *MyPar; break;
          }
         else
          switch( Type )
           {
             case _REAL:  *MyPar << *(psfloat)Adres; break;
             case _INT:   *MyPar << *(psint)Adres; break;
             case _LONG:  *MyPar << *(pslong)Adres; break;
             case _LOGIC: *MyPar << *(psbool)Adres; break;
             case _BYTE:  *MyPar << *(pschar)Adres; break;
           }
    }
   delete NewPar;
}

#endif
static int counter;

/* Объявление функций */
#include <ampl.h>
#include <andn.h>
#include <asmot.h>
#include <azbars.h>
#include <bol.h>
#include <fsubo.h>
#include <fsumo.h>
#include <inf.h>
#include <ktoenc.h>
#include <lk.h>
#include <mod1.h>
#include <noto.h>
#include <or2.h>
#include <orn.h>
#include <orrsim.h>
#include <ovb1.h>
#include <react.h>
#include <rs.h>
#include <to3val.h>
#include <toao.h>
#include <twobool.h>
#include <vchs.h>
#include <zpfs.h>

/* Определение внутренних параметров */
#define bFirstEnterFlag (*((psbool)(InternalBuf+0x0)))
#define internal1_m870_Chim0 (*((psfloat)(InternalBuf+0x2))) /*измеренная частота импульсов камеры Гц*/
#define internal1_m860_Chim0 (*((psfloat)(InternalBuf+0x7))) /*измеренная частота импульсов камеры Гц*/
#define internal1_m852_Chim0 (*((psfloat)(InternalBuf+0xC))) /*измеренная частота импульсов камеры Гц*/
#define internal1_m807_Out10 (*((psbool)(InternalBuf+0x11))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m806_Out10 (*((psbool)(InternalBuf+0x13))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m989_Out10 (*((psbool)(InternalBuf+0x15))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m988_Out10 (*((psbool)(InternalBuf+0x17))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m987_Out10 (*((psbool)(InternalBuf+0x19))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m986_Out10 (*((psbool)(InternalBuf+0x1B))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m666_Out10 (*((psbool)(InternalBuf+0x1D))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m665_Out10 (*((psbool)(InternalBuf+0x1F))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m644_Out10 (*((psbool)(InternalBuf+0x21))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m643_Out10 (*((psbool)(InternalBuf+0x23))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m664_Out10 (*((psbool)(InternalBuf+0x25))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m663_Out10 (*((psbool)(InternalBuf+0x27))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m642_Out10 (*((psbool)(InternalBuf+0x29))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m641_Out10 (*((psbool)(InternalBuf+0x2B))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m508_Out10 (*((psbool)(InternalBuf+0x2D))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m524_Out10 (*((psbool)(InternalBuf+0x2F))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m396_Out10 (*((psbool)(InternalBuf+0x31))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m469_q0 (*((psbool)(InternalBuf+0x33))) /*q0 - внутренний параметр*/
#define internal1_m470_q0 (*((psbool)(InternalBuf+0x35))) /*q0 - внутренний параметр*/
#define internal1_m457_q0 (*((psbool)(InternalBuf+0x37))) /*q0 - внутренний параметр*/
#define internal1_m458_q0 (*((psbool)(InternalBuf+0x39))) /*q0 - внутренний параметр*/
#define internal1_m617_tx (*((psfloat)(InternalBuf+0x3B))) /*tx - время накопленное сек*/
#define internal1_m617_y0 (*((pschar)(InternalBuf+0x40))) /*y0*/
#define internal1_m605_tx (*((psfloat)(InternalBuf+0x42))) /*tx - время накопленное сек*/
#define internal1_m605_y0 (*((pschar)(InternalBuf+0x47))) /*y0*/
#define internal1_m593_tx (*((psfloat)(InternalBuf+0x49))) /*tx - время накопленное сек*/
#define internal1_m593_y0 (*((pschar)(InternalBuf+0x4E))) /*y0*/
#define internal1_m591_tx (*((psfloat)(InternalBuf+0x50))) /*tx - время накопленное сек*/
#define internal1_m591_y0 (*((pschar)(InternalBuf+0x55))) /*y0*/
#define internal1_m202_Out10 (*((psbool)(InternalBuf+0x57))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m218_Out10 (*((psbool)(InternalBuf+0x59))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m41_Out10 (*((psbool)(InternalBuf+0x5B))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m56_Out10 (*((psbool)(InternalBuf+0x5D))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m960_Out10 (*((psbool)(InternalBuf+0x5F))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m957_Out10 (*((psbool)(InternalBuf+0x61))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m956_Out10 (*((psbool)(InternalBuf+0x63))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m959_Xtek0 (*((psfloat)(InternalBuf+0x65))) /*Xtek0 - положение механизма на прошлом шаге, мм*/
#define internal1_m942_Xtek0 (*((psfloat)(InternalBuf+0x6A))) /*Xtek0 - положение механизма на прошлом шаге, мм*/
#define internal1_m943_Out10 (*((psbool)(InternalBuf+0x6F))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m940_Out10 (*((psbool)(InternalBuf+0x71))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m939_Out10 (*((psbool)(InternalBuf+0x73))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m1027_Out10 (*((psbool)(InternalBuf+0x75))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m1008_Out10 (*((psbool)(InternalBuf+0x77))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m1007_Out10 (*((psbool)(InternalBuf+0x79))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m1006_Out10 (*((psbool)(InternalBuf+0x7B))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m828_Out10 (*((psbool)(InternalBuf+0x7D))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m830_Out10 (*((psbool)(InternalBuf+0x7F))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m827_Out10 (*((psbool)(InternalBuf+0x81))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m829_Out10 (*((psbool)(InternalBuf+0x83))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m803_Out10 (*((psbool)(InternalBuf+0x85))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m804_Out10 (*((psbool)(InternalBuf+0x87))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m802_Out10 (*((psbool)(InternalBuf+0x89))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m801_Out10 (*((psbool)(InternalBuf+0x8B))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m1022_Out10 (*((psbool)(InternalBuf+0x8D))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m974_Out10 (*((psbool)(InternalBuf+0x8F))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m973_Out10 (*((psbool)(InternalBuf+0x91))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m972_Out10 (*((psbool)(InternalBuf+0x93))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m971_Out10 (*((psbool)(InternalBuf+0x95))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m1023_Out10 (*((psbool)(InternalBuf+0x97))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m1004_Out10 (*((psbool)(InternalBuf+0x99))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m805_Out10 (*((psbool)(InternalBuf+0x9B))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m1005_Out10 (*((psbool)(InternalBuf+0x9D))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m1003_Out10 (*((psbool)(InternalBuf+0x9F))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m1024_Out10 (*((psbool)(InternalBuf+0xA1))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m1002_Out10 (*((psbool)(InternalBuf+0xA3))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m985_Out10 (*((psbool)(InternalBuf+0xA5))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m970_Out10 (*((psbool)(InternalBuf+0xA7))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m525_Out10 (*((psbool)(InternalBuf+0xA9))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m406_Xtek0 (*((psfloat)(InternalBuf+0xAB))) /*Xtek0 - положение механизма на прошлом шаге, мм*/
#define internal1_m397_Out10 (*((psbool)(InternalBuf+0xB0))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m399_Out10 (*((psbool)(InternalBuf+0xB2))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m398_Out10 (*((psbool)(InternalBuf+0xB4))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m843_Out10 (*((psbool)(InternalBuf+0xB6))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m844_Out10 (*((psbool)(InternalBuf+0xB8))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m842_Out10 (*((psbool)(InternalBuf+0xBA))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m1026_Out10 (*((psbool)(InternalBuf+0xBC))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m679_Out10 (*((psbool)(InternalBuf+0xBE))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m680_Out10 (*((psbool)(InternalBuf+0xC0))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m677_Out10 (*((psbool)(InternalBuf+0xC2))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m678_Out10 (*((psbool)(InternalBuf+0xC4))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m541_Out10 (*((psbool)(InternalBuf+0xC6))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m540_Out10 (*((psbool)(InternalBuf+0xC8))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m824_Xtek0 (*((psfloat)(InternalBuf+0xCA))) /*Xtek0 - положение механизма на прошлом шаге, мм*/
#define internal1_m826_Xtek0 (*((psfloat)(InternalBuf+0xCF))) /*Xtek0 - положение механизма на прошлом шаге, мм*/
#define internal1_m676_Out10 (*((psbool)(InternalBuf+0xD4))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m660_Out10 (*((psbool)(InternalBuf+0xD6))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m640_Out10 (*((psbool)(InternalBuf+0xD8))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m659_Out10 (*((psbool)(InternalBuf+0xDA))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m639_Out10 (*((psbool)(InternalBuf+0xDC))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m327_Out10 (*((psbool)(InternalBuf+0xDE))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m326_Out10 (*((psbool)(InternalBuf+0xE0))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m311_Out10 (*((psbool)(InternalBuf+0xE2))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m310_Out10 (*((psbool)(InternalBuf+0xE4))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m542_Out10 (*((psbool)(InternalBuf+0xE6))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m340_Out10 (*((psbool)(InternalBuf+0xE8))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m324_Xtek0 (*((psfloat)(InternalBuf+0xEA))) /*Xtek0 - положение механизма на прошлом шаге, мм*/
#define internal1_m339_Out10 (*((psbool)(InternalBuf+0xEF))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m337_Out10 (*((psbool)(InternalBuf+0xF1))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m316_Xtek0 (*((psfloat)(InternalBuf+0xF3))) /*Xtek0 - положение механизма на прошлом шаге, мм*/
#define internal1_m338_Out10 (*((psbool)(InternalBuf+0xF8))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m309_Out10 (*((psbool)(InternalBuf+0xFA))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m325_Out10 (*((psbool)(InternalBuf+0xFC))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m418_Out10 (*((psbool)(InternalBuf+0xFE))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m419_Xtek0 (*((psfloat)(InternalBuf+0x100))) /*Xtek0 - положение механизма на прошлом шаге, мм*/
#define internal1_m417_Out10 (*((psbool)(InternalBuf+0x105))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m416_Out10 (*((psbool)(InternalBuf+0x107))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m415_Out10 (*((psbool)(InternalBuf+0x109))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m1025_Out10 (*((psbool)(InternalBuf+0x10B))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m144_Out10 (*((psbool)(InternalBuf+0x10D))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m143_Out10 (*((psbool)(InternalBuf+0x10F))) /*Out10 (psbool) - прошлое значение выходного сигнала*/
#define internal1_m191_tx (*((psint)(InternalBuf+0x111))) /*tx - внутренний параметр*/
#define internal1_m30_tx (*((psint)(InternalBuf+0x114))) /*tx - внутренний параметр*/
#define internal1_m461_X00 (*((psfloat)(InternalBuf+0x117))) /* X00 - текущая координата механизма*/
#define internal1_m461_V00 (*((psfloat)(InternalBuf+0x11C))) /* V00 - текущая скорость механизма*/
#define internal1_m461_Pav0 (*((psbool)(InternalBuf+0x121))) /* - Пер.аварийный выключатель механизма*/
#define internal1_m461_Zav0 (*((psbool)(InternalBuf+0x123))) /* - Зад.аварийный выключатель механизма*/
#define internal1_m461_Pv0 (*((psbool)(InternalBuf+0x125))) /* - Пер. выключатель механизма*/
#define internal1_m461_Zv0 (*((psbool)(InternalBuf+0x127))) /* - Зад. выключатель механизма*/
#define internal1_m461_RA00 (*((psbool)(InternalBuf+0x129))) /* - последнее задание вперед*/
#define internal1_m461_RA10 (*((psbool)(InternalBuf+0x12B))) /* - последнее задание назад*/
#define internal1_m461_MyFirstEnterFlag (*((psbool)(InternalBuf+0x12D))) /*MyFirstEnterFlag*/
#define internal1_m473_X00 (*((psfloat)(InternalBuf+0x12F))) /* X00 - текущая координата механизма*/
#define internal1_m473_V00 (*((psfloat)(InternalBuf+0x134))) /* V00 - текущая скорость механизма*/
#define internal1_m473_Pav0 (*((psbool)(InternalBuf+0x139))) /* - Пер.аварийный выключатель механизма*/
#define internal1_m473_Zav0 (*((psbool)(InternalBuf+0x13B))) /* - Зад.аварийный выключатель механизма*/
#define internal1_m473_Pv0 (*((psbool)(InternalBuf+0x13D))) /* - Пер. выключатель механизма*/
#define internal1_m473_Zv0 (*((psbool)(InternalBuf+0x13F))) /* - Зад. выключатель механизма*/
#define internal1_m473_RA00 (*((psbool)(InternalBuf+0x141))) /* - последнее задание вперед*/
#define internal1_m473_RA10 (*((psbool)(InternalBuf+0x143))) /* - последнее задание назад*/
#define internal1_m473_MyFirstEnterFlag (*((psbool)(InternalBuf+0x145))) /*MyFirstEnterFlag*/
#define internal1_m463_X00 (*((psfloat)(InternalBuf+0x147))) /* X00 - текущая координата механизма*/
#define internal1_m463_V00 (*((psfloat)(InternalBuf+0x14C))) /* V00 - текущая скорость механизма*/
#define internal1_m463_Pav0 (*((psbool)(InternalBuf+0x151))) /* - Пер.аварийный выключатель механизма*/
#define internal1_m463_Zav0 (*((psbool)(InternalBuf+0x153))) /* - Зад.аварийный выключатель механизма*/
#define internal1_m463_Pv0 (*((psbool)(InternalBuf+0x155))) /* - Пер. выключатель механизма*/
#define internal1_m463_Zv0 (*((psbool)(InternalBuf+0x157))) /* - Зад. выключатель механизма*/
#define internal1_m463_RA00 (*((psbool)(InternalBuf+0x159))) /* - последнее задание вперед*/
#define internal1_m463_RA10 (*((psbool)(InternalBuf+0x15B))) /* - последнее задание назад*/
#define internal1_m463_MyFirstEnterFlag (*((psbool)(InternalBuf+0x15D))) /*MyFirstEnterFlag*/
#define internal1_m596_X00 (*((psfloat)(InternalBuf+0x15F))) /* X00 - текущая координата механизма*/
#define internal1_m596_V00 (*((psfloat)(InternalBuf+0x164))) /* V00 - текущая скорость механизма*/
#define internal1_m596_Pav0 (*((psbool)(InternalBuf+0x169))) /* - Пер.аварийный выключатель механизма*/
#define internal1_m596_Zav0 (*((psbool)(InternalBuf+0x16B))) /* - Зад.аварийный выключатель механизма*/
#define internal1_m596_Pv0 (*((psbool)(InternalBuf+0x16D))) /* - Пер. выключатель механизма*/
#define internal1_m596_Zv0 (*((psbool)(InternalBuf+0x16F))) /* - Зад. выключатель механизма*/
#define internal1_m596_RA00 (*((psbool)(InternalBuf+0x171))) /* - последнее задание вперед*/
#define internal1_m596_RA10 (*((psbool)(InternalBuf+0x173))) /* - последнее задание назад*/
#define internal1_m596_MyFirstEnterFlag (*((psbool)(InternalBuf+0x175))) /*MyFirstEnterFlag*/
#define internal1_m595_X00 (*((psfloat)(InternalBuf+0x177))) /* X00 - текущая координата механизма*/
#define internal1_m595_V00 (*((psfloat)(InternalBuf+0x17C))) /* V00 - текущая скорость механизма*/
#define internal1_m595_Pav0 (*((psbool)(InternalBuf+0x181))) /* - Пер.аварийный выключатель механизма*/
#define internal1_m595_Zav0 (*((psbool)(InternalBuf+0x183))) /* - Зад.аварийный выключатель механизма*/
#define internal1_m595_Pv0 (*((psbool)(InternalBuf+0x185))) /* - Пер. выключатель механизма*/
#define internal1_m595_Zv0 (*((psbool)(InternalBuf+0x187))) /* - Зад. выключатель механизма*/
#define internal1_m595_RA00 (*((psbool)(InternalBuf+0x189))) /* - последнее задание вперед*/
#define internal1_m595_RA10 (*((psbool)(InternalBuf+0x18B))) /* - последнее задание назад*/
#define internal1_m595_MyFirstEnterFlag (*((psbool)(InternalBuf+0x18D))) /*MyFirstEnterFlag*/
#define internal1_m583_X00 (*((psfloat)(InternalBuf+0x18F))) /* X00 - текущая координата механизма*/
#define internal1_m583_V00 (*((psfloat)(InternalBuf+0x194))) /* V00 - текущая скорость механизма*/
#define internal1_m583_Pav0 (*((psbool)(InternalBuf+0x199))) /* - Пер.аварийный выключатель механизма*/
#define internal1_m583_Zav0 (*((psbool)(InternalBuf+0x19B))) /* - Зад.аварийный выключатель механизма*/
#define internal1_m583_Pv0 (*((psbool)(InternalBuf+0x19D))) /* - Пер. выключатель механизма*/
#define internal1_m583_Zv0 (*((psbool)(InternalBuf+0x19F))) /* - Зад. выключатель механизма*/
#define internal1_m583_RA00 (*((psbool)(InternalBuf+0x1A1))) /* - последнее задание вперед*/
#define internal1_m583_RA10 (*((psbool)(InternalBuf+0x1A3))) /* - последнее задание назад*/
#define internal1_m583_MyFirstEnterFlag (*((psbool)(InternalBuf+0x1A5))) /*MyFirstEnterFlag*/
#define internal1_m582_X00 (*((psfloat)(InternalBuf+0x1A7))) /* X00 - текущая координата механизма*/
#define internal1_m582_V00 (*((psfloat)(InternalBuf+0x1AC))) /* V00 - текущая скорость механизма*/
#define internal1_m582_Pav0 (*((psbool)(InternalBuf+0x1B1))) /* - Пер.аварийный выключатель механизма*/
#define internal1_m582_Zav0 (*((psbool)(InternalBuf+0x1B3))) /* - Зад.аварийный выключатель механизма*/
#define internal1_m582_Pv0 (*((psbool)(InternalBuf+0x1B5))) /* - Пер. выключатель механизма*/
#define internal1_m582_Zv0 (*((psbool)(InternalBuf+0x1B7))) /* - Зад. выключатель механизма*/
#define internal1_m582_RA00 (*((psbool)(InternalBuf+0x1B9))) /* - последнее задание вперед*/
#define internal1_m582_RA10 (*((psbool)(InternalBuf+0x1BB))) /* - последнее задание назад*/
#define internal1_m582_MyFirstEnterFlag (*((psbool)(InternalBuf+0x1BD))) /*MyFirstEnterFlag*/
#define internal1_m625_y0 (*((psfloat)(InternalBuf+0x1BF))) /*y0 - внутренний параметр*/
#define internal1_m789_Chim0 (*((psfloat)(InternalBuf+0x1C4))) /*измеренная частота импульсов камеры Гц*/
#define internal1_m780_Chim0 (*((psfloat)(InternalBuf+0x1C9))) /*измеренная частота импульсов камеры Гц*/
#define internal1_m772_Chim0 (*((psfloat)(InternalBuf+0x1CE))) /*измеренная частота импульсов камеры Гц*/
#define internal1_m763_Chim0 (*((psfloat)(InternalBuf+0x1D3))) /*измеренная частота импульсов камеры Гц*/
#define internal1_m754_Chim0 (*((psfloat)(InternalBuf+0x1D8))) /*измеренная частота импульсов камеры Гц*/
#define internal1_m746_Chim0 (*((psfloat)(InternalBuf+0x1DD))) /*измеренная частота импульсов камеры Гц*/
#define internal1_m737_Chim0 (*((psfloat)(InternalBuf+0x1E2))) /*измеренная частота импульсов камеры Гц*/
#define internal1_m728_Chim0 (*((psfloat)(InternalBuf+0x1E7))) /*измеренная частота импульсов камеры Гц*/
#define internal1_m720_Chim0 (*((psfloat)(InternalBuf+0x1EC))) /*измеренная частота импульсов камеры Гц*/
#define internal1_m711_Chim0 (*((psfloat)(InternalBuf+0x1F1))) /*измеренная частота импульсов камеры Гц*/
#define internal1_m702_Chim0 (*((psfloat)(InternalBuf+0x1F6))) /*измеренная частота импульсов камеры Гц*/
#define internal1_m692_Chim0 (*((psfloat)(InternalBuf+0x1FB))) /*измеренная частота импульсов камеры Гц*/
#define internal1_m570_X00 (*((psfloat)(InternalBuf+0x200))) /* X00 - текущая координата механизма*/
#define internal1_m570_V00 (*((psfloat)(InternalBuf+0x205))) /* V00 - текущая скорость механизма*/
#define internal1_m570_Pav0 (*((psbool)(InternalBuf+0x20A))) /* - Пер.аварийный выключатель механизма*/
#define internal1_m570_Zav0 (*((psbool)(InternalBuf+0x20C))) /* - Зад.аварийный выключатель механизма*/
#define internal1_m570_Pv0 (*((psbool)(InternalBuf+0x20E))) /* - Пер. выключатель механизма*/
#define internal1_m570_Zv0 (*((psbool)(InternalBuf+0x210))) /* - Зад. выключатель механизма*/
#define internal1_m570_RA00 (*((psbool)(InternalBuf+0x212))) /* - последнее задание вперед*/
#define internal1_m570_RA10 (*((psbool)(InternalBuf+0x214))) /* - последнее задание назад*/
#define internal1_m570_MyFirstEnterFlag (*((psbool)(InternalBuf+0x216))) /*MyFirstEnterFlag*/
#define internal1_m556_X00 (*((psfloat)(InternalBuf+0x218))) /* X00 - текущая координата механизма*/
#define internal1_m556_V00 (*((psfloat)(InternalBuf+0x21D))) /* V00 - текущая скорость механизма*/
#define internal1_m556_Pav0 (*((psbool)(InternalBuf+0x222))) /* - Пер.аварийный выключатель механизма*/
#define internal1_m556_Zav0 (*((psbool)(InternalBuf+0x224))) /* - Зад.аварийный выключатель механизма*/
#define internal1_m556_Pv0 (*((psbool)(InternalBuf+0x226))) /* - Пер. выключатель механизма*/
#define internal1_m556_Zv0 (*((psbool)(InternalBuf+0x228))) /* - Зад. выключатель механизма*/
#define internal1_m556_RA00 (*((psbool)(InternalBuf+0x22A))) /* - последнее задание вперед*/
#define internal1_m556_RA10 (*((psbool)(InternalBuf+0x22C))) /* - последнее задание назад*/
#define internal1_m556_MyFirstEnterFlag (*((psbool)(InternalBuf+0x22E))) /*MyFirstEnterFlag*/
#define internal1_m447_X00 (*((psfloat)(InternalBuf+0x230))) /* X00 - текущая координата механизма*/
#define internal1_m447_V00 (*((psfloat)(InternalBuf+0x235))) /* V00 - текущая скорость механизма*/
#define internal1_m447_Pav0 (*((psbool)(InternalBuf+0x23A))) /* - Пер.аварийный выключатель механизма*/
#define internal1_m447_Zav0 (*((psbool)(InternalBuf+0x23C))) /* - Зад.аварийный выключатель механизма*/
#define internal1_m447_Pv0 (*((psbool)(InternalBuf+0x23E))) /* - Пер. выключатель механизма*/
#define internal1_m447_Zv0 (*((psbool)(InternalBuf+0x240))) /* - Зад. выключатель механизма*/
#define internal1_m447_RA00 (*((psbool)(InternalBuf+0x242))) /* - последнее задание вперед*/
#define internal1_m447_RA10 (*((psbool)(InternalBuf+0x244))) /* - последнее задание назад*/
#define internal1_m447_MyFirstEnterFlag (*((psbool)(InternalBuf+0x246))) /*MyFirstEnterFlag*/
#define internal1_m433_X00 (*((psfloat)(InternalBuf+0x248))) /* X00 - текущая координата механизма*/
#define internal1_m433_V00 (*((psfloat)(InternalBuf+0x24D))) /* V00 - текущая скорость механизма*/
#define internal1_m433_Pav0 (*((psbool)(InternalBuf+0x252))) /* - Пер.аварийный выключатель механизма*/
#define internal1_m433_Zav0 (*((psbool)(InternalBuf+0x254))) /* - Зад.аварийный выключатель механизма*/
#define internal1_m433_Pv0 (*((psbool)(InternalBuf+0x256))) /* - Пер. выключатель механизма*/
#define internal1_m433_Zv0 (*((psbool)(InternalBuf+0x258))) /* - Зад. выключатель механизма*/
#define internal1_m433_RA00 (*((psbool)(InternalBuf+0x25A))) /* - последнее задание вперед*/
#define internal1_m433_RA10 (*((psbool)(InternalBuf+0x25C))) /* - последнее задание назад*/
#define internal1_m433_MyFirstEnterFlag (*((psbool)(InternalBuf+0x25E))) /*MyFirstEnterFlag*/
#define internal1_m484_X00 (*((psfloat)(InternalBuf+0x260))) /* X00 - текущая координата механизма*/
#define internal1_m484_V00 (*((psfloat)(InternalBuf+0x265))) /* V00 - текущая скорость механизма*/
#define internal1_m484_Pav0 (*((psbool)(InternalBuf+0x26A))) /* - Пер.аварийный выключатель механизма*/
#define internal1_m484_Zav0 (*((psbool)(InternalBuf+0x26C))) /* - Зад.аварийный выключатель механизма*/
#define internal1_m484_Pv0 (*((psbool)(InternalBuf+0x26E))) /* - Пер. выключатель механизма*/
#define internal1_m484_Zv0 (*((psbool)(InternalBuf+0x270))) /* - Зад. выключатель механизма*/
#define internal1_m484_RA00 (*((psbool)(InternalBuf+0x272))) /* - последнее задание вперед*/
#define internal1_m484_RA10 (*((psbool)(InternalBuf+0x274))) /* - последнее задание назад*/
#define internal1_m484_MyFirstEnterFlag (*((psbool)(InternalBuf+0x276))) /*MyFirstEnterFlag*/
#define internal1_m385_X00 (*((psfloat)(InternalBuf+0x278))) /* X00 - текущая координата механизма*/
#define internal1_m385_V00 (*((psfloat)(InternalBuf+0x27D))) /* V00 - текущая скорость механизма*/
#define internal1_m385_Pav0 (*((psbool)(InternalBuf+0x282))) /* - Пер.аварийный выключатель механизма*/
#define internal1_m385_Zav0 (*((psbool)(InternalBuf+0x284))) /* - Зад.аварийный выключатель механизма*/
#define internal1_m385_Pv0 (*((psbool)(InternalBuf+0x286))) /* - Пер. выключатель механизма*/
#define internal1_m385_Zv0 (*((psbool)(InternalBuf+0x288))) /* - Зад. выключатель механизма*/
#define internal1_m385_RA00 (*((psbool)(InternalBuf+0x28A))) /* - последнее задание вперед*/
#define internal1_m385_RA10 (*((psbool)(InternalBuf+0x28C))) /* - последнее задание назад*/
#define internal1_m385_MyFirstEnterFlag (*((psbool)(InternalBuf+0x28E))) /*MyFirstEnterFlag*/
#define internal1_m370_X00 (*((psfloat)(InternalBuf+0x290))) /* X00 - текущая координата механизма*/
#define internal1_m370_V00 (*((psfloat)(InternalBuf+0x295))) /* V00 - текущая скорость механизма*/
#define internal1_m370_Pav0 (*((psbool)(InternalBuf+0x29A))) /* - Пер.аварийный выключатель механизма*/
#define internal1_m370_Zav0 (*((psbool)(InternalBuf+0x29C))) /* - Зад.аварийный выключатель механизма*/
#define internal1_m370_Pv0 (*((psbool)(InternalBuf+0x29E))) /* - Пер. выключатель механизма*/
#define internal1_m370_Zv0 (*((psbool)(InternalBuf+0x2A0))) /* - Зад. выключатель механизма*/
#define internal1_m370_RA00 (*((psbool)(InternalBuf+0x2A2))) /* - последнее задание вперед*/
#define internal1_m370_RA10 (*((psbool)(InternalBuf+0x2A4))) /* - последнее задание назад*/
#define internal1_m370_MyFirstEnterFlag (*((psbool)(InternalBuf+0x2A6))) /*MyFirstEnterFlag*/
#define internal1_m354_X00 (*((psfloat)(InternalBuf+0x2A8))) /* X00 - текущая координата механизма*/
#define internal1_m354_V00 (*((psfloat)(InternalBuf+0x2AD))) /* V00 - текущая скорость механизма*/
#define internal1_m354_Pav0 (*((psbool)(InternalBuf+0x2B2))) /* - Пер.аварийный выключатель механизма*/
#define internal1_m354_Zav0 (*((psbool)(InternalBuf+0x2B4))) /* - Зад.аварийный выключатель механизма*/
#define internal1_m354_Pv0 (*((psbool)(InternalBuf+0x2B6))) /* - Пер. выключатель механизма*/
#define internal1_m354_Zv0 (*((psbool)(InternalBuf+0x2B8))) /* - Зад. выключатель механизма*/
#define internal1_m354_RA00 (*((psbool)(InternalBuf+0x2BA))) /* - последнее задание вперед*/
#define internal1_m354_RA10 (*((psbool)(InternalBuf+0x2BC))) /* - последнее задание назад*/
#define internal1_m354_MyFirstEnterFlag (*((psbool)(InternalBuf+0x2BE))) /*MyFirstEnterFlag*/
#define internal1_m882_X00 (*((psfloat)(InternalBuf+0x2C0))) /* X00 - текущая координата механизма*/
#define internal1_m882_V00 (*((psfloat)(InternalBuf+0x2C5))) /* V00 - текущая скорость механизма*/
#define internal1_m882_Pav0 (*((psbool)(InternalBuf+0x2CA))) /* - Пер.аварийный выключатель механизма*/
#define internal1_m882_Zav0 (*((psbool)(InternalBuf+0x2CC))) /* - Зад.аварийный выключатель механизма*/
#define internal1_m882_Pv0 (*((psbool)(InternalBuf+0x2CE))) /* - Пер. выключатель механизма*/
#define internal1_m882_Zv0 (*((psbool)(InternalBuf+0x2D0))) /* - Зад. выключатель механизма*/
#define internal1_m882_RA00 (*((psbool)(InternalBuf+0x2D2))) /* - последнее задание вперед*/
#define internal1_m882_RA10 (*((psbool)(InternalBuf+0x2D4))) /* - последнее задание назад*/
#define internal1_m882_MyFirstEnterFlag (*((psbool)(InternalBuf+0x2D6))) /*MyFirstEnterFlag*/
#define internal1_m176_C1 (*((psfloat)(InternalBuf+0x2D8))) /*C1 - концентрация запаздывающих нейтронов 1-го типа*/
#define internal1_m176_C2 (*((psfloat)(InternalBuf+0x2DD))) /*C2 - концентрация запаздывающих нейтронов 2-го типа*/
#define internal1_m176_C3 (*((psfloat)(InternalBuf+0x2E2))) /*C3 - концентрация запаздывающих нейтронов 3-го типа*/
#define internal1_m176_C4 (*((psfloat)(InternalBuf+0x2E7))) /*C4 - концентрация запаздывающих нейтронов 4-го типа*/
#define internal1_m176_C5 (*((psfloat)(InternalBuf+0x2EC))) /*C5 - концентрация запаздывающих нейтронов 5-го типа*/
#define internal1_m176_C6 (*((psfloat)(InternalBuf+0x2F1))) /*C6 - концентрация запаздывающих нейтронов 6-го типа*/
#define internal1_m176_N20 (*((psfloat)(InternalBuf+0x2F6))) /*N20 - пред. концентрация нейтронов второй АЗ*/
#define internal1_m176_C0 (*((psfloat)(InternalBuf+0x2FB))) /**C0 - пред. концентрация запаздывающих нейтронов*/
#define internal1_m176_ImpINI0 (*((psbool)(InternalBuf+0x319))) /*ImpINI - Запуск системы инициирования(пред.)*/
#define internal1_m176_MyFirstEnterFlag (*((psbool)(InternalBuf+0x31B))) /*MyFirstEnterFlag*/
#define internal1_m290_X00 (*((psfloat)(InternalBuf+0x31D))) /*X0 - текущая координата ОРР*/
#define internal1_m290_Sh00 (*((psfloat)(InternalBuf+0x322))) /*Sh0 - текущая координата штока ОРР*/
#define internal1_m290_RV00 (*((psfloat)(InternalBuf+0x327))) /*V0 - текущая скорость ОРР*/
#define internal1_m290_ShV00 (*((psfloat)(InternalBuf+0x32C))) /*V0 - текущая скорость штока ОРР*/
#define internal1_m290_Ppv0 (*((psbool)(InternalBuf+0x331))) /*Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)*/
#define internal1_m290_Pav0 (*((psbool)(InternalBuf+0x333))) /*Pav0 - Пер.аварийный выключатель ОРР*/
#define internal1_m290_Zav0 (*((psbool)(InternalBuf+0x335))) /*Zav0 - Зад.аварийный выключатель ОРР*/
#define internal1_m290_RA00 (*((psbool)(InternalBuf+0x337))) /*RA00 - последнее задание вперед*/
#define internal1_m290_RA10 (*((psbool)(InternalBuf+0x339))) /*RA10 - последнее задание назад*/
#define internal1_m290_RA50 (*((pschar)(InternalBuf+0x33B))) /*Ra50 - последнее задание скорости*/
#define internal1_m290_fls (*((psbool)(InternalBuf+0x33D))) /* fls - флаг одношагового режима*/
#define internal1_m290_flp (*((psbool)(InternalBuf+0x33F))) /* flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)*/
#define internal1_m290_MyFirstEnterFlag (*((psbool)(InternalBuf+0x341))) /*MyFirstEnterFlag*/
#define internal1_m126_X00 (*((psfloat)(InternalBuf+0x343))) /*X0 - текущая координата ОРР*/
#define internal1_m126_Sh00 (*((psfloat)(InternalBuf+0x348))) /*Sh0 - текущая координата штока ОРР*/
#define internal1_m126_RV00 (*((psfloat)(InternalBuf+0x34D))) /*V0 - текущая скорость ОРР*/
#define internal1_m126_ShV00 (*((psfloat)(InternalBuf+0x352))) /*V0 - текущая скорость штока ОРР*/
#define internal1_m126_Ppv0 (*((psbool)(InternalBuf+0x357))) /*Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)*/
#define internal1_m126_Pav0 (*((psbool)(InternalBuf+0x359))) /*Pav0 - Пер.аварийный выключатель ОРР*/
#define internal1_m126_Zav0 (*((psbool)(InternalBuf+0x35B))) /*Zav0 - Зад.аварийный выключатель ОРР*/
#define internal1_m126_RA00 (*((psbool)(InternalBuf+0x35D))) /*RA00 - последнее задание вперед*/
#define internal1_m126_RA10 (*((psbool)(InternalBuf+0x35F))) /*RA10 - последнее задание назад*/
#define internal1_m126_RA50 (*((pschar)(InternalBuf+0x361))) /*Ra50 - последнее задание скорости*/
#define internal1_m126_fls (*((psbool)(InternalBuf+0x363))) /* fls - флаг одношагового режима*/
#define internal1_m126_flp (*((psbool)(InternalBuf+0x365))) /* flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)*/
#define internal1_m126_MyFirstEnterFlag (*((psbool)(InternalBuf+0x367))) /*MyFirstEnterFlag*/
#define internal1_m258_X00 (*((psfloat)(InternalBuf+0x369))) /*X0 - текущая координата ОРР*/
#define internal1_m258_Sh00 (*((psfloat)(InternalBuf+0x36E))) /*Sh0 - текущая координата штока ОРР*/
#define internal1_m258_RV00 (*((psfloat)(InternalBuf+0x373))) /*V0 - текущая скорость ОРР*/
#define internal1_m258_ShV00 (*((psfloat)(InternalBuf+0x378))) /*V0 - текущая скорость штока ОРР*/
#define internal1_m258_Ppv0 (*((psbool)(InternalBuf+0x37D))) /*Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)*/
#define internal1_m258_Pav0 (*((psbool)(InternalBuf+0x37F))) /*Pav0 - Пер.аварийный выключатель ОРР*/
#define internal1_m258_Zav0 (*((psbool)(InternalBuf+0x381))) /*Zav0 - Зад.аварийный выключатель ОРР*/
#define internal1_m258_RA00 (*((psbool)(InternalBuf+0x383))) /*RA00 - последнее задание вперед*/
#define internal1_m258_RA10 (*((psbool)(InternalBuf+0x385))) /*RA10 - последнее задание назад*/
#define internal1_m258_RA50 (*((pschar)(InternalBuf+0x387))) /*Ra50 - последнее задание скорости*/
#define internal1_m258_fls (*((psbool)(InternalBuf+0x389))) /* fls - флаг одношагового режима*/
#define internal1_m258_flp (*((psbool)(InternalBuf+0x38B))) /* flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)*/
#define internal1_m258_MyFirstEnterFlag (*((psbool)(InternalBuf+0x38D))) /*MyFirstEnterFlag*/
#define internal1_m94_X00 (*((psfloat)(InternalBuf+0x38F))) /*X0 - текущая координата ОРР*/
#define internal1_m94_Sh00 (*((psfloat)(InternalBuf+0x394))) /*Sh0 - текущая координата штока ОРР*/
#define internal1_m94_RV00 (*((psfloat)(InternalBuf+0x399))) /*V0 - текущая скорость ОРР*/
#define internal1_m94_ShV00 (*((psfloat)(InternalBuf+0x39E))) /*V0 - текущая скорость штока ОРР*/
#define internal1_m94_Ppv0 (*((psbool)(InternalBuf+0x3A3))) /*Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)*/
#define internal1_m94_Pav0 (*((psbool)(InternalBuf+0x3A5))) /*Pav0 - Пер.аварийный выключатель ОРР*/
#define internal1_m94_Zav0 (*((psbool)(InternalBuf+0x3A7))) /*Zav0 - Зад.аварийный выключатель ОРР*/
#define internal1_m94_RA00 (*((psbool)(InternalBuf+0x3A9))) /*RA00 - последнее задание вперед*/
#define internal1_m94_RA10 (*((psbool)(InternalBuf+0x3AB))) /*RA10 - последнее задание назад*/
#define internal1_m94_RA50 (*((pschar)(InternalBuf+0x3AD))) /*Ra50 - последнее задание скорости*/
#define internal1_m94_fls (*((psbool)(InternalBuf+0x3AF))) /* fls - флаг одношагового режима*/
#define internal1_m94_flp (*((psbool)(InternalBuf+0x3B1))) /* flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)*/
#define internal1_m94_MyFirstEnterFlag (*((psbool)(InternalBuf+0x3B3))) /*MyFirstEnterFlag*/
#define internal1_m223_X00 (*((psfloat)(InternalBuf+0x3B5))) /*X0 - текущая координата ОРР*/
#define internal1_m223_Sh00 (*((psfloat)(InternalBuf+0x3BA))) /*Sh0 - текущая координата штока ОРР*/
#define internal1_m223_RV00 (*((psfloat)(InternalBuf+0x3BF))) /*V0 - текущая скорость ОРР*/
#define internal1_m223_ShV00 (*((psfloat)(InternalBuf+0x3C4))) /*V0 - текущая скорость штока ОРР*/
#define internal1_m223_Ppv0 (*((psbool)(InternalBuf+0x3C9))) /*Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)*/
#define internal1_m223_Pav0 (*((psbool)(InternalBuf+0x3CB))) /*Pav0 - Пер.аварийный выключатель ОРР*/
#define internal1_m223_Zav0 (*((psbool)(InternalBuf+0x3CD))) /*Zav0 - Зад.аварийный выключатель ОРР*/
#define internal1_m223_RA00 (*((psbool)(InternalBuf+0x3CF))) /*RA00 - последнее задание вперед*/
#define internal1_m223_RA10 (*((psbool)(InternalBuf+0x3D1))) /*RA10 - последнее задание назад*/
#define internal1_m223_RA50 (*((pschar)(InternalBuf+0x3D3))) /*Ra50 - последнее задание скорости*/
#define internal1_m223_fls (*((psbool)(InternalBuf+0x3D5))) /* fls - флаг одношагового режима*/
#define internal1_m223_flp (*((psbool)(InternalBuf+0x3D7))) /* flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)*/
#define internal1_m223_MyFirstEnterFlag (*((psbool)(InternalBuf+0x3D9))) /*MyFirstEnterFlag*/
#define internal1_m59_X00 (*((psfloat)(InternalBuf+0x3DB))) /*X0 - текущая координата ОРР*/
#define internal1_m59_Sh00 (*((psfloat)(InternalBuf+0x3E0))) /*Sh0 - текущая координата штока ОРР*/
#define internal1_m59_RV00 (*((psfloat)(InternalBuf+0x3E5))) /*V0 - текущая скорость ОРР*/
#define internal1_m59_ShV00 (*((psfloat)(InternalBuf+0x3EA))) /*V0 - текущая скорость штока ОРР*/
#define internal1_m59_Ppv0 (*((psbool)(InternalBuf+0x3EF))) /*Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)*/
#define internal1_m59_Pav0 (*((psbool)(InternalBuf+0x3F1))) /*Pav0 - Пер.аварийный выключатель ОРР*/
#define internal1_m59_Zav0 (*((psbool)(InternalBuf+0x3F3))) /*Zav0 - Зад.аварийный выключатель ОРР*/
#define internal1_m59_RA00 (*((psbool)(InternalBuf+0x3F5))) /*RA00 - последнее задание вперед*/
#define internal1_m59_RA10 (*((psbool)(InternalBuf+0x3F7))) /*RA10 - последнее задание назад*/
#define internal1_m59_RA50 (*((pschar)(InternalBuf+0x3F9))) /*Ra50 - последнее задание скорости*/
#define internal1_m59_fls (*((psbool)(InternalBuf+0x3FB))) /* fls - флаг одношагового режима*/
#define internal1_m59_flp (*((psbool)(InternalBuf+0x3FD))) /* flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)*/
#define internal1_m59_MyFirstEnterFlag (*((psbool)(InternalBuf+0x3FF))) /*MyFirstEnterFlag*/
#define internal1_m14_C1 (*((psfloat)(InternalBuf+0x401))) /*C1 - концентрация запаздывающих нейтронов 1-го типа*/
#define internal1_m14_C2 (*((psfloat)(InternalBuf+0x406))) /*C2 - концентрация запаздывающих нейтронов 2-го типа*/
#define internal1_m14_C3 (*((psfloat)(InternalBuf+0x40B))) /*C3 - концентрация запаздывающих нейтронов 3-го типа*/
#define internal1_m14_C4 (*((psfloat)(InternalBuf+0x410))) /*C4 - концентрация запаздывающих нейтронов 4-го типа*/
#define internal1_m14_C5 (*((psfloat)(InternalBuf+0x415))) /*C5 - концентрация запаздывающих нейтронов 5-го типа*/
#define internal1_m14_C6 (*((psfloat)(InternalBuf+0x41A))) /*C6 - концентрация запаздывающих нейтронов 6-го типа*/
#define internal1_m14_N20 (*((psfloat)(InternalBuf+0x41F))) /*N20 - пред. концентрация нейтронов второй АЗ*/
#define internal1_m14_C0 (*((psfloat)(InternalBuf+0x424))) /**C0 - пред. концентрация запаздывающих нейтронов*/
#define internal1_m14_ImpINI0 (*((psbool)(InternalBuf+0x442))) /*ImpINI - Запуск системы инициирования(пред.)*/
#define internal1_m14_MyFirstEnterFlag (*((psbool)(InternalBuf+0x444))) /*MyFirstEnterFlag*/
int InternalBufSize = 1094;

/* Определение сигналов */
#define signal_A0SR01RIM     (*((psfloat)(PBSTART+0x0)))  /*                       Текущая реактивность AЗ1 */
#define signal_A1AD11LDU     (*((psbool)(PBSTART+0x5)))  /*                       Сигнал на перемещение ББ1 вверх */
#define signal_A1AD21LDU     (*((psbool)(PBSTART+0x7)))  /*                       Сигнал на перемещение ББ1 вниз */
#define signal_A1AD01LDU     (*((psbool)(PBSTART+0x9)))  /*                       Разрешение движения ББ1 */
#define signal_A1AD02LDU     (*((psbool)(PBSTART+0xb)))  /*                       0-й бит скорости ББ1 */
#define signal_A1AD03LDU     (*((psbool)(PBSTART+0xd)))  /*                       1-й бит скорости ББ1 */
#define signal_A1AD04LDU     (*((psbool)(PBSTART+0xf)))  /*                       2-й бит скорости ББ1 */
#define signal_A1AD05LDU     (*((psbool)(PBSTART+0x11)))  /*                       паритет команды на ББ1 */
#define signal_B1AD11LDU     (*((psbool)(PBSTART+0x13)))  /*                       Сигнал на перемещение ББ2 вверх */
#define signal_B1AD21LDU     (*((psbool)(PBSTART+0x15)))  /*                       Сигнал на перемещение ББ2 вниз */
#define signal_B1AD01LDU     (*((psbool)(PBSTART+0x17)))  /*                       Разрешение движения ББ2 */
#define signal_B1AD02LDU     (*((psbool)(PBSTART+0x19)))  /*                       0-й бит скорости  ББ2 */
#define signal_B1AD03LDU     (*((psbool)(PBSTART+0x1b)))  /*                       1-й бит скорости ББ2 */
#define signal_B1AD04LDU     (*((psbool)(PBSTART+0x1d)))  /*                       2-й бит скорости ББ2 */
#define signal_B1AD05LDU     (*((psbool)(PBSTART+0x1f)))  /*                       паритет команды на ББ2 */
#define signal_A2AD11LDU     (*((psbool)(PBSTART+0x21)))  /*                       Сигнал на перемещение РБ1 вверх */
#define signal_A2AD21LDU     (*((psbool)(PBSTART+0x23)))  /*                       Сигнал на перемещение РБ1 вниз */
#define signal_A2AD01LDU     (*((psbool)(PBSTART+0x25)))  /*                       Разрешение движения РБ1 */
#define signal_A2AD02LDU     (*((psbool)(PBSTART+0x27)))  /*                       0-й бит скорости РБ1 */
#define signal_A2AD03LDU     (*((psbool)(PBSTART+0x29)))  /*                       1-й бит скорости РБ1 */
#define signal_A2AD04LDU     (*((psbool)(PBSTART+0x2b)))  /*                       2-й бит скорости РБ1 */
#define signal_A2AD05LDU     (*((psbool)(PBSTART+0x2d)))  /*                       паритет команды на РБ1 */
#define signal_A2AD33LDU     (*((psbool)(PBSTART+0x2f)))  /*                       Клапан (Подъем РБ1) закрыть (обесточить) */
#define signal_B2AD11LDU     (*((psbool)(PBSTART+0x31)))  /*                       Сигнал на перемещение РБ2 вверх */
#define signal_B2AD21LDU     (*((psbool)(PBSTART+0x33)))  /*                       Сигнал на перемещение РБ2 вниз */
#define signal_B2AD01LDU     (*((psbool)(PBSTART+0x35)))  /*                       Разрешение движения РБ2 */
#define signal_B2AD02LDU     (*((psbool)(PBSTART+0x37)))  /*                       0-й бит скорости РБ2 */
#define signal_B2AD03LDU     (*((psbool)(PBSTART+0x39)))  /*                       1-й бит скорости РБ2 */
#define signal_B2AD04LDU     (*((psbool)(PBSTART+0x3b)))  /*                       2-й бит скорости РБ2 */
#define signal_B2AD05LDU     (*((psbool)(PBSTART+0x3d)))  /*                       паритет команды на РБ2 */
#define signal_B2AD33LDU     (*((psbool)(PBSTART+0x3f)))  /*                       Клапан (Подъем РБ2) закрыть (обесточить) */
#define signal_A3AD11LDU     (*((psbool)(PBSTART+0x41)))  /*                       Сигнал на перемещение ИС1 вверх */
#define signal_A3AD21LDU     (*((psbool)(PBSTART+0x43)))  /*                       Сигнал на перемещение ИС1 вниз */
#define signal_A3AD01LDU     (*((psbool)(PBSTART+0x45)))  /*                       Разрешение движения ИС1 */
#define signal_A3AD02LDU     (*((psbool)(PBSTART+0x47)))  /*                       0-й бит скорости ИС1 */
#define signal_A3AD03LDU     (*((psbool)(PBSTART+0x49)))  /*                       1-й бит скорости ИС1 */
#define signal_A3AD04LDU     (*((psbool)(PBSTART+0x4b)))  /*                       2-й бит скорости ИС1 */
#define signal_A3AD05LDU     (*((psbool)(PBSTART+0x4d)))  /*                       паритет команды на ИС1 */
#define signal_A3AD33LDU     (*((psbool)(PBSTART+0x4f)))  /*                       Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить) */
#define signal_B3AD11LDU     (*((psbool)(PBSTART+0x51)))  /*                       Сигнал на перемещение ИС2 вверх */
#define signal_B3AD21LDU     (*((psbool)(PBSTART+0x53)))  /*                       Сигнал на перемещение ИС2 вниз */
#define signal_B3AD01LDU     (*((psbool)(PBSTART+0x55)))  /*                       Разрешение движения ИС2 */
#define signal_B3AD02LDU     (*((psbool)(PBSTART+0x57)))  /*                       0-й бит скорости ИС2 */
#define signal_B3AD03LDU     (*((psbool)(PBSTART+0x59)))  /*                       1-й бит скорости ИС2 */
#define signal_B3AD04LDU     (*((psbool)(PBSTART+0x5b)))  /*                       2-й бит скорости ИС2 */
#define signal_B3AD05LDU     (*((psbool)(PBSTART+0x5d)))  /*                       паритет команды на ИС2 */
#define signal_B3AD33LDU     (*((psbool)(PBSTART+0x5f)))  /*                       Клапан ВЫСТРЕЛ ИС2 открыть (обесточить) */
#define signal_B0SR01RIM     (*((psfloat)(PBSTART+0x61)))  /*                       Текущая реактивность AЗ2 */
#define signal_R4AD10LDU     (*((psbool)(PBSTART+0x66)))  /*                       Перемещение тележки вперед */
#define signal_R4AD20LDU     (*((psbool)(PBSTART+0x68)))  /*                       Перемещение тележки назад */
#define signal_B8AD10LDU     (*((psbool)(PBSTART+0x6a)))  /*                       Перемещение АЗ2 вперед */
#define signal_B8AD20LDU     (*((psbool)(PBSTART+0x6c)))  /*                       Перемещение АЗ2 назад */
#define signal_A8AD10LDU     (*((psbool)(PBSTART+0x6e)))  /*                       Перемещение ДС2 вперед */
#define signal_A8AD20LDU     (*((psbool)(PBSTART+0x70)))  /*                       Перемещение ДС2 назад */
#define signal_A6AD10LDU     (*((psbool)(PBSTART+0x72)))  /*                       Открыть БЗ1 */
#define signal_A6AD20LDU     (*((psbool)(PBSTART+0x74)))  /*                       Закрыть БЗ1 */
#define signal_B6AD10LDU     (*((psbool)(PBSTART+0x76)))  /*                       Открыть БЗ2 */
#define signal_B6AD20LDU     (*((psbool)(PBSTART+0x78)))  /*                       Закрыть БЗ2 */
#define signal_R1AD10LDU     (*((psbool)(PBSTART+0x7a)))  /*                       Опустить МДЗ1 в зону облучения */
#define signal_R1AD20LDU     (*((psbool)(PBSTART+0x7c)))  /*                       Поднять МДЗ1 */
#define signal_R2AD10LDU     (*((psbool)(PBSTART+0x7e)))  /*                       Опустить МДЗ2 в зону облучения */
#define signal_R2AD20LDU     (*((psbool)(PBSTART+0x80)))  /*                       Поднять МДЗ2 */
#define signal_A5AD10LDU     (*((psbool)(PBSTART+0x82)))  /*                       Поднять НЛ1 */
#define signal_A5AD20LDU     (*((psbool)(PBSTART+0x84)))  /*                       Опустить НЛ1 */
#define signal_B5AD10LDU     (*((psbool)(PBSTART+0x86)))  /*                       Поднять НЛ2 */
#define signal_B5AD20LDU     (*((psbool)(PBSTART+0x88)))  /*                       Опустить НЛ2 */
#define signal_A0SN08RIM     (*((psfloat)(PBSTART+0x8a)))  /*                       Поток нейтронов AЗ1(нейтр/с) */
#define signal_B0SN08RIM     (*((psfloat)(PBSTART+0x8f)))  /*                       Поток нейтронов AЗ2(нейтр/с) */
#define signal_R0CR01RIM     (*((psfloat)(PBSTART+0x94)))  /*                       Коэффициент 12 связи АЗ1,2 */
#define signal_R0CR02RIM     (*((psfloat)(PBSTART+0x99)))  /*                       Коэффициент 11 связи АЗ1,2 */
#define signal_R0SR02RIM     (*((psfloat)(PBSTART+0x9e)))  /*                       Текущая мощность РУ (ватт) */
#define signal_R0AD14LDU     (*((psbool)(PBSTART+0xa3)))  /*                       Имитация срабатывания верхней АС II УР */
#define signal_R8AD21LDU     (*((psbool)(PBSTART+0xa5)))  /*                       Запуск системы инициирования */
#define signal_R8AD21LDU     (*((psbool)(PBSTART+0xa5)))  /*                       Запуск системы инициирования */
#define signal_R0VZ71LZ1     (*((psbool)(PBSTART+0xa7)))  /*                       Обобщенный сигнал по АЗ  1 канала */
#define signal_R0VZ71LZ2     (*((psbool)(PBSTART+0xa9)))  /*                       Обобщенный сигнал по АЗ  2 канала */
#define signal_A2AD32LDU     (*((psbool)(PBSTART+0xab)))  /*                       Обесточить ЭМ РБ1 */
#define signal_C2MD31LP1     (*((psbool)(PBSTART+0xad)))  /*                       Кнопка «СБРОС РБ» */
#define signal_C2MD31LP1     (*((psbool)(PBSTART+0xad)))  /*                       Кнопка «СБРОС РБ» */
#define signal_A2AD31LDU     (*((psbool)(PBSTART+0xaf)))  /*                       Клапан (Сброс РБ1) открыть (обесточить) */
#define signal_A1AD32LDU     (*((psbool)(PBSTART+0xb1)))  /*                       Обесточить ЭМ ББ1 */
#define signal_A1AD31LDU     (*((psbool)(PBSTART+0xb3)))  /*                       Клапан (Сброс ББ1) открыть (обесточить) */
#define signal_C1MD31LP2     (*((psbool)(PBSTART+0xb5)))  /*                       Кнопка «СБРОС ББ»  на ОПУ2 */
#define signal_C1MD31LP2     (*((psbool)(PBSTART+0xb5)))  /*                       Кнопка «СБРОС ББ»  на ОПУ2 */
#define signal_C1MD31LP1     (*((psbool)(PBSTART+0xb7)))  /*                       Кнопка «СБРОС ББ»  на ОПУ1 */
#define signal_C1MD31LP1     (*((psbool)(PBSTART+0xb7)))  /*                       Кнопка «СБРОС ББ»  на ОПУ1 */
#define signal_A3AD31LDU     (*((psbool)(PBSTART+0xb9)))  /*                       Клапан (СПУСК ИС1) открыть (обесточить) */
#define signal_B1AD31LDU     (*((psbool)(PBSTART+0xbb)))  /*                       Клапан (Сброс ББ2) открыть (обесточить) */
#define signal_B1AD32LDU     (*((psbool)(PBSTART+0xbd)))  /*                       Обесточить ЭМ ББ2 */
#define signal_B2AD31LDU     (*((psbool)(PBSTART+0xbf)))  /*                       Клапан (Сброс РБ2) открыть (обесточить) */
#define signal_B2AD32LDU     (*((psbool)(PBSTART+0xc1)))  /*                       Обесточить ЭМ РБ2 */
#define signal_B3AD31LDU     (*((psbool)(PBSTART+0xc3)))  /*                       Клапан (СПУСК ИС2) открыть (обесточить) */
#define signal_R0MW13LP2     (*((psbool)(PBSTART+0xc5)))  /*                       Переключатель «СЕТЬ» */
#define signal_B9AD10LDU     (*((psbool)(PBSTART+0xc7)))  /*                       Открыть клапан (Подъем НИ ДС2) */
#define signal_A9AD10LDU     (*((psbool)(PBSTART+0xc9)))  /*                       Открыть клапан (Подъем НИ ДС1) */
#define signal_B4AD10LDU     (*((psbool)(PBSTART+0xcb)))  /*                       Открыть клапан (Подъем НИ2) */
#define signal_A4AD10LDU     (*((psbool)(PBSTART+0xcd)))  /*                       Открыть клапан (Подъем НИ1) */
#define signal_R0ST01RIM     (*((psfloat)(PBSTART+0xcf)))  /*                       Текущий период разгона РУ */
#define signal_R0SR01RIM     (*((psfloat)(PBSTART+0xd4)))  /*                       Текущая реактивность PУ */
#define signal_R7II73LZ1     (*((psbool)(PBSTART+0xd9)))  /*                       Сработала АС IIУР */
#define signal_R7II71LZ1     (*((psbool)(PBSTART+0xdb)))  /*                       Сработала АС IУР (датчик 1) */
#define signal_R7II72LZ1     (*((psbool)(PBSTART+0xdd)))  /*                       Сработала АС IУР (датчик 2) */
#define signal_R0AD16LDU     (*((psbool)(PBSTART+0xdf)))  /*                       Контроль  I-II УР. РАД */
#define signal_R7II72LZ2     (*((psbool)(PBSTART+0xe1)))  /*                       Сработала АС IУР (датчик 2) */
#define signal_R7II71LZ2     (*((psbool)(PBSTART+0xe3)))  /*                       Сработала АС IУР (датчик 1) */
#define signal_R7II73LZ2     (*((psbool)(PBSTART+0xe5)))  /*                       Сработала АС IIУР */
#define signal_A3IS35LDU     (*((psbool)(PBSTART+0xe7)))  /*                       Клапан (ВПИС1) открыт(обесточен) */
#define signal_B3AD34LDU     (*((psbool)(PBSTART+0xe9)))  /*                       Клапан (ВПИС2) открыть (обесточить) */
#define signal_B3IS35LDU     (*((psbool)(PBSTART+0xeb)))  /*                       Клапан «ВПИС2» открыт(обесточен) */
#define signal_A7AS31LDU     (*((psbool)(PBSTART+0xed)))  /*                       Клапан (Обдув АЗ1) открыт (обесточен) */
#define signal_B7AS31LDU     (*((psbool)(PBSTART+0xef)))  /*                       Клапан (Обдув АЗ2) открыт (обесточен) */
#define signal_R6IS21LDU     (*((psbool)(PBSTART+0xf1)))  /*                       Кран-балка в нерабочем положении */
#define signal_A0IT01IZ1     (*((psint)(PBSTART+0xf3)))  /*                       Температура АЗ1-1 */
#define signal_A0IT02IZ2     (*((psint)(PBSTART+0xf6)))  /*                       Температура АЗ1-2 */
#define signal_B0IT01IZ1     (*((psint)(PBSTART+0xf9)))  /*                       Температура АЗ2-1 */
#define signal_B0IT02IZ2     (*((psint)(PBSTART+0xfc)))  /*                       Температура АЗ2-2 */
#define signal_A2IS21LDU     (*((psbool)(PBSTART+0xff)))  /*                       Приход на НУ РБ1 */
#define signal_A2IS11LDU     (*((psbool)(PBSTART+0x101)))  /*                       Приход на ВУ РБ1 */
#define signal_A2IS12LDU     (*((psbool)(PBSTART+0x103)))  /*                       Магнит РБ1 зацеплен */
#define signal_A2IC01UDU     (*((pslong)(PBSTART+0x105)))  /*                       Координата штока РБ1 */
#define signal_A2IS33LDU     (*((psbool)(PBSTART+0x10a)))  /*                       Клапан (Подъём РБ1)  открыт (обесточен) */
#define signal_A3IS21LDU     (*((psbool)(PBSTART+0x10c)))  /*                       Приход на НУ ИС1 */
#define signal_B3IS21LDU     (*((psbool)(PBSTART+0x10e)))  /*                       Приход на НУ ИС2 */
#define signal_A2IP01IZ1     (*((psint)(PBSTART+0x110)))  /*                       Текущее давление СБРОС РБ1 */
#define signal_A2IP01IZ2     (*((psint)(PBSTART+0x113)))  /*                       Текущее давление СБРОС РБ1 */
#define signal_A2VP82LDU     (*((psbool)(PBSTART+0x116)))  /*                       Давление ПОДЪЁМ РБ1 в норме */
#define signal_A3IS31LDU     (*((psbool)(PBSTART+0x118)))  /*                       Клапан (СПУСК ИС1)  открыт (обесточен) */
#define signal_A3IC01UDU     (*((pslong)(PBSTART+0x11a)))  /*                       Координата штока ИС1 */
#define signal_A3IS33LDU     (*((psbool)(PBSTART+0x11f)))  /*                       Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен) */
#define signal_B3IP02IDU     (*((psint)(PBSTART+0x121)))  /*                       Текущее давление ВЫСТРЕЛ  ИС2 */
#define signal_B3IS31LDU     (*((psbool)(PBSTART+0x124)))  /*                       Клапан (СПУСК ИС2)  открыт (обесточен) */
#define signal_B3IC01UDU     (*((pslong)(PBSTART+0x126)))  /*                       Координата штока ИС2 */
#define signal_B3IS33LDU     (*((psbool)(PBSTART+0x12b)))  /*                       Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен) */
#define signal_A3VP81LDU     (*((psbool)(PBSTART+0x12d)))  /*                       Давление СПУСК ИС1 в норме */
#define signal_B3VP81LDU     (*((psbool)(PBSTART+0x12f)))  /*                       Давление СПУСК ИС2 в норме */
#define signal_A3IP02IDU     (*((psint)(PBSTART+0x131)))  /*                       Текущее давление ВЫСТРЕЛ ИС1 */
#define signal_A3IS11LDU     (*((psbool)(PBSTART+0x134)))  /*                       Приход на ВУ ИС1 */
#define signal_B3IS11LDU     (*((psbool)(PBSTART+0x136)))  /*                       Приход на ВУ ИС2 */
#define signal_A3IS22LDU     (*((psbool)(PBSTART+0x138)))  /*                       Приход на НУП ИС1 */
#define signal_B3IS22LDU     (*((psbool)(PBSTART+0x13a)))  /*                       Приход на НУП ИС2 */
#define signal_R6IS62LDU     (*((psbool)(PBSTART+0x13c)))  /*                       Исправность ВИП ССДИ-39 1канал */
#define signal_R6IS63LDU     (*((psbool)(PBSTART+0x13e)))  /*                       Исправность ВИП ССДИ-39 2канал */
#define signal_R6IS64LDU     (*((psbool)(PBSTART+0x140)))  /*                       Исправность ВИП ССДИ-35 1канал */
#define signal_R6IS65LDU     (*((psbool)(PBSTART+0x142)))  /*                       Исправность ВИП ССДИ-35 2канал */
#define signal_R6IS66LZZ     (*((psbool)(PBSTART+0x144)))  /*                       Исправность ВИП 4,0 (№5) ССДИ-1-1 */
#define signal_R6IS67LZZ     (*((psbool)(PBSTART+0x146)))  /*                       Исправность ВИП 4,0 (№6) ССДИ-1-2 */
#define signal_R6IS68LZZ     (*((psbool)(PBSTART+0x148)))  /*                       Исправность ВИП 4,0 (№7) ССДИ-2 */
#define signal_A8IC01UDU     (*((pslong)(PBSTART+0x14a)))  /*                       Координата ДС2 */
#define signal_B8IC01UDU     (*((pslong)(PBSTART+0x14f)))  /*                       Координата АЗ2 */
#define signal_A0VP81LZZ     (*((psbool)(PBSTART+0x154)))  /*                       Давление АЗ1 в норме */
#define signal_B0VP81LZZ     (*((psbool)(PBSTART+0x156)))  /*                       Давление АЗ2 в норме */
#define signal_A5IS11LDU     (*((psbool)(PBSTART+0x158)))  /*                       Приход на ВУ НЛ1 */
#define signal_A5IS21LDU     (*((psbool)(PBSTART+0x15a)))  /*                       Приход на НУ НЛ1 */
#define signal_B5IS11LDU     (*((psbool)(PBSTART+0x15c)))  /*                       Приход на ВУ НЛ2 */
#define signal_B5IS21LDU     (*((psbool)(PBSTART+0x15e)))  /*                       Приход на НУ НЛ2 */
#define signal_A9IS11LDU     (*((psbool)(PBSTART+0x160)))  /*                       Приход на ВУ НИ ДС1 */
#define signal_A9IS21LDU     (*((psbool)(PBSTART+0x162)))  /*                       Приход на НУ НИ ДС1 */
#define signal_B9IS11LDU     (*((psbool)(PBSTART+0x164)))  /*                       Приход на ВУ НИ ДС2 */
#define signal_B9IS21LDU     (*((psbool)(PBSTART+0x166)))  /*                       Приход на НУ НИ ДС2 */
#define signal_B2IS21LDU     (*((psbool)(PBSTART+0x168)))  /*                       Приход на НУ РБ2 */
#define signal_B2IS11LDU     (*((psbool)(PBSTART+0x16a)))  /*                       Приход на ВУ РБ2 */
#define signal_B2IS12LDU     (*((psbool)(PBSTART+0x16c)))  /*                       Магнит РБ2 зацеплен */
#define signal_B2IC01UDU     (*((pslong)(PBSTART+0x16e)))  /*                       Координата штока РБ2 */
#define signal_B2IP01IZ1     (*((psint)(PBSTART+0x173)))  /*                       Текущее давление СБРОС РБ2 */
#define signal_B2IP01IZ2     (*((psint)(PBSTART+0x176)))  /*                       Текущее давление СБРОС РБ2 */
#define signal_B2VP82LDU     (*((psbool)(PBSTART+0x179)))  /*                       Давление ПОДЪЁМ РБ2 в норме */
#define signal_R3IS11LDU     (*((psbool)(PBSTART+0x17b)))  /*                       Приход на ВУ гомогенных дверей */
#define signal_R3IS21LDU     (*((psbool)(PBSTART+0x17d)))  /*                       Приход на НУ гомогенных дверей */
#define signal_R5IS11LDU     (*((psbool)(PBSTART+0x17f)))  /*                       Приход на ВУ ворот отстойной зоны */
#define signal_R5IS21LDU     (*((psbool)(PBSTART+0x181)))  /*                       Приход на НУ ворот отстойной зоны */
#define signal_A4IS11LDU     (*((psbool)(PBSTART+0x183)))  /*                       Приход на ВУ НИ1 */
#define signal_A4IS21LDU     (*((psbool)(PBSTART+0x185)))  /*                       Приход на НУ НИ1 */
#define signal_R8IS11LDU     (*((psbool)(PBSTART+0x187)))  /*                       Аварийный НИ установлен */
#define signal_B4IS11LDU     (*((psbool)(PBSTART+0x189)))  /*                       Приход на ВУ НИ2 */
#define signal_B4IS21LDU     (*((psbool)(PBSTART+0x18b)))  /*                       Приход на НУ НИ2 */
#define signal_R1IS11LDU     (*((psbool)(PBSTART+0x18d)))  /*                       Приход на ВУ МДЗ1 */
#define signal_R1IS21LDU     (*((psbool)(PBSTART+0x18f)))  /*                       Приход на НУ МДЗ1 */
#define signal_R2IS11LDU     (*((psbool)(PBSTART+0x191)))  /*                       Приход на ВУ МДЗ2 */
#define signal_R2IS21LDU     (*((psbool)(PBSTART+0x193)))  /*                       Приход на НУ МДЗ2 */
#define signal_A4VP82LDU     (*((psbool)(PBSTART+0x195)))  /*                       Давление ПОДЪЁМ НИ1 в норме */
#define signal_B4VP82LDU     (*((psbool)(PBSTART+0x197)))  /*                       Давление ПОДЪЁМ НИ2 в норме */
#define signal_R4IS11LDU     (*((psbool)(PBSTART+0x199)))  /*                       Приход на ВУ1 тележки */
#define signal_R4IS21LDU     (*((psbool)(PBSTART+0x19b)))  /*                       Приход на НУ1 тележки */
#define signal_R4IS22LDU     (*((psbool)(PBSTART+0x19d)))  /*                       Приход на НУ2 тележки */
#define signal_R4IS12LDU     (*((psbool)(PBSTART+0x19f)))  /*                       Приход на  ВУ2 тележки */
#define signal_B8IS22LDU     (*((psbool)(PBSTART+0x1a1)))  /*                       Приход на НУ2 АЗ2 */
#define signal_B8IS12LDU     (*((psbool)(PBSTART+0x1a3)))  /*                       Приход на ВУ2 АЗ2 */
#define signal_A8IS22LDU     (*((psbool)(PBSTART+0x1a5)))  /*                       Приход на механический НУ ДС2 */
#define signal_A8IS12LDU     (*((psbool)(PBSTART+0x1a7)))  /*                       Приход на механический ВУ ДС2 */
#define signal_A6IS11LDU     (*((psbool)(PBSTART+0x1a9)))  /*                       Приход на ВУ БЗ1 */
#define signal_A6IS21LDU     (*((psbool)(PBSTART+0x1ab)))  /*                       Приход на НУ БЗ1 */
#define signal_B6IS11LDU     (*((psbool)(PBSTART+0x1ad)))  /*                       Приход на ВУ БЗ2 */
#define signal_B6IS21LDU     (*((psbool)(PBSTART+0x1af)))  /*                       Приход на НУ БЗ2 */
#define signal_A1IS21LDU     (*((psbool)(PBSTART+0x1b1)))  /*                       Приход на НУ ББ1 */
#define signal_A1IS11LDU     (*((psbool)(PBSTART+0x1b3)))  /*                       Приход на ВУ ББ1 */
#define signal_A1IS12LDU     (*((psbool)(PBSTART+0x1b5)))  /*                       Магнит ББ1 зацеплен */
#define signal_A1IC01UDU     (*((pslong)(PBSTART+0x1b7)))  /*                       Координата штока ББ1 */
#define signal_B1IC01UDU     (*((pslong)(PBSTART+0x1bc)))  /*                       Координата штока ББ2 */
#define signal_B1IS21LDU     (*((psbool)(PBSTART+0x1c1)))  /*                       Приход на НУ ББ2 */
#define signal_B1IS11LDU     (*((psbool)(PBSTART+0x1c3)))  /*                       Приход на ВУ ББ2 */
#define signal_B1IS12LDU     (*((psbool)(PBSTART+0x1c5)))  /*                       Магнит ББ2 зацеплен */
#define signal_A1IE03LDU     (*((psbool)(PBSTART+0x1c7)))  /*                       Движение ББ1 вперед (от БУШД) */
#define signal_A1IE04LDU     (*((psbool)(PBSTART+0x1c9)))  /*                       Движение ББ1 назад (от БУШД) */
#define signal_B1IE03LDU     (*((psbool)(PBSTART+0x1cb)))  /*                       Движение ББ2 вперед (от БУШД) */
#define signal_B1IE04LDU     (*((psbool)(PBSTART+0x1cd)))  /*                       Движение ББ2 назад (от БУШД) */
#define signal_A4IS10LDU     (*((psbool)(PBSTART+0x1cf)))  /*                       Клапан (Подъём НИ1) открыт (обесточен) */
#define signal_B4IS10LDU     (*((psbool)(PBSTART+0x1d1)))  /*                       Клапан (Подъём НИ2) открыт (обесточен) */
#define signal_R0EE01LZ1     (*((psbool)(PBSTART+0x1d3)))  /*                       Питание  АКНП1  отключить */
#define signal_R0EE01LZ2     (*((psbool)(PBSTART+0x1d5)))  /*                       Питание  АКНП1  отключить */
#define signal_R0EE02LZ1     (*((psbool)(PBSTART+0x1d7)))  /*                       Питание  АКНП  отключить */
#define signal_R0EE03LZ1     (*((psbool)(PBSTART+0x1d9)))  /*                       Питание  АКНП3  отключить */
#define signal_R0EE04LZ1     (*((psbool)(PBSTART+0x1db)))  /*                       Питание  АКНП4  отключить */
#define signal_R0EE02LZ2     (*((psbool)(PBSTART+0x1dd)))  /*                       Питание  АКНП  отключить */
#define signal_R0EE03LZ2     (*((psbool)(PBSTART+0x1df)))  /*                       Питание  АКНП3  отключить */
#define signal_R0EE04LZ2     (*((psbool)(PBSTART+0x1e1)))  /*                       Питание  АКНП4  отключить */
#define signal_R0IS02LDU     (*((psbool)(PBSTART+0x1e3)))  /*                       Разрешение ввода от имитатора */
#define signal_A3AD34LDU     (*((psbool)(PBSTART+0x1e5)))  /*                       Клапан (ВПИС ИС1) открыть (обесточить) */
#define signal_A1IS11LIM     (*((psbool)(PBSTART+0x1e7)))  /*                       Магнит ББ1 обесточен */
#define signal_A1IS32LIM     (*((psbool)(PBSTART+0x1e9)))  /*                       Клапан cброса ББ1 открыт(обесточен) */
#define signal_B1IS11LIM     (*((psbool)(PBSTART+0x1eb)))  /*                       Магнит ББ2 обесточен */
#define signal_B1IS32LIM     (*((psbool)(PBSTART+0x1ed)))  /*                       Клапан cброса ББ2 открыт(обесточен) */
#define signal_A2IS11LIM     (*((psbool)(PBSTART+0x1ef)))  /*                       Магнит РБ1 обесточен */
#define signal_A2IS32LIM     (*((psbool)(PBSTART+0x1f1)))  /*                       Клапан cброса РБ1 открыт(обесточен) */
#define signal_B2IS11LIM     (*((psbool)(PBSTART+0x1f3)))  /*                       Магнит РБ2 обесточен */
#define signal_B2IS32LIM     (*((psbool)(PBSTART+0x1f5)))  /*                       Клапан cброса РБ2 открыт(обесточен) */
#define signal_A0VN01RIM     (*((psfloat)(PBSTART+0x1f7)))  /*                       Период разгона  AЗ1 */
#define signal_B2IS33LDU     (*((psbool)(PBSTART+0x1fc)))  /*                       Клапан (Подъём РБ2)  открыт (обесточен) */
#define signal_B1VP81LZZ     (*((psbool)(PBSTART+0x1fe)))  /*                       Давление СБРОС ББ2 в норме */
#define signal_A1VP81LZZ     (*((psbool)(PBSTART+0x200)))  /*                       Давление СБРОС ББ1 в норме */
#define signal_B8IS11LDU     (*((psbool)(PBSTART+0x202)))  /*                       Приход на ВУ1 АЗ2 */
#define signal_B8IS21LDU     (*((psbool)(PBSTART+0x204)))  /*                       Приход на НУ1 АЗ2 */
#define signal_A6VS22LDU     (*((psbool)(PBSTART+0x206)))  /*                       Движение створок БЗ1  к ЗАКРЫТА */
#define signal_A6VS12LDU     (*((psbool)(PBSTART+0x208)))  /*                       Движение створок БЗ1  к  ОТКРЫТА */
#define signal_B6VS22LDU     (*((psbool)(PBSTART+0x20a)))  /*                       Движение створок БЗ2  к ЗАКРЫТА */
#define signal_B6VS12LDU     (*((psbool)(PBSTART+0x20c)))  /*                       Движение створок БЗ2  к ОТКРЫТА */
#define signal_A5VS22LDU     (*((psbool)(PBSTART+0x20e)))  /*                       Движение НЛ1 в сторону НУ */
#define signal_A5VS12LDU     (*((psbool)(PBSTART+0x210)))  /*                       Движение НЛ1 в сторону ВУ */
#define signal_B5VS22LDU     (*((psbool)(PBSTART+0x212)))  /*                       Движение НЛ2 в сторону НУ */
#define signal_B5VS12LDU     (*((psbool)(PBSTART+0x214)))  /*                       Движение НЛ2 в сторону ВУ */
#define signal_R1VS22LDU     (*((psbool)(PBSTART+0x216)))  /*                       Движение МДЗ1 в сторону НУ */
#define signal_R2VS22LDU     (*((psbool)(PBSTART+0x218)))  /*                       Движение МДЗ2 в сторону НУ */
#define signal_R2VS12LDU     (*((psbool)(PBSTART+0x21a)))  /*                       Движение МДЗ2 в сторону ВУ */
#define signal_R1VS12LDU     (*((psbool)(PBSTART+0x21c)))  /*                       Движение МДЗ1 в сторону ВУ */
#define signal_R4VS22LDU     (*((psbool)(PBSTART+0x21e)))  /*                       Движение реактора к «У ЗАЩИТЫ» */
#define signal_R4VS12LDU     (*((psbool)(PBSTART+0x220)))  /*                       Движение реактора  к «У ОБРАЗЦОВ» */
#define signal_A7AP31LDU     (*((psbool)(PBSTART+0x222)))  /*                       Клапан (Обдув АЗ1) открыть (обесточить) */
#define signal_B7AP31LDU     (*((psbool)(PBSTART+0x224)))  /*                       Клапан (Обдув АЗ2) открыть (обесточить) */
#define signal_R0IN01FI1     (*((psfloat)(PBSTART+0x226)))  /*                       Выход КНК15-1 Гц от ПТИ */
#define signal_R0IN01FI4     (*((psfloat)(PBSTART+0x22b)))  /*                       Выход СНМ-11 Гц от ПТИ */
#define signal_R0IN01FI2     (*((psfloat)(PBSTART+0x230)))  /*                       Выход КНК15-1 Гц от ПТИ */
#define signal_R0IN01FI3     (*((psfloat)(PBSTART+0x235)))  /*                       Выход СНМ-11 Гц от ПТИ */
#define signal_R0IN02FI4     (*((psfloat)(PBSTART+0x23a)))  /*                       Выход КНК15-1 Гц от ПТИ */
#define signal_R0IN03FI4     (*((psfloat)(PBSTART+0x23f)))  /*                       Выход КНК53М Гц от ПТИ */
#define signal_R0IN02FI1     (*((psfloat)(PBSTART+0x244)))  /*                       Выход КНК15-1 Гц от ПТИ */
#define signal_R0IN03FI1     (*((psfloat)(PBSTART+0x249)))  /*                       Выход КНК53М Гц от ПТИ */
#define signal_R0IN02FI2     (*((psfloat)(PBSTART+0x24e)))  /*                       Выход КНК15-1 Гц от ПТИ */
#define signal_R0IN01RIP     (*((psfloat)(PBSTART+0x253)))  /*                       Выход СНМ-11 Гц от ПТИ */
#define signal_R0IN02RIP     (*((psfloat)(PBSTART+0x258)))  /*                       Выход КНК15- Гц от ПТИ */
#define signal_R0IN03RIP     (*((psfloat)(PBSTART+0x25d)))  /*                       Выход КНК53М Гц от ПТИ */
#define signal_TerR0IN06FRP  (*((psint)(PBSTART+0x262)))  /*                       Неисправности СНМ-11 -1,2 */
#define signal_R0IN06RIP     (*((psfloat)(PBSTART+0x265)))  /*                       Выход СНМ-11-1 Гц от ПТИ */
#define signal_R0IN07RIP     (*((psfloat)(PBSTART+0x26a)))  /*                       Выход СНМ-11-2 Гц от ПТИ */
#define signal_R0IN03FI2     (*((psfloat)(PBSTART+0x26f)))  /*                       Выход КНК53М Гц от ПТИ */
#define signal_R0IN02FI3     (*((psfloat)(PBSTART+0x274)))  /*                       Выход КНК15-1 Гц от ПТИ */
#define signal_R0IN03FI3     (*((psfloat)(PBSTART+0x279)))  /*                       Выход КНК53М Гц от ПТИ */
#define signal_B0IT03IRP     (*((psint)(PBSTART+0x27e)))  /*                       Температура АЗ2-3 */
#define signal_A0IT03IRP     (*((psint)(PBSTART+0x281)))  /*                       Температура АЗ1-3 */
#define signal_R0IS01FI0     (*((psint)(PBSTART+0x284)))  /*                       Признак работы с имитатором */
#define signal_R0MW11IP1     (*((psint)(PBSTART+0x287)))  /*                       Переключатель ВЫСТРЕЛ */
#define signal_R0DEUMLSS     (*((psint)(PBSTART+0x28a)))  /*                       Сигнал управления моделью */

/* Определение констант ПЗУ и ЭСППЗУ*/
struct      sbool  lRM_1_ = {    1,0}; /* Флаг наличия магнита на штоке ОРР */ 
struct     sfloat  fRM_0_ = {    0,0}; /* Заглушка давления на подъём ББ1 */ 
struct     sfloat  fRM_1_ = {    1,0}; /* *Vm - массив скоростей движения (шагов в секунду) */ 
struct      sbool  lRM_0_ = {    0,0}; /* Флаг наличия магнита на штоке ОРР */ 
struct     sfloat  fRM_1_0 = {  1.0,0}; /* Номинальная скорость БЗ (град/с) */ 
struct     sfloat  fRM_180_0 = {180.0,0}; /* Координата верхнего путевого выключателя БЗ град */ 
struct     sfloat  fRM_0_0 = {  0.0,0}; /* Координата нижних упоров БЗ град */ 
struct     sfloat  fRM_n50_ = {  -50,0}; /* Координата нижнего путевого выключателя БЗ град */ 
struct     sfloat  fRM_2000_0 = {2000.0,0}; /* Координата верхнего путевого выключателя МДЗ мм */ 
struct     sfloat  fRM_n150_ = { -150,0}; /* Координата нижнего путевого выключателя МДЗ мм */ 
struct     sfloat  fRM_1500_0 = {1500.0,0}; /* Координата верхнего механического выключателя НЛ мм */ 
struct       sint  iRM_7_ = {    7,0}; /* N */ 
struct     sfloat  fRM_390_ = {  390,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
struct     sfloat  fRM_420_ = {  420,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
struct     sfloat  fRM_513_ = {  513,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
struct     sfloat  fRM_767_ = {  767,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
struct     sfloat  fRM_900_ = {  900,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
struct     sfloat  fRM_1200_ = { 1200,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
struct     sfloat  fRM_1500_ = { 1500,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
struct     sfloat  fRM_3_546 = {3.546,0}; /* Bi, i=1..N -ординаты опорных точек */ 
struct     sfloat  fRM_2_7 = {  2.7,0}; /* Bi, i=1..N -ординаты опорных точек */ 
struct     sfloat  fRM_2_ = {    2,0}; /* Bi, i=1..N -ординаты опорных точек */ 
struct     sfloat  fRM_0_88884 = {0.88884,0}; /* Bi, i=1..N -ординаты опорных точек */ 
struct     sfloat  fRM_0_6221739 = {0.6221739,0}; /* Bi, i=1..N -ординаты опорных точек */ 
struct     sfloat  fRM_0_35555072 = {0.35555072,0}; /* Bi, i=1..N -ординаты опорных точек */ 
struct     sfloat  fRM_0_2666666667 = {0.2666666667,0}; /* Bi, i=1..N -ординаты опорных точек */ 
struct       sint  iRM_5_ = {    5,0}; /* N */ 
struct     sfloat  fRM_600_ = {  600,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
struct     sfloat  fRM_0_5 = {  0.5,0}; /* Bi, i=1..N -ординаты опорных точек */ 
struct     sfloat  fRM_0_2 = {  0.2,0}; /* Bi, i=1..N -ординаты опорных точек */ 
struct     sfloat  fRM_0_088884 = {0.088884,0}; /* Bi, i=1..N -ординаты опорных точек */ 
struct     sfloat  fRM_0_066666667 = {0.066666667,0}; /* Bi, i=1..N -ординаты опорных точек */ 
struct     sfloat  fRM_0_02173913 = {0.02173913,0}; /* Bi, i=1..N -ординаты опорных точек */ 
struct     sfloat  fRM_0_002453 = {0.002453,0}; /* Bi, i=1..N -ординаты опорных точек */ 
struct     sfloat  fRM_0_00184 = {0.00184,0}; /* Bi, i=1..N -ординаты опорных точек */ 
struct     sfloat  fRM_0_10 = { 0.10,0}; /* Зона срабатывания КВ БЗ(мм) */ 
struct     sfloat  fRM_0_50 = { 0.50,0}; /* Зона срабатывания КВ МДЗ (мм) */ 
struct       sint  iRM_2_ = {    2,0}; /* n - N-размерность массива x */ 
struct       sint  iRM_3_ = {    3,0}; /* N-число входов */ 
struct       sint  iRM_4_ = {    4,0}; /* N-число входов */ 
struct       sint  iRM_0_ = {    0,0}; /* Ter - Неисправности механизма */ 
struct     sfloat  fRM_100000_ = {100000,0}; /* KPv - координата пер. выключателя механизма мм */ 
struct     sfloat  fRM_n100_ = { -100,0}; /* KZv - координата зад. выключателя механизма мм */ 
struct     sfloat  fRM_20_ = {   20,0}; /* Tp - Тормозной путь мм */ 
struct      schar  bRM_2_ = {    2,0}; /* type - тип камеры */ 
struct      schar  bRM_4_ = {    4,0}; /* type - тип камеры */ 
struct      schar  bRM_5_ = {    5,0}; /* type - тип камеры */ 
struct      schar  bRM_1_ = {    1,0}; /* type - тип камеры */ 
struct       sint  iRM_500_ = {  500,0}; /* tz - ширина импульса, 10-ки мс */ 
struct     sfloat  fRM_3_ = {    3,0}; /* m1 - величина отклонения второго сигнала от входного */ 
struct     sfloat  fRM_2_0 = {  2.0,0}; /* ampl - амплетуда синусоидального отклонения */ 
struct       sint  iRM_719_ = {  719,0}; /* min - минимальное возможное значение выходного сигнала */ 
struct       sint  iRM_4195_ = { 4195,0}; /* max - максимальное возможное значение выходного сигнала */ 
struct     sfloat  fRM_3276_ = { 3276,0}; /* c   - мин. значение кода ФАС */ 
struct     sfloat  fRM_16383_ = {16383,0}; /* d - макс.  значение кода ФАС */ 
struct     sfloat  fRM_200_ = {  200,0}; /* maxs1 - макc. значение второго сигнала */ 
struct     sfloat  fRM_0_0015 = {0.0015,0}; /* m1 - величина отклонения второго сигнала от входного */ 
struct     sfloat  fRM_0_001 = {0.001,0}; /* ampl - амплетуда синусоидального отклонения */ 
struct     sfloat  fRM_0_1 = {  0.1,0}; /* k - коэффициент усиления */ 
struct       sint  iRM_16_ = {   16,0}; /* n - N-размерность массива входных параметров */ 
struct     sfloat  fRM_2000_ = { 2000,0}; /* maxs1 - макc. значение второго сигнала */ 
struct     sfloat  fRM_15_ = {   15,0}; /* m1 - величина отклонения второго сигнала от входного */ 
struct       sint  iRM_1_ = {    1,0}; /* признак константа */ 
#define fEM_R0UL01RIM  (*((psfloat)(SpaEEPROMBuf+0x0)))
#define fEM_R0UN02RIM  (*((psfloat)(SpaEEPROMBuf+0x5)))
#define fEM_A1UR01RIM  (*((psfloat)(SpaEEPROMBuf+0xA)))
#define fEM_A1UR00RIM  (*((psfloat)(SpaEEPROMBuf+0xF)))
#define fEM_A3UR00RIM  (*((psfloat)(SpaEEPROMBuf+0x14)))
#define fEM_A3UR01RIM  (*((psfloat)(SpaEEPROMBuf+0x19)))
#define fEM_R0UT01RIM  (*((psfloat)(SpaEEPROMBuf+0x1E)))
#define fEM_R0UT02RIM  (*((psfloat)(SpaEEPROMBuf+0x23)))
#define fEM_R0UT04RIM  (*((psfloat)(SpaEEPROMBuf+0x28)))
#define fEM_R0UT03RIM  (*((psfloat)(SpaEEPROMBuf+0x2D)))
#define fEM_R0UT05RIM  (*((psfloat)(SpaEEPROMBuf+0x32)))
#define fEM_R0UT06RIM  (*((psfloat)(SpaEEPROMBuf+0x37)))
#define fEM_A1UC02RDU  (*((psfloat)(SpaEEPROMBuf+0x3C)))
#define fEM_A1UC04RIM  (*((psfloat)(SpaEEPROMBuf+0x41)))
#define fEM_A1UC05RIM  (*((psfloat)(SpaEEPROMBuf+0x46)))
#define fEM_A1UC06RIM  (*((psfloat)(SpaEEPROMBuf+0x4B)))
#define fEM_A2UC06RIM  (*((psfloat)(SpaEEPROMBuf+0x50)))
#define fEM_A2UC05RIM  (*((psfloat)(SpaEEPROMBuf+0x55)))
#define fEM_A2UC04RIM  (*((psfloat)(SpaEEPROMBuf+0x5A)))
#define fEM_A2UC02RDU  (*((psfloat)(SpaEEPROMBuf+0x5F)))
#define fEM_A3UC06RIM  (*((psfloat)(SpaEEPROMBuf+0x64)))
#define fEM_A3UC05RIM  (*((psfloat)(SpaEEPROMBuf+0x69)))
#define fEM_A3UC04RIM  (*((psfloat)(SpaEEPROMBuf+0x6E)))
#define fEM_A3UC02RDU  (*((psfloat)(SpaEEPROMBuf+0x73)))
#define fEM_R4UV80RDU  (*((psfloat)(SpaEEPROMBuf+0x78)))
#define fEM_R4UC10RIM  (*((psfloat)(SpaEEPROMBuf+0x7D)))
#define fEM_R4UC20RIM  (*((psfloat)(SpaEEPROMBuf+0x82)))
#define fEM_B8UC21RIM  (*((psfloat)(SpaEEPROMBuf+0x87)))
#define fEM_B8UC20RIM  (*((psfloat)(SpaEEPROMBuf+0x8C)))
#define fEM_B8UC11RIM  (*((psfloat)(SpaEEPROMBuf+0x91)))
#define fEM_B8UC10RIM  (*((psfloat)(SpaEEPROMBuf+0x96)))
#define fEM_B8UV80RDU  (*((psfloat)(SpaEEPROMBuf+0x9B)))
#define fEM_A8UV80RDU  (*((psfloat)(SpaEEPROMBuf+0xA0)))
#define fEM_A8UC10RIM  (*((psfloat)(SpaEEPROMBuf+0xA5)))
#define fEM_A8UC11RIM  (*((psfloat)(SpaEEPROMBuf+0xAA)))
#define fEM_A8UC20RIM  (*((psfloat)(SpaEEPROMBuf+0xAF)))
#define fEM_A8UC21RIM  (*((psfloat)(SpaEEPROMBuf+0xB4)))
#define fEM_A6UC10RIM  (*((psfloat)(SpaEEPROMBuf+0xB9)))
#define fEM_R1UC10RIM  (*((psfloat)(SpaEEPROMBuf+0xBE)))
#define fEM_A5UC10RIM  (*((psfloat)(SpaEEPROMBuf+0xC3)))
#define fEM_A0UN01RIM  (*((psfloat)(SpaEEPROMBuf+0xC8)))
#define fEM_R4UC22RIM  (*((psfloat)(SpaEEPROMBuf+0xCD)))
#define fEM_A1UG01RDU  (*((psfloat)(SpaEEPROMBuf+0xD2)))
#define fEM_A2UG01RDU  (*((psfloat)(SpaEEPROMBuf+0xD7)))
#define fEM_A3UG01RDU  (*((psfloat)(SpaEEPROMBuf+0xDC)))
#define fEM_R7UC10RIM  (*((psfloat)(SpaEEPROMBuf+0xE1)))
#define fEM_R7UC19RIM  (*((psfloat)(SpaEEPROMBuf+0xE6)))
#define fEM_R7UI02RIM  (*((psfloat)(SpaEEPROMBuf+0xEB)))
#define fEM_R7UL01RIM  (*((psfloat)(SpaEEPROMBuf+0xF0)))
#define fEM_A2UR00RIM  (*((psfloat)(SpaEEPROMBuf+0xF5)))
#define fEM_A2UR01RIM  (*((psfloat)(SpaEEPROMBuf+0xFA)))
#define fEM_A0UN02RIM  (*((psfloat)(SpaEEPROMBuf+0xFF)))
#define fEM_R0UR30RIM  (*((psfloat)(SpaEEPROMBuf+0x104)))
#define fEM_R0UR01RIM  (*((psfloat)(SpaEEPROMBuf+0x109)))
#define fEM_R0UT02RDU  (*((psfloat)(SpaEEPROMBuf+0x10E)))
#define fEM_R0UT01RDU  (*((psfloat)(SpaEEPROMBuf+0x113)))
#define fEM_A1UC03RDU  (*((psfloat)(SpaEEPROMBuf+0x118)))
#define fEM_A2UP03RDU  (*((psfloat)(SpaEEPROMBuf+0x11D)))
#define fEM_A2UP04RDU  (*((psfloat)(SpaEEPROMBuf+0x122)))
#define fEM_A2UC03RDU  (*((psfloat)(SpaEEPROMBuf+0x127)))
#define fEM_A3UP03RDU  (*((psfloat)(SpaEEPROMBuf+0x12C)))
#define fEM_A3UP04RDU  (*((psfloat)(SpaEEPROMBuf+0x131)))
#define fEM_A3UC03RDU  (*((psfloat)(SpaEEPROMBuf+0x136)))
#define fEM_R7UI74RIM  (*((psfloat)(SpaEEPROMBuf+0x13B)))
#define fEM_A8UC03RDU  (*((psfloat)(SpaEEPROMBuf+0x140)))
#define fEM_R0UV87RDU  (*((psfloat)(SpaEEPROMBuf+0x145)))
#define fEM_R0UV81RDU  (*((psfloat)(SpaEEPROMBuf+0x14A)))
#define fEM_R0UV82RDU  (*((psfloat)(SpaEEPROMBuf+0x14F)))
#define fEM_R0UV83RDU  (*((psfloat)(SpaEEPROMBuf+0x154)))
#define fEM_R0UV84RDU  (*((psfloat)(SpaEEPROMBuf+0x159)))
#define fEM_R0UV85RDU  (*((psfloat)(SpaEEPROMBuf+0x15E)))
#define fEM_R0UV86RDU  (*((psfloat)(SpaEEPROMBuf+0x163)))
#define fEM_A8UC08RDU  (*((psfloat)(SpaEEPROMBuf+0x168)))
#define fEM_B8UC08RDU  (*((psfloat)(SpaEEPROMBuf+0x16D)))
#define fEM_R4UC08RDU  (*((psfloat)(SpaEEPROMBuf+0x172)))
#define fEM_R0UH01RSS  (*((psfloat)(SpaEEPROMBuf+0x177)))
#define fEM_A0UX00RSS  (*((psfloat)(SpaEEPROMBuf+0x17C)))
#define fEM_R7UX01RSS  (*((psfloat)(SpaEEPROMBuf+0x181)))
#define fEM_R7UX02RSS  (*((psfloat)(SpaEEPROMBuf+0x186)))
#define fEM_R7UX04RSS  (*((psfloat)(SpaEEPROMBuf+0x18B)))
#define fEM_R7UX05RSS  (*((psfloat)(SpaEEPROMBuf+0x190)))
#define fEM_R7UX06RSS  (*((psfloat)(SpaEEPROMBuf+0x195)))
#define fEM_R7UX07RSS  (*((psfloat)(SpaEEPROMBuf+0x19A)))
#define fEM_R7UX08RSS  (*((psfloat)(SpaEEPROMBuf+0x19F)))
#define fEM_R7UX09RSS  (*((psfloat)(SpaEEPROMBuf+0x1A4)))
#define fEM_R7UY01RSS  (*((psfloat)(SpaEEPROMBuf+0x1A9)))
#define fEM_R7UY02RSS  (*((psfloat)(SpaEEPROMBuf+0x1AE)))
#define fEM_R7UY04RSS  (*((psfloat)(SpaEEPROMBuf+0x1B3)))
#define fEM_R7UY05RSS  (*((psfloat)(SpaEEPROMBuf+0x1B8)))
#define fEM_R7UY06RSS  (*((psfloat)(SpaEEPROMBuf+0x1BD)))
#define fEM_R7UY07RSS  (*((psfloat)(SpaEEPROMBuf+0x1C2)))
#define fEM_R7UY08RSS  (*((psfloat)(SpaEEPROMBuf+0x1C7)))
#define fEM_R7UY09RSS  (*((psfloat)(SpaEEPROMBuf+0x1CC)))
#define fEM_R7UX10RSS  (*((psfloat)(SpaEEPROMBuf+0x1D1)))
#define fEM_R7UX11RSS  (*((psfloat)(SpaEEPROMBuf+0x1D6)))
#define fEM_R7UX12RSS  (*((psfloat)(SpaEEPROMBuf+0x1DB)))
#define fEM_R7UY10RSS  (*((psfloat)(SpaEEPROMBuf+0x1E0)))
#define fEM_R7UY11RSS  (*((psfloat)(SpaEEPROMBuf+0x1E5)))
#define fEM_R7UY12RSS  (*((psfloat)(SpaEEPROMBuf+0x1EA)))
#define fEM_A0UX01RSS  (*((psfloat)(SpaEEPROMBuf+0x1EF)))
#define fEM_A0UX02RSS  (*((psfloat)(SpaEEPROMBuf+0x1F4)))
#define fEM_A0UX03RSS  (*((psfloat)(SpaEEPROMBuf+0x1F9)))
#define fEM_A0UX04RSS  (*((psfloat)(SpaEEPROMBuf+0x1FE)))
#define fEM_A0UX05RSS  (*((psfloat)(SpaEEPROMBuf+0x203)))
#define fEM_A0UX06RSS  (*((psfloat)(SpaEEPROMBuf+0x208)))
#define fEM_A0UX07RSS  (*((psfloat)(SpaEEPROMBuf+0x20D)))
#define fEM_A0UX08RSS  (*((psfloat)(SpaEEPROMBuf+0x212)))
#define fEM_A0UX09RSS  (*((psfloat)(SpaEEPROMBuf+0x217)))
#define fEM_A0UX10RSS  (*((psfloat)(SpaEEPROMBuf+0x21C)))
#define fEM_A0UX11RSS  (*((psfloat)(SpaEEPROMBuf+0x221)))
#define fEM_A0UX12RSS  (*((psfloat)(SpaEEPROMBuf+0x226)))
#define fEM_B0UX01RSS  (*((psfloat)(SpaEEPROMBuf+0x22B)))
#define fEM_B0UX02RSS  (*((psfloat)(SpaEEPROMBuf+0x230)))
#define fEM_B0UX03RSS  (*((psfloat)(SpaEEPROMBuf+0x235)))
#define fEM_B0UX04RSS  (*((psfloat)(SpaEEPROMBuf+0x23A)))
#define fEM_B0UX05RSS  (*((psfloat)(SpaEEPROMBuf+0x23F)))
#define fEM_B0UX06RSS  (*((psfloat)(SpaEEPROMBuf+0x244)))
#define fEM_B0UX07RSS  (*((psfloat)(SpaEEPROMBuf+0x249)))
#define fEM_B0UX08RSS  (*((psfloat)(SpaEEPROMBuf+0x24E)))
#define fEM_B0UX09RSS  (*((psfloat)(SpaEEPROMBuf+0x253)))
#define fEM_B0UX10RSS  (*((psfloat)(SpaEEPROMBuf+0x258)))
#define fEM_B0UX11RSS  (*((psfloat)(SpaEEPROMBuf+0x25D)))
#define fEM_B0UX12RSS  (*((psfloat)(SpaEEPROMBuf+0x262)))
#define fEM_R0UH02RSS  (*((psfloat)(SpaEEPROMBuf+0x267)))
#define fEM_R0UH03RSS  (*((psfloat)(SpaEEPROMBuf+0x26C)))
#define fEM_R4US80RDU  (*((psfloat)(SpaEEPROMBuf+0x271)))
#define fEM_R7UI71RIM  (*((psfloat)(SpaEEPROMBuf+0x276)))
#define fEM_R7UI72RIM  (*((psfloat)(SpaEEPROMBuf+0x27B)))
#define fEM_R7UI73RIM  (*((psfloat)(SpaEEPROMBuf+0x280)))
#define fEM_A1UP01RIM  (*((psfloat)(SpaEEPROMBuf+0x285)))
#define fEM_A2UP01RIM  (*((psfloat)(SpaEEPROMBuf+0x28A)))
#define fEM_A0UP02RIM  (*((psfloat)(SpaEEPROMBuf+0x28F)))
#define fEM_A3UP01RIM  (*((psfloat)(SpaEEPROMBuf+0x294)))
#define fEM_A1UP82RIM  (*((psfloat)(SpaEEPROMBuf+0x299)))
#define fEM_A3UP02RDU  (*((psfloat)(SpaEEPROMBuf+0x29E)))
#define fEM_A1UV02RIM  (*((psfloat)(SpaEEPROMBuf+0x2A3)))
#define fEM_A3UV02RIM  (*((psfloat)(SpaEEPROMBuf+0x2A8)))
#define fEM_A2UV02RIM  (*((psfloat)(SpaEEPROMBuf+0x2AD)))
#define fEM_B8US80RDU  (*((psfloat)(SpaEEPROMBuf+0x2B2)))
#define fEM_A8US80RDU  (*((psfloat)(SpaEEPROMBuf+0x2B7)))
#define fEM_A6US80RDU  (*((psfloat)(SpaEEPROMBuf+0x2BC)))
#define fEM_A1US07RDU  (*((psfloat)(SpaEEPROMBuf+0x2C1)))
#define fEM_A2US07RDU  (*((psfloat)(SpaEEPROMBuf+0x2C6)))
#define fEM_A3US07RDU  (*((psfloat)(SpaEEPROMBuf+0x2CB)))
#define fEM_R7UI75RIM  (*((psfloat)(SpaEEPROMBuf+0x2D0)))
#define fEM_R0UH21RSS  (*((psfloat)(SpaEEPROMBuf+0x2D5)))
#define fEM_R0UH22RSS  (*((psfloat)(SpaEEPROMBuf+0x2DA)))
#define fEM_R0UH23RSS  (*((psfloat)(SpaEEPROMBuf+0x2DF)))
#define fEM_R0UH05RSS  (*((psfloat)(SpaEEPROMBuf+0x2E4)))
#define fEM_A4UL10RIM  (*((psfloat)(SpaEEPROMBuf+0x2E9)))
#define fEM_A9UL10RIM  (*((psfloat)(SpaEEPROMBuf+0x2EE)))
#define fEM_R3UL10RIM  (*((psfloat)(SpaEEPROMBuf+0x2F3)))
#define fEM_R5UL10RIM  (*((psfloat)(SpaEEPROMBuf+0x2F8)))
#define fEM_R6UL10RIM  (*((psfloat)(SpaEEPROMBuf+0x2FD)))
#define lEM_C1AD31LRP  (*((psbool)(SpaEEPROMBuf+0x302)))
#define lEM_R0IE01LRP  (*((psbool)(SpaEEPROMBuf+0x304)))
#define lEM_R0IE02LRP  (*((psbool)(SpaEEPROMBuf+0x306)))
#define fEM_A2UP02RIM  (*((psfloat)(SpaEEPROMBuf+0x308)))
#define fEM_A2UP03RIM  (*((psfloat)(SpaEEPROMBuf+0x30D)))
#define fEM_A0UP01RIM  (*((psfloat)(SpaEEPROMBuf+0x312)))
#define fEM_A3UP02RIM  (*((psfloat)(SpaEEPROMBuf+0x317)))
#define fEM_A4UP01RIM  (*((psfloat)(SpaEEPROMBuf+0x31C)))
#define fEM_A4UP02RIM  (*((psfloat)(SpaEEPROMBuf+0x321)))
#define fEM_R7UI76RIM  (*((psfloat)(SpaEEPROMBuf+0x326)))
#define fEM_R7UI77RIM  (*((psfloat)(SpaEEPROMBuf+0x32B)))
#define iEM_TERBB1  (*((psint)(SpaEEPROMBuf+0x330)))
#define fEM_A1MC02RC1  (*((psfloat)(SpaEEPROMBuf+0x333)))
#define fEM_A1MV02RC1  (*((psfloat)(SpaEEPROMBuf+0x338)))
#define iEM_TERBB2  (*((psint)(SpaEEPROMBuf+0x33D)))
#define fEM_B1MC02RC1  (*((psfloat)(SpaEEPROMBuf+0x340)))
#define fEM_B1MV02RC1  (*((psfloat)(SpaEEPROMBuf+0x345)))
#define iEM_TERRB2  (*((psint)(SpaEEPROMBuf+0x34A)))
#define fEM_B2MC02RC1  (*((psfloat)(SpaEEPROMBuf+0x34D)))
#define fEM_B2MV02RC1  (*((psfloat)(SpaEEPROMBuf+0x352)))
#define iEM_TERRB1  (*((psint)(SpaEEPROMBuf+0x357)))
#define fEM_A2MC02RC1  (*((psfloat)(SpaEEPROMBuf+0x35A)))
#define fEM_A2MV02RC1  (*((psfloat)(SpaEEPROMBuf+0x35F)))
#define iEM_TERIS2  (*((psint)(SpaEEPROMBuf+0x364)))
#define fEM_B3MC02RC1  (*((psfloat)(SpaEEPROMBuf+0x367)))
#define fEM_B3MV02RC1  (*((psfloat)(SpaEEPROMBuf+0x36C)))
#define iEM_TERIS1  (*((psint)(SpaEEPROMBuf+0x371)))
#define fEM_A3MC02RC1  (*((psfloat)(SpaEEPROMBuf+0x374)))
#define fEM_A3MV02RC1  (*((psfloat)(SpaEEPROMBuf+0x379)))
#define iEM_TERA1IE04LDU  (*((psint)(SpaEEPROMBuf+0x37E)))
#define iEM_TERA1IE03LDU  (*((psint)(SpaEEPROMBuf+0x381)))
#define fEM_A1MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x384)))
#define iEM_TERB1IE03LDU  (*((psint)(SpaEEPROMBuf+0x389)))
#define iEM_TERB1IE04LDU  (*((psint)(SpaEEPROMBuf+0x38C)))
#define fEM_B1MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x38F)))
#define fEM_B1MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x394)))
#define fEM_B2MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x399)))
#define fEM_B2MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x39E)))
#define fEM_A3MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x3A3)))
#define fEM_A3MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x3A8)))
#define fEM_B3MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x3AD)))
#define fEM_B3MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x3B2)))
#define iEM_TERA2SS21LIM  (*((psint)(SpaEEPROMBuf+0x3B7)))
#define iEM_TERA2SS12LIM  (*((psint)(SpaEEPROMBuf+0x3BA)))
#define iEM_TERR6SS21LIM  (*((psint)(SpaEEPROMBuf+0x3BD)))
#define iEM_TERA2VP82LIM  (*((psint)(SpaEEPROMBuf+0x3C0)))
#define iEM_TERA2SS11LIM  (*((psint)(SpaEEPROMBuf+0x3C3)))
#define iEM_TERB3SS21LIM  (*((psint)(SpaEEPROMBuf+0x3C6)))
#define iEM_TERA0MT01RIM  (*((psint)(SpaEEPROMBuf+0x3C9)))
#define iEM_TERB0MT01RIM  (*((psint)(SpaEEPROMBuf+0x3CC)))
#define iEM_TERA2SP01RIM  (*((psint)(SpaEEPROMBuf+0x3CF)))
#define iEM_TERB2SP01RIM  (*((psint)(SpaEEPROMBuf+0x3D2)))
#define iEM_TERB3SP02RIM  (*((psint)(SpaEEPROMBuf+0x3D5)))
#define iEM_TERA3SC01RIM  (*((psint)(SpaEEPROMBuf+0x3D8)))
#define iEM_TERA3VP81LIM  (*((psint)(SpaEEPROMBuf+0x3DB)))
#define iEM_TERA2SC01RIM  (*((psint)(SpaEEPROMBuf+0x3DE)))
#define iEM_TERA2SS33LIM  (*((psint)(SpaEEPROMBuf+0x3E1)))
#define iEM_TERA3SS21LIM  (*((psint)(SpaEEPROMBuf+0x3E4)))
#define iEM_TERA3SS33LIM  (*((psint)(SpaEEPROMBuf+0x3E7)))
#define iEM_TERA3SS31LIM  (*((psint)(SpaEEPROMBuf+0x3EA)))
#define iEM_TERB3SS31LIM  (*((psint)(SpaEEPROMBuf+0x3ED)))
#define iEM_TERB3SS33LIM  (*((psint)(SpaEEPROMBuf+0x3F0)))
#define iEM_TERB3SC01RIM  (*((psint)(SpaEEPROMBuf+0x3F3)))
#define iEM_TERA3SS11LIM  (*((psint)(SpaEEPROMBuf+0x3F6)))
#define iEM_TERB3SS11LIM  (*((psint)(SpaEEPROMBuf+0x3F9)))
#define iEM_TERR6IS64LIM  (*((psint)(SpaEEPROMBuf+0x3FC)))
#define iEM_TERB3SS22LIM  (*((psint)(SpaEEPROMBuf+0x3FF)))
#define iEM_TERA3SS22LIM  (*((psint)(SpaEEPROMBuf+0x402)))
#define iEM_TERA3SP02RIM  (*((psint)(SpaEEPROMBuf+0x405)))
#define iEM_TERR6IS62LIM  (*((psint)(SpaEEPROMBuf+0x408)))
#define iEM_TERR6IS66LIM  (*((psint)(SpaEEPROMBuf+0x40B)))
#define iEM_TERR6IS67LIM  (*((psint)(SpaEEPROMBuf+0x40E)))
#define iEM_TERA0VP81LIM  (*((psint)(SpaEEPROMBuf+0x411)))
#define iEM_TERB0VP81LIM  (*((psint)(SpaEEPROMBuf+0x414)))
#define iEM_TERR0VP81LIM  (*((psint)(SpaEEPROMBuf+0x417)))
#define iEM_TERR6IS68LIM  (*((psint)(SpaEEPROMBuf+0x41A)))
#define iEM_TERR7SI74RIM  (*((psint)(SpaEEPROMBuf+0x41D)))
#define iEM_TERA5SS21LIM  (*((psint)(SpaEEPROMBuf+0x420)))
#define iEM_TERB5SS11LIM  (*((psint)(SpaEEPROMBuf+0x423)))
#define iEM_TERA5SS11LIM  (*((psint)(SpaEEPROMBuf+0x426)))
#define iEM_TERA9SS11LIM  (*((psint)(SpaEEPROMBuf+0x429)))
#define iEM_TERB2SS11LIM  (*((psint)(SpaEEPROMBuf+0x42C)))
#define iEM_TERB2SS12LIM  (*((psint)(SpaEEPROMBuf+0x42F)))
#define iEM_TERB2SS21LIM  (*((psint)(SpaEEPROMBuf+0x432)))
#define iEM_TERR3SS11LIM  (*((psint)(SpaEEPROMBuf+0x435)))
#define iEM_TERB2SC01RIM  (*((psint)(SpaEEPROMBuf+0x438)))
#define iEM_TERR3SS21LIM  (*((psint)(SpaEEPROMBuf+0x43B)))
#define iEM_TERR5SS11LIM  (*((psint)(SpaEEPROMBuf+0x43E)))
#define iEM_TERA4SS11LIM  (*((psint)(SpaEEPROMBuf+0x441)))
#define iEM_TERR1SS11LIM  (*((psint)(SpaEEPROMBuf+0x444)))
#define iEM_TERR1SS21LIM  (*((psint)(SpaEEPROMBuf+0x447)))
#define iEM_TERR2SS11LIM  (*((psint)(SpaEEPROMBuf+0x44A)))
#define iEM_TERR2SS21LIM  (*((psint)(SpaEEPROMBuf+0x44D)))
#define iEM_TERA4VP82LIM  (*((psint)(SpaEEPROMBuf+0x450)))
#define iEM_TERB4SS21LIM  (*((psint)(SpaEEPROMBuf+0x453)))
#define iEM_TERR5SS21LIM  (*((psint)(SpaEEPROMBuf+0x456)))
#define iEM_TERB6SS21LIM  (*((psint)(SpaEEPROMBuf+0x459)))
#define iEM_TERB4SS11LIM  (*((psint)(SpaEEPROMBuf+0x45C)))
#define iEM_TERA4SS21LIM  (*((psint)(SpaEEPROMBuf+0x45F)))
#define iEM_TERA6MS11LIM  (*((psint)(SpaEEPROMBuf+0x462)))
#define iEM_TERA6SS21LIM  (*((psint)(SpaEEPROMBuf+0x465)))
#define iEM_TERB6SS11LIM  (*((psint)(SpaEEPROMBuf+0x468)))
#define iEM_TERR4SS11LIM  (*((psint)(SpaEEPROMBuf+0x46B)))
#define iEM_TERR4MS21LIM  (*((psint)(SpaEEPROMBuf+0x46E)))
#define iEM_TERR4SS12LIM  (*((psint)(SpaEEPROMBuf+0x471)))
#define iEM_TERR4SS22LIM  (*((psint)(SpaEEPROMBuf+0x474)))
#define iEM_TERR8SS11LIM  (*((psint)(SpaEEPROMBuf+0x477)))
#define iEM_TERB8SC01RIM  (*((psint)(SpaEEPROMBuf+0x47A)))
#define iEM_TERA8SC01RIM  (*((psint)(SpaEEPROMBuf+0x47D)))
#define iEM_TERB8SS12LIM  (*((psint)(SpaEEPROMBuf+0x480)))
#define iEM_TERA8SS12LIM  (*((psint)(SpaEEPROMBuf+0x483)))
#define iEM_TERB8SS22LIM  (*((psint)(SpaEEPROMBuf+0x486)))
#define iEM_TERA8SS22LIM  (*((psint)(SpaEEPROMBuf+0x489)))
#define iEM_TERA9SS21LIM  (*((psint)(SpaEEPROMBuf+0x48C)))
#define iEM_TERB9SS21LIM  (*((psint)(SpaEEPROMBuf+0x48F)))
#define iEM_TERB9SS11LIM  (*((psint)(SpaEEPROMBuf+0x492)))
#define iEM_TERB5SS21LIM  (*((psint)(SpaEEPROMBuf+0x495)))
#define iEM_TERA1SS21LIM  (*((psint)(SpaEEPROMBuf+0x498)))
#define iEM_TERA1SS11LIM  (*((psint)(SpaEEPROMBuf+0x49B)))
#define iEM_TERA1SC01RIM  (*((psint)(SpaEEPROMBuf+0x49E)))
#define iEM_TERA1SS12LIM  (*((psint)(SpaEEPROMBuf+0x4A1)))
#define iEM_TERB1SS21LIM  (*((psint)(SpaEEPROMBuf+0x4A4)))
#define iEM_TERB1SS11LIM  (*((psint)(SpaEEPROMBuf+0x4A7)))
#define iEM_TERB1MC01RIM  (*((psint)(SpaEEPROMBuf+0x4AA)))
#define iEM_TERB1SS12LIM  (*((psint)(SpaEEPROMBuf+0x4AD)))
#define iEM_TERTLG  (*((psint)(SpaEEPROMBuf+0x4B0)))
#define fEM_R4MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x4B3)))
#define fEM_R4MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x4B8)))
#define iEM_TERMAZ2  (*((psint)(SpaEEPROMBuf+0x4BD)))
#define fEM_B8MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x4C0)))
#define fEM_B8MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x4C5)))
#define iEM_TERDS2  (*((psint)(SpaEEPROMBuf+0x4CA)))
#define fEM_A8MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x4CD)))
#define fEM_A8MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x4D2)))
#define iEM_TERBZ1  (*((psint)(SpaEEPROMBuf+0x4D7)))
#define fEM_A6MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x4DA)))
#define fEM_A6MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x4DF)))
#define iEM_TERBZ2  (*((psint)(SpaEEPROMBuf+0x4E4)))
#define fEM_B6MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x4E7)))
#define fEM_B6MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x4EC)))
#define lEM_R3AD10LC1  (*((psbool)(SpaEEPROMBuf+0x4F1)))
#define lEM_R3AD20LC1  (*((psbool)(SpaEEPROMBuf+0x4F3)))
#define lEM_R6AD10LC1  (*((psbool)(SpaEEPROMBuf+0x4F5)))
#define lEM_R5AD10LC1  (*((psbool)(SpaEEPROMBuf+0x4F7)))
#define lEM_R5AD20LC1  (*((psbool)(SpaEEPROMBuf+0x4F9)))
#define iEM_TERMDZ2  (*((psint)(SpaEEPROMBuf+0x4FB)))
#define fEM_R2MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x4FE)))
#define fEM_R2MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x503)))
#define iEM_TERMDZ1  (*((psint)(SpaEEPROMBuf+0x508)))
#define fEM_R1MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x50B)))
#define fEM_R1MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x510)))
#define iEM_TERNL1  (*((psint)(SpaEEPROMBuf+0x515)))
#define fEM_A5MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x518)))
#define fEM_A5MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x51D)))
#define iEM_TERNL2  (*((psint)(SpaEEPROMBuf+0x522)))
#define fEM_B5MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x525)))
#define fEM_B5MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x52A)))
#define lEM_R8AD10LC1  (*((psbool)(SpaEEPROMBuf+0x52F)))
#define fEM_A1UC08RIM  (*((psfloat)(SpaEEPROMBuf+0x531)))
#define fEM_A2UC08RIM  (*((psfloat)(SpaEEPROMBuf+0x536)))
#define fEM_A3UC08RIM  (*((psfloat)(SpaEEPROMBuf+0x53B)))
#define iEM_TERB2SS33LIM  (*((psint)(SpaEEPROMBuf+0x540)))
#define iEM_TERA1VP81LIM  (*((psint)(SpaEEPROMBuf+0x543)))
#define iEM_TERB1VP81LIM  (*((psint)(SpaEEPROMBuf+0x546)))
#define fEM_A0UT03RSP  (*((psfloat)(SpaEEPROMBuf+0x549)))
#define fEM_A0UR01RSP  (*((psfloat)(SpaEEPROMBuf+0x54E)))
#define fEM_A0UR02RSP  (*((psfloat)(SpaEEPROMBuf+0x553)))
#define fEM_B0UT03RSP  (*((psfloat)(SpaEEPROMBuf+0x558)))
#define fEM_A1MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x55D)))
#define fEM_A1MC02RSP  (*((psfloat)(SpaEEPROMBuf+0x562)))
#define fEM_A1MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x567)))
#define fEM_A1MV02RSP  (*((psfloat)(SpaEEPROMBuf+0x56C)))
#define fEM_B1MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x571)))
#define fEM_B1MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x576)))
#define fEM_B1MC02RSP  (*((psfloat)(SpaEEPROMBuf+0x57B)))
#define fEM_B1MV02RSP  (*((psfloat)(SpaEEPROMBuf+0x580)))
#define fEM_A2MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x585)))
#define fEM_A2MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x58A)))
#define fEM_A2MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x58F)))
#define fEM_A2MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x594)))
#define fEM_A2MC02RSP  (*((psfloat)(SpaEEPROMBuf+0x599)))
#define fEM_A2MV02RSP  (*((psfloat)(SpaEEPROMBuf+0x59E)))
#define fEM_B2MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x5A3)))
#define fEM_B2MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x5A8)))
#define fEM_B2MC02RSP  (*((psfloat)(SpaEEPROMBuf+0x5AD)))
#define fEM_B2MV02RSP  (*((psfloat)(SpaEEPROMBuf+0x5B2)))
#define fEM_A3MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x5B7)))
#define fEM_A3MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x5BC)))
#define fEM_A3MC02RSP  (*((psfloat)(SpaEEPROMBuf+0x5C1)))
#define fEM_A3MV02RSP  (*((psfloat)(SpaEEPROMBuf+0x5C6)))
#define fEM_B3MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x5CB)))
#define fEM_B3MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x5D0)))
#define fEM_B3MC02RSP  (*((psfloat)(SpaEEPROMBuf+0x5D5)))
#define fEM_B3MV02RSP  (*((psfloat)(SpaEEPROMBuf+0x5DA)))
#define fEM_B8MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x5DF)))
#define fEM_B8MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x5E4)))
#define fEM_A8MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x5E9)))
#define fEM_A8MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x5EE)))
#define fEM_A6MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x5F3)))
#define fEM_A6MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x5F8)))
#define fEM_B6MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x5FD)))
#define fEM_B6MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x602)))
#define fEM_R3UC01RSP  (*((psfloat)(SpaEEPROMBuf+0x607)))
#define fEM_R3UV01RSP  (*((psfloat)(SpaEEPROMBuf+0x60C)))
#define fEM_R5UC01RSP  (*((psfloat)(SpaEEPROMBuf+0x611)))
#define fEM_R5UV01RSP  (*((psfloat)(SpaEEPROMBuf+0x616)))
#define fEM_R6UC01RSP  (*((psfloat)(SpaEEPROMBuf+0x61B)))
#define fEM_R6UV01RSP  (*((psfloat)(SpaEEPROMBuf+0x620)))
#define fEM_R2MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x625)))
#define fEM_R2MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x62A)))
#define fEM_R1MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x62F)))
#define fEM_R1MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x634)))
#define fEM_A5MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x639)))
#define fEM_A5MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x63E)))
#define fEM_B5MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x643)))
#define fEM_B5MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x648)))
#define fEM_A9MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x64D)))
#define fEM_A9MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x652)))
#define fEM_B9MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x657)))
#define fEM_B9MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x65C)))
#define fEM_A4MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x661)))
#define fEM_A4MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x666)))
#define fEM_B4MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x66B)))
#define fEM_B4MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x670)))
#define fEM_R4MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x675)))
#define fEM_R4MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x67A)))
#define fEM_A1MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x67F)))
#define iEM_TERB7MS31LIM  (*((psint)(SpaEEPROMBuf+0x684)))
#define iEM_TERA7MS31LIM  (*((psint)(SpaEEPROMBuf+0x687)))
#define fEM_R7UY00RSS  (*((psfloat)(SpaEEPROMBuf+0x68A)))
#define iEM_TERA6VS12LIM  (*((psint)(SpaEEPROMBuf+0x68F)))
#define iEM_TERA6VS22LIM  (*((psint)(SpaEEPROMBuf+0x692)))
#define iEM_TERB6VS12LIM  (*((psint)(SpaEEPROMBuf+0x695)))
#define iEM_TERB6VS22LIM  (*((psint)(SpaEEPROMBuf+0x698)))
#define iEM_TERA5VS22LIM  (*((psint)(SpaEEPROMBuf+0x69B)))
#define iEM_TERA5VS12LIM  (*((psint)(SpaEEPROMBuf+0x69E)))
#define iEM_TERB5VS12LIM  (*((psint)(SpaEEPROMBuf+0x6A1)))
#define iEM_TERB5VS22LIM  (*((psint)(SpaEEPROMBuf+0x6A4)))
#define iEM_TERR1VS12LIM  (*((psint)(SpaEEPROMBuf+0x6A7)))
#define iEM_TERR1VS22LIM  (*((psint)(SpaEEPROMBuf+0x6AA)))
#define iEM_TERR2VS12LIM  (*((psint)(SpaEEPROMBuf+0x6AD)))
#define iEM_TERR2VS22LIM  (*((psint)(SpaEEPROMBuf+0x6B0)))
#define iEM_TERR4VS12LDU  (*((psint)(SpaEEPROMBuf+0x6B3)))
#define iEM_TERR4VS22LDU  (*((psint)(SpaEEPROMBuf+0x6B6)))
#define fEM_R4UC23RIM  (*((psfloat)(SpaEEPROMBuf+0x6B9)))
#define fEM_A0UX13RSS  (*((psfloat)(SpaEEPROMBuf+0x6BE)))
#define fEM_A0UX14RSS  (*((psfloat)(SpaEEPROMBuf+0x6C3)))
#define fEM_A0UX15RSS  (*((psfloat)(SpaEEPROMBuf+0x6C8)))
#define fEM_R7UX13RSS  (*((psfloat)(SpaEEPROMBuf+0x6CD)))
#define fEM_R7UX14RSS  (*((psfloat)(SpaEEPROMBuf+0x6D2)))
#define fEM_R7UX15RSS  (*((psfloat)(SpaEEPROMBuf+0x6D7)))
#define fEM_R7UY13RSS  (*((psfloat)(SpaEEPROMBuf+0x6DC)))
#define fEM_R7UY14RSS  (*((psfloat)(SpaEEPROMBuf+0x6E1)))
#define fEM_R7UY15RSS  (*((psfloat)(SpaEEPROMBuf+0x6E6)))
#define fEM_R7UX16RSS  (*((psfloat)(SpaEEPROMBuf+0x6EB)))

int SpaEEPROMBufSize = 1776;

/* Определение переменных */
struct sfloat  var1;
struct sfloat  var2;
struct sfloat  var3;
struct sfloat  var4;
struct sfloat  var5;
struct sbool  var6;
struct sbool  var7;
struct sbool  var8;
struct sbool  var9;
struct sbool  var10;
struct sbool  var11;
struct sbool  var12;
struct sbool  var13;
struct sbool  var14;
struct sbool  var15;
struct sbool  var16;
struct sbool  var17;
struct sbool  var18;
struct sbool  var19;
struct sbool  var20;
struct sbool  var21;
struct sbool  var22;
struct sbool  var23;
struct sbool  var24;
struct sbool  var25;
struct sbool  var26;
struct sbool  var27;
struct sbool  var28;
struct sbool  var29;
struct sbool  var30;
struct sbool  var31;
struct sbool  var32;
struct sbool  var33;
struct sbool  var34;
struct sbool  var35;
struct sbool  var36;
struct sbool  var37;
struct sbool  var38;
struct sbool  var39;
struct sbool  var40;
struct sbool  var41;
struct sbool  var42;
struct sbool  var43;
struct sbool  var44;
struct sbool  var45;
struct sbool  var46;
struct sbool  var47;
struct sbool  var48;
struct sbool  var49;
struct sbool  var50;
struct slong  var51;
struct sfloat  var52;
struct slong  var53;
struct sfloat  var54;
struct sbool  var55;
struct sbool  var56;
struct sbool  var57;
struct sbool  var58;
struct sbool  var59;
struct sbool  var60;
struct sbool  var61;
struct sbool  var62;
struct sbool  var63;
struct sbool  var64;
struct sbool  var65;
struct sbool  var66;
struct sbool  var67;
struct sbool  var68;
struct sbool  var69;
struct sbool  var70;
struct sbool  var71;
struct sbool  var72;
struct sbool  var73;
struct sbool  var74;
struct sbool  var75;
struct sbool  var76;
struct sbool  var77;
struct sbool  var78;
struct sbool  var79;
struct sbool  var80;
struct sbool  var81;
struct sbool  var82;
struct sbool  var83;
struct sbool  var84;
struct sbool  var85;
struct sbool  var86;
struct sbool  var87;
struct sbool  var88;
struct sint  var89;
struct sint  var90;
struct sfloat  var91;
struct sfloat  var92;
struct slong  var93;
struct sfloat  var94;
struct sbool  var95;
struct sbool  var96;
struct sbool  var97;
struct sbool  var98;
struct sbool  var99;
struct sbool  var100;
struct sbool  var101;
struct sbool  var102;
struct sbool  var103;
struct sbool  var104;
struct sbool  var105;
struct sfloat  var106;
struct sbool  var107;
struct sbool  var108;
struct slong  var109;
struct sfloat  var110;
struct slong  var111;
struct sfloat  var112;
struct sbool  var113;
struct sbool  var114;
struct sbool  var115;
struct sbool  var116;
struct sbool  var117;
struct sbool  var118;
struct sbool  var119;
struct sbool  var120;
struct sbool  var121;
struct sbool  var122;
struct sbool  var123;
struct sint  var124;
struct sfloat  var125;
struct sbool  var126;
struct sbool  var127;
struct sint  var128;
struct sfloat  var129;
struct sbool  var130;
struct slong  var131;
struct sfloat  var132;
struct sbool  var133;
struct sbool  var134;
struct slong  var135;
struct sfloat  var136;
struct sbool  var137;
struct sint  var138;
struct sint  var139;
struct sbool  var140;
struct sbool  var141;
struct sbool  var142;
struct slong  var143;
struct sfloat  var144;
struct sbool  var145;
struct sbool  var146;
struct sbool  var147;
struct sfloat  var148;
struct sfloat  var149;
struct sfloat  var150;
struct sint  var151;
struct sint  var152;
struct sint  var153;
struct sfloat  var154;
struct sfloat  var155;
struct sfloat  var156;
struct sint  var157;
struct sint  var158;
struct sbool  var159;
struct sbool  var160;
struct sint  var161;
struct sfloat  var162;
struct sfloat  var163;
struct sfloat  var164;
struct sbool  var165;
struct sbool  var166;
struct sbool  var167;
struct sbool  var168;
struct sfloat  var169;
struct sbool  var170;
struct sfloat  var171;
struct sbool  var172;
struct sbool  var173;
struct sbool  var174;
struct sbool  var175;
struct sbool  var176;
struct sbool  var177;
struct sbool  var178;
struct sfloat  var179;
struct sbool  var180;
struct sbool  var181;
struct sbool  var182 = {0,0};
struct sbool  var183 = {0,0};
struct sbool  var184 = {0,0};
struct sbool  var185 = {0,0};
struct sbool  var186;
struct sbool  var187;
struct sbool  var188;
struct sbool  var189;
struct sbool  var190;
struct sbool  var191;
struct sbool  var192;
struct sbool  var193;
struct sbool  var194;
struct sbool  var195;
struct sbool  var196;
struct sbool  var197;
struct sbool  var198;
struct sbool  var199;
struct sbool  var200;
struct sbool  var201;
struct sbool  var202;
struct sbool  var203;
struct sbool  var204;
struct sbool  var205;
struct sbool  var206;
struct sbool  var207;
struct sbool  var208;
struct sbool  var209;
struct sbool  var210;
struct sbool  var211;
struct sbool  var212;
struct sbool  var213;
struct sbool  var214;
struct sbool  var215;
struct sbool  var216;
struct sbool  var217;
struct sfloat  var218;
struct sfloat  var219;
struct sfloat  var220;
struct sfloat  var221;
struct sfloat  var222;
struct sfloat  var223;
struct sfloat  var224;
struct sfloat  var225;
struct sfloat  var226;
struct sbool  var227;
struct sbool  var228;
struct sbool  var229;
struct sfloat  var230;
struct sfloat  var231;
struct sfloat  var232;
struct sfloat  var233;
struct sfloat  var234;
struct sfloat  var235;
struct sfloat  var236;
struct sfloat  var237;
struct sfloat  var238;
struct sfloat  var239;
struct sfloat  var240;
struct sfloat  var241;
struct sfloat  var242;
struct sbool  var243;
struct sbool  var244;
struct sbool  var245;
struct sbool  var246;
struct sbool  var247;
struct sbool  var248;
struct sbool  var249;
struct sbool  var250;
struct sbool  var251;
struct sbool  var252;
struct sbool  var253;
struct sbool  var254;
struct sbool  var255;
struct sbool  var256;
struct sbool  var257;
struct sbool  var258;
struct sbool  var259;
struct sbool  var260;
struct sbool  var261;
struct sbool  var262;
struct sbool  var263;
struct sbool  var264;
struct sbool  var265;
struct sbool  var266;
struct sfloat  var267;
struct sbool  var268;
struct sbool  var269;
struct sfloat  var270;
struct sbool  var271;
struct sbool  var272;
struct sbool  var273;
struct sbool  var274;
struct sbool  var275;
struct sbool  var276;
struct sbool  var277;
struct sbool  var278;
struct sfloat  var279;
struct sfloat  var280;
struct sfloat  var281;
struct sfloat  var282;
struct sbool  var283;
struct sfloat  var284;
struct sfloat  var285;
struct sfloat  var286;
struct sfloat  var287;
struct sbool  var288;
struct sbool  var289;
struct sbool  var290;
struct sbool  var291;
struct sbool  var292;
struct sfloat  var293;
struct sfloat  var294;
struct sbool  var295;
struct sbool  var296;
struct sbool  var297;
struct sbool  var298;
struct sbool  var299;
struct sfloat  var300;
struct sfloat  var301;
struct sbool  var302;
struct sbool  var303;
struct sbool  var304;
struct sbool  var305;
struct sbool  var306;
struct sbool  var307;
struct sfloat  var308;
struct sfloat  var309;
struct sbool  var310;
struct sbool  var311;
struct sbool  var312;
struct sbool  var313;
struct sbool  var314;
struct sbool  var315;
struct sfloat  var316;
struct sfloat  var317;
struct sbool  var318;
struct sbool  var319;
struct sbool  var320;
struct sbool  var321;
struct sbool  var322;
struct sfloat  var323;
struct sfloat  var324;
struct sbool  var325;
struct sbool  var326;
struct sbool  var327;
struct sbool  var328;
struct sbool  var329;
struct sfloat  var330 = {0,0};
struct sfloat  var331;
struct sfloat  var332;
struct sfloat  var333;
struct sbool  var334;
struct sfloat  var335;
struct slong  vainSLong;
struct sfloat  vainSFloat;
struct sint  vainSInt;
struct sbool  vainSBool;
struct schar  vainSChar;
char  vainSText[] = "";

/* Объявление массивов */
psbool  array_m345_x_1[16] = {NULL,NULL,&var329,&var187,&var181,&var271,&var269,&var263,&var260,&var276,&var319,&var314,&var305,&var295,&var289,NULL};
psbool  array_m895_x_1[2] = {NULL,NULL};
psbool  array_m890_x_1[2] = {&var167,NULL};
psbool  array_m915_x_1[2] = {&var174,NULL};
psbool  array_m908_x_1[2] = {&var175,NULL};
psbool  array_m900_x_1[2] = {&var176,NULL};
psbool  array_m607_x_1[2] = {&var32,&var228};
psbool  array_m604_x_1[2] = {&var32,&var229};
psbool  array_m614_x_1[3] = {NULL,NULL,NULL};
psbool  array_m892_x_1[2] = {&var199,NULL};
psbool  array_m282_x_1[2] = {&var216,NULL};
psbool  array_m249_x_1[3] = {NULL,&var202,&var216};
psbool  array_m250_x_1[3] = {NULL,&var202,&var216};
psbool  array_m212_x_1[4] = {NULL,&var205,&var204,&var216};
psbool  array_m211_x_1[4] = {&var205,NULL,&var204,&var216};
psbool  array_m117_x_1[2] = {NULL,&var216};
psbool  array_m48_x_1[4] = {NULL,&var210,&var209,&var216};
psbool  array_m47_x_1[4] = {&var210,NULL,&var209,&var216};
psbool  array_m85_x_1[3] = {NULL,&var214,&var216};
psbool  array_m86_x_1[3] = {NULL,&var214,&var216};
psbool  array_m620_x_1[2] = {&var227,&var31};
psfloat  array_m7_a_1[5] = {&fRM_390_,&fRM_600_,&fRM_900_,&fRM_1200_,&fRM_1500_};
psfloat  array_m7_b_1[5] = {&fRM_0_5,&fRM_0_2,&fRM_0_088884,&fRM_0_066666667,&fRM_0_02173913};
psfloat  array_m9_a_1[7] = {&fRM_390_,&fRM_420_,&fRM_513_,&fRM_767_,&fRM_900_,&fRM_1200_,&fRM_1500_};
psfloat  array_m9_b_1[7] = {&fRM_3_546,&fRM_2_7,&fRM_2_,&fRM_0_88884,&fRM_0_6221739,&fRM_0_35555072,&fRM_0_2666666667};
psfloat  array_m176_C0_1[6];
psfloat  array_m290_Vr_1[8] = {&fRM_1_,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
psfloat  array_m126_Vr_1[8] = {&fRM_1_,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
psfloat  array_m258_Vr_1[8] = {&fRM_1_,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
psfloat  array_m94_Vr_1[8] = {&fRM_1_,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
psfloat  array_m223_Vr_1[8] = {&fRM_1_,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
psfloat  array_m59_Vr_1[8] = {&fRM_1_,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
psfloat  array_m14_C0_1[6];

/* описания структур для ф-ий */

/* код алгоблоков */
/* Объявление структур */
_S_to3val far S_to3val_944_1 = {NULL,&fRM_900_,&fRM_15_,&fRM_0_0015,&fRM_0_,&fRM_2000_,&fRM_2000_,NULL,&var1,&var2,&vainSFloat,NULL};
_S_vchs far S_vchs_870_1 = {&var280,&var331,&var241,NULL,NULL,NULL,NULL,&bRM_5_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var3,NULL};
_S_vchs far S_vchs_860_1 = {&var331,&var280,&var241,NULL,NULL,NULL,NULL,&bRM_4_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var4,NULL};
_S_vchs far S_vchs_852_1 = {&var331,&var280,&var241,NULL,NULL,NULL,NULL,&bRM_2_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var5,NULL};
_S_twobool far S_twobool_807_1 = {&var278,NULL,&var6,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_806_1 = {&var277,NULL,&var7,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_989_1 = {&var254,NULL,&var8,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_988_1 = {&var253,NULL,&var9,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_987_1 = {&var258,NULL,&var10,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_986_1 = {&var257,NULL,&var11,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_666_1 = {&var246,NULL,&var12,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_665_1 = {&var245,NULL,&var13,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_644_1 = {&var250,NULL,&var14,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_643_1 = {&var249,NULL,&var15,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_664_1 = {&var262,NULL,&var16,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_663_1 = {&var261,NULL,&var17,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_642_1 = {&var266,NULL,&var18,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_641_1 = {&var265,NULL,&var19,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_508_1 = {&var37,NULL,&var20,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_524_1 = {&var37,NULL,&var21,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_396_1 = {&var305,NULL,&var22,&vainSBool,NULL,NULL};
_S_noto far S_noto_471_1 = {&var183,&var23};
_S_noto far S_noto_472_1 = {&var182,&var24};
_S_noto far S_noto_462_1 = {&var184,&var25};
_S_noto far S_noto_464_1 = {&var185,&var26};
_S_rs far S_rs_469_1 = {&var24,NULL,&var27,&vainSBool,NULL};
_S_rs far S_rs_470_1 = {&var23,NULL,&var28,&vainSBool,NULL};
_S_rs far S_rs_457_1 = {&var25,NULL,&var29,&vainSBool,NULL};
_S_rs far S_rs_458_1 = {&var26,NULL,&var30,&vainSBool,NULL};
_S_andn far S_andn_345_1 = {array_m345_x_1,&iRM_16_,&vainSBool};
_S_zpfs far S_zpfs_617_1 = {NULL,NULL,&var31,NULL,NULL};
_S_zpfs far S_zpfs_605_1 = {NULL,NULL,&var32,NULL,NULL};
_S_bol far S_bol_930_1 = {NULL,NULL,&var33};
_S_bol far S_bol_927_1 = {NULL,NULL,&var34};
_S_bol far S_bol_906_1 = {NULL,NULL,&var35};
_S_bol far S_bol_928_1 = {NULL,NULL,&var36};
_S_bol far S_bol_918_1 = {NULL,NULL,&var37};
_S_ampl far S_ampl_361_1 = {&var218,&fRM_0_1,&vainSFloat};
_S_or2 far S_or2_919_1 = {NULL,NULL,&var38};
_S_or2 far S_or2_910_1 = {NULL,NULL,&var39};
_S_or2 far S_or2_903_1 = {NULL,NULL,&var40};
_S_or2 far S_or2_896_1 = {NULL,NULL,&var41};
_S_zpfs far S_zpfs_593_1 = {&var186,&fRM_1_0,&var42,NULL,NULL};
_S_zpfs far S_zpfs_591_1 = {&var189,&fRM_0_5,&var43,NULL,NULL};
_S_twobool far S_twobool_202_1 = {NULL,NULL,&var44,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_218_1 = {NULL,NULL,&var45,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_41_1 = {NULL,NULL,&var46,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_56_1 = {NULL,NULL,&var47,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_960_1 = {&var322,NULL,&var48,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_957_1 = {&var318,NULL,&var49,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_956_1 = {&var319,NULL,&var50,&vainSBool,NULL,NULL};
_S_ktoenc far S_ktoenc_959_1 = {&var52,NULL,&fRM_0_,&iRM_0_,&var51,&vainSBool,&vainSBool,&vainSBool,&vainSLong,NULL,NULL};
_S_to3val far S_to3val_954_1 = {&var221,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,NULL,&var52,&vainSFloat,&vainSFloat,NULL};
_S_ktoenc far S_ktoenc_942_1 = {&var54,NULL,&fRM_0_,&iRM_0_,&var53,&vainSBool,&vainSBool,&vainSBool,&vainSLong,NULL,NULL};
_S_to3val far S_to3val_935_1 = {&var222,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,NULL,&var54,&vainSFloat,&vainSFloat,NULL};
_S_twobool far S_twobool_943_1 = {&var329,NULL,&var55,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_940_1 = {&var326,NULL,&var56,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_939_1 = {&var327,NULL,&var57,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1027_1 = {&var260,NULL,&var58,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1008_1 = {&var259,NULL,&var59,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1007_1 = {&var264,NULL,&var60,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1006_1 = {&var263,NULL,&var61,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_828_1 = {&var269,NULL,&var62,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_830_1 = {&var268,NULL,&var63,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_827_1 = {&var272,NULL,&var64,&var65,NULL,NULL};
_S_twobool far S_twobool_829_1 = {&var271,NULL,&var66,&var67,NULL,NULL};
_S_twobool far S_twobool_803_1 = {&var273,NULL,&var68,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_804_1 = {&var274,NULL,&var69,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_802_1 = {&var276,NULL,&var70,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_801_1 = {&var275,NULL,&var71,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1022_1 = {&var33,NULL,&var72,&var73,NULL,NULL};
_S_twobool far S_twobool_974_1 = {&var252,NULL,&var74,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_973_1 = {&var251,NULL,&var75,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_972_1 = {&var256,NULL,&var76,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_971_1 = {&var255,NULL,&var77,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1023_1 = {&var191,NULL,&var78,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1004_1 = {&var190,NULL,&var79,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_805_1 = {NULL,NULL,&var80,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1005_1 = {&var188,NULL,&var81,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1003_1 = {&var187,NULL,&var82,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1024_1 = {&var183,NULL,&var83,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1002_1 = {&var182,NULL,&var84,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_985_1 = {&var185,NULL,&var85,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_970_1 = {&var184,NULL,&var86,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_525_1 = {&var36,NULL,&var87,&var88,NULL,NULL};
_S_toao far S_toao_529_1 = {&var92,NULL,NULL,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var89,NULL};
_S_toao far S_toao_528_1 = {&var91,NULL,NULL,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var90,NULL};
_S_to3val far S_to3val_522_1 = {&var149,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,NULL,NULL,NULL,&var91,&vainSFloat,&var92,NULL};
_S_ktoenc far S_ktoenc_406_1 = {&var94,NULL,&fRM_0_,&iRM_0_,&var93,&vainSBool,&vainSBool,&vainSBool,&vainSLong,NULL,NULL};
_S_to3val far S_to3val_400_1 = {&var220,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,NULL,&var94,&vainSFloat,&vainSFloat,NULL};
_S_twobool far S_twobool_397_1 = {&var307,NULL,&var95,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_399_1 = {&var302,NULL,&var96,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_398_1 = {&var303,NULL,&var97,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_843_1 = {&var197,NULL,&var98,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_844_1 = {&var196,NULL,&var99,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_842_1 = {&var194,NULL,&var100,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1026_1 = {&var193,NULL,&var101,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_679_1 = {&var244,NULL,&var102,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_680_1 = {&var243,NULL,&var103,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_677_1 = {&var248,NULL,&var104,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_678_1 = {&var247,NULL,&var105,&vainSBool,NULL,NULL};
_S_ampl far S_ampl_630_1 = {&var226,NULL,&var106};
_S_to3val far S_to3val_631_1 = {&var106,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,NULL,NULL,NULL,&vainSFloat,&vainSFloat,&vainSFloat,NULL};
_S_twobool far S_twobool_541_1 = {&var35,NULL,&var107,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_540_1 = {&var35,NULL,&var108,&vainSBool,NULL,NULL};
_S_ktoenc far S_ktoenc_824_1 = {&var110,NULL,&fRM_0_,&iRM_0_,&var109,&vainSBool,&vainSBool,&vainSBool,&vainSLong,NULL,NULL};
_S_to3val far S_to3val_816_1 = {&var270,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,NULL,&var110,&vainSFloat,&vainSFloat,NULL};
_S_ktoenc far S_ktoenc_826_1 = {&var112,NULL,&fRM_0_,&iRM_0_,&var111,&vainSBool,&vainSBool,&vainSBool,&vainSLong,NULL,NULL};
_S_to3val far S_to3val_818_1 = {&var267,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,NULL,&var112,&vainSFloat,&vainSFloat,NULL};
_S_twobool far S_twobool_676_1 = {NULL,NULL,&var113,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_660_1 = {NULL,NULL,&var114,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_640_1 = {NULL,NULL,&var115,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_659_1 = {NULL,NULL,&var116,&var117,NULL,NULL};
_S_twobool far S_twobool_639_1 = {NULL,NULL,&var118,&var119,NULL,NULL};
_S_twobool far S_twobool_327_1 = {&var288,NULL,&var120,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_326_1 = {&var295,NULL,&var121,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_311_1 = {&var289,NULL,&var122,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_310_1 = {&var296,NULL,&var123,&vainSBool,NULL,NULL};
_S_toao far S_toao_503_1 = {&var125,NULL,NULL,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var124,NULL};
_S_to3val far S_to3val_496_1 = {&var171,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,NULL,NULL,NULL,&vainSFloat,&var125,&vainSFloat,NULL};
_S_twobool far S_twobool_542_1 = {&var34,NULL,&var126,&var127,NULL,NULL};
_S_toao far S_toao_507_1 = {&var129,NULL,NULL,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var128,NULL};
_S_to3val far S_to3val_499_1 = {&var169,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,NULL,NULL,NULL,&vainSFloat,&var129,&vainSFloat,NULL};
_S_twobool far S_twobool_340_1 = {&var292,NULL,&var130,&vainSBool,NULL,NULL};
_S_ktoenc far S_ktoenc_324_1 = {&var132,NULL,&fRM_0_,&iRM_0_,&var131,&vainSBool,&vainSBool,&vainSBool,&vainSLong,NULL,NULL};
_S_to3val far S_to3val_323_1 = {&var287,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,NULL,&var132,&vainSFloat,&vainSFloat,NULL};
_S_twobool far S_twobool_339_1 = {&var291,NULL,&var133,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_337_1 = {&var299,NULL,&var134,&vainSBool,NULL,NULL};
_S_ktoenc far S_ktoenc_316_1 = {&var136,NULL,&fRM_0_,&iRM_0_,&var135,&vainSBool,&vainSBool,&vainSBool,&vainSLong,NULL,NULL};
_S_to3val far S_to3val_313_1 = {&var294,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,NULL,&var136,&vainSFloat,&vainSFloat,NULL};
_S_twobool far S_twobool_338_1 = {&var298,NULL,&var137,&vainSBool,NULL,NULL};
_S_toao far S_toao_527_1 = {&var150,NULL,NULL,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var138,NULL};
_S_toao far S_toao_526_1 = {&var148,NULL,NULL,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var139,NULL};
_S_twobool far S_twobool_309_1 = {&var290,NULL,&var140,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_325_1 = {&var297,NULL,&var141,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_418_1 = {&var313,NULL,&var142,&vainSBool,NULL,NULL};
_S_ktoenc far S_ktoenc_419_1 = {&var144,NULL,&fRM_0_,&iRM_0_,&var143,&vainSBool,&vainSBool,&vainSBool,&vainSLong,NULL,NULL};
_S_to3val far S_to3val_414_1 = {&var219,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,NULL,&var144,&vainSFloat,&vainSFloat,NULL};
_S_twobool far S_twobool_417_1 = {&var315,NULL,&var145,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_416_1 = {&var310,NULL,&var146,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_415_1 = {&var311,NULL,&var147,&vainSBool,NULL,NULL};
_S_to3val far S_to3val_521_1 = {NULL,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,NULL,NULL,NULL,&var148,&var149,&var150,NULL};
_S_toao far S_toao_157_1 = {&var156,NULL,NULL,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var151,NULL};
_S_toao far S_toao_156_1 = {&var155,NULL,NULL,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var152,NULL};
_S_toao far S_toao_155_1 = {&var154,NULL,NULL,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var153,NULL};
_S_to3val far S_to3val_150_1 = {&var282,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,NULL,NULL,NULL,&var154,&var155,&var156,NULL};
_S_toao far S_toao_160_1 = {&var164,NULL,NULL,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var157,NULL};
_S_toao far S_toao_159_1 = {&var163,NULL,NULL,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var158,NULL};
_S_twobool far S_twobool_1025_1 = {&var181,NULL,&var159,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_144_1 = {&var283,NULL,&var160,&vainSBool,NULL,NULL};
_S_toao far S_toao_158_1 = {&var162,NULL,NULL,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var161,NULL};
_S_to3val far S_to3val_152_1 = {&var333,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,NULL,NULL,NULL,&var162,&var163,&var164,NULL};
_S_twobool far S_twobool_143_1 = {&var334,NULL,&var165,&vainSBool,NULL,NULL};
_S_orn far S_orn_895_1 = {array_m895_x_1,&iRM_2_,&var166};
_S_andn far S_andn_890_1 = {array_m890_x_1,&iRM_2_,&vainSBool};
_S_noto far S_noto_894_1 = {&var166,&var167};
_S_noto far S_noto_494_1 = {NULL,&var168};
_S_lk far S_lk_498_1 = {NULL,&var168,&var169};
_S_noto far S_noto_492_1 = {NULL,&var170};
_S_lk far S_lk_497_1 = {NULL,&var170,&var171};
_S_ovb1 far S_ovb1_191_1 = {NULL,&iRM_500_,&var172,NULL};
_S_ovb1 far S_ovb1_30_1 = {NULL,&iRM_500_,&var173,NULL};
_S_andn far S_andn_915_1 = {array_m915_x_1,&iRM_2_,&vainSBool};
_S_noto far S_noto_920_1 = {&var38,&var174};
_S_andn far S_andn_908_1 = {array_m908_x_1,&iRM_2_,&vainSBool};
_S_noto far S_noto_911_1 = {&var39,&var175};
_S_andn far S_andn_900_1 = {array_m900_x_1,&iRM_2_,&vainSBool};
_S_noto far S_noto_904_1 = {&var40,&var176};
_S_orn far S_orn_607_1 = {array_m607_x_1,&iRM_2_,&var177};
_S_orn far S_orn_604_1 = {array_m604_x_1,&iRM_2_,&var178};
_S_react far S_react_194_1 = {&var284,&var179};
_S_noto far S_noto_459_1 = {NULL,&var180};
_S_asmot far S_asmot_461_1 = {&var180,NULL,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,NULL,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,NULL,&vainSFloat,&var181,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_asmot far S_asmot_473_1 = {&var27,&var28,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,NULL,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,NULL,&vainSFloat,&var182,&var183,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_asmot far S_asmot_463_1 = {&var29,&var30,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,NULL,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,NULL,&vainSFloat,&var184,&var185,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_noto far S_noto_592_1 = {NULL,&var186};
_S_asmot far S_asmot_596_1 = {&var186,NULL,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,NULL,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,NULL,&vainSFloat,&var187,&var188,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_noto far S_noto_590_1 = {NULL,&var189};
_S_asmot far S_asmot_595_1 = {&var189,NULL,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,NULL,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,NULL,&vainSFloat,&var190,&var191,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_noto far S_noto_581_1 = {NULL,&var192};
_S_asmot far S_asmot_583_1 = {&var192,NULL,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,NULL,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,NULL,&vainSFloat,&var193,&var194,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_noto far S_noto_580_1 = {NULL,&var195};
_S_asmot far S_asmot_582_1 = {&var195,NULL,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,NULL,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,NULL,&vainSFloat,&var196,&var197,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_orn far S_orn_614_1 = {array_m614_x_1,&iRM_3_,&var198};
_S_andn far S_andn_892_1 = {array_m892_x_1,&iRM_2_,&vainSBool};
_S_noto far S_noto_897_1 = {&var41,&var199};
_S_andn far S_andn_282_1 = {array_m282_x_1,&iRM_2_,&var200};
_S_andn far S_andn_249_1 = {array_m249_x_1,&iRM_3_,&var201};
_S_noto far S_noto_248_1 = {NULL,&var202};
_S_andn far S_andn_250_1 = {array_m250_x_1,&iRM_3_,&var203};
_S_noto far S_noto_210_1 = {NULL,&var204};
_S_noto far S_noto_209_1 = {NULL,&var205};
_S_andn far S_andn_212_1 = {array_m212_x_1,&iRM_4_,&var206};
_S_andn far S_andn_211_1 = {array_m211_x_1,&iRM_4_,&var207};
_S_andn far S_andn_117_1 = {array_m117_x_1,&iRM_2_,&var208};
_S_noto far S_noto_46_1 = {NULL,&var209};
_S_noto far S_noto_45_1 = {NULL,&var210};
_S_andn far S_andn_48_1 = {array_m48_x_1,&iRM_4_,&var211};
_S_andn far S_andn_47_1 = {array_m47_x_1,&iRM_4_,&var212};
_S_andn far S_andn_85_1 = {array_m85_x_1,&iRM_3_,&var213};
_S_noto far S_noto_84_1 = {NULL,&var214};
_S_andn far S_andn_86_1 = {array_m86_x_1,&iRM_3_,&var215};
_S_noto far S_noto_612_1 = {&var198,&var216};
_S_orn far S_orn_620_1 = {array_m620_x_1,&iRM_2_,&var217};
_S_fsubo far S_fsubo_360_1 = {NULL,&var270,&var218};
_S_fsubo far S_fsubo_111_1 = {NULL,&var309,&var219};
_S_fsubo far S_fsubo_275_1 = {NULL,&var301,&var220};
_S_fsubo far S_fsubo_238_1 = {NULL,&var317,&var221};
_S_fsubo far S_fsubo_74_1 = {NULL,&var324,&var222};
_S_fsubo far S_fsubo_8_1 = {&var224,NULL,&var223};
_S_inf far S_inf_7_1 = {&var270,array_m7_a_1,array_m7_b_1,&iRM_5_,&var224,&vainSInt};
_S_inf far S_inf_9_1 = {&var270,array_m9_a_1,array_m9_b_1,&iRM_7_,&var225,&vainSInt};
_S_mod1 far S_mod1_625_1 = {&var285,NULL,NULL,&var226,NULL};
_S_bol far S_bol_619_1 = {&var285,NULL,&var227};
_S_bol far S_bol_609_1 = {&var285,NULL,&var228};
_S_bol far S_bol_603_1 = {&var285,NULL,&var229};
_S_vchs far S_vchs_789_1 = {&var331,&var280,&var241,NULL,NULL,NULL,NULL,&bRM_5_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var230,NULL};
_S_vchs far S_vchs_780_1 = {&var331,&var280,&var241,NULL,NULL,NULL,NULL,&bRM_4_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var231,NULL};
_S_vchs far S_vchs_772_1 = {&var331,&var280,&var241,NULL,NULL,NULL,NULL,&bRM_1_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var232,NULL};
_S_vchs far S_vchs_763_1 = {&var331,&var280,&var241,NULL,NULL,NULL,NULL,&bRM_5_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var233,NULL};
_S_vchs far S_vchs_754_1 = {&var331,&var280,&var241,NULL,NULL,NULL,NULL,&bRM_4_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var234,NULL};
_S_vchs far S_vchs_746_1 = {&var331,&var280,&var241,NULL,NULL,NULL,NULL,&bRM_1_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var235,NULL};
_S_vchs far S_vchs_737_1 = {&var331,&var280,&var241,NULL,NULL,NULL,NULL,&bRM_5_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var236,NULL};
_S_vchs far S_vchs_728_1 = {&var331,&var280,&var241,NULL,NULL,NULL,NULL,&bRM_4_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var237,NULL};
_S_vchs far S_vchs_720_1 = {&var331,&var280,&var241,NULL,NULL,NULL,NULL,&bRM_2_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var238,NULL};
_S_vchs far S_vchs_711_1 = {&var331,&var280,&var241,NULL,NULL,NULL,NULL,&bRM_5_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var239,NULL};
_S_vchs far S_vchs_702_1 = {&var331,&var280,&var241,NULL,NULL,NULL,NULL,&bRM_4_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var240,NULL};
_S_fsumo far S_fsumo_886_1 = {NULL,NULL,&var241};
_S_vchs far S_vchs_692_1 = {&var331,&var280,&var241,NULL,NULL,NULL,NULL,&bRM_2_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var242,NULL};
_S_asmot far S_asmot_570_1 = {NULL,NULL,NULL,NULL,&fRM_1_,&fRM_0_,NULL,NULL,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,NULL,&vainSFloat,&var243,&var244,&vainSBool,&vainSBool,&vainSFloat,&var245,&var246,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_asmot far S_asmot_556_1 = {NULL,NULL,NULL,NULL,&fRM_1_,&fRM_0_,NULL,NULL,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,NULL,&vainSFloat,&var247,&var248,&vainSBool,&vainSBool,&vainSFloat,&var249,&var250,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_asmot far S_asmot_447_1 = {NULL,NULL,NULL,NULL,&fRM_1_,&fRM_0_,NULL,NULL,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,NULL,&vainSFloat,&var251,&var252,&vainSBool,&vainSBool,&vainSFloat,&var253,&var254,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_asmot far S_asmot_433_1 = {NULL,NULL,NULL,NULL,&fRM_1_,&fRM_0_,NULL,NULL,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,NULL,&vainSFloat,&var255,&var256,&vainSBool,&vainSBool,&vainSFloat,&var257,&var258,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_asmot far S_asmot_484_1 = {NULL,NULL,NULL,NULL,&fRM_1_0,NULL,NULL,NULL,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,NULL,&vainSFloat,&var259,&var260,&vainSBool,&vainSBool,&vainSFloat,&var261,&var262,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_asmot far S_asmot_385_1 = {NULL,NULL,NULL,NULL,&fRM_1_0,NULL,NULL,NULL,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,NULL,&vainSFloat,&var263,&var264,&vainSBool,&vainSBool,&vainSFloat,&var265,&var266,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_asmot far S_asmot_370_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var267,&var268,&var269,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_asmot far S_asmot_354_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var270,&var271,&var272,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_asmot far S_asmot_882_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&vainSFloat,&var273,&var274,&var275,&var276,&vainSFloat,&var277,&var278,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_azbars far S_azbars_176_1 = {&var316,&var300,&var286,&var330,NULL,NULL,&var190,NULL,&var172,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var223,&var225,NULL,NULL,NULL,NULL,NULL,&var279,&var280,&var281,&var282,&var283,&var284,&var285,NULL,NULL,NULL,NULL,NULL,NULL,NULL,array_m176_C0_1,NULL,NULL,NULL};
_S_orrsim far S_orrsim_290_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var200,NULL,&lRM_1_,NULL,NULL,NULL,NULL,&lRM_0_,array_m290_Vr_1,NULL,&var169,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var286,&var287,&var288,&var289,&var290,&vainSFloat,&vainSFloat,&var291,&var292,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_orrsim far S_orrsim_126_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var208,NULL,&lRM_1_,NULL,NULL,NULL,NULL,&lRM_0_,array_m126_Vr_1,NULL,&var171,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var293,&var294,&var295,&var296,&var297,&vainSFloat,&vainSFloat,&var298,&var299,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_orrsim far S_orrsim_258_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var201,NULL,&var203,NULL,NULL,NULL,NULL,&lRM_1_,array_m258_Vr_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var300,&var301,&vainSBool,&var302,&var303,&vainSFloat,&vainSFloat,&var304,&var305,&var306,&var307,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_orrsim far S_orrsim_94_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var213,NULL,&var215,NULL,NULL,NULL,NULL,&lRM_1_,array_m94_Vr_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var308,&var309,&vainSBool,&var310,&var311,&vainSFloat,&vainSFloat,&var312,&var313,&var314,&var315,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_orrsim far S_orrsim_223_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var207,&lRM_1_,&var206,NULL,NULL,NULL,NULL,&lRM_1_,array_m223_Vr_1,NULL,&fRM_0_,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var316,&var317,&vainSBool,&var318,&var319,&vainSFloat,&vainSFloat,&var320,&vainSBool,&var321,&var322,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_orrsim far S_orrsim_59_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var212,&lRM_1_,&var211,NULL,NULL,NULL,NULL,&lRM_1_,array_m59_Vr_1,NULL,&fRM_0_,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var323,&var324,&var325,&var326,&var327,&vainSFloat,&vainSFloat,&vainSBool,&vainSBool,&var328,&var329,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_azbars far S_azbars_14_1 = {&var323,&var308,&var293,&var279,NULL,NULL,&var187,NULL,&var173,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var223,&var225,NULL,NULL,NULL,NULL,NULL,&var330,&var331,&var332,&var333,&var334,&var335,&vainSFloat,NULL,NULL,NULL,NULL,NULL,NULL,NULL,array_m14_C0_1,NULL,NULL,NULL};


  #ifdef SIMUL_MODE
void __stdcall GetMainHinst(HINSTANCE Hi,__int8 *SigBuf,__int8 *IntBuf,__int8 *InEEPBuf,__int8 *ExEEPBuf)
{
 PutErrors = ((void(__stdcall*)(char*,char**))GetProcAddress( Hi ,"PutErrors"));
 Set_Eeprom = ((char(__stdcall*)(char,int,void*,int,int))GetProcAddress( Hi ,"Set_Eeprom"));
 Get_Eeprom = ((char(__stdcall*)(char,int,void*,int,int))GetProcAddress( Hi ,"Get_Eeprom"));
 GetBranch = ((void(__stdcall*)(char*,void*,int,int,int))GetProcAddress( Hi ,"GetBranch"));
 GetFSize  = ((long(__stdcall*)(char))GetProcAddress( Hi ,"GetFSize"));
 SignalBuffer = SigBuf;
 InternalBuf = IntBuf;
 IntEEPROMBuffer = InEEPBuf;
 SpaEEPROMBuf = ExEEPBuf;
 InitInternalParametr();
 bFirstEnterFlag.b=0;
 bFirstEnterFlag.error=0;
}
void __stdcall GetAddress(TStringList *sl)
{
}
void __stdcall simulmain(DVE_Parametrs *Par)
#else
void Scheme()
#endif
{
static int NewFEF = 0;
if (NewFEF==0){++NewFEF;bFirstEnterFlag.b=0;}
else bFirstEnterFlag.b=1;
if(bFirstEnterFlag.b==0){ InitInternalParametr(); }
#ifndef SIMUL_MODE
 UpdateTakt();
 CheckSignals();
 watch_dg();
 UpdateEEPROM(EEPROMInSignal, EEPROMOutSignal);
 if (!CycleStopped) {
#else
 CheckSignals(Par);
#endif
  noto((&S_noto_84_1));
  noto((&S_noto_248_1));
  noto((&S_noto_580_1));
  noto((&S_noto_581_1));
  ovb1((&S_ovb1_30_1));
  ovb1((&S_ovb1_191_1));
  noto((&S_noto_494_1));
  bol((&S_bol_918_1));
  bol((&S_bol_928_1));
  bol((&S_bol_906_1));
  bol((&S_bol_927_1));
  bol((&S_bol_930_1));
  zpfs((&S_zpfs_605_1));
  zpfs((&S_zpfs_617_1));
  noto((&S_noto_464_1));
  noto((&S_noto_462_1));
  noto((&S_noto_472_1));
  noto((&S_noto_471_1));
  to3val((&S_to3val_944_1));
  asmot((&S_asmot_882_1));
  asmot((&S_asmot_354_1));
  asmot((&S_asmot_370_1));
  asmot((&S_asmot_385_1));
  asmot((&S_asmot_484_1));
  asmot((&S_asmot_433_1));
  asmot((&S_asmot_447_1));
  asmot((&S_asmot_556_1));
  asmot((&S_asmot_570_1));
  fsumo((&S_fsumo_886_1));
  inf((&S_inf_9_1));
  inf((&S_inf_7_1));
  fsubo((&S_fsubo_8_1));
  fsubo((&S_fsubo_360_1));
  noto((&S_noto_45_1));
  noto((&S_noto_46_1));
  noto((&S_noto_209_1));
  noto((&S_noto_210_1));
  orn((&S_orn_614_1));
  asmot((&S_asmot_582_1));
  asmot((&S_asmot_583_1));
  noto((&S_noto_590_1));
  noto((&S_noto_592_1));
  noto((&S_noto_459_1));
  noto((&S_noto_492_1));
  lk((&S_lk_498_1));
  orn((&S_orn_895_1));
  to3val((&S_to3val_521_1));
  toao((&S_toao_526_1));
  toao((&S_toao_527_1));
  to3val((&S_to3val_499_1));
  toao((&S_toao_507_1));
  twobool((&S_twobool_542_1));
  twobool((&S_twobool_639_1));
  twobool((&S_twobool_659_1));
  twobool((&S_twobool_640_1));
  twobool((&S_twobool_660_1));
  twobool((&S_twobool_676_1));
  to3val((&S_to3val_818_1));
  ktoenc((&S_ktoenc_826_1));
  to3val((&S_to3val_816_1));
  ktoenc((&S_ktoenc_824_1));
  twobool((&S_twobool_540_1));
  twobool((&S_twobool_541_1));
  twobool((&S_twobool_678_1));
  twobool((&S_twobool_677_1));
  twobool((&S_twobool_680_1));
  twobool((&S_twobool_679_1));
  twobool((&S_twobool_1026_1));
  twobool((&S_twobool_842_1));
  twobool((&S_twobool_844_1));
  twobool((&S_twobool_843_1));
  to3val((&S_to3val_522_1));
  toao((&S_toao_528_1));
  toao((&S_toao_529_1));
  twobool((&S_twobool_525_1));
  twobool((&S_twobool_970_1));
  twobool((&S_twobool_985_1));
  twobool((&S_twobool_1002_1));
  twobool((&S_twobool_1024_1));
  twobool((&S_twobool_805_1));
  twobool((&S_twobool_971_1));
  twobool((&S_twobool_972_1));
  twobool((&S_twobool_973_1));
  twobool((&S_twobool_974_1));
  twobool((&S_twobool_1022_1));
  twobool((&S_twobool_801_1));
  twobool((&S_twobool_802_1));
  twobool((&S_twobool_804_1));
  twobool((&S_twobool_803_1));
  twobool((&S_twobool_829_1));
  twobool((&S_twobool_827_1));
  twobool((&S_twobool_830_1));
  twobool((&S_twobool_828_1));
  twobool((&S_twobool_1006_1));
  twobool((&S_twobool_1007_1));
  twobool((&S_twobool_1008_1));
  twobool((&S_twobool_1027_1));
  twobool((&S_twobool_56_1));
  twobool((&S_twobool_41_1));
  twobool((&S_twobool_218_1));
  twobool((&S_twobool_202_1));
  zpfs((&S_zpfs_591_1));
  zpfs((&S_zpfs_593_1));
  or2((&S_or2_896_1));
  or2((&S_or2_903_1));
  or2((&S_or2_910_1));
  or2((&S_or2_919_1));
  ampl((&S_ampl_361_1));
  rs((&S_rs_458_1));
  rs((&S_rs_457_1));
  rs((&S_rs_470_1));
  rs((&S_rs_469_1));
  twobool((&S_twobool_524_1));
  twobool((&S_twobool_508_1));
  twobool((&S_twobool_641_1));
  twobool((&S_twobool_642_1));
  twobool((&S_twobool_663_1));
  twobool((&S_twobool_664_1));
  twobool((&S_twobool_643_1));
  twobool((&S_twobool_644_1));
  twobool((&S_twobool_665_1));
  twobool((&S_twobool_666_1));
  twobool((&S_twobool_986_1));
  twobool((&S_twobool_987_1));
  twobool((&S_twobool_988_1));
  twobool((&S_twobool_989_1));
  twobool((&S_twobool_806_1));
  twobool((&S_twobool_807_1));
  noto((&S_noto_612_1));
  andn((&S_andn_86_1));
  andn((&S_andn_85_1));
  andn((&S_andn_47_1));
  andn((&S_andn_48_1));
  andn((&S_andn_117_1));
  andn((&S_andn_211_1));
  andn((&S_andn_212_1));
  andn((&S_andn_250_1));
  andn((&S_andn_249_1));
  andn((&S_andn_282_1));
  noto((&S_noto_897_1));
  andn((&S_andn_892_1));
  asmot((&S_asmot_595_1));
  asmot((&S_asmot_596_1));
  asmot((&S_asmot_463_1));
  asmot((&S_asmot_473_1));
  asmot((&S_asmot_461_1));
  noto((&S_noto_904_1));
  andn((&S_andn_900_1));
  noto((&S_noto_911_1));
  andn((&S_andn_908_1));
  noto((&S_noto_920_1));
  andn((&S_andn_915_1));
  lk((&S_lk_497_1));
  noto((&S_noto_894_1));
  andn((&S_andn_890_1));
  twobool((&S_twobool_1025_1));
  to3val((&S_to3val_496_1));
  toao((&S_toao_503_1));
  twobool((&S_twobool_1003_1));
  twobool((&S_twobool_1005_1));
  twobool((&S_twobool_1004_1));
  twobool((&S_twobool_1023_1));
  orrsim((&S_orrsim_59_1));
  orrsim((&S_orrsim_223_1));
  orrsim((&S_orrsim_94_1));
  orrsim((&S_orrsim_258_1));
  orrsim((&S_orrsim_126_1));
  orrsim((&S_orrsim_290_1));
  azbars((&S_azbars_176_1));
  bol((&S_bol_603_1));
  bol((&S_bol_609_1));
  bol((&S_bol_619_1));
  mod1((&S_mod1_625_1));
  fsubo((&S_fsubo_74_1));
  fsubo((&S_fsubo_238_1));
  fsubo((&S_fsubo_275_1));
  fsubo((&S_fsubo_111_1));
  orn((&S_orn_620_1));
  react((&S_react_194_1));
  orn((&S_orn_604_1));
  orn((&S_orn_607_1));
  twobool((&S_twobool_144_1));
  to3val((&S_to3val_150_1));
  toao((&S_toao_155_1));
  toao((&S_toao_156_1));
  toao((&S_toao_157_1));
  twobool((&S_twobool_415_1));
  twobool((&S_twobool_416_1));
  twobool((&S_twobool_417_1));
  to3val((&S_to3val_414_1));
  ktoenc((&S_ktoenc_419_1));
  twobool((&S_twobool_418_1));
  twobool((&S_twobool_325_1));
  twobool((&S_twobool_309_1));
  twobool((&S_twobool_338_1));
  to3val((&S_to3val_313_1));
  ktoenc((&S_ktoenc_316_1));
  twobool((&S_twobool_337_1));
  twobool((&S_twobool_339_1));
  to3val((&S_to3val_323_1));
  ktoenc((&S_ktoenc_324_1));
  twobool((&S_twobool_340_1));
  twobool((&S_twobool_310_1));
  twobool((&S_twobool_311_1));
  twobool((&S_twobool_326_1));
  twobool((&S_twobool_327_1));
  ampl((&S_ampl_630_1));
  twobool((&S_twobool_398_1));
  twobool((&S_twobool_399_1));
  twobool((&S_twobool_397_1));
  to3val((&S_to3val_400_1));
  ktoenc((&S_ktoenc_406_1));
  twobool((&S_twobool_939_1));
  twobool((&S_twobool_940_1));
  twobool((&S_twobool_943_1));
  to3val((&S_to3val_935_1));
  ktoenc((&S_ktoenc_942_1));
  to3val((&S_to3val_954_1));
  ktoenc((&S_ktoenc_959_1));
  twobool((&S_twobool_956_1));
  twobool((&S_twobool_957_1));
  twobool((&S_twobool_960_1));
  andn((&S_andn_345_1));
  twobool((&S_twobool_396_1));
  azbars((&S_azbars_14_1));
  vchs((&S_vchs_692_1));
  vchs((&S_vchs_702_1));
  vchs((&S_vchs_711_1));
  vchs((&S_vchs_720_1));
  vchs((&S_vchs_728_1));
  vchs((&S_vchs_737_1));
  vchs((&S_vchs_746_1));
  vchs((&S_vchs_754_1));
  vchs((&S_vchs_763_1));
  vchs((&S_vchs_772_1));
  vchs((&S_vchs_780_1));
  vchs((&S_vchs_789_1));
  twobool((&S_twobool_143_1));
  to3val((&S_to3val_152_1));
  toao((&S_toao_158_1));
  toao((&S_toao_159_1));
  toao((&S_toao_160_1));
  to3val((&S_to3val_631_1));
  vchs((&S_vchs_852_1));
  vchs((&S_vchs_860_1));
  vchs((&S_vchs_870_1));
  signal_R0IS01FI0.i = iRM_1_.i;
  signal_R0IS01FI0.error = iRM_1_.error;
  signal_A0IT03IRP.i = var157.i;
  signal_A0IT03IRP.error = var157.error;
  signal_B0IT03IRP.i = var151.i;
  signal_B0IT03IRP.error = var151.error;
  fplet(&signal_R0IN03FI3.f,&var233.f);
  signal_R0IN03FI3.error = var233.error;
  fplet(&signal_R0IN02FI3.f,&var234.f);
  signal_R0IN02FI3.error = var234.error;
  fplet(&signal_R0IN03FI2.f,&var236.f);
  signal_R0IN03FI2.error = var236.error;
  fplet(&signal_R0IN07RIP.f,&var2.f);
  signal_R0IN07RIP.error = var2.error;
  fplet(&signal_R0IN06RIP.f,&var1.f);
  signal_R0IN06RIP.error = var1.error;
  fplet(&signal_R0IN03RIP.f,&var3.f);
  signal_R0IN03RIP.error = var3.error;
  fplet(&signal_R0IN02RIP.f,&var4.f);
  signal_R0IN02RIP.error = var4.error;
  fplet(&signal_R0IN01RIP.f,&var5.f);
  signal_R0IN01RIP.error = var5.error;
  fplet(&signal_R0IN02FI2.f,&var237.f);
  signal_R0IN02FI2.error = var237.error;
  fplet(&signal_R0IN03FI1.f,&var239.f);
  signal_R0IN03FI1.error = var239.error;
  fplet(&signal_R0IN02FI1.f,&var240.f);
  signal_R0IN02FI1.error = var240.error;
  fplet(&signal_R0IN03FI4.f,&var230.f);
  signal_R0IN03FI4.error = var230.error;
  fplet(&signal_R0IN02FI4.f,&var231.f);
  signal_R0IN02FI4.error = var231.error;
  fplet(&signal_R0IN01FI3.f,&var235.f);
  signal_R0IN01FI3.error = var235.error;
  fplet(&signal_R0IN01FI2.f,&var238.f);
  signal_R0IN01FI2.error = var238.error;
  fplet(&signal_R0IN01FI4.f,&var232.f);
  signal_R0IN01FI4.error = var232.error;
  fplet(&signal_R0IN01FI1.f,&var242.f);
  signal_R0IN01FI1.error = var242.error;
  signal_R4VS12LDU.b = var7.b;
  signal_R4VS12LDU.error = var7.error;
  signal_R4VS22LDU.b = var6.b;
  signal_R4VS22LDU.error = var6.error;
  signal_R1VS12LDU.b = var11.b;
  signal_R1VS12LDU.error = var11.error;
  signal_R2VS12LDU.b = var9.b;
  signal_R2VS12LDU.error = var9.error;
  signal_R2VS22LDU.b = var8.b;
  signal_R2VS22LDU.error = var8.error;
  signal_R1VS22LDU.b = var10.b;
  signal_R1VS22LDU.error = var10.error;
  signal_B5VS12LDU.b = var13.b;
  signal_B5VS12LDU.error = var13.error;
  signal_B5VS22LDU.b = var12.b;
  signal_B5VS22LDU.error = var12.error;
  signal_A5VS12LDU.b = var15.b;
  signal_A5VS12LDU.error = var15.error;
  signal_A5VS22LDU.b = var14.b;
  signal_A5VS22LDU.error = var14.error;
  signal_B6VS12LDU.b = var17.b;
  signal_B6VS12LDU.error = var17.error;
  signal_B6VS22LDU.b = var16.b;
  signal_B6VS22LDU.error = var16.error;
  signal_A6VS12LDU.b = var19.b;
  signal_A6VS12LDU.error = var19.error;
  signal_A6VS22LDU.b = var18.b;
  signal_A6VS22LDU.error = var18.error;
  signal_B8IS21LDU.b = var66.b;
  signal_B8IS21LDU.error = var66.error;
  signal_B8IS11LDU.b = var64.b;
  signal_B8IS11LDU.error = var64.error;
  signal_A1VP81LZZ.b = var20.b;
  signal_A1VP81LZZ.error = var20.error;
  signal_B1VP81LZZ.b = var21.b;
  signal_B1VP81LZZ.error = var21.error;
  signal_B2IS33LDU.b = var22.b;
  signal_B2IS33LDU.error = var22.error;
  fplet(&signal_A0VN01RIM.f,&var335.f);
  signal_A0VN01RIM.error = var335.error;
  signal_B2IS32LIM.b = var304.b;
  signal_B2IS32LIM.error = var304.error;
  signal_B2IS11LIM.b = var306.b;
  signal_B2IS11LIM.error = var306.error;
  signal_A2IS32LIM.b = var312.b;
  signal_A2IS32LIM.error = var312.error;
  signal_A2IS11LIM.b = var314.b;
  signal_A2IS11LIM.error = var314.error;
  signal_B1IS32LIM.b = var320.b;
  signal_B1IS32LIM.error = var320.error;
  signal_B1IS11LIM.b = var321.b;
  signal_B1IS11LIM.error = var321.error;
  signal_A1IS32LIM.b = var325.b;
  signal_A1IS32LIM.error = var325.error;
  signal_A1IS11LIM.b = var328.b;
  signal_A1IS11LIM.error = var328.error;
  signal_R0IS02LDU.b = lEM_R0IE02LRP.b;
  signal_R0IS02LDU.error = lEM_R0IE02LRP.error;
  signal_B4IS10LDU.b = var43.b;
  signal_B4IS10LDU.error = var43.error;
  signal_A4IS10LDU.b = var42.b;
  signal_A4IS10LDU.error = var42.error;
  signal_B1IE04LDU.b = var44.b;
  signal_B1IE04LDU.error = var44.error;
  signal_B1IE03LDU.b = var45.b;
  signal_B1IE03LDU.error = var45.error;
  signal_A1IE04LDU.b = var46.b;
  signal_A1IE04LDU.error = var46.error;
  signal_A1IE03LDU.b = var47.b;
  signal_A1IE03LDU.error = var47.error;
  signal_B1IS12LDU.b = var48.b;
  signal_B1IS12LDU.error = var48.error;
  signal_B1IS11LDU.b = var49.b;
  signal_B1IS11LDU.error = var49.error;
  signal_B1IS21LDU.b = var50.b;
  signal_B1IS21LDU.error = var50.error;
  signal_B1IC01UDU.l = var51.l;
  signal_B1IC01UDU.error = var51.error;
  signal_A1IC01UDU.l = var53.l;
  signal_A1IC01UDU.error = var53.error;
  signal_A1IS12LDU.b = var55.b;
  signal_A1IS12LDU.error = var55.error;
  signal_A1IS11LDU.b = var56.b;
  signal_A1IS11LDU.error = var56.error;
  signal_A1IS21LDU.b = var57.b;
  signal_A1IS21LDU.error = var57.error;
  signal_B6IS21LDU.b = var58.b;
  signal_B6IS21LDU.error = var58.error;
  signal_B6IS11LDU.b = var59.b;
  signal_B6IS11LDU.error = var59.error;
  signal_A6IS21LDU.b = var60.b;
  signal_A6IS21LDU.error = var60.error;
  signal_A6IS11LDU.b = var61.b;
  signal_A6IS11LDU.error = var61.error;
  signal_A8IS12LDU.b = var62.b;
  signal_A8IS12LDU.error = var62.error;
  signal_A8IS22LDU.b = var63.b;
  signal_A8IS22LDU.error = var63.error;
  signal_B8IS12LDU.b = var65.b;
  signal_B8IS12LDU.error = var65.error;
  signal_B8IS22LDU.b = var67.b;
  signal_B8IS22LDU.error = var67.error;
  signal_R4IS12LDU.b = var68.b;
  signal_R4IS12LDU.error = var68.error;
  signal_R4IS22LDU.b = var69.b;
  signal_R4IS22LDU.error = var69.error;
  signal_R4IS21LDU.b = var70.b;
  signal_R4IS21LDU.error = var70.error;
  signal_R4IS11LDU.b = var71.b;
  signal_R4IS11LDU.error = var71.error;
  signal_B4VP82LDU.b = var73.b;
  signal_B4VP82LDU.error = var73.error;
  signal_A4VP82LDU.b = var72.b;
  signal_A4VP82LDU.error = var72.error;
  signal_R2IS21LDU.b = var74.b;
  signal_R2IS21LDU.error = var74.error;
  signal_R2IS11LDU.b = var75.b;
  signal_R2IS11LDU.error = var75.error;
  signal_R1IS21LDU.b = var76.b;
  signal_R1IS21LDU.error = var76.error;
  signal_R1IS11LDU.b = var77.b;
  signal_R1IS11LDU.error = var77.error;
  signal_B4IS21LDU.b = var78.b;
  signal_B4IS21LDU.error = var78.error;
  signal_B4IS11LDU.b = var79.b;
  signal_B4IS11LDU.error = var79.error;
  signal_R8IS11LDU.b = var80.b;
  signal_R8IS11LDU.error = var80.error;
  signal_A4IS21LDU.b = var81.b;
  signal_A4IS21LDU.error = var81.error;
  signal_A4IS11LDU.b = var82.b;
  signal_A4IS11LDU.error = var82.error;
  signal_R5IS21LDU.b = var83.b;
  signal_R5IS21LDU.error = var83.error;
  signal_R5IS11LDU.b = var84.b;
  signal_R5IS11LDU.error = var84.error;
  signal_R3IS21LDU.b = var85.b;
  signal_R3IS21LDU.error = var85.error;
  signal_R3IS11LDU.b = var86.b;
  signal_R3IS11LDU.error = var86.error;
  signal_B2VP82LDU.b = var87.b;
  signal_B2VP82LDU.error = var87.error;
  signal_B2IP01IZ2.i = var89.i;
  signal_B2IP01IZ2.error = var89.error;
  signal_B2IP01IZ1.i = var90.i;
  signal_B2IP01IZ1.error = var90.error;
  signal_B2IC01UDU.l = var93.l;
  signal_B2IC01UDU.error = var93.error;
  signal_B2IS12LDU.b = var95.b;
  signal_B2IS12LDU.error = var95.error;
  signal_B2IS11LDU.b = var96.b;
  signal_B2IS11LDU.error = var96.error;
  signal_B2IS21LDU.b = var97.b;
  signal_B2IS21LDU.error = var97.error;
  signal_B9IS21LDU.b = var98.b;
  signal_B9IS21LDU.error = var98.error;
  signal_B9IS11LDU.b = var99.b;
  signal_B9IS11LDU.error = var99.error;
  signal_A9IS21LDU.b = var100.b;
  signal_A9IS21LDU.error = var100.error;
  signal_A9IS11LDU.b = var101.b;
  signal_A9IS11LDU.error = var101.error;
  signal_B5IS21LDU.b = var102.b;
  signal_B5IS21LDU.error = var102.error;
  signal_B5IS11LDU.b = var103.b;
  signal_B5IS11LDU.error = var103.error;
  signal_A5IS21LDU.b = var104.b;
  signal_A5IS21LDU.error = var104.error;
  signal_A5IS11LDU.b = var105.b;
  signal_A5IS11LDU.error = var105.error;
  signal_B0VP81LZZ.b = var107.b;
  signal_B0VP81LZZ.error = var107.error;
  signal_A0VP81LZZ.b = var108.b;
  signal_A0VP81LZZ.error = var108.error;
  signal_B8IC01UDU.l = var109.l;
  signal_B8IC01UDU.error = var109.error;
  signal_A8IC01UDU.l = var111.l;
  signal_A8IC01UDU.error = var111.error;
  signal_R6IS68LZZ.b = var113.b;
  signal_R6IS68LZZ.error = var113.error;
  signal_R6IS67LZZ.b = var114.b;
  signal_R6IS67LZZ.error = var114.error;
  signal_R6IS66LZZ.b = var115.b;
  signal_R6IS66LZZ.error = var115.error;
  signal_R6IS65LDU.b = var117.b;
  signal_R6IS65LDU.error = var117.error;
  signal_R6IS64LDU.b = var116.b;
  signal_R6IS64LDU.error = var116.error;
  signal_R6IS63LDU.b = var119.b;
  signal_R6IS63LDU.error = var119.error;
  signal_R6IS62LDU.b = var118.b;
  signal_R6IS62LDU.error = var118.error;
  signal_B3IS22LDU.b = var120.b;
  signal_B3IS22LDU.error = var120.error;
  signal_A3IS22LDU.b = var121.b;
  signal_A3IS22LDU.error = var121.error;
  signal_B3IS11LDU.b = var122.b;
  signal_B3IS11LDU.error = var122.error;
  signal_A3IS11LDU.b = var123.b;
  signal_A3IS11LDU.error = var123.error;
  signal_A3IP02IDU.i = var124.i;
  signal_A3IP02IDU.error = var124.error;
  signal_B3VP81LDU.b = var127.b;
  signal_B3VP81LDU.error = var127.error;
  signal_A3VP81LDU.b = var126.b;
  signal_A3VP81LDU.error = var126.error;
  signal_B3IS33LDU.b = var130.b;
  signal_B3IS33LDU.error = var130.error;
  signal_B3IC01UDU.l = var131.l;
  signal_B3IC01UDU.error = var131.error;
  signal_B3IS31LDU.b = var133.b;
  signal_B3IS31LDU.error = var133.error;
  signal_B3IP02IDU.i = var128.i;
  signal_B3IP02IDU.error = var128.error;
  signal_A3IS33LDU.b = var134.b;
  signal_A3IS33LDU.error = var134.error;
  signal_A3IC01UDU.l = var135.l;
  signal_A3IC01UDU.error = var135.error;
  signal_A3IS31LDU.b = var137.b;
  signal_A3IS31LDU.error = var137.error;
  signal_A2VP82LDU.b = var88.b;
  signal_A2VP82LDU.error = var88.error;
  signal_A2IP01IZ2.i = var138.i;
  signal_A2IP01IZ2.error = var138.error;
  signal_A2IP01IZ1.i = var139.i;
  signal_A2IP01IZ1.error = var139.error;
  signal_B3IS21LDU.b = var140.b;
  signal_B3IS21LDU.error = var140.error;
  signal_A3IS21LDU.b = var141.b;
  signal_A3IS21LDU.error = var141.error;
  signal_A2IS33LDU.b = var142.b;
  signal_A2IS33LDU.error = var142.error;
  signal_A2IC01UDU.l = var143.l;
  signal_A2IC01UDU.error = var143.error;
  signal_A2IS12LDU.b = var145.b;
  signal_A2IS12LDU.error = var145.error;
  signal_A2IS11LDU.b = var146.b;
  signal_A2IS11LDU.error = var146.error;
  signal_A2IS21LDU.b = var147.b;
  signal_A2IS21LDU.error = var147.error;
  signal_B0IT02IZ2.i = var152.i;
  signal_B0IT02IZ2.error = var152.error;
  signal_B0IT01IZ1.i = var153.i;
  signal_B0IT01IZ1.error = var153.error;
  signal_A0IT02IZ2.i = var158.i;
  signal_A0IT02IZ2.error = var158.error;
  signal_A0IT01IZ1.i = var161.i;
  signal_A0IT01IZ1.error = var161.error;
  signal_R6IS21LDU.b = var159.b;
  signal_R6IS21LDU.error = var159.error;
  signal_B7AS31LDU.b = var160.b;
  signal_B7AS31LDU.error = var160.error;
  signal_A7AS31LDU.b = var165.b;
  signal_A7AS31LDU.error = var165.error;
  signal_B3IS35LDU.b = var168.b;
  signal_B3IS35LDU.error = var168.error;
  signal_A3IS35LDU.b = var170.b;
  signal_A3IS35LDU.error = var170.error;
  signal_R7II73LZ2.b = var217.b;
  signal_R7II73LZ2.error = var217.error;
  signal_R7II71LZ2.b = var178.b;
  signal_R7II71LZ2.error = var178.error;
  signal_R7II72LZ2.b = var177.b;
  signal_R7II72LZ2.error = var177.error;
  signal_R7II72LZ1.b = var177.b;
  signal_R7II72LZ1.error = var177.error;
  signal_R7II71LZ1.b = var178.b;
  signal_R7II71LZ1.error = var178.error;
  signal_R7II73LZ1.b = var217.b;
  signal_R7II73LZ1.error = var217.error;
  fplet(&signal_R0SR01RIM.f,&var179.f);
  signal_R0SR01RIM.error = var179.error;
  fplet(&signal_R0ST01RIM.f,&var284.f);
  signal_R0ST01RIM.error = var284.error;
  fplet(&signal_R0SR02RIM.f,&var285.f);
  signal_R0SR02RIM.error = var285.error;
  fplet(&signal_R0CR02RIM.f,&var223.f);
  signal_R0CR02RIM.error = var223.error;
  fplet(&signal_R0CR01RIM.f,&var225.f);
  signal_R0CR01RIM.error = var225.error;
  fplet(&signal_B0SN08RIM.f,&var280.f);
  signal_B0SN08RIM.error = var280.error;
  fplet(&signal_A0SN08RIM.f,&var331.f);
  signal_A0SN08RIM.error = var331.error;
  fplet(&signal_B0SR01RIM.f,&var281.f);
  signal_B0SR01RIM.error = var281.error;
  fplet(&signal_A0SR01RIM.f,&var332.f);
  signal_A0SR01RIM.error = var332.error;

  bFirstEnterFlag.b = 1;
#ifndef SIMUL_MODE
 watch_dg();
 InvertSignals();
 }
#else
 UnloadSignals();
#endif
}


void LoadSignals()
{
#ifndef SIMUL_MODE
 if (WHICH_SIDE)
 SignalBuffer = (char*)(28672);
  else
 SignalBuffer =(char*)(28672+4096);
#endif
}
  #ifdef SIMUL_MODE
void __stdcall InitSignals(void)
#else
void InitSignals(void)
#endif
{ char *i , *j;
#ifdef SIMUL_MODE
 setmem(InternalBuf,InternalBufSize,0);
#else
 for(i=InternalBuf,j = InternalBuf + InternalBufSize; i < j ; i++) *i = 0;
#endif
 LoadSignals();
 SignalBuffer[4] = 3;
#ifndef SIMUL_MODE
 SignalBuffer[PBLENGTH/2-4] = ~((unsigned char)3);
#endif
#ifndef SIMUL_MODE
 InvertSignals();
#endif
}

#ifndef SIMUL_MODE
void CheckSignals(void)
{
 LoadSignals();
#else
void __stdcall CheckSignals(DVE_Parametrs *Par)
{
  AllParams = Par;
#endif
#ifdef CONTROL
#ifndef SIMUL_MODE
  CheckSBool(5);
#else
ParExchange("A1AD11LDU",3,&SignalBuffer[5],"Сигнал на перемещение ББ1 вверх",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(7);
#else
ParExchange("A1AD21LDU",3,&SignalBuffer[7],"Сигнал на перемещение ББ1 вниз",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(9);
#else
ParExchange("A1AD01LDU",3,&SignalBuffer[9],"Разрешение движения ББ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(11);
#else
ParExchange("A1AD02LDU",3,&SignalBuffer[11],"0-й бит скорости ББ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(13);
#else
ParExchange("A1AD03LDU",3,&SignalBuffer[13],"1-й бит скорости ББ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(15);
#else
ParExchange("A1AD04LDU",3,&SignalBuffer[15],"2-й бит скорости ББ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(17);
#else
ParExchange("A1AD05LDU",3,&SignalBuffer[17],"паритет команды на ББ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(19);
#else
ParExchange("B1AD11LDU",3,&SignalBuffer[19],"Сигнал на перемещение ББ2 вверх",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(21);
#else
ParExchange("B1AD21LDU",3,&SignalBuffer[21],"Сигнал на перемещение ББ2 вниз",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(23);
#else
ParExchange("B1AD01LDU",3,&SignalBuffer[23],"Разрешение движения ББ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(25);
#else
ParExchange("B1AD02LDU",3,&SignalBuffer[25],"0-й бит скорости  ББ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(27);
#else
ParExchange("B1AD03LDU",3,&SignalBuffer[27],"1-й бит скорости ББ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(29);
#else
ParExchange("B1AD04LDU",3,&SignalBuffer[29],"2-й бит скорости ББ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(31);
#else
ParExchange("B1AD05LDU",3,&SignalBuffer[31],"паритет команды на ББ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(33);
#else
ParExchange("A2AD11LDU",3,&SignalBuffer[33],"Сигнал на перемещение РБ1 вверх",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(35);
#else
ParExchange("A2AD21LDU",3,&SignalBuffer[35],"Сигнал на перемещение РБ1 вниз",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(37);
#else
ParExchange("A2AD01LDU",3,&SignalBuffer[37],"Разрешение движения РБ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(39);
#else
ParExchange("A2AD02LDU",3,&SignalBuffer[39],"0-й бит скорости РБ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(41);
#else
ParExchange("A2AD03LDU",3,&SignalBuffer[41],"1-й бит скорости РБ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(43);
#else
ParExchange("A2AD04LDU",3,&SignalBuffer[43],"2-й бит скорости РБ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(45);
#else
ParExchange("A2AD05LDU",3,&SignalBuffer[45],"паритет команды на РБ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(47);
#else
ParExchange("A2AD33LDU",3,&SignalBuffer[47],"Клапан (Подъем РБ1) закрыть (обесточить)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(49);
#else
ParExchange("B2AD11LDU",3,&SignalBuffer[49],"Сигнал на перемещение РБ2 вверх",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(51);
#else
ParExchange("B2AD21LDU",3,&SignalBuffer[51],"Сигнал на перемещение РБ2 вниз",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(53);
#else
ParExchange("B2AD01LDU",3,&SignalBuffer[53],"Разрешение движения РБ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(55);
#else
ParExchange("B2AD02LDU",3,&SignalBuffer[55],"0-й бит скорости РБ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(57);
#else
ParExchange("B2AD03LDU",3,&SignalBuffer[57],"1-й бит скорости РБ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(59);
#else
ParExchange("B2AD04LDU",3,&SignalBuffer[59],"2-й бит скорости РБ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(61);
#else
ParExchange("B2AD05LDU",3,&SignalBuffer[61],"паритет команды на РБ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(63);
#else
ParExchange("B2AD33LDU",3,&SignalBuffer[63],"Клапан (Подъем РБ2) закрыть (обесточить)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(65);
#else
ParExchange("A3AD11LDU",3,&SignalBuffer[65],"Сигнал на перемещение ИС1 вверх",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(67);
#else
ParExchange("A3AD21LDU",3,&SignalBuffer[67],"Сигнал на перемещение ИС1 вниз",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(69);
#else
ParExchange("A3AD01LDU",3,&SignalBuffer[69],"Разрешение движения ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(71);
#else
ParExchange("A3AD02LDU",3,&SignalBuffer[71],"0-й бит скорости ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(73);
#else
ParExchange("A3AD03LDU",3,&SignalBuffer[73],"1-й бит скорости ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(75);
#else
ParExchange("A3AD04LDU",3,&SignalBuffer[75],"2-й бит скорости ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(77);
#else
ParExchange("A3AD05LDU",3,&SignalBuffer[77],"паритет команды на ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(79);
#else
ParExchange("A3AD33LDU",3,&SignalBuffer[79],"Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(81);
#else
ParExchange("B3AD11LDU",3,&SignalBuffer[81],"Сигнал на перемещение ИС2 вверх",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(83);
#else
ParExchange("B3AD21LDU",3,&SignalBuffer[83],"Сигнал на перемещение ИС2 вниз",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(85);
#else
ParExchange("B3AD01LDU",3,&SignalBuffer[85],"Разрешение движения ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(87);
#else
ParExchange("B3AD02LDU",3,&SignalBuffer[87],"0-й бит скорости ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(89);
#else
ParExchange("B3AD03LDU",3,&SignalBuffer[89],"1-й бит скорости ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(91);
#else
ParExchange("B3AD04LDU",3,&SignalBuffer[91],"2-й бит скорости ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(93);
#else
ParExchange("B3AD05LDU",3,&SignalBuffer[93],"паритет команды на ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(95);
#else
ParExchange("B3AD33LDU",3,&SignalBuffer[95],"Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(102);
#else
ParExchange("R4AD10LDU",3,&SignalBuffer[102],"Перемещение тележки вперед",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(104);
#else
ParExchange("R4AD20LDU",3,&SignalBuffer[104],"Перемещение тележки назад",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(106);
#else
ParExchange("B8AD10LDU",3,&SignalBuffer[106],"Перемещение АЗ2 вперед",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(108);
#else
ParExchange("B8AD20LDU",3,&SignalBuffer[108],"Перемещение АЗ2 назад",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(110);
#else
ParExchange("A8AD10LDU",3,&SignalBuffer[110],"Перемещение ДС2 вперед",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(112);
#else
ParExchange("A8AD20LDU",3,&SignalBuffer[112],"Перемещение ДС2 назад",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(114);
#else
ParExchange("A6AD10LDU",3,&SignalBuffer[114],"Открыть БЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(116);
#else
ParExchange("A6AD20LDU",3,&SignalBuffer[116],"Закрыть БЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(118);
#else
ParExchange("B6AD10LDU",3,&SignalBuffer[118],"Открыть БЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(120);
#else
ParExchange("B6AD20LDU",3,&SignalBuffer[120],"Закрыть БЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(122);
#else
ParExchange("R1AD10LDU",3,&SignalBuffer[122],"Опустить МДЗ1 в зону облучения",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(124);
#else
ParExchange("R1AD20LDU",3,&SignalBuffer[124],"Поднять МДЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(126);
#else
ParExchange("R2AD10LDU",3,&SignalBuffer[126],"Опустить МДЗ2 в зону облучения",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(128);
#else
ParExchange("R2AD20LDU",3,&SignalBuffer[128],"Поднять МДЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(130);
#else
ParExchange("A5AD10LDU",3,&SignalBuffer[130],"Поднять НЛ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(132);
#else
ParExchange("A5AD20LDU",3,&SignalBuffer[132],"Опустить НЛ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(134);
#else
ParExchange("B5AD10LDU",3,&SignalBuffer[134],"Поднять НЛ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(136);
#else
ParExchange("B5AD20LDU",3,&SignalBuffer[136],"Опустить НЛ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(163);
#else
ParExchange("R0AD14LDU",3,&SignalBuffer[163],"Имитация срабатывания верхней АС II УР",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(165);
#else
ParExchange("R8AD21LDU",3,&SignalBuffer[165],"Запуск системы инициирования",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(165);
#else
ParExchange("R8AD21LDU",3,&SignalBuffer[165],"Запуск системы инициирования",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(167);
#else
ParExchange("R0VZ71LZ1",3,&SignalBuffer[167],"Обобщенный сигнал по АЗ  1 канала",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(169);
#else
ParExchange("R0VZ71LZ2",3,&SignalBuffer[169],"Обобщенный сигнал по АЗ  2 канала",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(171);
#else
ParExchange("A2AD32LDU",3,&SignalBuffer[171],"Обесточить ЭМ РБ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(173);
#else
ParExchange("C2MD31LP1",3,&SignalBuffer[173],"Кнопка «СБРОС РБ»",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(173);
#else
ParExchange("C2MD31LP1",3,&SignalBuffer[173],"Кнопка «СБРОС РБ»",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(175);
#else
ParExchange("A2AD31LDU",3,&SignalBuffer[175],"Клапан (Сброс РБ1) открыть (обесточить)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(177);
#else
ParExchange("A1AD32LDU",3,&SignalBuffer[177],"Обесточить ЭМ ББ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(179);
#else
ParExchange("A1AD31LDU",3,&SignalBuffer[179],"Клапан (Сброс ББ1) открыть (обесточить)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(181);
#else
ParExchange("C1MD31LP2",3,&SignalBuffer[181],"Кнопка «СБРОС ББ»  на ОПУ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(181);
#else
ParExchange("C1MD31LP2",3,&SignalBuffer[181],"Кнопка «СБРОС ББ»  на ОПУ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(183);
#else
ParExchange("C1MD31LP1",3,&SignalBuffer[183],"Кнопка «СБРОС ББ»  на ОПУ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(183);
#else
ParExchange("C1MD31LP1",3,&SignalBuffer[183],"Кнопка «СБРОС ББ»  на ОПУ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(185);
#else
ParExchange("A3AD31LDU",3,&SignalBuffer[185],"Клапан (СПУСК ИС1) открыть (обесточить)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(187);
#else
ParExchange("B1AD31LDU",3,&SignalBuffer[187],"Клапан (Сброс ББ2) открыть (обесточить)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(189);
#else
ParExchange("B1AD32LDU",3,&SignalBuffer[189],"Обесточить ЭМ ББ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(191);
#else
ParExchange("B2AD31LDU",3,&SignalBuffer[191],"Клапан (Сброс РБ2) открыть (обесточить)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(193);
#else
ParExchange("B2AD32LDU",3,&SignalBuffer[193],"Обесточить ЭМ РБ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(195);
#else
ParExchange("B3AD31LDU",3,&SignalBuffer[195],"Клапан (СПУСК ИС2) открыть (обесточить)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(197);
#else
ParExchange("R0MW13LP2",3,&SignalBuffer[197],"Переключатель «СЕТЬ»",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(199);
#else
ParExchange("B9AD10LDU",3,&SignalBuffer[199],"Открыть клапан (Подъем НИ ДС2)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(201);
#else
ParExchange("A9AD10LDU",3,&SignalBuffer[201],"Открыть клапан (Подъем НИ ДС1)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(203);
#else
ParExchange("B4AD10LDU",3,&SignalBuffer[203],"Открыть клапан (Подъем НИ2)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(205);
#else
ParExchange("A4AD10LDU",3,&SignalBuffer[205],"Открыть клапан (Подъем НИ1)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(223);
#else
ParExchange("R0AD16LDU",3,&SignalBuffer[223],"Контроль  I-II УР. РАД",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(233);
#else
ParExchange("B3AD34LDU",3,&SignalBuffer[233],"Клапан (ВПИС2) открыть (обесточить)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(467);
#else
ParExchange("R0EE01LZ1",3,&SignalBuffer[467],"Питание  АКНП1  отключить",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(469);
#else
ParExchange("R0EE01LZ2",3,&SignalBuffer[469],"Питание  АКНП1  отключить",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(471);
#else
ParExchange("R0EE02LZ1",3,&SignalBuffer[471],"Питание  АКНП  отключить",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(473);
#else
ParExchange("R0EE03LZ1",3,&SignalBuffer[473],"Питание  АКНП3  отключить",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(475);
#else
ParExchange("R0EE04LZ1",3,&SignalBuffer[475],"Питание  АКНП4  отключить",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(477);
#else
ParExchange("R0EE02LZ2",3,&SignalBuffer[477],"Питание  АКНП  отключить",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(479);
#else
ParExchange("R0EE03LZ2",3,&SignalBuffer[479],"Питание  АКНП3  отключить",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(481);
#else
ParExchange("R0EE04LZ2",3,&SignalBuffer[481],"Питание  АКНП4  отключить",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(485);
#else
ParExchange("A3AD34LDU",3,&SignalBuffer[485],"Клапан (ВПИС ИС1) открыть (обесточить)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(546);
#else
ParExchange("A7AP31LDU",3,&SignalBuffer[546],"Клапан (Обдув АЗ1) открыть (обесточить)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(548);
#else
ParExchange("B7AP31LDU",3,&SignalBuffer[548],"Клапан (Обдув АЗ2) открыть (обесточить)",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(610);
#else
ParExchange("TerR0IN06FRP",2,&SignalBuffer[610],"Неисправности СНМ-11 -1,2",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(647);
#else
ParExchange("R0MW11IP1",2,&SignalBuffer[647],"Переключатель ВЫСТРЕЛ",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(650);
#else
ParExchange("R0DEUMLSS",2,&SignalBuffer[650],"Сигнал управления моделью",0);
#endif
#ifndef SIMUL_MODE
  *((unsigned int*)(PBSTART + 10)) = InvertionFailureCounter;
#endif
#endif
 reInit_Signals();
}

#ifndef SIMUL_MODE
void InvertSignals(void)
{
#ifdef CONTROL
 unsigned int counter;
 for(counter=0; counter<653; counter++) {
   *((unsigned char*)(SignalBuffer)+PBLENGTH-counter-1) =
          (unsigned char)~(*((unsigned char*)(SignalBuffer)+counter));
 }
#endif
}
#endif
#ifdef SIMUL_MODE
void UnloadSignals()
{
ParExchange("A0SR01RIM",1,&SignalBuffer[0],"Текущая реактивность AЗ1",1);
ParExchange("B0SR01RIM",1,&SignalBuffer[97],"Текущая реактивность AЗ2",1);
ParExchange("A0SN08RIM",1,&SignalBuffer[138],"Поток нейтронов AЗ1(нейтр/с)",1);
ParExchange("B0SN08RIM",1,&SignalBuffer[143],"Поток нейтронов AЗ2(нейтр/с)",1);
ParExchange("R0CR01RIM",1,&SignalBuffer[148],"Коэффициент 12 связи АЗ1,2",1);
ParExchange("R0CR02RIM",1,&SignalBuffer[153],"Коэффициент 11 связи АЗ1,2",1);
ParExchange("R0SR02RIM",1,&SignalBuffer[158],"Текущая мощность РУ (ватт)",1);
ParExchange("R0ST01RIM",1,&SignalBuffer[207],"Текущий период разгона РУ",1);
ParExchange("R0SR01RIM",1,&SignalBuffer[212],"Текущая реактивность PУ",1);
ParExchange("R7II73LZ1",3,&SignalBuffer[217],"Сработала АС IIУР",1);
ParExchange("R7II71LZ1",3,&SignalBuffer[219],"Сработала АС IУР (датчик 1)",1);
ParExchange("R7II72LZ1",3,&SignalBuffer[221],"Сработала АС IУР (датчик 2)",1);
ParExchange("R7II72LZ2",3,&SignalBuffer[225],"Сработала АС IУР (датчик 2)",1);
ParExchange("R7II71LZ2",3,&SignalBuffer[227],"Сработала АС IУР (датчик 1)",1);
ParExchange("R7II73LZ2",3,&SignalBuffer[229],"Сработала АС IIУР",1);
ParExchange("A3IS35LDU",3,&SignalBuffer[231],"Клапан (ВПИС1) открыт(обесточен)",1);
ParExchange("B3IS35LDU",3,&SignalBuffer[235],"Клапан «ВПИС2» открыт(обесточен)",1);
ParExchange("A7AS31LDU",3,&SignalBuffer[237],"Клапан (Обдув АЗ1) открыт (обесточен)",1);
ParExchange("B7AS31LDU",3,&SignalBuffer[239],"Клапан (Обдув АЗ2) открыт (обесточен)",1);
ParExchange("R6IS21LDU",3,&SignalBuffer[241],"Кран-балка в нерабочем положении",1);
ParExchange("A0IT01IZ1",2,&SignalBuffer[243],"Температура АЗ1-1",1);
ParExchange("A0IT02IZ2",2,&SignalBuffer[246],"Температура АЗ1-2",1);
ParExchange("B0IT01IZ1",2,&SignalBuffer[249],"Температура АЗ2-1",1);
ParExchange("B0IT02IZ2",2,&SignalBuffer[252],"Температура АЗ2-2",1);
ParExchange("A2IS21LDU",3,&SignalBuffer[255],"Приход на НУ РБ1",1);
ParExchange("A2IS11LDU",3,&SignalBuffer[257],"Приход на ВУ РБ1",1);
ParExchange("A2IS12LDU",3,&SignalBuffer[259],"Магнит РБ1 зацеплен",1);
ParExchange("A2IC01UDU",7,&SignalBuffer[261],"Координата штока РБ1",1);
ParExchange("A2IS33LDU",3,&SignalBuffer[266],"Клапан (Подъём РБ1)  открыт (обесточен)",1);
ParExchange("A3IS21LDU",3,&SignalBuffer[268],"Приход на НУ ИС1",1);
ParExchange("B3IS21LDU",3,&SignalBuffer[270],"Приход на НУ ИС2",1);
ParExchange("A2IP01IZ1",2,&SignalBuffer[272],"Текущее давление СБРОС РБ1",1);
ParExchange("A2IP01IZ2",2,&SignalBuffer[275],"Текущее давление СБРОС РБ1",1);
ParExchange("A2VP82LDU",3,&SignalBuffer[278],"Давление ПОДЪЁМ РБ1 в норме",1);
ParExchange("A3IS31LDU",3,&SignalBuffer[280],"Клапан (СПУСК ИС1)  открыт (обесточен)",1);
ParExchange("A3IC01UDU",7,&SignalBuffer[282],"Координата штока ИС1",1);
ParExchange("A3IS33LDU",3,&SignalBuffer[287],"Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)",1);
ParExchange("B3IP02IDU",2,&SignalBuffer[289],"Текущее давление ВЫСТРЕЛ  ИС2",1);
ParExchange("B3IS31LDU",3,&SignalBuffer[292],"Клапан (СПУСК ИС2)  открыт (обесточен)",1);
ParExchange("B3IC01UDU",7,&SignalBuffer[294],"Координата штока ИС2",1);
ParExchange("B3IS33LDU",3,&SignalBuffer[299],"Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)",1);
ParExchange("A3VP81LDU",3,&SignalBuffer[301],"Давление СПУСК ИС1 в норме",1);
ParExchange("B3VP81LDU",3,&SignalBuffer[303],"Давление СПУСК ИС2 в норме",1);
ParExchange("A3IP02IDU",2,&SignalBuffer[305],"Текущее давление ВЫСТРЕЛ ИС1",1);
ParExchange("A3IS11LDU",3,&SignalBuffer[308],"Приход на ВУ ИС1",1);
ParExchange("B3IS11LDU",3,&SignalBuffer[310],"Приход на ВУ ИС2",1);
ParExchange("A3IS22LDU",3,&SignalBuffer[312],"Приход на НУП ИС1",1);
ParExchange("B3IS22LDU",3,&SignalBuffer[314],"Приход на НУП ИС2",1);
ParExchange("R6IS62LDU",3,&SignalBuffer[316],"Исправность ВИП ССДИ-39 1канал",1);
ParExchange("R6IS63LDU",3,&SignalBuffer[318],"Исправность ВИП ССДИ-39 2канал",1);
ParExchange("R6IS64LDU",3,&SignalBuffer[320],"Исправность ВИП ССДИ-35 1канал",1);
ParExchange("R6IS65LDU",3,&SignalBuffer[322],"Исправность ВИП ССДИ-35 2канал",1);
ParExchange("R6IS66LZZ",3,&SignalBuffer[324],"Исправность ВИП 4,0 (№5) ССДИ-1-1",1);
ParExchange("R6IS67LZZ",3,&SignalBuffer[326],"Исправность ВИП 4,0 (№6) ССДИ-1-2",1);
ParExchange("R6IS68LZZ",3,&SignalBuffer[328],"Исправность ВИП 4,0 (№7) ССДИ-2",1);
ParExchange("A8IC01UDU",7,&SignalBuffer[330],"Координата ДС2",1);
ParExchange("B8IC01UDU",7,&SignalBuffer[335],"Координата АЗ2",1);
ParExchange("A0VP81LZZ",3,&SignalBuffer[340],"Давление АЗ1 в норме",1);
ParExchange("B0VP81LZZ",3,&SignalBuffer[342],"Давление АЗ2 в норме",1);
ParExchange("A5IS11LDU",3,&SignalBuffer[344],"Приход на ВУ НЛ1",1);
ParExchange("A5IS21LDU",3,&SignalBuffer[346],"Приход на НУ НЛ1",1);
ParExchange("B5IS11LDU",3,&SignalBuffer[348],"Приход на ВУ НЛ2",1);
ParExchange("B5IS21LDU",3,&SignalBuffer[350],"Приход на НУ НЛ2",1);
ParExchange("A9IS11LDU",3,&SignalBuffer[352],"Приход на ВУ НИ ДС1",1);
ParExchange("A9IS21LDU",3,&SignalBuffer[354],"Приход на НУ НИ ДС1",1);
ParExchange("B9IS11LDU",3,&SignalBuffer[356],"Приход на ВУ НИ ДС2",1);
ParExchange("B9IS21LDU",3,&SignalBuffer[358],"Приход на НУ НИ ДС2",1);
ParExchange("B2IS21LDU",3,&SignalBuffer[360],"Приход на НУ РБ2",1);
ParExchange("B2IS11LDU",3,&SignalBuffer[362],"Приход на ВУ РБ2",1);
ParExchange("B2IS12LDU",3,&SignalBuffer[364],"Магнит РБ2 зацеплен",1);
ParExchange("B2IC01UDU",7,&SignalBuffer[366],"Координата штока РБ2",1);
ParExchange("B2IP01IZ1",2,&SignalBuffer[371],"Текущее давление СБРОС РБ2",1);
ParExchange("B2IP01IZ2",2,&SignalBuffer[374],"Текущее давление СБРОС РБ2",1);
ParExchange("B2VP82LDU",3,&SignalBuffer[377],"Давление ПОДЪЁМ РБ2 в норме",1);
ParExchange("R3IS11LDU",3,&SignalBuffer[379],"Приход на ВУ гомогенных дверей",1);
ParExchange("R3IS21LDU",3,&SignalBuffer[381],"Приход на НУ гомогенных дверей",1);
ParExchange("R5IS11LDU",3,&SignalBuffer[383],"Приход на ВУ ворот отстойной зоны",1);
ParExchange("R5IS21LDU",3,&SignalBuffer[385],"Приход на НУ ворот отстойной зоны",1);
ParExchange("A4IS11LDU",3,&SignalBuffer[387],"Приход на ВУ НИ1",1);
ParExchange("A4IS21LDU",3,&SignalBuffer[389],"Приход на НУ НИ1",1);
ParExchange("R8IS11LDU",3,&SignalBuffer[391],"Аварийный НИ установлен",1);
ParExchange("B4IS11LDU",3,&SignalBuffer[393],"Приход на ВУ НИ2",1);
ParExchange("B4IS21LDU",3,&SignalBuffer[395],"Приход на НУ НИ2",1);
ParExchange("R1IS11LDU",3,&SignalBuffer[397],"Приход на ВУ МДЗ1",1);
ParExchange("R1IS21LDU",3,&SignalBuffer[399],"Приход на НУ МДЗ1",1);
ParExchange("R2IS11LDU",3,&SignalBuffer[401],"Приход на ВУ МДЗ2",1);
ParExchange("R2IS21LDU",3,&SignalBuffer[403],"Приход на НУ МДЗ2",1);
ParExchange("A4VP82LDU",3,&SignalBuffer[405],"Давление ПОДЪЁМ НИ1 в норме",1);
ParExchange("B4VP82LDU",3,&SignalBuffer[407],"Давление ПОДЪЁМ НИ2 в норме",1);
ParExchange("R4IS11LDU",3,&SignalBuffer[409],"Приход на ВУ1 тележки",1);
ParExchange("R4IS21LDU",3,&SignalBuffer[411],"Приход на НУ1 тележки",1);
ParExchange("R4IS22LDU",3,&SignalBuffer[413],"Приход на НУ2 тележки",1);
ParExchange("R4IS12LDU",3,&SignalBuffer[415],"Приход на  ВУ2 тележки",1);
ParExchange("B8IS22LDU",3,&SignalBuffer[417],"Приход на НУ2 АЗ2",1);
ParExchange("B8IS12LDU",3,&SignalBuffer[419],"Приход на ВУ2 АЗ2",1);
ParExchange("A8IS22LDU",3,&SignalBuffer[421],"Приход на механический НУ ДС2",1);
ParExchange("A8IS12LDU",3,&SignalBuffer[423],"Приход на механический ВУ ДС2",1);
ParExchange("A6IS11LDU",3,&SignalBuffer[425],"Приход на ВУ БЗ1",1);
ParExchange("A6IS21LDU",3,&SignalBuffer[427],"Приход на НУ БЗ1",1);
ParExchange("B6IS11LDU",3,&SignalBuffer[429],"Приход на ВУ БЗ2",1);
ParExchange("B6IS21LDU",3,&SignalBuffer[431],"Приход на НУ БЗ2",1);
ParExchange("A1IS21LDU",3,&SignalBuffer[433],"Приход на НУ ББ1",1);
ParExchange("A1IS11LDU",3,&SignalBuffer[435],"Приход на ВУ ББ1",1);
ParExchange("A1IS12LDU",3,&SignalBuffer[437],"Магнит ББ1 зацеплен",1);
ParExchange("A1IC01UDU",7,&SignalBuffer[439],"Координата штока ББ1",1);
ParExchange("B1IC01UDU",7,&SignalBuffer[444],"Координата штока ББ2",1);
ParExchange("B1IS21LDU",3,&SignalBuffer[449],"Приход на НУ ББ2",1);
ParExchange("B1IS11LDU",3,&SignalBuffer[451],"Приход на ВУ ББ2",1);
ParExchange("B1IS12LDU",3,&SignalBuffer[453],"Магнит ББ2 зацеплен",1);
ParExchange("A1IE03LDU",3,&SignalBuffer[455],"Движение ББ1 вперед (от БУШД)",1);
ParExchange("A1IE04LDU",3,&SignalBuffer[457],"Движение ББ1 назад (от БУШД)",1);
ParExchange("B1IE03LDU",3,&SignalBuffer[459],"Движение ББ2 вперед (от БУШД)",1);
ParExchange("B1IE04LDU",3,&SignalBuffer[461],"Движение ББ2 назад (от БУШД)",1);
ParExchange("A4IS10LDU",3,&SignalBuffer[463],"Клапан (Подъём НИ1) открыт (обесточен)",1);
ParExchange("B4IS10LDU",3,&SignalBuffer[465],"Клапан (Подъём НИ2) открыт (обесточен)",1);
ParExchange("R0IS02LDU",3,&SignalBuffer[483],"Разрешение ввода от имитатора",1);
ParExchange("A1IS11LIM",3,&SignalBuffer[487],"Магнит ББ1 обесточен",1);
ParExchange("A1IS32LIM",3,&SignalBuffer[489],"Клапан cброса ББ1 открыт(обесточен)",1);
ParExchange("B1IS11LIM",3,&SignalBuffer[491],"Магнит ББ2 обесточен",1);
ParExchange("B1IS32LIM",3,&SignalBuffer[493],"Клапан cброса ББ2 открыт(обесточен)",1);
ParExchange("A2IS11LIM",3,&SignalBuffer[495],"Магнит РБ1 обесточен",1);
ParExchange("A2IS32LIM",3,&SignalBuffer[497],"Клапан cброса РБ1 открыт(обесточен)",1);
ParExchange("B2IS11LIM",3,&SignalBuffer[499],"Магнит РБ2 обесточен",1);
ParExchange("B2IS32LIM",3,&SignalBuffer[501],"Клапан cброса РБ2 открыт(обесточен)",1);
ParExchange("A0VN01RIM",1,&SignalBuffer[503],"Период разгона  AЗ1",1);
ParExchange("B2IS33LDU",3,&SignalBuffer[508],"Клапан (Подъём РБ2)  открыт (обесточен)",1);
ParExchange("B1VP81LZZ",3,&SignalBuffer[510],"Давление СБРОС ББ2 в норме",1);
ParExchange("A1VP81LZZ",3,&SignalBuffer[512],"Давление СБРОС ББ1 в норме",1);
ParExchange("B8IS11LDU",3,&SignalBuffer[514],"Приход на ВУ1 АЗ2",1);
ParExchange("B8IS21LDU",3,&SignalBuffer[516],"Приход на НУ1 АЗ2",1);
ParExchange("A6VS22LDU",3,&SignalBuffer[518],"Движение створок БЗ1  к ЗАКРЫТА",1);
ParExchange("A6VS12LDU",3,&SignalBuffer[520],"Движение створок БЗ1  к  ОТКРЫТА",1);
ParExchange("B6VS22LDU",3,&SignalBuffer[522],"Движение створок БЗ2  к ЗАКРЫТА",1);
ParExchange("B6VS12LDU",3,&SignalBuffer[524],"Движение створок БЗ2  к ОТКРЫТА",1);
ParExchange("A5VS22LDU",3,&SignalBuffer[526],"Движение НЛ1 в сторону НУ",1);
ParExchange("A5VS12LDU",3,&SignalBuffer[528],"Движение НЛ1 в сторону ВУ",1);
ParExchange("B5VS22LDU",3,&SignalBuffer[530],"Движение НЛ2 в сторону НУ",1);
ParExchange("B5VS12LDU",3,&SignalBuffer[532],"Движение НЛ2 в сторону ВУ",1);
ParExchange("R1VS22LDU",3,&SignalBuffer[534],"Движение МДЗ1 в сторону НУ",1);
ParExchange("R2VS22LDU",3,&SignalBuffer[536],"Движение МДЗ2 в сторону НУ",1);
ParExchange("R2VS12LDU",3,&SignalBuffer[538],"Движение МДЗ2 в сторону ВУ",1);
ParExchange("R1VS12LDU",3,&SignalBuffer[540],"Движение МДЗ1 в сторону ВУ",1);
ParExchange("R4VS22LDU",3,&SignalBuffer[542],"Движение реактора к «У ЗАЩИТЫ»",1);
ParExchange("R4VS12LDU",3,&SignalBuffer[544],"Движение реактора  к «У ОБРАЗЦОВ»",1);
ParExchange("R0IN01FI1",1,&SignalBuffer[550],"Выход КНК15-1 Гц от ПТИ",1);
ParExchange("R0IN01FI4",1,&SignalBuffer[555],"Выход СНМ-11 Гц от ПТИ",1);
ParExchange("R0IN01FI2",1,&SignalBuffer[560],"Выход КНК15-1 Гц от ПТИ",1);
ParExchange("R0IN01FI3",1,&SignalBuffer[565],"Выход СНМ-11 Гц от ПТИ",1);
ParExchange("R0IN02FI4",1,&SignalBuffer[570],"Выход КНК15-1 Гц от ПТИ",1);
ParExchange("R0IN03FI4",1,&SignalBuffer[575],"Выход КНК53М Гц от ПТИ",1);
ParExchange("R0IN02FI1",1,&SignalBuffer[580],"Выход КНК15-1 Гц от ПТИ",1);
ParExchange("R0IN03FI1",1,&SignalBuffer[585],"Выход КНК53М Гц от ПТИ",1);
ParExchange("R0IN02FI2",1,&SignalBuffer[590],"Выход КНК15-1 Гц от ПТИ",1);
ParExchange("R0IN01RIP",1,&SignalBuffer[595],"Выход СНМ-11 Гц от ПТИ",1);
ParExchange("R0IN02RIP",1,&SignalBuffer[600],"Выход КНК15- Гц от ПТИ",1);
ParExchange("R0IN03RIP",1,&SignalBuffer[605],"Выход КНК53М Гц от ПТИ",1);
ParExchange("R0IN06RIP",1,&SignalBuffer[613],"Выход СНМ-11-1 Гц от ПТИ",1);
ParExchange("R0IN07RIP",1,&SignalBuffer[618],"Выход СНМ-11-2 Гц от ПТИ",1);
ParExchange("R0IN03FI2",1,&SignalBuffer[623],"Выход КНК53М Гц от ПТИ",1);
ParExchange("R0IN02FI3",1,&SignalBuffer[628],"Выход КНК15-1 Гц от ПТИ",1);
ParExchange("R0IN03FI3",1,&SignalBuffer[633],"Выход КНК53М Гц от ПТИ",1);
ParExchange("B0IT03IRP",2,&SignalBuffer[638],"Температура АЗ2-3",1);
ParExchange("A0IT03IRP",2,&SignalBuffer[641],"Температура АЗ1-3",1);
ParExchange("R0IS01FI0",2,&SignalBuffer[644],"Признак работы с имитатором",1);
}
#endif
unsigned int StartIntEEPROMAddress = 0;
unsigned int StartExtEEPROMAddress = 0;
unsigned char* EEPROMInSignal = (unsigned char*)(-1);
unsigned char* EEPROMOutSignal = (unsigned char*)(-1);

#ifndef SIMUL_MODE
void SplitEEPROMs(void){
#else
void __stdcall SplitEEPROMs(DVE_Parametrs *Par){
 EEPROMParams = Par;
#endif
#ifdef SIMUL_MODE
NewEEPROM("fEM_R0UL01RIM",1,&fEM_R0UL01RIM,"Среднее время генерации нейтронов","0.015");
NewEEPROM("fEM_R0UN02RIM",1,&fEM_R0UN02RIM,"Доля запаздывающих нейтронов в общем количестве нейтронов","0.0069");
NewEEPROM("fEM_A1UR01RIM",1,&fEM_A1UR01RIM,"Коэффициент-1 функции реактивности вносимой ББ (долл)","0.21");
NewEEPROM("fEM_A1UR00RIM",1,&fEM_A1UR00RIM,"Коэффициент-0 функции реактивности вносимой ББ (долл)","0");
NewEEPROM("fEM_A3UR00RIM",1,&fEM_A3UR00RIM,"Коэффициент-0 функции реактивности вносимой ИС (долл)","0");
NewEEPROM("fEM_A3UR01RIM",1,&fEM_A3UR01RIM,"Коэффициент-1 функции реактивности вносимой ИС (долл)","0.0096");
NewEEPROM("fEM_R0UT01RIM",1,&fEM_R0UT01RIM,"Температурный коэффициент (долл)","0.0026");
NewEEPROM("fEM_R0UT02RIM",1,&fEM_R0UT02RIM,"Масса топлива в АЗ","106");
NewEEPROM("fEM_R0UT04RIM",1,&fEM_R0UT04RIM,"Удельная теплоёмкость топлива","135.227");
NewEEPROM("fEM_R0UT03RIM",1,&fEM_R0UT03RIM,"Нормальная температура АЗ град","25");
NewEEPROM("fEM_R0UT05RIM",1,&fEM_R0UT05RIM,"Энергия деления ядра","320.435466");
NewEEPROM("fEM_R0UT06RIM",1,&fEM_R0UT06RIM,"Конвекционное сопротивление при обдуве","0.0055");
NewEEPROM("fEM_A1UC02RDU",1,&fEM_A1UC02RDU,"Коэффициент преобразования частоты двигателя ББ в скорость мм/с","0.000877");
NewEEPROM("fEM_A1UC04RIM",1,&fEM_A1UC04RIM,"Координата промежуточного путевого выключателя ББ мм","200");
NewEEPROM("fEM_A1UC05RIM",1,&fEM_A1UC05RIM,"Координата переднего аварийного выключателя ББ мм","100");
NewEEPROM("fEM_A1UC06RIM",1,&fEM_A1UC06RIM,"Координата заднего аварийного выключателя ББ мм","0");
NewEEPROM("fEM_A2UC06RIM",1,&fEM_A2UC06RIM,"Координата заднего аварийного выключателя РБ мм","0");
NewEEPROM("fEM_A2UC05RIM",1,&fEM_A2UC05RIM,"Координата переднего аварийного выключателя РБ мм","100");
NewEEPROM("fEM_A2UC04RIM",1,&fEM_A2UC04RIM,"Координата промежуточного путевого выключателя РБ мм","80");
NewEEPROM("fEM_A2UC02RDU",1,&fEM_A2UC02RDU,"Коэффициент преобразования частоты двигателя РБ в скорость мм/с","0.002375");
NewEEPROM("fEM_A3UC06RIM",1,&fEM_A3UC06RIM,"Координата заднего аварийного выключателя ИС мм","0");
NewEEPROM("fEM_A3UC05RIM",1,&fEM_A3UC05RIM,"Координата переднего аварийного выключателя ИС мм","165");
NewEEPROM("fEM_A3UC04RIM",1,&fEM_A3UC04RIM,"Координата промежуточного путевого выключателя ИС мм","200");
NewEEPROM("fEM_A3UC02RDU",1,&fEM_A3UC02RDU,"Коэффициент преобразования частоты двигателя ИС в скорость мм/с","0.001675");
NewEEPROM("fEM_R4UV80RDU",1,&fEM_R4UV80RDU,"Номинальная скорость тележки (мм/с)","40");
NewEEPROM("fEM_R4UC10RIM",1,&fEM_R4UC10RIM,"Координата верхних механических упоров тележки мм","15630.0");
NewEEPROM("fEM_R4UC20RIM",1,&fEM_R4UC20RIM,"Координата нижних механических упоров тележки мм","1374");
NewEEPROM("fEM_B8UC21RIM",1,&fEM_B8UC21RIM,"Координата верхнего путевого выключателя АЗ2 мм","0");
NewEEPROM("fEM_B8UC20RIM",1,&fEM_B8UC20RIM,"Координата верхних механических упоров АЗ2 мм","390.0");
NewEEPROM("fEM_B8UC11RIM",1,&fEM_B8UC11RIM,"Координата нижнего путевого выключателя АЗ2 мм","2000.0");
NewEEPROM("fEM_B8UC10RIM",1,&fEM_B8UC10RIM,"Координата нижних механических упоров АЗ2 мм","1500.0");
NewEEPROM("fEM_B8UV80RDU",1,&fEM_B8UV80RDU,"Номинальная скорость АЗ2 (мм/с)","10.91");
NewEEPROM("fEM_A8UV80RDU",1,&fEM_A8UV80RDU,"Номинальная скорость ДС2 (мм/с)","10.91");
NewEEPROM("fEM_A8UC10RIM",1,&fEM_A8UC10RIM,"Координата нижних механических упоров ДС2 мм","1500.0");
NewEEPROM("fEM_A8UC11RIM",1,&fEM_A8UC11RIM,"Координата нижнего путевого выключателя ДС2 мм","2000");
NewEEPROM("fEM_A8UC20RIM",1,&fEM_A8UC20RIM,"Координата верхних механических упоров ДС2 мм","390.0");
NewEEPROM("fEM_A8UC21RIM",1,&fEM_A8UC21RIM,"Координата верхнего путевого выключателя ДС2 мм","0");
NewEEPROM("fEM_A6UC10RIM",1,&fEM_A6UC10RIM,"Время полного хода БЗ (сек)","55.0");
NewEEPROM("fEM_R1UC10RIM",1,&fEM_R1UC10RIM,"Время полного хода МДЗ сек","15.0");
NewEEPROM("fEM_A5UC10RIM",1,&fEM_A5UC10RIM,"Время полного хода НЛ сек","5.0");
NewEEPROM("fEM_A0UN01RIM",1,&fEM_A0UN01RIM,"Мощность источника нейтронов ИНИ","1E12");
NewEEPROM("fEM_R4UC22RIM",1,&fEM_R4UC22RIM,"Смещение координаты АЗ от координаты тележки","43.6");
NewEEPROM("fEM_A1UG01RDU",1,&fEM_A1UG01RDU,"Расстояние включения масляного демпфера ББ(мм)","20.0");
NewEEPROM("fEM_A2UG01RDU",1,&fEM_A2UG01RDU,"Расстояние включения масляного демпфера РБ","20.0");
NewEEPROM("fEM_A3UG01RDU",1,&fEM_A3UG01RDU,"Расстояние включения масляного демпфера ИС","20.0");
NewEEPROM("fEM_R7UC10RIM",1,&fEM_R7UC10RIM,"X-координата КНК53М R7IN13 см","1269.0");
NewEEPROM("fEM_R7UC19RIM",1,&fEM_R7UC19RIM,"Y-координата СНМ-11 (11) см","256.0");
NewEEPROM("fEM_R7UI02RIM",1,&fEM_R7UI02RIM,"Коэффициент усиления уровня радиации","1.0");
NewEEPROM("fEM_R7UL01RIM",1,&fEM_R7UL01RIM,"Постоянная времени изменения уровня радиации в зале","2.0");
NewEEPROM("fEM_A2UR00RIM",1,&fEM_A2UR00RIM,"Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)","0");
NewEEPROM("fEM_A2UR01RIM",1,&fEM_A2UR01RIM,"Коэффициент-1 функции реактивности вносимой РБ (долл)","0.026");
NewEEPROM("fEM_A0UN02RIM",1,&fEM_A0UN02RIM,"Мощность источника нейтронов с АНИ","0.08");
NewEEPROM("fEM_R0UR30RIM",1,&fEM_R0UR30RIM,"Реактивность вносимая образцами (долл)","0.0");
NewEEPROM("fEM_R0UR01RIM",1,&fEM_R0UR01RIM,"Стартовая отрицательная реактивность","27.108");
NewEEPROM("fEM_R0UT02RDU",1,&fEM_R0UT02RDU,"Верхний предел шкалы датчика температуры","600");
NewEEPROM("fEM_R0UT01RDU",1,&fEM_R0UT01RDU,"Нижний предел шкалы датчика температуры","0");
NewEEPROM("fEM_A1UC03RDU",1,&fEM_A1UC03RDU,"Коэффициент преобразования показания энкодера ББ мм/дел.энкодера","0.00009765625");
NewEEPROM("fEM_A2UP03RDU",1,&fEM_A2UP03RDU,"Верхний предел шкалы датчика давления на подъем/сброс РБ","1.6");
NewEEPROM("fEM_A2UP04RDU",1,&fEM_A2UP04RDU,"Нижний предел шкалы датчика давления на подъем/сброс РБ","0");
NewEEPROM("fEM_A2UC03RDU",1,&fEM_A2UC03RDU,"Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм","0.00009765625");
NewEEPROM("fEM_A3UP03RDU",1,&fEM_A3UP03RDU,"Верхний предел шкалы датчика давления на подъем/сброс ИС","1.6");
NewEEPROM("fEM_A3UP04RDU",1,&fEM_A3UP04RDU,"Нижний предел шкалы датчика давления на подъем/сброс ИС","0");
NewEEPROM("fEM_A3UC03RDU",1,&fEM_A3UC03RDU,"Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм","0.00009765625");
NewEEPROM("fEM_R7UI74RIM",1,&fEM_R7UI74RIM,"Верхняя граница измерения уровня радиации в зале","10000.0");
NewEEPROM("fEM_A8UC03RDU",1,&fEM_A8UC03RDU,"Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера","0.0009765625");
NewEEPROM("fEM_R0UV87RDU",1,&fEM_R0UV87RDU,"7-я скорость перемещения ББ (шагов/секунду)","750");
NewEEPROM("fEM_R0UV81RDU",1,&fEM_R0UV81RDU,"1-я частота двигателя (шагов/секунду)","100");
NewEEPROM("fEM_R0UV82RDU",1,&fEM_R0UV82RDU,"3-я частота двигателя (шагов/секунду)","200");
NewEEPROM("fEM_R0UV83RDU",1,&fEM_R0UV83RDU,"4-я частота двигателя (шагов/секунду)","300");
NewEEPROM("fEM_R0UV84RDU",1,&fEM_R0UV84RDU,"5-я частота двигателя (шагов/секунду)","400");
NewEEPROM("fEM_R0UV85RDU",1,&fEM_R0UV85RDU,"6-я скорость перемещения ББ (шагов/секунду)","500");
NewEEPROM("fEM_R0UV86RDU",1,&fEM_R0UV86RDU,"7-я скорость перемещения ББ (шагов/секунду)","600");
NewEEPROM("fEM_A8UC08RDU",1,&fEM_A8UC08RDU,"Зона срабатывания КВ ДС2(мм)","0.50");
NewEEPROM("fEM_B8UC08RDU",1,&fEM_B8UC08RDU,"Зона срабатывания КВ АЗ2(мм)","0.50");
NewEEPROM("fEM_R4UC08RDU",1,&fEM_R4UC08RDU,"Зона срабатывания КВ тележки РУ(мм)","0.50");
NewEEPROM("fEM_R0UH01RSS",1,&fEM_R0UH01RSS,"Коэфф. преобразования частота->нейтр/с  СНМ11","2");
NewEEPROM("fEM_A0UX00RSS",1,&fEM_A0UX00RSS,"Эффективный радиус АЗ","11.0");
NewEEPROM("fEM_R7UX01RSS",1,&fEM_R7UX01RSS,"X-координата камеры R7IN11","1585.0");
NewEEPROM("fEM_R7UX02RSS",1,&fEM_R7UX02RSS,"X-координата камеры R7IN12 (см)","1796.0");
NewEEPROM("fEM_R7UX04RSS",1,&fEM_R7UX04RSS,"X-координата камеры R7IN21 (см)","1555.0");
NewEEPROM("fEM_R7UX05RSS",1,&fEM_R7UX05RSS,"X-координата камеры R7IN22 (см)","1269.0");
NewEEPROM("fEM_R7UX06RSS",1,&fEM_R7UX06RSS,"X-координата камеры R7IN23 (см)","1269.0");
NewEEPROM("fEM_R7UX07RSS",1,&fEM_R7UX07RSS,"X-координата камеры R7IN31 (см)","1585.0");
NewEEPROM("fEM_R7UX08RSS",1,&fEM_R7UX08RSS,"X-координата камеры R7IN32 (см)","1796.0");
NewEEPROM("fEM_R7UX09RSS",1,&fEM_R7UX09RSS,"X-координата камеры R7IN33 (см)","1269.0");
NewEEPROM("fEM_R7UY01RSS",1,&fEM_R7UY01RSS,"Y-координата камеры R7IN11","248.0");
NewEEPROM("fEM_R7UY02RSS",1,&fEM_R7UY02RSS,"Y-координата камеры R7IN12 (см)","284.5");
NewEEPROM("fEM_R7UY04RSS",1,&fEM_R7UY04RSS,"Y-координата камеры R7IN21 (см)","248.0");
NewEEPROM("fEM_R7UY05RSS",1,&fEM_R7UY05RSS,"Y-координата камеры R7IN22 (см)","271.6");
NewEEPROM("fEM_R7UY06RSS",1,&fEM_R7UY06RSS,"Y-координата камеры R7IN23 (см)","287.2");
NewEEPROM("fEM_R7UY07RSS",1,&fEM_R7UY07RSS,"Y-координата камеры R7IN31 (см)","594.0");
NewEEPROM("fEM_R7UY08RSS",1,&fEM_R7UY08RSS,"Y-координата камеры R7IN32 (см)","559.0");
NewEEPROM("fEM_R7UY09RSS",1,&fEM_R7UY09RSS,"Y-координата камеры R7IN33 (см)","588.0");
NewEEPROM("fEM_R7UX10RSS",1,&fEM_R7UX10RSS,"X-координата камеры R7IN41","1555.0");
NewEEPROM("fEM_R7UX11RSS",1,&fEM_R7UX11RSS,"X-координата камеры R7IN42","1281.2");
NewEEPROM("fEM_R7UX12RSS",1,&fEM_R7UX12RSS,"X-координата камеры R7IN43","1269.0");
NewEEPROM("fEM_R7UY10RSS",1,&fEM_R7UY10RSS,"Y-координата камеры R7IN41","594.0");
NewEEPROM("fEM_R7UY11RSS",1,&fEM_R7UY11RSS,"Y-координата камеры R7IN42","597.2");
NewEEPROM("fEM_R7UY12RSS",1,&fEM_R7UY12RSS,"Y-координата камеры R7IN43","556.8");
NewEEPROM("fEM_A0UX01RSS",1,&fEM_A0UX01RSS,"Первый коэффициент калибровки камеры 1","1.0");
NewEEPROM("fEM_A0UX02RSS",1,&fEM_A0UX02RSS,"Первый коэффициент калибровки камеры 2","1.0");
NewEEPROM("fEM_A0UX03RSS",1,&fEM_A0UX03RSS,"Первый коэффициент калибровки камеры 3","1.0");
NewEEPROM("fEM_A0UX04RSS",1,&fEM_A0UX04RSS,"Первый коэффициент калибровки камеры4","1.0");
NewEEPROM("fEM_A0UX05RSS",1,&fEM_A0UX05RSS,"Первый коэффициент калибровки камеры 5","1.0");
NewEEPROM("fEM_A0UX06RSS",1,&fEM_A0UX06RSS,"Первый коэффициент калибровки камеры 6","1.0");
NewEEPROM("fEM_A0UX07RSS",1,&fEM_A0UX07RSS,"Первый коэффициент калибровки камеры 7","1.0");
NewEEPROM("fEM_A0UX08RSS",1,&fEM_A0UX08RSS,"Первый коэффициент калибровки камеры 8","1.0");
NewEEPROM("fEM_A0UX09RSS",1,&fEM_A0UX09RSS,"Первый коэффициент калибровки камеры 9","1.0");
NewEEPROM("fEM_A0UX10RSS",1,&fEM_A0UX10RSS,"Первый коэффициент калибровки камеры 10","1.0");
NewEEPROM("fEM_A0UX11RSS",1,&fEM_A0UX11RSS,"Первый коэффициент калибровки камеры 11","1.0");
NewEEPROM("fEM_A0UX12RSS",1,&fEM_A0UX12RSS,"Первый коэффициент калибровки камеры 12","1.0");
NewEEPROM("fEM_B0UX01RSS",1,&fEM_B0UX01RSS,"Второй коэффициент калибровки камеры 1","0");
NewEEPROM("fEM_B0UX02RSS",1,&fEM_B0UX02RSS,"Второй коэффициент калибровки камеры 2","0");
NewEEPROM("fEM_B0UX03RSS",1,&fEM_B0UX03RSS,"Второй коэффициент калибровки камеры 3","0");
NewEEPROM("fEM_B0UX04RSS",1,&fEM_B0UX04RSS,"Второй коэффициент калибровки камеры 4","0");
NewEEPROM("fEM_B0UX05RSS",1,&fEM_B0UX05RSS,"Второй коэффициент калибровки камеры 5","0.0");
NewEEPROM("fEM_B0UX06RSS",1,&fEM_B0UX06RSS,"Второй коэффициент калибровки камеры 6","0");
NewEEPROM("fEM_B0UX07RSS",1,&fEM_B0UX07RSS,"Второй коэффициент калибровки камеры 7","0.0");
NewEEPROM("fEM_B0UX08RSS",1,&fEM_B0UX08RSS,"Второй коэффициент калибровки камеры 8","0");
NewEEPROM("fEM_B0UX09RSS",1,&fEM_B0UX09RSS,"Второй коэффициент калибровки камеры 9","0.0");
NewEEPROM("fEM_B0UX10RSS",1,&fEM_B0UX10RSS,"Второй коэффициент калибровки камеры 10","0.0");
NewEEPROM("fEM_B0UX11RSS",1,&fEM_B0UX11RSS,"Второй коэффициент калибровки камеры 11","0.0");
NewEEPROM("fEM_B0UX12RSS",1,&fEM_B0UX12RSS,"Второй коэффициент калибровки камеры 12","0.0");
NewEEPROM("fEM_R0UH02RSS",1,&fEM_R0UH02RSS,"Коэфф. преобразования частота->нейтр/с  КНК15-1","3703.704");
NewEEPROM("fEM_R0UH03RSS",1,&fEM_R0UH03RSS,"Коэфф. преобразования частота->нейтр/с  КНК53М","62500.0");
NewEEPROM("fEM_R4US80RDU",1,&fEM_R4US80RDU,"Тормозной путь тележки (мм)","20");
NewEEPROM("fEM_R7UI71RIM",1,&fEM_R7UI71RIM,"Уровень мощности срабатывания АС IУР  ватт (датчик 1)","18000");
NewEEPROM("fEM_R7UI72RIM",1,&fEM_R7UI72RIM,"Уровень мощности срабатывания АС IУР  ватт (датчик 2)","18000");
NewEEPROM("fEM_R7UI73RIM",1,&fEM_R7UI73RIM,"Уровень мощности срабатывания АС II УР  ватт","18000");
NewEEPROM("fEM_A1UP01RIM",1,&fEM_A1UP01RIM,"Текущее давление на сброс ББ (МПа)","0.76");
NewEEPROM("fEM_A2UP01RIM",1,&fEM_A2UP01RIM,"Текущее давление на сброс РБ","0.245");
NewEEPROM("fEM_A0UP02RIM",1,&fEM_A0UP02RIM,"Текущее давление в АЗ1,2","2.9");
NewEEPROM("fEM_A3UP01RIM",1,&fEM_A3UP01RIM,"Текущее давление на СПУСК ИС","0.13");
NewEEPROM("fEM_A1UP82RIM",1,&fEM_A1UP82RIM,"Нижняя граница нормализации давления СБРОС ББ (МПа)","0.73");
NewEEPROM("fEM_A3UP02RDU",1,&fEM_A3UP02RDU,"Текущее давление ВЫСТРЕЛ ИС","0.41");
NewEEPROM("fEM_A1UV02RIM",1,&fEM_A1UV02RIM,"Ускорение сброса ББ от пневматики - g (мм/с^2)","9807.0");
NewEEPROM("fEM_A3UV02RIM",1,&fEM_A3UV02RIM,"Ускорение сброса ИС от пневматики - g (мм/с^2)","22975.0");
NewEEPROM("fEM_A2UV02RIM",1,&fEM_A2UV02RIM,"Ускорение сброса РБ от пневматики - g (мм/с^2)","12750.0");
NewEEPROM("fEM_B8US80RDU",1,&fEM_B8US80RDU,"Тормозной путь АЗ2 (мм)","20");
NewEEPROM("fEM_A8US80RDU",1,&fEM_A8US80RDU,"Тормозной путь ДС2 (мм)","20");
NewEEPROM("fEM_A6US80RDU",1,&fEM_A6US80RDU,"Тормозной путь БЗ (мм)","0");
NewEEPROM("fEM_A1US07RDU",1,&fEM_A1US07RDU,"Постоянная времени масляного демпфера ББ","5.0");
NewEEPROM("fEM_A2US07RDU",1,&fEM_A2US07RDU,"Постоянная времени масляного демпфера РБ","5.0");
NewEEPROM("fEM_A3US07RDU",1,&fEM_A3US07RDU,"Постоянная времени масляного демпфера ИС","5.0");
NewEEPROM("fEM_R7UI75RIM",1,&fEM_R7UI75RIM,"Множитель к уровню радиации","100.0");
NewEEPROM("fEM_R0UH21RSS",1,&fEM_R0UH21RSS,"Верхняя граница измерения частоты импульсов(имп/с) СНМ-11","4000");
NewEEPROM("fEM_R0UH22RSS",1,&fEM_R0UH22RSS,"Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1","100000");
NewEEPROM("fEM_R0UH23RSS",1,&fEM_R0UH23RSS,"Верхняя граница измерения частоты импульсов(имп/с) КНК-53М","1000000");
NewEEPROM("fEM_R0UH05RSS",1,&fEM_R0UH05RSS,"Кол-во делений/сек на 1 ватт * E^6","32000.0");
NewEEPROM("fEM_A4UL10RIM",1,&fEM_A4UL10RIM,"Время полного перемещения НИ сек","5.0");
NewEEPROM("fEM_A9UL10RIM",1,&fEM_A9UL10RIM,"Время полного перемещения НИ ДС1/ДС2 сек","15.0");
NewEEPROM("fEM_R3UL10RIM",1,&fEM_R3UL10RIM,"Время полного хода гомогенных дверей (сек)","15.0");
NewEEPROM("fEM_R5UL10RIM",1,&fEM_R5UL10RIM,"Время полного хода ворот отстойной зоны (дес. мс)","20.0");
NewEEPROM("fEM_R6UL10RIM",1,&fEM_R6UL10RIM,"Время полного хода кран-балки сек","10.0");
NewEEPROM("lEM_C1AD31LRP",3,&lEM_C1AD31LRP,"Общий сброс от РПУ","0");
NewEEPROM("lEM_R0IE01LRP",3,&lEM_R0IE01LRP,"Отключение питание детекторов","0");
NewEEPROM("lEM_R0IE02LRP",3,&lEM_R0IE02LRP,"Отключить питание ПР, ПУ","0");
NewEEPROM("fEM_A2UP02RIM",1,&fEM_A2UP02RIM,"Текущее давление на подъём РБ","0.45");
NewEEPROM("fEM_A2UP03RIM",1,&fEM_A2UP03RIM,"Нижняя граница давления на ПОДЪЁМ РБ","0.39");
NewEEPROM("fEM_A0UP01RIM",1,&fEM_A0UP01RIM,"Текущее давление в АЗ1,2","2.74");
NewEEPROM("fEM_A3UP02RIM",1,&fEM_A3UP02RIM,"Нижняя граница  давления на СПУСК ИС","0.07");
NewEEPROM("fEM_A4UP01RIM",1,&fEM_A4UP01RIM,"Текущее давление на подъём НИ","0.275");
NewEEPROM("fEM_A4UP02RIM",1,&fEM_A4UP02RIM,"Нижняя граница давления на подъём НИ","0.245");
NewEEPROM("fEM_R7UI76RIM",1,&fEM_R7UI76RIM,"Время задержки  срабатывания АС II УР при имитации сигнала сек","0.045");
NewEEPROM("fEM_R7UI77RIM",1,&fEM_R7UI77RIM,"Время задержки  срабатывания АС 1 УР при имитации сигнала сек","0.05");
NewEEPROM("iEM_TERBB1",2,&iEM_TERBB1,"Неисправности  ББ1","0");
NewEEPROM("fEM_A1MC02RC1",1,&fEM_A1MC02RC1,"Заданная координата штока ББ1 от ИС","0");
NewEEPROM("fEM_A1MV02RC1",1,&fEM_A1MV02RC1,"Заданная скорость движения  штока ББ1 от ИС","0");
NewEEPROM("iEM_TERBB2",2,&iEM_TERBB2,"Неисправности  ББ2","0");
NewEEPROM("fEM_B1MC02RC1",1,&fEM_B1MC02RC1,"Заданная координата штока ББ2 от ИС","0");
NewEEPROM("fEM_B1MV02RC1",1,&fEM_B1MV02RC1,"Заданная скорость движения штока ББ2 от ИС","0");
NewEEPROM("iEM_TERRB2",2,&iEM_TERRB2,"Неисправности  РБ2","0");
NewEEPROM("fEM_B2MC02RC1",1,&fEM_B2MC02RC1,"Заданная координата штока РБ2 от ИС","0");
NewEEPROM("fEM_B2MV02RC1",1,&fEM_B2MV02RC1,"Заданная скорость движения штока РБ2 от ИС","0");
NewEEPROM("iEM_TERRB1",2,&iEM_TERRB1,"Неисправности  РБ1","0");
NewEEPROM("fEM_A2MC02RC1",1,&fEM_A2MC02RC1,"Заданная координата штока РБ1 от ИС","0");
NewEEPROM("fEM_A2MV02RC1",1,&fEM_A2MV02RC1,"Заданная скорость движения штока РБ1 от ИС","0");
NewEEPROM("iEM_TERIS2",2,&iEM_TERIS2,"Неисправности  ИС2","0");
NewEEPROM("fEM_B3MC02RC1",1,&fEM_B3MC02RC1,"Заданная координата штока ИС2 от ИС","0");
NewEEPROM("fEM_B3MV02RC1",1,&fEM_B3MV02RC1,"Заданная скорость движения штока ИС2 от ИС","0");
NewEEPROM("iEM_TERIS1",2,&iEM_TERIS1,"Неисправности  ИС1","0");
NewEEPROM("fEM_A3MC02RC1",1,&fEM_A3MC02RC1,"Заданная координата штока ИС1 от ИС","0");
NewEEPROM("fEM_A3MV02RC1",1,&fEM_A3MV02RC1,"Заданная скорость движения штока ИС1 от ИС","0");
NewEEPROM("iEM_TERA1IE04LDU",2,&iEM_TERA1IE04LDU,"Искажение Движение ББ1 назад (от БУШД)","0");
NewEEPROM("iEM_TERA1IE03LDU",2,&iEM_TERA1IE03LDU,"Искажение Движение ББ1 вперёд (от БУШД)","0");
NewEEPROM("fEM_A1MC01RC1",1,&fEM_A1MC01RC1,"Заданная координата  ББ1 от ИС","0");
NewEEPROM("iEM_TERB1IE03LDU",2,&iEM_TERB1IE03LDU,"Искажение Движение ББ2 вперёд (от БУШД)","0");
NewEEPROM("iEM_TERB1IE04LDU",2,&iEM_TERB1IE04LDU,"Искажение Движение ББ2 назад (от БУШД)","0");
NewEEPROM("fEM_B1MC01RC1",1,&fEM_B1MC01RC1,"Заданная координата ББ2 от ИС","0");
NewEEPROM("fEM_B1MV01RC1",1,&fEM_B1MV01RC1,"Заданная скорость движения ББ2 от ИС","0");
NewEEPROM("fEM_B2MC01RC1",1,&fEM_B2MC01RC1,"Заданная координата РБ2 от ИС","0");
NewEEPROM("fEM_B2MV01RC1",1,&fEM_B2MV01RC1,"Заданная скорость движения  РБ2 от ИС","0");
NewEEPROM("fEM_A3MC01RC1",1,&fEM_A3MC01RC1,"Заданная координата ИС1 от ИС","0");
NewEEPROM("fEM_A3MV01RC1",1,&fEM_A3MV01RC1,"Заданная скорость движения ИС1 от ИС","0");
NewEEPROM("fEM_B3MC01RC1",1,&fEM_B3MC01RC1,"Заданная координата ИС2 от ИС","0");
NewEEPROM("fEM_B3MV01RC1",1,&fEM_B3MV01RC1,"Заданная скорость движения ИС2 от ИС","0");
NewEEPROM("iEM_TERA2SS21LIM",2,&iEM_TERA2SS21LIM,"Искажение: Приход на НУ РБ1","0");
NewEEPROM("iEM_TERA2SS12LIM",2,&iEM_TERA2SS12LIM,"Искажение: Магнит РБ1 зацеплен","0");
NewEEPROM("iEM_TERR6SS21LIM",2,&iEM_TERR6SS21LIM,"Искажение: Кран-балка в нерабочем положении","0");
NewEEPROM("iEM_TERA2VP82LIM",2,&iEM_TERA2VP82LIM,"Искажение: Текущее давление на подъём РБ  в норме","0");
NewEEPROM("iEM_TERA2SS11LIM",2,&iEM_TERA2SS11LIM,"Искажение: Приход на ВУ РБ1","0");
NewEEPROM("iEM_TERB3SS21LIM",2,&iEM_TERB3SS21LIM,"Искажение: Приход на НУ ИС2","0");
NewEEPROM("iEM_TERA0MT01RIM",2,&iEM_TERA0MT01RIM,"Искажение: Текущая температура AЗ1","0");
NewEEPROM("iEM_TERB0MT01RIM",2,&iEM_TERB0MT01RIM,"Искажение: Текущая температура AЗ2","0");
NewEEPROM("iEM_TERA2SP01RIM",2,&iEM_TERA2SP01RIM,"Искажение: Текущее давление СБРОС РБ1","0");
NewEEPROM("iEM_TERB2SP01RIM",2,&iEM_TERB2SP01RIM,"Искажение: Текущее давление СБРОС РБ2","0");
NewEEPROM("iEM_TERB3SP02RIM",2,&iEM_TERB3SP02RIM,"Искажение: Текущее давление на ВЫСТРЕЛ ИС2","0");
NewEEPROM("iEM_TERA3SC01RIM",2,&iEM_TERA3SC01RIM,"Искажение: Координата штока ИС1","0");
NewEEPROM("iEM_TERA3VP81LIM",2,&iEM_TERA3VP81LIM,"Искажение: Текущее давление СПУСК ИС  в норме","0");
NewEEPROM("iEM_TERA2SC01RIM",2,&iEM_TERA2SC01RIM,"Искажение: Координата штока РБ1","0");
NewEEPROM("iEM_TERA2SS33LIM",2,&iEM_TERA2SS33LIM,"Искажение: Клапан «Подъём РБ1»  открыт (обесточен)","0");
NewEEPROM("iEM_TERA3SS21LIM",2,&iEM_TERA3SS21LIM,"Искажение: Приход на НУ ИС1","0");
NewEEPROM("iEM_TERA3SS33LIM",2,&iEM_TERA3SS33LIM,"Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)","0");
NewEEPROM("iEM_TERA3SS31LIM",2,&iEM_TERA3SS31LIM,"Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)","0");
NewEEPROM("iEM_TERB3SS31LIM",2,&iEM_TERB3SS31LIM,"Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)","0");
NewEEPROM("iEM_TERB3SS33LIM",2,&iEM_TERB3SS33LIM,"Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)","0");
NewEEPROM("iEM_TERB3SC01RIM",2,&iEM_TERB3SC01RIM,"Искажение: Координата штока ИС2","0");
NewEEPROM("iEM_TERA3SS11LIM",2,&iEM_TERA3SS11LIM,"Искажение: Приход на ВУ ИС1","0");
NewEEPROM("iEM_TERB3SS11LIM",2,&iEM_TERB3SS11LIM,"Искажение: Приход на ВУ ИС2","0");
NewEEPROM("iEM_TERR6IS64LIM",2,&iEM_TERR6IS64LIM,"Искажение: Исправность ВИП ССДИ-35","0");
NewEEPROM("iEM_TERB3SS22LIM",2,&iEM_TERB3SS22LIM,"Искажение: Приход на НУП ИС2","0");
NewEEPROM("iEM_TERA3SS22LIM",2,&iEM_TERA3SS22LIM,"Искажение: Приход на НУП ИС1","0");
NewEEPROM("iEM_TERA3SP02RIM",2,&iEM_TERA3SP02RIM,"Искажение: Текущее давление на ВЫСТРЕЛ ИС1","0");
NewEEPROM("iEM_TERR6IS62LIM",2,&iEM_TERR6IS62LIM,"Искажение Исправность ВИП ССДИ-39","0");
NewEEPROM("iEM_TERR6IS66LIM",2,&iEM_TERR6IS66LIM,"Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1","0");
NewEEPROM("iEM_TERR6IS67LIM",2,&iEM_TERR6IS67LIM,"Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2","0");
NewEEPROM("iEM_TERA0VP81LIM",2,&iEM_TERA0VP81LIM,"Искажение: Давление  АЗ1  в норме","0");
NewEEPROM("iEM_TERB0VP81LIM",2,&iEM_TERB0VP81LIM,"Искажение: Давление  АЗ2 в норме","0");
NewEEPROM("iEM_TERR0VP81LIM",2,&iEM_TERR0VP81LIM,"Искажение: Давление  в СИСТЕМЕ-1 в норме","0");
NewEEPROM("iEM_TERR6IS68LIM",2,&iEM_TERR6IS68LIM,"Искажение Исправность ВИП 4,0 (№7) ССДИ-2","0");
NewEEPROM("iEM_TERR7SI74RIM",2,&iEM_TERR7SI74RIM,"Искажение: Радиация в реакторном зале","0");
NewEEPROM("iEM_TERA5SS21LIM",2,&iEM_TERA5SS21LIM,"Искажение: Приход на НУ НЛ1","0");
NewEEPROM("iEM_TERB5SS11LIM",2,&iEM_TERB5SS11LIM,"Искажение: Приход на ВУ НЛ2","0");
NewEEPROM("iEM_TERA5SS11LIM",2,&iEM_TERA5SS11LIM,"Искажение: Движенеие створок БЗ1 к ОТКРЫТА","0");
NewEEPROM("iEM_TERA9SS11LIM",2,&iEM_TERA9SS11LIM,"Искажение: Приход на ВУ НИ ДС1","0");
NewEEPROM("iEM_TERB2SS11LIM",2,&iEM_TERB2SS11LIM,"Искажение: Приход на ВУ РБ2","0");
NewEEPROM("iEM_TERB2SS12LIM",2,&iEM_TERB2SS12LIM,"Искажение: Магнит РБ2 зацеплен","0");
NewEEPROM("iEM_TERB2SS21LIM",2,&iEM_TERB2SS21LIM,"Искажение: Приход на НУ РБ2","0");
NewEEPROM("iEM_TERR3SS11LIM",2,&iEM_TERR3SS11LIM,"Искажение: Приход на ВУ гомогенных дверей-1","0");
NewEEPROM("iEM_TERB2SC01RIM",2,&iEM_TERB2SC01RIM,"Искажение: Координата штока РБ2","0");
NewEEPROM("iEM_TERR3SS21LIM",2,&iEM_TERR3SS21LIM,"Искажение: Приход на НУ гомогенных дверей-1","0");
NewEEPROM("iEM_TERR5SS11LIM",2,&iEM_TERR5SS11LIM,"Искажение: Приход на ВУ ворот отстойной зоны","0");
NewEEPROM("iEM_TERA4SS11LIM",2,&iEM_TERA4SS11LIM,"Искажение: Приход на ВУ НИ1","0");
NewEEPROM("iEM_TERR1SS11LIM",2,&iEM_TERR1SS11LIM,"Искажение: Приход на ВУ МДЗ1","0");
NewEEPROM("iEM_TERR1SS21LIM",2,&iEM_TERR1SS21LIM,"Искажение: Приход на НУ МДЗ1","0");
NewEEPROM("iEM_TERR2SS11LIM",2,&iEM_TERR2SS11LIM,"Искажение: Приход на ВУ МДЗ2","0");
NewEEPROM("iEM_TERR2SS21LIM",2,&iEM_TERR2SS21LIM,"Искажение: Приход на НУ МДЗ2","0");
NewEEPROM("iEM_TERA4VP82LIM",2,&iEM_TERA4VP82LIM,"Искажение Давление ПОДЪЁМ НИ в норме","0");
NewEEPROM("iEM_TERB4SS21LIM",2,&iEM_TERB4SS21LIM,"Искажение: Приход на НУ НИ2","0");
NewEEPROM("iEM_TERR5SS21LIM",2,&iEM_TERR5SS21LIM,"Искажение: Приход на НУ ворот отстойной зоны","0");
NewEEPROM("iEM_TERB6SS21LIM",2,&iEM_TERB6SS21LIM,"Искажение: Приход на НУ БЗ2","0");
NewEEPROM("iEM_TERB4SS11LIM",2,&iEM_TERB4SS11LIM,"Искажение: Приход на ВУ НИ2","0");
NewEEPROM("iEM_TERA4SS21LIM",2,&iEM_TERA4SS21LIM,"Искажение: Приход на НУ НИ1","0");
NewEEPROM("iEM_TERA6MS11LIM",2,&iEM_TERA6MS11LIM,"Искажение: Приход на ВУ БЗ1","0");
NewEEPROM("iEM_TERA6SS21LIM",2,&iEM_TERA6SS21LIM,"Искажение: Приход на НУ БЗ1","0");
NewEEPROM("iEM_TERB6SS11LIM",2,&iEM_TERB6SS11LIM,"Искажение: Приход на ВУ БЗ2","0");
NewEEPROM("iEM_TERR4SS11LIM",2,&iEM_TERR4SS11LIM,"Искажение: Приход на ВУ тележки","0");
NewEEPROM("iEM_TERR4MS21LIM",2,&iEM_TERR4MS21LIM,"Искажение: Приход на НУ тележки","0");
NewEEPROM("iEM_TERR4SS12LIM",2,&iEM_TERR4SS12LIM,"Искажение: Приход на механический ВУ тележки","0");
NewEEPROM("iEM_TERR4SS22LIM",2,&iEM_TERR4SS22LIM,"Искажение: Приход на механический НУ тележки","0");
NewEEPROM("iEM_TERR8SS11LIM",2,&iEM_TERR8SS11LIM,"Искажение: Аварийный НИ установлен","0");
NewEEPROM("iEM_TERB8SC01RIM",2,&iEM_TERB8SC01RIM,"Искажение: Координата АЗ2","0");
NewEEPROM("iEM_TERA8SC01RIM",2,&iEM_TERA8SC01RIM,"Искажение: Координата ДС2","0");
NewEEPROM("iEM_TERB8SS12LIM",2,&iEM_TERB8SS12LIM,"Искажение: Приход на механический ВУ АЗ2","0");
NewEEPROM("iEM_TERA8SS12LIM",2,&iEM_TERA8SS12LIM,"Искажение: Приход на механический ВУ ДС2","0");
NewEEPROM("iEM_TERB8SS22LIM",2,&iEM_TERB8SS22LIM,"Искажение: Приход на механический НУ АЗ2","0");
NewEEPROM("iEM_TERA8SS22LIM",2,&iEM_TERA8SS22LIM,"Искажение: Приход на механический НУ ДС2","0");
NewEEPROM("iEM_TERA9SS21LIM",2,&iEM_TERA9SS21LIM,"Искажение: Приход на НУ НИ ДС1","0");
NewEEPROM("iEM_TERB9SS21LIM",2,&iEM_TERB9SS21LIM,"Искажение: Приход на НУ НИ ДС2","0");
NewEEPROM("iEM_TERB9SS11LIM",2,&iEM_TERB9SS11LIM,"Искажение: Приход на ВУ НИ ДС2","0");
NewEEPROM("iEM_TERB5SS21LIM",2,&iEM_TERB5SS21LIM,"Искажение: Приход на НУ НЛ2","0");
NewEEPROM("iEM_TERA1SS21LIM",2,&iEM_TERA1SS21LIM,"Искажение: Приход на НУ ББ1","0");
NewEEPROM("iEM_TERA1SS11LIM",2,&iEM_TERA1SS11LIM,"Искажение: Приход на ВУ ББ1","0");
NewEEPROM("iEM_TERA1SC01RIM",2,&iEM_TERA1SC01RIM,"Искажение: Координата штока ББ1","0");
NewEEPROM("iEM_TERA1SS12LIM",2,&iEM_TERA1SS12LIM,"Искажение: Магнит ББ1 зацеплен","0");
NewEEPROM("iEM_TERB1SS21LIM",2,&iEM_TERB1SS21LIM,"Искажение: Приход на НУ ББ2","0");
NewEEPROM("iEM_TERB1SS11LIM",2,&iEM_TERB1SS11LIM,"Искажение:Приход на ВУ ББ2","0");
NewEEPROM("iEM_TERB1MC01RIM",2,&iEM_TERB1MC01RIM,"Искажение: Координата штока ББ2","0");
NewEEPROM("iEM_TERB1SS12LIM",2,&iEM_TERB1SS12LIM,"Искажение: Магнит ББ2 зацеплен","0");
NewEEPROM("iEM_TERTLG",2,&iEM_TERTLG,"Неисправности  тележки от ИС","0");
NewEEPROM("fEM_R4MC01RC1",1,&fEM_R4MC01RC1,"Заданная координата тележки от ИС","0");
NewEEPROM("fEM_R4MV01RC1",1,&fEM_R4MV01RC1,"Заданная скорость тележки от ИС","0");
NewEEPROM("iEM_TERMAZ2",2,&iEM_TERMAZ2,"Неисправности АЗ2 от ИС","0");
NewEEPROM("fEM_B8MC01RC1",1,&fEM_B8MC01RC1,"Заданная координата АЗ2 от ИС","0");
NewEEPROM("fEM_B8MV01RC1",1,&fEM_B8MV01RC1,"Заданная скорость АЗ2 от ИС","0");
NewEEPROM("iEM_TERDS2",2,&iEM_TERDS2,"Неисправности ДС2 от ИС","0");
NewEEPROM("fEM_A8MC01RC1",1,&fEM_A8MC01RC1,"Заданная координата ДС2 от ИС","0");
NewEEPROM("fEM_A8MV01RC1",1,&fEM_A8MV01RC1,"Заданная скорость ДС2 от ИС","0");
NewEEPROM("iEM_TERBZ1",2,&iEM_TERBZ1,"Неисправности БЗ1","0");
NewEEPROM("fEM_A6MC01RC1",1,&fEM_A6MC01RC1,"Заданная координата БЗ1 от ИС","0");
NewEEPROM("fEM_A6MV01RC1",1,&fEM_A6MV01RC1,"Заданная скорость БЗ1 от ИС","0");
NewEEPROM("iEM_TERBZ2",2,&iEM_TERBZ2,"Неисправности БЗ2","0");
NewEEPROM("fEM_B6MC01RC1",1,&fEM_B6MC01RC1,"Заданная координата БЗ2 от ИС","0");
NewEEPROM("fEM_B6MV01RC1",1,&fEM_B6MV01RC1,"Заданная скорость БЗ2 от ИС","0");
NewEEPROM("lEM_R3AD10LC1",3,&lEM_R3AD10LC1,"Гомогенные двери-1 открыть от ИС","0");
NewEEPROM("lEM_R3AD20LC1",3,&lEM_R3AD20LC1,"Гомогенные двери-1 закрыть от ИС","1");
NewEEPROM("lEM_R6AD10LC1",3,&lEM_R6AD10LC1,"Выкатить кран-балку от ИС","0");
NewEEPROM("lEM_R5AD10LC1",3,&lEM_R5AD10LC1,"Открыть ворота отстойной зоны от ИС","1");
NewEEPROM("lEM_R5AD20LC1",3,&lEM_R5AD20LC1,"Закрыть ворота отстойной зоны от ИС","0");
NewEEPROM("iEM_TERMDZ2",2,&iEM_TERMDZ2,"Неисправности МДЗ2","0");
NewEEPROM("fEM_R2MC01RC1",1,&fEM_R2MC01RC1,"Заданная координата МДЗ2 от ИС","0");
NewEEPROM("fEM_R2MV01RC1",1,&fEM_R2MV01RC1,"Заданная скорость МДЗ2 от ИС","0");
NewEEPROM("iEM_TERMDZ1",2,&iEM_TERMDZ1,"Неисправности МДЗ1","0");
NewEEPROM("fEM_R1MC01RC1",1,&fEM_R1MC01RC1,"Заданная координата МДЗ1 от ИС","0");
NewEEPROM("fEM_R1MV01RC1",1,&fEM_R1MV01RC1,"Заданная скорость МДЗ1 от ИС","0");
NewEEPROM("iEM_TERNL1",2,&iEM_TERNL1,"Неисправности НЛ1","0");
NewEEPROM("fEM_A5MC01RC1",1,&fEM_A5MC01RC1,"Заданная координата НЛ1 от ИС","0");
NewEEPROM("fEM_A5MV01RC1",1,&fEM_A5MV01RC1,"Заданная скорость НЛ1 от ИС","0");
NewEEPROM("iEM_TERNL2",2,&iEM_TERNL2,"Неисправности НЛ2","0");
NewEEPROM("fEM_B5MC01RC1",1,&fEM_B5MC01RC1,"Заданная координата НЛ2 от ИС","0");
NewEEPROM("fEM_B5MV01RC1",1,&fEM_B5MV01RC1,"Заданная скорость НЛ2 от ИС","0");
NewEEPROM("lEM_R8AD10LC1",3,&lEM_R8AD10LC1,"Установить аварийный НИ от ИС","1");
NewEEPROM("fEM_A1UC08RIM",1,&fEM_A1UC08RIM,"Зона срабатывания КВ ББ(мм)","0.01");
NewEEPROM("fEM_A2UC08RIM",1,&fEM_A2UC08RIM,"Зона срабатывания КВ  РБ мм","0.01");
NewEEPROM("fEM_A3UC08RIM",1,&fEM_A3UC08RIM,"Зона срабатывания КВ ИС(мм)","0.01");
NewEEPROM("iEM_TERB2SS33LIM",2,&iEM_TERB2SS33LIM,"Искажение: Клапан «Подъём РБ2»  открыт (обесточен)","0");
NewEEPROM("iEM_TERA1VP81LIM",2,&iEM_TERA1VP81LIM,"Искажение: Текущее давление СБРОС ББ1  в норме","0");
NewEEPROM("iEM_TERB1VP81LIM",2,&iEM_TERB1VP81LIM,"Искажение: Текущее давление СБРОС ББ2  в норме","0");
NewEEPROM("fEM_A0UT03RSP",1,&fEM_A0UT03RSP,"Стартовая  температура АЗ1 град","25.017338");
NewEEPROM("fEM_A0UR01RSP",1,&fEM_A0UR01RSP,"Стартовая  реактивность АЗ1","-0.15912805");
NewEEPROM("fEM_A0UR02RSP",1,&fEM_A0UR02RSP,"Стартовый  поток нейтронов АЗ1","0.000000166");
NewEEPROM("fEM_B0UT03RSP",1,&fEM_B0UT03RSP,"Стартовая  температура АЗ2 град","25.017338");
NewEEPROM("fEM_A1MC01RSP",1,&fEM_A1MC01RSP,"Стартовая координата  ББ1","0");
NewEEPROM("fEM_A1MC02RSP",1,&fEM_A1MC02RSP,"Стартовая координата штока ББ1","0.000167646");
NewEEPROM("fEM_A1MV01RSP",1,&fEM_A1MV01RSP,"Стартовая скорость движения  ББ1","0");
NewEEPROM("fEM_A1MV02RSP",1,&fEM_A1MV02RSP,"Стартовая скорость движения  ББ1","0");
NewEEPROM("fEM_B1MC01RSP",1,&fEM_B1MC01RSP,"Стартовая координата  ББ2","0");
NewEEPROM("fEM_B1MV01RSP",1,&fEM_B1MV01RSP,"Стартовая скорость движения  ББ2","0");
NewEEPROM("fEM_B1MC02RSP",1,&fEM_B1MC02RSP,"Стартовая координата штока ББ2","0.000167676");
NewEEPROM("fEM_B1MV02RSP",1,&fEM_B1MV02RSP,"Стартовая скорость движения  ББ2","0");
NewEEPROM("fEM_A2MC01RC1",1,&fEM_A2MC01RC1,"Заданная координата РБ1 от ИС","0");
NewEEPROM("fEM_A2MV01RC1",1,&fEM_A2MV01RC1,"Заданная скорость движения РБ1 от ИС","0");
NewEEPROM("fEM_A2MC01RSP",1,&fEM_A2MC01RSP,"Стартовая координата  РБ1","0");
NewEEPROM("fEM_A2MV01RSP",1,&fEM_A2MV01RSP,"Стартовая скорость движения  РБ1","0");
NewEEPROM("fEM_A2MC02RSP",1,&fEM_A2MC02RSP,"Стартовая координата штока РБ1","0");
NewEEPROM("fEM_A2MV02RSP",1,&fEM_A2MV02RSP,"Стартовая скорость движения  РБ1","0");
NewEEPROM("fEM_B2MC01RSP",1,&fEM_B2MC01RSP,"Стартовая координата  РБ2","0");
NewEEPROM("fEM_B2MV01RSP",1,&fEM_B2MV01RSP,"Стартовая скорость движения  РБ2","0");
NewEEPROM("fEM_B2MC02RSP",1,&fEM_B2MC02RSP,"Стартовая координата штока РБ2","0");
NewEEPROM("fEM_B2MV02RSP",1,&fEM_B2MV02RSP,"Стартовая скорость движения  РБ2","0");
NewEEPROM("fEM_A3MC01RSP",1,&fEM_A3MC01RSP,"Стартовая координата  ИС1","0.000885839");
NewEEPROM("fEM_A3MV01RSP",1,&fEM_A3MV01RSP,"Стартовая скорость движения  ИС1","0");
NewEEPROM("fEM_A3MC02RSP",1,&fEM_A3MC02RSP,"Стартовая координата штока ИС1","0.000885839");
NewEEPROM("fEM_A3MV02RSP",1,&fEM_A3MV02RSP,"Стартовая скорость движения  ИС1","0");
NewEEPROM("fEM_B3MC01RSP",1,&fEM_B3MC01RSP,"Стартовая координата  ИС2","0.000885839");
NewEEPROM("fEM_B3MV01RSP",1,&fEM_B3MV01RSP,"Стартовая скорость движения  ИС2","0");
NewEEPROM("fEM_B3MC02RSP",1,&fEM_B3MC02RSP,"Стартовая координата штока ИС2","0.000885839");
NewEEPROM("fEM_B3MV02RSP",1,&fEM_B3MV02RSP,"Стартовая скорость движения  ИС2","0");
NewEEPROM("fEM_B8MC01RSP",1,&fEM_B8MC01RSP,"Стартовая координата АЗ2","390");
NewEEPROM("fEM_B8MV01RSP",1,&fEM_B8MV01RSP,"Стартовая скорость АЗ2","0");
NewEEPROM("fEM_A8MC01RSP",1,&fEM_A8MC01RSP,"Стартовая координата ДС2","390");
NewEEPROM("fEM_A8MV01RSP",1,&fEM_A8MV01RSP,"Стартовая скорость ДС2","0");
NewEEPROM("fEM_A6MC01RSP",1,&fEM_A6MC01RSP,"Стартовая координата БЗ1","55");
NewEEPROM("fEM_A6MV01RSP",1,&fEM_A6MV01RSP,"Стартовая скорость БЗ1","0");
NewEEPROM("fEM_B6MC01RSP",1,&fEM_B6MC01RSP,"Стартовая координата БЗ2","55");
NewEEPROM("fEM_B6MV01RSP",1,&fEM_B6MV01RSP,"Стартовая скорость БЗ2","0");
NewEEPROM("fEM_R3UC01RSP",1,&fEM_R3UC01RSP,"Стартовая координата Гомогенных дверей","0");
NewEEPROM("fEM_R3UV01RSP",1,&fEM_R3UV01RSP,"Стартовая скорость Гомогенных дверей","0");
NewEEPROM("fEM_R5UC01RSP",1,&fEM_R5UC01RSP,"Стартовая координата Ворот отстойной зоны","4000.0");
NewEEPROM("fEM_R5UV01RSP",1,&fEM_R5UV01RSP,"Стартовая скорость Ворот отстойной зоны","0");
NewEEPROM("fEM_R6UC01RSP",1,&fEM_R6UC01RSP,"Стартовая координата Кран-балки","10");
NewEEPROM("fEM_R6UV01RSP",1,&fEM_R6UV01RSP,"Стартовая скорость Кран-балки","0");
NewEEPROM("fEM_R2MC01RSP",1,&fEM_R2MC01RSP,"Стартовая координата МДЗ2","0");
NewEEPROM("fEM_R2MV01RSP",1,&fEM_R2MV01RSP,"Стартовая скорость МДЗ2","0");
NewEEPROM("fEM_R1MC01RSP",1,&fEM_R1MC01RSP,"Стартовая координата МДЗ1","0");
NewEEPROM("fEM_R1MV01RSP",1,&fEM_R1MV01RSP,"Стартовая скорость МДЗ1","0");
NewEEPROM("fEM_A5MC01RSP",1,&fEM_A5MC01RSP,"Стартовая координата НЛ1","5");
NewEEPROM("fEM_A5MV01RSP",1,&fEM_A5MV01RSP,"Стартовая скорость НЛ1","0");
NewEEPROM("fEM_B5MC01RSP",1,&fEM_B5MC01RSP,"Стартовая координата НЛ2","5");
NewEEPROM("fEM_B5MV01RSP",1,&fEM_B5MV01RSP,"Стартовая скорость НЛ2","0");
NewEEPROM("fEM_A9MC01RSP",1,&fEM_A9MC01RSP,"Стартовая координата НИ ДС1","0");
NewEEPROM("fEM_A9MV01RSP",1,&fEM_A9MV01RSP,"Стартовая скорость НИ ДС1","0");
NewEEPROM("fEM_B9MC01RSP",1,&fEM_B9MC01RSP,"Стартовая координата НИ ДС2","0");
NewEEPROM("fEM_B9MV01RSP",1,&fEM_B9MV01RSP,"Стартовая скорость НИ ДС2","0");
NewEEPROM("fEM_A4MC01RSP",1,&fEM_A4MC01RSP,"Стартовая координата НИ1","0");
NewEEPROM("fEM_A4MV01RSP",1,&fEM_A4MV01RSP,"Стартовая скорость НИ1","0");
NewEEPROM("fEM_B4MC01RSP",1,&fEM_B4MC01RSP,"Стартовая координата НИ2","0");
NewEEPROM("fEM_B4MV01RSP",1,&fEM_B4MV01RSP,"Стартовая скорость НИ2","0");
NewEEPROM("fEM_R4MC01RSP",1,&fEM_R4MC01RSP,"Стартовая координата тележки","15650");
NewEEPROM("fEM_R4MV01RSP",1,&fEM_R4MV01RSP,"Стартовая скорость тележки","0");
NewEEPROM("fEM_A1MV01RC1",1,&fEM_A1MV01RC1,"Заданная скорость движения  ББ1 от ИС","0");
NewEEPROM("iEM_TERB7MS31LIM",2,&iEM_TERB7MS31LIM,"Искажение: Клапан (Обдув АЗ2) открыт (обесточен)","0");
NewEEPROM("iEM_TERA7MS31LIM",2,&iEM_TERA7MS31LIM,"Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)","0");
NewEEPROM("fEM_R7UY00RSS",1,&fEM_R7UY00RSS,"Y-координата АЗ1 см","506.6");
NewEEPROM("iEM_TERA6VS12LIM",2,&iEM_TERA6VS12LIM,"Искажение: Движение створок БЗ1 к ОТКРЫТА","0");
NewEEPROM("iEM_TERA6VS22LIM",2,&iEM_TERA6VS22LIM,"Искажение: Движение створок БЗ1 к ЗАКРЫТА","0");
NewEEPROM("iEM_TERB6VS12LIM",2,&iEM_TERB6VS12LIM,"Искажение: Движение створок БЗ2 к ОТКРЫТА","0");
NewEEPROM("iEM_TERB6VS22LIM",2,&iEM_TERB6VS22LIM,"Искажение: Движение створок БЗ2 к ЗАКРЫТА","0");
NewEEPROM("iEM_TERA5VS22LIM",2,&iEM_TERA5VS22LIM,"Искажение: Движение створок НЛ1 к НУ","0");
NewEEPROM("iEM_TERA5VS12LIM",2,&iEM_TERA5VS12LIM,"Искажение: Движение створок НЛ1 к ВУ","0");
NewEEPROM("iEM_TERB5VS12LIM",2,&iEM_TERB5VS12LIM,"Искажение: Движение створок НЛ2 к ВУ","0");
NewEEPROM("iEM_TERB5VS22LIM",2,&iEM_TERB5VS22LIM,"Искажение: Движение створок НЛ2 к НУ","0");
NewEEPROM("iEM_TERR1VS12LIM",2,&iEM_TERR1VS12LIM,"Искажение: Движение МДЗ1 в сторону ВУ","0");
NewEEPROM("iEM_TERR1VS22LIM",2,&iEM_TERR1VS22LIM,"Искажение: Движение МДЗ1 в сторону НУ","0");
NewEEPROM("iEM_TERR2VS12LIM",2,&iEM_TERR2VS12LIM,"Искажение: Движение МДЗ2 в сторону ВУ","0");
NewEEPROM("iEM_TERR2VS22LIM",2,&iEM_TERR2VS22LIM,"Искажение: Движение МДЗ2 в сторону НУ","0");
NewEEPROM("iEM_TERR4VS12LDU",2,&iEM_TERR4VS12LDU,"Искажение: Движение реактора к «У ЗАЩИТЫ»","0");
NewEEPROM("iEM_TERR4VS22LDU",2,&iEM_TERR4VS22LDU,"Искажение: Движение реактора к «У ЗАЩИТЫ»","0");
NewEEPROM("fEM_R4UC23RIM",1,&fEM_R4UC23RIM,"Y-координата АЗ1","5065.0");
NewEEPROM("fEM_A0UX13RSS",1,&fEM_A0UX13RSS,"Первый коэффициент калибровки камеры 13","1.0");
NewEEPROM("fEM_A0UX14RSS",1,&fEM_A0UX14RSS,"Первый коэффициент калибровки камеры 14","1.0");
NewEEPROM("fEM_A0UX15RSS",1,&fEM_A0UX15RSS,"Первый коэффициент калибровки камеры 15","1.0");
NewEEPROM("fEM_R7UX13RSS",1,&fEM_R7UX13RSS,"X-координата камеры R7IN51","1570.0");
NewEEPROM("fEM_R7UX14RSS",1,&fEM_R7UX14RSS,"X-координата камеры R7IN52","1269");
NewEEPROM("fEM_R7UX15RSS",1,&fEM_R7UX15RSS,"X-координата камеры R7IN53","1281.2");
NewEEPROM("fEM_R7UY13RSS",1,&fEM_R7UY13RSS,"Y-координата камеры R7IN51","248.0");
NewEEPROM("fEM_R7UY14RSS",1,&fEM_R7UY14RSS,"Y-координата камеры R7IN52","572.4");
NewEEPROM("fEM_R7UY15RSS",1,&fEM_R7UY15RSS,"Y-координата камеры R7IN53","246.8");
NewEEPROM("fEM_R7UX16RSS",1,&fEM_R7UX16RSS,"Величина сигнала СНМ11 в БЗ","1");
#else
if(EEPROMFlag) {
  fplet(&fEM_R0UL01RIM.f,((float*)(IntEEPROMBuffer+0x0)));
  fEM_R0UL01RIM.error = 0;
  fplet(&fEM_R0UN02RIM.f,((float*)(IntEEPROMBuffer+0x4)));
  fEM_R0UN02RIM.error = 0;
  fplet(&fEM_A1UR01RIM.f,((float*)(IntEEPROMBuffer+0x8)));
  fEM_A1UR01RIM.error = 0;
  fplet(&fEM_A1UR00RIM.f,((float*)(IntEEPROMBuffer+0xC)));
  fEM_A1UR00RIM.error = 0;
  fplet(&fEM_A3UR00RIM.f,((float*)(IntEEPROMBuffer+0x10)));
  fEM_A3UR00RIM.error = 0;
  fplet(&fEM_A3UR01RIM.f,((float*)(IntEEPROMBuffer+0x14)));
  fEM_A3UR01RIM.error = 0;
  fplet(&fEM_R0UT01RIM.f,((float*)(IntEEPROMBuffer+0x18)));
  fEM_R0UT01RIM.error = 0;
  fplet(&fEM_R0UT02RIM.f,((float*)(IntEEPROMBuffer+0x1C)));
  fEM_R0UT02RIM.error = 0;
  fplet(&fEM_R0UT04RIM.f,((float*)(IntEEPROMBuffer+0x20)));
  fEM_R0UT04RIM.error = 0;
  fplet(&fEM_R0UT03RIM.f,((float*)(IntEEPROMBuffer+0x24)));
  fEM_R0UT03RIM.error = 0;
  fplet(&fEM_R0UT05RIM.f,((float*)(IntEEPROMBuffer+0x28)));
  fEM_R0UT05RIM.error = 0;
  fplet(&fEM_R0UT06RIM.f,((float*)(IntEEPROMBuffer+0x2C)));
  fEM_R0UT06RIM.error = 0;
  fplet(&fEM_A1UC02RDU.f,((float*)(IntEEPROMBuffer+0x30)));
  fEM_A1UC02RDU.error = 0;
  fplet(&fEM_A1UC04RIM.f,((float*)(IntEEPROMBuffer+0x34)));
  fEM_A1UC04RIM.error = 0;
  fplet(&fEM_A1UC05RIM.f,((float*)(IntEEPROMBuffer+0x38)));
  fEM_A1UC05RIM.error = 0;
  fplet(&fEM_A1UC06RIM.f,((float*)(IntEEPROMBuffer+0x3C)));
  fEM_A1UC06RIM.error = 0;
  fplet(&fEM_A2UC06RIM.f,((float*)(IntEEPROMBuffer+0x40)));
  fEM_A2UC06RIM.error = 0;
  fplet(&fEM_A2UC05RIM.f,((float*)(IntEEPROMBuffer+0x44)));
  fEM_A2UC05RIM.error = 0;
  fplet(&fEM_A2UC04RIM.f,((float*)(IntEEPROMBuffer+0x48)));
  fEM_A2UC04RIM.error = 0;
  fplet(&fEM_A2UC02RDU.f,((float*)(IntEEPROMBuffer+0x4C)));
  fEM_A2UC02RDU.error = 0;
  fplet(&fEM_A3UC06RIM.f,((float*)(IntEEPROMBuffer+0x50)));
  fEM_A3UC06RIM.error = 0;
  fplet(&fEM_A3UC05RIM.f,((float*)(IntEEPROMBuffer+0x54)));
  fEM_A3UC05RIM.error = 0;
  fplet(&fEM_A3UC04RIM.f,((float*)(IntEEPROMBuffer+0x58)));
  fEM_A3UC04RIM.error = 0;
  fplet(&fEM_A3UC02RDU.f,((float*)(IntEEPROMBuffer+0x5C)));
  fEM_A3UC02RDU.error = 0;
  fplet(&fEM_R4UV80RDU.f,((float*)(IntEEPROMBuffer+0x60)));
  fEM_R4UV80RDU.error = 0;
  fplet(&fEM_R4UC10RIM.f,((float*)(IntEEPROMBuffer+0x64)));
  fEM_R4UC10RIM.error = 0;
  fplet(&fEM_R4UC20RIM.f,((float*)(IntEEPROMBuffer+0x68)));
  fEM_R4UC20RIM.error = 0;
  fplet(&fEM_B8UC21RIM.f,((float*)(IntEEPROMBuffer+0x6C)));
  fEM_B8UC21RIM.error = 0;
  fplet(&fEM_B8UC20RIM.f,((float*)(IntEEPROMBuffer+0x70)));
  fEM_B8UC20RIM.error = 0;
  fplet(&fEM_B8UC11RIM.f,((float*)(IntEEPROMBuffer+0x74)));
  fEM_B8UC11RIM.error = 0;
  fplet(&fEM_B8UC10RIM.f,((float*)(IntEEPROMBuffer+0x78)));
  fEM_B8UC10RIM.error = 0;
  fplet(&fEM_B8UV80RDU.f,((float*)(IntEEPROMBuffer+0x7C)));
  fEM_B8UV80RDU.error = 0;
  fplet(&fEM_A8UV80RDU.f,((float*)(IntEEPROMBuffer+0x80)));
  fEM_A8UV80RDU.error = 0;
  fplet(&fEM_A8UC10RIM.f,((float*)(IntEEPROMBuffer+0x84)));
  fEM_A8UC10RIM.error = 0;
  fplet(&fEM_A8UC11RIM.f,((float*)(IntEEPROMBuffer+0x88)));
  fEM_A8UC11RIM.error = 0;
  fplet(&fEM_A8UC20RIM.f,((float*)(IntEEPROMBuffer+0x8C)));
  fEM_A8UC20RIM.error = 0;
  fplet(&fEM_A8UC21RIM.f,((float*)(IntEEPROMBuffer+0x90)));
  fEM_A8UC21RIM.error = 0;
  fplet(&fEM_A6UC10RIM.f,((float*)(IntEEPROMBuffer+0x94)));
  fEM_A6UC10RIM.error = 0;
  fplet(&fEM_R1UC10RIM.f,((float*)(IntEEPROMBuffer+0x98)));
  fEM_R1UC10RIM.error = 0;
  fplet(&fEM_A5UC10RIM.f,((float*)(IntEEPROMBuffer+0x9C)));
  fEM_A5UC10RIM.error = 0;
  fplet(&fEM_A0UN01RIM.f,((float*)(IntEEPROMBuffer+0xA0)));
  fEM_A0UN01RIM.error = 0;
  fplet(&fEM_R4UC22RIM.f,((float*)(IntEEPROMBuffer+0xA4)));
  fEM_R4UC22RIM.error = 0;
  fplet(&fEM_A1UG01RDU.f,((float*)(IntEEPROMBuffer+0xA8)));
  fEM_A1UG01RDU.error = 0;
  fplet(&fEM_A2UG01RDU.f,((float*)(IntEEPROMBuffer+0xAC)));
  fEM_A2UG01RDU.error = 0;
  fplet(&fEM_A3UG01RDU.f,((float*)(IntEEPROMBuffer+0xB0)));
  fEM_A3UG01RDU.error = 0;
  fplet(&fEM_R7UC10RIM.f,((float*)(IntEEPROMBuffer+0xB4)));
  fEM_R7UC10RIM.error = 0;
  fplet(&fEM_R7UC19RIM.f,((float*)(IntEEPROMBuffer+0xB8)));
  fEM_R7UC19RIM.error = 0;
  fplet(&fEM_R7UI02RIM.f,((float*)(IntEEPROMBuffer+0xBC)));
  fEM_R7UI02RIM.error = 0;
  fplet(&fEM_R7UL01RIM.f,((float*)(IntEEPROMBuffer+0xC0)));
  fEM_R7UL01RIM.error = 0;
  fplet(&fEM_A2UR00RIM.f,((float*)(IntEEPROMBuffer+0xC4)));
  fEM_A2UR00RIM.error = 0;
  fplet(&fEM_A2UR01RIM.f,((float*)(IntEEPROMBuffer+0xC8)));
  fEM_A2UR01RIM.error = 0;
  fplet(&fEM_A0UN02RIM.f,((float*)(IntEEPROMBuffer+0xCC)));
  fEM_A0UN02RIM.error = 0;
  fplet(&fEM_R0UR30RIM.f,((float*)(IntEEPROMBuffer+0xD0)));
  fEM_R0UR30RIM.error = 0;
  fplet(&fEM_R0UR01RIM.f,((float*)(IntEEPROMBuffer+0xD4)));
  fEM_R0UR01RIM.error = 0;
  fplet(&fEM_R0UT02RDU.f,((float*)(IntEEPROMBuffer+0xD8)));
  fEM_R0UT02RDU.error = 0;
  fplet(&fEM_R0UT01RDU.f,((float*)(IntEEPROMBuffer+0xDC)));
  fEM_R0UT01RDU.error = 0;
  fplet(&fEM_A1UC03RDU.f,((float*)(IntEEPROMBuffer+0xE0)));
  fEM_A1UC03RDU.error = 0;
  fplet(&fEM_A2UP03RDU.f,((float*)(IntEEPROMBuffer+0xE4)));
  fEM_A2UP03RDU.error = 0;
  fplet(&fEM_A2UP04RDU.f,((float*)(IntEEPROMBuffer+0xE8)));
  fEM_A2UP04RDU.error = 0;
  fplet(&fEM_A2UC03RDU.f,((float*)(IntEEPROMBuffer+0xEC)));
  fEM_A2UC03RDU.error = 0;
  fplet(&fEM_A3UP03RDU.f,((float*)(IntEEPROMBuffer+0xF0)));
  fEM_A3UP03RDU.error = 0;
  fplet(&fEM_A3UP04RDU.f,((float*)(IntEEPROMBuffer+0xF4)));
  fEM_A3UP04RDU.error = 0;
  fplet(&fEM_A3UC03RDU.f,((float*)(IntEEPROMBuffer+0xF8)));
  fEM_A3UC03RDU.error = 0;
  fplet(&fEM_R7UI74RIM.f,((float*)(IntEEPROMBuffer+0xFC)));
  fEM_R7UI74RIM.error = 0;
  fplet(&fEM_A8UC03RDU.f,((float*)(IntEEPROMBuffer+0x100)));
  fEM_A8UC03RDU.error = 0;
  fplet(&fEM_R0UV87RDU.f,((float*)(IntEEPROMBuffer+0x104)));
  fEM_R0UV87RDU.error = 0;
  fplet(&fEM_R0UV81RDU.f,((float*)(IntEEPROMBuffer+0x108)));
  fEM_R0UV81RDU.error = 0;
  fplet(&fEM_R0UV82RDU.f,((float*)(IntEEPROMBuffer+0x10C)));
  fEM_R0UV82RDU.error = 0;
  fplet(&fEM_R0UV83RDU.f,((float*)(IntEEPROMBuffer+0x110)));
  fEM_R0UV83RDU.error = 0;
  fplet(&fEM_R0UV84RDU.f,((float*)(IntEEPROMBuffer+0x114)));
  fEM_R0UV84RDU.error = 0;
  fplet(&fEM_R0UV85RDU.f,((float*)(IntEEPROMBuffer+0x118)));
  fEM_R0UV85RDU.error = 0;
  fplet(&fEM_R0UV86RDU.f,((float*)(IntEEPROMBuffer+0x11C)));
  fEM_R0UV86RDU.error = 0;
  fplet(&fEM_A8UC08RDU.f,((float*)(IntEEPROMBuffer+0x120)));
  fEM_A8UC08RDU.error = 0;
  fplet(&fEM_B8UC08RDU.f,((float*)(IntEEPROMBuffer+0x124)));
  fEM_B8UC08RDU.error = 0;
  fplet(&fEM_R4UC08RDU.f,((float*)(IntEEPROMBuffer+0x128)));
  fEM_R4UC08RDU.error = 0;
  fplet(&fEM_R0UH01RSS.f,((float*)(IntEEPROMBuffer+0x12C)));
  fEM_R0UH01RSS.error = 0;
  fplet(&fEM_A0UX00RSS.f,((float*)(IntEEPROMBuffer+0x130)));
  fEM_A0UX00RSS.error = 0;
  fplet(&fEM_R7UX01RSS.f,((float*)(IntEEPROMBuffer+0x134)));
  fEM_R7UX01RSS.error = 0;
  fplet(&fEM_R7UX02RSS.f,((float*)(IntEEPROMBuffer+0x138)));
  fEM_R7UX02RSS.error = 0;
  fplet(&fEM_R7UX04RSS.f,((float*)(IntEEPROMBuffer+0x13C)));
  fEM_R7UX04RSS.error = 0;
  fplet(&fEM_R7UX05RSS.f,((float*)(IntEEPROMBuffer+0x140)));
  fEM_R7UX05RSS.error = 0;
  fplet(&fEM_R7UX06RSS.f,((float*)(IntEEPROMBuffer+0x144)));
  fEM_R7UX06RSS.error = 0;
  fplet(&fEM_R7UX07RSS.f,((float*)(IntEEPROMBuffer+0x148)));
  fEM_R7UX07RSS.error = 0;
  fplet(&fEM_R7UX08RSS.f,((float*)(IntEEPROMBuffer+0x14C)));
  fEM_R7UX08RSS.error = 0;
  fplet(&fEM_R7UX09RSS.f,((float*)(IntEEPROMBuffer+0x150)));
  fEM_R7UX09RSS.error = 0;
  fplet(&fEM_R7UY01RSS.f,((float*)(IntEEPROMBuffer+0x154)));
  fEM_R7UY01RSS.error = 0;
  fplet(&fEM_R7UY02RSS.f,((float*)(IntEEPROMBuffer+0x158)));
  fEM_R7UY02RSS.error = 0;
  fplet(&fEM_R7UY04RSS.f,((float*)(IntEEPROMBuffer+0x15C)));
  fEM_R7UY04RSS.error = 0;
  fplet(&fEM_R7UY05RSS.f,((float*)(IntEEPROMBuffer+0x160)));
  fEM_R7UY05RSS.error = 0;
  fplet(&fEM_R7UY06RSS.f,((float*)(IntEEPROMBuffer+0x164)));
  fEM_R7UY06RSS.error = 0;
  fplet(&fEM_R7UY07RSS.f,((float*)(IntEEPROMBuffer+0x168)));
  fEM_R7UY07RSS.error = 0;
  fplet(&fEM_R7UY08RSS.f,((float*)(IntEEPROMBuffer+0x16C)));
  fEM_R7UY08RSS.error = 0;
  fplet(&fEM_R7UY09RSS.f,((float*)(IntEEPROMBuffer+0x170)));
  fEM_R7UY09RSS.error = 0;
  fplet(&fEM_R7UX10RSS.f,((float*)(IntEEPROMBuffer+0x174)));
  fEM_R7UX10RSS.error = 0;
  fplet(&fEM_R7UX11RSS.f,((float*)(IntEEPROMBuffer+0x178)));
  fEM_R7UX11RSS.error = 0;
  fplet(&fEM_R7UX12RSS.f,((float*)(IntEEPROMBuffer+0x17C)));
  fEM_R7UX12RSS.error = 0;
  fplet(&fEM_R7UY10RSS.f,((float*)(IntEEPROMBuffer+0x180)));
  fEM_R7UY10RSS.error = 0;
  fplet(&fEM_R7UY11RSS.f,((float*)(IntEEPROMBuffer+0x184)));
  fEM_R7UY11RSS.error = 0;
  fplet(&fEM_R7UY12RSS.f,((float*)(IntEEPROMBuffer+0x188)));
  fEM_R7UY12RSS.error = 0;
  fplet(&fEM_A0UX01RSS.f,((float*)(IntEEPROMBuffer+0x18C)));
  fEM_A0UX01RSS.error = 0;
  fplet(&fEM_A0UX02RSS.f,((float*)(IntEEPROMBuffer+0x190)));
  fEM_A0UX02RSS.error = 0;
  fplet(&fEM_A0UX03RSS.f,((float*)(IntEEPROMBuffer+0x194)));
  fEM_A0UX03RSS.error = 0;
  fplet(&fEM_A0UX04RSS.f,((float*)(IntEEPROMBuffer+0x198)));
  fEM_A0UX04RSS.error = 0;
  fplet(&fEM_A0UX05RSS.f,((float*)(IntEEPROMBuffer+0x19C)));
  fEM_A0UX05RSS.error = 0;
  fplet(&fEM_A0UX06RSS.f,((float*)(IntEEPROMBuffer+0x1A0)));
  fEM_A0UX06RSS.error = 0;
  fplet(&fEM_A0UX07RSS.f,((float*)(IntEEPROMBuffer+0x1A4)));
  fEM_A0UX07RSS.error = 0;
  fplet(&fEM_A0UX08RSS.f,((float*)(IntEEPROMBuffer+0x1A8)));
  fEM_A0UX08RSS.error = 0;
  fplet(&fEM_A0UX09RSS.f,((float*)(IntEEPROMBuffer+0x1AC)));
  fEM_A0UX09RSS.error = 0;
  fplet(&fEM_A0UX10RSS.f,((float*)(IntEEPROMBuffer+0x1B0)));
  fEM_A0UX10RSS.error = 0;
  fplet(&fEM_A0UX11RSS.f,((float*)(IntEEPROMBuffer+0x1B4)));
  fEM_A0UX11RSS.error = 0;
  fplet(&fEM_A0UX12RSS.f,((float*)(IntEEPROMBuffer+0x1B8)));
  fEM_A0UX12RSS.error = 0;
  fplet(&fEM_B0UX01RSS.f,((float*)(IntEEPROMBuffer+0x1BC)));
  fEM_B0UX01RSS.error = 0;
  fplet(&fEM_B0UX02RSS.f,((float*)(IntEEPROMBuffer+0x1C0)));
  fEM_B0UX02RSS.error = 0;
  fplet(&fEM_B0UX03RSS.f,((float*)(IntEEPROMBuffer+0x1C4)));
  fEM_B0UX03RSS.error = 0;
  fplet(&fEM_B0UX04RSS.f,((float*)(IntEEPROMBuffer+0x1C8)));
  fEM_B0UX04RSS.error = 0;
  fplet(&fEM_B0UX05RSS.f,((float*)(IntEEPROMBuffer+0x1CC)));
  fEM_B0UX05RSS.error = 0;
  fplet(&fEM_B0UX06RSS.f,((float*)(IntEEPROMBuffer+0x1D0)));
  fEM_B0UX06RSS.error = 0;
  fplet(&fEM_B0UX07RSS.f,((float*)(IntEEPROMBuffer+0x1D4)));
  fEM_B0UX07RSS.error = 0;
  fplet(&fEM_B0UX08RSS.f,((float*)(IntEEPROMBuffer+0x1D8)));
  fEM_B0UX08RSS.error = 0;
  fplet(&fEM_B0UX09RSS.f,((float*)(IntEEPROMBuffer+0x1DC)));
  fEM_B0UX09RSS.error = 0;
  fplet(&fEM_B0UX10RSS.f,((float*)(IntEEPROMBuffer+0x1E0)));
  fEM_B0UX10RSS.error = 0;
  fplet(&fEM_B0UX11RSS.f,((float*)(IntEEPROMBuffer+0x1E4)));
  fEM_B0UX11RSS.error = 0;
  fplet(&fEM_B0UX12RSS.f,((float*)(IntEEPROMBuffer+0x1E8)));
  fEM_B0UX12RSS.error = 0;
  fplet(&fEM_R0UH02RSS.f,((float*)(IntEEPROMBuffer+0x1EC)));
  fEM_R0UH02RSS.error = 0;
  fplet(&fEM_R0UH03RSS.f,((float*)(IntEEPROMBuffer+0x1F0)));
  fEM_R0UH03RSS.error = 0;
  fplet(&fEM_R4US80RDU.f,((float*)(IntEEPROMBuffer+0x1F4)));
  fEM_R4US80RDU.error = 0;
  fplet(&fEM_R7UI71RIM.f,((float*)(IntEEPROMBuffer+0x1F8)));
  fEM_R7UI71RIM.error = 0;
  fplet(&fEM_R7UI72RIM.f,((float*)(IntEEPROMBuffer+0x1FC)));
  fEM_R7UI72RIM.error = 0;
  fplet(&fEM_R7UI73RIM.f,((float*)(IntEEPROMBuffer+0x200)));
  fEM_R7UI73RIM.error = 0;
  fplet(&fEM_A1UP01RIM.f,((float*)(IntEEPROMBuffer+0x204)));
  fEM_A1UP01RIM.error = 0;
  fplet(&fEM_A2UP01RIM.f,((float*)(IntEEPROMBuffer+0x208)));
  fEM_A2UP01RIM.error = 0;
  fplet(&fEM_A0UP02RIM.f,((float*)(IntEEPROMBuffer+0x20C)));
  fEM_A0UP02RIM.error = 0;
  fplet(&fEM_A3UP01RIM.f,((float*)(IntEEPROMBuffer+0x210)));
  fEM_A3UP01RIM.error = 0;
  fplet(&fEM_A1UP82RIM.f,((float*)(IntEEPROMBuffer+0x214)));
  fEM_A1UP82RIM.error = 0;
  fplet(&fEM_A3UP02RDU.f,((float*)(IntEEPROMBuffer+0x218)));
  fEM_A3UP02RDU.error = 0;
  fplet(&fEM_A1UV02RIM.f,((float*)(IntEEPROMBuffer+0x21C)));
  fEM_A1UV02RIM.error = 0;
  fplet(&fEM_A3UV02RIM.f,((float*)(IntEEPROMBuffer+0x220)));
  fEM_A3UV02RIM.error = 0;
  fplet(&fEM_A2UV02RIM.f,((float*)(IntEEPROMBuffer+0x224)));
  fEM_A2UV02RIM.error = 0;
  fplet(&fEM_B8US80RDU.f,((float*)(IntEEPROMBuffer+0x228)));
  fEM_B8US80RDU.error = 0;
  fplet(&fEM_A8US80RDU.f,((float*)(IntEEPROMBuffer+0x22C)));
  fEM_A8US80RDU.error = 0;
  fplet(&fEM_A6US80RDU.f,((float*)(IntEEPROMBuffer+0x230)));
  fEM_A6US80RDU.error = 0;
  fplet(&fEM_A1US07RDU.f,((float*)(IntEEPROMBuffer+0x234)));
  fEM_A1US07RDU.error = 0;
  fplet(&fEM_A2US07RDU.f,((float*)(IntEEPROMBuffer+0x238)));
  fEM_A2US07RDU.error = 0;
  fplet(&fEM_A3US07RDU.f,((float*)(IntEEPROMBuffer+0x23C)));
  fEM_A3US07RDU.error = 0;
  fplet(&fEM_R7UI75RIM.f,((float*)(IntEEPROMBuffer+0x240)));
  fEM_R7UI75RIM.error = 0;
  fplet(&fEM_R0UH21RSS.f,((float*)(IntEEPROMBuffer+0x244)));
  fEM_R0UH21RSS.error = 0;
  fplet(&fEM_R0UH22RSS.f,((float*)(IntEEPROMBuffer+0x248)));
  fEM_R0UH22RSS.error = 0;
  fplet(&fEM_R0UH23RSS.f,((float*)(IntEEPROMBuffer+0x24C)));
  fEM_R0UH23RSS.error = 0;
  fplet(&fEM_R0UH05RSS.f,((float*)(IntEEPROMBuffer+0x250)));
  fEM_R0UH05RSS.error = 0;
  fplet(&fEM_A4UL10RIM.f,((float*)(IntEEPROMBuffer+0x254)));
  fEM_A4UL10RIM.error = 0;
  fplet(&fEM_A9UL10RIM.f,((float*)(IntEEPROMBuffer+0x258)));
  fEM_A9UL10RIM.error = 0;
  fplet(&fEM_R3UL10RIM.f,((float*)(IntEEPROMBuffer+0x25C)));
  fEM_R3UL10RIM.error = 0;
  fplet(&fEM_R5UL10RIM.f,((float*)(IntEEPROMBuffer+0x260)));
  fEM_R5UL10RIM.error = 0;
  fplet(&fEM_R6UL10RIM.f,((float*)(IntEEPROMBuffer+0x264)));
  fEM_R6UL10RIM.error = 0;
  lEM_C1AD31LRP.b = *((uspaint8*)(IntEEPROMBuffer+0x268));
  lEM_C1AD31LRP.error = 0;
  lEM_R0IE01LRP.b = *((uspaint8*)(IntEEPROMBuffer+0x269));
  lEM_R0IE01LRP.error = 0;
  lEM_R0IE02LRP.b = *((uspaint8*)(IntEEPROMBuffer+0x26A));
  lEM_R0IE02LRP.error = 0;
  fplet(&fEM_A2UP02RIM.f,((float*)(IntEEPROMBuffer+0x26B)));
  fEM_A2UP02RIM.error = 0;
  fplet(&fEM_A2UP03RIM.f,((float*)(IntEEPROMBuffer+0x26F)));
  fEM_A2UP03RIM.error = 0;
  fplet(&fEM_A0UP01RIM.f,((float*)(IntEEPROMBuffer+0x273)));
  fEM_A0UP01RIM.error = 0;
  fplet(&fEM_A3UP02RIM.f,((float*)(IntEEPROMBuffer+0x277)));
  fEM_A3UP02RIM.error = 0;
  fplet(&fEM_A4UP01RIM.f,((float*)(IntEEPROMBuffer+0x27B)));
  fEM_A4UP01RIM.error = 0;
  fplet(&fEM_A4UP02RIM.f,((float*)(IntEEPROMBuffer+0x27F)));
  fEM_A4UP02RIM.error = 0;
  fplet(&fEM_R7UI76RIM.f,((float*)(IntEEPROMBuffer+0x283)));
  fEM_R7UI76RIM.error = 0;
  fplet(&fEM_R7UI77RIM.f,((float*)(IntEEPROMBuffer+0x287)));
  fEM_R7UI77RIM.error = 0;
  iEM_TERBB1.i = *((__int16*)(IntEEPROMBuffer+0x28B));
  iEM_TERBB1.error = 0;
  fplet(&fEM_A1MC02RC1.f,((float*)(IntEEPROMBuffer+0x28D)));
  fEM_A1MC02RC1.error = 0;
  fplet(&fEM_A1MV02RC1.f,((float*)(IntEEPROMBuffer+0x291)));
  fEM_A1MV02RC1.error = 0;
  iEM_TERBB2.i = *((__int16*)(IntEEPROMBuffer+0x295));
  iEM_TERBB2.error = 0;
  fplet(&fEM_B1MC02RC1.f,((float*)(IntEEPROMBuffer+0x297)));
  fEM_B1MC02RC1.error = 0;
  fplet(&fEM_B1MV02RC1.f,((float*)(IntEEPROMBuffer+0x29B)));
  fEM_B1MV02RC1.error = 0;
  iEM_TERRB2.i = *((__int16*)(IntEEPROMBuffer+0x29F));
  iEM_TERRB2.error = 0;
  fplet(&fEM_B2MC02RC1.f,((float*)(IntEEPROMBuffer+0x2A1)));
  fEM_B2MC02RC1.error = 0;
  fplet(&fEM_B2MV02RC1.f,((float*)(IntEEPROMBuffer+0x2A5)));
  fEM_B2MV02RC1.error = 0;
  iEM_TERRB1.i = *((__int16*)(IntEEPROMBuffer+0x2A9));
  iEM_TERRB1.error = 0;
  fplet(&fEM_A2MC02RC1.f,((float*)(IntEEPROMBuffer+0x2AB)));
  fEM_A2MC02RC1.error = 0;
  fplet(&fEM_A2MV02RC1.f,((float*)(IntEEPROMBuffer+0x2AF)));
  fEM_A2MV02RC1.error = 0;
  iEM_TERIS2.i = *((__int16*)(IntEEPROMBuffer+0x2B3));
  iEM_TERIS2.error = 0;
  fplet(&fEM_B3MC02RC1.f,((float*)(IntEEPROMBuffer+0x2B5)));
  fEM_B3MC02RC1.error = 0;
  fplet(&fEM_B3MV02RC1.f,((float*)(IntEEPROMBuffer+0x2B9)));
  fEM_B3MV02RC1.error = 0;
  iEM_TERIS1.i = *((__int16*)(IntEEPROMBuffer+0x2BD));
  iEM_TERIS1.error = 0;
  fplet(&fEM_A3MC02RC1.f,((float*)(IntEEPROMBuffer+0x2BF)));
  fEM_A3MC02RC1.error = 0;
  fplet(&fEM_A3MV02RC1.f,((float*)(IntEEPROMBuffer+0x2C3)));
  fEM_A3MV02RC1.error = 0;
  iEM_TERA1IE04LDU.i = *((__int16*)(IntEEPROMBuffer+0x2C7));
  iEM_TERA1IE04LDU.error = 0;
  iEM_TERA1IE03LDU.i = *((__int16*)(IntEEPROMBuffer+0x2C9));
  iEM_TERA1IE03LDU.error = 0;
  fplet(&fEM_A1MC01RC1.f,((float*)(IntEEPROMBuffer+0x2CB)));
  fEM_A1MC01RC1.error = 0;
  iEM_TERB1IE03LDU.i = *((__int16*)(IntEEPROMBuffer+0x2CF));
  iEM_TERB1IE03LDU.error = 0;
  iEM_TERB1IE04LDU.i = *((__int16*)(IntEEPROMBuffer+0x2D1));
  iEM_TERB1IE04LDU.error = 0;
  fplet(&fEM_B1MC01RC1.f,((float*)(IntEEPROMBuffer+0x2D3)));
  fEM_B1MC01RC1.error = 0;
  fplet(&fEM_B1MV01RC1.f,((float*)(IntEEPROMBuffer+0x2D7)));
  fEM_B1MV01RC1.error = 0;
  fplet(&fEM_B2MC01RC1.f,((float*)(IntEEPROMBuffer+0x2DB)));
  fEM_B2MC01RC1.error = 0;
  fplet(&fEM_B2MV01RC1.f,((float*)(IntEEPROMBuffer+0x2DF)));
  fEM_B2MV01RC1.error = 0;
  fplet(&fEM_A3MC01RC1.f,((float*)(IntEEPROMBuffer+0x2E3)));
  fEM_A3MC01RC1.error = 0;
  fplet(&fEM_A3MV01RC1.f,((float*)(IntEEPROMBuffer+0x2E7)));
  fEM_A3MV01RC1.error = 0;
  fplet(&fEM_B3MC01RC1.f,((float*)(IntEEPROMBuffer+0x2EB)));
  fEM_B3MC01RC1.error = 0;
  fplet(&fEM_B3MV01RC1.f,((float*)(IntEEPROMBuffer+0x2EF)));
  fEM_B3MV01RC1.error = 0;
  iEM_TERA2SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x2F3));
  iEM_TERA2SS21LIM.error = 0;
  iEM_TERA2SS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x2F5));
  iEM_TERA2SS12LIM.error = 0;
  iEM_TERR6SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x2F7));
  iEM_TERR6SS21LIM.error = 0;
  iEM_TERA2VP82LIM.i = *((__int16*)(IntEEPROMBuffer+0x2F9));
  iEM_TERA2VP82LIM.error = 0;
  iEM_TERA2SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x2FB));
  iEM_TERA2SS11LIM.error = 0;
  iEM_TERB3SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x2FD));
  iEM_TERB3SS21LIM.error = 0;
  iEM_TERA0MT01RIM.i = *((__int16*)(IntEEPROMBuffer+0x2FF));
  iEM_TERA0MT01RIM.error = 0;
  iEM_TERB0MT01RIM.i = *((__int16*)(IntEEPROMBuffer+0x301));
  iEM_TERB0MT01RIM.error = 0;
  iEM_TERA2SP01RIM.i = *((__int16*)(IntEEPROMBuffer+0x303));
  iEM_TERA2SP01RIM.error = 0;
  iEM_TERB2SP01RIM.i = *((__int16*)(IntEEPROMBuffer+0x305));
  iEM_TERB2SP01RIM.error = 0;
  iEM_TERB3SP02RIM.i = *((__int16*)(IntEEPROMBuffer+0x307));
  iEM_TERB3SP02RIM.error = 0;
  iEM_TERA3SC01RIM.i = *((__int16*)(IntEEPROMBuffer+0x309));
  iEM_TERA3SC01RIM.error = 0;
  iEM_TERA3VP81LIM.i = *((__int16*)(IntEEPROMBuffer+0x30B));
  iEM_TERA3VP81LIM.error = 0;
  iEM_TERA2SC01RIM.i = *((__int16*)(IntEEPROMBuffer+0x30D));
  iEM_TERA2SC01RIM.error = 0;
  iEM_TERA2SS33LIM.i = *((__int16*)(IntEEPROMBuffer+0x30F));
  iEM_TERA2SS33LIM.error = 0;
  iEM_TERA3SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x311));
  iEM_TERA3SS21LIM.error = 0;
  iEM_TERA3SS33LIM.i = *((__int16*)(IntEEPROMBuffer+0x313));
  iEM_TERA3SS33LIM.error = 0;
  iEM_TERA3SS31LIM.i = *((__int16*)(IntEEPROMBuffer+0x315));
  iEM_TERA3SS31LIM.error = 0;
  iEM_TERB3SS31LIM.i = *((__int16*)(IntEEPROMBuffer+0x317));
  iEM_TERB3SS31LIM.error = 0;
  iEM_TERB3SS33LIM.i = *((__int16*)(IntEEPROMBuffer+0x319));
  iEM_TERB3SS33LIM.error = 0;
  iEM_TERB3SC01RIM.i = *((__int16*)(IntEEPROMBuffer+0x31B));
  iEM_TERB3SC01RIM.error = 0;
  iEM_TERA3SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x31D));
  iEM_TERA3SS11LIM.error = 0;
  iEM_TERB3SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x31F));
  iEM_TERB3SS11LIM.error = 0;
  iEM_TERR6IS64LIM.i = *((__int16*)(IntEEPROMBuffer+0x321));
  iEM_TERR6IS64LIM.error = 0;
  iEM_TERB3SS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x323));
  iEM_TERB3SS22LIM.error = 0;
  iEM_TERA3SS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x325));
  iEM_TERA3SS22LIM.error = 0;
  iEM_TERA3SP02RIM.i = *((__int16*)(IntEEPROMBuffer+0x327));
  iEM_TERA3SP02RIM.error = 0;
  iEM_TERR6IS62LIM.i = *((__int16*)(IntEEPROMBuffer+0x329));
  iEM_TERR6IS62LIM.error = 0;
  iEM_TERR6IS66LIM.i = *((__int16*)(IntEEPROMBuffer+0x32B));
  iEM_TERR6IS66LIM.error = 0;
  iEM_TERR6IS67LIM.i = *((__int16*)(IntEEPROMBuffer+0x32D));
  iEM_TERR6IS67LIM.error = 0;
  iEM_TERA0VP81LIM.i = *((__int16*)(IntEEPROMBuffer+0x32F));
  iEM_TERA0VP81LIM.error = 0;
  iEM_TERB0VP81LIM.i = *((__int16*)(IntEEPROMBuffer+0x331));
  iEM_TERB0VP81LIM.error = 0;
  iEM_TERR0VP81LIM.i = *((__int16*)(IntEEPROMBuffer+0x333));
  iEM_TERR0VP81LIM.error = 0;
  iEM_TERR6IS68LIM.i = *((__int16*)(IntEEPROMBuffer+0x335));
  iEM_TERR6IS68LIM.error = 0;
  iEM_TERR7SI74RIM.i = *((__int16*)(IntEEPROMBuffer+0x337));
  iEM_TERR7SI74RIM.error = 0;
  iEM_TERA5SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x339));
  iEM_TERA5SS21LIM.error = 0;
  iEM_TERB5SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x33B));
  iEM_TERB5SS11LIM.error = 0;
  iEM_TERA5SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x33D));
  iEM_TERA5SS11LIM.error = 0;
  iEM_TERA9SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x33F));
  iEM_TERA9SS11LIM.error = 0;
  iEM_TERB2SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x341));
  iEM_TERB2SS11LIM.error = 0;
  iEM_TERB2SS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x343));
  iEM_TERB2SS12LIM.error = 0;
  iEM_TERB2SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x345));
  iEM_TERB2SS21LIM.error = 0;
  iEM_TERR3SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x347));
  iEM_TERR3SS11LIM.error = 0;
  iEM_TERB2SC01RIM.i = *((__int16*)(IntEEPROMBuffer+0x349));
  iEM_TERB2SC01RIM.error = 0;
  iEM_TERR3SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x34B));
  iEM_TERR3SS21LIM.error = 0;
  iEM_TERR5SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x34D));
  iEM_TERR5SS11LIM.error = 0;
  iEM_TERA4SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x34F));
  iEM_TERA4SS11LIM.error = 0;
  iEM_TERR1SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x351));
  iEM_TERR1SS11LIM.error = 0;
  iEM_TERR1SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x353));
  iEM_TERR1SS21LIM.error = 0;
  iEM_TERR2SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x355));
  iEM_TERR2SS11LIM.error = 0;
  iEM_TERR2SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x357));
  iEM_TERR2SS21LIM.error = 0;
  iEM_TERA4VP82LIM.i = *((__int16*)(IntEEPROMBuffer+0x359));
  iEM_TERA4VP82LIM.error = 0;
  iEM_TERB4SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x35B));
  iEM_TERB4SS21LIM.error = 0;
  iEM_TERR5SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x35D));
  iEM_TERR5SS21LIM.error = 0;
  iEM_TERB6SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x35F));
  iEM_TERB6SS21LIM.error = 0;
  iEM_TERB4SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x361));
  iEM_TERB4SS11LIM.error = 0;
  iEM_TERA4SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x363));
  iEM_TERA4SS21LIM.error = 0;
  iEM_TERA6MS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x365));
  iEM_TERA6MS11LIM.error = 0;
  iEM_TERA6SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x367));
  iEM_TERA6SS21LIM.error = 0;
  iEM_TERB6SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x369));
  iEM_TERB6SS11LIM.error = 0;
  iEM_TERR4SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x36B));
  iEM_TERR4SS11LIM.error = 0;
  iEM_TERR4MS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x36D));
  iEM_TERR4MS21LIM.error = 0;
  iEM_TERR4SS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x36F));
  iEM_TERR4SS12LIM.error = 0;
  iEM_TERR4SS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x371));
  iEM_TERR4SS22LIM.error = 0;
  iEM_TERR8SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x373));
  iEM_TERR8SS11LIM.error = 0;
  iEM_TERB8SC01RIM.i = *((__int16*)(IntEEPROMBuffer+0x375));
  iEM_TERB8SC01RIM.error = 0;
  iEM_TERA8SC01RIM.i = *((__int16*)(IntEEPROMBuffer+0x377));
  iEM_TERA8SC01RIM.error = 0;
  iEM_TERB8SS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x379));
  iEM_TERB8SS12LIM.error = 0;
  iEM_TERA8SS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x37B));
  iEM_TERA8SS12LIM.error = 0;
  iEM_TERB8SS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x37D));
  iEM_TERB8SS22LIM.error = 0;
  iEM_TERA8SS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x37F));
  iEM_TERA8SS22LIM.error = 0;
  iEM_TERA9SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x381));
  iEM_TERA9SS21LIM.error = 0;
  iEM_TERB9SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x383));
  iEM_TERB9SS21LIM.error = 0;
  iEM_TERB9SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x385));
  iEM_TERB9SS11LIM.error = 0;
  iEM_TERB5SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x387));
  iEM_TERB5SS21LIM.error = 0;
  iEM_TERA1SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x389));
  iEM_TERA1SS21LIM.error = 0;
  iEM_TERA1SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x38B));
  iEM_TERA1SS11LIM.error = 0;
  iEM_TERA1SC01RIM.i = *((__int16*)(IntEEPROMBuffer+0x38D));
  iEM_TERA1SC01RIM.error = 0;
  iEM_TERA1SS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x38F));
  iEM_TERA1SS12LIM.error = 0;
  iEM_TERB1SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x391));
  iEM_TERB1SS21LIM.error = 0;
  iEM_TERB1SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x393));
  iEM_TERB1SS11LIM.error = 0;
  iEM_TERB1MC01RIM.i = *((__int16*)(IntEEPROMBuffer+0x395));
  iEM_TERB1MC01RIM.error = 0;
  iEM_TERB1SS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x397));
  iEM_TERB1SS12LIM.error = 0;
  iEM_TERTLG.i = *((__int16*)(IntEEPROMBuffer+0x399));
  iEM_TERTLG.error = 0;
  fplet(&fEM_R4MC01RC1.f,((float*)(IntEEPROMBuffer+0x39B)));
  fEM_R4MC01RC1.error = 0;
  fplet(&fEM_R4MV01RC1.f,((float*)(IntEEPROMBuffer+0x39F)));
  fEM_R4MV01RC1.error = 0;
  iEM_TERMAZ2.i = *((__int16*)(IntEEPROMBuffer+0x3A3));
  iEM_TERMAZ2.error = 0;
  fplet(&fEM_B8MC01RC1.f,((float*)(IntEEPROMBuffer+0x3A5)));
  fEM_B8MC01RC1.error = 0;
  fplet(&fEM_B8MV01RC1.f,((float*)(IntEEPROMBuffer+0x3A9)));
  fEM_B8MV01RC1.error = 0;
  iEM_TERDS2.i = *((__int16*)(IntEEPROMBuffer+0x3AD));
  iEM_TERDS2.error = 0;
  fplet(&fEM_A8MC01RC1.f,((float*)(IntEEPROMBuffer+0x3AF)));
  fEM_A8MC01RC1.error = 0;
  fplet(&fEM_A8MV01RC1.f,((float*)(IntEEPROMBuffer+0x3B3)));
  fEM_A8MV01RC1.error = 0;
  iEM_TERBZ1.i = *((__int16*)(IntEEPROMBuffer+0x3B7));
  iEM_TERBZ1.error = 0;
  fplet(&fEM_A6MC01RC1.f,((float*)(IntEEPROMBuffer+0x3B9)));
  fEM_A6MC01RC1.error = 0;
  fplet(&fEM_A6MV01RC1.f,((float*)(IntEEPROMBuffer+0x3BD)));
  fEM_A6MV01RC1.error = 0;
  iEM_TERBZ2.i = *((__int16*)(IntEEPROMBuffer+0x3C1));
  iEM_TERBZ2.error = 0;
  fplet(&fEM_B6MC01RC1.f,((float*)(IntEEPROMBuffer+0x3C3)));
  fEM_B6MC01RC1.error = 0;
  fplet(&fEM_B6MV01RC1.f,((float*)(IntEEPROMBuffer+0x3C7)));
  fEM_B6MV01RC1.error = 0;
  lEM_R3AD10LC1.b = *((uspaint8*)(IntEEPROMBuffer+0x3CB));
  lEM_R3AD10LC1.error = 0;
  lEM_R3AD20LC1.b = *((uspaint8*)(IntEEPROMBuffer+0x3CC));
  lEM_R3AD20LC1.error = 0;
  lEM_R6AD10LC1.b = *((uspaint8*)(IntEEPROMBuffer+0x3CD));
  lEM_R6AD10LC1.error = 0;
  lEM_R5AD10LC1.b = *((uspaint8*)(IntEEPROMBuffer+0x3CE));
  lEM_R5AD10LC1.error = 0;
  lEM_R5AD20LC1.b = *((uspaint8*)(IntEEPROMBuffer+0x3CF));
  lEM_R5AD20LC1.error = 0;
  iEM_TERMDZ2.i = *((__int16*)(IntEEPROMBuffer+0x3D0));
  iEM_TERMDZ2.error = 0;
  fplet(&fEM_R2MC01RC1.f,((float*)(IntEEPROMBuffer+0x3D2)));
  fEM_R2MC01RC1.error = 0;
  fplet(&fEM_R2MV01RC1.f,((float*)(IntEEPROMBuffer+0x3D6)));
  fEM_R2MV01RC1.error = 0;
  iEM_TERMDZ1.i = *((__int16*)(IntEEPROMBuffer+0x3DA));
  iEM_TERMDZ1.error = 0;
  fplet(&fEM_R1MC01RC1.f,((float*)(IntEEPROMBuffer+0x3DC)));
  fEM_R1MC01RC1.error = 0;
  fplet(&fEM_R1MV01RC1.f,((float*)(IntEEPROMBuffer+0x3E0)));
  fEM_R1MV01RC1.error = 0;
  iEM_TERNL1.i = *((__int16*)(IntEEPROMBuffer+0x3E4));
  iEM_TERNL1.error = 0;
  fplet(&fEM_A5MC01RC1.f,((float*)(IntEEPROMBuffer+0x3E6)));
  fEM_A5MC01RC1.error = 0;
  fplet(&fEM_A5MV01RC1.f,((float*)(IntEEPROMBuffer+0x3EA)));
  fEM_A5MV01RC1.error = 0;
  iEM_TERNL2.i = *((__int16*)(IntEEPROMBuffer+0x3EE));
  iEM_TERNL2.error = 0;
  fplet(&fEM_B5MC01RC1.f,((float*)(IntEEPROMBuffer+0x3F0)));
  fEM_B5MC01RC1.error = 0;
  fplet(&fEM_B5MV01RC1.f,((float*)(IntEEPROMBuffer+0x3F4)));
  fEM_B5MV01RC1.error = 0;
  lEM_R8AD10LC1.b = *((uspaint8*)(IntEEPROMBuffer+0x3F8));
  lEM_R8AD10LC1.error = 0;
  fplet(&fEM_A1UC08RIM.f,((float*)(IntEEPROMBuffer+0x3F9)));
  fEM_A1UC08RIM.error = 0;
  fplet(&fEM_A2UC08RIM.f,((float*)(IntEEPROMBuffer+0x3FD)));
  fEM_A2UC08RIM.error = 0;
  fplet(&fEM_A3UC08RIM.f,((float*)(IntEEPROMBuffer+0x401)));
  fEM_A3UC08RIM.error = 0;
  iEM_TERB2SS33LIM.i = *((__int16*)(IntEEPROMBuffer+0x405));
  iEM_TERB2SS33LIM.error = 0;
  iEM_TERA1VP81LIM.i = *((__int16*)(IntEEPROMBuffer+0x407));
  iEM_TERA1VP81LIM.error = 0;
  iEM_TERB1VP81LIM.i = *((__int16*)(IntEEPROMBuffer+0x409));
  iEM_TERB1VP81LIM.error = 0;
  fplet(&fEM_A0UT03RSP.f,((float*)(IntEEPROMBuffer+0x40B)));
  fEM_A0UT03RSP.error = 0;
  fplet(&fEM_A0UR01RSP.f,((float*)(IntEEPROMBuffer+0x40F)));
  fEM_A0UR01RSP.error = 0;
  fplet(&fEM_A0UR02RSP.f,((float*)(IntEEPROMBuffer+0x413)));
  fEM_A0UR02RSP.error = 0;
  fplet(&fEM_B0UT03RSP.f,((float*)(IntEEPROMBuffer+0x417)));
  fEM_B0UT03RSP.error = 0;
  fplet(&fEM_A1MC01RSP.f,((float*)(IntEEPROMBuffer+0x41B)));
  fEM_A1MC01RSP.error = 0;
  fplet(&fEM_A1MC02RSP.f,((float*)(IntEEPROMBuffer+0x41F)));
  fEM_A1MC02RSP.error = 0;
  fplet(&fEM_A1MV01RSP.f,((float*)(IntEEPROMBuffer+0x423)));
  fEM_A1MV01RSP.error = 0;
  fplet(&fEM_A1MV02RSP.f,((float*)(IntEEPROMBuffer+0x427)));
  fEM_A1MV02RSP.error = 0;
  fplet(&fEM_B1MC01RSP.f,((float*)(IntEEPROMBuffer+0x42B)));
  fEM_B1MC01RSP.error = 0;
  fplet(&fEM_B1MV01RSP.f,((float*)(IntEEPROMBuffer+0x42F)));
  fEM_B1MV01RSP.error = 0;
  fplet(&fEM_B1MC02RSP.f,((float*)(IntEEPROMBuffer+0x433)));
  fEM_B1MC02RSP.error = 0;
  fplet(&fEM_B1MV02RSP.f,((float*)(IntEEPROMBuffer+0x437)));
  fEM_B1MV02RSP.error = 0;
  fplet(&fEM_A2MC01RC1.f,((float*)(IntEEPROMBuffer+0x43B)));
  fEM_A2MC01RC1.error = 0;
  fplet(&fEM_A2MV01RC1.f,((float*)(IntEEPROMBuffer+0x43F)));
  fEM_A2MV01RC1.error = 0;
  fplet(&fEM_A2MC01RSP.f,((float*)(IntEEPROMBuffer+0x443)));
  fEM_A2MC01RSP.error = 0;
  fplet(&fEM_A2MV01RSP.f,((float*)(IntEEPROMBuffer+0x447)));
  fEM_A2MV01RSP.error = 0;
  fplet(&fEM_A2MC02RSP.f,((float*)(IntEEPROMBuffer+0x44B)));
  fEM_A2MC02RSP.error = 0;
  fplet(&fEM_A2MV02RSP.f,((float*)(IntEEPROMBuffer+0x44F)));
  fEM_A2MV02RSP.error = 0;
  fplet(&fEM_B2MC01RSP.f,((float*)(IntEEPROMBuffer+0x453)));
  fEM_B2MC01RSP.error = 0;
  fplet(&fEM_B2MV01RSP.f,((float*)(IntEEPROMBuffer+0x457)));
  fEM_B2MV01RSP.error = 0;
  fplet(&fEM_B2MC02RSP.f,((float*)(IntEEPROMBuffer+0x45B)));
  fEM_B2MC02RSP.error = 0;
  fplet(&fEM_B2MV02RSP.f,((float*)(IntEEPROMBuffer+0x45F)));
  fEM_B2MV02RSP.error = 0;
  fplet(&fEM_A3MC01RSP.f,((float*)(IntEEPROMBuffer+0x463)));
  fEM_A3MC01RSP.error = 0;
  fplet(&fEM_A3MV01RSP.f,((float*)(IntEEPROMBuffer+0x467)));
  fEM_A3MV01RSP.error = 0;
  fplet(&fEM_A3MC02RSP.f,((float*)(IntEEPROMBuffer+0x46B)));
  fEM_A3MC02RSP.error = 0;
  fplet(&fEM_A3MV02RSP.f,((float*)(IntEEPROMBuffer+0x46F)));
  fEM_A3MV02RSP.error = 0;
  fplet(&fEM_B3MC01RSP.f,((float*)(IntEEPROMBuffer+0x473)));
  fEM_B3MC01RSP.error = 0;
  fplet(&fEM_B3MV01RSP.f,((float*)(IntEEPROMBuffer+0x477)));
  fEM_B3MV01RSP.error = 0;
  fplet(&fEM_B3MC02RSP.f,((float*)(IntEEPROMBuffer+0x47B)));
  fEM_B3MC02RSP.error = 0;
  fplet(&fEM_B3MV02RSP.f,((float*)(IntEEPROMBuffer+0x47F)));
  fEM_B3MV02RSP.error = 0;
  fplet(&fEM_B8MC01RSP.f,((float*)(IntEEPROMBuffer+0x483)));
  fEM_B8MC01RSP.error = 0;
  fplet(&fEM_B8MV01RSP.f,((float*)(IntEEPROMBuffer+0x487)));
  fEM_B8MV01RSP.error = 0;
  fplet(&fEM_A8MC01RSP.f,((float*)(IntEEPROMBuffer+0x48B)));
  fEM_A8MC01RSP.error = 0;
  fplet(&fEM_A8MV01RSP.f,((float*)(IntEEPROMBuffer+0x48F)));
  fEM_A8MV01RSP.error = 0;
  fplet(&fEM_A6MC01RSP.f,((float*)(IntEEPROMBuffer+0x493)));
  fEM_A6MC01RSP.error = 0;
  fplet(&fEM_A6MV01RSP.f,((float*)(IntEEPROMBuffer+0x497)));
  fEM_A6MV01RSP.error = 0;
  fplet(&fEM_B6MC01RSP.f,((float*)(IntEEPROMBuffer+0x49B)));
  fEM_B6MC01RSP.error = 0;
  fplet(&fEM_B6MV01RSP.f,((float*)(IntEEPROMBuffer+0x49F)));
  fEM_B6MV01RSP.error = 0;
  fplet(&fEM_R3UC01RSP.f,((float*)(IntEEPROMBuffer+0x4A3)));
  fEM_R3UC01RSP.error = 0;
  fplet(&fEM_R3UV01RSP.f,((float*)(IntEEPROMBuffer+0x4A7)));
  fEM_R3UV01RSP.error = 0;
  fplet(&fEM_R5UC01RSP.f,((float*)(IntEEPROMBuffer+0x4AB)));
  fEM_R5UC01RSP.error = 0;
  fplet(&fEM_R5UV01RSP.f,((float*)(IntEEPROMBuffer+0x4AF)));
  fEM_R5UV01RSP.error = 0;
  fplet(&fEM_R6UC01RSP.f,((float*)(IntEEPROMBuffer+0x4B3)));
  fEM_R6UC01RSP.error = 0;
  fplet(&fEM_R6UV01RSP.f,((float*)(IntEEPROMBuffer+0x4B7)));
  fEM_R6UV01RSP.error = 0;
  fplet(&fEM_R2MC01RSP.f,((float*)(IntEEPROMBuffer+0x4BB)));
  fEM_R2MC01RSP.error = 0;
  fplet(&fEM_R2MV01RSP.f,((float*)(IntEEPROMBuffer+0x4BF)));
  fEM_R2MV01RSP.error = 0;
  fplet(&fEM_R1MC01RSP.f,((float*)(IntEEPROMBuffer+0x4C3)));
  fEM_R1MC01RSP.error = 0;
  fplet(&fEM_R1MV01RSP.f,((float*)(IntEEPROMBuffer+0x4C7)));
  fEM_R1MV01RSP.error = 0;
  fplet(&fEM_A5MC01RSP.f,((float*)(IntEEPROMBuffer+0x4CB)));
  fEM_A5MC01RSP.error = 0;
  fplet(&fEM_A5MV01RSP.f,((float*)(IntEEPROMBuffer+0x4CF)));
  fEM_A5MV01RSP.error = 0;
  fplet(&fEM_B5MC01RSP.f,((float*)(IntEEPROMBuffer+0x4D3)));
  fEM_B5MC01RSP.error = 0;
  fplet(&fEM_B5MV01RSP.f,((float*)(IntEEPROMBuffer+0x4D7)));
  fEM_B5MV01RSP.error = 0;
  fplet(&fEM_A9MC01RSP.f,((float*)(IntEEPROMBuffer+0x4DB)));
  fEM_A9MC01RSP.error = 0;
  fplet(&fEM_A9MV01RSP.f,((float*)(IntEEPROMBuffer+0x4DF)));
  fEM_A9MV01RSP.error = 0;
  fplet(&fEM_B9MC01RSP.f,((float*)(IntEEPROMBuffer+0x4E3)));
  fEM_B9MC01RSP.error = 0;
  fplet(&fEM_B9MV01RSP.f,((float*)(IntEEPROMBuffer+0x4E7)));
  fEM_B9MV01RSP.error = 0;
  fplet(&fEM_A4MC01RSP.f,((float*)(IntEEPROMBuffer+0x4EB)));
  fEM_A4MC01RSP.error = 0;
  fplet(&fEM_A4MV01RSP.f,((float*)(IntEEPROMBuffer+0x4EF)));
  fEM_A4MV01RSP.error = 0;
  fplet(&fEM_B4MC01RSP.f,((float*)(IntEEPROMBuffer+0x4F3)));
  fEM_B4MC01RSP.error = 0;
  fplet(&fEM_B4MV01RSP.f,((float*)(IntEEPROMBuffer+0x4F7)));
  fEM_B4MV01RSP.error = 0;
  fplet(&fEM_R4MC01RSP.f,((float*)(IntEEPROMBuffer+0x4FB)));
  fEM_R4MC01RSP.error = 0;
  fplet(&fEM_R4MV01RSP.f,((float*)(IntEEPROMBuffer+0x4FF)));
  fEM_R4MV01RSP.error = 0;
  fplet(&fEM_A1MV01RC1.f,((float*)(IntEEPROMBuffer+0x503)));
  fEM_A1MV01RC1.error = 0;
  iEM_TERB7MS31LIM.i = *((__int16*)(IntEEPROMBuffer+0x507));
  iEM_TERB7MS31LIM.error = 0;
  iEM_TERA7MS31LIM.i = *((__int16*)(IntEEPROMBuffer+0x509));
  iEM_TERA7MS31LIM.error = 0;
  fplet(&fEM_R7UY00RSS.f,((float*)(IntEEPROMBuffer+0x50B)));
  fEM_R7UY00RSS.error = 0;
  iEM_TERA6VS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x50F));
  iEM_TERA6VS12LIM.error = 0;
  iEM_TERA6VS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x511));
  iEM_TERA6VS22LIM.error = 0;
  iEM_TERB6VS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x513));
  iEM_TERB6VS12LIM.error = 0;
  iEM_TERB6VS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x515));
  iEM_TERB6VS22LIM.error = 0;
  iEM_TERA5VS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x517));
  iEM_TERA5VS22LIM.error = 0;
  iEM_TERA5VS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x519));
  iEM_TERA5VS12LIM.error = 0;
  iEM_TERB5VS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x51B));
  iEM_TERB5VS12LIM.error = 0;
  iEM_TERB5VS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x51D));
  iEM_TERB5VS22LIM.error = 0;
  iEM_TERR1VS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x51F));
  iEM_TERR1VS12LIM.error = 0;
  iEM_TERR1VS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x521));
  iEM_TERR1VS22LIM.error = 0;
  iEM_TERR2VS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x523));
  iEM_TERR2VS12LIM.error = 0;
  iEM_TERR2VS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x525));
  iEM_TERR2VS22LIM.error = 0;
  iEM_TERR4VS12LDU.i = *((__int16*)(IntEEPROMBuffer+0x527));
  iEM_TERR4VS12LDU.error = 0;
  iEM_TERR4VS22LDU.i = *((__int16*)(IntEEPROMBuffer+0x529));
  iEM_TERR4VS22LDU.error = 0;
  fplet(&fEM_R4UC23RIM.f,((float*)(IntEEPROMBuffer+0x52B)));
  fEM_R4UC23RIM.error = 0;
  fplet(&fEM_A0UX13RSS.f,((float*)(IntEEPROMBuffer+0x52F)));
  fEM_A0UX13RSS.error = 0;
  fplet(&fEM_A0UX14RSS.f,((float*)(IntEEPROMBuffer+0x533)));
  fEM_A0UX14RSS.error = 0;
  fplet(&fEM_A0UX15RSS.f,((float*)(IntEEPROMBuffer+0x537)));
  fEM_A0UX15RSS.error = 0;
  fplet(&fEM_R7UX13RSS.f,((float*)(IntEEPROMBuffer+0x53B)));
  fEM_R7UX13RSS.error = 0;
  fplet(&fEM_R7UX14RSS.f,((float*)(IntEEPROMBuffer+0x53F)));
  fEM_R7UX14RSS.error = 0;
  fplet(&fEM_R7UX15RSS.f,((float*)(IntEEPROMBuffer+0x543)));
  fEM_R7UX15RSS.error = 0;
  fplet(&fEM_R7UY13RSS.f,((float*)(IntEEPROMBuffer+0x547)));
  fEM_R7UY13RSS.error = 0;
  fplet(&fEM_R7UY14RSS.f,((float*)(IntEEPROMBuffer+0x54B)));
  fEM_R7UY14RSS.error = 0;
  fplet(&fEM_R7UY15RSS.f,((float*)(IntEEPROMBuffer+0x54F)));
  fEM_R7UY15RSS.error = 0;
  fplet(&fEM_R7UX16RSS.f,((float*)(IntEEPROMBuffer+0x553)));
  fEM_R7UX16RSS.error = 0;
}
#endif
}

#ifndef SIMUL_MODE
unsigned int EndIntEEPROMAddress = 1367;
#endif

void reInit_Signals(void)
{
  S_to3val_944_1.Ter = &signal_TerR0IN06FRP;
  S_zpfs_617_1.x = &signal_R0AD14LDU;
  S_zpfs_605_1.x = &signal_R0AD16LDU;
  S_or2_919_1.x1 = &signal_R0EE04LZ1;
  S_or2_919_1.x2 = &signal_R0EE04LZ2;
  S_or2_910_1.x1 = &signal_R0EE03LZ1;
  S_or2_910_1.x2 = &signal_R0EE03LZ2;
  S_or2_903_1.x1 = &signal_R0EE02LZ1;
  S_or2_903_1.x2 = &signal_R0EE02LZ2;
  S_or2_896_1.x1 = &signal_R0EE01LZ1;
  S_or2_896_1.x2 = &signal_R0EE01LZ2;
  S_twobool_202_1.S = &signal_B1AD21LDU;
  S_twobool_218_1.S = &signal_B1AD11LDU;
  S_twobool_41_1.S = &signal_A1AD21LDU;
  S_twobool_56_1.S = &signal_A1AD11LDU;
  S_twobool_676_1.S = &signal_R0MW13LP2;
  S_twobool_660_1.S = &signal_R0MW13LP2;
  S_twobool_640_1.S = &signal_R0MW13LP2;
  S_twobool_659_1.S = &signal_R0MW13LP2;
  S_twobool_639_1.S = &signal_R0MW13LP2;
  S_noto_494_1.x = &signal_B3AD34LDU;
  S_noto_492_1.x = &signal_A3AD34LDU;
  S_ovb1_191_1.x = &signal_R8AD21LDU;
  S_ovb1_30_1.x = &signal_R8AD21LDU;
  S_noto_592_1.x = &signal_A4AD10LDU;
  S_asmot_596_1.RA1 = &signal_A4AD10LDU;
  S_noto_590_1.x = &signal_B4AD10LDU;
  S_asmot_595_1.RA1 = &signal_B4AD10LDU;
  S_noto_581_1.x = &signal_A9AD10LDU;
  S_asmot_583_1.RA1 = &signal_A9AD10LDU;
  S_noto_580_1.x = &signal_B9AD10LDU;
  S_asmot_582_1.RA1 = &signal_B9AD10LDU;
  S_noto_248_1.x = &signal_C2MD31LP1;
  S_noto_210_1.x = &signal_C1MD31LP2;
  S_noto_209_1.x = &signal_C1MD31LP1;
  S_noto_46_1.x = &signal_C1MD31LP2;
  S_noto_45_1.x = &signal_C1MD31LP1;
  S_noto_84_1.x = &signal_C2MD31LP1;
  S_asmot_570_1.RA0 = &signal_B5AD10LDU;
  S_asmot_570_1.RA1 = &signal_B5AD20LDU;
  S_asmot_556_1.RA0 = &signal_A5AD10LDU;
  S_asmot_556_1.RA1 = &signal_A5AD20LDU;
  S_asmot_447_1.RA0 = &signal_R2AD10LDU;
  S_asmot_447_1.RA1 = &signal_R2AD20LDU;
  S_asmot_433_1.RA0 = &signal_R1AD10LDU;
  S_asmot_433_1.RA1 = &signal_R1AD20LDU;
  S_asmot_484_1.RA0 = &signal_B6AD10LDU;
  S_asmot_484_1.RA1 = &signal_B6AD20LDU;
  S_asmot_385_1.RA0 = &signal_A6AD10LDU;
  S_asmot_385_1.RA1 = &signal_A6AD20LDU;
  S_asmot_370_1.RA0 = &signal_A8AD20LDU;
  S_asmot_370_1.RA1 = &signal_A8AD10LDU;
  S_asmot_354_1.RA0 = &signal_B8AD20LDU;
  S_asmot_354_1.RA1 = &signal_B8AD10LDU;
  S_asmot_882_1.RA0 = &signal_R4AD10LDU;
  S_asmot_882_1.RA1 = &signal_R4AD20LDU;
  S_azbars_176_1.BlowOut = &signal_B7AP31LDU;
  S_orrsim_290_1.RA0 = &signal_B3AD11LDU;
  S_orrsim_290_1.RA1 = &signal_B3AD21LDU;
  S_orrsim_290_1.RA2 = &signal_B3AD02LDU;
  S_orrsim_290_1.RA3 = &signal_B3AD01LDU;
  S_orrsim_290_1.RA4 = &signal_B3AD03LDU;
  S_orrsim_290_1.RA5 = &signal_B3AD04LDU;
  S_orrsim_290_1.RB3 = &signal_B3AD05LDU;
  S_orrsim_290_1.Klz = &signal_B3AD33LDU;
  S_orrsim_126_1.RA0 = &signal_A3AD11LDU;
  S_orrsim_126_1.RA1 = &signal_A3AD21LDU;
  S_orrsim_126_1.RA2 = &signal_A3AD02LDU;
  S_orrsim_126_1.RA3 = &signal_A3AD01LDU;
  S_orrsim_126_1.RA4 = &signal_A3AD03LDU;
  S_orrsim_126_1.RA5 = &signal_A3AD04LDU;
  S_orrsim_126_1.RB3 = &signal_A3AD05LDU;
  S_orrsim_126_1.Klz = &signal_A3AD33LDU;
  S_orrsim_258_1.RA0 = &signal_B2AD11LDU;
  S_orrsim_258_1.RA1 = &signal_B2AD21LDU;
  S_orrsim_258_1.RA2 = &signal_B2AD02LDU;
  S_orrsim_258_1.RA3 = &signal_B2AD01LDU;
  S_orrsim_258_1.RA4 = &signal_B2AD03LDU;
  S_orrsim_258_1.RA5 = &signal_B2AD04LDU;
  S_orrsim_258_1.RB3 = &signal_B2AD05LDU;
  S_orrsim_258_1.Klz = &signal_B2AD33LDU;
  S_orrsim_94_1.RA0 = &signal_A2AD11LDU;
  S_orrsim_94_1.RA1 = &signal_A2AD21LDU;
  S_orrsim_94_1.RA2 = &signal_A2AD02LDU;
  S_orrsim_94_1.RA3 = &signal_A2AD01LDU;
  S_orrsim_94_1.RA4 = &signal_A2AD03LDU;
  S_orrsim_94_1.RA5 = &signal_A2AD04LDU;
  S_orrsim_94_1.RB3 = &signal_A2AD05LDU;
  S_orrsim_94_1.Klz = &signal_A2AD33LDU;
  S_orrsim_223_1.RA0 = &signal_B1AD11LDU;
  S_orrsim_223_1.RA1 = &signal_B1AD21LDU;
  S_orrsim_223_1.RA2 = &signal_B1AD02LDU;
  S_orrsim_223_1.RA3 = &signal_B1AD01LDU;
  S_orrsim_223_1.RA4 = &signal_B1AD03LDU;
  S_orrsim_223_1.RA5 = &signal_B1AD04LDU;
  S_orrsim_223_1.RB3 = &signal_B1AD05LDU;
  S_orrsim_59_1.RA0 = &signal_A1AD11LDU;
  S_orrsim_59_1.RA1 = &signal_A1AD21LDU;
  S_orrsim_59_1.RA2 = &signal_A1AD02LDU;
  S_orrsim_59_1.RA3 = &signal_A1AD01LDU;
  S_orrsim_59_1.RA4 = &signal_A1AD03LDU;
  S_orrsim_59_1.RA5 = &signal_A1AD04LDU;
  S_orrsim_59_1.RB3 = &signal_A1AD05LDU;
  S_azbars_14_1.BlowOut = &signal_A7AP31LDU;
  array_m345_x_1[15] = &signal_R0MW13LP2;
  array_m890_x_1[1] = &signal_R0MW13LP2;
  array_m915_x_1[1] = &signal_R0MW13LP2;
  array_m908_x_1[1] = &signal_R0MW13LP2;
  array_m900_x_1[1] = &signal_R0MW13LP2;
  array_m614_x_1[1] = &signal_R0VZ71LZ1;
  array_m614_x_1[2] = &signal_R0VZ71LZ2;
  array_m892_x_1[1] = &signal_R0MW13LP2;
  array_m282_x_1[1] = &signal_B3AD31LDU;
  array_m249_x_1[0] = &signal_B2AD31LDU;
  array_m250_x_1[0] = &signal_B2AD32LDU;
  array_m212_x_1[0] = &signal_B1AD32LDU;
  array_m211_x_1[1] = &signal_B1AD31LDU;
  array_m117_x_1[0] = &signal_A3AD31LDU;
  array_m48_x_1[0] = &signal_A1AD32LDU;
  array_m47_x_1[1] = &signal_A1AD31LDU;
  array_m85_x_1[0] = &signal_A2AD31LDU;
  array_m86_x_1[0] = &signal_A2AD32LDU;
}

void InitInternalParametr(void)
{
  int i;
  S_to3val_944_1.FirstEnterFlag = &bFirstEnterFlag;
  S_vchs_870_1.Chim0 = &internal1_m870_Chim0;
  S_vchs_860_1.Chim0 = &internal1_m860_Chim0;
  S_vchs_852_1.Chim0 = &internal1_m852_Chim0;
  S_twobool_807_1.Out10 = &internal1_m807_Out10;
  S_twobool_807_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_806_1.Out10 = &internal1_m806_Out10;
  S_twobool_806_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_989_1.Out10 = &internal1_m989_Out10;
  S_twobool_989_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_988_1.Out10 = &internal1_m988_Out10;
  S_twobool_988_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_987_1.Out10 = &internal1_m987_Out10;
  S_twobool_987_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_986_1.Out10 = &internal1_m986_Out10;
  S_twobool_986_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_666_1.Out10 = &internal1_m666_Out10;
  S_twobool_666_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_665_1.Out10 = &internal1_m665_Out10;
  S_twobool_665_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_644_1.Out10 = &internal1_m644_Out10;
  S_twobool_644_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_643_1.Out10 = &internal1_m643_Out10;
  S_twobool_643_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_664_1.Out10 = &internal1_m664_Out10;
  S_twobool_664_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_663_1.Out10 = &internal1_m663_Out10;
  S_twobool_663_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_642_1.Out10 = &internal1_m642_Out10;
  S_twobool_642_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_641_1.Out10 = &internal1_m641_Out10;
  S_twobool_641_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_508_1.Out10 = &internal1_m508_Out10;
  S_twobool_508_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_524_1.Out10 = &internal1_m524_Out10;
  S_twobool_524_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_396_1.Out10 = &internal1_m396_Out10;
  S_twobool_396_1.FirstEnterFlag = &bFirstEnterFlag;
  S_rs_469_1.q0 = &internal1_m469_q0;
  S_rs_470_1.q0 = &internal1_m470_q0;
  S_rs_457_1.q0 = &internal1_m457_q0;
  S_rs_458_1.q0 = &internal1_m458_q0;
  S_zpfs_617_1.tx = &internal1_m617_tx;
  S_zpfs_617_1.y0 = &internal1_m617_y0;
  S_zpfs_605_1.tx = &internal1_m605_tx;
  S_zpfs_605_1.y0 = &internal1_m605_y0;
  S_zpfs_593_1.tx = &internal1_m593_tx;
  S_zpfs_593_1.y0 = &internal1_m593_y0;
  S_zpfs_591_1.tx = &internal1_m591_tx;
  S_zpfs_591_1.y0 = &internal1_m591_y0;
  S_twobool_202_1.Out10 = &internal1_m202_Out10;
  S_twobool_202_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_218_1.Out10 = &internal1_m218_Out10;
  S_twobool_218_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_41_1.Out10 = &internal1_m41_Out10;
  S_twobool_41_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_56_1.Out10 = &internal1_m56_Out10;
  S_twobool_56_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_960_1.Out10 = &internal1_m960_Out10;
  S_twobool_960_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_957_1.Out10 = &internal1_m957_Out10;
  S_twobool_957_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_956_1.Out10 = &internal1_m956_Out10;
  S_twobool_956_1.FirstEnterFlag = &bFirstEnterFlag;
  S_ktoenc_959_1.Xtek0 = &internal1_m959_Xtek0;
  S_ktoenc_959_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_954_1.FirstEnterFlag = &bFirstEnterFlag;
  S_ktoenc_942_1.Xtek0 = &internal1_m942_Xtek0;
  S_ktoenc_942_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_935_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_943_1.Out10 = &internal1_m943_Out10;
  S_twobool_943_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_940_1.Out10 = &internal1_m940_Out10;
  S_twobool_940_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_939_1.Out10 = &internal1_m939_Out10;
  S_twobool_939_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1027_1.Out10 = &internal1_m1027_Out10;
  S_twobool_1027_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1008_1.Out10 = &internal1_m1008_Out10;
  S_twobool_1008_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1007_1.Out10 = &internal1_m1007_Out10;
  S_twobool_1007_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1006_1.Out10 = &internal1_m1006_Out10;
  S_twobool_1006_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_828_1.Out10 = &internal1_m828_Out10;
  S_twobool_828_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_830_1.Out10 = &internal1_m830_Out10;
  S_twobool_830_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_827_1.Out10 = &internal1_m827_Out10;
  S_twobool_827_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_829_1.Out10 = &internal1_m829_Out10;
  S_twobool_829_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_803_1.Out10 = &internal1_m803_Out10;
  S_twobool_803_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_804_1.Out10 = &internal1_m804_Out10;
  S_twobool_804_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_802_1.Out10 = &internal1_m802_Out10;
  S_twobool_802_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_801_1.Out10 = &internal1_m801_Out10;
  S_twobool_801_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1022_1.Out10 = &internal1_m1022_Out10;
  S_twobool_1022_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_974_1.Out10 = &internal1_m974_Out10;
  S_twobool_974_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_973_1.Out10 = &internal1_m973_Out10;
  S_twobool_973_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_972_1.Out10 = &internal1_m972_Out10;
  S_twobool_972_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_971_1.Out10 = &internal1_m971_Out10;
  S_twobool_971_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1023_1.Out10 = &internal1_m1023_Out10;
  S_twobool_1023_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1004_1.Out10 = &internal1_m1004_Out10;
  S_twobool_1004_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_805_1.Out10 = &internal1_m805_Out10;
  S_twobool_805_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1005_1.Out10 = &internal1_m1005_Out10;
  S_twobool_1005_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1003_1.Out10 = &internal1_m1003_Out10;
  S_twobool_1003_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1024_1.Out10 = &internal1_m1024_Out10;
  S_twobool_1024_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1002_1.Out10 = &internal1_m1002_Out10;
  S_twobool_1002_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_985_1.Out10 = &internal1_m985_Out10;
  S_twobool_985_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_970_1.Out10 = &internal1_m970_Out10;
  S_twobool_970_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_525_1.Out10 = &internal1_m525_Out10;
  S_twobool_525_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_529_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_528_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_522_1.FirstEnterFlag = &bFirstEnterFlag;
  S_ktoenc_406_1.Xtek0 = &internal1_m406_Xtek0;
  S_ktoenc_406_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_400_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_397_1.Out10 = &internal1_m397_Out10;
  S_twobool_397_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_399_1.Out10 = &internal1_m399_Out10;
  S_twobool_399_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_398_1.Out10 = &internal1_m398_Out10;
  S_twobool_398_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_843_1.Out10 = &internal1_m843_Out10;
  S_twobool_843_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_844_1.Out10 = &internal1_m844_Out10;
  S_twobool_844_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_842_1.Out10 = &internal1_m842_Out10;
  S_twobool_842_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1026_1.Out10 = &internal1_m1026_Out10;
  S_twobool_1026_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_679_1.Out10 = &internal1_m679_Out10;
  S_twobool_679_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_680_1.Out10 = &internal1_m680_Out10;
  S_twobool_680_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_677_1.Out10 = &internal1_m677_Out10;
  S_twobool_677_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_678_1.Out10 = &internal1_m678_Out10;
  S_twobool_678_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_631_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_541_1.Out10 = &internal1_m541_Out10;
  S_twobool_541_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_540_1.Out10 = &internal1_m540_Out10;
  S_twobool_540_1.FirstEnterFlag = &bFirstEnterFlag;
  S_ktoenc_824_1.Xtek0 = &internal1_m824_Xtek0;
  S_ktoenc_824_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_816_1.FirstEnterFlag = &bFirstEnterFlag;
  S_ktoenc_826_1.Xtek0 = &internal1_m826_Xtek0;
  S_ktoenc_826_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_818_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_676_1.Out10 = &internal1_m676_Out10;
  S_twobool_676_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_660_1.Out10 = &internal1_m660_Out10;
  S_twobool_660_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_640_1.Out10 = &internal1_m640_Out10;
  S_twobool_640_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_659_1.Out10 = &internal1_m659_Out10;
  S_twobool_659_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_639_1.Out10 = &internal1_m639_Out10;
  S_twobool_639_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_327_1.Out10 = &internal1_m327_Out10;
  S_twobool_327_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_326_1.Out10 = &internal1_m326_Out10;
  S_twobool_326_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_311_1.Out10 = &internal1_m311_Out10;
  S_twobool_311_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_310_1.Out10 = &internal1_m310_Out10;
  S_twobool_310_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_503_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_496_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_542_1.Out10 = &internal1_m542_Out10;
  S_twobool_542_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_507_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_499_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_340_1.Out10 = &internal1_m340_Out10;
  S_twobool_340_1.FirstEnterFlag = &bFirstEnterFlag;
  S_ktoenc_324_1.Xtek0 = &internal1_m324_Xtek0;
  S_ktoenc_324_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_323_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_339_1.Out10 = &internal1_m339_Out10;
  S_twobool_339_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_337_1.Out10 = &internal1_m337_Out10;
  S_twobool_337_1.FirstEnterFlag = &bFirstEnterFlag;
  S_ktoenc_316_1.Xtek0 = &internal1_m316_Xtek0;
  S_ktoenc_316_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_313_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_338_1.Out10 = &internal1_m338_Out10;
  S_twobool_338_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_527_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_526_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_309_1.Out10 = &internal1_m309_Out10;
  S_twobool_309_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_325_1.Out10 = &internal1_m325_Out10;
  S_twobool_325_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_418_1.Out10 = &internal1_m418_Out10;
  S_twobool_418_1.FirstEnterFlag = &bFirstEnterFlag;
  S_ktoenc_419_1.Xtek0 = &internal1_m419_Xtek0;
  S_ktoenc_419_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_414_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_417_1.Out10 = &internal1_m417_Out10;
  S_twobool_417_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_416_1.Out10 = &internal1_m416_Out10;
  S_twobool_416_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_415_1.Out10 = &internal1_m415_Out10;
  S_twobool_415_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_521_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_157_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_156_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_155_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_150_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_160_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_159_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1025_1.Out10 = &internal1_m1025_Out10;
  S_twobool_1025_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_144_1.Out10 = &internal1_m144_Out10;
  S_twobool_144_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_158_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_152_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_143_1.Out10 = &internal1_m143_Out10;
  S_twobool_143_1.FirstEnterFlag = &bFirstEnterFlag;
  S_ovb1_191_1.tx = &internal1_m191_tx;
  S_ovb1_30_1.tx = &internal1_m30_tx;
  S_asmot_461_1.X00 = &internal1_m461_X00;
  S_asmot_461_1.V00 = &internal1_m461_V00;
  S_asmot_461_1.Pav0 = &internal1_m461_Pav0;
  S_asmot_461_1.Zav0 = &internal1_m461_Zav0;
  S_asmot_461_1.Pv0 = &internal1_m461_Pv0;
  S_asmot_461_1.Zv0 = &internal1_m461_Zv0;
  S_asmot_461_1.RA00 = &internal1_m461_RA00;
  S_asmot_461_1.RA10 = &internal1_m461_RA10;
  S_asmot_461_1.MyFirstEnterFlag = &internal1_m461_MyFirstEnterFlag;
  S_asmot_461_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_473_1.X00 = &internal1_m473_X00;
  S_asmot_473_1.V00 = &internal1_m473_V00;
  S_asmot_473_1.Pav0 = &internal1_m473_Pav0;
  S_asmot_473_1.Zav0 = &internal1_m473_Zav0;
  S_asmot_473_1.Pv0 = &internal1_m473_Pv0;
  S_asmot_473_1.Zv0 = &internal1_m473_Zv0;
  S_asmot_473_1.RA00 = &internal1_m473_RA00;
  S_asmot_473_1.RA10 = &internal1_m473_RA10;
  S_asmot_473_1.MyFirstEnterFlag = &internal1_m473_MyFirstEnterFlag;
  S_asmot_473_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_463_1.X00 = &internal1_m463_X00;
  S_asmot_463_1.V00 = &internal1_m463_V00;
  S_asmot_463_1.Pav0 = &internal1_m463_Pav0;
  S_asmot_463_1.Zav0 = &internal1_m463_Zav0;
  S_asmot_463_1.Pv0 = &internal1_m463_Pv0;
  S_asmot_463_1.Zv0 = &internal1_m463_Zv0;
  S_asmot_463_1.RA00 = &internal1_m463_RA00;
  S_asmot_463_1.RA10 = &internal1_m463_RA10;
  S_asmot_463_1.MyFirstEnterFlag = &internal1_m463_MyFirstEnterFlag;
  S_asmot_463_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_596_1.X00 = &internal1_m596_X00;
  S_asmot_596_1.V00 = &internal1_m596_V00;
  S_asmot_596_1.Pav0 = &internal1_m596_Pav0;
  S_asmot_596_1.Zav0 = &internal1_m596_Zav0;
  S_asmot_596_1.Pv0 = &internal1_m596_Pv0;
  S_asmot_596_1.Zv0 = &internal1_m596_Zv0;
  S_asmot_596_1.RA00 = &internal1_m596_RA00;
  S_asmot_596_1.RA10 = &internal1_m596_RA10;
  S_asmot_596_1.MyFirstEnterFlag = &internal1_m596_MyFirstEnterFlag;
  S_asmot_596_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_595_1.X00 = &internal1_m595_X00;
  S_asmot_595_1.V00 = &internal1_m595_V00;
  S_asmot_595_1.Pav0 = &internal1_m595_Pav0;
  S_asmot_595_1.Zav0 = &internal1_m595_Zav0;
  S_asmot_595_1.Pv0 = &internal1_m595_Pv0;
  S_asmot_595_1.Zv0 = &internal1_m595_Zv0;
  S_asmot_595_1.RA00 = &internal1_m595_RA00;
  S_asmot_595_1.RA10 = &internal1_m595_RA10;
  S_asmot_595_1.MyFirstEnterFlag = &internal1_m595_MyFirstEnterFlag;
  S_asmot_595_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_583_1.X00 = &internal1_m583_X00;
  S_asmot_583_1.V00 = &internal1_m583_V00;
  S_asmot_583_1.Pav0 = &internal1_m583_Pav0;
  S_asmot_583_1.Zav0 = &internal1_m583_Zav0;
  S_asmot_583_1.Pv0 = &internal1_m583_Pv0;
  S_asmot_583_1.Zv0 = &internal1_m583_Zv0;
  S_asmot_583_1.RA00 = &internal1_m583_RA00;
  S_asmot_583_1.RA10 = &internal1_m583_RA10;
  S_asmot_583_1.MyFirstEnterFlag = &internal1_m583_MyFirstEnterFlag;
  S_asmot_583_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_582_1.X00 = &internal1_m582_X00;
  S_asmot_582_1.V00 = &internal1_m582_V00;
  S_asmot_582_1.Pav0 = &internal1_m582_Pav0;
  S_asmot_582_1.Zav0 = &internal1_m582_Zav0;
  S_asmot_582_1.Pv0 = &internal1_m582_Pv0;
  S_asmot_582_1.Zv0 = &internal1_m582_Zv0;
  S_asmot_582_1.RA00 = &internal1_m582_RA00;
  S_asmot_582_1.RA10 = &internal1_m582_RA10;
  S_asmot_582_1.MyFirstEnterFlag = &internal1_m582_MyFirstEnterFlag;
  S_asmot_582_1.FirstEnterFlag = &bFirstEnterFlag;
  S_mod1_625_1.y0 = &internal1_m625_y0;
  S_vchs_789_1.Chim0 = &internal1_m789_Chim0;
  S_vchs_780_1.Chim0 = &internal1_m780_Chim0;
  S_vchs_772_1.Chim0 = &internal1_m772_Chim0;
  S_vchs_763_1.Chim0 = &internal1_m763_Chim0;
  S_vchs_754_1.Chim0 = &internal1_m754_Chim0;
  S_vchs_746_1.Chim0 = &internal1_m746_Chim0;
  S_vchs_737_1.Chim0 = &internal1_m737_Chim0;
  S_vchs_728_1.Chim0 = &internal1_m728_Chim0;
  S_vchs_720_1.Chim0 = &internal1_m720_Chim0;
  S_vchs_711_1.Chim0 = &internal1_m711_Chim0;
  S_vchs_702_1.Chim0 = &internal1_m702_Chim0;
  S_vchs_692_1.Chim0 = &internal1_m692_Chim0;
  S_asmot_570_1.X00 = &internal1_m570_X00;
  S_asmot_570_1.V00 = &internal1_m570_V00;
  S_asmot_570_1.Pav0 = &internal1_m570_Pav0;
  S_asmot_570_1.Zav0 = &internal1_m570_Zav0;
  S_asmot_570_1.Pv0 = &internal1_m570_Pv0;
  S_asmot_570_1.Zv0 = &internal1_m570_Zv0;
  S_asmot_570_1.RA00 = &internal1_m570_RA00;
  S_asmot_570_1.RA10 = &internal1_m570_RA10;
  S_asmot_570_1.MyFirstEnterFlag = &internal1_m570_MyFirstEnterFlag;
  S_asmot_570_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_556_1.X00 = &internal1_m556_X00;
  S_asmot_556_1.V00 = &internal1_m556_V00;
  S_asmot_556_1.Pav0 = &internal1_m556_Pav0;
  S_asmot_556_1.Zav0 = &internal1_m556_Zav0;
  S_asmot_556_1.Pv0 = &internal1_m556_Pv0;
  S_asmot_556_1.Zv0 = &internal1_m556_Zv0;
  S_asmot_556_1.RA00 = &internal1_m556_RA00;
  S_asmot_556_1.RA10 = &internal1_m556_RA10;
  S_asmot_556_1.MyFirstEnterFlag = &internal1_m556_MyFirstEnterFlag;
  S_asmot_556_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_447_1.X00 = &internal1_m447_X00;
  S_asmot_447_1.V00 = &internal1_m447_V00;
  S_asmot_447_1.Pav0 = &internal1_m447_Pav0;
  S_asmot_447_1.Zav0 = &internal1_m447_Zav0;
  S_asmot_447_1.Pv0 = &internal1_m447_Pv0;
  S_asmot_447_1.Zv0 = &internal1_m447_Zv0;
  S_asmot_447_1.RA00 = &internal1_m447_RA00;
  S_asmot_447_1.RA10 = &internal1_m447_RA10;
  S_asmot_447_1.MyFirstEnterFlag = &internal1_m447_MyFirstEnterFlag;
  S_asmot_447_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_433_1.X00 = &internal1_m433_X00;
  S_asmot_433_1.V00 = &internal1_m433_V00;
  S_asmot_433_1.Pav0 = &internal1_m433_Pav0;
  S_asmot_433_1.Zav0 = &internal1_m433_Zav0;
  S_asmot_433_1.Pv0 = &internal1_m433_Pv0;
  S_asmot_433_1.Zv0 = &internal1_m433_Zv0;
  S_asmot_433_1.RA00 = &internal1_m433_RA00;
  S_asmot_433_1.RA10 = &internal1_m433_RA10;
  S_asmot_433_1.MyFirstEnterFlag = &internal1_m433_MyFirstEnterFlag;
  S_asmot_433_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_484_1.X00 = &internal1_m484_X00;
  S_asmot_484_1.V00 = &internal1_m484_V00;
  S_asmot_484_1.Pav0 = &internal1_m484_Pav0;
  S_asmot_484_1.Zav0 = &internal1_m484_Zav0;
  S_asmot_484_1.Pv0 = &internal1_m484_Pv0;
  S_asmot_484_1.Zv0 = &internal1_m484_Zv0;
  S_asmot_484_1.RA00 = &internal1_m484_RA00;
  S_asmot_484_1.RA10 = &internal1_m484_RA10;
  S_asmot_484_1.MyFirstEnterFlag = &internal1_m484_MyFirstEnterFlag;
  S_asmot_484_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_385_1.X00 = &internal1_m385_X00;
  S_asmot_385_1.V00 = &internal1_m385_V00;
  S_asmot_385_1.Pav0 = &internal1_m385_Pav0;
  S_asmot_385_1.Zav0 = &internal1_m385_Zav0;
  S_asmot_385_1.Pv0 = &internal1_m385_Pv0;
  S_asmot_385_1.Zv0 = &internal1_m385_Zv0;
  S_asmot_385_1.RA00 = &internal1_m385_RA00;
  S_asmot_385_1.RA10 = &internal1_m385_RA10;
  S_asmot_385_1.MyFirstEnterFlag = &internal1_m385_MyFirstEnterFlag;
  S_asmot_385_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_370_1.X00 = &internal1_m370_X00;
  S_asmot_370_1.V00 = &internal1_m370_V00;
  S_asmot_370_1.Pav0 = &internal1_m370_Pav0;
  S_asmot_370_1.Zav0 = &internal1_m370_Zav0;
  S_asmot_370_1.Pv0 = &internal1_m370_Pv0;
  S_asmot_370_1.Zv0 = &internal1_m370_Zv0;
  S_asmot_370_1.RA00 = &internal1_m370_RA00;
  S_asmot_370_1.RA10 = &internal1_m370_RA10;
  S_asmot_370_1.MyFirstEnterFlag = &internal1_m370_MyFirstEnterFlag;
  S_asmot_370_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_354_1.X00 = &internal1_m354_X00;
  S_asmot_354_1.V00 = &internal1_m354_V00;
  S_asmot_354_1.Pav0 = &internal1_m354_Pav0;
  S_asmot_354_1.Zav0 = &internal1_m354_Zav0;
  S_asmot_354_1.Pv0 = &internal1_m354_Pv0;
  S_asmot_354_1.Zv0 = &internal1_m354_Zv0;
  S_asmot_354_1.RA00 = &internal1_m354_RA00;
  S_asmot_354_1.RA10 = &internal1_m354_RA10;
  S_asmot_354_1.MyFirstEnterFlag = &internal1_m354_MyFirstEnterFlag;
  S_asmot_354_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_882_1.X00 = &internal1_m882_X00;
  S_asmot_882_1.V00 = &internal1_m882_V00;
  S_asmot_882_1.Pav0 = &internal1_m882_Pav0;
  S_asmot_882_1.Zav0 = &internal1_m882_Zav0;
  S_asmot_882_1.Pv0 = &internal1_m882_Pv0;
  S_asmot_882_1.Zv0 = &internal1_m882_Zv0;
  S_asmot_882_1.RA00 = &internal1_m882_RA00;
  S_asmot_882_1.RA10 = &internal1_m882_RA10;
  S_asmot_882_1.MyFirstEnterFlag = &internal1_m882_MyFirstEnterFlag;
  S_asmot_882_1.FirstEnterFlag = &bFirstEnterFlag;
  S_azbars_176_1.C1 = &internal1_m176_C1;
  S_azbars_176_1.C2 = &internal1_m176_C2;
  S_azbars_176_1.C3 = &internal1_m176_C3;
  S_azbars_176_1.C4 = &internal1_m176_C4;
  S_azbars_176_1.C5 = &internal1_m176_C5;
  S_azbars_176_1.C6 = &internal1_m176_C6;
  S_azbars_176_1.N20 = &internal1_m176_N20;
  S_azbars_176_1.ImpINI0 = &internal1_m176_ImpINI0;
  S_azbars_176_1.MyFirstEnterFlag = &internal1_m176_MyFirstEnterFlag;
  S_azbars_176_1.FirstEnterFlag = &bFirstEnterFlag;
  S_orrsim_290_1.X00 = &internal1_m290_X00;
  S_orrsim_290_1.Sh00 = &internal1_m290_Sh00;
  S_orrsim_290_1.RV00 = &internal1_m290_RV00;
  S_orrsim_290_1.ShV00 = &internal1_m290_ShV00;
  S_orrsim_290_1.Ppv0 = &internal1_m290_Ppv0;
  S_orrsim_290_1.Pav0 = &internal1_m290_Pav0;
  S_orrsim_290_1.Zav0 = &internal1_m290_Zav0;
  S_orrsim_290_1.RA00 = &internal1_m290_RA00;
  S_orrsim_290_1.RA10 = &internal1_m290_RA10;
  S_orrsim_290_1.RA50 = &internal1_m290_RA50;
  S_orrsim_290_1.fls = &internal1_m290_fls;
  S_orrsim_290_1.flp = &internal1_m290_flp;
  S_orrsim_290_1.MyFirstEnterFlag = &internal1_m290_MyFirstEnterFlag;
  S_orrsim_290_1.FirstEnterFlag = &bFirstEnterFlag;
  S_orrsim_126_1.X00 = &internal1_m126_X00;
  S_orrsim_126_1.Sh00 = &internal1_m126_Sh00;
  S_orrsim_126_1.RV00 = &internal1_m126_RV00;
  S_orrsim_126_1.ShV00 = &internal1_m126_ShV00;
  S_orrsim_126_1.Ppv0 = &internal1_m126_Ppv0;
  S_orrsim_126_1.Pav0 = &internal1_m126_Pav0;
  S_orrsim_126_1.Zav0 = &internal1_m126_Zav0;
  S_orrsim_126_1.RA00 = &internal1_m126_RA00;
  S_orrsim_126_1.RA10 = &internal1_m126_RA10;
  S_orrsim_126_1.RA50 = &internal1_m126_RA50;
  S_orrsim_126_1.fls = &internal1_m126_fls;
  S_orrsim_126_1.flp = &internal1_m126_flp;
  S_orrsim_126_1.MyFirstEnterFlag = &internal1_m126_MyFirstEnterFlag;
  S_orrsim_126_1.FirstEnterFlag = &bFirstEnterFlag;
  S_orrsim_258_1.X00 = &internal1_m258_X00;
  S_orrsim_258_1.Sh00 = &internal1_m258_Sh00;
  S_orrsim_258_1.RV00 = &internal1_m258_RV00;
  S_orrsim_258_1.ShV00 = &internal1_m258_ShV00;
  S_orrsim_258_1.Ppv0 = &internal1_m258_Ppv0;
  S_orrsim_258_1.Pav0 = &internal1_m258_Pav0;
  S_orrsim_258_1.Zav0 = &internal1_m258_Zav0;
  S_orrsim_258_1.RA00 = &internal1_m258_RA00;
  S_orrsim_258_1.RA10 = &internal1_m258_RA10;
  S_orrsim_258_1.RA50 = &internal1_m258_RA50;
  S_orrsim_258_1.fls = &internal1_m258_fls;
  S_orrsim_258_1.flp = &internal1_m258_flp;
  S_orrsim_258_1.MyFirstEnterFlag = &internal1_m258_MyFirstEnterFlag;
  S_orrsim_258_1.FirstEnterFlag = &bFirstEnterFlag;
  S_orrsim_94_1.X00 = &internal1_m94_X00;
  S_orrsim_94_1.Sh00 = &internal1_m94_Sh00;
  S_orrsim_94_1.RV00 = &internal1_m94_RV00;
  S_orrsim_94_1.ShV00 = &internal1_m94_ShV00;
  S_orrsim_94_1.Ppv0 = &internal1_m94_Ppv0;
  S_orrsim_94_1.Pav0 = &internal1_m94_Pav0;
  S_orrsim_94_1.Zav0 = &internal1_m94_Zav0;
  S_orrsim_94_1.RA00 = &internal1_m94_RA00;
  S_orrsim_94_1.RA10 = &internal1_m94_RA10;
  S_orrsim_94_1.RA50 = &internal1_m94_RA50;
  S_orrsim_94_1.fls = &internal1_m94_fls;
  S_orrsim_94_1.flp = &internal1_m94_flp;
  S_orrsim_94_1.MyFirstEnterFlag = &internal1_m94_MyFirstEnterFlag;
  S_orrsim_94_1.FirstEnterFlag = &bFirstEnterFlag;
  S_orrsim_223_1.X00 = &internal1_m223_X00;
  S_orrsim_223_1.Sh00 = &internal1_m223_Sh00;
  S_orrsim_223_1.RV00 = &internal1_m223_RV00;
  S_orrsim_223_1.ShV00 = &internal1_m223_ShV00;
  S_orrsim_223_1.Ppv0 = &internal1_m223_Ppv0;
  S_orrsim_223_1.Pav0 = &internal1_m223_Pav0;
  S_orrsim_223_1.Zav0 = &internal1_m223_Zav0;
  S_orrsim_223_1.RA00 = &internal1_m223_RA00;
  S_orrsim_223_1.RA10 = &internal1_m223_RA10;
  S_orrsim_223_1.RA50 = &internal1_m223_RA50;
  S_orrsim_223_1.fls = &internal1_m223_fls;
  S_orrsim_223_1.flp = &internal1_m223_flp;
  S_orrsim_223_1.MyFirstEnterFlag = &internal1_m223_MyFirstEnterFlag;
  S_orrsim_223_1.FirstEnterFlag = &bFirstEnterFlag;
  S_orrsim_59_1.X00 = &internal1_m59_X00;
  S_orrsim_59_1.Sh00 = &internal1_m59_Sh00;
  S_orrsim_59_1.RV00 = &internal1_m59_RV00;
  S_orrsim_59_1.ShV00 = &internal1_m59_ShV00;
  S_orrsim_59_1.Ppv0 = &internal1_m59_Ppv0;
  S_orrsim_59_1.Pav0 = &internal1_m59_Pav0;
  S_orrsim_59_1.Zav0 = &internal1_m59_Zav0;
  S_orrsim_59_1.RA00 = &internal1_m59_RA00;
  S_orrsim_59_1.RA10 = &internal1_m59_RA10;
  S_orrsim_59_1.RA50 = &internal1_m59_RA50;
  S_orrsim_59_1.fls = &internal1_m59_fls;
  S_orrsim_59_1.flp = &internal1_m59_flp;
  S_orrsim_59_1.MyFirstEnterFlag = &internal1_m59_MyFirstEnterFlag;
  S_orrsim_59_1.FirstEnterFlag = &bFirstEnterFlag;
  S_azbars_14_1.C1 = &internal1_m14_C1;
  S_azbars_14_1.C2 = &internal1_m14_C2;
  S_azbars_14_1.C3 = &internal1_m14_C3;
  S_azbars_14_1.C4 = &internal1_m14_C4;
  S_azbars_14_1.C5 = &internal1_m14_C5;
  S_azbars_14_1.C6 = &internal1_m14_C6;
  S_azbars_14_1.N20 = &internal1_m14_N20;
  S_azbars_14_1.ImpINI0 = &internal1_m14_ImpINI0;
  S_azbars_14_1.MyFirstEnterFlag = &internal1_m14_MyFirstEnterFlag;
  S_azbars_14_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_944_1.x1 = &fEM_R7UX16RSS;
  S_vchs_870_1.YAz1 = &fEM_R4UC23RIM;
  S_vchs_870_1.YAz2 = &fEM_R7UY00RSS;
  S_vchs_870_1.XCm = &fEM_R7UX15RSS;
  S_vchs_870_1.YCm = &fEM_R7UY15RSS;
  S_vchs_870_1.Ak = &fEM_A0UX15RSS;
  S_vchs_870_1.Bk = &fEM_B0UX05RSS;
  S_vchs_870_1.Fk = &fEM_R0UH03RSS;
  S_vchs_870_1.FMax = &fEM_R0UH23RSS;
  S_vchs_870_1.Reff = &fEM_A0UX00RSS;
  S_vchs_860_1.YAz1 = &fEM_R4UC23RIM;
  S_vchs_860_1.YAz2 = &fEM_R7UY00RSS;
  S_vchs_860_1.XCm = &fEM_R7UX14RSS;
  S_vchs_860_1.YCm = &fEM_R7UY14RSS;
  S_vchs_860_1.Ak = &fEM_A0UX14RSS;
  S_vchs_860_1.Bk = &fEM_B0UX04RSS;
  S_vchs_860_1.Fk = &fEM_R0UH02RSS;
  S_vchs_860_1.FMax = &fEM_R0UH22RSS;
  S_vchs_860_1.Reff = &fEM_A0UX00RSS;
  S_vchs_852_1.YAz1 = &fEM_R4UC23RIM;
  S_vchs_852_1.YAz2 = &fEM_R7UY00RSS;
  S_vchs_852_1.XCm = &fEM_R7UX13RSS;
  S_vchs_852_1.YCm = &fEM_R7UY13RSS;
  S_vchs_852_1.Ak = &fEM_A0UX13RSS;
  S_vchs_852_1.Bk = &fEM_B0UX03RSS;
  S_vchs_852_1.Fk = &fEM_R0UH01RSS;
  S_vchs_852_1.FMax = &fEM_R0UH21RSS;
  S_vchs_852_1.Reff = &fEM_A0UX00RSS;
  S_twobool_807_1.Ter = &iEM_TERR4VS22LDU;
  S_twobool_806_1.Ter = &iEM_TERR4VS12LDU;
  S_twobool_989_1.Ter = &iEM_TERR2VS22LIM;
  S_twobool_988_1.Ter = &iEM_TERR2VS12LIM;
  S_twobool_987_1.Ter = &iEM_TERR1VS22LIM;
  S_twobool_986_1.Ter = &iEM_TERR1VS12LIM;
  S_twobool_666_1.Ter = &iEM_TERB5VS22LIM;
  S_twobool_665_1.Ter = &iEM_TERB5VS12LIM;
  S_twobool_644_1.Ter = &iEM_TERA5VS22LIM;
  S_twobool_643_1.Ter = &iEM_TERA5VS12LIM;
  S_twobool_664_1.Ter = &iEM_TERB6VS22LIM;
  S_twobool_663_1.Ter = &iEM_TERB6VS12LIM;
  S_twobool_642_1.Ter = &iEM_TERA6VS22LIM;
  S_twobool_641_1.Ter = &iEM_TERA6VS12LIM;
  S_twobool_508_1.Ter = &iEM_TERA1VP81LIM;
  S_twobool_524_1.Ter = &iEM_TERB1VP81LIM;
  S_twobool_396_1.Ter = &iEM_TERB2SS33LIM;
  S_rs_469_1.s = &lEM_R5AD10LC1;
  S_rs_470_1.s = &lEM_R5AD20LC1;
  S_rs_457_1.s = &lEM_R3AD10LC1;
  S_rs_458_1.s = &lEM_R3AD20LC1;
  S_zpfs_617_1.tz = &fEM_R7UI76RIM;
  S_zpfs_605_1.tz = &fEM_R7UI77RIM;
  S_bol_930_1.x1 = &fEM_A4UP01RIM;
  S_bol_930_1.x2 = &fEM_A4UP02RIM;
  S_bol_927_1.x1 = &fEM_A3UP01RIM;
  S_bol_927_1.x2 = &fEM_A3UP02RIM;
  S_bol_906_1.x1 = &fEM_A0UP02RIM;
  S_bol_906_1.x2 = &fEM_A0UP01RIM;
  S_bol_928_1.x1 = &fEM_A2UP02RIM;
  S_bol_928_1.x2 = &fEM_A2UP03RIM;
  S_bol_918_1.x1 = &fEM_A1UP01RIM;
  S_bol_918_1.x2 = &fEM_A1UP82RIM;
  S_twobool_202_1.Ter = &iEM_TERB1IE04LDU;
  S_twobool_218_1.Ter = &iEM_TERB1IE03LDU;
  S_twobool_41_1.Ter = &iEM_TERA1IE04LDU;
  S_twobool_56_1.Ter = &iEM_TERA1IE03LDU;
  S_twobool_960_1.Ter = &iEM_TERB1SS12LIM;
  S_twobool_957_1.Ter = &iEM_TERB1SS11LIM;
  S_twobool_956_1.Ter = &iEM_TERB1SS21LIM;
  S_ktoenc_959_1.C = &fEM_A1UC03RDU;
  S_to3val_954_1.Ter = &iEM_TERB1MC01RIM;
  S_ktoenc_942_1.C = &fEM_A1UC03RDU;
  S_to3val_935_1.Ter = &iEM_TERA1SC01RIM;
  S_twobool_943_1.Ter = &iEM_TERA1SS12LIM;
  S_twobool_940_1.Ter = &iEM_TERA1SS11LIM;
  S_twobool_939_1.Ter = &iEM_TERA1SS21LIM;
  S_twobool_1027_1.Ter = &iEM_TERB6SS21LIM;
  S_twobool_1008_1.Ter = &iEM_TERB6SS11LIM;
  S_twobool_1007_1.Ter = &iEM_TERA6SS21LIM;
  S_twobool_1006_1.Ter = &iEM_TERA6MS11LIM;
  S_twobool_828_1.Ter = &iEM_TERA8SS12LIM;
  S_twobool_830_1.Ter = &iEM_TERA8SS22LIM;
  S_twobool_827_1.Ter = &iEM_TERB8SS12LIM;
  S_twobool_829_1.Ter = &iEM_TERB8SS22LIM;
  S_twobool_803_1.Ter = &iEM_TERR4SS12LIM;
  S_twobool_804_1.Ter = &iEM_TERR4SS22LIM;
  S_twobool_802_1.Ter = &iEM_TERR4MS21LIM;
  S_twobool_801_1.Ter = &iEM_TERR4SS11LIM;
  S_twobool_1022_1.Ter = &iEM_TERA4VP82LIM;
  S_twobool_974_1.Ter = &iEM_TERR2SS21LIM;
  S_twobool_973_1.Ter = &iEM_TERR2SS11LIM;
  S_twobool_972_1.Ter = &iEM_TERR1SS21LIM;
  S_twobool_971_1.Ter = &iEM_TERR1SS11LIM;
  S_twobool_1023_1.Ter = &iEM_TERB4SS21LIM;
  S_twobool_1004_1.Ter = &iEM_TERB4SS11LIM;
  S_twobool_805_1.S = &lEM_R8AD10LC1;
  S_twobool_805_1.Ter = &iEM_TERR8SS11LIM;
  S_twobool_1005_1.Ter = &iEM_TERA4SS21LIM;
  S_twobool_1003_1.Ter = &iEM_TERA4SS11LIM;
  S_twobool_1024_1.Ter = &iEM_TERR5SS21LIM;
  S_twobool_1002_1.Ter = &iEM_TERR5SS11LIM;
  S_twobool_985_1.Ter = &iEM_TERR3SS21LIM;
  S_twobool_970_1.Ter = &iEM_TERR3SS11LIM;
  S_twobool_525_1.Ter = &iEM_TERA2VP82LIM;
  S_toao_529_1.a = &fEM_A2UP04RDU;
  S_toao_529_1.b = &fEM_A2UP03RDU;
  S_toao_528_1.a = &fEM_A2UP04RDU;
  S_toao_528_1.b = &fEM_A2UP03RDU;
  S_to3val_522_1.maxs1 = &fEM_A2UP03RDU;
  S_to3val_522_1.maxs2 = &fEM_A2UP03RDU;
  S_to3val_522_1.Ter = &iEM_TERB2SP01RIM;
  S_ktoenc_406_1.C = &fEM_A2UC03RDU;
  S_to3val_400_1.Ter = &iEM_TERB2SC01RIM;
  S_twobool_397_1.Ter = &iEM_TERB2SS12LIM;
  S_twobool_399_1.Ter = &iEM_TERB2SS11LIM;
  S_twobool_398_1.Ter = &iEM_TERB2SS21LIM;
  S_twobool_843_1.Ter = &iEM_TERB9SS21LIM;
  S_twobool_844_1.Ter = &iEM_TERB9SS11LIM;
  S_twobool_842_1.Ter = &iEM_TERA9SS21LIM;
  S_twobool_1026_1.Ter = &iEM_TERA9SS11LIM;
  S_twobool_679_1.Ter = &iEM_TERB5SS21LIM;
  S_twobool_680_1.Ter = &iEM_TERB5SS11LIM;
  S_twobool_677_1.Ter = &iEM_TERA5SS21LIM;
  S_twobool_678_1.Ter = &iEM_TERA5SS11LIM;
  S_ampl_630_1.k = &fEM_R7UI75RIM;
  S_to3val_631_1.maxs1 = &fEM_R7UI74RIM;
  S_to3val_631_1.maxs2 = &fEM_R7UI74RIM;
  S_to3val_631_1.Ter = &iEM_TERR7SI74RIM;
  S_twobool_541_1.Ter = &iEM_TERB0VP81LIM;
  S_twobool_540_1.Ter = &iEM_TERA0VP81LIM;
  S_ktoenc_824_1.C = &fEM_A8UC03RDU;
  S_to3val_816_1.Ter = &iEM_TERB8SC01RIM;
  S_ktoenc_826_1.C = &fEM_A8UC03RDU;
  S_to3val_818_1.Ter = &iEM_TERA8SC01RIM;
  S_twobool_676_1.Ter = &iEM_TERR6IS68LIM;
  S_twobool_660_1.Ter = &iEM_TERR6IS67LIM;
  S_twobool_640_1.Ter = &iEM_TERR6IS66LIM;
  S_twobool_659_1.Ter = &iEM_TERR6IS64LIM;
  S_twobool_639_1.Ter = &iEM_TERR6IS62LIM;
  S_twobool_327_1.Ter = &iEM_TERB3SS22LIM;
  S_twobool_326_1.Ter = &iEM_TERA3SS22LIM;
  S_twobool_311_1.Ter = &iEM_TERB3SS11LIM;
  S_twobool_310_1.Ter = &iEM_TERA3SS11LIM;
  S_toao_503_1.a = &fEM_A3UP04RDU;
  S_toao_503_1.b = &fEM_A3UP03RDU;
  S_to3val_496_1.maxs1 = &fEM_A3UP03RDU;
  S_to3val_496_1.maxs2 = &fEM_A3UP03RDU;
  S_to3val_496_1.Ter = &iEM_TERA3SP02RIM;
  S_twobool_542_1.Ter = &iEM_TERA3VP81LIM;
  S_toao_507_1.a = &fEM_A3UP04RDU;
  S_toao_507_1.b = &fEM_A3UP03RDU;
  S_to3val_499_1.maxs1 = &fEM_A3UP03RDU;
  S_to3val_499_1.maxs2 = &fEM_A3UP03RDU;
  S_to3val_499_1.Ter = &iEM_TERB3SP02RIM;
  S_twobool_340_1.Ter = &iEM_TERB3SS33LIM;
  S_ktoenc_324_1.C = &fEM_A3UC03RDU;
  S_to3val_323_1.Ter = &iEM_TERB3SC01RIM;
  S_twobool_339_1.Ter = &iEM_TERB3SS31LIM;
  S_twobool_337_1.Ter = &iEM_TERA3SS33LIM;
  S_ktoenc_316_1.C = &fEM_A3UC03RDU;
  S_to3val_313_1.Ter = &iEM_TERA3SC01RIM;
  S_twobool_338_1.Ter = &iEM_TERA3SS31LIM;
  S_toao_527_1.a = &fEM_A2UP04RDU;
  S_toao_527_1.b = &fEM_A2UP03RDU;
  S_toao_526_1.a = &fEM_A2UP04RDU;
  S_toao_526_1.b = &fEM_A2UP03RDU;
  S_twobool_309_1.Ter = &iEM_TERB3SS21LIM;
  S_twobool_325_1.Ter = &iEM_TERA3SS21LIM;
  S_twobool_418_1.Ter = &iEM_TERA2SS33LIM;
  S_ktoenc_419_1.C = &fEM_A2UC03RDU;
  S_to3val_414_1.Ter = &iEM_TERA2SC01RIM;
  S_twobool_417_1.Ter = &iEM_TERA2SS12LIM;
  S_twobool_416_1.Ter = &iEM_TERA2SS11LIM;
  S_twobool_415_1.Ter = &iEM_TERA2SS21LIM;
  S_to3val_521_1.x1 = &fEM_A2UP01RIM;
  S_to3val_521_1.maxs1 = &fEM_A2UP03RDU;
  S_to3val_521_1.maxs2 = &fEM_A2UP03RDU;
  S_to3val_521_1.Ter = &iEM_TERA2SP01RIM;
  S_toao_157_1.a = &fEM_R0UT01RDU;
  S_toao_157_1.b = &fEM_R0UT02RDU;
  S_toao_156_1.a = &fEM_R0UT01RDU;
  S_toao_156_1.b = &fEM_R0UT02RDU;
  S_toao_155_1.a = &fEM_R0UT01RDU;
  S_toao_155_1.b = &fEM_R0UT02RDU;
  S_to3val_150_1.maxs1 = &fEM_R0UT02RDU;
  S_to3val_150_1.maxs2 = &fEM_R0UT02RDU;
  S_to3val_150_1.Ter = &iEM_TERB0MT01RIM;
  S_toao_160_1.a = &fEM_R0UT01RDU;
  S_toao_160_1.b = &fEM_R0UT02RDU;
  S_toao_159_1.a = &fEM_R0UT01RDU;
  S_toao_159_1.b = &fEM_R0UT02RDU;
  S_twobool_1025_1.Ter = &iEM_TERR6SS21LIM;
  S_twobool_144_1.Ter = &iEM_TERB7MS31LIM;
  S_toao_158_1.a = &fEM_R0UT01RDU;
  S_toao_158_1.b = &fEM_R0UT02RDU;
  S_to3val_152_1.maxs1 = &fEM_R0UT02RDU;
  S_to3val_152_1.maxs2 = &fEM_R0UT02RDU;
  S_to3val_152_1.Ter = &iEM_TERA0MT01RIM;
  S_twobool_143_1.Ter = &iEM_TERA7MS31LIM;
  S_lk_498_1.x = &fEM_A3UP02RDU;
  S_lk_497_1.x = &fEM_A3UP02RDU;
  S_noto_459_1.x = &lEM_R6AD10LC1;
  S_asmot_461_1.RA1 = &lEM_R6AD10LC1;
  S_asmot_461_1.KPav = &fEM_R6UL10RIM;
  S_asmot_461_1.X0 = &fEM_R6UC01RSP;
  S_asmot_473_1.KPav = &fEM_R5UL10RIM;
  S_asmot_473_1.X0 = &fEM_R5UC01RSP;
  S_asmot_463_1.KPav = &fEM_R3UL10RIM;
  S_asmot_463_1.X0 = &fEM_R3UC01RSP;
  S_asmot_596_1.KPav = &fEM_A4UL10RIM;
  S_asmot_596_1.X0 = &fEM_A4MC01RSP;
  S_asmot_595_1.KPav = &fEM_A4UL10RIM;
  S_asmot_595_1.X0 = &fEM_B4MC01RSP;
  S_asmot_583_1.KPav = &fEM_A9UL10RIM;
  S_asmot_583_1.X0 = &fEM_A9MC01RSP;
  S_asmot_582_1.KPav = &fEM_A9UL10RIM;
  S_asmot_582_1.X0 = &fEM_B9MC01RSP;
  S_fsubo_360_1.x1 = &fEM_R7UY00RSS;
  S_fsubo_111_1.x1 = &fEM_A2UC05RIM;
  S_fsubo_275_1.x1 = &fEM_A2UC05RIM;
  S_fsubo_238_1.x1 = &fEM_A1UC05RIM;
  S_fsubo_74_1.x1 = &fEM_A1UC05RIM;
  S_fsubo_8_1.x2 = &fEM_R0UR01RIM;
  S_mod1_625_1.k = &fEM_R7UI02RIM;
  S_mod1_625_1.tau = &fEM_R7UL01RIM;
  S_bol_619_1.x2 = &fEM_R7UI73RIM;
  S_bol_609_1.x2 = &fEM_R7UI72RIM;
  S_bol_603_1.x2 = &fEM_R7UI71RIM;
  S_vchs_789_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_789_1.YAz2 = &fEM_R7UY00RSS;
  S_vchs_789_1.XCm = &fEM_R7UX12RSS;
  S_vchs_789_1.YCm = &fEM_R7UY12RSS;
  S_vchs_789_1.Ak = &fEM_A0UX12RSS;
  S_vchs_789_1.Bk = &fEM_B0UX12RSS;
  S_vchs_789_1.Fk = &fEM_R0UH03RSS;
  S_vchs_789_1.FMax = &fEM_R0UH23RSS;
  S_vchs_789_1.Reff = &fEM_A0UX00RSS;
  S_vchs_780_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_780_1.YAz2 = &fEM_R7UY00RSS;
  S_vchs_780_1.XCm = &fEM_R7UX11RSS;
  S_vchs_780_1.YCm = &fEM_R7UY11RSS;
  S_vchs_780_1.Ak = &fEM_A0UX11RSS;
  S_vchs_780_1.Bk = &fEM_B0UX11RSS;
  S_vchs_780_1.Fk = &fEM_R0UH02RSS;
  S_vchs_780_1.FMax = &fEM_R0UH22RSS;
  S_vchs_780_1.Reff = &fEM_A0UX00RSS;
  S_vchs_772_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_772_1.YAz2 = &fEM_R7UY00RSS;
  S_vchs_772_1.XCm = &fEM_R7UX10RSS;
  S_vchs_772_1.YCm = &fEM_R7UY10RSS;
  S_vchs_772_1.Ak = &fEM_A0UX10RSS;
  S_vchs_772_1.Bk = &fEM_B0UX10RSS;
  S_vchs_772_1.Fk = &fEM_R0UH01RSS;
  S_vchs_772_1.FMax = &fEM_R0UH21RSS;
  S_vchs_772_1.Reff = &fEM_A0UX00RSS;
  S_vchs_763_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_763_1.YAz2 = &fEM_R7UY00RSS;
  S_vchs_763_1.XCm = &fEM_R7UX09RSS;
  S_vchs_763_1.YCm = &fEM_R7UY09RSS;
  S_vchs_763_1.Ak = &fEM_A0UX09RSS;
  S_vchs_763_1.Bk = &fEM_B0UX09RSS;
  S_vchs_763_1.Fk = &fEM_R0UH03RSS;
  S_vchs_763_1.FMax = &fEM_R0UH23RSS;
  S_vchs_763_1.Reff = &fEM_A0UX00RSS;
  S_vchs_754_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_754_1.YAz2 = &fEM_R7UY00RSS;
  S_vchs_754_1.XCm = &fEM_R7UX08RSS;
  S_vchs_754_1.YCm = &fEM_R7UY08RSS;
  S_vchs_754_1.Ak = &fEM_A0UX08RSS;
  S_vchs_754_1.Bk = &fEM_B0UX08RSS;
  S_vchs_754_1.Fk = &fEM_R0UH02RSS;
  S_vchs_754_1.FMax = &fEM_R0UH22RSS;
  S_vchs_754_1.Reff = &fEM_A0UX00RSS;
  S_vchs_746_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_746_1.YAz2 = &fEM_R7UY00RSS;
  S_vchs_746_1.XCm = &fEM_R7UX07RSS;
  S_vchs_746_1.YCm = &fEM_R7UY07RSS;
  S_vchs_746_1.Ak = &fEM_A0UX07RSS;
  S_vchs_746_1.Bk = &fEM_B0UX07RSS;
  S_vchs_746_1.Fk = &fEM_R0UH01RSS;
  S_vchs_746_1.FMax = &fEM_R0UH21RSS;
  S_vchs_746_1.Reff = &fEM_A0UX00RSS;
  S_vchs_737_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_737_1.YAz2 = &fEM_R7UY00RSS;
  S_vchs_737_1.XCm = &fEM_R7UX06RSS;
  S_vchs_737_1.YCm = &fEM_R7UY06RSS;
  S_vchs_737_1.Ak = &fEM_A0UX06RSS;
  S_vchs_737_1.Bk = &fEM_B0UX06RSS;
  S_vchs_737_1.Fk = &fEM_R0UH03RSS;
  S_vchs_737_1.FMax = &fEM_R0UH23RSS;
  S_vchs_737_1.Reff = &fEM_A0UX00RSS;
  S_vchs_728_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_728_1.YAz2 = &fEM_R7UY00RSS;
  S_vchs_728_1.XCm = &fEM_R7UX05RSS;
  S_vchs_728_1.YCm = &fEM_R7UY05RSS;
  S_vchs_728_1.Ak = &fEM_A0UX05RSS;
  S_vchs_728_1.Bk = &fEM_B0UX05RSS;
  S_vchs_728_1.Fk = &fEM_R0UH02RSS;
  S_vchs_728_1.FMax = &fEM_R0UH22RSS;
  S_vchs_728_1.Reff = &fEM_A0UX00RSS;
  S_vchs_720_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_720_1.YAz2 = &fEM_R7UY00RSS;
  S_vchs_720_1.XCm = &fEM_R7UX04RSS;
  S_vchs_720_1.YCm = &fEM_R7UY04RSS;
  S_vchs_720_1.Ak = &fEM_A0UX04RSS;
  S_vchs_720_1.Bk = &fEM_B0UX04RSS;
  S_vchs_720_1.Fk = &fEM_R0UH01RSS;
  S_vchs_720_1.FMax = &fEM_R0UH21RSS;
  S_vchs_720_1.Reff = &fEM_A0UX00RSS;
  S_vchs_711_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_711_1.YAz2 = &fEM_R7UY00RSS;
  S_vchs_711_1.XCm = &fEM_R7UC10RIM;
  S_vchs_711_1.YCm = &fEM_R7UC19RIM;
  S_vchs_711_1.Ak = &fEM_A0UX03RSS;
  S_vchs_711_1.Bk = &fEM_B0UX03RSS;
  S_vchs_711_1.Fk = &fEM_R0UH03RSS;
  S_vchs_711_1.FMax = &fEM_R0UH23RSS;
  S_vchs_711_1.Reff = &fEM_A0UX00RSS;
  S_vchs_702_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_702_1.YAz2 = &fEM_R7UY00RSS;
  S_vchs_702_1.XCm = &fEM_R7UX02RSS;
  S_vchs_702_1.YCm = &fEM_R7UY02RSS;
  S_vchs_702_1.Ak = &fEM_A0UX02RSS;
  S_vchs_702_1.Bk = &fEM_B0UX02RSS;
  S_vchs_702_1.Fk = &fEM_R0UH02RSS;
  S_vchs_702_1.FMax = &fEM_R0UH22RSS;
  S_vchs_702_1.Reff = &fEM_A0UX00RSS;
  S_fsumo_886_1.x1 = &fEM_R4UC10RIM;
  S_fsumo_886_1.x2 = &fEM_R4UC22RIM;
  S_vchs_692_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_692_1.YAz2 = &fEM_R7UY00RSS;
  S_vchs_692_1.XCm = &fEM_R7UX01RSS;
  S_vchs_692_1.YCm = &fEM_R7UY01RSS;
  S_vchs_692_1.Ak = &fEM_A0UX01RSS;
  S_vchs_692_1.Bk = &fEM_B0UX01RSS;
  S_vchs_692_1.Fk = &fEM_R0UH01RSS;
  S_vchs_692_1.FMax = &fEM_R0UH21RSS;
  S_vchs_692_1.Reff = &fEM_A0UX00RSS;
  S_asmot_570_1.XYvk = &fEM_B5MC01RC1;
  S_asmot_570_1.Vzvk = &fEM_B5MV01RC1;
  S_asmot_570_1.Ter = &iEM_TERNL2;
  S_asmot_570_1.KPav = &fEM_A5UC10RIM;
  S_asmot_570_1.X0 = &fEM_B5MC01RSP;
  S_asmot_556_1.XYvk = &fEM_A5MC01RC1;
  S_asmot_556_1.Vzvk = &fEM_A5MV01RC1;
  S_asmot_556_1.Ter = &iEM_TERNL1;
  S_asmot_556_1.KPav = &fEM_A5UC10RIM;
  S_asmot_556_1.X0 = &fEM_A5MC01RSP;
  S_asmot_447_1.XYvk = &fEM_R2MC01RC1;
  S_asmot_447_1.Vzvk = &fEM_R2MV01RC1;
  S_asmot_447_1.Ter = &iEM_TERMDZ2;
  S_asmot_447_1.KPav = &fEM_R1UC10RIM;
  S_asmot_447_1.X0 = &fEM_R2MC01RSP;
  S_asmot_433_1.XYvk = &fEM_R1MC01RC1;
  S_asmot_433_1.Vzvk = &fEM_R1MV01RC1;
  S_asmot_433_1.Ter = &iEM_TERMDZ1;
  S_asmot_433_1.KPav = &fEM_R1UC10RIM;
  S_asmot_433_1.X0 = &fEM_R1MC01RSP;
  S_asmot_484_1.XYvk = &fEM_B6MC01RC1;
  S_asmot_484_1.Vzvk = &fEM_B6MV01RC1;
  S_asmot_484_1.Tp = &fEM_A6US80RDU;
  S_asmot_484_1.Ter = &iEM_TERBZ2;
  S_asmot_484_1.KPav = &fEM_A6UC10RIM;
  S_asmot_484_1.X0 = &fEM_B6MC01RSP;
  S_asmot_385_1.XYvk = &fEM_A6MC01RC1;
  S_asmot_385_1.Vzvk = &fEM_A6MV01RC1;
  S_asmot_385_1.Tp = &fEM_A6US80RDU;
  S_asmot_385_1.Ter = &iEM_TERBZ1;
  S_asmot_385_1.KPav = &fEM_A6UC10RIM;
  S_asmot_385_1.X0 = &fEM_A6MC01RSP;
  S_asmot_370_1.XYvk = &fEM_A8MC01RC1;
  S_asmot_370_1.Vzvk = &fEM_A8MV01RC1;
  S_asmot_370_1.Vm = &fEM_A8UV80RDU;
  S_asmot_370_1.Tp = &fEM_A8US80RDU;
  S_asmot_370_1.Ter = &iEM_TERDS2;
  S_asmot_370_1.KPav = &fEM_A8UC10RIM;
  S_asmot_370_1.KZav = &fEM_A8UC20RIM;
  S_asmot_370_1.KPv = &fEM_A8UC11RIM;
  S_asmot_370_1.KZv = &fEM_A8UC21RIM;
  S_asmot_370_1.Dlt = &fEM_A8UC08RDU;
  S_asmot_370_1.X0 = &fEM_A8MC01RSP;
  S_asmot_354_1.XYvk = &fEM_B8MC01RC1;
  S_asmot_354_1.Vzvk = &fEM_B8MV01RC1;
  S_asmot_354_1.Vm = &fEM_B8UV80RDU;
  S_asmot_354_1.Tp = &fEM_B8US80RDU;
  S_asmot_354_1.Ter = &iEM_TERMAZ2;
  S_asmot_354_1.KPav = &fEM_B8UC10RIM;
  S_asmot_354_1.KZav = &fEM_B8UC20RIM;
  S_asmot_354_1.KPv = &fEM_B8UC11RIM;
  S_asmot_354_1.KZv = &fEM_B8UC21RIM;
  S_asmot_354_1.Dlt = &fEM_B8UC08RDU;
  S_asmot_354_1.X0 = &fEM_B8MC01RSP;
  S_asmot_882_1.XYvk = &fEM_R4MC01RC1;
  S_asmot_882_1.Vzvk = &fEM_R4MV01RC1;
  S_asmot_882_1.Vm = &fEM_R4UV80RDU;
  S_asmot_882_1.Tp = &fEM_R4US80RDU;
  S_asmot_882_1.Ter = &iEM_TERTLG;
  S_asmot_882_1.KPav = &fEM_R4UC10RIM;
  S_asmot_882_1.KZav = &fEM_R4UC20RIM;
  S_asmot_882_1.KPv = &fEM_R4UC10RIM;
  S_asmot_882_1.KZv = &fEM_R4UC20RIM;
  S_asmot_882_1.Dlt = &fEM_R4UC08RDU;
  S_asmot_882_1.X0 = &fEM_R4MC01RSP;
  S_azbars_176_1.RIt = &fEM_R0UR30RIM;
  S_azbars_176_1.IsANI = &lEM_R8AD10LC1;
  S_azbars_176_1.Lg = &fEM_R0UL01RIM;
  S_azbars_176_1.Bz = &fEM_R0UN02RIM;
  S_azbars_176_1.AT = &fEM_R0UT01RIM;
  S_azbars_176_1.MT = &fEM_R0UT02RIM;
  S_azbars_176_1.CT = &fEM_R0UT04RIM;
  S_azbars_176_1.EN = &fEM_R0UT05RIM;
  S_azbars_176_1.EVt = &fEM_R0UH05RSS;
  S_azbars_176_1.Sani = &fEM_A0UN02RIM;
  S_azbars_176_1.Sno = &fEM_A0UN01RIM;
  S_azbars_176_1.ABB0 = &fEM_A1UR00RIM;
  S_azbars_176_1.ABB1 = &fEM_A1UR01RIM;
  S_azbars_176_1.ARB0 = &fEM_A2UR00RIM;
  S_azbars_176_1.ARB1 = &fEM_A2UR01RIM;
  S_azbars_176_1.AIS0 = &fEM_A3UR00RIM;
  S_azbars_176_1.AIS1 = &fEM_A3UR01RIM;
  S_azbars_176_1.Tn0 = &fEM_R0UT03RIM;
  S_azbars_176_1.RBlow = &fEM_R0UT06RIM;
  S_azbars_176_1.N0 = &fEM_A0UR02RSP;
  S_azbars_176_1.R0 = &fEM_A0UR01RSP;
  S_azbars_176_1.T0 = &fEM_B0UT03RSP;
  S_orrsim_290_1.Xk = &fEM_B3MC01RC1;
  S_orrsim_290_1.Shk = &fEM_B3MC02RC1;
  S_orrsim_290_1.IRV = &fEM_B3MV01RC1;
  S_orrsim_290_1.IShV = &fEM_B3MV02RC1;
  S_orrsim_290_1.Kpr = &fEM_A3UC02RDU;
  S_orrsim_290_1.Pdw = &fEM_A3UP01RIM;
  S_orrsim_290_1.Ldemp = &fEM_A3UG01RDU;
  S_orrsim_290_1.Tau = &fEM_A3US07RDU;
  S_orrsim_290_1.Aps = &fEM_A3UV02RIM;
  S_orrsim_290_1.Ter = &iEM_TERIS2;
  S_orrsim_290_1.KPpv = &fEM_A3UC04RIM;
  S_orrsim_290_1.KPav = &fEM_A3UC05RIM;
  S_orrsim_290_1.KZav = &fEM_A3UC06RIM;
  S_orrsim_290_1.Dlt = &fEM_A3UC08RIM;
  S_orrsim_290_1.X0 = &fEM_B3MC01RSP;
  S_orrsim_290_1.Sh0 = &fEM_B3MC02RSP;
  S_orrsim_126_1.Xk = &fEM_A3MC01RC1;
  S_orrsim_126_1.Shk = &fEM_A3MC02RC1;
  S_orrsim_126_1.IRV = &fEM_A3MV01RC1;
  S_orrsim_126_1.IShV = &fEM_A3MV02RC1;
  S_orrsim_126_1.Kpr = &fEM_A3UC02RDU;
  S_orrsim_126_1.Pdw = &fEM_A3UP01RIM;
  S_orrsim_126_1.Ldemp = &fEM_A3UG01RDU;
  S_orrsim_126_1.Tau = &fEM_A3US07RDU;
  S_orrsim_126_1.Aps = &fEM_A3UV02RIM;
  S_orrsim_126_1.Ter = &iEM_TERIS1;
  S_orrsim_126_1.KPpv = &fEM_A3UC04RIM;
  S_orrsim_126_1.KPav = &fEM_A3UC05RIM;
  S_orrsim_126_1.KZav = &fEM_A3UC06RIM;
  S_orrsim_126_1.Dlt = &fEM_A3UC08RIM;
  S_orrsim_126_1.X0 = &fEM_A3MC01RSP;
  S_orrsim_126_1.Sh0 = &fEM_A3MC02RSP;
  S_orrsim_258_1.Xk = &fEM_B2MC01RC1;
  S_orrsim_258_1.Shk = &fEM_B2MC02RC1;
  S_orrsim_258_1.IRV = &fEM_B2MV01RC1;
  S_orrsim_258_1.IShV = &fEM_B2MV02RC1;
  S_orrsim_258_1.Kpr = &fEM_A2UC02RDU;
  S_orrsim_258_1.Pup = &fEM_A2UP02RIM;
  S_orrsim_258_1.Pdw = &fEM_A2UP01RIM;
  S_orrsim_258_1.Ldemp = &fEM_A2UG01RDU;
  S_orrsim_258_1.Tau = &fEM_A2US07RDU;
  S_orrsim_258_1.Aps = &fEM_A2UV02RIM;
  S_orrsim_258_1.Ter = &iEM_TERRB2;
  S_orrsim_258_1.KPpv = &fEM_A2UC04RIM;
  S_orrsim_258_1.KPav = &fEM_A2UC05RIM;
  S_orrsim_258_1.KZav = &fEM_A2UC06RIM;
  S_orrsim_258_1.Dlt = &fEM_A2UC08RIM;
  S_orrsim_258_1.X0 = &fEM_B2MC01RSP;
  S_orrsim_258_1.Sh0 = &fEM_B2MC02RSP;
  S_orrsim_94_1.Xk = &fEM_A2MC01RC1;
  S_orrsim_94_1.Shk = &fEM_A2MC02RC1;
  S_orrsim_94_1.IRV = &fEM_A2MV01RC1;
  S_orrsim_94_1.IShV = &fEM_A2MV02RC1;
  S_orrsim_94_1.Kpr = &fEM_A2UC02RDU;
  S_orrsim_94_1.Pup = &fEM_A2UP02RIM;
  S_orrsim_94_1.Pdw = &fEM_A2UP01RIM;
  S_orrsim_94_1.Ldemp = &fEM_A2UG01RDU;
  S_orrsim_94_1.Tau = &fEM_A2US07RDU;
  S_orrsim_94_1.Aps = &fEM_A2UV02RIM;
  S_orrsim_94_1.Ter = &iEM_TERRB1;
  S_orrsim_94_1.KPpv = &fEM_A2UC04RIM;
  S_orrsim_94_1.KPav = &fEM_A2UC05RIM;
  S_orrsim_94_1.KZav = &fEM_A2UC06RIM;
  S_orrsim_94_1.Dlt = &fEM_A2UC08RIM;
  S_orrsim_94_1.X0 = &fEM_A2MC01RSP;
  S_orrsim_94_1.Sh0 = &fEM_A2MC02RSP;
  S_orrsim_223_1.Xk = &fEM_B1MC01RC1;
  S_orrsim_223_1.Shk = &fEM_B1MC02RC1;
  S_orrsim_223_1.IRV = &fEM_B1MV01RC1;
  S_orrsim_223_1.IShV = &fEM_B1MV02RC1;
  S_orrsim_223_1.Kpr = &fEM_A1UC02RDU;
  S_orrsim_223_1.Pdw = &fEM_A1UP01RIM;
  S_orrsim_223_1.Ldemp = &fEM_A1UG01RDU;
  S_orrsim_223_1.Tau = &fEM_A1US07RDU;
  S_orrsim_223_1.Aps = &fEM_A1UV02RIM;
  S_orrsim_223_1.Ter = &iEM_TERBB2;
  S_orrsim_223_1.KPpv = &fEM_A1UC04RIM;
  S_orrsim_223_1.KPav = &fEM_A1UC05RIM;
  S_orrsim_223_1.KZav = &fEM_A1UC06RIM;
  S_orrsim_223_1.Dlt = &fEM_A1UC08RIM;
  S_orrsim_223_1.X0 = &fEM_B1MC01RSP;
  S_orrsim_223_1.Sh0 = &fEM_B1MC02RSP;
  S_orrsim_59_1.Xk = &fEM_A1MC01RC1;
  S_orrsim_59_1.Shk = &fEM_A1MC02RC1;
  S_orrsim_59_1.IRV = &fEM_A1MV01RC1;
  S_orrsim_59_1.IShV = &fEM_A1MV02RC1;
  S_orrsim_59_1.Kpr = &fEM_A1UC02RDU;
  S_orrsim_59_1.Pdw = &fEM_A1UP01RIM;
  S_orrsim_59_1.Ldemp = &fEM_A1UG01RDU;
  S_orrsim_59_1.Tau = &fEM_A1US07RDU;
  S_orrsim_59_1.Aps = &fEM_A1UV02RIM;
  S_orrsim_59_1.Ter = &iEM_TERBB1;
  S_orrsim_59_1.KPpv = &fEM_A1UC04RIM;
  S_orrsim_59_1.KPav = &fEM_A1UC05RIM;
  S_orrsim_59_1.KZav = &fEM_A1UC06RIM;
  S_orrsim_59_1.Dlt = &fEM_A1UC08RIM;
  S_orrsim_59_1.X0 = &fEM_A1MC01RSP;
  S_orrsim_59_1.Sh0 = &fEM_A1MC02RSP;
  S_azbars_14_1.RIt = &fEM_R0UR30RIM;
  S_azbars_14_1.IsANI = &lEM_R8AD10LC1;
  S_azbars_14_1.Lg = &fEM_R0UL01RIM;
  S_azbars_14_1.Bz = &fEM_R0UN02RIM;
  S_azbars_14_1.AT = &fEM_R0UT01RIM;
  S_azbars_14_1.MT = &fEM_R0UT02RIM;
  S_azbars_14_1.CT = &fEM_R0UT04RIM;
  S_azbars_14_1.EN = &fEM_R0UT05RIM;
  S_azbars_14_1.EVt = &fEM_R0UH05RSS;
  S_azbars_14_1.Sani = &fEM_A0UN02RIM;
  S_azbars_14_1.Sno = &fEM_A0UN01RIM;
  S_azbars_14_1.ABB0 = &fEM_A1UR00RIM;
  S_azbars_14_1.ABB1 = &fEM_A1UR01RIM;
  S_azbars_14_1.ARB0 = &fEM_A2UR00RIM;
  S_azbars_14_1.ARB1 = &fEM_A2UR01RIM;
  S_azbars_14_1.AIS0 = &fEM_A3UR00RIM;
  S_azbars_14_1.AIS1 = &fEM_A3UR01RIM;
  S_azbars_14_1.Tn0 = &fEM_R0UT03RIM;
  S_azbars_14_1.RBlow = &fEM_R0UT06RIM;
  S_azbars_14_1.N0 = &fEM_A0UR02RSP;
  S_azbars_14_1.R0 = &fEM_A0UR01RSP;
  S_azbars_14_1.T0 = &fEM_A0UT03RSP;
  for( i=0;i<6;i++ )
    array_m176_C0_1[i] = &(&internal1_m176_C0)[i];
  for( i=0;i<6;i++ )
    array_m14_C0_1[i] = &(&internal1_m14_C0)[i];
  array_m345_x_1[0] = &lEM_R8AD10LC1;
  array_m345_x_1[1] = &lEM_R8AD10LC1;
  array_m895_x_1[0] = &lEM_R0IE02LRP;
  array_m895_x_1[1] = &lEM_R0IE01LRP;
  array_m614_x_1[0] = &lEM_C1AD31LRP;
  array_m290_Vr_1[1] = &fEM_R0UV81RDU;
  array_m290_Vr_1[2] = &fEM_R0UV82RDU;
  array_m290_Vr_1[3] = &fEM_R0UV83RDU;
  array_m290_Vr_1[4] = &fEM_R0UV84RDU;
  array_m290_Vr_1[5] = &fEM_R0UV85RDU;
  array_m290_Vr_1[6] = &fEM_R0UV86RDU;
  array_m290_Vr_1[7] = &fEM_R0UV87RDU;
  array_m126_Vr_1[1] = &fEM_R0UV81RDU;
  array_m126_Vr_1[2] = &fEM_R0UV82RDU;
  array_m126_Vr_1[3] = &fEM_R0UV83RDU;
  array_m126_Vr_1[4] = &fEM_R0UV84RDU;
  array_m126_Vr_1[5] = &fEM_R0UV85RDU;
  array_m126_Vr_1[6] = &fEM_R0UV86RDU;
  array_m126_Vr_1[7] = &fEM_R0UV87RDU;
  array_m258_Vr_1[1] = &fEM_R0UV81RDU;
  array_m258_Vr_1[2] = &fEM_R0UV82RDU;
  array_m258_Vr_1[3] = &fEM_R0UV83RDU;
  array_m258_Vr_1[4] = &fEM_R0UV84RDU;
  array_m258_Vr_1[5] = &fEM_R0UV85RDU;
  array_m258_Vr_1[6] = &fEM_R0UV86RDU;
  array_m258_Vr_1[7] = &fEM_R0UV87RDU;
  array_m94_Vr_1[1] = &fEM_R0UV81RDU;
  array_m94_Vr_1[2] = &fEM_R0UV82RDU;
  array_m94_Vr_1[3] = &fEM_R0UV83RDU;
  array_m94_Vr_1[4] = &fEM_R0UV84RDU;
  array_m94_Vr_1[5] = &fEM_R0UV85RDU;
  array_m94_Vr_1[6] = &fEM_R0UV86RDU;
  array_m94_Vr_1[7] = &fEM_R0UV87RDU;
  array_m223_Vr_1[1] = &fEM_R0UV81RDU;
  array_m223_Vr_1[2] = &fEM_R0UV82RDU;
  array_m223_Vr_1[3] = &fEM_R0UV83RDU;
  array_m223_Vr_1[4] = &fEM_R0UV84RDU;
  array_m223_Vr_1[5] = &fEM_R0UV85RDU;
  array_m223_Vr_1[6] = &fEM_R0UV86RDU;
  array_m223_Vr_1[7] = &fEM_R0UV87RDU;
  array_m59_Vr_1[1] = &fEM_R0UV81RDU;
  array_m59_Vr_1[2] = &fEM_R0UV82RDU;
  array_m59_Vr_1[3] = &fEM_R0UV83RDU;
  array_m59_Vr_1[4] = &fEM_R0UV84RDU;
  array_m59_Vr_1[5] = &fEM_R0UV85RDU;
  array_m59_Vr_1[6] = &fEM_R0UV86RDU;
  array_m59_Vr_1[7] = &fEM_R0UV87RDU;
}
