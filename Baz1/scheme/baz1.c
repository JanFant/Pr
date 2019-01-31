#include "baz1.h"
extern  func_ext1();
// АП
//  Результат трансляции схемы D:\md\pti\pr\Baz1\scheme\baz1.tpr

#define PBLENGTH 8192
#ifndef SIMUL_MODE
char EEPROMType = 2;/*0 - absent, 1 - external, 2 - internal, 3 - misc*/
#else
char *SchemaName = "D:\md\pti\pr\Baz1\scheme\baz1.tpr";
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

/* Определение внутренних параметров */
#define bFirstEnterFlag (*((psbool)(InternalBuf+0x0)))
#define internal1_m244_tx (*((psfloat)(InternalBuf+0x2))) /*tx - время накопленное сек*/
#define internal1_m244_y0 (*((pschar)(InternalBuf+0x7))) /*y0*/
#define internal1_m252_tx (*((psfloat)(InternalBuf+0x9))) /*tx - время накопленное сек*/
#define internal1_m252_y0 (*((pschar)(InternalBuf+0xE))) /*y0*/
#define internal1_m315_tx (*((psfloat)(InternalBuf+0x10))) /*tx - время накопленное сек*/
#define internal1_m315_y0 (*((pschar)(InternalBuf+0x15))) /*y0*/
#define internal1_m211_tx (*((psfloat)(InternalBuf+0x17))) /*tx - время накопленное сек*/
#define internal1_m211_y0 (*((pschar)(InternalBuf+0x1C))) /*y0*/
#define internal1_m210_tx (*((psfloat)(InternalBuf+0x1E))) /*tx - время накопленное сек*/
#define internal1_m210_y0 (*((pschar)(InternalBuf+0x23))) /*y0*/
#define internal1_m208_tx (*((psfloat)(InternalBuf+0x25))) /*tx - время накопленное сек*/
#define internal1_m208_y0 (*((pschar)(InternalBuf+0x2A))) /*y0*/
#define internal1_m206_tx (*((psfloat)(InternalBuf+0x2C))) /*tx - время накопленное сек*/
#define internal1_m206_y0 (*((pschar)(InternalBuf+0x31))) /*y0*/
#define internal1_m33_tx (*((psint)(InternalBuf+0x33))) /*tx - внутренний параметр*/
#define internal1_m143_y0 (*((psfloat)(InternalBuf+0x36))) /*y0*/
#define internal1_m141_y0 (*((psfloat)(InternalBuf+0x3B))) /*y0*/
#define internal1_m93_y0 (*((psfloat)(InternalBuf+0x40))) /*y0*/
#define internal1_m91_y0 (*((psfloat)(InternalBuf+0x45))) /*y0*/
#define internal1_m154_y1 (*((psbool)(InternalBuf+0x4A))) /*y1 - внутренний параметр*/
#define internal1_m165_y1 (*((psbool)(InternalBuf+0x4C))) /*y1 - внутренний параметр*/
#define internal1_m308_q0 (*((pslong)(InternalBuf+0x4E))) /*q0 - внутренний параметр*/
#define internal1_m130_y0 (*((psbool)(InternalBuf+0x53))) /*state*/
#define internal1_m123_y0 (*((psbool)(InternalBuf+0x55))) /*state*/
#define internal1_m106_y1 (*((psbool)(InternalBuf+0x57))) /*y1 - внутренний параметр*/
#define internal1_m116_y1 (*((psbool)(InternalBuf+0x59))) /*y1 - внутренний параметр*/
#define internal1_m97_y1 (*((psbool)(InternalBuf+0x5B))) /*y1 - внутренний параметр*/
#define internal1_m104_y1 (*((psbool)(InternalBuf+0x5D))) /*y1 - внутренний параметр*/
#define internal1_m153_y1 (*((psbool)(InternalBuf+0x5F))) /*y1 - внутренний параметр*/
#define internal1_m163_y1 (*((psbool)(InternalBuf+0x61))) /*y1 - внутренний параметр*/
int InternalBufSize = 99;

/* Определение сигналов */
#define signal_A0IT01IZ1     (*((psint)(PBSTART+0x0)))  /*                       Температура АЗ1-1 */
#define signal_A0CT01IZ1     (*((psfloat)(PBSTART+0x3)))  /*                       Температура АЗ1-1 */
#define signal_A0VT61LZ1     (*((psbool)(PBSTART+0x8)))  /*                       ПС по температуре в АЗ1 */
#define signal_A0VT71LZ1     (*((psbool)(PBSTART+0xa)))  /*                       АС по температуре в АЗ1 */
#define signal_A1VP41LZ1     (*((psbool)(PBSTART+0xc)))  /*                       Давление СБРОС ББ1 ниже АС */
#define signal_B1VP41LZ1     (*((psbool)(PBSTART+0xe)))  /*                       Давление СБРОС ББ2 ниже АС */
#define signal_B1VP81LZZ     (*((psbool)(PBSTART+0x10)))  /*                       Давление СБРОС ББ2 в норме */
#define signal_A1VP81LZZ     (*((psbool)(PBSTART+0x12)))  /*                       Давление СБРОС ББ1 в норме */
#define signal_A2VP41LZ1     (*((psbool)(PBSTART+0x14)))  /*                       Давление СБРОС РБ1 ниже АС */
#define signal_A2CP01RZ1     (*((psfloat)(PBSTART+0x16)))  /*                       Текущее давление СБРОС РБ1 */
#define signal_A2VP51LZ1     (*((psbool)(PBSTART+0x1b)))  /*                       Давление СБРОС РБ1 ниже ПС */
#define signal_B2VP41LZ1     (*((psbool)(PBSTART+0x1d)))  /*                       Давление СБРОС РБ2 ниже АС */
#define signal_B2CP01RZ1     (*((psfloat)(PBSTART+0x1f)))  /*                       Текущее давление СБРОС РБ2 */
#define signal_B2VP51LZ1     (*((psbool)(PBSTART+0x24)))  /*                       Давление СБРОС РБ2 ниже ПС */
#define signal_B2VP81LZ1     (*((psbool)(PBSTART+0x26)))  /*                       Давление СБРОС РБ2 в норме */
#define signal_A2VP81LZ1     (*((psbool)(PBSTART+0x28)))  /*                       Давление СБРОС РБ1 в норме */
#define signal_A2IP01IZ1     (*((psint)(PBSTART+0x2a)))  /*                       Текущее давление СБРОС РБ1 */
#define signal_B2IP01IZ1     (*((psint)(PBSTART+0x2d)))  /*                       Текущее давление СБРОС РБ2 */
#define signal_R0ET01LZ1     (*((psbool)(PBSTART+0x30)))  /*                       Признак наличия неисправности по температуре  АЗ1 */
#define signal_B0IT01IZ1     (*((psint)(PBSTART+0x32)))  /*                       Температура АЗ2-1 */
#define signal_A0VP41LZ1     (*((psbool)(PBSTART+0x35)))  /*                       Давление АЗ1 ниже АС */
#define signal_B0VP41LZ1     (*((psbool)(PBSTART+0x37)))  /*                       Давление АЗ2 ниже АС */
#define signal_B0VP81LZZ     (*((psbool)(PBSTART+0x39)))  /*                       Давление АЗ2 в норме */
#define signal_A0VP81LZZ     (*((psbool)(PBSTART+0x3b)))  /*                       Давление  АЗ1 в норме */
#define signal_R0ET02LZ1     (*((psbool)(PBSTART+0x3d)))  /*                       Признак наличия неисправности по температуре АЗ2 */
#define signal_B0EP02IZ1     (*((psint)(PBSTART+0x3f)))  /*                       Индикатор -Давление  АЗ2 ниже АС */
#define signal_A0EP02IZ1     (*((psint)(PBSTART+0x42)))  /*                       Индикатор -Давление  АЗ1 ниже АС */
#define signal_A0VP71LZ1     (*((psbool)(PBSTART+0x45)))  /*                       АЗ по АС любого давления для АЗ1 */
#define signal_B0VP71LZ1     (*((psbool)(PBSTART+0x47)))  /*                       АЗ по АС любого давления для АЗ2 */
#define signal_R0VN02RS1     (*((psfloat)(PBSTART+0x49)))  /*                       Уровень мощности канал 1 */
#define signal_R0VN02RS2     (*((psfloat)(PBSTART+0x4e)))  /*                       Уровень мощности канал 2 */
#define signal_R0VN02RS3     (*((psfloat)(PBSTART+0x53)))  /*                       Уровень мощности канал 3 */
#define signal_R0VN02RS4     (*((psfloat)(PBSTART+0x58)))  /*                       Уровень мощности канал 4 */
#define signal_R0VN01RS1     (*((psfloat)(PBSTART+0x5d)))  /*                       Период разгона канал 1 */
#define signal_R0VN01RS2     (*((psfloat)(PBSTART+0x62)))  /*                       Период разгона канал 2 */
#define signal_R0VN01RS3     (*((psfloat)(PBSTART+0x67)))  /*                       Период разгона канал 3 */
#define signal_R0VN01RS4     (*((psfloat)(PBSTART+0x6c)))  /*                       Период разгона канал 4 */
#define signal_R0VN61LS1     (*((psbool)(PBSTART+0x71)))  /*                       ПС по мощности канал 1 */
#define signal_R0VN61LS2     (*((psbool)(PBSTART+0x73)))  /*                       ПС по мощности канал 2 */
#define signal_R0VN61LS3     (*((psbool)(PBSTART+0x75)))  /*                       ПС по мощности канал 3 */
#define signal_R0VN61LS4     (*((psbool)(PBSTART+0x77)))  /*                       ПС по мощности канал 4 */
#define signal_R0VN65LS1     (*((psbool)(PBSTART+0x79)))  /*                       ПС по периоду разгона канал 1 */
#define signal_R0VN65LS2     (*((psbool)(PBSTART+0x7b)))  /*                       ПС по периоду разгона  канал 2 */
#define signal_R0VN65LS3     (*((psbool)(PBSTART+0x7d)))  /*                       ПС по периоду разгона канал 3 */
#define signal_R0VN65LS4     (*((psbool)(PBSTART+0x7f)))  /*                       ПС по периоду разгона канал 4 */
#define signal_R0VN01RZ1     (*((psfloat)(PBSTART+0x81)))  /*                       Уровень мощности по каналу 1 */
#define signal_R0VN02RZ1     (*((psfloat)(PBSTART+0x86)))  /*                       Уровень мощности по каналу 2 */
#define signal_R0VN03RZ1     (*((psfloat)(PBSTART+0x8b)))  /*                       Уровень мощности по каналу 3 */
#define signal_R0VN04RZ1     (*((psfloat)(PBSTART+0x90)))  /*                       Уровень мощности по каналу 4 */
#define signal_R0VN05RZ1     (*((psfloat)(PBSTART+0x95)))  /*                       Период разгона по каналу 1 */
#define signal_R0VN06RZ1     (*((psfloat)(PBSTART+0x9a)))  /*                       Период разгона по каналу 2 */
#define signal_R0VN07RZ1     (*((psfloat)(PBSTART+0x9f)))  /*                       Период разгона по каналу 3 */
#define signal_R0VN08RZ1     (*((psfloat)(PBSTART+0xa4)))  /*                       Период разгона по каналу 4 */
#define signal_R0VN61LZ1     (*((psbool)(PBSTART+0xa9)))  /*                       ПС по мощности канал 1 */
#define signal_R0VN62LZ1     (*((psbool)(PBSTART+0xab)))  /*                       ПС по мощности канал 2 */
#define signal_R0VN63LZ1     (*((psbool)(PBSTART+0xad)))  /*                       ПС по мощности канал 3 */
#define signal_R0VN64LZ1     (*((psbool)(PBSTART+0xaf)))  /*                       ПС по мощности канал 4 */
#define signal_R0VN65LZ1     (*((psbool)(PBSTART+0xb1)))  /*                       ПС по периоду разгона канал 1 */
#define signal_R0VN66LZ1     (*((psbool)(PBSTART+0xb3)))  /*                       ПС по периоду разгона канал 2 */
#define signal_R0VN67LZ1     (*((psbool)(PBSTART+0xb5)))  /*                       ПС по периоду разгона канал 3 */
#define signal_R0VN68LZ1     (*((psbool)(PBSTART+0xb7)))  /*                       ПС по периоду разгона канал 4 */
#define signal_R0VN09RZ1     (*((psfloat)(PBSTART+0xb9)))  /*                       Усредненный период разгона */
#define signal_A3IS11LDU     (*((psbool)(PBSTART+0xbe)))  /*                       Приход на ВУ ИС1 */
#define signal_A3IS22LDU     (*((psbool)(PBSTART+0xc0)))  /*                       Приход на НУП ИС1 */
#define signal_R0AD03LZ1     (*((psbool)(PBSTART+0xc2)))  /*                       Имитация прихода на ВУ ИС */
#define signal_B3IS11LDU     (*((psbool)(PBSTART+0xc4)))  /*                       Приход на ВУ ИС2 */
#define signal_A3VZ31LZ1     (*((psbool)(PBSTART+0xc6)))  /*                       АЗ от ВУ ИС1 */
#define signal_B3VZ31LZ1     (*((psbool)(PBSTART+0xc8)))  /*                       АЗ от ВУ ИС2 */
#define signal_R0AD05LZ1     (*((psbool)(PBSTART+0xca)))  /*                       Имитация ухода с НУП ИС */
#define signal_A3VZ11LZ1     (*((psbool)(PBSTART+0xcc)))  /*                       АЗ от НУП ИС1 */
#define signal_B3VZ11LZ1     (*((psbool)(PBSTART+0xce)))  /*                       АЗ от НУП ИС2 */
#define signal_B3IS22LDU     (*((psbool)(PBSTART+0xd0)))  /*                       Приход на НУП ИС2 */
#define signal_R0VN69LZ1     (*((psbool)(PBSTART+0xd2)))  /*                       ПС по усредненному периоду */
#define signal_R0VN79LZ1     (*((psbool)(PBSTART+0xd4)))  /*                       АС по усредненному периоду */
#define signal_R0VR02RZ1     (*((psfloat)(PBSTART+0xd6)))  /*                       Усредненная реактивность */
#define signal_R0VZ71LZ1     (*((psbool)(PBSTART+0xdb)))  /*                       Обобщенный сигнал АЗ 1 канала */
#define signal_R0VN70LZ1     (*((psbool)(PBSTART+0xdd)))  /*                       АЗ по АС мощности РУ */
#define signal_R0VN80LZ1     (*((psbool)(PBSTART+0xdf)))  /*                       АЗ по АС периода разгона РУ */
#define signal_A0EE01LS1     (*((psbool)(PBSTART+0xe1)))  /*                       Исправность АКНП канал 1 */
#define signal_A0EE01LS4     (*((psbool)(PBSTART+0xe3)))  /*                       Исправность АКНП канал 4 */
#define signal_A0EE01LS3     (*((psbool)(PBSTART+0xe5)))  /*                       Исправность АКНП канал 3 */
#define signal_A0EE01LZ1     (*((psbool)(PBSTART+0xe7)))  /*                       Исправность АКНП1 */
#define signal_A0EE04LZ1     (*((psbool)(PBSTART+0xe9)))  /*                       Исправность АКНП4 */
#define signal_A0EE02LZ1     (*((psbool)(PBSTART+0xeb)))  /*                       Исправность АКНП2 */
#define signal_A0EE03LZ1     (*((psbool)(PBSTART+0xed)))  /*                       Исправность АКНП3 */
#define signal_A0EE01LS2     (*((psbool)(PBSTART+0xef)))  /*                       Исправность АКНП  канал 2 */
#define signal_A0EE05LZ1     (*((psbool)(PBSTART+0xf1)))  /*                       Исправность сети АКНП1 */
#define signal_A0EE06LZ1     (*((psbool)(PBSTART+0xf3)))  /*                       Исправность сети АКНП2 */
#define signal_A0EE07LZ1     (*((psbool)(PBSTART+0xf5)))  /*                       Исправность сети АКНП3 */
#define signal_A0EE08LZ1     (*((psbool)(PBSTART+0xf7)))  /*                       Исправность сети АКНП4 */
#define signal_A0VZ71LZ1     (*((psbool)(PBSTART+0xf9)))  /*                       Обобщенный сигнал АС по АЗ1 */
#define signal_A0EE00LZ1     (*((psbool)(PBSTART+0xfb)))  /*                       Исправность АКНП АЗ1 */
#define signal_B0EE00LZ1     (*((psbool)(PBSTART+0xfd)))  /*                       Исправность АКНП АЗ2 */
#define signal_B0VZ71LZ1     (*((psbool)(PBSTART+0xff)))  /*                       Обобщенный сигнал АС по АЗ2 */
#define signal_A0VN71LZ1     (*((psbool)(PBSTART+0x101)))  /*                       АЗ по АС мощности  АЗ1 */
#define signal_B0VN71LZ1     (*((psbool)(PBSTART+0x103)))  /*                       АЗ по АС мощности  АЗ2 */
#define signal_A0VN81LZ1     (*((psbool)(PBSTART+0x105)))  /*                       АЗ по АС периода разгона АЗ1 */
#define signal_B0VN81LZ1     (*((psbool)(PBSTART+0x107)))  /*                       АЗ по АС периода разгона АЗ2 */
#define signal_R0EE02LDU     (*((psbool)(PBSTART+0x109)))  /*                       Питание  АКНП  отключить */
#define signal_R0VZ05UZ1     (*((pslong)(PBSTART+0x10b)))  /*                       Индикатор причины сброса */
#define signal_R0VN11RZ1     (*((psfloat)(PBSTART+0x110)))  /*                       Средняя мощность по БАЗ1 */
#define signal_R0VP73LZ1     (*((psbool)(PBSTART+0x115)))  /*                       ПС давления для РУ */
#define signal_B0CT01IZ1     (*((psfloat)(PBSTART+0x117)))  /*                       Температура АЗ2-1 */
#define signal_B0VT61LZ1     (*((psbool)(PBSTART+0x11c)))  /*                       ПС по температуре в АЗ2 */
#define signal_B0VT71LZ1     (*((psbool)(PBSTART+0x11e)))  /*                       АС по температуре в АЗ2 */
#define signal_A0VN71LS1     (*((psbool)(PBSTART+0x120)))  /*                       Блокировка автоматического подъёма ББ канал 1 */
#define signal_A0VN71LS2     (*((psbool)(PBSTART+0x122)))  /*                       Блокировка автоматического подъёма ББ канал 2 */
#define signal_A0VN71LS3     (*((psbool)(PBSTART+0x124)))  /*                       Блокировка автоматического подъёма ББ канал 3 */
#define signal_A0VN71LS4     (*((psbool)(PBSTART+0x126)))  /*                       Блокировка автоматического подъёма ББ канал 4 */
#define signal_A1VN71LZ1     (*((psbool)(PBSTART+0x128)))  /*                       Блокировка автоматического подъёма ББ */
#define signal_A3VZ15LZ1     (*((psbool)(PBSTART+0x12a)))  /*                       Имитация АЗ от НУП ИС */
#define signal_A3VZ13LZ1     (*((psbool)(PBSTART+0x12c)))  /*                       Имитация АЗ от ВУ ИС */
#define signal_R0VW13LDU     (*((psbool)(PBSTART+0x12e)))  /*                       Индикация выбора АЗ1 или АЗ1+АЗ2 */
#define signal_R0VW23LDU     (*((psbool)(PBSTART+0x130)))  /*                       Индикация выбора АЗ2 или АЗ1+АЗ2 */
#define signal_R7II73LZ1     (*((psbool)(PBSTART+0x132)))  /*                       Сработала АС II УР РАД */
#define signal_R7II71LZ1     (*((psbool)(PBSTART+0x134)))  /*                       Сработала АС IУР РАД (датчик 1) */
#define signal_R7II72LZ1     (*((psbool)(PBSTART+0x136)))  /*                       Сработала АС IУР РАД  (датчик 2) */
#define signal_R0AD14LZ1     (*((psbool)(PBSTART+0x138)))  /*                       Имитация АЗ от IIУР */
#define signal_R0AD21LDU     (*((psbool)(PBSTART+0x13a)))  /*                       Подключить защиту от II УР */
#define signal_R0AD14LDU     (*((psbool)(PBSTART+0x13c)))  /*                       Имитация срабатывания верхней АС II УР */
#define signal_R0MD34LP1     (*((psbool)(PBSTART+0x13e)))  /*                       Кнопка (Квитировать) */
#define signal_R0AD04LZ1     (*((psbool)(PBSTART+0x140)))  /*                       Имитация срабатывания верхней АС II УР */
#define signal_R0AD16LDU     (*((psbool)(PBSTART+0x142)))  /*                       Имитация срабатывания верхней АС I УР */
#define signal_R0EE01LZ1     (*((psbool)(PBSTART+0x144)))  /*                       Питание  АКНП1  отключить */
#define signal_R6IS66LZZ     (*((psbool)(PBSTART+0x146)))  /*                       Исправность ВИП 4,0 (№5) ССДИ-1-1 */
#define signal_R6IS67LZZ     (*((psbool)(PBSTART+0x148)))  /*                       Исправность ВИП 4,0 (№6) ССДИ-1-2 */
#define signal_R6IS68LZZ     (*((psbool)(PBSTART+0x14a)))  /*                       Исправность ВИП 4,0 (№7) ССДИ-2 */
#define signal_R0VN71LZ1     (*((psbool)(PBSTART+0x14c)))  /*                       АС по мощности канал 1 */
#define signal_R0VN75LZ1     (*((psbool)(PBSTART+0x14e)))  /*                       АС по периоду разгона канал 1 */
#define signal_R0VN72LZ1     (*((psbool)(PBSTART+0x150)))  /*                       АС по мощности канал 2 */
#define signal_R0VN76LZ1     (*((psbool)(PBSTART+0x152)))  /*                       АС по периоду разгона канал  2 */
#define signal_R0VN73LZ1     (*((psbool)(PBSTART+0x154)))  /*                       АС по мощности канал 3 */
#define signal_R0VN77LZ1     (*((psbool)(PBSTART+0x156)))  /*                       АС по периоду разгона канал  3 */
#define signal_R0VN74LZ1     (*((psbool)(PBSTART+0x158)))  /*                       АС по мощности канал 4 */
#define signal_R0VN78LZ1     (*((psbool)(PBSTART+0x15a)))  /*                       АС по периоду разгона канал  4 */
#define signal_R0EE02LZ1     (*((psbool)(PBSTART+0x15c)))  /*                       Питание  АКНП2  отключить */
#define signal_R0EE03LZ1     (*((psbool)(PBSTART+0x15e)))  /*                       Питание  АКНП3  отключить */
#define signal_R0EE04LZ1     (*((psbool)(PBSTART+0x160)))  /*                       Питание  АКНП4  отключить */
#define signal_R0AD15LZ1     (*((psbool)(PBSTART+0x162)))  /*                       Имитация АЗ от 1УР (датчик1) */
#define signal_R0AD16LZ1     (*((psbool)(PBSTART+0x164)))  /*                       Имитация АЗ от 1УР (датчик2) */
#define signal_R0MW12IP2     (*((psint)(PBSTART+0x166)))  /*                       Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС */
#define signal_A2IS12LDU     (*((psbool)(PBSTART+0x169)))  /*                       Магнит РБ1 зацеплен */
#define signal_B2IS12LDU     (*((psbool)(PBSTART+0x16b)))  /*                       Магнит РБ2 зацеплен */

/* Определение констант ПЗУ и ЭСППЗУ*/
struct      sbool  lRM_0_ = {    0,0}; /* A-Граница участка насыщения А */ 
struct      sbool  lRM_1_ = {    1,0}; /* B-Граница участка насыщения В */ 
struct      slong  dRM_0_ = {    0,0}; /* lx вход лонг */ 
struct      schar  bRM_0_ = {    0,0}; /* cx вход байтовый */ 
struct       sint  iRM_0_ = {    0,0}; /* ix вход целый */ 
struct       sint  iRM_3_ = {    3,0}; /* N-число входов */ 
struct       sint  iRM_4_ = {    4,0}; /* n - размерность массива */ 
struct       sint  iRM_6_ = {    6,0}; /* N-число входов */ 
struct       sint  iRM_17_ = {   17,0}; /* n - размерность массива входных сигналов */ 
struct       sint  iRM_819_ = {  819,0}; /* a */ 
struct       sint  iRM_4095_ = { 4095,0}; /* b */ 
struct     sfloat  fRM_0_00001 = {0.00001,0}; /* X2 */ 
struct       sint  iRM_200_ = {  200,0}; /* tz - ширина импульса, 10-ки мс */ 
struct     sfloat  fRM_0_2 = {  0.2,0}; /* tz - время задержки сек */ 
struct     sfloat  fRM_1_0 = {  1.0,0}; /* tz - время задержки сек */ 
struct       sint  iRM_7_ = {    7,0}; /* n - N-размерность массива x */ 
struct     sfloat  fRM_0_002 = {0.002,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_0_005 = {0.005,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_0_007 = {0.007,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_0_01 = { 0.01,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_0_015 = {0.015,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_0_02 = { 0.02,0}; /* x - массив входных параметров */ 
struct     sfloat  fRM_1_7 = {  1.7,0}; /* x - массив входных параметров */ 
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

/* Объявление массивов */
psfloat  array_m188_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psfloat  array_m330_x_1[4] = {NULL,NULL,NULL,NULL};
psbool  array_m330_diag_1[4] = {&var21,&var22,&var23,&var24};
psbool  array_m310_x_1[17] = {&var83,&var49,&var50,&var78,&var33,&var36,&var154,&var48,&var44,&var43,&var79,&var39,&var37,&var156,&var47,&var46,&var45};
psbool  array_m16_x_1[6] = {&var88,&var79,&var37,&var39,&var97,&var156};
psbool  array_m36_x_1[6] = {&var78,&var33,&var36,&var154,&var86,&var97};
psfloat  array_m2_x_1[4] = {NULL,NULL,NULL,NULL};
psbool  array_m2_diag_1[4] = {&var21,&var22,&var23,&var24};
psbool  array_m3_x_1[3] = {&var107,&var136,&var19};
psbool  array_m12_x_1[3] = {&var106,&var20,&var108};

/* описания структур для ф-ий */

/* код алгоблоков */
/* Объявление структур */
_S_ma far S_ma_188_1 = {array_m188_x_1,NULL,&iRM_7_,&vainSFloat};
_S_and3 far S_and3_232_1 = {&var4,&var14,&var13,&var1};
_S_and3 far S_and3_229_1 = {&var14,&var4,&var123,&var2};
_S_and3 far S_and3_228_1 = {&var13,&var4,&var122,&var3};
_S_noto far S_noto_220_1 = {NULL,&var4};
_S_and3 far S_and3_226_1 = {&var7,&var10,&var9,&var5};
_S_and3 far S_and3_223_1 = {&var7,&var9,&var125,&var6};
_S_noto far S_noto_214_1 = {NULL,&var7};
_S_and3 far S_and3_222_1 = {&var7,&var10,&var124,&var8};
_S_and2 far S_and2_215_1 = {&var101,NULL,&var9};
_S_and2 far S_and2_213_1 = {&var102,NULL,&var10};
_S_and3 far S_and3_207_1 = {&var102,&var101,NULL,&var11};
_S_and3 far S_and3_212_1 = {&var100,&var99,NULL,&var12};
_S_and2 far S_and2_216_1 = {&var100,NULL,&var13};
_S_and2 far S_and2_217_1 = {NULL,&var99,&var14};
_S_and2 far S_and2_251_1 = {&var121,&var31,&var15};
_S_zzfs far S_zzfs_244_1 = {NULL,&fRM_1_0,&var16,NULL,NULL};
_S_and2 far S_and2_126_1 = {&var159,&var135,&var17};
_S_and2 far S_and2_133_1 = {&var158,&var134,&var18};
_S_or2 far S_or2_103_1 = {&var165,&var163,&var19};
_S_or2 far S_or2_110_1 = {&var160,&var161,&var20};
_S_and2 far S_and2_80_1 = {NULL,NULL,&var21};
_S_and2 far S_and2_82_1 = {NULL,NULL,&var22};
_S_and2 far S_and2_84_1 = {NULL,NULL,&var23};
_S_and2 far S_and2_86_1 = {NULL,NULL,&var24};
_S_and2 far S_and2_178_1 = {&var151,&var116,&var25};
_S_and2 far S_and2_179_1 = {&var150,&var116,&var26};
_S_or2 far S_or2_255_1 = {&var104,NULL,&var27};
_S_or2 far S_or2_257_1 = {NULL,NULL,&var28};
_S_and2 far S_and2_256_1 = {&var28,&var27,&var29};
_S_or2 far S_or2_249_1 = {NULL,&var103,&var30};
_S_or3 far S_or3_250_1 = {&var32,&var30,&var29,&var31};
_S_or2 far S_or2_243_1 = {&var105,NULL,&var32};
_S_or2 far S_or2_230_1 = {&var8,&var5,&var33};
_S_or2 far S_or2_199_1 = {NULL,NULL,&var34};
_S_or2 far S_or2_201_1 = {NULL,NULL,&var35};
_S_or2 far S_or2_233_1 = {&var3,&var1,&var36};
_S_or2 far S_or2_234_1 = {&var2,&var1,&var37};
_S_or2 far S_or2_202_1 = {&var120,NULL,&var38};
_S_or2 far S_or2_231_1 = {&var6,&var5,&var39};
_S_or2 far S_or2_204_1 = {&var119,NULL,&var40};
_S_schl24 far S_schl24_332_1 = {NULL,NULL,NULL,NULL,&var41};
_S_and2 far S_and2_323_1 = {&var115,&var114,&var42};
_S_and2 far S_and2_312_1 = {&var62,&var84,&var43};
_S_and2 far S_and2_314_1 = {&var69,&var84,&var44};
_S_and2 far S_and2_320_1 = {&var29,&var98,&var45};
_S_and2 far S_and2_319_1 = {&var30,&var98,&var46};
_S_and2 far S_and2_318_1 = {&var32,&var98,&var47};
_S_and2 far S_and2_316_1 = {&var117,&var84,&var48};
_S_and2 far S_and2_313_1 = {&var73,&var84,&var49};
_S_and2 far S_and2_311_1 = {&var55,&var84,&var50};
_S_and2 far S_and2_297_1 = {&var53,&var52,&var51};
_S_or2 far S_or2_299_1 = {NULL,&var148,&var52};
_S_or2 far S_or2_300_1 = {NULL,&var147,&var53};
_S_or2 far S_or2_285_1 = {&var51,&var59,&var54};
_S_or2 far S_or2_291_1 = {&var56,&var51,&var55};
_S_and2 far S_and2_292_1 = {&var143,&var60,&var56};
_S_or2 far S_or2_302_1 = {NULL,&var145,&var57};
_S_or2 far S_or2_301_1 = {NULL,&var146,&var58};
_S_and2 far S_and2_298_1 = {&var58,&var57,&var59};
_S_schl24 far S_schl24_296_1 = {&var58,&var57,&var53,&var52,&var60};
_S_and2 far S_and2_294_1 = {&var84,&var60,&var61};
_S_or2 far S_or2_293_1 = {&var59,&var56,&var62};
_S_and2 far S_and2_289_1 = {&var62,&var84,&var63};
_S_or2 far S_or2_265_1 = {NULL,&var146,&var64};
_S_and2 far S_and2_280_1 = {&var73,&var84,&var65};
_S_and2 far S_and2_270_1 = {&var64,&var67,&var66};
_S_or2 far S_or2_266_1 = {NULL,&var145,&var67};
_S_and2 far S_and2_281_1 = {&var69,&var84,&var68};
_S_or2 far S_or2_278_1 = {&var66,&var72,&var69};
_S_or2 far S_or2_284_1 = {&var74,&var66,&var70};
_S_and2 far S_and2_272_1 = {&var76,&var84,&var71};
_S_and2 far S_and2_277_1 = {&var144,&var76,&var72};
_S_or2 far S_or2_276_1 = {&var74,&var72,&var73};
_S_and2 far S_and2_267_1 = {&var75,&var77,&var74};
_S_or2 far S_or2_264_1 = {NULL,&var147,&var75};
_S_schl24 far S_schl24_269_1 = {&var75,&var77,&var64,&var67,&var76};
_S_or2 far S_or2_263_1 = {NULL,&var148,&var77};
_S_or2 far S_or2_152_1 = {&var128,&var166,&var78};
_S_or2 far S_or2_150_1 = {&var133,&var131,&var79};
_S_or2 far S_or2_336_1 = {&var164,&var162,&var80};
_S_or2 far S_or2_35_1 = {NULL,NULL,&var81};
_S_and2 far S_and2_288_1 = {&var84,&var55,&var82};
_S_and2 far S_and2_317_1 = {&var118,&var84,&var83};
_S_and2 far S_and2_22_1 = {&var113,&var109,&var84};
_S_or2 far S_or2_26_1 = {&var141,&var140,&var85};
_S_and2 far S_and2_31_1 = {&var87,&var84,&var86};
_S_or3 far S_or3_30_1 = {&var55,&var73,&var112,&var87};
_S_and2 far S_and2_19_1 = {&var84,&var89,&var88};
_S_or3 far S_or3_18_1 = {&var69,&var62,&var111,&var89};
_S_and2 far S_and2_6_1 = {&var22,&var24,&var90};
_S_or2 far S_or2_9_1 = {&var142,&var90,&var91};
_S_or2 far S_or2_8_1 = {&var93,&var142,&var92};
_S_and2 far S_and2_5_1 = {&var21,&var23,&var93};
_S_and2 far S_and2_189_1 = {NULL,NULL,&var94};
_S_and2 far S_and2_185_1 = {NULL,NULL,&var95};
_S_and2 far S_and2_182_1 = {NULL,NULL,&var96};
_S_zpfs far S_zpfs_252_1 = {&var15,NULL,&var97,NULL,NULL};
_S_zpfs far S_zpfs_315_1 = {&var42,&fRM_0_2,&var98,NULL,NULL};
_S_zpfs far S_zpfs_211_1 = {&var40,NULL,&var99,NULL,NULL};
_S_zpfs far S_zpfs_210_1 = {&var38,NULL,&var100,NULL,NULL};
_S_zpfs far S_zpfs_208_1 = {&var35,NULL,&var101,NULL,NULL};
_S_zpfs far S_zpfs_206_1 = {&var34,NULL,&var102,NULL,NULL};
_S_noto far S_noto_248_1 = {NULL,&var103};
_S_noto far S_noto_254_1 = {NULL,&var104};
_S_noto far S_noto_237_1 = {NULL,&var105};
_S_noto far S_noto_129_1 = {NULL,&var106};
_S_noto far S_noto_128_1 = {NULL,&var107};
_S_noto far S_noto_96_1 = {NULL,&var108};
_S_noto far S_noto_27_1 = {&var110,&var109};
_S_ovb1 far S_ovb1_33_1 = {&var81,&iRM_200_,&var110,NULL};
_S_noto far S_noto_13_1 = {&var91,&var111};
_S_noto far S_noto_15_1 = {&var92,&var112};
_S_noto far S_noto_25_1 = {NULL,&var113};
_S_noto far S_noto_325_1 = {NULL,&var114};
_S_noto far S_noto_324_1 = {NULL,&var115};
_S_bol far S_bol_174_1 = {&var152,&fRM_0_00001,&var116};
_S_noto far S_noto_321_1 = {&var91,&var117};
_S_noto far S_noto_322_1 = {&var92,&var118};
_S_noto far S_noto_198_1 = {NULL,&var119};
_S_noto far S_noto_197_1 = {NULL,&var120};
_S_noto far S_noto_245_1 = {&var16,&var121};
_S_noto far S_noto_225_1 = {NULL,&var122};
_S_noto far S_noto_224_1 = {NULL,&var123};
_S_noto far S_noto_219_1 = {NULL,&var124};
_S_noto far S_noto_218_1 = {NULL,&var125};
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
_S_noto far S_noto_287_1 = {&var54,&var143};
_S_noto far S_noto_282_1 = {&var70,&var144};
_S_noto far S_noto_271_1 = {NULL,&var145};
_S_noto far S_noto_275_1 = {NULL,&var146};
_S_noto far S_noto_274_1 = {NULL,&var147};
_S_noto far S_noto_268_1 = {NULL,&var148};
_S_react far S_react_170_1 = {&var152,&var149};
_S_bol far S_bol_175_1 = {NULL,&var152,&var150};
_S_bol far S_bol_173_1 = {NULL,&var152,&var151};
_S_srm far S_srm_2_1 = {array_m2_x_1,array_m2_diag_1,&iRM_4_,&iRM_3_,&var152,&var153};
_S_ornc far S_ornc_3_1 = {array_m3_x_1,&iRM_3_,&var154,&var155};
_S_ornc far S_ornc_12_1 = {array_m12_x_1,&iRM_3_,&var156,&var157};
_S_tprg far S_tprg_130_1 = {&var129,NULL,NULL,NULL,NULL,&var158,NULL};
_S_tprg far S_tprg_123_1 = {&var130,NULL,NULL,NULL,NULL,&var159,NULL};
_S_geterr far S_geterr_102_1 = {&var129,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var160};
_S_drg far S_drg_106_1 = {&var129,&lRM_1_,&lRM_0_,NULL,NULL,&var161,NULL};
_S_drg far S_drg_116_1 = {&var129,&lRM_1_,&lRM_0_,NULL,NULL,&var162,NULL};
_S_drg far S_drg_97_1 = {&var130,&lRM_1_,&lRM_0_,NULL,NULL,&var163,NULL};
_S_drg far S_drg_104_1 = {&var130,&lRM_1_,&lRM_0_,NULL,NULL,&var164,NULL};
_S_geterr far S_geterr_99_1 = {&var130,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var165};
_S_drg far S_drg_153_1 = {&var127,&lRM_0_,&lRM_1_,NULL,NULL,&var166,NULL};
_S_drg far S_drg_163_1 = {&var127,&lRM_0_,&lRM_1_,NULL,NULL,&var167,NULL};


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
  noto((&S_noto_268_1));
  noto((&S_noto_274_1));
  noto((&S_noto_275_1));
  noto((&S_noto_271_1));
  noto((&S_noto_95_1));
  scalzz((&S_scalzz_91_1));
  scalzz((&S_scalzz_93_1));
  scalzz((&S_scalzz_141_1));
  scalzz((&S_scalzz_143_1));
  noto((&S_noto_219_1));
  noto((&S_noto_224_1));
  noto((&S_noto_225_1));
  noto((&S_noto_197_1));
  noto((&S_noto_198_1));
  noto((&S_noto_25_1));
  noto((&S_noto_96_1));
  noto((&S_noto_128_1));
  noto((&S_noto_129_1));
  noto((&S_noto_237_1));
  noto((&S_noto_254_1));
  noto((&S_noto_248_1));
  and2((&S_and2_182_1));
  and2((&S_and2_185_1));
  and2((&S_and2_189_1));
  or2((&S_or2_263_1));
  or2((&S_or2_264_1));
  and2((&S_and2_267_1));
  or2((&S_or2_266_1));
  or2((&S_or2_265_1));
  or2((&S_or2_301_1));
  or2((&S_or2_302_1));
  or2((&S_or2_300_1));
  or2((&S_or2_299_1));
  and2((&S_and2_297_1));
  schl24((&S_schl24_332_1));
  or2((&S_or2_204_1));
  or2((&S_or2_202_1));
  or2((&S_or2_201_1));
  or2((&S_or2_199_1));
  or2((&S_or2_243_1));
  or2((&S_or2_249_1));
  or2((&S_or2_257_1));
  or2((&S_or2_255_1));
  and2((&S_and2_86_1));
  and2((&S_and2_84_1));
  and2((&S_and2_82_1));
  and2((&S_and2_80_1));
  zzfs((&S_zzfs_244_1));
  noto((&S_noto_214_1));
  noto((&S_noto_220_1));
  ma((&S_ma_188_1));
  drg((&S_drg_163_1));
  drg((&S_drg_153_1));
  geterr((&S_geterr_99_1));
  drg((&S_drg_104_1));
  drg((&S_drg_97_1));
  drg((&S_drg_116_1));
  drg((&S_drg_106_1));
  geterr((&S_geterr_102_1));
  tprg((&S_tprg_123_1));
  tprg((&S_tprg_130_1));
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
  noto((&S_noto_218_1));
  noto((&S_noto_245_1));
  bol((&S_bol_174_1));
  noto((&S_noto_324_1));
  noto((&S_noto_325_1));
  zpfs((&S_zpfs_206_1));
  zpfs((&S_zpfs_208_1));
  zpfs((&S_zpfs_210_1));
  zpfs((&S_zpfs_211_1));
  and2((&S_and2_5_1));
  or2((&S_or2_8_1));
  and2((&S_and2_6_1));
  or2((&S_or2_35_1));
  or2((&S_or2_336_1));
  or2((&S_or2_150_1));
  or2((&S_or2_152_1));
  schl24((&S_schl24_269_1));
  and2((&S_and2_270_1));
  schl24((&S_schl24_296_1));
  and2((&S_and2_298_1));
  or2((&S_or2_285_1));
  and2((&S_and2_323_1));
  and2((&S_and2_256_1));
  and2((&S_and2_179_1));
  and2((&S_and2_178_1));
  or2((&S_or2_110_1));
  or2((&S_or2_103_1));
  and2((&S_and2_133_1));
  and2((&S_and2_126_1));
  and2((&S_and2_217_1));
  and2((&S_and2_216_1));
  and3((&S_and3_212_1));
  and3((&S_and3_207_1));
  and2((&S_and2_213_1));
  and2((&S_and2_215_1));
  and3((&S_and3_222_1));
  and3((&S_and3_223_1));
  and3((&S_and3_226_1));
  and3((&S_and3_228_1));
  and3((&S_and3_229_1));
  and3((&S_and3_232_1));
  ornc((&S_ornc_12_1));
  ornc((&S_ornc_3_1));
  noto((&S_noto_287_1));
  noto((&S_noto_322_1));
  noto((&S_noto_15_1));
  ovb1((&S_ovb1_33_1));
  noto((&S_noto_27_1));
  zpfs((&S_zpfs_315_1));
  or2((&S_or2_9_1));
  and2((&S_and2_22_1));
  and2((&S_and2_317_1));
  and2((&S_and2_272_1));
  or2((&S_or2_284_1));
  and2((&S_and2_294_1));
  and2((&S_and2_292_1));
  or2((&S_or2_291_1));
  and2((&S_and2_311_1));
  and2((&S_and2_318_1));
  and2((&S_and2_319_1));
  and2((&S_and2_320_1));
  or2((&S_or2_231_1));
  or2((&S_or2_234_1));
  or2((&S_or2_233_1));
  or2((&S_or2_230_1));
  or3((&S_or3_250_1));
  and2((&S_and2_251_1));
  noto((&S_noto_282_1));
  noto((&S_noto_321_1));
  noto((&S_noto_13_1));
  zpfs((&S_zpfs_252_1));
  and2((&S_and2_288_1));
  and2((&S_and2_277_1));
  or2((&S_or2_278_1));
  and2((&S_and2_281_1));
  or2((&S_or2_293_1));
  and2((&S_and2_316_1));
  and2((&S_and2_314_1));
  and2((&S_and2_312_1));
  or3((&S_or3_18_1));
  and2((&S_and2_19_1));
  or2((&S_or2_276_1));
  and2((&S_and2_280_1));
  and2((&S_and2_289_1));
  and2((&S_and2_313_1));
  orn((&S_orn_16_1));
  orni((&S_orni_310_1));
  rsu((&S_rsu_308_1));
  or3((&S_or3_30_1));
  and2((&S_and2_31_1));
  orn((&S_orn_36_1));
  or2((&S_or2_26_1));
  signal_R0AD16LZ1.b = var94.b;
  signal_R0AD16LZ1.error = var94.error;
  signal_R0AD15LZ1.b = var95.b;
  signal_R0AD15LZ1.error = var95.error;
  signal_R0EE04LZ1.b = signal_R0EE02LDU.b;
  signal_R0EE04LZ1.error = signal_R0EE02LDU.error;
  signal_R0EE03LZ1.b = signal_R0EE02LDU.b;
  signal_R0EE03LZ1.error = signal_R0EE02LDU.error;
  signal_R0EE02LZ1.b = signal_R0EE02LDU.b;
  signal_R0EE02LZ1.error = signal_R0EE02LDU.error;
  signal_R0EE01LZ1.b = signal_R0EE02LDU.b;
  signal_R0EE01LZ1.error = signal_R0EE02LDU.error;
  signal_R0AD14LZ1.b = var96.b;
  signal_R0AD14LZ1.error = var96.error;
  signal_A3VZ13LZ1.b = var12.b;
  signal_A3VZ13LZ1.error = var12.error;
  signal_A3VZ15LZ1.b = var11.b;
  signal_A3VZ15LZ1.error = var11.error;
  signal_A1VN71LZ1.b = var41.b;
  signal_A1VN71LZ1.error = var41.error;
  signal_B0VT71LZ1.b = var79.b;
  signal_B0VT71LZ1.error = var79.error;
  signal_B0VT61LZ1.b = var132.b;
  signal_B0VT61LZ1.error = var132.error;
  fplet(&signal_B0CT01IZ1.f,&var126.f);
  signal_B0CT01IZ1.error = var126.error;
  signal_R0VP73LZ1.b = var80.b;
  signal_R0VP73LZ1.error = var80.error;
  fplet(&signal_R0VN11RZ1.f,&var137.f);
  signal_R0VN11RZ1.error = var137.error;
  signal_R0VZ05UZ1.l = var138.l;
  signal_R0VZ05UZ1.error = var138.error;
  signal_B0VN81LZ1.b = var63.b;
  signal_B0VN81LZ1.error = var63.error;
  signal_A0VN81LZ1.b = var82.b;
  signal_A0VN81LZ1.error = var82.error;
  signal_B0VN71LZ1.b = var68.b;
  signal_B0VN71LZ1.error = var68.error;
  signal_A0VN71LZ1.b = var65.b;
  signal_A0VN71LZ1.error = var65.error;
  signal_B0VZ71LZ1.b = var140.b;
  signal_B0VZ71LZ1.error = var140.error;
  signal_B0EE00LZ1.b = var91.b;
  signal_B0EE00LZ1.error = var91.error;
  signal_A0EE00LZ1.b = var92.b;
  signal_A0EE00LZ1.error = var92.error;
  signal_A0VZ71LZ1.b = var141.b;
  signal_A0VZ71LZ1.error = var141.error;
  signal_A0EE03LZ1.b = var23.b;
  signal_A0EE03LZ1.error = var23.error;
  signal_A0EE02LZ1.b = var22.b;
  signal_A0EE02LZ1.error = var22.error;
  signal_A0EE04LZ1.b = var24.b;
  signal_A0EE04LZ1.error = var24.error;
  signal_A0EE01LZ1.b = var21.b;
  signal_A0EE01LZ1.error = var21.error;
  signal_R0VN80LZ1.b = var61.b;
  signal_R0VN80LZ1.error = var61.error;
  signal_R0VN70LZ1.b = var71.b;
  signal_R0VN70LZ1.error = var71.error;
  signal_R0VZ71LZ1.b = var85.b;
  signal_R0VZ71LZ1.error = var85.error;
  fplet(&signal_R0VR02RZ1.f,&var149.f);
  signal_R0VR02RZ1.error = var149.error;
  signal_R0VN79LZ1.b = var26.b;
  signal_R0VN79LZ1.error = var26.error;
  signal_R0VN69LZ1.b = var25.b;
  signal_R0VN69LZ1.error = var25.error;
  signal_B3VZ11LZ1.b = var39.b;
  signal_B3VZ11LZ1.error = var39.error;
  signal_A3VZ11LZ1.b = var33.b;
  signal_A3VZ11LZ1.error = var33.error;
  signal_B3VZ31LZ1.b = var37.b;
  signal_B3VZ31LZ1.error = var37.error;
  signal_A3VZ31LZ1.b = var36.b;
  signal_A3VZ31LZ1.error = var36.error;
  fplet(&signal_R0VN09RZ1.f,&var152.f);
  signal_R0VN09RZ1.error = var152.error;
  signal_R0VN68LZ1.b = signal_R0VN65LS4.b;
  signal_R0VN68LZ1.error = signal_R0VN65LS4.error;
  signal_R0VN67LZ1.b = signal_R0VN65LS3.b;
  signal_R0VN67LZ1.error = signal_R0VN65LS3.error;
  signal_R0VN66LZ1.b = signal_R0VN65LS2.b;
  signal_R0VN66LZ1.error = signal_R0VN65LS2.error;
  signal_R0VN65LZ1.b = signal_R0VN65LS1.b;
  signal_R0VN65LZ1.error = signal_R0VN65LS1.error;
  signal_R0VN64LZ1.b = signal_R0VN61LS4.b;
  signal_R0VN64LZ1.error = signal_R0VN61LS4.error;
  signal_R0VN63LZ1.b = signal_R0VN61LS3.b;
  signal_R0VN63LZ1.error = signal_R0VN61LS3.error;
  signal_R0VN62LZ1.b = signal_R0VN61LS2.b;
  signal_R0VN62LZ1.error = signal_R0VN61LS2.error;
  signal_R0VN61LZ1.b = signal_R0VN61LS1.b;
  signal_R0VN61LZ1.error = signal_R0VN61LS1.error;
  fplet(&signal_R0VN08RZ1.f,&signal_R0VN01RS4.f);
  signal_R0VN08RZ1.error = signal_R0VN01RS4.error;
  fplet(&signal_R0VN07RZ1.f,&signal_R0VN01RS3.f);
  signal_R0VN07RZ1.error = signal_R0VN01RS3.error;
  fplet(&signal_R0VN06RZ1.f,&signal_R0VN01RS2.f);
  signal_R0VN06RZ1.error = signal_R0VN01RS2.error;
  fplet(&signal_R0VN05RZ1.f,&signal_R0VN01RS1.f);
  signal_R0VN05RZ1.error = signal_R0VN01RS1.error;
  fplet(&signal_R0VN04RZ1.f,&signal_R0VN02RS4.f);
  signal_R0VN04RZ1.error = signal_R0VN02RS4.error;
  fplet(&signal_R0VN03RZ1.f,&signal_R0VN02RS3.f);
  signal_R0VN03RZ1.error = signal_R0VN02RS3.error;
  fplet(&signal_R0VN02RZ1.f,&signal_R0VN02RS2.f);
  signal_R0VN02RZ1.error = signal_R0VN02RS2.error;
  fplet(&signal_R0VN01RZ1.f,&signal_R0VN02RS1.f);
  signal_R0VN01RZ1.error = signal_R0VN02RS1.error;
  signal_B0VP71LZ1.b = var156.b;
  signal_B0VP71LZ1.error = var156.error;
  signal_A0VP71LZ1.b = var154.b;
  signal_A0VP71LZ1.error = var154.error;
  signal_A0EP02IZ1.i = var155.c;
  signal_A0EP02IZ1.error = var155.error;
  signal_B0EP02IZ1.i = var157.c;
  signal_B0EP02IZ1.error = var157.error;
  signal_R0ET02LZ1.b = var133.b;
  signal_R0ET02LZ1.error = var133.error;
  signal_B0VP41LZ1.b = var106.b;
  signal_B0VP41LZ1.error = var106.error;
  signal_A0VP41LZ1.b = var107.b;
  signal_A0VP41LZ1.error = var107.error;
  signal_R0ET01LZ1.b = var128.b;
  signal_R0ET01LZ1.error = var128.error;
  signal_A2VP81LZ1.b = var17.b;
  signal_A2VP81LZ1.error = var17.error;
  signal_B2VP81LZ1.b = var18.b;
  signal_B2VP81LZ1.error = var18.error;
  signal_B2VP51LZ1.b = var162.b;
  signal_B2VP51LZ1.error = var162.error;
  fplet(&signal_B2CP01RZ1.f,&var129.f);
  signal_B2CP01RZ1.error = var129.error;
  signal_B2VP41LZ1.b = var20.b;
  signal_B2VP41LZ1.error = var20.error;
  signal_A2VP51LZ1.b = var164.b;
  signal_A2VP51LZ1.error = var164.error;
  fplet(&signal_A2CP01RZ1.f,&var130.f);
  signal_A2CP01RZ1.error = var130.error;
  signal_A2VP41LZ1.b = var19.b;
  signal_A2VP41LZ1.error = var19.error;
  signal_B1VP41LZ1.b = var108.b;
  signal_B1VP41LZ1.error = var108.error;
  signal_A1VP41LZ1.b = var136.b;
  signal_A1VP41LZ1.error = var136.error;
  signal_A0VT71LZ1.b = var78.b;
  signal_A0VT71LZ1.error = var78.error;
  signal_A0VT61LZ1.b = var167.b;
  signal_A0VT61LZ1.error = var167.error;
  fplet(&signal_A0CT01IZ1.f,&var127.f);
  signal_A0CT01IZ1.error = var127.error;

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
ParExchange("A0IT01IZ1",2,&SignalBuffer[0],"Температура АЗ1-1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(16);
#else
ParExchange("B1VP81LZZ",3,&SignalBuffer[16],"Давление СБРОС ББ2 в норме",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(18);
#else
ParExchange("A1VP81LZZ",3,&SignalBuffer[18],"Давление СБРОС ББ1 в норме",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(42);
#else
ParExchange("A2IP01IZ1",2,&SignalBuffer[42],"Текущее давление СБРОС РБ1",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(45);
#else
ParExchange("B2IP01IZ1",2,&SignalBuffer[45],"Текущее давление СБРОС РБ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(50);
#else
ParExchange("B0IT01IZ1",2,&SignalBuffer[50],"Температура АЗ2-1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(57);
#else
ParExchange("B0VP81LZZ",3,&SignalBuffer[57],"Давление АЗ2 в норме",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(59);
#else
ParExchange("A0VP81LZZ",3,&SignalBuffer[59],"Давление  АЗ1 в норме",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(73);
#else
ParExchange("R0VN02RS1",1,&SignalBuffer[73],"Уровень мощности канал 1",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(78);
#else
ParExchange("R0VN02RS2",1,&SignalBuffer[78],"Уровень мощности канал 2",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(83);
#else
ParExchange("R0VN02RS3",1,&SignalBuffer[83],"Уровень мощности канал 3",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(88);
#else
ParExchange("R0VN02RS4",1,&SignalBuffer[88],"Уровень мощности канал 4",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(93);
#else
ParExchange("R0VN01RS1",1,&SignalBuffer[93],"Период разгона канал 1",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(98);
#else
ParExchange("R0VN01RS2",1,&SignalBuffer[98],"Период разгона канал 2",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(103);
#else
ParExchange("R0VN01RS3",1,&SignalBuffer[103],"Период разгона канал 3",0);
#endif
#ifndef SIMUL_MODE
  CheckSFloat(108);
#else
ParExchange("R0VN01RS4",1,&SignalBuffer[108],"Период разгона канал 4",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(113);
#else
ParExchange("R0VN61LS1",3,&SignalBuffer[113],"ПС по мощности канал 1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(115);
#else
ParExchange("R0VN61LS2",3,&SignalBuffer[115],"ПС по мощности канал 2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(117);
#else
ParExchange("R0VN61LS3",3,&SignalBuffer[117],"ПС по мощности канал 3",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(119);
#else
ParExchange("R0VN61LS4",3,&SignalBuffer[119],"ПС по мощности канал 4",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(121);
#else
ParExchange("R0VN65LS1",3,&SignalBuffer[121],"ПС по периоду разгона канал 1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(123);
#else
ParExchange("R0VN65LS2",3,&SignalBuffer[123],"ПС по периоду разгона  канал 2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(125);
#else
ParExchange("R0VN65LS3",3,&SignalBuffer[125],"ПС по периоду разгона канал 3",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(127);
#else
ParExchange("R0VN65LS4",3,&SignalBuffer[127],"ПС по периоду разгона канал 4",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(190);
#else
ParExchange("A3IS11LDU",3,&SignalBuffer[190],"Приход на ВУ ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(192);
#else
ParExchange("A3IS22LDU",3,&SignalBuffer[192],"Приход на НУП ИС1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(194);
#else
ParExchange("R0AD03LZ1",3,&SignalBuffer[194],"Имитация прихода на ВУ ИС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(196);
#else
ParExchange("B3IS11LDU",3,&SignalBuffer[196],"Приход на ВУ ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(202);
#else
ParExchange("R0AD05LZ1",3,&SignalBuffer[202],"Имитация ухода с НУП ИС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(208);
#else
ParExchange("B3IS22LDU",3,&SignalBuffer[208],"Приход на НУП ИС2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(225);
#else
ParExchange("A0EE01LS1",3,&SignalBuffer[225],"Исправность АКНП канал 1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(227);
#else
ParExchange("A0EE01LS4",3,&SignalBuffer[227],"Исправность АКНП канал 4",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(229);
#else
ParExchange("A0EE01LS3",3,&SignalBuffer[229],"Исправность АКНП канал 3",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(239);
#else
ParExchange("A0EE01LS2",3,&SignalBuffer[239],"Исправность АКНП  канал 2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(241);
#else
ParExchange("A0EE05LZ1",3,&SignalBuffer[241],"Исправность сети АКНП1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(243);
#else
ParExchange("A0EE06LZ1",3,&SignalBuffer[243],"Исправность сети АКНП2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(245);
#else
ParExchange("A0EE07LZ1",3,&SignalBuffer[245],"Исправность сети АКНП3",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(247);
#else
ParExchange("A0EE08LZ1",3,&SignalBuffer[247],"Исправность сети АКНП4",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(265);
#else
ParExchange("R0EE02LDU",3,&SignalBuffer[265],"Питание  АКНП  отключить",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(288);
#else
ParExchange("A0VN71LS1",3,&SignalBuffer[288],"Блокировка автоматического подъёма ББ канал 1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(290);
#else
ParExchange("A0VN71LS2",3,&SignalBuffer[290],"Блокировка автоматического подъёма ББ канал 2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(292);
#else
ParExchange("A0VN71LS3",3,&SignalBuffer[292],"Блокировка автоматического подъёма ББ канал 3",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(294);
#else
ParExchange("A0VN71LS4",3,&SignalBuffer[294],"Блокировка автоматического подъёма ББ канал 4",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(302);
#else
ParExchange("R0VW13LDU",3,&SignalBuffer[302],"Индикация выбора АЗ1 или АЗ1+АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(304);
#else
ParExchange("R0VW23LDU",3,&SignalBuffer[304],"Индикация выбора АЗ2 или АЗ1+АЗ2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(306);
#else
ParExchange("R7II73LZ1",3,&SignalBuffer[306],"Сработала АС II УР РАД",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(308);
#else
ParExchange("R7II71LZ1",3,&SignalBuffer[308],"Сработала АС IУР РАД (датчик 1)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(310);
#else
ParExchange("R7II72LZ1",3,&SignalBuffer[310],"Сработала АС IУР РАД  (датчик 2)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(314);
#else
ParExchange("R0AD21LDU",3,&SignalBuffer[314],"Подключить защиту от II УР",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(316);
#else
ParExchange("R0AD14LDU",3,&SignalBuffer[316],"Имитация срабатывания верхней АС II УР",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(318);
#else
ParExchange("R0MD34LP1",3,&SignalBuffer[318],"Кнопка (Квитировать)",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(320);
#else
ParExchange("R0AD04LZ1",3,&SignalBuffer[320],"Имитация срабатывания верхней АС II УР",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(322);
#else
ParExchange("R0AD16LDU",3,&SignalBuffer[322],"Имитация срабатывания верхней АС I УР",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(326);
#else
ParExchange("R6IS66LZZ",3,&SignalBuffer[326],"Исправность ВИП 4,0 (№5) ССДИ-1-1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(328);
#else
ParExchange("R6IS67LZZ",3,&SignalBuffer[328],"Исправность ВИП 4,0 (№6) ССДИ-1-2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(330);
#else
ParExchange("R6IS68LZZ",3,&SignalBuffer[330],"Исправность ВИП 4,0 (№7) ССДИ-2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(332);
#else
ParExchange("R0VN71LZ1",3,&SignalBuffer[332],"АС по мощности канал 1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(334);
#else
ParExchange("R0VN75LZ1",3,&SignalBuffer[334],"АС по периоду разгона канал 1",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(336);
#else
ParExchange("R0VN72LZ1",3,&SignalBuffer[336],"АС по мощности канал 2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(338);
#else
ParExchange("R0VN76LZ1",3,&SignalBuffer[338],"АС по периоду разгона канал  2",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(340);
#else
ParExchange("R0VN73LZ1",3,&SignalBuffer[340],"АС по мощности канал 3",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(342);
#else
ParExchange("R0VN77LZ1",3,&SignalBuffer[342],"АС по периоду разгона канал  3",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(344);
#else
ParExchange("R0VN74LZ1",3,&SignalBuffer[344],"АС по мощности канал 4",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(346);
#else
ParExchange("R0VN78LZ1",3,&SignalBuffer[346],"АС по периоду разгона канал  4",0);
#endif
#ifndef SIMUL_MODE
  CheckSInt(358);
#else
ParExchange("R0MW12IP2",2,&SignalBuffer[358],"Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(361);
#else
ParExchange("A2IS12LDU",3,&SignalBuffer[361],"Магнит РБ1 зацеплен",0);
#endif
#ifndef SIMUL_MODE
  CheckSBool(363);
#else
ParExchange("B2IS12LDU",3,&SignalBuffer[363],"Магнит РБ2 зацеплен",0);
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
ParExchange("A0CT01IZ1",1,&SignalBuffer[3],"Температура АЗ1-1",1);
ParExchange("A0VT61LZ1",3,&SignalBuffer[8],"ПС по температуре в АЗ1",1);
ParExchange("A0VT71LZ1",3,&SignalBuffer[10],"АС по температуре в АЗ1",1);
ParExchange("A1VP41LZ1",3,&SignalBuffer[12],"Давление СБРОС ББ1 ниже АС",1);
ParExchange("B1VP41LZ1",3,&SignalBuffer[14],"Давление СБРОС ББ2 ниже АС",1);
ParExchange("A2VP41LZ1",3,&SignalBuffer[20],"Давление СБРОС РБ1 ниже АС",1);
ParExchange("A2CP01RZ1",1,&SignalBuffer[22],"Текущее давление СБРОС РБ1",1);
ParExchange("A2VP51LZ1",3,&SignalBuffer[27],"Давление СБРОС РБ1 ниже ПС",1);
ParExchange("B2VP41LZ1",3,&SignalBuffer[29],"Давление СБРОС РБ2 ниже АС",1);
ParExchange("B2CP01RZ1",1,&SignalBuffer[31],"Текущее давление СБРОС РБ2",1);
ParExchange("B2VP51LZ1",3,&SignalBuffer[36],"Давление СБРОС РБ2 ниже ПС",1);
ParExchange("B2VP81LZ1",3,&SignalBuffer[38],"Давление СБРОС РБ2 в норме",1);
ParExchange("A2VP81LZ1",3,&SignalBuffer[40],"Давление СБРОС РБ1 в норме",1);
ParExchange("R0ET01LZ1",3,&SignalBuffer[48],"Признак наличия неисправности по температуре  АЗ1",1);
ParExchange("A0VP41LZ1",3,&SignalBuffer[53],"Давление АЗ1 ниже АС",1);
ParExchange("B0VP41LZ1",3,&SignalBuffer[55],"Давление АЗ2 ниже АС",1);
ParExchange("R0ET02LZ1",3,&SignalBuffer[61],"Признак наличия неисправности по температуре АЗ2",1);
ParExchange("B0EP02IZ1",2,&SignalBuffer[63],"Индикатор -Давление  АЗ2 ниже АС",1);
ParExchange("A0EP02IZ1",2,&SignalBuffer[66],"Индикатор -Давление  АЗ1 ниже АС",1);
ParExchange("A0VP71LZ1",3,&SignalBuffer[69],"АЗ по АС любого давления для АЗ1",1);
ParExchange("B0VP71LZ1",3,&SignalBuffer[71],"АЗ по АС любого давления для АЗ2",1);
ParExchange("R0VN01RZ1",1,&SignalBuffer[129],"Уровень мощности по каналу 1",1);
ParExchange("R0VN02RZ1",1,&SignalBuffer[134],"Уровень мощности по каналу 2",1);
ParExchange("R0VN03RZ1",1,&SignalBuffer[139],"Уровень мощности по каналу 3",1);
ParExchange("R0VN04RZ1",1,&SignalBuffer[144],"Уровень мощности по каналу 4",1);
ParExchange("R0VN05RZ1",1,&SignalBuffer[149],"Период разгона по каналу 1",1);
ParExchange("R0VN06RZ1",1,&SignalBuffer[154],"Период разгона по каналу 2",1);
ParExchange("R0VN07RZ1",1,&SignalBuffer[159],"Период разгона по каналу 3",1);
ParExchange("R0VN08RZ1",1,&SignalBuffer[164],"Период разгона по каналу 4",1);
ParExchange("R0VN61LZ1",3,&SignalBuffer[169],"ПС по мощности канал 1",1);
ParExchange("R0VN62LZ1",3,&SignalBuffer[171],"ПС по мощности канал 2",1);
ParExchange("R0VN63LZ1",3,&SignalBuffer[173],"ПС по мощности канал 3",1);
ParExchange("R0VN64LZ1",3,&SignalBuffer[175],"ПС по мощности канал 4",1);
ParExchange("R0VN65LZ1",3,&SignalBuffer[177],"ПС по периоду разгона канал 1",1);
ParExchange("R0VN66LZ1",3,&SignalBuffer[179],"ПС по периоду разгона канал 2",1);
ParExchange("R0VN67LZ1",3,&SignalBuffer[181],"ПС по периоду разгона канал 3",1);
ParExchange("R0VN68LZ1",3,&SignalBuffer[183],"ПС по периоду разгона канал 4",1);
ParExchange("R0VN09RZ1",1,&SignalBuffer[185],"Усредненный период разгона",1);
ParExchange("A3VZ31LZ1",3,&SignalBuffer[198],"АЗ от ВУ ИС1",1);
ParExchange("B3VZ31LZ1",3,&SignalBuffer[200],"АЗ от ВУ ИС2",1);
ParExchange("A3VZ11LZ1",3,&SignalBuffer[204],"АЗ от НУП ИС1",1);
ParExchange("B3VZ11LZ1",3,&SignalBuffer[206],"АЗ от НУП ИС2",1);
ParExchange("R0VN69LZ1",3,&SignalBuffer[210],"ПС по усредненному периоду",1);
ParExchange("R0VN79LZ1",3,&SignalBuffer[212],"АС по усредненному периоду",1);
ParExchange("R0VR02RZ1",1,&SignalBuffer[214],"Усредненная реактивность",1);
ParExchange("R0VZ71LZ1",3,&SignalBuffer[219],"Обобщенный сигнал АЗ 1 канала",1);
ParExchange("R0VN70LZ1",3,&SignalBuffer[221],"АЗ по АС мощности РУ",1);
ParExchange("R0VN80LZ1",3,&SignalBuffer[223],"АЗ по АС периода разгона РУ",1);
ParExchange("A0EE01LZ1",3,&SignalBuffer[231],"Исправность АКНП1",1);
ParExchange("A0EE04LZ1",3,&SignalBuffer[233],"Исправность АКНП4",1);
ParExchange("A0EE02LZ1",3,&SignalBuffer[235],"Исправность АКНП2",1);
ParExchange("A0EE03LZ1",3,&SignalBuffer[237],"Исправность АКНП3",1);
ParExchange("A0VZ71LZ1",3,&SignalBuffer[249],"Обобщенный сигнал АС по АЗ1",1);
ParExchange("A0EE00LZ1",3,&SignalBuffer[251],"Исправность АКНП АЗ1",1);
ParExchange("B0EE00LZ1",3,&SignalBuffer[253],"Исправность АКНП АЗ2",1);
ParExchange("B0VZ71LZ1",3,&SignalBuffer[255],"Обобщенный сигнал АС по АЗ2",1);
ParExchange("A0VN71LZ1",3,&SignalBuffer[257],"АЗ по АС мощности  АЗ1",1);
ParExchange("B0VN71LZ1",3,&SignalBuffer[259],"АЗ по АС мощности  АЗ2",1);
ParExchange("A0VN81LZ1",3,&SignalBuffer[261],"АЗ по АС периода разгона АЗ1",1);
ParExchange("B0VN81LZ1",3,&SignalBuffer[263],"АЗ по АС периода разгона АЗ2",1);
ParExchange("R0VZ05UZ1",7,&SignalBuffer[267],"Индикатор причины сброса",1);
ParExchange("R0VN11RZ1",1,&SignalBuffer[272],"Средняя мощность по БАЗ1",1);
ParExchange("R0VP73LZ1",3,&SignalBuffer[277],"ПС давления для РУ",1);
ParExchange("B0CT01IZ1",1,&SignalBuffer[279],"Температура АЗ2-1",1);
ParExchange("B0VT61LZ1",3,&SignalBuffer[284],"ПС по температуре в АЗ2",1);
ParExchange("B0VT71LZ1",3,&SignalBuffer[286],"АС по температуре в АЗ2",1);
ParExchange("A1VN71LZ1",3,&SignalBuffer[296],"Блокировка автоматического подъёма ББ",1);
ParExchange("A3VZ15LZ1",3,&SignalBuffer[298],"Имитация АЗ от НУП ИС",1);
ParExchange("A3VZ13LZ1",3,&SignalBuffer[300],"Имитация АЗ от ВУ ИС",1);
ParExchange("R0AD14LZ1",3,&SignalBuffer[312],"Имитация АЗ от IIУР",1);
ParExchange("R0EE01LZ1",3,&SignalBuffer[324],"Питание  АКНП1  отключить",1);
ParExchange("R0EE02LZ1",3,&SignalBuffer[348],"Питание  АКНП2  отключить",1);
ParExchange("R0EE03LZ1",3,&SignalBuffer[350],"Питание  АКНП3  отключить",1);
ParExchange("R0EE04LZ1",3,&SignalBuffer[352],"Питание  АКНП4  отключить",1);
ParExchange("R0AD15LZ1",3,&SignalBuffer[354],"Имитация АЗ от 1УР (датчик1)",1);
ParExchange("R0AD16LZ1",3,&SignalBuffer[356],"Имитация АЗ от 1УР (датчик2)",1);
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
NewEEPROM("fEM_R0UT02RZZ",1,&fEM_R0UT02RZZ,"Верхний предел шкалы датчика температуры","600");
NewEEPROM("fEM_R0UT01RZZ",1,&fEM_R0UT01RZZ,"Нижний предел шкалы датчика температуры","0");
NewEEPROM("fEM_A2UP03RZZ",1,&fEM_A2UP03RZZ,"Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ","1.6");
NewEEPROM("fEM_A2UP04RZZ",1,&fEM_A2UP04RZZ,"Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ","0");
NewEEPROM("fEM_R0UT72RZZ",1,&fEM_R0UT72RZZ,"Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)","150");
NewEEPROM("fEM_R0UT71RZZ",1,&fEM_R0UT71RZZ,"Уровень срабатывания аварийной сигнализации по температуре АЗ","200");
NewEEPROM("fEM_R0UT62RZZ",1,&fEM_R0UT62RZZ,"Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)","90");
NewEEPROM("fEM_R0UT61RZZ",1,&fEM_R0UT61RZZ,"Уровень срабатывания предупредительной сигнализации по температуре АЗ","100");
NewEEPROM("fEM_A2UP41RZZ",1,&fEM_A2UP41RZZ,"Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ","0.1");
NewEEPROM("fEM_A2UP42RZZ",1,&fEM_A2UP42RZZ,"Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)","0.13");
NewEEPROM("fEM_A2UP51RZZ",1,&fEM_A2UP51RZZ,"Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)","0.16");
NewEEPROM("fEM_A2UP81RZZ",1,&fEM_A2UP81RZZ,"Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)","0.17");
NewEEPROM("fEM_A2UP84RZZ",1,&fEM_A2UP84RZZ,"Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)","0.31");
NewEEPROM("fEM_A2UP82RZZ",1,&fEM_A2UP82RZZ,"Нижняя граница нормализации давления СБРОС РБ (МПа)","0.2");
NewEEPROM("fEM_A2UP52RZZ",1,&fEM_A2UP52RZZ,"Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)","0.19");
NewEEPROM("fEM_A2UP83RZZ",1,&fEM_A2UP83RZZ,"Верхняя граница нормализации давления СБРОС РБ (МПа)","0.28");
NewEEPROM("fEM_R0UR01RZZ",1,&fEM_R0UR01RZZ,"Уставка АКНП ПС  АЗ по периоду (сек)","15");
NewEEPROM("fEM_R0UR04RZZ",1,&fEM_R0UR04RZZ,"Уставка АКНП АС  АЗ по периоду (сек)","10");
NewEEPROM("fEM_A1UL12RZZ",1,&fEM_A1UL12RZZ,"Время задержки АЗ от НУ ИС(сек)","0.180");
NewEEPROM("fEM_A1UL11RZZ",1,&fEM_A1UL11RZZ,"Время задержки АЗ от ВУ ИС сек","0.020");
NewEEPROM("fEM_R7UI73RZZ",1,&fEM_R7UI73RZZ,"Время задержки  срабатывания АС II УР","0.045");
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
  S_ma_188_1.r = &signal_R0MW12IP2;
  S_noto_220_1.x = &signal_R0AD03LZ1;
  S_noto_214_1.x = &signal_R0AD05LZ1;
  S_and2_215_1.x2 = &signal_R0VW23LDU;
  S_and2_213_1.x2 = &signal_R0VW13LDU;
  S_and3_207_1.x3 = &signal_R0AD05LZ1;
  S_and3_212_1.x3 = &signal_R0AD03LZ1;
  S_and2_216_1.x2 = &signal_R0VW13LDU;
  S_and2_217_1.x1 = &signal_R0VW23LDU;
  S_zzfs_244_1.x = &signal_R0AD14LDU;
  S_and2_80_1.x1 = &signal_A0EE05LZ1;
  S_and2_80_1.x2 = &signal_A0EE01LS1;
  S_and2_82_1.x1 = &signal_A0EE06LZ1;
  S_and2_82_1.x2 = &signal_A0EE01LS2;
  S_and2_84_1.x1 = &signal_A0EE07LZ1;
  S_and2_84_1.x2 = &signal_A0EE01LS3;
  S_and2_86_1.x1 = &signal_A0EE08LZ1;
  S_and2_86_1.x2 = &signal_A0EE01LS4;
  S_or2_255_1.x2 = &signal_R7II73LZ1;
  S_or2_257_1.x1 = &signal_R0AD21LDU;
  S_or2_257_1.x2 = &signal_R0AD14LDU;
  S_or2_249_1.x1 = &signal_R7II71LZ1;
  S_or2_243_1.x2 = &signal_R7II72LZ1;
  S_or2_199_1.x1 = &signal_A3IS22LDU;
  S_or2_199_1.x2 = &signal_R0AD05LZ1;
  S_or2_201_1.x1 = &signal_B3IS22LDU;
  S_or2_201_1.x2 = &signal_R0AD05LZ1;
  S_or2_202_1.x2 = &signal_R0AD03LZ1;
  S_or2_204_1.x2 = &signal_R0AD03LZ1;
  S_schl24_332_1.x1 = &signal_A0VN71LS2;
  S_schl24_332_1.x2 = &signal_A0VN71LS1;
  S_schl24_332_1.x3 = &signal_A0VN71LS4;
  S_schl24_332_1.x4 = &signal_A0VN71LS3;
  S_or2_299_1.x1 = &signal_R0VN75LZ1;
  S_or2_300_1.x1 = &signal_R0VN77LZ1;
  S_or2_302_1.x1 = &signal_R0VN78LZ1;
  S_or2_301_1.x1 = &signal_R0VN76LZ1;
  S_or2_265_1.x1 = &signal_R0VN72LZ1;
  S_or2_266_1.x1 = &signal_R0VN74LZ1;
  S_or2_264_1.x1 = &signal_R0VN73LZ1;
  S_or2_263_1.x1 = &signal_R0VN71LZ1;
  S_or2_35_1.x1 = &signal_B2IS12LDU;
  S_or2_35_1.x2 = &signal_A2IS12LDU;
  S_and2_189_1.x1 = &signal_R0AD14LDU;
  S_and2_189_1.x2 = &signal_R7II72LZ1;
  S_and2_185_1.x1 = &signal_R0AD14LDU;
  S_and2_185_1.x2 = &signal_R7II71LZ1;
  S_and2_182_1.x1 = &signal_R0AD14LDU;
  S_and2_182_1.x2 = &signal_R7II73LZ1;
  S_noto_248_1.x = &signal_R6IS67LZZ;
  S_noto_254_1.x = &signal_R6IS68LZZ;
  S_noto_237_1.x = &signal_R6IS66LZZ;
  S_noto_129_1.x = &signal_B0VP81LZZ;
  S_noto_128_1.x = &signal_A0VP81LZZ;
  S_noto_96_1.x = &signal_B1VP81LZZ;
  S_noto_25_1.x = &signal_R0EE02LDU;
  S_noto_325_1.x = &signal_R0AD16LDU;
  S_noto_324_1.x = &signal_R0AD04LZ1;
  S_noto_198_1.x = &signal_B3IS11LDU;
  S_noto_197_1.x = &signal_A3IS11LDU;
  S_noto_225_1.x = &signal_R0VW23LDU;
  S_noto_224_1.x = &signal_R0VW13LDU;
  S_noto_219_1.x = &signal_R0VW23LDU;
  S_noto_218_1.x = &signal_R0VW13LDU;
  S_scalzz_143_1.x = &signal_B0IT01IZ1;
  S_scalzz_141_1.x = &signal_A0IT01IZ1;
  S_scalzz_93_1.x = &signal_B2IP01IZ1;
  S_scalzz_91_1.x = &signal_A2IP01IZ1;
  S_noto_95_1.x = &signal_A1VP81LZZ;
  S_rsu_308_1.r = &signal_R0MD34LP1;
  S_noto_271_1.x = &signal_A0EE01LS4;
  S_noto_275_1.x = &signal_A0EE01LS2;
  S_noto_274_1.x = &signal_A0EE01LS3;
  S_noto_268_1.x = &signal_A0EE01LS1;
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
  S_zpfs_252_1.tx = &internal1_m252_tx;
  S_zpfs_252_1.y0 = &internal1_m252_y0;
  S_zpfs_315_1.tx = &internal1_m315_tx;
  S_zpfs_315_1.y0 = &internal1_m315_y0;
  S_zpfs_211_1.tx = &internal1_m211_tx;
  S_zpfs_211_1.y0 = &internal1_m211_y0;
  S_zpfs_210_1.tx = &internal1_m210_tx;
  S_zpfs_210_1.y0 = &internal1_m210_y0;
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
  S_tprg_130_1.y0 = &internal1_m130_y0;
  S_tprg_123_1.y0 = &internal1_m123_y0;
  S_drg_106_1.y1 = &internal1_m106_y1;
  S_drg_116_1.y1 = &internal1_m116_y1;
  S_drg_97_1.y1 = &internal1_m97_y1;
  S_drg_104_1.y1 = &internal1_m104_y1;
  S_drg_153_1.y1 = &internal1_m153_y1;
  S_drg_163_1.y1 = &internal1_m163_y1;
  S_zpfs_252_1.tz = &fEM_R7UI73RZZ;
  S_zpfs_211_1.tz = &fEM_A1UL11RZZ;
  S_zpfs_210_1.tz = &fEM_A1UL11RZZ;
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
  S_tprg_130_1.e = &fEM_A2UP81RZZ;
  S_tprg_130_1.f = &fEM_A2UP82RZZ;
  S_tprg_130_1.c = &fEM_A2UP83RZZ;
  S_tprg_130_1.d = &fEM_A2UP84RZZ;
  S_tprg_123_1.e = &fEM_A2UP81RZZ;
  S_tprg_123_1.f = &fEM_A2UP82RZZ;
  S_tprg_123_1.c = &fEM_A2UP83RZZ;
  S_tprg_123_1.d = &fEM_A2UP84RZZ;
  S_drg_106_1.e = &fEM_A2UP41RZZ;
  S_drg_106_1.f = &fEM_A2UP42RZZ;
  S_drg_116_1.e = &fEM_A2UP51RZZ;
  S_drg_116_1.f = &fEM_A2UP52RZZ;
  S_drg_97_1.e = &fEM_A2UP41RZZ;
  S_drg_97_1.f = &fEM_A2UP42RZZ;
  S_drg_104_1.e = &fEM_A2UP51RZZ;
  S_drg_104_1.f = &fEM_A2UP52RZZ;
  S_drg_153_1.e = &fEM_R0UT72RZZ;
  S_drg_153_1.f = &fEM_R0UT71RZZ;
  S_drg_163_1.e = &fEM_R0UT62RZZ;
  S_drg_163_1.f = &fEM_R0UT61RZZ;
}
