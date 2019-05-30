#ifndef BAZ1_H
#define BAZ1_H
// Подсистема Baz1:Baz1
static char SimulOn=0;
static short CodeSub=4;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=50;	 // Время цикла в ms
float takt, taktScheme=0, taktSS=0;
#define SIZE_BUFFER 647
static char BUFFER[647];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.52\0", 5432, "192.168.10.152\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0VN11RZ1	 BUFFER[0]	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
#define idR0VN11RZ1	 1	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
#define R0VP73LZ1	 BUFFER[5]	//( - , Baz1, SBz1DU) ПС давления для РУ
#define idR0VP73LZ1	 2	//( - , Baz1, SBz1DU) ПС давления для РУ
#define B0CT01IZ1	 BUFFER[7]	//( - , Baz1, SBz1DU) Температура АЗ2-1
#define idB0CT01IZ1	 3	//( - , Baz1, SBz1DU) Температура АЗ2-1
#define B0VT61LZ1	 BUFFER[12]	//( - , Baz1) ПС по температуре в АЗ2
#define idB0VT61LZ1	 4	//( - , Baz1) ПС по температуре в АЗ2
#define B0VT71LZ1	 BUFFER[14]	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
#define idB0VT71LZ1	 5	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
#define A0VN71LS1	 BUFFER[16]	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
#define idA0VN71LS1	 6	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
#define A0VN71LS2	 BUFFER[18]	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
#define idA0VN71LS2	 7	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
#define A0VN71LS3	 BUFFER[20]	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
#define idA0VN71LS3	 8	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
#define A0VN71LS4	 BUFFER[22]	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
#define idA0VN71LS4	 9	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
#define A1VN71LZ1	 BUFFER[24]	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	 10	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
#define A3VZ15LZ1	 BUFFER[26]	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
#define idA3VZ15LZ1	 11	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
#define A3VZ13LZ1	 BUFFER[28]	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
#define idA3VZ13LZ1	 12	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
#define R0VW13LDU	 BUFFER[30]	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 13	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	 BUFFER[32]	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 14	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R7II73LZ1	 BUFFER[34]	//(vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
#define idR7II73LZ1	 15	//(vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
#define R7II71LZ1	 BUFFER[36]	//(vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
#define idR7II71LZ1	 16	//(vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
#define R7II72LZ1	 BUFFER[38]	//(vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
#define idR7II72LZ1	 17	//(vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
#define R0AD14LZ1	 BUFFER[40]	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define idR0AD14LZ1	 18	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define R0AD21LDU	 BUFFER[42]	//( - , SBz1DU) Подключить защиту от II УР
#define idR0AD21LDU	 19	//( - , SBz1DU) Подключить защиту от II УР
#define A0EE01LS3	 BUFFER[44]	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define idA0EE01LS3	 20	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define A0EE01LZ1	 BUFFER[46]	//( - , Baz1, SBz1DU) Исправность АКНП1
#define idA0EE01LZ1	 21	//( - , Baz1, SBz1DU) Исправность АКНП1
#define A0EE04LZ1	 BUFFER[48]	//( - , Baz1, SBz1DU) Исправность АКНП4
#define idA0EE04LZ1	 22	//( - , Baz1, SBz1DU) Исправность АКНП4
#define A0EE02LZ1	 BUFFER[50]	//( - , Baz1, SBz1DU) Исправность АКНП2
#define idA0EE02LZ1	 23	//( - , Baz1, SBz1DU) Исправность АКНП2
#define A0EE03LZ1	 BUFFER[52]	//( - , Baz1, SBz1DU) Исправность АКНП3
#define idA0EE03LZ1	 24	//( - , Baz1, SBz1DU) Исправность АКНП3
#define A0EE01LS2	 BUFFER[54]	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define idA0EE01LS2	 25	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define A0EE05LZ1	 BUFFER[56]	//( - , Baz1) Исправность сети АКНП1
#define idA0EE05LZ1	 26	//( - , Baz1) Исправность сети АКНП1
#define A0EE06LZ1	 BUFFER[58]	//( - , Baz1) Исправность сети АКНП2
#define idA0EE06LZ1	 27	//( - , Baz1) Исправность сети АКНП2
#define A0EE07LZ1	 BUFFER[60]	//( - , Baz1) Исправность сети АКНП3
#define idA0EE07LZ1	 28	//( - , Baz1) Исправность сети АКНП3
#define A0EE08LZ1	 BUFFER[62]	//( - , Baz1) Исправность сети АКНП4
#define idA0EE08LZ1	 29	//( - , Baz1) Исправность сети АКНП4
#define A0VZ71LZ1	 BUFFER[64]	//( - , Baz1) Обобщенный сигнал АС по АЗ1
#define idA0VZ71LZ1	 30	//( - , Baz1) Обобщенный сигнал АС по АЗ1
#define A0EE00LZ1	 BUFFER[66]	//( - , Baz1) Исправность АКНП АЗ1
#define idA0EE00LZ1	 31	//( - , Baz1) Исправность АКНП АЗ1
#define B0EE00LZ1	 BUFFER[68]	//( - , Baz1) Исправность АКНП АЗ2
#define idB0EE00LZ1	 32	//( - , Baz1) Исправность АКНП АЗ2
#define B0VZ71LZ1	 BUFFER[70]	//( - , Baz1) Обобщенный сигнал АС по АЗ2
#define idB0VZ71LZ1	 33	//( - , Baz1) Обобщенный сигнал АС по АЗ2
#define A0VN71LZ1	 BUFFER[72]	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
#define idA0VN71LZ1	 34	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
#define B0VN71LZ1	 BUFFER[74]	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
#define idB0VN71LZ1	 35	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
#define A0VN81LZ1	 BUFFER[76]	//( - , Baz1) АЗ по АС периода разгона АЗ1
#define idA0VN81LZ1	 36	//( - , Baz1) АЗ по АС периода разгона АЗ1
#define B0VN81LZ1	 BUFFER[78]	//( - , Baz1) АЗ по АС периода разгона АЗ2
#define idB0VN81LZ1	 37	//( - , Baz1) АЗ по АС периода разгона АЗ2
#define R0EE02LDU	 BUFFER[80]	//( - , Baz1) Питание  АКНП  отключить
#define idR0EE02LDU	 38	//( - , Baz1) Питание  АКНП  отключить
#define R0VZ05UZ1	 BUFFER[82]	//( - , Baz1) Индикатор причины сброса
#define idR0VZ05UZ1	 39	//( - , Baz1) Индикатор причины сброса
#define A2IS12LDU	 BUFFER[87]	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	 40	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define B2IS12LDU	 BUFFER[89]	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	 41	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define R0DE04LZ1	 BUFFER[91]	//(vas84:04 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
#define idR0DE04LZ1	 42	//(vas84:04 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
#define R0DE05LZ1	 BUFFER[94]	//(vds32:05 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
#define idR0DE05LZ1	 43	//(vds32:05 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
#define R0DE06LZ1	 BUFFER[97]	//(vds32:06 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
#define idR0DE06LZ1	 44	//(vds32:06 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
#define R0DE08LZ1	 BUFFER[100]	//(vds32:08 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
#define idR0DE08LZ1	 45	//(vds32:08 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
#define R0DE07LZ1	 BUFFER[103]	//(vds32:07 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
#define idR0DE07LZ1	 46	//(vds32:07 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
#define R0DE0ALZ1	 BUFFER[106]	//(fds16:0a - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
#define idR0DE0ALZ1	 47	//(fds16:0a - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
#define TTLBaz1	 BUFFER[109]	//( - , Baz1) ttl
#define idTTLBaz1	 48	//( - , Baz1) ttl
#define R0DEB1LZ1	 BUFFER[112]	//(sbk:20 - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
#define idR0DEB1LZ1	 49	//(sbk:20 - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
#define R0DEB2LZ1	 BUFFER[114]	//(sbk:20 - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
#define idR0DEB2LZ1	 50	//(sbk:20 - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
#define R0DEB4LZ1	 BUFFER[116]	//(sbk:20 - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
#define idR0DEB4LZ1	 51	//(sbk:20 - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
#define R0DEB3LZ1	 BUFFER[118]	//(sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
#define idR0DEB3LZ1	 52	//(sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
#define R0DE3CLZ1	 BUFFER[120]	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 5
#define idR0DE3CLZ1	 53	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 5
#define R0DE3DLZ1	 BUFFER[122]	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 6
#define idR0DE3DLZ1	 54	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 6
#define TestDiagnBaz1	 BUFFER[124]	//( - , Baz1) Неисправность от диагностики
#define idTestDiagnBaz1	 55	//( - , Baz1) Неисправность от диагностики
#define R0MW11IP1	 BUFFER[126]	//( - , Baz1) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 56	//( - , Baz1) Переключатель ВЫСТРЕЛ
#define R0VZ05U	 BUFFER[129]	//( - , - ) причины сброса
#define idR0VZ05U	 57	//( - , - ) причины сброса
#define B8VC01RDU	 BUFFER[134]	//( - , SBz1DU, MBz1A1, MBz1A2, MBz1A3, MBz1A4) Координата АЗ2, мм
#define idB8VC01RDU	 58	//( - , SBz1DU, MBz1A1, MBz1A2, MBz1A3, MBz1A4) Координата АЗ2, мм
#define R0S01LZ1	 BUFFER[139]	//(vds32:08 - K08VDSR, - ) Отключение сетевых передач в Баз1
#define idR0S01LZ1	 59	//(vds32:08 - K08VDSR, - ) Отключение сетевых передач в Баз1
#define R0AD14LDU	 BUFFER[141]	//( - , Baz1) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 60	//( - , Baz1) Имитация срабатывания верхней АС II УР
#define R0MD34LP1	 BUFFER[143]	//( - , Baz1) Кнопка (Квитировать)
#define idR0MD34LP1	 61	//( - , Baz1) Кнопка (Квитировать)
#define R0AD04LZ1	 BUFFER[145]	//(vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
#define idR0AD04LZ1	 62	//(vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
#define R0AD16LDU	 BUFFER[147]	//( - , Baz1) Имитация срабатывания верхней АС I УР
#define idR0AD16LDU	 63	//( - , Baz1) Имитация срабатывания верхней АС I УР
#define R0EE01LZ1	 BUFFER[149]	//( - , MBz1S) Питание  АКНП1  отключить
#define idR0EE01LZ1	 64	//( - , MBz1S) Питание  АКНП1  отключить
#define R6IS66LZZ	 BUFFER[151]	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 65	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[153]	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 66	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[155]	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 67	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define R0VN71LZ1	 BUFFER[157]	//(vds32:05 - K01VDSR, Baz1) АС по мощности канал 1
#define idR0VN71LZ1	 68	//(vds32:05 - K01VDSR, Baz1) АС по мощности канал 1
#define R0VN75LZ1	 BUFFER[159]	//(vds32:05 - K02VDSR, Baz1) АС по периоду разгона канал 1
#define idR0VN75LZ1	 69	//(vds32:05 - K02VDSR, Baz1) АС по периоду разгона канал 1
#define R0VN72LZ1	 BUFFER[161]	//(vds32:06 - K01VDSR, Baz1) АС по мощности канал 2
#define idR0VN72LZ1	 70	//(vds32:06 - K01VDSR, Baz1) АС по мощности канал 2
#define R0VN76LZ1	 BUFFER[163]	//(vds32:06 - K02VDSR, Baz1) АС по периоду разгона канал  2
#define idR0VN76LZ1	 71	//(vds32:06 - K02VDSR, Baz1) АС по периоду разгона канал  2
#define R0VN73LZ1	 BUFFER[165]	//(vds32:08 - K01VDSR, Baz1) АС по мощности канал 3
#define idR0VN73LZ1	 72	//(vds32:08 - K01VDSR, Baz1) АС по мощности канал 3
#define R0VN77LZ1	 BUFFER[167]	//(vds32:08 - K02VDSR, Baz1) АС по периоду разгона канал  3
#define idR0VN77LZ1	 73	//(vds32:08 - K02VDSR, Baz1) АС по периоду разгона канал  3
#define R0VN74LZ1	 BUFFER[169]	//(vds32:07 - K01VDSR, Baz1) АС по мощности канал 4
#define idR0VN74LZ1	 74	//(vds32:07 - K01VDSR, Baz1) АС по мощности канал 4
#define R0VN78LZ1	 BUFFER[171]	//(vds32:07 - K02VDSR, Baz1) АС по периоду разгона канал  4
#define idR0VN78LZ1	 75	//(vds32:07 - K02VDSR, Baz1) АС по периоду разгона канал  4
#define R0EE02LZ1	 BUFFER[173]	//( - , MBz1S) Питание  АКНП2  отключить
#define idR0EE02LZ1	 76	//( - , MBz1S) Питание  АКНП2  отключить
#define R0EE03LZ1	 BUFFER[175]	//( - , MBz1S) Питание  АКНП3  отключить
#define idR0EE03LZ1	 77	//( - , MBz1S) Питание  АКНП3  отключить
#define R0EE04LZ1	 BUFFER[177]	//( - , MBz1S) Питание  АКНП4  отключить
#define idR0EE04LZ1	 78	//( - , MBz1S) Питание  АКНП4  отключить
#define R0MW12IP2	 BUFFER[179]	//( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define idR0MW12IP2	 79	//( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define A0VP41LZ1	 BUFFER[182]	//( - , Baz1) Давление АЗ1 ниже АС
#define idA0VP41LZ1	 80	//( - , Baz1) Давление АЗ1 ниже АС
#define B0VP41LZ1	 BUFFER[184]	//( - , Baz1) Давление АЗ2 ниже АС
#define idB0VP41LZ1	 81	//( - , Baz1) Давление АЗ2 ниже АС
#define B0VP81LZZ	 BUFFER[186]	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	 82	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define A0VP81LZZ	 BUFFER[188]	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define idA0VP81LZZ	 83	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define R0ET02LZ1	 BUFFER[190]	//( - , Baz1) Признак наличия неисправности по температуре АЗ2
#define idR0ET02LZ1	 84	//( - , Baz1) Признак наличия неисправности по температуре АЗ2
#define B0EP02IZ1	 BUFFER[192]	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
#define idB0EP02IZ1	 85	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
#define A0EP02IZ1	 BUFFER[195]	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
#define idA0EP02IZ1	 86	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
#define A0VP71LZ1	 BUFFER[198]	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	 87	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
#define B0VP71LZ1	 BUFFER[200]	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	 88	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
#define R0VN02RS1	 BUFFER[202]	//( - , MBz1A1) Уровень мощности канал 1
#define idR0VN02RS1	 89	//( - , MBz1A1) Уровень мощности канал 1
#define R0VN02RS2	 BUFFER[207]	//( - , MBz1A2) Уровень мощности канал 2
#define idR0VN02RS2	 90	//( - , MBz1A2) Уровень мощности канал 2
#define R0VN02RS3	 BUFFER[212]	//( - , MBz1A3) Уровень мощности канал 3
#define idR0VN02RS3	 91	//( - , MBz1A3) Уровень мощности канал 3
#define R0VN02RS4	 BUFFER[217]	//( - , MBz1A4) Уровень мощности канал 4
#define idR0VN02RS4	 92	//( - , MBz1A4) Уровень мощности канал 4
#define R0VN01RS1	 BUFFER[222]	//( - , MBz1A1) Период разгона канал 1
#define idR0VN01RS1	 93	//( - , MBz1A1) Период разгона канал 1
#define R0VN01RS2	 BUFFER[227]	//( - , MBz1A2) Период разгона канал 2
#define idR0VN01RS2	 94	//( - , MBz1A2) Период разгона канал 2
#define R0VN01RS3	 BUFFER[232]	//( - , MBz1A3) Период разгона канал 3
#define idR0VN01RS3	 95	//( - , MBz1A3) Период разгона канал 3
#define R0VN01RS4	 BUFFER[237]	//( - , MBz1A4) Период разгона канал 4
#define idR0VN01RS4	 96	//( - , MBz1A4) Период разгона канал 4
#define R0VN61LS1	 BUFFER[242]	//( - , MBz1A1) ПС по мощности канал 1
#define idR0VN61LS1	 97	//( - , MBz1A1) ПС по мощности канал 1
#define R0VN61LS2	 BUFFER[244]	//( - , MBz1A2) ПС по мощности канал 2
#define idR0VN61LS2	 98	//( - , MBz1A2) ПС по мощности канал 2
#define R0VN61LS3	 BUFFER[246]	//( - , MBz1A3) ПС по мощности канал 3
#define idR0VN61LS3	 99	//( - , MBz1A3) ПС по мощности канал 3
#define A0IT01IZ1	 BUFFER[248]	//(vas84:04 - K01VASR, - ) Температура АЗ1-1
#define idA0IT01IZ1	 100	//(vas84:04 - K01VASR, - ) Температура АЗ1-1
#define A0CT01IZ1	 BUFFER[251]	//( - , Baz1, SBz1DU) Температура АЗ1-1
#define idA0CT01IZ1	 101	//( - , Baz1, SBz1DU) Температура АЗ1-1
#define A0VT61LZ1	 BUFFER[256]	//( - , Baz1) ПС по температуре в АЗ1
#define idA0VT61LZ1	 102	//( - , Baz1) ПС по температуре в АЗ1
#define A0VT71LZ1	 BUFFER[258]	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
#define idA0VT71LZ1	 103	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
#define A1VP41LZ1	 BUFFER[260]	//( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	 104	//( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
#define B1VP41LZ1	 BUFFER[262]	//( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	 105	//( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
#define B1VP81LZZ	 BUFFER[264]	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	 106	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define A1VP81LZZ	 BUFFER[266]	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	 107	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define A2VP41LZ1	 BUFFER[268]	//( - , Baz1) Давление СБРОС РБ1 ниже АС
#define idA2VP41LZ1	 108	//( - , Baz1) Давление СБРОС РБ1 ниже АС
#define A2CP01RZ1	 BUFFER[270]	//( - , Baz1) Текущее давление СБРОС РБ1
#define idA2CP01RZ1	 109	//( - , Baz1) Текущее давление СБРОС РБ1
#define A2VP51LZ1	 BUFFER[275]	//( - , Baz1) Давление СБРОС РБ1 ниже ПС
#define idA2VP51LZ1	 110	//( - , Baz1) Давление СБРОС РБ1 ниже ПС
#define B2VP41LZ1	 BUFFER[277]	//( - , Baz1) Давление СБРОС РБ2 ниже АС
#define idB2VP41LZ1	 111	//( - , Baz1) Давление СБРОС РБ2 ниже АС
#define B2CP01RZ1	 BUFFER[279]	//( - , Baz1) Текущее давление СБРОС РБ2
#define idB2CP01RZ1	 112	//( - , Baz1) Текущее давление СБРОС РБ2
#define B2VP51LZ1	 BUFFER[284]	//( - , Baz1) Давление СБРОС РБ2 ниже ПС
#define idB2VP51LZ1	 113	//( - , Baz1) Давление СБРОС РБ2 ниже ПС
#define B2VP81LZ1	 BUFFER[286]	//( - , Baz1) Давление СБРОС РБ2 в норме
#define idB2VP81LZ1	 114	//( - , Baz1) Давление СБРОС РБ2 в норме
#define A2VP81LZ1	 BUFFER[288]	//( - , Baz1) Давление СБРОС РБ1 в норме
#define idA2VP81LZ1	 115	//( - , Baz1) Давление СБРОС РБ1 в норме
#define A2IP01IZ1	 BUFFER[290]	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	 116	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define B2IP01IZ1	 BUFFER[293]	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	 117	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define R0ET01LZ1	 BUFFER[296]	//( - , Baz1) Признак наличия неисправности по температуре  АЗ1
#define idR0ET01LZ1	 118	//( - , Baz1) Признак наличия неисправности по температуре  АЗ1
#define B0IT01IZ1	 BUFFER[298]	//(vas84:04 - K03VASR, - ) Температура АЗ2-1
#define idB0IT01IZ1	 119	//(vas84:04 - K03VASR, - ) Температура АЗ2-1
#define R0VN68LZ1	 BUFFER[301]	//( - , Baz1) ПС по периоду разгона канал 4
#define idR0VN68LZ1	 120	//( - , Baz1) ПС по периоду разгона канал 4
#define R0VN09RZ1	 BUFFER[303]	//( - , Baz1) Усредненный период разгона
#define idR0VN09RZ1	 121	//( - , Baz1) Усредненный период разгона
#define A3IS11LDU	 BUFFER[308]	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define idA3IS11LDU	 122	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define A3IS22LDU	 BUFFER[310]	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define idA3IS22LDU	 123	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define R0AD03LZ1	 BUFFER[312]	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define idR0AD03LZ1	 124	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define B3IS11LDU	 BUFFER[314]	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define idB3IS11LDU	 125	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define A3VZ31LZ1	 BUFFER[316]	//( - , Baz1) АЗ от ВУ ИС1
#define idA3VZ31LZ1	 126	//( - , Baz1) АЗ от ВУ ИС1
#define B3VZ31LZ1	 BUFFER[318]	//( - , Baz1) АЗ от ВУ ИС2
#define idB3VZ31LZ1	 127	//( - , Baz1) АЗ от ВУ ИС2
#define R0AD05LZ1	 BUFFER[320]	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define idR0AD05LZ1	 128	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define A3VZ11LZ1	 BUFFER[322]	//( - , Baz1) АЗ от НУП ИС1
#define idA3VZ11LZ1	 129	//( - , Baz1) АЗ от НУП ИС1
#define B3VZ11LZ1	 BUFFER[324]	//( - , Baz1) АЗ от НУП ИС2
#define idB3VZ11LZ1	 130	//( - , Baz1) АЗ от НУП ИС2
#define B3IS22LDU	 BUFFER[326]	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
#define idB3IS22LDU	 131	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
#define R0VN69LZ1	 BUFFER[328]	//( - , Baz1) ПС по усредненному периоду
#define idR0VN69LZ1	 132	//( - , Baz1) ПС по усредненному периоду
#define R0VN79LZ1	 BUFFER[330]	//( - , Baz1) АС по усредненному периоду
#define idR0VN79LZ1	 133	//( - , Baz1) АС по усредненному периоду
#define R0VR02RZ1	 BUFFER[332]	//( - , Baz1) Усредненная реактивность
#define idR0VR02RZ1	 134	//( - , Baz1) Усредненная реактивность
#define R0VZ71LZ1	 BUFFER[337]	//(fds16:0a - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
#define idR0VZ71LZ1	 135	//(fds16:0a - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
#define R0VN70LZ1	 BUFFER[339]	//( - , Baz1) АЗ по АС мощности РУ
#define idR0VN70LZ1	 136	//( - , Baz1) АЗ по АС мощности РУ
#define R0VN80LZ1	 BUFFER[341]	//( - , Baz1) АЗ по АС периода разгона РУ
#define idR0VN80LZ1	 137	//( - , Baz1) АЗ по АС периода разгона РУ
#define A0EE01LS1	 BUFFER[343]	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define idA0EE01LS1	 138	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define A0EE01LS4	 BUFFER[345]	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define idA0EE01LS4	 139	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define R0VN61LS4	 BUFFER[347]	//( - , MBz1A4) ПС по мощности канал 4
#define idR0VN61LS4	 140	//( - , MBz1A4) ПС по мощности канал 4
#define R0VN65LS1	 BUFFER[349]	//( - , MBz1A1) ПС по периоду разгона канал 1
#define idR0VN65LS1	 141	//( - , MBz1A1) ПС по периоду разгона канал 1
#define R0VN65LS2	 BUFFER[351]	//( - , MBz1A2) ПС по периоду разгона  канал 2
#define idR0VN65LS2	 142	//( - , MBz1A2) ПС по периоду разгона  канал 2
#define R0VN65LS3	 BUFFER[353]	//( - , MBz1A3) ПС по периоду разгона канал 3
#define idR0VN65LS3	 143	//( - , MBz1A3) ПС по периоду разгона канал 3
#define R0VN65LS4	 BUFFER[355]	//( - , MBz1A4) ПС по периоду разгона канал 4
#define idR0VN65LS4	 144	//( - , MBz1A4) ПС по периоду разгона канал 4
#define R0VN01RZ1	 BUFFER[357]	//( - , Baz1) Уровень мощности по каналу 1
#define idR0VN01RZ1	 145	//( - , Baz1) Уровень мощности по каналу 1
#define R0VN02RZ1	 BUFFER[362]	//( - , Baz1) Уровень мощности по каналу 2
#define idR0VN02RZ1	 146	//( - , Baz1) Уровень мощности по каналу 2
#define R0VN03RZ1	 BUFFER[367]	//( - , Baz1) Уровень мощности по каналу 3
#define idR0VN03RZ1	 147	//( - , Baz1) Уровень мощности по каналу 3
#define R0VN04RZ1	 BUFFER[372]	//( - , Baz1) Уровень мощности по каналу 4
#define idR0VN04RZ1	 148	//( - , Baz1) Уровень мощности по каналу 4
#define R0VN05RZ1	 BUFFER[377]	//( - , Baz1) Период разгона по каналу 1
#define idR0VN05RZ1	 149	//( - , Baz1) Период разгона по каналу 1
#define R0VN06RZ1	 BUFFER[382]	//( - , Baz1) Период разгона по каналу 2
#define idR0VN06RZ1	 150	//( - , Baz1) Период разгона по каналу 2
#define R0VN07RZ1	 BUFFER[387]	//( - , Baz1) Период разгона по каналу 3
#define idR0VN07RZ1	 151	//( - , Baz1) Период разгона по каналу 3
#define R0VN08RZ1	 BUFFER[392]	//( - , Baz1) Период разгона по каналу 4
#define idR0VN08RZ1	 152	//( - , Baz1) Период разгона по каналу 4
#define R0VN61LZ1	 BUFFER[397]	//( - , Baz1) ПС по мощности канал 1
#define idR0VN61LZ1	 153	//( - , Baz1) ПС по мощности канал 1
#define R0VN62LZ1	 BUFFER[399]	//( - , Baz1) ПС по мощности канал 2
#define idR0VN62LZ1	 154	//( - , Baz1) ПС по мощности канал 2
#define R0VN63LZ1	 BUFFER[401]	//( - , Baz1) ПС по мощности канал 3
#define idR0VN63LZ1	 155	//( - , Baz1) ПС по мощности канал 3
#define R0VN64LZ1	 BUFFER[403]	//( - , Baz1) ПС по мощности канал 4
#define idR0VN64LZ1	 156	//( - , Baz1) ПС по мощности канал 4
#define R0VN65LZ1	 BUFFER[405]	//( - , Baz1) ПС по периоду разгона канал 1
#define idR0VN65LZ1	 157	//( - , Baz1) ПС по периоду разгона канал 1
#define R0VN66LZ1	 BUFFER[407]	//( - , Baz1) ПС по периоду разгона канал 2
#define idR0VN66LZ1	 158	//( - , Baz1) ПС по периоду разгона канал 2
#define R0VN67LZ1	 BUFFER[409]	//( - , Baz1) ПС по периоду разгона канал 3
#define idR0VN67LZ1	 159	//( - , Baz1) ПС по периоду разгона канал 3
#define fEM_R0UT02RZZ	 BUFFER[411]	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	 160	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RZZ	 BUFFER[416]	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	 161	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_A2UP03RZZ	 BUFFER[421]	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define idfEM_A2UP03RZZ	 162	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define fEM_A2UP04RZZ	 BUFFER[426]	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define idfEM_A2UP04RZZ	 163	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define fEM_R0UT72RZZ	 BUFFER[431]	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	 164	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	 BUFFER[436]	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	 165	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	 BUFFER[441]	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	 166	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT61RZZ	 BUFFER[446]	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	 167	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_A2UP41RZZ	 BUFFER[451]	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define idfEM_A2UP41RZZ	 168	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define fEM_A2UP42RZZ	 BUFFER[456]	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define idfEM_A2UP42RZZ	 169	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define fEM_A2UP51RZZ	 BUFFER[461]	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define idfEM_A2UP51RZZ	 170	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define fEM_A2UP81RZZ	 BUFFER[466]	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP81RZZ	 171	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP84RZZ	 BUFFER[471]	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP84RZZ	 172	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP82RZZ	 BUFFER[476]	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP82RZZ	 173	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP52RZZ	 BUFFER[481]	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define idfEM_A2UP52RZZ	 174	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define fEM_A2UP83RZZ	 BUFFER[486]	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP83RZZ	 175	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_R0UR01RZZ	 BUFFER[491]	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RZZ	 176	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R0UR04RZZ	 BUFFER[496]	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define idfEM_R0UR04RZZ	 177	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define fEM_A1UL12RZZ	 BUFFER[501]	//(A1UL12RZZ) Время задержки АЗ от НУП ИС(сек)
#define idfEM_A1UL12RZZ	 178	//(A1UL12RZZ) Время задержки АЗ от НУП ИС(сек)
#define fEM_A1UL11RZZ	 BUFFER[506]	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
#define idfEM_A1UL11RZZ	 179	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
#define fEM_R7UI73RZZ	 BUFFER[511]	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define idfEM_R7UI73RZZ	 180	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define fEM_A1UL13RZZ	 BUFFER[516]	//(A1UL13RZZ) Максимальное время цикла
#define idfEM_A1UL13RZZ	 181	//(A1UL13RZZ) Максимальное время цикла
#define bFirstEnterFlag	 BUFFER[521]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 182	//(bFirstEnterFlag) 
#define internal1_m205_TVuIs1	 BUFFER[523]	//(internal1_m205_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
#define idinternal1_m205_TVuIs1	 183	//(internal1_m205_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
#define internal1_m205_TVuIs2	 BUFFER[528]	//(internal1_m205_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
#define idinternal1_m205_TVuIs2	 184	//(internal1_m205_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
#define internal1_m205_TImVuIs	 BUFFER[533]	//(internal1_m205_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
#define idinternal1_m205_TImVuIs	 185	//(internal1_m205_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
#define internal1_m205_TNupIs1	 BUFFER[538]	//(internal1_m205_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
#define idinternal1_m205_TNupIs1	 186	//(internal1_m205_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
#define internal1_m205_TNupIs2	 BUFFER[543]	//(internal1_m205_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
#define idinternal1_m205_TNupIs2	 187	//(internal1_m205_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
#define internal1_m205_TImNupIs	 BUFFER[548]	//(internal1_m205_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
#define idinternal1_m205_TImNupIs	 188	//(internal1_m205_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
#define internal1_m205_TImAZ2UR	 BUFFER[553]	//(internal1_m205_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
#define idinternal1_m205_TImAZ2UR	 189	//(internal1_m205_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
#define internal1_m205_fef	 BUFFER[558]	//(internal1_m205_fef) fef
#define idinternal1_m205_fef	 190	//(internal1_m205_fef) fef
#define internal1_m108_tx	 BUFFER[560]	//(internal1_m108_tx) tx - время накопленное сек
#define idinternal1_m108_tx	 191	//(internal1_m108_tx) tx - время накопленное сек
#define internal1_m108_y0	 BUFFER[565]	//(internal1_m108_y0) y0
#define idinternal1_m108_y0	 192	//(internal1_m108_y0) y0
#define internal1_m107_tx	 BUFFER[566]	//(internal1_m107_tx) tx - время накопленное сек
#define idinternal1_m107_tx	 193	//(internal1_m107_tx) tx - время накопленное сек
#define internal1_m107_y0	 BUFFER[571]	//(internal1_m107_y0) y0
#define idinternal1_m107_y0	 194	//(internal1_m107_y0) y0
#define internal1_m135_tx	 BUFFER[572]	//(internal1_m135_tx) tx - время накопленное сек
#define idinternal1_m135_tx	 195	//(internal1_m135_tx) tx - время накопленное сек
#define internal1_m135_y0	 BUFFER[577]	//(internal1_m135_y0) y0
#define idinternal1_m135_y0	 196	//(internal1_m135_y0) y0
#define internal1_m134_tx	 BUFFER[578]	//(internal1_m134_tx) tx - время накопленное сек
#define idinternal1_m134_tx	 197	//(internal1_m134_tx) tx - время накопленное сек
#define internal1_m134_y0	 BUFFER[583]	//(internal1_m134_y0) y0
#define idinternal1_m134_y0	 198	//(internal1_m134_y0) y0
#define internal1_m314_sttlf	 BUFFER[584]	//(internal1_m314_sttlf) sttlf - счетчик для вещественного формата
#define idinternal1_m314_sttlf	 199	//(internal1_m314_sttlf) sttlf - счетчик для вещественного формата
#define internal1_m225_tx	 BUFFER[587]	//(internal1_m225_tx) tx - время накопленное сек
#define idinternal1_m225_tx	 200	//(internal1_m225_tx) tx - время накопленное сек
#define internal1_m225_y0	 BUFFER[592]	//(internal1_m225_y0) y0
#define idinternal1_m225_y0	 201	//(internal1_m225_y0) y0
#define internal1_m285_tx	 BUFFER[593]	//(internal1_m285_tx) tx - время накопленное сек
#define idinternal1_m285_tx	 202	//(internal1_m285_tx) tx - время накопленное сек
#define internal1_m285_y0	 BUFFER[598]	//(internal1_m285_y0) y0
#define idinternal1_m285_y0	 203	//(internal1_m285_y0) y0
#define internal1_m33_tx	 BUFFER[599]	//(internal1_m33_tx) tx - внутренний параметр
#define idinternal1_m33_tx	 204	//(internal1_m33_tx) tx - внутренний параметр
#define internal1_m148_y0	 BUFFER[602]	//(internal1_m148_y0) y0
#define idinternal1_m148_y0	 205	//(internal1_m148_y0) y0
#define internal1_m146_y0	 BUFFER[607]	//(internal1_m146_y0) y0
#define idinternal1_m146_y0	 206	//(internal1_m146_y0) y0
#define internal1_m92_y0	 BUFFER[612]	//(internal1_m92_y0) y0
#define idinternal1_m92_y0	 207	//(internal1_m92_y0) y0
#define internal1_m90_y0	 BUFFER[617]	//(internal1_m90_y0) y0
#define idinternal1_m90_y0	 208	//(internal1_m90_y0) y0
#define internal1_m159_y1	 BUFFER[622]	//(internal1_m159_y1) y1 - внутренний параметр
#define idinternal1_m159_y1	 209	//(internal1_m159_y1) y1 - внутренний параметр
#define internal1_m170_y1	 BUFFER[624]	//(internal1_m170_y1) y1 - внутренний параметр
#define idinternal1_m170_y1	 210	//(internal1_m170_y1) y1 - внутренний параметр
#define internal1_m278_q0	 BUFFER[626]	//(internal1_m278_q0) q0 - внутренний параметр
#define idinternal1_m278_q0	 211	//(internal1_m278_q0) q0 - внутренний параметр
#define internal1_m128_y0	 BUFFER[631]	//(internal1_m128_y0) state
#define idinternal1_m128_y0	 212	//(internal1_m128_y0) state
#define internal1_m124_y0	 BUFFER[633]	//(internal1_m124_y0) state
#define idinternal1_m124_y0	 213	//(internal1_m124_y0) state
#define internal1_m102_y1	 BUFFER[635]	//(internal1_m102_y1) y1 - внутренний параметр
#define idinternal1_m102_y1	 214	//(internal1_m102_y1) y1 - внутренний параметр
#define internal1_m117_y1	 BUFFER[637]	//(internal1_m117_y1) y1 - внутренний параметр
#define idinternal1_m117_y1	 215	//(internal1_m117_y1) y1 - внутренний параметр
#define internal1_m94_y1	 BUFFER[639]	//(internal1_m94_y1) y1 - внутренний параметр
#define idinternal1_m94_y1	 216	//(internal1_m94_y1) y1 - внутренний параметр
#define internal1_m105_y1	 BUFFER[641]	//(internal1_m105_y1) y1 - внутренний параметр
#define idinternal1_m105_y1	 217	//(internal1_m105_y1) y1 - внутренний параметр
#define internal1_m156_y1	 BUFFER[643]	//(internal1_m156_y1) y1 - внутренний параметр
#define idinternal1_m156_y1	 218	//(internal1_m156_y1) y1 - внутренний параметр
#define internal1_m168_y1	 BUFFER[645]	//(internal1_m168_y1) y1 - внутренний параметр
#define idinternal1_m168_y1	 219	//(internal1_m168_y1) y1 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,8	,1	, &R0VN11RZ1},	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
	{ 2	,1	,1	, &R0VP73LZ1},	//( - , Baz1, SBz1DU) ПС давления для РУ
	{ 3	,8	,1	, &B0CT01IZ1},	//( - , Baz1, SBz1DU) Температура АЗ2-1
	{ 4	,1	,1	, &B0VT61LZ1},	//( - , Baz1) ПС по температуре в АЗ2
	{ 5	,1	,1	, &B0VT71LZ1},	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
	{ 6	,1	,1	, &A0VN71LS1},	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
	{ 7	,1	,1	, &A0VN71LS2},	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
	{ 8	,1	,1	, &A0VN71LS3},	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
	{ 9	,1	,1	, &A0VN71LS4},	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
	{ 10	,1	,1	, &A1VN71LZ1},	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
	{ 11	,1	,1	, &A3VZ15LZ1},	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
	{ 12	,1	,1	, &A3VZ13LZ1},	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
	{ 13	,1	,1	, &R0VW13LDU},	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 14	,1	,1	, &R0VW23LDU},	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 15	,1	,1	, &R7II73LZ1},	//(vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
	{ 16	,1	,1	, &R7II71LZ1},	//(vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
	{ 17	,1	,1	, &R7II72LZ1},	//(vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
	{ 18	,1	,1	, &R0AD14LZ1},	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
	{ 19	,1	,1	, &R0AD21LDU},	//( - , SBz1DU) Подключить защиту от II УР
	{ 20	,1	,1	, &A0EE01LS3},	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
	{ 21	,1	,1	, &A0EE01LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП1
	{ 22	,1	,1	, &A0EE04LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП4
	{ 23	,1	,1	, &A0EE02LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП2
	{ 24	,1	,1	, &A0EE03LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП3
	{ 25	,1	,1	, &A0EE01LS2},	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
	{ 26	,1	,1	, &A0EE05LZ1},	//( - , Baz1) Исправность сети АКНП1
	{ 27	,1	,1	, &A0EE06LZ1},	//( - , Baz1) Исправность сети АКНП2
	{ 28	,1	,1	, &A0EE07LZ1},	//( - , Baz1) Исправность сети АКНП3
	{ 29	,1	,1	, &A0EE08LZ1},	//( - , Baz1) Исправность сети АКНП4
	{ 30	,1	,1	, &A0VZ71LZ1},	//( - , Baz1) Обобщенный сигнал АС по АЗ1
	{ 31	,1	,1	, &A0EE00LZ1},	//( - , Baz1) Исправность АКНП АЗ1
	{ 32	,1	,1	, &B0EE00LZ1},	//( - , Baz1) Исправность АКНП АЗ2
	{ 33	,1	,1	, &B0VZ71LZ1},	//( - , Baz1) Обобщенный сигнал АС по АЗ2
	{ 34	,1	,1	, &A0VN71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
	{ 35	,1	,1	, &B0VN71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
	{ 36	,1	,1	, &A0VN81LZ1},	//( - , Baz1) АЗ по АС периода разгона АЗ1
	{ 37	,1	,1	, &B0VN81LZ1},	//( - , Baz1) АЗ по АС периода разгона АЗ2
	{ 38	,1	,1	, &R0EE02LDU},	//( - , Baz1) Питание  АКНП  отключить
	{ 39	,5	,1	, &R0VZ05UZ1},	//( - , Baz1) Индикатор причины сброса
	{ 40	,1	,1	, &A2IS12LDU},	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
	{ 41	,1	,1	, &B2IS12LDU},	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
	{ 42	,3	,1	, &R0DE04LZ1},	//(vas84:04 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
	{ 43	,3	,1	, &R0DE05LZ1},	//(vds32:05 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
	{ 44	,3	,1	, &R0DE06LZ1},	//(vds32:06 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
	{ 45	,3	,1	, &R0DE08LZ1},	//(vds32:08 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
	{ 46	,3	,1	, &R0DE07LZ1},	//(vds32:07 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
	{ 47	,3	,1	, &R0DE0ALZ1},	//(fds16:0a - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
	{ 48	,3	,1	, &TTLBaz1},	//( - , Baz1) ttl
	{ 49	,1	,1	, &R0DEB1LZ1},	//(sbk:20 - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
	{ 50	,1	,1	, &R0DEB2LZ1},	//(sbk:20 - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
	{ 51	,1	,1	, &R0DEB4LZ1},	//(sbk:20 - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
	{ 52	,1	,1	, &R0DEB3LZ1},	//(sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
	{ 53	,1	,1	, &R0DE3CLZ1},	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 5
	{ 54	,1	,1	, &R0DE3DLZ1},	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 6
	{ 55	,1	,1	, &TestDiagnBaz1},	//( - , Baz1) Неисправность от диагностики
	{ 56	,3	,1	, &R0MW11IP1},	//( - , Baz1) Переключатель ВЫСТРЕЛ
	{ 57	,5	,1	, &R0VZ05U},	//( - , - ) причины сброса
	{ 58	,8	,1	, &B8VC01RDU},	//( - , SBz1DU, MBz1A1, MBz1A2, MBz1A3, MBz1A4) Координата АЗ2, мм
	{ 59	,1	,1	, &R0S01LZ1},	//(vds32:08 - K08VDSR, - ) Отключение сетевых передач в Баз1
	{ 60	,1	,1	, &R0AD14LDU},	//( - , Baz1) Имитация срабатывания верхней АС II УР
	{ 61	,1	,1	, &R0MD34LP1},	//( - , Baz1) Кнопка (Квитировать)
	{ 62	,1	,1	, &R0AD04LZ1},	//(vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
	{ 63	,1	,1	, &R0AD16LDU},	//( - , Baz1) Имитация срабатывания верхней АС I УР
	{ 64	,1	,1	, &R0EE01LZ1},	//( - , MBz1S) Питание  АКНП1  отключить
	{ 65	,1	,1	, &R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 66	,1	,1	, &R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 67	,1	,1	, &R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 68	,1	,1	, &R0VN71LZ1},	//(vds32:05 - K01VDSR, Baz1) АС по мощности канал 1
	{ 69	,1	,1	, &R0VN75LZ1},	//(vds32:05 - K02VDSR, Baz1) АС по периоду разгона канал 1
	{ 70	,1	,1	, &R0VN72LZ1},	//(vds32:06 - K01VDSR, Baz1) АС по мощности канал 2
	{ 71	,1	,1	, &R0VN76LZ1},	//(vds32:06 - K02VDSR, Baz1) АС по периоду разгона канал  2
	{ 72	,1	,1	, &R0VN73LZ1},	//(vds32:08 - K01VDSR, Baz1) АС по мощности канал 3
	{ 73	,1	,1	, &R0VN77LZ1},	//(vds32:08 - K02VDSR, Baz1) АС по периоду разгона канал  3
	{ 74	,1	,1	, &R0VN74LZ1},	//(vds32:07 - K01VDSR, Baz1) АС по мощности канал 4
	{ 75	,1	,1	, &R0VN78LZ1},	//(vds32:07 - K02VDSR, Baz1) АС по периоду разгона канал  4
	{ 76	,1	,1	, &R0EE02LZ1},	//( - , MBz1S) Питание  АКНП2  отключить
	{ 77	,1	,1	, &R0EE03LZ1},	//( - , MBz1S) Питание  АКНП3  отключить
	{ 78	,1	,1	, &R0EE04LZ1},	//( - , MBz1S) Питание  АКНП4  отключить
	{ 79	,3	,1	, &R0MW12IP2},	//( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{ 80	,1	,1	, &A0VP41LZ1},	//( - , Baz1) Давление АЗ1 ниже АС
	{ 81	,1	,1	, &B0VP41LZ1},	//( - , Baz1) Давление АЗ2 ниже АС
	{ 82	,1	,1	, &B0VP81LZZ},	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
	{ 83	,1	,1	, &A0VP81LZZ},	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
	{ 84	,1	,1	, &R0ET02LZ1},	//( - , Baz1) Признак наличия неисправности по температуре АЗ2
	{ 85	,3	,1	, &B0EP02IZ1},	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
	{ 86	,3	,1	, &A0EP02IZ1},	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
	{ 87	,1	,1	, &A0VP71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
	{ 88	,1	,1	, &B0VP71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
	{ 89	,8	,1	, &R0VN02RS1},	//( - , MBz1A1) Уровень мощности канал 1
	{ 90	,8	,1	, &R0VN02RS2},	//( - , MBz1A2) Уровень мощности канал 2
	{ 91	,8	,1	, &R0VN02RS3},	//( - , MBz1A3) Уровень мощности канал 3
	{ 92	,8	,1	, &R0VN02RS4},	//( - , MBz1A4) Уровень мощности канал 4
	{ 93	,8	,1	, &R0VN01RS1},	//( - , MBz1A1) Период разгона канал 1
	{ 94	,8	,1	, &R0VN01RS2},	//( - , MBz1A2) Период разгона канал 2
	{ 95	,8	,1	, &R0VN01RS3},	//( - , MBz1A3) Период разгона канал 3
	{ 96	,8	,1	, &R0VN01RS4},	//( - , MBz1A4) Период разгона канал 4
	{ 97	,1	,1	, &R0VN61LS1},	//( - , MBz1A1) ПС по мощности канал 1
	{ 98	,1	,1	, &R0VN61LS2},	//( - , MBz1A2) ПС по мощности канал 2
	{ 99	,1	,1	, &R0VN61LS3},	//( - , MBz1A3) ПС по мощности канал 3
	{ 100	,3	,1	, &A0IT01IZ1},	//(vas84:04 - K01VASR, - ) Температура АЗ1-1
	{ 101	,8	,1	, &A0CT01IZ1},	//( - , Baz1, SBz1DU) Температура АЗ1-1
	{ 102	,1	,1	, &A0VT61LZ1},	//( - , Baz1) ПС по температуре в АЗ1
	{ 103	,1	,1	, &A0VT71LZ1},	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
	{ 104	,1	,1	, &A1VP41LZ1},	//( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
	{ 105	,1	,1	, &B1VP41LZ1},	//( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
	{ 106	,1	,1	, &B1VP81LZZ},	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
	{ 107	,1	,1	, &A1VP81LZZ},	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
	{ 108	,1	,1	, &A2VP41LZ1},	//( - , Baz1) Давление СБРОС РБ1 ниже АС
	{ 109	,8	,1	, &A2CP01RZ1},	//( - , Baz1) Текущее давление СБРОС РБ1
	{ 110	,1	,1	, &A2VP51LZ1},	//( - , Baz1) Давление СБРОС РБ1 ниже ПС
	{ 111	,1	,1	, &B2VP41LZ1},	//( - , Baz1) Давление СБРОС РБ2 ниже АС
	{ 112	,8	,1	, &B2CP01RZ1},	//( - , Baz1) Текущее давление СБРОС РБ2
	{ 113	,1	,1	, &B2VP51LZ1},	//( - , Baz1) Давление СБРОС РБ2 ниже ПС
	{ 114	,1	,1	, &B2VP81LZ1},	//( - , Baz1) Давление СБРОС РБ2 в норме
	{ 115	,1	,1	, &A2VP81LZ1},	//( - , Baz1) Давление СБРОС РБ1 в норме
	{ 116	,3	,1	, &A2IP01IZ1},	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
	{ 117	,3	,1	, &B2IP01IZ1},	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
	{ 118	,1	,1	, &R0ET01LZ1},	//( - , Baz1) Признак наличия неисправности по температуре  АЗ1
	{ 119	,3	,1	, &B0IT01IZ1},	//(vas84:04 - K03VASR, - ) Температура АЗ2-1
	{ 120	,1	,1	, &R0VN68LZ1},	//( - , Baz1) ПС по периоду разгона канал 4
	{ 121	,8	,1	, &R0VN09RZ1},	//( - , Baz1) Усредненный период разгона
	{ 122	,1	,1	, &A3IS11LDU},	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
	{ 123	,1	,1	, &A3IS22LDU},	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
	{ 124	,1	,1	, &R0AD03LZ1},	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
	{ 125	,1	,1	, &B3IS11LDU},	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
	{ 126	,1	,1	, &A3VZ31LZ1},	//( - , Baz1) АЗ от ВУ ИС1
	{ 127	,1	,1	, &B3VZ31LZ1},	//( - , Baz1) АЗ от ВУ ИС2
	{ 128	,1	,1	, &R0AD05LZ1},	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
	{ 129	,1	,1	, &A3VZ11LZ1},	//( - , Baz1) АЗ от НУП ИС1
	{ 130	,1	,1	, &B3VZ11LZ1},	//( - , Baz1) АЗ от НУП ИС2
	{ 131	,1	,1	, &B3IS22LDU},	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
	{ 132	,1	,1	, &R0VN69LZ1},	//( - , Baz1) ПС по усредненному периоду
	{ 133	,1	,1	, &R0VN79LZ1},	//( - , Baz1) АС по усредненному периоду
	{ 134	,8	,1	, &R0VR02RZ1},	//( - , Baz1) Усредненная реактивность
	{ 135	,1	,1	, &R0VZ71LZ1},	//(fds16:0a - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
	{ 136	,1	,1	, &R0VN70LZ1},	//( - , Baz1) АЗ по АС мощности РУ
	{ 137	,1	,1	, &R0VN80LZ1},	//( - , Baz1) АЗ по АС периода разгона РУ
	{ 138	,1	,1	, &A0EE01LS1},	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
	{ 139	,1	,1	, &A0EE01LS4},	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
	{ 140	,1	,1	, &R0VN61LS4},	//( - , MBz1A4) ПС по мощности канал 4
	{ 141	,1	,1	, &R0VN65LS1},	//( - , MBz1A1) ПС по периоду разгона канал 1
	{ 142	,1	,1	, &R0VN65LS2},	//( - , MBz1A2) ПС по периоду разгона  канал 2
	{ 143	,1	,1	, &R0VN65LS3},	//( - , MBz1A3) ПС по периоду разгона канал 3
	{ 144	,1	,1	, &R0VN65LS4},	//( - , MBz1A4) ПС по периоду разгона канал 4
	{ 145	,8	,1	, &R0VN01RZ1},	//( - , Baz1) Уровень мощности по каналу 1
	{ 146	,8	,1	, &R0VN02RZ1},	//( - , Baz1) Уровень мощности по каналу 2
	{ 147	,8	,1	, &R0VN03RZ1},	//( - , Baz1) Уровень мощности по каналу 3
	{ 148	,8	,1	, &R0VN04RZ1},	//( - , Baz1) Уровень мощности по каналу 4
	{ 149	,8	,1	, &R0VN05RZ1},	//( - , Baz1) Период разгона по каналу 1
	{ 150	,8	,1	, &R0VN06RZ1},	//( - , Baz1) Период разгона по каналу 2
	{ 151	,8	,1	, &R0VN07RZ1},	//( - , Baz1) Период разгона по каналу 3
	{ 152	,8	,1	, &R0VN08RZ1},	//( - , Baz1) Период разгона по каналу 4
	{ 153	,1	,1	, &R0VN61LZ1},	//( - , Baz1) ПС по мощности канал 1
	{ 154	,1	,1	, &R0VN62LZ1},	//( - , Baz1) ПС по мощности канал 2
	{ 155	,1	,1	, &R0VN63LZ1},	//( - , Baz1) ПС по мощности канал 3
	{ 156	,1	,1	, &R0VN64LZ1},	//( - , Baz1) ПС по мощности канал 4
	{ 157	,1	,1	, &R0VN65LZ1},	//( - , Baz1) ПС по периоду разгона канал 1
	{ 158	,1	,1	, &R0VN66LZ1},	//( - , Baz1) ПС по периоду разгона канал 2
	{ 159	,1	,1	, &R0VN67LZ1},	//( - , Baz1) ПС по периоду разгона канал 3
	{ 160	,8	,1	, &fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{ 161	,8	,1	, &fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{ 162	,8	,1	, &fEM_A2UP03RZZ},	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{ 163	,8	,1	, &fEM_A2UP04RZZ},	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{ 164	,8	,1	, &fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{ 165	,8	,1	, &fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{ 166	,8	,1	, &fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{ 167	,8	,1	, &fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{ 168	,8	,1	, &fEM_A2UP41RZZ},	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{ 169	,8	,1	, &fEM_A2UP42RZZ},	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{ 170	,8	,1	, &fEM_A2UP51RZZ},	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{ 171	,8	,1	, &fEM_A2UP81RZZ},	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{ 172	,8	,1	, &fEM_A2UP84RZZ},	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{ 173	,8	,1	, &fEM_A2UP82RZZ},	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{ 174	,8	,1	, &fEM_A2UP52RZZ},	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{ 175	,8	,1	, &fEM_A2UP83RZZ},	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{ 176	,8	,1	, &fEM_R0UR01RZZ},	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
	{ 177	,8	,1	, &fEM_R0UR04RZZ},	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
	{ 178	,8	,1	, &fEM_A1UL12RZZ},	//(A1UL12RZZ) Время задержки АЗ от НУП ИС(сек)
	{ 179	,8	,1	, &fEM_A1UL11RZZ},	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
	{ 180	,8	,1	, &fEM_R7UI73RZZ},	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
	{ 181	,8	,1	, &fEM_A1UL13RZZ},	//(A1UL13RZZ) Максимальное время цикла
	{ 182	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 183	,8	,1	, &internal1_m205_TVuIs1},	//(internal1_m205_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
	{ 184	,8	,1	, &internal1_m205_TVuIs2},	//(internal1_m205_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
	{ 185	,8	,1	, &internal1_m205_TImVuIs},	//(internal1_m205_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
	{ 186	,8	,1	, &internal1_m205_TNupIs1},	//(internal1_m205_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
	{ 187	,8	,1	, &internal1_m205_TNupIs2},	//(internal1_m205_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
	{ 188	,8	,1	, &internal1_m205_TImNupIs},	//(internal1_m205_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
	{ 189	,8	,1	, &internal1_m205_TImAZ2UR},	//(internal1_m205_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
	{ 190	,1	,1	, &internal1_m205_fef},	//(internal1_m205_fef) fef
	{ 191	,8	,1	, &internal1_m108_tx},	//(internal1_m108_tx) tx - время накопленное сек
	{ 192	,18	,1	, &internal1_m108_y0},	//(internal1_m108_y0) y0
	{ 193	,8	,1	, &internal1_m107_tx},	//(internal1_m107_tx) tx - время накопленное сек
	{ 194	,18	,1	, &internal1_m107_y0},	//(internal1_m107_y0) y0
	{ 195	,8	,1	, &internal1_m135_tx},	//(internal1_m135_tx) tx - время накопленное сек
	{ 196	,18	,1	, &internal1_m135_y0},	//(internal1_m135_y0) y0
	{ 197	,8	,1	, &internal1_m134_tx},	//(internal1_m134_tx) tx - время накопленное сек
	{ 198	,18	,1	, &internal1_m134_y0},	//(internal1_m134_y0) y0
	{ 199	,3	,1	, &internal1_m314_sttlf},	//(internal1_m314_sttlf) sttlf - счетчик для вещественного формата
	{ 200	,8	,1	, &internal1_m225_tx},	//(internal1_m225_tx) tx - время накопленное сек
	{ 201	,18	,1	, &internal1_m225_y0},	//(internal1_m225_y0) y0
	{ 202	,8	,1	, &internal1_m285_tx},	//(internal1_m285_tx) tx - время накопленное сек
	{ 203	,18	,1	, &internal1_m285_y0},	//(internal1_m285_y0) y0
	{ 204	,3	,1	, &internal1_m33_tx},	//(internal1_m33_tx) tx - внутренний параметр
	{ 205	,8	,1	, &internal1_m148_y0},	//(internal1_m148_y0) y0
	{ 206	,8	,1	, &internal1_m146_y0},	//(internal1_m146_y0) y0
	{ 207	,8	,1	, &internal1_m92_y0},	//(internal1_m92_y0) y0
	{ 208	,8	,1	, &internal1_m90_y0},	//(internal1_m90_y0) y0
	{ 209	,1	,1	, &internal1_m159_y1},	//(internal1_m159_y1) y1 - внутренний параметр
	{ 210	,1	,1	, &internal1_m170_y1},	//(internal1_m170_y1) y1 - внутренний параметр
	{ 211	,5	,1	, &internal1_m278_q0},	//(internal1_m278_q0) q0 - внутренний параметр
	{ 212	,1	,1	, &internal1_m128_y0},	//(internal1_m128_y0) state
	{ 213	,1	,1	, &internal1_m124_y0},	//(internal1_m124_y0) state
	{ 214	,1	,1	, &internal1_m102_y1},	//(internal1_m102_y1) y1 - внутренний параметр
	{ 215	,1	,1	, &internal1_m117_y1},	//(internal1_m117_y1) y1 - внутренний параметр
	{ 216	,1	,1	, &internal1_m94_y1},	//(internal1_m94_y1) y1 - внутренний параметр
	{ 217	,1	,1	, &internal1_m105_y1},	//(internal1_m105_y1) y1 - внутренний параметр
	{ 218	,1	,1	, &internal1_m156_y1},	//(internal1_m156_y1) y1 - внутренний параметр
	{ 219	,1	,1	, &internal1_m168_y1},	//(internal1_m168_y1) y1 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="baz1.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{160,"fEM_R0UT02RZZ\0"}, 
{161,"fEM_R0UT01RZZ\0"}, 
{162,"fEM_A2UP03RZZ\0"}, 
{163,"fEM_A2UP04RZZ\0"}, 
{164,"fEM_R0UT72RZZ\0"}, 
{165,"fEM_R0UT71RZZ\0"}, 
{166,"fEM_R0UT62RZZ\0"}, 
{167,"fEM_R0UT61RZZ\0"}, 
{168,"fEM_A2UP41RZZ\0"}, 
{169,"fEM_A2UP42RZZ\0"}, 
{170,"fEM_A2UP51RZZ\0"}, 
{171,"fEM_A2UP81RZZ\0"}, 
{172,"fEM_A2UP84RZZ\0"}, 
{173,"fEM_A2UP82RZZ\0"}, 
{174,"fEM_A2UP52RZZ\0"}, 
{175,"fEM_A2UP83RZZ\0"}, 
{176,"fEM_R0UR01RZZ\0"}, 
{177,"fEM_R0UR04RZZ\0"}, 
{178,"fEM_A1UL12RZZ\0"}, 
{179,"fEM_A1UL11RZZ\0"}, 
{180,"fEM_R7UI73RZZ\0"}, 
{181,"fEM_A1UL13RZZ\0"}, 
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
	{&R0AD16LDU,1,6},	//( - , Baz1) Имитация срабатывания верхней АС I УР
	{&R0MD34LP1,1,7},	//( - , Baz1) Кнопка (Квитировать)
	{&R0AD14LDU,1,8},	//( - , Baz1) Имитация срабатывания верхней АС II УР
	{&R0VW23LDU,1,9},	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,10},	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{&R0VN64LZ1,1,11},	//( - , Baz1) ПС по мощности канал 4
	{&R0VN63LZ1,1,12},	//( - , Baz1) ПС по мощности канал 3
	{&R0VN62LZ1,1,13},	//( - , Baz1) ПС по мощности канал 2
	{&R0VN61LZ1,1,14},	//( - , Baz1) ПС по мощности канал 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_Baz1[]={  // 
	{&R0VP73LZ1,1,0},	//( - , Baz1, SBz1DU) ПС давления для РУ
	{&B0VN81LZ1,1,1},	//( - , Baz1) АЗ по АС периода разгона АЗ2
	{&A0VN81LZ1,1,2},	//( - , Baz1) АЗ по АС периода разгона АЗ1
	{&B0VN71LZ1,1,3},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
	{&A0VN71LZ1,1,4},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
	{&B0VZ71LZ1,1,5},	//( - , Baz1) Обобщенный сигнал АС по АЗ2
	{&B0EE00LZ1,1,6},	//( - , Baz1) Исправность АКНП АЗ2
	{&A0EE00LZ1,1,7},	//( - , Baz1) Исправность АКНП АЗ1
	{&A0VZ71LZ1,1,8},	//( - , Baz1) Обобщенный сигнал АС по АЗ1
	{&A0EE03LZ1,1,9},	//( - , Baz1, SBz1DU) Исправность АКНП3
	{&A0EE02LZ1,1,10},	//( - , Baz1, SBz1DU) Исправность АКНП2
	{&A0EE04LZ1,1,11},	//( - , Baz1, SBz1DU) Исправность АКНП4
	{&A0EE01LZ1,1,12},	//( - , Baz1, SBz1DU) Исправность АКНП1
	{&R0VN80LZ1,1,13},	//( - , Baz1) АЗ по АС периода разгона РУ
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
	{&R7II73LZ1,1,25},	//( - K07VDSR, Baz1) Сработала АС II УР РАД
	{&B0VT71LZ1,1,26},	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
	{&B0VT61LZ1,1,27},	//( - , Baz1) ПС по температуре в АЗ2
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
	{&R0VZ71LZ1,1,44},	//( - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
	{&R0VN79LZ1,1,45},	//( - , Baz1) АС по усредненному периоду
	{&R0VN69LZ1,1,46},	//( - , Baz1) ПС по усредненному периоду
	{&B3VZ11LZ1,1,47},	//( - , Baz1) АЗ от НУП ИС2
	{&A3VZ11LZ1,1,48},	//( - , Baz1) АЗ от НУП ИС1
	{&B3VZ31LZ1,1,49},	//( - , Baz1) АЗ от ВУ ИС2
	{&A3VZ31LZ1,1,50},	//( - , Baz1) АЗ от ВУ ИС1
	{&R0VN68LZ1,1,51},	//( - , Baz1) ПС по периоду разгона канал 4
	{&R0VN67LZ1,1,52},	//( - , Baz1) ПС по периоду разгона канал 3
	{&R0VN66LZ1,1,53},	//( - , Baz1) ПС по периоду разгона канал 2
	{&R0VN65LZ1,1,54},	//( - , Baz1) ПС по периоду разгона канал 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_Baz1[]={  // 
	{&R0VN11RZ1,8,0},	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
	{&R0VZ05UZ1,5,2},	//( - , Baz1) Индикатор причины сброса
	{&TTLBaz1,3,4},	//( - , Baz1) ttl
	{&B0CT01IZ1,8,5},	//( - , Baz1, SBz1DU) Температура АЗ2-1
	{&R0VN02RZ1,8,7},	//( - , Baz1) Уровень мощности по каналу 2
	{&R0VN01RZ1,8,9},	//( - , Baz1) Уровень мощности по каналу 1
	{&A0EP02IZ1,3,11},	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
	{&B0EP02IZ1,3,12},	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
	{&B2CP01RZ1,8,13},	//( - , Baz1) Текущее давление СБРОС РБ2
	{&A2CP01RZ1,8,15},	//( - , Baz1) Текущее давление СБРОС РБ1
	{&A0CT01IZ1,8,17},	//( - , Baz1, SBz1DU) Температура АЗ1-1
	{&R0VR02RZ1,8,19},	//( - , Baz1) Усредненная реактивность
	{&R0VN09RZ1,8,21},	//( - , Baz1) Усредненный период разгона
	{&R0VN08RZ1,8,23},	//( - , Baz1) Период разгона по каналу 4
	{&R0VN07RZ1,8,25},	//( - , Baz1) Период разгона по каналу 3
	{&R0VN06RZ1,8,27},	//( - , Baz1) Период разгона по каналу 2
	{&R0VN05RZ1,8,29},	//( - , Baz1) Период разгона по каналу 1
	{&R0VN04RZ1,8,31},	//( - , Baz1) Уровень мощности по каналу 4
	{&R0VN03RZ1,8,33},	//( - , Baz1) Уровень мощности по каналу 3
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
	{&fEM_A1UL12RZZ,8,38},	//( - , Baz1) Время задержки АЗ от НУП ИС(сек)
	{&fEM_A1UL11RZZ,8,40},	//( - , Baz1) Время задержки АЗ от ВУ ИС сек
	{&fEM_R7UI73RZZ,8,42},	//( - , Baz1) Время задержки  срабатывания АС II УР
	{&fEM_A1UL13RZZ,8,44},	//( - , Baz1) Максимальное время цикла
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
	{1,5015,&coil_MBz1A1[0],&di_MBz1A1[0],&ir_MBz1A1[0],&hr_MBz1A1[0],NULL,MBz1A1_ip1,MBz1A1_ip2,50},	 //Мастер Баз1 в AKNP1
	{1,5016,&coil_MBz1A2[0],&di_MBz1A2[0],&ir_MBz1A2[0],&hr_MBz1A2[0],NULL,MBz1A2_ip1,MBz1A2_ip2,50},	 //Мастер Баз1 в AKNP2
	{1,5017,&coil_MBz1A3[0],&di_MBz1A3[0],&ir_MBz1A3[0],&hr_MBz1A3[0],NULL,MBz1A3_ip1,MBz1A3_ip2,50},	 //Мастер Баз1 в AKNP3
	{1,5018,&coil_MBz1A4[0],&di_MBz1A4[0],&ir_MBz1A4[0],&hr_MBz1A4[0],NULL,MBz1A4_ip1,MBz1A4_ip2,50},	 //Мастер Баз1 в AKNP4

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
	{&A2IP01IZ1,3,3},
	{&B2IP01IZ1,3,9},
	{&R0DE04LZ1,3,26},
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
	{&A0EE01LS1,1,4},
	{&A0VN71LS1,1,6},
	{&R0VN75LZ1,1,2},
	{&R0VN71LZ1,1,0},
	{&R0AD04LZ1,1,14},
	{&B2IS12LDU,1,20},
	{&R0DE05LZ1,3,64},
	{&A2IS12LDU,1,18},
	{&A3IS11LDU,1,8},
	{&A3IS22LDU,1,10},
	{&R0AD03LZ1,1,12},
	{&R0AD05LZ1,1,16},
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
	{&B3IS11LDU,1,8},
	{&A0EE01LS2,1,4},
	{&B3IS22LDU,1,10},
	{&R0VN76LZ1,1,2},
	{&R0VN72LZ1,1,0},
	{&R0DE06LZ1,3,64},
	{&A0VN71LS2,1,6},
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
	{&A0VN71LS4,1,6},
	{&R0DE07LZ1,3,64},
	{&R0VN74LZ1,1,0},
	{&R0VN78LZ1,1,2},
	{&A0EE01LS4,1,4},
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
	{&R7II73LZ1,1,12},
	{&R7II71LZ1,1,8},
	{&R0VN77LZ1,1,2},
	{&B1VP81LZZ,1,24},
	{&R7II72LZ1,1,10},
	{&A1VP81LZZ,1,18},
	{&A0VN71LS3,1,6},
	{&A0EE01LS3,1,4},
	{&R0VN73LZ1,1,0},
	{&R0S01LZ1,1,14},
	{&A0VP81LZZ,1,16},
	{&R0DE08LZ1,3,64},
	{&B0VP81LZZ,1,22},
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
	{&A1VN71LZ1,1,6},
	{&A3VZ15LZ1,1,2},
	{&A3VZ13LZ1,1,0},
	{&R0AD14LZ1,1,4},
	{&R0VZ71LZ1,1,8},
	{&R0DE0ALZ1,3,38},
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
	{&R0DEB3LZ1,1,22},
	{&R0DEB4LZ1,1,24},
	{&R0DEB1LZ1,1,18},
	{&R0DEB2LZ1,1,20},
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
	setAsFloat(160,600);
	setAsFloat(161,0);
	setAsFloat(162,1.6);
	setAsFloat(163,0);
	setAsFloat(164,150);
	setAsFloat(165,200);
	setAsFloat(166,90);
	setAsFloat(167,100);
	setAsFloat(168,0.1);
	setAsFloat(169,0.13);
	setAsFloat(170,0.16);
	setAsFloat(171,0.17);
	setAsFloat(172,0.31);
	setAsFloat(173,0.2);
	setAsFloat(174,0.19);
	setAsFloat(175,0.28);
	setAsFloat(176,15);
	setAsFloat(177,10);
	setAsFloat(178,0.190);
	setAsFloat(179,0.020);
	setAsFloat(180,0.022);
	setAsFloat(181,0.019);
	setAsBool(65,1);
	setAsBool(66,1);
	setAsBool(67,1);
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
ssfloat fRM_0_2 = {0.2,0}; /* tz - время задержки сек */ 
ssint iRM_7_ = {7,0}; /* n - N-размерность массива x */ 
ssfloat fRM_0_002 = {0.002,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_005 = {0.005,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_007 = {0.007,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_01 = {0.01,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_015 = {0.015,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_02 = {0.02,0}; /* x - массив входных параметров */ 
ssfloat fRM_1_7 = {1.7,0}; /* x - массив входных параметров */ 
ssfloat fRM_10000_ = {10000,0}; /* tz - время задержки сек */ 

uspaint8 SpaEEPROMBuf[110];

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
ssint var19;
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
ssbool var100;
ssbool var101;
ssbool var102;
ssbool var103;
ssbool var104;
ssbool var105;
ssfloat var106;
ssfloat var107;
ssbool var108;
ssfloat var109;
ssfloat var110;
ssbool var111;
ssbool var112;
ssbool var113;
ssbool var114;
ssbool var115;
ssbool var116;
ssfloat var117;
sslong var118;
sslong var119;
ssbool var120;
ssbool var121;
ssbool var122;
ssbool var123;
ssbool var124;
ssbool var125;
ssbool var126;
ssbool var127;
ssbool var128;
ssfloat var129;
ssbool var130;
ssbool var131;
ssfloat var132;
ssbool var133;
ssbool var134;
sschar var135;
ssbool var136;
sschar var137;
ssbool var138;
ssbool var139;
ssbool var140;
ssbool var141;
ssbool var142;
ssbool var143;
ssbool var144;
ssbool var145;
ssbool var146;
ssbool var147;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psint  array_m314_x_1[6] = {&R0DE04LZ1,&R0DE05LZ1,&R0DE06LZ1,&R0DE0ALZ1,&R0DE08LZ1,&R0DE07LZ1};
psfloat  array_m189_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psfloat  array_m300_x_1[4] = {&R0VN02RS1,&R0VN02RS2,&R0VN02RS3,&R0VN02RS4};
psbool  array_m300_diag_1[4] = {&var24,&var25,&var26,&var27};
psbool  array_m280_x_1[17] = {&var77,&var43,&var44,&var72,&var7,&var4,&var134,&var42,&var38,&var37,&var73,&var8,&var5,&var136,&var41,&var40,&var39};
psbool  array_m16_x_1[6] = {&var82,&var73,&var8,&var5,&var88,&var136};
psbool  array_m36_x_1[6] = {&var72,&var7,&var4,&var134,&var80,&var88};
psfloat  array_m2_x_1[4] = {&R0VN01RS1,&R0VN01RS2,&R0VN01RS3,&R0VN01RS4};
psbool  array_m2_diag_1[4] = {&var24,&var25,&var26,&var27};
psbool  array_m3_x_1[3] = {&var94,&var116,&var22};
psbool  array_m12_x_1[3] = {&var93,&var23,&var95};

/* Объявление структур */
_S_noto  S_noto_223_1 = {&R0AD14LDU,&var1};
_S_and2  S_and2_226_1 = {&var1,&var3,&var2};
_S_or3  S_or3_227_1 = {&var33,&var34,&R7II73LZ1,&var3};
_S_inicn  S_inicn_205_1 = {&A3IS11LDU,&B3IS11LDU,&R0AD03LZ1,&A3IS22LDU,&B3IS22LDU,&R0AD05LZ1,&var33,&var34,&var32,&R0AD14LDU,&fEM_A1UL11RZZ,&fEM_A1UL12RZZ,&fEM_R7UI73RZZ,&fEM_A1UL13RZZ,&var4,&var5,&var6,&var7,&var8,&var9,&var10,&internal1_m205_TVuIs1,&internal1_m205_TVuIs2,&internal1_m205_TImVuIs,&internal1_m205_TNupIs1,&internal1_m205_TNupIs2,&internal1_m205_TImNupIs,&internal1_m205_TImAZ2UR,&internal1_m205_fef};
_S_zzfs  S_zzfs_108_1 = {&B1VP81LZZ,&fRM_10000_,&var11,&internal1_m108_tx,&internal1_m108_y0};
_S_zzfs  S_zzfs_107_1 = {&A1VP81LZZ,&fRM_10000_,&var12,&internal1_m107_tx,&internal1_m107_y0};
_S_zzfs  S_zzfs_135_1 = {&B0VP81LZZ,&fRM_10000_,&var13,&internal1_m135_tx,&internal1_m135_y0};
_S_zzfs  S_zzfs_134_1 = {&A0VP81LZZ,&fRM_10000_,&var14,&internal1_m134_tx,&internal1_m134_y0};
_S_or3  S_or3_322_1 = {&var18,&var17,&var16,&var15};
_S_or2  S_or2_324_1 = {&R0DEB3LZ1,&R0DEB4LZ1,&var16};
_S_or2  S_or2_318_1 = {&R0DEB1LZ1,&R0DEB2LZ1,&var17};
_S_diagndev  S_diagndev_314_1 = {array_m314_x_1,&iRM_6_,&var18,&var19,&vainSFloat,&internal1_m314_sttlf};
_S_ma  S_ma_189_1 = {array_m189_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_and2  S_and2_127_1 = {&var139,&var115,&var20};
_S_and2  S_and2_138_1 = {&var138,&var114,&var21};
_S_or2  S_or2_104_1 = {&var145,&var143,&var22};
_S_or2  S_or2_109_1 = {&var140,&var141,&var23};
_S_and2  S_and2_81_1 = {&lRM_1_,&A0EE01LS1,&var24};
_S_and2  S_and2_83_1 = {&lRM_1_,&A0EE01LS2,&var25};
_S_and2  S_and2_85_1 = {&lRM_1_,&A0EE01LS3,&var26};
_S_and2  S_and2_87_1 = {&lRM_1_,&A0EE01LS4,&var27};
_S_and2  S_and2_183_1 = {&var131,&var103,&var28};
_S_and2  S_and2_184_1 = {&var130,&var103,&var29};
_S_or2  S_or2_217_1 = {&R7II73LZ1,&var91,&var30};
_S_or2  S_or2_215_1 = {&R0AD21LDU,&R0AD14LDU,&var31};
_S_and2  S_and2_214_1 = {&var30,&var31,&var32};
_S_or2  S_or2_206_1 = {&var90,&R7II71LZ1,&var33};
_S_or2  S_or2_199_1 = {&var92,&R7II72LZ1,&var34};
_S_schl24  S_schl24_302_1 = {&A0VN71LS2,&A0VN71LS1,&A0VN71LS4,&A0VN71LS3,&var35};
_S_and2  S_and2_293_1 = {&var102,&var101,&var36};
_S_and2  S_and2_282_1 = {&var56,&var78,&var37};
_S_and2  S_and2_284_1 = {&var63,&var78,&var38};
_S_and2  S_and2_290_1 = {&R7II73LZ1,&var89,&var39};
_S_and2  S_and2_289_1 = {&var33,&var89,&var40};
_S_and2  S_and2_288_1 = {&var34,&var89,&var41};
_S_and2  S_and2_286_1 = {&var104,&var78,&var42};
_S_and2  S_and2_283_1 = {&var67,&var78,&var43};
_S_and2  S_and2_281_1 = {&var49,&var78,&var44};
_S_and2  S_and2_266_1 = {&var47,&var46,&var45};
_S_or2  S_or2_268_1 = {&R0VN75LZ1,&var128,&var46};
_S_or2  S_or2_269_1 = {&R0VN77LZ1,&var127,&var47};
_S_or2  S_or2_254_1 = {&var45,&var53,&var48};
_S_or2  S_or2_260_1 = {&var50,&var45,&var49};
_S_and2  S_and2_261_1 = {&var123,&var54,&var50};
_S_or2  S_or2_271_1 = {&R0VN78LZ1,&var125,&var51};
_S_or2  S_or2_270_1 = {&R0VN76LZ1,&var126,&var52};
_S_and2  S_and2_267_1 = {&var52,&var51,&var53};
_S_schl24  S_schl24_265_1 = {&var52,&var51,&var47,&var46,&var54};
_S_and2  S_and2_263_1 = {&var78,&var54,&var55};
_S_or2  S_or2_262_1 = {&var53,&var50,&var56};
_S_and2  S_and2_258_1 = {&var56,&var78,&var57};
_S_or2  S_or2_234_1 = {&R0VN72LZ1,&var126,&var58};
_S_and2  S_and2_249_1 = {&var67,&var78,&var59};
_S_and2  S_and2_238_1 = {&var58,&var61,&var60};
_S_or2  S_or2_235_1 = {&R0VN74LZ1,&var125,&var61};
_S_and2  S_and2_250_1 = {&var63,&var78,&var62};
_S_or2  S_or2_247_1 = {&var60,&var66,&var63};
_S_or2  S_or2_253_1 = {&var68,&var60,&var64};
_S_and2  S_and2_241_1 = {&var70,&var78,&var65};
_S_and2  S_and2_246_1 = {&var124,&var70,&var66};
_S_or2  S_or2_245_1 = {&var68,&var66,&var67};
_S_and2  S_and2_236_1 = {&var69,&var71,&var68};
_S_or2  S_or2_233_1 = {&R0VN73LZ1,&var127,&var69};
_S_schl24  S_schl24_237_1 = {&var69,&var71,&var58,&var61,&var70};
_S_or2  S_or2_232_1 = {&R0VN71LZ1,&var128,&var71};
_S_or2  S_or2_155_1 = {&var108,&var146,&var72};
_S_or2  S_or2_157_1 = {&var113,&var111,&var73};
_S_or2  S_or2_306_1 = {&var144,&var142,&var74};
_S_or2  S_or2_35_1 = {&B2IS12LDU,&A2IS12LDU,&var75};
_S_and2  S_and2_257_1 = {&var78,&var49,&var76};
_S_and2  S_and2_287_1 = {&var105,&var78,&var77};
_S_and2  S_and2_21_1 = {&var100,&var96,&var78};
_S_or2  S_or2_25_1 = {&var121,&var120,&var79};
_S_and2  S_and2_31_1 = {&var81,&var78,&var80};
_S_or3  S_or3_30_1 = {&var49,&var67,&var99,&var81};
_S_and2  S_and2_19_1 = {&var78,&var83,&var82};
_S_or3  S_or3_18_1 = {&var63,&var56,&var98,&var83};
_S_and2  S_and2_6_1 = {&var25,&var27,&var84};
_S_or2  S_or2_11_1 = {&var122,&var84,&var85};
_S_or2  S_or2_10_1 = {&var87,&var122,&var86};
_S_and2  S_and2_5_1 = {&var24,&var26,&var87};
_S_zpfs  S_zpfs_225_1 = {&var2,&fEM_R7UI73RZZ,&var88,&internal1_m225_tx,&internal1_m225_y0};
_S_zpfs  S_zpfs_285_1 = {&var36,&fRM_0_2,&var89,&internal1_m285_tx,&internal1_m285_y0};
_S_noto  S_noto_201_1 = {&R6IS67LZZ,&var90};
_S_noto  S_noto_218_1 = {&R6IS68LZZ,&var91};
_S_noto  S_noto_200_1 = {&R6IS66LZZ,&var92};
_S_noto  S_noto_137_1 = {&var13,&var93};
_S_noto  S_noto_136_1 = {&var14,&var94};
_S_noto  S_noto_112_1 = {&var11,&var95};
_S_noto  S_noto_27_1 = {&var97,&var96};
_S_ovb1  S_ovb1_33_1 = {&var75,&iRM_200_,&var97,&internal1_m33_tx};
_S_noto  S_noto_15_1 = {&var85,&var98};
_S_noto  S_noto_14_1 = {&var86,&var99};
_S_noto  S_noto_24_1 = {&R0EE02LDU,&var100};
_S_noto  S_noto_295_1 = {&R0AD16LDU,&var101};
_S_noto  S_noto_294_1 = {&R0AD04LZ1,&var102};
_S_bol  S_bol_179_1 = {&var132,&fRM_0_00001,&var103};
_S_noto  S_noto_291_1 = {&var85,&var104};
_S_noto  S_noto_292_1 = {&var86,&var105};
_S_scalzz  S_scalzz_148_1 = {&B0IT01IZ1,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var106,&internal1_m148_y0};
_S_scalzz  S_scalzz_146_1 = {&A0IT01IZ1,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var107,&internal1_m146_y0};
_S_geterr  S_geterr_150_1 = {&var107,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var108};
_S_scalzz  S_scalzz_92_1 = {&B2IP01IZ1,&iRM_3276_,&iRM_16383_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var109,&internal1_m92_y0};
_S_scalzz  S_scalzz_90_1 = {&A2IP01IZ1,&iRM_3276_,&iRM_16383_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var110,&internal1_m90_y0};
_S_drg  S_drg_159_1 = {&var106,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var111,&internal1_m159_y1};
_S_drg  S_drg_170_1 = {&var106,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var112,&internal1_m170_y1};
_S_geterr  S_geterr_152_1 = {&var106,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var113};
_S_noto  S_noto_139_1 = {&var140,&var114};
_S_noto  S_noto_126_1 = {&var145,&var115};
_S_noto  S_noto_111_1 = {&var12,&var116};
_S_srm  S_srm_300_1 = {array_m300_x_1,array_m300_diag_1,&iRM_4_,&iRM_3_,&var117,&vainSBool};
_S_rsu  S_rsu_278_1 = {&R0MD34LP1,&var119,&var118,&internal1_m278_q0};
_S_orni  S_orni_280_1 = {array_m280_x_1,&iRM_17_,&vainSBool,&var119};
_S_orn  S_orn_16_1 = {array_m16_x_1,&iRM_6_,&var120};
_S_orn  S_orn_36_1 = {array_m36_x_1,&iRM_6_,&var121};
_S_noto  S_noto_7_1 = {&var133,&var122};
_S_noto  S_noto_256_1 = {&var48,&var123};
_S_noto  S_noto_251_1 = {&var64,&var124};
_S_noto  S_noto_240_1 = {&A0EE01LS4,&var125};
_S_noto  S_noto_244_1 = {&A0EE01LS2,&var126};
_S_noto  S_noto_243_1 = {&A0EE01LS3,&var127};
_S_noto  S_noto_239_1 = {&A0EE01LS1,&var128};
_S_react  S_react_175_1 = {&var132,&var129};
_S_bol  S_bol_180_1 = {&fEM_R0UR04RZZ,&var132,&var130};
_S_bol  S_bol_178_1 = {&fEM_R0UR01RZZ,&var132,&var131};
_S_srm  S_srm_2_1 = {array_m2_x_1,array_m2_diag_1,&iRM_4_,&iRM_3_,&var132,&var133};
_S_ornc  S_ornc_3_1 = {array_m3_x_1,&iRM_3_,&var134,&var135};
_S_ornc  S_ornc_12_1 = {array_m12_x_1,&iRM_3_,&var136,&var137};
_S_tprg  S_tprg_128_1 = {&var109,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var138,&internal1_m128_y0};
_S_tprg  S_tprg_124_1 = {&var110,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var139,&internal1_m124_y0};
_S_geterr  S_geterr_101_1 = {&var109,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var140};
_S_drg  S_drg_102_1 = {&var109,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var141,&internal1_m102_y1};
_S_drg  S_drg_117_1 = {&var109,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var142,&internal1_m117_y1};
_S_drg  S_drg_94_1 = {&var110,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var143,&internal1_m94_y1};
_S_drg  S_drg_105_1 = {&var110,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var144,&internal1_m105_y1};
_S_geterr  S_geterr_98_1 = {&var110,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var145};
_S_drg  S_drg_156_1 = {&var107,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var146,&internal1_m156_y1};
_S_drg  S_drg_168_1 = {&var107,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var147,&internal1_m168_y1};


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
   var19.i=0;
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
   var100.b=0;
   var101.b=0;
   var102.b=0;
   var103.b=0;
   var104.b=0;
   var105.b=0;
   var106.f=0.0;
   var107.f=0.0;
   var108.b=0;
   var109.f=0.0;
   var110.f=0.0;
   var111.b=0;
   var112.b=0;
   var113.b=0;
   var114.b=0;
   var115.b=0;
   var116.b=0;
   var117.f=0.0;
   var118.l=0L;
   var119.l=0L;
   var120.b=0;
   var121.b=0;
   var122.b=0;
   var123.b=0;
   var124.b=0;
   var125.b=0;
   var126.b=0;
   var127.b=0;
   var128.b=0;
   var129.f=0.0;
   var130.b=0;
   var131.b=0;
   var132.f=0.0;
   var133.b=0;
   var134.b=0;
   var135.c=0;
   var136.b=0;
   var137.c=0;
   var138.b=0;
   var139.b=0;
   var140.b=0;
   var141.b=0;
   var142.b=0;
   var143.b=0;
   var144.b=0;
   var145.b=0;
   var146.b=0;
   var147.b=0;
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
  schl24(&S_schl24_302_1);
  or2(&S_or2_199_1);
  or2(&S_or2_206_1);
  or2(&S_or2_215_1);
  or2(&S_or2_217_1);
  ma(&S_ma_189_1);
  or2(&S_or2_318_1);
  or2(&S_or2_324_1);
  zzfs(&S_zzfs_134_1);
  zzfs(&S_zzfs_135_1);
  zzfs(&S_zzfs_107_1);
  zzfs(&S_zzfs_108_1);
  or3(&S_or3_227_1);
  noto(&S_noto_223_1);
  drg(&S_drg_168_1);
  drg(&S_drg_156_1);
  geterr(&S_geterr_98_1);
  drg(&S_drg_105_1);
  drg(&S_drg_94_1);
  drg(&S_drg_117_1);
  drg(&S_drg_102_1);
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
  noto(&S_noto_294_1);
  noto(&S_noto_295_1);
  noto(&S_noto_112_1);
  noto(&S_noto_136_1);
  noto(&S_noto_137_1);
  or2(&S_or2_35_1);
  or2(&S_or2_306_1);
  or2(&S_or2_157_1);
  or2(&S_or2_155_1);
  schl24(&S_schl24_237_1);
  and2(&S_and2_238_1);
  schl24(&S_schl24_265_1);
  and2(&S_and2_267_1);
  or2(&S_or2_254_1);
  and2(&S_and2_293_1);
  and2(&S_and2_214_1);
  and2(&S_and2_87_1);
  and2(&S_and2_85_1);
  and2(&S_and2_83_1);
  and2(&S_and2_81_1);
  or2(&S_or2_109_1);
  or2(&S_or2_104_1);
  and2(&S_and2_138_1);
  and2(&S_and2_127_1);
  diagndev(&S_diagndev_314_1);
  or3(&S_or3_322_1);
  inicn(&S_inicn_205_1);
  and2(&S_and2_226_1);
  ornc(&S_ornc_12_1);
  ornc(&S_ornc_3_1);
  srm(&S_srm_2_1);
  bol(&S_bol_178_1);
  bol(&S_bol_180_1);
  react(&S_react_175_1);
  noto(&S_noto_256_1);
  noto(&S_noto_7_1);
  srm(&S_srm_300_1);
  bol(&S_bol_179_1);
  ovb1(&S_ovb1_33_1);
  noto(&S_noto_27_1);
  zpfs(&S_zpfs_285_1);
  zpfs(&S_zpfs_225_1);
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
  and2(&S_and2_288_1);
  and2(&S_and2_289_1);
  and2(&S_and2_290_1);
  and2(&S_and2_184_1);
  and2(&S_and2_183_1);
  noto(&S_noto_251_1);
  noto(&S_noto_292_1);
  noto(&S_noto_14_1);
  or2(&S_or2_11_1);
  and2(&S_and2_287_1);
  and2(&S_and2_257_1);
  and2(&S_and2_246_1);
  or2(&S_or2_247_1);
  and2(&S_and2_250_1);
  or2(&S_or2_262_1);
  and2(&S_and2_284_1);
  and2(&S_and2_282_1);
  noto(&S_noto_291_1);
  noto(&S_noto_15_1);
  or3(&S_or3_18_1);
  and2(&S_and2_19_1);
  or2(&S_or2_245_1);
  and2(&S_and2_249_1);
  and2(&S_and2_258_1);
  and2(&S_and2_283_1);
  and2(&S_and2_286_1);
  orn(&S_orn_16_1);
  orni(&S_orni_280_1);
  rsu(&S_rsu_278_1);
  or3(&S_or3_30_1);
  and2(&S_and2_31_1);
  orn(&S_orn_36_1);
  or2(&S_or2_25_1);
  setData(idR0VZ05U,&var119);
  setData(idTestDiagnBaz1,&var15);
  setData(idR0DE3DLZ1,&var16);
  setData(idR0DE3CLZ1,&var17);
  setData(idTTLBaz1,&var19);
  moveData(idR0EE04LZ1,idR0EE02LDU);
  moveData(idR0EE03LZ1,idR0EE02LDU);
  moveData(idR0EE02LZ1,idR0EE02LDU);
  moveData(idR0EE01LZ1,idR0EE02LDU);
  setData(idR0AD14LZ1,&var10);
  setData(idA3VZ13LZ1,&var6);
  setData(idA3VZ15LZ1,&var9);
  setData(idA1VN71LZ1,&var35);
  setData(idB0VT71LZ1,&var73);
  setData(idB0VT61LZ1,&var112);
  setData(idB0CT01IZ1,&var106);
  setData(idR0VP73LZ1,&var74);
  setData(idR0VN11RZ1,&var117);
  setData(idR0VZ05UZ1,&var118);
  setData(idB0VN81LZ1,&var57);
  setData(idA0VN81LZ1,&var76);
  setData(idB0VN71LZ1,&var62);
  setData(idA0VN71LZ1,&var59);
  setData(idB0VZ71LZ1,&var120);
  setData(idB0EE00LZ1,&var85);
  setData(idA0EE00LZ1,&var86);
  setData(idA0VZ71LZ1,&var121);
  setData(idA0EE03LZ1,&var26);
  setData(idA0EE02LZ1,&var25);
  setData(idA0EE04LZ1,&var27);
  setData(idA0EE01LZ1,&var24);
  setData(idR0VN80LZ1,&var55);
  setData(idR0VN70LZ1,&var65);
  setData(idR0VZ71LZ1,&var79);
  setData(idR0VR02RZ1,&var129);
  setData(idR0VN79LZ1,&var29);
  setData(idR0VN69LZ1,&var28);
  setData(idB3VZ11LZ1,&var8);
  setData(idA3VZ11LZ1,&var7);
  setData(idB3VZ31LZ1,&var5);
  setData(idA3VZ31LZ1,&var4);
  setData(idR0VN09RZ1,&var132);
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
  setData(idB0VP71LZ1,&var136);
  setData(idA0VP71LZ1,&var134);
  setData(idA0EP02IZ1,&var135);
  setData(idB0EP02IZ1,&var137);
  setData(idR0ET02LZ1,&var113);
  setData(idB0VP41LZ1,&var93);
  setData(idA0VP41LZ1,&var94);
  setData(idR0ET01LZ1,&var108);
  setData(idA2VP81LZ1,&var20);
  setData(idB2VP81LZ1,&var21);
  setData(idB2VP51LZ1,&var142);
  setData(idB2CP01RZ1,&var109);
  setData(idB2VP41LZ1,&var23);
  setData(idA2VP51LZ1,&var144);
  setData(idA2CP01RZ1,&var110);
  setData(idA2VP41LZ1,&var22);
  setData(idB1VP41LZ1,&var95);
  setData(idA1VP41LZ1,&var116);
  setData(idA0VT71LZ1,&var72);
  setData(idA0VT61LZ1,&var147);
  setData(idA0CT01IZ1,&var107);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}

void MainCycle(void)
{
if ((getAsShort(idR0MW11IP1) == 2) || (getAsShort(idR0MW11IP1) == 3)) { 
     if(delay++ < 40) return;
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
