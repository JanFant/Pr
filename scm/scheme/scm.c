#include "scm.h"
extern  func_ext1();
// ��
//  ��������� ���������� ����� D:\md\pti\pr\scm\scheme\scm.tpr

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
float takt;// ����� � ��������
__int16 itakt;// ����� � �������������
__int16 dtakt;// ����� � �������� �����������
unsigned long sys_time;// ��������� ����� � ������������, �� ������� ��� ������
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
      // ��� ����������� ��������� ��� ������� � ������� � AllPars
      // � ������ ����� ��������� ��������
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
       ShowMessage(AnsiString("������������ ���� ��������� ") + AnsiString(Name) + AnsiString(" � ����� ") + AnsiString(SchemaName));
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

/* ���������� ������� */
#include <ampl.h>
#include <and2.h>
#include <and5.h>
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
#include <ocham.h>
#include <or2.h>
#include <orn.h>
#include <orrsim.h>
#include <ovb1.h>
#include <period.h>
#include <react.h>
#include <rs.h>
#include <to3val.h>
#include <toao.h>
#include <twobool.h>
#include <vchs.h>
#include <zpfs.h>

/* ����������� ���������� ���������� */
#define bFirstEnterFlag (*((psbool)(InternalBuf+0x0)))
#define internal1_m1118_Out10 (*((psbool)(InternalBuf+0x2))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1117_Out10 (*((psbool)(InternalBuf+0x4))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m943_Out10 (*((psbool)(InternalBuf+0x6))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m942_Out10 (*((psbool)(InternalBuf+0x8))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m941_Out10 (*((psbool)(InternalBuf+0xA))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m940_Out10 (*((psbool)(InternalBuf+0xC))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m691_Out10 (*((psbool)(InternalBuf+0xE))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m690_Out10 (*((psbool)(InternalBuf+0x10))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m669_Out10 (*((psbool)(InternalBuf+0x12))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m668_Out10 (*((psbool)(InternalBuf+0x14))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m689_Out10 (*((psbool)(InternalBuf+0x16))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m688_Out10 (*((psbool)(InternalBuf+0x18))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m667_Out10 (*((psbool)(InternalBuf+0x1A))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m666_Out10 (*((psbool)(InternalBuf+0x1C))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m527_Out10 (*((psbool)(InternalBuf+0x1E))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m545_Out10 (*((psbool)(InternalBuf+0x20))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m409_Out10 (*((psbool)(InternalBuf+0x22))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m486_q0 (*((psbool)(InternalBuf+0x24))) /*q0 - ���������� ��������*/
#define internal1_m487_q0 (*((psbool)(InternalBuf+0x26))) /*q0 - ���������� ��������*/
#define internal1_m472_q0 (*((psbool)(InternalBuf+0x28))) /*q0 - ���������� ��������*/
#define internal1_m473_q0 (*((psbool)(InternalBuf+0x2A))) /*q0 - ���������� ��������*/
#define internal1_m642_tx (*((psfloat)(InternalBuf+0x2C))) /*tx - ����� ����������� ���*/
#define internal1_m642_y0 (*((pschar)(InternalBuf+0x31))) /*y0*/
#define internal1_m630_tx (*((psfloat)(InternalBuf+0x33))) /*tx - ����� ����������� ���*/
#define internal1_m630_y0 (*((pschar)(InternalBuf+0x38))) /*y0*/
#define internal1_m616_tx (*((psfloat)(InternalBuf+0x3A))) /*tx - ����� ����������� ���*/
#define internal1_m616_y0 (*((pschar)(InternalBuf+0x3F))) /*y0*/
#define internal1_m614_tx (*((psfloat)(InternalBuf+0x41))) /*tx - ����� ����������� ���*/
#define internal1_m614_y0 (*((pschar)(InternalBuf+0x46))) /*y0*/
#define internal1_m206_Out10 (*((psbool)(InternalBuf+0x48))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m224_Out10 (*((psbool)(InternalBuf+0x4A))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m41_Out10 (*((psbool)(InternalBuf+0x4C))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m56_Out10 (*((psbool)(InternalBuf+0x4E))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1241_Out10 (*((psbool)(InternalBuf+0x50))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1238_Out10 (*((psbool)(InternalBuf+0x52))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1237_Out10 (*((psbool)(InternalBuf+0x54))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1240_Xtek0 (*((psfloat)(InternalBuf+0x56))) /*Xtek0 - ��������� ��������� �� ������� ����, ��*/
#define internal1_m1226_Xtek0 (*((psfloat)(InternalBuf+0x5B))) /*Xtek0 - ��������� ��������� �� ������� ����, ��*/
#define internal1_m1227_Out10 (*((psbool)(InternalBuf+0x60))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1224_Out10 (*((psbool)(InternalBuf+0x62))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1223_Out10 (*((psbool)(InternalBuf+0x64))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m981_Out10 (*((psbool)(InternalBuf+0x66))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m962_Out10 (*((psbool)(InternalBuf+0x68))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m961_Out10 (*((psbool)(InternalBuf+0x6A))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m960_Out10 (*((psbool)(InternalBuf+0x6C))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1139_Out10 (*((psbool)(InternalBuf+0x6E))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1141_Out10 (*((psbool)(InternalBuf+0x70))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1138_Out10 (*((psbool)(InternalBuf+0x72))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1140_Out10 (*((psbool)(InternalBuf+0x74))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1114_Out10 (*((psbool)(InternalBuf+0x76))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1115_Out10 (*((psbool)(InternalBuf+0x78))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1113_Out10 (*((psbool)(InternalBuf+0x7A))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1112_Out10 (*((psbool)(InternalBuf+0x7C))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m976_Out10 (*((psbool)(InternalBuf+0x7E))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m928_Out10 (*((psbool)(InternalBuf+0x80))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m927_Out10 (*((psbool)(InternalBuf+0x82))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m926_Out10 (*((psbool)(InternalBuf+0x84))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m925_Out10 (*((psbool)(InternalBuf+0x86))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m977_Out10 (*((psbool)(InternalBuf+0x88))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m958_Out10 (*((psbool)(InternalBuf+0x8A))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1116_Out10 (*((psbool)(InternalBuf+0x8C))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m959_Out10 (*((psbool)(InternalBuf+0x8E))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m957_Out10 (*((psbool)(InternalBuf+0x90))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m978_Out10 (*((psbool)(InternalBuf+0x92))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m956_Out10 (*((psbool)(InternalBuf+0x94))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m939_Out10 (*((psbool)(InternalBuf+0x96))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m924_Out10 (*((psbool)(InternalBuf+0x98))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m543_Out10 (*((psbool)(InternalBuf+0x9A))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m419_Xtek0 (*((psfloat)(InternalBuf+0x9C))) /*Xtek0 - ��������� ��������� �� ������� ����, ��*/
#define internal1_m410_Out10 (*((psbool)(InternalBuf+0xA1))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m412_Out10 (*((psbool)(InternalBuf+0xA3))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m411_Out10 (*((psbool)(InternalBuf+0xA5))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1154_Out10 (*((psbool)(InternalBuf+0xA7))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1155_Out10 (*((psbool)(InternalBuf+0xA9))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1153_Out10 (*((psbool)(InternalBuf+0xAB))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m980_Out10 (*((psbool)(InternalBuf+0xAD))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m704_Out10 (*((psbool)(InternalBuf+0xAF))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m705_Out10 (*((psbool)(InternalBuf+0xB1))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m702_Out10 (*((psbool)(InternalBuf+0xB3))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m703_Out10 (*((psbool)(InternalBuf+0xB5))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m561_Out10 (*((psbool)(InternalBuf+0xB7))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m560_Out10 (*((psbool)(InternalBuf+0xB9))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1135_Xtek0 (*((psfloat)(InternalBuf+0xBB))) /*Xtek0 - ��������� ��������� �� ������� ����, ��*/
#define internal1_m1137_Xtek0 (*((psfloat)(InternalBuf+0xC0))) /*Xtek0 - ��������� ��������� �� ������� ����, ��*/
#define internal1_m701_Out10 (*((psbool)(InternalBuf+0xC5))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m685_Out10 (*((psbool)(InternalBuf+0xC7))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m665_Out10 (*((psbool)(InternalBuf+0xC9))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m684_Out10 (*((psbool)(InternalBuf+0xCB))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m664_Out10 (*((psbool)(InternalBuf+0xCD))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m337_Out10 (*((psbool)(InternalBuf+0xCF))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m336_Out10 (*((psbool)(InternalBuf+0xD1))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m321_Out10 (*((psbool)(InternalBuf+0xD3))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m320_Out10 (*((psbool)(InternalBuf+0xD5))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m562_Out10 (*((psbool)(InternalBuf+0xD7))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m350_Out10 (*((psbool)(InternalBuf+0xD9))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m334_Xtek0 (*((psfloat)(InternalBuf+0xDB))) /*Xtek0 - ��������� ��������� �� ������� ����, ��*/
#define internal1_m349_Out10 (*((psbool)(InternalBuf+0xE0))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m347_Out10 (*((psbool)(InternalBuf+0xE2))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m327_Xtek0 (*((psfloat)(InternalBuf+0xE4))) /*Xtek0 - ��������� ��������� �� ������� ����, ��*/
#define internal1_m348_Out10 (*((psbool)(InternalBuf+0xE9))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m319_Out10 (*((psbool)(InternalBuf+0xEB))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m335_Out10 (*((psbool)(InternalBuf+0xED))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m431_Out10 (*((psbool)(InternalBuf+0xEF))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m432_Xtek0 (*((psfloat)(InternalBuf+0xF1))) /*Xtek0 - ��������� ��������� �� ������� ����, ��*/
#define internal1_m430_Out10 (*((psbool)(InternalBuf+0xF6))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m429_Out10 (*((psbool)(InternalBuf+0xF8))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m428_Out10 (*((psbool)(InternalBuf+0xFA))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m979_Out10 (*((psbool)(InternalBuf+0xFC))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m150_Out10 (*((psbool)(InternalBuf+0xFE))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m149_Out10 (*((psbool)(InternalBuf+0x100))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1102_Out10 (*((psbool)(InternalBuf+0x102))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1093_Out10 (*((psbool)(InternalBuf+0x104))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1082_tst (*((psfloat)(InternalBuf+0x106))) /*- ������ ������� �������� ��������� ��������*/
#define internal1_m1082_trz (*((psfloat)(InternalBuf+0x110))) /*- ������ ������� �������� ���������� �������*/
#define internal1_m1082_N1 (*((psfloat)(InternalBuf+0x11A))) /*- ������ �������� �������� � ������ ������*/
#define internal1_m1082_N2 (*((psfloat)(InternalBuf+0x124))) /*- ������ �������� �������� � ����� ������*/
#define internal1_m1082_Period0 (*((psfloat)(InternalBuf+0x12E))) /*Per - ������ ������� ��*/
#define internal1_m1082_MyFirstEnterFlag (*((psbool)(InternalBuf+0x133))) /* FirstEnterFlag*/
#define internal1_m1048_Nk (*((psint)(InternalBuf+0x135))) /*Nk - ������� ������*/
#define internal1_m1043_Out10 (*((psbool)(InternalBuf+0x138))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1035_Out10 (*((psbool)(InternalBuf+0x13A))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m1024_tst (*((psfloat)(InternalBuf+0x13C))) /*- ������ ������� �������� ��������� ��������*/
#define internal1_m1024_trz (*((psfloat)(InternalBuf+0x146))) /*- ������ ������� �������� ���������� �������*/
#define internal1_m1024_N1 (*((psfloat)(InternalBuf+0x150))) /*- ������ �������� �������� � ������ ������*/
#define internal1_m1024_N2 (*((psfloat)(InternalBuf+0x15A))) /*- ������ �������� �������� � ����� ������*/
#define internal1_m1024_Period0 (*((psfloat)(InternalBuf+0x164))) /*Per - ������ ������� ��*/
#define internal1_m1024_MyFirstEnterFlag (*((psbool)(InternalBuf+0x169))) /* FirstEnterFlag*/
#define internal1_m994_Nk (*((psint)(InternalBuf+0x16B))) /*Nk - ������� ������*/
#define internal1_m915_Out10 (*((psbool)(InternalBuf+0x16E))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m905_Out10 (*((psbool)(InternalBuf+0x170))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m896_tst (*((psfloat)(InternalBuf+0x172))) /*- ������ ������� �������� ��������� ��������*/
#define internal1_m896_trz (*((psfloat)(InternalBuf+0x17C))) /*- ������ ������� �������� ���������� �������*/
#define internal1_m896_N1 (*((psfloat)(InternalBuf+0x186))) /*- ������ �������� �������� � ������ ������*/
#define internal1_m896_N2 (*((psfloat)(InternalBuf+0x190))) /*- ������ �������� �������� � ����� ������*/
#define internal1_m896_Period0 (*((psfloat)(InternalBuf+0x19A))) /*Per - ������ ������� ��*/
#define internal1_m896_MyFirstEnterFlag (*((psbool)(InternalBuf+0x19F))) /* FirstEnterFlag*/
#define internal1_m862_Nk (*((psint)(InternalBuf+0x1A1))) /*Nk - ������� ������*/
#define internal1_m849_Out10 (*((psbool)(InternalBuf+0x1A4))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m838_Out10 (*((psbool)(InternalBuf+0x1A6))) /*Out10 (psbool) - ������� �������� ��������� �������*/
#define internal1_m841_tst (*((psfloat)(InternalBuf+0x1A8))) /*- ������ ������� �������� ��������� ��������*/
#define internal1_m841_trz (*((psfloat)(InternalBuf+0x1B2))) /*- ������ ������� �������� ���������� �������*/
#define internal1_m841_N1 (*((psfloat)(InternalBuf+0x1BC))) /*- ������ �������� �������� � ������ ������*/
#define internal1_m841_N2 (*((psfloat)(InternalBuf+0x1C6))) /*- ������ �������� �������� � ����� ������*/
#define internal1_m841_Period0 (*((psfloat)(InternalBuf+0x1D0))) /*Per - ������ ������� ��*/
#define internal1_m841_MyFirstEnterFlag (*((psbool)(InternalBuf+0x1D5))) /* FirstEnterFlag*/
#define internal1_m804_Nk (*((psint)(InternalBuf+0x1D7))) /*Nk - ������� ������*/
#define internal1_m195_tx (*((psint)(InternalBuf+0x1DA))) /*tx - ���������� ��������*/
#define internal1_m25_tx (*((psint)(InternalBuf+0x1DD))) /*tx - ���������� ��������*/
#define internal1_m476_Pav0 (*((psbool)(InternalBuf+0x1E0))) /* - ���.��������� ����������� ���������*/
#define internal1_m476_Zav0 (*((psbool)(InternalBuf+0x1E2))) /* - ���.��������� ����������� ���������*/
#define internal1_m476_Pv0 (*((psbool)(InternalBuf+0x1E4))) /* - ���. ����������� ���������*/
#define internal1_m476_Zv0 (*((psbool)(InternalBuf+0x1E6))) /* - ���. ����������� ���������*/
#define internal1_m476_RA00 (*((psbool)(InternalBuf+0x1E8))) /* - ��������� ������� ������*/
#define internal1_m476_RA10 (*((psbool)(InternalBuf+0x1EA))) /* - ��������� ������� �����*/
#define internal1_m476_MyFirstEnterFlag (*((psbool)(InternalBuf+0x1EC))) /*MyFirstEnterFlag*/
#define internal1_m490_Pav0 (*((psbool)(InternalBuf+0x1EE))) /* - ���.��������� ����������� ���������*/
#define internal1_m490_Zav0 (*((psbool)(InternalBuf+0x1F0))) /* - ���.��������� ����������� ���������*/
#define internal1_m490_Pv0 (*((psbool)(InternalBuf+0x1F2))) /* - ���. ����������� ���������*/
#define internal1_m490_Zv0 (*((psbool)(InternalBuf+0x1F4))) /* - ���. ����������� ���������*/
#define internal1_m490_RA00 (*((psbool)(InternalBuf+0x1F6))) /* - ��������� ������� ������*/
#define internal1_m490_RA10 (*((psbool)(InternalBuf+0x1F8))) /* - ��������� ������� �����*/
#define internal1_m490_MyFirstEnterFlag (*((psbool)(InternalBuf+0x1FA))) /*MyFirstEnterFlag*/
#define internal1_m478_Pav0 (*((psbool)(InternalBuf+0x1FC))) /* - ���.��������� ����������� ���������*/
#define internal1_m478_Zav0 (*((psbool)(InternalBuf+0x1FE))) /* - ���.��������� ����������� ���������*/
#define internal1_m478_Pv0 (*((psbool)(InternalBuf+0x200))) /* - ���. ����������� ���������*/
#define internal1_m478_Zv0 (*((psbool)(InternalBuf+0x202))) /* - ���. ����������� ���������*/
#define internal1_m478_RA00 (*((psbool)(InternalBuf+0x204))) /* - ��������� ������� ������*/
#define internal1_m478_RA10 (*((psbool)(InternalBuf+0x206))) /* - ��������� ������� �����*/
#define internal1_m478_MyFirstEnterFlag (*((psbool)(InternalBuf+0x208))) /*MyFirstEnterFlag*/
#define internal1_m621_Pav0 (*((psbool)(InternalBuf+0x20A))) /* - ���.��������� ����������� ���������*/
#define internal1_m621_Zav0 (*((psbool)(InternalBuf+0x20C))) /* - ���.��������� ����������� ���������*/
#define internal1_m621_Pv0 (*((psbool)(InternalBuf+0x20E))) /* - ���. ����������� ���������*/
#define internal1_m621_Zv0 (*((psbool)(InternalBuf+0x210))) /* - ���. ����������� ���������*/
#define internal1_m621_RA00 (*((psbool)(InternalBuf+0x212))) /* - ��������� ������� ������*/
#define internal1_m621_RA10 (*((psbool)(InternalBuf+0x214))) /* - ��������� ������� �����*/
#define internal1_m621_MyFirstEnterFlag (*((psbool)(InternalBuf+0x216))) /*MyFirstEnterFlag*/
#define internal1_m618_Pav0 (*((psbool)(InternalBuf+0x218))) /* - ���.��������� ����������� ���������*/
#define internal1_m618_Zav0 (*((psbool)(InternalBuf+0x21A))) /* - ���.��������� ����������� ���������*/
#define internal1_m618_Pv0 (*((psbool)(InternalBuf+0x21C))) /* - ���. ����������� ���������*/
#define internal1_m618_Zv0 (*((psbool)(InternalBuf+0x21E))) /* - ���. ����������� ���������*/
#define internal1_m618_RA00 (*((psbool)(InternalBuf+0x220))) /* - ��������� ������� ������*/
#define internal1_m618_RA10 (*((psbool)(InternalBuf+0x222))) /* - ��������� ������� �����*/
#define internal1_m618_MyFirstEnterFlag (*((psbool)(InternalBuf+0x224))) /*MyFirstEnterFlag*/
#define internal1_m604_Pav0 (*((psbool)(InternalBuf+0x226))) /* - ���.��������� ����������� ���������*/
#define internal1_m604_Zav0 (*((psbool)(InternalBuf+0x228))) /* - ���.��������� ����������� ���������*/
#define internal1_m604_Pv0 (*((psbool)(InternalBuf+0x22A))) /* - ���. ����������� ���������*/
#define internal1_m604_Zv0 (*((psbool)(InternalBuf+0x22C))) /* - ���. ����������� ���������*/
#define internal1_m604_RA00 (*((psbool)(InternalBuf+0x22E))) /* - ��������� ������� ������*/
#define internal1_m604_RA10 (*((psbool)(InternalBuf+0x230))) /* - ��������� ������� �����*/
#define internal1_m604_MyFirstEnterFlag (*((psbool)(InternalBuf+0x232))) /*MyFirstEnterFlag*/
#define internal1_m603_Pav0 (*((psbool)(InternalBuf+0x234))) /* - ���.��������� ����������� ���������*/
#define internal1_m603_Zav0 (*((psbool)(InternalBuf+0x236))) /* - ���.��������� ����������� ���������*/
#define internal1_m603_Pv0 (*((psbool)(InternalBuf+0x238))) /* - ���. ����������� ���������*/
#define internal1_m603_Zv0 (*((psbool)(InternalBuf+0x23A))) /* - ���. ����������� ���������*/
#define internal1_m603_RA00 (*((psbool)(InternalBuf+0x23C))) /* - ��������� ������� ������*/
#define internal1_m603_RA10 (*((psbool)(InternalBuf+0x23E))) /* - ��������� ������� �����*/
#define internal1_m603_MyFirstEnterFlag (*((psbool)(InternalBuf+0x240))) /*MyFirstEnterFlag*/
#define internal1_m650_y0 (*((psfloat)(InternalBuf+0x242))) /*y0 - ���������� ��������*/
#define internal1_m798_Chim0 (*((psfloat)(InternalBuf+0x247))) /*���������� ������� ��������� ������ ��*/
#define internal1_m790_Chim0 (*((psfloat)(InternalBuf+0x24C))) /*���������� ������� ��������� ������ ��*/
#define internal1_m783_Chim0 (*((psfloat)(InternalBuf+0x251))) /*���������� ������� ��������� ������ ��*/
#define internal1_m775_Chim0 (*((psfloat)(InternalBuf+0x256))) /*���������� ������� ��������� ������ ��*/
#define internal1_m767_Chim0 (*((psfloat)(InternalBuf+0x25B))) /*���������� ������� ��������� ������ ��*/
#define internal1_m760_Chim0 (*((psfloat)(InternalBuf+0x260))) /*���������� ������� ��������� ������ ��*/
#define internal1_m752_Chim0 (*((psfloat)(InternalBuf+0x265))) /*���������� ������� ��������� ������ ��*/
#define internal1_m744_Chim0 (*((psfloat)(InternalBuf+0x26A))) /*���������� ������� ��������� ������ ��*/
#define internal1_m737_Chim0 (*((psfloat)(InternalBuf+0x26F))) /*���������� ������� ��������� ������ ��*/
#define internal1_m729_Chim0 (*((psfloat)(InternalBuf+0x274))) /*���������� ������� ��������� ������ ��*/
#define internal1_m721_Chim0 (*((psfloat)(InternalBuf+0x279))) /*���������� ������� ��������� ������ ��*/
#define internal1_m714_Chim0 (*((psfloat)(InternalBuf+0x27E))) /*���������� ������� ��������� ������ ��*/
#define internal1_m590_Pav0 (*((psbool)(InternalBuf+0x283))) /* - ���.��������� ����������� ���������*/
#define internal1_m590_Zav0 (*((psbool)(InternalBuf+0x285))) /* - ���.��������� ����������� ���������*/
#define internal1_m590_Pv0 (*((psbool)(InternalBuf+0x287))) /* - ���. ����������� ���������*/
#define internal1_m590_Zv0 (*((psbool)(InternalBuf+0x289))) /* - ���. ����������� ���������*/
#define internal1_m590_RA00 (*((psbool)(InternalBuf+0x28B))) /* - ��������� ������� ������*/
#define internal1_m590_RA10 (*((psbool)(InternalBuf+0x28D))) /* - ��������� ������� �����*/
#define internal1_m590_MyFirstEnterFlag (*((psbool)(InternalBuf+0x28F))) /*MyFirstEnterFlag*/
#define internal1_m575_Pav0 (*((psbool)(InternalBuf+0x291))) /* - ���.��������� ����������� ���������*/
#define internal1_m575_Zav0 (*((psbool)(InternalBuf+0x293))) /* - ���.��������� ����������� ���������*/
#define internal1_m575_Pv0 (*((psbool)(InternalBuf+0x295))) /* - ���. ����������� ���������*/
#define internal1_m575_Zv0 (*((psbool)(InternalBuf+0x297))) /* - ���. ����������� ���������*/
#define internal1_m575_RA00 (*((psbool)(InternalBuf+0x299))) /* - ��������� ������� ������*/
#define internal1_m575_RA10 (*((psbool)(InternalBuf+0x29B))) /* - ��������� ������� �����*/
#define internal1_m575_MyFirstEnterFlag (*((psbool)(InternalBuf+0x29D))) /*MyFirstEnterFlag*/
#define internal1_m461_Pav0 (*((psbool)(InternalBuf+0x29F))) /* - ���.��������� ����������� ���������*/
#define internal1_m461_Zav0 (*((psbool)(InternalBuf+0x2A1))) /* - ���.��������� ����������� ���������*/
#define internal1_m461_Pv0 (*((psbool)(InternalBuf+0x2A3))) /* - ���. ����������� ���������*/
#define internal1_m461_Zv0 (*((psbool)(InternalBuf+0x2A5))) /* - ���. ����������� ���������*/
#define internal1_m461_RA00 (*((psbool)(InternalBuf+0x2A7))) /* - ��������� ������� ������*/
#define internal1_m461_RA10 (*((psbool)(InternalBuf+0x2A9))) /* - ��������� ������� �����*/
#define internal1_m461_MyFirstEnterFlag (*((psbool)(InternalBuf+0x2AB))) /*MyFirstEnterFlag*/
#define internal1_m446_Pav0 (*((psbool)(InternalBuf+0x2AD))) /* - ���.��������� ����������� ���������*/
#define internal1_m446_Zav0 (*((psbool)(InternalBuf+0x2AF))) /* - ���.��������� ����������� ���������*/
#define internal1_m446_Pv0 (*((psbool)(InternalBuf+0x2B1))) /* - ���. ����������� ���������*/
#define internal1_m446_Zv0 (*((psbool)(InternalBuf+0x2B3))) /* - ���. ����������� ���������*/
#define internal1_m446_RA00 (*((psbool)(InternalBuf+0x2B5))) /* - ��������� ������� ������*/
#define internal1_m446_RA10 (*((psbool)(InternalBuf+0x2B7))) /* - ��������� ������� �����*/
#define internal1_m446_MyFirstEnterFlag (*((psbool)(InternalBuf+0x2B9))) /*MyFirstEnterFlag*/
#define internal1_m502_Pav0 (*((psbool)(InternalBuf+0x2BB))) /* - ���.��������� ����������� ���������*/
#define internal1_m502_Zav0 (*((psbool)(InternalBuf+0x2BD))) /* - ���.��������� ����������� ���������*/
#define internal1_m502_Pv0 (*((psbool)(InternalBuf+0x2BF))) /* - ���. ����������� ���������*/
#define internal1_m502_Zv0 (*((psbool)(InternalBuf+0x2C1))) /* - ���. ����������� ���������*/
#define internal1_m502_RA00 (*((psbool)(InternalBuf+0x2C3))) /* - ��������� ������� ������*/
#define internal1_m502_RA10 (*((psbool)(InternalBuf+0x2C5))) /* - ��������� ������� �����*/
#define internal1_m502_MyFirstEnterFlag (*((psbool)(InternalBuf+0x2C7))) /*MyFirstEnterFlag*/
#define internal1_m397_Pav0 (*((psbool)(InternalBuf+0x2C9))) /* - ���.��������� ����������� ���������*/
#define internal1_m397_Zav0 (*((psbool)(InternalBuf+0x2CB))) /* - ���.��������� ����������� ���������*/
#define internal1_m397_Pv0 (*((psbool)(InternalBuf+0x2CD))) /* - ���. ����������� ���������*/
#define internal1_m397_Zv0 (*((psbool)(InternalBuf+0x2CF))) /* - ���. ����������� ���������*/
#define internal1_m397_RA00 (*((psbool)(InternalBuf+0x2D1))) /* - ��������� ������� ������*/
#define internal1_m397_RA10 (*((psbool)(InternalBuf+0x2D3))) /* - ��������� ������� �����*/
#define internal1_m397_MyFirstEnterFlag (*((psbool)(InternalBuf+0x2D5))) /*MyFirstEnterFlag*/
#define internal1_m381_Pav0 (*((psbool)(InternalBuf+0x2D7))) /* - ���.��������� ����������� ���������*/
#define internal1_m381_Zav0 (*((psbool)(InternalBuf+0x2D9))) /* - ���.��������� ����������� ���������*/
#define internal1_m381_Pv0 (*((psbool)(InternalBuf+0x2DB))) /* - ���. ����������� ���������*/
#define internal1_m381_Zv0 (*((psbool)(InternalBuf+0x2DD))) /* - ���. ����������� ���������*/
#define internal1_m381_RA00 (*((psbool)(InternalBuf+0x2DF))) /* - ��������� ������� ������*/
#define internal1_m381_RA10 (*((psbool)(InternalBuf+0x2E1))) /* - ��������� ������� �����*/
#define internal1_m381_MyFirstEnterFlag (*((psbool)(InternalBuf+0x2E3))) /*MyFirstEnterFlag*/
#define internal1_m364_Pav0 (*((psbool)(InternalBuf+0x2E5))) /* - ���.��������� ����������� ���������*/
#define internal1_m364_Zav0 (*((psbool)(InternalBuf+0x2E7))) /* - ���.��������� ����������� ���������*/
#define internal1_m364_Pv0 (*((psbool)(InternalBuf+0x2E9))) /* - ���. ����������� ���������*/
#define internal1_m364_Zv0 (*((psbool)(InternalBuf+0x2EB))) /* - ���. ����������� ���������*/
#define internal1_m364_RA00 (*((psbool)(InternalBuf+0x2ED))) /* - ��������� ������� ������*/
#define internal1_m364_RA10 (*((psbool)(InternalBuf+0x2EF))) /* - ��������� ������� �����*/
#define internal1_m364_MyFirstEnterFlag (*((psbool)(InternalBuf+0x2F1))) /*MyFirstEnterFlag*/
#define internal1_m1167_Pav0 (*((psbool)(InternalBuf+0x2F3))) /* - ���.��������� ����������� ���������*/
#define internal1_m1167_Zav0 (*((psbool)(InternalBuf+0x2F5))) /* - ���.��������� ����������� ���������*/
#define internal1_m1167_Pv0 (*((psbool)(InternalBuf+0x2F7))) /* - ���. ����������� ���������*/
#define internal1_m1167_Zv0 (*((psbool)(InternalBuf+0x2F9))) /* - ���. ����������� ���������*/
#define internal1_m1167_RA00 (*((psbool)(InternalBuf+0x2FB))) /* - ��������� ������� ������*/
#define internal1_m1167_RA10 (*((psbool)(InternalBuf+0x2FD))) /* - ��������� ������� �����*/
#define internal1_m1167_MyFirstEnterFlag (*((psbool)(InternalBuf+0x2FF))) /*MyFirstEnterFlag*/
#define internal1_m180_C1 (*((psfloat)(InternalBuf+0x301))) /*C1 - ������������ ������������� ��������� 1-�� ����*/
#define internal1_m180_C2 (*((psfloat)(InternalBuf+0x306))) /*C2 - ������������ ������������� ��������� 2-�� ����*/
#define internal1_m180_C3 (*((psfloat)(InternalBuf+0x30B))) /*C3 - ������������ ������������� ��������� 3-�� ����*/
#define internal1_m180_C4 (*((psfloat)(InternalBuf+0x310))) /*C4 - ������������ ������������� ��������� 4-�� ����*/
#define internal1_m180_C5 (*((psfloat)(InternalBuf+0x315))) /*C5 - ������������ ������������� ��������� 5-�� ����*/
#define internal1_m180_C6 (*((psfloat)(InternalBuf+0x31A))) /*C6 - ������������ ������������� ��������� 6-�� ����*/
#define internal1_m180_N20 (*((psfloat)(InternalBuf+0x31F))) /*N20 - ����. ������������ ��������� ������ ��*/
#define internal1_m180_C0 (*((psfloat)(InternalBuf+0x324))) /**C0 - ����. ������������ ������������� ���������*/
#define internal1_m180_ImpINI0 (*((psbool)(InternalBuf+0x342))) /*ImpINI - ������ ������� �������������(����.)*/
#define internal1_m180_MyFirstEnterFlag (*((psbool)(InternalBuf+0x344))) /*MyFirstEnterFlag*/
#define internal1_m301_Ppv0 (*((psbool)(InternalBuf+0x346))) /*Ppv0 - ������������� ������� ����������� ���(80 ��)*/
#define internal1_m301_Pav0 (*((psbool)(InternalBuf+0x348))) /*Pav0 - ���.��������� ����������� ���*/
#define internal1_m301_Zav0 (*((psbool)(InternalBuf+0x34A))) /*Zav0 - ���.��������� ����������� ���*/
#define internal1_m301_RA00 (*((psbool)(InternalBuf+0x34C))) /*RA00 - ��������� ������� ������*/
#define internal1_m301_RA10 (*((psbool)(InternalBuf+0x34E))) /*RA10 - ��������� ������� �����*/
#define internal1_m301_RA50 (*((pschar)(InternalBuf+0x350))) /*Ra50 - ��������� ������� ��������*/
#define internal1_m301_fls (*((psbool)(InternalBuf+0x352))) /* fls - ���� ������������ ������*/
#define internal1_m301_flp (*((psbool)(InternalBuf+0x354))) /* flp - ���� ������/������� �� ���������� (0 - ���, 1-�����, 2-������)*/
#define internal1_m301_MyFirstEnterFlag (*((psbool)(InternalBuf+0x356))) /*MyFirstEnterFlag*/
#define internal1_m130_Ppv0 (*((psbool)(InternalBuf+0x358))) /*Ppv0 - ������������� ������� ����������� ���(80 ��)*/
#define internal1_m130_Pav0 (*((psbool)(InternalBuf+0x35A))) /*Pav0 - ���.��������� ����������� ���*/
#define internal1_m130_Zav0 (*((psbool)(InternalBuf+0x35C))) /*Zav0 - ���.��������� ����������� ���*/
#define internal1_m130_RA00 (*((psbool)(InternalBuf+0x35E))) /*RA00 - ��������� ������� ������*/
#define internal1_m130_RA10 (*((psbool)(InternalBuf+0x360))) /*RA10 - ��������� ������� �����*/
#define internal1_m130_RA50 (*((pschar)(InternalBuf+0x362))) /*Ra50 - ��������� ������� ��������*/
#define internal1_m130_fls (*((psbool)(InternalBuf+0x364))) /* fls - ���� ������������ ������*/
#define internal1_m130_flp (*((psbool)(InternalBuf+0x366))) /* flp - ���� ������/������� �� ���������� (0 - ���, 1-�����, 2-������)*/
#define internal1_m130_MyFirstEnterFlag (*((psbool)(InternalBuf+0x368))) /*MyFirstEnterFlag*/
#define internal1_m265_Ppv0 (*((psbool)(InternalBuf+0x36A))) /*Ppv0 - ������������� ������� ����������� ���(80 ��)*/
#define internal1_m265_Pav0 (*((psbool)(InternalBuf+0x36C))) /*Pav0 - ���.��������� ����������� ���*/
#define internal1_m265_Zav0 (*((psbool)(InternalBuf+0x36E))) /*Zav0 - ���.��������� ����������� ���*/
#define internal1_m265_RA00 (*((psbool)(InternalBuf+0x370))) /*RA00 - ��������� ������� ������*/
#define internal1_m265_RA10 (*((psbool)(InternalBuf+0x372))) /*RA10 - ��������� ������� �����*/
#define internal1_m265_RA50 (*((pschar)(InternalBuf+0x374))) /*Ra50 - ��������� ������� ��������*/
#define internal1_m265_fls (*((psbool)(InternalBuf+0x376))) /* fls - ���� ������������ ������*/
#define internal1_m265_flp (*((psbool)(InternalBuf+0x378))) /* flp - ���� ������/������� �� ���������� (0 - ���, 1-�����, 2-������)*/
#define internal1_m265_MyFirstEnterFlag (*((psbool)(InternalBuf+0x37A))) /*MyFirstEnterFlag*/
#define internal1_m97_Ppv0 (*((psbool)(InternalBuf+0x37C))) /*Ppv0 - ������������� ������� ����������� ���(80 ��)*/
#define internal1_m97_Pav0 (*((psbool)(InternalBuf+0x37E))) /*Pav0 - ���.��������� ����������� ���*/
#define internal1_m97_Zav0 (*((psbool)(InternalBuf+0x380))) /*Zav0 - ���.��������� ����������� ���*/
#define internal1_m97_RA00 (*((psbool)(InternalBuf+0x382))) /*RA00 - ��������� ������� ������*/
#define internal1_m97_RA10 (*((psbool)(InternalBuf+0x384))) /*RA10 - ��������� ������� �����*/
#define internal1_m97_RA50 (*((pschar)(InternalBuf+0x386))) /*Ra50 - ��������� ������� ��������*/
#define internal1_m97_fls (*((psbool)(InternalBuf+0x388))) /* fls - ���� ������������ ������*/
#define internal1_m97_flp (*((psbool)(InternalBuf+0x38A))) /* flp - ���� ������/������� �� ���������� (0 - ���, 1-�����, 2-������)*/
#define internal1_m97_MyFirstEnterFlag (*((psbool)(InternalBuf+0x38C))) /*MyFirstEnterFlag*/
#define internal1_m227_Ppv0 (*((psbool)(InternalBuf+0x38E))) /*Ppv0 - ������������� ������� ����������� ���(80 ��)*/
#define internal1_m227_Pav0 (*((psbool)(InternalBuf+0x390))) /*Pav0 - ���.��������� ����������� ���*/
#define internal1_m227_Zav0 (*((psbool)(InternalBuf+0x392))) /*Zav0 - ���.��������� ����������� ���*/
#define internal1_m227_RA00 (*((psbool)(InternalBuf+0x394))) /*RA00 - ��������� ������� ������*/
#define internal1_m227_RA10 (*((psbool)(InternalBuf+0x396))) /*RA10 - ��������� ������� �����*/
#define internal1_m227_RA50 (*((pschar)(InternalBuf+0x398))) /*Ra50 - ��������� ������� ��������*/
#define internal1_m227_fls (*((psbool)(InternalBuf+0x39A))) /* fls - ���� ������������ ������*/
#define internal1_m227_flp (*((psbool)(InternalBuf+0x39C))) /* flp - ���� ������/������� �� ���������� (0 - ���, 1-�����, 2-������)*/
#define internal1_m227_MyFirstEnterFlag (*((psbool)(InternalBuf+0x39E))) /*MyFirstEnterFlag*/
#define internal1_m59_Ppv0 (*((psbool)(InternalBuf+0x3A0))) /*Ppv0 - ������������� ������� ����������� ���(80 ��)*/
#define internal1_m59_Pav0 (*((psbool)(InternalBuf+0x3A2))) /*Pav0 - ���.��������� ����������� ���*/
#define internal1_m59_Zav0 (*((psbool)(InternalBuf+0x3A4))) /*Zav0 - ���.��������� ����������� ���*/
#define internal1_m59_RA00 (*((psbool)(InternalBuf+0x3A6))) /*RA00 - ��������� ������� ������*/
#define internal1_m59_RA10 (*((psbool)(InternalBuf+0x3A8))) /*RA10 - ��������� ������� �����*/
#define internal1_m59_RA50 (*((pschar)(InternalBuf+0x3AA))) /*Ra50 - ��������� ������� ��������*/
#define internal1_m59_fls (*((psbool)(InternalBuf+0x3AC))) /* fls - ���� ������������ ������*/
#define internal1_m59_flp (*((psbool)(InternalBuf+0x3AE))) /* flp - ���� ������/������� �� ���������� (0 - ���, 1-�����, 2-������)*/
#define internal1_m59_MyFirstEnterFlag (*((psbool)(InternalBuf+0x3B0))) /*MyFirstEnterFlag*/
#define internal1_m14_C1 (*((psfloat)(InternalBuf+0x3B2))) /*C1 - ������������ ������������� ��������� 1-�� ����*/
#define internal1_m14_C2 (*((psfloat)(InternalBuf+0x3B7))) /*C2 - ������������ ������������� ��������� 2-�� ����*/
#define internal1_m14_C3 (*((psfloat)(InternalBuf+0x3BC))) /*C3 - ������������ ������������� ��������� 3-�� ����*/
#define internal1_m14_C4 (*((psfloat)(InternalBuf+0x3C1))) /*C4 - ������������ ������������� ��������� 4-�� ����*/
#define internal1_m14_C5 (*((psfloat)(InternalBuf+0x3C6))) /*C5 - ������������ ������������� ��������� 5-�� ����*/
#define internal1_m14_C6 (*((psfloat)(InternalBuf+0x3CB))) /*C6 - ������������ ������������� ��������� 6-�� ����*/
#define internal1_m14_N20 (*((psfloat)(InternalBuf+0x3D0))) /*N20 - ����. ������������ ��������� ������ ��*/
#define internal1_m14_C0 (*((psfloat)(InternalBuf+0x3D5))) /**C0 - ����. ������������ ������������� ���������*/
#define internal1_m14_ImpINI0 (*((psbool)(InternalBuf+0x3F3))) /*ImpINI - ������ ������� �������������(����.)*/
#define internal1_m14_MyFirstEnterFlag (*((psbool)(InternalBuf+0x3F5))) /*MyFirstEnterFlag*/
int InternalBufSize = 1015;

/* ����������� �������� */
#define signal_A0SR01RIM     (*((psfloat)(PBSTART+0x0)))  /*                       ������� ������������ A�1 */
#define signal_A1AD11LDU     (*((psbool)(PBSTART+0x5)))  /*                       ������ �� ����������� ��1 ����� */
#define signal_A1AD21LDU     (*((psbool)(PBSTART+0x7)))  /*                       ������ �� ����������� ��1 ���� */
#define signal_A1AD01LDU     (*((psbool)(PBSTART+0x9)))  /*                       ���������� �������� ��1 */
#define signal_A1AD02LDU     (*((psbool)(PBSTART+0xb)))  /*                       0-� ��� �������� ��1 */
#define signal_A1AD03LDU     (*((psbool)(PBSTART+0xd)))  /*                       1-� ��� �������� ��1 */
#define signal_A1AD04LDU     (*((psbool)(PBSTART+0xf)))  /*                       2-� ��� �������� ��1 */
#define signal_A1AD05LDU     (*((psbool)(PBSTART+0x11)))  /*                       ������� ������� �� ��1 */
#define signal_B1AD11LDU     (*((psbool)(PBSTART+0x13)))  /*                       ������ �� ����������� ��2 ����� */
#define signal_B1AD21LDU     (*((psbool)(PBSTART+0x15)))  /*                       ������ �� ����������� ��2 ���� */
#define signal_B1AD01LDU     (*((psbool)(PBSTART+0x17)))  /*                       ���������� �������� ��2 */
#define signal_B1AD02LDU     (*((psbool)(PBSTART+0x19)))  /*                       0-� ��� ��������  ��2 */
#define signal_B1AD03LDU     (*((psbool)(PBSTART+0x1b)))  /*                       1-� ��� �������� ��2 */
#define signal_B1AD04LDU     (*((psbool)(PBSTART+0x1d)))  /*                       2-� ��� �������� ��2 */
#define signal_B1AD05LDU     (*((psbool)(PBSTART+0x1f)))  /*                       ������� ������� �� ��2 */
#define signal_A2AD11LDU     (*((psbool)(PBSTART+0x21)))  /*                       ������ �� ����������� ��1 ����� */
#define signal_A2AD21LDU     (*((psbool)(PBSTART+0x23)))  /*                       ������ �� ����������� ��1 ���� */
#define signal_A2AD01LDU     (*((psbool)(PBSTART+0x25)))  /*                       ���������� �������� ��1 */
#define signal_A2AD02LDU     (*((psbool)(PBSTART+0x27)))  /*                       0-� ��� �������� ��1 */
#define signal_A2AD03LDU     (*((psbool)(PBSTART+0x29)))  /*                       1-� ��� �������� ��1 */
#define signal_A2AD04LDU     (*((psbool)(PBSTART+0x2b)))  /*                       2-� ��� �������� ��1 */
#define signal_A2AD05LDU     (*((psbool)(PBSTART+0x2d)))  /*                       ������� ������� �� ��1 */
#define signal_A2AD33LDU     (*((psbool)(PBSTART+0x2f)))  /*                       ������ (������ ��1) ������� (����������) */
#define signal_B2AD11LDU     (*((psbool)(PBSTART+0x31)))  /*                       ������ �� ����������� ��2 ����� */
#define signal_B2AD21LDU     (*((psbool)(PBSTART+0x33)))  /*                       ������ �� ����������� ��2 ���� */
#define signal_B2AD01LDU     (*((psbool)(PBSTART+0x35)))  /*                       ���������� �������� ��2 */
#define signal_B2AD02LDU     (*((psbool)(PBSTART+0x37)))  /*                       0-� ��� �������� ��2 */
#define signal_B2AD03LDU     (*((psbool)(PBSTART+0x39)))  /*                       1-� ��� �������� ��2 */
#define signal_B2AD04LDU     (*((psbool)(PBSTART+0x3b)))  /*                       2-� ��� �������� ��2 */
#define signal_B2AD05LDU     (*((psbool)(PBSTART+0x3d)))  /*                       ������� ������� �� ��2 */
#define signal_B2AD33LDU     (*((psbool)(PBSTART+0x3f)))  /*                       ������ (������ ��2) ������� (����������) */
#define signal_A3AD11LDU     (*((psbool)(PBSTART+0x41)))  /*                       ������ �� ����������� ��1 ����� */
#define signal_A3AD21LDU     (*((psbool)(PBSTART+0x43)))  /*                       ������ �� ����������� ��1 ���� */
#define signal_A3AD01LDU     (*((psbool)(PBSTART+0x45)))  /*                       ���������� �������� ��1 */
#define signal_A3AD02LDU     (*((psbool)(PBSTART+0x47)))  /*                       0-� ��� �������� ��1 */
#define signal_A3AD03LDU     (*((psbool)(PBSTART+0x49)))  /*                       1-� ��� �������� ��1 */
#define signal_A3AD04LDU     (*((psbool)(PBSTART+0x4b)))  /*                       2-� ��� �������� ��1 */
#define signal_A3AD05LDU     (*((psbool)(PBSTART+0x4d)))  /*                       ������� ������� �� ��1 */
#define signal_A3AD33LDU     (*((psbool)(PBSTART+0x4f)))  /*                       ������ �������  ��1 ������� (����������) */
#define signal_B3AD11LDU     (*((psbool)(PBSTART+0x51)))  /*                       ������ �� ����������� ��2 ����� */
#define signal_B3AD21LDU     (*((psbool)(PBSTART+0x53)))  /*                       ������ �� ����������� ��2 ���� */
#define signal_B3AD01LDU     (*((psbool)(PBSTART+0x55)))  /*                       ���������� �������� ��2 */
#define signal_B3AD02LDU     (*((psbool)(PBSTART+0x57)))  /*                       0-� ��� �������� ��2 */
#define signal_B3AD03LDU     (*((psbool)(PBSTART+0x59)))  /*                       1-� ��� �������� ��2 */
#define signal_B3AD04LDU     (*((psbool)(PBSTART+0x5b)))  /*                       2-� ��� �������� ��2 */
#define signal_B3AD05LDU     (*((psbool)(PBSTART+0x5d)))  /*                       ������� ������� �� ��2 */
#define signal_B3AD33LDU     (*((psbool)(PBSTART+0x5f)))  /*                       ������ ������� ��2 ������� (����������) */
#define signal_B0SR01RIM     (*((psfloat)(PBSTART+0x61)))  /*                       ������� ������������ A�2 */
#define signal_R4AD10LDU     (*((psbool)(PBSTART+0x66)))  /*                       ����������� ������� ������ */
#define signal_R4AD20LDU     (*((psbool)(PBSTART+0x68)))  /*                       ����������� ������� ����� */
#define signal_B8AD10LDU     (*((psbool)(PBSTART+0x6a)))  /*                       ����������� ��2 ������ */
#define signal_B8AD20LDU     (*((psbool)(PBSTART+0x6c)))  /*                       ����������� ��2 ����� */
#define signal_A8AD10LDU     (*((psbool)(PBSTART+0x6e)))  /*                       ����������� ��2 ������ */
#define signal_A8AD20LDU     (*((psbool)(PBSTART+0x70)))  /*                       ����������� ��2 ����� */
#define signal_A6AD10LDU     (*((psbool)(PBSTART+0x72)))  /*                       ������� ��1 */
#define signal_A6AD20LDU     (*((psbool)(PBSTART+0x74)))  /*                       ������� ��1 */
#define signal_B6AD10LDU     (*((psbool)(PBSTART+0x76)))  /*                       ������� ��2 */
#define signal_B6AD20LDU     (*((psbool)(PBSTART+0x78)))  /*                       ������� ��2 */
#define signal_R1AD10LDU     (*((psbool)(PBSTART+0x7a)))  /*                       �������� ���1 � ���� ��������� */
#define signal_R1AD20LDU     (*((psbool)(PBSTART+0x7c)))  /*                       ������� ���1 */
#define signal_R2AD10LDU     (*((psbool)(PBSTART+0x7e)))  /*                       �������� ���2 � ���� ��������� */
#define signal_R2AD20LDU     (*((psbool)(PBSTART+0x80)))  /*                       ������� ���2 */
#define signal_A5AD10LDU     (*((psbool)(PBSTART+0x82)))  /*                       ������� ��1 */
#define signal_A5AD20LDU     (*((psbool)(PBSTART+0x84)))  /*                       �������� ��1 */
#define signal_B5AD10LDU     (*((psbool)(PBSTART+0x86)))  /*                       ������� ��2 */
#define signal_B5AD20LDU     (*((psbool)(PBSTART+0x88)))  /*                       �������� ��2 */
#define signal_A0SN08RIM     (*((psfloat)(PBSTART+0x8a)))  /*                       ����� ��������� A�1(�����/�) */
#define signal_B0SN08RIM     (*((psfloat)(PBSTART+0x8f)))  /*                       ����� ��������� A�2(�����/�) */
#define signal_R0CR01RIM     (*((psfloat)(PBSTART+0x94)))  /*                       ����������� 12 ����� ��1,2 */
#define signal_R0CR02RIM     (*((psfloat)(PBSTART+0x99)))  /*                       ����������� 11 ����� ��1,2 */
#define signal_R0SR02RIM     (*((psfloat)(PBSTART+0x9e)))  /*                       ������� �������� �� (����) */
#define signal_R0AD14LDU     (*((psbool)(PBSTART+0xa3)))  /*                       �������� ������������ ������� �� II �� */
#define signal_R8AD21LDU     (*((psbool)(PBSTART+0xa5)))  /*                       ������ ������� ������������� */
#define signal_R8AD21LDU     (*((psbool)(PBSTART+0xa5)))  /*                       ������ ������� ������������� */
#define signal_R0VZ71LZ1     (*((psbool)(PBSTART+0xa7)))  /*                       ���������� ������ �� ��  1 ������ */
#define signal_R0VZ71LZ2     (*((psbool)(PBSTART+0xa9)))  /*                       ���������� ������ �� ��  2 ������ */
#define signal_A2AD32LDU     (*((psbool)(PBSTART+0xab)))  /*                       ���������� �� ��1 */
#define signal_C2MD31LP1     (*((psbool)(PBSTART+0xad)))  /*                       ������ ������ ��� */
#define signal_C2MD31LP1     (*((psbool)(PBSTART+0xad)))  /*                       ������ ������ ��� */
#define signal_A2AD31LDU     (*((psbool)(PBSTART+0xaf)))  /*                       ������ (����� ��1) ������� (����������) */
#define signal_A1AD32LDU     (*((psbool)(PBSTART+0xb1)))  /*                       ���������� �� ��1 */
#define signal_A1AD31LDU     (*((psbool)(PBSTART+0xb3)))  /*                       ������ (����� ��1) ������� (����������) */
#define signal_C1MD31LP2     (*((psbool)(PBSTART+0xb5)))  /*                       ������ ������ ���  �� ���2 */
#define signal_C1MD31LP2     (*((psbool)(PBSTART+0xb5)))  /*                       ������ ������ ���  �� ���2 */
#define signal_C1MD31LP1     (*((psbool)(PBSTART+0xb7)))  /*                       ������ ������ ���  �� ���1 */
#define signal_C1MD31LP1     (*((psbool)(PBSTART+0xb7)))  /*                       ������ ������ ���  �� ���1 */
#define signal_A3AD31LDU     (*((psbool)(PBSTART+0xb9)))  /*                       ������ (����� ��1) ������� (����������) */
#define signal_B1AD31LDU     (*((psbool)(PBSTART+0xbb)))  /*                       ������ (����� ��2) ������� (����������) */
#define signal_B1AD32LDU     (*((psbool)(PBSTART+0xbd)))  /*                       ���������� �� ��2 */
#define signal_B2AD31LDU     (*((psbool)(PBSTART+0xbf)))  /*                       ������ (����� ��2) ������� (����������) */
#define signal_B2AD32LDU     (*((psbool)(PBSTART+0xc1)))  /*                       ���������� �� ��2 */
#define signal_B3AD31LDU     (*((psbool)(PBSTART+0xc3)))  /*                       ������ (����� ��2) ������� (����������) */
#define signal_R0MW13LP2     (*((psbool)(PBSTART+0xc5)))  /*                       ������������� ����ܻ */
#define signal_B9AD10LDU     (*((psbool)(PBSTART+0xc7)))  /*                       ������� ������ (������ �� ��2) */
#define signal_A9AD10LDU     (*((psbool)(PBSTART+0xc9)))  /*                       ������� ������ (������ �� ��1) */
#define signal_B4AD10LDU     (*((psbool)(PBSTART+0xcb)))  /*                       ������� ������ (������ ��2) */
#define signal_A4AD10LDU     (*((psbool)(PBSTART+0xcd)))  /*                       ������� ������ (������ ��1) */
#define signal_R0ST01RIM     (*((psfloat)(PBSTART+0xcf)))  /*                       ������� ������ ������� �� */
#define signal_R0SR01RIM     (*((psfloat)(PBSTART+0xd4)))  /*                       ������� ������������ P� */
#define signal_R7II73LZ1     (*((psbool)(PBSTART+0xd9)))  /*                       ��������� �� II�� */
#define signal_R7II71LZ1     (*((psbool)(PBSTART+0xdb)))  /*                       ��������� �� I�� (������ 1) */
#define signal_R7II72LZ1     (*((psbool)(PBSTART+0xdd)))  /*                       ��������� �� I�� (������ 2) */
#define signal_R0AD16LDU     (*((psbool)(PBSTART+0xdf)))  /*                       ��������  I-II ��. ��� */
#define signal_R7II72LZ2     (*((psbool)(PBSTART+0xe1)))  /*                       ��������� �� I�� (������ 2) */
#define signal_R7II71LZ2     (*((psbool)(PBSTART+0xe3)))  /*                       ��������� �� I�� (������ 1) */
#define signal_R7II73LZ2     (*((psbool)(PBSTART+0xe5)))  /*                       ��������� �� II�� */
#define signal_A3IS35LDU     (*((psbool)(PBSTART+0xe7)))  /*                       ������ (����1) ������(���������) */
#define signal_B3AD34LDU     (*((psbool)(PBSTART+0xe9)))  /*                       ������ (����2) ������� (����������) */
#define signal_B3IS35LDU     (*((psbool)(PBSTART+0xeb)))  /*                       ������ �����2� ������(���������) */
#define signal_R0VN02RS1     (*((psfloat)(PBSTART+0xed)))  /*                       ������� �������� �����1 */
#define signal_R0VN61LS1     (*((psbool)(PBSTART+0xf2)))  /*                       �� �� �������� �����1 */
#define signal_R0VN71LZ1     (*((psbool)(PBSTART+0xf4)))  /*                       �� �� �������� �����1 �� ���1 */
#define signal_A0VN71LS1     (*((psbool)(PBSTART+0xf6)))  /*                       ���������� ���������������  ������� �� ����� 1 �� ���1 */
#define signal_R0VN15RS1     (*((psint)(PBSTART+0xf8)))  /*                       ����� ������� ������ 1-���-11,2-���-15�-1,3-���-53�,0-��� ������� */
#define signal_R0VN71LZ2     (*((psbool)(PBSTART+0xfb)))  /*                       �� �� �������� ����� 1  �� ���2 */
#define signal_A1VN71LS1     (*((psbool)(PBSTART+0xfd)))  /*                       ���������� ���������������  ������� �� ����� 1 �� ���2 */
#define signal_R0VN01RS1     (*((psfloat)(PBSTART+0xff)))  /*                       ������ ������� �����1 */
#define signal_R0VN65LS1     (*((psbool)(PBSTART+0x104)))  /*                       �� �� ������� ������� �����1 */
#define signal_R0VN75LZ1     (*((psbool)(PBSTART+0x106)))  /*                       �� �� ������� ��������� ���1 */
#define signal_A0EE01LS1     (*((psbool)(PBSTART+0x108)))  /*                       ����������� ���� �����1 �� ���1 */
#define signal_R0VN75LZ2     (*((psbool)(PBSTART+0x10a)))  /*                       �� �� ������� ��������� ���2 */
#define signal_A1EE01LS1     (*((psbool)(PBSTART+0x10c)))  /*                       ����������� ���� �� ���2 */
#define signal_R0IE11LS1     (*((psbool)(PBSTART+0x10e)))  /*                       ����������� ��� 1,6 (�8) ���11 1������ */
#define signal_R0IE12LS1     (*((psbool)(PBSTART+0x110)))  /*                       ����������� ��� 0,5 (�9) ���15-1 1������ */
#define signal_R0IE13LS1     (*((psbool)(PBSTART+0x112)))  /*                       ����������� ��� 0,5 (�10) ���53� 1������ */
#define signal_R0VN02RS2     (*((psfloat)(PBSTART+0x114)))  /*                       ������� �������� ����� 2 */
#define signal_R0VN61LS2     (*((psbool)(PBSTART+0x119)))  /*                       �� �� �������� ����� 2 */
#define signal_R0VN72LZ1     (*((psbool)(PBSTART+0x11b)))  /*                       �� �� �������� ����� 2 �� ���1 */
#define signal_A1VN71LS2     (*((psbool)(PBSTART+0x11d)))  /*                       ���������� ��������������� ������� �� ����� 2 �� ���2 */
#define signal_R0VN15RS2     (*((psint)(PBSTART+0x11f)))  /*                       ����� ������� ������ ����� 2 */
#define signal_R0VN72LZ2     (*((psbool)(PBSTART+0x122)))  /*                       �� �� �������� ����� 2 �� ���2 */
#define signal_A0VN71LS2     (*((psbool)(PBSTART+0x124)))  /*                       ���������� ��������������� ������� �� ����� 2 �� ���1 */
#define signal_R0VN01RS2     (*((psfloat)(PBSTART+0x126)))  /*                       ������ ������� ����� 2 */
#define signal_R0VN65LS2     (*((psbool)(PBSTART+0x12b)))  /*                       �� �� ������� ������� ����� 2 */
#define signal_R0VN76LZ1     (*((psbool)(PBSTART+0x12d)))  /*                       �� �� ������� ������� ����� 2  �� ���1 */
#define signal_A0EE01LS2     (*((psbool)(PBSTART+0x12f)))  /*                       ����������� ���� ����� 2 �� ���1 */
#define signal_R0VN76LZ2     (*((psbool)(PBSTART+0x131)))  /*                       �� �� ������� ������� ����� 2  �� ���2 */
#define signal_A1EE01LS2     (*((psbool)(PBSTART+0x133)))  /*                       ����������� ���� ����� 2 �� ���2 */
#define signal_R0IE12LS2     (*((psbool)(PBSTART+0x135)))  /*                       ����������� ��� 0,5 (�12) ���15-1 2������ */
#define signal_R0IE13LS2     (*((psbool)(PBSTART+0x137)))  /*                       ����������� ��� 0,5 (�13) ���53� 2������ */
#define signal_R0IE11LS2     (*((psbool)(PBSTART+0x139)))  /*                       ����������� ��� 1,6 (�11) ���11 2������ */
#define signal_R0VN02RS3     (*((psfloat)(PBSTART+0x13b)))  /*                       ������� �������� ����� 3 */
#define signal_R0VN61LS3     (*((psbool)(PBSTART+0x140)))  /*                       �� �� �������� ����� 3 */
#define signal_R0VN73LZ1     (*((psbool)(PBSTART+0x142)))  /*                       �� �� �������� ����� 3 �� ���1 */
#define signal_A1VN71LS3     (*((psbool)(PBSTART+0x144)))  /*                       ���������� ���������������  ������� �� ����� 3 �� ���2 */
#define signal_R0VN15RS3     (*((psint)(PBSTART+0x146)))  /*                       ����� ������� ������ ����� 3 */
#define signal_A0VN71LS3     (*((psbool)(PBSTART+0x149)))  /*                       ���������� ���������������  ������� �� ����� 3 �� ���1 */
#define signal_R0VN73LZ2     (*((psbool)(PBSTART+0x14b)))  /*                       �� �� �������� ����� 3 �� ���2 */
#define signal_R0VN01RS3     (*((psfloat)(PBSTART+0x14d)))  /*                       ������ ������� ����� 3 */
#define signal_R0VN65LS3     (*((psbool)(PBSTART+0x152)))  /*                       �� �� ������� ������� ����� 3 */
#define signal_R0VN77LZ1     (*((psbool)(PBSTART+0x154)))  /*                       �� �� ������� ������� ����� 3 �� ���1 */
#define signal_A0EE01LS3     (*((psbool)(PBSTART+0x156)))  /*                       ����������� ���� ����� 3 �� ���1 */
#define signal_R0VN77LZ2     (*((psbool)(PBSTART+0x158)))  /*                       �� �� ������� ������� ����� 3 �� ���2 */
#define signal_A1EE01LS3     (*((psbool)(PBSTART+0x15a)))  /*                       ����������� ���� ����� 3 �� ���2 */
#define signal_R0IE12LS3     (*((psbool)(PBSTART+0x15c)))  /*                       ����������� ��� 0,5 (�15) ���15-1 3������ */
#define signal_R0IE13LS3     (*((psbool)(PBSTART+0x15e)))  /*                       ����������� ��� 0,5 (�16) ���53� 3������ */
#define signal_R0IE11LS3     (*((psbool)(PBSTART+0x160)))  /*                       ����������� ��� 1,6 (�14) ���11 3������ */
#define signal_R0VN02RS4     (*((psfloat)(PBSTART+0x162)))  /*                       ������� �������� ����� 4 */
#define signal_R0VN61LS4     (*((psbool)(PBSTART+0x167)))  /*                       �� �� �������� ����� 4 */
#define signal_R0VN74LZ1     (*((psbool)(PBSTART+0x169)))  /*                       �� �� �������� ����� 4 �� ���1 */
#define signal_A1VN71LS4     (*((psbool)(PBSTART+0x16b)))  /*                       ���������� ���������������  ������� �� ����� 4 �� ���2 */
#define signal_R0VN15RS4     (*((psint)(PBSTART+0x16d)))  /*                       ����� ������� ������ ����� 4 */
#define signal_A0VN71LS4     (*((psbool)(PBSTART+0x170)))  /*                       ���������� ���������������  ������� �� ����� 4 �� ���1 */
#define signal_R0VN74LZ2     (*((psbool)(PBSTART+0x172)))  /*                       �� �� �������� ����� 4 �� ���2 */
#define signal_R0VN01RS4     (*((psfloat)(PBSTART+0x174)))  /*                       ������ ������� ����� 4 */
#define signal_R0VN65LS4     (*((psbool)(PBSTART+0x179)))  /*                       �� �� ������� ������� ����� 4 */
#define signal_R0VN78LZ1     (*((psbool)(PBSTART+0x17b)))  /*                       �� �� ������� ������� ����� 4 �� ���1 */
#define signal_A0EE01LS4     (*((psbool)(PBSTART+0x17d)))  /*                       ����������� ���� ����� 4 �� ���1 */
#define signal_R0VN78LZ2     (*((psbool)(PBSTART+0x17f)))  /*                       �� �� ������� ������� ����� 4 �� ���2 */
#define signal_A1EE01LS4     (*((psbool)(PBSTART+0x181)))  /*                       ����������� ���� ����� 4 �� ���2 */
#define signal_R0IE12LS4     (*((psbool)(PBSTART+0x183)))  /*                       ����������� ��� 0,5 (�18) ���15-1 4������ */
#define signal_R0IE13LS4     (*((psbool)(PBSTART+0x185)))  /*                       ����������� ��� 0,5 (�19) ���53� 4������ */
#define signal_R0IE11LS4     (*((psbool)(PBSTART+0x187)))  /*                       ����������� ��� 1,6 (�17) ���11 4������ */
#define signal_A7AS31LDU     (*((psbool)(PBSTART+0x189)))  /*                       ������ (����� ��1) ������ (���������) */
#define signal_B7AS31LDU     (*((psbool)(PBSTART+0x18b)))  /*                       ������ (����� ��2) ������ (���������) */
#define signal_R6IS21LDU     (*((psbool)(PBSTART+0x18d)))  /*                       ����-����� � ��������� ��������� */
#define signal_A0IT01IZ1     (*((psint)(PBSTART+0x18f)))  /*                       ����������� ��1-1 */
#define signal_A0IT02IZ2     (*((psint)(PBSTART+0x192)))  /*                       ����������� ��1-2 */
#define signal_B0IT01IZ1     (*((psint)(PBSTART+0x195)))  /*                       ����������� ��2-1 */
#define signal_B0IT02IZ2     (*((psint)(PBSTART+0x198)))  /*                       ����������� ��2-2 */
#define signal_A2IS21LDU     (*((psbool)(PBSTART+0x19b)))  /*                       ������ �� �� ��1 */
#define signal_A2IS11LDU     (*((psbool)(PBSTART+0x19d)))  /*                       ������ �� �� ��1 */
#define signal_A2IS12LDU     (*((psbool)(PBSTART+0x19f)))  /*                       ������ ��1 �������� */
#define signal_A2IC01UDU     (*((pslong)(PBSTART+0x1a1)))  /*                       ���������� ����� ��1 */
#define signal_A2IS33LDU     (*((psbool)(PBSTART+0x1a6)))  /*                       ������ (������ ��1)  ������ (���������) */
#define signal_A3IS21LDU     (*((psbool)(PBSTART+0x1a8)))  /*                       ������ �� �� ��1 */
#define signal_B3IS21LDU     (*((psbool)(PBSTART+0x1aa)))  /*                       ������ �� �� ��2 */
#define signal_A2IP01IZ1     (*((psint)(PBSTART+0x1ac)))  /*                       ������� �������� ����� ��1 */
#define signal_A2IP01IZ2     (*((psint)(PBSTART+0x1af)))  /*                       ������� �������� ����� ��1 */
#define signal_A2VP82LDU     (*((psbool)(PBSTART+0x1b2)))  /*                       �������� ���ڨ� ��1 � ����� */
#define signal_A3IS31LDU     (*((psbool)(PBSTART+0x1b4)))  /*                       ������ (����� ��1)  ������ (���������) */
#define signal_A3IC01UDU     (*((pslong)(PBSTART+0x1b6)))  /*                       ���������� ����� ��1 */
#define signal_A3IS33LDU     (*((psbool)(PBSTART+0x1bb)))  /*                       ������ (������� ��1)  ������ (���������) */
#define signal_B3IP02IDU     (*((psint)(PBSTART+0x1bd)))  /*                       ������� �������� �������  ��2 */
#define signal_B3IS31LDU     (*((psbool)(PBSTART+0x1c0)))  /*                       ������ (����� ��2)  ������ (���������) */
#define signal_B3IC01UDU     (*((pslong)(PBSTART+0x1c2)))  /*                       ���������� ����� ��2 */
#define signal_B3IS33LDU     (*((psbool)(PBSTART+0x1c7)))  /*                       ������ �������� ��2�  ������ (���������) */
#define signal_A3VP81LDU     (*((psbool)(PBSTART+0x1c9)))  /*                       �������� ����� ��1 � ����� */
#define signal_B3VP81LDU     (*((psbool)(PBSTART+0x1cb)))  /*                       �������� ����� ��2 � ����� */
#define signal_A3IP02IDU     (*((psint)(PBSTART+0x1cd)))  /*                       ������� �������� ������� ��1 */
#define signal_A3IS11LDU     (*((psbool)(PBSTART+0x1d0)))  /*                       ������ �� �� ��1 */
#define signal_B3IS11LDU     (*((psbool)(PBSTART+0x1d2)))  /*                       ������ �� �� ��2 */
#define signal_A3IS22LDU     (*((psbool)(PBSTART+0x1d4)))  /*                       ������ �� ��� ��1 */
#define signal_B3IS22LDU     (*((psbool)(PBSTART+0x1d6)))  /*                       ������ �� ��� ��2 */
#define signal_R6IS62LDU     (*((psbool)(PBSTART+0x1d8)))  /*                       ����������� ��� ����-39 1����� */
#define signal_R6IS63LDU     (*((psbool)(PBSTART+0x1da)))  /*                       ����������� ��� ����-39 2����� */
#define signal_R6IS64LDU     (*((psbool)(PBSTART+0x1dc)))  /*                       ����������� ��� ����-35 1����� */
#define signal_R6IS65LDU     (*((psbool)(PBSTART+0x1de)))  /*                       ����������� ��� ����-35 2����� */
#define signal_R6IS66LZZ     (*((psbool)(PBSTART+0x1e0)))  /*                       ����������� ��� 4,0 (�5) ����-1-1 */
#define signal_R6IS67LZZ     (*((psbool)(PBSTART+0x1e2)))  /*                       ����������� ��� 4,0 (�6) ����-1-2 */
#define signal_R6IS68LZZ     (*((psbool)(PBSTART+0x1e4)))  /*                       ����������� ��� 4,0 (�7) ����-2 */
#define signal_A8IC01UDU     (*((pslong)(PBSTART+0x1e6)))  /*                       ���������� ��2 */
#define signal_B8IC01UDU     (*((pslong)(PBSTART+0x1eb)))  /*                       ���������� ��2 */
#define signal_A0VP81LZZ     (*((psbool)(PBSTART+0x1f0)))  /*                       �������� ��1 � ����� */
#define signal_B0VP81LZZ     (*((psbool)(PBSTART+0x1f2)))  /*                       �������� ��2 � ����� */
#define signal_A5IS11LDU     (*((psbool)(PBSTART+0x1f4)))  /*                       ������ �� �� ��1 */
#define signal_A5IS21LDU     (*((psbool)(PBSTART+0x1f6)))  /*                       ������ �� �� ��1 */
#define signal_B5IS11LDU     (*((psbool)(PBSTART+0x1f8)))  /*                       ������ �� �� ��2 */
#define signal_B5IS21LDU     (*((psbool)(PBSTART+0x1fa)))  /*                       ������ �� �� ��2 */
#define signal_A9IS11LDU     (*((psbool)(PBSTART+0x1fc)))  /*                       ������ �� �� �� ��1 */
#define signal_A9IS21LDU     (*((psbool)(PBSTART+0x1fe)))  /*                       ������ �� �� �� ��1 */
#define signal_B9IS11LDU     (*((psbool)(PBSTART+0x200)))  /*                       ������ �� �� �� ��2 */
#define signal_B9IS21LDU     (*((psbool)(PBSTART+0x202)))  /*                       ������ �� �� �� ��2 */
#define signal_B2IS21LDU     (*((psbool)(PBSTART+0x204)))  /*                       ������ �� �� ��2 */
#define signal_B2IS11LDU     (*((psbool)(PBSTART+0x206)))  /*                       ������ �� �� ��2 */
#define signal_B2IS12LDU     (*((psbool)(PBSTART+0x208)))  /*                       ������ ��2 �������� */
#define signal_B2IC01UDU     (*((pslong)(PBSTART+0x20a)))  /*                       ���������� ����� ��2 */
#define signal_B2IP01IZ1     (*((psint)(PBSTART+0x20f)))  /*                       ������� �������� ����� ��2 */
#define signal_B2IP01IZ2     (*((psint)(PBSTART+0x212)))  /*                       ������� �������� ����� ��2 */
#define signal_B2VP82LDU     (*((psbool)(PBSTART+0x215)))  /*                       �������� ���ڨ� ��2 � ����� */
#define signal_R3IS11LDU     (*((psbool)(PBSTART+0x217)))  /*                       ������ �� �� ���������� ������ */
#define signal_R3IS21LDU     (*((psbool)(PBSTART+0x219)))  /*                       ������ �� �� ���������� ������ */
#define signal_R5IS11LDU     (*((psbool)(PBSTART+0x21b)))  /*                       ������ �� �� ����� ��������� ���� */
#define signal_R5IS21LDU     (*((psbool)(PBSTART+0x21d)))  /*                       ������ �� �� ����� ��������� ���� */
#define signal_A4IS11LDU     (*((psbool)(PBSTART+0x21f)))  /*                       ������ �� �� ��1 */
#define signal_A4IS21LDU     (*((psbool)(PBSTART+0x221)))  /*                       ������ �� �� ��1 */
#define signal_R8IS11LDU     (*((psbool)(PBSTART+0x223)))  /*                       ��������� �� ���������� */
#define signal_B4IS11LDU     (*((psbool)(PBSTART+0x225)))  /*                       ������ �� �� ��2 */
#define signal_B4IS21LDU     (*((psbool)(PBSTART+0x227)))  /*                       ������ �� �� ��2 */
#define signal_R1IS11LDU     (*((psbool)(PBSTART+0x229)))  /*                       ������ �� �� ���1 */
#define signal_R1IS21LDU     (*((psbool)(PBSTART+0x22b)))  /*                       ������ �� �� ���1 */
#define signal_R2IS11LDU     (*((psbool)(PBSTART+0x22d)))  /*                       ������ �� �� ���2 */
#define signal_R2IS21LDU     (*((psbool)(PBSTART+0x22f)))  /*                       ������ �� �� ���2 */
#define signal_A4VP82LDU     (*((psbool)(PBSTART+0x231)))  /*                       �������� ���ڨ� ��1 � ����� */
#define signal_B4VP82LDU     (*((psbool)(PBSTART+0x233)))  /*                       �������� ���ڨ� ��2 � ����� */
#define signal_R4IS11LDU     (*((psbool)(PBSTART+0x235)))  /*                       ������ �� ��1 ������� */
#define signal_R4IS21LDU     (*((psbool)(PBSTART+0x237)))  /*                       ������ �� ��1 ������� */
#define signal_R4IS22LDU     (*((psbool)(PBSTART+0x239)))  /*                       ������ �� ��2 ������� */
#define signal_R4IS12LDU     (*((psbool)(PBSTART+0x23b)))  /*                       ������ ��  ��2 ������� */
#define signal_B8IS22LDU     (*((psbool)(PBSTART+0x23d)))  /*                       ������ �� ��2 ��2 */
#define signal_B8IS12LDU     (*((psbool)(PBSTART+0x23f)))  /*                       ������ �� ��2 ��2 */
#define signal_A8IS22LDU     (*((psbool)(PBSTART+0x241)))  /*                       ������ �� ������������ �� ��2 */
#define signal_A8IS12LDU     (*((psbool)(PBSTART+0x243)))  /*                       ������ �� ������������ �� ��2 */
#define signal_A6IS11LDU     (*((psbool)(PBSTART+0x245)))  /*                       ������ �� �� ��1 */
#define signal_A6IS21LDU     (*((psbool)(PBSTART+0x247)))  /*                       ������ �� �� ��1 */
#define signal_B6IS11LDU     (*((psbool)(PBSTART+0x249)))  /*                       ������ �� �� ��2 */
#define signal_B6IS21LDU     (*((psbool)(PBSTART+0x24b)))  /*                       ������ �� �� ��2 */
#define signal_A1IS21LDU     (*((psbool)(PBSTART+0x24d)))  /*                       ������ �� �� ��1 */
#define signal_A1IS11LDU     (*((psbool)(PBSTART+0x24f)))  /*                       ������ �� �� ��1 */
#define signal_A1IS12LDU     (*((psbool)(PBSTART+0x251)))  /*                       ������ ��1 �������� */
#define signal_A1IC01UDU     (*((pslong)(PBSTART+0x253)))  /*                       ���������� ����� ��1 */
#define signal_B1IC01UDU     (*((pslong)(PBSTART+0x258)))  /*                       ���������� ����� ��2 */
#define signal_B1IS21LDU     (*((psbool)(PBSTART+0x25d)))  /*                       ������ �� �� ��2 */
#define signal_B1IS11LDU     (*((psbool)(PBSTART+0x25f)))  /*                       ������ �� �� ��2 */
#define signal_B1IS12LDU     (*((psbool)(PBSTART+0x261)))  /*                       ������ ��2 �������� */
#define signal_A1IE03LDU     (*((psbool)(PBSTART+0x263)))  /*                       �������� ��1 ������ (�� ����) */
#define signal_A1IE04LDU     (*((psbool)(PBSTART+0x265)))  /*                       �������� ��1 ����� (�� ����) */
#define signal_B1IE03LDU     (*((psbool)(PBSTART+0x267)))  /*                       �������� ��2 ������ (�� ����) */
#define signal_B1IE04LDU     (*((psbool)(PBSTART+0x269)))  /*                       �������� ��2 ����� (�� ����) */
#define signal_A4IS10LDU     (*((psbool)(PBSTART+0x26b)))  /*                       ������ (������ ��1) ������ (���������) */
#define signal_B4IS10LDU     (*((psbool)(PBSTART+0x26d)))  /*                       ������ (������ ��2) ������ (���������) */
#define signal_R0EE01LZ1     (*((psbool)(PBSTART+0x26f)))  /*                       �������  ����1  ��������� */
#define signal_R0EE01LZ2     (*((psbool)(PBSTART+0x271)))  /*                       �������  ����1  ��������� */
#define signal_R0EE02LZ1     (*((psbool)(PBSTART+0x273)))  /*                       �������  ����  ��������� */
#define signal_R0EE03LZ1     (*((psbool)(PBSTART+0x275)))  /*                       �������  ����3  ��������� */
#define signal_R0EE04LZ1     (*((psbool)(PBSTART+0x277)))  /*                       �������  ����4  ��������� */
#define signal_R0EE02LZ2     (*((psbool)(PBSTART+0x279)))  /*                       �������  ����  ��������� */
#define signal_R0EE03LZ2     (*((psbool)(PBSTART+0x27b)))  /*                       �������  ����3  ��������� */
#define signal_R0EE04LZ2     (*((psbool)(PBSTART+0x27d)))  /*                       �������  ����4  ��������� */
#define signal_R0IS02LDU     (*((psbool)(PBSTART+0x27f)))  /*                       ���������� ����� �� ��������� */
#define signal_A3AD34LDU     (*((psbool)(PBSTART+0x281)))  /*                       ������ (���� ��1) ������� (����������) */
#define signal_A1IS11LIM     (*((psbool)(PBSTART+0x283)))  /*                       ������ ��1 ��������� */
#define signal_A1IS32LIM     (*((psbool)(PBSTART+0x285)))  /*                       ������ c����� ��1 ������(���������) */
#define signal_B1IS11LIM     (*((psbool)(PBSTART+0x287)))  /*                       ������ ��2 ��������� */
#define signal_B1IS32LIM     (*((psbool)(PBSTART+0x289)))  /*                       ������ c����� ��2 ������(���������) */
#define signal_A2IS11LIM     (*((psbool)(PBSTART+0x28b)))  /*                       ������ ��1 ��������� */
#define signal_A2IS32LIM     (*((psbool)(PBSTART+0x28d)))  /*                       ������ c����� ��1 ������(���������) */
#define signal_B2IS11LIM     (*((psbool)(PBSTART+0x28f)))  /*                       ������ ��2 ��������� */
#define signal_B2IS32LIM     (*((psbool)(PBSTART+0x291)))  /*                       ������ c����� ��2 ������(���������) */
#define signal_A0VN01RIM     (*((psfloat)(PBSTART+0x293)))  /*                       ������ �������  A�1 */
#define signal_B2IS33LDU     (*((psbool)(PBSTART+0x298)))  /*                       ������ (������ ��2)  ������ (���������) */
#define signal_B1VP81LZZ     (*((psbool)(PBSTART+0x29a)))  /*                       �������� ����� ��2 � ����� */
#define signal_A1VP81LZZ     (*((psbool)(PBSTART+0x29c)))  /*                       �������� ����� ��1 � ����� */
#define signal_B8IS11LDU     (*((psbool)(PBSTART+0x29e)))  /*                       ������ �� ��1 ��2 */
#define signal_B8IS21LDU     (*((psbool)(PBSTART+0x2a0)))  /*                       ������ �� ��1 ��2 */
#define signal_A6VS22LDU     (*((psbool)(PBSTART+0x2a2)))  /*                       �������� ������� ��1  � ������� */
#define signal_A6VS12LDU     (*((psbool)(PBSTART+0x2a4)))  /*                       �������� ������� ��1  �  ������� */
#define signal_B6VS22LDU     (*((psbool)(PBSTART+0x2a6)))  /*                       �������� ������� ��2  � ������� */
#define signal_B6VS12LDU     (*((psbool)(PBSTART+0x2a8)))  /*                       �������� ������� ��2  � ������� */
#define signal_A5VS22LDU     (*((psbool)(PBSTART+0x2aa)))  /*                       �������� ��1 � ������� �� */
#define signal_A5VS12LDU     (*((psbool)(PBSTART+0x2ac)))  /*                       �������� ��1 � ������� �� */
#define signal_B5VS22LDU     (*((psbool)(PBSTART+0x2ae)))  /*                       �������� ��2 � ������� �� */
#define signal_B5VS12LDU     (*((psbool)(PBSTART+0x2b0)))  /*                       �������� ��2 � ������� �� */
#define signal_R1VS22LDU     (*((psbool)(PBSTART+0x2b2)))  /*                       �������� ���1 � ������� �� */
#define signal_R2VS22LDU     (*((psbool)(PBSTART+0x2b4)))  /*                       �������� ���2 � ������� �� */
#define signal_R2VS12LDU     (*((psbool)(PBSTART+0x2b6)))  /*                       �������� ���2 � ������� �� */
#define signal_R1VS12LDU     (*((psbool)(PBSTART+0x2b8)))  /*                       �������� ���1 � ������� �� */
#define signal_R4VS22LDU     (*((psbool)(PBSTART+0x2ba)))  /*                       �������� �������� � �� �����ۻ */
#define signal_R4VS12LDU     (*((psbool)(PBSTART+0x2bc)))  /*                       �������� ��������  � �� �������» */
#define signal_A7AP31LDU     (*((psbool)(PBSTART+0x2dc)))  /*                       ������ (����� ��1) ������� (����������) */
#define signal_B7AP31LDU     (*((psbool)(PBSTART+0x2de)))  /*                       ������ (����� ��2) ������� (����������) */

/* ����������� �������� ��� � ������*/
struct      sbool  lRM_1_ = {    1,0}; /* ���� ������� ������� �� ����� ��� */ 
struct     sfloat  fRM_0_ = {    0,0}; /* �������� �������� �� ������ ��1 */ 
struct     sfloat  fRM_1_ = {    1,0}; /* *Vm - ������ ��������� �������� (����� � �������) */ 
struct      sbool  lRM_0_ = {    0,0}; /* ���� ������� ������� �� ����� ��� */ 
struct     sfloat  fRM_1_0 = {  1.0,0}; /* ����������� �������� �� (����/�) */ 
struct     sfloat  fRM_180_0 = {180.0,0}; /* ���������� �������� �������� ����������� �� ���� */ 
struct     sfloat  fRM_0_0 = {  0.0,0}; /* ���������� ������ ������ �� ���� */ 
struct     sfloat  fRM_n50_ = {  -50,0}; /* ���������� ������� �������� ����������� �� ���� */ 
struct     sfloat  fRM_2000_0 = {2000.0,0}; /* ���������� �������� �������� ����������� ��� �� */ 
struct     sfloat  fRM_n150_ = { -150,0}; /* ���������� ������� �������� ����������� ��� �� */ 
struct     sfloat  fRM_1500_0 = {1500.0,0}; /* ���������� �������� ������������� ����������� �� �� */ 
struct       sint  iRM_7_ = {    7,0}; /* N */ 
struct     sfloat  fRM_390_ = {  390,0}; /* Ai, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_420_ = {  420,0}; /* Ai, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_513_ = {  513,0}; /* Ai, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_767_ = {  767,0}; /* Ai, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_900_ = {  900,0}; /* Ai, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_1200_ = { 1200,0}; /* Ai, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_1500_ = { 1500,0}; /* Ai, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_3_546 = {3.546,0}; /* Bi, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_2_7 = {  2.7,0}; /* Bi, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_2_ = {    2,0}; /* Bi, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_0_88884 = {0.88884,0}; /* Bi, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_0_6221739 = {0.6221739,0}; /* Bi, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_0_35555072 = {0.35555072,0}; /* Bi, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_0_2666666667 = {0.2666666667,0}; /* Bi, i=1..N -�������� ������� ����� */ 
struct       sint  iRM_5_ = {    5,0}; /* N */ 
struct     sfloat  fRM_600_ = {  600,0}; /* Ai, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_0_5 = {  0.5,0}; /* Bi, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_0_2 = {  0.2,0}; /* Bi, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_0_088884 = {0.088884,0}; /* Bi, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_0_066666667 = {0.066666667,0}; /* Bi, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_0_02173913 = {0.02173913,0}; /* Bi, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_0_002453 = {0.002453,0}; /* Bi, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_0_00184 = {0.00184,0}; /* Bi, i=1..N -�������� ������� ����� */ 
struct     sfloat  fRM_0_10 = { 0.10,0}; /* ���� ������������ �� ��(��) */ 
struct     sfloat  fRM_0_50 = { 0.50,0}; /* ���� ������������ �� ��� (��) */ 
struct       sint  iRM_2_ = {    2,0}; /* n - N-����������� ������� x */ 
struct       sint  iRM_3_ = {    3,0}; /* N-����� ������ */ 
struct       sint  iRM_4_ = {    4,0}; /* N-����� ������ */ 
struct       sint  iRM_0_ = {    0,0}; /* Ter - ������������� ��������� */ 
struct     sfloat  fRM_100000_ = {100000,0}; /* KPv - ���������� ���. ����������� ��������� �� */ 
struct     sfloat  fRM_n100_ = { -100,0}; /* KZv - ���������� ���. ����������� ��������� �� */ 
struct     sfloat  fRM_20_ = {   20,0}; /* Tp - ��������� ���� �� */ 
struct      schar  bRM_2_ = {    2,0}; /* type - ��� ������ */ 
struct     sfloat  fRM_2_0 = {  2.0,0}; /* �����. �������������� �������->�����/�  ���11 */ 
struct      schar  bRM_4_ = {    4,0}; /* type - ��� ������ */ 
struct      schar  bRM_5_ = {    5,0}; /* type - ��� ������ */ 
struct      schar  bRM_1_ = {    1,0}; /* type - ��� ������ */ 
struct       sint  iRM_500_ = {  500,0}; /* tz - ������ ��������, 10-�� �� */ 
struct       sint  iRM_18_ = {   18,0}; /* n - ������ ������� �������� ���������� �������� ����������� ������ */ 
char                    sRM_1[] = "A3SS11LIM"; /* agr - ������������ ������� */ 
struct     sfloat  fRM_3_ = {    3,0}; /* m1 - �������� ���������� ������� ������� �� �������� */ 
struct       sint  iRM_719_ = {  719,0}; /* min - ����������� ��������� �������� ��������� ������� */ 
struct       sint  iRM_4195_ = { 4195,0}; /* max - ������������ ��������� �������� ��������� ������� */ 
struct     sfloat  fRM_819_ = {  819,0}; /* c   - ���. �������� ���� ��� */ 
struct     sfloat  fRM_4095_ = { 4095,0}; /* d - ����.  �������� ���� ��� */ 
struct     sfloat  fRM_200_ = {  200,0}; /* maxs1 - ���c. �������� ������� ������� */ 
struct     sfloat  fRM_0_0015 = {0.0015,0}; /* m1 - �������� ���������� ������� ������� �� �������� */ 
struct     sfloat  fRM_0_001 = {0.001,0}; /* ampl - ��������� ��������������� ���������� */ 
struct     sfloat  fRM_0_1 = {  0.1,0}; /* k - ����������� �������� */ 
struct       sint  iRM_16_ = {   16,0}; /* n - N-����������� ������� ������� ���������� */ 
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
#define fEM_A0UX00RSS  (*((psfloat)(SpaEEPROMBuf+0x177)))
#define fEM_R7UX01RSS  (*((psfloat)(SpaEEPROMBuf+0x17C)))
#define fEM_R7UX02RSS  (*((psfloat)(SpaEEPROMBuf+0x181)))
#define fEM_R7UX04RSS  (*((psfloat)(SpaEEPROMBuf+0x186)))
#define fEM_R7UX05RSS  (*((psfloat)(SpaEEPROMBuf+0x18B)))
#define fEM_R7UX06RSS  (*((psfloat)(SpaEEPROMBuf+0x190)))
#define fEM_R7UX07RSS  (*((psfloat)(SpaEEPROMBuf+0x195)))
#define fEM_R7UX08RSS  (*((psfloat)(SpaEEPROMBuf+0x19A)))
#define fEM_R7UX09RSS  (*((psfloat)(SpaEEPROMBuf+0x19F)))
#define fEM_R7UY01RSS  (*((psfloat)(SpaEEPROMBuf+0x1A4)))
#define fEM_R7UY02RSS  (*((psfloat)(SpaEEPROMBuf+0x1A9)))
#define fEM_R7UY04RSS  (*((psfloat)(SpaEEPROMBuf+0x1AE)))
#define fEM_R7UY05RSS  (*((psfloat)(SpaEEPROMBuf+0x1B3)))
#define fEM_R7UY06RSS  (*((psfloat)(SpaEEPROMBuf+0x1B8)))
#define fEM_R7UY07RSS  (*((psfloat)(SpaEEPROMBuf+0x1BD)))
#define fEM_R7UY08RSS  (*((psfloat)(SpaEEPROMBuf+0x1C2)))
#define fEM_R7UY09RSS  (*((psfloat)(SpaEEPROMBuf+0x1C7)))
#define fEM_R7UX10RSS  (*((psfloat)(SpaEEPROMBuf+0x1CC)))
#define fEM_R7UX11RSS  (*((psfloat)(SpaEEPROMBuf+0x1D1)))
#define fEM_R7UX12RSS  (*((psfloat)(SpaEEPROMBuf+0x1D6)))
#define fEM_R7UY10RSS  (*((psfloat)(SpaEEPROMBuf+0x1DB)))
#define fEM_R7UY11RSS  (*((psfloat)(SpaEEPROMBuf+0x1E0)))
#define fEM_R7UY12RSS  (*((psfloat)(SpaEEPROMBuf+0x1E5)))
#define fEM_A0UX01RSS  (*((psfloat)(SpaEEPROMBuf+0x1EA)))
#define fEM_A0UX02RSS  (*((psfloat)(SpaEEPROMBuf+0x1EF)))
#define fEM_A0UX03RSS  (*((psfloat)(SpaEEPROMBuf+0x1F4)))
#define fEM_A0UX04RSS  (*((psfloat)(SpaEEPROMBuf+0x1F9)))
#define fEM_A0UX05RSS  (*((psfloat)(SpaEEPROMBuf+0x1FE)))
#define fEM_A0UX06RSS  (*((psfloat)(SpaEEPROMBuf+0x203)))
#define fEM_A0UX07RSS  (*((psfloat)(SpaEEPROMBuf+0x208)))
#define fEM_A0UX08RSS  (*((psfloat)(SpaEEPROMBuf+0x20D)))
#define fEM_A0UX09RSS  (*((psfloat)(SpaEEPROMBuf+0x212)))
#define fEM_A0UX10RSS  (*((psfloat)(SpaEEPROMBuf+0x217)))
#define fEM_A0UX11RSS  (*((psfloat)(SpaEEPROMBuf+0x21C)))
#define fEM_A0UX12RSS  (*((psfloat)(SpaEEPROMBuf+0x221)))
#define fEM_B0UX01RSS  (*((psfloat)(SpaEEPROMBuf+0x226)))
#define fEM_B0UX02RSS  (*((psfloat)(SpaEEPROMBuf+0x22B)))
#define fEM_B0UX03RSS  (*((psfloat)(SpaEEPROMBuf+0x230)))
#define fEM_B0UX04RSS  (*((psfloat)(SpaEEPROMBuf+0x235)))
#define fEM_B0UX05RSS  (*((psfloat)(SpaEEPROMBuf+0x23A)))
#define fEM_B0UX06RSS  (*((psfloat)(SpaEEPROMBuf+0x23F)))
#define fEM_B0UX07RSS  (*((psfloat)(SpaEEPROMBuf+0x244)))
#define fEM_B0UX08RSS  (*((psfloat)(SpaEEPROMBuf+0x249)))
#define fEM_B0UX09RSS  (*((psfloat)(SpaEEPROMBuf+0x24E)))
#define fEM_B0UX10RSS  (*((psfloat)(SpaEEPROMBuf+0x253)))
#define fEM_B0UX11RSS  (*((psfloat)(SpaEEPROMBuf+0x258)))
#define fEM_B0UX12RSS  (*((psfloat)(SpaEEPROMBuf+0x25D)))
#define fEM_R0UH02RSS  (*((psfloat)(SpaEEPROMBuf+0x262)))
#define fEM_R0UH03RSS  (*((psfloat)(SpaEEPROMBuf+0x267)))
#define fEM_R4US80RDU  (*((psfloat)(SpaEEPROMBuf+0x26C)))
#define fEM_R7UI71RIM  (*((psfloat)(SpaEEPROMBuf+0x271)))
#define fEM_R7UI72RIM  (*((psfloat)(SpaEEPROMBuf+0x276)))
#define fEM_R7UI73RIM  (*((psfloat)(SpaEEPROMBuf+0x27B)))
#define fEM_A1UP01RIM  (*((psfloat)(SpaEEPROMBuf+0x280)))
#define fEM_A2UP01RIM  (*((psfloat)(SpaEEPROMBuf+0x285)))
#define fEM_A0UP02RIM  (*((psfloat)(SpaEEPROMBuf+0x28A)))
#define fEM_A3UP01RIM  (*((psfloat)(SpaEEPROMBuf+0x28F)))
#define fEM_A1UP82RIM  (*((psfloat)(SpaEEPROMBuf+0x294)))
#define fEM_A3UP02RDU  (*((psfloat)(SpaEEPROMBuf+0x299)))
#define fEM_A1UV02RIM  (*((psfloat)(SpaEEPROMBuf+0x29E)))
#define fEM_A3UV02RIM  (*((psfloat)(SpaEEPROMBuf+0x2A3)))
#define fEM_A2UV02RIM  (*((psfloat)(SpaEEPROMBuf+0x2A8)))
#define fEM_B8US80RDU  (*((psfloat)(SpaEEPROMBuf+0x2AD)))
#define fEM_A8US80RDU  (*((psfloat)(SpaEEPROMBuf+0x2B2)))
#define fEM_A6US80RDU  (*((psfloat)(SpaEEPROMBuf+0x2B7)))
#define fEM_A1US07RDU  (*((psfloat)(SpaEEPROMBuf+0x2BC)))
#define fEM_A2US07RDU  (*((psfloat)(SpaEEPROMBuf+0x2C1)))
#define fEM_A3US07RDU  (*((psfloat)(SpaEEPROMBuf+0x2C6)))
#define fEM_R7UI75RIM  (*((psfloat)(SpaEEPROMBuf+0x2CB)))
#define fEM_R0UH21RSS  (*((psfloat)(SpaEEPROMBuf+0x2D0)))
#define fEM_R0UH22RSS  (*((psfloat)(SpaEEPROMBuf+0x2D5)))
#define fEM_R0UH23RSS  (*((psfloat)(SpaEEPROMBuf+0x2DA)))
#define fEM_R0UR01RSS  (*((psfloat)(SpaEEPROMBuf+0x2DF)))
#define fEM_R0UL52RSS  (*((psfloat)(SpaEEPROMBuf+0x2E4)))
#define fEM_R0UL41RSS  (*((psfloat)(SpaEEPROMBuf+0x2E9)))
#define fEM_R0UL51RSS  (*((psfloat)(SpaEEPROMBuf+0x2EE)))
#define fEM_R0UL42RSS  (*((psfloat)(SpaEEPROMBuf+0x2F3)))
#define fEM_R0UH05RSS  (*((psfloat)(SpaEEPROMBuf+0x2F8)))
#define fEM_R0UN03RSS  (*((psfloat)(SpaEEPROMBuf+0x2FD)))
#define fEM_A4UL10RIM  (*((psfloat)(SpaEEPROMBuf+0x302)))
#define fEM_A9UL10RIM  (*((psfloat)(SpaEEPROMBuf+0x307)))
#define fEM_R3UL10RIM  (*((psfloat)(SpaEEPROMBuf+0x30C)))
#define fEM_R5UL10RIM  (*((psfloat)(SpaEEPROMBuf+0x311)))
#define fEM_R6UL10RIM  (*((psfloat)(SpaEEPROMBuf+0x316)))
#define lEM_C1AD31LRP  (*((psbool)(SpaEEPROMBuf+0x31B)))
#define lEM_R0IE01LRP  (*((psbool)(SpaEEPROMBuf+0x31D)))
#define lEM_R0IE02LRP  (*((psbool)(SpaEEPROMBuf+0x31F)))
#define fEM_A2UP02RIM  (*((psfloat)(SpaEEPROMBuf+0x321)))
#define fEM_A2UP03RIM  (*((psfloat)(SpaEEPROMBuf+0x326)))
#define fEM_A0UP01RIM  (*((psfloat)(SpaEEPROMBuf+0x32B)))
#define fEM_A3UP02RIM  (*((psfloat)(SpaEEPROMBuf+0x330)))
#define fEM_A4UP01RIM  (*((psfloat)(SpaEEPROMBuf+0x335)))
#define fEM_A4UP02RIM  (*((psfloat)(SpaEEPROMBuf+0x33A)))
#define fEM_R7UI76RIM  (*((psfloat)(SpaEEPROMBuf+0x33F)))
#define fEM_R7UI77RIM  (*((psfloat)(SpaEEPROMBuf+0x344)))
#define iEM_TERBB1  (*((psint)(SpaEEPROMBuf+0x349)))
#define fEM_A1MC02RC1  (*((psfloat)(SpaEEPROMBuf+0x34C)))
#define fEM_A1MV02RC1  (*((psfloat)(SpaEEPROMBuf+0x351)))
#define iEM_TERBB2  (*((psint)(SpaEEPROMBuf+0x356)))
#define fEM_B1MC02RC1  (*((psfloat)(SpaEEPROMBuf+0x359)))
#define fEM_B1MV02RC1  (*((psfloat)(SpaEEPROMBuf+0x35E)))
#define iEM_TERRB2  (*((psint)(SpaEEPROMBuf+0x363)))
#define fEM_B2MC02RC1  (*((psfloat)(SpaEEPROMBuf+0x366)))
#define fEM_B2MV02RC1  (*((psfloat)(SpaEEPROMBuf+0x36B)))
#define iEM_TERRB1  (*((psint)(SpaEEPROMBuf+0x370)))
#define fEM_A2MC02RC1  (*((psfloat)(SpaEEPROMBuf+0x373)))
#define fEM_A2MV02RC1  (*((psfloat)(SpaEEPROMBuf+0x378)))
#define iEM_TERIS2  (*((psint)(SpaEEPROMBuf+0x37D)))
#define fEM_B3MC02RC1  (*((psfloat)(SpaEEPROMBuf+0x380)))
#define fEM_B3MV02RC1  (*((psfloat)(SpaEEPROMBuf+0x385)))
#define iEM_TERIS1  (*((psint)(SpaEEPROMBuf+0x38A)))
#define fEM_A3MC02RC1  (*((psfloat)(SpaEEPROMBuf+0x38D)))
#define fEM_A3MV02RC1  (*((psfloat)(SpaEEPROMBuf+0x392)))
#define iEM_TERA1IE04LDU  (*((psint)(SpaEEPROMBuf+0x397)))
#define iEM_TERA1IE03LDU  (*((psint)(SpaEEPROMBuf+0x39A)))
#define fEM_A1MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x39D)))
#define iEM_TERB1IE03LDU  (*((psint)(SpaEEPROMBuf+0x3A2)))
#define iEM_TERB1IE04LDU  (*((psint)(SpaEEPROMBuf+0x3A5)))
#define fEM_B1MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x3A8)))
#define fEM_B1MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x3AD)))
#define fEM_B2MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x3B2)))
#define fEM_B2MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x3B7)))
#define fEM_A3MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x3BC)))
#define fEM_A3MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x3C1)))
#define fEM_B3MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x3C6)))
#define fEM_B3MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x3CB)))
#define iEM_TERA2SS21LIM  (*((psint)(SpaEEPROMBuf+0x3D0)))
#define iEM_TERA2SS12LIM  (*((psint)(SpaEEPROMBuf+0x3D3)))
#define iEM_TERR6SS21LIM  (*((psint)(SpaEEPROMBuf+0x3D6)))
#define iEM_TERA2VP82LIM  (*((psint)(SpaEEPROMBuf+0x3D9)))
#define iEM_TERA2SS11LIM  (*((psint)(SpaEEPROMBuf+0x3DC)))
#define iEM_TERB3SS21LIM  (*((psint)(SpaEEPROMBuf+0x3DF)))
#define iEM_TERA0MT01RIM  (*((psint)(SpaEEPROMBuf+0x3E2)))
#define iEM_TERB0MT01RIM  (*((psint)(SpaEEPROMBuf+0x3E5)))
#define iEM_TERA2SP01RIM  (*((psint)(SpaEEPROMBuf+0x3E8)))
#define iEM_TERB2SP01RIM  (*((psint)(SpaEEPROMBuf+0x3EB)))
#define iEM_TERB3SP02RIM  (*((psint)(SpaEEPROMBuf+0x3EE)))
#define iEM_TERA3SC01RIM  (*((psint)(SpaEEPROMBuf+0x3F1)))
#define iEM_TERA3VP81LIM  (*((psint)(SpaEEPROMBuf+0x3F4)))
#define iEM_TERA2SC01RIM  (*((psint)(SpaEEPROMBuf+0x3F7)))
#define iEM_TERA2SS33LIM  (*((psint)(SpaEEPROMBuf+0x3FA)))
#define iEM_TERA3SS21LIM  (*((psint)(SpaEEPROMBuf+0x3FD)))
#define iEM_TERA3SS33LIM  (*((psint)(SpaEEPROMBuf+0x400)))
#define iEM_TERA3SS31LIM  (*((psint)(SpaEEPROMBuf+0x403)))
#define iEM_TERB3SS31LIM  (*((psint)(SpaEEPROMBuf+0x406)))
#define iEM_TERB3SS33LIM  (*((psint)(SpaEEPROMBuf+0x409)))
#define iEM_TERB3SC01RIM  (*((psint)(SpaEEPROMBuf+0x40C)))
#define iEM_TERA3SS11LIM  (*((psint)(SpaEEPROMBuf+0x40F)))
#define iEM_TERB3SS11LIM  (*((psint)(SpaEEPROMBuf+0x412)))
#define iEM_TERR6IS64LIM  (*((psint)(SpaEEPROMBuf+0x415)))
#define iEM_TERB3SS22LIM  (*((psint)(SpaEEPROMBuf+0x418)))
#define iEM_TERA3SS22LIM  (*((psint)(SpaEEPROMBuf+0x41B)))
#define iEM_TERA3SP02RIM  (*((psint)(SpaEEPROMBuf+0x41E)))
#define iEM_TERR6IS62LIM  (*((psint)(SpaEEPROMBuf+0x421)))
#define iEM_TERR6IS66LIM  (*((psint)(SpaEEPROMBuf+0x424)))
#define iEM_TERR6IS67LIM  (*((psint)(SpaEEPROMBuf+0x427)))
#define iEM_TERA0VP81LIM  (*((psint)(SpaEEPROMBuf+0x42A)))
#define iEM_TERB0VP81LIM  (*((psint)(SpaEEPROMBuf+0x42D)))
#define iEM_TERR0VP81LIM  (*((psint)(SpaEEPROMBuf+0x430)))
#define iEM_TERR6IS68LIM  (*((psint)(SpaEEPROMBuf+0x433)))
#define iEM_TERR7SI74RIM  (*((psint)(SpaEEPROMBuf+0x436)))
#define iEM_TERA5SS21LIM  (*((psint)(SpaEEPROMBuf+0x439)))
#define iEM_TERB5SS11LIM  (*((psint)(SpaEEPROMBuf+0x43C)))
#define iEM_TERA5SS11LIM  (*((psint)(SpaEEPROMBuf+0x43F)))
#define iEM_TERA9SS11LIM  (*((psint)(SpaEEPROMBuf+0x442)))
#define iEM_TERB2SS11LIM  (*((psint)(SpaEEPROMBuf+0x445)))
#define iEM_TERB2SS12LIM  (*((psint)(SpaEEPROMBuf+0x448)))
#define iEM_TERB2SS21LIM  (*((psint)(SpaEEPROMBuf+0x44B)))
#define iEM_TERR3SS11LIM  (*((psint)(SpaEEPROMBuf+0x44E)))
#define iEM_TERB2SC01RIM  (*((psint)(SpaEEPROMBuf+0x451)))
#define iEM_TERR3SS21LIM  (*((psint)(SpaEEPROMBuf+0x454)))
#define iEM_TERR5SS11LIM  (*((psint)(SpaEEPROMBuf+0x457)))
#define iEM_TERA4SS11LIM  (*((psint)(SpaEEPROMBuf+0x45A)))
#define iEM_TERR1SS11LIM  (*((psint)(SpaEEPROMBuf+0x45D)))
#define iEM_TERR1SS21LIM  (*((psint)(SpaEEPROMBuf+0x460)))
#define iEM_TERR2SS11LIM  (*((psint)(SpaEEPROMBuf+0x463)))
#define iEM_TERR2SS21LIM  (*((psint)(SpaEEPROMBuf+0x466)))
#define iEM_TERA4VP82LIM  (*((psint)(SpaEEPROMBuf+0x469)))
#define iEM_TERB4SS21LIM  (*((psint)(SpaEEPROMBuf+0x46C)))
#define iEM_TERR5SS21LIM  (*((psint)(SpaEEPROMBuf+0x46F)))
#define iEM_TERB6SS21LIM  (*((psint)(SpaEEPROMBuf+0x472)))
#define iEM_TERB4SS11LIM  (*((psint)(SpaEEPROMBuf+0x475)))
#define iEM_TERA4SS21LIM  (*((psint)(SpaEEPROMBuf+0x478)))
#define iEM_TERA6MS11LIM  (*((psint)(SpaEEPROMBuf+0x47B)))
#define iEM_TERA6SS21LIM  (*((psint)(SpaEEPROMBuf+0x47E)))
#define iEM_TERB6SS11LIM  (*((psint)(SpaEEPROMBuf+0x481)))
#define iEM_TERR4SS11LIM  (*((psint)(SpaEEPROMBuf+0x484)))
#define iEM_TERR4MS21LIM  (*((psint)(SpaEEPROMBuf+0x487)))
#define iEM_TERR4SS12LIM  (*((psint)(SpaEEPROMBuf+0x48A)))
#define iEM_TERR4SS22LIM  (*((psint)(SpaEEPROMBuf+0x48D)))
#define iEM_TERR8SS11LIM  (*((psint)(SpaEEPROMBuf+0x490)))
#define iEM_TERB8SC01RIM  (*((psint)(SpaEEPROMBuf+0x493)))
#define iEM_TERA8SC01RIM  (*((psint)(SpaEEPROMBuf+0x496)))
#define iEM_TERB8SS12LIM  (*((psint)(SpaEEPROMBuf+0x499)))
#define iEM_TERA8SS12LIM  (*((psint)(SpaEEPROMBuf+0x49C)))
#define iEM_TERB8SS22LIM  (*((psint)(SpaEEPROMBuf+0x49F)))
#define iEM_TERA8SS22LIM  (*((psint)(SpaEEPROMBuf+0x4A2)))
#define iEM_TERA9SS21LIM  (*((psint)(SpaEEPROMBuf+0x4A5)))
#define iEM_TERB9SS21LIM  (*((psint)(SpaEEPROMBuf+0x4A8)))
#define iEM_TERB9SS11LIM  (*((psint)(SpaEEPROMBuf+0x4AB)))
#define iEM_TERB5SS21LIM  (*((psint)(SpaEEPROMBuf+0x4AE)))
#define iEM_TERA1SS21LIM  (*((psint)(SpaEEPROMBuf+0x4B1)))
#define iEM_TERA1SS11LIM  (*((psint)(SpaEEPROMBuf+0x4B4)))
#define iEM_TERA1SC01RIM  (*((psint)(SpaEEPROMBuf+0x4B7)))
#define iEM_TERA1SS12LIM  (*((psint)(SpaEEPROMBuf+0x4BA)))
#define iEM_TERB1SS21LIM  (*((psint)(SpaEEPROMBuf+0x4BD)))
#define iEM_TERB1SS11LIM  (*((psint)(SpaEEPROMBuf+0x4C0)))
#define iEM_TERB1MC01RIM  (*((psint)(SpaEEPROMBuf+0x4C3)))
#define iEM_TERB1SS12LIM  (*((psint)(SpaEEPROMBuf+0x4C6)))
#define iEM_TERR0IE43LIM  (*((psint)(SpaEEPROMBuf+0x4C9)))
#define iEM_TERR0IE41LIM  (*((psint)(SpaEEPROMBuf+0x4CC)))
#define lEM_A0EE06LC1  (*((psbool)(SpaEEPROMBuf+0x4CF)))
#define iEM_TERR0IE33LIM  (*((psint)(SpaEEPROMBuf+0x4D1)))
#define iEM_TERR0IE31LIM  (*((psint)(SpaEEPROMBuf+0x4D4)))
#define lEM_A0EE05LC1  (*((psbool)(SpaEEPROMBuf+0x4D7)))
#define iEM_TERR0IE11LIM  (*((psint)(SpaEEPROMBuf+0x4D9)))
#define iEM_TERR0IE13LIM  (*((psint)(SpaEEPROMBuf+0x4DC)))
#define lEM_A0EE03LC1  (*((psbool)(SpaEEPROMBuf+0x4DF)))
#define iEM_TERR0IE23LIM  (*((psint)(SpaEEPROMBuf+0x4E1)))
#define iEM_TERR0IE21LIM  (*((psint)(SpaEEPROMBuf+0x4E4)))
#define lEM_A0EE04LC1  (*((psbool)(SpaEEPROMBuf+0x4E7)))
#define iEM_TERTLG  (*((psint)(SpaEEPROMBuf+0x4E9)))
#define fEM_R4MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x4EC)))
#define fEM_R4MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x4F1)))
#define iEM_TERMAZ2  (*((psint)(SpaEEPROMBuf+0x4F6)))
#define fEM_B8MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x4F9)))
#define fEM_B8MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x4FE)))
#define iEM_TERDS2  (*((psint)(SpaEEPROMBuf+0x503)))
#define fEM_A8MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x506)))
#define fEM_A8MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x50B)))
#define iEM_TERBZ1  (*((psint)(SpaEEPROMBuf+0x510)))
#define fEM_A6MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x513)))
#define fEM_A6MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x518)))
#define iEM_TERBZ2  (*((psint)(SpaEEPROMBuf+0x51D)))
#define fEM_B6MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x520)))
#define fEM_B6MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x525)))
#define lEM_R3AD10LC1  (*((psbool)(SpaEEPROMBuf+0x52A)))
#define lEM_R3AD20LC1  (*((psbool)(SpaEEPROMBuf+0x52C)))
#define lEM_R6AD10LC1  (*((psbool)(SpaEEPROMBuf+0x52E)))
#define lEM_R5AD10LC1  (*((psbool)(SpaEEPROMBuf+0x530)))
#define lEM_R5AD20LC1  (*((psbool)(SpaEEPROMBuf+0x532)))
#define iEM_TERMDZ2  (*((psint)(SpaEEPROMBuf+0x534)))
#define fEM_R2MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x537)))
#define fEM_R2MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x53C)))
#define iEM_TERMDZ1  (*((psint)(SpaEEPROMBuf+0x541)))
#define fEM_R1MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x544)))
#define fEM_R1MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x549)))
#define iEM_TERNL1  (*((psint)(SpaEEPROMBuf+0x54E)))
#define fEM_A5MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x551)))
#define fEM_A5MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x556)))
#define iEM_TERNL2  (*((psint)(SpaEEPROMBuf+0x55B)))
#define fEM_B5MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x55E)))
#define fEM_B5MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x563)))
#define lEM_R8AD10LC1  (*((psbool)(SpaEEPROMBuf+0x568)))
#define fEM_A1UC08RIM  (*((psfloat)(SpaEEPROMBuf+0x56A)))
#define fEM_A2UC08RIM  (*((psfloat)(SpaEEPROMBuf+0x56F)))
#define fEM_A3UC08RIM  (*((psfloat)(SpaEEPROMBuf+0x574)))
#define fEM_R0UL01RSS  (*((psfloat)(SpaEEPROMBuf+0x579)))
#define fEM_R0UL03RSS  (*((psfloat)(SpaEEPROMBuf+0x57E)))
#define iEM_TERB2SS33LIM  (*((psint)(SpaEEPROMBuf+0x583)))
#define iEM_TERA1VP81LIM  (*((psint)(SpaEEPROMBuf+0x586)))
#define iEM_TERB1VP81LIM  (*((psint)(SpaEEPROMBuf+0x589)))
#define fEM_A0UT03RSP  (*((psfloat)(SpaEEPROMBuf+0x58C)))
#define fEM_A0UR01RSP  (*((psfloat)(SpaEEPROMBuf+0x591)))
#define fEM_A0UR02RSP  (*((psfloat)(SpaEEPROMBuf+0x596)))
#define fEM_B0UT03RSP  (*((psfloat)(SpaEEPROMBuf+0x59B)))
#define fEM_A1MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x5A0)))
#define fEM_A1MC02RSP  (*((psfloat)(SpaEEPROMBuf+0x5A5)))
#define fEM_A1MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x5AA)))
#define fEM_A1MV02RSP  (*((psfloat)(SpaEEPROMBuf+0x5AF)))
#define fEM_B1MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x5B4)))
#define fEM_B1MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x5B9)))
#define fEM_B1MC02RSP  (*((psfloat)(SpaEEPROMBuf+0x5BE)))
#define fEM_B1MV02RSP  (*((psfloat)(SpaEEPROMBuf+0x5C3)))
#define fEM_A2MC01RC1  (*((psfloat)(SpaEEPROMBuf+0x5C8)))
#define fEM_A2MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x5CD)))
#define fEM_A2MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x5D2)))
#define fEM_A2MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x5D7)))
#define fEM_A2MC02RSP  (*((psfloat)(SpaEEPROMBuf+0x5DC)))
#define fEM_A2MV02RSP  (*((psfloat)(SpaEEPROMBuf+0x5E1)))
#define fEM_B2MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x5E6)))
#define fEM_B2MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x5EB)))
#define fEM_B2MC02RSP  (*((psfloat)(SpaEEPROMBuf+0x5F0)))
#define fEM_B2MV02RSP  (*((psfloat)(SpaEEPROMBuf+0x5F5)))
#define fEM_A3MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x5FA)))
#define fEM_A3MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x5FF)))
#define fEM_A3MC02RSP  (*((psfloat)(SpaEEPROMBuf+0x604)))
#define fEM_A3MV02RSP  (*((psfloat)(SpaEEPROMBuf+0x609)))
#define fEM_B3MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x60E)))
#define fEM_B3MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x613)))
#define fEM_B3MC02RSP  (*((psfloat)(SpaEEPROMBuf+0x618)))
#define fEM_B3MV02RSP  (*((psfloat)(SpaEEPROMBuf+0x61D)))
#define fEM_B8MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x622)))
#define fEM_B8MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x627)))
#define fEM_A8MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x62C)))
#define fEM_A8MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x631)))
#define fEM_A6MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x636)))
#define fEM_A6MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x63B)))
#define fEM_B6MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x640)))
#define fEM_B6MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x645)))
#define fEM_R3UC01RSP  (*((psfloat)(SpaEEPROMBuf+0x64A)))
#define fEM_R3UV01RSP  (*((psfloat)(SpaEEPROMBuf+0x64F)))
#define fEM_R5UC01RSP  (*((psfloat)(SpaEEPROMBuf+0x654)))
#define fEM_R5UV01RSP  (*((psfloat)(SpaEEPROMBuf+0x659)))
#define fEM_R6UC01RSP  (*((psfloat)(SpaEEPROMBuf+0x65E)))
#define fEM_R6UV01RSP  (*((psfloat)(SpaEEPROMBuf+0x663)))
#define fEM_R2MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x668)))
#define fEM_R2MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x66D)))
#define fEM_R1MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x672)))
#define fEM_R1MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x677)))
#define fEM_A5MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x67C)))
#define fEM_A5MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x681)))
#define fEM_B5MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x686)))
#define fEM_B5MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x68B)))
#define fEM_A9MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x690)))
#define fEM_A9MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x695)))
#define fEM_B9MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x69A)))
#define fEM_B9MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x69F)))
#define fEM_A4MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x6A4)))
#define fEM_A4MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x6A9)))
#define fEM_B4MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x6AE)))
#define fEM_B4MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x6B3)))
#define fEM_R4MC01RSP  (*((psfloat)(SpaEEPROMBuf+0x6B8)))
#define fEM_R4MV01RSP  (*((psfloat)(SpaEEPROMBuf+0x6BD)))
#define fEM_A1MV01RC1  (*((psfloat)(SpaEEPROMBuf+0x6C2)))
#define iEM_TERB7MS31LIM  (*((psint)(SpaEEPROMBuf+0x6C7)))
#define iEM_TERA7MS31LIM  (*((psint)(SpaEEPROMBuf+0x6CA)))
#define fEM_R7UX03RSS  (*((psfloat)(SpaEEPROMBuf+0x6CD)))
#define fEM_R7UY03RSS  (*((psfloat)(SpaEEPROMBuf+0x6D2)))
#define fEM_R7UY00RSS  (*((psfloat)(SpaEEPROMBuf+0x6D7)))
#define iEM_TERA6VS12LIM  (*((psint)(SpaEEPROMBuf+0x6DC)))
#define iEM_TERA6VS22LIM  (*((psint)(SpaEEPROMBuf+0x6DF)))
#define iEM_TERB6VS12LIM  (*((psint)(SpaEEPROMBuf+0x6E2)))
#define iEM_TERB6VS22LIM  (*((psint)(SpaEEPROMBuf+0x6E5)))
#define iEM_TERA5VS22LIM  (*((psint)(SpaEEPROMBuf+0x6E8)))
#define iEM_TERA5VS12LIM  (*((psint)(SpaEEPROMBuf+0x6EB)))
#define iEM_TERB5VS12LIM  (*((psint)(SpaEEPROMBuf+0x6EE)))
#define iEM_TERB5VS22LIM  (*((psint)(SpaEEPROMBuf+0x6F1)))
#define iEM_TERR1VS12LIM  (*((psint)(SpaEEPROMBuf+0x6F4)))
#define iEM_TERR1VS22LIM  (*((psint)(SpaEEPROMBuf+0x6F7)))
#define iEM_TERR2VS12LIM  (*((psint)(SpaEEPROMBuf+0x6FA)))
#define iEM_TERR2VS22LIM  (*((psint)(SpaEEPROMBuf+0x6FD)))
#define iEM_TERR4VS12LDU  (*((psint)(SpaEEPROMBuf+0x700)))
#define iEM_TERR4VS22LDU  (*((psint)(SpaEEPROMBuf+0x703)))

int SpaEEPROMBufSize = 1798;

/* ����������� ���������� */
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
struct sfloat  var33;
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
struct sbool  var51;
struct sbool  var52;
struct sbool  var53;
struct sbool  var54;
struct sbool  var55;
struct sbool  var56;
struct sbool  var57;
struct sbool  var58;
struct slong  var59;
struct sfloat  var60;
struct slong  var61;
struct sfloat  var62;
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
struct sbool  var89;
struct sbool  var90;
struct sbool  var91;
struct sbool  var92;
struct sbool  var93;
struct sbool  var94;
struct sbool  var95;
struct sbool  var96;
struct sint  var97;
struct sint  var98;
struct sfloat  var99;
struct sfloat  var100;
struct slong  var101;
struct sfloat  var102;
struct sbool  var103;
struct sbool  var104;
struct sbool  var105;
struct sbool  var106;
struct sbool  var107;
struct sbool  var108;
struct sbool  var109;
struct sbool  var110;
struct sbool  var111;
struct sbool  var112;
struct sbool  var113;
struct sfloat  var114;
struct sbool  var115;
struct sbool  var116;
struct slong  var117;
struct sfloat  var118;
struct slong  var119;
struct sfloat  var120;
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
struct sint  var132;
struct sfloat  var133;
struct sbool  var134;
struct sbool  var135;
struct sint  var136;
struct sfloat  var137;
struct sbool  var138;
struct slong  var139;
struct sfloat  var140;
struct sbool  var141;
struct sbool  var142;
struct slong  var143;
struct sfloat  var144;
struct sbool  var145;
struct sint  var146;
struct sint  var147;
struct sbool  var148;
struct sbool  var149;
struct sbool  var150;
struct slong  var151;
struct sfloat  var152;
struct sbool  var153;
struct sbool  var154;
struct sbool  var155;
struct sfloat  var156;
struct sfloat  var157;
struct sfloat  var158;
struct sint  var159;
struct sint  var160;
struct sfloat  var161;
struct sfloat  var162;
struct sfloat  var163;
struct sint  var164;
struct sbool  var165;
struct sbool  var166;
struct sint  var167;
struct sfloat  var168;
struct sfloat  var169;
struct sfloat  var170;
struct sbool  var171;
struct sbool  var172;
struct sbool  var173;
struct sbool  var174;
struct sfloat  var175;
struct sbool  var176;
struct sbool  var177;
struct sbool  var178;
struct sbool  var179;
struct sbool  var180;
struct sfloat  var181;
struct sbool  var182;
struct sint  var183;
struct sbool  var184;
struct sbool  var185;
struct sbool  var186;
struct sbool  var187;
struct sfloat  var188;
struct sbool  var189;
struct sbool  var190;
struct sbool  var191;
struct sbool  var192;
struct sbool  var193;
struct sfloat  var194;
struct sbool  var195;
struct sint  var196;
struct sbool  var197;
struct sbool  var198;
struct sbool  var199;
struct sbool  var200;
struct sfloat  var201;
struct sbool  var202;
struct sbool  var203;
struct sbool  var204;
struct sbool  var205;
struct sbool  var206;
struct sfloat  var207;
struct sbool  var208;
struct sint  var209;
struct sbool  var210;
struct sbool  var211;
struct sbool  var212;
struct sbool  var213;
struct sfloat  var214;
struct sbool  var215;
struct sbool  var216;
struct sbool  var217;
struct sbool  var218;
struct sbool  var219;
struct sfloat  var220;
struct sbool  var221;
struct sint  var222;
struct sbool  var223;
struct sbool  var224;
struct sbool  var225;
struct sbool  var226;
struct sfloat  var227;
struct sbool  var228;
struct sfloat  var229;
struct sbool  var230;
struct sbool  var231;
struct sbool  var232;
struct sbool  var233;
struct sbool  var234;
struct sbool  var235;
struct sbool  var236;
struct sbool  var237;
struct sbool  var238;
struct sbool  var239;
struct sfloat  var240;
struct sbool  var241;
struct sbool  var242;
struct sbool  var243 = {0,0};
struct sbool  var244 = {0,0};
struct sbool  var245 = {0,0};
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
struct sbool  var258;
struct sbool  var259;
struct sbool  var260;
struct sbool  var261;
struct sbool  var262;
struct sbool  var263;
struct sbool  var264;
struct sbool  var265;
struct sbool  var266;
struct sbool  var267;
struct sbool  var268;
struct sbool  var269;
struct sbool  var270;
struct sbool  var271;
struct sbool  var272;
struct sbool  var273;
struct sbool  var274;
struct sbool  var275;
struct sbool  var276;
struct sbool  var277;
struct sbool  var278;
struct sbool  var279;
struct sfloat  var280;
struct sfloat  var281;
struct sfloat  var282;
struct sfloat  var283;
struct sfloat  var284;
struct sfloat  var285;
struct sfloat  var286;
struct sfloat  var287;
struct sfloat  var288;
struct sbool  var289;
struct sbool  var290;
struct sbool  var291;
struct sfloat  var292;
struct sfloat  var293;
struct sfloat  var294;
struct sfloat  var295;
struct sfloat  var296;
struct sfloat  var297;
struct sfloat  var298;
struct sfloat  var299;
struct sfloat  var300;
struct sfloat  var301;
struct sfloat  var302;
struct sfloat  var303;
struct sfloat  var304;
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
struct sfloat  var329;
struct sbool  var330;
struct sbool  var331;
struct sfloat  var332;
struct sbool  var333;
struct sbool  var334;
struct sbool  var335;
struct sbool  var336;
struct sbool  var337;
struct sbool  var338;
struct sbool  var339;
struct sbool  var340;
struct sfloat  var341;
struct sfloat  var342;
struct sfloat  var343;
struct sfloat  var344;
struct sbool  var345;
struct sfloat  var346;
struct sfloat  var347;
struct sfloat  var348;
struct sfloat  var349;
struct sbool  var350;
struct sbool  var351;
struct sbool  var352;
struct sbool  var353;
struct sbool  var354;
struct sfloat  var355;
struct sfloat  var356;
struct sbool  var357;
struct sbool  var358;
struct sbool  var359;
struct sbool  var360;
struct sbool  var361;
struct sfloat  var362;
struct sfloat  var363;
struct sbool  var364;
struct sbool  var365;
struct sbool  var366;
struct sbool  var367;
struct sbool  var368;
struct sbool  var369;
struct sfloat  var370;
struct sfloat  var371;
struct sbool  var372;
struct sbool  var373;
struct sbool  var374;
struct sbool  var375;
struct sbool  var376;
struct sbool  var377;
struct sfloat  var378;
struct sfloat  var379;
struct sbool  var380;
struct sbool  var381;
struct sbool  var382;
struct sbool  var383;
struct sbool  var384;
struct sfloat  var385;
struct sfloat  var386;
struct sbool  var387;
struct sbool  var388;
struct sbool  var389;
struct sbool  var390;
struct sbool  var391;
struct sfloat  var392 = {0,0};
struct sfloat  var393;
struct sfloat  var394;
struct sfloat  var395;
struct sbool  var396;
struct sfloat  var397;
struct slong  vainSLong;
struct sfloat  vainSFloat;
struct sint  vainSInt;
struct sbool  vainSBool;
struct schar  vainSChar;
char  vainSText[] = "";

/* ���������� �������� */
psbool  array_m355_x_1[16] = {&var396,&var345,&var391,&var248,&var242,&var333,&var331,&var325,&var322,&var338,&var381,&var376,&var367,&var357,&var351,NULL};
psfloat  array_m1082_tst_1[2];
psfloat  array_m1082_trz_1[2];
psfloat  array_m1082_N1_1[2];
psfloat  array_m1082_N2_1[2];
psfloat  array_m1024_tst_1[2];
psfloat  array_m1024_trz_1[2];
psfloat  array_m1024_N1_1[2];
psfloat  array_m1024_N2_1[2];
psfloat  array_m896_tst_1[2];
psfloat  array_m896_trz_1[2];
psfloat  array_m896_N1_1[2];
psfloat  array_m896_N2_1[2];
psfloat  array_m841_tst_1[2];
psfloat  array_m841_trz_1[2];
psfloat  array_m841_N1_1[2];
psfloat  array_m841_N2_1[2];
psbool  array_m1179_x_1[2] = {NULL,NULL};
psbool  array_m1176_x_1[2] = {&var225,NULL};
psbool  array_m1197_x_1[2] = {&var233,NULL};
psbool  array_m1192_x_1[2] = {&var235,NULL};
psbool  array_m1186_x_1[2] = {&var237,NULL};
psbool  array_m632_x_1[2] = {&var27,&var290};
psbool  array_m629_x_1[2] = {&var27,&var291};
psbool  array_m639_x_1[3] = {NULL,NULL,NULL};
psbool  array_m1181_x_1[2] = {&var261,NULL};
psbool  array_m290_x_1[2] = {&var278,NULL};
psbool  array_m255_x_1[3] = {NULL,&var264,&var278};
psbool  array_m256_x_1[3] = {NULL,&var264,&var278};
psbool  array_m216_x_1[4] = {NULL,&var267,&var266,&var278};
psbool  array_m215_x_1[4] = {&var267,NULL,&var266,&var278};
psbool  array_m121_x_1[2] = {NULL,&var278};
psbool  array_m48_x_1[4] = {NULL,&var272,&var271,&var278};
psbool  array_m47_x_1[4] = {&var272,NULL,&var271,&var278};
psbool  array_m87_x_1[3] = {NULL,&var276,&var278};
psbool  array_m88_x_1[3] = {NULL,&var276,&var278};
psbool  array_m645_x_1[2] = {&var289,&var26};
psfloat  array_m7_a_1[5] = {&fRM_390_,&fRM_600_,&fRM_900_,&fRM_1200_,&fRM_1500_};
psfloat  array_m7_b_1[5] = {&fRM_0_5,&fRM_0_2,&fRM_0_088884,&fRM_0_066666667,&fRM_0_02173913};
psfloat  array_m9_a_1[7] = {&fRM_390_,&fRM_420_,&fRM_513_,&fRM_767_,&fRM_900_,&fRM_1200_,&fRM_1500_};
psfloat  array_m9_b_1[7] = {&fRM_3_546,&fRM_2_7,&fRM_2_,&fRM_0_88884,&fRM_0_6221739,&fRM_0_35555072,&fRM_0_2666666667};
psfloat  array_m180_C0_1[6];
psfloat  array_m301_Vr_1[8] = {&fRM_1_,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
psfloat  array_m130_Vr_1[8] = {&fRM_1_,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
psfloat  array_m265_Vr_1[8] = {&fRM_1_,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
psfloat  array_m97_Vr_1[8] = {&fRM_1_,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
psfloat  array_m227_Vr_1[8] = {&fRM_1_,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
psfloat  array_m59_Vr_1[8] = {&fRM_1_,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
psfloat  array_m14_C0_1[6];

/* �������� �������� ��� �-�� */

/* ��� ���������� */
/* ���������� �������� */
_S_twobool far S_twobool_1118_1 = {&var340,NULL,&var1,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1117_1 = {&var339,NULL,&var2,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_943_1 = {&var316,NULL,&var3,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_942_1 = {&var315,NULL,&var4,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_941_1 = {&var320,NULL,&var5,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_940_1 = {&var319,NULL,&var6,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_691_1 = {&var308,NULL,&var7,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_690_1 = {&var307,NULL,&var8,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_669_1 = {&var312,NULL,&var9,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_668_1 = {&var311,NULL,&var10,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_689_1 = {&var324,NULL,&var11,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_688_1 = {&var323,NULL,&var12,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_667_1 = {&var328,NULL,&var13,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_666_1 = {&var327,NULL,&var14,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_527_1 = {&var32,NULL,&var15,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_545_1 = {&var32,NULL,&var16,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_409_1 = {&var367,NULL,&var17,&vainSBool,NULL,NULL};
_S_noto far S_noto_488_1 = {&var244,&var18};
_S_noto far S_noto_489_1 = {&var243,&var19};
_S_noto far S_noto_477_1 = {&var245,&var20};
_S_noto far S_noto_479_1 = {&var246,&var21};
_S_rs far S_rs_486_1 = {&var19,NULL,&var22,&vainSBool,NULL};
_S_rs far S_rs_487_1 = {&var18,NULL,&var23,&vainSBool,NULL};
_S_rs far S_rs_472_1 = {&var20,NULL,&var24,&vainSBool,NULL};
_S_rs far S_rs_473_1 = {&var21,NULL,&var25,&vainSBool,NULL};
_S_andn far S_andn_355_1 = {array_m355_x_1,&iRM_16_,&vainSBool};
_S_zpfs far S_zpfs_642_1 = {NULL,NULL,&var26,NULL,NULL};
_S_zpfs far S_zpfs_630_1 = {NULL,NULL,&var27,NULL,NULL};
_S_bol far S_bol_1214_1 = {NULL,NULL,&var28};
_S_bol far S_bol_1216_1 = {NULL,NULL,&var29};
_S_bol far S_bol_1211_1 = {NULL,NULL,&var30};
_S_bol far S_bol_1208_1 = {NULL,NULL,&var31};
_S_bol far S_bol_1207_1 = {NULL,NULL,&var32};
_S_ampl far S_ampl_372_1 = {&var280,&fRM_0_1,&var33};
_S_or2 far S_or2_1199_1 = {NULL,NULL,&var34};
_S_or2 far S_or2_1194_1 = {NULL,NULL,&var35};
_S_or2 far S_or2_1188_1 = {NULL,NULL,&var36};
_S_or2 far S_or2_1183_1 = {NULL,NULL,&var37};
_S_and5 far S_and5_1098_1 = {&var182,&var173,&var174,&var172,NULL,&var38};
_S_and2 far S_and2_1092_1 = {&var177,&var176,&var39};
_S_and2 far S_and2_1091_1 = {&var177,&var178,&var40};
_S_and5 far S_and5_913_1 = {&var208,&var198,&var199,&var200,NULL,&var41};
_S_and2 far S_and2_907_1 = {&var203,&var202,&var42};
_S_and2 far S_and2_906_1 = {&var203,&var204,&var43};
_S_and2 far S_and2_1034_1 = {&var190,&var189,&var44};
_S_and2 far S_and2_1033_1 = {&var191,&var190,&var45};
_S_and5 far S_and5_1041_1 = {&var195,&var186,&var185,&var187,NULL,&var46};
_S_and5 far S_and5_854_1 = {&var221,&var212,&var211,&var213,NULL,&var47};
_S_and2 far S_and2_852_1 = {&var216,&var215,&var48};
_S_and2 far S_and2_851_1 = {&var216,&var217,&var49};
_S_zpfs far S_zpfs_616_1 = {&var247,&fRM_1_0,&var50,NULL,NULL};
_S_zpfs far S_zpfs_614_1 = {&var250,&fRM_0_5,&var51,NULL,NULL};
_S_twobool far S_twobool_206_1 = {NULL,NULL,&var52,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_224_1 = {NULL,NULL,&var53,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_41_1 = {NULL,NULL,&var54,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_56_1 = {NULL,NULL,&var55,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1241_1 = {&var384,NULL,&var56,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1238_1 = {&var380,NULL,&var57,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1237_1 = {&var381,NULL,&var58,&vainSBool,NULL,NULL};
_S_ktoenc far S_ktoenc_1240_1 = {&var60,NULL,&fRM_0_,&iRM_0_,&var59,&vainSBool,&vainSBool,&vainSBool,&vainSLong,NULL,NULL};
_S_to3val far S_to3val_1235_1 = {&var283,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,NULL,&var60,&vainSFloat,&vainSFloat,NULL};
_S_ktoenc far S_ktoenc_1226_1 = {&var62,NULL,&fRM_0_,&iRM_0_,&var61,&vainSBool,&vainSBool,&vainSBool,&vainSLong,NULL,NULL};
_S_to3val far S_to3val_1221_1 = {&var284,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,NULL,&var62,&vainSFloat,&vainSFloat,NULL};
_S_twobool far S_twobool_1227_1 = {&var391,NULL,&var63,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1224_1 = {&var388,NULL,&var64,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1223_1 = {&var389,NULL,&var65,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_981_1 = {&var322,NULL,&var66,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_962_1 = {&var321,NULL,&var67,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_961_1 = {&var326,NULL,&var68,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_960_1 = {&var325,NULL,&var69,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1139_1 = {&var331,NULL,&var70,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1141_1 = {&var330,NULL,&var71,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1138_1 = {&var334,NULL,&var72,&var73,NULL,NULL};
_S_twobool far S_twobool_1140_1 = {&var333,NULL,&var74,&var75,NULL,NULL};
_S_twobool far S_twobool_1114_1 = {&var335,NULL,&var76,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1115_1 = {&var336,NULL,&var77,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1113_1 = {&var338,NULL,&var78,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1112_1 = {&var337,NULL,&var79,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_976_1 = {&var28,NULL,&var80,&var81,NULL,NULL};
_S_twobool far S_twobool_928_1 = {&var314,NULL,&var82,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_927_1 = {&var313,NULL,&var83,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_926_1 = {&var318,NULL,&var84,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_925_1 = {&var317,NULL,&var85,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_977_1 = {&var252,NULL,&var86,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_958_1 = {&var251,NULL,&var87,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1116_1 = {NULL,NULL,&var88,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_959_1 = {&var249,NULL,&var89,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_957_1 = {&var248,NULL,&var90,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_978_1 = {&var244,NULL,&var91,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_956_1 = {&var243,NULL,&var92,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_939_1 = {&var246,NULL,&var93,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_924_1 = {&var245,NULL,&var94,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_543_1 = {&var31,NULL,&var95,&var96,NULL,NULL};
_S_toao far S_toao_544_1 = {&var100,NULL,NULL,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var97,NULL};
_S_toao far S_toao_550_1 = {&var99,NULL,NULL,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var98,NULL};
_S_to3val far S_to3val_541_1 = {&var157,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,NULL,NULL,NULL,&var99,&vainSFloat,&var100,NULL};
_S_ktoenc far S_ktoenc_419_1 = {&var102,NULL,&fRM_0_,&iRM_0_,&var101,&vainSBool,&vainSBool,&vainSBool,&vainSLong,NULL,NULL};
_S_to3val far S_to3val_413_1 = {&var282,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,NULL,&var102,&vainSFloat,&vainSFloat,NULL};
_S_twobool far S_twobool_410_1 = {&var369,NULL,&var103,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_412_1 = {&var364,NULL,&var104,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_411_1 = {&var365,NULL,&var105,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1154_1 = {&var258,NULL,&var106,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1155_1 = {&var257,NULL,&var107,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1153_1 = {&var255,NULL,&var108,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_980_1 = {&var254,NULL,&var109,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_704_1 = {&var306,NULL,&var110,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_705_1 = {&var305,NULL,&var111,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_702_1 = {&var310,NULL,&var112,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_703_1 = {&var309,NULL,&var113,&vainSBool,NULL,NULL};
_S_ampl far S_ampl_655_1 = {&var288,NULL,&var114};
_S_to3val far S_to3val_656_1 = {&var114,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,NULL,NULL,NULL,&vainSFloat,&vainSFloat,&vainSFloat,NULL};
_S_twobool far S_twobool_561_1 = {&var30,NULL,&var115,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_560_1 = {&var30,NULL,&var116,&vainSBool,NULL,NULL};
_S_ktoenc far S_ktoenc_1135_1 = {&var118,NULL,&fRM_0_,&iRM_0_,&var117,&vainSBool,&vainSBool,&vainSBool,&vainSLong,NULL,NULL};
_S_to3val far S_to3val_1127_1 = {&var332,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,NULL,&var118,&vainSFloat,&vainSFloat,NULL};
_S_ktoenc far S_ktoenc_1137_1 = {&var120,NULL,&fRM_0_,&iRM_0_,&var119,&vainSBool,&vainSBool,&vainSBool,&vainSLong,NULL,NULL};
_S_to3val far S_to3val_1129_1 = {&var329,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,NULL,&var120,&vainSFloat,&vainSFloat,NULL};
_S_twobool far S_twobool_701_1 = {NULL,NULL,&var121,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_685_1 = {NULL,NULL,&var122,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_665_1 = {NULL,NULL,&var123,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_684_1 = {NULL,NULL,&var124,&var125,NULL,NULL};
_S_twobool far S_twobool_664_1 = {NULL,NULL,&var126,&var127,NULL,NULL};
_S_twobool far S_twobool_337_1 = {&var350,NULL,&var128,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_336_1 = {&var357,NULL,&var129,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_321_1 = {&var351,NULL,&var130,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_320_1 = {&var358,NULL,&var131,&vainSBool,NULL,NULL};
_S_toao far S_toao_521_1 = {&var133,NULL,NULL,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var132,NULL};
_S_to3val far S_to3val_515_1 = {&var229,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,NULL,NULL,NULL,&vainSFloat,&var133,&vainSFloat,NULL};
_S_twobool far S_twobool_562_1 = {&var29,NULL,&var134,&var135,NULL,NULL};
_S_toao far S_toao_525_1 = {&var137,NULL,NULL,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var136,NULL};
_S_to3val far S_to3val_518_1 = {&var227,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,NULL,NULL,NULL,&vainSFloat,&var137,&vainSFloat,NULL};
_S_twobool far S_twobool_350_1 = {&var354,NULL,&var138,&vainSBool,NULL,NULL};
_S_ktoenc far S_ktoenc_334_1 = {&var140,NULL,&fRM_0_,&iRM_0_,&var139,&vainSBool,&vainSBool,&vainSBool,&vainSLong,NULL,NULL};
_S_to3val far S_to3val_333_1 = {&var349,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,NULL,&var140,&vainSFloat,&vainSFloat,NULL};
_S_twobool far S_twobool_349_1 = {&var353,NULL,&var141,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_347_1 = {&var361,NULL,&var142,&vainSBool,NULL,NULL};
_S_ktoenc far S_ktoenc_327_1 = {&var144,NULL,&fRM_0_,&iRM_0_,&var143,&vainSBool,&vainSBool,&vainSBool,&vainSLong,NULL,NULL};
_S_to3val far S_to3val_323_1 = {&var356,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,NULL,&var144,&vainSFloat,&vainSFloat,NULL};
_S_twobool far S_twobool_348_1 = {&var360,NULL,&var145,&vainSBool,NULL,NULL};
_S_toao far S_toao_549_1 = {&var158,NULL,NULL,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var146,NULL};
_S_toao far S_toao_548_1 = {&var156,NULL,NULL,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var147,NULL};
_S_twobool far S_twobool_319_1 = {&var352,NULL,&var148,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_335_1 = {&var359,NULL,&var149,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_431_1 = {&var375,NULL,&var150,&vainSBool,NULL,NULL};
_S_ktoenc far S_ktoenc_432_1 = {&var152,NULL,&fRM_0_,&iRM_0_,&var151,&vainSBool,&vainSBool,&vainSBool,&vainSLong,NULL,NULL};
_S_to3val far S_to3val_427_1 = {&var281,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,NULL,&var152,&vainSFloat,&vainSFloat,NULL};
_S_twobool far S_twobool_430_1 = {&var377,NULL,&var153,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_429_1 = {&var372,NULL,&var154,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_428_1 = {&var373,NULL,&var155,&vainSBool,NULL,NULL};
_S_to3val far S_to3val_540_1 = {NULL,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,NULL,NULL,NULL,&var156,&var157,&var158,NULL};
_S_toao far S_toao_163_1 = {&var163,NULL,NULL,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&vainSInt,NULL};
_S_toao far S_toao_162_1 = {&var162,NULL,NULL,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var159,NULL};
_S_toao far S_toao_161_1 = {&var161,NULL,NULL,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var160,NULL};
_S_to3val far S_to3val_156_1 = {&var344,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,NULL,NULL,NULL,&var161,&var162,&var163,NULL};
_S_toao far S_toao_166_1 = {&var170,NULL,NULL,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&vainSInt,NULL};
_S_toao far S_toao_165_1 = {&var169,NULL,NULL,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var164,NULL};
_S_twobool far S_twobool_979_1 = {&var242,NULL,&var165,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_150_1 = {&var345,NULL,&var166,&vainSBool,NULL,NULL};
_S_toao far S_toao_164_1 = {&var168,NULL,NULL,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var167,NULL};
_S_to3val far S_to3val_158_1 = {&var395,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,NULL,NULL,NULL,&var168,&var169,&var170,NULL};
_S_twobool far S_twobool_149_1 = {&var396,NULL,&var171,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1102_1 = {&var232,NULL,&var172,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1093_1 = {&var232,NULL,&var173,&var174,NULL,NULL};
_S_period far S_period_1082_1 = {&var181,&var38,&iRM_2_,NULL,NULL,NULL,&var175,array_m1082_tst_1,array_m1082_trz_1,array_m1082_N1_1,array_m1082_N2_1,NULL,NULL};
_S_bol far S_bol_1087_1 = {NULL,&var175,&var176};
_S_bol far S_bol_1086_1 = {&var181,NULL,&var177};
_S_bol far S_bol_1085_1 = {NULL,&var175,&var178};
_S_bol far S_bol_1073_1 = {&var181,NULL,&var179};
_S_bol far S_bol_1077_1 = {&var181,NULL,&var180};
_S_ocham far S_ocham_1048_1 = {&var294,&var293,&var292,&var33,&var303,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_1_,&fRM_2_0,NULL,NULL,NULL,&vainSFloat,&var181,&var182,&vainSFloat,&vainSFloat,&vainSFloat,&var183,NULL};
_S_bol far S_bol_1067_1 = {&var181,NULL,&var184};
_S_twobool far S_twobool_1043_1 = {&var234,NULL,&var185,&vainSBool,NULL,NULL};
_S_twobool far S_twobool_1035_1 = {&var234,NULL,&var186,&var187,NULL,NULL};
_S_period far S_period_1024_1 = {&var194,&var46,&iRM_2_,NULL,NULL,NULL,&var188,array_m1024_tst_1,array_m1024_trz_1,array_m1024_N1_1,array_m1024_N2_1,NULL,NULL};
_S_bol far S_bol_1029_1 = {NULL,&var188,&var189};
_S_bol far S_bol_1028_1 = {&var194,NULL,&var190};
_S_bol far S_bol_1027_1 = {NULL,&var188,&var191};
_S_bol far S_bol_1016_1 = {&var194,NULL,&var192};
_S_bol far S_bol_1019_1 = {&var194,NULL,&var193};
_S_ocham far S_ocham_994_1 = {&var297,&var296,&var295,&var33,&var303,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_1_,&fRM_2_0,NULL,NULL,NULL,&vainSFloat,&var194,&var195,&vainSFloat,&vainSFloat,&vainSFloat,&var196,NULL};
_S_bol far S_bol_1002_1 = {&var194,NULL,&var197};
_S_twobool far S_twobool_915_1 = {&var236,NULL,&vainSBool,&var198,NULL,NULL};
_S_twobool far S_twobool_905_1 = {&var236,NULL,&var199,&var200,NULL,NULL};
_S_period far S_period_896_1 = {&var207,&var41,&iRM_2_,NULL,NULL,NULL,&var201,array_m896_tst_1,array_m896_trz_1,array_m896_N1_1,array_m896_N2_1,NULL,NULL};
_S_bol far S_bol_903_1 = {NULL,&var201,&var202};
_S_bol far S_bol_902_1 = {&var207,NULL,&var203};
_S_bol far S_bol_901_1 = {NULL,&var201,&var204};
_S_bol far S_bol_886_1 = {&var207,NULL,&var205};
_S_bol far S_bol_890_1 = {&var207,NULL,&var206};
_S_ocham far S_ocham_862_1 = {&var300,&var299,&var298,&var33,&var303,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_2_,&fRM_2_0,NULL,NULL,NULL,&vainSFloat,&var207,&var208,&vainSFloat,&vainSFloat,&vainSFloat,&var209,NULL};
_S_bol far S_bol_884_1 = {&var207,NULL,&var210};
_S_twobool far S_twobool_849_1 = {&var260,NULL,&var211,&var212,NULL,NULL};
_S_twobool far S_twobool_838_1 = {&var260,NULL,&var213,&vainSBool,NULL,NULL};
_S_period far S_period_841_1 = {&var220,&var47,&iRM_2_,NULL,NULL,NULL,&var214,array_m841_tst_1,array_m841_trz_1,array_m841_N1_1,array_m841_N2_1,NULL,NULL};
_S_bol far S_bol_846_1 = {NULL,&var214,&var215};
_S_bol far S_bol_845_1 = {&var220,NULL,&var216};
_S_bol far S_bol_844_1 = {NULL,&var214,&var217};
_S_bol far S_bol_829_1 = {&var220,NULL,&var218};
_S_bol far S_bol_833_1 = {&var220,NULL,&var219};
_S_ocham far S_ocham_804_1 = {&var304,&var302,&var301,&var33,&var303,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_2_,&fRM_2_0,NULL,NULL,NULL,&vainSFloat,&var220,&var221,&vainSFloat,&vainSFloat,&vainSFloat,&var222,NULL};
_S_bol far S_bol_823_1 = {&var220,NULL,&var223};
_S_orn far S_orn_1179_1 = {array_m1179_x_1,&iRM_2_,&var224};
_S_andn far S_andn_1176_1 = {array_m1176_x_1,&iRM_2_,&vainSBool};
_S_noto far S_noto_1178_1 = {&var224,&var225};
_S_noto far S_noto_513_1 = {NULL,&var226};
_S_lk far S_lk_517_1 = {NULL,&var226,&var227};
_S_noto far S_noto_511_1 = {NULL,&var228};
_S_lk far S_lk_516_1 = {NULL,&var228,&var229};
_S_ovb1 far S_ovb1_195_1 = {NULL,&iRM_500_,&var230,NULL};
_S_ovb1 far S_ovb1_25_1 = {NULL,&iRM_500_,&var231,NULL};
_S_andn far S_andn_1197_1 = {array_m1197_x_1,&iRM_2_,&var232};
_S_noto far S_noto_1200_1 = {&var34,&var233};
_S_andn far S_andn_1192_1 = {array_m1192_x_1,&iRM_2_,&var234};
_S_noto far S_noto_1195_1 = {&var35,&var235};
_S_andn far S_andn_1186_1 = {array_m1186_x_1,&iRM_2_,&var236};
_S_noto far S_noto_1189_1 = {&var36,&var237};
_S_orn far S_orn_632_1 = {array_m632_x_1,&iRM_2_,&var238};
_S_orn far S_orn_629_1 = {array_m629_x_1,&iRM_2_,&var239};
_S_react far S_react_198_1 = {&var346,&var240};
_S_noto far S_noto_474_1 = {NULL,&var241};
_S_asmot far S_asmot_476_1 = {&var241,NULL,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,NULL,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,NULL,NULL,&vainSFloat,&var242,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_asmot far S_asmot_490_1 = {&var22,&var23,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,NULL,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,NULL,NULL,&vainSFloat,&var243,&var244,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_asmot far S_asmot_478_1 = {&var24,&var25,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,NULL,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,NULL,NULL,&vainSFloat,&var245,&var246,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_noto far S_noto_615_1 = {NULL,&var247};
_S_asmot far S_asmot_621_1 = {&var247,NULL,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,NULL,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,NULL,NULL,&vainSFloat,&var248,&var249,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_noto far S_noto_613_1 = {NULL,&var250};
_S_asmot far S_asmot_618_1 = {&var250,NULL,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,NULL,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,NULL,NULL,&vainSFloat,&var251,&var252,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_noto far S_noto_602_1 = {NULL,&var253};
_S_asmot far S_asmot_604_1 = {&var253,NULL,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,NULL,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,NULL,NULL,&vainSFloat,&var254,&var255,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_noto far S_noto_601_1 = {NULL,&var256};
_S_asmot far S_asmot_603_1 = {&var256,NULL,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,NULL,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,NULL,NULL,&vainSFloat,&var257,&var258,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_orn far S_orn_639_1 = {array_m639_x_1,&iRM_3_,&var259};
_S_andn far S_andn_1181_1 = {array_m1181_x_1,&iRM_2_,&var260};
_S_noto far S_noto_1184_1 = {&var37,&var261};
_S_andn far S_andn_290_1 = {array_m290_x_1,&iRM_2_,&var262};
_S_andn far S_andn_255_1 = {array_m255_x_1,&iRM_3_,&var263};
_S_noto far S_noto_254_1 = {NULL,&var264};
_S_andn far S_andn_256_1 = {array_m256_x_1,&iRM_3_,&var265};
_S_noto far S_noto_214_1 = {NULL,&var266};
_S_noto far S_noto_213_1 = {NULL,&var267};
_S_andn far S_andn_216_1 = {array_m216_x_1,&iRM_4_,&var268};
_S_andn far S_andn_215_1 = {array_m215_x_1,&iRM_4_,&var269};
_S_andn far S_andn_121_1 = {array_m121_x_1,&iRM_2_,&var270};
_S_noto far S_noto_46_1 = {NULL,&var271};
_S_noto far S_noto_45_1 = {NULL,&var272};
_S_andn far S_andn_48_1 = {array_m48_x_1,&iRM_4_,&var273};
_S_andn far S_andn_47_1 = {array_m47_x_1,&iRM_4_,&var274};
_S_andn far S_andn_87_1 = {array_m87_x_1,&iRM_3_,&var275};
_S_noto far S_noto_86_1 = {NULL,&var276};
_S_andn far S_andn_88_1 = {array_m88_x_1,&iRM_3_,&var277};
_S_noto far S_noto_637_1 = {&var259,&var278};
_S_orn far S_orn_645_1 = {array_m645_x_1,&iRM_2_,&var279};
_S_fsubo far S_fsubo_371_1 = {NULL,&var332,&var280};
_S_fsubo far S_fsubo_115_1 = {NULL,&var371,&var281};
_S_fsubo far S_fsubo_283_1 = {NULL,&var363,&var282};
_S_fsubo far S_fsubo_242_1 = {NULL,&var379,&var283};
_S_fsubo far S_fsubo_74_1 = {NULL,&var386,&var284};
_S_fsubo far S_fsubo_8_1 = {&var286,NULL,&var285};
_S_inf far S_inf_7_1 = {&var332,array_m7_a_1,array_m7_b_1,&iRM_5_,&var286,&vainSInt};
_S_inf far S_inf_9_1 = {&var332,array_m9_a_1,array_m9_b_1,&iRM_7_,&var287,&vainSInt};
_S_mod1 far S_mod1_650_1 = {&var347,NULL,NULL,&var288,NULL};
_S_bol far S_bol_644_1 = {&var347,NULL,&var289};
_S_bol far S_bol_634_1 = {&var347,NULL,&var290};
_S_bol far S_bol_628_1 = {&var347,NULL,&var291};
_S_vchs far S_vchs_798_1 = {&var393,&var342,&var303,NULL,&var33,NULL,NULL,&bRM_5_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var292,NULL};
_S_vchs far S_vchs_790_1 = {&var393,&var342,&var303,NULL,&var33,NULL,NULL,&bRM_4_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var293,NULL};
_S_vchs far S_vchs_783_1 = {&var393,&var342,&var303,NULL,&var33,NULL,NULL,&bRM_1_,NULL,NULL,&fRM_2_0,NULL,&fRM_0_,NULL,&var294,NULL};
_S_vchs far S_vchs_775_1 = {&var393,&var342,&var303,NULL,&var33,NULL,NULL,&bRM_5_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var295,NULL};
_S_vchs far S_vchs_767_1 = {&var393,&var342,&var303,NULL,&var33,NULL,NULL,&bRM_4_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var296,NULL};
_S_vchs far S_vchs_760_1 = {&var393,&var342,&var303,NULL,&var33,NULL,NULL,&bRM_1_,NULL,NULL,&fRM_2_0,NULL,&fRM_0_,NULL,&var297,NULL};
_S_vchs far S_vchs_752_1 = {&var393,&var342,&var303,NULL,&var33,NULL,NULL,&bRM_5_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var298,NULL};
_S_vchs far S_vchs_744_1 = {&var393,&var342,&var303,NULL,&var33,NULL,NULL,&bRM_4_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var299,NULL};
_S_vchs far S_vchs_737_1 = {&var393,&var342,&var303,NULL,&var33,NULL,NULL,&bRM_2_,NULL,NULL,&fRM_2_0,NULL,&fRM_0_,NULL,&var300,NULL};
_S_vchs far S_vchs_729_1 = {&var393,&var342,&var303,NULL,&var33,NULL,NULL,&bRM_5_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var301,NULL};
_S_vchs far S_vchs_721_1 = {&var393,&var342,&var303,NULL,&var33,NULL,NULL,&bRM_4_,NULL,NULL,NULL,NULL,&fRM_0_,NULL,&var302,NULL};
_S_fsumo far S_fsumo_1172_1 = {NULL,NULL,&var303};
_S_vchs far S_vchs_714_1 = {&var393,&var342,&var303,NULL,&var33,NULL,NULL,&bRM_2_,NULL,NULL,&fRM_2_0,NULL,&fRM_0_,NULL,&var304,NULL};
_S_asmot far S_asmot_590_1 = {NULL,NULL,NULL,NULL,&fRM_1_,&fRM_0_,NULL,NULL,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,NULL,NULL,&vainSFloat,&var305,&var306,&vainSBool,&vainSBool,&vainSFloat,&var307,&var308,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_asmot far S_asmot_575_1 = {NULL,NULL,NULL,NULL,&fRM_1_,&fRM_0_,NULL,NULL,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,NULL,NULL,&vainSFloat,&var309,&var310,&vainSBool,&vainSBool,&vainSFloat,&var311,&var312,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_asmot far S_asmot_461_1 = {NULL,NULL,NULL,NULL,&fRM_1_,&fRM_0_,NULL,NULL,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,NULL,NULL,&vainSFloat,&var313,&var314,&vainSBool,&vainSBool,&vainSFloat,&var315,&var316,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_asmot far S_asmot_446_1 = {NULL,NULL,NULL,NULL,&fRM_1_,&fRM_0_,NULL,NULL,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,NULL,NULL,&vainSFloat,&var317,&var318,&vainSBool,&vainSBool,&vainSFloat,&var319,&var320,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_asmot far S_asmot_502_1 = {NULL,NULL,NULL,NULL,&fRM_1_0,NULL,NULL,NULL,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,NULL,NULL,&vainSFloat,&var321,&var322,&vainSBool,&vainSBool,&vainSFloat,&var323,&var324,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_asmot far S_asmot_397_1 = {NULL,NULL,NULL,NULL,&fRM_1_0,NULL,NULL,NULL,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,NULL,NULL,&vainSFloat,&var325,&var326,&vainSBool,&vainSBool,&vainSFloat,&var327,&var328,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_asmot far S_asmot_381_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var329,&var330,&var331,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_asmot far S_asmot_364_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var332,&var333,&var334,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_asmot far S_asmot_1167_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&vainSFloat,&var335,&var336,&var337,&var338,&vainSFloat,&var339,&var340,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_azbars far S_azbars_180_1 = {&var378,&var362,&var348,&var392,NULL,NULL,&var251,NULL,&var230,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var285,&var287,NULL,NULL,NULL,NULL,NULL,&var341,&var342,&var343,&var344,&var345,&var346,&var347,NULL,NULL,NULL,NULL,NULL,NULL,NULL,array_m180_C0_1,NULL,NULL,NULL};
_S_orrsim far S_orrsim_301_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var262,NULL,&lRM_1_,NULL,NULL,NULL,NULL,&lRM_0_,array_m301_Vr_1,NULL,&var227,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var348,&var349,&var350,&var351,&var352,&vainSFloat,&vainSFloat,&var353,&var354,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_orrsim far S_orrsim_130_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var270,NULL,&lRM_1_,NULL,NULL,NULL,NULL,&lRM_0_,array_m130_Vr_1,NULL,&var229,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var355,&var356,&var357,&var358,&var359,&vainSFloat,&vainSFloat,&var360,&var361,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_orrsim far S_orrsim_265_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var263,NULL,&var265,NULL,NULL,NULL,NULL,&lRM_1_,array_m265_Vr_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var362,&var363,&vainSBool,&var364,&var365,&vainSFloat,&vainSFloat,&var366,&var367,&var368,&var369,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_orrsim far S_orrsim_97_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var275,NULL,&var277,NULL,NULL,NULL,NULL,&lRM_1_,array_m97_Vr_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var370,&var371,&vainSBool,&var372,&var373,&vainSFloat,&vainSFloat,&var374,&var375,&var376,&var377,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_orrsim far S_orrsim_227_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var269,&lRM_1_,&var268,NULL,NULL,NULL,NULL,&lRM_1_,array_m227_Vr_1,NULL,&fRM_0_,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var378,&var379,&vainSBool,&var380,&var381,&vainSFloat,&vainSFloat,&var382,&vainSBool,&var383,&var384,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_orrsim far S_orrsim_59_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var274,&lRM_1_,&var273,NULL,NULL,NULL,NULL,&lRM_1_,array_m59_Vr_1,NULL,&fRM_0_,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var385,&var386,&var387,&var388,&var389,&vainSFloat,&vainSFloat,&vainSBool,&vainSBool,&var390,&var391,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_azbars far S_azbars_14_1 = {&var385,&var370,&var355,&var341,NULL,NULL,&var248,NULL,&var231,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var285,&var287,NULL,NULL,NULL,NULL,NULL,&var392,&var393,&var394,&var395,&var396,&var397,&vainSFloat,NULL,NULL,NULL,NULL,NULL,NULL,NULL,array_m14_C0_1,NULL,NULL,NULL};


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
  noto((&S_noto_86_1));
  noto((&S_noto_254_1));
  noto((&S_noto_601_1));
  noto((&S_noto_602_1));
  ovb1((&S_ovb1_25_1));
  ovb1((&S_ovb1_195_1));
  noto((&S_noto_513_1));
  bol((&S_bol_1207_1));
  bol((&S_bol_1208_1));
  bol((&S_bol_1211_1));
  bol((&S_bol_1216_1));
  bol((&S_bol_1214_1));
  zpfs((&S_zpfs_630_1));
  zpfs((&S_zpfs_642_1));
  noto((&S_noto_479_1));
  noto((&S_noto_477_1));
  noto((&S_noto_489_1));
  noto((&S_noto_488_1));
  asmot((&S_asmot_1167_1));
  asmot((&S_asmot_364_1));
  asmot((&S_asmot_381_1));
  asmot((&S_asmot_397_1));
  asmot((&S_asmot_502_1));
  asmot((&S_asmot_446_1));
  asmot((&S_asmot_461_1));
  asmot((&S_asmot_575_1));
  asmot((&S_asmot_590_1));
  fsumo((&S_fsumo_1172_1));
  inf((&S_inf_9_1));
  inf((&S_inf_7_1));
  fsubo((&S_fsubo_8_1));
  fsubo((&S_fsubo_371_1));
  noto((&S_noto_45_1));
  noto((&S_noto_46_1));
  noto((&S_noto_213_1));
  noto((&S_noto_214_1));
  orn((&S_orn_639_1));
  asmot((&S_asmot_603_1));
  asmot((&S_asmot_604_1));
  noto((&S_noto_613_1));
  noto((&S_noto_615_1));
  noto((&S_noto_474_1));
  noto((&S_noto_511_1));
  lk((&S_lk_517_1));
  orn((&S_orn_1179_1));
  to3val((&S_to3val_540_1));
  toao((&S_toao_548_1));
  toao((&S_toao_549_1));
  to3val((&S_to3val_518_1));
  toao((&S_toao_525_1));
  twobool((&S_twobool_562_1));
  twobool((&S_twobool_664_1));
  twobool((&S_twobool_684_1));
  twobool((&S_twobool_665_1));
  twobool((&S_twobool_685_1));
  twobool((&S_twobool_701_1));
  to3val((&S_to3val_1129_1));
  ktoenc((&S_ktoenc_1137_1));
  to3val((&S_to3val_1127_1));
  ktoenc((&S_ktoenc_1135_1));
  twobool((&S_twobool_560_1));
  twobool((&S_twobool_561_1));
  twobool((&S_twobool_703_1));
  twobool((&S_twobool_702_1));
  twobool((&S_twobool_705_1));
  twobool((&S_twobool_704_1));
  twobool((&S_twobool_980_1));
  twobool((&S_twobool_1153_1));
  twobool((&S_twobool_1155_1));
  twobool((&S_twobool_1154_1));
  to3val((&S_to3val_541_1));
  toao((&S_toao_550_1));
  toao((&S_toao_544_1));
  twobool((&S_twobool_543_1));
  twobool((&S_twobool_924_1));
  twobool((&S_twobool_939_1));
  twobool((&S_twobool_956_1));
  twobool((&S_twobool_978_1));
  twobool((&S_twobool_1116_1));
  twobool((&S_twobool_925_1));
  twobool((&S_twobool_926_1));
  twobool((&S_twobool_927_1));
  twobool((&S_twobool_928_1));
  twobool((&S_twobool_976_1));
  twobool((&S_twobool_1112_1));
  twobool((&S_twobool_1113_1));
  twobool((&S_twobool_1115_1));
  twobool((&S_twobool_1114_1));
  twobool((&S_twobool_1140_1));
  twobool((&S_twobool_1138_1));
  twobool((&S_twobool_1141_1));
  twobool((&S_twobool_1139_1));
  twobool((&S_twobool_960_1));
  twobool((&S_twobool_961_1));
  twobool((&S_twobool_962_1));
  twobool((&S_twobool_981_1));
  twobool((&S_twobool_56_1));
  twobool((&S_twobool_41_1));
  twobool((&S_twobool_224_1));
  twobool((&S_twobool_206_1));
  zpfs((&S_zpfs_614_1));
  zpfs((&S_zpfs_616_1));
  or2((&S_or2_1183_1));
  or2((&S_or2_1188_1));
  or2((&S_or2_1194_1));
  or2((&S_or2_1199_1));
  ampl((&S_ampl_372_1));
  rs((&S_rs_473_1));
  rs((&S_rs_472_1));
  rs((&S_rs_487_1));
  rs((&S_rs_486_1));
  twobool((&S_twobool_545_1));
  twobool((&S_twobool_527_1));
  twobool((&S_twobool_666_1));
  twobool((&S_twobool_667_1));
  twobool((&S_twobool_688_1));
  twobool((&S_twobool_689_1));
  twobool((&S_twobool_668_1));
  twobool((&S_twobool_669_1));
  twobool((&S_twobool_690_1));
  twobool((&S_twobool_691_1));
  twobool((&S_twobool_940_1));
  twobool((&S_twobool_941_1));
  twobool((&S_twobool_942_1));
  twobool((&S_twobool_943_1));
  twobool((&S_twobool_1117_1));
  twobool((&S_twobool_1118_1));
  noto((&S_noto_637_1));
  andn((&S_andn_88_1));
  andn((&S_andn_87_1));
  andn((&S_andn_47_1));
  andn((&S_andn_48_1));
  andn((&S_andn_121_1));
  andn((&S_andn_215_1));
  andn((&S_andn_216_1));
  andn((&S_andn_256_1));
  andn((&S_andn_255_1));
  andn((&S_andn_290_1));
  noto((&S_noto_1184_1));
  andn((&S_andn_1181_1));
  asmot((&S_asmot_618_1));
  asmot((&S_asmot_621_1));
  asmot((&S_asmot_478_1));
  asmot((&S_asmot_490_1));
  asmot((&S_asmot_476_1));
  noto((&S_noto_1189_1));
  andn((&S_andn_1186_1));
  noto((&S_noto_1195_1));
  andn((&S_andn_1192_1));
  noto((&S_noto_1200_1));
  andn((&S_andn_1197_1));
  lk((&S_lk_516_1));
  noto((&S_noto_1178_1));
  andn((&S_andn_1176_1));
  twobool((&S_twobool_838_1));
  twobool((&S_twobool_849_1));
  twobool((&S_twobool_905_1));
  twobool((&S_twobool_915_1));
  twobool((&S_twobool_1035_1));
  twobool((&S_twobool_1043_1));
  twobool((&S_twobool_1093_1));
  twobool((&S_twobool_1102_1));
  twobool((&S_twobool_979_1));
  to3val((&S_to3val_515_1));
  toao((&S_toao_521_1));
  twobool((&S_twobool_957_1));
  twobool((&S_twobool_959_1));
  twobool((&S_twobool_958_1));
  twobool((&S_twobool_977_1));
  orrsim((&S_orrsim_59_1));
  orrsim((&S_orrsim_227_1));
  orrsim((&S_orrsim_97_1));
  orrsim((&S_orrsim_265_1));
  orrsim((&S_orrsim_130_1));
  orrsim((&S_orrsim_301_1));
  azbars((&S_azbars_180_1));
  bol((&S_bol_628_1));
  bol((&S_bol_634_1));
  bol((&S_bol_644_1));
  mod1((&S_mod1_650_1));
  fsubo((&S_fsubo_74_1));
  fsubo((&S_fsubo_242_1));
  fsubo((&S_fsubo_283_1));
  fsubo((&S_fsubo_115_1));
  orn((&S_orn_645_1));
  react((&S_react_198_1));
  orn((&S_orn_629_1));
  orn((&S_orn_632_1));
  twobool((&S_twobool_150_1));
  to3val((&S_to3val_156_1));
  toao((&S_toao_161_1));
  toao((&S_toao_162_1));
  toao((&S_toao_163_1));
  twobool((&S_twobool_428_1));
  twobool((&S_twobool_429_1));
  twobool((&S_twobool_430_1));
  to3val((&S_to3val_427_1));
  ktoenc((&S_ktoenc_432_1));
  twobool((&S_twobool_431_1));
  twobool((&S_twobool_335_1));
  twobool((&S_twobool_319_1));
  twobool((&S_twobool_348_1));
  to3val((&S_to3val_323_1));
  ktoenc((&S_ktoenc_327_1));
  twobool((&S_twobool_347_1));
  twobool((&S_twobool_349_1));
  to3val((&S_to3val_333_1));
  ktoenc((&S_ktoenc_334_1));
  twobool((&S_twobool_350_1));
  twobool((&S_twobool_320_1));
  twobool((&S_twobool_321_1));
  twobool((&S_twobool_336_1));
  twobool((&S_twobool_337_1));
  ampl((&S_ampl_655_1));
  twobool((&S_twobool_411_1));
  twobool((&S_twobool_412_1));
  twobool((&S_twobool_410_1));
  to3val((&S_to3val_413_1));
  ktoenc((&S_ktoenc_419_1));
  twobool((&S_twobool_1223_1));
  twobool((&S_twobool_1224_1));
  twobool((&S_twobool_1227_1));
  to3val((&S_to3val_1221_1));
  ktoenc((&S_ktoenc_1226_1));
  to3val((&S_to3val_1235_1));
  ktoenc((&S_ktoenc_1240_1));
  twobool((&S_twobool_1237_1));
  twobool((&S_twobool_1238_1));
  twobool((&S_twobool_1241_1));
  twobool((&S_twobool_409_1));
  azbars((&S_azbars_14_1));
  vchs((&S_vchs_714_1));
  vchs((&S_vchs_721_1));
  vchs((&S_vchs_729_1));
  vchs((&S_vchs_737_1));
  vchs((&S_vchs_744_1));
  vchs((&S_vchs_752_1));
  vchs((&S_vchs_760_1));
  vchs((&S_vchs_767_1));
  vchs((&S_vchs_775_1));
  vchs((&S_vchs_783_1));
  vchs((&S_vchs_790_1));
  vchs((&S_vchs_798_1));
  ocham((&S_ocham_804_1));
  bol((&S_bol_833_1));
  bol((&S_bol_829_1));
  bol((&S_bol_845_1));
  ocham((&S_ocham_862_1));
  bol((&S_bol_890_1));
  bol((&S_bol_886_1));
  bol((&S_bol_902_1));
  ocham((&S_ocham_994_1));
  bol((&S_bol_1019_1));
  bol((&S_bol_1016_1));
  bol((&S_bol_1028_1));
  ocham((&S_ocham_1048_1));
  bol((&S_bol_1077_1));
  bol((&S_bol_1073_1));
  bol((&S_bol_1086_1));
  twobool((&S_twobool_149_1));
  to3val((&S_to3val_158_1));
  toao((&S_toao_164_1));
  toao((&S_toao_165_1));
  toao((&S_toao_166_1));
  to3val((&S_to3val_656_1));
  and5((&S_and5_854_1));
  and5((&S_and5_1041_1));
  and5((&S_and5_913_1));
  and5((&S_and5_1098_1));
  andn((&S_andn_355_1));
  bol((&S_bol_823_1));
  period((&S_period_841_1));
  bol((&S_bol_884_1));
  period((&S_period_896_1));
  bol((&S_bol_1002_1));
  period((&S_period_1024_1));
  bol((&S_bol_1067_1));
  period((&S_period_1082_1));
  bol((&S_bol_844_1));
  bol((&S_bol_846_1));
  bol((&S_bol_901_1));
  bol((&S_bol_903_1));
  bol((&S_bol_1027_1));
  bol((&S_bol_1029_1));
  bol((&S_bol_1085_1));
  bol((&S_bol_1087_1));
  and2((&S_and2_851_1));
  and2((&S_and2_852_1));
  and2((&S_and2_1033_1));
  and2((&S_and2_1034_1));
  and2((&S_and2_906_1));
  and2((&S_and2_907_1));
  and2((&S_and2_1091_1));
  and2((&S_and2_1092_1));
  signal_R4VS12LDU.b = var2.b;
  signal_R4VS12LDU.error = var2.error;
  signal_R4VS22LDU.b = var1.b;
  signal_R4VS22LDU.error = var1.error;
  signal_R1VS12LDU.b = var6.b;
  signal_R1VS12LDU.error = var6.error;
  signal_R2VS12LDU.b = var4.b;
  signal_R2VS12LDU.error = var4.error;
  signal_R2VS22LDU.b = var3.b;
  signal_R2VS22LDU.error = var3.error;
  signal_R1VS22LDU.b = var5.b;
  signal_R1VS22LDU.error = var5.error;
  signal_B5VS12LDU.b = var8.b;
  signal_B5VS12LDU.error = var8.error;
  signal_B5VS22LDU.b = var7.b;
  signal_B5VS22LDU.error = var7.error;
  signal_A5VS12LDU.b = var10.b;
  signal_A5VS12LDU.error = var10.error;
  signal_A5VS22LDU.b = var9.b;
  signal_A5VS22LDU.error = var9.error;
  signal_B6VS12LDU.b = var12.b;
  signal_B6VS12LDU.error = var12.error;
  signal_B6VS22LDU.b = var11.b;
  signal_B6VS22LDU.error = var11.error;
  signal_A6VS12LDU.b = var14.b;
  signal_A6VS12LDU.error = var14.error;
  signal_A6VS22LDU.b = var13.b;
  signal_A6VS22LDU.error = var13.error;
  signal_B8IS21LDU.b = var74.b;
  signal_B8IS21LDU.error = var74.error;
  signal_B8IS11LDU.b = var72.b;
  signal_B8IS11LDU.error = var72.error;
  signal_A1VP81LZZ.b = var15.b;
  signal_A1VP81LZZ.error = var15.error;
  signal_B1VP81LZZ.b = var16.b;
  signal_B1VP81LZZ.error = var16.error;
  signal_B2IS33LDU.b = var17.b;
  signal_B2IS33LDU.error = var17.error;
  fplet(&signal_A0VN01RIM.f,&var397.f);
  signal_A0VN01RIM.error = var397.error;
  signal_B2IS32LIM.b = var366.b;
  signal_B2IS32LIM.error = var366.error;
  signal_B2IS11LIM.b = var368.b;
  signal_B2IS11LIM.error = var368.error;
  signal_A2IS32LIM.b = var374.b;
  signal_A2IS32LIM.error = var374.error;
  signal_A2IS11LIM.b = var376.b;
  signal_A2IS11LIM.error = var376.error;
  signal_B1IS32LIM.b = var382.b;
  signal_B1IS32LIM.error = var382.error;
  signal_B1IS11LIM.b = var383.b;
  signal_B1IS11LIM.error = var383.error;
  signal_A1IS32LIM.b = var387.b;
  signal_A1IS32LIM.error = var387.error;
  signal_A1IS11LIM.b = var390.b;
  signal_A1IS11LIM.error = var390.error;
  signal_R0IS02LDU.b = lEM_R0IE02LRP.b;
  signal_R0IS02LDU.error = lEM_R0IE02LRP.error;
  signal_B4IS10LDU.b = var51.b;
  signal_B4IS10LDU.error = var51.error;
  signal_A4IS10LDU.b = var50.b;
  signal_A4IS10LDU.error = var50.error;
  signal_B1IE04LDU.b = var52.b;
  signal_B1IE04LDU.error = var52.error;
  signal_B1IE03LDU.b = var53.b;
  signal_B1IE03LDU.error = var53.error;
  signal_A1IE04LDU.b = var54.b;
  signal_A1IE04LDU.error = var54.error;
  signal_A1IE03LDU.b = var55.b;
  signal_A1IE03LDU.error = var55.error;
  signal_B1IS12LDU.b = var56.b;
  signal_B1IS12LDU.error = var56.error;
  signal_B1IS11LDU.b = var57.b;
  signal_B1IS11LDU.error = var57.error;
  signal_B1IS21LDU.b = var58.b;
  signal_B1IS21LDU.error = var58.error;
  signal_B1IC01UDU.l = var59.l;
  signal_B1IC01UDU.error = var59.error;
  signal_A1IC01UDU.l = var61.l;
  signal_A1IC01UDU.error = var61.error;
  signal_A1IS12LDU.b = var63.b;
  signal_A1IS12LDU.error = var63.error;
  signal_A1IS11LDU.b = var64.b;
  signal_A1IS11LDU.error = var64.error;
  signal_A1IS21LDU.b = var65.b;
  signal_A1IS21LDU.error = var65.error;
  signal_B6IS21LDU.b = var66.b;
  signal_B6IS21LDU.error = var66.error;
  signal_B6IS11LDU.b = var67.b;
  signal_B6IS11LDU.error = var67.error;
  signal_A6IS21LDU.b = var68.b;
  signal_A6IS21LDU.error = var68.error;
  signal_A6IS11LDU.b = var69.b;
  signal_A6IS11LDU.error = var69.error;
  signal_A8IS12LDU.b = var70.b;
  signal_A8IS12LDU.error = var70.error;
  signal_A8IS22LDU.b = var71.b;
  signal_A8IS22LDU.error = var71.error;
  signal_B8IS12LDU.b = var73.b;
  signal_B8IS12LDU.error = var73.error;
  signal_B8IS22LDU.b = var75.b;
  signal_B8IS22LDU.error = var75.error;
  signal_R4IS12LDU.b = var76.b;
  signal_R4IS12LDU.error = var76.error;
  signal_R4IS22LDU.b = var77.b;
  signal_R4IS22LDU.error = var77.error;
  signal_R4IS21LDU.b = var78.b;
  signal_R4IS21LDU.error = var78.error;
  signal_R4IS11LDU.b = var79.b;
  signal_R4IS11LDU.error = var79.error;
  signal_B4VP82LDU.b = var81.b;
  signal_B4VP82LDU.error = var81.error;
  signal_A4VP82LDU.b = var80.b;
  signal_A4VP82LDU.error = var80.error;
  signal_R2IS21LDU.b = var82.b;
  signal_R2IS21LDU.error = var82.error;
  signal_R2IS11LDU.b = var83.b;
  signal_R2IS11LDU.error = var83.error;
  signal_R1IS21LDU.b = var84.b;
  signal_R1IS21LDU.error = var84.error;
  signal_R1IS11LDU.b = var85.b;
  signal_R1IS11LDU.error = var85.error;
  signal_B4IS21LDU.b = var86.b;
  signal_B4IS21LDU.error = var86.error;
  signal_B4IS11LDU.b = var87.b;
  signal_B4IS11LDU.error = var87.error;
  signal_R8IS11LDU.b = var88.b;
  signal_R8IS11LDU.error = var88.error;
  signal_A4IS21LDU.b = var89.b;
  signal_A4IS21LDU.error = var89.error;
  signal_A4IS11LDU.b = var90.b;
  signal_A4IS11LDU.error = var90.error;
  signal_R5IS21LDU.b = var91.b;
  signal_R5IS21LDU.error = var91.error;
  signal_R5IS11LDU.b = var92.b;
  signal_R5IS11LDU.error = var92.error;
  signal_R3IS21LDU.b = var93.b;
  signal_R3IS21LDU.error = var93.error;
  signal_R3IS11LDU.b = var94.b;
  signal_R3IS11LDU.error = var94.error;
  signal_B2VP82LDU.b = var95.b;
  signal_B2VP82LDU.error = var95.error;
  signal_B2IP01IZ2.i = var97.i;
  signal_B2IP01IZ2.error = var97.error;
  signal_B2IP01IZ1.i = var98.i;
  signal_B2IP01IZ1.error = var98.error;
  signal_B2IC01UDU.l = var101.l;
  signal_B2IC01UDU.error = var101.error;
  signal_B2IS12LDU.b = var103.b;
  signal_B2IS12LDU.error = var103.error;
  signal_B2IS11LDU.b = var104.b;
  signal_B2IS11LDU.error = var104.error;
  signal_B2IS21LDU.b = var105.b;
  signal_B2IS21LDU.error = var105.error;
  signal_B9IS21LDU.b = var106.b;
  signal_B9IS21LDU.error = var106.error;
  signal_B9IS11LDU.b = var107.b;
  signal_B9IS11LDU.error = var107.error;
  signal_A9IS21LDU.b = var108.b;
  signal_A9IS21LDU.error = var108.error;
  signal_A9IS11LDU.b = var109.b;
  signal_A9IS11LDU.error = var109.error;
  signal_B5IS21LDU.b = var110.b;
  signal_B5IS21LDU.error = var110.error;
  signal_B5IS11LDU.b = var111.b;
  signal_B5IS11LDU.error = var111.error;
  signal_A5IS21LDU.b = var112.b;
  signal_A5IS21LDU.error = var112.error;
  signal_A5IS11LDU.b = var113.b;
  signal_A5IS11LDU.error = var113.error;
  signal_B0VP81LZZ.b = var115.b;
  signal_B0VP81LZZ.error = var115.error;
  signal_A0VP81LZZ.b = var116.b;
  signal_A0VP81LZZ.error = var116.error;
  signal_B8IC01UDU.l = var117.l;
  signal_B8IC01UDU.error = var117.error;
  signal_A8IC01UDU.l = var119.l;
  signal_A8IC01UDU.error = var119.error;
  signal_R6IS68LZZ.b = var121.b;
  signal_R6IS68LZZ.error = var121.error;
  signal_R6IS67LZZ.b = var122.b;
  signal_R6IS67LZZ.error = var122.error;
  signal_R6IS66LZZ.b = var123.b;
  signal_R6IS66LZZ.error = var123.error;
  signal_R6IS65LDU.b = var125.b;
  signal_R6IS65LDU.error = var125.error;
  signal_R6IS64LDU.b = var124.b;
  signal_R6IS64LDU.error = var124.error;
  signal_R6IS63LDU.b = var127.b;
  signal_R6IS63LDU.error = var127.error;
  signal_R6IS62LDU.b = var126.b;
  signal_R6IS62LDU.error = var126.error;
  signal_B3IS22LDU.b = var128.b;
  signal_B3IS22LDU.error = var128.error;
  signal_A3IS22LDU.b = var129.b;
  signal_A3IS22LDU.error = var129.error;
  signal_B3IS11LDU.b = var130.b;
  signal_B3IS11LDU.error = var130.error;
  signal_A3IS11LDU.b = var131.b;
  signal_A3IS11LDU.error = var131.error;
  signal_A3IP02IDU.i = var132.i;
  signal_A3IP02IDU.error = var132.error;
  signal_B3VP81LDU.b = var135.b;
  signal_B3VP81LDU.error = var135.error;
  signal_A3VP81LDU.b = var134.b;
  signal_A3VP81LDU.error = var134.error;
  signal_B3IS33LDU.b = var138.b;
  signal_B3IS33LDU.error = var138.error;
  signal_B3IC01UDU.l = var139.l;
  signal_B3IC01UDU.error = var139.error;
  signal_B3IS31LDU.b = var141.b;
  signal_B3IS31LDU.error = var141.error;
  signal_B3IP02IDU.i = var136.i;
  signal_B3IP02IDU.error = var136.error;
  signal_A3IS33LDU.b = var142.b;
  signal_A3IS33LDU.error = var142.error;
  signal_A3IC01UDU.l = var143.l;
  signal_A3IC01UDU.error = var143.error;
  signal_A3IS31LDU.b = var145.b;
  signal_A3IS31LDU.error = var145.error;
  signal_A2VP82LDU.b = var96.b;
  signal_A2VP82LDU.error = var96.error;
  signal_A2IP01IZ2.i = var146.i;
  signal_A2IP01IZ2.error = var146.error;
  signal_A2IP01IZ1.i = var147.i;
  signal_A2IP01IZ1.error = var147.error;
  signal_B3IS21LDU.b = var148.b;
  signal_B3IS21LDU.error = var148.error;
  signal_A3IS21LDU.b = var149.b;
  signal_A3IS21LDU.error = var149.error;
  signal_A2IS33LDU.b = var150.b;
  signal_A2IS33LDU.error = var150.error;
  signal_A2IC01UDU.l = var151.l;
  signal_A2IC01UDU.error = var151.error;
  signal_A2IS12LDU.b = var153.b;
  signal_A2IS12LDU.error = var153.error;
  signal_A2IS11LDU.b = var154.b;
  signal_A2IS11LDU.error = var154.error;
  signal_A2IS21LDU.b = var155.b;
  signal_A2IS21LDU.error = var155.error;
  signal_B0IT02IZ2.i = var159.i;
  signal_B0IT02IZ2.error = var159.error;
  signal_B0IT01IZ1.i = var160.i;
  signal_B0IT01IZ1.error = var160.error;
  signal_A0IT02IZ2.i = var164.i;
  signal_A0IT02IZ2.error = var164.error;
  signal_A0IT01IZ1.i = var167.i;
  signal_A0IT01IZ1.error = var167.error;
  signal_R6IS21LDU.b = var165.b;
  signal_R6IS21LDU.error = var165.error;
  signal_B7AS31LDU.b = var166.b;
  signal_B7AS31LDU.error = var166.error;
  signal_A7AS31LDU.b = var171.b;
  signal_A7AS31LDU.error = var171.error;
  signal_R0IE11LS4.b = var172.b;
  signal_R0IE11LS4.error = var172.error;
  signal_R0IE13LS4.b = var174.b;
  signal_R0IE13LS4.error = var174.error;
  signal_R0IE12LS4.b = var173.b;
  signal_R0IE12LS4.error = var173.error;
  signal_A1EE01LS4.b = var38.b;
  signal_A1EE01LS4.error = var38.error;
  signal_R0VN78LZ2.b = var40.b;
  signal_R0VN78LZ2.error = var40.error;
  signal_A0EE01LS4.b = var38.b;
  signal_A0EE01LS4.error = var38.error;
  signal_R0VN78LZ1.b = var40.b;
  signal_R0VN78LZ1.error = var40.error;
  signal_R0VN65LS4.b = var39.b;
  signal_R0VN65LS4.error = var39.error;
  fplet(&signal_R0VN01RS4.f,&var175.f);
  signal_R0VN01RS4.error = var175.error;
  signal_R0VN74LZ2.b = var179.b;
  signal_R0VN74LZ2.error = var179.error;
  signal_A0VN71LS4.b = var184.b;
  signal_A0VN71LS4.error = var184.error;
  signal_R0VN15RS4.i = var183.i;
  signal_R0VN15RS4.error = var183.error;
  signal_A1VN71LS4.b = var184.b;
  signal_A1VN71LS4.error = var184.error;
  signal_R0VN74LZ1.b = var179.b;
  signal_R0VN74LZ1.error = var179.error;
  signal_R0VN61LS4.b = var180.b;
  signal_R0VN61LS4.error = var180.error;
  fplet(&signal_R0VN02RS4.f,&var181.f);
  signal_R0VN02RS4.error = var181.error;
  signal_R0IE11LS3.b = var185.b;
  signal_R0IE11LS3.error = var185.error;
  signal_R0IE13LS3.b = var187.b;
  signal_R0IE13LS3.error = var187.error;
  signal_R0IE12LS3.b = var186.b;
  signal_R0IE12LS3.error = var186.error;
  signal_A1EE01LS3.b = var46.b;
  signal_A1EE01LS3.error = var46.error;
  signal_R0VN77LZ2.b = var45.b;
  signal_R0VN77LZ2.error = var45.error;
  signal_A0EE01LS3.b = var46.b;
  signal_A0EE01LS3.error = var46.error;
  signal_R0VN77LZ1.b = var45.b;
  signal_R0VN77LZ1.error = var45.error;
  signal_R0VN65LS3.b = var44.b;
  signal_R0VN65LS3.error = var44.error;
  fplet(&signal_R0VN01RS3.f,&var188.f);
  signal_R0VN01RS3.error = var188.error;
  signal_R0VN73LZ2.b = var192.b;
  signal_R0VN73LZ2.error = var192.error;
  signal_A0VN71LS3.b = var197.b;
  signal_A0VN71LS3.error = var197.error;
  signal_R0VN15RS3.i = var196.i;
  signal_R0VN15RS3.error = var196.error;
  signal_A1VN71LS3.b = var197.b;
  signal_A1VN71LS3.error = var197.error;
  signal_R0VN73LZ1.b = var192.b;
  signal_R0VN73LZ1.error = var192.error;
  signal_R0VN61LS3.b = var193.b;
  signal_R0VN61LS3.error = var193.error;
  fplet(&signal_R0VN02RS3.f,&var194.f);
  signal_R0VN02RS3.error = var194.error;
  signal_R0IE11LS2.b = var198.b;
  signal_R0IE11LS2.error = var198.error;
  signal_R0IE13LS2.b = var200.b;
  signal_R0IE13LS2.error = var200.error;
  signal_R0IE12LS2.b = var199.b;
  signal_R0IE12LS2.error = var199.error;
  signal_A1EE01LS2.b = var41.b;
  signal_A1EE01LS2.error = var41.error;
  signal_R0VN76LZ2.b = var43.b;
  signal_R0VN76LZ2.error = var43.error;
  signal_A0EE01LS2.b = var41.b;
  signal_A0EE01LS2.error = var41.error;
  signal_R0VN76LZ1.b = var43.b;
  signal_R0VN76LZ1.error = var43.error;
  signal_R0VN65LS2.b = var42.b;
  signal_R0VN65LS2.error = var42.error;
  fplet(&signal_R0VN01RS2.f,&var201.f);
  signal_R0VN01RS2.error = var201.error;
  signal_A0VN71LS2.b = var210.b;
  signal_A0VN71LS2.error = var210.error;
  signal_R0VN72LZ2.b = var205.b;
  signal_R0VN72LZ2.error = var205.error;
  signal_R0VN15RS2.i = var209.i;
  signal_R0VN15RS2.error = var209.error;
  signal_A1VN71LS2.b = var210.b;
  signal_A1VN71LS2.error = var210.error;
  signal_R0VN72LZ1.b = var205.b;
  signal_R0VN72LZ1.error = var205.error;
  signal_R0VN61LS2.b = var206.b;
  signal_R0VN61LS2.error = var206.error;
  fplet(&signal_R0VN02RS2.f,&var207.f);
  signal_R0VN02RS2.error = var207.error;
  signal_R0IE13LS1.b = var211.b;
  signal_R0IE13LS1.error = var211.error;
  signal_R0IE12LS1.b = var212.b;
  signal_R0IE12LS1.error = var212.error;
  signal_R0IE11LS1.b = var213.b;
  signal_R0IE11LS1.error = var213.error;
  signal_A1EE01LS1.b = var47.b;
  signal_A1EE01LS1.error = var47.error;
  signal_R0VN75LZ2.b = var49.b;
  signal_R0VN75LZ2.error = var49.error;
  signal_A0EE01LS1.b = var47.b;
  signal_A0EE01LS1.error = var47.error;
  signal_R0VN75LZ1.b = var49.b;
  signal_R0VN75LZ1.error = var49.error;
  signal_R0VN65LS1.b = var48.b;
  signal_R0VN65LS1.error = var48.error;
  fplet(&signal_R0VN01RS1.f,&var214.f);
  signal_R0VN01RS1.error = var214.error;
  signal_A1VN71LS1.b = var223.b;
  signal_A1VN71LS1.error = var223.error;
  signal_R0VN71LZ2.b = var218.b;
  signal_R0VN71LZ2.error = var218.error;
  signal_R0VN15RS1.i = var222.i;
  signal_R0VN15RS1.error = var222.error;
  signal_A0VN71LS1.b = var223.b;
  signal_A0VN71LS1.error = var223.error;
  signal_R0VN71LZ1.b = var218.b;
  signal_R0VN71LZ1.error = var218.error;
  signal_R0VN61LS1.b = var219.b;
  signal_R0VN61LS1.error = var219.error;
  fplet(&signal_R0VN02RS1.f,&var220.f);
  signal_R0VN02RS1.error = var220.error;
  signal_B3IS35LDU.b = var226.b;
  signal_B3IS35LDU.error = var226.error;
  signal_A3IS35LDU.b = var228.b;
  signal_A3IS35LDU.error = var228.error;
  signal_R7II73LZ2.b = var279.b;
  signal_R7II73LZ2.error = var279.error;
  signal_R7II71LZ2.b = var239.b;
  signal_R7II71LZ2.error = var239.error;
  signal_R7II72LZ2.b = var238.b;
  signal_R7II72LZ2.error = var238.error;
  signal_R7II72LZ1.b = var238.b;
  signal_R7II72LZ1.error = var238.error;
  signal_R7II71LZ1.b = var239.b;
  signal_R7II71LZ1.error = var239.error;
  signal_R7II73LZ1.b = var279.b;
  signal_R7II73LZ1.error = var279.error;
  fplet(&signal_R0SR01RIM.f,&var240.f);
  signal_R0SR01RIM.error = var240.error;
  fplet(&signal_R0ST01RIM.f,&var346.f);
  signal_R0ST01RIM.error = var346.error;
  fplet(&signal_R0SR02RIM.f,&var347.f);
  signal_R0SR02RIM.error = var347.error;
  fplet(&signal_R0CR02RIM.f,&var285.f);
  signal_R0CR02RIM.error = var285.error;
  fplet(&signal_R0CR01RIM.f,&var287.f);
  signal_R0CR01RIM.error = var287.error;
  fplet(&signal_B0SN08RIM.f,&var342.f);
  signal_B0SN08RIM.error = var342.error;
  fplet(&signal_A0SN08RIM.f,&var393.f);
  signal_A0SN08RIM.error = var393.error;
  fplet(&signal_B0SR01RIM.f,&var343.f);
  signal_B0SR01RIM.error = var343.error;
  fplet(&signal_A0SR01RIM.f,&var394.f);
  signal_A0SR01RIM.error = var394.error;

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
ParExchange("A1AD11LDU",3,&SignalBuffer[5],"������ �� ����������� ��1 �����",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(7);
#else
ParExchange("A1AD21LDU",3,&SignalBuffer[7],"������ �� ����������� ��1 ����",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(9);
#else
ParExchange("A1AD01LDU",3,&SignalBuffer[9],"���������� �������� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(11);
#else
ParExchange("A1AD02LDU",3,&SignalBuffer[11],"0-� ��� �������� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(13);
#else
ParExchange("A1AD03LDU",3,&SignalBuffer[13],"1-� ��� �������� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(15);
#else
ParExchange("A1AD04LDU",3,&SignalBuffer[15],"2-� ��� �������� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(17);
#else
ParExchange("A1AD05LDU",3,&SignalBuffer[17],"������� ������� �� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(19);
#else
ParExchange("B1AD11LDU",3,&SignalBuffer[19],"������ �� ����������� ��2 �����",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(21);
#else
ParExchange("B1AD21LDU",3,&SignalBuffer[21],"������ �� ����������� ��2 ����",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(23);
#else
ParExchange("B1AD01LDU",3,&SignalBuffer[23],"���������� �������� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(25);
#else
ParExchange("B1AD02LDU",3,&SignalBuffer[25],"0-� ��� ��������  ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(27);
#else
ParExchange("B1AD03LDU",3,&SignalBuffer[27],"1-� ��� �������� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(29);
#else
ParExchange("B1AD04LDU",3,&SignalBuffer[29],"2-� ��� �������� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(31);
#else
ParExchange("B1AD05LDU",3,&SignalBuffer[31],"������� ������� �� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(33);
#else
ParExchange("A2AD11LDU",3,&SignalBuffer[33],"������ �� ����������� ��1 �����",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(35);
#else
ParExchange("A2AD21LDU",3,&SignalBuffer[35],"������ �� ����������� ��1 ����",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(37);
#else
ParExchange("A2AD01LDU",3,&SignalBuffer[37],"���������� �������� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(39);
#else
ParExchange("A2AD02LDU",3,&SignalBuffer[39],"0-� ��� �������� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(41);
#else
ParExchange("A2AD03LDU",3,&SignalBuffer[41],"1-� ��� �������� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(43);
#else
ParExchange("A2AD04LDU",3,&SignalBuffer[43],"2-� ��� �������� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(45);
#else
ParExchange("A2AD05LDU",3,&SignalBuffer[45],"������� ������� �� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(47);
#else
ParExchange("A2AD33LDU",3,&SignalBuffer[47],"������ (������ ��1) ������� (����������)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(49);
#else
ParExchange("B2AD11LDU",3,&SignalBuffer[49],"������ �� ����������� ��2 �����",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(51);
#else
ParExchange("B2AD21LDU",3,&SignalBuffer[51],"������ �� ����������� ��2 ����",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(53);
#else
ParExchange("B2AD01LDU",3,&SignalBuffer[53],"���������� �������� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(55);
#else
ParExchange("B2AD02LDU",3,&SignalBuffer[55],"0-� ��� �������� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(57);
#else
ParExchange("B2AD03LDU",3,&SignalBuffer[57],"1-� ��� �������� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(59);
#else
ParExchange("B2AD04LDU",3,&SignalBuffer[59],"2-� ��� �������� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(61);
#else
ParExchange("B2AD05LDU",3,&SignalBuffer[61],"������� ������� �� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(63);
#else
ParExchange("B2AD33LDU",3,&SignalBuffer[63],"������ (������ ��2) ������� (����������)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(65);
#else
ParExchange("A3AD11LDU",3,&SignalBuffer[65],"������ �� ����������� ��1 �����",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(67);
#else
ParExchange("A3AD21LDU",3,&SignalBuffer[67],"������ �� ����������� ��1 ����",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(69);
#else
ParExchange("A3AD01LDU",3,&SignalBuffer[69],"���������� �������� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(71);
#else
ParExchange("A3AD02LDU",3,&SignalBuffer[71],"0-� ��� �������� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(73);
#else
ParExchange("A3AD03LDU",3,&SignalBuffer[73],"1-� ��� �������� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(75);
#else
ParExchange("A3AD04LDU",3,&SignalBuffer[75],"2-� ��� �������� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(77);
#else
ParExchange("A3AD05LDU",3,&SignalBuffer[77],"������� ������� �� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(79);
#else
ParExchange("A3AD33LDU",3,&SignalBuffer[79],"������ �������  ��1 ������� (����������)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(81);
#else
ParExchange("B3AD11LDU",3,&SignalBuffer[81],"������ �� ����������� ��2 �����",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(83);
#else
ParExchange("B3AD21LDU",3,&SignalBuffer[83],"������ �� ����������� ��2 ����",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(85);
#else
ParExchange("B3AD01LDU",3,&SignalBuffer[85],"���������� �������� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(87);
#else
ParExchange("B3AD02LDU",3,&SignalBuffer[87],"0-� ��� �������� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(89);
#else
ParExchange("B3AD03LDU",3,&SignalBuffer[89],"1-� ��� �������� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(91);
#else
ParExchange("B3AD04LDU",3,&SignalBuffer[91],"2-� ��� �������� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(93);
#else
ParExchange("B3AD05LDU",3,&SignalBuffer[93],"������� ������� �� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(95);
#else
ParExchange("B3AD33LDU",3,&SignalBuffer[95],"������ ������� ��2 ������� (����������)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(102);
#else
ParExchange("R4AD10LDU",3,&SignalBuffer[102],"����������� ������� ������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(104);
#else
ParExchange("R4AD20LDU",3,&SignalBuffer[104],"����������� ������� �����",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(106);
#else
ParExchange("B8AD10LDU",3,&SignalBuffer[106],"����������� ��2 ������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(108);
#else
ParExchange("B8AD20LDU",3,&SignalBuffer[108],"����������� ��2 �����",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(110);
#else
ParExchange("A8AD10LDU",3,&SignalBuffer[110],"����������� ��2 ������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(112);
#else
ParExchange("A8AD20LDU",3,&SignalBuffer[112],"����������� ��2 �����",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(114);
#else
ParExchange("A6AD10LDU",3,&SignalBuffer[114],"������� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(116);
#else
ParExchange("A6AD20LDU",3,&SignalBuffer[116],"������� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(118);
#else
ParExchange("B6AD10LDU",3,&SignalBuffer[118],"������� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(120);
#else
ParExchange("B6AD20LDU",3,&SignalBuffer[120],"������� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(122);
#else
ParExchange("R1AD10LDU",3,&SignalBuffer[122],"�������� ���1 � ���� ���������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(124);
#else
ParExchange("R1AD20LDU",3,&SignalBuffer[124],"������� ���1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(126);
#else
ParExchange("R2AD10LDU",3,&SignalBuffer[126],"�������� ���2 � ���� ���������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(128);
#else
ParExchange("R2AD20LDU",3,&SignalBuffer[128],"������� ���2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(130);
#else
ParExchange("A5AD10LDU",3,&SignalBuffer[130],"������� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(132);
#else
ParExchange("A5AD20LDU",3,&SignalBuffer[132],"�������� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(134);
#else
ParExchange("B5AD10LDU",3,&SignalBuffer[134],"������� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(136);
#else
ParExchange("B5AD20LDU",3,&SignalBuffer[136],"�������� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(163);
#else
ParExchange("R0AD14LDU",3,&SignalBuffer[163],"�������� ������������ ������� �� II ��",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(165);
#else
ParExchange("R8AD21LDU",3,&SignalBuffer[165],"������ ������� �������������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(165);
#else
ParExchange("R8AD21LDU",3,&SignalBuffer[165],"������ ������� �������������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(167);
#else
ParExchange("R0VZ71LZ1",3,&SignalBuffer[167],"���������� ������ �� ��  1 ������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(169);
#else
ParExchange("R0VZ71LZ2",3,&SignalBuffer[169],"���������� ������ �� ��  2 ������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(171);
#else
ParExchange("A2AD32LDU",3,&SignalBuffer[171],"���������� �� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(173);
#else
ParExchange("C2MD31LP1",3,&SignalBuffer[173],"������ ������ ���",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(173);
#else
ParExchange("C2MD31LP1",3,&SignalBuffer[173],"������ ������ ���",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(175);
#else
ParExchange("A2AD31LDU",3,&SignalBuffer[175],"������ (����� ��1) ������� (����������)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(177);
#else
ParExchange("A1AD32LDU",3,&SignalBuffer[177],"���������� �� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(179);
#else
ParExchange("A1AD31LDU",3,&SignalBuffer[179],"������ (����� ��1) ������� (����������)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(181);
#else
ParExchange("C1MD31LP2",3,&SignalBuffer[181],"������ ������ ���  �� ���2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(181);
#else
ParExchange("C1MD31LP2",3,&SignalBuffer[181],"������ ������ ���  �� ���2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(183);
#else
ParExchange("C1MD31LP1",3,&SignalBuffer[183],"������ ������ ���  �� ���1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(183);
#else
ParExchange("C1MD31LP1",3,&SignalBuffer[183],"������ ������ ���  �� ���1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(185);
#else
ParExchange("A3AD31LDU",3,&SignalBuffer[185],"������ (����� ��1) ������� (����������)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(187);
#else
ParExchange("B1AD31LDU",3,&SignalBuffer[187],"������ (����� ��2) ������� (����������)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(189);
#else
ParExchange("B1AD32LDU",3,&SignalBuffer[189],"���������� �� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(191);
#else
ParExchange("B2AD31LDU",3,&SignalBuffer[191],"������ (����� ��2) ������� (����������)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(193);
#else
ParExchange("B2AD32LDU",3,&SignalBuffer[193],"���������� �� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(195);
#else
ParExchange("B3AD31LDU",3,&SignalBuffer[195],"������ (����� ��2) ������� (����������)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(197);
#else
ParExchange("R0MW13LP2",3,&SignalBuffer[197],"������������� ����ܻ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(199);
#else
ParExchange("B9AD10LDU",3,&SignalBuffer[199],"������� ������ (������ �� ��2)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(201);
#else
ParExchange("A9AD10LDU",3,&SignalBuffer[201],"������� ������ (������ �� ��1)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(203);
#else
ParExchange("B4AD10LDU",3,&SignalBuffer[203],"������� ������ (������ ��2)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(205);
#else
ParExchange("A4AD10LDU",3,&SignalBuffer[205],"������� ������ (������ ��1)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(223);
#else
ParExchange("R0AD16LDU",3,&SignalBuffer[223],"��������  I-II ��. ���",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(233);
#else
ParExchange("B3AD34LDU",3,&SignalBuffer[233],"������ (����2) ������� (����������)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(623);
#else
ParExchange("R0EE01LZ1",3,&SignalBuffer[623],"�������  ����1  ���������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(625);
#else
ParExchange("R0EE01LZ2",3,&SignalBuffer[625],"�������  ����1  ���������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(627);
#else
ParExchange("R0EE02LZ1",3,&SignalBuffer[627],"�������  ����  ���������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(629);
#else
ParExchange("R0EE03LZ1",3,&SignalBuffer[629],"�������  ����3  ���������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(631);
#else
ParExchange("R0EE04LZ1",3,&SignalBuffer[631],"�������  ����4  ���������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(633);
#else
ParExchange("R0EE02LZ2",3,&SignalBuffer[633],"�������  ����  ���������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(635);
#else
ParExchange("R0EE03LZ2",3,&SignalBuffer[635],"�������  ����3  ���������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(637);
#else
ParExchange("R0EE04LZ2",3,&SignalBuffer[637],"�������  ����4  ���������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(641);
#else
ParExchange("A3AD34LDU",3,&SignalBuffer[641],"������ (���� ��1) ������� (����������)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(732);
#else
ParExchange("A7AP31LDU",3,&SignalBuffer[732],"������ (����� ��1) ������� (����������)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(734);
#else
ParExchange("B7AP31LDU",3,&SignalBuffer[734],"������ (����� ��2) ������� (����������)",0);
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
 for(counter=0; counter<736; counter++) {
   *((unsigned char*)(SignalBuffer)+PBLENGTH-counter-1) =
          (unsigned char)~(*((unsigned char*)(SignalBuffer)+counter));
 }
#endif
}
#endif
#ifdef SIMUL_MODE
void UnloadSignals()
{
ParExchange("A0SR01RIM",1,&SignalBuffer[0],"������� ������������ A�1",1);
ParExchange("B0SR01RIM",1,&SignalBuffer[97],"������� ������������ A�2",1);
ParExchange("A0SN08RIM",1,&SignalBuffer[138],"����� ��������� A�1(�����/�)",1);
ParExchange("B0SN08RIM",1,&SignalBuffer[143],"����� ��������� A�2(�����/�)",1);
ParExchange("R0CR01RIM",1,&SignalBuffer[148],"����������� 12 ����� ��1,2",1);
ParExchange("R0CR02RIM",1,&SignalBuffer[153],"����������� 11 ����� ��1,2",1);
ParExchange("R0SR02RIM",1,&SignalBuffer[158],"������� �������� �� (����)",1);
ParExchange("R0ST01RIM",1,&SignalBuffer[207],"������� ������ ������� ��",1);
ParExchange("R0SR01RIM",1,&SignalBuffer[212],"������� ������������ P�",1);
ParExchange("R7II73LZ1",3,&SignalBuffer[217],"��������� �� II��",1);
ParExchange("R7II71LZ1",3,&SignalBuffer[219],"��������� �� I�� (������ 1)",1);
ParExchange("R7II72LZ1",3,&SignalBuffer[221],"��������� �� I�� (������ 2)",1);
ParExchange("R7II72LZ2",3,&SignalBuffer[225],"��������� �� I�� (������ 2)",1);
ParExchange("R7II71LZ2",3,&SignalBuffer[227],"��������� �� I�� (������ 1)",1);
ParExchange("R7II73LZ2",3,&SignalBuffer[229],"��������� �� II��",1);
ParExchange("A3IS35LDU",3,&SignalBuffer[231],"������ (����1) ������(���������)",1);
ParExchange("B3IS35LDU",3,&SignalBuffer[235],"������ �����2� ������(���������)",1);
ParExchange("R0VN02RS1",1,&SignalBuffer[237],"������� �������� �����1",1);
ParExchange("R0VN61LS1",3,&SignalBuffer[242],"�� �� �������� �����1",1);
ParExchange("R0VN71LZ1",3,&SignalBuffer[244],"�� �� �������� �����1 �� ���1",1);
ParExchange("A0VN71LS1",3,&SignalBuffer[246],"���������� ���������������  ������� �� ����� 1 �� ���1",1);
ParExchange("R0VN15RS1",2,&SignalBuffer[248],"����� ������� ������ 1-���-11,2-���-15�-1,3-���-53�,0-��� �������",1);
ParExchange("R0VN71LZ2",3,&SignalBuffer[251],"�� �� �������� ����� 1  �� ���2",1);
ParExchange("A1VN71LS1",3,&SignalBuffer[253],"���������� ���������������  ������� �� ����� 1 �� ���2",1);
ParExchange("R0VN01RS1",1,&SignalBuffer[255],"������ ������� �����1",1);
ParExchange("R0VN65LS1",3,&SignalBuffer[260],"�� �� ������� ������� �����1",1);
ParExchange("R0VN75LZ1",3,&SignalBuffer[262],"�� �� ������� ��������� ���1",1);
ParExchange("A0EE01LS1",3,&SignalBuffer[264],"����������� ���� �����1 �� ���1",1);
ParExchange("R0VN75LZ2",3,&SignalBuffer[266],"�� �� ������� ��������� ���2",1);
ParExchange("A1EE01LS1",3,&SignalBuffer[268],"����������� ���� �� ���2",1);
ParExchange("R0IE11LS1",3,&SignalBuffer[270],"����������� ��� 1,6 (�8) ���11 1������",1);
ParExchange("R0IE12LS1",3,&SignalBuffer[272],"����������� ��� 0,5 (�9) ���15-1 1������",1);
ParExchange("R0IE13LS1",3,&SignalBuffer[274],"����������� ��� 0,5 (�10) ���53� 1������",1);
ParExchange("R0VN02RS2",1,&SignalBuffer[276],"������� �������� ����� 2",1);
ParExchange("R0VN61LS2",3,&SignalBuffer[281],"�� �� �������� ����� 2",1);
ParExchange("R0VN72LZ1",3,&SignalBuffer[283],"�� �� �������� ����� 2 �� ���1",1);
ParExchange("A1VN71LS2",3,&SignalBuffer[285],"���������� ��������������� ������� �� ����� 2 �� ���2",1);
ParExchange("R0VN15RS2",2,&SignalBuffer[287],"����� ������� ������ ����� 2",1);
ParExchange("R0VN72LZ2",3,&SignalBuffer[290],"�� �� �������� ����� 2 �� ���2",1);
ParExchange("A0VN71LS2",3,&SignalBuffer[292],"���������� ��������������� ������� �� ����� 2 �� ���1",1);
ParExchange("R0VN01RS2",1,&SignalBuffer[294],"������ ������� ����� 2",1);
ParExchange("R0VN65LS2",3,&SignalBuffer[299],"�� �� ������� ������� ����� 2",1);
ParExchange("R0VN76LZ1",3,&SignalBuffer[301],"�� �� ������� ������� ����� 2  �� ���1",1);
ParExchange("A0EE01LS2",3,&SignalBuffer[303],"����������� ���� ����� 2 �� ���1",1);
ParExchange("R0VN76LZ2",3,&SignalBuffer[305],"�� �� ������� ������� ����� 2  �� ���2",1);
ParExchange("A1EE01LS2",3,&SignalBuffer[307],"����������� ���� ����� 2 �� ���2",1);
ParExchange("R0IE12LS2",3,&SignalBuffer[309],"����������� ��� 0,5 (�12) ���15-1 2������",1);
ParExchange("R0IE13LS2",3,&SignalBuffer[311],"����������� ��� 0,5 (�13) ���53� 2������",1);
ParExchange("R0IE11LS2",3,&SignalBuffer[313],"����������� ��� 1,6 (�11) ���11 2������",1);
ParExchange("R0VN02RS3",1,&SignalBuffer[315],"������� �������� ����� 3",1);
ParExchange("R0VN61LS3",3,&SignalBuffer[320],"�� �� �������� ����� 3",1);
ParExchange("R0VN73LZ1",3,&SignalBuffer[322],"�� �� �������� ����� 3 �� ���1",1);
ParExchange("A1VN71LS3",3,&SignalBuffer[324],"���������� ���������������  ������� �� ����� 3 �� ���2",1);
ParExchange("R0VN15RS3",2,&SignalBuffer[326],"����� ������� ������ ����� 3",1);
ParExchange("A0VN71LS3",3,&SignalBuffer[329],"���������� ���������������  ������� �� ����� 3 �� ���1",1);
ParExchange("R0VN73LZ2",3,&SignalBuffer[331],"�� �� �������� ����� 3 �� ���2",1);
ParExchange("R0VN01RS3",1,&SignalBuffer[333],"������ ������� ����� 3",1);
ParExchange("R0VN65LS3",3,&SignalBuffer[338],"�� �� ������� ������� ����� 3",1);
ParExchange("R0VN77LZ1",3,&SignalBuffer[340],"�� �� ������� ������� ����� 3 �� ���1",1);
ParExchange("A0EE01LS3",3,&SignalBuffer[342],"����������� ���� ����� 3 �� ���1",1);
ParExchange("R0VN77LZ2",3,&SignalBuffer[344],"�� �� ������� ������� ����� 3 �� ���2",1);
ParExchange("A1EE01LS3",3,&SignalBuffer[346],"����������� ���� ����� 3 �� ���2",1);
ParExchange("R0IE12LS3",3,&SignalBuffer[348],"����������� ��� 0,5 (�15) ���15-1 3������",1);
ParExchange("R0IE13LS3",3,&SignalBuffer[350],"����������� ��� 0,5 (�16) ���53� 3������",1);
ParExchange("R0IE11LS3",3,&SignalBuffer[352],"����������� ��� 1,6 (�14) ���11 3������",1);
ParExchange("R0VN02RS4",1,&SignalBuffer[354],"������� �������� ����� 4",1);
ParExchange("R0VN61LS4",3,&SignalBuffer[359],"�� �� �������� ����� 4",1);
ParExchange("R0VN74LZ1",3,&SignalBuffer[361],"�� �� �������� ����� 4 �� ���1",1);
ParExchange("A1VN71LS4",3,&SignalBuffer[363],"���������� ���������������  ������� �� ����� 4 �� ���2",1);
ParExchange("R0VN15RS4",2,&SignalBuffer[365],"����� ������� ������ ����� 4",1);
ParExchange("A0VN71LS4",3,&SignalBuffer[368],"���������� ���������������  ������� �� ����� 4 �� ���1",1);
ParExchange("R0VN74LZ2",3,&SignalBuffer[370],"�� �� �������� ����� 4 �� ���2",1);
ParExchange("R0VN01RS4",1,&SignalBuffer[372],"������ ������� ����� 4",1);
ParExchange("R0VN65LS4",3,&SignalBuffer[377],"�� �� ������� ������� ����� 4",1);
ParExchange("R0VN78LZ1",3,&SignalBuffer[379],"�� �� ������� ������� ����� 4 �� ���1",1);
ParExchange("A0EE01LS4",3,&SignalBuffer[381],"����������� ���� ����� 4 �� ���1",1);
ParExchange("R0VN78LZ2",3,&SignalBuffer[383],"�� �� ������� ������� ����� 4 �� ���2",1);
ParExchange("A1EE01LS4",3,&SignalBuffer[385],"����������� ���� ����� 4 �� ���2",1);
ParExchange("R0IE12LS4",3,&SignalBuffer[387],"����������� ��� 0,5 (�18) ���15-1 4������",1);
ParExchange("R0IE13LS4",3,&SignalBuffer[389],"����������� ��� 0,5 (�19) ���53� 4������",1);
ParExchange("R0IE11LS4",3,&SignalBuffer[391],"����������� ��� 1,6 (�17) ���11 4������",1);
ParExchange("A7AS31LDU",3,&SignalBuffer[393],"������ (����� ��1) ������ (���������)",1);
ParExchange("B7AS31LDU",3,&SignalBuffer[395],"������ (����� ��2) ������ (���������)",1);
ParExchange("R6IS21LDU",3,&SignalBuffer[397],"����-����� � ��������� ���������",1);
ParExchange("A0IT01IZ1",2,&SignalBuffer[399],"����������� ��1-1",1);
ParExchange("A0IT02IZ2",2,&SignalBuffer[402],"����������� ��1-2",1);
ParExchange("B0IT01IZ1",2,&SignalBuffer[405],"����������� ��2-1",1);
ParExchange("B0IT02IZ2",2,&SignalBuffer[408],"����������� ��2-2",1);
ParExchange("A2IS21LDU",3,&SignalBuffer[411],"������ �� �� ��1",1);
ParExchange("A2IS11LDU",3,&SignalBuffer[413],"������ �� �� ��1",1);
ParExchange("A2IS12LDU",3,&SignalBuffer[415],"������ ��1 ��������",1);
ParExchange("A2IC01UDU",7,&SignalBuffer[417],"���������� ����� ��1",1);
ParExchange("A2IS33LDU",3,&SignalBuffer[422],"������ (������ ��1)  ������ (���������)",1);
ParExchange("A3IS21LDU",3,&SignalBuffer[424],"������ �� �� ��1",1);
ParExchange("B3IS21LDU",3,&SignalBuffer[426],"������ �� �� ��2",1);
ParExchange("A2IP01IZ1",2,&SignalBuffer[428],"������� �������� ����� ��1",1);
ParExchange("A2IP01IZ2",2,&SignalBuffer[431],"������� �������� ����� ��1",1);
ParExchange("A2VP82LDU",3,&SignalBuffer[434],"�������� ���ڨ� ��1 � �����",1);
ParExchange("A3IS31LDU",3,&SignalBuffer[436],"������ (����� ��1)  ������ (���������)",1);
ParExchange("A3IC01UDU",7,&SignalBuffer[438],"���������� ����� ��1",1);
ParExchange("A3IS33LDU",3,&SignalBuffer[443],"������ (������� ��1)  ������ (���������)",1);
ParExchange("B3IP02IDU",2,&SignalBuffer[445],"������� �������� �������  ��2",1);
ParExchange("B3IS31LDU",3,&SignalBuffer[448],"������ (����� ��2)  ������ (���������)",1);
ParExchange("B3IC01UDU",7,&SignalBuffer[450],"���������� ����� ��2",1);
ParExchange("B3IS33LDU",3,&SignalBuffer[455],"������ �������� ��2�  ������ (���������)",1);
ParExchange("A3VP81LDU",3,&SignalBuffer[457],"�������� ����� ��1 � �����",1);
ParExchange("B3VP81LDU",3,&SignalBuffer[459],"�������� ����� ��2 � �����",1);
ParExchange("A3IP02IDU",2,&SignalBuffer[461],"������� �������� ������� ��1",1);
ParExchange("A3IS11LDU",3,&SignalBuffer[464],"������ �� �� ��1",1);
ParExchange("B3IS11LDU",3,&SignalBuffer[466],"������ �� �� ��2",1);
ParExchange("A3IS22LDU",3,&SignalBuffer[468],"������ �� ��� ��1",1);
ParExchange("B3IS22LDU",3,&SignalBuffer[470],"������ �� ��� ��2",1);
ParExchange("R6IS62LDU",3,&SignalBuffer[472],"����������� ��� ����-39 1�����",1);
ParExchange("R6IS63LDU",3,&SignalBuffer[474],"����������� ��� ����-39 2�����",1);
ParExchange("R6IS64LDU",3,&SignalBuffer[476],"����������� ��� ����-35 1�����",1);
ParExchange("R6IS65LDU",3,&SignalBuffer[478],"����������� ��� ����-35 2�����",1);
ParExchange("R6IS66LZZ",3,&SignalBuffer[480],"����������� ��� 4,0 (�5) ����-1-1",1);
ParExchange("R6IS67LZZ",3,&SignalBuffer[482],"����������� ��� 4,0 (�6) ����-1-2",1);
ParExchange("R6IS68LZZ",3,&SignalBuffer[484],"����������� ��� 4,0 (�7) ����-2",1);
ParExchange("A8IC01UDU",7,&SignalBuffer[486],"���������� ��2",1);
ParExchange("B8IC01UDU",7,&SignalBuffer[491],"���������� ��2",1);
ParExchange("A0VP81LZZ",3,&SignalBuffer[496],"�������� ��1 � �����",1);
ParExchange("B0VP81LZZ",3,&SignalBuffer[498],"�������� ��2 � �����",1);
ParExchange("A5IS11LDU",3,&SignalBuffer[500],"������ �� �� ��1",1);
ParExchange("A5IS21LDU",3,&SignalBuffer[502],"������ �� �� ��1",1);
ParExchange("B5IS11LDU",3,&SignalBuffer[504],"������ �� �� ��2",1);
ParExchange("B5IS21LDU",3,&SignalBuffer[506],"������ �� �� ��2",1);
ParExchange("A9IS11LDU",3,&SignalBuffer[508],"������ �� �� �� ��1",1);
ParExchange("A9IS21LDU",3,&SignalBuffer[510],"������ �� �� �� ��1",1);
ParExchange("B9IS11LDU",3,&SignalBuffer[512],"������ �� �� �� ��2",1);
ParExchange("B9IS21LDU",3,&SignalBuffer[514],"������ �� �� �� ��2",1);
ParExchange("B2IS21LDU",3,&SignalBuffer[516],"������ �� �� ��2",1);
ParExchange("B2IS11LDU",3,&SignalBuffer[518],"������ �� �� ��2",1);
ParExchange("B2IS12LDU",3,&SignalBuffer[520],"������ ��2 ��������",1);
ParExchange("B2IC01UDU",7,&SignalBuffer[522],"���������� ����� ��2",1);
ParExchange("B2IP01IZ1",2,&SignalBuffer[527],"������� �������� ����� ��2",1);
ParExchange("B2IP01IZ2",2,&SignalBuffer[530],"������� �������� ����� ��2",1);
ParExchange("B2VP82LDU",3,&SignalBuffer[533],"�������� ���ڨ� ��2 � �����",1);
ParExchange("R3IS11LDU",3,&SignalBuffer[535],"������ �� �� ���������� ������",1);
ParExchange("R3IS21LDU",3,&SignalBuffer[537],"������ �� �� ���������� ������",1);
ParExchange("R5IS11LDU",3,&SignalBuffer[539],"������ �� �� ����� ��������� ����",1);
ParExchange("R5IS21LDU",3,&SignalBuffer[541],"������ �� �� ����� ��������� ����",1);
ParExchange("A4IS11LDU",3,&SignalBuffer[543],"������ �� �� ��1",1);
ParExchange("A4IS21LDU",3,&SignalBuffer[545],"������ �� �� ��1",1);
ParExchange("R8IS11LDU",3,&SignalBuffer[547],"��������� �� ����������",1);
ParExchange("B4IS11LDU",3,&SignalBuffer[549],"������ �� �� ��2",1);
ParExchange("B4IS21LDU",3,&SignalBuffer[551],"������ �� �� ��2",1);
ParExchange("R1IS11LDU",3,&SignalBuffer[553],"������ �� �� ���1",1);
ParExchange("R1IS21LDU",3,&SignalBuffer[555],"������ �� �� ���1",1);
ParExchange("R2IS11LDU",3,&SignalBuffer[557],"������ �� �� ���2",1);
ParExchange("R2IS21LDU",3,&SignalBuffer[559],"������ �� �� ���2",1);
ParExchange("A4VP82LDU",3,&SignalBuffer[561],"�������� ���ڨ� ��1 � �����",1);
ParExchange("B4VP82LDU",3,&SignalBuffer[563],"�������� ���ڨ� ��2 � �����",1);
ParExchange("R4IS11LDU",3,&SignalBuffer[565],"������ �� ��1 �������",1);
ParExchange("R4IS21LDU",3,&SignalBuffer[567],"������ �� ��1 �������",1);
ParExchange("R4IS22LDU",3,&SignalBuffer[569],"������ �� ��2 �������",1);
ParExchange("R4IS12LDU",3,&SignalBuffer[571],"������ ��  ��2 �������",1);
ParExchange("B8IS22LDU",3,&SignalBuffer[573],"������ �� ��2 ��2",1);
ParExchange("B8IS12LDU",3,&SignalBuffer[575],"������ �� ��2 ��2",1);
ParExchange("A8IS22LDU",3,&SignalBuffer[577],"������ �� ������������ �� ��2",1);
ParExchange("A8IS12LDU",3,&SignalBuffer[579],"������ �� ������������ �� ��2",1);
ParExchange("A6IS11LDU",3,&SignalBuffer[581],"������ �� �� ��1",1);
ParExchange("A6IS21LDU",3,&SignalBuffer[583],"������ �� �� ��1",1);
ParExchange("B6IS11LDU",3,&SignalBuffer[585],"������ �� �� ��2",1);
ParExchange("B6IS21LDU",3,&SignalBuffer[587],"������ �� �� ��2",1);
ParExchange("A1IS21LDU",3,&SignalBuffer[589],"������ �� �� ��1",1);
ParExchange("A1IS11LDU",3,&SignalBuffer[591],"������ �� �� ��1",1);
ParExchange("A1IS12LDU",3,&SignalBuffer[593],"������ ��1 ��������",1);
ParExchange("A1IC01UDU",7,&SignalBuffer[595],"���������� ����� ��1",1);
ParExchange("B1IC01UDU",7,&SignalBuffer[600],"���������� ����� ��2",1);
ParExchange("B1IS21LDU",3,&SignalBuffer[605],"������ �� �� ��2",1);
ParExchange("B1IS11LDU",3,&SignalBuffer[607],"������ �� �� ��2",1);
ParExchange("B1IS12LDU",3,&SignalBuffer[609],"������ ��2 ��������",1);
ParExchange("A1IE03LDU",3,&SignalBuffer[611],"�������� ��1 ������ (�� ����)",1);
ParExchange("A1IE04LDU",3,&SignalBuffer[613],"�������� ��1 ����� (�� ����)",1);
ParExchange("B1IE03LDU",3,&SignalBuffer[615],"�������� ��2 ������ (�� ����)",1);
ParExchange("B1IE04LDU",3,&SignalBuffer[617],"�������� ��2 ����� (�� ����)",1);
ParExchange("A4IS10LDU",3,&SignalBuffer[619],"������ (������ ��1) ������ (���������)",1);
ParExchange("B4IS10LDU",3,&SignalBuffer[621],"������ (������ ��2) ������ (���������)",1);
ParExchange("R0IS02LDU",3,&SignalBuffer[639],"���������� ����� �� ���������",1);
ParExchange("A1IS11LIM",3,&SignalBuffer[643],"������ ��1 ���������",1);
ParExchange("A1IS32LIM",3,&SignalBuffer[645],"������ c����� ��1 ������(���������)",1);
ParExchange("B1IS11LIM",3,&SignalBuffer[647],"������ ��2 ���������",1);
ParExchange("B1IS32LIM",3,&SignalBuffer[649],"������ c����� ��2 ������(���������)",1);
ParExchange("A2IS11LIM",3,&SignalBuffer[651],"������ ��1 ���������",1);
ParExchange("A2IS32LIM",3,&SignalBuffer[653],"������ c����� ��1 ������(���������)",1);
ParExchange("B2IS11LIM",3,&SignalBuffer[655],"������ ��2 ���������",1);
ParExchange("B2IS32LIM",3,&SignalBuffer[657],"������ c����� ��2 ������(���������)",1);
ParExchange("A0VN01RIM",1,&SignalBuffer[659],"������ �������  A�1",1);
ParExchange("B2IS33LDU",3,&SignalBuffer[664],"������ (������ ��2)  ������ (���������)",1);
ParExchange("B1VP81LZZ",3,&SignalBuffer[666],"�������� ����� ��2 � �����",1);
ParExchange("A1VP81LZZ",3,&SignalBuffer[668],"�������� ����� ��1 � �����",1);
ParExchange("B8IS11LDU",3,&SignalBuffer[670],"������ �� ��1 ��2",1);
ParExchange("B8IS21LDU",3,&SignalBuffer[672],"������ �� ��1 ��2",1);
ParExchange("A6VS22LDU",3,&SignalBuffer[674],"�������� ������� ��1  � �������",1);
ParExchange("A6VS12LDU",3,&SignalBuffer[676],"�������� ������� ��1  �  �������",1);
ParExchange("B6VS22LDU",3,&SignalBuffer[678],"�������� ������� ��2  � �������",1);
ParExchange("B6VS12LDU",3,&SignalBuffer[680],"�������� ������� ��2  � �������",1);
ParExchange("A5VS22LDU",3,&SignalBuffer[682],"�������� ��1 � ������� ��",1);
ParExchange("A5VS12LDU",3,&SignalBuffer[684],"�������� ��1 � ������� ��",1);
ParExchange("B5VS22LDU",3,&SignalBuffer[686],"�������� ��2 � ������� ��",1);
ParExchange("B5VS12LDU",3,&SignalBuffer[688],"�������� ��2 � ������� ��",1);
ParExchange("R1VS22LDU",3,&SignalBuffer[690],"�������� ���1 � ������� ��",1);
ParExchange("R2VS22LDU",3,&SignalBuffer[692],"�������� ���2 � ������� ��",1);
ParExchange("R2VS12LDU",3,&SignalBuffer[694],"�������� ���2 � ������� ��",1);
ParExchange("R1VS12LDU",3,&SignalBuffer[696],"�������� ���1 � ������� ��",1);
ParExchange("R4VS22LDU",3,&SignalBuffer[698],"�������� �������� � �� �����ۻ",1);
ParExchange("R4VS12LDU",3,&SignalBuffer[700],"�������� ��������  � �� �������»",1);
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
NewEEPROM("fEM_R0UL01RIM",1,&fEM_R0UL01RIM,"������� ����� ��������� ���������","0.015");
NewEEPROM("fEM_R0UN02RIM",1,&fEM_R0UN02RIM,"���� ������������� ��������� � ����� ���������� ���������","0.0069");
NewEEPROM("fEM_A1UR01RIM",1,&fEM_A1UR01RIM,"�����������-1 ������� ������������ �������� �� (����)","0.21");
NewEEPROM("fEM_A1UR00RIM",1,&fEM_A1UR00RIM,"�����������-0 ������� ������������ �������� �� (����)","0");
NewEEPROM("fEM_A3UR00RIM",1,&fEM_A3UR00RIM,"�����������-0 ������� ������������ �������� �� (����)","0");
NewEEPROM("fEM_A3UR01RIM",1,&fEM_A3UR01RIM,"�����������-1 ������� ������������ �������� �� (����)","0.0096");
NewEEPROM("fEM_R0UT01RIM",1,&fEM_R0UT01RIM,"������������� ����������� (����)","0.0026");
NewEEPROM("fEM_R0UT02RIM",1,&fEM_R0UT02RIM,"����� ������� � ��","106");
NewEEPROM("fEM_R0UT04RIM",1,&fEM_R0UT04RIM,"�������� ����������� �������","135.227");
NewEEPROM("fEM_R0UT03RIM",1,&fEM_R0UT03RIM,"���������� ����������� �� ����","25");
NewEEPROM("fEM_R0UT05RIM",1,&fEM_R0UT05RIM,"������� ������� ����","320.435466");
NewEEPROM("fEM_R0UT06RIM",1,&fEM_R0UT06RIM,"������������� ������������� ��� ������","0.0055");
NewEEPROM("fEM_A1UC02RDU",1,&fEM_A1UC02RDU,"����������� �������������� ������� ��������� �� � �������� ��/�","0.000877");
NewEEPROM("fEM_A1UC04RIM",1,&fEM_A1UC04RIM,"���������� �������������� �������� ����������� �� ��","200");
NewEEPROM("fEM_A1UC05RIM",1,&fEM_A1UC05RIM,"���������� ��������� ���������� ����������� �� ��","100");
NewEEPROM("fEM_A1UC06RIM",1,&fEM_A1UC06RIM,"���������� ������� ���������� ����������� �� ��","0");
NewEEPROM("fEM_A2UC06RIM",1,&fEM_A2UC06RIM,"���������� ������� ���������� ����������� �� ��","0");
NewEEPROM("fEM_A2UC05RIM",1,&fEM_A2UC05RIM,"���������� ��������� ���������� ����������� �� ��","100");
NewEEPROM("fEM_A2UC04RIM",1,&fEM_A2UC04RIM,"���������� �������������� �������� ����������� �� ��","80");
NewEEPROM("fEM_A2UC02RDU",1,&fEM_A2UC02RDU,"����������� �������������� ������� ��������� �� � �������� ��/�","0.002375");
NewEEPROM("fEM_A3UC06RIM",1,&fEM_A3UC06RIM,"���������� ������� ���������� ����������� �� ��","0");
NewEEPROM("fEM_A3UC05RIM",1,&fEM_A3UC05RIM,"���������� ��������� ���������� ����������� �� ��","165");
NewEEPROM("fEM_A3UC04RIM",1,&fEM_A3UC04RIM,"���������� �������������� �������� ����������� �� ��","200");
NewEEPROM("fEM_A3UC02RDU",1,&fEM_A3UC02RDU,"����������� �������������� ������� ��������� �� � �������� ��/�","0.001667");
NewEEPROM("fEM_R4UV80RDU",1,&fEM_R4UV80RDU,"����������� �������� ������� (��/�)","40");
NewEEPROM("fEM_R4UC10RIM",1,&fEM_R4UC10RIM,"���������� ������� ������������ ������ ������� ��","15630.0");
NewEEPROM("fEM_R4UC20RIM",1,&fEM_R4UC20RIM,"���������� ������ ������������ ������ ������� ��","1374");
NewEEPROM("fEM_B8UC21RIM",1,&fEM_B8UC21RIM,"���������� �������� �������� ����������� ��2 ��","0");
NewEEPROM("fEM_B8UC20RIM",1,&fEM_B8UC20RIM,"���������� ������� ������������ ������ ��2 ��","390.0");
NewEEPROM("fEM_B8UC11RIM",1,&fEM_B8UC11RIM,"���������� ������� �������� ����������� ��2 ��","2000.0");
NewEEPROM("fEM_B8UC10RIM",1,&fEM_B8UC10RIM,"���������� ������ ������������ ������ ��2 ��","1500.0");
NewEEPROM("fEM_B8UV80RDU",1,&fEM_B8UV80RDU,"����������� �������� ��2 (��/�)","10.91");
NewEEPROM("fEM_A8UV80RDU",1,&fEM_A8UV80RDU,"����������� �������� ��2 (��/�)","10.91");
NewEEPROM("fEM_A8UC10RIM",1,&fEM_A8UC10RIM,"���������� ������ ������������ ������ ��2 ��","1500.0");
NewEEPROM("fEM_A8UC11RIM",1,&fEM_A8UC11RIM,"���������� ������� �������� ����������� ��2 ��","2000");
NewEEPROM("fEM_A8UC20RIM",1,&fEM_A8UC20RIM,"���������� ������� ������������ ������ ��2 ��","390.0");
NewEEPROM("fEM_A8UC21RIM",1,&fEM_A8UC21RIM,"���������� �������� �������� ����������� ��2 ��","0");
NewEEPROM("fEM_A6UC10RIM",1,&fEM_A6UC10RIM,"����� ������� ���� �� (���)","55.0");
NewEEPROM("fEM_R1UC10RIM",1,&fEM_R1UC10RIM,"����� ������� ���� ��� ���","15.0");
NewEEPROM("fEM_A5UC10RIM",1,&fEM_A5UC10RIM,"����� ������� ���� �� ���","5.0");
NewEEPROM("fEM_A0UN01RIM",1,&fEM_A0UN01RIM,"�������� ��������� ��������� ���","1E12");
NewEEPROM("fEM_R4UC22RIM",1,&fEM_R4UC22RIM,"�������� ���������� �� �� ���������� �������","43.6");
NewEEPROM("fEM_A1UG01RDU",1,&fEM_A1UG01RDU,"���������� ��������� ��������� �������� ��(��)","20.0");
NewEEPROM("fEM_A2UG01RDU",1,&fEM_A2UG01RDU,"���������� ��������� ��������� �������� ��","20.0");
NewEEPROM("fEM_A3UG01RDU",1,&fEM_A3UG01RDU,"���������� ��������� ��������� �������� ��","20.0");
NewEEPROM("fEM_R7UC10RIM",1,&fEM_R7UC10RIM,"X-���������� ���53� R7IN13 ��","1269.0");
NewEEPROM("fEM_R7UC19RIM",1,&fEM_R7UC19RIM,"Y-���������� ���-11 (11) ��","256.0");
NewEEPROM("fEM_R7UI02RIM",1,&fEM_R7UI02RIM,"����������� �������� ������ ��������","1.0");
NewEEPROM("fEM_R7UL01RIM",1,&fEM_R7UL01RIM,"���������� ������� ��������� ������ �������� � ����","2.0");
NewEEPROM("fEM_A2UR00RIM",1,&fEM_A2UR00RIM,"�����������-0 (����) ������� ������������ �������� �� (����)","0");
NewEEPROM("fEM_A2UR01RIM",1,&fEM_A2UR01RIM,"�����������-1 ������� ������������ �������� �� (����)","0.026");
NewEEPROM("fEM_A0UN02RIM",1,&fEM_A0UN02RIM,"�������� ��������� ��������� � ���","0.08");
NewEEPROM("fEM_R0UR30RIM",1,&fEM_R0UR30RIM,"������������ �������� ��������� (����)","0.0");
NewEEPROM("fEM_R0UR01RIM",1,&fEM_R0UR01RIM,"��������� ������������� ������������","27.108");
NewEEPROM("fEM_R0UT02RDU",1,&fEM_R0UT02RDU,"������� ������ ����� ������� �����������","600");
NewEEPROM("fEM_R0UT01RDU",1,&fEM_R0UT01RDU,"������ ������ ����� ������� �����������","0");
NewEEPROM("fEM_A1UC03RDU",1,&fEM_A1UC03RDU,"����������� �������������� ��������� �������� �� ��/���.��������","0.00009765625");
NewEEPROM("fEM_A2UP03RDU",1,&fEM_A2UP03RDU,"������� ������ ����� ������� �������� �� ������/����� ��","1.6");
NewEEPROM("fEM_A2UP04RDU",1,&fEM_A2UP04RDU,"������ ������ ����� ������� �������� �� ������/����� ��","0");
NewEEPROM("fEM_A2UC03RDU",1,&fEM_A2UC03RDU,"����������� �������������� ��������� �������� ��, ���.��������/��","0.00009765625");
NewEEPROM("fEM_A3UP03RDU",1,&fEM_A3UP03RDU,"������� ������ ����� ������� �������� �� ������/����� ��","2.5");
NewEEPROM("fEM_A3UP04RDU",1,&fEM_A3UP04RDU,"������ ������ ����� ������� �������� �� ������/����� ��","0");
NewEEPROM("fEM_A3UC03RDU",1,&fEM_A3UC03RDU,"����������� �������������� ��������� �������� ��, ���.��������/��","0.00009765625");
NewEEPROM("fEM_R7UI74RIM",1,&fEM_R7UI74RIM,"������� ������� ��������� ������ �������� � ����","10000.0");
NewEEPROM("fEM_A8UC03RDU",1,&fEM_A8UC03RDU,"����������� �������������� ��������� �������� ��2/��2 ��/���.��������","0.0009765625");
NewEEPROM("fEM_R0UV87RDU",1,&fEM_R0UV87RDU,"7-� �������� ����������� �� (�����/�������)","750");
NewEEPROM("fEM_R0UV81RDU",1,&fEM_R0UV81RDU,"1-� ������� ��������� (�����/�������)","100");
NewEEPROM("fEM_R0UV82RDU",1,&fEM_R0UV82RDU,"3-� ������� ��������� (�����/�������)","200");
NewEEPROM("fEM_R0UV83RDU",1,&fEM_R0UV83RDU,"4-� ������� ��������� (�����/�������)","300");
NewEEPROM("fEM_R0UV84RDU",1,&fEM_R0UV84RDU,"5-� ������� ��������� (�����/�������)","400");
NewEEPROM("fEM_R0UV85RDU",1,&fEM_R0UV85RDU,"6-� �������� ����������� �� (�����/�������)","500");
NewEEPROM("fEM_R0UV86RDU",1,&fEM_R0UV86RDU,"7-� �������� ����������� �� (�����/�������)","600");
NewEEPROM("fEM_A8UC08RDU",1,&fEM_A8UC08RDU,"���� ������������ �� ��2(��)","0.50");
NewEEPROM("fEM_B8UC08RDU",1,&fEM_B8UC08RDU,"���� ������������ �� ��2(��)","0.50");
NewEEPROM("fEM_R4UC08RDU",1,&fEM_R4UC08RDU,"���� ������������ �� ������� ��(��)","0.50");
NewEEPROM("fEM_A0UX00RSS",1,&fEM_A0UX00RSS,"����������� ������ ��","11.0");
NewEEPROM("fEM_R7UX01RSS",1,&fEM_R7UX01RSS,"X-���������� ������ R7IN11","1585.0");
NewEEPROM("fEM_R7UX02RSS",1,&fEM_R7UX02RSS,"X-���������� ������ R7IN12 (��)","1796.0");
NewEEPROM("fEM_R7UX04RSS",1,&fEM_R7UX04RSS,"X-���������� ������ R7IN21 (��)","1555.0");
NewEEPROM("fEM_R7UX05RSS",1,&fEM_R7UX05RSS,"X-���������� ������ R7IN22 (��)","1269.0");
NewEEPROM("fEM_R7UX06RSS",1,&fEM_R7UX06RSS,"X-���������� ������ R7IN23 (��)","1269.0");
NewEEPROM("fEM_R7UX07RSS",1,&fEM_R7UX07RSS,"X-���������� ������ R7IN31 (��)","1585.0");
NewEEPROM("fEM_R7UX08RSS",1,&fEM_R7UX08RSS,"X-���������� ������ R7IN32 (��)","1796.0");
NewEEPROM("fEM_R7UX09RSS",1,&fEM_R7UX09RSS,"X-���������� ������ R7IN33 (��)","1269.0");
NewEEPROM("fEM_R7UY01RSS",1,&fEM_R7UY01RSS,"Y-���������� ������ R7IN11","248.0");
NewEEPROM("fEM_R7UY02RSS",1,&fEM_R7UY02RSS,"Y-���������� ������ R7IN12 (��)","284.5");
NewEEPROM("fEM_R7UY04RSS",1,&fEM_R7UY04RSS,"Y-���������� ������ R7IN21 (��)","248.0");
NewEEPROM("fEM_R7UY05RSS",1,&fEM_R7UY05RSS,"Y-���������� ������ R7IN22 (��)","271.6");
NewEEPROM("fEM_R7UY06RSS",1,&fEM_R7UY06RSS,"Y-���������� ������ R7IN23 (��)","287.2");
NewEEPROM("fEM_R7UY07RSS",1,&fEM_R7UY07RSS,"Y-���������� ������ R7IN31 (��)","594.0");
NewEEPROM("fEM_R7UY08RSS",1,&fEM_R7UY08RSS,"Y-���������� ������ R7IN32 (��)","559.0");
NewEEPROM("fEM_R7UY09RSS",1,&fEM_R7UY09RSS,"Y-���������� ������ R7IN33 (��)","588.0");
NewEEPROM("fEM_R7UX10RSS",1,&fEM_R7UX10RSS,"X-���������� ������ R7IN41","1555.0");
NewEEPROM("fEM_R7UX11RSS",1,&fEM_R7UX11RSS,"X-���������� ������ R7IN42","1281.2");
NewEEPROM("fEM_R7UX12RSS",1,&fEM_R7UX12RSS,"X-���������� ������ R7IN43","1269.0");
NewEEPROM("fEM_R7UY10RSS",1,&fEM_R7UY10RSS,"Y-���������� ������ R7IN41","594.0");
NewEEPROM("fEM_R7UY11RSS",1,&fEM_R7UY11RSS,"Y-���������� ������ R7IN42","597.2");
NewEEPROM("fEM_R7UY12RSS",1,&fEM_R7UY12RSS,"Y-���������� ������ R7IN43","556.8");
NewEEPROM("fEM_A0UX01RSS",1,&fEM_A0UX01RSS,"������ ����������� ���������� ������ 1","1.0");
NewEEPROM("fEM_A0UX02RSS",1,&fEM_A0UX02RSS,"������ ����������� ���������� ������ 2","1.0");
NewEEPROM("fEM_A0UX03RSS",1,&fEM_A0UX03RSS,"������ ����������� ���������� ������ 3","1.0");
NewEEPROM("fEM_A0UX04RSS",1,&fEM_A0UX04RSS,"������ ����������� ���������� ������4","1.0");
NewEEPROM("fEM_A0UX05RSS",1,&fEM_A0UX05RSS,"������ ����������� ���������� ������ 5","1.0");
NewEEPROM("fEM_A0UX06RSS",1,&fEM_A0UX06RSS,"������ ����������� ���������� ������ 6","1.0");
NewEEPROM("fEM_A0UX07RSS",1,&fEM_A0UX07RSS,"������ ����������� ���������� ������ 7","1.0");
NewEEPROM("fEM_A0UX08RSS",1,&fEM_A0UX08RSS,"������ ����������� ���������� ������ 8","1.0");
NewEEPROM("fEM_A0UX09RSS",1,&fEM_A0UX09RSS,"������ ����������� ���������� ������ 9","1.0");
NewEEPROM("fEM_A0UX10RSS",1,&fEM_A0UX10RSS,"������ ����������� ���������� ������ 10","1.0");
NewEEPROM("fEM_A0UX11RSS",1,&fEM_A0UX11RSS,"������ ����������� ���������� ������ 11","1.0");
NewEEPROM("fEM_A0UX12RSS",1,&fEM_A0UX12RSS,"������ ����������� ���������� ������ 12","1.0");
NewEEPROM("fEM_B0UX01RSS",1,&fEM_B0UX01RSS,"������ ����������� ���������� ������ 1","0");
NewEEPROM("fEM_B0UX02RSS",1,&fEM_B0UX02RSS,"������ ����������� ���������� ������ 2","0");
NewEEPROM("fEM_B0UX03RSS",1,&fEM_B0UX03RSS,"������ ����������� ���������� ������ 3","0");
NewEEPROM("fEM_B0UX04RSS",1,&fEM_B0UX04RSS,"������ ����������� ���������� ������ 4","0");
NewEEPROM("fEM_B0UX05RSS",1,&fEM_B0UX05RSS,"������ ����������� ���������� ������ 5","0.0");
NewEEPROM("fEM_B0UX06RSS",1,&fEM_B0UX06RSS,"������ ����������� ���������� ������ 6","0");
NewEEPROM("fEM_B0UX07RSS",1,&fEM_B0UX07RSS,"������ ����������� ���������� ������ 7","0.0");
NewEEPROM("fEM_B0UX08RSS",1,&fEM_B0UX08RSS,"������ ����������� ���������� ������ 8","0");
NewEEPROM("fEM_B0UX09RSS",1,&fEM_B0UX09RSS,"������ ����������� ���������� ������ 9","0.0");
NewEEPROM("fEM_B0UX10RSS",1,&fEM_B0UX10RSS,"������ ����������� ���������� ������ 10","0.0");
NewEEPROM("fEM_B0UX11RSS",1,&fEM_B0UX11RSS,"������ ����������� ���������� ������ 11","0.0");
NewEEPROM("fEM_B0UX12RSS",1,&fEM_B0UX12RSS,"������ ����������� ���������� ������ 12","0.0");
NewEEPROM("fEM_R0UH02RSS",1,&fEM_R0UH02RSS,"�����. �������������� �������->�����/�  ���15-1","3703.704");
NewEEPROM("fEM_R0UH03RSS",1,&fEM_R0UH03RSS,"�����. �������������� �������->�����/�  ���53�","62500.0");
NewEEPROM("fEM_R4US80RDU",1,&fEM_R4US80RDU,"��������� ���� ������� (��)","20");
NewEEPROM("fEM_R7UI71RIM",1,&fEM_R7UI71RIM,"������� �������� ������������ �� I��  ���� (������ 1)","10000");
NewEEPROM("fEM_R7UI72RIM",1,&fEM_R7UI72RIM,"������� �������� ������������ �� I��  ���� (������ 2)","10000");
NewEEPROM("fEM_R7UI73RIM",1,&fEM_R7UI73RIM,"������� �������� ������������ �� II ��  ����","5000");
NewEEPROM("fEM_A1UP01RIM",1,&fEM_A1UP01RIM,"������� �������� �� ����� �� (���)","0.76");
NewEEPROM("fEM_A2UP01RIM",1,&fEM_A2UP01RIM,"������� �������� �� ����� ��","0.245");
NewEEPROM("fEM_A0UP02RIM",1,&fEM_A0UP02RIM,"������� �������� � ��1,2","2.9");
NewEEPROM("fEM_A3UP01RIM",1,&fEM_A3UP01RIM,"������� �������� �� ����� ��","0.13");
NewEEPROM("fEM_A1UP82RIM",1,&fEM_A1UP82RIM,"������ ������� ������������ �������� ����� �� (���)","0.73");
NewEEPROM("fEM_A3UP02RDU",1,&fEM_A3UP02RDU,"������� �������� ������� ��","0.41");
NewEEPROM("fEM_A1UV02RIM",1,&fEM_A1UV02RIM,"��������� ������ �� �� ���������� - g (��/�^2)","9807.0");
NewEEPROM("fEM_A3UV02RIM",1,&fEM_A3UV02RIM,"��������� ������ �� �� ���������� - g (��/�^2)","22975.0");
NewEEPROM("fEM_A2UV02RIM",1,&fEM_A2UV02RIM,"��������� ������ �� �� ���������� - g (��/�^2)","12750.0");
NewEEPROM("fEM_B8US80RDU",1,&fEM_B8US80RDU,"��������� ���� ��2 (��)","20");
NewEEPROM("fEM_A8US80RDU",1,&fEM_A8US80RDU,"��������� ���� ��2 (��)","20");
NewEEPROM("fEM_A6US80RDU",1,&fEM_A6US80RDU,"��������� ���� �� (��)","0");
NewEEPROM("fEM_A1US07RDU",1,&fEM_A1US07RDU,"���������� ������� ��������� �������� ��","5.0");
NewEEPROM("fEM_A2US07RDU",1,&fEM_A2US07RDU,"���������� ������� ��������� �������� ��","5.0");
NewEEPROM("fEM_A3US07RDU",1,&fEM_A3US07RDU,"���������� ������� ��������� �������� ��","5.0");
NewEEPROM("fEM_R7UI75RIM",1,&fEM_R7UI75RIM,"��������� � ������ ��������","100.0");
NewEEPROM("fEM_R0UH21RSS",1,&fEM_R0UH21RSS,"������� ������� ��������� ������� ���������(���/�) ���-11","4000");
NewEEPROM("fEM_R0UH22RSS",1,&fEM_R0UH22RSS,"������� ������� ��������� ������� ���������(���/�) ���-15-1","100000");
NewEEPROM("fEM_R0UH23RSS",1,&fEM_R0UH23RSS,"������� ������� ��������� ������� ���������(���/�) ���-53�","1000000");
NewEEPROM("fEM_R0UR01RSS",1,&fEM_R0UR01RSS,"������� �� �������� �� ���������� ��������������� ������� ��","10.0");
NewEEPROM("fEM_R0UL52RSS",1,&fEM_R0UL52RSS,"������� �� �� ��������","5100");
NewEEPROM("fEM_R0UL41RSS",1,&fEM_R0UL41RSS,"������� �� �� ������� �������","20");
NewEEPROM("fEM_R0UL51RSS",1,&fEM_R0UL51RSS,"������� �� �� ������� �������","13.0");
NewEEPROM("fEM_R0UL42RSS",1,&fEM_R0UL42RSS,"������� �� �� ��������","5000");
NewEEPROM("fEM_R0UH05RSS",1,&fEM_R0UH05RSS,"���-�� �������/��� �� 1 ���� * E^6","32000.0");
NewEEPROM("fEM_R0UN03RSS",1,&fEM_R0UN03RSS,"������ ������� ��������� �������� ��� ��������� ������� (����)","0.005");
NewEEPROM("fEM_A4UL10RIM",1,&fEM_A4UL10RIM,"����� ������� ����������� �� ���","5.0");
NewEEPROM("fEM_A9UL10RIM",1,&fEM_A9UL10RIM,"����� ������� ����������� �� ��1/��2 ���","15.0");
NewEEPROM("fEM_R3UL10RIM",1,&fEM_R3UL10RIM,"����� ������� ���� ���������� ������ (���)","15.0");
NewEEPROM("fEM_R5UL10RIM",1,&fEM_R5UL10RIM,"����� ������� ���� ����� ��������� ���� (���. ��)","20.0");
NewEEPROM("fEM_R6UL10RIM",1,&fEM_R6UL10RIM,"����� ������� ���� ����-����� ���","10.0");
NewEEPROM("lEM_C1AD31LRP",3,&lEM_C1AD31LRP,"����� ����� �� ���","0");
NewEEPROM("lEM_R0IE01LRP",3,&lEM_R0IE01LRP,"���������� ������� ����������","0");
NewEEPROM("lEM_R0IE02LRP",3,&lEM_R0IE02LRP,"��������� ������� ��, ��","0");
NewEEPROM("fEM_A2UP02RIM",1,&fEM_A2UP02RIM,"������� �������� �� ������ ��","0.45");
NewEEPROM("fEM_A2UP03RIM",1,&fEM_A2UP03RIM,"������ ������� �������� �� ���ڨ� ��","0.39");
NewEEPROM("fEM_A0UP01RIM",1,&fEM_A0UP01RIM,"������� �������� � ��1,2","2.74");
NewEEPROM("fEM_A3UP02RIM",1,&fEM_A3UP02RIM,"������ �������  �������� �� ����� ��","0.07");
NewEEPROM("fEM_A4UP01RIM",1,&fEM_A4UP01RIM,"������� �������� �� ������ ��","0.275");
NewEEPROM("fEM_A4UP02RIM",1,&fEM_A4UP02RIM,"������ ������� �������� �� ������ ��","0.245");
NewEEPROM("fEM_R7UI76RIM",1,&fEM_R7UI76RIM,"����� ��������  ������������ �� II �� ��� �������� ������� ���","0.045");
NewEEPROM("fEM_R7UI77RIM",1,&fEM_R7UI77RIM,"����� ��������  ������������ �� 1 �� ��� �������� ������� ���","0.05");
NewEEPROM("iEM_TERBB1",2,&iEM_TERBB1,"�������������  ��1","0");
NewEEPROM("fEM_A1MC02RC1",1,&fEM_A1MC02RC1,"�������� ���������� ����� ��1 �� ��","0");
NewEEPROM("fEM_A1MV02RC1",1,&fEM_A1MV02RC1,"�������� �������� ��������  ����� ��1 �� ��","0");
NewEEPROM("iEM_TERBB2",2,&iEM_TERBB2,"�������������  ��2","0");
NewEEPROM("fEM_B1MC02RC1",1,&fEM_B1MC02RC1,"�������� ���������� ����� ��2 �� ��","0");
NewEEPROM("fEM_B1MV02RC1",1,&fEM_B1MV02RC1,"�������� �������� �������� ����� ��2 �� ��","0");
NewEEPROM("iEM_TERRB2",2,&iEM_TERRB2,"�������������  ��2","0");
NewEEPROM("fEM_B2MC02RC1",1,&fEM_B2MC02RC1,"�������� ���������� ����� ��2 �� ��","0");
NewEEPROM("fEM_B2MV02RC1",1,&fEM_B2MV02RC1,"�������� �������� �������� ����� ��2 �� ��","0");
NewEEPROM("iEM_TERRB1",2,&iEM_TERRB1,"�������������  ��1","0");
NewEEPROM("fEM_A2MC02RC1",1,&fEM_A2MC02RC1,"�������� ���������� ����� ��1 �� ��","0");
NewEEPROM("fEM_A2MV02RC1",1,&fEM_A2MV02RC1,"�������� �������� �������� ����� ��1 �� ��","0");
NewEEPROM("iEM_TERIS2",2,&iEM_TERIS2,"�������������  ��2","0");
NewEEPROM("fEM_B3MC02RC1",1,&fEM_B3MC02RC1,"�������� ���������� ����� ��2 �� ��","0");
NewEEPROM("fEM_B3MV02RC1",1,&fEM_B3MV02RC1,"�������� �������� �������� ����� ��2 �� ��","0");
NewEEPROM("iEM_TERIS1",2,&iEM_TERIS1,"�������������  ��1","0");
NewEEPROM("fEM_A3MC02RC1",1,&fEM_A3MC02RC1,"�������� ���������� ����� ��1 �� ��","0");
NewEEPROM("fEM_A3MV02RC1",1,&fEM_A3MV02RC1,"�������� �������� �������� ����� ��1 �� ��","0");
NewEEPROM("iEM_TERA1IE04LDU",2,&iEM_TERA1IE04LDU,"��������� �������� ��1 ����� (�� ����)","0");
NewEEPROM("iEM_TERA1IE03LDU",2,&iEM_TERA1IE03LDU,"��������� �������� ��1 ����� (�� ����)","0");
NewEEPROM("fEM_A1MC01RC1",1,&fEM_A1MC01RC1,"�������� ����������  ��1 �� ��","0");
NewEEPROM("iEM_TERB1IE03LDU",2,&iEM_TERB1IE03LDU,"��������� �������� ��2 ����� (�� ����)","0");
NewEEPROM("iEM_TERB1IE04LDU",2,&iEM_TERB1IE04LDU,"��������� �������� ��2 ����� (�� ����)","0");
NewEEPROM("fEM_B1MC01RC1",1,&fEM_B1MC01RC1,"�������� ���������� ��2 �� ��","0");
NewEEPROM("fEM_B1MV01RC1",1,&fEM_B1MV01RC1,"�������� �������� �������� ��2 �� ��","0");
NewEEPROM("fEM_B2MC01RC1",1,&fEM_B2MC01RC1,"�������� ���������� ��2 �� ��","0");
NewEEPROM("fEM_B2MV01RC1",1,&fEM_B2MV01RC1,"�������� �������� ��������  ��2 �� ��","0");
NewEEPROM("fEM_A3MC01RC1",1,&fEM_A3MC01RC1,"�������� ���������� ��1 �� ��","0");
NewEEPROM("fEM_A3MV01RC1",1,&fEM_A3MV01RC1,"�������� �������� �������� ��1 �� ��","0");
NewEEPROM("fEM_B3MC01RC1",1,&fEM_B3MC01RC1,"�������� ���������� ��2 �� ��","0");
NewEEPROM("fEM_B3MV01RC1",1,&fEM_B3MV01RC1,"�������� �������� �������� ��2 �� ��","0");
NewEEPROM("iEM_TERA2SS21LIM",2,&iEM_TERA2SS21LIM,"���������: ������ �� �� ��1","0");
NewEEPROM("iEM_TERA2SS12LIM",2,&iEM_TERA2SS12LIM,"���������: ������ ��1 ��������","0");
NewEEPROM("iEM_TERR6SS21LIM",2,&iEM_TERR6SS21LIM,"���������: ����-����� � ��������� ���������","0");
NewEEPROM("iEM_TERA2VP82LIM",2,&iEM_TERA2VP82LIM,"���������: ������� �������� �� ������ ��  � �����","0");
NewEEPROM("iEM_TERA2SS11LIM",2,&iEM_TERA2SS11LIM,"���������: ������ �� �� ��1","0");
NewEEPROM("iEM_TERB3SS21LIM",2,&iEM_TERB3SS21LIM,"���������: ������ �� �� ��2","0");
NewEEPROM("iEM_TERA0MT01RIM",2,&iEM_TERA0MT01RIM,"���������: ������� ����������� A�1","0");
NewEEPROM("iEM_TERB0MT01RIM",2,&iEM_TERB0MT01RIM,"���������: ������� ����������� A�2","0");
NewEEPROM("iEM_TERA2SP01RIM",2,&iEM_TERA2SP01RIM,"���������: ������� �������� ����� ��1","0");
NewEEPROM("iEM_TERB2SP01RIM",2,&iEM_TERB2SP01RIM,"���������: ������� �������� ����� ��2","0");
NewEEPROM("iEM_TERB3SP02RIM",2,&iEM_TERB3SP02RIM,"���������: ������� �������� �� ������� ��2","0");
NewEEPROM("iEM_TERA3SC01RIM",2,&iEM_TERA3SC01RIM,"���������: ���������� ����� ��1","0");
NewEEPROM("iEM_TERA3VP81LIM",2,&iEM_TERA3VP81LIM,"���������: ������� �������� ����� ��  � �����","0");
NewEEPROM("iEM_TERA2SC01RIM",2,&iEM_TERA2SC01RIM,"���������: ���������� ����� ��1","0");
NewEEPROM("iEM_TERA2SS33LIM",2,&iEM_TERA2SS33LIM,"���������: ������ ������� ��1�  ������ (���������)","0");
NewEEPROM("iEM_TERA3SS21LIM",2,&iEM_TERA3SS21LIM,"���������: ������ �� �� ��1","0");
NewEEPROM("iEM_TERA3SS33LIM",2,&iEM_TERA3SS33LIM,"���������: ������ �������� ��1�  ������ (���������)","0");
NewEEPROM("iEM_TERA3SS31LIM",2,&iEM_TERA3SS31LIM,"���������: ������ ������ ��1�  ������ (���������)","0");
NewEEPROM("iEM_TERB3SS31LIM",2,&iEM_TERB3SS31LIM,"���������: ������ ������ ��2�  ������ (���������)","0");
NewEEPROM("iEM_TERB3SS33LIM",2,&iEM_TERB3SS33LIM,"���������: ������ �������� ��2�  ������ (���������)","0");
NewEEPROM("iEM_TERB3SC01RIM",2,&iEM_TERB3SC01RIM,"���������: ���������� ����� ��2","0");
NewEEPROM("iEM_TERA3SS11LIM",2,&iEM_TERA3SS11LIM,"���������: ������ �� �� ��1","0");
NewEEPROM("iEM_TERB3SS11LIM",2,&iEM_TERB3SS11LIM,"���������: ������ �� �� ��2","0");
NewEEPROM("iEM_TERR6IS64LIM",2,&iEM_TERR6IS64LIM,"���������: ����������� ��� ����-35","0");
NewEEPROM("iEM_TERB3SS22LIM",2,&iEM_TERB3SS22LIM,"���������: ������ �� ��� ��2","0");
NewEEPROM("iEM_TERA3SS22LIM",2,&iEM_TERA3SS22LIM,"���������: ������ �� ��� ��1","0");
NewEEPROM("iEM_TERA3SP02RIM",2,&iEM_TERA3SP02RIM,"���������: ������� �������� �� ������� ��1","0");
NewEEPROM("iEM_TERR6IS62LIM",2,&iEM_TERR6IS62LIM,"��������� ����������� ��� ����-39","0");
NewEEPROM("iEM_TERR6IS66LIM",2,&iEM_TERR6IS66LIM,"��������� ����������� ��� 4,0 (�5) ����-1-1","0");
NewEEPROM("iEM_TERR6IS67LIM",2,&iEM_TERR6IS67LIM,"��������� ����������� ��� 4,0 (�6) ����-1-2","0");
NewEEPROM("iEM_TERA0VP81LIM",2,&iEM_TERA0VP81LIM,"���������: ��������  ��1  � �����","0");
NewEEPROM("iEM_TERB0VP81LIM",2,&iEM_TERB0VP81LIM,"���������: ��������  ��2 � �����","0");
NewEEPROM("iEM_TERR0VP81LIM",2,&iEM_TERR0VP81LIM,"���������: ��������  � �������-1 � �����","0");
NewEEPROM("iEM_TERR6IS68LIM",2,&iEM_TERR6IS68LIM,"��������� ����������� ��� 4,0 (�7) ����-2","0");
NewEEPROM("iEM_TERR7SI74RIM",2,&iEM_TERR7SI74RIM,"���������: �������� � ���������� ����","0");
NewEEPROM("iEM_TERA5SS21LIM",2,&iEM_TERA5SS21LIM,"���������: ������ �� �� ��1","0");
NewEEPROM("iEM_TERB5SS11LIM",2,&iEM_TERB5SS11LIM,"���������: ������ �� �� ��2","0");
NewEEPROM("iEM_TERA5SS11LIM",2,&iEM_TERA5SS11LIM,"���������: ��������� ������� ��1 � �������","0");
NewEEPROM("iEM_TERA9SS11LIM",2,&iEM_TERA9SS11LIM,"���������: ������ �� �� �� ��1","0");
NewEEPROM("iEM_TERB2SS11LIM",2,&iEM_TERB2SS11LIM,"���������: ������ �� �� ��2","0");
NewEEPROM("iEM_TERB2SS12LIM",2,&iEM_TERB2SS12LIM,"���������: ������ ��2 ��������","0");
NewEEPROM("iEM_TERB2SS21LIM",2,&iEM_TERB2SS21LIM,"���������: ������ �� �� ��2","0");
NewEEPROM("iEM_TERR3SS11LIM",2,&iEM_TERR3SS11LIM,"���������: ������ �� �� ���������� ������-1","0");
NewEEPROM("iEM_TERB2SC01RIM",2,&iEM_TERB2SC01RIM,"���������: ���������� ����� ��2","0");
NewEEPROM("iEM_TERR3SS21LIM",2,&iEM_TERR3SS21LIM,"���������: ������ �� �� ���������� ������-1","0");
NewEEPROM("iEM_TERR5SS11LIM",2,&iEM_TERR5SS11LIM,"���������: ������ �� �� ����� ��������� ����","0");
NewEEPROM("iEM_TERA4SS11LIM",2,&iEM_TERA4SS11LIM,"���������: ������ �� �� ��1","0");
NewEEPROM("iEM_TERR1SS11LIM",2,&iEM_TERR1SS11LIM,"���������: ������ �� �� ���1","0");
NewEEPROM("iEM_TERR1SS21LIM",2,&iEM_TERR1SS21LIM,"���������: ������ �� �� ���1","0");
NewEEPROM("iEM_TERR2SS11LIM",2,&iEM_TERR2SS11LIM,"���������: ������ �� �� ���2","0");
NewEEPROM("iEM_TERR2SS21LIM",2,&iEM_TERR2SS21LIM,"���������: ������ �� �� ���2","0");
NewEEPROM("iEM_TERA4VP82LIM",2,&iEM_TERA4VP82LIM,"��������� �������� ���ڨ� �� � �����","0");
NewEEPROM("iEM_TERB4SS21LIM",2,&iEM_TERB4SS21LIM,"���������: ������ �� �� ��2","0");
NewEEPROM("iEM_TERR5SS21LIM",2,&iEM_TERR5SS21LIM,"���������: ������ �� �� ����� ��������� ����","0");
NewEEPROM("iEM_TERB6SS21LIM",2,&iEM_TERB6SS21LIM,"���������: ������ �� �� ��2","0");
NewEEPROM("iEM_TERB4SS11LIM",2,&iEM_TERB4SS11LIM,"���������: ������ �� �� ��2","0");
NewEEPROM("iEM_TERA4SS21LIM",2,&iEM_TERA4SS21LIM,"���������: ������ �� �� ��1","0");
NewEEPROM("iEM_TERA6MS11LIM",2,&iEM_TERA6MS11LIM,"���������: ������ �� �� ��1","0");
NewEEPROM("iEM_TERA6SS21LIM",2,&iEM_TERA6SS21LIM,"���������: ������ �� �� ��1","0");
NewEEPROM("iEM_TERB6SS11LIM",2,&iEM_TERB6SS11LIM,"���������: ������ �� �� ��2","0");
NewEEPROM("iEM_TERR4SS11LIM",2,&iEM_TERR4SS11LIM,"���������: ������ �� �� �������","0");
NewEEPROM("iEM_TERR4MS21LIM",2,&iEM_TERR4MS21LIM,"���������: ������ �� �� �������","0");
NewEEPROM("iEM_TERR4SS12LIM",2,&iEM_TERR4SS12LIM,"���������: ������ �� ������������ �� �������","0");
NewEEPROM("iEM_TERR4SS22LIM",2,&iEM_TERR4SS22LIM,"���������: ������ �� ������������ �� �������","0");
NewEEPROM("iEM_TERR8SS11LIM",2,&iEM_TERR8SS11LIM,"���������: ��������� �� ����������","0");
NewEEPROM("iEM_TERB8SC01RIM",2,&iEM_TERB8SC01RIM,"���������: ���������� ��2","0");
NewEEPROM("iEM_TERA8SC01RIM",2,&iEM_TERA8SC01RIM,"���������: ���������� ��2","0");
NewEEPROM("iEM_TERB8SS12LIM",2,&iEM_TERB8SS12LIM,"���������: ������ �� ������������ �� ��2","0");
NewEEPROM("iEM_TERA8SS12LIM",2,&iEM_TERA8SS12LIM,"���������: ������ �� ������������ �� ��2","0");
NewEEPROM("iEM_TERB8SS22LIM",2,&iEM_TERB8SS22LIM,"���������: ������ �� ������������ �� ��2","0");
NewEEPROM("iEM_TERA8SS22LIM",2,&iEM_TERA8SS22LIM,"���������: ������ �� ������������ �� ��2","0");
NewEEPROM("iEM_TERA9SS21LIM",2,&iEM_TERA9SS21LIM,"���������: ������ �� �� �� ��1","0");
NewEEPROM("iEM_TERB9SS21LIM",2,&iEM_TERB9SS21LIM,"���������: ������ �� �� �� ��2","0");
NewEEPROM("iEM_TERB9SS11LIM",2,&iEM_TERB9SS11LIM,"���������: ������ �� �� �� ��2","0");
NewEEPROM("iEM_TERB5SS21LIM",2,&iEM_TERB5SS21LIM,"���������: ������ �� �� ��2","0");
NewEEPROM("iEM_TERA1SS21LIM",2,&iEM_TERA1SS21LIM,"���������: ������ �� �� ��1","0");
NewEEPROM("iEM_TERA1SS11LIM",2,&iEM_TERA1SS11LIM,"���������: ������ �� �� ��1","0");
NewEEPROM("iEM_TERA1SC01RIM",2,&iEM_TERA1SC01RIM,"���������: ���������� ����� ��1","0");
NewEEPROM("iEM_TERA1SS12LIM",2,&iEM_TERA1SS12LIM,"���������: ������ ��1 ��������","0");
NewEEPROM("iEM_TERB1SS21LIM",2,&iEM_TERB1SS21LIM,"���������: ������ �� �� ��2","0");
NewEEPROM("iEM_TERB1SS11LIM",2,&iEM_TERB1SS11LIM,"���������:������ �� �� ��2","0");
NewEEPROM("iEM_TERB1MC01RIM",2,&iEM_TERB1MC01RIM,"���������: ���������� ����� ��2","0");
NewEEPROM("iEM_TERB1SS12LIM",2,&iEM_TERB1SS12LIM,"���������: ������ ��2 ��������","0");
NewEEPROM("iEM_TERR0IE43LIM",2,&iEM_TERR0IE43LIM,"����������� ��� 0,5 4������","0");
NewEEPROM("iEM_TERR0IE41LIM",2,&iEM_TERR0IE41LIM,"����������� ��� 1,6 (�17) ���11 4������","0");
NewEEPROM("lEM_A0EE06LC1",3,&lEM_A0EE06LC1,"����������� ����4 �� ����������� ����������� (�� ��)","1");
NewEEPROM("iEM_TERR0IE33LIM",2,&iEM_TERR0IE33LIM,"���������:����������� ��� 0,5  3������","0");
NewEEPROM("iEM_TERR0IE31LIM",2,&iEM_TERR0IE31LIM,"���������: ����������� ��� 1,6 (�14) ���11 3������","0");
NewEEPROM("lEM_A0EE05LC1",3,&lEM_A0EE05LC1,"����������� ����3 �� ����������� ����������� (�� ��)","1");
NewEEPROM("iEM_TERR0IE11LIM",2,&iEM_TERR0IE11LIM,"���������: ����������� ��� 1,6 (�8) ���11 1������","0");
NewEEPROM("iEM_TERR0IE13LIM",2,&iEM_TERR0IE13LIM,"���������: ����������� ��� 0,5  1������","0");
NewEEPROM("lEM_A0EE03LC1",3,&lEM_A0EE03LC1,"����������� ����1 �� ����������� ����������� (�� ��)","1");
NewEEPROM("iEM_TERR0IE23LIM",2,&iEM_TERR0IE23LIM,"���������: ����������� ��� 0,5 (�13) ���53� 2������","0");
NewEEPROM("iEM_TERR0IE21LIM",2,&iEM_TERR0IE21LIM,"���������: ����������� ��� 1,6 (�11) ���11 2������","0");
NewEEPROM("lEM_A0EE04LC1",3,&lEM_A0EE04LC1,"����������� ����2 �� ����������� ����������� (�� ��)","1");
NewEEPROM("iEM_TERTLG",2,&iEM_TERTLG,"�������������  ������� �� ��","0");
NewEEPROM("fEM_R4MC01RC1",1,&fEM_R4MC01RC1,"�������� ���������� ������� �� ��","0");
NewEEPROM("fEM_R4MV01RC1",1,&fEM_R4MV01RC1,"�������� �������� ������� �� ��","0");
NewEEPROM("iEM_TERMAZ2",2,&iEM_TERMAZ2,"������������� ��2 �� ��","0");
NewEEPROM("fEM_B8MC01RC1",1,&fEM_B8MC01RC1,"������� ���������� ��2 �� ��","0");
NewEEPROM("fEM_B8MV01RC1",1,&fEM_B8MV01RC1,"�������� �������� ��2 �� ��","0");
NewEEPROM("iEM_TERDS2",2,&iEM_TERDS2,"������������� ��2 �� ��","0");
NewEEPROM("fEM_A8MC01RC1",1,&fEM_A8MC01RC1,"�������� ���������� ��2 �� ��","0");
NewEEPROM("fEM_A8MV01RC1",1,&fEM_A8MV01RC1,"�������� �������� ��2 �� ��","0");
NewEEPROM("iEM_TERBZ1",2,&iEM_TERBZ1,"������������� ��1","0");
NewEEPROM("fEM_A6MC01RC1",1,&fEM_A6MC01RC1,"�������� ���������� ��1 �� ��","0");
NewEEPROM("fEM_A6MV01RC1",1,&fEM_A6MV01RC1,"�������� �������� ��1 �� ��","0");
NewEEPROM("iEM_TERBZ2",2,&iEM_TERBZ2,"������������� ��2","0");
NewEEPROM("fEM_B6MC01RC1",1,&fEM_B6MC01RC1,"�������� ���������� ��2 �� ��","0");
NewEEPROM("fEM_B6MV01RC1",1,&fEM_B6MV01RC1,"�������� �������� ��2 �� ��","0");
NewEEPROM("lEM_R3AD10LC1",3,&lEM_R3AD10LC1,"���������� �����-1 ������� �� ��","0");
NewEEPROM("lEM_R3AD20LC1",3,&lEM_R3AD20LC1,"���������� �����-1 ������� �� ��","0");
NewEEPROM("lEM_R6AD10LC1",3,&lEM_R6AD10LC1,"�������� ����-����� �� ��","0");
NewEEPROM("lEM_R5AD10LC1",3,&lEM_R5AD10LC1,"������� ������ ��������� ���� �� ��","1");
NewEEPROM("lEM_R5AD20LC1",3,&lEM_R5AD20LC1,"������� ������ ��������� ���� �� ��","0");
NewEEPROM("iEM_TERMDZ2",2,&iEM_TERMDZ2,"������������� ���2","0");
NewEEPROM("fEM_R2MC01RC1",1,&fEM_R2MC01RC1,"�������� ���������� ���2 �� ��","0");
NewEEPROM("fEM_R2MV01RC1",1,&fEM_R2MV01RC1,"�������� �������� ���2 �� ��","0");
NewEEPROM("iEM_TERMDZ1",2,&iEM_TERMDZ1,"������������� ���1","0");
NewEEPROM("fEM_R1MC01RC1",1,&fEM_R1MC01RC1,"�������� ���������� ���1 �� ��","0");
NewEEPROM("fEM_R1MV01RC1",1,&fEM_R1MV01RC1,"�������� �������� ���1 �� ��","0");
NewEEPROM("iEM_TERNL1",2,&iEM_TERNL1,"������������� ��1","0");
NewEEPROM("fEM_A5MC01RC1",1,&fEM_A5MC01RC1,"�������� ���������� ��1 �� ��","0");
NewEEPROM("fEM_A5MV01RC1",1,&fEM_A5MV01RC1,"�������� �������� ��1 �� ��","0");
NewEEPROM("iEM_TERNL2",2,&iEM_TERNL2,"������������� ��2","0");
NewEEPROM("fEM_B5MC01RC1",1,&fEM_B5MC01RC1,"�������� ���������� ��2 �� ��","0");
NewEEPROM("fEM_B5MV01RC1",1,&fEM_B5MV01RC1,"�������� �������� ��2 �� ��","0");
NewEEPROM("lEM_R8AD10LC1",3,&lEM_R8AD10LC1,"���������� ��������� �� �� ��","1");
NewEEPROM("fEM_A1UC08RIM",1,&fEM_A1UC08RIM,"���� ������������ �� ��(��)","0.01");
NewEEPROM("fEM_A2UC08RIM",1,&fEM_A2UC08RIM,"���� ������������ ��  �� ��","0.01");
NewEEPROM("fEM_A3UC08RIM",1,&fEM_A3UC08RIM,"���� ������������ �� ��(��)","0.01");
NewEEPROM("fEM_R0UL01RSS",1,&fEM_R0UL01RSS,"��� (��) ��������� �������","0.5");
NewEEPROM("fEM_R0UL03RSS",1,&fEM_R0UL03RSS,"���������� ����� �������� ����� ������ (���)","100.0");
NewEEPROM("iEM_TERB2SS33LIM",2,&iEM_TERB2SS33LIM,"���������: ������ ������� ��2�  ������ (���������)","0");
NewEEPROM("iEM_TERA1VP81LIM",2,&iEM_TERA1VP81LIM,"���������: ������� �������� ����� ��1  � �����","0");
NewEEPROM("iEM_TERB1VP81LIM",2,&iEM_TERB1VP81LIM,"���������: ������� �������� ����� ��2  � �����","0");
NewEEPROM("fEM_A0UT03RSP",1,&fEM_A0UT03RSP,"���������  ����������� ��1 ����","25");
NewEEPROM("fEM_A0UR01RSP",1,&fEM_A0UR01RSP,"���������  ������������ ��1","-0.18505518");
NewEEPROM("fEM_A0UR02RSP",1,&fEM_A0UR02RSP,"���������  ����� ��������� ��1","0.0");
NewEEPROM("fEM_B0UT03RSP",1,&fEM_B0UT03RSP,"���������  ����������� ��2 ����","25");
NewEEPROM("fEM_A1MC01RSP",1,&fEM_A1MC01RSP,"��������� ����������  ��1","0");
NewEEPROM("fEM_A1MC02RSP",1,&fEM_A1MC02RSP,"��������� ���������� ����� ��1","0");
NewEEPROM("fEM_A1MV01RSP",1,&fEM_A1MV01RSP,"��������� �������� ��������  ��1","0");
NewEEPROM("fEM_A1MV02RSP",1,&fEM_A1MV02RSP,"��������� �������� ��������  ��1","0");
NewEEPROM("fEM_B1MC01RSP",1,&fEM_B1MC01RSP,"��������� ����������  ��2","0");
NewEEPROM("fEM_B1MV01RSP",1,&fEM_B1MV01RSP,"��������� �������� ��������  ��2","0");
NewEEPROM("fEM_B1MC02RSP",1,&fEM_B1MC02RSP,"��������� ���������� ����� ��2","0");
NewEEPROM("fEM_B1MV02RSP",1,&fEM_B1MV02RSP,"��������� �������� ��������  ��2","0");
NewEEPROM("fEM_A2MC01RC1",1,&fEM_A2MC01RC1,"�������� ���������� ��1 �� ��","0");
NewEEPROM("fEM_A2MV01RC1",1,&fEM_A2MV01RC1,"�������� �������� �������� ��1 �� ��","0");
NewEEPROM("fEM_A2MC01RSP",1,&fEM_A2MC01RSP,"��������� ����������  ��1","0");
NewEEPROM("fEM_A2MV01RSP",1,&fEM_A2MV01RSP,"��������� �������� ��������  ��1","0");
NewEEPROM("fEM_A2MC02RSP",1,&fEM_A2MC02RSP,"��������� ���������� ����� ��1","0");
NewEEPROM("fEM_A2MV02RSP",1,&fEM_A2MV02RSP,"��������� �������� ��������  ��1","0");
NewEEPROM("fEM_B2MC01RSP",1,&fEM_B2MC01RSP,"��������� ����������  ��2","0");
NewEEPROM("fEM_B2MV01RSP",1,&fEM_B2MV01RSP,"��������� �������� ��������  ��2","0");
NewEEPROM("fEM_B2MC02RSP",1,&fEM_B2MC02RSP,"��������� ���������� ����� ��2","0");
NewEEPROM("fEM_B2MV02RSP",1,&fEM_B2MV02RSP,"��������� �������� ��������  ��2","0");
NewEEPROM("fEM_A3MC01RSP",1,&fEM_A3MC01RSP,"��������� ����������  ��1","0");
NewEEPROM("fEM_A3MV01RSP",1,&fEM_A3MV01RSP,"��������� �������� ��������  ��1","0");
NewEEPROM("fEM_A3MC02RSP",1,&fEM_A3MC02RSP,"��������� ���������� ����� ��1","0");
NewEEPROM("fEM_A3MV02RSP",1,&fEM_A3MV02RSP,"��������� �������� ��������  ��1","0");
NewEEPROM("fEM_B3MC01RSP",1,&fEM_B3MC01RSP,"��������� ����������  ��2","0");
NewEEPROM("fEM_B3MV01RSP",1,&fEM_B3MV01RSP,"��������� �������� ��������  ��2","0");
NewEEPROM("fEM_B3MC02RSP",1,&fEM_B3MC02RSP,"��������� ���������� ����� ��2","0");
NewEEPROM("fEM_B3MV02RSP",1,&fEM_B3MV02RSP,"��������� �������� ��������  ��2","0");
NewEEPROM("fEM_B8MC01RSP",1,&fEM_B8MC01RSP,"��������� ���������� ��2","1500");
NewEEPROM("fEM_B8MV01RSP",1,&fEM_B8MV01RSP,"��������� �������� ��2","0");
NewEEPROM("fEM_A8MC01RSP",1,&fEM_A8MC01RSP,"��������� ���������� ��2","1500");
NewEEPROM("fEM_A8MV01RSP",1,&fEM_A8MV01RSP,"��������� �������� ��2","0");
NewEEPROM("fEM_A6MC01RSP",1,&fEM_A6MC01RSP,"��������� ���������� ��1","0");
NewEEPROM("fEM_A6MV01RSP",1,&fEM_A6MV01RSP,"��������� �������� ��1","0");
NewEEPROM("fEM_B6MC01RSP",1,&fEM_B6MC01RSP,"��������� ���������� ��2","0");
NewEEPROM("fEM_B6MV01RSP",1,&fEM_B6MV01RSP,"��������� �������� ��2","0");
NewEEPROM("fEM_R3UC01RSP",1,&fEM_R3UC01RSP,"��������� ���������� ���������� ������","0");
NewEEPROM("fEM_R3UV01RSP",1,&fEM_R3UV01RSP,"��������� �������� ���������� ������","0");
NewEEPROM("fEM_R5UC01RSP",1,&fEM_R5UC01RSP,"��������� ���������� ����� ��������� ����","4000.0");
NewEEPROM("fEM_R5UV01RSP",1,&fEM_R5UV01RSP,"��������� �������� ����� ��������� ����","0");
NewEEPROM("fEM_R6UC01RSP",1,&fEM_R6UC01RSP,"��������� ���������� ����-�����","0");
NewEEPROM("fEM_R6UV01RSP",1,&fEM_R6UV01RSP,"��������� �������� ����-�����","0");
NewEEPROM("fEM_R2MC01RSP",1,&fEM_R2MC01RSP,"��������� ���������� ���2","0");
NewEEPROM("fEM_R2MV01RSP",1,&fEM_R2MV01RSP,"��������� �������� ���2","0");
NewEEPROM("fEM_R1MC01RSP",1,&fEM_R1MC01RSP,"��������� ���������� ���1","0");
NewEEPROM("fEM_R1MV01RSP",1,&fEM_R1MV01RSP,"��������� �������� ���1","0");
NewEEPROM("fEM_A5MC01RSP",1,&fEM_A5MC01RSP,"��������� ���������� ��1","0");
NewEEPROM("fEM_A5MV01RSP",1,&fEM_A5MV01RSP,"��������� �������� ��1","0");
NewEEPROM("fEM_B5MC01RSP",1,&fEM_B5MC01RSP,"��������� ���������� ��2","0");
NewEEPROM("fEM_B5MV01RSP",1,&fEM_B5MV01RSP,"��������� �������� ��2","0");
NewEEPROM("fEM_A9MC01RSP",1,&fEM_A9MC01RSP,"��������� ���������� �� ��1","15.0");
NewEEPROM("fEM_A9MV01RSP",1,&fEM_A9MV01RSP,"��������� �������� �� ��1","0");
NewEEPROM("fEM_B9MC01RSP",1,&fEM_B9MC01RSP,"��������� ���������� �� ��2","15.0");
NewEEPROM("fEM_B9MV01RSP",1,&fEM_B9MV01RSP,"��������� �������� �� ��2","0");
NewEEPROM("fEM_A4MC01RSP",1,&fEM_A4MC01RSP,"��������� ���������� ��1","5.0");
NewEEPROM("fEM_A4MV01RSP",1,&fEM_A4MV01RSP,"��������� �������� ��1","0");
NewEEPROM("fEM_B4MC01RSP",1,&fEM_B4MC01RSP,"��������� ���������� ��2","5.0");
NewEEPROM("fEM_B4MV01RSP",1,&fEM_B4MV01RSP,"��������� �������� ��2","0");
NewEEPROM("fEM_R4MC01RSP",1,&fEM_R4MC01RSP,"��������� ���������� �������","1374");
NewEEPROM("fEM_R4MV01RSP",1,&fEM_R4MV01RSP,"��������� �������� �������","0");
NewEEPROM("fEM_A1MV01RC1",1,&fEM_A1MV01RC1,"�������� �������� ��������  ��1 �� ��","0");
NewEEPROM("iEM_TERB7MS31LIM",2,&iEM_TERB7MS31LIM,"���������: ������ (����� ��2) ������ (���������)","0");
NewEEPROM("iEM_TERA7MS31LIM",2,&iEM_TERA7MS31LIM,"���������:  ������ ������ ��1� ������ (���������)","0");
NewEEPROM("fEM_R7UX03RSS",1,&fEM_R7UX03RSS,"X-���������� ������ R7IN13 ��","1269.0");
NewEEPROM("fEM_R7UY03RSS",1,&fEM_R7UY03RSS,"Y-���������� ������ R7IN13 (��)","256.0");
NewEEPROM("fEM_R7UY00RSS",1,&fEM_R7UY00RSS,"Y-���������� ��1 ��","506.6");
NewEEPROM("iEM_TERA6VS12LIM",2,&iEM_TERA6VS12LIM,"���������: �������� ������� ��1 � �������","0");
NewEEPROM("iEM_TERA6VS22LIM",2,&iEM_TERA6VS22LIM,"���������: �������� ������� ��1 � �������","0");
NewEEPROM("iEM_TERB6VS12LIM",2,&iEM_TERB6VS12LIM,"���������: �������� ������� ��2 � �������","0");
NewEEPROM("iEM_TERB6VS22LIM",2,&iEM_TERB6VS22LIM,"���������: �������� ������� ��2 � �������","0");
NewEEPROM("iEM_TERA5VS22LIM",2,&iEM_TERA5VS22LIM,"���������: �������� ������� ��1 � ��","0");
NewEEPROM("iEM_TERA5VS12LIM",2,&iEM_TERA5VS12LIM,"���������: �������� ������� ��1 � ��","0");
NewEEPROM("iEM_TERB5VS12LIM",2,&iEM_TERB5VS12LIM,"���������: �������� ������� ��2 � ��","0");
NewEEPROM("iEM_TERB5VS22LIM",2,&iEM_TERB5VS22LIM,"���������: �������� ������� ��2 � ��","0");
NewEEPROM("iEM_TERR1VS12LIM",2,&iEM_TERR1VS12LIM,"���������: �������� ���1 � ������� ��","0");
NewEEPROM("iEM_TERR1VS22LIM",2,&iEM_TERR1VS22LIM,"���������: �������� ���1 � ������� ��","0");
NewEEPROM("iEM_TERR2VS12LIM",2,&iEM_TERR2VS12LIM,"���������: �������� ���2 � ������� ��","0");
NewEEPROM("iEM_TERR2VS22LIM",2,&iEM_TERR2VS22LIM,"���������: �������� ���2 � ������� ��","0");
NewEEPROM("iEM_TERR4VS12LDU",2,&iEM_TERR4VS12LDU,"���������: �������� �������� � �� �����ۻ","0");
NewEEPROM("iEM_TERR4VS22LDU",2,&iEM_TERR4VS22LDU,"���������: �������� �������� � �� �����ۻ","0");
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
  fplet(&fEM_A0UX00RSS.f,((float*)(IntEEPROMBuffer+0x12C)));
  fEM_A0UX00RSS.error = 0;
  fplet(&fEM_R7UX01RSS.f,((float*)(IntEEPROMBuffer+0x130)));
  fEM_R7UX01RSS.error = 0;
  fplet(&fEM_R7UX02RSS.f,((float*)(IntEEPROMBuffer+0x134)));
  fEM_R7UX02RSS.error = 0;
  fplet(&fEM_R7UX04RSS.f,((float*)(IntEEPROMBuffer+0x138)));
  fEM_R7UX04RSS.error = 0;
  fplet(&fEM_R7UX05RSS.f,((float*)(IntEEPROMBuffer+0x13C)));
  fEM_R7UX05RSS.error = 0;
  fplet(&fEM_R7UX06RSS.f,((float*)(IntEEPROMBuffer+0x140)));
  fEM_R7UX06RSS.error = 0;
  fplet(&fEM_R7UX07RSS.f,((float*)(IntEEPROMBuffer+0x144)));
  fEM_R7UX07RSS.error = 0;
  fplet(&fEM_R7UX08RSS.f,((float*)(IntEEPROMBuffer+0x148)));
  fEM_R7UX08RSS.error = 0;
  fplet(&fEM_R7UX09RSS.f,((float*)(IntEEPROMBuffer+0x14C)));
  fEM_R7UX09RSS.error = 0;
  fplet(&fEM_R7UY01RSS.f,((float*)(IntEEPROMBuffer+0x150)));
  fEM_R7UY01RSS.error = 0;
  fplet(&fEM_R7UY02RSS.f,((float*)(IntEEPROMBuffer+0x154)));
  fEM_R7UY02RSS.error = 0;
  fplet(&fEM_R7UY04RSS.f,((float*)(IntEEPROMBuffer+0x158)));
  fEM_R7UY04RSS.error = 0;
  fplet(&fEM_R7UY05RSS.f,((float*)(IntEEPROMBuffer+0x15C)));
  fEM_R7UY05RSS.error = 0;
  fplet(&fEM_R7UY06RSS.f,((float*)(IntEEPROMBuffer+0x160)));
  fEM_R7UY06RSS.error = 0;
  fplet(&fEM_R7UY07RSS.f,((float*)(IntEEPROMBuffer+0x164)));
  fEM_R7UY07RSS.error = 0;
  fplet(&fEM_R7UY08RSS.f,((float*)(IntEEPROMBuffer+0x168)));
  fEM_R7UY08RSS.error = 0;
  fplet(&fEM_R7UY09RSS.f,((float*)(IntEEPROMBuffer+0x16C)));
  fEM_R7UY09RSS.error = 0;
  fplet(&fEM_R7UX10RSS.f,((float*)(IntEEPROMBuffer+0x170)));
  fEM_R7UX10RSS.error = 0;
  fplet(&fEM_R7UX11RSS.f,((float*)(IntEEPROMBuffer+0x174)));
  fEM_R7UX11RSS.error = 0;
  fplet(&fEM_R7UX12RSS.f,((float*)(IntEEPROMBuffer+0x178)));
  fEM_R7UX12RSS.error = 0;
  fplet(&fEM_R7UY10RSS.f,((float*)(IntEEPROMBuffer+0x17C)));
  fEM_R7UY10RSS.error = 0;
  fplet(&fEM_R7UY11RSS.f,((float*)(IntEEPROMBuffer+0x180)));
  fEM_R7UY11RSS.error = 0;
  fplet(&fEM_R7UY12RSS.f,((float*)(IntEEPROMBuffer+0x184)));
  fEM_R7UY12RSS.error = 0;
  fplet(&fEM_A0UX01RSS.f,((float*)(IntEEPROMBuffer+0x188)));
  fEM_A0UX01RSS.error = 0;
  fplet(&fEM_A0UX02RSS.f,((float*)(IntEEPROMBuffer+0x18C)));
  fEM_A0UX02RSS.error = 0;
  fplet(&fEM_A0UX03RSS.f,((float*)(IntEEPROMBuffer+0x190)));
  fEM_A0UX03RSS.error = 0;
  fplet(&fEM_A0UX04RSS.f,((float*)(IntEEPROMBuffer+0x194)));
  fEM_A0UX04RSS.error = 0;
  fplet(&fEM_A0UX05RSS.f,((float*)(IntEEPROMBuffer+0x198)));
  fEM_A0UX05RSS.error = 0;
  fplet(&fEM_A0UX06RSS.f,((float*)(IntEEPROMBuffer+0x19C)));
  fEM_A0UX06RSS.error = 0;
  fplet(&fEM_A0UX07RSS.f,((float*)(IntEEPROMBuffer+0x1A0)));
  fEM_A0UX07RSS.error = 0;
  fplet(&fEM_A0UX08RSS.f,((float*)(IntEEPROMBuffer+0x1A4)));
  fEM_A0UX08RSS.error = 0;
  fplet(&fEM_A0UX09RSS.f,((float*)(IntEEPROMBuffer+0x1A8)));
  fEM_A0UX09RSS.error = 0;
  fplet(&fEM_A0UX10RSS.f,((float*)(IntEEPROMBuffer+0x1AC)));
  fEM_A0UX10RSS.error = 0;
  fplet(&fEM_A0UX11RSS.f,((float*)(IntEEPROMBuffer+0x1B0)));
  fEM_A0UX11RSS.error = 0;
  fplet(&fEM_A0UX12RSS.f,((float*)(IntEEPROMBuffer+0x1B4)));
  fEM_A0UX12RSS.error = 0;
  fplet(&fEM_B0UX01RSS.f,((float*)(IntEEPROMBuffer+0x1B8)));
  fEM_B0UX01RSS.error = 0;
  fplet(&fEM_B0UX02RSS.f,((float*)(IntEEPROMBuffer+0x1BC)));
  fEM_B0UX02RSS.error = 0;
  fplet(&fEM_B0UX03RSS.f,((float*)(IntEEPROMBuffer+0x1C0)));
  fEM_B0UX03RSS.error = 0;
  fplet(&fEM_B0UX04RSS.f,((float*)(IntEEPROMBuffer+0x1C4)));
  fEM_B0UX04RSS.error = 0;
  fplet(&fEM_B0UX05RSS.f,((float*)(IntEEPROMBuffer+0x1C8)));
  fEM_B0UX05RSS.error = 0;
  fplet(&fEM_B0UX06RSS.f,((float*)(IntEEPROMBuffer+0x1CC)));
  fEM_B0UX06RSS.error = 0;
  fplet(&fEM_B0UX07RSS.f,((float*)(IntEEPROMBuffer+0x1D0)));
  fEM_B0UX07RSS.error = 0;
  fplet(&fEM_B0UX08RSS.f,((float*)(IntEEPROMBuffer+0x1D4)));
  fEM_B0UX08RSS.error = 0;
  fplet(&fEM_B0UX09RSS.f,((float*)(IntEEPROMBuffer+0x1D8)));
  fEM_B0UX09RSS.error = 0;
  fplet(&fEM_B0UX10RSS.f,((float*)(IntEEPROMBuffer+0x1DC)));
  fEM_B0UX10RSS.error = 0;
  fplet(&fEM_B0UX11RSS.f,((float*)(IntEEPROMBuffer+0x1E0)));
  fEM_B0UX11RSS.error = 0;
  fplet(&fEM_B0UX12RSS.f,((float*)(IntEEPROMBuffer+0x1E4)));
  fEM_B0UX12RSS.error = 0;
  fplet(&fEM_R0UH02RSS.f,((float*)(IntEEPROMBuffer+0x1E8)));
  fEM_R0UH02RSS.error = 0;
  fplet(&fEM_R0UH03RSS.f,((float*)(IntEEPROMBuffer+0x1EC)));
  fEM_R0UH03RSS.error = 0;
  fplet(&fEM_R4US80RDU.f,((float*)(IntEEPROMBuffer+0x1F0)));
  fEM_R4US80RDU.error = 0;
  fplet(&fEM_R7UI71RIM.f,((float*)(IntEEPROMBuffer+0x1F4)));
  fEM_R7UI71RIM.error = 0;
  fplet(&fEM_R7UI72RIM.f,((float*)(IntEEPROMBuffer+0x1F8)));
  fEM_R7UI72RIM.error = 0;
  fplet(&fEM_R7UI73RIM.f,((float*)(IntEEPROMBuffer+0x1FC)));
  fEM_R7UI73RIM.error = 0;
  fplet(&fEM_A1UP01RIM.f,((float*)(IntEEPROMBuffer+0x200)));
  fEM_A1UP01RIM.error = 0;
  fplet(&fEM_A2UP01RIM.f,((float*)(IntEEPROMBuffer+0x204)));
  fEM_A2UP01RIM.error = 0;
  fplet(&fEM_A0UP02RIM.f,((float*)(IntEEPROMBuffer+0x208)));
  fEM_A0UP02RIM.error = 0;
  fplet(&fEM_A3UP01RIM.f,((float*)(IntEEPROMBuffer+0x20C)));
  fEM_A3UP01RIM.error = 0;
  fplet(&fEM_A1UP82RIM.f,((float*)(IntEEPROMBuffer+0x210)));
  fEM_A1UP82RIM.error = 0;
  fplet(&fEM_A3UP02RDU.f,((float*)(IntEEPROMBuffer+0x214)));
  fEM_A3UP02RDU.error = 0;
  fplet(&fEM_A1UV02RIM.f,((float*)(IntEEPROMBuffer+0x218)));
  fEM_A1UV02RIM.error = 0;
  fplet(&fEM_A3UV02RIM.f,((float*)(IntEEPROMBuffer+0x21C)));
  fEM_A3UV02RIM.error = 0;
  fplet(&fEM_A2UV02RIM.f,((float*)(IntEEPROMBuffer+0x220)));
  fEM_A2UV02RIM.error = 0;
  fplet(&fEM_B8US80RDU.f,((float*)(IntEEPROMBuffer+0x224)));
  fEM_B8US80RDU.error = 0;
  fplet(&fEM_A8US80RDU.f,((float*)(IntEEPROMBuffer+0x228)));
  fEM_A8US80RDU.error = 0;
  fplet(&fEM_A6US80RDU.f,((float*)(IntEEPROMBuffer+0x22C)));
  fEM_A6US80RDU.error = 0;
  fplet(&fEM_A1US07RDU.f,((float*)(IntEEPROMBuffer+0x230)));
  fEM_A1US07RDU.error = 0;
  fplet(&fEM_A2US07RDU.f,((float*)(IntEEPROMBuffer+0x234)));
  fEM_A2US07RDU.error = 0;
  fplet(&fEM_A3US07RDU.f,((float*)(IntEEPROMBuffer+0x238)));
  fEM_A3US07RDU.error = 0;
  fplet(&fEM_R7UI75RIM.f,((float*)(IntEEPROMBuffer+0x23C)));
  fEM_R7UI75RIM.error = 0;
  fplet(&fEM_R0UH21RSS.f,((float*)(IntEEPROMBuffer+0x240)));
  fEM_R0UH21RSS.error = 0;
  fplet(&fEM_R0UH22RSS.f,((float*)(IntEEPROMBuffer+0x244)));
  fEM_R0UH22RSS.error = 0;
  fplet(&fEM_R0UH23RSS.f,((float*)(IntEEPROMBuffer+0x248)));
  fEM_R0UH23RSS.error = 0;
  fplet(&fEM_R0UR01RSS.f,((float*)(IntEEPROMBuffer+0x24C)));
  fEM_R0UR01RSS.error = 0;
  fplet(&fEM_R0UL52RSS.f,((float*)(IntEEPROMBuffer+0x250)));
  fEM_R0UL52RSS.error = 0;
  fplet(&fEM_R0UL41RSS.f,((float*)(IntEEPROMBuffer+0x254)));
  fEM_R0UL41RSS.error = 0;
  fplet(&fEM_R0UL51RSS.f,((float*)(IntEEPROMBuffer+0x258)));
  fEM_R0UL51RSS.error = 0;
  fplet(&fEM_R0UL42RSS.f,((float*)(IntEEPROMBuffer+0x25C)));
  fEM_R0UL42RSS.error = 0;
  fplet(&fEM_R0UH05RSS.f,((float*)(IntEEPROMBuffer+0x260)));
  fEM_R0UH05RSS.error = 0;
  fplet(&fEM_R0UN03RSS.f,((float*)(IntEEPROMBuffer+0x264)));
  fEM_R0UN03RSS.error = 0;
  fplet(&fEM_A4UL10RIM.f,((float*)(IntEEPROMBuffer+0x268)));
  fEM_A4UL10RIM.error = 0;
  fplet(&fEM_A9UL10RIM.f,((float*)(IntEEPROMBuffer+0x26C)));
  fEM_A9UL10RIM.error = 0;
  fplet(&fEM_R3UL10RIM.f,((float*)(IntEEPROMBuffer+0x270)));
  fEM_R3UL10RIM.error = 0;
  fplet(&fEM_R5UL10RIM.f,((float*)(IntEEPROMBuffer+0x274)));
  fEM_R5UL10RIM.error = 0;
  fplet(&fEM_R6UL10RIM.f,((float*)(IntEEPROMBuffer+0x278)));
  fEM_R6UL10RIM.error = 0;
  lEM_C1AD31LRP.b = *((uspaint8*)(IntEEPROMBuffer+0x27C));
  lEM_C1AD31LRP.error = 0;
  lEM_R0IE01LRP.b = *((uspaint8*)(IntEEPROMBuffer+0x27D));
  lEM_R0IE01LRP.error = 0;
  lEM_R0IE02LRP.b = *((uspaint8*)(IntEEPROMBuffer+0x27E));
  lEM_R0IE02LRP.error = 0;
  fplet(&fEM_A2UP02RIM.f,((float*)(IntEEPROMBuffer+0x27F)));
  fEM_A2UP02RIM.error = 0;
  fplet(&fEM_A2UP03RIM.f,((float*)(IntEEPROMBuffer+0x283)));
  fEM_A2UP03RIM.error = 0;
  fplet(&fEM_A0UP01RIM.f,((float*)(IntEEPROMBuffer+0x287)));
  fEM_A0UP01RIM.error = 0;
  fplet(&fEM_A3UP02RIM.f,((float*)(IntEEPROMBuffer+0x28B)));
  fEM_A3UP02RIM.error = 0;
  fplet(&fEM_A4UP01RIM.f,((float*)(IntEEPROMBuffer+0x28F)));
  fEM_A4UP01RIM.error = 0;
  fplet(&fEM_A4UP02RIM.f,((float*)(IntEEPROMBuffer+0x293)));
  fEM_A4UP02RIM.error = 0;
  fplet(&fEM_R7UI76RIM.f,((float*)(IntEEPROMBuffer+0x297)));
  fEM_R7UI76RIM.error = 0;
  fplet(&fEM_R7UI77RIM.f,((float*)(IntEEPROMBuffer+0x29B)));
  fEM_R7UI77RIM.error = 0;
  iEM_TERBB1.i = *((__int16*)(IntEEPROMBuffer+0x29F));
  iEM_TERBB1.error = 0;
  fplet(&fEM_A1MC02RC1.f,((float*)(IntEEPROMBuffer+0x2A1)));
  fEM_A1MC02RC1.error = 0;
  fplet(&fEM_A1MV02RC1.f,((float*)(IntEEPROMBuffer+0x2A5)));
  fEM_A1MV02RC1.error = 0;
  iEM_TERBB2.i = *((__int16*)(IntEEPROMBuffer+0x2A9));
  iEM_TERBB2.error = 0;
  fplet(&fEM_B1MC02RC1.f,((float*)(IntEEPROMBuffer+0x2AB)));
  fEM_B1MC02RC1.error = 0;
  fplet(&fEM_B1MV02RC1.f,((float*)(IntEEPROMBuffer+0x2AF)));
  fEM_B1MV02RC1.error = 0;
  iEM_TERRB2.i = *((__int16*)(IntEEPROMBuffer+0x2B3));
  iEM_TERRB2.error = 0;
  fplet(&fEM_B2MC02RC1.f,((float*)(IntEEPROMBuffer+0x2B5)));
  fEM_B2MC02RC1.error = 0;
  fplet(&fEM_B2MV02RC1.f,((float*)(IntEEPROMBuffer+0x2B9)));
  fEM_B2MV02RC1.error = 0;
  iEM_TERRB1.i = *((__int16*)(IntEEPROMBuffer+0x2BD));
  iEM_TERRB1.error = 0;
  fplet(&fEM_A2MC02RC1.f,((float*)(IntEEPROMBuffer+0x2BF)));
  fEM_A2MC02RC1.error = 0;
  fplet(&fEM_A2MV02RC1.f,((float*)(IntEEPROMBuffer+0x2C3)));
  fEM_A2MV02RC1.error = 0;
  iEM_TERIS2.i = *((__int16*)(IntEEPROMBuffer+0x2C7));
  iEM_TERIS2.error = 0;
  fplet(&fEM_B3MC02RC1.f,((float*)(IntEEPROMBuffer+0x2C9)));
  fEM_B3MC02RC1.error = 0;
  fplet(&fEM_B3MV02RC1.f,((float*)(IntEEPROMBuffer+0x2CD)));
  fEM_B3MV02RC1.error = 0;
  iEM_TERIS1.i = *((__int16*)(IntEEPROMBuffer+0x2D1));
  iEM_TERIS1.error = 0;
  fplet(&fEM_A3MC02RC1.f,((float*)(IntEEPROMBuffer+0x2D3)));
  fEM_A3MC02RC1.error = 0;
  fplet(&fEM_A3MV02RC1.f,((float*)(IntEEPROMBuffer+0x2D7)));
  fEM_A3MV02RC1.error = 0;
  iEM_TERA1IE04LDU.i = *((__int16*)(IntEEPROMBuffer+0x2DB));
  iEM_TERA1IE04LDU.error = 0;
  iEM_TERA1IE03LDU.i = *((__int16*)(IntEEPROMBuffer+0x2DD));
  iEM_TERA1IE03LDU.error = 0;
  fplet(&fEM_A1MC01RC1.f,((float*)(IntEEPROMBuffer+0x2DF)));
  fEM_A1MC01RC1.error = 0;
  iEM_TERB1IE03LDU.i = *((__int16*)(IntEEPROMBuffer+0x2E3));
  iEM_TERB1IE03LDU.error = 0;
  iEM_TERB1IE04LDU.i = *((__int16*)(IntEEPROMBuffer+0x2E5));
  iEM_TERB1IE04LDU.error = 0;
  fplet(&fEM_B1MC01RC1.f,((float*)(IntEEPROMBuffer+0x2E7)));
  fEM_B1MC01RC1.error = 0;
  fplet(&fEM_B1MV01RC1.f,((float*)(IntEEPROMBuffer+0x2EB)));
  fEM_B1MV01RC1.error = 0;
  fplet(&fEM_B2MC01RC1.f,((float*)(IntEEPROMBuffer+0x2EF)));
  fEM_B2MC01RC1.error = 0;
  fplet(&fEM_B2MV01RC1.f,((float*)(IntEEPROMBuffer+0x2F3)));
  fEM_B2MV01RC1.error = 0;
  fplet(&fEM_A3MC01RC1.f,((float*)(IntEEPROMBuffer+0x2F7)));
  fEM_A3MC01RC1.error = 0;
  fplet(&fEM_A3MV01RC1.f,((float*)(IntEEPROMBuffer+0x2FB)));
  fEM_A3MV01RC1.error = 0;
  fplet(&fEM_B3MC01RC1.f,((float*)(IntEEPROMBuffer+0x2FF)));
  fEM_B3MC01RC1.error = 0;
  fplet(&fEM_B3MV01RC1.f,((float*)(IntEEPROMBuffer+0x303)));
  fEM_B3MV01RC1.error = 0;
  iEM_TERA2SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x307));
  iEM_TERA2SS21LIM.error = 0;
  iEM_TERA2SS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x309));
  iEM_TERA2SS12LIM.error = 0;
  iEM_TERR6SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x30B));
  iEM_TERR6SS21LIM.error = 0;
  iEM_TERA2VP82LIM.i = *((__int16*)(IntEEPROMBuffer+0x30D));
  iEM_TERA2VP82LIM.error = 0;
  iEM_TERA2SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x30F));
  iEM_TERA2SS11LIM.error = 0;
  iEM_TERB3SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x311));
  iEM_TERB3SS21LIM.error = 0;
  iEM_TERA0MT01RIM.i = *((__int16*)(IntEEPROMBuffer+0x313));
  iEM_TERA0MT01RIM.error = 0;
  iEM_TERB0MT01RIM.i = *((__int16*)(IntEEPROMBuffer+0x315));
  iEM_TERB0MT01RIM.error = 0;
  iEM_TERA2SP01RIM.i = *((__int16*)(IntEEPROMBuffer+0x317));
  iEM_TERA2SP01RIM.error = 0;
  iEM_TERB2SP01RIM.i = *((__int16*)(IntEEPROMBuffer+0x319));
  iEM_TERB2SP01RIM.error = 0;
  iEM_TERB3SP02RIM.i = *((__int16*)(IntEEPROMBuffer+0x31B));
  iEM_TERB3SP02RIM.error = 0;
  iEM_TERA3SC01RIM.i = *((__int16*)(IntEEPROMBuffer+0x31D));
  iEM_TERA3SC01RIM.error = 0;
  iEM_TERA3VP81LIM.i = *((__int16*)(IntEEPROMBuffer+0x31F));
  iEM_TERA3VP81LIM.error = 0;
  iEM_TERA2SC01RIM.i = *((__int16*)(IntEEPROMBuffer+0x321));
  iEM_TERA2SC01RIM.error = 0;
  iEM_TERA2SS33LIM.i = *((__int16*)(IntEEPROMBuffer+0x323));
  iEM_TERA2SS33LIM.error = 0;
  iEM_TERA3SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x325));
  iEM_TERA3SS21LIM.error = 0;
  iEM_TERA3SS33LIM.i = *((__int16*)(IntEEPROMBuffer+0x327));
  iEM_TERA3SS33LIM.error = 0;
  iEM_TERA3SS31LIM.i = *((__int16*)(IntEEPROMBuffer+0x329));
  iEM_TERA3SS31LIM.error = 0;
  iEM_TERB3SS31LIM.i = *((__int16*)(IntEEPROMBuffer+0x32B));
  iEM_TERB3SS31LIM.error = 0;
  iEM_TERB3SS33LIM.i = *((__int16*)(IntEEPROMBuffer+0x32D));
  iEM_TERB3SS33LIM.error = 0;
  iEM_TERB3SC01RIM.i = *((__int16*)(IntEEPROMBuffer+0x32F));
  iEM_TERB3SC01RIM.error = 0;
  iEM_TERA3SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x331));
  iEM_TERA3SS11LIM.error = 0;
  iEM_TERB3SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x333));
  iEM_TERB3SS11LIM.error = 0;
  iEM_TERR6IS64LIM.i = *((__int16*)(IntEEPROMBuffer+0x335));
  iEM_TERR6IS64LIM.error = 0;
  iEM_TERB3SS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x337));
  iEM_TERB3SS22LIM.error = 0;
  iEM_TERA3SS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x339));
  iEM_TERA3SS22LIM.error = 0;
  iEM_TERA3SP02RIM.i = *((__int16*)(IntEEPROMBuffer+0x33B));
  iEM_TERA3SP02RIM.error = 0;
  iEM_TERR6IS62LIM.i = *((__int16*)(IntEEPROMBuffer+0x33D));
  iEM_TERR6IS62LIM.error = 0;
  iEM_TERR6IS66LIM.i = *((__int16*)(IntEEPROMBuffer+0x33F));
  iEM_TERR6IS66LIM.error = 0;
  iEM_TERR6IS67LIM.i = *((__int16*)(IntEEPROMBuffer+0x341));
  iEM_TERR6IS67LIM.error = 0;
  iEM_TERA0VP81LIM.i = *((__int16*)(IntEEPROMBuffer+0x343));
  iEM_TERA0VP81LIM.error = 0;
  iEM_TERB0VP81LIM.i = *((__int16*)(IntEEPROMBuffer+0x345));
  iEM_TERB0VP81LIM.error = 0;
  iEM_TERR0VP81LIM.i = *((__int16*)(IntEEPROMBuffer+0x347));
  iEM_TERR0VP81LIM.error = 0;
  iEM_TERR6IS68LIM.i = *((__int16*)(IntEEPROMBuffer+0x349));
  iEM_TERR6IS68LIM.error = 0;
  iEM_TERR7SI74RIM.i = *((__int16*)(IntEEPROMBuffer+0x34B));
  iEM_TERR7SI74RIM.error = 0;
  iEM_TERA5SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x34D));
  iEM_TERA5SS21LIM.error = 0;
  iEM_TERB5SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x34F));
  iEM_TERB5SS11LIM.error = 0;
  iEM_TERA5SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x351));
  iEM_TERA5SS11LIM.error = 0;
  iEM_TERA9SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x353));
  iEM_TERA9SS11LIM.error = 0;
  iEM_TERB2SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x355));
  iEM_TERB2SS11LIM.error = 0;
  iEM_TERB2SS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x357));
  iEM_TERB2SS12LIM.error = 0;
  iEM_TERB2SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x359));
  iEM_TERB2SS21LIM.error = 0;
  iEM_TERR3SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x35B));
  iEM_TERR3SS11LIM.error = 0;
  iEM_TERB2SC01RIM.i = *((__int16*)(IntEEPROMBuffer+0x35D));
  iEM_TERB2SC01RIM.error = 0;
  iEM_TERR3SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x35F));
  iEM_TERR3SS21LIM.error = 0;
  iEM_TERR5SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x361));
  iEM_TERR5SS11LIM.error = 0;
  iEM_TERA4SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x363));
  iEM_TERA4SS11LIM.error = 0;
  iEM_TERR1SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x365));
  iEM_TERR1SS11LIM.error = 0;
  iEM_TERR1SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x367));
  iEM_TERR1SS21LIM.error = 0;
  iEM_TERR2SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x369));
  iEM_TERR2SS11LIM.error = 0;
  iEM_TERR2SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x36B));
  iEM_TERR2SS21LIM.error = 0;
  iEM_TERA4VP82LIM.i = *((__int16*)(IntEEPROMBuffer+0x36D));
  iEM_TERA4VP82LIM.error = 0;
  iEM_TERB4SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x36F));
  iEM_TERB4SS21LIM.error = 0;
  iEM_TERR5SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x371));
  iEM_TERR5SS21LIM.error = 0;
  iEM_TERB6SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x373));
  iEM_TERB6SS21LIM.error = 0;
  iEM_TERB4SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x375));
  iEM_TERB4SS11LIM.error = 0;
  iEM_TERA4SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x377));
  iEM_TERA4SS21LIM.error = 0;
  iEM_TERA6MS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x379));
  iEM_TERA6MS11LIM.error = 0;
  iEM_TERA6SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x37B));
  iEM_TERA6SS21LIM.error = 0;
  iEM_TERB6SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x37D));
  iEM_TERB6SS11LIM.error = 0;
  iEM_TERR4SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x37F));
  iEM_TERR4SS11LIM.error = 0;
  iEM_TERR4MS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x381));
  iEM_TERR4MS21LIM.error = 0;
  iEM_TERR4SS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x383));
  iEM_TERR4SS12LIM.error = 0;
  iEM_TERR4SS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x385));
  iEM_TERR4SS22LIM.error = 0;
  iEM_TERR8SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x387));
  iEM_TERR8SS11LIM.error = 0;
  iEM_TERB8SC01RIM.i = *((__int16*)(IntEEPROMBuffer+0x389));
  iEM_TERB8SC01RIM.error = 0;
  iEM_TERA8SC01RIM.i = *((__int16*)(IntEEPROMBuffer+0x38B));
  iEM_TERA8SC01RIM.error = 0;
  iEM_TERB8SS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x38D));
  iEM_TERB8SS12LIM.error = 0;
  iEM_TERA8SS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x38F));
  iEM_TERA8SS12LIM.error = 0;
  iEM_TERB8SS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x391));
  iEM_TERB8SS22LIM.error = 0;
  iEM_TERA8SS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x393));
  iEM_TERA8SS22LIM.error = 0;
  iEM_TERA9SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x395));
  iEM_TERA9SS21LIM.error = 0;
  iEM_TERB9SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x397));
  iEM_TERB9SS21LIM.error = 0;
  iEM_TERB9SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x399));
  iEM_TERB9SS11LIM.error = 0;
  iEM_TERB5SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x39B));
  iEM_TERB5SS21LIM.error = 0;
  iEM_TERA1SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x39D));
  iEM_TERA1SS21LIM.error = 0;
  iEM_TERA1SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x39F));
  iEM_TERA1SS11LIM.error = 0;
  iEM_TERA1SC01RIM.i = *((__int16*)(IntEEPROMBuffer+0x3A1));
  iEM_TERA1SC01RIM.error = 0;
  iEM_TERA1SS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x3A3));
  iEM_TERA1SS12LIM.error = 0;
  iEM_TERB1SS21LIM.i = *((__int16*)(IntEEPROMBuffer+0x3A5));
  iEM_TERB1SS21LIM.error = 0;
  iEM_TERB1SS11LIM.i = *((__int16*)(IntEEPROMBuffer+0x3A7));
  iEM_TERB1SS11LIM.error = 0;
  iEM_TERB1MC01RIM.i = *((__int16*)(IntEEPROMBuffer+0x3A9));
  iEM_TERB1MC01RIM.error = 0;
  iEM_TERB1SS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x3AB));
  iEM_TERB1SS12LIM.error = 0;
  iEM_TERR0IE43LIM.i = *((__int16*)(IntEEPROMBuffer+0x3AD));
  iEM_TERR0IE43LIM.error = 0;
  iEM_TERR0IE41LIM.i = *((__int16*)(IntEEPROMBuffer+0x3AF));
  iEM_TERR0IE41LIM.error = 0;
  lEM_A0EE06LC1.b = *((uspaint8*)(IntEEPROMBuffer+0x3B1));
  lEM_A0EE06LC1.error = 0;
  iEM_TERR0IE33LIM.i = *((__int16*)(IntEEPROMBuffer+0x3B2));
  iEM_TERR0IE33LIM.error = 0;
  iEM_TERR0IE31LIM.i = *((__int16*)(IntEEPROMBuffer+0x3B4));
  iEM_TERR0IE31LIM.error = 0;
  lEM_A0EE05LC1.b = *((uspaint8*)(IntEEPROMBuffer+0x3B6));
  lEM_A0EE05LC1.error = 0;
  iEM_TERR0IE11LIM.i = *((__int16*)(IntEEPROMBuffer+0x3B7));
  iEM_TERR0IE11LIM.error = 0;
  iEM_TERR0IE13LIM.i = *((__int16*)(IntEEPROMBuffer+0x3B9));
  iEM_TERR0IE13LIM.error = 0;
  lEM_A0EE03LC1.b = *((uspaint8*)(IntEEPROMBuffer+0x3BB));
  lEM_A0EE03LC1.error = 0;
  iEM_TERR0IE23LIM.i = *((__int16*)(IntEEPROMBuffer+0x3BC));
  iEM_TERR0IE23LIM.error = 0;
  iEM_TERR0IE21LIM.i = *((__int16*)(IntEEPROMBuffer+0x3BE));
  iEM_TERR0IE21LIM.error = 0;
  lEM_A0EE04LC1.b = *((uspaint8*)(IntEEPROMBuffer+0x3C0));
  lEM_A0EE04LC1.error = 0;
  iEM_TERTLG.i = *((__int16*)(IntEEPROMBuffer+0x3C1));
  iEM_TERTLG.error = 0;
  fplet(&fEM_R4MC01RC1.f,((float*)(IntEEPROMBuffer+0x3C3)));
  fEM_R4MC01RC1.error = 0;
  fplet(&fEM_R4MV01RC1.f,((float*)(IntEEPROMBuffer+0x3C7)));
  fEM_R4MV01RC1.error = 0;
  iEM_TERMAZ2.i = *((__int16*)(IntEEPROMBuffer+0x3CB));
  iEM_TERMAZ2.error = 0;
  fplet(&fEM_B8MC01RC1.f,((float*)(IntEEPROMBuffer+0x3CD)));
  fEM_B8MC01RC1.error = 0;
  fplet(&fEM_B8MV01RC1.f,((float*)(IntEEPROMBuffer+0x3D1)));
  fEM_B8MV01RC1.error = 0;
  iEM_TERDS2.i = *((__int16*)(IntEEPROMBuffer+0x3D5));
  iEM_TERDS2.error = 0;
  fplet(&fEM_A8MC01RC1.f,((float*)(IntEEPROMBuffer+0x3D7)));
  fEM_A8MC01RC1.error = 0;
  fplet(&fEM_A8MV01RC1.f,((float*)(IntEEPROMBuffer+0x3DB)));
  fEM_A8MV01RC1.error = 0;
  iEM_TERBZ1.i = *((__int16*)(IntEEPROMBuffer+0x3DF));
  iEM_TERBZ1.error = 0;
  fplet(&fEM_A6MC01RC1.f,((float*)(IntEEPROMBuffer+0x3E1)));
  fEM_A6MC01RC1.error = 0;
  fplet(&fEM_A6MV01RC1.f,((float*)(IntEEPROMBuffer+0x3E5)));
  fEM_A6MV01RC1.error = 0;
  iEM_TERBZ2.i = *((__int16*)(IntEEPROMBuffer+0x3E9));
  iEM_TERBZ2.error = 0;
  fplet(&fEM_B6MC01RC1.f,((float*)(IntEEPROMBuffer+0x3EB)));
  fEM_B6MC01RC1.error = 0;
  fplet(&fEM_B6MV01RC1.f,((float*)(IntEEPROMBuffer+0x3EF)));
  fEM_B6MV01RC1.error = 0;
  lEM_R3AD10LC1.b = *((uspaint8*)(IntEEPROMBuffer+0x3F3));
  lEM_R3AD10LC1.error = 0;
  lEM_R3AD20LC1.b = *((uspaint8*)(IntEEPROMBuffer+0x3F4));
  lEM_R3AD20LC1.error = 0;
  lEM_R6AD10LC1.b = *((uspaint8*)(IntEEPROMBuffer+0x3F5));
  lEM_R6AD10LC1.error = 0;
  lEM_R5AD10LC1.b = *((uspaint8*)(IntEEPROMBuffer+0x3F6));
  lEM_R5AD10LC1.error = 0;
  lEM_R5AD20LC1.b = *((uspaint8*)(IntEEPROMBuffer+0x3F7));
  lEM_R5AD20LC1.error = 0;
  iEM_TERMDZ2.i = *((__int16*)(IntEEPROMBuffer+0x3F8));
  iEM_TERMDZ2.error = 0;
  fplet(&fEM_R2MC01RC1.f,((float*)(IntEEPROMBuffer+0x3FA)));
  fEM_R2MC01RC1.error = 0;
  fplet(&fEM_R2MV01RC1.f,((float*)(IntEEPROMBuffer+0x3FE)));
  fEM_R2MV01RC1.error = 0;
  iEM_TERMDZ1.i = *((__int16*)(IntEEPROMBuffer+0x402));
  iEM_TERMDZ1.error = 0;
  fplet(&fEM_R1MC01RC1.f,((float*)(IntEEPROMBuffer+0x404)));
  fEM_R1MC01RC1.error = 0;
  fplet(&fEM_R1MV01RC1.f,((float*)(IntEEPROMBuffer+0x408)));
  fEM_R1MV01RC1.error = 0;
  iEM_TERNL1.i = *((__int16*)(IntEEPROMBuffer+0x40C));
  iEM_TERNL1.error = 0;
  fplet(&fEM_A5MC01RC1.f,((float*)(IntEEPROMBuffer+0x40E)));
  fEM_A5MC01RC1.error = 0;
  fplet(&fEM_A5MV01RC1.f,((float*)(IntEEPROMBuffer+0x412)));
  fEM_A5MV01RC1.error = 0;
  iEM_TERNL2.i = *((__int16*)(IntEEPROMBuffer+0x416));
  iEM_TERNL2.error = 0;
  fplet(&fEM_B5MC01RC1.f,((float*)(IntEEPROMBuffer+0x418)));
  fEM_B5MC01RC1.error = 0;
  fplet(&fEM_B5MV01RC1.f,((float*)(IntEEPROMBuffer+0x41C)));
  fEM_B5MV01RC1.error = 0;
  lEM_R8AD10LC1.b = *((uspaint8*)(IntEEPROMBuffer+0x420));
  lEM_R8AD10LC1.error = 0;
  fplet(&fEM_A1UC08RIM.f,((float*)(IntEEPROMBuffer+0x421)));
  fEM_A1UC08RIM.error = 0;
  fplet(&fEM_A2UC08RIM.f,((float*)(IntEEPROMBuffer+0x425)));
  fEM_A2UC08RIM.error = 0;
  fplet(&fEM_A3UC08RIM.f,((float*)(IntEEPROMBuffer+0x429)));
  fEM_A3UC08RIM.error = 0;
  fplet(&fEM_R0UL01RSS.f,((float*)(IntEEPROMBuffer+0x42D)));
  fEM_R0UL01RSS.error = 0;
  fplet(&fEM_R0UL03RSS.f,((float*)(IntEEPROMBuffer+0x431)));
  fEM_R0UL03RSS.error = 0;
  iEM_TERB2SS33LIM.i = *((__int16*)(IntEEPROMBuffer+0x435));
  iEM_TERB2SS33LIM.error = 0;
  iEM_TERA1VP81LIM.i = *((__int16*)(IntEEPROMBuffer+0x437));
  iEM_TERA1VP81LIM.error = 0;
  iEM_TERB1VP81LIM.i = *((__int16*)(IntEEPROMBuffer+0x439));
  iEM_TERB1VP81LIM.error = 0;
  fplet(&fEM_A0UT03RSP.f,((float*)(IntEEPROMBuffer+0x43B)));
  fEM_A0UT03RSP.error = 0;
  fplet(&fEM_A0UR01RSP.f,((float*)(IntEEPROMBuffer+0x43F)));
  fEM_A0UR01RSP.error = 0;
  fplet(&fEM_A0UR02RSP.f,((float*)(IntEEPROMBuffer+0x443)));
  fEM_A0UR02RSP.error = 0;
  fplet(&fEM_B0UT03RSP.f,((float*)(IntEEPROMBuffer+0x447)));
  fEM_B0UT03RSP.error = 0;
  fplet(&fEM_A1MC01RSP.f,((float*)(IntEEPROMBuffer+0x44B)));
  fEM_A1MC01RSP.error = 0;
  fplet(&fEM_A1MC02RSP.f,((float*)(IntEEPROMBuffer+0x44F)));
  fEM_A1MC02RSP.error = 0;
  fplet(&fEM_A1MV01RSP.f,((float*)(IntEEPROMBuffer+0x453)));
  fEM_A1MV01RSP.error = 0;
  fplet(&fEM_A1MV02RSP.f,((float*)(IntEEPROMBuffer+0x457)));
  fEM_A1MV02RSP.error = 0;
  fplet(&fEM_B1MC01RSP.f,((float*)(IntEEPROMBuffer+0x45B)));
  fEM_B1MC01RSP.error = 0;
  fplet(&fEM_B1MV01RSP.f,((float*)(IntEEPROMBuffer+0x45F)));
  fEM_B1MV01RSP.error = 0;
  fplet(&fEM_B1MC02RSP.f,((float*)(IntEEPROMBuffer+0x463)));
  fEM_B1MC02RSP.error = 0;
  fplet(&fEM_B1MV02RSP.f,((float*)(IntEEPROMBuffer+0x467)));
  fEM_B1MV02RSP.error = 0;
  fplet(&fEM_A2MC01RC1.f,((float*)(IntEEPROMBuffer+0x46B)));
  fEM_A2MC01RC1.error = 0;
  fplet(&fEM_A2MV01RC1.f,((float*)(IntEEPROMBuffer+0x46F)));
  fEM_A2MV01RC1.error = 0;
  fplet(&fEM_A2MC01RSP.f,((float*)(IntEEPROMBuffer+0x473)));
  fEM_A2MC01RSP.error = 0;
  fplet(&fEM_A2MV01RSP.f,((float*)(IntEEPROMBuffer+0x477)));
  fEM_A2MV01RSP.error = 0;
  fplet(&fEM_A2MC02RSP.f,((float*)(IntEEPROMBuffer+0x47B)));
  fEM_A2MC02RSP.error = 0;
  fplet(&fEM_A2MV02RSP.f,((float*)(IntEEPROMBuffer+0x47F)));
  fEM_A2MV02RSP.error = 0;
  fplet(&fEM_B2MC01RSP.f,((float*)(IntEEPROMBuffer+0x483)));
  fEM_B2MC01RSP.error = 0;
  fplet(&fEM_B2MV01RSP.f,((float*)(IntEEPROMBuffer+0x487)));
  fEM_B2MV01RSP.error = 0;
  fplet(&fEM_B2MC02RSP.f,((float*)(IntEEPROMBuffer+0x48B)));
  fEM_B2MC02RSP.error = 0;
  fplet(&fEM_B2MV02RSP.f,((float*)(IntEEPROMBuffer+0x48F)));
  fEM_B2MV02RSP.error = 0;
  fplet(&fEM_A3MC01RSP.f,((float*)(IntEEPROMBuffer+0x493)));
  fEM_A3MC01RSP.error = 0;
  fplet(&fEM_A3MV01RSP.f,((float*)(IntEEPROMBuffer+0x497)));
  fEM_A3MV01RSP.error = 0;
  fplet(&fEM_A3MC02RSP.f,((float*)(IntEEPROMBuffer+0x49B)));
  fEM_A3MC02RSP.error = 0;
  fplet(&fEM_A3MV02RSP.f,((float*)(IntEEPROMBuffer+0x49F)));
  fEM_A3MV02RSP.error = 0;
  fplet(&fEM_B3MC01RSP.f,((float*)(IntEEPROMBuffer+0x4A3)));
  fEM_B3MC01RSP.error = 0;
  fplet(&fEM_B3MV01RSP.f,((float*)(IntEEPROMBuffer+0x4A7)));
  fEM_B3MV01RSP.error = 0;
  fplet(&fEM_B3MC02RSP.f,((float*)(IntEEPROMBuffer+0x4AB)));
  fEM_B3MC02RSP.error = 0;
  fplet(&fEM_B3MV02RSP.f,((float*)(IntEEPROMBuffer+0x4AF)));
  fEM_B3MV02RSP.error = 0;
  fplet(&fEM_B8MC01RSP.f,((float*)(IntEEPROMBuffer+0x4B3)));
  fEM_B8MC01RSP.error = 0;
  fplet(&fEM_B8MV01RSP.f,((float*)(IntEEPROMBuffer+0x4B7)));
  fEM_B8MV01RSP.error = 0;
  fplet(&fEM_A8MC01RSP.f,((float*)(IntEEPROMBuffer+0x4BB)));
  fEM_A8MC01RSP.error = 0;
  fplet(&fEM_A8MV01RSP.f,((float*)(IntEEPROMBuffer+0x4BF)));
  fEM_A8MV01RSP.error = 0;
  fplet(&fEM_A6MC01RSP.f,((float*)(IntEEPROMBuffer+0x4C3)));
  fEM_A6MC01RSP.error = 0;
  fplet(&fEM_A6MV01RSP.f,((float*)(IntEEPROMBuffer+0x4C7)));
  fEM_A6MV01RSP.error = 0;
  fplet(&fEM_B6MC01RSP.f,((float*)(IntEEPROMBuffer+0x4CB)));
  fEM_B6MC01RSP.error = 0;
  fplet(&fEM_B6MV01RSP.f,((float*)(IntEEPROMBuffer+0x4CF)));
  fEM_B6MV01RSP.error = 0;
  fplet(&fEM_R3UC01RSP.f,((float*)(IntEEPROMBuffer+0x4D3)));
  fEM_R3UC01RSP.error = 0;
  fplet(&fEM_R3UV01RSP.f,((float*)(IntEEPROMBuffer+0x4D7)));
  fEM_R3UV01RSP.error = 0;
  fplet(&fEM_R5UC01RSP.f,((float*)(IntEEPROMBuffer+0x4DB)));
  fEM_R5UC01RSP.error = 0;
  fplet(&fEM_R5UV01RSP.f,((float*)(IntEEPROMBuffer+0x4DF)));
  fEM_R5UV01RSP.error = 0;
  fplet(&fEM_R6UC01RSP.f,((float*)(IntEEPROMBuffer+0x4E3)));
  fEM_R6UC01RSP.error = 0;
  fplet(&fEM_R6UV01RSP.f,((float*)(IntEEPROMBuffer+0x4E7)));
  fEM_R6UV01RSP.error = 0;
  fplet(&fEM_R2MC01RSP.f,((float*)(IntEEPROMBuffer+0x4EB)));
  fEM_R2MC01RSP.error = 0;
  fplet(&fEM_R2MV01RSP.f,((float*)(IntEEPROMBuffer+0x4EF)));
  fEM_R2MV01RSP.error = 0;
  fplet(&fEM_R1MC01RSP.f,((float*)(IntEEPROMBuffer+0x4F3)));
  fEM_R1MC01RSP.error = 0;
  fplet(&fEM_R1MV01RSP.f,((float*)(IntEEPROMBuffer+0x4F7)));
  fEM_R1MV01RSP.error = 0;
  fplet(&fEM_A5MC01RSP.f,((float*)(IntEEPROMBuffer+0x4FB)));
  fEM_A5MC01RSP.error = 0;
  fplet(&fEM_A5MV01RSP.f,((float*)(IntEEPROMBuffer+0x4FF)));
  fEM_A5MV01RSP.error = 0;
  fplet(&fEM_B5MC01RSP.f,((float*)(IntEEPROMBuffer+0x503)));
  fEM_B5MC01RSP.error = 0;
  fplet(&fEM_B5MV01RSP.f,((float*)(IntEEPROMBuffer+0x507)));
  fEM_B5MV01RSP.error = 0;
  fplet(&fEM_A9MC01RSP.f,((float*)(IntEEPROMBuffer+0x50B)));
  fEM_A9MC01RSP.error = 0;
  fplet(&fEM_A9MV01RSP.f,((float*)(IntEEPROMBuffer+0x50F)));
  fEM_A9MV01RSP.error = 0;
  fplet(&fEM_B9MC01RSP.f,((float*)(IntEEPROMBuffer+0x513)));
  fEM_B9MC01RSP.error = 0;
  fplet(&fEM_B9MV01RSP.f,((float*)(IntEEPROMBuffer+0x517)));
  fEM_B9MV01RSP.error = 0;
  fplet(&fEM_A4MC01RSP.f,((float*)(IntEEPROMBuffer+0x51B)));
  fEM_A4MC01RSP.error = 0;
  fplet(&fEM_A4MV01RSP.f,((float*)(IntEEPROMBuffer+0x51F)));
  fEM_A4MV01RSP.error = 0;
  fplet(&fEM_B4MC01RSP.f,((float*)(IntEEPROMBuffer+0x523)));
  fEM_B4MC01RSP.error = 0;
  fplet(&fEM_B4MV01RSP.f,((float*)(IntEEPROMBuffer+0x527)));
  fEM_B4MV01RSP.error = 0;
  fplet(&fEM_R4MC01RSP.f,((float*)(IntEEPROMBuffer+0x52B)));
  fEM_R4MC01RSP.error = 0;
  fplet(&fEM_R4MV01RSP.f,((float*)(IntEEPROMBuffer+0x52F)));
  fEM_R4MV01RSP.error = 0;
  fplet(&fEM_A1MV01RC1.f,((float*)(IntEEPROMBuffer+0x533)));
  fEM_A1MV01RC1.error = 0;
  iEM_TERB7MS31LIM.i = *((__int16*)(IntEEPROMBuffer+0x537));
  iEM_TERB7MS31LIM.error = 0;
  iEM_TERA7MS31LIM.i = *((__int16*)(IntEEPROMBuffer+0x539));
  iEM_TERA7MS31LIM.error = 0;
  fplet(&fEM_R7UX03RSS.f,((float*)(IntEEPROMBuffer+0x53B)));
  fEM_R7UX03RSS.error = 0;
  fplet(&fEM_R7UY03RSS.f,((float*)(IntEEPROMBuffer+0x53F)));
  fEM_R7UY03RSS.error = 0;
  fplet(&fEM_R7UY00RSS.f,((float*)(IntEEPROMBuffer+0x543)));
  fEM_R7UY00RSS.error = 0;
  iEM_TERA6VS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x547));
  iEM_TERA6VS12LIM.error = 0;
  iEM_TERA6VS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x549));
  iEM_TERA6VS22LIM.error = 0;
  iEM_TERB6VS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x54B));
  iEM_TERB6VS12LIM.error = 0;
  iEM_TERB6VS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x54D));
  iEM_TERB6VS22LIM.error = 0;
  iEM_TERA5VS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x54F));
  iEM_TERA5VS22LIM.error = 0;
  iEM_TERA5VS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x551));
  iEM_TERA5VS12LIM.error = 0;
  iEM_TERB5VS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x553));
  iEM_TERB5VS12LIM.error = 0;
  iEM_TERB5VS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x555));
  iEM_TERB5VS22LIM.error = 0;
  iEM_TERR1VS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x557));
  iEM_TERR1VS12LIM.error = 0;
  iEM_TERR1VS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x559));
  iEM_TERR1VS22LIM.error = 0;
  iEM_TERR2VS12LIM.i = *((__int16*)(IntEEPROMBuffer+0x55B));
  iEM_TERR2VS12LIM.error = 0;
  iEM_TERR2VS22LIM.i = *((__int16*)(IntEEPROMBuffer+0x55D));
  iEM_TERR2VS22LIM.error = 0;
  iEM_TERR4VS12LDU.i = *((__int16*)(IntEEPROMBuffer+0x55F));
  iEM_TERR4VS12LDU.error = 0;
  iEM_TERR4VS22LDU.i = *((__int16*)(IntEEPROMBuffer+0x561));
  iEM_TERR4VS22LDU.error = 0;
}
#endif
}

#ifndef SIMUL_MODE
unsigned int EndIntEEPROMAddress = 1379;
#endif

void reInit_Signals(void)
{
  S_zpfs_642_1.x = &signal_R0AD14LDU;
  S_zpfs_630_1.x = &signal_R0AD16LDU;
  S_or2_1199_1.x1 = &signal_R0EE04LZ1;
  S_or2_1199_1.x2 = &signal_R0EE04LZ2;
  S_or2_1194_1.x1 = &signal_R0EE03LZ1;
  S_or2_1194_1.x2 = &signal_R0EE03LZ2;
  S_or2_1188_1.x1 = &signal_R0EE02LZ1;
  S_or2_1188_1.x2 = &signal_R0EE02LZ2;
  S_or2_1183_1.x1 = &signal_R0EE01LZ1;
  S_or2_1183_1.x2 = &signal_R0EE01LZ2;
  S_twobool_206_1.S = &signal_B1AD21LDU;
  S_twobool_224_1.S = &signal_B1AD11LDU;
  S_twobool_41_1.S = &signal_A1AD21LDU;
  S_twobool_56_1.S = &signal_A1AD11LDU;
  S_twobool_701_1.S = &signal_R0MW13LP2;
  S_twobool_685_1.S = &signal_R0MW13LP2;
  S_twobool_665_1.S = &signal_R0MW13LP2;
  S_twobool_684_1.S = &signal_R0MW13LP2;
  S_twobool_664_1.S = &signal_R0MW13LP2;
  S_noto_513_1.x = &signal_B3AD34LDU;
  S_noto_511_1.x = &signal_A3AD34LDU;
  S_ovb1_195_1.x = &signal_R8AD21LDU;
  S_ovb1_25_1.x = &signal_R8AD21LDU;
  S_noto_615_1.x = &signal_A4AD10LDU;
  S_asmot_621_1.RA1 = &signal_A4AD10LDU;
  S_noto_613_1.x = &signal_B4AD10LDU;
  S_asmot_618_1.RA1 = &signal_B4AD10LDU;
  S_noto_602_1.x = &signal_A9AD10LDU;
  S_asmot_604_1.RA1 = &signal_A9AD10LDU;
  S_noto_601_1.x = &signal_B9AD10LDU;
  S_asmot_603_1.RA1 = &signal_B9AD10LDU;
  S_noto_254_1.x = &signal_C2MD31LP1;
  S_noto_214_1.x = &signal_C1MD31LP2;
  S_noto_213_1.x = &signal_C1MD31LP1;
  S_noto_46_1.x = &signal_C1MD31LP2;
  S_noto_45_1.x = &signal_C1MD31LP1;
  S_noto_86_1.x = &signal_C2MD31LP1;
  S_asmot_590_1.RA0 = &signal_B5AD10LDU;
  S_asmot_590_1.RA1 = &signal_B5AD20LDU;
  S_asmot_575_1.RA0 = &signal_A5AD10LDU;
  S_asmot_575_1.RA1 = &signal_A5AD20LDU;
  S_asmot_461_1.RA0 = &signal_R2AD10LDU;
  S_asmot_461_1.RA1 = &signal_R2AD20LDU;
  S_asmot_446_1.RA0 = &signal_R1AD10LDU;
  S_asmot_446_1.RA1 = &signal_R1AD20LDU;
  S_asmot_502_1.RA0 = &signal_B6AD10LDU;
  S_asmot_502_1.RA1 = &signal_B6AD20LDU;
  S_asmot_397_1.RA0 = &signal_A6AD10LDU;
  S_asmot_397_1.RA1 = &signal_A6AD20LDU;
  S_asmot_381_1.RA0 = &signal_A8AD20LDU;
  S_asmot_381_1.RA1 = &signal_A8AD10LDU;
  S_asmot_364_1.RA0 = &signal_B8AD20LDU;
  S_asmot_364_1.RA1 = &signal_B8AD10LDU;
  S_asmot_1167_1.RA0 = &signal_R4AD10LDU;
  S_asmot_1167_1.RA1 = &signal_R4AD20LDU;
  S_azbars_180_1.BlowOut = &signal_B7AP31LDU;
  S_orrsim_301_1.RA0 = &signal_B3AD11LDU;
  S_orrsim_301_1.RA1 = &signal_B3AD21LDU;
  S_orrsim_301_1.RA2 = &signal_B3AD02LDU;
  S_orrsim_301_1.RA3 = &signal_B3AD01LDU;
  S_orrsim_301_1.RA4 = &signal_B3AD03LDU;
  S_orrsim_301_1.RA5 = &signal_B3AD04LDU;
  S_orrsim_301_1.RB3 = &signal_B3AD05LDU;
  S_orrsim_301_1.Klz = &signal_B3AD33LDU;
  S_orrsim_130_1.RA0 = &signal_A3AD11LDU;
  S_orrsim_130_1.RA1 = &signal_A3AD21LDU;
  S_orrsim_130_1.RA2 = &signal_A3AD02LDU;
  S_orrsim_130_1.RA3 = &signal_A3AD01LDU;
  S_orrsim_130_1.RA4 = &signal_A3AD03LDU;
  S_orrsim_130_1.RA5 = &signal_A3AD04LDU;
  S_orrsim_130_1.RB3 = &signal_A3AD05LDU;
  S_orrsim_130_1.Klz = &signal_A3AD33LDU;
  S_orrsim_265_1.RA0 = &signal_B2AD11LDU;
  S_orrsim_265_1.RA1 = &signal_B2AD21LDU;
  S_orrsim_265_1.RA2 = &signal_B2AD02LDU;
  S_orrsim_265_1.RA3 = &signal_B2AD01LDU;
  S_orrsim_265_1.RA4 = &signal_B2AD03LDU;
  S_orrsim_265_1.RA5 = &signal_B2AD04LDU;
  S_orrsim_265_1.RB3 = &signal_B2AD05LDU;
  S_orrsim_265_1.Klz = &signal_B2AD33LDU;
  S_orrsim_97_1.RA0 = &signal_A2AD11LDU;
  S_orrsim_97_1.RA1 = &signal_A2AD21LDU;
  S_orrsim_97_1.RA2 = &signal_A2AD02LDU;
  S_orrsim_97_1.RA3 = &signal_A2AD01LDU;
  S_orrsim_97_1.RA4 = &signal_A2AD03LDU;
  S_orrsim_97_1.RA5 = &signal_A2AD04LDU;
  S_orrsim_97_1.RB3 = &signal_A2AD05LDU;
  S_orrsim_97_1.Klz = &signal_A2AD33LDU;
  S_orrsim_227_1.RA0 = &signal_B1AD11LDU;
  S_orrsim_227_1.RA1 = &signal_B1AD21LDU;
  S_orrsim_227_1.RA2 = &signal_B1AD02LDU;
  S_orrsim_227_1.RA3 = &signal_B1AD01LDU;
  S_orrsim_227_1.RA4 = &signal_B1AD03LDU;
  S_orrsim_227_1.RA5 = &signal_B1AD04LDU;
  S_orrsim_227_1.RB3 = &signal_B1AD05LDU;
  S_orrsim_59_1.RA0 = &signal_A1AD11LDU;
  S_orrsim_59_1.RA1 = &signal_A1AD21LDU;
  S_orrsim_59_1.RA2 = &signal_A1AD02LDU;
  S_orrsim_59_1.RA3 = &signal_A1AD01LDU;
  S_orrsim_59_1.RA4 = &signal_A1AD03LDU;
  S_orrsim_59_1.RA5 = &signal_A1AD04LDU;
  S_orrsim_59_1.RB3 = &signal_A1AD05LDU;
  S_azbars_14_1.BlowOut = &signal_A7AP31LDU;
  array_m355_x_1[15] = &signal_R0MW13LP2;
  array_m1176_x_1[1] = &signal_R0MW13LP2;
  array_m1197_x_1[1] = &signal_R0MW13LP2;
  array_m1192_x_1[1] = &signal_R0MW13LP2;
  array_m1186_x_1[1] = &signal_R0MW13LP2;
  array_m639_x_1[1] = &signal_R0VZ71LZ1;
  array_m639_x_1[2] = &signal_R0VZ71LZ2;
  array_m1181_x_1[1] = &signal_R0MW13LP2;
  array_m290_x_1[1] = &signal_B3AD31LDU;
  array_m255_x_1[0] = &signal_B2AD31LDU;
  array_m256_x_1[0] = &signal_B2AD32LDU;
  array_m216_x_1[0] = &signal_B1AD32LDU;
  array_m215_x_1[1] = &signal_B1AD31LDU;
  array_m121_x_1[0] = &signal_A3AD31LDU;
  array_m48_x_1[0] = &signal_A1AD32LDU;
  array_m47_x_1[1] = &signal_A1AD31LDU;
  array_m87_x_1[0] = &signal_A2AD31LDU;
  array_m88_x_1[0] = &signal_A2AD32LDU;
}

void InitInternalParametr(void)
{
  int i;
  S_twobool_1118_1.Out10 = &internal1_m1118_Out10;
  S_twobool_1118_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1117_1.Out10 = &internal1_m1117_Out10;
  S_twobool_1117_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_943_1.Out10 = &internal1_m943_Out10;
  S_twobool_943_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_942_1.Out10 = &internal1_m942_Out10;
  S_twobool_942_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_941_1.Out10 = &internal1_m941_Out10;
  S_twobool_941_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_940_1.Out10 = &internal1_m940_Out10;
  S_twobool_940_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_691_1.Out10 = &internal1_m691_Out10;
  S_twobool_691_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_690_1.Out10 = &internal1_m690_Out10;
  S_twobool_690_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_669_1.Out10 = &internal1_m669_Out10;
  S_twobool_669_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_668_1.Out10 = &internal1_m668_Out10;
  S_twobool_668_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_689_1.Out10 = &internal1_m689_Out10;
  S_twobool_689_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_688_1.Out10 = &internal1_m688_Out10;
  S_twobool_688_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_667_1.Out10 = &internal1_m667_Out10;
  S_twobool_667_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_666_1.Out10 = &internal1_m666_Out10;
  S_twobool_666_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_527_1.Out10 = &internal1_m527_Out10;
  S_twobool_527_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_545_1.Out10 = &internal1_m545_Out10;
  S_twobool_545_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_409_1.Out10 = &internal1_m409_Out10;
  S_twobool_409_1.FirstEnterFlag = &bFirstEnterFlag;
  S_rs_486_1.q0 = &internal1_m486_q0;
  S_rs_487_1.q0 = &internal1_m487_q0;
  S_rs_472_1.q0 = &internal1_m472_q0;
  S_rs_473_1.q0 = &internal1_m473_q0;
  S_zpfs_642_1.tx = &internal1_m642_tx;
  S_zpfs_642_1.y0 = &internal1_m642_y0;
  S_zpfs_630_1.tx = &internal1_m630_tx;
  S_zpfs_630_1.y0 = &internal1_m630_y0;
  S_zpfs_616_1.tx = &internal1_m616_tx;
  S_zpfs_616_1.y0 = &internal1_m616_y0;
  S_zpfs_614_1.tx = &internal1_m614_tx;
  S_zpfs_614_1.y0 = &internal1_m614_y0;
  S_twobool_206_1.Out10 = &internal1_m206_Out10;
  S_twobool_206_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_224_1.Out10 = &internal1_m224_Out10;
  S_twobool_224_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_41_1.Out10 = &internal1_m41_Out10;
  S_twobool_41_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_56_1.Out10 = &internal1_m56_Out10;
  S_twobool_56_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1241_1.Out10 = &internal1_m1241_Out10;
  S_twobool_1241_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1238_1.Out10 = &internal1_m1238_Out10;
  S_twobool_1238_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1237_1.Out10 = &internal1_m1237_Out10;
  S_twobool_1237_1.FirstEnterFlag = &bFirstEnterFlag;
  S_ktoenc_1240_1.Xtek0 = &internal1_m1240_Xtek0;
  S_ktoenc_1240_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_1235_1.FirstEnterFlag = &bFirstEnterFlag;
  S_ktoenc_1226_1.Xtek0 = &internal1_m1226_Xtek0;
  S_ktoenc_1226_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_1221_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1227_1.Out10 = &internal1_m1227_Out10;
  S_twobool_1227_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1224_1.Out10 = &internal1_m1224_Out10;
  S_twobool_1224_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1223_1.Out10 = &internal1_m1223_Out10;
  S_twobool_1223_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_981_1.Out10 = &internal1_m981_Out10;
  S_twobool_981_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_962_1.Out10 = &internal1_m962_Out10;
  S_twobool_962_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_961_1.Out10 = &internal1_m961_Out10;
  S_twobool_961_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_960_1.Out10 = &internal1_m960_Out10;
  S_twobool_960_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1139_1.Out10 = &internal1_m1139_Out10;
  S_twobool_1139_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1141_1.Out10 = &internal1_m1141_Out10;
  S_twobool_1141_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1138_1.Out10 = &internal1_m1138_Out10;
  S_twobool_1138_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1140_1.Out10 = &internal1_m1140_Out10;
  S_twobool_1140_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1114_1.Out10 = &internal1_m1114_Out10;
  S_twobool_1114_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1115_1.Out10 = &internal1_m1115_Out10;
  S_twobool_1115_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1113_1.Out10 = &internal1_m1113_Out10;
  S_twobool_1113_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1112_1.Out10 = &internal1_m1112_Out10;
  S_twobool_1112_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_976_1.Out10 = &internal1_m976_Out10;
  S_twobool_976_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_928_1.Out10 = &internal1_m928_Out10;
  S_twobool_928_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_927_1.Out10 = &internal1_m927_Out10;
  S_twobool_927_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_926_1.Out10 = &internal1_m926_Out10;
  S_twobool_926_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_925_1.Out10 = &internal1_m925_Out10;
  S_twobool_925_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_977_1.Out10 = &internal1_m977_Out10;
  S_twobool_977_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_958_1.Out10 = &internal1_m958_Out10;
  S_twobool_958_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1116_1.Out10 = &internal1_m1116_Out10;
  S_twobool_1116_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_959_1.Out10 = &internal1_m959_Out10;
  S_twobool_959_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_957_1.Out10 = &internal1_m957_Out10;
  S_twobool_957_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_978_1.Out10 = &internal1_m978_Out10;
  S_twobool_978_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_956_1.Out10 = &internal1_m956_Out10;
  S_twobool_956_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_939_1.Out10 = &internal1_m939_Out10;
  S_twobool_939_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_924_1.Out10 = &internal1_m924_Out10;
  S_twobool_924_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_543_1.Out10 = &internal1_m543_Out10;
  S_twobool_543_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_544_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_550_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_541_1.FirstEnterFlag = &bFirstEnterFlag;
  S_ktoenc_419_1.Xtek0 = &internal1_m419_Xtek0;
  S_ktoenc_419_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_413_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_410_1.Out10 = &internal1_m410_Out10;
  S_twobool_410_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_412_1.Out10 = &internal1_m412_Out10;
  S_twobool_412_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_411_1.Out10 = &internal1_m411_Out10;
  S_twobool_411_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1154_1.Out10 = &internal1_m1154_Out10;
  S_twobool_1154_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1155_1.Out10 = &internal1_m1155_Out10;
  S_twobool_1155_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1153_1.Out10 = &internal1_m1153_Out10;
  S_twobool_1153_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_980_1.Out10 = &internal1_m980_Out10;
  S_twobool_980_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_704_1.Out10 = &internal1_m704_Out10;
  S_twobool_704_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_705_1.Out10 = &internal1_m705_Out10;
  S_twobool_705_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_702_1.Out10 = &internal1_m702_Out10;
  S_twobool_702_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_703_1.Out10 = &internal1_m703_Out10;
  S_twobool_703_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_656_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_561_1.Out10 = &internal1_m561_Out10;
  S_twobool_561_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_560_1.Out10 = &internal1_m560_Out10;
  S_twobool_560_1.FirstEnterFlag = &bFirstEnterFlag;
  S_ktoenc_1135_1.Xtek0 = &internal1_m1135_Xtek0;
  S_ktoenc_1135_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_1127_1.FirstEnterFlag = &bFirstEnterFlag;
  S_ktoenc_1137_1.Xtek0 = &internal1_m1137_Xtek0;
  S_ktoenc_1137_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_1129_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_701_1.Out10 = &internal1_m701_Out10;
  S_twobool_701_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_685_1.Out10 = &internal1_m685_Out10;
  S_twobool_685_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_665_1.Out10 = &internal1_m665_Out10;
  S_twobool_665_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_684_1.Out10 = &internal1_m684_Out10;
  S_twobool_684_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_664_1.Out10 = &internal1_m664_Out10;
  S_twobool_664_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_337_1.Out10 = &internal1_m337_Out10;
  S_twobool_337_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_336_1.Out10 = &internal1_m336_Out10;
  S_twobool_336_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_321_1.Out10 = &internal1_m321_Out10;
  S_twobool_321_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_320_1.Out10 = &internal1_m320_Out10;
  S_twobool_320_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_521_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_515_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_562_1.Out10 = &internal1_m562_Out10;
  S_twobool_562_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_525_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_518_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_350_1.Out10 = &internal1_m350_Out10;
  S_twobool_350_1.FirstEnterFlag = &bFirstEnterFlag;
  S_ktoenc_334_1.Xtek0 = &internal1_m334_Xtek0;
  S_ktoenc_334_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_333_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_349_1.Out10 = &internal1_m349_Out10;
  S_twobool_349_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_347_1.Out10 = &internal1_m347_Out10;
  S_twobool_347_1.FirstEnterFlag = &bFirstEnterFlag;
  S_ktoenc_327_1.Xtek0 = &internal1_m327_Xtek0;
  S_ktoenc_327_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_323_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_348_1.Out10 = &internal1_m348_Out10;
  S_twobool_348_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_549_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_548_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_319_1.Out10 = &internal1_m319_Out10;
  S_twobool_319_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_335_1.Out10 = &internal1_m335_Out10;
  S_twobool_335_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_431_1.Out10 = &internal1_m431_Out10;
  S_twobool_431_1.FirstEnterFlag = &bFirstEnterFlag;
  S_ktoenc_432_1.Xtek0 = &internal1_m432_Xtek0;
  S_ktoenc_432_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_427_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_430_1.Out10 = &internal1_m430_Out10;
  S_twobool_430_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_429_1.Out10 = &internal1_m429_Out10;
  S_twobool_429_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_428_1.Out10 = &internal1_m428_Out10;
  S_twobool_428_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_540_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_163_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_162_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_161_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_156_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_166_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_165_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_979_1.Out10 = &internal1_m979_Out10;
  S_twobool_979_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_150_1.Out10 = &internal1_m150_Out10;
  S_twobool_150_1.FirstEnterFlag = &bFirstEnterFlag;
  S_toao_164_1.FirstEnterFlag = &bFirstEnterFlag;
  S_to3val_158_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_149_1.Out10 = &internal1_m149_Out10;
  S_twobool_149_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1102_1.Out10 = &internal1_m1102_Out10;
  S_twobool_1102_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1093_1.Out10 = &internal1_m1093_Out10;
  S_twobool_1093_1.FirstEnterFlag = &bFirstEnterFlag;
  S_period_1082_1.Period0 = &internal1_m1082_Period0;
  S_period_1082_1.MyFirstEnterFlag = &internal1_m1082_MyFirstEnterFlag;
  S_ocham_1048_1.Nk = &internal1_m1048_Nk;
  S_twobool_1043_1.Out10 = &internal1_m1043_Out10;
  S_twobool_1043_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_1035_1.Out10 = &internal1_m1035_Out10;
  S_twobool_1035_1.FirstEnterFlag = &bFirstEnterFlag;
  S_period_1024_1.Period0 = &internal1_m1024_Period0;
  S_period_1024_1.MyFirstEnterFlag = &internal1_m1024_MyFirstEnterFlag;
  S_ocham_994_1.Nk = &internal1_m994_Nk;
  S_twobool_915_1.Out10 = &internal1_m915_Out10;
  S_twobool_915_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_905_1.Out10 = &internal1_m905_Out10;
  S_twobool_905_1.FirstEnterFlag = &bFirstEnterFlag;
  S_period_896_1.Period0 = &internal1_m896_Period0;
  S_period_896_1.MyFirstEnterFlag = &internal1_m896_MyFirstEnterFlag;
  S_ocham_862_1.Nk = &internal1_m862_Nk;
  S_twobool_849_1.Out10 = &internal1_m849_Out10;
  S_twobool_849_1.FirstEnterFlag = &bFirstEnterFlag;
  S_twobool_838_1.Out10 = &internal1_m838_Out10;
  S_twobool_838_1.FirstEnterFlag = &bFirstEnterFlag;
  S_period_841_1.Period0 = &internal1_m841_Period0;
  S_period_841_1.MyFirstEnterFlag = &internal1_m841_MyFirstEnterFlag;
  S_ocham_804_1.Nk = &internal1_m804_Nk;
  S_ovb1_195_1.tx = &internal1_m195_tx;
  S_ovb1_25_1.tx = &internal1_m25_tx;
  S_asmot_476_1.Pav0 = &internal1_m476_Pav0;
  S_asmot_476_1.Zav0 = &internal1_m476_Zav0;
  S_asmot_476_1.Pv0 = &internal1_m476_Pv0;
  S_asmot_476_1.Zv0 = &internal1_m476_Zv0;
  S_asmot_476_1.RA00 = &internal1_m476_RA00;
  S_asmot_476_1.RA10 = &internal1_m476_RA10;
  S_asmot_476_1.MyFirstEnterFlag = &internal1_m476_MyFirstEnterFlag;
  S_asmot_476_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_490_1.Pav0 = &internal1_m490_Pav0;
  S_asmot_490_1.Zav0 = &internal1_m490_Zav0;
  S_asmot_490_1.Pv0 = &internal1_m490_Pv0;
  S_asmot_490_1.Zv0 = &internal1_m490_Zv0;
  S_asmot_490_1.RA00 = &internal1_m490_RA00;
  S_asmot_490_1.RA10 = &internal1_m490_RA10;
  S_asmot_490_1.MyFirstEnterFlag = &internal1_m490_MyFirstEnterFlag;
  S_asmot_490_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_478_1.Pav0 = &internal1_m478_Pav0;
  S_asmot_478_1.Zav0 = &internal1_m478_Zav0;
  S_asmot_478_1.Pv0 = &internal1_m478_Pv0;
  S_asmot_478_1.Zv0 = &internal1_m478_Zv0;
  S_asmot_478_1.RA00 = &internal1_m478_RA00;
  S_asmot_478_1.RA10 = &internal1_m478_RA10;
  S_asmot_478_1.MyFirstEnterFlag = &internal1_m478_MyFirstEnterFlag;
  S_asmot_478_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_621_1.Pav0 = &internal1_m621_Pav0;
  S_asmot_621_1.Zav0 = &internal1_m621_Zav0;
  S_asmot_621_1.Pv0 = &internal1_m621_Pv0;
  S_asmot_621_1.Zv0 = &internal1_m621_Zv0;
  S_asmot_621_1.RA00 = &internal1_m621_RA00;
  S_asmot_621_1.RA10 = &internal1_m621_RA10;
  S_asmot_621_1.MyFirstEnterFlag = &internal1_m621_MyFirstEnterFlag;
  S_asmot_621_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_618_1.Pav0 = &internal1_m618_Pav0;
  S_asmot_618_1.Zav0 = &internal1_m618_Zav0;
  S_asmot_618_1.Pv0 = &internal1_m618_Pv0;
  S_asmot_618_1.Zv0 = &internal1_m618_Zv0;
  S_asmot_618_1.RA00 = &internal1_m618_RA00;
  S_asmot_618_1.RA10 = &internal1_m618_RA10;
  S_asmot_618_1.MyFirstEnterFlag = &internal1_m618_MyFirstEnterFlag;
  S_asmot_618_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_604_1.Pav0 = &internal1_m604_Pav0;
  S_asmot_604_1.Zav0 = &internal1_m604_Zav0;
  S_asmot_604_1.Pv0 = &internal1_m604_Pv0;
  S_asmot_604_1.Zv0 = &internal1_m604_Zv0;
  S_asmot_604_1.RA00 = &internal1_m604_RA00;
  S_asmot_604_1.RA10 = &internal1_m604_RA10;
  S_asmot_604_1.MyFirstEnterFlag = &internal1_m604_MyFirstEnterFlag;
  S_asmot_604_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_603_1.Pav0 = &internal1_m603_Pav0;
  S_asmot_603_1.Zav0 = &internal1_m603_Zav0;
  S_asmot_603_1.Pv0 = &internal1_m603_Pv0;
  S_asmot_603_1.Zv0 = &internal1_m603_Zv0;
  S_asmot_603_1.RA00 = &internal1_m603_RA00;
  S_asmot_603_1.RA10 = &internal1_m603_RA10;
  S_asmot_603_1.MyFirstEnterFlag = &internal1_m603_MyFirstEnterFlag;
  S_asmot_603_1.FirstEnterFlag = &bFirstEnterFlag;
  S_mod1_650_1.y0 = &internal1_m650_y0;
  S_vchs_798_1.Chim0 = &internal1_m798_Chim0;
  S_vchs_790_1.Chim0 = &internal1_m790_Chim0;
  S_vchs_783_1.Chim0 = &internal1_m783_Chim0;
  S_vchs_775_1.Chim0 = &internal1_m775_Chim0;
  S_vchs_767_1.Chim0 = &internal1_m767_Chim0;
  S_vchs_760_1.Chim0 = &internal1_m760_Chim0;
  S_vchs_752_1.Chim0 = &internal1_m752_Chim0;
  S_vchs_744_1.Chim0 = &internal1_m744_Chim0;
  S_vchs_737_1.Chim0 = &internal1_m737_Chim0;
  S_vchs_729_1.Chim0 = &internal1_m729_Chim0;
  S_vchs_721_1.Chim0 = &internal1_m721_Chim0;
  S_vchs_714_1.Chim0 = &internal1_m714_Chim0;
  S_asmot_590_1.Pav0 = &internal1_m590_Pav0;
  S_asmot_590_1.Zav0 = &internal1_m590_Zav0;
  S_asmot_590_1.Pv0 = &internal1_m590_Pv0;
  S_asmot_590_1.Zv0 = &internal1_m590_Zv0;
  S_asmot_590_1.RA00 = &internal1_m590_RA00;
  S_asmot_590_1.RA10 = &internal1_m590_RA10;
  S_asmot_590_1.MyFirstEnterFlag = &internal1_m590_MyFirstEnterFlag;
  S_asmot_590_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_575_1.Pav0 = &internal1_m575_Pav0;
  S_asmot_575_1.Zav0 = &internal1_m575_Zav0;
  S_asmot_575_1.Pv0 = &internal1_m575_Pv0;
  S_asmot_575_1.Zv0 = &internal1_m575_Zv0;
  S_asmot_575_1.RA00 = &internal1_m575_RA00;
  S_asmot_575_1.RA10 = &internal1_m575_RA10;
  S_asmot_575_1.MyFirstEnterFlag = &internal1_m575_MyFirstEnterFlag;
  S_asmot_575_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_461_1.Pav0 = &internal1_m461_Pav0;
  S_asmot_461_1.Zav0 = &internal1_m461_Zav0;
  S_asmot_461_1.Pv0 = &internal1_m461_Pv0;
  S_asmot_461_1.Zv0 = &internal1_m461_Zv0;
  S_asmot_461_1.RA00 = &internal1_m461_RA00;
  S_asmot_461_1.RA10 = &internal1_m461_RA10;
  S_asmot_461_1.MyFirstEnterFlag = &internal1_m461_MyFirstEnterFlag;
  S_asmot_461_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_446_1.Pav0 = &internal1_m446_Pav0;
  S_asmot_446_1.Zav0 = &internal1_m446_Zav0;
  S_asmot_446_1.Pv0 = &internal1_m446_Pv0;
  S_asmot_446_1.Zv0 = &internal1_m446_Zv0;
  S_asmot_446_1.RA00 = &internal1_m446_RA00;
  S_asmot_446_1.RA10 = &internal1_m446_RA10;
  S_asmot_446_1.MyFirstEnterFlag = &internal1_m446_MyFirstEnterFlag;
  S_asmot_446_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_502_1.Pav0 = &internal1_m502_Pav0;
  S_asmot_502_1.Zav0 = &internal1_m502_Zav0;
  S_asmot_502_1.Pv0 = &internal1_m502_Pv0;
  S_asmot_502_1.Zv0 = &internal1_m502_Zv0;
  S_asmot_502_1.RA00 = &internal1_m502_RA00;
  S_asmot_502_1.RA10 = &internal1_m502_RA10;
  S_asmot_502_1.MyFirstEnterFlag = &internal1_m502_MyFirstEnterFlag;
  S_asmot_502_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_397_1.Pav0 = &internal1_m397_Pav0;
  S_asmot_397_1.Zav0 = &internal1_m397_Zav0;
  S_asmot_397_1.Pv0 = &internal1_m397_Pv0;
  S_asmot_397_1.Zv0 = &internal1_m397_Zv0;
  S_asmot_397_1.RA00 = &internal1_m397_RA00;
  S_asmot_397_1.RA10 = &internal1_m397_RA10;
  S_asmot_397_1.MyFirstEnterFlag = &internal1_m397_MyFirstEnterFlag;
  S_asmot_397_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_381_1.Pav0 = &internal1_m381_Pav0;
  S_asmot_381_1.Zav0 = &internal1_m381_Zav0;
  S_asmot_381_1.Pv0 = &internal1_m381_Pv0;
  S_asmot_381_1.Zv0 = &internal1_m381_Zv0;
  S_asmot_381_1.RA00 = &internal1_m381_RA00;
  S_asmot_381_1.RA10 = &internal1_m381_RA10;
  S_asmot_381_1.MyFirstEnterFlag = &internal1_m381_MyFirstEnterFlag;
  S_asmot_381_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_364_1.Pav0 = &internal1_m364_Pav0;
  S_asmot_364_1.Zav0 = &internal1_m364_Zav0;
  S_asmot_364_1.Pv0 = &internal1_m364_Pv0;
  S_asmot_364_1.Zv0 = &internal1_m364_Zv0;
  S_asmot_364_1.RA00 = &internal1_m364_RA00;
  S_asmot_364_1.RA10 = &internal1_m364_RA10;
  S_asmot_364_1.MyFirstEnterFlag = &internal1_m364_MyFirstEnterFlag;
  S_asmot_364_1.FirstEnterFlag = &bFirstEnterFlag;
  S_asmot_1167_1.Pav0 = &internal1_m1167_Pav0;
  S_asmot_1167_1.Zav0 = &internal1_m1167_Zav0;
  S_asmot_1167_1.Pv0 = &internal1_m1167_Pv0;
  S_asmot_1167_1.Zv0 = &internal1_m1167_Zv0;
  S_asmot_1167_1.RA00 = &internal1_m1167_RA00;
  S_asmot_1167_1.RA10 = &internal1_m1167_RA10;
  S_asmot_1167_1.MyFirstEnterFlag = &internal1_m1167_MyFirstEnterFlag;
  S_asmot_1167_1.FirstEnterFlag = &bFirstEnterFlag;
  S_azbars_180_1.C1 = &internal1_m180_C1;
  S_azbars_180_1.C2 = &internal1_m180_C2;
  S_azbars_180_1.C3 = &internal1_m180_C3;
  S_azbars_180_1.C4 = &internal1_m180_C4;
  S_azbars_180_1.C5 = &internal1_m180_C5;
  S_azbars_180_1.C6 = &internal1_m180_C6;
  S_azbars_180_1.N20 = &internal1_m180_N20;
  S_azbars_180_1.ImpINI0 = &internal1_m180_ImpINI0;
  S_azbars_180_1.MyFirstEnterFlag = &internal1_m180_MyFirstEnterFlag;
  S_azbars_180_1.FirstEnterFlag = &bFirstEnterFlag;
  S_orrsim_301_1.Ppv0 = &internal1_m301_Ppv0;
  S_orrsim_301_1.Pav0 = &internal1_m301_Pav0;
  S_orrsim_301_1.Zav0 = &internal1_m301_Zav0;
  S_orrsim_301_1.RA00 = &internal1_m301_RA00;
  S_orrsim_301_1.RA10 = &internal1_m301_RA10;
  S_orrsim_301_1.RA50 = &internal1_m301_RA50;
  S_orrsim_301_1.fls = &internal1_m301_fls;
  S_orrsim_301_1.flp = &internal1_m301_flp;
  S_orrsim_301_1.MyFirstEnterFlag = &internal1_m301_MyFirstEnterFlag;
  S_orrsim_301_1.FirstEnterFlag = &bFirstEnterFlag;
  S_orrsim_130_1.Ppv0 = &internal1_m130_Ppv0;
  S_orrsim_130_1.Pav0 = &internal1_m130_Pav0;
  S_orrsim_130_1.Zav0 = &internal1_m130_Zav0;
  S_orrsim_130_1.RA00 = &internal1_m130_RA00;
  S_orrsim_130_1.RA10 = &internal1_m130_RA10;
  S_orrsim_130_1.RA50 = &internal1_m130_RA50;
  S_orrsim_130_1.fls = &internal1_m130_fls;
  S_orrsim_130_1.flp = &internal1_m130_flp;
  S_orrsim_130_1.MyFirstEnterFlag = &internal1_m130_MyFirstEnterFlag;
  S_orrsim_130_1.FirstEnterFlag = &bFirstEnterFlag;
  S_orrsim_265_1.Ppv0 = &internal1_m265_Ppv0;
  S_orrsim_265_1.Pav0 = &internal1_m265_Pav0;
  S_orrsim_265_1.Zav0 = &internal1_m265_Zav0;
  S_orrsim_265_1.RA00 = &internal1_m265_RA00;
  S_orrsim_265_1.RA10 = &internal1_m265_RA10;
  S_orrsim_265_1.RA50 = &internal1_m265_RA50;
  S_orrsim_265_1.fls = &internal1_m265_fls;
  S_orrsim_265_1.flp = &internal1_m265_flp;
  S_orrsim_265_1.MyFirstEnterFlag = &internal1_m265_MyFirstEnterFlag;
  S_orrsim_265_1.FirstEnterFlag = &bFirstEnterFlag;
  S_orrsim_97_1.Ppv0 = &internal1_m97_Ppv0;
  S_orrsim_97_1.Pav0 = &internal1_m97_Pav0;
  S_orrsim_97_1.Zav0 = &internal1_m97_Zav0;
  S_orrsim_97_1.RA00 = &internal1_m97_RA00;
  S_orrsim_97_1.RA10 = &internal1_m97_RA10;
  S_orrsim_97_1.RA50 = &internal1_m97_RA50;
  S_orrsim_97_1.fls = &internal1_m97_fls;
  S_orrsim_97_1.flp = &internal1_m97_flp;
  S_orrsim_97_1.MyFirstEnterFlag = &internal1_m97_MyFirstEnterFlag;
  S_orrsim_97_1.FirstEnterFlag = &bFirstEnterFlag;
  S_orrsim_227_1.Ppv0 = &internal1_m227_Ppv0;
  S_orrsim_227_1.Pav0 = &internal1_m227_Pav0;
  S_orrsim_227_1.Zav0 = &internal1_m227_Zav0;
  S_orrsim_227_1.RA00 = &internal1_m227_RA00;
  S_orrsim_227_1.RA10 = &internal1_m227_RA10;
  S_orrsim_227_1.RA50 = &internal1_m227_RA50;
  S_orrsim_227_1.fls = &internal1_m227_fls;
  S_orrsim_227_1.flp = &internal1_m227_flp;
  S_orrsim_227_1.MyFirstEnterFlag = &internal1_m227_MyFirstEnterFlag;
  S_orrsim_227_1.FirstEnterFlag = &bFirstEnterFlag;
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
  S_twobool_1118_1.Ter = &iEM_TERR4VS22LDU;
  S_twobool_1117_1.Ter = &iEM_TERR4VS12LDU;
  S_twobool_943_1.Ter = &iEM_TERR2VS22LIM;
  S_twobool_942_1.Ter = &iEM_TERR2VS12LIM;
  S_twobool_941_1.Ter = &iEM_TERR1VS22LIM;
  S_twobool_940_1.Ter = &iEM_TERR1VS12LIM;
  S_twobool_691_1.Ter = &iEM_TERB5VS22LIM;
  S_twobool_690_1.Ter = &iEM_TERB5VS12LIM;
  S_twobool_669_1.Ter = &iEM_TERA5VS22LIM;
  S_twobool_668_1.Ter = &iEM_TERA5VS12LIM;
  S_twobool_689_1.Ter = &iEM_TERB6VS22LIM;
  S_twobool_688_1.Ter = &iEM_TERB6VS12LIM;
  S_twobool_667_1.Ter = &iEM_TERA6VS22LIM;
  S_twobool_666_1.Ter = &iEM_TERA6VS12LIM;
  S_twobool_527_1.Ter = &iEM_TERA1VP81LIM;
  S_twobool_545_1.Ter = &iEM_TERB1VP81LIM;
  S_twobool_409_1.Ter = &iEM_TERB2SS33LIM;
  S_rs_486_1.s = &lEM_R5AD10LC1;
  S_rs_487_1.s = &lEM_R5AD20LC1;
  S_rs_472_1.s = &lEM_R3AD10LC1;
  S_rs_473_1.s = &lEM_R3AD20LC1;
  S_zpfs_642_1.tz = &fEM_R7UI76RIM;
  S_zpfs_630_1.tz = &fEM_R7UI77RIM;
  S_bol_1214_1.x1 = &fEM_A4UP01RIM;
  S_bol_1214_1.x2 = &fEM_A4UP02RIM;
  S_bol_1216_1.x1 = &fEM_A3UP01RIM;
  S_bol_1216_1.x2 = &fEM_A3UP02RIM;
  S_bol_1211_1.x1 = &fEM_A0UP02RIM;
  S_bol_1211_1.x2 = &fEM_A0UP01RIM;
  S_bol_1208_1.x1 = &fEM_A2UP02RIM;
  S_bol_1208_1.x2 = &fEM_A2UP03RIM;
  S_bol_1207_1.x1 = &fEM_A1UP01RIM;
  S_bol_1207_1.x2 = &fEM_A1UP82RIM;
  S_and5_1098_1.x5 = &lEM_A0EE06LC1;
  S_and5_913_1.x5 = &lEM_A0EE04LC1;
  S_and5_1041_1.x5 = &lEM_A0EE05LC1;
  S_and5_854_1.x5 = &lEM_A0EE03LC1;
  S_twobool_206_1.Ter = &iEM_TERB1IE04LDU;
  S_twobool_224_1.Ter = &iEM_TERB1IE03LDU;
  S_twobool_41_1.Ter = &iEM_TERA1IE04LDU;
  S_twobool_56_1.Ter = &iEM_TERA1IE03LDU;
  S_twobool_1241_1.Ter = &iEM_TERB1SS12LIM;
  S_twobool_1238_1.Ter = &iEM_TERB1SS11LIM;
  S_twobool_1237_1.Ter = &iEM_TERB1SS21LIM;
  S_ktoenc_1240_1.C = &fEM_A1UC03RDU;
  S_to3val_1235_1.Ter = &iEM_TERB1MC01RIM;
  S_ktoenc_1226_1.C = &fEM_A1UC03RDU;
  S_to3val_1221_1.Ter = &iEM_TERA1SC01RIM;
  S_twobool_1227_1.Ter = &iEM_TERA1SS12LIM;
  S_twobool_1224_1.Ter = &iEM_TERA1SS11LIM;
  S_twobool_1223_1.Ter = &iEM_TERA1SS21LIM;
  S_twobool_981_1.Ter = &iEM_TERB6SS21LIM;
  S_twobool_962_1.Ter = &iEM_TERB6SS11LIM;
  S_twobool_961_1.Ter = &iEM_TERA6SS21LIM;
  S_twobool_960_1.Ter = &iEM_TERA6MS11LIM;
  S_twobool_1139_1.Ter = &iEM_TERA8SS12LIM;
  S_twobool_1141_1.Ter = &iEM_TERA8SS22LIM;
  S_twobool_1138_1.Ter = &iEM_TERB8SS12LIM;
  S_twobool_1140_1.Ter = &iEM_TERB8SS22LIM;
  S_twobool_1114_1.Ter = &iEM_TERR4SS12LIM;
  S_twobool_1115_1.Ter = &iEM_TERR4SS22LIM;
  S_twobool_1113_1.Ter = &iEM_TERR4MS21LIM;
  S_twobool_1112_1.Ter = &iEM_TERR4SS11LIM;
  S_twobool_976_1.Ter = &iEM_TERA4VP82LIM;
  S_twobool_928_1.Ter = &iEM_TERR2SS21LIM;
  S_twobool_927_1.Ter = &iEM_TERR2SS11LIM;
  S_twobool_926_1.Ter = &iEM_TERR1SS21LIM;
  S_twobool_925_1.Ter = &iEM_TERR1SS11LIM;
  S_twobool_977_1.Ter = &iEM_TERB4SS21LIM;
  S_twobool_958_1.Ter = &iEM_TERB4SS11LIM;
  S_twobool_1116_1.S = &lEM_R8AD10LC1;
  S_twobool_1116_1.Ter = &iEM_TERR8SS11LIM;
  S_twobool_959_1.Ter = &iEM_TERA4SS21LIM;
  S_twobool_957_1.Ter = &iEM_TERA4SS11LIM;
  S_twobool_978_1.Ter = &iEM_TERR5SS21LIM;
  S_twobool_956_1.Ter = &iEM_TERR5SS11LIM;
  S_twobool_939_1.Ter = &iEM_TERR3SS21LIM;
  S_twobool_924_1.Ter = &iEM_TERR3SS11LIM;
  S_twobool_543_1.Ter = &iEM_TERA2VP82LIM;
  S_toao_544_1.a = &fEM_A2UP04RDU;
  S_toao_544_1.b = &fEM_A2UP03RDU;
  S_toao_550_1.a = &fEM_A2UP04RDU;
  S_toao_550_1.b = &fEM_A2UP03RDU;
  S_to3val_541_1.maxs1 = &fEM_A2UP03RDU;
  S_to3val_541_1.maxs2 = &fEM_A2UP03RDU;
  S_to3val_541_1.Ter = &iEM_TERB2SP01RIM;
  S_ktoenc_419_1.C = &fEM_A2UC03RDU;
  S_to3val_413_1.Ter = &iEM_TERB2SC01RIM;
  S_twobool_410_1.Ter = &iEM_TERB2SS12LIM;
  S_twobool_412_1.Ter = &iEM_TERB2SS11LIM;
  S_twobool_411_1.Ter = &iEM_TERB2SS21LIM;
  S_twobool_1154_1.Ter = &iEM_TERB9SS21LIM;
  S_twobool_1155_1.Ter = &iEM_TERB9SS11LIM;
  S_twobool_1153_1.Ter = &iEM_TERA9SS21LIM;
  S_twobool_980_1.Ter = &iEM_TERA9SS11LIM;
  S_twobool_704_1.Ter = &iEM_TERB5SS21LIM;
  S_twobool_705_1.Ter = &iEM_TERB5SS11LIM;
  S_twobool_702_1.Ter = &iEM_TERA5SS21LIM;
  S_twobool_703_1.Ter = &iEM_TERA5SS11LIM;
  S_ampl_655_1.k = &fEM_R7UI75RIM;
  S_to3val_656_1.maxs1 = &fEM_R7UI74RIM;
  S_to3val_656_1.maxs2 = &fEM_R7UI74RIM;
  S_to3val_656_1.Ter = &iEM_TERR7SI74RIM;
  S_twobool_561_1.Ter = &iEM_TERB0VP81LIM;
  S_twobool_560_1.Ter = &iEM_TERA0VP81LIM;
  S_ktoenc_1135_1.C = &fEM_A8UC03RDU;
  S_to3val_1127_1.Ter = &iEM_TERB8SC01RIM;
  S_ktoenc_1137_1.C = &fEM_A8UC03RDU;
  S_to3val_1129_1.Ter = &iEM_TERA8SC01RIM;
  S_twobool_701_1.Ter = &iEM_TERR6IS68LIM;
  S_twobool_685_1.Ter = &iEM_TERR6IS67LIM;
  S_twobool_665_1.Ter = &iEM_TERR6IS66LIM;
  S_twobool_684_1.Ter = &iEM_TERR6IS64LIM;
  S_twobool_664_1.Ter = &iEM_TERR6IS62LIM;
  S_twobool_337_1.Ter = &iEM_TERB3SS22LIM;
  S_twobool_336_1.Ter = &iEM_TERA3SS22LIM;
  S_twobool_321_1.Ter = &iEM_TERB3SS11LIM;
  S_twobool_320_1.Ter = &iEM_TERA3SS11LIM;
  S_toao_521_1.a = &fEM_A3UP04RDU;
  S_toao_521_1.b = &fEM_A3UP03RDU;
  S_to3val_515_1.maxs1 = &fEM_A3UP03RDU;
  S_to3val_515_1.maxs2 = &fEM_A3UP03RDU;
  S_to3val_515_1.Ter = &iEM_TERA3SP02RIM;
  S_twobool_562_1.Ter = &iEM_TERA3VP81LIM;
  S_toao_525_1.a = &fEM_A3UP04RDU;
  S_toao_525_1.b = &fEM_A3UP03RDU;
  S_to3val_518_1.maxs1 = &fEM_A3UP03RDU;
  S_to3val_518_1.maxs2 = &fEM_A3UP03RDU;
  S_to3val_518_1.Ter = &iEM_TERB3SP02RIM;
  S_twobool_350_1.Ter = &iEM_TERB3SS33LIM;
  S_ktoenc_334_1.C = &fEM_A3UC03RDU;
  S_to3val_333_1.Ter = &iEM_TERB3SC01RIM;
  S_twobool_349_1.Ter = &iEM_TERB3SS31LIM;
  S_twobool_347_1.Ter = &iEM_TERA3SS33LIM;
  S_ktoenc_327_1.C = &fEM_A3UC03RDU;
  S_to3val_323_1.Ter = &iEM_TERA3SC01RIM;
  S_twobool_348_1.Ter = &iEM_TERA3SS31LIM;
  S_toao_549_1.a = &fEM_A2UP04RDU;
  S_toao_549_1.b = &fEM_A2UP03RDU;
  S_toao_548_1.a = &fEM_A2UP04RDU;
  S_toao_548_1.b = &fEM_A2UP03RDU;
  S_twobool_319_1.Ter = &iEM_TERB3SS21LIM;
  S_twobool_335_1.Ter = &iEM_TERA3SS21LIM;
  S_twobool_431_1.Ter = &iEM_TERA2SS33LIM;
  S_ktoenc_432_1.C = &fEM_A2UC03RDU;
  S_to3val_427_1.Ter = &iEM_TERA2SC01RIM;
  S_twobool_430_1.Ter = &iEM_TERA2SS12LIM;
  S_twobool_429_1.Ter = &iEM_TERA2SS11LIM;
  S_twobool_428_1.Ter = &iEM_TERA2SS21LIM;
  S_to3val_540_1.x1 = &fEM_A2UP01RIM;
  S_to3val_540_1.maxs1 = &fEM_A2UP03RDU;
  S_to3val_540_1.maxs2 = &fEM_A2UP03RDU;
  S_to3val_540_1.Ter = &iEM_TERA2SP01RIM;
  S_toao_163_1.a = &fEM_R0UT01RDU;
  S_toao_163_1.b = &fEM_R0UT02RDU;
  S_toao_162_1.a = &fEM_R0UT01RDU;
  S_toao_162_1.b = &fEM_R0UT02RDU;
  S_toao_161_1.a = &fEM_R0UT01RDU;
  S_toao_161_1.b = &fEM_R0UT02RDU;
  S_to3val_156_1.maxs1 = &fEM_R0UT02RDU;
  S_to3val_156_1.maxs2 = &fEM_R0UT02RDU;
  S_to3val_156_1.Ter = &iEM_TERB0MT01RIM;
  S_toao_166_1.a = &fEM_R0UT01RDU;
  S_toao_166_1.b = &fEM_R0UT02RDU;
  S_toao_165_1.a = &fEM_R0UT01RDU;
  S_toao_165_1.b = &fEM_R0UT02RDU;
  S_twobool_979_1.Ter = &iEM_TERR6SS21LIM;
  S_twobool_150_1.Ter = &iEM_TERB7MS31LIM;
  S_toao_164_1.a = &fEM_R0UT01RDU;
  S_toao_164_1.b = &fEM_R0UT02RDU;
  S_to3val_158_1.maxs1 = &fEM_R0UT02RDU;
  S_to3val_158_1.maxs2 = &fEM_R0UT02RDU;
  S_to3val_158_1.Ter = &iEM_TERA0MT01RIM;
  S_twobool_149_1.Ter = &iEM_TERA7MS31LIM;
  S_twobool_1102_1.Ter = &iEM_TERR0IE41LIM;
  S_twobool_1093_1.Ter = &iEM_TERR0IE43LIM;
  S_period_1082_1.TiStep = &fEM_R0UL01RSS;
  S_period_1082_1.Tmax = &fEM_R0UL03RSS;
  S_period_1082_1.Nmin = &fEM_R0UN03RSS;
  S_bol_1087_1.x1 = &fEM_R0UL41RSS;
  S_bol_1086_1.x2 = &fEM_R0UN03RSS;
  S_bol_1085_1.x1 = &fEM_R0UL51RSS;
  S_bol_1073_1.x2 = &fEM_R0UL52RSS;
  S_bol_1077_1.x2 = &fEM_R0UL42RSS;
  S_ocham_1048_1.YAz1 = &fEM_R7UY00RSS;
  S_ocham_1048_1.Reff = &fEM_A0UX00RSS;
  S_ocham_1048_1.Ak1 = &fEM_A0UX10RSS;
  S_ocham_1048_1.Bk1 = &fEM_B0UX10RSS;
  S_ocham_1048_1.Ak2 = &fEM_A0UX11RSS;
  S_ocham_1048_1.Bk2 = &fEM_B0UX11RSS;
  S_ocham_1048_1.Ak3 = &fEM_A0UX12RSS;
  S_ocham_1048_1.Bk3 = &fEM_B0UX12RSS;
  S_ocham_1048_1.XCm1 = &fEM_R7UX10RSS;
  S_ocham_1048_1.YCm1 = &fEM_R7UY10RSS;
  S_ocham_1048_1.XCm2 = &fEM_R7UX11RSS;
  S_ocham_1048_1.YCm2 = &fEM_R7UY11RSS;
  S_ocham_1048_1.XCm3 = &fEM_R7UX12RSS;
  S_ocham_1048_1.YCm3 = &fEM_R7UY12RSS;
  S_ocham_1048_1.Kpr2k = &fEM_R0UH02RSS;
  S_ocham_1048_1.Kpr3k = &fEM_R0UH03RSS;
  S_ocham_1048_1.Kprm = &fEM_R0UH05RSS;
  S_bol_1067_1.x2 = &fEM_R0UR01RSS;
  S_twobool_1043_1.Ter = &iEM_TERR0IE31LIM;
  S_twobool_1035_1.Ter = &iEM_TERR0IE33LIM;
  S_period_1024_1.TiStep = &fEM_R0UL01RSS;
  S_period_1024_1.Tmax = &fEM_R0UL03RSS;
  S_period_1024_1.Nmin = &fEM_R0UN03RSS;
  S_bol_1029_1.x1 = &fEM_R0UL41RSS;
  S_bol_1028_1.x2 = &fEM_R0UN03RSS;
  S_bol_1027_1.x1 = &fEM_R0UL51RSS;
  S_bol_1016_1.x2 = &fEM_R0UL52RSS;
  S_bol_1019_1.x2 = &fEM_R0UL42RSS;
  S_ocham_994_1.YAz1 = &fEM_R7UY00RSS;
  S_ocham_994_1.Reff = &fEM_A0UX00RSS;
  S_ocham_994_1.Ak1 = &fEM_A0UX07RSS;
  S_ocham_994_1.Bk1 = &fEM_B0UX07RSS;
  S_ocham_994_1.Ak2 = &fEM_A0UX08RSS;
  S_ocham_994_1.Bk2 = &fEM_B0UX08RSS;
  S_ocham_994_1.Ak3 = &fEM_A0UX09RSS;
  S_ocham_994_1.Bk3 = &fEM_B0UX09RSS;
  S_ocham_994_1.XCm1 = &fEM_R7UX07RSS;
  S_ocham_994_1.YCm1 = &fEM_R7UY07RSS;
  S_ocham_994_1.XCm2 = &fEM_R7UX08RSS;
  S_ocham_994_1.YCm2 = &fEM_R7UY08RSS;
  S_ocham_994_1.XCm3 = &fEM_R7UX09RSS;
  S_ocham_994_1.YCm3 = &fEM_R7UY09RSS;
  S_ocham_994_1.Kpr2k = &fEM_R0UH02RSS;
  S_ocham_994_1.Kpr3k = &fEM_R0UH03RSS;
  S_ocham_994_1.Kprm = &fEM_R0UH05RSS;
  S_bol_1002_1.x2 = &fEM_R0UR01RSS;
  S_twobool_915_1.Ter = &iEM_TERR0IE21LIM;
  S_twobool_905_1.Ter = &iEM_TERR0IE23LIM;
  S_period_896_1.TiStep = &fEM_R0UL01RSS;
  S_period_896_1.Tmax = &fEM_R0UL03RSS;
  S_period_896_1.Nmin = &fEM_R0UN03RSS;
  S_bol_903_1.x1 = &fEM_R0UL41RSS;
  S_bol_902_1.x2 = &fEM_R0UN03RSS;
  S_bol_901_1.x1 = &fEM_R0UL51RSS;
  S_bol_886_1.x2 = &fEM_R0UL52RSS;
  S_bol_890_1.x2 = &fEM_R0UL42RSS;
  S_ocham_862_1.YAz1 = &fEM_R7UY00RSS;
  S_ocham_862_1.Reff = &fEM_A0UX00RSS;
  S_ocham_862_1.Ak1 = &fEM_A0UX04RSS;
  S_ocham_862_1.Bk1 = &fEM_B0UX04RSS;
  S_ocham_862_1.Ak2 = &fEM_A0UX05RSS;
  S_ocham_862_1.Bk2 = &fEM_B0UX05RSS;
  S_ocham_862_1.Ak3 = &fEM_A0UX06RSS;
  S_ocham_862_1.Bk3 = &fEM_B0UX06RSS;
  S_ocham_862_1.XCm1 = &fEM_R7UX04RSS;
  S_ocham_862_1.YCm1 = &fEM_R7UY04RSS;
  S_ocham_862_1.XCm2 = &fEM_R7UX05RSS;
  S_ocham_862_1.YCm2 = &fEM_R7UY05RSS;
  S_ocham_862_1.XCm3 = &fEM_R7UX06RSS;
  S_ocham_862_1.YCm3 = &fEM_R7UY06RSS;
  S_ocham_862_1.Kpr2k = &fEM_R0UH02RSS;
  S_ocham_862_1.Kpr3k = &fEM_R0UH03RSS;
  S_ocham_862_1.Kprm = &fEM_R0UH05RSS;
  S_bol_884_1.x2 = &fEM_R0UR01RSS;
  S_twobool_849_1.Ter = &iEM_TERR0IE13LIM;
  S_twobool_838_1.Ter = &iEM_TERR0IE11LIM;
  S_period_841_1.TiStep = &fEM_R0UL01RSS;
  S_period_841_1.Tmax = &fEM_R0UL03RSS;
  S_period_841_1.Nmin = &fEM_R0UN03RSS;
  S_bol_846_1.x1 = &fEM_R0UL41RSS;
  S_bol_845_1.x2 = &fEM_R0UN03RSS;
  S_bol_844_1.x1 = &fEM_R0UL51RSS;
  S_bol_829_1.x2 = &fEM_R0UL52RSS;
  S_bol_833_1.x2 = &fEM_R0UL42RSS;
  S_ocham_804_1.YAz1 = &fEM_R7UY00RSS;
  S_ocham_804_1.Reff = &fEM_A0UX00RSS;
  S_ocham_804_1.Ak1 = &fEM_A0UX01RSS;
  S_ocham_804_1.Bk1 = &fEM_B0UX01RSS;
  S_ocham_804_1.Ak2 = &fEM_A0UX02RSS;
  S_ocham_804_1.Bk2 = &fEM_B0UX02RSS;
  S_ocham_804_1.Ak3 = &fEM_A0UX03RSS;
  S_ocham_804_1.Bk3 = &fEM_B0UX03RSS;
  S_ocham_804_1.XCm1 = &fEM_R7UX01RSS;
  S_ocham_804_1.YCm1 = &fEM_R7UY01RSS;
  S_ocham_804_1.XCm2 = &fEM_R7UX02RSS;
  S_ocham_804_1.YCm2 = &fEM_R7UY02RSS;
  S_ocham_804_1.XCm3 = &fEM_R7UX03RSS;
  S_ocham_804_1.YCm3 = &fEM_R7UY03RSS;
  S_ocham_804_1.Kpr2k = &fEM_R0UH02RSS;
  S_ocham_804_1.Kpr3k = &fEM_R0UH03RSS;
  S_ocham_804_1.Kprm = &fEM_R0UH05RSS;
  S_bol_823_1.x2 = &fEM_R0UR01RSS;
  S_lk_517_1.x = &fEM_A3UP02RDU;
  S_lk_516_1.x = &fEM_A3UP02RDU;
  S_noto_474_1.x = &lEM_R6AD10LC1;
  S_asmot_476_1.RA1 = &lEM_R6AD10LC1;
  S_asmot_476_1.KPav = &fEM_R6UL10RIM;
  S_asmot_476_1.X0 = &fEM_R6UC01RSP;
  S_asmot_476_1.V0 = &fEM_R6UV01RSP;
  S_asmot_490_1.KPav = &fEM_R5UL10RIM;
  S_asmot_490_1.X0 = &fEM_R5UC01RSP;
  S_asmot_490_1.V0 = &fEM_R5UV01RSP;
  S_asmot_478_1.KPav = &fEM_R3UL10RIM;
  S_asmot_478_1.X0 = &fEM_R3UC01RSP;
  S_asmot_478_1.V0 = &fEM_R3UV01RSP;
  S_asmot_621_1.KPav = &fEM_A4UL10RIM;
  S_asmot_621_1.X0 = &fEM_A4MC01RSP;
  S_asmot_621_1.V0 = &fEM_A4MV01RSP;
  S_asmot_618_1.KPav = &fEM_A4UL10RIM;
  S_asmot_618_1.X0 = &fEM_B4MC01RSP;
  S_asmot_618_1.V0 = &fEM_B4MV01RSP;
  S_asmot_604_1.KPav = &fEM_A9UL10RIM;
  S_asmot_604_1.X0 = &fEM_A9MC01RSP;
  S_asmot_604_1.V0 = &fEM_A9MV01RSP;
  S_asmot_603_1.KPav = &fEM_A9UL10RIM;
  S_asmot_603_1.X0 = &fEM_B9MC01RSP;
  S_asmot_603_1.V0 = &fEM_B9MV01RSP;
  S_fsubo_371_1.x1 = &fEM_R7UY00RSS;
  S_fsubo_115_1.x1 = &fEM_A2UC05RIM;
  S_fsubo_283_1.x1 = &fEM_A2UC05RIM;
  S_fsubo_242_1.x1 = &fEM_A1UC05RIM;
  S_fsubo_74_1.x1 = &fEM_A1UC05RIM;
  S_fsubo_8_1.x2 = &fEM_R0UR01RIM;
  S_mod1_650_1.k = &fEM_R7UI02RIM;
  S_mod1_650_1.tau = &fEM_R7UL01RIM;
  S_bol_644_1.x2 = &fEM_R7UI73RIM;
  S_bol_634_1.x2 = &fEM_R7UI72RIM;
  S_bol_628_1.x2 = &fEM_R7UI71RIM;
  S_vchs_798_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_798_1.XCm = &fEM_R7UX12RSS;
  S_vchs_798_1.YCm = &fEM_R7UY12RSS;
  S_vchs_798_1.Ak = &fEM_A0UX12RSS;
  S_vchs_798_1.Bk = &fEM_B0UX12RSS;
  S_vchs_798_1.Fk = &fEM_R0UH03RSS;
  S_vchs_798_1.FMax = &fEM_R0UH23RSS;
  S_vchs_798_1.Reff = &fEM_A0UX00RSS;
  S_vchs_790_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_790_1.XCm = &fEM_R7UX11RSS;
  S_vchs_790_1.YCm = &fEM_R7UY11RSS;
  S_vchs_790_1.Ak = &fEM_A0UX11RSS;
  S_vchs_790_1.Bk = &fEM_B0UX11RSS;
  S_vchs_790_1.Fk = &fEM_R0UH02RSS;
  S_vchs_790_1.FMax = &fEM_R0UH22RSS;
  S_vchs_790_1.Reff = &fEM_A0UX00RSS;
  S_vchs_783_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_783_1.XCm = &fEM_R7UX10RSS;
  S_vchs_783_1.YCm = &fEM_R7UY10RSS;
  S_vchs_783_1.Ak = &fEM_A0UX10RSS;
  S_vchs_783_1.Bk = &fEM_B0UX10RSS;
  S_vchs_783_1.FMax = &fEM_R0UH21RSS;
  S_vchs_783_1.Reff = &fEM_A0UX00RSS;
  S_vchs_775_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_775_1.XCm = &fEM_R7UX09RSS;
  S_vchs_775_1.YCm = &fEM_R7UY09RSS;
  S_vchs_775_1.Ak = &fEM_A0UX09RSS;
  S_vchs_775_1.Bk = &fEM_B0UX09RSS;
  S_vchs_775_1.Fk = &fEM_R0UH03RSS;
  S_vchs_775_1.FMax = &fEM_R0UH23RSS;
  S_vchs_775_1.Reff = &fEM_A0UX00RSS;
  S_vchs_767_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_767_1.XCm = &fEM_R7UX08RSS;
  S_vchs_767_1.YCm = &fEM_R7UY08RSS;
  S_vchs_767_1.Ak = &fEM_A0UX08RSS;
  S_vchs_767_1.Bk = &fEM_B0UX08RSS;
  S_vchs_767_1.Fk = &fEM_R0UH02RSS;
  S_vchs_767_1.FMax = &fEM_R0UH22RSS;
  S_vchs_767_1.Reff = &fEM_A0UX00RSS;
  S_vchs_760_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_760_1.XCm = &fEM_R7UX07RSS;
  S_vchs_760_1.YCm = &fEM_R7UY07RSS;
  S_vchs_760_1.Ak = &fEM_A0UX07RSS;
  S_vchs_760_1.Bk = &fEM_B0UX07RSS;
  S_vchs_760_1.FMax = &fEM_R0UH21RSS;
  S_vchs_760_1.Reff = &fEM_A0UX00RSS;
  S_vchs_752_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_752_1.XCm = &fEM_R7UX06RSS;
  S_vchs_752_1.YCm = &fEM_R7UY06RSS;
  S_vchs_752_1.Ak = &fEM_A0UX06RSS;
  S_vchs_752_1.Bk = &fEM_B0UX06RSS;
  S_vchs_752_1.Fk = &fEM_R0UH03RSS;
  S_vchs_752_1.FMax = &fEM_R0UH23RSS;
  S_vchs_752_1.Reff = &fEM_A0UX00RSS;
  S_vchs_744_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_744_1.XCm = &fEM_R7UX05RSS;
  S_vchs_744_1.YCm = &fEM_R7UY05RSS;
  S_vchs_744_1.Ak = &fEM_A0UX05RSS;
  S_vchs_744_1.Bk = &fEM_B0UX05RSS;
  S_vchs_744_1.Fk = &fEM_R0UH02RSS;
  S_vchs_744_1.FMax = &fEM_R0UH22RSS;
  S_vchs_744_1.Reff = &fEM_A0UX00RSS;
  S_vchs_737_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_737_1.XCm = &fEM_R7UX04RSS;
  S_vchs_737_1.YCm = &fEM_R7UY04RSS;
  S_vchs_737_1.Ak = &fEM_A0UX04RSS;
  S_vchs_737_1.Bk = &fEM_B0UX04RSS;
  S_vchs_737_1.FMax = &fEM_R0UH21RSS;
  S_vchs_737_1.Reff = &fEM_A0UX00RSS;
  S_vchs_729_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_729_1.XCm = &fEM_R7UC10RIM;
  S_vchs_729_1.YCm = &fEM_R7UC19RIM;
  S_vchs_729_1.Ak = &fEM_A0UX03RSS;
  S_vchs_729_1.Bk = &fEM_B0UX03RSS;
  S_vchs_729_1.Fk = &fEM_R0UH03RSS;
  S_vchs_729_1.FMax = &fEM_R0UH23RSS;
  S_vchs_729_1.Reff = &fEM_A0UX00RSS;
  S_vchs_721_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_721_1.XCm = &fEM_R7UX02RSS;
  S_vchs_721_1.YCm = &fEM_R7UY02RSS;
  S_vchs_721_1.Ak = &fEM_A0UX02RSS;
  S_vchs_721_1.Bk = &fEM_B0UX02RSS;
  S_vchs_721_1.Fk = &fEM_R0UH02RSS;
  S_vchs_721_1.FMax = &fEM_R0UH22RSS;
  S_vchs_721_1.Reff = &fEM_A0UX00RSS;
  S_fsumo_1172_1.x1 = &fEM_R4UC10RIM;
  S_fsumo_1172_1.x2 = &fEM_R4UC22RIM;
  S_vchs_714_1.YAz1 = &fEM_R7UY00RSS;
  S_vchs_714_1.XCm = &fEM_R7UX01RSS;
  S_vchs_714_1.YCm = &fEM_R7UY01RSS;
  S_vchs_714_1.Ak = &fEM_A0UX01RSS;
  S_vchs_714_1.Bk = &fEM_B0UX01RSS;
  S_vchs_714_1.FMax = &fEM_R0UH21RSS;
  S_vchs_714_1.Reff = &fEM_A0UX00RSS;
  S_asmot_590_1.XYvk = &fEM_B5MC01RC1;
  S_asmot_590_1.Vzvk = &fEM_B5MV01RC1;
  S_asmot_590_1.Ter = &iEM_TERNL2;
  S_asmot_590_1.KPav = &fEM_A5UC10RIM;
  S_asmot_590_1.X0 = &fEM_B5MC01RSP;
  S_asmot_590_1.V0 = &fEM_B5MV01RSP;
  S_asmot_575_1.XYvk = &fEM_A5MC01RC1;
  S_asmot_575_1.Vzvk = &fEM_A5MV01RC1;
  S_asmot_575_1.Ter = &iEM_TERNL1;
  S_asmot_575_1.KPav = &fEM_A5UC10RIM;
  S_asmot_575_1.X0 = &fEM_A5MC01RSP;
  S_asmot_575_1.V0 = &fEM_A5MV01RSP;
  S_asmot_461_1.XYvk = &fEM_R2MC01RC1;
  S_asmot_461_1.Vzvk = &fEM_R2MV01RC1;
  S_asmot_461_1.Ter = &iEM_TERMDZ2;
  S_asmot_461_1.KPav = &fEM_R1UC10RIM;
  S_asmot_461_1.X0 = &fEM_R2MC01RSP;
  S_asmot_461_1.V0 = &fEM_R2MV01RSP;
  S_asmot_446_1.XYvk = &fEM_R1MC01RC1;
  S_asmot_446_1.Vzvk = &fEM_R1MV01RC1;
  S_asmot_446_1.Ter = &iEM_TERMDZ1;
  S_asmot_446_1.KPav = &fEM_R1UC10RIM;
  S_asmot_446_1.X0 = &fEM_R1MC01RSP;
  S_asmot_446_1.V0 = &fEM_R1MV01RSP;
  S_asmot_502_1.XYvk = &fEM_B6MC01RC1;
  S_asmot_502_1.Vzvk = &fEM_B6MV01RC1;
  S_asmot_502_1.Tp = &fEM_A6US80RDU;
  S_asmot_502_1.Ter = &iEM_TERBZ2;
  S_asmot_502_1.KPav = &fEM_A6UC10RIM;
  S_asmot_502_1.X0 = &fEM_B6MC01RSP;
  S_asmot_502_1.V0 = &fEM_B6MV01RSP;
  S_asmot_397_1.XYvk = &fEM_A6MC01RC1;
  S_asmot_397_1.Vzvk = &fEM_A6MV01RC1;
  S_asmot_397_1.Tp = &fEM_A6US80RDU;
  S_asmot_397_1.Ter = &iEM_TERBZ1;
  S_asmot_397_1.KPav = &fEM_A6UC10RIM;
  S_asmot_397_1.X0 = &fEM_A6MC01RSP;
  S_asmot_397_1.V0 = &fEM_A6MV01RSP;
  S_asmot_381_1.XYvk = &fEM_A8MC01RC1;
  S_asmot_381_1.Vzvk = &fEM_A8MV01RC1;
  S_asmot_381_1.Vm = &fEM_A8UV80RDU;
  S_asmot_381_1.Tp = &fEM_A8US80RDU;
  S_asmot_381_1.Ter = &iEM_TERDS2;
  S_asmot_381_1.KPav = &fEM_A8UC10RIM;
  S_asmot_381_1.KZav = &fEM_A8UC20RIM;
  S_asmot_381_1.KPv = &fEM_A8UC11RIM;
  S_asmot_381_1.KZv = &fEM_A8UC21RIM;
  S_asmot_381_1.Dlt = &fEM_A8UC08RDU;
  S_asmot_381_1.X0 = &fEM_A8MC01RSP;
  S_asmot_381_1.V0 = &fEM_A8MV01RSP;
  S_asmot_364_1.XYvk = &fEM_B8MC01RC1;
  S_asmot_364_1.Vzvk = &fEM_B8MV01RC1;
  S_asmot_364_1.Vm = &fEM_B8UV80RDU;
  S_asmot_364_1.Tp = &fEM_B8US80RDU;
  S_asmot_364_1.Ter = &iEM_TERMAZ2;
  S_asmot_364_1.KPav = &fEM_B8UC10RIM;
  S_asmot_364_1.KZav = &fEM_B8UC20RIM;
  S_asmot_364_1.KPv = &fEM_B8UC11RIM;
  S_asmot_364_1.KZv = &fEM_B8UC21RIM;
  S_asmot_364_1.Dlt = &fEM_B8UC08RDU;
  S_asmot_364_1.X0 = &fEM_B8MC01RSP;
  S_asmot_364_1.V0 = &fEM_B8MV01RSP;
  S_asmot_1167_1.XYvk = &fEM_R4MC01RC1;
  S_asmot_1167_1.Vzvk = &fEM_R4MV01RC1;
  S_asmot_1167_1.Vm = &fEM_R4UV80RDU;
  S_asmot_1167_1.Tp = &fEM_R4US80RDU;
  S_asmot_1167_1.Ter = &iEM_TERTLG;
  S_asmot_1167_1.KPav = &fEM_R4UC10RIM;
  S_asmot_1167_1.KZav = &fEM_R4UC20RIM;
  S_asmot_1167_1.KPv = &fEM_R4UC10RIM;
  S_asmot_1167_1.KZv = &fEM_R4UC20RIM;
  S_asmot_1167_1.Dlt = &fEM_R4UC08RDU;
  S_asmot_1167_1.X0 = &fEM_R4MC01RSP;
  S_asmot_1167_1.V0 = &fEM_R4MV01RSP;
  S_azbars_180_1.RIt = &fEM_R0UR30RIM;
  S_azbars_180_1.IsANI = &lEM_R8AD10LC1;
  S_azbars_180_1.Lg = &fEM_R0UL01RIM;
  S_azbars_180_1.Bz = &fEM_R0UN02RIM;
  S_azbars_180_1.AT = &fEM_R0UT01RIM;
  S_azbars_180_1.MT = &fEM_R0UT02RIM;
  S_azbars_180_1.CT = &fEM_R0UT04RIM;
  S_azbars_180_1.EN = &fEM_R0UT05RIM;
  S_azbars_180_1.EVt = &fEM_R0UH05RSS;
  S_azbars_180_1.Sani = &fEM_A0UN02RIM;
  S_azbars_180_1.Sno = &fEM_A0UN01RIM;
  S_azbars_180_1.ABB0 = &fEM_A1UR00RIM;
  S_azbars_180_1.ABB1 = &fEM_A1UR01RIM;
  S_azbars_180_1.ARB0 = &fEM_A2UR00RIM;
  S_azbars_180_1.ARB1 = &fEM_A2UR01RIM;
  S_azbars_180_1.AIS0 = &fEM_A3UR00RIM;
  S_azbars_180_1.AIS1 = &fEM_A3UR01RIM;
  S_azbars_180_1.Tn0 = &fEM_R0UT03RIM;
  S_azbars_180_1.RBlow = &fEM_R0UT06RIM;
  S_azbars_180_1.N0 = &fEM_A0UR02RSP;
  S_azbars_180_1.R0 = &fEM_A0UR01RSP;
  S_azbars_180_1.T0 = &fEM_B0UT03RSP;
  S_orrsim_301_1.Xk = &fEM_B3MC01RC1;
  S_orrsim_301_1.Shk = &fEM_B3MC02RC1;
  S_orrsim_301_1.IRV = &fEM_B3MV01RC1;
  S_orrsim_301_1.IShV = &fEM_B3MV02RC1;
  S_orrsim_301_1.Kpr = &fEM_A3UC02RDU;
  S_orrsim_301_1.Pdw = &fEM_A3UP01RIM;
  S_orrsim_301_1.Ldemp = &fEM_A3UG01RDU;
  S_orrsim_301_1.Tau = &fEM_A3US07RDU;
  S_orrsim_301_1.Aps = &fEM_A3UV02RIM;
  S_orrsim_301_1.Ter = &iEM_TERIS2;
  S_orrsim_301_1.KPpv = &fEM_A3UC04RIM;
  S_orrsim_301_1.KPav = &fEM_A3UC05RIM;
  S_orrsim_301_1.KZav = &fEM_A3UC06RIM;
  S_orrsim_301_1.Dlt = &fEM_A3UC08RIM;
  S_orrsim_301_1.X0 = &fEM_B3MC01RSP;
  S_orrsim_301_1.Sh0 = &fEM_B3MC02RSP;
  S_orrsim_301_1.RV0 = &fEM_B3MV01RSP;
  S_orrsim_301_1.ShV0 = &fEM_B3MV02RSP;
  S_orrsim_130_1.Xk = &fEM_A3MC01RC1;
  S_orrsim_130_1.Shk = &fEM_A3MC02RC1;
  S_orrsim_130_1.IRV = &fEM_A3MV01RC1;
  S_orrsim_130_1.IShV = &fEM_A3MV02RC1;
  S_orrsim_130_1.Kpr = &fEM_A3UC02RDU;
  S_orrsim_130_1.Pdw = &fEM_A3UP01RIM;
  S_orrsim_130_1.Ldemp = &fEM_A3UG01RDU;
  S_orrsim_130_1.Tau = &fEM_A3US07RDU;
  S_orrsim_130_1.Aps = &fEM_A3UV02RIM;
  S_orrsim_130_1.Ter = &iEM_TERIS1;
  S_orrsim_130_1.KPpv = &fEM_A3UC04RIM;
  S_orrsim_130_1.KPav = &fEM_A3UC05RIM;
  S_orrsim_130_1.KZav = &fEM_A3UC06RIM;
  S_orrsim_130_1.Dlt = &fEM_A3UC08RIM;
  S_orrsim_130_1.X0 = &fEM_A3MC01RSP;
  S_orrsim_130_1.Sh0 = &fEM_A3MC02RSP;
  S_orrsim_130_1.RV0 = &fEM_A3MV01RSP;
  S_orrsim_130_1.ShV0 = &fEM_A3MV02RSP;
  S_orrsim_265_1.Xk = &fEM_B2MC01RC1;
  S_orrsim_265_1.Shk = &fEM_B2MC02RC1;
  S_orrsim_265_1.IRV = &fEM_B2MV01RC1;
  S_orrsim_265_1.IShV = &fEM_B2MV02RC1;
  S_orrsim_265_1.Kpr = &fEM_A2UC02RDU;
  S_orrsim_265_1.Pup = &fEM_A2UP02RIM;
  S_orrsim_265_1.Pdw = &fEM_A2UP01RIM;
  S_orrsim_265_1.Ldemp = &fEM_A2UG01RDU;
  S_orrsim_265_1.Tau = &fEM_A2US07RDU;
  S_orrsim_265_1.Aps = &fEM_A2UV02RIM;
  S_orrsim_265_1.Ter = &iEM_TERRB2;
  S_orrsim_265_1.KPpv = &fEM_A2UC04RIM;
  S_orrsim_265_1.KPav = &fEM_A2UC05RIM;
  S_orrsim_265_1.KZav = &fEM_A2UC06RIM;
  S_orrsim_265_1.Dlt = &fEM_A2UC08RIM;
  S_orrsim_265_1.X0 = &fEM_B2MC01RSP;
  S_orrsim_265_1.Sh0 = &fEM_B2MC02RSP;
  S_orrsim_265_1.RV0 = &fEM_B2MV01RSP;
  S_orrsim_265_1.ShV0 = &fEM_B2MV02RSP;
  S_orrsim_97_1.Xk = &fEM_A2MC01RC1;
  S_orrsim_97_1.Shk = &fEM_A2MC02RC1;
  S_orrsim_97_1.IRV = &fEM_A2MV01RC1;
  S_orrsim_97_1.IShV = &fEM_A2MV02RC1;
  S_orrsim_97_1.Kpr = &fEM_A2UC02RDU;
  S_orrsim_97_1.Pup = &fEM_A2UP02RIM;
  S_orrsim_97_1.Pdw = &fEM_A2UP01RIM;
  S_orrsim_97_1.Ldemp = &fEM_A2UG01RDU;
  S_orrsim_97_1.Tau = &fEM_A2US07RDU;
  S_orrsim_97_1.Aps = &fEM_A2UV02RIM;
  S_orrsim_97_1.Ter = &iEM_TERRB1;
  S_orrsim_97_1.KPpv = &fEM_A2UC04RIM;
  S_orrsim_97_1.KPav = &fEM_A2UC05RIM;
  S_orrsim_97_1.KZav = &fEM_A2UC06RIM;
  S_orrsim_97_1.Dlt = &fEM_A2UC08RIM;
  S_orrsim_97_1.X0 = &fEM_A2MC01RSP;
  S_orrsim_97_1.Sh0 = &fEM_A2MC02RSP;
  S_orrsim_97_1.RV0 = &fEM_A2MV01RSP;
  S_orrsim_97_1.ShV0 = &fEM_A2MV02RSP;
  S_orrsim_227_1.Xk = &fEM_B1MC01RC1;
  S_orrsim_227_1.Shk = &fEM_B1MC02RC1;
  S_orrsim_227_1.IRV = &fEM_B1MV01RC1;
  S_orrsim_227_1.IShV = &fEM_B1MV02RC1;
  S_orrsim_227_1.Kpr = &fEM_A1UC02RDU;
  S_orrsim_227_1.Pdw = &fEM_A1UP01RIM;
  S_orrsim_227_1.Ldemp = &fEM_A1UG01RDU;
  S_orrsim_227_1.Tau = &fEM_A1US07RDU;
  S_orrsim_227_1.Aps = &fEM_A1UV02RIM;
  S_orrsim_227_1.Ter = &iEM_TERBB2;
  S_orrsim_227_1.KPpv = &fEM_A1UC04RIM;
  S_orrsim_227_1.KPav = &fEM_A1UC05RIM;
  S_orrsim_227_1.KZav = &fEM_A1UC06RIM;
  S_orrsim_227_1.Dlt = &fEM_A1UC08RIM;
  S_orrsim_227_1.X0 = &fEM_B1MC01RSP;
  S_orrsim_227_1.Sh0 = &fEM_B1MC02RSP;
  S_orrsim_227_1.RV0 = &fEM_B1MV01RSP;
  S_orrsim_227_1.ShV0 = &fEM_B1MV02RSP;
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
  S_orrsim_59_1.RV0 = &fEM_A1MV01RSP;
  S_orrsim_59_1.ShV0 = &fEM_A1MV02RSP;
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
  for( i=0;i<2;i++ )
    array_m1082_tst_1[i] = &(&internal1_m1082_tst)[i];
  for( i=0;i<2;i++ )
    array_m1082_trz_1[i] = &(&internal1_m1082_trz)[i];
  for( i=0;i<2;i++ )
    array_m1082_N1_1[i] = &(&internal1_m1082_N1)[i];
  for( i=0;i<2;i++ )
    array_m1082_N2_1[i] = &(&internal1_m1082_N2)[i];
  for( i=0;i<2;i++ )
    array_m1024_tst_1[i] = &(&internal1_m1024_tst)[i];
  for( i=0;i<2;i++ )
    array_m1024_trz_1[i] = &(&internal1_m1024_trz)[i];
  for( i=0;i<2;i++ )
    array_m1024_N1_1[i] = &(&internal1_m1024_N1)[i];
  for( i=0;i<2;i++ )
    array_m1024_N2_1[i] = &(&internal1_m1024_N2)[i];
  for( i=0;i<2;i++ )
    array_m896_tst_1[i] = &(&internal1_m896_tst)[i];
  for( i=0;i<2;i++ )
    array_m896_trz_1[i] = &(&internal1_m896_trz)[i];
  for( i=0;i<2;i++ )
    array_m896_N1_1[i] = &(&internal1_m896_N1)[i];
  for( i=0;i<2;i++ )
    array_m896_N2_1[i] = &(&internal1_m896_N2)[i];
  for( i=0;i<2;i++ )
    array_m841_tst_1[i] = &(&internal1_m841_tst)[i];
  for( i=0;i<2;i++ )
    array_m841_trz_1[i] = &(&internal1_m841_trz)[i];
  for( i=0;i<2;i++ )
    array_m841_N1_1[i] = &(&internal1_m841_N1)[i];
  for( i=0;i<2;i++ )
    array_m841_N2_1[i] = &(&internal1_m841_N2)[i];
  for( i=0;i<6;i++ )
    array_m180_C0_1[i] = &(&internal1_m180_C0)[i];
  for( i=0;i<6;i++ )
    array_m14_C0_1[i] = &(&internal1_m14_C0)[i];
  array_m1179_x_1[0] = &lEM_R0IE02LRP;
  array_m1179_x_1[1] = &lEM_R0IE01LRP;
  array_m639_x_1[0] = &lEM_C1AD31LRP;
  array_m301_Vr_1[1] = &fEM_R0UV81RDU;
  array_m301_Vr_1[2] = &fEM_R0UV82RDU;
  array_m301_Vr_1[3] = &fEM_R0UV83RDU;
  array_m301_Vr_1[4] = &fEM_R0UV84RDU;
  array_m301_Vr_1[5] = &fEM_R0UV85RDU;
  array_m301_Vr_1[6] = &fEM_R0UV86RDU;
  array_m301_Vr_1[7] = &fEM_R0UV87RDU;
  array_m130_Vr_1[1] = &fEM_R0UV81RDU;
  array_m130_Vr_1[2] = &fEM_R0UV82RDU;
  array_m130_Vr_1[3] = &fEM_R0UV83RDU;
  array_m130_Vr_1[4] = &fEM_R0UV84RDU;
  array_m130_Vr_1[5] = &fEM_R0UV85RDU;
  array_m130_Vr_1[6] = &fEM_R0UV86RDU;
  array_m130_Vr_1[7] = &fEM_R0UV87RDU;
  array_m265_Vr_1[1] = &fEM_R0UV81RDU;
  array_m265_Vr_1[2] = &fEM_R0UV82RDU;
  array_m265_Vr_1[3] = &fEM_R0UV83RDU;
  array_m265_Vr_1[4] = &fEM_R0UV84RDU;
  array_m265_Vr_1[5] = &fEM_R0UV85RDU;
  array_m265_Vr_1[6] = &fEM_R0UV86RDU;
  array_m265_Vr_1[7] = &fEM_R0UV87RDU;
  array_m97_Vr_1[1] = &fEM_R0UV81RDU;
  array_m97_Vr_1[2] = &fEM_R0UV82RDU;
  array_m97_Vr_1[3] = &fEM_R0UV83RDU;
  array_m97_Vr_1[4] = &fEM_R0UV84RDU;
  array_m97_Vr_1[5] = &fEM_R0UV85RDU;
  array_m97_Vr_1[6] = &fEM_R0UV86RDU;
  array_m97_Vr_1[7] = &fEM_R0UV87RDU;
  array_m227_Vr_1[1] = &fEM_R0UV81RDU;
  array_m227_Vr_1[2] = &fEM_R0UV82RDU;
  array_m227_Vr_1[3] = &fEM_R0UV83RDU;
  array_m227_Vr_1[4] = &fEM_R0UV84RDU;
  array_m227_Vr_1[5] = &fEM_R0UV85RDU;
  array_m227_Vr_1[6] = &fEM_R0UV86RDU;
  array_m227_Vr_1[7] = &fEM_R0UV87RDU;
  array_m59_Vr_1[1] = &fEM_R0UV81RDU;
  array_m59_Vr_1[2] = &fEM_R0UV82RDU;
  array_m59_Vr_1[3] = &fEM_R0UV83RDU;
  array_m59_Vr_1[4] = &fEM_R0UV84RDU;
  array_m59_Vr_1[5] = &fEM_R0UV85RDU;
  array_m59_Vr_1[6] = &fEM_R0UV86RDU;
  array_m59_Vr_1[7] = &fEM_R0UV87RDU;
}
