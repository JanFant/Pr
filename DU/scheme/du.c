#include "du.h"
extern  func_ext1();
// АП
//  Результат трансляции схемы D:\md\pti\pr\DU\scheme\du.tpr

#define PBLENGTH 8192
#ifndef SIMUL_MODE
char EEPROMType = 2;/*0 - absent, 1 - external, 2 - internal, 3 - misc*/
#else
char *SchemaName = "D:\md\pti\pr\DU\scheme\du.tpr";
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
#include <abs_subf.h>
#include <and2.h>
#include <and3.h>
#include <and4.h>
#include <and5.h>
#include <andn.h>
#include <bol.h>
#include <bolz.h>
#include <charint.h>
#include <cnshd.h>
#include <cntch.h>
#include <decatron.h>
#include <drg.h>
#include <enctkb.h>
#include <equz_p.h>
#include <fnapb.h>
#include <fsumo.h>
#include <fsumz.h>
#include <geterr.h>
#include <inf.h>
#include <irm.h>
#include <kvf.h>
#include <lk.h>
#include <lkb.h>
#include <ma.h>
#include <maz.h>
#include <ml.h>
#include <newstage.h>
#include <nocnm.h>
#include <noto.h>
#include <or2.h>
#include <or3.h>
#include <or4.h>
#include <or5.h>
#include <orn.h>
#include <ornc.h>
#include <orni.h>
#include <ovbs.h>
#include <provsbr.h>
#include <regch.h>
#include <rs.h>
#include <rsfn.h>
#include <rsun.h>
#include <samhd.h>
#include <scalzz.h>
#include <schl24.h>
#include <sr.h>
#include <swtakt.h>
#include <tprg.h>
#include <vmemb.h>
#include <zpfs.h>
#include <zzfs.h>

/* Определение внутренних параметров */
#define bFirstEnterFlag (*((psbool)(InternalBuf+0x0)))
#define internal2_m187_y0 (*((psfloat)(InternalBuf+0x2))) /*y0*/
#define internal2_m185_y0 (*((psfloat)(InternalBuf+0x7))) /*y0*/
#define internal2_m214_y0 (*((psbool)(InternalBuf+0xC))) /*state*/
#define internal2_m210_y0 (*((psbool)(InternalBuf+0xE))) /*state*/
#define internal2_m199_y1 (*((psbool)(InternalBuf+0x10))) /*y1 - внутренний параметр*/
#define internal2_m204_y1 (*((psbool)(InternalBuf+0x12))) /*y1 - внутренний параметр*/
#define internal2_m189_y1 (*((psbool)(InternalBuf+0x14))) /*y1 - внутренний параметр*/
#define internal2_m196_y1 (*((psbool)(InternalBuf+0x16))) /*y1 - внутренний параметр*/
#define internal2_m16_Nk0 (*((pslong)(InternalBuf+0x18))) /*Nk0 - предыдущее показание энкодера, в тиках*/
#define internal2_m16_SetFlag (*((psbool)(InternalBuf+0x1D))) /*SetFlag - признак записи смещения в ЭСППЗУ*/
#define internal2_m108_Nk0 (*((pslong)(InternalBuf+0x1F))) /*Nk0 - предыдущее показание энкодера, в тиках*/
#define internal2_m108_SetFlag (*((psbool)(InternalBuf+0x24))) /*SetFlag - признак записи смещения в ЭСППЗУ*/
#define internal2_m112_Nk0 (*((pslong)(InternalBuf+0x26))) /*Nk0 - предыдущее показание энкодера, в тиках*/
#define internal2_m112_SetFlag (*((psbool)(InternalBuf+0x2B))) /*SetFlag - признак записи смещения в ЭСППЗУ*/
#define internal2_m75_Nk0 (*((pslong)(InternalBuf+0x2D))) /*Nk0 - предыдущее показание энкодера, в тиках*/
#define internal2_m75_SetFlag (*((psbool)(InternalBuf+0x32))) /*SetFlag - признак записи смещения в ЭСППЗУ*/
#define internal2_m77_Nk0 (*((pslong)(InternalBuf+0x34))) /*Nk0 - предыдущее показание энкодера, в тиках*/
#define internal2_m77_SetFlag (*((psbool)(InternalBuf+0x39))) /*SetFlag - признак записи смещения в ЭСППЗУ*/
#define internal2_m47_Nk0 (*((pslong)(InternalBuf+0x3B))) /*Nk0 - предыдущее показание энкодера, в тиках*/
#define internal2_m47_SetFlag (*((psbool)(InternalBuf+0x40))) /*SetFlag - признак записи смещения в ЭСППЗУ*/
#define internal2_m51_Nk0 (*((pslong)(InternalBuf+0x42))) /*Nk0 - предыдущее показание энкодера, в тиках*/
#define internal2_m51_SetFlag (*((psbool)(InternalBuf+0x47))) /*SetFlag - признак записи смещения в ЭСППЗУ*/
#define internal2_m21_Nk0 (*((pslong)(InternalBuf+0x49))) /*Nk0 - предыдущее показание энкодера, в тиках*/
#define internal2_m21_SetFlag (*((psbool)(InternalBuf+0x4E))) /*SetFlag - признак записи смещения в ЭСППЗУ*/
#define internal1_m2094_q0 (*((psbool)(InternalBuf+0x50))) /*q0 - внутренний параметр*/
#define internal1_m2078_q0 (*((psbool)(InternalBuf+0x52))) /*q0 - внутренний параметр*/
#define internal1_m2120_q0 (*((psbool)(InternalBuf+0x54))) /*q0 - внутренний параметр*/
#define internal1_m2104_q0 (*((psbool)(InternalBuf+0x56))) /*q0 - внутренний параметр*/
#define internal1_m2097_q0 (*((psbool)(InternalBuf+0x58))) /*q0 - внутренний параметр*/
#define internal1_m2080_q0 (*((psbool)(InternalBuf+0x5A))) /*q0 - внутренний параметр*/
#define internal1_m2096_q0 (*((psbool)(InternalBuf+0x5C))) /*q0 - внутренний параметр*/
#define internal1_m2079_q0 (*((psbool)(InternalBuf+0x5E))) /*q0 - внутренний параметр*/
#define internal1_m2077_q0 (*((psbool)(InternalBuf+0x60))) /*q0 - внутренний параметр*/
#define internal1_m2076_q0 (*((psbool)(InternalBuf+0x62))) /*q0 - внутренний параметр*/
#define internal1_m2090_q0 (*((psbool)(InternalBuf+0x64))) /*q0 - внутренний параметр*/
#define internal1_m2088_q0 (*((psbool)(InternalBuf+0x66))) /*q0 - внутренний параметр*/
#define internal1_m2095_q0 (*((psbool)(InternalBuf+0x68))) /*q0 - внутренний параметр*/
#define internal1_m2092_q0 (*((psbool)(InternalBuf+0x6A))) /*q0 - внутренний параметр*/
#define internal1_m2123_q0 (*((psbool)(InternalBuf+0x6C))) /*q0 - внутренний параметр*/
#define internal1_m2106_q0 (*((psbool)(InternalBuf+0x6E))) /*q0 - внутренний параметр*/
#define internal1_m2122_q0 (*((psbool)(InternalBuf+0x70))) /*q0 - внутренний параметр*/
#define internal1_m2105_q0 (*((psbool)(InternalBuf+0x72))) /*q0 - внутренний параметр*/
#define internal1_m2103_q0 (*((psbool)(InternalBuf+0x74))) /*q0 - внутренний параметр*/
#define internal1_m2102_q0 (*((psbool)(InternalBuf+0x76))) /*q0 - внутренний параметр*/
#define internal1_m2116_q0 (*((psbool)(InternalBuf+0x78))) /*q0 - внутренний параметр*/
#define internal1_m2114_q0 (*((psbool)(InternalBuf+0x7A))) /*q0 - внутренний параметр*/
#define internal1_m1997_tx (*((psfloat)(InternalBuf+0x7C))) /*tx - внутренний параметр*/
#define internal1_m1976_tx (*((psfloat)(InternalBuf+0x81))) /*tx - внутренний параметр*/
#define internal1_m1689_Pv0 (*((psbool)(InternalBuf+0x86))) /* - Пер. выключатель механизма*/
#define internal1_m1689_Zv0 (*((psbool)(InternalBuf+0x88))) /* - Зад. выключатель механизма*/
#define internal1_m1689_MyFirstEnterFlag (*((psbool)(InternalBuf+0x8A))) /*MyFirstEnterFlag*/
#define internal1_m1686_Pv0 (*((psbool)(InternalBuf+0x8C))) /* - Пер. выключатель механизма*/
#define internal1_m1686_Zv0 (*((psbool)(InternalBuf+0x8E))) /* - Зад. выключатель механизма*/
#define internal1_m1686_MyFirstEnterFlag (*((psbool)(InternalBuf+0x90))) /*MyFirstEnterFlag*/
#define internal1_m2138_tx (*((psfloat)(InternalBuf+0x92))) /*tx - время накопленное сек*/
#define internal1_m2138_y0 (*((pschar)(InternalBuf+0x97))) /*y0*/
#define internal1_m2143_tx (*((psfloat)(InternalBuf+0x99))) /*tx - время накопленное сек*/
#define internal1_m2143_y0 (*((pschar)(InternalBuf+0x9E))) /*y0*/
#define internal1_m2142_tx (*((psfloat)(InternalBuf+0xA0))) /*tx - время накопленное сек*/
#define internal1_m2142_y0 (*((pschar)(InternalBuf+0xA5))) /*y0*/
#define internal1_m2179_tx (*((psfloat)(InternalBuf+0xA7))) /*tx - внутренний параметр*/
#define internal1_m2177_tx (*((psfloat)(InternalBuf+0xAC))) /*tx - время накопленное сек*/
#define internal1_m2177_y0 (*((pschar)(InternalBuf+0xB1))) /*y0*/
#define internal1_m2182_q0 (*((psbool)(InternalBuf+0xB3))) /*q0 - внутренний параметр*/
#define internal1_m2149_q0 (*((psbool)(InternalBuf+0xB5))) /*q0 - внутренний параметр*/
#define internal1_m2157_tx (*((psfloat)(InternalBuf+0xB7))) /*tx - внутренний параметр*/
#define internal1_m2155_q0 (*((psbool)(InternalBuf+0xBC))) /*q0 - внутренний параметр*/
#define internal1_m1991_tx (*((psfloat)(InternalBuf+0xBE))) /*tx - время накопленное сек*/
#define internal1_m1991_y0 (*((pschar)(InternalBuf+0xC3))) /*y0*/
#define internal1_m1983_tx (*((psfloat)(InternalBuf+0xC5))) /*tx - время накопленное сек*/
#define internal1_m1983_y0 (*((pschar)(InternalBuf+0xCA))) /*y0*/
#define internal1_m1682_q0 (*((psbool)(InternalBuf+0xCC))) /*q0 - внутренний параметр*/
#define internal1_m1680_q0 (*((psbool)(InternalBuf+0xCE))) /*q0 - внутренний параметр*/
#define internal1_m1679_q0 (*((psbool)(InternalBuf+0xD0))) /*q0 - внутренний параметр*/
#define internal1_m1710_q0 (*((psbool)(InternalBuf+0xD2))) /*q0 - внутренний параметр*/
#define internal1_m739_tx (*((psfloat)(InternalBuf+0xD4))) /*tx - время накопленное сек*/
#define internal1_m739_y0 (*((pschar)(InternalBuf+0xD9))) /*y0*/
#define internal1_m1987_tx (*((psfloat)(InternalBuf+0xDB))) /*tx - внутренний параметр*/
#define internal1_m1990_q0 (*((psbool)(InternalBuf+0xE0))) /*q0 - внутренний параметр*/
#define internal1_m1982_q0 (*((psbool)(InternalBuf+0xE2))) /*q0 - внутренний параметр*/
#define internal1_m1952_tx (*((psfloat)(InternalBuf+0xE4))) /*tx - внутренний параметр*/
#define internal1_m1963_tx (*((psfloat)(InternalBuf+0xE9))) /*tx - внутренний параметр*/
#define internal1_m1949_tx (*((psfloat)(InternalBuf+0xEE))) /*tx - внутренний параметр*/
#define internal1_m1955_q0 (*((psbool)(InternalBuf+0xF3))) /*q0 - внутренний параметр*/
#define internal1_m1967_q0 (*((psbool)(InternalBuf+0xF5))) /*q0 - внутренний параметр*/
#define internal1_m1925_tx (*((psfloat)(InternalBuf+0xF7))) /*tx - внутренний параметр*/
#define internal1_m51_tx (*((psfloat)(InternalBuf+0xFC))) /*tx - внутренний параметр*/
#define internal1_m336_tx (*((psfloat)(InternalBuf+0x101))) /*tx - внутренний параметр*/
#define internal1_m291_tx (*((psfloat)(InternalBuf+0x106))) /*tx - внутренний параметр*/
#define internal1_m740_tx (*((psfloat)(InternalBuf+0x10B))) /*tx - внутренний параметр*/
#define internal1_m1405_tx (*((psfloat)(InternalBuf+0x110))) /*tx - внутренний параметр*/
#define internal1_m112_tx (*((psfloat)(InternalBuf+0x115))) /*tx - внутренний параметр*/
#define internal1_m114_tx (*((psfloat)(InternalBuf+0x11A))) /*tx - внутренний параметр*/
#define internal1_m119_tx (*((psfloat)(InternalBuf+0x11F))) /*tx - внутренний параметр*/
#define internal1_m21_tx (*((psfloat)(InternalBuf+0x124))) /*tx - внутренний параметр*/
#define internal1_m13_tx (*((psfloat)(InternalBuf+0x129))) /*tx - внутренний параметр*/
#define internal1_m1934_tx (*((psfloat)(InternalBuf+0x12E))) /*tx - внутренний параметр*/
#define internal1_m1922_tx (*((psfloat)(InternalBuf+0x133))) /*tx - внутренний параметр*/
#define internal1_m2030_tx (*((psfloat)(InternalBuf+0x138))) /*tx - внутренний параметр*/
#define internal1_m2034_tx (*((psfloat)(InternalBuf+0x13D))) /*tx - внутренний параметр*/
#define internal1_m1847_tx (*((psfloat)(InternalBuf+0x142))) /*tx - внутренний параметр*/
#define internal1_m76_tx (*((psfloat)(InternalBuf+0x147))) /*tx - внутренний параметр*/
#define internal1_m305_tx (*((psfloat)(InternalBuf+0x14C))) /*tx - время накопленное сек*/
#define internal1_m305_y0 (*((pschar)(InternalBuf+0x151))) /*y0*/
#define internal1_m1841_tx (*((psfloat)(InternalBuf+0x153))) /*tx - время накопленное сек*/
#define internal1_m1841_y0 (*((pschar)(InternalBuf+0x158))) /*y0*/
#define internal1_m1839_tx (*((psfloat)(InternalBuf+0x15A))) /*tx - время накопленное сек*/
#define internal1_m1839_y0 (*((pschar)(InternalBuf+0x15F))) /*y0*/
#define internal1_m1828_tx (*((psfloat)(InternalBuf+0x161))) /*tx - время накопленное сек*/
#define internal1_m1828_y0 (*((pschar)(InternalBuf+0x166))) /*y0*/
#define internal1_m1848_q0 (*((psfloat)(InternalBuf+0x168))) /*q0 - внутренний параметр*/
#define internal1_m1425_q0 (*((psfloat)(InternalBuf+0x16D))) /*q0 - внутренний параметр*/
#define internal1_m1463_q0 (*((psfloat)(InternalBuf+0x172))) /*q0 - внутренний параметр*/
#define internal1_m1466_q0 (*((psfloat)(InternalBuf+0x177))) /*q0 - внутренний параметр*/
#define internal1_m1887_q0 (*((psfloat)(InternalBuf+0x17C))) /*q0 - внутренний параметр*/
#define internal1_m1864_tx (*((psfloat)(InternalBuf+0x181))) /*tx - время накопленное сек*/
#define internal1_m1864_y0 (*((pschar)(InternalBuf+0x186))) /*y0*/
#define internal1_m1880_tx (*((psfloat)(InternalBuf+0x188))) /*tx - время накопленное сек*/
#define internal1_m1880_y0 (*((pschar)(InternalBuf+0x18D))) /*y0*/
#define internal1_m1877_tx (*((psfloat)(InternalBuf+0x18F))) /*tx - время накопленное сек*/
#define internal1_m1877_y0 (*((pschar)(InternalBuf+0x194))) /*y0*/
#define internal1_m2013_tx (*((psfloat)(InternalBuf+0x196))) /*tx - время накопленное сек*/
#define internal1_m2013_y0 (*((pschar)(InternalBuf+0x19B))) /*y0*/
#define internal1_m2024_tx (*((psfloat)(InternalBuf+0x19D))) /*tx - время накопленное сек*/
#define internal1_m2024_y0 (*((pschar)(InternalBuf+0x1A2))) /*y0*/
#define internal1_m1778_tx (*((psfloat)(InternalBuf+0x1A4))) /*tx - время накопленное сек*/
#define internal1_m1778_y0 (*((pschar)(InternalBuf+0x1A9))) /*y0*/
#define internal1_m1777_tx (*((psfloat)(InternalBuf+0x1AB))) /*tx - время накопленное сек*/
#define internal1_m1777_y0 (*((pschar)(InternalBuf+0x1B0))) /*y0*/
#define internal1_m1776_tx (*((psfloat)(InternalBuf+0x1B2))) /*tx - время накопленное сек*/
#define internal1_m1776_y0 (*((pschar)(InternalBuf+0x1B7))) /*y0*/
#define internal1_m1775_tx (*((psfloat)(InternalBuf+0x1B9))) /*tx - время накопленное сек*/
#define internal1_m1775_y0 (*((pschar)(InternalBuf+0x1BE))) /*y0*/
#define internal1_m1477_tx (*((psfloat)(InternalBuf+0x1C0))) /*tx - время накопленное сек*/
#define internal1_m1477_y0 (*((pschar)(InternalBuf+0x1C5))) /*y0*/
#define internal1_m1471_tx (*((psfloat)(InternalBuf+0x1C7))) /*tx - время накопленное сек*/
#define internal1_m1471_y0 (*((pschar)(InternalBuf+0x1CC))) /*y0*/
#define internal1_m1421_tx (*((psfloat)(InternalBuf+0x1CE))) /*tx - время накопленное сек*/
#define internal1_m1421_y0 (*((pschar)(InternalBuf+0x1D3))) /*y0*/
#define internal1_m823_tx (*((psfloat)(InternalBuf+0x1D5))) /*tx - время накопленное сек*/
#define internal1_m823_y0 (*((pschar)(InternalBuf+0x1DA))) /*y0*/
#define internal1_m820_tx (*((psfloat)(InternalBuf+0x1DC))) /*tx - время накопленное сек*/
#define internal1_m820_y0 (*((pschar)(InternalBuf+0x1E1))) /*y0*/
#define internal1_m827_tx (*((psfloat)(InternalBuf+0x1E3))) /*tx - время накопленное сек*/
#define internal1_m827_y0 (*((pschar)(InternalBuf+0x1E8))) /*y0*/
#define internal1_m186_tx (*((psfloat)(InternalBuf+0x1EA))) /*tx - время накопленное сек*/
#define internal1_m186_y0 (*((pschar)(InternalBuf+0x1EF))) /*y0*/
#define internal1_m190_tx (*((psfloat)(InternalBuf+0x1F1))) /*tx - время накопленное сек*/
#define internal1_m190_y0 (*((pschar)(InternalBuf+0x1F6))) /*y0*/
#define internal1_m197_tx (*((psfloat)(InternalBuf+0x1F8))) /*tx - время накопленное сек*/
#define internal1_m197_y0 (*((pschar)(InternalBuf+0x1FD))) /*y0*/
#define internal1_m516_tx (*((psfloat)(InternalBuf+0x1FF))) /*tx - время накопленное сек*/
#define internal1_m516_y0 (*((pschar)(InternalBuf+0x204))) /*y0*/
#define internal1_m2062_tx (*((psfloat)(InternalBuf+0x206))) /*tx - внутренний параметр*/
#define internal1_m1165_tx (*((psfloat)(InternalBuf+0x20B))) /*tx - внутренний параметр*/
#define internal1_m1591_tx (*((psfloat)(InternalBuf+0x210))) /*tx - время накопленное сек*/
#define internal1_m1591_y0 (*((pschar)(InternalBuf+0x215))) /*y0*/
#define internal1_m1131_tx (*((psfloat)(InternalBuf+0x217))) /*tx - время накопленное сек*/
#define internal1_m1131_y0 (*((pschar)(InternalBuf+0x21C))) /*y0*/
#define internal1_m1317_tx (*((psfloat)(InternalBuf+0x21E))) /*tx - время накопленное сек*/
#define internal1_m1317_y0 (*((pschar)(InternalBuf+0x223))) /*y0*/
#define internal1_m920_tx (*((psfloat)(InternalBuf+0x225))) /*tx - время накопленное сек*/
#define internal1_m920_y0 (*((pschar)(InternalBuf+0x22A))) /*y0*/
#define internal1_m1224_tx (*((psfloat)(InternalBuf+0x22C))) /*tx - время накопленное сек*/
#define internal1_m1224_y0 (*((pschar)(InternalBuf+0x231))) /*y0*/
#define internal1_m1072_q0 (*((psbool)(InternalBuf+0x233))) /*q0 - внутренний параметр*/
#define internal1_m1070_q0 (*((psbool)(InternalBuf+0x235))) /*q0 - внутренний параметр*/
#define internal1_m1069_q0 (*((psbool)(InternalBuf+0x237))) /*q0 - внутренний параметр*/
#define internal1_m1067_q0 (*((psbool)(InternalBuf+0x239))) /*q0 - внутренний параметр*/
#define internal1_m1066_q0 (*((psbool)(InternalBuf+0x23B))) /*q0 - внутренний параметр*/
#define internal1_m1064_q0 (*((psbool)(InternalBuf+0x23D))) /*q0 - внутренний параметр*/
#define internal1_m1063_q0 (*((psbool)(InternalBuf+0x23F))) /*q0 - внутренний параметр*/
#define internal1_m1061_q0 (*((psbool)(InternalBuf+0x241))) /*q0 - внутренний параметр*/
#define internal1_m1060_q0 (*((psbool)(InternalBuf+0x243))) /*q0 - внутренний параметр*/
#define internal1_m52_x0 (*((psbool)(InternalBuf+0x245))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m980_q0 (*((psbool)(InternalBuf+0x247))) /*q0 - внутренний параметр*/
#define internal1_m1414_x0 (*((psbool)(InternalBuf+0x249))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m1458_x0 (*((psbool)(InternalBuf+0x24B))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m1454_x0 (*((psbool)(InternalBuf+0x24D))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m1856_x0 (*((psbool)(InternalBuf+0x24F))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m1821_x0 (*((psbool)(InternalBuf+0x251))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m1019_q0 (*((psbool)(InternalBuf+0x253))) /*q0 - внутренний параметр*/
#define internal1_m1031_q0 (*((psbool)(InternalBuf+0x255))) /*q0 - внутренний параметр*/
#define internal1_m1043_q0 (*((psbool)(InternalBuf+0x257))) /*q0 - внутренний параметр*/
#define internal1_m1052_q0 (*((psbool)(InternalBuf+0x259))) /*q0 - внутренний параметр*/
#define internal1_m1030_q0 (*((psbool)(InternalBuf+0x25B))) /*q0 - внутренний параметр*/
#define internal1_m1045_q0 (*((psbool)(InternalBuf+0x25D))) /*q0 - внутренний параметр*/
#define internal1_m1914_q0 (*((psbool)(InternalBuf+0x25F))) /*q0 - внутренний параметр*/
#define internal1_m1913_q0 (*((psbool)(InternalBuf+0x261))) /*q0 - внутренний параметр*/
#define internal1_m324_Step (*((psint)(InternalBuf+0x263))) /* - текущий шаг программы*/
#define internal1_m324_rz (*((pschar)(InternalBuf+0x266))) /*- результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка*/
#define internal1_m324_TimS (*((psfloat)(InternalBuf+0x27A))) /*Время от старта программы*/
#define internal1_m324_FinPr0 (*((psbool)(InternalBuf+0x27F))) /*FinPr - конец программы*/
#define internal1_m324_ErrPr0 (*((psbool)(InternalBuf+0x281))) /*ErrPr - Приостановка программы по ошибке*/
#define internal1_m324_sbINI0 (*((psbool)(InternalBuf+0x283))) /*sbINI - запуск проверки ИНИ*/
#define internal1_m324_sbVuIS0 (*((psbool)(InternalBuf+0x285))) /*sbVuIS - запуск проверки сброса от ВУ ИС*/
#define internal1_m324_sb2UR0 (*((psbool)(InternalBuf+0x287))) /*sb2UR - запуск проверки сброса от 2УР*/
#define internal1_m324_sbNupIS0 (*((psbool)(InternalBuf+0x289))) /*sbNupIS - запуск проверки сброса от НУП ИС*/
#define internal1_m324_sbVuRB0 (*((psbool)(InternalBuf+0x28B))) /*sbVuRB - запуск проверки сброса от ВУ РБ*/
#define internal1_m324_MyFirstEnterFlag (*((psbool)(InternalBuf+0x28D))) /* */
#define internal1_m332_x0 (*((pslong)(InternalBuf+0x28F))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m290_TimS (*((pslong)(InternalBuf+0x294))) /*Время старта*/
#define internal1_m267_Step (*((psint)(InternalBuf+0x299))) /* - текущий шаг программы*/
#define internal1_m267_rz (*((pschar)(InternalBuf+0x29C))) /*- результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка*/
#define internal1_m267_TimS (*((psfloat)(InternalBuf+0x2B0))) /*Время от старта программы*/
#define internal1_m267_FinPr0 (*((psbool)(InternalBuf+0x2B5))) /*FinPr - конец программы*/
#define internal1_m267_ErrPr0 (*((psbool)(InternalBuf+0x2B7))) /*ErrPr - Приостановка программы по ошибке*/
#define internal1_m267_sbINI0 (*((psbool)(InternalBuf+0x2B9))) /*sbINI - запуск проверки ИНИ*/
#define internal1_m267_sbVuIS0 (*((psbool)(InternalBuf+0x2BB))) /*sbVuIS - запуск проверки сброса от ВУ ИС*/
#define internal1_m267_sb2UR0 (*((psbool)(InternalBuf+0x2BD))) /*sb2UR - запуск проверки сброса от 2УР*/
#define internal1_m267_sbNupIS0 (*((psbool)(InternalBuf+0x2BF))) /*sbNupIS - запуск проверки сброса от НУП ИС*/
#define internal1_m267_sbVuRB0 (*((psbool)(InternalBuf+0x2C1))) /*sbVuRB - запуск проверки сброса от ВУ РБ*/
#define internal1_m267_MyFirstEnterFlag (*((psbool)(InternalBuf+0x2C3))) /* */
#define internal1_m1388_q0 (*((psbool)(InternalBuf+0x2C5))) /*q0 - внутренний параметр*/
#define internal1_m1389_Step (*((psint)(InternalBuf+0x2C7))) /* - текущий шаг программы*/
#define internal1_m1389_rz (*((pschar)(InternalBuf+0x2CA))) /*- результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка*/
#define internal1_m1389_TimS (*((psfloat)(InternalBuf+0x2D6))) /*Время от старта программы*/
#define internal1_m1389_FinPr0 (*((psbool)(InternalBuf+0x2DB))) /*FinPr - конец программы*/
#define internal1_m1389_ErrPr0 (*((psbool)(InternalBuf+0x2DD))) /*ErrPr - Приостановка программы по ошибке*/
#define internal1_m1389_sbINI0 (*((psbool)(InternalBuf+0x2DF))) /*sbINI - запуск проверки ИНИ*/
#define internal1_m1389_sbVuIS0 (*((psbool)(InternalBuf+0x2E1))) /*sbVuIS - запуск проверки сброса от ВУ ИС*/
#define internal1_m1389_sb2UR0 (*((psbool)(InternalBuf+0x2E3))) /*sb2UR - запуск проверки сброса от 2УР*/
#define internal1_m1389_sbNupIS0 (*((psbool)(InternalBuf+0x2E5))) /*sbNupIS - запуск проверки сброса от НУП ИС*/
#define internal1_m1389_sbVuRB0 (*((psbool)(InternalBuf+0x2E7))) /*sbVuRB - запуск проверки сброса от ВУ РБ*/
#define internal1_m1389_MyFirstEnterFlag (*((psbool)(InternalBuf+0x2E9))) /* */
#define internal1_m1014_q0 (*((psbool)(InternalBuf+0x2EB))) /*q0 - внутренний параметр*/
#define internal1_m1011_q0 (*((psbool)(InternalBuf+0x2ED))) /*q0 - внутренний параметр*/
#define internal1_m1013_q0 (*((psbool)(InternalBuf+0x2EF))) /*q0 - внутренний параметр*/
#define internal1_m1008_q0 (*((psbool)(InternalBuf+0x2F1))) /*q0 - внутренний параметр*/
#define internal1_m741_q0 (*((psbool)(InternalBuf+0x2F3))) /*q0 - внутренний параметр*/
#define internal1_m334_q0 (*((psbool)(InternalBuf+0x2F5))) /*q0 - внутренний параметр*/
#define internal1_m330_q0 (*((psbool)(InternalBuf+0x2F7))) /*q0 - внутренний параметр*/
#define internal1_m287_q0 (*((psbool)(InternalBuf+0x2F9))) /*q0 - внутренний параметр*/
#define internal1_m286_x0 (*((pslong)(InternalBuf+0x2FB))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m1843_q0 (*((psbool)(InternalBuf+0x300))) /*q0 - внутренний параметр*/
#define internal1_m1831_q0 (*((psbool)(InternalBuf+0x302))) /*q0 - внутренний параметр*/
#define internal1_m1822_q0 (*((psbool)(InternalBuf+0x304))) /*q0 - внутренний параметр*/
#define internal1_m1897_q0 (*((psbool)(InternalBuf+0x306))) /*q0 - внутренний параметр*/
#define internal1_m1867_q0 (*((psbool)(InternalBuf+0x308))) /*q0 - внутренний параметр*/
#define internal1_m1857_q0 (*((psbool)(InternalBuf+0x30A))) /*q0 - внутренний параметр*/
#define internal1_m1441_q0 (*((psbool)(InternalBuf+0x30C))) /*q0 - внутренний параметр*/
#define internal1_m1428_x0 (*((psbool)(InternalBuf+0x30E))) /*был приход сигнала x1*/
#define internal1_m1428_y0 (*((psfloat)(InternalBuf+0x310))) /*интервал между сигналами х1 и х2*/
#define internal1_m1424_q0 (*((psbool)(InternalBuf+0x315))) /*q0 - внутренний параметр*/
#define internal1_m1415_q0 (*((psbool)(InternalBuf+0x317))) /*q0 - внутренний параметр*/
#define internal1_m1474_q0 (*((psbool)(InternalBuf+0x319))) /*q0 - внутренний параметр*/
#define internal1_m1494_q0 (*((psbool)(InternalBuf+0x31B))) /*q0 - внутренний параметр*/
#define internal1_m1460_q0 (*((psbool)(InternalBuf+0x31D))) /*q0 - внутренний параметр*/
#define internal1_m1475_x0 (*((psbool)(InternalBuf+0x31F))) /*был приход сигнала x1*/
#define internal1_m1475_y0 (*((psfloat)(InternalBuf+0x321))) /*интервал между сигналами х1 и х2*/
#define internal1_m1399_x0 (*((pslong)(InternalBuf+0x326))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m1480_q0 (*((psbool)(InternalBuf+0x32B))) /*q0 - внутренний параметр*/
#define internal1_m26_q0 (*((psbool)(InternalBuf+0x32D))) /*q0 - внутренний параметр*/
#define internal1_m1495_q0 (*((psbool)(InternalBuf+0x32F))) /*q0 - внутренний параметр*/
#define internal1_m631_q0 (*((psbool)(InternalBuf+0x331))) /*q0 - внутренний параметр*/
#define internal1_m616_q0 (*((psbool)(InternalBuf+0x333))) /*q0 - внутренний параметр*/
#define internal1_m642_q0 (*((psbool)(InternalBuf+0x335))) /*q0 - внутренний параметр*/
#define internal1_m627_q0 (*((psbool)(InternalBuf+0x337))) /*q0 - внутренний параметр*/
#define internal1_m611_q0 (*((psbool)(InternalBuf+0x339))) /*q0 - внутренний параметр*/
#define internal1_m609_q0 (*((psbool)(InternalBuf+0x33B))) /*q0 - внутренний параметр*/
#define internal1_m597_q0 (*((psbool)(InternalBuf+0x33D))) /*q0 - внутренний параметр*/
#define internal1_m1391_q0 (*((pslong)(InternalBuf+0x33F))) /*q0 - внутренний параметр*/
#define internal1_m607_q0 (*((psbool)(InternalBuf+0x344))) /*q0 - внутренний параметр*/
#define internal1_m108_q0 (*((psbool)(InternalBuf+0x346))) /*q0 - внутренний параметр*/
#define internal1_m1625_q0 (*((psbool)(InternalBuf+0x348))) /*q0 - внутренний параметр*/
#define internal1_m1624_q0 (*((psbool)(InternalBuf+0x34A))) /*q0 - внутренний параметр*/
#define internal1_m1623_q0 (*((psbool)(InternalBuf+0x34C))) /*q0 - внутренний параметр*/
#define internal1_m1622_q0 (*((psbool)(InternalBuf+0x34E))) /*q0 - внутренний параметр*/
#define internal1_m1651_q0 (*((psbool)(InternalBuf+0x350))) /*q0 - внутренний параметр*/
#define internal1_m1650_q0 (*((psbool)(InternalBuf+0x352))) /*q0 - внутренний параметр*/
#define internal1_m1649_q0 (*((psbool)(InternalBuf+0x354))) /*q0 - внутренний параметр*/
#define internal1_m1648_q0 (*((psbool)(InternalBuf+0x356))) /*q0 - внутренний параметр*/
#define internal1_m1928_q0 (*((psbool)(InternalBuf+0x358))) /*q0 - внутренний параметр*/
#define internal1_m1708_q0 (*((psbool)(InternalBuf+0x35A))) /*q0 - внутренний параметр*/
#define internal1_m1707_q0 (*((psbool)(InternalBuf+0x35C))) /*q0 - внутренний параметр*/
#define internal1_m1705_q0 (*((psbool)(InternalBuf+0x35E))) /*q0 - внутренний параметр*/
#define internal1_m1704_q0 (*((psbool)(InternalBuf+0x360))) /*q0 - внутренний параметр*/
#define internal1_m1702_q0 (*((psbool)(InternalBuf+0x362))) /*q0 - внутренний параметр*/
#define internal1_m2121_q0 (*((psbool)(InternalBuf+0x364))) /*q0 - внутренний параметр*/
#define internal1_m2118_q0 (*((psbool)(InternalBuf+0x366))) /*q0 - внутренний параметр*/
#define internal1_m1677_q0 (*((psbool)(InternalBuf+0x368))) /*q0 - внутренний параметр*/
#define internal1_m1671_q0 (*((psbool)(InternalBuf+0x36A))) /*q0 - внутренний параметр*/
#define internal1_m1670_q0 (*((psbool)(InternalBuf+0x36C))) /*q0 - внутренний параметр*/
#define internal1_m1666_q0 (*((psbool)(InternalBuf+0x36E))) /*q0 - внутренний параметр*/
#define internal1_m1668_q0 (*((psbool)(InternalBuf+0x370))) /*q0 - внутренний параметр*/
#define internal1_m1665_q0 (*((psbool)(InternalBuf+0x372))) /*q0 - внутренний параметр*/
#define internal1_m1664_q0 (*((psbool)(InternalBuf+0x374))) /*q0 - внутренний параметр*/
#define internal1_m1660_q0 (*((psbool)(InternalBuf+0x376))) /*q0 - внутренний параметр*/
#define internal1_m1662_q0 (*((psbool)(InternalBuf+0x378))) /*q0 - внутренний параметр*/
#define internal1_m19_q0 (*((psbool)(InternalBuf+0x37A))) /*q0 - внутренний параметр*/
#define internal1_m1645_q0 (*((psbool)(InternalBuf+0x37C))) /*q0 - внутренний параметр*/
#define internal1_m1643_q0 (*((psbool)(InternalBuf+0x37E))) /*q0 - внутренний параметр*/
#define internal1_m1640_q0 (*((psbool)(InternalBuf+0x380))) /*q0 - внутренний параметр*/
#define internal1_m1642_q0 (*((psbool)(InternalBuf+0x382))) /*q0 - внутренний параметр*/
#define internal1_m1639_q0 (*((psbool)(InternalBuf+0x384))) /*q0 - внутренний параметр*/
#define internal1_m1637_q0 (*((psbool)(InternalBuf+0x386))) /*q0 - внутренний параметр*/
#define internal1_m2044_q0 (*((psbool)(InternalBuf+0x388))) /*q0 - внутренний параметр*/
#define internal1_m2039_q0 (*((psbool)(InternalBuf+0x38A))) /*q0 - внутренний параметр*/
#define internal1_m2018_q0 (*((psbool)(InternalBuf+0x38C))) /*q0 - внутренний параметр*/
#define internal1_m2006_q0 (*((psbool)(InternalBuf+0x38E))) /*q0 - внутренний параметр*/
#define internal1_m1939_q0 (*((psbool)(InternalBuf+0x390))) /*q0 - внутренний параметр*/
#define internal1_m1634_q0 (*((psbool)(InternalBuf+0x392))) /*q0 - внутренний параметр*/
#define internal1_m1636_q0 (*((psbool)(InternalBuf+0x394))) /*q0 - внутренний параметр*/
#define internal1_m1621_q0 (*((psbool)(InternalBuf+0x396))) /*q0 - внутренний параметр*/
#define internal1_m1619_q0 (*((psbool)(InternalBuf+0x398))) /*q0 - внутренний параметр*/
#define internal1_m1618_q0 (*((psbool)(InternalBuf+0x39A))) /*q0 - внутренний параметр*/
#define internal1_m1616_q0 (*((psbool)(InternalBuf+0x39C))) /*q0 - внутренний параметр*/
#define internal1_m1615_q0 (*((psbool)(InternalBuf+0x39E))) /*q0 - внутренний параметр*/
#define internal1_m1613_q0 (*((psbool)(InternalBuf+0x3A0))) /*q0 - внутренний параметр*/
#define internal1_m1612_q0 (*((psbool)(InternalBuf+0x3A2))) /*q0 - внутренний параметр*/
#define internal1_m1610_q0 (*((psbool)(InternalBuf+0x3A4))) /*q0 - внутренний параметр*/
#define internal1_m2067_DvUp0 (*((pschar)(InternalBuf+0x3A6))) /*- есть команда на движение вперёд*/
#define internal1_m2067_DvDw0 (*((pschar)(InternalBuf+0x3A8))) /*- есть команда на движение назад*/
#define internal1_m2067_FDvUp0 (*((pschar)(InternalBuf+0x3AA))) /*- есть команда на движение вперёд*/
#define internal1_m2067_FDvDw0 (*((pschar)(InternalBuf+0x3AC))) /*- есть команда на движение назад*/
#define internal1_m2067_BlDv0 (*((pschar)(InternalBuf+0x3AE))) /*- была блокировка*/
#define internal1_m2067_Pkv0 (*((pschar)(InternalBuf+0x3B0))) /*Pkv - передний конечный выключатель*/
#define internal1_m2067_Pkav0 (*((pschar)(InternalBuf+0x3B2))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m2067_Zkv0 (*((pschar)(InternalBuf+0x3B4))) /*Zkv - задний конечный выключатель*/
#define internal1_m2067_Zkav0 (*((pschar)(InternalBuf+0x3B6))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m2067_txNm (*((psfloat)(InternalBuf+0x3B8))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m2067_txSm (*((psfloat)(InternalBuf+0x3BD))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m2067_txHr (*((psfloat)(InternalBuf+0x3C2))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m2067_txLd (*((psfloat)(InternalBuf+0x3C7))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m2067_fef (*((pschar)(InternalBuf+0x3CC))) /*fef*/
#define internal1_m2061_DvUp0 (*((pschar)(InternalBuf+0x3CE))) /*- есть команда на движение вперёд*/
#define internal1_m2061_DvDw0 (*((pschar)(InternalBuf+0x3D0))) /*- есть команда на движение назад*/
#define internal1_m2061_FDvUp0 (*((pschar)(InternalBuf+0x3D2))) /*- есть команда на движение вперёд*/
#define internal1_m2061_FDvDw0 (*((pschar)(InternalBuf+0x3D4))) /*- есть команда на движение назад*/
#define internal1_m2061_BlDv0 (*((pschar)(InternalBuf+0x3D6))) /*- была блокировка*/
#define internal1_m2061_Pkv0 (*((pschar)(InternalBuf+0x3D8))) /*Pkv - передний конечный выключатель*/
#define internal1_m2061_Pkav0 (*((pschar)(InternalBuf+0x3DA))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m2061_Zkv0 (*((pschar)(InternalBuf+0x3DC))) /*Zkv - задний конечный выключатель*/
#define internal1_m2061_Zkav0 (*((pschar)(InternalBuf+0x3DE))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m2061_txNm (*((psfloat)(InternalBuf+0x3E0))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m2061_txSm (*((psfloat)(InternalBuf+0x3E5))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m2061_txHr (*((psfloat)(InternalBuf+0x3EA))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m2061_txLd (*((psfloat)(InternalBuf+0x3EF))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m2061_fef (*((pschar)(InternalBuf+0x3F4))) /*fef*/
#define internal1_m1465_q0 (*((psbool)(InternalBuf+0x3F6))) /*q0 - внутренний параметр*/
#define internal1_m1469_x0 (*((psbool)(InternalBuf+0x3F8))) /*был приход сигнала x1*/
#define internal1_m1469_y0 (*((psfloat)(InternalBuf+0x3FA))) /*интервал между сигналами х1 и х2*/
#define internal1_m1879_x0 (*((psbool)(InternalBuf+0x3FF))) /*был приход сигнала x1*/
#define internal1_m1879_y0 (*((psfloat)(InternalBuf+0x401))) /*интервал между сигналами х1 и х2*/
#define internal1_m1840_x0 (*((psbool)(InternalBuf+0x406))) /*был приход сигнала x1*/
#define internal1_m1840_y0 (*((psfloat)(InternalBuf+0x408))) /*интервал между сигналами х1 и х2*/
#define internal1_m278_q0 (*((psbool)(InternalBuf+0x40D))) /*q0 - внутренний параметр*/
#define internal1_m988_q0 (*((psbool)(InternalBuf+0x40F))) /*q0 - внутренний параметр*/
#define internal1_m619_q0 (*((psbool)(InternalBuf+0x411))) /*q0 - внутренний параметр*/
#define internal1_m1288_X0 (*((psfloat)(InternalBuf+0x413))) /*текущая зона нечувствительности (Dlt/Du) в мм (гр.)*/
#define internal1_m1288_t0 (*((psfloat)(InternalBuf+0x418))) /*время нахождения в зоне возврата*/
#define internal1_m1288_BLDv0 (*((pschar)(InternalBuf+0x41D))) /*BlDv - Блокировка движения*/
#define internal1_m1307_tx (*((psfloat)(InternalBuf+0x41F))) /*tx - время накопленное сек*/
#define internal1_m1307_y0 (*((pschar)(InternalBuf+0x424))) /*y0*/
#define internal1_m1310_tx (*((psfloat)(InternalBuf+0x426))) /*tx - время накопленное сек*/
#define internal1_m1310_y0 (*((pschar)(InternalBuf+0x42B))) /*y0*/
#define internal1_m1316_xptr (*((psint)(InternalBuf+0x42D))) /*указатель текущей позиции в массиве координат*/
#define internal1_m1316_x0 (*((psfloat)(InternalBuf+0x430))) /*x0 - массив мгновенных значений координат*/
#define internal1_m1316_tim0 (*((psfloat)(InternalBuf+0x55C))) /*tim0 - массив значений времени цикла*/
#define internal1_m1316_sumtim (*((psfloat)(InternalBuf+0x688))) /*sumtim - время в пути*/
#define internal1_m1316_StSpeed (*((psfloat)(InternalBuf+0x68D))) /*StSpeed - стартовая скорость - с которой начинается изменение скорости*/
#define internal1_m1316_Vz0 (*((psfloat)(InternalBuf+0x692))) /*Vz0 - предыдущая заданная скорость*/
#define internal1_m1316_flRazg (*((psint)(InternalBuf+0x697))) /*признак разгона/торможения*/
#define internal1_m1316_DelSp (*((psfloat)(InternalBuf+0x69A))) /*DelSp - время переключения скоростей*/
#define internal1_m1316_z0 (*((psfloat)(InternalBuf+0x69F))) /*z0 - точка прекращения движения*/
#define internal1_m1316_txZS (*((psfloat)(InternalBuf+0x6A4))) /*txZS*/
#define internal1_m1316_tx (*((psfloat)(InternalBuf+0x6A9))) /*tx*/
#define internal1_m1316_txd (*((psfloat)(InternalBuf+0x6AE))) /*txd*/
#define internal1_m1316_txMBl (*((psfloat)(InternalBuf+0x6B3))) /*tx*/
#define internal1_m1316_txBl (*((psfloat)(InternalBuf+0x6B8))) /*tx*/
#define internal1_m1316_Speed0 (*((psfloat)(InternalBuf+0x6BD))) /*Speed0 - предыдущее значение скорости перемещения*/
#define internal1_m1316_xz0 (*((psfloat)(InternalBuf+0x6C2))) /*xz0 - новое задание мм*/
#define internal1_m1316_tz0 (*((psfloat)(InternalBuf+0x6C7))) /*tz0 - время защиты от нового задания сек*/
#define internal1_m1316_Shift0 (*((psbool)(InternalBuf+0x6CC))) /*Shift0 - признак самохода*/
#define internal1_m1316_ShCntlSp0 (*((psbool)(InternalBuf+0x6CE))) /*ShCntlSp0 - признак выдержки времени после достижения 0 скорости*/
#define internal1_m1316_ShiftControl (*((psbool)(InternalBuf+0x6D0))) /*ShiftControl - признак самохода*/
#define internal1_m617_q0 (*((psbool)(InternalBuf+0x6D2))) /*q0 - внутренний параметр*/
#define internal1_m886_X0 (*((psfloat)(InternalBuf+0x6D4))) /*текущая зона нечувствительности (Dlt/Du) в мм (гр.)*/
#define internal1_m886_t0 (*((psfloat)(InternalBuf+0x6D9))) /*время нахождения в зоне возврата*/
#define internal1_m886_BLDv0 (*((pschar)(InternalBuf+0x6DE))) /*BlDv - Блокировка движения*/
#define internal1_m910_tx (*((psfloat)(InternalBuf+0x6E0))) /*tx - время накопленное сек*/
#define internal1_m910_y0 (*((pschar)(InternalBuf+0x6E5))) /*y0*/
#define internal1_m911_tx (*((psfloat)(InternalBuf+0x6E7))) /*tx - время накопленное сек*/
#define internal1_m911_y0 (*((pschar)(InternalBuf+0x6EC))) /*y0*/
#define internal1_m919_xptr (*((psint)(InternalBuf+0x6EE))) /*указатель текущей позиции в массиве координат*/
#define internal1_m919_x0 (*((psfloat)(InternalBuf+0x6F1))) /*x0 - массив мгновенных значений координат*/
#define internal1_m919_tim0 (*((psfloat)(InternalBuf+0x81D))) /*tim0 - массив значений времени цикла*/
#define internal1_m919_sumtim (*((psfloat)(InternalBuf+0x949))) /*sumtim - время в пути*/
#define internal1_m919_StSpeed (*((psfloat)(InternalBuf+0x94E))) /*StSpeed - стартовая скорость - с которой начинается изменение скорости*/
#define internal1_m919_Vz0 (*((psfloat)(InternalBuf+0x953))) /*Vz0 - предыдущая заданная скорость*/
#define internal1_m919_flRazg (*((psint)(InternalBuf+0x958))) /*признак разгона/торможения*/
#define internal1_m919_DelSp (*((psfloat)(InternalBuf+0x95B))) /*DelSp - время переключения скоростей*/
#define internal1_m919_z0 (*((psfloat)(InternalBuf+0x960))) /*z0 - точка прекращения движения*/
#define internal1_m919_txZS (*((psfloat)(InternalBuf+0x965))) /*txZS*/
#define internal1_m919_tx (*((psfloat)(InternalBuf+0x96A))) /*tx*/
#define internal1_m919_txd (*((psfloat)(InternalBuf+0x96F))) /*txd*/
#define internal1_m919_txMBl (*((psfloat)(InternalBuf+0x974))) /*tx*/
#define internal1_m919_txBl (*((psfloat)(InternalBuf+0x979))) /*tx*/
#define internal1_m919_Speed0 (*((psfloat)(InternalBuf+0x97E))) /*Speed0 - предыдущее значение скорости перемещения*/
#define internal1_m919_xz0 (*((psfloat)(InternalBuf+0x983))) /*xz0 - новое задание мм*/
#define internal1_m919_tz0 (*((psfloat)(InternalBuf+0x988))) /*tz0 - время защиты от нового задания сек*/
#define internal1_m919_Shift0 (*((psbool)(InternalBuf+0x98D))) /*Shift0 - признак самохода*/
#define internal1_m919_ShCntlSp0 (*((psbool)(InternalBuf+0x98F))) /*ShCntlSp0 - признак выдержки времени после достижения 0 скорости*/
#define internal1_m919_ShiftControl (*((psbool)(InternalBuf+0x991))) /*ShiftControl - признак самохода*/
#define internal1_m488_X0 (*((psfloat)(InternalBuf+0x993))) /*текущая зона нечувствительности (Dlt/Du) в мм (гр.)*/
#define internal1_m488_t0 (*((psfloat)(InternalBuf+0x998))) /*время нахождения в зоне возврата*/
#define internal1_m488_BLDv0 (*((pschar)(InternalBuf+0x99D))) /*BlDv - Блокировка движения*/
#define internal1_m508_tx (*((psfloat)(InternalBuf+0x99F))) /*tx - время накопленное сек*/
#define internal1_m508_y0 (*((pschar)(InternalBuf+0x9A4))) /*y0*/
#define internal1_m511_tx (*((psfloat)(InternalBuf+0x9A6))) /*tx - время накопленное сек*/
#define internal1_m511_y0 (*((pschar)(InternalBuf+0x9AB))) /*y0*/
#define internal1_m515_xptr (*((psint)(InternalBuf+0x9AD))) /*указатель текущей позиции в массиве координат*/
#define internal1_m515_x0 (*((psfloat)(InternalBuf+0x9B0))) /*x0 - массив мгновенных значений координат*/
#define internal1_m515_tim0 (*((psfloat)(InternalBuf+0xC9E))) /*tim0 - массив значений времени цикла*/
#define internal1_m515_sumtim (*((psfloat)(InternalBuf+0xF8C))) /*sumtim - время в пути*/
#define internal1_m515_StSpeed (*((psfloat)(InternalBuf+0xF91))) /*StSpeed - стартовая скорость - с которой начинается изменение скорости*/
#define internal1_m515_Vz0 (*((psfloat)(InternalBuf+0xF96))) /*Vz0 - предыдущая заданная скорость*/
#define internal1_m515_flRazg (*((psint)(InternalBuf+0xF9B))) /*признак разгона/торможения*/
#define internal1_m515_DelSp (*((psfloat)(InternalBuf+0xF9E))) /*DelSp - время переключения скоростей*/
#define internal1_m515_z0 (*((psfloat)(InternalBuf+0xFA3))) /*z0 - точка прекращения движения*/
#define internal1_m515_txZS (*((psfloat)(InternalBuf+0xFA8))) /*txZS*/
#define internal1_m515_tx (*((psfloat)(InternalBuf+0xFAD))) /*tx*/
#define internal1_m515_txd (*((psfloat)(InternalBuf+0xFB2))) /*txd*/
#define internal1_m515_txMBl (*((psfloat)(InternalBuf+0xFB7))) /*tx*/
#define internal1_m515_txBl (*((psfloat)(InternalBuf+0xFBC))) /*tx*/
#define internal1_m515_Speed0 (*((psfloat)(InternalBuf+0xFC1))) /*Speed0 - предыдущее значение скорости перемещения*/
#define internal1_m515_xz0 (*((psfloat)(InternalBuf+0xFC6))) /*xz0 - новое задание мм*/
#define internal1_m515_tz0 (*((psfloat)(InternalBuf+0xFCB))) /*tz0 - время защиты от нового задания сек*/
#define internal1_m515_Shift0 (*((psbool)(InternalBuf+0xFD0))) /*Shift0 - признак самохода*/
#define internal1_m515_ShCntlSp0 (*((psbool)(InternalBuf+0xFD2))) /*ShCntlSp0 - признак выдержки времени после достижения 0 скорости*/
#define internal1_m515_ShiftControl (*((psbool)(InternalBuf+0xFD4))) /*ShiftControl - признак самохода*/
#define internal1_m614_q0 (*((psbool)(InternalBuf+0xFD6))) /*q0 - внутренний параметр*/
#define internal1_m167_X0 (*((psfloat)(InternalBuf+0xFD8))) /*текущая зона нечувствительности (Dlt/Du) в мм (гр.)*/
#define internal1_m167_t0 (*((psfloat)(InternalBuf+0xFDD))) /*время нахождения в зоне возврата*/
#define internal1_m167_BLDv0 (*((pschar)(InternalBuf+0xFE2))) /*BlDv - Блокировка движения*/
#define internal1_m196_xptr (*((psint)(InternalBuf+0xFE4))) /*указатель текущей позиции в массиве координат*/
#define internal1_m196_x0 (*((psfloat)(InternalBuf+0xFE7))) /*x0 - массив мгновенных значений координат*/
#define internal1_m196_tim0 (*((psfloat)(InternalBuf+0x12D5))) /*tim0 - массив значений времени цикла*/
#define internal1_m196_sumtim (*((psfloat)(InternalBuf+0x15C3))) /*sumtim - время в пути*/
#define internal1_m196_StSpeed (*((psfloat)(InternalBuf+0x15C8))) /*StSpeed - стартовая скорость - с которой начинается изменение скорости*/
#define internal1_m196_Vz0 (*((psfloat)(InternalBuf+0x15CD))) /*Vz0 - предыдущая заданная скорость*/
#define internal1_m196_flRazg (*((psint)(InternalBuf+0x15D2))) /*признак разгона/торможения*/
#define internal1_m196_DelSp (*((psfloat)(InternalBuf+0x15D5))) /*DelSp - время переключения скоростей*/
#define internal1_m196_z0 (*((psfloat)(InternalBuf+0x15DA))) /*z0 - точка прекращения движения*/
#define internal1_m196_txZS (*((psfloat)(InternalBuf+0x15DF))) /*txZS*/
#define internal1_m196_tx (*((psfloat)(InternalBuf+0x15E4))) /*tx*/
#define internal1_m196_txd (*((psfloat)(InternalBuf+0x15E9))) /*txd*/
#define internal1_m196_txMBl (*((psfloat)(InternalBuf+0x15EE))) /*tx*/
#define internal1_m196_txBl (*((psfloat)(InternalBuf+0x15F3))) /*tx*/
#define internal1_m196_Speed0 (*((psfloat)(InternalBuf+0x15F8))) /*Speed0 - предыдущее значение скорости перемещения*/
#define internal1_m196_xz0 (*((psfloat)(InternalBuf+0x15FD))) /*xz0 - новое задание мм*/
#define internal1_m196_tz0 (*((psfloat)(InternalBuf+0x1602))) /*tz0 - время защиты от нового задания сек*/
#define internal1_m196_Shift0 (*((psbool)(InternalBuf+0x1607))) /*Shift0 - признак самохода*/
#define internal1_m196_ShCntlSp0 (*((psbool)(InternalBuf+0x1609))) /*ShCntlSp0 - признак выдержки времени после достижения 0 скорости*/
#define internal1_m196_ShiftControl (*((psbool)(InternalBuf+0x160B))) /*ShiftControl - признак самохода*/
#define internal1_m640_q0 (*((psbool)(InternalBuf+0x160D))) /*q0 - внутренний параметр*/
#define internal1_m459_DvUp0 (*((pschar)(InternalBuf+0x160F))) /*- есть команда на движение вперёд*/
#define internal1_m459_DvDw0 (*((pschar)(InternalBuf+0x1611))) /*- есть команда на движение назад*/
#define internal1_m459_FDvUp0 (*((pschar)(InternalBuf+0x1613))) /*- есть команда на движение вперёд*/
#define internal1_m459_FDvDw0 (*((pschar)(InternalBuf+0x1615))) /*- есть команда на движение назад*/
#define internal1_m459_BlDv0 (*((pschar)(InternalBuf+0x1617))) /*- была блокировка*/
#define internal1_m459_Pkv0 (*((pschar)(InternalBuf+0x1619))) /*Pkv - передний конечный выключатель*/
#define internal1_m459_Pkav0 (*((pschar)(InternalBuf+0x161B))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m459_Zkv0 (*((pschar)(InternalBuf+0x161D))) /*Zkv - задний конечный выключатель*/
#define internal1_m459_Zkav0 (*((pschar)(InternalBuf+0x161F))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m459_txNm (*((psfloat)(InternalBuf+0x1621))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m459_txSm (*((psfloat)(InternalBuf+0x1626))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m459_txHr (*((psfloat)(InternalBuf+0x162B))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m459_txLd (*((psfloat)(InternalBuf+0x1630))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m459_fef (*((pschar)(InternalBuf+0x1635))) /*fef*/
#define internal1_m453_DvUp0 (*((pschar)(InternalBuf+0x1637))) /*- есть команда на движение вперёд*/
#define internal1_m453_DvDw0 (*((pschar)(InternalBuf+0x1639))) /*- есть команда на движение назад*/
#define internal1_m453_FDvUp0 (*((pschar)(InternalBuf+0x163B))) /*- есть команда на движение вперёд*/
#define internal1_m453_FDvDw0 (*((pschar)(InternalBuf+0x163D))) /*- есть команда на движение назад*/
#define internal1_m453_BlDv0 (*((pschar)(InternalBuf+0x163F))) /*- была блокировка*/
#define internal1_m453_Pkv0 (*((pschar)(InternalBuf+0x1641))) /*Pkv - передний конечный выключатель*/
#define internal1_m453_Pkav0 (*((pschar)(InternalBuf+0x1643))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m453_Zkv0 (*((pschar)(InternalBuf+0x1645))) /*Zkv - задний конечный выключатель*/
#define internal1_m453_Zkav0 (*((pschar)(InternalBuf+0x1647))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m453_txNm (*((psfloat)(InternalBuf+0x1649))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m453_txSm (*((psfloat)(InternalBuf+0x164E))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m453_txHr (*((psfloat)(InternalBuf+0x1653))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m453_txLd (*((psfloat)(InternalBuf+0x1658))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m453_fef (*((pschar)(InternalBuf+0x165D))) /*fef*/
#define internal1_m806_X0 (*((psfloat)(InternalBuf+0x165F))) /*текущая зона нечувствительности (Dlt/Du) в мм (гр.)*/
#define internal1_m806_t0 (*((psfloat)(InternalBuf+0x1664))) /*время нахождения в зоне возврата*/
#define internal1_m806_BLDv0 (*((pschar)(InternalBuf+0x1669))) /*BlDv - Блокировка движения*/
#define internal1_m826_xptr (*((psint)(InternalBuf+0x166B))) /*указатель текущей позиции в массиве координат*/
#define internal1_m826_x0 (*((psfloat)(InternalBuf+0x166E))) /*x0 - массив мгновенных значений координат*/
#define internal1_m826_tim0 (*((psfloat)(InternalBuf+0x17FE))) /*tim0 - массив значений времени цикла*/
#define internal1_m826_sumtim (*((psfloat)(InternalBuf+0x198E))) /*sumtim - время в пути*/
#define internal1_m826_StSpeed (*((psfloat)(InternalBuf+0x1993))) /*StSpeed - стартовая скорость - с которой начинается изменение скорости*/
#define internal1_m826_Vz0 (*((psfloat)(InternalBuf+0x1998))) /*Vz0 - предыдущая заданная скорость*/
#define internal1_m826_flRazg (*((psint)(InternalBuf+0x199D))) /*признак разгона/торможения*/
#define internal1_m826_DelSp (*((psfloat)(InternalBuf+0x19A0))) /*DelSp - время переключения скоростей*/
#define internal1_m826_z0 (*((psfloat)(InternalBuf+0x19A5))) /*z0 - точка прекращения движения*/
#define internal1_m826_txZS (*((psfloat)(InternalBuf+0x19AA))) /*txZS*/
#define internal1_m826_tx (*((psfloat)(InternalBuf+0x19AF))) /*tx*/
#define internal1_m826_txd (*((psfloat)(InternalBuf+0x19B4))) /*txd*/
#define internal1_m826_txMBl (*((psfloat)(InternalBuf+0x19B9))) /*tx*/
#define internal1_m826_txBl (*((psfloat)(InternalBuf+0x19BE))) /*tx*/
#define internal1_m826_Speed0 (*((psfloat)(InternalBuf+0x19C3))) /*Speed0 - предыдущее значение скорости перемещения*/
#define internal1_m826_xz0 (*((psfloat)(InternalBuf+0x19C8))) /*xz0 - новое задание мм*/
#define internal1_m826_tz0 (*((psfloat)(InternalBuf+0x19CD))) /*tz0 - время защиты от нового задания сек*/
#define internal1_m826_Shift0 (*((psbool)(InternalBuf+0x19D2))) /*Shift0 - признак самохода*/
#define internal1_m826_ShCntlSp0 (*((psbool)(InternalBuf+0x19D4))) /*ShCntlSp0 - признак выдержки времени после достижения 0 скорости*/
#define internal1_m826_ShiftControl (*((psbool)(InternalBuf+0x19D6))) /*ShiftControl - признак самохода*/
#define internal1_m1570_X0 (*((psfloat)(InternalBuf+0x19D8))) /*текущая зона нечувствительности (Dlt/Du) в мм (гр.)*/
#define internal1_m1570_t0 (*((psfloat)(InternalBuf+0x19DD))) /*время нахождения в зоне возврата*/
#define internal1_m1570_BLDv0 (*((pschar)(InternalBuf+0x19E2))) /*BlDv - Блокировка движения*/
#define internal1_m1109_X0 (*((psfloat)(InternalBuf+0x19E4))) /*текущая зона нечувствительности (Dlt/Du) в мм (гр.)*/
#define internal1_m1109_t0 (*((psfloat)(InternalBuf+0x19E9))) /*время нахождения в зоне возврата*/
#define internal1_m1109_BLDv0 (*((pschar)(InternalBuf+0x19EE))) /*BlDv - Блокировка движения*/
#define internal1_m612_q0 (*((psbool)(InternalBuf+0x19F0))) /*q0 - внутренний параметр*/
#define internal1_m1191_X0 (*((psfloat)(InternalBuf+0x19F2))) /*текущая зона нечувствительности (Dlt/Du) в мм (гр.)*/
#define internal1_m1191_t0 (*((psfloat)(InternalBuf+0x19F7))) /*время нахождения в зоне возврата*/
#define internal1_m1191_BLDv0 (*((pschar)(InternalBuf+0x19FC))) /*BlDv - Блокировка движения*/
#define internal1_m1211_tx (*((psfloat)(InternalBuf+0x19FE))) /*tx - время накопленное сек*/
#define internal1_m1211_y0 (*((pschar)(InternalBuf+0x1A03))) /*y0*/
#define internal1_m1219_tx (*((psfloat)(InternalBuf+0x1A05))) /*tx - время накопленное сек*/
#define internal1_m1219_y0 (*((pschar)(InternalBuf+0x1A0A))) /*y0*/
#define internal1_m1226_xptr (*((psint)(InternalBuf+0x1A0C))) /*указатель текущей позиции в массиве координат*/
#define internal1_m1226_x0 (*((psfloat)(InternalBuf+0x1A0F))) /*x0 - массив мгновенных значений координат*/
#define internal1_m1226_tim0 (*((psfloat)(InternalBuf+0x1B9F))) /*tim0 - массив значений времени цикла*/
#define internal1_m1226_sumtim (*((psfloat)(InternalBuf+0x1D2F))) /*sumtim - время в пути*/
#define internal1_m1226_StSpeed (*((psfloat)(InternalBuf+0x1D34))) /*StSpeed - стартовая скорость - с которой начинается изменение скорости*/
#define internal1_m1226_Vz0 (*((psfloat)(InternalBuf+0x1D39))) /*Vz0 - предыдущая заданная скорость*/
#define internal1_m1226_flRazg (*((psint)(InternalBuf+0x1D3E))) /*признак разгона/торможения*/
#define internal1_m1226_DelSp (*((psfloat)(InternalBuf+0x1D41))) /*DelSp - время переключения скоростей*/
#define internal1_m1226_z0 (*((psfloat)(InternalBuf+0x1D46))) /*z0 - точка прекращения движения*/
#define internal1_m1226_txZS (*((psfloat)(InternalBuf+0x1D4B))) /*txZS*/
#define internal1_m1226_tx (*((psfloat)(InternalBuf+0x1D50))) /*tx*/
#define internal1_m1226_txd (*((psfloat)(InternalBuf+0x1D55))) /*txd*/
#define internal1_m1226_txMBl (*((psfloat)(InternalBuf+0x1D5A))) /*tx*/
#define internal1_m1226_txBl (*((psfloat)(InternalBuf+0x1D5F))) /*tx*/
#define internal1_m1226_Speed0 (*((psfloat)(InternalBuf+0x1D64))) /*Speed0 - предыдущее значение скорости перемещения*/
#define internal1_m1226_xz0 (*((psfloat)(InternalBuf+0x1D69))) /*xz0 - новое задание мм*/
#define internal1_m1226_tz0 (*((psfloat)(InternalBuf+0x1D6E))) /*tz0 - время защиты от нового задания сек*/
#define internal1_m1226_Shift0 (*((psbool)(InternalBuf+0x1D73))) /*Shift0 - признак самохода*/
#define internal1_m1226_ShCntlSp0 (*((psbool)(InternalBuf+0x1D75))) /*ShCntlSp0 - признак выдержки времени после достижения 0 скорости*/
#define internal1_m1226_ShiftControl (*((psbool)(InternalBuf+0x1D77))) /*ShiftControl - признак самохода*/
#define internal1_m632_q0 (*((psbool)(InternalBuf+0x1D79))) /*q0 - внутренний параметр*/
#define internal1_m1583_tx (*((psfloat)(InternalBuf+0x1D7B))) /*tx - время накопленное сек*/
#define internal1_m1583_y0 (*((pschar)(InternalBuf+0x1D80))) /*y0*/
#define internal1_m1586_tx (*((psfloat)(InternalBuf+0x1D82))) /*tx - время накопленное сек*/
#define internal1_m1586_y0 (*((pschar)(InternalBuf+0x1D87))) /*y0*/
#define internal1_m1573_DvUp0 (*((pschar)(InternalBuf+0x1D89))) /*- есть команда на движение вперёд*/
#define internal1_m1573_DvDw0 (*((pschar)(InternalBuf+0x1D8B))) /*- есть команда на движение назад*/
#define internal1_m1573_FDvUp0 (*((pschar)(InternalBuf+0x1D8D))) /*- есть команда на движение вперёд*/
#define internal1_m1573_FDvDw0 (*((pschar)(InternalBuf+0x1D8F))) /*- есть команда на движение назад*/
#define internal1_m1573_BlDv0 (*((pschar)(InternalBuf+0x1D91))) /*- была блокировка*/
#define internal1_m1573_Pkv0 (*((pschar)(InternalBuf+0x1D93))) /*Pkv - передний конечный выключатель*/
#define internal1_m1573_Pkav0 (*((pschar)(InternalBuf+0x1D95))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m1573_Zkv0 (*((pschar)(InternalBuf+0x1D97))) /*Zkv - задний конечный выключатель*/
#define internal1_m1573_Zkav0 (*((pschar)(InternalBuf+0x1D99))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m1573_txNm (*((psfloat)(InternalBuf+0x1D9B))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m1573_txSm (*((psfloat)(InternalBuf+0x1DA0))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m1573_txHr (*((psfloat)(InternalBuf+0x1DA5))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m1573_txLd (*((psfloat)(InternalBuf+0x1DAA))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m1573_fef (*((pschar)(InternalBuf+0x1DAF))) /*fef*/
#define internal1_m1590_xptr (*((psint)(InternalBuf+0x1DB1))) /*указатель текущей позиции в массиве координат*/
#define internal1_m1590_x0 (*((psfloat)(InternalBuf+0x1DB4))) /*x0 - массив мгновенных значений координат*/
#define internal1_m1590_tim0 (*((psfloat)(InternalBuf+0x1E18))) /*tim0 - массив значений времени цикла*/
#define internal1_m1590_sumtim (*((psfloat)(InternalBuf+0x1E7C))) /*sumtim - время в пути*/
#define internal1_m1590_StSpeed (*((psfloat)(InternalBuf+0x1E81))) /*StSpeed - стартовая скорость - с которой начинается изменение скорости*/
#define internal1_m1590_Vz0 (*((psfloat)(InternalBuf+0x1E86))) /*Vz0 - предыдущая заданная скорость*/
#define internal1_m1590_flRazg (*((psint)(InternalBuf+0x1E8B))) /*признак разгона/торможения*/
#define internal1_m1590_DelSp (*((psfloat)(InternalBuf+0x1E8E))) /*DelSp - время переключения скоростей*/
#define internal1_m1590_z0 (*((psfloat)(InternalBuf+0x1E93))) /*z0 - точка прекращения движения*/
#define internal1_m1590_txZS (*((psfloat)(InternalBuf+0x1E98))) /*txZS*/
#define internal1_m1590_tx (*((psfloat)(InternalBuf+0x1E9D))) /*tx*/
#define internal1_m1590_txd (*((psfloat)(InternalBuf+0x1EA2))) /*txd*/
#define internal1_m1590_txMBl (*((psfloat)(InternalBuf+0x1EA7))) /*tx*/
#define internal1_m1590_txBl (*((psfloat)(InternalBuf+0x1EAC))) /*tx*/
#define internal1_m1590_Speed0 (*((psfloat)(InternalBuf+0x1EB1))) /*Speed0 - предыдущее значение скорости перемещения*/
#define internal1_m1590_xz0 (*((psfloat)(InternalBuf+0x1EB6))) /*xz0 - новое задание мм*/
#define internal1_m1590_tz0 (*((psfloat)(InternalBuf+0x1EBB))) /*tz0 - время защиты от нового задания сек*/
#define internal1_m1590_Shift0 (*((psbool)(InternalBuf+0x1EC0))) /*Shift0 - признак самохода*/
#define internal1_m1590_ShCntlSp0 (*((psbool)(InternalBuf+0x1EC2))) /*ShCntlSp0 - признак выдержки времени после достижения 0 скорости*/
#define internal1_m1590_ShiftControl (*((psbool)(InternalBuf+0x1EC4))) /*ShiftControl - признак самохода*/
#define internal1_m1122_tx (*((psfloat)(InternalBuf+0x1EC6))) /*tx - время накопленное сек*/
#define internal1_m1122_y0 (*((pschar)(InternalBuf+0x1ECB))) /*y0*/
#define internal1_m1126_tx (*((psfloat)(InternalBuf+0x1ECD))) /*tx - время накопленное сек*/
#define internal1_m1126_y0 (*((pschar)(InternalBuf+0x1ED2))) /*y0*/
#define internal1_m622_q0 (*((psbool)(InternalBuf+0x1ED4))) /*q0 - внутренний параметр*/
#define internal1_m587_q0 (*((psbool)(InternalBuf+0x1ED6))) /*q0 - внутренний параметр*/
#define internal1_m1113_DvUp0 (*((pschar)(InternalBuf+0x1ED8))) /*- есть команда на движение вперёд*/
#define internal1_m1113_DvDw0 (*((pschar)(InternalBuf+0x1EDA))) /*- есть команда на движение назад*/
#define internal1_m1113_FDvUp0 (*((pschar)(InternalBuf+0x1EDC))) /*- есть команда на движение вперёд*/
#define internal1_m1113_FDvDw0 (*((pschar)(InternalBuf+0x1EDE))) /*- есть команда на движение назад*/
#define internal1_m1113_BlDv0 (*((pschar)(InternalBuf+0x1EE0))) /*- была блокировка*/
#define internal1_m1113_Pkv0 (*((pschar)(InternalBuf+0x1EE2))) /*Pkv - передний конечный выключатель*/
#define internal1_m1113_Pkav0 (*((pschar)(InternalBuf+0x1EE4))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m1113_Zkv0 (*((pschar)(InternalBuf+0x1EE6))) /*Zkv - задний конечный выключатель*/
#define internal1_m1113_Zkav0 (*((pschar)(InternalBuf+0x1EE8))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m1113_txNm (*((psfloat)(InternalBuf+0x1EEA))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m1113_txSm (*((psfloat)(InternalBuf+0x1EEF))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m1113_txHr (*((psfloat)(InternalBuf+0x1EF4))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m1113_txLd (*((psfloat)(InternalBuf+0x1EF9))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m1113_fef (*((pschar)(InternalBuf+0x1EFE))) /*fef*/
#define internal1_m1130_xptr (*((psint)(InternalBuf+0x1F00))) /*указатель текущей позиции в массиве координат*/
#define internal1_m1130_x0 (*((psfloat)(InternalBuf+0x1F03))) /*x0 - массив мгновенных значений координат*/
#define internal1_m1130_tim0 (*((psfloat)(InternalBuf+0x1F67))) /*tim0 - массив значений времени цикла*/
#define internal1_m1130_sumtim (*((psfloat)(InternalBuf+0x1FCB))) /*sumtim - время в пути*/
#define internal1_m1130_StSpeed (*((psfloat)(InternalBuf+0x1FD0))) /*StSpeed - стартовая скорость - с которой начинается изменение скорости*/
#define internal1_m1130_Vz0 (*((psfloat)(InternalBuf+0x1FD5))) /*Vz0 - предыдущая заданная скорость*/
#define internal1_m1130_flRazg (*((psint)(InternalBuf+0x1FDA))) /*признак разгона/торможения*/
#define internal1_m1130_DelSp (*((psfloat)(InternalBuf+0x1FDD))) /*DelSp - время переключения скоростей*/
#define internal1_m1130_z0 (*((psfloat)(InternalBuf+0x1FE2))) /*z0 - точка прекращения движения*/
#define internal1_m1130_txZS (*((psfloat)(InternalBuf+0x1FE7))) /*txZS*/
#define internal1_m1130_tx (*((psfloat)(InternalBuf+0x1FEC))) /*tx*/
#define internal1_m1130_txd (*((psfloat)(InternalBuf+0x1FF1))) /*txd*/
#define internal1_m1130_txMBl (*((psfloat)(InternalBuf+0x1FF6))) /*tx*/
#define internal1_m1130_txBl (*((psfloat)(InternalBuf+0x1FFB))) /*tx*/
#define internal1_m1130_Speed0 (*((psfloat)(InternalBuf+0x2000))) /*Speed0 - предыдущее значение скорости перемещения*/
#define internal1_m1130_xz0 (*((psfloat)(InternalBuf+0x2005))) /*xz0 - новое задание мм*/
#define internal1_m1130_tz0 (*((psfloat)(InternalBuf+0x200A))) /*tz0 - время защиты от нового задания сек*/
#define internal1_m1130_Shift0 (*((psbool)(InternalBuf+0x200F))) /*Shift0 - признак самохода*/
#define internal1_m1130_ShCntlSp0 (*((psbool)(InternalBuf+0x2011))) /*ShCntlSp0 - признак выдержки времени после достижения 0 скорости*/
#define internal1_m1130_ShiftControl (*((psbool)(InternalBuf+0x2013))) /*ShiftControl - признак самохода*/
#define internal1_m735_x0 (*((psbool)(InternalBuf+0x2015))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m704_x0 (*((psbool)(InternalBuf+0x2017))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m667_x0 (*((psbool)(InternalBuf+0x2019))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m760_q0 (*((psbool)(InternalBuf+0x201B))) /*q0 - внутренний параметр*/
#define internal1_m755_q0 (*((psbool)(InternalBuf+0x201D))) /*q0 - внутренний параметр*/
#define internal1_m723_q0 (*((psbool)(InternalBuf+0x201F))) /*q0 - внутренний параметр*/
#define internal1_m728_q0 (*((psbool)(InternalBuf+0x2021))) /*q0 - внутренний параметр*/
#define internal1_m736_q0 (*((psbool)(InternalBuf+0x2023))) /*q0 - внутренний параметр*/
#define internal1_m748_q0 (*((psbool)(InternalBuf+0x2025))) /*q0 - внутренний параметр*/
#define internal1_m726_q0 (*((psbool)(InternalBuf+0x2027))) /*q0 - внутренний параметр*/
#define internal1_m1167_DvUp0 (*((pschar)(InternalBuf+0x2029))) /*- есть команда на движение вперёд*/
#define internal1_m1167_DvDw0 (*((pschar)(InternalBuf+0x202B))) /*- есть команда на движение назад*/
#define internal1_m1167_FDvUp0 (*((pschar)(InternalBuf+0x202D))) /*- есть команда на движение вперёд*/
#define internal1_m1167_FDvDw0 (*((pschar)(InternalBuf+0x202F))) /*- есть команда на движение назад*/
#define internal1_m1167_BlDv0 (*((pschar)(InternalBuf+0x2031))) /*- была блокировка*/
#define internal1_m1167_Pkv0 (*((pschar)(InternalBuf+0x2033))) /*Pkv - передний конечный выключатель*/
#define internal1_m1167_Pkav0 (*((pschar)(InternalBuf+0x2035))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m1167_Zkv0 (*((pschar)(InternalBuf+0x2037))) /*Zkv - задний конечный выключатель*/
#define internal1_m1167_Zkav0 (*((pschar)(InternalBuf+0x2039))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m1167_txNm (*((psfloat)(InternalBuf+0x203B))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m1167_txSm (*((psfloat)(InternalBuf+0x2040))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m1167_txHr (*((psfloat)(InternalBuf+0x2045))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m1167_txLd (*((psfloat)(InternalBuf+0x204A))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m1167_fef (*((pschar)(InternalBuf+0x204F))) /*fef*/
#define internal1_m1157_DvUp0 (*((pschar)(InternalBuf+0x2051))) /*- есть команда на движение вперёд*/
#define internal1_m1157_DvDw0 (*((pschar)(InternalBuf+0x2053))) /*- есть команда на движение назад*/
#define internal1_m1157_FDvUp0 (*((pschar)(InternalBuf+0x2055))) /*- есть команда на движение вперёд*/
#define internal1_m1157_FDvDw0 (*((pschar)(InternalBuf+0x2057))) /*- есть команда на движение назад*/
#define internal1_m1157_BlDv0 (*((pschar)(InternalBuf+0x2059))) /*- была блокировка*/
#define internal1_m1157_Pkv0 (*((pschar)(InternalBuf+0x205B))) /*Pkv - передний конечный выключатель*/
#define internal1_m1157_Pkav0 (*((pschar)(InternalBuf+0x205D))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m1157_Zkv0 (*((pschar)(InternalBuf+0x205F))) /*Zkv - задний конечный выключатель*/
#define internal1_m1157_Zkav0 (*((pschar)(InternalBuf+0x2061))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m1157_txNm (*((psfloat)(InternalBuf+0x2063))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m1157_txSm (*((psfloat)(InternalBuf+0x2068))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m1157_txHr (*((psfloat)(InternalBuf+0x206D))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m1157_txLd (*((psfloat)(InternalBuf+0x2072))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m1157_fef (*((pschar)(InternalBuf+0x2077))) /*fef*/
#define internal1_m780_DvUp0 (*((pschar)(InternalBuf+0x2079))) /*- есть команда на движение вперёд*/
#define internal1_m780_DvDw0 (*((pschar)(InternalBuf+0x207B))) /*- есть команда на движение назад*/
#define internal1_m780_FDvUp0 (*((pschar)(InternalBuf+0x207D))) /*- есть команда на движение вперёд*/
#define internal1_m780_FDvDw0 (*((pschar)(InternalBuf+0x207F))) /*- есть команда на движение назад*/
#define internal1_m780_BlDv0 (*((pschar)(InternalBuf+0x2081))) /*- была блокировка*/
#define internal1_m780_Pkv0 (*((pschar)(InternalBuf+0x2083))) /*Pkv - передний конечный выключатель*/
#define internal1_m780_Pkav0 (*((pschar)(InternalBuf+0x2085))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m780_Zkv0 (*((pschar)(InternalBuf+0x2087))) /*Zkv - задний конечный выключатель*/
#define internal1_m780_Zkav0 (*((pschar)(InternalBuf+0x2089))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m780_txNm (*((psfloat)(InternalBuf+0x208B))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m780_txSm (*((psfloat)(InternalBuf+0x2090))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m780_txHr (*((psfloat)(InternalBuf+0x2095))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m780_txLd (*((psfloat)(InternalBuf+0x209A))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m780_fef (*((pschar)(InternalBuf+0x209F))) /*fef*/
#define internal1_m776_DvUp0 (*((pschar)(InternalBuf+0x20A1))) /*- есть команда на движение вперёд*/
#define internal1_m776_DvDw0 (*((pschar)(InternalBuf+0x20A3))) /*- есть команда на движение назад*/
#define internal1_m776_FDvUp0 (*((pschar)(InternalBuf+0x20A5))) /*- есть команда на движение вперёд*/
#define internal1_m776_FDvDw0 (*((pschar)(InternalBuf+0x20A7))) /*- есть команда на движение назад*/
#define internal1_m776_BlDv0 (*((pschar)(InternalBuf+0x20A9))) /*- была блокировка*/
#define internal1_m776_Pkv0 (*((pschar)(InternalBuf+0x20AB))) /*Pkv - передний конечный выключатель*/
#define internal1_m776_Pkav0 (*((pschar)(InternalBuf+0x20AD))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m776_Zkv0 (*((pschar)(InternalBuf+0x20AF))) /*Zkv - задний конечный выключатель*/
#define internal1_m776_Zkav0 (*((pschar)(InternalBuf+0x20B1))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m776_txNm (*((psfloat)(InternalBuf+0x20B3))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m776_txSm (*((psfloat)(InternalBuf+0x20B8))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m776_txHr (*((psfloat)(InternalBuf+0x20BD))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m776_txLd (*((psfloat)(InternalBuf+0x20C2))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m776_fef (*((pschar)(InternalBuf+0x20C7))) /*fef*/
#define internal1_m358_DvUp0 (*((pschar)(InternalBuf+0x20C9))) /*- есть команда на движение вперёд*/
#define internal1_m358_DvDw0 (*((pschar)(InternalBuf+0x20CB))) /*- есть команда на движение назад*/
#define internal1_m358_FDvUp0 (*((pschar)(InternalBuf+0x20CD))) /*- есть команда на движение вперёд*/
#define internal1_m358_FDvDw0 (*((pschar)(InternalBuf+0x20CF))) /*- есть команда на движение назад*/
#define internal1_m358_BlDv0 (*((pschar)(InternalBuf+0x20D1))) /*- была блокировка*/
#define internal1_m358_Pkv0 (*((pschar)(InternalBuf+0x20D3))) /*Pkv - передний конечный выключатель*/
#define internal1_m358_Pkav0 (*((pschar)(InternalBuf+0x20D5))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m358_Zkv0 (*((pschar)(InternalBuf+0x20D7))) /*Zkv - задний конечный выключатель*/
#define internal1_m358_Zkav0 (*((pschar)(InternalBuf+0x20D9))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m358_txNm (*((psfloat)(InternalBuf+0x20DB))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m358_txSm (*((psfloat)(InternalBuf+0x20E0))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m358_txHr (*((psfloat)(InternalBuf+0x20E5))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m358_txLd (*((psfloat)(InternalBuf+0x20EA))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m358_fef (*((pschar)(InternalBuf+0x20EF))) /*fef*/
#define internal1_m387_DvUp0 (*((pschar)(InternalBuf+0x20F1))) /*- есть команда на движение вперёд*/
#define internal1_m387_DvDw0 (*((pschar)(InternalBuf+0x20F3))) /*- есть команда на движение назад*/
#define internal1_m387_FDvUp0 (*((pschar)(InternalBuf+0x20F5))) /*- есть команда на движение вперёд*/
#define internal1_m387_FDvDw0 (*((pschar)(InternalBuf+0x20F7))) /*- есть команда на движение назад*/
#define internal1_m387_BlDv0 (*((pschar)(InternalBuf+0x20F9))) /*- была блокировка*/
#define internal1_m387_Pkv0 (*((pschar)(InternalBuf+0x20FB))) /*Pkv - передний конечный выключатель*/
#define internal1_m387_Pkav0 (*((pschar)(InternalBuf+0x20FD))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m387_Zkv0 (*((pschar)(InternalBuf+0x20FF))) /*Zkv - задний конечный выключатель*/
#define internal1_m387_Zkav0 (*((pschar)(InternalBuf+0x2101))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m387_txNm (*((psfloat)(InternalBuf+0x2103))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m387_txSm (*((psfloat)(InternalBuf+0x2108))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m387_txHr (*((psfloat)(InternalBuf+0x210D))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m387_txLd (*((psfloat)(InternalBuf+0x2112))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m387_fef (*((pschar)(InternalBuf+0x2117))) /*fef*/
#define internal1_m381_DvUp0 (*((pschar)(InternalBuf+0x2119))) /*- есть команда на движение вперёд*/
#define internal1_m381_DvDw0 (*((pschar)(InternalBuf+0x211B))) /*- есть команда на движение назад*/
#define internal1_m381_FDvUp0 (*((pschar)(InternalBuf+0x211D))) /*- есть команда на движение вперёд*/
#define internal1_m381_FDvDw0 (*((pschar)(InternalBuf+0x211F))) /*- есть команда на движение назад*/
#define internal1_m381_BlDv0 (*((pschar)(InternalBuf+0x2121))) /*- была блокировка*/
#define internal1_m381_Pkv0 (*((pschar)(InternalBuf+0x2123))) /*Pkv - передний конечный выключатель*/
#define internal1_m381_Pkav0 (*((pschar)(InternalBuf+0x2125))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m381_Zkv0 (*((pschar)(InternalBuf+0x2127))) /*Zkv - задний конечный выключатель*/
#define internal1_m381_Zkav0 (*((pschar)(InternalBuf+0x2129))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m381_txNm (*((psfloat)(InternalBuf+0x212B))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m381_txSm (*((psfloat)(InternalBuf+0x2130))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m381_txHr (*((psfloat)(InternalBuf+0x2135))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m381_txLd (*((psfloat)(InternalBuf+0x213A))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m381_fef (*((pschar)(InternalBuf+0x213F))) /*fef*/
#define internal1_m732_q0 (*((psbool)(InternalBuf+0x2141))) /*q0 - внутренний параметр*/
#define internal1_m729_q0 (*((psbool)(InternalBuf+0x2143))) /*q0 - внутренний параметр*/
int InternalBufSize = 8517;

/* Определение сигналов */
#define signal_R0MW15IP1     (*((psint)(PBSTART+0x0)))  /*                       Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ */
#define signal_R0MW14IP1     (*((psint)(PBSTART+0x3)))  /*                       Переключатель ПРОГРАММЫ */
#define signal_R0MW12IP1     (*((psint)(PBSTART+0x6)))  /*                       Переключатель РЕЖИМ РАБОТЫ */
#define signal_R0MW12IP1     (*((psint)(PBSTART+0x6)))  /*                       Переключатель РЕЖИМ РАБОТЫ */
#define signal_R0MW13IP1     (*((psint)(PBSTART+0x9)))  /*                       Переключатель ВЫБОР ЗОН */
#define signal_R0MW16IP1     (*((psint)(PBSTART+0xc)))  /*                       Переключатель ВИД ПРОВЕРКИ */
#define signal_R0MW11IP1     (*((psint)(PBSTART+0xf)))  /*                       Переключатель ВЫСТРЕЛ */
#define signal_R0MW11IP2     (*((psint)(PBSTART+0x12)))  /*                       Переключатель ПРОВЕРКА СХЕМ СБРОСА */
#define signal_R0MW13LP2     (*((psbool)(PBSTART+0x15)))  /*                       Переключатель СЕТЬ */
#define signal_R0MD32LP1     (*((psbool)(PBSTART+0x17)))  /*                       Кнопка СПУСК */
#define signal_R0MD31LP1     (*((psbool)(PBSTART+0x19)))  /*                       Кнопка СТОП */
#define signal_A1IS21LDU     (*((psbool)(PBSTART+0x1b)))  /*                       Приход на НУ ББ1 */
#define signal_A1IS21LDU     (*((psbool)(PBSTART+0x1b)))  /*                       Приход на НУ ББ1 */
#define signal_A1IS21LDU     (*((psbool)(PBSTART+0x1b)))  /*                       Приход на НУ ББ1 */
#define signal_A2IS21LDU     (*((psbool)(PBSTART+0x1d)))  /*                       Приход на НУ РБ1-СС */
#define signal_A2IS21LDU     (*((psbool)(PBSTART+0x1d)))  /*                       Приход на НУ РБ1-СС */
#define signal_A2IS21LDU     (*((psbool)(PBSTART+0x1d)))  /*                       Приход на НУ РБ1-СС */
#define signal_A2IS21LDU     (*((psbool)(PBSTART+0x1d)))  /*                       Приход на НУ РБ1-СС */
#define signal_A2IS21LDU     (*((psbool)(PBSTART+0x1d)))  /*                       Приход на НУ РБ1-СС */
#define signal_A2IS21LDU     (*((psbool)(PBSTART+0x1d)))  /*                       Приход на НУ РБ1-СС */
#define signal_A3IS21LDU     (*((psbool)(PBSTART+0x1f)))  /*                       Приход на НУ ИС1 */
#define signal_A3IS21LDU     (*((psbool)(PBSTART+0x1f)))  /*                       Приход на НУ ИС1 */
#define signal_B1IS21LDU     (*((psbool)(PBSTART+0x21)))  /*                       Приход на НУ ББ2 */
#define signal_B1IS21LDU     (*((psbool)(PBSTART+0x21)))  /*                       Приход на НУ ББ2 */
#define signal_B1IS21LDU     (*((psbool)(PBSTART+0x21)))  /*                       Приход на НУ ББ2 */
#define signal_B2IS21LDU     (*((psbool)(PBSTART+0x23)))  /*                       Приход на НУ РБ2-СС */
#define signal_B2IS21LDU     (*((psbool)(PBSTART+0x23)))  /*                       Приход на НУ РБ2-СС */
#define signal_B2IS21LDU     (*((psbool)(PBSTART+0x23)))  /*                       Приход на НУ РБ2-СС */
#define signal_B2IS21LDU     (*((psbool)(PBSTART+0x23)))  /*                       Приход на НУ РБ2-СС */
#define signal_B2IS21LDU     (*((psbool)(PBSTART+0x23)))  /*                       Приход на НУ РБ2-СС */
#define signal_B2IS21LDU     (*((psbool)(PBSTART+0x23)))  /*                       Приход на НУ РБ2-СС */
#define signal_B3IS21LDU     (*((psbool)(PBSTART+0x25)))  /*                       Приход на НУ ИС2 */
#define signal_B3IS21LDU     (*((psbool)(PBSTART+0x25)))  /*                       Приход на НУ ИС2 */
#define signal_R0ES01LDU     (*((psbool)(PBSTART+0x27)))  /*                       ОРР не в исходном состоянии */
#define signal_R4MD11LP2     (*((psbool)(PBSTART+0x29)))  /*                       Кнопка ВПЕРЁД  (тележки) */
#define signal_R4MD31LP2     (*((psbool)(PBSTART+0x2b)))  /*                       Кнопка СТОП  (тележки) */
#define signal_R4MD21LP2     (*((psbool)(PBSTART+0x2d)))  /*                       Кнопка НАЗАД  (тележки) */
#define signal_A6IS11LDU     (*((psbool)(PBSTART+0x2f)))  /*                       Приход на ВУ БЗ1 */
#define signal_A6IS11LDU     (*((psbool)(PBSTART+0x2f)))  /*                       Приход на ВУ БЗ1 */
#define signal_A6IS21LDU     (*((psbool)(PBSTART+0x31)))  /*                       Приход на НУ БЗ1 */
#define signal_B6IS11LDU     (*((psbool)(PBSTART+0x33)))  /*                       Приход на ВУ БЗ2 */
#define signal_B6IS11LDU     (*((psbool)(PBSTART+0x33)))  /*                       Приход на ВУ БЗ2 */
#define signal_B6IS21LDU     (*((psbool)(PBSTART+0x35)))  /*                       Приход на НУ БЗ2 */
#define signal_A6VS22LDU     (*((psbool)(PBSTART+0x37)))  /*                       Движение створок БЗ1  к ЗАКРЫТА */
#define signal_A6VS12LDU     (*((psbool)(PBSTART+0x39)))  /*                       Движение створок БЗ1  к  ОТКРЫТА */
#define signal_B6VS22LDU     (*((psbool)(PBSTART+0x3b)))  /*                       Движение створок БЗ2  к «ЗАКРЫТА» */
#define signal_B6VS12LDU     (*((psbool)(PBSTART+0x3d)))  /*                       Движение створок БЗ2  к  ОТКРЫТА */
#define signal_A6AD10LDU     (*((psbool)(PBSTART+0x3f)))  /*                       Открыть БЗ1 */
#define signal_A6AD20LDU     (*((psbool)(PBSTART+0x41)))  /*                       Закрыть БЗ1 */
#define signal_B6AD10LDU     (*((psbool)(PBSTART+0x43)))  /*                       Открыть БЗ2 */
#define signal_B6AD20LDU     (*((psbool)(PBSTART+0x45)))  /*                       Закрыть БЗ2 */
#define signal_A6AZ03LDU     (*((psbool)(PBSTART+0x47)))  /*                       Несанкционированное перемещение БЗ1 */
#define signal_A6AB01LDU     (*((psbool)(PBSTART+0x49)))  /*                       Блокировка движения БЗ1 - Превышение времени движения */
#define signal_A6AB02LDU     (*((psbool)(PBSTART+0x4b)))  /*                       Блокировка движения БЗ1 - Нет перемещения */
#define signal_B6AZ03LDU     (*((psbool)(PBSTART+0x4d)))  /*                       Несанкционированное перемещение БЗ2 */
#define signal_B6AB01LDU     (*((psbool)(PBSTART+0x4f)))  /*                       Блокировка движения движения БЗ2 - Превышение времени движения */
#define signal_B6AB02LDU     (*((psbool)(PBSTART+0x51)))  /*                       Блокировка движения БЗ2 - Нет перемещения */
#define signal_A6AB04LDU     (*((psbool)(PBSTART+0x53)))  /*                       Блокировка движения БЗ1 -Ошибка в направлении  движения */
#define signal_B6AB04LDU     (*((psbool)(PBSTART+0x55)))  /*                       Блокировка движения БЗ2 -Ошибка в направлении  движения */
#define signal_R4AB01LDU     (*((psbool)(PBSTART+0x57)))  /*                       Блокировка движения тележки - АНИ не установлен */
#define signal_R8IS11LDU     (*((psbool)(PBSTART+0x59)))  /*                       Аварийный НИ установлен */
#define signal_R8IS11LDU     (*((psbool)(PBSTART+0x59)))  /*                       Аварийный НИ установлен */
#define signal_R8IS11LDU     (*((psbool)(PBSTART+0x59)))  /*                       Аварийный НИ установлен */
#define signal_R8IS11LDU     (*((psbool)(PBSTART+0x59)))  /*                       Аварийный НИ установлен */
#define signal_R8IS11LDU     (*((psbool)(PBSTART+0x59)))  /*                       Аварийный НИ установлен */
#define signal_R8IS11LDU     (*((psbool)(PBSTART+0x59)))  /*                       Аварийный НИ установлен */
#define signal_R8IS11LDU     (*((psbool)(PBSTART+0x59)))  /*                       Аварийный НИ установлен */
#define signal_R8IS11LDU     (*((psbool)(PBSTART+0x59)))  /*                       Аварийный НИ установлен */
#define signal_R8IS11LDU     (*((psbool)(PBSTART+0x59)))  /*                       Аварийный НИ установлен */
#define signal_R8IS11LDU     (*((psbool)(PBSTART+0x59)))  /*                       Аварийный НИ установлен */
#define signal_R6IS21LDU     (*((psbool)(PBSTART+0x5b)))  /*                       Кран-балка в нерабочем положении */
#define signal_A0VN71LZ2     (*((psbool)(PBSTART+0x5d)))  /*                       АЗ по АС мощности для АЗ1 */
#define signal_A0VN71LZ1     (*((psbool)(PBSTART+0x5f)))  /*                       АЗ по АС мощности для АЗ1 */
#define signal_R0NE01LDU     (*((psbool)(PBSTART+0x61)))  /*                       Потеря связи с БАЗ1 */
#define signal_R0NE02LDU     (*((psbool)(PBSTART+0x63)))  /*                       Потеря связи с БАЗ2 */
#define signal_R4AB02LDU     (*((psbool)(PBSTART+0x65)))  /*                       Блокировка движения тележки - Потеря связи с БАЗ, ОПУ */
#define signal_R0NE08LDU     (*((psbool)(PBSTART+0x67)))  /*                       Потеря связи с ОПУ */
#define signal_R4IS21LDU     (*((psbool)(PBSTART+0x69)))  /*                       Приход на НУ1 тележки */
#define signal_R4IS22LDU     (*((psbool)(PBSTART+0x6b)))  /*                       Приход на НУ2 тележки */
#define signal_R4IS12LDU     (*((psbool)(PBSTART+0x6d)))  /*                       Приход ВУ2 тележки */
#define signal_R4VS22LDU     (*((psbool)(PBSTART+0x6f)))  /*                       Движение реактора к У ЗАЩИТЫ */
#define signal_R4VS12LDU     (*((psbool)(PBSTART+0x71)))  /*                       Движение реактора  к У ОБРАЗЦОВ */
#define signal_R4AZ03LDU     (*((psbool)(PBSTART+0x73)))  /*                       Несанкционированное перемещение тележки */
#define signal_R4AB03LDU     (*((psbool)(PBSTART+0x75)))  /*                       Блокировка движения тележки - Самоход любого механизма */
#define signal_R1IS21LDU     (*((psbool)(PBSTART+0x77)))  /*                       Приход на НУ МДЗ1 */
#define signal_R1IS21LDU     (*((psbool)(PBSTART+0x77)))  /*                       Приход на НУ МДЗ1 */
#define signal_R1IS21LDU     (*((psbool)(PBSTART+0x77)))  /*                       Приход на НУ МДЗ1 */
#define signal_R1IS21LDU     (*((psbool)(PBSTART+0x77)))  /*                       Приход на НУ МДЗ1 */
#define signal_R2IS21LDU     (*((psbool)(PBSTART+0x79)))  /*                       Приход на НУ МДЗ2 */
#define signal_R2IS21LDU     (*((psbool)(PBSTART+0x79)))  /*                       Приход на НУ МДЗ2 */
#define signal_R2IS21LDU     (*((psbool)(PBSTART+0x79)))  /*                       Приход на НУ МДЗ2 */
#define signal_R2IS21LDU     (*((psbool)(PBSTART+0x79)))  /*                       Приход на НУ МДЗ2 */
#define signal_R4AB04LDU     (*((psbool)(PBSTART+0x7b)))  /*                       Блокировка движения тележки - Превышение времени движения */
#define signal_R4AB05LDU     (*((psbool)(PBSTART+0x7d)))  /*                       Блокировка движения  тележки - Нет перемещения тележки */
#define signal_R4AB06LDU     (*((psbool)(PBSTART+0x7f)))  /*                       Блокировка движения тележки - Ошибка в  направлении перемещения */
#define signal_R4AB07LDU     (*((psbool)(PBSTART+0x81)))  /*                       Блокировка движения тележки - ОРР не в исходном состоянии */
#define signal_R4AB08LDU     (*((psbool)(PBSTART+0x83)))  /*                       Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм) */
#define signal_R4AB09LDU     (*((psbool)(PBSTART+0x85)))  /*                       Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ */
#define signal_B0VN71LZ1     (*((psbool)(PBSTART+0x87)))  /*                       АЗ по АС мощности для АЗ2 */
#define signal_B0VN71LZ2     (*((psbool)(PBSTART+0x89)))  /*                       АЗ по АС мощности для АЗ2 */
#define signal_R4AB10LDU     (*((psbool)(PBSTART+0x8b)))  /*                       Блокировка тележки - не открыта биологическая защита */
#define signal_R4AB11LDU     (*((psbool)(PBSTART+0x8d)))  /*                       Блокировка движения тележки - МДЗ1,2 не находятся на НУ */
#define signal_R4AB12LDU     (*((psbool)(PBSTART+0x8f)))  /*                       Блокировка движения тележки - НИ не в положении ВУ */
#define signal_A4IS11LDU     (*((psbool)(PBSTART+0x91)))  /*                       Приход на ВУ НИ1 */
#define signal_A4IS11LDU     (*((psbool)(PBSTART+0x91)))  /*                       Приход на ВУ НИ1 */
#define signal_A4IS11LDU     (*((psbool)(PBSTART+0x91)))  /*                       Приход на ВУ НИ1 */
#define signal_A4IS11LDU     (*((psbool)(PBSTART+0x91)))  /*                       Приход на ВУ НИ1 */
#define signal_A4IS11LDU     (*((psbool)(PBSTART+0x91)))  /*                       Приход на ВУ НИ1 */
#define signal_A4IS11LDU     (*((psbool)(PBSTART+0x91)))  /*                       Приход на ВУ НИ1 */
#define signal_A4IS11LDU     (*((psbool)(PBSTART+0x91)))  /*                       Приход на ВУ НИ1 */
#define signal_A4IS11LDU     (*((psbool)(PBSTART+0x91)))  /*                       Приход на ВУ НИ1 */
#define signal_A4IS11LDU     (*((psbool)(PBSTART+0x91)))  /*                       Приход на ВУ НИ1 */
#define signal_A4IS11LDU     (*((psbool)(PBSTART+0x91)))  /*                       Приход на ВУ НИ1 */
#define signal_B4IS11LDU     (*((psbool)(PBSTART+0x93)))  /*                       Приход на ВУ НИ2 */
#define signal_B4IS11LDU     (*((psbool)(PBSTART+0x93)))  /*                       Приход на ВУ НИ2 */
#define signal_B4IS11LDU     (*((psbool)(PBSTART+0x93)))  /*                       Приход на ВУ НИ2 */
#define signal_B4IS11LDU     (*((psbool)(PBSTART+0x93)))  /*                       Приход на ВУ НИ2 */
#define signal_B4IS11LDU     (*((psbool)(PBSTART+0x93)))  /*                       Приход на ВУ НИ2 */
#define signal_B4IS11LDU     (*((psbool)(PBSTART+0x93)))  /*                       Приход на ВУ НИ2 */
#define signal_B4IS11LDU     (*((psbool)(PBSTART+0x93)))  /*                       Приход на ВУ НИ2 */
#define signal_B4IS11LDU     (*((psbool)(PBSTART+0x93)))  /*                       Приход на ВУ НИ2 */
#define signal_B4IS11LDU     (*((psbool)(PBSTART+0x93)))  /*                       Приход на ВУ НИ2 */
#define signal_B4IS11LDU     (*((psbool)(PBSTART+0x93)))  /*                       Приход на ВУ НИ2 */
#define signal_R4AB13LDU     (*((psbool)(PBSTART+0x95)))  /*                       Блокировка тележки - НЛ не в положении ВУ */
#define signal_R4AB14LDU     (*((psbool)(PBSTART+0x97)))  /*                       Блокировка движения тележки - Кран - балка не в безопасном положении */
#define signal_R4AB15LDU     (*((psbool)(PBSTART+0x99)))  /*                       Блокировка движения тележки - ворота в пом. 0041 не в положении Открыто */
#define signal_R5IS11LDU     (*((psbool)(PBSTART+0x9b)))  /*                       Приход на ВУ ворот отстойной зоны */
#define signal_R5IS11LDU     (*((psbool)(PBSTART+0x9b)))  /*                       Приход на ВУ ворот отстойной зоны */
#define signal_R5IS11LDU     (*((psbool)(PBSTART+0x9b)))  /*                       Приход на ВУ ворот отстойной зоны */
#define signal_R5IS11LDU     (*((psbool)(PBSTART+0x9b)))  /*                       Приход на ВУ ворот отстойной зоны */
#define signal_R4AB16LDU     (*((psbool)(PBSTART+0x9d)))  /*                       Блокировка движения тележки - Гомогенные двери не в положении Закрыты */
#define signal_R4AB17LDU     (*((psbool)(PBSTART+0x9f)))  /*                       Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора */
#define signal_R4AB18LDU     (*((psbool)(PBSTART+0xa1)))  /*                       Блокировка движения тележки назад - тележка на нижних механических упорах реактора */
#define signal_R4AD10LDU     (*((psbool)(PBSTART+0xa3)))  /*                       Перемещение тележки вперед */
#define signal_R4AD20LDU     (*((psbool)(PBSTART+0xa5)))  /*                       Перемещение тележки назад */
#define signal_A5VS22LDU     (*((psbool)(PBSTART+0xa7)))  /*                       Движение НЛ1 в сторону НУ */
#define signal_A5VS12LDU     (*((psbool)(PBSTART+0xa9)))  /*                       Движение НЛ1 в сторону ВУ */
#define signal_B5VS22LDU     (*((psbool)(PBSTART+0xab)))  /*                       Движение НЛ2 в сторону НУ */
#define signal_B5VS12LDU     (*((psbool)(PBSTART+0xad)))  /*                       Движение НЛ2 в сторону ВУ */
#define signal_B5AD10LDU     (*((psbool)(PBSTART+0xaf)))  /*                       Поднять НЛ2 */
#define signal_B5AD20LDU     (*((psbool)(PBSTART+0xb1)))  /*                       Опустить НЛ2 */
#define signal_A5AD10LDU     (*((psbool)(PBSTART+0xb3)))  /*                       Поднять НЛ1 */
#define signal_A5AD20LDU     (*((psbool)(PBSTART+0xb5)))  /*                       Опустить НЛ1 */
#define signal_A5IS11LDU     (*((psbool)(PBSTART+0xb7)))  /*                       Приход на ВУ НЛ1 */
#define signal_A5IS11LDU     (*((psbool)(PBSTART+0xb7)))  /*                       Приход на ВУ НЛ1 */
#define signal_A5IS21LDU     (*((psbool)(PBSTART+0xb9)))  /*                       Приход на НУ НЛ1 */
#define signal_A5IS21LDU     (*((psbool)(PBSTART+0xb9)))  /*                       Приход на НУ НЛ1 */
#define signal_B5IS11LDU     (*((psbool)(PBSTART+0xbb)))  /*                       Приход на ВУ НЛ2 */
#define signal_B5IS11LDU     (*((psbool)(PBSTART+0xbb)))  /*                       Приход на ВУ НЛ2 */
#define signal_B5IS21LDU     (*((psbool)(PBSTART+0xbd)))  /*                       Приход на НУ НЛ2 */
#define signal_A5AZ03LDU     (*((psbool)(PBSTART+0xbf)))  /*                       Несанкционированное перемещение НЛ1 */
#define signal_A5AB01LDU     (*((psbool)(PBSTART+0xc1)))  /*                       Блокировка движения НЛ1 - Превышение времени движения */
#define signal_A5AB02LDU     (*((psbool)(PBSTART+0xc3)))  /*                       Блокировка движения НЛ1 - Нет перемещения */
#define signal_B5AZ03LDU     (*((psbool)(PBSTART+0xc5)))  /*                       Несанкционированное перемещение НЛ2 */
#define signal_B5AB01LDU     (*((psbool)(PBSTART+0xc7)))  /*                       Блокировка движения НЛ2 - Превышение времени движения */
#define signal_B5AB02LDU     (*((psbool)(PBSTART+0xc9)))  /*                       Блокировка движения НЛ2 - Нет перемещения */
#define signal_A4IS21LDU     (*((psbool)(PBSTART+0xcb)))  /*                       Приход на НУ НИ1 */
#define signal_A4IS21LDU     (*((psbool)(PBSTART+0xcb)))  /*                       Приход на НУ НИ1 */
#define signal_A4IS21LDU     (*((psbool)(PBSTART+0xcb)))  /*                       Приход на НУ НИ1 */
#define signal_A4IS21LDU     (*((psbool)(PBSTART+0xcb)))  /*                       Приход на НУ НИ1 */
#define signal_B4IS21LDU     (*((psbool)(PBSTART+0xcd)))  /*                       Приход на НУ НИ2 */
#define signal_B4IS21LDU     (*((psbool)(PBSTART+0xcd)))  /*                       Приход на НУ НИ2 */
#define signal_B4IS21LDU     (*((psbool)(PBSTART+0xcd)))  /*                       Приход на НУ НИ2 */
#define signal_B4IS21LDU     (*((psbool)(PBSTART+0xcd)))  /*                       Приход на НУ НИ2 */
#define signal_B4AD10LDU     (*((psbool)(PBSTART+0xcf)))  /*                       Клапан Подъем НИ2 открыть (обесточить) */
#define signal_A4AD10LDU     (*((psbool)(PBSTART+0xd1)))  /*                       Клапан ПОДЪЕМ НИ1 открыть (обесточить) */
#define signal_A4AZ03LDU     (*((psbool)(PBSTART+0xd3)))  /*                       Несанкционированное перемещение НИ1 */
#define signal_A4AB01LDU     (*((psbool)(PBSTART+0xd5)))  /*                       Блокировка движения НИ1 - Превышение времени движения */
#define signal_A4AB02LDU     (*((psbool)(PBSTART+0xd7)))  /*                       Блокировка движения НИ1 - Нет перемещения */
#define signal_B4AZ03LDU     (*((psbool)(PBSTART+0xd9)))  /*                       Несанкционированное перемещение НИ2 */
#define signal_B4AB01LDU     (*((psbool)(PBSTART+0xdb)))  /*                       Блокировка движения НИ2 - Превышение времени движения */
#define signal_B4AB02LDU     (*((psbool)(PBSTART+0xdd)))  /*                       Блокировка движения НИ2 - Нет перемещения */
#define signal_A5AB04LDU     (*((psbool)(PBSTART+0xdf)))  /*                       Блокировка движения НЛ1 -Ошибка в направлении  движения */
#define signal_B5AB04LDU     (*((psbool)(PBSTART+0xe1)))  /*                       Блокировка движения НЛ2 -Ошибка в направлении  движения */
#define signal_A1IS12LDU     (*((psbool)(PBSTART+0xe3)))  /*                       Магнит ББ1 зацеплен */
#define signal_A1IS12LDU     (*((psbool)(PBSTART+0xe3)))  /*                       Магнит ББ1 зацеплен */
#define signal_A2IS12LDU     (*((psbool)(PBSTART+0xe5)))  /*                       Магнит РБ1 зацеплен */
#define signal_A2IS12LDU     (*((psbool)(PBSTART+0xe5)))  /*                       Магнит РБ1 зацеплен */
#define signal_A2IS12LDU     (*((psbool)(PBSTART+0xe5)))  /*                       Магнит РБ1 зацеплен */
#define signal_A2IS12LDU     (*((psbool)(PBSTART+0xe5)))  /*                       Магнит РБ1 зацеплен */
#define signal_A2IS12LDU     (*((psbool)(PBSTART+0xe5)))  /*                       Магнит РБ1 зацеплен */
#define signal_B1IS12LDU     (*((psbool)(PBSTART+0xe7)))  /*                       Магнит ББ2 зацеплен */
#define signal_B1IS12LDU     (*((psbool)(PBSTART+0xe7)))  /*                       Магнит ББ2 зацеплен */
#define signal_B2IS12LDU     (*((psbool)(PBSTART+0xe9)))  /*                       Магнит РБ2 зацеплен */
#define signal_B2IS12LDU     (*((psbool)(PBSTART+0xe9)))  /*                       Магнит РБ2 зацеплен */
#define signal_B2IS12LDU     (*((psbool)(PBSTART+0xe9)))  /*                       Магнит РБ2 зацеплен */
#define signal_B2IS12LDU     (*((psbool)(PBSTART+0xe9)))  /*                       Магнит РБ2 зацеплен */
#define signal_B2IS12LDU     (*((psbool)(PBSTART+0xe9)))  /*                       Магнит РБ2 зацеплен */
#define signal_R4IS11LDU     (*((psbool)(PBSTART+0xeb)))  /*                       Приход на ВУ1 тележки */
#define signal_A6AB06LDU     (*((psbool)(PBSTART+0xed)))  /*                       Блокировка открытия БЗ1 - ОРР не в исходном состоянии */
#define signal_A6AB07LDU     (*((psbool)(PBSTART+0xef)))  /*                       Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м */
#define signal_A6AB08LDU     (*((psbool)(PBSTART+0xf1)))  /*                       Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м */
#define signal_A6AB09LDU     (*((psbool)(PBSTART+0xf3)))  /*                       Блокировка открытия БЗ1 -ворота отстойной зоны не открыты */
#define signal_B6AB06LDU     (*((psbool)(PBSTART+0xf5)))  /*                       Блокировка открытия БЗ2 - ОРР не в исходном состоянии */
#define signal_B6AB07LDU     (*((psbool)(PBSTART+0xf7)))  /*                       Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м */
#define signal_B6AB08LDU     (*((psbool)(PBSTART+0xf9)))  /*                       Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м */
#define signal_B6AB09LDU     (*((psbool)(PBSTART+0xfb)))  /*                       Блокировка открытия БЗ2 -ворота отстойной зоны не открыты */
#define signal_A6AB05LDU     (*((psbool)(PBSTART+0xfd)))  /*                       Блокировка открытия БЗ1 - АНИ не установлен */
#define signal_B8VS12LDU     (*((psbool)(PBSTART+0xff)))  /*                       Движение АЗ2 в сторону ВУ */
#define signal_B8CV01RDU     (*((psfloat)(PBSTART+0x101)))  /*                       Измеренная скорость перемещения АЗ2 */
#define signal_B8AB06LDU     (*((psbool)(PBSTART+0x106)))  /*                       Блокировка движения АЗ2 нет перемещения АЗ2 */
#define signal_B8AB07LDU     (*((psbool)(PBSTART+0x108)))  /*                       Блокировка движения АЗ2: превышение заданной скорости */
#define signal_B8AB05LDU     (*((psbool)(PBSTART+0x10a)))  /*                       Блокировка движения АЗ2: скорость перемещения менее заданной */
#define signal_B8VS22LDU     (*((psbool)(PBSTART+0x10c)))  /*                       Движение АЗ2 в сторону НУ */
#define signal_B8AZ03LDU     (*((psbool)(PBSTART+0x10e)))  /*                       Несанкционированное перемещение АЗ2 */
#define signal_R0MD11LP1     (*((psbool)(PBSTART+0x110)))  /*                       Кнопка ПУСК */
#define signal_B8AD10LDU     (*((psbool)(PBSTART+0x112)))  /*                       Перемещение АЗ2 вперед */
#define signal_B8AD20LDU     (*((psbool)(PBSTART+0x114)))  /*                       Перемещение АЗ2 назад */
#define signal_B8IS11LDU     (*((psbool)(PBSTART+0x116)))  /*                       Приход на ВУ1 АЗ2 */
#define signal_B8IS11LDU     (*((psbool)(PBSTART+0x116)))  /*                       Приход на ВУ1 АЗ2 */
#define signal_B8AB01LDU     (*((psbool)(PBSTART+0x118)))  /*                       Блокировка движения АЗ2 - Превышение времени движения */
#define signal_B8AB04LDU     (*((psbool)(PBSTART+0x11a)))  /*                       Блокировка движения АЗ2 -Ошибка в направлении  движения */
#define signal_B8AB08LDU     (*((psbool)(PBSTART+0x11c)))  /*                       Блокировка движения АЗ2 Гомогенные двери не закрыты */
#define signal_B8AB09LDU     (*((psbool)(PBSTART+0x11e)))  /*                       Блокировка  движения  АЗ2 - АС по мощности от любого канала */
#define signal_B8AB10LDU     (*((psbool)(PBSTART+0x120)))  /*                       Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора */
#define signal_B8AB11LDU     (*((psbool)(PBSTART+0x122)))  /*                       Блокировка движения АЗ2 -нет сигнала готовности СУЗ */
#define signal_B8AB12LDU     (*((psbool)(PBSTART+0x124)))  /*                       Блокировка движения АЗ2 - НИ не в положении ВУ */
#define signal_B8AB13LDU     (*((psbool)(PBSTART+0x126)))  /*                       Блокировка движения АЗ2 - ОРР не в исходном состоянии */
#define signal_B8AB14LDU     (*((psbool)(PBSTART+0x128)))  /*                       Блокировка движения АЗ2 - Самоход любого механизма */
#define signal_B8AB02LDU     (*((psbool)(PBSTART+0x12a)))  /*                       Блокировка движения АЗ2- АНИ не установлен */
#define signal_A8VS12LDU     (*((psbool)(PBSTART+0x12c)))  /*                       Движение ДС2 в сторону ВУ */
#define signal_A8CV01RDU     (*((psfloat)(PBSTART+0x12e)))  /*                       Измеренная скорость перемещения ДС2 */
#define signal_A8AB06LDU     (*((psbool)(PBSTART+0x133)))  /*                       Блокировка движения ДС2 нет перемещения ДС2 */
#define signal_A8AB07LDU     (*((psbool)(PBSTART+0x135)))  /*                       Блокировка движения ДС2: превышение заданной скорости */
#define signal_A8AB05LDU     (*((psbool)(PBSTART+0x137)))  /*                       Блокировка движения ДС2: скорость перемещения менее заданной */
#define signal_A8VS22LDU     (*((psbool)(PBSTART+0x139)))  /*                       Движение ДС2 в сторону НУ */
#define signal_A8AZ03LDU     (*((psbool)(PBSTART+0x13b)))  /*                       Несанкционированное перемещение ДС2 */
#define signal_A8AD10LDU     (*((psbool)(PBSTART+0x13d)))  /*                       Перемещение ДС2 вперед */
#define signal_A8AD20LDU     (*((psbool)(PBSTART+0x13f)))  /*                       Перемещение ДС2 назад */
#define signal_B8IS22LDU     (*((psbool)(PBSTART+0x141)))  /*                       Приход на НУ2 АЗ2 */
#define signal_B8IS22LDU     (*((psbool)(PBSTART+0x141)))  /*                       Приход на НУ2 АЗ2 */
#define signal_B8IS22LDU     (*((psbool)(PBSTART+0x141)))  /*                       Приход на НУ2 АЗ2 */
#define signal_B8IS22LDU     (*((psbool)(PBSTART+0x141)))  /*                       Приход на НУ2 АЗ2 */
#define signal_A8IS12LDU     (*((psbool)(PBSTART+0x143)))  /*                       Приход на механический ВУ ДС2 */
#define signal_A8IS12LDU     (*((psbool)(PBSTART+0x143)))  /*                       Приход на механический ВУ ДС2 */
#define signal_A8AB04LDU     (*((psbool)(PBSTART+0x145)))  /*                       Блокировка ДС2 -Ошибка в направлении  движения */
#define signal_A8IS22LDU     (*((psbool)(PBSTART+0x147)))  /*                       Приход на механический НУ ДС2 */
#define signal_A8IS22LDU     (*((psbool)(PBSTART+0x147)))  /*                       Приход на механический НУ ДС2 */
#define signal_A8IS22LDU     (*((psbool)(PBSTART+0x147)))  /*                       Приход на механический НУ ДС2 */
#define signal_A8IS22LDU     (*((psbool)(PBSTART+0x147)))  /*                       Приход на механический НУ ДС2 */
#define signal_A8AB08LDU     (*((psbool)(PBSTART+0x149)))  /*                       Блокировка движения ДС2 Гомогенные двери не закрыты */
#define signal_A8AB09LDU     (*((psbool)(PBSTART+0x14b)))  /*                       Блокировка  движения ДС2 - АС по мощности от любого канала */
#define signal_A8AB10LDU     (*((psbool)(PBSTART+0x14d)))  /*                       Блокировка движения ДС2 - тележка не на верхних механических упорах реактора */
#define signal_A8AB11LDU     (*((psbool)(PBSTART+0x14f)))  /*                       Блокировка движения ДС2 -нет сигнала готовности СУЗ */
#define signal_A8AB12LDU     (*((psbool)(PBSTART+0x151)))  /*                       Блокировка движения ДС2 - НИ не в положении ВУ */
#define signal_A8AB13LDU     (*((psbool)(PBSTART+0x153)))  /*                       Блокировка движения ДС2 - ОРР не в исходном состоянии */
#define signal_A8AB14LDU     (*((psbool)(PBSTART+0x155)))  /*                       Блокировка движения ДС2 - Самоход любого механизма */
#define signal_A8AB02LDU     (*((psbool)(PBSTART+0x157)))  /*                       Блокировка движения ДС2- АНИ не установлен */
#define signal_A8AB01LDU     (*((psbool)(PBSTART+0x159)))  /*                       Блокировка ДС2 -Превышение времени перемещения */
#define signal_A2VS11LDU     (*((psbool)(PBSTART+0x15b)))  /*                       Движение РБ1 в сторону ВУ */
#define signal_A2CV01RDU     (*((psfloat)(PBSTART+0x15d)))  /*                       Измеренная скорость перемещения РБ1 */
#define signal_A2AB04LDU     (*((psbool)(PBSTART+0x162)))  /*                       Блокировка движения РБ1 нет перемещения  РБ1 */
#define signal_A2AB02LDU     (*((psbool)(PBSTART+0x164)))  /*                       Блокировка движения РБ1: превышение заданной скорости */
#define signal_A2AB01LDU     (*((psbool)(PBSTART+0x166)))  /*                       Блокировка движения РБ1: скорость перемещения менее заданной */
#define signal_A2VS21LDU     (*((psbool)(PBSTART+0x168)))  /*                       Движение РБ1 в сторону НУ */
#define signal_A2AZ03LDU     (*((psbool)(PBSTART+0x16a)))  /*                       Сброс РБ: Несанкционированное перемещение РБ1 */
#define signal_A2AD11LDU     (*((psbool)(PBSTART+0x16c)))  /*                       Сигнал на перемещение РБ1 вверх */
#define signal_A2AD21LDU     (*((psbool)(PBSTART+0x16e)))  /*                       Сигнал на перемещение РБ1 вниз */
#define signal_A2AD02LDU     (*((psbool)(PBSTART+0x170)))  /*                       0-й бит скорости РБ1 */
#define signal_A2AD03LDU     (*((psbool)(PBSTART+0x172)))  /*                       1-й бит скорости РБ1 */
#define signal_A2AD04LDU     (*((psbool)(PBSTART+0x174)))  /*                       2-й бит скорости РБ1 */
#define signal_A2AD05LDU     (*((psbool)(PBSTART+0x176)))  /*                       паритет команды на РБ1 */
#define signal_A2AB07LDU     (*((psbool)(PBSTART+0x178)))  /*                       Блокировка подъёма РБ1 Гомогенные двери не закрыты */
#define signal_A2AB08LDU     (*((psbool)(PBSTART+0x17a)))  /*                       Блокировка подъёма РБ1 - реактор не на рабочем месте */
#define signal_A2AB05LDU     (*((psbool)(PBSTART+0x17c)))  /*                       Блокировка подъёма РБ1 -нет сигнала готовности СУЗ */
#define signal_A2AB06LDU     (*((psbool)(PBSTART+0x17e)))  /*                       Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный */
#define signal_A2AB09LDU     (*((psbool)(PBSTART+0x180)))  /*                       Блокировка подъёма РБ1- АНИ не установлен */
#define signal_A2AB10LDU     (*((psbool)(PBSTART+0x182)))  /*                       Блокировка подъёма РБ1- есть сигнал общего сброса */
#define signal_A2AB11LDU     (*((psbool)(PBSTART+0x184)))  /*                       Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате */
#define signal_A2AB12LDU     (*((psbool)(PBSTART+0x186)))  /*                       Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ */
#define signal_A2AB13LDU     (*((psbool)(PBSTART+0x188)))  /*                       Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС */
#define signal_A2AB14LDU     (*((psbool)(PBSTART+0x18a)))  /*                       Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной */
#define signal_A2AB16LDU     (*((psbool)(PBSTART+0x18c)))  /*                       Блокировка перемещения РБ1: выполняется программа 200 с */
#define signal_A2AB17LDU     (*((psbool)(PBSTART+0x18e)))  /*                       Блокировка перемещения РБ1: выполняется программа 20 мин */
#define signal_A2AD01LDU     (*((psbool)(PBSTART+0x190)))  /*                       Разрешение движения РБ1 */
#define signal_A2CV02RDU     (*((psfloat)(PBSTART+0x192)))  /*                       Заданная скорость перемещения РБ1 */
#define signal_B2CV01RDU     (*((psfloat)(PBSTART+0x197)))  /*                       Измеренная скорость перемещения РБ2 */
#define signal_B2AB04LDU     (*((psbool)(PBSTART+0x19c)))  /*                       Блокировка движения РБ2 нет перемещения  РБ2 */
#define signal_B2AB02LDU     (*((psbool)(PBSTART+0x19e)))  /*                       Блокировка движения РБ2: превышение заданной скорости */
#define signal_B2AB01LDU     (*((psbool)(PBSTART+0x1a0)))  /*                       Блокировка движения РБ2: скорость перемещения менее заданной */
#define signal_B2AZ03LDU     (*((psbool)(PBSTART+0x1a2)))  /*                       Сброс РБ: Несанкционированное перемещение РБ2 */
#define signal_B2AD11LDU     (*((psbool)(PBSTART+0x1a4)))  /*                       Сигнал на перемещение РБ2 вверх */
#define signal_B2AD21LDU     (*((psbool)(PBSTART+0x1a6)))  /*                       Сигнал на перемещение РБ2 вниз */
#define signal_B2AD02LDU     (*((psbool)(PBSTART+0x1a8)))  /*                       0-й бит скорости РБ2 */
#define signal_B2AD03LDU     (*((psbool)(PBSTART+0x1aa)))  /*                       1-й бит скорости РБ2 */
#define signal_B2AD04LDU     (*((psbool)(PBSTART+0x1ac)))  /*                       2-й бит скорости РБ2 */
#define signal_B2AD05LDU     (*((psbool)(PBSTART+0x1ae)))  /*                       паритет команды на РБ2 */
#define signal_B2AD01LDU     (*((psbool)(PBSTART+0x1b0)))  /*                       Разрешение движения РБ2 */
#define signal_B2CV02RDU     (*((psfloat)(PBSTART+0x1b2)))  /*                       Заданная скорость перемещения РБ2 */
#define signal_B2AB07LDU     (*((psbool)(PBSTART+0x1b7)))  /*                       Блокировка подъёма РБ2 Гомогенные двери не закрыты */
#define signal_B2AB08LDU     (*((psbool)(PBSTART+0x1b9)))  /*                       Блокировка подъёма РБ2 - реактор не на рабочем месте */
#define signal_B2AB05LDU     (*((psbool)(PBSTART+0x1bb)))  /*                       Блокировка подъёма РБ2 -нет сигнала готовности СУЗ */
#define signal_B2AB06LDU     (*((psbool)(PBSTART+0x1bd)))  /*                       Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный */
#define signal_B2AB09LDU     (*((psbool)(PBSTART+0x1bf)))  /*                       Блокировка подъёма РБ2- АНИ не установлен */
#define signal_B2AB10LDU     (*((psbool)(PBSTART+0x1c1)))  /*                       Блокировка подъёма РБ2- есть сигнал общего сброса */
#define signal_B2AB11LDU     (*((psbool)(PBSTART+0x1c3)))  /*                       Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате */
#define signal_B2AB12LDU     (*((psbool)(PBSTART+0x1c5)))  /*                       Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ */
#define signal_B2AB13LDU     (*((psbool)(PBSTART+0x1c7)))  /*                       Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС */
#define signal_B2AB14LDU     (*((psbool)(PBSTART+0x1c9)))  /*                       Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной */
#define signal_B2AB16LDU     (*((psbool)(PBSTART+0x1cb)))  /*                       Блокировка перемещения РБ2: выполняется программа 200 с */
#define signal_B2AB17LDU     (*((psbool)(PBSTART+0x1cd)))  /*                       Блокировка перемещения РБ2: выполняется программа 20 мин */
#define signal_R1AZ03LDU     (*((psbool)(PBSTART+0x1cf)))  /*                       Несанкционированное перемещение МДЗ1 */
#define signal_R1AB01LDU     (*((psbool)(PBSTART+0x1d1)))  /*                       Блокировка движения МДЗ1 - Превышение времени движения */
#define signal_R1AB02LDU     (*((psbool)(PBSTART+0x1d3)))  /*                       Блокировка движения МДЗ1 - Нет перемещения МДЗ1 */
#define signal_R2AZ03LDU     (*((psbool)(PBSTART+0x1d5)))  /*                       Несанкционированное перемещение МДЗ2 */
#define signal_R2AB01LDU     (*((psbool)(PBSTART+0x1d7)))  /*                       Блокировка движения МДЗ2 - Превышение времени движения */
#define signal_R2AB02LDU     (*((psbool)(PBSTART+0x1d9)))  /*                       Блокировка движения МДЗ2 - Нет перемещения МДЗ2 */
#define signal_R1AB04LDU     (*((psbool)(PBSTART+0x1db)))  /*                       Блокировка движения МДЗ1 -Ошибка в направлении  движения */
#define signal_R2AB04LDU     (*((psbool)(PBSTART+0x1dd)))  /*                       Блокировка движения МДЗ2 -Ошибка в направлении  движения */
#define signal_R1AD10LDU     (*((psbool)(PBSTART+0x1df)))  /*                       Опустить МДЗ1 */
#define signal_R1AD20LDU     (*((psbool)(PBSTART+0x1e1)))  /*                       Поднять МДЗ1 */
#define signal_R1IS11LDU     (*((psbool)(PBSTART+0x1e3)))  /*                       Приход на ВУ МДЗ1 */
#define signal_R1IS11LDU     (*((psbool)(PBSTART+0x1e3)))  /*                       Приход на ВУ МДЗ1 */
#define signal_R1VS22LDU     (*((psbool)(PBSTART+0x1e5)))  /*                       Движение МДЗ1 в сторону НУ */
#define signal_R2VS22LDU     (*((psbool)(PBSTART+0x1e7)))  /*                       Движение МДЗ2 в сторону НУ */
#define signal_R2VS12LDU     (*((psbool)(PBSTART+0x1e9)))  /*                       Движение МДЗ2 в сторону ВУ */
#define signal_R1VS12LDU     (*((psbool)(PBSTART+0x1eb)))  /*                       Движение МДЗ1 в сторону ВУ */
#define signal_R2IS11LDU     (*((psbool)(PBSTART+0x1ed)))  /*                       Приход на ВУ МДЗ2 */
#define signal_R2IS11LDU     (*((psbool)(PBSTART+0x1ed)))  /*                       Приход на ВУ МДЗ2 */
#define signal_A1VS12LDU     (*((psbool)(PBSTART+0x1ef)))  /*                       Движение ББ1 в сторону ВУ */
#define signal_A1CV01RDU     (*((psfloat)(PBSTART+0x1f1)))  /*                       Измеренная скорость перемещения ББ1 */
#define signal_A1AB04LDU     (*((psbool)(PBSTART+0x1f6)))  /*                       Блокировка движения ББ1 нет перемещения  ББ1 */
#define signal_A1AB02LDU     (*((psbool)(PBSTART+0x1f8)))  /*                       Блокировка движения ББ1: превышение заданной скорости */
#define signal_A1AB01LDU     (*((psbool)(PBSTART+0x1fa)))  /*                       Блокировка движения ББ1: скорость перемещения менее заданной */
#define signal_A1VS22LDU     (*((psbool)(PBSTART+0x1fc)))  /*                       Движение ББ1 в сторону НУ */
#define signal_A1AZ03LDU     (*((psbool)(PBSTART+0x1fe)))  /*                       Сброс ББ: Несанкционированное перемещение ББ1 */
#define signal_A1AD11LDU     (*((psbool)(PBSTART+0x200)))  /*                       Сигнал на перемещение ББ1 вверх */
#define signal_A1AD21LDU     (*((psbool)(PBSTART+0x202)))  /*                       Сигнал на перемещение ББ1 вниз */
#define signal_A1AD02LDU     (*((psbool)(PBSTART+0x204)))  /*                       0-й бит скорости ББ1 */
#define signal_A1AD03LDU     (*((psbool)(PBSTART+0x206)))  /*                       1-й бит скорости ББ1 */
#define signal_A1AD04LDU     (*((psbool)(PBSTART+0x208)))  /*                       2-й бит скорости ББ1 */
#define signal_A1AD05LDU     (*((psbool)(PBSTART+0x20a)))  /*                       паритет команды на ББ1 */
#define signal_A1AD01LDU     (*((psbool)(PBSTART+0x20c)))  /*                       Разрешение движения ББ1 */
#define signal_A1CV02RDU     (*((psfloat)(PBSTART+0x20e)))  /*                       Заданная скорость перемещения ББ1 */
#define signal_A1AB07LDU     (*((psbool)(PBSTART+0x213)))  /*                       Блокировка подъёма ББ1 Гомогенные двери не закрыты */
#define signal_A1AB08LDU     (*((psbool)(PBSTART+0x215)))  /*                       Блокировка подъёма ББ1 - реактор не на рабочем месте */
#define signal_A1AB05LDU     (*((psbool)(PBSTART+0x217)))  /*                       Блокировка подъёма ББ1 -нет сигнала готовности СУЗ */
#define signal_A1AB06LDU     (*((psbool)(PBSTART+0x219)))  /*                       Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный */
#define signal_A1AB09LDU     (*((psbool)(PBSTART+0x21b)))  /*                       Блокировка подъёма ББ1- АНИ не установлен */
#define signal_A1AB10LDU     (*((psbool)(PBSTART+0x21d)))  /*                       Блокировка подъёма ББ1- есть сигнал общего сброса */
#define signal_A1AB11LDU     (*((psbool)(PBSTART+0x21f)))  /*                       Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате */
#define signal_A1AB12LDU     (*((psbool)(PBSTART+0x221)))  /*                       Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ */
#define signal_A1AB13LDU     (*((psbool)(PBSTART+0x223)))  /*                       Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС */
#define signal_A1AB14LDU     (*((psbool)(PBSTART+0x225)))  /*                       Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной */
#define signal_A1AB16LDU     (*((psbool)(PBSTART+0x227)))  /*                       Блокировка перемещения ББ1: выполняется программа 200 с */
#define signal_A1AB17LDU     (*((psbool)(PBSTART+0x229)))  /*                       Блокировка перемещения ББ1: выполняется программа 20 мин */
#define signal_A1AB18LDU     (*((psbool)(PBSTART+0x22b)))  /*                       Блокировка подъёма ББ1- РБ-СТР ниже 80 мм */
#define signal_B1VS12LDU     (*((psbool)(PBSTART+0x22d)))  /*                       Движение ББ2 в сторону ВУ */
#define signal_B1CV01RDU     (*((psfloat)(PBSTART+0x22f)))  /*                       Измеренная скорость перемещения ББ2 */
#define signal_B1AB04LDU     (*((psbool)(PBSTART+0x234)))  /*                       Блокировка движения ББ2 нет перемещения  ББ2 */
#define signal_B1AB02LDU     (*((psbool)(PBSTART+0x236)))  /*                       Блокировка движения ББ2: превышение заданной скорости */
#define signal_B1AB01LDU     (*((psbool)(PBSTART+0x238)))  /*                       Блокировка движения ББ2: скорость перемещения менее заданной */
#define signal_B1VS22LDU     (*((psbool)(PBSTART+0x23a)))  /*                       Движение ББ2 в сторону НУ */
#define signal_B1AZ03LDU     (*((psbool)(PBSTART+0x23c)))  /*                       Сброс ББ: Несанкционированное перемещение ББ2 */
#define signal_B1AD11LDU     (*((psbool)(PBSTART+0x23e)))  /*                       Сигнал на перемещение ББ2 вверх */
#define signal_B1AD21LDU     (*((psbool)(PBSTART+0x240)))  /*                       Сигнал на перемещение ББ2 вниз */
#define signal_B1AD02LDU     (*((psbool)(PBSTART+0x242)))  /*                       0-й бит скорости ББ2 */
#define signal_B1AD03LDU     (*((psbool)(PBSTART+0x244)))  /*                       1-й бит скорости ББ2 */
#define signal_B1AD04LDU     (*((psbool)(PBSTART+0x246)))  /*                       2-й бит скорости ББ2 */
#define signal_B1AD05LDU     (*((psbool)(PBSTART+0x248)))  /*                       паритет команды на ББ2 */
#define signal_B1AD01LDU     (*((psbool)(PBSTART+0x24a)))  /*                       Разрешение движения ББ2 */
#define signal_B1CV02RDU     (*((psfloat)(PBSTART+0x24c)))  /*                       Заданная скорость перемещения ББ2 */
#define signal_B1AB07LDU     (*((psbool)(PBSTART+0x251)))  /*                       Блокировка подъёма ББ2 Гомогенные двери не закрыты */
#define signal_B1AB08LDU     (*((psbool)(PBSTART+0x253)))  /*                       Блокировка подъёма ББ2 - реактор не на рабочем месте */
#define signal_B1AB05LDU     (*((psbool)(PBSTART+0x255)))  /*                       Блокировка подъёма ББ2 -нет сигнала готовности СУЗ */
#define signal_B1AB06LDU     (*((psbool)(PBSTART+0x257)))  /*                       Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный */
#define signal_B1AB09LDU     (*((psbool)(PBSTART+0x259)))  /*                       Блокировка подъёма ББ2- АНИ не установлен */
#define signal_B1AB10LDU     (*((psbool)(PBSTART+0x25b)))  /*                       Блокировка подъёма ББ2- есть сигнал общего сброса */
#define signal_B1AB11LDU     (*((psbool)(PBSTART+0x25d)))  /*                       Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате */
#define signal_B1AB12LDU     (*((psbool)(PBSTART+0x25f)))  /*                       Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ */
#define signal_B1AB13LDU     (*((psbool)(PBSTART+0x261)))  /*                       Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС */
#define signal_B1AB14LDU     (*((psbool)(PBSTART+0x263)))  /*                       Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной */
#define signal_B1AB16LDU     (*((psbool)(PBSTART+0x265)))  /*                       Блокировка перемещения ББ2: выполняется программа 200 с */
#define signal_B1AB17LDU     (*((psbool)(PBSTART+0x267)))  /*                       Блокировка перемещения ББ2: выполняется программа 20 мин */
#define signal_B1AB18LDU     (*((psbool)(PBSTART+0x269)))  /*                       Блокировка подъёма ББ2- РБ-СТР ниже 80 мм */
#define signal_A3VS12LDU     (*((psbool)(PBSTART+0x26b)))  /*                       Движение ИС1 в сторону ВУ */
#define signal_A3CV01RDU     (*((psfloat)(PBSTART+0x26d)))  /*                       Измеренная скорость перемещения ИС1 */
#define signal_A3AB04LDU     (*((psbool)(PBSTART+0x272)))  /*                       Блокировка движения ИС1 нет перемещения  ИС1 */
#define signal_A3AB02LDU     (*((psbool)(PBSTART+0x274)))  /*                       Блокировка движения ИС1: превышение заданной скорости */
#define signal_A3AB01LDU     (*((psbool)(PBSTART+0x276)))  /*                       Блокировка движения ИС1: скорость перемещения менее заданной */
#define signal_A3VS22LDU     (*((psbool)(PBSTART+0x278)))  /*                       Движение ИС1 в сторону НУ */
#define signal_A3AZ03LDU     (*((psbool)(PBSTART+0x27a)))  /*                       Сброс РБ: Несанкционированное перемещение ИС1 */
#define signal_A3AD11LDU     (*((psbool)(PBSTART+0x27c)))  /*                       Сигнал на перемещение ИС1 вверх */
#define signal_A3AD21LDU     (*((psbool)(PBSTART+0x27e)))  /*                       Сигнал на перемещение ИС1 вниз */
#define signal_A3AD02LDU     (*((psbool)(PBSTART+0x280)))  /*                       0-й бит скорости ИС1 */
#define signal_A3AD03LDU     (*((psbool)(PBSTART+0x282)))  /*                       1-й бит скорости ИС1 */
#define signal_A3AD04LDU     (*((psbool)(PBSTART+0x284)))  /*                       2-й бит скорости ИС1 */
#define signal_A3AD05LDU     (*((psbool)(PBSTART+0x286)))  /*                       паритет команды на ИС1 */
#define signal_A3AD01LDU     (*((psbool)(PBSTART+0x288)))  /*                       Разрешение движения ИС1 */
#define signal_A3CV02RDU     (*((psfloat)(PBSTART+0x28a)))  /*                       Заданная скорость перемещения ИС1 */
#define signal_A3AB07LDU     (*((psbool)(PBSTART+0x28f)))  /*                       Блокировка подъёма ИС1 Гомогенные двери не закрыты */
#define signal_A3AB08LDU     (*((psbool)(PBSTART+0x291)))  /*                       Блокировка подъёма ИС1 - реактор не на рабочем месте */
#define signal_A3AB05LDU     (*((psbool)(PBSTART+0x293)))  /*                       Блокировка подъёма ИС1 -нет сигнала готовности СУЗ */
#define signal_A3AB06LDU     (*((psbool)(PBSTART+0x295)))  /*                       Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный */
#define signal_A3AB09LDU     (*((psbool)(PBSTART+0x297)))  /*                       Блокировка подъёма ИС1- АНИ не установлен */
#define signal_A3AB10LDU     (*((psbool)(PBSTART+0x299)))  /*                       Блокировка подъёма ИС1- есть сигнал общего сброса */
#define signal_A3AB11LDU     (*((psbool)(PBSTART+0x29b)))  /*                       Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате */
#define signal_A3AB12LDU     (*((psbool)(PBSTART+0x29d)))  /*                       Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ */
#define signal_A3AB14LDU     (*((psbool)(PBSTART+0x29f)))  /*                       Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной */
#define signal_A3AB16LDU     (*((psbool)(PBSTART+0x2a1)))  /*                       Блокировка перемещения ИС1: выполняется программа 200 с */
#define signal_A3AB17LDU     (*((psbool)(PBSTART+0x2a3)))  /*                       Блокировка перемещения ИС1: выполняется программа 20 мин */
#define signal_A3AB18LDU     (*((psbool)(PBSTART+0x2a5)))  /*                       Блокировка подъёма ИС1- РБ-СТР ниже 80 мм */
#define signal_A3AB20LDU     (*((psbool)(PBSTART+0x2a7)))  /*                       Блокировка выстрела ИС1 - клапан ВПИС1 закрыт */
#define signal_B3VS12LDU     (*((psbool)(PBSTART+0x2a9)))  /*                       Движение ИС2 в сторону ВУ */
#define signal_B3CV01RDU     (*((psfloat)(PBSTART+0x2ab)))  /*                       Измеренная скорость перемещения ИС2 */
#define signal_B3AB04LDU     (*((psbool)(PBSTART+0x2b0)))  /*                       Блокировка движения ИС2 нет перемещения  ИС1 */
#define signal_B3AB02LDU     (*((psbool)(PBSTART+0x2b2)))  /*                       Блокировка движения ИС2: превышение заданной скорости */
#define signal_B3AB01LDU     (*((psbool)(PBSTART+0x2b4)))  /*                       Блокировка движения ИС2: скорость перемещения менее заданной */
#define signal_B3VS22LDU     (*((psbool)(PBSTART+0x2b6)))  /*                       Движение ИС2 в сторону НУ */
#define signal_B3AZ03LDU     (*((psbool)(PBSTART+0x2b8)))  /*                       Сброс РБ: Несанкционированное перемещение ИС2 */
#define signal_B3AD11LDU     (*((psbool)(PBSTART+0x2ba)))  /*                       Сигнал на перемещение ИС2 вверх */
#define signal_B3AD21LDU     (*((psbool)(PBSTART+0x2bc)))  /*                       Сигнал на перемещение ИС2 вниз */
#define signal_B3AD02LDU     (*((psbool)(PBSTART+0x2be)))  /*                       0-й бит скорости ИС2 */
#define signal_B3AD03LDU     (*((psbool)(PBSTART+0x2c0)))  /*                       1-й бит скорости ИС2 */
#define signal_B3AD04LDU     (*((psbool)(PBSTART+0x2c2)))  /*                       2-й бит скорости ИС2 */
#define signal_B3AD05LDU     (*((psbool)(PBSTART+0x2c4)))  /*                       паритет команды на ИС2 */
#define signal_B3AD01LDU     (*((psbool)(PBSTART+0x2c6)))  /*                       Разрешение движения ИС2 */
#define signal_B3CV02RDU     (*((psfloat)(PBSTART+0x2c8)))  /*                       Заданная скорость перемещения ИС2 */
#define signal_B3AB07LDU     (*((psbool)(PBSTART+0x2cd)))  /*                       Блокировка подъёма ИС2 Гомогенные двери не закрыты */
#define signal_B3AB08LDU     (*((psbool)(PBSTART+0x2cf)))  /*                       Блокировка подъёма ИС2 - реактор не на рабочем месте */
#define signal_B3AB05LDU     (*((psbool)(PBSTART+0x2d1)))  /*                       Блокировка подъёма ИС2 -нет сигнала готовности СУЗ */
#define signal_B3AB06LDU     (*((psbool)(PBSTART+0x2d3)))  /*                       Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный */
#define signal_B3AB09LDU     (*((psbool)(PBSTART+0x2d5)))  /*                       Блокировка подъёма ИС2- АНИ не установлен */
#define signal_B3AB10LDU     (*((psbool)(PBSTART+0x2d7)))  /*                       Блокировка подъёма ИС2- есть сигнал общего сброса */
#define signal_B3AB11LDU     (*((psbool)(PBSTART+0x2d9)))  /*                       Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате */
#define signal_B3AB12LDU     (*((psbool)(PBSTART+0x2db)))  /*                       Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ */
#define signal_B3AB14LDU     (*((psbool)(PBSTART+0x2dd)))  /*                       Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной */
#define signal_B3AB16LDU     (*((psbool)(PBSTART+0x2df)))  /*                       Блокировка перемещения ИС2: выполняется программа 200 с */
#define signal_B3AB17LDU     (*((psbool)(PBSTART+0x2e1)))  /*                       Блокировка перемещения ИС2: выполняется программа 20 мин */
#define signal_B3AB18LDU     (*((psbool)(PBSTART+0x2e3)))  /*                       Блокировка подъёма ИС2- РБ-СТР ниже 80 мм */
#define signal_B3AB20LDU     (*((psbool)(PBSTART+0x2e5)))  /*                       Блокировка выстрела ИС2 - клапан ВПИС2 закрыт */
#define signal_C1MD31LP1     (*((psbool)(PBSTART+0x2e7)))  /*                       Кнопка «СБРОС ББ» */
#define signal_C1MD31LP2     (*((psbool)(PBSTART+0x2e9)))  /*                       Кнопка «СБРОС ББ» */
#define signal_A2AD31LDU     (*((psbool)(PBSTART+0x2eb)))  /*                       Клапан СБРОС РБ1 открыть (обесточить) */
#define signal_B2AD31LDU     (*((psbool)(PBSTART+0x2ed)))  /*                       Клапан Сброс РБ2 открыть (обесточить) */
#define signal_A1AD31LDU     (*((psbool)(PBSTART+0x2ef)))  /*                       Клапан СБРОС ББ1 открыть (обесточить) */
#define signal_B1AD31LDU     (*((psbool)(PBSTART+0x2f1)))  /*                       Клапан СБРОС ББ2 открыть (обесточить) */
#define signal_A2AD32LDU     (*((psbool)(PBSTART+0x2f3)))  /*                       Обесточить ЭМ РБ1 */
#define signal_B2AD32LDU     (*((psbool)(PBSTART+0x2f5)))  /*                       Обесточить ЭМ РБ2 */
#define signal_A1AD32LDU     (*((psbool)(PBSTART+0x2f7)))  /*                       Обесточить ЭМ ББ1 */
#define signal_B1AD32LDU     (*((psbool)(PBSTART+0x2f9)))  /*                       Обесточить ЭМ ББ2 */
#define signal_R0MD11LP2     (*((psbool)(PBSTART+0x2fb)))  /*                       Кнопка Пуск проверки схем сброса */
#define signal_R0VX01LDU     (*((psbool)(PBSTART+0x2fd)))  /*                       ДО ИМПУЛЬСА */
#define signal_R0VL01IDU     (*((psint)(PBSTART+0x2ff)))  /*                       До импульса минут */
#define signal_R0VL11IDU     (*((psint)(PBSTART+0x302)))  /*                       До импульса секунд */
#define signal_R0VL06RDU     (*((psfloat)(PBSTART+0x305)))  /*                       Индикация (Время задержки от ВУ РБ) */
#define signal_B3AD33LDU     (*((psbool)(PBSTART+0x30a)))  /*                       Клапан ВЫСТРЕЛ ИС2 закрыть (обесточить) */
#define signal_B3IS11LDU     (*((psbool)(PBSTART+0x30c)))  /*                       Приход на ВУ ИС2 */
#define signal_B3IS11LDU     (*((psbool)(PBSTART+0x30c)))  /*                       Приход на ВУ ИС2 */
#define signal_B3IS11LDU     (*((psbool)(PBSTART+0x30c)))  /*                       Приход на ВУ ИС2 */
#define signal_R0VL02RDU     (*((psfloat)(PBSTART+0x30e)))  /*                       Индикация (Время задержки ИНИ) */
#define signal_R8AD21LDU     (*((psbool)(PBSTART+0x313)))  /*                       Запуск системы инициирования */
#define signal_R0AD14LDU     (*((psbool)(PBSTART+0x315)))  /*                       Имитация срабатывания верхней АС II УР */
#define signal_R0VL04RDU     (*((psfloat)(PBSTART+0x317)))  /*                       Индикация (Время срабатывания верхней АС II УР) */
#define signal_R0AB04LDU     (*((psbool)(PBSTART+0x31c)))  /*                       Нарушение времени срабатывания верхней АС II УР */
#define signal_R0AB06LDU     (*((psbool)(PBSTART+0x31e)))  /*                       Нарушение времени задержки от ВУ РБ */
#define signal_R0AB02LDU     (*((psbool)(PBSTART+0x320)))  /*                       Нарушение времени задержки ИНИ */
#define signal_R0VL03RDU     (*((psfloat)(PBSTART+0x322)))  /*                       Индикация (Время срабатывания АЗ от ВУ ИС) */
#define signal_R0VL05RDU     (*((psfloat)(PBSTART+0x327)))  /*                       Индикация (Время срабатывания АЗ от НУП ИС) */
#define signal_R0VL21IDU     (*((psint)(PBSTART+0x32c)))  /*                       Декатрон */
#define signal_R0VX03LDU     (*((psbool)(PBSTART+0x32f)))  /*                       Готовность 2 мин */
#define signal_R0VS21IDU     (*((psint)(PBSTART+0x331)))  /*                       Индикация ВИД ПРОВЕРКИ */
#define signal_A1VS01IDU     (*((psint)(PBSTART+0x334)))  /*                       Готовность к управлению ББ1 */
#define signal_B1VS01IDU     (*((psint)(PBSTART+0x337)))  /*                       Готовность к управлению ББ2 */
#define signal_A3VS01IDU     (*((psint)(PBSTART+0x33a)))  /*                       Готовность к управлению ИС1 */
#define signal_B3VS01IDU     (*((psint)(PBSTART+0x33d)))  /*                       Готовность к управлению ИС2 */
#define signal_A2VS01IDU     (*((psint)(PBSTART+0x340)))  /*                       Готовность к управлению РБ1 */
#define signal_A4VS01IDU     (*((psint)(PBSTART+0x343)))  /*                       Готовность к управлению НИ1 */
#define signal_A4VS12LDU     (*((psbool)(PBSTART+0x346)))  /*                       Движение НИ1 в сторону ВУ */
#define signal_A4VS22LDU     (*((psbool)(PBSTART+0x348)))  /*                       Движение НИ1 в сторону НУ */
#define signal_B4VS01IDU     (*((psint)(PBSTART+0x34a)))  /*                       Готовность к управлению НИ2 */
#define signal_B4VS12LDU     (*((psbool)(PBSTART+0x34d)))  /*                       Движение НИ2 в сторону ВУ */
#define signal_B4VS22LDU     (*((psbool)(PBSTART+0x34f)))  /*                       Движение НИ2 в сторону НУ */
#define signal_A5VS01IDU     (*((psint)(PBSTART+0x351)))  /*                       Готовность к управлению НЛ1 */
#define signal_B5VS01IDU     (*((psint)(PBSTART+0x354)))  /*                       Готовность к управлению НЛ2 */
#define signal_A6VS01IDU     (*((psint)(PBSTART+0x357)))  /*                       Готовность к управлению БЗ1 */
#define signal_R4VS01IDU     (*((psint)(PBSTART+0x35a)))  /*                       Готовность к управлению тележкой реактора */
#define signal_R2VS01IDU     (*((psint)(PBSTART+0x35d)))  /*                       Готовность к управлению МДЗ2 */
#define signal_R1VS01IDU     (*((psint)(PBSTART+0x360)))  /*                       Готовность к управлению МДЗ1 */
#define signal_A9IS11LDU     (*((psbool)(PBSTART+0x363)))  /*                       Приход на ВУ НИ ДС1 */
#define signal_A9IS21LDU     (*((psbool)(PBSTART+0x365)))  /*                       Приход на НУ НИ ДС1 */
#define signal_B9IS11LDU     (*((psbool)(PBSTART+0x367)))  /*                       Приход на ВУ НИ ДС2 */
#define signal_B9IS21LDU     (*((psbool)(PBSTART+0x369)))  /*                       Приход на НУ НИ ДС2 */
#define signal_B9AD10LDU     (*((psbool)(PBSTART+0x36b)))  /*                       Открыть клапан Подъем НИ ДС2 */
#define signal_A9AD10LDU     (*((psbool)(PBSTART+0x36d)))  /*                       Открыть клапан Подъем НИ ДС1 */
#define signal_A9AZ03LDU     (*((psbool)(PBSTART+0x36f)))  /*                       Несанкционированное перемещение НИ ДС1 */
#define signal_A9AB01LDU     (*((psbool)(PBSTART+0x371)))  /*                       Блокировка движения НИ ДС1 - Превышение времени движения */
#define signal_A9AB02LDU     (*((psbool)(PBSTART+0x373)))  /*                       Блокировка НИ ДС1 - Нет перемещения */
#define signal_B9AZ03LDU     (*((psbool)(PBSTART+0x375)))  /*                       Несанкционированное перемещение НИ ДС2 */
#define signal_B9AB01LDU     (*((psbool)(PBSTART+0x377)))  /*                       Блокировка движения НИ ДС2 - Превышение времени движения */
#define signal_B9AB02LDU     (*((psbool)(PBSTART+0x379)))  /*                       Блокировка движения НИ ДС2 - Нет перемещения */
#define signal_R0AB01LDU     (*((psbool)(PBSTART+0x37b)))  /*                       Режим проверки разрешён */
#define signal_A3IS22LDU     (*((psbool)(PBSTART+0x37d)))  /*                       Приход на НУП ИС1 */
#define signal_A3IS22LDU     (*((psbool)(PBSTART+0x37d)))  /*                       Приход на НУП ИС1 */
#define signal_A3IS22LDU     (*((psbool)(PBSTART+0x37d)))  /*                       Приход на НУП ИС1 */
#define signal_B3IS22LDU     (*((psbool)(PBSTART+0x37f)))  /*                       Приход на НУП ИС2 */
#define signal_B3IS22LDU     (*((psbool)(PBSTART+0x37f)))  /*                       Приход на НУП ИС2 */
#define signal_B3IS22LDU     (*((psbool)(PBSTART+0x37f)))  /*                       Приход на НУП ИС2 */
#define signal_A2AD33LDU     (*((psbool)(PBSTART+0x381)))  /*                       Клапан ПОДЪЕМ РБ1 открыть (обесточить) */
#define signal_B2AD33LDU     (*((psbool)(PBSTART+0x383)))  /*                       Клапан ПОДЪЕМ РБ2 открыть (обесточить) */
#define signal_A3AD33LDU     (*((psbool)(PBSTART+0x385)))  /*                       Клапан ВЫСТРЕЛ ИС1 открыть (обесточить) */
#define signal_A3AD34LDU     (*((psbool)(PBSTART+0x387)))  /*                       Клапан ВПИС1  открыть (обесточить) */
#define signal_A3AD31LDU     (*((psbool)(PBSTART+0x389)))  /*                       Клапан СПУСК ИС1 открыть (обесточить) */
#define signal_B3AD34LDU     (*((psbool)(PBSTART+0x38b)))  /*                       Клапан ВПИС ИС2  открыть (обесточить) */
#define signal_B3AD31LDU     (*((psbool)(PBSTART+0x38d)))  /*                       Клапан СПУСК ИС2 открыть (обесточить) */
#define signal_A2IS11LDU     (*((psbool)(PBSTART+0x38f)))  /*                       Приход на ВУ РБ1-СТР */
#define signal_A2IS11LDU     (*((psbool)(PBSTART+0x38f)))  /*                       Приход на ВУ РБ1-СТР */
#define signal_A2IS11LDU     (*((psbool)(PBSTART+0x38f)))  /*                       Приход на ВУ РБ1-СТР */
#define signal_A2IS11LDU     (*((psbool)(PBSTART+0x38f)))  /*                       Приход на ВУ РБ1-СТР */
#define signal_B2IS11LDU     (*((psbool)(PBSTART+0x391)))  /*                       Приход на ВУ РБ2-СТР */
#define signal_B2IS11LDU     (*((psbool)(PBSTART+0x391)))  /*                       Приход на ВУ РБ2-СТР */
#define signal_B2IS11LDU     (*((psbool)(PBSTART+0x391)))  /*                       Приход на ВУ РБ2-СТР */
#define signal_B2IS11LDU     (*((psbool)(PBSTART+0x391)))  /*                       Приход на ВУ РБ2-СТР */
#define signal_A3MD12LP1     (*((psbool)(PBSTART+0x393)))  /*                       Переключатель РАЗРЕШИТЬ ИС1 */
#define signal_A3MD11LP1     (*((psbool)(PBSTART+0x395)))  /*                       Кнопка ПУСК ИС1 */
#define signal_R0MD33LP1     (*((psbool)(PBSTART+0x397)))  /*                       Переключатель РАЗРЕШИТЬ МДЗ */
#define signal_R0MD33LP1     (*((psbool)(PBSTART+0x397)))  /*                       Переключатель РАЗРЕШИТЬ МДЗ */
#define signal_R0MD33LP1     (*((psbool)(PBSTART+0x397)))  /*                       Переключатель РАЗРЕШИТЬ МДЗ */
#define signal_A1MD12LP1     (*((psbool)(PBSTART+0x399)))  /*                       Переключатель РАЗРЕШИТЬ ББ1 */
#define signal_A1MD11LP1     (*((psbool)(PBSTART+0x39b)))  /*                       Кнопка ПУСК ББ1 */
#define signal_R0MW14IP2     (*((psint)(PBSTART+0x39d)))  /*                       Переключатель «Обдув» */
#define signal_A7AP31LDU     (*((psbool)(PBSTART+0x3a0)))  /*                       Клапан Обдув АЗ1 открыть (обесточить) */
#define signal_B7AP31LDU     (*((psbool)(PBSTART+0x3a2)))  /*                       Клапан Обдув АЗ2 открыть (обесточить) */
#define signal_R0MW12IP2     (*((psint)(PBSTART+0x3a4)))  /*                       Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ */
#define signal_R0MW17LP1     (*((psbool)(PBSTART+0x3a7)))  /*                       Переключатель АВТ/Р */
#define signal_R0VW13LDU     (*((psbool)(PBSTART+0x3a9)))  /*                       Индикация выбора АЗ1 или АЗ1+АЗ2 */
#define signal_R0VW23LDU     (*((psbool)(PBSTART+0x3ab)))  /*                       Индикация выбора АЗ2 или АЗ1+АЗ2 */
#define signal_R0VX08IDU     (*((psint)(PBSTART+0x3ad)))  /*                       Индикация Режим */
#define signal_R0VX09LDU     (*((psbool)(PBSTART+0x3b0)))  /*                       Индикация регулятор мощности включен/отключен */
#define signal_R0VS17LDU     (*((psbool)(PBSTART+0x3b2)))  /*                       Индикация выбора АВТОМАТ */
#define signal_A2VS32LDU     (*((psbool)(PBSTART+0x3b4)))  /*                       Индикация  СБРОС РБ1 */
#define signal_B2VS32LDU     (*((psbool)(PBSTART+0x3b6)))  /*                       Индикация  СБРОС РБ2 */
#define signal_A3VX01LDU     (*((psbool)(PBSTART+0x3b8)))  /*                       Индикация Выстрел ИС1 */
#define signal_A3IS11LDU     (*((psbool)(PBSTART+0x3ba)))  /*                       Приход на ВУ ИС1 */
#define signal_A3IS11LDU     (*((psbool)(PBSTART+0x3ba)))  /*                       Приход на ВУ ИС1 */
#define signal_A3IS11LDU     (*((psbool)(PBSTART+0x3ba)))  /*                       Приход на ВУ ИС1 */
#define signal_B3VX01LDU     (*((psbool)(PBSTART+0x3bc)))  /*                       Индикация Выстрел ИС2 */
#define signal_R0VS18LDU     (*((psbool)(PBSTART+0x3be)))  /*                       Индикация  Проверка схем сброса */
#define signal_B1MD11LP1     (*((psbool)(PBSTART+0x3c0)))  /*                       Кнопка ПУСК ББ2 */
#define signal_B1MD12LP1     (*((psbool)(PBSTART+0x3c2)))  /*                       Переключатель РАЗРЕШИТЬ ББ2 */
#define signal_B2MD11LP1     (*((psbool)(PBSTART+0x3c4)))  /*                       Кнопка ПУСК РБ2 */
#define signal_B2MD12LP1     (*((psbool)(PBSTART+0x3c6)))  /*                       Переключатель РАЗРЕШИТЬ РБ2 */
#define signal_A2MD11LP1     (*((psbool)(PBSTART+0x3c8)))  /*                       Кнопка ПУСК РБ1 */
#define signal_A2MD12LP1     (*((psbool)(PBSTART+0x3ca)))  /*                       Переключатель РАЗРЕШИТЬ РБ1 */
#define signal_R0IS01LDU     (*((psbool)(PBSTART+0x3cc)))  /*                       Признак работы с имитатором */
#define signal_R0IS02LDU     (*((psbool)(PBSTART+0x3ce)))  /*                       Разрешение ввода от имитатора */
#define signal_R0VP73LZ1     (*((psbool)(PBSTART+0x3d0)))  /*                       ПС давления для РУ */
#define signal_R0VP73LZ2     (*((psbool)(PBSTART+0x3d2)))  /*                       ПС давления для РУ */
#define signal_R0VP73LDU     (*((psbool)(PBSTART+0x3d4)))  /*                       ПС давления для РУ */
#define signal_R0MD34LP1     (*((psbool)(PBSTART+0x3d6)))  /*                       Кнопка КВИТИРОВАТЬ */
#define signal_A0VT71LZ1     (*((psbool)(PBSTART+0x3d8)))  /*                       АС по температуре в АЗ1 */
#define signal_A0VT71LZ1     (*((psbool)(PBSTART+0x3d8)))  /*                       АС по температуре в АЗ1 */
#define signal_B0VT71LZ1     (*((psbool)(PBSTART+0x3da)))  /*                       АС по температуре в АЗ2 */
#define signal_B0VT71LZ1     (*((psbool)(PBSTART+0x3da)))  /*                       АС по температуре в АЗ2 */
#define signal_A0VT71LZ2     (*((psbool)(PBSTART+0x3dc)))  /*                       АС по температуре в АЗ1 */
#define signal_A0VT71LZ2     (*((psbool)(PBSTART+0x3dc)))  /*                       АС по температуре в АЗ1 */
#define signal_B0VT71LZ2     (*((psbool)(PBSTART+0x3de)))  /*                       АС по температуре в АЗ2 */
#define signal_B0VT71LZ2     (*((psbool)(PBSTART+0x3de)))  /*                       АС по температуре в АЗ2 */
#define signal_B2VS11LDU     (*((psbool)(PBSTART+0x3e0)))  /*                       Движение РБ2 в сторону ВУ */
#define signal_B2VS21LDU     (*((psbool)(PBSTART+0x3e2)))  /*                       Движение РБ2 в сторону НУ */
#define signal_B2VS01IDU     (*((psint)(PBSTART+0x3e4)))  /*                       Готовность к управлению РБ2 */
#define signal_A7AS31LDU     (*((psbool)(PBSTART+0x3e7)))  /*                       Клапан Обдув АЗ1 открыт (обесточен) */
#define signal_B7AS31LDU     (*((psbool)(PBSTART+0x3e9)))  /*                       Клапан Обдув АЗ2 открыт (обесточен) */
#define signal_A7AZ03LDU     (*((psbool)(PBSTART+0x3eb)))  /*                       Несанкционированное включение обдува АЗ1 */
#define signal_B7AZ03LDU     (*((psbool)(PBSTART+0x3ed)))  /*                       Несанкционированное включение обдува АЗ2 */
#define signal_B3MD12LP1     (*((psbool)(PBSTART+0x3ef)))  /*                       Переключатель «РАЗРЕШИТЬ» ИС2 */
#define signal_B3MD11LP1     (*((psbool)(PBSTART+0x3f1)))  /*                       Кнопка «ПУСК ИС2» */
#define signal_R0VL01RDU     (*((psfloat)(PBSTART+0x3f3)))  /*                       Индикация Время задержки */
#define signal_R0VZ71LZ2     (*((psbool)(PBSTART+0x3f8)))  /*                       Обобщенный сигнал АЗ 2 канала */
#define signal_R0VZ71LZ1     (*((psbool)(PBSTART+0x3fa)))  /*                       Обобщенный сигнал АЗ 1канала */
#define signal_R0VZ71LDU     (*((psbool)(PBSTART+0x3fc)))  /*                       Обобщенный сигнал АЗ */
#define signal_A2IS33LDU     (*((psbool)(PBSTART+0x3fe)))  /*                       Клапан ПОДЪЕМ РБ1 открыт (обесточен) */
#define signal_A3IS31LDU     (*((psbool)(PBSTART+0x400)))  /*                       Клапан СПУСК ИС1 открыт (обесточен) */
#define signal_A3IS33LDU     (*((psbool)(PBSTART+0x402)))  /*                       Клапан ВЫСТРЕЛ ИС1 открыт (обесточен) */
#define signal_A3IS35LDU     (*((psbool)(PBSTART+0x404)))  /*                       Клапан ВПИС1 открыт (обесточен) */
#define signal_A4IS10LDU     (*((psbool)(PBSTART+0x406)))  /*                       Клапан Подъём НИ1 открыт (обесточен) */
#define signal_A1VN71LZ1     (*((psbool)(PBSTART+0x408)))  /*                       Блокировка автоматического подъёма ББ */
#define signal_A1VN71LZ2     (*((psbool)(PBSTART+0x40a)))  /*                       Блокировка автоматического подъёма ББ */
#define signal_A1AB19LDU     (*((psbool)(PBSTART+0x40c)))  /*                       Блокировка автоматического подъёма ББ1 -превышение нейтронного потока */
#define signal_R0AD14LZ1     (*((psbool)(PBSTART+0x40e)))  /*                       Имитация срабатывания АЗ от II УР */
#define signal_R0AD14LZ2     (*((psbool)(PBSTART+0x410)))  /*                       Имитация срабатывания АЗ от  II УР */
#define signal_A3VZ13LZ2     (*((psbool)(PBSTART+0x412)))  /*                       Имитация срабатывания АЗ от ВУ ИС */
#define signal_A3VZ13LZ1     (*((psbool)(PBSTART+0x414)))  /*                       Имитация срабатывания АЗ от ВУ ИС */
#define signal_A3VZ15LZ1     (*((psbool)(PBSTART+0x416)))  /*                       Имитация срабатывания АЗ от НУП ИС */
#define signal_A3VZ15LZ2     (*((psbool)(PBSTART+0x418)))  /*                       Имитация срабатывания АЗ от НУП ИС */
#define signal_B2IS33LDU     (*((psbool)(PBSTART+0x41a)))  /*                       Клапан ПОДЪЕМ РБ2 открыт (обесточен) */
#define signal_B3IS31LDU     (*((psbool)(PBSTART+0x41c)))  /*                       Клапан СПУСК ИС2 открыт (обесточен) */
#define signal_B3IS33LDU     (*((psbool)(PBSTART+0x41e)))  /*                       Клапан ВЫСТРЕЛ ИС2 открыт (обесточен) */
#define signal_B3IS35LDU     (*((psbool)(PBSTART+0x420)))  /*                       Клапан ВПИС2 открыт (обесточен) */
#define signal_B4IS10LDU     (*((psbool)(PBSTART+0x422)))  /*                       Клапан ПОДЪЕМ НИ2 открыт (обесточен) */
#define signal_R6IS31LDU     (*((psbool)(PBSTART+0x424)))  /*                       контроль задней двери ШС */
#define signal_R6IS32LDU     (*((psbool)(PBSTART+0x426)))  /*                       контроль передней двери ШС */
#define signal_R6IS42LDU     (*((psbool)(PBSTART+0x428)))  /*                       контроль передней двери ШЭП */
#define signal_R6IS41LDU     (*((psbool)(PBSTART+0x42a)))  /*                       контроль задней двери ШЭП */
#define signal_R6IS52LDU     (*((psbool)(PBSTART+0x42c)))  /*                       контроль передней двери ШПУ */
#define signal_R6IS51LDU     (*((psbool)(PBSTART+0x42e)))  /*                       контроль задней двери ШПУ */
#define signal_R3IS11LDU     (*((psbool)(PBSTART+0x430)))  /*                       Приход на ВУ гомогенных дверей */
#define signal_R3IS21LDU     (*((psbool)(PBSTART+0x432)))  /*                       Приход на НУ гомогенных дверей */
#define signal_R0AB03LDU     (*((psbool)(PBSTART+0x434)))  /*                       Нарушение времени срабатывания АЗ от ВУ ИС */
#define signal_R0AB05LDU     (*((psbool)(PBSTART+0x436)))  /*                       Нарушение времени срабатывания АЗ от НУП ИС */
#define signal_R0VN11RZ1     (*((psfloat)(PBSTART+0x438)))  /*                       Средняя мощность по BAZ1 */
#define signal_R0VN11RZ1     (*((psfloat)(PBSTART+0x438)))  /*                       Средняя мощность по BAZ1 */
#define signal_R0VN11RZ2     (*((psfloat)(PBSTART+0x43d)))  /*                       Средняя мощность по BAZ2 */
#define signal_R0VN11RZ2     (*((psfloat)(PBSTART+0x43d)))  /*                       Средняя мощность по BAZ2 */
#define signal_A2AB15LDU     (*((psbool)(PBSTART+0x442)))  /*                       Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин */
#define signal_B2AB15LDU     (*((psbool)(PBSTART+0x444)))  /*                       Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин */
#define signal_R0AD21LDU     (*((psbool)(PBSTART+0x446)))  /*                       Подключить защиту от II УР */
#define signal_R0VX02LDU     (*((psbool)(PBSTART+0x448)))  /*                       Импульс разрешен */
#define signal_R0EE03LDU     (*((psbool)(PBSTART+0x44a)))  /*                       ВПИС ИС */
#define signal_syn_R0EE03LDU (*((psbool)(PBSTART+0x44a)))  /*                       ВПИС ИС */
#define signal_R0AB07LDU     (*((psbool)(PBSTART+0x44c)))  /*                       Блокировка программы подъёма ОРР-ошибка уставки АЗ2 */
#define signal_R0AD16LDU     (*((psbool)(PBSTART+0x44e)))  /*                       Контроль  I-II УР. РАД */
#define signal_C2MD31LP1     (*((psbool)(PBSTART+0x450)))  /*                       Кнопка СБРОС РБ */
#define signal_B6VS01IDU     (*((psint)(PBSTART+0x452)))  /*                       Готовность к управлению БЗ2 */
#define signal_R2AD20LDU     (*((psbool)(PBSTART+0x455)))  /*                       Поднять МДЗ2 */
#define signal_R2AD10LDU     (*((psbool)(PBSTART+0x457)))  /*                       Опустить МДЗ2 */
#define signal_B8VS01IDU     (*((psint)(PBSTART+0x459)))  /*                       Готовность к управлению АЗ2 */
#define signal_A8VS01IDU     (*((psint)(PBSTART+0x45c)))  /*                       Готовность к управлению ДС2 */
#define signal_A1IE03LDU     (*((psbool)(PBSTART+0x45f)))  /*                       Движение ББ1 вперед (от БУШД) */
#define signal_A1IE04LDU     (*((psbool)(PBSTART+0x461)))  /*                       Движение ББ1 назад (от БУШД) */
#define signal_A2IE03LDU     (*((psbool)(PBSTART+0x463)))  /*                       Движение РБ1 вперед (от БУШД) */
#define signal_A2IE04LDU     (*((psbool)(PBSTART+0x465)))  /*                       Движение РБ1 назад (от БУШД) */
#define signal_A3IE03LDU     (*((psbool)(PBSTART+0x467)))  /*                       Движение ИС1 вперед (от БУШД) */
#define signal_A3IE04LDU     (*((psbool)(PBSTART+0x469)))  /*                       Движение ИС1 назад (от БУШД) */
#define signal_B1IE03LDU     (*((psbool)(PBSTART+0x46b)))  /*                       Движение ББ2 вперед (от БУШД) */
#define signal_B1IE04LDU     (*((psbool)(PBSTART+0x46d)))  /*                       Движение ББ2 назад (от БУШД) */
#define signal_B2IE03LDU     (*((psbool)(PBSTART+0x46f)))  /*                       Движение РБ2 вперед (от БУШД) */
#define signal_B2IE04LDU     (*((psbool)(PBSTART+0x471)))  /*                       Движение РБ2 назад (от БУШД) */
#define signal_B3IE03LDU     (*((psbool)(PBSTART+0x473)))  /*                       Движение ИС2 вперед (от БУШД) */
#define signal_B3IE04LDU     (*((psbool)(PBSTART+0x475)))  /*                       Движение ИС2 назад (от БУШД) */
#define signal_R0VS11LDU     (*((psbool)(PBSTART+0x477)))  /*                       РУ не готова к работе */
#define signal_B6AB05LDU     (*((psbool)(PBSTART+0x479)))  /*                       Блокировка открытия БЗ2- АНИ не установлен */
#define signal_R0AB08LDU     (*((psbool)(PBSTART+0x47b)))  /*                       Блокировка кнопки ПУСК - тележка не у образцов */
#define signal_A1MC01RP1     (*((psfloat)(PBSTART+0x47d)))  /*                       Заданная координата положения ББ1 мм */
#define signal_B1MC01RP1     (*((psfloat)(PBSTART+0x482)))  /*                       Заданная координата положения ББ2  мм */
#define signal_A3MC01RP1     (*((psfloat)(PBSTART+0x487)))  /*                       Заданная координата положения ИС1 мм */
#define signal_A3MC01RP1     (*((psfloat)(PBSTART+0x487)))  /*                       Заданная координата положения ИС1 мм */
#define signal_B3MC01RP1     (*((psfloat)(PBSTART+0x48c)))  /*                       Заданная координата положения ИС2 мм */
#define signal_B3MC01RP1     (*((psfloat)(PBSTART+0x48c)))  /*                       Заданная координата положения ИС2 мм */
#define signal_B8MC01RP2     (*((psfloat)(PBSTART+0x491)))  /*                       Заданная координата АЗ2 мм */
#define signal_R0AB09LDU     (*((psbool)(PBSTART+0x496)))  /*                       Ошибка в заданной координате ББ1 */
#define signal_R0AB10LDU     (*((psbool)(PBSTART+0x498)))  /*                       Ошибка в заданной координате ББ2 */
#define signal_R0AB11LDU     (*((psbool)(PBSTART+0x49a)))  /*                       Ошибка в заданной координате  ИС1 */
#define signal_R0AB12LDU     (*((psbool)(PBSTART+0x49c)))  /*                       Ошибка в заданной координате  ИС2 */
#define signal_R0AB13LDU     (*((psbool)(PBSTART+0x49e)))  /*                       Ошибка в заданной координате  АЗ2 */
#define signal_A4ZAV         (*((psbool)(PBSTART+0x4a0)))  /*                        */
#define signal_A6ZAV         (*((psbool)(PBSTART+0x4a2)))  /*                        */
#define signal_R2ZAV         (*((psbool)(PBSTART+0x4a4)))  /*                        */
#define signal_A5ZAV         (*((psbool)(PBSTART+0x4a6)))  /*                        */
#define signal_B8ZAV         (*((psbool)(PBSTART+0x4a8)))  /*                        */
#define signal_A2ZAV         (*((psbool)(PBSTART+0x4aa)))  /*                       Завершение РБ1,2 */
#define signal_A8ZAV         (*((psbool)(PBSTART+0x4ac)))  /*                        */
#define signal_A9ZAV         (*((psbool)(PBSTART+0x4ae)))  /*                       Завершение НИ ДС1(2) */
#define signal_R4ABL         (*((psbool)(PBSTART+0x4b0)))  /*                       Блокировка тележки - */
#define signal_A4UP          (*((psbool)(PBSTART+0x4b2)))  /*                        */
#define signal_A4DW          (*((psbool)(PBSTART+0x4b4)))  /*                        */
#define signal_R0AB14LDU     (*((psbool)(PBSTART+0x4b6)))  /*                       Режим проверки не разрешён: ИС2 ниже 55 мм */
#define signal_R0AB15LDU     (*((psbool)(PBSTART+0x4b8)))  /*                       Режим проверки не разрешён: ИС1 ниже 55 мм */
#define signal_A3IS12LDU     (*((psbool)(PBSTART+0x4ba)))  /*                       Приход на ВУ штока ИС1 */
#define signal_B3IS12LDU     (*((psbool)(PBSTART+0x4bc)))  /*                       Приход на ВУ штока ИС2 */
#define signal_A1ZAV         (*((psbool)(PBSTART+0x4be)))  /*                        */
#define signal_A3ZAV         (*((psbool)(PBSTART+0x4c0)))  /*                        */
#define signal_B1AB19LDU     (*((psbool)(PBSTART+0x4c2)))  /*                       Блокировка автоматического подъёма ББ2 -превышение нейтронного потока */
#define signal_R0VN09RZ2     (*((psfloat)(PBSTART+0x4c4)))  /*                       Усредненный период разгона */
#define signal_R0VN09RZ1     (*((psfloat)(PBSTART+0x4c9)))  /*                       Усредненный период разгона */
#define signal_R0AB16LDU     (*((psbool)(PBSTART+0x4ce)))  /*                       Блокировка регулирования мощности: Усредненный период разгона меньше допустимого */
#define signal_R0AB17LDU     (*((psbool)(PBSTART+0x4d0)))  /*                       Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого */
#define signal_R0AB18LDU     (*((psbool)(PBSTART+0x4d2)))  /*                       Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2 */
#define signal_A0CT01IZ1     (*((psfloat)(PBSTART+0x4d4)))  /*                       Температура АЗ1-1 */
#define signal_B0CT01IZ1     (*((psfloat)(PBSTART+0x4d9)))  /*                       Температура АЗ2-1 */
#define signal_A0CT01IZ2     (*((psfloat)(PBSTART+0x4de)))  /*                       Температура АЗ1-2 */
#define signal_B0CT01IZ2     (*((psfloat)(PBSTART+0x4e3)))  /*                       Температура АЗ2-2 */
#define signal_A3MC01RDU     (*((psfloat)(PBSTART+0x4e8)))  /*                       Заданная координата положения ИС от регулятора мм */
#define signal_A3MC02RDU     (*((psfloat)(PBSTART+0x4ed)))  /*                       Температурная корректировка координаты ИМ */
#define signal_R0CN91LDU     (*((psfloat)(PBSTART+0x4f2)))  /*                       Рассчётная реактивность от регулятора */
#define signal_A3MC03RDU     (*((psfloat)(PBSTART+0x4f7)))  /*                       Координата положения ИМ 0-й реактивности */
#define signal_A3AB15LDU     (*((psbool)(PBSTART+0x4fc)))  /*                       Блокировка заполнения ресивера ИС1: работает регулятор мощности */
#define signal_R0AB20LDU     (*((psbool)(PBSTART+0x4fe)))  /*                       Блокировка изменения положения ОР: работает  регулятор мощности */
#define signal_R0CN92LDU     (*((psfloat)(PBSTART+0x500)))  /*                       Рассчётный коэффициент  опережения старта ИМ */
#define signal_R0VN11RDU     (*((psfloat)(PBSTART+0x505)))  /*                       Текущая мощность РУ */
#define signal_R0VN12RDU     (*((psfloat)(PBSTART+0x50a)))  /*                       Заданная мощность РУ */
#define signal_R0AB19LDU     (*((psbool)(PBSTART+0x50f)))  /*                       Блокировка регулирования мощности:Нарушение исходных условий. */
#define signal_R0CN93LDU     (*((psfloat)(PBSTART+0x511)))  /*                       время работы на мощности более 100Вт, сек */
#define signal_R0CN94LDU     (*((psfloat)(PBSTART+0x516)))  /*                       Скорость изменения мощности */
#define signal_R0CN95LDU     (*((psint)(PBSTART+0x51b)))  /*                       Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание */
#define signal_R0AD03LZ1     (*((psbool)(PBSTART+0x51e)))  /*                       Имитация прихода на ВУ ИС (БАЗ1) */
#define signal_R0AD03LZ2     (*((psbool)(PBSTART+0x520)))  /*                       Имитация прихода на ВУ ИС (БАЗ2) */
#define signal_R0AD04LZ1     (*((psbool)(PBSTART+0x522)))  /*                       Имитация срабатывания АС II УР. РАД (БАЗ1) */
#define signal_R0AD04LZ2     (*((psbool)(PBSTART+0x524)))  /*                       Имитация срабатывания АС II УР. РАД (БАЗ2) */
#define signal_R0AD05LZ1     (*((psbool)(PBSTART+0x526)))  /*                       Имитация ухода с НУП ИС  (БАЗ1) */
#define signal_R0AD05LZ2     (*((psbool)(PBSTART+0x528)))  /*                       Имитация ухода с НУП ИС  (БАЗ2) */
#define signal_B8IS12LDU     (*((psbool)(PBSTART+0x52a)))  /*                       Приход на ВУ2 АЗ2 */
#define signal_B8IS12LDU     (*((psbool)(PBSTART+0x52a)))  /*                       Приход на ВУ2 АЗ2 */
#define signal_B8IS21LDU     (*((psbool)(PBSTART+0x52c)))  /*                       Приход на НУ1 АЗ2 */
#define signal_B8IS21LDU     (*((psbool)(PBSTART+0x52c)))  /*                       Приход на НУ1 АЗ2 */
#define signal_A1VP41LZ1     (*((psbool)(PBSTART+0x52e)))  /*                       Давление СБРОС ББ1 ниже АС */
#define signal_A1VP41LZ2     (*((psbool)(PBSTART+0x530)))  /*                       Давление СБРОС ББ1 ниже АС */
#define signal_R0VL22LDU     (*((psbool)(PBSTART+0x532)))  /*                       Конец программы 200сек */
#define signal_R0VL23LDU     (*((psbool)(PBSTART+0x534)))  /*                       Конец программы 20мин */
#define signal_B1VP41LZ1     (*((psbool)(PBSTART+0x536)))  /*                       Давление СБРОС ББ2 ниже АС */
#define signal_B1VP41LZ2     (*((psbool)(PBSTART+0x538)))  /*                       Давление СБРОС ББ2 ниже АС */
#define signal_A3AB19LDU     (*((psbool)(PBSTART+0x53a)))  /*                       Блокировка пневматического подъема ИС1: режим статический */
#define signal_B3AB19LDU     (*((psbool)(PBSTART+0x53c)))  /*                       Блокировка пневматического подъема ИС2: режим статический */
#define signal_A3EE03LDU     (*((psbool)(PBSTART+0x53e)))  /*                       ВПИС ИС1 */
#define signal_B3EE03LDU     (*((psbool)(PBSTART+0x540)))  /*                       ВПИС ИС2 */
#define signal_B3AB15LDU     (*((psbool)(PBSTART+0x542)))  /*                       Блокировка заполнения ресивера ИС2: работает регулятор мощности */
#define signal_R5IS21LDU     (*((psbool)(PBSTART+0x544)))  /*                       Приход на НУ ворот отстойной зоны */
#define signal_R5VS22LDU     (*((psbool)(PBSTART+0x546)))  /*                       Движение ворот отстойной зоны к закрыты */
#define signal_R5VS12LDU     (*((psbool)(PBSTART+0x548)))  /*                       Движение ворот отстойной зоны к открыты */
#define signal_R5VS01IDU     (*((psint)(PBSTART+0x54a)))  /*                       Готовность к управлению ворот отстойной зоны */
#define signal_R3VS22LDU     (*((psbool)(PBSTART+0x54d)))  /*                       Движение гомогенных дверей к закрыты */
#define signal_R3VS12LDU     (*((psbool)(PBSTART+0x54f)))  /*                       Движение гомогенных дверей к открыты */
#define signal_R3VS01IDU     (*((psint)(PBSTART+0x551)))  /*                       Готовность к управлению гомогенных дверей */
#define signal_A3AB13LDU     (*((psbool)(PBSTART+0x554)))  /*                       Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС */
#define signal_syn_A3VP52LDU (*((psbool)(PBSTART+0x556)))  /*                       Давление ВЫСТРЕЛ ИС1 ниже ПС */
#define signal_A3VP52LDU     (*((psbool)(PBSTART+0x556)))  /*                       Давление ВЫСТРЕЛ ИС1 ниже ПС */
#define signal_syn_A3VP52LDU (*((psbool)(PBSTART+0x556)))  /*                       Давление ВЫСТРЕЛ ИС1 ниже ПС */
#define signal_B3AB13LDU     (*((psbool)(PBSTART+0x558)))  /*                       Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой */
#define signal_B3VP52LDU     (*((psbool)(PBSTART+0x55a)))  /*                       Давление ВЫСТРЕЛ ИС2 ниже ПС */
#define signal_syn_B3VP52LDU (*((psbool)(PBSTART+0x55a)))  /*                       Давление ВЫСТРЕЛ ИС2 ниже ПС */
#define signal_syn_B3VP52LDU (*((psbool)(PBSTART+0x55a)))  /*                       Давление ВЫСТРЕЛ ИС2 ниже ПС */
#define signal_B1IC01UDU     (*((pslong)(PBSTART+0x55c)))  /*                       Координата штока ББ2 (дел.энк) */
#define signal_B1VC01RDU     (*((psfloat)(PBSTART+0x561)))  /*                       Координата ББ2, мм */
#define signal_B1IS11LDU     (*((psbool)(PBSTART+0x566)))  /*                       Приход на ВУ ББ2 */
#define signal_A2IC01UDU     (*((pslong)(PBSTART+0x568)))  /*                       Координата штока РБ1 (дел.энк) */
#define signal_B2IC01UDU     (*((pslong)(PBSTART+0x56d)))  /*                       Координата штока РБ2 (дел.энк) */
#define signal_A3IC01UDU     (*((pslong)(PBSTART+0x572)))  /*                       Координата штока ИС1 (дел.энк) */
#define signal_B3IC01UDU     (*((pslong)(PBSTART+0x577)))  /*                       Координата штока ИС2 (дел.энк) */
#define signal_B3VC01RDU     (*((psfloat)(PBSTART+0x57c)))  /*                       Координата ИС2, мм */
#define signal_A8IC01UDU     (*((pslong)(PBSTART+0x581)))  /*                       Координата ДС2 (дел.энк) */
#define signal_A8VC01RDU     (*((psfloat)(PBSTART+0x586)))  /*                       Координата ДС2, мм */
#define signal_B8IC01UDU     (*((pslong)(PBSTART+0x58b)))  /*                       Координата АЗ2 (дел.энк) */
#define signal_A1IC01UDU     (*((pslong)(PBSTART+0x590)))  /*                       Координата штока ББ1 (дел.энк) */
#define signal_A1VC01RDU     (*((psfloat)(PBSTART+0x595)))  /*                       Координата ББ1, мм */
#define signal_A1IS11LDU     (*((psbool)(PBSTART+0x59a)))  /*                       Приход на ВУ ББ1 */
#define signal_B1MC01LC1     (*((psbool)(PBSTART+0x59c)))  /*                       Настроить энкодер ББ2 */
#define signal_B1MC01LC2     (*((psbool)(PBSTART+0x59e)))  /*                       Настроить энкодер ББ2 */
#define signal_A1MC01LC1     (*((psbool)(PBSTART+0x5a0)))  /*                       Настроить энкодер ББ1 */
#define signal_A1MC01LC2     (*((psbool)(PBSTART+0x5a2)))  /*                       Настроить энкодер ББ1 */
#define signal_B2MC01LC1     (*((psbool)(PBSTART+0x5a4)))  /*                       Настроить энкодер РБ2 */
#define signal_B2MC01LC2     (*((psbool)(PBSTART+0x5a6)))  /*                       Настроить энкодер РБ2 */
#define signal_A2MC01LC1     (*((psbool)(PBSTART+0x5a8)))  /*                       Настроить энкодер РБ1 */
#define signal_A2MC01LC2     (*((psbool)(PBSTART+0x5aa)))  /*                       Настроить энкодер РБ1 */
#define signal_B3MC01LC1     (*((psbool)(PBSTART+0x5ac)))  /*                       Настроить энкодер ИС2 */
#define signal_B3MC01LC2     (*((psbool)(PBSTART+0x5ae)))  /*                       Настроить энкодер ИС2 */
#define signal_A3MC01LC1     (*((psbool)(PBSTART+0x5b0)))  /*                       Настроить энкодер ИС1 */
#define signal_A3MC01LC2     (*((psbool)(PBSTART+0x5b2)))  /*                       Настроить энкодер ИС1 */
#define signal_B8MC01LC1     (*((psbool)(PBSTART+0x5b4)))  /*                       Настроить энкодер АЗ2 */
#define signal_B8MC01LC2     (*((psbool)(PBSTART+0x5b6)))  /*                       Настроить энкодер АЗ2 */
#define signal_A8MC01LC1     (*((psbool)(PBSTART+0x5b8)))  /*                       Настроить энкодер ДС2 */
#define signal_A8MC01LC2     (*((psbool)(PBSTART+0x5ba)))  /*                       Настроить энкодер ДС2 */
#define signal_A3VP42LDU     (*((psbool)(PBSTART+0x5bc)))  /*                       Давление ВЫСТРЕЛ ИС1 ниже АС */
#define signal_A3CP02RDU     (*((psfloat)(PBSTART+0x5be)))  /*                       Текущее давление ВЫСТРЕЛ ИС1 */
#define signal_B3VP42LDU     (*((psbool)(PBSTART+0x5c3)))  /*                       Давление ВЫСТРЕЛ ИС2 ниже АС */
#define signal_B3CP02RDU     (*((psfloat)(PBSTART+0x5c5)))  /*                       Текущее давление ВЫСТРЕЛ ИС2 */
#define signal_B3VP82LDU     (*((psbool)(PBSTART+0x5ca)))  /*                       Давление ВЫСТРЕЛ ИС2 в норме */
#define signal_A3VP82LDU     (*((psbool)(PBSTART+0x5cc)))  /*                       Давление ВЫСТРЕЛ ИС1 в норме */
#define signal_A3IP02IDU     (*((psint)(PBSTART+0x5ce)))  /*                       Текущее давление ВЫСТРЕЛ ИС1 */
#define signal_B3IP02IDU     (*((psint)(PBSTART+0x5d1)))  /*                       Текущее давление ВЫСТРЕЛ ИС2 */
#define signal_A0VE01LDU     (*((psbool)(PBSTART+0x5d4)))  /*                       Напряжение в системы АЗ1 подано */
#define signal_B0VE01LDU     (*((psbool)(PBSTART+0x5d6)))  /*                       Напряжение в системы АЗ2 подано */
#define signal_A0VP01LDU     (*((psbool)(PBSTART+0x5d8)))  /*                       Давление в системы АЗ1 подано */
#define signal_B0VP01LDU     (*((psbool)(PBSTART+0x5da)))  /*                       Давление в системы АЗ2 подано */
#define signal_A0EE01LZ1     (*((psbool)(PBSTART+0x5dc)))  /*                       Исправность АКНП1 */
#define signal_A0EE03LZ1     (*((psbool)(PBSTART+0x5de)))  /*                       Исправность АКНП3 */
#define signal_A0EE02LZ1     (*((psbool)(PBSTART+0x5e0)))  /*                       Исправность АКНП2 */
#define signal_A0EE04LZ1     (*((psbool)(PBSTART+0x5e2)))  /*                       Исправность АКНП4 */
#define signal_A0VN01LDU     (*((psbool)(PBSTART+0x5e4)))  /*                       Каналы АЗ1 проверены */
#define signal_B0VN01LDU     (*((psbool)(PBSTART+0x5e6)))  /*                       Каналы АЗ2 проверены */
#define signal_A0EE01LZ2     (*((psbool)(PBSTART+0x5e8)))  /*                       Исправность АКНП1 */
#define signal_A0EE03LZ2     (*((psbool)(PBSTART+0x5ea)))  /*                       Исправность АКНП3 */
#define signal_A0EE02LZ2     (*((psbool)(PBSTART+0x5ec)))  /*                       Исправность АКНП2 */
#define signal_A0EE04LZ2     (*((psbool)(PBSTART+0x5ee)))  /*                       Исправность АКНП4 */
#define signal_A0VP71LZ1     (*((psbool)(PBSTART+0x5f0)))  /*                       АЗ по АС любого давления для АЗ1 */
#define signal_A0VP71LZ2     (*((psbool)(PBSTART+0x5f2)))  /*                       АЗ по АС любого давления для АЗ1 */
#define signal_B0VP71LZ1     (*((psbool)(PBSTART+0x5f4)))  /*                       АЗ по АС любого давления для АЗ2 */
#define signal_B0VP71LZ2     (*((psbool)(PBSTART+0x5f6)))  /*                       АЗ по АС любого давления для АЗ2 */
#define signal_A0VS11LDU     (*((psbool)(PBSTART+0x5f8)))  /*                       АЗ1 готова к работе */
#define signal_B0VS11LDU     (*((psbool)(PBSTART+0x5fa)))  /*                       АЗ2 готова к работе */
#define signal_A1IE01LDU     (*((psbool)(PBSTART+0x5fc)))  /*                       Исправность БУШД ББ1 */
#define signal_A3IE01LDU     (*((psbool)(PBSTART+0x5fe)))  /*                       Исправность БУШД ИС1 */
#define signal_A2IE01LDU     (*((psbool)(PBSTART+0x600)))  /*                       Исправность БУШД РБ1 */
#define signal_A1IE02LDU     (*((psbool)(PBSTART+0x602)))  /*                       Исправность ИП ББ1 */
#define signal_A3IE02LDU     (*((psbool)(PBSTART+0x604)))  /*                       Исправность ИП ИС1 */
#define signal_A2IE02LDU     (*((psbool)(PBSTART+0x606)))  /*                       Исправность ИП РБ1 */
#define signal_B1IE01LDU     (*((psbool)(PBSTART+0x608)))  /*                       Исправность БУШД ББ2 */
#define signal_B2IE01LDU     (*((psbool)(PBSTART+0x60a)))  /*                       Исправность БУШД РБ2 */
#define signal_B3IE01LDU     (*((psbool)(PBSTART+0x60c)))  /*                       Исправность БУШД ИС2 */
#define signal_B1IE02LDU     (*((psbool)(PBSTART+0x60e)))  /*                       Исправность ИП ББ2 */
#define signal_B3IE02LDU     (*((psbool)(PBSTART+0x610)))  /*                       Исправность ИП ИС2 */
#define signal_B2IE02LDU     (*((psbool)(PBSTART+0x612)))  /*                       Исправность ИП РБ2 */
#define signal_R0IE02LDU     (*((psbool)(PBSTART+0x614)))  /*                       Исправность ИП 24 В-1 */
#define signal_R0IE01LDU     (*((psbool)(PBSTART+0x616)))  /*                       Исправность ИП 24 В-2 */
#define signal_A6IE01LDU     (*((psbool)(PBSTART+0x618)))  /*                       Исправность ИП БЗ1 */
#define signal_B6IE01LDU     (*((psbool)(PBSTART+0x61a)))  /*                       Исправность ИП БЗ2 */
#define signal_A8IE01LDU     (*((psbool)(PBSTART+0x61c)))  /*                       Исправность ИП ДС2 */
#define signal_B5IE01LDU     (*((psbool)(PBSTART+0x61e)))  /*                       Исправность ИП НЛ2 */
#define signal_A5IE02LDU     (*((psbool)(PBSTART+0x620)))  /*                       Исправность ИП НЛ1 */
#define signal_R1IE01LDU     (*((psbool)(PBSTART+0x622)))  /*                       Исправность ИП МДЗ1 */
#define signal_R2IE01LDU     (*((psbool)(PBSTART+0x624)))  /*                       Исправность ИП МДЗ2 */
#define signal_R6IS61LDU     (*((psbool)(PBSTART+0x626)))  /*                       Исправность 3-х  фазной сети */
#define signal_R6IS64LDU     (*((psbool)(PBSTART+0x628)))  /*                       Исправность ВИП ССДИ-35 1канал */
#define signal_R6IS65LDU     (*((psbool)(PBSTART+0x62a)))  /*                       Исправность ВИП ССДИ-35 2канал */
#define signal_R6IS62LDU     (*((psbool)(PBSTART+0x62c)))  /*                       Исправность ВИП ССДИ-39 1канал */
#define signal_R6IS63LDU     (*((psbool)(PBSTART+0x62e)))  /*                       Исправность ВИП ССДИ-39 2канал */
#define signal_R6IS66LZZ     (*((psbool)(PBSTART+0x630)))  /*                       Исправность ВИП 4,0 (№5) ССДИ-1-1 */
#define signal_R6IS67LZZ     (*((psbool)(PBSTART+0x632)))  /*                       Исправность ВИП 4,0 (№6) ССДИ-1-2 */
#define signal_R6IS68LZZ     (*((psbool)(PBSTART+0x634)))  /*                       Исправность ВИП 4,0 (№7) ССДИ-2 */
#define signal_A3VC01RDU     (*((psfloat)(PBSTART+0x636)))  /*                       Координата ИС1, мм */
#define signal_A2VC01RDU     (*((psfloat)(PBSTART+0x63b)))  /*                       Координата РБ1, мм */
#define signal_B2VC01RDU     (*((psfloat)(PBSTART+0x640)))  /*                       Координата РБ2, мм */
#define signal_B8VC01RDU     (*((psfloat)(PBSTART+0x645)))  /*                       Координата АЗ2, мм */
#define signal_A4VP82LDU     (*((psbool)(PBSTART+0x64a)))  /*                       Давление ПОДЪЁМ НИ1 в норме */
#define signal_B4VP82LDU     (*((psbool)(PBSTART+0x64c)))  /*                       Давление ПОДЪЁМ НИ2 в норме */
#define signal_A2VP82LDU     (*((psbool)(PBSTART+0x64e)))  /*                       Давление ПОДЪЁМ РБ1 в норме */
#define signal_B2VP82LDU     (*((psbool)(PBSTART+0x650)))  /*                       Давление ПОДЪЁМ РБ2 в норме */
#define signal_A3VP81LDU     (*((psbool)(PBSTART+0x652)))  /*                       Давление СПУСК ИС1 в норме */
#define signal_B3VP81LDU     (*((psbool)(PBSTART+0x654)))  /*                       Давление СПУСК ИС2 в норме */
#define signal_R0EE02LDU     (*((psbool)(PBSTART+0x656)))  /*                       Питание  АКНП  отключить */

/* Определение констант ПЗУ и ЭСППЗУ*/
struct       sint  iRM_8_ = {    8,0}; /* N-число входов */ 
struct      slong  dRM_16777215_ = {16777215,0}; /*  */ 
struct      schar  bRM_1_ = {    1,0}; /* FileN - номер файла ЭСППЗУ */ 
struct       sint  iRM_0_ = {    0,0}; /* FileOffs - смещение в файле ЭСППЗУ */ 
struct       sint  iRM_4_ = {    4,0}; /* p */ 
struct     sfloat  fRM_0_0 = {  0.0,0}; /* Стартовая координата ИС по умолчанию */ 
struct     sfloat  fRM_1500_0 = {1500.0,0}; /* Стартовая координата АЗ2/ДС2 по умолчанию */ 
struct     sfloat  fRM_100_0 = {100.0,0}; /* Стартовая координата ББ по умолчанию */ 
struct       sint  iRM_2_ = {    2,0}; /* p */ 
struct       sint  iRM_1_ = {    1,0}; /* p */ 
struct       sint  iRM_3_ = {    3,0}; /* p */ 
struct       sint  iRM_11_ = {   11,0}; /* p */ 
struct       sint  iRM_5_ = {    5,0}; /* p */ 
struct       sint  iRM_6_ = {    6,0}; /* p */ 
struct      sbool  lRM_1_ = {    1,0}; /* A-Граница участка насыщения А */ 
struct      sbool  lRM_0_ = {    0,0}; /* B-Граница участка насыщения В */ 
struct      slong  dRM_0_ = {    0,0}; /* lx вход лонг */ 
struct      schar  bRM_0_ = {    0,0}; /* cx вход байтовый */ 
struct       sint  iRM_21_ = {   21,0}; /* N-число входов */ 
struct       sint  iRM_17_ = {   17,0}; /* N-число входов */ 
struct       sint  iRM_7_ = {    7,0}; /* N-число входов */ 
struct       sint  iRM_20_ = {   20,0}; /* N-число входов */ 
struct       sint  iRM_18_ = {   18,0}; /* N-число входов */ 
struct       sint  iRM_80_ = {   80,0}; /* N-число входов */ 
struct       sint  iRM_10_ = {   10,0}; /* N-число входов */ 
struct       sint  iRM_150_ = {  150,0}; /* N-число входов */ 
struct       sint  iRM_12_ = {   12,0}; /* N-число входов */ 
struct       sint  iRM_60_ = {   60,0}; /* N-число входов */ 
struct       sint  iRM_9_ = {    9,0}; /* p */ 
struct       sint  iRM_16_ = {   16,0}; /* n - N-размерность массива x */ 
struct     sfloat  fRM_0_ = {    0,0}; /* x - массив входных параметров */ 
struct       sint  iRM_819_ = {  819,0}; /* a */ 
struct       sint  iRM_4095_ = { 4095,0}; /* b */ 
struct      schar  bRM_2_ = {    2,0}; /* type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец */ 
struct      schar  bRM_3_ = {    3,0}; /* type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец */ 
struct      schar  bRM_4_ = {    4,0}; /* type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец */ 
struct      schar  bRM_5_ = {    5,0}; /* type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец */ 
struct      schar  bRM_6_ = {    6,0}; /* type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец */ 
struct     sfloat  fRM_100_ = {  100,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_160_ = {  160,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_20_ = {   20,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_20_03 = {20.03,0}; /* X2 */ 
struct     sfloat  fRM_20_0 = { 20.0,0}; /* X2 */ 
struct       sint  iRM_14_ = {   14,0}; /* n - N-размерность массива x */ 
struct     sfloat  fRM_2_0 = {  2.0,0}; /* tz - время задержки */ 
struct     sfloat  fRM_3_0 = {  3.0,0}; /* tz - время задержки */ 
struct     sfloat  fRM_2_5 = {  2.5,0}; /* tz - время задержки */ 
struct     sfloat  fRM_15_0 = { 15.0,0}; /* tz - время задержки */ 
struct     sfloat  fRM_0_002 = {0.002,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_0_005 = {0.005,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_0_007 = {0.007,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_0_01 = { 0.01,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_0_015 = {0.015,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_0_02 = { 0.02,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_1_7 = {  1.7,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_10_0 = { 10.0,0}; /* tz - время задержки */ 
struct     sfloat  fRM_0_15 = { 0.15,0}; /* tz - ширина импульса, sek */ 
struct     sfloat  fRM_0_2 = {  0.2,0}; /* tz - ширина импульса, sek */ 
struct     sfloat  fRM_0_5 = {  0.5,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_3_5 = {  3.5,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_6_5 = {  6.5,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_9_5 = {  9.5,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_12_5 = { 12.5,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_15_5 = { 15.5,0}; /* Tpr - время завершения проверки сек от старта программы */ 
struct     sfloat  fRM_30_0 = { 30.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_50_0 = { 50.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_70_0 = { 70.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_90_0 = { 90.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_110_0 = {110.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_130_0 = {130.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_150_0 = {150.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_170_0 = {170.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_200_0 = {200.0,0}; /* Tpr - время окончания проверки сек от старта программы */ 
struct     sfloat  fRM_6_0 = {  6.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_126_0 = {126.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_246_0 = {246.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_366_0 = {366.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_486_0 = {486.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_606_0 = {606.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_726_0 = {726.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_846_0 = {846.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_966_0 = {966.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
struct     sfloat  fRM_1200_0 = {1200.0,0}; /* Tpr - время завершения проверки сек от старта программы */ 
struct     sfloat  fRM_2000_ = { 2000,0}; /* Lt_bw - шкала координат выбора скорости движения назад(мм) */ 
struct     sfloat  fRM_390_ = {  390,0}; /* Kt - текущее, известное(контрольное) положение механизма, мм */ 
struct     sfloat  fRM_390_0 = {390.0,0}; /* Kt - текущее, известное(контрольное) положение механизма, мм */ 
struct     sfloat  fRM_1000_ = { 1000,0}; /* Lt_fw - шкала координат выбора скорости движения вперёд(мм) */ 
struct     sfloat  fRM_210_0 = {210.0,0}; /* Время задержки подъёма ОРР после сброса (сек) */ 
struct     sfloat  fRM_100_0001 = {100.0001,0}; /* X2 */ 
struct     sfloat  fRM_0_0001 = {0.0001,0}; /* X1 */ 
struct     sfloat  fRM_160_0001 = {160.0001,0}; /* X2 */ 
struct     sfloat  fRM_160_00001 = {160.00001,0}; /* X2 */ 
struct     sfloat  fRM_389_99 = {389.99,0}; /* X1 */ 
struct     sfloat  fRM_1500_0001 = {1500.0001,0}; /* X2 */ 
struct       sint  iRM_47_ = {   47,0}; /* n - N-размерность массива входных параметров */ 
struct     sfloat  fRM_3_ = {    3,0}; /* tz - время задержки сек */ 
struct     sfloat  fRM_55_0 = { 55.0,0}; /* X1 */ 
struct     sfloat  fRM_1_0 = {  1.0,0}; /* tz - ширина импульса, sek */ 
#define fEM_A1UC03RDU  (*((psfloat)(SpaEEPROMBuf+0x0)))
#define dEM_A1UC05UDU  (*((pslong)(SpaEEPROMBuf+0x5)))
#define dEM_A1UC06UDU  (*((pslong)(SpaEEPROMBuf+0xA)))
#define dEM_A2UC06UDU  (*((pslong)(SpaEEPROMBuf+0xF)))
#define dEM_A2UC05UDU  (*((pslong)(SpaEEPROMBuf+0x14)))
#define fEM_A2UC03RDU  (*((psfloat)(SpaEEPROMBuf+0x19)))
#define dEM_A3UC06UDU  (*((pslong)(SpaEEPROMBuf+0x1E)))
#define dEM_A3UC05UDU  (*((pslong)(SpaEEPROMBuf+0x23)))
#define fEM_A3UC03RDU  (*((psfloat)(SpaEEPROMBuf+0x28)))
#define dEM_A8UC06UDU  (*((pslong)(SpaEEPROMBuf+0x2D)))
#define fEM_A8UC03RDU  (*((psfloat)(SpaEEPROMBuf+0x32)))
#define dEM_A8UC05UDU  (*((pslong)(SpaEEPROMBuf+0x37)))
#define fEM_R0UV81RDU  (*((psfloat)(SpaEEPROMBuf+0x3C)))
#define fEM_R0UV82RDU  (*((psfloat)(SpaEEPROMBuf+0x41)))
#define fEM_R0UV83RDU  (*((psfloat)(SpaEEPROMBuf+0x46)))
#define fEM_R0UV84RDU  (*((psfloat)(SpaEEPROMBuf+0x4B)))
#define fEM_R0UV86RDU  (*((psfloat)(SpaEEPROMBuf+0x50)))
#define fEM_R0UV85RDU  (*((psfloat)(SpaEEPROMBuf+0x55)))
#define fEM_R0UV87RDU  (*((psfloat)(SpaEEPROMBuf+0x5A)))
#define fEM_A3UP03RDU  (*((psfloat)(SpaEEPROMBuf+0x5F)))
#define fEM_A3UP04RDU  (*((psfloat)(SpaEEPROMBuf+0x64)))
#define fEM_A3UP43RDU  (*((psfloat)(SpaEEPROMBuf+0x69)))
#define fEM_A3UP44RDU  (*((psfloat)(SpaEEPROMBuf+0x6E)))
#define fEM_A3UP53RDU  (*((psfloat)(SpaEEPROMBuf+0x73)))
#define fEM_A3UP85RDU  (*((psfloat)(SpaEEPROMBuf+0x78)))
#define fEM_A3UP88RDU  (*((psfloat)(SpaEEPROMBuf+0x7D)))
#define fEM_A3UP86RDU  (*((psfloat)(SpaEEPROMBuf+0x82)))
#define fEM_B8UV01RDU  (*((psfloat)(SpaEEPROMBuf+0x87)))
#define fEM_B8UV02RDU  (*((psfloat)(SpaEEPROMBuf+0x8C)))
#define fEM_B8UV03RDU  (*((psfloat)(SpaEEPROMBuf+0x91)))
#define fEM_B8UL04RDU  (*((psfloat)(SpaEEPROMBuf+0x96)))
#define iEM_A2UV03CDU  (*((psint)(SpaEEPROMBuf+0x9B)))
#define fEM_A2UV01RDU  (*((psfloat)(SpaEEPROMBuf+0x9E)))
#define fEM_A2UV02RDU  (*((psfloat)(SpaEEPROMBuf+0xA3)))
#define fEM_A1UV01RDU  (*((psfloat)(SpaEEPROMBuf+0xA8)))
#define fEM_A1UV02RDU  (*((psfloat)(SpaEEPROMBuf+0xAD)))
#define fEM_A1UC06RDU  (*((psfloat)(SpaEEPROMBuf+0xB2)))
#define fEM_A1UC05RDU  (*((psfloat)(SpaEEPROMBuf+0xB7)))
#define fEM_A1UL04RDU  (*((psfloat)(SpaEEPROMBuf+0xBC)))
#define fEM_A3UV01RDU  (*((psfloat)(SpaEEPROMBuf+0xC1)))
#define fEM_A3UV02RDU  (*((psfloat)(SpaEEPROMBuf+0xC6)))
#define fEM_A3UC06RDU  (*((psfloat)(SpaEEPROMBuf+0xCB)))
#define fEM_A3UC05RDU  (*((psfloat)(SpaEEPROMBuf+0xD0)))
#define fEM_A3UL04RDU  (*((psfloat)(SpaEEPROMBuf+0xD5)))
#define fEM_A3UP54RDU  (*((psfloat)(SpaEEPROMBuf+0xDA)))
#define fEM_A3UP87RDU  (*((psfloat)(SpaEEPROMBuf+0xDF)))
#define fEM_R0UL05RDU  (*((psfloat)(SpaEEPROMBuf+0xE4)))
#define fEM_R0UL20RDU  (*((psfloat)(SpaEEPROMBuf+0xE9)))
#define fEM_B8UV04RDU  (*((psfloat)(SpaEEPROMBuf+0xEE)))
#define fEM_B8UC06RDU  (*((psfloat)(SpaEEPROMBuf+0xF3)))
#define fEM_B8UC05RDU  (*((psfloat)(SpaEEPROMBuf+0xF8)))
#define fEM_A2UL05RDU  (*((psfloat)(SpaEEPROMBuf+0xFD)))
#define fEM_A2UL03RDU  (*((psfloat)(SpaEEPROMBuf+0x102)))
#define fEM_A2UC06RDU  (*((psfloat)(SpaEEPROMBuf+0x107)))
#define fEM_A2UC05RDU  (*((psfloat)(SpaEEPROMBuf+0x10C)))
#define fEM_A2UL04RDU  (*((psfloat)(SpaEEPROMBuf+0x111)))
#define fEM_A1UL03RDU  (*((psfloat)(SpaEEPROMBuf+0x116)))
#define fEM_A1UL05RDU  (*((psfloat)(SpaEEPROMBuf+0x11B)))
#define fEM_A3UL03RDU  (*((psfloat)(SpaEEPROMBuf+0x120)))
#define fEM_A3UL05RDU  (*((psfloat)(SpaEEPROMBuf+0x125)))
#define fEM_A1UC08RDU  (*((psfloat)(SpaEEPROMBuf+0x12A)))
#define fEM_A3UC08RDU  (*((psfloat)(SpaEEPROMBuf+0x12F)))
#define fEM_A1UC07RDU  (*((psfloat)(SpaEEPROMBuf+0x134)))
#define fEM_A1UL01RDU  (*((psfloat)(SpaEEPROMBuf+0x139)))
#define fEM_A3UC07RDU  (*((psfloat)(SpaEEPROMBuf+0x13E)))
#define fEM_A3UL01RDU  (*((psfloat)(SpaEEPROMBuf+0x143)))
#define fEM_A2UC08RDU  (*((psfloat)(SpaEEPROMBuf+0x148)))
#define fEM_A2UC07RDU  (*((psfloat)(SpaEEPROMBuf+0x14D)))
#define fEM_A2UL01RDU  (*((psfloat)(SpaEEPROMBuf+0x152)))
#define fEM_B8UC01RDU  (*((psfloat)(SpaEEPROMBuf+0x157)))
#define fEM_B8UL07RDU  (*((psfloat)(SpaEEPROMBuf+0x15C)))
#define fEM_B8UC02RDU  (*((psfloat)(SpaEEPROMBuf+0x161)))
#define fEM_B8UL01RDU  (*((psfloat)(SpaEEPROMBuf+0x166)))
#define fEM_B8UL05RDU  (*((psfloat)(SpaEEPROMBuf+0x16B)))
#define fEM_B8UL03RDU  (*((psfloat)(SpaEEPROMBuf+0x170)))
#define fEM_B8UL06RDU  (*((psfloat)(SpaEEPROMBuf+0x175)))
#define fEM_A9UZ03RDU  (*((psfloat)(SpaEEPROMBuf+0x17A)))
#define fEM_A9UZ04RDU  (*((psfloat)(SpaEEPROMBuf+0x17F)))
#define fEM_A9UZ05RDU  (*((psfloat)(SpaEEPROMBuf+0x184)))
#define fEM_R4UZ04RDU  (*((psfloat)(SpaEEPROMBuf+0x189)))
#define fEM_R4UZ03RDU  (*((psfloat)(SpaEEPROMBuf+0x18E)))
#define fEM_R4UZ05RDU  (*((psfloat)(SpaEEPROMBuf+0x193)))
#define fEM_A5UZ03RDU  (*((psfloat)(SpaEEPROMBuf+0x198)))
#define fEM_A5UZ04RDU  (*((psfloat)(SpaEEPROMBuf+0x19D)))
#define fEM_A5UZ05RDU  (*((psfloat)(SpaEEPROMBuf+0x1A2)))
#define fEM_A4UZ03RDU  (*((psfloat)(SpaEEPROMBuf+0x1A7)))
#define fEM_A4UZ04RDU  (*((psfloat)(SpaEEPROMBuf+0x1AC)))
#define fEM_A4UZ05RDU  (*((psfloat)(SpaEEPROMBuf+0x1B1)))
#define fEM_A6UZ03RDU  (*((psfloat)(SpaEEPROMBuf+0x1B6)))
#define fEM_A6UZ04RDU  (*((psfloat)(SpaEEPROMBuf+0x1BB)))
#define fEM_A6UZ05RDU  (*((psfloat)(SpaEEPROMBuf+0x1C0)))
#define fEM_R1UZ03RDU  (*((psfloat)(SpaEEPROMBuf+0x1C5)))
#define fEM_R1UZ04RDU  (*((psfloat)(SpaEEPROMBuf+0x1CA)))
#define fEM_R1UZ05RDU  (*((psfloat)(SpaEEPROMBuf+0x1CF)))
#define fEM_R0UL04RDU  (*((psfloat)(SpaEEPROMBuf+0x1D4)))
#define fEM_R0UL06RDU  (*((psfloat)(SpaEEPROMBuf+0x1D9)))
#define fEM_R0UL03RDU  (*((psfloat)(SpaEEPROMBuf+0x1DE)))
#define fEM_R0UL17RDU  (*((psfloat)(SpaEEPROMBuf+0x1E3)))
#define fEM_R0UL19RDU  (*((psfloat)(SpaEEPROMBuf+0x1E8)))
#define fEM_R0UL07RDU  (*((psfloat)(SpaEEPROMBuf+0x1ED)))
#define fEM_R0UL18RDU  (*((psfloat)(SpaEEPROMBuf+0x1F2)))
#define fEM_R0UL16RDU  (*((psfloat)(SpaEEPROMBuf+0x1F7)))
#define fEM_R0UL02RDU  (*((psfloat)(SpaEEPROMBuf+0x1FC)))
#define fEM_R0UN08RDU  (*((psfloat)(SpaEEPROMBuf+0x201)))
#define fEM_R0UN07RDU  (*((psfloat)(SpaEEPROMBuf+0x206)))
#define fEM_R0UN06RDU  (*((psfloat)(SpaEEPROMBuf+0x20B)))
#define fEM_R0UN05RDU  (*((psfloat)(SpaEEPROMBuf+0x210)))
#define fEM_R0UN04RDU  (*((psfloat)(SpaEEPROMBuf+0x215)))
#define fEM_R0UN03RDU  (*((psfloat)(SpaEEPROMBuf+0x21A)))
#define fEM_R0UN02RDU  (*((psfloat)(SpaEEPROMBuf+0x21F)))
#define fEM_R0UN01RDU  (*((psfloat)(SpaEEPROMBuf+0x224)))
#define fEM_A2UC82RDU  (*((psfloat)(SpaEEPROMBuf+0x229)))
#define fEM_A2UC83RDU  (*((psfloat)(SpaEEPROMBuf+0x22E)))
#define fEM_A1UC83RDU  (*((psfloat)(SpaEEPROMBuf+0x233)))
#define fEM_A2UC81RDU  (*((psfloat)(SpaEEPROMBuf+0x238)))
#define fEM_A1UC81RDU  (*((psfloat)(SpaEEPROMBuf+0x23D)))
#define fEM_A1UC82RDU  (*((psfloat)(SpaEEPROMBuf+0x242)))
#define fEM_A2UL83RDU  (*((psfloat)(SpaEEPROMBuf+0x247)))
#define fEM_A3UC81RDU  (*((psfloat)(SpaEEPROMBuf+0x24C)))
#define fEM_A3UC82RDU  (*((psfloat)(SpaEEPROMBuf+0x251)))
#define fEM_R0UN80RDU  (*((psfloat)(SpaEEPROMBuf+0x256)))
#define iEM_A2UV01IDU  (*((psint)(SpaEEPROMBuf+0x25B)))
#define iEM_A2UV02IDU  (*((psint)(SpaEEPROMBuf+0x25E)))
#define iEM_A1UV01IDU  (*((psint)(SpaEEPROMBuf+0x261)))
#define iEM_A1UV02IDU  (*((psint)(SpaEEPROMBuf+0x264)))
#define iEM_A1UV03IDU  (*((psint)(SpaEEPROMBuf+0x267)))
#define iEM_A3UV01IDU  (*((psint)(SpaEEPROMBuf+0x26A)))
#define iEM_A3UV02IDU  (*((psint)(SpaEEPROMBuf+0x26D)))
#define lEM_R0MD01LC1  (*((psbool)(SpaEEPROMBuf+0x270)))
#define fEM_A3UC09RDU  (*((psfloat)(SpaEEPROMBuf+0x272)))
#define fEM_A2UC02RDU  (*((psfloat)(SpaEEPROMBuf+0x277)))
#define fEM_A1UC02RDU  (*((psfloat)(SpaEEPROMBuf+0x27C)))
#define fEM_A3UC02RDU  (*((psfloat)(SpaEEPROMBuf+0x281)))
#define fEM_R0UL21RDU  (*((psfloat)(SpaEEPROMBuf+0x286)))
#define fEM_R0UN09RDU  (*((psfloat)(SpaEEPROMBuf+0x28B)))
#define fEM_R0UN11RDU  (*((psfloat)(SpaEEPROMBuf+0x290)))
#define fEM_R0UN12RDU  (*((psfloat)(SpaEEPROMBuf+0x295)))
#define fEM_R0UN13RDU  (*((psfloat)(SpaEEPROMBuf+0x29A)))
#define fEM_R0UN14RDU  (*((psfloat)(SpaEEPROMBuf+0x29F)))
#define fEM_R0UN16RDU  (*((psfloat)(SpaEEPROMBuf+0x2A4)))
#define fEM_R0UN17RDU  (*((psfloat)(SpaEEPROMBuf+0x2A9)))
#define fEM_R0UN18RDU  (*((psfloat)(SpaEEPROMBuf+0x2AE)))
#define fEM_R0UN19RDU  (*((psfloat)(SpaEEPROMBuf+0x2B3)))
#define fEM_R0UN70LDU  (*((psfloat)(SpaEEPROMBuf+0x2B8)))
#define fEM_R0UN71LDU  (*((psfloat)(SpaEEPROMBuf+0x2BD)))
#define fEM_R0UN72LDU  (*((psfloat)(SpaEEPROMBuf+0x2C2)))
#define fEM_R0UN73LDU  (*((psfloat)(SpaEEPROMBuf+0x2C7)))
#define fEM_R0UN74LDU  (*((psfloat)(SpaEEPROMBuf+0x2CC)))
#define fEM_R0UN75LDU  (*((psfloat)(SpaEEPROMBuf+0x2D1)))
#define fEM_R0UN80LDU  (*((psfloat)(SpaEEPROMBuf+0x2D6)))
#define fEM_R0UN81LDU  (*((psfloat)(SpaEEPROMBuf+0x2DB)))
#define fEM_R0UN82LDU  (*((psfloat)(SpaEEPROMBuf+0x2E0)))
#define fEM_R0UN83LDU  (*((psfloat)(SpaEEPROMBuf+0x2E5)))
#define fEM_R0UN84LDU  (*((psfloat)(SpaEEPROMBuf+0x2EA)))
#define fEM_R0UN85LDU  (*((psfloat)(SpaEEPROMBuf+0x2EF)))
#define fEM_R0UT20RDU  (*((psfloat)(SpaEEPROMBuf+0x2F4)))
#define fEM_R0UN25RDU  (*((psfloat)(SpaEEPROMBuf+0x2F9)))
#define fEM_R0UN15RDU  (*((psfloat)(SpaEEPROMBuf+0x2FE)))
#define fEM_R0UN26RDU  (*((psfloat)(SpaEEPROMBuf+0x303)))
#define fEM_R0UN27RDU  (*((psfloat)(SpaEEPROMBuf+0x308)))
#define fEM_R0UN24RDU  (*((psfloat)(SpaEEPROMBuf+0x30D)))
#define fEM_R0UL25RDU  (*((psfloat)(SpaEEPROMBuf+0x312)))

int SpaEEPROMBufSize = 791;

/* Определение переменных */
struct sbool  var1;
struct sbool  var2;
struct sbool  var3;
struct sbool  var4;
struct sbool  var5;
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
struct sbool  var19 = {0,0};
struct sbool  var20;
struct sbool  var21;
struct sbool  var22;
struct sbool  var23 = {0,0};
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
struct sbool  var35 = {0,0};
struct sbool  var36 = {0,0};
struct sbool  var37;
struct sbool  var38 = {0,0};
struct sbool  var39;
struct sbool  var40;
struct sbool  var41;
struct sbool  var42;
struct sbool  var43 = {0,0};
struct sbool  var44;
struct sbool  var45;
struct sbool  var46 = {0,0};
struct sbool  var47;
struct sbool  var48 = {0,0};
struct sbool  var49 = {0,0};
struct sbool  var50;
struct sbool  var51;
struct sbool  var52;
struct sbool  var53;
struct sbool  var54 = {0,0};
struct sbool  var55;
struct sbool  var56 = {0,0};
struct sbool  var57;
struct sbool  var58 = {0,0};
struct sbool  var59;
struct sbool  var60;
struct sbool  var61;
struct sbool  var62;
struct sbool  var63;
struct sbool  var64 = {0,0};
struct sbool  var65;
struct sbool  var66;
struct sbool  var67;
struct sbool  var68 = {0,0};
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
struct sint  var84;
struct sbool  var85;
struct sbool  var86;
struct sint  var87;
struct sbool  var88;
struct sbool  var89;
struct sbool  var90;
struct sbool  var91;
struct sbool  var92;
struct sbool  var93;
struct sbool  var94;
struct sbool  var95;
struct sbool  var96;
struct sbool  var97;
struct sbool  var98;
struct sbool  var99;
struct sbool  var100;
struct sbool  var101;
struct sbool  var102;
struct sbool  var103;
struct sbool  var104 = {0,0};
struct sbool  var105 = {0,0};
struct sbool  var106 = {0,0};
struct sbool  var107 = {0,0};
struct sbool  var108;
struct sbool  var109;
struct sbool  var110;
struct sbool  var111;
struct sbool  var112;
struct sbool  var113;
struct sbool  var114;
struct sbool  var115;
struct sbool  var116;
struct sbool  var117;
struct sbool  var118;
struct sbool  var119;
struct sbool  var120 = {0,0};
struct sbool  var121;
struct sbool  var122;
struct sbool  var123;
struct sbool  var124;
struct sbool  var125;
struct sbool  var126;
struct sbool  var127;
struct sbool  var128;
struct sbool  var129;
struct sbool  var130;
struct sbool  var131;
struct sfloat  var132;
struct sbool  var133;
struct sbool  var134;
struct sbool  var135;
struct sbool  var136;
struct sbool  var137;
struct sbool  var138;
struct sbool  var139 = {0,0};
struct sbool  var140;
struct sbool  var141;
struct sfloat  var142;
struct sfloat  var143;
struct sbool  var144;
struct sbool  var145 = {0,0};
struct sbool  var146;
struct sfloat  var147;
struct sfloat  var148;
struct sbool  var149;
struct sbool  var150;
struct sfloat  var151;
struct sbool  var152;
struct sbool  var153 = {0,0};
struct sbool  var154;
struct sbool  var155;
struct sbool  var156;
struct sbool  var157;
struct sbool  var158;
struct sbool  var159;
struct sfloat  var160;
struct sfloat  var161;
struct sfloat  var162 = {0,0};
struct sfloat  var163;
struct sbool  var164 = {0,0};
struct sfloat  var165;
struct sfloat  var166;
struct sint  var167;
struct sbool  var168;
struct sbool  var169;
struct sbool  var170;
struct sbool  var171;
struct sbool  var172 = {0,0};
struct sbool  var173 = {0,0};
struct sbool  var174;
struct sbool  var175;
struct sbool  var176;
struct sbool  var177;
struct sbool  var178;
struct sbool  var179;
struct sbool  var180;
struct sbool  var181;
struct sbool  var182;
struct sbool  var183;
struct sbool  var184;
struct sbool  var185;
struct sbool  var186;
struct sbool  var187;
struct sbool  var188;
struct sbool  var189;
struct sbool  var190;
struct sbool  var191;
struct sbool  var192;
struct sbool  var193;
struct sbool  var194 = {0,0};
struct sbool  var195 = {0,0};
struct sbool  var196;
struct sbool  var197;
struct sbool  var198 = {0,0};
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
struct sbool  var218;
struct sbool  var219;
struct sbool  var220;
struct sbool  var221;
struct sbool  var222;
struct sbool  var223;
struct sbool  var224;
struct sbool  var225;
struct sbool  var226;
struct sbool  var227;
struct sbool  var228;
struct sbool  var229;
struct sbool  var230;
struct sbool  var231;
struct sbool  var232;
struct sbool  var233;
struct sbool  var234;
struct sbool  var235;
struct sbool  var236;
struct sbool  var237 = {0,0};
struct sbool  var238;
struct sbool  var239;
struct sbool  var240;
struct sbool  var241 = {0,0};
struct sbool  var242 = {0,0};
struct sbool  var243;
struct sbool  var244;
struct sbool  var245;
struct sbool  var246 = {0,0};
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
struct sbool  var258 = {0,0};
struct sbool  var259;
struct sbool  var260;
struct sbool  var261;
struct sfloat  var262;
struct sbool  var263;
struct sbool  var264;
struct sbool  var265;
struct sfloat  var266;
struct sbool  var267;
struct sbool  var268;
struct sbool  var269;
struct sfloat  var270;
struct sbool  var271;
struct sbool  var272;
struct sbool  var273;
struct sfloat  var274 = {0,0};
struct sbool  var275;
struct sbool  var276;
struct sbool  var277;
struct sfloat  var278;
struct sbool  var279;
struct sbool  var280;
struct sbool  var281;
struct sbool  var282;
struct sbool  var283;
struct sbool  var284;
struct sbool  var285;
struct sbool  var286 = {0,0};
struct sbool  var287;
struct sbool  var288 = {0,0};
struct sbool  var289 = {0,0};
struct sbool  var290;
struct sbool  var291;
struct sbool  var292;
struct sbool  var293;
struct sbool  var294;
struct sbool  var295;
struct sbool  var296;
struct sbool  var297;
struct sbool  var298;
struct sbool  var299;
struct sbool  var300;
struct sbool  var301;
struct sbool  var302;
struct sbool  var303;
struct sbool  var304;
struct sbool  var305;
struct sbool  var306;
struct sbool  var307;
struct sbool  var308;
struct sbool  var309;
struct sbool  var310;
struct sbool  var311;
struct sbool  var312;
struct sbool  var313;
struct sbool  var314;
struct sbool  var315;
struct sbool  var316;
struct sbool  var317;
struct sbool  var318;
struct sbool  var319;
struct sbool  var320;
struct sbool  var321;
struct sbool  var322;
struct sbool  var323;
struct sbool  var324;
struct sbool  var325;
struct sbool  var326;
struct sbool  var327;
struct sbool  var328;
struct sbool  var329;
struct sbool  var330;
struct sbool  var331;
struct sbool  var332;
struct sbool  var333;
struct sbool  var334;
struct sbool  var335;
struct sbool  var336;
struct sbool  var337;
struct sbool  var338 = {0,0};
struct sbool  var339 = {0,0};
struct sbool  var340;
struct sbool  var341;
struct sbool  var342;
struct sbool  var343;
struct sbool  var344;
struct sbool  var345;
struct sbool  var346;
struct sbool  var347;
struct sbool  var348;
struct sbool  var349;
struct sbool  var350;
struct sbool  var351;
struct sbool  var352;
struct sbool  var353;
struct sbool  var354;
struct sbool  var355;
struct sbool  var356;
struct sbool  var357;
struct sbool  var358;
struct sbool  var359;
struct sbool  var360;
struct sbool  var361;
struct sbool  var362;
struct sbool  var363;
struct sbool  var364;
struct sbool  var365;
struct sbool  var366;
struct sbool  var367;
struct sbool  var368;
struct sbool  var369;
struct sbool  var370;
struct sbool  var371;
struct sbool  var372;
struct sbool  var373;
struct sbool  var374;
struct sfloat  var375;
struct sfloat  var376;
struct sbool  var377;
struct sfloat  var378;
struct sfloat  var379;
struct sbool  var380;
struct sfloat  var381;
struct sfloat  var382;
struct sbool  var383;
struct sfloat  var384;
struct sfloat  var385;
struct sbool  var386;
struct sbool  var387;
struct sfloat  var388;
struct sfloat  var389;
struct sbool  var390;
struct sbool  var391;
struct sbool  var392;
struct sbool  var393;
struct sbool  var394;
struct sbool  var395;
struct sbool  var396 = {0,0};
struct sbool  var397;
struct sbool  var398;
struct sbool  var399;
struct sbool  var400;
struct sbool  var401;
struct sbool  var402;
struct sbool  var403;
struct sbool  var404;
struct sbool  var405;
struct sbool  var406;
struct sbool  var407;
struct sbool  var408 = {0,0};
struct sbool  var409 = {0,0};
struct sbool  var410;
struct sbool  var411;
struct sbool  var412;
struct sbool  var413;
struct sbool  var414;
struct sbool  var415;
struct sbool  var416;
struct sbool  var417;
struct sbool  var418;
struct sbool  var419;
struct sbool  var420;
struct sbool  var421;
struct sbool  var422;
struct sbool  var423;
struct sbool  var424;
struct sbool  var425;
struct sbool  var426;
struct sbool  var427;
struct sbool  var428;
struct sbool  var429;
struct sbool  var430;
struct sbool  var431;
struct sbool  var432;
struct sbool  var433;
struct sbool  var434;
struct sbool  var435;
struct sbool  var436;
struct sbool  var437;
struct sbool  var438;
struct sbool  var439;
struct sbool  var440;
struct sbool  var441;
struct sbool  var442;
struct sbool  var443;
struct sbool  var444;
struct sbool  var445;
struct sbool  var446;
struct sbool  var447;
struct sbool  var448;
struct sbool  var449;
struct sbool  var450;
struct sbool  var451;
struct sbool  var452;
struct sbool  var453;
struct sbool  var454;
struct sbool  var455;
struct sbool  var456;
struct sbool  var457;
struct sbool  var458;
struct sbool  var459;
struct sbool  var460;
struct sbool  var461;
struct sbool  var462;
struct sbool  var463 = {0,0};
struct sbool  var464 = {0,0};
struct sbool  var465;
struct sbool  var466 = {0,0};
struct sbool  var467;
struct sbool  var468 = {0,0};
struct sbool  var469;
struct sbool  var470 = {0,0};
struct sbool  var471;
struct sbool  var472;
struct sbool  var473;
struct sbool  var474;
struct sbool  var475;
struct sbool  var476;
struct sbool  var477;
struct sbool  var478;
struct sbool  var479;
struct sbool  var480;
struct sbool  var481;
struct sbool  var482;
struct sbool  var483;
struct sbool  var484;
struct sbool  var485;
struct sbool  var486;
struct sbool  var487;
struct sbool  var488;
struct sbool  var489;
struct sbool  var490 = {0,0};
struct sbool  var491 = {0,0};
struct sbool  var492;
struct sbool  var493;
struct sbool  var494 = {0,0};
struct sbool  var495;
struct sbool  var496 = {0,0};
struct sbool  var497;
struct sbool  var498;
struct sbool  var499;
struct sbool  var500 = {0,0};
struct sbool  var501;
struct sbool  var502 = {0,0};
struct sbool  var503;
struct sbool  var504;
struct sbool  var505;
struct sbool  var506;
struct sbool  var507;
struct sbool  var508 = {0,0};
struct sbool  var509;
struct sbool  var510;
struct sbool  var511 = {0,0};
struct sbool  var512;
struct sbool  var513;
struct sbool  var514;
struct sbool  var515;
struct sbool  var516;
struct sbool  var517;
struct sbool  var518;
struct sbool  var519;
struct sbool  var520 = {0,0};
struct sbool  var521;
struct sbool  var522;
struct sbool  var523;
struct sbool  var524;
struct sbool  var525;
struct sbool  var526;
struct sbool  var527;
struct sbool  var528;
struct sbool  var529;
struct sbool  var530;
struct sbool  var531;
struct sbool  var532;
struct slong  var533;
struct sbool  var534 = {0,0};
struct sbool  var535;
struct sbool  var536;
struct sbool  var537;
struct sbool  var538;
struct sbool  var539;
struct sbool  var540;
struct sbool  var541;
struct sbool  var542;
struct sbool  var543;
struct sbool  var544;
struct sbool  var545;
struct sbool  var546;
struct sbool  var547;
struct sbool  var548 = {0,0};
struct sbool  var549;
struct sbool  var550;
struct sbool  var551;
struct sbool  var552 = {0,0};
struct sbool  var553;
struct sbool  var554;
struct sbool  var555;
struct sbool  var556;
struct sbool  var557;
struct sbool  var558;
struct sbool  var559;
struct sbool  var560;
struct sbool  var561;
struct sbool  var562;
struct sbool  var563;
struct sbool  var564;
struct sbool  var565;
struct sbool  var566;
struct sbool  var567;
struct sbool  var568 = {0,0};
struct sbool  var569 = {0,0};
struct sbool  var570;
struct sbool  var571;
struct sbool  var572;
struct sbool  var573;
struct sbool  var574;
struct sbool  var575;
struct sbool  var576;
struct sbool  var577;
struct sbool  var578;
struct sbool  var579;
struct sbool  var580;
struct sbool  var581;
struct sbool  var582;
struct sbool  var583;
struct sbool  var584;
struct sbool  var585;
struct sbool  var586;
struct sbool  var587;
struct sbool  var588;
struct sbool  var589;
struct sbool  var590;
struct sbool  var591;
struct sbool  var592;
struct sbool  var593;
struct sbool  var594;
struct sbool  var595;
struct sbool  var596;
struct sbool  var597;
struct sbool  var598;
struct sbool  var599;
struct sbool  var600;
struct sbool  var601;
struct sbool  var602;
struct sbool  var603;
struct sbool  var604;
struct sbool  var605;
struct sbool  var606;
struct sbool  var607;
struct sbool  var608;
struct sbool  var609;
struct sbool  var610;
struct sbool  var611;
struct sbool  var612;
struct sbool  var613;
struct sbool  var614;
struct sbool  var615;
struct sbool  var616;
struct sbool  var617;
struct sbool  var618;
struct sbool  var619;
struct sbool  var620;
struct sbool  var621;
struct sbool  var622;
struct sbool  var623;
struct sbool  var624;
struct sbool  var625;
struct sbool  var626;
struct sbool  var627;
struct sbool  var628;
struct sbool  var629;
struct sbool  var630;
struct sbool  var631;
struct sbool  var632;
struct sbool  var633;
struct sbool  var634;
struct sbool  var635;
struct sbool  var636;
struct sbool  var637;
struct sbool  var638;
struct sbool  var639;
struct sbool  var640;
struct sbool  var641;
struct sbool  var642;
struct sbool  var643;
struct sbool  var644;
struct sbool  var645;
struct sbool  var646;
struct sbool  var647;
struct sbool  var648;
struct sbool  var649;
struct sbool  var650;
struct sbool  var651;
struct sbool  var652;
struct sbool  var653;
struct sbool  var654;
struct sbool  var655;
struct sbool  var656;
struct sbool  var657;
struct sbool  var658;
struct sbool  var659;
struct sbool  var660;
struct sbool  var661;
struct sbool  var662;
struct sbool  var663;
struct sbool  var664;
struct sbool  var665;
struct sbool  var666;
struct sbool  var667;
struct sbool  var668;
struct sbool  var669;
struct sbool  var670;
struct sbool  var671;
struct sbool  var672 = {0,0};
struct sbool  var673 = {0,0};
struct sbool  var674 = {0,0};
struct sbool  var675;
struct sbool  var676;
struct sbool  var677;
struct sbool  var678;
struct sbool  var679;
struct sbool  var680;
struct sbool  var681;
struct sbool  var682;
struct sbool  var683;
struct sbool  var684;
struct sbool  var685;
struct sbool  var686;
struct sbool  var687;
struct sbool  var688;
struct sbool  var689;
struct sbool  var690;
struct sbool  var691;
struct sbool  var692;
struct sbool  var693;
struct sbool  var694;
struct sbool  var695;
struct sbool  var696;
struct sbool  var697;
struct sbool  var698;
struct sbool  var699;
struct sbool  var700;
struct sbool  var701;
struct sbool  var702;
struct sbool  var703;
struct sbool  var704;
struct sbool  var705;
struct sbool  var706;
struct sbool  var707;
struct sbool  var708;
struct sbool  var709;
struct sbool  var710;
struct sbool  var711;
struct sbool  var712;
struct sbool  var713;
struct sbool  var714;
struct sbool  var715;
struct sbool  var716;
struct sbool  var717;
struct sbool  var718;
struct sbool  var719;
struct sbool  var720 = {0,0};
struct sbool  var721 = {0,0};
struct sbool  var722;
struct sbool  var723;
struct sbool  var724;
struct sbool  var725;
struct sbool  var726;
struct sbool  var727;
struct sbool  var728;
struct sbool  var729;
struct sbool  var730;
struct sbool  var731;
struct sbool  var732;
struct sbool  var733 = {0,0};
struct sbool  var734;
struct sbool  var735;
struct sbool  var736;
struct sbool  var737;
struct sbool  var738;
struct sbool  var739;
struct sbool  var740;
struct sbool  var741;
struct sbool  var742 = {0,0};
struct sbool  var743;
struct sbool  var744;
struct sbool  var745 = {0,0};
struct sbool  var746;
struct sbool  var747;
struct sbool  var748;
struct sbool  var749 = {0,0};
struct sbool  var750 = {0,0};
struct sbool  var751;
struct sbool  var752;
struct sbool  var753;
struct sbool  var754;
struct sbool  var755;
struct sbool  var756;
struct sbool  var757;
struct sbool  var758 = {0,0};
struct sbool  var759 = {0,0};
struct sbool  var760;
struct sbool  var761 = {0,0};
struct sbool  var762;
struct sbool  var763;
struct sbool  var764 = {0,0};
struct sbool  var765;
struct sbool  var766 = {0,0};
struct sbool  var767;
struct sbool  var768 = {0,0};
struct sbool  var769;
struct sbool  var770;
struct sbool  var771;
struct sbool  var772;
struct sbool  var773;
struct sbool  var774;
struct sbool  var775;
struct sbool  var776;
struct sbool  var777;
struct sbool  var778;
struct sbool  var779;
struct sbool  var780;
struct sbool  var781;
struct sbool  var782;
struct sbool  var783 = {0,0};
struct sbool  var784;
struct sbool  var785;
struct sbool  var786;
struct sbool  var787;
struct sbool  var788;
struct sbool  var789;
struct sbool  var790;
struct sbool  var791;
struct sbool  var792;
struct sbool  var793;
struct sbool  var794;
struct sbool  var795;
struct sbool  var796;
struct sbool  var797;
struct sbool  var798;
struct sbool  var799;
struct sbool  var800;
struct sbool  var801;
struct sbool  var802;
struct sbool  var803;
struct sbool  var804;
struct sbool  var805;
struct sbool  var806;
struct sbool  var807;
struct sbool  var808;
struct sbool  var809;
struct sbool  var810;
struct sbool  var811;
struct sbool  var812;
struct sbool  var813;
struct sbool  var814;
struct sbool  var815 = {0,0};
struct sbool  var816;
struct sbool  var817 = {0,0};
struct sbool  var818 = {0,0};
struct sbool  var819;
struct sbool  var820;
struct sbool  var821;
struct sbool  var822;
struct sbool  var823;
struct sbool  var824;
struct sbool  var825;
struct sbool  var826;
struct sbool  var827;
struct sbool  var828;
struct sbool  var829;
struct sbool  var830;
struct sbool  var831;
struct sbool  var832;
struct sbool  var833;
struct sbool  var834 = {0,0};
struct sbool  var835;
struct sbool  var836;
struct sbool  var837;
struct sbool  var838 = {0,0};
struct sbool  var839;
struct sbool  var840 = {0,0};
struct sbool  var841;
struct sbool  var842;
struct sbool  var843;
struct sbool  var844;
struct sbool  var845;
struct sbool  var846 = {0,0};
struct sbool  var847;
struct sbool  var848;
struct sbool  var849;
struct sbool  var850;
struct sbool  var851;
struct sbool  var852;
struct sbool  var853;
struct sbool  var854;
struct sbool  var855;
struct sbool  var856;
struct sbool  var857;
struct sbool  var858;
struct sbool  var859;
struct sbool  var860;
struct sbool  var861;
struct sbool  var862;
struct sbool  var863;
struct sbool  var864;
struct sbool  var865;
struct sbool  var866;
struct sbool  var867;
struct sbool  var868;
struct sbool  var869;
struct sbool  var870;
struct sbool  var871;
struct sbool  var872;
struct sbool  var873;
struct sbool  var874;
struct sbool  var875;
struct sbool  var876;
struct sbool  var877;
struct sbool  var878;
struct sbool  var879;
struct sbool  var880;
struct sbool  var881;
struct sbool  var882;
struct sbool  var883;
struct sbool  var884;
struct sbool  var885;
struct sbool  var886;
struct sbool  var887;
struct sbool  var888;
struct sbool  var889;
struct sbool  var890;
struct sbool  var891;
struct sbool  var892;
struct sbool  var893;
struct sbool  var894;
struct sbool  var895;
struct sbool  var896;
struct sbool  var897;
struct sbool  var898;
struct sbool  var899;
struct sbool  var900;
struct sbool  var901;
struct sbool  var902;
struct sbool  var903 = {0,0};
struct sbool  var904 = {0,0};
struct sbool  var905;
struct sbool  var906;
struct sbool  var907 = {0,0};
struct sbool  var908;
struct sbool  var909;
struct sbool  var910;
struct sbool  var911;
struct sbool  var912;
struct sbool  var913;
struct sbool  var914;
struct sbool  var915;
struct sbool  var916;
struct sbool  var917;
struct sbool  var918;
struct sbool  var919;
struct sbool  var920;
struct sbool  var921;
struct sbool  var922;
struct sbool  var923;
struct sbool  var924;
struct sbool  var925;
struct sbool  var926;
struct sbool  var927 = {0,0};
struct sbool  var928;
struct sbool  var929;
struct sbool  var930;
struct sbool  var931;
struct sbool  var932;
struct sbool  var933;
struct sbool  var934;
struct sbool  var935;
struct sbool  var936;
struct sbool  var937;
struct sbool  var938;
struct sbool  var939;
struct sbool  var940;
struct sbool  var941;
struct sbool  var942;
struct sbool  var943;
struct sfloat  var944;
struct sbool  var945;
struct sfloat  var946;
struct sbool  var947;
struct sfloat  var948;
struct sbool  var949;
struct sbool  var950;
struct sbool  var951;
struct sbool  var952;
struct sfloat  var953;
struct sfloat  var954;
struct sfloat  var955;
struct sfloat  var956;
struct sfloat  var957;
struct sfloat  var958;
struct sbool  var959;
struct sbool  var960;
struct sbool  var961;
struct sbool  var962 = {0,0};
struct sbool  var963;
struct sbool  var964;
struct sbool  var965;
struct sbool  var966;
struct sbool  var967;
struct sbool  var968;
struct sbool  var969;
struct sbool  var970 = {0,0};
struct sbool  var971;
struct sbool  var972;
struct sbool  var973 = {0,0};
struct sbool  var974 = {0,0};
struct sbool  var975 = {0,0};
struct sbool  var976;
struct sbool  var977 = {0,0};
struct sbool  var978 = {0,0};
struct sbool  var979 = {0,0};
struct sbool  var980 = {0,0};
struct sbool  var981 = {0,0};
struct sbool  var982;
struct sbool  var983;
struct sbool  var984;
struct sbool  var985 = {0,0};
struct sbool  var986;
struct sbool  var987;
struct sbool  var988;
struct sbool  var989;
struct sbool  var990;
struct sbool  var991;
struct sbool  var992;
struct sbool  var993;
struct sbool  var994;
struct sbool  var995;
struct sbool  var996;
struct sbool  var997;
struct sbool  var998;
struct sbool  var999 = {0,0};
struct sbool  var1000;
struct sbool  var1001;
struct sbool  var1002;
struct sbool  var1003;
struct sbool  var1004;
struct sbool  var1005;
struct sbool  var1006;
struct sbool  var1007;
struct sbool  var1008;
struct sbool  var1009;
struct sbool  var1010;
struct sbool  var1011;
struct sbool  var1012;
struct sbool  var1013;
struct sint  var1014;
struct sint  var1015;
struct sbool  var1016;
struct sbool  var1017;
struct sbool  var1018;
struct sbool  var1019;
struct sbool  var1020;
struct sbool  var1021;
struct slong  var1022;
struct sbool  var1023;
struct sbool  var1024;
struct sbool  var1025;
struct sint  var1026;
struct sbool  var1027;
struct sbool  var1028;
struct sbool  var1029;
struct sbool  var1030;
struct sbool  var1031;
struct sbool  var1032;
struct sbool  var1033;
struct sbool  var1034;
struct sbool  var1035;
struct sint  var1036;
struct sint  var1037;
struct sbool  var1038;
struct sbool  var1039;
struct sbool  var1040;
struct sbool  var1041;
struct sbool  var1042;
struct sbool  var1043;
struct sbool  var1044 = {0,0};
struct sbool  var1045;
struct sbool  var1046;
struct sbool  var1047;
struct sbool  var1048;
struct sbool  var1049;
struct sbool  var1050;
struct sbool  var1051;
struct sbool  var1052;
struct sbool  var1053;
struct sbool  var1054;
struct sbool  var1055;
struct sbool  var1056 = {0,0};
struct sbool  var1057;
struct sbool  var1058;
struct sbool  var1059;
struct sbool  var1060;
struct sbool  var1061;
struct sbool  var1062;
struct sbool  var1063;
struct sbool  var1064;
struct sbool  var1065;
struct sbool  var1066;
struct sbool  var1067;
struct sbool  var1068;
struct sbool  var1069;
struct sbool  var1070;
struct sbool  var1071;
struct sbool  var1072;
struct sbool  var1073 = {0,0};
struct sbool  var1074;
struct sbool  var1075;
struct sbool  var1076;
struct slong  var1077;
struct sbool  var1078;
struct sbool  var1079 = {0,0};
struct sbool  var1080;
struct sbool  var1081;
struct sbool  var1082 = {0,0};
struct sbool  var1083;
struct sbool  var1084;
struct sbool  var1085;
struct sbool  var1086;
struct sbool  var1087;
struct sbool  var1088;
struct sbool  var1089;
struct sbool  var1090 = {0,0};
struct sbool  var1091 = {0,0};
struct sbool  var1092;
struct sbool  var1093 = {0,0};
struct sbool  var1094;
struct sbool  var1095;
struct sfloat  var1096;
struct sbool  var1097;
struct sbool  var1098;
struct sbool  var1099;
struct sbool  var1100;
struct sbool  var1101;
struct sfloat  var1102;
struct sbool  var1103;
struct sbool  var1104;
struct sbool  var1105;
struct sbool  var1106;
struct sbool  var1107;
struct sbool  var1108;
struct sbool  var1109;
struct sbool  var1110;
struct sbool  var1111;
struct sbool  var1112;
struct sbool  var1113;
struct sbool  var1114;
struct sbool  var1115;
struct sint  var1116;
struct sbool  var1117;
struct sbool  var1118;
struct sbool  var1119;
struct sbool  var1120;
struct sbool  var1121;
struct sbool  var1122;
struct sbool  var1123 = {0,0};
struct sbool  var1124;
struct sbool  var1125;
struct sbool  var1126;
struct sbool  var1127;
struct sbool  var1128;
struct sbool  var1129;
struct sbool  var1130;
struct sbool  var1131;
struct sbool  var1132;
struct sbool  var1133;
struct sbool  var1134;
struct sbool  var1135;
struct sbool  var1136;
struct sbool  var1137;
struct sbool  var1138;
struct sbool  var1139;
struct sbool  var1140;
struct sbool  var1141;
struct sfloat  var1142;
struct sbool  var1143;
struct sbool  var1144;
struct sbool  var1145;
struct sbool  var1146;
struct sbool  var1147;
struct sbool  var1148;
struct sbool  var1149;
struct sbool  var1150;
struct sbool  var1151;
struct sbool  var1152;
struct sbool  var1153;
struct sbool  var1154;
struct sbool  var1155;
struct sbool  var1156 = {0,0};
struct sbool  var1157;
struct sbool  var1158 = {0,0};
struct sbool  var1159 = {0,0};
struct sbool  var1160;
struct sbool  var1161;
struct sbool  var1162 = {0,0};
struct sbool  var1163;
struct sbool  var1164 = {0,0};
struct sbool  var1165 = {0,0};
struct sbool  var1166;
struct sbool  var1167 = {0,0};
struct sbool  var1168;
struct sbool  var1169 = {0,0};
struct sbool  var1170;
struct sbool  var1171 = {0,0};
struct sbool  var1172;
struct sbool  var1173;
struct sbool  var1174;
struct sbool  var1175;
struct sbool  var1176;
struct sbool  var1177;
struct sbool  var1178;
struct sbool  var1179;
struct sbool  var1180 = {0,0};
struct sbool  var1181;
struct sbool  var1182 = {0,0};
struct sbool  var1183;
struct sbool  var1184;
struct sbool  var1185;
struct sbool  var1186;
struct sbool  var1187;
struct sbool  var1188;
struct sbool  var1189;
struct sbool  var1190;
struct sbool  var1191 = {0,0};
struct sbool  var1192;
struct sbool  var1193 = {0,0};
struct sbool  var1194;
struct sbool  var1195 = {0,0};
struct sbool  var1196;
struct sbool  var1197;
struct sbool  var1198;
struct sbool  var1199;
struct sbool  var1200;
struct sbool  var1201;
struct sbool  var1202 = {0,0};
struct sbool  var1203;
struct sbool  var1204 = {0,0};
struct sbool  var1205 = {0,0};
struct sbool  var1206 = {0,0};
struct sbool  var1207 = {0,0};
struct sbool  var1208;
struct sbool  var1209;
struct sbool  var1210;
struct sbool  var1211;
struct sbool  var1212;
struct sbool  var1213;
struct sbool  var1214;
struct sbool  var1215;
struct sbool  var1216;
struct sbool  var1217;
struct sbool  var1218;
struct sbool  var1219;
struct sbool  var1220;
struct sbool  var1221;
struct sbool  var1222;
struct sbool  var1223 = {0,0};
struct sbool  var1224 = {0,0};
struct sbool  var1225 = {0,0};
struct sbool  var1226 = {0,0};
struct sbool  var1227;
struct sbool  var1228;
struct sbool  var1229;
struct sbool  var1230;
struct sbool  var1231;
struct sbool  var1232;
struct sbool  var1233;
struct sbool  var1234;
struct sbool  var1235;
struct sbool  var1236;
struct sbool  var1237;
struct sbool  var1238;
struct sbool  var1239;
struct sbool  var1240;
struct slong  var1241 = {0,0};
struct sbool  var1242;
struct sint  var1243;
struct sint  var1244;
struct sbool  var1245;
struct sfloat  var1246;
struct sfloat  var1247;
struct sfloat  var1248;
struct sbool  var1249;
struct sbool  var1250;
struct sbool  var1251;
struct sbool  var1252;
struct sbool  var1253;
struct sbool  var1254 = {0,0};
struct sbool  var1255 = {0,0};
struct sbool  var1256;
struct sbool  var1257;
struct sbool  var1258;
struct sbool  var1259;
struct sbool  var1260;
struct sbool  var1261;
struct sbool  var1262;
struct sbool  var1263;
struct sbool  var1264;
struct sint  var1265;
struct sbool  var1266;
struct schar  var1267;
struct sint  var1268;
struct sbool  var1269;
struct sfloat  var1270 = {0,0};
struct sbool  var1271 = {0,0};
struct sbool  var1272;
struct sbool  var1273 = {0,0};
struct sbool  var1274;
struct sbool  var1275;
struct sbool  var1276;
struct sbool  var1277;
struct sfloat  var1278 = {0,0};
struct schar  var1279;
struct sbool  var1280;
struct sbool  var1281;
struct sbool  var1282;
struct sbool  var1283;
struct sfloat  var1284;
struct sbool  var1285;
struct sbool  var1286;
struct sbool  var1287;
struct sbool  var1288;
struct sbool  var1289;
struct sbool  var1290;
struct sbool  var1291;
struct sbool  var1292;
struct sbool  var1293;
struct sbool  var1294;
struct sbool  var1295;
struct sbool  var1296;
struct sint  var1297;
struct sbool  var1298;
struct schar  var1299;
struct sint  var1300;
struct sbool  var1301;
struct sfloat  var1302 = {0,0};
struct sbool  var1303 = {0,0};
struct sbool  var1304;
struct sbool  var1305 = {0,0};
struct sbool  var1306;
struct sbool  var1307;
struct sbool  var1308;
struct sbool  var1309;
struct sfloat  var1310 = {0,0};
struct schar  var1311;
struct sbool  var1312;
struct sbool  var1313;
struct sbool  var1314;
struct sbool  var1315;
struct sfloat  var1316;
struct sbool  var1317;
struct sbool  var1318;
struct sbool  var1319;
struct sbool  var1320;
struct sbool  var1321;
struct sbool  var1322;
struct sbool  var1323;
struct sbool  var1324;
struct sbool  var1325;
struct sint  var1326;
struct sbool  var1327;
struct schar  var1328;
struct sint  var1329;
struct sbool  var1330;
struct sfloat  var1331 = {0,0};
struct sbool  var1332 = {0,0};
struct sbool  var1333 = {0,0};
struct sbool  var1334;
struct sbool  var1335;
struct sbool  var1336;
struct sbool  var1337;
struct sbool  var1338;
struct sfloat  var1339 = {0,0};
struct schar  var1340;
struct sbool  var1341;
struct sbool  var1342;
struct sbool  var1343;
struct sbool  var1344;
struct sfloat  var1345;
struct sbool  var1346;
struct sbool  var1347;
struct sbool  var1348;
struct sbool  var1349;
struct sbool  var1350;
struct sbool  var1351;
struct sbool  var1352;
struct sbool  var1353;
struct sbool  var1354;
struct sbool  var1355;
struct sbool  var1356;
struct sbool  var1357;
struct sbool  var1358;
struct sint  var1359;
struct sbool  var1360;
struct schar  var1361;
struct sint  var1362;
struct sbool  var1363;
struct sfloat  var1364 = {0,0};
struct sbool  var1365 = {0,0};
struct sbool  var1366 = {0,0};
struct sbool  var1367;
struct sbool  var1368;
struct sbool  var1369;
struct sbool  var1370;
struct sbool  var1371;
struct sfloat  var1372 = {0,0};
struct schar  var1373;
struct sbool  var1374;
struct sbool  var1375;
struct sfloat  var1376;
struct sbool  var1377;
struct sbool  var1378;
struct sbool  var1379;
struct sbool  var1380;
struct sbool  var1381;
struct sbool  var1382;
struct sbool  var1383;
struct sbool  var1384 = {0,0};
struct sbool  var1385;
struct sbool  var1386;
struct sbool  var1387;
struct sbool  var1388;
struct sint  var1389;
struct sbool  var1390;
struct sbool  var1391;
struct sbool  var1392;
struct sbool  var1393 = {0,0};
struct sbool  var1394;
struct sbool  var1395;
struct sbool  var1396;
struct sbool  var1397;
struct sint  var1398;
struct sbool  var1399;
struct sbool  var1400;
struct sbool  var1401;
struct sbool  var1402;
struct sbool  var1403;
struct sbool  var1404;
struct sbool  var1405;
struct sint  var1406;
struct sbool  var1407;
struct schar  var1408;
struct sint  var1409;
struct sbool  var1410;
struct sfloat  var1411 = {0,0};
struct sbool  var1412 = {0,0};
struct sbool  var1413 = {0,0};
struct sbool  var1414;
struct sbool  var1415;
struct sbool  var1416;
struct sbool  var1417;
struct sbool  var1418;
struct sfloat  var1419 = {0,0};
struct schar  var1420;
struct sbool  var1421;
struct sbool  var1422;
struct sfloat  var1423;
struct sbool  var1424;
struct sbool  var1425;
struct sbool  var1426;
struct sbool  var1427;
struct sbool  var1428;
struct sbool  var1429;
struct sbool  var1430;
struct sbool  var1431;
struct schar  var1432;
struct sbool  var1433;
struct sbool  var1434;
struct sbool  var1435;
struct sbool  var1436;
struct sbool  var1437;
struct sbool  var1438;
struct sbool  var1439;
struct sbool  var1440;
struct sbool  var1441;
struct schar  var1442;
struct sbool  var1443;
struct sbool  var1444;
struct sint  var1445;
struct sbool  var1446;
struct schar  var1447;
struct sbool  var1448;
struct sint  var1449;
struct sbool  var1450;
struct sbool  var1451;
struct sfloat  var1452 = {0,0};
struct sbool  var1453 = {0,0};
struct sbool  var1454 = {0,0};
struct sbool  var1455;
struct sbool  var1456;
struct sbool  var1457;
struct sbool  var1458;
struct sbool  var1459;
struct sfloat  var1460 = {0,0};
struct schar  var1461;
struct sbool  var1462;
struct sbool  var1463;
struct sbool  var1464;
struct sbool  var1465;
struct sfloat  var1466;
struct sbool  var1467;
struct sbool  var1468;
struct sbool  var1469;
struct sbool  var1470;
struct sbool  var1471;
struct sbool  var1472;
struct sbool  var1473;
struct sbool  var1474;
struct sbool  var1475;
struct sbool  var1476;
struct sbool  var1477;
struct sbool  var1478;
struct sfloat  var1479;
struct sbool  var1480;
struct sbool  var1481;
struct sbool  var1482;
struct sbool  var1483;
struct sbool  var1484;
struct sbool  var1485;
struct sbool  var1486;
struct sbool  var1487;
struct sbool  var1488 = {0,0};
struct sbool  var1489;
struct sbool  var1490;
struct sbool  var1491;
struct sbool  var1492;
struct sbool  var1493;
struct sbool  var1494;
struct sbool  var1495;
struct sfloat  var1496;
struct sbool  var1497;
struct sbool  var1498;
struct sbool  var1499;
struct sbool  var1500;
struct sbool  var1501;
struct sbool  var1502;
struct sbool  var1503;
struct sbool  var1504;
struct sbool  var1505;
struct sbool  var1506;
struct sbool  var1507;
struct sbool  var1508;
struct sbool  var1509;
struct sbool  var1510 = {0,0};
struct sbool  var1511 = {0,0};
struct sbool  var1512;
struct sbool  var1513;
struct sbool  var1514 = {0,0};
struct sbool  var1515 = {0,0};
struct sbool  var1516 = {0,0};
struct sbool  var1517 = {0,0};
struct sbool  var1518;
struct sbool  var1519;
struct sbool  var1520;
struct sbool  var1521 = {0,0};
struct sbool  var1522 = {0,0};
struct sbool  var1523;
struct sbool  var1524;
struct sbool  var1525;
struct sbool  var1526;
struct sbool  var1527;
struct sbool  var1528;
struct sbool  var1529;
struct sbool  var1530;
struct sbool  var1531;
struct sbool  var1532;
struct sbool  var1533;
struct sint  var1534;
struct sbool  var1535;
struct sbool  var1536;
struct sbool  var1537;
struct sbool  var1538;
struct sbool  var1539;
struct sbool  var1540;
struct sbool  var1541;
struct sbool  var1542;
struct sint  var1543;
struct sbool  var1544;
struct sbool  var1545;
struct sbool  var1546;
struct sbool  var1547;
struct sbool  var1548;
struct sbool  var1549;
struct sbool  var1550;
struct sbool  var1551;
struct sint  var1552;
struct sbool  var1553;
struct sbool  var1554;
struct sbool  var1555;
struct sbool  var1556;
struct sbool  var1557;
struct sbool  var1558;
struct sbool  var1559;
struct sbool  var1560;
struct sint  var1561;
struct sbool  var1562;
struct sbool  var1563;
struct sbool  var1564 = {0,0};
struct sbool  var1565;
struct sbool  var1566;
struct sbool  var1567;
struct sbool  var1568;
struct sbool  var1569;
struct sint  var1570;
struct sbool  var1571;
struct sbool  var1572;
struct sbool  var1573;
struct sbool  var1574;
struct sbool  var1575;
struct sbool  var1576;
struct sbool  var1577;
struct sbool  var1578;
struct sint  var1579;
struct sbool  var1580;
struct sbool  var1581;
struct sbool  var1582;
struct sbool  var1583;
struct sbool  var1584;
struct sbool  var1585;
struct sbool  var1586;
struct sbool  var1587;
struct sint  var1588;
struct sbool  var1589;
struct sbool  var1590;
struct sbool  var1591;
struct sbool  var1592;
struct sbool  var1593 = {0,0};
struct sbool  var1594;
struct sbool  var1595;
struct sbool  var1596;
struct sbool  var1597;
struct sbool  var1598;
struct sbool  var1599;
struct sbool  var1600;
struct sbool  var1601;
struct sbool  var1602;
struct sbool  var1603;
struct sbool  var1604;
struct sbool  var1605;
struct sbool  var1606;
struct sbool  var1607;
struct sbool  var1608;
struct sbool  var1609;
struct sbool  var1610;
struct sbool  var1611;
struct sbool  var1612;
struct sbool  var1613;
struct sbool  var1614;
struct sbool  var1615;
struct sbool  var1616;
struct sbool  var1617;
struct sbool  var1618;
struct sbool  var1619;
struct sbool  var1620;
struct sbool  var1621;
struct sbool  var1622;
struct sbool  var1623;
struct sbool  var1624;
struct sfloat  var1625;
struct sbool  var1626;
struct sbool  var1627;
struct sbool  var1628;
struct sbool  var1629;
struct sbool  var1630;
struct sbool  var1631;
struct sbool  var1632;
struct sbool  var1633;
struct sbool  var1634;
struct sbool  var1635;
struct sbool  var1636;
struct sbool  var1637;
struct sbool  var1638;
struct sbool  var1639;
struct sbool  var1640;
struct sbool  var1641;
struct sbool  var1642;
struct sbool  var1643;
struct sbool  var1644;
struct sbool  var1645;
struct sbool  var1646;
struct sbool  var1647;
struct sbool  var1648;
struct sbool  var1649;
struct sbool  var1650;
struct sbool  var1651;
struct sbool  var1652;
struct sbool  var1653;
struct sbool  var1654;
struct sbool  var1655;
struct sbool  var1656;
struct sbool  var1657;
struct sbool  var1658;
struct sbool  var1659;
struct sfloat  var1660;
struct sfloat  var1661;
struct sbool  var1662;
struct sbool  var1663;
struct sbool  var1664;
struct sbool  var1665;
struct sbool  var1666;
struct sbool  var1667;
struct sbool  var1668;
struct sbool  var1669;
struct sbool  var1670;
struct sbool  var1671;
struct sbool  var1672;
struct sbool  var1673;
struct sbool  var1674;
struct sbool  var1675;
struct sbool  var1676;
struct sbool  var1677;
struct sbool  var1678;
struct sbool  var1679;
struct sbool  var1680;
struct sbool  var1681;
struct sbool  var1682;
struct sbool  var1683;
struct sbool  var1684;
struct sbool  var1685;
struct sbool  var1686;
struct sbool  var1687;
struct sfloat  var1688;
struct sbool  var1689;
struct sbool  var1690;
struct sfloat  var1691;
struct sbool  var1692;
struct sbool  var1693;
struct sfloat  var1694;
struct sbool  var1695;
struct sbool  var1696;
struct sfloat  var1697;
struct sbool  var1698;
struct sbool  var1699;
struct sfloat  var1700;
struct sbool  var1701;
struct sbool  var1702;
struct sfloat  var1703;
struct sbool  var1704;
struct sbool  var1705;
struct sfloat  var1706;
struct sbool  var1707;
struct sbool  var1708;
struct sbool  var1709;
struct sfloat  var1710;
struct sbool  var1711;
struct sbool  var1712;
struct sbool  var1713;
struct slong  vainSLong;
struct sfloat  vainSFloat;
struct sint  vainSInt;
struct sbool  vainSBool;
struct schar  vainSChar;
char  vainSText[] = "";

/* Объявление массивов */
psbool  array_m170_x_2[17] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
psbool  array_m150_x_2[6] = {NULL,NULL,NULL,NULL,NULL,NULL};
psbool  array_m131_x_2[6] = {NULL,NULL,NULL,NULL,NULL,NULL};
psbool  array_m242_x_2[6] = {&var1672,&var1664,&var1678,NULL,NULL,&var1623};
psbool  array_m232_x_2[6] = {&var1673,&var1666,&var1679,NULL,NULL,&var1623};
psbool  array_m255_x_2[6] = {&var1657,NULL,NULL,&var1628,&var1627,&var1626};
psbool  array_m234_x_2[6] = {&var1658,NULL,NULL,&var1631,&var1630,&var1629};
psbool  array_m124_x_2[8] = {&var1690,&var1712,&var1708,&var1705,&var1702,&var1699,&var1693,&var1696};
psbool  array_m795_x_1[6] = {&var564,&var1204,&var1180,&var1166,&var969,&var29};
psbool  array_m1180_x_1[6] = {&var563,&var1184,&var1170,&var1206,&var969,&var52};
psbool  array_m586_x_1[6] = {&var759,&var1068,&var1491,&var1029,&var1450,&var1062};
psbool  array_m585_x_1[6] = {&var759,&var1069,&var1491,&var1029,&var1450,&var1061};
psfloat  array_m2159_a_1[6] = {NULL,NULL,NULL,NULL,NULL,NULL};
psfloat  array_m2159_b_1[6] = {NULL,NULL,NULL,NULL,NULL,NULL};
psfloat  array_m2170_x_1[4] = {NULL,NULL,NULL,NULL};
psfloat  array_m2193_x_1[2] = {NULL,NULL};
psbool  array_m2162_x_1[14] = {&var146,&var119,&var793,&var180,&var182,&var117,&var1613,&var1193,&var1191,&var1624,&var145,&var134,&var130,&var154};
psbool  array_m1_x_1[47] = {&var1153,&var347,&var283,&var2,&var433,&var1360,&var682,NULL,&var596,NULL,&var655,NULL,&var889,NULL,&var709,NULL,&var887,&var1387,NULL,&var340,&var1187,&var1076,&var1074,&var987,&var802,NULL,&var370,&var411,&var1231,&var1541,NULL,&var540,&var531,&var480,NULL,NULL,&var252,&var1227,&var444,&var201,&var1592,&var1550,&var1577,&var908,&var1564,NULL,&var120};
psfloat  array_m1446_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psbool  array_m1400_x_1[5] = {&var540,&var539,&var538,&var537,&var536};
psbool  array_m544_x_1[14] = {&var707,&var713,&var714,&var705,&var706,&var891,&var892,&var872,&var871,&var703,&var701,&var709,&var702,&var174};
psfloat  array_m81_x_1[2] = {NULL,NULL};
psfloat  array_m83_x_1[8] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
psfloat  array_m1054_x_1[2] = {NULL,NULL};
psfloat  array_m1187_x_1[8] = {&var1452,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m803_x_1[8] = {&var1411,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m885_x_1[8] = {&var1302,&var143,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m1287_x_1[8] = {&var1270,&var142,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m486_x_1[8] = {&var1331,&var274,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m162_x_1[8] = {&var1364,&var278,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m324_Tpr_1[10] = {&fRM_6_0,&fRM_126_0,&fRM_246_0,&fRM_366_0,&fRM_486_0,&fRM_606_0,&fRM_726_0,&fRM_846_0,&fRM_966_0,&fRM_1200_0};
pschar  array_m324_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m324_rz_1[10];
psbool  array_m328_x_1[5] = {&var1017,&var1018,&var1019,&var1020,&var1021};
psbool  array_m263_x_1[7] = {&var793,&var176,&var996,&var993,&var182,&var180,&var178};
psfloat  array_m267_Tpr_1[10] = {&fRM_10_0,&fRM_30_0,&fRM_50_0,&fRM_70_0,&fRM_90_0,&fRM_110_0,&fRM_130_0,&fRM_150_0,&fRM_170_0,&fRM_200_0};
pschar  array_m267_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m267_rz_1[10];
psfloat  array_m1389_Tpr_1[6] = {&fRM_0_5,&fRM_3_5,&fRM_6_5,&fRM_9_5,&fRM_12_5,&fRM_15_5};
pschar  array_m1389_type_1[6] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_6_};
pschar  array_m1389_rz_1[6];
psbool  array_m283_x_1[5] = {&var1039,&var1040,&var1041,&var1042,&var1043};
psbool  array_m1164_x_1[6] = {&var1165,&var776,&var1523,&var1173,&var1169,&var192};
psbool  array_m1152_x_1[5] = {&var1073,&var1115,&var1167,&var1171,&var989};
psfloat  array_m1430_x_1[16] = {&var375,&var384,&fRM_0_,&var381,&fRM_0_,&fRM_0_,&fRM_0_,&var378,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&var388};
psbool  array_m1736_x_1[17] = {&var455,&var456,&var462,&var457,&var453,&var454,&var926,&var458,&var459,&var1220,&var460,&var461,&var1212,&var1213,&var1222,&var186,&var187};
psbool  array_m1392_x_1[5] = {&var367,&var504,&var521,&var522,&var397};
psint  array_m302_x_1[3] = {&var1015,&iRM_0_,&var1037};
psint  array_m293_x_1[3] = {&var1014,&iRM_0_,&var1036};
psbool  array_m588_x_1[5] = {&var742,&var1490,&var1257,&var970,&var152};
psbool  array_m1351_x_1[8] = {&var626,&var627,&var628,&var623,&var622,&var621,&var887,&var619};
psbool  array_m1286_x_1[3] = {&var31,&lRM_0_,&var30};
psfloat  array_m1288_Lt_fw_1[1] = {NULL};
psint  array_m1288_Vr_fw_1[1] = {NULL};
psfloat  array_m1288_Lt_bw_1[1] = {NULL};
psint  array_m1288_Vr_bw_1[1] = {NULL};
psfloat  array_m1316_x0_1[60];
psfloat  array_m1316_tim0_1[60];
psbool  array_m954_x_1[8] = {&var641,&var643,&var644,&var636,&var642,&var638,&var889,&var356};
psbool  array_m884_x_1[3] = {&var60,&lRM_0_,&var55};
psfloat  array_m886_Lt_fw_1[1] = {NULL};
psint  array_m886_Vr_fw_1[1] = {NULL};
psfloat  array_m886_Lt_bw_1[1] = {NULL};
psint  array_m886_Vr_bw_1[1] = {NULL};
psfloat  array_m919_x0_1[60];
psfloat  array_m919_tim0_1[60];
psbool  array_m485_x_1[3] = {&var718,&lRM_0_,&var719};
psfloat  array_m488_Lt_fw_1[2] = {NULL,NULL};
psint  array_m488_Vr_fw_1[2] = {NULL,NULL};
psfloat  array_m488_Lt_bw_1[1] = {NULL};
psint  array_m488_Vr_bw_1[1] = {NULL};
psfloat  array_m515_x0_1[150];
psfloat  array_m515_tim0_1[150];
psbool  array_m227_x_1[12] = {&var687,&var689,&var688,&var685,&var683,&var682,&var681,&var895,&var894,&var676,&var679,&var175};
psbool  array_m164_x_1[3] = {&var865,&lRM_0_,&var866};
psfloat  array_m167_Lt_fw_1[2] = {NULL,NULL};
psint  array_m167_Vr_fw_1[2] = {NULL,NULL};
psfloat  array_m167_Lt_bw_1[1] = {NULL};
psint  array_m167_Vr_bw_1[1] = {NULL};
psfloat  array_m196_x0_1[150];
psfloat  array_m196_tim0_1[150];
psbool  array_m859_x_1[10] = {&var653,&var654,&var660,&var661,&var659,&var657,&var656,&var897,&var896,&var655};
psbool  array_m802_x_1[3] = {&var33,&var671,&var32};
psfloat  array_m806_Lt_fw_1[2] = {NULL,NULL};
psint  array_m806_Vr_fw_1[2] = {NULL,NULL};
psfloat  array_m806_Lt_bw_1[1] = {NULL};
psint  array_m806_Vr_bw_1[1] = {NULL};
psfloat  array_m826_x0_1[80];
psfloat  array_m826_tim0_1[80];
psfloat  array_m1570_Lt_fw_1[1] = {&fRM_1000_};
psint  array_m1570_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1570_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1570_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1261_x_1[10] = {&var592,&var593,&var595,&var594,&var596,&var598,&var600,&var597,&var599,&var601};
psbool  array_m145_x_1[5] = {NULL,NULL,NULL,&var912,&var911};
psfloat  array_m1109_Lt_fw_1[1] = {&fRM_2000_};
psint  array_m1109_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1109_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1109_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1190_x_1[3] = {&var65,&var586,&var51};
psfloat  array_m1191_Lt_fw_1[2] = {NULL,NULL};
psint  array_m1191_Vr_fw_1[2] = {NULL,NULL};
psfloat  array_m1191_Lt_bw_1[1] = {NULL};
psint  array_m1191_Vr_bw_1[1] = {NULL};
psfloat  array_m1226_x0_1[80];
psfloat  array_m1226_tim0_1[80];
psfloat  array_m1590_x0_1[20];
psfloat  array_m1590_tim0_1[20];
psbool  array_m1077_x_1[8] = {&var803,&var800,&var801,&var802,&var799,&var798,&var797,&var796};
psbool  array_m589_x_1[18] = {NULL,&var494,&var817,&var496,&var815,&var587,&var722,&var670,&var697,&var717,&var646,&var611,&var873,&var295,&var294,&var577,&var208,&var144};
psfloat  array_m1130_x0_1[20];
psfloat  array_m1130_tim0_1[20];
psbool  array_m429_x_1[7] = {&var918,&var917,&var916,&var915,&var1594,&var907,&var324};
psbool  array_m411_x_1[7] = {&var920,&var1594,&var908,&var921,&var919,&var906,&var90};
psbool  array_m759_x_1[17] = {&var818,&var863,&var862,&var859,&var858,&var855,&var820,&var857,&var825,&var854,&var850,&var852,&var851,&var822,&var816,&var905,&var673};
psbool  array_m131_x_1[21] = {&var696,&var716,&var961,&var669,&var960,&var959,&var1528,&var1537,&var1555,&var1546,&var1582,&var1573,&var433,&var325,&var951,&var952,&var1234,&var1228,&var1392,&var1383,&var1564};

/* описания структур для ф-ий */

/* код алгоблоков */
/* Объявление структур */
_S_and4 far S_and4_106_2 = {&var1709,&var1644,NULL,NULL,&var1614};
_S_lkb far S_lkb_111_2 = {&lRM_1_,&var1642,&var1615};
_S_lkb far S_lkb_107_2 = {&lRM_1_,&var1614,&var1616};
_S_lkb far S_lkb_80_2 = {&lRM_1_,&var1645,&var1617};
_S_lkb far S_lkb_50_2 = {&lRM_1_,&var1650,&var1618};
_S_lkb far S_lkb_83_2 = {&lRM_1_,&var1648,&var1619};
_S_lkb far S_lkb_46_2 = {&lRM_1_,&var1654,&var1620};
_S_lkb far S_lkb_24_2 = {&lRM_1_,&var1652,&var1621};
_S_lkb far S_lkb_20_2 = {&lRM_1_,&var1656,&var1622};
_S_or2 far S_or2_258_2 = {&var1713,&var1662,&var1623};
_S_bol far S_bol_223_2 = {&fRM_0_5,&var1625,&var1624};
_S_fsumo far S_fsumo_222_2 = {&var1661,&var1660,&var1625};
_S_noto far S_noto_251_2 = {NULL,&var1626};
_S_noto far S_noto_250_2 = {NULL,&var1627};
_S_noto far S_noto_249_2 = {NULL,&var1628};
_S_noto far S_noto_231_2 = {NULL,&var1629};
_S_noto far S_noto_230_2 = {NULL,&var1630};
_S_noto far S_noto_229_2 = {NULL,&var1631};
_S_schl24 far S_schl24_149_2 = {NULL,NULL,NULL,NULL,&var1632};
_S_schl24 far S_schl24_143_2 = {NULL,NULL,NULL,NULL,&var1633};
_S_or2 far S_or2_198_2 = {&var1682,&var1683,&var1634};
_S_or2 far S_or2_195_2 = {&var1685,&var1686,&var1635};
_S_and2 far S_and2_213_2 = {&var1670,&var1681,&var1636};
_S_or2 far S_or2_243_2 = {&var1677,&var1676,&var1637};
_S_and4 far S_and4_159_2 = {NULL,NULL,NULL,NULL,&var1638};
_S_or3 far S_or3_158_2 = {&var1638,&var781,&var1632,&var1639};
_S_and4 far S_and4_136_2 = {NULL,NULL,NULL,NULL,&var1640};
_S_or3 far S_or3_135_2 = {&var1640,&var1633,&var781,&var1641};
_S_and3 far S_and3_110_2 = {&var1643,&var1709,NULL,&var1642};
_S_or2 far S_or2_104_2 = {NULL,NULL,&var1643};
_S_or2 far S_or2_103_2 = {NULL,NULL,&var1644};
_S_and3 far S_and3_79_2 = {&var1709,NULL,&var1646,&var1645};
_S_or2 far S_or2_71_2 = {NULL,NULL,&var1646};
_S_or2 far S_or2_74_2 = {NULL,NULL,&var1647};
_S_and3 far S_and3_82_2 = {&var1709,&var1647,NULL,&var1648};
_S_or2 far S_or2_43_2 = {NULL,NULL,&var1649};
_S_and3 far S_and3_49_2 = {&var1709,NULL,&var1649,&var1650};
_S_or2 far S_or2_13_2 = {NULL,NULL,&var1651};
_S_and3 far S_and3_23_2 = {&var1651,&var1709,NULL,&var1652};
_S_or2 far S_or2_42_2 = {NULL,NULL,&var1653};
_S_and3 far S_and3_45_2 = {&var1709,NULL,&var1653,&var1654};
_S_or2 far S_or2_11_2 = {NULL,NULL,&var1655};
_S_and3 far S_and3_19_2 = {&var1709,NULL,&var1655,&var1656};
_S_and2 far S_and2_254_2 = {NULL,&var1634,&var1657};
_S_and2 far S_and2_233_2 = {NULL,&var1635,&var1658};
_S_and2 far S_and2_219_2 = {&var1671,&var1680,&var1659};
_S_scalzz far S_scalzz_187_2 = {NULL,&iRM_819_,&iRM_4095_,NULL,NULL,&var1660,NULL};
_S_scalzz far S_scalzz_185_2 = {NULL,&iRM_819_,&iRM_4095_,NULL,NULL,&var1661,NULL};
_S_noto far S_noto_171_2 = {&var1663,&var1662};
_S_andn far S_andn_170_2 = {array_m170_x_2,&iRM_17_,&var1663};
_S_noto far S_noto_153_2 = {&var1665,&var1664};
_S_andn far S_andn_150_2 = {array_m150_x_2,&iRM_6_,&var1665};
_S_noto far S_noto_134_2 = {&var1667,&var1666};
_S_andn far S_andn_131_2 = {array_m131_x_2,&iRM_6_,&var1667};
_S_noto far S_noto_253_2 = {&var1676,&var1668};
_S_noto far S_noto_235_2 = {&var1677,&var1669};
_S_noto far S_noto_212_2 = {&var1685,&var1670};
_S_noto far S_noto_220_2 = {&var1682,&var1671};
_S_noto far S_noto_157_2 = {&var1639,&var1672};
_S_noto far S_noto_141_2 = {&var1641,&var1673};
_S_noto far S_noto_256_2 = {&var1678,&var1674};
_S_noto far S_noto_240_2 = {&var1679,&var1675};
_S_ornc far S_ornc_242_2 = {array_m242_x_2,&iRM_6_,&var1676,&vainSChar};
_S_ornc far S_ornc_232_2 = {array_m232_x_2,&iRM_6_,&var1677,&vainSChar};
_S_ornc far S_ornc_255_2 = {array_m255_x_2,&iRM_6_,&var1678,&vainSChar};
_S_ornc far S_ornc_234_2 = {array_m234_x_2,&iRM_6_,&var1679,&vainSChar};
_S_tprg far S_tprg_214_2 = {&var1660,NULL,NULL,NULL,NULL,&var1680,NULL};
_S_tprg far S_tprg_210_2 = {&var1661,NULL,NULL,NULL,NULL,&var1681,NULL};
_S_geterr far S_geterr_191_2 = {&var1660,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1682};
_S_drg far S_drg_199_2 = {&var1660,&lRM_1_,&lRM_0_,NULL,NULL,&var1683,NULL};
_S_drg far S_drg_204_2 = {&var1660,&lRM_1_,&lRM_0_,NULL,NULL,&var1684,NULL};
_S_geterr far S_geterr_188_2 = {&var1661,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1685};
_S_drg far S_drg_189_2 = {&var1661,&lRM_1_,&lRM_0_,NULL,NULL,&var1686,NULL};
_S_drg far S_drg_196_2 = {&var1661,&lRM_1_,&lRM_0_,NULL,NULL,&var1687,NULL};
_S_enctkb far S_enctkb_16_2 = {&var1621,&fRM_0_0,NULL,NULL,NULL,NULL,&fRM_100_0,&dRM_0_,&var1688,&var1689,&var1690,NULL,NULL,NULL};
_S_enctkb far S_enctkb_108_2 = {&var1616,&fRM_390_,NULL,NULL,NULL,NULL,&fRM_1500_0,&dRM_0_,&var1691,&var1692,&var1693,NULL,NULL,NULL};
_S_enctkb far S_enctkb_112_2 = {&var1615,&fRM_390_0,NULL,NULL,NULL,NULL,&fRM_1500_0,&dRM_0_,&var1694,&var1695,&var1696,NULL,NULL,NULL};
_S_enctkb far S_enctkb_75_2 = {&var1617,&fRM_0_,NULL,NULL,NULL,NULL,&fRM_0_0,&dRM_0_,&var1697,&var1698,&var1699,NULL,NULL,NULL};
_S_enctkb far S_enctkb_77_2 = {&var1619,&fRM_0_0,NULL,NULL,NULL,NULL,&fRM_0_0,&dRM_0_,&var1700,&var1701,&var1702,NULL,NULL,NULL};
_S_enctkb far S_enctkb_47_2 = {&var1620,&fRM_0_0,NULL,NULL,NULL,NULL,&fRM_100_0,&dRM_0_,&var1703,&var1704,&var1705,NULL,NULL,NULL};
_S_enctkb far S_enctkb_51_2 = {&var1618,&fRM_0_0,NULL,NULL,NULL,NULL,&fRM_100_0,&dRM_0_,&var1706,&var1707,&var1708,NULL,NULL,NULL};
_S_equz_p far S_equz_p_18_2 = {NULL,&iRM_4_,&var1709};
_S_enctkb far S_enctkb_21_2 = {&var1622,&fRM_0_0,NULL,NULL,NULL,NULL,&fRM_100_0,&dRM_0_,&var1710,&var1711,&var1712,NULL,NULL,NULL};
_S_ornc far S_ornc_124_2 = {array_m124_x_2,&iRM_8_,&var1713,&vainSChar};
_S_regch far S_regch_124_1 = {NULL,&var867,&var1};
_S_or2 far S_or2_127_1 = {&var3,&var1,&var2};
_S_or2 far S_or2_126_1 = {NULL,NULL,&var3};
_S_and3 far S_and3_1384_1 = {NULL,&var926,&var7,&var4};
_S_and2 far S_and2_722_1 = {NULL,&var7,&var5};
_S_and2 far S_and2_719_1 = {NULL,&var7,&var6};
_S_noto far S_noto_106_1 = {&var1604,&var7};
_S_and2 far S_and2_104_1 = {NULL,&var7,&var8};
_S_noto far S_noto_2101_1 = {NULL,&var9};
_S_noto far S_noto_2127_1 = {NULL,&var10};
_S_and2 far S_and2_2028_1 = {&var429,&var1153,&var11};
_S_or3 far S_or3_2023_1 = {&var428,&var120,&var56,&var12};
_S_and2 far S_and2_2012_1 = {&var425,&var1153,&var13};
_S_or3 far S_or3_2009_1 = {&var120,&var426,&var36,&var14};
_S_and3 far S_and3_2085_1 = {&var1174,&var252,NULL,&var15};
_S_and3 far S_and3_2111_1 = {&var1174,&var253,NULL,&var16};
_S_or2 far S_or2_1449_1 = {&var1245,&var1174,&var17};
_S_or2 far S_or2_1418_1 = {&var1098,&var1174,&var18};
_S_rs far S_rs_2094_1 = {&var15,&var22,&var19,&vainSBool,NULL};
_S_rs far S_rs_2078_1 = {&var15,&var41,&var20,&vainSBool,NULL};
_S_noto far S_noto_2098_1 = {NULL,&var21};
_S_and2 far S_and2_2084_1 = {&var21,&var20,&var22};
_S_rs far S_rs_2120_1 = {&var16,&var25,&var23,&vainSBool,NULL};
_S_noto far S_noto_2124_1 = {NULL,&var24};
_S_and2 far S_and2_2110_1 = {&var26,&var24,&var25};
_S_rs far S_rs_2104_1 = {&var16,&var62,&var26,&vainSBool,NULL};
_S_and4 far S_and4_1339_1 = {&var926,&var1174,&var212,&var1219,&var27};
_S_and4 far S_and4_942_1 = {&var926,&var1174,&var212,&var1219,&var28};
_S_rs far S_rs_2097_1 = {&var194,&var34,&var29,&vainSBool,NULL};
_S_or4 far S_or4_1276_1 = {&var562,&var237,&var965,&var36,&var30};
_S_or4 far S_or4_1285_1 = {&var109,&var241,&var738,&var43,&var31};
_S_orn far S_orn_795_1 = {array_m795_x_1,&iRM_6_,&var32};
_S_or3 far S_or3_807_1 = {&var757,&var1168,&var47,&var33};
_S_and2 far S_and2_2087_1 = {&var201,&var35,&var34};
_S_rs far S_rs_2080_1 = {&var34,&var37,&var35,&vainSBool,NULL};
_S_rs far S_rs_2096_1 = {&var201,&var37,&var36,&vainSBool,NULL};
_S_and2 far S_and2_2086_1 = {&var38,&var9,&var37};
_S_rs far S_rs_2079_1 = {&var37,&var15,&var38,&vainSBool,NULL};
_S_rs far S_rs_2077_1 = {&var48,&var44,&var39,&vainSBool,NULL};
_S_rs far S_rs_2076_1 = {&var42,&var45,&var40,&vainSBool,NULL};
_S_and2 far S_and2_2083_1 = {&var201,&var39,&var41};
_S_or2 far S_or2_2091_1 = {&var252,&var201,&var42};
_S_rs far S_rs_2090_1 = {&var42,&var44,&var43,&vainSBool,NULL};
_S_and2 far S_and2_2082_1 = {&var40,&var194,&var44};
_S_and2 far S_and2_2081_1 = {&var255,&var1174,&var45};
_S_or2 far S_or2_2089_1 = {&var252,&var194,&var46};
_S_rs far S_rs_2088_1 = {&var46,&var45,&var47,&vainSBool,NULL};
_S_or2 far S_or2_2093_1 = {&var21,&var252,&var48};
_S_rs far S_rs_2095_1 = {&var9,&var15,&var49,&vainSBool,NULL};
_S_rs far S_rs_2092_1 = {&var48,&var41,&var50,&vainSBool,NULL};
_S_orn far S_orn_1180_1 = {array_m1180_x_1,&iRM_6_,&var51};
_S_rs far S_rs_2123_1 = {&var194,&var53,&var52,&vainSBool,NULL};
_S_and2 far S_and2_2113_1 = {&var201,&var54,&var53};
_S_rs far S_rs_2106_1 = {&var53,&var57,&var54,&vainSBool,NULL};
_S_or4 far S_or4_874_1 = {&var561,&var242,&var965,&var56,&var55};
_S_rs far S_rs_2122_1 = {&var201,&var57,&var56,&vainSBool,NULL};
_S_and2 far S_and2_2112_1 = {&var58,&var10,&var57};
_S_rs far S_rs_2105_1 = {&var57,&var16,&var58,&vainSBool,NULL};
_S_rs far S_rs_2103_1 = {&var466,&var66,&var59,&vainSBool,NULL};
_S_or4 far S_or4_883_1 = {&var1164,&var109,&var748,&var64,&var60};
_S_rs far S_rs_2102_1 = {&var63,&var67,&var61,&vainSBool,NULL};
_S_and2 far S_and2_2109_1 = {&var201,&var59,&var62};
_S_or2 far S_or2_2117_1 = {&var201,&var253,&var63};
_S_rs far S_rs_2116_1 = {&var63,&var66,&var64,&vainSBool,NULL};
_S_or3 far S_or3_1192_1 = {&var756,&var1172,&var69,&var65};
_S_and2 far S_and2_2108_1 = {&var61,&var194,&var66};
_S_and2 far S_and2_2107_1 = {&var256,&var1174,&var67};
_S_or2 far S_or2_2115_1 = {&var194,&var253,&var68};
_S_rs far S_rs_2114_1 = {&var68,&var67,&var69,&vainSBool,NULL};
_S_or2 far S_or2_1995_1 = {&var111,&var997,&var70};
_S_ovbs far S_ovbs_1997_1 = {&var170,&fRM_2_0,&var71,NULL};
_S_or2 far S_or2_1998_1 = {&var1183,&var71,&var72};
_S_ovbs far S_ovbs_1976_1 = {&var171,&fRM_2_0,&var73,NULL};
_S_or2 far S_or2_1974_1 = {&var112,&var998,&var74};
_S_or2 far S_or2_1977_1 = {&var1203,&var73,&var75};
_S_noto far S_noto_1644_1 = {NULL,&var76};
_S_noto far S_noto_1638_1 = {NULL,&var77};
_S_and2 far S_and2_2048_1 = {NULL,&var430,&var78};
_S_or5 far S_or5_2051_1 = {&var619,&var1613,&var95,&var49,&var78,&var79};
_S_or5 far S_or5_2050_1 = {&var356,&var1162,&var432,&var1613,NULL,&var80};
_S_and2 far S_and2_2025_1 = {NULL,&var431,&var81};
_S_nocnm far S_nocnm_1689_1 = {NULL,NULL,&var82,&var83,&var84,NULL,NULL,NULL,NULL};
_S_nocnm far S_nocnm_1686_1 = {NULL,NULL,&var85,&var86,&var87,NULL,NULL,NULL,NULL};
_S_or5 far S_or5_1945_1 = {&var961,&var669,NULL,&var960,&var959,&var88};
_S_or4 far S_or4_1921_1 = {NULL,NULL,&var696,&var716,&var89};
_S_and3 far S_and3_407_1 = {NULL,NULL,&var1586,&var90};
_S_and2 far S_and2_2014_1 = {&var424,&var120,&var91};
_S_and2 far S_and2_2022_1 = {&var427,&var120,&var92};
_S_or4 far S_or4_974_1 = {&var1292,&var631,&var630,&var633,&var93};
_S_or4 far S_or4_1371_1 = {&var1260,&var612,&var613,&var616,&var94};
_S_and2 far S_and2_2052_1 = {&var345,&var1153,&var95};
_S_and2 far S_and2_2037_1 = {&var430,&var1613,&var96};
_S_and2 far S_and2_2026_1 = {&var431,&var1613,&var97};
_S_or2 far S_or2_546_1 = {NULL,NULL,&var98};
_S_or2 far S_or2_229_1 = {NULL,NULL,&var99};
_S_or2 far S_or2_1108_1 = {NULL,NULL,&var100};
_S_or2 far S_or2_1103_1 = {NULL,NULL,&var101};
_S_or2 far S_or2_348_1 = {NULL,NULL,&var102};
_S_or2 far S_or2_365_1 = {NULL,NULL,&var103};
_S_or2 far S_or2_1062_1 = {&var968,NULL,&var104};
_S_or2 far S_or2_1065_1 = {&var966,NULL,&var105};
_S_or2 far S_or2_1068_1 = {&var964,NULL,&var106};
_S_or2 far S_or2_1071_1 = {&var962,NULL,&var107};
_S_noto far S_noto_2150_1 = {&var1613,&var108};
_S_zzfs far S_zzfs_2138_1 = {&var126,&fRM_0_5,&var109,NULL,NULL};
_S_or2 far S_or2_2173_1 = {&var306,&var970,&var110};
_S_andn far S_andn_586_1 = {array_m586_x_1,&iRM_6_,&var111};
_S_andn far S_andn_585_1 = {array_m585_x_1,&iRM_6_,&var112};
_S_or2 far S_or2_2190_1 = {&var646,&var611,&var113};
_S_noto far S_noto_2135_1 = {&var996,&var114};
_S_noto far S_noto_2134_1 = {&var993,&var115};
_S_zpfs far S_zpfs_2143_1 = {&var114,&fRM_30_0,&var116,NULL,NULL};
_S_noto far S_noto_2148_1 = {&var116,&var117};
_S_zpfs far S_zpfs_2142_1 = {&var115,&fRM_30_0,&var118,NULL,NULL};
_S_noto far S_noto_2147_1 = {&var118,&var119};
_S_and3 far S_and3_2140_1 = {&var159,&var139,&lRM_1_,&var120};
_S_and2 far S_and2_903_1 = {&var1318,&var122,&var121};
_S_noto far S_noto_891_1 = {&var109,&var122};
_S_and2 far S_and2_1302_1 = {&var1286,&var124,&var123};
_S_noto far S_noto_1299_1 = {&var109,&var124};
_S_or2 far S_or2_2183_1 = {&var135,&var136,&var125};
_S_and2 far S_and2_2137_1 = {&var127,&var120,&var126};
_S_abs_subf far S_abs_subf_2130_1 = {&var1700,&var160,NULL,&vainSFloat,&var127};
_S_and2 far S_and2_2185_1 = {&var120,&var135,&var128};
_S_or4 far S_or4_1946_1 = {&var88,&var774,&var884,&var128,&var129};
_S_noto far S_noto_2189_1 = {&var113,&var130};
_S_or2 far S_or2_2164_1 = {&var153,&var164,&var131};
_S_inf far S_inf_2159_1 = {&var162,array_m2159_a_1,array_m2159_b_1,&iRM_6_,&var132,&vainSInt};
_S_or3 far S_or3_2188_1 = {&var149,&var156,&var157,&var133};
_S_noto far S_noto_2187_1 = {&var133,&var134};
_S_noto far S_noto_2184_1 = {&var159,&var135};
_S_ovbs far S_ovbs_2179_1 = {&var138,&fRM_15_0,&var136,NULL};
_S_zpfs far S_zpfs_2177_1 = {&var139,&fRM_10_0,&var137,NULL,NULL};
_S_and2 far S_and2_2178_1 = {&var137,NULL,&var138};
_S_rs far S_rs_2182_1 = {&var125,NULL,&var139,&vainSBool,NULL};
_S_rs far S_rs_2149_1 = {&var153,&var120,&var140,&vainSBool,NULL};
_S_and3 far S_and3_2156_1 = {&var155,&var108,&var140,&var141};
_S_ml far S_ml_1280_1 = {&var160,&var266,&var109,&var142};
_S_ml far S_ml_878_1 = {&var160,&var270,&var109,&var143};
_S_and2 far S_and2_2203_1 = {&var120,&var283,&var144};
_S_noto far S_noto_2169_1 = {&var110,&var145};
_S_noto far S_noto_2154_1 = {&var1257,&var146};
_S_sr far S_sr_2170_1 = {array_m2170_x_1,&iRM_4_,&var147};
_S_sr far S_sr_2193_1 = {array_m2193_x_1,&iRM_2_,&var148};
_S_and2 far S_and2_2207_1 = {&var150,&var120,&var149};
_S_abs_subf far S_abs_subf_2202_1 = {NULL,NULL,&fRM_0_01,&vainSFloat,&var150};
_S_fsumo far S_fsumo_79_1 = {&var946,NULL,&var151};
_S_or3 far S_or3_125_1 = {&var89,&var2,&var131,&var152};
_S_ovbs far S_ovbs_2157_1 = {&var141,&fRM_1_0,&var153,NULL};
_S_noto far S_noto_2163_1 = {&var131,&var154};
_S_rs far S_rs_2155_1 = {&var153,&var1613,&var155,&vainSBool,NULL};
_S_and2 far S_and2_2206_1 = {&var164,&var120,&var156};
_S_and2 far S_and2_2205_1 = {&var158,&var120,&var157};
_S_bol far S_bol_2195_1 = {NULL,&var148,&var158};
_S_andn far S_andn_2162_1 = {array_m2162_x_1,&iRM_14_,&var159};
_S_irm far S_irm_2141_1 = {&var946,&var944,NULL,&var1700,&var148,&var147,&var120,NULL,NULL,NULL,NULL,&var132,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var160,&var161,&var162,&var163,&var164,&var165,&var166,&var167};
_S_noto far S_noto_2003_1 = {&var294,&var168};
_S_noto far S_noto_1973_1 = {&var295,&var169};
_S_and4 far S_and4_1996_1 = {&var317,&var70,&var287,&var168,&var170};
_S_and4 far S_and4_1975_1 = {&var318,&var74,&var287,&var169,&var171};
_S_zpfs far S_zpfs_1991_1 = {&var301,&fRM_210_0,&var172,NULL,NULL};
_S_zpfs far S_zpfs_1983_1 = {&var302,&fRM_210_0,&var173,NULL,NULL};
_S_and2 far S_and2_549_1 = {&var1333,&var350,&var174};
_S_and2 far S_and2_232_1 = {&var350,&var1366,&var175};
_S_noto far S_noto_1539_1 = {&var177,&var176};
_S_abs_subf far S_abs_subf_1531_1 = {&var1697,&var266,NULL,&vainSFloat,&var177};
_S_noto far S_noto_1519_1 = {&var179,&var178};
_S_abs_subf far S_abs_subf_1508_1 = {&var270,&var1700,NULL,&vainSFloat,&var179};
_S_noto far S_noto_1534_1 = {&var181,&var180};
_S_abs_subf far S_abs_subf_1528_1 = {&var274,&var1710,NULL,&vainSFloat,&var181};
_S_noto far S_noto_1514_1 = {&var183,&var182};
_S_abs_subf far S_abs_subf_1507_1 = {&var278,&var1688,NULL,&vainSFloat,&var183};
_S_bol far S_bol_1298_1 = {&var1697,NULL,&var184};
_S_bol far S_bol_899_1 = {&var1700,NULL,&var185};
_S_noto far S_noto_1748_1 = {&var190,&var186};
_S_noto far S_noto_1737_1 = {&var188,&var187};
_S_and3 far S_and3_1730_1 = {&var878,&var189,&var1174,&var188};
_S_bol far S_bol_1722_1 = {&fRM_55_0,&var266,&var189};
_S_and3 far S_and3_1749_1 = {&var191,&var877,&var1174,&var190};
_S_bol far S_bol_1758_1 = {&fRM_55_0,&var270,&var191};
_S_and4 far S_and4_45_1 = {&var1604,&var876,&var1055,&var1153,&var192};
_S_noto far S_noto_1214_1 = {&var926,&var193};
_S_and2 far S_and2_1218_1 = {&var1433,&var926,&var194};
_S_and2 far S_and2_1215_1 = {&var1433,&var193,&var195};
_S_noto far S_noto_1160_1 = {&var926,&var196};
_S_and2 far S_and2_1168_1 = {&var926,&var1507,&var197};
_S_and2 far S_and2_1161_1 = {&var1507,&var196,&var198};
_S_noto far S_noto_908_1 = {&var926,&var199};
_S_and2 far S_and2_909_1 = {&var199,&var1289,&var200};
_S_and2 far S_and2_905_1 = {&var1289,&var926,&var201};
_S_noto far S_noto_461_1 = {&var926,&var202};
_S_and2 far S_and2_462_1 = {&var202,&var1382,&var203};
_S_and2 far S_and2_464_1 = {&var1382,&var926,&var204};
_S_noto far S_noto_188_1 = {&var926,&var205};
_S_and2 far S_and2_189_1 = {&var205,&var1352,&var206};
_S_and2 far S_and2_193_1 = {&var926,&var1352,&var207};
_S_and2 far S_and2_120_1 = {&var210,&var339,&var208};
_S_and2 far S_and2_121_1 = {&var926,&var339,&var209};
_S_noto far S_noto_115_1 = {&var926,&var210};
_S_and2 far S_and2_116_1 = {&var210,&var338,&var211};
_S_and2 far S_and2_117_1 = {&var926,&var338,&var212};
_S_and2 far S_and2_1609_1 = {&var252,&var1178,&var213};
_S_and2 far S_and2_1608_1 = {&var255,&var1178,&var214};
_S_and2 far S_and2_1607_1 = {&var253,&var1178,&var215};
_S_and2 far S_and2_1606_1 = {&var1178,&var256,&var216};
_S_and2 far S_and2_1605_1 = {&var487,&var254,&var217};
_S_and2 far S_and2_1604_1 = {&var487,&var257,&var218};
_S_and2 far S_and2_1603_1 = {&var488,&var254,&var219};
_S_and2 far S_and2_1602_1 = {&var488,&var257,&var220};
_S_and2 far S_and2_1633_1 = {&var76,&var1131,&var221};
_S_and2 far S_and2_1632_1 = {&var252,&var1179,&var222};
_S_and2 far S_and2_1631_1 = {&var1132,&var194,&var223};
_S_and2 far S_and2_1630_1 = {&var1179,&var255,&var224};
_S_and2 far S_and2_1629_1 = {&var77,&var1133,&var225};
_S_and2 far S_and2_1628_1 = {&var1179,&var253,&var226};
_S_and2 far S_and2_1627_1 = {&var1134,&var194,&var227};
_S_and2 far S_and2_1626_1 = {&var1179,&var256,&var228};
_S_and2 far S_and2_1659_1 = {&var194,&var1135,&var229};
_S_and2 far S_and2_1658_1 = {&var252,&var1177,&var230};
_S_and2 far S_and2_1657_1 = {&var1136,&var197,&var231};
_S_and2 far S_and2_1656_1 = {&var255,&var1177,&var232};
_S_and2 far S_and2_1655_1 = {&var194,&var1137,&var233};
_S_and2 far S_and2_1654_1 = {&var253,&var1177,&var234};
_S_and2 far S_and2_1653_1 = {&var1138,&var197,&var235};
_S_and2 far S_and2_1652_1 = {&var256,&var1177,&var236};
_S_rs far S_rs_1682_1 = {&var201,&var238,&var237,&vainSBool,NULL};
_S_and2 far S_and2_1675_1 = {&var1175,&var252,&var238};
_S_and2 far S_and2_1674_1 = {&var1175,&var255,&var239};
_S_or2 far S_or2_1681_1 = {&var201,&var252,&var240};
_S_rs far S_rs_1680_1 = {&var240,&var239,&var241,&vainSBool,NULL};
_S_rs far S_rs_1679_1 = {&var201,&var243,&var242,&vainSBool,NULL};
_S_and2 far S_and2_1673_1 = {&var253,&var1175,&var243};
_S_and2 far S_and2_1672_1 = {&var1175,&var256,&var244};
_S_and2 far S_and2_1701_1 = {&var254,&var1606,&var245};
_S_rs far S_rs_1710_1 = {&var204,&var245,&var246,&vainSBool,NULL};
_S_and2 far S_and2_1700_1 = {&var1606,&var257,&var247};
_S_and2 far S_and2_1699_1 = {&var252,&var1160,&var248};
_S_and2 far S_and2_1698_1 = {&var1160,&var255,&var249};
_S_and2 far S_and2_1697_1 = {&var253,&var1160,&var250};
_S_and2 far S_and2_1696_1 = {&var1160,&var256,&var251};
_S_and2 far S_and2_1712_1 = {&var878,&var254,&var252};
_S_and2 far S_and2_1695_1 = {&var877,&var254,&var253};
_S_and2 far S_and2_1714_1 = {&var209,&var1219,&var254};
_S_and2 far S_and2_1711_1 = {&var257,&var878,&var255};
_S_and2 far S_and2_1694_1 = {&var257,&var877,&var256};
_S_and2 far S_and2_1713_1 = {&var212,&var1219,&var257};
_S_zpfs far S_zpfs_739_1 = {&var842,&fRM_3_,&var258,NULL,NULL};
_S_or4 far S_or4_1549_1 = {&var472,&var473,&var474,&var476,&var259};
_S_or5 far S_or5_1540_1 = {&var480,&var479,&var478,&var477,&var259,&var260};
_S_andn far S_andn_1_1 = {array_m1_x_1,&iRM_47_,&vainSBool};
_S_or2 far S_or2_1521_1 = {&var263,&var264,&var261};
_S_ml far S_ml_1506_1 = {&fRM_1500_0,NULL,&var261,&var262};
_S_bol far S_bol_1517_1 = {NULL,&fRM_1500_0001,&var263};
_S_bol far S_bol_1523_1 = {&fRM_389_99,NULL,&var264};
_S_or2 far S_or2_1536_1 = {&var267,&var268,&var265};
_S_ml far S_ml_1527_1 = {&fRM_0_0,NULL,&var265,&var266};
_S_bol far S_bol_1530_1 = {NULL,&fRM_160_00001,&var267};
_S_bol far S_bol_1538_1 = {&fRM_0_0001,NULL,&var268};
_S_or2 far S_or2_1516_1 = {&var271,&var272,&var269};
_S_ml far S_ml_1505_1 = {&fRM_0_0,NULL,&var269,&var270};
_S_bol far S_bol_1511_1 = {NULL,&fRM_160_0001,&var271};
_S_bol far S_bol_1518_1 = {&fRM_0_0001,NULL,&var272};
_S_or2 far S_or2_1533_1 = {&var275,&var276,&var273};
_S_ml far S_ml_1525_1 = {&fRM_100_0,NULL,&var273,&var274};
_S_bol far S_bol_1529_1 = {NULL,&fRM_100_0001,&var275};
_S_bol far S_bol_1537_1 = {&fRM_0_0001,NULL,&var276};
_S_or2 far S_or2_1513_1 = {&var279,&var280,&var277};
_S_ml far S_ml_1503_1 = {&fRM_100_0,NULL,&var277,&var278};
_S_bol far S_bol_1510_1 = {NULL,&fRM_100_0001,&var279};
_S_bol far S_bol_1522_1 = {&fRM_0_0001,NULL,&var280};
_S_and2 far S_and2_101_1 = {&var8,&var102,&var281};
_S_noto far S_noto_102_1 = {&var102,&var282};
_S_and2 far S_and2_105_1 = {&var8,&var282,&var283};
_S_and2 far S_and2_1962_1 = {&var285,&var286,&var284};
_S_or3 far S_or3_1961_1 = {&var1181,&var417,&var129,&var285};
_S_noto far S_noto_1999_1 = {&var72,&var286};
_S_noto far S_noto_1988_1 = {&var288,&var287};
_S_ovbs far S_ovbs_1987_1 = {&var1067,&fRM_2_0,&var288,NULL};
_S_noto far S_noto_1978_1 = {&var75,&var289};
_S_and2 far S_and2_1948_1 = {&var291,&var289,&var290};
_S_or3 far S_or3_1947_1 = {&var129,&var1185,&var417,&var291};
_S_noto far S_noto_1993_1 = {&var299,&var292};
_S_and2 far S_and2_1994_1 = {&var1153,&var292,&var293};
_S_and2 far S_and2_2002_1 = {&var293,&var70,&var294};
_S_and2 far S_and2_1981_1 = {&var296,&var74,&var295};
_S_and2 far S_and2_1986_1 = {&var297,&var1153,&var296};
_S_noto far S_noto_1985_1 = {&var869,&var297};
_S_noto far S_noto_2001_1 = {&var301,&var298};
_S_or2 far S_or2_1992_1 = {&var172,&var298,&var299};
_S_noto far S_noto_1980_1 = {&var302,&var300};
_S_rs far S_rs_1990_1 = {&var172,&var307,&var301,&vainSBool,NULL};
_S_rs far S_rs_1982_1 = {&var173,&var308,&var302,&vainSBool,NULL};
_S_and2 far S_and2_1971_1 = {&var305,&var312,&var303};
_S_and2 far S_and2_1959_1 = {&var305,&var309,&var304};
_S_noto far S_noto_1953_1 = {&var306,&var305};
_S_ovbs far S_ovbs_1952_1 = {&var129,&fRM_10_0,&var306,NULL};
_S_ovbs far S_ovbs_1963_1 = {&var284,&fRM_2_0,&var307,NULL};
_S_ovbs far S_ovbs_1949_1 = {&var290,&fRM_2_0,&var308,NULL};
_S_or2 far S_or2_1958_1 = {&var340,&var931,&var309};
_S_or2 far S_or2_1954_1 = {&var341,&var290,&var310};
_S_or2 far S_or2_1966_1 = {&var341,&var284,&var311};
_S_or2 far S_or2_1970_1 = {&var340,&var928,&var312};
_S_rs far S_rs_1955_1 = {&var304,&var310,&var313,&vainSBool,NULL};
_S_noto far S_noto_1968_1 = {&var315,&var314};
_S_rs far S_rs_1967_1 = {&var303,&var311,&var315,&vainSBool,NULL};
_S_noto far S_noto_1956_1 = {&var313,&var316};
_S_noto far S_noto_1964_1 = {&var307,&var317};
_S_noto far S_noto_1950_1 = {&var308,&var318};
_S_and2 far S_and2_1943_1 = {&var321,&var423,&var319};
_S_and2 far S_and2_1932_1 = {&var321,&var420,&var320};
_S_noto far S_noto_1926_1 = {&var322,&var321};
_S_ovbs far S_ovbs_1925_1 = {&var89,&fRM_3_0,&var322,NULL};
_S_or2 far S_or2_1461_1 = {&var1101,&var347,&var323};
_S_and2 far S_and2_432_1 = {&var1578,&var1520,&var324};
_S_and2 far S_and2_1811_1 = {&var1126,NULL,&var325};
_S_and2 far S_and2_443_1 = {&var877,&var723,&var326};
_S_and2 far S_and2_435_1 = {&var724,&var877,&var327};
_S_and2 far S_and2_472_1 = {&var723,&var878,&var328};
_S_and2 far S_and2_468_1 = {&var724,&var878,&var329};
_S_or2 far S_or2_359_1 = {&var1591,&var849,&var330};
_S_or2 far S_or2_355_1 = {&var1591,&var848,&var331};
_S_ovbs far S_ovbs_51_1 = {&var1603,&fRM_15_0,&var332,NULL};
_S_ovbs far S_ovbs_336_1 = {&var1074,&fRM_0_02,&var333,NULL};
_S_ovbs far S_ovbs_291_1 = {&var1076,&fRM_0_02,&var334,NULL};
_S_ovbs far S_ovbs_740_1 = {&var258,&fRM_0_2,&var335,NULL};
_S_ovbs far S_ovbs_1405_1 = {NULL,&fRM_10_0,&var336,NULL};
_S_ovbs far S_ovbs_112_1 = {NULL,&fRM_0_15,&var337,NULL};
_S_ovbs far S_ovbs_114_1 = {&var283,&fRM_0_02,&var338,NULL};
_S_ovbs far S_ovbs_119_1 = {NULL,&fRM_0_02,&var339,NULL};
_S_ovbs far S_ovbs_21_1 = {&var1153,&fRM_3_0,&var340,NULL};
_S_ovbs far S_ovbs_13_1 = {&var926,&fRM_3_0,&var341,NULL};
_S_ovbs far S_ovbs_1934_1 = {&var89,&fRM_2_0,&var342,NULL};
_S_ovbs far S_ovbs_1922_1 = {&var89,&fRM_2_0,&var343,NULL};
_S_ovbs far S_ovbs_2030_1 = {&var1162,&fRM_2_0,&var344,NULL};
_S_ovbs far S_ovbs_2034_1 = {&var49,&fRM_2_0,&var345,NULL};
_S_ovbs far S_ovbs_1847_1 = {&var358,&fRM_0_01,&var346,NULL};
_S_ovbs far S_ovbs_76_1 = {NULL,&fRM_10_0,&var347,NULL};
_S_zpfs far S_zpfs_305_1 = {&var780,&fRM_10_0,&var348,NULL,NULL};
_S_or2 far S_or2_1021_1 = {&var987,&var550,&var349};
_S_or2 far S_or2_233_1 = {NULL,NULL,&var350};
_S_or2 far S_or2_248_1 = {&var675,&var943,&var351};
_S_or5 far S_or5_147_1 = {NULL,NULL,NULL,&var913,&var914,&var352};
_S_and2 far S_and2_1018_1 = {&var1428,&var1058,&var353};
_S_or3 far S_or3_976_1 = {&var93,&var635,&var634,&var354};
_S_or3 far S_or3_1373_1 = {&var618,&var617,&var94,&var355};
_S_and2 far S_and2_957_1 = {&var1193,&var972,&var356};
_S_and3 far S_and3_1842_1 = {&var374,&var359,&var367,&var357};
_S_or2 far S_or2_1846_1 = {&var361,&var360,&var358};
_S_or3 far S_or3_1844_1 = {&var361,&var360,&var370,&var359};
_S_zpfs far S_zpfs_1841_1 = {&var363,NULL,&var360,NULL,NULL};
_S_zpfs far S_zpfs_1839_1 = {&var364,NULL,&var361,NULL,NULL};
_S_or2 far S_or2_1833_1 = {&var364,&var363,&var362};
_S_or2 far S_or2_1834_1 = {&var365,&var1091,&var363};
_S_or2 far S_or2_1832_1 = {&var366,&var1091,&var364};
_S_and3 far S_and3_1826_1 = {&var1149,&var900,&var878,&var365};
_S_and3 far S_and3_1825_1 = {&var1150,&var877,&var900,&var366};
_S_or2 far S_or2_1823_1 = {&var1091,&var1090,&var367};
_S_or3 far S_or3_1830_1 = {&var372,&var1090,&var370,&var368};
_S_and2 far S_and2_1838_1 = {&var1091,&var359,&var369};
_S_and2 far S_and2_1829_1 = {&var1082,&var371,&var370};
_S_zpfs far S_zpfs_1828_1 = {&var1091,NULL,&var371,NULL,NULL};
_S_and2 far S_and2_1816_1 = {&var1085,&var534,&var372};
_S_or3 far S_or3_1817_1 = {&var1039,&var540,&var1017,&var373};
_S_abs_subf far S_abs_subf_1850_1 = {NULL,&var375,NULL,&vainSFloat,&var374};
_S_rsfn far S_rsfn_1848_1 = {&var531,&var376,&var375,NULL};
_S_lk far S_lk_1845_1 = {&var1248,&var359,&var376};
_S_abs_subf far S_abs_subf_1434_1 = {NULL,&var378,NULL,&vainSFloat,&var377};
_S_rsfn far S_rsfn_1425_1 = {&var531,&var379,&var378,NULL};
_S_lk far S_lk_1429_1 = {&var1096,&var518,&var379};
_S_abs_subf far S_abs_subf_1476_1 = {NULL,&var381,NULL,&vainSFloat,&var380};
_S_rsfn far S_rsfn_1463_1 = {&var531,&var382,&var381,NULL};
_S_lk far S_lk_1467_1 = {&var1102,&var508,&var382};
_S_ma far S_ma_1446_1 = {array_m1446_x_1,NULL,&iRM_7_,&vainSFloat};
_S_abs_subf far S_abs_subf_1481_1 = {NULL,&var384,NULL,&vainSFloat,&var383};
_S_rsfn far S_rsfn_1466_1 = {&var531,&var385,&var384,NULL};
_S_lk far S_lk_1470_1 = {&var1246,&var499,&var385};
_S_and3 far S_and3_1892_1 = {&var387,&var390,&var397,&var386};
_S_abs_subf far S_abs_subf_1889_1 = {&var388,NULL,NULL,&vainSFloat,&var387};
_S_rsfn far S_rsfn_1887_1 = {&var531,&var389,&var388,NULL};
_S_lk far S_lk_1883_1 = {&var1247,&var390,&var389};
_S_or3 far S_or3_1882_1 = {&var395,&var401,&var400,&var390};
_S_and4 far S_and4_1886_1 = {&var400,&var1253,&var413,&var411,&var391};
_S_and4 far S_and4_1884_1 = {&var401,&var1253,&var413,&var411,&var392};
_S_and2 far S_and2_1876_1 = {&var1094,&var390,&var393};
_S_and2 far S_and2_1862_1 = {&var534,&var1084,&var394};
_S_and2 far S_and2_1865_1 = {&var398,&var1083,&var395};
_S_or3 far S_or3_1866_1 = {&var395,&var394,&var1093,&var396};
_S_or2 far S_or2_1858_1 = {&var1094,&var1093,&var397};
_S_zpfs far S_zpfs_1864_1 = {&var1094,NULL,&var398,NULL,NULL};
_S_or3 far S_or3_1855_1 = {&var536,&var1043,&var1021,&var399};
_S_zpfs far S_zpfs_1880_1 = {&var403,NULL,&var400,NULL,NULL};
_S_zpfs far S_zpfs_1877_1 = {&var404,NULL,&var401,NULL,NULL};
_S_or2 far S_or2_1873_1 = {&var404,&var403,&var402};
_S_or2 far S_or2_1874_1 = {&var405,&var1094,&var403};
_S_or2 far S_or2_1872_1 = {&var406,&var1094,&var404};
_S_and4 far S_and4_1870_1 = {&var1151,&var878,NULL,&var407,&var405};
_S_and4 far S_and4_1869_1 = {&var1152,NULL,&var877,&var407,&var406};
_S_and2 far S_and2_1863_1 = {&var900,&var411,&var407};
_S_and3 far S_and3_1901_1 = {&var878,&var1005,&var410,&var408};
_S_and3 far S_and3_1900_1 = {&var877,&var1006,&var410,&var409};
_S_and4 far S_and4_1899_1 = {&var971,&var770,&var772,&var411,&var410};
_S_and2 far S_and2_1893_1 = {&var783,&var972,&var411};
_S_or2 far S_or2_1895_1 = {&var1257,&var970,&var412};
_S_or3 far S_or3_1904_1 = {&var416,&var415,&var418,&var413};
_S_and2 far S_and2_1894_1 = {&var1009,NULL,&var414};
_S_and2 far S_and2_1898_1 = {&var910,&var414,&var415};
_S_and3 far S_and3_1903_1 = {&var1252,&var419,&var414,&var416};
_S_or2 far S_or2_1912_1 = {&lRM_0_,&var412,&var417};
_S_and2 far S_and2_1909_1 = {&var925,&var419,&var418};
_S_and2 far S_and2_1911_1 = {&var1008,NULL,&var419};
_S_or2 far S_or2_1931_1 = {&var930,&var340,&var420};
_S_or2 far S_or2_1927_1 = {&var341,&var89,&var421};
_S_or2 far S_or2_1938_1 = {&var89,&var341,&var422};
_S_or2 far S_or2_1942_1 = {&var340,&var929,&var423};
_S_or2 far S_or2_2005_1 = {&var778,&var1163,&var424};
_S_or2 far S_or2_2011_1 = {&var972,&var1187,&var425};
_S_zpfs far S_zpfs_2013_1 = {&var13,&fRM_15_0,&var426,NULL,NULL};
_S_or2 far S_or2_2017_1 = {&var777,&var50,&var427};
_S_zpfs far S_zpfs_2024_1 = {&var11,&fRM_15_0,&var428,NULL,NULL};
_S_or2 far S_or2_2027_1 = {&var972,&var1186,&var429};
_S_or2 far S_or2_2043_1 = {&var19,&var391,&var430};
_S_or2 far S_or2_2038_1 = {&var392,&var23,&var431};
_S_and2 far S_and2_2049_1 = {&var1153,&var344,&var432};
_S_and2 far S_and2_1810_1 = {&var1127,NULL,&var433};
_S_or3 far S_or3_1783_1 = {&var438,&var442,&var440,&var434};
_S_or3 far S_or3_1787_1 = {&var441,&var440,&var437,&var435};
_S_or2 far S_or2_1797_1 = {NULL,NULL,&var436};
_S_and2 far S_and2_1788_1 = {&var443,&var436,&var437};
_S_and2 far S_and2_1782_1 = {&var443,&var439,&var438};
_S_or2 far S_or2_1781_1 = {NULL,NULL,&var439};
_S_zpfs far S_zpfs_1778_1 = {&var1145,&fRM_2_5,&var440,NULL,NULL};
_S_zpfs far S_zpfs_1777_1 = {&var1146,&fRM_2_5,&var441,NULL,NULL};
_S_zpfs far S_zpfs_1776_1 = {&var1147,&fRM_2_5,&var442,NULL,NULL};
_S_zpfs far S_zpfs_1775_1 = {&var1148,&fRM_2_5,&var443,NULL,NULL};
_S_or2 far S_or2_1806_1 = {NULL,NULL,&var444};
_S_and2 far S_and2_1801_1 = {&var49,&var1128,&var445};
_S_or2 far S_or2_1796_1 = {&var448,&var445,&var446};
_S_or2 far S_or2_1798_1 = {&var19,&var49,&var447};
_S_and2 far S_and2_1795_1 = {&var19,&var1118,&var448};
_S_and2 far S_and2_1779_1 = {&var1162,&var1129,&var449};
_S_or2 far S_or2_1780_1 = {&var452,&var449,&var450};
_S_or2 far S_or2_1773_1 = {&var23,&var1162,&var451};
_S_and2 far S_and2_1772_1 = {&var23,&var1119,&var452};
_S_or3 far S_or3_1742_1 = {&var1216,&var1174,&var1175,&var453};
_S_or3 far S_or3_1743_1 = {&var1214,&var1174,&var1175,&var454};
_S_or2 far S_or2_1734_1 = {&var1209,&var1174,&var455};
_S_or2 far S_or2_1735_1 = {&var1208,&var1174,&var456};
_S_or2 far S_or2_1741_1 = {&var1218,&var1177,&var457};
_S_or4 far S_or4_1739_1 = {&var1177,&var1215,&var1178,&var1179,&var458};
_S_or4 far S_or4_1738_1 = {&var1177,&var1221,&var1178,&var1179,&var459};
_S_or2 far S_or2_1732_1 = {&var1210,&var1179,&var460};
_S_or2 far S_or2_1731_1 = {&var1211,&var1179,&var461};
_S_or2 far S_or2_1740_1 = {&var1177,&var1217,&var462};
_S_or2 far S_or2_1709_1 = {&var204,&var254,&var463};
_S_or2 far S_or2_1706_1 = {&var252,&var207,&var464};
_S_or2 far S_or2_1703_1 = {&var207,&var253,&var465};
_S_or2 far S_or2_2119_1 = {&var24,&var253,&var466};
_S_or2 far S_or2_1678_1 = {&var201,&var253,&var467};
_S_or2 far S_or2_1669_1 = {&var252,&var194,&var468};
_S_or2 far S_or2_1667_1 = {&var252,&var197,&var469};
_S_or2 far S_or2_1663_1 = {&var253,&var194,&var470};
_S_or2 far S_or2_1661_1 = {&var197,&var253,&var471};
_S_and2 far S_and2_1554_1 = {&var1471,&var1429,&var472};
_S_and2 far S_and2_1553_1 = {&var1594,&var1429,&var473};
_S_and2 far S_and2_1552_1 = {&var867,&var1429,&var474};
_S_or2 far S_or2_1551_1 = {NULL,NULL,&var475};
_S_and2 far S_and2_1550_1 = {&var475,&var1429,&var476};
_S_and2 far S_and2_1544_1 = {&var1637,&var1429,&var477};
_S_and2 far S_and2_1543_1 = {&var102,&var1429,&var478};
_S_and2 far S_and2_1542_1 = {&var856,&var1429,&var479};
_S_and2 far S_and2_1541_1 = {NULL,&var1429,&var480};
_S_or2 far S_or2_1641_1 = {&var194,&var252,&var481};
_S_or2 far S_or2_1635_1 = {&var194,&var253,&var482};
_S_or2 far S_or2_1620_1 = {&var194,&var252,&var483};
_S_or2 far S_or2_1617_1 = {&var194,&var253,&var484};
_S_or2 far S_or2_1614_1 = {&var1227,&var254,&var485};
_S_or2 far S_or2_1611_1 = {&var1227,&var254,&var486};
_S_or2 far S_or2_1601_1 = {&var1607,&var1608,&var487};
_S_or2 far S_or2_1600_1 = {&var1609,&var1607,&var488};
_S_or2 far S_or2_2063_1 = {&var949,NULL,&var489};
_S_or3 far S_or3_2069_1 = {&var1228,&var1230,&var1229,&var490};
_S_or3 far S_or3_2060_1 = {&var1234,&var1236,&var1235,&var491};
_S_or2 far S_or2_1589_1 = {&var1695,&var1429,&var492};
_S_or2 far S_or2_1563_1 = {&var1472,&var1058,&var493};
_S_or5 far S_or5_1115_1 = {&var1487,&var495,&var1498,&var1484,&var1485,&var494};
_S_or3 far S_or3_1119_1 = {&var1492,&var1493,&var952,&var495};
_S_or5 far S_or5_1577_1 = {&var260,&var497,&var1481,&var1473,&var1474,&var496};
_S_or3 far S_or3_1580_1 = {&var951,&var1475,&var1476,&var497};
_S_and3 far S_and3_1491_1 = {&var499,&var504,&var383,&var498};
_S_and2 far S_and2_1493_1 = {&var500,&var1245,&var499};
_S_or3 far S_or3_1492_1 = {NULL,NULL,&var503,&var500};
_S_zpfs far S_zpfs_1477_1 = {&var1245,&fRM_0_2,&var501,NULL,NULL};
_S_or3 far S_or3_1479_1 = {&var1104,&var503,&var505,&var502};
_S_and2 far S_and2_1478_1 = {&var1081,&var501,&var503};
_S_or2 far S_or2_1468_1 = {&var1245,&var1104,&var504};
_S_and2 far S_and2_1456_1 = {&var1086,&var534,&var505};
_S_or3 far S_or3_1464_1 = {&var1018,&var1040,&var539,&var506};
_S_or3 far S_or3_1487_1 = {NULL,NULL,&var510,&var507};
_S_and2 far S_and2_1488_1 = {&var507,&var1101,&var508};
_S_zpfs far S_zpfs_1471_1 = {&var1101,NULL,&var509,NULL,NULL};
_S_and2 far S_and2_1472_1 = {&var509,&var1080,&var510};
_S_or3 far S_or3_1473_1 = {&var1099,&var510,&var513,&var511};
_S_or3 far S_or3_1448_1 = {&var538,&var1041,&var1019,&var512};
_S_and2 far S_and2_1451_1 = {&var1087,&var534,&var513};
_S_and3 far S_and3_1490_1 = {&var380,&var508,&var521,&var514};
_S_zpfs far S_zpfs_1421_1 = {&var1098,NULL,&var515,NULL,NULL};
_S_and2 far S_and2_1422_1 = {&var515,&var1079,&var516};
_S_and3 far S_and3_1438_1 = {&var377,&var518,&var522,&var517};
_S_and2 far S_and2_1432_1 = {&var519,&var1098,&var518};
_S_or3 far S_or3_1431_1 = {NULL,NULL,&var516,&var519};
_S_or3 far S_or3_1423_1 = {&var523,&var516,&var1097,&var520};
_S_or2 far S_or2_1459_1 = {&var1101,&var1099,&var521};
_S_or2 far S_or2_1419_1 = {&var1098,&var1097,&var522};
_S_and2 far S_and2_1411_1 = {&var1088,&var534,&var523};
_S_or3 far S_or3_1409_1 = {&var1020,&var1042,&var537,&var524};
_S_or2 far S_or2_1383_1 = {&var1600,&var526,&var525};
_S_and2 far S_and2_1382_1 = {&var527,&var1143,&var526};
_S_or2 far S_or2_1381_1 = {&var923,&var875,&var527};
_S_or2 far S_or2_1378_1 = {&var1013,&var1035,&var528};
_S_and2 far S_and2_1376_1 = {&var1107,&var1108,&var529};
_S_and2 far S_and2_1379_1 = {&var528,&var527,&var530};
_S_or5 far S_or5_1380_1 = {&var334,&var333,&var529,&var530,NULL,&var531};
_S_orni far S_orni_1400_1 = {array_m1400_x_1,&iRM_5_,&var532,&var533};
_S_or5 far S_or5_1402_1 = {&var1103,&var1078,&var531,&var1023,&var336,&var534};
_S_and2 far S_and2_1401_1 = {&var532,&var1240,&var535};
_S_or2 far S_or2_1408_1 = {&var1050,&var541,&var536};
_S_or2 far S_or2_1404_1 = {&var1049,&var542,&var537};
_S_or2 far S_or2_1398_1 = {&var1048,&var543,&var538};
_S_or2 far S_or2_1396_1 = {&var1047,&var544,&var539};
_S_or2 far S_or2_1394_1 = {&var1046,&var545,&var540};
_S_and2 far S_and2_1407_1 = {&var1595,&var546,&var541};
_S_and2 far S_and2_1403_1 = {&var1596,&var546,&var542};
_S_and2 far S_and2_1397_1 = {&var1597,&var546,&var543};
_S_and2 far S_and2_1395_1 = {&var1598,&var546,&var544};
_S_and2 far S_and2_1393_1 = {&var1599,&var546,&var545};
_S_and2 far S_and2_1387_1 = {&var1600,&var4,&var546};
_S_and3 far S_and3_1051_1 = {&var198,&var551,&var569,&var547};
_S_or2 far S_or2_1015_1 = {&var1060,&var1056,&var548};
_S_or2 far S_or2_1035_1 = {&var1056,&var990,&var549};
_S_and2 far S_and2_1009_1 = {&var1438,&var1057,&var550};
_S_and2 far S_and2_1005_1 = {&var1257,&var571,&var551};
_S_or3 far S_or3_1012_1 = {&var1056,&var986,&var1059,&var552};
_S_and2 far S_and2_1016_1 = {&var195,&var1257,&var553};
_S_and2 far S_and2_1036_1 = {&var206,&var1257,&var554};
_S_and2 far S_and2_1050_1 = {&var200,&var1257,&var555};
_S_and2 far S_and2_1057_1 = {&var203,&var1257,&var556};
_S_and3 far S_and3_1000_1 = {&var559,&var975,&var1257,&var557};
_S_and3 far S_and3_994_1 = {&var560,&var975,&var1257,&var558};
_S_and2 far S_and2_1002_1 = {&var877,&var1256,&var559};
_S_and2 far S_and2_992_1 = {&var878,&var1256,&var560};
_S_and4 far S_and4_1001_1 = {&var559,&var1257,&var983,&var973,&var561};
_S_and4 far S_and4_995_1 = {&var560,&var1257,&var983,&var973,&var562};
_S_and4 far S_and4_999_1 = {&var1257,&var559,&var567,&var974,&var563};
_S_and4 far S_and4_993_1 = {&var1257,&var560,&var567,&var974,&var564};
_S_and2 far S_and2_986_1 = {&var984,&var1257,&var565};
_S_or4 far S_or4_989_1 = {NULL,&var1491,&var211,&var578,&var566};
_S_and3 far S_and3_1037_1 = {&var985,&var984,&var983,&var567};
_S_and2 far S_and2_1022_1 = {&var569,&var349,&var568};
_S_and2 far S_and2_1025_1 = {&var982,&var567,&var569};
_S_or2 far S_or2_1038_1 = {&var1052,&var994,&var570};
_S_and2 far S_and2_1044_1 = {&var572,&var570,&var571};
_S_or2 far S_or2_1039_1 = {&var993,&var995,&var572};
_S_or2 far S_or2_1040_1 = {&var992,&var993,&var573};
_S_or2 far S_or2_1041_1 = {&var991,&var996,&var574};
_S_and2 far S_and2_1042_1 = {&var573,&var574,&var575};
_S_or2 far S_or2_1028_1 = {&var1052,&var1051,&var576};
_S_and2 far S_and2_1029_1 = {&var576,&var988,&var577};
_S_and5 far S_and5_982_1 = {&var579,&var1072,&var993,&var1052,&var568,&var578};
_S_and2 far S_and2_983_1 = {&var1027,&var1028,&var579};
_S_and2 far S_and2_1230_1 = {&var1121,&var581,&var580};
_S_or2 far S_or2_1225_1 = {NULL,&var582,&var581};
_S_and2 far S_and2_1213_1 = {NULL,&var1139,&var582};
_S_or2 far S_or2_1206_1 = {&var585,NULL,&var583};
_S_and2 far S_and2_1209_1 = {&var583,&var1121,&var584};
_S_and2 far S_and2_1200_1 = {NULL,&var1140,&var585};
_S_or3 far S_or3_1189_1 = {&var1207,&var1202,&var741,&var586};
_S_or5 far S_or5_1204_1 = {&var589,&var961,&var1468,&var1462,&var1463,&var587};
_S_or2 far S_or2_1223_1 = {&var1707,&var1453,&var588};
_S_or3 far S_or3_1275_1 = {&var1434,&var590,&var591,&var589};
_S_and2 far S_and2_1270_1 = {&var1453,&var924,&var590};
_S_and2 far S_and2_1269_1 = {&var874,&var1453,&var591};
_S_and3 far S_and3_1268_1 = {&var352,&var910,&var606,&var592};
_S_and2 far S_and2_1267_1 = {&var102,&var606,&var593};
_S_and3 far S_and3_1263_1 = {&var899,&var945,&var606,&var594};
_S_and2 far S_and2_1262_1 = {&var444,&var606,&var595};
_S_and2 far S_and2_1250_1 = {&var1444,&var606,&var596};
_S_and2 far S_and2_1237_1 = {&var1637,&var606,&var597};
_S_and2 far S_and2_1252_1 = {&var2,&var606,&var598};
_S_and2 far S_and2_1238_1 = {NULL,&var606,&var599};
_S_and2 far S_and2_1253_1 = {&var602,&var606,&var600};
_S_and3 far S_and3_1239_1 = {&var603,&var1443,&var606,&var601};
_S_or2 far S_or2_1254_1 = {&var1436,&var1437,&var602};
_S_or2 far S_or2_1241_1 = {NULL,NULL,&var603};
_S_and3 far S_and3_1249_1 = {&var1177,&var212,&var926,&var604};
_S_and3 far S_and3_1248_1 = {&var1179,&var212,&var926,&var605};
_S_or3 far S_or3_1240_1 = {&var1454,&var605,&var604,&var606};
_S_and2 far S_and2_1324_1 = {&var608,&var1121,&var607};
_S_or2 far S_or2_1323_1 = {&var609,NULL,&var608};
_S_and2 far S_and2_1312_1 = {NULL,&var1117,&var609};
_S_or2 far S_or2_1315_1 = {&var1698,&var1271,&var610};
_S_or5 far S_or5_1301_1 = {&var355,&var1281,&var1280,&var123,&var959,&var611};
_S_and2 far S_and2_1361_1 = {&var1271,&var924,&var612};
_S_and2 far S_and2_1360_1 = {&var1271,&var874,&var613};
_S_and2 far S_and2_1369_1 = {&var940,&var1259,&var614};
_S_or2 far S_or2_1364_1 = {&var614,&var941,&var615};
_S_and3 far S_and3_1359_1 = {&var1130,&var615,&var624,&var616};
_S_and3 far S_and3_1358_1 = {&var352,&var925,&var624,&var617};
_S_and2 far S_and2_1357_1 = {&var102,&var624,&var618};
_S_and2 far S_and2_1354_1 = {&var1191,&var972,&var619};
_S_or2 far S_or2_1344_1 = {&var1262,&var1261,&var620};
_S_and2 far S_and2_1343_1 = {&var620,&var624,&var621};
_S_and2 far S_and2_1342_1 = {&var2,&var624,&var622};
_S_and2 far S_and2_1340_1 = {&var1264,&var624,&var623};
_S_or2 far S_or2_1332_1 = {&var1273,&var27,&var624};
_S_or2 far S_or2_1333_1 = {NULL,NULL,&var625};
_S_and3 far S_and3_1330_1 = {&var1263,&var625,&var624,&var626};
_S_and2 far S_and2_1329_1 = {NULL,&var624,&var627};
_S_and2 far S_and2_1328_1 = {&var1637,&var624,&var628};
_S_and2 far S_and2_972_1 = {&var938,&var1291,&var629};
_S_and2 far S_and2_963_1 = {&var874,&var1303,&var630};
_S_and2 far S_and2_964_1 = {&var924,&var1303,&var631};
_S_or2 far S_or2_967_1 = {&var939,&var629,&var632};
_S_and3 far S_and3_962_1 = {&var1130,&var632,&var639,&var633};
_S_and3 far S_and3_961_1 = {&var910,&var352,&var639,&var634};
_S_and2 far S_and2_960_1 = {&var102,&var639,&var635};
_S_and2 far S_and2_943_1 = {&var1296,&var639,&var636};
_S_or2 far S_or2_947_1 = {&var1294,&var1293,&var637};
_S_and2 far S_and2_946_1 = {&var637,&var639,&var638};
_S_or2 far S_or2_936_1 = {&var1305,&var28,&var639};
_S_or2 far S_or2_934_1 = {NULL,NULL,&var640};
_S_and3 far S_and3_933_1 = {&var640,&var1295,&var639,&var641};
_S_and2 far S_and2_945_1 = {&var2,&var639,&var642};
_S_and2 far S_and2_932_1 = {NULL,&var639,&var643};
_S_and2 far S_and2_931_1 = {&var1637,&var639,&var644};
_S_or2 far S_or2_918_1 = {&var1303,&var1701,&var645};
_S_or5 far S_or5_902_1 = {&var354,&var960,&var121,&var1312,&var1313,&var646};
_S_and2 far S_and2_929_1 = {&var1121,&var648,&var647};
_S_or2 far S_or2_926_1 = {&var649,NULL,&var648};
_S_and2 far S_and2_915_1 = {NULL,&var1176,&var649};
_S_or3 far S_or3_873_1 = {&var1401,&var652,&var651,&var650};
_S_and2 far S_and2_867_1 = {&var1412,&var874,&var651};
_S_and2 far S_and2_868_1 = {&var1412,&var924,&var652};
_S_and3 far S_and3_866_1 = {&var1435,&var925,&var664,&var653};
_S_and2 far S_and2_865_1 = {&var102,&var664,&var654};
_S_and2 far S_and2_848_1 = {&var1405,&var664,&var655};
_S_and2 far S_and2_850_1 = {&var2,&var664,&var656};
_S_and2 far S_and2_851_1 = {&var658,&var664,&var657};
_S_or2 far S_or2_852_1 = {&var1403,&var1402,&var658};
_S_and2 far S_and2_835_1 = {&var1637,&var664,&var659};
_S_and3 far S_and3_837_1 = {&var1404,&var665,&var664,&var660};
_S_and2 far S_and2_836_1 = {NULL,&var664,&var661};
_S_and3 far S_and3_847_1 = {&var1177,&var212,&var926,&var662};
_S_and3 far S_and3_846_1 = {&var212,&var1179,&var926,&var663};
_S_or3 far S_or3_839_1 = {&var1413,&var662,&var663,&var664};
_S_or2 far S_or2_840_1 = {NULL,NULL,&var665};
_S_or2 far S_or2_825_1 = {&var1704,&var1412,&var666};
_S_zpfs far S_zpfs_823_1 = {&var1426,&fRM_3_0,&var667,NULL,NULL};
_S_zpfs far S_zpfs_820_1 = {&var1427,&fRM_2_0,&var668,NULL,NULL};
_S_zpfs far S_zpfs_827_1 = {&var1424,NULL,&var669,NULL,NULL};
_S_or5 far S_or5_815_1 = {&var650,&var669,&var1425,&var668,&var667,&var670};
_S_or3 far S_or3_801_1 = {&var1182,&var1205,&var736,&var671};
_S_or4 far S_or4_788_1 = {&var1548,&var1546,&var1547,&var1549,&var672};
_S_or2 far S_or2_779_1 = {&var674,&var672,&var673};
_S_or4 far S_or4_772_1 = {&var1557,&var1556,&var1555,&var1558,&var674};
_S_and2 far S_and2_253_1 = {&var942,&var1351,&var675};
_S_and3 far S_and3_242_1 = {&var910,&var352,&var1366,&var676};
_S_or3 far S_or3_255_1 = {&var680,&var678,&var1354,&var677};
_S_and2 far S_and2_245_1 = {&var1365,&var924,&var678};
_S_and3 far S_and3_243_1 = {&var351,&var1130,&var1366,&var679};
_S_and2 far S_and2_244_1 = {&var874,&var1365,&var680};
_S_and2 far S_and2_241_1 = {&var102,&var1366,&var681};
_S_and2 far S_and2_216_1 = {&var1358,&var1366,&var682};
_S_and2 far S_and2_218_1 = {&var2,&var1366,&var683};
_S_or2 far S_or2_220_1 = {&var1355,&var1356,&var684};
_S_and2 far S_and2_219_1 = {&var684,&var1366,&var685};
_S_or2 far S_or2_209_1 = {NULL,NULL,&var686};
_S_and3 far S_and3_208_1 = {&var1357,&var686,&var1366,&var687};
_S_and2 far S_and2_206_1 = {&var1637,&var1366,&var688};
_S_and2 far S_and2_207_1 = {NULL,&var1366,&var689};
_S_and2 far S_and2_183_1 = {&var1121,&var692,&var690};
_S_and2 far S_and2_175_1 = {NULL,&var1161,&var691};
_S_or2 far S_or2_181_1 = {NULL,&var691,&var692};
_S_or2 far S_or2_195_1 = {&var1365,&var1689,&var693};
_S_zpfs far S_zpfs_186_1 = {&var1380,&fRM_2_0,&var694,NULL,NULL};
_S_zpfs far S_zpfs_190_1 = {&var1379,&fRM_2_0,&var695,NULL,NULL};
_S_zpfs far S_zpfs_197_1 = {&var1377,NULL,&var696,NULL,NULL};
_S_or5 far S_or5_179_1 = {&var677,&var696,&var695,&var694,&var1378,&var697};
_S_orn far S_orn_544_1 = {array_m544_x_1,&iRM_14_,&var698};
_S_and2 far S_and2_567_1 = {&var1321,&var937,&var699};
_S_or2 far S_or2_562_1 = {&var936,&var699,&var700};
_S_and3 far S_and3_556_1 = {&var925,&var1435,&var1333,&var701};
_S_and2 far S_and2_555_1 = {&var102,&var1333,&var702};
_S_and3 far S_and3_557_1 = {&var1130,&var1333,&var700,&var703};
_S_or2 far S_or2_537_1 = {&var1323,&var1322,&var704};
_S_and2 far S_and2_536_1 = {&var704,&var1333,&var705};
_S_and2 far S_and2_535_1 = {&var1333,&var2,&var706};
_S_and3 far S_and3_525_1 = {&var1324,&var708,&var1333,&var707};
_S_or2 far S_or2_526_1 = {NULL,NULL,&var708};
_S_and2 far S_and2_533_1 = {&var1333,&var1325,&var709};
_S_or2 far S_or2_503_1 = {NULL,&var712,&var710};
_S_and2 far S_and2_507_1 = {&var1121,&var710,&var711};
_S_and2 far S_and2_496_1 = {NULL,&var1141,&var712};
_S_and2 far S_and2_524_1 = {&var1333,NULL,&var713};
_S_and2 far S_and2_523_1 = {&var1333,&var1637,&var714};
_S_or2 far S_or2_514_1 = {&var1332,&var1711,&var715};
_S_zpfs far S_zpfs_516_1 = {&var1346,NULL,&var716,NULL,NULL};
_S_or5 far S_or5_499_1 = {&var870,&var716,&var1347,&var1341,&var1342,&var717};
_S_or2 far S_or2_487_1 = {&var1157,&var737,&var718};
_S_or3 far S_or3_477_1 = {&var558,&var1156,&var967,&var719};
_S_or4 far S_or4_467_1 = {&var1385,&var1383,&var1385,&var1384,&var720};
_S_or4 far S_or4_449_1 = {&var1394,&var1392,&var1393,&var1395,&var721};
_S_or2 far S_or2_456_1 = {&var721,&var720,&var722};
_S_and3 far S_and3_440_1 = {&var725,&var1121,NULL,&var723};
_S_and3 far S_and3_441_1 = {&var1121,&var726,NULL,&var724};
_S_or3 far S_or3_433_1 = {&var246,&var976,&var963,&var725};
_S_or2 far S_or2_434_1 = {&var1381,&var1155,&var726};
_S_or2 far S_or2_742_1 = {&var1516,&var1517,&var727};
_S_and2 far S_and2_326_1 = {&var1012,&var1074,&var728};
_S_or2 far S_or2_345_1 = {NULL,NULL,&var729};
_S_or2 far S_or2_340_1 = {NULL,NULL,&var730};
_S_or2 far S_or2_335_1 = {&var733,&var1016,&var731};
_S_and3 far S_and3_333_1 = {&var1075,&var1070,&var1071,&var732};
_S_or4 far S_or4_331_1 = {&var1001,&var152,NULL,&var1011,&var733};
_S_and4 far S_and4_327_1 = {&var923,&var791,&var211,&var881,&var734};
_S_or2 far S_or2_322_1 = {NULL,&var1011,&var735};
_S_and3 far S_and3_596_1 = {&var758,&var1258,NULL,&var736};
_S_and2 far S_and2_595_1 = {&var758,&var1290,&var737};
_S_and2 far S_and2_594_1 = {&var758,&var1353,&var738};
_S_or2 far S_or2_638_1 = {NULL,NULL,&var739};
_S_or2 far S_or2_615_1 = {&var1488,&var1110,&var740};
_S_and3 far S_and3_606_1 = {NULL,&var1258,&var759,&var741};
_S_and2 far S_and2_637_1 = {&var743,&var1258,&var742};
_S_or2 far S_or2_639_1 = {&var1053,&var195,&var743};
_S_or2 far S_or2_620_1 = {&var1488,&var1109,&var744};
_S_or2 far S_or2_618_1 = {&var746,&var1488,&var745};
_S_and2 far S_and2_630_1 = {&var1290,&var206,&var746};
_S_and2 far S_and2_605_1 = {&var759,&var1290,&var747};
_S_and2 far S_and2_604_1 = {&var759,&var1353,&var748};
_S_and2 far S_and2_629_1 = {&var200,&var1353,&var749};
_S_and2 far S_and2_645_1 = {&var203,&var1381,&var750};
_S_or2 far S_or2_641_1 = {&var1488,&var1111,&var751};
_S_or2 far S_or2_636_1 = {&var753,&var750,&var752};
_S_and2 far S_and2_628_1 = {&var761,&var1350,&var753};
_S_and2 far S_and2_634_1 = {&var761,NULL,&var754};
_S_or2 far S_or2_584_1 = {&var934,&var935,&var755};
_S_and4 far S_and4_603_1 = {&var934,&var759,&var1450,NULL,&var756};
_S_and4 far S_and4_593_1 = {&var758,&var935,&var1450,NULL,&var757};
_S_and2 far S_and2_592_1 = {&var878,&var1448,&var758};
_S_and2 far S_and2_602_1 = {&var877,&var1448,&var759};
_S_or2 far S_or2_633_1 = {&var1054,&var195,&var760};
_S_and2 far S_and2_626_1 = {&var760,&var1450,&var761};
_S_or2 far S_or2_613_1 = {&var1488,&var1112,&var762};
_S_or2 far S_or2_625_1 = {&var1428,&var1067,&var763};
_S_and2 far S_and2_624_1 = {&var763,&var1472,&var764};
_S_or2 far S_or2_610_1 = {&var1488,&var1113,&var765};
_S_and2 far S_and2_623_1 = {&var1489,&var1438,&var766};
_S_or2 far S_or2_608_1 = {&var1488,&var1114,&var767};
_S_and2 far S_and2_621_1 = {&var198,&var1491,&var768};
_S_or2 far S_or2_600_1 = {&var1122,&var1488,&var769};
_S_and2 far S_and2_301_1 = {&var1188,&var772,&var770};
_S_and2 far S_and2_289_1 = {&var772,&var999,&var771};
_S_or2 far S_or2_284_1 = {&var1013,&var1035,&var772};
_S_and3 far S_and3_280_1 = {&var1254,&var1070,&var1071,&var773};
_S_and3 far S_and3_295_1 = {&var730,&var1000,&var775,&var774};
_S_or2 far S_or2_285_1 = {&var1254,&var1075,&var775};
_S_and2 far S_and2_294_1 = {&var729,&var775,&var776};
_S_and2 far S_and2_314_1 = {&var781,&var878,&var777};
_S_and2 far S_and2_315_1 = {&var877,&var781,&var778};
_S_and2 far S_and2_320_1 = {&var972,&var770,&var779};
_S_and2 far S_and2_308_1 = {&var781,&var972,&var780};
_S_and2 far S_and2_313_1 = {&var1153,&var782,&var781};
_S_or2 far S_or2_309_1 = {&var783,&var728,&var782};
_S_or2 far S_or2_310_1 = {&var784,&var728,&var783};
_S_and4 far S_and4_311_1 = {&var1076,&var1024,&var1025,&var875,&var784};
_S_or2 far S_or2_297_1 = {&var1076,&var1074,&var785};
_S_and2 far S_and2_282_1 = {&var1038,&var1007,&var786};
_S_or2 far S_or2_288_1 = {&var789,&var786,&var787};
_S_or2 far S_or2_262_1 = {NULL,&var1010,&var788};
_S_or4 far S_or4_279_1 = {&var1001,NULL,&var152,&var1010,&var789};
_S_and3 far S_and3_272_1 = {&var791,&var880,&var211,&var790};
_S_or2 far S_or2_271_1 = {&var1029,&var1219,&var791};
_S_and3 far S_and3_274_1 = {&var1030,&var1032,&var1031,&var792};
_S_or2 far S_or2_264_1 = {&var794,&var792,&var793};
_S_and3 far S_and3_258_1 = {NULL,&var1034,&var1033,&var794};
_S_or2 far S_or2_1087_1 = {NULL,NULL,&var795};
_S_and2 far S_and2_1090_1 = {&var1439,&var1486,&var796};
_S_and2 far S_and2_1089_1 = {&var1439,&var1594,&var797};
_S_and2 far S_and2_1088_1 = {&var1439,&var867,&var798};
_S_and2 far S_and2_1086_1 = {&var1439,&var795,&var799};
_S_and2 far S_and2_1080_1 = {&var1439,&var102,&var800};
_S_and2 far S_and2_1079_1 = {&var856,&var1439,&var801};
_S_and2 far S_and2_1078_1 = {&var1439,NULL,&var802};
_S_and2 far S_and2_1081_1 = {&var1439,&var1637,&var803};
_S_and2 far S_and2_1073_1 = {&var195,&var969,&var804};
_S_and2 far S_and2_1074_1 = {&var206,&var967,&var805};
_S_and2 far S_and2_1075_1 = {&var200,&var965,&var806};
_S_and2 far S_and2_1076_1 = {&var203,&var963,&var807};
_S_or2 far S_or2_1058_1 = {NULL,&var809,&var808};
_S_and4 far S_and4_1059_1 = {&var107,&var106,&var105,&var104,&var809};
_S_or2 far S_or2_1129_1 = {&var1439,&var1692,&var810};
_S_or2 far S_or2_1105_1 = {&var1489,&var1057,&var811};
_S_or2 far S_or2_1170_1 = {&var1530,&var1529,&var812};
_S_or2 far S_or2_1156_1 = {&var1539,&var1538,&var813};
_S_or2 far S_or2_1166_1 = {&var950,NULL,&var814};
_S_or2 far S_or2_1143_1 = {&var812,&var1594,&var815};
_S_or2 far S_or2_1141_1 = {&var817,&var815,&var816};
_S_or2 far S_or2_1142_1 = {&var813,&var1594,&var817};
_S_or4 far S_or4_357_1 = {&var1566,&var1565,&var1567,&var1564,&var818};
_S_or2 far S_or2_658_1 = {NULL,NULL,&var819};
_S_and2 far S_and2_657_1 = {&var824,&var819,&var820};
_S_or2 far S_or2_656_1 = {NULL,NULL,&var821};
_S_and2 far S_and2_655_1 = {&var824,&var821,&var822};
_S_or2 far S_or2_654_1 = {NULL,NULL,&var823};
_S_or2 far S_or2_647_1 = {&var826,&var827,&var824};
_S_and2 far S_and2_653_1 = {&var824,&var823,&var825};
_S_and2 far S_and2_650_1 = {&var102,&var837,&var826};
_S_and2 far S_and2_646_1 = {&var103,&var830,&var827};
_S_and2 far S_and2_762_1 = {&var1592,&var1510,&var828};
_S_and2 far S_and2_758_1 = {&var1592,&var1511,&var829};
_S_and3 far S_and3_753_1 = {&var1592,&var103,&var1517,&var830};
_S_or2 far S_or2_761_1 = {&var1512,&var1506,&var831};
_S_or2 far S_or2_756_1 = {&var1510,&var1512,&var832};
_S_or2 far S_or2_752_1 = {&var1512,&var1511,&var833};
_S_and2 far S_and2_734_1 = {&var1506,&var1592,&var834};
_S_or2 far S_or2_725_1 = {&var1513,&var1514,&var835};
_S_or2 far S_or2_721_1 = {&var1571,&var1513,&var836};
_S_and2 far S_and2_718_1 = {&var1514,&var1593,&var837};
_S_and2 far S_and2_717_1 = {&var1571,&var1593,&var838};
_S_and2 far S_and2_746_1 = {&var198,&var1592,&var839};
_S_and2 far S_and2_727_1 = {&var198,&var1523,&var840};
_S_and2 far S_and2_744_1 = {&var1593,&var198,&var841};
_S_or2 far S_or2_738_1 = {&var1593,&var1592,&var842};
_S_or3 far S_or3_731_1 = {&var6,&var845,&var846,&var843};
_S_or4 far S_or4_730_1 = {&var845,&var5,&var847,&var1502,&var844};
_S_or3 far S_or3_720_1 = {NULL,&var834,&var838,&var845};
_S_or2 far S_or2_750_1 = {&var1591,&var849,&var846};
_S_or2 far S_or2_749_1 = {&var1591,&var848,&var847};
_S_and2 far S_and2_668_1 = {&var6,&var1505,&var848};
_S_and3 far S_and3_697_1 = {&var1504,&var1518,&var5,&var849};
_S_and2 far S_and2_702_1 = {NULL,&var864,&var850};
_S_and3 far S_and3_700_1 = {&var1153,NULL,&var864,&var851};
_S_and2 far S_and2_701_1 = {NULL,&var864,&var852};
_S_or2 far S_or2_699_1 = {NULL,NULL,&var853};
_S_and2 far S_and2_698_1 = {&var853,&var864,&var854};
_S_and2 far S_and2_685_1 = {&var864,&var856,&var855};
_S_or4 far S_or4_686_1 = {NULL,NULL,NULL,NULL,&var856};
_S_and2 far S_and2_683_1 = {&var861,&var864,&var857};
_S_and2 far S_and2_674_1 = {&var867,&var864,&var858};
_S_and2 far S_and2_673_1 = {&var1594,&var864,&var859};
_S_or3 far S_or3_672_1 = {NULL,NULL,NULL,&var860};
_S_or2 far S_or2_684_1 = {NULL,NULL,&var861};
_S_and2 far S_and2_671_1 = {&var864,&var860,&var862};
_S_and2 far S_and2_669_1 = {&var1572,&var864,&var863};
_S_or2 far S_or2_660_1 = {&var1593,&var1592,&var864};
_S_or2 far S_or2_165_1 = {&var1159,&var747,&var865};
_S_or3 far S_or3_155_1 = {&var557,&var1158,&var967,&var866};
_S_or2 far S_or2_146_1 = {&var1435,&var352,&var867};
_S_or3 far S_or3_107_1 = {&var1120,&var338,&var339,&var868};
_S_or2 far S_or2_1984_1 = {&var300,&var173,&var869};
_S_or3 far S_or3_569_1 = {&var871,&var872,&var698,&var870};
_S_and2 far S_and2_558_1 = {&var1332,&var874,&var871};
_S_and2 far S_and2_559_1 = {&var1332,&var924,&var872};
_S_or2 far S_or2_60_1 = {&var924,&var874,&var873};
_S_and2 far S_and2_63_1 = {&var875,&var1003,&var874};
_S_and2 far S_and2_62_1 = {&var1601,&var1004,&var875};
_S_or2 far S_or2_48_1 = {NULL,NULL,&var876};
_S_or2 far S_or2_35_1 = {&var1252,&var1249,&var877};
_S_or2 far S_or2_39_1 = {&var1252,&var1251,&var878};
_S_or2 far S_or2_20_1 = {&var1153,&var1105,&var879};
_S_or2 far S_or2_8_1 = {&var1611,&var926,&var880};
_S_or2 far S_or2_14_1 = {&var926,&var1612,&var881};
_S_and3 far S_and3_981_1 = {&var208,&var1605,&var901,&var882};
_S_and3 far S_and3_582_1 = {&var901,&var211,&var1605,&var883};
_S_and2 far S_and2_1047_1 = {&var947,&var885,&var884};
_S_or2 far S_or2_1053_1 = {&var1612,&var1611,&var885};
_S_or2 far S_or2_1353_1 = {&var1613,&var1611,&var886};
_S_and3 far S_and3_1352_1 = {&var945,&var886,&var624,&var887};
_S_or2 far S_or2_956_1 = {&var1613,&var1611,&var888};
_S_and3 far S_and3_955_1 = {&var945,&var888,&var639,&var889};
_S_or2 far S_or2_548_1 = {&var1613,&var1611,&var890};
_S_and3 far S_and3_547_1 = {&var945,&var890,&var1333,&var891};
_S_and2 far S_and2_545_1 = {&var98,&var1333,&var892};
_S_or2 far S_or2_231_1 = {&var1613,&var1611,&var893};
_S_and3 far S_and3_230_1 = {&var945,&var893,&var1366,&var894};
_S_and2 far S_and2_228_1 = {&var1366,&var99,&var895};
_S_and3 far S_and3_861_1 = {&var945,&var898,&var664,&var896};
_S_and2 far S_and2_860_1 = {&var444,&var664,&var897};
_S_or2 far S_or2_862_1 = {&var1613,&var1611,&var898};
_S_or2 far S_or2_1264_1 = {&var1613,&var1611,&var899};
_S_or2 far S_or2_6_1 = {&var1612,&var1611,&var900};
_S_or3 far S_or3_5_1 = {&var1613,&var1612,&var1611,&var901};
_S_or2 far S_or2_737_1 = {&var1513,&var1515,&var902};
_S_or2 far S_or2_430_1 = {&var1594,&var907,&var903};
_S_or2 far S_or2_413_1 = {&var1594,&var908,&var904};
_S_or4 far S_or4_414_1 = {&var904,&var1522,&var1521,&var903,&var905};
_S_and2 far S_and2_406_1 = {NULL,&var1586,&var906};
_S_or3 far S_or3_392_1 = {&var1576,&var1574,&var1575,&var907};
_S_or3 far S_or3_377_1 = {&var1584,&var1583,&var1585,&var908};
_S_and2 far S_and2_724_1 = {&var1593,&var1515,&var909};
_S_and2 far S_and2_38_1 = {&var1249,&var1250,&var910};
_S_and2 far S_and2_141_1 = {&var1525,&var1144,&var911};
_S_and2 far S_and2_149_1 = {&var1527,&var1144,&var912};
_S_and2 far S_and2_152_1 = {&var1524,&var1144,&var913};
_S_and2 far S_and2_144_1 = {&var1144,&var1526,&var914};
_S_and2 far S_and2_427_1 = {&var867,&var1578,&var915};
_S_and2 far S_and2_426_1 = {NULL,&var1578,&var916};
_S_and2 far S_and2_425_1 = {NULL,&var1578,&var917};
_S_and2 far S_and2_424_1 = {NULL,&var1578,&var918};
_S_and2 far S_and2_416_1 = {&var1520,&var1586,&var919};
_S_and2 far S_and2_405_1 = {NULL,&var1586,&var920};
_S_and2 far S_and2_409_1 = {&var867,&var1586,&var921};
_S_and2 far S_and2_111_1 = {&var926,&var337,&var922};
_S_and2 far S_and2_58_1 = {&var1602,&var1004,&var923};
_S_and2 far S_and2_59_1 = {&var923,&var1002,&var924};
_S_and2 far S_and2_42_1 = {&var1250,&var1251,&var925};
_S_and2 far S_and2_11_1 = {&var1610,&var1242,&var926};
_S_and2 far S_and2_31_1 = {&var1173,&var197,&var927};
_S_and2 far S_and2_30_1 = {&var1063,&var1153,&var928};
_S_and2 far S_and2_29_1 = {&var1064,&var1153,&var929};
_S_and2 far S_and2_28_1 = {&var1065,&var1153,&var930};
_S_and2 far S_and2_27_1 = {&var1066,&var1153,&var931};
_S_and2 far S_and2_751_1 = {&var1509,&var1517,&var932};
_S_and2 far S_and2_733_1 = {&var1516,&var1593,&var933};
_S_bol far S_bol_583_1 = {&var1706,&fRM_20_0,&var934};
_S_bol far S_bol_577_1 = {&var1703,&fRM_20_0,&var935};
_S_bol far S_bol_568_1 = {&var1703,&fRM_20_03,&var936};
_S_bol far S_bol_566_1 = {&var1706,&fRM_20_03,&var937};
_S_bol far S_bol_971_1 = {&var1703,&fRM_20_03,&var938};
_S_bol far S_bol_973_1 = {&var1706,&fRM_20_03,&var939};
_S_bol far S_bol_1368_1 = {&var1706,&fRM_20_03,&var940};
_S_bol far S_bol_1370_1 = {&var1703,&fRM_20_03,&var941};
_S_bol far S_bol_252_1 = {&var1703,&fRM_20_03,&var942};
_S_bol far S_bol_254_1 = {&var1706,&fRM_20_03,&var943};
_S_sr far S_sr_81_1 = {array_m81_x_1,&iRM_2_,&var944};
_S_bol far S_bol_80_1 = {&var944,&var151,&var945};
_S_ma far S_ma_83_1 = {array_m83_x_1,NULL,&iRM_8_,&var946};
_S_bol far S_bol_1048_1 = {&var948,NULL,&var947};
_S_sr far S_sr_1054_1 = {array_m1054_x_1,&iRM_2_,&var948};
_S_ovbs far S_ovbs_2062_1 = {&lRM_1_,NULL,&var949,NULL};
_S_ovbs far S_ovbs_1165_1 = {&lRM_1_,NULL,&var950,NULL};
_S_zpfs far S_zpfs_1591_1 = {&var1480,NULL,&var951,NULL,NULL};
_S_zpfs far S_zpfs_1131_1 = {&var1497,NULL,&var952,NULL,NULL};
_S_ma far S_ma_1187_1 = {array_m1187_x_1,&var1449,&iRM_8_,&var953};
_S_ma far S_ma_803_1 = {array_m803_x_1,&var1409,&iRM_8_,&var954};
_S_ma far S_ma_885_1 = {array_m885_x_1,&var1300,&iRM_8_,&var955};
_S_ma far S_ma_1287_1 = {array_m1287_x_1,&var1268,&iRM_8_,&var956};
_S_ma far S_ma_486_1 = {array_m486_x_1,&var1329,&iRM_8_,&var957};
_S_ma far S_ma_162_1 = {array_m162_x_1,&var1362,&iRM_8_,&var958};
_S_zpfs far S_zpfs_1317_1 = {&var1285,NULL,&var959,NULL,NULL};
_S_zpfs far S_zpfs_920_1 = {&var1317,NULL,&var960,NULL,NULL};
_S_zpfs far S_zpfs_1224_1 = {&var1467,NULL,&var961,NULL,NULL};
_S_rs far S_rs_1072_1 = {&var808,&var807,&var962,&vainSBool,NULL};
_S_rs far S_rs_1070_1 = {&var107,&var970,&var963,&vainSBool,NULL};
_S_rs far S_rs_1069_1 = {&var808,&var806,&var964,&vainSBool,NULL};
_S_rs far S_rs_1067_1 = {&var106,&var970,&var965,&vainSBool,NULL};
_S_rs far S_rs_1066_1 = {&var808,&var805,&var966,&vainSBool,NULL};
_S_rs far S_rs_1064_1 = {&var105,&var970,&var967,&vainSBool,NULL};
_S_rs far S_rs_1063_1 = {&var808,&var804,&var968,&vainSBool,NULL};
_S_rs far S_rs_1061_1 = {&var104,&var970,&var969,&vainSBool,NULL};
_S_rs far S_rs_1060_1 = {&var808,&var152,&var970,&vainSBool,NULL};
_S_noto far S_noto_1896_1 = {&var412,&var971};
_S_swtakt far S_swtakt_52_1 = {&var332,&var972,NULL};
_S_noto far S_noto_1046_1 = {&var984,&var973};
_S_noto far S_noto_1020_1 = {&var982,&var974};
_S_noto far S_noto_1032_1 = {&var983,&var975};
_S_rs far S_rs_980_1 = {&var985,&var565,&var976,&vainSBool,NULL};
_S_swtakt far S_swtakt_1414_1 = {&var524,&var977,NULL};
_S_swtakt far S_swtakt_1458_1 = {&var512,&var978,NULL};
_S_swtakt far S_swtakt_1454_1 = {&var506,&var979,NULL};
_S_swtakt far S_swtakt_1856_1 = {&var399,&var980,NULL};
_S_swtakt far S_swtakt_1821_1 = {&var373,&var981,NULL};
_S_rs far S_rs_1019_1 = {&var1056,&var553,&var982,&vainSBool,NULL};
_S_rs far S_rs_1031_1 = {&var1056,&var554,&var983,&vainSBool,NULL};
_S_rs far S_rs_1043_1 = {&var1056,&var555,&var984,&vainSBool,NULL};
_S_rs far S_rs_1052_1 = {&var1056,&var556,&var985,&vainSBool,NULL};
_S_noto far S_noto_1006_1 = {&var571,&var986};
_S_noto far S_noto_1034_1 = {&var571,&var987};
_S_noto far S_noto_1033_1 = {&var575,&var988};
_S_rs far S_rs_1030_1 = {&var549,&var551,&var989,&vainSBool,NULL};
_S_rs far S_rs_1045_1 = {&var1056,&var547,&var990,&vainSBool,NULL};
_S_bol far S_bol_1027_1 = {&var1691,&var262,&var991};
_S_bol far S_bol_1026_1 = {&var1694,&var262,&var992};
_S_noto far S_noto_987_1 = {&var1051,&var993};
_S_bol far S_bol_1024_1 = {&var262,&var1691,&var994};
_S_bol far S_bol_1023_1 = {&var262,&var1694,&var995};
_S_noto far S_noto_1010_1 = {&var1052,&var996};
_S_rs far S_rs_1914_1 = {&var417,&var408,&var997,&vainSBool,NULL};
_S_rs far S_rs_1913_1 = {&var417,&var409,&var998,&vainSBool,NULL};
_S_noto far S_noto_321_1 = {&var779,&var999};
_S_noto far S_noto_303_1 = {&var772,&var1000};
_S_noto far S_noto_273_1 = {&var791,&var1001};
_S_noto far S_noto_56_1 = {&var1013,&var1002};
_S_noto far S_noto_67_1 = {&var1035,&var1003};
_S_noto far S_noto_66_1 = {&var970,&var1004};
_S_noto far S_noto_1908_1 = {NULL,&var1005};
_S_noto far S_noto_1906_1 = {NULL,&var1006};
_S_noto far S_noto_281_1 = {&var211,&var1007};
_S_noto far S_noto_1915_1 = {NULL,&var1008};
_S_noto far S_noto_1890_1 = {NULL,&var1009};
_S_noto far S_noto_268_1 = {&var875,&var1010};
_S_noto far S_noto_325_1 = {&var923,&var1011};
_S_bolz far S_bolz_329_1 = {&iRM_2_,&var1014,&var1012};
_S_provsbr far S_provsbr_324_1 = {&var1074,&var735,&var1089,&var1106,&var1100,&var1095,&var1092,&var1090,&var1104,&var1099,&var1097,&var1093,&iRM_10_,array_m324_Tpr_1,array_m324_type_1,&var1013,&var1014,&var1015,&var1016,&var1017,&var1018,&var1019,&var1020,&var1021,NULL,array_m324_rz_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_orni far S_orni_328_1 = {array_m328_x_1,&iRM_5_,&vainSBool,&var1022};
_S_cntch far S_cntch_332_1 = {&var1022,&var1023,NULL};
_S_bolz far S_bolz_307_1 = {&iRM_20_,&var1037,&var1024};
_S_equz_p far S_equz_p_306_1 = {&var1036,&iRM_0_,&var1025};
_S_decatron far S_decatron_290_1 = {&var771,&var1026,NULL};
_S_noto far S_noto_984_1 = {NULL,&var1027};
_S_noto far S_noto_978_1 = {NULL,&var1028};
_S_andn far S_andn_263_1 = {array_m263_x_1,&iRM_7_,&var1029};
_S_noto far S_noto_265_1 = {NULL,&var1030};
_S_noto far S_noto_275_1 = {NULL,&var1031};
_S_noto far S_noto_269_1 = {NULL,&var1032};
_S_noto far S_noto_260_1 = {NULL,&var1033};
_S_noto far S_noto_257_1 = {NULL,&var1034};
_S_provsbr far S_provsbr_267_1 = {&var1076,&var788,&var1089,&var1106,&var1100,&var1095,&var1092,&var1090,&var1104,&var1099,&var1097,&var1093,&iRM_10_,array_m267_Tpr_1,array_m267_type_1,&var1035,&var1036,&var1037,&var1038,&var1039,&var1040,&var1041,&var1042,&var1043,NULL,array_m267_rz_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_rs far S_rs_1388_1 = {&var1045,&var546,&var1044,&vainSBool,NULL};
_S_provsbr far S_provsbr_1389_1 = {&var1044,NULL,&var1089,&var1106,&var1100,&var1095,&var1092,&var1090,&var1104,&var1099,&var1097,&var1093,&iRM_6_,array_m1389_Tpr_1,array_m1389_type_1,&var1045,&vainSInt,&vainSInt,&vainSBool,&var1046,&var1047,&var1048,&var1049,&var1050,NULL,array_m1389_rz_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_abs_subf far S_abs_subf_990_1 = {&var262,&var1694,NULL,&vainSFloat,&var1051};
_S_abs_subf far S_abs_subf_1003_1 = {&var1691,&var262,NULL,&vainSFloat,&var1052};
_S_noto far S_noto_644_1 = {&var739,&var1053};
_S_noto far S_noto_590_1 = {&var755,&var1054};
_S_noto far S_noto_49_1 = {&var258,&var1055};
_S_noto far S_noto_1007_1 = {&var1257,&var1056};
_S_rs far S_rs_1014_1 = {&var548,&var353,&var1057,&vainSBool,NULL};
_S_rs far S_rs_1011_1 = {&var552,&var547,&var1058,&vainSBool,NULL};
_S_rs far S_rs_1013_1 = {&var1056,&var353,&var1059,&vainSBool,NULL};
_S_rs far S_rs_1008_1 = {&var1056,&var550,&var1060,&vainSBool,NULL};
_S_noto far S_noto_579_1 = {NULL,&var1061};
_S_noto far S_noto_581_1 = {NULL,&var1062};
_S_noto far S_noto_25_1 = {NULL,&var1063};
_S_noto far S_noto_24_1 = {NULL,&var1064};
_S_noto far S_noto_23_1 = {NULL,&var1065};
_S_noto far S_noto_22_1 = {NULL,&var1066};
_S_newstage far S_newstage_591_1 = {&var75,&var72,NULL,NULL,&var1067};
_S_noto far S_noto_580_1 = {NULL,&var1068};
_S_noto far S_noto_578_1 = {NULL,&var1069};
_S_noto far S_noto_338_1 = {&var730,&var1070};
_S_noto far S_noto_342_1 = {&var729,&var1071};
_S_noto far S_noto_977_1 = {&var867,&var1072};
_S_rs far S_rs_741_1 = {&var727,&var335,&var1073,&vainSBool,NULL};
_S_rs far S_rs_334_1 = {&var731,&var732,&var1074,&vainSBool,NULL};
_S_rs far S_rs_330_1 = {&var733,&var734,&var1075,&vainSBool,NULL};
_S_rs far S_rs_287_1 = {&var787,&var773,&var1076,&vainSBool,NULL};
_S_orni far S_orni_283_1 = {array_m283_x_1,&iRM_5_,&vainSBool,&var1077};
_S_cntch far S_cntch_286_1 = {&var1077,&var1078,NULL};
_S_noto far S_noto_1427_1 = {&var1097,&var1079};
_S_noto far S_noto_1483_1 = {&var1099,&var1080};
_S_noto far S_noto_1485_1 = {&var1104,&var1081};
_S_noto far S_noto_1837_1 = {&var1090,&var1082};
_S_noto far S_noto_1871_1 = {&var1093,&var1083};
_S_noto far S_noto_1852_1 = {&var980,&var1084};
_S_noto far S_noto_1815_1 = {&var981,&var1085};
_S_noto far S_noto_1455_1 = {&var979,&var1086};
_S_noto far S_noto_1450_1 = {&var978,&var1087};
_S_noto far S_noto_1410_1 = {&var977,&var1088};
_S_rs far S_rs_1843_1 = {&var531,&var357,&var1089,&vainSBool,NULL};
_S_rs far S_rs_1831_1 = {&var372,&var369,&var1090,&vainSBool,NULL};
_S_rs far S_rs_1822_1 = {&var368,&var981,&var1091,&vainSBool,NULL};
_S_rs far S_rs_1897_1 = {&var531,&var386,&var1092,&vainSBool,NULL};
_S_rs far S_rs_1867_1 = {&var394,&var393,&var1093,&vainSBool,NULL};
_S_rs far S_rs_1857_1 = {&var396,&var980,&var1094,&vainSBool,NULL};
_S_rs far S_rs_1441_1 = {&var531,&var517,&var1095,&vainSBool,NULL};
_S_kvf far S_kvf_1428_1 = {&var1098,&var518,&fRM_0_0,&var1096,&vainSInt,&vainSInt,NULL,NULL,NULL};
_S_rs far S_rs_1424_1 = {&var523,&var518,&var1097,&vainSBool,NULL};
_S_rs far S_rs_1415_1 = {&var520,&var977,&var1098,&vainSBool,NULL};
_S_rs far S_rs_1474_1 = {&var513,&var508,&var1099,&vainSBool,NULL};
_S_rs far S_rs_1494_1 = {&var531,&var514,&var1100,&vainSBool,NULL};
_S_rs far S_rs_1460_1 = {&var511,&var978,&var1101,&vainSBool,NULL};
_S_kvf far S_kvf_1475_1 = {&var1101,&var508,&fRM_0_0,&var1102,&vainSInt,&vainSInt,NULL,NULL,NULL};
_S_cntch far S_cntch_1399_1 = {&var533,&var1103,NULL};
_S_rs far S_rs_1480_1 = {&var505,&var499,&var1104,&vainSBool,NULL};
_S_rs far S_rs_26_1 = {&var1153,&var927,&var1105,&vainSBool,NULL};
_S_rs far S_rs_1495_1 = {&var531,&var498,&var1106,&vainSBool,NULL};
_S_noto far S_noto_1377_1 = {&var527,&var1107};
_S_noto far S_noto_1375_1 = {&var926,&var1108};
_S_rs far S_rs_631_1 = {&var1488,&var742,&var1109,&vainSBool,NULL};
_S_rs far S_rs_616_1 = {&var1488,&var749,&var1110,&vainSBool,NULL};
_S_rs far S_rs_642_1 = {&var1488,&var750,&var1111,&vainSBool,NULL};
_S_rs far S_rs_627_1 = {&var1488,&var761,&var1112,&vainSBool,NULL};
_S_rs far S_rs_611_1 = {&var1488,&var764,&var1113,&vainSBool,NULL};
_S_rs far S_rs_609_1 = {&var1488,&var766,&var1114,&vainSBool,NULL};
_S_rs far S_rs_597_1 = {&var769,&var1491,&var1115,&vainSBool,NULL};
_S_rsun far S_rsun_1391_1 = {&var531,&var1241,&vainSLong,&var1116,NULL};
_S_noto far S_noto_1318_1 = {NULL,&var1117};
_S_noto far S_noto_1791_1 = {NULL,&var1118};
_S_noto far S_noto_1765_1 = {NULL,&var1119};
_S_noto far S_noto_110_1 = {&var926,&var1120};
_S_noto far S_noto_109_1 = {&var1125,&var1121};
_S_rs far S_rs_607_1 = {&var1488,&var768,&var1122,&vainSBool,NULL};
_S_orni far S_orni_1164_1 = {array_m1164_x_1,&iRM_6_,&var1123,&vainSLong};
_S_orni far S_orni_1152_1 = {array_m1152_x_1,&iRM_5_,&var1124,&vainSLong};
_S_rs far S_rs_108_1 = {&var868,&var922,&var1125,&vainSBool,NULL};
_S_noto far S_noto_1794_1 = {&var435,&var1126};
_S_noto far S_noto_1793_1 = {&var434,&var1127};
_S_noto far S_noto_1805_1 = {NULL,&var1128};
_S_noto far S_noto_1785_1 = {NULL,&var1129};
_S_newstage far S_newstage_1789_1 = {&var451,&var447,&var450,&var446,&vainSBool};
_S_noto far S_noto_1733_1 = {&var1219,&var1130};
_S_rs far S_rs_1625_1 = {&var194,&var222,&var1131,&vainSBool,NULL};
_S_rs far S_rs_1624_1 = {&var252,&var224,&var1132,&vainSBool,NULL};
_S_rs far S_rs_1623_1 = {&var194,&var226,&var1133,&vainSBool,NULL};
_S_rs far S_rs_1622_1 = {&var253,&var228,&var1134,&vainSBool,NULL};
_S_rs far S_rs_1651_1 = {&var197,&var230,&var1135,&vainSBool,NULL};
_S_rs far S_rs_1650_1 = {&var468,&var232,&var1136,&vainSBool,NULL};
_S_rs far S_rs_1649_1 = {&var197,&var234,&var1137,&vainSBool,NULL};
_S_rs far S_rs_1648_1 = {&var470,&var236,&var1138,&vainSBool,NULL};
_S_noto far S_noto_1217_1 = {NULL,&var1139};
_S_noto far S_noto_1202_1 = {NULL,&var1140};
_S_noto far S_noto_501_1 = {NULL,&var1141};
_S_ma far S_ma_1430_1 = {array_m1430_x_1,&var1116,&iRM_16_,&var1142};
_S_noto far S_noto_1385_1 = {&var783,&var1143};
_S_noto far S_noto_139_1 = {&var926,&var1144};
_S_equz_p far S_equz_p_1771_1 = {NULL,&iRM_5_,&var1145};
_S_equz_p far S_equz_p_1770_1 = {NULL,&iRM_4_,&var1146};
_S_equz_p far S_equz_p_1769_1 = {NULL,&iRM_3_,&var1147};
_S_equz_p far S_equz_p_1767_1 = {NULL,&iRM_1_,&vainSBool};
_S_equz_p far S_equz_p_1768_1 = {NULL,&iRM_2_,&var1148};
_S_noto far S_noto_1824_1 = {NULL,&var1149};
_S_noto far S_noto_1819_1 = {NULL,&var1150};
_S_noto far S_noto_1861_1 = {NULL,&var1151};
_S_noto far S_noto_1868_1 = {NULL,&var1152};
_S_noto far S_noto_12_1 = {&var1610,&var1153};
_S_rs far S_rs_1928_1 = {&var320,&var421,&var1154,&vainSBool,NULL};
_S_rs far S_rs_1708_1 = {&var463,&var247,&var1155,&vainSBool,NULL};
_S_rs far S_rs_1707_1 = {&var207,&var248,&var1156,&vainSBool,NULL};
_S_rs far S_rs_1705_1 = {&var464,&var249,&var1157,&vainSBool,NULL};
_S_rs far S_rs_1704_1 = {&var207,&var250,&var1158,&vainSBool,NULL};
_S_rs far S_rs_1702_1 = {&var465,&var251,&var1159,&vainSBool,NULL};
_S_equz_p far S_equz_p_98_1 = {NULL,&iRM_10_,&var1160};
_S_noto far S_noto_177_1 = {NULL,&var1161};
_S_rs far S_rs_2121_1 = {&var10,&var16,&var1162,&vainSBool,NULL};
_S_rs far S_rs_2118_1 = {&var466,&var62,&var1163,&vainSBool,NULL};
_S_rs far S_rs_1677_1 = {&var467,&var244,&var1164,&vainSBool,NULL};
_S_rs far S_rs_1671_1 = {&var197,&var229,&var1165,&vainSBool,NULL};
_S_rs far S_rs_1670_1 = {&var194,&var230,&var1166,&vainSBool,NULL};
_S_rs far S_rs_1666_1 = {&var469,&var232,&var1167,&vainSBool,NULL};
_S_rs far S_rs_1668_1 = {&var468,&var231,&var1168,&vainSBool,NULL};
_S_rs far S_rs_1665_1 = {&var197,&var233,&var1169,&vainSBool,NULL};
_S_rs far S_rs_1664_1 = {&var194,&var234,&var1170,&vainSBool,NULL};
_S_rs far S_rs_1660_1 = {&var471,&var236,&var1171,&vainSBool,NULL};
_S_rs far S_rs_1662_1 = {&var470,&var235,&var1172,&vainSBool,NULL};
_S_rs far S_rs_19_1 = {&var879,&var341,&var1173,&vainSBool,NULL};
_S_equz_p far S_equz_p_97_1 = {NULL,&iRM_9_,&var1174};
_S_equz_p far S_equz_p_96_1 = {NULL,&iRM_8_,&var1175};
_S_noto far S_noto_921_1 = {NULL,&var1176};
_S_equz_p far S_equz_p_95_1 = {NULL,&iRM_7_,&var1177};
_S_equz_p far S_equz_p_94_1 = {NULL,&iRM_6_,&var1178};
_S_equz_p far S_equz_p_93_1 = {NULL,&iRM_5_,&var1179};
_S_rs far S_rs_1645_1 = {&var194,&var221,&var1180,&vainSBool,NULL};
_S_rs far S_rs_1643_1 = {&var76,&var222,&var1181,&vainSBool,NULL};
_S_rs far S_rs_1640_1 = {&var481,&var224,&var1182,&vainSBool,NULL};
_S_rs far S_rs_1642_1 = {&var252,&var223,&var1183,&vainSBool,NULL};
_S_rs far S_rs_1639_1 = {&var194,&var225,&var1184,&vainSBool,NULL};
_S_rs far S_rs_1637_1 = {&var77,&var226,&var1185,&vainSBool,NULL};
_S_rs far S_rs_2044_1 = {&var79,&var430,&var1186,&vainSBool,NULL};
_S_rs far S_rs_2039_1 = {&var80,&var431,&var1187,&vainSBool,NULL};
_S_equz_p far S_equz_p_296_1 = {&var1026,&iRM_0_,&var1188};
_S_noto far S_noto_2045_1 = {&var1186,&var1189};
_S_noto far S_noto_2035_1 = {&var345,&var1190};
_S_noto far S_noto_2019_1 = {&var1192,&var1191};
_S_rs far S_rs_2018_1 = {&var12,&var427,&var1192,&vainSBool,NULL};
_S_noto far S_noto_2007_1 = {&var1194,&var1193};
_S_rs far S_rs_2006_1 = {&var14,&var424,&var1194,&vainSBool,NULL};
_S_noto far S_noto_2040_1 = {&var1187,&var1195};
_S_noto far S_noto_2031_1 = {&var344,&var1196};
_S_noto far S_noto_1940_1 = {&var1198,&var1197};
_S_rs far S_rs_1939_1 = {&var319,&var422,&var1198,&vainSBool,NULL};
_S_noto far S_noto_1929_1 = {&var1154,&var1199};
_S_noto far S_noto_1935_1 = {&var342,&var1200};
_S_noto far S_noto_1923_1 = {&var343,&var1201};
_S_rs far S_rs_1634_1 = {&var482,&var228,&var1202,&vainSBool,NULL};
_S_rs far S_rs_1636_1 = {&var253,&var227,&var1203,&vainSBool,NULL};
_S_rs far S_rs_1621_1 = {&var194,&var213,&var1204,&vainSBool,NULL};
_S_rs far S_rs_1619_1 = {&var483,&var214,&var1205,&vainSBool,NULL};
_S_rs far S_rs_1618_1 = {&var194,&var215,&var1206,&vainSBool,NULL};
_S_rs far S_rs_1616_1 = {&var484,&var216,&var1207,&vainSBool,NULL};
_S_noto far S_noto_1728_1 = {NULL,&var1208};
_S_noto far S_noto_1727_1 = {NULL,&var1209};
_S_noto far S_noto_1726_1 = {NULL,&var1210};
_S_noto far S_noto_1725_1 = {NULL,&var1211};
_S_noto far S_noto_1724_1 = {NULL,&var1212};
_S_noto far S_noto_1723_1 = {NULL,&var1213};
_S_noto far S_noto_1753_1 = {NULL,&var1214};
_S_noto far S_noto_1747_1 = {NULL,&var1215};
_S_noto far S_noto_1752_1 = {NULL,&var1216};
_S_noto far S_noto_1750_1 = {NULL,&var1217};
_S_noto far S_noto_1751_1 = {NULL,&var1218};
_S_andn far S_andn_1736_1 = {array_m1736_x_1,&iRM_17_,&var1219};
_S_noto far S_noto_1745_1 = {NULL,&var1220};
_S_noto far S_noto_1746_1 = {NULL,&var1221};
_S_noto far S_noto_1744_1 = {NULL,&var1222};
_S_rs far S_rs_1615_1 = {&var1227,&var217,&var1223,&vainSBool,NULL};
_S_rs far S_rs_1613_1 = {&var485,&var218,&var1224,&vainSBool,NULL};
_S_rs far S_rs_1612_1 = {&var1227,&var219,&var1225,&vainSBool,NULL};
_S_rs far S_rs_1610_1 = {&var486,&var220,&var1226,&vainSBool,NULL};
_S_newstage far S_newstage_2065_1 = {&var1239,&var1233,&var1238,&var1232,&var1227};
_S_samhd far S_samhd_2067_1 = {&var489,&var490,&var490,&var1224,&var1223,&var1224,&var1223,NULL,NULL,NULL,NULL,&bRM_1_,NULL,NULL,NULL,&var1228,&var1229,&vainSBool,&var1230,&var1231,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1232,&var1233,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_samhd far S_samhd_2061_1 = {&var489,&var491,&var491,&var1226,&var1225,&var1226,&var1225,NULL,NULL,NULL,NULL,&bRM_1_,NULL,NULL,NULL,&var1234,&var1235,&vainSBool,&var1236,&var1237,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1238,&var1239,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_orni far S_orni_1392_1 = {array_m1392_x_1,&iRM_5_,&var1240,&var1241};
_S_noto far S_noto_77_1 = {&var347,&var1242};
_S_maz far S_maz_302_1 = {array_m302_x_1,NULL,&iRM_3_,&var1243};
_S_maz far S_maz_293_1 = {array_m293_x_1,NULL,&iRM_3_,&var1244};
_S_rs far S_rs_1465_1 = {&var502,&var979,&var1245,&vainSBool,NULL};
_S_kvf far S_kvf_1469_1 = {&var1245,&var499,&fRM_0_0,&var1246,&vainSInt,&vainSInt,NULL,NULL,NULL};
_S_kvf far S_kvf_1879_1 = {&var402,&var390,&fRM_0_0,&var1247,&vainSInt,&vainSInt,NULL,NULL,NULL};
_S_kvf far S_kvf_1840_1 = {&var362,&var359,&fRM_0_0,&var1248,&vainSInt,&vainSInt,NULL,NULL,NULL};
_S_equz_p far S_equz_p_37_1 = {NULL,&iRM_1_,&var1249};
_S_noto far S_noto_34_1 = {&var1252,&var1250};
_S_equz_p far S_equz_p_41_1 = {NULL,&iRM_2_,&var1251};
_S_equz_p far S_equz_p_32_1 = {NULL,&iRM_3_,&var1252};
_S_noto far S_noto_1881_1 = {&var1094,&var1253};
_S_rs far S_rs_278_1 = {&var789,&var790,&var1254,&vainSBool,NULL};
_S_orn far S_orn_588_1 = {array_m588_x_1,&iRM_5_,&var1255};
_S_noto far S_noto_997_1 = {NULL,&var1256};
_S_rs far S_rs_988_1 = {&var566,&var882,&var1257,&vainSBool,NULL};
_S_rs far S_rs_619_1 = {&var744,&var746,&var1258,&vainSBool,NULL};
_S_noto far S_noto_1372_1 = {&var925,&var1259};
_S_orn far S_orn_1351_1 = {array_m1351_x_1,&iRM_8_,&var1260};
_S_noto far S_noto_1350_1 = {&var1428,&var1261};
_S_noto far S_noto_1349_1 = {&var1438,&var1262};
_S_noto far S_noto_1331_1 = {&var926,&var1263};
_S_noto far S_noto_1341_1 = {NULL,&var1264};
_S_charint far S_charint_1278_1 = {&var1267,&var1265};
_S_ornc far S_ornc_1286_1 = {array_m1286_x_1,&iRM_3_,&var1266,&var1267};
_S_fsumz far S_fsumz_1279_1 = {&var1265,&iRM_1_,&var1268};
_S_cnshd far S_cnshd_1288_1 = {NULL,&var1697,&var956,&var266,&var1266,&var611,&var607,&iRM_1_,array_m1288_Lt_fw_1,array_m1288_Vr_fw_1,&iRM_1_,array_m1288_Lt_bw_1,array_m1288_Vr_bw_1,NULL,NULL,NULL,NULL,&var1269,&vainSBool,&var1270,&var1271,&var1272,&var1273,&var1274,&var1275,&var1276,&var1277,&var1278,&var1279,NULL,NULL,NULL};
_S_zpfs far S_zpfs_1307_1 = {&var1288,&fRM_2_0,&var1280,NULL,NULL};
_S_zpfs far S_zpfs_1310_1 = {&var1287,&fRM_3_0,&var1281,NULL,NULL};
_S_fnapb far S_fnapb_1316_1 = {&var1697,&var956,&var610,NULL,&var1271,&var1278,NULL,NULL,NULL,NULL,NULL,&iRM_60_,NULL,NULL,NULL,&var1282,&var1283,&var1284,&var1285,&var1286,&var1287,&var1288,&vainSFloat,NULL,array_m1316_x0_1,array_m1316_tim0_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_newstage far S_newstage_898_1 = {&var1298,&var1266,&var1301,&var1269,&var1289};
_S_rs far S_rs_617_1 = {&var745,&var749,&var1290,&vainSBool,NULL};
_S_noto far S_noto_975_1 = {&var910,&var1291};
_S_orn far S_orn_954_1 = {array_m954_x_1,&iRM_8_,&var1292};
_S_noto far S_noto_953_1 = {&var1428,&var1293};
_S_noto far S_noto_952_1 = {&var1438,&var1294};
_S_noto far S_noto_935_1 = {&var926,&var1295};
_S_noto far S_noto_944_1 = {NULL,&var1296};
_S_charint far S_charint_876_1 = {&var1299,&var1297};
_S_ornc far S_ornc_884_1 = {array_m884_x_1,&iRM_3_,&var1298,&var1299};
_S_fsumz far S_fsumz_877_1 = {&var1297,&iRM_1_,&var1300};
_S_cnshd far S_cnshd_886_1 = {NULL,&var1700,&var955,&var270,&var1298,&var646,&var647,&iRM_1_,array_m886_Lt_fw_1,array_m886_Vr_fw_1,&iRM_1_,array_m886_Lt_bw_1,array_m886_Vr_bw_1,NULL,NULL,NULL,NULL,&var1301,&vainSBool,&var1302,&var1303,&var1304,&var1305,&var1306,&var1307,&var1308,&var1309,&var1310,&var1311,NULL,NULL,NULL};
_S_zpfs far S_zpfs_910_1 = {&var1320,&fRM_2_0,&var1312,NULL,NULL};
_S_zpfs far S_zpfs_911_1 = {&var1319,&fRM_3_0,&var1313,NULL,NULL};
_S_fnapb far S_fnapb_919_1 = {&var1700,&var955,&var645,NULL,&var1303,&var1310,NULL,NULL,NULL,NULL,NULL,&iRM_60_,NULL,NULL,NULL,&var1314,&var1315,&var1316,&var1317,&var1318,&var1319,&var1320,&vainSFloat,NULL,array_m919_x0_1,array_m919_tim0_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_noto far S_noto_570_1 = {&var925,&var1321};
_S_noto far S_noto_543_1 = {&var1428,&var1322};
_S_noto far S_noto_542_1 = {&var1438,&var1323};
_S_noto far S_noto_527_1 = {&var926,&var1324};
_S_noto far S_noto_534_1 = {NULL,&var1325};
_S_charint far S_charint_479_1 = {&var1328,&var1326};
_S_ornc far S_ornc_485_1 = {array_m485_x_1,&iRM_3_,&var1327,&var1328};
_S_fsumz far S_fsumz_480_1 = {&var1326,&iRM_1_,&var1329};
_S_cnshd far S_cnshd_488_1 = {NULL,&var1710,&var957,&var274,&var1327,&var717,&var711,&iRM_2_,array_m488_Lt_fw_1,array_m488_Vr_fw_1,&iRM_1_,array_m488_Lt_bw_1,array_m488_Vr_bw_1,NULL,NULL,NULL,NULL,&var1330,&vainSBool,&var1331,&var1332,&var1333,&var1334,&var1335,&var1336,&var1337,&var1338,&var1339,&var1340,NULL,NULL,NULL};
_S_zpfs far S_zpfs_508_1 = {&var1349,&fRM_2_0,&var1341,NULL,NULL};
_S_zpfs far S_zpfs_511_1 = {&var1348,&fRM_3_0,&var1342,NULL,NULL};
_S_fnapb far S_fnapb_515_1 = {&var1710,&var957,&var715,NULL,&var1332,&var1339,NULL,NULL,NULL,NULL,NULL,&iRM_150_,NULL,NULL,NULL,&var1343,&var1344,&var1345,&var1346,&var1347,&var1348,&var1349,&vainSFloat,NULL,array_m515_x0_1,array_m515_tim0_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_noto far S_noto_635_1 = {NULL,&var1350};
_S_noto far S_noto_256_1 = {&var910,&var1351};
_S_newstage far S_newstage_204_1 = {&var1360,&var1327,&var1363,&var1330,&var1352};
_S_rs far S_rs_614_1 = {&var740,&var752,&var1353,&vainSBool,NULL};
_S_orn far S_orn_227_1 = {array_m227_x_1,&iRM_12_,&var1354};
_S_noto far S_noto_226_1 = {&var1428,&var1355};
_S_noto far S_noto_225_1 = {&var1438,&var1356};
_S_noto far S_noto_210_1 = {&var926,&var1357};
_S_noto far S_noto_217_1 = {NULL,&var1358};
_S_charint far S_charint_156_1 = {&var1361,&var1359};
_S_ornc far S_ornc_164_1 = {array_m164_x_1,&iRM_3_,&var1360,&var1361};
_S_fsumz far S_fsumz_157_1 = {&var1359,&iRM_1_,&var1362};
_S_cnshd far S_cnshd_167_1 = {NULL,&var1688,&var958,&var278,&var1360,&var697,&var690,&iRM_2_,array_m167_Lt_fw_1,array_m167_Vr_fw_1,&iRM_1_,array_m167_Lt_bw_1,array_m167_Vr_bw_1,NULL,NULL,NULL,NULL,&var1363,&vainSBool,&var1364,&var1365,&var1366,&var1367,&var1368,&var1369,&var1370,&var1371,&var1372,&var1373,NULL,NULL,NULL};
_S_fnapb far S_fnapb_196_1 = {&var1688,&var958,&var693,NULL,&var1365,&var1372,NULL,NULL,NULL,NULL,NULL,&iRM_150_,NULL,NULL,NULL,&var1374,&var1375,&var1376,&var1377,&var1378,&var1379,&var1380,&vainSFloat,NULL,array_m196_x0_1,array_m196_tim0_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_rs far S_rs_640_1 = {&var751,&var754,&var1381,&vainSBool,NULL};
_S_newstage far S_newstage_455_1 = {&var1400,&var1391,&var1399,&var1390,&var1382};
_S_samhd far S_samhd_459_1 = {NULL,&var720,&var720,&var329,&var328,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_0_,NULL,NULL,NULL,&var1383,&var1384,&var1385,&var1386,&var1387,&var1388,&vainSBool,&vainSBool,&var1389,&var1390,&var1391,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_samhd far S_samhd_453_1 = {NULL,&var721,&var721,&var327,&var326,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_0_,NULL,NULL,NULL,&var1392,&var1393,&var1394,&var1395,&var1396,&var1397,&vainSBool,&vainSBool,&var1398,&var1399,&var1400,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_orn far S_orn_859_1 = {array_m859_x_1,&iRM_10_,&var1401};
_S_noto far S_noto_858_1 = {&var1428,&var1402};
_S_noto far S_noto_857_1 = {&var1438,&var1403};
_S_noto far S_noto_838_1 = {&var926,&var1404};
_S_noto far S_noto_849_1 = {NULL,&var1405};
_S_charint far S_charint_796_1 = {&var1408,&var1406};
_S_ornc far S_ornc_802_1 = {array_m802_x_1,&iRM_3_,&var1407,&var1408};
_S_fsumz far S_fsumz_797_1 = {&var1406,&iRM_1_,&var1409};
_S_cnshd far S_cnshd_806_1 = {NULL,&var1703,&var954,&var954,&var1407,&var670,&var584,&iRM_2_,array_m806_Lt_fw_1,array_m806_Vr_fw_1,&iRM_1_,array_m806_Lt_bw_1,array_m806_Vr_bw_1,NULL,NULL,NULL,NULL,&var1410,&vainSBool,&var1411,&var1412,&var1413,&var1414,&var1415,&var1416,&var1417,&var1418,&var1419,&var1420,NULL,NULL,NULL};
_S_fnapb far S_fnapb_826_1 = {&var1703,&var954,&var666,NULL,&var1412,&var1419,NULL,NULL,NULL,NULL,NULL,&iRM_80_,NULL,NULL,NULL,&var1421,&var1422,&var1423,&var1424,&var1425,&var1426,&var1427,&vainSFloat,NULL,array_m826_x0_1,array_m826_tim0_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_cnshd far S_cnshd_1570_1 = {NULL,&var1694,&var262,&var262,&var493,&var496,&lRM_1_,&iRM_1_,array_m1570_Lt_fw_1,array_m1570_Vr_fw_1,&iRM_1_,array_m1570_Lt_bw_1,array_m1570_Vr_bw_1,NULL,NULL,NULL,&fRM_0_0,&var1428,&vainSBool,&vainSFloat,&var1429,&var1430,&var1431,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1432,NULL,NULL,NULL};
_S_newstage far S_newstage_1231_1 = {&var1446,&var1407,&var1451,&var1410,&var1433};
_S_orn far S_orn_1261_1 = {array_m1261_x_1,&iRM_10_,&var1434};
_S_orn far S_orn_145_1 = {array_m145_x_1,&iRM_5_,&var1435};
_S_noto far S_noto_1260_1 = {&var1428,&var1436};
_S_noto far S_noto_1259_1 = {&var1438,&var1437};
_S_cnshd far S_cnshd_1109_1 = {NULL,&var1691,&var262,&var262,&var811,&var494,&lRM_1_,&iRM_1_,array_m1109_Lt_fw_1,array_m1109_Vr_fw_1,&iRM_1_,array_m1109_Lt_bw_1,array_m1109_Vr_bw_1,NULL,NULL,NULL,&fRM_0_0,&var1438,&vainSBool,&vainSFloat,&var1439,&var1440,&var1441,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1442,NULL,NULL,NULL};
_S_noto far S_noto_1242_1 = {&var926,&var1443};
_S_noto far S_noto_1251_1 = {NULL,&var1444};
_S_charint far S_charint_1181_1 = {&var1447,&var1445};
_S_ornc far S_ornc_1190_1 = {array_m1190_x_1,&iRM_3_,&var1446,&var1447};
_S_noto far S_noto_599_1 = {NULL,&var1448};
_S_fsumz far S_fsumz_1182_1 = {&var1445,&iRM_1_,&var1449};
_S_rs far S_rs_612_1 = {&var762,&var764,&var1450,&vainSBool,NULL};
_S_cnshd far S_cnshd_1191_1 = {NULL,&var1706,&var953,&var953,&var1446,&var587,&var580,&iRM_2_,array_m1191_Lt_fw_1,array_m1191_Vr_fw_1,&iRM_1_,array_m1191_Lt_bw_1,array_m1191_Vr_bw_1,NULL,NULL,NULL,NULL,&var1451,&vainSBool,&var1452,&var1453,&var1454,&var1455,&var1456,&var1457,&var1458,&var1459,&var1460,&var1461,NULL,NULL,NULL};
_S_zpfs far S_zpfs_1211_1 = {&var1470,&fRM_2_0,&var1462,NULL,NULL};
_S_zpfs far S_zpfs_1219_1 = {&var1469,&fRM_3_0,&var1463,NULL,NULL};
_S_fnapb far S_fnapb_1226_1 = {&var1706,&var953,&var588,NULL,&var1453,&var1460,NULL,NULL,NULL,NULL,NULL,&iRM_80_,NULL,NULL,NULL,&var1464,&var1465,&var1466,&var1467,&var1468,&var1469,&var1470,&vainSFloat,NULL,array_m1226_x0_1,array_m1226_tim0_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_noto far S_noto_1555_1 = {NULL,&var1471};
_S_rs far S_rs_632_1 = {&var765,&var766,&var1472,&vainSBool,NULL};
_S_zpfs far S_zpfs_1583_1 = {&var1483,&fRM_2_0,&var1473,NULL,NULL};
_S_zpfs far S_zpfs_1586_1 = {&var1482,&fRM_3_0,&var1474,NULL,NULL};
_S_samhd far S_samhd_1573_1 = {NULL,&var496,&var496,&var1430,&var1431,&var1477,&var1478,NULL,NULL,NULL,NULL,&bRM_3_,NULL,NULL,NULL,&vainSBool,&vainSBool,&var1475,&var1476,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_fnapb far S_fnapb_1590_1 = {&var1694,&var262,&var492,NULL,&var1429,NULL,NULL,NULL,NULL,NULL,NULL,&iRM_20_,NULL,NULL,NULL,&var1477,&var1478,&var1479,&var1480,&var1481,&var1482,&var1483,&vainSFloat,NULL,array_m1590_x0_1,array_m1590_tim0_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_zpfs far S_zpfs_1122_1 = {&var1500,&fRM_2_0,&var1484,NULL,NULL};
_S_zpfs far S_zpfs_1126_1 = {&var1499,&fRM_3_0,&var1485,NULL,NULL};
_S_noto far S_noto_1091_1 = {NULL,&var1486};
_S_orn far S_orn_1077_1 = {array_m1077_x_1,&iRM_8_,&var1487};
_S_noto far S_noto_601_1 = {&var1491,&var1488};
_S_rs far S_rs_622_1 = {&var767,&var768,&var1489,&vainSBool,NULL};
_S_orn far S_orn_589_1 = {array_m589_x_1,&iRM_18_,&var1490};
_S_rs far S_rs_587_1 = {&var1255,&var883,&var1491,&vainSBool,NULL};
_S_samhd far S_samhd_1113_1 = {NULL,&var494,&var494,&var1440,&var1441,&var1494,&var1495,&var101,&var101,&var100,&var100,&bRM_3_,NULL,NULL,NULL,&vainSBool,&vainSBool,&var1492,&var1493,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_fnapb far S_fnapb_1130_1 = {&var1691,&var262,&var810,NULL,&var1439,NULL,NULL,NULL,NULL,NULL,NULL,&iRM_20_,NULL,NULL,NULL,&var1494,&var1495,&var1496,&var1497,&var1498,&var1499,&var1500,&vainSFloat,NULL,array_m1130_x0_1,array_m1130_tim0_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_noto far S_noto_712_1 = {NULL,&var1501};
_S_vmemb far S_vmemb_735_1 = {&var1503,&var1502,NULL};
_S_noto far S_noto_743_1 = {&var102,&var1503};
_S_vmemb far S_vmemb_704_1 = {&var1501,&var1504,NULL};
_S_vmemb far S_vmemb_667_1 = {&var1519,&var1505,NULL};
_S_newstage far S_newstage_778_1 = {&var1563,&var1554,&var1562,&var1553,&var1506};
_S_newstage far S_newstage_1163_1 = {&var1545,&var1536,&var1544,&var1535,&var1507};
_S_newstage far S_newstage_384_1 = {&var1590,&var1581,&var1589,&var1580,&var1508};
_S_noto far S_noto_754_1 = {&var103,&var1509};
_S_rs far S_rs_760_1 = {&var831,&var1508,&var1510,&vainSBool,NULL};
_S_rs far S_rs_755_1 = {&var832,&var932,&var1511,&vainSBool,NULL};
_S_noto far S_noto_747_1 = {&var1592,&var1512};
_S_noto far S_noto_745_1 = {&var1593,&var1513};
_S_rs far S_rs_723_1 = {&var836,&var1508,&var1514,&vainSBool,NULL};
_S_rs far S_rs_728_1 = {&var835,&var1506,&var1515,&vainSBool,NULL};
_S_rs far S_rs_736_1 = {&var902,&var841,&var1516,&vainSBool,NULL};
_S_rs far S_rs_748_1 = {&var833,&var839,&var1517,&vainSBool,NULL};
_S_noto far S_noto_703_1 = {&var103,&var1518};
_S_noto far S_noto_659_1 = {&var102,&var1519};
_S_noto far S_noto_415_1 = {NULL,&var1520};
_S_orn far S_orn_429_1 = {array_m429_x_1,&iRM_7_,&var1521};
_S_orn far S_orn_411_1 = {array_m411_x_1,&iRM_7_,&var1522};
_S_rs far S_rs_726_1 = {&var840,&var845,&var1523,&vainSBool,NULL};
_S_noto far S_noto_153_1 = {NULL,&var1524};
_S_noto far S_noto_142_1 = {NULL,&var1525};
_S_noto far S_noto_143_1 = {NULL,&var1526};
_S_noto far S_noto_151_1 = {NULL,&var1527};
_S_samhd far S_samhd_1167_1 = {&var814,&var815,&var815,&var1124,&var1123,&var1124,&var1123,NULL,NULL,NULL,NULL,&bRM_1_,NULL,NULL,NULL,&var1528,&var1529,&vainSBool,&var1530,&var1531,&vainSBool,&var1532,&var1533,&var1534,&var1535,&var1536,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_samhd far S_samhd_1157_1 = {&var814,&var817,&var817,&var1124,&var1123,&var1124,&var1123,NULL,NULL,NULL,NULL,&bRM_1_,NULL,NULL,NULL,&var1537,&var1538,&vainSBool,&var1539,&var1540,&vainSBool,&var1541,&var1542,&var1543,&var1544,&var1545,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_samhd far S_samhd_780_1 = {NULL,&var672,&var672,&var933,&var828,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_0_,NULL,NULL,NULL,&var1546,&var1547,&var1548,&var1549,&var1550,&var1551,&vainSBool,&vainSBool,&var1552,&var1553,&var1554,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_samhd far S_samhd_776_1 = {NULL,&var674,&var674,&var933,&var828,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_0_,NULL,NULL,NULL,&var1555,&var1556,&var1557,&var1558,&var1559,&var1560,&vainSBool,&vainSBool,&var1561,&var1562,&var1563,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_samhd far S_samhd_358_1 = {NULL,&var331,&var330,&var837,&var830,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_0_,NULL,NULL,NULL,&var1564,&var1565,&var1566,&var1567,&var1568,&var1569,&vainSBool,&vainSBool,&var1570,&var1571,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_noto far S_noto_670_1 = {NULL,&var1572};
_S_samhd far S_samhd_387_1 = {NULL,&var1521,&var903,&var909,&var829,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_0_,NULL,NULL,NULL,&var1573,&var1574,&var1575,&var1576,&var1577,&var1578,&vainSBool,&vainSBool,&var1579,&var1580,&var1581,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_samhd far S_samhd_381_1 = {NULL,&var1522,&var904,&var909,&var829,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_0_,NULL,NULL,NULL,&var1582,&var1583,&var1584,&var1585,&var1586,&var1587,&vainSBool,&vainSBool,&var1588,&var1589,&var1590,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_orn far S_orn_759_1 = {array_m759_x_1,&iRM_17_,&var1591};
_S_rs far S_rs_732_1 = {&var843,&var5,&var1592,&vainSBool,NULL};
_S_rs far S_rs_729_1 = {&var844,&var6,&var1593,&vainSBool,NULL};
_S_orni far S_orni_131_1 = {array_m131_x_1,&iRM_21_,&var1594,&vainSLong};
_S_equz_p far S_equz_p_74_1 = {NULL,&iRM_6_,&var1595};
_S_equz_p far S_equz_p_72_1 = {NULL,&iRM_5_,&var1596};
_S_equz_p far S_equz_p_70_1 = {NULL,&iRM_4_,&var1597};
_S_equz_p far S_equz_p_69_1 = {NULL,&iRM_3_,&var1598};
_S_equz_p far S_equz_p_68_1 = {NULL,&iRM_2_,&var1599};
_S_equz_p far S_equz_p_65_1 = {NULL,&iRM_1_,&var1600};
_S_equz_p far S_equz_p_61_1 = {NULL,&iRM_3_,&var1601};
_S_equz_p far S_equz_p_55_1 = {NULL,&iRM_1_,&vainSBool};
_S_equz_p far S_equz_p_57_1 = {NULL,&iRM_2_,&var1602};
_S_equz_p far S_equz_p_50_1 = {NULL,&iRM_3_,&var1603};
_S_equz_p far S_equz_p_43_1 = {NULL,&iRM_1_,&var1604};
_S_equz_p far S_equz_p_46_1 = {NULL,&iRM_2_,&var1605};
_S_equz_p far S_equz_p_99_1 = {NULL,&iRM_11_,&var1606};
_S_equz_p far S_equz_p_92_1 = {NULL,&iRM_4_,&var1607};
_S_equz_p far S_equz_p_91_1 = {NULL,&iRM_3_,&var1608};
_S_equz_p far S_equz_p_90_1 = {NULL,&iRM_2_,&var1609};
_S_equz_p far S_equz_p_10_1 = {NULL,&iRM_4_,&var1610};
_S_equz_p far S_equz_p_7_1 = {NULL,&iRM_3_,&var1611};
_S_equz_p far S_equz_p_2_1 = {NULL,&iRM_1_,&var1612};
_S_equz_p far S_equz_p_4_1 = {NULL,&iRM_2_,&var1613};


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
  equz_p((&S_equz_p_18_2));
  andn((&S_andn_131_2));
  noto((&S_noto_134_2));
  andn((&S_andn_150_2));
  noto((&S_noto_153_2));
  scalzz((&S_scalzz_185_2));
  scalzz((&S_scalzz_187_2));
  or2((&S_or2_11_2));
  or2((&S_or2_42_2));
  or2((&S_or2_13_2));
  or2((&S_or2_43_2));
  or2((&S_or2_74_2));
  or2((&S_or2_71_2));
  and3((&S_and3_79_2));
  or2((&S_or2_103_2));
  or2((&S_or2_104_2));
  and3((&S_and3_110_2));
  and4((&S_and4_136_2));
  and4((&S_and4_159_2));
  schl24((&S_schl24_143_2));
  schl24((&S_schl24_149_2));
  noto((&S_noto_229_2));
  noto((&S_noto_230_2));
  noto((&S_noto_231_2));
  noto((&S_noto_249_2));
  noto((&S_noto_250_2));
  noto((&S_noto_251_2));
  fsumo((&S_fsumo_222_2));
  bol((&S_bol_223_2));
  lkb((&S_lkb_80_2));
  lkb((&S_lkb_111_2));
  and4((&S_and4_106_2));
  enctkb((&S_enctkb_75_2));
  enctkb((&S_enctkb_112_2));
  drg((&S_drg_196_2));
  drg((&S_drg_189_2));
  geterr((&S_geterr_188_2));
  drg((&S_drg_204_2));
  drg((&S_drg_199_2));
  geterr((&S_geterr_191_2));
  tprg((&S_tprg_210_2));
  tprg((&S_tprg_214_2));
  noto((&S_noto_220_2));
  noto((&S_noto_212_2));
  andn((&S_andn_170_2));
  noto((&S_noto_171_2));
  and2((&S_and2_219_2));
  and3((&S_and3_19_2));
  and3((&S_and3_45_2));
  and3((&S_and3_23_2));
  and3((&S_and3_49_2));
  and3((&S_and3_82_2));
  or3((&S_or3_135_2));
  or3((&S_or3_158_2));
  and2((&S_and2_213_2));
  or2((&S_or2_195_2));
  or2((&S_or2_198_2));
  lkb((&S_lkb_20_2));
  lkb((&S_lkb_24_2));
  lkb((&S_lkb_46_2));
  lkb((&S_lkb_83_2));
  lkb((&S_lkb_50_2));
  lkb((&S_lkb_107_2));
  enctkb((&S_enctkb_21_2));
  enctkb((&S_enctkb_51_2));
  enctkb((&S_enctkb_47_2));
  enctkb((&S_enctkb_77_2));
  enctkb((&S_enctkb_108_2));
  enctkb((&S_enctkb_16_2));
  noto((&S_noto_141_2));
  noto((&S_noto_157_2));
  and2((&S_and2_233_2));
  and2((&S_and2_254_2));
  ornc((&S_ornc_124_2));
  ornc((&S_ornc_234_2));
  ornc((&S_ornc_255_2));
  noto((&S_noto_240_2));
  noto((&S_noto_256_2));
  or2((&S_or2_258_2));
  ornc((&S_ornc_232_2));
  ornc((&S_ornc_242_2));
  noto((&S_noto_235_2));
  noto((&S_noto_253_2));
  or2((&S_or2_243_2));
  signal_R0EE02LDU.b = var781.b;
  signal_R0EE02LDU.error = var781.error;
  fplet(&signal_B8VC01RDU.f,&var1691.f);
  signal_B8VC01RDU.error = var1691.error;
  fplet(&signal_B2VC01RDU.f,&var1703.f);
  signal_B2VC01RDU.error = var1703.error;
  fplet(&signal_A2VC01RDU.f,&var1706.f);
  signal_A2VC01RDU.error = var1706.error;
  fplet(&signal_A3VC01RDU.f,&var1700.f);
  signal_A3VC01RDU.error = var1700.error;
  signal_B0VS11LDU.b = var1668.b;
  signal_B0VS11LDU.error = var1668.error;
  signal_A0VS11LDU.b = var1669.b;
  signal_A0VS11LDU.error = var1669.error;
  signal_B0VN01LDU.b = var1638.b;
  signal_B0VN01LDU.error = var1638.error;
  signal_A0VN01LDU.b = var1640.b;
  signal_A0VN01LDU.error = var1640.error;
  signal_B0VP01LDU.b = var1674.b;
  signal_B0VP01LDU.error = var1674.error;
  signal_A0VP01LDU.b = var1675.b;
  signal_A0VP01LDU.error = var1675.error;
  signal_B0VE01LDU.b = var1665.b;
  signal_B0VE01LDU.error = var1665.error;
  signal_A0VE01LDU.b = var1667.b;
  signal_A0VE01LDU.error = var1667.error;
  signal_A3VP82LDU.b = var1636.b;
  signal_A3VP82LDU.error = var1636.error;
  signal_B3VP82LDU.b = var1659.b;
  signal_B3VP82LDU.error = var1659.error;
  signal_B3VP52LDU.b = var1684.b;
  signal_B3VP52LDU.error = var1684.error;
  fplet(&signal_B3CP02RDU.f,&var1660.f);
  signal_B3CP02RDU.error = var1660.error;
  signal_B3VP42LDU.b = var1634.b;
  signal_B3VP42LDU.error = var1634.error;
  signal_A3VP52LDU.b = var1687.b;
  signal_A3VP52LDU.error = var1687.error;
  fplet(&signal_A3CP02RDU.f,&var1661.f);
  signal_A3CP02RDU.error = var1661.error;
  signal_A3VP42LDU.b = var1635.b;
  signal_A3VP42LDU.error = var1635.error;
  fplet(&signal_A1VC01RDU.f,&var1688.f);
  signal_A1VC01RDU.error = var1688.error;
  fplet(&signal_A8VC01RDU.f,&var1694.f);
  signal_A8VC01RDU.error = var1694.error;
  fplet(&signal_B3VC01RDU.f,&var1697.f);
  signal_B3VC01RDU.error = var1697.error;
  fplet(&signal_B1VC01RDU.f,&var1710.f);
  signal_B1VC01RDU.error = var1710.error;
  equz_p((&S_equz_p_4_1));
  equz_p((&S_equz_p_2_1));
  equz_p((&S_equz_p_7_1));
  equz_p((&S_equz_p_10_1));
  equz_p((&S_equz_p_90_1));
  equz_p((&S_equz_p_91_1));
  equz_p((&S_equz_p_92_1));
  equz_p((&S_equz_p_99_1));
  equz_p((&S_equz_p_46_1));
  equz_p((&S_equz_p_43_1));
  equz_p((&S_equz_p_50_1));
  equz_p((&S_equz_p_57_1));
  equz_p((&S_equz_p_55_1));
  equz_p((&S_equz_p_61_1));
  equz_p((&S_equz_p_65_1));
  equz_p((&S_equz_p_68_1));
  equz_p((&S_equz_p_69_1));
  equz_p((&S_equz_p_70_1));
  equz_p((&S_equz_p_72_1));
  equz_p((&S_equz_p_74_1));
  noto((&S_noto_143_1));
  noto((&S_noto_142_1));
  noto((&S_noto_153_1));
  noto((&S_noto_745_1));
  noto((&S_noto_712_1));
  noto((&S_noto_1091_1));
  noto((&S_noto_1555_1));
  noto((&S_noto_1251_1));
  noto((&S_noto_849_1));
  noto((&S_noto_217_1));
  noto((&S_noto_534_1));
  noto((&S_noto_944_1));
  rs((&S_rs_617_1));
  noto((&S_noto_1341_1));
  equz_p((&S_equz_p_32_1));
  equz_p((&S_equz_p_41_1));
  noto((&S_noto_34_1));
  equz_p((&S_equz_p_37_1));
  rs((&S_rs_1465_1));
  noto((&S_noto_1746_1));
  noto((&S_noto_1745_1));
  noto((&S_noto_1751_1));
  noto((&S_noto_1747_1));
  noto((&S_noto_1753_1));
  noto((&S_noto_1724_1));
  noto((&S_noto_1725_1));
  noto((&S_noto_1726_1));
  noto((&S_noto_1727_1));
  noto((&S_noto_1728_1));
  noto((&S_noto_2040_1));
  equz_p((&S_equz_p_93_1));
  equz_p((&S_equz_p_94_1));
  equz_p((&S_equz_p_95_1));
  noto((&S_noto_921_1));
  equz_p((&S_equz_p_96_1));
  equz_p((&S_equz_p_97_1));
  noto((&S_noto_177_1));
  equz_p((&S_equz_p_98_1));
  noto((&S_noto_12_1));
  noto((&S_noto_1824_1));
  equz_p((&S_equz_p_1768_1));
  equz_p((&S_equz_p_1767_1));
  equz_p((&S_equz_p_1769_1));
  equz_p((&S_equz_p_1770_1));
  equz_p((&S_equz_p_1771_1));
  noto((&S_noto_1733_1));
  noto((&S_noto_1785_1));
  noto((&S_noto_1805_1));
  rs((&S_rs_607_1));
  noto((&S_noto_1765_1));
  noto((&S_noto_1791_1));
  noto((&S_noto_1318_1));
  rsun((&S_rsun_1391_1));
  rs((&S_rs_609_1));
  rs((&S_rs_611_1));
  rs((&S_rs_627_1));
  rs((&S_rs_642_1));
  rs((&S_rs_616_1));
  rs((&S_rs_631_1));
  rs((&S_rs_26_1));
  rs((&S_rs_1460_1));
  rs((&S_rs_1415_1));
  rs((&S_rs_1857_1));
  noto((&S_noto_1410_1));
  noto((&S_noto_1450_1));
  noto((&S_noto_1455_1));
  noto((&S_noto_1815_1));
  noto((&S_noto_1852_1));
  noto((&S_noto_1871_1));
  noto((&S_noto_1837_1));
  noto((&S_noto_578_1));
  noto((&S_noto_22_1));
  noto((&S_noto_23_1));
  noto((&S_noto_24_1));
  noto((&S_noto_25_1));
  noto((&S_noto_581_1));
  noto((&S_noto_579_1));
  noto((&S_noto_49_1));
  noto((&S_noto_257_1));
  noto((&S_noto_260_1));
  noto((&S_noto_269_1));
  noto((&S_noto_275_1));
  noto((&S_noto_265_1));
  noto((&S_noto_978_1));
  noto((&S_noto_984_1));
  noto((&S_noto_1906_1));
  noto((&S_noto_1908_1));
  rs((&S_rs_1061_1));
  rs((&S_rs_1064_1));
  rs((&S_rs_1067_1));
  rs((&S_rs_1070_1));
  ovbs((&S_ovbs_1165_1));
  ovbs((&S_ovbs_2062_1));
  sr((&S_sr_1054_1));
  bol((&S_bol_1048_1));
  ma((&S_ma_83_1));
  sr((&S_sr_81_1));
  bol((&S_bol_254_1));
  bol((&S_bol_252_1));
  bol((&S_bol_1370_1));
  bol((&S_bol_1368_1));
  bol((&S_bol_973_1));
  bol((&S_bol_971_1));
  bol((&S_bol_566_1));
  bol((&S_bol_568_1));
  bol((&S_bol_577_1));
  bol((&S_bol_583_1));
  and2((&S_and2_733_1));
  and2((&S_and2_27_1));
  and2((&S_and2_28_1));
  and2((&S_and2_29_1));
  and2((&S_and2_30_1));
  and2((&S_and2_42_1));
  and2((&S_and2_38_1));
  and2((&S_and2_724_1));
  or4((&S_or4_414_1));
  or2((&S_or2_737_1));
  or3((&S_or3_5_1));
  or2((&S_or2_6_1));
  or2((&S_or2_1264_1));
  or2((&S_or2_862_1));
  or2((&S_or2_231_1));
  or2((&S_or2_548_1));
  or2((&S_or2_956_1));
  or2((&S_or2_1353_1));
  or2((&S_or2_1053_1));
  and2((&S_and2_1047_1));
  or2((&S_or2_20_1));
  or2((&S_or2_39_1));
  or2((&S_or2_35_1));
  or2((&S_or2_48_1));
  or2((&S_or2_684_1));
  or3((&S_or3_672_1));
  or4((&S_or4_686_1));
  or2((&S_or2_699_1));
  or3((&S_or3_720_1));
  and2((&S_and2_744_1));
  and2((&S_and2_718_1));
  or2((&S_or2_725_1));
  or2((&S_or2_654_1));
  or2((&S_or2_656_1));
  or2((&S_or2_658_1));
  or2((&S_or2_1141_1));
  or2((&S_or2_1166_1));
  and4((&S_and4_1059_1));
  or2((&S_or2_1058_1));
  and2((&S_and2_1073_1));
  or2((&S_or2_1087_1));
  and3((&S_and3_258_1));
  and3((&S_and3_274_1));
  or2((&S_or2_600_1));
  or2((&S_or2_608_1));
  or2((&S_or2_610_1));
  or2((&S_or2_613_1));
  or2((&S_or2_584_1));
  and2((&S_and2_634_1));
  or2((&S_or2_641_1));
  and2((&S_and2_605_1));
  or2((&S_or2_620_1));
  or2((&S_or2_615_1));
  or2((&S_or2_638_1));
  and2((&S_and2_595_1));
  or2((&S_or2_340_1));
  or2((&S_or2_345_1));
  or2((&S_or2_742_1));
  or2((&S_or2_456_1));
  or2((&S_or2_514_1));
  and2((&S_and2_523_1));
  and2((&S_and2_524_1));
  and2((&S_and2_533_1));
  or2((&S_or2_526_1));
  or2((&S_or2_195_1));
  and2((&S_and2_175_1));
  and2((&S_and2_207_1));
  and2((&S_and2_206_1));
  or2((&S_or2_209_1));
  and2((&S_and2_216_1));
  or2((&S_or2_779_1));
  or2((&S_or2_825_1));
  or2((&S_or2_840_1));
  and2((&S_and2_915_1));
  or2((&S_or2_926_1));
  or2((&S_or2_918_1));
  or2((&S_or2_934_1));
  or2((&S_or2_1333_1));
  or2((&S_or2_1315_1));
  and2((&S_and2_1312_1));
  or2((&S_or2_1323_1));
  or2((&S_or2_1241_1));
  or2((&S_or2_1223_1));
  and2((&S_and2_983_1));
  and2((&S_and2_1411_1));
  zpfs((&S_zpfs_1421_1));
  and2((&S_and2_1451_1));
  zpfs((&S_zpfs_1471_1));
  and2((&S_and2_1456_1));
  zpfs((&S_zpfs_1477_1));
  and2((&S_and2_1493_1));
  or2((&S_or2_2063_1));
  or2((&S_or2_1600_1));
  or2((&S_or2_1601_1));
  or2((&S_or2_1551_1));
  or2((&S_or2_1731_1));
  or2((&S_or2_1732_1));
  or4((&S_or4_1738_1));
  or4((&S_or4_1739_1));
  or2((&S_or2_1741_1));
  or2((&S_or2_1735_1));
  or2((&S_or2_1734_1));
  or3((&S_or3_1743_1));
  and2((&S_and2_1772_1));
  or2((&S_or2_1773_1));
  and2((&S_and2_1779_1));
  and2((&S_and2_1795_1));
  or2((&S_or2_1798_1));
  and2((&S_and2_1801_1));
  or2((&S_or2_1806_1));
  zpfs((&S_zpfs_1775_1));
  zpfs((&S_zpfs_1776_1));
  zpfs((&S_zpfs_1777_1));
  zpfs((&S_zpfs_1778_1));
  or2((&S_or2_1781_1));
  and2((&S_and2_1782_1));
  or2((&S_or2_1797_1));
  or3((&S_or3_1783_1));
  or2((&S_or2_1858_1));
  ma((&S_ma_1446_1));
  zpfs((&S_zpfs_1828_1));
  and2((&S_and2_1829_1));
  or2((&S_or2_1823_1));
  and3((&S_and3_1826_1));
  or2((&S_or2_1834_1));
  or2((&S_or2_233_1));
  ovbs((&S_ovbs_76_1));
  ovbs((&S_ovbs_2034_1));
  ovbs((&S_ovbs_2030_1));
  ovbs((&S_ovbs_21_1));
  ovbs((&S_ovbs_119_1));
  ovbs((&S_ovbs_112_1));
  ovbs((&S_ovbs_1405_1));
  ovbs((&S_ovbs_740_1));
  ovbs((&S_ovbs_291_1));
  ovbs((&S_ovbs_336_1));
  ovbs((&S_ovbs_51_1));
  or2((&S_or2_1461_1));
  or2((&S_or2_1970_1));
  or2((&S_or2_1958_1));
  noto((&S_noto_1988_1));
  bol((&S_bol_1537_1));
  bol((&S_bol_1529_1));
  or2((&S_or2_1533_1));
  bol((&S_bol_1518_1));
  bol((&S_bol_1511_1));
  or2((&S_or2_1516_1));
  bol((&S_bol_1538_1));
  bol((&S_bol_1530_1));
  or2((&S_or2_1536_1));
  bol((&S_bol_1523_1));
  bol((&S_bol_1517_1));
  or2((&S_or2_1521_1));
  and4((&S_and4_45_1));
  abs_subf((&S_abs_subf_1528_1));
  noto((&S_noto_1534_1));
  and2((&S_and2_232_1));
  and2((&S_and2_549_1));
  and2((&S_and2_2206_1));
  rs((&S_rs_2155_1));
  sr((&S_sr_2193_1));
  sr((&S_sr_2170_1));
  rs((&S_rs_2149_1));
  zpfs((&S_zpfs_2177_1));
  or2((&S_or2_2164_1));
  abs_subf((&S_abs_subf_2130_1));
  and2((&S_and2_2137_1));
  noto((&S_noto_891_1));
  zzfs((&S_zzfs_2138_1));
  noto((&S_noto_2150_1));
  or2((&S_or2_1071_1));
  or2((&S_or2_365_1));
  or2((&S_or2_348_1));
  or2((&S_or2_1103_1));
  or2((&S_or2_1108_1));
  or2((&S_or2_229_1));
  or2((&S_or2_546_1));
  and2((&S_and2_2052_1));
  nocnm((&S_nocnm_1686_1));
  nocnm((&S_nocnm_1689_1));
  noto((&S_noto_1638_1));
  noto((&S_noto_1644_1));
  noto((&S_noto_2124_1));
  noto((&S_noto_2098_1));
  or2((&S_or2_1418_1));
  or2((&S_or2_1449_1));
  noto((&S_noto_2127_1));
  noto((&S_noto_2101_1));
  noto((&S_noto_106_1));
  and2((&S_and2_719_1));
  and2((&S_and2_722_1));
  or2((&S_or2_126_1));
  noto((&S_noto_670_1));
  noto((&S_noto_151_1));
  rs((&S_rs_726_1));
  noto((&S_noto_415_1));
  noto((&S_noto_659_1));
  noto((&S_noto_703_1));
  rs((&S_rs_736_1));
  noto((&S_noto_754_1));
  vmemb((&S_vmemb_667_1));
  vmemb((&S_vmemb_704_1));
  noto((&S_noto_743_1));
  vmemb((&S_vmemb_735_1));
  rs((&S_rs_622_1));
  rs((&S_rs_632_1));
  rs((&S_rs_612_1));
  noto((&S_noto_599_1));
  rs((&S_rs_640_1));
  noto((&S_noto_256_1));
  noto((&S_noto_635_1));
  noto((&S_noto_570_1));
  noto((&S_noto_975_1));
  noto((&S_noto_1372_1));
  noto((&S_noto_997_1));
  noto((&S_noto_1881_1));
  kvf((&S_kvf_1469_1));
  noto((&S_noto_77_1));
  samhd((&S_samhd_2061_1));
  samhd((&S_samhd_2067_1));
  newstage((&S_newstage_2065_1));
  noto((&S_noto_1744_1));
  noto((&S_noto_1750_1));
  noto((&S_noto_1752_1));
  noto((&S_noto_1723_1));
  noto((&S_noto_2031_1));
  noto((&S_noto_2035_1));
  noto((&S_noto_1868_1));
  noto((&S_noto_1861_1));
  noto((&S_noto_1819_1));
  noto((&S_noto_501_1));
  noto((&S_noto_1202_1));
  noto((&S_noto_1217_1));
  noto((&S_noto_1793_1));
  rs((&S_rs_1480_1));
  kvf((&S_kvf_1475_1));
  rs((&S_rs_1474_1));
  noto((&S_noto_1485_1));
  noto((&S_noto_1483_1));
  rs((&S_rs_741_1));
  noto((&S_noto_342_1));
  noto((&S_noto_338_1));
  noto((&S_noto_580_1));
  noto((&S_noto_590_1));
  noto((&S_noto_644_1));
  noto((&S_noto_1890_1));
  noto((&S_noto_1915_1));
  swtakt((&S_swtakt_52_1));
  rs((&S_rs_1063_1));
  and2((&S_and2_751_1));
  and2((&S_and2_11_1));
  and2((&S_and2_111_1));
  and2((&S_and2_228_1));
  and2((&S_and2_545_1));
  or2((&S_or2_14_1));
  or2((&S_or2_8_1));
  or2((&S_or2_165_1));
  and3((&S_and3_697_1));
  and2((&S_and2_668_1));
  or3((&S_or3_731_1));
  and2((&S_and2_727_1));
  and2((&S_and2_650_1));
  or2((&S_or2_264_1));
  and3((&S_and3_280_1));
  or2((&S_or2_633_1));
  and2((&S_and2_602_1));
  and2((&S_and2_592_1));
  and4((&S_and4_593_1));
  and4((&S_and4_603_1));
  and2((&S_and2_628_1));
  or2((&S_or2_636_1));
  or2((&S_or2_639_1));
  and3((&S_and3_333_1));
  and2((&S_and2_496_1));
  or2((&S_or2_503_1));
  and2((&S_and2_555_1));
  and2((&S_and2_567_1));
  or2((&S_or2_181_1));
  and2((&S_and2_241_1));
  and2((&S_and2_253_1));
  and2((&S_and2_972_1));
  and2((&S_and2_1354_1));
  and2((&S_and2_1369_1));
  and2((&S_and2_1200_1));
  or2((&S_or2_1206_1));
  and2((&S_and2_1213_1));
  or2((&S_or2_1225_1));
  and2((&S_and2_992_1));
  and2((&S_and2_1002_1));
  or2((&S_or2_1459_1));
  and2((&S_and2_1422_1));
  and2((&S_and2_1472_1));
  or3((&S_or3_1487_1));
  or2((&S_or2_1468_1));
  and2((&S_and2_1478_1));
  or3((&S_or3_1479_1));
  or3((&S_or3_1492_1));
  or3((&S_or3_2060_1));
  or3((&S_or3_2069_1));
  or2((&S_or2_1740_1));
  or3((&S_or3_1742_1));
  or2((&S_or2_1780_1));
  or2((&S_or2_1796_1));
  and2((&S_and2_1788_1));
  or3((&S_or3_1787_1));
  and2((&S_and2_1810_1));
  and2((&S_and2_2049_1));
  or2((&S_or2_2011_1));
  or2((&S_or2_1942_1));
  or2((&S_or2_1931_1));
  and2((&S_and2_1911_1));
  and2((&S_and2_1909_1));
  and2((&S_and2_1894_1));
  and2((&S_and2_1893_1));
  and2((&S_and2_1863_1));
  and4((&S_and4_1869_1));
  and4((&S_and4_1870_1));
  or2((&S_or2_1872_1));
  or2((&S_or2_1874_1));
  or2((&S_or2_1873_1));
  zpfs((&S_zpfs_1877_1));
  zpfs((&S_zpfs_1880_1));
  zpfs((&S_zpfs_1864_1));
  and2((&S_and2_1865_1));
  or3((&S_or3_1882_1));
  lk((&S_lk_1470_1));
  rsfn((&S_rsfn_1466_1));
  abs_subf((&S_abs_subf_1481_1));
  lk((&S_lk_1467_1));
  rsfn((&S_rsfn_1463_1));
  abs_subf((&S_abs_subf_1476_1));
  and3((&S_and3_1825_1));
  or2((&S_or2_1832_1));
  or2((&S_or2_1833_1));
  zpfs((&S_zpfs_1839_1));
  zpfs((&S_zpfs_1841_1));
  or3((&S_or3_1844_1));
  or2((&S_or2_1846_1));
  and2((&S_and2_957_1));
  or2((&S_or2_248_1));
  ovbs((&S_ovbs_1847_1));
  ovbs((&S_ovbs_13_1));
  noto((&S_noto_102_1));
  bol((&S_bol_1522_1));
  bol((&S_bol_1510_1));
  or2((&S_or2_1513_1));
  ml((&S_ml_1525_1));
  ml((&S_ml_1505_1));
  ml((&S_ml_1527_1));
  ml((&S_ml_1506_1));
  and2((&S_and2_117_1));
  noto((&S_noto_115_1));
  and2((&S_and2_121_1));
  and2((&S_and2_120_1));
  noto((&S_noto_188_1));
  noto((&S_noto_461_1));
  noto((&S_noto_908_1));
  noto((&S_noto_1160_1));
  noto((&S_noto_1214_1));
  bol((&S_bol_1758_1));
  and3((&S_and3_1749_1));
  bol((&S_bol_1722_1));
  and3((&S_and3_1730_1));
  noto((&S_noto_1737_1));
  noto((&S_noto_1748_1));
  bol((&S_bol_899_1));
  bol((&S_bol_1298_1));
  abs_subf((&S_abs_subf_1508_1));
  noto((&S_noto_1519_1));
  abs_subf((&S_abs_subf_1531_1));
  noto((&S_noto_1539_1));
  bol((&S_bol_2195_1));
  and2((&S_and2_2205_1));
  noto((&S_noto_2163_1));
  fsumo((&S_fsumo_79_1));
  abs_subf((&S_abs_subf_2202_1));
  and2((&S_and2_2207_1));
  and3((&S_and3_2156_1));
  and2((&S_and2_2178_1));
  ovbs((&S_ovbs_2179_1));
  or3((&S_or3_2188_1));
  inf((&S_inf_2159_1));
  noto((&S_noto_1299_1));
  or2((&S_or2_1062_1));
  or5((&S_or5_2050_1));
  and2((&S_and2_2112_1));
  and2((&S_and2_2086_1));
  and2((&S_and2_2012_1));
  and2((&S_and2_104_1));
  and3((&S_and3_1384_1));
  rs((&S_rs_732_1));
  noto((&S_noto_747_1));
  noto((&S_noto_1242_1));
  noto((&S_noto_838_1));
  noto((&S_noto_210_1));
  rs((&S_rs_614_1));
  noto((&S_noto_527_1));
  noto((&S_noto_935_1));
  noto((&S_noto_1331_1));
  kvf((&S_kvf_1840_1));
  kvf((&S_kvf_1879_1));
  andn((&S_andn_1736_1));
  rs((&S_rs_19_1));
  noto((&S_noto_139_1));
  newstage((&S_newstage_1789_1));
  noto((&S_noto_1794_1));
  noto((&S_noto_110_1));
  noto((&S_noto_1375_1));
  abs_subf((&S_abs_subf_1003_1));
  abs_subf((&S_abs_subf_990_1));
  noto((&S_noto_1010_1));
  bol((&S_bol_1023_1));
  bol((&S_bol_1024_1));
  noto((&S_noto_987_1));
  bol((&S_bol_1026_1));
  bol((&S_bol_1027_1));
  bol((&S_bol_80_1));
  and2((&S_and2_144_1));
  and2((&S_and2_152_1));
  and2((&S_and2_149_1));
  and2((&S_and2_141_1));
  and3((&S_and3_230_1));
  and3((&S_and3_547_1));
  and3((&S_and3_981_1));
  or3((&S_or3_107_1));
  or2((&S_or2_660_1));
  and2((&S_and2_669_1));
  and2((&S_and2_671_1));
  and2((&S_and2_683_1));
  and2((&S_and2_685_1));
  and2((&S_and2_698_1));
  and2((&S_and2_701_1));
  and3((&S_and3_700_1));
  and2((&S_and2_702_1));
  or2((&S_or2_738_1));
  and2((&S_and2_746_1));
  or2((&S_or2_752_1));
  or2((&S_or2_756_1));
  and3((&S_and3_753_1));
  and2((&S_and2_758_1));
  and2((&S_and2_762_1));
  and2((&S_and2_646_1));
  or2((&S_or2_647_1));
  and2((&S_and2_655_1));
  and2((&S_and2_657_1));
  and2((&S_and2_626_1));
  and2((&S_and2_604_1));
  and2((&S_and2_594_1));
  and3((&S_and3_525_1));
  or2((&S_or2_562_1));
  and3((&S_and3_208_1));
  and3((&S_and3_243_1));
  and3((&S_and3_846_1));
  and3((&S_and3_847_1));
  or2((&S_or2_967_1));
  or2((&S_or2_1364_1));
  and3((&S_and3_1248_1));
  and3((&S_and3_1249_1));
  or2((&S_or2_1028_1));
  or2((&S_or2_1041_1));
  or2((&S_or2_1040_1));
  or2((&S_or2_1039_1));
  or2((&S_or2_1038_1));
  and2((&S_and2_1387_1));
  and2((&S_and2_1393_1));
  and2((&S_and2_1395_1));
  and2((&S_and2_1397_1));
  and2((&S_and2_1403_1));
  and2((&S_and2_1407_1));
  or3((&S_or3_1431_1));
  and2((&S_and2_1432_1));
  and3((&S_and3_1490_1));
  or3((&S_or3_1473_1));
  and2((&S_and2_1488_1));
  and3((&S_and3_1491_1));
  zpfs((&S_zpfs_2013_1));
  and3((&S_and3_1903_1));
  and2((&S_and2_1898_1));
  or3((&S_or3_1904_1));
  and2((&S_and2_1876_1));
  and4((&S_and4_1884_1));
  and4((&S_and4_1886_1));
  lk((&S_lk_1883_1));
  rsfn((&S_rsfn_1887_1));
  abs_subf((&S_abs_subf_1889_1));
  and3((&S_and3_1892_1));
  lk((&S_lk_1845_1));
  rsfn((&S_rsfn_1848_1));
  abs_subf((&S_abs_subf_1850_1));
  and2((&S_and2_1838_1));
  and3((&S_and3_1842_1));
  or5((&S_or5_147_1));
  and2((&S_and2_1811_1));
  and2((&S_and2_105_1));
  and2((&S_and2_101_1));
  ml((&S_ml_1503_1));
  zpfs((&S_zpfs_739_1));
  and2((&S_and2_1713_1));
  and2((&S_and2_1694_1));
  and2((&S_and2_1711_1));
  and2((&S_and2_1714_1));
  and2((&S_and2_1695_1));
  and2((&S_and2_1712_1));
  and2((&S_and2_1696_1));
  and2((&S_and2_1697_1));
  and2((&S_and2_1698_1));
  and2((&S_and2_1699_1));
  and2((&S_and2_1700_1));
  and2((&S_and2_1701_1));
  and2((&S_and2_1672_1));
  and2((&S_and2_1673_1));
  and2((&S_and2_1674_1));
  and2((&S_and2_1675_1));
  and2((&S_and2_1652_1));
  and2((&S_and2_1654_1));
  and2((&S_and2_1656_1));
  and2((&S_and2_1658_1));
  and2((&S_and2_1626_1));
  and2((&S_and2_1628_1));
  and2((&S_and2_1630_1));
  and2((&S_and2_1632_1));
  and2((&S_and2_1602_1));
  and2((&S_and2_1603_1));
  and2((&S_and2_1604_1));
  and2((&S_and2_1605_1));
  and2((&S_and2_1606_1));
  and2((&S_and2_1607_1));
  and2((&S_and2_1608_1));
  and2((&S_and2_1609_1));
  and2((&S_and2_116_1));
  abs_subf((&S_abs_subf_1507_1));
  noto((&S_noto_1514_1));
  irm((&S_irm_2141_1));
  ovbs((&S_ovbs_2157_1));
  and2((&S_and2_2203_1));
  ml((&S_ml_878_1));
  ml((&S_ml_1280_1));
  noto((&S_noto_2187_1));
  noto((&S_noto_2134_1));
  noto((&S_noto_2135_1));
  or2((&S_or2_2115_1));
  and2((&S_and2_2107_1));
  or4((&S_or4_883_1));
  or2((&S_or2_2093_1));
  or2((&S_or2_2089_1));
  and2((&S_and2_2081_1));
  or4((&S_or4_1285_1));
  and4((&S_and4_942_1));
  and4((&S_and4_1339_1));
  and3((&S_and3_2111_1));
  and3((&S_and3_2085_1));
  samhd((&S_samhd_381_1));
  samhd((&S_samhd_387_1));
  samhd((&S_samhd_776_1));
  samhd((&S_samhd_780_1));
  rs((&S_rs_748_1));
  rs((&S_rs_755_1));
  newstage((&S_newstage_384_1));
  newstage((&S_newstage_778_1));
  orn((&S_orn_145_1));
  rs((&S_rs_1612_1));
  rs((&S_rs_1615_1));
  rs((&S_rs_1618_1));
  rs((&S_rs_1621_1));
  rs((&S_rs_1637_1));
  rs((&S_rs_1643_1));
  rs((&S_rs_1664_1));
  rs((&S_rs_1670_1));
  rs((&S_rs_2121_1));
  rs((&S_rs_1705_1));
  rs((&S_rs_1708_1));
  rs((&S_rs_1648_1));
  rs((&S_rs_1650_1));
  rs((&S_rs_1622_1));
  rs((&S_rs_1623_1));
  rs((&S_rs_1624_1));
  rs((&S_rs_1625_1));
  rs((&S_rs_108_1));
  noto((&S_noto_109_1));
  rs((&S_rs_1495_1));
  rs((&S_rs_1494_1));
  rs((&S_rs_1424_1));
  kvf((&S_kvf_1428_1));
  rs((&S_rs_1897_1));
  rs((&S_rs_1843_1));
  noto((&S_noto_1427_1));
  andn((&S_andn_263_1));
  noto((&S_noto_281_1));
  and2((&S_and2_405_1));
  and2((&S_and2_416_1));
  and2((&S_and2_424_1));
  and2((&S_and2_425_1));
  and2((&S_and2_426_1));
  or3((&S_or3_377_1));
  or3((&S_or3_392_1));
  and2((&S_and2_406_1));
  and3((&S_and3_582_1));
  or2((&S_or2_146_1));
  and2((&S_and2_674_1));
  and2((&S_and2_734_1));
  or2((&S_or2_761_1));
  and2((&S_and2_653_1));
  or2((&S_or2_271_1));
  and3((&S_and3_272_1));
  or2((&S_or2_434_1));
  and3((&S_and3_441_1));
  or2((&S_or2_487_1));
  and2((&S_and2_507_1));
  and3((&S_and3_557_1));
  and3((&S_and3_556_1));
  and2((&S_and2_183_1));
  and3((&S_and3_242_1));
  or4((&S_or4_772_1));
  or4((&S_or4_788_1));
  or3((&S_or3_839_1));
  and2((&S_and2_836_1));
  and3((&S_and3_837_1));
  and2((&S_and2_835_1));
  and2((&S_and2_848_1));
  and2((&S_and2_865_1));
  and3((&S_and3_866_1));
  and2((&S_and2_929_1));
  or2((&S_or2_936_1));
  and2((&S_and2_943_1));
  and2((&S_and2_960_1));
  and3((&S_and3_961_1));
  and3((&S_and3_962_1));
  or2((&S_or2_1332_1));
  and2((&S_and2_1340_1));
  and2((&S_and2_1357_1));
  and3((&S_and3_1358_1));
  and3((&S_and3_1359_1));
  and2((&S_and2_1324_1));
  or3((&S_or3_1240_1));
  and3((&S_and3_1239_1));
  and2((&S_and2_1238_1));
  and2((&S_and2_1237_1));
  and2((&S_and2_1250_1));
  and2((&S_and2_1262_1));
  and3((&S_and3_1263_1));
  and2((&S_and2_1267_1));
  and3((&S_and3_1268_1));
  and2((&S_and2_1209_1));
  and2((&S_and2_1230_1));
  and2((&S_and2_1042_1));
  and2((&S_and2_1044_1));
  or2((&S_or2_1419_1));
  or3((&S_or3_1423_1));
  or2((&S_or2_1611_1));
  or2((&S_or2_1614_1));
  or2((&S_or2_1617_1));
  or2((&S_or2_1620_1));
  or2((&S_or2_1635_1));
  or2((&S_or2_1641_1));
  or2((&S_or2_1663_1));
  or2((&S_or2_1669_1));
  or2((&S_or2_2119_1));
  or2((&S_or2_2038_1));
  or2((&S_or2_2043_1));
  lk((&S_lk_1429_1));
  rsfn((&S_rsfn_1425_1));
  abs_subf((&S_abs_subf_1434_1));
  ovbs((&S_ovbs_114_1));
  and2((&S_and2_468_1));
  and2((&S_and2_435_1));
  and2((&S_and2_432_1));
  and2((&S_and2_1627_1));
  and2((&S_and2_1629_1));
  and2((&S_and2_1631_1));
  and2((&S_and2_1633_1));
  zpfs((&S_zpfs_2142_1));
  zpfs((&S_zpfs_2143_1));
  and2((&S_and2_2026_1));
  and2((&S_and2_2037_1));
  and3((&S_and3_407_1));
  and2((&S_and2_2025_1));
  and2((&S_and2_2048_1));
  rs((&S_rs_2114_1));
  rs((&S_rs_2105_1));
  rs((&S_rs_2095_1));
  rs((&S_rs_2088_1));
  rs((&S_rs_2079_1));
  regch((&S_regch_124_1));
  rs((&S_rs_728_1));
  rs((&S_rs_760_1));
  rs((&S_rs_587_1));
  noto((&S_noto_601_1));
  orni((&S_orni_1392_1));
  rs((&S_rs_1610_1));
  rs((&S_rs_1613_1));
  rs((&S_rs_1616_1));
  rs((&S_rs_1619_1));
  rs((&S_rs_1636_1));
  rs((&S_rs_1634_1));
  rs((&S_rs_2039_1));
  rs((&S_rs_1639_1));
  rs((&S_rs_1642_1));
  rs((&S_rs_1640_1));
  rs((&S_rs_1645_1));
  ma((&S_ma_1430_1));
  rs((&S_rs_597_1));
  noto((&S_noto_977_1));
  noto((&S_noto_273_1));
  noto((&S_noto_1033_1));
  noto((&S_noto_1034_1));
  noto((&S_noto_1006_1));
  and2((&S_and2_409_1));
  and2((&S_and2_427_1));
  and2((&S_and2_860_1));
  and3((&S_and3_861_1));
  and3((&S_and3_955_1));
  and3((&S_and3_1352_1));
  and2((&S_and2_621_1));
  and2((&S_and2_931_1));
  and2((&S_and2_932_1));
  and3((&S_and3_933_1));
  and2((&S_and2_1328_1));
  and2((&S_and2_1329_1));
  and3((&S_and3_1330_1));
  and5((&S_and5_982_1));
  and2((&S_and2_1029_1));
  or4((&S_or4_989_1));
  and3((&S_and3_1438_1));
  noto((&S_noto_2147_1));
  noto((&S_noto_2148_1));
  andn((&S_andn_585_1));
  andn((&S_andn_586_1));
  or5((&S_or5_2051_1));
  or2((&S_or2_127_1));
  rs((&S_rs_988_1));
  rs((&S_rs_2044_1));
  rs((&S_rs_1441_1));
  noto((&S_noto_1007_1));
  provsbr((&S_provsbr_1389_1));
  rs((&S_rs_1388_1));
  and2((&S_and2_535_1));
  and2((&S_and2_218_1));
  and2((&S_and2_850_1));
  and2((&S_and2_945_1));
  and2((&S_and2_1342_1));
  and2((&S_and2_1252_1));
  and3((&S_and3_994_1));
  and3((&S_and3_1000_1));
  and2((&S_and2_1016_1));
  and2((&S_and2_1005_1));
  and3((&S_and3_1051_1));
  or2((&S_or2_1394_1));
  or2((&S_or2_1396_1));
  or2((&S_or2_1398_1));
  or2((&S_or2_1404_1));
  or2((&S_or2_1408_1));
  orni((&S_orni_1400_1));
  or2((&S_or2_2027_1));
  noto((&S_noto_2154_1));
  and2((&S_and2_2028_1));
  noto((&S_noto_2045_1));
  cntch((&S_cntch_1399_1));
  rs((&S_rs_1011_1));
  rs((&S_rs_1045_1));
  rs((&S_rs_1019_1));
  noto((&S_noto_1020_1));
  or3((&S_or3_155_1));
  or3((&S_or3_477_1));
  or2((&S_or2_1035_1));
  and2((&S_and2_1401_1));
  or2((&S_or2_1563_1));
  zpfs((&S_zpfs_2024_1));
  cnshd((&S_cnshd_1570_1));
  noto((&S_noto_858_1));
  ornc((&S_ornc_164_1));
  charint((&S_charint_156_1));
  noto((&S_noto_226_1));
  ornc((&S_ornc_485_1));
  charint((&S_charint_479_1));
  noto((&S_noto_543_1));
  noto((&S_noto_953_1));
  noto((&S_noto_1350_1));
  rs((&S_rs_1030_1));
  or2((&S_or2_1589_1));
  and2((&S_and2_1541_1));
  and2((&S_and2_1542_1));
  and2((&S_and2_1543_1));
  and2((&S_and2_1544_1));
  and2((&S_and2_1550_1));
  and2((&S_and2_1552_1));
  and2((&S_and2_1554_1));
  and2((&S_and2_1018_1));
  fnapb((&S_fnapb_1590_1));
  samhd((&S_samhd_1573_1));
  zpfs((&S_zpfs_1586_1));
  zpfs((&S_zpfs_1583_1));
  noto((&S_noto_1260_1));
  fsumz((&S_fsumz_157_1));
  fsumz((&S_fsumz_480_1));
  orni((&S_orni_1152_1));
  rs((&S_rs_1013_1));
  rs((&S_rs_1014_1));
  ma((&S_ma_162_1));
  ma((&S_ma_486_1));
  zpfs((&S_zpfs_1591_1));
  or2((&S_or2_1105_1));
  or3((&S_or3_1012_1));
  or3((&S_or3_1580_1));
  samhd((&S_samhd_1157_1));
  samhd((&S_samhd_1167_1));
  newstage((&S_newstage_1163_1));
  cnshd((&S_cnshd_1109_1));
  noto((&S_noto_1259_1));
  noto((&S_noto_857_1));
  fnapb((&S_fnapb_196_1));
  noto((&S_noto_225_1));
  fnapb((&S_fnapb_515_1));
  zpfs((&S_zpfs_511_1));
  zpfs((&S_zpfs_508_1));
  noto((&S_noto_542_1));
  noto((&S_noto_952_1));
  noto((&S_noto_1349_1));
  or2((&S_or2_1156_1));
  or2((&S_or2_1170_1));
  or2((&S_or2_1129_1));
  and2((&S_and2_1081_1));
  and2((&S_and2_1078_1));
  and2((&S_and2_1079_1));
  and2((&S_and2_1080_1));
  and2((&S_and2_1086_1));
  and2((&S_and2_1088_1));
  and2((&S_and2_1090_1));
  and2((&S_and2_623_1));
  zpfs((&S_zpfs_516_1));
  or2((&S_or2_537_1));
  zpfs((&S_zpfs_197_1));
  zpfs((&S_zpfs_190_1));
  zpfs((&S_zpfs_186_1));
  or2((&S_or2_220_1));
  or2((&S_or2_852_1));
  and2((&S_and2_851_1));
  or2((&S_or2_947_1));
  or2((&S_or2_1344_1));
  or2((&S_or2_1254_1));
  and2((&S_and2_1253_1));
  and2((&S_and2_1009_1));
  or2((&S_or2_1021_1));
  and2((&S_and2_1161_1));
  and2((&S_and2_1168_1));
  or4((&S_or4_1921_1));
  fnapb((&S_fnapb_1130_1));
  samhd((&S_samhd_1113_1));
  zpfs((&S_zpfs_1126_1));
  zpfs((&S_zpfs_1122_1));
  orn((&S_orn_1261_1));
  orn((&S_orn_859_1));
  rs((&S_rs_1649_1));
  rs((&S_rs_1651_1));
  rs((&S_rs_1008_1));
  zpfs((&S_zpfs_1131_1));
  and2((&S_and2_31_1));
  and2((&S_and2_536_1));
  and2((&S_and2_219_1));
  and2((&S_and2_946_1));
  and2((&S_and2_1343_1));
  and2((&S_and2_1022_1));
  or2((&S_or2_1015_1));
  or3((&S_or3_1119_1));
  or2((&S_or2_1661_1));
  or2((&S_or2_1667_1));
  or2((&S_or2_1938_1));
  or2((&S_or2_1927_1));
  ovbs((&S_ovbs_1922_1));
  ovbs((&S_ovbs_1934_1));
  ovbs((&S_ovbs_1925_1));
  noto((&S_noto_1926_1));
  and2((&S_and2_1932_1));
  and2((&S_and2_1943_1));
  and2((&S_and2_1653_1));
  and2((&S_and2_1655_1));
  and2((&S_and2_1657_1));
  and2((&S_and2_1659_1));
  or3((&S_or3_125_1));
  orn((&S_orn_227_1));
  orn((&S_orn_954_1));
  orn((&S_orn_1351_1));
  noto((&S_noto_1923_1));
  noto((&S_noto_1935_1));
  rs((&S_rs_1939_1));
  noto((&S_noto_1940_1));
  rs((&S_rs_1662_1));
  rs((&S_rs_1660_1));
  rs((&S_rs_1665_1));
  rs((&S_rs_1668_1));
  rs((&S_rs_1666_1));
  rs((&S_rs_1671_1));
  rs((&S_rs_1928_1));
  rs((&S_rs_1060_1));
  or2((&S_or2_1895_1));
  or3((&S_or3_1192_1));
  or3((&S_or3_807_1));
  noto((&S_noto_1929_1));
  noto((&S_noto_66_1));
  noto((&S_noto_1896_1));
  and2((&S_and2_58_1));
  and2((&S_and2_62_1));
  and4((&S_and4_327_1));
  or2((&S_or2_1381_1));
  or2((&S_or2_1912_1));
  noto((&S_noto_1377_1));
  rs((&S_rs_330_1));
  noto((&S_noto_325_1));
  noto((&S_noto_268_1));
  rs((&S_rs_1913_1));
  rs((&S_rs_1914_1));
  or4((&S_or4_279_1));
  or2((&S_or2_262_1));
  or2((&S_or2_285_1));
  or2((&S_or2_322_1));
  or4((&S_or4_331_1));
  and2((&S_and2_1376_1));
  or2((&S_or2_1974_1));
  or2((&S_or2_1995_1));
  rs((&S_rs_278_1));
  provsbr((&S_provsbr_267_1));
  equz_p((&S_equz_p_306_1));
  bolz((&S_bolz_307_1));
  provsbr((&S_provsbr_324_1));
  bolz((&S_bolz_329_1));
  noto((&S_noto_67_1));
  noto((&S_noto_56_1));
  and2((&S_and2_59_1));
  and2((&S_and2_63_1));
  or2((&S_or2_60_1));
  and2((&S_and2_559_1));
  and2((&S_and2_558_1));
  and2((&S_and2_282_1));
  and4((&S_and4_311_1));
  and2((&S_and2_294_1));
  or2((&S_or2_284_1));
  and2((&S_and2_289_1));
  or2((&S_or2_335_1));
  and2((&S_and2_326_1));
  orn((&S_orn_544_1));
  and2((&S_and2_244_1));
  and2((&S_and2_245_1));
  or3((&S_or3_255_1));
  and2((&S_and2_868_1));
  and2((&S_and2_867_1));
  or3((&S_or3_873_1));
  and2((&S_and2_964_1));
  and2((&S_and2_963_1));
  and2((&S_and2_1360_1));
  and2((&S_and2_1361_1));
  and2((&S_and2_1269_1));
  and2((&S_and2_1270_1));
  or3((&S_or3_1275_1));
  or2((&S_or2_1378_1));
  or3((&S_or3_1409_1));
  or3((&S_or3_1448_1));
  or3((&S_or3_1464_1));
  or3((&S_or3_1855_1));
  or3((&S_or3_1817_1));
  or4((&S_or4_1371_1));
  or4((&S_or4_974_1));
  maz((&S_maz_293_1));
  maz((&S_maz_302_1));
  orni((&S_orni_1164_1));
  orni((&S_orni_283_1));
  rs((&S_rs_334_1));
  decatron((&S_decatron_290_1));
  orni((&S_orni_328_1));
  noto((&S_noto_303_1));
  swtakt((&S_swtakt_1821_1));
  swtakt((&S_swtakt_1856_1));
  swtakt((&S_swtakt_1454_1));
  swtakt((&S_swtakt_1458_1));
  swtakt((&S_swtakt_1414_1));
  or3((&S_or3_569_1));
  or2((&S_or2_288_1));
  or2((&S_or2_297_1));
  or2((&S_or2_310_1));
  or2((&S_or2_309_1));
  and2((&S_and2_313_1));
  and2((&S_and2_308_1));
  and2((&S_and2_315_1));
  and2((&S_and2_314_1));
  and3((&S_and3_295_1));
  or5((&S_or5_499_1));
  or5((&S_or5_179_1));
  and2((&S_and2_1379_1));
  or3((&S_or3_1373_1));
  or3((&S_or3_976_1));
  zpfs((&S_zpfs_305_1));
  cnshd((&S_cnshd_167_1));
  cnshd((&S_cnshd_488_1));
  equz_p((&S_equz_p_296_1));
  noto((&S_noto_1385_1));
  cntch((&S_cntch_286_1));
  rs((&S_rs_287_1));
  cntch((&S_cntch_332_1));
  and2((&S_and2_301_1));
  or5((&S_or5_1402_1));
  or5((&S_or5_1380_1));
  and2((&S_and2_1382_1));
  or2((&S_or2_1383_1));
  and4((&S_and4_1899_1));
  and3((&S_and3_1900_1));
  and3((&S_and3_1901_1));
  and2((&S_and2_1862_1));
  and2((&S_and2_1816_1));
  or3((&S_or3_1830_1));
  newstage((&S_newstage_204_1));
  rs((&S_rs_1867_1));
  rs((&S_rs_1822_1));
  rs((&S_rs_1831_1));
  and2((&S_and2_320_1));
  or3((&S_or3_1866_1));
  and2((&S_and2_193_1));
  and2((&S_and2_189_1));
  rs((&S_rs_1704_1));
  rs((&S_rs_1707_1));
  noto((&S_noto_321_1));
  and2((&S_and2_1074_1));
  and2((&S_and2_630_1));
  or2((&S_or2_618_1));
  and2((&S_and2_1036_1));
  or2((&S_or2_1703_1));
  or2((&S_or2_1706_1));
  rs((&S_rs_619_1));
  rs((&S_rs_1702_1));
  rs((&S_rs_1031_1));
  noto((&S_noto_1032_1));
  rs((&S_rs_1066_1));
  and2((&S_and2_637_1));
  and3((&S_and3_606_1));
  and3((&S_and3_596_1));
  or3((&S_or3_801_1));
  or3((&S_or3_1189_1));
  and4((&S_and4_995_1));
  and4((&S_and4_1001_1));
  or2((&S_or2_1065_1));
  or4((&S_or4_874_1));
  or4((&S_or4_1276_1));
  ornc((&S_ornc_884_1));
  charint((&S_charint_876_1));
  ornc((&S_ornc_1286_1));
  charint((&S_charint_1278_1));
  fsumz((&S_fsumz_877_1));
  fsumz((&S_fsumz_1279_1));
  ma((&S_ma_1287_1));
  ma((&S_ma_885_1));
  fnapb((&S_fnapb_919_1));
  zpfs((&S_zpfs_911_1));
  zpfs((&S_zpfs_910_1));
  fnapb((&S_fnapb_1316_1));
  zpfs((&S_zpfs_1310_1));
  zpfs((&S_zpfs_1307_1));
  zpfs((&S_zpfs_920_1));
  zpfs((&S_zpfs_1317_1));
  and2((&S_and2_1302_1));
  and2((&S_and2_903_1));
  or5((&S_or5_902_1));
  or5((&S_or5_1301_1));
  or2((&S_or2_2190_1));
  cnshd((&S_cnshd_886_1));
  cnshd((&S_cnshd_1288_1));
  noto((&S_noto_2189_1));
  newstage((&S_newstage_898_1));
  and2((&S_and2_905_1));
  and2((&S_and2_909_1));
  andn((&S_andn_2162_1));
  noto((&S_noto_2184_1));
  and2((&S_and2_2185_1));
  or2((&S_or2_2183_1));
  and3((&S_and3_2140_1));
  or2((&S_or2_2117_1));
  rs((&S_rs_2102_1));
  rs((&S_rs_2122_1));
  and2((&S_and2_2113_1));
  rs((&S_rs_2123_1));
  or2((&S_or2_2091_1));
  rs((&S_rs_2076_1));
  rs((&S_rs_2096_1));
  and2((&S_and2_2087_1));
  rs((&S_rs_2097_1));
  or3((&S_or3_2009_1));
  or3((&S_or3_2023_1));
  and2((&S_and2_1075_1));
  and2((&S_and2_629_1));
  and2((&S_and2_1050_1));
  or2((&S_or2_1678_1));
  rs((&S_rs_1679_1));
  or2((&S_or2_1681_1));
  rs((&S_rs_1682_1));
  rs((&S_rs_2182_1));
  and2((&S_and2_2108_1));
  rs((&S_rs_2116_1));
  rs((&S_rs_2103_1));
  rs((&S_rs_2106_1));
  and2((&S_and2_2082_1));
  rs((&S_rs_2090_1));
  rs((&S_rs_2077_1));
  rs((&S_rs_2080_1));
  rs((&S_rs_1677_1));
  rs((&S_rs_1043_1));
  noto((&S_noto_1046_1));
  rs((&S_rs_1069_1));
  and3((&S_and3_1037_1));
  and2((&S_and2_986_1));
  and4((&S_and4_993_1));
  and4((&S_and4_999_1));
  rs((&S_rs_1680_1));
  or2((&S_or2_1068_1));
  and2((&S_and2_2109_1));
  orn((&S_orn_1180_1));
  and2((&S_and2_2083_1));
  orn((&S_orn_795_1));
  rs((&S_rs_2104_1));
  and2((&S_and2_2110_1));
  rs((&S_rs_2120_1));
  rs((&S_rs_2078_1));
  ornc((&S_ornc_1190_1));
  charint((&S_charint_1181_1));
  ornc((&S_ornc_802_1));
  charint((&S_charint_796_1));
  rs((&S_rs_2118_1));
  rs((&S_rs_980_1));
  or3((&S_or3_433_1));
  and3((&S_and3_440_1));
  and2((&S_and2_1025_1));
  or2((&S_or2_2005_1));
  and2((&S_and2_472_1));
  and2((&S_and2_443_1));
  and2((&S_and2_2014_1));
  rs((&S_rs_2092_1));
  and2((&S_and2_2084_1));
  rs((&S_rs_2094_1));
  fsumz((&S_fsumz_1182_1));
  fsumz((&S_fsumz_797_1));
  samhd((&S_samhd_453_1));
  samhd((&S_samhd_459_1));
  newstage((&S_newstage_455_1));
  rs((&S_rs_2006_1));
  noto((&S_noto_2007_1));
  ma((&S_ma_803_1));
  ma((&S_ma_1187_1));
  or4((&S_or4_449_1));
  or4((&S_or4_467_1));
  or2((&S_or2_2017_1));
  and2((&S_and2_464_1));
  and2((&S_and2_462_1));
  and2((&S_and2_2022_1));
  fnapb((&S_fnapb_1226_1));
  zpfs((&S_zpfs_1219_1));
  zpfs((&S_zpfs_1211_1));
  fnapb((&S_fnapb_826_1));
  rs((&S_rs_2018_1));
  noto((&S_noto_2019_1));
  zpfs((&S_zpfs_1224_1));
  and2((&S_and2_1076_1));
  and2((&S_and2_645_1));
  zpfs((&S_zpfs_827_1));
  zpfs((&S_zpfs_820_1));
  zpfs((&S_zpfs_823_1));
  or5((&S_or5_1204_1));
  and2((&S_and2_1057_1));
  or2((&S_or2_1709_1));
  rs((&S_rs_1710_1));
  or5((&S_or5_1945_1));
  orni((&S_orni_131_1));
  orn((&S_orn_411_1));
  orn((&S_orn_429_1));
  cnshd((&S_cnshd_1191_1));
  rs((&S_rs_1052_1));
  rs((&S_rs_1072_1));
  or2((&S_or2_413_1));
  or2((&S_or2_430_1));
  and2((&S_and2_673_1));
  or2((&S_or2_1142_1));
  or2((&S_or2_1143_1));
  and2((&S_and2_1089_1));
  or5((&S_or5_815_1));
  and2((&S_and2_1553_1));
  or4((&S_or4_1549_1));
  or4((&S_or4_1946_1));
  orn((&S_orn_759_1));
  orn((&S_orn_1077_1));
  cnshd((&S_cnshd_806_1));
  or2((&S_or2_749_1));
  or2((&S_or2_750_1));
  or4((&S_or4_730_1));
  or5((&S_or5_1115_1));
  or2((&S_or2_355_1));
  or2((&S_or2_359_1));
  ovbs((&S_ovbs_1952_1));
  noto((&S_noto_1953_1));
  and2((&S_and2_1959_1));
  and2((&S_and2_1971_1));
  or3((&S_or3_1947_1));
  and2((&S_and2_1948_1));
  or3((&S_or3_1961_1));
  and2((&S_and2_1962_1));
  or5((&S_or5_1540_1));
  or2((&S_or2_2173_1));
  rs((&S_rs_729_1));
  samhd((&S_samhd_358_1));
  newstage((&S_newstage_1231_1));
  and2((&S_and2_717_1));
  or2((&S_or2_721_1));
  or4((&S_or4_357_1));
  or5((&S_or5_1577_1));
  or2((&S_or2_1966_1));
  or2((&S_or2_1954_1));
  ovbs((&S_ovbs_1949_1));
  ovbs((&S_ovbs_1963_1));
  rs((&S_rs_1982_1));
  rs((&S_rs_1990_1));
  noto((&S_noto_1980_1));
  noto((&S_noto_2001_1));
  andn((&S_andn_1_1));
  and2((&S_and2_1215_1));
  and2((&S_and2_1218_1));
  zpfs((&S_zpfs_1983_1));
  zpfs((&S_zpfs_1991_1));
  noto((&S_noto_2169_1));
  rs((&S_rs_723_1));
  or2((&S_or2_1984_1));
  noto((&S_noto_1950_1));
  noto((&S_noto_1964_1));
  rs((&S_rs_1967_1));
  noto((&S_noto_1968_1));
  rs((&S_rs_1955_1));
  or2((&S_or2_1992_1));
  noto((&S_noto_1985_1));
  and2((&S_and2_1986_1));
  and2((&S_and2_1981_1));
  noto((&S_noto_1993_1));
  noto((&S_noto_1973_1));
  noto((&S_noto_1956_1));
  and2((&S_and2_1994_1));
  and4((&S_and4_1975_1));
  ovbs((&S_ovbs_1976_1));
  and2((&S_and2_2002_1));
  noto((&S_noto_2003_1));
  or2((&S_or2_1977_1));
  orn((&S_orn_589_1));
  orn((&S_orn_588_1));
  noto((&S_noto_1978_1));
  and4((&S_and4_1996_1));
  ovbs((&S_ovbs_1997_1));
  or2((&S_or2_1998_1));
  newstage((&S_newstage_591_1));
  or2((&S_or2_625_1));
  ovbs((&S_ovbs_1987_1));
  noto((&S_noto_1999_1));
  and2((&S_and2_624_1));
  signal_B3AB13LDU.b = var78.b;
  signal_B3AB13LDU.error = var78.error;
  signal_A3AB13LDU.b = var81.b;
  signal_A3AB13LDU.error = var81.error;
  signal_R3VS01IDU.i = var87.i;
  signal_R3VS01IDU.error = var87.error;
  signal_R3VS12LDU.b = var85.b;
  signal_R3VS12LDU.error = var85.error;
  signal_R3VS22LDU.b = var86.b;
  signal_R3VS22LDU.error = var86.error;
  signal_R5VS01IDU.i = var84.i;
  signal_R5VS01IDU.error = var84.error;
  signal_R5VS12LDU.b = var82.b;
  signal_R5VS12LDU.error = var82.error;
  signal_R5VS22LDU.b = var83.b;
  signal_R5VS22LDU.error = var83.error;
  signal_B3AB15LDU.b = var91.b;
  signal_B3AB15LDU.error = var91.error;
  signal_B3EE03LDU.b = var777.b;
  signal_B3EE03LDU.error = var777.error;
  signal_A3EE03LDU.b = var778.b;
  signal_A3EE03LDU.error = var778.error;
  signal_B3AB19LDU.b = var96.b;
  signal_B3AB19LDU.error = var96.error;
  signal_A3AB19LDU.b = var97.b;
  signal_A3AB19LDU.error = var97.error;
  signal_R0VL23LDU.b = var1013.b;
  signal_R0VL23LDU.error = var1013.error;
  signal_R0VL22LDU.b = var1035.b;
  signal_R0VL22LDU.error = var1035.error;
  signal_R0AD05LZ2.b = var18.b;
  signal_R0AD05LZ2.error = var18.error;
  signal_R0AD05LZ1.b = var18.b;
  signal_R0AD05LZ1.error = var18.error;
  signal_R0AD04LZ2.b = var323.b;
  signal_R0AD04LZ2.error = var323.error;
  signal_R0AD04LZ1.b = var323.b;
  signal_R0AD04LZ1.error = var323.error;
  signal_R0AD03LZ2.b = var17.b;
  signal_R0AD03LZ2.error = var17.error;
  signal_R0AD03LZ1.b = var17.b;
  signal_R0AD03LZ1.error = var17.error;
  signal_R0CN95LDU.i = var167.i;
  signal_R0CN95LDU.error = var167.error;
  fplet(&signal_R0CN94LDU.f,&var166.f);
  signal_R0CN94LDU.error = var166.error;
  fplet(&signal_R0CN93LDU.f,&var165.f);
  signal_R0CN93LDU.error = var165.error;
  signal_R0AB19LDU.b = var128.b;
  signal_R0AB19LDU.error = var128.error;
  fplet(&signal_R0VN12RDU.f,&var946.f);
  signal_R0VN12RDU.error = var946.error;
  fplet(&signal_R0VN11RDU.f,&var944.f);
  signal_R0VN11RDU.error = var944.error;
  fplet(&signal_R0CN92LDU.f,&var132.f);
  signal_R0CN92LDU.error = var132.error;
  signal_R0AB20LDU.b = var144.b;
  signal_R0AB20LDU.error = var144.error;
  signal_A3AB15LDU.b = var92.b;
  signal_A3AB15LDU.error = var92.error;
  fplet(&signal_A3MC03RDU.f,&var163.f);
  signal_A3MC03RDU.error = var163.error;
  fplet(&signal_R0CN91LDU.f,&var162.f);
  signal_R0CN91LDU.error = var162.error;
  fplet(&signal_A3MC02RDU.f,&var161.f);
  signal_A3MC02RDU.error = var161.error;
  fplet(&signal_A3MC01RDU.f,&var160.f);
  signal_A3MC01RDU.error = var160.error;
  signal_R0AB18LDU.b = var149.b;
  signal_R0AB18LDU.error = var149.error;
  signal_R0AB17LDU.b = var156.b;
  signal_R0AB17LDU.error = var156.error;
  signal_R0AB16LDU.b = var157.b;
  signal_R0AB16LDU.error = var157.error;
  signal_B1AB19LDU.b = var174.b;
  signal_B1AB19LDU.error = var174.error;
  signal_A3ZAV.b = var1289.b;
  signal_A3ZAV.error = var1289.error;
  signal_A1ZAV.b = var1352.b;
  signal_A1ZAV.error = var1352.error;
  signal_B3IS12LDU.b = var184.b;
  signal_B3IS12LDU.error = var184.error;
  signal_A3IS12LDU.b = var185.b;
  signal_A3IS12LDU.error = var185.error;
  signal_R0AB15LDU.b = var190.b;
  signal_R0AB15LDU.error = var190.error;
  signal_R0AB14LDU.b = var188.b;
  signal_R0AB14LDU.error = var188.error;
  signal_A4DW.b = var1123.b;
  signal_A4DW.error = var1123.error;
  signal_A4UP.b = var1124.b;
  signal_A4UP.error = var1124.error;
  signal_R4ABL.b = var1591.b;
  signal_R4ABL.error = var1591.error;
  signal_A9ZAV.b = var1227.b;
  signal_A9ZAV.error = var1227.error;
  signal_A8ZAV.b = var1428.b;
  signal_A8ZAV.error = var1428.error;
  signal_A2ZAV.b = var1433.b;
  signal_A2ZAV.error = var1433.error;
  signal_B8ZAV.b = var1438.b;
  signal_B8ZAV.error = var1438.error;
  signal_A5ZAV.b = var1506.b;
  signal_A5ZAV.error = var1506.error;
  signal_R2ZAV.b = var1382.b;
  signal_R2ZAV.error = var1382.error;
  signal_A6ZAV.b = var1508.b;
  signal_A6ZAV.error = var1508.error;
  signal_A4ZAV.b = var1507.b;
  signal_A4ZAV.error = var1507.error;
  signal_R0AB13LDU.b = var261.b;
  signal_R0AB13LDU.error = var261.error;
  signal_R0AB12LDU.b = var265.b;
  signal_R0AB12LDU.error = var265.error;
  signal_R0AB11LDU.b = var269.b;
  signal_R0AB11LDU.error = var269.error;
  signal_R0AB10LDU.b = var273.b;
  signal_R0AB10LDU.error = var273.error;
  signal_R0AB09LDU.b = var277.b;
  signal_R0AB09LDU.error = var277.error;
  signal_R0AB08LDU.b = var281.b;
  signal_R0AB08LDU.error = var281.error;
  signal_B6AB05LDU.b = var324.b;
  signal_B6AB05LDU.error = var324.error;
  signal_R0VS11LDU.b = var1637.b;
  signal_R0VS11LDU.error = var1637.error;
  signal_A8VS01IDU.i = var1432.c;
  signal_A8VS01IDU.error = var1432.error;
  signal_B8VS01IDU.i = var1442.c;
  signal_B8VS01IDU.error = var1442.error;
  signal_R2AD10LDU.b = var1387.b;
  signal_R2AD10LDU.error = var1387.error;
  signal_R2AD20LDU.b = var1388.b;
  signal_R2AD20LDU.error = var1388.error;
  signal_B6VS01IDU.i = var1579.i;
  signal_B6VS01IDU.error = var1579.error;
  signal_R0AD16LDU.b = var347.b;
  signal_R0AD16LDU.error = var347.error;
  signal_R0AB07LDU.b = var577.b;
  signal_R0AB07LDU.error = var577.error;
  signal_R0EE03LDU.b = var348.b;
  signal_R0EE03LDU.error = var348.error;
  signal_R0VX02LDU.b = var783.b;
  signal_R0VX02LDU.error = var783.error;
  signal_R0AD21LDU.b = var781.b;
  signal_R0AD21LDU.error = var781.error;
  signal_B2AB15LDU.b = var294.b;
  signal_B2AB15LDU.error = var294.error;
  signal_A2AB15LDU.b = var295.b;
  signal_A2AB15LDU.error = var295.error;
  signal_R0AB05LDU.b = var1095.b;
  signal_R0AB05LDU.error = var1095.error;
  signal_R0AB03LDU.b = var1106.b;
  signal_R0AB03LDU.error = var1106.error;
  signal_A1AB19LDU.b = var175.b;
  signal_A1AB19LDU.error = var175.error;
  signal_R0VZ71LDU.b = var2.b;
  signal_R0VZ71LDU.error = var2.error;
  fplet(&signal_R0VL01RDU.f,&var1142.f);
  signal_R0VL01RDU.error = var1142.error;
  signal_B7AZ03LDU.b = var325.b;
  signal_B7AZ03LDU.error = var325.error;
  signal_A7AZ03LDU.b = var433.b;
  signal_A7AZ03LDU.error = var433.error;
  signal_B2VS01IDU.i = var1420.c;
  signal_B2VS01IDU.error = var1420.error;
  signal_B2VS21LDU.b = var1422.b;
  signal_B2VS21LDU.error = var1422.error;
  signal_B2VS11LDU.b = var1421.b;
  signal_B2VS11LDU.error = var1421.error;
  signal_R0VP73LDU.b = var444.b;
  signal_R0VP73LDU.error = var444.error;
  signal_R0VS18LDU.b = var535.b;
  signal_R0VS18LDU.error = var535.error;
  signal_B3VX01LDU.b = var391.b;
  signal_B3VX01LDU.error = var391.error;
  signal_A3VX01LDU.b = var392.b;
  signal_A3VX01LDU.error = var392.error;
  signal_B2VS32LDU.b = var307.b;
  signal_B2VS32LDU.error = var307.error;
  signal_A2VS32LDU.b = var308.b;
  signal_A2VS32LDU.error = var308.error;
  signal_R0VS17LDU.b = var525.b;
  signal_R0VS17LDU.error = var525.error;
  signal_R0VX09LDU.b = var120.b;
  signal_R0VX09LDU.error = var120.error;
  signal_R0VX08IDU.i = signal_R0MW12IP1.i;
  signal_R0VX08IDU.error = signal_R0MW12IP1.error;
  signal_R0VW23LDU.b = var878.b;
  signal_R0VW23LDU.error = var878.error;
  signal_R0VW13LDU.b = var877.b;
  signal_R0VW13LDU.error = var877.error;
  signal_B7AP31LDU.b = var1126.b;
  signal_B7AP31LDU.error = var1126.error;
  signal_A7AP31LDU.b = var1127.b;
  signal_A7AP31LDU.error = var1127.error;
  signal_B3AD31LDU.b = var1190.b;
  signal_B3AD31LDU.error = var1190.error;
  signal_B3AD34LDU.b = var1191.b;
  signal_B3AD34LDU.error = var1191.error;
  signal_A3AD31LDU.b = var1196.b;
  signal_A3AD31LDU.error = var1196.error;
  signal_A3AD34LDU.b = var1193.b;
  signal_A3AD34LDU.error = var1193.error;
  signal_A3AD33LDU.b = var1195.b;
  signal_A3AD33LDU.error = var1195.error;
  signal_B2AD33LDU.b = var286.b;
  signal_B2AD33LDU.error = var286.error;
  signal_A2AD33LDU.b = var289.b;
  signal_A2AD33LDU.error = var289.error;
  signal_R0AB01LDU.b = var1219.b;
  signal_R0AB01LDU.error = var1219.error;
  signal_B9AB02LDU.b = var1229.b;
  signal_B9AB02LDU.error = var1229.error;
  signal_B9AB01LDU.b = var1230.b;
  signal_B9AB01LDU.error = var1230.error;
  signal_B9AZ03LDU.b = var1228.b;
  signal_B9AZ03LDU.error = var1228.error;
  signal_A9AB02LDU.b = var1235.b;
  signal_A9AB02LDU.error = var1235.error;
  signal_A9AB01LDU.b = var1236.b;
  signal_A9AB01LDU.error = var1236.error;
  signal_A9AZ03LDU.b = var1234.b;
  signal_A9AZ03LDU.error = var1234.error;
  signal_A9AD10LDU.b = var1237.b;
  signal_A9AD10LDU.error = var1237.error;
  signal_B9AD10LDU.b = var1231.b;
  signal_B9AD10LDU.error = var1231.error;
  signal_R1VS01IDU.i = var1398.i;
  signal_R1VS01IDU.error = var1398.error;
  signal_R2VS01IDU.i = var1389.i;
  signal_R2VS01IDU.error = var1389.error;
  signal_R4VS01IDU.i = var1570.i;
  signal_R4VS01IDU.error = var1570.error;
  signal_A6VS01IDU.i = var1588.i;
  signal_A6VS01IDU.error = var1588.error;
  signal_B5VS01IDU.i = var1552.i;
  signal_B5VS01IDU.error = var1552.error;
  signal_A5VS01IDU.i = var1561.i;
  signal_A5VS01IDU.error = var1561.error;
  signal_B4VS22LDU.b = var1533.b;
  signal_B4VS22LDU.error = var1533.error;
  signal_B4VS12LDU.b = var1532.b;
  signal_B4VS12LDU.error = var1532.error;
  signal_B4VS01IDU.i = var1534.i;
  signal_B4VS01IDU.error = var1534.error;
  signal_A4VS22LDU.b = var1542.b;
  signal_A4VS22LDU.error = var1542.error;
  signal_A4VS12LDU.b = var1541.b;
  signal_A4VS12LDU.error = var1541.error;
  signal_A4VS01IDU.i = var1543.i;
  signal_A4VS01IDU.error = var1543.error;
  signal_A2VS01IDU.i = var1461.c;
  signal_A2VS01IDU.error = var1461.error;
  signal_B3VS01IDU.i = var1279.c;
  signal_B3VS01IDU.error = var1279.error;
  signal_A3VS01IDU.i = var1311.c;
  signal_A3VS01IDU.error = var1311.error;
  signal_B1VS01IDU.i = var1340.c;
  signal_B1VS01IDU.error = var1340.error;
  signal_A1VS01IDU.i = var1373.c;
  signal_A1VS01IDU.error = var1373.error;
  signal_R0VS21IDU.i = var1116.i;
  signal_R0VS21IDU.error = var1116.error;
  signal_R0VX03LDU.b = var728.b;
  signal_R0VX03LDU.error = var728.error;
  signal_R0VL21IDU.i = var1026.i;
  signal_R0VL21IDU.error = var1026.error;
  fplet(&signal_R0VL05RDU.f,&var378.f);
  signal_R0VL05RDU.error = var378.error;
  fplet(&signal_R0VL03RDU.f,&var384.f);
  signal_R0VL03RDU.error = var384.error;
  signal_R0AB02LDU.b = var1089.b;
  signal_R0AB02LDU.error = var1089.error;
  signal_R0AB06LDU.b = var1092.b;
  signal_R0AB06LDU.error = var1092.error;
  signal_R0AB04LDU.b = var1100.b;
  signal_R0AB04LDU.error = var1100.error;
  fplet(&signal_R0VL04RDU.f,&var381.f);
  signal_R0VL04RDU.error = var381.error;
  signal_R0AD14LDU.b = var323.b;
  signal_R0AD14LDU.error = var323.error;
  signal_R8AD21LDU.b = var346.b;
  signal_R8AD21LDU.error = var346.error;
  fplet(&signal_R0VL02RDU.f,&var375.f);
  signal_R0VL02RDU.error = var375.error;
  signal_B3AD33LDU.b = var1189.b;
  signal_B3AD33LDU.error = var1189.error;
  fplet(&signal_R0VL06RDU.f,&var388.f);
  signal_R0VL06RDU.error = var388.error;
  signal_R0VL11IDU.i = var1243.i;
  signal_R0VL11IDU.error = var1243.error;
  signal_R0VL01IDU.i = var1244.i;
  signal_R0VL01IDU.error = var1244.error;
  signal_R0VX01LDU.b = var785.b;
  signal_R0VX01LDU.error = var785.error;
  signal_B1AD32LDU.b = var1197.b;
  signal_B1AD32LDU.error = var1197.error;
  signal_A1AD32LDU.b = var1199.b;
  signal_A1AD32LDU.error = var1199.error;
  signal_B2AD32LDU.b = var314.b;
  signal_B2AD32LDU.error = var314.error;
  signal_A2AD32LDU.b = var316.b;
  signal_A2AD32LDU.error = var316.error;
  signal_B1AD31LDU.b = var1200.b;
  signal_B1AD31LDU.error = var1200.error;
  signal_A1AD31LDU.b = var1201.b;
  signal_A1AD31LDU.error = var1201.error;
  signal_B2AD31LDU.b = var317.b;
  signal_B2AD31LDU.error = var317.error;
  signal_A2AD31LDU.b = var318.b;
  signal_A2AD31LDU.error = var318.error;
  signal_B3AB20LDU.b = var619.b;
  signal_B3AB20LDU.error = var619.error;
  signal_B3AB18LDU.b = var616.b;
  signal_B3AB18LDU.error = var616.error;
  signal_B3AB17LDU.b = var612.b;
  signal_B3AB17LDU.error = var612.error;
  signal_B3AB16LDU.b = var613.b;
  signal_B3AB16LDU.error = var613.error;
  signal_B3AB14LDU.b = var887.b;
  signal_B3AB14LDU.error = var887.error;
  signal_B3AB12LDU.b = var617.b;
  signal_B3AB12LDU.error = var617.error;
  signal_B3AB11LDU.b = var621.b;
  signal_B3AB11LDU.error = var621.error;
  signal_B3AB10LDU.b = var622.b;
  signal_B3AB10LDU.error = var622.error;
  signal_B3AB09LDU.b = var623.b;
  signal_B3AB09LDU.error = var623.error;
  signal_B3AB06LDU.b = var626.b;
  signal_B3AB06LDU.error = var626.error;
  signal_B3AB05LDU.b = var628.b;
  signal_B3AB05LDU.error = var628.error;
  signal_B3AB08LDU.b = var618.b;
  signal_B3AB08LDU.error = var618.error;
  signal_B3AB07LDU.b = var627.b;
  signal_B3AB07LDU.error = var627.error;
  fplet(&signal_B3CV02RDU.f,&var1278.f);
  signal_B3CV02RDU.error = var1278.error;
  signal_B3AD01LDU.b = var1271.b;
  signal_B3AD01LDU.error = var1271.error;
  signal_B3AD05LDU.b = var1277.b;
  signal_B3AD05LDU.error = var1277.error;
  signal_B3AD04LDU.b = var1276.b;
  signal_B3AD04LDU.error = var1276.error;
  signal_B3AD03LDU.b = var1275.b;
  signal_B3AD03LDU.error = var1275.error;
  signal_B3AD02LDU.b = var1274.b;
  signal_B3AD02LDU.error = var1274.error;
  signal_B3AD21LDU.b = var1272.b;
  signal_B3AD21LDU.error = var1272.error;
  signal_B3AD11LDU.b = var1273.b;
  signal_B3AD11LDU.error = var1273.error;
  signal_B3AZ03LDU.b = var959.b;
  signal_B3AZ03LDU.error = var959.error;
  signal_B3VS22LDU.b = var1282.b;
  signal_B3VS22LDU.error = var1282.error;
  signal_B3AB01LDU.b = var1280.b;
  signal_B3AB01LDU.error = var1280.error;
  signal_B3AB02LDU.b = var1281.b;
  signal_B3AB02LDU.error = var1281.error;
  signal_B3AB04LDU.b = var1286.b;
  signal_B3AB04LDU.error = var1286.error;
  fplet(&signal_B3CV01RDU.f,&var1284.f);
  signal_B3CV01RDU.error = var1284.error;
  signal_B3VS12LDU.b = var1283.b;
  signal_B3VS12LDU.error = var1283.error;
  signal_A3AB20LDU.b = var356.b;
  signal_A3AB20LDU.error = var356.error;
  signal_A3AB18LDU.b = var633.b;
  signal_A3AB18LDU.error = var633.error;
  signal_A3AB17LDU.b = var631.b;
  signal_A3AB17LDU.error = var631.error;
  signal_A3AB16LDU.b = var630.b;
  signal_A3AB16LDU.error = var630.error;
  signal_A3AB14LDU.b = var889.b;
  signal_A3AB14LDU.error = var889.error;
  signal_A3AB12LDU.b = var634.b;
  signal_A3AB12LDU.error = var634.error;
  signal_A3AB11LDU.b = var638.b;
  signal_A3AB11LDU.error = var638.error;
  signal_A3AB10LDU.b = var642.b;
  signal_A3AB10LDU.error = var642.error;
  signal_A3AB09LDU.b = var636.b;
  signal_A3AB09LDU.error = var636.error;
  signal_A3AB06LDU.b = var641.b;
  signal_A3AB06LDU.error = var641.error;
  signal_A3AB05LDU.b = var644.b;
  signal_A3AB05LDU.error = var644.error;
  signal_A3AB08LDU.b = var635.b;
  signal_A3AB08LDU.error = var635.error;
  signal_A3AB07LDU.b = var643.b;
  signal_A3AB07LDU.error = var643.error;
  fplet(&signal_A3CV02RDU.f,&var1310.f);
  signal_A3CV02RDU.error = var1310.error;
  signal_A3AD01LDU.b = var1303.b;
  signal_A3AD01LDU.error = var1303.error;
  signal_A3AD05LDU.b = var1309.b;
  signal_A3AD05LDU.error = var1309.error;
  signal_A3AD04LDU.b = var1308.b;
  signal_A3AD04LDU.error = var1308.error;
  signal_A3AD03LDU.b = var1307.b;
  signal_A3AD03LDU.error = var1307.error;
  signal_A3AD02LDU.b = var1306.b;
  signal_A3AD02LDU.error = var1306.error;
  signal_A3AD21LDU.b = var1304.b;
  signal_A3AD21LDU.error = var1304.error;
  signal_A3AD11LDU.b = var1305.b;
  signal_A3AD11LDU.error = var1305.error;
  signal_A3AZ03LDU.b = var960.b;
  signal_A3AZ03LDU.error = var960.error;
  signal_A3VS22LDU.b = var1314.b;
  signal_A3VS22LDU.error = var1314.error;
  signal_A3AB01LDU.b = var1312.b;
  signal_A3AB01LDU.error = var1312.error;
  signal_A3AB02LDU.b = var1313.b;
  signal_A3AB02LDU.error = var1313.error;
  signal_A3AB04LDU.b = var1318.b;
  signal_A3AB04LDU.error = var1318.error;
  fplet(&signal_A3CV01RDU.f,&var1316.f);
  signal_A3CV01RDU.error = var1316.error;
  signal_A3VS12LDU.b = var1315.b;
  signal_A3VS12LDU.error = var1315.error;
  signal_B1AB18LDU.b = var703.b;
  signal_B1AB18LDU.error = var703.error;
  signal_B1AB17LDU.b = var872.b;
  signal_B1AB17LDU.error = var872.error;
  signal_B1AB16LDU.b = var871.b;
  signal_B1AB16LDU.error = var871.error;
  signal_B1AB14LDU.b = var891.b;
  signal_B1AB14LDU.error = var891.error;
  signal_B1AB13LDU.b = var892.b;
  signal_B1AB13LDU.error = var892.error;
  signal_B1AB12LDU.b = var701.b;
  signal_B1AB12LDU.error = var701.error;
  signal_B1AB11LDU.b = var705.b;
  signal_B1AB11LDU.error = var705.error;
  signal_B1AB10LDU.b = var706.b;
  signal_B1AB10LDU.error = var706.error;
  signal_B1AB09LDU.b = var709.b;
  signal_B1AB09LDU.error = var709.error;
  signal_B1AB06LDU.b = var707.b;
  signal_B1AB06LDU.error = var707.error;
  signal_B1AB05LDU.b = var714.b;
  signal_B1AB05LDU.error = var714.error;
  signal_B1AB08LDU.b = var702.b;
  signal_B1AB08LDU.error = var702.error;
  signal_B1AB07LDU.b = var713.b;
  signal_B1AB07LDU.error = var713.error;
  fplet(&signal_B1CV02RDU.f,&var1339.f);
  signal_B1CV02RDU.error = var1339.error;
  signal_B1AD01LDU.b = var1332.b;
  signal_B1AD01LDU.error = var1332.error;
  signal_B1AD05LDU.b = var1338.b;
  signal_B1AD05LDU.error = var1338.error;
  signal_B1AD04LDU.b = var1337.b;
  signal_B1AD04LDU.error = var1337.error;
  signal_B1AD03LDU.b = var1336.b;
  signal_B1AD03LDU.error = var1336.error;
  signal_B1AD02LDU.b = var1335.b;
  signal_B1AD02LDU.error = var1335.error;
  signal_B1AD21LDU.b = var1334.b;
  signal_B1AD21LDU.error = var1334.error;
  signal_B1AD11LDU.b = var1333.b;
  signal_B1AD11LDU.error = var1333.error;
  signal_B1AZ03LDU.b = var716.b;
  signal_B1AZ03LDU.error = var716.error;
  signal_B1VS22LDU.b = var1344.b;
  signal_B1VS22LDU.error = var1344.error;
  signal_B1AB01LDU.b = var1341.b;
  signal_B1AB01LDU.error = var1341.error;
  signal_B1AB02LDU.b = var1342.b;
  signal_B1AB02LDU.error = var1342.error;
  signal_B1AB04LDU.b = var1347.b;
  signal_B1AB04LDU.error = var1347.error;
  fplet(&signal_B1CV01RDU.f,&var1345.f);
  signal_B1CV01RDU.error = var1345.error;
  signal_B1VS12LDU.b = var1343.b;
  signal_B1VS12LDU.error = var1343.error;
  signal_A1AB18LDU.b = var679.b;
  signal_A1AB18LDU.error = var679.error;
  signal_A1AB17LDU.b = var678.b;
  signal_A1AB17LDU.error = var678.error;
  signal_A1AB16LDU.b = var680.b;
  signal_A1AB16LDU.error = var680.error;
  signal_A1AB14LDU.b = var894.b;
  signal_A1AB14LDU.error = var894.error;
  signal_A1AB13LDU.b = var895.b;
  signal_A1AB13LDU.error = var895.error;
  signal_A1AB12LDU.b = var676.b;
  signal_A1AB12LDU.error = var676.error;
  signal_A1AB11LDU.b = var685.b;
  signal_A1AB11LDU.error = var685.error;
  signal_A1AB10LDU.b = var683.b;
  signal_A1AB10LDU.error = var683.error;
  signal_A1AB09LDU.b = var682.b;
  signal_A1AB09LDU.error = var682.error;
  signal_A1AB06LDU.b = var687.b;
  signal_A1AB06LDU.error = var687.error;
  signal_A1AB05LDU.b = var688.b;
  signal_A1AB05LDU.error = var688.error;
  signal_A1AB08LDU.b = var681.b;
  signal_A1AB08LDU.error = var681.error;
  signal_A1AB07LDU.b = var689.b;
  signal_A1AB07LDU.error = var689.error;
  fplet(&signal_A1CV02RDU.f,&var1372.f);
  signal_A1CV02RDU.error = var1372.error;
  signal_A1AD01LDU.b = var1365.b;
  signal_A1AD01LDU.error = var1365.error;
  signal_A1AD05LDU.b = var1371.b;
  signal_A1AD05LDU.error = var1371.error;
  signal_A1AD04LDU.b = var1370.b;
  signal_A1AD04LDU.error = var1370.error;
  signal_A1AD03LDU.b = var1369.b;
  signal_A1AD03LDU.error = var1369.error;
  signal_A1AD02LDU.b = var1368.b;
  signal_A1AD02LDU.error = var1368.error;
  signal_A1AD21LDU.b = var1367.b;
  signal_A1AD21LDU.error = var1367.error;
  signal_A1AD11LDU.b = var1366.b;
  signal_A1AD11LDU.error = var1366.error;
  signal_A1AZ03LDU.b = var696.b;
  signal_A1AZ03LDU.error = var696.error;
  signal_A1VS22LDU.b = var1375.b;
  signal_A1VS22LDU.error = var1375.error;
  signal_A1AB01LDU.b = var694.b;
  signal_A1AB01LDU.error = var694.error;
  signal_A1AB02LDU.b = var695.b;
  signal_A1AB02LDU.error = var695.error;
  signal_A1AB04LDU.b = var1378.b;
  signal_A1AB04LDU.error = var1378.error;
  fplet(&signal_A1CV01RDU.f,&var1376.f);
  signal_A1CV01RDU.error = var1376.error;
  signal_A1VS12LDU.b = var1374.b;
  signal_A1VS12LDU.error = var1374.error;
  signal_R1AD20LDU.b = var1397.b;
  signal_R1AD20LDU.error = var1397.error;
  signal_R1AD10LDU.b = var1396.b;
  signal_R1AD10LDU.error = var1396.error;
  signal_R2AB04LDU.b = var1385.b;
  signal_R2AB04LDU.error = var1385.error;
  signal_R1AB04LDU.b = var1394.b;
  signal_R1AB04LDU.error = var1394.error;
  signal_R2AB02LDU.b = var1384.b;
  signal_R2AB02LDU.error = var1384.error;
  signal_R2AB01LDU.b = var1386.b;
  signal_R2AB01LDU.error = var1386.error;
  signal_R2AZ03LDU.b = var1383.b;
  signal_R2AZ03LDU.error = var1383.error;
  signal_R1AB02LDU.b = var1393.b;
  signal_R1AB02LDU.error = var1393.error;
  signal_R1AB01LDU.b = var1395.b;
  signal_R1AB01LDU.error = var1395.error;
  signal_R1AZ03LDU.b = var1392.b;
  signal_R1AZ03LDU.error = var1392.error;
  signal_B2AB17LDU.b = var652.b;
  signal_B2AB17LDU.error = var652.error;
  signal_B2AB16LDU.b = var651.b;
  signal_B2AB16LDU.error = var651.error;
  signal_B2AB14LDU.b = var896.b;
  signal_B2AB14LDU.error = var896.error;
  signal_B2AB13LDU.b = var897.b;
  signal_B2AB13LDU.error = var897.error;
  signal_B2AB12LDU.b = var653.b;
  signal_B2AB12LDU.error = var653.error;
  signal_B2AB11LDU.b = var657.b;
  signal_B2AB11LDU.error = var657.error;
  signal_B2AB10LDU.b = var656.b;
  signal_B2AB10LDU.error = var656.error;
  signal_B2AB09LDU.b = var655.b;
  signal_B2AB09LDU.error = var655.error;
  signal_B2AB06LDU.b = var660.b;
  signal_B2AB06LDU.error = var660.error;
  signal_B2AB05LDU.b = var659.b;
  signal_B2AB05LDU.error = var659.error;
  signal_B2AB08LDU.b = var654.b;
  signal_B2AB08LDU.error = var654.error;
  signal_B2AB07LDU.b = var661.b;
  signal_B2AB07LDU.error = var661.error;
  fplet(&signal_B2CV02RDU.f,&var1419.f);
  signal_B2CV02RDU.error = var1419.error;
  signal_B2AD01LDU.b = var1412.b;
  signal_B2AD01LDU.error = var1412.error;
  signal_B2AD05LDU.b = var1418.b;
  signal_B2AD05LDU.error = var1418.error;
  signal_B2AD04LDU.b = var1417.b;
  signal_B2AD04LDU.error = var1417.error;
  signal_B2AD03LDU.b = var1416.b;
  signal_B2AD03LDU.error = var1416.error;
  signal_B2AD02LDU.b = var1415.b;
  signal_B2AD02LDU.error = var1415.error;
  signal_B2AD21LDU.b = var1414.b;
  signal_B2AD21LDU.error = var1414.error;
  signal_B2AD11LDU.b = var1413.b;
  signal_B2AD11LDU.error = var1413.error;
  signal_B2AZ03LDU.b = var669.b;
  signal_B2AZ03LDU.error = var669.error;
  signal_B2AB01LDU.b = var668.b;
  signal_B2AB01LDU.error = var668.error;
  signal_B2AB02LDU.b = var667.b;
  signal_B2AB02LDU.error = var667.error;
  signal_B2AB04LDU.b = var1425.b;
  signal_B2AB04LDU.error = var1425.error;
  fplet(&signal_B2CV01RDU.f,&var1423.f);
  signal_B2CV01RDU.error = var1423.error;
  fplet(&signal_A2CV02RDU.f,&var1460.f);
  signal_A2CV02RDU.error = var1460.error;
  signal_A2AD01LDU.b = var1453.b;
  signal_A2AD01LDU.error = var1453.error;
  signal_A2AB17LDU.b = var590.b;
  signal_A2AB17LDU.error = var590.error;
  signal_A2AB16LDU.b = var591.b;
  signal_A2AB16LDU.error = var591.error;
  signal_A2AB14LDU.b = var594.b;
  signal_A2AB14LDU.error = var594.error;
  signal_A2AB13LDU.b = var595.b;
  signal_A2AB13LDU.error = var595.error;
  signal_A2AB12LDU.b = var592.b;
  signal_A2AB12LDU.error = var592.error;
  signal_A2AB11LDU.b = var600.b;
  signal_A2AB11LDU.error = var600.error;
  signal_A2AB10LDU.b = var598.b;
  signal_A2AB10LDU.error = var598.error;
  signal_A2AB09LDU.b = var596.b;
  signal_A2AB09LDU.error = var596.error;
  signal_A2AB06LDU.b = var601.b;
  signal_A2AB06LDU.error = var601.error;
  signal_A2AB05LDU.b = var597.b;
  signal_A2AB05LDU.error = var597.error;
  signal_A2AB08LDU.b = var593.b;
  signal_A2AB08LDU.error = var593.error;
  signal_A2AB07LDU.b = var599.b;
  signal_A2AB07LDU.error = var599.error;
  signal_A2AD05LDU.b = var1459.b;
  signal_A2AD05LDU.error = var1459.error;
  signal_A2AD04LDU.b = var1458.b;
  signal_A2AD04LDU.error = var1458.error;
  signal_A2AD03LDU.b = var1457.b;
  signal_A2AD03LDU.error = var1457.error;
  signal_A2AD02LDU.b = var1456.b;
  signal_A2AD02LDU.error = var1456.error;
  signal_A2AD21LDU.b = var1455.b;
  signal_A2AD21LDU.error = var1455.error;
  signal_A2AD11LDU.b = var1454.b;
  signal_A2AD11LDU.error = var1454.error;
  signal_A2AZ03LDU.b = var961.b;
  signal_A2AZ03LDU.error = var961.error;
  signal_A2VS21LDU.b = var1465.b;
  signal_A2VS21LDU.error = var1465.error;
  signal_A2AB01LDU.b = var1462.b;
  signal_A2AB01LDU.error = var1462.error;
  signal_A2AB02LDU.b = var1463.b;
  signal_A2AB02LDU.error = var1463.error;
  signal_A2AB04LDU.b = var1468.b;
  signal_A2AB04LDU.error = var1468.error;
  fplet(&signal_A2CV01RDU.f,&var1466.f);
  signal_A2CV01RDU.error = var1466.error;
  signal_A2VS11LDU.b = var1464.b;
  signal_A2VS11LDU.error = var1464.error;
  signal_A8AB01LDU.b = var1476.b;
  signal_A8AB01LDU.error = var1476.error;
  signal_A8AB02LDU.b = var472.b;
  signal_A8AB02LDU.error = var472.error;
  signal_A8AB14LDU.b = var473.b;
  signal_A8AB14LDU.error = var473.error;
  signal_A8AB13LDU.b = var474.b;
  signal_A8AB13LDU.error = var474.error;
  signal_A8AB12LDU.b = var476.b;
  signal_A8AB12LDU.error = var476.error;
  signal_A8AB11LDU.b = var477.b;
  signal_A8AB11LDU.error = var477.error;
  signal_A8AB10LDU.b = var478.b;
  signal_A8AB10LDU.error = var478.error;
  signal_A8AB09LDU.b = var479.b;
  signal_A8AB09LDU.error = var479.error;
  signal_A8AB08LDU.b = var480.b;
  signal_A8AB08LDU.error = var480.error;
  signal_A8AB04LDU.b = var1475.b;
  signal_A8AB04LDU.error = var1475.error;
  signal_A8AD20LDU.b = var1431.b;
  signal_A8AD20LDU.error = var1431.error;
  signal_A8AD10LDU.b = var1430.b;
  signal_A8AD10LDU.error = var1430.error;
  signal_A8AZ03LDU.b = var951.b;
  signal_A8AZ03LDU.error = var951.error;
  signal_A8VS22LDU.b = var1478.b;
  signal_A8VS22LDU.error = var1478.error;
  signal_A8AB05LDU.b = var1473.b;
  signal_A8AB05LDU.error = var1473.error;
  signal_A8AB07LDU.b = var1474.b;
  signal_A8AB07LDU.error = var1474.error;
  signal_A8AB06LDU.b = var1481.b;
  signal_A8AB06LDU.error = var1481.error;
  fplet(&signal_A8CV01RDU.f,&var1479.f);
  signal_A8CV01RDU.error = var1479.error;
  signal_A8VS12LDU.b = var1477.b;
  signal_A8VS12LDU.error = var1477.error;
  signal_B8AB02LDU.b = var796.b;
  signal_B8AB02LDU.error = var796.error;
  signal_B8AB14LDU.b = var797.b;
  signal_B8AB14LDU.error = var797.error;
  signal_B8AB13LDU.b = var798.b;
  signal_B8AB13LDU.error = var798.error;
  signal_B8AB12LDU.b = var799.b;
  signal_B8AB12LDU.error = var799.error;
  signal_B8AB11LDU.b = var803.b;
  signal_B8AB11LDU.error = var803.error;
  signal_B8AB10LDU.b = var800.b;
  signal_B8AB10LDU.error = var800.error;
  signal_B8AB09LDU.b = var801.b;
  signal_B8AB09LDU.error = var801.error;
  signal_B8AB08LDU.b = var802.b;
  signal_B8AB08LDU.error = var802.error;
  signal_B8AB04LDU.b = var1492.b;
  signal_B8AB04LDU.error = var1492.error;
  signal_B8AB01LDU.b = var1493.b;
  signal_B8AB01LDU.error = var1493.error;
  signal_B8AD20LDU.b = var1441.b;
  signal_B8AD20LDU.error = var1441.error;
  signal_B8AD10LDU.b = var1440.b;
  signal_B8AD10LDU.error = var1440.error;
  signal_B8AZ03LDU.b = var952.b;
  signal_B8AZ03LDU.error = var952.error;
  signal_B8VS22LDU.b = var1495.b;
  signal_B8VS22LDU.error = var1495.error;
  signal_B8AB05LDU.b = var1484.b;
  signal_B8AB05LDU.error = var1484.error;
  signal_B8AB07LDU.b = var1485.b;
  signal_B8AB07LDU.error = var1485.error;
  signal_B8AB06LDU.b = var1498.b;
  signal_B8AB06LDU.error = var1498.error;
  fplet(&signal_B8CV01RDU.f,&var1496.f);
  signal_B8CV01RDU.error = var1496.error;
  signal_B8VS12LDU.b = var1494.b;
  signal_B8VS12LDU.error = var1494.error;
  signal_A6AB05LDU.b = var919.b;
  signal_A6AB05LDU.error = var919.error;
  signal_B6AB09LDU.b = var918.b;
  signal_B6AB09LDU.error = var918.error;
  signal_B6AB08LDU.b = var917.b;
  signal_B6AB08LDU.error = var917.error;
  signal_B6AB07LDU.b = var916.b;
  signal_B6AB07LDU.error = var916.error;
  signal_B6AB06LDU.b = var915.b;
  signal_B6AB06LDU.error = var915.error;
  signal_A6AB09LDU.b = var920.b;
  signal_A6AB09LDU.error = var920.error;
  signal_A6AB08LDU.b = var906.b;
  signal_A6AB08LDU.error = var906.error;
  signal_A6AB07LDU.b = var90.b;
  signal_A6AB07LDU.error = var90.error;
  signal_A6AB06LDU.b = var921.b;
  signal_A6AB06LDU.error = var921.error;
  signal_B5AB04LDU.b = var1548.b;
  signal_B5AB04LDU.error = var1548.error;
  signal_A5AB04LDU.b = var1557.b;
  signal_A5AB04LDU.error = var1557.error;
  signal_B4AB02LDU.b = var1529.b;
  signal_B4AB02LDU.error = var1529.error;
  signal_B4AB01LDU.b = var1530.b;
  signal_B4AB01LDU.error = var1530.error;
  signal_B4AZ03LDU.b = var1528.b;
  signal_B4AZ03LDU.error = var1528.error;
  signal_A4AB02LDU.b = var1538.b;
  signal_A4AB02LDU.error = var1538.error;
  signal_A4AB01LDU.b = var1539.b;
  signal_A4AB01LDU.error = var1539.error;
  signal_A4AZ03LDU.b = var1537.b;
  signal_A4AZ03LDU.error = var1537.error;
  signal_A4AD10LDU.b = var1540.b;
  signal_A4AD10LDU.error = var1540.error;
  signal_B4AD10LDU.b = var1531.b;
  signal_B4AD10LDU.error = var1531.error;
  signal_B5AB02LDU.b = var1547.b;
  signal_B5AB02LDU.error = var1547.error;
  signal_B5AB01LDU.b = var1549.b;
  signal_B5AB01LDU.error = var1549.error;
  signal_B5AZ03LDU.b = var1546.b;
  signal_B5AZ03LDU.error = var1546.error;
  signal_A5AB02LDU.b = var1556.b;
  signal_A5AB02LDU.error = var1556.error;
  signal_A5AB01LDU.b = var1558.b;
  signal_A5AB01LDU.error = var1558.error;
  signal_A5AZ03LDU.b = var1555.b;
  signal_A5AZ03LDU.error = var1555.error;
  signal_A5AD20LDU.b = var1560.b;
  signal_A5AD20LDU.error = var1560.error;
  signal_A5AD10LDU.b = var1559.b;
  signal_A5AD10LDU.error = var1559.error;
  signal_B5AD20LDU.b = var1551.b;
  signal_B5AD20LDU.error = var1551.error;
  signal_B5AD10LDU.b = var1550.b;
  signal_B5AD10LDU.error = var1550.error;
  signal_R4AD20LDU.b = var1569.b;
  signal_R4AD20LDU.error = var1569.error;
  signal_R4AD10LDU.b = var1568.b;
  signal_R4AD10LDU.error = var1568.error;
  signal_R4AB18LDU.b = var849.b;
  signal_R4AB18LDU.error = var849.error;
  signal_R4AB17LDU.b = var848.b;
  signal_R4AB17LDU.error = var848.error;
  signal_R4AB16LDU.b = var851.b;
  signal_R4AB16LDU.error = var851.error;
  signal_R4AB15LDU.b = var850.b;
  signal_R4AB15LDU.error = var850.error;
  signal_R4AB14LDU.b = var852.b;
  signal_R4AB14LDU.error = var852.error;
  signal_R4AB13LDU.b = var820.b;
  signal_R4AB13LDU.error = var820.error;
  signal_R4AB12LDU.b = var825.b;
  signal_R4AB12LDU.error = var825.error;
  signal_R4AB11LDU.b = var857.b;
  signal_R4AB11LDU.error = var857.error;
  signal_R4AB10LDU.b = var822.b;
  signal_R4AB10LDU.error = var822.error;
  signal_R4AB09LDU.b = var855.b;
  signal_R4AB09LDU.error = var855.error;
  signal_R4AB08LDU.b = var854.b;
  signal_R4AB08LDU.error = var854.error;
  signal_R4AB07LDU.b = var858.b;
  signal_R4AB07LDU.error = var858.error;
  signal_R4AB06LDU.b = var1566.b;
  signal_R4AB06LDU.error = var1566.error;
  signal_R4AB05LDU.b = var1565.b;
  signal_R4AB05LDU.error = var1565.error;
  signal_R4AB04LDU.b = var1567.b;
  signal_R4AB04LDU.error = var1567.error;
  signal_R4AB03LDU.b = var859.b;
  signal_R4AB03LDU.error = var859.error;
  signal_R4AZ03LDU.b = var1564.b;
  signal_R4AZ03LDU.error = var1564.error;
  signal_R4AB02LDU.b = var862.b;
  signal_R4AB02LDU.error = var862.error;
  signal_R4AB01LDU.b = var863.b;
  signal_R4AB01LDU.error = var863.error;
  signal_B6AB04LDU.b = var1575.b;
  signal_B6AB04LDU.error = var1575.error;
  signal_A6AB04LDU.b = var1584.b;
  signal_A6AB04LDU.error = var1584.error;
  signal_B6AB02LDU.b = var1574.b;
  signal_B6AB02LDU.error = var1574.error;
  signal_B6AB01LDU.b = var1576.b;
  signal_B6AB01LDU.error = var1576.error;
  signal_B6AZ03LDU.b = var1573.b;
  signal_B6AZ03LDU.error = var1573.error;
  signal_A6AB02LDU.b = var1583.b;
  signal_A6AB02LDU.error = var1583.error;
  signal_A6AB01LDU.b = var1585.b;
  signal_A6AB01LDU.error = var1585.error;
  signal_A6AZ03LDU.b = var1582.b;
  signal_A6AZ03LDU.error = var1582.error;
  signal_B6AD20LDU.b = var1578.b;
  signal_B6AD20LDU.error = var1578.error;
  signal_B6AD10LDU.b = var1577.b;
  signal_B6AD10LDU.error = var1577.error;
  signal_A6AD20LDU.b = var1587.b;
  signal_A6AD20LDU.error = var1587.error;
  signal_A6AD10LDU.b = var1586.b;
  signal_A6AD10LDU.error = var1586.error;
  signal_R0ES01LDU.b = var867.b;
  signal_R0ES01LDU.error = var867.error;

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
  CheckSInt(0);
#else
ParExchange("R0MW15IP1",2,&SignalBuffer[0],"Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(3);
#else
ParExchange("R0MW14IP1",2,&SignalBuffer[3],"Переключатель ПРОГРАММЫ",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(6);
#else
ParExchange("R0MW12IP1",2,&SignalBuffer[6],"Переключатель РЕЖИМ РАБОТЫ",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(6);
#else
ParExchange("R0MW12IP1",2,&SignalBuffer[6],"Переключатель РЕЖИМ РАБОТЫ",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(9);
#else
ParExchange("R0MW13IP1",2,&SignalBuffer[9],"Переключатель ВЫБОР ЗОН",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(12);
#else
ParExchange("R0MW16IP1",2,&SignalBuffer[12],"Переключатель ВИД ПРОВЕРКИ",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(15);
#else
ParExchange("R0MW11IP1",2,&SignalBuffer[15],"Переключатель ВЫСТРЕЛ",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(18);
#else
ParExchange("R0MW11IP2",2,&SignalBuffer[18],"Переключатель ПРОВЕРКА СХЕМ СБРОСА",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(21);
#else
ParExchange("R0MW13LP2",3,&SignalBuffer[21],"Переключатель СЕТЬ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(23);
#else
ParExchange("R0MD32LP1",3,&SignalBuffer[23],"Кнопка СПУСК",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(25);
#else
ParExchange("R0MD31LP1",3,&SignalBuffer[25],"Кнопка СТОП",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(27);
#else
ParExchange("A1IS21LDU",3,&SignalBuffer[27],"Приход на НУ ББ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(27);
#else
ParExchange("A1IS21LDU",3,&SignalBuffer[27],"Приход на НУ ББ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(27);
#else
ParExchange("A1IS21LDU",3,&SignalBuffer[27],"Приход на НУ ББ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(29);
#else
ParExchange("A2IS21LDU",3,&SignalBuffer[29],"Приход на НУ РБ1-СС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(29);
#else
ParExchange("A2IS21LDU",3,&SignalBuffer[29],"Приход на НУ РБ1-СС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(29);
#else
ParExchange("A2IS21LDU",3,&SignalBuffer[29],"Приход на НУ РБ1-СС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(29);
#else
ParExchange("A2IS21LDU",3,&SignalBuffer[29],"Приход на НУ РБ1-СС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(29);
#else
ParExchange("A2IS21LDU",3,&SignalBuffer[29],"Приход на НУ РБ1-СС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(29);
#else
ParExchange("A2IS21LDU",3,&SignalBuffer[29],"Приход на НУ РБ1-СС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(31);
#else
ParExchange("A3IS21LDU",3,&SignalBuffer[31],"Приход на НУ ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(31);
#else
ParExchange("A3IS21LDU",3,&SignalBuffer[31],"Приход на НУ ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(33);
#else
ParExchange("B1IS21LDU",3,&SignalBuffer[33],"Приход на НУ ББ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(33);
#else
ParExchange("B1IS21LDU",3,&SignalBuffer[33],"Приход на НУ ББ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(33);
#else
ParExchange("B1IS21LDU",3,&SignalBuffer[33],"Приход на НУ ББ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(35);
#else
ParExchange("B2IS21LDU",3,&SignalBuffer[35],"Приход на НУ РБ2-СС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(35);
#else
ParExchange("B2IS21LDU",3,&SignalBuffer[35],"Приход на НУ РБ2-СС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(35);
#else
ParExchange("B2IS21LDU",3,&SignalBuffer[35],"Приход на НУ РБ2-СС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(35);
#else
ParExchange("B2IS21LDU",3,&SignalBuffer[35],"Приход на НУ РБ2-СС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(35);
#else
ParExchange("B2IS21LDU",3,&SignalBuffer[35],"Приход на НУ РБ2-СС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(35);
#else
ParExchange("B2IS21LDU",3,&SignalBuffer[35],"Приход на НУ РБ2-СС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(37);
#else
ParExchange("B3IS21LDU",3,&SignalBuffer[37],"Приход на НУ ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(37);
#else
ParExchange("B3IS21LDU",3,&SignalBuffer[37],"Приход на НУ ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(41);
#else
ParExchange("R4MD11LP2",3,&SignalBuffer[41],"Кнопка ВПЕРЁД  (тележки)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(43);
#else
ParExchange("R4MD31LP2",3,&SignalBuffer[43],"Кнопка СТОП  (тележки)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(45);
#else
ParExchange("R4MD21LP2",3,&SignalBuffer[45],"Кнопка НАЗАД  (тележки)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(47);
#else
ParExchange("A6IS11LDU",3,&SignalBuffer[47],"Приход на ВУ БЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(47);
#else
ParExchange("A6IS11LDU",3,&SignalBuffer[47],"Приход на ВУ БЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(49);
#else
ParExchange("A6IS21LDU",3,&SignalBuffer[49],"Приход на НУ БЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(51);
#else
ParExchange("B6IS11LDU",3,&SignalBuffer[51],"Приход на ВУ БЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(51);
#else
ParExchange("B6IS11LDU",3,&SignalBuffer[51],"Приход на ВУ БЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(53);
#else
ParExchange("B6IS21LDU",3,&SignalBuffer[53],"Приход на НУ БЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(55);
#else
ParExchange("A6VS22LDU",3,&SignalBuffer[55],"Движение створок БЗ1  к ЗАКРЫТА",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(57);
#else
ParExchange("A6VS12LDU",3,&SignalBuffer[57],"Движение створок БЗ1  к  ОТКРЫТА",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(59);
#else
ParExchange("B6VS22LDU",3,&SignalBuffer[59],"Движение створок БЗ2  к «ЗАКРЫТА»",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(61);
#else
ParExchange("B6VS12LDU",3,&SignalBuffer[61],"Движение створок БЗ2  к  ОТКРЫТА",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(89);
#else
ParExchange("R8IS11LDU",3,&SignalBuffer[89],"Аварийный НИ установлен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(89);
#else
ParExchange("R8IS11LDU",3,&SignalBuffer[89],"Аварийный НИ установлен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(89);
#else
ParExchange("R8IS11LDU",3,&SignalBuffer[89],"Аварийный НИ установлен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(89);
#else
ParExchange("R8IS11LDU",3,&SignalBuffer[89],"Аварийный НИ установлен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(89);
#else
ParExchange("R8IS11LDU",3,&SignalBuffer[89],"Аварийный НИ установлен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(89);
#else
ParExchange("R8IS11LDU",3,&SignalBuffer[89],"Аварийный НИ установлен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(89);
#else
ParExchange("R8IS11LDU",3,&SignalBuffer[89],"Аварийный НИ установлен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(89);
#else
ParExchange("R8IS11LDU",3,&SignalBuffer[89],"Аварийный НИ установлен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(89);
#else
ParExchange("R8IS11LDU",3,&SignalBuffer[89],"Аварийный НИ установлен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(89);
#else
ParExchange("R8IS11LDU",3,&SignalBuffer[89],"Аварийный НИ установлен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(91);
#else
ParExchange("R6IS21LDU",3,&SignalBuffer[91],"Кран-балка в нерабочем положении",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(93);
#else
ParExchange("A0VN71LZ2",3,&SignalBuffer[93],"АЗ по АС мощности для АЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(95);
#else
ParExchange("A0VN71LZ1",3,&SignalBuffer[95],"АЗ по АС мощности для АЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(97);
#else
ParExchange("R0NE01LDU",3,&SignalBuffer[97],"Потеря связи с БАЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(99);
#else
ParExchange("R0NE02LDU",3,&SignalBuffer[99],"Потеря связи с БАЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(103);
#else
ParExchange("R0NE08LDU",3,&SignalBuffer[103],"Потеря связи с ОПУ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(105);
#else
ParExchange("R4IS21LDU",3,&SignalBuffer[105],"Приход на НУ1 тележки",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(107);
#else
ParExchange("R4IS22LDU",3,&SignalBuffer[107],"Приход на НУ2 тележки",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(109);
#else
ParExchange("R4IS12LDU",3,&SignalBuffer[109],"Приход ВУ2 тележки",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(111);
#else
ParExchange("R4VS22LDU",3,&SignalBuffer[111],"Движение реактора к У ЗАЩИТЫ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(113);
#else
ParExchange("R4VS12LDU",3,&SignalBuffer[113],"Движение реактора  к У ОБРАЗЦОВ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(119);
#else
ParExchange("R1IS21LDU",3,&SignalBuffer[119],"Приход на НУ МДЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(119);
#else
ParExchange("R1IS21LDU",3,&SignalBuffer[119],"Приход на НУ МДЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(119);
#else
ParExchange("R1IS21LDU",3,&SignalBuffer[119],"Приход на НУ МДЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(119);
#else
ParExchange("R1IS21LDU",3,&SignalBuffer[119],"Приход на НУ МДЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(121);
#else
ParExchange("R2IS21LDU",3,&SignalBuffer[121],"Приход на НУ МДЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(121);
#else
ParExchange("R2IS21LDU",3,&SignalBuffer[121],"Приход на НУ МДЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(121);
#else
ParExchange("R2IS21LDU",3,&SignalBuffer[121],"Приход на НУ МДЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(121);
#else
ParExchange("R2IS21LDU",3,&SignalBuffer[121],"Приход на НУ МДЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(135);
#else
ParExchange("B0VN71LZ1",3,&SignalBuffer[135],"АЗ по АС мощности для АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(137);
#else
ParExchange("B0VN71LZ2",3,&SignalBuffer[137],"АЗ по АС мощности для АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(145);
#else
ParExchange("A4IS11LDU",3,&SignalBuffer[145],"Приход на ВУ НИ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(145);
#else
ParExchange("A4IS11LDU",3,&SignalBuffer[145],"Приход на ВУ НИ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(145);
#else
ParExchange("A4IS11LDU",3,&SignalBuffer[145],"Приход на ВУ НИ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(145);
#else
ParExchange("A4IS11LDU",3,&SignalBuffer[145],"Приход на ВУ НИ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(145);
#else
ParExchange("A4IS11LDU",3,&SignalBuffer[145],"Приход на ВУ НИ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(145);
#else
ParExchange("A4IS11LDU",3,&SignalBuffer[145],"Приход на ВУ НИ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(145);
#else
ParExchange("A4IS11LDU",3,&SignalBuffer[145],"Приход на ВУ НИ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(145);
#else
ParExchange("A4IS11LDU",3,&SignalBuffer[145],"Приход на ВУ НИ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(145);
#else
ParExchange("A4IS11LDU",3,&SignalBuffer[145],"Приход на ВУ НИ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(145);
#else
ParExchange("A4IS11LDU",3,&SignalBuffer[145],"Приход на ВУ НИ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(147);
#else
ParExchange("B4IS11LDU",3,&SignalBuffer[147],"Приход на ВУ НИ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(147);
#else
ParExchange("B4IS11LDU",3,&SignalBuffer[147],"Приход на ВУ НИ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(147);
#else
ParExchange("B4IS11LDU",3,&SignalBuffer[147],"Приход на ВУ НИ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(147);
#else
ParExchange("B4IS11LDU",3,&SignalBuffer[147],"Приход на ВУ НИ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(147);
#else
ParExchange("B4IS11LDU",3,&SignalBuffer[147],"Приход на ВУ НИ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(147);
#else
ParExchange("B4IS11LDU",3,&SignalBuffer[147],"Приход на ВУ НИ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(147);
#else
ParExchange("B4IS11LDU",3,&SignalBuffer[147],"Приход на ВУ НИ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(147);
#else
ParExchange("B4IS11LDU",3,&SignalBuffer[147],"Приход на ВУ НИ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(147);
#else
ParExchange("B4IS11LDU",3,&SignalBuffer[147],"Приход на ВУ НИ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(147);
#else
ParExchange("B4IS11LDU",3,&SignalBuffer[147],"Приход на ВУ НИ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(155);
#else
ParExchange("R5IS11LDU",3,&SignalBuffer[155],"Приход на ВУ ворот отстойной зоны",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(155);
#else
ParExchange("R5IS11LDU",3,&SignalBuffer[155],"Приход на ВУ ворот отстойной зоны",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(155);
#else
ParExchange("R5IS11LDU",3,&SignalBuffer[155],"Приход на ВУ ворот отстойной зоны",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(155);
#else
ParExchange("R5IS11LDU",3,&SignalBuffer[155],"Приход на ВУ ворот отстойной зоны",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(167);
#else
ParExchange("A5VS22LDU",3,&SignalBuffer[167],"Движение НЛ1 в сторону НУ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(169);
#else
ParExchange("A5VS12LDU",3,&SignalBuffer[169],"Движение НЛ1 в сторону ВУ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(171);
#else
ParExchange("B5VS22LDU",3,&SignalBuffer[171],"Движение НЛ2 в сторону НУ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(173);
#else
ParExchange("B5VS12LDU",3,&SignalBuffer[173],"Движение НЛ2 в сторону ВУ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(183);
#else
ParExchange("A5IS11LDU",3,&SignalBuffer[183],"Приход на ВУ НЛ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(183);
#else
ParExchange("A5IS11LDU",3,&SignalBuffer[183],"Приход на ВУ НЛ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(185);
#else
ParExchange("A5IS21LDU",3,&SignalBuffer[185],"Приход на НУ НЛ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(185);
#else
ParExchange("A5IS21LDU",3,&SignalBuffer[185],"Приход на НУ НЛ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(187);
#else
ParExchange("B5IS11LDU",3,&SignalBuffer[187],"Приход на ВУ НЛ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(187);
#else
ParExchange("B5IS11LDU",3,&SignalBuffer[187],"Приход на ВУ НЛ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(189);
#else
ParExchange("B5IS21LDU",3,&SignalBuffer[189],"Приход на НУ НЛ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(203);
#else
ParExchange("A4IS21LDU",3,&SignalBuffer[203],"Приход на НУ НИ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(203);
#else
ParExchange("A4IS21LDU",3,&SignalBuffer[203],"Приход на НУ НИ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(203);
#else
ParExchange("A4IS21LDU",3,&SignalBuffer[203],"Приход на НУ НИ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(203);
#else
ParExchange("A4IS21LDU",3,&SignalBuffer[203],"Приход на НУ НИ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(205);
#else
ParExchange("B4IS21LDU",3,&SignalBuffer[205],"Приход на НУ НИ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(205);
#else
ParExchange("B4IS21LDU",3,&SignalBuffer[205],"Приход на НУ НИ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(205);
#else
ParExchange("B4IS21LDU",3,&SignalBuffer[205],"Приход на НУ НИ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(205);
#else
ParExchange("B4IS21LDU",3,&SignalBuffer[205],"Приход на НУ НИ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(227);
#else
ParExchange("A1IS12LDU",3,&SignalBuffer[227],"Магнит ББ1 зацеплен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(227);
#else
ParExchange("A1IS12LDU",3,&SignalBuffer[227],"Магнит ББ1 зацеплен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(229);
#else
ParExchange("A2IS12LDU",3,&SignalBuffer[229],"Магнит РБ1 зацеплен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(229);
#else
ParExchange("A2IS12LDU",3,&SignalBuffer[229],"Магнит РБ1 зацеплен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(229);
#else
ParExchange("A2IS12LDU",3,&SignalBuffer[229],"Магнит РБ1 зацеплен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(229);
#else
ParExchange("A2IS12LDU",3,&SignalBuffer[229],"Магнит РБ1 зацеплен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(229);
#else
ParExchange("A2IS12LDU",3,&SignalBuffer[229],"Магнит РБ1 зацеплен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(231);
#else
ParExchange("B1IS12LDU",3,&SignalBuffer[231],"Магнит ББ2 зацеплен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(231);
#else
ParExchange("B1IS12LDU",3,&SignalBuffer[231],"Магнит ББ2 зацеплен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(233);
#else
ParExchange("B2IS12LDU",3,&SignalBuffer[233],"Магнит РБ2 зацеплен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(233);
#else
ParExchange("B2IS12LDU",3,&SignalBuffer[233],"Магнит РБ2 зацеплен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(233);
#else
ParExchange("B2IS12LDU",3,&SignalBuffer[233],"Магнит РБ2 зацеплен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(233);
#else
ParExchange("B2IS12LDU",3,&SignalBuffer[233],"Магнит РБ2 зацеплен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(233);
#else
ParExchange("B2IS12LDU",3,&SignalBuffer[233],"Магнит РБ2 зацеплен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(235);
#else
ParExchange("R4IS11LDU",3,&SignalBuffer[235],"Приход на ВУ1 тележки",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(272);
#else
ParExchange("R0MD11LP1",3,&SignalBuffer[272],"Кнопка ПУСК",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(278);
#else
ParExchange("B8IS11LDU",3,&SignalBuffer[278],"Приход на ВУ1 АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(278);
#else
ParExchange("B8IS11LDU",3,&SignalBuffer[278],"Приход на ВУ1 АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(321);
#else
ParExchange("B8IS22LDU",3,&SignalBuffer[321],"Приход на НУ2 АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(321);
#else
ParExchange("B8IS22LDU",3,&SignalBuffer[321],"Приход на НУ2 АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(321);
#else
ParExchange("B8IS22LDU",3,&SignalBuffer[321],"Приход на НУ2 АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(321);
#else
ParExchange("B8IS22LDU",3,&SignalBuffer[321],"Приход на НУ2 АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(323);
#else
ParExchange("A8IS12LDU",3,&SignalBuffer[323],"Приход на механический ВУ ДС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(323);
#else
ParExchange("A8IS12LDU",3,&SignalBuffer[323],"Приход на механический ВУ ДС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(327);
#else
ParExchange("A8IS22LDU",3,&SignalBuffer[327],"Приход на механический НУ ДС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(327);
#else
ParExchange("A8IS22LDU",3,&SignalBuffer[327],"Приход на механический НУ ДС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(327);
#else
ParExchange("A8IS22LDU",3,&SignalBuffer[327],"Приход на механический НУ ДС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(327);
#else
ParExchange("A8IS22LDU",3,&SignalBuffer[327],"Приход на механический НУ ДС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(483);
#else
ParExchange("R1IS11LDU",3,&SignalBuffer[483],"Приход на ВУ МДЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(483);
#else
ParExchange("R1IS11LDU",3,&SignalBuffer[483],"Приход на ВУ МДЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(485);
#else
ParExchange("R1VS22LDU",3,&SignalBuffer[485],"Движение МДЗ1 в сторону НУ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(487);
#else
ParExchange("R2VS22LDU",3,&SignalBuffer[487],"Движение МДЗ2 в сторону НУ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(489);
#else
ParExchange("R2VS12LDU",3,&SignalBuffer[489],"Движение МДЗ2 в сторону ВУ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(491);
#else
ParExchange("R1VS12LDU",3,&SignalBuffer[491],"Движение МДЗ1 в сторону ВУ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(493);
#else
ParExchange("R2IS11LDU",3,&SignalBuffer[493],"Приход на ВУ МДЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(493);
#else
ParExchange("R2IS11LDU",3,&SignalBuffer[493],"Приход на ВУ МДЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(743);
#else
ParExchange("C1MD31LP1",3,&SignalBuffer[743],"Кнопка «СБРОС ББ»",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(745);
#else
ParExchange("C1MD31LP2",3,&SignalBuffer[745],"Кнопка «СБРОС ББ»",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(763);
#else
ParExchange("R0MD11LP2",3,&SignalBuffer[763],"Кнопка Пуск проверки схем сброса",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(780);
#else
ParExchange("B3IS11LDU",3,&SignalBuffer[780],"Приход на ВУ ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(780);
#else
ParExchange("B3IS11LDU",3,&SignalBuffer[780],"Приход на ВУ ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(780);
#else
ParExchange("B3IS11LDU",3,&SignalBuffer[780],"Приход на ВУ ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(867);
#else
ParExchange("A9IS11LDU",3,&SignalBuffer[867],"Приход на ВУ НИ ДС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(869);
#else
ParExchange("A9IS21LDU",3,&SignalBuffer[869],"Приход на НУ НИ ДС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(871);
#else
ParExchange("B9IS11LDU",3,&SignalBuffer[871],"Приход на ВУ НИ ДС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(873);
#else
ParExchange("B9IS21LDU",3,&SignalBuffer[873],"Приход на НУ НИ ДС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(893);
#else
ParExchange("A3IS22LDU",3,&SignalBuffer[893],"Приход на НУП ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(893);
#else
ParExchange("A3IS22LDU",3,&SignalBuffer[893],"Приход на НУП ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(893);
#else
ParExchange("A3IS22LDU",3,&SignalBuffer[893],"Приход на НУП ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(895);
#else
ParExchange("B3IS22LDU",3,&SignalBuffer[895],"Приход на НУП ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(895);
#else
ParExchange("B3IS22LDU",3,&SignalBuffer[895],"Приход на НУП ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(895);
#else
ParExchange("B3IS22LDU",3,&SignalBuffer[895],"Приход на НУП ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(911);
#else
ParExchange("A2IS11LDU",3,&SignalBuffer[911],"Приход на ВУ РБ1-СТР",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(911);
#else
ParExchange("A2IS11LDU",3,&SignalBuffer[911],"Приход на ВУ РБ1-СТР",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(911);
#else
ParExchange("A2IS11LDU",3,&SignalBuffer[911],"Приход на ВУ РБ1-СТР",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(911);
#else
ParExchange("A2IS11LDU",3,&SignalBuffer[911],"Приход на ВУ РБ1-СТР",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(913);
#else
ParExchange("B2IS11LDU",3,&SignalBuffer[913],"Приход на ВУ РБ2-СТР",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(913);
#else
ParExchange("B2IS11LDU",3,&SignalBuffer[913],"Приход на ВУ РБ2-СТР",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(913);
#else
ParExchange("B2IS11LDU",3,&SignalBuffer[913],"Приход на ВУ РБ2-СТР",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(913);
#else
ParExchange("B2IS11LDU",3,&SignalBuffer[913],"Приход на ВУ РБ2-СТР",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(915);
#else
ParExchange("A3MD12LP1",3,&SignalBuffer[915],"Переключатель РАЗРЕШИТЬ ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(917);
#else
ParExchange("A3MD11LP1",3,&SignalBuffer[917],"Кнопка ПУСК ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(919);
#else
ParExchange("R0MD33LP1",3,&SignalBuffer[919],"Переключатель РАЗРЕШИТЬ МДЗ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(919);
#else
ParExchange("R0MD33LP1",3,&SignalBuffer[919],"Переключатель РАЗРЕШИТЬ МДЗ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(919);
#else
ParExchange("R0MD33LP1",3,&SignalBuffer[919],"Переключатель РАЗРЕШИТЬ МДЗ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(921);
#else
ParExchange("A1MD12LP1",3,&SignalBuffer[921],"Переключатель РАЗРЕШИТЬ ББ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(923);
#else
ParExchange("A1MD11LP1",3,&SignalBuffer[923],"Кнопка ПУСК ББ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(925);
#else
ParExchange("R0MW14IP2",2,&SignalBuffer[925],"Переключатель «Обдув»",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(932);
#else
ParExchange("R0MW12IP2",2,&SignalBuffer[932],"Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(935);
#else
ParExchange("R0MW17LP1",3,&SignalBuffer[935],"Переключатель АВТ/Р",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(954);
#else
ParExchange("A3IS11LDU",3,&SignalBuffer[954],"Приход на ВУ ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(954);
#else
ParExchange("A3IS11LDU",3,&SignalBuffer[954],"Приход на ВУ ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(954);
#else
ParExchange("A3IS11LDU",3,&SignalBuffer[954],"Приход на ВУ ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(960);
#else
ParExchange("B1MD11LP1",3,&SignalBuffer[960],"Кнопка ПУСК ББ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(962);
#else
ParExchange("B1MD12LP1",3,&SignalBuffer[962],"Переключатель РАЗРЕШИТЬ ББ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(964);
#else
ParExchange("B2MD11LP1",3,&SignalBuffer[964],"Кнопка ПУСК РБ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(966);
#else
ParExchange("B2MD12LP1",3,&SignalBuffer[966],"Переключатель РАЗРЕШИТЬ РБ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(968);
#else
ParExchange("A2MD11LP1",3,&SignalBuffer[968],"Кнопка ПУСК РБ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(970);
#else
ParExchange("A2MD12LP1",3,&SignalBuffer[970],"Переключатель РАЗРЕШИТЬ РБ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(972);
#else
ParExchange("R0IS01LDU",3,&SignalBuffer[972],"Признак работы с имитатором",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(974);
#else
ParExchange("R0IS02LDU",3,&SignalBuffer[974],"Разрешение ввода от имитатора",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(976);
#else
ParExchange("R0VP73LZ1",3,&SignalBuffer[976],"ПС давления для РУ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(978);
#else
ParExchange("R0VP73LZ2",3,&SignalBuffer[978],"ПС давления для РУ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(982);
#else
ParExchange("R0MD34LP1",3,&SignalBuffer[982],"Кнопка КВИТИРОВАТЬ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(984);
#else
ParExchange("A0VT71LZ1",3,&SignalBuffer[984],"АС по температуре в АЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(984);
#else
ParExchange("A0VT71LZ1",3,&SignalBuffer[984],"АС по температуре в АЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(986);
#else
ParExchange("B0VT71LZ1",3,&SignalBuffer[986],"АС по температуре в АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(986);
#else
ParExchange("B0VT71LZ1",3,&SignalBuffer[986],"АС по температуре в АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(988);
#else
ParExchange("A0VT71LZ2",3,&SignalBuffer[988],"АС по температуре в АЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(988);
#else
ParExchange("A0VT71LZ2",3,&SignalBuffer[988],"АС по температуре в АЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(990);
#else
ParExchange("B0VT71LZ2",3,&SignalBuffer[990],"АС по температуре в АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(990);
#else
ParExchange("B0VT71LZ2",3,&SignalBuffer[990],"АС по температуре в АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(999);
#else
ParExchange("A7AS31LDU",3,&SignalBuffer[999],"Клапан Обдув АЗ1 открыт (обесточен)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1001);
#else
ParExchange("B7AS31LDU",3,&SignalBuffer[1001],"Клапан Обдув АЗ2 открыт (обесточен)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1007);
#else
ParExchange("B3MD12LP1",3,&SignalBuffer[1007],"Переключатель «РАЗРЕШИТЬ» ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1009);
#else
ParExchange("B3MD11LP1",3,&SignalBuffer[1009],"Кнопка «ПУСК ИС2»",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1016);
#else
ParExchange("R0VZ71LZ2",3,&SignalBuffer[1016],"Обобщенный сигнал АЗ 2 канала",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1018);
#else
ParExchange("R0VZ71LZ1",3,&SignalBuffer[1018],"Обобщенный сигнал АЗ 1канала",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1022);
#else
ParExchange("A2IS33LDU",3,&SignalBuffer[1022],"Клапан ПОДЪЕМ РБ1 открыт (обесточен)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1024);
#else
ParExchange("A3IS31LDU",3,&SignalBuffer[1024],"Клапан СПУСК ИС1 открыт (обесточен)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1026);
#else
ParExchange("A3IS33LDU",3,&SignalBuffer[1026],"Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1028);
#else
ParExchange("A3IS35LDU",3,&SignalBuffer[1028],"Клапан ВПИС1 открыт (обесточен)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1030);
#else
ParExchange("A4IS10LDU",3,&SignalBuffer[1030],"Клапан Подъём НИ1 открыт (обесточен)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1032);
#else
ParExchange("A1VN71LZ1",3,&SignalBuffer[1032],"Блокировка автоматического подъёма ББ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1034);
#else
ParExchange("A1VN71LZ2",3,&SignalBuffer[1034],"Блокировка автоматического подъёма ББ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1038);
#else
ParExchange("R0AD14LZ1",3,&SignalBuffer[1038],"Имитация срабатывания АЗ от II УР",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1040);
#else
ParExchange("R0AD14LZ2",3,&SignalBuffer[1040],"Имитация срабатывания АЗ от  II УР",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1042);
#else
ParExchange("A3VZ13LZ2",3,&SignalBuffer[1042],"Имитация срабатывания АЗ от ВУ ИС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1044);
#else
ParExchange("A3VZ13LZ1",3,&SignalBuffer[1044],"Имитация срабатывания АЗ от ВУ ИС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1046);
#else
ParExchange("A3VZ15LZ1",3,&SignalBuffer[1046],"Имитация срабатывания АЗ от НУП ИС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1048);
#else
ParExchange("A3VZ15LZ2",3,&SignalBuffer[1048],"Имитация срабатывания АЗ от НУП ИС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1050);
#else
ParExchange("B2IS33LDU",3,&SignalBuffer[1050],"Клапан ПОДЪЕМ РБ2 открыт (обесточен)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1052);
#else
ParExchange("B3IS31LDU",3,&SignalBuffer[1052],"Клапан СПУСК ИС2 открыт (обесточен)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1054);
#else
ParExchange("B3IS33LDU",3,&SignalBuffer[1054],"Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1056);
#else
ParExchange("B3IS35LDU",3,&SignalBuffer[1056],"Клапан ВПИС2 открыт (обесточен)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1058);
#else
ParExchange("B4IS10LDU",3,&SignalBuffer[1058],"Клапан ПОДЪЕМ НИ2 открыт (обесточен)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1060);
#else
ParExchange("R6IS31LDU",3,&SignalBuffer[1060],"контроль задней двери ШС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1062);
#else
ParExchange("R6IS32LDU",3,&SignalBuffer[1062],"контроль передней двери ШС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1064);
#else
ParExchange("R6IS42LDU",3,&SignalBuffer[1064],"контроль передней двери ШЭП",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1066);
#else
ParExchange("R6IS41LDU",3,&SignalBuffer[1066],"контроль задней двери ШЭП",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1068);
#else
ParExchange("R6IS52LDU",3,&SignalBuffer[1068],"контроль передней двери ШПУ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1070);
#else
ParExchange("R6IS51LDU",3,&SignalBuffer[1070],"контроль задней двери ШПУ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1072);
#else
ParExchange("R3IS11LDU",3,&SignalBuffer[1072],"Приход на ВУ гомогенных дверей",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1074);
#else
ParExchange("R3IS21LDU",3,&SignalBuffer[1074],"Приход на НУ гомогенных дверей",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(1080);
#else
ParExchange("R0VN11RZ1",1,&SignalBuffer[1080],"Средняя мощность по BAZ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(1080);
#else
ParExchange("R0VN11RZ1",1,&SignalBuffer[1080],"Средняя мощность по BAZ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(1085);
#else
ParExchange("R0VN11RZ2",1,&SignalBuffer[1085],"Средняя мощность по BAZ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(1085);
#else
ParExchange("R0VN11RZ2",1,&SignalBuffer[1085],"Средняя мощность по BAZ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1098);
#else
ParExchange("syn_R0EE03LDU",3,&SignalBuffer[1098],"ВПИС ИС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1104);
#else
ParExchange("C2MD31LP1",3,&SignalBuffer[1104],"Кнопка СБРОС РБ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1119);
#else
ParExchange("A1IE03LDU",3,&SignalBuffer[1119],"Движение ББ1 вперед (от БУШД)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1121);
#else
ParExchange("A1IE04LDU",3,&SignalBuffer[1121],"Движение ББ1 назад (от БУШД)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1123);
#else
ParExchange("A2IE03LDU",3,&SignalBuffer[1123],"Движение РБ1 вперед (от БУШД)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1125);
#else
ParExchange("A2IE04LDU",3,&SignalBuffer[1125],"Движение РБ1 назад (от БУШД)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1127);
#else
ParExchange("A3IE03LDU",3,&SignalBuffer[1127],"Движение ИС1 вперед (от БУШД)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1129);
#else
ParExchange("A3IE04LDU",3,&SignalBuffer[1129],"Движение ИС1 назад (от БУШД)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1131);
#else
ParExchange("B1IE03LDU",3,&SignalBuffer[1131],"Движение ББ2 вперед (от БУШД)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1133);
#else
ParExchange("B1IE04LDU",3,&SignalBuffer[1133],"Движение ББ2 назад (от БУШД)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1135);
#else
ParExchange("B2IE03LDU",3,&SignalBuffer[1135],"Движение РБ2 вперед (от БУШД)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1137);
#else
ParExchange("B2IE04LDU",3,&SignalBuffer[1137],"Движение РБ2 назад (от БУШД)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1139);
#else
ParExchange("B3IE03LDU",3,&SignalBuffer[1139],"Движение ИС2 вперед (от БУШД)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1141);
#else
ParExchange("B3IE04LDU",3,&SignalBuffer[1141],"Движение ИС2 назад (от БУШД)",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(1149);
#else
ParExchange("A1MC01RP1",1,&SignalBuffer[1149],"Заданная координата положения ББ1 мм",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(1154);
#else
ParExchange("B1MC01RP1",1,&SignalBuffer[1154],"Заданная координата положения ББ2  мм",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(1159);
#else
ParExchange("A3MC01RP1",1,&SignalBuffer[1159],"Заданная координата положения ИС1 мм",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(1159);
#else
ParExchange("A3MC01RP1",1,&SignalBuffer[1159],"Заданная координата положения ИС1 мм",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(1164);
#else
ParExchange("B3MC01RP1",1,&SignalBuffer[1164],"Заданная координата положения ИС2 мм",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(1164);
#else
ParExchange("B3MC01RP1",1,&SignalBuffer[1164],"Заданная координата положения ИС2 мм",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(1169);
#else
ParExchange("B8MC01RP2",1,&SignalBuffer[1169],"Заданная координата АЗ2 мм",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(1220);
#else
ParExchange("R0VN09RZ2",1,&SignalBuffer[1220],"Усредненный период разгона",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(1225);
#else
ParExchange("R0VN09RZ1",1,&SignalBuffer[1225],"Усредненный период разгона",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(1236);
#else
ParExchange("A0CT01IZ1",1,&SignalBuffer[1236],"Температура АЗ1-1",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(1241);
#else
ParExchange("B0CT01IZ1",1,&SignalBuffer[1241],"Температура АЗ2-1",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(1246);
#else
ParExchange("A0CT01IZ2",1,&SignalBuffer[1246],"Температура АЗ1-2",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(1251);
#else
ParExchange("B0CT01IZ2",1,&SignalBuffer[1251],"Температура АЗ2-2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1322);
#else
ParExchange("B8IS12LDU",3,&SignalBuffer[1322],"Приход на ВУ2 АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1322);
#else
ParExchange("B8IS12LDU",3,&SignalBuffer[1322],"Приход на ВУ2 АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1324);
#else
ParExchange("B8IS21LDU",3,&SignalBuffer[1324],"Приход на НУ1 АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1324);
#else
ParExchange("B8IS21LDU",3,&SignalBuffer[1324],"Приход на НУ1 АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1326);
#else
ParExchange("A1VP41LZ1",3,&SignalBuffer[1326],"Давление СБРОС ББ1 ниже АС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1328);
#else
ParExchange("A1VP41LZ2",3,&SignalBuffer[1328],"Давление СБРОС ББ1 ниже АС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1334);
#else
ParExchange("B1VP41LZ1",3,&SignalBuffer[1334],"Давление СБРОС ББ2 ниже АС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1336);
#else
ParExchange("B1VP41LZ2",3,&SignalBuffer[1336],"Давление СБРОС ББ2 ниже АС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1348);
#else
ParExchange("R5IS21LDU",3,&SignalBuffer[1348],"Приход на НУ ворот отстойной зоны",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1366);
#else
ParExchange("syn_A3VP52LDU",3,&SignalBuffer[1366],"Давление ВЫСТРЕЛ ИС1 ниже ПС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1366);
#else
ParExchange("syn_A3VP52LDU",3,&SignalBuffer[1366],"Давление ВЫСТРЕЛ ИС1 ниже ПС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1370);
#else
ParExchange("syn_B3VP52LDU",3,&SignalBuffer[1370],"Давление ВЫСТРЕЛ ИС2 ниже ПС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1370);
#else
ParExchange("syn_B3VP52LDU",3,&SignalBuffer[1370],"Давление ВЫСТРЕЛ ИС2 ниже ПС",0);
#endif
#ifndef SIMUL_MODE
  CheckSLong(1372);
#else
ParExchange("B1IC01UDU",7,&SignalBuffer[1372],"Координата штока ББ2 (дел.энк)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1382);
#else
ParExchange("B1IS11LDU",3,&SignalBuffer[1382],"Приход на ВУ ББ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSLong(1384);
#else
ParExchange("A2IC01UDU",7,&SignalBuffer[1384],"Координата штока РБ1 (дел.энк)",0);
#endif
#ifndef SIMUL_MODE
  CheckSLong(1389);
#else
ParExchange("B2IC01UDU",7,&SignalBuffer[1389],"Координата штока РБ2 (дел.энк)",0);
#endif
#ifndef SIMUL_MODE
  CheckSLong(1394);
#else
ParExchange("A3IC01UDU",7,&SignalBuffer[1394],"Координата штока ИС1 (дел.энк)",0);
#endif
#ifndef SIMUL_MODE
  CheckSLong(1399);
#else
ParExchange("B3IC01UDU",7,&SignalBuffer[1399],"Координата штока ИС2 (дел.энк)",0);
#endif
#ifndef SIMUL_MODE
  CheckSLong(1409);
#else
ParExchange("A8IC01UDU",7,&SignalBuffer[1409],"Координата ДС2 (дел.энк)",0);
#endif
#ifndef SIMUL_MODE
  CheckSLong(1419);
#else
ParExchange("B8IC01UDU",7,&SignalBuffer[1419],"Координата АЗ2 (дел.энк)",0);
#endif
#ifndef SIMUL_MODE
  CheckSLong(1424);
#else
ParExchange("A1IC01UDU",7,&SignalBuffer[1424],"Координата штока ББ1 (дел.энк)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1434);
#else
ParExchange("A1IS11LDU",3,&SignalBuffer[1434],"Приход на ВУ ББ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1436);
#else
ParExchange("B1MC01LC1",3,&SignalBuffer[1436],"Настроить энкодер ББ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1438);
#else
ParExchange("B1MC01LC2",3,&SignalBuffer[1438],"Настроить энкодер ББ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1440);
#else
ParExchange("A1MC01LC1",3,&SignalBuffer[1440],"Настроить энкодер ББ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1442);
#else
ParExchange("A1MC01LC2",3,&SignalBuffer[1442],"Настроить энкодер ББ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1444);
#else
ParExchange("B2MC01LC1",3,&SignalBuffer[1444],"Настроить энкодер РБ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1446);
#else
ParExchange("B2MC01LC2",3,&SignalBuffer[1446],"Настроить энкодер РБ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1448);
#else
ParExchange("A2MC01LC1",3,&SignalBuffer[1448],"Настроить энкодер РБ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1450);
#else
ParExchange("A2MC01LC2",3,&SignalBuffer[1450],"Настроить энкодер РБ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1452);
#else
ParExchange("B3MC01LC1",3,&SignalBuffer[1452],"Настроить энкодер ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1454);
#else
ParExchange("B3MC01LC2",3,&SignalBuffer[1454],"Настроить энкодер ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1456);
#else
ParExchange("A3MC01LC1",3,&SignalBuffer[1456],"Настроить энкодер ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1458);
#else
ParExchange("A3MC01LC2",3,&SignalBuffer[1458],"Настроить энкодер ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1460);
#else
ParExchange("B8MC01LC1",3,&SignalBuffer[1460],"Настроить энкодер АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1462);
#else
ParExchange("B8MC01LC2",3,&SignalBuffer[1462],"Настроить энкодер АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1464);
#else
ParExchange("A8MC01LC1",3,&SignalBuffer[1464],"Настроить энкодер ДС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1466);
#else
ParExchange("A8MC01LC2",3,&SignalBuffer[1466],"Настроить энкодер ДС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(1486);
#else
ParExchange("A3IP02IDU",2,&SignalBuffer[1486],"Текущее давление ВЫСТРЕЛ ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(1489);
#else
ParExchange("B3IP02IDU",2,&SignalBuffer[1489],"Текущее давление ВЫСТРЕЛ ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1500);
#else
ParExchange("A0EE01LZ1",3,&SignalBuffer[1500],"Исправность АКНП1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1502);
#else
ParExchange("A0EE03LZ1",3,&SignalBuffer[1502],"Исправность АКНП3",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1504);
#else
ParExchange("A0EE02LZ1",3,&SignalBuffer[1504],"Исправность АКНП2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1506);
#else
ParExchange("A0EE04LZ1",3,&SignalBuffer[1506],"Исправность АКНП4",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1512);
#else
ParExchange("A0EE01LZ2",3,&SignalBuffer[1512],"Исправность АКНП1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1514);
#else
ParExchange("A0EE03LZ2",3,&SignalBuffer[1514],"Исправность АКНП3",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1516);
#else
ParExchange("A0EE02LZ2",3,&SignalBuffer[1516],"Исправность АКНП2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1518);
#else
ParExchange("A0EE04LZ2",3,&SignalBuffer[1518],"Исправность АКНП4",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1520);
#else
ParExchange("A0VP71LZ1",3,&SignalBuffer[1520],"АЗ по АС любого давления для АЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1522);
#else
ParExchange("A0VP71LZ2",3,&SignalBuffer[1522],"АЗ по АС любого давления для АЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1524);
#else
ParExchange("B0VP71LZ1",3,&SignalBuffer[1524],"АЗ по АС любого давления для АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1526);
#else
ParExchange("B0VP71LZ2",3,&SignalBuffer[1526],"АЗ по АС любого давления для АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1532);
#else
ParExchange("A1IE01LDU",3,&SignalBuffer[1532],"Исправность БУШД ББ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1534);
#else
ParExchange("A3IE01LDU",3,&SignalBuffer[1534],"Исправность БУШД ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1536);
#else
ParExchange("A2IE01LDU",3,&SignalBuffer[1536],"Исправность БУШД РБ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1538);
#else
ParExchange("A1IE02LDU",3,&SignalBuffer[1538],"Исправность ИП ББ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1540);
#else
ParExchange("A3IE02LDU",3,&SignalBuffer[1540],"Исправность ИП ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1542);
#else
ParExchange("A2IE02LDU",3,&SignalBuffer[1542],"Исправность ИП РБ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1544);
#else
ParExchange("B1IE01LDU",3,&SignalBuffer[1544],"Исправность БУШД ББ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1546);
#else
ParExchange("B2IE01LDU",3,&SignalBuffer[1546],"Исправность БУШД РБ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1548);
#else
ParExchange("B3IE01LDU",3,&SignalBuffer[1548],"Исправность БУШД ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1550);
#else
ParExchange("B1IE02LDU",3,&SignalBuffer[1550],"Исправность ИП ББ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1552);
#else
ParExchange("B3IE02LDU",3,&SignalBuffer[1552],"Исправность ИП ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1554);
#else
ParExchange("B2IE02LDU",3,&SignalBuffer[1554],"Исправность ИП РБ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1556);
#else
ParExchange("R0IE02LDU",3,&SignalBuffer[1556],"Исправность ИП 24 В-1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1558);
#else
ParExchange("R0IE01LDU",3,&SignalBuffer[1558],"Исправность ИП 24 В-2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1560);
#else
ParExchange("A6IE01LDU",3,&SignalBuffer[1560],"Исправность ИП БЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1562);
#else
ParExchange("B6IE01LDU",3,&SignalBuffer[1562],"Исправность ИП БЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1564);
#else
ParExchange("A8IE01LDU",3,&SignalBuffer[1564],"Исправность ИП ДС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1566);
#else
ParExchange("B5IE01LDU",3,&SignalBuffer[1566],"Исправность ИП НЛ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1568);
#else
ParExchange("A5IE02LDU",3,&SignalBuffer[1568],"Исправность ИП НЛ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1570);
#else
ParExchange("R1IE01LDU",3,&SignalBuffer[1570],"Исправность ИП МДЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1572);
#else
ParExchange("R2IE01LDU",3,&SignalBuffer[1572],"Исправность ИП МДЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1574);
#else
ParExchange("R6IS61LDU",3,&SignalBuffer[1574],"Исправность 3-х  фазной сети",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1576);
#else
ParExchange("R6IS64LDU",3,&SignalBuffer[1576],"Исправность ВИП ССДИ-35 1канал",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1578);
#else
ParExchange("R6IS65LDU",3,&SignalBuffer[1578],"Исправность ВИП ССДИ-35 2канал",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1580);
#else
ParExchange("R6IS62LDU",3,&SignalBuffer[1580],"Исправность ВИП ССДИ-39 1канал",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1582);
#else
ParExchange("R6IS63LDU",3,&SignalBuffer[1582],"Исправность ВИП ССДИ-39 2канал",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1584);
#else
ParExchange("R6IS66LZZ",3,&SignalBuffer[1584],"Исправность ВИП 4,0 (№5) ССДИ-1-1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1586);
#else
ParExchange("R6IS67LZZ",3,&SignalBuffer[1586],"Исправность ВИП 4,0 (№6) ССДИ-1-2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1588);
#else
ParExchange("R6IS68LZZ",3,&SignalBuffer[1588],"Исправность ВИП 4,0 (№7) ССДИ-2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1610);
#else
ParExchange("A4VP82LDU",3,&SignalBuffer[1610],"Давление ПОДЪЁМ НИ1 в норме",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1612);
#else
ParExchange("B4VP82LDU",3,&SignalBuffer[1612],"Давление ПОДЪЁМ НИ2 в норме",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1614);
#else
ParExchange("A2VP82LDU",3,&SignalBuffer[1614],"Давление ПОДЪЁМ РБ1 в норме",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1616);
#else
ParExchange("B2VP82LDU",3,&SignalBuffer[1616],"Давление ПОДЪЁМ РБ2 в норме",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1618);
#else
ParExchange("A3VP81LDU",3,&SignalBuffer[1618],"Давление СПУСК ИС1 в норме",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(1620);
#else
ParExchange("B3VP81LDU",3,&SignalBuffer[1620],"Давление СПУСК ИС2 в норме",0);
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
 for(counter=0; counter<1624; counter++) {
   *((unsigned char*)(SignalBuffer)+PBLENGTH-counter-1) =
          (unsigned char)~(*((unsigned char*)(SignalBuffer)+counter));
 }
#endif
}
#endif
#ifdef SIMUL_MODE
void UnloadSignals()
{
ParExchange("R0ES01LDU",3,&SignalBuffer[39],"ОРР не в исходном состоянии",1);
ParExchange("A6AD10LDU",3,&SignalBuffer[63],"Открыть БЗ1",1);
ParExchange("A6AD20LDU",3,&SignalBuffer[65],"Закрыть БЗ1",1);
ParExchange("B6AD10LDU",3,&SignalBuffer[67],"Открыть БЗ2",1);
ParExchange("B6AD20LDU",3,&SignalBuffer[69],"Закрыть БЗ2",1);
ParExchange("A6AZ03LDU",3,&SignalBuffer[71],"Несанкционированное перемещение БЗ1",1);
ParExchange("A6AB01LDU",3,&SignalBuffer[73],"Блокировка движения БЗ1 - Превышение времени движения",1);
ParExchange("A6AB02LDU",3,&SignalBuffer[75],"Блокировка движения БЗ1 - Нет перемещения",1);
ParExchange("B6AZ03LDU",3,&SignalBuffer[77],"Несанкционированное перемещение БЗ2",1);
ParExchange("B6AB01LDU",3,&SignalBuffer[79],"Блокировка движения движения БЗ2 - Превышение времени движения",1);
ParExchange("B6AB02LDU",3,&SignalBuffer[81],"Блокировка движения БЗ2 - Нет перемещения",1);
ParExchange("A6AB04LDU",3,&SignalBuffer[83],"Блокировка движения БЗ1 -Ошибка в направлении  движения",1);
ParExchange("B6AB04LDU",3,&SignalBuffer[85],"Блокировка движения БЗ2 -Ошибка в направлении  движения",1);
ParExchange("R4AB01LDU",3,&SignalBuffer[87],"Блокировка движения тележки - АНИ не установлен",1);
ParExchange("R4AB02LDU",3,&SignalBuffer[101],"Блокировка движения тележки - Потеря связи с БАЗ, ОПУ",1);
ParExchange("R4AZ03LDU",3,&SignalBuffer[115],"Несанкционированное перемещение тележки",1);
ParExchange("R4AB03LDU",3,&SignalBuffer[117],"Блокировка движения тележки - Самоход любого механизма",1);
ParExchange("R4AB04LDU",3,&SignalBuffer[123],"Блокировка движения тележки - Превышение времени движения",1);
ParExchange("R4AB05LDU",3,&SignalBuffer[125],"Блокировка движения  тележки - Нет перемещения тележки",1);
ParExchange("R4AB06LDU",3,&SignalBuffer[127],"Блокировка движения тележки - Ошибка в  направлении перемещения",1);
ParExchange("R4AB07LDU",3,&SignalBuffer[129],"Блокировка движения тележки - ОРР не в исходном состоянии",1);
ParExchange("R4AB08LDU",3,&SignalBuffer[131],"Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)",1);
ParExchange("R4AB09LDU",3,&SignalBuffer[133],"Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ",1);
ParExchange("R4AB10LDU",3,&SignalBuffer[139],"Блокировка тележки - не открыта биологическая защита",1);
ParExchange("R4AB11LDU",3,&SignalBuffer[141],"Блокировка движения тележки - МДЗ1,2 не находятся на НУ",1);
ParExchange("R4AB12LDU",3,&SignalBuffer[143],"Блокировка движения тележки - НИ не в положении ВУ",1);
ParExchange("R4AB13LDU",3,&SignalBuffer[149],"Блокировка тележки - НЛ не в положении ВУ",1);
ParExchange("R4AB14LDU",3,&SignalBuffer[151],"Блокировка движения тележки - Кран - балка не в безопасном положении",1);
ParExchange("R4AB15LDU",3,&SignalBuffer[153],"Блокировка движения тележки - ворота в пом. 0041 не в положении Открыто",1);
ParExchange("R4AB16LDU",3,&SignalBuffer[157],"Блокировка движения тележки - Гомогенные двери не в положении Закрыты",1);
ParExchange("R4AB17LDU",3,&SignalBuffer[159],"Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора",1);
ParExchange("R4AB18LDU",3,&SignalBuffer[161],"Блокировка движения тележки назад - тележка на нижних механических упорах реактора",1);
ParExchange("R4AD10LDU",3,&SignalBuffer[163],"Перемещение тележки вперед",1);
ParExchange("R4AD20LDU",3,&SignalBuffer[165],"Перемещение тележки назад",1);
ParExchange("B5AD10LDU",3,&SignalBuffer[175],"Поднять НЛ2",1);
ParExchange("B5AD20LDU",3,&SignalBuffer[177],"Опустить НЛ2",1);
ParExchange("A5AD10LDU",3,&SignalBuffer[179],"Поднять НЛ1",1);
ParExchange("A5AD20LDU",3,&SignalBuffer[181],"Опустить НЛ1",1);
ParExchange("A5AZ03LDU",3,&SignalBuffer[191],"Несанкционированное перемещение НЛ1",1);
ParExchange("A5AB01LDU",3,&SignalBuffer[193],"Блокировка движения НЛ1 - Превышение времени движения",1);
ParExchange("A5AB02LDU",3,&SignalBuffer[195],"Блокировка движения НЛ1 - Нет перемещения",1);
ParExchange("B5AZ03LDU",3,&SignalBuffer[197],"Несанкционированное перемещение НЛ2",1);
ParExchange("B5AB01LDU",3,&SignalBuffer[199],"Блокировка движения НЛ2 - Превышение времени движения",1);
ParExchange("B5AB02LDU",3,&SignalBuffer[201],"Блокировка движения НЛ2 - Нет перемещения",1);
ParExchange("B4AD10LDU",3,&SignalBuffer[207],"Клапан Подъем НИ2 открыть (обесточить)",1);
ParExchange("A4AD10LDU",3,&SignalBuffer[209],"Клапан ПОДЪЕМ НИ1 открыть (обесточить)",1);
ParExchange("A4AZ03LDU",3,&SignalBuffer[211],"Несанкционированное перемещение НИ1",1);
ParExchange("A4AB01LDU",3,&SignalBuffer[213],"Блокировка движения НИ1 - Превышение времени движения",1);
ParExchange("A4AB02LDU",3,&SignalBuffer[215],"Блокировка движения НИ1 - Нет перемещения",1);
ParExchange("B4AZ03LDU",3,&SignalBuffer[217],"Несанкционированное перемещение НИ2",1);
ParExchange("B4AB01LDU",3,&SignalBuffer[219],"Блокировка движения НИ2 - Превышение времени движения",1);
ParExchange("B4AB02LDU",3,&SignalBuffer[221],"Блокировка движения НИ2 - Нет перемещения",1);
ParExchange("A5AB04LDU",3,&SignalBuffer[223],"Блокировка движения НЛ1 -Ошибка в направлении  движения",1);
ParExchange("B5AB04LDU",3,&SignalBuffer[225],"Блокировка движения НЛ2 -Ошибка в направлении  движения",1);
ParExchange("A6AB06LDU",3,&SignalBuffer[237],"Блокировка открытия БЗ1 - ОРР не в исходном состоянии",1);
ParExchange("A6AB07LDU",3,&SignalBuffer[239],"Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м",1);
ParExchange("A6AB08LDU",3,&SignalBuffer[241],"Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м",1);
ParExchange("A6AB09LDU",3,&SignalBuffer[243],"Блокировка открытия БЗ1 -ворота отстойной зоны не открыты",1);
ParExchange("B6AB06LDU",3,&SignalBuffer[245],"Блокировка открытия БЗ2 - ОРР не в исходном состоянии",1);
ParExchange("B6AB07LDU",3,&SignalBuffer[247],"Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м",1);
ParExchange("B6AB08LDU",3,&SignalBuffer[249],"Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м",1);
ParExchange("B6AB09LDU",3,&SignalBuffer[251],"Блокировка открытия БЗ2 -ворота отстойной зоны не открыты",1);
ParExchange("A6AB05LDU",3,&SignalBuffer[253],"Блокировка открытия БЗ1 - АНИ не установлен",1);
ParExchange("B8VS12LDU",3,&SignalBuffer[255],"Движение АЗ2 в сторону ВУ",1);
ParExchange("B8CV01RDU",1,&SignalBuffer[257],"Измеренная скорость перемещения АЗ2",1);
ParExchange("B8AB06LDU",3,&SignalBuffer[262],"Блокировка движения АЗ2 нет перемещения АЗ2",1);
ParExchange("B8AB07LDU",3,&SignalBuffer[264],"Блокировка движения АЗ2: превышение заданной скорости",1);
ParExchange("B8AB05LDU",3,&SignalBuffer[266],"Блокировка движения АЗ2: скорость перемещения менее заданной",1);
ParExchange("B8VS22LDU",3,&SignalBuffer[268],"Движение АЗ2 в сторону НУ",1);
ParExchange("B8AZ03LDU",3,&SignalBuffer[270],"Несанкционированное перемещение АЗ2",1);
ParExchange("B8AD10LDU",3,&SignalBuffer[274],"Перемещение АЗ2 вперед",1);
ParExchange("B8AD20LDU",3,&SignalBuffer[276],"Перемещение АЗ2 назад",1);
ParExchange("B8AB01LDU",3,&SignalBuffer[280],"Блокировка движения АЗ2 - Превышение времени движения",1);
ParExchange("B8AB04LDU",3,&SignalBuffer[282],"Блокировка движения АЗ2 -Ошибка в направлении  движения",1);
ParExchange("B8AB08LDU",3,&SignalBuffer[284],"Блокировка движения АЗ2 Гомогенные двери не закрыты",1);
ParExchange("B8AB09LDU",3,&SignalBuffer[286],"Блокировка  движения  АЗ2 - АС по мощности от любого канала",1);
ParExchange("B8AB10LDU",3,&SignalBuffer[288],"Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора",1);
ParExchange("B8AB11LDU",3,&SignalBuffer[290],"Блокировка движения АЗ2 -нет сигнала готовности СУЗ",1);
ParExchange("B8AB12LDU",3,&SignalBuffer[292],"Блокировка движения АЗ2 - НИ не в положении ВУ",1);
ParExchange("B8AB13LDU",3,&SignalBuffer[294],"Блокировка движения АЗ2 - ОРР не в исходном состоянии",1);
ParExchange("B8AB14LDU",3,&SignalBuffer[296],"Блокировка движения АЗ2 - Самоход любого механизма",1);
ParExchange("B8AB02LDU",3,&SignalBuffer[298],"Блокировка движения АЗ2- АНИ не установлен",1);
ParExchange("A8VS12LDU",3,&SignalBuffer[300],"Движение ДС2 в сторону ВУ",1);
ParExchange("A8CV01RDU",1,&SignalBuffer[302],"Измеренная скорость перемещения ДС2",1);
ParExchange("A8AB06LDU",3,&SignalBuffer[307],"Блокировка движения ДС2 нет перемещения ДС2",1);
ParExchange("A8AB07LDU",3,&SignalBuffer[309],"Блокировка движения ДС2: превышение заданной скорости",1);
ParExchange("A8AB05LDU",3,&SignalBuffer[311],"Блокировка движения ДС2: скорость перемещения менее заданной",1);
ParExchange("A8VS22LDU",3,&SignalBuffer[313],"Движение ДС2 в сторону НУ",1);
ParExchange("A8AZ03LDU",3,&SignalBuffer[315],"Несанкционированное перемещение ДС2",1);
ParExchange("A8AD10LDU",3,&SignalBuffer[317],"Перемещение ДС2 вперед",1);
ParExchange("A8AD20LDU",3,&SignalBuffer[319],"Перемещение ДС2 назад",1);
ParExchange("A8AB04LDU",3,&SignalBuffer[325],"Блокировка ДС2 -Ошибка в направлении  движения",1);
ParExchange("A8AB08LDU",3,&SignalBuffer[329],"Блокировка движения ДС2 Гомогенные двери не закрыты",1);
ParExchange("A8AB09LDU",3,&SignalBuffer[331],"Блокировка  движения ДС2 - АС по мощности от любого канала",1);
ParExchange("A8AB10LDU",3,&SignalBuffer[333],"Блокировка движения ДС2 - тележка не на верхних механических упорах реактора",1);
ParExchange("A8AB11LDU",3,&SignalBuffer[335],"Блокировка движения ДС2 -нет сигнала готовности СУЗ",1);
ParExchange("A8AB12LDU",3,&SignalBuffer[337],"Блокировка движения ДС2 - НИ не в положении ВУ",1);
ParExchange("A8AB13LDU",3,&SignalBuffer[339],"Блокировка движения ДС2 - ОРР не в исходном состоянии",1);
ParExchange("A8AB14LDU",3,&SignalBuffer[341],"Блокировка движения ДС2 - Самоход любого механизма",1);
ParExchange("A8AB02LDU",3,&SignalBuffer[343],"Блокировка движения ДС2- АНИ не установлен",1);
ParExchange("A8AB01LDU",3,&SignalBuffer[345],"Блокировка ДС2 -Превышение времени перемещения",1);
ParExchange("A2VS11LDU",3,&SignalBuffer[347],"Движение РБ1 в сторону ВУ",1);
ParExchange("A2CV01RDU",1,&SignalBuffer[349],"Измеренная скорость перемещения РБ1",1);
ParExchange("A2AB04LDU",3,&SignalBuffer[354],"Блокировка движения РБ1 нет перемещения  РБ1",1);
ParExchange("A2AB02LDU",3,&SignalBuffer[356],"Блокировка движения РБ1: превышение заданной скорости",1);
ParExchange("A2AB01LDU",3,&SignalBuffer[358],"Блокировка движения РБ1: скорость перемещения менее заданной",1);
ParExchange("A2VS21LDU",3,&SignalBuffer[360],"Движение РБ1 в сторону НУ",1);
ParExchange("A2AZ03LDU",3,&SignalBuffer[362],"Сброс РБ: Несанкционированное перемещение РБ1",1);
ParExchange("A2AD11LDU",3,&SignalBuffer[364],"Сигнал на перемещение РБ1 вверх",1);
ParExchange("A2AD21LDU",3,&SignalBuffer[366],"Сигнал на перемещение РБ1 вниз",1);
ParExchange("A2AD02LDU",3,&SignalBuffer[368],"0-й бит скорости РБ1",1);
ParExchange("A2AD03LDU",3,&SignalBuffer[370],"1-й бит скорости РБ1",1);
ParExchange("A2AD04LDU",3,&SignalBuffer[372],"2-й бит скорости РБ1",1);
ParExchange("A2AD05LDU",3,&SignalBuffer[374],"паритет команды на РБ1",1);
ParExchange("A2AB07LDU",3,&SignalBuffer[376],"Блокировка подъёма РБ1 Гомогенные двери не закрыты",1);
ParExchange("A2AB08LDU",3,&SignalBuffer[378],"Блокировка подъёма РБ1 - реактор не на рабочем месте",1);
ParExchange("A2AB05LDU",3,&SignalBuffer[380],"Блокировка подъёма РБ1 -нет сигнала готовности СУЗ",1);
ParExchange("A2AB06LDU",3,&SignalBuffer[382],"Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный",1);
ParExchange("A2AB09LDU",3,&SignalBuffer[384],"Блокировка подъёма РБ1- АНИ не установлен",1);
ParExchange("A2AB10LDU",3,&SignalBuffer[386],"Блокировка подъёма РБ1- есть сигнал общего сброса",1);
ParExchange("A2AB11LDU",3,&SignalBuffer[388],"Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате",1);
ParExchange("A2AB12LDU",3,&SignalBuffer[390],"Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ",1);
ParExchange("A2AB13LDU",3,&SignalBuffer[392],"Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС",1);
ParExchange("A2AB14LDU",3,&SignalBuffer[394],"Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной",1);
ParExchange("A2AB16LDU",3,&SignalBuffer[396],"Блокировка перемещения РБ1: выполняется программа 200 с",1);
ParExchange("A2AB17LDU",3,&SignalBuffer[398],"Блокировка перемещения РБ1: выполняется программа 20 мин",1);
ParExchange("A2AD01LDU",3,&SignalBuffer[400],"Разрешение движения РБ1",1);
ParExchange("A2CV02RDU",1,&SignalBuffer[402],"Заданная скорость перемещения РБ1",1);
ParExchange("B2CV01RDU",1,&SignalBuffer[407],"Измеренная скорость перемещения РБ2",1);
ParExchange("B2AB04LDU",3,&SignalBuffer[412],"Блокировка движения РБ2 нет перемещения  РБ2",1);
ParExchange("B2AB02LDU",3,&SignalBuffer[414],"Блокировка движения РБ2: превышение заданной скорости",1);
ParExchange("B2AB01LDU",3,&SignalBuffer[416],"Блокировка движения РБ2: скорость перемещения менее заданной",1);
ParExchange("B2AZ03LDU",3,&SignalBuffer[418],"Сброс РБ: Несанкционированное перемещение РБ2",1);
ParExchange("B2AD11LDU",3,&SignalBuffer[420],"Сигнал на перемещение РБ2 вверх",1);
ParExchange("B2AD21LDU",3,&SignalBuffer[422],"Сигнал на перемещение РБ2 вниз",1);
ParExchange("B2AD02LDU",3,&SignalBuffer[424],"0-й бит скорости РБ2",1);
ParExchange("B2AD03LDU",3,&SignalBuffer[426],"1-й бит скорости РБ2",1);
ParExchange("B2AD04LDU",3,&SignalBuffer[428],"2-й бит скорости РБ2",1);
ParExchange("B2AD05LDU",3,&SignalBuffer[430],"паритет команды на РБ2",1);
ParExchange("B2AD01LDU",3,&SignalBuffer[432],"Разрешение движения РБ2",1);
ParExchange("B2CV02RDU",1,&SignalBuffer[434],"Заданная скорость перемещения РБ2",1);
ParExchange("B2AB07LDU",3,&SignalBuffer[439],"Блокировка подъёма РБ2 Гомогенные двери не закрыты",1);
ParExchange("B2AB08LDU",3,&SignalBuffer[441],"Блокировка подъёма РБ2 - реактор не на рабочем месте",1);
ParExchange("B2AB05LDU",3,&SignalBuffer[443],"Блокировка подъёма РБ2 -нет сигнала готовности СУЗ",1);
ParExchange("B2AB06LDU",3,&SignalBuffer[445],"Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный",1);
ParExchange("B2AB09LDU",3,&SignalBuffer[447],"Блокировка подъёма РБ2- АНИ не установлен",1);
ParExchange("B2AB10LDU",3,&SignalBuffer[449],"Блокировка подъёма РБ2- есть сигнал общего сброса",1);
ParExchange("B2AB11LDU",3,&SignalBuffer[451],"Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате",1);
ParExchange("B2AB12LDU",3,&SignalBuffer[453],"Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ",1);
ParExchange("B2AB13LDU",3,&SignalBuffer[455],"Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС",1);
ParExchange("B2AB14LDU",3,&SignalBuffer[457],"Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной",1);
ParExchange("B2AB16LDU",3,&SignalBuffer[459],"Блокировка перемещения РБ2: выполняется программа 200 с",1);
ParExchange("B2AB17LDU",3,&SignalBuffer[461],"Блокировка перемещения РБ2: выполняется программа 20 мин",1);
ParExchange("R1AZ03LDU",3,&SignalBuffer[463],"Несанкционированное перемещение МДЗ1",1);
ParExchange("R1AB01LDU",3,&SignalBuffer[465],"Блокировка движения МДЗ1 - Превышение времени движения",1);
ParExchange("R1AB02LDU",3,&SignalBuffer[467],"Блокировка движения МДЗ1 - Нет перемещения МДЗ1",1);
ParExchange("R2AZ03LDU",3,&SignalBuffer[469],"Несанкционированное перемещение МДЗ2",1);
ParExchange("R2AB01LDU",3,&SignalBuffer[471],"Блокировка движения МДЗ2 - Превышение времени движения",1);
ParExchange("R2AB02LDU",3,&SignalBuffer[473],"Блокировка движения МДЗ2 - Нет перемещения МДЗ2",1);
ParExchange("R1AB04LDU",3,&SignalBuffer[475],"Блокировка движения МДЗ1 -Ошибка в направлении  движения",1);
ParExchange("R2AB04LDU",3,&SignalBuffer[477],"Блокировка движения МДЗ2 -Ошибка в направлении  движения",1);
ParExchange("R1AD10LDU",3,&SignalBuffer[479],"Опустить МДЗ1",1);
ParExchange("R1AD20LDU",3,&SignalBuffer[481],"Поднять МДЗ1",1);
ParExchange("A1VS12LDU",3,&SignalBuffer[495],"Движение ББ1 в сторону ВУ",1);
ParExchange("A1CV01RDU",1,&SignalBuffer[497],"Измеренная скорость перемещения ББ1",1);
ParExchange("A1AB04LDU",3,&SignalBuffer[502],"Блокировка движения ББ1 нет перемещения  ББ1",1);
ParExchange("A1AB02LDU",3,&SignalBuffer[504],"Блокировка движения ББ1: превышение заданной скорости",1);
ParExchange("A1AB01LDU",3,&SignalBuffer[506],"Блокировка движения ББ1: скорость перемещения менее заданной",1);
ParExchange("A1VS22LDU",3,&SignalBuffer[508],"Движение ББ1 в сторону НУ",1);
ParExchange("A1AZ03LDU",3,&SignalBuffer[510],"Сброс ББ: Несанкционированное перемещение ББ1",1);
ParExchange("A1AD11LDU",3,&SignalBuffer[512],"Сигнал на перемещение ББ1 вверх",1);
ParExchange("A1AD21LDU",3,&SignalBuffer[514],"Сигнал на перемещение ББ1 вниз",1);
ParExchange("A1AD02LDU",3,&SignalBuffer[516],"0-й бит скорости ББ1",1);
ParExchange("A1AD03LDU",3,&SignalBuffer[518],"1-й бит скорости ББ1",1);
ParExchange("A1AD04LDU",3,&SignalBuffer[520],"2-й бит скорости ББ1",1);
ParExchange("A1AD05LDU",3,&SignalBuffer[522],"паритет команды на ББ1",1);
ParExchange("A1AD01LDU",3,&SignalBuffer[524],"Разрешение движения ББ1",1);
ParExchange("A1CV02RDU",1,&SignalBuffer[526],"Заданная скорость перемещения ББ1",1);
ParExchange("A1AB07LDU",3,&SignalBuffer[531],"Блокировка подъёма ББ1 Гомогенные двери не закрыты",1);
ParExchange("A1AB08LDU",3,&SignalBuffer[533],"Блокировка подъёма ББ1 - реактор не на рабочем месте",1);
ParExchange("A1AB05LDU",3,&SignalBuffer[535],"Блокировка подъёма ББ1 -нет сигнала готовности СУЗ",1);
ParExchange("A1AB06LDU",3,&SignalBuffer[537],"Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный",1);
ParExchange("A1AB09LDU",3,&SignalBuffer[539],"Блокировка подъёма ББ1- АНИ не установлен",1);
ParExchange("A1AB10LDU",3,&SignalBuffer[541],"Блокировка подъёма ББ1- есть сигнал общего сброса",1);
ParExchange("A1AB11LDU",3,&SignalBuffer[543],"Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате",1);
ParExchange("A1AB12LDU",3,&SignalBuffer[545],"Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ",1);
ParExchange("A1AB13LDU",3,&SignalBuffer[547],"Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС",1);
ParExchange("A1AB14LDU",3,&SignalBuffer[549],"Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной",1);
ParExchange("A1AB16LDU",3,&SignalBuffer[551],"Блокировка перемещения ББ1: выполняется программа 200 с",1);
ParExchange("A1AB17LDU",3,&SignalBuffer[553],"Блокировка перемещения ББ1: выполняется программа 20 мин",1);
ParExchange("A1AB18LDU",3,&SignalBuffer[555],"Блокировка подъёма ББ1- РБ-СТР ниже 80 мм",1);
ParExchange("B1VS12LDU",3,&SignalBuffer[557],"Движение ББ2 в сторону ВУ",1);
ParExchange("B1CV01RDU",1,&SignalBuffer[559],"Измеренная скорость перемещения ББ2",1);
ParExchange("B1AB04LDU",3,&SignalBuffer[564],"Блокировка движения ББ2 нет перемещения  ББ2",1);
ParExchange("B1AB02LDU",3,&SignalBuffer[566],"Блокировка движения ББ2: превышение заданной скорости",1);
ParExchange("B1AB01LDU",3,&SignalBuffer[568],"Блокировка движения ББ2: скорость перемещения менее заданной",1);
ParExchange("B1VS22LDU",3,&SignalBuffer[570],"Движение ББ2 в сторону НУ",1);
ParExchange("B1AZ03LDU",3,&SignalBuffer[572],"Сброс ББ: Несанкционированное перемещение ББ2",1);
ParExchange("B1AD11LDU",3,&SignalBuffer[574],"Сигнал на перемещение ББ2 вверх",1);
ParExchange("B1AD21LDU",3,&SignalBuffer[576],"Сигнал на перемещение ББ2 вниз",1);
ParExchange("B1AD02LDU",3,&SignalBuffer[578],"0-й бит скорости ББ2",1);
ParExchange("B1AD03LDU",3,&SignalBuffer[580],"1-й бит скорости ББ2",1);
ParExchange("B1AD04LDU",3,&SignalBuffer[582],"2-й бит скорости ББ2",1);
ParExchange("B1AD05LDU",3,&SignalBuffer[584],"паритет команды на ББ2",1);
ParExchange("B1AD01LDU",3,&SignalBuffer[586],"Разрешение движения ББ2",1);
ParExchange("B1CV02RDU",1,&SignalBuffer[588],"Заданная скорость перемещения ББ2",1);
ParExchange("B1AB07LDU",3,&SignalBuffer[593],"Блокировка подъёма ББ2 Гомогенные двери не закрыты",1);
ParExchange("B1AB08LDU",3,&SignalBuffer[595],"Блокировка подъёма ББ2 - реактор не на рабочем месте",1);
ParExchange("B1AB05LDU",3,&SignalBuffer[597],"Блокировка подъёма ББ2 -нет сигнала готовности СУЗ",1);
ParExchange("B1AB06LDU",3,&SignalBuffer[599],"Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный",1);
ParExchange("B1AB09LDU",3,&SignalBuffer[601],"Блокировка подъёма ББ2- АНИ не установлен",1);
ParExchange("B1AB10LDU",3,&SignalBuffer[603],"Блокировка подъёма ББ2- есть сигнал общего сброса",1);
ParExchange("B1AB11LDU",3,&SignalBuffer[605],"Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате",1);
ParExchange("B1AB12LDU",3,&SignalBuffer[607],"Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ",1);
ParExchange("B1AB13LDU",3,&SignalBuffer[609],"Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС",1);
ParExchange("B1AB14LDU",3,&SignalBuffer[611],"Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной",1);
ParExchange("B1AB16LDU",3,&SignalBuffer[613],"Блокировка перемещения ББ2: выполняется программа 200 с",1);
ParExchange("B1AB17LDU",3,&SignalBuffer[615],"Блокировка перемещения ББ2: выполняется программа 20 мин",1);
ParExchange("B1AB18LDU",3,&SignalBuffer[617],"Блокировка подъёма ББ2- РБ-СТР ниже 80 мм",1);
ParExchange("A3VS12LDU",3,&SignalBuffer[619],"Движение ИС1 в сторону ВУ",1);
ParExchange("A3CV01RDU",1,&SignalBuffer[621],"Измеренная скорость перемещения ИС1",1);
ParExchange("A3AB04LDU",3,&SignalBuffer[626],"Блокировка движения ИС1 нет перемещения  ИС1",1);
ParExchange("A3AB02LDU",3,&SignalBuffer[628],"Блокировка движения ИС1: превышение заданной скорости",1);
ParExchange("A3AB01LDU",3,&SignalBuffer[630],"Блокировка движения ИС1: скорость перемещения менее заданной",1);
ParExchange("A3VS22LDU",3,&SignalBuffer[632],"Движение ИС1 в сторону НУ",1);
ParExchange("A3AZ03LDU",3,&SignalBuffer[634],"Сброс РБ: Несанкционированное перемещение ИС1",1);
ParExchange("A3AD11LDU",3,&SignalBuffer[636],"Сигнал на перемещение ИС1 вверх",1);
ParExchange("A3AD21LDU",3,&SignalBuffer[638],"Сигнал на перемещение ИС1 вниз",1);
ParExchange("A3AD02LDU",3,&SignalBuffer[640],"0-й бит скорости ИС1",1);
ParExchange("A3AD03LDU",3,&SignalBuffer[642],"1-й бит скорости ИС1",1);
ParExchange("A3AD04LDU",3,&SignalBuffer[644],"2-й бит скорости ИС1",1);
ParExchange("A3AD05LDU",3,&SignalBuffer[646],"паритет команды на ИС1",1);
ParExchange("A3AD01LDU",3,&SignalBuffer[648],"Разрешение движения ИС1",1);
ParExchange("A3CV02RDU",1,&SignalBuffer[650],"Заданная скорость перемещения ИС1",1);
ParExchange("A3AB07LDU",3,&SignalBuffer[655],"Блокировка подъёма ИС1 Гомогенные двери не закрыты",1);
ParExchange("A3AB08LDU",3,&SignalBuffer[657],"Блокировка подъёма ИС1 - реактор не на рабочем месте",1);
ParExchange("A3AB05LDU",3,&SignalBuffer[659],"Блокировка подъёма ИС1 -нет сигнала готовности СУЗ",1);
ParExchange("A3AB06LDU",3,&SignalBuffer[661],"Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный",1);
ParExchange("A3AB09LDU",3,&SignalBuffer[663],"Блокировка подъёма ИС1- АНИ не установлен",1);
ParExchange("A3AB10LDU",3,&SignalBuffer[665],"Блокировка подъёма ИС1- есть сигнал общего сброса",1);
ParExchange("A3AB11LDU",3,&SignalBuffer[667],"Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате",1);
ParExchange("A3AB12LDU",3,&SignalBuffer[669],"Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ",1);
ParExchange("A3AB14LDU",3,&SignalBuffer[671],"Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной",1);
ParExchange("A3AB16LDU",3,&SignalBuffer[673],"Блокировка перемещения ИС1: выполняется программа 200 с",1);
ParExchange("A3AB17LDU",3,&SignalBuffer[675],"Блокировка перемещения ИС1: выполняется программа 20 мин",1);
ParExchange("A3AB18LDU",3,&SignalBuffer[677],"Блокировка подъёма ИС1- РБ-СТР ниже 80 мм",1);
ParExchange("A3AB20LDU",3,&SignalBuffer[679],"Блокировка выстрела ИС1 - клапан ВПИС1 закрыт",1);
ParExchange("B3VS12LDU",3,&SignalBuffer[681],"Движение ИС2 в сторону ВУ",1);
ParExchange("B3CV01RDU",1,&SignalBuffer[683],"Измеренная скорость перемещения ИС2",1);
ParExchange("B3AB04LDU",3,&SignalBuffer[688],"Блокировка движения ИС2 нет перемещения  ИС1",1);
ParExchange("B3AB02LDU",3,&SignalBuffer[690],"Блокировка движения ИС2: превышение заданной скорости",1);
ParExchange("B3AB01LDU",3,&SignalBuffer[692],"Блокировка движения ИС2: скорость перемещения менее заданной",1);
ParExchange("B3VS22LDU",3,&SignalBuffer[694],"Движение ИС2 в сторону НУ",1);
ParExchange("B3AZ03LDU",3,&SignalBuffer[696],"Сброс РБ: Несанкционированное перемещение ИС2",1);
ParExchange("B3AD11LDU",3,&SignalBuffer[698],"Сигнал на перемещение ИС2 вверх",1);
ParExchange("B3AD21LDU",3,&SignalBuffer[700],"Сигнал на перемещение ИС2 вниз",1);
ParExchange("B3AD02LDU",3,&SignalBuffer[702],"0-й бит скорости ИС2",1);
ParExchange("B3AD03LDU",3,&SignalBuffer[704],"1-й бит скорости ИС2",1);
ParExchange("B3AD04LDU",3,&SignalBuffer[706],"2-й бит скорости ИС2",1);
ParExchange("B3AD05LDU",3,&SignalBuffer[708],"паритет команды на ИС2",1);
ParExchange("B3AD01LDU",3,&SignalBuffer[710],"Разрешение движения ИС2",1);
ParExchange("B3CV02RDU",1,&SignalBuffer[712],"Заданная скорость перемещения ИС2",1);
ParExchange("B3AB07LDU",3,&SignalBuffer[717],"Блокировка подъёма ИС2 Гомогенные двери не закрыты",1);
ParExchange("B3AB08LDU",3,&SignalBuffer[719],"Блокировка подъёма ИС2 - реактор не на рабочем месте",1);
ParExchange("B3AB05LDU",3,&SignalBuffer[721],"Блокировка подъёма ИС2 -нет сигнала готовности СУЗ",1);
ParExchange("B3AB06LDU",3,&SignalBuffer[723],"Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный",1);
ParExchange("B3AB09LDU",3,&SignalBuffer[725],"Блокировка подъёма ИС2- АНИ не установлен",1);
ParExchange("B3AB10LDU",3,&SignalBuffer[727],"Блокировка подъёма ИС2- есть сигнал общего сброса",1);
ParExchange("B3AB11LDU",3,&SignalBuffer[729],"Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате",1);
ParExchange("B3AB12LDU",3,&SignalBuffer[731],"Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ",1);
ParExchange("B3AB14LDU",3,&SignalBuffer[733],"Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной",1);
ParExchange("B3AB16LDU",3,&SignalBuffer[735],"Блокировка перемещения ИС2: выполняется программа 200 с",1);
ParExchange("B3AB17LDU",3,&SignalBuffer[737],"Блокировка перемещения ИС2: выполняется программа 20 мин",1);
ParExchange("B3AB18LDU",3,&SignalBuffer[739],"Блокировка подъёма ИС2- РБ-СТР ниже 80 мм",1);
ParExchange("B3AB20LDU",3,&SignalBuffer[741],"Блокировка выстрела ИС2 - клапан ВПИС2 закрыт",1);
ParExchange("A2AD31LDU",3,&SignalBuffer[747],"Клапан СБРОС РБ1 открыть (обесточить)",1);
ParExchange("B2AD31LDU",3,&SignalBuffer[749],"Клапан Сброс РБ2 открыть (обесточить)",1);
ParExchange("A1AD31LDU",3,&SignalBuffer[751],"Клапан СБРОС ББ1 открыть (обесточить)",1);
ParExchange("B1AD31LDU",3,&SignalBuffer[753],"Клапан СБРОС ББ2 открыть (обесточить)",1);
ParExchange("A2AD32LDU",3,&SignalBuffer[755],"Обесточить ЭМ РБ1",1);
ParExchange("B2AD32LDU",3,&SignalBuffer[757],"Обесточить ЭМ РБ2",1);
ParExchange("A1AD32LDU",3,&SignalBuffer[759],"Обесточить ЭМ ББ1",1);
ParExchange("B1AD32LDU",3,&SignalBuffer[761],"Обесточить ЭМ ББ2",1);
ParExchange("R0VX01LDU",3,&SignalBuffer[765],"ДО ИМПУЛЬСА",1);
ParExchange("R0VL01IDU",2,&SignalBuffer[767],"До импульса минут",1);
ParExchange("R0VL11IDU",2,&SignalBuffer[770],"До импульса секунд",1);
ParExchange("R0VL06RDU",1,&SignalBuffer[773],"Индикация (Время задержки от ВУ РБ)",1);
ParExchange("B3AD33LDU",3,&SignalBuffer[778],"Клапан ВЫСТРЕЛ ИС2 закрыть (обесточить)",1);
ParExchange("R0VL02RDU",1,&SignalBuffer[782],"Индикация (Время задержки ИНИ)",1);
ParExchange("R8AD21LDU",3,&SignalBuffer[787],"Запуск системы инициирования",1);
ParExchange("R0AD14LDU",3,&SignalBuffer[789],"Имитация срабатывания верхней АС II УР",1);
ParExchange("R0VL04RDU",1,&SignalBuffer[791],"Индикация (Время срабатывания верхней АС II УР)",1);
ParExchange("R0AB04LDU",3,&SignalBuffer[796],"Нарушение времени срабатывания верхней АС II УР",1);
ParExchange("R0AB06LDU",3,&SignalBuffer[798],"Нарушение времени задержки от ВУ РБ",1);
ParExchange("R0AB02LDU",3,&SignalBuffer[800],"Нарушение времени задержки ИНИ",1);
ParExchange("R0VL03RDU",1,&SignalBuffer[802],"Индикация (Время срабатывания АЗ от ВУ ИС)",1);
ParExchange("R0VL05RDU",1,&SignalBuffer[807],"Индикация (Время срабатывания АЗ от НУП ИС)",1);
ParExchange("R0VL21IDU",2,&SignalBuffer[812],"Декатрон",1);
ParExchange("R0VX03LDU",3,&SignalBuffer[815],"Готовность 2 мин",1);
ParExchange("R0VS21IDU",2,&SignalBuffer[817],"Индикация ВИД ПРОВЕРКИ",1);
ParExchange("A1VS01IDU",2,&SignalBuffer[820],"Готовность к управлению ББ1",1);
ParExchange("B1VS01IDU",2,&SignalBuffer[823],"Готовность к управлению ББ2",1);
ParExchange("A3VS01IDU",2,&SignalBuffer[826],"Готовность к управлению ИС1",1);
ParExchange("B3VS01IDU",2,&SignalBuffer[829],"Готовность к управлению ИС2",1);
ParExchange("A2VS01IDU",2,&SignalBuffer[832],"Готовность к управлению РБ1",1);
ParExchange("A4VS01IDU",2,&SignalBuffer[835],"Готовность к управлению НИ1",1);
ParExchange("A4VS12LDU",3,&SignalBuffer[838],"Движение НИ1 в сторону ВУ",1);
ParExchange("A4VS22LDU",3,&SignalBuffer[840],"Движение НИ1 в сторону НУ",1);
ParExchange("B4VS01IDU",2,&SignalBuffer[842],"Готовность к управлению НИ2",1);
ParExchange("B4VS12LDU",3,&SignalBuffer[845],"Движение НИ2 в сторону ВУ",1);
ParExchange("B4VS22LDU",3,&SignalBuffer[847],"Движение НИ2 в сторону НУ",1);
ParExchange("A5VS01IDU",2,&SignalBuffer[849],"Готовность к управлению НЛ1",1);
ParExchange("B5VS01IDU",2,&SignalBuffer[852],"Готовность к управлению НЛ2",1);
ParExchange("A6VS01IDU",2,&SignalBuffer[855],"Готовность к управлению БЗ1",1);
ParExchange("R4VS01IDU",2,&SignalBuffer[858],"Готовность к управлению тележкой реактора",1);
ParExchange("R2VS01IDU",2,&SignalBuffer[861],"Готовность к управлению МДЗ2",1);
ParExchange("R1VS01IDU",2,&SignalBuffer[864],"Готовность к управлению МДЗ1",1);
ParExchange("B9AD10LDU",3,&SignalBuffer[875],"Открыть клапан Подъем НИ ДС2",1);
ParExchange("A9AD10LDU",3,&SignalBuffer[877],"Открыть клапан Подъем НИ ДС1",1);
ParExchange("A9AZ03LDU",3,&SignalBuffer[879],"Несанкционированное перемещение НИ ДС1",1);
ParExchange("A9AB01LDU",3,&SignalBuffer[881],"Блокировка движения НИ ДС1 - Превышение времени движения",1);
ParExchange("A9AB02LDU",3,&SignalBuffer[883],"Блокировка НИ ДС1 - Нет перемещения",1);
ParExchange("B9AZ03LDU",3,&SignalBuffer[885],"Несанкционированное перемещение НИ ДС2",1);
ParExchange("B9AB01LDU",3,&SignalBuffer[887],"Блокировка движения НИ ДС2 - Превышение времени движения",1);
ParExchange("B9AB02LDU",3,&SignalBuffer[889],"Блокировка движения НИ ДС2 - Нет перемещения",1);
ParExchange("R0AB01LDU",3,&SignalBuffer[891],"Режим проверки разрешён",1);
ParExchange("A2AD33LDU",3,&SignalBuffer[897],"Клапан ПОДЪЕМ РБ1 открыть (обесточить)",1);
ParExchange("B2AD33LDU",3,&SignalBuffer[899],"Клапан ПОДЪЕМ РБ2 открыть (обесточить)",1);
ParExchange("A3AD33LDU",3,&SignalBuffer[901],"Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)",1);
ParExchange("A3AD34LDU",3,&SignalBuffer[903],"Клапан ВПИС1  открыть (обесточить)",1);
ParExchange("A3AD31LDU",3,&SignalBuffer[905],"Клапан СПУСК ИС1 открыть (обесточить)",1);
ParExchange("B3AD34LDU",3,&SignalBuffer[907],"Клапан ВПИС ИС2  открыть (обесточить)",1);
ParExchange("B3AD31LDU",3,&SignalBuffer[909],"Клапан СПУСК ИС2 открыть (обесточить)",1);
ParExchange("A7AP31LDU",3,&SignalBuffer[928],"Клапан Обдув АЗ1 открыть (обесточить)",1);
ParExchange("B7AP31LDU",3,&SignalBuffer[930],"Клапан Обдув АЗ2 открыть (обесточить)",1);
ParExchange("R0VW13LDU",3,&SignalBuffer[937],"Индикация выбора АЗ1 или АЗ1+АЗ2",1);
ParExchange("R0VW23LDU",3,&SignalBuffer[939],"Индикация выбора АЗ2 или АЗ1+АЗ2",1);
ParExchange("R0VX08IDU",2,&SignalBuffer[941],"Индикация Режим",1);
ParExchange("R0VX09LDU",3,&SignalBuffer[944],"Индикация регулятор мощности включен/отключен",1);
ParExchange("R0VS17LDU",3,&SignalBuffer[946],"Индикация выбора АВТОМАТ",1);
ParExchange("A2VS32LDU",3,&SignalBuffer[948],"Индикация  СБРОС РБ1",1);
ParExchange("B2VS32LDU",3,&SignalBuffer[950],"Индикация  СБРОС РБ2",1);
ParExchange("A3VX01LDU",3,&SignalBuffer[952],"Индикация Выстрел ИС1",1);
ParExchange("B3VX01LDU",3,&SignalBuffer[956],"Индикация Выстрел ИС2",1);
ParExchange("R0VS18LDU",3,&SignalBuffer[958],"Индикация  Проверка схем сброса",1);
ParExchange("R0VP73LDU",3,&SignalBuffer[980],"ПС давления для РУ",1);
ParExchange("B2VS11LDU",3,&SignalBuffer[992],"Движение РБ2 в сторону ВУ",1);
ParExchange("B2VS21LDU",3,&SignalBuffer[994],"Движение РБ2 в сторону НУ",1);
ParExchange("B2VS01IDU",2,&SignalBuffer[996],"Готовность к управлению РБ2",1);
ParExchange("A7AZ03LDU",3,&SignalBuffer[1003],"Несанкционированное включение обдува АЗ1",1);
ParExchange("B7AZ03LDU",3,&SignalBuffer[1005],"Несанкционированное включение обдува АЗ2",1);
ParExchange("R0VL01RDU",1,&SignalBuffer[1011],"Индикация Время задержки",1);
ParExchange("R0VZ71LDU",3,&SignalBuffer[1020],"Обобщенный сигнал АЗ",1);
ParExchange("A1AB19LDU",3,&SignalBuffer[1036],"Блокировка автоматического подъёма ББ1 -превышение нейтронного потока",1);
ParExchange("R0AB03LDU",3,&SignalBuffer[1076],"Нарушение времени срабатывания АЗ от ВУ ИС",1);
ParExchange("R0AB05LDU",3,&SignalBuffer[1078],"Нарушение времени срабатывания АЗ от НУП ИС",1);
ParExchange("A2AB15LDU",3,&SignalBuffer[1090],"Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин",1);
ParExchange("B2AB15LDU",3,&SignalBuffer[1092],"Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин",1);
ParExchange("R0AD21LDU",3,&SignalBuffer[1094],"Подключить защиту от II УР",1);
ParExchange("R0VX02LDU",3,&SignalBuffer[1096],"Импульс разрешен",1);
ParExchange("R0EE03LDU",3,&SignalBuffer[1098],"ВПИС ИС",1);
ParExchange("R0AB07LDU",3,&SignalBuffer[1100],"Блокировка программы подъёма ОРР-ошибка уставки АЗ2",1);
ParExchange("R0AD16LDU",3,&SignalBuffer[1102],"Контроль  I-II УР. РАД",1);
ParExchange("B6VS01IDU",2,&SignalBuffer[1106],"Готовность к управлению БЗ2",1);
ParExchange("R2AD20LDU",3,&SignalBuffer[1109],"Поднять МДЗ2",1);
ParExchange("R2AD10LDU",3,&SignalBuffer[1111],"Опустить МДЗ2",1);
ParExchange("B8VS01IDU",2,&SignalBuffer[1113],"Готовность к управлению АЗ2",1);
ParExchange("A8VS01IDU",2,&SignalBuffer[1116],"Готовность к управлению ДС2",1);
ParExchange("R0VS11LDU",3,&SignalBuffer[1143],"РУ не готова к работе",1);
ParExchange("B6AB05LDU",3,&SignalBuffer[1145],"Блокировка открытия БЗ2- АНИ не установлен",1);
ParExchange("R0AB08LDU",3,&SignalBuffer[1147],"Блокировка кнопки ПУСК - тележка не у образцов",1);
ParExchange("R0AB09LDU",3,&SignalBuffer[1174],"Ошибка в заданной координате ББ1",1);
ParExchange("R0AB10LDU",3,&SignalBuffer[1176],"Ошибка в заданной координате ББ2",1);
ParExchange("R0AB11LDU",3,&SignalBuffer[1178],"Ошибка в заданной координате  ИС1",1);
ParExchange("R0AB12LDU",3,&SignalBuffer[1180],"Ошибка в заданной координате  ИС2",1);
ParExchange("R0AB13LDU",3,&SignalBuffer[1182],"Ошибка в заданной координате  АЗ2",1);
ParExchange("A4ZAV",3,&SignalBuffer[1184]," Завершение НИ",1);
ParExchange("A6ZAV",3,&SignalBuffer[1186]," Завершение БЗ",1);
ParExchange("R2ZAV",3,&SignalBuffer[1188]," Завершение МДЗ1,2",1);
ParExchange("A5ZAV",3,&SignalBuffer[1190]," Завершение НЛ1,2",1);
ParExchange("B8ZAV",3,&SignalBuffer[1192]," Завершение AZ2",1);
ParExchange("A2ZAV",3,&SignalBuffer[1194],"Завершение РБ1,2",1);
ParExchange("A8ZAV",3,&SignalBuffer[1196]," Завершение ДС2",1);
ParExchange("A9ZAV",3,&SignalBuffer[1198],"Завершение НИ ДС1(2)",1);
ParExchange("R4ABL",3,&SignalBuffer[1200],"Блокировка тележки -",1);
ParExchange("A4UP",3,&SignalBuffer[1202]," Задание вверх  НИ",1);
ParExchange("A4DW",3,&SignalBuffer[1204]," Задание вниз  НИ",1);
ParExchange("R0AB14LDU",3,&SignalBuffer[1206],"Режим проверки не разрешён: ИС2 ниже 55 мм",1);
ParExchange("R0AB15LDU",3,&SignalBuffer[1208],"Режим проверки не разрешён: ИС1 ниже 55 мм",1);
ParExchange("A3IS12LDU",3,&SignalBuffer[1210],"Приход на ВУ штока ИС1",1);
ParExchange("B3IS12LDU",3,&SignalBuffer[1212],"Приход на ВУ штока ИС2",1);
ParExchange("A1ZAV",3,&SignalBuffer[1214]," Завершение ББ1,2",1);
ParExchange("A3ZAV",3,&SignalBuffer[1216]," Завершение ИС1,2",1);
ParExchange("B1AB19LDU",3,&SignalBuffer[1218],"Блокировка автоматического подъёма ББ2 -превышение нейтронного потока",1);
ParExchange("R0AB16LDU",3,&SignalBuffer[1230],"Блокировка регулирования мощности: Усредненный период разгона меньше допустимого",1);
ParExchange("R0AB17LDU",3,&SignalBuffer[1232],"Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого",1);
ParExchange("R0AB18LDU",3,&SignalBuffer[1234],"Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2",1);
ParExchange("A3MC01RDU",1,&SignalBuffer[1256],"Заданная координата положения ИС от регулятора мм",1);
ParExchange("A3MC02RDU",1,&SignalBuffer[1261],"Температурная корректировка координаты ИМ",1);
ParExchange("R0CN91LDU",1,&SignalBuffer[1266],"Рассчётная реактивность от регулятора",1);
ParExchange("A3MC03RDU",1,&SignalBuffer[1271],"Координата положения ИМ 0-й реактивности",1);
ParExchange("A3AB15LDU",3,&SignalBuffer[1276],"Блокировка заполнения ресивера ИС1: работает регулятор мощности",1);
ParExchange("R0AB20LDU",3,&SignalBuffer[1278],"Блокировка изменения положения ОР: работает  регулятор мощности",1);
ParExchange("R0CN92LDU",1,&SignalBuffer[1280],"Рассчётный коэффициент  опережения старта ИМ",1);
ParExchange("R0VN11RDU",1,&SignalBuffer[1285],"Текущая мощность РУ",1);
ParExchange("R0VN12RDU",1,&SignalBuffer[1290],"Заданная мощность РУ",1);
ParExchange("R0AB19LDU",3,&SignalBuffer[1295],"Блокировка регулирования мощности:Нарушение исходных условий.",1);
ParExchange("R0CN93LDU",1,&SignalBuffer[1297],"время работы на мощности более 100Вт, сек",1);
ParExchange("R0CN94LDU",1,&SignalBuffer[1302],"Скорость изменения мощности",1);
ParExchange("R0CN95LDU",2,&SignalBuffer[1307],"Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание",1);
ParExchange("R0AD03LZ1",3,&SignalBuffer[1310],"Имитация прихода на ВУ ИС (БАЗ1)",1);
ParExchange("R0AD03LZ2",3,&SignalBuffer[1312],"Имитация прихода на ВУ ИС (БАЗ2)",1);
ParExchange("R0AD04LZ1",3,&SignalBuffer[1314],"Имитация срабатывания АС II УР. РАД (БАЗ1)",1);
ParExchange("R0AD04LZ2",3,&SignalBuffer[1316],"Имитация срабатывания АС II УР. РАД (БАЗ2)",1);
ParExchange("R0AD05LZ1",3,&SignalBuffer[1318],"Имитация ухода с НУП ИС  (БАЗ1)",1);
ParExchange("R0AD05LZ2",3,&SignalBuffer[1320],"Имитация ухода с НУП ИС  (БАЗ2)",1);
ParExchange("R0VL22LDU",3,&SignalBuffer[1330],"Конец программы 200сек",1);
ParExchange("R0VL23LDU",3,&SignalBuffer[1332],"Конец программы 20мин",1);
ParExchange("A3AB19LDU",3,&SignalBuffer[1338],"Блокировка пневматического подъема ИС1: режим статический",1);
ParExchange("B3AB19LDU",3,&SignalBuffer[1340],"Блокировка пневматического подъема ИС2: режим статический",1);
ParExchange("A3EE03LDU",3,&SignalBuffer[1342],"ВПИС ИС1",1);
ParExchange("B3EE03LDU",3,&SignalBuffer[1344],"ВПИС ИС2",1);
ParExchange("B3AB15LDU",3,&SignalBuffer[1346],"Блокировка заполнения ресивера ИС2: работает регулятор мощности",1);
ParExchange("R5VS22LDU",3,&SignalBuffer[1350],"Движение ворот отстойной зоны к закрыты",1);
ParExchange("R5VS12LDU",3,&SignalBuffer[1352],"Движение ворот отстойной зоны к открыты",1);
ParExchange("R5VS01IDU",2,&SignalBuffer[1354],"Готовность к управлению ворот отстойной зоны",1);
ParExchange("R3VS22LDU",3,&SignalBuffer[1357],"Движение гомогенных дверей к закрыты",1);
ParExchange("R3VS12LDU",3,&SignalBuffer[1359],"Движение гомогенных дверей к открыты",1);
ParExchange("R3VS01IDU",2,&SignalBuffer[1361],"Готовность к управлению гомогенных дверей",1);
ParExchange("A3AB13LDU",3,&SignalBuffer[1364],"Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС",1);
ParExchange("A3VP52LDU",3,&SignalBuffer[1366],"Давление ВЫСТРЕЛ ИС1 ниже ПС",1);
ParExchange("B3AB13LDU",3,&SignalBuffer[1368],"Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой",1);
ParExchange("B3VP52LDU",3,&SignalBuffer[1370],"Давление ВЫСТРЕЛ ИС2 ниже ПС",1);
ParExchange("B1VC01RDU",1,&SignalBuffer[1377],"Координата ББ2, мм",1);
ParExchange("B3VC01RDU",1,&SignalBuffer[1404],"Координата ИС2, мм",1);
ParExchange("A8VC01RDU",1,&SignalBuffer[1414],"Координата ДС2, мм",1);
ParExchange("A1VC01RDU",1,&SignalBuffer[1429],"Координата ББ1, мм",1);
ParExchange("A3VP42LDU",3,&SignalBuffer[1468],"Давление ВЫСТРЕЛ ИС1 ниже АС",1);
ParExchange("A3CP02RDU",1,&SignalBuffer[1470],"Текущее давление ВЫСТРЕЛ ИС1",1);
ParExchange("B3VP42LDU",3,&SignalBuffer[1475],"Давление ВЫСТРЕЛ ИС2 ниже АС",1);
ParExchange("B3CP02RDU",1,&SignalBuffer[1477],"Текущее давление ВЫСТРЕЛ ИС2",1);
ParExchange("B3VP82LDU",3,&SignalBuffer[1482],"Давление ВЫСТРЕЛ ИС2 в норме",1);
ParExchange("A3VP82LDU",3,&SignalBuffer[1484],"Давление ВЫСТРЕЛ ИС1 в норме",1);
ParExchange("A0VE01LDU",3,&SignalBuffer[1492],"Напряжение в системы АЗ1 подано",1);
ParExchange("B0VE01LDU",3,&SignalBuffer[1494],"Напряжение в системы АЗ2 подано",1);
ParExchange("A0VP01LDU",3,&SignalBuffer[1496],"Давление в системы АЗ1 подано",1);
ParExchange("B0VP01LDU",3,&SignalBuffer[1498],"Давление в системы АЗ2 подано",1);
ParExchange("A0VN01LDU",3,&SignalBuffer[1508],"Каналы АЗ1 проверены",1);
ParExchange("B0VN01LDU",3,&SignalBuffer[1510],"Каналы АЗ2 проверены",1);
ParExchange("A0VS11LDU",3,&SignalBuffer[1528],"АЗ1 готова к работе",1);
ParExchange("B0VS11LDU",3,&SignalBuffer[1530],"АЗ2 готова к работе",1);
ParExchange("A3VC01RDU",1,&SignalBuffer[1590],"Координата ИС1, мм",1);
ParExchange("A2VC01RDU",1,&SignalBuffer[1595],"Координата РБ1, мм",1);
ParExchange("B2VC01RDU",1,&SignalBuffer[1600],"Координата РБ2, мм",1);
ParExchange("B8VC01RDU",1,&SignalBuffer[1605],"Координата АЗ2, мм",1);
ParExchange("R0EE02LDU",3,&SignalBuffer[1622],"Питание  АКНП  отключить",1);
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
NewEEPROM("fEM_A1UC03RDU",1,&fEM_A1UC03RDU,"Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера","0.0000976563");
NewEEPROM("dEM_A1UC05UDU",7,&dEM_A1UC05UDU,"Верхняя граница показания энкодера ББ, деления энкодера","1024200");
NewEEPROM("dEM_A1UC06UDU",7,&dEM_A1UC06UDU,"Нижняя граница показания энкодера ББ, деления энкодера","-200");
NewEEPROM("dEM_A2UC06UDU",7,&dEM_A2UC06UDU,"Нижняя граница показания энкодера РБ, деления энкодера","-200");
NewEEPROM("dEM_A2UC05UDU",7,&dEM_A2UC05UDU,"Верхняя граница показания энкодера РБ, деления энкодера","1024200");
NewEEPROM("fEM_A2UC03RDU",1,&fEM_A2UC03RDU,"Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера","0.0000976563");
NewEEPROM("dEM_A3UC06UDU",7,&dEM_A3UC06UDU,"Нижняя граница показания энкодера ИС, деления энкодера","-200");
NewEEPROM("dEM_A3UC05UDU",7,&dEM_A3UC05UDU,"Верхняя граница показания энкодера ИС, деления энкодера","1689599");
NewEEPROM("fEM_A3UC03RDU",1,&fEM_A3UC03RDU,"Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера","0.00009765625");
NewEEPROM("dEM_A8UC06UDU",7,&dEM_A8UC06UDU,"Нижняя граница показания энкодера АЗ2, деления энкодера","-200");
NewEEPROM("fEM_A8UC03RDU",1,&fEM_A8UC03RDU,"Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера","0.0009765625");
NewEEPROM("dEM_A8UC05UDU",7,&dEM_A8UC05UDU,"Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера","1536200");
NewEEPROM("fEM_R0UV81RDU",1,&fEM_R0UV81RDU,"1-я частота двигателя (шагов/секунду)","100");
NewEEPROM("fEM_R0UV82RDU",1,&fEM_R0UV82RDU,"3-я частота двигателя (шагов/секунду)","200");
NewEEPROM("fEM_R0UV83RDU",1,&fEM_R0UV83RDU,"4-я частота двигателя (шагов/секунду)","300");
NewEEPROM("fEM_R0UV84RDU",1,&fEM_R0UV84RDU,"5-я частота двигателя (шагов/секунду)","400");
NewEEPROM("fEM_R0UV86RDU",1,&fEM_R0UV86RDU,"7-я скорость перемещения ББ (шагов/секунду)","600");
NewEEPROM("fEM_R0UV85RDU",1,&fEM_R0UV85RDU,"6-я скорость перемещения ББ (шагов/секунду)","500");
NewEEPROM("fEM_R0UV87RDU",1,&fEM_R0UV87RDU,"7-я скорость перемещения ББ (шагов/секунду)","750");
NewEEPROM("fEM_A3UP03RDU",1,&fEM_A3UP03RDU,"Верхний предел шкалы датчика давления на подъем/сброс ИС","2.5");
NewEEPROM("fEM_A3UP04RDU",1,&fEM_A3UP04RDU,"Нижний предел шкалы датчика давления на подъем/сброс ИС","0");
NewEEPROM("fEM_A3UP43RDU",1,&fEM_A3UP43RDU,"Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС","0.46");
NewEEPROM("fEM_A3UP44RDU",1,&fEM_A3UP44RDU,"Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)","0.49");
NewEEPROM("fEM_A3UP53RDU",1,&fEM_A3UP53RDU,"Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)","0.52");
NewEEPROM("fEM_A3UP85RDU",1,&fEM_A3UP85RDU,"Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)","0.53");
NewEEPROM("fEM_A3UP88RDU",1,&fEM_A3UP88RDU,"Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)","0.67");
NewEEPROM("fEM_A3UP86RDU",1,&fEM_A3UP86RDU,"Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)","0.56");
NewEEPROM("fEM_B8UV01RDU",1,&fEM_B8UV01RDU,"Допустимое превышение заданной скорости АЗ2,ДС2 мм/с","4");
NewEEPROM("fEM_B8UV02RDU",1,&fEM_B8UV02RDU,"Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с","4");
NewEEPROM("fEM_B8UV03RDU",1,&fEM_B8UV03RDU,"Номинальная скорость перемещения АЗ2,ДС2 мм/с","10.91");
NewEEPROM("fEM_B8UL04RDU",1,&fEM_B8UL04RDU,"Задержка определения самохода АЗ-ДС после команды на останов, сек","3");
NewEEPROM("iEM_A2UV03CDU",2,&iEM_A2UV03CDU,"Скорость 1-го диапазона РБ назад (вниз)","4");
NewEEPROM("fEM_A2UV01RDU",1,&fEM_A2UV01RDU,"Допустимое превышение заданной скорости РБ мм/с","0.15");
NewEEPROM("fEM_A2UV02RDU",1,&fEM_A2UV02RDU,"Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек","0.15");
NewEEPROM("fEM_A1UV01RDU",1,&fEM_A1UV01RDU,"Допустимое превышение заданной скорости ББ мм/с","0.4");
NewEEPROM("fEM_A1UV02RDU",1,&fEM_A1UV02RDU,"Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек","0.4");
NewEEPROM("fEM_A1UC06RDU",1,&fEM_A1UC06RDU,"Уставка определения самохода ББ  мм","0.03");
NewEEPROM("fEM_A1UC05RDU",1,&fEM_A1UC05RDU,"Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм","0.04");
NewEEPROM("fEM_A1UL04RDU",1,&fEM_A1UL04RDU,"Задержка определения самохода ББ после команды на останов, сек","3");
NewEEPROM("fEM_A3UV01RDU",1,&fEM_A3UV01RDU,"Допустимое превышение заданной скорости ИС мм/с","0.3");
NewEEPROM("fEM_A3UV02RDU",1,&fEM_A3UV02RDU,"Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек","0.3");
NewEEPROM("fEM_A3UC06RDU",1,&fEM_A3UC06RDU,"Уставка определения самохода ИС1  мм","0.07");
NewEEPROM("fEM_A3UC05RDU",1,&fEM_A3UC05RDU,"Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм","0.04");
NewEEPROM("fEM_A3UL04RDU",1,&fEM_A3UL04RDU,"Задержка определения самохода ИС после команды на останов, сек","3");
NewEEPROM("fEM_A3UP54RDU",1,&fEM_A3UP54RDU,"Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)","0.55");
NewEEPROM("fEM_A3UP87RDU",1,&fEM_A3UP87RDU,"Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)","0.64");
NewEEPROM("fEM_R0UL05RDU",1,&fEM_R0UL05RDU,"Время срабатывания сброса от НУП ИС","0.180");
NewEEPROM("fEM_R0UL20RDU",1,&fEM_R0UL20RDU,"Предельное отклонение от времени задержки  сброса от II УР","0.025");
NewEEPROM("fEM_B8UV04RDU",1,&fEM_B8UV04RDU,"Время разгона механизма при переходе на новую скорость сек","0.1");
NewEEPROM("fEM_B8UC06RDU",1,&fEM_B8UC06RDU,"Уставка определения самохода АЗ-ДС,  мм","2");
NewEEPROM("fEM_B8UC05RDU",1,&fEM_B8UC05RDU,"Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм","0.3");
NewEEPROM("fEM_A2UL05RDU",1,&fEM_A2UL05RDU,"Время задержки блокировки РБ по недвижению сек","3");
NewEEPROM("fEM_A2UL03RDU",1,&fEM_A2UL03RDU,"Задержка определения самохода РБ после останова (достижения скорости 0), с","1.50");
NewEEPROM("fEM_A2UC06RDU",1,&fEM_A2UC06RDU,"Уставка определения самохода РБ  мм","0.04");
NewEEPROM("fEM_A2UC05RDU",1,&fEM_A2UC05RDU,"Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм","0.05");
NewEEPROM("fEM_A2UL04RDU",1,&fEM_A2UL04RDU,"Задержка определения самохода РБ после команды на останов, с","3");
NewEEPROM("fEM_A1UL03RDU",1,&fEM_A1UL03RDU,"Задержка определения самохода ББ после останова (достижения скорости 0), с","1.50");
NewEEPROM("fEM_A1UL05RDU",1,&fEM_A1UL05RDU,"Время задержки блокировки ББ по недвижению с","3");
NewEEPROM("fEM_A3UL03RDU",1,&fEM_A3UL03RDU,"Задержка определения самохода ИС после останова (достижения скорости 0), сек","1.50");
NewEEPROM("fEM_A3UL05RDU",1,&fEM_A3UL05RDU,"Время задержки блокировки ИС по недвижению сек","2");
NewEEPROM("fEM_A1UC08RDU",1,&fEM_A1UC08RDU,"Зона нечувствительности при наведении ББ  мм","0.004");
NewEEPROM("fEM_A3UC08RDU",1,&fEM_A3UC08RDU,"Зона нечувствительности при наведении ИС 0.01 мм","0.006");
NewEEPROM("fEM_A1UC07RDU",1,&fEM_A1UC07RDU,"Зона возврата при наведении ББ мм","0.006");
NewEEPROM("fEM_A1UL01RDU",1,&fEM_A1UL01RDU,"Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек","1.0");
NewEEPROM("fEM_A3UC07RDU",1,&fEM_A3UC07RDU,"Зона возврата при наведении ИС 0.01 мм","0.01");
NewEEPROM("fEM_A3UL01RDU",1,&fEM_A3UL01RDU,"Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек","1");
NewEEPROM("fEM_A2UC08RDU",1,&fEM_A2UC08RDU,"Зона нечувствительности при наведении РБ мм","0.008");
NewEEPROM("fEM_A2UC07RDU",1,&fEM_A2UC07RDU,"Зона возврата при наведении РБ  мм","0.01");
NewEEPROM("fEM_A2UL01RDU",1,&fEM_A2UL01RDU,"Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек","1");
NewEEPROM("fEM_B8UC01RDU",1,&fEM_B8UC01RDU,"Зона нечувствительности при наведении АЗ2,ДС2 мм","0.4");
NewEEPROM("fEM_B8UL07RDU",1,&fEM_B8UL07RDU,"Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек","120");
NewEEPROM("fEM_B8UC02RDU",1,&fEM_B8UC02RDU,"Зона возврата при наведении АЗ2,ДС2  мм","0.6");
NewEEPROM("fEM_B8UL01RDU",1,&fEM_B8UL01RDU,"Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек","1");
NewEEPROM("fEM_B8UL05RDU",1,&fEM_B8UL05RDU,"Время задержки сигнализации по недвижению АЗ2,ДС2 сек","2");
NewEEPROM("fEM_B8UL03RDU",1,&fEM_B8UL03RDU,"Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек","1.50");
NewEEPROM("fEM_B8UL06RDU",1,&fEM_B8UL06RDU,"Время задержки блокировки АЗ2,ДС2 по недвижению сек","2.0");
NewEEPROM("fEM_A9UZ03RDU",1,&fEM_A9UZ03RDU,"Время задержки блокировки НИ  ДС по самоходу сек","1");
NewEEPROM("fEM_A9UZ04RDU",1,&fEM_A9UZ04RDU,"Время задержки блокировки НИ ДС по превышению времени движения сек","15");
NewEEPROM("fEM_A9UZ05RDU",1,&fEM_A9UZ05RDU,"Время задержки блокировки НИ ДС по недвижению сек","0.50");
NewEEPROM("fEM_R4UZ04RDU",1,&fEM_R4UZ04RDU,"Время задержки блокировки тележки по превышению времени движения сек","360");
NewEEPROM("fEM_R4UZ03RDU",1,&fEM_R4UZ03RDU,"Время задержки блокировки тележки по самоходу сек","1");
NewEEPROM("fEM_R4UZ05RDU",1,&fEM_R4UZ05RDU,"Время задержки блокировки тележки по недвижению сек","2");
NewEEPROM("fEM_A5UZ03RDU",1,&fEM_A5UZ03RDU,"Время задержки блокировки НЛ по самоходу сек","1.0");
NewEEPROM("fEM_A5UZ04RDU",1,&fEM_A5UZ04RDU,"Время задержки блокировки НЛ по превышению времени движения сек","6.0");
NewEEPROM("fEM_A5UZ05RDU",1,&fEM_A5UZ05RDU,"Время задержки блокировки НЛ по недвижению сек","0.50");
NewEEPROM("fEM_A4UZ03RDU",1,&fEM_A4UZ03RDU,"Время задержки блокировки НИ по самоходу сек","1.0");
NewEEPROM("fEM_A4UZ04RDU",1,&fEM_A4UZ04RDU,"Время задержки блокировки НИ по превышению времени движения сек","16.0");
NewEEPROM("fEM_A4UZ05RDU",1,&fEM_A4UZ05RDU,"Время задержки блокировки НИ по недвижению сек","3.0");
NewEEPROM("fEM_A6UZ03RDU",1,&fEM_A6UZ03RDU,"Время задержки блокировки БЗ по самоходу сек","1.0");
NewEEPROM("fEM_A6UZ04RDU",1,&fEM_A6UZ04RDU,"Время задержки блокировки БЗ по превышению времени движения сек","60.0");
NewEEPROM("fEM_A6UZ05RDU",1,&fEM_A6UZ05RDU,"Время задержки блокировки БЗ по недвижению сек","0.50");
NewEEPROM("fEM_R1UZ03RDU",1,&fEM_R1UZ03RDU,"Время задержки блокировки МДЗ по самоходу сек","1.0");
NewEEPROM("fEM_R1UZ04RDU",1,&fEM_R1UZ04RDU,"Время задержки блокировки МДЗ по превышению времени движения сек","20.0");
NewEEPROM("fEM_R1UZ05RDU",1,&fEM_R1UZ05RDU,"Время задержки блокировки МДЗ по недвижению сек","0.50");
NewEEPROM("fEM_R0UL04RDU",1,&fEM_R0UL04RDU,"Предельное время ожидания срабатывания АЗ от НУП ИС","2.0");
NewEEPROM("fEM_R0UL06RDU",1,&fEM_R0UL06RDU,"Предельное время срабатывания верхней АС II УР","2.0");
NewEEPROM("fEM_R0UL03RDU",1,&fEM_R0UL03RDU,"Время срабатывания сброса от ВУ РБ","1.5");
NewEEPROM("fEM_R0UL17RDU",1,&fEM_R0UL17RDU,"Предельное отклонение от времени задержки  сброса от ВУ РБ","0.06");
NewEEPROM("fEM_R0UL19RDU",1,&fEM_R0UL19RDU,"Предельное отклонение от времени задержки  сброса от ВУ ИС","0.01");
NewEEPROM("fEM_R0UL07RDU",1,&fEM_R0UL07RDU,"Время срабатывания верхней АС II УР","0.045");
NewEEPROM("fEM_R0UL18RDU",1,&fEM_R0UL18RDU,"Предельное отклонение от времени задержки  сброса от НУП ИС","0.040");
NewEEPROM("fEM_R0UL16RDU",1,&fEM_R0UL16RDU,"Предельное отклонение от времени задержки  ИНИ","0.007");
NewEEPROM("fEM_R0UL02RDU",1,&fEM_R0UL02RDU,"Время задержки  ИНИ","0.014");
NewEEPROM("fEM_R0UN08RDU",1,&fEM_R0UN08RDU,"8-я заданная мощность","2000.0");
NewEEPROM("fEM_R0UN07RDU",1,&fEM_R0UN07RDU,"7-я заданная мощность","1500.0");
NewEEPROM("fEM_R0UN06RDU",1,&fEM_R0UN06RDU,"6-я заданная мощность","1000.0");
NewEEPROM("fEM_R0UN05RDU",1,&fEM_R0UN05RDU,"5-я заданная мощность","800.0");
NewEEPROM("fEM_R0UN04RDU",1,&fEM_R0UN04RDU,"4-я заданная мощность","500.0");
NewEEPROM("fEM_R0UN03RDU",1,&fEM_R0UN03RDU,"Ограничение 3 по мощности","200.0");
NewEEPROM("fEM_R0UN02RDU",1,&fEM_R0UN02RDU,"2-я заданная мощность","100.0");
NewEEPROM("fEM_R0UN01RDU",1,&fEM_R0UN01RDU,"1-я заданная мощность","0.001");
NewEEPROM("fEM_A2UC82RDU",1,&fEM_A2UC82RDU,"Граница 2-го диапазона РБ вперёд (вверх)","100");
NewEEPROM("fEM_A2UC83RDU",1,&fEM_A2UC83RDU,"Граница 1-го диапазона РБ назад (вниз)","100");
NewEEPROM("fEM_A1UC83RDU",1,&fEM_A1UC83RDU,"Граница 1-го диапазона ББ назад (вниз)","110.0");
NewEEPROM("fEM_A2UC81RDU",1,&fEM_A2UC81RDU,"Граница 1-го диапазона РБ вперёд (вверх)","20");
NewEEPROM("fEM_A1UC81RDU",1,&fEM_A1UC81RDU,"Граница 1-го диапазона ББ вперёд (вверх)","30.0");
NewEEPROM("fEM_A1UC82RDU",1,&fEM_A1UC82RDU,"Граница 2-го диапазона ББ вперёд (вверх)","100.0");
NewEEPROM("fEM_A2UL83RDU",1,&fEM_A2UL83RDU,"Задержка определения самохода РБ после останова (достижения скорости 0), с","1.50");
NewEEPROM("fEM_A3UC81RDU",1,&fEM_A3UC81RDU,"Граница 1-го диапазона ИС вперёд (вверх)","170");
NewEEPROM("fEM_A3UC82RDU",1,&fEM_A3UC82RDU,"Граница 1-го диапазона ИС назад (вниз)","170");
NewEEPROM("fEM_R0UN80RDU",1,&fEM_R0UN80RDU,"Ограничение по мощности в режиме калибровка и имульс","10");
NewEEPROM("iEM_A2UV01IDU",2,&iEM_A2UV01IDU,"Скорость 1-го диапазона РБ вперёд (вверх)","1");
NewEEPROM("iEM_A2UV02IDU",2,&iEM_A2UV02IDU,"Скорость 2-го диапазона РБ вперёд (вверх)","4");
NewEEPROM("iEM_A1UV01IDU",2,&iEM_A1UV01IDU,"Скорость 1-го диапазона ББ вперёд (вверх)","1");
NewEEPROM("iEM_A1UV02IDU",2,&iEM_A1UV02IDU,"Скорость 2-го диапазона ББ вперёд (вверх)","4");
NewEEPROM("iEM_A1UV03IDU",2,&iEM_A1UV03IDU,"Скорость1-го диапазона ББ назад (вниз)","4");
NewEEPROM("iEM_A3UV01IDU",2,&iEM_A3UV01IDU,"Скорость ИС для 1-го диапазона вперёд (вверх)","4");
NewEEPROM("iEM_A3UV02IDU",2,&iEM_A3UV02IDU,"Скорость ИС для 1-го диапазона назад (вниз)","4");
NewEEPROM("lEM_R0MD01LC1",3,&lEM_R0MD01LC1,"Ручное управление ОРР","0");
NewEEPROM("fEM_A3UC09RDU",1,&fEM_A3UC09RDU,"Координата переднего аварийного выключателя ИС мм","159.99");
NewEEPROM("fEM_A2UC02RDU",1,&fEM_A2UC02RDU,"Коэффициент преобразования частота-скорость(мм/сек)","0.002375");
NewEEPROM("fEM_A1UC02RDU",1,&fEM_A1UC02RDU,"Коэффициент преобразования частота-скорость(мм/сек) ББ","0.000877");
NewEEPROM("fEM_A3UC02RDU",1,&fEM_A3UC02RDU,"Коэффициент преобразования частота-скорость (мм/сек) ИС","0.001675");
NewEEPROM("fEM_R0UL21RDU",1,&fEM_R0UL21RDU,"Предельное время задержки  сброса от ВУ РБ","2.5");
NewEEPROM("fEM_R0UN09RDU",1,&fEM_R0UN09RDU,"Минимальный период при регулировании мощности","30");
NewEEPROM("fEM_R0UN11RDU",1,&fEM_R0UN11RDU,"Допустимое превышение заданной мощности  при регулировании","30");
NewEEPROM("fEM_R0UN12RDU",1,&fEM_R0UN12RDU,"Зона нечувствительности при регулировании мощности %","0.05");
NewEEPROM("fEM_R0UN13RDU",1,&fEM_R0UN13RDU,"Минимальное изменение координаты, мм","0.05");
NewEEPROM("fEM_R0UN14RDU",1,&fEM_R0UN14RDU,"Максимальная координата штока ИМ, мм","160.0");
NewEEPROM("fEM_R0UN16RDU",1,&fEM_R0UN16RDU,"Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью","-170.11");
NewEEPROM("fEM_R0UN17RDU",1,&fEM_R0UN17RDU,"Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью","76.25088");
NewEEPROM("fEM_R0UN18RDU",1,&fEM_R0UN18RDU,"Коэффициент t1 ф-ции температурной корректировки ИМ","0.271145");
NewEEPROM("fEM_R0UN19RDU",1,&fEM_R0UN19RDU,"Коэффициент t0 ф-ции температурной корректировки ИМ","24.93556615");
NewEEPROM("fEM_R0UN70LDU",1,&fEM_R0UN70LDU,"0 - Коэффициент реактивности функции опережения старта ИМ","0.1268");
NewEEPROM("fEM_R0UN71LDU",1,&fEM_R0UN71LDU,"1 - Коэффициент реактивности функции опережения старта ИМ","0.1567");
NewEEPROM("fEM_R0UN72LDU",1,&fEM_R0UN72LDU,"2 - Коэффициент реактивности функции опережения старта ИМ","0.1858");
NewEEPROM("fEM_R0UN73LDU",1,&fEM_R0UN73LDU,"3 - Коэффициент реактивности функции опережения старта ИМ","0.2066");
NewEEPROM("fEM_R0UN74LDU",1,&fEM_R0UN74LDU,"4 - Коэффициент реактивности функции опережения старта ИМ","0.2646");
NewEEPROM("fEM_R0UN75LDU",1,&fEM_R0UN75LDU,"5 - Коэффициент реактивности функции опережения старта ИМ","0.2995");
NewEEPROM("fEM_R0UN80LDU",1,&fEM_R0UN80LDU,"0 - Коэффициент  опережения старта ИМ","0.721275");
NewEEPROM("fEM_R0UN81LDU",1,&fEM_R0UN81LDU,"1 - Коэффициент  опережения старта ИМ","0.700575");
NewEEPROM("fEM_R0UN82LDU",1,&fEM_R0UN82LDU,"2 - Коэффициент  опережения старта ИМ","0.6681");
NewEEPROM("fEM_R0UN83LDU",1,&fEM_R0UN83LDU,"3 - Коэффициент  опережения старта ИМ","0.61515");
NewEEPROM("fEM_R0UN84LDU",1,&fEM_R0UN84LDU,"4 - Коэффициент  опережения старта ИМ","0.3885");
NewEEPROM("fEM_R0UN85LDU",1,&fEM_R0UN85LDU,"5 - Коэффициент  опережения старта ИМ","0.23325");
NewEEPROM("fEM_R0UT20RDU",1,&fEM_R0UT20RDU,"Предельное время работы на мощности более 100 Вт, сек","3600.0");
NewEEPROM("fEM_R0UN25RDU",1,&fEM_R0UN25RDU,"Коэффициент опережения для выхода с разгонной на 0-ю реактивность","0.935");
NewEEPROM("fEM_R0UN15RDU",1,&fEM_R0UN15RDU,"коэффициент рассогласования по координате для транспортной реактивности %","0.1");
NewEEPROM("fEM_R0UN26RDU",1,&fEM_R0UN26RDU,"Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности","0.006792308");
NewEEPROM("fEM_R0UN27RDU",1,&fEM_R0UN27RDU,"Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности","0.000418877");
NewEEPROM("fEM_R0UN24RDU",1,&fEM_R0UN24RDU,"Нижняя граница интервала мощности для измерения периода (ватт)","0.0015");
NewEEPROM("fEM_R0UL25RDU",1,&fEM_R0UL25RDU,"Предельное отклонение от времени задержки  сброса от ВУ ИС","0.30");
#else
if(EEPROMFlag) {
  fplet(&fEM_A1UC03RDU.f,((float*)(IntEEPROMBuffer+0x0)));
  fEM_A1UC03RDU.error = 0;
  dEM_A1UC05UDU.l = *((long*)(IntEEPROMBuffer+0x4));
  dEM_A1UC05UDU.error = 0;
  dEM_A1UC06UDU.l = *((long*)(IntEEPROMBuffer+0x8));
  dEM_A1UC06UDU.error = 0;
  dEM_A2UC06UDU.l = *((long*)(IntEEPROMBuffer+0xC));
  dEM_A2UC06UDU.error = 0;
  dEM_A2UC05UDU.l = *((long*)(IntEEPROMBuffer+0x10));
  dEM_A2UC05UDU.error = 0;
  fplet(&fEM_A2UC03RDU.f,((float*)(IntEEPROMBuffer+0x14)));
  fEM_A2UC03RDU.error = 0;
  dEM_A3UC06UDU.l = *((long*)(IntEEPROMBuffer+0x18));
  dEM_A3UC06UDU.error = 0;
  dEM_A3UC05UDU.l = *((long*)(IntEEPROMBuffer+0x1C));
  dEM_A3UC05UDU.error = 0;
  fplet(&fEM_A3UC03RDU.f,((float*)(IntEEPROMBuffer+0x20)));
  fEM_A3UC03RDU.error = 0;
  dEM_A8UC06UDU.l = *((long*)(IntEEPROMBuffer+0x24));
  dEM_A8UC06UDU.error = 0;
  fplet(&fEM_A8UC03RDU.f,((float*)(IntEEPROMBuffer+0x28)));
  fEM_A8UC03RDU.error = 0;
  dEM_A8UC05UDU.l = *((long*)(IntEEPROMBuffer+0x2C));
  dEM_A8UC05UDU.error = 0;
  fplet(&fEM_R0UV81RDU.f,((float*)(IntEEPROMBuffer+0x30)));
  fEM_R0UV81RDU.error = 0;
  fplet(&fEM_R0UV82RDU.f,((float*)(IntEEPROMBuffer+0x34)));
  fEM_R0UV82RDU.error = 0;
  fplet(&fEM_R0UV83RDU.f,((float*)(IntEEPROMBuffer+0x38)));
  fEM_R0UV83RDU.error = 0;
  fplet(&fEM_R0UV84RDU.f,((float*)(IntEEPROMBuffer+0x3C)));
  fEM_R0UV84RDU.error = 0;
  fplet(&fEM_R0UV86RDU.f,((float*)(IntEEPROMBuffer+0x40)));
  fEM_R0UV86RDU.error = 0;
  fplet(&fEM_R0UV85RDU.f,((float*)(IntEEPROMBuffer+0x44)));
  fEM_R0UV85RDU.error = 0;
  fplet(&fEM_R0UV87RDU.f,((float*)(IntEEPROMBuffer+0x48)));
  fEM_R0UV87RDU.error = 0;
  fplet(&fEM_A3UP03RDU.f,((float*)(IntEEPROMBuffer+0x4C)));
  fEM_A3UP03RDU.error = 0;
  fplet(&fEM_A3UP04RDU.f,((float*)(IntEEPROMBuffer+0x50)));
  fEM_A3UP04RDU.error = 0;
  fplet(&fEM_A3UP43RDU.f,((float*)(IntEEPROMBuffer+0x54)));
  fEM_A3UP43RDU.error = 0;
  fplet(&fEM_A3UP44RDU.f,((float*)(IntEEPROMBuffer+0x58)));
  fEM_A3UP44RDU.error = 0;
  fplet(&fEM_A3UP53RDU.f,((float*)(IntEEPROMBuffer+0x5C)));
  fEM_A3UP53RDU.error = 0;
  fplet(&fEM_A3UP85RDU.f,((float*)(IntEEPROMBuffer+0x60)));
  fEM_A3UP85RDU.error = 0;
  fplet(&fEM_A3UP88RDU.f,((float*)(IntEEPROMBuffer+0x64)));
  fEM_A3UP88RDU.error = 0;
  fplet(&fEM_A3UP86RDU.f,((float*)(IntEEPROMBuffer+0x68)));
  fEM_A3UP86RDU.error = 0;
  fplet(&fEM_B8UV01RDU.f,((float*)(IntEEPROMBuffer+0x6C)));
  fEM_B8UV01RDU.error = 0;
  fplet(&fEM_B8UV02RDU.f,((float*)(IntEEPROMBuffer+0x70)));
  fEM_B8UV02RDU.error = 0;
  fplet(&fEM_B8UV03RDU.f,((float*)(IntEEPROMBuffer+0x74)));
  fEM_B8UV03RDU.error = 0;
  fplet(&fEM_B8UL04RDU.f,((float*)(IntEEPROMBuffer+0x78)));
  fEM_B8UL04RDU.error = 0;
  iEM_A2UV03CDU.i = *((__int16*)(IntEEPROMBuffer+0x7C));
  iEM_A2UV03CDU.error = 0;
  fplet(&fEM_A2UV01RDU.f,((float*)(IntEEPROMBuffer+0x7E)));
  fEM_A2UV01RDU.error = 0;
  fplet(&fEM_A2UV02RDU.f,((float*)(IntEEPROMBuffer+0x82)));
  fEM_A2UV02RDU.error = 0;
  fplet(&fEM_A1UV01RDU.f,((float*)(IntEEPROMBuffer+0x86)));
  fEM_A1UV01RDU.error = 0;
  fplet(&fEM_A1UV02RDU.f,((float*)(IntEEPROMBuffer+0x8A)));
  fEM_A1UV02RDU.error = 0;
  fplet(&fEM_A1UC06RDU.f,((float*)(IntEEPROMBuffer+0x8E)));
  fEM_A1UC06RDU.error = 0;
  fplet(&fEM_A1UC05RDU.f,((float*)(IntEEPROMBuffer+0x92)));
  fEM_A1UC05RDU.error = 0;
  fplet(&fEM_A1UL04RDU.f,((float*)(IntEEPROMBuffer+0x96)));
  fEM_A1UL04RDU.error = 0;
  fplet(&fEM_A3UV01RDU.f,((float*)(IntEEPROMBuffer+0x9A)));
  fEM_A3UV01RDU.error = 0;
  fplet(&fEM_A3UV02RDU.f,((float*)(IntEEPROMBuffer+0x9E)));
  fEM_A3UV02RDU.error = 0;
  fplet(&fEM_A3UC06RDU.f,((float*)(IntEEPROMBuffer+0xA2)));
  fEM_A3UC06RDU.error = 0;
  fplet(&fEM_A3UC05RDU.f,((float*)(IntEEPROMBuffer+0xA6)));
  fEM_A3UC05RDU.error = 0;
  fplet(&fEM_A3UL04RDU.f,((float*)(IntEEPROMBuffer+0xAA)));
  fEM_A3UL04RDU.error = 0;
  fplet(&fEM_A3UP54RDU.f,((float*)(IntEEPROMBuffer+0xAE)));
  fEM_A3UP54RDU.error = 0;
  fplet(&fEM_A3UP87RDU.f,((float*)(IntEEPROMBuffer+0xB2)));
  fEM_A3UP87RDU.error = 0;
  fplet(&fEM_R0UL05RDU.f,((float*)(IntEEPROMBuffer+0xB6)));
  fEM_R0UL05RDU.error = 0;
  fplet(&fEM_R0UL20RDU.f,((float*)(IntEEPROMBuffer+0xBA)));
  fEM_R0UL20RDU.error = 0;
  fplet(&fEM_B8UV04RDU.f,((float*)(IntEEPROMBuffer+0xBE)));
  fEM_B8UV04RDU.error = 0;
  fplet(&fEM_B8UC06RDU.f,((float*)(IntEEPROMBuffer+0xC2)));
  fEM_B8UC06RDU.error = 0;
  fplet(&fEM_B8UC05RDU.f,((float*)(IntEEPROMBuffer+0xC6)));
  fEM_B8UC05RDU.error = 0;
  fplet(&fEM_A2UL05RDU.f,((float*)(IntEEPROMBuffer+0xCA)));
  fEM_A2UL05RDU.error = 0;
  fplet(&fEM_A2UL03RDU.f,((float*)(IntEEPROMBuffer+0xCE)));
  fEM_A2UL03RDU.error = 0;
  fplet(&fEM_A2UC06RDU.f,((float*)(IntEEPROMBuffer+0xD2)));
  fEM_A2UC06RDU.error = 0;
  fplet(&fEM_A2UC05RDU.f,((float*)(IntEEPROMBuffer+0xD6)));
  fEM_A2UC05RDU.error = 0;
  fplet(&fEM_A2UL04RDU.f,((float*)(IntEEPROMBuffer+0xDA)));
  fEM_A2UL04RDU.error = 0;
  fplet(&fEM_A1UL03RDU.f,((float*)(IntEEPROMBuffer+0xDE)));
  fEM_A1UL03RDU.error = 0;
  fplet(&fEM_A1UL05RDU.f,((float*)(IntEEPROMBuffer+0xE2)));
  fEM_A1UL05RDU.error = 0;
  fplet(&fEM_A3UL03RDU.f,((float*)(IntEEPROMBuffer+0xE6)));
  fEM_A3UL03RDU.error = 0;
  fplet(&fEM_A3UL05RDU.f,((float*)(IntEEPROMBuffer+0xEA)));
  fEM_A3UL05RDU.error = 0;
  fplet(&fEM_A1UC08RDU.f,((float*)(IntEEPROMBuffer+0xEE)));
  fEM_A1UC08RDU.error = 0;
  fplet(&fEM_A3UC08RDU.f,((float*)(IntEEPROMBuffer+0xF2)));
  fEM_A3UC08RDU.error = 0;
  fplet(&fEM_A1UC07RDU.f,((float*)(IntEEPROMBuffer+0xF6)));
  fEM_A1UC07RDU.error = 0;
  fplet(&fEM_A1UL01RDU.f,((float*)(IntEEPROMBuffer+0xFA)));
  fEM_A1UL01RDU.error = 0;
  fplet(&fEM_A3UC07RDU.f,((float*)(IntEEPROMBuffer+0xFE)));
  fEM_A3UC07RDU.error = 0;
  fplet(&fEM_A3UL01RDU.f,((float*)(IntEEPROMBuffer+0x102)));
  fEM_A3UL01RDU.error = 0;
  fplet(&fEM_A2UC08RDU.f,((float*)(IntEEPROMBuffer+0x106)));
  fEM_A2UC08RDU.error = 0;
  fplet(&fEM_A2UC07RDU.f,((float*)(IntEEPROMBuffer+0x10A)));
  fEM_A2UC07RDU.error = 0;
  fplet(&fEM_A2UL01RDU.f,((float*)(IntEEPROMBuffer+0x10E)));
  fEM_A2UL01RDU.error = 0;
  fplet(&fEM_B8UC01RDU.f,((float*)(IntEEPROMBuffer+0x112)));
  fEM_B8UC01RDU.error = 0;
  fplet(&fEM_B8UL07RDU.f,((float*)(IntEEPROMBuffer+0x116)));
  fEM_B8UL07RDU.error = 0;
  fplet(&fEM_B8UC02RDU.f,((float*)(IntEEPROMBuffer+0x11A)));
  fEM_B8UC02RDU.error = 0;
  fplet(&fEM_B8UL01RDU.f,((float*)(IntEEPROMBuffer+0x11E)));
  fEM_B8UL01RDU.error = 0;
  fplet(&fEM_B8UL05RDU.f,((float*)(IntEEPROMBuffer+0x122)));
  fEM_B8UL05RDU.error = 0;
  fplet(&fEM_B8UL03RDU.f,((float*)(IntEEPROMBuffer+0x126)));
  fEM_B8UL03RDU.error = 0;
  fplet(&fEM_B8UL06RDU.f,((float*)(IntEEPROMBuffer+0x12A)));
  fEM_B8UL06RDU.error = 0;
  fplet(&fEM_A9UZ03RDU.f,((float*)(IntEEPROMBuffer+0x12E)));
  fEM_A9UZ03RDU.error = 0;
  fplet(&fEM_A9UZ04RDU.f,((float*)(IntEEPROMBuffer+0x132)));
  fEM_A9UZ04RDU.error = 0;
  fplet(&fEM_A9UZ05RDU.f,((float*)(IntEEPROMBuffer+0x136)));
  fEM_A9UZ05RDU.error = 0;
  fplet(&fEM_R4UZ04RDU.f,((float*)(IntEEPROMBuffer+0x13A)));
  fEM_R4UZ04RDU.error = 0;
  fplet(&fEM_R4UZ03RDU.f,((float*)(IntEEPROMBuffer+0x13E)));
  fEM_R4UZ03RDU.error = 0;
  fplet(&fEM_R4UZ05RDU.f,((float*)(IntEEPROMBuffer+0x142)));
  fEM_R4UZ05RDU.error = 0;
  fplet(&fEM_A5UZ03RDU.f,((float*)(IntEEPROMBuffer+0x146)));
  fEM_A5UZ03RDU.error = 0;
  fplet(&fEM_A5UZ04RDU.f,((float*)(IntEEPROMBuffer+0x14A)));
  fEM_A5UZ04RDU.error = 0;
  fplet(&fEM_A5UZ05RDU.f,((float*)(IntEEPROMBuffer+0x14E)));
  fEM_A5UZ05RDU.error = 0;
  fplet(&fEM_A4UZ03RDU.f,((float*)(IntEEPROMBuffer+0x152)));
  fEM_A4UZ03RDU.error = 0;
  fplet(&fEM_A4UZ04RDU.f,((float*)(IntEEPROMBuffer+0x156)));
  fEM_A4UZ04RDU.error = 0;
  fplet(&fEM_A4UZ05RDU.f,((float*)(IntEEPROMBuffer+0x15A)));
  fEM_A4UZ05RDU.error = 0;
  fplet(&fEM_A6UZ03RDU.f,((float*)(IntEEPROMBuffer+0x15E)));
  fEM_A6UZ03RDU.error = 0;
  fplet(&fEM_A6UZ04RDU.f,((float*)(IntEEPROMBuffer+0x162)));
  fEM_A6UZ04RDU.error = 0;
  fplet(&fEM_A6UZ05RDU.f,((float*)(IntEEPROMBuffer+0x166)));
  fEM_A6UZ05RDU.error = 0;
  fplet(&fEM_R1UZ03RDU.f,((float*)(IntEEPROMBuffer+0x16A)));
  fEM_R1UZ03RDU.error = 0;
  fplet(&fEM_R1UZ04RDU.f,((float*)(IntEEPROMBuffer+0x16E)));
  fEM_R1UZ04RDU.error = 0;
  fplet(&fEM_R1UZ05RDU.f,((float*)(IntEEPROMBuffer+0x172)));
  fEM_R1UZ05RDU.error = 0;
  fplet(&fEM_R0UL04RDU.f,((float*)(IntEEPROMBuffer+0x176)));
  fEM_R0UL04RDU.error = 0;
  fplet(&fEM_R0UL06RDU.f,((float*)(IntEEPROMBuffer+0x17A)));
  fEM_R0UL06RDU.error = 0;
  fplet(&fEM_R0UL03RDU.f,((float*)(IntEEPROMBuffer+0x17E)));
  fEM_R0UL03RDU.error = 0;
  fplet(&fEM_R0UL17RDU.f,((float*)(IntEEPROMBuffer+0x182)));
  fEM_R0UL17RDU.error = 0;
  fplet(&fEM_R0UL19RDU.f,((float*)(IntEEPROMBuffer+0x186)));
  fEM_R0UL19RDU.error = 0;
  fplet(&fEM_R0UL07RDU.f,((float*)(IntEEPROMBuffer+0x18A)));
  fEM_R0UL07RDU.error = 0;
  fplet(&fEM_R0UL18RDU.f,((float*)(IntEEPROMBuffer+0x18E)));
  fEM_R0UL18RDU.error = 0;
  fplet(&fEM_R0UL16RDU.f,((float*)(IntEEPROMBuffer+0x192)));
  fEM_R0UL16RDU.error = 0;
  fplet(&fEM_R0UL02RDU.f,((float*)(IntEEPROMBuffer+0x196)));
  fEM_R0UL02RDU.error = 0;
  fplet(&fEM_R0UN08RDU.f,((float*)(IntEEPROMBuffer+0x19A)));
  fEM_R0UN08RDU.error = 0;
  fplet(&fEM_R0UN07RDU.f,((float*)(IntEEPROMBuffer+0x19E)));
  fEM_R0UN07RDU.error = 0;
  fplet(&fEM_R0UN06RDU.f,((float*)(IntEEPROMBuffer+0x1A2)));
  fEM_R0UN06RDU.error = 0;
  fplet(&fEM_R0UN05RDU.f,((float*)(IntEEPROMBuffer+0x1A6)));
  fEM_R0UN05RDU.error = 0;
  fplet(&fEM_R0UN04RDU.f,((float*)(IntEEPROMBuffer+0x1AA)));
  fEM_R0UN04RDU.error = 0;
  fplet(&fEM_R0UN03RDU.f,((float*)(IntEEPROMBuffer+0x1AE)));
  fEM_R0UN03RDU.error = 0;
  fplet(&fEM_R0UN02RDU.f,((float*)(IntEEPROMBuffer+0x1B2)));
  fEM_R0UN02RDU.error = 0;
  fplet(&fEM_R0UN01RDU.f,((float*)(IntEEPROMBuffer+0x1B6)));
  fEM_R0UN01RDU.error = 0;
  fplet(&fEM_A2UC82RDU.f,((float*)(IntEEPROMBuffer+0x1BA)));
  fEM_A2UC82RDU.error = 0;
  fplet(&fEM_A2UC83RDU.f,((float*)(IntEEPROMBuffer+0x1BE)));
  fEM_A2UC83RDU.error = 0;
  fplet(&fEM_A1UC83RDU.f,((float*)(IntEEPROMBuffer+0x1C2)));
  fEM_A1UC83RDU.error = 0;
  fplet(&fEM_A2UC81RDU.f,((float*)(IntEEPROMBuffer+0x1C6)));
  fEM_A2UC81RDU.error = 0;
  fplet(&fEM_A1UC81RDU.f,((float*)(IntEEPROMBuffer+0x1CA)));
  fEM_A1UC81RDU.error = 0;
  fplet(&fEM_A1UC82RDU.f,((float*)(IntEEPROMBuffer+0x1CE)));
  fEM_A1UC82RDU.error = 0;
  fplet(&fEM_A2UL83RDU.f,((float*)(IntEEPROMBuffer+0x1D2)));
  fEM_A2UL83RDU.error = 0;
  fplet(&fEM_A3UC81RDU.f,((float*)(IntEEPROMBuffer+0x1D6)));
  fEM_A3UC81RDU.error = 0;
  fplet(&fEM_A3UC82RDU.f,((float*)(IntEEPROMBuffer+0x1DA)));
  fEM_A3UC82RDU.error = 0;
  fplet(&fEM_R0UN80RDU.f,((float*)(IntEEPROMBuffer+0x1DE)));
  fEM_R0UN80RDU.error = 0;
  iEM_A2UV01IDU.i = *((__int16*)(IntEEPROMBuffer+0x1E2));
  iEM_A2UV01IDU.error = 0;
  iEM_A2UV02IDU.i = *((__int16*)(IntEEPROMBuffer+0x1E4));
  iEM_A2UV02IDU.error = 0;
  iEM_A1UV01IDU.i = *((__int16*)(IntEEPROMBuffer+0x1E6));
  iEM_A1UV01IDU.error = 0;
  iEM_A1UV02IDU.i = *((__int16*)(IntEEPROMBuffer+0x1E8));
  iEM_A1UV02IDU.error = 0;
  iEM_A1UV03IDU.i = *((__int16*)(IntEEPROMBuffer+0x1EA));
  iEM_A1UV03IDU.error = 0;
  iEM_A3UV01IDU.i = *((__int16*)(IntEEPROMBuffer+0x1EC));
  iEM_A3UV01IDU.error = 0;
  iEM_A3UV02IDU.i = *((__int16*)(IntEEPROMBuffer+0x1EE));
  iEM_A3UV02IDU.error = 0;
  lEM_R0MD01LC1.b = *((uspaint8*)(IntEEPROMBuffer+0x1F0));
  lEM_R0MD01LC1.error = 0;
  fplet(&fEM_A3UC09RDU.f,((float*)(IntEEPROMBuffer+0x1F1)));
  fEM_A3UC09RDU.error = 0;
  fplet(&fEM_A2UC02RDU.f,((float*)(IntEEPROMBuffer+0x1F5)));
  fEM_A2UC02RDU.error = 0;
  fplet(&fEM_A1UC02RDU.f,((float*)(IntEEPROMBuffer+0x1F9)));
  fEM_A1UC02RDU.error = 0;
  fplet(&fEM_A3UC02RDU.f,((float*)(IntEEPROMBuffer+0x1FD)));
  fEM_A3UC02RDU.error = 0;
  fplet(&fEM_R0UL21RDU.f,((float*)(IntEEPROMBuffer+0x201)));
  fEM_R0UL21RDU.error = 0;
  fplet(&fEM_R0UN09RDU.f,((float*)(IntEEPROMBuffer+0x205)));
  fEM_R0UN09RDU.error = 0;
  fplet(&fEM_R0UN11RDU.f,((float*)(IntEEPROMBuffer+0x209)));
  fEM_R0UN11RDU.error = 0;
  fplet(&fEM_R0UN12RDU.f,((float*)(IntEEPROMBuffer+0x20D)));
  fEM_R0UN12RDU.error = 0;
  fplet(&fEM_R0UN13RDU.f,((float*)(IntEEPROMBuffer+0x211)));
  fEM_R0UN13RDU.error = 0;
  fplet(&fEM_R0UN14RDU.f,((float*)(IntEEPROMBuffer+0x215)));
  fEM_R0UN14RDU.error = 0;
  fplet(&fEM_R0UN16RDU.f,((float*)(IntEEPROMBuffer+0x219)));
  fEM_R0UN16RDU.error = 0;
  fplet(&fEM_R0UN17RDU.f,((float*)(IntEEPROMBuffer+0x21D)));
  fEM_R0UN17RDU.error = 0;
  fplet(&fEM_R0UN18RDU.f,((float*)(IntEEPROMBuffer+0x221)));
  fEM_R0UN18RDU.error = 0;
  fplet(&fEM_R0UN19RDU.f,((float*)(IntEEPROMBuffer+0x225)));
  fEM_R0UN19RDU.error = 0;
  fplet(&fEM_R0UN70LDU.f,((float*)(IntEEPROMBuffer+0x229)));
  fEM_R0UN70LDU.error = 0;
  fplet(&fEM_R0UN71LDU.f,((float*)(IntEEPROMBuffer+0x22D)));
  fEM_R0UN71LDU.error = 0;
  fplet(&fEM_R0UN72LDU.f,((float*)(IntEEPROMBuffer+0x231)));
  fEM_R0UN72LDU.error = 0;
  fplet(&fEM_R0UN73LDU.f,((float*)(IntEEPROMBuffer+0x235)));
  fEM_R0UN73LDU.error = 0;
  fplet(&fEM_R0UN74LDU.f,((float*)(IntEEPROMBuffer+0x239)));
  fEM_R0UN74LDU.error = 0;
  fplet(&fEM_R0UN75LDU.f,((float*)(IntEEPROMBuffer+0x23D)));
  fEM_R0UN75LDU.error = 0;
  fplet(&fEM_R0UN80LDU.f,((float*)(IntEEPROMBuffer+0x241)));
  fEM_R0UN80LDU.error = 0;
  fplet(&fEM_R0UN81LDU.f,((float*)(IntEEPROMBuffer+0x245)));
  fEM_R0UN81LDU.error = 0;
  fplet(&fEM_R0UN82LDU.f,((float*)(IntEEPROMBuffer+0x249)));
  fEM_R0UN82LDU.error = 0;
  fplet(&fEM_R0UN83LDU.f,((float*)(IntEEPROMBuffer+0x24D)));
  fEM_R0UN83LDU.error = 0;
  fplet(&fEM_R0UN84LDU.f,((float*)(IntEEPROMBuffer+0x251)));
  fEM_R0UN84LDU.error = 0;
  fplet(&fEM_R0UN85LDU.f,((float*)(IntEEPROMBuffer+0x255)));
  fEM_R0UN85LDU.error = 0;
  fplet(&fEM_R0UT20RDU.f,((float*)(IntEEPROMBuffer+0x259)));
  fEM_R0UT20RDU.error = 0;
  fplet(&fEM_R0UN25RDU.f,((float*)(IntEEPROMBuffer+0x25D)));
  fEM_R0UN25RDU.error = 0;
  fplet(&fEM_R0UN15RDU.f,((float*)(IntEEPROMBuffer+0x261)));
  fEM_R0UN15RDU.error = 0;
  fplet(&fEM_R0UN26RDU.f,((float*)(IntEEPROMBuffer+0x265)));
  fEM_R0UN26RDU.error = 0;
  fplet(&fEM_R0UN27RDU.f,((float*)(IntEEPROMBuffer+0x269)));
  fEM_R0UN27RDU.error = 0;
  fplet(&fEM_R0UN24RDU.f,((float*)(IntEEPROMBuffer+0x26D)));
  fEM_R0UN24RDU.error = 0;
  fplet(&fEM_R0UL25RDU.f,((float*)(IntEEPROMBuffer+0x271)));
  fEM_R0UL25RDU.error = 0;
}
#endif
}

#ifndef SIMUL_MODE
unsigned int EndIntEEPROMAddress = 629;
#endif

void reInit_Signals(void)
{
  S_and4_106_2.x3 = &signal_B8IS11LDU;
  S_and4_106_2.x4 = &signal_B8IS12LDU;
  S_noto_251_2.x = &signal_B3VP81LDU;
  S_noto_250_2.x = &signal_B2VP82LDU;
  S_noto_249_2.x = &signal_B4VP82LDU;
  S_noto_231_2.x = &signal_A3VP81LDU;
  S_noto_230_2.x = &signal_A2VP82LDU;
  S_noto_229_2.x = &signal_A4VP82LDU;
  S_schl24_149_2.x1 = &signal_A0EE02LZ1;
  S_schl24_149_2.x2 = &signal_A0EE03LZ1;
  S_schl24_149_2.x3 = &signal_A0EE01LZ1;
  S_schl24_149_2.x4 = &signal_A0EE04LZ1;
  S_schl24_143_2.x1 = &signal_A0EE03LZ2;
  S_schl24_143_2.x2 = &signal_A0EE01LZ2;
  S_schl24_143_2.x3 = &signal_A0EE02LZ2;
  S_schl24_143_2.x4 = &signal_A0EE04LZ2;
  S_and4_159_2.x1 = &signal_A0EE02LZ1;
  S_and4_159_2.x2 = &signal_A0EE04LZ1;
  S_and4_159_2.x3 = &signal_A0EE02LZ2;
  S_and4_159_2.x4 = &signal_A0EE04LZ2;
  S_and4_136_2.x1 = &signal_A0EE03LZ1;
  S_and4_136_2.x2 = &signal_A0EE01LZ1;
  S_and4_136_2.x3 = &signal_A0EE01LZ2;
  S_and4_136_2.x4 = &signal_A0EE03LZ2;
  S_and3_110_2.x3 = &signal_A8IS12LDU;
  S_or2_104_2.x1 = &signal_A8MC01LC2;
  S_or2_104_2.x2 = &signal_A8MC01LC1;
  S_or2_103_2.x1 = &signal_B8MC01LC2;
  S_or2_103_2.x2 = &signal_B8MC01LC1;
  S_and3_79_2.x2 = &signal_B3IS11LDU;
  S_or2_71_2.x1 = &signal_B3MC01LC2;
  S_or2_71_2.x2 = &signal_B3MC01LC1;
  S_or2_74_2.x1 = &signal_A3MC01LC2;
  S_or2_74_2.x2 = &signal_A3MC01LC1;
  S_and3_82_2.x3 = &signal_A3IS11LDU;
  S_or2_43_2.x1 = &signal_A2MC01LC2;
  S_or2_43_2.x2 = &signal_A2MC01LC1;
  S_and3_49_2.x2 = &signal_A2IS11LDU;
  S_or2_13_2.x1 = &signal_A1MC01LC2;
  S_or2_13_2.x2 = &signal_A1MC01LC1;
  S_and3_23_2.x3 = &signal_A1IS11LDU;
  S_or2_42_2.x1 = &signal_B2MC01LC1;
  S_or2_42_2.x2 = &signal_B2MC01LC2;
  S_and3_45_2.x2 = &signal_B2IS11LDU;
  S_or2_11_2.x1 = &signal_B1MC01LC2;
  S_or2_11_2.x2 = &signal_B1MC01LC1;
  S_and3_19_2.x2 = &signal_B1IS11LDU;
  S_and2_254_2.x1 = &signal_syn_R0EE03LDU;
  S_and2_233_2.x1 = &signal_syn_R0EE03LDU;
  S_scalzz_187_2.x = &signal_B3IP02IDU;
  S_scalzz_185_2.x = &signal_A3IP02IDU;
  S_enctkb_16_2.Nk = &signal_A1IC01UDU;
  S_enctkb_108_2.Nk = &signal_B8IC01UDU;
  S_enctkb_112_2.Nk = &signal_A8IC01UDU;
  S_enctkb_75_2.Nk = &signal_B3IC01UDU;
  S_enctkb_77_2.Nk = &signal_A3IC01UDU;
  S_enctkb_47_2.Nk = &signal_B2IC01UDU;
  S_enctkb_51_2.Nk = &signal_A2IC01UDU;
  S_equz_p_18_2.x = &signal_R0MW12IP1;
  S_enctkb_21_2.Nk = &signal_B1IC01UDU;
  S_regch_124_1.reg = &signal_R0MW12IP1;
  S_or2_126_1.x1 = &signal_R0VZ71LZ1;
  S_or2_126_1.x2 = &signal_R0VZ71LZ2;
  S_and3_1384_1.x1 = &signal_R0MD11LP2;
  S_and2_722_1.x1 = &signal_R4MD21LP2;
  S_and2_719_1.x1 = &signal_R4MD11LP2;
  S_and2_104_1.x1 = &signal_R0MD11LP1;
  S_noto_2101_1.x = &signal_B3IS22LDU;
  S_noto_2127_1.x = &signal_A3IS22LDU;
  S_and3_2085_1.x3 = &signal_B3IS22LDU;
  S_and3_2111_1.x3 = &signal_A3IS22LDU;
  S_noto_2098_1.x = &signal_syn_B3VP52LDU;
  S_noto_2124_1.x = &signal_syn_A3VP52LDU;
  S_noto_1644_1.x = &signal_B2IS21LDU;
  S_noto_1638_1.x = &signal_A2IS21LDU;
  S_and2_2048_1.x1 = &signal_syn_B3VP52LDU;
  S_or5_2050_1.x5 = &signal_syn_A3VP52LDU;
  S_and2_2025_1.x1 = &signal_syn_A3VP52LDU;
  S_nocnm_1689_1.Pv = &signal_R5IS21LDU;
  S_nocnm_1689_1.Zv = &signal_R5IS11LDU;
  S_nocnm_1686_1.Pv = &signal_R3IS11LDU;
  S_nocnm_1686_1.Zv = &signal_R3IS21LDU;
  S_or5_1945_1.x3 = &signal_C2MD31LP1;
  S_or4_1921_1.x1 = &signal_C1MD31LP2;
  S_or4_1921_1.x2 = &signal_C1MD31LP1;
  S_and3_407_1.x1 = &signal_B8IS22LDU;
  S_and3_407_1.x2 = &signal_B8IS21LDU;
  S_or2_546_1.x1 = &signal_B1VP41LZ2;
  S_or2_546_1.x2 = &signal_B1VP41LZ1;
  S_or2_229_1.x1 = &signal_A1VP41LZ2;
  S_or2_229_1.x2 = &signal_A1VP41LZ1;
  S_or2_1108_1.x1 = &signal_B8IS22LDU;
  S_or2_1108_1.x2 = &signal_B8IS21LDU;
  S_or2_1103_1.x1 = &signal_B8IS11LDU;
  S_or2_1103_1.x2 = &signal_B8IS12LDU;
  S_or2_348_1.x1 = &signal_R4IS11LDU;
  S_or2_348_1.x2 = &signal_R4IS12LDU;
  S_or2_365_1.x1 = &signal_R4IS21LDU;
  S_or2_365_1.x2 = &signal_R4IS22LDU;
  S_or2_1062_1.x2 = &signal_R0MD34LP1;
  S_or2_1065_1.x2 = &signal_R0MD34LP1;
  S_or2_1068_1.x2 = &signal_R0MD34LP1;
  S_or2_1071_1.x2 = &signal_R0MD34LP1;
  S_and2_2178_1.x2 = &signal_R0MW17LP1;
  S_rs_2182_1.s = &signal_R0MW17LP1;
  S_abs_subf_2202_1.x1 = &signal_B3MC01RP1;
  S_abs_subf_2202_1.x2 = &signal_A3MC01RP1;
  S_irm_2141_1.kz = &signal_B3MC01RP1;
  S_ml_1506_1.x2 = &signal_B8MC01RP2;
  S_bol_1517_1.x1 = &signal_B8MC01RP2;
  S_bol_1523_1.x2 = &signal_B8MC01RP2;
  S_ml_1527_1.x2 = &signal_B3MC01RP1;
  S_bol_1530_1.x1 = &signal_B3MC01RP1;
  S_bol_1538_1.x2 = &signal_B3MC01RP1;
  S_ml_1505_1.x2 = &signal_A3MC01RP1;
  S_bol_1511_1.x1 = &signal_A3MC01RP1;
  S_bol_1518_1.x2 = &signal_A3MC01RP1;
  S_ml_1525_1.x2 = &signal_B1MC01RP1;
  S_bol_1529_1.x1 = &signal_B1MC01RP1;
  S_bol_1537_1.x2 = &signal_B1MC01RP1;
  S_ml_1503_1.x2 = &signal_A1MC01RP1;
  S_bol_1510_1.x1 = &signal_A1MC01RP1;
  S_bol_1522_1.x2 = &signal_A1MC01RP1;
  S_and2_1811_1.x2 = &signal_B7AS31LDU;
  S_ovbs_1405_1.x = &signal_R0MD31LP1;
  S_ovbs_112_1.x = &signal_R0MD31LP1;
  S_ovbs_119_1.x = &signal_R0MD32LP1;
  S_ovbs_76_1.x = &signal_R0MW13LP2;
  S_or2_233_1.x1 = &signal_A1VN71LZ1;
  S_or2_233_1.x2 = &signal_A1VN71LZ2;
  S_or5_147_1.x1 = &signal_B1IS21LDU;
  S_or5_147_1.x2 = &signal_B3IS21LDU;
  S_or5_147_1.x3 = &signal_B2IS21LDU;
  S_ma_1446_1.r = &signal_R0MW12IP2;
  S_and4_1870_1.x3 = &signal_B2IS12LDU;
  S_and4_1869_1.x2 = &signal_A2IS12LDU;
  S_and2_1894_1.x2 = &signal_A2IS12LDU;
  S_and2_1911_1.x2 = &signal_B2IS12LDU;
  S_and2_1810_1.x2 = &signal_A7AS31LDU;
  S_or2_1797_1.x1 = &signal_B0VT71LZ1;
  S_or2_1797_1.x2 = &signal_B0VT71LZ2;
  S_or2_1781_1.x1 = &signal_A0VT71LZ1;
  S_or2_1781_1.x2 = &signal_A0VT71LZ2;
  S_or2_1806_1.x1 = &signal_R0VP73LZ2;
  S_or2_1806_1.x2 = &signal_R0VP73LZ1;
  S_or2_1551_1.x1 = &signal_B4IS11LDU;
  S_or2_1551_1.x2 = &signal_A4IS11LDU;
  S_and2_1541_1.x1 = &signal_R3IS21LDU;
  S_or2_2063_1.x2 = &signal_R0MD34LP1;
  S_or3_1492_1.x1 = &signal_A3VZ13LZ2;
  S_or3_1492_1.x2 = &signal_A3VZ13LZ1;
  S_or3_1487_1.x1 = &signal_R0AD14LZ1;
  S_or3_1487_1.x2 = &signal_R0AD14LZ2;
  S_or3_1431_1.x1 = &signal_A3VZ15LZ1;
  S_or3_1431_1.x2 = &signal_A3VZ15LZ2;
  S_or5_1380_1.x5 = &signal_R0MD34LP1;
  S_or4_989_1.x1 = &signal_R0MD31LP1;
  S_or2_1225_1.x1 = &signal_A2MD12LP1;
  S_and2_1213_1.x1 = &signal_A2MD11LP1;
  S_or2_1206_1.x2 = &signal_B2MD12LP1;
  S_and2_1200_1.x1 = &signal_B2MD11LP1;
  S_and2_1238_1.x1 = &signal_R3IS21LDU;
  S_or2_1241_1.x1 = &signal_A4IS11LDU;
  S_or2_1241_1.x2 = &signal_B4IS11LDU;
  S_or2_1323_1.x2 = &signal_B3MD12LP1;
  S_and2_1312_1.x1 = &signal_B3MD11LP1;
  S_or2_1333_1.x1 = &signal_B4IS11LDU;
  S_or2_1333_1.x2 = &signal_A4IS11LDU;
  S_and2_1329_1.x1 = &signal_R3IS21LDU;
  S_or2_934_1.x1 = &signal_B4IS11LDU;
  S_or2_934_1.x2 = &signal_A4IS11LDU;
  S_and2_932_1.x1 = &signal_R3IS21LDU;
  S_or2_926_1.x2 = &signal_A3MD12LP1;
  S_and2_915_1.x1 = &signal_A3MD11LP1;
  S_and2_836_1.x1 = &signal_R3IS21LDU;
  S_or2_840_1.x1 = &signal_B4IS11LDU;
  S_or2_840_1.x2 = &signal_A4IS11LDU;
  S_or2_209_1.x1 = &signal_B4IS11LDU;
  S_or2_209_1.x2 = &signal_A4IS11LDU;
  S_and2_207_1.x1 = &signal_R3IS21LDU;
  S_and2_175_1.x1 = &signal_A1MD11LP1;
  S_or2_181_1.x1 = &signal_A1MD12LP1;
  S_or2_526_1.x1 = &signal_B4IS11LDU;
  S_or2_526_1.x2 = &signal_A4IS11LDU;
  S_or2_503_1.x1 = &signal_B1MD12LP1;
  S_and2_496_1.x1 = &signal_B1MD11LP1;
  S_and2_524_1.x2 = &signal_R3IS21LDU;
  S_and3_440_1.x3 = &signal_R0MD33LP1;
  S_and3_441_1.x3 = &signal_R0MD33LP1;
  S_or2_345_1.x1 = &signal_B4IS21LDU;
  S_or2_345_1.x2 = &signal_A4IS21LDU;
  S_or2_340_1.x1 = &signal_A2IS21LDU;
  S_or2_340_1.x2 = &signal_B2IS21LDU;
  S_or4_331_1.x3 = &signal_R0MD31LP1;
  S_or2_322_1.x1 = &signal_R0MD34LP1;
  S_and3_596_1.x3 = &signal_B2IS12LDU;
  S_or2_638_1.x1 = &signal_A2IS12LDU;
  S_or2_638_1.x2 = &signal_B2IS12LDU;
  S_and3_606_1.x1 = &signal_A2IS12LDU;
  S_and2_634_1.x2 = &signal_R0MD33LP1;
  S_and4_603_1.x4 = &signal_A2IS12LDU;
  S_and4_593_1.x4 = &signal_B2IS12LDU;
  S_or2_262_1.x1 = &signal_R0MD34LP1;
  S_or4_279_1.x2 = &signal_R0MD31LP1;
  S_and3_258_1.x1 = &signal_R0MD33LP1;
  S_or2_1087_1.x1 = &signal_B4IS11LDU;
  S_or2_1087_1.x2 = &signal_A4IS11LDU;
  S_and2_1078_1.x2 = &signal_R3IS21LDU;
  S_or2_1058_1.x1 = &signal_R0MD31LP1;
  S_or2_1166_1.x2 = &signal_R0MD34LP1;
  S_or2_658_1.x1 = &signal_B5IS11LDU;
  S_or2_658_1.x2 = &signal_A5IS11LDU;
  S_or2_656_1.x1 = &signal_B6IS11LDU;
  S_or2_656_1.x2 = &signal_A6IS11LDU;
  S_or2_654_1.x1 = &signal_A4IS11LDU;
  S_or2_654_1.x2 = &signal_B4IS11LDU;
  S_or3_720_1.x1 = &signal_R4MD31LP2;
  S_and2_702_1.x1 = &signal_R5IS11LDU;
  S_and3_700_1.x2 = &signal_R3IS21LDU;
  S_and2_701_1.x1 = &signal_R6IS21LDU;
  S_or2_699_1.x1 = &signal_B8IS22LDU;
  S_or2_699_1.x2 = &signal_A8IS22LDU;
  S_or4_686_1.x1 = &signal_A0VN71LZ1;
  S_or4_686_1.x2 = &signal_B0VN71LZ1;
  S_or4_686_1.x3 = &signal_B0VN71LZ2;
  S_or4_686_1.x4 = &signal_A0VN71LZ2;
  S_or3_672_1.x1 = &signal_R0NE01LDU;
  S_or3_672_1.x2 = &signal_R0NE02LDU;
  S_or3_672_1.x3 = &signal_R0NE08LDU;
  S_or2_684_1.x1 = &signal_R1IS21LDU;
  S_or2_684_1.x2 = &signal_R2IS21LDU;
  S_or2_48_1.x1 = &signal_A4IS21LDU;
  S_or2_48_1.x2 = &signal_B4IS21LDU;
  S_and2_406_1.x1 = &signal_A8IS22LDU;
  S_and2_426_1.x1 = &signal_B8IS22LDU;
  S_and2_425_1.x1 = &signal_A8IS22LDU;
  S_and2_424_1.x1 = &signal_R5IS11LDU;
  S_and2_405_1.x1 = &signal_R5IS11LDU;
  S_ma_83_1.r = &signal_R0MW15IP1;
  S_noto_1908_1.x = &signal_B2IS11LDU;
  S_noto_1906_1.x = &signal_A2IS11LDU;
  S_noto_1915_1.x = &signal_B2IS11LDU;
  S_noto_1890_1.x = &signal_A2IS11LDU;
  S_noto_984_1.x = &signal_R2IS21LDU;
  S_noto_978_1.x = &signal_R1IS21LDU;
  S_noto_265_1.x = &signal_R0MD33LP1;
  S_noto_275_1.x = &signal_R2IS21LDU;
  S_noto_269_1.x = &signal_R1IS21LDU;
  S_noto_260_1.x = &signal_R1IS11LDU;
  S_noto_257_1.x = &signal_R2IS11LDU;
  S_provsbr_1389_1.kvit = &signal_R0MD34LP1;
  S_noto_579_1.x = &signal_A2IS21LDU;
  S_noto_581_1.x = &signal_B2IS21LDU;
  S_noto_25_1.x = &signal_B2IS21LDU;
  S_noto_24_1.x = &signal_B1IS21LDU;
  S_noto_23_1.x = &signal_A1IS21LDU;
  S_noto_22_1.x = &signal_A2IS21LDU;
  S_newstage_591_1.fin1 = &signal_A2IS12LDU;
  S_newstage_591_1.fin2 = &signal_B2IS12LDU;
  S_noto_580_1.x = &signal_B2IS12LDU;
  S_noto_578_1.x = &signal_A2IS12LDU;
  S_noto_1318_1.x = &signal_B3MD12LP1;
  S_noto_1791_1.x = &signal_B3IS11LDU;
  S_noto_1765_1.x = &signal_A3IS11LDU;
  S_noto_1805_1.x = &signal_B3IS22LDU;
  S_noto_1785_1.x = &signal_A3IS22LDU;
  S_noto_1217_1.x = &signal_A2MD12LP1;
  S_noto_1202_1.x = &signal_B2MD12LP1;
  S_noto_501_1.x = &signal_B1MD12LP1;
  S_equz_p_1771_1.x = &signal_R0MW14IP2;
  S_equz_p_1770_1.x = &signal_R0MW14IP2;
  S_equz_p_1769_1.x = &signal_R0MW14IP2;
  S_equz_p_1767_1.x = &signal_R0MW14IP2;
  S_equz_p_1768_1.x = &signal_R0MW14IP2;
  S_noto_1824_1.x = &signal_B3IS11LDU;
  S_noto_1819_1.x = &signal_A3IS11LDU;
  S_noto_1861_1.x = &signal_B2IS11LDU;
  S_noto_1868_1.x = &signal_A2IS11LDU;
  S_equz_p_98_1.x = &signal_R0MW16IP1;
  S_noto_177_1.x = &signal_A1MD12LP1;
  S_equz_p_97_1.x = &signal_R0MW16IP1;
  S_equz_p_96_1.x = &signal_R0MW16IP1;
  S_noto_921_1.x = &signal_A3MD12LP1;
  S_equz_p_95_1.x = &signal_R0MW16IP1;
  S_equz_p_94_1.x = &signal_R0MW16IP1;
  S_equz_p_93_1.x = &signal_R0MW16IP1;
  S_noto_1728_1.x = &signal_B3IS22LDU;
  S_noto_1727_1.x = &signal_A3IS22LDU;
  S_noto_1726_1.x = &signal_B2IS12LDU;
  S_noto_1725_1.x = &signal_A2IS12LDU;
  S_noto_1724_1.x = &signal_B1IS12LDU;
  S_noto_1723_1.x = &signal_A1IS12LDU;
  S_noto_1753_1.x = &signal_B3IS21LDU;
  S_noto_1747_1.x = &signal_B2IS21LDU;
  S_noto_1752_1.x = &signal_A3IS21LDU;
  S_noto_1750_1.x = &signal_B4IS21LDU;
  S_noto_1751_1.x = &signal_A4IS21LDU;
  S_noto_1745_1.x = &signal_B1IS21LDU;
  S_noto_1746_1.x = &signal_A2IS21LDU;
  S_noto_1744_1.x = &signal_A1IS21LDU;
  S_samhd_2067_1.Pkv = &signal_B9IS11LDU;
  S_samhd_2067_1.Pkav = &signal_B9IS11LDU;
  S_samhd_2067_1.Zkv = &signal_B9IS21LDU;
  S_samhd_2067_1.Zkav = &signal_B9IS21LDU;
  S_samhd_2061_1.Pkv = &signal_A9IS11LDU;
  S_samhd_2061_1.Pkav = &signal_A9IS11LDU;
  S_samhd_2061_1.Zkv = &signal_A9IS21LDU;
  S_samhd_2061_1.Zkav = &signal_A9IS21LDU;
  S_maz_302_1.r = &signal_R0MW12IP1;
  S_maz_293_1.r = &signal_R0MW12IP1;
  S_equz_p_37_1.x = &signal_R0MW13IP1;
  S_equz_p_41_1.x = &signal_R0MW13IP1;
  S_equz_p_32_1.x = &signal_R0MW13IP1;
  S_noto_1341_1.x = &signal_R8IS11LDU;
  S_cnshd_1288_1.KvitSam = &signal_R0MD34LP1;
  S_fnapb_1316_1.KvitSam = &signal_R0MD34LP1;
  S_noto_944_1.x = &signal_R8IS11LDU;
  S_cnshd_886_1.KvitSam = &signal_R0MD34LP1;
  S_fnapb_919_1.KvitSam = &signal_R0MD34LP1;
  S_noto_534_1.x = &signal_R8IS11LDU;
  S_cnshd_488_1.KvitSam = &signal_R0MD34LP1;
  S_fnapb_515_1.KvitSam = &signal_R0MD34LP1;
  S_noto_635_1.x = &signal_R0MD33LP1;
  S_noto_217_1.x = &signal_R8IS11LDU;
  S_cnshd_167_1.KvitSam = &signal_R0MD34LP1;
  S_fnapb_196_1.KvitSam = &signal_R0MD34LP1;
  S_samhd_459_1.KvitSam = &signal_R0MD34LP1;
  S_samhd_459_1.FDvUp = &signal_R2VS12LDU;
  S_samhd_459_1.FDvDw = &signal_R2VS22LDU;
  S_samhd_459_1.Pkv = &signal_R2IS11LDU;
  S_samhd_459_1.Pkav = &signal_R2IS11LDU;
  S_samhd_459_1.Zkv = &signal_R2IS21LDU;
  S_samhd_459_1.Zkav = &signal_R2IS21LDU;
  S_samhd_453_1.KvitSam = &signal_R0MD34LP1;
  S_samhd_453_1.FDvUp = &signal_R1VS12LDU;
  S_samhd_453_1.FDvDw = &signal_R1VS22LDU;
  S_samhd_453_1.Pkv = &signal_R1IS11LDU;
  S_samhd_453_1.Pkav = &signal_R1IS11LDU;
  S_samhd_453_1.Zkv = &signal_R1IS21LDU;
  S_samhd_453_1.Zkav = &signal_R1IS21LDU;
  S_noto_849_1.x = &signal_R8IS11LDU;
  S_cnshd_806_1.KvitSam = &signal_R0MD34LP1;
  S_fnapb_826_1.KvitSam = &signal_R0MD34LP1;
  S_cnshd_1570_1.KvitSam = &signal_R0MD34LP1;
  S_cnshd_1109_1.KvitSam = &signal_R0MD34LP1;
  S_noto_1251_1.x = &signal_R8IS11LDU;
  S_cnshd_1191_1.KvitSam = &signal_R0MD34LP1;
  S_fnapb_1226_1.KvitSam = &signal_R0MD34LP1;
  S_noto_1555_1.x = &signal_R8IS11LDU;
  S_samhd_1573_1.KvitSam = &signal_R0MD34LP1;
  S_samhd_1573_1.Pkv = &signal_A8IS12LDU;
  S_samhd_1573_1.Pkav = &signal_A8IS12LDU;
  S_samhd_1573_1.Zkv = &signal_A8IS22LDU;
  S_samhd_1573_1.Zkav = &signal_A8IS22LDU;
  S_fnapb_1590_1.KvitSam = &signal_R0MD34LP1;
  S_noto_1091_1.x = &signal_R8IS11LDU;
  S_samhd_1113_1.KvitSam = &signal_R0MD34LP1;
  S_fnapb_1130_1.KvitSam = &signal_R0MD34LP1;
  S_noto_712_1.x = &signal_A5IS21LDU;
  S_noto_415_1.x = &signal_R8IS11LDU;
  S_noto_153_1.x = &signal_B2IS12LDU;
  S_noto_142_1.x = &signal_A2IS12LDU;
  S_noto_143_1.x = &signal_B1IS12LDU;
  S_noto_151_1.x = &signal_A1IS12LDU;
  S_samhd_1167_1.Pkv = &signal_B4IS11LDU;
  S_samhd_1167_1.Pkav = &signal_B4IS11LDU;
  S_samhd_1167_1.Zkv = &signal_B4IS21LDU;
  S_samhd_1167_1.Zkav = &signal_B4IS21LDU;
  S_samhd_1157_1.Pkv = &signal_A4IS11LDU;
  S_samhd_1157_1.Pkav = &signal_A4IS11LDU;
  S_samhd_1157_1.Zkv = &signal_A4IS21LDU;
  S_samhd_1157_1.Zkav = &signal_A4IS21LDU;
  S_samhd_780_1.KvitSam = &signal_R0MD34LP1;
  S_samhd_780_1.FDvUp = &signal_B5VS12LDU;
  S_samhd_780_1.FDvDw = &signal_B5VS22LDU;
  S_samhd_780_1.Pkv = &signal_B5IS11LDU;
  S_samhd_780_1.Pkav = &signal_B5IS11LDU;
  S_samhd_780_1.Zkv = &signal_B5IS21LDU;
  S_samhd_780_1.Zkav = &signal_B5IS21LDU;
  S_samhd_776_1.KvitSam = &signal_R0MD34LP1;
  S_samhd_776_1.FDvUp = &signal_A5VS12LDU;
  S_samhd_776_1.FDvDw = &signal_A5VS22LDU;
  S_samhd_776_1.Pkv = &signal_A5IS11LDU;
  S_samhd_776_1.Pkav = &signal_A5IS11LDU;
  S_samhd_776_1.Zkv = &signal_A5IS21LDU;
  S_samhd_776_1.Zkav = &signal_A5IS21LDU;
  S_samhd_358_1.KvitSam = &signal_R0MD34LP1;
  S_samhd_358_1.FDvUp = &signal_R4VS12LDU;
  S_samhd_358_1.FDvDw = &signal_R4VS22LDU;
  S_samhd_358_1.Pkv = &signal_R4IS11LDU;
  S_samhd_358_1.Pkav = &signal_R4IS12LDU;
  S_samhd_358_1.Zkv = &signal_R4IS21LDU;
  S_samhd_358_1.Zkav = &signal_R4IS22LDU;
  S_noto_670_1.x = &signal_R8IS11LDU;
  S_samhd_387_1.KvitSam = &signal_R0MD34LP1;
  S_samhd_387_1.FDvUp = &signal_B6VS12LDU;
  S_samhd_387_1.FDvDw = &signal_B6VS22LDU;
  S_samhd_387_1.Pkv = &signal_B6IS11LDU;
  S_samhd_387_1.Pkav = &signal_B6IS11LDU;
  S_samhd_387_1.Zkv = &signal_B6IS21LDU;
  S_samhd_387_1.Zkav = &signal_B6IS21LDU;
  S_samhd_381_1.KvitSam = &signal_R0MD34LP1;
  S_samhd_381_1.FDvUp = &signal_A6VS12LDU;
  S_samhd_381_1.FDvDw = &signal_A6VS22LDU;
  S_samhd_381_1.Pkv = &signal_A6IS11LDU;
  S_samhd_381_1.Pkav = &signal_A6IS11LDU;
  S_samhd_381_1.Zkv = &signal_A6IS21LDU;
  S_samhd_381_1.Zkav = &signal_A6IS21LDU;
  S_equz_p_74_1.x = &signal_R0MW11IP2;
  S_equz_p_72_1.x = &signal_R0MW11IP2;
  S_equz_p_70_1.x = &signal_R0MW11IP2;
  S_equz_p_69_1.x = &signal_R0MW11IP2;
  S_equz_p_68_1.x = &signal_R0MW11IP2;
  S_equz_p_65_1.x = &signal_R0MW11IP2;
  S_equz_p_61_1.x = &signal_R0MW14IP1;
  S_equz_p_55_1.x = &signal_R0MW14IP1;
  S_equz_p_57_1.x = &signal_R0MW14IP1;
  S_equz_p_50_1.x = &signal_R0MW11IP1;
  S_equz_p_43_1.x = &signal_R0MW11IP1;
  S_equz_p_46_1.x = &signal_R0MW11IP1;
  S_equz_p_99_1.x = &signal_R0MW16IP1;
  S_equz_p_92_1.x = &signal_R0MW16IP1;
  S_equz_p_91_1.x = &signal_R0MW16IP1;
  S_equz_p_90_1.x = &signal_R0MW16IP1;
  S_equz_p_10_1.x = &signal_R0MW12IP1;
  S_equz_p_7_1.x = &signal_R0MW12IP1;
  S_equz_p_2_1.x = &signal_R0MW12IP1;
  S_equz_p_4_1.x = &signal_R0MW12IP1;
  array_m170_x_2[0] = &signal_R0IE02LDU;
  array_m170_x_2[1] = &signal_R0IE01LDU;
  array_m170_x_2[2] = &signal_A8IE01LDU;
  array_m170_x_2[3] = &signal_B6IE01LDU;
  array_m170_x_2[4] = &signal_R1IE01LDU;
  array_m170_x_2[5] = &signal_R2IE01LDU;
  array_m170_x_2[6] = &signal_A5IE02LDU;
  array_m170_x_2[7] = &signal_B5IE01LDU;
  array_m170_x_2[8] = &signal_A6IE01LDU;
  array_m170_x_2[9] = &signal_R6IS62LDU;
  array_m170_x_2[10] = &signal_R6IS63LDU;
  array_m170_x_2[11] = &signal_R6IS64LDU;
  array_m170_x_2[12] = &signal_R6IS65LDU;
  array_m170_x_2[13] = &signal_R6IS61LDU;
  array_m170_x_2[14] = &signal_R6IS68LZZ;
  array_m170_x_2[15] = &signal_R6IS67LZZ;
  array_m170_x_2[16] = &signal_R6IS66LZZ;
  array_m150_x_2[0] = &signal_B3IE02LDU;
  array_m150_x_2[1] = &signal_B1IE02LDU;
  array_m150_x_2[2] = &signal_B2IE01LDU;
  array_m150_x_2[3] = &signal_B1IE01LDU;
  array_m150_x_2[4] = &signal_B3IE01LDU;
  array_m150_x_2[5] = &signal_B2IE02LDU;
  array_m131_x_2[0] = &signal_A1IE02LDU;
  array_m131_x_2[1] = &signal_A2IE02LDU;
  array_m131_x_2[2] = &signal_A1IE01LDU;
  array_m131_x_2[3] = &signal_A2IE01LDU;
  array_m131_x_2[4] = &signal_A3IE01LDU;
  array_m131_x_2[5] = &signal_A3IE02LDU;
  array_m242_x_2[3] = &signal_B0VT71LZ1;
  array_m242_x_2[4] = &signal_B0VT71LZ2;
  array_m232_x_2[3] = &signal_A0VT71LZ1;
  array_m232_x_2[4] = &signal_A0VT71LZ2;
  array_m255_x_2[1] = &signal_B0VP71LZ1;
  array_m255_x_2[2] = &signal_B0VP71LZ2;
  array_m234_x_2[1] = &signal_A0VP71LZ1;
  array_m234_x_2[2] = &signal_A0VP71LZ2;
  array_m2170_x_1[0] = &signal_B0CT01IZ1;
  array_m2170_x_1[1] = &signal_A0CT01IZ1;
  array_m2170_x_1[2] = &signal_B0CT01IZ2;
  array_m2170_x_1[3] = &signal_A0CT01IZ2;
  array_m2193_x_1[0] = &signal_R0VN09RZ1;
  array_m2193_x_1[1] = &signal_R0VN09RZ2;
  array_m1_x_1[7] = &signal_R0MD34LP1;
  array_m1_x_1[9] = &signal_R0MD34LP1;
  array_m1_x_1[11] = &signal_R0MD34LP1;
  array_m1_x_1[13] = &signal_R0MD34LP1;
  array_m1_x_1[15] = &signal_R0MD34LP1;
  array_m1_x_1[18] = &signal_A2IS12LDU;
  array_m1_x_1[25] = &signal_R0MD34LP1;
  array_m1_x_1[30] = &signal_R0MD34LP1;
  array_m1_x_1[34] = &signal_B3IS35LDU;
  array_m1_x_1[35] = &signal_B3IS35LDU;
  array_m1_x_1[45] = &signal_R2IS21LDU;
  array_m81_x_1[0] = &signal_R0VN11RZ2;
  array_m81_x_1[1] = &signal_R0VN11RZ1;
  array_m1054_x_1[0] = &signal_R0VN11RZ2;
  array_m1054_x_1[1] = &signal_R0VN11RZ1;
  array_m145_x_1[0] = &signal_A1IS21LDU;
  array_m145_x_1[1] = &signal_A3IS21LDU;
  array_m145_x_1[2] = &signal_A2IS21LDU;
  array_m589_x_1[0] = &signal_R0MD31LP1;
}

void InitInternalParametr(void)
{
  int i;
  S_scalzz_187_2.y0 = &internal2_m187_y0;
  S_scalzz_185_2.y0 = &internal2_m185_y0;
  S_tprg_214_2.y0 = &internal2_m214_y0;
  S_tprg_210_2.y0 = &internal2_m210_y0;
  S_drg_199_2.y1 = &internal2_m199_y1;
  S_drg_204_2.y1 = &internal2_m204_y1;
  S_drg_189_2.y1 = &internal2_m189_y1;
  S_drg_196_2.y1 = &internal2_m196_y1;
  S_enctkb_16_2.Nk0 = &internal2_m16_Nk0;
  S_enctkb_16_2.SetFlag = &internal2_m16_SetFlag;
  S_enctkb_16_2.FirstEnterFlag = &bFirstEnterFlag;
  S_enctkb_108_2.Nk0 = &internal2_m108_Nk0;
  S_enctkb_108_2.SetFlag = &internal2_m108_SetFlag;
  S_enctkb_108_2.FirstEnterFlag = &bFirstEnterFlag;
  S_enctkb_112_2.Nk0 = &internal2_m112_Nk0;
  S_enctkb_112_2.SetFlag = &internal2_m112_SetFlag;
  S_enctkb_112_2.FirstEnterFlag = &bFirstEnterFlag;
  S_enctkb_75_2.Nk0 = &internal2_m75_Nk0;
  S_enctkb_75_2.SetFlag = &internal2_m75_SetFlag;
  S_enctkb_75_2.FirstEnterFlag = &bFirstEnterFlag;
  S_enctkb_77_2.Nk0 = &internal2_m77_Nk0;
  S_enctkb_77_2.SetFlag = &internal2_m77_SetFlag;
  S_enctkb_77_2.FirstEnterFlag = &bFirstEnterFlag;
  S_enctkb_47_2.Nk0 = &internal2_m47_Nk0;
  S_enctkb_47_2.SetFlag = &internal2_m47_SetFlag;
  S_enctkb_47_2.FirstEnterFlag = &bFirstEnterFlag;
  S_enctkb_51_2.Nk0 = &internal2_m51_Nk0;
  S_enctkb_51_2.SetFlag = &internal2_m51_SetFlag;
  S_enctkb_51_2.FirstEnterFlag = &bFirstEnterFlag;
  S_enctkb_21_2.Nk0 = &internal2_m21_Nk0;
  S_enctkb_21_2.SetFlag = &internal2_m21_SetFlag;
  S_enctkb_21_2.FirstEnterFlag = &bFirstEnterFlag;
  S_rs_2094_1.q0 = &internal1_m2094_q0;
  S_rs_2078_1.q0 = &internal1_m2078_q0;
  S_rs_2120_1.q0 = &internal1_m2120_q0;
  S_rs_2104_1.q0 = &internal1_m2104_q0;
  S_rs_2097_1.q0 = &internal1_m2097_q0;
  S_rs_2080_1.q0 = &internal1_m2080_q0;
  S_rs_2096_1.q0 = &internal1_m2096_q0;
  S_rs_2079_1.q0 = &internal1_m2079_q0;
  S_rs_2077_1.q0 = &internal1_m2077_q0;
  S_rs_2076_1.q0 = &internal1_m2076_q0;
  S_rs_2090_1.q0 = &internal1_m2090_q0;
  S_rs_2088_1.q0 = &internal1_m2088_q0;
  S_rs_2095_1.q0 = &internal1_m2095_q0;
  S_rs_2092_1.q0 = &internal1_m2092_q0;
  S_rs_2123_1.q0 = &internal1_m2123_q0;
  S_rs_2106_1.q0 = &internal1_m2106_q0;
  S_rs_2122_1.q0 = &internal1_m2122_q0;
  S_rs_2105_1.q0 = &internal1_m2105_q0;
  S_rs_2103_1.q0 = &internal1_m2103_q0;
  S_rs_2102_1.q0 = &internal1_m2102_q0;
  S_rs_2116_1.q0 = &internal1_m2116_q0;
  S_rs_2114_1.q0 = &internal1_m2114_q0;
  S_ovbs_1997_1.tx = &internal1_m1997_tx;
  S_ovbs_1976_1.tx = &internal1_m1976_tx;
  S_nocnm_1689_1.Pv0 = &internal1_m1689_Pv0;
  S_nocnm_1689_1.Zv0 = &internal1_m1689_Zv0;
  S_nocnm_1689_1.MyFirstEnterFlag = &internal1_m1689_MyFirstEnterFlag;
  S_nocnm_1689_1.FirstEnterFlag = &bFirstEnterFlag;
  S_nocnm_1686_1.Pv0 = &internal1_m1686_Pv0;
  S_nocnm_1686_1.Zv0 = &internal1_m1686_Zv0;
  S_nocnm_1686_1.MyFirstEnterFlag = &internal1_m1686_MyFirstEnterFlag;
  S_nocnm_1686_1.FirstEnterFlag = &bFirstEnterFlag;
  S_zzfs_2138_1.tx = &internal1_m2138_tx;
  S_zzfs_2138_1.y0 = &internal1_m2138_y0;
  S_zpfs_2143_1.tx = &internal1_m2143_tx;
  S_zpfs_2143_1.y0 = &internal1_m2143_y0;
  S_zpfs_2142_1.tx = &internal1_m2142_tx;
  S_zpfs_2142_1.y0 = &internal1_m2142_y0;
  S_ovbs_2179_1.tx = &internal1_m2179_tx;
  S_zpfs_2177_1.tx = &internal1_m2177_tx;
  S_zpfs_2177_1.y0 = &internal1_m2177_y0;
  S_rs_2182_1.q0 = &internal1_m2182_q0;
  S_rs_2149_1.q0 = &internal1_m2149_q0;
  S_ovbs_2157_1.tx = &internal1_m2157_tx;
  S_rs_2155_1.q0 = &internal1_m2155_q0;
  S_zpfs_1991_1.tx = &internal1_m1991_tx;
  S_zpfs_1991_1.y0 = &internal1_m1991_y0;
  S_zpfs_1983_1.tx = &internal1_m1983_tx;
  S_zpfs_1983_1.y0 = &internal1_m1983_y0;
  S_rs_1682_1.q0 = &internal1_m1682_q0;
  S_rs_1680_1.q0 = &internal1_m1680_q0;
  S_rs_1679_1.q0 = &internal1_m1679_q0;
  S_rs_1710_1.q0 = &internal1_m1710_q0;
  S_zpfs_739_1.tx = &internal1_m739_tx;
  S_zpfs_739_1.y0 = &internal1_m739_y0;
  S_ovbs_1987_1.tx = &internal1_m1987_tx;
  S_rs_1990_1.q0 = &internal1_m1990_q0;
  S_rs_1982_1.q0 = &internal1_m1982_q0;
  S_ovbs_1952_1.tx = &internal1_m1952_tx;
  S_ovbs_1963_1.tx = &internal1_m1963_tx;
  S_ovbs_1949_1.tx = &internal1_m1949_tx;
  S_rs_1955_1.q0 = &internal1_m1955_q0;
  S_rs_1967_1.q0 = &internal1_m1967_q0;
  S_ovbs_1925_1.tx = &internal1_m1925_tx;
  S_ovbs_51_1.tx = &internal1_m51_tx;
  S_ovbs_336_1.tx = &internal1_m336_tx;
  S_ovbs_291_1.tx = &internal1_m291_tx;
  S_ovbs_740_1.tx = &internal1_m740_tx;
  S_ovbs_1405_1.tx = &internal1_m1405_tx;
  S_ovbs_112_1.tx = &internal1_m112_tx;
  S_ovbs_114_1.tx = &internal1_m114_tx;
  S_ovbs_119_1.tx = &internal1_m119_tx;
  S_ovbs_21_1.tx = &internal1_m21_tx;
  S_ovbs_13_1.tx = &internal1_m13_tx;
  S_ovbs_1934_1.tx = &internal1_m1934_tx;
  S_ovbs_1922_1.tx = &internal1_m1922_tx;
  S_ovbs_2030_1.tx = &internal1_m2030_tx;
  S_ovbs_2034_1.tx = &internal1_m2034_tx;
  S_ovbs_1847_1.tx = &internal1_m1847_tx;
  S_ovbs_76_1.tx = &internal1_m76_tx;
  S_zpfs_305_1.tx = &internal1_m305_tx;
  S_zpfs_305_1.y0 = &internal1_m305_y0;
  S_zpfs_1841_1.tx = &internal1_m1841_tx;
  S_zpfs_1841_1.y0 = &internal1_m1841_y0;
  S_zpfs_1839_1.tx = &internal1_m1839_tx;
  S_zpfs_1839_1.y0 = &internal1_m1839_y0;
  S_zpfs_1828_1.tx = &internal1_m1828_tx;
  S_zpfs_1828_1.y0 = &internal1_m1828_y0;
  S_rsfn_1848_1.q0 = &internal1_m1848_q0;
  S_rsfn_1425_1.q0 = &internal1_m1425_q0;
  S_rsfn_1463_1.q0 = &internal1_m1463_q0;
  S_rsfn_1466_1.q0 = &internal1_m1466_q0;
  S_rsfn_1887_1.q0 = &internal1_m1887_q0;
  S_zpfs_1864_1.tx = &internal1_m1864_tx;
  S_zpfs_1864_1.y0 = &internal1_m1864_y0;
  S_zpfs_1880_1.tx = &internal1_m1880_tx;
  S_zpfs_1880_1.y0 = &internal1_m1880_y0;
  S_zpfs_1877_1.tx = &internal1_m1877_tx;
  S_zpfs_1877_1.y0 = &internal1_m1877_y0;
  S_zpfs_2013_1.tx = &internal1_m2013_tx;
  S_zpfs_2013_1.y0 = &internal1_m2013_y0;
  S_zpfs_2024_1.tx = &internal1_m2024_tx;
  S_zpfs_2024_1.y0 = &internal1_m2024_y0;
  S_zpfs_1778_1.tx = &internal1_m1778_tx;
  S_zpfs_1778_1.y0 = &internal1_m1778_y0;
  S_zpfs_1777_1.tx = &internal1_m1777_tx;
  S_zpfs_1777_1.y0 = &internal1_m1777_y0;
  S_zpfs_1776_1.tx = &internal1_m1776_tx;
  S_zpfs_1776_1.y0 = &internal1_m1776_y0;
  S_zpfs_1775_1.tx = &internal1_m1775_tx;
  S_zpfs_1775_1.y0 = &internal1_m1775_y0;
  S_zpfs_1477_1.tx = &internal1_m1477_tx;
  S_zpfs_1477_1.y0 = &internal1_m1477_y0;
  S_zpfs_1471_1.tx = &internal1_m1471_tx;
  S_zpfs_1471_1.y0 = &internal1_m1471_y0;
  S_zpfs_1421_1.tx = &internal1_m1421_tx;
  S_zpfs_1421_1.y0 = &internal1_m1421_y0;
  S_zpfs_823_1.tx = &internal1_m823_tx;
  S_zpfs_823_1.y0 = &internal1_m823_y0;
  S_zpfs_820_1.tx = &internal1_m820_tx;
  S_zpfs_820_1.y0 = &internal1_m820_y0;
  S_zpfs_827_1.tx = &internal1_m827_tx;
  S_zpfs_827_1.y0 = &internal1_m827_y0;
  S_zpfs_186_1.tx = &internal1_m186_tx;
  S_zpfs_186_1.y0 = &internal1_m186_y0;
  S_zpfs_190_1.tx = &internal1_m190_tx;
  S_zpfs_190_1.y0 = &internal1_m190_y0;
  S_zpfs_197_1.tx = &internal1_m197_tx;
  S_zpfs_197_1.y0 = &internal1_m197_y0;
  S_zpfs_516_1.tx = &internal1_m516_tx;
  S_zpfs_516_1.y0 = &internal1_m516_y0;
  S_ovbs_2062_1.tx = &internal1_m2062_tx;
  S_ovbs_1165_1.tx = &internal1_m1165_tx;
  S_zpfs_1591_1.tx = &internal1_m1591_tx;
  S_zpfs_1591_1.y0 = &internal1_m1591_y0;
  S_zpfs_1131_1.tx = &internal1_m1131_tx;
  S_zpfs_1131_1.y0 = &internal1_m1131_y0;
  S_zpfs_1317_1.tx = &internal1_m1317_tx;
  S_zpfs_1317_1.y0 = &internal1_m1317_y0;
  S_zpfs_920_1.tx = &internal1_m920_tx;
  S_zpfs_920_1.y0 = &internal1_m920_y0;
  S_zpfs_1224_1.tx = &internal1_m1224_tx;
  S_zpfs_1224_1.y0 = &internal1_m1224_y0;
  S_rs_1072_1.q0 = &internal1_m1072_q0;
  S_rs_1070_1.q0 = &internal1_m1070_q0;
  S_rs_1069_1.q0 = &internal1_m1069_q0;
  S_rs_1067_1.q0 = &internal1_m1067_q0;
  S_rs_1066_1.q0 = &internal1_m1066_q0;
  S_rs_1064_1.q0 = &internal1_m1064_q0;
  S_rs_1063_1.q0 = &internal1_m1063_q0;
  S_rs_1061_1.q0 = &internal1_m1061_q0;
  S_rs_1060_1.q0 = &internal1_m1060_q0;
  S_swtakt_52_1.x0 = &internal1_m52_x0;
  S_rs_980_1.q0 = &internal1_m980_q0;
  S_swtakt_1414_1.x0 = &internal1_m1414_x0;
  S_swtakt_1458_1.x0 = &internal1_m1458_x0;
  S_swtakt_1454_1.x0 = &internal1_m1454_x0;
  S_swtakt_1856_1.x0 = &internal1_m1856_x0;
  S_swtakt_1821_1.x0 = &internal1_m1821_x0;
  S_rs_1019_1.q0 = &internal1_m1019_q0;
  S_rs_1031_1.q0 = &internal1_m1031_q0;
  S_rs_1043_1.q0 = &internal1_m1043_q0;
  S_rs_1052_1.q0 = &internal1_m1052_q0;
  S_rs_1030_1.q0 = &internal1_m1030_q0;
  S_rs_1045_1.q0 = &internal1_m1045_q0;
  S_rs_1914_1.q0 = &internal1_m1914_q0;
  S_rs_1913_1.q0 = &internal1_m1913_q0;
  S_provsbr_324_1.Step = &internal1_m324_Step;
  S_provsbr_324_1.TimS = &internal1_m324_TimS;
  S_provsbr_324_1.FinPr0 = &internal1_m324_FinPr0;
  S_provsbr_324_1.ErrPr0 = &internal1_m324_ErrPr0;
  S_provsbr_324_1.sbINI0 = &internal1_m324_sbINI0;
  S_provsbr_324_1.sbVuIS0 = &internal1_m324_sbVuIS0;
  S_provsbr_324_1.sb2UR0 = &internal1_m324_sb2UR0;
  S_provsbr_324_1.sbNupIS0 = &internal1_m324_sbNupIS0;
  S_provsbr_324_1.sbVuRB0 = &internal1_m324_sbVuRB0;
  S_provsbr_324_1.MyFirstEnterFlag = &internal1_m324_MyFirstEnterFlag;
  S_cntch_332_1.x0 = &internal1_m332_x0;
  S_decatron_290_1.TimS = &internal1_m290_TimS;
  S_provsbr_267_1.Step = &internal1_m267_Step;
  S_provsbr_267_1.TimS = &internal1_m267_TimS;
  S_provsbr_267_1.FinPr0 = &internal1_m267_FinPr0;
  S_provsbr_267_1.ErrPr0 = &internal1_m267_ErrPr0;
  S_provsbr_267_1.sbINI0 = &internal1_m267_sbINI0;
  S_provsbr_267_1.sbVuIS0 = &internal1_m267_sbVuIS0;
  S_provsbr_267_1.sb2UR0 = &internal1_m267_sb2UR0;
  S_provsbr_267_1.sbNupIS0 = &internal1_m267_sbNupIS0;
  S_provsbr_267_1.sbVuRB0 = &internal1_m267_sbVuRB0;
  S_provsbr_267_1.MyFirstEnterFlag = &internal1_m267_MyFirstEnterFlag;
  S_rs_1388_1.q0 = &internal1_m1388_q0;
  S_provsbr_1389_1.Step = &internal1_m1389_Step;
  S_provsbr_1389_1.TimS = &internal1_m1389_TimS;
  S_provsbr_1389_1.FinPr0 = &internal1_m1389_FinPr0;
  S_provsbr_1389_1.ErrPr0 = &internal1_m1389_ErrPr0;
  S_provsbr_1389_1.sbINI0 = &internal1_m1389_sbINI0;
  S_provsbr_1389_1.sbVuIS0 = &internal1_m1389_sbVuIS0;
  S_provsbr_1389_1.sb2UR0 = &internal1_m1389_sb2UR0;
  S_provsbr_1389_1.sbNupIS0 = &internal1_m1389_sbNupIS0;
  S_provsbr_1389_1.sbVuRB0 = &internal1_m1389_sbVuRB0;
  S_provsbr_1389_1.MyFirstEnterFlag = &internal1_m1389_MyFirstEnterFlag;
  S_rs_1014_1.q0 = &internal1_m1014_q0;
  S_rs_1011_1.q0 = &internal1_m1011_q0;
  S_rs_1013_1.q0 = &internal1_m1013_q0;
  S_rs_1008_1.q0 = &internal1_m1008_q0;
  S_rs_741_1.q0 = &internal1_m741_q0;
  S_rs_334_1.q0 = &internal1_m334_q0;
  S_rs_330_1.q0 = &internal1_m330_q0;
  S_rs_287_1.q0 = &internal1_m287_q0;
  S_cntch_286_1.x0 = &internal1_m286_x0;
  S_rs_1843_1.q0 = &internal1_m1843_q0;
  S_rs_1831_1.q0 = &internal1_m1831_q0;
  S_rs_1822_1.q0 = &internal1_m1822_q0;
  S_rs_1897_1.q0 = &internal1_m1897_q0;
  S_rs_1867_1.q0 = &internal1_m1867_q0;
  S_rs_1857_1.q0 = &internal1_m1857_q0;
  S_rs_1441_1.q0 = &internal1_m1441_q0;
  S_kvf_1428_1.x0 = &internal1_m1428_x0;
  S_kvf_1428_1.y0 = &internal1_m1428_y0;
  S_kvf_1428_1.FirstEnterFlag = &bFirstEnterFlag;
  S_rs_1424_1.q0 = &internal1_m1424_q0;
  S_rs_1415_1.q0 = &internal1_m1415_q0;
  S_rs_1474_1.q0 = &internal1_m1474_q0;
  S_rs_1494_1.q0 = &internal1_m1494_q0;
  S_rs_1460_1.q0 = &internal1_m1460_q0;
  S_kvf_1475_1.x0 = &internal1_m1475_x0;
  S_kvf_1475_1.y0 = &internal1_m1475_y0;
  S_kvf_1475_1.FirstEnterFlag = &bFirstEnterFlag;
  S_cntch_1399_1.x0 = &internal1_m1399_x0;
  S_rs_1480_1.q0 = &internal1_m1480_q0;
  S_rs_26_1.q0 = &internal1_m26_q0;
  S_rs_1495_1.q0 = &internal1_m1495_q0;
  S_rs_631_1.q0 = &internal1_m631_q0;
  S_rs_616_1.q0 = &internal1_m616_q0;
  S_rs_642_1.q0 = &internal1_m642_q0;
  S_rs_627_1.q0 = &internal1_m627_q0;
  S_rs_611_1.q0 = &internal1_m611_q0;
  S_rs_609_1.q0 = &internal1_m609_q0;
  S_rs_597_1.q0 = &internal1_m597_q0;
  S_rsun_1391_1.q0 = &internal1_m1391_q0;
  S_rs_607_1.q0 = &internal1_m607_q0;
  S_rs_108_1.q0 = &internal1_m108_q0;
  S_rs_1625_1.q0 = &internal1_m1625_q0;
  S_rs_1624_1.q0 = &internal1_m1624_q0;
  S_rs_1623_1.q0 = &internal1_m1623_q0;
  S_rs_1622_1.q0 = &internal1_m1622_q0;
  S_rs_1651_1.q0 = &internal1_m1651_q0;
  S_rs_1650_1.q0 = &internal1_m1650_q0;
  S_rs_1649_1.q0 = &internal1_m1649_q0;
  S_rs_1648_1.q0 = &internal1_m1648_q0;
  S_rs_1928_1.q0 = &internal1_m1928_q0;
  S_rs_1708_1.q0 = &internal1_m1708_q0;
  S_rs_1707_1.q0 = &internal1_m1707_q0;
  S_rs_1705_1.q0 = &internal1_m1705_q0;
  S_rs_1704_1.q0 = &internal1_m1704_q0;
  S_rs_1702_1.q0 = &internal1_m1702_q0;
  S_rs_2121_1.q0 = &internal1_m2121_q0;
  S_rs_2118_1.q0 = &internal1_m2118_q0;
  S_rs_1677_1.q0 = &internal1_m1677_q0;
  S_rs_1671_1.q0 = &internal1_m1671_q0;
  S_rs_1670_1.q0 = &internal1_m1670_q0;
  S_rs_1666_1.q0 = &internal1_m1666_q0;
  S_rs_1668_1.q0 = &internal1_m1668_q0;
  S_rs_1665_1.q0 = &internal1_m1665_q0;
  S_rs_1664_1.q0 = &internal1_m1664_q0;
  S_rs_1660_1.q0 = &internal1_m1660_q0;
  S_rs_1662_1.q0 = &internal1_m1662_q0;
  S_rs_19_1.q0 = &internal1_m19_q0;
  S_rs_1645_1.q0 = &internal1_m1645_q0;
  S_rs_1643_1.q0 = &internal1_m1643_q0;
  S_rs_1640_1.q0 = &internal1_m1640_q0;
  S_rs_1642_1.q0 = &internal1_m1642_q0;
  S_rs_1639_1.q0 = &internal1_m1639_q0;
  S_rs_1637_1.q0 = &internal1_m1637_q0;
  S_rs_2044_1.q0 = &internal1_m2044_q0;
  S_rs_2039_1.q0 = &internal1_m2039_q0;
  S_rs_2018_1.q0 = &internal1_m2018_q0;
  S_rs_2006_1.q0 = &internal1_m2006_q0;
  S_rs_1939_1.q0 = &internal1_m1939_q0;
  S_rs_1634_1.q0 = &internal1_m1634_q0;
  S_rs_1636_1.q0 = &internal1_m1636_q0;
  S_rs_1621_1.q0 = &internal1_m1621_q0;
  S_rs_1619_1.q0 = &internal1_m1619_q0;
  S_rs_1618_1.q0 = &internal1_m1618_q0;
  S_rs_1616_1.q0 = &internal1_m1616_q0;
  S_rs_1615_1.q0 = &internal1_m1615_q0;
  S_rs_1613_1.q0 = &internal1_m1613_q0;
  S_rs_1612_1.q0 = &internal1_m1612_q0;
  S_rs_1610_1.q0 = &internal1_m1610_q0;
  S_samhd_2067_1.DvUp0 = &internal1_m2067_DvUp0;
  S_samhd_2067_1.DvDw0 = &internal1_m2067_DvDw0;
  S_samhd_2067_1.FDvUp0 = &internal1_m2067_FDvUp0;
  S_samhd_2067_1.FDvDw0 = &internal1_m2067_FDvDw0;
  S_samhd_2067_1.BlDv0 = &internal1_m2067_BlDv0;
  S_samhd_2067_1.Pkv0 = &internal1_m2067_Pkv0;
  S_samhd_2067_1.Pkav0 = &internal1_m2067_Pkav0;
  S_samhd_2067_1.Zkv0 = &internal1_m2067_Zkv0;
  S_samhd_2067_1.Zkav0 = &internal1_m2067_Zkav0;
  S_samhd_2067_1.txNm = &internal1_m2067_txNm;
  S_samhd_2067_1.txSm = &internal1_m2067_txSm;
  S_samhd_2067_1.txHr = &internal1_m2067_txHr;
  S_samhd_2067_1.txLd = &internal1_m2067_txLd;
  S_samhd_2067_1.fef = &internal1_m2067_fef;
  S_samhd_2067_1.FirstEnterFlag = &bFirstEnterFlag;
  S_samhd_2061_1.DvUp0 = &internal1_m2061_DvUp0;
  S_samhd_2061_1.DvDw0 = &internal1_m2061_DvDw0;
  S_samhd_2061_1.FDvUp0 = &internal1_m2061_FDvUp0;
  S_samhd_2061_1.FDvDw0 = &internal1_m2061_FDvDw0;
  S_samhd_2061_1.BlDv0 = &internal1_m2061_BlDv0;
  S_samhd_2061_1.Pkv0 = &internal1_m2061_Pkv0;
  S_samhd_2061_1.Pkav0 = &internal1_m2061_Pkav0;
  S_samhd_2061_1.Zkv0 = &internal1_m2061_Zkv0;
  S_samhd_2061_1.Zkav0 = &internal1_m2061_Zkav0;
  S_samhd_2061_1.txNm = &internal1_m2061_txNm;
  S_samhd_2061_1.txSm = &internal1_m2061_txSm;
  S_samhd_2061_1.txHr = &internal1_m2061_txHr;
  S_samhd_2061_1.txLd = &internal1_m2061_txLd;
  S_samhd_2061_1.fef = &internal1_m2061_fef;
  S_samhd_2061_1.FirstEnterFlag = &bFirstEnterFlag;
  S_rs_1465_1.q0 = &internal1_m1465_q0;
  S_kvf_1469_1.x0 = &internal1_m1469_x0;
  S_kvf_1469_1.y0 = &internal1_m1469_y0;
  S_kvf_1469_1.FirstEnterFlag = &bFirstEnterFlag;
  S_kvf_1879_1.x0 = &internal1_m1879_x0;
  S_kvf_1879_1.y0 = &internal1_m1879_y0;
  S_kvf_1879_1.FirstEnterFlag = &bFirstEnterFlag;
  S_kvf_1840_1.x0 = &internal1_m1840_x0;
  S_kvf_1840_1.y0 = &internal1_m1840_y0;
  S_kvf_1840_1.FirstEnterFlag = &bFirstEnterFlag;
  S_rs_278_1.q0 = &internal1_m278_q0;
  S_rs_988_1.q0 = &internal1_m988_q0;
  S_rs_619_1.q0 = &internal1_m619_q0;
  S_cnshd_1288_1.X0 = &internal1_m1288_X0;
  S_cnshd_1288_1.t0 = &internal1_m1288_t0;
  S_cnshd_1288_1.BLDv0 = &internal1_m1288_BLDv0;
  S_zpfs_1307_1.tx = &internal1_m1307_tx;
  S_zpfs_1307_1.y0 = &internal1_m1307_y0;
  S_zpfs_1310_1.tx = &internal1_m1310_tx;
  S_zpfs_1310_1.y0 = &internal1_m1310_y0;
  S_fnapb_1316_1.xptr = &internal1_m1316_xptr;
  S_fnapb_1316_1.sumtim = &internal1_m1316_sumtim;
  S_fnapb_1316_1.StSpeed = &internal1_m1316_StSpeed;
  S_fnapb_1316_1.Vz0 = &internal1_m1316_Vz0;
  S_fnapb_1316_1.flRazg = &internal1_m1316_flRazg;
  S_fnapb_1316_1.DelSp = &internal1_m1316_DelSp;
  S_fnapb_1316_1.z0 = &internal1_m1316_z0;
  S_fnapb_1316_1.txZS = &internal1_m1316_txZS;
  S_fnapb_1316_1.tx = &internal1_m1316_tx;
  S_fnapb_1316_1.txd = &internal1_m1316_txd;
  S_fnapb_1316_1.txMBl = &internal1_m1316_txMBl;
  S_fnapb_1316_1.txBl = &internal1_m1316_txBl;
  S_fnapb_1316_1.Speed0 = &internal1_m1316_Speed0;
  S_fnapb_1316_1.xz0 = &internal1_m1316_xz0;
  S_fnapb_1316_1.tz0 = &internal1_m1316_tz0;
  S_fnapb_1316_1.Shift0 = &internal1_m1316_Shift0;
  S_fnapb_1316_1.ShCntlSp0 = &internal1_m1316_ShCntlSp0;
  S_fnapb_1316_1.ShiftControl = &internal1_m1316_ShiftControl;
  S_fnapb_1316_1.FirstEnterFlag = &bFirstEnterFlag;
  S_rs_617_1.q0 = &internal1_m617_q0;
  S_cnshd_886_1.X0 = &internal1_m886_X0;
  S_cnshd_886_1.t0 = &internal1_m886_t0;
  S_cnshd_886_1.BLDv0 = &internal1_m886_BLDv0;
  S_zpfs_910_1.tx = &internal1_m910_tx;
  S_zpfs_910_1.y0 = &internal1_m910_y0;
  S_zpfs_911_1.tx = &internal1_m911_tx;
  S_zpfs_911_1.y0 = &internal1_m911_y0;
  S_fnapb_919_1.xptr = &internal1_m919_xptr;
  S_fnapb_919_1.sumtim = &internal1_m919_sumtim;
  S_fnapb_919_1.StSpeed = &internal1_m919_StSpeed;
  S_fnapb_919_1.Vz0 = &internal1_m919_Vz0;
  S_fnapb_919_1.flRazg = &internal1_m919_flRazg;
  S_fnapb_919_1.DelSp = &internal1_m919_DelSp;
  S_fnapb_919_1.z0 = &internal1_m919_z0;
  S_fnapb_919_1.txZS = &internal1_m919_txZS;
  S_fnapb_919_1.tx = &internal1_m919_tx;
  S_fnapb_919_1.txd = &internal1_m919_txd;
  S_fnapb_919_1.txMBl = &internal1_m919_txMBl;
  S_fnapb_919_1.txBl = &internal1_m919_txBl;
  S_fnapb_919_1.Speed0 = &internal1_m919_Speed0;
  S_fnapb_919_1.xz0 = &internal1_m919_xz0;
  S_fnapb_919_1.tz0 = &internal1_m919_tz0;
  S_fnapb_919_1.Shift0 = &internal1_m919_Shift0;
  S_fnapb_919_1.ShCntlSp0 = &internal1_m919_ShCntlSp0;
  S_fnapb_919_1.ShiftControl = &internal1_m919_ShiftControl;
  S_fnapb_919_1.FirstEnterFlag = &bFirstEnterFlag;
  S_cnshd_488_1.X0 = &internal1_m488_X0;
  S_cnshd_488_1.t0 = &internal1_m488_t0;
  S_cnshd_488_1.BLDv0 = &internal1_m488_BLDv0;
  S_zpfs_508_1.tx = &internal1_m508_tx;
  S_zpfs_508_1.y0 = &internal1_m508_y0;
  S_zpfs_511_1.tx = &internal1_m511_tx;
  S_zpfs_511_1.y0 = &internal1_m511_y0;
  S_fnapb_515_1.xptr = &internal1_m515_xptr;
  S_fnapb_515_1.sumtim = &internal1_m515_sumtim;
  S_fnapb_515_1.StSpeed = &internal1_m515_StSpeed;
  S_fnapb_515_1.Vz0 = &internal1_m515_Vz0;
  S_fnapb_515_1.flRazg = &internal1_m515_flRazg;
  S_fnapb_515_1.DelSp = &internal1_m515_DelSp;
  S_fnapb_515_1.z0 = &internal1_m515_z0;
  S_fnapb_515_1.txZS = &internal1_m515_txZS;
  S_fnapb_515_1.tx = &internal1_m515_tx;
  S_fnapb_515_1.txd = &internal1_m515_txd;
  S_fnapb_515_1.txMBl = &internal1_m515_txMBl;
  S_fnapb_515_1.txBl = &internal1_m515_txBl;
  S_fnapb_515_1.Speed0 = &internal1_m515_Speed0;
  S_fnapb_515_1.xz0 = &internal1_m515_xz0;
  S_fnapb_515_1.tz0 = &internal1_m515_tz0;
  S_fnapb_515_1.Shift0 = &internal1_m515_Shift0;
  S_fnapb_515_1.ShCntlSp0 = &internal1_m515_ShCntlSp0;
  S_fnapb_515_1.ShiftControl = &internal1_m515_ShiftControl;
  S_fnapb_515_1.FirstEnterFlag = &bFirstEnterFlag;
  S_rs_614_1.q0 = &internal1_m614_q0;
  S_cnshd_167_1.X0 = &internal1_m167_X0;
  S_cnshd_167_1.t0 = &internal1_m167_t0;
  S_cnshd_167_1.BLDv0 = &internal1_m167_BLDv0;
  S_fnapb_196_1.xptr = &internal1_m196_xptr;
  S_fnapb_196_1.sumtim = &internal1_m196_sumtim;
  S_fnapb_196_1.StSpeed = &internal1_m196_StSpeed;
  S_fnapb_196_1.Vz0 = &internal1_m196_Vz0;
  S_fnapb_196_1.flRazg = &internal1_m196_flRazg;
  S_fnapb_196_1.DelSp = &internal1_m196_DelSp;
  S_fnapb_196_1.z0 = &internal1_m196_z0;
  S_fnapb_196_1.txZS = &internal1_m196_txZS;
  S_fnapb_196_1.tx = &internal1_m196_tx;
  S_fnapb_196_1.txd = &internal1_m196_txd;
  S_fnapb_196_1.txMBl = &internal1_m196_txMBl;
  S_fnapb_196_1.txBl = &internal1_m196_txBl;
  S_fnapb_196_1.Speed0 = &internal1_m196_Speed0;
  S_fnapb_196_1.xz0 = &internal1_m196_xz0;
  S_fnapb_196_1.tz0 = &internal1_m196_tz0;
  S_fnapb_196_1.Shift0 = &internal1_m196_Shift0;
  S_fnapb_196_1.ShCntlSp0 = &internal1_m196_ShCntlSp0;
  S_fnapb_196_1.ShiftControl = &internal1_m196_ShiftControl;
  S_fnapb_196_1.FirstEnterFlag = &bFirstEnterFlag;
  S_rs_640_1.q0 = &internal1_m640_q0;
  S_samhd_459_1.DvUp0 = &internal1_m459_DvUp0;
  S_samhd_459_1.DvDw0 = &internal1_m459_DvDw0;
  S_samhd_459_1.FDvUp0 = &internal1_m459_FDvUp0;
  S_samhd_459_1.FDvDw0 = &internal1_m459_FDvDw0;
  S_samhd_459_1.BlDv0 = &internal1_m459_BlDv0;
  S_samhd_459_1.Pkv0 = &internal1_m459_Pkv0;
  S_samhd_459_1.Pkav0 = &internal1_m459_Pkav0;
  S_samhd_459_1.Zkv0 = &internal1_m459_Zkv0;
  S_samhd_459_1.Zkav0 = &internal1_m459_Zkav0;
  S_samhd_459_1.txNm = &internal1_m459_txNm;
  S_samhd_459_1.txSm = &internal1_m459_txSm;
  S_samhd_459_1.txHr = &internal1_m459_txHr;
  S_samhd_459_1.txLd = &internal1_m459_txLd;
  S_samhd_459_1.fef = &internal1_m459_fef;
  S_samhd_459_1.FirstEnterFlag = &bFirstEnterFlag;
  S_samhd_453_1.DvUp0 = &internal1_m453_DvUp0;
  S_samhd_453_1.DvDw0 = &internal1_m453_DvDw0;
  S_samhd_453_1.FDvUp0 = &internal1_m453_FDvUp0;
  S_samhd_453_1.FDvDw0 = &internal1_m453_FDvDw0;
  S_samhd_453_1.BlDv0 = &internal1_m453_BlDv0;
  S_samhd_453_1.Pkv0 = &internal1_m453_Pkv0;
  S_samhd_453_1.Pkav0 = &internal1_m453_Pkav0;
  S_samhd_453_1.Zkv0 = &internal1_m453_Zkv0;
  S_samhd_453_1.Zkav0 = &internal1_m453_Zkav0;
  S_samhd_453_1.txNm = &internal1_m453_txNm;
  S_samhd_453_1.txSm = &internal1_m453_txSm;
  S_samhd_453_1.txHr = &internal1_m453_txHr;
  S_samhd_453_1.txLd = &internal1_m453_txLd;
  S_samhd_453_1.fef = &internal1_m453_fef;
  S_samhd_453_1.FirstEnterFlag = &bFirstEnterFlag;
  S_cnshd_806_1.X0 = &internal1_m806_X0;
  S_cnshd_806_1.t0 = &internal1_m806_t0;
  S_cnshd_806_1.BLDv0 = &internal1_m806_BLDv0;
  S_fnapb_826_1.xptr = &internal1_m826_xptr;
  S_fnapb_826_1.sumtim = &internal1_m826_sumtim;
  S_fnapb_826_1.StSpeed = &internal1_m826_StSpeed;
  S_fnapb_826_1.Vz0 = &internal1_m826_Vz0;
  S_fnapb_826_1.flRazg = &internal1_m826_flRazg;
  S_fnapb_826_1.DelSp = &internal1_m826_DelSp;
  S_fnapb_826_1.z0 = &internal1_m826_z0;
  S_fnapb_826_1.txZS = &internal1_m826_txZS;
  S_fnapb_826_1.tx = &internal1_m826_tx;
  S_fnapb_826_1.txd = &internal1_m826_txd;
  S_fnapb_826_1.txMBl = &internal1_m826_txMBl;
  S_fnapb_826_1.txBl = &internal1_m826_txBl;
  S_fnapb_826_1.Speed0 = &internal1_m826_Speed0;
  S_fnapb_826_1.xz0 = &internal1_m826_xz0;
  S_fnapb_826_1.tz0 = &internal1_m826_tz0;
  S_fnapb_826_1.Shift0 = &internal1_m826_Shift0;
  S_fnapb_826_1.ShCntlSp0 = &internal1_m826_ShCntlSp0;
  S_fnapb_826_1.ShiftControl = &internal1_m826_ShiftControl;
  S_fnapb_826_1.FirstEnterFlag = &bFirstEnterFlag;
  S_cnshd_1570_1.X0 = &internal1_m1570_X0;
  S_cnshd_1570_1.t0 = &internal1_m1570_t0;
  S_cnshd_1570_1.BLDv0 = &internal1_m1570_BLDv0;
  S_cnshd_1109_1.X0 = &internal1_m1109_X0;
  S_cnshd_1109_1.t0 = &internal1_m1109_t0;
  S_cnshd_1109_1.BLDv0 = &internal1_m1109_BLDv0;
  S_rs_612_1.q0 = &internal1_m612_q0;
  S_cnshd_1191_1.X0 = &internal1_m1191_X0;
  S_cnshd_1191_1.t0 = &internal1_m1191_t0;
  S_cnshd_1191_1.BLDv0 = &internal1_m1191_BLDv0;
  S_zpfs_1211_1.tx = &internal1_m1211_tx;
  S_zpfs_1211_1.y0 = &internal1_m1211_y0;
  S_zpfs_1219_1.tx = &internal1_m1219_tx;
  S_zpfs_1219_1.y0 = &internal1_m1219_y0;
  S_fnapb_1226_1.xptr = &internal1_m1226_xptr;
  S_fnapb_1226_1.sumtim = &internal1_m1226_sumtim;
  S_fnapb_1226_1.StSpeed = &internal1_m1226_StSpeed;
  S_fnapb_1226_1.Vz0 = &internal1_m1226_Vz0;
  S_fnapb_1226_1.flRazg = &internal1_m1226_flRazg;
  S_fnapb_1226_1.DelSp = &internal1_m1226_DelSp;
  S_fnapb_1226_1.z0 = &internal1_m1226_z0;
  S_fnapb_1226_1.txZS = &internal1_m1226_txZS;
  S_fnapb_1226_1.tx = &internal1_m1226_tx;
  S_fnapb_1226_1.txd = &internal1_m1226_txd;
  S_fnapb_1226_1.txMBl = &internal1_m1226_txMBl;
  S_fnapb_1226_1.txBl = &internal1_m1226_txBl;
  S_fnapb_1226_1.Speed0 = &internal1_m1226_Speed0;
  S_fnapb_1226_1.xz0 = &internal1_m1226_xz0;
  S_fnapb_1226_1.tz0 = &internal1_m1226_tz0;
  S_fnapb_1226_1.Shift0 = &internal1_m1226_Shift0;
  S_fnapb_1226_1.ShCntlSp0 = &internal1_m1226_ShCntlSp0;
  S_fnapb_1226_1.ShiftControl = &internal1_m1226_ShiftControl;
  S_fnapb_1226_1.FirstEnterFlag = &bFirstEnterFlag;
  S_rs_632_1.q0 = &internal1_m632_q0;
  S_zpfs_1583_1.tx = &internal1_m1583_tx;
  S_zpfs_1583_1.y0 = &internal1_m1583_y0;
  S_zpfs_1586_1.tx = &internal1_m1586_tx;
  S_zpfs_1586_1.y0 = &internal1_m1586_y0;
  S_samhd_1573_1.DvUp0 = &internal1_m1573_DvUp0;
  S_samhd_1573_1.DvDw0 = &internal1_m1573_DvDw0;
  S_samhd_1573_1.FDvUp0 = &internal1_m1573_FDvUp0;
  S_samhd_1573_1.FDvDw0 = &internal1_m1573_FDvDw0;
  S_samhd_1573_1.BlDv0 = &internal1_m1573_BlDv0;
  S_samhd_1573_1.Pkv0 = &internal1_m1573_Pkv0;
  S_samhd_1573_1.Pkav0 = &internal1_m1573_Pkav0;
  S_samhd_1573_1.Zkv0 = &internal1_m1573_Zkv0;
  S_samhd_1573_1.Zkav0 = &internal1_m1573_Zkav0;
  S_samhd_1573_1.txNm = &internal1_m1573_txNm;
  S_samhd_1573_1.txSm = &internal1_m1573_txSm;
  S_samhd_1573_1.txHr = &internal1_m1573_txHr;
  S_samhd_1573_1.txLd = &internal1_m1573_txLd;
  S_samhd_1573_1.fef = &internal1_m1573_fef;
  S_samhd_1573_1.FirstEnterFlag = &bFirstEnterFlag;
  S_fnapb_1590_1.xptr = &internal1_m1590_xptr;
  S_fnapb_1590_1.sumtim = &internal1_m1590_sumtim;
  S_fnapb_1590_1.StSpeed = &internal1_m1590_StSpeed;
  S_fnapb_1590_1.Vz0 = &internal1_m1590_Vz0;
  S_fnapb_1590_1.flRazg = &internal1_m1590_flRazg;
  S_fnapb_1590_1.DelSp = &internal1_m1590_DelSp;
  S_fnapb_1590_1.z0 = &internal1_m1590_z0;
  S_fnapb_1590_1.txZS = &internal1_m1590_txZS;
  S_fnapb_1590_1.tx = &internal1_m1590_tx;
  S_fnapb_1590_1.txd = &internal1_m1590_txd;
  S_fnapb_1590_1.txMBl = &internal1_m1590_txMBl;
  S_fnapb_1590_1.txBl = &internal1_m1590_txBl;
  S_fnapb_1590_1.Speed0 = &internal1_m1590_Speed0;
  S_fnapb_1590_1.xz0 = &internal1_m1590_xz0;
  S_fnapb_1590_1.tz0 = &internal1_m1590_tz0;
  S_fnapb_1590_1.Shift0 = &internal1_m1590_Shift0;
  S_fnapb_1590_1.ShCntlSp0 = &internal1_m1590_ShCntlSp0;
  S_fnapb_1590_1.ShiftControl = &internal1_m1590_ShiftControl;
  S_fnapb_1590_1.FirstEnterFlag = &bFirstEnterFlag;
  S_zpfs_1122_1.tx = &internal1_m1122_tx;
  S_zpfs_1122_1.y0 = &internal1_m1122_y0;
  S_zpfs_1126_1.tx = &internal1_m1126_tx;
  S_zpfs_1126_1.y0 = &internal1_m1126_y0;
  S_rs_622_1.q0 = &internal1_m622_q0;
  S_rs_587_1.q0 = &internal1_m587_q0;
  S_samhd_1113_1.DvUp0 = &internal1_m1113_DvUp0;
  S_samhd_1113_1.DvDw0 = &internal1_m1113_DvDw0;
  S_samhd_1113_1.FDvUp0 = &internal1_m1113_FDvUp0;
  S_samhd_1113_1.FDvDw0 = &internal1_m1113_FDvDw0;
  S_samhd_1113_1.BlDv0 = &internal1_m1113_BlDv0;
  S_samhd_1113_1.Pkv0 = &internal1_m1113_Pkv0;
  S_samhd_1113_1.Pkav0 = &internal1_m1113_Pkav0;
  S_samhd_1113_1.Zkv0 = &internal1_m1113_Zkv0;
  S_samhd_1113_1.Zkav0 = &internal1_m1113_Zkav0;
  S_samhd_1113_1.txNm = &internal1_m1113_txNm;
  S_samhd_1113_1.txSm = &internal1_m1113_txSm;
  S_samhd_1113_1.txHr = &internal1_m1113_txHr;
  S_samhd_1113_1.txLd = &internal1_m1113_txLd;
  S_samhd_1113_1.fef = &internal1_m1113_fef;
  S_samhd_1113_1.FirstEnterFlag = &bFirstEnterFlag;
  S_fnapb_1130_1.xptr = &internal1_m1130_xptr;
  S_fnapb_1130_1.sumtim = &internal1_m1130_sumtim;
  S_fnapb_1130_1.StSpeed = &internal1_m1130_StSpeed;
  S_fnapb_1130_1.Vz0 = &internal1_m1130_Vz0;
  S_fnapb_1130_1.flRazg = &internal1_m1130_flRazg;
  S_fnapb_1130_1.DelSp = &internal1_m1130_DelSp;
  S_fnapb_1130_1.z0 = &internal1_m1130_z0;
  S_fnapb_1130_1.txZS = &internal1_m1130_txZS;
  S_fnapb_1130_1.tx = &internal1_m1130_tx;
  S_fnapb_1130_1.txd = &internal1_m1130_txd;
  S_fnapb_1130_1.txMBl = &internal1_m1130_txMBl;
  S_fnapb_1130_1.txBl = &internal1_m1130_txBl;
  S_fnapb_1130_1.Speed0 = &internal1_m1130_Speed0;
  S_fnapb_1130_1.xz0 = &internal1_m1130_xz0;
  S_fnapb_1130_1.tz0 = &internal1_m1130_tz0;
  S_fnapb_1130_1.Shift0 = &internal1_m1130_Shift0;
  S_fnapb_1130_1.ShCntlSp0 = &internal1_m1130_ShCntlSp0;
  S_fnapb_1130_1.ShiftControl = &internal1_m1130_ShiftControl;
  S_fnapb_1130_1.FirstEnterFlag = &bFirstEnterFlag;
  S_vmemb_735_1.x0 = &internal1_m735_x0;
  S_vmemb_704_1.x0 = &internal1_m704_x0;
  S_vmemb_667_1.x0 = &internal1_m667_x0;
  S_rs_760_1.q0 = &internal1_m760_q0;
  S_rs_755_1.q0 = &internal1_m755_q0;
  S_rs_723_1.q0 = &internal1_m723_q0;
  S_rs_728_1.q0 = &internal1_m728_q0;
  S_rs_736_1.q0 = &internal1_m736_q0;
  S_rs_748_1.q0 = &internal1_m748_q0;
  S_rs_726_1.q0 = &internal1_m726_q0;
  S_samhd_1167_1.DvUp0 = &internal1_m1167_DvUp0;
  S_samhd_1167_1.DvDw0 = &internal1_m1167_DvDw0;
  S_samhd_1167_1.FDvUp0 = &internal1_m1167_FDvUp0;
  S_samhd_1167_1.FDvDw0 = &internal1_m1167_FDvDw0;
  S_samhd_1167_1.BlDv0 = &internal1_m1167_BlDv0;
  S_samhd_1167_1.Pkv0 = &internal1_m1167_Pkv0;
  S_samhd_1167_1.Pkav0 = &internal1_m1167_Pkav0;
  S_samhd_1167_1.Zkv0 = &internal1_m1167_Zkv0;
  S_samhd_1167_1.Zkav0 = &internal1_m1167_Zkav0;
  S_samhd_1167_1.txNm = &internal1_m1167_txNm;
  S_samhd_1167_1.txSm = &internal1_m1167_txSm;
  S_samhd_1167_1.txHr = &internal1_m1167_txHr;
  S_samhd_1167_1.txLd = &internal1_m1167_txLd;
  S_samhd_1167_1.fef = &internal1_m1167_fef;
  S_samhd_1167_1.FirstEnterFlag = &bFirstEnterFlag;
  S_samhd_1157_1.DvUp0 = &internal1_m1157_DvUp0;
  S_samhd_1157_1.DvDw0 = &internal1_m1157_DvDw0;
  S_samhd_1157_1.FDvUp0 = &internal1_m1157_FDvUp0;
  S_samhd_1157_1.FDvDw0 = &internal1_m1157_FDvDw0;
  S_samhd_1157_1.BlDv0 = &internal1_m1157_BlDv0;
  S_samhd_1157_1.Pkv0 = &internal1_m1157_Pkv0;
  S_samhd_1157_1.Pkav0 = &internal1_m1157_Pkav0;
  S_samhd_1157_1.Zkv0 = &internal1_m1157_Zkv0;
  S_samhd_1157_1.Zkav0 = &internal1_m1157_Zkav0;
  S_samhd_1157_1.txNm = &internal1_m1157_txNm;
  S_samhd_1157_1.txSm = &internal1_m1157_txSm;
  S_samhd_1157_1.txHr = &internal1_m1157_txHr;
  S_samhd_1157_1.txLd = &internal1_m1157_txLd;
  S_samhd_1157_1.fef = &internal1_m1157_fef;
  S_samhd_1157_1.FirstEnterFlag = &bFirstEnterFlag;
  S_samhd_780_1.DvUp0 = &internal1_m780_DvUp0;
  S_samhd_780_1.DvDw0 = &internal1_m780_DvDw0;
  S_samhd_780_1.FDvUp0 = &internal1_m780_FDvUp0;
  S_samhd_780_1.FDvDw0 = &internal1_m780_FDvDw0;
  S_samhd_780_1.BlDv0 = &internal1_m780_BlDv0;
  S_samhd_780_1.Pkv0 = &internal1_m780_Pkv0;
  S_samhd_780_1.Pkav0 = &internal1_m780_Pkav0;
  S_samhd_780_1.Zkv0 = &internal1_m780_Zkv0;
  S_samhd_780_1.Zkav0 = &internal1_m780_Zkav0;
  S_samhd_780_1.txNm = &internal1_m780_txNm;
  S_samhd_780_1.txSm = &internal1_m780_txSm;
  S_samhd_780_1.txHr = &internal1_m780_txHr;
  S_samhd_780_1.txLd = &internal1_m780_txLd;
  S_samhd_780_1.fef = &internal1_m780_fef;
  S_samhd_780_1.FirstEnterFlag = &bFirstEnterFlag;
  S_samhd_776_1.DvUp0 = &internal1_m776_DvUp0;
  S_samhd_776_1.DvDw0 = &internal1_m776_DvDw0;
  S_samhd_776_1.FDvUp0 = &internal1_m776_FDvUp0;
  S_samhd_776_1.FDvDw0 = &internal1_m776_FDvDw0;
  S_samhd_776_1.BlDv0 = &internal1_m776_BlDv0;
  S_samhd_776_1.Pkv0 = &internal1_m776_Pkv0;
  S_samhd_776_1.Pkav0 = &internal1_m776_Pkav0;
  S_samhd_776_1.Zkv0 = &internal1_m776_Zkv0;
  S_samhd_776_1.Zkav0 = &internal1_m776_Zkav0;
  S_samhd_776_1.txNm = &internal1_m776_txNm;
  S_samhd_776_1.txSm = &internal1_m776_txSm;
  S_samhd_776_1.txHr = &internal1_m776_txHr;
  S_samhd_776_1.txLd = &internal1_m776_txLd;
  S_samhd_776_1.fef = &internal1_m776_fef;
  S_samhd_776_1.FirstEnterFlag = &bFirstEnterFlag;
  S_samhd_358_1.DvUp0 = &internal1_m358_DvUp0;
  S_samhd_358_1.DvDw0 = &internal1_m358_DvDw0;
  S_samhd_358_1.FDvUp0 = &internal1_m358_FDvUp0;
  S_samhd_358_1.FDvDw0 = &internal1_m358_FDvDw0;
  S_samhd_358_1.BlDv0 = &internal1_m358_BlDv0;
  S_samhd_358_1.Pkv0 = &internal1_m358_Pkv0;
  S_samhd_358_1.Pkav0 = &internal1_m358_Pkav0;
  S_samhd_358_1.Zkv0 = &internal1_m358_Zkv0;
  S_samhd_358_1.Zkav0 = &internal1_m358_Zkav0;
  S_samhd_358_1.txNm = &internal1_m358_txNm;
  S_samhd_358_1.txSm = &internal1_m358_txSm;
  S_samhd_358_1.txHr = &internal1_m358_txHr;
  S_samhd_358_1.txLd = &internal1_m358_txLd;
  S_samhd_358_1.fef = &internal1_m358_fef;
  S_samhd_358_1.FirstEnterFlag = &bFirstEnterFlag;
  S_samhd_387_1.DvUp0 = &internal1_m387_DvUp0;
  S_samhd_387_1.DvDw0 = &internal1_m387_DvDw0;
  S_samhd_387_1.FDvUp0 = &internal1_m387_FDvUp0;
  S_samhd_387_1.FDvDw0 = &internal1_m387_FDvDw0;
  S_samhd_387_1.BlDv0 = &internal1_m387_BlDv0;
  S_samhd_387_1.Pkv0 = &internal1_m387_Pkv0;
  S_samhd_387_1.Pkav0 = &internal1_m387_Pkav0;
  S_samhd_387_1.Zkv0 = &internal1_m387_Zkv0;
  S_samhd_387_1.Zkav0 = &internal1_m387_Zkav0;
  S_samhd_387_1.txNm = &internal1_m387_txNm;
  S_samhd_387_1.txSm = &internal1_m387_txSm;
  S_samhd_387_1.txHr = &internal1_m387_txHr;
  S_samhd_387_1.txLd = &internal1_m387_txLd;
  S_samhd_387_1.fef = &internal1_m387_fef;
  S_samhd_387_1.FirstEnterFlag = &bFirstEnterFlag;
  S_samhd_381_1.DvUp0 = &internal1_m381_DvUp0;
  S_samhd_381_1.DvDw0 = &internal1_m381_DvDw0;
  S_samhd_381_1.FDvUp0 = &internal1_m381_FDvUp0;
  S_samhd_381_1.FDvDw0 = &internal1_m381_FDvDw0;
  S_samhd_381_1.BlDv0 = &internal1_m381_BlDv0;
  S_samhd_381_1.Pkv0 = &internal1_m381_Pkv0;
  S_samhd_381_1.Pkav0 = &internal1_m381_Pkav0;
  S_samhd_381_1.Zkv0 = &internal1_m381_Zkv0;
  S_samhd_381_1.Zkav0 = &internal1_m381_Zkav0;
  S_samhd_381_1.txNm = &internal1_m381_txNm;
  S_samhd_381_1.txSm = &internal1_m381_txSm;
  S_samhd_381_1.txHr = &internal1_m381_txHr;
  S_samhd_381_1.txLd = &internal1_m381_txLd;
  S_samhd_381_1.fef = &internal1_m381_fef;
  S_samhd_381_1.FirstEnterFlag = &bFirstEnterFlag;
  S_rs_732_1.q0 = &internal1_m732_q0;
  S_rs_729_1.q0 = &internal1_m729_q0;
  S_scalzz_187_2.c = &fEM_A3UP04RDU;
  S_scalzz_187_2.d = &fEM_A3UP03RDU;
  S_scalzz_185_2.c = &fEM_A3UP04RDU;
  S_scalzz_185_2.d = &fEM_A3UP03RDU;
  S_tprg_214_2.e = &fEM_A3UP85RDU;
  S_tprg_214_2.f = &fEM_A3UP86RDU;
  S_tprg_214_2.c = &fEM_A3UP87RDU;
  S_tprg_214_2.d = &fEM_A3UP88RDU;
  S_tprg_210_2.e = &fEM_A3UP85RDU;
  S_tprg_210_2.f = &fEM_A3UP86RDU;
  S_tprg_210_2.c = &fEM_A3UP87RDU;
  S_tprg_210_2.d = &fEM_A3UP88RDU;
  S_drg_199_2.e = &fEM_A3UP43RDU;
  S_drg_199_2.f = &fEM_A3UP44RDU;
  S_drg_204_2.e = &fEM_A3UP53RDU;
  S_drg_204_2.f = &fEM_A3UP54RDU;
  S_drg_189_2.e = &fEM_A3UP43RDU;
  S_drg_189_2.f = &fEM_A3UP44RDU;
  S_drg_196_2.e = &fEM_A3UP53RDU;
  S_drg_196_2.f = &fEM_A3UP54RDU;
  S_enctkb_16_2.LeftBound = &dEM_A1UC06UDU;
  S_enctkb_16_2.RightBound = &dEM_A1UC05UDU;
  S_enctkb_16_2.C = &fEM_A1UC03RDU;
  S_enctkb_108_2.LeftBound = &dEM_A8UC06UDU;
  S_enctkb_108_2.RightBound = &dEM_A8UC05UDU;
  S_enctkb_108_2.C = &fEM_A8UC03RDU;
  S_enctkb_112_2.LeftBound = &dEM_A8UC06UDU;
  S_enctkb_112_2.RightBound = &dEM_A8UC05UDU;
  S_enctkb_112_2.C = &fEM_A8UC03RDU;
  S_enctkb_75_2.LeftBound = &dEM_A3UC06UDU;
  S_enctkb_75_2.RightBound = &dEM_A3UC05UDU;
  S_enctkb_75_2.C = &fEM_A3UC03RDU;
  S_enctkb_77_2.LeftBound = &dEM_A3UC06UDU;
  S_enctkb_77_2.RightBound = &dEM_A3UC05UDU;
  S_enctkb_77_2.C = &fEM_A3UC03RDU;
  S_enctkb_47_2.LeftBound = &dEM_A2UC06UDU;
  S_enctkb_47_2.RightBound = &dEM_A2UC05UDU;
  S_enctkb_47_2.C = &fEM_A2UC03RDU;
  S_enctkb_51_2.LeftBound = &dEM_A2UC06UDU;
  S_enctkb_51_2.RightBound = &dEM_A2UC05UDU;
  S_enctkb_51_2.C = &fEM_A2UC03RDU;
  S_enctkb_21_2.LeftBound = &dEM_A1UC06UDU;
  S_enctkb_21_2.RightBound = &dEM_A1UC05UDU;
  S_enctkb_21_2.C = &fEM_A1UC03RDU;
  S_abs_subf_2130_1.Delta = &fEM_A3UC08RDU;
  S_fsumo_79_1.x2 = &fEM_R0UN11RDU;
  S_bol_2195_1.x1 = &fEM_R0UN09RDU;
  S_irm_2141_1.Zn = &fEM_R0UN12RDU;
  S_irm_2141_1.MinDk = &fEM_R0UN13RDU;
  S_irm_2141_1.MaxKr = &fEM_R0UN14RDU;
  S_irm_2141_1.MaxTime = &fEM_R0UT20RDU;
  S_irm_2141_1.W2 = &fEM_R0UN15RDU;
  S_irm_2141_1.W3 = &fEM_R0UN25RDU;
  S_irm_2141_1.A1 = &fEM_R0UN16RDU;
  S_irm_2141_1.A0 = &fEM_R0UN17RDU;
  S_irm_2141_1.T1 = &fEM_R0UN18RDU;
  S_irm_2141_1.T0 = &fEM_R0UN19RDU;
  S_irm_2141_1.MT1 = &fEM_R0UN27RDU;
  S_irm_2141_1.MT0 = &fEM_R0UN26RDU;
  S_irm_2141_1.Nmin = &fEM_R0UN24RDU;
  S_abs_subf_1531_1.Delta = &fEM_A3UC07RDU;
  S_abs_subf_1508_1.Delta = &fEM_A3UC07RDU;
  S_abs_subf_1528_1.Delta = &fEM_A1UC07RDU;
  S_abs_subf_1507_1.Delta = &fEM_A1UC07RDU;
  S_bol_1298_1.x2 = &fEM_A3UC09RDU;
  S_bol_899_1.x2 = &fEM_A3UC09RDU;
  S_zpfs_1841_1.tz = &fEM_R0UL02RDU;
  S_zpfs_1839_1.tz = &fEM_R0UL02RDU;
  S_zpfs_1828_1.tz = &fEM_R0UL04RDU;
  S_abs_subf_1850_1.x1 = &fEM_R0UL02RDU;
  S_abs_subf_1850_1.Delta = &fEM_R0UL16RDU;
  S_abs_subf_1434_1.x1 = &fEM_R0UL05RDU;
  S_abs_subf_1434_1.Delta = &fEM_R0UL18RDU;
  S_abs_subf_1476_1.x1 = &fEM_R0UL07RDU;
  S_abs_subf_1476_1.Delta = &fEM_R0UL20RDU;
  S_abs_subf_1481_1.x1 = &fEM_R0UL25RDU;
  S_abs_subf_1481_1.Delta = &fEM_R0UL19RDU;
  S_abs_subf_1889_1.x2 = &fEM_R0UL03RDU;
  S_abs_subf_1889_1.Delta = &fEM_R0UL17RDU;
  S_zpfs_1864_1.tz = &fEM_R0UL21RDU;
  S_zpfs_1880_1.tz = &fEM_R0UL03RDU;
  S_zpfs_1877_1.tz = &fEM_R0UL03RDU;
  S_zpfs_1471_1.tz = &fEM_R0UL06RDU;
  S_zpfs_1421_1.tz = &fEM_R0UL04RDU;
  S_zpfs_827_1.tz = &fEM_A2UL83RDU;
  S_zpfs_197_1.tz = &fEM_A1UL03RDU;
  S_zpfs_516_1.tz = &fEM_A1UL03RDU;
  S_bol_1048_1.x2 = &fEM_R0UN80RDU;
  S_ovbs_2062_1.tz = &fEM_A9UZ04RDU;
  S_ovbs_1165_1.tz = &fEM_A4UZ04RDU;
  S_zpfs_1591_1.tz = &fEM_B8UL03RDU;
  S_zpfs_1131_1.tz = &fEM_B8UL03RDU;
  S_zpfs_1317_1.tz = &fEM_A3UL03RDU;
  S_zpfs_920_1.tz = &fEM_A3UL03RDU;
  S_zpfs_1224_1.tz = &fEM_A2UL03RDU;
  S_abs_subf_990_1.Delta = &fEM_B8UC01RDU;
  S_abs_subf_1003_1.Delta = &fEM_B8UC01RDU;
  S_samhd_2067_1.tzNm = &fEM_A9UZ05RDU;
  S_samhd_2067_1.tzSm = &fEM_A9UZ03RDU;
  S_samhd_2067_1.tzLd = &fEM_A9UZ04RDU;
  S_samhd_2061_1.tzNm = &fEM_A9UZ05RDU;
  S_samhd_2061_1.tzSm = &fEM_A9UZ03RDU;
  S_samhd_2061_1.tzLd = &fEM_A9UZ04RDU;
  S_noto_997_1.x = &lEM_R0MD01LC1;
  S_cnshd_1288_1.Dlt = &fEM_A3UC08RDU;
  S_cnshd_1288_1.DltRet = &fEM_A3UC07RDU;
  S_cnshd_1288_1.Tim = &fEM_A3UL01RDU;
  S_cnshd_1288_1.Kpr = &fEM_A3UC02RDU;
  S_fnapb_1316_1.Trz = &fEM_B8UV04RDU;
  S_fnapb_1316_1.Delta = &fEM_A3UV01RDU;
  S_fnapb_1316_1.MDelta = &fEM_A3UV02RDU;
  S_fnapb_1316_1.p = &fEM_A3UC06RDU;
  S_fnapb_1316_1.pl = &fEM_A3UC05RDU;
  S_fnapb_1316_1.tz = &fEM_A3UL04RDU;
  S_fnapb_1316_1.tnm = &fEM_A3UL05RDU;
  S_fnapb_1316_1.tzZS = &fEM_A3UL03RDU;
  S_cnshd_886_1.Dlt = &fEM_A3UC08RDU;
  S_cnshd_886_1.DltRet = &fEM_A3UC07RDU;
  S_cnshd_886_1.Tim = &fEM_A3UL01RDU;
  S_cnshd_886_1.Kpr = &fEM_A3UC02RDU;
  S_fnapb_919_1.Trz = &fEM_B8UV04RDU;
  S_fnapb_919_1.Delta = &fEM_A3UV01RDU;
  S_fnapb_919_1.MDelta = &fEM_A3UV02RDU;
  S_fnapb_919_1.p = &fEM_A3UC06RDU;
  S_fnapb_919_1.pl = &fEM_A3UC05RDU;
  S_fnapb_919_1.tz = &fEM_A3UL04RDU;
  S_fnapb_919_1.tnm = &fEM_A3UL05RDU;
  S_fnapb_919_1.tzZS = &fEM_A3UL03RDU;
  S_cnshd_488_1.Dlt = &fEM_A1UC08RDU;
  S_cnshd_488_1.DltRet = &fEM_A1UC07RDU;
  S_cnshd_488_1.Tim = &fEM_A1UL01RDU;
  S_cnshd_488_1.Kpr = &fEM_A1UC02RDU;
  S_fnapb_515_1.Trz = &fEM_B8UV04RDU;
  S_fnapb_515_1.Delta = &fEM_A1UV01RDU;
  S_fnapb_515_1.MDelta = &fEM_A1UV02RDU;
  S_fnapb_515_1.p = &fEM_A1UC06RDU;
  S_fnapb_515_1.pl = &fEM_A1UC05RDU;
  S_fnapb_515_1.tz = &fEM_A1UL04RDU;
  S_fnapb_515_1.tnm = &fEM_A1UL05RDU;
  S_fnapb_515_1.tzZS = &fEM_A1UL03RDU;
  S_cnshd_167_1.Dlt = &fEM_A1UC08RDU;
  S_cnshd_167_1.DltRet = &fEM_A1UC07RDU;
  S_cnshd_167_1.Tim = &fEM_A1UL01RDU;
  S_cnshd_167_1.Kpr = &fEM_A1UC02RDU;
  S_fnapb_196_1.Trz = &fEM_B8UV04RDU;
  S_fnapb_196_1.Delta = &fEM_A1UV01RDU;
  S_fnapb_196_1.MDelta = &fEM_A1UV02RDU;
  S_fnapb_196_1.p = &fEM_A1UC06RDU;
  S_fnapb_196_1.pl = &fEM_A1UC05RDU;
  S_fnapb_196_1.tz = &fEM_A1UL04RDU;
  S_fnapb_196_1.tnm = &fEM_A1UL05RDU;
  S_fnapb_196_1.tzZS = &fEM_A1UL03RDU;
  S_samhd_459_1.tzNm = &fEM_R1UZ05RDU;
  S_samhd_459_1.tzSm = &fEM_R1UZ03RDU;
  S_samhd_459_1.tzLd = &fEM_R1UZ04RDU;
  S_samhd_453_1.tzNm = &fEM_R1UZ05RDU;
  S_samhd_453_1.tzSm = &fEM_R1UZ03RDU;
  S_samhd_453_1.tzLd = &fEM_R1UZ04RDU;
  S_cnshd_806_1.Dlt = &fEM_A2UC08RDU;
  S_cnshd_806_1.DltRet = &fEM_A2UC07RDU;
  S_cnshd_806_1.Tim = &fEM_A2UL01RDU;
  S_cnshd_806_1.Kpr = &fEM_A2UC02RDU;
  S_fnapb_826_1.Trz = &fEM_B8UV04RDU;
  S_fnapb_826_1.Delta = &fEM_A2UV01RDU;
  S_fnapb_826_1.MDelta = &fEM_A2UV02RDU;
  S_fnapb_826_1.p = &fEM_A2UC06RDU;
  S_fnapb_826_1.pl = &fEM_A2UC05RDU;
  S_fnapb_826_1.tz = &fEM_A2UL04RDU;
  S_fnapb_826_1.tnm = &fEM_A2UL05RDU;
  S_fnapb_826_1.tzZS = &fEM_A2UL83RDU;
  S_cnshd_1570_1.Dlt = &fEM_B8UC01RDU;
  S_cnshd_1570_1.DltRet = &fEM_B8UC02RDU;
  S_cnshd_1570_1.Tim = &fEM_B8UL01RDU;
  S_cnshd_1109_1.Dlt = &fEM_B8UC01RDU;
  S_cnshd_1109_1.DltRet = &fEM_B8UC02RDU;
  S_cnshd_1109_1.Tim = &fEM_B8UL01RDU;
  S_noto_599_1.x = &lEM_R0MD01LC1;
  S_cnshd_1191_1.Dlt = &fEM_A2UC08RDU;
  S_cnshd_1191_1.DltRet = &fEM_A2UC07RDU;
  S_cnshd_1191_1.Tim = &fEM_A2UL01RDU;
  S_cnshd_1191_1.Kpr = &fEM_A2UC02RDU;
  S_fnapb_1226_1.Trz = &fEM_B8UV04RDU;
  S_fnapb_1226_1.Delta = &fEM_A2UV01RDU;
  S_fnapb_1226_1.MDelta = &fEM_A2UV02RDU;
  S_fnapb_1226_1.p = &fEM_A2UC06RDU;
  S_fnapb_1226_1.pl = &fEM_A2UC05RDU;
  S_fnapb_1226_1.tz = &fEM_A2UL04RDU;
  S_fnapb_1226_1.tnm = &fEM_A2UL05RDU;
  S_fnapb_1226_1.tzZS = &fEM_A2UL03RDU;
  S_samhd_1573_1.tzNm = &fEM_B8UL05RDU;
  S_samhd_1573_1.tzSm = &fEM_B8UL03RDU;
  S_samhd_1573_1.tzLd = &fEM_B8UL07RDU;
  S_fnapb_1590_1.Vz = &fEM_B8UV03RDU;
  S_fnapb_1590_1.Trz = &fEM_B8UV04RDU;
  S_fnapb_1590_1.Delta = &fEM_B8UV01RDU;
  S_fnapb_1590_1.MDelta = &fEM_B8UV02RDU;
  S_fnapb_1590_1.p = &fEM_B8UC06RDU;
  S_fnapb_1590_1.pl = &fEM_B8UC05RDU;
  S_fnapb_1590_1.tz = &fEM_B8UL04RDU;
  S_fnapb_1590_1.tnm = &fEM_B8UL05RDU;
  S_fnapb_1590_1.tzZS = &fEM_B8UL03RDU;
  S_samhd_1113_1.tzNm = &fEM_B8UL05RDU;
  S_samhd_1113_1.tzSm = &fEM_B8UL03RDU;
  S_samhd_1113_1.tzLd = &fEM_B8UL07RDU;
  S_fnapb_1130_1.Vz = &fEM_B8UV03RDU;
  S_fnapb_1130_1.Trz = &fEM_B8UV04RDU;
  S_fnapb_1130_1.Delta = &fEM_B8UV01RDU;
  S_fnapb_1130_1.MDelta = &fEM_B8UV02RDU;
  S_fnapb_1130_1.p = &fEM_B8UC06RDU;
  S_fnapb_1130_1.pl = &fEM_B8UC05RDU;
  S_fnapb_1130_1.tz = &fEM_B8UL04RDU;
  S_fnapb_1130_1.tnm = &fEM_B8UL06RDU;
  S_fnapb_1130_1.tzZS = &fEM_B8UL03RDU;
  S_samhd_1167_1.tzNm = &fEM_A4UZ05RDU;
  S_samhd_1167_1.tzSm = &fEM_A4UZ03RDU;
  S_samhd_1167_1.tzLd = &fEM_A4UZ04RDU;
  S_samhd_1157_1.tzNm = &fEM_A4UZ05RDU;
  S_samhd_1157_1.tzSm = &fEM_A4UZ03RDU;
  S_samhd_1157_1.tzLd = &fEM_A4UZ04RDU;
  S_samhd_780_1.tzNm = &fEM_A5UZ05RDU;
  S_samhd_780_1.tzSm = &fEM_A5UZ03RDU;
  S_samhd_780_1.tzLd = &fEM_A5UZ04RDU;
  S_samhd_776_1.tzNm = &fEM_A5UZ05RDU;
  S_samhd_776_1.tzSm = &fEM_A5UZ03RDU;
  S_samhd_776_1.tzLd = &fEM_A5UZ04RDU;
  S_samhd_358_1.tzNm = &fEM_R4UZ05RDU;
  S_samhd_358_1.tzSm = &fEM_R4UZ03RDU;
  S_samhd_358_1.tzLd = &fEM_R4UZ04RDU;
  S_samhd_387_1.tzNm = &fEM_A6UZ05RDU;
  S_samhd_387_1.tzSm = &fEM_A6UZ03RDU;
  S_samhd_387_1.tzLd = &fEM_A6UZ04RDU;
  S_samhd_381_1.tzNm = &fEM_A6UZ05RDU;
  S_samhd_381_1.tzSm = &fEM_A6UZ03RDU;
  S_samhd_381_1.tzLd = &fEM_A6UZ04RDU;
  for( i=0;i<10;i++ )
    array_m324_rz_1[i] = &(&internal1_m324_rz)[i];
  for( i=0;i<10;i++ )
    array_m267_rz_1[i] = &(&internal1_m267_rz)[i];
  for( i=0;i<6;i++ )
    array_m1389_rz_1[i] = &(&internal1_m1389_rz)[i];
  for( i=0;i<60;i++ )
    array_m1316_x0_1[i] = &(&internal1_m1316_x0)[i];
  for( i=0;i<60;i++ )
    array_m1316_tim0_1[i] = &(&internal1_m1316_tim0)[i];
  for( i=0;i<60;i++ )
    array_m919_x0_1[i] = &(&internal1_m919_x0)[i];
  for( i=0;i<60;i++ )
    array_m919_tim0_1[i] = &(&internal1_m919_tim0)[i];
  for( i=0;i<150;i++ )
    array_m515_x0_1[i] = &(&internal1_m515_x0)[i];
  for( i=0;i<150;i++ )
    array_m515_tim0_1[i] = &(&internal1_m515_tim0)[i];
  for( i=0;i<150;i++ )
    array_m196_x0_1[i] = &(&internal1_m196_x0)[i];
  for( i=0;i<150;i++ )
    array_m196_tim0_1[i] = &(&internal1_m196_tim0)[i];
  for( i=0;i<80;i++ )
    array_m826_x0_1[i] = &(&internal1_m826_x0)[i];
  for( i=0;i<80;i++ )
    array_m826_tim0_1[i] = &(&internal1_m826_tim0)[i];
  for( i=0;i<80;i++ )
    array_m1226_x0_1[i] = &(&internal1_m1226_x0)[i];
  for( i=0;i<80;i++ )
    array_m1226_tim0_1[i] = &(&internal1_m1226_tim0)[i];
  for( i=0;i<20;i++ )
    array_m1590_x0_1[i] = &(&internal1_m1590_x0)[i];
  for( i=0;i<20;i++ )
    array_m1590_tim0_1[i] = &(&internal1_m1590_tim0)[i];
  for( i=0;i<20;i++ )
    array_m1130_x0_1[i] = &(&internal1_m1130_x0)[i];
  for( i=0;i<20;i++ )
    array_m1130_tim0_1[i] = &(&internal1_m1130_tim0)[i];
  array_m2159_a_1[0] = &fEM_R0UN70LDU;
  array_m2159_a_1[1] = &fEM_R0UN71LDU;
  array_m2159_a_1[2] = &fEM_R0UN72LDU;
  array_m2159_a_1[3] = &fEM_R0UN73LDU;
  array_m2159_a_1[4] = &fEM_R0UN74LDU;
  array_m2159_a_1[5] = &fEM_R0UN75LDU;
  array_m2159_b_1[0] = &fEM_R0UN80LDU;
  array_m2159_b_1[1] = &fEM_R0UN81LDU;
  array_m2159_b_1[2] = &fEM_R0UN82LDU;
  array_m2159_b_1[3] = &fEM_R0UN83LDU;
  array_m2159_b_1[4] = &fEM_R0UN84LDU;
  array_m2159_b_1[5] = &fEM_R0UN85LDU;
  array_m83_x_1[0] = &fEM_R0UN01RDU;
  array_m83_x_1[1] = &fEM_R0UN02RDU;
  array_m83_x_1[2] = &fEM_R0UN03RDU;
  array_m83_x_1[3] = &fEM_R0UN04RDU;
  array_m83_x_1[4] = &fEM_R0UN05RDU;
  array_m83_x_1[5] = &fEM_R0UN06RDU;
  array_m83_x_1[6] = &fEM_R0UN07RDU;
  array_m83_x_1[7] = &fEM_R0UN08RDU;
  array_m1288_Lt_fw_1[0] = &fEM_A3UC81RDU;
  array_m1288_Vr_fw_1[0] = &iEM_A3UV01IDU;
  array_m1288_Lt_bw_1[0] = &fEM_A3UC82RDU;
  array_m1288_Vr_bw_1[0] = &iEM_A3UV02IDU;
  array_m886_Lt_fw_1[0] = &fEM_A3UC81RDU;
  array_m886_Vr_fw_1[0] = &iEM_A3UV01IDU;
  array_m886_Lt_bw_1[0] = &fEM_A3UC82RDU;
  array_m886_Vr_bw_1[0] = &iEM_A3UV02IDU;
  array_m488_Lt_fw_1[0] = &fEM_A1UC81RDU;
  array_m488_Lt_fw_1[1] = &fEM_A1UC82RDU;
  array_m488_Vr_fw_1[0] = &iEM_A1UV01IDU;
  array_m488_Vr_fw_1[1] = &iEM_A1UV02IDU;
  array_m488_Lt_bw_1[0] = &fEM_A1UC83RDU;
  array_m488_Vr_bw_1[0] = &iEM_A1UV03IDU;
  array_m167_Lt_fw_1[0] = &fEM_A1UC81RDU;
  array_m167_Lt_fw_1[1] = &fEM_A1UC82RDU;
  array_m167_Vr_fw_1[0] = &iEM_A1UV01IDU;
  array_m167_Vr_fw_1[1] = &iEM_A1UV02IDU;
  array_m167_Lt_bw_1[0] = &fEM_A1UC83RDU;
  array_m167_Vr_bw_1[0] = &iEM_A1UV03IDU;
  array_m806_Lt_fw_1[0] = &fEM_A2UC81RDU;
  array_m806_Lt_fw_1[1] = &fEM_A2UC82RDU;
  array_m806_Vr_fw_1[0] = &iEM_A2UV01IDU;
  array_m806_Vr_fw_1[1] = &iEM_A2UV02IDU;
  array_m806_Lt_bw_1[0] = &fEM_A2UC83RDU;
  array_m806_Vr_bw_1[0] = &iEM_A2UV03CDU;
  array_m1191_Lt_fw_1[0] = &fEM_A2UC81RDU;
  array_m1191_Lt_fw_1[1] = &fEM_A2UC82RDU;
  array_m1191_Vr_fw_1[0] = &iEM_A2UV01IDU;
  array_m1191_Vr_fw_1[1] = &iEM_A2UV02IDU;
  array_m1191_Lt_bw_1[0] = &fEM_A2UC83RDU;
  array_m1191_Vr_bw_1[0] = &iEM_A2UV03CDU;
}
