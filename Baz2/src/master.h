#ifndef BAZ2_H
#define BAZ2_H
// Подсистема Baz2:Baz2
static char SimulOn=0;
static short CodeSub=6;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt, taktScheme=0, taktSS=0;
#define SIZE_BUFFER 649
static char BUFFER[649];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.54\0", 5432, "192.168.10.154\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define A1VN71LS4	 BUFFER[0]	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
#define idA1VN71LS4	 1	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
#define A1VN71LZ2	 BUFFER[2]	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
#define idA1VN71LZ2	 2	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
#define R0MD34LP1	 BUFFER[4]	//( - , Baz2) Кнопка Квитировать
#define idR0MD34LP1	 3	//( - , Baz2) Кнопка Квитировать
#define R0AD04LZ2	 BUFFER[6]	//(vds32:05 - K08VDSR, - ) Имитация срабатывания АС II УР рад (БАЗ2)
#define idR0AD04LZ2	 4	//(vds32:05 - K08VDSR, - ) Имитация срабатывания АС II УР рад (БАЗ2)
#define R0VN71LZ2	 BUFFER[8]	//(vds32:05 - K01VDSR, Baz2) АС по мощности канал 1
#define idR0VN71LZ2	 5	//(vds32:05 - K01VDSR, Baz2) АС по мощности канал 1
#define R0VN75LZ2	 BUFFER[10]	//(vds32:05 - K02VDSR, Baz2) АС по периоду разгона канал 1
#define idR0VN75LZ2	 6	//(vds32:05 - K02VDSR, Baz2) АС по периоду разгона канал 1
#define R0VN72LZ2	 BUFFER[12]	//(vds32:06 - K01VDSR, Baz2) АС по мощности канал 2
#define idR0VN72LZ2	 7	//(vds32:06 - K01VDSR, Baz2) АС по мощности канал 2
#define R0VN76LZ2	 BUFFER[14]	//(vds32:06 - K02VDSR, Baz2) АС по периоду разгона канал  2
#define idR0VN76LZ2	 8	//(vds32:06 - K02VDSR, Baz2) АС по периоду разгона канал  2
#define R0VN73LZ2	 BUFFER[16]	//(vds32:08 - K01VDSR, Baz2) АС по мощности канал 3
#define idR0VN73LZ2	 9	//(vds32:08 - K01VDSR, Baz2) АС по мощности канал 3
#define R0VN74LZ2	 BUFFER[18]	//(vds32:07 - K01VDSR, Baz2) АС по мощности канал 4
#define idR0VN74LZ2	 10	//(vds32:07 - K01VDSR, Baz2) АС по мощности канал 4
#define R0VN77LZ2	 BUFFER[20]	//(vds32:08 - K02VDSR, Baz2) АС по периоду разгона канал  3
#define idR0VN77LZ2	 11	//(vds32:08 - K02VDSR, Baz2) АС по периоду разгона канал  3
#define R0VN78LZ2	 BUFFER[22]	//(vds32:07 - K02VDSR, Baz2) АС по периоду разгона канал  4
#define idR0VN78LZ2	 12	//(vds32:07 - K02VDSR, Baz2) АС по периоду разгона канал  4
#define R0EE01LZ2	 BUFFER[24]	//( - , MBz2S) Питание  АКНП1  отключить
#define idR0EE01LZ2	 13	//( - , MBz2S) Питание  АКНП1  отключить
#define R0EE02LZ2	 BUFFER[26]	//( - , MBz2S) Питание  АКНП2  отключить
#define idR0EE02LZ2	 14	//( - , MBz2S) Питание  АКНП2  отключить
#define R0EE03LZ2	 BUFFER[28]	//( - , MBz2S) Питание  АКНП3  отключить
#define idR0EE03LZ2	 15	//( - , MBz2S) Питание  АКНП3  отключить
#define R0EE04LZ2	 BUFFER[30]	//( - , MBz2S) Питание  АКНП4  отключить
#define idR0EE04LZ2	 16	//( - , MBz2S) Питание  АКНП4  отключить
#define R0MW12IP2	 BUFFER[32]	//( - , Baz2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define idR0MW12IP2	 17	//( - , Baz2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define A2IS12LDU	 BUFFER[35]	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	 18	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define B2IS12LDU	 BUFFER[37]	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	 19	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define A0EE07LZ2	 BUFFER[39]	//( - , Baz2) Исправность сети АКНП3
#define idA0EE07LZ2	 20	//( - , Baz2) Исправность сети АКНП3
#define A0EE08LZ2	 BUFFER[41]	//( - , Baz2) Исправность сети АКНП4
#define idA0EE08LZ2	 21	//( - , Baz2) Исправность сети АКНП4
#define A0VZ71LZ2	 BUFFER[43]	//( - , Baz2) Обобщенный сигнал АС по АЗ1
#define idA0VZ71LZ2	 22	//( - , Baz2) Обобщенный сигнал АС по АЗ1
#define A0EE00LZ2	 BUFFER[45]	//( - , Baz2) Исправность АКНП АЗ1
#define idA0EE00LZ2	 23	//( - , Baz2) Исправность АКНП АЗ1
#define B0EE00LZ2	 BUFFER[47]	//( - , Baz2) Исправность АКНП АЗ2
#define idB0EE00LZ2	 24	//( - , Baz2) Исправность АКНП АЗ2
#define B0VZ71LZ2	 BUFFER[49]	//( - , Baz2) Обобщенный сигнал АС по АЗ2
#define idB0VZ71LZ2	 25	//( - , Baz2) Обобщенный сигнал АС по АЗ2
#define A0VN71LZ2	 BUFFER[51]	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ1
#define idA0VN71LZ2	 26	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ1
#define B0VN71LZ2	 BUFFER[53]	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ2
#define idB0VN71LZ2	 27	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ2
#define A0VN81LZ2	 BUFFER[55]	//( - , Baz2) АЗ по АС периода разгона АЗ1
#define idA0VN81LZ2	 28	//( - , Baz2) АЗ по АС периода разгона АЗ1
#define B0VN81LZ2	 BUFFER[57]	//( - , Baz2) АЗ по АС периода разгона АЗ2
#define idB0VN81LZ2	 29	//( - , Baz2) АЗ по АС периода разгона АЗ2
#define R0VZ05UZ2	 BUFFER[59]	//( - , Baz2) Индикатор причины сброса
#define idR0VZ05UZ2	 30	//( - , Baz2) Индикатор причины сброса
#define R0VN11RZ2	 BUFFER[64]	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ1
#define idR0VN11RZ2	 31	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ1
#define R0VP73LZ2	 BUFFER[69]	//( - , Baz2, SBz2DU) ПС давления для РУ
#define idR0VP73LZ2	 32	//( - , Baz2, SBz2DU) ПС давления для РУ
#define B0CT01IZ2	 BUFFER[71]	//( - , Baz2, SBz2DU) Температура АЗ2-1
#define idB0CT01IZ2	 33	//( - , Baz2, SBz2DU) Температура АЗ2-1
#define B0VT61LZ2	 BUFFER[76]	//( - , Baz2) ПС по температуре в АЗ2
#define idB0VT61LZ2	 34	//( - , Baz2) ПС по температуре в АЗ2
#define B0VT71LZ2	 BUFFER[78]	//( - , Baz2, SBz2DU) АС по температуре в АЗ2
#define idB0VT71LZ2	 35	//( - , Baz2, SBz2DU) АС по температуре в АЗ2
#define A1VN71LS1	 BUFFER[80]	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
#define idA1VN71LS1	 36	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
#define A1VN71LS2	 BUFFER[82]	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
#define idA1VN71LS2	 37	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
#define A1VN71LS3	 BUFFER[84]	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
#define idA1VN71LS3	 38	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
#define R0AD03LZ2	 BUFFER[86]	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define idR0AD03LZ2	 39	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define B3IS11LDU	 BUFFER[88]	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define idB3IS11LDU	 40	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define A3VZ31LZ2	 BUFFER[90]	//( - , Baz2) АЗ от ВУ ИС1
#define idA3VZ31LZ2	 41	//( - , Baz2) АЗ от ВУ ИС1
#define B3VZ31LZ2	 BUFFER[92]	//( - , Baz2) АЗ от ВУ ИС2
#define idB3VZ31LZ2	 42	//( - , Baz2) АЗ от ВУ ИС2
#define R0AD05LZ2	 BUFFER[94]	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define idR0AD05LZ2	 43	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define A3VZ11LZ2	 BUFFER[96]	//( - , Baz2) АЗ от НУП ИС1
#define idA3VZ11LZ2	 44	//( - , Baz2) АЗ от НУП ИС1
#define B3VZ11LZ2	 BUFFER[98]	//( - , Baz2) АЗ от НУП ИС2
#define idB3VZ11LZ2	 45	//( - , Baz2) АЗ от НУП ИС2
#define B3IS22LDU	 BUFFER[100]	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
#define idB3IS22LDU	 46	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
#define A3VZ15LZ2	 BUFFER[102]	//(fds16:0a - K02FDSR, Baz2) Имитация АЗ от НУП ИС
#define idA3VZ15LZ2	 47	//(fds16:0a - K02FDSR, Baz2) Имитация АЗ от НУП ИС
#define A3VZ13LZ2	 BUFFER[104]	//(fds16:0a - K01FDSR, Baz2) Имитация АЗ от ВУ ИС
#define idA3VZ13LZ2	 48	//(fds16:0a - K01FDSR, Baz2) Имитация АЗ от ВУ ИС
#define R7II73LZ2	 BUFFER[106]	//(vds32:08 - K07VDSR, Baz2) Сработала АС II УР РАД
#define idR7II73LZ2	 49	//(vds32:08 - K07VDSR, Baz2) Сработала АС II УР РАД
#define R7II71LZ2	 BUFFER[108]	//(vds32:08 - K05VDSR, Baz2) Сработала АС IУР РАД (датчик 1)
#define idR7II71LZ2	 50	//(vds32:08 - K05VDSR, Baz2) Сработала АС IУР РАД (датчик 1)
#define R7II72LZ2	 BUFFER[110]	//(vds32:08 - K06VDSR, Baz2) Сработала АС IУР РАД  (датчик 2)
#define idR7II72LZ2	 51	//(vds32:08 - K06VDSR, Baz2) Сработала АС IУР РАД  (датчик 2)
#define R0AD14LZ2	 BUFFER[112]	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define idR0AD14LZ2	 52	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define R0AD21LDU	 BUFFER[114]	//( - , SBz2DU) Подключить защиту от II УР
#define idR0AD21LDU	 53	//( - , SBz2DU) Подключить защиту от II УР
#define R6IS66LZZ	 BUFFER[116]	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 54	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[118]	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 55	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[120]	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 56	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define R0S01LZ2	 BUFFER[122]	//(vds32:08 - K08VDSR, - ) Отключение сетевых передач в Баз2
#define idR0S01LZ2	 57	//(vds32:08 - K08VDSR, - ) Отключение сетевых передач в Баз2
#define R0EE02LDU	 BUFFER[124]	//( - , Baz2) Питание  АКНП  отключить
#define idR0EE02LDU	 58	//( - , Baz2) Питание  АКНП  отключить
#define R0DE04LZ2	 BUFFER[126]	//(vas84:04 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 4 месте
#define idR0DE04LZ2	 59	//(vas84:04 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 4 месте
#define R0DE05LZ2	 BUFFER[129]	//(vds32:05 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 5 месте
#define idR0DE05LZ2	 60	//(vds32:05 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 5 месте
#define R0DE06LZ2	 BUFFER[132]	//(vds32:06 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 6 месте
#define idR0DE06LZ2	 61	//(vds32:06 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 6 месте
#define R0DE07LZ2	 BUFFER[135]	//(vds32:07 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 7 месте
#define idR0DE07LZ2	 62	//(vds32:07 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 7 месте
#define R0DE0ALZ2	 BUFFER[138]	//(fds16:0a - Diagn, DiagnBaz2) диагностика модуля Баз2 на 10 месте
#define idR0DE0ALZ2	 63	//(fds16:0a - Diagn, DiagnBaz2) диагностика модуля Баз2 на 10 месте
#define R0DE08LZ2	 BUFFER[141]	//(vds32:08 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 8 месте
#define idR0DE08LZ2	 64	//(vds32:08 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 8 месте
#define TTLBaz2	 BUFFER[144]	//( - , Baz2) ttl
#define idTTLBaz2	 65	//( - , Baz2) ttl
#define R0DEB1LZ2	 BUFFER[147]	//(sbk:20 - S10SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 5
#define idR0DEB1LZ2	 66	//(sbk:20 - S10SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 5
#define R0DEB2LZ2	 BUFFER[149]	//(sbk:20 - S11SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 5
#define idR0DEB2LZ2	 67	//(sbk:20 - S11SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 5
#define R0DEB3LZ2	 BUFFER[151]	//(sbk:20 - S12SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 6
#define idR0DEB3LZ2	 68	//(sbk:20 - S12SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 6
#define R0DEB4LZ2	 BUFFER[153]	//(sbk:20 - S13SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 6
#define idR0DEB4LZ2	 69	//(sbk:20 - S13SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 6
#define R0DE3CLZ2	 BUFFER[155]	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 5
#define idR0DE3CLZ2	 70	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 5
#define R0DE3DLZ2	 BUFFER[157]	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 6
#define idR0DE3DLZ2	 71	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 6
#define TestDiagnBaz2	 BUFFER[159]	//( - , Baz2) Неисправность от
#define idTestDiagnBaz2	 72	//( - , Baz2) Неисправность от
#define R0MW11IP1	 BUFFER[161]	//( - , Baz2) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 73	//( - , Baz2) Переключатель ВЫСТРЕЛ
#define R0VZ05U	 BUFFER[164]	//( - , - ) причины сброса
#define idR0VZ05U	 74	//( - , - ) причины сброса
#define B8VC01RDU	 BUFFER[169]	//( - , SBz2DU, MBz2A1, MBz2A2, MBz2A3, MBz2A4) Координата АЗ2, мм
#define idB8VC01RDU	 75	//( - , SBz2DU, MBz2A1, MBz2A2, MBz2A3, MBz2A4) Координата АЗ2, мм
#define A3IS11LDU	 BUFFER[174]	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define idA3IS11LDU	 76	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define A3IS22LDU	 BUFFER[176]	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define idA3IS22LDU	 77	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define A0VP41LZ2	 BUFFER[178]	//( - , Baz2) Давление АЗ1 ниже АС
#define idA0VP41LZ2	 78	//( - , Baz2) Давление АЗ1 ниже АС
#define B0VP41LZ2	 BUFFER[180]	//( - , Baz2) Давление АЗ2 ниже АС
#define idB0VP41LZ2	 79	//( - , Baz2) Давление АЗ2 ниже АС
#define B0VP81LZZ	 BUFFER[182]	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	 80	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define A0VP81LZZ	 BUFFER[184]	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define idA0VP81LZZ	 81	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define R0ET02LZ2	 BUFFER[186]	//( - , Baz2) Признак наличия неисправности по температуре АЗ2
#define idR0ET02LZ2	 82	//( - , Baz2) Признак наличия неисправности по температуре АЗ2
#define B0EP02IZ2	 BUFFER[188]	//( - , Baz2) Индикатор -Давление  АЗ2 ниже АС
#define idB0EP02IZ2	 83	//( - , Baz2) Индикатор -Давление  АЗ2 ниже АС
#define A0EP02IZ2	 BUFFER[191]	//( - , Baz2) Индикатор -Давление  АЗ1 ниже АС
#define idA0EP02IZ2	 84	//( - , Baz2) Индикатор -Давление  АЗ1 ниже АС
#define A0VP71LZ2	 BUFFER[194]	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ2	 85	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
#define B0VP71LZ2	 BUFFER[196]	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ2	 86	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
#define R0VN02RS1	 BUFFER[198]	//( - , MBz2A1) Уровень мощности канал 1
#define idR0VN02RS1	 87	//( - , MBz2A1) Уровень мощности канал 1
#define R0VN02RS2	 BUFFER[203]	//( - , MBz2A2) Уровень мощности канал 2
#define idR0VN02RS2	 88	//( - , MBz2A2) Уровень мощности канал 2
#define R0VN02RS3	 BUFFER[208]	//( - , MBz2A3) Уровень мощности канал 3
#define idR0VN02RS3	 89	//( - , MBz2A3) Уровень мощности канал 3
#define R0VN02RS4	 BUFFER[213]	//( - , MBz2A4) Уровень мощности канал 4
#define idR0VN02RS4	 90	//( - , MBz2A4) Уровень мощности канал 4
#define R0VN01RS1	 BUFFER[218]	//( - , MBz2A1) Период разгона канал 1
#define idR0VN01RS1	 91	//( - , MBz2A1) Период разгона канал 1
#define R0VN01RS2	 BUFFER[223]	//( - , MBz2A2) Период разгона канал 2
#define idR0VN01RS2	 92	//( - , MBz2A2) Период разгона канал 2
#define R0VN01RS3	 BUFFER[228]	//( - , MBz2A3) Период разгона канал 3
#define idR0VN01RS3	 93	//( - , MBz2A3) Период разгона канал 3
#define R0VN01RS4	 BUFFER[233]	//( - , MBz2A4) Период разгона канал 4
#define idR0VN01RS4	 94	//( - , MBz2A4) Период разгона канал 4
#define R0VN61LS1	 BUFFER[238]	//( - , MBz2A1) ПС по мощности канал 1
#define idR0VN61LS1	 95	//( - , MBz2A1) ПС по мощности канал 1
#define R0VN61LS2	 BUFFER[240]	//( - , MBz2A2) ПС по мощности канал 2
#define idR0VN61LS2	 96	//( - , MBz2A2) ПС по мощности канал 2
#define A0IT02IZ2	 BUFFER[242]	//(vas84:04 - K01VASR, - ) Температура АЗ1-2
#define idA0IT02IZ2	 97	//(vas84:04 - K01VASR, - ) Температура АЗ1-2
#define A0CT01IZ2	 BUFFER[245]	//( - , Baz2, SBz2DU) Температура АЗ1-1
#define idA0CT01IZ2	 98	//( - , Baz2, SBz2DU) Температура АЗ1-1
#define A0VT61LZ2	 BUFFER[250]	//( - , Baz2) ПС по температуре в АЗ1
#define idA0VT61LZ2	 99	//( - , Baz2) ПС по температуре в АЗ1
#define A0VT71LZ2	 BUFFER[252]	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
#define idA0VT71LZ2	 100	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
#define A1VP41LZ2	 BUFFER[254]	//( - , Baz2, SBz2DU) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ2	 101	//( - , Baz2, SBz2DU) Давление СБРОС ББ1 ниже АС
#define B1VP41LZ2	 BUFFER[256]	//( - , Baz2, SBz2DU) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ2	 102	//( - , Baz2, SBz2DU) Давление СБРОС ББ2 ниже АС
#define B1VP81LZZ	 BUFFER[258]	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	 103	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define A1VP81LZZ	 BUFFER[260]	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	 104	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define A2VP41LZ2	 BUFFER[262]	//( - , Baz2) Давление СБРОС РБ1 ниже АС
#define idA2VP41LZ2	 105	//( - , Baz2) Давление СБРОС РБ1 ниже АС
#define A2CP01RZ2	 BUFFER[264]	//( - , Baz2) Текущее давление СБРОС РБ1
#define idA2CP01RZ2	 106	//( - , Baz2) Текущее давление СБРОС РБ1
#define A2VP51LZ2	 BUFFER[269]	//( - , Baz2) Давление СБРОС РБ1 ниже ПС
#define idA2VP51LZ2	 107	//( - , Baz2) Давление СБРОС РБ1 ниже ПС
#define B2VP41LZ2	 BUFFER[271]	//( - , Baz2) Давление СБРОС РБ2 ниже АС
#define idB2VP41LZ2	 108	//( - , Baz2) Давление СБРОС РБ2 ниже АС
#define B2CP01RZ2	 BUFFER[273]	//( - , Baz2) Текущее давление СБРОС РБ2
#define idB2CP01RZ2	 109	//( - , Baz2) Текущее давление СБРОС РБ2
#define B2VP51LZ2	 BUFFER[278]	//( - , Baz2) Давление СБРОС РБ2 ниже ПС
#define idB2VP51LZ2	 110	//( - , Baz2) Давление СБРОС РБ2 ниже ПС
#define B2VP81LZ2	 BUFFER[280]	//( - , Baz2) Давление СБРОС РБ2 в норме
#define idB2VP81LZ2	 111	//( - , Baz2) Давление СБРОС РБ2 в норме
#define A2VP81LZ2	 BUFFER[282]	//( - , Baz2) Давление СБРОС РБ1 в норме
#define idA2VP81LZ2	 112	//( - , Baz2) Давление СБРОС РБ1 в норме
#define A2IP01IZ2	 BUFFER[284]	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ2	 113	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define B2IP01IZ2	 BUFFER[287]	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ2	 114	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define R0ET01LZ2	 BUFFER[290]	//( - , Baz2) Признак наличия неисправности по температуре  АЗ1
#define idR0ET01LZ2	 115	//( - , Baz2) Признак наличия неисправности по температуре  АЗ1
#define B0IT02IZ2	 BUFFER[292]	//(vas84:04 - K03VASR, - ) Температура АЗ2-2
#define idB0IT02IZ2	 116	//(vas84:04 - K03VASR, - ) Температура АЗ2-2
#define R0VN67LZ2	 BUFFER[295]	//( - , Baz2) ПС по периоду разгона канал 3
#define idR0VN67LZ2	 117	//( - , Baz2) ПС по периоду разгона канал 3
#define R0VN68LZ2	 BUFFER[297]	//( - , Baz2) ПС по периоду разгона канал 4
#define idR0VN68LZ2	 118	//( - , Baz2) ПС по периоду разгона канал 4
#define R0VN09RZ2	 BUFFER[299]	//( - , Baz2) Усредненный период разгона
#define idR0VN09RZ2	 119	//( - , Baz2) Усредненный период разгона
#define R0VN69LZ2	 BUFFER[304]	//( - , Baz2) ПС по усредненному периоду
#define idR0VN69LZ2	 120	//( - , Baz2) ПС по усредненному периоду
#define R0VN79LZ2	 BUFFER[306]	//( - , Baz2) АС по усредненному периоду
#define idR0VN79LZ2	 121	//( - , Baz2) АС по усредненному периоду
#define R0VR02RZ2	 BUFFER[308]	//( - , Baz2) Усредненная реактивность
#define idR0VR02RZ2	 122	//( - , Baz2) Усредненная реактивность
#define R0VZ71LZ2	 BUFFER[313]	//(fds16:0a - K05FDSR, Baz2) Обобщенный сигнал АЗ 2 канала
#define idR0VZ71LZ2	 123	//(fds16:0a - K05FDSR, Baz2) Обобщенный сигнал АЗ 2 канала
#define R0VN70LZ2	 BUFFER[315]	//( - , Baz2) АЗ по АС мощности РУ
#define idR0VN70LZ2	 124	//( - , Baz2) АЗ по АС мощности РУ
#define R0VN80LZ2	 BUFFER[317]	//( - , Baz2) АЗ по АС периода разгона РУ
#define idR0VN80LZ2	 125	//( - , Baz2) АЗ по АС периода разгона РУ
#define A1EE01LS1	 BUFFER[319]	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define idA1EE01LS1	 126	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define A1EE01LS4	 BUFFER[321]	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define idA1EE01LS4	 127	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define A1EE01LS3	 BUFFER[323]	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define idA1EE01LS3	 128	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define A0EE01LZ2	 BUFFER[325]	//( - , Baz2, SBz2DU) Исправность АКНП1
#define idA0EE01LZ2	 129	//( - , Baz2, SBz2DU) Исправность АКНП1
#define A0EE04LZ2	 BUFFER[327]	//( - , Baz2, SBz2DU) Исправность АКНП4
#define idA0EE04LZ2	 130	//( - , Baz2, SBz2DU) Исправность АКНП4
#define A0EE02LZ2	 BUFFER[329]	//( - , Baz2, SBz2DU) Исправность АКНП2
#define idA0EE02LZ2	 131	//( - , Baz2, SBz2DU) Исправность АКНП2
#define A0EE03LZ2	 BUFFER[331]	//( - , Baz2, SBz2DU) Исправность АКНП3
#define idA0EE03LZ2	 132	//( - , Baz2, SBz2DU) Исправность АКНП3
#define A1EE01LS2	 BUFFER[333]	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define idA1EE01LS2	 133	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define A0EE05LZ2	 BUFFER[335]	//( - , Baz2) Исправность сети АКНП1
#define idA0EE05LZ2	 134	//( - , Baz2) Исправность сети АКНП1
#define A0EE06LZ2	 BUFFER[337]	//( - , Baz2) Исправность сети АКНП2
#define idA0EE06LZ2	 135	//( - , Baz2) Исправность сети АКНП2
#define R0VN61LS3	 BUFFER[339]	//( - , MBz2A3) ПС по мощности канал 3
#define idR0VN61LS3	 136	//( - , MBz2A3) ПС по мощности канал 3
#define R0VN61LS4	 BUFFER[341]	//( - , MBz2A4) ПС по мощности канал 4
#define idR0VN61LS4	 137	//( - , MBz2A4) ПС по мощности канал 4
#define R0VN65LS1	 BUFFER[343]	//( - , MBz2A1) ПС по периоду разгона канал 1
#define idR0VN65LS1	 138	//( - , MBz2A1) ПС по периоду разгона канал 1
#define R0VN65LS2	 BUFFER[345]	//( - , MBz2A2) ПС по периоду разгона  канал 2
#define idR0VN65LS2	 139	//( - , MBz2A2) ПС по периоду разгона  канал 2
#define R0VN65LS3	 BUFFER[347]	//( - , MBz2A3) ПС по периоду разгона канал 3
#define idR0VN65LS3	 140	//( - , MBz2A3) ПС по периоду разгона канал 3
#define R0VN65LS4	 BUFFER[349]	//( - , MBz2A4) ПС по периоду разгона канал 4
#define idR0VN65LS4	 141	//( - , MBz2A4) ПС по периоду разгона канал 4
#define R0VN01RZ2	 BUFFER[351]	//( - , Baz2) Уровень мощности по каналу 1
#define idR0VN01RZ2	 142	//( - , Baz2) Уровень мощности по каналу 1
#define R0VN02RZ2	 BUFFER[356]	//( - , Baz2) Уровень мощности по каналу 2
#define idR0VN02RZ2	 143	//( - , Baz2) Уровень мощности по каналу 2
#define R0VN03RZ2	 BUFFER[361]	//( - , Baz2) Уровень мощности по каналу 3
#define idR0VN03RZ2	 144	//( - , Baz2) Уровень мощности по каналу 3
#define R0VN04RZ2	 BUFFER[366]	//( - , Baz2) Уровень мощности по каналу 4
#define idR0VN04RZ2	 145	//( - , Baz2) Уровень мощности по каналу 4
#define R0VN05RZ2	 BUFFER[371]	//( - , Baz2) Период разгона по каналу 1
#define idR0VN05RZ2	 146	//( - , Baz2) Период разгона по каналу 1
#define R0VN06RZ2	 BUFFER[376]	//( - , Baz2) Период разгона по каналу 2
#define idR0VN06RZ2	 147	//( - , Baz2) Период разгона по каналу 2
#define R0VN07RZ2	 BUFFER[381]	//( - , Baz2) Период разгона по каналу 3
#define idR0VN07RZ2	 148	//( - , Baz2) Период разгона по каналу 3
#define R0VN08RZ2	 BUFFER[386]	//( - , Baz2) Период разгона по каналу 4
#define idR0VN08RZ2	 149	//( - , Baz2) Период разгона по каналу 4
#define R0VN61LZ2	 BUFFER[391]	//( - , Baz2) ПС по мощности канал 1
#define idR0VN61LZ2	 150	//( - , Baz2) ПС по мощности канал 1
#define R0VN62LZ2	 BUFFER[393]	//( - , Baz2) ПС по мощности канал 2
#define idR0VN62LZ2	 151	//( - , Baz2) ПС по мощности канал 2
#define R0VN63LZ2	 BUFFER[395]	//( - , Baz2) ПС по мощности канал 3
#define idR0VN63LZ2	 152	//( - , Baz2) ПС по мощности канал 3
#define R0VN64LZ2	 BUFFER[397]	//( - , Baz2) ПС по мощности канал 4
#define idR0VN64LZ2	 153	//( - , Baz2) ПС по мощности канал 4
#define R0VN65LZ2	 BUFFER[399]	//( - , Baz2) ПС по периоду разгона канал 1
#define idR0VN65LZ2	 154	//( - , Baz2) ПС по периоду разгона канал 1
#define R0VN66LZ2	 BUFFER[401]	//( - , Baz2) ПС по периоду разгона канал 2
#define idR0VN66LZ2	 155	//( - , Baz2) ПС по периоду разгона канал 2
#define fEM_R0UT02RZZ	 BUFFER[403]	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	 156	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RZZ	 BUFFER[408]	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	 157	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_A2UP03RZZ	 BUFFER[413]	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define idfEM_A2UP03RZZ	 158	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define fEM_A2UP04RZZ	 BUFFER[418]	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define idfEM_A2UP04RZZ	 159	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define fEM_R0UT72RZZ	 BUFFER[423]	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	 160	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	 BUFFER[428]	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	 161	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	 BUFFER[433]	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	 162	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT61RZZ	 BUFFER[438]	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	 163	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_A2UP41RZZ	 BUFFER[443]	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define idfEM_A2UP41RZZ	 164	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define fEM_A2UP42RZZ	 BUFFER[448]	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define idfEM_A2UP42RZZ	 165	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define fEM_A2UP51RZZ	 BUFFER[453]	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define idfEM_A2UP51RZZ	 166	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define fEM_A2UP81RZZ	 BUFFER[458]	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP81RZZ	 167	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP84RZZ	 BUFFER[463]	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP84RZZ	 168	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP82RZZ	 BUFFER[468]	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP82RZZ	 169	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP52RZZ	 BUFFER[473]	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define idfEM_A2UP52RZZ	 170	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define fEM_A2UP83RZZ	 BUFFER[478]	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP83RZZ	 171	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_R0UR01RZZ	 BUFFER[483]	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RZZ	 172	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R0UR04RZZ	 BUFFER[488]	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define idfEM_R0UR04RZZ	 173	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define fEM_R0UL05RDU	 BUFFER[493]	//(R0UL05RDU) Время задержки АЗ от НУП ИС(сек)
#define idfEM_R0UL05RDU	 174	//(R0UL05RDU) Время задержки АЗ от НУП ИС(сек)
#define fEM_R0UL25RDU	 BUFFER[498]	//(R0UL25RDU) Время задержки АЗ от ВУ ИС сек
#define idfEM_R0UL25RDU	 175	//(R0UL25RDU) Время задержки АЗ от ВУ ИС сек
#define fEM_R0UL07RDU	 BUFFER[503]	//(R0UL07RDU) Время задержки  срабатывания АС II УР
#define idfEM_R0UL07RDU	 176	//(R0UL07RDU) Время задержки  срабатывания АС II УР
#define bFirstEnterFlag	 BUFFER[508]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 177	//(bFirstEnterFlag) 
#define internal1_m214_tx	 BUFFER[510]	//(internal1_m214_tx) tx - время накопленное сек
#define idinternal1_m214_tx	 178	//(internal1_m214_tx) tx - время накопленное сек
#define internal1_m214_y0	 BUFFER[515]	//(internal1_m214_y0) y0
#define idinternal1_m214_y0	 179	//(internal1_m214_y0) y0
#define internal1_m210_tx	 BUFFER[516]	//(internal1_m210_tx) tx - время накопленное сек
#define idinternal1_m210_tx	 180	//(internal1_m210_tx) tx - время накопленное сек
#define internal1_m210_y0	 BUFFER[521]	//(internal1_m210_y0) y0
#define idinternal1_m210_y0	 181	//(internal1_m210_y0) y0
#define internal1_m205_TVuIs1	 BUFFER[522]	//(internal1_m205_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
#define idinternal1_m205_TVuIs1	 182	//(internal1_m205_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
#define internal1_m205_TVuIs2	 BUFFER[527]	//(internal1_m205_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
#define idinternal1_m205_TVuIs2	 183	//(internal1_m205_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
#define internal1_m205_TImVuIs	 BUFFER[532]	//(internal1_m205_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
#define idinternal1_m205_TImVuIs	 184	//(internal1_m205_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
#define internal1_m205_TNupIs1	 BUFFER[537]	//(internal1_m205_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
#define idinternal1_m205_TNupIs1	 185	//(internal1_m205_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
#define internal1_m205_TNupIs2	 BUFFER[542]	//(internal1_m205_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
#define idinternal1_m205_TNupIs2	 186	//(internal1_m205_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
#define internal1_m205_TImNupIs	 BUFFER[547]	//(internal1_m205_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
#define idinternal1_m205_TImNupIs	 187	//(internal1_m205_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
#define internal1_m205_TImAZ2UR	 BUFFER[552]	//(internal1_m205_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
#define idinternal1_m205_TImAZ2UR	 188	//(internal1_m205_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
#define internal1_m205_fef	 BUFFER[557]	//(internal1_m205_fef) fef
#define idinternal1_m205_fef	 189	//(internal1_m205_fef) fef
#define internal1_m226_tx	 BUFFER[559]	//(internal1_m226_tx) tx - время накопленное сек
#define idinternal1_m226_tx	 190	//(internal1_m226_tx) tx - время накопленное сек
#define internal1_m226_y0	 BUFFER[564]	//(internal1_m226_y0) y0
#define idinternal1_m226_y0	 191	//(internal1_m226_y0) y0
#define internal1_m111_tx	 BUFFER[565]	//(internal1_m111_tx) tx - время накопленное сек
#define idinternal1_m111_tx	 192	//(internal1_m111_tx) tx - время накопленное сек
#define internal1_m111_y0	 BUFFER[570]	//(internal1_m111_y0) y0
#define idinternal1_m111_y0	 193	//(internal1_m111_y0) y0
#define internal1_m110_tx	 BUFFER[571]	//(internal1_m110_tx) tx - время накопленное сек
#define idinternal1_m110_tx	 194	//(internal1_m110_tx) tx - время накопленное сек
#define internal1_m110_y0	 BUFFER[576]	//(internal1_m110_y0) y0
#define idinternal1_m110_y0	 195	//(internal1_m110_y0) y0
#define internal1_m99_tx	 BUFFER[577]	//(internal1_m99_tx) tx - время накопленное сек
#define idinternal1_m99_tx	 196	//(internal1_m99_tx) tx - время накопленное сек
#define internal1_m99_y0	 BUFFER[582]	//(internal1_m99_y0) y0
#define idinternal1_m99_y0	 197	//(internal1_m99_y0) y0
#define internal1_m112_tx	 BUFFER[583]	//(internal1_m112_tx) tx - время накопленное сек
#define idinternal1_m112_tx	 198	//(internal1_m112_tx) tx - время накопленное сек
#define internal1_m112_y0	 BUFFER[588]	//(internal1_m112_y0) y0
#define idinternal1_m112_y0	 199	//(internal1_m112_y0) y0
#define internal1_m140_tx	 BUFFER[589]	//(internal1_m140_tx) tx - время накопленное сек
#define idinternal1_m140_tx	 200	//(internal1_m140_tx) tx - время накопленное сек
#define internal1_m140_y0	 BUFFER[594]	//(internal1_m140_y0) y0
#define idinternal1_m140_y0	 201	//(internal1_m140_y0) y0
#define internal1_m139_tx	 BUFFER[595]	//(internal1_m139_tx) tx - время накопленное сек
#define idinternal1_m139_tx	 202	//(internal1_m139_tx) tx - время накопленное сек
#define internal1_m139_y0	 BUFFER[600]	//(internal1_m139_y0) y0
#define idinternal1_m139_y0	 203	//(internal1_m139_y0) y0
#define internal1_m33_tx	 BUFFER[601]	//(internal1_m33_tx) tx - внутренний параметр
#define idinternal1_m33_tx	 204	//(internal1_m33_tx) tx - внутренний параметр
#define internal1_m150_y0	 BUFFER[604]	//(internal1_m150_y0) y0
#define idinternal1_m150_y0	 205	//(internal1_m150_y0) y0
#define internal1_m148_y0	 BUFFER[609]	//(internal1_m148_y0) y0
#define idinternal1_m148_y0	 206	//(internal1_m148_y0) y0
#define internal1_m92_y0	 BUFFER[614]	//(internal1_m92_y0) y0
#define idinternal1_m92_y0	 207	//(internal1_m92_y0) y0
#define internal1_m90_y0	 BUFFER[619]	//(internal1_m90_y0) y0
#define idinternal1_m90_y0	 208	//(internal1_m90_y0) y0
#define internal1_m161_y1	 BUFFER[624]	//(internal1_m161_y1) y1 - внутренний параметр
#define idinternal1_m161_y1	 209	//(internal1_m161_y1) y1 - внутренний параметр
#define internal1_m172_y1	 BUFFER[626]	//(internal1_m172_y1) y1 - внутренний параметр
#define idinternal1_m172_y1	 210	//(internal1_m172_y1) y1 - внутренний параметр
#define internal1_m281_q0	 BUFFER[628]	//(internal1_m281_q0) q0 - внутренний параметр
#define idinternal1_m281_q0	 211	//(internal1_m281_q0) q0 - внутренний параметр
#define internal1_m130_y0	 BUFFER[633]	//(internal1_m130_y0) state
#define idinternal1_m130_y0	 212	//(internal1_m130_y0) state
#define internal1_m124_y0	 BUFFER[635]	//(internal1_m124_y0) state
#define idinternal1_m124_y0	 213	//(internal1_m124_y0) state
#define internal1_m107_y1	 BUFFER[637]	//(internal1_m107_y1) y1 - внутренний параметр
#define idinternal1_m107_y1	 214	//(internal1_m107_y1) y1 - внутренний параметр
#define internal1_m120_y1	 BUFFER[639]	//(internal1_m120_y1) y1 - внутренний параметр
#define idinternal1_m120_y1	 215	//(internal1_m120_y1) y1 - внутренний параметр
#define internal1_m94_y1	 BUFFER[641]	//(internal1_m94_y1) y1 - внутренний параметр
#define idinternal1_m94_y1	 216	//(internal1_m94_y1) y1 - внутренний параметр
#define internal1_m105_y1	 BUFFER[643]	//(internal1_m105_y1) y1 - внутренний параметр
#define idinternal1_m105_y1	 217	//(internal1_m105_y1) y1 - внутренний параметр
#define internal1_m159_y1	 BUFFER[645]	//(internal1_m159_y1) y1 - внутренний параметр
#define idinternal1_m159_y1	 218	//(internal1_m159_y1) y1 - внутренний параметр
#define internal1_m170_y1	 BUFFER[647]	//(internal1_m170_y1) y1 - внутренний параметр
#define idinternal1_m170_y1	 219	//(internal1_m170_y1) y1 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &A1VN71LS4},	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
	{ 2	,1	,1	, &A1VN71LZ2},	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
	{ 3	,1	,1	, &R0MD34LP1},	//( - , Baz2) Кнопка Квитировать
	{ 4	,1	,1	, &R0AD04LZ2},	//(vds32:05 - K08VDSR, - ) Имитация срабатывания АС II УР рад (БАЗ2)
	{ 5	,1	,1	, &R0VN71LZ2},	//(vds32:05 - K01VDSR, Baz2) АС по мощности канал 1
	{ 6	,1	,1	, &R0VN75LZ2},	//(vds32:05 - K02VDSR, Baz2) АС по периоду разгона канал 1
	{ 7	,1	,1	, &R0VN72LZ2},	//(vds32:06 - K01VDSR, Baz2) АС по мощности канал 2
	{ 8	,1	,1	, &R0VN76LZ2},	//(vds32:06 - K02VDSR, Baz2) АС по периоду разгона канал  2
	{ 9	,1	,1	, &R0VN73LZ2},	//(vds32:08 - K01VDSR, Baz2) АС по мощности канал 3
	{ 10	,1	,1	, &R0VN74LZ2},	//(vds32:07 - K01VDSR, Baz2) АС по мощности канал 4
	{ 11	,1	,1	, &R0VN77LZ2},	//(vds32:08 - K02VDSR, Baz2) АС по периоду разгона канал  3
	{ 12	,1	,1	, &R0VN78LZ2},	//(vds32:07 - K02VDSR, Baz2) АС по периоду разгона канал  4
	{ 13	,1	,1	, &R0EE01LZ2},	//( - , MBz2S) Питание  АКНП1  отключить
	{ 14	,1	,1	, &R0EE02LZ2},	//( - , MBz2S) Питание  АКНП2  отключить
	{ 15	,1	,1	, &R0EE03LZ2},	//( - , MBz2S) Питание  АКНП3  отключить
	{ 16	,1	,1	, &R0EE04LZ2},	//( - , MBz2S) Питание  АКНП4  отключить
	{ 17	,3	,1	, &R0MW12IP2},	//( - , Baz2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{ 18	,1	,1	, &A2IS12LDU},	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
	{ 19	,1	,1	, &B2IS12LDU},	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
	{ 20	,1	,1	, &A0EE07LZ2},	//( - , Baz2) Исправность сети АКНП3
	{ 21	,1	,1	, &A0EE08LZ2},	//( - , Baz2) Исправность сети АКНП4
	{ 22	,1	,1	, &A0VZ71LZ2},	//( - , Baz2) Обобщенный сигнал АС по АЗ1
	{ 23	,1	,1	, &A0EE00LZ2},	//( - , Baz2) Исправность АКНП АЗ1
	{ 24	,1	,1	, &B0EE00LZ2},	//( - , Baz2) Исправность АКНП АЗ2
	{ 25	,1	,1	, &B0VZ71LZ2},	//( - , Baz2) Обобщенный сигнал АС по АЗ2
	{ 26	,1	,1	, &A0VN71LZ2},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ1
	{ 27	,1	,1	, &B0VN71LZ2},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ2
	{ 28	,1	,1	, &A0VN81LZ2},	//( - , Baz2) АЗ по АС периода разгона АЗ1
	{ 29	,1	,1	, &B0VN81LZ2},	//( - , Baz2) АЗ по АС периода разгона АЗ2
	{ 30	,5	,1	, &R0VZ05UZ2},	//( - , Baz2) Индикатор причины сброса
	{ 31	,8	,1	, &R0VN11RZ2},	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ1
	{ 32	,1	,1	, &R0VP73LZ2},	//( - , Baz2, SBz2DU) ПС давления для РУ
	{ 33	,8	,1	, &B0CT01IZ2},	//( - , Baz2, SBz2DU) Температура АЗ2-1
	{ 34	,1	,1	, &B0VT61LZ2},	//( - , Baz2) ПС по температуре в АЗ2
	{ 35	,1	,1	, &B0VT71LZ2},	//( - , Baz2, SBz2DU) АС по температуре в АЗ2
	{ 36	,1	,1	, &A1VN71LS1},	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
	{ 37	,1	,1	, &A1VN71LS2},	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
	{ 38	,1	,1	, &A1VN71LS3},	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
	{ 39	,1	,1	, &R0AD03LZ2},	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
	{ 40	,1	,1	, &B3IS11LDU},	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
	{ 41	,1	,1	, &A3VZ31LZ2},	//( - , Baz2) АЗ от ВУ ИС1
	{ 42	,1	,1	, &B3VZ31LZ2},	//( - , Baz2) АЗ от ВУ ИС2
	{ 43	,1	,1	, &R0AD05LZ2},	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
	{ 44	,1	,1	, &A3VZ11LZ2},	//( - , Baz2) АЗ от НУП ИС1
	{ 45	,1	,1	, &B3VZ11LZ2},	//( - , Baz2) АЗ от НУП ИС2
	{ 46	,1	,1	, &B3IS22LDU},	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
	{ 47	,1	,1	, &A3VZ15LZ2},	//(fds16:0a - K02FDSR, Baz2) Имитация АЗ от НУП ИС
	{ 48	,1	,1	, &A3VZ13LZ2},	//(fds16:0a - K01FDSR, Baz2) Имитация АЗ от ВУ ИС
	{ 49	,1	,1	, &R7II73LZ2},	//(vds32:08 - K07VDSR, Baz2) Сработала АС II УР РАД
	{ 50	,1	,1	, &R7II71LZ2},	//(vds32:08 - K05VDSR, Baz2) Сработала АС IУР РАД (датчик 1)
	{ 51	,1	,1	, &R7II72LZ2},	//(vds32:08 - K06VDSR, Baz2) Сработала АС IУР РАД  (датчик 2)
	{ 52	,1	,1	, &R0AD14LZ2},	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
	{ 53	,1	,1	, &R0AD21LDU},	//( - , SBz2DU) Подключить защиту от II УР
	{ 54	,1	,1	, &R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 55	,1	,1	, &R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 56	,1	,1	, &R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 57	,1	,1	, &R0S01LZ2},	//(vds32:08 - K08VDSR, - ) Отключение сетевых передач в Баз2
	{ 58	,1	,1	, &R0EE02LDU},	//( - , Baz2) Питание  АКНП  отключить
	{ 59	,3	,1	, &R0DE04LZ2},	//(vas84:04 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 4 месте
	{ 60	,3	,1	, &R0DE05LZ2},	//(vds32:05 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 5 месте
	{ 61	,3	,1	, &R0DE06LZ2},	//(vds32:06 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 6 месте
	{ 62	,3	,1	, &R0DE07LZ2},	//(vds32:07 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 7 месте
	{ 63	,3	,1	, &R0DE0ALZ2},	//(fds16:0a - Diagn, DiagnBaz2) диагностика модуля Баз2 на 10 месте
	{ 64	,3	,1	, &R0DE08LZ2},	//(vds32:08 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 8 месте
	{ 65	,3	,1	, &TTLBaz2},	//( - , Baz2) ttl
	{ 66	,1	,1	, &R0DEB1LZ2},	//(sbk:20 - S10SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 5
	{ 67	,1	,1	, &R0DEB2LZ2},	//(sbk:20 - S11SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 5
	{ 68	,1	,1	, &R0DEB3LZ2},	//(sbk:20 - S12SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 6
	{ 69	,1	,1	, &R0DEB4LZ2},	//(sbk:20 - S13SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 6
	{ 70	,1	,1	, &R0DE3CLZ2},	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 5
	{ 71	,1	,1	, &R0DE3DLZ2},	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 6
	{ 72	,1	,1	, &TestDiagnBaz2},	//( - , Baz2) Неисправность от
	{ 73	,3	,1	, &R0MW11IP1},	//( - , Baz2) Переключатель ВЫСТРЕЛ
	{ 74	,5	,1	, &R0VZ05U},	//( - , - ) причины сброса
	{ 75	,8	,1	, &B8VC01RDU},	//( - , SBz2DU, MBz2A1, MBz2A2, MBz2A3, MBz2A4) Координата АЗ2, мм
	{ 76	,1	,1	, &A3IS11LDU},	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
	{ 77	,1	,1	, &A3IS22LDU},	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
	{ 78	,1	,1	, &A0VP41LZ2},	//( - , Baz2) Давление АЗ1 ниже АС
	{ 79	,1	,1	, &B0VP41LZ2},	//( - , Baz2) Давление АЗ2 ниже АС
	{ 80	,1	,1	, &B0VP81LZZ},	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
	{ 81	,1	,1	, &A0VP81LZZ},	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
	{ 82	,1	,1	, &R0ET02LZ2},	//( - , Baz2) Признак наличия неисправности по температуре АЗ2
	{ 83	,3	,1	, &B0EP02IZ2},	//( - , Baz2) Индикатор -Давление  АЗ2 ниже АС
	{ 84	,3	,1	, &A0EP02IZ2},	//( - , Baz2) Индикатор -Давление  АЗ1 ниже АС
	{ 85	,1	,1	, &A0VP71LZ2},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
	{ 86	,1	,1	, &B0VP71LZ2},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
	{ 87	,8	,1	, &R0VN02RS1},	//( - , MBz2A1) Уровень мощности канал 1
	{ 88	,8	,1	, &R0VN02RS2},	//( - , MBz2A2) Уровень мощности канал 2
	{ 89	,8	,1	, &R0VN02RS3},	//( - , MBz2A3) Уровень мощности канал 3
	{ 90	,8	,1	, &R0VN02RS4},	//( - , MBz2A4) Уровень мощности канал 4
	{ 91	,8	,1	, &R0VN01RS1},	//( - , MBz2A1) Период разгона канал 1
	{ 92	,8	,1	, &R0VN01RS2},	//( - , MBz2A2) Период разгона канал 2
	{ 93	,8	,1	, &R0VN01RS3},	//( - , MBz2A3) Период разгона канал 3
	{ 94	,8	,1	, &R0VN01RS4},	//( - , MBz2A4) Период разгона канал 4
	{ 95	,1	,1	, &R0VN61LS1},	//( - , MBz2A1) ПС по мощности канал 1
	{ 96	,1	,1	, &R0VN61LS2},	//( - , MBz2A2) ПС по мощности канал 2
	{ 97	,3	,1	, &A0IT02IZ2},	//(vas84:04 - K01VASR, - ) Температура АЗ1-2
	{ 98	,8	,1	, &A0CT01IZ2},	//( - , Baz2, SBz2DU) Температура АЗ1-1
	{ 99	,1	,1	, &A0VT61LZ2},	//( - , Baz2) ПС по температуре в АЗ1
	{ 100	,1	,1	, &A0VT71LZ2},	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
	{ 101	,1	,1	, &A1VP41LZ2},	//( - , Baz2, SBz2DU) Давление СБРОС ББ1 ниже АС
	{ 102	,1	,1	, &B1VP41LZ2},	//( - , Baz2, SBz2DU) Давление СБРОС ББ2 ниже АС
	{ 103	,1	,1	, &B1VP81LZZ},	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
	{ 104	,1	,1	, &A1VP81LZZ},	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
	{ 105	,1	,1	, &A2VP41LZ2},	//( - , Baz2) Давление СБРОС РБ1 ниже АС
	{ 106	,8	,1	, &A2CP01RZ2},	//( - , Baz2) Текущее давление СБРОС РБ1
	{ 107	,1	,1	, &A2VP51LZ2},	//( - , Baz2) Давление СБРОС РБ1 ниже ПС
	{ 108	,1	,1	, &B2VP41LZ2},	//( - , Baz2) Давление СБРОС РБ2 ниже АС
	{ 109	,8	,1	, &B2CP01RZ2},	//( - , Baz2) Текущее давление СБРОС РБ2
	{ 110	,1	,1	, &B2VP51LZ2},	//( - , Baz2) Давление СБРОС РБ2 ниже ПС
	{ 111	,1	,1	, &B2VP81LZ2},	//( - , Baz2) Давление СБРОС РБ2 в норме
	{ 112	,1	,1	, &A2VP81LZ2},	//( - , Baz2) Давление СБРОС РБ1 в норме
	{ 113	,3	,1	, &A2IP01IZ2},	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
	{ 114	,3	,1	, &B2IP01IZ2},	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
	{ 115	,1	,1	, &R0ET01LZ2},	//( - , Baz2) Признак наличия неисправности по температуре  АЗ1
	{ 116	,3	,1	, &B0IT02IZ2},	//(vas84:04 - K03VASR, - ) Температура АЗ2-2
	{ 117	,1	,1	, &R0VN67LZ2},	//( - , Baz2) ПС по периоду разгона канал 3
	{ 118	,1	,1	, &R0VN68LZ2},	//( - , Baz2) ПС по периоду разгона канал 4
	{ 119	,8	,1	, &R0VN09RZ2},	//( - , Baz2) Усредненный период разгона
	{ 120	,1	,1	, &R0VN69LZ2},	//( - , Baz2) ПС по усредненному периоду
	{ 121	,1	,1	, &R0VN79LZ2},	//( - , Baz2) АС по усредненному периоду
	{ 122	,8	,1	, &R0VR02RZ2},	//( - , Baz2) Усредненная реактивность
	{ 123	,1	,1	, &R0VZ71LZ2},	//(fds16:0a - K05FDSR, Baz2) Обобщенный сигнал АЗ 2 канала
	{ 124	,1	,1	, &R0VN70LZ2},	//( - , Baz2) АЗ по АС мощности РУ
	{ 125	,1	,1	, &R0VN80LZ2},	//( - , Baz2) АЗ по АС периода разгона РУ
	{ 126	,1	,1	, &A1EE01LS1},	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
	{ 127	,1	,1	, &A1EE01LS4},	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
	{ 128	,1	,1	, &A1EE01LS3},	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
	{ 129	,1	,1	, &A0EE01LZ2},	//( - , Baz2, SBz2DU) Исправность АКНП1
	{ 130	,1	,1	, &A0EE04LZ2},	//( - , Baz2, SBz2DU) Исправность АКНП4
	{ 131	,1	,1	, &A0EE02LZ2},	//( - , Baz2, SBz2DU) Исправность АКНП2
	{ 132	,1	,1	, &A0EE03LZ2},	//( - , Baz2, SBz2DU) Исправность АКНП3
	{ 133	,1	,1	, &A1EE01LS2},	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
	{ 134	,1	,1	, &A0EE05LZ2},	//( - , Baz2) Исправность сети АКНП1
	{ 135	,1	,1	, &A0EE06LZ2},	//( - , Baz2) Исправность сети АКНП2
	{ 136	,1	,1	, &R0VN61LS3},	//( - , MBz2A3) ПС по мощности канал 3
	{ 137	,1	,1	, &R0VN61LS4},	//( - , MBz2A4) ПС по мощности канал 4
	{ 138	,1	,1	, &R0VN65LS1},	//( - , MBz2A1) ПС по периоду разгона канал 1
	{ 139	,1	,1	, &R0VN65LS2},	//( - , MBz2A2) ПС по периоду разгона  канал 2
	{ 140	,1	,1	, &R0VN65LS3},	//( - , MBz2A3) ПС по периоду разгона канал 3
	{ 141	,1	,1	, &R0VN65LS4},	//( - , MBz2A4) ПС по периоду разгона канал 4
	{ 142	,8	,1	, &R0VN01RZ2},	//( - , Baz2) Уровень мощности по каналу 1
	{ 143	,8	,1	, &R0VN02RZ2},	//( - , Baz2) Уровень мощности по каналу 2
	{ 144	,8	,1	, &R0VN03RZ2},	//( - , Baz2) Уровень мощности по каналу 3
	{ 145	,8	,1	, &R0VN04RZ2},	//( - , Baz2) Уровень мощности по каналу 4
	{ 146	,8	,1	, &R0VN05RZ2},	//( - , Baz2) Период разгона по каналу 1
	{ 147	,8	,1	, &R0VN06RZ2},	//( - , Baz2) Период разгона по каналу 2
	{ 148	,8	,1	, &R0VN07RZ2},	//( - , Baz2) Период разгона по каналу 3
	{ 149	,8	,1	, &R0VN08RZ2},	//( - , Baz2) Период разгона по каналу 4
	{ 150	,1	,1	, &R0VN61LZ2},	//( - , Baz2) ПС по мощности канал 1
	{ 151	,1	,1	, &R0VN62LZ2},	//( - , Baz2) ПС по мощности канал 2
	{ 152	,1	,1	, &R0VN63LZ2},	//( - , Baz2) ПС по мощности канал 3
	{ 153	,1	,1	, &R0VN64LZ2},	//( - , Baz2) ПС по мощности канал 4
	{ 154	,1	,1	, &R0VN65LZ2},	//( - , Baz2) ПС по периоду разгона канал 1
	{ 155	,1	,1	, &R0VN66LZ2},	//( - , Baz2) ПС по периоду разгона канал 2
	{ 156	,8	,1	, &fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{ 157	,8	,1	, &fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{ 158	,8	,1	, &fEM_A2UP03RZZ},	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{ 159	,8	,1	, &fEM_A2UP04RZZ},	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{ 160	,8	,1	, &fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{ 161	,8	,1	, &fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{ 162	,8	,1	, &fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{ 163	,8	,1	, &fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{ 164	,8	,1	, &fEM_A2UP41RZZ},	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{ 165	,8	,1	, &fEM_A2UP42RZZ},	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{ 166	,8	,1	, &fEM_A2UP51RZZ},	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{ 167	,8	,1	, &fEM_A2UP81RZZ},	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{ 168	,8	,1	, &fEM_A2UP84RZZ},	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{ 169	,8	,1	, &fEM_A2UP82RZZ},	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{ 170	,8	,1	, &fEM_A2UP52RZZ},	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{ 171	,8	,1	, &fEM_A2UP83RZZ},	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{ 172	,8	,1	, &fEM_R0UR01RZZ},	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
	{ 173	,8	,1	, &fEM_R0UR04RZZ},	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
	{ 174	,8	,1	, &fEM_R0UL05RDU},	//(R0UL05RDU) Время задержки АЗ от НУП ИС(сек)
	{ 175	,8	,1	, &fEM_R0UL25RDU},	//(R0UL25RDU) Время задержки АЗ от ВУ ИС сек
	{ 176	,8	,1	, &fEM_R0UL07RDU},	//(R0UL07RDU) Время задержки  срабатывания АС II УР
	{ 177	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 178	,8	,1	, &internal1_m214_tx},	//(internal1_m214_tx) tx - время накопленное сек
	{ 179	,18	,1	, &internal1_m214_y0},	//(internal1_m214_y0) y0
	{ 180	,8	,1	, &internal1_m210_tx},	//(internal1_m210_tx) tx - время накопленное сек
	{ 181	,18	,1	, &internal1_m210_y0},	//(internal1_m210_y0) y0
	{ 182	,8	,1	, &internal1_m205_TVuIs1},	//(internal1_m205_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
	{ 183	,8	,1	, &internal1_m205_TVuIs2},	//(internal1_m205_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
	{ 184	,8	,1	, &internal1_m205_TImVuIs},	//(internal1_m205_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
	{ 185	,8	,1	, &internal1_m205_TNupIs1},	//(internal1_m205_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
	{ 186	,8	,1	, &internal1_m205_TNupIs2},	//(internal1_m205_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
	{ 187	,8	,1	, &internal1_m205_TImNupIs},	//(internal1_m205_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
	{ 188	,8	,1	, &internal1_m205_TImAZ2UR},	//(internal1_m205_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
	{ 189	,1	,1	, &internal1_m205_fef},	//(internal1_m205_fef) fef
	{ 190	,8	,1	, &internal1_m226_tx},	//(internal1_m226_tx) tx - время накопленное сек
	{ 191	,18	,1	, &internal1_m226_y0},	//(internal1_m226_y0) y0
	{ 192	,8	,1	, &internal1_m111_tx},	//(internal1_m111_tx) tx - время накопленное сек
	{ 193	,18	,1	, &internal1_m111_y0},	//(internal1_m111_y0) y0
	{ 194	,8	,1	, &internal1_m110_tx},	//(internal1_m110_tx) tx - время накопленное сек
	{ 195	,18	,1	, &internal1_m110_y0},	//(internal1_m110_y0) y0
	{ 196	,8	,1	, &internal1_m99_tx},	//(internal1_m99_tx) tx - время накопленное сек
	{ 197	,18	,1	, &internal1_m99_y0},	//(internal1_m99_y0) y0
	{ 198	,8	,1	, &internal1_m112_tx},	//(internal1_m112_tx) tx - время накопленное сек
	{ 199	,18	,1	, &internal1_m112_y0},	//(internal1_m112_y0) y0
	{ 200	,8	,1	, &internal1_m140_tx},	//(internal1_m140_tx) tx - время накопленное сек
	{ 201	,18	,1	, &internal1_m140_y0},	//(internal1_m140_y0) y0
	{ 202	,8	,1	, &internal1_m139_tx},	//(internal1_m139_tx) tx - время накопленное сек
	{ 203	,18	,1	, &internal1_m139_y0},	//(internal1_m139_y0) y0
	{ 204	,3	,1	, &internal1_m33_tx},	//(internal1_m33_tx) tx - внутренний параметр
	{ 205	,8	,1	, &internal1_m150_y0},	//(internal1_m150_y0) y0
	{ 206	,8	,1	, &internal1_m148_y0},	//(internal1_m148_y0) y0
	{ 207	,8	,1	, &internal1_m92_y0},	//(internal1_m92_y0) y0
	{ 208	,8	,1	, &internal1_m90_y0},	//(internal1_m90_y0) y0
	{ 209	,1	,1	, &internal1_m161_y1},	//(internal1_m161_y1) y1 - внутренний параметр
	{ 210	,1	,1	, &internal1_m172_y1},	//(internal1_m172_y1) y1 - внутренний параметр
	{ 211	,5	,1	, &internal1_m281_q0},	//(internal1_m281_q0) q0 - внутренний параметр
	{ 212	,1	,1	, &internal1_m130_y0},	//(internal1_m130_y0) state
	{ 213	,1	,1	, &internal1_m124_y0},	//(internal1_m124_y0) state
	{ 214	,1	,1	, &internal1_m107_y1},	//(internal1_m107_y1) y1 - внутренний параметр
	{ 215	,1	,1	, &internal1_m120_y1},	//(internal1_m120_y1) y1 - внутренний параметр
	{ 216	,1	,1	, &internal1_m94_y1},	//(internal1_m94_y1) y1 - внутренний параметр
	{ 217	,1	,1	, &internal1_m105_y1},	//(internal1_m105_y1) y1 - внутренний параметр
	{ 218	,1	,1	, &internal1_m159_y1},	//(internal1_m159_y1) y1 - внутренний параметр
	{ 219	,1	,1	, &internal1_m170_y1},	//(internal1_m170_y1) y1 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="baz2.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{156,"fEM_R0UT02RZZ\0"}, 
{157,"fEM_R0UT01RZZ\0"}, 
{158,"fEM_A2UP03RZZ\0"}, 
{159,"fEM_A2UP04RZZ\0"}, 
{160,"fEM_R0UT72RZZ\0"}, 
{161,"fEM_R0UT71RZZ\0"}, 
{162,"fEM_R0UT62RZZ\0"}, 
{163,"fEM_R0UT61RZZ\0"}, 
{164,"fEM_A2UP41RZZ\0"}, 
{165,"fEM_A2UP42RZZ\0"}, 
{166,"fEM_A2UP51RZZ\0"}, 
{167,"fEM_A2UP81RZZ\0"}, 
{168,"fEM_A2UP84RZZ\0"}, 
{169,"fEM_A2UP82RZZ\0"}, 
{170,"fEM_A2UP52RZZ\0"}, 
{171,"fEM_A2UP83RZZ\0"}, 
{172,"fEM_R0UR01RZZ\0"}, 
{173,"fEM_R0UR04RZZ\0"}, 
{174,"fEM_R0UL05RDU\0"}, 
{175,"fEM_R0UL25RDU\0"}, 
{176,"fEM_R0UL07RDU\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_Baz2[]={  // 
	{&R0MD34LP1,1,0},	//( - , Baz2) Кнопка Квитировать
	{&A0EE08LZ2,1,1},	//( - , Baz2) Исправность сети АКНП4
	{&A0EE07LZ2,1,2},	//( - , Baz2) Исправность сети АКНП3
	{&A0EE06LZ2,1,3},	//( - , Baz2) Исправность сети АКНП2
	{&A0EE05LZ2,1,4},	//( - , Baz2) Исправность сети АКНП1
	{&R7II72LZ2,1,5},	//( - K06VDSR, Baz2) Сработала АС IУР РАД  (датчик 2)
	{&R7II71LZ2,1,6},	//( - K05VDSR, Baz2) Сработала АС IУР РАД (датчик 1)
	{&R7II73LZ2,1,7},	//( - K07VDSR, Baz2) Сработала АС II УР РАД
	{&R0EE02LDU,1,8},	//( - , Baz2) Питание  АКНП  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_Baz2[]={  // 
	{&B0VT71LZ2,1,0},	//( - , Baz2, SBz2DU) АС по температуре в АЗ2
	{&B0VT61LZ2,1,1},	//( - , Baz2) ПС по температуре в АЗ2
	{&R0VP73LZ2,1,2},	//( - , Baz2, SBz2DU) ПС давления для РУ
	{&B0VN81LZ2,1,3},	//( - , Baz2) АЗ по АС периода разгона АЗ2
	{&A0VN81LZ2,1,4},	//( - , Baz2) АЗ по АС периода разгона АЗ1
	{&B0VN71LZ2,1,5},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ2
	{&A0VN71LZ2,1,6},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ1
	{&B0VZ71LZ2,1,7},	//( - , Baz2) Обобщенный сигнал АС по АЗ2
	{&B0EE00LZ2,1,8},	//( - , Baz2) Исправность АКНП АЗ2
	{&A0EE00LZ2,1,9},	//( - , Baz2) Исправность АКНП АЗ1
	{&A0VZ71LZ2,1,10},	//( - , Baz2) Обобщенный сигнал АС по АЗ1
	{&A0EE03LZ2,1,11},	//( - , Baz2, SBz2DU) Исправность АКНП3
	{&A0EE02LZ2,1,12},	//( - , Baz2, SBz2DU) Исправность АКНП2
	{&A0EE04LZ2,1,13},	//( - , Baz2, SBz2DU) Исправность АКНП4
	{&A3VZ13LZ2,1,14},	//( - K01FDSR, Baz2) Имитация АЗ от ВУ ИС
	{&A3VZ15LZ2,1,15},	//( - K02FDSR, Baz2) Имитация АЗ от НУП ИС
	{&B3VZ11LZ2,1,16},	//( - , Baz2) АЗ от НУП ИС2
	{&A3VZ11LZ2,1,17},	//( - , Baz2) АЗ от НУП ИС1
	{&B3VZ31LZ2,1,18},	//( - , Baz2) АЗ от ВУ ИС2
	{&A3VZ31LZ2,1,19},	//( - , Baz2) АЗ от ВУ ИС1
	{&TestDiagnBaz2,1,20},	//( - , Baz2) Неисправность от
	{&R0VN78LZ2,1,21},	//( - K02VDSR, Baz2) АС по периоду разгона канал  4
	{&R0VN77LZ2,1,22},	//( - K02VDSR, Baz2) АС по периоду разгона канал  3
	{&R0VN74LZ2,1,23},	//( - K01VDSR, Baz2) АС по мощности канал 4
	{&R0VN73LZ2,1,24},	//( - K01VDSR, Baz2) АС по мощности канал 3
	{&R0VN76LZ2,1,25},	//( - K02VDSR, Baz2) АС по периоду разгона канал  2
	{&R0VN72LZ2,1,26},	//( - K01VDSR, Baz2) АС по мощности канал 2
	{&R0VN75LZ2,1,27},	//( - K02VDSR, Baz2) АС по периоду разгона канал 1
	{&R0VN71LZ2,1,28},	//( - K01VDSR, Baz2) АС по мощности канал 1
	{&B0VP71LZ2,1,29},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
	{&A0VP71LZ2,1,30},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
	{&R0ET02LZ2,1,31},	//( - , Baz2) Признак наличия неисправности по температуре АЗ2
	{&B0VP41LZ2,1,32},	//( - , Baz2) Давление АЗ2 ниже АС
	{&A0VP41LZ2,1,33},	//( - , Baz2) Давление АЗ1 ниже АС
	{&R0ET01LZ2,1,34},	//( - , Baz2) Признак наличия неисправности по температуре  АЗ1
	{&A2VP81LZ2,1,35},	//( - , Baz2) Давление СБРОС РБ1 в норме
	{&B2VP81LZ2,1,36},	//( - , Baz2) Давление СБРОС РБ2 в норме
	{&B2VP51LZ2,1,37},	//( - , Baz2) Давление СБРОС РБ2 ниже ПС
	{&B2VP41LZ2,1,38},	//( - , Baz2) Давление СБРОС РБ2 ниже АС
	{&A2VP51LZ2,1,39},	//( - , Baz2) Давление СБРОС РБ1 ниже ПС
	{&A2VP41LZ2,1,40},	//( - , Baz2) Давление СБРОС РБ1 ниже АС
	{&B1VP41LZ2,1,41},	//( - , Baz2, SBz2DU) Давление СБРОС ББ2 ниже АС
	{&A1VP41LZ2,1,42},	//( - , Baz2, SBz2DU) Давление СБРОС ББ1 ниже АС
	{&A0VT71LZ2,1,43},	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
	{&A0VT61LZ2,1,44},	//( - , Baz2) ПС по температуре в АЗ1
	{&A0EE01LZ2,1,45},	//( - , Baz2, SBz2DU) Исправность АКНП1
	{&R0VN80LZ2,1,46},	//( - , Baz2) АЗ по АС периода разгона РУ
	{&R0VN70LZ2,1,47},	//( - , Baz2) АЗ по АС мощности РУ
	{&R0VZ71LZ2,1,48},	//( - K05FDSR, Baz2) Обобщенный сигнал АЗ 2 канала
	{&R0VN79LZ2,1,49},	//( - , Baz2) АС по усредненному периоду
	{&R0VN69LZ2,1,50},	//( - , Baz2) ПС по усредненному периоду
	{&R0VN68LZ2,1,51},	//( - , Baz2) ПС по периоду разгона канал 4
	{&R0VN67LZ2,1,52},	//( - , Baz2) ПС по периоду разгона канал 3
	{&R0VN66LZ2,1,53},	//( - , Baz2) ПС по периоду разгона канал 2
	{&R0VN65LZ2,1,54},	//( - , Baz2) ПС по периоду разгона канал 1
	{&R0VN64LZ2,1,55},	//( - , Baz2) ПС по мощности канал 4
	{&R0VN63LZ2,1,56},	//( - , Baz2) ПС по мощности канал 3
	{&R0VN62LZ2,1,57},	//( - , Baz2) ПС по мощности канал 2
	{&R0VN61LZ2,1,58},	//( - , Baz2) ПС по мощности канал 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_Baz2[]={  // 
	{&B0CT01IZ2,8,0},	//( - , Baz2, SBz2DU) Температура АЗ2-1
	{&R0VN11RZ2,8,2},	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ1
	{&R0VZ05UZ2,5,4},	//( - , Baz2) Индикатор причины сброса
	{&TTLBaz2,3,6},	//( - , Baz2) ttl
	{&R0VN01RZ2,8,7},	//( - , Baz2) Уровень мощности по каналу 1
	{&A0EP02IZ2,3,9},	//( - , Baz2) Индикатор -Давление  АЗ1 ниже АС
	{&B0EP02IZ2,3,10},	//( - , Baz2) Индикатор -Давление  АЗ2 ниже АС
	{&B2CP01RZ2,8,11},	//( - , Baz2) Текущее давление СБРОС РБ2
	{&A2CP01RZ2,8,13},	//( - , Baz2) Текущее давление СБРОС РБ1
	{&A0CT01IZ2,8,15},	//( - , Baz2, SBz2DU) Температура АЗ1-1
	{&R0VR02RZ2,8,17},	//( - , Baz2) Усредненная реактивность
	{&R0VN09RZ2,8,19},	//( - , Baz2) Усредненный период разгона
	{&R0VN08RZ2,8,21},	//( - , Baz2) Период разгона по каналу 4
	{&R0VN07RZ2,8,23},	//( - , Baz2) Период разгона по каналу 3
	{&R0VN06RZ2,8,25},	//( - , Baz2) Период разгона по каналу 2
	{&R0VN05RZ2,8,27},	//( - , Baz2) Период разгона по каналу 1
	{&R0VN04RZ2,8,29},	//( - , Baz2) Уровень мощности по каналу 4
	{&R0VN03RZ2,8,31},	//( - , Baz2) Уровень мощности по каналу 3
	{&R0VN02RZ2,8,33},	//( - , Baz2) Уровень мощности по каналу 2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_Baz2[]={  // 
	{&R0MW11IP1,3,0},	//( - , Baz2) Переключатель ВЫСТРЕЛ
	{&R0MW12IP2,3,1},	//( - , Baz2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{&fEM_R0UT02RZZ,8,2},	//( - , Baz2) Верхний предел шкалы датчика температуры
	{&fEM_R0UT01RZZ,8,4},	//( - , Baz2) Нижний предел шкалы датчика температуры
	{&fEM_A2UP03RZZ,8,6},	//( - , Baz2) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{&fEM_A2UP04RZZ,8,8},	//( - , Baz2) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{&fEM_R0UT72RZZ,8,10},	//( - , Baz2) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{&fEM_R0UT71RZZ,8,12},	//( - , Baz2) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{&fEM_R0UT62RZZ,8,14},	//( - , Baz2) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{&fEM_R0UT61RZZ,8,16},	//( - , Baz2) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{&fEM_A2UP41RZZ,8,18},	//( - , Baz2) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{&fEM_A2UP42RZZ,8,20},	//( - , Baz2) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{&fEM_A2UP51RZZ,8,22},	//( - , Baz2) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{&fEM_A2UP81RZZ,8,24},	//( - , Baz2) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{&fEM_A2UP84RZZ,8,26},	//( - , Baz2) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{&fEM_A2UP82RZZ,8,28},	//( - , Baz2) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{&fEM_A2UP52RZZ,8,30},	//( - , Baz2) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{&fEM_A2UP83RZZ,8,32},	//( - , Baz2) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{&fEM_R0UR01RZZ,8,34},	//( - , Baz2) Уставка АКНП ПС  АЗ по периоду (сек)
	{&fEM_R0UR04RZZ,8,36},	//( - , Baz2) Уставка АКНП АС  АЗ по периоду (сек)
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SBz2DU[]={  // 
	{&R0AD21LDU,1,0},	//( - , SBz2DU) Подключить защиту от II УР
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz2DU[]={  // 
	{&B0VT71LZ2,1,0},	//( - , Baz2, SBz2DU) АС по температуре в АЗ2
	{&R0VP73LZ2,1,1},	//( - , Baz2, SBz2DU) ПС давления для РУ
	{&B0VN71LZ2,1,2},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ2
	{&A0VN71LZ2,1,3},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ1
	{&A0EE03LZ2,1,4},	//( - , Baz2, SBz2DU) Исправность АКНП3
	{&A0EE02LZ2,1,5},	//( - , Baz2, SBz2DU) Исправность АКНП2
	{&A0EE04LZ2,1,6},	//( - , Baz2, SBz2DU) Исправность АКНП4
	{&A0EE01LZ2,1,7},	//( - , Baz2, SBz2DU) Исправность АКНП1
	{&B0VP71LZ2,1,8},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
	{&A0VP71LZ2,1,9},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
	{&B1VP41LZ2,1,10},	//( - , Baz2, SBz2DU) Давление СБРОС ББ2 ниже АС
	{&A1VP41LZ2,1,11},	//( - , Baz2, SBz2DU) Давление СБРОС ББ1 ниже АС
	{&A0VT71LZ2,1,12},	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SBz2DU[]={  // 
	{&B0CT01IZ2,8,0},	//( - , Baz2, SBz2DU) Температура АЗ2-1
	{&R0VN11RZ2,8,2},	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ1
	{&A0CT01IZ2,8,4},	//( - , Baz2, SBz2DU) Температура АЗ1-1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SBz2DU[]={  // 
	{&B8VC01RDU,8,0},	//( - , SBz2DU, MBz2A1, MBz2A2, MBz2A3, MBz2A4) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_DiagnBaz2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnBaz2[]={  // 
	{&R0DEB1LZ2,1,0},	//( - S10SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 5
	{&R0DEB2LZ2,1,1},	//( - S11SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 5
	{&R0DEB3LZ2,1,2},	//( - S12SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 6
	{&R0DEB4LZ2,1,3},	//( - S13SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 6
	{&R0DE3CLZ2,1,4},	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 5
	{&R0DE3DLZ2,1,5},	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 6
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DiagnBaz2[]={  // 
	{&R0DE04LZ2,3,0},	//( - Diagn, DiagnBaz2) диагностика модуля Баз2 на 4 месте
	{&R0DE05LZ2,3,1},	//( - Diagn, DiagnBaz2) диагностика модуля Баз2 на 5 месте
	{&R0DE06LZ2,3,2},	//( - Diagn, DiagnBaz2) диагностика модуля Баз2 на 6 месте
	{&R0DE07LZ2,3,3},	//( - Diagn, DiagnBaz2) диагностика модуля Баз2 на 7 месте
	{&R0DE0ALZ2,3,4},	//( - Diagn, DiagnBaz2) диагностика модуля Баз2 на 10 месте
	{&R0DE08LZ2,3,5},	//( - Diagn, DiagnBaz2) диагностика модуля Баз2 на 8 месте
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DiagnBaz2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MBz2S[]={  // 
	{&R0EE01LZ2,1,0},	//( - , SBz2) Питание  АКНП1  отключить
	{&R0EE02LZ2,1,1},	//( - , SBz2) Питание  АКНП  отключить
	{&R0EE03LZ2,1,2},	//( - , SBz2) Питание  АКНП3  отключить
	{&R0EE04LZ2,1,3},	//( - , SBz2) Питание  АКНП4  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz2S[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz2S[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz2S[]={  // 
	{NULL,0,0},
};
#pragma pop
static char MBz2S_ip1[]={"192.168.10.60\0"};
static char MBz2S_ip2[]={"192.168.10.60\0"};
#pragma pack(push,1)
static ModbusRegister coil_MBz2A1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz2A1[]={  // 
	{&R0VN61LS1,1,0},	//( - , A1Bz1, A1Bz2) ПС по мощности канал1
	{&R0VN65LS1,1,1},	//( - , A1Bz1, A1Bz2) ПС по периоду разгона канал1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz2A1[]={  // 
	{&R0VN02RS1,8,0},	//( - , A1Bz1, A1Bz2) Уровень мощности
	{&R0VN01RS1,8,2},	//( - , A1Bz1, A1Bz2) Период разгона канал1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz2A1[]={  // 
	{&B8VC01RDU,8,0},	//( - , A1Bz1, A1Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
static char MBz2A1_ip1[]={"192.168.10.51\0"};
static char MBz2A1_ip2[]={"192.168.10.151\0"};
#pragma pack(push,1)
static ModbusRegister coil_MBz2A2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz2A2[]={  // 
	{&R0VN61LS2,1,0},	//( - , A2Bz1, A2Bz2) ПС по мощности канал 2
	{&R0VN65LS2,1,1},	//( - , A2Bz1, A2Bz2) ПС по периоду разгона канал 2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz2A2[]={  // 
	{&R0VN02RS2,8,0},	//( - , A2Bz1, A2Bz2) Уровень мощности канал 2
	{&R0VN01RS2,8,2},	//( - , A2Bz1, A2Bz2) Период разгона канал 2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz2A2[]={  // 
	{&B8VC01RDU,8,0},	//( - , A2Bz1, A2Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
static char MBz2A2_ip1[]={"192.168.10.57\0"};
static char MBz2A2_ip2[]={"192.168.10.157\0"};
#pragma pack(push,1)
static ModbusRegister coil_MBz2A3[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz2A3[]={  // 
	{&R0VN61LS3,1,0},	//( - , A3Bz1, A3Bz2) ПС по мощности канал 3
	{&R0VN65LS3,1,1},	//( - , A3Bz1, A3Bz2) ПС по периоду разгона канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz2A3[]={  // 
	{&R0VN02RS3,8,0},	//( - , A3Bz1, A3Bz2) Уровень мощности канал 3
	{&R0VN01RS3,8,2},	//( - , A3Bz1, A3Bz2) Период разгона канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz2A3[]={  // 
	{&B8VC01RDU,8,0},	//( - , A3Bz1, A3Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
static char MBz2A3_ip1[]={"192.168.10.53\0"};
static char MBz2A3_ip2[]={"192.168.10.153\0"};
#pragma pack(push,1)
static ModbusRegister coil_MBz2A4[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz2A4[]={  // 
	{&R0VN61LS4,1,0},	//( - , A4Bz1, A4Bz2) ПС по мощности канал 4
	{&R0VN65LS4,1,1},	//( - , A4Bz1, A4Bz2) ПС по периоду разгона канал 4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz2A4[]={  // 
	{&R0VN02RS4,8,0},	//( - , A4Bz1, A4Bz2) Уровень мощности канал 4
	{&R0VN01RS4,8,2},	//( - , A4Bz1, A4Bz2) Период разгона канал 4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz2A4[]={  // 
	{&B8VC01RDU,8,0},	//( - , A4Bz1, A4Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
static char MBz2A4_ip1[]={"192.168.10.55\0"};
static char MBz2A4_ip2[]={"192.168.10.155\0"};
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_Baz2[0],&di_Baz2[0],&ir_Baz2[0],&hr_Baz2[0],NULL,NULL,NULL,0},	 //Общий слэйв
	{0,5009,&coil_SBz2DU[0],&di_SBz2DU[0],&ir_SBz2DU[0],&hr_SBz2DU[0],NULL,NULL,NULL,0},	 //Слэйв для DU
	{0,5005,&coil_DiagnBaz2[0],&di_DiagnBaz2[0],&ir_DiagnBaz2[0],&hr_DiagnBaz2[0],NULL,NULL,NULL,0},	 //Диагностика Baz2
	{1,5004,&coil_MBz2S[0],&di_MBz2S[0],&ir_MBz2S[0],&hr_MBz2S[0],NULL,MBz2S_ip1,MBz2S_ip2,100},	 //Мастер Баз2 в SCM
	{1,5019,&coil_MBz2A1[0],&di_MBz2A1[0],&ir_MBz2A1[0],&hr_MBz2A1[0],NULL,MBz2A1_ip1,MBz2A1_ip2,20},	 //Мастер Баз2 в AKNP1
	{1,5020,&coil_MBz2A2[0],&di_MBz2A2[0],&ir_MBz2A2[0],&hr_MBz2A2[0],NULL,MBz2A2_ip1,MBz2A2_ip2,20},	 //Мастер Баз2 в AKNP2
	{1,5021,&coil_MBz2A3[0],&di_MBz2A3[0],&ir_MBz2A3[0],&hr_MBz2A3[0],NULL,MBz2A3_ip1,MBz2A3_ip2,20},	 //Мастер Баз2 в AKNP3
	{1,5022,&coil_MBz2A4[0],&di_MBz2A4[0],&ir_MBz2A4[0],&hr_MBz2A4[0],NULL,MBz2A4_ip1,MBz2A4_ip2,20},	 //Мастер Баз2 в AKNP4

	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},};
#pragma pop
#include <fp8/drivers/vas84r.h>
static char buf_VAS84[30];	//VAS84
static vas84r_inipar ini_VAS84={0xc6,255,1,8,0xff,0,16,};
#pragma pack(push,1)
static table_drv table_VAS84={0,0,&ini_VAS84,buf_VAS84,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VAS84[]={
	{&B0IT02IZ2,3,6},
	{&R0DE04LZ2,3,26},
	{&A0IT02IZ2,3,0},
	{&B2IP01IZ2,3,9},
	{&A2IP01IZ2,3,3},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS321[132];	//VDS32
static vds32r_inipar ini_VDS321={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS321={0,0,&ini_VDS321,buf_VDS321,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS321[]={
	{&A3IS11LDU,1,8},
	{&A3IS22LDU,1,10},
	{&R0AD04LZ2,1,14},
	{&R0VN71LZ2,1,0},
	{&R0VN75LZ2,1,2},
	{&A2IS12LDU,1,18},
	{&B2IS12LDU,1,20},
	{&R0DE05LZ2,3,64},
	{&A1VN71LS1,1,6},
	{&A1EE01LS1,1,4},
	{&R0AD03LZ2,1,12},
	{&R0AD05LZ2,1,16},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS322[132];	//VDS32
static vds32r_inipar ini_VDS322={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS322={0,0,&ini_VDS322,buf_VDS322,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS322[]={
	{&A1VN71LS2,1,6},
	{&B3IS11LDU,1,8},
	{&A1EE01LS2,1,4},
	{&R0VN72LZ2,1,0},
	{&B3IS22LDU,1,10},
	{&R0VN76LZ2,1,2},
	{&R0DE06LZ2,3,64},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS323[132];	//VDS32
static vds32r_inipar ini_VDS323={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS323={0,0,&ini_VDS323,buf_VDS323,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS323[]={
	{&A1VN71LS4,1,6},
	{&R0VN74LZ2,1,0},
	{&R0VN78LZ2,1,2},
	{&R0DE07LZ2,3,64},
	{&A1EE01LS4,1,4},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS324[132];	//VDS32
static vds32r_inipar ini_VDS324={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS324={0,0,&ini_VDS324,buf_VDS324,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS324[]={
	{&A0VP81LZZ,1,16},
	{&B0VP81LZZ,1,22},
	{&R0DE08LZ2,3,64},
	{&R0VN77LZ2,1,2},
	{&A1VP81LZZ,1,18},
	{&R0VN73LZ2,1,0},
	{&B1VP81LZZ,1,24},
	{&R0S01LZ2,1,14},
	{&R7II72LZ2,1,10},
	{&R7II71LZ2,1,8},
	{&A1VN71LS3,1,6},
	{&R7II73LZ2,1,12},
	{&A1EE01LS3,1,4},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS16[40];	//FDS16
static fds16r_inipar ini_FDS16={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS16={0,0,&ini_FDS16,buf_FDS16,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS16[]={
	{&R0DE0ALZ2,3,38},
	{&R0VZ71LZ2,1,8},
	{&R0AD14LZ2,1,4},
	{&A3VZ15LZ2,1,2},
	{&A3VZ13LZ2,1,0},
	{&A1VN71LZ2,1,6},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/sbkfp7.h>
static char buf_SBKFP[26];	//SBKFP
static sbk_inipar ini_SBKFP={0xcc,0xff,8,8,};
#pragma pack(push,1)
static table_drv table_SBKFP={0,0,&ini_SBKFP,buf_SBKFP,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_SBKFP[]={
	{&R0DEB1LZ2,1,18},
	{&R0DEB2LZ2,1,20},
	{&R0DEB3LZ2,1,22},
	{&R0DEB4LZ2,1,24},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc6,0x04,7,30,def_buf_VAS84,&table_VAS84}, //VAS84
	{0xc2,0x05,15,132,def_buf_VDS321,&table_VDS321}, //VDS32
	{0xc2,0x06,15,132,def_buf_VDS322,&table_VDS322}, //VDS32
	{0xc2,0x07,15,132,def_buf_VDS323,&table_VDS323}, //VDS32
	{0xc2,0x08,15,132,def_buf_VDS324,&table_VDS324}, //VDS32
	{0x96,0x0a,20,40,def_buf_FDS16,&table_FDS16}, //FDS16
	{0xcc,0x20,4,26,def_buf_SBKFP,&table_SBKFP}, //SBKFP
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
	setAsFloat(156,600);
	setAsFloat(157,0);
	setAsFloat(158,1.6);
	setAsFloat(159,0);
	setAsFloat(160,150);
	setAsFloat(161,200);
	setAsFloat(162,90);
	setAsFloat(163,100);
	setAsFloat(164,0.1);
	setAsFloat(165,0.13);
	setAsFloat(166,0.16);
	setAsFloat(167,0.17);
	setAsFloat(168,0.31);
	setAsFloat(169,0.2);
	setAsFloat(170,0.19);
	setAsFloat(171,0.28);
	setAsFloat(172,15);
	setAsFloat(173,10);
	setAsFloat(174,0.190);
	setAsFloat(175,0.170);
	setAsFloat(176,0.150);
	setAsBool(54,1);
	setAsBool(55,1);
	setAsBool(56,1);
}
uspaint8 InternalBuf[150];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssbool lRM_0_ = {0,0}; /* A-Граница участка насыщения А */ 
ssbool lRM_1_ = {1,0}; /* B-Граница участка насыщения В */ 
sslong dRM_0_ = {0,0}; /* lx вход лонг */ 
sschar bRM_0_ = {0,0}; /* cx вход байтовый */ 
ssint iRM_0_ = {0,0}; /* ix вход целый */ 
ssint iRM_3_ = {3,0}; /* N-число входов */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива */ 
ssint iRM_6_ = {6,0}; /* N-число входов */ 
ssint iRM_17_ = {17,0}; /* n - размерность массива входных сигналов */ 
ssint iRM_3276_ = {3276,0}; /* a */ 
ssint iRM_16000_ = {16000,0}; /* b */ 
ssfloat fRM_0_00001 = {0.00001,0}; /* X2 */ 
ssint iRM_200_ = {200,0}; /* tz - ширина импульса, 10-ки мс */ 
ssint iRM_7_ = {7,0}; /* n - N-размерность массива x */ 
ssfloat fRM_0_002 = {0.002,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_005 = {0.005,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_007 = {0.007,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_01 = {0.01,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_015 = {0.015,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_02 = {0.02,0}; /* x - массив входных параметров */ 
ssfloat fRM_1_7 = {1.7,0}; /* x - массив входных параметров */ 
ssfloat fRM_10000_ = {10000,0}; /* tz - время задержки сек */ 
ssfloat fRM_10_ = {10,0}; /* tz - время задержки сек */ 
ssfloat fRM_0_3 = {0.3,0}; /* tz - время задержки сек */ 

uspaint8 SpaEEPROMBuf[105];

/* Определение переменных */
ssbool var1;
ssbool var2;
ssbool var3;
ssbool var4;
ssbool var5;
ssbool var6;
ssbool var7;
ssbool var8;
ssbool var9;
ssbool var10;
ssbool var11;
ssbool var12;
ssbool var13;
ssbool var14;
ssbool var15;
ssbool var16;
ssbool var17;
ssbool var18;
ssbool var19;
ssbool var20;
ssbool var21;
ssbool var22;
ssbool var23;
ssbool var24;
ssbool var25;
ssbool var26;
ssbool var27;
ssbool var28;
ssbool var29;
ssbool var30;
ssbool var31;
ssbool var32;
ssint var33;
ssbool var34;
ssbool var35;
ssbool var36;
ssbool var37;
ssbool var38;
ssbool var39;
ssbool var40;
ssbool var41;
ssbool var42;
ssbool var43;
ssbool var44;
ssbool var45;
ssbool var46;
ssbool var47;
ssbool var48;
ssbool var49;
ssbool var50;
ssbool var51;
ssbool var52;
ssbool var53;
ssbool var54;
ssbool var55;
ssbool var56;
ssbool var57;
ssbool var58;
ssbool var59;
ssbool var60;
ssbool var61;
ssbool var62;
ssbool var63;
ssbool var64;
ssbool var65;
ssbool var66;
ssbool var67;
ssbool var68;
ssbool var69;
ssbool var70;
ssbool var71;
ssbool var72;
ssbool var73;
ssbool var74;
ssbool var75;
ssbool var76;
ssbool var77;
ssbool var78;
ssbool var79;
ssbool var80;
ssbool var81;
ssbool var82;
ssbool var83;
ssbool var84;
ssbool var85;
ssbool var86;
ssbool var87;
ssbool var88;
ssbool var89;
ssbool var90;
ssbool var91;
ssbool var92;
ssbool var93;
ssbool var94;
ssbool var95;
ssbool var96;
ssbool var97;
ssbool var98;
ssbool var99;
ssbool var100;
ssbool var101;
ssbool var102;
ssbool var103;
ssfloat var104;
ssfloat var105;
ssbool var106;
ssfloat var107;
ssfloat var108;
ssbool var109;
ssbool var110;
ssbool var111;
ssbool var112;
ssbool var113;
ssbool var114;
ssfloat var115;
sslong var116;
sslong var117;
ssbool var118;
ssbool var119;
ssbool var120;
ssbool var121;
ssbool var122;
ssbool var123;
ssbool var124;
ssbool var125;
ssbool var126;
ssfloat var127;
ssbool var128;
ssbool var129;
ssfloat var130;
ssbool var131;
ssbool var132;
sschar var133;
ssbool var134;
sschar var135;
ssbool var136;
ssbool var137;
ssbool var138;
ssbool var139;
ssbool var140;
ssbool var141;
ssbool var142;
ssbool var143;
ssbool var144;
ssbool var145;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psint  array_m307_x_1[6] = {&R0DE04LZ2,&R0DE05LZ2,&R0DE06LZ2,&R0DE0ALZ2,&R0DE08LZ2,&R0DE07LZ2};
psfloat  array_m189_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psfloat  array_m293_x_1[4] = {&R0VN02RS1,&R0VN02RS2,&R0VN02RS3,&R0VN02RS4};
psbool  array_m293_diag_1[4] = {&var34,&var35,&var36,&var37};
psbool  array_m282_x_1[17] = {&var77,&var42,&var43,&var88,&var10,&var7,&var132,&var44,&var47,&var48,&var86,&var11,&var8,&var134,&R7II72LZ2,&R7II71LZ2,&R7II73LZ2};
psbool  array_m16_x_1[6] = {&var81,&var86,&var11,&var8,&var19,&var134};
psbool  array_m36_x_1[6] = {&var88,&var7,&var10,&var132,&var79,&var19};
psfloat  array_m2_x_1[4] = {&R0VN01RS1,&R0VN01RS2,&R0VN01RS3,&R0VN01RS4};
psbool  array_m2_diag_1[4] = {&var34,&var35,&var36,&var37};
psbool  array_m3_x_1[3] = {&var94,&var114,&var38};
psbool  array_m12_x_1[3] = {&var93,&var41,&var95};

/* Объявление структур */
_S_zzfs  S_zzfs_214_1 = {&var13,&fRM_0_3,&var1,&internal1_m214_tx,&internal1_m214_y0};
_S_or2  S_or2_279_1 = {&R0MD34LP1,&var1,&var2};
_S_zzfs  S_zzfs_210_1 = {&R0AD04LZ2,&fRM_0_3,&var3,&internal1_m210_tx,&internal1_m210_y0};
_S_noto  S_noto_224_1 = {&var3,&var4};
_S_and2  S_and2_227_1 = {&var4,&var6,&var5};
_S_or3  S_or3_228_1 = {&var17,&var18,&R7II73LZ2,&var6};
_S_inicn  S_inicn_205_1 = {&A3IS11LDU,&B3IS11LDU,&R0AD03LZ2,&A3IS22LDU,&B3IS22LDU,&R0AD05LZ2,&var17,&var18,&var16,&var3,&fEM_R0UL25RDU,&fEM_R0UL05RDU,&fEM_R0UL07RDU,&var7,&var8,&var9,&var10,&var11,&var12,&var13,&internal1_m205_TVuIs1,&internal1_m205_TVuIs2,&internal1_m205_TImVuIs,&internal1_m205_TNupIs1,&internal1_m205_TNupIs2,&internal1_m205_TImNupIs,&internal1_m205_TImAZ2UR,&internal1_m205_fef};
_S_or2  S_or2_218_1 = {&R7II73LZ2,&var21,&var14};
_S_or2  S_or2_216_1 = {&R0AD21LDU,&var3,&var15};
_S_and2  S_and2_215_1 = {&var14,&var15,&var16};
_S_or2  S_or2_206_1 = {&var20,&R7II71LZ2,&var17};
_S_or2  S_or2_199_1 = {&var22,&R7II72LZ2,&var18};
_S_zpfs  S_zpfs_226_1 = {&var5,&fEM_R0UL07RDU,&var19,&internal1_m226_tx,&internal1_m226_y0};
_S_noto  S_noto_201_1 = {&R6IS67LZZ,&var20};
_S_noto  S_noto_219_1 = {&R6IS68LZZ,&var21};
_S_noto  S_noto_200_1 = {&R6IS66LZZ,&var22};
_S_zzfs  S_zzfs_111_1 = {&B1VP81LZZ,&fRM_10000_,&var23,&internal1_m111_tx,&internal1_m111_y0};
_S_zzfs  S_zzfs_110_1 = {&A1VP81LZZ,&fRM_10000_,&var24,&internal1_m110_tx,&internal1_m110_y0};
_S_zzfs  S_zzfs_99_1 = {&var38,&fRM_10_,&var25,&internal1_m99_tx,&internal1_m99_y0};
_S_zzfs  S_zzfs_112_1 = {&var41,&fRM_10_,&var26,&internal1_m112_tx,&internal1_m112_y0};
_S_zzfs  S_zzfs_140_1 = {&B0VP81LZZ,&fRM_10000_,&var27,&internal1_m140_tx,&internal1_m140_y0};
_S_zzfs  S_zzfs_139_1 = {&A0VP81LZZ,&fRM_10000_,&var28,&internal1_m139_tx,&internal1_m139_y0};
_S_or3  S_or3_313_1 = {&var32,&var31,&var30,&var29};
_S_or2  S_or2_317_1 = {&R0DEB3LZ2,&R0DEB4LZ2,&var30};
_S_or2  S_or2_311_1 = {&R0DEB1LZ2,&R0DEB2LZ2,&var31};
_S_diagndev  S_diagndev_307_1 = {array_m307_x_1,&iRM_6_,&var32,&var33};
_S_ma  S_ma_189_1 = {array_m189_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_and2  S_and2_81_1 = {&lRM_1_,&A1EE01LS1,&var34};
_S_and2  S_and2_83_1 = {&lRM_1_,&A1EE01LS2,&var35};
_S_and2  S_and2_85_1 = {&lRM_1_,&A1EE01LS3,&var36};
_S_and2  S_and2_87_1 = {&lRM_1_,&A1EE01LS4,&var37};
_S_or2  S_or2_104_1 = {&var143,&var141,&var38};
_S_and2  S_and2_136_1 = {&var136,&var112,&var39};
_S_and2  S_and2_129_1 = {&var113,&var137,&var40};
_S_or2  S_or2_108_1 = {&var138,&var139,&var41};
_S_and2  S_and2_285_1 = {&var64,&var90,&var42};
_S_and2  S_and2_283_1 = {&var52,&var90,&var43};
_S_and2  S_and2_287_1 = {&var102,&var90,&var44};
_S_schl24  S_schl24_295_1 = {&A1VN71LS2,&A1VN71LS1,&A1VN71LS4,&A1VN71LS3,&var45};
_S_or2  S_or2_299_1 = {&var140,&var142,&var46};
_S_and2  S_and2_286_1 = {&var65,&var90,&var47};
_S_and2  S_and2_284_1 = {&var53,&var90,&var48};
_S_and2  S_and2_258_1 = {&var90,&var52,&var49};
_S_or2  S_or2_255_1 = {&var62,&var60,&var50};
_S_and2  S_and2_264_1 = {&var61,&var90,&var51};
_S_or2  S_or2_261_1 = {&var54,&var62,&var52};
_S_or2  S_or2_263_1 = {&var54,&var60,&var53};
_S_and2  S_and2_262_1 = {&var61,&var121,&var54};
_S_and2  S_and2_259_1 = {&var90,&var53,&var55};
_S_or2  S_or2_271_1 = {&R0VN76LZ2,&var124,&var56};
_S_or2  S_or2_272_1 = {&R0VN78LZ2,&var123,&var57};
_S_or2  S_or2_269_1 = {&R0VN75LZ2,&var126,&var58};
_S_or2  S_or2_270_1 = {&R0VN77LZ2,&var125,&var59};
_S_and2  S_and2_268_1 = {&var56,&var57,&var60};
_S_schl24  S_schl24_266_1 = {&var58,&var59,&var56,&var57,&var61};
_S_and2  S_and2_267_1 = {&var58,&var59,&var62};
_S_or2  S_or2_254_1 = {&var72,&var76,&var63};
_S_or2  S_or2_246_1 = {&var67,&var76,&var64};
_S_or2  S_or2_248_1 = {&var67,&var72,&var65};
_S_and2  S_and2_242_1 = {&var73,&var90,&var66};
_S_and2  S_and2_247_1 = {&var73,&var122,&var67};
_S_and2  S_and2_250_1 = {&var64,&var90,&var68};
_S_and2  S_and2_251_1 = {&var90,&var65,&var69};
_S_or2  S_or2_235_1 = {&R0VN72LZ2,&var124,&var70};
_S_or2  S_or2_236_1 = {&R0VN74LZ2,&var123,&var71};
_S_and2  S_and2_238_1 = {&var71,&var70,&var72};
_S_schl24  S_schl24_240_1 = {&var75,&var74,&var70,&var71,&var73};
_S_or2  S_or2_233_1 = {&R0VN71LZ2,&var126,&var74};
_S_or2  S_or2_234_1 = {&R0VN73LZ2,&var125,&var75};
_S_and2  S_and2_237_1 = {&var75,&var74,&var76};
_S_and2  S_and2_288_1 = {&var103,&var90,&var77};
_S_or3  S_or3_30_1 = {&var99,&var64,&var52,&var78};
_S_and2  S_and2_31_1 = {&var78,&var90,&var79};
_S_or2  S_or2_25_1 = {&var118,&var119,&var80};
_S_and2  S_and2_19_1 = {&var82,&var90,&var81};
_S_or3  S_or3_18_1 = {&var65,&var53,&var98,&var82};
_S_and2  S_and2_6_1 = {&var35,&var37,&var83};
_S_or2  S_or2_8_1 = {&var120,&var83,&var84};
_S_or2  S_or2_11_1 = {&var89,&var120,&var85};
_S_or2  S_or2_160_1 = {&var109,&var111,&var86};
_S_or2  S_or2_35_1 = {&B2IS12LDU,&A2IS12LDU,&var87};
_S_or2  S_or2_156_1 = {&var144,&var106,&var88};
_S_and2  S_and2_5_1 = {&var36,&var34,&var89};
_S_and2  S_and2_22_1 = {&var100,&var96,&var90};
_S_and2  S_and2_186_1 = {&var101,&var128,&var91};
_S_and2  S_and2_185_1 = {&var129,&var101,&var92};
_S_noto  S_noto_142_1 = {&var27,&var93};
_S_noto  S_noto_141_1 = {&var28,&var94};
_S_noto  S_noto_116_1 = {&var23,&var95};
_S_noto  S_noto_27_1 = {&var97,&var96};
_S_ovb1  S_ovb1_33_1 = {&var87,&iRM_200_,&var97,&internal1_m33_tx};
_S_noto  S_noto_14_1 = {&var84,&var98};
_S_noto  S_noto_13_1 = {&var85,&var99};
_S_noto  S_noto_24_1 = {&R0EE02LDU,&var100};
_S_bol  S_bol_181_1 = {&var130,&fRM_0_00001,&var101};
_S_noto  S_noto_289_1 = {&var84,&var102};
_S_noto  S_noto_290_1 = {&var85,&var103};
_S_scalzz  S_scalzz_150_1 = {&B0IT02IZ2,&iRM_3276_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var104,&internal1_m150_y0};
_S_scalzz  S_scalzz_148_1 = {&A0IT02IZ2,&iRM_3276_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var105,&internal1_m148_y0};
_S_geterr  S_geterr_152_1 = {&var105,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var106};
_S_scalzz  S_scalzz_92_1 = {&B2IP01IZ2,&iRM_3276_,&iRM_16000_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var107,&internal1_m92_y0};
_S_scalzz  S_scalzz_90_1 = {&A2IP01IZ2,&iRM_3276_,&iRM_16000_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var108,&internal1_m90_y0};
_S_drg  S_drg_161_1 = {&var104,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var109,&internal1_m161_y1};
_S_drg  S_drg_172_1 = {&var104,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var110,&internal1_m172_y1};
_S_geterr  S_geterr_154_1 = {&var104,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var111};
_S_noto  S_noto_137_1 = {&var138,&var112};
_S_noto  S_noto_128_1 = {&var143,&var113};
_S_noto  S_noto_115_1 = {&var24,&var114};
_S_srm  S_srm_293_1 = {array_m293_x_1,array_m293_diag_1,&iRM_4_,&iRM_3_,&var115,&vainSBool};
_S_rsu  S_rsu_281_1 = {&var2,&var117,&var116,&internal1_m281_q0};
_S_orni  S_orni_282_1 = {array_m282_x_1,&iRM_17_,&vainSBool,&var117};
_S_orn  S_orn_16_1 = {array_m16_x_1,&iRM_6_,&var118};
_S_orn  S_orn_36_1 = {array_m36_x_1,&iRM_6_,&var119};
_S_noto  S_noto_7_1 = {&var131,&var120};
_S_noto  S_noto_257_1 = {&var50,&var121};
_S_noto  S_noto_252_1 = {&var63,&var122};
_S_noto  S_noto_241_1 = {&A1EE01LS4,&var123};
_S_noto  S_noto_245_1 = {&A1EE01LS2,&var124};
_S_noto  S_noto_244_1 = {&A1EE01LS3,&var125};
_S_noto  S_noto_239_1 = {&A1EE01LS1,&var126};
_S_react  S_react_177_1 = {&var130,&var127};
_S_bol  S_bol_182_1 = {&fEM_R0UR04RZZ,&var130,&var128};
_S_bol  S_bol_180_1 = {&fEM_R0UR01RZZ,&var130,&var129};
_S_srm  S_srm_2_1 = {array_m2_x_1,array_m2_diag_1,&iRM_4_,&iRM_3_,&var130,&var131};
_S_ornc  S_ornc_3_1 = {array_m3_x_1,&iRM_3_,&var132,&var133};
_S_ornc  S_ornc_12_1 = {array_m12_x_1,&iRM_3_,&var134,&var135};
_S_tprg  S_tprg_130_1 = {&var107,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var136,&internal1_m130_y0};
_S_tprg  S_tprg_124_1 = {&var108,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var137,&internal1_m124_y0};
_S_geterr  S_geterr_100_1 = {&var107,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var138};
_S_drg  S_drg_107_1 = {&var107,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var139,&internal1_m107_y1};
_S_drg  S_drg_120_1 = {&var107,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var140,&internal1_m120_y1};
_S_drg  S_drg_94_1 = {&var108,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var141,&internal1_m94_y1};
_S_drg  S_drg_105_1 = {&var108,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var142,&internal1_m105_y1};
_S_geterr  S_geterr_96_1 = {&var108,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var143};
_S_drg  S_drg_159_1 = {&var105,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var144,&internal1_m159_y1};
_S_drg  S_drg_170_1 = {&var105,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var145,&internal1_m170_y1};


void ZeroVar()
{
   var1.b=0;
   var2.b=0;
   var3.b=0;
   var4.b=0;
   var5.b=0;
   var6.b=0;
   var7.b=0;
   var8.b=0;
   var9.b=0;
   var10.b=0;
   var11.b=0;
   var12.b=0;
   var13.b=0;
   var14.b=0;
   var15.b=0;
   var16.b=0;
   var17.b=0;
   var18.b=0;
   var19.b=0;
   var20.b=0;
   var21.b=0;
   var22.b=0;
   var23.b=0;
   var24.b=0;
   var25.b=0;
   var26.b=0;
   var27.b=0;
   var28.b=0;
   var29.b=0;
   var30.b=0;
   var31.b=0;
   var32.b=0;
   var33.i=0;
   var34.b=0;
   var35.b=0;
   var36.b=0;
   var37.b=0;
   var38.b=0;
   var39.b=0;
   var40.b=0;
   var41.b=0;
   var42.b=0;
   var43.b=0;
   var44.b=0;
   var45.b=0;
   var46.b=0;
   var47.b=0;
   var48.b=0;
   var49.b=0;
   var50.b=0;
   var51.b=0;
   var52.b=0;
   var53.b=0;
   var54.b=0;
   var55.b=0;
   var56.b=0;
   var57.b=0;
   var58.b=0;
   var59.b=0;
   var60.b=0;
   var61.b=0;
   var62.b=0;
   var63.b=0;
   var64.b=0;
   var65.b=0;
   var66.b=0;
   var67.b=0;
   var68.b=0;
   var69.b=0;
   var70.b=0;
   var71.b=0;
   var72.b=0;
   var73.b=0;
   var74.b=0;
   var75.b=0;
   var76.b=0;
   var77.b=0;
   var78.b=0;
   var79.b=0;
   var80.b=0;
   var81.b=0;
   var82.b=0;
   var83.b=0;
   var84.b=0;
   var85.b=0;
   var86.b=0;
   var87.b=0;
   var88.b=0;
   var89.b=0;
   var90.b=0;
   var91.b=0;
   var92.b=0;
   var93.b=0;
   var94.b=0;
   var95.b=0;
   var96.b=0;
   var97.b=0;
   var98.b=0;
   var99.b=0;
   var100.b=0;
   var101.b=0;
   var102.b=0;
   var103.b=0;
   var104.f=0.0;
   var105.f=0.0;
   var106.b=0;
   var107.f=0.0;
   var108.f=0.0;
   var109.b=0;
   var110.b=0;
   var111.b=0;
   var112.b=0;
   var113.b=0;
   var114.b=0;
   var115.f=0.0;
   var116.l=0L;
   var117.l=0L;
   var118.b=0;
   var119.b=0;
   var120.b=0;
   var121.b=0;
   var122.b=0;
   var123.b=0;
   var124.b=0;
   var125.b=0;
   var126.b=0;
   var127.f=0.0;
   var128.b=0;
   var129.b=0;
   var130.f=0.0;
   var131.b=0;
   var132.b=0;
   var133.c=0;
   var134.b=0;
   var135.c=0;
   var136.b=0;
   var137.b=0;
   var138.b=0;
   var139.b=0;
   var140.b=0;
   var141.b=0;
   var142.b=0;
   var143.b=0;
   var144.b=0;
   var145.b=0;
   vainSLong.l=0L;
   vainSFloat.f=0.0;
   vainSInt.i=0;
   vainSBool.b=0;
   vainSChar.c=0;

}
int freebuff = 0, delay = 0;
void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  noto(&S_noto_239_1);
  noto(&S_noto_244_1);
  noto(&S_noto_245_1);
  noto(&S_noto_241_1);
  scalzz(&S_scalzz_90_1);
  scalzz(&S_scalzz_92_1);
  scalzz(&S_scalzz_148_1);
  scalzz(&S_scalzz_150_1);
  or2(&S_or2_234_1);
  or2(&S_or2_233_1);
  or2(&S_or2_236_1);
  or2(&S_or2_235_1);
  or2(&S_or2_270_1);
  or2(&S_or2_269_1);
  or2(&S_or2_272_1);
  or2(&S_or2_271_1);
  schl24(&S_schl24_295_1);
  ma(&S_ma_189_1);
  diagndev(&S_diagndev_307_1);
  or2(&S_or2_311_1);
  or2(&S_or2_317_1);
  or3(&S_or3_313_1);
  zzfs(&S_zzfs_139_1);
  zzfs(&S_zzfs_140_1);
  zzfs(&S_zzfs_110_1);
  zzfs(&S_zzfs_111_1);
  noto(&S_noto_200_1);
  noto(&S_noto_219_1);
  noto(&S_noto_201_1);
  or2(&S_or2_199_1);
  or2(&S_or2_206_1);
  or2(&S_or2_218_1);
  or3(&S_or3_228_1);
  zzfs(&S_zzfs_210_1);
  drg(&S_drg_170_1);
  drg(&S_drg_159_1);
  geterr(&S_geterr_96_1);
  drg(&S_drg_105_1);
  drg(&S_drg_94_1);
  drg(&S_drg_120_1);
  drg(&S_drg_107_1);
  geterr(&S_geterr_100_1);
  tprg(&S_tprg_124_1);
  tprg(&S_tprg_130_1);
  noto(&S_noto_115_1);
  noto(&S_noto_128_1);
  noto(&S_noto_137_1);
  geterr(&S_geterr_154_1);
  drg(&S_drg_172_1);
  drg(&S_drg_161_1);
  geterr(&S_geterr_152_1);
  noto(&S_noto_24_1);
  noto(&S_noto_116_1);
  noto(&S_noto_141_1);
  noto(&S_noto_142_1);
  or2(&S_or2_156_1);
  or2(&S_or2_35_1);
  or2(&S_or2_160_1);
  and2(&S_and2_237_1);
  schl24(&S_schl24_240_1);
  and2(&S_and2_238_1);
  or2(&S_or2_254_1);
  and2(&S_and2_267_1);
  schl24(&S_schl24_266_1);
  and2(&S_and2_268_1);
  or2(&S_or2_255_1);
  or2(&S_or2_299_1);
  or2(&S_or2_108_1);
  and2(&S_and2_129_1);
  and2(&S_and2_136_1);
  or2(&S_or2_104_1);
  and2(&S_and2_87_1);
  and2(&S_and2_85_1);
  and2(&S_and2_83_1);
  and2(&S_and2_81_1);
  zzfs(&S_zzfs_112_1);
  zzfs(&S_zzfs_99_1);
  or2(&S_or2_216_1);
  noto(&S_noto_224_1);
  ornc(&S_ornc_12_1);
  ornc(&S_ornc_3_1);
  srm(&S_srm_2_1);
  bol(&S_bol_180_1);
  bol(&S_bol_182_1);
  react(&S_react_177_1);
  noto(&S_noto_252_1);
  noto(&S_noto_257_1);
  noto(&S_noto_7_1);
  srm(&S_srm_293_1);
  bol(&S_bol_181_1);
  ovb1(&S_ovb1_33_1);
  noto(&S_noto_27_1);
  and2(&S_and2_185_1);
  and2(&S_and2_186_1);
  and2(&S_and2_22_1);
  and2(&S_and2_5_1);
  or2(&S_or2_11_1);
  and2(&S_and2_6_1);
  and2(&S_and2_247_1);
  and2(&S_and2_242_1);
  or2(&S_or2_248_1);
  or2(&S_or2_246_1);
  and2(&S_and2_262_1);
  or2(&S_or2_263_1);
  or2(&S_or2_261_1);
  and2(&S_and2_264_1);
  and2(&S_and2_258_1);
  and2(&S_and2_284_1);
  and2(&S_and2_286_1);
  and2(&S_and2_283_1);
  and2(&S_and2_285_1);
  and2(&S_and2_215_1);
  inicn(&S_inicn_205_1);
  and2(&S_and2_227_1);
  zzfs(&S_zzfs_214_1);
  noto(&S_noto_290_1);
  noto(&S_noto_13_1);
  or2(&S_or2_8_1);
  or3(&S_or3_30_1);
  and2(&S_and2_288_1);
  and2(&S_and2_251_1);
  and2(&S_and2_250_1);
  and2(&S_and2_259_1);
  zpfs(&S_zpfs_226_1);
  or2(&S_or2_279_1);
  noto(&S_noto_289_1);
  noto(&S_noto_14_1);
  or3(&S_or3_18_1);
  and2(&S_and2_19_1);
  and2(&S_and2_31_1);
  and2(&S_and2_287_1);
  orn(&S_orn_36_1);
  orn(&S_orn_16_1);
  orni(&S_orni_282_1);
  rsu(&S_rsu_281_1);
  or2(&S_or2_25_1);
  setData(idR0AD14LZ2,&var13);
  setData(idA3VZ13LZ2,&var9);
  setData(idA3VZ15LZ2,&var12);
  setData(idB3VZ11LZ2,&var11);
  setData(idA3VZ11LZ2,&var10);
  setData(idB3VZ31LZ2,&var8);
  setData(idA3VZ31LZ2,&var7);
  setData(idR0VZ05U,&var117);
  setData(idTestDiagnBaz2,&var29);
  setData(idR0DE3DLZ2,&var30);
  setData(idR0DE3CLZ2,&var31);
  setData(idTTLBaz2,&var33);
  moveData(idR0EE04LZ2,idR0EE02LDU);
  moveData(idR0EE03LZ2,idR0EE02LDU);
  moveData(idR0EE02LZ2,idR0EE02LDU);
  moveData(idR0EE01LZ2,idR0EE02LDU);
  setData(idA1VN71LZ2,&var45);
  setData(idB0VT71LZ2,&var86);
  setData(idB0VT61LZ2,&var110);
  setData(idB0CT01IZ2,&var104);
  setData(idR0VP73LZ2,&var46);
  setData(idR0VN11RZ2,&var115);
  setData(idR0VZ05UZ2,&var116);
  setData(idB0VN81LZ2,&var55);
  setData(idA0VN81LZ2,&var49);
  setData(idB0VN71LZ2,&var69);
  setData(idA0VN71LZ2,&var68);
  setData(idB0VZ71LZ2,&var118);
  setData(idB0EE00LZ2,&var84);
  setData(idA0EE00LZ2,&var85);
  setData(idA0VZ71LZ2,&var119);
  setData(idA0EE03LZ2,&var36);
  setData(idA0EE02LZ2,&var35);
  setData(idA0EE04LZ2,&var37);
  setData(idA0EE01LZ2,&var34);
  setData(idR0VN80LZ2,&var51);
  setData(idR0VN70LZ2,&var66);
  setData(idR0VZ71LZ2,&var80);
  setData(idR0VR02RZ2,&var127);
  setData(idR0VN79LZ2,&var91);
  setData(idR0VN69LZ2,&var92);
  setData(idR0VN09RZ2,&var130);
  moveData(idR0VN68LZ2,idR0VN65LS4);
  moveData(idR0VN67LZ2,idR0VN65LS3);
  moveData(idR0VN66LZ2,idR0VN65LS2);
  moveData(idR0VN65LZ2,idR0VN65LS1);
  moveData(idR0VN64LZ2,idR0VN61LS4);
  moveData(idR0VN63LZ2,idR0VN61LS3);
  moveData(idR0VN62LZ2,idR0VN61LS2);
  moveData(idR0VN61LZ2,idR0VN61LS1);
  moveData(idR0VN08RZ2,idR0VN01RS4);
  moveData(idR0VN07RZ2,idR0VN01RS3);
  moveData(idR0VN06RZ2,idR0VN01RS2);
  moveData(idR0VN05RZ2,idR0VN01RS1);
  moveData(idR0VN04RZ2,idR0VN02RS4);
  moveData(idR0VN03RZ2,idR0VN02RS3);
  moveData(idR0VN02RZ2,idR0VN02RS2);
  moveData(idR0VN01RZ2,idR0VN02RS1);
  setData(idB0VP71LZ2,&var134);
  setData(idA0VP71LZ2,&var132);
  setData(idA0EP02IZ2,&var133);
  setData(idB0EP02IZ2,&var135);
  setData(idR0ET02LZ2,&var111);
  setData(idB0VP41LZ2,&var93);
  setData(idA0VP41LZ2,&var94);
  setData(idR0ET01LZ2,&var106);
  setData(idA2VP81LZ2,&var40);
  setData(idB2VP81LZ2,&var39);
  setData(idB2VP51LZ2,&var140);
  setData(idB2CP01RZ2,&var107);
  setData(idB2VP41LZ2,&var26);
  setData(idA2VP51LZ2,&var142);
  setData(idA2CP01RZ2,&var108);
  setData(idA2VP41LZ2,&var25);
  setData(idB1VP41LZ2,&var95);
  setData(idA1VP41LZ2,&var114);
  setData(idA0VT71LZ2,&var88);
  setData(idA0VT61LZ2,&var145);
  setData(idA0CT01IZ2,&var105);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}

void MainCycle(void)
{
if ((getAsShort(idR0MW11IP1) == 2) || (getAsShort(idR0MW11IP1) == 3)) { 
     if(delay++ < 100) return;
     freebuff = 0;
     delay = delay > 32000 ? 32000 : delay; 
       Scheme(); 
 }
 else {
      delay = 0;
      if (freebuff)
            return;
       else{
           freebuff = 1;
           memset(BUFFER, 0, SIZE_BUFFER);
           InitSetConst();
           ZeroVar();
           if (SimulOn) {
                 if (initAllSimul(CodeSub, drivers, SimulIP, SimulPort))
           return EXIT_FAILURE;
           } else {
                 if (initAllDrivers(drivers))
                 return EXIT_FAILURE;
           }
           }
       }


}
#endif
