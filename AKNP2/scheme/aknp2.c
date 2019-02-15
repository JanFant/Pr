#include "aknp2.h"
extern  func_ext1();
// ��
//  ��������� ���������� ����� D:\md\pti\pr\AKNP2\scheme\aknp2.tpr

#define PBLENGTH 8192
#ifndef SIMUL_MODE
char EEPROMType = 2;/*0 - absent, 1 - external, 2 - internal, 3 - misc*/
#else
char *SchemaName = "D:\md\pti\pr\AKNP2\scheme\aknp2.tpr";
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
#include <andn.h>
#include <bol.h>
#include <diagndev.h>
#include <ocham.h>
#include <or2.h>
#include <or3.h>
#include <orn.h>
#include <period.h>
#include <react.h>

/* ����������� ���������� ���������� */
#define bFirstEnterFlag (*((psbool)(InternalBuf+0x0)))
#define internal1_m15_Nk (*((psint)(InternalBuf+0x2))) /*Nk - ������� ������*/
#define internal1_m45_tst (*((psfloat)(InternalBuf+0x5))) /*- ������ ������� �������� ��������� ��������*/
#define internal1_m45_trz (*((psfloat)(InternalBuf+0x1E))) /*- ������ ������� �������� ���������� �������*/
#define internal1_m45_N1 (*((psfloat)(InternalBuf+0x37))) /*- ������ �������� �������� � ������ ������*/
#define internal1_m45_N2 (*((psfloat)(InternalBuf+0x50))) /*- ������ �������� �������� � ����� ������*/
#define internal1_m45_Period0 (*((psfloat)(InternalBuf+0x69))) /*Per - ������ ������� ��*/
#define internal1_m45_MyFirstEnterFlag (*((psbool)(InternalBuf+0x6E))) /* FirstEnterFlag*/
int InternalBufSize = 112;

/* ����������� �������� */
#define signal_R0VN02RS2     (*((psfloat)(PBSTART+0x0)))  /*                       ������� �������� ����� 2 */
#define signal_R0VN01RS2     (*((psfloat)(PBSTART+0x5)))  /*                       ������ ������� ����� 2 */
#define signal_R0VN61LS2     (*((psbool)(PBSTART+0xa)))  /*                       �� �� �������� ����� 2 */
#define signal_R0VN72LZ1     (*((psbool)(PBSTART+0xc)))  /*                       �� �� �������� ����� 2 �� ���1 */
#define signal_R0VN65LS2     (*((psbool)(PBSTART+0xe)))  /*                       �� �� ������� ������� ����� 2 */
#define signal_R0VN76LZ1     (*((psbool)(PBSTART+0x10)))  /*                       �� �� ������� ������� ����� 2  �� ���1 */
#define signal_A0EE01LS2     (*((psbool)(PBSTART+0x12)))  /*                       ����������� ���� ����� 2 �� ���1 */
#define signal_R0IN01FS2     (*((psfloat)(PBSTART+0x14)))  /*                       ����� ���-11 �� */
#define signal_R0IN02FS2     (*((psfloat)(PBSTART+0x19)))  /*                       ����� ���15-1  �� */
#define signal_R0VN03RS2     (*((psfloat)(PBSTART+0x1e)))  /*                       ���������� ���������� ����� ����� 2 */
#define signal_R0VN04RS2     (*((psfloat)(PBSTART+0x23)))  /*                       ������������ ����� 2 */
#define signal_A1VN71LS2     (*((psbool)(PBSTART+0x28)))  /*                       ���������� ��������������� ������� �� ����� 2 �� ���2 */
#define signal_R0IN03FS2     (*((psfloat)(PBSTART+0x2a)))  /*                       ����� ���53� �� */
#define signal_A0EE02LS2     (*((psbool)(PBSTART+0x2f)))  /*                       ����������� ����2 (�� ������ �������) ����� 2 */
#define signal_R0IE11LS2     (*((psbool)(PBSTART+0x31)))  /*                       ����������� ��� 1,6 (�11) ���11 2������ */
#define signal_R0IE12LS2     (*((psbool)(PBSTART+0x33)))  /*                       ����������� ��� 0,5 (�12) ���15-1 2 ������ */
#define signal_R0IE13LS2     (*((psbool)(PBSTART+0x35)))  /*                       ����������� ��� 0,5 (�13) ���53� 2 ������ */
#define signal_R0VN13RS2     (*((psfloat)(PBSTART+0x37)))  /*                       ���������� ����� �� ������ ���11 ����� 2 */
#define signal_R0VN23RS2     (*((psfloat)(PBSTART+0x3c)))  /*                       ���������� ����� �� ������ ���15-1 ����� 2 */
#define signal_R0VN33RS2     (*((psfloat)(PBSTART+0x41)))  /*                       ���������� ����� �� ������ ���53� ����� 2 */
#define signal_R0VN15RS2     (*((psint)(PBSTART+0x46)))  /*                       ����� ������� ������ ����� 2 */
#define signal_A0EE03LS2     (*((psbool)(PBSTART+0x49)))  /*                       ���������� ���� ������� ���� ����� 2 */
#define signal_R0IE01LS2     (*((psbool)(PBSTART+0x4b)))  /*                       ���������� ������� ���������� ����� 2 */
#define signal_R0IE02LS2     (*((psbool)(PBSTART+0x4d)))  /*                       ��������� ������� ��, �� ����� 2 */
#define signal_R0VN72LZ2     (*((psbool)(PBSTART+0x4f)))  /*                       �� �� �������� ����� 2 �� ���2 */
#define signal_R0VN76LZ2     (*((psbool)(PBSTART+0x51)))  /*                       �� �� ������� ������� ����� 2  �� ���2 */
#define signal_A1EE01LS2     (*((psbool)(PBSTART+0x53)))  /*                       ����������� ���� ����� 2 �� ���2 */
#define signal_A0VN71LS2     (*((psbool)(PBSTART+0x55)))  /*                       ���������� ��������������� ������� �� ����� 2 �� ���1 */
#define signal_B8VC01RDU     (*((psfloat)(PBSTART+0x57)))  /*                       ���������� ��2, �� */
#define signal_R0EE02LZ1     (*((psbool)(PBSTART+0x5c)))  /*                       �������  ����  ��������� */
#define signal_R0EE02LZ2     (*((psbool)(PBSTART+0x5e)))  /*                       �������  ����  ��������� */
#define signal_R0DE01LS2     (*((psint)(PBSTART+0x60)))  /*                       ����������� ������ ����2 �� 1 ����� */
#define signal_R0DE02LS2     (*((psint)(PBSTART+0x63)))  /*                       ����������� ������ ����2 �� 2 ����� */
#define signal_R0DE04LS2     (*((psint)(PBSTART+0x66)))  /*                       ����������� ������ ����2 �� 4 ����� */
#define signal_R0DE05LS2     (*((psint)(PBSTART+0x69)))  /*                       ����������� ������ ����2 �� 5 ����� */
#define signal_TTLaknp2      (*((psint)(PBSTART+0x6c)))  /*                       TTL */
#define signal_R0DE31LS2     (*((psbool)(PBSTART+0x6f)))  /*                       ����������� ����� ����2 ���� 1 */
#define signal_R0DE32LS2     (*((psbool)(PBSTART+0x71)))  /*                       ����������� ����� ����2 ���� 2 */
#define signal_R0DE33LS2     (*((psbool)(PBSTART+0x73)))  /*                       ����������� ����� ����2 ����� */
#define signal_R0DE34LS2     (*((psbool)(PBSTART+0x75)))  /*                       ����������� ����� ����2 ����������� ������ 43 */
#define signal_R0DE35LS2     (*((psbool)(PBSTART+0x77)))  /*                       ����������� ����� ����2 ����������� ������ 53 */
#define signal_R0DE36LS2     (*((psbool)(PBSTART+0x79)))  /*                       ����������� ����� ����2 ��15-3.1 ����� 1 */
#define signal_R0DE37LS2     (*((psbool)(PBSTART+0x7b)))  /*                       ����������� ����� ����2 ��15-3.1 ����� 2 */
#define signal_R0DE38LS2     (*((psbool)(PBSTART+0x7d)))  /*                       ����������� ����� ����2 ��15-3 ����� 3 */
#define signal_R0DE39LS2     (*((psbool)(PBSTART+0x7f)))  /*                       ����������� ����� ����2 ��24-2 ����� 4 */
#define signal_R0DE3ALS2     (*((psbool)(PBSTART+0x81)))  /*                       ����������� ����� ����2 ��5/24� ����� 5 */
#define signal_R0DE3BLS2     (*((psbool)(PBSTART+0x83)))  /*                       ����������� ����� ����2 ��5/24� ����� 6 */
#define signal_R0DE3CLS2     (*((psbool)(PBSTART+0x85)))  /*                       ����������� ����� ����2 ��5/24� ����� 7 */
#define signal_R0DE3DLS2     (*((psbool)(PBSTART+0x87)))  /*                       ����������� ����� ����2 ��5/24� ����� 8 */
#define signal_TestDiagnAKNP2 (*((psbool)(PBSTART+0x89)))  /*                       ������������� �� ����������� */

/* ����������� �������� ��� � ������*/
struct       sint  iRM_5_ = {    5,0}; /* n - N-����������� ������� ������� ���������� */ 
struct       sint  iRM_2_ = {    2,0}; /* n - N-����������� ������� ������� ���������� */ 
struct     sfloat  fRM_2_0 = {  2.0,0}; /* Kpr1 - �����. �������������� �������->�����/� ���-11 */ 
struct      schar  bRM_2_ = {    2,0}; /* type - ��� ������ ���-11 1- ��� ��1, 2- ��� ��2, >2 ��� */ 
struct       sint  iRM_4_ = {    4,0}; /*  */ 
struct       sint  iRM_8_ = {    8,0}; /*  */ 
#define fEM_R0UR01RSS  (*((psfloat)(SpaEEPROMBuf+0x0)))
#define fEM_R0UL52RSS  (*((psfloat)(SpaEEPROMBuf+0x5)))
#define fEM_R0UL41RSS  (*((psfloat)(SpaEEPROMBuf+0xA)))
#define fEM_R0UL51RSS  (*((psfloat)(SpaEEPROMBuf+0xF)))
#define fEM_R0UH02RSS  (*((psfloat)(SpaEEPROMBuf+0x14)))
#define fEM_R0UH03RSS  (*((psfloat)(SpaEEPROMBuf+0x19)))
#define fEM_R0UL42RSS  (*((psfloat)(SpaEEPROMBuf+0x1E)))
#define fEM_R7UX00RSS  (*((psfloat)(SpaEEPROMBuf+0x23)))
#define fEM_R7UX04RSS  (*((psfloat)(SpaEEPROMBuf+0x28)))
#define fEM_R7UX05RSS  (*((psfloat)(SpaEEPROMBuf+0x2D)))
#define fEM_R7UX06RSS  (*((psfloat)(SpaEEPROMBuf+0x32)))
#define fEM_R7UY00RSS  (*((psfloat)(SpaEEPROMBuf+0x37)))
#define fEM_R7UY04RSS  (*((psfloat)(SpaEEPROMBuf+0x3C)))
#define fEM_R7UY05RSS  (*((psfloat)(SpaEEPROMBuf+0x41)))
#define fEM_R7UY06RSS  (*((psfloat)(SpaEEPROMBuf+0x46)))
#define fEM_A0UX00RSS  (*((psfloat)(SpaEEPROMBuf+0x4B)))
#define fEM_A0UX04RSS  (*((psfloat)(SpaEEPROMBuf+0x50)))
#define fEM_A0UX05RSS  (*((psfloat)(SpaEEPROMBuf+0x55)))
#define fEM_A0UX06RSS  (*((psfloat)(SpaEEPROMBuf+0x5A)))
#define fEM_B0UX04RSS  (*((psfloat)(SpaEEPROMBuf+0x5F)))
#define fEM_B0UX05RSS  (*((psfloat)(SpaEEPROMBuf+0x64)))
#define fEM_B0UX06RSS  (*((psfloat)(SpaEEPROMBuf+0x69)))
#define fEM_R0UH05RSS  (*((psfloat)(SpaEEPROMBuf+0x6E)))
#define iEM_R0UL01ISS  (*((psint)(SpaEEPROMBuf+0x73)))
#define dEM_R0UL02USS  (*((pslong)(SpaEEPROMBuf+0x76)))
#define fEM_R0UN03RSS  (*((psfloat)(SpaEEPROMBuf+0x7B)))

int SpaEEPROMBufSize = 128;

/* ����������� ���������� */
struct sbool  var1;
struct sbool  var2;
struct sbool  var3;
struct sbool  var4;
struct sint  var5;
struct sfloat  var6;
struct sfloat  var7;
struct sbool  var8;
struct sfloat  var9;
struct sfloat  var10;
struct sfloat  var11;
struct sint  var12;
struct sbool  var13;
struct sfloat  var14;
struct sbool  var15;
struct sbool  var16;
struct sbool  var17;
struct sbool  var18;
struct sbool  var19;
struct sbool  var20;
struct sbool  var21;
struct sbool  var22;
struct sfloat  var23;
struct sbool  var24;
struct sfloat  var25;
struct sfloat  var26;
struct slong  vainSLong;
struct sfloat  vainSFloat;
struct sint  vainSInt;
struct sbool  vainSBool;
struct schar  vainSChar;
char  vainSText[] = "";

/* ���������� �������� */
psbool  array_m88_x_1[8] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
psint  array_m78_x_1[4] = {NULL,NULL,NULL,NULL};
psfloat  array_m45_tst_1[5];
psfloat  array_m45_trz_1[5];
psfloat  array_m45_N1_1[5];
psfloat  array_m45_N2_1[5];
psbool  array_m55_x_1[2] = {&var21,&var16};
psbool  array_m54_x_1[2] = {&var21,&var22};
psbool  array_m65_x_1[5] = {&var8,NULL,NULL,NULL,NULL};

/* �������� �������� ��� �-�� */

/* ��� ���������� */
/* ���������� �������� */
_S_or3 far S_or3_83_1 = {&var4,&var3,&var2,&var1};
_S_orn far S_orn_88_1 = {array_m88_x_1,&iRM_8_,&var2};
_S_and2 far S_and2_79_1 = {NULL,NULL,&var3};
_S_diagndev far S_diagndev_78_1 = {array_m78_x_1,&iRM_4_,&var4,&var5};
_S_ocham far S_ocham_15_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_2_,&fRM_2_0,NULL,NULL,NULL,&var6,&var7,&var8,&var9,&var10,&var11,&var12,NULL};
_S_or2 far S_or2_66_1 = {NULL,NULL,&var13};
_S_period far S_period_45_1 = {&var7,&var18,&iRM_5_,&var25,&var26,NULL,&var14,array_m45_tst_1,array_m45_trz_1,array_m45_N1_1,array_m45_N2_1,NULL,NULL};
_S_andn far S_andn_55_1 = {array_m55_x_1,&iRM_2_,&var15};
_S_bol far S_bol_52_1 = {NULL,&var14,&var16};
_S_andn far S_andn_54_1 = {array_m54_x_1,&iRM_2_,&var17};
_S_andn far S_andn_65_1 = {array_m65_x_1,&iRM_5_,&var18};
_S_bol far S_bol_35_1 = {&var7,NULL,&var19};
_S_bol far S_bol_40_1 = {&var7,NULL,&var20};
_S_bol far S_bol_51_1 = {&var7,NULL,&var21};
_S_bol far S_bol_50_1 = {NULL,&var14,&var22};
_S_react far S_react_46_1 = {&var14,&var23};
_S_bol far S_bol_31_1 = {&var7,NULL,&var24};


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
  or2((&S_or2_66_1));
  ocham((&S_ocham_15_1));
  diagndev((&S_diagndev_78_1));
  and2((&S_and2_79_1));
  orn((&S_orn_88_1));
  or3((&S_or3_83_1));
  bol((&S_bol_31_1));
  bol((&S_bol_51_1));
  bol((&S_bol_40_1));
  bol((&S_bol_35_1));
  andn((&S_andn_65_1));
  itof(iEM_R0UL01ISS.i,&var25.f);
  var25.error = iEM_R0UL01ISS.error;
  utof(dEM_R0UL02USS.l,&var26.f);
  var26.error = dEM_R0UL02USS.error;
  period((&S_period_45_1));
  react((&S_react_46_1));
  bol((&S_bol_50_1));
  andn((&S_andn_54_1));
  bol((&S_bol_52_1));
  andn((&S_andn_55_1));
  signal_TestDiagnAKNP2.b = var1.b;
  signal_TestDiagnAKNP2.error = var1.error;
  signal_TTLaknp2.i = var5.i;
  signal_TTLaknp2.error = var5.error;
  signal_A0VN71LS2.b = var24.b;
  signal_A0VN71LS2.error = var24.error;
  signal_A1EE01LS2.b = var18.b;
  signal_A1EE01LS2.error = var18.error;
  signal_R0VN76LZ2.b = var17.b;
  signal_R0VN76LZ2.error = var17.error;
  signal_R0VN72LZ2.b = var19.b;
  signal_R0VN72LZ2.error = var19.error;
  signal_R0IE02LS2.b = var13.b;
  signal_R0IE02LS2.error = var13.error;
  signal_R0IE01LS2.b = var13.b;
  signal_R0IE01LS2.error = var13.error;
  signal_R0VN15RS2.i = var12.i;
  signal_R0VN15RS2.error = var12.error;
  fplet(&signal_R0VN33RS2.f,&var11.f);
  signal_R0VN33RS2.error = var11.error;
  fplet(&signal_R0VN23RS2.f,&var10.f);
  signal_R0VN23RS2.error = var10.error;
  fplet(&signal_R0VN13RS2.f,&var9.f);
  signal_R0VN13RS2.error = var9.error;
  signal_A0EE02LS2.b = var8.b;
  signal_A0EE02LS2.error = var8.error;
  signal_A1VN71LS2.b = var24.b;
  signal_A1VN71LS2.error = var24.error;
  fplet(&signal_R0VN04RS2.f,&var23.f);
  signal_R0VN04RS2.error = var23.error;
  fplet(&signal_R0VN03RS2.f,&var6.f);
  signal_R0VN03RS2.error = var6.error;
  signal_A0EE01LS2.b = var18.b;
  signal_A0EE01LS2.error = var18.error;
  signal_R0VN76LZ1.b = var17.b;
  signal_R0VN76LZ1.error = var17.error;
  signal_R0VN65LS2.b = var15.b;
  signal_R0VN65LS2.error = var15.error;
  signal_R0VN72LZ1.b = var19.b;
  signal_R0VN72LZ1.error = var19.error;
  signal_R0VN61LS2.b = var20.b;
  signal_R0VN61LS2.error = var20.error;
  fplet(&signal_R0VN01RS2.f,&var14.f);
  signal_R0VN01RS2.error = var14.error;
  fplet(&signal_R0VN02RS2.f,&var7.f);
  signal_R0VN02RS2.error = var7.error;

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
  CheckSFloat(20);
#else
ParExchange("R0IN01FS2",1,&SignalBuffer[20],"����� ���-11 ��",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(25);
#else
ParExchange("R0IN02FS2",1,&SignalBuffer[25],"����� ���15-1  ��",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(42);
#else
ParExchange("R0IN03FS2",1,&SignalBuffer[42],"����� ���53� ��",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(49);
#else
ParExchange("R0IE11LS2",3,&SignalBuffer[49],"����������� ��� 1,6 (�11) ���11 2������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(51);
#else
ParExchange("R0IE12LS2",3,&SignalBuffer[51],"����������� ��� 0,5 (�12) ���15-1 2 ������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(53);
#else
ParExchange("R0IE13LS2",3,&SignalBuffer[53],"����������� ��� 0,5 (�13) ���53� 2 ������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(73);
#else
ParExchange("A0EE03LS2",3,&SignalBuffer[73],"���������� ���� ������� ���� ����� 2",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(87);
#else
ParExchange("B8VC01RDU",1,&SignalBuffer[87],"���������� ��2, ��",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(92);
#else
ParExchange("R0EE02LZ1",3,&SignalBuffer[92],"�������  ����  ���������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(94);
#else
ParExchange("R0EE02LZ2",3,&SignalBuffer[94],"�������  ����  ���������",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(96);
#else
ParExchange("R0DE01LS2",2,&SignalBuffer[96],"����������� ������ ����2 �� 1 �����",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(99);
#else
ParExchange("R0DE02LS2",2,&SignalBuffer[99],"����������� ������ ����2 �� 2 �����",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(102);
#else
ParExchange("R0DE04LS2",2,&SignalBuffer[102],"����������� ������ ����2 �� 4 �����",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(105);
#else
ParExchange("R0DE05LS2",2,&SignalBuffer[105],"����������� ������ ����2 �� 5 �����",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(111);
#else
ParExchange("R0DE31LS2",3,&SignalBuffer[111],"����������� ����� ����2 ���� 1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(113);
#else
ParExchange("R0DE32LS2",3,&SignalBuffer[113],"����������� ����� ����2 ���� 2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(115);
#else
ParExchange("R0DE33LS2",3,&SignalBuffer[115],"����������� ����� ����2 �����",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(117);
#else
ParExchange("R0DE34LS2",3,&SignalBuffer[117],"����������� ����� ����2 ����������� ������ 43",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(119);
#else
ParExchange("R0DE35LS2",3,&SignalBuffer[119],"����������� ����� ����2 ����������� ������ 53",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(121);
#else
ParExchange("R0DE36LS2",3,&SignalBuffer[121],"����������� ����� ����2 ��15-3.1 ����� 1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(123);
#else
ParExchange("R0DE37LS2",3,&SignalBuffer[123],"����������� ����� ����2 ��15-3.1 ����� 2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(125);
#else
ParExchange("R0DE38LS2",3,&SignalBuffer[125],"����������� ����� ����2 ��15-3 ����� 3",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(127);
#else
ParExchange("R0DE39LS2",3,&SignalBuffer[127],"����������� ����� ����2 ��24-2 ����� 4",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(129);
#else
ParExchange("R0DE3ALS2",3,&SignalBuffer[129],"����������� ����� ����2 ��5/24� ����� 5",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(131);
#else
ParExchange("R0DE3BLS2",3,&SignalBuffer[131],"����������� ����� ����2 ��5/24� ����� 6",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(133);
#else
ParExchange("R0DE3CLS2",3,&SignalBuffer[133],"����������� ����� ����2 ��5/24� ����� 7",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(135);
#else
ParExchange("R0DE3DLS2",3,&SignalBuffer[135],"����������� ����� ����2 ��5/24� ����� 8",0);
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
 for(counter=0; counter<139; counter++) {
   *((unsigned char*)(SignalBuffer)+PBLENGTH-counter-1) =
          (unsigned char)~(*((unsigned char*)(SignalBuffer)+counter));
 }
#endif
}
#endif
#ifdef SIMUL_MODE
void UnloadSignals()
{
ParExchange("R0VN02RS2",1,&SignalBuffer[0],"������� �������� ����� 2",1);
ParExchange("R0VN01RS2",1,&SignalBuffer[5],"������ ������� ����� 2",1);
ParExchange("R0VN61LS2",3,&SignalBuffer[10],"�� �� �������� ����� 2",1);
ParExchange("R0VN72LZ1",3,&SignalBuffer[12],"�� �� �������� ����� 2 �� ���1",1);
ParExchange("R0VN65LS2",3,&SignalBuffer[14],"�� �� ������� ������� ����� 2",1);
ParExchange("R0VN76LZ1",3,&SignalBuffer[16],"�� �� ������� ������� ����� 2  �� ���1",1);
ParExchange("A0EE01LS2",3,&SignalBuffer[18],"����������� ���� ����� 2 �� ���1",1);
ParExchange("R0VN03RS2",1,&SignalBuffer[30],"���������� ���������� ����� ����� 2",1);
ParExchange("R0VN04RS2",1,&SignalBuffer[35],"������������ ����� 2",1);
ParExchange("A1VN71LS2",3,&SignalBuffer[40],"���������� ��������������� ������� �� ����� 2 �� ���2",1);
ParExchange("A0EE02LS2",3,&SignalBuffer[47],"����������� ����2 (�� ������ �������) ����� 2",1);
ParExchange("R0VN13RS2",1,&SignalBuffer[55],"���������� ����� �� ������ ���11 ����� 2",1);
ParExchange("R0VN23RS2",1,&SignalBuffer[60],"���������� ����� �� ������ ���15-1 ����� 2",1);
ParExchange("R0VN33RS2",1,&SignalBuffer[65],"���������� ����� �� ������ ���53� ����� 2",1);
ParExchange("R0VN15RS2",2,&SignalBuffer[70],"����� ������� ������ ����� 2",1);
ParExchange("R0IE01LS2",3,&SignalBuffer[75],"���������� ������� ���������� ����� 2",1);
ParExchange("R0IE02LS2",3,&SignalBuffer[77],"��������� ������� ��, �� ����� 2",1);
ParExchange("R0VN72LZ2",3,&SignalBuffer[79],"�� �� �������� ����� 2 �� ���2",1);
ParExchange("R0VN76LZ2",3,&SignalBuffer[81],"�� �� ������� ������� ����� 2  �� ���2",1);
ParExchange("A1EE01LS2",3,&SignalBuffer[83],"����������� ���� ����� 2 �� ���2",1);
ParExchange("A0VN71LS2",3,&SignalBuffer[85],"���������� ��������������� ������� �� ����� 2 �� ���1",1);
ParExchange("TTLaknp2",2,&SignalBuffer[108],"TTL",1);
ParExchange("TestDiagnAKNP2",3,&SignalBuffer[137],"������������� �� �����������",1);
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
NewEEPROM("fEM_R0UR01RSS",1,&fEM_R0UR01RSS,"������� ���� ���������� ��������������� ������� ��(���/���)","5000");
NewEEPROM("fEM_R0UL52RSS",1,&fEM_R0UL52RSS,"������� �� �� ��������","5100");
NewEEPROM("fEM_R0UL41RSS",1,&fEM_R0UL41RSS,"������� �� �� ������� �������","30");
NewEEPROM("fEM_R0UL51RSS",1,&fEM_R0UL51RSS,"������� �� �� ������� �������","20.0");
NewEEPROM("fEM_R0UH02RSS",1,&fEM_R0UH02RSS,"�����. �������������� �������->�����/� ���15-1","3703.704 ");
NewEEPROM("fEM_R0UH03RSS",1,&fEM_R0UH03RSS,"�����. �������������� �������->�����/� ���53�","62500.0");
NewEEPROM("fEM_R0UL42RSS",1,&fEM_R0UL42RSS,"������� �� �� ��������","5000");
NewEEPROM("fEM_R7UX00RSS",1,&fEM_R7UX00RSS,"X-���������� ��1 (��)","1567.36");
NewEEPROM("fEM_R7UX04RSS",1,&fEM_R7UX04RSS,"X-���������� ������ R7IN21 (��)","1555.0");
NewEEPROM("fEM_R7UX05RSS",1,&fEM_R7UX05RSS,"X-���������� ������ R7IN22 (��)","1269.0");
NewEEPROM("fEM_R7UX06RSS",1,&fEM_R7UX06RSS,"Y-���������� ������ R7IN23 (��)","1269.0");
NewEEPROM("fEM_R7UY00RSS",1,&fEM_R7UY00RSS,"Y-���������� ��1 (��)","506.5");
NewEEPROM("fEM_R7UY04RSS",1,&fEM_R7UY04RSS,"Y-���������� ������ R7IN21 (��)","248.0");
NewEEPROM("fEM_R7UY05RSS",1,&fEM_R7UY05RSS,"Y-���������� ������ R7IN22 (��)","271.6");
NewEEPROM("fEM_R7UY06RSS",1,&fEM_R7UY06RSS,"Y-���������� ������ R7IN23 (��)","287.2");
NewEEPROM("fEM_A0UX00RSS",1,&fEM_A0UX00RSS,"����������� ������ ��","11.0");
NewEEPROM("fEM_A0UX04RSS",1,&fEM_A0UX04RSS,"������ ����������� ���������� ������4","1.0");
NewEEPROM("fEM_A0UX05RSS",1,&fEM_A0UX05RSS,"������ ����������� ���������� ������ 5","1.0");
NewEEPROM("fEM_A0UX06RSS",1,&fEM_A0UX06RSS,"������ ����������� ���������� ������ 6","1.0");
NewEEPROM("fEM_B0UX04RSS",1,&fEM_B0UX04RSS,"������ ����������� ���������� ������4","0");
NewEEPROM("fEM_B0UX05RSS",1,&fEM_B0UX05RSS,"������ ����������� ���������� ������ 5","0.0");
NewEEPROM("fEM_B0UX06RSS",1,&fEM_B0UX06RSS,"������ ����������� ���������� ������ 6","0");
NewEEPROM("fEM_R0UH05RSS",1,&fEM_R0UH05RSS,"���-�� �������/��� �� 1 ���� * E^6","32000.0");
NewEEPROM("iEM_R0UL01ISS",2,&iEM_R0UL01ISS,"��� (��) ��������� �������","500");
NewEEPROM("dEM_R0UL02USS",7,&dEM_R0UL02USS,"���������� ����� �������� ����� ������ (��)","100000");
NewEEPROM("fEM_R0UN03RSS",1,&fEM_R0UN03RSS,"������ ������� ��������� �������� ��� ��������� ������� (����)","0.005");
#else
if(EEPROMFlag) {
  fplet(&fEM_R0UR01RSS.f,((float*)(IntEEPROMBuffer+0x0)));
  fEM_R0UR01RSS.error = 0;
  fplet(&fEM_R0UL52RSS.f,((float*)(IntEEPROMBuffer+0x4)));
  fEM_R0UL52RSS.error = 0;
  fplet(&fEM_R0UL41RSS.f,((float*)(IntEEPROMBuffer+0x8)));
  fEM_R0UL41RSS.error = 0;
  fplet(&fEM_R0UL51RSS.f,((float*)(IntEEPROMBuffer+0xC)));
  fEM_R0UL51RSS.error = 0;
  fplet(&fEM_R0UH02RSS.f,((float*)(IntEEPROMBuffer+0x10)));
  fEM_R0UH02RSS.error = 0;
  fplet(&fEM_R0UH03RSS.f,((float*)(IntEEPROMBuffer+0x14)));
  fEM_R0UH03RSS.error = 0;
  fplet(&fEM_R0UL42RSS.f,((float*)(IntEEPROMBuffer+0x18)));
  fEM_R0UL42RSS.error = 0;
  fplet(&fEM_R7UX00RSS.f,((float*)(IntEEPROMBuffer+0x1C)));
  fEM_R7UX00RSS.error = 0;
  fplet(&fEM_R7UX04RSS.f,((float*)(IntEEPROMBuffer+0x20)));
  fEM_R7UX04RSS.error = 0;
  fplet(&fEM_R7UX05RSS.f,((float*)(IntEEPROMBuffer+0x24)));
  fEM_R7UX05RSS.error = 0;
  fplet(&fEM_R7UX06RSS.f,((float*)(IntEEPROMBuffer+0x28)));
  fEM_R7UX06RSS.error = 0;
  fplet(&fEM_R7UY00RSS.f,((float*)(IntEEPROMBuffer+0x2C)));
  fEM_R7UY00RSS.error = 0;
  fplet(&fEM_R7UY04RSS.f,((float*)(IntEEPROMBuffer+0x30)));
  fEM_R7UY04RSS.error = 0;
  fplet(&fEM_R7UY05RSS.f,((float*)(IntEEPROMBuffer+0x34)));
  fEM_R7UY05RSS.error = 0;
  fplet(&fEM_R7UY06RSS.f,((float*)(IntEEPROMBuffer+0x38)));
  fEM_R7UY06RSS.error = 0;
  fplet(&fEM_A0UX00RSS.f,((float*)(IntEEPROMBuffer+0x3C)));
  fEM_A0UX00RSS.error = 0;
  fplet(&fEM_A0UX04RSS.f,((float*)(IntEEPROMBuffer+0x40)));
  fEM_A0UX04RSS.error = 0;
  fplet(&fEM_A0UX05RSS.f,((float*)(IntEEPROMBuffer+0x44)));
  fEM_A0UX05RSS.error = 0;
  fplet(&fEM_A0UX06RSS.f,((float*)(IntEEPROMBuffer+0x48)));
  fEM_A0UX06RSS.error = 0;
  fplet(&fEM_B0UX04RSS.f,((float*)(IntEEPROMBuffer+0x4C)));
  fEM_B0UX04RSS.error = 0;
  fplet(&fEM_B0UX05RSS.f,((float*)(IntEEPROMBuffer+0x50)));
  fEM_B0UX05RSS.error = 0;
  fplet(&fEM_B0UX06RSS.f,((float*)(IntEEPROMBuffer+0x54)));
  fEM_B0UX06RSS.error = 0;
  fplet(&fEM_R0UH05RSS.f,((float*)(IntEEPROMBuffer+0x58)));
  fEM_R0UH05RSS.error = 0;
  iEM_R0UL01ISS.i = *((__int16*)(IntEEPROMBuffer+0x5C));
  iEM_R0UL01ISS.error = 0;
  dEM_R0UL02USS.l = *((long*)(IntEEPROMBuffer+0x5E));
  dEM_R0UL02USS.error = 0;
  fplet(&fEM_R0UN03RSS.f,((float*)(IntEEPROMBuffer+0x62)));
  fEM_R0UN03RSS.error = 0;
}
#endif
}

#ifndef SIMUL_MODE
unsigned int EndIntEEPROMAddress = 102;
#endif

void reInit_Signals(void)
{
  S_and2_79_1.x1 = &signal_R0DE31LS2;
  S_and2_79_1.x2 = &signal_R0DE32LS2;
  S_ocham_15_1.Ch1k = &signal_R0IN01FS2;
  S_ocham_15_1.Ch2k = &signal_R0IN02FS2;
  S_ocham_15_1.Ch3k = &signal_R0IN03FS2;
  S_ocham_15_1.YAz2 = &signal_B8VC01RDU;
  S_or2_66_1.x1 = &signal_R0EE02LZ1;
  S_or2_66_1.x2 = &signal_R0EE02LZ2;
  array_m88_x_1[0] = &signal_R0DE36LS2;
  array_m88_x_1[1] = &signal_R0DE3CLS2;
  array_m88_x_1[2] = &signal_R0DE37LS2;
  array_m88_x_1[3] = &signal_R0DE38LS2;
  array_m88_x_1[4] = &signal_R0DE39LS2;
  array_m88_x_1[5] = &signal_R0DE3ALS2;
  array_m88_x_1[6] = &signal_R0DE3BLS2;
  array_m88_x_1[7] = &signal_R0DE3DLS2;
  array_m78_x_1[0] = &signal_R0DE01LS2;
  array_m78_x_1[1] = &signal_R0DE02LS2;
  array_m78_x_1[2] = &signal_R0DE04LS2;
  array_m78_x_1[3] = &signal_R0DE05LS2;
  array_m65_x_1[1] = &signal_R0IE11LS2;
  array_m65_x_1[2] = &signal_R0IE12LS2;
  array_m65_x_1[3] = &signal_R0IE13LS2;
  array_m65_x_1[4] = &signal_A0EE03LS2;
}

void InitInternalParametr(void)
{
  int i;
  S_ocham_15_1.Nk = &internal1_m15_Nk;
  S_period_45_1.Period0 = &internal1_m45_Period0;
  S_period_45_1.MyFirstEnterFlag = &internal1_m45_MyFirstEnterFlag;
  S_ocham_15_1.XAz = &fEM_R7UX00RSS;
  S_ocham_15_1.YAz1 = &fEM_R7UY00RSS;
  S_ocham_15_1.Reff = &fEM_A0UX00RSS;
  S_ocham_15_1.Ak1 = &fEM_A0UX04RSS;
  S_ocham_15_1.Bk1 = &fEM_B0UX04RSS;
  S_ocham_15_1.Ak2 = &fEM_A0UX05RSS;
  S_ocham_15_1.Bk2 = &fEM_B0UX05RSS;
  S_ocham_15_1.Ak3 = &fEM_A0UX06RSS;
  S_ocham_15_1.Bk3 = &fEM_B0UX06RSS;
  S_ocham_15_1.XCm1 = &fEM_R7UX04RSS;
  S_ocham_15_1.YCm1 = &fEM_R7UY04RSS;
  S_ocham_15_1.XCm2 = &fEM_R7UX05RSS;
  S_ocham_15_1.YCm2 = &fEM_R7UY05RSS;
  S_ocham_15_1.XCm3 = &fEM_R7UX06RSS;
  S_ocham_15_1.YCm3 = &fEM_R7UY06RSS;
  S_ocham_15_1.Kpr2k = &fEM_R0UH02RSS;
  S_ocham_15_1.Kpr3k = &fEM_R0UH03RSS;
  S_ocham_15_1.Kprm = &fEM_R0UH05RSS;
  S_period_45_1.Nmin = &fEM_R0UN03RSS;
  S_bol_52_1.x1 = &fEM_R0UL41RSS;
  S_bol_35_1.x2 = &fEM_R0UL52RSS;
  S_bol_40_1.x2 = &fEM_R0UL42RSS;
  S_bol_51_1.x2 = &fEM_R0UN03RSS;
  S_bol_50_1.x1 = &fEM_R0UL51RSS;
  S_bol_31_1.x2 = &fEM_R0UR01RSS;
  for( i=0;i<5;i++ )
    array_m45_tst_1[i] = &(&internal1_m45_tst)[i];
  for( i=0;i<5;i++ )
    array_m45_trz_1[i] = &(&internal1_m45_trz)[i];
  for( i=0;i<5;i++ )
    array_m45_N1_1[i] = &(&internal1_m45_N1)[i];
  for( i=0;i<5;i++ )
    array_m45_N2_1[i] = &(&internal1_m45_N2)[i];
}
