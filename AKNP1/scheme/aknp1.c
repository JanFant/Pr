#include "aknp1.h"
extern  func_ext1();
// ��
//  ��������� ���������� ����� D:\md\pti\pr\AKNP1\scheme\aknp1.tpr

#define PBLENGTH 8192
#ifndef SIMUL_MODE
char EEPROMType = 2;/*0 - absent, 1 - external, 2 - internal, 3 - misc*/
#else
char *SchemaName = "D:\md\pti\pr\AKNP1\scheme\aknp1.tpr";
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
#include <and5.h>
#include <bol.h>
#include <ocham.h>
#include <or2.h>
#include <period.h>
#include <react.h>

/* ����������� ���������� ���������� */
#define bFirstEnterFlag (*((psbool)(InternalBuf+0x0)))
#define internal1_m13_Nk (*((psint)(InternalBuf+0x2))) /*Nk - ������� ������*/
#define internal1_m45_tst (*((psfloat)(InternalBuf+0x5))) /*- ������ ������� �������� ��������� ��������*/
#define internal1_m45_trz (*((psfloat)(InternalBuf+0x1E))) /*- ������ ������� �������� ���������� �������*/
#define internal1_m45_N1 (*((psfloat)(InternalBuf+0x37))) /*- ������ �������� �������� � ������ ������*/
#define internal1_m45_N2 (*((psfloat)(InternalBuf+0x50))) /*- ������ �������� �������� � ����� ������*/
#define internal1_m45_Period0 (*((psfloat)(InternalBuf+0x69))) /*Per - ������ ������� ��*/
#define internal1_m45_MyFirstEnterFlag (*((psbool)(InternalBuf+0x6E))) /* FirstEnterFlag*/
int InternalBufSize = 112;

/* ����������� �������� */
#define signal_R0VN02RS1     (*((psfloat)(PBSTART+0x0)))  /*                       ������� �������� */
#define signal_R0VN01RS1     (*((psfloat)(PBSTART+0x5)))  /*                       ������ ������� �����1 */
#define signal_R0VN61LS1     (*((psbool)(PBSTART+0xa)))  /*                       �� �� �������� �����1 */
#define signal_R0VN71LZ1     (*((psbool)(PBSTART+0xc)))  /*                       �� �� �������� �� ���1 */
#define signal_R0VN65LS1     (*((psbool)(PBSTART+0xe)))  /*                       �� �� ������� ������� �����1 */
#define signal_R0VN75LZ1     (*((psbool)(PBSTART+0x10)))  /*                       �� �� ������� ��������� ���1 */
#define signal_A0EE01LS1     (*((psbool)(PBSTART+0x12)))  /*                       ����������� ���� �� ���1 */
#define signal_R0IN01FS1     (*((psfloat)(PBSTART+0x14)))  /*                       ����� ���-11 �� */
#define signal_R0IN02FS1     (*((psfloat)(PBSTART+0x19)))  /*                       ����� ���15-1 �� */
#define signal_R0VN03RS1     (*((psfloat)(PBSTART+0x1e)))  /*                       ���������� ���������� ����� */
#define signal_R0VN04RS1     (*((psfloat)(PBSTART+0x23)))  /*                       ������������ �����1 */
#define signal_A0VN71LS1     (*((psbool)(PBSTART+0x28)))  /*                       ���������� ���������������  ������� �� �� ���1 */
#define signal_R0IN03FS1     (*((psfloat)(PBSTART+0x2a)))  /*                       ����� ���53�  �� */
#define signal_A0EE02LS1     (*((psbool)(PBSTART+0x2f)))  /*                       ����������� ����1 (�� ������ �������) ����� 1 */
#define signal_R0IE11LS1     (*((psbool)(PBSTART+0x31)))  /*                       ����������� ��� 1,6 (�8) ���11 1 ������ */
#define signal_R0IE12LS1     (*((psbool)(PBSTART+0x33)))  /*                       ����������� ��� 0,5 (�9) ���15-1 1 ������ */
#define signal_R0IE13LS1     (*((psbool)(PBSTART+0x35)))  /*                       ����������� ��� 0,5 (�10) ���53� 1 ������ */
#define signal_R0VN13RS1     (*((psfloat)(PBSTART+0x37)))  /*                       ���������� ����� �� ������ ���11 */
#define signal_R0VN23RS1     (*((psfloat)(PBSTART+0x3c)))  /*                       ���������� ����� �� ������ ���15-1 */
#define signal_R0VN33RS1     (*((psfloat)(PBSTART+0x41)))  /*                       ���������� ����� �� ������ ���53� */
#define signal_R0VN15RS1     (*((psint)(PBSTART+0x46)))  /*                       ����� ������� ������ 1-���-11,2-���-15�-1,3-���-53�,0-��� ������� */
#define signal_A0EE03LS1     (*((psbool)(PBSTART+0x49)))  /*                       ���������� ���� ������� ���� */
#define signal_R0IE01LS1     (*((psbool)(PBSTART+0x4b)))  /*                       ���������� ������� ���������� */
#define signal_R0IE02LS1     (*((psbool)(PBSTART+0x4d)))  /*                       ��������� ������� ��, �� */
#define signal_R0VN71LZ2     (*((psbool)(PBSTART+0x4f)))  /*                       �� �� �������� �� ���2 */
#define signal_R0VN75LZ2     (*((psbool)(PBSTART+0x51)))  /*                       �� �� ������� ��������� ���2 */
#define signal_A1EE01LS1     (*((psbool)(PBSTART+0x53)))  /*                       ����������� ���� �� ���2 */
#define signal_A1VN71LS1     (*((psbool)(PBSTART+0x55)))  /*                       ���������� ���������������  ������� �� �� ���2 */
#define signal_B8VC01RDU     (*((psfloat)(PBSTART+0x57)))  /*                       ���������� ��2, �� */
#define signal_R0EE01LZ1     (*((psbool)(PBSTART+0x5c)))  /*                       �������  ����1  ��������� */
#define signal_R0EE01LZ2     (*((psbool)(PBSTART+0x5e)))  /*                       �������  ����1  ��������� */

/* ����������� �������� ��� � ������*/
struct       sint  iRM_5_ = {    5,0}; /* n - N-����������� ������� x */ 
struct     sfloat  fRM_2_0 = {  2.0,0}; /* Kpr1 - �����. �������������� �������->�����/� ���-11 */ 
struct      schar  bRM_2_ = {    2,0}; /* type - ��� ������ ���-11 1- ��� ��1, 2- ��� ��2, >2 ��� */ 
#define fEM_R0UR01RSS  (*((psfloat)(SpaEEPROMBuf+0x0)))
#define fEM_R0UL52RSS  (*((psfloat)(SpaEEPROMBuf+0x5)))
#define fEM_R0UL41RSS  (*((psfloat)(SpaEEPROMBuf+0xA)))
#define fEM_R0UL51RSS  (*((psfloat)(SpaEEPROMBuf+0xF)))
#define fEM_R0UH02RSS  (*((psfloat)(SpaEEPROMBuf+0x14)))
#define fEM_R0UH03RSS  (*((psfloat)(SpaEEPROMBuf+0x19)))
#define fEM_R0UL42RSS  (*((psfloat)(SpaEEPROMBuf+0x1E)))
#define fEM_R7UX00RSS  (*((psfloat)(SpaEEPROMBuf+0x23)))
#define fEM_R7UX01RSS  (*((psfloat)(SpaEEPROMBuf+0x28)))
#define fEM_R7UX02RSS  (*((psfloat)(SpaEEPROMBuf+0x2D)))
#define fEM_R7UX03RSS  (*((psfloat)(SpaEEPROMBuf+0x32)))
#define fEM_R7UY00RSS  (*((psfloat)(SpaEEPROMBuf+0x37)))
#define fEM_R7UY01RSS  (*((psfloat)(SpaEEPROMBuf+0x3C)))
#define fEM_R7UY02RSS  (*((psfloat)(SpaEEPROMBuf+0x41)))
#define fEM_R7UY03RSS  (*((psfloat)(SpaEEPROMBuf+0x46)))
#define fEM_A0UX00RSS  (*((psfloat)(SpaEEPROMBuf+0x4B)))
#define fEM_A0UX01RSS  (*((psfloat)(SpaEEPROMBuf+0x50)))
#define fEM_A0UX02RSS  (*((psfloat)(SpaEEPROMBuf+0x55)))
#define fEM_A0UX03RSS  (*((psfloat)(SpaEEPROMBuf+0x5A)))
#define fEM_B0UX01RSS  (*((psfloat)(SpaEEPROMBuf+0x5F)))
#define fEM_B0UX02RSS  (*((psfloat)(SpaEEPROMBuf+0x64)))
#define fEM_B0UX03RSS  (*((psfloat)(SpaEEPROMBuf+0x69)))
#define fEM_R0UH05RSS  (*((psfloat)(SpaEEPROMBuf+0x6E)))
#define fEM_R0UN03RSS  (*((psfloat)(SpaEEPROMBuf+0x73)))
#define fEM_R0UL01RSS  (*((psfloat)(SpaEEPROMBuf+0x78)))
#define fEM_R0UL02RSS  (*((psfloat)(SpaEEPROMBuf+0x7D)))

int SpaEEPROMBufSize = 130;

/* ����������� ���������� */
struct sbool  var1;
struct sbool  var2;
struct sbool  var3;
struct sfloat  var4;
struct sfloat  var5;
struct sbool  var6;
struct sfloat  var7;
struct sfloat  var8;
struct sfloat  var9;
struct sint  var10;
struct sbool  var11;
struct sfloat  var12;
struct sbool  var13;
struct sbool  var14;
struct sbool  var15;
struct sbool  var16;
struct sbool  var17;
struct sfloat  var18;
struct sbool  var19;
struct slong  vainSLong;
struct sfloat  vainSFloat;
struct sint  vainSInt;
struct sbool  vainSBool;
struct schar  vainSChar;
char  vainSText[] = "";

/* ���������� �������� */
psfloat  array_m45_tst_1[5];
psfloat  array_m45_trz_1[5];
psfloat  array_m45_N1_1[5];
psfloat  array_m45_N2_1[5];

/* �������� �������� ��� �-�� */

/* ��� ���������� */
/* ���������� �������� */
_S_and5 far S_and5_62_1 = {&var6,NULL,NULL,NULL,NULL,&var1};
_S_and2 far S_and2_58_1 = {&var16,&var13,&var2};
_S_and2 far S_and2_57_1 = {&var17,&var16,&var3};
_S_ocham far S_ocham_13_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_2_,&fRM_2_0,NULL,NULL,NULL,&var4,&var5,&var6,&var7,&var8,&var9,&var10,NULL};
_S_or2 far S_or2_68_1 = {NULL,NULL,&var11};
_S_period far S_period_45_1 = {&var5,&var1,&iRM_5_,NULL,NULL,NULL,&var12,array_m45_tst_1,array_m45_trz_1,array_m45_N1_1,array_m45_N2_1,NULL,NULL};
_S_bol far S_bol_51_1 = {NULL,&var12,&var13};
_S_bol far S_bol_36_1 = {&var5,NULL,&var14};
_S_bol far S_bol_31_1 = {&var5,NULL,&var15};
_S_bol far S_bol_50_1 = {&var5,NULL,&var16};
_S_bol far S_bol_49_1 = {NULL,&var12,&var17};
_S_react far S_react_46_1 = {&var12,&var18};
_S_bol far S_bol_39_1 = {&var5,NULL,&var19};


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
  or2((&S_or2_68_1));
  ocham((&S_ocham_13_1));
  and5((&S_and5_62_1));
  bol((&S_bol_39_1));
  bol((&S_bol_50_1));
  bol((&S_bol_31_1));
  bol((&S_bol_36_1));
  period((&S_period_45_1));
  react((&S_react_46_1));
  bol((&S_bol_49_1));
  bol((&S_bol_51_1));
  and2((&S_and2_57_1));
  and2((&S_and2_58_1));
  signal_A1VN71LS1.b = var19.b;
  signal_A1VN71LS1.error = var19.error;
  signal_A1EE01LS1.b = var1.b;
  signal_A1EE01LS1.error = var1.error;
  signal_R0VN75LZ2.b = var3.b;
  signal_R0VN75LZ2.error = var3.error;
  signal_R0VN71LZ2.b = var14.b;
  signal_R0VN71LZ2.error = var14.error;
  signal_R0IE02LS1.b = var11.b;
  signal_R0IE02LS1.error = var11.error;
  signal_R0IE01LS1.b = var11.b;
  signal_R0IE01LS1.error = var11.error;
  signal_R0VN15RS1.i = var10.i;
  signal_R0VN15RS1.error = var10.error;
  fplet(&signal_R0VN33RS1.f,&var9.f);
  signal_R0VN33RS1.error = var9.error;
  fplet(&signal_R0VN23RS1.f,&var8.f);
  signal_R0VN23RS1.error = var8.error;
  fplet(&signal_R0VN13RS1.f,&var7.f);
  signal_R0VN13RS1.error = var7.error;
  signal_A0EE02LS1.b = var6.b;
  signal_A0EE02LS1.error = var6.error;
  signal_A0VN71LS1.b = var19.b;
  signal_A0VN71LS1.error = var19.error;
  fplet(&signal_R0VN04RS1.f,&var18.f);
  signal_R0VN04RS1.error = var18.error;
  fplet(&signal_R0VN03RS1.f,&var4.f);
  signal_R0VN03RS1.error = var4.error;
  signal_A0EE01LS1.b = var1.b;
  signal_A0EE01LS1.error = var1.error;
  signal_R0VN75LZ1.b = var3.b;
  signal_R0VN75LZ1.error = var3.error;
  signal_R0VN65LS1.b = var2.b;
  signal_R0VN65LS1.error = var2.error;
  signal_R0VN71LZ1.b = var14.b;
  signal_R0VN71LZ1.error = var14.error;
  signal_R0VN61LS1.b = var15.b;
  signal_R0VN61LS1.error = var15.error;
  fplet(&signal_R0VN01RS1.f,&var12.f);
  signal_R0VN01RS1.error = var12.error;
  fplet(&signal_R0VN02RS1.f,&var5.f);
  signal_R0VN02RS1.error = var5.error;

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
ParExchange("R0IN01FS1",1,&SignalBuffer[20],"����� ���-11 ��",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(25);
#else
ParExchange("R0IN02FS1",1,&SignalBuffer[25],"����� ���15-1 ��",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(42);
#else
ParExchange("R0IN03FS1",1,&SignalBuffer[42],"����� ���53�  ��",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(49);
#else
ParExchange("R0IE11LS1",3,&SignalBuffer[49],"����������� ��� 1,6 (�8) ���11 1 ������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(51);
#else
ParExchange("R0IE12LS1",3,&SignalBuffer[51],"����������� ��� 0,5 (�9) ���15-1 1 ������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(53);
#else
ParExchange("R0IE13LS1",3,&SignalBuffer[53],"����������� ��� 0,5 (�10) ���53� 1 ������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(73);
#else
ParExchange("A0EE03LS1",3,&SignalBuffer[73],"���������� ���� ������� ����",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(87);
#else
ParExchange("B8VC01RDU",1,&SignalBuffer[87],"���������� ��2, ��",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(92);
#else
ParExchange("R0EE01LZ1",3,&SignalBuffer[92],"�������  ����1  ���������",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(94);
#else
ParExchange("R0EE01LZ2",3,&SignalBuffer[94],"�������  ����1  ���������",0);
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
 for(counter=0; counter<96; counter++) {
   *((unsigned char*)(SignalBuffer)+PBLENGTH-counter-1) =
          (unsigned char)~(*((unsigned char*)(SignalBuffer)+counter));
 }
#endif
}
#endif
#ifdef SIMUL_MODE
void UnloadSignals()
{
ParExchange("R0VN02RS1",1,&SignalBuffer[0],"������� ��������",1);
ParExchange("R0VN01RS1",1,&SignalBuffer[5],"������ ������� �����1",1);
ParExchange("R0VN61LS1",3,&SignalBuffer[10],"�� �� �������� �����1",1);
ParExchange("R0VN71LZ1",3,&SignalBuffer[12],"�� �� �������� �� ���1",1);
ParExchange("R0VN65LS1",3,&SignalBuffer[14],"�� �� ������� ������� �����1",1);
ParExchange("R0VN75LZ1",3,&SignalBuffer[16],"�� �� ������� ��������� ���1",1);
ParExchange("A0EE01LS1",3,&SignalBuffer[18],"����������� ���� �� ���1",1);
ParExchange("R0VN03RS1",1,&SignalBuffer[30],"���������� ���������� �����",1);
ParExchange("R0VN04RS1",1,&SignalBuffer[35],"������������ �����1",1);
ParExchange("A0VN71LS1",3,&SignalBuffer[40],"���������� ���������������  ������� �� �� ���1",1);
ParExchange("A0EE02LS1",3,&SignalBuffer[47],"����������� ����1 (�� ������ �������) ����� 1",1);
ParExchange("R0VN13RS1",1,&SignalBuffer[55],"���������� ����� �� ������ ���11",1);
ParExchange("R0VN23RS1",1,&SignalBuffer[60],"���������� ����� �� ������ ���15-1",1);
ParExchange("R0VN33RS1",1,&SignalBuffer[65],"���������� ����� �� ������ ���53�",1);
ParExchange("R0VN15RS1",2,&SignalBuffer[70],"����� ������� ������ 1-���-11,2-���-15�-1,3-���-53�,0-��� �������",1);
ParExchange("R0IE01LS1",3,&SignalBuffer[75],"���������� ������� ����������",1);
ParExchange("R0IE02LS1",3,&SignalBuffer[77],"��������� ������� ��, ��",1);
ParExchange("R0VN71LZ2",3,&SignalBuffer[79],"�� �� �������� �� ���2",1);
ParExchange("R0VN75LZ2",3,&SignalBuffer[81],"�� �� ������� ��������� ���2",1);
ParExchange("A1EE01LS1",3,&SignalBuffer[83],"����������� ���� �� ���2",1);
ParExchange("A1VN71LS1",3,&SignalBuffer[85],"���������� ���������������  ������� �� �� ���2",1);
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
NewEEPROM("fEM_R0UR01RSS",1,&fEM_R0UR01RSS,"������� ���� ��  �� �� ������� (���)","10");
NewEEPROM("fEM_R0UL52RSS",1,&fEM_R0UL52RSS,"������� �� �� ��������","5100");
NewEEPROM("fEM_R0UL41RSS",1,&fEM_R0UL41RSS,"������� �� �� ������� �������","20");
NewEEPROM("fEM_R0UL51RSS",1,&fEM_R0UL51RSS,"������� �� �� ������� �������","13.0");
NewEEPROM("fEM_R0UH02RSS",1,&fEM_R0UH02RSS,"�����. �������������� �������->�����/� ���15-1","3703.704 ");
NewEEPROM("fEM_R0UH03RSS",1,&fEM_R0UH03RSS,"�����. �������������� �������->�����/� ���53�","62500.0");
NewEEPROM("fEM_R0UL42RSS",1,&fEM_R0UL42RSS,"������� �� �� ��������","5000");
NewEEPROM("fEM_R7UX00RSS",1,&fEM_R7UX00RSS,"X-���������� ��1 (��)","1567.36");
NewEEPROM("fEM_R7UX01RSS",1,&fEM_R7UX01RSS,"X-���������� ������ R7IN11","1585.0");
NewEEPROM("fEM_R7UX02RSS",1,&fEM_R7UX02RSS,"X-���������� ������ R7IN12 (��)","1796.0");
NewEEPROM("fEM_R7UX03RSS",1,&fEM_R7UX03RSS,"X-���������� ������ R7IN13 (��)","1269.0");
NewEEPROM("fEM_R7UY00RSS",1,&fEM_R7UY00RSS,"Y-���������� ��1 (��)","506.6");
NewEEPROM("fEM_R7UY01RSS",1,&fEM_R7UY01RSS,"Y-���������� ������ R7IN11","248.0");
NewEEPROM("fEM_R7UY02RSS",1,&fEM_R7UY02RSS,"Y-���������� ������ R7IN12 (��)","284.5");
NewEEPROM("fEM_R7UY03RSS",1,&fEM_R7UY03RSS,"Y-���������� ������ R7IN13 (��)","256.0");
NewEEPROM("fEM_A0UX00RSS",1,&fEM_A0UX00RSS,"����������� ������ ��","11.0");
NewEEPROM("fEM_A0UX01RSS",1,&fEM_A0UX01RSS,"������ ����������� ���������� ������ 1","1.0");
NewEEPROM("fEM_A0UX02RSS",1,&fEM_A0UX02RSS,"������ ����������� ���������� ������ 2","1.0");
NewEEPROM("fEM_A0UX03RSS",1,&fEM_A0UX03RSS,"������ ����������� ���������� ������ 3","1.0");
NewEEPROM("fEM_B0UX01RSS",1,&fEM_B0UX01RSS,"������ ����������� ���������� ������ 1","0");
NewEEPROM("fEM_B0UX02RSS",1,&fEM_B0UX02RSS,"������ ����������� ���������� ������ 2","0");
NewEEPROM("fEM_B0UX03RSS",1,&fEM_B0UX03RSS,"������ ����������� ���������� ������ 3","0");
NewEEPROM("fEM_R0UH05RSS",1,&fEM_R0UH05RSS,"���-�� �������/��� �� 1 ���� * E^6","32000.0");
NewEEPROM("fEM_R0UN03RSS",1,&fEM_R0UN03RSS,"������ ������� ��������� �������� ��� ��������� ������� (����)","0.005");
NewEEPROM("fEM_R0UL01RSS",1,&fEM_R0UL01RSS,"��� (��) ��������� �������","0.5");
NewEEPROM("fEM_R0UL02RSS",1,&fEM_R0UL02RSS,"���������� ����� �������� ����� ������ (��)","100");
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
  fplet(&fEM_R7UX01RSS.f,((float*)(IntEEPROMBuffer+0x20)));
  fEM_R7UX01RSS.error = 0;
  fplet(&fEM_R7UX02RSS.f,((float*)(IntEEPROMBuffer+0x24)));
  fEM_R7UX02RSS.error = 0;
  fplet(&fEM_R7UX03RSS.f,((float*)(IntEEPROMBuffer+0x28)));
  fEM_R7UX03RSS.error = 0;
  fplet(&fEM_R7UY00RSS.f,((float*)(IntEEPROMBuffer+0x2C)));
  fEM_R7UY00RSS.error = 0;
  fplet(&fEM_R7UY01RSS.f,((float*)(IntEEPROMBuffer+0x30)));
  fEM_R7UY01RSS.error = 0;
  fplet(&fEM_R7UY02RSS.f,((float*)(IntEEPROMBuffer+0x34)));
  fEM_R7UY02RSS.error = 0;
  fplet(&fEM_R7UY03RSS.f,((float*)(IntEEPROMBuffer+0x38)));
  fEM_R7UY03RSS.error = 0;
  fplet(&fEM_A0UX00RSS.f,((float*)(IntEEPROMBuffer+0x3C)));
  fEM_A0UX00RSS.error = 0;
  fplet(&fEM_A0UX01RSS.f,((float*)(IntEEPROMBuffer+0x40)));
  fEM_A0UX01RSS.error = 0;
  fplet(&fEM_A0UX02RSS.f,((float*)(IntEEPROMBuffer+0x44)));
  fEM_A0UX02RSS.error = 0;
  fplet(&fEM_A0UX03RSS.f,((float*)(IntEEPROMBuffer+0x48)));
  fEM_A0UX03RSS.error = 0;
  fplet(&fEM_B0UX01RSS.f,((float*)(IntEEPROMBuffer+0x4C)));
  fEM_B0UX01RSS.error = 0;
  fplet(&fEM_B0UX02RSS.f,((float*)(IntEEPROMBuffer+0x50)));
  fEM_B0UX02RSS.error = 0;
  fplet(&fEM_B0UX03RSS.f,((float*)(IntEEPROMBuffer+0x54)));
  fEM_B0UX03RSS.error = 0;
  fplet(&fEM_R0UH05RSS.f,((float*)(IntEEPROMBuffer+0x58)));
  fEM_R0UH05RSS.error = 0;
  fplet(&fEM_R0UN03RSS.f,((float*)(IntEEPROMBuffer+0x5C)));
  fEM_R0UN03RSS.error = 0;
  fplet(&fEM_R0UL01RSS.f,((float*)(IntEEPROMBuffer+0x60)));
  fEM_R0UL01RSS.error = 0;
  fplet(&fEM_R0UL02RSS.f,((float*)(IntEEPROMBuffer+0x64)));
  fEM_R0UL02RSS.error = 0;
}
#endif
}

#ifndef SIMUL_MODE
unsigned int EndIntEEPROMAddress = 104;
#endif

void reInit_Signals(void)
{
  S_and5_62_1.x2 = &signal_R0IE13LS1;
  S_and5_62_1.x3 = &signal_A0EE03LS1;
  S_and5_62_1.x4 = &signal_R0IE11LS1;
  S_and5_62_1.x5 = &signal_R0IE12LS1;
  S_ocham_13_1.Ch1k = &signal_R0IN03FS1;
  S_ocham_13_1.Ch2k = &signal_R0IN02FS1;
  S_ocham_13_1.Ch3k = &signal_R0IN01FS1;
  S_ocham_13_1.YAz2 = &signal_B8VC01RDU;
  S_or2_68_1.x1 = &signal_R0EE01LZ1;
  S_or2_68_1.x2 = &signal_R0EE01LZ2;
}

void InitInternalParametr(void)
{
  int i;
  S_ocham_13_1.Nk = &internal1_m13_Nk;
  S_period_45_1.Period0 = &internal1_m45_Period0;
  S_period_45_1.MyFirstEnterFlag = &internal1_m45_MyFirstEnterFlag;
  S_ocham_13_1.XAz = &fEM_R7UX00RSS;
  S_ocham_13_1.YAz1 = &fEM_R7UY00RSS;
  S_ocham_13_1.Reff = &fEM_A0UX00RSS;
  S_ocham_13_1.Ak1 = &fEM_A0UX01RSS;
  S_ocham_13_1.Bk1 = &fEM_B0UX01RSS;
  S_ocham_13_1.Ak2 = &fEM_A0UX02RSS;
  S_ocham_13_1.Bk2 = &fEM_B0UX02RSS;
  S_ocham_13_1.Ak3 = &fEM_A0UX03RSS;
  S_ocham_13_1.Bk3 = &fEM_B0UX03RSS;
  S_ocham_13_1.XCm1 = &fEM_R7UX01RSS;
  S_ocham_13_1.YCm1 = &fEM_R7UY01RSS;
  S_ocham_13_1.XCm2 = &fEM_R7UX02RSS;
  S_ocham_13_1.YCm2 = &fEM_R7UY02RSS;
  S_ocham_13_1.XCm3 = &fEM_R7UX03RSS;
  S_ocham_13_1.YCm3 = &fEM_R7UY03RSS;
  S_ocham_13_1.Kpr2k = &fEM_R0UH02RSS;
  S_ocham_13_1.Kpr3k = &fEM_R0UH03RSS;
  S_ocham_13_1.Kprm = &fEM_R0UH05RSS;
  S_period_45_1.TiStep = &fEM_R0UL01RSS;
  S_period_45_1.Tmax = &fEM_R0UL02RSS;
  S_period_45_1.Nmin = &fEM_R0UN03RSS;
  S_bol_51_1.x1 = &fEM_R0UL41RSS;
  S_bol_36_1.x2 = &fEM_R0UL52RSS;
  S_bol_31_1.x2 = &fEM_R0UL42RSS;
  S_bol_50_1.x2 = &fEM_R0UN03RSS;
  S_bol_49_1.x1 = &fEM_R0UL51RSS;
  S_bol_39_1.x2 = &fEM_R0UR01RSS;
  for( i=0;i<5;i++ )
    array_m45_tst_1[i] = &(&internal1_m45_tst)[i];
  for( i=0;i<5;i++ )
    array_m45_trz_1[i] = &(&internal1_m45_trz)[i];
  for( i=0;i<5;i++ )
    array_m45_N1_1[i] = &(&internal1_m45_N1)[i];
  for( i=0;i<5;i++ )
    array_m45_N2_1[i] = &(&internal1_m45_N2)[i];
}