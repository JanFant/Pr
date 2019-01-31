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
#define internal1_m2088_q0 (*((psbool)(InternalBuf+0x50))) /*q0 - внутренний параметр*/
#define internal1_m2072_q0 (*((psbool)(InternalBuf+0x52))) /*q0 - внутренний параметр*/
#define internal1_m2114_q0 (*((psbool)(InternalBuf+0x54))) /*q0 - внутренний параметр*/
#define internal1_m2098_q0 (*((psbool)(InternalBuf+0x56))) /*q0 - внутренний параметр*/
#define internal1_m2091_q0 (*((psbool)(InternalBuf+0x58))) /*q0 - внутренний параметр*/
#define internal1_m2074_q0 (*((psbool)(InternalBuf+0x5A))) /*q0 - внутренний параметр*/
#define internal1_m2090_q0 (*((psbool)(InternalBuf+0x5C))) /*q0 - внутренний параметр*/
#define internal1_m2073_q0 (*((psbool)(InternalBuf+0x5E))) /*q0 - внутренний параметр*/
#define internal1_m2071_q0 (*((psbool)(InternalBuf+0x60))) /*q0 - внутренний параметр*/
#define internal1_m2070_q0 (*((psbool)(InternalBuf+0x62))) /*q0 - внутренний параметр*/
#define internal1_m2084_q0 (*((psbool)(InternalBuf+0x64))) /*q0 - внутренний параметр*/
#define internal1_m2082_q0 (*((psbool)(InternalBuf+0x66))) /*q0 - внутренний параметр*/
#define internal1_m2089_q0 (*((psbool)(InternalBuf+0x68))) /*q0 - внутренний параметр*/
#define internal1_m2086_q0 (*((psbool)(InternalBuf+0x6A))) /*q0 - внутренний параметр*/
#define internal1_m2117_q0 (*((psbool)(InternalBuf+0x6C))) /*q0 - внутренний параметр*/
#define internal1_m2100_q0 (*((psbool)(InternalBuf+0x6E))) /*q0 - внутренний параметр*/
#define internal1_m2116_q0 (*((psbool)(InternalBuf+0x70))) /*q0 - внутренний параметр*/
#define internal1_m2099_q0 (*((psbool)(InternalBuf+0x72))) /*q0 - внутренний параметр*/
#define internal1_m2097_q0 (*((psbool)(InternalBuf+0x74))) /*q0 - внутренний параметр*/
#define internal1_m2096_q0 (*((psbool)(InternalBuf+0x76))) /*q0 - внутренний параметр*/
#define internal1_m2110_q0 (*((psbool)(InternalBuf+0x78))) /*q0 - внутренний параметр*/
#define internal1_m2108_q0 (*((psbool)(InternalBuf+0x7A))) /*q0 - внутренний параметр*/
#define internal1_m1991_tx (*((psfloat)(InternalBuf+0x7C))) /*tx - внутренний параметр*/
#define internal1_m1970_tx (*((psfloat)(InternalBuf+0x81))) /*tx - внутренний параметр*/
#define internal1_m1683_Pv0 (*((psbool)(InternalBuf+0x86))) /* - Пер. выключатель механизма*/
#define internal1_m1683_Zv0 (*((psbool)(InternalBuf+0x88))) /* - Зад. выключатель механизма*/
#define internal1_m1683_MyFirstEnterFlag (*((psbool)(InternalBuf+0x8A))) /*MyFirstEnterFlag*/
#define internal1_m1680_Pv0 (*((psbool)(InternalBuf+0x8C))) /* - Пер. выключатель механизма*/
#define internal1_m1680_Zv0 (*((psbool)(InternalBuf+0x8E))) /* - Зад. выключатель механизма*/
#define internal1_m1680_MyFirstEnterFlag (*((psbool)(InternalBuf+0x90))) /*MyFirstEnterFlag*/
#define internal1_m2133_tx (*((psfloat)(InternalBuf+0x92))) /*tx - время накопленное сек*/
#define internal1_m2133_y0 (*((pschar)(InternalBuf+0x97))) /*y0*/
#define internal1_m2137_tx (*((psfloat)(InternalBuf+0x99))) /*tx - время накопленное сек*/
#define internal1_m2137_y0 (*((pschar)(InternalBuf+0x9E))) /*y0*/
#define internal1_m2136_tx (*((psfloat)(InternalBuf+0xA0))) /*tx - время накопленное сек*/
#define internal1_m2136_y0 (*((pschar)(InternalBuf+0xA5))) /*y0*/
#define internal1_m2173_tx (*((psfloat)(InternalBuf+0xA7))) /*tx - внутренний параметр*/
#define internal1_m2171_tx (*((psfloat)(InternalBuf+0xAC))) /*tx - время накопленное сек*/
#define internal1_m2171_y0 (*((pschar)(InternalBuf+0xB1))) /*y0*/
#define internal1_m2176_q0 (*((psbool)(InternalBuf+0xB3))) /*q0 - внутренний параметр*/
#define internal1_m2143_q0 (*((psbool)(InternalBuf+0xB5))) /*q0 - внутренний параметр*/
#define internal1_m2151_tx (*((psfloat)(InternalBuf+0xB7))) /*tx - внутренний параметр*/
#define internal1_m2149_q0 (*((psbool)(InternalBuf+0xBC))) /*q0 - внутренний параметр*/
#define internal1_m1985_tx (*((psfloat)(InternalBuf+0xBE))) /*tx - время накопленное сек*/
#define internal1_m1985_y0 (*((pschar)(InternalBuf+0xC3))) /*y0*/
#define internal1_m1977_tx (*((psfloat)(InternalBuf+0xC5))) /*tx - время накопленное сек*/
#define internal1_m1977_y0 (*((pschar)(InternalBuf+0xCA))) /*y0*/
#define internal1_m1676_q0 (*((psbool)(InternalBuf+0xCC))) /*q0 - внутренний параметр*/
#define internal1_m1674_q0 (*((psbool)(InternalBuf+0xCE))) /*q0 - внутренний параметр*/
#define internal1_m1673_q0 (*((psbool)(InternalBuf+0xD0))) /*q0 - внутренний параметр*/
#define internal1_m1704_q0 (*((psbool)(InternalBuf+0xD2))) /*q0 - внутренний параметр*/
#define internal1_m733_tx (*((psfloat)(InternalBuf+0xD4))) /*tx - время накопленное сек*/
#define internal1_m733_y0 (*((pschar)(InternalBuf+0xD9))) /*y0*/
#define internal1_m1981_tx (*((psfloat)(InternalBuf+0xDB))) /*tx - внутренний параметр*/
#define internal1_m1984_q0 (*((psbool)(InternalBuf+0xE0))) /*q0 - внутренний параметр*/
#define internal1_m1976_q0 (*((psbool)(InternalBuf+0xE2))) /*q0 - внутренний параметр*/
#define internal1_m1946_tx (*((psfloat)(InternalBuf+0xE4))) /*tx - внутренний параметр*/
#define internal1_m1957_tx (*((psfloat)(InternalBuf+0xE9))) /*tx - внутренний параметр*/
#define internal1_m1943_tx (*((psfloat)(InternalBuf+0xEE))) /*tx - внутренний параметр*/
#define internal1_m1949_q0 (*((psbool)(InternalBuf+0xF3))) /*q0 - внутренний параметр*/
#define internal1_m1961_q0 (*((psbool)(InternalBuf+0xF5))) /*q0 - внутренний параметр*/
#define internal1_m1919_tx (*((psfloat)(InternalBuf+0xF7))) /*tx - внутренний параметр*/
#define internal1_m51_tx (*((psfloat)(InternalBuf+0xFC))) /*tx - внутренний параметр*/
#define internal1_m332_tx (*((psfloat)(InternalBuf+0x101))) /*tx - внутренний параметр*/
#define internal1_m288_tx (*((psfloat)(InternalBuf+0x106))) /*tx - внутренний параметр*/
#define internal1_m734_tx (*((psfloat)(InternalBuf+0x10B))) /*tx - внутренний параметр*/
#define internal1_m1399_tx (*((psfloat)(InternalBuf+0x110))) /*tx - внутренний параметр*/
#define internal1_m110_tx (*((psfloat)(InternalBuf+0x115))) /*tx - внутренний параметр*/
#define internal1_m112_tx (*((psfloat)(InternalBuf+0x11A))) /*tx - внутренний параметр*/
#define internal1_m117_tx (*((psfloat)(InternalBuf+0x11F))) /*tx - внутренний параметр*/
#define internal1_m21_tx (*((psfloat)(InternalBuf+0x124))) /*tx - внутренний параметр*/
#define internal1_m13_tx (*((psfloat)(InternalBuf+0x129))) /*tx - внутренний параметр*/
#define internal1_m1928_tx (*((psfloat)(InternalBuf+0x12E))) /*tx - внутренний параметр*/
#define internal1_m1916_tx (*((psfloat)(InternalBuf+0x133))) /*tx - внутренний параметр*/
#define internal1_m2024_tx (*((psfloat)(InternalBuf+0x138))) /*tx - внутренний параметр*/
#define internal1_m2028_tx (*((psfloat)(InternalBuf+0x13D))) /*tx - внутренний параметр*/
#define internal1_m1841_tx (*((psfloat)(InternalBuf+0x142))) /*tx - внутренний параметр*/
#define internal1_m76_tx (*((psfloat)(InternalBuf+0x147))) /*tx - внутренний параметр*/
#define internal1_m301_tx (*((psfloat)(InternalBuf+0x14C))) /*tx - время накопленное сек*/
#define internal1_m301_y0 (*((pschar)(InternalBuf+0x151))) /*y0*/
#define internal1_m1835_tx (*((psfloat)(InternalBuf+0x153))) /*tx - время накопленное сек*/
#define internal1_m1835_y0 (*((pschar)(InternalBuf+0x158))) /*y0*/
#define internal1_m1833_tx (*((psfloat)(InternalBuf+0x15A))) /*tx - время накопленное сек*/
#define internal1_m1833_y0 (*((pschar)(InternalBuf+0x15F))) /*y0*/
#define internal1_m1822_tx (*((psfloat)(InternalBuf+0x161))) /*tx - время накопленное сек*/
#define internal1_m1822_y0 (*((pschar)(InternalBuf+0x166))) /*y0*/
#define internal1_m1842_q0 (*((psfloat)(InternalBuf+0x168))) /*q0 - внутренний параметр*/
#define internal1_m1419_q0 (*((psfloat)(InternalBuf+0x16D))) /*q0 - внутренний параметр*/
#define internal1_m1457_q0 (*((psfloat)(InternalBuf+0x172))) /*q0 - внутренний параметр*/
#define internal1_m1460_q0 (*((psfloat)(InternalBuf+0x177))) /*q0 - внутренний параметр*/
#define internal1_m1881_q0 (*((psfloat)(InternalBuf+0x17C))) /*q0 - внутренний параметр*/
#define internal1_m1859_tx (*((psfloat)(InternalBuf+0x181))) /*tx - время накопленное сек*/
#define internal1_m1859_y0 (*((pschar)(InternalBuf+0x186))) /*y0*/
#define internal1_m1874_tx (*((psfloat)(InternalBuf+0x188))) /*tx - время накопленное сек*/
#define internal1_m1874_y0 (*((pschar)(InternalBuf+0x18D))) /*y0*/
#define internal1_m1871_tx (*((psfloat)(InternalBuf+0x18F))) /*tx - время накопленное сек*/
#define internal1_m1871_y0 (*((pschar)(InternalBuf+0x194))) /*y0*/
#define internal1_m2008_tx (*((psfloat)(InternalBuf+0x196))) /*tx - время накопленное сек*/
#define internal1_m2008_y0 (*((pschar)(InternalBuf+0x19B))) /*y0*/
#define internal1_m2018_tx (*((psfloat)(InternalBuf+0x19D))) /*tx - время накопленное сек*/
#define internal1_m2018_y0 (*((pschar)(InternalBuf+0x1A2))) /*y0*/
#define internal1_m1772_tx (*((psfloat)(InternalBuf+0x1A4))) /*tx - время накопленное сек*/
#define internal1_m1772_y0 (*((pschar)(InternalBuf+0x1A9))) /*y0*/
#define internal1_m1771_tx (*((psfloat)(InternalBuf+0x1AB))) /*tx - время накопленное сек*/
#define internal1_m1771_y0 (*((pschar)(InternalBuf+0x1B0))) /*y0*/
#define internal1_m1770_tx (*((psfloat)(InternalBuf+0x1B2))) /*tx - время накопленное сек*/
#define internal1_m1770_y0 (*((pschar)(InternalBuf+0x1B7))) /*y0*/
#define internal1_m1769_tx (*((psfloat)(InternalBuf+0x1B9))) /*tx - время накопленное сек*/
#define internal1_m1769_y0 (*((pschar)(InternalBuf+0x1BE))) /*y0*/
#define internal1_m1471_tx (*((psfloat)(InternalBuf+0x1C0))) /*tx - время накопленное сек*/
#define internal1_m1471_y0 (*((pschar)(InternalBuf+0x1C5))) /*y0*/
#define internal1_m1465_tx (*((psfloat)(InternalBuf+0x1C7))) /*tx - время накопленное сек*/
#define internal1_m1465_y0 (*((pschar)(InternalBuf+0x1CC))) /*y0*/
#define internal1_m1415_tx (*((psfloat)(InternalBuf+0x1CE))) /*tx - время накопленное сек*/
#define internal1_m1415_y0 (*((pschar)(InternalBuf+0x1D3))) /*y0*/
#define internal1_m817_tx (*((psfloat)(InternalBuf+0x1D5))) /*tx - время накопленное сек*/
#define internal1_m817_y0 (*((pschar)(InternalBuf+0x1DA))) /*y0*/
#define internal1_m814_tx (*((psfloat)(InternalBuf+0x1DC))) /*tx - время накопленное сек*/
#define internal1_m814_y0 (*((pschar)(InternalBuf+0x1E1))) /*y0*/
#define internal1_m821_tx (*((psfloat)(InternalBuf+0x1E3))) /*tx - время накопленное сек*/
#define internal1_m821_y0 (*((pschar)(InternalBuf+0x1E8))) /*y0*/
#define internal1_m182_tx (*((psfloat)(InternalBuf+0x1EA))) /*tx - время накопленное сек*/
#define internal1_m182_y0 (*((pschar)(InternalBuf+0x1EF))) /*y0*/
#define internal1_m187_tx (*((psfloat)(InternalBuf+0x1F1))) /*tx - время накопленное сек*/
#define internal1_m187_y0 (*((pschar)(InternalBuf+0x1F6))) /*y0*/
#define internal1_m193_tx (*((psfloat)(InternalBuf+0x1F8))) /*tx - время накопленное сек*/
#define internal1_m193_y0 (*((pschar)(InternalBuf+0x1FD))) /*y0*/
#define internal1_m512_tx (*((psfloat)(InternalBuf+0x1FF))) /*tx - время накопленное сек*/
#define internal1_m512_y0 (*((pschar)(InternalBuf+0x204))) /*y0*/
#define internal1_m2056_tx (*((psfloat)(InternalBuf+0x206))) /*tx - внутренний параметр*/
#define internal1_m1159_tx (*((psfloat)(InternalBuf+0x20B))) /*tx - внутренний параметр*/
#define internal1_m1585_tx (*((psfloat)(InternalBuf+0x210))) /*tx - время накопленное сек*/
#define internal1_m1585_y0 (*((pschar)(InternalBuf+0x215))) /*y0*/
#define internal1_m1125_tx (*((psfloat)(InternalBuf+0x217))) /*tx - время накопленное сек*/
#define internal1_m1125_y0 (*((pschar)(InternalBuf+0x21C))) /*y0*/
#define internal1_m1311_tx (*((psfloat)(InternalBuf+0x21E))) /*tx - время накопленное сек*/
#define internal1_m1311_y0 (*((pschar)(InternalBuf+0x223))) /*y0*/
#define internal1_m914_tx (*((psfloat)(InternalBuf+0x225))) /*tx - время накопленное сек*/
#define internal1_m914_y0 (*((pschar)(InternalBuf+0x22A))) /*y0*/
#define internal1_m1220_tx (*((psfloat)(InternalBuf+0x22C))) /*tx - время накопленное сек*/
#define internal1_m1220_y0 (*((pschar)(InternalBuf+0x231))) /*y0*/
#define internal1_m1066_q0 (*((psbool)(InternalBuf+0x233))) /*q0 - внутренний параметр*/
#define internal1_m1064_q0 (*((psbool)(InternalBuf+0x235))) /*q0 - внутренний параметр*/
#define internal1_m1063_q0 (*((psbool)(InternalBuf+0x237))) /*q0 - внутренний параметр*/
#define internal1_m1061_q0 (*((psbool)(InternalBuf+0x239))) /*q0 - внутренний параметр*/
#define internal1_m1060_q0 (*((psbool)(InternalBuf+0x23B))) /*q0 - внутренний параметр*/
#define internal1_m1058_q0 (*((psbool)(InternalBuf+0x23D))) /*q0 - внутренний параметр*/
#define internal1_m1057_q0 (*((psbool)(InternalBuf+0x23F))) /*q0 - внутренний параметр*/
#define internal1_m1055_q0 (*((psbool)(InternalBuf+0x241))) /*q0 - внутренний параметр*/
#define internal1_m1054_q0 (*((psbool)(InternalBuf+0x243))) /*q0 - внутренний параметр*/
#define internal1_m52_x0 (*((psbool)(InternalBuf+0x245))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m974_q0 (*((psbool)(InternalBuf+0x247))) /*q0 - внутренний параметр*/
#define internal1_m1408_x0 (*((psbool)(InternalBuf+0x249))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m1452_x0 (*((psbool)(InternalBuf+0x24B))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m1448_x0 (*((psbool)(InternalBuf+0x24D))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m1850_x0 (*((psbool)(InternalBuf+0x24F))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m1815_x0 (*((psbool)(InternalBuf+0x251))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m1013_q0 (*((psbool)(InternalBuf+0x253))) /*q0 - внутренний параметр*/
#define internal1_m1025_q0 (*((psbool)(InternalBuf+0x255))) /*q0 - внутренний параметр*/
#define internal1_m1037_q0 (*((psbool)(InternalBuf+0x257))) /*q0 - внутренний параметр*/
#define internal1_m1047_q0 (*((psbool)(InternalBuf+0x259))) /*q0 - внутренний параметр*/
#define internal1_m1024_q0 (*((psbool)(InternalBuf+0x25B))) /*q0 - внутренний параметр*/
#define internal1_m1039_q0 (*((psbool)(InternalBuf+0x25D))) /*q0 - внутренний параметр*/
#define internal1_m1908_q0 (*((psbool)(InternalBuf+0x25F))) /*q0 - внутренний параметр*/
#define internal1_m1907_q0 (*((psbool)(InternalBuf+0x261))) /*q0 - внутренний параметр*/
#define internal1_m320_Step (*((psint)(InternalBuf+0x263))) /* - текущий шаг программы*/
#define internal1_m320_rz (*((pschar)(InternalBuf+0x266))) /*- результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка*/
#define internal1_m320_TimS (*((psfloat)(InternalBuf+0x27A))) /*Время от старта программы*/
#define internal1_m320_FinPr0 (*((psbool)(InternalBuf+0x27F))) /*FinPr - конец программы*/
#define internal1_m320_ErrPr0 (*((psbool)(InternalBuf+0x281))) /*ErrPr - Приостановка программы по ошибке*/
#define internal1_m320_sbINI0 (*((psbool)(InternalBuf+0x283))) /*sbINI - запуск проверки ИНИ*/
#define internal1_m320_sbVuIS0 (*((psbool)(InternalBuf+0x285))) /*sbVuIS - запуск проверки сброса от ВУ ИС*/
#define internal1_m320_sb2UR0 (*((psbool)(InternalBuf+0x287))) /*sb2UR - запуск проверки сброса от 2УР*/
#define internal1_m320_sbNupIS0 (*((psbool)(InternalBuf+0x289))) /*sbNupIS - запуск проверки сброса от НУП ИС*/
#define internal1_m320_sbVuRB0 (*((psbool)(InternalBuf+0x28B))) /*sbVuRB - запуск проверки сброса от ВУ РБ*/
#define internal1_m320_MyFirstEnterFlag (*((psbool)(InternalBuf+0x28D))) /* */
#define internal1_m328_x0 (*((pslong)(InternalBuf+0x28F))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m287_TimS (*((pslong)(InternalBuf+0x294))) /*Время старта*/
#define internal1_m263_Step (*((psint)(InternalBuf+0x299))) /* - текущий шаг программы*/
#define internal1_m263_rz (*((pschar)(InternalBuf+0x29C))) /*- результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка*/
#define internal1_m263_TimS (*((psfloat)(InternalBuf+0x2B0))) /*Время от старта программы*/
#define internal1_m263_FinPr0 (*((psbool)(InternalBuf+0x2B5))) /*FinPr - конец программы*/
#define internal1_m263_ErrPr0 (*((psbool)(InternalBuf+0x2B7))) /*ErrPr - Приостановка программы по ошибке*/
#define internal1_m263_sbINI0 (*((psbool)(InternalBuf+0x2B9))) /*sbINI - запуск проверки ИНИ*/
#define internal1_m263_sbVuIS0 (*((psbool)(InternalBuf+0x2BB))) /*sbVuIS - запуск проверки сброса от ВУ ИС*/
#define internal1_m263_sb2UR0 (*((psbool)(InternalBuf+0x2BD))) /*sb2UR - запуск проверки сброса от 2УР*/
#define internal1_m263_sbNupIS0 (*((psbool)(InternalBuf+0x2BF))) /*sbNupIS - запуск проверки сброса от НУП ИС*/
#define internal1_m263_sbVuRB0 (*((psbool)(InternalBuf+0x2C1))) /*sbVuRB - запуск проверки сброса от ВУ РБ*/
#define internal1_m263_MyFirstEnterFlag (*((psbool)(InternalBuf+0x2C3))) /* */
#define internal1_m1382_q0 (*((psbool)(InternalBuf+0x2C5))) /*q0 - внутренний параметр*/
#define internal1_m1383_Step (*((psint)(InternalBuf+0x2C7))) /* - текущий шаг программы*/
#define internal1_m1383_rz (*((pschar)(InternalBuf+0x2CA))) /*- результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка*/
#define internal1_m1383_TimS (*((psfloat)(InternalBuf+0x2D6))) /*Время от старта программы*/
#define internal1_m1383_FinPr0 (*((psbool)(InternalBuf+0x2DB))) /*FinPr - конец программы*/
#define internal1_m1383_ErrPr0 (*((psbool)(InternalBuf+0x2DD))) /*ErrPr - Приостановка программы по ошибке*/
#define internal1_m1383_sbINI0 (*((psbool)(InternalBuf+0x2DF))) /*sbINI - запуск проверки ИНИ*/
#define internal1_m1383_sbVuIS0 (*((psbool)(InternalBuf+0x2E1))) /*sbVuIS - запуск проверки сброса от ВУ ИС*/
#define internal1_m1383_sb2UR0 (*((psbool)(InternalBuf+0x2E3))) /*sb2UR - запуск проверки сброса от 2УР*/
#define internal1_m1383_sbNupIS0 (*((psbool)(InternalBuf+0x2E5))) /*sbNupIS - запуск проверки сброса от НУП ИС*/
#define internal1_m1383_sbVuRB0 (*((psbool)(InternalBuf+0x2E7))) /*sbVuRB - запуск проверки сброса от ВУ РБ*/
#define internal1_m1383_MyFirstEnterFlag (*((psbool)(InternalBuf+0x2E9))) /* */
#define internal1_m1008_q0 (*((psbool)(InternalBuf+0x2EB))) /*q0 - внутренний параметр*/
#define internal1_m1005_q0 (*((psbool)(InternalBuf+0x2ED))) /*q0 - внутренний параметр*/
#define internal1_m1007_q0 (*((psbool)(InternalBuf+0x2EF))) /*q0 - внутренний параметр*/
#define internal1_m1002_q0 (*((psbool)(InternalBuf+0x2F1))) /*q0 - внутренний параметр*/
#define internal1_m735_q0 (*((psbool)(InternalBuf+0x2F3))) /*q0 - внутренний параметр*/
#define internal1_m330_q0 (*((psbool)(InternalBuf+0x2F5))) /*q0 - внутренний параметр*/
#define internal1_m326_q0 (*((psbool)(InternalBuf+0x2F7))) /*q0 - внутренний параметр*/
#define internal1_m283_q0 (*((psbool)(InternalBuf+0x2F9))) /*q0 - внутренний параметр*/
#define internal1_m282_x0 (*((pslong)(InternalBuf+0x2FB))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m1837_q0 (*((psbool)(InternalBuf+0x300))) /*q0 - внутренний параметр*/
#define internal1_m1825_q0 (*((psbool)(InternalBuf+0x302))) /*q0 - внутренний параметр*/
#define internal1_m1816_q0 (*((psbool)(InternalBuf+0x304))) /*q0 - внутренний параметр*/
#define internal1_m1891_q0 (*((psbool)(InternalBuf+0x306))) /*q0 - внутренний параметр*/
#define internal1_m1862_q0 (*((psbool)(InternalBuf+0x308))) /*q0 - внутренний параметр*/
#define internal1_m1851_q0 (*((psbool)(InternalBuf+0x30A))) /*q0 - внутренний параметр*/
#define internal1_m1435_q0 (*((psbool)(InternalBuf+0x30C))) /*q0 - внутренний параметр*/
#define internal1_m1422_x0 (*((psbool)(InternalBuf+0x30E))) /*был приход сигнала x1*/
#define internal1_m1422_y0 (*((psfloat)(InternalBuf+0x310))) /*интервал между сигналами х1 и х2*/
#define internal1_m1418_q0 (*((psbool)(InternalBuf+0x315))) /*q0 - внутренний параметр*/
#define internal1_m1409_q0 (*((psbool)(InternalBuf+0x317))) /*q0 - внутренний параметр*/
#define internal1_m1468_q0 (*((psbool)(InternalBuf+0x319))) /*q0 - внутренний параметр*/
#define internal1_m1488_q0 (*((psbool)(InternalBuf+0x31B))) /*q0 - внутренний параметр*/
#define internal1_m1454_q0 (*((psbool)(InternalBuf+0x31D))) /*q0 - внутренний параметр*/
#define internal1_m1469_x0 (*((psbool)(InternalBuf+0x31F))) /*был приход сигнала x1*/
#define internal1_m1469_y0 (*((psfloat)(InternalBuf+0x321))) /*интервал между сигналами х1 и х2*/
#define internal1_m1393_x0 (*((pslong)(InternalBuf+0x326))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m1474_q0 (*((psbool)(InternalBuf+0x32B))) /*q0 - внутренний параметр*/
#define internal1_m26_q0 (*((psbool)(InternalBuf+0x32D))) /*q0 - внутренний параметр*/
#define internal1_m1489_q0 (*((psbool)(InternalBuf+0x32F))) /*q0 - внутренний параметр*/
#define internal1_m627_q0 (*((psbool)(InternalBuf+0x331))) /*q0 - внутренний параметр*/
#define internal1_m612_q0 (*((psbool)(InternalBuf+0x333))) /*q0 - внутренний параметр*/
#define internal1_m639_q0 (*((psbool)(InternalBuf+0x335))) /*q0 - внутренний параметр*/
#define internal1_m623_q0 (*((psbool)(InternalBuf+0x337))) /*q0 - внутренний параметр*/
#define internal1_m607_q0 (*((psbool)(InternalBuf+0x339))) /*q0 - внутренний параметр*/
#define internal1_m605_q0 (*((psbool)(InternalBuf+0x33B))) /*q0 - внутренний параметр*/
#define internal1_m593_q0 (*((psbool)(InternalBuf+0x33D))) /*q0 - внутренний параметр*/
#define internal1_m1385_q0 (*((pslong)(InternalBuf+0x33F))) /*q0 - внутренний параметр*/
#define internal1_m603_q0 (*((psbool)(InternalBuf+0x344))) /*q0 - внутренний параметр*/
#define internal1_m106_q0 (*((psbool)(InternalBuf+0x346))) /*q0 - внутренний параметр*/
#define internal1_m1619_q0 (*((psbool)(InternalBuf+0x348))) /*q0 - внутренний параметр*/
#define internal1_m1618_q0 (*((psbool)(InternalBuf+0x34A))) /*q0 - внутренний параметр*/
#define internal1_m1617_q0 (*((psbool)(InternalBuf+0x34C))) /*q0 - внутренний параметр*/
#define internal1_m1616_q0 (*((psbool)(InternalBuf+0x34E))) /*q0 - внутренний параметр*/
#define internal1_m1645_q0 (*((psbool)(InternalBuf+0x350))) /*q0 - внутренний параметр*/
#define internal1_m1644_q0 (*((psbool)(InternalBuf+0x352))) /*q0 - внутренний параметр*/
#define internal1_m1643_q0 (*((psbool)(InternalBuf+0x354))) /*q0 - внутренний параметр*/
#define internal1_m1642_q0 (*((psbool)(InternalBuf+0x356))) /*q0 - внутренний параметр*/
#define internal1_m1922_q0 (*((psbool)(InternalBuf+0x358))) /*q0 - внутренний параметр*/
#define internal1_m1702_q0 (*((psbool)(InternalBuf+0x35A))) /*q0 - внутренний параметр*/
#define internal1_m1701_q0 (*((psbool)(InternalBuf+0x35C))) /*q0 - внутренний параметр*/
#define internal1_m1699_q0 (*((psbool)(InternalBuf+0x35E))) /*q0 - внутренний параметр*/
#define internal1_m1698_q0 (*((psbool)(InternalBuf+0x360))) /*q0 - внутренний параметр*/
#define internal1_m1696_q0 (*((psbool)(InternalBuf+0x362))) /*q0 - внутренний параметр*/
#define internal1_m2115_q0 (*((psbool)(InternalBuf+0x364))) /*q0 - внутренний параметр*/
#define internal1_m2112_q0 (*((psbool)(InternalBuf+0x366))) /*q0 - внутренний параметр*/
#define internal1_m1671_q0 (*((psbool)(InternalBuf+0x368))) /*q0 - внутренний параметр*/
#define internal1_m1665_q0 (*((psbool)(InternalBuf+0x36A))) /*q0 - внутренний параметр*/
#define internal1_m1664_q0 (*((psbool)(InternalBuf+0x36C))) /*q0 - внутренний параметр*/
#define internal1_m1660_q0 (*((psbool)(InternalBuf+0x36E))) /*q0 - внутренний параметр*/
#define internal1_m1662_q0 (*((psbool)(InternalBuf+0x370))) /*q0 - внутренний параметр*/
#define internal1_m1659_q0 (*((psbool)(InternalBuf+0x372))) /*q0 - внутренний параметр*/
#define internal1_m1658_q0 (*((psbool)(InternalBuf+0x374))) /*q0 - внутренний параметр*/
#define internal1_m1654_q0 (*((psbool)(InternalBuf+0x376))) /*q0 - внутренний параметр*/
#define internal1_m1656_q0 (*((psbool)(InternalBuf+0x378))) /*q0 - внутренний параметр*/
#define internal1_m19_q0 (*((psbool)(InternalBuf+0x37A))) /*q0 - внутренний параметр*/
#define internal1_m1639_q0 (*((psbool)(InternalBuf+0x37C))) /*q0 - внутренний параметр*/
#define internal1_m1637_q0 (*((psbool)(InternalBuf+0x37E))) /*q0 - внутренний параметр*/
#define internal1_m1634_q0 (*((psbool)(InternalBuf+0x380))) /*q0 - внутренний параметр*/
#define internal1_m1636_q0 (*((psbool)(InternalBuf+0x382))) /*q0 - внутренний параметр*/
#define internal1_m1633_q0 (*((psbool)(InternalBuf+0x384))) /*q0 - внутренний параметр*/
#define internal1_m1631_q0 (*((psbool)(InternalBuf+0x386))) /*q0 - внутренний параметр*/
#define internal1_m2038_q0 (*((psbool)(InternalBuf+0x388))) /*q0 - внутренний параметр*/
#define internal1_m2033_q0 (*((psbool)(InternalBuf+0x38A))) /*q0 - внутренний параметр*/
#define internal1_m2012_q0 (*((psbool)(InternalBuf+0x38C))) /*q0 - внутренний параметр*/
#define internal1_m2000_q0 (*((psbool)(InternalBuf+0x38E))) /*q0 - внутренний параметр*/
#define internal1_m1933_q0 (*((psbool)(InternalBuf+0x390))) /*q0 - внутренний параметр*/
#define internal1_m1628_q0 (*((psbool)(InternalBuf+0x392))) /*q0 - внутренний параметр*/
#define internal1_m1630_q0 (*((psbool)(InternalBuf+0x394))) /*q0 - внутренний параметр*/
#define internal1_m1615_q0 (*((psbool)(InternalBuf+0x396))) /*q0 - внутренний параметр*/
#define internal1_m1613_q0 (*((psbool)(InternalBuf+0x398))) /*q0 - внутренний параметр*/
#define internal1_m1612_q0 (*((psbool)(InternalBuf+0x39A))) /*q0 - внутренний параметр*/
#define internal1_m1610_q0 (*((psbool)(InternalBuf+0x39C))) /*q0 - внутренний параметр*/
#define internal1_m1609_q0 (*((psbool)(InternalBuf+0x39E))) /*q0 - внутренний параметр*/
#define internal1_m1607_q0 (*((psbool)(InternalBuf+0x3A0))) /*q0 - внутренний параметр*/
#define internal1_m1606_q0 (*((psbool)(InternalBuf+0x3A2))) /*q0 - внутренний параметр*/
#define internal1_m1604_q0 (*((psbool)(InternalBuf+0x3A4))) /*q0 - внутренний параметр*/
#define internal1_m2061_DvUp0 (*((pschar)(InternalBuf+0x3A6))) /*- есть команда на движение вперёд*/
#define internal1_m2061_DvDw0 (*((pschar)(InternalBuf+0x3A8))) /*- есть команда на движение назад*/
#define internal1_m2061_FDvUp0 (*((pschar)(InternalBuf+0x3AA))) /*- есть команда на движение вперёд*/
#define internal1_m2061_FDvDw0 (*((pschar)(InternalBuf+0x3AC))) /*- есть команда на движение назад*/
#define internal1_m2061_BlDv0 (*((pschar)(InternalBuf+0x3AE))) /*- была блокировка*/
#define internal1_m2061_Pkv0 (*((pschar)(InternalBuf+0x3B0))) /*Pkv - передний конечный выключатель*/
#define internal1_m2061_Pkav0 (*((pschar)(InternalBuf+0x3B2))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m2061_Zkv0 (*((pschar)(InternalBuf+0x3B4))) /*Zkv - задний конечный выключатель*/
#define internal1_m2061_Zkav0 (*((pschar)(InternalBuf+0x3B6))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m2061_txNm (*((psfloat)(InternalBuf+0x3B8))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m2061_txSm (*((psfloat)(InternalBuf+0x3BD))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m2061_txHr (*((psfloat)(InternalBuf+0x3C2))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m2061_txLd (*((psfloat)(InternalBuf+0x3C7))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m2061_fef (*((pschar)(InternalBuf+0x3CC))) /*fef*/
#define internal1_m2055_DvUp0 (*((pschar)(InternalBuf+0x3CE))) /*- есть команда на движение вперёд*/
#define internal1_m2055_DvDw0 (*((pschar)(InternalBuf+0x3D0))) /*- есть команда на движение назад*/
#define internal1_m2055_FDvUp0 (*((pschar)(InternalBuf+0x3D2))) /*- есть команда на движение вперёд*/
#define internal1_m2055_FDvDw0 (*((pschar)(InternalBuf+0x3D4))) /*- есть команда на движение назад*/
#define internal1_m2055_BlDv0 (*((pschar)(InternalBuf+0x3D6))) /*- была блокировка*/
#define internal1_m2055_Pkv0 (*((pschar)(InternalBuf+0x3D8))) /*Pkv - передний конечный выключатель*/
#define internal1_m2055_Pkav0 (*((pschar)(InternalBuf+0x3DA))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m2055_Zkv0 (*((pschar)(InternalBuf+0x3DC))) /*Zkv - задний конечный выключатель*/
#define internal1_m2055_Zkav0 (*((pschar)(InternalBuf+0x3DE))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m2055_txNm (*((psfloat)(InternalBuf+0x3E0))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m2055_txSm (*((psfloat)(InternalBuf+0x3E5))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m2055_txHr (*((psfloat)(InternalBuf+0x3EA))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m2055_txLd (*((psfloat)(InternalBuf+0x3EF))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m2055_fef (*((pschar)(InternalBuf+0x3F4))) /*fef*/
#define internal1_m1459_q0 (*((psbool)(InternalBuf+0x3F6))) /*q0 - внутренний параметр*/
#define internal1_m1463_x0 (*((psbool)(InternalBuf+0x3F8))) /*был приход сигнала x1*/
#define internal1_m1463_y0 (*((psfloat)(InternalBuf+0x3FA))) /*интервал между сигналами х1 и х2*/
#define internal1_m1873_x0 (*((psbool)(InternalBuf+0x3FF))) /*был приход сигнала x1*/
#define internal1_m1873_y0 (*((psfloat)(InternalBuf+0x401))) /*интервал между сигналами х1 и х2*/
#define internal1_m1834_x0 (*((psbool)(InternalBuf+0x406))) /*был приход сигнала x1*/
#define internal1_m1834_y0 (*((psfloat)(InternalBuf+0x408))) /*интервал между сигналами х1 и х2*/
#define internal1_m274_q0 (*((psbool)(InternalBuf+0x40D))) /*q0 - внутренний параметр*/
#define internal1_m982_q0 (*((psbool)(InternalBuf+0x40F))) /*q0 - внутренний параметр*/
#define internal1_m615_q0 (*((psbool)(InternalBuf+0x411))) /*q0 - внутренний параметр*/
#define internal1_m1282_X0 (*((psfloat)(InternalBuf+0x413))) /*текущая зона нечувствительности (Dlt/Du) в мм (гр.)*/
#define internal1_m1282_t0 (*((psfloat)(InternalBuf+0x418))) /*время нахождения в зоне возврата*/
#define internal1_m1282_BLDv0 (*((pschar)(InternalBuf+0x41D))) /*BlDv - Блокировка движения*/
#define internal1_m1301_tx (*((psfloat)(InternalBuf+0x41F))) /*tx - время накопленное сек*/
#define internal1_m1301_y0 (*((pschar)(InternalBuf+0x424))) /*y0*/
#define internal1_m1303_tx (*((psfloat)(InternalBuf+0x426))) /*tx - время накопленное сек*/
#define internal1_m1303_y0 (*((pschar)(InternalBuf+0x42B))) /*y0*/
#define internal1_m1310_xptr (*((psint)(InternalBuf+0x42D))) /*указатель текущей позиции в массиве координат*/
#define internal1_m1310_x0 (*((psfloat)(InternalBuf+0x430))) /*x0 - массив мгновенных значений координат*/
#define internal1_m1310_tim0 (*((psfloat)(InternalBuf+0x55C))) /*tim0 - массив значений времени цикла*/
#define internal1_m1310_mcount (*((psint)(InternalBuf+0x688))) /*count - счетчик заполнения массива значений координат*/
#define internal1_m1310_sumtim (*((psfloat)(InternalBuf+0x68B))) /*sumtim - время в пути*/
#define internal1_m1310_sumtakt (*((psfloat)(InternalBuf+0x690))) /*sumtim - время в пути*/
#define internal1_m1310_StSpeed (*((psfloat)(InternalBuf+0x695))) /*StSpeed - стартовая скорость - с которой начинается изменение скорости*/
#define internal1_m1310_Vz0 (*((psfloat)(InternalBuf+0x69A))) /*Vz0 - предыдущая заданная скорость*/
#define internal1_m1310_flRazg (*((psint)(InternalBuf+0x69F))) /*признак разгона/торможения*/
#define internal1_m1310_DelSp (*((psfloat)(InternalBuf+0x6A2))) /*DelSp - время переключения скоростей*/
#define internal1_m1310_z0 (*((psfloat)(InternalBuf+0x6A7))) /*z0 - точка прекращения движения*/
#define internal1_m1310_txZS (*((psfloat)(InternalBuf+0x6AC))) /*txZS*/
#define internal1_m1310_tx (*((psfloat)(InternalBuf+0x6B1))) /*tx*/
#define internal1_m1310_txd (*((psfloat)(InternalBuf+0x6B6))) /*txd*/
#define internal1_m1310_txMBl (*((psfloat)(InternalBuf+0x6BB))) /*tx*/
#define internal1_m1310_txBl (*((psfloat)(InternalBuf+0x6C0))) /*tx*/
#define internal1_m1310_Speed0 (*((psfloat)(InternalBuf+0x6C5))) /*Speed0 - предыдущее значение скорости перемещения*/
#define internal1_m1310_xz0 (*((psfloat)(InternalBuf+0x6CA))) /*xz0 - новое задание мм*/
#define internal1_m1310_tz0 (*((psfloat)(InternalBuf+0x6CF))) /*tz0 - время защиты от нового задания сек*/
#define internal1_m1310_Shift0 (*((psbool)(InternalBuf+0x6D4))) /*Shift0 - признак самохода*/
#define internal1_m1310_ShCntlSp0 (*((psbool)(InternalBuf+0x6D6))) /*ShCntlSp0 - признак выдержки времени после достижения 0 скорости*/
#define internal1_m1310_ShiftControl (*((psbool)(InternalBuf+0x6D8))) /*ShiftControl - признак самохода*/
#define internal1_m613_q0 (*((psbool)(InternalBuf+0x6DA))) /*q0 - внутренний параметр*/
#define internal1_m880_X0 (*((psfloat)(InternalBuf+0x6DC))) /*текущая зона нечувствительности (Dlt/Du) в мм (гр.)*/
#define internal1_m880_t0 (*((psfloat)(InternalBuf+0x6E1))) /*время нахождения в зоне возврата*/
#define internal1_m880_BLDv0 (*((pschar)(InternalBuf+0x6E6))) /*BlDv - Блокировка движения*/
#define internal1_m904_tx (*((psfloat)(InternalBuf+0x6E8))) /*tx - время накопленное сек*/
#define internal1_m904_y0 (*((pschar)(InternalBuf+0x6ED))) /*y0*/
#define internal1_m905_tx (*((psfloat)(InternalBuf+0x6EF))) /*tx - время накопленное сек*/
#define internal1_m905_y0 (*((pschar)(InternalBuf+0x6F4))) /*y0*/
#define internal1_m913_xptr (*((psint)(InternalBuf+0x6F6))) /*указатель текущей позиции в массиве координат*/
#define internal1_m913_x0 (*((psfloat)(InternalBuf+0x6F9))) /*x0 - массив мгновенных значений координат*/
#define internal1_m913_tim0 (*((psfloat)(InternalBuf+0x825))) /*tim0 - массив значений времени цикла*/
#define internal1_m913_mcount (*((psint)(InternalBuf+0x951))) /*count - счетчик заполнения массива значений координат*/
#define internal1_m913_sumtim (*((psfloat)(InternalBuf+0x954))) /*sumtim - время в пути*/
#define internal1_m913_sumtakt (*((psfloat)(InternalBuf+0x959))) /*sumtim - время в пути*/
#define internal1_m913_StSpeed (*((psfloat)(InternalBuf+0x95E))) /*StSpeed - стартовая скорость - с которой начинается изменение скорости*/
#define internal1_m913_Vz0 (*((psfloat)(InternalBuf+0x963))) /*Vz0 - предыдущая заданная скорость*/
#define internal1_m913_flRazg (*((psint)(InternalBuf+0x968))) /*признак разгона/торможения*/
#define internal1_m913_DelSp (*((psfloat)(InternalBuf+0x96B))) /*DelSp - время переключения скоростей*/
#define internal1_m913_z0 (*((psfloat)(InternalBuf+0x970))) /*z0 - точка прекращения движения*/
#define internal1_m913_txZS (*((psfloat)(InternalBuf+0x975))) /*txZS*/
#define internal1_m913_tx (*((psfloat)(InternalBuf+0x97A))) /*tx*/
#define internal1_m913_txd (*((psfloat)(InternalBuf+0x97F))) /*txd*/
#define internal1_m913_txMBl (*((psfloat)(InternalBuf+0x984))) /*tx*/
#define internal1_m913_txBl (*((psfloat)(InternalBuf+0x989))) /*tx*/
#define internal1_m913_Speed0 (*((psfloat)(InternalBuf+0x98E))) /*Speed0 - предыдущее значение скорости перемещения*/
#define internal1_m913_xz0 (*((psfloat)(InternalBuf+0x993))) /*xz0 - новое задание мм*/
#define internal1_m913_tz0 (*((psfloat)(InternalBuf+0x998))) /*tz0 - время защиты от нового задания сек*/
#define internal1_m913_Shift0 (*((psbool)(InternalBuf+0x99D))) /*Shift0 - признак самохода*/
#define internal1_m913_ShCntlSp0 (*((psbool)(InternalBuf+0x99F))) /*ShCntlSp0 - признак выдержки времени после достижения 0 скорости*/
#define internal1_m913_ShiftControl (*((psbool)(InternalBuf+0x9A1))) /*ShiftControl - признак самохода*/
#define internal1_m484_X0 (*((psfloat)(InternalBuf+0x9A3))) /*текущая зона нечувствительности (Dlt/Du) в мм (гр.)*/
#define internal1_m484_t0 (*((psfloat)(InternalBuf+0x9A8))) /*время нахождения в зоне возврата*/
#define internal1_m484_BLDv0 (*((pschar)(InternalBuf+0x9AD))) /*BlDv - Блокировка движения*/
#define internal1_m504_tx (*((psfloat)(InternalBuf+0x9AF))) /*tx - время накопленное сек*/
#define internal1_m504_y0 (*((pschar)(InternalBuf+0x9B4))) /*y0*/
#define internal1_m506_tx (*((psfloat)(InternalBuf+0x9B6))) /*tx - время накопленное сек*/
#define internal1_m506_y0 (*((pschar)(InternalBuf+0x9BB))) /*y0*/
#define internal1_m511_xptr (*((psint)(InternalBuf+0x9BD))) /*указатель текущей позиции в массиве координат*/
#define internal1_m511_x0 (*((psfloat)(InternalBuf+0x9C0))) /*x0 - массив мгновенных значений координат*/
#define internal1_m511_tim0 (*((psfloat)(InternalBuf+0xCAE))) /*tim0 - массив значений времени цикла*/
#define internal1_m511_mcount (*((psint)(InternalBuf+0xF9C))) /*count - счетчик заполнения массива значений координат*/
#define internal1_m511_sumtim (*((psfloat)(InternalBuf+0xF9F))) /*sumtim - время в пути*/
#define internal1_m511_sumtakt (*((psfloat)(InternalBuf+0xFA4))) /*sumtim - время в пути*/
#define internal1_m511_StSpeed (*((psfloat)(InternalBuf+0xFA9))) /*StSpeed - стартовая скорость - с которой начинается изменение скорости*/
#define internal1_m511_Vz0 (*((psfloat)(InternalBuf+0xFAE))) /*Vz0 - предыдущая заданная скорость*/
#define internal1_m511_flRazg (*((psint)(InternalBuf+0xFB3))) /*признак разгона/торможения*/
#define internal1_m511_DelSp (*((psfloat)(InternalBuf+0xFB6))) /*DelSp - время переключения скоростей*/
#define internal1_m511_z0 (*((psfloat)(InternalBuf+0xFBB))) /*z0 - точка прекращения движения*/
#define internal1_m511_txZS (*((psfloat)(InternalBuf+0xFC0))) /*txZS*/
#define internal1_m511_tx (*((psfloat)(InternalBuf+0xFC5))) /*tx*/
#define internal1_m511_txd (*((psfloat)(InternalBuf+0xFCA))) /*txd*/
#define internal1_m511_txMBl (*((psfloat)(InternalBuf+0xFCF))) /*tx*/
#define internal1_m511_txBl (*((psfloat)(InternalBuf+0xFD4))) /*tx*/
#define internal1_m511_Speed0 (*((psfloat)(InternalBuf+0xFD9))) /*Speed0 - предыдущее значение скорости перемещения*/
#define internal1_m511_xz0 (*((psfloat)(InternalBuf+0xFDE))) /*xz0 - новое задание мм*/
#define internal1_m511_tz0 (*((psfloat)(InternalBuf+0xFE3))) /*tz0 - время защиты от нового задания сек*/
#define internal1_m511_Shift0 (*((psbool)(InternalBuf+0xFE8))) /*Shift0 - признак самохода*/
#define internal1_m511_ShCntlSp0 (*((psbool)(InternalBuf+0xFEA))) /*ShCntlSp0 - признак выдержки времени после достижения 0 скорости*/
#define internal1_m511_ShiftControl (*((psbool)(InternalBuf+0xFEC))) /*ShiftControl - признак самохода*/
#define internal1_m610_q0 (*((psbool)(InternalBuf+0xFEE))) /*q0 - внутренний параметр*/
#define internal1_m163_X0 (*((psfloat)(InternalBuf+0xFF0))) /*текущая зона нечувствительности (Dlt/Du) в мм (гр.)*/
#define internal1_m163_t0 (*((psfloat)(InternalBuf+0xFF5))) /*время нахождения в зоне возврата*/
#define internal1_m163_BLDv0 (*((pschar)(InternalBuf+0xFFA))) /*BlDv - Блокировка движения*/
#define internal1_m192_xptr (*((psint)(InternalBuf+0xFFC))) /*указатель текущей позиции в массиве координат*/
#define internal1_m192_x0 (*((psfloat)(InternalBuf+0xFFF))) /*x0 - массив мгновенных значений координат*/
#define internal1_m192_tim0 (*((psfloat)(InternalBuf+0x12ED))) /*tim0 - массив значений времени цикла*/
#define internal1_m192_mcount (*((psint)(InternalBuf+0x15DB))) /*count - счетчик заполнения массива значений координат*/
#define internal1_m192_sumtim (*((psfloat)(InternalBuf+0x15DE))) /*sumtim - время в пути*/
#define internal1_m192_sumtakt (*((psfloat)(InternalBuf+0x15E3))) /*sumtim - время в пути*/
#define internal1_m192_StSpeed (*((psfloat)(InternalBuf+0x15E8))) /*StSpeed - стартовая скорость - с которой начинается изменение скорости*/
#define internal1_m192_Vz0 (*((psfloat)(InternalBuf+0x15ED))) /*Vz0 - предыдущая заданная скорость*/
#define internal1_m192_flRazg (*((psint)(InternalBuf+0x15F2))) /*признак разгона/торможения*/
#define internal1_m192_DelSp (*((psfloat)(InternalBuf+0x15F5))) /*DelSp - время переключения скоростей*/
#define internal1_m192_z0 (*((psfloat)(InternalBuf+0x15FA))) /*z0 - точка прекращения движения*/
#define internal1_m192_txZS (*((psfloat)(InternalBuf+0x15FF))) /*txZS*/
#define internal1_m192_tx (*((psfloat)(InternalBuf+0x1604))) /*tx*/
#define internal1_m192_txd (*((psfloat)(InternalBuf+0x1609))) /*txd*/
#define internal1_m192_txMBl (*((psfloat)(InternalBuf+0x160E))) /*tx*/
#define internal1_m192_txBl (*((psfloat)(InternalBuf+0x1613))) /*tx*/
#define internal1_m192_Speed0 (*((psfloat)(InternalBuf+0x1618))) /*Speed0 - предыдущее значение скорости перемещения*/
#define internal1_m192_xz0 (*((psfloat)(InternalBuf+0x161D))) /*xz0 - новое задание мм*/
#define internal1_m192_tz0 (*((psfloat)(InternalBuf+0x1622))) /*tz0 - время защиты от нового задания сек*/
#define internal1_m192_Shift0 (*((psbool)(InternalBuf+0x1627))) /*Shift0 - признак самохода*/
#define internal1_m192_ShCntlSp0 (*((psbool)(InternalBuf+0x1629))) /*ShCntlSp0 - признак выдержки времени после достижения 0 скорости*/
#define internal1_m192_ShiftControl (*((psbool)(InternalBuf+0x162B))) /*ShiftControl - признак самохода*/
#define internal1_m636_q0 (*((psbool)(InternalBuf+0x162D))) /*q0 - внутренний параметр*/
#define internal1_m455_DvUp0 (*((pschar)(InternalBuf+0x162F))) /*- есть команда на движение вперёд*/
#define internal1_m455_DvDw0 (*((pschar)(InternalBuf+0x1631))) /*- есть команда на движение назад*/
#define internal1_m455_FDvUp0 (*((pschar)(InternalBuf+0x1633))) /*- есть команда на движение вперёд*/
#define internal1_m455_FDvDw0 (*((pschar)(InternalBuf+0x1635))) /*- есть команда на движение назад*/
#define internal1_m455_BlDv0 (*((pschar)(InternalBuf+0x1637))) /*- была блокировка*/
#define internal1_m455_Pkv0 (*((pschar)(InternalBuf+0x1639))) /*Pkv - передний конечный выключатель*/
#define internal1_m455_Pkav0 (*((pschar)(InternalBuf+0x163B))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m455_Zkv0 (*((pschar)(InternalBuf+0x163D))) /*Zkv - задний конечный выключатель*/
#define internal1_m455_Zkav0 (*((pschar)(InternalBuf+0x163F))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m455_txNm (*((psfloat)(InternalBuf+0x1641))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m455_txSm (*((psfloat)(InternalBuf+0x1646))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m455_txHr (*((psfloat)(InternalBuf+0x164B))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m455_txLd (*((psfloat)(InternalBuf+0x1650))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m455_fef (*((pschar)(InternalBuf+0x1655))) /*fef*/
#define internal1_m449_DvUp0 (*((pschar)(InternalBuf+0x1657))) /*- есть команда на движение вперёд*/
#define internal1_m449_DvDw0 (*((pschar)(InternalBuf+0x1659))) /*- есть команда на движение назад*/
#define internal1_m449_FDvUp0 (*((pschar)(InternalBuf+0x165B))) /*- есть команда на движение вперёд*/
#define internal1_m449_FDvDw0 (*((pschar)(InternalBuf+0x165D))) /*- есть команда на движение назад*/
#define internal1_m449_BlDv0 (*((pschar)(InternalBuf+0x165F))) /*- была блокировка*/
#define internal1_m449_Pkv0 (*((pschar)(InternalBuf+0x1661))) /*Pkv - передний конечный выключатель*/
#define internal1_m449_Pkav0 (*((pschar)(InternalBuf+0x1663))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m449_Zkv0 (*((pschar)(InternalBuf+0x1665))) /*Zkv - задний конечный выключатель*/
#define internal1_m449_Zkav0 (*((pschar)(InternalBuf+0x1667))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m449_txNm (*((psfloat)(InternalBuf+0x1669))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m449_txSm (*((psfloat)(InternalBuf+0x166E))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m449_txHr (*((psfloat)(InternalBuf+0x1673))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m449_txLd (*((psfloat)(InternalBuf+0x1678))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m449_fef (*((pschar)(InternalBuf+0x167D))) /*fef*/
#define internal1_m800_X0 (*((psfloat)(InternalBuf+0x167F))) /*текущая зона нечувствительности (Dlt/Du) в мм (гр.)*/
#define internal1_m800_t0 (*((psfloat)(InternalBuf+0x1684))) /*время нахождения в зоне возврата*/
#define internal1_m800_BLDv0 (*((pschar)(InternalBuf+0x1689))) /*BlDv - Блокировка движения*/
#define internal1_m820_xptr (*((psint)(InternalBuf+0x168B))) /*указатель текущей позиции в массиве координат*/
#define internal1_m820_x0 (*((psfloat)(InternalBuf+0x168E))) /*x0 - массив мгновенных значений координат*/
#define internal1_m820_tim0 (*((psfloat)(InternalBuf+0x181E))) /*tim0 - массив значений времени цикла*/
#define internal1_m820_mcount (*((psint)(InternalBuf+0x19AE))) /*count - счетчик заполнения массива значений координат*/
#define internal1_m820_sumtim (*((psfloat)(InternalBuf+0x19B1))) /*sumtim - время в пути*/
#define internal1_m820_sumtakt (*((psfloat)(InternalBuf+0x19B6))) /*sumtim - время в пути*/
#define internal1_m820_StSpeed (*((psfloat)(InternalBuf+0x19BB))) /*StSpeed - стартовая скорость - с которой начинается изменение скорости*/
#define internal1_m820_Vz0 (*((psfloat)(InternalBuf+0x19C0))) /*Vz0 - предыдущая заданная скорость*/
#define internal1_m820_flRazg (*((psint)(InternalBuf+0x19C5))) /*признак разгона/торможения*/
#define internal1_m820_DelSp (*((psfloat)(InternalBuf+0x19C8))) /*DelSp - время переключения скоростей*/
#define internal1_m820_z0 (*((psfloat)(InternalBuf+0x19CD))) /*z0 - точка прекращения движения*/
#define internal1_m820_txZS (*((psfloat)(InternalBuf+0x19D2))) /*txZS*/
#define internal1_m820_tx (*((psfloat)(InternalBuf+0x19D7))) /*tx*/
#define internal1_m820_txd (*((psfloat)(InternalBuf+0x19DC))) /*txd*/
#define internal1_m820_txMBl (*((psfloat)(InternalBuf+0x19E1))) /*tx*/
#define internal1_m820_txBl (*((psfloat)(InternalBuf+0x19E6))) /*tx*/
#define internal1_m820_Speed0 (*((psfloat)(InternalBuf+0x19EB))) /*Speed0 - предыдущее значение скорости перемещения*/
#define internal1_m820_xz0 (*((psfloat)(InternalBuf+0x19F0))) /*xz0 - новое задание мм*/
#define internal1_m820_tz0 (*((psfloat)(InternalBuf+0x19F5))) /*tz0 - время защиты от нового задания сек*/
#define internal1_m820_Shift0 (*((psbool)(InternalBuf+0x19FA))) /*Shift0 - признак самохода*/
#define internal1_m820_ShCntlSp0 (*((psbool)(InternalBuf+0x19FC))) /*ShCntlSp0 - признак выдержки времени после достижения 0 скорости*/
#define internal1_m820_ShiftControl (*((psbool)(InternalBuf+0x19FE))) /*ShiftControl - признак самохода*/
#define internal1_m1564_X0 (*((psfloat)(InternalBuf+0x1A00))) /*текущая зона нечувствительности (Dlt/Du) в мм (гр.)*/
#define internal1_m1564_t0 (*((psfloat)(InternalBuf+0x1A05))) /*время нахождения в зоне возврата*/
#define internal1_m1564_BLDv0 (*((pschar)(InternalBuf+0x1A0A))) /*BlDv - Блокировка движения*/
#define internal1_m1100_X0 (*((psfloat)(InternalBuf+0x1A0C))) /*текущая зона нечувствительности (Dlt/Du) в мм (гр.)*/
#define internal1_m1100_t0 (*((psfloat)(InternalBuf+0x1A11))) /*время нахождения в зоне возврата*/
#define internal1_m1100_BLDv0 (*((pschar)(InternalBuf+0x1A16))) /*BlDv - Блокировка движения*/
#define internal1_m608_q0 (*((psbool)(InternalBuf+0x1A18))) /*q0 - внутренний параметр*/
#define internal1_m1185_X0 (*((psfloat)(InternalBuf+0x1A1A))) /*текущая зона нечувствительности (Dlt/Du) в мм (гр.)*/
#define internal1_m1185_t0 (*((psfloat)(InternalBuf+0x1A1F))) /*время нахождения в зоне возврата*/
#define internal1_m1185_BLDv0 (*((pschar)(InternalBuf+0x1A24))) /*BlDv - Блокировка движения*/
#define internal1_m1205_tx (*((psfloat)(InternalBuf+0x1A26))) /*tx - время накопленное сек*/
#define internal1_m1205_y0 (*((pschar)(InternalBuf+0x1A2B))) /*y0*/
#define internal1_m1214_tx (*((psfloat)(InternalBuf+0x1A2D))) /*tx - время накопленное сек*/
#define internal1_m1214_y0 (*((pschar)(InternalBuf+0x1A32))) /*y0*/
#define internal1_m1219_xptr (*((psint)(InternalBuf+0x1A34))) /*указатель текущей позиции в массиве координат*/
#define internal1_m1219_x0 (*((psfloat)(InternalBuf+0x1A37))) /*x0 - массив мгновенных значений координат*/
#define internal1_m1219_tim0 (*((psfloat)(InternalBuf+0x1BC7))) /*tim0 - массив значений времени цикла*/
#define internal1_m1219_mcount (*((psint)(InternalBuf+0x1D57))) /*count - счетчик заполнения массива значений координат*/
#define internal1_m1219_sumtim (*((psfloat)(InternalBuf+0x1D5A))) /*sumtim - время в пути*/
#define internal1_m1219_sumtakt (*((psfloat)(InternalBuf+0x1D5F))) /*sumtim - время в пути*/
#define internal1_m1219_StSpeed (*((psfloat)(InternalBuf+0x1D64))) /*StSpeed - стартовая скорость - с которой начинается изменение скорости*/
#define internal1_m1219_Vz0 (*((psfloat)(InternalBuf+0x1D69))) /*Vz0 - предыдущая заданная скорость*/
#define internal1_m1219_flRazg (*((psint)(InternalBuf+0x1D6E))) /*признак разгона/торможения*/
#define internal1_m1219_DelSp (*((psfloat)(InternalBuf+0x1D71))) /*DelSp - время переключения скоростей*/
#define internal1_m1219_z0 (*((psfloat)(InternalBuf+0x1D76))) /*z0 - точка прекращения движения*/
#define internal1_m1219_txZS (*((psfloat)(InternalBuf+0x1D7B))) /*txZS*/
#define internal1_m1219_tx (*((psfloat)(InternalBuf+0x1D80))) /*tx*/
#define internal1_m1219_txd (*((psfloat)(InternalBuf+0x1D85))) /*txd*/
#define internal1_m1219_txMBl (*((psfloat)(InternalBuf+0x1D8A))) /*tx*/
#define internal1_m1219_txBl (*((psfloat)(InternalBuf+0x1D8F))) /*tx*/
#define internal1_m1219_Speed0 (*((psfloat)(InternalBuf+0x1D94))) /*Speed0 - предыдущее значение скорости перемещения*/
#define internal1_m1219_xz0 (*((psfloat)(InternalBuf+0x1D99))) /*xz0 - новое задание мм*/
#define internal1_m1219_tz0 (*((psfloat)(InternalBuf+0x1D9E))) /*tz0 - время защиты от нового задания сек*/
#define internal1_m1219_Shift0 (*((psbool)(InternalBuf+0x1DA3))) /*Shift0 - признак самохода*/
#define internal1_m1219_ShCntlSp0 (*((psbool)(InternalBuf+0x1DA5))) /*ShCntlSp0 - признак выдержки времени после достижения 0 скорости*/
#define internal1_m1219_ShiftControl (*((psbool)(InternalBuf+0x1DA7))) /*ShiftControl - признак самохода*/
#define internal1_m628_q0 (*((psbool)(InternalBuf+0x1DA9))) /*q0 - внутренний параметр*/
#define internal1_m1577_tx (*((psfloat)(InternalBuf+0x1DAB))) /*tx - время накопленное сек*/
#define internal1_m1577_y0 (*((pschar)(InternalBuf+0x1DB0))) /*y0*/
#define internal1_m1581_tx (*((psfloat)(InternalBuf+0x1DB2))) /*tx - время накопленное сек*/
#define internal1_m1581_y0 (*((pschar)(InternalBuf+0x1DB7))) /*y0*/
#define internal1_m1567_DvUp0 (*((pschar)(InternalBuf+0x1DB9))) /*- есть команда на движение вперёд*/
#define internal1_m1567_DvDw0 (*((pschar)(InternalBuf+0x1DBB))) /*- есть команда на движение назад*/
#define internal1_m1567_FDvUp0 (*((pschar)(InternalBuf+0x1DBD))) /*- есть команда на движение вперёд*/
#define internal1_m1567_FDvDw0 (*((pschar)(InternalBuf+0x1DBF))) /*- есть команда на движение назад*/
#define internal1_m1567_BlDv0 (*((pschar)(InternalBuf+0x1DC1))) /*- была блокировка*/
#define internal1_m1567_Pkv0 (*((pschar)(InternalBuf+0x1DC3))) /*Pkv - передний конечный выключатель*/
#define internal1_m1567_Pkav0 (*((pschar)(InternalBuf+0x1DC5))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m1567_Zkv0 (*((pschar)(InternalBuf+0x1DC7))) /*Zkv - задний конечный выключатель*/
#define internal1_m1567_Zkav0 (*((pschar)(InternalBuf+0x1DC9))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m1567_txNm (*((psfloat)(InternalBuf+0x1DCB))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m1567_txSm (*((psfloat)(InternalBuf+0x1DD0))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m1567_txHr (*((psfloat)(InternalBuf+0x1DD5))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m1567_txLd (*((psfloat)(InternalBuf+0x1DDA))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m1567_fef (*((pschar)(InternalBuf+0x1DDF))) /*fef*/
#define internal1_m1584_xptr (*((psint)(InternalBuf+0x1DE1))) /*указатель текущей позиции в массиве координат*/
#define internal1_m1584_x0 (*((psfloat)(InternalBuf+0x1DE4))) /*x0 - массив мгновенных значений координат*/
#define internal1_m1584_tim0 (*((psfloat)(InternalBuf+0x1E48))) /*tim0 - массив значений времени цикла*/
#define internal1_m1584_mcount (*((psint)(InternalBuf+0x1EAC))) /*count - счетчик заполнения массива значений координат*/
#define internal1_m1584_sumtim (*((psfloat)(InternalBuf+0x1EAF))) /*sumtim - время в пути*/
#define internal1_m1584_sumtakt (*((psfloat)(InternalBuf+0x1EB4))) /*sumtim - время в пути*/
#define internal1_m1584_StSpeed (*((psfloat)(InternalBuf+0x1EB9))) /*StSpeed - стартовая скорость - с которой начинается изменение скорости*/
#define internal1_m1584_Vz0 (*((psfloat)(InternalBuf+0x1EBE))) /*Vz0 - предыдущая заданная скорость*/
#define internal1_m1584_flRazg (*((psint)(InternalBuf+0x1EC3))) /*признак разгона/торможения*/
#define internal1_m1584_DelSp (*((psfloat)(InternalBuf+0x1EC6))) /*DelSp - время переключения скоростей*/
#define internal1_m1584_z0 (*((psfloat)(InternalBuf+0x1ECB))) /*z0 - точка прекращения движения*/
#define internal1_m1584_txZS (*((psfloat)(InternalBuf+0x1ED0))) /*txZS*/
#define internal1_m1584_tx (*((psfloat)(InternalBuf+0x1ED5))) /*tx*/
#define internal1_m1584_txd (*((psfloat)(InternalBuf+0x1EDA))) /*txd*/
#define internal1_m1584_txMBl (*((psfloat)(InternalBuf+0x1EDF))) /*tx*/
#define internal1_m1584_txBl (*((psfloat)(InternalBuf+0x1EE4))) /*tx*/
#define internal1_m1584_Speed0 (*((psfloat)(InternalBuf+0x1EE9))) /*Speed0 - предыдущее значение скорости перемещения*/
#define internal1_m1584_xz0 (*((psfloat)(InternalBuf+0x1EEE))) /*xz0 - новое задание мм*/
#define internal1_m1584_tz0 (*((psfloat)(InternalBuf+0x1EF3))) /*tz0 - время защиты от нового задания сек*/
#define internal1_m1584_Shift0 (*((psbool)(InternalBuf+0x1EF8))) /*Shift0 - признак самохода*/
#define internal1_m1584_ShCntlSp0 (*((psbool)(InternalBuf+0x1EFA))) /*ShCntlSp0 - признак выдержки времени после достижения 0 скорости*/
#define internal1_m1584_ShiftControl (*((psbool)(InternalBuf+0x1EFC))) /*ShiftControl - признак самохода*/
#define internal1_m1116_tx (*((psfloat)(InternalBuf+0x1EFE))) /*tx - время накопленное сек*/
#define internal1_m1116_y0 (*((pschar)(InternalBuf+0x1F03))) /*y0*/
#define internal1_m1120_tx (*((psfloat)(InternalBuf+0x1F05))) /*tx - время накопленное сек*/
#define internal1_m1120_y0 (*((pschar)(InternalBuf+0x1F0A))) /*y0*/
#define internal1_m618_q0 (*((psbool)(InternalBuf+0x1F0C))) /*q0 - внутренний параметр*/
#define internal1_m583_q0 (*((psbool)(InternalBuf+0x1F0E))) /*q0 - внутренний параметр*/
#define internal1_m1106_DvUp0 (*((pschar)(InternalBuf+0x1F10))) /*- есть команда на движение вперёд*/
#define internal1_m1106_DvDw0 (*((pschar)(InternalBuf+0x1F12))) /*- есть команда на движение назад*/
#define internal1_m1106_FDvUp0 (*((pschar)(InternalBuf+0x1F14))) /*- есть команда на движение вперёд*/
#define internal1_m1106_FDvDw0 (*((pschar)(InternalBuf+0x1F16))) /*- есть команда на движение назад*/
#define internal1_m1106_BlDv0 (*((pschar)(InternalBuf+0x1F18))) /*- была блокировка*/
#define internal1_m1106_Pkv0 (*((pschar)(InternalBuf+0x1F1A))) /*Pkv - передний конечный выключатель*/
#define internal1_m1106_Pkav0 (*((pschar)(InternalBuf+0x1F1C))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m1106_Zkv0 (*((pschar)(InternalBuf+0x1F1E))) /*Zkv - задний конечный выключатель*/
#define internal1_m1106_Zkav0 (*((pschar)(InternalBuf+0x1F20))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m1106_txNm (*((psfloat)(InternalBuf+0x1F22))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m1106_txSm (*((psfloat)(InternalBuf+0x1F27))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m1106_txHr (*((psfloat)(InternalBuf+0x1F2C))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m1106_txLd (*((psfloat)(InternalBuf+0x1F31))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m1106_fef (*((pschar)(InternalBuf+0x1F36))) /*fef*/
#define internal1_m1124_xptr (*((psint)(InternalBuf+0x1F38))) /*указатель текущей позиции в массиве координат*/
#define internal1_m1124_x0 (*((psfloat)(InternalBuf+0x1F3B))) /*x0 - массив мгновенных значений координат*/
#define internal1_m1124_tim0 (*((psfloat)(InternalBuf+0x1F9F))) /*tim0 - массив значений времени цикла*/
#define internal1_m1124_mcount (*((psint)(InternalBuf+0x2003))) /*count - счетчик заполнения массива значений координат*/
#define internal1_m1124_sumtim (*((psfloat)(InternalBuf+0x2006))) /*sumtim - время в пути*/
#define internal1_m1124_sumtakt (*((psfloat)(InternalBuf+0x200B))) /*sumtim - время в пути*/
#define internal1_m1124_StSpeed (*((psfloat)(InternalBuf+0x2010))) /*StSpeed - стартовая скорость - с которой начинается изменение скорости*/
#define internal1_m1124_Vz0 (*((psfloat)(InternalBuf+0x2015))) /*Vz0 - предыдущая заданная скорость*/
#define internal1_m1124_flRazg (*((psint)(InternalBuf+0x201A))) /*признак разгона/торможения*/
#define internal1_m1124_DelSp (*((psfloat)(InternalBuf+0x201D))) /*DelSp - время переключения скоростей*/
#define internal1_m1124_z0 (*((psfloat)(InternalBuf+0x2022))) /*z0 - точка прекращения движения*/
#define internal1_m1124_txZS (*((psfloat)(InternalBuf+0x2027))) /*txZS*/
#define internal1_m1124_tx (*((psfloat)(InternalBuf+0x202C))) /*tx*/
#define internal1_m1124_txd (*((psfloat)(InternalBuf+0x2031))) /*txd*/
#define internal1_m1124_txMBl (*((psfloat)(InternalBuf+0x2036))) /*tx*/
#define internal1_m1124_txBl (*((psfloat)(InternalBuf+0x203B))) /*tx*/
#define internal1_m1124_Speed0 (*((psfloat)(InternalBuf+0x2040))) /*Speed0 - предыдущее значение скорости перемещения*/
#define internal1_m1124_xz0 (*((psfloat)(InternalBuf+0x2045))) /*xz0 - новое задание мм*/
#define internal1_m1124_tz0 (*((psfloat)(InternalBuf+0x204A))) /*tz0 - время защиты от нового задания сек*/
#define internal1_m1124_Shift0 (*((psbool)(InternalBuf+0x204F))) /*Shift0 - признак самохода*/
#define internal1_m1124_ShCntlSp0 (*((psbool)(InternalBuf+0x2051))) /*ShCntlSp0 - признак выдержки времени после достижения 0 скорости*/
#define internal1_m1124_ShiftControl (*((psbool)(InternalBuf+0x2053))) /*ShiftControl - признак самохода*/
#define internal1_m729_x0 (*((psbool)(InternalBuf+0x2055))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m700_x0 (*((psbool)(InternalBuf+0x2057))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m663_x0 (*((psbool)(InternalBuf+0x2059))) /*x0 - значение входного параметра на предыдущем шаге*/
#define internal1_m754_q0 (*((psbool)(InternalBuf+0x205B))) /*q0 - внутренний параметр*/
#define internal1_m749_q0 (*((psbool)(InternalBuf+0x205D))) /*q0 - внутренний параметр*/
#define internal1_m717_q0 (*((psbool)(InternalBuf+0x205F))) /*q0 - внутренний параметр*/
#define internal1_m721_q0 (*((psbool)(InternalBuf+0x2061))) /*q0 - внутренний параметр*/
#define internal1_m730_q0 (*((psbool)(InternalBuf+0x2063))) /*q0 - внутренний параметр*/
#define internal1_m742_q0 (*((psbool)(InternalBuf+0x2065))) /*q0 - внутренний параметр*/
#define internal1_m719_q0 (*((psbool)(InternalBuf+0x2067))) /*q0 - внутренний параметр*/
#define internal1_m1161_DvUp0 (*((pschar)(InternalBuf+0x2069))) /*- есть команда на движение вперёд*/
#define internal1_m1161_DvDw0 (*((pschar)(InternalBuf+0x206B))) /*- есть команда на движение назад*/
#define internal1_m1161_FDvUp0 (*((pschar)(InternalBuf+0x206D))) /*- есть команда на движение вперёд*/
#define internal1_m1161_FDvDw0 (*((pschar)(InternalBuf+0x206F))) /*- есть команда на движение назад*/
#define internal1_m1161_BlDv0 (*((pschar)(InternalBuf+0x2071))) /*- была блокировка*/
#define internal1_m1161_Pkv0 (*((pschar)(InternalBuf+0x2073))) /*Pkv - передний конечный выключатель*/
#define internal1_m1161_Pkav0 (*((pschar)(InternalBuf+0x2075))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m1161_Zkv0 (*((pschar)(InternalBuf+0x2077))) /*Zkv - задний конечный выключатель*/
#define internal1_m1161_Zkav0 (*((pschar)(InternalBuf+0x2079))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m1161_txNm (*((psfloat)(InternalBuf+0x207B))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m1161_txSm (*((psfloat)(InternalBuf+0x2080))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m1161_txHr (*((psfloat)(InternalBuf+0x2085))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m1161_txLd (*((psfloat)(InternalBuf+0x208A))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m1161_fef (*((pschar)(InternalBuf+0x208F))) /*fef*/
#define internal1_m1151_DvUp0 (*((pschar)(InternalBuf+0x2091))) /*- есть команда на движение вперёд*/
#define internal1_m1151_DvDw0 (*((pschar)(InternalBuf+0x2093))) /*- есть команда на движение назад*/
#define internal1_m1151_FDvUp0 (*((pschar)(InternalBuf+0x2095))) /*- есть команда на движение вперёд*/
#define internal1_m1151_FDvDw0 (*((pschar)(InternalBuf+0x2097))) /*- есть команда на движение назад*/
#define internal1_m1151_BlDv0 (*((pschar)(InternalBuf+0x2099))) /*- была блокировка*/
#define internal1_m1151_Pkv0 (*((pschar)(InternalBuf+0x209B))) /*Pkv - передний конечный выключатель*/
#define internal1_m1151_Pkav0 (*((pschar)(InternalBuf+0x209D))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m1151_Zkv0 (*((pschar)(InternalBuf+0x209F))) /*Zkv - задний конечный выключатель*/
#define internal1_m1151_Zkav0 (*((pschar)(InternalBuf+0x20A1))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m1151_txNm (*((psfloat)(InternalBuf+0x20A3))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m1151_txSm (*((psfloat)(InternalBuf+0x20A8))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m1151_txHr (*((psfloat)(InternalBuf+0x20AD))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m1151_txLd (*((psfloat)(InternalBuf+0x20B2))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m1151_fef (*((pschar)(InternalBuf+0x20B7))) /*fef*/
#define internal1_m774_DvUp0 (*((pschar)(InternalBuf+0x20B9))) /*- есть команда на движение вперёд*/
#define internal1_m774_DvDw0 (*((pschar)(InternalBuf+0x20BB))) /*- есть команда на движение назад*/
#define internal1_m774_FDvUp0 (*((pschar)(InternalBuf+0x20BD))) /*- есть команда на движение вперёд*/
#define internal1_m774_FDvDw0 (*((pschar)(InternalBuf+0x20BF))) /*- есть команда на движение назад*/
#define internal1_m774_BlDv0 (*((pschar)(InternalBuf+0x20C1))) /*- была блокировка*/
#define internal1_m774_Pkv0 (*((pschar)(InternalBuf+0x20C3))) /*Pkv - передний конечный выключатель*/
#define internal1_m774_Pkav0 (*((pschar)(InternalBuf+0x20C5))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m774_Zkv0 (*((pschar)(InternalBuf+0x20C7))) /*Zkv - задний конечный выключатель*/
#define internal1_m774_Zkav0 (*((pschar)(InternalBuf+0x20C9))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m774_txNm (*((psfloat)(InternalBuf+0x20CB))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m774_txSm (*((psfloat)(InternalBuf+0x20D0))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m774_txHr (*((psfloat)(InternalBuf+0x20D5))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m774_txLd (*((psfloat)(InternalBuf+0x20DA))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m774_fef (*((pschar)(InternalBuf+0x20DF))) /*fef*/
#define internal1_m770_DvUp0 (*((pschar)(InternalBuf+0x20E1))) /*- есть команда на движение вперёд*/
#define internal1_m770_DvDw0 (*((pschar)(InternalBuf+0x20E3))) /*- есть команда на движение назад*/
#define internal1_m770_FDvUp0 (*((pschar)(InternalBuf+0x20E5))) /*- есть команда на движение вперёд*/
#define internal1_m770_FDvDw0 (*((pschar)(InternalBuf+0x20E7))) /*- есть команда на движение назад*/
#define internal1_m770_BlDv0 (*((pschar)(InternalBuf+0x20E9))) /*- была блокировка*/
#define internal1_m770_Pkv0 (*((pschar)(InternalBuf+0x20EB))) /*Pkv - передний конечный выключатель*/
#define internal1_m770_Pkav0 (*((pschar)(InternalBuf+0x20ED))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m770_Zkv0 (*((pschar)(InternalBuf+0x20EF))) /*Zkv - задний конечный выключатель*/
#define internal1_m770_Zkav0 (*((pschar)(InternalBuf+0x20F1))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m770_txNm (*((psfloat)(InternalBuf+0x20F3))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m770_txSm (*((psfloat)(InternalBuf+0x20F8))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m770_txHr (*((psfloat)(InternalBuf+0x20FD))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m770_txLd (*((psfloat)(InternalBuf+0x2102))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m770_fef (*((pschar)(InternalBuf+0x2107))) /*fef*/
#define internal1_m354_DvUp0 (*((pschar)(InternalBuf+0x2109))) /*- есть команда на движение вперёд*/
#define internal1_m354_DvDw0 (*((pschar)(InternalBuf+0x210B))) /*- есть команда на движение назад*/
#define internal1_m354_FDvUp0 (*((pschar)(InternalBuf+0x210D))) /*- есть команда на движение вперёд*/
#define internal1_m354_FDvDw0 (*((pschar)(InternalBuf+0x210F))) /*- есть команда на движение назад*/
#define internal1_m354_BlDv0 (*((pschar)(InternalBuf+0x2111))) /*- была блокировка*/
#define internal1_m354_Pkv0 (*((pschar)(InternalBuf+0x2113))) /*Pkv - передний конечный выключатель*/
#define internal1_m354_Pkav0 (*((pschar)(InternalBuf+0x2115))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m354_Zkv0 (*((pschar)(InternalBuf+0x2117))) /*Zkv - задний конечный выключатель*/
#define internal1_m354_Zkav0 (*((pschar)(InternalBuf+0x2119))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m354_txNm (*((psfloat)(InternalBuf+0x211B))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m354_txSm (*((psfloat)(InternalBuf+0x2120))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m354_txHr (*((psfloat)(InternalBuf+0x2125))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m354_txLd (*((psfloat)(InternalBuf+0x212A))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m354_fef (*((pschar)(InternalBuf+0x212F))) /*fef*/
#define internal1_m383_DvUp0 (*((pschar)(InternalBuf+0x2131))) /*- есть команда на движение вперёд*/
#define internal1_m383_DvDw0 (*((pschar)(InternalBuf+0x2133))) /*- есть команда на движение назад*/
#define internal1_m383_FDvUp0 (*((pschar)(InternalBuf+0x2135))) /*- есть команда на движение вперёд*/
#define internal1_m383_FDvDw0 (*((pschar)(InternalBuf+0x2137))) /*- есть команда на движение назад*/
#define internal1_m383_BlDv0 (*((pschar)(InternalBuf+0x2139))) /*- была блокировка*/
#define internal1_m383_Pkv0 (*((pschar)(InternalBuf+0x213B))) /*Pkv - передний конечный выключатель*/
#define internal1_m383_Pkav0 (*((pschar)(InternalBuf+0x213D))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m383_Zkv0 (*((pschar)(InternalBuf+0x213F))) /*Zkv - задний конечный выключатель*/
#define internal1_m383_Zkav0 (*((pschar)(InternalBuf+0x2141))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m383_txNm (*((psfloat)(InternalBuf+0x2143))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m383_txSm (*((psfloat)(InternalBuf+0x2148))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m383_txHr (*((psfloat)(InternalBuf+0x214D))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m383_txLd (*((psfloat)(InternalBuf+0x2152))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m383_fef (*((pschar)(InternalBuf+0x2157))) /*fef*/
#define internal1_m377_DvUp0 (*((pschar)(InternalBuf+0x2159))) /*- есть команда на движение вперёд*/
#define internal1_m377_DvDw0 (*((pschar)(InternalBuf+0x215B))) /*- есть команда на движение назад*/
#define internal1_m377_FDvUp0 (*((pschar)(InternalBuf+0x215D))) /*- есть команда на движение вперёд*/
#define internal1_m377_FDvDw0 (*((pschar)(InternalBuf+0x215F))) /*- есть команда на движение назад*/
#define internal1_m377_BlDv0 (*((pschar)(InternalBuf+0x2161))) /*- была блокировка*/
#define internal1_m377_Pkv0 (*((pschar)(InternalBuf+0x2163))) /*Pkv - передний конечный выключатель*/
#define internal1_m377_Pkav0 (*((pschar)(InternalBuf+0x2165))) /*Pkav - передний конечный аварийный выключатель*/
#define internal1_m377_Zkv0 (*((pschar)(InternalBuf+0x2167))) /*Zkv - задний конечный выключатель*/
#define internal1_m377_Zkav0 (*((pschar)(InternalBuf+0x2169))) /*Zkav - задний конечный аварийный выключатель*/
#define internal1_m377_txNm (*((psfloat)(InternalBuf+0x216B))) /*txNm - счётчик задержки сигнализации недвижения*/
#define internal1_m377_txSm (*((psfloat)(InternalBuf+0x2170))) /*txSm - счётчик задержки сигнализации самохода*/
#define internal1_m377_txHr (*((psfloat)(InternalBuf+0x2175))) /*txHr - счётчик задержки сигнализации ошибки направления перемещения*/
#define internal1_m377_txLd (*((psfloat)(InternalBuf+0x217A))) /*txLd - счётчик задержки сигнализации превышения времени перемещения*/
#define internal1_m377_fef (*((pschar)(InternalBuf+0x217F))) /*fef*/
#define internal1_m726_q0 (*((psbool)(InternalBuf+0x2181))) /*q0 - внутренний параметр*/
#define internal1_m723_q0 (*((psbool)(InternalBuf+0x2183))) /*q0 - внутренний параметр*/
int InternalBufSize = 8581;

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
struct sbool  var11 = {0,0};
struct sbool  var12;
struct sbool  var13;
struct sbool  var14;
struct sbool  var15 = {0,0};
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
struct sbool  var27 = {0,0};
struct sbool  var28 = {0,0};
struct sbool  var29;
struct sbool  var30 = {0,0};
struct sbool  var31;
struct sbool  var32;
struct sbool  var33;
struct sbool  var34;
struct sbool  var35 = {0,0};
struct sbool  var36;
struct sbool  var37;
struct sbool  var38 = {0,0};
struct sbool  var39;
struct sbool  var40 = {0,0};
struct sbool  var41 = {0,0};
struct sbool  var42;
struct sbool  var43;
struct sbool  var44;
struct sbool  var45;
struct sbool  var46 = {0,0};
struct sbool  var47;
struct sbool  var48 = {0,0};
struct sbool  var49;
struct sbool  var50 = {0,0};
struct sbool  var51;
struct sbool  var52;
struct sbool  var53;
struct sbool  var54;
struct sbool  var55;
struct sbool  var56 = {0,0};
struct sbool  var57;
struct sbool  var58;
struct sbool  var59;
struct sbool  var60 = {0,0};
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
struct sint  var76;
struct sbool  var77;
struct sbool  var78;
struct sint  var79;
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
struct sbool  var96 = {0,0};
struct sbool  var97 = {0,0};
struct sbool  var98 = {0,0};
struct sbool  var99 = {0,0};
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
struct sbool  var112 = {0,0};
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
struct sfloat  var124;
struct sbool  var125;
struct sbool  var126;
struct sbool  var127;
struct sbool  var128;
struct sbool  var129;
struct sbool  var130;
struct sbool  var131 = {0,0};
struct sbool  var132;
struct sbool  var133;
struct sfloat  var134;
struct sfloat  var135;
struct sbool  var136;
struct sbool  var137 = {0,0};
struct sbool  var138;
struct sfloat  var139;
struct sfloat  var140;
struct sbool  var141;
struct sbool  var142;
struct sfloat  var143;
struct sbool  var144;
struct sbool  var145 = {0,0};
struct sbool  var146;
struct sbool  var147;
struct sbool  var148;
struct sbool  var149;
struct sbool  var150;
struct sbool  var151;
struct sfloat  var152;
struct sfloat  var153;
struct sfloat  var154 = {0,0};
struct sfloat  var155;
struct sbool  var156 = {0,0};
struct sfloat  var157;
struct sfloat  var158;
struct sint  var159;
struct sbool  var160;
struct sbool  var161;
struct sbool  var162;
struct sbool  var163;
struct sbool  var164 = {0,0};
struct sbool  var165 = {0,0};
struct sbool  var166;
struct sbool  var167;
struct sbool  var168;
struct sbool  var169;
struct sbool  var170;
struct sbool  var171;
struct sbool  var172;
struct sbool  var173;
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
struct sbool  var186 = {0,0};
struct sbool  var187 = {0,0};
struct sbool  var188;
struct sbool  var189;
struct sbool  var190 = {0,0};
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
struct sbool  var229 = {0,0};
struct sbool  var230;
struct sbool  var231;
struct sbool  var232;
struct sbool  var233 = {0,0};
struct sbool  var234 = {0,0};
struct sbool  var235;
struct sbool  var236;
struct sbool  var237;
struct sbool  var238 = {0,0};
struct sbool  var239;
struct sbool  var240;
struct sbool  var241;
struct sbool  var242;
struct sbool  var243;
struct sbool  var244;
struct sbool  var245;
struct sbool  var246;
struct sbool  var247;
struct sbool  var248;
struct sbool  var249;
struct sbool  var250 = {0,0};
struct sbool  var251;
struct sbool  var252;
struct sbool  var253;
struct sfloat  var254;
struct sbool  var255;
struct sbool  var256;
struct sbool  var257;
struct sfloat  var258;
struct sbool  var259;
struct sbool  var260;
struct sbool  var261;
struct sfloat  var262;
struct sbool  var263;
struct sbool  var264;
struct sbool  var265;
struct sfloat  var266 = {0,0};
struct sbool  var267;
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
struct sbool  var278 = {0,0};
struct sbool  var279;
struct sbool  var280 = {0,0};
struct sbool  var281 = {0,0};
struct sbool  var282;
struct sbool  var283;
struct sbool  var284;
struct sbool  var285;
struct sbool  var286;
struct sbool  var287;
struct sbool  var288;
struct sbool  var289;
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
struct sbool  var330 = {0,0};
struct sbool  var331 = {0,0};
struct sbool  var332;
struct sbool  var333;
struct sbool  var334;
struct sbool  var335;
struct sbool  var336;
struct sbool  var337;
struct sbool  var338;
struct sbool  var339;
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
struct sfloat  var367;
struct sfloat  var368;
struct sbool  var369;
struct sfloat  var370;
struct sfloat  var371;
struct sbool  var372;
struct sfloat  var373;
struct sfloat  var374;
struct sbool  var375;
struct sfloat  var376;
struct sfloat  var377;
struct sbool  var378;
struct sbool  var379;
struct sfloat  var380;
struct sfloat  var381;
struct sbool  var382;
struct sbool  var383;
struct sbool  var384;
struct sbool  var385;
struct sbool  var386;
struct sbool  var387;
struct sbool  var388 = {0,0};
struct sbool  var389;
struct sbool  var390;
struct sbool  var391;
struct sbool  var392;
struct sbool  var393;
struct sbool  var394;
struct sbool  var395;
struct sbool  var396;
struct sbool  var397;
struct sbool  var398;
struct sbool  var399;
struct sbool  var400 = {0,0};
struct sbool  var401 = {0,0};
struct sbool  var402;
struct sbool  var403;
struct sbool  var404;
struct sbool  var405;
struct sbool  var406;
struct sbool  var407;
struct sbool  var408;
struct sbool  var409;
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
struct sbool  var455 = {0,0};
struct sbool  var456 = {0,0};
struct sbool  var457;
struct sbool  var458 = {0,0};
struct sbool  var459;
struct sbool  var460 = {0,0};
struct sbool  var461;
struct sbool  var462 = {0,0};
struct sbool  var463;
struct sbool  var464;
struct sbool  var465;
struct sbool  var466;
struct sbool  var467;
struct sbool  var468;
struct sbool  var469;
struct sbool  var470;
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
struct sbool  var482 = {0,0};
struct sbool  var483 = {0,0};
struct sbool  var484;
struct sbool  var485;
struct sbool  var486 = {0,0};
struct sbool  var487;
struct sbool  var488 = {0,0};
struct sbool  var489;
struct sbool  var490;
struct sbool  var491;
struct sbool  var492 = {0,0};
struct sbool  var493;
struct sbool  var494 = {0,0};
struct sbool  var495;
struct sbool  var496;
struct sbool  var497;
struct sbool  var498;
struct sbool  var499;
struct sbool  var500 = {0,0};
struct sbool  var501;
struct sbool  var502;
struct sbool  var503 = {0,0};
struct sbool  var504;
struct sbool  var505;
struct sbool  var506;
struct sbool  var507;
struct sbool  var508;
struct sbool  var509;
struct sbool  var510;
struct sbool  var511;
struct sbool  var512 = {0,0};
struct sbool  var513;
struct sbool  var514;
struct sbool  var515;
struct sbool  var516;
struct sbool  var517;
struct sbool  var518;
struct sbool  var519;
struct sbool  var520;
struct sbool  var521;
struct sbool  var522;
struct sbool  var523;
struct sbool  var524;
struct slong  var525;
struct sbool  var526 = {0,0};
struct sbool  var527;
struct sbool  var528;
struct sbool  var529;
struct sbool  var530;
struct sbool  var531;
struct sbool  var532;
struct sbool  var533;
struct sbool  var534;
struct sbool  var535;
struct sbool  var536;
struct sbool  var537;
struct sbool  var538;
struct sbool  var539;
struct sbool  var540;
struct sbool  var541 = {0,0};
struct sbool  var542;
struct sbool  var543;
struct sbool  var544;
struct sbool  var545 = {0,0};
struct sbool  var546;
struct sbool  var547;
struct sbool  var548;
struct sbool  var549;
struct sbool  var550;
struct sbool  var551;
struct sbool  var552;
struct sbool  var553;
struct sbool  var554;
struct sbool  var555;
struct sbool  var556;
struct sbool  var557;
struct sbool  var558;
struct sbool  var559;
struct sbool  var560;
struct sbool  var561 = {0,0};
struct sbool  var562 = {0,0};
struct sbool  var563;
struct sbool  var564;
struct sbool  var565;
struct sbool  var566;
struct sbool  var567;
struct sbool  var568;
struct sbool  var569;
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
struct sbool  var665 = {0,0};
struct sbool  var666 = {0,0};
struct sbool  var667 = {0,0};
struct sbool  var668;
struct sbool  var669;
struct sbool  var670;
struct sbool  var671;
struct sbool  var672;
struct sbool  var673;
struct sbool  var674;
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
struct sbool  var713 = {0,0};
struct sbool  var714 = {0,0};
struct sbool  var715;
struct sbool  var716;
struct sbool  var717;
struct sbool  var718;
struct sbool  var719;
struct sbool  var720;
struct sbool  var721;
struct sbool  var722;
struct sbool  var723;
struct sbool  var724;
struct sbool  var725;
struct sbool  var726 = {0,0};
struct sbool  var727;
struct sbool  var728;
struct sbool  var729;
struct sbool  var730;
struct sbool  var731;
struct sbool  var732;
struct sbool  var733;
struct sbool  var734;
struct sbool  var735 = {0,0};
struct sbool  var736;
struct sbool  var737;
struct sbool  var738 = {0,0};
struct sbool  var739;
struct sbool  var740;
struct sbool  var741;
struct sbool  var742 = {0,0};
struct sbool  var743 = {0,0};
struct sbool  var744;
struct sbool  var745;
struct sbool  var746;
struct sbool  var747;
struct sbool  var748;
struct sbool  var749;
struct sbool  var750;
struct sbool  var751 = {0,0};
struct sbool  var752 = {0,0};
struct sbool  var753;
struct sbool  var754 = {0,0};
struct sbool  var755;
struct sbool  var756;
struct sbool  var757 = {0,0};
struct sbool  var758;
struct sbool  var759 = {0,0};
struct sbool  var760;
struct sbool  var761 = {0,0};
struct sbool  var762;
struct sbool  var763;
struct sbool  var764;
struct sbool  var765;
struct sbool  var766;
struct sbool  var767;
struct sbool  var768;
struct sbool  var769;
struct sbool  var770;
struct sbool  var771;
struct sbool  var772;
struct sbool  var773;
struct sbool  var774;
struct sbool  var775;
struct sbool  var776 = {0,0};
struct sbool  var777;
struct sbool  var778;
struct sbool  var779;
struct sbool  var780;
struct sbool  var781;
struct sbool  var782;
struct sbool  var783;
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
struct sbool  var808 = {0,0};
struct sbool  var809;
struct sbool  var810 = {0,0};
struct sbool  var811 = {0,0};
struct sbool  var812;
struct sbool  var813;
struct sbool  var814;
struct sbool  var815;
struct sbool  var816;
struct sbool  var817;
struct sbool  var818;
struct sbool  var819;
struct sbool  var820;
struct sbool  var821;
struct sbool  var822;
struct sbool  var823;
struct sbool  var824;
struct sbool  var825;
struct sbool  var826;
struct sbool  var827 = {0,0};
struct sbool  var828;
struct sbool  var829;
struct sbool  var830;
struct sbool  var831 = {0,0};
struct sbool  var832;
struct sbool  var833 = {0,0};
struct sbool  var834;
struct sbool  var835;
struct sbool  var836;
struct sbool  var837;
struct sbool  var838;
struct sbool  var839 = {0,0};
struct sbool  var840;
struct sbool  var841;
struct sbool  var842;
struct sbool  var843;
struct sbool  var844;
struct sbool  var845;
struct sbool  var846;
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
struct sbool  var897 = {0,0};
struct sbool  var898 = {0,0};
struct sbool  var899;
struct sbool  var900;
struct sbool  var901 = {0,0};
struct sbool  var902;
struct sbool  var903;
struct sbool  var904;
struct sbool  var905;
struct sbool  var906;
struct sbool  var907;
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
struct sbool  var921 = {0,0};
struct sbool  var922;
struct sbool  var923;
struct sbool  var924;
struct sbool  var925;
struct sbool  var926;
struct sbool  var927;
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
struct sfloat  var938;
struct sbool  var939;
struct sfloat  var940;
struct sbool  var941;
struct sfloat  var942;
struct sbool  var943;
struct sbool  var944;
struct sbool  var945;
struct sbool  var946;
struct sfloat  var947;
struct sfloat  var948;
struct sfloat  var949;
struct sfloat  var950;
struct sfloat  var951;
struct sfloat  var952;
struct sbool  var953;
struct sbool  var954;
struct sbool  var955;
struct sbool  var956 = {0,0};
struct sbool  var957;
struct sbool  var958;
struct sbool  var959;
struct sbool  var960;
struct sbool  var961;
struct sbool  var962;
struct sbool  var963;
struct sbool  var964 = {0,0};
struct sbool  var965;
struct sbool  var966;
struct sbool  var967 = {0,0};
struct sbool  var968 = {0,0};
struct sbool  var969 = {0,0};
struct sbool  var970;
struct sbool  var971 = {0,0};
struct sbool  var972 = {0,0};
struct sbool  var973 = {0,0};
struct sbool  var974 = {0,0};
struct sbool  var975 = {0,0};
struct sbool  var976;
struct sbool  var977;
struct sbool  var978;
struct sbool  var979 = {0,0};
struct sbool  var980;
struct sbool  var981;
struct sbool  var982;
struct sbool  var983;
struct sbool  var984;
struct sbool  var985;
struct sbool  var986;
struct sbool  var987;
struct sbool  var988;
struct sbool  var989;
struct sbool  var990;
struct sbool  var991;
struct sbool  var992;
struct sbool  var993 = {0,0};
struct sbool  var994;
struct sbool  var995;
struct sbool  var996;
struct sbool  var997;
struct sbool  var998;
struct sbool  var999;
struct sbool  var1000;
struct sbool  var1001;
struct sbool  var1002;
struct sbool  var1003;
struct sbool  var1004;
struct sbool  var1005;
struct sbool  var1006;
struct sbool  var1007;
struct sint  var1008;
struct sint  var1009;
struct sbool  var1010;
struct sbool  var1011;
struct sbool  var1012;
struct sbool  var1013;
struct sbool  var1014;
struct sbool  var1015;
struct slong  var1016;
struct sbool  var1017;
struct sbool  var1018;
struct sbool  var1019;
struct sint  var1020;
struct sbool  var1021;
struct sbool  var1022;
struct sbool  var1023;
struct sbool  var1024;
struct sbool  var1025;
struct sbool  var1026;
struct sbool  var1027;
struct sbool  var1028;
struct sbool  var1029;
struct sint  var1030;
struct sint  var1031;
struct sbool  var1032;
struct sbool  var1033;
struct sbool  var1034;
struct sbool  var1035;
struct sbool  var1036;
struct sbool  var1037;
struct sbool  var1038 = {0,0};
struct sbool  var1039;
struct sbool  var1040;
struct sbool  var1041;
struct sbool  var1042;
struct sbool  var1043;
struct sbool  var1044;
struct sbool  var1045;
struct sbool  var1046;
struct sbool  var1047;
struct sbool  var1048;
struct sbool  var1049;
struct sbool  var1050 = {0,0};
struct sbool  var1051;
struct sbool  var1052;
struct sbool  var1053;
struct sbool  var1054;
struct sbool  var1055;
struct sbool  var1056;
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
struct sbool  var1067 = {0,0};
struct sbool  var1068;
struct sbool  var1069;
struct sbool  var1070;
struct slong  var1071;
struct sbool  var1072;
struct sbool  var1073 = {0,0};
struct sbool  var1074;
struct sbool  var1075;
struct sbool  var1076 = {0,0};
struct sbool  var1077;
struct sbool  var1078;
struct sbool  var1079;
struct sbool  var1080;
struct sbool  var1081;
struct sbool  var1082;
struct sbool  var1083;
struct sbool  var1084 = {0,0};
struct sbool  var1085 = {0,0};
struct sbool  var1086;
struct sbool  var1087 = {0,0};
struct sbool  var1088;
struct sbool  var1089;
struct sfloat  var1090;
struct sbool  var1091;
struct sbool  var1092;
struct sbool  var1093;
struct sbool  var1094;
struct sbool  var1095;
struct sfloat  var1096;
struct sbool  var1097;
struct sbool  var1098;
struct sbool  var1099;
struct sbool  var1100;
struct sbool  var1101;
struct sbool  var1102;
struct sbool  var1103;
struct sbool  var1104;
struct sbool  var1105;
struct sbool  var1106;
struct sbool  var1107;
struct sbool  var1108;
struct sbool  var1109;
struct sint  var1110;
struct sbool  var1111;
struct sbool  var1112;
struct sbool  var1113;
struct sbool  var1114;
struct sbool  var1115;
struct sbool  var1116;
struct sbool  var1117 = {0,0};
struct sbool  var1118;
struct sbool  var1119;
struct sbool  var1120;
struct sbool  var1121;
struct sbool  var1122;
struct sbool  var1123;
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
struct sfloat  var1136;
struct sbool  var1137;
struct sbool  var1138;
struct sbool  var1139;
struct sbool  var1140;
struct sbool  var1141;
struct sbool  var1142;
struct sbool  var1143;
struct sbool  var1144;
struct sbool  var1145;
struct sbool  var1146;
struct sbool  var1147;
struct sbool  var1148;
struct sbool  var1149;
struct sbool  var1150 = {0,0};
struct sbool  var1151;
struct sbool  var1152 = {0,0};
struct sbool  var1153 = {0,0};
struct sbool  var1154;
struct sbool  var1155;
struct sbool  var1156 = {0,0};
struct sbool  var1157;
struct sbool  var1158 = {0,0};
struct sbool  var1159 = {0,0};
struct sbool  var1160;
struct sbool  var1161 = {0,0};
struct sbool  var1162;
struct sbool  var1163 = {0,0};
struct sbool  var1164;
struct sbool  var1165 = {0,0};
struct sbool  var1166;
struct sbool  var1167;
struct sbool  var1168;
struct sbool  var1169;
struct sbool  var1170;
struct sbool  var1171;
struct sbool  var1172;
struct sbool  var1173;
struct sbool  var1174 = {0,0};
struct sbool  var1175;
struct sbool  var1176 = {0,0};
struct sbool  var1177;
struct sbool  var1178;
struct sbool  var1179;
struct sbool  var1180;
struct sbool  var1181;
struct sbool  var1182;
struct sbool  var1183;
struct sbool  var1184;
struct sbool  var1185 = {0,0};
struct sbool  var1186;
struct sbool  var1187 = {0,0};
struct sbool  var1188;
struct sbool  var1189 = {0,0};
struct sbool  var1190;
struct sbool  var1191;
struct sbool  var1192;
struct sbool  var1193;
struct sbool  var1194;
struct sbool  var1195;
struct sbool  var1196 = {0,0};
struct sbool  var1197;
struct sbool  var1198 = {0,0};
struct sbool  var1199 = {0,0};
struct sbool  var1200 = {0,0};
struct sbool  var1201 = {0,0};
struct sbool  var1202;
struct sbool  var1203;
struct sbool  var1204;
struct sbool  var1205;
struct sbool  var1206;
struct sbool  var1207;
struct sbool  var1208;
struct sbool  var1209;
struct sbool  var1210;
struct sbool  var1211;
struct sbool  var1212;
struct sbool  var1213;
struct sbool  var1214;
struct sbool  var1215;
struct sbool  var1216;
struct sbool  var1217 = {0,0};
struct sbool  var1218 = {0,0};
struct sbool  var1219 = {0,0};
struct sbool  var1220 = {0,0};
struct sbool  var1221;
struct sbool  var1222;
struct sbool  var1223;
struct sbool  var1224;
struct sbool  var1225;
struct sbool  var1226;
struct sbool  var1227;
struct sbool  var1228;
struct sbool  var1229;
struct sbool  var1230;
struct sbool  var1231;
struct sbool  var1232;
struct sbool  var1233;
struct sbool  var1234;
struct slong  var1235 = {0,0};
struct sbool  var1236;
struct sint  var1237;
struct sint  var1238;
struct sbool  var1239;
struct sfloat  var1240;
struct sfloat  var1241;
struct sfloat  var1242;
struct sbool  var1243;
struct sbool  var1244;
struct sbool  var1245;
struct sbool  var1246;
struct sbool  var1247;
struct sbool  var1248 = {0,0};
struct sbool  var1249 = {0,0};
struct sbool  var1250;
struct sbool  var1251;
struct sbool  var1252;
struct sbool  var1253;
struct sbool  var1254;
struct sbool  var1255;
struct sbool  var1256;
struct sbool  var1257;
struct sbool  var1258;
struct sint  var1259;
struct sbool  var1260;
struct schar  var1261;
struct sint  var1262;
struct sbool  var1263;
struct sfloat  var1264 = {0,0};
struct sbool  var1265 = {0,0};
struct sbool  var1266;
struct sbool  var1267 = {0,0};
struct sbool  var1268;
struct sbool  var1269;
struct sbool  var1270;
struct sbool  var1271;
struct sfloat  var1272 = {0,0};
struct schar  var1273;
struct sbool  var1274;
struct sbool  var1275;
struct sbool  var1276;
struct sbool  var1277;
struct sfloat  var1278;
struct sbool  var1279;
struct sbool  var1280;
struct sbool  var1281;
struct sbool  var1282;
struct sbool  var1283;
struct sbool  var1284;
struct sbool  var1285;
struct sbool  var1286;
struct sbool  var1287;
struct sbool  var1288;
struct sbool  var1289;
struct sbool  var1290;
struct sint  var1291;
struct sbool  var1292;
struct schar  var1293;
struct sint  var1294;
struct sbool  var1295;
struct sfloat  var1296 = {0,0};
struct sbool  var1297 = {0,0};
struct sbool  var1298;
struct sbool  var1299 = {0,0};
struct sbool  var1300;
struct sbool  var1301;
struct sbool  var1302;
struct sbool  var1303;
struct sfloat  var1304 = {0,0};
struct schar  var1305;
struct sbool  var1306;
struct sbool  var1307;
struct sbool  var1308;
struct sbool  var1309;
struct sfloat  var1310;
struct sbool  var1311;
struct sbool  var1312;
struct sbool  var1313;
struct sbool  var1314;
struct sbool  var1315;
struct sbool  var1316;
struct sbool  var1317;
struct sbool  var1318;
struct sbool  var1319;
struct sint  var1320;
struct sbool  var1321;
struct schar  var1322;
struct sint  var1323;
struct sbool  var1324;
struct sfloat  var1325 = {0,0};
struct sbool  var1326 = {0,0};
struct sbool  var1327 = {0,0};
struct sbool  var1328;
struct sbool  var1329;
struct sbool  var1330;
struct sbool  var1331;
struct sbool  var1332;
struct sfloat  var1333 = {0,0};
struct schar  var1334;
struct sbool  var1335;
struct sbool  var1336;
struct sbool  var1337;
struct sbool  var1338;
struct sfloat  var1339;
struct sbool  var1340;
struct sbool  var1341;
struct sbool  var1342;
struct sbool  var1343;
struct sbool  var1344;
struct sbool  var1345;
struct sbool  var1346;
struct sbool  var1347;
struct sbool  var1348;
struct sbool  var1349;
struct sbool  var1350;
struct sbool  var1351;
struct sbool  var1352;
struct sint  var1353;
struct sbool  var1354;
struct schar  var1355;
struct sint  var1356;
struct sbool  var1357;
struct sfloat  var1358 = {0,0};
struct sbool  var1359 = {0,0};
struct sbool  var1360 = {0,0};
struct sbool  var1361;
struct sbool  var1362;
struct sbool  var1363;
struct sbool  var1364;
struct sbool  var1365;
struct sfloat  var1366 = {0,0};
struct schar  var1367;
struct sbool  var1368;
struct sbool  var1369;
struct sfloat  var1370;
struct sbool  var1371;
struct sbool  var1372;
struct sbool  var1373;
struct sbool  var1374;
struct sbool  var1375;
struct sbool  var1376;
struct sbool  var1377;
struct sbool  var1378 = {0,0};
struct sbool  var1379;
struct sbool  var1380;
struct sbool  var1381;
struct sbool  var1382;
struct sint  var1383;
struct sbool  var1384;
struct sbool  var1385;
struct sbool  var1386;
struct sbool  var1387 = {0,0};
struct sbool  var1388;
struct sbool  var1389;
struct sbool  var1390;
struct sbool  var1391;
struct sint  var1392;
struct sbool  var1393;
struct sbool  var1394;
struct sbool  var1395;
struct sbool  var1396;
struct sbool  var1397;
struct sbool  var1398;
struct sbool  var1399;
struct sint  var1400;
struct sbool  var1401;
struct schar  var1402;
struct sint  var1403;
struct sbool  var1404;
struct sfloat  var1405 = {0,0};
struct sbool  var1406 = {0,0};
struct sbool  var1407 = {0,0};
struct sbool  var1408;
struct sbool  var1409;
struct sbool  var1410;
struct sbool  var1411;
struct sbool  var1412;
struct sfloat  var1413 = {0,0};
struct schar  var1414;
struct sbool  var1415;
struct sbool  var1416;
struct sfloat  var1417;
struct sbool  var1418;
struct sbool  var1419;
struct sbool  var1420;
struct sbool  var1421;
struct sbool  var1422;
struct sbool  var1423;
struct sbool  var1424;
struct sbool  var1425;
struct schar  var1426;
struct sbool  var1427;
struct sbool  var1428;
struct sbool  var1429;
struct sbool  var1430;
struct sbool  var1431;
struct sbool  var1432;
struct sbool  var1433;
struct sbool  var1434;
struct sbool  var1435;
struct schar  var1436;
struct sbool  var1437;
struct sbool  var1438;
struct sint  var1439;
struct sbool  var1440;
struct schar  var1441;
struct sbool  var1442;
struct sint  var1443;
struct sbool  var1444;
struct sbool  var1445;
struct sfloat  var1446 = {0,0};
struct sbool  var1447 = {0,0};
struct sbool  var1448 = {0,0};
struct sbool  var1449;
struct sbool  var1450;
struct sbool  var1451;
struct sbool  var1452;
struct sbool  var1453;
struct sfloat  var1454 = {0,0};
struct schar  var1455;
struct sbool  var1456;
struct sbool  var1457;
struct sbool  var1458;
struct sbool  var1459;
struct sfloat  var1460;
struct sbool  var1461;
struct sbool  var1462;
struct sbool  var1463;
struct sbool  var1464;
struct sbool  var1465;
struct sbool  var1466;
struct sbool  var1467;
struct sbool  var1468;
struct sbool  var1469;
struct sbool  var1470;
struct sbool  var1471;
struct sbool  var1472;
struct sfloat  var1473;
struct sbool  var1474;
struct sbool  var1475;
struct sbool  var1476;
struct sbool  var1477;
struct sbool  var1478;
struct sbool  var1479;
struct sbool  var1480;
struct sbool  var1481;
struct sbool  var1482 = {0,0};
struct sbool  var1483;
struct sbool  var1484;
struct sbool  var1485;
struct sbool  var1486;
struct sbool  var1487;
struct sbool  var1488;
struct sbool  var1489;
struct sfloat  var1490;
struct sbool  var1491;
struct sbool  var1492;
struct sbool  var1493;
struct sbool  var1494;
struct sbool  var1495;
struct sbool  var1496;
struct sbool  var1497;
struct sbool  var1498;
struct sbool  var1499;
struct sbool  var1500;
struct sbool  var1501;
struct sbool  var1502;
struct sbool  var1503;
struct sbool  var1504 = {0,0};
struct sbool  var1505 = {0,0};
struct sbool  var1506;
struct sbool  var1507;
struct sbool  var1508 = {0,0};
struct sbool  var1509 = {0,0};
struct sbool  var1510 = {0,0};
struct sbool  var1511 = {0,0};
struct sbool  var1512;
struct sbool  var1513;
struct sbool  var1514;
struct sbool  var1515 = {0,0};
struct sbool  var1516 = {0,0};
struct sbool  var1517;
struct sbool  var1518;
struct sbool  var1519;
struct sbool  var1520;
struct sbool  var1521;
struct sbool  var1522;
struct sbool  var1523;
struct sbool  var1524;
struct sbool  var1525;
struct sbool  var1526;
struct sbool  var1527;
struct sint  var1528;
struct sbool  var1529;
struct sbool  var1530;
struct sbool  var1531;
struct sbool  var1532;
struct sbool  var1533;
struct sbool  var1534;
struct sbool  var1535;
struct sbool  var1536;
struct sint  var1537;
struct sbool  var1538;
struct sbool  var1539;
struct sbool  var1540;
struct sbool  var1541;
struct sbool  var1542;
struct sbool  var1543;
struct sbool  var1544;
struct sbool  var1545;
struct sint  var1546;
struct sbool  var1547;
struct sbool  var1548;
struct sbool  var1549;
struct sbool  var1550;
struct sbool  var1551;
struct sbool  var1552;
struct sbool  var1553;
struct sbool  var1554;
struct sint  var1555;
struct sbool  var1556;
struct sbool  var1557;
struct sbool  var1558 = {0,0};
struct sbool  var1559;
struct sbool  var1560;
struct sbool  var1561;
struct sbool  var1562;
struct sbool  var1563;
struct sint  var1564;
struct sbool  var1565;
struct sbool  var1566;
struct sbool  var1567;
struct sbool  var1568;
struct sbool  var1569;
struct sbool  var1570;
struct sbool  var1571;
struct sbool  var1572;
struct sint  var1573;
struct sbool  var1574;
struct sbool  var1575;
struct sbool  var1576;
struct sbool  var1577;
struct sbool  var1578;
struct sbool  var1579;
struct sbool  var1580;
struct sbool  var1581;
struct sint  var1582;
struct sbool  var1583;
struct sbool  var1584;
struct sbool  var1585;
struct sbool  var1586;
struct sbool  var1587 = {0,0};
struct sbool  var1588;
struct sbool  var1589;
struct sbool  var1590;
struct sbool  var1591;
struct sbool  var1592;
struct sbool  var1593;
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
struct sfloat  var1619;
struct sbool  var1620;
struct sbool  var1621;
struct sbool  var1622;
struct sbool  var1623;
struct sbool  var1624;
struct sbool  var1625;
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
struct sfloat  var1654;
struct sfloat  var1655;
struct sbool  var1656;
struct sbool  var1657;
struct sbool  var1658;
struct sbool  var1659;
struct sbool  var1660;
struct sbool  var1661;
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
struct sfloat  var1682;
struct sbool  var1683;
struct sbool  var1684;
struct sfloat  var1685;
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
struct sbool  var1703;
struct sfloat  var1704;
struct sbool  var1705;
struct sbool  var1706;
struct sbool  var1707;
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
psbool  array_m242_x_2[6] = {&var1666,&var1658,&var1672,NULL,NULL,&var1617};
psbool  array_m232_x_2[6] = {&var1667,&var1660,&var1673,NULL,NULL,&var1617};
psbool  array_m255_x_2[6] = {&var1651,NULL,NULL,&var1622,&var1621,&var1620};
psbool  array_m234_x_2[6] = {&var1652,NULL,NULL,&var1625,&var1624,&var1623};
psbool  array_m124_x_2[8] = {&var1684,&var1706,&var1702,&var1699,&var1696,&var1693,&var1687,&var1690};
psbool  array_m789_x_1[6] = {&var557,&var1198,&var1174,&var1160,&var963,&var21};
psbool  array_m1174_x_1[6] = {&var556,&var1178,&var1164,&var1200,&var963,&var44};
psbool  array_m582_x_1[6] = {&var752,&var1062,&var1485,&var1023,&var1444,&var1056};
psbool  array_m581_x_1[6] = {&var752,&var1063,&var1485,&var1023,&var1444,&var1055};
psfloat  array_m2153_a_1[6] = {NULL,NULL,NULL,NULL,NULL,NULL};
psfloat  array_m2153_b_1[6] = {NULL,NULL,NULL,NULL,NULL,NULL};
psfloat  array_m2165_x_1[4] = {NULL,NULL,NULL,NULL};
psfloat  array_m2187_x_1[2] = {NULL,NULL};
psbool  array_m2156_x_1[14] = {&var138,&var111,&var786,&var172,&var174,&var109,&var1607,&var1187,&var1185,&var1618,&var137,&var126,&var122,&var146};
psbool  array_m1_x_1[47] = {&var1147,&var339,&var275,&var863,&var425,&var1354,&var675,NULL,&var589,NULL,&var648,NULL,&var883,NULL,&var702,NULL,&var881,&var1381,NULL,&var332,&var1181,&var1070,&var1068,&var981,&var795,NULL,&var362,&var403,&var1225,&var1535,NULL,&var532,&var523,&var472,NULL,NULL,&var244,&var1221,&var436,&var193,&var1586,&var1544,&var1571,&var902,&var1558,NULL,&var112};
psfloat  array_m1440_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psbool  array_m1394_x_1[5] = {&var532,&var531,&var530,&var529,&var528};
psbool  array_m540_x_1[14] = {&var700,&var706,&var707,&var698,&var699,&var885,&var886,&var866,&var865,&var696,&var694,&var702,&var695,&var166};
psfloat  array_m81_x_1[2] = {NULL,NULL};
psfloat  array_m83_x_1[8] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
psfloat  array_m1049_x_1[2] = {NULL,NULL};
psfloat  array_m1181_x_1[8] = {&var1446,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m797_x_1[8] = {&var1405,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m879_x_1[8] = {&var1296,&var135,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m1281_x_1[8] = {&var1264,&var134,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m482_x_1[8] = {&var1325,&var266,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m159_x_1[8] = {&var1358,&var270,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m320_Tpr_1[10] = {&fRM_6_0,&fRM_126_0,&fRM_246_0,&fRM_366_0,&fRM_486_0,&fRM_606_0,&fRM_726_0,&fRM_846_0,&fRM_966_0,&fRM_1200_0};
pschar  array_m320_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m320_rz_1[10];
psbool  array_m324_x_1[5] = {&var1011,&var1012,&var1013,&var1014,&var1015};
psbool  array_m259_x_1[7] = {&var786,&var168,&var990,&var987,&var174,&var172,&var170};
psfloat  array_m263_Tpr_1[10] = {&fRM_10_0,&fRM_30_0,&fRM_50_0,&fRM_70_0,&fRM_90_0,&fRM_110_0,&fRM_130_0,&fRM_150_0,&fRM_170_0,&fRM_200_0};
pschar  array_m263_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m263_rz_1[10];
psfloat  array_m1383_Tpr_1[6] = {&fRM_0_5,&fRM_3_5,&fRM_6_5,&fRM_9_5,&fRM_12_5,&fRM_15_5};
pschar  array_m1383_type_1[6] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_6_};
pschar  array_m1383_rz_1[6];
psbool  array_m279_x_1[5] = {&var1033,&var1034,&var1035,&var1036,&var1037};
psbool  array_m1158_x_1[6] = {&var1159,&var769,&var1517,&var1167,&var1163,&var184};
psbool  array_m1146_x_1[5] = {&var1067,&var1109,&var1161,&var1165,&var983};
psfloat  array_m1424_x_1[16] = {&var367,&var376,&fRM_0_,&var373,&fRM_0_,&fRM_0_,&fRM_0_,&var370,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&var380};
psbool  array_m1730_x_1[17] = {&var447,&var448,&var454,&var449,&var445,&var446,&var920,&var450,&var451,&var1214,&var452,&var453,&var1206,&var1207,&var1216,&var178,&var179};
psbool  array_m1386_x_1[5] = {&var359,&var496,&var513,&var514,&var389};
psint  array_m298_x_1[3] = {&var1009,&iRM_0_,&var1031};
psint  array_m289_x_1[3] = {&var1008,&iRM_0_,&var1030};
psbool  array_m584_x_1[5] = {&var735,&var1484,&var1251,&var964,&var144};
psbool  array_m1345_x_1[8] = {&var619,&var620,&var621,&var616,&var615,&var614,&var881,&var612};
psbool  array_m1280_x_1[3] = {&var23,&lRM_0_,&var22};
psfloat  array_m1282_Lt_fw_1[1] = {NULL};
psint  array_m1282_Vr_fw_1[1] = {NULL};
psfloat  array_m1282_Lt_bw_1[1] = {NULL};
psint  array_m1282_Vr_bw_1[1] = {NULL};
psfloat  array_m1310_x0_1[60];
psfloat  array_m1310_tim0_1[60];
psbool  array_m948_x_1[8] = {&var634,&var636,&var637,&var629,&var635,&var631,&var883,&var348};
psbool  array_m878_x_1[3] = {&var52,&lRM_0_,&var47};
psfloat  array_m880_Lt_fw_1[1] = {NULL};
psint  array_m880_Vr_fw_1[1] = {NULL};
psfloat  array_m880_Lt_bw_1[1] = {NULL};
psint  array_m880_Vr_bw_1[1] = {NULL};
psfloat  array_m913_x0_1[60];
psfloat  array_m913_tim0_1[60];
psbool  array_m481_x_1[3] = {&var711,&lRM_0_,&var712};
psfloat  array_m484_Lt_fw_1[2] = {NULL,NULL};
psint  array_m484_Vr_fw_1[2] = {NULL,NULL};
psfloat  array_m484_Lt_bw_1[1] = {NULL};
psint  array_m484_Vr_bw_1[1] = {NULL};
psfloat  array_m511_x0_1[150];
psfloat  array_m511_tim0_1[150];
psbool  array_m223_x_1[12] = {&var680,&var682,&var681,&var678,&var676,&var675,&var674,&var889,&var888,&var669,&var672,&var167};
psbool  array_m158_x_1[3] = {&var858,&lRM_0_,&var859};
psfloat  array_m163_Lt_fw_1[2] = {NULL,NULL};
psint  array_m163_Vr_fw_1[2] = {NULL,NULL};
psfloat  array_m163_Lt_bw_1[1] = {NULL};
psint  array_m163_Vr_bw_1[1] = {NULL};
psfloat  array_m192_x0_1[150];
psfloat  array_m192_tim0_1[150];
psbool  array_m853_x_1[10] = {&var646,&var647,&var653,&var654,&var652,&var650,&var649,&var891,&var890,&var648};
psbool  array_m796_x_1[3] = {&var25,&var664,&var24};
psfloat  array_m800_Lt_fw_1[2] = {NULL,NULL};
psint  array_m800_Vr_fw_1[2] = {NULL,NULL};
psfloat  array_m800_Lt_bw_1[1] = {NULL};
psint  array_m800_Vr_bw_1[1] = {NULL};
psfloat  array_m820_x0_1[80];
psfloat  array_m820_tim0_1[80];
psfloat  array_m1564_Lt_fw_1[1] = {&fRM_1000_};
psint  array_m1564_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1564_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1564_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1255_x_1[10] = {&var585,&var586,&var588,&var587,&var589,&var591,&var593,&var590,&var592,&var594};
psbool  array_m141_x_1[5] = {NULL,NULL,NULL,&var906,&var905};
psfloat  array_m1100_Lt_fw_1[1] = {&fRM_2000_};
psint  array_m1100_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1100_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1100_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1184_x_1[3] = {&var57,&var579,&var43};
psfloat  array_m1185_Lt_fw_1[2] = {NULL,NULL};
psint  array_m1185_Vr_fw_1[2] = {NULL,NULL};
psfloat  array_m1185_Lt_bw_1[1] = {NULL};
psint  array_m1185_Vr_bw_1[1] = {NULL};
psfloat  array_m1219_x0_1[80];
psfloat  array_m1219_tim0_1[80];
psfloat  array_m1584_x0_1[20];
psfloat  array_m1584_tim0_1[20];
psbool  array_m1071_x_1[8] = {&var796,&var793,&var794,&var795,&var792,&var791,&var790,&var789};
psbool  array_m585_x_1[18] = {NULL,&var486,&var810,&var488,&var808,&var580,&var715,&var663,&var690,&var710,&var639,&var604,&var867,&var287,&var286,&var570,&var200,&var136};
psfloat  array_m1124_x0_1[20];
psfloat  array_m1124_tim0_1[20];
psbool  array_m425_x_1[7] = {&var912,&var911,&var910,&var909,&var1588,&var901,&var316};
psbool  array_m407_x_1[7] = {&var914,&var1588,&var902,&var915,&var913,&var900,&var82};
psbool  array_m753_x_1[17] = {&var811,&var856,&var855,&var852,&var851,&var848,&var813,&var850,&var818,&var847,&var843,&var845,&var844,&var815,&var809,&var899,&var666};
psbool  array_m127_x_1[21] = {&var689,&var709,&var955,&var662,&var954,&var953,&var1522,&var1531,&var1549,&var1540,&var1576,&var1567,&var425,&var317,&var945,&var946,&var1228,&var1222,&var1386,&var1377,&var1558};

/* описания структур для ф-ий */

/* код алгоблоков */
/* Объявление структур */
_S_and4 far S_and4_106_2 = {&var1703,&var1638,NULL,NULL,&var1608};
_S_lkb far S_lkb_111_2 = {&lRM_1_,&var1636,&var1609};
_S_lkb far S_lkb_107_2 = {&lRM_1_,&var1608,&var1610};
_S_lkb far S_lkb_80_2 = {&lRM_1_,&var1639,&var1611};
_S_lkb far S_lkb_50_2 = {&lRM_1_,&var1644,&var1612};
_S_lkb far S_lkb_83_2 = {&lRM_1_,&var1642,&var1613};
_S_lkb far S_lkb_46_2 = {&lRM_1_,&var1648,&var1614};
_S_lkb far S_lkb_24_2 = {&lRM_1_,&var1646,&var1615};
_S_lkb far S_lkb_20_2 = {&lRM_1_,&var1650,&var1616};
_S_or2 far S_or2_258_2 = {&var1707,&var1656,&var1617};
_S_bol far S_bol_223_2 = {&fRM_0_5,&var1619,&var1618};
_S_fsumo far S_fsumo_222_2 = {&var1655,&var1654,&var1619};
_S_noto far S_noto_251_2 = {NULL,&var1620};
_S_noto far S_noto_250_2 = {NULL,&var1621};
_S_noto far S_noto_249_2 = {NULL,&var1622};
_S_noto far S_noto_231_2 = {NULL,&var1623};
_S_noto far S_noto_230_2 = {NULL,&var1624};
_S_noto far S_noto_229_2 = {NULL,&var1625};
_S_schl24 far S_schl24_149_2 = {NULL,NULL,NULL,NULL,&var1626};
_S_schl24 far S_schl24_143_2 = {NULL,NULL,NULL,NULL,&var1627};
_S_or2 far S_or2_198_2 = {&var1676,&var1677,&var1628};
_S_or2 far S_or2_195_2 = {&var1679,&var1680,&var1629};
_S_and2 far S_and2_213_2 = {&var1664,&var1675,&var1630};
_S_or2 far S_or2_243_2 = {&var1671,&var1670,&var1631};
_S_and4 far S_and4_159_2 = {NULL,NULL,NULL,NULL,&var1632};
_S_or3 far S_or3_158_2 = {&var1632,&var774,&var1626,&var1633};
_S_and4 far S_and4_136_2 = {NULL,NULL,NULL,NULL,&var1634};
_S_or3 far S_or3_135_2 = {&var1634,&var1627,&var774,&var1635};
_S_and3 far S_and3_110_2 = {&var1637,&var1703,NULL,&var1636};
_S_or2 far S_or2_104_2 = {NULL,NULL,&var1637};
_S_or2 far S_or2_103_2 = {NULL,NULL,&var1638};
_S_and3 far S_and3_79_2 = {&var1703,NULL,&var1640,&var1639};
_S_or2 far S_or2_71_2 = {NULL,NULL,&var1640};
_S_or2 far S_or2_74_2 = {NULL,NULL,&var1641};
_S_and3 far S_and3_82_2 = {&var1703,&var1641,NULL,&var1642};
_S_or2 far S_or2_43_2 = {NULL,NULL,&var1643};
_S_and3 far S_and3_49_2 = {&var1703,NULL,&var1643,&var1644};
_S_or2 far S_or2_13_2 = {NULL,NULL,&var1645};
_S_and3 far S_and3_23_2 = {&var1645,&var1703,NULL,&var1646};
_S_or2 far S_or2_42_2 = {NULL,NULL,&var1647};
_S_and3 far S_and3_45_2 = {&var1703,NULL,&var1647,&var1648};
_S_or2 far S_or2_11_2 = {NULL,NULL,&var1649};
_S_and3 far S_and3_19_2 = {&var1703,NULL,&var1649,&var1650};
_S_and2 far S_and2_254_2 = {NULL,&var1628,&var1651};
_S_and2 far S_and2_233_2 = {NULL,&var1629,&var1652};
_S_and2 far S_and2_219_2 = {&var1665,&var1674,&var1653};
_S_scalzz far S_scalzz_187_2 = {NULL,&iRM_819_,&iRM_4095_,NULL,NULL,&var1654,NULL};
_S_scalzz far S_scalzz_185_2 = {NULL,&iRM_819_,&iRM_4095_,NULL,NULL,&var1655,NULL};
_S_noto far S_noto_171_2 = {&var1657,&var1656};
_S_andn far S_andn_170_2 = {array_m170_x_2,&iRM_17_,&var1657};
_S_noto far S_noto_153_2 = {&var1659,&var1658};
_S_andn far S_andn_150_2 = {array_m150_x_2,&iRM_6_,&var1659};
_S_noto far S_noto_134_2 = {&var1661,&var1660};
_S_andn far S_andn_131_2 = {array_m131_x_2,&iRM_6_,&var1661};
_S_noto far S_noto_253_2 = {&var1670,&var1662};
_S_noto far S_noto_235_2 = {&var1671,&var1663};
_S_noto far S_noto_212_2 = {&var1679,&var1664};
_S_noto far S_noto_220_2 = {&var1676,&var1665};
_S_noto far S_noto_157_2 = {&var1633,&var1666};
_S_noto far S_noto_141_2 = {&var1635,&var1667};
_S_noto far S_noto_256_2 = {&var1672,&var1668};
_S_noto far S_noto_240_2 = {&var1673,&var1669};
_S_ornc far S_ornc_242_2 = {array_m242_x_2,&iRM_6_,&var1670,&vainSChar};
_S_ornc far S_ornc_232_2 = {array_m232_x_2,&iRM_6_,&var1671,&vainSChar};
_S_ornc far S_ornc_255_2 = {array_m255_x_2,&iRM_6_,&var1672,&vainSChar};
_S_ornc far S_ornc_234_2 = {array_m234_x_2,&iRM_6_,&var1673,&vainSChar};
_S_tprg far S_tprg_214_2 = {&var1654,NULL,NULL,NULL,NULL,&var1674,NULL};
_S_tprg far S_tprg_210_2 = {&var1655,NULL,NULL,NULL,NULL,&var1675,NULL};
_S_geterr far S_geterr_191_2 = {&var1654,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1676};
_S_drg far S_drg_199_2 = {&var1654,&lRM_1_,&lRM_0_,NULL,NULL,&var1677,NULL};
_S_drg far S_drg_204_2 = {&var1654,&lRM_1_,&lRM_0_,NULL,NULL,&var1678,NULL};
_S_geterr far S_geterr_188_2 = {&var1655,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1679};
_S_drg far S_drg_189_2 = {&var1655,&lRM_1_,&lRM_0_,NULL,NULL,&var1680,NULL};
_S_drg far S_drg_196_2 = {&var1655,&lRM_1_,&lRM_0_,NULL,NULL,&var1681,NULL};
_S_enctkb far S_enctkb_16_2 = {&var1615,&fRM_0_0,NULL,NULL,NULL,NULL,&fRM_100_0,&dRM_0_,&var1682,&var1683,&var1684,NULL,NULL,NULL};
_S_enctkb far S_enctkb_108_2 = {&var1610,&fRM_390_,NULL,NULL,NULL,NULL,&fRM_1500_0,&dRM_0_,&var1685,&var1686,&var1687,NULL,NULL,NULL};
_S_enctkb far S_enctkb_112_2 = {&var1609,&fRM_390_0,NULL,NULL,NULL,NULL,&fRM_1500_0,&dRM_0_,&var1688,&var1689,&var1690,NULL,NULL,NULL};
_S_enctkb far S_enctkb_75_2 = {&var1611,&fRM_0_,NULL,NULL,NULL,NULL,&fRM_0_0,&dRM_0_,&var1691,&var1692,&var1693,NULL,NULL,NULL};
_S_enctkb far S_enctkb_77_2 = {&var1613,&fRM_0_0,NULL,NULL,NULL,NULL,&fRM_0_0,&dRM_0_,&var1694,&var1695,&var1696,NULL,NULL,NULL};
_S_enctkb far S_enctkb_47_2 = {&var1614,&fRM_0_0,NULL,NULL,NULL,NULL,&fRM_100_0,&dRM_0_,&var1697,&var1698,&var1699,NULL,NULL,NULL};
_S_enctkb far S_enctkb_51_2 = {&var1612,&fRM_0_0,NULL,NULL,NULL,NULL,&fRM_100_0,&dRM_0_,&var1700,&var1701,&var1702,NULL,NULL,NULL};
_S_equz_p far S_equz_p_18_2 = {NULL,&iRM_4_,&var1703};
_S_enctkb far S_enctkb_21_2 = {&var1616,&fRM_0_0,NULL,NULL,NULL,NULL,&fRM_100_0,&dRM_0_,&var1704,&var1705,&var1706,NULL,NULL,NULL};
_S_ornc far S_ornc_124_2 = {array_m124_x_2,&iRM_8_,&var1707,&vainSChar};
_S_noto far S_noto_2095_1 = {NULL,&var1};
_S_noto far S_noto_2121_1 = {NULL,&var2};
_S_and2 far S_and2_2022_1 = {&var421,&var1147,&var3};
_S_or3 far S_or3_2017_1 = {&var420,&var112,&var48,&var4};
_S_and2 far S_and2_2007_1 = {&var417,&var1147,&var5};
_S_or3 far S_or3_2003_1 = {&var112,&var418,&var28,&var6};
_S_and3 far S_and3_2079_1 = {&var1168,&var244,NULL,&var7};
_S_and3 far S_and3_2105_1 = {&var1168,&var245,NULL,&var8};
_S_or2 far S_or2_1443_1 = {&var1239,&var1168,&var9};
_S_or2 far S_or2_1412_1 = {&var1092,&var1168,&var10};
_S_rs far S_rs_2088_1 = {&var7,&var14,&var11,&vainSBool,NULL};
_S_rs far S_rs_2072_1 = {&var7,&var33,&var12,&vainSBool,NULL};
_S_noto far S_noto_2092_1 = {NULL,&var13};
_S_and2 far S_and2_2078_1 = {&var13,&var12,&var14};
_S_rs far S_rs_2114_1 = {&var8,&var17,&var15,&vainSBool,NULL};
_S_noto far S_noto_2118_1 = {NULL,&var16};
_S_and2 far S_and2_2104_1 = {&var18,&var16,&var17};
_S_rs far S_rs_2098_1 = {&var8,&var54,&var18,&vainSBool,NULL};
_S_and4 far S_and4_1333_1 = {&var920,&var1168,&var204,&var1213,&var19};
_S_and4 far S_and4_936_1 = {&var920,&var1168,&var204,&var1213,&var20};
_S_rs far S_rs_2091_1 = {&var186,&var26,&var21,&vainSBool,NULL};
_S_or4 far S_or4_1270_1 = {&var555,&var229,&var959,&var28,&var22};
_S_or4 far S_or4_1279_1 = {&var101,&var233,&var731,&var35,&var23};
_S_orn far S_orn_789_1 = {array_m789_x_1,&iRM_6_,&var24};
_S_or3 far S_or3_801_1 = {&var750,&var1162,&var39,&var25};
_S_and2 far S_and2_2081_1 = {&var193,&var27,&var26};
_S_rs far S_rs_2074_1 = {&var26,&var29,&var27,&vainSBool,NULL};
_S_rs far S_rs_2090_1 = {&var193,&var29,&var28,&vainSBool,NULL};
_S_and2 far S_and2_2080_1 = {&var30,&var1,&var29};
_S_rs far S_rs_2073_1 = {&var29,&var7,&var30,&vainSBool,NULL};
_S_rs far S_rs_2071_1 = {&var40,&var36,&var31,&vainSBool,NULL};
_S_rs far S_rs_2070_1 = {&var34,&var37,&var32,&vainSBool,NULL};
_S_and2 far S_and2_2077_1 = {&var193,&var31,&var33};
_S_or2 far S_or2_2085_1 = {&var244,&var193,&var34};
_S_rs far S_rs_2084_1 = {&var34,&var36,&var35,&vainSBool,NULL};
_S_and2 far S_and2_2076_1 = {&var32,&var186,&var36};
_S_and2 far S_and2_2075_1 = {&var247,&var1168,&var37};
_S_or2 far S_or2_2083_1 = {&var244,&var186,&var38};
_S_rs far S_rs_2082_1 = {&var38,&var37,&var39,&vainSBool,NULL};
_S_or2 far S_or2_2087_1 = {&var13,&var244,&var40};
_S_rs far S_rs_2089_1 = {&var1,&var7,&var41,&vainSBool,NULL};
_S_rs far S_rs_2086_1 = {&var40,&var33,&var42,&vainSBool,NULL};
_S_orn far S_orn_1174_1 = {array_m1174_x_1,&iRM_6_,&var43};
_S_rs far S_rs_2117_1 = {&var186,&var45,&var44,&vainSBool,NULL};
_S_and2 far S_and2_2107_1 = {&var193,&var46,&var45};
_S_rs far S_rs_2100_1 = {&var45,&var49,&var46,&vainSBool,NULL};
_S_or4 far S_or4_868_1 = {&var554,&var234,&var959,&var48,&var47};
_S_rs far S_rs_2116_1 = {&var193,&var49,&var48,&vainSBool,NULL};
_S_and2 far S_and2_2106_1 = {&var50,&var2,&var49};
_S_rs far S_rs_2099_1 = {&var49,&var8,&var50,&vainSBool,NULL};
_S_rs far S_rs_2097_1 = {&var458,&var58,&var51,&vainSBool,NULL};
_S_or4 far S_or4_877_1 = {&var1158,&var101,&var741,&var56,&var52};
_S_rs far S_rs_2096_1 = {&var55,&var59,&var53,&vainSBool,NULL};
_S_and2 far S_and2_2103_1 = {&var193,&var51,&var54};
_S_or2 far S_or2_2111_1 = {&var193,&var245,&var55};
_S_rs far S_rs_2110_1 = {&var55,&var58,&var56,&vainSBool,NULL};
_S_or3 far S_or3_1186_1 = {&var749,&var1166,&var61,&var57};
_S_and2 far S_and2_2102_1 = {&var53,&var186,&var58};
_S_and2 far S_and2_2101_1 = {&var248,&var1168,&var59};
_S_or2 far S_or2_2109_1 = {&var186,&var245,&var60};
_S_rs far S_rs_2108_1 = {&var60,&var59,&var61,&vainSBool,NULL};
_S_or2 far S_or2_1989_1 = {&var103,&var991,&var62};
_S_ovbs far S_ovbs_1991_1 = {&var162,&fRM_2_0,&var63,NULL};
_S_or2 far S_or2_1992_1 = {&var1177,&var63,&var64};
_S_ovbs far S_ovbs_1970_1 = {&var163,&fRM_2_0,&var65,NULL};
_S_or2 far S_or2_1968_1 = {&var104,&var992,&var66};
_S_or2 far S_or2_1971_1 = {&var1197,&var65,&var67};
_S_noto far S_noto_1638_1 = {NULL,&var68};
_S_noto far S_noto_1632_1 = {NULL,&var69};
_S_and2 far S_and2_2042_1 = {NULL,&var422,&var70};
_S_or5 far S_or5_2045_1 = {&var612,&var1607,&var87,&var41,&var70,&var71};
_S_or5 far S_or5_2044_1 = {&var348,&var1156,&var424,&var1607,NULL,&var72};
_S_and2 far S_and2_2019_1 = {NULL,&var423,&var73};
_S_nocnm far S_nocnm_1683_1 = {NULL,NULL,&var74,&var75,&var76,NULL,NULL,NULL,NULL};
_S_nocnm far S_nocnm_1680_1 = {NULL,NULL,&var77,&var78,&var79,NULL,NULL,NULL,NULL};
_S_or5 far S_or5_1939_1 = {&var955,&var662,NULL,&var954,&var953,&var80};
_S_or4 far S_or4_1915_1 = {NULL,NULL,&var689,&var709,&var81};
_S_and3 far S_and3_403_1 = {NULL,NULL,&var1580,&var82};
_S_and2 far S_and2_2005_1 = {&var416,&var112,&var83};
_S_and2 far S_and2_2016_1 = {&var419,&var112,&var84};
_S_or4 far S_or4_968_1 = {&var1286,&var624,&var623,&var626,&var85};
_S_or4 far S_or4_1365_1 = {&var1254,&var605,&var606,&var609,&var86};
_S_and2 far S_and2_2046_1 = {&var337,&var1147,&var87};
_S_and2 far S_and2_2031_1 = {&var422,&var1607,&var88};
_S_and2 far S_and2_2020_1 = {&var423,&var1607,&var89};
_S_or2 far S_or2_542_1 = {NULL,NULL,&var90};
_S_or2 far S_or2_225_1 = {NULL,NULL,&var91};
_S_or2 far S_or2_1102_1 = {NULL,NULL,&var92};
_S_or2 far S_or2_1097_1 = {NULL,NULL,&var93};
_S_or2 far S_or2_344_1 = {NULL,NULL,&var94};
_S_or2 far S_or2_361_1 = {NULL,NULL,&var95};
_S_or2 far S_or2_1056_1 = {&var962,NULL,&var96};
_S_or2 far S_or2_1059_1 = {&var960,NULL,&var97};
_S_or2 far S_or2_1062_1 = {&var958,NULL,&var98};
_S_or2 far S_or2_1065_1 = {&var956,NULL,&var99};
_S_noto far S_noto_2144_1 = {&var1607,&var100};
_S_zzfs far S_zzfs_2133_1 = {&var118,&fRM_0_5,&var101,NULL,NULL};
_S_or2 far S_or2_2167_1 = {&var298,&var964,&var102};
_S_andn far S_andn_582_1 = {array_m582_x_1,&iRM_6_,&var103};
_S_andn far S_andn_581_1 = {array_m581_x_1,&iRM_6_,&var104};
_S_or2 far S_or2_2183_1 = {&var639,&var604,&var105};
_S_noto far S_noto_2129_1 = {&var990,&var106};
_S_noto far S_noto_2128_1 = {&var987,&var107};
_S_zpfs far S_zpfs_2137_1 = {&var106,&fRM_30_0,&var108,NULL,NULL};
_S_noto far S_noto_2142_1 = {&var108,&var109};
_S_zpfs far S_zpfs_2136_1 = {&var107,&fRM_30_0,&var110,NULL,NULL};
_S_noto far S_noto_2141_1 = {&var110,&var111};
_S_and3 far S_and3_2135_1 = {&var151,&var131,&lRM_1_,&var112};
_S_and2 far S_and2_896_1 = {&var1312,&var114,&var113};
_S_noto far S_noto_883_1 = {&var101,&var114};
_S_and2 far S_and2_1296_1 = {&var1280,&var116,&var115};
_S_noto far S_noto_1293_1 = {&var101,&var116};
_S_or2 far S_or2_2177_1 = {&var127,&var128,&var117};
_S_and2 far S_and2_2132_1 = {&var119,&var112,&var118};
_S_abs_subf far S_abs_subf_2124_1 = {&var1694,&var152,NULL,&vainSFloat,&var119};
_S_and2 far S_and2_2179_1 = {&var112,&var127,&var120};
_S_or4 far S_or4_1940_1 = {&var80,&var767,&var878,&var120,&var121};
_S_noto far S_noto_2182_1 = {&var105,&var122};
_S_or2 far S_or2_2158_1 = {&var145,&var156,&var123};
_S_inf far S_inf_2153_1 = {&var154,array_m2153_a_1,array_m2153_b_1,&iRM_6_,&var124,&vainSInt};
_S_or3 far S_or3_2181_1 = {&var141,&var148,&var149,&var125};
_S_noto far S_noto_2180_1 = {&var125,&var126};
_S_noto far S_noto_2178_1 = {&var151,&var127};
_S_ovbs far S_ovbs_2173_1 = {&var130,&fRM_15_0,&var128,NULL};
_S_zpfs far S_zpfs_2171_1 = {&var131,&fRM_10_0,&var129,NULL,NULL};
_S_and2 far S_and2_2172_1 = {&var129,NULL,&var130};
_S_rs far S_rs_2176_1 = {&var117,NULL,&var131,&vainSBool,NULL};
_S_rs far S_rs_2143_1 = {&var145,&var112,&var132,&vainSBool,NULL};
_S_and3 far S_and3_2150_1 = {&var147,&var100,&var132,&var133};
_S_ml far S_ml_1274_1 = {&var152,&var258,&var101,&var134};
_S_ml far S_ml_874_1 = {&var152,&var262,&var101,&var135};
_S_and2 far S_and2_2197_1 = {&var112,&var275,&var136};
_S_noto far S_noto_2164_1 = {&var102,&var137};
_S_noto far S_noto_2148_1 = {&var1251,&var138};
_S_sr far S_sr_2165_1 = {array_m2165_x_1,&iRM_4_,&var139};
_S_sr far S_sr_2187_1 = {array_m2187_x_1,&iRM_2_,&var140};
_S_and2 far S_and2_2201_1 = {&var142,&var112,&var141};
_S_abs_subf far S_abs_subf_2196_1 = {NULL,NULL,&fRM_0_01,&vainSFloat,&var142};
_S_fsumo far S_fsumo_79_1 = {&var940,NULL,&var143};
_S_or3 far S_or3_124_1 = {&var81,&var863,&var123,&var144};
_S_ovbs far S_ovbs_2151_1 = {&var133,&fRM_1_0,&var145,NULL};
_S_noto far S_noto_2157_1 = {&var123,&var146};
_S_rs far S_rs_2149_1 = {&var145,&var1607,&var147,&vainSBool,NULL};
_S_and2 far S_and2_2200_1 = {&var156,&var112,&var148};
_S_and2 far S_and2_2199_1 = {&var150,&var112,&var149};
_S_bol far S_bol_2188_1 = {NULL,&var140,&var150};
_S_andn far S_andn_2156_1 = {array_m2156_x_1,&iRM_14_,&var151};
_S_irm far S_irm_2131_1 = {&var940,&var938,NULL,&var1694,&var140,&var139,&var112,NULL,NULL,NULL,NULL,&var124,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&var152,&var153,&var154,&var155,&var156,&var157,&var158,&var159};
_S_noto far S_noto_1997_1 = {&var286,&var160};
_S_noto far S_noto_1967_1 = {&var287,&var161};
_S_and4 far S_and4_1990_1 = {&var309,&var62,&var279,&var160,&var162};
_S_and4 far S_and4_1969_1 = {&var310,&var66,&var279,&var161,&var163};
_S_zpfs far S_zpfs_1985_1 = {&var293,&fRM_210_0,&var164,NULL,NULL};
_S_zpfs far S_zpfs_1977_1 = {&var294,&fRM_210_0,&var165,NULL,NULL};
_S_and2 far S_and2_545_1 = {&var1327,&var342,&var166};
_S_and2 far S_and2_228_1 = {&var342,&var1360,&var167};
_S_noto far S_noto_1531_1 = {&var169,&var168};
_S_abs_subf far S_abs_subf_1524_1 = {&var1691,&var258,NULL,&vainSFloat,&var169};
_S_noto far S_noto_1511_1 = {&var171,&var170};
_S_abs_subf far S_abs_subf_1505_1 = {&var262,&var1694,NULL,&vainSFloat,&var171};
_S_noto far S_noto_1528_1 = {&var173,&var172};
_S_abs_subf far S_abs_subf_1522_1 = {&var266,&var1704,NULL,&vainSFloat,&var173};
_S_noto far S_noto_1509_1 = {&var175,&var174};
_S_abs_subf far S_abs_subf_1501_1 = {&var270,&var1682,NULL,&vainSFloat,&var175};
_S_bol far S_bol_1292_1 = {&var1691,NULL,&var176};
_S_bol far S_bol_893_1 = {&var1694,NULL,&var177};
_S_noto far S_noto_1742_1 = {&var182,&var178};
_S_noto far S_noto_1731_1 = {&var180,&var179};
_S_and3 far S_and3_1724_1 = {&var872,&var181,&var1168,&var180};
_S_bol far S_bol_1716_1 = {&fRM_55_0,&var258,&var181};
_S_and3 far S_and3_1743_1 = {&var183,&var871,&var1168,&var182};
_S_bol far S_bol_1752_1 = {&fRM_55_0,&var262,&var183};
_S_and4 far S_and4_45_1 = {&var1598,&var870,&var1049,&var1147,&var184};
_S_noto far S_noto_1207_1 = {&var920,&var185};
_S_and2 far S_and2_1213_1 = {&var1427,&var920,&var186};
_S_and2 far S_and2_1208_1 = {&var1427,&var185,&var187};
_S_noto far S_noto_1155_1 = {&var920,&var188};
_S_and2 far S_and2_1162_1 = {&var920,&var1501,&var189};
_S_and2 far S_and2_1156_1 = {&var1501,&var188,&var190};
_S_noto far S_noto_902_1 = {&var920,&var191};
_S_and2 far S_and2_903_1 = {&var191,&var1283,&var192};
_S_and2 far S_and2_899_1 = {&var1283,&var920,&var193};
_S_noto far S_noto_457_1 = {&var920,&var194};
_S_and2 far S_and2_458_1 = {&var194,&var1376,&var195};
_S_and2 far S_and2_460_1 = {&var1376,&var920,&var196};
_S_noto far S_noto_185_1 = {&var920,&var197};
_S_and2 far S_and2_186_1 = {&var197,&var1346,&var198};
_S_and2 far S_and2_189_1 = {&var920,&var1346,&var199};
_S_and2 far S_and2_118_1 = {&var202,&var331,&var200};
_S_and2 far S_and2_119_1 = {&var920,&var331,&var201};
_S_noto far S_noto_113_1 = {&var920,&var202};
_S_and2 far S_and2_114_1 = {&var202,&var330,&var203};
_S_and2 far S_and2_115_1 = {&var920,&var330,&var204};
_S_and2 far S_and2_1603_1 = {&var244,&var1172,&var205};
_S_and2 far S_and2_1602_1 = {&var247,&var1172,&var206};
_S_and2 far S_and2_1601_1 = {&var245,&var1172,&var207};
_S_and2 far S_and2_1600_1 = {&var1172,&var248,&var208};
_S_and2 far S_and2_1599_1 = {&var479,&var246,&var209};
_S_and2 far S_and2_1598_1 = {&var479,&var249,&var210};
_S_and2 far S_and2_1597_1 = {&var480,&var246,&var211};
_S_and2 far S_and2_1596_1 = {&var480,&var249,&var212};
_S_and2 far S_and2_1627_1 = {&var68,&var1125,&var213};
_S_and2 far S_and2_1626_1 = {&var244,&var1173,&var214};
_S_and2 far S_and2_1625_1 = {&var1126,&var186,&var215};
_S_and2 far S_and2_1624_1 = {&var1173,&var247,&var216};
_S_and2 far S_and2_1623_1 = {&var69,&var1127,&var217};
_S_and2 far S_and2_1622_1 = {&var1173,&var245,&var218};
_S_and2 far S_and2_1621_1 = {&var1128,&var186,&var219};
_S_and2 far S_and2_1620_1 = {&var1173,&var248,&var220};
_S_and2 far S_and2_1653_1 = {&var186,&var1129,&var221};
_S_and2 far S_and2_1652_1 = {&var244,&var1171,&var222};
_S_and2 far S_and2_1651_1 = {&var1130,&var189,&var223};
_S_and2 far S_and2_1650_1 = {&var247,&var1171,&var224};
_S_and2 far S_and2_1649_1 = {&var186,&var1131,&var225};
_S_and2 far S_and2_1648_1 = {&var245,&var1171,&var226};
_S_and2 far S_and2_1647_1 = {&var1132,&var189,&var227};
_S_and2 far S_and2_1646_1 = {&var248,&var1171,&var228};
_S_rs far S_rs_1676_1 = {&var193,&var230,&var229,&vainSBool,NULL};
_S_and2 far S_and2_1669_1 = {&var1169,&var244,&var230};
_S_and2 far S_and2_1668_1 = {&var1169,&var247,&var231};
_S_or2 far S_or2_1675_1 = {&var193,&var244,&var232};
_S_rs far S_rs_1674_1 = {&var232,&var231,&var233,&vainSBool,NULL};
_S_rs far S_rs_1673_1 = {&var193,&var235,&var234,&vainSBool,NULL};
_S_and2 far S_and2_1667_1 = {&var245,&var1169,&var235};
_S_and2 far S_and2_1666_1 = {&var1169,&var248,&var236};
_S_and2 far S_and2_1695_1 = {&var246,&var1600,&var237};
_S_rs far S_rs_1704_1 = {&var196,&var237,&var238,&vainSBool,NULL};
_S_and2 far S_and2_1694_1 = {&var1600,&var249,&var239};
_S_and2 far S_and2_1693_1 = {&var244,&var1154,&var240};
_S_and2 far S_and2_1692_1 = {&var1154,&var247,&var241};
_S_and2 far S_and2_1691_1 = {&var245,&var1154,&var242};
_S_and2 far S_and2_1690_1 = {&var1154,&var248,&var243};
_S_and2 far S_and2_1706_1 = {&var872,&var246,&var244};
_S_and2 far S_and2_1689_1 = {&var871,&var246,&var245};
_S_and2 far S_and2_1708_1 = {&var201,&var1213,&var246};
_S_and2 far S_and2_1705_1 = {&var249,&var872,&var247};
_S_and2 far S_and2_1688_1 = {&var249,&var871,&var248};
_S_and2 far S_and2_1707_1 = {&var204,&var1213,&var249};
_S_zpfs far S_zpfs_733_1 = {&var835,&fRM_3_,&var250,NULL,NULL};
_S_or4 far S_or4_1543_1 = {&var464,&var465,&var466,&var468,&var251};
_S_or5 far S_or5_1534_1 = {&var472,&var471,&var470,&var469,&var251,&var252};
_S_andn far S_andn_1_1 = {array_m1_x_1,&iRM_47_,&vainSBool};
_S_or2 far S_or2_1512_1 = {&var255,&var256,&var253};
_S_ml far S_ml_1500_1 = {&fRM_1500_0,NULL,&var253,&var254};
_S_bol far S_bol_1506_1 = {NULL,&fRM_1500_0001,&var255};
_S_bol far S_bol_1517_1 = {&fRM_389_99,NULL,&var256};
_S_or2 far S_or2_1530_1 = {&var259,&var260,&var257};
_S_ml far S_ml_1521_1 = {&fRM_0_0,NULL,&var257,&var258};
_S_bol far S_bol_1523_1 = {NULL,&fRM_160_00001,&var259};
_S_bol far S_bol_1533_1 = {&fRM_0_0001,NULL,&var260};
_S_or2 far S_or2_1510_1 = {&var263,&var264,&var261};
_S_ml far S_ml_1499_1 = {&fRM_0_0,NULL,&var261,&var262};
_S_bol far S_bol_1504_1 = {NULL,&fRM_160_0001,&var263};
_S_bol far S_bol_1515_1 = {&fRM_0_0001,NULL,&var264};
_S_or2 far S_or2_1527_1 = {&var267,&var268,&var265};
_S_ml far S_ml_1519_1 = {&fRM_100_0,NULL,&var265,&var266};
_S_bol far S_bol_1525_1 = {NULL,&fRM_100_0001,&var267};
_S_bol far S_bol_1532_1 = {&fRM_0_0001,NULL,&var268};
_S_or2 far S_or2_1508_1 = {&var271,&var272,&var269};
_S_ml far S_ml_1497_1 = {&fRM_100_0,NULL,&var269,&var270};
_S_bol far S_bol_1503_1 = {NULL,&fRM_100_0001,&var271};
_S_bol far S_bol_1513_1 = {&fRM_0_0001,NULL,&var272};
_S_and2 far S_and2_101_1 = {NULL,&var94,&var273};
_S_noto far S_noto_102_1 = {&var94,&var274};
_S_and2 far S_and2_104_1 = {NULL,&var274,&var275};
_S_and2 far S_and2_1956_1 = {&var277,&var278,&var276};
_S_or3 far S_or3_1955_1 = {&var1175,&var409,&var121,&var277};
_S_noto far S_noto_1993_1 = {&var64,&var278};
_S_noto far S_noto_1982_1 = {&var280,&var279};
_S_ovbs far S_ovbs_1981_1 = {&var1061,&fRM_2_0,&var280,NULL};
_S_noto far S_noto_1972_1 = {&var67,&var281};
_S_and2 far S_and2_1942_1 = {&var283,&var281,&var282};
_S_or3 far S_or3_1941_1 = {&var121,&var1179,&var409,&var283};
_S_noto far S_noto_1987_1 = {&var291,&var284};
_S_and2 far S_and2_1988_1 = {&var1147,&var284,&var285};
_S_and2 far S_and2_1996_1 = {&var285,&var62,&var286};
_S_and2 far S_and2_1975_1 = {&var288,&var66,&var287};
_S_and2 far S_and2_1980_1 = {&var289,&var1147,&var288};
_S_noto far S_noto_1979_1 = {&var862,&var289};
_S_noto far S_noto_1995_1 = {&var293,&var290};
_S_or2 far S_or2_1986_1 = {&var164,&var290,&var291};
_S_noto far S_noto_1974_1 = {&var294,&var292};
_S_rs far S_rs_1984_1 = {&var164,&var299,&var293,&vainSBool,NULL};
_S_rs far S_rs_1976_1 = {&var165,&var300,&var294,&vainSBool,NULL};
_S_and2 far S_and2_1965_1 = {&var297,&var304,&var295};
_S_and2 far S_and2_1953_1 = {&var297,&var301,&var296};
_S_noto far S_noto_1947_1 = {&var298,&var297};
_S_ovbs far S_ovbs_1946_1 = {&var121,&fRM_10_0,&var298,NULL};
_S_ovbs far S_ovbs_1957_1 = {&var276,&fRM_2_0,&var299,NULL};
_S_ovbs far S_ovbs_1943_1 = {&var282,&fRM_2_0,&var300,NULL};
_S_or2 far S_or2_1952_1 = {&var332,&var925,&var301};
_S_or2 far S_or2_1948_1 = {&var333,&var282,&var302};
_S_or2 far S_or2_1960_1 = {&var333,&var276,&var303};
_S_or2 far S_or2_1964_1 = {&var332,&var922,&var304};
_S_rs far S_rs_1949_1 = {&var296,&var302,&var305,&vainSBool,NULL};
_S_noto far S_noto_1962_1 = {&var307,&var306};
_S_rs far S_rs_1961_1 = {&var295,&var303,&var307,&vainSBool,NULL};
_S_noto far S_noto_1950_1 = {&var305,&var308};
_S_noto far S_noto_1958_1 = {&var299,&var309};
_S_noto far S_noto_1944_1 = {&var300,&var310};
_S_and2 far S_and2_1937_1 = {&var313,&var415,&var311};
_S_and2 far S_and2_1926_1 = {&var313,&var412,&var312};
_S_noto far S_noto_1920_1 = {&var314,&var313};
_S_ovbs far S_ovbs_1919_1 = {&var81,&fRM_3_0,&var314,NULL};
_S_or2 far S_or2_1455_1 = {&var1095,&var339,&var315};
_S_and2 far S_and2_428_1 = {&var1572,&var1514,&var316};
_S_and2 far S_and2_1805_1 = {&var1120,NULL,&var317};
_S_and2 far S_and2_439_1 = {&var871,&var716,&var318};
_S_and2 far S_and2_435_1 = {&var717,&var871,&var319};
_S_and2 far S_and2_468_1 = {&var716,&var872,&var320};
_S_and2 far S_and2_464_1 = {&var717,&var872,&var321};
_S_or2 far S_or2_355_1 = {&var1585,&var842,&var322};
_S_or2 far S_or2_351_1 = {&var1585,&var841,&var323};
_S_ovbs far S_ovbs_51_1 = {&var1597,&fRM_15_0,&var324,NULL};
_S_ovbs far S_ovbs_332_1 = {&var1068,&fRM_0_02,&var325,NULL};
_S_ovbs far S_ovbs_288_1 = {&var1070,&fRM_0_02,&var326,NULL};
_S_ovbs far S_ovbs_734_1 = {&var250,&fRM_0_2,&var327,NULL};
_S_ovbs far S_ovbs_1399_1 = {NULL,&fRM_10_0,&var328,NULL};
_S_ovbs far S_ovbs_110_1 = {NULL,&fRM_0_15,&var329,NULL};
_S_ovbs far S_ovbs_112_1 = {&var275,&fRM_0_02,&var330,NULL};
_S_ovbs far S_ovbs_117_1 = {NULL,&fRM_0_02,&var331,NULL};
_S_ovbs far S_ovbs_21_1 = {&var1147,&fRM_3_0,&var332,NULL};
_S_ovbs far S_ovbs_13_1 = {&var920,&fRM_3_0,&var333,NULL};
_S_ovbs far S_ovbs_1928_1 = {&var81,&fRM_2_0,&var334,NULL};
_S_ovbs far S_ovbs_1916_1 = {&var81,&fRM_2_0,&var335,NULL};
_S_ovbs far S_ovbs_2024_1 = {&var1156,&fRM_2_0,&var336,NULL};
_S_ovbs far S_ovbs_2028_1 = {&var41,&fRM_2_0,&var337,NULL};
_S_ovbs far S_ovbs_1841_1 = {&var350,&fRM_0_01,&var338,NULL};
_S_ovbs far S_ovbs_76_1 = {NULL,&fRM_10_0,&var339,NULL};
_S_zpfs far S_zpfs_301_1 = {&var773,&fRM_10_0,&var340,NULL,NULL};
_S_or2 far S_or2_1015_1 = {&var981,&var543,&var341};
_S_or2 far S_or2_229_1 = {NULL,NULL,&var342};
_S_or2 far S_or2_244_1 = {&var668,&var937,&var343};
_S_or5 far S_or5_144_1 = {NULL,NULL,NULL,&var907,&var908,&var344};
_S_and2 far S_and2_1012_1 = {&var1422,&var1052,&var345};
_S_or3 far S_or3_970_1 = {&var85,&var628,&var627,&var346};
_S_or3 far S_or3_1367_1 = {&var611,&var610,&var86,&var347};
_S_and2 far S_and2_951_1 = {&var1187,&var966,&var348};
_S_and3 far S_and3_1836_1 = {&var366,&var351,&var359,&var349};
_S_or2 far S_or2_1840_1 = {&var353,&var352,&var350};
_S_or3 far S_or3_1838_1 = {&var353,&var352,&var362,&var351};
_S_zpfs far S_zpfs_1835_1 = {&var355,NULL,&var352,NULL,NULL};
_S_zpfs far S_zpfs_1833_1 = {&var356,NULL,&var353,NULL,NULL};
_S_or2 far S_or2_1827_1 = {&var356,&var355,&var354};
_S_or2 far S_or2_1828_1 = {&var357,&var1085,&var355};
_S_or2 far S_or2_1826_1 = {&var358,&var1085,&var356};
_S_and3 far S_and3_1820_1 = {&var1143,&var894,&var872,&var357};
_S_and3 far S_and3_1819_1 = {&var1144,&var871,&var894,&var358};
_S_or2 far S_or2_1817_1 = {&var1085,&var1084,&var359};
_S_or3 far S_or3_1824_1 = {&var364,&var1084,&var362,&var360};
_S_and2 far S_and2_1832_1 = {&var1085,&var351,&var361};
_S_and2 far S_and2_1823_1 = {&var1076,&var363,&var362};
_S_zpfs far S_zpfs_1822_1 = {&var1085,NULL,&var363,NULL,NULL};
_S_and2 far S_and2_1810_1 = {&var1079,&var526,&var364};
_S_or3 far S_or3_1811_1 = {&var1033,&var532,&var1011,&var365};
_S_abs_subf far S_abs_subf_1844_1 = {NULL,&var367,NULL,&vainSFloat,&var366};
_S_rsfn far S_rsfn_1842_1 = {&var523,&var368,&var367,NULL};
_S_lk far S_lk_1839_1 = {&var1242,&var351,&var368};
_S_abs_subf far S_abs_subf_1428_1 = {NULL,&var370,NULL,&vainSFloat,&var369};
_S_rsfn far S_rsfn_1419_1 = {&var523,&var371,&var370,NULL};
_S_lk far S_lk_1423_1 = {&var1090,&var510,&var371};
_S_abs_subf far S_abs_subf_1470_1 = {NULL,&var373,NULL,&vainSFloat,&var372};
_S_rsfn far S_rsfn_1457_1 = {&var523,&var374,&var373,NULL};
_S_lk far S_lk_1461_1 = {&var1096,&var500,&var374};
_S_ma far S_ma_1440_1 = {array_m1440_x_1,NULL,&iRM_7_,&vainSFloat};
_S_abs_subf far S_abs_subf_1475_1 = {NULL,&var376,NULL,&vainSFloat,&var375};
_S_rsfn far S_rsfn_1460_1 = {&var523,&var377,&var376,NULL};
_S_lk far S_lk_1464_1 = {&var1240,&var491,&var377};
_S_and3 far S_and3_1886_1 = {&var379,&var382,&var389,&var378};
_S_abs_subf far S_abs_subf_1883_1 = {&var380,NULL,NULL,&vainSFloat,&var379};
_S_rsfn far S_rsfn_1881_1 = {&var523,&var381,&var380,NULL};
_S_lk far S_lk_1875_1 = {&var1241,&var382,&var381};
_S_or3 far S_or3_1877_1 = {&var387,&var393,&var392,&var382};
_S_and4 far S_and4_1880_1 = {&var392,&var1247,&var405,&var403,&var383};
_S_and4 far S_and4_1878_1 = {&var393,&var1247,&var405,&var403,&var384};
_S_and2 far S_and2_1870_1 = {&var1088,&var382,&var385};
_S_and2 far S_and2_1856_1 = {&var526,&var1078,&var386};
_S_and2 far S_and2_1860_1 = {&var390,&var1077,&var387};
_S_or3 far S_or3_1861_1 = {&var387,&var386,&var1087,&var388};
_S_or2 far S_or2_1852_1 = {&var1088,&var1087,&var389};
_S_zpfs far S_zpfs_1859_1 = {&var1088,NULL,&var390,NULL,NULL};
_S_or3 far S_or3_1849_1 = {&var528,&var1037,&var1015,&var391};
_S_zpfs far S_zpfs_1874_1 = {&var395,NULL,&var392,NULL,NULL};
_S_zpfs far S_zpfs_1871_1 = {&var396,NULL,&var393,NULL,NULL};
_S_or2 far S_or2_1868_1 = {&var396,&var395,&var394};
_S_or2 far S_or2_1869_1 = {&var397,&var1088,&var395};
_S_or2 far S_or2_1867_1 = {&var398,&var1088,&var396};
_S_and4 far S_and4_1864_1 = {&var1145,&var872,NULL,&var399,&var397};
_S_and4 far S_and4_1858_1 = {&var1146,NULL,&var871,&var399,&var398};
_S_and2 far S_and2_1857_1 = {&var894,&var403,&var399};
_S_and3 far S_and3_1895_1 = {&var872,&var999,&var402,&var400};
_S_and3 far S_and3_1894_1 = {&var871,&var1000,&var402,&var401};
_S_and4 far S_and4_1893_1 = {&var965,&var763,&var765,&var403,&var402};
_S_and2 far S_and2_1887_1 = {&var776,&var966,&var403};
_S_or2 far S_or2_1889_1 = {&var1251,&var964,&var404};
_S_or3 far S_or3_1898_1 = {&var408,&var407,&var410,&var405};
_S_and2 far S_and2_1888_1 = {&var1003,NULL,&var406};
_S_and2 far S_and2_1892_1 = {&var904,&var406,&var407};
_S_and3 far S_and3_1897_1 = {&var1246,&var411,&var406,&var408};
_S_or2 far S_or2_1906_1 = {&lRM_0_,&var404,&var409};
_S_and2 far S_and2_1903_1 = {&var919,&var411,&var410};
_S_and2 far S_and2_1905_1 = {&var1002,NULL,&var411};
_S_or2 far S_or2_1925_1 = {&var924,&var332,&var412};
_S_or2 far S_or2_1921_1 = {&var333,&var81,&var413};
_S_or2 far S_or2_1932_1 = {&var81,&var333,&var414};
_S_or2 far S_or2_1936_1 = {&var332,&var923,&var415};
_S_or2 far S_or2_1999_1 = {&var771,&var1157,&var416};
_S_or2 far S_or2_2006_1 = {&var966,&var1181,&var417};
_S_zpfs far S_zpfs_2008_1 = {&var5,&fRM_15_0,&var418,NULL,NULL};
_S_or2 far S_or2_2011_1 = {&var770,&var42,&var419};
_S_zpfs far S_zpfs_2018_1 = {&var3,&fRM_15_0,&var420,NULL,NULL};
_S_or2 far S_or2_2021_1 = {&var966,&var1180,&var421};
_S_or2 far S_or2_2037_1 = {&var11,&var383,&var422};
_S_or2 far S_or2_2032_1 = {&var384,&var15,&var423};
_S_and2 far S_and2_2043_1 = {&var1147,&var336,&var424};
_S_and2 far S_and2_1804_1 = {&var1121,NULL,&var425};
_S_or3 far S_or3_1777_1 = {&var430,&var434,&var432,&var426};
_S_or3 far S_or3_1779_1 = {&var433,&var432,&var429,&var427};
_S_or2 far S_or2_1791_1 = {NULL,NULL,&var428};
_S_and2 far S_and2_1782_1 = {&var435,&var428,&var429};
_S_and2 far S_and2_1776_1 = {&var435,&var431,&var430};
_S_or2 far S_or2_1775_1 = {NULL,NULL,&var431};
_S_zpfs far S_zpfs_1772_1 = {&var1139,&fRM_2_5,&var432,NULL,NULL};
_S_zpfs far S_zpfs_1771_1 = {&var1140,&fRM_2_5,&var433,NULL,NULL};
_S_zpfs far S_zpfs_1770_1 = {&var1141,&fRM_2_5,&var434,NULL,NULL};
_S_zpfs far S_zpfs_1769_1 = {&var1142,&fRM_2_5,&var435,NULL,NULL};
_S_or2 far S_or2_1800_1 = {NULL,NULL,&var436};
_S_and2 far S_and2_1794_1 = {&var41,&var1122,&var437};
_S_or2 far S_or2_1790_1 = {&var440,&var437,&var438};
_S_or2 far S_or2_1792_1 = {&var11,&var41,&var439};
_S_and2 far S_and2_1789_1 = {&var11,&var1112,&var440};
_S_and2 far S_and2_1773_1 = {&var1156,&var1123,&var441};
_S_or2 far S_or2_1774_1 = {&var444,&var441,&var442};
_S_or2 far S_or2_1767_1 = {&var15,&var1156,&var443};
_S_and2 far S_and2_1766_1 = {&var15,&var1113,&var444};
_S_or3 far S_or3_1736_1 = {&var1210,&var1168,&var1169,&var445};
_S_or3 far S_or3_1737_1 = {&var1208,&var1168,&var1169,&var446};
_S_or2 far S_or2_1728_1 = {&var1203,&var1168,&var447};
_S_or2 far S_or2_1729_1 = {&var1202,&var1168,&var448};
_S_or2 far S_or2_1735_1 = {&var1212,&var1171,&var449};
_S_or4 far S_or4_1733_1 = {&var1171,&var1209,&var1172,&var1173,&var450};
_S_or4 far S_or4_1732_1 = {&var1171,&var1215,&var1172,&var1173,&var451};
_S_or2 far S_or2_1726_1 = {&var1204,&var1173,&var452};
_S_or2 far S_or2_1725_1 = {&var1205,&var1173,&var453};
_S_or2 far S_or2_1734_1 = {&var1171,&var1211,&var454};
_S_or2 far S_or2_1703_1 = {&var196,&var246,&var455};
_S_or2 far S_or2_1700_1 = {&var244,&var199,&var456};
_S_or2 far S_or2_1697_1 = {&var199,&var245,&var457};
_S_or2 far S_or2_2113_1 = {&var16,&var245,&var458};
_S_or2 far S_or2_1672_1 = {&var193,&var245,&var459};
_S_or2 far S_or2_1663_1 = {&var244,&var186,&var460};
_S_or2 far S_or2_1661_1 = {&var244,&var189,&var461};
_S_or2 far S_or2_1657_1 = {&var245,&var186,&var462};
_S_or2 far S_or2_1655_1 = {&var189,&var245,&var463};
_S_and2 far S_and2_1548_1 = {&var1465,&var1423,&var464};
_S_and2 far S_and2_1547_1 = {&var1588,&var1423,&var465};
_S_and2 far S_and2_1546_1 = {&var860,&var1423,&var466};
_S_or2 far S_or2_1545_1 = {NULL,NULL,&var467};
_S_and2 far S_and2_1544_1 = {&var467,&var1423,&var468};
_S_and2 far S_and2_1538_1 = {&var1631,&var1423,&var469};
_S_and2 far S_and2_1537_1 = {&var94,&var1423,&var470};
_S_and2 far S_and2_1536_1 = {&var849,&var1423,&var471};
_S_and2 far S_and2_1535_1 = {NULL,&var1423,&var472};
_S_or2 far S_or2_1635_1 = {&var186,&var244,&var473};
_S_or2 far S_or2_1629_1 = {&var186,&var245,&var474};
_S_or2 far S_or2_1614_1 = {&var186,&var244,&var475};
_S_or2 far S_or2_1611_1 = {&var186,&var245,&var476};
_S_or2 far S_or2_1608_1 = {&var1221,&var246,&var477};
_S_or2 far S_or2_1605_1 = {&var1221,&var246,&var478};
_S_or2 far S_or2_1595_1 = {&var1601,&var1602,&var479};
_S_or2 far S_or2_1594_1 = {&var1603,&var1601,&var480};
_S_or2 far S_or2_2057_1 = {&var943,NULL,&var481};
_S_or3 far S_or3_2063_1 = {&var1222,&var1224,&var1223,&var482};
_S_or3 far S_or3_2054_1 = {&var1228,&var1230,&var1229,&var483};
_S_or2 far S_or2_1583_1 = {&var1689,&var1423,&var484};
_S_or2 far S_or2_1557_1 = {&var1466,&var1052,&var485};
_S_or5 far S_or5_1109_1 = {&var1481,&var487,&var1492,&var1478,&var1479,&var486};
_S_or3 far S_or3_1113_1 = {&var1486,&var1487,&var946,&var487};
_S_or5 far S_or5_1571_1 = {&var252,&var489,&var1475,&var1467,&var1468,&var488};
_S_or3 far S_or3_1574_1 = {&var945,&var1469,&var1470,&var489};
_S_and3 far S_and3_1484_1 = {&var491,&var496,&var375,&var490};
_S_and2 far S_and2_1487_1 = {&var492,&var1239,&var491};
_S_or3 far S_or3_1486_1 = {NULL,NULL,&var495,&var492};
_S_zpfs far S_zpfs_1471_1 = {&var1239,&fRM_0_2,&var493,NULL,NULL};
_S_or3 far S_or3_1473_1 = {&var1098,&var495,&var497,&var494};
_S_and2 far S_and2_1472_1 = {&var1075,&var493,&var495};
_S_or2 far S_or2_1462_1 = {&var1239,&var1098,&var496};
_S_and2 far S_and2_1450_1 = {&var1080,&var526,&var497};
_S_or3 far S_or3_1458_1 = {&var1012,&var1034,&var531,&var498};
_S_or3 far S_or3_1480_1 = {NULL,NULL,&var502,&var499};
_S_and2 far S_and2_1481_1 = {&var499,&var1095,&var500};
_S_zpfs far S_zpfs_1465_1 = {&var1095,NULL,&var501,NULL,NULL};
_S_and2 far S_and2_1466_1 = {&var501,&var1074,&var502};
_S_or3 far S_or3_1467_1 = {&var1093,&var502,&var505,&var503};
_S_or3 far S_or3_1442_1 = {&var530,&var1035,&var1013,&var504};
_S_and2 far S_and2_1445_1 = {&var1081,&var526,&var505};
_S_and3 far S_and3_1483_1 = {&var372,&var500,&var513,&var506};
_S_zpfs far S_zpfs_1415_1 = {&var1092,NULL,&var507,NULL,NULL};
_S_and2 far S_and2_1416_1 = {&var507,&var1073,&var508};
_S_and3 far S_and3_1432_1 = {&var369,&var510,&var514,&var509};
_S_and2 far S_and2_1426_1 = {&var511,&var1092,&var510};
_S_or3 far S_or3_1425_1 = {NULL,NULL,&var508,&var511};
_S_or3 far S_or3_1417_1 = {&var515,&var508,&var1091,&var512};
_S_or2 far S_or2_1453_1 = {&var1095,&var1093,&var513};
_S_or2 far S_or2_1413_1 = {&var1092,&var1091,&var514};
_S_and2 far S_and2_1405_1 = {&var1082,&var526,&var515};
_S_or3 far S_or3_1403_1 = {&var1014,&var1036,&var529,&var516};
_S_or2 far S_or2_1378_1 = {&var1594,&var518,&var517};
_S_and2 far S_and2_1377_1 = {&var519,&var1137,&var518};
_S_or2 far S_or2_1376_1 = {&var917,&var869,&var519};
_S_or2 far S_or2_1372_1 = {&var1007,&var1029,&var520};
_S_and2 far S_and2_1370_1 = {&var1101,&var1102,&var521};
_S_and2 far S_and2_1373_1 = {&var520,&var519,&var522};
_S_or5 far S_or5_1374_1 = {&var326,&var325,&var521,&var522,NULL,&var523};
_S_orni far S_orni_1394_1 = {array_m1394_x_1,&iRM_5_,&var524,&var525};
_S_or5 far S_or5_1396_1 = {&var1097,&var1072,&var523,&var1017,&var328,&var526};
_S_and2 far S_and2_1395_1 = {&var524,&var1234,&var527};
_S_or2 far S_or2_1402_1 = {&var1044,&var533,&var528};
_S_or2 far S_or2_1398_1 = {&var1043,&var534,&var529};
_S_or2 far S_or2_1392_1 = {&var1042,&var535,&var530};
_S_or2 far S_or2_1390_1 = {&var1041,&var536,&var531};
_S_or2 far S_or2_1388_1 = {&var1040,&var537,&var532};
_S_and2 far S_and2_1401_1 = {&var1589,&var539,&var533};
_S_and2 far S_and2_1397_1 = {&var1590,&var539,&var534};
_S_and2 far S_and2_1391_1 = {&var1591,&var539,&var535};
_S_and2 far S_and2_1389_1 = {&var1592,&var539,&var536};
_S_and2 far S_and2_1387_1 = {&var1593,&var539,&var537};
_S_and2 far S_and2_1381_1 = {&var1594,&var539,&var538};
_S_and2 far S_and2_1375_1 = {NULL,&var920,&var539};
_S_and3 far S_and3_1045_1 = {&var190,&var544,&var562,&var540};
_S_or2 far S_or2_1009_1 = {&var1054,&var1050,&var541};
_S_or2 far S_or2_1035_1 = {&var1050,&var984,&var542};
_S_and2 far S_and2_1003_1 = {&var1432,&var1051,&var543};
_S_and2 far S_and2_999_1 = {&var1251,&var564,&var544};
_S_or3 far S_or3_1006_1 = {&var1050,&var980,&var1053,&var545};
_S_and2 far S_and2_1010_1 = {&var187,&var1251,&var546};
_S_and2 far S_and2_1036_1 = {&var198,&var1251,&var547};
_S_and2 far S_and2_1044_1 = {&var192,&var1251,&var548};
_S_and2 far S_and2_1051_1 = {&var195,&var1251,&var549};
_S_and3 far S_and3_994_1 = {&var552,&var969,&var1251,&var550};
_S_and3 far S_and3_988_1 = {&var553,&var969,&var1251,&var551};
_S_and2 far S_and2_996_1 = {&var871,&var1250,&var552};
_S_and2 far S_and2_986_1 = {&var872,&var1250,&var553};
_S_and4 far S_and4_995_1 = {&var552,&var1251,&var977,&var967,&var554};
_S_and4 far S_and4_989_1 = {&var553,&var1251,&var977,&var967,&var555};
_S_and4 far S_and4_993_1 = {&var1251,&var552,&var560,&var968,&var556};
_S_and4 far S_and4_987_1 = {&var1251,&var553,&var560,&var968,&var557};
_S_and2 far S_and2_980_1 = {&var978,&var1251,&var558};
_S_or4 far S_or4_983_1 = {NULL,&var1485,&var203,&var571,&var559};
_S_and3 far S_and3_1029_1 = {&var979,&var978,&var977,&var560};
_S_and2 far S_and2_1016_1 = {&var562,&var341,&var561};
_S_and2 far S_and2_1019_1 = {&var976,&var560,&var562};
_S_or2 far S_or2_1030_1 = {&var1046,&var988,&var563};
_S_and2 far S_and2_1038_1 = {&var565,&var563,&var564};
_S_or2 far S_or2_1031_1 = {&var987,&var989,&var565};
_S_or2 far S_or2_1032_1 = {&var986,&var987,&var566};
_S_or2 far S_or2_1033_1 = {&var985,&var990,&var567};
_S_and2 far S_and2_1034_1 = {&var566,&var567,&var568};
_S_or2 far S_or2_1022_1 = {&var1046,&var1045,&var569};
_S_and2 far S_and2_1023_1 = {&var569,&var982,&var570};
_S_and5 far S_and5_976_1 = {&var572,&var1066,&var987,&var1046,&var561,&var571};
_S_and2 far S_and2_977_1 = {&var1021,&var1022,&var572};
_S_and2 far S_and2_1224_1 = {&var1115,&var574,&var573};
_S_or2 far S_or2_1218_1 = {NULL,&var575,&var574};
_S_and2 far S_and2_1206_1 = {NULL,&var1133,&var575};
_S_or2 far S_or2_1200_1 = {&var578,NULL,&var576};
_S_and2 far S_and2_1202_1 = {&var576,&var1115,&var577};
_S_and2 far S_and2_1194_1 = {NULL,&var1134,&var578};
_S_or3 far S_or3_1183_1 = {&var1201,&var1196,&var734,&var579};
_S_or5 far S_or5_1198_1 = {&var582,&var955,&var1462,&var1456,&var1457,&var580};
_S_or2 far S_or2_1217_1 = {&var1701,&var1447,&var581};
_S_or3 far S_or3_1269_1 = {&var1428,&var583,&var584,&var582};
_S_and2 far S_and2_1264_1 = {&var1447,&var918,&var583};
_S_and2 far S_and2_1263_1 = {&var868,&var1447,&var584};
_S_and3 far S_and3_1262_1 = {&var344,&var904,&var599,&var585};
_S_and2 far S_and2_1261_1 = {&var94,&var599,&var586};
_S_and3 far S_and3_1257_1 = {&var893,&var939,&var599,&var587};
_S_and2 far S_and2_1256_1 = {&var436,&var599,&var588};
_S_and2 far S_and2_1244_1 = {&var1438,&var599,&var589};
_S_and2 far S_and2_1231_1 = {&var1631,&var599,&var590};
_S_and2 far S_and2_1246_1 = {&var863,&var599,&var591};
_S_and2 far S_and2_1232_1 = {NULL,&var599,&var592};
_S_and2 far S_and2_1247_1 = {&var595,&var599,&var593};
_S_and3 far S_and3_1233_1 = {&var596,&var1437,&var599,&var594};
_S_or2 far S_or2_1248_1 = {&var1430,&var1431,&var595};
_S_or2 far S_or2_1235_1 = {NULL,NULL,&var596};
_S_and3 far S_and3_1243_1 = {&var1171,&var204,&var920,&var597};
_S_and3 far S_and3_1242_1 = {&var1173,&var204,&var920,&var598};
_S_or3 far S_or3_1234_1 = {&var1448,&var598,&var597,&var599};
_S_and2 far S_and2_1319_1 = {&var601,&var1115,&var600};
_S_or2 far S_or2_1317_1 = {&var602,NULL,&var601};
_S_and2 far S_and2_1306_1 = {NULL,&var1111,&var602};
_S_or2 far S_or2_1309_1 = {&var1692,&var1265,&var603};
_S_or5 far S_or5_1295_1 = {&var347,&var1275,&var1274,&var115,&var953,&var604};
_S_and2 far S_and2_1355_1 = {&var1265,&var918,&var605};
_S_and2 far S_and2_1354_1 = {&var1265,&var868,&var606};
_S_and2 far S_and2_1363_1 = {&var934,&var1253,&var607};
_S_or2 far S_or2_1358_1 = {&var607,&var935,&var608};
_S_and3 far S_and3_1353_1 = {&var1124,&var608,&var617,&var609};
_S_and3 far S_and3_1352_1 = {&var344,&var919,&var617,&var610};
_S_and2 far S_and2_1351_1 = {&var94,&var617,&var611};
_S_and2 far S_and2_1348_1 = {&var1185,&var966,&var612};
_S_or2 far S_or2_1338_1 = {&var1256,&var1255,&var613};
_S_and2 far S_and2_1337_1 = {&var613,&var617,&var614};
_S_and2 far S_and2_1336_1 = {&var863,&var617,&var615};
_S_and2 far S_and2_1334_1 = {&var1258,&var617,&var616};
_S_or2 far S_or2_1327_1 = {&var1267,&var19,&var617};
_S_or2 far S_or2_1325_1 = {NULL,NULL,&var618};
_S_and3 far S_and3_1324_1 = {&var1257,&var618,&var617,&var619};
_S_and2 far S_and2_1323_1 = {NULL,&var617,&var620};
_S_and2 far S_and2_1322_1 = {&var1631,&var617,&var621};
_S_and2 far S_and2_966_1 = {&var932,&var1285,&var622};
_S_and2 far S_and2_957_1 = {&var868,&var1297,&var623};
_S_and2 far S_and2_958_1 = {&var918,&var1297,&var624};
_S_or2 far S_or2_961_1 = {&var933,&var622,&var625};
_S_and3 far S_and3_956_1 = {&var1124,&var625,&var632,&var626};
_S_and3 far S_and3_955_1 = {&var904,&var344,&var632,&var627};
_S_and2 far S_and2_954_1 = {&var94,&var632,&var628};
_S_and2 far S_and2_937_1 = {&var1290,&var632,&var629};
_S_or2 far S_or2_941_1 = {&var1288,&var1287,&var630};
_S_and2 far S_and2_940_1 = {&var630,&var632,&var631};
_S_or2 far S_or2_930_1 = {&var1299,&var20,&var632};
_S_or2 far S_or2_928_1 = {NULL,NULL,&var633};
_S_and3 far S_and3_927_1 = {&var633,&var1289,&var632,&var634};
_S_and2 far S_and2_939_1 = {&var863,&var632,&var635};
_S_and2 far S_and2_926_1 = {NULL,&var632,&var636};
_S_and2 far S_and2_925_1 = {&var1631,&var632,&var637};
_S_or2 far S_or2_912_1 = {&var1297,&var1695,&var638};
_S_or5 far S_or5_895_1 = {&var346,&var954,&var113,&var1306,&var1307,&var639};
_S_and2 far S_and2_924_1 = {&var1115,&var641,&var640};
_S_or2 far S_or2_920_1 = {&var642,NULL,&var641};
_S_and2 far S_and2_909_1 = {NULL,&var1170,&var642};
_S_or3 far S_or3_867_1 = {&var1395,&var645,&var644,&var643};
_S_and2 far S_and2_861_1 = {&var1406,&var868,&var644};
_S_and2 far S_and2_862_1 = {&var1406,&var918,&var645};
_S_and3 far S_and3_860_1 = {&var1429,&var919,&var657,&var646};
_S_and2 far S_and2_859_1 = {&var94,&var657,&var647};
_S_and2 far S_and2_842_1 = {&var1399,&var657,&var648};
_S_and2 far S_and2_844_1 = {&var863,&var657,&var649};
_S_and2 far S_and2_845_1 = {&var651,&var657,&var650};
_S_or2 far S_or2_846_1 = {&var1397,&var1396,&var651};
_S_and2 far S_and2_829_1 = {&var1631,&var657,&var652};
_S_and3 far S_and3_831_1 = {&var1398,&var658,&var657,&var653};
_S_and2 far S_and2_830_1 = {NULL,&var657,&var654};
_S_and3 far S_and3_841_1 = {&var1171,&var204,&var920,&var655};
_S_and3 far S_and3_840_1 = {&var204,&var1173,&var920,&var656};
_S_or3 far S_or3_833_1 = {&var1407,&var655,&var656,&var657};
_S_or2 far S_or2_834_1 = {NULL,NULL,&var658};
_S_or2 far S_or2_819_1 = {&var1698,&var1406,&var659};
_S_zpfs far S_zpfs_817_1 = {&var1420,&fRM_3_0,&var660,NULL,NULL};
_S_zpfs far S_zpfs_814_1 = {&var1421,&fRM_2_0,&var661,NULL,NULL};
_S_zpfs far S_zpfs_821_1 = {&var1418,NULL,&var662,NULL,NULL};
_S_or5 far S_or5_809_1 = {&var643,&var662,&var1419,&var661,&var660,&var663};
_S_or3 far S_or3_799_1 = {&var1176,&var1199,&var729,&var664};
_S_or4 far S_or4_782_1 = {&var1542,&var1540,&var1541,&var1543,&var665};
_S_or2 far S_or2_773_1 = {&var667,&var665,&var666};
_S_or4 far S_or4_766_1 = {&var1551,&var1550,&var1549,&var1552,&var667};
_S_and2 far S_and2_249_1 = {&var936,&var1345,&var668};
_S_and3 far S_and3_238_1 = {&var904,&var344,&var1360,&var669};
_S_or3 far S_or3_251_1 = {&var673,&var671,&var1348,&var670};
_S_and2 far S_and2_241_1 = {&var1359,&var918,&var671};
_S_and3 far S_and3_239_1 = {&var343,&var1124,&var1360,&var672};
_S_and2 far S_and2_240_1 = {&var868,&var1359,&var673};
_S_and2 far S_and2_237_1 = {&var94,&var1360,&var674};
_S_and2 far S_and2_212_1 = {&var1352,&var1360,&var675};
_S_and2 far S_and2_214_1 = {&var863,&var1360,&var676};
_S_or2 far S_or2_216_1 = {&var1349,&var1350,&var677};
_S_and2 far S_and2_215_1 = {&var677,&var1360,&var678};
_S_or2 far S_or2_205_1 = {NULL,NULL,&var679};
_S_and3 far S_and3_204_1 = {&var1351,&var679,&var1360,&var680};
_S_and2 far S_and2_202_1 = {&var1631,&var1360,&var681};
_S_and2 far S_and2_203_1 = {NULL,&var1360,&var682};
_S_and2 far S_and2_179_1 = {&var1115,&var685,&var683};
_S_and2 far S_and2_171_1 = {NULL,&var1155,&var684};
_S_or2 far S_or2_177_1 = {NULL,&var684,&var685};
_S_or2 far S_or2_191_1 = {&var1359,&var1683,&var686};
_S_zpfs far S_zpfs_182_1 = {&var1374,&fRM_2_0,&var687,NULL,NULL};
_S_zpfs far S_zpfs_187_1 = {&var1373,&fRM_2_0,&var688,NULL,NULL};
_S_zpfs far S_zpfs_193_1 = {&var1371,NULL,&var689,NULL,NULL};
_S_or5 far S_or5_175_1 = {&var670,&var689,&var688,&var687,&var1372,&var690};
_S_orn far S_orn_540_1 = {array_m540_x_1,&iRM_14_,&var691};
_S_and2 far S_and2_563_1 = {&var1315,&var931,&var692};
_S_or2 far S_or2_558_1 = {&var930,&var692,&var693};
_S_and3 far S_and3_552_1 = {&var919,&var1429,&var1327,&var694};
_S_and2 far S_and2_551_1 = {&var94,&var1327,&var695};
_S_and3 far S_and3_553_1 = {&var1124,&var1327,&var693,&var696};
_S_or2 far S_or2_533_1 = {&var1317,&var1316,&var697};
_S_and2 far S_and2_532_1 = {&var697,&var1327,&var698};
_S_and2 far S_and2_531_1 = {&var1327,&var863,&var699};
_S_and3 far S_and3_521_1 = {&var1318,&var701,&var1327,&var700};
_S_or2 far S_or2_522_1 = {NULL,NULL,&var701};
_S_and2 far S_and2_529_1 = {&var1327,&var1319,&var702};
_S_or2 far S_or2_499_1 = {NULL,&var705,&var703};
_S_and2 far S_and2_503_1 = {&var1115,&var703,&var704};
_S_and2 far S_and2_493_1 = {NULL,&var1135,&var705};
_S_and2 far S_and2_520_1 = {&var1327,NULL,&var706};
_S_and2 far S_and2_519_1 = {&var1327,&var1631,&var707};
_S_or2 far S_or2_510_1 = {&var1326,&var1705,&var708};
_S_zpfs far S_zpfs_512_1 = {&var1340,NULL,&var709,NULL,NULL};
_S_or5 far S_or5_495_1 = {&var864,&var709,&var1341,&var1335,&var1336,&var710};
_S_or2 far S_or2_483_1 = {&var1151,&var730,&var711};
_S_or3 far S_or3_473_1 = {&var551,&var1150,&var961,&var712};
_S_or4 far S_or4_463_1 = {&var1379,&var1377,&var1379,&var1378,&var713};
_S_or4 far S_or4_445_1 = {&var1388,&var1386,&var1387,&var1389,&var714};
_S_or2 far S_or2_452_1 = {&var714,&var713,&var715};
_S_and3 far S_and3_436_1 = {&var718,&var1115,NULL,&var716};
_S_and3 far S_and3_437_1 = {&var1115,&var719,NULL,&var717};
_S_or3 far S_or3_429_1 = {&var238,&var970,&var957,&var718};
_S_or2 far S_or2_430_1 = {&var1375,&var1149,&var719};
_S_or2 far S_or2_736_1 = {&var1510,&var1511,&var720};
_S_and2 far S_and2_322_1 = {&var1006,&var1068,&var721};
_S_or2 far S_or2_341_1 = {NULL,NULL,&var722};
_S_or2 far S_or2_336_1 = {NULL,NULL,&var723};
_S_or2 far S_or2_331_1 = {&var726,&var1010,&var724};
_S_and3 far S_and3_329_1 = {&var1069,&var1064,&var1065,&var725};
_S_or4 far S_or4_327_1 = {&var995,&var144,NULL,&var1005,&var726};
_S_and4 far S_and4_323_1 = {&var917,&var784,&var203,&var875,&var727};
_S_or2 far S_or2_318_1 = {NULL,&var1005,&var728};
_S_and3 far S_and3_592_1 = {&var751,&var1252,NULL,&var729};
_S_and2 far S_and2_591_1 = {&var751,&var1284,&var730};
_S_and2 far S_and2_590_1 = {&var751,&var1347,&var731};
_S_or2 far S_or2_634_1 = {NULL,NULL,&var732};
_S_or2 far S_or2_611_1 = {&var1482,&var1104,&var733};
_S_and3 far S_and3_602_1 = {NULL,&var1252,&var752,&var734};
_S_and2 far S_and2_633_1 = {&var736,&var1252,&var735};
_S_or2 far S_or2_635_1 = {&var1047,&var187,&var736};
_S_or2 far S_or2_616_1 = {&var1482,&var1103,&var737};
_S_or2 far S_or2_614_1 = {&var739,&var1482,&var738};
_S_and2 far S_and2_626_1 = {&var1284,&var198,&var739};
_S_and2 far S_and2_601_1 = {&var752,&var1284,&var740};
_S_and2 far S_and2_600_1 = {&var752,&var1347,&var741};
_S_and2 far S_and2_625_1 = {&var192,&var1347,&var742};
_S_and2 far S_and2_641_1 = {&var195,&var1375,&var743};
_S_or2 far S_or2_637_1 = {&var1482,&var1105,&var744};
_S_or2 far S_or2_632_1 = {&var746,&var743,&var745};
_S_and2 far S_and2_624_1 = {&var754,&var1344,&var746};
_S_and2 far S_and2_630_1 = {&var754,NULL,&var747};
_S_or2 far S_or2_580_1 = {&var928,&var929,&var748};
_S_and4 far S_and4_599_1 = {&var928,&var752,&var1444,NULL,&var749};
_S_and4 far S_and4_589_1 = {&var751,&var929,&var1444,NULL,&var750};
_S_and2 far S_and2_588_1 = {&var872,&var1442,&var751};
_S_and2 far S_and2_598_1 = {&var871,&var1442,&var752};
_S_or2 far S_or2_629_1 = {&var1048,&var187,&var753};
_S_and2 far S_and2_622_1 = {&var753,&var1444,&var754};
_S_or2 far S_or2_609_1 = {&var1482,&var1106,&var755};
_S_or2 far S_or2_621_1 = {&var1422,&var1061,&var756};
_S_and2 far S_and2_620_1 = {&var756,&var1466,&var757};
_S_or2 far S_or2_606_1 = {&var1482,&var1107,&var758};
_S_and2 far S_and2_619_1 = {&var1483,&var1432,&var759};
_S_or2 far S_or2_604_1 = {&var1482,&var1108,&var760};
_S_and2 far S_and2_617_1 = {&var190,&var1485,&var761};
_S_or2 far S_or2_596_1 = {&var1116,&var1482,&var762};
_S_and2 far S_and2_297_1 = {&var1182,&var765,&var763};
_S_and2 far S_and2_285_1 = {&var765,&var993,&var764};
_S_or2 far S_or2_280_1 = {&var1007,&var1029,&var765};
_S_and3 far S_and3_276_1 = {&var1248,&var1064,&var1065,&var766};
_S_and3 far S_and3_291_1 = {&var723,&var994,&var768,&var767};
_S_or2 far S_or2_281_1 = {&var1248,&var1069,&var768};
_S_and2 far S_and2_290_1 = {&var722,&var768,&var769};
_S_and2 far S_and2_310_1 = {&var774,&var872,&var770};
_S_and2 far S_and2_311_1 = {&var871,&var774,&var771};
_S_and2 far S_and2_316_1 = {&var966,&var763,&var772};
_S_and2 far S_and2_304_1 = {&var774,&var966,&var773};
_S_and2 far S_and2_309_1 = {&var1147,&var775,&var774};
_S_or2 far S_or2_305_1 = {&var776,&var721,&var775};
_S_or2 far S_or2_306_1 = {&var777,&var721,&var776};
_S_and4 far S_and4_307_1 = {&var1070,&var1018,&var1019,&var869,&var777};
_S_or2 far S_or2_293_1 = {&var1070,&var1068,&var778};
_S_and2 far S_and2_278_1 = {&var1032,&var1001,&var779};
_S_or2 far S_or2_284_1 = {&var782,&var779,&var780};
_S_or2 far S_or2_258_1 = {NULL,&var1004,&var781};
_S_or4 far S_or4_275_1 = {&var995,NULL,&var144,&var1004,&var782};
_S_and3 far S_and3_268_1 = {&var784,&var874,&var203,&var783};
_S_or2 far S_or2_267_1 = {&var1023,&var1213,&var784};
_S_and3 far S_and3_270_1 = {&var1024,&var1026,&var1025,&var785};
_S_or2 far S_or2_260_1 = {&var787,&var785,&var786};
_S_and3 far S_and3_254_1 = {NULL,&var1028,&var1027,&var787};
_S_or2 far S_or2_1081_1 = {NULL,NULL,&var788};
_S_and2 far S_and2_1084_1 = {&var1433,&var1480,&var789};
_S_and2 far S_and2_1083_1 = {&var1433,&var1588,&var790};
_S_and2 far S_and2_1082_1 = {&var1433,&var860,&var791};
_S_and2 far S_and2_1080_1 = {&var1433,&var788,&var792};
_S_and2 far S_and2_1074_1 = {&var1433,&var94,&var793};
_S_and2 far S_and2_1073_1 = {&var849,&var1433,&var794};
_S_and2 far S_and2_1072_1 = {&var1433,NULL,&var795};
_S_and2 far S_and2_1075_1 = {&var1433,&var1631,&var796};
_S_and2 far S_and2_1067_1 = {&var187,&var963,&var797};
_S_and2 far S_and2_1068_1 = {&var198,&var961,&var798};
_S_and2 far S_and2_1069_1 = {&var192,&var959,&var799};
_S_and2 far S_and2_1070_1 = {&var195,&var957,&var800};
_S_or2 far S_or2_1052_1 = {NULL,&var802,&var801};
_S_and4 far S_and4_1053_1 = {&var99,&var98,&var97,&var96,&var802};
_S_or2 far S_or2_1123_1 = {&var1433,&var1686,&var803};
_S_or2 far S_or2_1099_1 = {&var1483,&var1051,&var804};
_S_or2 far S_or2_1164_1 = {&var1524,&var1523,&var805};
_S_or2 far S_or2_1150_1 = {&var1533,&var1532,&var806};
_S_or2 far S_or2_1160_1 = {&var944,NULL,&var807};
_S_or2 far S_or2_1137_1 = {&var805,&var1588,&var808};
_S_or2 far S_or2_1135_1 = {&var810,&var808,&var809};
_S_or2 far S_or2_1136_1 = {&var806,&var1588,&var810};
_S_or4 far S_or4_353_1 = {&var1560,&var1559,&var1561,&var1558,&var811};
_S_or2 far S_or2_654_1 = {NULL,NULL,&var812};
_S_and2 far S_and2_653_1 = {&var817,&var812,&var813};
_S_or2 far S_or2_652_1 = {NULL,NULL,&var814};
_S_and2 far S_and2_651_1 = {&var817,&var814,&var815};
_S_or2 far S_or2_650_1 = {NULL,NULL,&var816};
_S_or2 far S_or2_643_1 = {&var819,&var820,&var817};
_S_and2 far S_and2_649_1 = {&var817,&var816,&var818};
_S_and2 far S_and2_646_1 = {&var94,&var830,&var819};
_S_and2 far S_and2_642_1 = {&var95,&var823,&var820};
_S_and2 far S_and2_756_1 = {&var1586,&var1504,&var821};
_S_and2 far S_and2_752_1 = {&var1586,&var1505,&var822};
_S_and3 far S_and3_747_1 = {&var1586,&var95,&var1511,&var823};
_S_or2 far S_or2_755_1 = {&var1506,&var1500,&var824};
_S_or2 far S_or2_750_1 = {&var1504,&var1506,&var825};
_S_or2 far S_or2_746_1 = {&var1506,&var1505,&var826};
_S_and2 far S_and2_728_1 = {&var1500,&var1586,&var827};
_S_or2 far S_or2_722_1 = {&var1507,&var1508,&var828};
_S_or2 far S_or2_716_1 = {&var1565,&var1507,&var829};
_S_and2 far S_and2_714_1 = {&var1508,&var1587,&var830};
_S_and2 far S_and2_713_1 = {&var1565,&var1587,&var831};
_S_and2 far S_and2_740_1 = {&var190,&var1586,&var832};
_S_and2 far S_and2_720_1 = {&var190,&var1517,&var833};
_S_and2 far S_and2_738_1 = {&var1587,&var190,&var834};
_S_or2 far S_or2_732_1 = {&var1587,&var1586,&var835};
_S_or3 far S_or3_725_1 = {NULL,&var838,&var839,&var836};
_S_or4 far S_or4_724_1 = {&var838,NULL,&var840,&var1496,&var837};
_S_or3 far S_or3_715_1 = {NULL,&var827,&var831,&var838};
_S_or2 far S_or2_744_1 = {&var1585,&var842,&var839};
_S_or2 far S_or2_743_1 = {&var1585,&var841,&var840};
_S_and2 far S_and2_664_1 = {NULL,&var1499,&var841};
_S_and3 far S_and3_693_1 = {&var1498,&var1512,NULL,&var842};
_S_and2 far S_and2_698_1 = {NULL,&var857,&var843};
_S_and3 far S_and3_696_1 = {&var1147,NULL,&var857,&var844};
_S_and2 far S_and2_697_1 = {NULL,&var857,&var845};
_S_or2 far S_or2_695_1 = {NULL,NULL,&var846};
_S_and2 far S_and2_694_1 = {&var846,&var857,&var847};
_S_and2 far S_and2_681_1 = {&var857,&var849,&var848};
_S_or4 far S_or4_682_1 = {NULL,NULL,NULL,NULL,&var849};
_S_and2 far S_and2_679_1 = {&var854,&var857,&var850};
_S_and2 far S_and2_670_1 = {&var860,&var857,&var851};
_S_and2 far S_and2_669_1 = {&var1588,&var857,&var852};
_S_or3 far S_or3_668_1 = {NULL,NULL,NULL,&var853};
_S_or2 far S_or2_680_1 = {NULL,NULL,&var854};
_S_and2 far S_and2_667_1 = {&var857,&var853,&var855};
_S_and2 far S_and2_665_1 = {&var1566,&var857,&var856};
_S_or2 far S_or2_656_1 = {&var1587,&var1586,&var857};
_S_or2 far S_or2_161_1 = {&var1153,&var740,&var858};
_S_or3 far S_or3_151_1 = {&var550,&var1152,&var961,&var859};
_S_or2 far S_or2_143_1 = {&var1429,&var344,&var860};
_S_or3 far S_or3_105_1 = {&var1114,&var330,&var331,&var861};
_S_or2 far S_or2_1978_1 = {&var292,&var165,&var862};
_S_or2 far S_or2_125_1 = {NULL,NULL,&var863};
_S_or3 far S_or3_565_1 = {&var865,&var866,&var691,&var864};
_S_and2 far S_and2_554_1 = {&var1326,&var868,&var865};
_S_and2 far S_and2_555_1 = {&var1326,&var918,&var866};
_S_or2 far S_or2_60_1 = {&var918,&var868,&var867};
_S_and2 far S_and2_63_1 = {&var869,&var997,&var868};
_S_and2 far S_and2_62_1 = {&var1595,&var998,&var869};
_S_or2 far S_or2_48_1 = {NULL,NULL,&var870};
_S_or2 far S_or2_35_1 = {&var1246,&var1243,&var871};
_S_or2 far S_or2_39_1 = {&var1246,&var1245,&var872};
_S_or2 far S_or2_20_1 = {&var1147,&var1099,&var873};
_S_or2 far S_or2_8_1 = {&var1605,&var920,&var874};
_S_or2 far S_or2_14_1 = {&var920,&var1606,&var875};
_S_and3 far S_and3_975_1 = {&var200,&var1599,&var895,&var876};
_S_and3 far S_and3_578_1 = {&var895,&var203,&var1599,&var877};
_S_and2 far S_and2_1041_1 = {&var941,&var879,&var878};
_S_or2 far S_or2_1048_1 = {&var1606,&var1605,&var879};
_S_or2 far S_or2_1347_1 = {&var1607,&var1605,&var880};
_S_and3 far S_and3_1346_1 = {&var939,&var880,&var617,&var881};
_S_or2 far S_or2_950_1 = {&var1607,&var1605,&var882};
_S_and3 far S_and3_949_1 = {&var939,&var882,&var632,&var883};
_S_or2 far S_or2_544_1 = {&var1607,&var1605,&var884};
_S_and3 far S_and3_543_1 = {&var939,&var884,&var1327,&var885};
_S_and2 far S_and2_541_1 = {&var90,&var1327,&var886};
_S_or2 far S_or2_227_1 = {&var1607,&var1605,&var887};
_S_and3 far S_and3_226_1 = {&var939,&var887,&var1360,&var888};
_S_and2 far S_and2_224_1 = {&var1360,&var91,&var889};
_S_and3 far S_and3_855_1 = {&var939,&var892,&var657,&var890};
_S_and2 far S_and2_854_1 = {&var436,&var657,&var891};
_S_or2 far S_or2_856_1 = {&var1607,&var1605,&var892};
_S_or2 far S_or2_1258_1 = {&var1607,&var1605,&var893};
_S_or2 far S_or2_6_1 = {&var1606,&var1605,&var894};
_S_or3 far S_or3_5_1 = {&var1607,&var1606,&var1605,&var895};
_S_or2 far S_or2_731_1 = {&var1507,&var1509,&var896};
_S_or2 far S_or2_426_1 = {&var1588,&var901,&var897};
_S_or2 far S_or2_409_1 = {&var1588,&var902,&var898};
_S_or4 far S_or4_410_1 = {&var898,&var1516,&var1515,&var897,&var899};
_S_and2 far S_and2_402_1 = {NULL,&var1580,&var900};
_S_or3 far S_or3_388_1 = {&var1570,&var1568,&var1569,&var901};
_S_or3 far S_or3_373_1 = {&var1578,&var1577,&var1579,&var902};
_S_and2 far S_and2_718_1 = {&var1587,&var1509,&var903};
_S_and2 far S_and2_38_1 = {&var1243,&var1244,&var904};
_S_and2 far S_and2_137_1 = {&var1519,&var1138,&var905};
_S_and2 far S_and2_145_1 = {&var1521,&var1138,&var906};
_S_and2 far S_and2_148_1 = {&var1518,&var1138,&var907};
_S_and2 far S_and2_140_1 = {&var1138,&var1520,&var908};
_S_and2 far S_and2_423_1 = {&var860,&var1572,&var909};
_S_and2 far S_and2_422_1 = {NULL,&var1572,&var910};
_S_and2 far S_and2_421_1 = {NULL,&var1572,&var911};
_S_and2 far S_and2_420_1 = {NULL,&var1572,&var912};
_S_and2 far S_and2_412_1 = {&var1514,&var1580,&var913};
_S_and2 far S_and2_401_1 = {NULL,&var1580,&var914};
_S_and2 far S_and2_405_1 = {&var860,&var1580,&var915};
_S_and2 far S_and2_109_1 = {&var920,&var329,&var916};
_S_and2 far S_and2_58_1 = {&var1596,&var998,&var917};
_S_and2 far S_and2_59_1 = {&var917,&var996,&var918};
_S_and2 far S_and2_42_1 = {&var1244,&var1245,&var919};
_S_and2 far S_and2_11_1 = {&var1604,&var1236,&var920};
_S_and2 far S_and2_31_1 = {&var1167,&var189,&var921};
_S_and2 far S_and2_30_1 = {&var1057,&var1147,&var922};
_S_and2 far S_and2_29_1 = {&var1058,&var1147,&var923};
_S_and2 far S_and2_28_1 = {&var1059,&var1147,&var924};
_S_and2 far S_and2_27_1 = {&var1060,&var1147,&var925};
_S_and2 far S_and2_745_1 = {&var1503,&var1511,&var926};
_S_and2 far S_and2_727_1 = {&var1510,&var1587,&var927};
_S_bol far S_bol_579_1 = {&var1700,&fRM_20_0,&var928};
_S_bol far S_bol_573_1 = {&var1697,&fRM_20_0,&var929};
_S_bol far S_bol_564_1 = {&var1697,&fRM_20_03,&var930};
_S_bol far S_bol_562_1 = {&var1700,&fRM_20_03,&var931};
_S_bol far S_bol_965_1 = {&var1697,&fRM_20_03,&var932};
_S_bol far S_bol_967_1 = {&var1700,&fRM_20_03,&var933};
_S_bol far S_bol_1362_1 = {&var1700,&fRM_20_03,&var934};
_S_bol far S_bol_1364_1 = {&var1697,&fRM_20_03,&var935};
_S_bol far S_bol_248_1 = {&var1697,&fRM_20_03,&var936};
_S_bol far S_bol_250_1 = {&var1700,&fRM_20_03,&var937};
_S_sr far S_sr_81_1 = {array_m81_x_1,&iRM_2_,&var938};
_S_bol far S_bol_80_1 = {&var938,&var143,&var939};
_S_ma far S_ma_83_1 = {array_m83_x_1,NULL,&iRM_8_,&var940};
_S_bol far S_bol_1042_1 = {&var942,NULL,&var941};
_S_sr far S_sr_1049_1 = {array_m1049_x_1,&iRM_2_,&var942};
_S_ovbs far S_ovbs_2056_1 = {&lRM_1_,NULL,&var943,NULL};
_S_ovbs far S_ovbs_1159_1 = {&lRM_1_,NULL,&var944,NULL};
_S_zpfs far S_zpfs_1585_1 = {&var1474,NULL,&var945,NULL,NULL};
_S_zpfs far S_zpfs_1125_1 = {&var1491,NULL,&var946,NULL,NULL};
_S_ma far S_ma_1181_1 = {array_m1181_x_1,&var1443,&iRM_8_,&var947};
_S_ma far S_ma_797_1 = {array_m797_x_1,&var1403,&iRM_8_,&var948};
_S_ma far S_ma_879_1 = {array_m879_x_1,&var1294,&iRM_8_,&var949};
_S_ma far S_ma_1281_1 = {array_m1281_x_1,&var1262,&iRM_8_,&var950};
_S_ma far S_ma_482_1 = {array_m482_x_1,&var1323,&iRM_8_,&var951};
_S_ma far S_ma_159_1 = {array_m159_x_1,&var1356,&iRM_8_,&var952};
_S_zpfs far S_zpfs_1311_1 = {&var1279,NULL,&var953,NULL,NULL};
_S_zpfs far S_zpfs_914_1 = {&var1311,NULL,&var954,NULL,NULL};
_S_zpfs far S_zpfs_1220_1 = {&var1461,NULL,&var955,NULL,NULL};
_S_rs far S_rs_1066_1 = {&var801,&var800,&var956,&vainSBool,NULL};
_S_rs far S_rs_1064_1 = {&var99,&var964,&var957,&vainSBool,NULL};
_S_rs far S_rs_1063_1 = {&var801,&var799,&var958,&vainSBool,NULL};
_S_rs far S_rs_1061_1 = {&var98,&var964,&var959,&vainSBool,NULL};
_S_rs far S_rs_1060_1 = {&var801,&var798,&var960,&vainSBool,NULL};
_S_rs far S_rs_1058_1 = {&var97,&var964,&var961,&vainSBool,NULL};
_S_rs far S_rs_1057_1 = {&var801,&var797,&var962,&vainSBool,NULL};
_S_rs far S_rs_1055_1 = {&var96,&var964,&var963,&vainSBool,NULL};
_S_rs far S_rs_1054_1 = {&var801,&var144,&var964,&vainSBool,NULL};
_S_noto far S_noto_1890_1 = {&var404,&var965};
_S_swtakt far S_swtakt_52_1 = {&var324,&var966,NULL};
_S_noto far S_noto_1040_1 = {&var978,&var967};
_S_noto far S_noto_1014_1 = {&var976,&var968};
_S_noto far S_noto_1026_1 = {&var977,&var969};
_S_rs far S_rs_974_1 = {&var979,&var558,&var970,&vainSBool,NULL};
_S_swtakt far S_swtakt_1408_1 = {&var516,&var971,NULL};
_S_swtakt far S_swtakt_1452_1 = {&var504,&var972,NULL};
_S_swtakt far S_swtakt_1448_1 = {&var498,&var973,NULL};
_S_swtakt far S_swtakt_1850_1 = {&var391,&var974,NULL};
_S_swtakt far S_swtakt_1815_1 = {&var365,&var975,NULL};
_S_rs far S_rs_1013_1 = {&var1050,&var546,&var976,&vainSBool,NULL};
_S_rs far S_rs_1025_1 = {&var1050,&var547,&var977,&vainSBool,NULL};
_S_rs far S_rs_1037_1 = {&var1050,&var548,&var978,&vainSBool,NULL};
_S_rs far S_rs_1047_1 = {&var1050,&var549,&var979,&vainSBool,NULL};
_S_noto far S_noto_1000_1 = {&var564,&var980};
_S_noto far S_noto_1028_1 = {&var564,&var981};
_S_noto far S_noto_1027_1 = {&var568,&var982};
_S_rs far S_rs_1024_1 = {&var542,&var544,&var983,&vainSBool,NULL};
_S_rs far S_rs_1039_1 = {&var1050,&var540,&var984,&vainSBool,NULL};
_S_bol far S_bol_1021_1 = {&var1685,&var254,&var985};
_S_bol far S_bol_1020_1 = {&var1688,&var254,&var986};
_S_noto far S_noto_981_1 = {&var1045,&var987};
_S_bol far S_bol_1018_1 = {&var254,&var1685,&var988};
_S_bol far S_bol_1017_1 = {&var254,&var1688,&var989};
_S_noto far S_noto_1004_1 = {&var1046,&var990};
_S_rs far S_rs_1908_1 = {&var409,&var400,&var991,&vainSBool,NULL};
_S_rs far S_rs_1907_1 = {&var409,&var401,&var992,&vainSBool,NULL};
_S_noto far S_noto_317_1 = {&var772,&var993};
_S_noto far S_noto_299_1 = {&var765,&var994};
_S_noto far S_noto_269_1 = {&var784,&var995};
_S_noto far S_noto_56_1 = {&var1007,&var996};
_S_noto far S_noto_67_1 = {&var1029,&var997};
_S_noto far S_noto_66_1 = {&var964,&var998};
_S_noto far S_noto_1902_1 = {NULL,&var999};
_S_noto far S_noto_1900_1 = {NULL,&var1000};
_S_noto far S_noto_277_1 = {&var203,&var1001};
_S_noto far S_noto_1909_1 = {NULL,&var1002};
_S_noto far S_noto_1884_1 = {NULL,&var1003};
_S_noto far S_noto_264_1 = {&var869,&var1004};
_S_noto far S_noto_321_1 = {&var917,&var1005};
_S_bolz far S_bolz_325_1 = {&iRM_2_,&var1008,&var1006};
_S_provsbr far S_provsbr_320_1 = {&var1068,&var728,&var1083,&var1100,&var1094,&var1089,&var1086,&var1084,&var1098,&var1093,&var1091,&var1087,&iRM_10_,array_m320_Tpr_1,array_m320_type_1,&var1007,&var1008,&var1009,&var1010,&var1011,&var1012,&var1013,&var1014,&var1015,NULL,array_m320_rz_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_orni far S_orni_324_1 = {array_m324_x_1,&iRM_5_,&vainSBool,&var1016};
_S_cntch far S_cntch_328_1 = {&var1016,&var1017,NULL};
_S_bolz far S_bolz_303_1 = {&iRM_20_,&var1031,&var1018};
_S_equz_p far S_equz_p_302_1 = {&var1030,&iRM_0_,&var1019};
_S_decatron far S_decatron_287_1 = {&var764,&var1020,NULL};
_S_noto far S_noto_978_1 = {NULL,&var1021};
_S_noto far S_noto_972_1 = {NULL,&var1022};
_S_andn far S_andn_259_1 = {array_m259_x_1,&iRM_7_,&var1023};
_S_noto far S_noto_261_1 = {NULL,&var1024};
_S_noto far S_noto_271_1 = {NULL,&var1025};
_S_noto far S_noto_265_1 = {NULL,&var1026};
_S_noto far S_noto_256_1 = {NULL,&var1027};
_S_noto far S_noto_253_1 = {NULL,&var1028};
_S_provsbr far S_provsbr_263_1 = {&var1070,&var781,&var1083,&var1100,&var1094,&var1089,&var1086,&var1084,&var1098,&var1093,&var1091,&var1087,&iRM_10_,array_m263_Tpr_1,array_m263_type_1,&var1029,&var1030,&var1031,&var1032,&var1033,&var1034,&var1035,&var1036,&var1037,NULL,array_m263_rz_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_rs far S_rs_1382_1 = {&var1039,&var538,&var1038,&vainSBool,NULL};
_S_provsbr far S_provsbr_1383_1 = {&var1038,NULL,&var1083,&var1100,&var1094,&var1089,&var1086,&var1084,&var1098,&var1093,&var1091,&var1087,&iRM_6_,array_m1383_Tpr_1,array_m1383_type_1,&var1039,&vainSInt,&vainSInt,&vainSBool,&var1040,&var1041,&var1042,&var1043,&var1044,NULL,array_m1383_rz_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_abs_subf far S_abs_subf_984_1 = {&var254,&var1688,NULL,&vainSFloat,&var1045};
_S_abs_subf far S_abs_subf_997_1 = {&var1685,&var254,NULL,&vainSFloat,&var1046};
_S_noto far S_noto_638_1 = {&var732,&var1047};
_S_noto far S_noto_586_1 = {&var748,&var1048};
_S_noto far S_noto_49_1 = {&var250,&var1049};
_S_noto far S_noto_1001_1 = {&var1251,&var1050};
_S_rs far S_rs_1008_1 = {&var541,&var345,&var1051,&vainSBool,NULL};
_S_rs far S_rs_1005_1 = {&var545,&var540,&var1052,&vainSBool,NULL};
_S_rs far S_rs_1007_1 = {&var1050,&var345,&var1053,&vainSBool,NULL};
_S_rs far S_rs_1002_1 = {&var1050,&var543,&var1054,&vainSBool,NULL};
_S_noto far S_noto_575_1 = {NULL,&var1055};
_S_noto far S_noto_577_1 = {NULL,&var1056};
_S_noto far S_noto_25_1 = {NULL,&var1057};
_S_noto far S_noto_24_1 = {NULL,&var1058};
_S_noto far S_noto_23_1 = {NULL,&var1059};
_S_noto far S_noto_22_1 = {NULL,&var1060};
_S_newstage far S_newstage_587_1 = {&var67,&var64,NULL,NULL,&var1061};
_S_noto far S_noto_576_1 = {NULL,&var1062};
_S_noto far S_noto_574_1 = {NULL,&var1063};
_S_noto far S_noto_334_1 = {&var723,&var1064};
_S_noto far S_noto_338_1 = {&var722,&var1065};
_S_noto far S_noto_971_1 = {&var860,&var1066};
_S_rs far S_rs_735_1 = {&var720,&var327,&var1067,&vainSBool,NULL};
_S_rs far S_rs_330_1 = {&var724,&var725,&var1068,&vainSBool,NULL};
_S_rs far S_rs_326_1 = {&var726,&var727,&var1069,&vainSBool,NULL};
_S_rs far S_rs_283_1 = {&var780,&var766,&var1070,&vainSBool,NULL};
_S_orni far S_orni_279_1 = {array_m279_x_1,&iRM_5_,&vainSBool,&var1071};
_S_cntch far S_cntch_282_1 = {&var1071,&var1072,NULL};
_S_noto far S_noto_1421_1 = {&var1091,&var1073};
_S_noto far S_noto_1477_1 = {&var1093,&var1074};
_S_noto far S_noto_1479_1 = {&var1098,&var1075};
_S_noto far S_noto_1831_1 = {&var1084,&var1076};
_S_noto far S_noto_1866_1 = {&var1087,&var1077};
_S_noto far S_noto_1846_1 = {&var974,&var1078};
_S_noto far S_noto_1809_1 = {&var975,&var1079};
_S_noto far S_noto_1449_1 = {&var973,&var1080};
_S_noto far S_noto_1444_1 = {&var972,&var1081};
_S_noto far S_noto_1404_1 = {&var971,&var1082};
_S_rs far S_rs_1837_1 = {&var523,&var349,&var1083,&vainSBool,NULL};
_S_rs far S_rs_1825_1 = {&var364,&var361,&var1084,&vainSBool,NULL};
_S_rs far S_rs_1816_1 = {&var360,&var975,&var1085,&vainSBool,NULL};
_S_rs far S_rs_1891_1 = {&var523,&var378,&var1086,&vainSBool,NULL};
_S_rs far S_rs_1862_1 = {&var386,&var385,&var1087,&vainSBool,NULL};
_S_rs far S_rs_1851_1 = {&var388,&var974,&var1088,&vainSBool,NULL};
_S_rs far S_rs_1435_1 = {&var523,&var509,&var1089,&vainSBool,NULL};
_S_kvf far S_kvf_1422_1 = {&var1092,&var510,&fRM_0_0,&var1090,&vainSInt,&vainSInt,NULL,NULL,NULL};
_S_rs far S_rs_1418_1 = {&var515,&var510,&var1091,&vainSBool,NULL};
_S_rs far S_rs_1409_1 = {&var512,&var971,&var1092,&vainSBool,NULL};
_S_rs far S_rs_1468_1 = {&var505,&var500,&var1093,&vainSBool,NULL};
_S_rs far S_rs_1488_1 = {&var523,&var506,&var1094,&vainSBool,NULL};
_S_rs far S_rs_1454_1 = {&var503,&var972,&var1095,&vainSBool,NULL};
_S_kvf far S_kvf_1469_1 = {&var1095,&var500,&fRM_0_0,&var1096,&vainSInt,&vainSInt,NULL,NULL,NULL};
_S_cntch far S_cntch_1393_1 = {&var525,&var1097,NULL};
_S_rs far S_rs_1474_1 = {&var497,&var491,&var1098,&vainSBool,NULL};
_S_rs far S_rs_26_1 = {&var1147,&var921,&var1099,&vainSBool,NULL};
_S_rs far S_rs_1489_1 = {&var523,&var490,&var1100,&vainSBool,NULL};
_S_noto far S_noto_1371_1 = {&var519,&var1101};
_S_noto far S_noto_1369_1 = {&var920,&var1102};
_S_rs far S_rs_627_1 = {&var1482,&var735,&var1103,&vainSBool,NULL};
_S_rs far S_rs_612_1 = {&var1482,&var742,&var1104,&vainSBool,NULL};
_S_rs far S_rs_639_1 = {&var1482,&var743,&var1105,&vainSBool,NULL};
_S_rs far S_rs_623_1 = {&var1482,&var754,&var1106,&vainSBool,NULL};
_S_rs far S_rs_607_1 = {&var1482,&var757,&var1107,&vainSBool,NULL};
_S_rs far S_rs_605_1 = {&var1482,&var759,&var1108,&vainSBool,NULL};
_S_rs far S_rs_593_1 = {&var762,&var1485,&var1109,&vainSBool,NULL};
_S_rsun far S_rsun_1385_1 = {&var523,&var1235,&vainSLong,&var1110,NULL};
_S_noto far S_noto_1312_1 = {NULL,&var1111};
_S_noto far S_noto_1785_1 = {NULL,&var1112};
_S_noto far S_noto_1759_1 = {NULL,&var1113};
_S_noto far S_noto_108_1 = {&var920,&var1114};
_S_noto far S_noto_107_1 = {&var1119,&var1115};
_S_rs far S_rs_603_1 = {&var1482,&var761,&var1116,&vainSBool,NULL};
_S_orni far S_orni_1158_1 = {array_m1158_x_1,&iRM_6_,&var1117,&vainSLong};
_S_orni far S_orni_1146_1 = {array_m1146_x_1,&iRM_5_,&var1118,&vainSLong};
_S_rs far S_rs_106_1 = {&var861,&var916,&var1119,&vainSBool,NULL};
_S_noto far S_noto_1788_1 = {&var427,&var1120};
_S_noto far S_noto_1787_1 = {&var426,&var1121};
_S_noto far S_noto_1799_1 = {NULL,&var1122};
_S_noto far S_noto_1781_1 = {NULL,&var1123};
_S_newstage far S_newstage_1783_1 = {&var443,&var439,&var442,&var438,&vainSBool};
_S_noto far S_noto_1727_1 = {&var1213,&var1124};
_S_rs far S_rs_1619_1 = {&var186,&var214,&var1125,&vainSBool,NULL};
_S_rs far S_rs_1618_1 = {&var244,&var216,&var1126,&vainSBool,NULL};
_S_rs far S_rs_1617_1 = {&var186,&var218,&var1127,&vainSBool,NULL};
_S_rs far S_rs_1616_1 = {&var245,&var220,&var1128,&vainSBool,NULL};
_S_rs far S_rs_1645_1 = {&var189,&var222,&var1129,&vainSBool,NULL};
_S_rs far S_rs_1644_1 = {&var460,&var224,&var1130,&vainSBool,NULL};
_S_rs far S_rs_1643_1 = {&var189,&var226,&var1131,&vainSBool,NULL};
_S_rs far S_rs_1642_1 = {&var462,&var228,&var1132,&vainSBool,NULL};
_S_noto far S_noto_1212_1 = {NULL,&var1133};
_S_noto far S_noto_1196_1 = {NULL,&var1134};
_S_noto far S_noto_497_1 = {NULL,&var1135};
_S_ma far S_ma_1424_1 = {array_m1424_x_1,&var1110,&iRM_16_,&var1136};
_S_noto far S_noto_1379_1 = {&var776,&var1137};
_S_noto far S_noto_135_1 = {&var920,&var1138};
_S_equz_p far S_equz_p_1765_1 = {NULL,&iRM_5_,&var1139};
_S_equz_p far S_equz_p_1764_1 = {NULL,&iRM_4_,&var1140};
_S_equz_p far S_equz_p_1763_1 = {NULL,&iRM_3_,&var1141};
_S_equz_p far S_equz_p_1761_1 = {NULL,&iRM_1_,&vainSBool};
_S_equz_p far S_equz_p_1762_1 = {NULL,&iRM_2_,&var1142};
_S_noto far S_noto_1818_1 = {NULL,&var1143};
_S_noto far S_noto_1813_1 = {NULL,&var1144};
_S_noto far S_noto_1855_1 = {NULL,&var1145};
_S_noto far S_noto_1863_1 = {NULL,&var1146};
_S_noto far S_noto_12_1 = {&var1604,&var1147};
_S_rs far S_rs_1922_1 = {&var312,&var413,&var1148,&vainSBool,NULL};
_S_rs far S_rs_1702_1 = {&var455,&var239,&var1149,&vainSBool,NULL};
_S_rs far S_rs_1701_1 = {&var199,&var240,&var1150,&vainSBool,NULL};
_S_rs far S_rs_1699_1 = {&var456,&var241,&var1151,&vainSBool,NULL};
_S_rs far S_rs_1698_1 = {&var199,&var242,&var1152,&vainSBool,NULL};
_S_rs far S_rs_1696_1 = {&var457,&var243,&var1153,&vainSBool,NULL};
_S_equz_p far S_equz_p_98_1 = {NULL,&iRM_10_,&var1154};
_S_noto far S_noto_173_1 = {NULL,&var1155};
_S_rs far S_rs_2115_1 = {&var2,&var8,&var1156,&vainSBool,NULL};
_S_rs far S_rs_2112_1 = {&var458,&var54,&var1157,&vainSBool,NULL};
_S_rs far S_rs_1671_1 = {&var459,&var236,&var1158,&vainSBool,NULL};
_S_rs far S_rs_1665_1 = {&var189,&var221,&var1159,&vainSBool,NULL};
_S_rs far S_rs_1664_1 = {&var186,&var222,&var1160,&vainSBool,NULL};
_S_rs far S_rs_1660_1 = {&var461,&var224,&var1161,&vainSBool,NULL};
_S_rs far S_rs_1662_1 = {&var460,&var223,&var1162,&vainSBool,NULL};
_S_rs far S_rs_1659_1 = {&var189,&var225,&var1163,&vainSBool,NULL};
_S_rs far S_rs_1658_1 = {&var186,&var226,&var1164,&vainSBool,NULL};
_S_rs far S_rs_1654_1 = {&var463,&var228,&var1165,&vainSBool,NULL};
_S_rs far S_rs_1656_1 = {&var462,&var227,&var1166,&vainSBool,NULL};
_S_rs far S_rs_19_1 = {&var873,&var333,&var1167,&vainSBool,NULL};
_S_equz_p far S_equz_p_97_1 = {NULL,&iRM_9_,&var1168};
_S_equz_p far S_equz_p_96_1 = {NULL,&iRM_8_,&var1169};
_S_noto far S_noto_915_1 = {NULL,&var1170};
_S_equz_p far S_equz_p_95_1 = {NULL,&iRM_7_,&var1171};
_S_equz_p far S_equz_p_94_1 = {NULL,&iRM_6_,&var1172};
_S_equz_p far S_equz_p_93_1 = {NULL,&iRM_5_,&var1173};
_S_rs far S_rs_1639_1 = {&var186,&var213,&var1174,&vainSBool,NULL};
_S_rs far S_rs_1637_1 = {&var68,&var214,&var1175,&vainSBool,NULL};
_S_rs far S_rs_1634_1 = {&var473,&var216,&var1176,&vainSBool,NULL};
_S_rs far S_rs_1636_1 = {&var244,&var215,&var1177,&vainSBool,NULL};
_S_rs far S_rs_1633_1 = {&var186,&var217,&var1178,&vainSBool,NULL};
_S_rs far S_rs_1631_1 = {&var69,&var218,&var1179,&vainSBool,NULL};
_S_rs far S_rs_2038_1 = {&var71,&var422,&var1180,&vainSBool,NULL};
_S_rs far S_rs_2033_1 = {&var72,&var423,&var1181,&vainSBool,NULL};
_S_equz_p far S_equz_p_292_1 = {&var1020,&iRM_0_,&var1182};
_S_noto far S_noto_2039_1 = {&var1180,&var1183};
_S_noto far S_noto_2029_1 = {&var337,&var1184};
_S_noto far S_noto_2013_1 = {&var1186,&var1185};
_S_rs far S_rs_2012_1 = {&var4,&var419,&var1186,&vainSBool,NULL};
_S_noto far S_noto_2001_1 = {&var1188,&var1187};
_S_rs far S_rs_2000_1 = {&var6,&var416,&var1188,&vainSBool,NULL};
_S_noto far S_noto_2034_1 = {&var1181,&var1189};
_S_noto far S_noto_2025_1 = {&var336,&var1190};
_S_noto far S_noto_1934_1 = {&var1192,&var1191};
_S_rs far S_rs_1933_1 = {&var311,&var414,&var1192,&vainSBool,NULL};
_S_noto far S_noto_1923_1 = {&var1148,&var1193};
_S_noto far S_noto_1929_1 = {&var334,&var1194};
_S_noto far S_noto_1917_1 = {&var335,&var1195};
_S_rs far S_rs_1628_1 = {&var474,&var220,&var1196,&vainSBool,NULL};
_S_rs far S_rs_1630_1 = {&var245,&var219,&var1197,&vainSBool,NULL};
_S_rs far S_rs_1615_1 = {&var186,&var205,&var1198,&vainSBool,NULL};
_S_rs far S_rs_1613_1 = {&var475,&var206,&var1199,&vainSBool,NULL};
_S_rs far S_rs_1612_1 = {&var186,&var207,&var1200,&vainSBool,NULL};
_S_rs far S_rs_1610_1 = {&var476,&var208,&var1201,&vainSBool,NULL};
_S_noto far S_noto_1722_1 = {NULL,&var1202};
_S_noto far S_noto_1721_1 = {NULL,&var1203};
_S_noto far S_noto_1720_1 = {NULL,&var1204};
_S_noto far S_noto_1719_1 = {NULL,&var1205};
_S_noto far S_noto_1718_1 = {NULL,&var1206};
_S_noto far S_noto_1717_1 = {NULL,&var1207};
_S_noto far S_noto_1747_1 = {NULL,&var1208};
_S_noto far S_noto_1741_1 = {NULL,&var1209};
_S_noto far S_noto_1746_1 = {NULL,&var1210};
_S_noto far S_noto_1744_1 = {NULL,&var1211};
_S_noto far S_noto_1745_1 = {NULL,&var1212};
_S_andn far S_andn_1730_1 = {array_m1730_x_1,&iRM_17_,&var1213};
_S_noto far S_noto_1739_1 = {NULL,&var1214};
_S_noto far S_noto_1740_1 = {NULL,&var1215};
_S_noto far S_noto_1738_1 = {NULL,&var1216};
_S_rs far S_rs_1609_1 = {&var1221,&var209,&var1217,&vainSBool,NULL};
_S_rs far S_rs_1607_1 = {&var477,&var210,&var1218,&vainSBool,NULL};
_S_rs far S_rs_1606_1 = {&var1221,&var211,&var1219,&vainSBool,NULL};
_S_rs far S_rs_1604_1 = {&var478,&var212,&var1220,&vainSBool,NULL};
_S_newstage far S_newstage_2059_1 = {&var1233,&var1227,&var1232,&var1226,&var1221};
_S_samhd far S_samhd_2061_1 = {&var481,&var482,&var482,&var1218,&var1217,&var1218,&var1217,NULL,NULL,NULL,NULL,&bRM_1_,NULL,NULL,NULL,&var1222,&var1223,&vainSBool,&var1224,&var1225,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1226,&var1227,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_samhd far S_samhd_2055_1 = {&var481,&var483,&var483,&var1220,&var1219,&var1220,&var1219,NULL,NULL,NULL,NULL,&bRM_1_,NULL,NULL,NULL,&var1228,&var1229,&vainSBool,&var1230,&var1231,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1232,&var1233,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_orni far S_orni_1386_1 = {array_m1386_x_1,&iRM_5_,&var1234,&var1235};
_S_noto far S_noto_77_1 = {&var339,&var1236};
_S_maz far S_maz_298_1 = {array_m298_x_1,NULL,&iRM_3_,&var1237};
_S_maz far S_maz_289_1 = {array_m289_x_1,NULL,&iRM_3_,&var1238};
_S_rs far S_rs_1459_1 = {&var494,&var973,&var1239,&vainSBool,NULL};
_S_kvf far S_kvf_1463_1 = {&var1239,&var491,&fRM_0_0,&var1240,&vainSInt,&vainSInt,NULL,NULL,NULL};
_S_kvf far S_kvf_1873_1 = {&var394,&var382,&fRM_0_0,&var1241,&vainSInt,&vainSInt,NULL,NULL,NULL};
_S_kvf far S_kvf_1834_1 = {&var354,&var351,&fRM_0_0,&var1242,&vainSInt,&vainSInt,NULL,NULL,NULL};
_S_equz_p far S_equz_p_37_1 = {NULL,&iRM_1_,&var1243};
_S_noto far S_noto_34_1 = {&var1246,&var1244};
_S_equz_p far S_equz_p_41_1 = {NULL,&iRM_2_,&var1245};
_S_equz_p far S_equz_p_32_1 = {NULL,&iRM_3_,&var1246};
_S_noto far S_noto_1876_1 = {&var1088,&var1247};
_S_rs far S_rs_274_1 = {&var782,&var783,&var1248,&vainSBool,NULL};
_S_orn far S_orn_584_1 = {array_m584_x_1,&iRM_5_,&var1249};
_S_noto far S_noto_991_1 = {NULL,&var1250};
_S_rs far S_rs_982_1 = {&var559,&var876,&var1251,&vainSBool,NULL};
_S_rs far S_rs_615_1 = {&var737,&var739,&var1252,&vainSBool,NULL};
_S_noto far S_noto_1366_1 = {&var919,&var1253};
_S_orn far S_orn_1345_1 = {array_m1345_x_1,&iRM_8_,&var1254};
_S_noto far S_noto_1344_1 = {&var1422,&var1255};
_S_noto far S_noto_1343_1 = {&var1432,&var1256};
_S_noto far S_noto_1326_1 = {&var920,&var1257};
_S_noto far S_noto_1335_1 = {NULL,&var1258};
_S_charint far S_charint_1272_1 = {&var1261,&var1259};
_S_ornc far S_ornc_1280_1 = {array_m1280_x_1,&iRM_3_,&var1260,&var1261};
_S_fsumz far S_fsumz_1273_1 = {&var1259,&iRM_1_,&var1262};
_S_cnshd far S_cnshd_1282_1 = {NULL,&var1691,&var950,&var258,&var1260,&var604,&var600,&iRM_1_,array_m1282_Lt_fw_1,array_m1282_Vr_fw_1,&iRM_1_,array_m1282_Lt_bw_1,array_m1282_Vr_bw_1,NULL,NULL,NULL,NULL,&var1263,&vainSBool,&var1264,&var1265,&var1266,&var1267,&var1268,&var1269,&var1270,&var1271,&var1272,&var1273,NULL,NULL,NULL};
_S_zpfs far S_zpfs_1301_1 = {&var1282,&fRM_2_0,&var1274,NULL,NULL};
_S_zpfs far S_zpfs_1303_1 = {&var1281,&fRM_3_0,&var1275,NULL,NULL};
_S_fnapb far S_fnapb_1310_1 = {&var1691,&var950,&var603,NULL,&var1265,&var1272,NULL,NULL,NULL,NULL,NULL,&iRM_60_,NULL,NULL,NULL,&var1276,&var1277,&var1278,&var1279,&var1280,&var1281,&var1282,&vainSFloat,NULL,array_m1310_x0_1,array_m1310_tim0_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_newstage far S_newstage_892_1 = {&var1292,&var1260,&var1295,&var1263,&var1283};
_S_rs far S_rs_613_1 = {&var738,&var742,&var1284,&vainSBool,NULL};
_S_noto far S_noto_969_1 = {&var904,&var1285};
_S_orn far S_orn_948_1 = {array_m948_x_1,&iRM_8_,&var1286};
_S_noto far S_noto_947_1 = {&var1422,&var1287};
_S_noto far S_noto_946_1 = {&var1432,&var1288};
_S_noto far S_noto_929_1 = {&var920,&var1289};
_S_noto far S_noto_938_1 = {NULL,&var1290};
_S_charint far S_charint_872_1 = {&var1293,&var1291};
_S_ornc far S_ornc_878_1 = {array_m878_x_1,&iRM_3_,&var1292,&var1293};
_S_fsumz far S_fsumz_873_1 = {&var1291,&iRM_1_,&var1294};
_S_cnshd far S_cnshd_880_1 = {NULL,&var1694,&var949,&var262,&var1292,&var639,&var640,&iRM_1_,array_m880_Lt_fw_1,array_m880_Vr_fw_1,&iRM_1_,array_m880_Lt_bw_1,array_m880_Vr_bw_1,NULL,NULL,NULL,NULL,&var1295,&vainSBool,&var1296,&var1297,&var1298,&var1299,&var1300,&var1301,&var1302,&var1303,&var1304,&var1305,NULL,NULL,NULL};
_S_zpfs far S_zpfs_904_1 = {&var1314,&fRM_2_0,&var1306,NULL,NULL};
_S_zpfs far S_zpfs_905_1 = {&var1313,&fRM_3_0,&var1307,NULL,NULL};
_S_fnapb far S_fnapb_913_1 = {&var1694,&var949,&var638,NULL,&var1297,&var1304,NULL,NULL,NULL,NULL,NULL,&iRM_60_,NULL,NULL,NULL,&var1308,&var1309,&var1310,&var1311,&var1312,&var1313,&var1314,&vainSFloat,NULL,array_m913_x0_1,array_m913_tim0_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_noto far S_noto_566_1 = {&var919,&var1315};
_S_noto far S_noto_539_1 = {&var1422,&var1316};
_S_noto far S_noto_538_1 = {&var1432,&var1317};
_S_noto far S_noto_523_1 = {&var920,&var1318};
_S_noto far S_noto_530_1 = {NULL,&var1319};
_S_charint far S_charint_475_1 = {&var1322,&var1320};
_S_ornc far S_ornc_481_1 = {array_m481_x_1,&iRM_3_,&var1321,&var1322};
_S_fsumz far S_fsumz_476_1 = {&var1320,&iRM_1_,&var1323};
_S_cnshd far S_cnshd_484_1 = {NULL,&var1704,&var951,&var266,&var1321,&var710,&var704,&iRM_2_,array_m484_Lt_fw_1,array_m484_Vr_fw_1,&iRM_1_,array_m484_Lt_bw_1,array_m484_Vr_bw_1,NULL,NULL,NULL,NULL,&var1324,&vainSBool,&var1325,&var1326,&var1327,&var1328,&var1329,&var1330,&var1331,&var1332,&var1333,&var1334,NULL,NULL,NULL};
_S_zpfs far S_zpfs_504_1 = {&var1343,&fRM_2_0,&var1335,NULL,NULL};
_S_zpfs far S_zpfs_506_1 = {&var1342,&fRM_3_0,&var1336,NULL,NULL};
_S_fnapb far S_fnapb_511_1 = {&var1704,&var951,&var708,NULL,&var1326,&var1333,NULL,NULL,NULL,NULL,NULL,&iRM_150_,NULL,NULL,NULL,&var1337,&var1338,&var1339,&var1340,&var1341,&var1342,&var1343,&vainSFloat,NULL,array_m511_x0_1,array_m511_tim0_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_noto far S_noto_631_1 = {NULL,&var1344};
_S_noto far S_noto_252_1 = {&var904,&var1345};
_S_newstage far S_newstage_200_1 = {&var1354,&var1321,&var1357,&var1324,&var1346};
_S_rs far S_rs_610_1 = {&var733,&var745,&var1347,&vainSBool,NULL};
_S_orn far S_orn_223_1 = {array_m223_x_1,&iRM_12_,&var1348};
_S_noto far S_noto_222_1 = {&var1422,&var1349};
_S_noto far S_noto_221_1 = {&var1432,&var1350};
_S_noto far S_noto_206_1 = {&var920,&var1351};
_S_noto far S_noto_213_1 = {NULL,&var1352};
_S_charint far S_charint_152_1 = {&var1355,&var1353};
_S_ornc far S_ornc_158_1 = {array_m158_x_1,&iRM_3_,&var1354,&var1355};
_S_fsumz far S_fsumz_153_1 = {&var1353,&iRM_1_,&var1356};
_S_cnshd far S_cnshd_163_1 = {NULL,&var1682,&var952,&var270,&var1354,&var690,&var683,&iRM_2_,array_m163_Lt_fw_1,array_m163_Vr_fw_1,&iRM_1_,array_m163_Lt_bw_1,array_m163_Vr_bw_1,NULL,NULL,NULL,NULL,&var1357,&vainSBool,&var1358,&var1359,&var1360,&var1361,&var1362,&var1363,&var1364,&var1365,&var1366,&var1367,NULL,NULL,NULL};
_S_fnapb far S_fnapb_192_1 = {&var1682,&var952,&var686,NULL,&var1359,&var1366,NULL,NULL,NULL,NULL,NULL,&iRM_150_,NULL,NULL,NULL,&var1368,&var1369,&var1370,&var1371,&var1372,&var1373,&var1374,&vainSFloat,NULL,array_m192_x0_1,array_m192_tim0_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_rs far S_rs_636_1 = {&var744,&var747,&var1375,&vainSBool,NULL};
_S_newstage far S_newstage_451_1 = {&var1394,&var1385,&var1393,&var1384,&var1376};
_S_samhd far S_samhd_455_1 = {NULL,&var713,&var713,&var321,&var320,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_0_,NULL,NULL,NULL,&var1377,&var1378,&var1379,&var1380,&var1381,&var1382,&vainSBool,&vainSBool,&var1383,&var1384,&var1385,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_samhd far S_samhd_449_1 = {NULL,&var714,&var714,&var319,&var318,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_0_,NULL,NULL,NULL,&var1386,&var1387,&var1388,&var1389,&var1390,&var1391,&vainSBool,&vainSBool,&var1392,&var1393,&var1394,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_orn far S_orn_853_1 = {array_m853_x_1,&iRM_10_,&var1395};
_S_noto far S_noto_852_1 = {&var1422,&var1396};
_S_noto far S_noto_851_1 = {&var1432,&var1397};
_S_noto far S_noto_832_1 = {&var920,&var1398};
_S_noto far S_noto_843_1 = {NULL,&var1399};
_S_charint far S_charint_790_1 = {&var1402,&var1400};
_S_ornc far S_ornc_796_1 = {array_m796_x_1,&iRM_3_,&var1401,&var1402};
_S_fsumz far S_fsumz_791_1 = {&var1400,&iRM_1_,&var1403};
_S_cnshd far S_cnshd_800_1 = {NULL,&var1697,&var948,&var948,&var1401,&var663,&var577,&iRM_2_,array_m800_Lt_fw_1,array_m800_Vr_fw_1,&iRM_1_,array_m800_Lt_bw_1,array_m800_Vr_bw_1,NULL,NULL,NULL,NULL,&var1404,&vainSBool,&var1405,&var1406,&var1407,&var1408,&var1409,&var1410,&var1411,&var1412,&var1413,&var1414,NULL,NULL,NULL};
_S_fnapb far S_fnapb_820_1 = {&var1697,&var948,&var659,NULL,&var1406,&var1413,NULL,NULL,NULL,NULL,NULL,&iRM_80_,NULL,NULL,NULL,&var1415,&var1416,&var1417,&var1418,&var1419,&var1420,&var1421,&vainSFloat,NULL,array_m820_x0_1,array_m820_tim0_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_cnshd far S_cnshd_1564_1 = {NULL,&var1688,&var254,&var254,&var485,&var488,&lRM_1_,&iRM_1_,array_m1564_Lt_fw_1,array_m1564_Vr_fw_1,&iRM_1_,array_m1564_Lt_bw_1,array_m1564_Vr_bw_1,NULL,NULL,NULL,&fRM_0_0,&var1422,&vainSBool,&vainSFloat,&var1423,&var1424,&var1425,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1426,NULL,NULL,NULL};
_S_newstage far S_newstage_1225_1 = {&var1440,&var1401,&var1445,&var1404,&var1427};
_S_orn far S_orn_1255_1 = {array_m1255_x_1,&iRM_10_,&var1428};
_S_orn far S_orn_141_1 = {array_m141_x_1,&iRM_5_,&var1429};
_S_noto far S_noto_1254_1 = {&var1422,&var1430};
_S_noto far S_noto_1253_1 = {&var1432,&var1431};
_S_cnshd far S_cnshd_1100_1 = {NULL,&var1685,&var254,&var254,&var804,&var486,&lRM_1_,&iRM_1_,array_m1100_Lt_fw_1,array_m1100_Vr_fw_1,&iRM_1_,array_m1100_Lt_bw_1,array_m1100_Vr_bw_1,NULL,NULL,NULL,&fRM_0_0,&var1432,&vainSBool,&vainSFloat,&var1433,&var1434,&var1435,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1436,NULL,NULL,NULL};
_S_noto far S_noto_1236_1 = {&var920,&var1437};
_S_noto far S_noto_1245_1 = {NULL,&var1438};
_S_charint far S_charint_1175_1 = {&var1441,&var1439};
_S_ornc far S_ornc_1184_1 = {array_m1184_x_1,&iRM_3_,&var1440,&var1441};
_S_noto far S_noto_595_1 = {NULL,&var1442};
_S_fsumz far S_fsumz_1176_1 = {&var1439,&iRM_1_,&var1443};
_S_rs far S_rs_608_1 = {&var755,&var757,&var1444,&vainSBool,NULL};
_S_cnshd far S_cnshd_1185_1 = {NULL,&var1700,&var947,&var947,&var1440,&var580,&var573,&iRM_2_,array_m1185_Lt_fw_1,array_m1185_Vr_fw_1,&iRM_1_,array_m1185_Lt_bw_1,array_m1185_Vr_bw_1,NULL,NULL,NULL,NULL,&var1445,&vainSBool,&var1446,&var1447,&var1448,&var1449,&var1450,&var1451,&var1452,&var1453,&var1454,&var1455,NULL,NULL,NULL};
_S_zpfs far S_zpfs_1205_1 = {&var1464,&fRM_2_0,&var1456,NULL,NULL};
_S_zpfs far S_zpfs_1214_1 = {&var1463,&fRM_3_0,&var1457,NULL,NULL};
_S_fnapb far S_fnapb_1219_1 = {&var1700,&var947,&var581,NULL,&var1447,&var1454,NULL,NULL,NULL,NULL,NULL,&iRM_80_,NULL,NULL,NULL,&var1458,&var1459,&var1460,&var1461,&var1462,&var1463,&var1464,&vainSFloat,NULL,array_m1219_x0_1,array_m1219_tim0_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_noto far S_noto_1549_1 = {NULL,&var1465};
_S_rs far S_rs_628_1 = {&var758,&var759,&var1466,&vainSBool,NULL};
_S_zpfs far S_zpfs_1577_1 = {&var1477,&fRM_2_0,&var1467,NULL,NULL};
_S_zpfs far S_zpfs_1581_1 = {&var1476,&fRM_3_0,&var1468,NULL,NULL};
_S_samhd far S_samhd_1567_1 = {NULL,&var488,&var488,&var1424,&var1425,&var1471,&var1472,NULL,NULL,NULL,NULL,&bRM_3_,NULL,NULL,NULL,&vainSBool,&vainSBool,&var1469,&var1470,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_fnapb far S_fnapb_1584_1 = {&var1688,&var254,&var484,NULL,&var1423,NULL,NULL,NULL,NULL,NULL,NULL,&iRM_20_,NULL,NULL,NULL,&var1471,&var1472,&var1473,&var1474,&var1475,&var1476,&var1477,&vainSFloat,NULL,array_m1584_x0_1,array_m1584_tim0_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_zpfs far S_zpfs_1116_1 = {&var1494,&fRM_2_0,&var1478,NULL,NULL};
_S_zpfs far S_zpfs_1120_1 = {&var1493,&fRM_3_0,&var1479,NULL,NULL};
_S_noto far S_noto_1085_1 = {NULL,&var1480};
_S_orn far S_orn_1071_1 = {array_m1071_x_1,&iRM_8_,&var1481};
_S_noto far S_noto_597_1 = {&var1485,&var1482};
_S_rs far S_rs_618_1 = {&var760,&var761,&var1483,&vainSBool,NULL};
_S_orn far S_orn_585_1 = {array_m585_x_1,&iRM_18_,&var1484};
_S_rs far S_rs_583_1 = {&var1249,&var877,&var1485,&vainSBool,NULL};
_S_samhd far S_samhd_1106_1 = {NULL,&var486,&var486,&var1434,&var1435,&var1488,&var1489,&var93,&var93,&var92,&var92,&bRM_3_,NULL,NULL,NULL,&vainSBool,&vainSBool,&var1486,&var1487,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_fnapb far S_fnapb_1124_1 = {&var1685,&var254,&var803,NULL,&var1433,NULL,NULL,NULL,NULL,NULL,NULL,&iRM_20_,NULL,NULL,NULL,&var1488,&var1489,&var1490,&var1491,&var1492,&var1493,&var1494,&vainSFloat,NULL,array_m1124_x0_1,array_m1124_tim0_1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_noto far S_noto_708_1 = {NULL,&var1495};
_S_vmemb far S_vmemb_729_1 = {&var1497,&var1496,NULL};
_S_noto far S_noto_737_1 = {&var94,&var1497};
_S_vmemb far S_vmemb_700_1 = {&var1495,&var1498,NULL};
_S_vmemb far S_vmemb_663_1 = {&var1513,&var1499,NULL};
_S_newstage far S_newstage_772_1 = {&var1557,&var1548,&var1556,&var1547,&var1500};
_S_newstage far S_newstage_1154_1 = {&var1539,&var1530,&var1538,&var1529,&var1501};
_S_newstage far S_newstage_380_1 = {&var1584,&var1575,&var1583,&var1574,&var1502};
_S_noto far S_noto_748_1 = {&var95,&var1503};
_S_rs far S_rs_754_1 = {&var824,&var1502,&var1504,&vainSBool,NULL};
_S_rs far S_rs_749_1 = {&var825,&var926,&var1505,&vainSBool,NULL};
_S_noto far S_noto_741_1 = {&var1586,&var1506};
_S_noto far S_noto_739_1 = {&var1587,&var1507};
_S_rs far S_rs_717_1 = {&var829,&var1502,&var1508,&vainSBool,NULL};
_S_rs far S_rs_721_1 = {&var828,&var1500,&var1509,&vainSBool,NULL};
_S_rs far S_rs_730_1 = {&var896,&var834,&var1510,&vainSBool,NULL};
_S_rs far S_rs_742_1 = {&var826,&var832,&var1511,&vainSBool,NULL};
_S_noto far S_noto_699_1 = {&var95,&var1512};
_S_noto far S_noto_655_1 = {&var94,&var1513};
_S_noto far S_noto_411_1 = {NULL,&var1514};
_S_orn far S_orn_425_1 = {array_m425_x_1,&iRM_7_,&var1515};
_S_orn far S_orn_407_1 = {array_m407_x_1,&iRM_7_,&var1516};
_S_rs far S_rs_719_1 = {&var833,&var838,&var1517,&vainSBool,NULL};
_S_noto far S_noto_149_1 = {NULL,&var1518};
_S_noto far S_noto_138_1 = {NULL,&var1519};
_S_noto far S_noto_139_1 = {NULL,&var1520};
_S_noto far S_noto_147_1 = {NULL,&var1521};
_S_samhd far S_samhd_1161_1 = {&var807,&var808,&var808,&var1118,&var1117,&var1118,&var1117,NULL,NULL,NULL,NULL,&bRM_1_,NULL,NULL,NULL,&var1522,&var1523,&vainSBool,&var1524,&var1525,&vainSBool,&var1526,&var1527,&var1528,&var1529,&var1530,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_samhd far S_samhd_1151_1 = {&var807,&var810,&var810,&var1118,&var1117,&var1118,&var1117,NULL,NULL,NULL,NULL,&bRM_1_,NULL,NULL,NULL,&var1531,&var1532,&vainSBool,&var1533,&var1534,&vainSBool,&var1535,&var1536,&var1537,&var1538,&var1539,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_samhd far S_samhd_774_1 = {NULL,&var665,&var665,&var927,&var821,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_0_,NULL,NULL,NULL,&var1540,&var1541,&var1542,&var1543,&var1544,&var1545,&vainSBool,&vainSBool,&var1546,&var1547,&var1548,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_samhd far S_samhd_770_1 = {NULL,&var667,&var667,&var927,&var821,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_0_,NULL,NULL,NULL,&var1549,&var1550,&var1551,&var1552,&var1553,&var1554,&vainSBool,&vainSBool,&var1555,&var1556,&var1557,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_samhd far S_samhd_354_1 = {NULL,&var323,&var322,&var830,&var823,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_0_,NULL,NULL,NULL,&var1558,&var1559,&var1560,&var1561,&var1562,&var1563,&vainSBool,&vainSBool,&var1564,&var1565,&vainSBool,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_noto far S_noto_666_1 = {NULL,&var1566};
_S_samhd far S_samhd_383_1 = {NULL,&var1515,&var897,&var903,&var822,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_0_,NULL,NULL,NULL,&var1567,&var1568,&var1569,&var1570,&var1571,&var1572,&vainSBool,&vainSBool,&var1573,&var1574,&var1575,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_samhd far S_samhd_377_1 = {NULL,&var1516,&var898,&var903,&var822,NULL,NULL,NULL,NULL,NULL,NULL,&bRM_0_,NULL,NULL,NULL,&var1576,&var1577,&var1578,&var1579,&var1580,&var1581,&vainSBool,&vainSBool,&var1582,&var1583,&var1584,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
_S_orn far S_orn_753_1 = {array_m753_x_1,&iRM_17_,&var1585};
_S_rs far S_rs_726_1 = {&var836,NULL,&var1586,&vainSBool,NULL};
_S_rs far S_rs_723_1 = {&var837,NULL,&var1587,&vainSBool,NULL};
_S_orni far S_orni_127_1 = {array_m127_x_1,&iRM_21_,&var1588,&vainSLong};
_S_equz_p far S_equz_p_74_1 = {NULL,&iRM_6_,&var1589};
_S_equz_p far S_equz_p_72_1 = {NULL,&iRM_5_,&var1590};
_S_equz_p far S_equz_p_70_1 = {NULL,&iRM_4_,&var1591};
_S_equz_p far S_equz_p_69_1 = {NULL,&iRM_3_,&var1592};
_S_equz_p far S_equz_p_68_1 = {NULL,&iRM_2_,&var1593};
_S_equz_p far S_equz_p_65_1 = {NULL,&iRM_1_,&var1594};
_S_equz_p far S_equz_p_61_1 = {NULL,&iRM_3_,&var1595};
_S_equz_p far S_equz_p_55_1 = {NULL,&iRM_1_,&vainSBool};
_S_equz_p far S_equz_p_57_1 = {NULL,&iRM_2_,&var1596};
_S_equz_p far S_equz_p_50_1 = {NULL,&iRM_3_,&var1597};
_S_equz_p far S_equz_p_43_1 = {NULL,&iRM_1_,&var1598};
_S_equz_p far S_equz_p_46_1 = {NULL,&iRM_2_,&var1599};
_S_equz_p far S_equz_p_99_1 = {NULL,&iRM_11_,&var1600};
_S_equz_p far S_equz_p_92_1 = {NULL,&iRM_4_,&var1601};
_S_equz_p far S_equz_p_91_1 = {NULL,&iRM_3_,&var1602};
_S_equz_p far S_equz_p_90_1 = {NULL,&iRM_2_,&var1603};
_S_equz_p far S_equz_p_10_1 = {NULL,&iRM_4_,&var1604};
_S_equz_p far S_equz_p_7_1 = {NULL,&iRM_3_,&var1605};
_S_equz_p far S_equz_p_2_1 = {NULL,&iRM_1_,&var1606};
_S_equz_p far S_equz_p_4_1 = {NULL,&iRM_2_,&var1607};


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
  signal_R0EE02LDU.b = var774.b;
  signal_R0EE02LDU.error = var774.error;
  fplet(&signal_B8VC01RDU.f,&var1685.f);
  signal_B8VC01RDU.error = var1685.error;
  fplet(&signal_B2VC01RDU.f,&var1697.f);
  signal_B2VC01RDU.error = var1697.error;
  fplet(&signal_A2VC01RDU.f,&var1700.f);
  signal_A2VC01RDU.error = var1700.error;
  fplet(&signal_A3VC01RDU.f,&var1694.f);
  signal_A3VC01RDU.error = var1694.error;
  signal_B0VS11LDU.b = var1662.b;
  signal_B0VS11LDU.error = var1662.error;
  signal_A0VS11LDU.b = var1663.b;
  signal_A0VS11LDU.error = var1663.error;
  signal_B0VN01LDU.b = var1632.b;
  signal_B0VN01LDU.error = var1632.error;
  signal_A0VN01LDU.b = var1634.b;
  signal_A0VN01LDU.error = var1634.error;
  signal_B0VP01LDU.b = var1668.b;
  signal_B0VP01LDU.error = var1668.error;
  signal_A0VP01LDU.b = var1669.b;
  signal_A0VP01LDU.error = var1669.error;
  signal_B0VE01LDU.b = var1659.b;
  signal_B0VE01LDU.error = var1659.error;
  signal_A0VE01LDU.b = var1661.b;
  signal_A0VE01LDU.error = var1661.error;
  signal_A3VP82LDU.b = var1630.b;
  signal_A3VP82LDU.error = var1630.error;
  signal_B3VP82LDU.b = var1653.b;
  signal_B3VP82LDU.error = var1653.error;
  signal_B3VP52LDU.b = var1678.b;
  signal_B3VP52LDU.error = var1678.error;
  fplet(&signal_B3CP02RDU.f,&var1654.f);
  signal_B3CP02RDU.error = var1654.error;
  signal_B3VP42LDU.b = var1628.b;
  signal_B3VP42LDU.error = var1628.error;
  signal_A3VP52LDU.b = var1681.b;
  signal_A3VP52LDU.error = var1681.error;
  fplet(&signal_A3CP02RDU.f,&var1655.f);
  signal_A3CP02RDU.error = var1655.error;
  signal_A3VP42LDU.b = var1629.b;
  signal_A3VP42LDU.error = var1629.error;
  fplet(&signal_A1VC01RDU.f,&var1682.f);
  signal_A1VC01RDU.error = var1682.error;
  fplet(&signal_A8VC01RDU.f,&var1688.f);
  signal_A8VC01RDU.error = var1688.error;
  fplet(&signal_B3VC01RDU.f,&var1691.f);
  signal_B3VC01RDU.error = var1691.error;
  fplet(&signal_B1VC01RDU.f,&var1704.f);
  signal_B1VC01RDU.error = var1704.error;
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
  noto((&S_noto_139_1));
  noto((&S_noto_138_1));
  noto((&S_noto_149_1));
  noto((&S_noto_739_1));
  noto((&S_noto_708_1));
  noto((&S_noto_1085_1));
  noto((&S_noto_1549_1));
  noto((&S_noto_1245_1));
  noto((&S_noto_843_1));
  noto((&S_noto_213_1));
  noto((&S_noto_530_1));
  noto((&S_noto_938_1));
  rs((&S_rs_613_1));
  noto((&S_noto_1335_1));
  equz_p((&S_equz_p_32_1));
  equz_p((&S_equz_p_41_1));
  noto((&S_noto_34_1));
  equz_p((&S_equz_p_37_1));
  rs((&S_rs_1459_1));
  noto((&S_noto_1740_1));
  noto((&S_noto_1739_1));
  noto((&S_noto_1745_1));
  noto((&S_noto_1741_1));
  noto((&S_noto_1747_1));
  noto((&S_noto_1718_1));
  noto((&S_noto_1719_1));
  noto((&S_noto_1720_1));
  noto((&S_noto_1721_1));
  noto((&S_noto_1722_1));
  noto((&S_noto_2034_1));
  equz_p((&S_equz_p_93_1));
  equz_p((&S_equz_p_94_1));
  equz_p((&S_equz_p_95_1));
  noto((&S_noto_915_1));
  equz_p((&S_equz_p_96_1));
  equz_p((&S_equz_p_97_1));
  noto((&S_noto_173_1));
  equz_p((&S_equz_p_98_1));
  noto((&S_noto_12_1));
  noto((&S_noto_1818_1));
  equz_p((&S_equz_p_1762_1));
  equz_p((&S_equz_p_1761_1));
  equz_p((&S_equz_p_1763_1));
  equz_p((&S_equz_p_1764_1));
  equz_p((&S_equz_p_1765_1));
  noto((&S_noto_1727_1));
  noto((&S_noto_1781_1));
  noto((&S_noto_1799_1));
  rs((&S_rs_603_1));
  noto((&S_noto_1759_1));
  noto((&S_noto_1785_1));
  noto((&S_noto_1312_1));
  rsun((&S_rsun_1385_1));
  rs((&S_rs_605_1));
  rs((&S_rs_607_1));
  rs((&S_rs_623_1));
  rs((&S_rs_639_1));
  rs((&S_rs_612_1));
  rs((&S_rs_627_1));
  rs((&S_rs_26_1));
  rs((&S_rs_1454_1));
  rs((&S_rs_1409_1));
  rs((&S_rs_1851_1));
  noto((&S_noto_1404_1));
  noto((&S_noto_1444_1));
  noto((&S_noto_1449_1));
  noto((&S_noto_1809_1));
  noto((&S_noto_1846_1));
  noto((&S_noto_1866_1));
  noto((&S_noto_1831_1));
  noto((&S_noto_574_1));
  noto((&S_noto_22_1));
  noto((&S_noto_23_1));
  noto((&S_noto_24_1));
  noto((&S_noto_25_1));
  noto((&S_noto_577_1));
  noto((&S_noto_575_1));
  noto((&S_noto_49_1));
  noto((&S_noto_253_1));
  noto((&S_noto_256_1));
  noto((&S_noto_265_1));
  noto((&S_noto_271_1));
  noto((&S_noto_261_1));
  noto((&S_noto_972_1));
  noto((&S_noto_978_1));
  noto((&S_noto_1900_1));
  noto((&S_noto_1902_1));
  rs((&S_rs_1055_1));
  rs((&S_rs_1058_1));
  rs((&S_rs_1061_1));
  rs((&S_rs_1064_1));
  ovbs((&S_ovbs_1159_1));
  ovbs((&S_ovbs_2056_1));
  sr((&S_sr_1049_1));
  bol((&S_bol_1042_1));
  ma((&S_ma_83_1));
  sr((&S_sr_81_1));
  bol((&S_bol_250_1));
  bol((&S_bol_248_1));
  bol((&S_bol_1364_1));
  bol((&S_bol_1362_1));
  bol((&S_bol_967_1));
  bol((&S_bol_965_1));
  bol((&S_bol_562_1));
  bol((&S_bol_564_1));
  bol((&S_bol_573_1));
  bol((&S_bol_579_1));
  and2((&S_and2_727_1));
  and2((&S_and2_27_1));
  and2((&S_and2_28_1));
  and2((&S_and2_29_1));
  and2((&S_and2_30_1));
  and2((&S_and2_42_1));
  and2((&S_and2_38_1));
  and2((&S_and2_718_1));
  or4((&S_or4_410_1));
  or2((&S_or2_731_1));
  or3((&S_or3_5_1));
  or2((&S_or2_6_1));
  or2((&S_or2_1258_1));
  or2((&S_or2_856_1));
  or2((&S_or2_227_1));
  or2((&S_or2_544_1));
  or2((&S_or2_950_1));
  or2((&S_or2_1347_1));
  or2((&S_or2_1048_1));
  and2((&S_and2_1041_1));
  or2((&S_or2_20_1));
  or2((&S_or2_39_1));
  or2((&S_or2_35_1));
  or2((&S_or2_48_1));
  or2((&S_or2_125_1));
  or2((&S_or2_680_1));
  or3((&S_or3_668_1));
  or4((&S_or4_682_1));
  or2((&S_or2_695_1));
  or3((&S_or3_715_1));
  or3((&S_or3_725_1));
  and2((&S_and2_738_1));
  and2((&S_and2_714_1));
  or2((&S_or2_722_1));
  or2((&S_or2_650_1));
  or2((&S_or2_652_1));
  or2((&S_or2_654_1));
  or2((&S_or2_1135_1));
  or2((&S_or2_1160_1));
  and4((&S_and4_1053_1));
  or2((&S_or2_1052_1));
  and2((&S_and2_1067_1));
  or2((&S_or2_1081_1));
  and3((&S_and3_254_1));
  and3((&S_and3_270_1));
  or2((&S_or2_596_1));
  or2((&S_or2_604_1));
  or2((&S_or2_606_1));
  or2((&S_or2_609_1));
  or2((&S_or2_580_1));
  and2((&S_and2_630_1));
  or2((&S_or2_637_1));
  and2((&S_and2_601_1));
  or2((&S_or2_616_1));
  or2((&S_or2_611_1));
  or2((&S_or2_634_1));
  and2((&S_and2_591_1));
  or2((&S_or2_336_1));
  or2((&S_or2_341_1));
  or2((&S_or2_736_1));
  or2((&S_or2_452_1));
  or2((&S_or2_510_1));
  and2((&S_and2_519_1));
  and2((&S_and2_520_1));
  and2((&S_and2_529_1));
  or2((&S_or2_522_1));
  and2((&S_and2_531_1));
  or2((&S_or2_191_1));
  and2((&S_and2_171_1));
  and2((&S_and2_203_1));
  and2((&S_and2_202_1));
  or2((&S_or2_205_1));
  and2((&S_and2_214_1));
  and2((&S_and2_212_1));
  or2((&S_or2_773_1));
  or2((&S_or2_819_1));
  or2((&S_or2_834_1));
  and2((&S_and2_909_1));
  or2((&S_or2_920_1));
  or2((&S_or2_912_1));
  or2((&S_or2_928_1));
  or2((&S_or2_1325_1));
  or2((&S_or2_1309_1));
  and2((&S_and2_1306_1));
  or2((&S_or2_1317_1));
  or2((&S_or2_1235_1));
  or2((&S_or2_1217_1));
  and2((&S_and2_977_1));
  and2((&S_and2_1405_1));
  zpfs((&S_zpfs_1415_1));
  and2((&S_and2_1445_1));
  zpfs((&S_zpfs_1465_1));
  and2((&S_and2_1450_1));
  zpfs((&S_zpfs_1471_1));
  and2((&S_and2_1487_1));
  or2((&S_or2_2057_1));
  or2((&S_or2_1594_1));
  or2((&S_or2_1595_1));
  or2((&S_or2_1545_1));
  or2((&S_or2_1725_1));
  or2((&S_or2_1726_1));
  or4((&S_or4_1732_1));
  or4((&S_or4_1733_1));
  or2((&S_or2_1735_1));
  or2((&S_or2_1729_1));
  or2((&S_or2_1728_1));
  or3((&S_or3_1737_1));
  and2((&S_and2_1766_1));
  or2((&S_or2_1767_1));
  and2((&S_and2_1773_1));
  and2((&S_and2_1789_1));
  or2((&S_or2_1792_1));
  and2((&S_and2_1794_1));
  or2((&S_or2_1800_1));
  zpfs((&S_zpfs_1769_1));
  zpfs((&S_zpfs_1770_1));
  zpfs((&S_zpfs_1771_1));
  zpfs((&S_zpfs_1772_1));
  or2((&S_or2_1775_1));
  and2((&S_and2_1776_1));
  or2((&S_or2_1791_1));
  or3((&S_or3_1777_1));
  or2((&S_or2_1852_1));
  ma((&S_ma_1440_1));
  zpfs((&S_zpfs_1822_1));
  and2((&S_and2_1823_1));
  or2((&S_or2_1817_1));
  and3((&S_and3_1820_1));
  or2((&S_or2_1828_1));
  or2((&S_or2_229_1));
  ovbs((&S_ovbs_76_1));
  ovbs((&S_ovbs_2028_1));
  ovbs((&S_ovbs_2024_1));
  ovbs((&S_ovbs_21_1));
  ovbs((&S_ovbs_117_1));
  ovbs((&S_ovbs_110_1));
  ovbs((&S_ovbs_1399_1));
  ovbs((&S_ovbs_734_1));
  ovbs((&S_ovbs_288_1));
  ovbs((&S_ovbs_332_1));
  ovbs((&S_ovbs_51_1));
  or2((&S_or2_1455_1));
  or2((&S_or2_1964_1));
  or2((&S_or2_1952_1));
  noto((&S_noto_1982_1));
  bol((&S_bol_1532_1));
  bol((&S_bol_1525_1));
  or2((&S_or2_1527_1));
  bol((&S_bol_1515_1));
  bol((&S_bol_1504_1));
  or2((&S_or2_1510_1));
  bol((&S_bol_1533_1));
  bol((&S_bol_1523_1));
  or2((&S_or2_1530_1));
  bol((&S_bol_1517_1));
  bol((&S_bol_1506_1));
  or2((&S_or2_1512_1));
  and4((&S_and4_45_1));
  abs_subf((&S_abs_subf_1522_1));
  noto((&S_noto_1528_1));
  and2((&S_and2_228_1));
  and2((&S_and2_545_1));
  and2((&S_and2_2200_1));
  rs((&S_rs_2149_1));
  sr((&S_sr_2187_1));
  sr((&S_sr_2165_1));
  rs((&S_rs_2143_1));
  zpfs((&S_zpfs_2171_1));
  or2((&S_or2_2158_1));
  abs_subf((&S_abs_subf_2124_1));
  and2((&S_and2_2132_1));
  noto((&S_noto_883_1));
  zzfs((&S_zzfs_2133_1));
  noto((&S_noto_2144_1));
  or2((&S_or2_1065_1));
  or2((&S_or2_361_1));
  or2((&S_or2_344_1));
  or2((&S_or2_1097_1));
  or2((&S_or2_1102_1));
  or2((&S_or2_225_1));
  or2((&S_or2_542_1));
  and2((&S_and2_2046_1));
  nocnm((&S_nocnm_1680_1));
  nocnm((&S_nocnm_1683_1));
  noto((&S_noto_1632_1));
  noto((&S_noto_1638_1));
  noto((&S_noto_2118_1));
  noto((&S_noto_2092_1));
  or2((&S_or2_1412_1));
  or2((&S_or2_1443_1));
  noto((&S_noto_2121_1));
  noto((&S_noto_2095_1));
  rs((&S_rs_726_1));
  noto((&S_noto_666_1));
  noto((&S_noto_147_1));
  rs((&S_rs_719_1));
  noto((&S_noto_411_1));
  noto((&S_noto_655_1));
  noto((&S_noto_699_1));
  rs((&S_rs_730_1));
  noto((&S_noto_741_1));
  noto((&S_noto_748_1));
  vmemb((&S_vmemb_663_1));
  vmemb((&S_vmemb_700_1));
  noto((&S_noto_737_1));
  vmemb((&S_vmemb_729_1));
  rs((&S_rs_618_1));
  rs((&S_rs_628_1));
  rs((&S_rs_608_1));
  noto((&S_noto_595_1));
  rs((&S_rs_636_1));
  noto((&S_noto_252_1));
  noto((&S_noto_631_1));
  noto((&S_noto_566_1));
  noto((&S_noto_969_1));
  noto((&S_noto_1366_1));
  noto((&S_noto_991_1));
  noto((&S_noto_1876_1));
  kvf((&S_kvf_1463_1));
  noto((&S_noto_77_1));
  samhd((&S_samhd_2055_1));
  samhd((&S_samhd_2061_1));
  newstage((&S_newstage_2059_1));
  noto((&S_noto_1738_1));
  noto((&S_noto_1744_1));
  noto((&S_noto_1746_1));
  noto((&S_noto_1717_1));
  noto((&S_noto_2025_1));
  noto((&S_noto_2029_1));
  noto((&S_noto_1863_1));
  noto((&S_noto_1855_1));
  noto((&S_noto_1813_1));
  noto((&S_noto_497_1));
  noto((&S_noto_1196_1));
  noto((&S_noto_1212_1));
  noto((&S_noto_1787_1));
  rs((&S_rs_1474_1));
  kvf((&S_kvf_1469_1));
  rs((&S_rs_1468_1));
  noto((&S_noto_1479_1));
  noto((&S_noto_1477_1));
  rs((&S_rs_735_1));
  noto((&S_noto_338_1));
  noto((&S_noto_334_1));
  noto((&S_noto_576_1));
  noto((&S_noto_586_1));
  noto((&S_noto_638_1));
  noto((&S_noto_1884_1));
  noto((&S_noto_1909_1));
  swtakt((&S_swtakt_52_1));
  rs((&S_rs_1057_1));
  and2((&S_and2_745_1));
  and2((&S_and2_11_1));
  and2((&S_and2_109_1));
  and2((&S_and2_224_1));
  and2((&S_and2_541_1));
  or2((&S_or2_14_1));
  or2((&S_or2_8_1));
  or2((&S_or2_161_1));
  or2((&S_or2_656_1));
  and2((&S_and2_665_1));
  and2((&S_and2_667_1));
  and2((&S_and2_679_1));
  and2((&S_and2_681_1));
  and2((&S_and2_694_1));
  and2((&S_and2_697_1));
  and3((&S_and3_696_1));
  and2((&S_and2_698_1));
  and3((&S_and3_693_1));
  and2((&S_and2_664_1));
  or2((&S_or2_732_1));
  and2((&S_and2_720_1));
  and2((&S_and2_740_1));
  or2((&S_or2_746_1));
  or2((&S_or2_750_1));
  and3((&S_and3_747_1));
  and2((&S_and2_752_1));
  and2((&S_and2_756_1));
  and2((&S_and2_642_1));
  and2((&S_and2_646_1));
  or2((&S_or2_643_1));
  and2((&S_and2_651_1));
  and2((&S_and2_653_1));
  or2((&S_or2_260_1));
  and3((&S_and3_276_1));
  or2((&S_or2_629_1));
  and2((&S_and2_598_1));
  and2((&S_and2_588_1));
  and4((&S_and4_589_1));
  and4((&S_and4_599_1));
  and2((&S_and2_624_1));
  or2((&S_or2_632_1));
  or2((&S_or2_635_1));
  and3((&S_and3_329_1));
  and2((&S_and2_493_1));
  or2((&S_or2_499_1));
  and2((&S_and2_551_1));
  and2((&S_and2_563_1));
  or2((&S_or2_177_1));
  and2((&S_and2_237_1));
  and2((&S_and2_249_1));
  and2((&S_and2_966_1));
  and2((&S_and2_1348_1));
  and2((&S_and2_1363_1));
  and2((&S_and2_1194_1));
  or2((&S_or2_1200_1));
  and2((&S_and2_1206_1));
  or2((&S_or2_1218_1));
  and2((&S_and2_986_1));
  and2((&S_and2_996_1));
  and2((&S_and2_1375_1));
  and2((&S_and2_1381_1));
  and2((&S_and2_1387_1));
  and2((&S_and2_1389_1));
  and2((&S_and2_1391_1));
  and2((&S_and2_1397_1));
  and2((&S_and2_1401_1));
  or2((&S_or2_1453_1));
  and2((&S_and2_1416_1));
  and2((&S_and2_1466_1));
  or3((&S_or3_1480_1));
  or2((&S_or2_1462_1));
  and2((&S_and2_1472_1));
  or3((&S_or3_1473_1));
  or3((&S_or3_1486_1));
  or3((&S_or3_2054_1));
  or3((&S_or3_2063_1));
  or2((&S_or2_1734_1));
  or3((&S_or3_1736_1));
  or2((&S_or2_1774_1));
  or2((&S_or2_1790_1));
  and2((&S_and2_1782_1));
  or3((&S_or3_1779_1));
  and2((&S_and2_1804_1));
  and2((&S_and2_2043_1));
  or2((&S_or2_2006_1));
  or2((&S_or2_1936_1));
  or2((&S_or2_1925_1));
  and2((&S_and2_1905_1));
  and2((&S_and2_1903_1));
  and2((&S_and2_1888_1));
  and2((&S_and2_1887_1));
  and2((&S_and2_1857_1));
  and4((&S_and4_1858_1));
  and4((&S_and4_1864_1));
  or2((&S_or2_1867_1));
  or2((&S_or2_1869_1));
  or2((&S_or2_1868_1));
  zpfs((&S_zpfs_1871_1));
  zpfs((&S_zpfs_1874_1));
  zpfs((&S_zpfs_1859_1));
  and2((&S_and2_1860_1));
  or3((&S_or3_1877_1));
  lk((&S_lk_1464_1));
  rsfn((&S_rsfn_1460_1));
  abs_subf((&S_abs_subf_1475_1));
  lk((&S_lk_1461_1));
  rsfn((&S_rsfn_1457_1));
  abs_subf((&S_abs_subf_1470_1));
  and3((&S_and3_1819_1));
  or2((&S_or2_1826_1));
  or2((&S_or2_1827_1));
  zpfs((&S_zpfs_1833_1));
  zpfs((&S_zpfs_1835_1));
  or3((&S_or3_1838_1));
  or2((&S_or2_1840_1));
  and2((&S_and2_951_1));
  or2((&S_or2_244_1));
  ovbs((&S_ovbs_1841_1));
  ovbs((&S_ovbs_13_1));
  noto((&S_noto_102_1));
  and2((&S_and2_101_1));
  bol((&S_bol_1513_1));
  bol((&S_bol_1503_1));
  or2((&S_or2_1508_1));
  ml((&S_ml_1519_1));
  ml((&S_ml_1499_1));
  ml((&S_ml_1521_1));
  ml((&S_ml_1500_1));
  zpfs((&S_zpfs_733_1));
  and2((&S_and2_115_1));
  noto((&S_noto_113_1));
  and2((&S_and2_119_1));
  and2((&S_and2_118_1));
  noto((&S_noto_185_1));
  noto((&S_noto_457_1));
  noto((&S_noto_902_1));
  noto((&S_noto_1155_1));
  noto((&S_noto_1207_1));
  bol((&S_bol_1752_1));
  and3((&S_and3_1743_1));
  bol((&S_bol_1716_1));
  and3((&S_and3_1724_1));
  noto((&S_noto_1731_1));
  noto((&S_noto_1742_1));
  bol((&S_bol_893_1));
  bol((&S_bol_1292_1));
  abs_subf((&S_abs_subf_1505_1));
  noto((&S_noto_1511_1));
  abs_subf((&S_abs_subf_1524_1));
  noto((&S_noto_1531_1));
  bol((&S_bol_2188_1));
  and2((&S_and2_2199_1));
  noto((&S_noto_2157_1));
  fsumo((&S_fsumo_79_1));
  abs_subf((&S_abs_subf_2196_1));
  and2((&S_and2_2201_1));
  and3((&S_and3_2150_1));
  and2((&S_and2_2172_1));
  ovbs((&S_ovbs_2173_1));
  or3((&S_or3_2181_1));
  inf((&S_inf_2153_1));
  noto((&S_noto_1293_1));
  or2((&S_or2_1056_1));
  or5((&S_or5_2044_1));
  and2((&S_and2_2106_1));
  and2((&S_and2_2080_1));
  and2((&S_and2_2007_1));
  samhd((&S_samhd_377_1));
  samhd((&S_samhd_383_1));
  samhd((&S_samhd_770_1));
  samhd((&S_samhd_774_1));
  rs((&S_rs_742_1));
  rs((&S_rs_749_1));
  newstage((&S_newstage_380_1));
  newstage((&S_newstage_772_1));
  noto((&S_noto_1236_1));
  noto((&S_noto_832_1));
  noto((&S_noto_206_1));
  rs((&S_rs_610_1));
  noto((&S_noto_523_1));
  noto((&S_noto_929_1));
  noto((&S_noto_1326_1));
  kvf((&S_kvf_1834_1));
  kvf((&S_kvf_1873_1));
  andn((&S_andn_1730_1));
  rs((&S_rs_19_1));
  noto((&S_noto_135_1));
  newstage((&S_newstage_1783_1));
  noto((&S_noto_1788_1));
  noto((&S_noto_108_1));
  noto((&S_noto_1369_1));
  abs_subf((&S_abs_subf_997_1));
  abs_subf((&S_abs_subf_984_1));
  noto((&S_noto_1004_1));
  bol((&S_bol_1017_1));
  bol((&S_bol_1018_1));
  noto((&S_noto_981_1));
  bol((&S_bol_1020_1));
  bol((&S_bol_1021_1));
  bol((&S_bol_80_1));
  and2((&S_and2_401_1));
  and2((&S_and2_412_1));
  and2((&S_and2_420_1));
  and2((&S_and2_421_1));
  and2((&S_and2_422_1));
  and2((&S_and2_140_1));
  and2((&S_and2_148_1));
  and2((&S_and2_145_1));
  and2((&S_and2_137_1));
  or3((&S_or3_373_1));
  or3((&S_or3_388_1));
  and2((&S_and2_402_1));
  and3((&S_and3_226_1));
  and3((&S_and3_543_1));
  and3((&S_and3_975_1));
  or3((&S_or3_105_1));
  and2((&S_and2_728_1));
  or2((&S_or2_755_1));
  and2((&S_and2_649_1));
  and2((&S_and2_622_1));
  and2((&S_and2_600_1));
  and2((&S_and2_590_1));
  and3((&S_and3_521_1));
  or2((&S_or2_558_1));
  and3((&S_and3_204_1));
  and3((&S_and3_239_1));
  or4((&S_or4_766_1));
  or4((&S_or4_782_1));
  and3((&S_and3_840_1));
  and3((&S_and3_841_1));
  or2((&S_or2_961_1));
  or2((&S_or2_1358_1));
  and3((&S_and3_1242_1));
  and3((&S_and3_1243_1));
  or2((&S_or2_1022_1));
  or2((&S_or2_1033_1));
  or2((&S_or2_1032_1));
  or2((&S_or2_1031_1));
  or2((&S_or2_1030_1));
  or3((&S_or3_1425_1));
  and2((&S_and2_1426_1));
  and3((&S_and3_1483_1));
  or3((&S_or3_1467_1));
  and2((&S_and2_1481_1));
  and3((&S_and3_1484_1));
  zpfs((&S_zpfs_2008_1));
  and3((&S_and3_1897_1));
  and2((&S_and2_1892_1));
  or3((&S_or3_1898_1));
  and2((&S_and2_1870_1));
  and4((&S_and4_1878_1));
  and4((&S_and4_1880_1));
  lk((&S_lk_1875_1));
  rsfn((&S_rsfn_1881_1));
  abs_subf((&S_abs_subf_1883_1));
  and3((&S_and3_1886_1));
  lk((&S_lk_1839_1));
  rsfn((&S_rsfn_1842_1));
  abs_subf((&S_abs_subf_1844_1));
  and2((&S_and2_1832_1));
  and3((&S_and3_1836_1));
  or5((&S_or5_144_1));
  and2((&S_and2_1805_1));
  and2((&S_and2_428_1));
  and2((&S_and2_104_1));
  ml((&S_ml_1497_1));
  and2((&S_and2_1707_1));
  and2((&S_and2_1688_1));
  and2((&S_and2_1705_1));
  and2((&S_and2_1708_1));
  and2((&S_and2_1689_1));
  and2((&S_and2_1706_1));
  and2((&S_and2_1690_1));
  and2((&S_and2_1691_1));
  and2((&S_and2_1692_1));
  and2((&S_and2_1693_1));
  and2((&S_and2_1694_1));
  and2((&S_and2_1695_1));
  and2((&S_and2_1666_1));
  and2((&S_and2_1667_1));
  and2((&S_and2_1668_1));
  and2((&S_and2_1669_1));
  and2((&S_and2_1646_1));
  and2((&S_and2_1648_1));
  and2((&S_and2_1650_1));
  and2((&S_and2_1652_1));
  and2((&S_and2_1620_1));
  and2((&S_and2_1622_1));
  and2((&S_and2_1624_1));
  and2((&S_and2_1626_1));
  and2((&S_and2_1596_1));
  and2((&S_and2_1597_1));
  and2((&S_and2_1598_1));
  and2((&S_and2_1599_1));
  and2((&S_and2_1600_1));
  and2((&S_and2_1601_1));
  and2((&S_and2_1602_1));
  and2((&S_and2_1603_1));
  and2((&S_and2_114_1));
  abs_subf((&S_abs_subf_1501_1));
  noto((&S_noto_1509_1));
  irm((&S_irm_2131_1));
  ovbs((&S_ovbs_2151_1));
  and2((&S_and2_2197_1));
  ml((&S_ml_874_1));
  ml((&S_ml_1274_1));
  noto((&S_noto_2180_1));
  noto((&S_noto_2128_1));
  noto((&S_noto_2129_1));
  and3((&S_and3_403_1));
  or2((&S_or2_2109_1));
  and2((&S_and2_2101_1));
  or4((&S_or4_877_1));
  or2((&S_or2_2087_1));
  or2((&S_or2_2083_1));
  and2((&S_and2_2075_1));
  or4((&S_or4_1279_1));
  and4((&S_and4_936_1));
  and4((&S_and4_1333_1));
  and3((&S_and3_2105_1));
  and3((&S_and3_2079_1));
  rs((&S_rs_721_1));
  rs((&S_rs_754_1));
  orn((&S_orn_141_1));
  rs((&S_rs_1606_1));
  rs((&S_rs_1609_1));
  rs((&S_rs_1612_1));
  rs((&S_rs_1615_1));
  rs((&S_rs_1631_1));
  rs((&S_rs_1637_1));
  rs((&S_rs_1658_1));
  rs((&S_rs_1664_1));
  rs((&S_rs_2115_1));
  rs((&S_rs_1699_1));
  rs((&S_rs_1702_1));
  rs((&S_rs_1642_1));
  rs((&S_rs_1644_1));
  rs((&S_rs_1616_1));
  rs((&S_rs_1617_1));
  rs((&S_rs_1618_1));
  rs((&S_rs_1619_1));
  rs((&S_rs_106_1));
  noto((&S_noto_107_1));
  rs((&S_rs_1489_1));
  rs((&S_rs_1488_1));
  rs((&S_rs_1418_1));
  kvf((&S_kvf_1422_1));
  rs((&S_rs_1891_1));
  rs((&S_rs_1837_1));
  noto((&S_noto_1421_1));
  andn((&S_andn_259_1));
  noto((&S_noto_277_1));
  and3((&S_and3_578_1));
  or2((&S_or2_143_1));
  and2((&S_and2_670_1));
  or2((&S_or2_267_1));
  and3((&S_and3_268_1));
  or2((&S_or2_430_1));
  and3((&S_and3_437_1));
  or2((&S_or2_483_1));
  and2((&S_and2_503_1));
  and3((&S_and3_553_1));
  and3((&S_and3_552_1));
  and2((&S_and2_179_1));
  and3((&S_and3_238_1));
  or3((&S_or3_833_1));
  and2((&S_and2_830_1));
  and3((&S_and3_831_1));
  and2((&S_and2_829_1));
  and2((&S_and2_844_1));
  and2((&S_and2_842_1));
  and2((&S_and2_859_1));
  and3((&S_and3_860_1));
  and2((&S_and2_924_1));
  or2((&S_or2_930_1));
  and2((&S_and2_937_1));
  and2((&S_and2_954_1));
  and3((&S_and3_955_1));
  and3((&S_and3_956_1));
  or2((&S_or2_1327_1));
  and2((&S_and2_1334_1));
  and2((&S_and2_1336_1));
  and2((&S_and2_1351_1));
  and3((&S_and3_1352_1));
  and3((&S_and3_1353_1));
  and2((&S_and2_1319_1));
  or3((&S_or3_1234_1));
  and3((&S_and3_1233_1));
  and2((&S_and2_1232_1));
  and2((&S_and2_1246_1));
  and2((&S_and2_1231_1));
  and2((&S_and2_1244_1));
  and2((&S_and2_1256_1));
  and3((&S_and3_1257_1));
  and2((&S_and2_1261_1));
  and3((&S_and3_1262_1));
  and2((&S_and2_1202_1));
  and2((&S_and2_1224_1));
  and2((&S_and2_1034_1));
  and2((&S_and2_1038_1));
  or2((&S_or2_1413_1));
  or3((&S_or3_1417_1));
  or2((&S_or2_1605_1));
  or2((&S_or2_1608_1));
  or2((&S_or2_1611_1));
  or2((&S_or2_1614_1));
  or2((&S_or2_1629_1));
  or2((&S_or2_1635_1));
  or2((&S_or2_1657_1));
  or2((&S_or2_1663_1));
  or2((&S_or2_2113_1));
  or2((&S_or2_2032_1));
  or2((&S_or2_2037_1));
  lk((&S_lk_1423_1));
  rsfn((&S_rsfn_1419_1));
  abs_subf((&S_abs_subf_1428_1));
  ovbs((&S_ovbs_112_1));
  and2((&S_and2_464_1));
  and2((&S_and2_435_1));
  and2((&S_and2_1621_1));
  and2((&S_and2_1623_1));
  and2((&S_and2_1625_1));
  and2((&S_and2_1627_1));
  zpfs((&S_zpfs_2136_1));
  zpfs((&S_zpfs_2137_1));
  and2((&S_and2_2020_1));
  and2((&S_and2_2031_1));
  and2((&S_and2_2019_1));
  and2((&S_and2_2042_1));
  rs((&S_rs_2108_1));
  rs((&S_rs_2099_1));
  rs((&S_rs_2089_1));
  rs((&S_rs_2082_1));
  rs((&S_rs_2073_1));
  rs((&S_rs_583_1));
  noto((&S_noto_597_1));
  orni((&S_orni_1386_1));
  rs((&S_rs_1604_1));
  rs((&S_rs_1607_1));
  rs((&S_rs_1610_1));
  rs((&S_rs_1613_1));
  rs((&S_rs_1630_1));
  rs((&S_rs_1628_1));
  rs((&S_rs_2033_1));
  rs((&S_rs_1633_1));
  rs((&S_rs_1636_1));
  rs((&S_rs_1634_1));
  rs((&S_rs_1639_1));
  ma((&S_ma_1424_1));
  rs((&S_rs_593_1));
  noto((&S_noto_971_1));
  noto((&S_noto_269_1));
  noto((&S_noto_1027_1));
  noto((&S_noto_1028_1));
  noto((&S_noto_1000_1));
  and2((&S_and2_405_1));
  and2((&S_and2_423_1));
  and2((&S_and2_854_1));
  and3((&S_and3_855_1));
  and3((&S_and3_949_1));
  and3((&S_and3_1346_1));
  and2((&S_and2_617_1));
  and2((&S_and2_925_1));
  and2((&S_and2_926_1));
  and2((&S_and2_939_1));
  and3((&S_and3_927_1));
  and2((&S_and2_1322_1));
  and2((&S_and2_1323_1));
  and3((&S_and3_1324_1));
  and5((&S_and5_976_1));
  and2((&S_and2_1023_1));
  or4((&S_or4_983_1));
  and3((&S_and3_1432_1));
  noto((&S_noto_2141_1));
  noto((&S_noto_2142_1));
  andn((&S_andn_581_1));
  andn((&S_andn_582_1));
  or5((&S_or5_2045_1));
  rs((&S_rs_982_1));
  rs((&S_rs_2038_1));
  rs((&S_rs_1435_1));
  noto((&S_noto_1001_1));
  provsbr((&S_provsbr_1383_1));
  rs((&S_rs_1382_1));
  and3((&S_and3_988_1));
  and3((&S_and3_994_1));
  and2((&S_and2_1010_1));
  and2((&S_and2_999_1));
  and3((&S_and3_1045_1));
  or2((&S_or2_1388_1));
  or2((&S_or2_1390_1));
  or2((&S_or2_1392_1));
  or2((&S_or2_1398_1));
  or2((&S_or2_1402_1));
  orni((&S_orni_1394_1));
  or2((&S_or2_2021_1));
  noto((&S_noto_2148_1));
  and2((&S_and2_2022_1));
  noto((&S_noto_2039_1));
  cntch((&S_cntch_1393_1));
  rs((&S_rs_1005_1));
  rs((&S_rs_1039_1));
  rs((&S_rs_1013_1));
  noto((&S_noto_1014_1));
  or3((&S_or3_151_1));
  or3((&S_or3_473_1));
  or2((&S_or2_1035_1));
  and2((&S_and2_1395_1));
  or2((&S_or2_1557_1));
  zpfs((&S_zpfs_2018_1));
  cnshd((&S_cnshd_1564_1));
  noto((&S_noto_852_1));
  ornc((&S_ornc_158_1));
  charint((&S_charint_152_1));
  noto((&S_noto_222_1));
  ornc((&S_ornc_481_1));
  charint((&S_charint_475_1));
  noto((&S_noto_539_1));
  noto((&S_noto_947_1));
  noto((&S_noto_1344_1));
  rs((&S_rs_1024_1));
  or2((&S_or2_1583_1));
  and2((&S_and2_1535_1));
  and2((&S_and2_1536_1));
  and2((&S_and2_1537_1));
  and2((&S_and2_1538_1));
  and2((&S_and2_1544_1));
  and2((&S_and2_1546_1));
  and2((&S_and2_1548_1));
  and2((&S_and2_1012_1));
  fnapb((&S_fnapb_1584_1));
  samhd((&S_samhd_1567_1));
  zpfs((&S_zpfs_1581_1));
  zpfs((&S_zpfs_1577_1));
  noto((&S_noto_1254_1));
  fsumz((&S_fsumz_153_1));
  fsumz((&S_fsumz_476_1));
  orni((&S_orni_1146_1));
  rs((&S_rs_1007_1));
  rs((&S_rs_1008_1));
  ma((&S_ma_159_1));
  ma((&S_ma_482_1));
  zpfs((&S_zpfs_1585_1));
  or2((&S_or2_1099_1));
  or3((&S_or3_1006_1));
  or3((&S_or3_1574_1));
  samhd((&S_samhd_1151_1));
  samhd((&S_samhd_1161_1));
  newstage((&S_newstage_1154_1));
  cnshd((&S_cnshd_1100_1));
  noto((&S_noto_1253_1));
  noto((&S_noto_851_1));
  fnapb((&S_fnapb_192_1));
  noto((&S_noto_221_1));
  fnapb((&S_fnapb_511_1));
  zpfs((&S_zpfs_506_1));
  zpfs((&S_zpfs_504_1));
  noto((&S_noto_538_1));
  noto((&S_noto_946_1));
  noto((&S_noto_1343_1));
  or2((&S_or2_1150_1));
  or2((&S_or2_1164_1));
  or2((&S_or2_1123_1));
  and2((&S_and2_1075_1));
  and2((&S_and2_1072_1));
  and2((&S_and2_1073_1));
  and2((&S_and2_1074_1));
  and2((&S_and2_1080_1));
  and2((&S_and2_1082_1));
  and2((&S_and2_1084_1));
  and2((&S_and2_619_1));
  zpfs((&S_zpfs_512_1));
  or2((&S_or2_533_1));
  zpfs((&S_zpfs_193_1));
  zpfs((&S_zpfs_187_1));
  zpfs((&S_zpfs_182_1));
  or2((&S_or2_216_1));
  or2((&S_or2_846_1));
  and2((&S_and2_845_1));
  or2((&S_or2_941_1));
  or2((&S_or2_1338_1));
  or2((&S_or2_1248_1));
  and2((&S_and2_1247_1));
  and2((&S_and2_1003_1));
  or2((&S_or2_1015_1));
  and2((&S_and2_1156_1));
  and2((&S_and2_1162_1));
  or4((&S_or4_1915_1));
  fnapb((&S_fnapb_1124_1));
  samhd((&S_samhd_1106_1));
  zpfs((&S_zpfs_1120_1));
  zpfs((&S_zpfs_1116_1));
  orn((&S_orn_1255_1));
  orn((&S_orn_853_1));
  rs((&S_rs_1643_1));
  rs((&S_rs_1645_1));
  rs((&S_rs_1002_1));
  zpfs((&S_zpfs_1125_1));
  and2((&S_and2_31_1));
  and2((&S_and2_532_1));
  and2((&S_and2_215_1));
  and2((&S_and2_940_1));
  and2((&S_and2_1337_1));
  and2((&S_and2_1016_1));
  or2((&S_or2_1009_1));
  or3((&S_or3_1113_1));
  or2((&S_or2_1655_1));
  or2((&S_or2_1661_1));
  or2((&S_or2_1932_1));
  or2((&S_or2_1921_1));
  ovbs((&S_ovbs_1916_1));
  ovbs((&S_ovbs_1928_1));
  ovbs((&S_ovbs_1919_1));
  noto((&S_noto_1920_1));
  and2((&S_and2_1926_1));
  and2((&S_and2_1937_1));
  and2((&S_and2_1647_1));
  and2((&S_and2_1649_1));
  and2((&S_and2_1651_1));
  and2((&S_and2_1653_1));
  or3((&S_or3_124_1));
  orn((&S_orn_223_1));
  orn((&S_orn_948_1));
  orn((&S_orn_1345_1));
  noto((&S_noto_1917_1));
  noto((&S_noto_1929_1));
  rs((&S_rs_1933_1));
  noto((&S_noto_1934_1));
  rs((&S_rs_1656_1));
  rs((&S_rs_1654_1));
  rs((&S_rs_1659_1));
  rs((&S_rs_1662_1));
  rs((&S_rs_1660_1));
  rs((&S_rs_1665_1));
  rs((&S_rs_1922_1));
  rs((&S_rs_1054_1));
  or2((&S_or2_1889_1));
  or3((&S_or3_1186_1));
  or3((&S_or3_801_1));
  noto((&S_noto_1923_1));
  noto((&S_noto_66_1));
  noto((&S_noto_1890_1));
  and2((&S_and2_58_1));
  and2((&S_and2_62_1));
  and4((&S_and4_323_1));
  or2((&S_or2_1376_1));
  or2((&S_or2_1906_1));
  noto((&S_noto_1371_1));
  rs((&S_rs_326_1));
  noto((&S_noto_321_1));
  noto((&S_noto_264_1));
  rs((&S_rs_1907_1));
  rs((&S_rs_1908_1));
  or4((&S_or4_275_1));
  or2((&S_or2_258_1));
  or2((&S_or2_281_1));
  or2((&S_or2_318_1));
  or4((&S_or4_327_1));
  and2((&S_and2_1370_1));
  or2((&S_or2_1968_1));
  or2((&S_or2_1989_1));
  rs((&S_rs_274_1));
  provsbr((&S_provsbr_263_1));
  equz_p((&S_equz_p_302_1));
  bolz((&S_bolz_303_1));
  provsbr((&S_provsbr_320_1));
  bolz((&S_bolz_325_1));
  noto((&S_noto_67_1));
  noto((&S_noto_56_1));
  and2((&S_and2_59_1));
  and2((&S_and2_63_1));
  or2((&S_or2_60_1));
  and2((&S_and2_555_1));
  and2((&S_and2_554_1));
  and2((&S_and2_278_1));
  and4((&S_and4_307_1));
  and2((&S_and2_290_1));
  or2((&S_or2_280_1));
  and2((&S_and2_285_1));
  or2((&S_or2_331_1));
  and2((&S_and2_322_1));
  orn((&S_orn_540_1));
  and2((&S_and2_240_1));
  and2((&S_and2_241_1));
  or3((&S_or3_251_1));
  and2((&S_and2_862_1));
  and2((&S_and2_861_1));
  or3((&S_or3_867_1));
  and2((&S_and2_958_1));
  and2((&S_and2_957_1));
  and2((&S_and2_1354_1));
  and2((&S_and2_1355_1));
  and2((&S_and2_1263_1));
  and2((&S_and2_1264_1));
  or3((&S_or3_1269_1));
  or2((&S_or2_1372_1));
  or3((&S_or3_1403_1));
  or3((&S_or3_1442_1));
  or3((&S_or3_1458_1));
  or3((&S_or3_1849_1));
  or3((&S_or3_1811_1));
  or4((&S_or4_1365_1));
  or4((&S_or4_968_1));
  maz((&S_maz_289_1));
  maz((&S_maz_298_1));
  orni((&S_orni_1158_1));
  orni((&S_orni_279_1));
  rs((&S_rs_330_1));
  decatron((&S_decatron_287_1));
  orni((&S_orni_324_1));
  noto((&S_noto_299_1));
  swtakt((&S_swtakt_1815_1));
  swtakt((&S_swtakt_1850_1));
  swtakt((&S_swtakt_1448_1));
  swtakt((&S_swtakt_1452_1));
  swtakt((&S_swtakt_1408_1));
  or3((&S_or3_565_1));
  or2((&S_or2_284_1));
  or2((&S_or2_293_1));
  or2((&S_or2_306_1));
  or2((&S_or2_305_1));
  and2((&S_and2_309_1));
  and2((&S_and2_304_1));
  and2((&S_and2_311_1));
  and2((&S_and2_310_1));
  and3((&S_and3_291_1));
  or5((&S_or5_495_1));
  or5((&S_or5_175_1));
  and2((&S_and2_1373_1));
  or3((&S_or3_1367_1));
  or3((&S_or3_970_1));
  zpfs((&S_zpfs_301_1));
  cnshd((&S_cnshd_163_1));
  cnshd((&S_cnshd_484_1));
  equz_p((&S_equz_p_292_1));
  noto((&S_noto_1379_1));
  cntch((&S_cntch_282_1));
  rs((&S_rs_283_1));
  cntch((&S_cntch_328_1));
  and2((&S_and2_297_1));
  or5((&S_or5_1396_1));
  or5((&S_or5_1374_1));
  and2((&S_and2_1377_1));
  or2((&S_or2_1378_1));
  and4((&S_and4_1893_1));
  and3((&S_and3_1894_1));
  and3((&S_and3_1895_1));
  and2((&S_and2_1856_1));
  and2((&S_and2_1810_1));
  or3((&S_or3_1824_1));
  newstage((&S_newstage_200_1));
  rs((&S_rs_1862_1));
  rs((&S_rs_1816_1));
  rs((&S_rs_1825_1));
  and2((&S_and2_316_1));
  or3((&S_or3_1861_1));
  and2((&S_and2_189_1));
  and2((&S_and2_186_1));
  rs((&S_rs_1698_1));
  rs((&S_rs_1701_1));
  noto((&S_noto_317_1));
  and2((&S_and2_1068_1));
  and2((&S_and2_626_1));
  or2((&S_or2_614_1));
  and2((&S_and2_1036_1));
  or2((&S_or2_1697_1));
  or2((&S_or2_1700_1));
  rs((&S_rs_615_1));
  rs((&S_rs_1696_1));
  rs((&S_rs_1025_1));
  noto((&S_noto_1026_1));
  rs((&S_rs_1060_1));
  and2((&S_and2_633_1));
  and3((&S_and3_602_1));
  and3((&S_and3_592_1));
  or3((&S_or3_799_1));
  or3((&S_or3_1183_1));
  and4((&S_and4_989_1));
  and4((&S_and4_995_1));
  or2((&S_or2_1059_1));
  or4((&S_or4_868_1));
  or4((&S_or4_1270_1));
  ornc((&S_ornc_878_1));
  charint((&S_charint_872_1));
  ornc((&S_ornc_1280_1));
  charint((&S_charint_1272_1));
  fsumz((&S_fsumz_873_1));
  fsumz((&S_fsumz_1273_1));
  ma((&S_ma_1281_1));
  ma((&S_ma_879_1));
  fnapb((&S_fnapb_913_1));
  zpfs((&S_zpfs_905_1));
  zpfs((&S_zpfs_904_1));
  fnapb((&S_fnapb_1310_1));
  zpfs((&S_zpfs_1303_1));
  zpfs((&S_zpfs_1301_1));
  zpfs((&S_zpfs_914_1));
  zpfs((&S_zpfs_1311_1));
  and2((&S_and2_1296_1));
  and2((&S_and2_896_1));
  or5((&S_or5_895_1));
  or5((&S_or5_1295_1));
  or2((&S_or2_2183_1));
  cnshd((&S_cnshd_880_1));
  cnshd((&S_cnshd_1282_1));
  noto((&S_noto_2182_1));
  newstage((&S_newstage_892_1));
  and2((&S_and2_899_1));
  and2((&S_and2_903_1));
  andn((&S_andn_2156_1));
  noto((&S_noto_2178_1));
  and2((&S_and2_2179_1));
  or2((&S_or2_2177_1));
  and3((&S_and3_2135_1));
  or2((&S_or2_2111_1));
  rs((&S_rs_2096_1));
  rs((&S_rs_2116_1));
  and2((&S_and2_2107_1));
  rs((&S_rs_2117_1));
  or2((&S_or2_2085_1));
  rs((&S_rs_2070_1));
  rs((&S_rs_2090_1));
  and2((&S_and2_2081_1));
  rs((&S_rs_2091_1));
  or3((&S_or3_2003_1));
  or3((&S_or3_2017_1));
  and2((&S_and2_1069_1));
  and2((&S_and2_625_1));
  and2((&S_and2_1044_1));
  or2((&S_or2_1672_1));
  rs((&S_rs_1673_1));
  or2((&S_or2_1675_1));
  rs((&S_rs_1676_1));
  rs((&S_rs_2176_1));
  and2((&S_and2_2102_1));
  rs((&S_rs_2110_1));
  rs((&S_rs_2097_1));
  rs((&S_rs_2100_1));
  and2((&S_and2_2076_1));
  rs((&S_rs_2084_1));
  rs((&S_rs_2071_1));
  rs((&S_rs_2074_1));
  rs((&S_rs_1671_1));
  rs((&S_rs_1037_1));
  noto((&S_noto_1040_1));
  rs((&S_rs_1063_1));
  and3((&S_and3_1029_1));
  and2((&S_and2_980_1));
  and4((&S_and4_987_1));
  and4((&S_and4_993_1));
  rs((&S_rs_1674_1));
  or2((&S_or2_1062_1));
  and2((&S_and2_2103_1));
  orn((&S_orn_1174_1));
  and2((&S_and2_2077_1));
  orn((&S_orn_789_1));
  rs((&S_rs_2098_1));
  and2((&S_and2_2104_1));
  rs((&S_rs_2114_1));
  rs((&S_rs_2072_1));
  ornc((&S_ornc_1184_1));
  charint((&S_charint_1175_1));
  ornc((&S_ornc_796_1));
  charint((&S_charint_790_1));
  rs((&S_rs_2112_1));
  rs((&S_rs_974_1));
  or3((&S_or3_429_1));
  and3((&S_and3_436_1));
  and2((&S_and2_1019_1));
  or2((&S_or2_1999_1));
  and2((&S_and2_468_1));
  and2((&S_and2_439_1));
  and2((&S_and2_2005_1));
  rs((&S_rs_2086_1));
  and2((&S_and2_2078_1));
  rs((&S_rs_2088_1));
  fsumz((&S_fsumz_1176_1));
  fsumz((&S_fsumz_791_1));
  samhd((&S_samhd_449_1));
  samhd((&S_samhd_455_1));
  newstage((&S_newstage_451_1));
  rs((&S_rs_2000_1));
  noto((&S_noto_2001_1));
  ma((&S_ma_797_1));
  ma((&S_ma_1181_1));
  or4((&S_or4_445_1));
  or4((&S_or4_463_1));
  or2((&S_or2_2011_1));
  and2((&S_and2_460_1));
  and2((&S_and2_458_1));
  and2((&S_and2_2016_1));
  fnapb((&S_fnapb_1219_1));
  zpfs((&S_zpfs_1214_1));
  zpfs((&S_zpfs_1205_1));
  fnapb((&S_fnapb_820_1));
  rs((&S_rs_2012_1));
  noto((&S_noto_2013_1));
  zpfs((&S_zpfs_1220_1));
  and2((&S_and2_1070_1));
  and2((&S_and2_641_1));
  zpfs((&S_zpfs_821_1));
  zpfs((&S_zpfs_814_1));
  zpfs((&S_zpfs_817_1));
  or5((&S_or5_1198_1));
  and2((&S_and2_1051_1));
  or2((&S_or2_1703_1));
  rs((&S_rs_1704_1));
  or5((&S_or5_1939_1));
  orni((&S_orni_127_1));
  orn((&S_orn_407_1));
  orn((&S_orn_425_1));
  cnshd((&S_cnshd_1185_1));
  rs((&S_rs_1047_1));
  rs((&S_rs_1066_1));
  or2((&S_or2_409_1));
  or2((&S_or2_426_1));
  and2((&S_and2_669_1));
  or2((&S_or2_1136_1));
  or2((&S_or2_1137_1));
  and2((&S_and2_1083_1));
  or5((&S_or5_809_1));
  and2((&S_and2_1547_1));
  or4((&S_or4_1543_1));
  or4((&S_or4_1940_1));
  orn((&S_orn_753_1));
  orn((&S_orn_1071_1));
  cnshd((&S_cnshd_800_1));
  or2((&S_or2_743_1));
  or2((&S_or2_744_1));
  or4((&S_or4_724_1));
  or5((&S_or5_1109_1));
  or2((&S_or2_351_1));
  or2((&S_or2_355_1));
  ovbs((&S_ovbs_1946_1));
  noto((&S_noto_1947_1));
  and2((&S_and2_1953_1));
  and2((&S_and2_1965_1));
  or3((&S_or3_1941_1));
  and2((&S_and2_1942_1));
  or3((&S_or3_1955_1));
  and2((&S_and2_1956_1));
  or5((&S_or5_1534_1));
  or2((&S_or2_2167_1));
  rs((&S_rs_723_1));
  samhd((&S_samhd_354_1));
  newstage((&S_newstage_1225_1));
  and2((&S_and2_713_1));
  or2((&S_or2_716_1));
  or4((&S_or4_353_1));
  or5((&S_or5_1571_1));
  or2((&S_or2_1960_1));
  or2((&S_or2_1948_1));
  ovbs((&S_ovbs_1943_1));
  ovbs((&S_ovbs_1957_1));
  rs((&S_rs_1976_1));
  rs((&S_rs_1984_1));
  noto((&S_noto_1974_1));
  noto((&S_noto_1995_1));
  andn((&S_andn_1_1));
  and2((&S_and2_1208_1));
  and2((&S_and2_1213_1));
  zpfs((&S_zpfs_1977_1));
  zpfs((&S_zpfs_1985_1));
  noto((&S_noto_2164_1));
  rs((&S_rs_717_1));
  or2((&S_or2_1978_1));
  noto((&S_noto_1944_1));
  noto((&S_noto_1958_1));
  rs((&S_rs_1961_1));
  noto((&S_noto_1962_1));
  rs((&S_rs_1949_1));
  or2((&S_or2_1986_1));
  noto((&S_noto_1979_1));
  and2((&S_and2_1980_1));
  and2((&S_and2_1975_1));
  noto((&S_noto_1987_1));
  noto((&S_noto_1967_1));
  noto((&S_noto_1950_1));
  and2((&S_and2_1988_1));
  and4((&S_and4_1969_1));
  ovbs((&S_ovbs_1970_1));
  and2((&S_and2_1996_1));
  noto((&S_noto_1997_1));
  or2((&S_or2_1971_1));
  orn((&S_orn_585_1));
  orn((&S_orn_584_1));
  noto((&S_noto_1972_1));
  and4((&S_and4_1990_1));
  ovbs((&S_ovbs_1991_1));
  or2((&S_or2_1992_1));
  newstage((&S_newstage_587_1));
  or2((&S_or2_621_1));
  ovbs((&S_ovbs_1981_1));
  noto((&S_noto_1993_1));
  and2((&S_and2_620_1));
  signal_B3AB13LDU.b = var70.b;
  signal_B3AB13LDU.error = var70.error;
  signal_A3AB13LDU.b = var73.b;
  signal_A3AB13LDU.error = var73.error;
  signal_R3VS01IDU.i = var79.i;
  signal_R3VS01IDU.error = var79.error;
  signal_R3VS12LDU.b = var77.b;
  signal_R3VS12LDU.error = var77.error;
  signal_R3VS22LDU.b = var78.b;
  signal_R3VS22LDU.error = var78.error;
  signal_R5VS01IDU.i = var76.i;
  signal_R5VS01IDU.error = var76.error;
  signal_R5VS12LDU.b = var74.b;
  signal_R5VS12LDU.error = var74.error;
  signal_R5VS22LDU.b = var75.b;
  signal_R5VS22LDU.error = var75.error;
  signal_B3AB15LDU.b = var83.b;
  signal_B3AB15LDU.error = var83.error;
  signal_B3EE03LDU.b = var770.b;
  signal_B3EE03LDU.error = var770.error;
  signal_A3EE03LDU.b = var771.b;
  signal_A3EE03LDU.error = var771.error;
  signal_B3AB19LDU.b = var88.b;
  signal_B3AB19LDU.error = var88.error;
  signal_A3AB19LDU.b = var89.b;
  signal_A3AB19LDU.error = var89.error;
  signal_R0VL23LDU.b = var1007.b;
  signal_R0VL23LDU.error = var1007.error;
  signal_R0VL22LDU.b = var1029.b;
  signal_R0VL22LDU.error = var1029.error;
  signal_R0AD05LZ2.b = var10.b;
  signal_R0AD05LZ2.error = var10.error;
  signal_R0AD05LZ1.b = var10.b;
  signal_R0AD05LZ1.error = var10.error;
  signal_R0AD04LZ2.b = var315.b;
  signal_R0AD04LZ2.error = var315.error;
  signal_R0AD04LZ1.b = var315.b;
  signal_R0AD04LZ1.error = var315.error;
  signal_R0AD03LZ2.b = var9.b;
  signal_R0AD03LZ2.error = var9.error;
  signal_R0AD03LZ1.b = var9.b;
  signal_R0AD03LZ1.error = var9.error;
  signal_R0CN95LDU.i = var159.i;
  signal_R0CN95LDU.error = var159.error;
  fplet(&signal_R0CN94LDU.f,&var158.f);
  signal_R0CN94LDU.error = var158.error;
  fplet(&signal_R0CN93LDU.f,&var157.f);
  signal_R0CN93LDU.error = var157.error;
  signal_R0AB19LDU.b = var120.b;
  signal_R0AB19LDU.error = var120.error;
  fplet(&signal_R0VN12RDU.f,&var940.f);
  signal_R0VN12RDU.error = var940.error;
  fplet(&signal_R0VN11RDU.f,&var938.f);
  signal_R0VN11RDU.error = var938.error;
  fplet(&signal_R0CN92LDU.f,&var124.f);
  signal_R0CN92LDU.error = var124.error;
  signal_R0AB20LDU.b = var136.b;
  signal_R0AB20LDU.error = var136.error;
  signal_A3AB15LDU.b = var84.b;
  signal_A3AB15LDU.error = var84.error;
  fplet(&signal_A3MC03RDU.f,&var155.f);
  signal_A3MC03RDU.error = var155.error;
  fplet(&signal_R0CN91LDU.f,&var154.f);
  signal_R0CN91LDU.error = var154.error;
  fplet(&signal_A3MC02RDU.f,&var153.f);
  signal_A3MC02RDU.error = var153.error;
  fplet(&signal_A3MC01RDU.f,&var152.f);
  signal_A3MC01RDU.error = var152.error;
  signal_R0AB18LDU.b = var141.b;
  signal_R0AB18LDU.error = var141.error;
  signal_R0AB17LDU.b = var148.b;
  signal_R0AB17LDU.error = var148.error;
  signal_R0AB16LDU.b = var149.b;
  signal_R0AB16LDU.error = var149.error;
  signal_B1AB19LDU.b = var166.b;
  signal_B1AB19LDU.error = var166.error;
  signal_A3ZAV.b = var1283.b;
  signal_A3ZAV.error = var1283.error;
  signal_A1ZAV.b = var1346.b;
  signal_A1ZAV.error = var1346.error;
  signal_B3IS12LDU.b = var176.b;
  signal_B3IS12LDU.error = var176.error;
  signal_A3IS12LDU.b = var177.b;
  signal_A3IS12LDU.error = var177.error;
  signal_R0AB15LDU.b = var182.b;
  signal_R0AB15LDU.error = var182.error;
  signal_R0AB14LDU.b = var180.b;
  signal_R0AB14LDU.error = var180.error;
  signal_A4DW.b = var1117.b;
  signal_A4DW.error = var1117.error;
  signal_A4UP.b = var1118.b;
  signal_A4UP.error = var1118.error;
  signal_R4ABL.b = var1585.b;
  signal_R4ABL.error = var1585.error;
  signal_A9ZAV.b = var1221.b;
  signal_A9ZAV.error = var1221.error;
  signal_A8ZAV.b = var1422.b;
  signal_A8ZAV.error = var1422.error;
  signal_A2ZAV.b = var1427.b;
  signal_A2ZAV.error = var1427.error;
  signal_B8ZAV.b = var1432.b;
  signal_B8ZAV.error = var1432.error;
  signal_A5ZAV.b = var1500.b;
  signal_A5ZAV.error = var1500.error;
  signal_R2ZAV.b = var1376.b;
  signal_R2ZAV.error = var1376.error;
  signal_A6ZAV.b = var1502.b;
  signal_A6ZAV.error = var1502.error;
  signal_A4ZAV.b = var1501.b;
  signal_A4ZAV.error = var1501.error;
  signal_R0AB13LDU.b = var253.b;
  signal_R0AB13LDU.error = var253.error;
  signal_R0AB12LDU.b = var257.b;
  signal_R0AB12LDU.error = var257.error;
  signal_R0AB11LDU.b = var261.b;
  signal_R0AB11LDU.error = var261.error;
  signal_R0AB10LDU.b = var265.b;
  signal_R0AB10LDU.error = var265.error;
  signal_R0AB09LDU.b = var269.b;
  signal_R0AB09LDU.error = var269.error;
  signal_R0AB08LDU.b = var273.b;
  signal_R0AB08LDU.error = var273.error;
  signal_B6AB05LDU.b = var316.b;
  signal_B6AB05LDU.error = var316.error;
  signal_R0VS11LDU.b = var1631.b;
  signal_R0VS11LDU.error = var1631.error;
  signal_A8VS01IDU.i = var1426.c;
  signal_A8VS01IDU.error = var1426.error;
  signal_B8VS01IDU.i = var1436.c;
  signal_B8VS01IDU.error = var1436.error;
  signal_R2AD10LDU.b = var1381.b;
  signal_R2AD10LDU.error = var1381.error;
  signal_R2AD20LDU.b = var1382.b;
  signal_R2AD20LDU.error = var1382.error;
  signal_B6VS01IDU.i = var1573.i;
  signal_B6VS01IDU.error = var1573.error;
  signal_R0AD16LDU.b = var339.b;
  signal_R0AD16LDU.error = var339.error;
  signal_R0AB07LDU.b = var570.b;
  signal_R0AB07LDU.error = var570.error;
  signal_R0EE03LDU.b = var340.b;
  signal_R0EE03LDU.error = var340.error;
  signal_R0VX02LDU.b = var776.b;
  signal_R0VX02LDU.error = var776.error;
  signal_R0AD21LDU.b = var774.b;
  signal_R0AD21LDU.error = var774.error;
  signal_B2AB15LDU.b = var286.b;
  signal_B2AB15LDU.error = var286.error;
  signal_A2AB15LDU.b = var287.b;
  signal_A2AB15LDU.error = var287.error;
  signal_R0AB05LDU.b = var1089.b;
  signal_R0AB05LDU.error = var1089.error;
  signal_R0AB03LDU.b = var1100.b;
  signal_R0AB03LDU.error = var1100.error;
  signal_A1AB19LDU.b = var167.b;
  signal_A1AB19LDU.error = var167.error;
  signal_R0VZ71LDU.b = var863.b;
  signal_R0VZ71LDU.error = var863.error;
  fplet(&signal_R0VL01RDU.f,&var1136.f);
  signal_R0VL01RDU.error = var1136.error;
  signal_B7AZ03LDU.b = var317.b;
  signal_B7AZ03LDU.error = var317.error;
  signal_A7AZ03LDU.b = var425.b;
  signal_A7AZ03LDU.error = var425.error;
  signal_B2VS01IDU.i = var1414.c;
  signal_B2VS01IDU.error = var1414.error;
  signal_B2VS21LDU.b = var1416.b;
  signal_B2VS21LDU.error = var1416.error;
  signal_B2VS11LDU.b = var1415.b;
  signal_B2VS11LDU.error = var1415.error;
  signal_R0VP73LDU.b = var436.b;
  signal_R0VP73LDU.error = var436.error;
  signal_R0VS18LDU.b = var527.b;
  signal_R0VS18LDU.error = var527.error;
  signal_B3VX01LDU.b = var383.b;
  signal_B3VX01LDU.error = var383.error;
  signal_A3VX01LDU.b = var384.b;
  signal_A3VX01LDU.error = var384.error;
  signal_B2VS32LDU.b = var299.b;
  signal_B2VS32LDU.error = var299.error;
  signal_A2VS32LDU.b = var300.b;
  signal_A2VS32LDU.error = var300.error;
  signal_R0VS17LDU.b = var517.b;
  signal_R0VS17LDU.error = var517.error;
  signal_R0VX09LDU.b = var112.b;
  signal_R0VX09LDU.error = var112.error;
  signal_R0VX08IDU.i = signal_R0MW12IP1.i;
  signal_R0VX08IDU.error = signal_R0MW12IP1.error;
  signal_R0VW23LDU.b = var872.b;
  signal_R0VW23LDU.error = var872.error;
  signal_R0VW13LDU.b = var871.b;
  signal_R0VW13LDU.error = var871.error;
  signal_B7AP31LDU.b = var1120.b;
  signal_B7AP31LDU.error = var1120.error;
  signal_A7AP31LDU.b = var1121.b;
  signal_A7AP31LDU.error = var1121.error;
  signal_B3AD31LDU.b = var1184.b;
  signal_B3AD31LDU.error = var1184.error;
  signal_B3AD34LDU.b = var1185.b;
  signal_B3AD34LDU.error = var1185.error;
  signal_A3AD31LDU.b = var1190.b;
  signal_A3AD31LDU.error = var1190.error;
  signal_A3AD34LDU.b = var1187.b;
  signal_A3AD34LDU.error = var1187.error;
  signal_A3AD33LDU.b = var1189.b;
  signal_A3AD33LDU.error = var1189.error;
  signal_B2AD33LDU.b = var278.b;
  signal_B2AD33LDU.error = var278.error;
  signal_A2AD33LDU.b = var281.b;
  signal_A2AD33LDU.error = var281.error;
  signal_R0AB01LDU.b = var1213.b;
  signal_R0AB01LDU.error = var1213.error;
  signal_B9AB02LDU.b = var1223.b;
  signal_B9AB02LDU.error = var1223.error;
  signal_B9AB01LDU.b = var1224.b;
  signal_B9AB01LDU.error = var1224.error;
  signal_B9AZ03LDU.b = var1222.b;
  signal_B9AZ03LDU.error = var1222.error;
  signal_A9AB02LDU.b = var1229.b;
  signal_A9AB02LDU.error = var1229.error;
  signal_A9AB01LDU.b = var1230.b;
  signal_A9AB01LDU.error = var1230.error;
  signal_A9AZ03LDU.b = var1228.b;
  signal_A9AZ03LDU.error = var1228.error;
  signal_A9AD10LDU.b = var1231.b;
  signal_A9AD10LDU.error = var1231.error;
  signal_B9AD10LDU.b = var1225.b;
  signal_B9AD10LDU.error = var1225.error;
  signal_R1VS01IDU.i = var1392.i;
  signal_R1VS01IDU.error = var1392.error;
  signal_R2VS01IDU.i = var1383.i;
  signal_R2VS01IDU.error = var1383.error;
  signal_R4VS01IDU.i = var1564.i;
  signal_R4VS01IDU.error = var1564.error;
  signal_A6VS01IDU.i = var1582.i;
  signal_A6VS01IDU.error = var1582.error;
  signal_B5VS01IDU.i = var1546.i;
  signal_B5VS01IDU.error = var1546.error;
  signal_A5VS01IDU.i = var1555.i;
  signal_A5VS01IDU.error = var1555.error;
  signal_B4VS22LDU.b = var1527.b;
  signal_B4VS22LDU.error = var1527.error;
  signal_B4VS12LDU.b = var1526.b;
  signal_B4VS12LDU.error = var1526.error;
  signal_B4VS01IDU.i = var1528.i;
  signal_B4VS01IDU.error = var1528.error;
  signal_A4VS22LDU.b = var1536.b;
  signal_A4VS22LDU.error = var1536.error;
  signal_A4VS12LDU.b = var1535.b;
  signal_A4VS12LDU.error = var1535.error;
  signal_A4VS01IDU.i = var1537.i;
  signal_A4VS01IDU.error = var1537.error;
  signal_A2VS01IDU.i = var1455.c;
  signal_A2VS01IDU.error = var1455.error;
  signal_B3VS01IDU.i = var1273.c;
  signal_B3VS01IDU.error = var1273.error;
  signal_A3VS01IDU.i = var1305.c;
  signal_A3VS01IDU.error = var1305.error;
  signal_B1VS01IDU.i = var1334.c;
  signal_B1VS01IDU.error = var1334.error;
  signal_A1VS01IDU.i = var1367.c;
  signal_A1VS01IDU.error = var1367.error;
  signal_R0VS21IDU.i = var1110.i;
  signal_R0VS21IDU.error = var1110.error;
  signal_R0VX03LDU.b = var721.b;
  signal_R0VX03LDU.error = var721.error;
  signal_R0VL21IDU.i = var1020.i;
  signal_R0VL21IDU.error = var1020.error;
  fplet(&signal_R0VL05RDU.f,&var370.f);
  signal_R0VL05RDU.error = var370.error;
  fplet(&signal_R0VL03RDU.f,&var376.f);
  signal_R0VL03RDU.error = var376.error;
  signal_R0AB02LDU.b = var1083.b;
  signal_R0AB02LDU.error = var1083.error;
  signal_R0AB06LDU.b = var1086.b;
  signal_R0AB06LDU.error = var1086.error;
  signal_R0AB04LDU.b = var1094.b;
  signal_R0AB04LDU.error = var1094.error;
  fplet(&signal_R0VL04RDU.f,&var373.f);
  signal_R0VL04RDU.error = var373.error;
  signal_R0AD14LDU.b = var315.b;
  signal_R0AD14LDU.error = var315.error;
  signal_R8AD21LDU.b = var338.b;
  signal_R8AD21LDU.error = var338.error;
  fplet(&signal_R0VL02RDU.f,&var367.f);
  signal_R0VL02RDU.error = var367.error;
  signal_B3AD33LDU.b = var1183.b;
  signal_B3AD33LDU.error = var1183.error;
  fplet(&signal_R0VL06RDU.f,&var380.f);
  signal_R0VL06RDU.error = var380.error;
  signal_R0VL11IDU.i = var1237.i;
  signal_R0VL11IDU.error = var1237.error;
  signal_R0VL01IDU.i = var1238.i;
  signal_R0VL01IDU.error = var1238.error;
  signal_R0VX01LDU.b = var778.b;
  signal_R0VX01LDU.error = var778.error;
  signal_B1AD32LDU.b = var1191.b;
  signal_B1AD32LDU.error = var1191.error;
  signal_A1AD32LDU.b = var1193.b;
  signal_A1AD32LDU.error = var1193.error;
  signal_B2AD32LDU.b = var306.b;
  signal_B2AD32LDU.error = var306.error;
  signal_A2AD32LDU.b = var308.b;
  signal_A2AD32LDU.error = var308.error;
  signal_B1AD31LDU.b = var1194.b;
  signal_B1AD31LDU.error = var1194.error;
  signal_A1AD31LDU.b = var1195.b;
  signal_A1AD31LDU.error = var1195.error;
  signal_B2AD31LDU.b = var309.b;
  signal_B2AD31LDU.error = var309.error;
  signal_A2AD31LDU.b = var310.b;
  signal_A2AD31LDU.error = var310.error;
  signal_B3AB20LDU.b = var612.b;
  signal_B3AB20LDU.error = var612.error;
  signal_B3AB18LDU.b = var609.b;
  signal_B3AB18LDU.error = var609.error;
  signal_B3AB17LDU.b = var605.b;
  signal_B3AB17LDU.error = var605.error;
  signal_B3AB16LDU.b = var606.b;
  signal_B3AB16LDU.error = var606.error;
  signal_B3AB14LDU.b = var881.b;
  signal_B3AB14LDU.error = var881.error;
  signal_B3AB12LDU.b = var610.b;
  signal_B3AB12LDU.error = var610.error;
  signal_B3AB11LDU.b = var614.b;
  signal_B3AB11LDU.error = var614.error;
  signal_B3AB10LDU.b = var615.b;
  signal_B3AB10LDU.error = var615.error;
  signal_B3AB09LDU.b = var616.b;
  signal_B3AB09LDU.error = var616.error;
  signal_B3AB06LDU.b = var619.b;
  signal_B3AB06LDU.error = var619.error;
  signal_B3AB05LDU.b = var621.b;
  signal_B3AB05LDU.error = var621.error;
  signal_B3AB08LDU.b = var611.b;
  signal_B3AB08LDU.error = var611.error;
  signal_B3AB07LDU.b = var620.b;
  signal_B3AB07LDU.error = var620.error;
  fplet(&signal_B3CV02RDU.f,&var1272.f);
  signal_B3CV02RDU.error = var1272.error;
  signal_B3AD01LDU.b = var1265.b;
  signal_B3AD01LDU.error = var1265.error;
  signal_B3AD05LDU.b = var1271.b;
  signal_B3AD05LDU.error = var1271.error;
  signal_B3AD04LDU.b = var1270.b;
  signal_B3AD04LDU.error = var1270.error;
  signal_B3AD03LDU.b = var1269.b;
  signal_B3AD03LDU.error = var1269.error;
  signal_B3AD02LDU.b = var1268.b;
  signal_B3AD02LDU.error = var1268.error;
  signal_B3AD21LDU.b = var1266.b;
  signal_B3AD21LDU.error = var1266.error;
  signal_B3AD11LDU.b = var1267.b;
  signal_B3AD11LDU.error = var1267.error;
  signal_B3AZ03LDU.b = var953.b;
  signal_B3AZ03LDU.error = var953.error;
  signal_B3VS22LDU.b = var1276.b;
  signal_B3VS22LDU.error = var1276.error;
  signal_B3AB01LDU.b = var1274.b;
  signal_B3AB01LDU.error = var1274.error;
  signal_B3AB02LDU.b = var1275.b;
  signal_B3AB02LDU.error = var1275.error;
  signal_B3AB04LDU.b = var1280.b;
  signal_B3AB04LDU.error = var1280.error;
  fplet(&signal_B3CV01RDU.f,&var1278.f);
  signal_B3CV01RDU.error = var1278.error;
  signal_B3VS12LDU.b = var1277.b;
  signal_B3VS12LDU.error = var1277.error;
  signal_A3AB20LDU.b = var348.b;
  signal_A3AB20LDU.error = var348.error;
  signal_A3AB18LDU.b = var626.b;
  signal_A3AB18LDU.error = var626.error;
  signal_A3AB17LDU.b = var624.b;
  signal_A3AB17LDU.error = var624.error;
  signal_A3AB16LDU.b = var623.b;
  signal_A3AB16LDU.error = var623.error;
  signal_A3AB14LDU.b = var883.b;
  signal_A3AB14LDU.error = var883.error;
  signal_A3AB12LDU.b = var627.b;
  signal_A3AB12LDU.error = var627.error;
  signal_A3AB11LDU.b = var631.b;
  signal_A3AB11LDU.error = var631.error;
  signal_A3AB10LDU.b = var635.b;
  signal_A3AB10LDU.error = var635.error;
  signal_A3AB09LDU.b = var629.b;
  signal_A3AB09LDU.error = var629.error;
  signal_A3AB06LDU.b = var634.b;
  signal_A3AB06LDU.error = var634.error;
  signal_A3AB05LDU.b = var637.b;
  signal_A3AB05LDU.error = var637.error;
  signal_A3AB08LDU.b = var628.b;
  signal_A3AB08LDU.error = var628.error;
  signal_A3AB07LDU.b = var636.b;
  signal_A3AB07LDU.error = var636.error;
  fplet(&signal_A3CV02RDU.f,&var1304.f);
  signal_A3CV02RDU.error = var1304.error;
  signal_A3AD01LDU.b = var1297.b;
  signal_A3AD01LDU.error = var1297.error;
  signal_A3AD05LDU.b = var1303.b;
  signal_A3AD05LDU.error = var1303.error;
  signal_A3AD04LDU.b = var1302.b;
  signal_A3AD04LDU.error = var1302.error;
  signal_A3AD03LDU.b = var1301.b;
  signal_A3AD03LDU.error = var1301.error;
  signal_A3AD02LDU.b = var1300.b;
  signal_A3AD02LDU.error = var1300.error;
  signal_A3AD21LDU.b = var1298.b;
  signal_A3AD21LDU.error = var1298.error;
  signal_A3AD11LDU.b = var1299.b;
  signal_A3AD11LDU.error = var1299.error;
  signal_A3AZ03LDU.b = var954.b;
  signal_A3AZ03LDU.error = var954.error;
  signal_A3VS22LDU.b = var1308.b;
  signal_A3VS22LDU.error = var1308.error;
  signal_A3AB01LDU.b = var1306.b;
  signal_A3AB01LDU.error = var1306.error;
  signal_A3AB02LDU.b = var1307.b;
  signal_A3AB02LDU.error = var1307.error;
  signal_A3AB04LDU.b = var1312.b;
  signal_A3AB04LDU.error = var1312.error;
  fplet(&signal_A3CV01RDU.f,&var1310.f);
  signal_A3CV01RDU.error = var1310.error;
  signal_A3VS12LDU.b = var1309.b;
  signal_A3VS12LDU.error = var1309.error;
  signal_B1AB18LDU.b = var696.b;
  signal_B1AB18LDU.error = var696.error;
  signal_B1AB17LDU.b = var866.b;
  signal_B1AB17LDU.error = var866.error;
  signal_B1AB16LDU.b = var865.b;
  signal_B1AB16LDU.error = var865.error;
  signal_B1AB14LDU.b = var885.b;
  signal_B1AB14LDU.error = var885.error;
  signal_B1AB13LDU.b = var886.b;
  signal_B1AB13LDU.error = var886.error;
  signal_B1AB12LDU.b = var694.b;
  signal_B1AB12LDU.error = var694.error;
  signal_B1AB11LDU.b = var698.b;
  signal_B1AB11LDU.error = var698.error;
  signal_B1AB10LDU.b = var699.b;
  signal_B1AB10LDU.error = var699.error;
  signal_B1AB09LDU.b = var702.b;
  signal_B1AB09LDU.error = var702.error;
  signal_B1AB06LDU.b = var700.b;
  signal_B1AB06LDU.error = var700.error;
  signal_B1AB05LDU.b = var707.b;
  signal_B1AB05LDU.error = var707.error;
  signal_B1AB08LDU.b = var695.b;
  signal_B1AB08LDU.error = var695.error;
  signal_B1AB07LDU.b = var706.b;
  signal_B1AB07LDU.error = var706.error;
  fplet(&signal_B1CV02RDU.f,&var1333.f);
  signal_B1CV02RDU.error = var1333.error;
  signal_B1AD01LDU.b = var1326.b;
  signal_B1AD01LDU.error = var1326.error;
  signal_B1AD05LDU.b = var1332.b;
  signal_B1AD05LDU.error = var1332.error;
  signal_B1AD04LDU.b = var1331.b;
  signal_B1AD04LDU.error = var1331.error;
  signal_B1AD03LDU.b = var1330.b;
  signal_B1AD03LDU.error = var1330.error;
  signal_B1AD02LDU.b = var1329.b;
  signal_B1AD02LDU.error = var1329.error;
  signal_B1AD21LDU.b = var1328.b;
  signal_B1AD21LDU.error = var1328.error;
  signal_B1AD11LDU.b = var1327.b;
  signal_B1AD11LDU.error = var1327.error;
  signal_B1AZ03LDU.b = var709.b;
  signal_B1AZ03LDU.error = var709.error;
  signal_B1VS22LDU.b = var1338.b;
  signal_B1VS22LDU.error = var1338.error;
  signal_B1AB01LDU.b = var1335.b;
  signal_B1AB01LDU.error = var1335.error;
  signal_B1AB02LDU.b = var1336.b;
  signal_B1AB02LDU.error = var1336.error;
  signal_B1AB04LDU.b = var1341.b;
  signal_B1AB04LDU.error = var1341.error;
  fplet(&signal_B1CV01RDU.f,&var1339.f);
  signal_B1CV01RDU.error = var1339.error;
  signal_B1VS12LDU.b = var1337.b;
  signal_B1VS12LDU.error = var1337.error;
  signal_A1AB18LDU.b = var672.b;
  signal_A1AB18LDU.error = var672.error;
  signal_A1AB17LDU.b = var671.b;
  signal_A1AB17LDU.error = var671.error;
  signal_A1AB16LDU.b = var673.b;
  signal_A1AB16LDU.error = var673.error;
  signal_A1AB14LDU.b = var888.b;
  signal_A1AB14LDU.error = var888.error;
  signal_A1AB13LDU.b = var889.b;
  signal_A1AB13LDU.error = var889.error;
  signal_A1AB12LDU.b = var669.b;
  signal_A1AB12LDU.error = var669.error;
  signal_A1AB11LDU.b = var678.b;
  signal_A1AB11LDU.error = var678.error;
  signal_A1AB10LDU.b = var676.b;
  signal_A1AB10LDU.error = var676.error;
  signal_A1AB09LDU.b = var675.b;
  signal_A1AB09LDU.error = var675.error;
  signal_A1AB06LDU.b = var680.b;
  signal_A1AB06LDU.error = var680.error;
  signal_A1AB05LDU.b = var681.b;
  signal_A1AB05LDU.error = var681.error;
  signal_A1AB08LDU.b = var674.b;
  signal_A1AB08LDU.error = var674.error;
  signal_A1AB07LDU.b = var682.b;
  signal_A1AB07LDU.error = var682.error;
  fplet(&signal_A1CV02RDU.f,&var1366.f);
  signal_A1CV02RDU.error = var1366.error;
  signal_A1AD01LDU.b = var1359.b;
  signal_A1AD01LDU.error = var1359.error;
  signal_A1AD05LDU.b = var1365.b;
  signal_A1AD05LDU.error = var1365.error;
  signal_A1AD04LDU.b = var1364.b;
  signal_A1AD04LDU.error = var1364.error;
  signal_A1AD03LDU.b = var1363.b;
  signal_A1AD03LDU.error = var1363.error;
  signal_A1AD02LDU.b = var1362.b;
  signal_A1AD02LDU.error = var1362.error;
  signal_A1AD21LDU.b = var1361.b;
  signal_A1AD21LDU.error = var1361.error;
  signal_A1AD11LDU.b = var1360.b;
  signal_A1AD11LDU.error = var1360.error;
  signal_A1AZ03LDU.b = var689.b;
  signal_A1AZ03LDU.error = var689.error;
  signal_A1VS22LDU.b = var1369.b;
  signal_A1VS22LDU.error = var1369.error;
  signal_A1AB01LDU.b = var687.b;
  signal_A1AB01LDU.error = var687.error;
  signal_A1AB02LDU.b = var688.b;
  signal_A1AB02LDU.error = var688.error;
  signal_A1AB04LDU.b = var1372.b;
  signal_A1AB04LDU.error = var1372.error;
  fplet(&signal_A1CV01RDU.f,&var1370.f);
  signal_A1CV01RDU.error = var1370.error;
  signal_A1VS12LDU.b = var1368.b;
  signal_A1VS12LDU.error = var1368.error;
  signal_R1AD20LDU.b = var1391.b;
  signal_R1AD20LDU.error = var1391.error;
  signal_R1AD10LDU.b = var1390.b;
  signal_R1AD10LDU.error = var1390.error;
  signal_R2AB04LDU.b = var1379.b;
  signal_R2AB04LDU.error = var1379.error;
  signal_R1AB04LDU.b = var1388.b;
  signal_R1AB04LDU.error = var1388.error;
  signal_R2AB02LDU.b = var1378.b;
  signal_R2AB02LDU.error = var1378.error;
  signal_R2AB01LDU.b = var1380.b;
  signal_R2AB01LDU.error = var1380.error;
  signal_R2AZ03LDU.b = var1377.b;
  signal_R2AZ03LDU.error = var1377.error;
  signal_R1AB02LDU.b = var1387.b;
  signal_R1AB02LDU.error = var1387.error;
  signal_R1AB01LDU.b = var1389.b;
  signal_R1AB01LDU.error = var1389.error;
  signal_R1AZ03LDU.b = var1386.b;
  signal_R1AZ03LDU.error = var1386.error;
  signal_B2AB17LDU.b = var645.b;
  signal_B2AB17LDU.error = var645.error;
  signal_B2AB16LDU.b = var644.b;
  signal_B2AB16LDU.error = var644.error;
  signal_B2AB14LDU.b = var890.b;
  signal_B2AB14LDU.error = var890.error;
  signal_B2AB13LDU.b = var891.b;
  signal_B2AB13LDU.error = var891.error;
  signal_B2AB12LDU.b = var646.b;
  signal_B2AB12LDU.error = var646.error;
  signal_B2AB11LDU.b = var650.b;
  signal_B2AB11LDU.error = var650.error;
  signal_B2AB10LDU.b = var649.b;
  signal_B2AB10LDU.error = var649.error;
  signal_B2AB09LDU.b = var648.b;
  signal_B2AB09LDU.error = var648.error;
  signal_B2AB06LDU.b = var653.b;
  signal_B2AB06LDU.error = var653.error;
  signal_B2AB05LDU.b = var652.b;
  signal_B2AB05LDU.error = var652.error;
  signal_B2AB08LDU.b = var647.b;
  signal_B2AB08LDU.error = var647.error;
  signal_B2AB07LDU.b = var654.b;
  signal_B2AB07LDU.error = var654.error;
  fplet(&signal_B2CV02RDU.f,&var1413.f);
  signal_B2CV02RDU.error = var1413.error;
  signal_B2AD01LDU.b = var1406.b;
  signal_B2AD01LDU.error = var1406.error;
  signal_B2AD05LDU.b = var1412.b;
  signal_B2AD05LDU.error = var1412.error;
  signal_B2AD04LDU.b = var1411.b;
  signal_B2AD04LDU.error = var1411.error;
  signal_B2AD03LDU.b = var1410.b;
  signal_B2AD03LDU.error = var1410.error;
  signal_B2AD02LDU.b = var1409.b;
  signal_B2AD02LDU.error = var1409.error;
  signal_B2AD21LDU.b = var1408.b;
  signal_B2AD21LDU.error = var1408.error;
  signal_B2AD11LDU.b = var1407.b;
  signal_B2AD11LDU.error = var1407.error;
  signal_B2AZ03LDU.b = var662.b;
  signal_B2AZ03LDU.error = var662.error;
  signal_B2AB01LDU.b = var661.b;
  signal_B2AB01LDU.error = var661.error;
  signal_B2AB02LDU.b = var660.b;
  signal_B2AB02LDU.error = var660.error;
  signal_B2AB04LDU.b = var1419.b;
  signal_B2AB04LDU.error = var1419.error;
  fplet(&signal_B2CV01RDU.f,&var1417.f);
  signal_B2CV01RDU.error = var1417.error;
  fplet(&signal_A2CV02RDU.f,&var1454.f);
  signal_A2CV02RDU.error = var1454.error;
  signal_A2AD01LDU.b = var1447.b;
  signal_A2AD01LDU.error = var1447.error;
  signal_A2AB17LDU.b = var583.b;
  signal_A2AB17LDU.error = var583.error;
  signal_A2AB16LDU.b = var584.b;
  signal_A2AB16LDU.error = var584.error;
  signal_A2AB14LDU.b = var587.b;
  signal_A2AB14LDU.error = var587.error;
  signal_A2AB13LDU.b = var588.b;
  signal_A2AB13LDU.error = var588.error;
  signal_A2AB12LDU.b = var585.b;
  signal_A2AB12LDU.error = var585.error;
  signal_A2AB11LDU.b = var593.b;
  signal_A2AB11LDU.error = var593.error;
  signal_A2AB10LDU.b = var591.b;
  signal_A2AB10LDU.error = var591.error;
  signal_A2AB09LDU.b = var589.b;
  signal_A2AB09LDU.error = var589.error;
  signal_A2AB06LDU.b = var594.b;
  signal_A2AB06LDU.error = var594.error;
  signal_A2AB05LDU.b = var590.b;
  signal_A2AB05LDU.error = var590.error;
  signal_A2AB08LDU.b = var586.b;
  signal_A2AB08LDU.error = var586.error;
  signal_A2AB07LDU.b = var592.b;
  signal_A2AB07LDU.error = var592.error;
  signal_A2AD05LDU.b = var1453.b;
  signal_A2AD05LDU.error = var1453.error;
  signal_A2AD04LDU.b = var1452.b;
  signal_A2AD04LDU.error = var1452.error;
  signal_A2AD03LDU.b = var1451.b;
  signal_A2AD03LDU.error = var1451.error;
  signal_A2AD02LDU.b = var1450.b;
  signal_A2AD02LDU.error = var1450.error;
  signal_A2AD21LDU.b = var1449.b;
  signal_A2AD21LDU.error = var1449.error;
  signal_A2AD11LDU.b = var1448.b;
  signal_A2AD11LDU.error = var1448.error;
  signal_A2AZ03LDU.b = var955.b;
  signal_A2AZ03LDU.error = var955.error;
  signal_A2VS21LDU.b = var1459.b;
  signal_A2VS21LDU.error = var1459.error;
  signal_A2AB01LDU.b = var1456.b;
  signal_A2AB01LDU.error = var1456.error;
  signal_A2AB02LDU.b = var1457.b;
  signal_A2AB02LDU.error = var1457.error;
  signal_A2AB04LDU.b = var1462.b;
  signal_A2AB04LDU.error = var1462.error;
  fplet(&signal_A2CV01RDU.f,&var1460.f);
  signal_A2CV01RDU.error = var1460.error;
  signal_A2VS11LDU.b = var1458.b;
  signal_A2VS11LDU.error = var1458.error;
  signal_A8AB01LDU.b = var1470.b;
  signal_A8AB01LDU.error = var1470.error;
  signal_A8AB02LDU.b = var464.b;
  signal_A8AB02LDU.error = var464.error;
  signal_A8AB14LDU.b = var465.b;
  signal_A8AB14LDU.error = var465.error;
  signal_A8AB13LDU.b = var466.b;
  signal_A8AB13LDU.error = var466.error;
  signal_A8AB12LDU.b = var468.b;
  signal_A8AB12LDU.error = var468.error;
  signal_A8AB11LDU.b = var469.b;
  signal_A8AB11LDU.error = var469.error;
  signal_A8AB10LDU.b = var470.b;
  signal_A8AB10LDU.error = var470.error;
  signal_A8AB09LDU.b = var471.b;
  signal_A8AB09LDU.error = var471.error;
  signal_A8AB08LDU.b = var472.b;
  signal_A8AB08LDU.error = var472.error;
  signal_A8AB04LDU.b = var1469.b;
  signal_A8AB04LDU.error = var1469.error;
  signal_A8AD20LDU.b = var1425.b;
  signal_A8AD20LDU.error = var1425.error;
  signal_A8AD10LDU.b = var1424.b;
  signal_A8AD10LDU.error = var1424.error;
  signal_A8AZ03LDU.b = var945.b;
  signal_A8AZ03LDU.error = var945.error;
  signal_A8VS22LDU.b = var1472.b;
  signal_A8VS22LDU.error = var1472.error;
  signal_A8AB05LDU.b = var1467.b;
  signal_A8AB05LDU.error = var1467.error;
  signal_A8AB07LDU.b = var1468.b;
  signal_A8AB07LDU.error = var1468.error;
  signal_A8AB06LDU.b = var1475.b;
  signal_A8AB06LDU.error = var1475.error;
  fplet(&signal_A8CV01RDU.f,&var1473.f);
  signal_A8CV01RDU.error = var1473.error;
  signal_A8VS12LDU.b = var1471.b;
  signal_A8VS12LDU.error = var1471.error;
  signal_B8AB02LDU.b = var789.b;
  signal_B8AB02LDU.error = var789.error;
  signal_B8AB14LDU.b = var790.b;
  signal_B8AB14LDU.error = var790.error;
  signal_B8AB13LDU.b = var791.b;
  signal_B8AB13LDU.error = var791.error;
  signal_B8AB12LDU.b = var792.b;
  signal_B8AB12LDU.error = var792.error;
  signal_B8AB11LDU.b = var796.b;
  signal_B8AB11LDU.error = var796.error;
  signal_B8AB10LDU.b = var793.b;
  signal_B8AB10LDU.error = var793.error;
  signal_B8AB09LDU.b = var794.b;
  signal_B8AB09LDU.error = var794.error;
  signal_B8AB08LDU.b = var795.b;
  signal_B8AB08LDU.error = var795.error;
  signal_B8AB04LDU.b = var1486.b;
  signal_B8AB04LDU.error = var1486.error;
  signal_B8AB01LDU.b = var1487.b;
  signal_B8AB01LDU.error = var1487.error;
  signal_B8AD20LDU.b = var1435.b;
  signal_B8AD20LDU.error = var1435.error;
  signal_B8AD10LDU.b = var1434.b;
  signal_B8AD10LDU.error = var1434.error;
  signal_B8AZ03LDU.b = var946.b;
  signal_B8AZ03LDU.error = var946.error;
  signal_B8VS22LDU.b = var1489.b;
  signal_B8VS22LDU.error = var1489.error;
  signal_B8AB05LDU.b = var1478.b;
  signal_B8AB05LDU.error = var1478.error;
  signal_B8AB07LDU.b = var1479.b;
  signal_B8AB07LDU.error = var1479.error;
  signal_B8AB06LDU.b = var1492.b;
  signal_B8AB06LDU.error = var1492.error;
  fplet(&signal_B8CV01RDU.f,&var1490.f);
  signal_B8CV01RDU.error = var1490.error;
  signal_B8VS12LDU.b = var1488.b;
  signal_B8VS12LDU.error = var1488.error;
  signal_A6AB05LDU.b = var913.b;
  signal_A6AB05LDU.error = var913.error;
  signal_B6AB09LDU.b = var912.b;
  signal_B6AB09LDU.error = var912.error;
  signal_B6AB08LDU.b = var911.b;
  signal_B6AB08LDU.error = var911.error;
  signal_B6AB07LDU.b = var910.b;
  signal_B6AB07LDU.error = var910.error;
  signal_B6AB06LDU.b = var909.b;
  signal_B6AB06LDU.error = var909.error;
  signal_A6AB09LDU.b = var914.b;
  signal_A6AB09LDU.error = var914.error;
  signal_A6AB08LDU.b = var900.b;
  signal_A6AB08LDU.error = var900.error;
  signal_A6AB07LDU.b = var82.b;
  signal_A6AB07LDU.error = var82.error;
  signal_A6AB06LDU.b = var915.b;
  signal_A6AB06LDU.error = var915.error;
  signal_B5AB04LDU.b = var1542.b;
  signal_B5AB04LDU.error = var1542.error;
  signal_A5AB04LDU.b = var1551.b;
  signal_A5AB04LDU.error = var1551.error;
  signal_B4AB02LDU.b = var1523.b;
  signal_B4AB02LDU.error = var1523.error;
  signal_B4AB01LDU.b = var1524.b;
  signal_B4AB01LDU.error = var1524.error;
  signal_B4AZ03LDU.b = var1522.b;
  signal_B4AZ03LDU.error = var1522.error;
  signal_A4AB02LDU.b = var1532.b;
  signal_A4AB02LDU.error = var1532.error;
  signal_A4AB01LDU.b = var1533.b;
  signal_A4AB01LDU.error = var1533.error;
  signal_A4AZ03LDU.b = var1531.b;
  signal_A4AZ03LDU.error = var1531.error;
  signal_A4AD10LDU.b = var1534.b;
  signal_A4AD10LDU.error = var1534.error;
  signal_B4AD10LDU.b = var1525.b;
  signal_B4AD10LDU.error = var1525.error;
  signal_B5AB02LDU.b = var1541.b;
  signal_B5AB02LDU.error = var1541.error;
  signal_B5AB01LDU.b = var1543.b;
  signal_B5AB01LDU.error = var1543.error;
  signal_B5AZ03LDU.b = var1540.b;
  signal_B5AZ03LDU.error = var1540.error;
  signal_A5AB02LDU.b = var1550.b;
  signal_A5AB02LDU.error = var1550.error;
  signal_A5AB01LDU.b = var1552.b;
  signal_A5AB01LDU.error = var1552.error;
  signal_A5AZ03LDU.b = var1549.b;
  signal_A5AZ03LDU.error = var1549.error;
  signal_A5AD20LDU.b = var1554.b;
  signal_A5AD20LDU.error = var1554.error;
  signal_A5AD10LDU.b = var1553.b;
  signal_A5AD10LDU.error = var1553.error;
  signal_B5AD20LDU.b = var1545.b;
  signal_B5AD20LDU.error = var1545.error;
  signal_B5AD10LDU.b = var1544.b;
  signal_B5AD10LDU.error = var1544.error;
  signal_R4AD20LDU.b = var1563.b;
  signal_R4AD20LDU.error = var1563.error;
  signal_R4AD10LDU.b = var1562.b;
  signal_R4AD10LDU.error = var1562.error;
  signal_R4AB18LDU.b = var842.b;
  signal_R4AB18LDU.error = var842.error;
  signal_R4AB17LDU.b = var841.b;
  signal_R4AB17LDU.error = var841.error;
  signal_R4AB16LDU.b = var844.b;
  signal_R4AB16LDU.error = var844.error;
  signal_R4AB15LDU.b = var843.b;
  signal_R4AB15LDU.error = var843.error;
  signal_R4AB14LDU.b = var845.b;
  signal_R4AB14LDU.error = var845.error;
  signal_R4AB13LDU.b = var813.b;
  signal_R4AB13LDU.error = var813.error;
  signal_R4AB12LDU.b = var818.b;
  signal_R4AB12LDU.error = var818.error;
  signal_R4AB11LDU.b = var850.b;
  signal_R4AB11LDU.error = var850.error;
  signal_R4AB10LDU.b = var815.b;
  signal_R4AB10LDU.error = var815.error;
  signal_R4AB09LDU.b = var848.b;
  signal_R4AB09LDU.error = var848.error;
  signal_R4AB08LDU.b = var847.b;
  signal_R4AB08LDU.error = var847.error;
  signal_R4AB07LDU.b = var851.b;
  signal_R4AB07LDU.error = var851.error;
  signal_R4AB06LDU.b = var1560.b;
  signal_R4AB06LDU.error = var1560.error;
  signal_R4AB05LDU.b = var1559.b;
  signal_R4AB05LDU.error = var1559.error;
  signal_R4AB04LDU.b = var1561.b;
  signal_R4AB04LDU.error = var1561.error;
  signal_R4AB03LDU.b = var852.b;
  signal_R4AB03LDU.error = var852.error;
  signal_R4AZ03LDU.b = var1558.b;
  signal_R4AZ03LDU.error = var1558.error;
  signal_R4AB02LDU.b = var855.b;
  signal_R4AB02LDU.error = var855.error;
  signal_R4AB01LDU.b = var856.b;
  signal_R4AB01LDU.error = var856.error;
  signal_B6AB04LDU.b = var1569.b;
  signal_B6AB04LDU.error = var1569.error;
  signal_A6AB04LDU.b = var1578.b;
  signal_A6AB04LDU.error = var1578.error;
  signal_B6AB02LDU.b = var1568.b;
  signal_B6AB02LDU.error = var1568.error;
  signal_B6AB01LDU.b = var1570.b;
  signal_B6AB01LDU.error = var1570.error;
  signal_B6AZ03LDU.b = var1567.b;
  signal_B6AZ03LDU.error = var1567.error;
  signal_A6AB02LDU.b = var1577.b;
  signal_A6AB02LDU.error = var1577.error;
  signal_A6AB01LDU.b = var1579.b;
  signal_A6AB01LDU.error = var1579.error;
  signal_A6AZ03LDU.b = var1576.b;
  signal_A6AZ03LDU.error = var1576.error;
  signal_B6AD20LDU.b = var1572.b;
  signal_B6AD20LDU.error = var1572.error;
  signal_B6AD10LDU.b = var1571.b;
  signal_B6AD10LDU.error = var1571.error;
  signal_A6AD20LDU.b = var1581.b;
  signal_A6AD20LDU.error = var1581.error;
  signal_A6AD10LDU.b = var1580.b;
  signal_A6AD10LDU.error = var1580.error;
  signal_R0ES01LDU.b = var860.b;
  signal_R0ES01LDU.error = var860.error;

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
  S_noto_2095_1.x = &signal_B3IS22LDU;
  S_noto_2121_1.x = &signal_A3IS22LDU;
  S_and3_2079_1.x3 = &signal_B3IS22LDU;
  S_and3_2105_1.x3 = &signal_A3IS22LDU;
  S_noto_2092_1.x = &signal_syn_B3VP52LDU;
  S_noto_2118_1.x = &signal_syn_A3VP52LDU;
  S_noto_1638_1.x = &signal_B2IS21LDU;
  S_noto_1632_1.x = &signal_A2IS21LDU;
  S_and2_2042_1.x1 = &signal_syn_B3VP52LDU;
  S_or5_2044_1.x5 = &signal_syn_A3VP52LDU;
  S_and2_2019_1.x1 = &signal_syn_A3VP52LDU;
  S_nocnm_1683_1.Pv = &signal_R5IS21LDU;
  S_nocnm_1683_1.Zv = &signal_R5IS11LDU;
  S_nocnm_1680_1.Pv = &signal_R3IS11LDU;
  S_nocnm_1680_1.Zv = &signal_R3IS21LDU;
  S_or5_1939_1.x3 = &signal_C2MD31LP1;
  S_or4_1915_1.x1 = &signal_C1MD31LP2;
  S_or4_1915_1.x2 = &signal_C1MD31LP1;
  S_and3_403_1.x1 = &signal_B8IS22LDU;
  S_and3_403_1.x2 = &signal_B8IS21LDU;
  S_or2_542_1.x1 = &signal_B1VP41LZ2;
  S_or2_542_1.x2 = &signal_B1VP41LZ1;
  S_or2_225_1.x1 = &signal_A1VP41LZ2;
  S_or2_225_1.x2 = &signal_A1VP41LZ1;
  S_or2_1102_1.x1 = &signal_B8IS22LDU;
  S_or2_1102_1.x2 = &signal_B8IS21LDU;
  S_or2_1097_1.x1 = &signal_B8IS11LDU;
  S_or2_1097_1.x2 = &signal_B8IS12LDU;
  S_or2_344_1.x1 = &signal_R4IS11LDU;
  S_or2_344_1.x2 = &signal_R4IS12LDU;
  S_or2_361_1.x1 = &signal_R4IS21LDU;
  S_or2_361_1.x2 = &signal_R4IS22LDU;
  S_or2_1056_1.x2 = &signal_R0MD34LP1;
  S_or2_1059_1.x2 = &signal_R0MD34LP1;
  S_or2_1062_1.x2 = &signal_R0MD34LP1;
  S_or2_1065_1.x2 = &signal_R0MD34LP1;
  S_and2_2172_1.x2 = &signal_R0MW17LP1;
  S_rs_2176_1.s = &signal_R0MW17LP1;
  S_abs_subf_2196_1.x1 = &signal_B3MC01RP1;
  S_abs_subf_2196_1.x2 = &signal_A3MC01RP1;
  S_irm_2131_1.kz = &signal_B3MC01RP1;
  S_ml_1500_1.x2 = &signal_B8MC01RP2;
  S_bol_1506_1.x1 = &signal_B8MC01RP2;
  S_bol_1517_1.x2 = &signal_B8MC01RP2;
  S_ml_1521_1.x2 = &signal_B3MC01RP1;
  S_bol_1523_1.x1 = &signal_B3MC01RP1;
  S_bol_1533_1.x2 = &signal_B3MC01RP1;
  S_ml_1499_1.x2 = &signal_A3MC01RP1;
  S_bol_1504_1.x1 = &signal_A3MC01RP1;
  S_bol_1515_1.x2 = &signal_A3MC01RP1;
  S_ml_1519_1.x2 = &signal_B1MC01RP1;
  S_bol_1525_1.x1 = &signal_B1MC01RP1;
  S_bol_1532_1.x2 = &signal_B1MC01RP1;
  S_ml_1497_1.x2 = &signal_A1MC01RP1;
  S_bol_1503_1.x1 = &signal_A1MC01RP1;
  S_bol_1513_1.x2 = &signal_A1MC01RP1;
  S_and2_101_1.x1 = &signal_R0MD11LP1;
  S_and2_104_1.x1 = &signal_R0MD11LP1;
  S_and2_1805_1.x2 = &signal_B7AS31LDU;
  S_ovbs_1399_1.x = &signal_R0MD31LP1;
  S_ovbs_110_1.x = &signal_R0MD31LP1;
  S_ovbs_117_1.x = &signal_R0MD32LP1;
  S_ovbs_76_1.x = &signal_R0MW13LP2;
  S_or2_229_1.x1 = &signal_A1VN71LZ1;
  S_or2_229_1.x2 = &signal_A1VN71LZ2;
  S_or5_144_1.x1 = &signal_B1IS21LDU;
  S_or5_144_1.x2 = &signal_B3IS21LDU;
  S_or5_144_1.x3 = &signal_B2IS21LDU;
  S_ma_1440_1.r = &signal_R0MW12IP2;
  S_and4_1864_1.x3 = &signal_B2IS12LDU;
  S_and4_1858_1.x2 = &signal_A2IS12LDU;
  S_and2_1888_1.x2 = &signal_A2IS12LDU;
  S_and2_1905_1.x2 = &signal_B2IS12LDU;
  S_and2_1804_1.x2 = &signal_A7AS31LDU;
  S_or2_1791_1.x1 = &signal_B0VT71LZ1;
  S_or2_1791_1.x2 = &signal_B0VT71LZ2;
  S_or2_1775_1.x1 = &signal_A0VT71LZ1;
  S_or2_1775_1.x2 = &signal_A0VT71LZ2;
  S_or2_1800_1.x1 = &signal_R0VP73LZ2;
  S_or2_1800_1.x2 = &signal_R0VP73LZ1;
  S_or2_1545_1.x1 = &signal_B4IS11LDU;
  S_or2_1545_1.x2 = &signal_A4IS11LDU;
  S_and2_1535_1.x1 = &signal_R3IS21LDU;
  S_or2_2057_1.x2 = &signal_R0MD34LP1;
  S_or3_1486_1.x1 = &signal_A3VZ13LZ2;
  S_or3_1486_1.x2 = &signal_A3VZ13LZ1;
  S_or3_1480_1.x1 = &signal_R0AD14LZ1;
  S_or3_1480_1.x2 = &signal_R0AD14LZ2;
  S_or3_1425_1.x1 = &signal_A3VZ15LZ1;
  S_or3_1425_1.x2 = &signal_A3VZ15LZ2;
  S_or5_1374_1.x5 = &signal_R0MD34LP1;
  S_and2_1375_1.x1 = &signal_R0MD11LP2;
  S_or4_983_1.x1 = &signal_R0MD31LP1;
  S_or2_1218_1.x1 = &signal_A2MD12LP1;
  S_and2_1206_1.x1 = &signal_A2MD11LP1;
  S_or2_1200_1.x2 = &signal_B2MD12LP1;
  S_and2_1194_1.x1 = &signal_B2MD11LP1;
  S_and2_1232_1.x1 = &signal_R3IS21LDU;
  S_or2_1235_1.x1 = &signal_A4IS11LDU;
  S_or2_1235_1.x2 = &signal_B4IS11LDU;
  S_or2_1317_1.x2 = &signal_B3MD12LP1;
  S_and2_1306_1.x1 = &signal_B3MD11LP1;
  S_or2_1325_1.x1 = &signal_B4IS11LDU;
  S_or2_1325_1.x2 = &signal_A4IS11LDU;
  S_and2_1323_1.x1 = &signal_R3IS21LDU;
  S_or2_928_1.x1 = &signal_B4IS11LDU;
  S_or2_928_1.x2 = &signal_A4IS11LDU;
  S_and2_926_1.x1 = &signal_R3IS21LDU;
  S_or2_920_1.x2 = &signal_A3MD12LP1;
  S_and2_909_1.x1 = &signal_A3MD11LP1;
  S_and2_830_1.x1 = &signal_R3IS21LDU;
  S_or2_834_1.x1 = &signal_B4IS11LDU;
  S_or2_834_1.x2 = &signal_A4IS11LDU;
  S_or2_205_1.x1 = &signal_B4IS11LDU;
  S_or2_205_1.x2 = &signal_A4IS11LDU;
  S_and2_203_1.x1 = &signal_R3IS21LDU;
  S_and2_171_1.x1 = &signal_A1MD11LP1;
  S_or2_177_1.x1 = &signal_A1MD12LP1;
  S_or2_522_1.x1 = &signal_B4IS11LDU;
  S_or2_522_1.x2 = &signal_A4IS11LDU;
  S_or2_499_1.x1 = &signal_B1MD12LP1;
  S_and2_493_1.x1 = &signal_B1MD11LP1;
  S_and2_520_1.x2 = &signal_R3IS21LDU;
  S_and3_436_1.x3 = &signal_R0MD33LP1;
  S_and3_437_1.x3 = &signal_R0MD33LP1;
  S_or2_341_1.x1 = &signal_B4IS21LDU;
  S_or2_341_1.x2 = &signal_A4IS21LDU;
  S_or2_336_1.x1 = &signal_A2IS21LDU;
  S_or2_336_1.x2 = &signal_B2IS21LDU;
  S_or4_327_1.x3 = &signal_R0MD31LP1;
  S_or2_318_1.x1 = &signal_R0MD34LP1;
  S_and3_592_1.x3 = &signal_B2IS12LDU;
  S_or2_634_1.x1 = &signal_A2IS12LDU;
  S_or2_634_1.x2 = &signal_B2IS12LDU;
  S_and3_602_1.x1 = &signal_A2IS12LDU;
  S_and2_630_1.x2 = &signal_R0MD33LP1;
  S_and4_599_1.x4 = &signal_A2IS12LDU;
  S_and4_589_1.x4 = &signal_B2IS12LDU;
  S_or2_258_1.x1 = &signal_R0MD34LP1;
  S_or4_275_1.x2 = &signal_R0MD31LP1;
  S_and3_254_1.x1 = &signal_R0MD33LP1;
  S_or2_1081_1.x1 = &signal_B4IS11LDU;
  S_or2_1081_1.x2 = &signal_A4IS11LDU;
  S_and2_1072_1.x2 = &signal_R3IS21LDU;
  S_or2_1052_1.x1 = &signal_R0MD31LP1;
  S_or2_1160_1.x2 = &signal_R0MD34LP1;
  S_or2_654_1.x1 = &signal_B5IS11LDU;
  S_or2_654_1.x2 = &signal_A5IS11LDU;
  S_or2_652_1.x1 = &signal_B6IS11LDU;
  S_or2_652_1.x2 = &signal_A6IS11LDU;
  S_or2_650_1.x1 = &signal_A4IS11LDU;
  S_or2_650_1.x2 = &signal_B4IS11LDU;
  S_or3_725_1.x1 = &signal_R4MD11LP2;
  S_or4_724_1.x2 = &signal_R4MD21LP2;
  S_or3_715_1.x1 = &signal_R4MD31LP2;
  S_and2_664_1.x1 = &signal_R4MD11LP2;
  S_and3_693_1.x3 = &signal_R4MD21LP2;
  S_and2_698_1.x1 = &signal_R5IS11LDU;
  S_and3_696_1.x2 = &signal_R3IS21LDU;
  S_and2_697_1.x1 = &signal_R6IS21LDU;
  S_or2_695_1.x1 = &signal_B8IS22LDU;
  S_or2_695_1.x2 = &signal_A8IS22LDU;
  S_or4_682_1.x1 = &signal_A0VN71LZ1;
  S_or4_682_1.x2 = &signal_B0VN71LZ1;
  S_or4_682_1.x3 = &signal_B0VN71LZ2;
  S_or4_682_1.x4 = &signal_A0VN71LZ2;
  S_or3_668_1.x1 = &signal_R0NE01LDU;
  S_or3_668_1.x2 = &signal_R0NE02LDU;
  S_or3_668_1.x3 = &signal_R0NE08LDU;
  S_or2_680_1.x1 = &signal_R1IS21LDU;
  S_or2_680_1.x2 = &signal_R2IS21LDU;
  S_or2_125_1.x1 = &signal_R0VZ71LZ1;
  S_or2_125_1.x2 = &signal_R0VZ71LZ2;
  S_or2_48_1.x1 = &signal_A4IS21LDU;
  S_or2_48_1.x2 = &signal_B4IS21LDU;
  S_and2_402_1.x1 = &signal_A8IS22LDU;
  S_and2_422_1.x1 = &signal_B8IS22LDU;
  S_and2_421_1.x1 = &signal_A8IS22LDU;
  S_and2_420_1.x1 = &signal_R5IS11LDU;
  S_and2_401_1.x1 = &signal_R5IS11LDU;
  S_ma_83_1.r = &signal_R0MW15IP1;
  S_noto_1902_1.x = &signal_B2IS11LDU;
  S_noto_1900_1.x = &signal_A2IS11LDU;
  S_noto_1909_1.x = &signal_B2IS11LDU;
  S_noto_1884_1.x = &signal_A2IS11LDU;
  S_noto_978_1.x = &signal_R2IS21LDU;
  S_noto_972_1.x = &signal_R1IS21LDU;
  S_noto_261_1.x = &signal_R0MD33LP1;
  S_noto_271_1.x = &signal_R2IS21LDU;
  S_noto_265_1.x = &signal_R1IS21LDU;
  S_noto_256_1.x = &signal_R1IS11LDU;
  S_noto_253_1.x = &signal_R2IS11LDU;
  S_provsbr_1383_1.kvit = &signal_R0MD34LP1;
  S_noto_575_1.x = &signal_A2IS21LDU;
  S_noto_577_1.x = &signal_B2IS21LDU;
  S_noto_25_1.x = &signal_B2IS21LDU;
  S_noto_24_1.x = &signal_B1IS21LDU;
  S_noto_23_1.x = &signal_A1IS21LDU;
  S_noto_22_1.x = &signal_A2IS21LDU;
  S_newstage_587_1.fin1 = &signal_A2IS12LDU;
  S_newstage_587_1.fin2 = &signal_B2IS12LDU;
  S_noto_576_1.x = &signal_B2IS12LDU;
  S_noto_574_1.x = &signal_A2IS12LDU;
  S_noto_1312_1.x = &signal_B3MD12LP1;
  S_noto_1785_1.x = &signal_B3IS11LDU;
  S_noto_1759_1.x = &signal_A3IS11LDU;
  S_noto_1799_1.x = &signal_B3IS22LDU;
  S_noto_1781_1.x = &signal_A3IS22LDU;
  S_noto_1212_1.x = &signal_A2MD12LP1;
  S_noto_1196_1.x = &signal_B2MD12LP1;
  S_noto_497_1.x = &signal_B1MD12LP1;
  S_equz_p_1765_1.x = &signal_R0MW14IP2;
  S_equz_p_1764_1.x = &signal_R0MW14IP2;
  S_equz_p_1763_1.x = &signal_R0MW14IP2;
  S_equz_p_1761_1.x = &signal_R0MW14IP2;
  S_equz_p_1762_1.x = &signal_R0MW14IP2;
  S_noto_1818_1.x = &signal_B3IS11LDU;
  S_noto_1813_1.x = &signal_A3IS11LDU;
  S_noto_1855_1.x = &signal_B2IS11LDU;
  S_noto_1863_1.x = &signal_A2IS11LDU;
  S_equz_p_98_1.x = &signal_R0MW16IP1;
  S_noto_173_1.x = &signal_A1MD12LP1;
  S_equz_p_97_1.x = &signal_R0MW16IP1;
  S_equz_p_96_1.x = &signal_R0MW16IP1;
  S_noto_915_1.x = &signal_A3MD12LP1;
  S_equz_p_95_1.x = &signal_R0MW16IP1;
  S_equz_p_94_1.x = &signal_R0MW16IP1;
  S_equz_p_93_1.x = &signal_R0MW16IP1;
  S_noto_1722_1.x = &signal_B3IS22LDU;
  S_noto_1721_1.x = &signal_A3IS22LDU;
  S_noto_1720_1.x = &signal_B2IS12LDU;
  S_noto_1719_1.x = &signal_A2IS12LDU;
  S_noto_1718_1.x = &signal_B1IS12LDU;
  S_noto_1717_1.x = &signal_A1IS12LDU;
  S_noto_1747_1.x = &signal_B3IS21LDU;
  S_noto_1741_1.x = &signal_B2IS21LDU;
  S_noto_1746_1.x = &signal_A3IS21LDU;
  S_noto_1744_1.x = &signal_B4IS21LDU;
  S_noto_1745_1.x = &signal_A4IS21LDU;
  S_noto_1739_1.x = &signal_B1IS21LDU;
  S_noto_1740_1.x = &signal_A2IS21LDU;
  S_noto_1738_1.x = &signal_A1IS21LDU;
  S_samhd_2061_1.Pkv = &signal_B9IS11LDU;
  S_samhd_2061_1.Pkav = &signal_B9IS11LDU;
  S_samhd_2061_1.Zkv = &signal_B9IS21LDU;
  S_samhd_2061_1.Zkav = &signal_B9IS21LDU;
  S_samhd_2055_1.Pkv = &signal_A9IS11LDU;
  S_samhd_2055_1.Pkav = &signal_A9IS11LDU;
  S_samhd_2055_1.Zkv = &signal_A9IS21LDU;
  S_samhd_2055_1.Zkav = &signal_A9IS21LDU;
  S_maz_298_1.r = &signal_R0MW12IP1;
  S_maz_289_1.r = &signal_R0MW12IP1;
  S_equz_p_37_1.x = &signal_R0MW13IP1;
  S_equz_p_41_1.x = &signal_R0MW13IP1;
  S_equz_p_32_1.x = &signal_R0MW13IP1;
  S_noto_1335_1.x = &signal_R8IS11LDU;
  S_cnshd_1282_1.KvitSam = &signal_R0MD34LP1;
  S_fnapb_1310_1.KvitSam = &signal_R0MD34LP1;
  S_noto_938_1.x = &signal_R8IS11LDU;
  S_cnshd_880_1.KvitSam = &signal_R0MD34LP1;
  S_fnapb_913_1.KvitSam = &signal_R0MD34LP1;
  S_noto_530_1.x = &signal_R8IS11LDU;
  S_cnshd_484_1.KvitSam = &signal_R0MD34LP1;
  S_fnapb_511_1.KvitSam = &signal_R0MD34LP1;
  S_noto_631_1.x = &signal_R0MD33LP1;
  S_noto_213_1.x = &signal_R8IS11LDU;
  S_cnshd_163_1.KvitSam = &signal_R0MD34LP1;
  S_fnapb_192_1.KvitSam = &signal_R0MD34LP1;
  S_samhd_455_1.KvitSam = &signal_R0MD34LP1;
  S_samhd_455_1.FDvUp = &signal_R2VS12LDU;
  S_samhd_455_1.FDvDw = &signal_R2VS22LDU;
  S_samhd_455_1.Pkv = &signal_R2IS11LDU;
  S_samhd_455_1.Pkav = &signal_R2IS11LDU;
  S_samhd_455_1.Zkv = &signal_R2IS21LDU;
  S_samhd_455_1.Zkav = &signal_R2IS21LDU;
  S_samhd_449_1.KvitSam = &signal_R0MD34LP1;
  S_samhd_449_1.FDvUp = &signal_R1VS12LDU;
  S_samhd_449_1.FDvDw = &signal_R1VS22LDU;
  S_samhd_449_1.Pkv = &signal_R1IS11LDU;
  S_samhd_449_1.Pkav = &signal_R1IS11LDU;
  S_samhd_449_1.Zkv = &signal_R1IS21LDU;
  S_samhd_449_1.Zkav = &signal_R1IS21LDU;
  S_noto_843_1.x = &signal_R8IS11LDU;
  S_cnshd_800_1.KvitSam = &signal_R0MD34LP1;
  S_fnapb_820_1.KvitSam = &signal_R0MD34LP1;
  S_cnshd_1564_1.KvitSam = &signal_R0MD34LP1;
  S_cnshd_1100_1.KvitSam = &signal_R0MD34LP1;
  S_noto_1245_1.x = &signal_R8IS11LDU;
  S_cnshd_1185_1.KvitSam = &signal_R0MD34LP1;
  S_fnapb_1219_1.KvitSam = &signal_R0MD34LP1;
  S_noto_1549_1.x = &signal_R8IS11LDU;
  S_samhd_1567_1.KvitSam = &signal_R0MD34LP1;
  S_samhd_1567_1.Pkv = &signal_A8IS12LDU;
  S_samhd_1567_1.Pkav = &signal_A8IS12LDU;
  S_samhd_1567_1.Zkv = &signal_A8IS22LDU;
  S_samhd_1567_1.Zkav = &signal_A8IS22LDU;
  S_fnapb_1584_1.KvitSam = &signal_R0MD34LP1;
  S_noto_1085_1.x = &signal_R8IS11LDU;
  S_samhd_1106_1.KvitSam = &signal_R0MD34LP1;
  S_fnapb_1124_1.KvitSam = &signal_R0MD34LP1;
  S_noto_708_1.x = &signal_A5IS21LDU;
  S_noto_411_1.x = &signal_R8IS11LDU;
  S_noto_149_1.x = &signal_B2IS12LDU;
  S_noto_138_1.x = &signal_A2IS12LDU;
  S_noto_139_1.x = &signal_B1IS12LDU;
  S_noto_147_1.x = &signal_A1IS12LDU;
  S_samhd_1161_1.Pkv = &signal_B4IS11LDU;
  S_samhd_1161_1.Pkav = &signal_B4IS11LDU;
  S_samhd_1161_1.Zkv = &signal_B4IS21LDU;
  S_samhd_1161_1.Zkav = &signal_B4IS21LDU;
  S_samhd_1151_1.Pkv = &signal_A4IS11LDU;
  S_samhd_1151_1.Pkav = &signal_A4IS11LDU;
  S_samhd_1151_1.Zkv = &signal_A4IS21LDU;
  S_samhd_1151_1.Zkav = &signal_A4IS21LDU;
  S_samhd_774_1.KvitSam = &signal_R0MD34LP1;
  S_samhd_774_1.FDvUp = &signal_B5VS12LDU;
  S_samhd_774_1.FDvDw = &signal_B5VS22LDU;
  S_samhd_774_1.Pkv = &signal_B5IS11LDU;
  S_samhd_774_1.Pkav = &signal_B5IS11LDU;
  S_samhd_774_1.Zkv = &signal_B5IS21LDU;
  S_samhd_774_1.Zkav = &signal_B5IS21LDU;
  S_samhd_770_1.KvitSam = &signal_R0MD34LP1;
  S_samhd_770_1.FDvUp = &signal_A5VS12LDU;
  S_samhd_770_1.FDvDw = &signal_A5VS22LDU;
  S_samhd_770_1.Pkv = &signal_A5IS11LDU;
  S_samhd_770_1.Pkav = &signal_A5IS11LDU;
  S_samhd_770_1.Zkv = &signal_A5IS21LDU;
  S_samhd_770_1.Zkav = &signal_A5IS21LDU;
  S_samhd_354_1.KvitSam = &signal_R0MD34LP1;
  S_samhd_354_1.FDvUp = &signal_R4VS12LDU;
  S_samhd_354_1.FDvDw = &signal_R4VS22LDU;
  S_samhd_354_1.Pkv = &signal_R4IS11LDU;
  S_samhd_354_1.Pkav = &signal_R4IS12LDU;
  S_samhd_354_1.Zkv = &signal_R4IS21LDU;
  S_samhd_354_1.Zkav = &signal_R4IS22LDU;
  S_noto_666_1.x = &signal_R8IS11LDU;
  S_samhd_383_1.KvitSam = &signal_R0MD34LP1;
  S_samhd_383_1.FDvUp = &signal_B6VS12LDU;
  S_samhd_383_1.FDvDw = &signal_B6VS22LDU;
  S_samhd_383_1.Pkv = &signal_B6IS11LDU;
  S_samhd_383_1.Pkav = &signal_B6IS11LDU;
  S_samhd_383_1.Zkv = &signal_B6IS21LDU;
  S_samhd_383_1.Zkav = &signal_B6IS21LDU;
  S_samhd_377_1.KvitSam = &signal_R0MD34LP1;
  S_samhd_377_1.FDvUp = &signal_A6VS12LDU;
  S_samhd_377_1.FDvDw = &signal_A6VS22LDU;
  S_samhd_377_1.Pkv = &signal_A6IS11LDU;
  S_samhd_377_1.Pkav = &signal_A6IS11LDU;
  S_samhd_377_1.Zkv = &signal_A6IS21LDU;
  S_samhd_377_1.Zkav = &signal_A6IS21LDU;
  S_rs_726_1.s = &signal_R4MD21LP2;
  S_rs_723_1.s = &signal_R4MD11LP2;
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
  array_m2165_x_1[0] = &signal_B0CT01IZ1;
  array_m2165_x_1[1] = &signal_A0CT01IZ1;
  array_m2165_x_1[2] = &signal_B0CT01IZ2;
  array_m2165_x_1[3] = &signal_A0CT01IZ2;
  array_m2187_x_1[0] = &signal_R0VN09RZ1;
  array_m2187_x_1[1] = &signal_R0VN09RZ2;
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
  array_m1049_x_1[0] = &signal_R0VN11RZ2;
  array_m1049_x_1[1] = &signal_R0VN11RZ1;
  array_m141_x_1[0] = &signal_A1IS21LDU;
  array_m141_x_1[1] = &signal_A3IS21LDU;
  array_m141_x_1[2] = &signal_A2IS21LDU;
  array_m585_x_1[0] = &signal_R0MD31LP1;
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
  S_rs_2088_1.q0 = &internal1_m2088_q0;
  S_rs_2072_1.q0 = &internal1_m2072_q0;
  S_rs_2114_1.q0 = &internal1_m2114_q0;
  S_rs_2098_1.q0 = &internal1_m2098_q0;
  S_rs_2091_1.q0 = &internal1_m2091_q0;
  S_rs_2074_1.q0 = &internal1_m2074_q0;
  S_rs_2090_1.q0 = &internal1_m2090_q0;
  S_rs_2073_1.q0 = &internal1_m2073_q0;
  S_rs_2071_1.q0 = &internal1_m2071_q0;
  S_rs_2070_1.q0 = &internal1_m2070_q0;
  S_rs_2084_1.q0 = &internal1_m2084_q0;
  S_rs_2082_1.q0 = &internal1_m2082_q0;
  S_rs_2089_1.q0 = &internal1_m2089_q0;
  S_rs_2086_1.q0 = &internal1_m2086_q0;
  S_rs_2117_1.q0 = &internal1_m2117_q0;
  S_rs_2100_1.q0 = &internal1_m2100_q0;
  S_rs_2116_1.q0 = &internal1_m2116_q0;
  S_rs_2099_1.q0 = &internal1_m2099_q0;
  S_rs_2097_1.q0 = &internal1_m2097_q0;
  S_rs_2096_1.q0 = &internal1_m2096_q0;
  S_rs_2110_1.q0 = &internal1_m2110_q0;
  S_rs_2108_1.q0 = &internal1_m2108_q0;
  S_ovbs_1991_1.tx = &internal1_m1991_tx;
  S_ovbs_1970_1.tx = &internal1_m1970_tx;
  S_nocnm_1683_1.Pv0 = &internal1_m1683_Pv0;
  S_nocnm_1683_1.Zv0 = &internal1_m1683_Zv0;
  S_nocnm_1683_1.MyFirstEnterFlag = &internal1_m1683_MyFirstEnterFlag;
  S_nocnm_1683_1.FirstEnterFlag = &bFirstEnterFlag;
  S_nocnm_1680_1.Pv0 = &internal1_m1680_Pv0;
  S_nocnm_1680_1.Zv0 = &internal1_m1680_Zv0;
  S_nocnm_1680_1.MyFirstEnterFlag = &internal1_m1680_MyFirstEnterFlag;
  S_nocnm_1680_1.FirstEnterFlag = &bFirstEnterFlag;
  S_zzfs_2133_1.tx = &internal1_m2133_tx;
  S_zzfs_2133_1.y0 = &internal1_m2133_y0;
  S_zpfs_2137_1.tx = &internal1_m2137_tx;
  S_zpfs_2137_1.y0 = &internal1_m2137_y0;
  S_zpfs_2136_1.tx = &internal1_m2136_tx;
  S_zpfs_2136_1.y0 = &internal1_m2136_y0;
  S_ovbs_2173_1.tx = &internal1_m2173_tx;
  S_zpfs_2171_1.tx = &internal1_m2171_tx;
  S_zpfs_2171_1.y0 = &internal1_m2171_y0;
  S_rs_2176_1.q0 = &internal1_m2176_q0;
  S_rs_2143_1.q0 = &internal1_m2143_q0;
  S_ovbs_2151_1.tx = &internal1_m2151_tx;
  S_rs_2149_1.q0 = &internal1_m2149_q0;
  S_zpfs_1985_1.tx = &internal1_m1985_tx;
  S_zpfs_1985_1.y0 = &internal1_m1985_y0;
  S_zpfs_1977_1.tx = &internal1_m1977_tx;
  S_zpfs_1977_1.y0 = &internal1_m1977_y0;
  S_rs_1676_1.q0 = &internal1_m1676_q0;
  S_rs_1674_1.q0 = &internal1_m1674_q0;
  S_rs_1673_1.q0 = &internal1_m1673_q0;
  S_rs_1704_1.q0 = &internal1_m1704_q0;
  S_zpfs_733_1.tx = &internal1_m733_tx;
  S_zpfs_733_1.y0 = &internal1_m733_y0;
  S_ovbs_1981_1.tx = &internal1_m1981_tx;
  S_rs_1984_1.q0 = &internal1_m1984_q0;
  S_rs_1976_1.q0 = &internal1_m1976_q0;
  S_ovbs_1946_1.tx = &internal1_m1946_tx;
  S_ovbs_1957_1.tx = &internal1_m1957_tx;
  S_ovbs_1943_1.tx = &internal1_m1943_tx;
  S_rs_1949_1.q0 = &internal1_m1949_q0;
  S_rs_1961_1.q0 = &internal1_m1961_q0;
  S_ovbs_1919_1.tx = &internal1_m1919_tx;
  S_ovbs_51_1.tx = &internal1_m51_tx;
  S_ovbs_332_1.tx = &internal1_m332_tx;
  S_ovbs_288_1.tx = &internal1_m288_tx;
  S_ovbs_734_1.tx = &internal1_m734_tx;
  S_ovbs_1399_1.tx = &internal1_m1399_tx;
  S_ovbs_110_1.tx = &internal1_m110_tx;
  S_ovbs_112_1.tx = &internal1_m112_tx;
  S_ovbs_117_1.tx = &internal1_m117_tx;
  S_ovbs_21_1.tx = &internal1_m21_tx;
  S_ovbs_13_1.tx = &internal1_m13_tx;
  S_ovbs_1928_1.tx = &internal1_m1928_tx;
  S_ovbs_1916_1.tx = &internal1_m1916_tx;
  S_ovbs_2024_1.tx = &internal1_m2024_tx;
  S_ovbs_2028_1.tx = &internal1_m2028_tx;
  S_ovbs_1841_1.tx = &internal1_m1841_tx;
  S_ovbs_76_1.tx = &internal1_m76_tx;
  S_zpfs_301_1.tx = &internal1_m301_tx;
  S_zpfs_301_1.y0 = &internal1_m301_y0;
  S_zpfs_1835_1.tx = &internal1_m1835_tx;
  S_zpfs_1835_1.y0 = &internal1_m1835_y0;
  S_zpfs_1833_1.tx = &internal1_m1833_tx;
  S_zpfs_1833_1.y0 = &internal1_m1833_y0;
  S_zpfs_1822_1.tx = &internal1_m1822_tx;
  S_zpfs_1822_1.y0 = &internal1_m1822_y0;
  S_rsfn_1842_1.q0 = &internal1_m1842_q0;
  S_rsfn_1419_1.q0 = &internal1_m1419_q0;
  S_rsfn_1457_1.q0 = &internal1_m1457_q0;
  S_rsfn_1460_1.q0 = &internal1_m1460_q0;
  S_rsfn_1881_1.q0 = &internal1_m1881_q0;
  S_zpfs_1859_1.tx = &internal1_m1859_tx;
  S_zpfs_1859_1.y0 = &internal1_m1859_y0;
  S_zpfs_1874_1.tx = &internal1_m1874_tx;
  S_zpfs_1874_1.y0 = &internal1_m1874_y0;
  S_zpfs_1871_1.tx = &internal1_m1871_tx;
  S_zpfs_1871_1.y0 = &internal1_m1871_y0;
  S_zpfs_2008_1.tx = &internal1_m2008_tx;
  S_zpfs_2008_1.y0 = &internal1_m2008_y0;
  S_zpfs_2018_1.tx = &internal1_m2018_tx;
  S_zpfs_2018_1.y0 = &internal1_m2018_y0;
  S_zpfs_1772_1.tx = &internal1_m1772_tx;
  S_zpfs_1772_1.y0 = &internal1_m1772_y0;
  S_zpfs_1771_1.tx = &internal1_m1771_tx;
  S_zpfs_1771_1.y0 = &internal1_m1771_y0;
  S_zpfs_1770_1.tx = &internal1_m1770_tx;
  S_zpfs_1770_1.y0 = &internal1_m1770_y0;
  S_zpfs_1769_1.tx = &internal1_m1769_tx;
  S_zpfs_1769_1.y0 = &internal1_m1769_y0;
  S_zpfs_1471_1.tx = &internal1_m1471_tx;
  S_zpfs_1471_1.y0 = &internal1_m1471_y0;
  S_zpfs_1465_1.tx = &internal1_m1465_tx;
  S_zpfs_1465_1.y0 = &internal1_m1465_y0;
  S_zpfs_1415_1.tx = &internal1_m1415_tx;
  S_zpfs_1415_1.y0 = &internal1_m1415_y0;
  S_zpfs_817_1.tx = &internal1_m817_tx;
  S_zpfs_817_1.y0 = &internal1_m817_y0;
  S_zpfs_814_1.tx = &internal1_m814_tx;
  S_zpfs_814_1.y0 = &internal1_m814_y0;
  S_zpfs_821_1.tx = &internal1_m821_tx;
  S_zpfs_821_1.y0 = &internal1_m821_y0;
  S_zpfs_182_1.tx = &internal1_m182_tx;
  S_zpfs_182_1.y0 = &internal1_m182_y0;
  S_zpfs_187_1.tx = &internal1_m187_tx;
  S_zpfs_187_1.y0 = &internal1_m187_y0;
  S_zpfs_193_1.tx = &internal1_m193_tx;
  S_zpfs_193_1.y0 = &internal1_m193_y0;
  S_zpfs_512_1.tx = &internal1_m512_tx;
  S_zpfs_512_1.y0 = &internal1_m512_y0;
  S_ovbs_2056_1.tx = &internal1_m2056_tx;
  S_ovbs_1159_1.tx = &internal1_m1159_tx;
  S_zpfs_1585_1.tx = &internal1_m1585_tx;
  S_zpfs_1585_1.y0 = &internal1_m1585_y0;
  S_zpfs_1125_1.tx = &internal1_m1125_tx;
  S_zpfs_1125_1.y0 = &internal1_m1125_y0;
  S_zpfs_1311_1.tx = &internal1_m1311_tx;
  S_zpfs_1311_1.y0 = &internal1_m1311_y0;
  S_zpfs_914_1.tx = &internal1_m914_tx;
  S_zpfs_914_1.y0 = &internal1_m914_y0;
  S_zpfs_1220_1.tx = &internal1_m1220_tx;
  S_zpfs_1220_1.y0 = &internal1_m1220_y0;
  S_rs_1066_1.q0 = &internal1_m1066_q0;
  S_rs_1064_1.q0 = &internal1_m1064_q0;
  S_rs_1063_1.q0 = &internal1_m1063_q0;
  S_rs_1061_1.q0 = &internal1_m1061_q0;
  S_rs_1060_1.q0 = &internal1_m1060_q0;
  S_rs_1058_1.q0 = &internal1_m1058_q0;
  S_rs_1057_1.q0 = &internal1_m1057_q0;
  S_rs_1055_1.q0 = &internal1_m1055_q0;
  S_rs_1054_1.q0 = &internal1_m1054_q0;
  S_swtakt_52_1.x0 = &internal1_m52_x0;
  S_rs_974_1.q0 = &internal1_m974_q0;
  S_swtakt_1408_1.x0 = &internal1_m1408_x0;
  S_swtakt_1452_1.x0 = &internal1_m1452_x0;
  S_swtakt_1448_1.x0 = &internal1_m1448_x0;
  S_swtakt_1850_1.x0 = &internal1_m1850_x0;
  S_swtakt_1815_1.x0 = &internal1_m1815_x0;
  S_rs_1013_1.q0 = &internal1_m1013_q0;
  S_rs_1025_1.q0 = &internal1_m1025_q0;
  S_rs_1037_1.q0 = &internal1_m1037_q0;
  S_rs_1047_1.q0 = &internal1_m1047_q0;
  S_rs_1024_1.q0 = &internal1_m1024_q0;
  S_rs_1039_1.q0 = &internal1_m1039_q0;
  S_rs_1908_1.q0 = &internal1_m1908_q0;
  S_rs_1907_1.q0 = &internal1_m1907_q0;
  S_provsbr_320_1.Step = &internal1_m320_Step;
  S_provsbr_320_1.TimS = &internal1_m320_TimS;
  S_provsbr_320_1.FinPr0 = &internal1_m320_FinPr0;
  S_provsbr_320_1.ErrPr0 = &internal1_m320_ErrPr0;
  S_provsbr_320_1.sbINI0 = &internal1_m320_sbINI0;
  S_provsbr_320_1.sbVuIS0 = &internal1_m320_sbVuIS0;
  S_provsbr_320_1.sb2UR0 = &internal1_m320_sb2UR0;
  S_provsbr_320_1.sbNupIS0 = &internal1_m320_sbNupIS0;
  S_provsbr_320_1.sbVuRB0 = &internal1_m320_sbVuRB0;
  S_provsbr_320_1.MyFirstEnterFlag = &internal1_m320_MyFirstEnterFlag;
  S_cntch_328_1.x0 = &internal1_m328_x0;
  S_decatron_287_1.TimS = &internal1_m287_TimS;
  S_provsbr_263_1.Step = &internal1_m263_Step;
  S_provsbr_263_1.TimS = &internal1_m263_TimS;
  S_provsbr_263_1.FinPr0 = &internal1_m263_FinPr0;
  S_provsbr_263_1.ErrPr0 = &internal1_m263_ErrPr0;
  S_provsbr_263_1.sbINI0 = &internal1_m263_sbINI0;
  S_provsbr_263_1.sbVuIS0 = &internal1_m263_sbVuIS0;
  S_provsbr_263_1.sb2UR0 = &internal1_m263_sb2UR0;
  S_provsbr_263_1.sbNupIS0 = &internal1_m263_sbNupIS0;
  S_provsbr_263_1.sbVuRB0 = &internal1_m263_sbVuRB0;
  S_provsbr_263_1.MyFirstEnterFlag = &internal1_m263_MyFirstEnterFlag;
  S_rs_1382_1.q0 = &internal1_m1382_q0;
  S_provsbr_1383_1.Step = &internal1_m1383_Step;
  S_provsbr_1383_1.TimS = &internal1_m1383_TimS;
  S_provsbr_1383_1.FinPr0 = &internal1_m1383_FinPr0;
  S_provsbr_1383_1.ErrPr0 = &internal1_m1383_ErrPr0;
  S_provsbr_1383_1.sbINI0 = &internal1_m1383_sbINI0;
  S_provsbr_1383_1.sbVuIS0 = &internal1_m1383_sbVuIS0;
  S_provsbr_1383_1.sb2UR0 = &internal1_m1383_sb2UR0;
  S_provsbr_1383_1.sbNupIS0 = &internal1_m1383_sbNupIS0;
  S_provsbr_1383_1.sbVuRB0 = &internal1_m1383_sbVuRB0;
  S_provsbr_1383_1.MyFirstEnterFlag = &internal1_m1383_MyFirstEnterFlag;
  S_rs_1008_1.q0 = &internal1_m1008_q0;
  S_rs_1005_1.q0 = &internal1_m1005_q0;
  S_rs_1007_1.q0 = &internal1_m1007_q0;
  S_rs_1002_1.q0 = &internal1_m1002_q0;
  S_rs_735_1.q0 = &internal1_m735_q0;
  S_rs_330_1.q0 = &internal1_m330_q0;
  S_rs_326_1.q0 = &internal1_m326_q0;
  S_rs_283_1.q0 = &internal1_m283_q0;
  S_cntch_282_1.x0 = &internal1_m282_x0;
  S_rs_1837_1.q0 = &internal1_m1837_q0;
  S_rs_1825_1.q0 = &internal1_m1825_q0;
  S_rs_1816_1.q0 = &internal1_m1816_q0;
  S_rs_1891_1.q0 = &internal1_m1891_q0;
  S_rs_1862_1.q0 = &internal1_m1862_q0;
  S_rs_1851_1.q0 = &internal1_m1851_q0;
  S_rs_1435_1.q0 = &internal1_m1435_q0;
  S_kvf_1422_1.x0 = &internal1_m1422_x0;
  S_kvf_1422_1.y0 = &internal1_m1422_y0;
  S_kvf_1422_1.FirstEnterFlag = &bFirstEnterFlag;
  S_rs_1418_1.q0 = &internal1_m1418_q0;
  S_rs_1409_1.q0 = &internal1_m1409_q0;
  S_rs_1468_1.q0 = &internal1_m1468_q0;
  S_rs_1488_1.q0 = &internal1_m1488_q0;
  S_rs_1454_1.q0 = &internal1_m1454_q0;
  S_kvf_1469_1.x0 = &internal1_m1469_x0;
  S_kvf_1469_1.y0 = &internal1_m1469_y0;
  S_kvf_1469_1.FirstEnterFlag = &bFirstEnterFlag;
  S_cntch_1393_1.x0 = &internal1_m1393_x0;
  S_rs_1474_1.q0 = &internal1_m1474_q0;
  S_rs_26_1.q0 = &internal1_m26_q0;
  S_rs_1489_1.q0 = &internal1_m1489_q0;
  S_rs_627_1.q0 = &internal1_m627_q0;
  S_rs_612_1.q0 = &internal1_m612_q0;
  S_rs_639_1.q0 = &internal1_m639_q0;
  S_rs_623_1.q0 = &internal1_m623_q0;
  S_rs_607_1.q0 = &internal1_m607_q0;
  S_rs_605_1.q0 = &internal1_m605_q0;
  S_rs_593_1.q0 = &internal1_m593_q0;
  S_rsun_1385_1.q0 = &internal1_m1385_q0;
  S_rs_603_1.q0 = &internal1_m603_q0;
  S_rs_106_1.q0 = &internal1_m106_q0;
  S_rs_1619_1.q0 = &internal1_m1619_q0;
  S_rs_1618_1.q0 = &internal1_m1618_q0;
  S_rs_1617_1.q0 = &internal1_m1617_q0;
  S_rs_1616_1.q0 = &internal1_m1616_q0;
  S_rs_1645_1.q0 = &internal1_m1645_q0;
  S_rs_1644_1.q0 = &internal1_m1644_q0;
  S_rs_1643_1.q0 = &internal1_m1643_q0;
  S_rs_1642_1.q0 = &internal1_m1642_q0;
  S_rs_1922_1.q0 = &internal1_m1922_q0;
  S_rs_1702_1.q0 = &internal1_m1702_q0;
  S_rs_1701_1.q0 = &internal1_m1701_q0;
  S_rs_1699_1.q0 = &internal1_m1699_q0;
  S_rs_1698_1.q0 = &internal1_m1698_q0;
  S_rs_1696_1.q0 = &internal1_m1696_q0;
  S_rs_2115_1.q0 = &internal1_m2115_q0;
  S_rs_2112_1.q0 = &internal1_m2112_q0;
  S_rs_1671_1.q0 = &internal1_m1671_q0;
  S_rs_1665_1.q0 = &internal1_m1665_q0;
  S_rs_1664_1.q0 = &internal1_m1664_q0;
  S_rs_1660_1.q0 = &internal1_m1660_q0;
  S_rs_1662_1.q0 = &internal1_m1662_q0;
  S_rs_1659_1.q0 = &internal1_m1659_q0;
  S_rs_1658_1.q0 = &internal1_m1658_q0;
  S_rs_1654_1.q0 = &internal1_m1654_q0;
  S_rs_1656_1.q0 = &internal1_m1656_q0;
  S_rs_19_1.q0 = &internal1_m19_q0;
  S_rs_1639_1.q0 = &internal1_m1639_q0;
  S_rs_1637_1.q0 = &internal1_m1637_q0;
  S_rs_1634_1.q0 = &internal1_m1634_q0;
  S_rs_1636_1.q0 = &internal1_m1636_q0;
  S_rs_1633_1.q0 = &internal1_m1633_q0;
  S_rs_1631_1.q0 = &internal1_m1631_q0;
  S_rs_2038_1.q0 = &internal1_m2038_q0;
  S_rs_2033_1.q0 = &internal1_m2033_q0;
  S_rs_2012_1.q0 = &internal1_m2012_q0;
  S_rs_2000_1.q0 = &internal1_m2000_q0;
  S_rs_1933_1.q0 = &internal1_m1933_q0;
  S_rs_1628_1.q0 = &internal1_m1628_q0;
  S_rs_1630_1.q0 = &internal1_m1630_q0;
  S_rs_1615_1.q0 = &internal1_m1615_q0;
  S_rs_1613_1.q0 = &internal1_m1613_q0;
  S_rs_1612_1.q0 = &internal1_m1612_q0;
  S_rs_1610_1.q0 = &internal1_m1610_q0;
  S_rs_1609_1.q0 = &internal1_m1609_q0;
  S_rs_1607_1.q0 = &internal1_m1607_q0;
  S_rs_1606_1.q0 = &internal1_m1606_q0;
  S_rs_1604_1.q0 = &internal1_m1604_q0;
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
  S_samhd_2055_1.DvUp0 = &internal1_m2055_DvUp0;
  S_samhd_2055_1.DvDw0 = &internal1_m2055_DvDw0;
  S_samhd_2055_1.FDvUp0 = &internal1_m2055_FDvUp0;
  S_samhd_2055_1.FDvDw0 = &internal1_m2055_FDvDw0;
  S_samhd_2055_1.BlDv0 = &internal1_m2055_BlDv0;
  S_samhd_2055_1.Pkv0 = &internal1_m2055_Pkv0;
  S_samhd_2055_1.Pkav0 = &internal1_m2055_Pkav0;
  S_samhd_2055_1.Zkv0 = &internal1_m2055_Zkv0;
  S_samhd_2055_1.Zkav0 = &internal1_m2055_Zkav0;
  S_samhd_2055_1.txNm = &internal1_m2055_txNm;
  S_samhd_2055_1.txSm = &internal1_m2055_txSm;
  S_samhd_2055_1.txHr = &internal1_m2055_txHr;
  S_samhd_2055_1.txLd = &internal1_m2055_txLd;
  S_samhd_2055_1.fef = &internal1_m2055_fef;
  S_samhd_2055_1.FirstEnterFlag = &bFirstEnterFlag;
  S_rs_1459_1.q0 = &internal1_m1459_q0;
  S_kvf_1463_1.x0 = &internal1_m1463_x0;
  S_kvf_1463_1.y0 = &internal1_m1463_y0;
  S_kvf_1463_1.FirstEnterFlag = &bFirstEnterFlag;
  S_kvf_1873_1.x0 = &internal1_m1873_x0;
  S_kvf_1873_1.y0 = &internal1_m1873_y0;
  S_kvf_1873_1.FirstEnterFlag = &bFirstEnterFlag;
  S_kvf_1834_1.x0 = &internal1_m1834_x0;
  S_kvf_1834_1.y0 = &internal1_m1834_y0;
  S_kvf_1834_1.FirstEnterFlag = &bFirstEnterFlag;
  S_rs_274_1.q0 = &internal1_m274_q0;
  S_rs_982_1.q0 = &internal1_m982_q0;
  S_rs_615_1.q0 = &internal1_m615_q0;
  S_cnshd_1282_1.X0 = &internal1_m1282_X0;
  S_cnshd_1282_1.t0 = &internal1_m1282_t0;
  S_cnshd_1282_1.BLDv0 = &internal1_m1282_BLDv0;
  S_zpfs_1301_1.tx = &internal1_m1301_tx;
  S_zpfs_1301_1.y0 = &internal1_m1301_y0;
  S_zpfs_1303_1.tx = &internal1_m1303_tx;
  S_zpfs_1303_1.y0 = &internal1_m1303_y0;
  S_fnapb_1310_1.xptr = &internal1_m1310_xptr;
  S_fnapb_1310_1.mcount = &internal1_m1310_mcount;
  S_fnapb_1310_1.sumtim = &internal1_m1310_sumtim;
  S_fnapb_1310_1.sumtakt = &internal1_m1310_sumtakt;
  S_fnapb_1310_1.StSpeed = &internal1_m1310_StSpeed;
  S_fnapb_1310_1.Vz0 = &internal1_m1310_Vz0;
  S_fnapb_1310_1.flRazg = &internal1_m1310_flRazg;
  S_fnapb_1310_1.DelSp = &internal1_m1310_DelSp;
  S_fnapb_1310_1.z0 = &internal1_m1310_z0;
  S_fnapb_1310_1.txZS = &internal1_m1310_txZS;
  S_fnapb_1310_1.tx = &internal1_m1310_tx;
  S_fnapb_1310_1.txd = &internal1_m1310_txd;
  S_fnapb_1310_1.txMBl = &internal1_m1310_txMBl;
  S_fnapb_1310_1.txBl = &internal1_m1310_txBl;
  S_fnapb_1310_1.Speed0 = &internal1_m1310_Speed0;
  S_fnapb_1310_1.xz0 = &internal1_m1310_xz0;
  S_fnapb_1310_1.tz0 = &internal1_m1310_tz0;
  S_fnapb_1310_1.Shift0 = &internal1_m1310_Shift0;
  S_fnapb_1310_1.ShCntlSp0 = &internal1_m1310_ShCntlSp0;
  S_fnapb_1310_1.ShiftControl = &internal1_m1310_ShiftControl;
  S_fnapb_1310_1.FirstEnterFlag = &bFirstEnterFlag;
  S_rs_613_1.q0 = &internal1_m613_q0;
  S_cnshd_880_1.X0 = &internal1_m880_X0;
  S_cnshd_880_1.t0 = &internal1_m880_t0;
  S_cnshd_880_1.BLDv0 = &internal1_m880_BLDv0;
  S_zpfs_904_1.tx = &internal1_m904_tx;
  S_zpfs_904_1.y0 = &internal1_m904_y0;
  S_zpfs_905_1.tx = &internal1_m905_tx;
  S_zpfs_905_1.y0 = &internal1_m905_y0;
  S_fnapb_913_1.xptr = &internal1_m913_xptr;
  S_fnapb_913_1.mcount = &internal1_m913_mcount;
  S_fnapb_913_1.sumtim = &internal1_m913_sumtim;
  S_fnapb_913_1.sumtakt = &internal1_m913_sumtakt;
  S_fnapb_913_1.StSpeed = &internal1_m913_StSpeed;
  S_fnapb_913_1.Vz0 = &internal1_m913_Vz0;
  S_fnapb_913_1.flRazg = &internal1_m913_flRazg;
  S_fnapb_913_1.DelSp = &internal1_m913_DelSp;
  S_fnapb_913_1.z0 = &internal1_m913_z0;
  S_fnapb_913_1.txZS = &internal1_m913_txZS;
  S_fnapb_913_1.tx = &internal1_m913_tx;
  S_fnapb_913_1.txd = &internal1_m913_txd;
  S_fnapb_913_1.txMBl = &internal1_m913_txMBl;
  S_fnapb_913_1.txBl = &internal1_m913_txBl;
  S_fnapb_913_1.Speed0 = &internal1_m913_Speed0;
  S_fnapb_913_1.xz0 = &internal1_m913_xz0;
  S_fnapb_913_1.tz0 = &internal1_m913_tz0;
  S_fnapb_913_1.Shift0 = &internal1_m913_Shift0;
  S_fnapb_913_1.ShCntlSp0 = &internal1_m913_ShCntlSp0;
  S_fnapb_913_1.ShiftControl = &internal1_m913_ShiftControl;
  S_fnapb_913_1.FirstEnterFlag = &bFirstEnterFlag;
  S_cnshd_484_1.X0 = &internal1_m484_X0;
  S_cnshd_484_1.t0 = &internal1_m484_t0;
  S_cnshd_484_1.BLDv0 = &internal1_m484_BLDv0;
  S_zpfs_504_1.tx = &internal1_m504_tx;
  S_zpfs_504_1.y0 = &internal1_m504_y0;
  S_zpfs_506_1.tx = &internal1_m506_tx;
  S_zpfs_506_1.y0 = &internal1_m506_y0;
  S_fnapb_511_1.xptr = &internal1_m511_xptr;
  S_fnapb_511_1.mcount = &internal1_m511_mcount;
  S_fnapb_511_1.sumtim = &internal1_m511_sumtim;
  S_fnapb_511_1.sumtakt = &internal1_m511_sumtakt;
  S_fnapb_511_1.StSpeed = &internal1_m511_StSpeed;
  S_fnapb_511_1.Vz0 = &internal1_m511_Vz0;
  S_fnapb_511_1.flRazg = &internal1_m511_flRazg;
  S_fnapb_511_1.DelSp = &internal1_m511_DelSp;
  S_fnapb_511_1.z0 = &internal1_m511_z0;
  S_fnapb_511_1.txZS = &internal1_m511_txZS;
  S_fnapb_511_1.tx = &internal1_m511_tx;
  S_fnapb_511_1.txd = &internal1_m511_txd;
  S_fnapb_511_1.txMBl = &internal1_m511_txMBl;
  S_fnapb_511_1.txBl = &internal1_m511_txBl;
  S_fnapb_511_1.Speed0 = &internal1_m511_Speed0;
  S_fnapb_511_1.xz0 = &internal1_m511_xz0;
  S_fnapb_511_1.tz0 = &internal1_m511_tz0;
  S_fnapb_511_1.Shift0 = &internal1_m511_Shift0;
  S_fnapb_511_1.ShCntlSp0 = &internal1_m511_ShCntlSp0;
  S_fnapb_511_1.ShiftControl = &internal1_m511_ShiftControl;
  S_fnapb_511_1.FirstEnterFlag = &bFirstEnterFlag;
  S_rs_610_1.q0 = &internal1_m610_q0;
  S_cnshd_163_1.X0 = &internal1_m163_X0;
  S_cnshd_163_1.t0 = &internal1_m163_t0;
  S_cnshd_163_1.BLDv0 = &internal1_m163_BLDv0;
  S_fnapb_192_1.xptr = &internal1_m192_xptr;
  S_fnapb_192_1.mcount = &internal1_m192_mcount;
  S_fnapb_192_1.sumtim = &internal1_m192_sumtim;
  S_fnapb_192_1.sumtakt = &internal1_m192_sumtakt;
  S_fnapb_192_1.StSpeed = &internal1_m192_StSpeed;
  S_fnapb_192_1.Vz0 = &internal1_m192_Vz0;
  S_fnapb_192_1.flRazg = &internal1_m192_flRazg;
  S_fnapb_192_1.DelSp = &internal1_m192_DelSp;
  S_fnapb_192_1.z0 = &internal1_m192_z0;
  S_fnapb_192_1.txZS = &internal1_m192_txZS;
  S_fnapb_192_1.tx = &internal1_m192_tx;
  S_fnapb_192_1.txd = &internal1_m192_txd;
  S_fnapb_192_1.txMBl = &internal1_m192_txMBl;
  S_fnapb_192_1.txBl = &internal1_m192_txBl;
  S_fnapb_192_1.Speed0 = &internal1_m192_Speed0;
  S_fnapb_192_1.xz0 = &internal1_m192_xz0;
  S_fnapb_192_1.tz0 = &internal1_m192_tz0;
  S_fnapb_192_1.Shift0 = &internal1_m192_Shift0;
  S_fnapb_192_1.ShCntlSp0 = &internal1_m192_ShCntlSp0;
  S_fnapb_192_1.ShiftControl = &internal1_m192_ShiftControl;
  S_fnapb_192_1.FirstEnterFlag = &bFirstEnterFlag;
  S_rs_636_1.q0 = &internal1_m636_q0;
  S_samhd_455_1.DvUp0 = &internal1_m455_DvUp0;
  S_samhd_455_1.DvDw0 = &internal1_m455_DvDw0;
  S_samhd_455_1.FDvUp0 = &internal1_m455_FDvUp0;
  S_samhd_455_1.FDvDw0 = &internal1_m455_FDvDw0;
  S_samhd_455_1.BlDv0 = &internal1_m455_BlDv0;
  S_samhd_455_1.Pkv0 = &internal1_m455_Pkv0;
  S_samhd_455_1.Pkav0 = &internal1_m455_Pkav0;
  S_samhd_455_1.Zkv0 = &internal1_m455_Zkv0;
  S_samhd_455_1.Zkav0 = &internal1_m455_Zkav0;
  S_samhd_455_1.txNm = &internal1_m455_txNm;
  S_samhd_455_1.txSm = &internal1_m455_txSm;
  S_samhd_455_1.txHr = &internal1_m455_txHr;
  S_samhd_455_1.txLd = &internal1_m455_txLd;
  S_samhd_455_1.fef = &internal1_m455_fef;
  S_samhd_455_1.FirstEnterFlag = &bFirstEnterFlag;
  S_samhd_449_1.DvUp0 = &internal1_m449_DvUp0;
  S_samhd_449_1.DvDw0 = &internal1_m449_DvDw0;
  S_samhd_449_1.FDvUp0 = &internal1_m449_FDvUp0;
  S_samhd_449_1.FDvDw0 = &internal1_m449_FDvDw0;
  S_samhd_449_1.BlDv0 = &internal1_m449_BlDv0;
  S_samhd_449_1.Pkv0 = &internal1_m449_Pkv0;
  S_samhd_449_1.Pkav0 = &internal1_m449_Pkav0;
  S_samhd_449_1.Zkv0 = &internal1_m449_Zkv0;
  S_samhd_449_1.Zkav0 = &internal1_m449_Zkav0;
  S_samhd_449_1.txNm = &internal1_m449_txNm;
  S_samhd_449_1.txSm = &internal1_m449_txSm;
  S_samhd_449_1.txHr = &internal1_m449_txHr;
  S_samhd_449_1.txLd = &internal1_m449_txLd;
  S_samhd_449_1.fef = &internal1_m449_fef;
  S_samhd_449_1.FirstEnterFlag = &bFirstEnterFlag;
  S_cnshd_800_1.X0 = &internal1_m800_X0;
  S_cnshd_800_1.t0 = &internal1_m800_t0;
  S_cnshd_800_1.BLDv0 = &internal1_m800_BLDv0;
  S_fnapb_820_1.xptr = &internal1_m820_xptr;
  S_fnapb_820_1.mcount = &internal1_m820_mcount;
  S_fnapb_820_1.sumtim = &internal1_m820_sumtim;
  S_fnapb_820_1.sumtakt = &internal1_m820_sumtakt;
  S_fnapb_820_1.StSpeed = &internal1_m820_StSpeed;
  S_fnapb_820_1.Vz0 = &internal1_m820_Vz0;
  S_fnapb_820_1.flRazg = &internal1_m820_flRazg;
  S_fnapb_820_1.DelSp = &internal1_m820_DelSp;
  S_fnapb_820_1.z0 = &internal1_m820_z0;
  S_fnapb_820_1.txZS = &internal1_m820_txZS;
  S_fnapb_820_1.tx = &internal1_m820_tx;
  S_fnapb_820_1.txd = &internal1_m820_txd;
  S_fnapb_820_1.txMBl = &internal1_m820_txMBl;
  S_fnapb_820_1.txBl = &internal1_m820_txBl;
  S_fnapb_820_1.Speed0 = &internal1_m820_Speed0;
  S_fnapb_820_1.xz0 = &internal1_m820_xz0;
  S_fnapb_820_1.tz0 = &internal1_m820_tz0;
  S_fnapb_820_1.Shift0 = &internal1_m820_Shift0;
  S_fnapb_820_1.ShCntlSp0 = &internal1_m820_ShCntlSp0;
  S_fnapb_820_1.ShiftControl = &internal1_m820_ShiftControl;
  S_fnapb_820_1.FirstEnterFlag = &bFirstEnterFlag;
  S_cnshd_1564_1.X0 = &internal1_m1564_X0;
  S_cnshd_1564_1.t0 = &internal1_m1564_t0;
  S_cnshd_1564_1.BLDv0 = &internal1_m1564_BLDv0;
  S_cnshd_1100_1.X0 = &internal1_m1100_X0;
  S_cnshd_1100_1.t0 = &internal1_m1100_t0;
  S_cnshd_1100_1.BLDv0 = &internal1_m1100_BLDv0;
  S_rs_608_1.q0 = &internal1_m608_q0;
  S_cnshd_1185_1.X0 = &internal1_m1185_X0;
  S_cnshd_1185_1.t0 = &internal1_m1185_t0;
  S_cnshd_1185_1.BLDv0 = &internal1_m1185_BLDv0;
  S_zpfs_1205_1.tx = &internal1_m1205_tx;
  S_zpfs_1205_1.y0 = &internal1_m1205_y0;
  S_zpfs_1214_1.tx = &internal1_m1214_tx;
  S_zpfs_1214_1.y0 = &internal1_m1214_y0;
  S_fnapb_1219_1.xptr = &internal1_m1219_xptr;
  S_fnapb_1219_1.mcount = &internal1_m1219_mcount;
  S_fnapb_1219_1.sumtim = &internal1_m1219_sumtim;
  S_fnapb_1219_1.sumtakt = &internal1_m1219_sumtakt;
  S_fnapb_1219_1.StSpeed = &internal1_m1219_StSpeed;
  S_fnapb_1219_1.Vz0 = &internal1_m1219_Vz0;
  S_fnapb_1219_1.flRazg = &internal1_m1219_flRazg;
  S_fnapb_1219_1.DelSp = &internal1_m1219_DelSp;
  S_fnapb_1219_1.z0 = &internal1_m1219_z0;
  S_fnapb_1219_1.txZS = &internal1_m1219_txZS;
  S_fnapb_1219_1.tx = &internal1_m1219_tx;
  S_fnapb_1219_1.txd = &internal1_m1219_txd;
  S_fnapb_1219_1.txMBl = &internal1_m1219_txMBl;
  S_fnapb_1219_1.txBl = &internal1_m1219_txBl;
  S_fnapb_1219_1.Speed0 = &internal1_m1219_Speed0;
  S_fnapb_1219_1.xz0 = &internal1_m1219_xz0;
  S_fnapb_1219_1.tz0 = &internal1_m1219_tz0;
  S_fnapb_1219_1.Shift0 = &internal1_m1219_Shift0;
  S_fnapb_1219_1.ShCntlSp0 = &internal1_m1219_ShCntlSp0;
  S_fnapb_1219_1.ShiftControl = &internal1_m1219_ShiftControl;
  S_fnapb_1219_1.FirstEnterFlag = &bFirstEnterFlag;
  S_rs_628_1.q0 = &internal1_m628_q0;
  S_zpfs_1577_1.tx = &internal1_m1577_tx;
  S_zpfs_1577_1.y0 = &internal1_m1577_y0;
  S_zpfs_1581_1.tx = &internal1_m1581_tx;
  S_zpfs_1581_1.y0 = &internal1_m1581_y0;
  S_samhd_1567_1.DvUp0 = &internal1_m1567_DvUp0;
  S_samhd_1567_1.DvDw0 = &internal1_m1567_DvDw0;
  S_samhd_1567_1.FDvUp0 = &internal1_m1567_FDvUp0;
  S_samhd_1567_1.FDvDw0 = &internal1_m1567_FDvDw0;
  S_samhd_1567_1.BlDv0 = &internal1_m1567_BlDv0;
  S_samhd_1567_1.Pkv0 = &internal1_m1567_Pkv0;
  S_samhd_1567_1.Pkav0 = &internal1_m1567_Pkav0;
  S_samhd_1567_1.Zkv0 = &internal1_m1567_Zkv0;
  S_samhd_1567_1.Zkav0 = &internal1_m1567_Zkav0;
  S_samhd_1567_1.txNm = &internal1_m1567_txNm;
  S_samhd_1567_1.txSm = &internal1_m1567_txSm;
  S_samhd_1567_1.txHr = &internal1_m1567_txHr;
  S_samhd_1567_1.txLd = &internal1_m1567_txLd;
  S_samhd_1567_1.fef = &internal1_m1567_fef;
  S_samhd_1567_1.FirstEnterFlag = &bFirstEnterFlag;
  S_fnapb_1584_1.xptr = &internal1_m1584_xptr;
  S_fnapb_1584_1.mcount = &internal1_m1584_mcount;
  S_fnapb_1584_1.sumtim = &internal1_m1584_sumtim;
  S_fnapb_1584_1.sumtakt = &internal1_m1584_sumtakt;
  S_fnapb_1584_1.StSpeed = &internal1_m1584_StSpeed;
  S_fnapb_1584_1.Vz0 = &internal1_m1584_Vz0;
  S_fnapb_1584_1.flRazg = &internal1_m1584_flRazg;
  S_fnapb_1584_1.DelSp = &internal1_m1584_DelSp;
  S_fnapb_1584_1.z0 = &internal1_m1584_z0;
  S_fnapb_1584_1.txZS = &internal1_m1584_txZS;
  S_fnapb_1584_1.tx = &internal1_m1584_tx;
  S_fnapb_1584_1.txd = &internal1_m1584_txd;
  S_fnapb_1584_1.txMBl = &internal1_m1584_txMBl;
  S_fnapb_1584_1.txBl = &internal1_m1584_txBl;
  S_fnapb_1584_1.Speed0 = &internal1_m1584_Speed0;
  S_fnapb_1584_1.xz0 = &internal1_m1584_xz0;
  S_fnapb_1584_1.tz0 = &internal1_m1584_tz0;
  S_fnapb_1584_1.Shift0 = &internal1_m1584_Shift0;
  S_fnapb_1584_1.ShCntlSp0 = &internal1_m1584_ShCntlSp0;
  S_fnapb_1584_1.ShiftControl = &internal1_m1584_ShiftControl;
  S_fnapb_1584_1.FirstEnterFlag = &bFirstEnterFlag;
  S_zpfs_1116_1.tx = &internal1_m1116_tx;
  S_zpfs_1116_1.y0 = &internal1_m1116_y0;
  S_zpfs_1120_1.tx = &internal1_m1120_tx;
  S_zpfs_1120_1.y0 = &internal1_m1120_y0;
  S_rs_618_1.q0 = &internal1_m618_q0;
  S_rs_583_1.q0 = &internal1_m583_q0;
  S_samhd_1106_1.DvUp0 = &internal1_m1106_DvUp0;
  S_samhd_1106_1.DvDw0 = &internal1_m1106_DvDw0;
  S_samhd_1106_1.FDvUp0 = &internal1_m1106_FDvUp0;
  S_samhd_1106_1.FDvDw0 = &internal1_m1106_FDvDw0;
  S_samhd_1106_1.BlDv0 = &internal1_m1106_BlDv0;
  S_samhd_1106_1.Pkv0 = &internal1_m1106_Pkv0;
  S_samhd_1106_1.Pkav0 = &internal1_m1106_Pkav0;
  S_samhd_1106_1.Zkv0 = &internal1_m1106_Zkv0;
  S_samhd_1106_1.Zkav0 = &internal1_m1106_Zkav0;
  S_samhd_1106_1.txNm = &internal1_m1106_txNm;
  S_samhd_1106_1.txSm = &internal1_m1106_txSm;
  S_samhd_1106_1.txHr = &internal1_m1106_txHr;
  S_samhd_1106_1.txLd = &internal1_m1106_txLd;
  S_samhd_1106_1.fef = &internal1_m1106_fef;
  S_samhd_1106_1.FirstEnterFlag = &bFirstEnterFlag;
  S_fnapb_1124_1.xptr = &internal1_m1124_xptr;
  S_fnapb_1124_1.mcount = &internal1_m1124_mcount;
  S_fnapb_1124_1.sumtim = &internal1_m1124_sumtim;
  S_fnapb_1124_1.sumtakt = &internal1_m1124_sumtakt;
  S_fnapb_1124_1.StSpeed = &internal1_m1124_StSpeed;
  S_fnapb_1124_1.Vz0 = &internal1_m1124_Vz0;
  S_fnapb_1124_1.flRazg = &internal1_m1124_flRazg;
  S_fnapb_1124_1.DelSp = &internal1_m1124_DelSp;
  S_fnapb_1124_1.z0 = &internal1_m1124_z0;
  S_fnapb_1124_1.txZS = &internal1_m1124_txZS;
  S_fnapb_1124_1.tx = &internal1_m1124_tx;
  S_fnapb_1124_1.txd = &internal1_m1124_txd;
  S_fnapb_1124_1.txMBl = &internal1_m1124_txMBl;
  S_fnapb_1124_1.txBl = &internal1_m1124_txBl;
  S_fnapb_1124_1.Speed0 = &internal1_m1124_Speed0;
  S_fnapb_1124_1.xz0 = &internal1_m1124_xz0;
  S_fnapb_1124_1.tz0 = &internal1_m1124_tz0;
  S_fnapb_1124_1.Shift0 = &internal1_m1124_Shift0;
  S_fnapb_1124_1.ShCntlSp0 = &internal1_m1124_ShCntlSp0;
  S_fnapb_1124_1.ShiftControl = &internal1_m1124_ShiftControl;
  S_fnapb_1124_1.FirstEnterFlag = &bFirstEnterFlag;
  S_vmemb_729_1.x0 = &internal1_m729_x0;
  S_vmemb_700_1.x0 = &internal1_m700_x0;
  S_vmemb_663_1.x0 = &internal1_m663_x0;
  S_rs_754_1.q0 = &internal1_m754_q0;
  S_rs_749_1.q0 = &internal1_m749_q0;
  S_rs_717_1.q0 = &internal1_m717_q0;
  S_rs_721_1.q0 = &internal1_m721_q0;
  S_rs_730_1.q0 = &internal1_m730_q0;
  S_rs_742_1.q0 = &internal1_m742_q0;
  S_rs_719_1.q0 = &internal1_m719_q0;
  S_samhd_1161_1.DvUp0 = &internal1_m1161_DvUp0;
  S_samhd_1161_1.DvDw0 = &internal1_m1161_DvDw0;
  S_samhd_1161_1.FDvUp0 = &internal1_m1161_FDvUp0;
  S_samhd_1161_1.FDvDw0 = &internal1_m1161_FDvDw0;
  S_samhd_1161_1.BlDv0 = &internal1_m1161_BlDv0;
  S_samhd_1161_1.Pkv0 = &internal1_m1161_Pkv0;
  S_samhd_1161_1.Pkav0 = &internal1_m1161_Pkav0;
  S_samhd_1161_1.Zkv0 = &internal1_m1161_Zkv0;
  S_samhd_1161_1.Zkav0 = &internal1_m1161_Zkav0;
  S_samhd_1161_1.txNm = &internal1_m1161_txNm;
  S_samhd_1161_1.txSm = &internal1_m1161_txSm;
  S_samhd_1161_1.txHr = &internal1_m1161_txHr;
  S_samhd_1161_1.txLd = &internal1_m1161_txLd;
  S_samhd_1161_1.fef = &internal1_m1161_fef;
  S_samhd_1161_1.FirstEnterFlag = &bFirstEnterFlag;
  S_samhd_1151_1.DvUp0 = &internal1_m1151_DvUp0;
  S_samhd_1151_1.DvDw0 = &internal1_m1151_DvDw0;
  S_samhd_1151_1.FDvUp0 = &internal1_m1151_FDvUp0;
  S_samhd_1151_1.FDvDw0 = &internal1_m1151_FDvDw0;
  S_samhd_1151_1.BlDv0 = &internal1_m1151_BlDv0;
  S_samhd_1151_1.Pkv0 = &internal1_m1151_Pkv0;
  S_samhd_1151_1.Pkav0 = &internal1_m1151_Pkav0;
  S_samhd_1151_1.Zkv0 = &internal1_m1151_Zkv0;
  S_samhd_1151_1.Zkav0 = &internal1_m1151_Zkav0;
  S_samhd_1151_1.txNm = &internal1_m1151_txNm;
  S_samhd_1151_1.txSm = &internal1_m1151_txSm;
  S_samhd_1151_1.txHr = &internal1_m1151_txHr;
  S_samhd_1151_1.txLd = &internal1_m1151_txLd;
  S_samhd_1151_1.fef = &internal1_m1151_fef;
  S_samhd_1151_1.FirstEnterFlag = &bFirstEnterFlag;
  S_samhd_774_1.DvUp0 = &internal1_m774_DvUp0;
  S_samhd_774_1.DvDw0 = &internal1_m774_DvDw0;
  S_samhd_774_1.FDvUp0 = &internal1_m774_FDvUp0;
  S_samhd_774_1.FDvDw0 = &internal1_m774_FDvDw0;
  S_samhd_774_1.BlDv0 = &internal1_m774_BlDv0;
  S_samhd_774_1.Pkv0 = &internal1_m774_Pkv0;
  S_samhd_774_1.Pkav0 = &internal1_m774_Pkav0;
  S_samhd_774_1.Zkv0 = &internal1_m774_Zkv0;
  S_samhd_774_1.Zkav0 = &internal1_m774_Zkav0;
  S_samhd_774_1.txNm = &internal1_m774_txNm;
  S_samhd_774_1.txSm = &internal1_m774_txSm;
  S_samhd_774_1.txHr = &internal1_m774_txHr;
  S_samhd_774_1.txLd = &internal1_m774_txLd;
  S_samhd_774_1.fef = &internal1_m774_fef;
  S_samhd_774_1.FirstEnterFlag = &bFirstEnterFlag;
  S_samhd_770_1.DvUp0 = &internal1_m770_DvUp0;
  S_samhd_770_1.DvDw0 = &internal1_m770_DvDw0;
  S_samhd_770_1.FDvUp0 = &internal1_m770_FDvUp0;
  S_samhd_770_1.FDvDw0 = &internal1_m770_FDvDw0;
  S_samhd_770_1.BlDv0 = &internal1_m770_BlDv0;
  S_samhd_770_1.Pkv0 = &internal1_m770_Pkv0;
  S_samhd_770_1.Pkav0 = &internal1_m770_Pkav0;
  S_samhd_770_1.Zkv0 = &internal1_m770_Zkv0;
  S_samhd_770_1.Zkav0 = &internal1_m770_Zkav0;
  S_samhd_770_1.txNm = &internal1_m770_txNm;
  S_samhd_770_1.txSm = &internal1_m770_txSm;
  S_samhd_770_1.txHr = &internal1_m770_txHr;
  S_samhd_770_1.txLd = &internal1_m770_txLd;
  S_samhd_770_1.fef = &internal1_m770_fef;
  S_samhd_770_1.FirstEnterFlag = &bFirstEnterFlag;
  S_samhd_354_1.DvUp0 = &internal1_m354_DvUp0;
  S_samhd_354_1.DvDw0 = &internal1_m354_DvDw0;
  S_samhd_354_1.FDvUp0 = &internal1_m354_FDvUp0;
  S_samhd_354_1.FDvDw0 = &internal1_m354_FDvDw0;
  S_samhd_354_1.BlDv0 = &internal1_m354_BlDv0;
  S_samhd_354_1.Pkv0 = &internal1_m354_Pkv0;
  S_samhd_354_1.Pkav0 = &internal1_m354_Pkav0;
  S_samhd_354_1.Zkv0 = &internal1_m354_Zkv0;
  S_samhd_354_1.Zkav0 = &internal1_m354_Zkav0;
  S_samhd_354_1.txNm = &internal1_m354_txNm;
  S_samhd_354_1.txSm = &internal1_m354_txSm;
  S_samhd_354_1.txHr = &internal1_m354_txHr;
  S_samhd_354_1.txLd = &internal1_m354_txLd;
  S_samhd_354_1.fef = &internal1_m354_fef;
  S_samhd_354_1.FirstEnterFlag = &bFirstEnterFlag;
  S_samhd_383_1.DvUp0 = &internal1_m383_DvUp0;
  S_samhd_383_1.DvDw0 = &internal1_m383_DvDw0;
  S_samhd_383_1.FDvUp0 = &internal1_m383_FDvUp0;
  S_samhd_383_1.FDvDw0 = &internal1_m383_FDvDw0;
  S_samhd_383_1.BlDv0 = &internal1_m383_BlDv0;
  S_samhd_383_1.Pkv0 = &internal1_m383_Pkv0;
  S_samhd_383_1.Pkav0 = &internal1_m383_Pkav0;
  S_samhd_383_1.Zkv0 = &internal1_m383_Zkv0;
  S_samhd_383_1.Zkav0 = &internal1_m383_Zkav0;
  S_samhd_383_1.txNm = &internal1_m383_txNm;
  S_samhd_383_1.txSm = &internal1_m383_txSm;
  S_samhd_383_1.txHr = &internal1_m383_txHr;
  S_samhd_383_1.txLd = &internal1_m383_txLd;
  S_samhd_383_1.fef = &internal1_m383_fef;
  S_samhd_383_1.FirstEnterFlag = &bFirstEnterFlag;
  S_samhd_377_1.DvUp0 = &internal1_m377_DvUp0;
  S_samhd_377_1.DvDw0 = &internal1_m377_DvDw0;
  S_samhd_377_1.FDvUp0 = &internal1_m377_FDvUp0;
  S_samhd_377_1.FDvDw0 = &internal1_m377_FDvDw0;
  S_samhd_377_1.BlDv0 = &internal1_m377_BlDv0;
  S_samhd_377_1.Pkv0 = &internal1_m377_Pkv0;
  S_samhd_377_1.Pkav0 = &internal1_m377_Pkav0;
  S_samhd_377_1.Zkv0 = &internal1_m377_Zkv0;
  S_samhd_377_1.Zkav0 = &internal1_m377_Zkav0;
  S_samhd_377_1.txNm = &internal1_m377_txNm;
  S_samhd_377_1.txSm = &internal1_m377_txSm;
  S_samhd_377_1.txHr = &internal1_m377_txHr;
  S_samhd_377_1.txLd = &internal1_m377_txLd;
  S_samhd_377_1.fef = &internal1_m377_fef;
  S_samhd_377_1.FirstEnterFlag = &bFirstEnterFlag;
  S_rs_726_1.q0 = &internal1_m726_q0;
  S_rs_723_1.q0 = &internal1_m723_q0;
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
  S_abs_subf_2124_1.Delta = &fEM_A3UC08RDU;
  S_fsumo_79_1.x2 = &fEM_R0UN11RDU;
  S_bol_2188_1.x1 = &fEM_R0UN09RDU;
  S_irm_2131_1.Zn = &fEM_R0UN12RDU;
  S_irm_2131_1.MinDk = &fEM_R0UN13RDU;
  S_irm_2131_1.MaxKr = &fEM_R0UN14RDU;
  S_irm_2131_1.MaxTime = &fEM_R0UT20RDU;
  S_irm_2131_1.W2 = &fEM_R0UN15RDU;
  S_irm_2131_1.W3 = &fEM_R0UN25RDU;
  S_irm_2131_1.A1 = &fEM_R0UN16RDU;
  S_irm_2131_1.A0 = &fEM_R0UN17RDU;
  S_irm_2131_1.T1 = &fEM_R0UN18RDU;
  S_irm_2131_1.T0 = &fEM_R0UN19RDU;
  S_irm_2131_1.MT1 = &fEM_R0UN27RDU;
  S_irm_2131_1.MT0 = &fEM_R0UN26RDU;
  S_irm_2131_1.Nmin = &fEM_R0UN24RDU;
  S_abs_subf_1524_1.Delta = &fEM_A3UC07RDU;
  S_abs_subf_1505_1.Delta = &fEM_A3UC07RDU;
  S_abs_subf_1522_1.Delta = &fEM_A1UC07RDU;
  S_abs_subf_1501_1.Delta = &fEM_A1UC07RDU;
  S_bol_1292_1.x2 = &fEM_A3UC09RDU;
  S_bol_893_1.x2 = &fEM_A3UC09RDU;
  S_zpfs_1835_1.tz = &fEM_R0UL02RDU;
  S_zpfs_1833_1.tz = &fEM_R0UL02RDU;
  S_zpfs_1822_1.tz = &fEM_R0UL04RDU;
  S_abs_subf_1844_1.x1 = &fEM_R0UL02RDU;
  S_abs_subf_1844_1.Delta = &fEM_R0UL16RDU;
  S_abs_subf_1428_1.x1 = &fEM_R0UL05RDU;
  S_abs_subf_1428_1.Delta = &fEM_R0UL18RDU;
  S_abs_subf_1470_1.x1 = &fEM_R0UL07RDU;
  S_abs_subf_1470_1.Delta = &fEM_R0UL20RDU;
  S_abs_subf_1475_1.x1 = &fEM_R0UL25RDU;
  S_abs_subf_1475_1.Delta = &fEM_R0UL19RDU;
  S_abs_subf_1883_1.x2 = &fEM_R0UL03RDU;
  S_abs_subf_1883_1.Delta = &fEM_R0UL17RDU;
  S_zpfs_1859_1.tz = &fEM_R0UL21RDU;
  S_zpfs_1874_1.tz = &fEM_R0UL03RDU;
  S_zpfs_1871_1.tz = &fEM_R0UL03RDU;
  S_zpfs_1465_1.tz = &fEM_R0UL06RDU;
  S_zpfs_1415_1.tz = &fEM_R0UL04RDU;
  S_zpfs_821_1.tz = &fEM_A2UL83RDU;
  S_zpfs_193_1.tz = &fEM_A1UL03RDU;
  S_zpfs_512_1.tz = &fEM_A1UL03RDU;
  S_bol_1042_1.x2 = &fEM_R0UN80RDU;
  S_ovbs_2056_1.tz = &fEM_A9UZ04RDU;
  S_ovbs_1159_1.tz = &fEM_A4UZ04RDU;
  S_zpfs_1585_1.tz = &fEM_B8UL03RDU;
  S_zpfs_1125_1.tz = &fEM_B8UL03RDU;
  S_zpfs_1311_1.tz = &fEM_A3UL03RDU;
  S_zpfs_914_1.tz = &fEM_A3UL03RDU;
  S_zpfs_1220_1.tz = &fEM_A2UL03RDU;
  S_abs_subf_984_1.Delta = &fEM_B8UC01RDU;
  S_abs_subf_997_1.Delta = &fEM_B8UC01RDU;
  S_samhd_2061_1.tzNm = &fEM_A9UZ05RDU;
  S_samhd_2061_1.tzSm = &fEM_A9UZ03RDU;
  S_samhd_2061_1.tzLd = &fEM_A9UZ04RDU;
  S_samhd_2055_1.tzNm = &fEM_A9UZ05RDU;
  S_samhd_2055_1.tzSm = &fEM_A9UZ03RDU;
  S_samhd_2055_1.tzLd = &fEM_A9UZ04RDU;
  S_noto_991_1.x = &lEM_R0MD01LC1;
  S_cnshd_1282_1.Dlt = &fEM_A3UC08RDU;
  S_cnshd_1282_1.DltRet = &fEM_A3UC07RDU;
  S_cnshd_1282_1.Tim = &fEM_A3UL01RDU;
  S_cnshd_1282_1.Kpr = &fEM_A3UC02RDU;
  S_fnapb_1310_1.Trz = &fEM_B8UV04RDU;
  S_fnapb_1310_1.Delta = &fEM_A3UV01RDU;
  S_fnapb_1310_1.MDelta = &fEM_A3UV02RDU;
  S_fnapb_1310_1.p = &fEM_A3UC06RDU;
  S_fnapb_1310_1.pl = &fEM_A3UC05RDU;
  S_fnapb_1310_1.tz = &fEM_A3UL04RDU;
  S_fnapb_1310_1.tnm = &fEM_A3UL05RDU;
  S_fnapb_1310_1.tzZS = &fEM_A3UL03RDU;
  S_cnshd_880_1.Dlt = &fEM_A3UC08RDU;
  S_cnshd_880_1.DltRet = &fEM_A3UC07RDU;
  S_cnshd_880_1.Tim = &fEM_A3UL01RDU;
  S_cnshd_880_1.Kpr = &fEM_A3UC02RDU;
  S_fnapb_913_1.Trz = &fEM_B8UV04RDU;
  S_fnapb_913_1.Delta = &fEM_A3UV01RDU;
  S_fnapb_913_1.MDelta = &fEM_A3UV02RDU;
  S_fnapb_913_1.p = &fEM_A3UC06RDU;
  S_fnapb_913_1.pl = &fEM_A3UC05RDU;
  S_fnapb_913_1.tz = &fEM_A3UL04RDU;
  S_fnapb_913_1.tnm = &fEM_A3UL05RDU;
  S_fnapb_913_1.tzZS = &fEM_A3UL03RDU;
  S_cnshd_484_1.Dlt = &fEM_A1UC08RDU;
  S_cnshd_484_1.DltRet = &fEM_A1UC07RDU;
  S_cnshd_484_1.Tim = &fEM_A1UL01RDU;
  S_cnshd_484_1.Kpr = &fEM_A1UC02RDU;
  S_fnapb_511_1.Trz = &fEM_B8UV04RDU;
  S_fnapb_511_1.Delta = &fEM_A1UV01RDU;
  S_fnapb_511_1.MDelta = &fEM_A1UV02RDU;
  S_fnapb_511_1.p = &fEM_A1UC06RDU;
  S_fnapb_511_1.pl = &fEM_A1UC05RDU;
  S_fnapb_511_1.tz = &fEM_A1UL04RDU;
  S_fnapb_511_1.tnm = &fEM_A1UL05RDU;
  S_fnapb_511_1.tzZS = &fEM_A1UL03RDU;
  S_cnshd_163_1.Dlt = &fEM_A1UC08RDU;
  S_cnshd_163_1.DltRet = &fEM_A1UC07RDU;
  S_cnshd_163_1.Tim = &fEM_A1UL01RDU;
  S_cnshd_163_1.Kpr = &fEM_A1UC02RDU;
  S_fnapb_192_1.Trz = &fEM_B8UV04RDU;
  S_fnapb_192_1.Delta = &fEM_A1UV01RDU;
  S_fnapb_192_1.MDelta = &fEM_A1UV02RDU;
  S_fnapb_192_1.p = &fEM_A1UC06RDU;
  S_fnapb_192_1.pl = &fEM_A1UC05RDU;
  S_fnapb_192_1.tz = &fEM_A1UL04RDU;
  S_fnapb_192_1.tnm = &fEM_A1UL05RDU;
  S_fnapb_192_1.tzZS = &fEM_A1UL03RDU;
  S_samhd_455_1.tzNm = &fEM_R1UZ05RDU;
  S_samhd_455_1.tzSm = &fEM_R1UZ03RDU;
  S_samhd_455_1.tzLd = &fEM_R1UZ04RDU;
  S_samhd_449_1.tzNm = &fEM_R1UZ05RDU;
  S_samhd_449_1.tzSm = &fEM_R1UZ03RDU;
  S_samhd_449_1.tzLd = &fEM_R1UZ04RDU;
  S_cnshd_800_1.Dlt = &fEM_A2UC08RDU;
  S_cnshd_800_1.DltRet = &fEM_A2UC07RDU;
  S_cnshd_800_1.Tim = &fEM_A2UL01RDU;
  S_cnshd_800_1.Kpr = &fEM_A2UC02RDU;
  S_fnapb_820_1.Trz = &fEM_B8UV04RDU;
  S_fnapb_820_1.Delta = &fEM_A2UV01RDU;
  S_fnapb_820_1.MDelta = &fEM_A2UV02RDU;
  S_fnapb_820_1.p = &fEM_A2UC06RDU;
  S_fnapb_820_1.pl = &fEM_A2UC05RDU;
  S_fnapb_820_1.tz = &fEM_A2UL04RDU;
  S_fnapb_820_1.tnm = &fEM_A2UL05RDU;
  S_fnapb_820_1.tzZS = &fEM_A2UL83RDU;
  S_cnshd_1564_1.Dlt = &fEM_B8UC01RDU;
  S_cnshd_1564_1.DltRet = &fEM_B8UC02RDU;
  S_cnshd_1564_1.Tim = &fEM_B8UL01RDU;
  S_cnshd_1100_1.Dlt = &fEM_B8UC01RDU;
  S_cnshd_1100_1.DltRet = &fEM_B8UC02RDU;
  S_cnshd_1100_1.Tim = &fEM_B8UL01RDU;
  S_noto_595_1.x = &lEM_R0MD01LC1;
  S_cnshd_1185_1.Dlt = &fEM_A2UC08RDU;
  S_cnshd_1185_1.DltRet = &fEM_A2UC07RDU;
  S_cnshd_1185_1.Tim = &fEM_A2UL01RDU;
  S_cnshd_1185_1.Kpr = &fEM_A2UC02RDU;
  S_fnapb_1219_1.Trz = &fEM_B8UV04RDU;
  S_fnapb_1219_1.Delta = &fEM_A2UV01RDU;
  S_fnapb_1219_1.MDelta = &fEM_A2UV02RDU;
  S_fnapb_1219_1.p = &fEM_A2UC06RDU;
  S_fnapb_1219_1.pl = &fEM_A2UC05RDU;
  S_fnapb_1219_1.tz = &fEM_A2UL04RDU;
  S_fnapb_1219_1.tnm = &fEM_A2UL05RDU;
  S_fnapb_1219_1.tzZS = &fEM_A2UL03RDU;
  S_samhd_1567_1.tzNm = &fEM_B8UL05RDU;
  S_samhd_1567_1.tzSm = &fEM_B8UL03RDU;
  S_samhd_1567_1.tzLd = &fEM_B8UL07RDU;
  S_fnapb_1584_1.Vz = &fEM_B8UV03RDU;
  S_fnapb_1584_1.Trz = &fEM_B8UV04RDU;
  S_fnapb_1584_1.Delta = &fEM_B8UV01RDU;
  S_fnapb_1584_1.MDelta = &fEM_B8UV02RDU;
  S_fnapb_1584_1.p = &fEM_B8UC06RDU;
  S_fnapb_1584_1.pl = &fEM_B8UC05RDU;
  S_fnapb_1584_1.tz = &fEM_B8UL04RDU;
  S_fnapb_1584_1.tnm = &fEM_B8UL05RDU;
  S_fnapb_1584_1.tzZS = &fEM_B8UL03RDU;
  S_samhd_1106_1.tzNm = &fEM_B8UL05RDU;
  S_samhd_1106_1.tzSm = &fEM_B8UL03RDU;
  S_samhd_1106_1.tzLd = &fEM_B8UL07RDU;
  S_fnapb_1124_1.Vz = &fEM_B8UV03RDU;
  S_fnapb_1124_1.Trz = &fEM_B8UV04RDU;
  S_fnapb_1124_1.Delta = &fEM_B8UV01RDU;
  S_fnapb_1124_1.MDelta = &fEM_B8UV02RDU;
  S_fnapb_1124_1.p = &fEM_B8UC06RDU;
  S_fnapb_1124_1.pl = &fEM_B8UC05RDU;
  S_fnapb_1124_1.tz = &fEM_B8UL04RDU;
  S_fnapb_1124_1.tnm = &fEM_B8UL06RDU;
  S_fnapb_1124_1.tzZS = &fEM_B8UL03RDU;
  S_samhd_1161_1.tzNm = &fEM_A4UZ05RDU;
  S_samhd_1161_1.tzSm = &fEM_A4UZ03RDU;
  S_samhd_1161_1.tzLd = &fEM_A4UZ04RDU;
  S_samhd_1151_1.tzNm = &fEM_A4UZ05RDU;
  S_samhd_1151_1.tzSm = &fEM_A4UZ03RDU;
  S_samhd_1151_1.tzLd = &fEM_A4UZ04RDU;
  S_samhd_774_1.tzNm = &fEM_A5UZ05RDU;
  S_samhd_774_1.tzSm = &fEM_A5UZ03RDU;
  S_samhd_774_1.tzLd = &fEM_A5UZ04RDU;
  S_samhd_770_1.tzNm = &fEM_A5UZ05RDU;
  S_samhd_770_1.tzSm = &fEM_A5UZ03RDU;
  S_samhd_770_1.tzLd = &fEM_A5UZ04RDU;
  S_samhd_354_1.tzNm = &fEM_R4UZ05RDU;
  S_samhd_354_1.tzSm = &fEM_R4UZ03RDU;
  S_samhd_354_1.tzLd = &fEM_R4UZ04RDU;
  S_samhd_383_1.tzNm = &fEM_A6UZ05RDU;
  S_samhd_383_1.tzSm = &fEM_A6UZ03RDU;
  S_samhd_383_1.tzLd = &fEM_A6UZ04RDU;
  S_samhd_377_1.tzNm = &fEM_A6UZ05RDU;
  S_samhd_377_1.tzSm = &fEM_A6UZ03RDU;
  S_samhd_377_1.tzLd = &fEM_A6UZ04RDU;
  for( i=0;i<10;i++ )
    array_m320_rz_1[i] = &(&internal1_m320_rz)[i];
  for( i=0;i<10;i++ )
    array_m263_rz_1[i] = &(&internal1_m263_rz)[i];
  for( i=0;i<6;i++ )
    array_m1383_rz_1[i] = &(&internal1_m1383_rz)[i];
  for( i=0;i<60;i++ )
    array_m1310_x0_1[i] = &(&internal1_m1310_x0)[i];
  for( i=0;i<60;i++ )
    array_m1310_tim0_1[i] = &(&internal1_m1310_tim0)[i];
  for( i=0;i<60;i++ )
    array_m913_x0_1[i] = &(&internal1_m913_x0)[i];
  for( i=0;i<60;i++ )
    array_m913_tim0_1[i] = &(&internal1_m913_tim0)[i];
  for( i=0;i<150;i++ )
    array_m511_x0_1[i] = &(&internal1_m511_x0)[i];
  for( i=0;i<150;i++ )
    array_m511_tim0_1[i] = &(&internal1_m511_tim0)[i];
  for( i=0;i<150;i++ )
    array_m192_x0_1[i] = &(&internal1_m192_x0)[i];
  for( i=0;i<150;i++ )
    array_m192_tim0_1[i] = &(&internal1_m192_tim0)[i];
  for( i=0;i<80;i++ )
    array_m820_x0_1[i] = &(&internal1_m820_x0)[i];
  for( i=0;i<80;i++ )
    array_m820_tim0_1[i] = &(&internal1_m820_tim0)[i];
  for( i=0;i<80;i++ )
    array_m1219_x0_1[i] = &(&internal1_m1219_x0)[i];
  for( i=0;i<80;i++ )
    array_m1219_tim0_1[i] = &(&internal1_m1219_tim0)[i];
  for( i=0;i<20;i++ )
    array_m1584_x0_1[i] = &(&internal1_m1584_x0)[i];
  for( i=0;i<20;i++ )
    array_m1584_tim0_1[i] = &(&internal1_m1584_tim0)[i];
  for( i=0;i<20;i++ )
    array_m1124_x0_1[i] = &(&internal1_m1124_x0)[i];
  for( i=0;i<20;i++ )
    array_m1124_tim0_1[i] = &(&internal1_m1124_tim0)[i];
  array_m2153_a_1[0] = &fEM_R0UN70LDU;
  array_m2153_a_1[1] = &fEM_R0UN71LDU;
  array_m2153_a_1[2] = &fEM_R0UN72LDU;
  array_m2153_a_1[3] = &fEM_R0UN73LDU;
  array_m2153_a_1[4] = &fEM_R0UN74LDU;
  array_m2153_a_1[5] = &fEM_R0UN75LDU;
  array_m2153_b_1[0] = &fEM_R0UN80LDU;
  array_m2153_b_1[1] = &fEM_R0UN81LDU;
  array_m2153_b_1[2] = &fEM_R0UN82LDU;
  array_m2153_b_1[3] = &fEM_R0UN83LDU;
  array_m2153_b_1[4] = &fEM_R0UN84LDU;
  array_m2153_b_1[5] = &fEM_R0UN85LDU;
  array_m83_x_1[0] = &fEM_R0UN01RDU;
  array_m83_x_1[1] = &fEM_R0UN02RDU;
  array_m83_x_1[2] = &fEM_R0UN03RDU;
  array_m83_x_1[3] = &fEM_R0UN04RDU;
  array_m83_x_1[4] = &fEM_R0UN05RDU;
  array_m83_x_1[5] = &fEM_R0UN06RDU;
  array_m83_x_1[6] = &fEM_R0UN07RDU;
  array_m83_x_1[7] = &fEM_R0UN08RDU;
  array_m1282_Lt_fw_1[0] = &fEM_A3UC81RDU;
  array_m1282_Vr_fw_1[0] = &iEM_A3UV01IDU;
  array_m1282_Lt_bw_1[0] = &fEM_A3UC82RDU;
  array_m1282_Vr_bw_1[0] = &iEM_A3UV02IDU;
  array_m880_Lt_fw_1[0] = &fEM_A3UC81RDU;
  array_m880_Vr_fw_1[0] = &iEM_A3UV01IDU;
  array_m880_Lt_bw_1[0] = &fEM_A3UC82RDU;
  array_m880_Vr_bw_1[0] = &iEM_A3UV02IDU;
  array_m484_Lt_fw_1[0] = &fEM_A1UC81RDU;
  array_m484_Lt_fw_1[1] = &fEM_A1UC82RDU;
  array_m484_Vr_fw_1[0] = &iEM_A1UV01IDU;
  array_m484_Vr_fw_1[1] = &iEM_A1UV02IDU;
  array_m484_Lt_bw_1[0] = &fEM_A1UC83RDU;
  array_m484_Vr_bw_1[0] = &iEM_A1UV03IDU;
  array_m163_Lt_fw_1[0] = &fEM_A1UC81RDU;
  array_m163_Lt_fw_1[1] = &fEM_A1UC82RDU;
  array_m163_Vr_fw_1[0] = &iEM_A1UV01IDU;
  array_m163_Vr_fw_1[1] = &iEM_A1UV02IDU;
  array_m163_Lt_bw_1[0] = &fEM_A1UC83RDU;
  array_m163_Vr_bw_1[0] = &iEM_A1UV03IDU;
  array_m800_Lt_fw_1[0] = &fEM_A2UC81RDU;
  array_m800_Lt_fw_1[1] = &fEM_A2UC82RDU;
  array_m800_Vr_fw_1[0] = &iEM_A2UV01IDU;
  array_m800_Vr_fw_1[1] = &iEM_A2UV02IDU;
  array_m800_Lt_bw_1[0] = &fEM_A2UC83RDU;
  array_m800_Vr_bw_1[0] = &iEM_A2UV03CDU;
  array_m1185_Lt_fw_1[0] = &fEM_A2UC81RDU;
  array_m1185_Lt_fw_1[1] = &fEM_A2UC82RDU;
  array_m1185_Vr_fw_1[0] = &iEM_A2UV01IDU;
  array_m1185_Vr_fw_1[1] = &iEM_A2UV02IDU;
  array_m1185_Lt_bw_1[0] = &fEM_A2UC83RDU;
  array_m1185_Vr_bw_1[0] = &iEM_A2UV03CDU;
}
