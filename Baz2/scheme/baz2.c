#include "baz2.h"
extern  func_ext1();
// ��
//  ��������� ���������� ����� D:\md\pti\pr\Baz2\scheme\baz2.tpr

#define PBLENGTH 8192
#ifndef SIMUL_MODE
char EEPROMType = 2;/*0 - absent, 1 - external, 2 - internal, 3 - misc*/
#else
char *SchemaName = "D:\md\pti\pr\Baz2\scheme\baz2.tpr";
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
#include <and2.h>
#include <and3.h>
#include <bol.h>
#include <drg.h>
#include <geterr.h>
#include <ma.h>
#include <noto.h>
#include <or2.h>
#include <or3.h>
#include <orn.h>
#include <ornc.h>
#include <orni.h>
#include <ovb1.h>
#include <react.h>
#include <rsu.h>
#include <scalzz.h>
#include <schl24.h>
#include <srm.h>
#include <tprg.h>
#include <zpfs.h>
#include <zzfs.h>

/* ����������� ���������� ���������� */
#define bFirstEnterFlag (*((psbool)(InternalBuf+0x0)))
#define internal1_m244_tx (*((psfloat)(InternalBuf+0x2))) /*tx - ����� ����������� ���*/
#define internal1_m244_y0 (*((pschar)(InternalBuf+0x7))) /*y0*/
#define internal1_m315_tx (*((psfloat)(InternalBuf+0x9))) /*tx - ����� ����������� ���*/
#define internal1_m315_y0 (*((pschar)(InternalBuf+0xE))) /*y0*/
#define internal1_m212_tx (*((psfloat)(InternalBuf+0x10))) /*tx - ����� ����������� ���*/
#define internal1_m212_y0 (*((pschar)(InternalBuf+0x15))) /*y0*/
#define internal1_m210_tx (*((psfloat)(InternalBuf+0x17))) /*tx - ����� ����������� ���*/
#define internal1_m210_y0 (*((pschar)(InternalBuf+0x1C))) /*y0*/
#define internal1_m252_tx (*((psfloat)(InternalBuf+0x1E))) /*tx - ����� ����������� ���*/
#define internal1_m252_y0 (*((pschar)(InternalBuf+0x23))) /*y0*/
#define internal1_m208_tx (*((psfloat)(InternalBuf+0x25))) /*tx - ����� ����������� ���*/
#define internal1_m208_y0 (*((pschar)(InternalBuf+0x2A))) /*y0*/
#define internal1_m206_tx (*((psfloat)(InternalBuf+0x2C))) /*tx - ����� ����������� ���*/
#define internal1_m206_y0 (*((pschar)(InternalBuf+0x31))) /*y0*/
#define internal1_m33_tx (*((psint)(InternalBuf+0x33))) /*tx - ���������� ��������*/
#define internal1_m143_y0 (*((psfloat)(InternalBuf+0x36))) /*y0*/
#define internal1_m141_y0 (*((psfloat)(InternalBuf+0x3B))) /*y0*/
#define internal1_m93_y0 (*((psfloat)(InternalBuf+0x40))) /*y0*/
#define internal1_m91_y0 (*((psfloat)(InternalBuf+0x45))) /*y0*/
#define internal1_m154_y1 (*((psbool)(InternalBuf+0x4A))) /*y1 - ���������� ��������*/
#define internal1_m165_y1 (*((psbool)(InternalBuf+0x4C))) /*y1 - ���������� ��������*/
#define internal1_m308_q0 (*((pslong)(InternalBuf+0x4E))) /*q0 - ���������� ��������*/
#define internal1_m129_y0 (*((psbool)(InternalBuf+0x53))) /*state*/
#define internal1_m123_y0 (*((psbool)(InternalBuf+0x55))) /*state*/
#define internal1_m107_y1 (*((psbool)(InternalBuf+0x57))) /*y1 - ���������� ��������*/
#define internal1_m120_y1 (*((psbool)(InternalBuf+0x59))) /*y1 - ���������� ��������*/
#define internal1_m97_y1 (*((psbool)(InternalBuf+0x5B))) /*y1 - ���������� ��������*/
#define internal1_m105_y1 (*((psbool)(InternalBuf+0x5D))) /*y1 - ���������� ��������*/
#define internal1_m153_y1 (*((psbool)(InternalBuf+0x5F))) /*y1 - ���������� ��������*/
#define internal1_m162_y1 (*((psbool)(InternalBuf+0x61))) /*y1 - ���������� ��������*/
int InternalBufSize = 99;

/* ����������� �������� */
#define signal_A0IT02IZ2     (*((psint)(PBSTART+0x0)))  /*                       ����������� ��1-2 */
#define signal_A0CT01IZ2     (*((psfloat)(PBSTART+0x3)))  /*                       ����������� ��1-1 */
#define signal_A0VT61LZ2     (*((psbool)(PBSTART+0x8)))  /*                       �� �� ����������� � ��1 */
#define signal_A0VT71LZ2     (*((psbool)(PBSTART+0xa)))  /*                       �� �� ����������� � ��1 */
#define signal_A1VP41LZ2     (*((psbool)(PBSTART+0xc)))  /*                       �������� ����� ��1 ���� �� */
#define signal_B1VP41LZ2     (*((psbool)(PBSTART+0xe)))  /*                       �������� ����� ��2 ���� �� */
#define signal_B1VP81LZZ     (*((psbool)(PBSTART+0x10)))  /*                       �������� ����� ��2 � ����� */
#define signal_A1VP81LZZ     (*((psbool)(PBSTART+0x12)))  /*                       �������� ����� ��1 � ����� */
#define signal_A2VP41LZ2     (*((psbool)(PBSTART+0x14)))  /*                       �������� ����� ��1 ���� �� */
#define signal_A2CP01RZ2     (*((psfloat)(PBSTART+0x16)))  /*                       ������� �������� ����� ��1 */
#define signal_A2VP51LZ2     (*((psbool)(PBSTART+0x1b)))  /*                       �������� ����� ��1 ���� �� */
#define signal_B2VP41LZ2     (*((psbool)(PBSTART+0x1d)))  /*                       �������� ����� ��2 ���� �� */
#define signal_B2CP01RZ2     (*((psfloat)(PBSTART+0x1f)))  /*                       ������� �������� ����� ��2 */
#define signal_B2VP51LZ2     (*((psbool)(PBSTART+0x24)))  /*                       �������� ����� ��2 ���� �� */
#define signal_B2VP81LZ2     (*((psbool)(PBSTART+0x26)))  /*                       �������� ����� ��2 � ����� */
#define signal_A2VP81LZ2     (*((psbool)(PBSTART+0x28)))  /*                       �������� ����� ��1 � ����� */
#define signal_A2IP01IZ2     (*((psint)(PBSTART+0x2a)))  /*                       ������� �������� ����� ��1 */
#define signal_B2IP01IZ2     (*((psint)(PBSTART+0x2d)))  /*                       ������� �������� ����� ��2 */
#define signal_R0ET01LZ2     (*((psbool)(PBSTART+0x30)))  /*                       ������� ������� ������������� �� �����������  ��1 */
#define signal_B0IT02IZ2     (*((psint)(PBSTART+0x32)))  /*                       ����������� ��2-2 */
#define signal_A0VP41LZ2     (*((psbool)(PBSTART+0x35)))  /*                       �������� ��1 ���� �� */
#define signal_B0VP41LZ2     (*((psbool)(PBSTART+0x37)))  /*                       �������� ��2 ���� �� */
#define signal_B0VP81LZZ     (*((psbool)(PBSTART+0x39)))  /*                       �������� ��2 � ����� */
#define signal_A0VP81LZZ     (*((psbool)(PBSTART+0x3b)))  /*                       ��������  ��1 � ����� */
#define signal_R0ET02LZ2     (*((psbool)(PBSTART+0x3d)))  /*                       ������� ������� ������������� �� ����������� ��2 */
#define signal_B0EP02IZ2     (*((psint)(PBSTART+0x3f)))  /*                       ��������� -��������  ��2 ���� �� */
#define signal_A0EP02IZ2     (*((psint)(PBSTART+0x42)))  /*                       ��������� -��������  ��1 ���� �� */
#define signal_A0VP71LZ2     (*((psbool)(PBSTART+0x45)))  /*                       �� �� �� ������ �������� ��� ��1 */
#define signal_B0VP71LZ2     (*((psbool)(PBSTART+0x47)))  /*                       �� �� �� ������ �������� ��� ��2 */
#define signal_R0VN02RS1     (*((psfloat)(PBSTART+0x49)))  /*                       ������� �������� ����� 1 */
#define signal_R0VN02RS2     (*((psfloat)(PBSTART+0x4e)))  /*                       ������� �������� ����� 2 */
#define signal_R0VN02RS3     (*((psfloat)(PBSTART+0x53)))  /*                       ������� �������� ����� 3 */
#define signal_R0VN02RS4     (*((psfloat)(PBSTART+0x58)))  /*                       ������� �������� ����� 4 */
#define signal_R0VN01RS1     (*((psfloat)(PBSTART+0x5d)))  /*                       ������ ������� ����� 1 */
#define signal_R0VN01RS2     (*((psfloat)(PBSTART+0x62)))  /*                       ������ ������� ����� 2 */
#define signal_R0VN01RS3     (*((psfloat)(PBSTART+0x67)))  /*                       ������ ������� ����� 3 */
#define signal_R0VN01RS4     (*((psfloat)(PBSTART+0x6c)))  /*                       ������ ������� ����� 4 */
#define signal_R0VN61LS1     (*((psbool)(PBSTART+0x71)))  /*                       �� �� �������� ����� 1 */
#define signal_R0VN61LS2     (*((psbool)(PBSTART+0x73)))  /*                       �� �� �������� ����� 2 */
#define signal_R0VN61LS3     (*((psbool)(PBSTART+0x75)))  /*                       �� �� �������� ����� 3 */
#define signal_R0VN61LS4     (*((psbool)(PBSTART+0x77)))  /*                       �� �� �������� ����� 4 */
#define signal_R0VN65LS1     (*((psbool)(PBSTART+0x79)))  /*                       �� �� ������� ������� ����� 1 */
#define signal_R0VN65LS2     (*((psbool)(PBSTART+0x7b)))  /*                       �� �� ������� �������  ����� 2 */
#define signal_R0VN65LS3     (*((psbool)(PBSTART+0x7d)))  /*                       �� �� ������� ������� ����� 3 */
#define signal_R0VN65LS4     (*((psbool)(PBSTART+0x7f)))  /*                       �� �� ������� ������� ����� 4 */
#define signal_R0VN01RZ2     (*((psfloat)(PBSTART+0x81)))  /*                       ������� �������� �� ������ 1 */
#define signal_R0VN02RZ2     (*((psfloat)(PBSTART+0x86)))  /*                       ������� �������� �� ������ 2 */
#define signal_R0VN03RZ2     (*((psfloat)(PBSTART+0x8b)))  /*                       ������� �������� �� ������ 3 */
#define signal_R0VN04RZ2     (*((psfloat)(PBSTART+0x90)))  /*                       ������� �������� �� ������ 4 */
#define signal_R0VN05RZ2     (*((psfloat)(PBSTART+0x95)))  /*                       ������ ������� �� ������ 1 */
#define signal_R0VN06RZ2     (*((psfloat)(PBSTART+0x9a)))  /*                       ������ ������� �� ������ 2 */
#define signal_R0VN07RZ2     (*((psfloat)(PBSTART+0x9f)))  /*                       ������ ������� �� ������ 3 */
#define signal_R0VN08RZ2     (*((psfloat)(PBSTART+0xa4)))  /*                       ������ ������� �� ������ 4 */
#define signal_R0VN61LZ2     (*((psbool)(PBSTART+0xa9)))  /*                       �� �� �������� ����� 1 */
#define signal_R0VN62LZ2     (*((psbool)(PBSTART+0xab)))  /*                       �� �� �������� ����� 2 */
#define signal_R0VN63LZ2     (*((psbool)(PBSTART+0xad)))  /*                       �� �� �������� ����� 3 */
#define signal_R0VN64LZ2     (*((psbool)(PBSTART+0xaf)))  /*                       �� �� �������� ����� 4 */
#define signal_R0VN65LZ2     (*((psbool)(PBSTART+0xb1)))  /*                       �� �� ������� ������� ����� 1 */
#define signal_R0VN66LZ2     (*((psbool)(PBSTART+0xb3)))  /*                       �� �� ������� ������� ����� 2 */
#define signal_R0VN67LZ2     (*((psbool)(PBSTART+0xb5)))  /*                       �� �� ������� ������� ����� 3 */
#define signal_R0VN68LZ2     (*((psbool)(PBSTART+0xb7)))  /*                       �� �� ������� ������� ����� 4 */
#define signal_R0VN09RZ2     (*((psfloat)(PBSTART+0xb9)))  /*                       ����������� ������ ������� */
#define signal_A3IS11LDU     (*((psbool)(PBSTART+0xbe)))  /*                       ������ �� �� ��1 */
#define signal_A3IS22LDU     (*((psbool)(PBSTART+0xc0)))  /*                       ������ �� ��� ��1 */
#define signal_R0AD03LZ2     (*((psbool)(PBSTART+0xc2)))  /*                       �������� ������� �� �� �� */
#define signal_B3IS11LDU     (*((psbool)(PBSTART+0xc4)))  /*                       ������ �� �� ��2 */
#define signal_A3VZ31LZ2     (*((psbool)(PBSTART+0xc6)))  /*                       �� �� �� ��1 */
#define signal_B3VZ31LZ2     (*((psbool)(PBSTART+0xc8)))  /*                       �� �� �� ��2 */
#define signal_R0AD05LZ2     (*((psbool)(PBSTART+0xca)))  /*                       �������� ����� � ��� �� */
#define signal_A3VZ11LZ2     (*((psbool)(PBSTART+0xcc)))  /*                       �� �� ��� ��1 */
#define signal_B3VZ11LZ2     (*((psbool)(PBSTART+0xce)))  /*                       �� �� ��� ��2 */
#define signal_B3IS22LDU     (*((psbool)(PBSTART+0xd0)))  /*                       ������ �� ��� ��2 */
#define signal_R0VN69LZ2     (*((psbool)(PBSTART+0xd2)))  /*                       �� �� ������������ ������� */
#define signal_R0VN79LZ2     (*((psbool)(PBSTART+0xd4)))  /*                       �� �� ������������ ������� */
#define signal_R0VR02RZ2     (*((psfloat)(PBSTART+0xd6)))  /*                       ����������� ������������ */
#define signal_R0VZ71LZ2     (*((psbool)(PBSTART+0xdb)))  /*                       ���������� ������ �� 2 ������ */
#define signal_R0VN70LZ2     (*((psbool)(PBSTART+0xdd)))  /*                       �� �� �� �������� �� */
#define signal_R0VN80LZ2     (*((psbool)(PBSTART+0xdf)))  /*                       �� �� �� ������� ������� �� */
#define signal_A1EE01LS1     (*((psbool)(PBSTART+0xe1)))  /*                       ����������� ���� ����� 1 */
#define signal_A1EE01LS4     (*((psbool)(PBSTART+0xe3)))  /*                       ����������� ���� ����� 4 */
#define signal_A1EE01LS3     (*((psbool)(PBSTART+0xe5)))  /*                       ����������� ���� ����� 3 */
#define signal_A0EE01LZ2     (*((psbool)(PBSTART+0xe7)))  /*                       ����������� ����1 */
#define signal_A0EE04LZ2     (*((psbool)(PBSTART+0xe9)))  /*                       ����������� ����4 */
#define signal_A0EE02LZ2     (*((psbool)(PBSTART+0xeb)))  /*                       ����������� ����2 */
#define signal_A0EE03LZ2     (*((psbool)(PBSTART+0xed)))  /*                       ����������� ����3 */
#define signal_A1EE01LS2     (*((psbool)(PBSTART+0xef)))  /*                       ����������� ����  ����� 2 */
#define signal_A0EE05LZ2     (*((psbool)(PBSTART+0xf1)))  /*                       ����������� ���� ����1 */
#define signal_A0EE06LZ2     (*((psbool)(PBSTART+0xf3)))  /*                       ����������� ���� ����2 */
#define signal_A0EE07LZ2     (*((psbool)(PBSTART+0xf5)))  /*                       ����������� ���� ����3 */
#define signal_A0EE08LZ2     (*((psbool)(PBSTART+0xf7)))  /*                       ����������� ���� ����4 */
#define signal_A0VZ71LZ2     (*((psbool)(PBSTART+0xf9)))  /*                       ���������� ������ �� �� ��1 */
#define signal_A0EE00LZ2     (*((psbool)(PBSTART+0xfb)))  /*                       ����������� ���� ��1 */
#define signal_B0EE00LZ2     (*((psbool)(PBSTART+0xfd)))  /*                       ����������� ���� ��2 */
#define signal_B0VZ71LZ2     (*((psbool)(PBSTART+0xff)))  /*                       ���������� ������ �� �� ��2 */
#define signal_A0VN71LZ2     (*((psbool)(PBSTART+0x101)))  /*                       �� �� �� ��������  ��1 */
#define signal_B0VN71LZ2     (*((psbool)(PBSTART+0x103)))  /*                       �� �� �� ��������  ��2 */
#define signal_A0VN81LZ2     (*((psbool)(PBSTART+0x105)))  /*                       �� �� �� ������� ������� ��1 */
#define signal_B0VN81LZ2     (*((psbool)(PBSTART+0x107)))  /*                       �� �� �� ������� ������� ��2 */
#define signal_R0VZ05UZ2     (*((pslong)(PBSTART+0x109)))  /*                       ��������� ������� ������ */
#define signal_R0VN11RZ2     (*((psfloat)(PBSTART+0x10e)))  /*                       ������� �������� �� ���1 */
#define signal_R0VP73LZ2     (*((psbool)(PBSTART+0x113)))  /*                       �� �������� ��� �� */
#define signal_B0CT01IZ2     (*((psfloat)(PBSTART+0x115)))  /*                       ����������� ��2-1 */
#define signal_B0VT61LZ2     (*((psbool)(PBSTART+0x11a)))  /*                       �� �� ����������� � ��2 */
#define signal_B0VT71LZ2     (*((psbool)(PBSTART+0x11c)))  /*                       �� �� ����������� � ��2 */
#define signal_A1VN71LS1     (*((psbool)(PBSTART+0x11e)))  /*                       ���������� ��������������� ������� �� ����� 1 */
#define signal_A1VN71LS2     (*((psbool)(PBSTART+0x120)))  /*                       ���������� ��������������� ������� �� ����� 2 */
#define signal_A1VN71LS3     (*((psbool)(PBSTART+0x122)))  /*                       ���������� ��������������� ������� �� ����� 3 */
#define signal_A1VN71LS4     (*((psbool)(PBSTART+0x124)))  /*                       ���������� ��������������� ������� �� ����� 4 */
#define signal_A1VN71LZ2     (*((psbool)(PBSTART+0x126)))  /*                       ���������� ��������������� ������� �� */
#define signal_A3VZ15LZ2     (*((psbool)(PBSTART+0x128)))  /*                       �������� �� �� ��� �� */
#define signal_A3VZ13LZ2     (*((psbool)(PBSTART+0x12a)))  /*                       �������� �� �� �� �� */
#define signal_R0VW13LDU     (*((psbool)(PBSTART+0x12c)))  /*                       ��������� ������ ��1 ��� ��1+��2 */
#define signal_R0VW23LDU     (*((psbool)(PBSTART+0x12e)))  /*                       ��������� ������ ��2 ��� ��1+��2 */
#define signal_R7II73LZ2     (*((psbool)(PBSTART+0x130)))  /*                       ��������� �� II �� ��� */
#define signal_R7II71LZ2     (*((psbool)(PBSTART+0x132)))  /*                       ��������� �� I�� ��� (������ 1) */
#define signal_R7II72LZ2     (*((psbool)(PBSTART+0x134)))  /*                       ��������� �� I�� ��� (������ 2) */
#define signal_R0AD21LDU     (*((psbool)(PBSTART+0x136)))  /*                       ���������� ������ �� II �� */
#define signal_R0MD34LP1     (*((psbool)(PBSTART+0x138)))  /*                       ������ ����������� */
#define signal_R0AD14LDU     (*((psbool)(PBSTART+0x13a)))  /*                       �������� ������������ ������� �� II �� */
#define signal_R0AD16LDU     (*((psbool)(PBSTART+0x13c)))  /*                       �������� ������������ ������� �� I �� */
#define signal_R6IS66LZZ     (*((psbool)(PBSTART+0x13e)))  /*                       ����������� ��� 4,0 (�5) ����-1-1 */
#define signal_R6IS67LZZ     (*((psbool)(PBSTART+0x140)))  /*                       ����������� ��� 4,0 (�6) ����-1-2 */
#define signal_R6IS68LZZ     (*((psbool)(PBSTART+0x142)))  /*                       ����������� ��� 4,0 (�7) ����-2 */
#define signal_R0VN71LZ2     (*((psbool)(PBSTART+0x144)))  /*                       �� �� �������� ����� 1 */
#define signal_R0VN75LZ2     (*((psbool)(PBSTART+0x146)))  /*                       �� �� ������� ������� ����� 1 */
#define signal_R0VN72LZ2     (*((psbool)(PBSTART+0x148)))  /*                       �� �� �������� ����� 2 */
#define signal_R0VN76LZ2     (*((psbool)(PBSTART+0x14a)))  /*                       �� �� ������� ������� �����  2 */
#define signal_R0VN73LZ2     (*((psbool)(PBSTART+0x14c)))  /*                       �� �� �������� ����� 3 */
#define signal_R0VN74LZ2     (*((psbool)(PBSTART+0x14e)))  /*                       �� �� �������� ����� 4 */
#define signal_R0VN77LZ2     (*((psbool)(PBSTART+0x150)))  /*                       �� �� ������� ������� �����  3 */
#define signal_R0VN78LZ2     (*((psbool)(PBSTART+0x152)))  /*                       �� �� ������� ������� �����  4 */
#define signal_R0AD04LZ2     (*((psbool)(PBSTART+0x154)))  /*                       �������� ������������ ������� �� II �� */
#define signal_R0EE01LZ2     (*((psbool)(PBSTART+0x156)))  /*                       �������  ����1  ��������� */
#define signal_R0EE02LZ2     (*((psbool)(PBSTART+0x158)))  /*                       �������  ����2  ��������� */
#define signal_R0EE03LZ2     (*((psbool)(PBSTART+0x15a)))  /*                       �������  ����3  ��������� */
#define signal_R0EE04LZ2     (*((psbool)(PBSTART+0x15c)))  /*                       �������  ����4  ��������� */
#define signal_R0AD14LZ2     (*((psbool)(PBSTART+0x15e)))  /*                       �������� �� �� II�� */
#define signal_R0AD15LZ2     (*((psbool)(PBSTART+0x160)))  /*                       �������� �� �� 1�� (������1) */
#define signal_R0AD16LZ2     (*((psbool)(PBSTART+0x162)))  /*                       �������� �� �� 1�� (������2) */
#define signal_R0MW12IP2     (*((psint)(PBSTART+0x164)))  /*                       ������������� ����� ������������ �� �� �� */
#define signal_A2IS12LDU     (*((psbool)(PBSTART+0x167)))  /*                       ������ ��1 �������� */
#define signal_B2IS12LDU     (*((psbool)(PBSTART+0x169)))  /*                       ������ ��2 �������� */
#define signal_R0EE02LDU     (*((psbool)(PBSTART+0x16b)))  /*                       �������  ����  ��������� */

/* ����������� �������� ��� � ������*/
struct      sbool  lRM_0_ = {    0,0}; /* A-������� ������� ��������� � */ 
struct      sbool  lRM_1_ = {    1,0}; /* B-������� ������� ��������� � */ 
struct      slong  dRM_0_ = {    0,0}; /* lx ���� ���� */ 
struct      schar  bRM_0_ = {    0,0}; /* cx ���� �������� */ 
struct       sint  iRM_0_ = {    0,0}; /* ix ���� ����� */ 
struct       sint  iRM_3_ = {    3,0}; /* N-����� ������ */ 
struct       sint  iRM_4_ = {    4,0}; /* n - ����������� ������� */ 
struct       sint  iRM_6_ = {    6,0}; /* N-����� ������ */ 
struct       sint  iRM_17_ = {   17,0}; /* n - ����������� ������� ������� �������� */ 
struct       sint  iRM_819_ = {  819,0}; /* a */ 
struct       sint  iRM_4095_ = { 4095,0}; /* b */ 
struct     sfloat  fRM_0_00001 = {0.00001,0}; /* X2 */ 
struct       sint  iRM_200_ = {  200,0}; /* tz - ������ ��������, 10-�� �� */ 
struct     sfloat  fRM_0_2 = {  0.2,0}; /* tz - ����� �������� ��� */ 
struct     sfloat  fRM_1_0 = {  1.0,0}; /* tz - ����� �������� ��� */ 
struct       sint  iRM_7_ = {    7,0}; /* n - N-����������� ������� x */ 
struct     sfloat  fRM_0_002 = {0.002,0}; /* x - ������ ������� ���������� */ 
struct     sfloat  fRM_0_005 = {0.005,0}; /* x - ������ ������� ���������� */ 
struct     sfloat  fRM_0_007 = {0.007,0}; /* x - ������ ������� ���������� */ 
struct     sfloat  fRM_0_01 = { 0.01,0}; /* x - ������ ������� ���������� */ 
struct     sfloat  fRM_0_015 = {0.015,0}; /* x - ������ ������� ���������� */ 
struct     sfloat  fRM_0_02 = { 0.02,0}; /* x - ������ ������� ���������� */ 
struct     sfloat  fRM_1_7 = {  1.7,0}; /* x - ������ ������� ���������� */ 
#define fEM_R0UT02RZZ  (*((psfloat)(SpaEEPROMBuf+0x0)))
#define fEM_R0UT01RZZ  (*((psfloat)(SpaEEPROMBuf+0x5)))
#define fEM_A2UP03RZZ  (*((psfloat)(SpaEEPROMBuf+0xA)))
#define fEM_A2UP04RZZ  (*((psfloat)(SpaEEPROMBuf+0xF)))
#define fEM_R0UT72RZZ  (*((psfloat)(SpaEEPROMBuf+0x14)))
#define fEM_R0UT71RZZ  (*((psfloat)(SpaEEPROMBuf+0x19)))
#define fEM_R0UT62RZZ  (*((psfloat)(SpaEEPROMBuf+0x1E)))
#define fEM_R0UT61RZZ  (*((psfloat)(SpaEEPROMBuf+0x23)))
#define fEM_A2UP41RZZ  (*((psfloat)(SpaEEPROMBuf+0x28)))
#define fEM_A2UP42RZZ  (*((psfloat)(SpaEEPROMBuf+0x2D)))
#define fEM_A2UP51RZZ  (*((psfloat)(SpaEEPROMBuf+0x32)))
#define fEM_A2UP81RZZ  (*((psfloat)(SpaEEPROMBuf+0x37)))
#define fEM_A2UP84RZZ  (*((psfloat)(SpaEEPROMBuf+0x3C)))
#define fEM_A2UP82RZZ  (*((psfloat)(SpaEEPROMBuf+0x41)))
#define fEM_A2UP52RZZ  (*((psfloat)(SpaEEPROMBuf+0x46)))
#define fEM_A2UP83RZZ  (*((psfloat)(SpaEEPROMBuf+0x4B)))
#define fEM_R0UR01RZZ  (*((psfloat)(SpaEEPROMBuf+0x50)))
#define fEM_R0UR04RZZ  (*((psfloat)(SpaEEPROMBuf+0x55)))
#define fEM_A1UL12RZZ  (*((psfloat)(SpaEEPROMBuf+0x5A)))
#define fEM_A1UL11RZZ  (*((psfloat)(SpaEEPROMBuf+0x5F)))
#define fEM_R7UI73RZZ  (*((psfloat)(SpaEEPROMBuf+0x64)))

int SpaEEPROMBufSize = 105;

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
struct sbool  var51;
struct sbool  var52;
struct sbool  var53;
struct sbool  var54;
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
struct sbool  var124;
struct sbool  var125;
struct sfloat  var126;
struct sfloat  var127;
struct sbool  var128;
struct sfloat  var129;
struct sfloat  var130;
struct sbool  var131;
struct sbool  var132;
struct sbool  var133;
struct sbool  var134;
struct sbool  var135;
struct sbool  var136;
struct sfloat  var137;
struct slong  var138;
struct slong  var139;
struct sbool  var140;
struct sbool  var141;
struct sbool  var142;
struct sbool  var143;
struct sbool  var144;
struct sbool  var145;
struct sbool  var146;
struct sbool  var147;
struct sbool  var148;
struct sfloat  var149;
struct sbool  var150;
struct sbool  var151;
struct sfloat  var152;
struct sbool  var153;
struct sbool  var154;
struct schar  var155;
struct sbool  var156;
struct schar  var157;
struct sbool  var158;
struct sbool  var159;
struct sbool  var160;
struct sbool  var161;
struct sbool  var162;
struct sbool  var163;
struct sbool  var164;
struct sbool  var165;
struct sbool  var166;
struct sbool  var167;
struct slong  vainSLong;
struct sfloat  vainSFloat;
struct sint  vainSInt;
struct sbool  vainSBool;
struct schar  vainSChar;
char  vainSText[] = "";

/* ���������� �������� */
psfloat  array_m184_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psfloat  array_m330_x_1[4] = {NULL,NULL,NULL,NULL};
psbool  array_m330_diag_1[4] = {&var5,&var6,&var7,&var8};
psbool  array_m310_x_1[17] = {&var76,&var37,&var38,&var87,&var19,&var30,&var154,&var39,&var46,&var47,&var85,&var23,&var29,&var156,&var43,&var44,&var45};
psbool  array_m16_x_1[6] = {&var80,&var85,&var29,&var23,&var98,&var156};
psbool  array_m36_x_1[6] = {&var87,&var19,&var30,&var154,&var78,&var98};
psfloat  array_m2_x_1[4] = {NULL,NULL,NULL,NULL};
psbool  array_m2_diag_1[4] = {&var5,&var6,&var7,&var8};
psbool  array_m3_x_1[3] = {&var105,&var136,&var9};
psbool  array_m12_x_1[3] = {&var104,&var12,&var106};

/* �������� �������� ��� �-�� */

/* ��� ���������� */
/* ���������� �������� */
_S_ma far S_ma_184_1 = {array_m184_x_1,NULL,&iRM_7_,&vainSFloat};
_S_and3 far S_and3_207_1 = {&var100,&var99,NULL,&var1};
_S_and3 far S_and3_211_1 = {&var97,&var96,NULL,&var2};
_S_and2 far S_and2_251_1 = {&var28,&var121,&var3};
_S_zzfs far S_zzfs_244_1 = {NULL,&fRM_1_0,&var4,NULL,NULL};
_S_and2 far S_and2_80_1 = {NULL,NULL,&var5};
_S_and2 far S_and2_82_1 = {NULL,NULL,&var6};
_S_and2 far S_and2_84_1 = {NULL,NULL,&var7};
_S_and2 far S_and2_86_1 = {NULL,NULL,&var8};
_S_or2 far S_or2_104_1 = {&var165,&var163,&var9};
_S_and2 far S_and2_133_1 = {&var158,&var134,&var10};
_S_and2 far S_and2_126_1 = {&var135,&var159,&var11};
_S_or2 far S_or2_110_1 = {&var160,&var161,&var12};
_S_or2 far S_or2_199_1 = {NULL,NULL,&var13};
_S_or2 far S_or2_201_1 = {NULL,NULL,&var14};
_S_or2 far S_or2_202_1 = {NULL,&var120,&var15};
_S_or2 far S_or2_204_1 = {&var119,NULL,&var16};
_S_and2 far S_and2_213_1 = {&var100,NULL,&var17};
_S_and2 far S_and2_215_1 = {&var99,NULL,&var18};
_S_or2 far S_or2_228_1 = {&var20,&var21,&var19};
_S_and3 far S_and3_229_1 = {&var115,&var18,&var17,&var20};
_S_and3 far S_and3_224_1 = {&var17,&var124,&var115,&var21};
_S_and3 far S_and3_225_1 = {&var18,&var125,&var115,&var22};
_S_or2 far S_or2_231_1 = {&var22,&var20,&var23};
_S_or2 far S_or2_243_1 = {NULL,&var101,&var24};
_S_or2 far S_or2_249_1 = {&var102,NULL,&var25};
_S_or2 far S_or2_255_1 = {&var103,NULL,&var26};
_S_or2 far S_or2_257_1 = {NULL,NULL,&var27};
_S_or3 far S_or3_250_1 = {&var34,&var25,&var24,&var28};
_S_or2 far S_or2_233_1 = {&var33,&var31,&var29};
_S_or2 far S_or2_232_1 = {&var32,&var33,&var30};
_S_and3 far S_and3_227_1 = {&var123,&var35,&var114,&var31};
_S_and3 far S_and3_226_1 = {&var36,&var122,&var114,&var32};
_S_and3 far S_and3_230_1 = {&var114,&var35,&var36,&var33};
_S_and2 far S_and2_256_1 = {&var27,&var26,&var34};
_S_and2 far S_and2_218_1 = {&var96,NULL,&var35};
_S_and2 far S_and2_216_1 = {&var97,NULL,&var36};
_S_and2 far S_and2_313_1 = {&var63,&var89,&var37};
_S_and2 far S_and2_311_1 = {&var51,&var89,&var38};
_S_and2 far S_and2_316_1 = {&var117,&var89,&var39};
_S_schl24 far S_schl24_332_1 = {NULL,NULL,NULL,NULL,&var40};
_S_or2 far S_or2_336_1 = {&var164,&var162,&var41};
_S_and2 far S_and2_323_1 = {&var113,&var112,&var42};
_S_and2 far S_and2_318_1 = {&var24,&var95,&var43};
_S_and2 far S_and2_319_1 = {&var25,&var95,&var44};
_S_and2 far S_and2_320_1 = {&var34,&var95,&var45};
_S_and2 far S_and2_314_1 = {&var64,&var89,&var46};
_S_and2 far S_and2_312_1 = {&var52,&var89,&var47};
_S_and2 far S_and2_288_1 = {&var89,&var51,&var48};
_S_or2 far S_or2_285_1 = {&var61,&var59,&var49};
_S_and2 far S_and2_294_1 = {&var60,&var89,&var50};
_S_or2 far S_or2_291_1 = {&var53,&var61,&var51};
_S_or2 far S_or2_293_1 = {&var53,&var59,&var52};
_S_and2 far S_and2_292_1 = {&var60,&var143,&var53};
_S_and2 far S_and2_289_1 = {&var89,&var52,&var54};
_S_or2 far S_or2_301_1 = {NULL,&var146,&var55};
_S_or2 far S_or2_302_1 = {NULL,&var145,&var56};
_S_or2 far S_or2_299_1 = {NULL,&var148,&var57};
_S_or2 far S_or2_300_1 = {NULL,&var147,&var58};
_S_and2 far S_and2_298_1 = {&var55,&var56,&var59};
_S_schl24 far S_schl24_296_1 = {&var57,&var58,&var55,&var56,&var60};
_S_and2 far S_and2_297_1 = {&var57,&var58,&var61};
_S_or2 far S_or2_284_1 = {&var71,&var75,&var62};
_S_or2 far S_or2_276_1 = {&var66,&var75,&var63};
_S_or2 far S_or2_278_1 = {&var66,&var71,&var64};
_S_and2 far S_and2_272_1 = {&var72,&var89,&var65};
_S_and2 far S_and2_277_1 = {&var72,&var144,&var66};
_S_and2 far S_and2_280_1 = {&var63,&var89,&var67};
_S_and2 far S_and2_281_1 = {&var89,&var64,&var68};
_S_or2 far S_or2_265_1 = {NULL,&var146,&var69};
_S_or2 far S_or2_266_1 = {NULL,&var145,&var70};
_S_and2 far S_and2_268_1 = {&var70,&var69,&var71};
_S_schl24 far S_schl24_270_1 = {&var74,&var73,&var69,&var70,&var72};
_S_or2 far S_or2_263_1 = {NULL,&var148,&var73};
_S_or2 far S_or2_264_1 = {NULL,&var147,&var74};
_S_and2 far S_and2_267_1 = {&var74,&var73,&var75};
_S_and2 far S_and2_317_1 = {&var118,&var89,&var76};
_S_or3 far S_or3_30_1 = {&var110,&var63,&var51,&var77};
_S_and2 far S_and2_31_1 = {&var77,&var89,&var78};
_S_or2 far S_or2_25_1 = {&var140,&var141,&var79};
_S_and2 far S_and2_19_1 = {&var81,&var89,&var80};
_S_or3 far S_or3_18_1 = {&var64,&var52,&var109,&var81};
_S_and2 far S_and2_6_1 = {&var6,&var8,&var82};
_S_or2 far S_or2_11_1 = {&var142,&var82,&var83};
_S_or2 far S_or2_10_1 = {&var88,&var142,&var84};
_S_or2 far S_or2_151_1 = {&var131,&var133,&var85};
_S_or2 far S_or2_35_1 = {NULL,NULL,&var86};
_S_or2 far S_or2_149_1 = {&var166,&var128,&var87};
_S_and2 far S_and2_5_1 = {&var7,&var5,&var88};
_S_and2 far S_and2_22_1 = {&var111,&var107,&var89};
_S_and2 far S_and2_179_1 = {&var116,&var150,&var90};
_S_and2 far S_and2_178_1 = {&var151,&var116,&var91};
_S_and2 far S_and2_187_1 = {NULL,NULL,&var92};
_S_and2 far S_and2_185_1 = {NULL,NULL,&var93};
_S_and2 far S_and2_181_1 = {NULL,NULL,&var94};
_S_zpfs far S_zpfs_315_1 = {&var42,&fRM_0_2,&var95,NULL,NULL};
_S_zpfs far S_zpfs_212_1 = {&var16,NULL,&var96,NULL,NULL};
_S_zpfs far S_zpfs_210_1 = {&var15,NULL,&var97,NULL,NULL};
_S_zpfs far S_zpfs_252_1 = {&var3,NULL,&var98,NULL,NULL};
_S_zpfs far S_zpfs_208_1 = {&var14,NULL,&var99,NULL,NULL};
_S_zpfs far S_zpfs_206_1 = {&var13,NULL,&var100,NULL,NULL};
_S_noto far S_noto_236_1 = {NULL,&var101};
_S_noto far S_noto_248_1 = {NULL,&var102};
_S_noto far S_noto_254_1 = {NULL,&var103};
_S_noto far S_noto_128_1 = {NULL,&var104};
_S_noto far S_noto_127_1 = {NULL,&var105};
_S_noto far S_noto_96_1 = {NULL,&var106};
_S_noto far S_noto_27_1 = {&var108,&var107};
_S_ovb1 far S_ovb1_33_1 = {&var86,&iRM_200_,&var108,NULL};
_S_noto far S_noto_14_1 = {&var83,&var109};
_S_noto far S_noto_13_1 = {&var84,&var110};
_S_noto far S_noto_24_1 = {NULL,&var111};
_S_noto far S_noto_325_1 = {NULL,&var112};
_S_noto far S_noto_324_1 = {NULL,&var113};
_S_noto far S_noto_217_1 = {NULL,&var114};
_S_noto far S_noto_214_1 = {NULL,&var115};
_S_bol far S_bol_174_1 = {&var152,&fRM_0_00001,&var116};
_S_noto far S_noto_321_1 = {&var83,&var117};
_S_noto far S_noto_322_1 = {&var84,&var118};
_S_noto far S_noto_198_1 = {NULL,&var119};
_S_noto far S_noto_197_1 = {NULL,&var120};
_S_noto far S_noto_245_1 = {&var4,&var121};
_S_noto far S_noto_222_1 = {NULL,&var122};
_S_noto far S_noto_221_1 = {NULL,&var123};
_S_noto far S_noto_220_1 = {NULL,&var124};
_S_noto far S_noto_219_1 = {NULL,&var125};
_S_scalzz far S_scalzz_143_1 = {NULL,&iRM_819_,&iRM_4095_,NULL,NULL,&var126,NULL};
_S_scalzz far S_scalzz_141_1 = {NULL,&iRM_819_,&iRM_4095_,NULL,NULL,&var127,NULL};
_S_geterr far S_geterr_145_1 = {&var127,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var128};
_S_scalzz far S_scalzz_93_1 = {NULL,&iRM_819_,&iRM_4095_,NULL,NULL,&var129,NULL};
_S_scalzz far S_scalzz_91_1 = {NULL,&iRM_819_,&iRM_4095_,NULL,NULL,&var130,NULL};
_S_drg far S_drg_154_1 = {&var126,&lRM_0_,&lRM_1_,NULL,NULL,&var131,NULL};
_S_drg far S_drg_165_1 = {&var126,&lRM_0_,&lRM_1_,NULL,NULL,&var132,NULL};
_S_geterr far S_geterr_147_1 = {&var126,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var133};
_S_noto far S_noto_134_1 = {&var160,&var134};
_S_noto far S_noto_125_1 = {&var165,&var135};
_S_noto far S_noto_95_1 = {NULL,&var136};
_S_srm far S_srm_330_1 = {array_m330_x_1,array_m330_diag_1,&iRM_4_,&iRM_3_,&var137,&vainSBool};
_S_rsu far S_rsu_308_1 = {NULL,&var139,&var138,NULL};
_S_orni far S_orni_310_1 = {array_m310_x_1,&iRM_17_,&vainSBool,&var139};
_S_orn far S_orn_16_1 = {array_m16_x_1,&iRM_6_,&var140};
_S_orn far S_orn_36_1 = {array_m36_x_1,&iRM_6_,&var141};
_S_noto far S_noto_7_1 = {&var153,&var142};
_S_noto far S_noto_287_1 = {&var49,&var143};
_S_noto far S_noto_282_1 = {&var62,&var144};
_S_noto far S_noto_271_1 = {NULL,&var145};
_S_noto far S_noto_275_1 = {NULL,&var146};
_S_noto far S_noto_274_1 = {NULL,&var147};
_S_noto far S_noto_269_1 = {NULL,&var148};
_S_react far S_react_170_1 = {&var152,&var149};
_S_bol far S_bol_175_1 = {NULL,&var152,&var150};
_S_bol far S_bol_173_1 = {NULL,&var152,&var151};
_S_srm far S_srm_2_1 = {array_m2_x_1,array_m2_diag_1,&iRM_4_,&iRM_3_,&var152,&var153};
_S_ornc far S_ornc_3_1 = {array_m3_x_1,&iRM_3_,&var154,&var155};
_S_ornc far S_ornc_12_1 = {array_m12_x_1,&iRM_3_,&var156,&var157};
_S_tprg far S_tprg_129_1 = {&var129,NULL,NULL,NULL,NULL,&var158,NULL};
_S_tprg far S_tprg_123_1 = {&var130,NULL,NULL,NULL,NULL,&var159,NULL};
_S_geterr far S_geterr_102_1 = {&var129,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var160};
_S_drg far S_drg_107_1 = {&var129,&lRM_1_,&lRM_0_,NULL,NULL,&var161,NULL};
_S_drg far S_drg_120_1 = {&var129,&lRM_1_,&lRM_0_,NULL,NULL,&var162,NULL};
_S_drg far S_drg_97_1 = {&var130,&lRM_1_,&lRM_0_,NULL,NULL,&var163,NULL};
_S_drg far S_drg_105_1 = {&var130,&lRM_1_,&lRM_0_,NULL,NULL,&var164,NULL};
_S_geterr far S_geterr_99_1 = {&var130,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var165};
_S_drg far S_drg_153_1 = {&var127,&lRM_0_,&lRM_1_,NULL,NULL,&var166,NULL};
_S_drg far S_drg_162_1 = {&var127,&lRM_0_,&lRM_1_,NULL,NULL,&var167,NULL};


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
  noto((&S_noto_269_1));
  noto((&S_noto_274_1));
  noto((&S_noto_275_1));
  noto((&S_noto_271_1));
  noto((&S_noto_95_1));
  scalzz((&S_scalzz_91_1));
  scalzz((&S_scalzz_93_1));
  scalzz((&S_scalzz_141_1));
  scalzz((&S_scalzz_143_1));
  noto((&S_noto_220_1));
  noto((&S_noto_221_1));
  noto((&S_noto_222_1));
  noto((&S_noto_197_1));
  noto((&S_noto_198_1));
  noto((&S_noto_214_1));
  noto((&S_noto_217_1));
  noto((&S_noto_96_1));
  noto((&S_noto_127_1));
  noto((&S_noto_128_1));
  noto((&S_noto_254_1));
  noto((&S_noto_248_1));
  noto((&S_noto_236_1));
  and2((&S_and2_181_1));
  and2((&S_and2_185_1));
  and2((&S_and2_187_1));
  or2((&S_or2_264_1));
  or2((&S_or2_263_1));
  or2((&S_or2_266_1));
  or2((&S_or2_265_1));
  or2((&S_or2_300_1));
  or2((&S_or2_299_1));
  or2((&S_or2_302_1));
  or2((&S_or2_301_1));
  schl24((&S_schl24_332_1));
  or2((&S_or2_257_1));
  or2((&S_or2_255_1));
  or2((&S_or2_249_1));
  or2((&S_or2_243_1));
  or2((&S_or2_204_1));
  or2((&S_or2_202_1));
  or2((&S_or2_201_1));
  or2((&S_or2_199_1));
  and2((&S_and2_86_1));
  and2((&S_and2_84_1));
  and2((&S_and2_82_1));
  and2((&S_and2_80_1));
  zzfs((&S_zzfs_244_1));
  ma((&S_ma_184_1));
  drg((&S_drg_162_1));
  drg((&S_drg_153_1));
  geterr((&S_geterr_99_1));
  drg((&S_drg_105_1));
  drg((&S_drg_97_1));
  drg((&S_drg_120_1));
  drg((&S_drg_107_1));
  geterr((&S_geterr_102_1));
  tprg((&S_tprg_123_1));
  tprg((&S_tprg_129_1));
  srm((&S_srm_2_1));
  bol((&S_bol_173_1));
  bol((&S_bol_175_1));
  react((&S_react_170_1));
  noto((&S_noto_7_1));
  srm((&S_srm_330_1));
  noto((&S_noto_125_1));
  noto((&S_noto_134_1));
  geterr((&S_geterr_147_1));
  drg((&S_drg_165_1));
  drg((&S_drg_154_1));
  geterr((&S_geterr_145_1));
  noto((&S_noto_219_1));
  noto((&S_noto_245_1));
  bol((&S_bol_174_1));
  noto((&S_noto_324_1));
  noto((&S_noto_325_1));
  noto((&S_noto_24_1));
  zpfs((&S_zpfs_206_1));
  zpfs((&S_zpfs_208_1));
  zpfs((&S_zpfs_210_1));
  zpfs((&S_zpfs_212_1));
  and2((&S_and2_178_1));
  and2((&S_and2_179_1));
  and2((&S_and2_5_1));
  or2((&S_or2_149_1));
  or2((&S_or2_35_1));
  or2((&S_or2_151_1));
  or2((&S_or2_10_1));
  and2((&S_and2_6_1));
  and2((&S_and2_267_1));
  schl24((&S_schl24_270_1));
  and2((&S_and2_268_1));
  or2((&S_or2_284_1));
  and2((&S_and2_297_1));
  schl24((&S_schl24_296_1));
  and2((&S_and2_298_1));
  or2((&S_or2_285_1));
  and2((&S_and2_323_1));
  or2((&S_or2_336_1));
  and2((&S_and2_216_1));
  and2((&S_and2_218_1));
  and2((&S_and2_256_1));
  and3((&S_and3_230_1));
  and3((&S_and3_226_1));
  and3((&S_and3_227_1));
  or2((&S_or2_232_1));
  or2((&S_or2_233_1));
  or3((&S_or3_250_1));
  and2((&S_and2_215_1));
  and2((&S_and2_213_1));
  or2((&S_or2_110_1));
  and2((&S_and2_126_1));
  and2((&S_and2_133_1));
  or2((&S_or2_104_1));
  and2((&S_and2_251_1));
  and3((&S_and3_211_1));
  and3((&S_and3_207_1));
  ornc((&S_ornc_12_1));
  ornc((&S_ornc_3_1));
  noto((&S_noto_282_1));
  noto((&S_noto_287_1));
  noto((&S_noto_322_1));
  noto((&S_noto_13_1));
  ovb1((&S_ovb1_33_1));
  noto((&S_noto_27_1));
  zpfs((&S_zpfs_252_1));
  zpfs((&S_zpfs_315_1));
  and2((&S_and2_22_1));
  or2((&S_or2_11_1));
  and2((&S_and2_317_1));
  and2((&S_and2_277_1));
  and2((&S_and2_272_1));
  or2((&S_or2_278_1));
  or2((&S_or2_276_1));
  and2((&S_and2_292_1));
  or2((&S_or2_293_1));
  or2((&S_or2_291_1));
  and2((&S_and2_294_1));
  and2((&S_and2_288_1));
  and2((&S_and2_312_1));
  and2((&S_and2_314_1));
  and2((&S_and2_320_1));
  and2((&S_and2_319_1));
  and2((&S_and2_318_1));
  and2((&S_and2_311_1));
  and2((&S_and2_313_1));
  and3((&S_and3_225_1));
  and3((&S_and3_224_1));
  and3((&S_and3_229_1));
  or2((&S_or2_228_1));
  noto((&S_noto_321_1));
  noto((&S_noto_14_1));
  or3((&S_or3_18_1));
  and2((&S_and2_19_1));
  or3((&S_or3_30_1));
  and2((&S_and2_281_1));
  and2((&S_and2_280_1));
  and2((&S_and2_289_1));
  and2((&S_and2_316_1));
  or2((&S_or2_231_1));
  orn((&S_orn_16_1));
  orni((&S_orni_310_1));
  rsu((&S_rsu_308_1));
  and2((&S_and2_31_1));
  orn((&S_orn_36_1));
  or2((&S_or2_25_1));
  signal_R0AD16LZ2.b = var92.b;
  signal_R0AD16LZ2.error = var92.error;
  signal_R0AD15LZ2.b = var93.b;
  signal_R0AD15LZ2.error = var93.error;
  signal_R0AD14LZ2.b = var94.b;
  signal_R0AD14LZ2.error = var94.error;
  signal_R0EE04LZ2.b = signal_R0EE02LDU.b;
  signal_R0EE04LZ2.error = signal_R0EE02LDU.error;
  signal_R0EE03LZ2.b = signal_R0EE02LDU.b;
  signal_R0EE03LZ2.error = signal_R0EE02LDU.error;
  signal_R0EE02LZ2.b = signal_R0EE02LDU.b;
  signal_R0EE02LZ2.error = signal_R0EE02LDU.error;
  signal_R0EE01LZ2.b = signal_R0EE02LDU.b;
  signal_R0EE01LZ2.error = signal_R0EE02LDU.error;
  signal_A3VZ13LZ2.b = var2.b;
  signal_A3VZ13LZ2.error = var2.error;
  signal_A3VZ15LZ2.b = var1.b;
  signal_A3VZ15LZ2.error = var1.error;
  signal_A1VN71LZ2.b = var40.b;
  signal_A1VN71LZ2.error = var40.error;
  signal_B0VT71LZ2.b = var85.b;
  signal_B0VT71LZ2.error = var85.error;
  signal_B0VT61LZ2.b = var132.b;
  signal_B0VT61LZ2.error = var132.error;
  fplet(&signal_B0CT01IZ2.f,&var126.f);
  signal_B0CT01IZ2.error = var126.error;
  signal_R0VP73LZ2.b = var41.b;
  signal_R0VP73LZ2.error = var41.error;
  fplet(&signal_R0VN11RZ2.f,&var137.f);
  signal_R0VN11RZ2.error = var137.error;
  signal_R0VZ05UZ2.l = var138.l;
  signal_R0VZ05UZ2.error = var138.error;
  signal_B0VN81LZ2.b = var54.b;
  signal_B0VN81LZ2.error = var54.error;
  signal_A0VN81LZ2.b = var48.b;
  signal_A0VN81LZ2.error = var48.error;
  signal_B0VN71LZ2.b = var68.b;
  signal_B0VN71LZ2.error = var68.error;
  signal_A0VN71LZ2.b = var67.b;
  signal_A0VN71LZ2.error = var67.error;
  signal_B0VZ71LZ2.b = var140.b;
  signal_B0VZ71LZ2.error = var140.error;
  signal_B0EE00LZ2.b = var83.b;
  signal_B0EE00LZ2.error = var83.error;
  signal_A0EE00LZ2.b = var84.b;
  signal_A0EE00LZ2.error = var84.error;
  signal_A0VZ71LZ2.b = var141.b;
  signal_A0VZ71LZ2.error = var141.error;
  signal_A0EE03LZ2.b = var7.b;
  signal_A0EE03LZ2.error = var7.error;
  signal_A0EE02LZ2.b = var6.b;
  signal_A0EE02LZ2.error = var6.error;
  signal_A0EE04LZ2.b = var8.b;
  signal_A0EE04LZ2.error = var8.error;
  signal_A0EE01LZ2.b = var5.b;
  signal_A0EE01LZ2.error = var5.error;
  signal_R0VN80LZ2.b = var50.b;
  signal_R0VN80LZ2.error = var50.error;
  signal_R0VN70LZ2.b = var65.b;
  signal_R0VN70LZ2.error = var65.error;
  signal_R0VZ71LZ2.b = var79.b;
  signal_R0VZ71LZ2.error = var79.error;
  fplet(&signal_R0VR02RZ2.f,&var149.f);
  signal_R0VR02RZ2.error = var149.error;
  signal_R0VN79LZ2.b = var90.b;
  signal_R0VN79LZ2.error = var90.error;
  signal_R0VN69LZ2.b = var91.b;
  signal_R0VN69LZ2.error = var91.error;
  signal_B3VZ11LZ2.b = var23.b;
  signal_B3VZ11LZ2.error = var23.error;
  signal_A3VZ11LZ2.b = var19.b;
  signal_A3VZ11LZ2.error = var19.error;
  signal_B3VZ31LZ2.b = var29.b;
  signal_B3VZ31LZ2.error = var29.error;
  signal_A3VZ31LZ2.b = var30.b;
  signal_A3VZ31LZ2.error = var30.error;
  fplet(&signal_R0VN09RZ2.f,&var152.f);
  signal_R0VN09RZ2.error = var152.error;
  signal_R0VN68LZ2.b = signal_R0VN65LS4.b;
  signal_R0VN68LZ2.error = signal_R0VN65LS4.error;
  signal_R0VN67LZ2.b = signal_R0VN65LS3.b;
  signal_R0VN67LZ2.error = signal_R0VN65LS3.error;
  signal_R0VN66LZ2.b = signal_R0VN65LS2.b;
  signal_R0VN66LZ2.error = signal_R0VN65LS2.error;
  signal_R0VN65LZ2.b = signal_R0VN65LS1.b;
  signal_R0VN65LZ2.error = signal_R0VN65LS1.error;
  signal_R0VN64LZ2.b = signal_R0VN61LS4.b;
  signal_R0VN64LZ2.error = signal_R0VN61LS4.error;
  signal_R0VN63LZ2.b = signal_R0VN61LS3.b;
  signal_R0VN63LZ2.error = signal_R0VN61LS3.error;
  signal_R0VN62LZ2.b = signal_R0VN61LS2.b;
  signal_R0VN62LZ2.error = signal_R0VN61LS2.error;
  signal_R0VN61LZ2.b = signal_R0VN61LS1.b;
  signal_R0VN61LZ2.error = signal_R0VN61LS1.error;
  fplet(&signal_R0VN08RZ2.f,&signal_R0VN01RS4.f);
  signal_R0VN08RZ2.error = signal_R0VN01RS4.error;
  fplet(&signal_R0VN07RZ2.f,&signal_R0VN01RS3.f);
  signal_R0VN07RZ2.error = signal_R0VN01RS3.error;
  fplet(&signal_R0VN06RZ2.f,&signal_R0VN01RS2.f);
  signal_R0VN06RZ2.error = signal_R0VN01RS2.error;
  fplet(&signal_R0VN05RZ2.f,&signal_R0VN01RS1.f);
  signal_R0VN05RZ2.error = signal_R0VN01RS1.error;
  fplet(&signal_R0VN04RZ2.f,&signal_R0VN02RS4.f);
  signal_R0VN04RZ2.error = signal_R0VN02RS4.error;
  fplet(&signal_R0VN03RZ2.f,&signal_R0VN02RS3.f);
  signal_R0VN03RZ2.error = signal_R0VN02RS3.error;
  fplet(&signal_R0VN02RZ2.f,&signal_R0VN02RS2.f);
  signal_R0VN02RZ2.error = signal_R0VN02RS2.error;
  fplet(&signal_R0VN01RZ2.f,&signal_R0VN02RS1.f);
  signal_R0VN01RZ2.error = signal_R0VN02RS1.error;
  signal_B0VP71LZ2.b = var156.b;
  signal_B0VP71LZ2.error = var156.error;
  signal_A0VP71LZ2.b = var154.b;
  signal_A0VP71LZ2.error = var154.error;
  signal_A0EP02IZ2.i = var155.c;
  signal_A0EP02IZ2.error = var155.error;
  signal_B0EP02IZ2.i = var157.c;
  signal_B0EP02IZ2.error = var157.error;
  signal_R0ET02LZ2.b = var133.b;
  signal_R0ET02LZ2.error = var133.error;
  signal_B0VP41LZ2.b = var104.b;
  signal_B0VP41LZ2.error = var104.error;
  signal_A0VP41LZ2.b = var105.b;
  signal_A0VP41LZ2.error = var105.error;
  signal_R0ET01LZ2.b = var128.b;
  signal_R0ET01LZ2.error = var128.error;
  signal_A2VP81LZ2.b = var11.b;
  signal_A2VP81LZ2.error = var11.error;
  signal_B2VP81LZ2.b = var10.b;
  signal_B2VP81LZ2.error = var10.error;
  signal_B2VP51LZ2.b = var162.b;
  signal_B2VP51LZ2.error = var162.error;
  fplet(&signal_B2CP01RZ2.f,&var129.f);
  signal_B2CP01RZ2.error = var129.error;
  signal_B2VP41LZ2.b = var12.b;
  signal_B2VP41LZ2.error = var12.error;
  signal_A2VP51LZ2.b = var164.b;
  signal_A2VP51LZ2.error = var164.error;
  fplet(&signal_A2CP01RZ2.f,&var130.f);
  signal_A2CP01RZ2.error = var130.error;
  signal_A2VP41LZ2.b = var9.b;
  signal_A2VP41LZ2.error = var9.error;
  signal_B1VP41LZ2.b = var106.b;
  signal_B1VP41LZ2.error = var106.error;
  signal_A1VP41LZ2.b = var136.b;
  signal_A1VP41LZ2.error = var136.error;
  signal_A0VT71LZ2.b = var87.b;
  signal_A0VT71LZ2.error = var87.error;
  signal_A0VT61LZ2.b = var167.b;
  signal_A0VT61LZ2.error = var167.error;
  fplet(&signal_A0CT01IZ2.f,&var127.f);
  signal_A0CT01IZ2.error = var127.error;

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
ParExchange("A0IT02IZ2",2,&SignalBuffer[0],"����������� ��1-2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(16);
#else
ParExchange("B1VP81LZZ",3,&SignalBuffer[16],"�������� ����� ��2 � �����",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(18);
#else
ParExchange("A1VP81LZZ",3,&SignalBuffer[18],"�������� ����� ��1 � �����",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(42);
#else
ParExchange("A2IP01IZ2",2,&SignalBuffer[42],"������� �������� ����� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(45);
#else
ParExchange("B2IP01IZ2",2,&SignalBuffer[45],"������� �������� ����� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(50);
#else
ParExchange("B0IT02IZ2",2,&SignalBuffer[50],"����������� ��2-2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(57);
#else
ParExchange("B0VP81LZZ",3,&SignalBuffer[57],"�������� ��2 � �����",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(59);
#else
ParExchange("A0VP81LZZ",3,&SignalBuffer[59],"��������  ��1 � �����",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(73);
#else
ParExchange("R0VN02RS1",1,&SignalBuffer[73],"������� �������� ����� 1",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(78);
#else
ParExchange("R0VN02RS2",1,&SignalBuffer[78],"������� �������� ����� 2",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(83);
#else
ParExchange("R0VN02RS3",1,&SignalBuffer[83],"������� �������� ����� 3",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(88);
#else
ParExchange("R0VN02RS4",1,&SignalBuffer[88],"������� �������� ����� 4",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(93);
#else
ParExchange("R0VN01RS1",1,&SignalBuffer[93],"������ ������� ����� 1",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(98);
#else
ParExchange("R0VN01RS2",1,&SignalBuffer[98],"������ ������� ����� 2",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(103);
#else
ParExchange("R0VN01RS3",1,&SignalBuffer[103],"������ ������� ����� 3",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(108);
#else
ParExchange("R0VN01RS4",1,&SignalBuffer[108],"������ ������� ����� 4",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(113);
#else
ParExchange("R0VN61LS1",3,&SignalBuffer[113],"�� �� �������� ����� 1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(115);
#else
ParExchange("R0VN61LS2",3,&SignalBuffer[115],"�� �� �������� ����� 2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(117);
#else
ParExchange("R0VN61LS3",3,&SignalBuffer[117],"�� �� �������� ����� 3",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(119);
#else
ParExchange("R0VN61LS4",3,&SignalBuffer[119],"�� �� �������� ����� 4",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(121);
#else
ParExchange("R0VN65LS1",3,&SignalBuffer[121],"�� �� ������� ������� ����� 1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(123);
#else
ParExchange("R0VN65LS2",3,&SignalBuffer[123],"�� �� ������� �������  ����� 2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(125);
#else
ParExchange("R0VN65LS3",3,&SignalBuffer[125],"�� �� ������� ������� ����� 3",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(127);
#else
ParExchange("R0VN65LS4",3,&SignalBuffer[127],"�� �� ������� ������� ����� 4",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(190);
#else
ParExchange("A3IS11LDU",3,&SignalBuffer[190],"������ �� �� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(192);
#else
ParExchange("A3IS22LDU",3,&SignalBuffer[192],"������ �� ��� ��1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(194);
#else
ParExchange("R0AD03LZ2",3,&SignalBuffer[194],"�������� ������� �� �� ��",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(196);
#else
ParExchange("B3IS11LDU",3,&SignalBuffer[196],"������ �� �� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(202);
#else
ParExchange("R0AD05LZ2",3,&SignalBuffer[202],"�������� ����� � ��� ��",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(208);
#else
ParExchange("B3IS22LDU",3,&SignalBuffer[208],"������ �� ��� ��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(225);
#else
ParExchange("A1EE01LS1",3,&SignalBuffer[225],"����������� ���� ����� 1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(227);
#else
ParExchange("A1EE01LS4",3,&SignalBuffer[227],"����������� ���� ����� 4",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(229);
#else
ParExchange("A1EE01LS3",3,&SignalBuffer[229],"����������� ���� ����� 3",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(239);
#else
ParExchange("A1EE01LS2",3,&SignalBuffer[239],"����������� ����  ����� 2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(241);
#else
ParExchange("A0EE05LZ2",3,&SignalBuffer[241],"����������� ���� ����1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(243);
#else
ParExchange("A0EE06LZ2",3,&SignalBuffer[243],"����������� ���� ����2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(245);
#else
ParExchange("A0EE07LZ2",3,&SignalBuffer[245],"����������� ���� ����3",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(247);
#else
ParExchange("A0EE08LZ2",3,&SignalBuffer[247],"����������� ���� ����4",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(286);
#else
ParExchange("A1VN71LS1",3,&SignalBuffer[286],"���������� ��������������� ������� �� ����� 1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(288);
#else
ParExchange("A1VN71LS2",3,&SignalBuffer[288],"���������� ��������������� ������� �� ����� 2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(290);
#else
ParExchange("A1VN71LS3",3,&SignalBuffer[290],"���������� ��������������� ������� �� ����� 3",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(292);
#else
ParExchange("A1VN71LS4",3,&SignalBuffer[292],"���������� ��������������� ������� �� ����� 4",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(300);
#else
ParExchange("R0VW13LDU",3,&SignalBuffer[300],"��������� ������ ��1 ��� ��1+��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(302);
#else
ParExchange("R0VW23LDU",3,&SignalBuffer[302],"��������� ������ ��2 ��� ��1+��2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(304);
#else
ParExchange("R7II73LZ2",3,&SignalBuffer[304],"��������� �� II �� ���",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(306);
#else
ParExchange("R7II71LZ2",3,&SignalBuffer[306],"��������� �� I�� ��� (������ 1)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(308);
#else
ParExchange("R7II72LZ2",3,&SignalBuffer[308],"��������� �� I�� ��� (������ 2)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(310);
#else
ParExchange("R0AD21LDU",3,&SignalBuffer[310],"���������� ������ �� II ��",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(312);
#else
ParExchange("R0MD34LP1",3,&SignalBuffer[312],"������ �����������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(314);
#else
ParExchange("R0AD14LDU",3,&SignalBuffer[314],"�������� ������������ ������� �� II ��",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(316);
#else
ParExchange("R0AD16LDU",3,&SignalBuffer[316],"�������� ������������ ������� �� I ��",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(318);
#else
ParExchange("R6IS66LZZ",3,&SignalBuffer[318],"����������� ��� 4,0 (�5) ����-1-1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(320);
#else
ParExchange("R6IS67LZZ",3,&SignalBuffer[320],"����������� ��� 4,0 (�6) ����-1-2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(322);
#else
ParExchange("R6IS68LZZ",3,&SignalBuffer[322],"����������� ��� 4,0 (�7) ����-2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(324);
#else
ParExchange("R0VN71LZ2",3,&SignalBuffer[324],"�� �� �������� ����� 1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(326);
#else
ParExchange("R0VN75LZ2",3,&SignalBuffer[326],"�� �� ������� ������� ����� 1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(328);
#else
ParExchange("R0VN72LZ2",3,&SignalBuffer[328],"�� �� �������� ����� 2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(330);
#else
ParExchange("R0VN76LZ2",3,&SignalBuffer[330],"�� �� ������� ������� �����  2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(332);
#else
ParExchange("R0VN73LZ2",3,&SignalBuffer[332],"�� �� �������� ����� 3",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(334);
#else
ParExchange("R0VN74LZ2",3,&SignalBuffer[334],"�� �� �������� ����� 4",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(336);
#else
ParExchange("R0VN77LZ2",3,&SignalBuffer[336],"�� �� ������� ������� �����  3",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(338);
#else
ParExchange("R0VN78LZ2",3,&SignalBuffer[338],"�� �� ������� ������� �����  4",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(340);
#else
ParExchange("R0AD04LZ2",3,&SignalBuffer[340],"�������� ������������ ������� �� II ��",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(356);
#else
ParExchange("R0MW12IP2",2,&SignalBuffer[356],"������������� ����� ������������ �� �� ��",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(359);
#else
ParExchange("A2IS12LDU",3,&SignalBuffer[359],"������ ��1 ��������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(361);
#else
ParExchange("B2IS12LDU",3,&SignalBuffer[361],"������ ��2 ��������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(363);
#else
ParExchange("R0EE02LDU",3,&SignalBuffer[363],"�������  ����  ���������",0);
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
 for(counter=0; counter<365; counter++) {
   *((unsigned char*)(SignalBuffer)+PBLENGTH-counter-1) =
          (unsigned char)~(*((unsigned char*)(SignalBuffer)+counter));
 }
#endif
}
#endif
#ifdef SIMUL_MODE
void UnloadSignals()
{
ParExchange("A0CT01IZ2",1,&SignalBuffer[3],"����������� ��1-1",1);
ParExchange("A0VT61LZ2",3,&SignalBuffer[8],"�� �� ����������� � ��1",1);
ParExchange("A0VT71LZ2",3,&SignalBuffer[10],"�� �� ����������� � ��1",1);
ParExchange("A1VP41LZ2",3,&SignalBuffer[12],"�������� ����� ��1 ���� ��",1);
ParExchange("B1VP41LZ2",3,&SignalBuffer[14],"�������� ����� ��2 ���� ��",1);
ParExchange("A2VP41LZ2",3,&SignalBuffer[20],"�������� ����� ��1 ���� ��",1);
ParExchange("A2CP01RZ2",1,&SignalBuffer[22],"������� �������� ����� ��1",1);
ParExchange("A2VP51LZ2",3,&SignalBuffer[27],"�������� ����� ��1 ���� ��",1);
ParExchange("B2VP41LZ2",3,&SignalBuffer[29],"�������� ����� ��2 ���� ��",1);
ParExchange("B2CP01RZ2",1,&SignalBuffer[31],"������� �������� ����� ��2",1);
ParExchange("B2VP51LZ2",3,&SignalBuffer[36],"�������� ����� ��2 ���� ��",1);
ParExchange("B2VP81LZ2",3,&SignalBuffer[38],"�������� ����� ��2 � �����",1);
ParExchange("A2VP81LZ2",3,&SignalBuffer[40],"�������� ����� ��1 � �����",1);
ParExchange("R0ET01LZ2",3,&SignalBuffer[48],"������� ������� ������������� �� �����������  ��1",1);
ParExchange("A0VP41LZ2",3,&SignalBuffer[53],"�������� ��1 ���� ��",1);
ParExchange("B0VP41LZ2",3,&SignalBuffer[55],"�������� ��2 ���� ��",1);
ParExchange("R0ET02LZ2",3,&SignalBuffer[61],"������� ������� ������������� �� ����������� ��2",1);
ParExchange("B0EP02IZ2",2,&SignalBuffer[63],"��������� -��������  ��2 ���� ��",1);
ParExchange("A0EP02IZ2",2,&SignalBuffer[66],"��������� -��������  ��1 ���� ��",1);
ParExchange("A0VP71LZ2",3,&SignalBuffer[69],"�� �� �� ������ �������� ��� ��1",1);
ParExchange("B0VP71LZ2",3,&SignalBuffer[71],"�� �� �� ������ �������� ��� ��2",1);
ParExchange("R0VN01RZ2",1,&SignalBuffer[129],"������� �������� �� ������ 1",1);
ParExchange("R0VN02RZ2",1,&SignalBuffer[134],"������� �������� �� ������ 2",1);
ParExchange("R0VN03RZ2",1,&SignalBuffer[139],"������� �������� �� ������ 3",1);
ParExchange("R0VN04RZ2",1,&SignalBuffer[144],"������� �������� �� ������ 4",1);
ParExchange("R0VN05RZ2",1,&SignalBuffer[149],"������ ������� �� ������ 1",1);
ParExchange("R0VN06RZ2",1,&SignalBuffer[154],"������ ������� �� ������ 2",1);
ParExchange("R0VN07RZ2",1,&SignalBuffer[159],"������ ������� �� ������ 3",1);
ParExchange("R0VN08RZ2",1,&SignalBuffer[164],"������ ������� �� ������ 4",1);
ParExchange("R0VN61LZ2",3,&SignalBuffer[169],"�� �� �������� ����� 1",1);
ParExchange("R0VN62LZ2",3,&SignalBuffer[171],"�� �� �������� ����� 2",1);
ParExchange("R0VN63LZ2",3,&SignalBuffer[173],"�� �� �������� ����� 3",1);
ParExchange("R0VN64LZ2",3,&SignalBuffer[175],"�� �� �������� ����� 4",1);
ParExchange("R0VN65LZ2",3,&SignalBuffer[177],"�� �� ������� ������� ����� 1",1);
ParExchange("R0VN66LZ2",3,&SignalBuffer[179],"�� �� ������� ������� ����� 2",1);
ParExchange("R0VN67LZ2",3,&SignalBuffer[181],"�� �� ������� ������� ����� 3",1);
ParExchange("R0VN68LZ2",3,&SignalBuffer[183],"�� �� ������� ������� ����� 4",1);
ParExchange("R0VN09RZ2",1,&SignalBuffer[185],"����������� ������ �������",1);
ParExchange("A3VZ31LZ2",3,&SignalBuffer[198],"�� �� �� ��1",1);
ParExchange("B3VZ31LZ2",3,&SignalBuffer[200],"�� �� �� ��2",1);
ParExchange("A3VZ11LZ2",3,&SignalBuffer[204],"�� �� ��� ��1",1);
ParExchange("B3VZ11LZ2",3,&SignalBuffer[206],"�� �� ��� ��2",1);
ParExchange("R0VN69LZ2",3,&SignalBuffer[210],"�� �� ������������ �������",1);
ParExchange("R0VN79LZ2",3,&SignalBuffer[212],"�� �� ������������ �������",1);
ParExchange("R0VR02RZ2",1,&SignalBuffer[214],"����������� ������������",1);
ParExchange("R0VZ71LZ2",3,&SignalBuffer[219],"���������� ������ �� 2 ������",1);
ParExchange("R0VN70LZ2",3,&SignalBuffer[221],"�� �� �� �������� ��",1);
ParExchange("R0VN80LZ2",3,&SignalBuffer[223],"�� �� �� ������� ������� ��",1);
ParExchange("A0EE01LZ2",3,&SignalBuffer[231],"����������� ����1",1);
ParExchange("A0EE04LZ2",3,&SignalBuffer[233],"����������� ����4",1);
ParExchange("A0EE02LZ2",3,&SignalBuffer[235],"����������� ����2",1);
ParExchange("A0EE03LZ2",3,&SignalBuffer[237],"����������� ����3",1);
ParExchange("A0VZ71LZ2",3,&SignalBuffer[249],"���������� ������ �� �� ��1",1);
ParExchange("A0EE00LZ2",3,&SignalBuffer[251],"����������� ���� ��1",1);
ParExchange("B0EE00LZ2",3,&SignalBuffer[253],"����������� ���� ��2",1);
ParExchange("B0VZ71LZ2",3,&SignalBuffer[255],"���������� ������ �� �� ��2",1);
ParExchange("A0VN71LZ2",3,&SignalBuffer[257],"�� �� �� ��������  ��1",1);
ParExchange("B0VN71LZ2",3,&SignalBuffer[259],"�� �� �� ��������  ��2",1);
ParExchange("A0VN81LZ2",3,&SignalBuffer[261],"�� �� �� ������� ������� ��1",1);
ParExchange("B0VN81LZ2",3,&SignalBuffer[263],"�� �� �� ������� ������� ��2",1);
ParExchange("R0VZ05UZ2",7,&SignalBuffer[265],"��������� ������� ������",1);
ParExchange("R0VN11RZ2",1,&SignalBuffer[270],"������� �������� �� ���1",1);
ParExchange("R0VP73LZ2",3,&SignalBuffer[275],"�� �������� ��� ��",1);
ParExchange("B0CT01IZ2",1,&SignalBuffer[277],"����������� ��2-1",1);
ParExchange("B0VT61LZ2",3,&SignalBuffer[282],"�� �� ����������� � ��2",1);
ParExchange("B0VT71LZ2",3,&SignalBuffer[284],"�� �� ����������� � ��2",1);
ParExchange("A1VN71LZ2",3,&SignalBuffer[294],"���������� ��������������� ������� ��",1);
ParExchange("A3VZ15LZ2",3,&SignalBuffer[296],"�������� �� �� ��� ��",1);
ParExchange("A3VZ13LZ2",3,&SignalBuffer[298],"�������� �� �� �� ��",1);
ParExchange("R0EE01LZ2",3,&SignalBuffer[342],"�������  ����1  ���������",1);
ParExchange("R0EE02LZ2",3,&SignalBuffer[344],"�������  ����2  ���������",1);
ParExchange("R0EE03LZ2",3,&SignalBuffer[346],"�������  ����3  ���������",1);
ParExchange("R0EE04LZ2",3,&SignalBuffer[348],"�������  ����4  ���������",1);
ParExchange("R0AD14LZ2",3,&SignalBuffer[350],"�������� �� �� II��",1);
ParExchange("R0AD15LZ2",3,&SignalBuffer[352],"�������� �� �� 1�� (������1)",1);
ParExchange("R0AD16LZ2",3,&SignalBuffer[354],"�������� �� �� 1�� (������2)",1);
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
NewEEPROM("fEM_R0UT02RZZ",1,&fEM_R0UT02RZZ,"������� ������ ����� ������� �����������","600");
NewEEPROM("fEM_R0UT01RZZ",1,&fEM_R0UT01RZZ,"������ ������ ����� ������� �����������","0");
NewEEPROM("fEM_A2UP03RZZ",1,&fEM_A2UP03RZZ,"������� ������ ����� ������� �������� �� ������/����� ��,��","1.6");
NewEEPROM("fEM_A2UP04RZZ",1,&fEM_A2UP04RZZ,"������ ������ ����� ������� �������� �� ������/����� ��.��","0");
NewEEPROM("fEM_R0UT72RZZ",1,&fEM_R0UT72RZZ,"������� ��������������� ������������ ��������� ������������ �� ����������� �� (����)","150");
NewEEPROM("fEM_R0UT71RZZ",1,&fEM_R0UT71RZZ,"������� ������������ ��������� ������������ �� ����������� ��","200");
NewEEPROM("fEM_R0UT62RZZ",1,&fEM_R0UT62RZZ,"������� ��������������� ������������ ����������������� ������������ �� ����������� �� (����)","90");
NewEEPROM("fEM_R0UT61RZZ",1,&fEM_R0UT61RZZ,"������� ������������ ����������������� ������������ �� ����������� ��","100");
NewEEPROM("fEM_A2UP41RZZ",1,&fEM_A2UP41RZZ,"������� ������������ ��������� ������������ �� �������� ����� ��","0.1");
NewEEPROM("fEM_A2UP42RZZ",1,&fEM_A2UP42RZZ,"������� ��������������� ������������ ��������� ������������ �� �������� ����� �� (���)","0.13");
NewEEPROM("fEM_A2UP51RZZ",1,&fEM_A2UP51RZZ,"������� ������������ ����������������� �� �������� ����� �� (���)","0.16");
NewEEPROM("fEM_A2UP81RZZ",1,&fEM_A2UP81RZZ,"������ ������� ��������������� ������������ �������� ����� �� (���)","0.17");
NewEEPROM("fEM_A2UP84RZZ",1,&fEM_A2UP84RZZ,"������� ������� ��������������� ������������ �������� ����� �� (���)","0.31");
NewEEPROM("fEM_A2UP82RZZ",1,&fEM_A2UP82RZZ,"������ ������� ������������ �������� ����� �� (���)","0.2");
NewEEPROM("fEM_A2UP52RZZ",1,&fEM_A2UP52RZZ,"������� ��������������� ������������ ����������������� ������������ �� �������� ����� ��(���)","0.19");
NewEEPROM("fEM_A2UP83RZZ",1,&fEM_A2UP83RZZ,"������� ������� ������������ �������� ����� �� (���)","0.28");
NewEEPROM("fEM_R0UR01RZZ",1,&fEM_R0UR01RZZ,"������� ���� ��  �� �� ������� (���)","15");
NewEEPROM("fEM_R0UR04RZZ",1,&fEM_R0UR04RZZ,"������� ���� ��  �� �� ������� (���)","10");
NewEEPROM("fEM_A1UL12RZZ",1,&fEM_A1UL12RZZ,"����� �������� �� �� �� ��(���)","0.180");
NewEEPROM("fEM_A1UL11RZZ",1,&fEM_A1UL11RZZ,"����� �������� �� �� �� ��","0.020");
NewEEPROM("fEM_R7UI73RZZ",1,&fEM_R7UI73RZZ,"����� ��������  ������������ �� II ��","0.045");
#else
if(EEPROMFlag) {
  fplet(&fEM_R0UT02RZZ.f,((float*)(IntEEPROMBuffer+0x0)));
  fEM_R0UT02RZZ.error = 0;
  fplet(&fEM_R0UT01RZZ.f,((float*)(IntEEPROMBuffer+0x4)));
  fEM_R0UT01RZZ.error = 0;
  fplet(&fEM_A2UP03RZZ.f,((float*)(IntEEPROMBuffer+0x8)));
  fEM_A2UP03RZZ.error = 0;
  fplet(&fEM_A2UP04RZZ.f,((float*)(IntEEPROMBuffer+0xC)));
  fEM_A2UP04RZZ.error = 0;
  fplet(&fEM_R0UT72RZZ.f,((float*)(IntEEPROMBuffer+0x10)));
  fEM_R0UT72RZZ.error = 0;
  fplet(&fEM_R0UT71RZZ.f,((float*)(IntEEPROMBuffer+0x14)));
  fEM_R0UT71RZZ.error = 0;
  fplet(&fEM_R0UT62RZZ.f,((float*)(IntEEPROMBuffer+0x18)));
  fEM_R0UT62RZZ.error = 0;
  fplet(&fEM_R0UT61RZZ.f,((float*)(IntEEPROMBuffer+0x1C)));
  fEM_R0UT61RZZ.error = 0;
  fplet(&fEM_A2UP41RZZ.f,((float*)(IntEEPROMBuffer+0x20)));
  fEM_A2UP41RZZ.error = 0;
  fplet(&fEM_A2UP42RZZ.f,((float*)(IntEEPROMBuffer+0x24)));
  fEM_A2UP42RZZ.error = 0;
  fplet(&fEM_A2UP51RZZ.f,((float*)(IntEEPROMBuffer+0x28)));
  fEM_A2UP51RZZ.error = 0;
  fplet(&fEM_A2UP81RZZ.f,((float*)(IntEEPROMBuffer+0x2C)));
  fEM_A2UP81RZZ.error = 0;
  fplet(&fEM_A2UP84RZZ.f,((float*)(IntEEPROMBuffer+0x30)));
  fEM_A2UP84RZZ.error = 0;
  fplet(&fEM_A2UP82RZZ.f,((float*)(IntEEPROMBuffer+0x34)));
  fEM_A2UP82RZZ.error = 0;
  fplet(&fEM_A2UP52RZZ.f,((float*)(IntEEPROMBuffer+0x38)));
  fEM_A2UP52RZZ.error = 0;
  fplet(&fEM_A2UP83RZZ.f,((float*)(IntEEPROMBuffer+0x3C)));
  fEM_A2UP83RZZ.error = 0;
  fplet(&fEM_R0UR01RZZ.f,((float*)(IntEEPROMBuffer+0x40)));
  fEM_R0UR01RZZ.error = 0;
  fplet(&fEM_R0UR04RZZ.f,((float*)(IntEEPROMBuffer+0x44)));
  fEM_R0UR04RZZ.error = 0;
  fplet(&fEM_A1UL12RZZ.f,((float*)(IntEEPROMBuffer+0x48)));
  fEM_A1UL12RZZ.error = 0;
  fplet(&fEM_A1UL11RZZ.f,((float*)(IntEEPROMBuffer+0x4C)));
  fEM_A1UL11RZZ.error = 0;
  fplet(&fEM_R7UI73RZZ.f,((float*)(IntEEPROMBuffer+0x50)));
  fEM_R7UI73RZZ.error = 0;
}
#endif
}

#ifndef SIMUL_MODE
unsigned int EndIntEEPROMAddress = 84;
#endif

void reInit_Signals(void)
{
  S_ma_184_1.r = &signal_R0MW12IP2;
  S_and3_207_1.x3 = &signal_R0AD05LZ2;
  S_and3_211_1.x3 = &signal_R0AD03LZ2;
  S_zzfs_244_1.x = &signal_R0AD04LZ2;
  S_and2_80_1.x1 = &signal_A0EE05LZ2;
  S_and2_80_1.x2 = &signal_A1EE01LS1;
  S_and2_82_1.x1 = &signal_A0EE06LZ2;
  S_and2_82_1.x2 = &signal_A1EE01LS2;
  S_and2_84_1.x1 = &signal_A0EE07LZ2;
  S_and2_84_1.x2 = &signal_A1EE01LS3;
  S_and2_86_1.x1 = &signal_A0EE08LZ2;
  S_and2_86_1.x2 = &signal_A1EE01LS4;
  S_or2_199_1.x1 = &signal_A3IS22LDU;
  S_or2_199_1.x2 = &signal_R0AD05LZ2;
  S_or2_201_1.x1 = &signal_B3IS22LDU;
  S_or2_201_1.x2 = &signal_R0AD05LZ2;
  S_or2_202_1.x1 = &signal_R0AD03LZ2;
  S_or2_204_1.x2 = &signal_R0AD03LZ2;
  S_and2_213_1.x2 = &signal_R0VW13LDU;
  S_and2_215_1.x2 = &signal_R0VW23LDU;
  S_or2_243_1.x1 = &signal_R7II72LZ2;
  S_or2_249_1.x2 = &signal_R7II71LZ2;
  S_or2_255_1.x2 = &signal_R7II73LZ2;
  S_or2_257_1.x1 = &signal_R0AD21LDU;
  S_or2_257_1.x2 = &signal_R0AD04LZ2;
  S_and2_218_1.x2 = &signal_R0VW23LDU;
  S_and2_216_1.x2 = &signal_R0VW13LDU;
  S_schl24_332_1.x1 = &signal_A1VN71LS2;
  S_schl24_332_1.x2 = &signal_A1VN71LS1;
  S_schl24_332_1.x3 = &signal_A1VN71LS4;
  S_schl24_332_1.x4 = &signal_A1VN71LS3;
  S_or2_301_1.x1 = &signal_R0VN76LZ2;
  S_or2_302_1.x1 = &signal_R0VN78LZ2;
  S_or2_299_1.x1 = &signal_R0VN75LZ2;
  S_or2_300_1.x1 = &signal_R0VN77LZ2;
  S_or2_265_1.x1 = &signal_R0VN72LZ2;
  S_or2_266_1.x1 = &signal_R0VN74LZ2;
  S_or2_263_1.x1 = &signal_R0VN71LZ2;
  S_or2_264_1.x1 = &signal_R0VN73LZ2;
  S_or2_35_1.x1 = &signal_B2IS12LDU;
  S_or2_35_1.x2 = &signal_A2IS12LDU;
  S_and2_187_1.x1 = &signal_R0AD04LZ2;
  S_and2_187_1.x2 = &signal_R7II72LZ2;
  S_and2_185_1.x1 = &signal_R0AD04LZ2;
  S_and2_185_1.x2 = &signal_R7II71LZ2;
  S_and2_181_1.x1 = &signal_R0AD04LZ2;
  S_and2_181_1.x2 = &signal_R7II73LZ2;
  S_noto_236_1.x = &signal_R6IS66LZZ;
  S_noto_248_1.x = &signal_R6IS67LZZ;
  S_noto_254_1.x = &signal_R6IS68LZZ;
  S_noto_128_1.x = &signal_B0VP81LZZ;
  S_noto_127_1.x = &signal_A0VP81LZZ;
  S_noto_96_1.x = &signal_B1VP81LZZ;
  S_noto_24_1.x = &signal_R0EE02LDU;
  S_noto_325_1.x = &signal_R0AD16LDU;
  S_noto_324_1.x = &signal_R0AD14LDU;
  S_noto_217_1.x = &signal_R0AD03LZ2;
  S_noto_214_1.x = &signal_R0AD05LZ2;
  S_noto_198_1.x = &signal_B3IS11LDU;
  S_noto_197_1.x = &signal_A3IS11LDU;
  S_noto_222_1.x = &signal_R0VW23LDU;
  S_noto_221_1.x = &signal_R0VW13LDU;
  S_noto_220_1.x = &signal_R0VW23LDU;
  S_noto_219_1.x = &signal_R0VW13LDU;
  S_scalzz_143_1.x = &signal_B0IT02IZ2;
  S_scalzz_141_1.x = &signal_A0IT02IZ2;
  S_scalzz_93_1.x = &signal_B2IP01IZ2;
  S_scalzz_91_1.x = &signal_A2IP01IZ2;
  S_noto_95_1.x = &signal_A1VP81LZZ;
  S_rsu_308_1.r = &signal_R0MD34LP1;
  S_noto_271_1.x = &signal_A1EE01LS4;
  S_noto_275_1.x = &signal_A1EE01LS2;
  S_noto_274_1.x = &signal_A1EE01LS3;
  S_noto_269_1.x = &signal_A1EE01LS1;
  array_m330_x_1[0] = &signal_R0VN02RS1;
  array_m330_x_1[1] = &signal_R0VN02RS2;
  array_m330_x_1[2] = &signal_R0VN02RS3;
  array_m330_x_1[3] = &signal_R0VN02RS4;
  array_m2_x_1[0] = &signal_R0VN01RS1;
  array_m2_x_1[1] = &signal_R0VN01RS2;
  array_m2_x_1[2] = &signal_R0VN01RS3;
  array_m2_x_1[3] = &signal_R0VN01RS4;
}

void InitInternalParametr(void)
{
  int i;
  S_zzfs_244_1.tx = &internal1_m244_tx;
  S_zzfs_244_1.y0 = &internal1_m244_y0;
  S_zpfs_315_1.tx = &internal1_m315_tx;
  S_zpfs_315_1.y0 = &internal1_m315_y0;
  S_zpfs_212_1.tx = &internal1_m212_tx;
  S_zpfs_212_1.y0 = &internal1_m212_y0;
  S_zpfs_210_1.tx = &internal1_m210_tx;
  S_zpfs_210_1.y0 = &internal1_m210_y0;
  S_zpfs_252_1.tx = &internal1_m252_tx;
  S_zpfs_252_1.y0 = &internal1_m252_y0;
  S_zpfs_208_1.tx = &internal1_m208_tx;
  S_zpfs_208_1.y0 = &internal1_m208_y0;
  S_zpfs_206_1.tx = &internal1_m206_tx;
  S_zpfs_206_1.y0 = &internal1_m206_y0;
  S_ovb1_33_1.tx = &internal1_m33_tx;
  S_scalzz_143_1.y0 = &internal1_m143_y0;
  S_scalzz_141_1.y0 = &internal1_m141_y0;
  S_scalzz_93_1.y0 = &internal1_m93_y0;
  S_scalzz_91_1.y0 = &internal1_m91_y0;
  S_drg_154_1.y1 = &internal1_m154_y1;
  S_drg_165_1.y1 = &internal1_m165_y1;
  S_rsu_308_1.q0 = &internal1_m308_q0;
  S_tprg_129_1.y0 = &internal1_m129_y0;
  S_tprg_123_1.y0 = &internal1_m123_y0;
  S_drg_107_1.y1 = &internal1_m107_y1;
  S_drg_120_1.y1 = &internal1_m120_y1;
  S_drg_97_1.y1 = &internal1_m97_y1;
  S_drg_105_1.y1 = &internal1_m105_y1;
  S_drg_153_1.y1 = &internal1_m153_y1;
  S_drg_162_1.y1 = &internal1_m162_y1;
  S_zpfs_212_1.tz = &fEM_A1UL11RZZ;
  S_zpfs_210_1.tz = &fEM_A1UL11RZZ;
  S_zpfs_252_1.tz = &fEM_R7UI73RZZ;
  S_zpfs_208_1.tz = &fEM_A1UL12RZZ;
  S_zpfs_206_1.tz = &fEM_A1UL12RZZ;
  S_scalzz_143_1.c = &fEM_R0UT01RZZ;
  S_scalzz_143_1.d = &fEM_R0UT02RZZ;
  S_scalzz_141_1.c = &fEM_R0UT01RZZ;
  S_scalzz_141_1.d = &fEM_R0UT02RZZ;
  S_scalzz_93_1.c = &fEM_A2UP04RZZ;
  S_scalzz_93_1.d = &fEM_A2UP03RZZ;
  S_scalzz_91_1.c = &fEM_A2UP04RZZ;
  S_scalzz_91_1.d = &fEM_A2UP03RZZ;
  S_drg_154_1.e = &fEM_R0UT72RZZ;
  S_drg_154_1.f = &fEM_R0UT71RZZ;
  S_drg_165_1.e = &fEM_R0UT62RZZ;
  S_drg_165_1.f = &fEM_R0UT61RZZ;
  S_bol_175_1.x1 = &fEM_R0UR04RZZ;
  S_bol_173_1.x1 = &fEM_R0UR01RZZ;
  S_tprg_129_1.e = &fEM_A2UP81RZZ;
  S_tprg_129_1.f = &fEM_A2UP82RZZ;
  S_tprg_129_1.c = &fEM_A2UP83RZZ;
  S_tprg_129_1.d = &fEM_A2UP84RZZ;
  S_tprg_123_1.e = &fEM_A2UP81RZZ;
  S_tprg_123_1.f = &fEM_A2UP82RZZ;
  S_tprg_123_1.c = &fEM_A2UP83RZZ;
  S_tprg_123_1.d = &fEM_A2UP84RZZ;
  S_drg_107_1.e = &fEM_A2UP41RZZ;
  S_drg_107_1.f = &fEM_A2UP42RZZ;
  S_drg_120_1.e = &fEM_A2UP51RZZ;
  S_drg_120_1.f = &fEM_A2UP52RZZ;
  S_drg_97_1.e = &fEM_A2UP41RZZ;
  S_drg_97_1.f = &fEM_A2UP42RZZ;
  S_drg_105_1.e = &fEM_A2UP51RZZ;
  S_drg_105_1.f = &fEM_A2UP52RZZ;
  S_drg_153_1.e = &fEM_R0UT72RZZ;
  S_drg_153_1.f = &fEM_R0UT71RZZ;
  S_drg_162_1.e = &fEM_R0UT62RZZ;
  S_drg_162_1.f = &fEM_R0UT61RZZ;
}
