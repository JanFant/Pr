#ifndef BAZ1_H
#define BAZ1_H
// Подсистема Baz1:Baz1
static char SimulOn=0;
static short CodeSub=4;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt, taktScheme=0, taktSS=0;
#define SIZE_BUFFER 638
static char BUFFER[638];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.52\0", 5432, "192.168.10.152\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0VZ05UZ1	 BUFFER[0]	//( - , Baz1) Индикатор причины сброса
#define idR0VZ05UZ1	 1	//( - , Baz1) Индикатор причины сброса
#define R0VN11RZ1	 BUFFER[5]	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
#define idR0VN11RZ1	 2	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
#define R0VP73LZ1	 BUFFER[10]	//( - , Baz1, SBz1DU) ПС давления для РУ
#define idR0VP73LZ1	 3	//( - , Baz1, SBz1DU) ПС давления для РУ
#define B0CT01IZ1	 BUFFER[12]	//( - , Baz1, SBz1DU) Температура АЗ2-1
#define idB0CT01IZ1	 4	//( - , Baz1, SBz1DU) Температура АЗ2-1
#define B0VT61LZ1	 BUFFER[17]	//( - , Baz1) ПС по температуре в АЗ2
#define idB0VT61LZ1	 5	//( - , Baz1) ПС по температуре в АЗ2
#define B0VT71LZ1	 BUFFER[19]	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
#define idB0VT71LZ1	 6	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
#define A0VN71LS1	 BUFFER[21]	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
#define idA0VN71LS1	 7	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
#define A0VN71LS2	 BUFFER[23]	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
#define idA0VN71LS2	 8	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
#define A0VN71LS3	 BUFFER[25]	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
#define idA0VN71LS3	 9	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
#define A0VN71LS4	 BUFFER[27]	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
#define idA0VN71LS4	 10	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
#define A1VN71LZ1	 BUFFER[29]	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	 11	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
#define A3VZ15LZ1	 BUFFER[31]	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
#define idA3VZ15LZ1	 12	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
#define A3VZ13LZ1	 BUFFER[33]	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
#define idA3VZ13LZ1	 13	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
#define R0VW13LDU	 BUFFER[35]	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 14	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	 BUFFER[37]	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 15	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R7II73LZ1	 BUFFER[39]	//(vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
#define idR7II73LZ1	 16	//(vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
#define R7II71LZ1	 BUFFER[41]	//(vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
#define idR7II71LZ1	 17	//(vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
#define R7II72LZ1	 BUFFER[43]	//(vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
#define idR7II72LZ1	 18	//(vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
#define R0AD14LZ1	 BUFFER[45]	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define idR0AD14LZ1	 19	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define A0EE01LS4	 BUFFER[47]	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define idA0EE01LS4	 20	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define A0EE01LS3	 BUFFER[49]	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define idA0EE01LS3	 21	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define A0EE01LZ1	 BUFFER[51]	//( - , Baz1, SBz1DU) Исправность АКНП1
#define idA0EE01LZ1	 22	//( - , Baz1, SBz1DU) Исправность АКНП1
#define A0EE04LZ1	 BUFFER[53]	//( - , Baz1, SBz1DU) Исправность АКНП4
#define idA0EE04LZ1	 23	//( - , Baz1, SBz1DU) Исправность АКНП4
#define A0EE02LZ1	 BUFFER[55]	//( - , Baz1, SBz1DU) Исправность АКНП2
#define idA0EE02LZ1	 24	//( - , Baz1, SBz1DU) Исправность АКНП2
#define A0EE03LZ1	 BUFFER[57]	//( - , Baz1, SBz1DU) Исправность АКНП3
#define idA0EE03LZ1	 25	//( - , Baz1, SBz1DU) Исправность АКНП3
#define A0EE01LS2	 BUFFER[59]	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define idA0EE01LS2	 26	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define A0EE05LZ1	 BUFFER[61]	//( - , Baz1) Исправность сети АКНП1
#define idA0EE05LZ1	 27	//( - , Baz1) Исправность сети АКНП1
#define A0EE06LZ1	 BUFFER[63]	//( - , Baz1) Исправность сети АКНП2
#define idA0EE06LZ1	 28	//( - , Baz1) Исправность сети АКНП2
#define A0EE07LZ1	 BUFFER[65]	//( - , Baz1) Исправность сети АКНП3
#define idA0EE07LZ1	 29	//( - , Baz1) Исправность сети АКНП3
#define A0EE08LZ1	 BUFFER[67]	//( - , Baz1) Исправность сети АКНП4
#define idA0EE08LZ1	 30	//( - , Baz1) Исправность сети АКНП4
#define A0VZ71LZ1	 BUFFER[69]	//( - , Baz1) Обобщенный сигнал АС по АЗ1
#define idA0VZ71LZ1	 31	//( - , Baz1) Обобщенный сигнал АС по АЗ1
#define A0EE00LZ1	 BUFFER[71]	//( - , Baz1) Исправность АКНП АЗ1
#define idA0EE00LZ1	 32	//( - , Baz1) Исправность АКНП АЗ1
#define B0EE00LZ1	 BUFFER[73]	//( - , Baz1) Исправность АКНП АЗ2
#define idB0EE00LZ1	 33	//( - , Baz1) Исправность АКНП АЗ2
#define B0VZ71LZ1	 BUFFER[75]	//( - , Baz1) Обобщенный сигнал АС по АЗ2
#define idB0VZ71LZ1	 34	//( - , Baz1) Обобщенный сигнал АС по АЗ2
#define A0VN71LZ1	 BUFFER[77]	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
#define idA0VN71LZ1	 35	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
#define B0VN71LZ1	 BUFFER[79]	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
#define idB0VN71LZ1	 36	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
#define A0VN81LZ1	 BUFFER[81]	//( - , Baz1) АЗ по АС периода разгона АЗ1
#define idA0VN81LZ1	 37	//( - , Baz1) АЗ по АС периода разгона АЗ1
#define B0VN81LZ1	 BUFFER[83]	//( - , Baz1) АЗ по АС периода разгона АЗ2
#define idB0VN81LZ1	 38	//( - , Baz1) АЗ по АС периода разгона АЗ2
#define R0EE02LDU	 BUFFER[85]	//( - , Baz1) Питание  АКНП  отключить
#define idR0EE02LDU	 39	//( - , Baz1) Питание  АКНП  отключить
#define B2IS12LDU	 BUFFER[87]	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	 40	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define R0DE04LZ1	 BUFFER[89]	//(vas84:04 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
#define idR0DE04LZ1	 41	//(vas84:04 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
#define R0DE05LZ1	 BUFFER[92]	//(vds32:05 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
#define idR0DE05LZ1	 42	//(vds32:05 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
#define R0DE06LZ1	 BUFFER[95]	//(vds32:06 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
#define idR0DE06LZ1	 43	//(vds32:06 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
#define R0DE08LZ1	 BUFFER[98]	//(vds32:08 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
#define idR0DE08LZ1	 44	//(vds32:08 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
#define R0DE07LZ1	 BUFFER[101]	//(vds32:07 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
#define idR0DE07LZ1	 45	//(vds32:07 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
#define R0DE0ALZ1	 BUFFER[104]	//(fds16:0a - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
#define idR0DE0ALZ1	 46	//(fds16:0a - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
#define TTLBaz1	 BUFFER[107]	//( - , Baz1) ttl
#define idTTLBaz1	 47	//( - , Baz1) ttl
#define R0DEB1LZ1	 BUFFER[110]	//(sbk:20 - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
#define idR0DEB1LZ1	 48	//(sbk:20 - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
#define R0DEB2LZ1	 BUFFER[112]	//(sbk:20 - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
#define idR0DEB2LZ1	 49	//(sbk:20 - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
#define R0DEB4LZ1	 BUFFER[114]	//(sbk:20 - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
#define idR0DEB4LZ1	 50	//(sbk:20 - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
#define R0DEB3LZ1	 BUFFER[116]	//(sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
#define idR0DEB3LZ1	 51	//(sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
#define R0DE3CLZ1	 BUFFER[118]	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 5
#define idR0DE3CLZ1	 52	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 5
#define R0DE3DLZ1	 BUFFER[120]	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 6
#define idR0DE3DLZ1	 53	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 6
#define TestDiagnBaz1	 BUFFER[122]	//( - , Baz1) Неисправность от диагностики
#define idTestDiagnBaz1	 54	//( - , Baz1) Неисправность от диагностики
#define R0MW11IP1	 BUFFER[124]	//( - , Baz1) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 55	//( - , Baz1) Переключатель ВЫСТРЕЛ
#define R0VZ05U	 BUFFER[127]	//( - , - ) причины сброса
#define idR0VZ05U	 56	//( - , - ) причины сброса
#define B8VC01RDU	 BUFFER[132]	//( - , SBz1DU, MBz1A1, MBz1A2, MBz1A3, MBz1A4) Координата АЗ2, мм
#define idB8VC01RDU	 57	//( - , SBz1DU, MBz1A1, MBz1A2, MBz1A3, MBz1A4) Координата АЗ2, мм
#define R0S01LZ1	 BUFFER[137]	//(vds32:08 - K08VDSR, - ) Отключение сетевых передач в Баз1
#define idR0S01LZ1	 58	//(vds32:08 - K08VDSR, - ) Отключение сетевых передач в Баз1
#define R0AD21LDU	 BUFFER[139]	//( - , SBz1DU) Подключить защиту от II УР
#define idR0AD21LDU	 59	//( - , SBz1DU) Подключить защиту от II УР
#define R0MD34LP1	 BUFFER[141]	//( - , Baz1) Кнопка (Квитировать)
#define idR0MD34LP1	 60	//( - , Baz1) Кнопка (Квитировать)
#define R0AD04LZ1	 BUFFER[143]	//(vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
#define idR0AD04LZ1	 61	//(vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
#define R0EE01LZ1	 BUFFER[145]	//( - , MBz1S) Питание  АКНП1  отключить
#define idR0EE01LZ1	 62	//( - , MBz1S) Питание  АКНП1  отключить
#define R6IS66LZZ	 BUFFER[147]	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 63	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[149]	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 64	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[151]	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 65	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define R0VN71LZ1	 BUFFER[153]	//(vds32:05 - K01VDSR, Baz1) АС по мощности канал 1
#define idR0VN71LZ1	 66	//(vds32:05 - K01VDSR, Baz1) АС по мощности канал 1
#define R0VN75LZ1	 BUFFER[155]	//(vds32:05 - K02VDSR, Baz1) АС по периоду разгона канал 1
#define idR0VN75LZ1	 67	//(vds32:05 - K02VDSR, Baz1) АС по периоду разгона канал 1
#define R0VN72LZ1	 BUFFER[157]	//(vds32:06 - K01VDSR, Baz1) АС по мощности канал 2
#define idR0VN72LZ1	 68	//(vds32:06 - K01VDSR, Baz1) АС по мощности канал 2
#define R0VN76LZ1	 BUFFER[159]	//(vds32:06 - K02VDSR, Baz1) АС по периоду разгона канал  2
#define idR0VN76LZ1	 69	//(vds32:06 - K02VDSR, Baz1) АС по периоду разгона канал  2
#define R0VN73LZ1	 BUFFER[161]	//(vds32:08 - K01VDSR, Baz1) АС по мощности канал 3
#define idR0VN73LZ1	 70	//(vds32:08 - K01VDSR, Baz1) АС по мощности канал 3
#define R0VN77LZ1	 BUFFER[163]	//(vds32:08 - K02VDSR, Baz1) АС по периоду разгона канал  3
#define idR0VN77LZ1	 71	//(vds32:08 - K02VDSR, Baz1) АС по периоду разгона канал  3
#define R0VN74LZ1	 BUFFER[165]	//(vds32:07 - K01VDSR, Baz1) АС по мощности канал 4
#define idR0VN74LZ1	 72	//(vds32:07 - K01VDSR, Baz1) АС по мощности канал 4
#define R0VN78LZ1	 BUFFER[167]	//(vds32:07 - K02VDSR, Baz1) АС по периоду разгона канал  4
#define idR0VN78LZ1	 73	//(vds32:07 - K02VDSR, Baz1) АС по периоду разгона канал  4
#define R0EE02LZ1	 BUFFER[169]	//( - , MBz1S) Питание  АКНП2  отключить
#define idR0EE02LZ1	 74	//( - , MBz1S) Питание  АКНП2  отключить
#define R0EE03LZ1	 BUFFER[171]	//( - , MBz1S) Питание  АКНП3  отключить
#define idR0EE03LZ1	 75	//( - , MBz1S) Питание  АКНП3  отключить
#define R0EE04LZ1	 BUFFER[173]	//( - , MBz1S) Питание  АКНП4  отключить
#define idR0EE04LZ1	 76	//( - , MBz1S) Питание  АКНП4  отключить
#define R0MW12IP2	 BUFFER[175]	//( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define idR0MW12IP2	 77	//( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define A2IS12LDU	 BUFFER[178]	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	 78	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define A0VP41LZ1	 BUFFER[180]	//( - , Baz1) Давление АЗ1 ниже АС
#define idA0VP41LZ1	 79	//( - , Baz1) Давление АЗ1 ниже АС
#define B0VP41LZ1	 BUFFER[182]	//( - , Baz1) Давление АЗ2 ниже АС
#define idB0VP41LZ1	 80	//( - , Baz1) Давление АЗ2 ниже АС
#define B0VP81LZZ	 BUFFER[184]	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	 81	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define A0VP81LZZ	 BUFFER[186]	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define idA0VP81LZZ	 82	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define R0ET02LZ1	 BUFFER[188]	//( - , Baz1) Признак наличия неисправности по температуре АЗ2
#define idR0ET02LZ1	 83	//( - , Baz1) Признак наличия неисправности по температуре АЗ2
#define B0EP02IZ1	 BUFFER[190]	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
#define idB0EP02IZ1	 84	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
#define A0EP02IZ1	 BUFFER[193]	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
#define idA0EP02IZ1	 85	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
#define A0VP71LZ1	 BUFFER[196]	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	 86	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
#define B0VP71LZ1	 BUFFER[198]	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	 87	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
#define R0VN02RS1	 BUFFER[200]	//( - , MBz1A1) Уровень мощности канал 1
#define idR0VN02RS1	 88	//( - , MBz1A1) Уровень мощности канал 1
#define R0VN02RS2	 BUFFER[205]	//( - , MBz1A2) Уровень мощности канал 2
#define idR0VN02RS2	 89	//( - , MBz1A2) Уровень мощности канал 2
#define R0VN02RS3	 BUFFER[210]	//( - , MBz1A3) Уровень мощности канал 3
#define idR0VN02RS3	 90	//( - , MBz1A3) Уровень мощности канал 3
#define R0VN02RS4	 BUFFER[215]	//( - , MBz1A4) Уровень мощности канал 4
#define idR0VN02RS4	 91	//( - , MBz1A4) Уровень мощности канал 4
#define R0VN01RS1	 BUFFER[220]	//( - , MBz1A1) Период разгона канал 1
#define idR0VN01RS1	 92	//( - , MBz1A1) Период разгона канал 1
#define R0VN01RS2	 BUFFER[225]	//( - , MBz1A2) Период разгона канал 2
#define idR0VN01RS2	 93	//( - , MBz1A2) Период разгона канал 2
#define R0VN01RS3	 BUFFER[230]	//( - , MBz1A3) Период разгона канал 3
#define idR0VN01RS3	 94	//( - , MBz1A3) Период разгона канал 3
#define R0VN01RS4	 BUFFER[235]	//( - , MBz1A4) Период разгона канал 4
#define idR0VN01RS4	 95	//( - , MBz1A4) Период разгона канал 4
#define R0VN61LS1	 BUFFER[240]	//( - , MBz1A1) ПС по мощности канал 1
#define idR0VN61LS1	 96	//( - , MBz1A1) ПС по мощности канал 1
#define R0VN61LS2	 BUFFER[242]	//( - , MBz1A2) ПС по мощности канал 2
#define idR0VN61LS2	 97	//( - , MBz1A2) ПС по мощности канал 2
#define A0IT01IZ1	 BUFFER[244]	//(vas84:04 - K01VASR, - ) Температура АЗ1-1
#define idA0IT01IZ1	 98	//(vas84:04 - K01VASR, - ) Температура АЗ1-1
#define A0CT01IZ1	 BUFFER[247]	//( - , Baz1, SBz1DU) Температура АЗ1-1
#define idA0CT01IZ1	 99	//( - , Baz1, SBz1DU) Температура АЗ1-1
#define A0VT61LZ1	 BUFFER[252]	//( - , Baz1) ПС по температуре в АЗ1
#define idA0VT61LZ1	 100	//( - , Baz1) ПС по температуре в АЗ1
#define A0VT71LZ1	 BUFFER[254]	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
#define idA0VT71LZ1	 101	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
#define A1VP41LZ1	 BUFFER[256]	//( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	 102	//( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
#define B1VP41LZ1	 BUFFER[258]	//( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	 103	//( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
#define B1VP81LZZ	 BUFFER[260]	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	 104	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define A1VP81LZZ	 BUFFER[262]	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	 105	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define A2VP41LZ1	 BUFFER[264]	//( - , Baz1) Давление СБРОС РБ1 ниже АС
#define idA2VP41LZ1	 106	//( - , Baz1) Давление СБРОС РБ1 ниже АС
#define A2CP01RZ1	 BUFFER[266]	//( - , Baz1) Текущее давление СБРОС РБ1
#define idA2CP01RZ1	 107	//( - , Baz1) Текущее давление СБРОС РБ1
#define A2VP51LZ1	 BUFFER[271]	//( - , Baz1) Давление СБРОС РБ1 ниже ПС
#define idA2VP51LZ1	 108	//( - , Baz1) Давление СБРОС РБ1 ниже ПС
#define B2VP41LZ1	 BUFFER[273]	//( - , Baz1) Давление СБРОС РБ2 ниже АС
#define idB2VP41LZ1	 109	//( - , Baz1) Давление СБРОС РБ2 ниже АС
#define B2CP01RZ1	 BUFFER[275]	//( - , Baz1) Текущее давление СБРОС РБ2
#define idB2CP01RZ1	 110	//( - , Baz1) Текущее давление СБРОС РБ2
#define B2VP51LZ1	 BUFFER[280]	//( - , Baz1) Давление СБРОС РБ2 ниже ПС
#define idB2VP51LZ1	 111	//( - , Baz1) Давление СБРОС РБ2 ниже ПС
#define B2VP81LZ1	 BUFFER[282]	//( - , Baz1) Давление СБРОС РБ2 в норме
#define idB2VP81LZ1	 112	//( - , Baz1) Давление СБРОС РБ2 в норме
#define A2VP81LZ1	 BUFFER[284]	//( - , Baz1) Давление СБРОС РБ1 в норме
#define idA2VP81LZ1	 113	//( - , Baz1) Давление СБРОС РБ1 в норме
#define A2IP01IZ1	 BUFFER[286]	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	 114	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define B2IP01IZ1	 BUFFER[289]	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	 115	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define R0ET01LZ1	 BUFFER[292]	//( - , Baz1) Признак наличия неисправности по температуре  АЗ1
#define idR0ET01LZ1	 116	//( - , Baz1) Признак наличия неисправности по температуре  АЗ1
#define B0IT01IZ1	 BUFFER[294]	//(vas84:04 - K03VASR, - ) Температура АЗ2-1
#define idB0IT01IZ1	 117	//(vas84:04 - K03VASR, - ) Температура АЗ2-1
#define R0VN67LZ1	 BUFFER[297]	//( - , Baz1) ПС по периоду разгона канал 3
#define idR0VN67LZ1	 118	//( - , Baz1) ПС по периоду разгона канал 3
#define R0VN68LZ1	 BUFFER[299]	//( - , Baz1) ПС по периоду разгона канал 4
#define idR0VN68LZ1	 119	//( - , Baz1) ПС по периоду разгона канал 4
#define R0VN09RZ1	 BUFFER[301]	//( - , Baz1) Усредненный период разгона
#define idR0VN09RZ1	 120	//( - , Baz1) Усредненный период разгона
#define A3IS11LDU	 BUFFER[306]	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define idA3IS11LDU	 121	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define A3IS22LDU	 BUFFER[308]	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define idA3IS22LDU	 122	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define R0AD03LZ1	 BUFFER[310]	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define idR0AD03LZ1	 123	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define B3IS11LDU	 BUFFER[312]	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define idB3IS11LDU	 124	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define A3VZ31LZ1	 BUFFER[314]	//( - , Baz1) АЗ от ВУ ИС1
#define idA3VZ31LZ1	 125	//( - , Baz1) АЗ от ВУ ИС1
#define B3VZ31LZ1	 BUFFER[316]	//( - , Baz1) АЗ от ВУ ИС2
#define idB3VZ31LZ1	 126	//( - , Baz1) АЗ от ВУ ИС2
#define R0AD05LZ1	 BUFFER[318]	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define idR0AD05LZ1	 127	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define A3VZ11LZ1	 BUFFER[320]	//( - , Baz1) АЗ от НУП ИС1
#define idA3VZ11LZ1	 128	//( - , Baz1) АЗ от НУП ИС1
#define B3VZ11LZ1	 BUFFER[322]	//( - , Baz1) АЗ от НУП ИС2
#define idB3VZ11LZ1	 129	//( - , Baz1) АЗ от НУП ИС2
#define B3IS22LDU	 BUFFER[324]	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
#define idB3IS22LDU	 130	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
#define R0VN69LZ1	 BUFFER[326]	//( - , Baz1) ПС по усредненному периоду
#define idR0VN69LZ1	 131	//( - , Baz1) ПС по усредненному периоду
#define R0VN79LZ1	 BUFFER[328]	//( - , Baz1) АС по усредненному периоду
#define idR0VN79LZ1	 132	//( - , Baz1) АС по усредненному периоду
#define R0VR02RZ1	 BUFFER[330]	//( - , Baz1) Усредненная реактивность
#define idR0VR02RZ1	 133	//( - , Baz1) Усредненная реактивность
#define R0VZ71LZ1	 BUFFER[335]	//(fds16:0a - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
#define idR0VZ71LZ1	 134	//(fds16:0a - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
#define R0VN70LZ1	 BUFFER[337]	//( - , Baz1) АЗ по АС мощности РУ
#define idR0VN70LZ1	 135	//( - , Baz1) АЗ по АС мощности РУ
#define R0VN80LZ1	 BUFFER[339]	//( - , Baz1) АЗ по АС периода разгона РУ
#define idR0VN80LZ1	 136	//( - , Baz1) АЗ по АС периода разгона РУ
#define A0EE01LS1	 BUFFER[341]	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define idA0EE01LS1	 137	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define R0VN61LS3	 BUFFER[343]	//( - , MBz1A3) ПС по мощности канал 3
#define idR0VN61LS3	 138	//( - , MBz1A3) ПС по мощности канал 3
#define R0VN61LS4	 BUFFER[345]	//( - , MBz1A4) ПС по мощности канал 4
#define idR0VN61LS4	 139	//( - , MBz1A4) ПС по мощности канал 4
#define R0VN65LS1	 BUFFER[347]	//( - , MBz1A1) ПС по периоду разгона канал 1
#define idR0VN65LS1	 140	//( - , MBz1A1) ПС по периоду разгона канал 1
#define R0VN65LS2	 BUFFER[349]	//( - , MBz1A2) ПС по периоду разгона  канал 2
#define idR0VN65LS2	 141	//( - , MBz1A2) ПС по периоду разгона  канал 2
#define R0VN65LS3	 BUFFER[351]	//( - , MBz1A3) ПС по периоду разгона канал 3
#define idR0VN65LS3	 142	//( - , MBz1A3) ПС по периоду разгона канал 3
#define R0VN65LS4	 BUFFER[353]	//( - , MBz1A4) ПС по периоду разгона канал 4
#define idR0VN65LS4	 143	//( - , MBz1A4) ПС по периоду разгона канал 4
#define R0VN01RZ1	 BUFFER[355]	//( - , Baz1) Уровень мощности по каналу 1
#define idR0VN01RZ1	 144	//( - , Baz1) Уровень мощности по каналу 1
#define R0VN02RZ1	 BUFFER[360]	//( - , Baz1) Уровень мощности по каналу 2
#define idR0VN02RZ1	 145	//( - , Baz1) Уровень мощности по каналу 2
#define R0VN03RZ1	 BUFFER[365]	//( - , Baz1) Уровень мощности по каналу 3
#define idR0VN03RZ1	 146	//( - , Baz1) Уровень мощности по каналу 3
#define R0VN04RZ1	 BUFFER[370]	//( - , Baz1) Уровень мощности по каналу 4
#define idR0VN04RZ1	 147	//( - , Baz1) Уровень мощности по каналу 4
#define R0VN05RZ1	 BUFFER[375]	//( - , Baz1) Период разгона по каналу 1
#define idR0VN05RZ1	 148	//( - , Baz1) Период разгона по каналу 1
#define R0VN06RZ1	 BUFFER[380]	//( - , Baz1) Период разгона по каналу 2
#define idR0VN06RZ1	 149	//( - , Baz1) Период разгона по каналу 2
#define R0VN07RZ1	 BUFFER[385]	//( - , Baz1) Период разгона по каналу 3
#define idR0VN07RZ1	 150	//( - , Baz1) Период разгона по каналу 3
#define R0VN08RZ1	 BUFFER[390]	//( - , Baz1) Период разгона по каналу 4
#define idR0VN08RZ1	 151	//( - , Baz1) Период разгона по каналу 4
#define R0VN61LZ1	 BUFFER[395]	//( - , Baz1) ПС по мощности канал 1
#define idR0VN61LZ1	 152	//( - , Baz1) ПС по мощности канал 1
#define R0VN62LZ1	 BUFFER[397]	//( - , Baz1) ПС по мощности канал 2
#define idR0VN62LZ1	 153	//( - , Baz1) ПС по мощности канал 2
#define R0VN63LZ1	 BUFFER[399]	//( - , Baz1) ПС по мощности канал 3
#define idR0VN63LZ1	 154	//( - , Baz1) ПС по мощности канал 3
#define R0VN64LZ1	 BUFFER[401]	//( - , Baz1) ПС по мощности канал 4
#define idR0VN64LZ1	 155	//( - , Baz1) ПС по мощности канал 4
#define R0VN65LZ1	 BUFFER[403]	//( - , Baz1) ПС по периоду разгона канал 1
#define idR0VN65LZ1	 156	//( - , Baz1) ПС по периоду разгона канал 1
#define R0VN66LZ1	 BUFFER[405]	//( - , Baz1) ПС по периоду разгона канал 2
#define idR0VN66LZ1	 157	//( - , Baz1) ПС по периоду разгона канал 2
#define fEM_R0UT02RZZ	 BUFFER[407]	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	 158	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RZZ	 BUFFER[412]	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	 159	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_A2UP03RZZ	 BUFFER[417]	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define idfEM_A2UP03RZZ	 160	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define fEM_A2UP04RZZ	 BUFFER[422]	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define idfEM_A2UP04RZZ	 161	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define fEM_R0UT72RZZ	 BUFFER[427]	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	 162	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	 BUFFER[432]	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	 163	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	 BUFFER[437]	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	 164	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT61RZZ	 BUFFER[442]	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	 165	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_A2UP41RZZ	 BUFFER[447]	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define idfEM_A2UP41RZZ	 166	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define fEM_A2UP42RZZ	 BUFFER[452]	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define idfEM_A2UP42RZZ	 167	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define fEM_A2UP51RZZ	 BUFFER[457]	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define idfEM_A2UP51RZZ	 168	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define fEM_A2UP81RZZ	 BUFFER[462]	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP81RZZ	 169	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP84RZZ	 BUFFER[467]	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP84RZZ	 170	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP82RZZ	 BUFFER[472]	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP82RZZ	 171	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP52RZZ	 BUFFER[477]	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define idfEM_A2UP52RZZ	 172	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define fEM_A2UP83RZZ	 BUFFER[482]	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP83RZZ	 173	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_R0UR01RZZ	 BUFFER[487]	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RZZ	 174	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R0UR04RZZ	 BUFFER[492]	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define idfEM_R0UR04RZZ	 175	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define fEM_R0UL05RDU	 BUFFER[497]	//(R0UL05RDU) Время задержки АЗ от НУП ИС(сек)
#define idfEM_R0UL05RDU	 176	//(R0UL05RDU) Время задержки АЗ от НУП ИС(сек)
#define fEM_R0UL25RDU	 BUFFER[502]	//(R0UL25RDU) Время задержки АЗ от ВУ ИС сек
#define idfEM_R0UL25RDU	 177	//(R0UL25RDU) Время задержки АЗ от ВУ ИС сек
#define fEM_R0UL07RDU	 BUFFER[507]	//(R0UL07RDU) Время задержки  срабатывания АС II УР
#define idfEM_R0UL07RDU	 178	//(R0UL07RDU) Время задержки  срабатывания АС II УР
#define bFirstEnterFlag	 BUFFER[512]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 179	//(bFirstEnterFlag) 
#define internal1_m210_tx	 BUFFER[514]	//(internal1_m210_tx) tx - время накопленное сек
#define idinternal1_m210_tx	 180	//(internal1_m210_tx) tx - время накопленное сек
#define internal1_m210_y0	 BUFFER[519]	//(internal1_m210_y0) y0
#define idinternal1_m210_y0	 181	//(internal1_m210_y0) y0
#define internal1_m205_TVuIs1	 BUFFER[520]	//(internal1_m205_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
#define idinternal1_m205_TVuIs1	 182	//(internal1_m205_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
#define internal1_m205_TVuIs2	 BUFFER[525]	//(internal1_m205_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
#define idinternal1_m205_TVuIs2	 183	//(internal1_m205_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
#define internal1_m205_TImVuIs	 BUFFER[530]	//(internal1_m205_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
#define idinternal1_m205_TImVuIs	 184	//(internal1_m205_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
#define internal1_m205_TNupIs1	 BUFFER[535]	//(internal1_m205_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
#define idinternal1_m205_TNupIs1	 185	//(internal1_m205_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
#define internal1_m205_TNupIs2	 BUFFER[540]	//(internal1_m205_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
#define idinternal1_m205_TNupIs2	 186	//(internal1_m205_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
#define internal1_m205_TImNupIs	 BUFFER[545]	//(internal1_m205_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
#define idinternal1_m205_TImNupIs	 187	//(internal1_m205_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
#define internal1_m205_TImAZ2UR	 BUFFER[550]	//(internal1_m205_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
#define idinternal1_m205_TImAZ2UR	 188	//(internal1_m205_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
#define internal1_m205_fef	 BUFFER[555]	//(internal1_m205_fef) fef
#define idinternal1_m205_fef	 189	//(internal1_m205_fef) fef
#define internal1_m110_tx	 BUFFER[557]	//(internal1_m110_tx) tx - время накопленное сек
#define idinternal1_m110_tx	 190	//(internal1_m110_tx) tx - время накопленное сек
#define internal1_m110_y0	 BUFFER[562]	//(internal1_m110_y0) y0
#define idinternal1_m110_y0	 191	//(internal1_m110_y0) y0
#define internal1_m107_tx	 BUFFER[563]	//(internal1_m107_tx) tx - время накопленное сек
#define idinternal1_m107_tx	 192	//(internal1_m107_tx) tx - время накопленное сек
#define internal1_m107_y0	 BUFFER[568]	//(internal1_m107_y0) y0
#define idinternal1_m107_y0	 193	//(internal1_m107_y0) y0
#define internal1_m135_tx	 BUFFER[569]	//(internal1_m135_tx) tx - время накопленное сек
#define idinternal1_m135_tx	 194	//(internal1_m135_tx) tx - время накопленное сек
#define internal1_m135_y0	 BUFFER[574]	//(internal1_m135_y0) y0
#define idinternal1_m135_y0	 195	//(internal1_m135_y0) y0
#define internal1_m134_tx	 BUFFER[575]	//(internal1_m134_tx) tx - время накопленное сек
#define idinternal1_m134_tx	 196	//(internal1_m134_tx) tx - время накопленное сек
#define internal1_m134_y0	 BUFFER[580]	//(internal1_m134_y0) y0
#define idinternal1_m134_y0	 197	//(internal1_m134_y0) y0
#define internal1_m305_sttlf	 BUFFER[581]	//(internal1_m305_sttlf) sttlf - счетчик для вещественного формата
#define idinternal1_m305_sttlf	 198	//(internal1_m305_sttlf) sttlf - счетчик для вещественного формата
#define internal1_m225_tx	 BUFFER[584]	//(internal1_m225_tx) tx - время накопленное сек
#define idinternal1_m225_tx	 199	//(internal1_m225_tx) tx - время накопленное сек
#define internal1_m225_y0	 BUFFER[589]	//(internal1_m225_y0) y0
#define idinternal1_m225_y0	 200	//(internal1_m225_y0) y0
#define internal1_m33_tx	 BUFFER[590]	//(internal1_m33_tx) tx - внутренний параметр
#define idinternal1_m33_tx	 201	//(internal1_m33_tx) tx - внутренний параметр
#define internal1_m148_y0	 BUFFER[593]	//(internal1_m148_y0) y0
#define idinternal1_m148_y0	 202	//(internal1_m148_y0) y0
#define internal1_m146_y0	 BUFFER[598]	//(internal1_m146_y0) y0
#define idinternal1_m146_y0	 203	//(internal1_m146_y0) y0
#define internal1_m92_y0	 BUFFER[603]	//(internal1_m92_y0) y0
#define idinternal1_m92_y0	 204	//(internal1_m92_y0) y0
#define internal1_m90_y0	 BUFFER[608]	//(internal1_m90_y0) y0
#define idinternal1_m90_y0	 205	//(internal1_m90_y0) y0
#define internal1_m159_y1	 BUFFER[613]	//(internal1_m159_y1) y1 - внутренний параметр
#define idinternal1_m159_y1	 206	//(internal1_m159_y1) y1 - внутренний параметр
#define internal1_m170_y1	 BUFFER[615]	//(internal1_m170_y1) y1 - внутренний параметр
#define idinternal1_m170_y1	 207	//(internal1_m170_y1) y1 - внутренний параметр
#define internal1_m278_q0	 BUFFER[617]	//(internal1_m278_q0) q0 - внутренний параметр
#define idinternal1_m278_q0	 208	//(internal1_m278_q0) q0 - внутренний параметр
#define internal1_m128_y0	 BUFFER[622]	//(internal1_m128_y0) state
#define idinternal1_m128_y0	 209	//(internal1_m128_y0) state
#define internal1_m124_y0	 BUFFER[624]	//(internal1_m124_y0) state
#define idinternal1_m124_y0	 210	//(internal1_m124_y0) state
#define internal1_m106_y1	 BUFFER[626]	//(internal1_m106_y1) y1 - внутренний параметр
#define idinternal1_m106_y1	 211	//(internal1_m106_y1) y1 - внутренний параметр
#define internal1_m121_y1	 BUFFER[628]	//(internal1_m121_y1) y1 - внутренний параметр
#define idinternal1_m121_y1	 212	//(internal1_m121_y1) y1 - внутренний параметр
#define internal1_m94_y1	 BUFFER[630]	//(internal1_m94_y1) y1 - внутренний параметр
#define idinternal1_m94_y1	 213	//(internal1_m94_y1) y1 - внутренний параметр
#define internal1_m104_y1	 BUFFER[632]	//(internal1_m104_y1) y1 - внутренний параметр
#define idinternal1_m104_y1	 214	//(internal1_m104_y1) y1 - внутренний параметр
#define internal1_m156_y1	 BUFFER[634]	//(internal1_m156_y1) y1 - внутренний параметр
#define idinternal1_m156_y1	 215	//(internal1_m156_y1) y1 - внутренний параметр
#define internal1_m167_y1	 BUFFER[636]	//(internal1_m167_y1) y1 - внутренний параметр
#define idinternal1_m167_y1	 216	//(internal1_m167_y1) y1 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,5	,1	, &R0VZ05UZ1},	//( - , Baz1) Индикатор причины сброса
	{ 2	,8	,1	, &R0VN11RZ1},	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
	{ 3	,1	,1	, &R0VP73LZ1},	//( - , Baz1, SBz1DU) ПС давления для РУ
	{ 4	,8	,1	, &B0CT01IZ1},	//( - , Baz1, SBz1DU) Температура АЗ2-1
	{ 5	,1	,1	, &B0VT61LZ1},	//( - , Baz1) ПС по температуре в АЗ2
	{ 6	,1	,1	, &B0VT71LZ1},	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
	{ 7	,1	,1	, &A0VN71LS1},	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
	{ 8	,1	,1	, &A0VN71LS2},	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
	{ 9	,1	,1	, &A0VN71LS3},	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
	{ 10	,1	,1	, &A0VN71LS4},	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
	{ 11	,1	,1	, &A1VN71LZ1},	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
	{ 12	,1	,1	, &A3VZ15LZ1},	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
	{ 13	,1	,1	, &A3VZ13LZ1},	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
	{ 14	,1	,1	, &R0VW13LDU},	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 15	,1	,1	, &R0VW23LDU},	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 16	,1	,1	, &R7II73LZ1},	//(vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
	{ 17	,1	,1	, &R7II71LZ1},	//(vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
	{ 18	,1	,1	, &R7II72LZ1},	//(vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
	{ 19	,1	,1	, &R0AD14LZ1},	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
	{ 20	,1	,1	, &A0EE01LS4},	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
	{ 21	,1	,1	, &A0EE01LS3},	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
	{ 22	,1	,1	, &A0EE01LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП1
	{ 23	,1	,1	, &A0EE04LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП4
	{ 24	,1	,1	, &A0EE02LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП2
	{ 25	,1	,1	, &A0EE03LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП3
	{ 26	,1	,1	, &A0EE01LS2},	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
	{ 27	,1	,1	, &A0EE05LZ1},	//( - , Baz1) Исправность сети АКНП1
	{ 28	,1	,1	, &A0EE06LZ1},	//( - , Baz1) Исправность сети АКНП2
	{ 29	,1	,1	, &A0EE07LZ1},	//( - , Baz1) Исправность сети АКНП3
	{ 30	,1	,1	, &A0EE08LZ1},	//( - , Baz1) Исправность сети АКНП4
	{ 31	,1	,1	, &A0VZ71LZ1},	//( - , Baz1) Обобщенный сигнал АС по АЗ1
	{ 32	,1	,1	, &A0EE00LZ1},	//( - , Baz1) Исправность АКНП АЗ1
	{ 33	,1	,1	, &B0EE00LZ1},	//( - , Baz1) Исправность АКНП АЗ2
	{ 34	,1	,1	, &B0VZ71LZ1},	//( - , Baz1) Обобщенный сигнал АС по АЗ2
	{ 35	,1	,1	, &A0VN71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
	{ 36	,1	,1	, &B0VN71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
	{ 37	,1	,1	, &A0VN81LZ1},	//( - , Baz1) АЗ по АС периода разгона АЗ1
	{ 38	,1	,1	, &B0VN81LZ1},	//( - , Baz1) АЗ по АС периода разгона АЗ2
	{ 39	,1	,1	, &R0EE02LDU},	//( - , Baz1) Питание  АКНП  отключить
	{ 40	,1	,1	, &B2IS12LDU},	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
	{ 41	,3	,1	, &R0DE04LZ1},	//(vas84:04 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
	{ 42	,3	,1	, &R0DE05LZ1},	//(vds32:05 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
	{ 43	,3	,1	, &R0DE06LZ1},	//(vds32:06 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
	{ 44	,3	,1	, &R0DE08LZ1},	//(vds32:08 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
	{ 45	,3	,1	, &R0DE07LZ1},	//(vds32:07 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
	{ 46	,3	,1	, &R0DE0ALZ1},	//(fds16:0a - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
	{ 47	,3	,1	, &TTLBaz1},	//( - , Baz1) ttl
	{ 48	,1	,1	, &R0DEB1LZ1},	//(sbk:20 - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
	{ 49	,1	,1	, &R0DEB2LZ1},	//(sbk:20 - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
	{ 50	,1	,1	, &R0DEB4LZ1},	//(sbk:20 - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
	{ 51	,1	,1	, &R0DEB3LZ1},	//(sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
	{ 52	,1	,1	, &R0DE3CLZ1},	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 5
	{ 53	,1	,1	, &R0DE3DLZ1},	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 6
	{ 54	,1	,1	, &TestDiagnBaz1},	//( - , Baz1) Неисправность от диагностики
	{ 55	,3	,1	, &R0MW11IP1},	//( - , Baz1) Переключатель ВЫСТРЕЛ
	{ 56	,5	,1	, &R0VZ05U},	//( - , - ) причины сброса
	{ 57	,8	,1	, &B8VC01RDU},	//( - , SBz1DU, MBz1A1, MBz1A2, MBz1A3, MBz1A4) Координата АЗ2, мм
	{ 58	,1	,1	, &R0S01LZ1},	//(vds32:08 - K08VDSR, - ) Отключение сетевых передач в Баз1
	{ 59	,1	,1	, &R0AD21LDU},	//( - , SBz1DU) Подключить защиту от II УР
	{ 60	,1	,1	, &R0MD34LP1},	//( - , Baz1) Кнопка (Квитировать)
	{ 61	,1	,1	, &R0AD04LZ1},	//(vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
	{ 62	,1	,1	, &R0EE01LZ1},	//( - , MBz1S) Питание  АКНП1  отключить
	{ 63	,1	,1	, &R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 64	,1	,1	, &R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 65	,1	,1	, &R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 66	,1	,1	, &R0VN71LZ1},	//(vds32:05 - K01VDSR, Baz1) АС по мощности канал 1
	{ 67	,1	,1	, &R0VN75LZ1},	//(vds32:05 - K02VDSR, Baz1) АС по периоду разгона канал 1
	{ 68	,1	,1	, &R0VN72LZ1},	//(vds32:06 - K01VDSR, Baz1) АС по мощности канал 2
	{ 69	,1	,1	, &R0VN76LZ1},	//(vds32:06 - K02VDSR, Baz1) АС по периоду разгона канал  2
	{ 70	,1	,1	, &R0VN73LZ1},	//(vds32:08 - K01VDSR, Baz1) АС по мощности канал 3
	{ 71	,1	,1	, &R0VN77LZ1},	//(vds32:08 - K02VDSR, Baz1) АС по периоду разгона канал  3
	{ 72	,1	,1	, &R0VN74LZ1},	//(vds32:07 - K01VDSR, Baz1) АС по мощности канал 4
	{ 73	,1	,1	, &R0VN78LZ1},	//(vds32:07 - K02VDSR, Baz1) АС по периоду разгона канал  4
	{ 74	,1	,1	, &R0EE02LZ1},	//( - , MBz1S) Питание  АКНП2  отключить
	{ 75	,1	,1	, &R0EE03LZ1},	//( - , MBz1S) Питание  АКНП3  отключить
	{ 76	,1	,1	, &R0EE04LZ1},	//( - , MBz1S) Питание  АКНП4  отключить
	{ 77	,3	,1	, &R0MW12IP2},	//( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{ 78	,1	,1	, &A2IS12LDU},	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
	{ 79	,1	,1	, &A0VP41LZ1},	//( - , Baz1) Давление АЗ1 ниже АС
	{ 80	,1	,1	, &B0VP41LZ1},	//( - , Baz1) Давление АЗ2 ниже АС
	{ 81	,1	,1	, &B0VP81LZZ},	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
	{ 82	,1	,1	, &A0VP81LZZ},	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
	{ 83	,1	,1	, &R0ET02LZ1},	//( - , Baz1) Признак наличия неисправности по температуре АЗ2
	{ 84	,3	,1	, &B0EP02IZ1},	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
	{ 85	,3	,1	, &A0EP02IZ1},	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
	{ 86	,1	,1	, &A0VP71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
	{ 87	,1	,1	, &B0VP71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
	{ 88	,8	,1	, &R0VN02RS1},	//( - , MBz1A1) Уровень мощности канал 1
	{ 89	,8	,1	, &R0VN02RS2},	//( - , MBz1A2) Уровень мощности канал 2
	{ 90	,8	,1	, &R0VN02RS3},	//( - , MBz1A3) Уровень мощности канал 3
	{ 91	,8	,1	, &R0VN02RS4},	//( - , MBz1A4) Уровень мощности канал 4
	{ 92	,8	,1	, &R0VN01RS1},	//( - , MBz1A1) Период разгона канал 1
	{ 93	,8	,1	, &R0VN01RS2},	//( - , MBz1A2) Период разгона канал 2
	{ 94	,8	,1	, &R0VN01RS3},	//( - , MBz1A3) Период разгона канал 3
	{ 95	,8	,1	, &R0VN01RS4},	//( - , MBz1A4) Период разгона канал 4
	{ 96	,1	,1	, &R0VN61LS1},	//( - , MBz1A1) ПС по мощности канал 1
	{ 97	,1	,1	, &R0VN61LS2},	//( - , MBz1A2) ПС по мощности канал 2
	{ 98	,3	,1	, &A0IT01IZ1},	//(vas84:04 - K01VASR, - ) Температура АЗ1-1
	{ 99	,8	,1	, &A0CT01IZ1},	//( - , Baz1, SBz1DU) Температура АЗ1-1
	{ 100	,1	,1	, &A0VT61LZ1},	//( - , Baz1) ПС по температуре в АЗ1
	{ 101	,1	,1	, &A0VT71LZ1},	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
	{ 102	,1	,1	, &A1VP41LZ1},	//( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
	{ 103	,1	,1	, &B1VP41LZ1},	//( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
	{ 104	,1	,1	, &B1VP81LZZ},	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
	{ 105	,1	,1	, &A1VP81LZZ},	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
	{ 106	,1	,1	, &A2VP41LZ1},	//( - , Baz1) Давление СБРОС РБ1 ниже АС
	{ 107	,8	,1	, &A2CP01RZ1},	//( - , Baz1) Текущее давление СБРОС РБ1
	{ 108	,1	,1	, &A2VP51LZ1},	//( - , Baz1) Давление СБРОС РБ1 ниже ПС
	{ 109	,1	,1	, &B2VP41LZ1},	//( - , Baz1) Давление СБРОС РБ2 ниже АС
	{ 110	,8	,1	, &B2CP01RZ1},	//( - , Baz1) Текущее давление СБРОС РБ2
	{ 111	,1	,1	, &B2VP51LZ1},	//( - , Baz1) Давление СБРОС РБ2 ниже ПС
	{ 112	,1	,1	, &B2VP81LZ1},	//( - , Baz1) Давление СБРОС РБ2 в норме
	{ 113	,1	,1	, &A2VP81LZ1},	//( - , Baz1) Давление СБРОС РБ1 в норме
	{ 114	,3	,1	, &A2IP01IZ1},	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
	{ 115	,3	,1	, &B2IP01IZ1},	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
	{ 116	,1	,1	, &R0ET01LZ1},	//( - , Baz1) Признак наличия неисправности по температуре  АЗ1
	{ 117	,3	,1	, &B0IT01IZ1},	//(vas84:04 - K03VASR, - ) Температура АЗ2-1
	{ 118	,1	,1	, &R0VN67LZ1},	//( - , Baz1) ПС по периоду разгона канал 3
	{ 119	,1	,1	, &R0VN68LZ1},	//( - , Baz1) ПС по периоду разгона канал 4
	{ 120	,8	,1	, &R0VN09RZ1},	//( - , Baz1) Усредненный период разгона
	{ 121	,1	,1	, &A3IS11LDU},	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
	{ 122	,1	,1	, &A3IS22LDU},	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
	{ 123	,1	,1	, &R0AD03LZ1},	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
	{ 124	,1	,1	, &B3IS11LDU},	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
	{ 125	,1	,1	, &A3VZ31LZ1},	//( - , Baz1) АЗ от ВУ ИС1
	{ 126	,1	,1	, &B3VZ31LZ1},	//( - , Baz1) АЗ от ВУ ИС2
	{ 127	,1	,1	, &R0AD05LZ1},	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
	{ 128	,1	,1	, &A3VZ11LZ1},	//( - , Baz1) АЗ от НУП ИС1
	{ 129	,1	,1	, &B3VZ11LZ1},	//( - , Baz1) АЗ от НУП ИС2
	{ 130	,1	,1	, &B3IS22LDU},	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
	{ 131	,1	,1	, &R0VN69LZ1},	//( - , Baz1) ПС по усредненному периоду
	{ 132	,1	,1	, &R0VN79LZ1},	//( - , Baz1) АС по усредненному периоду
	{ 133	,8	,1	, &R0VR02RZ1},	//( - , Baz1) Усредненная реактивность
	{ 134	,1	,1	, &R0VZ71LZ1},	//(fds16:0a - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
	{ 135	,1	,1	, &R0VN70LZ1},	//( - , Baz1) АЗ по АС мощности РУ
	{ 136	,1	,1	, &R0VN80LZ1},	//( - , Baz1) АЗ по АС периода разгона РУ
	{ 137	,1	,1	, &A0EE01LS1},	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
	{ 138	,1	,1	, &R0VN61LS3},	//( - , MBz1A3) ПС по мощности канал 3
	{ 139	,1	,1	, &R0VN61LS4},	//( - , MBz1A4) ПС по мощности канал 4
	{ 140	,1	,1	, &R0VN65LS1},	//( - , MBz1A1) ПС по периоду разгона канал 1
	{ 141	,1	,1	, &R0VN65LS2},	//( - , MBz1A2) ПС по периоду разгона  канал 2
	{ 142	,1	,1	, &R0VN65LS3},	//( - , MBz1A3) ПС по периоду разгона канал 3
	{ 143	,1	,1	, &R0VN65LS4},	//( - , MBz1A4) ПС по периоду разгона канал 4
	{ 144	,8	,1	, &R0VN01RZ1},	//( - , Baz1) Уровень мощности по каналу 1
	{ 145	,8	,1	, &R0VN02RZ1},	//( - , Baz1) Уровень мощности по каналу 2
	{ 146	,8	,1	, &R0VN03RZ1},	//( - , Baz1) Уровень мощности по каналу 3
	{ 147	,8	,1	, &R0VN04RZ1},	//( - , Baz1) Уровень мощности по каналу 4
	{ 148	,8	,1	, &R0VN05RZ1},	//( - , Baz1) Период разгона по каналу 1
	{ 149	,8	,1	, &R0VN06RZ1},	//( - , Baz1) Период разгона по каналу 2
	{ 150	,8	,1	, &R0VN07RZ1},	//( - , Baz1) Период разгона по каналу 3
	{ 151	,8	,1	, &R0VN08RZ1},	//( - , Baz1) Период разгона по каналу 4
	{ 152	,1	,1	, &R0VN61LZ1},	//( - , Baz1) ПС по мощности канал 1
	{ 153	,1	,1	, &R0VN62LZ1},	//( - , Baz1) ПС по мощности канал 2
	{ 154	,1	,1	, &R0VN63LZ1},	//( - , Baz1) ПС по мощности канал 3
	{ 155	,1	,1	, &R0VN64LZ1},	//( - , Baz1) ПС по мощности канал 4
	{ 156	,1	,1	, &R0VN65LZ1},	//( - , Baz1) ПС по периоду разгона канал 1
	{ 157	,1	,1	, &R0VN66LZ1},	//( - , Baz1) ПС по периоду разгона канал 2
	{ 158	,8	,1	, &fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{ 159	,8	,1	, &fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{ 160	,8	,1	, &fEM_A2UP03RZZ},	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{ 161	,8	,1	, &fEM_A2UP04RZZ},	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{ 162	,8	,1	, &fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{ 163	,8	,1	, &fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{ 164	,8	,1	, &fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{ 165	,8	,1	, &fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{ 166	,8	,1	, &fEM_A2UP41RZZ},	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{ 167	,8	,1	, &fEM_A2UP42RZZ},	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{ 168	,8	,1	, &fEM_A2UP51RZZ},	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{ 169	,8	,1	, &fEM_A2UP81RZZ},	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{ 170	,8	,1	, &fEM_A2UP84RZZ},	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{ 171	,8	,1	, &fEM_A2UP82RZZ},	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{ 172	,8	,1	, &fEM_A2UP52RZZ},	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{ 173	,8	,1	, &fEM_A2UP83RZZ},	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{ 174	,8	,1	, &fEM_R0UR01RZZ},	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
	{ 175	,8	,1	, &fEM_R0UR04RZZ},	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
	{ 176	,8	,1	, &fEM_R0UL05RDU},	//(R0UL05RDU) Время задержки АЗ от НУП ИС(сек)
	{ 177	,8	,1	, &fEM_R0UL25RDU},	//(R0UL25RDU) Время задержки АЗ от ВУ ИС сек
	{ 178	,8	,1	, &fEM_R0UL07RDU},	//(R0UL07RDU) Время задержки  срабатывания АС II УР
	{ 179	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
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
	{ 190	,8	,1	, &internal1_m110_tx},	//(internal1_m110_tx) tx - время накопленное сек
	{ 191	,18	,1	, &internal1_m110_y0},	//(internal1_m110_y0) y0
	{ 192	,8	,1	, &internal1_m107_tx},	//(internal1_m107_tx) tx - время накопленное сек
	{ 193	,18	,1	, &internal1_m107_y0},	//(internal1_m107_y0) y0
	{ 194	,8	,1	, &internal1_m135_tx},	//(internal1_m135_tx) tx - время накопленное сек
	{ 195	,18	,1	, &internal1_m135_y0},	//(internal1_m135_y0) y0
	{ 196	,8	,1	, &internal1_m134_tx},	//(internal1_m134_tx) tx - время накопленное сек
	{ 197	,18	,1	, &internal1_m134_y0},	//(internal1_m134_y0) y0
	{ 198	,3	,1	, &internal1_m305_sttlf},	//(internal1_m305_sttlf) sttlf - счетчик для вещественного формата
	{ 199	,8	,1	, &internal1_m225_tx},	//(internal1_m225_tx) tx - время накопленное сек
	{ 200	,18	,1	, &internal1_m225_y0},	//(internal1_m225_y0) y0
	{ 201	,3	,1	, &internal1_m33_tx},	//(internal1_m33_tx) tx - внутренний параметр
	{ 202	,8	,1	, &internal1_m148_y0},	//(internal1_m148_y0) y0
	{ 203	,8	,1	, &internal1_m146_y0},	//(internal1_m146_y0) y0
	{ 204	,8	,1	, &internal1_m92_y0},	//(internal1_m92_y0) y0
	{ 205	,8	,1	, &internal1_m90_y0},	//(internal1_m90_y0) y0
	{ 206	,1	,1	, &internal1_m159_y1},	//(internal1_m159_y1) y1 - внутренний параметр
	{ 207	,1	,1	, &internal1_m170_y1},	//(internal1_m170_y1) y1 - внутренний параметр
	{ 208	,5	,1	, &internal1_m278_q0},	//(internal1_m278_q0) q0 - внутренний параметр
	{ 209	,1	,1	, &internal1_m128_y0},	//(internal1_m128_y0) state
	{ 210	,1	,1	, &internal1_m124_y0},	//(internal1_m124_y0) state
	{ 211	,1	,1	, &internal1_m106_y1},	//(internal1_m106_y1) y1 - внутренний параметр
	{ 212	,1	,1	, &internal1_m121_y1},	//(internal1_m121_y1) y1 - внутренний параметр
	{ 213	,1	,1	, &internal1_m94_y1},	//(internal1_m94_y1) y1 - внутренний параметр
	{ 214	,1	,1	, &internal1_m104_y1},	//(internal1_m104_y1) y1 - внутренний параметр
	{ 215	,1	,1	, &internal1_m156_y1},	//(internal1_m156_y1) y1 - внутренний параметр
	{ 216	,1	,1	, &internal1_m167_y1},	//(internal1_m167_y1) y1 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="baz1.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{158,"fEM_R0UT02RZZ\0"}, 
{159,"fEM_R0UT01RZZ\0"}, 
{160,"fEM_A2UP03RZZ\0"}, 
{161,"fEM_A2UP04RZZ\0"}, 
{162,"fEM_R0UT72RZZ\0"}, 
{163,"fEM_R0UT71RZZ\0"}, 
{164,"fEM_R0UT62RZZ\0"}, 
{165,"fEM_R0UT61RZZ\0"}, 
{166,"fEM_A2UP41RZZ\0"}, 
{167,"fEM_A2UP42RZZ\0"}, 
{168,"fEM_A2UP51RZZ\0"}, 
{169,"fEM_A2UP81RZZ\0"}, 
{170,"fEM_A2UP84RZZ\0"}, 
{171,"fEM_A2UP82RZZ\0"}, 
{172,"fEM_A2UP52RZZ\0"}, 
{173,"fEM_A2UP83RZZ\0"}, 
{174,"fEM_R0UR01RZZ\0"}, 
{175,"fEM_R0UR04RZZ\0"}, 
{176,"fEM_R0UL05RDU\0"}, 
{177,"fEM_R0UL25RDU\0"}, 
{178,"fEM_R0UL07RDU\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_Baz1[]={  // 
	{&R0EE02LDU,1,0},	//( - , Baz1) Питание  АКНП  отключить
	{&A0EE08LZ1,1,1},	//( - , Baz1) Исправность сети АКНП4
	{&A0EE07LZ1,1,2},	//( - , Baz1) Исправность сети АКНП3
	{&A0EE06LZ1,1,3},	//( - , Baz1) Исправность сети АКНП2
	{&A0EE05LZ1,1,4},	//( - , Baz1) Исправность сети АКНП1
	{&R0VN70LZ1,1,5},	//( - , Baz1) АЗ по АС мощности РУ
	{&R0MD34LP1,1,6},	//( - , Baz1) Кнопка (Квитировать)
	{&R7II73LZ1,1,7},	//( - K07VDSR, Baz1) Сработала АС II УР РАД
	{&R0VW23LDU,1,8},	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,9},	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{&R0VN64LZ1,1,10},	//( - , Baz1) ПС по мощности канал 4
	{&R0VN63LZ1,1,11},	//( - , Baz1) ПС по мощности канал 3
	{&R0VN62LZ1,1,12},	//( - , Baz1) ПС по мощности канал 2
	{&R0VN61LZ1,1,13},	//( - , Baz1) ПС по мощности канал 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_Baz1[]={  // 
	{&B0VN81LZ1,1,0},	//( - , Baz1) АЗ по АС периода разгона АЗ2
	{&A0VN81LZ1,1,1},	//( - , Baz1) АЗ по АС периода разгона АЗ1
	{&B0VN71LZ1,1,2},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
	{&A0VN71LZ1,1,3},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
	{&B0VZ71LZ1,1,4},	//( - , Baz1) Обобщенный сигнал АС по АЗ2
	{&B0EE00LZ1,1,5},	//( - , Baz1) Исправность АКНП АЗ2
	{&A0EE00LZ1,1,6},	//( - , Baz1) Исправность АКНП АЗ1
	{&A0VZ71LZ1,1,7},	//( - , Baz1) Обобщенный сигнал АС по АЗ1
	{&A0EE03LZ1,1,8},	//( - , Baz1, SBz1DU) Исправность АКНП3
	{&A0EE02LZ1,1,9},	//( - , Baz1, SBz1DU) Исправность АКНП2
	{&A0EE04LZ1,1,10},	//( - , Baz1, SBz1DU) Исправность АКНП4
	{&A0EE01LZ1,1,11},	//( - , Baz1, SBz1DU) Исправность АКНП1
	{&R0VN80LZ1,1,12},	//( - , Baz1) АЗ по АС периода разгона РУ
	{&R0VZ71LZ1,1,13},	//( - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
	{&TestDiagnBaz1,1,14},	//( - , Baz1) Неисправность от диагностики
	{&R0VN78LZ1,1,15},	//( - K02VDSR, Baz1) АС по периоду разгона канал  4
	{&R0VN74LZ1,1,16},	//( - K01VDSR, Baz1) АС по мощности канал 4
	{&R0VN77LZ1,1,17},	//( - K02VDSR, Baz1) АС по периоду разгона канал  3
	{&R0VN73LZ1,1,18},	//( - K01VDSR, Baz1) АС по мощности канал 3
	{&R0VN76LZ1,1,19},	//( - K02VDSR, Baz1) АС по периоду разгона канал  2
	{&R0VN72LZ1,1,20},	//( - K01VDSR, Baz1) АС по мощности канал 2
	{&R0VN75LZ1,1,21},	//( - K02VDSR, Baz1) АС по периоду разгона канал 1
	{&R0VN71LZ1,1,22},	//( - K01VDSR, Baz1) АС по мощности канал 1
	{&R7II72LZ1,1,23},	//( - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
	{&R7II71LZ1,1,24},	//( - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
	{&B0VT71LZ1,1,25},	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
	{&B0VT61LZ1,1,26},	//( - , Baz1) ПС по температуре в АЗ2
	{&R0VP73LZ1,1,27},	//( - , Baz1, SBz1DU) ПС давления для РУ
	{&B0VP71LZ1,1,28},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
	{&A0VP71LZ1,1,29},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
	{&R0ET02LZ1,1,30},	//( - , Baz1) Признак наличия неисправности по температуре АЗ2
	{&B0VP41LZ1,1,31},	//( - , Baz1) Давление АЗ2 ниже АС
	{&A0VP41LZ1,1,32},	//( - , Baz1) Давление АЗ1 ниже АС
	{&R0ET01LZ1,1,33},	//( - , Baz1) Признак наличия неисправности по температуре  АЗ1
	{&A2VP81LZ1,1,34},	//( - , Baz1) Давление СБРОС РБ1 в норме
	{&B2VP81LZ1,1,35},	//( - , Baz1) Давление СБРОС РБ2 в норме
	{&B2VP51LZ1,1,36},	//( - , Baz1) Давление СБРОС РБ2 ниже ПС
	{&B2VP41LZ1,1,37},	//( - , Baz1) Давление СБРОС РБ2 ниже АС
	{&A2VP51LZ1,1,38},	//( - , Baz1) Давление СБРОС РБ1 ниже ПС
	{&A2VP41LZ1,1,39},	//( - , Baz1) Давление СБРОС РБ1 ниже АС
	{&B1VP41LZ1,1,40},	//( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
	{&A1VP41LZ1,1,41},	//( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
	{&A0VT71LZ1,1,42},	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
	{&A0VT61LZ1,1,43},	//( - , Baz1) ПС по температуре в АЗ1
	{&R0VN79LZ1,1,44},	//( - , Baz1) АС по усредненному периоду
	{&R0VN69LZ1,1,45},	//( - , Baz1) ПС по усредненному периоду
	{&B3VZ11LZ1,1,46},	//( - , Baz1) АЗ от НУП ИС2
	{&A3VZ11LZ1,1,47},	//( - , Baz1) АЗ от НУП ИС1
	{&B3VZ31LZ1,1,48},	//( - , Baz1) АЗ от ВУ ИС2
	{&A3VZ31LZ1,1,49},	//( - , Baz1) АЗ от ВУ ИС1
	{&R0VN68LZ1,1,50},	//( - , Baz1) ПС по периоду разгона канал 4
	{&R0VN67LZ1,1,51},	//( - , Baz1) ПС по периоду разгона канал 3
	{&R0VN66LZ1,1,52},	//( - , Baz1) ПС по периоду разгона канал 2
	{&R0VN65LZ1,1,53},	//( - , Baz1) ПС по периоду разгона канал 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_Baz1[]={  // 
	{&R0VN11RZ1,8,0},	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
	{&R0VZ05UZ1,5,2},	//( - , Baz1) Индикатор причины сброса
	{&TTLBaz1,3,4},	//( - , Baz1) ttl
	{&B0CT01IZ1,8,5},	//( - , Baz1, SBz1DU) Температура АЗ2-1
	{&R0VN01RZ1,8,7},	//( - , Baz1) Уровень мощности по каналу 1
	{&A0EP02IZ1,3,9},	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
	{&B0EP02IZ1,3,10},	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
	{&B2CP01RZ1,8,11},	//( - , Baz1) Текущее давление СБРОС РБ2
	{&A2CP01RZ1,8,13},	//( - , Baz1) Текущее давление СБРОС РБ1
	{&A0CT01IZ1,8,15},	//( - , Baz1, SBz1DU) Температура АЗ1-1
	{&R0VR02RZ1,8,17},	//( - , Baz1) Усредненная реактивность
	{&R0VN09RZ1,8,19},	//( - , Baz1) Усредненный период разгона
	{&R0VN08RZ1,8,21},	//( - , Baz1) Период разгона по каналу 4
	{&R0VN07RZ1,8,23},	//( - , Baz1) Период разгона по каналу 3
	{&R0VN06RZ1,8,25},	//( - , Baz1) Период разгона по каналу 2
	{&R0VN05RZ1,8,27},	//( - , Baz1) Период разгона по каналу 1
	{&R0VN04RZ1,8,29},	//( - , Baz1) Уровень мощности по каналу 4
	{&R0VN03RZ1,8,31},	//( - , Baz1) Уровень мощности по каналу 3
	{&R0VN02RZ1,8,33},	//( - , Baz1) Уровень мощности по каналу 2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_Baz1[]={  // 
	{&R0MW11IP1,3,0},	//( - , Baz1) Переключатель ВЫСТРЕЛ
	{&R0MW12IP2,3,1},	//( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{&fEM_R0UT02RZZ,8,2},	//( - , Baz1) Верхний предел шкалы датчика температуры
	{&fEM_R0UT01RZZ,8,4},	//( - , Baz1) Нижний предел шкалы датчика температуры
	{&fEM_A2UP03RZZ,8,6},	//( - , Baz1) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{&fEM_A2UP04RZZ,8,8},	//( - , Baz1) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{&fEM_R0UT72RZZ,8,10},	//( - , Baz1) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{&fEM_R0UT71RZZ,8,12},	//( - , Baz1) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{&fEM_R0UT62RZZ,8,14},	//( - , Baz1) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{&fEM_R0UT61RZZ,8,16},	//( - , Baz1) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{&fEM_A2UP41RZZ,8,18},	//( - , Baz1) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{&fEM_A2UP42RZZ,8,20},	//( - , Baz1) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{&fEM_A2UP51RZZ,8,22},	//( - , Baz1) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{&fEM_A2UP81RZZ,8,24},	//( - , Baz1) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{&fEM_A2UP84RZZ,8,26},	//( - , Baz1) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{&fEM_A2UP82RZZ,8,28},	//( - , Baz1) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{&fEM_A2UP52RZZ,8,30},	//( - , Baz1) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{&fEM_A2UP83RZZ,8,32},	//( - , Baz1) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{&fEM_R0UR01RZZ,8,34},	//( - , Baz1) Уставка АКНП ПС  АЗ по периоду (сек)
	{&fEM_R0UR04RZZ,8,36},	//( - , Baz1) Уставка АКНП АС  АЗ по периоду (сек)
	{&fEM_R0UL05RDU,8,38},	//( - , Baz1) Время задержки АЗ от НУП ИС(сек)
	{&fEM_R0UL25RDU,8,40},	//( - , Baz1) Время задержки АЗ от ВУ ИС сек
	{&fEM_R0UL07RDU,8,42},	//( - , Baz1) Время задержки  срабатывания АС II УР
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SBz1DU[]={  // 
	{&R0AD21LDU,1,0},	//( - , SBz1DU) Подключить защиту от II УР
	{&R0VW23LDU,1,1},	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,2},	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz1DU[]={  // 
	{&B0VT71LZ1,1,0},	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
	{&R0VP73LZ1,1,1},	//( - , Baz1, SBz1DU) ПС давления для РУ
	{&B0VN71LZ1,1,2},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
	{&A0VN71LZ1,1,3},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
	{&A0EE03LZ1,1,4},	//( - , Baz1, SBz1DU) Исправность АКНП3
	{&A0EE02LZ1,1,5},	//( - , Baz1, SBz1DU) Исправность АКНП2
	{&A0EE04LZ1,1,6},	//( - , Baz1, SBz1DU) Исправность АКНП4
	{&A0EE01LZ1,1,7},	//( - , Baz1, SBz1DU) Исправность АКНП1
	{&B0VP71LZ1,1,8},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
	{&A0VP71LZ1,1,9},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
	{&B1VP41LZ1,1,10},	//( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
	{&A1VP41LZ1,1,11},	//( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
	{&A0VT71LZ1,1,12},	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SBz1DU[]={  // 
	{&B0CT01IZ1,8,0},	//( - , Baz1, SBz1DU) Температура АЗ2-1
	{&R0VN11RZ1,8,2},	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
	{&A0CT01IZ1,8,4},	//( - , Baz1, SBz1DU) Температура АЗ1-1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SBz1DU[]={  // 
	{&B8VC01RDU,8,0},	//( - , SBz1DU, MBz1A1, MBz1A2, MBz1A3, MBz1A4) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_DiagnBaz1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnBaz1[]={  // 
	{&R0DEB1LZ1,1,0},	//( - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
	{&R0DEB2LZ1,1,1},	//( - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
	{&R0DEB4LZ1,1,2},	//( - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
	{&R0DEB3LZ1,1,3},	//( - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
	{&R0DE3CLZ1,1,4},	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 5
	{&R0DE3DLZ1,1,5},	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 6
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DiagnBaz1[]={  // 
	{&R0DE04LZ1,3,0},	//( - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
	{&R0DE05LZ1,3,1},	//( - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
	{&R0DE06LZ1,3,2},	//( - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
	{&R0DE08LZ1,3,3},	//( - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
	{&R0DE07LZ1,3,4},	//( - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
	{&R0DE0ALZ1,3,5},	//( - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DiagnBaz1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MBz1S[]={  // 
	{&R0EE01LZ1,1,0},	//( - , SBz1) Питание  АКНП1  отключить
	{&R0EE02LZ1,1,1},	//( - , SBz1) Питание  АКНП  отключить
	{&R0EE03LZ1,1,2},	//( - , SBz1) Питание  АКНП3  отключить
	{&R0EE04LZ1,1,3},	//( - , SBz1) Питание  АКНП4  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz1S[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz1S[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz1S[]={  // 
	{NULL,0,0},
};
#pragma pop
static char MBz1S_ip1[]={"192.168.10.60\0"};
static char MBz1S_ip2[]={"192.168.10.60\0"};
#pragma pack(push,1)
static ModbusRegister coil_MBz1A1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz1A1[]={  // 
	{&R0VN61LS1,1,0},	//( - , A1Bz1, A1Bz2) ПС по мощности канал1
	{&R0VN65LS1,1,1},	//( - , A1Bz1, A1Bz2) ПС по периоду разгона канал1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz1A1[]={  // 
	{&R0VN02RS1,8,0},	//( - , A1Bz1, A1Bz2) Уровень мощности
	{&R0VN01RS1,8,2},	//( - , A1Bz1, A1Bz2) Период разгона канал1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz1A1[]={  // 
	{&B8VC01RDU,8,0},	//( - , A1Bz1, A1Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
static char MBz1A1_ip1[]={"192.168.10.51\0"};
static char MBz1A1_ip2[]={"192.168.10.151\0"};
#pragma pack(push,1)
static ModbusRegister coil_MBz1A2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz1A2[]={  // 
	{&R0VN61LS2,1,0},	//( - , A2Bz1, A2Bz2) ПС по мощности канал 2
	{&R0VN65LS2,1,1},	//( - , A2Bz1, A2Bz2) ПС по периоду разгона канал 2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz1A2[]={  // 
	{&R0VN02RS2,8,0},	//( - , A2Bz1, A2Bz2) Уровень мощности канал 2
	{&R0VN01RS2,8,2},	//( - , A2Bz1, A2Bz2) Период разгона канал 2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz1A2[]={  // 
	{&B8VC01RDU,8,0},	//( - , A2Bz1, A2Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
static char MBz1A2_ip1[]={"192.168.10.57\0"};
static char MBz1A2_ip2[]={"192.168.10.157\0"};
#pragma pack(push,1)
static ModbusRegister coil_MBz1A3[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz1A3[]={  // 
	{&R0VN61LS3,1,0},	//( - , A3Bz1, A3Bz2) ПС по мощности канал 3
	{&R0VN65LS3,1,1},	//( - , A3Bz1, A3Bz2) ПС по периоду разгона канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz1A3[]={  // 
	{&R0VN02RS3,8,0},	//( - , A3Bz1, A3Bz2) Уровень мощности канал 3
	{&R0VN01RS3,8,2},	//( - , A3Bz1, A3Bz2) Период разгона канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz1A3[]={  // 
	{&B8VC01RDU,8,0},	//( - , A3Bz1, A3Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
static char MBz1A3_ip1[]={"192.168.10.53\0"};
static char MBz1A3_ip2[]={"192.168.10.153\0"};
#pragma pack(push,1)
static ModbusRegister coil_MBz1A4[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz1A4[]={  // 
	{&R0VN61LS4,1,0},	//( - , A4Bz1, A4Bz2) ПС по мощности канал 4
	{&R0VN65LS4,1,1},	//( - , A4Bz1, A4Bz2) ПС по периоду разгона канал 4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz1A4[]={  // 
	{&R0VN02RS4,8,0},	//( - , A4Bz1, A4Bz2) Уровень мощности канал 4
	{&R0VN01RS4,8,2},	//( - , A4Bz1, A4Bz2) Период разгона канал 4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz1A4[]={  // 
	{&B8VC01RDU,8,0},	//( - , A4Bz1, A4Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
static char MBz1A4_ip1[]={"192.168.10.55\0"};
static char MBz1A4_ip2[]={"192.168.10.155\0"};
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_Baz1[0],&di_Baz1[0],&ir_Baz1[0],&hr_Baz1[0],NULL,NULL,NULL,0},	 //Общий слэйв
	{0,5010,&coil_SBz1DU[0],&di_SBz1DU[0],&ir_SBz1DU[0],&hr_SBz1DU[0],NULL,NULL,NULL,0},	 //Слэйв для DU
	{0,5005,&coil_DiagnBaz1[0],&di_DiagnBaz1[0],&ir_DiagnBaz1[0],&hr_DiagnBaz1[0],NULL,NULL,NULL,0},	 //Диагностика Baz1
	{1,5003,&coil_MBz1S[0],&di_MBz1S[0],&ir_MBz1S[0],&hr_MBz1S[0],NULL,MBz1S_ip1,MBz1S_ip2,100},	 //Мастер Баз1 в SCM
	{1,5015,&coil_MBz1A1[0],&di_MBz1A1[0],&ir_MBz1A1[0],&hr_MBz1A1[0],NULL,MBz1A1_ip1,MBz1A1_ip2,20},	 //Мастер Баз1 в AKNP1
	{1,5016,&coil_MBz1A2[0],&di_MBz1A2[0],&ir_MBz1A2[0],&hr_MBz1A2[0],NULL,MBz1A2_ip1,MBz1A2_ip2,20},	 //Мастер Баз1 в AKNP2
	{1,5017,&coil_MBz1A3[0],&di_MBz1A3[0],&ir_MBz1A3[0],&hr_MBz1A3[0],NULL,MBz1A3_ip1,MBz1A3_ip2,20},	 //Мастер Баз1 в AKNP3
	{1,5018,&coil_MBz1A4[0],&di_MBz1A4[0],&ir_MBz1A4[0],&hr_MBz1A4[0],NULL,MBz1A4_ip1,MBz1A4_ip2,20},	 //Мастер Баз1 в AKNP4

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
	{&R0DE04LZ1,3,26},
	{&A2IP01IZ1,3,3},
	{&B2IP01IZ1,3,9},
	{&B0IT01IZ1,3,6},
	{&A0IT01IZ1,3,0},
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
	{&A2IS12LDU,1,18},
	{&A0EE01LS1,1,4},
	{&R0AD05LZ1,1,16},
	{&R0VN71LZ1,1,0},
	{&R0VN75LZ1,1,2},
	{&R0AD03LZ1,1,12},
	{&A3IS22LDU,1,10},
	{&A3IS11LDU,1,8},
	{&R0AD04LZ1,1,14},
	{&A0VN71LS1,1,6},
	{&R0DE05LZ1,3,64},
	{&B2IS12LDU,1,20},
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
	{&R0VN76LZ1,1,2},
	{&R0VN72LZ1,1,0},
	{&A0VN71LS2,1,6},
	{&B3IS22LDU,1,10},
	{&A0EE01LS2,1,4},
	{&B3IS11LDU,1,8},
	{&R0DE06LZ1,3,64},
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
	{&R0DE07LZ1,3,64},
	{&A0EE01LS4,1,4},
	{&R0VN74LZ1,1,0},
	{&R0VN78LZ1,1,2},
	{&A0VN71LS4,1,6},
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
	{&R0DE08LZ1,3,64},
	{&R0VN73LZ1,1,0},
	{&R0VN77LZ1,1,2},
	{&B1VP81LZZ,1,24},
	{&A0VN71LS3,1,6},
	{&A1VP81LZZ,1,18},
	{&R0S01LZ1,1,14},
	{&A0VP81LZZ,1,16},
	{&B0VP81LZZ,1,22},
	{&R7II73LZ1,1,12},
	{&R7II71LZ1,1,8},
	{&R7II72LZ1,1,10},
	{&A0EE01LS3,1,4},
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
	{&A3VZ13LZ1,1,0},
	{&A3VZ15LZ1,1,2},
	{&A1VN71LZ1,1,6},
	{&R0DE0ALZ1,3,38},
	{&R0AD14LZ1,1,4},
	{&R0VZ71LZ1,1,8},
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
	{&R0DEB4LZ1,1,24},
	{&R0DEB2LZ1,1,20},
	{&R0DEB1LZ1,1,18},
	{&R0DEB3LZ1,1,22},
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
	setAsFloat(158,600);
	setAsFloat(159,0);
	setAsFloat(160,1.6);
	setAsFloat(161,0);
	setAsFloat(162,150);
	setAsFloat(163,200);
	setAsFloat(164,90);
	setAsFloat(165,100);
	setAsFloat(166,0.1);
	setAsFloat(167,0.13);
	setAsFloat(168,0.16);
	setAsFloat(169,0.17);
	setAsFloat(170,0.31);
	setAsFloat(171,0.2);
	setAsFloat(172,0.19);
	setAsFloat(173,0.28);
	setAsFloat(174,15);
	setAsFloat(175,10);
	setAsFloat(176,0.190);
	setAsFloat(177,0.170);
	setAsFloat(178,0.150);
	setAsBool(63,1);
	setAsBool(64,1);
	setAsBool(65,1);
}
uspaint8 InternalBuf[132];

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
ssint iRM_16383_ = {16383,0}; /* b */ 
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
ssint var20;
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
ssbool var33;
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
ssfloat var100;
ssfloat var101;
ssbool var102;
ssfloat var103;
ssfloat var104;
ssbool var105;
ssbool var106;
ssbool var107;
ssbool var108;
ssbool var109;
ssbool var110;
ssfloat var111;
sslong var112;
sslong var113;
ssbool var114;
ssbool var115;
ssbool var116;
ssbool var117;
ssbool var118;
ssbool var119;
ssbool var120;
ssbool var121;
ssbool var122;
ssfloat var123;
ssbool var124;
ssbool var125;
ssfloat var126;
ssbool var127;
ssbool var128;
sschar var129;
ssbool var130;
sschar var131;
ssbool var132;
ssbool var133;
ssbool var134;
ssbool var135;
ssbool var136;
ssbool var137;
ssbool var138;
ssbool var139;
ssbool var140;
ssbool var141;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psint  array_m305_x_1[6] = {&R0DE04LZ1,&R0DE05LZ1,&R0DE06LZ1,&R0DE0ALZ1,&R0DE08LZ1,&R0DE07LZ1};
psfloat  array_m189_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psfloat  array_m291_x_1[4] = {&R0VN02RS1,&R0VN02RS2,&R0VN02RS3,&R0VN02RS4};
psbool  array_m291_diag_1[4] = {&var25,&var26,&var27,&var28};
psbool  array_m280_x_1[17] = {&var74,&var40,&var41,&var69,&var8,&var5,&var128,&var39,&var38,&var37,&var70,&var9,&var6,&var130,&var35,&var34,&R7II73LZ1};
psbool  array_m16_x_1[6] = {&var79,&var70,&var9,&var6,&var85,&var130};
psbool  array_m36_x_1[6] = {&var69,&var8,&var5,&var128,&var77,&var85};
psfloat  array_m2_x_1[4] = {&R0VN01RS1,&R0VN01RS2,&R0VN01RS3,&R0VN01RS4};
psbool  array_m2_diag_1[4] = {&var25,&var26,&var27,&var28};
psbool  array_m3_x_1[3] = {&var90,&var110,&var23};
psbool  array_m12_x_1[3] = {&var89,&var24,&var91};

/* Объявление структур */
_S_zzfs  S_zzfs_210_1 = {&R0AD04LZ1,&fRM_0_3,&var1,&internal1_m210_tx,&internal1_m210_y0};
_S_noto  S_noto_223_1 = {&var1,&var2};
_S_and2  S_and2_226_1 = {&var2,&var4,&var3};
_S_or3  S_or3_227_1 = {&var34,&var35,&R7II73LZ1,&var4};
_S_inicn  S_inicn_205_1 = {&A3IS11LDU,&B3IS11LDU,&R0AD03LZ1,&A3IS22LDU,&B3IS22LDU,&R0AD05LZ1,&var34,&var35,&var33,&var1,&fEM_R0UL25RDU,&fEM_R0UL05RDU,&fEM_R0UL07RDU,&var5,&var6,&var7,&var8,&var9,&var10,&var11,&internal1_m205_TVuIs1,&internal1_m205_TVuIs2,&internal1_m205_TImVuIs,&internal1_m205_TNupIs1,&internal1_m205_TNupIs2,&internal1_m205_TImNupIs,&internal1_m205_TImAZ2UR,&internal1_m205_fef};
_S_zzfs  S_zzfs_110_1 = {&B1VP81LZZ,&fRM_10000_,&var12,&internal1_m110_tx,&internal1_m110_y0};
_S_zzfs  S_zzfs_107_1 = {&A1VP81LZZ,&fRM_10000_,&var13,&internal1_m107_tx,&internal1_m107_y0};
_S_zzfs  S_zzfs_135_1 = {&B0VP81LZZ,&fRM_10000_,&var14,&internal1_m135_tx,&internal1_m135_y0};
_S_zzfs  S_zzfs_134_1 = {&A0VP81LZZ,&fRM_10000_,&var15,&internal1_m134_tx,&internal1_m134_y0};
_S_or3  S_or3_313_1 = {&var19,&var18,&var17,&var16};
_S_or2  S_or2_315_1 = {&R0DEB3LZ1,&R0DEB4LZ1,&var17};
_S_or2  S_or2_309_1 = {&R0DEB1LZ1,&R0DEB2LZ1,&var18};
_S_diagndev  S_diagndev_305_1 = {array_m305_x_1,&iRM_6_,&var19,&var20,&vainSFloat,&internal1_m305_sttlf};
_S_ma  S_ma_189_1 = {array_m189_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_and2  S_and2_127_1 = {&var133,&var109,&var21};
_S_and2  S_and2_138_1 = {&var132,&var108,&var22};
_S_or2  S_or2_103_1 = {&var139,&var137,&var23};
_S_or2  S_or2_108_1 = {&var134,&var135,&var24};
_S_and2  S_and2_81_1 = {&lRM_1_,&A0EE01LS1,&var25};
_S_and2  S_and2_83_1 = {&lRM_1_,&A0EE01LS2,&var26};
_S_and2  S_and2_85_1 = {&lRM_1_,&A0EE01LS3,&var27};
_S_and2  S_and2_87_1 = {&lRM_1_,&A0EE01LS4,&var28};
_S_and2  S_and2_183_1 = {&var125,&var97,&var29};
_S_and2  S_and2_184_1 = {&var124,&var97,&var30};
_S_or2  S_or2_217_1 = {&R7II73LZ1,&var87,&var31};
_S_or2  S_or2_215_1 = {&R0AD21LDU,&var1,&var32};
_S_and2  S_and2_214_1 = {&var31,&var32,&var33};
_S_or2  S_or2_206_1 = {&var86,&R7II71LZ1,&var34};
_S_or2  S_or2_199_1 = {&var88,&R7II72LZ1,&var35};
_S_schl24  S_schl24_293_1 = {&A0VN71LS2,&A0VN71LS1,&A0VN71LS4,&A0VN71LS3,&var36};
_S_and2  S_and2_282_1 = {&var53,&var75,&var37};
_S_and2  S_and2_284_1 = {&var60,&var75,&var38};
_S_and2  S_and2_285_1 = {&var98,&var75,&var39};
_S_and2  S_and2_283_1 = {&var64,&var75,&var40};
_S_and2  S_and2_281_1 = {&var46,&var75,&var41};
_S_and2  S_and2_266_1 = {&var44,&var43,&var42};
_S_or2  S_or2_268_1 = {&R0VN75LZ1,&var122,&var43};
_S_or2  S_or2_269_1 = {&R0VN77LZ1,&var121,&var44};
_S_or2  S_or2_254_1 = {&var42,&var50,&var45};
_S_or2  S_or2_260_1 = {&var47,&var42,&var46};
_S_and2  S_and2_261_1 = {&var117,&var51,&var47};
_S_or2  S_or2_271_1 = {&R0VN78LZ1,&var119,&var48};
_S_or2  S_or2_270_1 = {&R0VN76LZ1,&var120,&var49};
_S_and2  S_and2_267_1 = {&var49,&var48,&var50};
_S_schl24  S_schl24_265_1 = {&var49,&var48,&var44,&var43,&var51};
_S_and2  S_and2_263_1 = {&var75,&var51,&var52};
_S_or2  S_or2_262_1 = {&var50,&var47,&var53};
_S_and2  S_and2_258_1 = {&var53,&var75,&var54};
_S_or2  S_or2_234_1 = {&R0VN72LZ1,&var120,&var55};
_S_and2  S_and2_249_1 = {&var64,&var75,&var56};
_S_and2  S_and2_239_1 = {&var55,&var58,&var57};
_S_or2  S_or2_235_1 = {&R0VN74LZ1,&var119,&var58};
_S_and2  S_and2_250_1 = {&var60,&var75,&var59};
_S_or2  S_or2_247_1 = {&var57,&var63,&var60};
_S_or2  S_or2_253_1 = {&var65,&var57,&var61};
_S_and2  S_and2_241_1 = {&var67,&var75,&var62};
_S_and2  S_and2_246_1 = {&var118,&var67,&var63};
_S_or2  S_or2_245_1 = {&var65,&var63,&var64};
_S_and2  S_and2_236_1 = {&var66,&var68,&var65};
_S_or2  S_or2_233_1 = {&R0VN73LZ1,&var121,&var66};
_S_schl24  S_schl24_238_1 = {&var66,&var68,&var55,&var58,&var67};
_S_or2  S_or2_232_1 = {&R0VN71LZ1,&var122,&var68};
_S_or2  S_or2_155_1 = {&var102,&var140,&var69};
_S_or2  S_or2_157_1 = {&var107,&var105,&var70};
_S_or2  S_or2_297_1 = {&var138,&var136,&var71};
_S_or2  S_or2_35_1 = {&B2IS12LDU,&A2IS12LDU,&var72};
_S_and2  S_and2_257_1 = {&var75,&var46,&var73};
_S_and2  S_and2_286_1 = {&var99,&var75,&var74};
_S_and2  S_and2_21_1 = {&var96,&var92,&var75};
_S_or2  S_or2_25_1 = {&var115,&var114,&var76};
_S_and2  S_and2_31_1 = {&var78,&var75,&var77};
_S_or3  S_or3_30_1 = {&var46,&var64,&var95,&var78};
_S_and2  S_and2_19_1 = {&var75,&var80,&var79};
_S_or3  S_or3_18_1 = {&var60,&var53,&var94,&var80};
_S_and2  S_and2_6_1 = {&var26,&var28,&var81};
_S_or2  S_or2_11_1 = {&var116,&var81,&var82};
_S_or2  S_or2_10_1 = {&var84,&var116,&var83};
_S_and2  S_and2_5_1 = {&var25,&var27,&var84};
_S_zpfs  S_zpfs_225_1 = {&var3,&fEM_R0UL07RDU,&var85,&internal1_m225_tx,&internal1_m225_y0};
_S_noto  S_noto_201_1 = {&R6IS67LZZ,&var86};
_S_noto  S_noto_218_1 = {&R6IS68LZZ,&var87};
_S_noto  S_noto_200_1 = {&R6IS66LZZ,&var88};
_S_noto  S_noto_137_1 = {&var14,&var89};
_S_noto  S_noto_136_1 = {&var15,&var90};
_S_noto  S_noto_112_1 = {&var12,&var91};
_S_noto  S_noto_27_1 = {&var93,&var92};
_S_ovb1  S_ovb1_33_1 = {&var72,&iRM_200_,&var93,&internal1_m33_tx};
_S_noto  S_noto_15_1 = {&var82,&var94};
_S_noto  S_noto_14_1 = {&var83,&var95};
_S_noto  S_noto_24_1 = {&R0EE02LDU,&var96};
_S_bol  S_bol_179_1 = {&var126,&fRM_0_00001,&var97};
_S_noto  S_noto_287_1 = {&var82,&var98};
_S_noto  S_noto_288_1 = {&var83,&var99};
_S_scalzz  S_scalzz_148_1 = {&B0IT01IZ1,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var100,&internal1_m148_y0};
_S_scalzz  S_scalzz_146_1 = {&A0IT01IZ1,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var101,&internal1_m146_y0};
_S_geterr  S_geterr_150_1 = {&var101,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var102};
_S_scalzz  S_scalzz_92_1 = {&B2IP01IZ1,&iRM_3276_,&iRM_16383_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var103,&internal1_m92_y0};
_S_scalzz  S_scalzz_90_1 = {&A2IP01IZ1,&iRM_3276_,&iRM_16383_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var104,&internal1_m90_y0};
_S_drg  S_drg_159_1 = {&var100,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var105,&internal1_m159_y1};
_S_drg  S_drg_170_1 = {&var100,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var106,&internal1_m170_y1};
_S_geterr  S_geterr_152_1 = {&var100,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var107};
_S_noto  S_noto_139_1 = {&var134,&var108};
_S_noto  S_noto_126_1 = {&var139,&var109};
_S_noto  S_noto_111_1 = {&var13,&var110};
_S_srm  S_srm_291_1 = {array_m291_x_1,array_m291_diag_1,&iRM_4_,&iRM_3_,&var111,&vainSBool};
_S_rsu  S_rsu_278_1 = {&R0MD34LP1,&var113,&var112,&internal1_m278_q0};
_S_orni  S_orni_280_1 = {array_m280_x_1,&iRM_17_,&vainSBool,&var113};
_S_orn  S_orn_16_1 = {array_m16_x_1,&iRM_6_,&var114};
_S_orn  S_orn_36_1 = {array_m36_x_1,&iRM_6_,&var115};
_S_noto  S_noto_7_1 = {&var127,&var116};
_S_noto  S_noto_256_1 = {&var45,&var117};
_S_noto  S_noto_251_1 = {&var61,&var118};
_S_noto  S_noto_240_1 = {&A0EE01LS4,&var119};
_S_noto  S_noto_244_1 = {&A0EE01LS2,&var120};
_S_noto  S_noto_243_1 = {&A0EE01LS3,&var121};
_S_noto  S_noto_237_1 = {&A0EE01LS1,&var122};
_S_react  S_react_175_1 = {&var126,&var123};
_S_bol  S_bol_180_1 = {&fEM_R0UR04RZZ,&var126,&var124};
_S_bol  S_bol_178_1 = {&fEM_R0UR01RZZ,&var126,&var125};
_S_srm  S_srm_2_1 = {array_m2_x_1,array_m2_diag_1,&iRM_4_,&iRM_3_,&var126,&var127};
_S_ornc  S_ornc_3_1 = {array_m3_x_1,&iRM_3_,&var128,&var129};
_S_ornc  S_ornc_12_1 = {array_m12_x_1,&iRM_3_,&var130,&var131};
_S_tprg  S_tprg_128_1 = {&var103,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var132,&internal1_m128_y0};
_S_tprg  S_tprg_124_1 = {&var104,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var133,&internal1_m124_y0};
_S_geterr  S_geterr_101_1 = {&var103,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var134};
_S_drg  S_drg_106_1 = {&var103,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var135,&internal1_m106_y1};
_S_drg  S_drg_121_1 = {&var103,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var136,&internal1_m121_y1};
_S_drg  S_drg_94_1 = {&var104,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var137,&internal1_m94_y1};
_S_drg  S_drg_104_1 = {&var104,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var138,&internal1_m104_y1};
_S_geterr  S_geterr_98_1 = {&var104,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var139};
_S_drg  S_drg_156_1 = {&var101,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var140,&internal1_m156_y1};
_S_drg  S_drg_167_1 = {&var101,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var141,&internal1_m167_y1};


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
   var20.i=0;
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
   var33.b=0;
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
   var100.f=0.0;
   var101.f=0.0;
   var102.b=0;
   var103.f=0.0;
   var104.f=0.0;
   var105.b=0;
   var106.b=0;
   var107.b=0;
   var108.b=0;
   var109.b=0;
   var110.b=0;
   var111.f=0.0;
   var112.l=0L;
   var113.l=0L;
   var114.b=0;
   var115.b=0;
   var116.b=0;
   var117.b=0;
   var118.b=0;
   var119.b=0;
   var120.b=0;
   var121.b=0;
   var122.b=0;
   var123.f=0.0;
   var124.b=0;
   var125.b=0;
   var126.f=0.0;
   var127.b=0;
   var128.b=0;
   var129.c=0;
   var130.b=0;
   var131.c=0;
   var132.b=0;
   var133.b=0;
   var134.b=0;
   var135.b=0;
   var136.b=0;
   var137.b=0;
   var138.b=0;
   var139.b=0;
   var140.b=0;
   var141.b=0;
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
  noto(&S_noto_237_1);
  noto(&S_noto_243_1);
  noto(&S_noto_244_1);
  noto(&S_noto_240_1);
  scalzz(&S_scalzz_90_1);
  scalzz(&S_scalzz_92_1);
  scalzz(&S_scalzz_146_1);
  scalzz(&S_scalzz_148_1);
  noto(&S_noto_24_1);
  noto(&S_noto_200_1);
  noto(&S_noto_218_1);
  noto(&S_noto_201_1);
  or2(&S_or2_232_1);
  or2(&S_or2_233_1);
  and2(&S_and2_236_1);
  or2(&S_or2_235_1);
  or2(&S_or2_234_1);
  or2(&S_or2_270_1);
  or2(&S_or2_271_1);
  or2(&S_or2_269_1);
  or2(&S_or2_268_1);
  and2(&S_and2_266_1);
  schl24(&S_schl24_293_1);
  or2(&S_or2_199_1);
  or2(&S_or2_206_1);
  or2(&S_or2_217_1);
  ma(&S_ma_189_1);
  or2(&S_or2_309_1);
  or2(&S_or2_315_1);
  zzfs(&S_zzfs_134_1);
  zzfs(&S_zzfs_135_1);
  zzfs(&S_zzfs_107_1);
  zzfs(&S_zzfs_110_1);
  or3(&S_or3_227_1);
  zzfs(&S_zzfs_210_1);
  drg(&S_drg_167_1);
  drg(&S_drg_156_1);
  geterr(&S_geterr_98_1);
  drg(&S_drg_104_1);
  drg(&S_drg_94_1);
  drg(&S_drg_121_1);
  drg(&S_drg_106_1);
  geterr(&S_geterr_101_1);
  tprg(&S_tprg_124_1);
  tprg(&S_tprg_128_1);
  noto(&S_noto_111_1);
  noto(&S_noto_126_1);
  noto(&S_noto_139_1);
  geterr(&S_geterr_152_1);
  drg(&S_drg_170_1);
  drg(&S_drg_159_1);
  geterr(&S_geterr_150_1);
  noto(&S_noto_112_1);
  noto(&S_noto_136_1);
  noto(&S_noto_137_1);
  or2(&S_or2_35_1);
  or2(&S_or2_297_1);
  or2(&S_or2_157_1);
  or2(&S_or2_155_1);
  schl24(&S_schl24_238_1);
  and2(&S_and2_239_1);
  schl24(&S_schl24_265_1);
  and2(&S_and2_267_1);
  or2(&S_or2_254_1);
  or2(&S_or2_215_1);
  and2(&S_and2_87_1);
  and2(&S_and2_85_1);
  and2(&S_and2_83_1);
  and2(&S_and2_81_1);
  or2(&S_or2_108_1);
  or2(&S_or2_103_1);
  and2(&S_and2_138_1);
  and2(&S_and2_127_1);
  diagndev(&S_diagndev_305_1);
  or3(&S_or3_313_1);
  noto(&S_noto_223_1);
  ornc(&S_ornc_12_1);
  ornc(&S_ornc_3_1);
  srm(&S_srm_2_1);
  bol(&S_bol_178_1);
  bol(&S_bol_180_1);
  react(&S_react_175_1);
  noto(&S_noto_256_1);
  noto(&S_noto_7_1);
  srm(&S_srm_291_1);
  bol(&S_bol_179_1);
  ovb1(&S_ovb1_33_1);
  noto(&S_noto_27_1);
  and2(&S_and2_5_1);
  or2(&S_or2_10_1);
  and2(&S_and2_6_1);
  and2(&S_and2_21_1);
  and2(&S_and2_241_1);
  or2(&S_or2_253_1);
  and2(&S_and2_263_1);
  and2(&S_and2_261_1);
  or2(&S_or2_260_1);
  and2(&S_and2_281_1);
  and2(&S_and2_214_1);
  and2(&S_and2_184_1);
  and2(&S_and2_183_1);
  inicn(&S_inicn_205_1);
  and2(&S_and2_226_1);
  noto(&S_noto_251_1);
  noto(&S_noto_288_1);
  noto(&S_noto_14_1);
  zpfs(&S_zpfs_225_1);
  or2(&S_or2_11_1);
  and2(&S_and2_286_1);
  and2(&S_and2_257_1);
  and2(&S_and2_246_1);
  or2(&S_or2_247_1);
  and2(&S_and2_250_1);
  or2(&S_or2_262_1);
  and2(&S_and2_284_1);
  and2(&S_and2_282_1);
  noto(&S_noto_287_1);
  noto(&S_noto_15_1);
  or3(&S_or3_18_1);
  and2(&S_and2_19_1);
  or2(&S_or2_245_1);
  and2(&S_and2_249_1);
  and2(&S_and2_258_1);
  and2(&S_and2_283_1);
  and2(&S_and2_285_1);
  orn(&S_orn_16_1);
  orni(&S_orni_280_1);
  rsu(&S_rsu_278_1);
  or3(&S_or3_30_1);
  and2(&S_and2_31_1);
  orn(&S_orn_36_1);
  or2(&S_or2_25_1);
  setData(idR0VZ05U,&var113);
  setData(idTestDiagnBaz1,&var16);
  setData(idR0DE3DLZ1,&var17);
  setData(idR0DE3CLZ1,&var18);
  setData(idTTLBaz1,&var20);
  moveData(idR0EE04LZ1,idR0EE02LDU);
  moveData(idR0EE03LZ1,idR0EE02LDU);
  moveData(idR0EE02LZ1,idR0EE02LDU);
  moveData(idR0EE01LZ1,idR0EE02LDU);
  setData(idR0AD14LZ1,&var11);
  setData(idA3VZ13LZ1,&var7);
  setData(idA3VZ15LZ1,&var10);
  setData(idA1VN71LZ1,&var36);
  setData(idB0VT71LZ1,&var70);
  setData(idB0VT61LZ1,&var106);
  setData(idB0CT01IZ1,&var100);
  setData(idR0VP73LZ1,&var71);
  setData(idR0VN11RZ1,&var111);
  setData(idR0VZ05UZ1,&var112);
  setData(idB0VN81LZ1,&var54);
  setData(idA0VN81LZ1,&var73);
  setData(idB0VN71LZ1,&var59);
  setData(idA0VN71LZ1,&var56);
  setData(idB0VZ71LZ1,&var114);
  setData(idB0EE00LZ1,&var82);
  setData(idA0EE00LZ1,&var83);
  setData(idA0VZ71LZ1,&var115);
  setData(idA0EE03LZ1,&var27);
  setData(idA0EE02LZ1,&var26);
  setData(idA0EE04LZ1,&var28);
  setData(idA0EE01LZ1,&var25);
  setData(idR0VN80LZ1,&var52);
  setData(idR0VN70LZ1,&var62);
  setData(idR0VZ71LZ1,&var76);
  setData(idR0VR02RZ1,&var123);
  setData(idR0VN79LZ1,&var30);
  setData(idR0VN69LZ1,&var29);
  setData(idB3VZ11LZ1,&var9);
  setData(idA3VZ11LZ1,&var8);
  setData(idB3VZ31LZ1,&var6);
  setData(idA3VZ31LZ1,&var5);
  setData(idR0VN09RZ1,&var126);
  moveData(idR0VN68LZ1,idR0VN65LS4);
  moveData(idR0VN67LZ1,idR0VN65LS3);
  moveData(idR0VN66LZ1,idR0VN65LS2);
  moveData(idR0VN65LZ1,idR0VN65LS1);
  moveData(idR0VN64LZ1,idR0VN61LS4);
  moveData(idR0VN63LZ1,idR0VN61LS3);
  moveData(idR0VN62LZ1,idR0VN61LS2);
  moveData(idR0VN61LZ1,idR0VN61LS1);
  moveData(idR0VN08RZ1,idR0VN01RS4);
  moveData(idR0VN07RZ1,idR0VN01RS3);
  moveData(idR0VN06RZ1,idR0VN01RS2);
  moveData(idR0VN05RZ1,idR0VN01RS1);
  moveData(idR0VN04RZ1,idR0VN02RS4);
  moveData(idR0VN03RZ1,idR0VN02RS3);
  moveData(idR0VN02RZ1,idR0VN02RS2);
  moveData(idR0VN01RZ1,idR0VN02RS1);
  setData(idB0VP71LZ1,&var130);
  setData(idA0VP71LZ1,&var128);
  setData(idA0EP02IZ1,&var129);
  setData(idB0EP02IZ1,&var131);
  setData(idR0ET02LZ1,&var107);
  setData(idB0VP41LZ1,&var89);
  setData(idA0VP41LZ1,&var90);
  setData(idR0ET01LZ1,&var102);
  setData(idA2VP81LZ1,&var21);
  setData(idB2VP81LZ1,&var22);
  setData(idB2VP51LZ1,&var136);
  setData(idB2CP01RZ1,&var103);
  setData(idB2VP41LZ1,&var24);
  setData(idA2VP51LZ1,&var138);
  setData(idA2CP01RZ1,&var104);
  setData(idA2VP41LZ1,&var23);
  setData(idB1VP41LZ1,&var91);
  setData(idA1VP41LZ1,&var110);
  setData(idA0VT71LZ1,&var69);
  setData(idA0VT61LZ1,&var141);
  setData(idA0CT01IZ1,&var101);

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
