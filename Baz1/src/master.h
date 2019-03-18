#ifndef BAZ1_H
#define BAZ1_H
// Подсистема Baz1:Baz1
static char SimulOn=0;
static short CodeSub=4;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 630
static char BUFFER[630];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.52\0", 5432, "192.168.10.152\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define A0VN71LS3	 BUFFER[0]	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
#define idA0VN71LS3	 1	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
#define A0VN71LS4	 BUFFER[2]	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
#define idA0VN71LS4	 2	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
#define A1VN71LZ1	 BUFFER[4]	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	 3	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
#define A3VZ15LZ1	 BUFFER[6]	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
#define idA3VZ15LZ1	 4	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
#define A3VZ13LZ1	 BUFFER[8]	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
#define idA3VZ13LZ1	 5	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
#define R0VW13LDU	 BUFFER[10]	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 6	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	 BUFFER[12]	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 7	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R7II73LZ1	 BUFFER[14]	//(vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
#define idR7II73LZ1	 8	//(vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
#define R7II71LZ1	 BUFFER[16]	//(vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
#define idR7II71LZ1	 9	//(vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
#define R7II72LZ1	 BUFFER[18]	//(vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
#define idR7II72LZ1	 10	//(vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
#define R0AD14LZ1	 BUFFER[20]	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define idR0AD14LZ1	 11	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define R0AD21LDU	 BUFFER[22]	//( - , SBz1DU) Подключить защиту от II УР
#define idR0AD21LDU	 12	//( - , SBz1DU) Подключить защиту от II УР
#define R0AD14LDU	 BUFFER[24]	//( - , Baz1) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 13	//( - , Baz1) Имитация срабатывания верхней АС II УР
#define R0MD34LP1	 BUFFER[26]	//( - , Baz1) Кнопка (Квитировать)
#define idR0MD34LP1	 14	//( - , Baz1) Кнопка (Квитировать)
#define R0AD04LZ1	 BUFFER[28]	//(vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
#define idR0AD04LZ1	 15	//(vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
#define R0AD16LDU	 BUFFER[30]	//( - , Baz1) Имитация срабатывания верхней АС I УР
#define idR0AD16LDU	 16	//( - , Baz1) Имитация срабатывания верхней АС I УР
#define R0EE01LZ1	 BUFFER[32]	//( - , MBz1S) Питание  АКНП1  отключить
#define idR0EE01LZ1	 17	//( - , MBz1S) Питание  АКНП1  отключить
#define R6IS66LZZ	 BUFFER[34]	//(vds32:07 - K05VDSR, - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 18	//(vds32:07 - K05VDSR, - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[36]	//(vds32:07 - K06VDSR, - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 19	//(vds32:07 - K06VDSR, - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[38]	//(vds32:07 - K07VDSR, - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 20	//(vds32:07 - K07VDSR, - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define R0VN71LZ1	 BUFFER[40]	//(vds32:05 - K01VDSR, Baz1) АС по мощности канал 1
#define idR0VN71LZ1	 21	//(vds32:05 - K01VDSR, Baz1) АС по мощности канал 1
#define A0EE05LZ1	 BUFFER[42]	//( - , Baz1) Исправность сети АКНП1
#define idA0EE05LZ1	 22	//( - , Baz1) Исправность сети АКНП1
#define A0EE06LZ1	 BUFFER[44]	//( - , Baz1) Исправность сети АКНП2
#define idA0EE06LZ1	 23	//( - , Baz1) Исправность сети АКНП2
#define A0EE07LZ1	 BUFFER[46]	//( - , Baz1) Исправность сети АКНП3
#define idA0EE07LZ1	 24	//( - , Baz1) Исправность сети АКНП3
#define A0EE08LZ1	 BUFFER[48]	//( - , Baz1) Исправность сети АКНП4
#define idA0EE08LZ1	 25	//( - , Baz1) Исправность сети АКНП4
#define A0VZ71LZ1	 BUFFER[50]	//( - , Baz1) Обобщенный сигнал АС по АЗ1
#define idA0VZ71LZ1	 26	//( - , Baz1) Обобщенный сигнал АС по АЗ1
#define A0EE00LZ1	 BUFFER[52]	//( - , Baz1) Исправность АКНП АЗ1
#define idA0EE00LZ1	 27	//( - , Baz1) Исправность АКНП АЗ1
#define B0EE00LZ1	 BUFFER[54]	//( - , Baz1) Исправность АКНП АЗ2
#define idB0EE00LZ1	 28	//( - , Baz1) Исправность АКНП АЗ2
#define B0VZ71LZ1	 BUFFER[56]	//( - , Baz1) Обобщенный сигнал АС по АЗ2
#define idB0VZ71LZ1	 29	//( - , Baz1) Обобщенный сигнал АС по АЗ2
#define A0VN71LZ1	 BUFFER[58]	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
#define idA0VN71LZ1	 30	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
#define B0VN71LZ1	 BUFFER[60]	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
#define idB0VN71LZ1	 31	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
#define A0VN81LZ1	 BUFFER[62]	//( - , Baz1) АЗ по АС периода разгона АЗ1
#define idA0VN81LZ1	 32	//( - , Baz1) АЗ по АС периода разгона АЗ1
#define B0VN81LZ1	 BUFFER[64]	//( - , Baz1) АЗ по АС периода разгона АЗ2
#define idB0VN81LZ1	 33	//( - , Baz1) АЗ по АС периода разгона АЗ2
#define R0EE02LDU	 BUFFER[66]	//( - , Baz1) Питание  АКНП  отключить
#define idR0EE02LDU	 34	//( - , Baz1) Питание  АКНП  отключить
#define R0VZ05UZ1	 BUFFER[68]	//( - , Baz1) Индикатор причины сброса
#define idR0VZ05UZ1	 35	//( - , Baz1) Индикатор причины сброса
#define R0VN11RZ1	 BUFFER[73]	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
#define idR0VN11RZ1	 36	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
#define R0VP73LZ1	 BUFFER[78]	//( - , Baz1, SBz1DU) ПС давления для РУ
#define idR0VP73LZ1	 37	//( - , Baz1, SBz1DU) ПС давления для РУ
#define B0CT01IZ1	 BUFFER[80]	//( - , Baz1, SBz1DU) Температура АЗ2-1
#define idB0CT01IZ1	 38	//( - , Baz1, SBz1DU) Температура АЗ2-1
#define B0VT61LZ1	 BUFFER[85]	//( - , Baz1) ПС по температуре в АЗ2
#define idB0VT61LZ1	 39	//( - , Baz1) ПС по температуре в АЗ2
#define B0VT71LZ1	 BUFFER[87]	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
#define idB0VT71LZ1	 40	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
#define A0VN71LS1	 BUFFER[89]	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
#define idA0VN71LS1	 41	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
#define A0VN71LS2	 BUFFER[91]	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
#define idA0VN71LS2	 42	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
#define R0DE31LZ1	 BUFFER[93]	//(sbk:20 - S01SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 1
#define idR0DE31LZ1	 43	//(sbk:20 - S01SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 1
#define R0DE32LZ1	 BUFFER[95]	//(sbk:20 - S02SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 2
#define idR0DE32LZ1	 44	//(sbk:20 - S02SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 2
#define R0DE34LZ1	 BUFFER[97]	//(sbk:20 - S04SBK, DiagnBaz1) диагностика шкафа Баз1 температура меньше 43
#define idR0DE34LZ1	 45	//(sbk:20 - S04SBK, DiagnBaz1) диагностика шкафа Баз1 температура меньше 43
#define R0DE33LZ1	 BUFFER[99]	//(sbk:20 - S03SBK, DiagnBaz1) диагностика шкафа Баз1 двери
#define idR0DE33LZ1	 46	//(sbk:20 - S03SBK, DiagnBaz1) диагностика шкафа Баз1 двери
#define R0DE36LZ1	 BUFFER[101]	//(sbk:20 - S06SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 1
#define idR0DE36LZ1	 47	//(sbk:20 - S06SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 1
#define R0DE37LZ1	 BUFFER[103]	//(sbk:20 - S07SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 2
#define idR0DE37LZ1	 48	//(sbk:20 - S07SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 2
#define R0DE35LZ1	 BUFFER[105]	//(sbk:20 - S05SBK, DiagnBaz1) диагностика шкафа Баз1 температура больше 53
#define idR0DE35LZ1	 49	//(sbk:20 - S05SBK, DiagnBaz1) диагностика шкафа Баз1 температура больше 53
#define R0DE39LZ1	 BUFFER[107]	//(sbk:20 - S09SBK, DiagnBaz1) диагностика шкафа Баз1 МП24-2 место 4
#define idR0DE39LZ1	 50	//(sbk:20 - S09SBK, DiagnBaz1) диагностика шкафа Баз1 МП24-2 место 4
#define R0DE38LZ1	 BUFFER[109]	//(sbk:20 - S08SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3 место 3
#define idR0DE38LZ1	 51	//(sbk:20 - S08SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3 место 3
#define R0DEB1LZ1	 BUFFER[111]	//(sbk:20 - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
#define idR0DEB1LZ1	 52	//(sbk:20 - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
#define R0DEB2LZ1	 BUFFER[113]	//(sbk:20 - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
#define idR0DEB2LZ1	 53	//(sbk:20 - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
#define R0DEB4LZ1	 BUFFER[115]	//(sbk:20 - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
#define idR0DEB4LZ1	 54	//(sbk:20 - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
#define R0DEB3LZ1	 BUFFER[117]	//(sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
#define idR0DEB3LZ1	 55	//(sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
#define R0DE3CLZ1	 BUFFER[119]	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 5
#define idR0DE3CLZ1	 56	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 5
#define R0DE3DLZ1	 BUFFER[121]	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 6
#define idR0DE3DLZ1	 57	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 6
#define TestDiagnBaz1	 BUFFER[123]	//( - , Baz1) Неисправность от диагностики
#define idTestDiagnBaz1	 58	//( - , Baz1) Неисправность от диагностики
#define R0IS01FI0	 BUFFER[125]	//( - , MBz1S) Признак работы с имитатором
#define idR0IS01FI0	 59	//( - , MBz1S) Признак работы с имитатором
#define A0IT01FZ1	 BUFFER[128]	//( - , MBz1S) Температура АЗ1-1
#define idA0IT01FZ1	 60	//( - , MBz1S) Температура АЗ1-1
#define B0IT01FZ1	 BUFFER[131]	//( - , MBz1S) Температура АЗ2-1
#define idB0IT01FZ1	 61	//( - , MBz1S) Температура АЗ2-1
#define A2IP01FZ1	 BUFFER[134]	//( - , MBz1S) Текущее давление СБРОС РБ1
#define idA2IP01FZ1	 62	//( - , MBz1S) Текущее давление СБРОС РБ1
#define B2IP01FZ1	 BUFFER[137]	//( - , MBz1S) Текущее давление СБРОС РБ2
#define idB2IP01FZ1	 63	//( - , MBz1S) Текущее давление СБРОС РБ2
#define R0VN75LZ1	 BUFFER[140]	//(vds32:05 - K02VDSR, Baz1) АС по периоду разгона канал 1
#define idR0VN75LZ1	 64	//(vds32:05 - K02VDSR, Baz1) АС по периоду разгона канал 1
#define R0VN72LZ1	 BUFFER[142]	//(vds32:06 - K01VDSR, Baz1) АС по мощности канал 2
#define idR0VN72LZ1	 65	//(vds32:06 - K01VDSR, Baz1) АС по мощности канал 2
#define R0VN76LZ1	 BUFFER[144]	//(vds32:06 - K02VDSR, Baz1) АС по периоду разгона канал  2
#define idR0VN76LZ1	 66	//(vds32:06 - K02VDSR, Baz1) АС по периоду разгона канал  2
#define R0VN73LZ1	 BUFFER[146]	//(vds32:08 - K01VDSR, Baz1) АС по мощности канал 3
#define idR0VN73LZ1	 67	//(vds32:08 - K01VDSR, Baz1) АС по мощности канал 3
#define R0VN77LZ1	 BUFFER[148]	//(vds32:08 - K02VDSR, Baz1) АС по периоду разгона канал  3
#define idR0VN77LZ1	 68	//(vds32:08 - K02VDSR, Baz1) АС по периоду разгона канал  3
#define R0VN74LZ1	 BUFFER[150]	//(vds32:07 - K01VDSR, Baz1) АС по мощности канал 4
#define idR0VN74LZ1	 69	//(vds32:07 - K01VDSR, Baz1) АС по мощности канал 4
#define R0VN78LZ1	 BUFFER[152]	//(vds32:07 - K02VDSR, Baz1) АС по периоду разгона канал  4
#define idR0VN78LZ1	 70	//(vds32:07 - K02VDSR, Baz1) АС по периоду разгона канал  4
#define R0EE02LZ1	 BUFFER[154]	//( - , MBz1S) Питание  АКНП2  отключить
#define idR0EE02LZ1	 71	//( - , MBz1S) Питание  АКНП2  отключить
#define R0EE03LZ1	 BUFFER[156]	//( - , MBz1S) Питание  АКНП3  отключить
#define idR0EE03LZ1	 72	//( - , MBz1S) Питание  АКНП3  отключить
#define R0EE04LZ1	 BUFFER[158]	//( - , MBz1S) Питание  АКНП4  отключить
#define idR0EE04LZ1	 73	//( - , MBz1S) Питание  АКНП4  отключить
#define R0AD15LZ1	 BUFFER[160]	//( - , Baz1) Имитация АЗ от 1УР (датчик1)
#define idR0AD15LZ1	 74	//( - , Baz1) Имитация АЗ от 1УР (датчик1)
#define R0AD16LZ1	 BUFFER[162]	//( - , Baz1) Имитация АЗ от 1УР (датчик2)
#define idR0AD16LZ1	 75	//( - , Baz1) Имитация АЗ от 1УР (датчик2)
#define R0MW12IP2	 BUFFER[164]	//( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define idR0MW12IP2	 76	//( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define A2IS12LDU	 BUFFER[167]	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	 77	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define B2IS12LDU	 BUFFER[169]	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	 78	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define R0DE04LZ1	 BUFFER[171]	//(vas84:04 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
#define idR0DE04LZ1	 79	//(vas84:04 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
#define R0DE05LZ1	 BUFFER[174]	//(vds32:05 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
#define idR0DE05LZ1	 80	//(vds32:05 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
#define R0DE06LZ1	 BUFFER[177]	//(vds32:06 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
#define idR0DE06LZ1	 81	//(vds32:06 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
#define R0DE08LZ1	 BUFFER[180]	//(vds32:08 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
#define idR0DE08LZ1	 82	//(vds32:08 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
#define R0DE07LZ1	 BUFFER[183]	//(vds32:07 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
#define idR0DE07LZ1	 83	//(vds32:07 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
#define R0DE0ALZ1	 BUFFER[186]	//(fds16:0a - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
#define idR0DE0ALZ1	 84	//(fds16:0a - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
#define TTLBaz1	 BUFFER[189]	//( - , Baz1) ttl
#define idTTLBaz1	 85	//( - , Baz1) ttl
#define B0VP81LZZ	 BUFFER[192]	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	 86	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define A0VP81LZZ	 BUFFER[194]	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define idA0VP81LZZ	 87	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define R0ET02LZ1	 BUFFER[196]	//( - , Baz1) Признак наличия неисправности по температуре АЗ2
#define idR0ET02LZ1	 88	//( - , Baz1) Признак наличия неисправности по температуре АЗ2
#define B0EP02IZ1	 BUFFER[198]	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
#define idB0EP02IZ1	 89	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
#define A0EP02IZ1	 BUFFER[201]	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
#define idA0EP02IZ1	 90	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
#define A0VP71LZ1	 BUFFER[204]	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	 91	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
#define B0VP71LZ1	 BUFFER[206]	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	 92	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
#define R0VN02RS1	 BUFFER[208]	//( - , MBz1S) Уровень мощности канал 1
#define idR0VN02RS1	 93	//( - , MBz1S) Уровень мощности канал 1
#define R0VN02RS2	 BUFFER[213]	//( - , MBz1S) Уровень мощности канал 2
#define idR0VN02RS2	 94	//( - , MBz1S) Уровень мощности канал 2
#define R0VN02RS3	 BUFFER[218]	//( - , MBz1S) Уровень мощности канал 3
#define idR0VN02RS3	 95	//( - , MBz1S) Уровень мощности канал 3
#define R0VN02RS4	 BUFFER[223]	//( - , MBz1S) Уровень мощности канал 4
#define idR0VN02RS4	 96	//( - , MBz1S) Уровень мощности канал 4
#define R0VN01RS1	 BUFFER[228]	//( - , MBz1S) Период разгона канал 1
#define idR0VN01RS1	 97	//( - , MBz1S) Период разгона канал 1
#define R0VN01RS2	 BUFFER[233]	//( - , MBz1S) Период разгона канал 2
#define idR0VN01RS2	 98	//( - , MBz1S) Период разгона канал 2
#define R0VN01RS3	 BUFFER[238]	//( - , MBz1S) Период разгона канал 3
#define idR0VN01RS3	 99	//( - , MBz1S) Период разгона канал 3
#define R0VN01RS4	 BUFFER[243]	//( - , MBz1S) Период разгона канал 4
#define idR0VN01RS4	 100	//( - , MBz1S) Период разгона канал 4
#define R0VN61LS1	 BUFFER[248]	//( - , MBz1S) ПС по мощности канал 1
#define idR0VN61LS1	 101	//( - , MBz1S) ПС по мощности канал 1
#define R0VN61LS2	 BUFFER[250]	//( - , MBz1S) ПС по мощности канал 2
#define idR0VN61LS2	 102	//( - , MBz1S) ПС по мощности канал 2
#define R0VN61LS3	 BUFFER[252]	//( - , MBz1S) ПС по мощности канал 3
#define idR0VN61LS3	 103	//( - , MBz1S) ПС по мощности канал 3
#define R0VN61LS4	 BUFFER[254]	//( - , MBz1S) ПС по мощности канал 4
#define idR0VN61LS4	 104	//( - , MBz1S) ПС по мощности канал 4
#define R0VN65LS1	 BUFFER[256]	//( - , MBz1S) ПС по периоду разгона канал 1
#define idR0VN65LS1	 105	//( - , MBz1S) ПС по периоду разгона канал 1
#define R0VN65LS2	 BUFFER[258]	//( - , MBz1S) ПС по периоду разгона  канал 2
#define idR0VN65LS2	 106	//( - , MBz1S) ПС по периоду разгона  канал 2
#define A0IT01IZ1	 BUFFER[260]	//(vas84:04 - K01VASR, - ) Температура АЗ1-1
#define idA0IT01IZ1	 107	//(vas84:04 - K01VASR, - ) Температура АЗ1-1
#define A0CT01IZ1	 BUFFER[263]	//( - , Baz1, SBz1DU) Температура АЗ1-1
#define idA0CT01IZ1	 108	//( - , Baz1, SBz1DU) Температура АЗ1-1
#define A0VT61LZ1	 BUFFER[268]	//( - , Baz1) ПС по температуре в АЗ1
#define idA0VT61LZ1	 109	//( - , Baz1) ПС по температуре в АЗ1
#define A0VT71LZ1	 BUFFER[270]	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
#define idA0VT71LZ1	 110	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
#define A1VP41LZ1	 BUFFER[272]	//( - , Baz1) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	 111	//( - , Baz1) Давление СБРОС ББ1 ниже АС
#define B1VP41LZ1	 BUFFER[274]	//( - , Baz1) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	 112	//( - , Baz1) Давление СБРОС ББ2 ниже АС
#define B1VP81LZZ	 BUFFER[276]	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	 113	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define A1VP81LZZ	 BUFFER[278]	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	 114	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define A2VP41LZ1	 BUFFER[280]	//( - , Baz1) Давление СБРОС РБ1 ниже АС
#define idA2VP41LZ1	 115	//( - , Baz1) Давление СБРОС РБ1 ниже АС
#define A2CP01RZ1	 BUFFER[282]	//( - , Baz1) Текущее давление СБРОС РБ1
#define idA2CP01RZ1	 116	//( - , Baz1) Текущее давление СБРОС РБ1
#define A2VP51LZ1	 BUFFER[287]	//( - , Baz1) Давление СБРОС РБ1 ниже ПС
#define idA2VP51LZ1	 117	//( - , Baz1) Давление СБРОС РБ1 ниже ПС
#define B2VP41LZ1	 BUFFER[289]	//( - , Baz1) Давление СБРОС РБ2 ниже АС
#define idB2VP41LZ1	 118	//( - , Baz1) Давление СБРОС РБ2 ниже АС
#define B2CP01RZ1	 BUFFER[291]	//( - , Baz1) Текущее давление СБРОС РБ2
#define idB2CP01RZ1	 119	//( - , Baz1) Текущее давление СБРОС РБ2
#define B2VP51LZ1	 BUFFER[296]	//( - , Baz1) Давление СБРОС РБ2 ниже ПС
#define idB2VP51LZ1	 120	//( - , Baz1) Давление СБРОС РБ2 ниже ПС
#define B2VP81LZ1	 BUFFER[298]	//( - , Baz1) Давление СБРОС РБ2 в норме
#define idB2VP81LZ1	 121	//( - , Baz1) Давление СБРОС РБ2 в норме
#define A2VP81LZ1	 BUFFER[300]	//( - , Baz1) Давление СБРОС РБ1 в норме
#define idA2VP81LZ1	 122	//( - , Baz1) Давление СБРОС РБ1 в норме
#define A2IP01IZ1	 BUFFER[302]	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	 123	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define B2IP01IZ1	 BUFFER[305]	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	 124	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define R0ET01LZ1	 BUFFER[308]	//( - , Baz1) Признак наличия неисправности по температуре  АЗ1
#define idR0ET01LZ1	 125	//( - , Baz1) Признак наличия неисправности по температуре  АЗ1
#define B0IT01IZ1	 BUFFER[310]	//(vas84:04 - K03VASR, - ) Температура АЗ2-1
#define idB0IT01IZ1	 126	//(vas84:04 - K03VASR, - ) Температура АЗ2-1
#define A0VP41LZ1	 BUFFER[313]	//( - , Baz1) Давление АЗ1 ниже АС
#define idA0VP41LZ1	 127	//( - , Baz1) Давление АЗ1 ниже АС
#define B0VP41LZ1	 BUFFER[315]	//( - , Baz1) Давление АЗ2 ниже АС
#define idB0VP41LZ1	 128	//( - , Baz1) Давление АЗ2 ниже АС
#define B3IS11LDU	 BUFFER[317]	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define idB3IS11LDU	 129	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define A3VZ31LZ1	 BUFFER[319]	//( - , Baz1) АЗ от ВУ ИС1
#define idA3VZ31LZ1	 130	//( - , Baz1) АЗ от ВУ ИС1
#define B3VZ31LZ1	 BUFFER[321]	//( - , Baz1) АЗ от ВУ ИС2
#define idB3VZ31LZ1	 131	//( - , Baz1) АЗ от ВУ ИС2
#define R0AD05LZ1	 BUFFER[323]	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define idR0AD05LZ1	 132	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define A3VZ11LZ1	 BUFFER[325]	//( - , Baz1) АЗ от НУП ИС1
#define idA3VZ11LZ1	 133	//( - , Baz1) АЗ от НУП ИС1
#define B3VZ11LZ1	 BUFFER[327]	//( - , Baz1) АЗ от НУП ИС2
#define idB3VZ11LZ1	 134	//( - , Baz1) АЗ от НУП ИС2
#define B3IS22LDU	 BUFFER[329]	//(vds32:06 - K12VDSR, - ) Приход на НУП ИС2
#define idB3IS22LDU	 135	//(vds32:06 - K12VDSR, - ) Приход на НУП ИС2
#define R0VN69LZ1	 BUFFER[331]	//( - , Baz1) ПС по усредненному периоду
#define idR0VN69LZ1	 136	//( - , Baz1) ПС по усредненному периоду
#define R0VN79LZ1	 BUFFER[333]	//( - , Baz1) АС по усредненному периоду
#define idR0VN79LZ1	 137	//( - , Baz1) АС по усредненному периоду
#define R0VR02RZ1	 BUFFER[335]	//( - , Baz1) Усредненная реактивность
#define idR0VR02RZ1	 138	//( - , Baz1) Усредненная реактивность
#define R0VZ71LZ1	 BUFFER[340]	//(fds16:0a - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
#define idR0VZ71LZ1	 139	//(fds16:0a - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
#define R0VN70LZ1	 BUFFER[342]	//( - , Baz1) АЗ по АС мощности РУ
#define idR0VN70LZ1	 140	//( - , Baz1) АЗ по АС мощности РУ
#define R0VN80LZ1	 BUFFER[344]	//( - , Baz1) АЗ по АС периода разгона РУ
#define idR0VN80LZ1	 141	//( - , Baz1) АЗ по АС периода разгона РУ
#define A0EE01LS1	 BUFFER[346]	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define idA0EE01LS1	 142	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define A0EE01LS4	 BUFFER[348]	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define idA0EE01LS4	 143	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define A0EE01LS3	 BUFFER[350]	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define idA0EE01LS3	 144	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define A0EE01LZ1	 BUFFER[352]	//( - , Baz1, SBz1DU) Исправность АКНП1
#define idA0EE01LZ1	 145	//( - , Baz1, SBz1DU) Исправность АКНП1
#define A0EE04LZ1	 BUFFER[354]	//( - , Baz1, SBz1DU) Исправность АКНП4
#define idA0EE04LZ1	 146	//( - , Baz1, SBz1DU) Исправность АКНП4
#define A0EE02LZ1	 BUFFER[356]	//( - , Baz1, SBz1DU) Исправность АКНП2
#define idA0EE02LZ1	 147	//( - , Baz1, SBz1DU) Исправность АКНП2
#define A0EE03LZ1	 BUFFER[358]	//( - , Baz1, SBz1DU) Исправность АКНП3
#define idA0EE03LZ1	 148	//( - , Baz1, SBz1DU) Исправность АКНП3
#define A0EE01LS2	 BUFFER[360]	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define idA0EE01LS2	 149	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define R0VN65LS3	 BUFFER[362]	//( - , MBz1S) ПС по периоду разгона канал 3
#define idR0VN65LS3	 150	//( - , MBz1S) ПС по периоду разгона канал 3
#define R0VN65LS4	 BUFFER[364]	//( - , MBz1S) ПС по периоду разгона канал 4
#define idR0VN65LS4	 151	//( - , MBz1S) ПС по периоду разгона канал 4
#define R0VN01RZ1	 BUFFER[366]	//( - , Baz1) Уровень мощности по каналу 1
#define idR0VN01RZ1	 152	//( - , Baz1) Уровень мощности по каналу 1
#define R0VN02RZ1	 BUFFER[371]	//( - , Baz1) Уровень мощности по каналу 2
#define idR0VN02RZ1	 153	//( - , Baz1) Уровень мощности по каналу 2
#define R0VN03RZ1	 BUFFER[376]	//( - , Baz1) Уровень мощности по каналу 3
#define idR0VN03RZ1	 154	//( - , Baz1) Уровень мощности по каналу 3
#define R0VN04RZ1	 BUFFER[381]	//( - , Baz1) Уровень мощности по каналу 4
#define idR0VN04RZ1	 155	//( - , Baz1) Уровень мощности по каналу 4
#define R0VN05RZ1	 BUFFER[386]	//( - , Baz1) Период разгона по каналу 1
#define idR0VN05RZ1	 156	//( - , Baz1) Период разгона по каналу 1
#define R0VN06RZ1	 BUFFER[391]	//( - , Baz1) Период разгона по каналу 2
#define idR0VN06RZ1	 157	//( - , Baz1) Период разгона по каналу 2
#define R0VN07RZ1	 BUFFER[396]	//( - , Baz1) Период разгона по каналу 3
#define idR0VN07RZ1	 158	//( - , Baz1) Период разгона по каналу 3
#define R0VN08RZ1	 BUFFER[401]	//( - , Baz1) Период разгона по каналу 4
#define idR0VN08RZ1	 159	//( - , Baz1) Период разгона по каналу 4
#define R0VN61LZ1	 BUFFER[406]	//( - , Baz1) ПС по мощности канал 1
#define idR0VN61LZ1	 160	//( - , Baz1) ПС по мощности канал 1
#define R0VN62LZ1	 BUFFER[408]	//( - , Baz1) ПС по мощности канал 2
#define idR0VN62LZ1	 161	//( - , Baz1) ПС по мощности канал 2
#define R0VN63LZ1	 BUFFER[410]	//( - , Baz1) ПС по мощности канал 3
#define idR0VN63LZ1	 162	//( - , Baz1) ПС по мощности канал 3
#define R0VN64LZ1	 BUFFER[412]	//( - , Baz1) ПС по мощности канал 4
#define idR0VN64LZ1	 163	//( - , Baz1) ПС по мощности канал 4
#define R0VN65LZ1	 BUFFER[414]	//( - , Baz1) ПС по периоду разгона канал 1
#define idR0VN65LZ1	 164	//( - , Baz1) ПС по периоду разгона канал 1
#define R0VN66LZ1	 BUFFER[416]	//( - , Baz1) ПС по периоду разгона канал 2
#define idR0VN66LZ1	 165	//( - , Baz1) ПС по периоду разгона канал 2
#define R0VN67LZ1	 BUFFER[418]	//( - , Baz1) ПС по периоду разгона канал 3
#define idR0VN67LZ1	 166	//( - , Baz1) ПС по периоду разгона канал 3
#define R0VN68LZ1	 BUFFER[420]	//( - , Baz1) ПС по периоду разгона канал 4
#define idR0VN68LZ1	 167	//( - , Baz1) ПС по периоду разгона канал 4
#define R0VN09RZ1	 BUFFER[422]	//( - , Baz1, SBz1DU) Усредненный период разгона
#define idR0VN09RZ1	 168	//( - , Baz1, SBz1DU) Усредненный период разгона
#define A3IS11LDU	 BUFFER[427]	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define idA3IS11LDU	 169	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define A3IS22LDU	 BUFFER[429]	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define idA3IS22LDU	 170	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define R0AD03LZ1	 BUFFER[431]	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define idR0AD03LZ1	 171	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define fEM_R0UT02RZZ	 BUFFER[433]	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	 172	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RZZ	 BUFFER[438]	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	 173	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_A2UP03RZZ	 BUFFER[443]	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define idfEM_A2UP03RZZ	 174	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define fEM_A2UP04RZZ	 BUFFER[448]	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define idfEM_A2UP04RZZ	 175	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define fEM_R0UT72RZZ	 BUFFER[453]	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	 176	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	 BUFFER[458]	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	 177	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	 BUFFER[463]	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	 178	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT61RZZ	 BUFFER[468]	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	 179	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_A2UP41RZZ	 BUFFER[473]	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define idfEM_A2UP41RZZ	 180	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define fEM_A2UP42RZZ	 BUFFER[478]	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define idfEM_A2UP42RZZ	 181	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define fEM_A2UP51RZZ	 BUFFER[483]	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define idfEM_A2UP51RZZ	 182	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define fEM_A2UP81RZZ	 BUFFER[488]	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP81RZZ	 183	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP84RZZ	 BUFFER[493]	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP84RZZ	 184	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP82RZZ	 BUFFER[498]	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP82RZZ	 185	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP52RZZ	 BUFFER[503]	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define idfEM_A2UP52RZZ	 186	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define fEM_A2UP83RZZ	 BUFFER[508]	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP83RZZ	 187	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_R0UR01RZZ	 BUFFER[513]	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RZZ	 188	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R0UR04RZZ	 BUFFER[518]	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define idfEM_R0UR04RZZ	 189	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define fEM_A1UL12RZZ	 BUFFER[523]	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
#define idfEM_A1UL12RZZ	 190	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
#define fEM_A1UL11RZZ	 BUFFER[528]	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
#define idfEM_A1UL11RZZ	 191	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
#define fEM_R7UI73RZZ	 BUFFER[533]	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define idfEM_R7UI73RZZ	 192	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define bFirstEnterFlag	 BUFFER[538]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 193	//(bFirstEnterFlag) 
#define internal1_m254_tx	 BUFFER[540]	//(internal1_m254_tx) tx - время накопленное сек
#define idinternal1_m254_tx	 194	//(internal1_m254_tx) tx - время накопленное сек
#define internal1_m254_y0	 BUFFER[545]	//(internal1_m254_y0) y0
#define idinternal1_m254_y0	 195	//(internal1_m254_y0) y0
#define internal1_m262_tx	 BUFFER[546]	//(internal1_m262_tx) tx - время накопленное сек
#define idinternal1_m262_tx	 196	//(internal1_m262_tx) tx - время накопленное сек
#define internal1_m262_y0	 BUFFER[551]	//(internal1_m262_y0) y0
#define idinternal1_m262_y0	 197	//(internal1_m262_y0) y0
#define internal1_m325_tx	 BUFFER[552]	//(internal1_m325_tx) tx - время накопленное сек
#define idinternal1_m325_tx	 198	//(internal1_m325_tx) tx - время накопленное сек
#define internal1_m325_y0	 BUFFER[557]	//(internal1_m325_y0) y0
#define idinternal1_m325_y0	 199	//(internal1_m325_y0) y0
#define internal1_m221_tx	 BUFFER[558]	//(internal1_m221_tx) tx - время накопленное сек
#define idinternal1_m221_tx	 200	//(internal1_m221_tx) tx - время накопленное сек
#define internal1_m221_y0	 BUFFER[563]	//(internal1_m221_y0) y0
#define idinternal1_m221_y0	 201	//(internal1_m221_y0) y0
#define internal1_m220_tx	 BUFFER[564]	//(internal1_m220_tx) tx - время накопленное сек
#define idinternal1_m220_tx	 202	//(internal1_m220_tx) tx - время накопленное сек
#define internal1_m220_y0	 BUFFER[569]	//(internal1_m220_y0) y0
#define idinternal1_m220_y0	 203	//(internal1_m220_y0) y0
#define internal1_m218_tx	 BUFFER[570]	//(internal1_m218_tx) tx - время накопленное сек
#define idinternal1_m218_tx	 204	//(internal1_m218_tx) tx - время накопленное сек
#define internal1_m218_y0	 BUFFER[575]	//(internal1_m218_y0) y0
#define idinternal1_m218_y0	 205	//(internal1_m218_y0) y0
#define internal1_m216_tx	 BUFFER[576]	//(internal1_m216_tx) tx - время накопленное сек
#define idinternal1_m216_tx	 206	//(internal1_m216_tx) tx - время накопленное сек
#define internal1_m216_y0	 BUFFER[581]	//(internal1_m216_y0) y0
#define idinternal1_m216_y0	 207	//(internal1_m216_y0) y0
#define internal1_m33_tx	 BUFFER[582]	//(internal1_m33_tx) tx - внутренний параметр
#define idinternal1_m33_tx	 208	//(internal1_m33_tx) tx - внутренний параметр
#define internal1_m147_y0	 BUFFER[585]	//(internal1_m147_y0) y0
#define idinternal1_m147_y0	 209	//(internal1_m147_y0) y0
#define internal1_m146_y0	 BUFFER[590]	//(internal1_m146_y0) y0
#define idinternal1_m146_y0	 210	//(internal1_m146_y0) y0
#define internal1_m94_y0	 BUFFER[595]	//(internal1_m94_y0) y0
#define idinternal1_m94_y0	 211	//(internal1_m94_y0) y0
#define internal1_m93_y0	 BUFFER[600]	//(internal1_m93_y0) y0
#define idinternal1_m93_y0	 212	//(internal1_m93_y0) y0
#define internal1_m161_y1	 BUFFER[605]	//(internal1_m161_y1) y1 - внутренний параметр
#define idinternal1_m161_y1	 213	//(internal1_m161_y1) y1 - внутренний параметр
#define internal1_m175_y1	 BUFFER[607]	//(internal1_m175_y1) y1 - внутренний параметр
#define idinternal1_m175_y1	 214	//(internal1_m175_y1) y1 - внутренний параметр
#define internal1_m318_q0	 BUFFER[609]	//(internal1_m318_q0) q0 - внутренний параметр
#define idinternal1_m318_q0	 215	//(internal1_m318_q0) q0 - внутренний параметр
#define internal1_m129_y0	 BUFFER[614]	//(internal1_m129_y0) state
#define idinternal1_m129_y0	 216	//(internal1_m129_y0) state
#define internal1_m125_y0	 BUFFER[616]	//(internal1_m125_y0) state
#define idinternal1_m125_y0	 217	//(internal1_m125_y0) state
#define internal1_m109_y1	 BUFFER[618]	//(internal1_m109_y1) y1 - внутренний параметр
#define idinternal1_m109_y1	 218	//(internal1_m109_y1) y1 - внутренний параметр
#define internal1_m118_y1	 BUFFER[620]	//(internal1_m118_y1) y1 - внутренний параметр
#define idinternal1_m118_y1	 219	//(internal1_m118_y1) y1 - внутренний параметр
#define internal1_m97_y1	 BUFFER[622]	//(internal1_m97_y1) y1 - внутренний параметр
#define idinternal1_m97_y1	 220	//(internal1_m97_y1) y1 - внутренний параметр
#define internal1_m107_y1	 BUFFER[624]	//(internal1_m107_y1) y1 - внутренний параметр
#define idinternal1_m107_y1	 221	//(internal1_m107_y1) y1 - внутренний параметр
#define internal1_m159_y1	 BUFFER[626]	//(internal1_m159_y1) y1 - внутренний параметр
#define idinternal1_m159_y1	 222	//(internal1_m159_y1) y1 - внутренний параметр
#define internal1_m173_y1	 BUFFER[628]	//(internal1_m173_y1) y1 - внутренний параметр
#define idinternal1_m173_y1	 223	//(internal1_m173_y1) y1 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &A0VN71LS3},	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
	{ 2	,1	,1	, &A0VN71LS4},	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
	{ 3	,1	,1	, &A1VN71LZ1},	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
	{ 4	,1	,1	, &A3VZ15LZ1},	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
	{ 5	,1	,1	, &A3VZ13LZ1},	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
	{ 6	,1	,1	, &R0VW13LDU},	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 7	,1	,1	, &R0VW23LDU},	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 8	,1	,1	, &R7II73LZ1},	//(vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
	{ 9	,1	,1	, &R7II71LZ1},	//(vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
	{ 10	,1	,1	, &R7II72LZ1},	//(vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
	{ 11	,1	,1	, &R0AD14LZ1},	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
	{ 12	,1	,1	, &R0AD21LDU},	//( - , SBz1DU) Подключить защиту от II УР
	{ 13	,1	,1	, &R0AD14LDU},	//( - , Baz1) Имитация срабатывания верхней АС II УР
	{ 14	,1	,1	, &R0MD34LP1},	//( - , Baz1) Кнопка (Квитировать)
	{ 15	,1	,1	, &R0AD04LZ1},	//(vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
	{ 16	,1	,1	, &R0AD16LDU},	//( - , Baz1) Имитация срабатывания верхней АС I УР
	{ 17	,1	,1	, &R0EE01LZ1},	//( - , MBz1S) Питание  АКНП1  отключить
	{ 18	,1	,1	, &R6IS66LZZ},	//(vds32:07 - K05VDSR, - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 19	,1	,1	, &R6IS67LZZ},	//(vds32:07 - K06VDSR, - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 20	,1	,1	, &R6IS68LZZ},	//(vds32:07 - K07VDSR, - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 21	,1	,1	, &R0VN71LZ1},	//(vds32:05 - K01VDSR, Baz1) АС по мощности канал 1
	{ 22	,1	,1	, &A0EE05LZ1},	//( - , Baz1) Исправность сети АКНП1
	{ 23	,1	,1	, &A0EE06LZ1},	//( - , Baz1) Исправность сети АКНП2
	{ 24	,1	,1	, &A0EE07LZ1},	//( - , Baz1) Исправность сети АКНП3
	{ 25	,1	,1	, &A0EE08LZ1},	//( - , Baz1) Исправность сети АКНП4
	{ 26	,1	,1	, &A0VZ71LZ1},	//( - , Baz1) Обобщенный сигнал АС по АЗ1
	{ 27	,1	,1	, &A0EE00LZ1},	//( - , Baz1) Исправность АКНП АЗ1
	{ 28	,1	,1	, &B0EE00LZ1},	//( - , Baz1) Исправность АКНП АЗ2
	{ 29	,1	,1	, &B0VZ71LZ1},	//( - , Baz1) Обобщенный сигнал АС по АЗ2
	{ 30	,1	,1	, &A0VN71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
	{ 31	,1	,1	, &B0VN71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
	{ 32	,1	,1	, &A0VN81LZ1},	//( - , Baz1) АЗ по АС периода разгона АЗ1
	{ 33	,1	,1	, &B0VN81LZ1},	//( - , Baz1) АЗ по АС периода разгона АЗ2
	{ 34	,1	,1	, &R0EE02LDU},	//( - , Baz1) Питание  АКНП  отключить
	{ 35	,5	,1	, &R0VZ05UZ1},	//( - , Baz1) Индикатор причины сброса
	{ 36	,8	,1	, &R0VN11RZ1},	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
	{ 37	,1	,1	, &R0VP73LZ1},	//( - , Baz1, SBz1DU) ПС давления для РУ
	{ 38	,8	,1	, &B0CT01IZ1},	//( - , Baz1, SBz1DU) Температура АЗ2-1
	{ 39	,1	,1	, &B0VT61LZ1},	//( - , Baz1) ПС по температуре в АЗ2
	{ 40	,1	,1	, &B0VT71LZ1},	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
	{ 41	,1	,1	, &A0VN71LS1},	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
	{ 42	,1	,1	, &A0VN71LS2},	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
	{ 43	,1	,1	, &R0DE31LZ1},	//(sbk:20 - S01SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 1
	{ 44	,1	,1	, &R0DE32LZ1},	//(sbk:20 - S02SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 2
	{ 45	,1	,1	, &R0DE34LZ1},	//(sbk:20 - S04SBK, DiagnBaz1) диагностика шкафа Баз1 температура меньше 43
	{ 46	,1	,1	, &R0DE33LZ1},	//(sbk:20 - S03SBK, DiagnBaz1) диагностика шкафа Баз1 двери
	{ 47	,1	,1	, &R0DE36LZ1},	//(sbk:20 - S06SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 1
	{ 48	,1	,1	, &R0DE37LZ1},	//(sbk:20 - S07SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 2
	{ 49	,1	,1	, &R0DE35LZ1},	//(sbk:20 - S05SBK, DiagnBaz1) диагностика шкафа Баз1 температура больше 53
	{ 50	,1	,1	, &R0DE39LZ1},	//(sbk:20 - S09SBK, DiagnBaz1) диагностика шкафа Баз1 МП24-2 место 4
	{ 51	,1	,1	, &R0DE38LZ1},	//(sbk:20 - S08SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3 место 3
	{ 52	,1	,1	, &R0DEB1LZ1},	//(sbk:20 - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
	{ 53	,1	,1	, &R0DEB2LZ1},	//(sbk:20 - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
	{ 54	,1	,1	, &R0DEB4LZ1},	//(sbk:20 - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
	{ 55	,1	,1	, &R0DEB3LZ1},	//(sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
	{ 56	,1	,1	, &R0DE3CLZ1},	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 5
	{ 57	,1	,1	, &R0DE3DLZ1},	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 6
	{ 58	,1	,1	, &TestDiagnBaz1},	//( - , Baz1) Неисправность от диагностики
	{ 59	,3	,1	, &R0IS01FI0},	//( - , MBz1S) Признак работы с имитатором
	{ 60	,3	,1	, &A0IT01FZ1},	//( - , MBz1S) Температура АЗ1-1
	{ 61	,3	,1	, &B0IT01FZ1},	//( - , MBz1S) Температура АЗ2-1
	{ 62	,3	,1	, &A2IP01FZ1},	//( - , MBz1S) Текущее давление СБРОС РБ1
	{ 63	,3	,1	, &B2IP01FZ1},	//( - , MBz1S) Текущее давление СБРОС РБ2
	{ 64	,1	,1	, &R0VN75LZ1},	//(vds32:05 - K02VDSR, Baz1) АС по периоду разгона канал 1
	{ 65	,1	,1	, &R0VN72LZ1},	//(vds32:06 - K01VDSR, Baz1) АС по мощности канал 2
	{ 66	,1	,1	, &R0VN76LZ1},	//(vds32:06 - K02VDSR, Baz1) АС по периоду разгона канал  2
	{ 67	,1	,1	, &R0VN73LZ1},	//(vds32:08 - K01VDSR, Baz1) АС по мощности канал 3
	{ 68	,1	,1	, &R0VN77LZ1},	//(vds32:08 - K02VDSR, Baz1) АС по периоду разгона канал  3
	{ 69	,1	,1	, &R0VN74LZ1},	//(vds32:07 - K01VDSR, Baz1) АС по мощности канал 4
	{ 70	,1	,1	, &R0VN78LZ1},	//(vds32:07 - K02VDSR, Baz1) АС по периоду разгона канал  4
	{ 71	,1	,1	, &R0EE02LZ1},	//( - , MBz1S) Питание  АКНП2  отключить
	{ 72	,1	,1	, &R0EE03LZ1},	//( - , MBz1S) Питание  АКНП3  отключить
	{ 73	,1	,1	, &R0EE04LZ1},	//( - , MBz1S) Питание  АКНП4  отключить
	{ 74	,1	,1	, &R0AD15LZ1},	//( - , Baz1) Имитация АЗ от 1УР (датчик1)
	{ 75	,1	,1	, &R0AD16LZ1},	//( - , Baz1) Имитация АЗ от 1УР (датчик2)
	{ 76	,3	,1	, &R0MW12IP2},	//( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{ 77	,1	,1	, &A2IS12LDU},	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
	{ 78	,1	,1	, &B2IS12LDU},	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
	{ 79	,3	,1	, &R0DE04LZ1},	//(vas84:04 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
	{ 80	,3	,1	, &R0DE05LZ1},	//(vds32:05 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
	{ 81	,3	,1	, &R0DE06LZ1},	//(vds32:06 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
	{ 82	,3	,1	, &R0DE08LZ1},	//(vds32:08 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
	{ 83	,3	,1	, &R0DE07LZ1},	//(vds32:07 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
	{ 84	,3	,1	, &R0DE0ALZ1},	//(fds16:0a - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
	{ 85	,3	,1	, &TTLBaz1},	//( - , Baz1) ttl
	{ 86	,1	,1	, &B0VP81LZZ},	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
	{ 87	,1	,1	, &A0VP81LZZ},	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
	{ 88	,1	,1	, &R0ET02LZ1},	//( - , Baz1) Признак наличия неисправности по температуре АЗ2
	{ 89	,3	,1	, &B0EP02IZ1},	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
	{ 90	,3	,1	, &A0EP02IZ1},	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
	{ 91	,1	,1	, &A0VP71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
	{ 92	,1	,1	, &B0VP71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
	{ 93	,8	,1	, &R0VN02RS1},	//( - , MBz1S) Уровень мощности канал 1
	{ 94	,8	,1	, &R0VN02RS2},	//( - , MBz1S) Уровень мощности канал 2
	{ 95	,8	,1	, &R0VN02RS3},	//( - , MBz1S) Уровень мощности канал 3
	{ 96	,8	,1	, &R0VN02RS4},	//( - , MBz1S) Уровень мощности канал 4
	{ 97	,8	,1	, &R0VN01RS1},	//( - , MBz1S) Период разгона канал 1
	{ 98	,8	,1	, &R0VN01RS2},	//( - , MBz1S) Период разгона канал 2
	{ 99	,8	,1	, &R0VN01RS3},	//( - , MBz1S) Период разгона канал 3
	{ 100	,8	,1	, &R0VN01RS4},	//( - , MBz1S) Период разгона канал 4
	{ 101	,1	,1	, &R0VN61LS1},	//( - , MBz1S) ПС по мощности канал 1
	{ 102	,1	,1	, &R0VN61LS2},	//( - , MBz1S) ПС по мощности канал 2
	{ 103	,1	,1	, &R0VN61LS3},	//( - , MBz1S) ПС по мощности канал 3
	{ 104	,1	,1	, &R0VN61LS4},	//( - , MBz1S) ПС по мощности канал 4
	{ 105	,1	,1	, &R0VN65LS1},	//( - , MBz1S) ПС по периоду разгона канал 1
	{ 106	,1	,1	, &R0VN65LS2},	//( - , MBz1S) ПС по периоду разгона  канал 2
	{ 107	,3	,1	, &A0IT01IZ1},	//(vas84:04 - K01VASR, - ) Температура АЗ1-1
	{ 108	,8	,1	, &A0CT01IZ1},	//( - , Baz1, SBz1DU) Температура АЗ1-1
	{ 109	,1	,1	, &A0VT61LZ1},	//( - , Baz1) ПС по температуре в АЗ1
	{ 110	,1	,1	, &A0VT71LZ1},	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
	{ 111	,1	,1	, &A1VP41LZ1},	//( - , Baz1) Давление СБРОС ББ1 ниже АС
	{ 112	,1	,1	, &B1VP41LZ1},	//( - , Baz1) Давление СБРОС ББ2 ниже АС
	{ 113	,1	,1	, &B1VP81LZZ},	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
	{ 114	,1	,1	, &A1VP81LZZ},	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
	{ 115	,1	,1	, &A2VP41LZ1},	//( - , Baz1) Давление СБРОС РБ1 ниже АС
	{ 116	,8	,1	, &A2CP01RZ1},	//( - , Baz1) Текущее давление СБРОС РБ1
	{ 117	,1	,1	, &A2VP51LZ1},	//( - , Baz1) Давление СБРОС РБ1 ниже ПС
	{ 118	,1	,1	, &B2VP41LZ1},	//( - , Baz1) Давление СБРОС РБ2 ниже АС
	{ 119	,8	,1	, &B2CP01RZ1},	//( - , Baz1) Текущее давление СБРОС РБ2
	{ 120	,1	,1	, &B2VP51LZ1},	//( - , Baz1) Давление СБРОС РБ2 ниже ПС
	{ 121	,1	,1	, &B2VP81LZ1},	//( - , Baz1) Давление СБРОС РБ2 в норме
	{ 122	,1	,1	, &A2VP81LZ1},	//( - , Baz1) Давление СБРОС РБ1 в норме
	{ 123	,3	,1	, &A2IP01IZ1},	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
	{ 124	,3	,1	, &B2IP01IZ1},	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
	{ 125	,1	,1	, &R0ET01LZ1},	//( - , Baz1) Признак наличия неисправности по температуре  АЗ1
	{ 126	,3	,1	, &B0IT01IZ1},	//(vas84:04 - K03VASR, - ) Температура АЗ2-1
	{ 127	,1	,1	, &A0VP41LZ1},	//( - , Baz1) Давление АЗ1 ниже АС
	{ 128	,1	,1	, &B0VP41LZ1},	//( - , Baz1) Давление АЗ2 ниже АС
	{ 129	,1	,1	, &B3IS11LDU},	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
	{ 130	,1	,1	, &A3VZ31LZ1},	//( - , Baz1) АЗ от ВУ ИС1
	{ 131	,1	,1	, &B3VZ31LZ1},	//( - , Baz1) АЗ от ВУ ИС2
	{ 132	,1	,1	, &R0AD05LZ1},	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
	{ 133	,1	,1	, &A3VZ11LZ1},	//( - , Baz1) АЗ от НУП ИС1
	{ 134	,1	,1	, &B3VZ11LZ1},	//( - , Baz1) АЗ от НУП ИС2
	{ 135	,1	,1	, &B3IS22LDU},	//(vds32:06 - K12VDSR, - ) Приход на НУП ИС2
	{ 136	,1	,1	, &R0VN69LZ1},	//( - , Baz1) ПС по усредненному периоду
	{ 137	,1	,1	, &R0VN79LZ1},	//( - , Baz1) АС по усредненному периоду
	{ 138	,8	,1	, &R0VR02RZ1},	//( - , Baz1) Усредненная реактивность
	{ 139	,1	,1	, &R0VZ71LZ1},	//(fds16:0a - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
	{ 140	,1	,1	, &R0VN70LZ1},	//( - , Baz1) АЗ по АС мощности РУ
	{ 141	,1	,1	, &R0VN80LZ1},	//( - , Baz1) АЗ по АС периода разгона РУ
	{ 142	,1	,1	, &A0EE01LS1},	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
	{ 143	,1	,1	, &A0EE01LS4},	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
	{ 144	,1	,1	, &A0EE01LS3},	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
	{ 145	,1	,1	, &A0EE01LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП1
	{ 146	,1	,1	, &A0EE04LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП4
	{ 147	,1	,1	, &A0EE02LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП2
	{ 148	,1	,1	, &A0EE03LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП3
	{ 149	,1	,1	, &A0EE01LS2},	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
	{ 150	,1	,1	, &R0VN65LS3},	//( - , MBz1S) ПС по периоду разгона канал 3
	{ 151	,1	,1	, &R0VN65LS4},	//( - , MBz1S) ПС по периоду разгона канал 4
	{ 152	,8	,1	, &R0VN01RZ1},	//( - , Baz1) Уровень мощности по каналу 1
	{ 153	,8	,1	, &R0VN02RZ1},	//( - , Baz1) Уровень мощности по каналу 2
	{ 154	,8	,1	, &R0VN03RZ1},	//( - , Baz1) Уровень мощности по каналу 3
	{ 155	,8	,1	, &R0VN04RZ1},	//( - , Baz1) Уровень мощности по каналу 4
	{ 156	,8	,1	, &R0VN05RZ1},	//( - , Baz1) Период разгона по каналу 1
	{ 157	,8	,1	, &R0VN06RZ1},	//( - , Baz1) Период разгона по каналу 2
	{ 158	,8	,1	, &R0VN07RZ1},	//( - , Baz1) Период разгона по каналу 3
	{ 159	,8	,1	, &R0VN08RZ1},	//( - , Baz1) Период разгона по каналу 4
	{ 160	,1	,1	, &R0VN61LZ1},	//( - , Baz1) ПС по мощности канал 1
	{ 161	,1	,1	, &R0VN62LZ1},	//( - , Baz1) ПС по мощности канал 2
	{ 162	,1	,1	, &R0VN63LZ1},	//( - , Baz1) ПС по мощности канал 3
	{ 163	,1	,1	, &R0VN64LZ1},	//( - , Baz1) ПС по мощности канал 4
	{ 164	,1	,1	, &R0VN65LZ1},	//( - , Baz1) ПС по периоду разгона канал 1
	{ 165	,1	,1	, &R0VN66LZ1},	//( - , Baz1) ПС по периоду разгона канал 2
	{ 166	,1	,1	, &R0VN67LZ1},	//( - , Baz1) ПС по периоду разгона канал 3
	{ 167	,1	,1	, &R0VN68LZ1},	//( - , Baz1) ПС по периоду разгона канал 4
	{ 168	,8	,1	, &R0VN09RZ1},	//( - , Baz1, SBz1DU) Усредненный период разгона
	{ 169	,1	,1	, &A3IS11LDU},	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
	{ 170	,1	,1	, &A3IS22LDU},	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
	{ 171	,1	,1	, &R0AD03LZ1},	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
	{ 172	,8	,1	, &fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{ 173	,8	,1	, &fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{ 174	,8	,1	, &fEM_A2UP03RZZ},	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{ 175	,8	,1	, &fEM_A2UP04RZZ},	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{ 176	,8	,1	, &fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{ 177	,8	,1	, &fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{ 178	,8	,1	, &fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{ 179	,8	,1	, &fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{ 180	,8	,1	, &fEM_A2UP41RZZ},	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{ 181	,8	,1	, &fEM_A2UP42RZZ},	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{ 182	,8	,1	, &fEM_A2UP51RZZ},	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{ 183	,8	,1	, &fEM_A2UP81RZZ},	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{ 184	,8	,1	, &fEM_A2UP84RZZ},	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{ 185	,8	,1	, &fEM_A2UP82RZZ},	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{ 186	,8	,1	, &fEM_A2UP52RZZ},	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{ 187	,8	,1	, &fEM_A2UP83RZZ},	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{ 188	,8	,1	, &fEM_R0UR01RZZ},	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
	{ 189	,8	,1	, &fEM_R0UR04RZZ},	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
	{ 190	,8	,1	, &fEM_A1UL12RZZ},	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
	{ 191	,8	,1	, &fEM_A1UL11RZZ},	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
	{ 192	,8	,1	, &fEM_R7UI73RZZ},	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
	{ 193	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 194	,8	,1	, &internal1_m254_tx},	//(internal1_m254_tx) tx - время накопленное сек
	{ 195	,18	,1	, &internal1_m254_y0},	//(internal1_m254_y0) y0
	{ 196	,8	,1	, &internal1_m262_tx},	//(internal1_m262_tx) tx - время накопленное сек
	{ 197	,18	,1	, &internal1_m262_y0},	//(internal1_m262_y0) y0
	{ 198	,8	,1	, &internal1_m325_tx},	//(internal1_m325_tx) tx - время накопленное сек
	{ 199	,18	,1	, &internal1_m325_y0},	//(internal1_m325_y0) y0
	{ 200	,8	,1	, &internal1_m221_tx},	//(internal1_m221_tx) tx - время накопленное сек
	{ 201	,18	,1	, &internal1_m221_y0},	//(internal1_m221_y0) y0
	{ 202	,8	,1	, &internal1_m220_tx},	//(internal1_m220_tx) tx - время накопленное сек
	{ 203	,18	,1	, &internal1_m220_y0},	//(internal1_m220_y0) y0
	{ 204	,8	,1	, &internal1_m218_tx},	//(internal1_m218_tx) tx - время накопленное сек
	{ 205	,18	,1	, &internal1_m218_y0},	//(internal1_m218_y0) y0
	{ 206	,8	,1	, &internal1_m216_tx},	//(internal1_m216_tx) tx - время накопленное сек
	{ 207	,18	,1	, &internal1_m216_y0},	//(internal1_m216_y0) y0
	{ 208	,3	,1	, &internal1_m33_tx},	//(internal1_m33_tx) tx - внутренний параметр
	{ 209	,8	,1	, &internal1_m147_y0},	//(internal1_m147_y0) y0
	{ 210	,8	,1	, &internal1_m146_y0},	//(internal1_m146_y0) y0
	{ 211	,8	,1	, &internal1_m94_y0},	//(internal1_m94_y0) y0
	{ 212	,8	,1	, &internal1_m93_y0},	//(internal1_m93_y0) y0
	{ 213	,1	,1	, &internal1_m161_y1},	//(internal1_m161_y1) y1 - внутренний параметр
	{ 214	,1	,1	, &internal1_m175_y1},	//(internal1_m175_y1) y1 - внутренний параметр
	{ 215	,5	,1	, &internal1_m318_q0},	//(internal1_m318_q0) q0 - внутренний параметр
	{ 216	,1	,1	, &internal1_m129_y0},	//(internal1_m129_y0) state
	{ 217	,1	,1	, &internal1_m125_y0},	//(internal1_m125_y0) state
	{ 218	,1	,1	, &internal1_m109_y1},	//(internal1_m109_y1) y1 - внутренний параметр
	{ 219	,1	,1	, &internal1_m118_y1},	//(internal1_m118_y1) y1 - внутренний параметр
	{ 220	,1	,1	, &internal1_m97_y1},	//(internal1_m97_y1) y1 - внутренний параметр
	{ 221	,1	,1	, &internal1_m107_y1},	//(internal1_m107_y1) y1 - внутренний параметр
	{ 222	,1	,1	, &internal1_m159_y1},	//(internal1_m159_y1) y1 - внутренний параметр
	{ 223	,1	,1	, &internal1_m173_y1},	//(internal1_m173_y1) y1 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="baz1.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{172,"fEM_R0UT02RZZ\0"}, 
{173,"fEM_R0UT01RZZ\0"}, 
{174,"fEM_A2UP03RZZ\0"}, 
{175,"fEM_A2UP04RZZ\0"}, 
{176,"fEM_R0UT72RZZ\0"}, 
{177,"fEM_R0UT71RZZ\0"}, 
{178,"fEM_R0UT62RZZ\0"}, 
{179,"fEM_R0UT61RZZ\0"}, 
{180,"fEM_A2UP41RZZ\0"}, 
{181,"fEM_A2UP42RZZ\0"}, 
{182,"fEM_A2UP51RZZ\0"}, 
{183,"fEM_A2UP81RZZ\0"}, 
{184,"fEM_A2UP84RZZ\0"}, 
{185,"fEM_A2UP82RZZ\0"}, 
{186,"fEM_A2UP52RZZ\0"}, 
{187,"fEM_A2UP83RZZ\0"}, 
{188,"fEM_R0UR01RZZ\0"}, 
{189,"fEM_R0UR04RZZ\0"}, 
{190,"fEM_A1UL12RZZ\0"}, 
{191,"fEM_A1UL11RZZ\0"}, 
{192,"fEM_R7UI73RZZ\0"}, 
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
	{&R0AD16LZ1,1,15},	//( - , Baz1) Имитация АЗ от 1УР (датчик2)
	{&R0AD15LZ1,1,16},	//( - , Baz1) Имитация АЗ от 1УР (датчик1)
	{&R0VN78LZ1,1,17},	//( - K02VDSR, Baz1) АС по периоду разгона канал  4
	{&R0VN74LZ1,1,18},	//( - K01VDSR, Baz1) АС по мощности канал 4
	{&R0VN77LZ1,1,19},	//( - K02VDSR, Baz1) АС по периоду разгона канал  3
	{&R0VN73LZ1,1,20},	//( - K01VDSR, Baz1) АС по мощности канал 3
	{&R0VN76LZ1,1,21},	//( - K02VDSR, Baz1) АС по периоду разгона канал  2
	{&R0VN72LZ1,1,22},	//( - K01VDSR, Baz1) АС по мощности канал 2
	{&R0VN75LZ1,1,23},	//( - K02VDSR, Baz1) АС по периоду разгона канал 1
	{&R0VN71LZ1,1,24},	//( - K01VDSR, Baz1) АС по мощности канал 1
	{&R7II72LZ1,1,25},	//( - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
	{&R7II71LZ1,1,26},	//( - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
	{&R7II73LZ1,1,27},	//( - K07VDSR, Baz1) Сработала АС II УР РАД
	{&B0VT71LZ1,1,28},	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
	{&B0VT61LZ1,1,29},	//( - , Baz1) ПС по температуре в АЗ2
	{&B0VP71LZ1,1,30},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
	{&A0VP71LZ1,1,31},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
	{&R0ET02LZ1,1,32},	//( - , Baz1) Признак наличия неисправности по температуре АЗ2
	{&B0VP41LZ1,1,33},	//( - , Baz1) Давление АЗ2 ниже АС
	{&A0VP41LZ1,1,34},	//( - , Baz1) Давление АЗ1 ниже АС
	{&R0ET01LZ1,1,35},	//( - , Baz1) Признак наличия неисправности по температуре  АЗ1
	{&A2VP81LZ1,1,36},	//( - , Baz1) Давление СБРОС РБ1 в норме
	{&B2VP81LZ1,1,37},	//( - , Baz1) Давление СБРОС РБ2 в норме
	{&B2VP51LZ1,1,38},	//( - , Baz1) Давление СБРОС РБ2 ниже ПС
	{&B2VP41LZ1,1,39},	//( - , Baz1) Давление СБРОС РБ2 ниже АС
	{&A2VP51LZ1,1,40},	//( - , Baz1) Давление СБРОС РБ1 ниже ПС
	{&A2VP41LZ1,1,41},	//( - , Baz1) Давление СБРОС РБ1 ниже АС
	{&B1VP41LZ1,1,42},	//( - , Baz1) Давление СБРОС ББ2 ниже АС
	{&A1VP41LZ1,1,43},	//( - , Baz1) Давление СБРОС ББ1 ниже АС
	{&A0VT71LZ1,1,44},	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
	{&A0VT61LZ1,1,45},	//( - , Baz1) ПС по температуре в АЗ1
	{&R0VZ71LZ1,1,46},	//( - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
	{&R0VN79LZ1,1,47},	//( - , Baz1) АС по усредненному периоду
	{&R0VN69LZ1,1,48},	//( - , Baz1) ПС по усредненному периоду
	{&B3VZ11LZ1,1,49},	//( - , Baz1) АЗ от НУП ИС2
	{&A3VZ11LZ1,1,50},	//( - , Baz1) АЗ от НУП ИС1
	{&B3VZ31LZ1,1,51},	//( - , Baz1) АЗ от ВУ ИС2
	{&A3VZ31LZ1,1,52},	//( - , Baz1) АЗ от ВУ ИС1
	{&R0VN68LZ1,1,53},	//( - , Baz1) ПС по периоду разгона канал 4
	{&R0VN67LZ1,1,54},	//( - , Baz1) ПС по периоду разгона канал 3
	{&R0VN66LZ1,1,55},	//( - , Baz1) ПС по периоду разгона канал 2
	{&R0VN65LZ1,1,56},	//( - , Baz1) ПС по периоду разгона канал 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_Baz1[]={  // 
	{&B0CT01IZ1,8,0},	//( - , Baz1, SBz1DU) Температура АЗ2-1
	{&R0VN11RZ1,8,2},	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
	{&R0VZ05UZ1,5,4},	//( - , Baz1) Индикатор причины сброса
	{&TTLBaz1,3,6},	//( - , Baz1) ttl
	{&R0VN02RZ1,8,7},	//( - , Baz1) Уровень мощности по каналу 2
	{&R0VN01RZ1,8,9},	//( - , Baz1) Уровень мощности по каналу 1
	{&A0EP02IZ1,3,11},	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
	{&B0EP02IZ1,3,12},	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
	{&B2CP01RZ1,8,13},	//( - , Baz1) Текущее давление СБРОС РБ2
	{&A2CP01RZ1,8,15},	//( - , Baz1) Текущее давление СБРОС РБ1
	{&A0CT01IZ1,8,17},	//( - , Baz1, SBz1DU) Температура АЗ1-1
	{&R0VR02RZ1,8,19},	//( - , Baz1) Усредненная реактивность
	{&R0VN09RZ1,8,21},	//( - , Baz1, SBz1DU) Усредненный период разгона
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
	{&R0MW12IP2,3,0},	//( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{&fEM_R0UT02RZZ,8,1},	//( - , Baz1) Верхний предел шкалы датчика температуры
	{&fEM_R0UT01RZZ,8,3},	//( - , Baz1) Нижний предел шкалы датчика температуры
	{&fEM_A2UP03RZZ,8,5},	//( - , Baz1) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{&fEM_A2UP04RZZ,8,7},	//( - , Baz1) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{&fEM_R0UT72RZZ,8,9},	//( - , Baz1) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{&fEM_R0UT71RZZ,8,11},	//( - , Baz1) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{&fEM_R0UT62RZZ,8,13},	//( - , Baz1) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{&fEM_R0UT61RZZ,8,15},	//( - , Baz1) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{&fEM_A2UP41RZZ,8,17},	//( - , Baz1) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{&fEM_A2UP42RZZ,8,19},	//( - , Baz1) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{&fEM_A2UP51RZZ,8,21},	//( - , Baz1) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{&fEM_A2UP81RZZ,8,23},	//( - , Baz1) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{&fEM_A2UP84RZZ,8,25},	//( - , Baz1) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{&fEM_A2UP82RZZ,8,27},	//( - , Baz1) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{&fEM_A2UP52RZZ,8,29},	//( - , Baz1) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{&fEM_A2UP83RZZ,8,31},	//( - , Baz1) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{&fEM_R0UR01RZZ,8,33},	//( - , Baz1) Уставка АКНП ПС  АЗ по периоду (сек)
	{&fEM_R0UR04RZZ,8,35},	//( - , Baz1) Уставка АКНП АС  АЗ по периоду (сек)
	{&fEM_A1UL12RZZ,8,37},	//( - , Baz1) Время задержки АЗ от НУ ИС(сек)
	{&fEM_A1UL11RZZ,8,39},	//( - , Baz1) Время задержки АЗ от ВУ ИС сек
	{&fEM_R7UI73RZZ,8,41},	//( - , Baz1) Время задержки  срабатывания АС II УР
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
	{&A0VT71LZ1,1,10},	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SBz1DU[]={  // 
	{&B0CT01IZ1,8,0},	//( - , Baz1, SBz1DU) Температура АЗ2-1
	{&R0VN11RZ1,8,2},	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
	{&R0VN09RZ1,8,4},	//( - , Baz1, SBz1DU) Усредненный период разгона
	{&A0CT01IZ1,8,6},	//( - , Baz1, SBz1DU) Температура АЗ1-1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SBz1DU[]={  // 
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
	{&R0IS01FI0,3,0},	//( - , SBz1, SBz2, SDu, SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{&B0IT01FZ1,3,1},	//( - , SBz1) Температура АЗ2-1
	{&A0IT01FZ1,3,2},	//( - , SBz1) Температура АЗ1-1
	{&A2IP01FZ1,3,3},	//( - , SBz1) Текущее давление СБРОС РБ1
	{&B2IP01FZ1,3,4},	//( - , SBz1) Текущее давление СБРОС РБ2
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
static ModbusRegister coil_DiagnBaz1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnBaz1[]={  // 
	{&R0DE3DLZ1,1,0},	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 6
	{&R0DE3CLZ1,1,1},	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 5
	{&R0DEB3LZ1,1,2},	//( - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
	{&R0DEB4LZ1,1,3},	//( - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
	{&R0DEB2LZ1,1,4},	//( - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
	{&R0DEB1LZ1,1,5},	//( - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
	{&R0DE38LZ1,1,6},	//( - S08SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3 место 3
	{&R0DE39LZ1,1,7},	//( - S09SBK, DiagnBaz1) диагностика шкафа Баз1 МП24-2 место 4
	{&R0DE35LZ1,1,8},	//( - S05SBK, DiagnBaz1) диагностика шкафа Баз1 температура больше 53
	{&R0DE37LZ1,1,9},	//( - S07SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 2
	{&R0DE36LZ1,1,10},	//( - S06SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 1
	{&R0DE33LZ1,1,11},	//( - S03SBK, DiagnBaz1) диагностика шкафа Баз1 двери
	{&R0DE34LZ1,1,12},	//( - S04SBK, DiagnBaz1) диагностика шкафа Баз1 температура меньше 43
	{&R0DE32LZ1,1,13},	//( - S02SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 2
	{&R0DE31LZ1,1,14},	//( - S01SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DiagnBaz1[]={  // 
	{&R0DE0ALZ1,3,0},	//( - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
	{&R0DE07LZ1,3,1},	//( - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
	{&R0DE08LZ1,3,2},	//( - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
	{&R0DE06LZ1,3,3},	//( - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
	{&R0DE05LZ1,3,4},	//( - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
	{&R0DE04LZ1,3,5},	//( - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DiagnBaz1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_Baz1[0],&di_Baz1[0],&ir_Baz1[0],&hr_Baz1[0],NULL,NULL,NULL,0},	 //Общий слэйв
	{0,5010,&coil_SBz1DU[0],&di_SBz1DU[0],&ir_SBz1DU[0],&hr_SBz1DU[0],NULL,NULL,NULL,0},	 //Слэйв для DU
	{1,5003,&coil_MBz1S[0],&di_MBz1S[0],&ir_MBz1S[0],&hr_MBz1S[0],NULL,MBz1S_ip1,MBz1S_ip2,100},	 //Мастер Баз1 в SCM
	{0,5005,&coil_DiagnBaz1[0],&di_DiagnBaz1[0],&ir_DiagnBaz1[0],&hr_DiagnBaz1[0],NULL,NULL,NULL,0},	 //Диагностика корзины Baz1

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
	{&B0IT01IZ1,3,6},
	{&R0DE04LZ1,3,26},
	{&A0IT01IZ1,3,0},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS321[66];	//VDS32
static vds32r_inipar ini_VDS321={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS321={0,0,&ini_VDS321,buf_VDS321,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS321[]={
	{&A0EE01LS1,1,4},
	{&R0AD03LZ1,1,12},
	{&A3IS22LDU,1,10},
	{&A3IS11LDU,1,8},
	{&R0AD04LZ1,1,14},
	{&R0VN71LZ1,1,0},
	{&A0VN71LS1,1,6},
	{&R0VN75LZ1,1,2},
	{&R0AD05LZ1,1,16},
	{&R0DE05LZ1,3,64},
	{&B2IS12LDU,1,20},
	{&A2IS12LDU,1,18},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS322[66];	//VDS32
static vds32r_inipar ini_VDS322={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS322={0,0,&ini_VDS322,buf_VDS322,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS322[]={
	{&R0VN76LZ1,1,2},
	{&R0VN72LZ1,1,0},
	{&A0VN71LS2,1,6},
	{&A0EE01LS2,1,4},
	{&R0DE06LZ1,3,64},
	{&B3IS11LDU,1,8},
	{&B3IS22LDU,1,22},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS323[66];	//VDS32
static vds32r_inipar ini_VDS323={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS323={0,0,&ini_VDS323,buf_VDS323,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS323[]={
	{&R0VN74LZ1,1,0},
	{&A0EE01LS4,1,4},
	{&R0VN78LZ1,1,2},
	{&R6IS68LZZ,1,12},
	{&R6IS67LZZ,1,10},
	{&R6IS66LZZ,1,8},
	{&R0DE07LZ1,3,64},
	{&A0VN71LS4,1,6},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS324[66];	//VDS32
static vds32r_inipar ini_VDS324={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS324={0,0,&ini_VDS324,buf_VDS324,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS324[]={
	{&A0EE01LS3,1,4},
	{&A1VP81LZZ,1,18},
	{&B1VP81LZZ,1,24},
	{&A0VP81LZZ,1,16},
	{&B0VP81LZZ,1,22},
	{&R0DE08LZ1,3,64},
	{&R0VN77LZ1,1,2},
	{&R0VN73LZ1,1,0},
	{&R7II72LZ1,1,10},
	{&R7II71LZ1,1,8},
	{&R7II73LZ1,1,12},
	{&A0VN71LS3,1,6},
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
	{&R0DE0ALZ1,3,38},
	{&A1VN71LZ1,1,6},
	{&A3VZ15LZ1,1,2},
	{&A3VZ13LZ1,1,0},
	{&R0VZ71LZ1,1,8},
	{&R0AD14LZ1,1,4},
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
	{&R0DE31LZ1,1,0},
	{&R0DEB3LZ1,1,22},
	{&R0DE32LZ1,1,2},
	{&R0DE34LZ1,1,6},
	{&R0DE33LZ1,1,4},
	{&R0DE36LZ1,1,10},
	{&R0DE37LZ1,1,12},
	{&R0DE35LZ1,1,8},
	{&R0DE39LZ1,1,16},
	{&R0DE38LZ1,1,14},
	{&R0DEB1LZ1,1,18},
	{&R0DEB2LZ1,1,20},
	{&R0DEB4LZ1,1,24},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc6,0x04,7,30,def_buf_VAS84,&table_VAS84}, //VAS84
	{0xc2,0x05,15,66,def_buf_VDS321,&table_VDS321}, //VDS32
	{0xc2,0x06,15,66,def_buf_VDS322,&table_VDS322}, //VDS32
	{0xc2,0x07,15,66,def_buf_VDS323,&table_VDS323}, //VDS32
	{0xc2,0x08,15,66,def_buf_VDS324,&table_VDS324}, //VDS32
	{0x96,0x0a,20,40,def_buf_FDS16,&table_FDS16}, //FDS16
	{0xcc,0x20,4,26,def_buf_SBKFP,&table_SBKFP}, //SBKFP
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
	setAsFloat(172,600);
	setAsFloat(173,0);
	setAsFloat(174,1.6);
	setAsFloat(175,0);
	setAsFloat(176,150);
	setAsFloat(177,200);
	setAsFloat(178,90);
	setAsFloat(179,100);
	setAsFloat(180,0.1);
	setAsFloat(181,0.13);
	setAsFloat(182,0.16);
	setAsFloat(183,0.17);
	setAsFloat(184,0.31);
	setAsFloat(185,0.2);
	setAsFloat(186,0.19);
	setAsFloat(187,0.28);
	setAsFloat(188,15);
	setAsFloat(189,10);
	setAsFloat(190,0.180);
	setAsFloat(191,0.020);
	setAsFloat(192,0.045);
}
uspaint8 InternalBuf[99];

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
ssint iRM_819_ = {819,0}; /* a */ 
ssint iRM_4095_ = {4095,0}; /* b */ 
ssfloat fRM_0_00001 = {0.00001,0}; /* X2 */ 
ssint iRM_200_ = {200,0}; /* tz - ширина импульса, 10-ки мс */ 
ssfloat fRM_0_2 = {0.2,0}; /* tz - время задержки сек */ 
ssfloat fRM_1_0 = {1.0,0}; /* tz - время задержки сек */ 
ssint iRM_7_ = {7,0}; /* n - N-размерность массива x */ 
ssfloat fRM_0_002 = {0.002,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_005 = {0.005,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_007 = {0.007,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_01 = {0.01,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_015 = {0.015,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_02 = {0.02,0}; /* x - массив входных параметров */ 
ssfloat fRM_1_7 = {1.7,0}; /* x - массив входных параметров */ 
ssint iRM_1_ = {1,0}; /*  */ 
ssint iRM_2_ = {2,0}; /*  */ 

uspaint8 SpaEEPROMBuf[105];

/* Определение переменных */
ssint var1;
ssint var2;
ssint var3;
ssint var4;
ssint var5;
ssbool var6;
ssbool var7;
ssbool var8;
ssbool var9;
ssbool var10;
ssbool var11;
ssint var12;
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
ssbool var106;
ssbool var107;
ssbool var108;
ssbool var109;
ssbool var110;
ssbool var111;
ssbool var112;
ssbool var113;
ssbool var114;
ssbool var115;
ssbool var116;
ssbool var117;
ssbool var118;
ssbool var119;
ssbool var120;
ssbool var121;
ssbool var122;
ssbool var123;
ssbool var124;
ssbool var125;
ssbool var126;
ssbool var127;
ssbool var128;
ssbool var129;
ssbool var130;
ssbool var131;
ssbool var132;
ssbool var133;
ssbool var134;
ssbool var135;
ssbool var136;
ssbool var137;
ssfloat var138;
ssfloat var139;
ssbool var140;
ssfloat var141;
ssfloat var142;
ssbool var143;
ssbool var144;
ssbool var145;
ssbool var146;
ssbool var147;
ssbool var148;
ssfloat var149;
sslong var150;
sslong var151;
ssbool var152;
ssbool var153;
ssbool var154;
ssbool var155;
ssbool var156;
ssbool var157;
ssbool var158;
ssbool var159;
ssbool var160;
ssfloat var161;
ssbool var162;
ssbool var163;
ssfloat var164;
ssbool var165;
ssbool var166;
sschar var167;
ssbool var168;
sschar var169;
ssbool var170;
ssbool var171;
ssbool var172;
ssbool var173;
ssbool var174;
ssbool var175;
ssbool var176;
ssbool var177;
ssbool var178;
ssbool var179;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psint  array_m95_x_1[2] = {&A2IP01IZ1,&A2IP01FZ1};
psint  array_m96_x_1[2] = {&B2IP01IZ1,&B2IP01FZ1};
psint  array_m167_x_1[2] = {&B0IT01IZ1,&B0IT01FZ1};
psint  array_m154_x_1[2] = {&A0IT01IZ1,&A0IT01FZ1};
psbool  array_m370_x_1[6] = {&var9,&var8,&R0DE36LZ1,&R0DE37LZ1,&R0DE38LZ1,&R0DE39LZ1};
psint  array_m357_x_1[6] = {&R0DE04LZ1,&R0DE05LZ1,&R0DE06LZ1,&R0DE0ALZ1,&R0DE08LZ1,&R0DE07LZ1};
psfloat  array_m198_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psfloat  array_m340_x_1[4] = {&R0VN02RS1,&R0VN02RS2,&R0VN02RS3,&R0VN02RS4};
psbool  array_m340_diag_1[4] = {&var33,&var34,&var35,&var36};
psbool  array_m320_x_1[17] = {&var95,&var61,&var62,&var90,&var45,&var48,&var166,&var60,&var56,&var55,&var91,&var51,&var49,&var168,&var59,&var58,&var57};
psbool  array_m16_x_1[6] = {&var100,&var91,&var49,&var51,&var109,&var168};
psbool  array_m36_x_1[6] = {&var90,&var45,&var48,&var166,&var98,&var109};
psfloat  array_m2_x_1[4] = {&R0VN01RS1,&R0VN01RS2,&R0VN01RS3,&R0VN01RS4};
psbool  array_m2_diag_1[4] = {&var33,&var34,&var35,&var36};
psbool  array_m3_x_1[3] = {&var119,&var148,&var31};
psbool  array_m12_x_1[3] = {&var118,&var32,&var120};

/* Объявление структур */
_S_maz  S_maz_95_1 = {array_m95_x_1,&var5,&iRM_2_,&var1};
_S_maz  S_maz_96_1 = {array_m96_x_1,&var5,&iRM_2_,&var2};
_S_maz  S_maz_167_1 = {array_m167_x_1,&var5,&iRM_2_,&var3};
_S_maz  S_maz_154_1 = {array_m154_x_1,&var5,&iRM_2_,&var4};
_S_fsumz  S_fsumz_148_1 = {&R0IS01FI0,&iRM_1_,&var5};
_S_or3  S_or3_371_1 = {&var11,&var10,&var7,&var6};
_S_orn  S_orn_370_1 = {array_m370_x_1,&iRM_6_,&var7};
_S_or2  S_or2_375_1 = {&R0DEB3LZ1,&R0DEB4LZ1,&var8};
_S_or2  S_or2_368_1 = {&R0DEB1LZ1,&R0DEB2LZ1,&var9};
_S_and2  S_and2_359_1 = {&R0DE31LZ1,&R0DE32LZ1,&var10};
_S_diagndev  S_diagndev_357_1 = {array_m357_x_1,&iRM_6_,&var11,&var12};
_S_ma  S_ma_198_1 = {array_m198_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_and3  S_and3_242_1 = {&var16,&var26,&var25,&var13};
_S_and3  S_and3_239_1 = {&var26,&var16,&var135,&var14};
_S_and3  S_and3_238_1 = {&var25,&var16,&var134,&var15};
_S_noto  S_noto_230_1 = {&R0AD03LZ1,&var16};
_S_and3  S_and3_236_1 = {&var19,&var22,&var21,&var17};
_S_and3  S_and3_232_1 = {&var19,&var21,&var137,&var18};
_S_noto  S_noto_224_1 = {&R0AD05LZ1,&var19};
_S_and3  S_and3_231_1 = {&var19,&var22,&var136,&var20};
_S_and2  S_and2_225_1 = {&var113,&R0VW23LDU,&var21};
_S_and2  S_and2_223_1 = {&var114,&R0VW13LDU,&var22};
_S_and3  S_and3_217_1 = {&var114,&var113,&R0AD05LZ1,&var23};
_S_and3  S_and3_222_1 = {&var112,&var111,&R0AD03LZ1,&var24};
_S_and2  S_and2_226_1 = {&var112,&R0VW13LDU,&var25};
_S_and2  S_and2_227_1 = {&R0VW23LDU,&var111,&var26};
_S_and2  S_and2_261_1 = {&var133,&var43,&var27};
_S_zzfs  S_zzfs_254_1 = {&R0AD14LDU,&fRM_1_0,&var28,&internal1_m254_tx,&internal1_m254_y0};
_S_and2  S_and2_128_1 = {&var171,&var147,&var29};
_S_and2  S_and2_137_1 = {&var170,&var146,&var30};
_S_or2  S_or2_106_1 = {&var177,&var175,&var31};
_S_or2  S_or2_110_1 = {&var172,&var173,&var32};
_S_and2  S_and2_80_1 = {&A0EE05LZ1,&A0EE01LS1,&var33};
_S_and2  S_and2_82_1 = {&A0EE06LZ1,&A0EE01LS2,&var34};
_S_and2  S_and2_84_1 = {&A0EE07LZ1,&A0EE01LS3,&var35};
_S_and2  S_and2_86_1 = {&A0EE08LZ1,&A0EE01LS4,&var36};
_S_and2  S_and2_188_1 = {&var163,&var128,&var37};
_S_and2  S_and2_189_1 = {&var162,&var128,&var38};
_S_or2  S_or2_265_1 = {&var116,&R7II73LZ1,&var39};
_S_or2  S_or2_267_1 = {&R0AD21LDU,&R0AD14LDU,&var40};
_S_and2  S_and2_266_1 = {&var40,&var39,&var41};
_S_or2  S_or2_259_1 = {&R7II71LZ1,&var115,&var42};
_S_or3  S_or3_260_1 = {&var44,&var42,&var41,&var43};
_S_or2  S_or2_253_1 = {&var117,&R7II72LZ1,&var44};
_S_or2  S_or2_240_1 = {&var20,&var17,&var45};
_S_or2  S_or2_209_1 = {&A3IS22LDU,&R0AD05LZ1,&var46};
_S_or2  S_or2_211_1 = {&B3IS22LDU,&R0AD05LZ1,&var47};
_S_or2  S_or2_243_1 = {&var15,&var13,&var48};
_S_or2  S_or2_244_1 = {&var14,&var13,&var49};
_S_or2  S_or2_212_1 = {&var132,&R0AD03LZ1,&var50};
_S_or2  S_or2_241_1 = {&var18,&var17,&var51};
_S_or2  S_or2_214_1 = {&var131,&R0AD03LZ1,&var52};
_S_schl24  S_schl24_342_1 = {&A0VN71LS2,&A0VN71LS1,&A0VN71LS4,&A0VN71LS3,&var53};
_S_and2  S_and2_333_1 = {&var127,&var126,&var54};
_S_and2  S_and2_322_1 = {&var74,&var96,&var55};
_S_and2  S_and2_324_1 = {&var81,&var96,&var56};
_S_and2  S_and2_330_1 = {&var41,&var110,&var57};
_S_and2  S_and2_329_1 = {&var42,&var110,&var58};
_S_and2  S_and2_328_1 = {&var44,&var110,&var59};
_S_and2  S_and2_326_1 = {&var129,&var96,&var60};
_S_and2  S_and2_323_1 = {&var85,&var96,&var61};
_S_and2  S_and2_321_1 = {&var67,&var96,&var62};
_S_and2  S_and2_307_1 = {&var65,&var64,&var63};
_S_or2  S_or2_309_1 = {&R0VN75LZ1,&var160,&var64};
_S_or2  S_or2_310_1 = {&R0VN77LZ1,&var159,&var65};
_S_or2  S_or2_295_1 = {&var63,&var71,&var66};
_S_or2  S_or2_301_1 = {&var68,&var63,&var67};
_S_and2  S_and2_302_1 = {&var155,&var72,&var68};
_S_or2  S_or2_312_1 = {&R0VN78LZ1,&var157,&var69};
_S_or2  S_or2_311_1 = {&R0VN76LZ1,&var158,&var70};
_S_and2  S_and2_308_1 = {&var70,&var69,&var71};
_S_schl24  S_schl24_306_1 = {&var70,&var69,&var65,&var64,&var72};
_S_and2  S_and2_304_1 = {&var96,&var72,&var73};
_S_or2  S_or2_303_1 = {&var71,&var68,&var74};
_S_and2  S_and2_299_1 = {&var74,&var96,&var75};
_S_or2  S_or2_275_1 = {&R0VN72LZ1,&var158,&var76};
_S_and2  S_and2_290_1 = {&var85,&var96,&var77};
_S_and2  S_and2_280_1 = {&var76,&var79,&var78};
_S_or2  S_or2_276_1 = {&R0VN74LZ1,&var157,&var79};
_S_and2  S_and2_291_1 = {&var81,&var96,&var80};
_S_or2  S_or2_288_1 = {&var78,&var84,&var81};
_S_or2  S_or2_294_1 = {&var86,&var78,&var82};
_S_and2  S_and2_282_1 = {&var88,&var96,&var83};
_S_and2  S_and2_287_1 = {&var156,&var88,&var84};
_S_or2  S_or2_286_1 = {&var86,&var84,&var85};
_S_and2  S_and2_277_1 = {&var87,&var89,&var86};
_S_or2  S_or2_274_1 = {&R0VN73LZ1,&var159,&var87};
_S_schl24  S_schl24_279_1 = {&var87,&var89,&var76,&var79,&var88};
_S_or2  S_or2_273_1 = {&R0VN71LZ1,&var160,&var89};
_S_or2  S_or2_158_1 = {&var140,&var178,&var90};
_S_or2  S_or2_160_1 = {&var145,&var143,&var91};
_S_or2  S_or2_346_1 = {&var176,&var174,&var92};
_S_or2  S_or2_35_1 = {&B2IS12LDU,&A2IS12LDU,&var93};
_S_and2  S_and2_298_1 = {&var96,&var67,&var94};
_S_and2  S_and2_327_1 = {&var130,&var96,&var95};
_S_and2  S_and2_26_1 = {&var125,&var121,&var96};
_S_or2  S_or2_24_1 = {&var153,&var152,&var97};
_S_and2  S_and2_31_1 = {&var99,&var96,&var98};
_S_or3  S_or3_30_1 = {&var67,&var85,&var124,&var99};
_S_and2  S_and2_19_1 = {&var96,&var101,&var100};
_S_or3  S_or3_18_1 = {&var81,&var74,&var123,&var101};
_S_and2  S_and2_6_1 = {&var34,&var36,&var102};
_S_or2  S_or2_11_1 = {&var154,&var102,&var103};
_S_or2  S_or2_10_1 = {&var105,&var154,&var104};
_S_and2  S_and2_5_1 = {&var33,&var35,&var105};
_S_and2  S_and2_199_1 = {&R0AD14LDU,&R7II72LZ1,&var106};
_S_and2  S_and2_195_1 = {&R0AD14LDU,&R7II71LZ1,&var107};
_S_and2  S_and2_192_1 = {&R0AD14LDU,&R7II73LZ1,&var108};
_S_zpfs  S_zpfs_262_1 = {&var27,&fEM_R7UI73RZZ,&var109,&internal1_m262_tx,&internal1_m262_y0};
_S_zpfs  S_zpfs_325_1 = {&var54,&fRM_0_2,&var110,&internal1_m325_tx,&internal1_m325_y0};
_S_zpfs  S_zpfs_221_1 = {&var52,&fEM_A1UL11RZZ,&var111,&internal1_m221_tx,&internal1_m221_y0};
_S_zpfs  S_zpfs_220_1 = {&var50,&fEM_A1UL11RZZ,&var112,&internal1_m220_tx,&internal1_m220_y0};
_S_zpfs  S_zpfs_218_1 = {&var47,&fEM_A1UL12RZZ,&var113,&internal1_m218_tx,&internal1_m218_y0};
_S_zpfs  S_zpfs_216_1 = {&var46,&fEM_A1UL12RZZ,&var114,&internal1_m216_tx,&internal1_m216_y0};
_S_noto  S_noto_258_1 = {&R6IS67LZZ,&var115};
_S_noto  S_noto_264_1 = {&R6IS68LZZ,&var116};
_S_noto  S_noto_247_1 = {&R6IS66LZZ,&var117};
_S_noto  S_noto_136_1 = {&B0VP81LZZ,&var118};
_S_noto  S_noto_135_1 = {&A0VP81LZZ,&var119};
_S_noto  S_noto_113_1 = {&B1VP81LZZ,&var120};
_S_noto  S_noto_27_1 = {&var122,&var121};
_S_ovb1  S_ovb1_33_1 = {&var93,&iRM_200_,&var122,&internal1_m33_tx};
_S_noto  S_noto_15_1 = {&var103,&var123};
_S_noto  S_noto_14_1 = {&var104,&var124};
_S_noto  S_noto_23_1 = {&R0EE02LDU,&var125};
_S_noto  S_noto_335_1 = {&R0AD16LDU,&var126};
_S_noto  S_noto_334_1 = {&R0AD04LZ1,&var127};
_S_bol  S_bol_184_1 = {&var164,&fRM_0_00001,&var128};
_S_noto  S_noto_331_1 = {&var103,&var129};
_S_noto  S_noto_332_1 = {&var104,&var130};
_S_noto  S_noto_208_1 = {&B3IS11LDU,&var131};
_S_noto  S_noto_207_1 = {&A3IS11LDU,&var132};
_S_noto  S_noto_255_1 = {&var28,&var133};
_S_noto  S_noto_234_1 = {&R0VW23LDU,&var134};
_S_noto  S_noto_233_1 = {&R0VW13LDU,&var135};
_S_noto  S_noto_229_1 = {&R0VW23LDU,&var136};
_S_noto  S_noto_228_1 = {&R0VW13LDU,&var137};
_S_scalzz  S_scalzz_147_1 = {&var3,&iRM_819_,&iRM_4095_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var138,&internal1_m147_y0};
_S_scalzz  S_scalzz_146_1 = {&var4,&iRM_819_,&iRM_4095_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var139,&internal1_m146_y0};
_S_geterr  S_geterr_149_1 = {&var139,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var140};
_S_scalzz  S_scalzz_94_1 = {&var2,&iRM_819_,&iRM_4095_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var141,&internal1_m94_y0};
_S_scalzz  S_scalzz_93_1 = {&var1,&iRM_819_,&iRM_4095_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var142,&internal1_m93_y0};
_S_drg  S_drg_161_1 = {&var138,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var143,&internal1_m161_y1};
_S_drg  S_drg_175_1 = {&var138,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var144,&internal1_m175_y1};
_S_geterr  S_geterr_151_1 = {&var138,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var145};
_S_noto  S_noto_138_1 = {&var172,&var146};
_S_noto  S_noto_127_1 = {&var177,&var147};
_S_noto  S_noto_112_1 = {&A1VP81LZZ,&var148};
_S_srm  S_srm_340_1 = {array_m340_x_1,array_m340_diag_1,&iRM_4_,&iRM_3_,&var149,&vainSBool};
_S_rsu  S_rsu_318_1 = {&R0MD34LP1,&var151,&var150,&internal1_m318_q0};
_S_orni  S_orni_320_1 = {array_m320_x_1,&iRM_17_,&vainSBool,&var151};
_S_orn  S_orn_16_1 = {array_m16_x_1,&iRM_6_,&var152};
_S_orn  S_orn_36_1 = {array_m36_x_1,&iRM_6_,&var153};
_S_noto  S_noto_7_1 = {&var165,&var154};
_S_noto  S_noto_297_1 = {&var66,&var155};
_S_noto  S_noto_292_1 = {&var82,&var156};
_S_noto  S_noto_281_1 = {&A0EE01LS4,&var157};
_S_noto  S_noto_285_1 = {&A0EE01LS2,&var158};
_S_noto  S_noto_284_1 = {&A0EE01LS3,&var159};
_S_noto  S_noto_278_1 = {&A0EE01LS1,&var160};
_S_react  S_react_180_1 = {&var164,&var161};
_S_bol  S_bol_185_1 = {&fEM_R0UR04RZZ,&var164,&var162};
_S_bol  S_bol_183_1 = {&fEM_R0UR01RZZ,&var164,&var163};
_S_srm  S_srm_2_1 = {array_m2_x_1,array_m2_diag_1,&iRM_4_,&iRM_3_,&var164,&var165};
_S_ornc  S_ornc_3_1 = {array_m3_x_1,&iRM_3_,&var166,&var167};
_S_ornc  S_ornc_12_1 = {array_m12_x_1,&iRM_3_,&var168,&var169};
_S_tprg  S_tprg_129_1 = {&var141,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var170,&internal1_m129_y0};
_S_tprg  S_tprg_125_1 = {&var142,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var171,&internal1_m125_y0};
_S_geterr  S_geterr_104_1 = {&var141,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var172};
_S_drg  S_drg_109_1 = {&var141,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var173,&internal1_m109_y1};
_S_drg  S_drg_118_1 = {&var141,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var174,&internal1_m118_y1};
_S_drg  S_drg_97_1 = {&var142,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var175,&internal1_m97_y1};
_S_drg  S_drg_107_1 = {&var142,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var176,&internal1_m107_y1};
_S_geterr  S_geterr_101_1 = {&var142,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var177};
_S_drg  S_drg_159_1 = {&var139,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var178,&internal1_m159_y1};
_S_drg  S_drg_173_1 = {&var139,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var179,&internal1_m173_y1};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  noto(&S_noto_278_1);
  noto(&S_noto_284_1);
  noto(&S_noto_285_1);
  noto(&S_noto_281_1);
  noto(&S_noto_112_1);
  noto(&S_noto_229_1);
  noto(&S_noto_233_1);
  noto(&S_noto_234_1);
  noto(&S_noto_207_1);
  noto(&S_noto_208_1);
  noto(&S_noto_23_1);
  noto(&S_noto_113_1);
  noto(&S_noto_135_1);
  noto(&S_noto_136_1);
  noto(&S_noto_247_1);
  noto(&S_noto_264_1);
  noto(&S_noto_258_1);
  and2(&S_and2_192_1);
  and2(&S_and2_195_1);
  and2(&S_and2_199_1);
  or2(&S_or2_273_1);
  or2(&S_or2_274_1);
  and2(&S_and2_277_1);
  or2(&S_or2_276_1);
  or2(&S_or2_275_1);
  or2(&S_or2_311_1);
  or2(&S_or2_312_1);
  or2(&S_or2_310_1);
  or2(&S_or2_309_1);
  and2(&S_and2_307_1);
  schl24(&S_schl24_342_1);
  or2(&S_or2_214_1);
  or2(&S_or2_212_1);
  or2(&S_or2_211_1);
  or2(&S_or2_209_1);
  or2(&S_or2_253_1);
  or2(&S_or2_259_1);
  or2(&S_or2_267_1);
  or2(&S_or2_265_1);
  and2(&S_and2_86_1);
  and2(&S_and2_84_1);
  and2(&S_and2_82_1);
  and2(&S_and2_80_1);
  zzfs(&S_zzfs_254_1);
  noto(&S_noto_224_1);
  noto(&S_noto_230_1);
  ma(&S_ma_198_1);
  and2(&S_and2_359_1);
  or2(&S_or2_368_1);
  or2(&S_or2_375_1);
  orn(&S_orn_370_1);
  fsumz(&S_fsumz_148_1);
  srm(&S_srm_2_1);
  bol(&S_bol_183_1);
  bol(&S_bol_185_1);
  react(&S_react_180_1);
  noto(&S_noto_7_1);
  srm(&S_srm_340_1);
  noto(&S_noto_228_1);
  noto(&S_noto_255_1);
  bol(&S_bol_184_1);
  noto(&S_noto_334_1);
  noto(&S_noto_335_1);
  zpfs(&S_zpfs_216_1);
  zpfs(&S_zpfs_218_1);
  zpfs(&S_zpfs_220_1);
  zpfs(&S_zpfs_221_1);
  and2(&S_and2_5_1);
  or2(&S_or2_10_1);
  and2(&S_and2_6_1);
  or2(&S_or2_35_1);
  schl24(&S_schl24_279_1);
  and2(&S_and2_280_1);
  schl24(&S_schl24_306_1);
  and2(&S_and2_308_1);
  or2(&S_or2_295_1);
  and2(&S_and2_333_1);
  and2(&S_and2_266_1);
  and2(&S_and2_189_1);
  and2(&S_and2_188_1);
  and2(&S_and2_227_1);
  and2(&S_and2_226_1);
  and3(&S_and3_222_1);
  and3(&S_and3_217_1);
  and2(&S_and2_223_1);
  and2(&S_and2_225_1);
  and3(&S_and3_231_1);
  and3(&S_and3_232_1);
  and3(&S_and3_236_1);
  and3(&S_and3_238_1);
  and3(&S_and3_239_1);
  and3(&S_and3_242_1);
  diagndev(&S_diagndev_357_1);
  or3(&S_or3_371_1);
  maz(&S_maz_154_1);
  maz(&S_maz_167_1);
  maz(&S_maz_96_1);
  maz(&S_maz_95_1);
  noto(&S_noto_297_1);
  scalzz(&S_scalzz_93_1);
  scalzz(&S_scalzz_94_1);
  scalzz(&S_scalzz_146_1);
  scalzz(&S_scalzz_147_1);
  noto(&S_noto_332_1);
  noto(&S_noto_14_1);
  ovb1(&S_ovb1_33_1);
  noto(&S_noto_27_1);
  zpfs(&S_zpfs_325_1);
  or2(&S_or2_11_1);
  and2(&S_and2_26_1);
  and2(&S_and2_327_1);
  and2(&S_and2_282_1);
  or2(&S_or2_294_1);
  and2(&S_and2_304_1);
  and2(&S_and2_302_1);
  or2(&S_or2_301_1);
  and2(&S_and2_321_1);
  and2(&S_and2_328_1);
  and2(&S_and2_329_1);
  and2(&S_and2_330_1);
  or2(&S_or2_241_1);
  or2(&S_or2_244_1);
  or2(&S_or2_243_1);
  or2(&S_or2_240_1);
  or3(&S_or3_260_1);
  and2(&S_and2_261_1);
  drg(&S_drg_173_1);
  drg(&S_drg_159_1);
  geterr(&S_geterr_101_1);
  drg(&S_drg_107_1);
  drg(&S_drg_97_1);
  drg(&S_drg_118_1);
  drg(&S_drg_109_1);
  geterr(&S_geterr_104_1);
  tprg(&S_tprg_125_1);
  tprg(&S_tprg_129_1);
  noto(&S_noto_292_1);
  noto(&S_noto_127_1);
  noto(&S_noto_138_1);
  geterr(&S_geterr_151_1);
  drg(&S_drg_175_1);
  drg(&S_drg_161_1);
  geterr(&S_geterr_149_1);
  noto(&S_noto_331_1);
  noto(&S_noto_15_1);
  zpfs(&S_zpfs_262_1);
  and2(&S_and2_298_1);
  or2(&S_or2_346_1);
  or2(&S_or2_160_1);
  or2(&S_or2_158_1);
  and2(&S_and2_287_1);
  or2(&S_or2_288_1);
  and2(&S_and2_291_1);
  or2(&S_or2_303_1);
  and2(&S_and2_326_1);
  and2(&S_and2_324_1);
  and2(&S_and2_322_1);
  or2(&S_or2_110_1);
  or2(&S_or2_106_1);
  and2(&S_and2_137_1);
  and2(&S_and2_128_1);
  ornc(&S_ornc_12_1);
  ornc(&S_ornc_3_1);
  or3(&S_or3_18_1);
  and2(&S_and2_19_1);
  or2(&S_or2_286_1);
  and2(&S_and2_290_1);
  and2(&S_and2_299_1);
  and2(&S_and2_323_1);
  orn(&S_orn_16_1);
  orni(&S_orni_320_1);
  rsu(&S_rsu_318_1);
  or3(&S_or3_30_1);
  and2(&S_and2_31_1);
  orn(&S_orn_36_1);
  or2(&S_or2_24_1);
  setData(idTestDiagnBaz1,&var6);
  setData(idR0DE3DLZ1,&var8);
  setData(idR0DE3CLZ1,&var9);
  setData(idTTLBaz1,&var12);
  setData(idR0AD16LZ1,&var106);
  setData(idR0AD15LZ1,&var107);
  moveData(idR0EE04LZ1,idR0EE02LDU);
  moveData(idR0EE03LZ1,idR0EE02LDU);
  moveData(idR0EE02LZ1,idR0EE02LDU);
  moveData(idR0EE01LZ1,idR0EE02LDU);
  setData(idR0AD14LZ1,&var108);
  setData(idA3VZ13LZ1,&var24);
  setData(idA3VZ15LZ1,&var23);
  setData(idA1VN71LZ1,&var53);
  setData(idB0VT71LZ1,&var91);
  setData(idB0VT61LZ1,&var144);
  setData(idB0CT01IZ1,&var138);
  setData(idR0VP73LZ1,&var92);
  setData(idR0VN11RZ1,&var149);
  setData(idR0VZ05UZ1,&var150);
  setData(idB0VN81LZ1,&var75);
  setData(idA0VN81LZ1,&var94);
  setData(idB0VN71LZ1,&var80);
  setData(idA0VN71LZ1,&var77);
  setData(idB0VZ71LZ1,&var152);
  setData(idB0EE00LZ1,&var103);
  setData(idA0EE00LZ1,&var104);
  setData(idA0VZ71LZ1,&var153);
  setData(idA0EE03LZ1,&var35);
  setData(idA0EE02LZ1,&var34);
  setData(idA0EE04LZ1,&var36);
  setData(idA0EE01LZ1,&var33);
  setData(idR0VN80LZ1,&var73);
  setData(idR0VN70LZ1,&var83);
  setData(idR0VZ71LZ1,&var97);
  setData(idR0VR02RZ1,&var161);
  setData(idR0VN79LZ1,&var38);
  setData(idR0VN69LZ1,&var37);
  setData(idB3VZ11LZ1,&var51);
  setData(idA3VZ11LZ1,&var45);
  setData(idB3VZ31LZ1,&var49);
  setData(idA3VZ31LZ1,&var48);
  setData(idR0VN09RZ1,&var164);
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
  setData(idB0VP71LZ1,&var168);
  setData(idA0VP71LZ1,&var166);
  setData(idA0EP02IZ1,&var167);
  setData(idB0EP02IZ1,&var169);
  setData(idR0ET02LZ1,&var145);
  setData(idB0VP41LZ1,&var118);
  setData(idA0VP41LZ1,&var119);
  setData(idR0ET01LZ1,&var140);
  setData(idA2VP81LZ1,&var29);
  setData(idB2VP81LZ1,&var30);
  setData(idB2VP51LZ1,&var174);
  setData(idB2CP01RZ1,&var141);
  setData(idB2VP41LZ1,&var32);
  setData(idA2VP51LZ1,&var176);
  setData(idA2CP01RZ1,&var142);
  setData(idA2VP41LZ1,&var31);
  setData(idB1VP41LZ1,&var120);
  setData(idA1VP41LZ1,&var148);
  setData(idA0VT71LZ1,&var90);
  setData(idA0VT61LZ1,&var179);
  setData(idA0CT01IZ1,&var139);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}

#endif
