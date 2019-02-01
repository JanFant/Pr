#include "rpu.h"
extern  func_ext1();
// АП
//  Результат трансляции схемы D:\md\pti\pr\RPU\scheme\rpu.tpr

#define PBLENGTH 8192
#ifndef SIMUL_MODE
char EEPROMType = 2;/*0 - absent, 1 - external, 2 - internal, 3 - misc*/
#else
char *SchemaName = "D:\md\pti\pr\RPU\scheme\rpu.tpr";
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
#include <and3.h>
#include <and4.h>
#include <bol.h>
#include <drg.h>
#include <geterr.h>
#include <noto.h>
#include <ocham.h>
#include <or2.h>
#include <or3.h>
#include <or4.h>
#include <or5.h>
#include <scalzz.h>
#include <zzfs.h>

/* Определение внутренних параметров */
#define bFirstEnterFlag (*((psbool)(InternalBuf+0x0)))
#define internal1_m16_Nk (*((psint)(InternalBuf+0x2))) /*Nk - ведущая камера*/
#define internal1_m61_tx (*((psfloat)(InternalBuf+0x5))) /*tx - время накопленное сек*/
#define internal1_m61_y0 (*((pschar)(InternalBuf+0xA))) /*y0*/
#define internal1_m70_tx (*((psfloat)(InternalBuf+0xC))) /*tx - время накопленное сек*/
#define internal1_m70_y0 (*((pschar)(InternalBuf+0x11))) /*y0*/
#define internal1_m78_y0 (*((psfloat)(InternalBuf+0x13))) /*y0*/
#define internal1_m76_y0 (*((psfloat)(InternalBuf+0x18))) /*y0*/
#define internal1_m90_y1 (*((psbool)(InternalBuf+0x1D))) /*y1 - внутренний параметр*/
#define internal1_m101_y1 (*((psbool)(InternalBuf+0x1F))) /*y1 - внутренний параметр*/
#define internal1_m88_y1 (*((psbool)(InternalBuf+0x21))) /*y1 - внутренний параметр*/
#define internal1_m98_y1 (*((psbool)(InternalBuf+0x23))) /*y1 - внутренний параметр*/
int InternalBufSize = 37;

/* Определение сигналов */
#define signal_R0VN02RRP     (*((psfloat)(PBSTART+0x0)))  /*                       Уровень мощности канал 5 */
#define signal_R0IN01RRP     (*((psfloat)(PBSTART+0x5)))  /*                       Частота СНМ-11 Гц (канал 5) */
#define signal_R0IN02RRP     (*((psfloat)(PBSTART+0xa)))  /*                       Частота КНК15-1 Гц (канал 5) */
#define signal_R0VN03RRP     (*((psfloat)(PBSTART+0xf)))  /*                       Измеренный нейтронный поток канал 5 */
#define signal_B8VC01RDU     (*((psfloat)(PBSTART+0x14)))  /*                       Координата АЗ2, мм */
#define signal_R0IN03RRP     (*((psfloat)(PBSTART+0x19)))  /*                       Частота КНК53М Гц (канал 5) */
#define signal_A0EE02LRP     (*((psbool)(PBSTART+0x1e)))  /*                       Исправность АКНП5 (от сшивки каналов) канал 5 */
#define signal_R0VN23RRP     (*((psfloat)(PBSTART+0x20)))  /*                       Нейтронный поток по камере КНК15-1 канал 5 */
#define signal_R0VN33RRP     (*((psfloat)(PBSTART+0x25)))  /*                       Нейтронный поток по камере КНК53М канал 5 */
#define signal_R0VN15RRP     (*((psint)(PBSTART+0x2a)))  /*                       Номер ведущей камеры канал 5 */
#define signal_R0IE01LRP     (*((psbool)(PBSTART+0x2d)))  /*                       Отключение питание детекторов канал 5 */
#define signal_R0IE02LRP     (*((psbool)(PBSTART+0x2f)))  /*                       Отключить питание ПР, ПУ канал 5 */
#define signal_R0IN06RRP     (*((psfloat)(PBSTART+0x31)))  /*                       Частота СНМ-11 Гц (канал 6) */
#define signal_R7VN71LRP     (*((psbool)(PBSTART+0x36)))  /*                       Сигнал тревоги по уровню нейтронного потока на диспетчера */
#define signal_R0IN07RRP     (*((psfloat)(PBSTART+0x38)))  /*                       Частота СНМ-11 Гц (канал 7) */
#define signal_A0IT03IRP     (*((psint)(PBSTART+0x3d)))  /*                       Температура АЗ1-3 */
#define signal_A0CT01IRP     (*((psfloat)(PBSTART+0x40)))  /*                       Температура АЗ1-3 */
#define signal_A0VT61LRP     (*((psbool)(PBSTART+0x45)))  /*                       ПС по температуре в АЗ1 */
#define signal_A0VT71LRP     (*((psbool)(PBSTART+0x47)))  /*                       АС по температуре в АЗ1 */
#define signal_R0ET01LRP     (*((psbool)(PBSTART+0x49)))  /*                       Признак наличия неисправности по температуре  АЗ1-3 */
#define signal_B0IT03IRP     (*((psint)(PBSTART+0x4b)))  /*                       Температура АЗ2-3 */
#define signal_R0ET02LRP     (*((psbool)(PBSTART+0x4e)))  /*                       Признак наличия неисправности по температуре АЗ2-3 */
#define signal_B0CT01IRP     (*((psfloat)(PBSTART+0x50)))  /*                       Температура АЗ2-3 */
#define signal_B0VT61LRP     (*((psbool)(PBSTART+0x55)))  /*                       ПС по температуре в АЗ2-3 */
#define signal_B0VT71LRP     (*((psbool)(PBSTART+0x57)))  /*                       АС по температуре в АЗ2-3 */
#define signal_R0IE11LRP     (*((psbool)(PBSTART+0x59)))  /*                       Исправность ВИП 1,6 (№20) СНМ11 5 канала */
#define signal_A0EE03LRP     (*((psbool)(PBSTART+0x5b)))  /*                       Неисправность от диагностики контроллера */
#define signal_A0EE01LRP     (*((psbool)(PBSTART+0x5d)))  /*                       Исправность АКНП канал 5 */
#define signal_R0IE12LRP     (*((psbool)(PBSTART+0x5f)))  /*                       Исправность ВИП 0,5 -5к (№21) */
#define signal_R0IE13LRP     (*((psbool)(PBSTART+0x61)))  /*                       Исправность ВИП 0,5 -5к (№22) */
#define signal_R0IE14LRP     (*((psbool)(PBSTART+0x63)))  /*                       Исправность ВИП 1,6 БЗ-1 - 6к(№23) */
#define signal_R0IE15LRP     (*((psbool)(PBSTART+0x65)))  /*                       Исправность ВИП 1,6 БЗ-2 - 7к(№24) */
#define signal_R0IE03LRP     (*((psbool)(PBSTART+0x67)))  /*                       Отключение питание детекторов канал  6,7 */
#define signal_R0IE04LRP     (*((psbool)(PBSTART+0x69)))  /*                       Отключить питание ПР, ПУ канал 6,7 */
#define signal_A1VT71LRP     (*((psbool)(PBSTART+0x6b)))  /*                       АС по температуре */
#define signal_R0VN71LRP     (*((psbool)(PBSTART+0x6d)))  /*                       АС по мощности канал 5 */
#define signal_R0VN13RRP     (*((psfloat)(PBSTART+0x6f)))  /*                       Нейтронный поток по камере  СНМ-11 канал 5 */
#define signal_A6IS11LRP     (*((psbool)(PBSTART+0x74)))  /*                       Приход на ВУ БЗ1 */
#define signal_B6IS11LRP     (*((psbool)(PBSTART+0x76)))  /*                       Приход на ВУ БЗ2 */
#define signal_R7VE70LRP     (*((psbool)(PBSTART+0x78)))  /*                       Сигнал тревоги по неисправности РПУ на диспетчера */
#define signal_A3IS21LRP     (*((psbool)(PBSTART+0x7a)))  /*                       Приход на НУ ИС1 */
#define signal_B3IS21LRP     (*((psbool)(PBSTART+0x7c)))  /*                       Приход на НУ ИС2 */
#define signal_A1IS21LRP     (*((psbool)(PBSTART+0x7e)))  /*                       Приход на НУ ББ1 */
#define signal_B1IS21LRP     (*((psbool)(PBSTART+0x80)))  /*                       Приход на НУ ББ2 */
#define signal_A2IS21LRP     (*((psbool)(PBSTART+0x82)))  /*                       Приход на НУ РБ1-CC */
#define signal_B2IS21LRP     (*((psbool)(PBSTART+0x84)))  /*                       Приход на НУ РБ2-CC */
#define signal_A1VS21LRP     (*((psbool)(PBSTART+0x86)))  /*                       Индикация - Приход на НУ ББ1 */
#define signal_B1VS21LRP     (*((psbool)(PBSTART+0x88)))  /*                       Индикация - Приход на НУ ББ2 */
#define signal_A2VS21LRP     (*((psbool)(PBSTART+0x8a)))  /*                       Индикация - Приход на НУ РБ1-CC */
#define signal_B2VS21LRP     (*((psbool)(PBSTART+0x8c)))  /*                       Индикация - Приход на НУ РБ2-CC */
#define signal_A3VS21LRP     (*((psbool)(PBSTART+0x8e)))  /*                       Индикация - Приход на НУ ИС1 */
#define signal_B3VS21LRP     (*((psbool)(PBSTART+0x90)))  /*                       Индикация - Приход на НУ ИС2 */
#define signal_C1MD31LRP     (*((psbool)(PBSTART+0x92)))  /*                       Кнопка ОБЩИЙ СБРОС  на РПУ */
#define signal_C1MZ31LRP     (*((psbool)(PBSTART+0x94)))  /*                       Кнопка ОБДУВ  на РПУ */
#define signal_A7MZ31LRP     (*((psbool)(PBSTART+0x96)))  /*                       Клапан <ОБДУВ АЗ1> открыть(обесточить) */
#define signal_B7MZ31LRP     (*((psbool)(PBSTART+0x98)))  /*                       Клапан <ОБДУВ АЗ2> открыть(обесточить) */
#define signal_R0EE02LDU     (*((psbool)(PBSTART+0x9a)))  /*                       Питание  АКНП  отключить */

/* Определение констант ПЗУ и ЭСППЗУ*/
struct      sbool  lRM_0_ = {    0,0}; /* A-Граница участка насыщения А */ 
struct      sbool  lRM_1_ = {    1,0}; /* B-Граница участка насыщения В */ 
struct      slong  dRM_0_ = {    0,0}; /* lx вход лонг */ 
struct      schar  bRM_0_ = {    0,0}; /* cx вход байтовый */ 
struct       sint  iRM_0_ = {    0,0}; /* ix вход целый */ 
struct       sint  iRM_819_ = {  819,0}; /* a */ 
struct       sint  iRM_4095_ = { 4095,0}; /* b */ 
struct      schar  bRM_1_ = {    1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
struct     sfloat  fRM_2_0 = {  2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 
#define fEM_R0UH02RSS  (*((psfloat)(SpaEEPROMBuf+0x0)))
#define fEM_R0UH03RSS  (*((psfloat)(SpaEEPROMBuf+0x5)))
#define fEM_R7UX00RSS  (*((psfloat)(SpaEEPROMBuf+0xA)))
#define fEM_R7UY00RSS  (*((psfloat)(SpaEEPROMBuf+0xF)))
#define fEM_R7UX13RSS  (*((psfloat)(SpaEEPROMBuf+0x14)))
#define fEM_R7UX14RSS  (*((psfloat)(SpaEEPROMBuf+0x19)))
#define fEM_R7UX15RSS  (*((psfloat)(SpaEEPROMBuf+0x1E)))
#define fEM_R7UY13RSS  (*((psfloat)(SpaEEPROMBuf+0x23)))
#define fEM_R7UY14RSS  (*((psfloat)(SpaEEPROMBuf+0x28)))
#define fEM_R7UY15RSS  (*((psfloat)(SpaEEPROMBuf+0x2D)))
#define fEM_A0UX00RSS  (*((psfloat)(SpaEEPROMBuf+0x32)))
#define fEM_A0UX13RSS  (*((psfloat)(SpaEEPROMBuf+0x37)))
#define fEM_A0UX14RSS  (*((psfloat)(SpaEEPROMBuf+0x3C)))
#define fEM_A0UX15RSS  (*((psfloat)(SpaEEPROMBuf+0x41)))
#define fEM_B0UX03RSS  (*((psfloat)(SpaEEPROMBuf+0x46)))
#define fEM_B0UX04RSS  (*((psfloat)(SpaEEPROMBuf+0x4B)))
#define fEM_B0UX05RSS  (*((psfloat)(SpaEEPROMBuf+0x50)))
#define fEM_R0UH05RSS  (*((psfloat)(SpaEEPROMBuf+0x55)))
#define fEM_R0UR01RRP  (*((psfloat)(SpaEEPROMBuf+0x5A)))
#define fEM_R0UT02RZZ  (*((psfloat)(SpaEEPROMBuf+0x5F)))
#define fEM_R0UT01RZZ  (*((psfloat)(SpaEEPROMBuf+0x64)))
#define fEM_R0UT72RZZ  (*((psfloat)(SpaEEPROMBuf+0x69)))
#define fEM_R0UT71RZZ  (*((psfloat)(SpaEEPROMBuf+0x6E)))
#define fEM_R0UT62RZZ  (*((psfloat)(SpaEEPROMBuf+0x73)))
#define fEM_R0UT61RZZ  (*((psfloat)(SpaEEPROMBuf+0x78)))
#define fEM_R0UL52RSS  (*((psfloat)(SpaEEPROMBuf+0x7D)))
#define fEM_Z7UE20RRP  (*((psfloat)(SpaEEPROMBuf+0x82)))

int SpaEEPROMBufSize = 135;

/* Определение переменных */
struct sfloat  var1;
struct sfloat  var2;
struct sbool  var3;
struct sfloat  var4;
struct sfloat  var5;
struct sfloat  var6;
struct sint  var7;
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
struct schar  var20;
struct sbool  var21;
struct schar  var22;
struct sbool  var23;
struct sbool  var24;
struct sbool  var25;
struct sbool  var26;
struct sbool  var27;
struct sfloat  var28;
struct sfloat  var29;
struct schar  var30;
struct sbool  var31;
struct sbool  var32;
struct schar  var33;
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
struct slong  vainSLong;
struct sfloat  vainSFloat;
struct sint  vainSInt;
struct sbool  vainSBool;
struct schar  vainSChar;
char  vainSText[] = "";

/* Объявление массивов */

/* описания структур для ф-ий */

/* код алгоблоков */
/* Объявление структур */
_S_ocham far S_ocham_16_1 = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_1_,&fRM_2_0,NULL,NULL,NULL,&var1,&var2,&var3,&var4,&var5,&var6,&var7,NULL};
_S_or2 far S_or2_57_1 = {NULL,NULL,&vainSBool};
_S_or5 far S_or5_62_1 = {&var18,&var19,NULL,&var9,&var36,&var8};
_S_or2 far S_or2_84_1 = {&var43,&var44,&var9};
_S_or4 far S_or4_42_1 = {&var17,&var14,&var16,&var12,&var10};
_S_or2 far S_or2_89_1 = {&var42,&var31,&var11};
_S_or2 far S_or2_105_1 = {&var13,&var11,&var12};
_S_or2 far S_or2_85_1 = {&var41,&var34,&var13};
_S_and3 far S_and3_37_1 = {&var15,&var27,&var21,&var14};
_S_and4 far S_and4_36_1 = {NULL,&var3,NULL,NULL,&var15};
_S_and3 far S_and3_45_1 = {&var25,NULL,&var37,&var16};
_S_and3 far S_and3_44_1 = {NULL,&var25,&var38,&var17};
_S_and3 far S_and3_52_1 = {NULL,&var25,&var40,&var18};
_S_and3 far S_and3_51_1 = {&var39,NULL,&var25,&var19};
_S_geterr far S_geterr_48_1 = {NULL,&dRM_0_,&iRM_0_,&bRM_0_,&var20,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_noto far S_noto_71_1 = {&var26,&var21};
_S_geterr far S_geterr_47_1 = {NULL,&dRM_0_,&iRM_0_,&bRM_0_,&var22,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_zzfs far S_zzfs_61_1 = {&var24,NULL,&var23,NULL,NULL};
_S_or3 far S_or3_60_1 = {NULL,NULL,NULL,&var24};
_S_noto far S_noto_58_1 = {&var23,&var25};
_S_zzfs far S_zzfs_70_1 = {NULL,NULL,&var26,NULL,NULL};
_S_bol far S_bol_35_1 = {&var2,NULL,&var27};
_S_scalzz far S_scalzz_78_1 = {NULL,&iRM_819_,&iRM_4095_,NULL,NULL,&var28,NULL};
_S_scalzz far S_scalzz_76_1 = {NULL,&iRM_819_,&iRM_4095_,NULL,NULL,&var29,NULL};
_S_geterr far S_geterr_80_1 = {&var29,&dRM_0_,&iRM_0_,&bRM_0_,&var30,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg far S_drg_90_1 = {&var28,&lRM_0_,&lRM_1_,NULL,NULL,&var31,NULL};
_S_drg far S_drg_101_1 = {&var28,&lRM_0_,&lRM_1_,NULL,NULL,&var32,NULL};
_S_geterr far S_geterr_82_1 = {&var28,&dRM_0_,&iRM_0_,&bRM_0_,&var33,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg far S_drg_88_1 = {&var29,&lRM_0_,&lRM_1_,NULL,NULL,&var34,NULL};
_S_drg far S_drg_98_1 = {&var29,&lRM_0_,&lRM_1_,NULL,NULL,&var35,NULL};
_S_noto far S_noto_67_1 = {&var15,&var36};
_S_bol far S_bol_53_1 = {NULL,NULL,&var37};
_S_bol far S_bol_43_1 = {NULL,NULL,&var38};


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
  scalzz((&S_scalzz_76_1));
  scalzz((&S_scalzz_78_1));
  geterr((&S_geterr_47_1));
  geterr((&S_geterr_48_1));
  or2((&S_or2_57_1));
  ocham((&S_ocham_16_1));
  bol((&S_bol_43_1));
  bol((&S_bol_53_1));
  drg((&S_drg_98_1));
  drg((&S_drg_88_1));
  geterr((&S_geterr_82_1));
  drg((&S_drg_101_1));
  drg((&S_drg_90_1));
  geterr((&S_geterr_80_1));
  bol((&S_bol_35_1));
  zzfs((&S_zzfs_70_1));
  or3((&S_or3_60_1));
  zzfs((&S_zzfs_61_1));
  noto((&S_noto_71_1));
  and4((&S_and4_36_1));
  and3((&S_and3_37_1));
  var41.b = var30.c;
  var41.error = var30.error;
  or2((&S_or2_85_1));
  var42.b = var33.c;
  var42.error = var33.error;
  or2((&S_or2_89_1));
  var43.b = var30.c;
  var43.error = var30.error;
  var44.b = var33.c;
  var44.error = var33.error;
  or2((&S_or2_84_1));
  noto((&S_noto_67_1));
  noto((&S_noto_58_1));
  var39.b = var22.c;
  var39.error = var22.error;
  and3((&S_and3_51_1));
  var40.b = var20.c;
  var40.error = var20.error;
  and3((&S_and3_52_1));
  and3((&S_and3_44_1));
  and3((&S_and3_45_1));
  or2((&S_or2_105_1));
  or4((&S_or4_42_1));
  or5((&S_or5_62_1));
  signal_B7MZ31LRP.b = signal_C1MZ31LRP.b;
  signal_B7MZ31LRP.error = signal_C1MZ31LRP.error;
  signal_A7MZ31LRP.b = signal_C1MZ31LRP.b;
  signal_A7MZ31LRP.error = signal_C1MZ31LRP.error;
  signal_B3VS21LRP.b = signal_B3IS21LRP.b;
  signal_B3VS21LRP.error = signal_B3IS21LRP.error;
  signal_A3VS21LRP.b = signal_A3IS21LRP.b;
  signal_A3VS21LRP.error = signal_A3IS21LRP.error;
  signal_B2VS21LRP.b = signal_B2IS21LRP.b;
  signal_B2VS21LRP.error = signal_B2IS21LRP.error;
  signal_A2VS21LRP.b = signal_A2IS21LRP.b;
  signal_A2VS21LRP.error = signal_A2IS21LRP.error;
  signal_B1VS21LRP.b = signal_B1IS21LRP.b;
  signal_B1VS21LRP.error = signal_B1IS21LRP.error;
  signal_A1VS21LRP.b = signal_A1IS21LRP.b;
  signal_A1VS21LRP.error = signal_A1IS21LRP.error;
  signal_R7VE70LRP.b = var8.b;
  signal_R7VE70LRP.error = var8.error;
  fplet(&signal_R0VN13RRP.f,&var4.f);
  signal_R0VN13RRP.error = var4.error;
  signal_R0VN71LRP.b = var27.b;
  signal_R0VN71LRP.error = var27.error;
  signal_A1VT71LRP.b = var12.b;
  signal_A1VT71LRP.error = var12.error;
  signal_R0IE04LRP.b = var23.b;
  signal_R0IE04LRP.error = var23.error;
  signal_R0IE03LRP.b = var23.b;
  signal_R0IE03LRP.error = var23.error;
  signal_A0EE01LRP.b = var15.b;
  signal_A0EE01LRP.error = var15.error;
  signal_B0VT71LRP.b = var11.b;
  signal_B0VT71LRP.error = var11.error;
  signal_B0VT61LRP.b = var32.b;
  signal_B0VT61LRP.error = var32.error;
  fplet(&signal_B0CT01IRP.f,&var28.f);
  signal_B0CT01IRP.error = var28.error;
  signal_R0ET02LRP.b = var33.c;
  signal_R0ET02LRP.error = var33.error;
  signal_R0ET01LRP.b = var30.c;
  signal_R0ET01LRP.error = var30.error;
  signal_A0VT71LRP.b = var13.b;
  signal_A0VT71LRP.error = var13.error;
  signal_A0VT61LRP.b = var35.b;
  signal_A0VT61LRP.error = var35.error;
  fplet(&signal_A0CT01IRP.f,&var29.f);
  signal_A0CT01IRP.error = var29.error;
  signal_R7VN71LRP.b = var10.b;
  signal_R7VN71LRP.error = var10.error;
  signal_R0IE02LRP.b = var26.b;
  signal_R0IE02LRP.error = var26.error;
  signal_R0IE01LRP.b = var26.b;
  signal_R0IE01LRP.error = var26.error;
  signal_R0VN15RRP.i = var7.i;
  signal_R0VN15RRP.error = var7.error;
  fplet(&signal_R0VN33RRP.f,&var6.f);
  signal_R0VN33RRP.error = var6.error;
  fplet(&signal_R0VN23RRP.f,&var5.f);
  signal_R0VN23RRP.error = var5.error;
  signal_A0EE02LRP.b = var3.b;
  signal_A0EE02LRP.error = var3.error;
  fplet(&signal_R0VN03RRP.f,&var1.f);
  signal_R0VN03RRP.error = var1.error;
  fplet(&signal_R0VN02RRP.f,&var2.f);
  signal_R0VN02RRP.error = var2.error;

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
  CheckSFloat(5);
#else
ParExchange("R0IN01RRP",1,&SignalBuffer[5],"Частота СНМ-11 Гц (канал 5)",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(10);
#else
ParExchange("R0IN02RRP",1,&SignalBuffer[10],"Частота КНК15-1 Гц (канал 5)",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(20);
#else
ParExchange("B8VC01RDU",1,&SignalBuffer[20],"Координата АЗ2, мм",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(25);
#else
ParExchange("R0IN03RRP",1,&SignalBuffer[25],"Частота КНК53М Гц (канал 5)",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(49);
#else
ParExchange("R0IN06RRP",1,&SignalBuffer[49],"Частота СНМ-11 Гц (канал 6)",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(56);
#else
ParExchange("R0IN07RRP",1,&SignalBuffer[56],"Частота СНМ-11 Гц (канал 7)",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(61);
#else
ParExchange("A0IT03IRP",2,&SignalBuffer[61],"Температура АЗ1-3",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(75);
#else
ParExchange("B0IT03IRP",2,&SignalBuffer[75],"Температура АЗ2-3",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(89);
#else
ParExchange("R0IE11LRP",3,&SignalBuffer[89],"Исправность ВИП 1,6 (№20) СНМ11 5 канала",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(91);
#else
ParExchange("A0EE03LRP",3,&SignalBuffer[91],"Неисправность от диагностики контроллера",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(95);
#else
ParExchange("R0IE12LRP",3,&SignalBuffer[95],"Исправность ВИП 0,5 -5к (№21)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(97);
#else
ParExchange("R0IE13LRP",3,&SignalBuffer[97],"Исправность ВИП 0,5 -5к (№22)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(99);
#else
ParExchange("R0IE14LRP",3,&SignalBuffer[99],"Исправность ВИП 1,6 БЗ-1 - 6к(№23)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(101);
#else
ParExchange("R0IE15LRP",3,&SignalBuffer[101],"Исправность ВИП 1,6 БЗ-2 - 7к(№24)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(116);
#else
ParExchange("A6IS11LRP",3,&SignalBuffer[116],"Приход на ВУ БЗ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(118);
#else
ParExchange("B6IS11LRP",3,&SignalBuffer[118],"Приход на ВУ БЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(122);
#else
ParExchange("A3IS21LRP",3,&SignalBuffer[122],"Приход на НУ ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(124);
#else
ParExchange("B3IS21LRP",3,&SignalBuffer[124],"Приход на НУ ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(126);
#else
ParExchange("A1IS21LRP",3,&SignalBuffer[126],"Приход на НУ ББ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(128);
#else
ParExchange("B1IS21LRP",3,&SignalBuffer[128],"Приход на НУ ББ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(130);
#else
ParExchange("A2IS21LRP",3,&SignalBuffer[130],"Приход на НУ РБ1-CC",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(132);
#else
ParExchange("B2IS21LRP",3,&SignalBuffer[132],"Приход на НУ РБ2-CC",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(146);
#else
ParExchange("C1MD31LRP",3,&SignalBuffer[146],"Кнопка ОБЩИЙ СБРОС  на РПУ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(148);
#else
ParExchange("C1MZ31LRP",3,&SignalBuffer[148],"Кнопка ОБДУВ  на РПУ",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(154);
#else
ParExchange("R0EE02LDU",3,&SignalBuffer[154],"Питание  АКНП  отключить",0);
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
 for(counter=0; counter<156; counter++) {
   *((unsigned char*)(SignalBuffer)+PBLENGTH-counter-1) =
          (unsigned char)~(*((unsigned char*)(SignalBuffer)+counter));
 }
#endif
}
#endif
#ifdef SIMUL_MODE
void UnloadSignals()
{
ParExchange("R0VN02RRP",1,&SignalBuffer[0],"Уровень мощности канал 5",1);
ParExchange("R0VN03RRP",1,&SignalBuffer[15],"Измеренный нейтронный поток канал 5",1);
ParExchange("A0EE02LRP",3,&SignalBuffer[30],"Исправность АКНП5 (от сшивки каналов) канал 5",1);
ParExchange("R0VN23RRP",1,&SignalBuffer[32],"Нейтронный поток по камере КНК15-1 канал 5",1);
ParExchange("R0VN33RRP",1,&SignalBuffer[37],"Нейтронный поток по камере КНК53М канал 5",1);
ParExchange("R0VN15RRP",2,&SignalBuffer[42],"Номер ведущей камеры канал 5",1);
ParExchange("R0IE01LRP",3,&SignalBuffer[45],"Отключение питание детекторов канал 5",1);
ParExchange("R0IE02LRP",3,&SignalBuffer[47],"Отключить питание ПР, ПУ канал 5",1);
ParExchange("R7VN71LRP",3,&SignalBuffer[54],"Сигнал тревоги по уровню нейтронного потока на диспетчера",1);
ParExchange("A0CT01IRP",1,&SignalBuffer[64],"Температура АЗ1-3",1);
ParExchange("A0VT61LRP",3,&SignalBuffer[69],"ПС по температуре в АЗ1",1);
ParExchange("A0VT71LRP",3,&SignalBuffer[71],"АС по температуре в АЗ1",1);
ParExchange("R0ET01LRP",3,&SignalBuffer[73],"Признак наличия неисправности по температуре  АЗ1-3",1);
ParExchange("R0ET02LRP",3,&SignalBuffer[78],"Признак наличия неисправности по температуре АЗ2-3",1);
ParExchange("B0CT01IRP",1,&SignalBuffer[80],"Температура АЗ2-3",1);
ParExchange("B0VT61LRP",3,&SignalBuffer[85],"ПС по температуре в АЗ2-3",1);
ParExchange("B0VT71LRP",3,&SignalBuffer[87],"АС по температуре в АЗ2-3",1);
ParExchange("A0EE01LRP",3,&SignalBuffer[93],"Исправность АКНП канал 5",1);
ParExchange("R0IE03LRP",3,&SignalBuffer[103],"Отключение питание детекторов канал  6,7",1);
ParExchange("R0IE04LRP",3,&SignalBuffer[105],"Отключить питание ПР, ПУ канал 6,7",1);
ParExchange("A1VT71LRP",3,&SignalBuffer[107],"АС по температуре",1);
ParExchange("R0VN71LRP",3,&SignalBuffer[109],"АС по мощности канал 5",1);
ParExchange("R0VN13RRP",1,&SignalBuffer[111],"Нейтронный поток по камере  СНМ-11 канал 5",1);
ParExchange("R7VE70LRP",3,&SignalBuffer[120],"Сигнал тревоги по неисправности РПУ на диспетчера",1);
ParExchange("A1VS21LRP",3,&SignalBuffer[134],"Индикация - Приход на НУ ББ1",1);
ParExchange("B1VS21LRP",3,&SignalBuffer[136],"Индикация - Приход на НУ ББ2",1);
ParExchange("A2VS21LRP",3,&SignalBuffer[138],"Индикация - Приход на НУ РБ1-CC",1);
ParExchange("B2VS21LRP",3,&SignalBuffer[140],"Индикация - Приход на НУ РБ2-CC",1);
ParExchange("A3VS21LRP",3,&SignalBuffer[142],"Индикация - Приход на НУ ИС1",1);
ParExchange("B3VS21LRP",3,&SignalBuffer[144],"Индикация - Приход на НУ ИС2",1);
ParExchange("A7MZ31LRP",3,&SignalBuffer[150],"Клапан <ОБДУВ АЗ1> открыть(обесточить)",1);
ParExchange("B7MZ31LRP",3,&SignalBuffer[152],"Клапан <ОБДУВ АЗ2> открыть(обесточить)",1);
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
NewEEPROM("fEM_R0UH02RSS",1,&fEM_R0UH02RSS,"Коэфф. преобразования частота->нейтр/с КНК15-1","3703.704 ");
NewEEPROM("fEM_R0UH03RSS",1,&fEM_R0UH03RSS,"Коэфф. преобразования частота->нейтр/с КНК53М","62500.0");
NewEEPROM("fEM_R7UX00RSS",1,&fEM_R7UX00RSS,"X-координата АЗ1 (см)","1567.36");
NewEEPROM("fEM_R7UY00RSS",1,&fEM_R7UY00RSS,"Y-координата АЗ1 (см)","506.5");
NewEEPROM("fEM_R7UX13RSS",1,&fEM_R7UX13RSS,"X-координата камеры R7IN51","1570.0");
NewEEPROM("fEM_R7UX14RSS",1,&fEM_R7UX14RSS,"X-координата камеры R7IN52","1269");
NewEEPROM("fEM_R7UX15RSS",1,&fEM_R7UX15RSS,"X-координата камеры R7IN53","1281.2");
NewEEPROM("fEM_R7UY13RSS",1,&fEM_R7UY13RSS,"Y-координата камеры R7IN51","248.0");
NewEEPROM("fEM_R7UY14RSS",1,&fEM_R7UY14RSS,"Y-координата камеры R7IN52","572.4");
NewEEPROM("fEM_R7UY15RSS",1,&fEM_R7UY15RSS,"Y-координата камеры R7IN53","246.8");
NewEEPROM("fEM_A0UX00RSS",1,&fEM_A0UX00RSS,"Эффективный радиус АЗ","11.0");
NewEEPROM("fEM_A0UX13RSS",1,&fEM_A0UX13RSS,"Первый коэффициент калибровки камеры 13","1.0");
NewEEPROM("fEM_A0UX14RSS",1,&fEM_A0UX14RSS,"Первый коэффициент калибровки камеры 14","1.0");
NewEEPROM("fEM_A0UX15RSS",1,&fEM_A0UX15RSS,"Первый коэффициент калибровки камеры 15","1.0");
NewEEPROM("fEM_B0UX03RSS",1,&fEM_B0UX03RSS,"Второй коэффициент калибровки камеры 3","0");
NewEEPROM("fEM_B0UX04RSS",1,&fEM_B0UX04RSS,"Второй коэффициент калибровки камеры4","0");
NewEEPROM("fEM_B0UX05RSS",1,&fEM_B0UX05RSS,"Второй коэффициент калибровки камеры 5","0.0");
NewEEPROM("fEM_R0UH05RSS",1,&fEM_R0UH05RSS,"Кол-во делений/сек на 1 ватт * E^6","32000.0");
NewEEPROM("fEM_R0UR01RRP",1,&fEM_R0UR01RRP,"Уставка СНМ11 в БЗ - АС по частоте","1000");
NewEEPROM("fEM_R0UT02RZZ",1,&fEM_R0UT02RZZ,"Верхний предел шкалы датчика температуры","600");
NewEEPROM("fEM_R0UT01RZZ",1,&fEM_R0UT01RZZ,"Нижний предел шкалы датчика температуры","0");
NewEEPROM("fEM_R0UT72RZZ",1,&fEM_R0UT72RZZ,"Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)","150");
NewEEPROM("fEM_R0UT71RZZ",1,&fEM_R0UT71RZZ,"Уровень срабатывания аварийной сигнализации по температуре АЗ","200");
NewEEPROM("fEM_R0UT62RZZ",1,&fEM_R0UT62RZZ,"Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)","90");
NewEEPROM("fEM_R0UT61RZZ",1,&fEM_R0UT61RZZ,"Уровень срабатывания предупредительной сигнализации по температуре АЗ","100");
NewEEPROM("fEM_R0UL52RSS",1,&fEM_R0UL52RSS,"Уровень АС по мощности","5100");
NewEEPROM("fEM_Z7UE20RRP",1,&fEM_Z7UE20RRP,"Время задержки сигнала на включение источников питания после снятия команды на отключение","210");
#else
if(EEPROMFlag) {
  fplet(&fEM_R0UH02RSS.f,((float*)(IntEEPROMBuffer+0x0)));
  fEM_R0UH02RSS.error = 0;
  fplet(&fEM_R0UH03RSS.f,((float*)(IntEEPROMBuffer+0x4)));
  fEM_R0UH03RSS.error = 0;
  fplet(&fEM_R7UX00RSS.f,((float*)(IntEEPROMBuffer+0x8)));
  fEM_R7UX00RSS.error = 0;
  fplet(&fEM_R7UY00RSS.f,((float*)(IntEEPROMBuffer+0xC)));
  fEM_R7UY00RSS.error = 0;
  fplet(&fEM_R7UX13RSS.f,((float*)(IntEEPROMBuffer+0x10)));
  fEM_R7UX13RSS.error = 0;
  fplet(&fEM_R7UX14RSS.f,((float*)(IntEEPROMBuffer+0x14)));
  fEM_R7UX14RSS.error = 0;
  fplet(&fEM_R7UX15RSS.f,((float*)(IntEEPROMBuffer+0x18)));
  fEM_R7UX15RSS.error = 0;
  fplet(&fEM_R7UY13RSS.f,((float*)(IntEEPROMBuffer+0x1C)));
  fEM_R7UY13RSS.error = 0;
  fplet(&fEM_R7UY14RSS.f,((float*)(IntEEPROMBuffer+0x20)));
  fEM_R7UY14RSS.error = 0;
  fplet(&fEM_R7UY15RSS.f,((float*)(IntEEPROMBuffer+0x24)));
  fEM_R7UY15RSS.error = 0;
  fplet(&fEM_A0UX00RSS.f,((float*)(IntEEPROMBuffer+0x28)));
  fEM_A0UX00RSS.error = 0;
  fplet(&fEM_A0UX13RSS.f,((float*)(IntEEPROMBuffer+0x2C)));
  fEM_A0UX13RSS.error = 0;
  fplet(&fEM_A0UX14RSS.f,((float*)(IntEEPROMBuffer+0x30)));
  fEM_A0UX14RSS.error = 0;
  fplet(&fEM_A0UX15RSS.f,((float*)(IntEEPROMBuffer+0x34)));
  fEM_A0UX15RSS.error = 0;
  fplet(&fEM_B0UX03RSS.f,((float*)(IntEEPROMBuffer+0x38)));
  fEM_B0UX03RSS.error = 0;
  fplet(&fEM_B0UX04RSS.f,((float*)(IntEEPROMBuffer+0x3C)));
  fEM_B0UX04RSS.error = 0;
  fplet(&fEM_B0UX05RSS.f,((float*)(IntEEPROMBuffer+0x40)));
  fEM_B0UX05RSS.error = 0;
  fplet(&fEM_R0UH05RSS.f,((float*)(IntEEPROMBuffer+0x44)));
  fEM_R0UH05RSS.error = 0;
  fplet(&fEM_R0UR01RRP.f,((float*)(IntEEPROMBuffer+0x48)));
  fEM_R0UR01RRP.error = 0;
  fplet(&fEM_R0UT02RZZ.f,((float*)(IntEEPROMBuffer+0x4C)));
  fEM_R0UT02RZZ.error = 0;
  fplet(&fEM_R0UT01RZZ.f,((float*)(IntEEPROMBuffer+0x50)));
  fEM_R0UT01RZZ.error = 0;
  fplet(&fEM_R0UT72RZZ.f,((float*)(IntEEPROMBuffer+0x54)));
  fEM_R0UT72RZZ.error = 0;
  fplet(&fEM_R0UT71RZZ.f,((float*)(IntEEPROMBuffer+0x58)));
  fEM_R0UT71RZZ.error = 0;
  fplet(&fEM_R0UT62RZZ.f,((float*)(IntEEPROMBuffer+0x5C)));
  fEM_R0UT62RZZ.error = 0;
  fplet(&fEM_R0UT61RZZ.f,((float*)(IntEEPROMBuffer+0x60)));
  fEM_R0UT61RZZ.error = 0;
  fplet(&fEM_R0UL52RSS.f,((float*)(IntEEPROMBuffer+0x64)));
  fEM_R0UL52RSS.error = 0;
  fplet(&fEM_Z7UE20RRP.f,((float*)(IntEEPROMBuffer+0x68)));
  fEM_Z7UE20RRP.error = 0;
}
#endif
}

#ifndef SIMUL_MODE
unsigned int EndIntEEPROMAddress = 108;
#endif

void reInit_Signals(void)
{
  S_ocham_16_1.Ch1k = &signal_R0IN01RRP;
  S_ocham_16_1.Ch2k = &signal_R0IN02RRP;
  S_ocham_16_1.Ch3k = &signal_R0IN03RRP;
  S_ocham_16_1.YAz2 = &signal_B8VC01RDU;
  S_or2_57_1.x1 = &signal_A6IS11LRP;
  S_or2_57_1.x2 = &signal_B6IS11LRP;
  S_or5_62_1.x3 = &signal_A0EE03LRP;
  S_and4_36_1.x1 = &signal_R0IE11LRP;
  S_and4_36_1.x3 = &signal_R0IE12LRP;
  S_and4_36_1.x4 = &signal_R0IE13LRP;
  S_and3_45_1.x2 = &signal_R0IE14LRP;
  S_and3_44_1.x1 = &signal_R0IE15LRP;
  S_and3_52_1.x1 = &signal_R0IE14LRP;
  S_and3_51_1.x2 = &signal_R0IE15LRP;
  S_geterr_48_1.fx = &signal_R0IN06RRP;
  S_geterr_47_1.fx = &signal_R0IN07RRP;
  S_or3_60_1.x1 = &signal_A6IS11LRP;
  S_or3_60_1.x2 = &signal_B6IS11LRP;
  S_or3_60_1.x3 = &signal_R0EE02LDU;
  S_zzfs_70_1.x = &signal_R0EE02LDU;
  S_scalzz_78_1.x = &signal_B0IT03IRP;
  S_scalzz_76_1.x = &signal_A0IT03IRP;
  S_bol_53_1.x1 = &signal_R0IN07RRP;
  S_bol_43_1.x1 = &signal_R0IN06RRP;
}

void InitInternalParametr(void)
{
  int i;
  S_ocham_16_1.Nk = &internal1_m16_Nk;
  S_zzfs_61_1.tx = &internal1_m61_tx;
  S_zzfs_61_1.y0 = &internal1_m61_y0;
  S_zzfs_70_1.tx = &internal1_m70_tx;
  S_zzfs_70_1.y0 = &internal1_m70_y0;
  S_scalzz_78_1.y0 = &internal1_m78_y0;
  S_scalzz_76_1.y0 = &internal1_m76_y0;
  S_drg_90_1.y1 = &internal1_m90_y1;
  S_drg_101_1.y1 = &internal1_m101_y1;
  S_drg_88_1.y1 = &internal1_m88_y1;
  S_drg_98_1.y1 = &internal1_m98_y1;
  S_ocham_16_1.XAz = &fEM_R7UX00RSS;
  S_ocham_16_1.YAz1 = &fEM_R7UY00RSS;
  S_ocham_16_1.Reff = &fEM_A0UX00RSS;
  S_ocham_16_1.Ak1 = &fEM_A0UX13RSS;
  S_ocham_16_1.Bk1 = &fEM_B0UX03RSS;
  S_ocham_16_1.Ak2 = &fEM_A0UX14RSS;
  S_ocham_16_1.Bk2 = &fEM_B0UX04RSS;
  S_ocham_16_1.Ak3 = &fEM_A0UX15RSS;
  S_ocham_16_1.Bk3 = &fEM_B0UX05RSS;
  S_ocham_16_1.XCm1 = &fEM_R7UX13RSS;
  S_ocham_16_1.YCm1 = &fEM_R7UY13RSS;
  S_ocham_16_1.XCm2 = &fEM_R7UX14RSS;
  S_ocham_16_1.YCm2 = &fEM_R7UY14RSS;
  S_ocham_16_1.XCm3 = &fEM_R7UX15RSS;
  S_ocham_16_1.YCm3 = &fEM_R7UY15RSS;
  S_ocham_16_1.Kpr2k = &fEM_R0UH02RSS;
  S_ocham_16_1.Kpr3k = &fEM_R0UH03RSS;
  S_ocham_16_1.Kprm = &fEM_R0UH05RSS;
  S_zzfs_61_1.tz = &fEM_Z7UE20RRP;
  S_zzfs_70_1.tz = &fEM_Z7UE20RRP;
  S_bol_35_1.x2 = &fEM_R0UL52RSS;
  S_scalzz_78_1.c = &fEM_R0UT01RZZ;
  S_scalzz_78_1.d = &fEM_R0UT02RZZ;
  S_scalzz_76_1.c = &fEM_R0UT01RZZ;
  S_scalzz_76_1.d = &fEM_R0UT02RZZ;
  S_drg_90_1.e = &fEM_R0UT72RZZ;
  S_drg_90_1.f = &fEM_R0UT71RZZ;
  S_drg_101_1.e = &fEM_R0UT62RZZ;
  S_drg_101_1.f = &fEM_R0UT61RZZ;
  S_drg_88_1.e = &fEM_R0UT72RZZ;
  S_drg_88_1.f = &fEM_R0UT71RZZ;
  S_drg_98_1.e = &fEM_R0UT62RZZ;
  S_drg_98_1.f = &fEM_R0UT61RZZ;
  S_bol_53_1.x2 = &fEM_R0UR01RRP;
  S_bol_43_1.x2 = &fEM_R0UR01RRP;
}
