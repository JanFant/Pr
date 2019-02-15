#include "aknp1.h"
extern  func_ext1();
// АП
//  Результат трансляции схемы D:\md\pti\pr\AKNP1\scheme\aknp1.tpr

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
#include <and2.h>
#include <and5.h>
#include <bol.h>
#include <diagndev.h>
#include <ocham.h>
#include <or2.h>
#include <or3.h>
#include <orn.h>
#include <period.h>
#include <react.h>

/* Определение внутренних параметров */
#define bFirstEnterFlag (*((psbool)(InternalBuf+0x0)))
#define internal1_m13_Nk (*((psint)(InternalBuf+0x2))) /*Nk - ведущая камера*/
#define internal1_m45_tst (*((psfloat)(InternalBuf+0x5))) /*- массив времени фиксации стартовой мощности*/
#define internal1_m45_trz (*((psfloat)(InternalBuf+0x1E))) /*- массив времени фиксации очередного периода*/
#define internal1_m45_N1 (*((psfloat)(InternalBuf+0x37))) /*- массив значения мощности в начале замера*/
#define internal1_m45_N2 (*((psfloat)(InternalBuf+0x50))) /*- массив значения мощности в конце замера*/
#define internal1_m45_Period0 (*((psfloat)(InternalBuf+0x69))) /*Per - Период разгона РУ*/
#define internal1_m45_MyFirstEnterFlag (*((psbool)(InternalBuf+0x6E))) /* FirstEnterFlag*/
int InternalBufSize = 112;

/* Определение сигналов */
#define signal_R0VN02RS1     (*((psfloat)(PBSTART+0x0)))  /*                       Уровень мощности */
#define signal_R0VN01RS1     (*((psfloat)(PBSTART+0x5)))  /*                       Период разгона канал1 */
#define signal_R0VN61LS1     (*((psbool)(PBSTART+0xa)))  /*                       ПС по мощности канал1 */
#define signal_R0VN71LZ1     (*((psbool)(PBSTART+0xc)))  /*                       АС по мощности на БАЗ1 */
#define signal_R0VN65LS1     (*((psbool)(PBSTART+0xe)))  /*                       ПС по периоду разгона канал1 */
#define signal_R0VN75LZ1     (*((psbool)(PBSTART+0x10)))  /*                       АС по периоду разгонана БАЗ1 */
#define signal_A0EE01LS1     (*((psbool)(PBSTART+0x12)))  /*                       Исправность АКНП1 на БАЗ1 */
#define signal_R0IN01FS1     (*((psfloat)(PBSTART+0x14)))  /*                       Выход СНМ-11 Гц */
#define signal_R0IN02FS1     (*((psfloat)(PBSTART+0x19)))  /*                       Выход КНК15-1 Гц */
#define signal_R0VN03RS1     (*((psfloat)(PBSTART+0x1e)))  /*                       Измеренный нейтронный поток */
#define signal_R0VN04RS1     (*((psfloat)(PBSTART+0x23)))  /*                       Реактивность канал1 */
#define signal_A0VN71LS1     (*((psbool)(PBSTART+0x28)))  /*                       Блокировка автоматического  подъёма ББ на БАЗ1 */
#define signal_R0IN03FS1     (*((psfloat)(PBSTART+0x2a)))  /*                       Выход КНК53М  Гц */
#define signal_A0EE02LS1     (*((psbool)(PBSTART+0x2f)))  /*                       Исправность АКНП1 (от сшивки каналов) канал 1 */
#define signal_R0IE11LS1     (*((psbool)(PBSTART+0x31)))  /*                       Исправность ВИП 1,6 (№8) СНМ11 1 канала */
#define signal_R0IE12LS1     (*((psbool)(PBSTART+0x33)))  /*                       Исправность ВИП 0,5 (№9) КНК15-1 1 канала */
#define signal_R0IE13LS1     (*((psbool)(PBSTART+0x35)))  /*                       Исправность ВИП 0,5 (№10) КНК53М 1 канала */
#define signal_R0VN13RS1     (*((psfloat)(PBSTART+0x37)))  /*                       Нейтронный поток по камере СНМ11 */
#define signal_R0VN23RS1     (*((psfloat)(PBSTART+0x3c)))  /*                       Нейтронный поток по камере КНК15-1 */
#define signal_R0VN33RS1     (*((psfloat)(PBSTART+0x41)))  /*                       Нейтронный поток по камере КНК53М */
#define signal_R0VN15RS1     (*((psint)(PBSTART+0x46)))  /*                       Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей */
#define signal_A0EE03LS1     (*((psbool)(PBSTART+0x49)))  /*                       Подключена сеть питания АКНП */
#define signal_R0IE01LS1     (*((psbool)(PBSTART+0x4b)))  /*                       Отключение питание детекторов 1 канала */
#define signal_R0IE02LS1     (*((psbool)(PBSTART+0x4d)))  /*                       Отключить питание ПР, ПУ 1 канала */
#define signal_R0VN71LZ2     (*((psbool)(PBSTART+0x4f)))  /*                       АС по мощности на БАЗ2 */
#define signal_R0VN75LZ2     (*((psbool)(PBSTART+0x51)))  /*                       АС по периоду разгонана БАЗ2 */
#define signal_A1EE01LS1     (*((psbool)(PBSTART+0x53)))  /*                       Исправность АКНП1 на БАЗ2 */
#define signal_A1VN71LS1     (*((psbool)(PBSTART+0x55)))  /*                       Блокировка автоматического  подъёма ББ на БАЗ2 */
#define signal_B8VC01RDU     (*((psfloat)(PBSTART+0x57)))  /*                       Координата АЗ2, мм */
#define signal_R0EE01LZ1     (*((psbool)(PBSTART+0x5c)))  /*                       Питание  АКНП1  отключить */
#define signal_R0EE01LZ2     (*((psbool)(PBSTART+0x5e)))  /*                       Питание  АКНП1  отключить */
#define signal_R0DE01LS1     (*((psint)(PBSTART+0x60)))  /*                       диагностика модуля АКНП1 на 1 месте */
#define signal_R0DE02LS1     (*((psint)(PBSTART+0x63)))  /*                       диагностика модуля АКНП1 на 2 месте */
#define signal_R0DE04LS1     (*((psint)(PBSTART+0x66)))  /*                       диагностика модуля АКНП1 на 4 месте */
#define signal_R0DE05LS1     (*((psint)(PBSTART+0x69)))  /*                       диагностика модуля АКНП1 на 5 месте */
#define signal_TTLaknp1      (*((psint)(PBSTART+0x6c)))  /*                       ttl */
#define signal_R0DE31LS1     (*((psbool)(PBSTART+0x6f)))  /*                       диагностика шкафа АКНП1 сеть 1 */
#define signal_R0DE32LS1     (*((psbool)(PBSTART+0x71)))  /*                       диагностика шкафа АКНП1 сеть 2 */
#define signal_R0DE33LS1     (*((psbool)(PBSTART+0x73)))  /*                       диагностика шкафа АКНП1 двери */
#define signal_R0DE34LS1     (*((psbool)(PBSTART+0x75)))  /*                       диагностика шкафа АКНП1 температура меньше 43 */
#define signal_R0DE35LS1     (*((psbool)(PBSTART+0x77)))  /*                       диагностика шкафа АКНП1 температура больше 53 */
#define signal_R0DE36LS1     (*((psbool)(PBSTART+0x79)))  /*                       диагностика шкафа АКНП1 МП15-3.1 место 1 */
#define signal_R0DE37LS1     (*((psbool)(PBSTART+0x7b)))  /*                       диагностика шкафа АКНП1 МП15-3.1 место 2 */
#define signal_R0DE38LS1     (*((psbool)(PBSTART+0x7d)))  /*                       диагностика шкафа АКНП1 МП15-3 место 3 */
#define signal_R0DE39LS1     (*((psbool)(PBSTART+0x7f)))  /*                       диагностика шкафа АКНП1 МП24-2 место 4 */
#define signal_R0DE3ALS1     (*((psbool)(PBSTART+0x81)))  /*                       диагностика шкафа АКНП1 БП5/24Д место 5 */
#define signal_R0DE3BLS1     (*((psbool)(PBSTART+0x83)))  /*                       диагностика шкафа АКНП1 БП5/24Д место 6 */
#define signal_R0DE3CLS1     (*((psbool)(PBSTART+0x85)))  /*                       диагностика шкафа АКНП1 БП5/24Д место 7 */
#define signal_R0DE3DLS1     (*((psbool)(PBSTART+0x87)))  /*                       диагностика шкафа АКНП1 БП5/24Д место 8 */
#define signal_TestDiagnAKNP1 (*((psbool)(PBSTART+0x89)))  /*                       Неисправность от диагностики */

/* Определение констант ПЗУ и ЭСППЗУ*/
struct       sint  iRM_5_ = {    5,0}; /* n - N-размерность массива x */ 
struct     sfloat  fRM_2_0 = {  2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 
struct      schar  bRM_2_ = {    2,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
struct       sint  iRM_4_ = {    4,0}; /* n - размерность массива значений */ 
struct       sint  iRM_8_ = {    8,0}; /* n - N-размерность массива x */ 
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

/* Определение переменных */
struct sbool  var1;
struct sbool  var2;
struct sbool  var3;
struct sbool  var4;
struct sint  var5;
struct sbool  var6;
struct sbool  var7;
struct sbool  var8;
struct sfloat  var9;
struct sfloat  var10;
struct sbool  var11;
struct sfloat  var12;
struct sfloat  var13;
struct sfloat  var14;
struct sint  var15;
struct sbool  var16;
struct sfloat  var17;
struct sbool  var18;
struct sbool  var19;
struct sbool  var20;
struct sbool  var21;
struct sbool  var22;
struct sfloat  var23;
struct sbool  var24;
struct slong  vainSLong;
struct sfloat  vainSFloat;
struct sint  vainSInt;
struct sbool  vainSBool;
struct schar  vainSChar;
char  vainSText[] = "";

/* Объявление массивов */
psbool  array_m88_x_1[8] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
psint  array_m78_x_1[4] = {NULL,NULL,NULL,NULL};
psfloat  array_m45_tst_1[5];
psfloat  array_m45_trz_1[5];
psfloat  array_m45_N1_1[5];
psfloat  array_m45_N2_1[5];

/* описания структур для ф-ий */

/* код алгоблоков */
/* Объявление структур */
_S_orn far S_orn_88_1 = {array_m88_x_1,&iRM_8_,&var1};
_S_or3 far S_or3_83_1 = {&var4,&var3,&var1,&var2};
_S_and2 far S_and2_80_1 = {NULL,NULL,&var3};
_S_diagndev far S_diagndev_78_1 = {array_m78_x_1,&iRM_4_,&var4,&var5};
_S_and5 far S_and5_61_1 = {&var11,NULL,NULL,NULL,NULL,&var6};
_S_and2 far S_and2_58_1 = {&var21,&var18,&var7};
_S_and2 far S_and2_57_1 = {&var22,&var21,&var8};
_S_ocham far S_ocham_13_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_2_,&fRM_2_0,NULL,NULL,NULL,&var9,&var10,&var11,&var12,&var13,&var14,&var15,NULL};
_S_or2 far S_or2_68_1 = {NULL,NULL,&var16};
_S_period far S_period_45_1 = {&var10,&var6,&iRM_5_,NULL,NULL,NULL,&var17,array_m45_tst_1,array_m45_trz_1,array_m45_N1_1,array_m45_N2_1,NULL,NULL};
_S_bol far S_bol_51_1 = {NULL,&var17,&var18};
_S_bol far S_bol_36_1 = {&var10,NULL,&var19};
_S_bol far S_bol_31_1 = {&var10,NULL,&var20};
_S_bol far S_bol_50_1 = {&var10,NULL,&var21};
_S_bol far S_bol_49_1 = {NULL,&var17,&var22};
_S_react far S_react_46_1 = {&var17,&var23};
_S_bol far S_bol_39_1 = {&var10,NULL,&var24};


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
  and5((&S_and5_61_1));
  diagndev((&S_diagndev_78_1));
  and2((&S_and2_80_1));
  orn((&S_orn_88_1));
  bol((&S_bol_39_1));
  bol((&S_bol_50_1));
  bol((&S_bol_31_1));
  bol((&S_bol_36_1));
  period((&S_period_45_1));
  or3((&S_or3_83_1));
  react((&S_react_46_1));
  bol((&S_bol_49_1));
  bol((&S_bol_51_1));
  and2((&S_and2_57_1));
  and2((&S_and2_58_1));
  signal_TestDiagnAKNP1.b = var2.b;
  signal_TestDiagnAKNP1.error = var2.error;
  signal_TTLaknp1.i = var5.i;
  signal_TTLaknp1.error = var5.error;
  signal_A1VN71LS1.b = var24.b;
  signal_A1VN71LS1.error = var24.error;
  signal_A1EE01LS1.b = var6.b;
  signal_A1EE01LS1.error = var6.error;
  signal_R0VN75LZ2.b = var8.b;
  signal_R0VN75LZ2.error = var8.error;
  signal_R0VN71LZ2.b = var19.b;
  signal_R0VN71LZ2.error = var19.error;
  signal_R0IE02LS1.b = var16.b;
  signal_R0IE02LS1.error = var16.error;
  signal_R0IE01LS1.b = var16.b;
  signal_R0IE01LS1.error = var16.error;
  signal_R0VN15RS1.i = var15.i;
  signal_R0VN15RS1.error = var15.error;
  fplet(&signal_R0VN33RS1.f,&var14.f);
  signal_R0VN33RS1.error = var14.error;
  fplet(&signal_R0VN23RS1.f,&var13.f);
  signal_R0VN23RS1.error = var13.error;
  fplet(&signal_R0VN13RS1.f,&var12.f);
  signal_R0VN13RS1.error = var12.error;
  signal_A0EE02LS1.b = var11.b;
  signal_A0EE02LS1.error = var11.error;
  signal_A0VN71LS1.b = var24.b;
  signal_A0VN71LS1.error = var24.error;
  fplet(&signal_R0VN04RS1.f,&var23.f);
  signal_R0VN04RS1.error = var23.error;
  fplet(&signal_R0VN03RS1.f,&var9.f);
  signal_R0VN03RS1.error = var9.error;
  signal_A0EE01LS1.b = var6.b;
  signal_A0EE01LS1.error = var6.error;
  signal_R0VN75LZ1.b = var8.b;
  signal_R0VN75LZ1.error = var8.error;
  signal_R0VN65LS1.b = var7.b;
  signal_R0VN65LS1.error = var7.error;
  signal_R0VN71LZ1.b = var19.b;
  signal_R0VN71LZ1.error = var19.error;
  signal_R0VN61LS1.b = var20.b;
  signal_R0VN61LS1.error = var20.error;
  fplet(&signal_R0VN01RS1.f,&var17.f);
  signal_R0VN01RS1.error = var17.error;
  fplet(&signal_R0VN02RS1.f,&var10.f);
  signal_R0VN02RS1.error = var10.error;

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
ParExchange("R0IN01FS1",1,&SignalBuffer[20],"Выход СНМ-11 Гц",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(25);
#else
ParExchange("R0IN02FS1",1,&SignalBuffer[25],"Выход КНК15-1 Гц",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(42);
#else
ParExchange("R0IN03FS1",1,&SignalBuffer[42],"Выход КНК53М  Гц",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(49);
#else
ParExchange("R0IE11LS1",3,&SignalBuffer[49],"Исправность ВИП 1,6 (№8) СНМ11 1 канала",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(51);
#else
ParExchange("R0IE12LS1",3,&SignalBuffer[51],"Исправность ВИП 0,5 (№9) КНК15-1 1 канала",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(53);
#else
ParExchange("R0IE13LS1",3,&SignalBuffer[53],"Исправность ВИП 0,5 (№10) КНК53М 1 канала",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(73);
#else
ParExchange("A0EE03LS1",3,&SignalBuffer[73],"Подключена сеть питания АКНП",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(87);
#else
ParExchange("B8VC01RDU",1,&SignalBuffer[87],"Координата АЗ2, мм",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(92);
#else
ParExchange("R0EE01LZ1",3,&SignalBuffer[92],"Питание  АКНП1  отключить",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(94);
#else
ParExchange("R0EE01LZ2",3,&SignalBuffer[94],"Питание  АКНП1  отключить",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(96);
#else
ParExchange("R0DE01LS1",2,&SignalBuffer[96],"диагностика модуля АКНП1 на 1 месте",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(99);
#else
ParExchange("R0DE02LS1",2,&SignalBuffer[99],"диагностика модуля АКНП1 на 2 месте",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(102);
#else
ParExchange("R0DE04LS1",2,&SignalBuffer[102],"диагностика модуля АКНП1 на 4 месте",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(105);
#else
ParExchange("R0DE05LS1",2,&SignalBuffer[105],"диагностика модуля АКНП1 на 5 месте",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(111);
#else
ParExchange("R0DE31LS1",3,&SignalBuffer[111],"диагностика шкафа АКНП1 сеть 1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(113);
#else
ParExchange("R0DE32LS1",3,&SignalBuffer[113],"диагностика шкафа АКНП1 сеть 2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(115);
#else
ParExchange("R0DE33LS1",3,&SignalBuffer[115],"диагностика шкафа АКНП1 двери",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(117);
#else
ParExchange("R0DE34LS1",3,&SignalBuffer[117],"диагностика шкафа АКНП1 температура меньше 43",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(119);
#else
ParExchange("R0DE35LS1",3,&SignalBuffer[119],"диагностика шкафа АКНП1 температура больше 53",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(121);
#else
ParExchange("R0DE36LS1",3,&SignalBuffer[121],"диагностика шкафа АКНП1 МП15-3.1 место 1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(123);
#else
ParExchange("R0DE37LS1",3,&SignalBuffer[123],"диагностика шкафа АКНП1 МП15-3.1 место 2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(125);
#else
ParExchange("R0DE38LS1",3,&SignalBuffer[125],"диагностика шкафа АКНП1 МП15-3 место 3",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(127);
#else
ParExchange("R0DE39LS1",3,&SignalBuffer[127],"диагностика шкафа АКНП1 МП24-2 место 4",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(129);
#else
ParExchange("R0DE3ALS1",3,&SignalBuffer[129],"диагностика шкафа АКНП1 БП5/24Д место 5",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(131);
#else
ParExchange("R0DE3BLS1",3,&SignalBuffer[131],"диагностика шкафа АКНП1 БП5/24Д место 6",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(133);
#else
ParExchange("R0DE3CLS1",3,&SignalBuffer[133],"диагностика шкафа АКНП1 БП5/24Д место 7",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(135);
#else
ParExchange("R0DE3DLS1",3,&SignalBuffer[135],"диагностика шкафа АКНП1 БП5/24Д место 8",0);
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
ParExchange("R0VN02RS1",1,&SignalBuffer[0],"Уровень мощности",1);
ParExchange("R0VN01RS1",1,&SignalBuffer[5],"Период разгона канал1",1);
ParExchange("R0VN61LS1",3,&SignalBuffer[10],"ПС по мощности канал1",1);
ParExchange("R0VN71LZ1",3,&SignalBuffer[12],"АС по мощности на БАЗ1",1);
ParExchange("R0VN65LS1",3,&SignalBuffer[14],"ПС по периоду разгона канал1",1);
ParExchange("R0VN75LZ1",3,&SignalBuffer[16],"АС по периоду разгонана БАЗ1",1);
ParExchange("A0EE01LS1",3,&SignalBuffer[18],"Исправность АКНП1 на БАЗ1",1);
ParExchange("R0VN03RS1",1,&SignalBuffer[30],"Измеренный нейтронный поток",1);
ParExchange("R0VN04RS1",1,&SignalBuffer[35],"Реактивность канал1",1);
ParExchange("A0VN71LS1",3,&SignalBuffer[40],"Блокировка автоматического  подъёма ББ на БАЗ1",1);
ParExchange("A0EE02LS1",3,&SignalBuffer[47],"Исправность АКНП1 (от сшивки каналов) канал 1",1);
ParExchange("R0VN13RS1",1,&SignalBuffer[55],"Нейтронный поток по камере СНМ11",1);
ParExchange("R0VN23RS1",1,&SignalBuffer[60],"Нейтронный поток по камере КНК15-1",1);
ParExchange("R0VN33RS1",1,&SignalBuffer[65],"Нейтронный поток по камере КНК53М",1);
ParExchange("R0VN15RS1",2,&SignalBuffer[70],"Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей",1);
ParExchange("R0IE01LS1",3,&SignalBuffer[75],"Отключение питание детекторов 1 канала",1);
ParExchange("R0IE02LS1",3,&SignalBuffer[77],"Отключить питание ПР, ПУ 1 канала",1);
ParExchange("R0VN71LZ2",3,&SignalBuffer[79],"АС по мощности на БАЗ2",1);
ParExchange("R0VN75LZ2",3,&SignalBuffer[81],"АС по периоду разгонана БАЗ2",1);
ParExchange("A1EE01LS1",3,&SignalBuffer[83],"Исправность АКНП1 на БАЗ2",1);
ParExchange("A1VN71LS1",3,&SignalBuffer[85],"Блокировка автоматического  подъёма ББ на БАЗ2",1);
ParExchange("TTLaknp1",2,&SignalBuffer[108],"ttl",1);
ParExchange("TestDiagnAKNP1",3,&SignalBuffer[137],"Неисправность от диагностики",1);
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
NewEEPROM("fEM_R0UR01RSS",1,&fEM_R0UR01RSS,"Уставка АКНП ПС  АЗ по периоду (сек)","10");
NewEEPROM("fEM_R0UL52RSS",1,&fEM_R0UL52RSS,"Уровень АС по мощности","5100");
NewEEPROM("fEM_R0UL41RSS",1,&fEM_R0UL41RSS,"Уровень ПС по периоду разгона","20");
NewEEPROM("fEM_R0UL51RSS",1,&fEM_R0UL51RSS,"Уровень АС по периоду разгона","13.0");
NewEEPROM("fEM_R0UH02RSS",1,&fEM_R0UH02RSS,"Коэфф. преобразования частота->нейтр/с КНК15-1","3703.704 ");
NewEEPROM("fEM_R0UH03RSS",1,&fEM_R0UH03RSS,"Коэфф. преобразования частота->нейтр/с КНК53М","62500.0");
NewEEPROM("fEM_R0UL42RSS",1,&fEM_R0UL42RSS,"Уровень ПС по мощности","5000");
NewEEPROM("fEM_R7UX00RSS",1,&fEM_R7UX00RSS,"X-координата АЗ1 (см)","1567.36");
NewEEPROM("fEM_R7UX01RSS",1,&fEM_R7UX01RSS,"X-координата камеры R7IN11","1585.0");
NewEEPROM("fEM_R7UX02RSS",1,&fEM_R7UX02RSS,"X-координата камеры R7IN12 (см)","1796.0");
NewEEPROM("fEM_R7UX03RSS",1,&fEM_R7UX03RSS,"X-координата камеры R7IN13 (см)","1269.0");
NewEEPROM("fEM_R7UY00RSS",1,&fEM_R7UY00RSS,"Y-координата АЗ1 (см)","506.6");
NewEEPROM("fEM_R7UY01RSS",1,&fEM_R7UY01RSS,"Y-координата камеры R7IN11","248.0");
NewEEPROM("fEM_R7UY02RSS",1,&fEM_R7UY02RSS,"Y-координата камеры R7IN12 (см)","284.5");
NewEEPROM("fEM_R7UY03RSS",1,&fEM_R7UY03RSS,"Y-координата камеры R7IN13 (см)","256.0");
NewEEPROM("fEM_A0UX00RSS",1,&fEM_A0UX00RSS,"Эффективный радиус АЗ","11.0");
NewEEPROM("fEM_A0UX01RSS",1,&fEM_A0UX01RSS,"Первый коэффициент калибровки камеры 1","1.0");
NewEEPROM("fEM_A0UX02RSS",1,&fEM_A0UX02RSS,"Первый коэффициент калибровки камеры 2","1.0");
NewEEPROM("fEM_A0UX03RSS",1,&fEM_A0UX03RSS,"Первый коэффициент калибровки камеры 3","1.0");
NewEEPROM("fEM_B0UX01RSS",1,&fEM_B0UX01RSS,"Второй коэффициент калибровки камеры 1","0");
NewEEPROM("fEM_B0UX02RSS",1,&fEM_B0UX02RSS,"Второй коэффициент калибровки камеры 2","0");
NewEEPROM("fEM_B0UX03RSS",1,&fEM_B0UX03RSS,"Второй коэффициент калибровки камеры 3","0");
NewEEPROM("fEM_R0UH05RSS",1,&fEM_R0UH05RSS,"Кол-во делений/сек на 1 ватт * E^6","32000.0");
NewEEPROM("fEM_R0UN03RSS",1,&fEM_R0UN03RSS,"Нижняя граница интервала мощности для измерения периода (ватт)","0.005");
NewEEPROM("fEM_R0UL01RSS",1,&fEM_R0UL01RSS,"Шаг (мс) измерения периода","0.5");
NewEEPROM("fEM_R0UL02RSS",1,&fEM_R0UL02RSS,"Предельное время ожидания роста потока (мс)","100");
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
  S_and2_80_1.x1 = &signal_R0DE31LS1;
  S_and2_80_1.x2 = &signal_R0DE32LS1;
  S_and5_61_1.x2 = &signal_R0IE13LS1;
  S_and5_61_1.x3 = &signal_A0EE03LS1;
  S_and5_61_1.x4 = &signal_R0IE11LS1;
  S_and5_61_1.x5 = &signal_R0IE12LS1;
  S_ocham_13_1.Ch1k = &signal_R0IN03FS1;
  S_ocham_13_1.Ch2k = &signal_R0IN02FS1;
  S_ocham_13_1.Ch3k = &signal_R0IN01FS1;
  S_ocham_13_1.YAz2 = &signal_B8VC01RDU;
  S_or2_68_1.x1 = &signal_R0EE01LZ1;
  S_or2_68_1.x2 = &signal_R0EE01LZ2;
  array_m88_x_1[0] = &signal_R0DE3CLS1;
  array_m88_x_1[1] = &signal_R0DE36LS1;
  array_m88_x_1[2] = &signal_R0DE37LS1;
  array_m88_x_1[3] = &signal_R0DE38LS1;
  array_m88_x_1[4] = &signal_R0DE39LS1;
  array_m88_x_1[5] = &signal_R0DE3ALS1;
  array_m88_x_1[6] = &signal_R0DE3BLS1;
  array_m88_x_1[7] = &signal_R0DE3DLS1;
  array_m78_x_1[0] = &signal_R0DE01LS1;
  array_m78_x_1[1] = &signal_R0DE02LS1;
  array_m78_x_1[2] = &signal_R0DE04LS1;
  array_m78_x_1[3] = &signal_R0DE05LS1;
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
