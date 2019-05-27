#ifndef BAZ1_H
#define BAZ1_H
// Подсистема Baz1:Baz1
static char SimulOn=0;
static short CodeSub=4;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=50;	 // Время цикла в ms
float takt, taktScheme=0, taktSS=0;
#define SIZE_BUFFER 697
static char BUFFER[697];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.52\0", 5432, "192.168.10.152\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R7II71LZ1	 BUFFER[0]	//(vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
#define idR7II71LZ1	 1	//(vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
#define R7II72LZ1	 BUFFER[2]	//(vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
#define idR7II72LZ1	 2	//(vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
#define R0AD14LZ1	 BUFFER[4]	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define idR0AD14LZ1	 3	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define R0AD21LDU	 BUFFER[6]	//( - , SBz1DU) Подключить защиту от II УР
#define idR0AD21LDU	 4	//( - , SBz1DU) Подключить защиту от II УР
#define R0AD14LDU	 BUFFER[8]	//( - , Baz1) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 5	//( - , Baz1) Имитация срабатывания верхней АС II УР
#define R0MD34LP1	 BUFFER[10]	//( - , Baz1) Кнопка (Квитировать)
#define idR0MD34LP1	 6	//( - , Baz1) Кнопка (Квитировать)
#define R0AD04LZ1	 BUFFER[12]	//(vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
#define idR0AD04LZ1	 7	//(vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
#define R0AD16LDU	 BUFFER[14]	//( - , Baz1) Имитация срабатывания верхней АС I УР
#define idR0AD16LDU	 8	//( - , Baz1) Имитация срабатывания верхней АС I УР
#define R0EE01LZ1	 BUFFER[16]	//( - , MBz1S) Питание  АКНП1  отключить
#define idR0EE01LZ1	 9	//( - , MBz1S) Питание  АКНП1  отключить
#define R6IS66LZZ	 BUFFER[18]	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 10	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[20]	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 11	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[22]	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 12	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define R0VN71LZ1	 BUFFER[24]	//(vds32:05 - K01VDSR, Baz1) АС по мощности канал 1
#define idR0VN71LZ1	 13	//(vds32:05 - K01VDSR, Baz1) АС по мощности канал 1
#define R0VN75LZ1	 BUFFER[26]	//(vds32:05 - K02VDSR, Baz1) АС по периоду разгона канал 1
#define idR0VN75LZ1	 14	//(vds32:05 - K02VDSR, Baz1) АС по периоду разгона канал 1
#define R0VN72LZ1	 BUFFER[28]	//(vds32:06 - K01VDSR, Baz1) АС по мощности канал 2
#define idR0VN72LZ1	 15	//(vds32:06 - K01VDSR, Baz1) АС по мощности канал 2
#define R0VN76LZ1	 BUFFER[30]	//(vds32:06 - K02VDSR, Baz1) АС по периоду разгона канал  2
#define idR0VN76LZ1	 16	//(vds32:06 - K02VDSR, Baz1) АС по периоду разгона канал  2
#define R0VN73LZ1	 BUFFER[32]	//(vds32:08 - K01VDSR, Baz1) АС по мощности канал 3
#define idR0VN73LZ1	 17	//(vds32:08 - K01VDSR, Baz1) АС по мощности канал 3
#define R0VN77LZ1	 BUFFER[34]	//(vds32:08 - K02VDSR, Baz1) АС по периоду разгона канал  3
#define idR0VN77LZ1	 18	//(vds32:08 - K02VDSR, Baz1) АС по периоду разгона канал  3
#define R0VN74LZ1	 BUFFER[36]	//(vds32:07 - K01VDSR, Baz1) АС по мощности канал 4
#define idR0VN74LZ1	 19	//(vds32:07 - K01VDSR, Baz1) АС по мощности канал 4
#define R0VN78LZ1	 BUFFER[38]	//(vds32:07 - K02VDSR, Baz1) АС по периоду разгона канал  4
#define idR0VN78LZ1	 20	//(vds32:07 - K02VDSR, Baz1) АС по периоду разгона канал  4
#define R0EE02LZ1	 BUFFER[40]	//( - , MBz1S) Питание  АКНП2  отключить
#define idR0EE02LZ1	 21	//( - , MBz1S) Питание  АКНП2  отключить
#define R0EE03LZ1	 BUFFER[42]	//( - , MBz1S) Питание  АКНП3  отключить
#define idR0EE03LZ1	 22	//( - , MBz1S) Питание  АКНП3  отключить
#define R0EE04LZ1	 BUFFER[44]	//( - , MBz1S) Питание  АКНП4  отключить
#define idR0EE04LZ1	 23	//( - , MBz1S) Питание  АКНП4  отключить
#define B0EE00LZ1	 BUFFER[46]	//( - , Baz1) Исправность АКНП АЗ2
#define idB0EE00LZ1	 24	//( - , Baz1) Исправность АКНП АЗ2
#define B0VZ71LZ1	 BUFFER[48]	//( - , Baz1) Обобщенный сигнал АС по АЗ2
#define idB0VZ71LZ1	 25	//( - , Baz1) Обобщенный сигнал АС по АЗ2
#define A0VN71LZ1	 BUFFER[50]	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
#define idA0VN71LZ1	 26	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
#define B0VN71LZ1	 BUFFER[52]	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
#define idB0VN71LZ1	 27	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
#define A0VN81LZ1	 BUFFER[54]	//( - , Baz1) АЗ по АС периода разгона АЗ1
#define idA0VN81LZ1	 28	//( - , Baz1) АЗ по АС периода разгона АЗ1
#define B0VN81LZ1	 BUFFER[56]	//( - , Baz1) АЗ по АС периода разгона АЗ2
#define idB0VN81LZ1	 29	//( - , Baz1) АЗ по АС периода разгона АЗ2
#define R0EE02LDU	 BUFFER[58]	//( - , Baz1) Питание  АКНП  отключить
#define idR0EE02LDU	 30	//( - , Baz1) Питание  АКНП  отключить
#define R0VZ05UZ1	 BUFFER[60]	//( - , Baz1) Индикатор причины сброса
#define idR0VZ05UZ1	 31	//( - , Baz1) Индикатор причины сброса
#define R0VN11RZ1	 BUFFER[65]	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
#define idR0VN11RZ1	 32	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
#define R0VP73LZ1	 BUFFER[70]	//( - , Baz1, SBz1DU) ПС давления для РУ
#define idR0VP73LZ1	 33	//( - , Baz1, SBz1DU) ПС давления для РУ
#define B0CT01IZ1	 BUFFER[72]	//( - , Baz1, SBz1DU) Температура АЗ2-1
#define idB0CT01IZ1	 34	//( - , Baz1, SBz1DU) Температура АЗ2-1
#define B0VT61LZ1	 BUFFER[77]	//( - , Baz1) ПС по температуре в АЗ2
#define idB0VT61LZ1	 35	//( - , Baz1) ПС по температуре в АЗ2
#define B0VT71LZ1	 BUFFER[79]	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
#define idB0VT71LZ1	 36	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
#define A0VN71LS1	 BUFFER[81]	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
#define idA0VN71LS1	 37	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
#define A0VN71LS2	 BUFFER[83]	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
#define idA0VN71LS2	 38	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
#define A0VN71LS3	 BUFFER[85]	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
#define idA0VN71LS3	 39	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
#define A0VN71LS4	 BUFFER[87]	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
#define idA0VN71LS4	 40	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
#define A1VN71LZ1	 BUFFER[89]	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	 41	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
#define A3VZ15LZ1	 BUFFER[91]	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
#define idA3VZ15LZ1	 42	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
#define A3VZ13LZ1	 BUFFER[93]	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
#define idA3VZ13LZ1	 43	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
#define R0VW13LDU	 BUFFER[95]	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 44	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	 BUFFER[97]	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 45	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R7II73LZ1	 BUFFER[99]	//(vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
#define idR7II73LZ1	 46	//(vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
#define R0DE3CLZ1	 BUFFER[101]	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 5
#define idR0DE3CLZ1	 47	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 5
#define R0DE3DLZ1	 BUFFER[103]	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 6
#define idR0DE3DLZ1	 48	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 6
#define TestDiagnBaz1	 BUFFER[105]	//( - , Baz1) Неисправность от диагностики
#define idTestDiagnBaz1	 49	//( - , Baz1) Неисправность от диагностики
#define R0MW11IP1	 BUFFER[107]	//( - , Baz1) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 50	//( - , Baz1) Переключатель ВЫСТРЕЛ
#define PS1	 BUFFER[110]	//( - , - ) АЗ по АС любого давления за АЗ1
#define idPS1	 51	//( - , - ) АЗ по АС любого давления за АЗ1
#define PS2	 BUFFER[112]	//( - , - ) АЗ от ВУ ИС1
#define idPS2	 52	//( - , - ) АЗ от ВУ ИС1
#define PS3	 BUFFER[114]	//( - , - ) АЗ от НУП ИС1
#define idPS3	 53	//( - , - ) АЗ от НУП ИС1
#define PS4	 BUFFER[116]	//( - , - ) АС по температуру АЗ1
#define idPS4	 54	//( - , - ) АС по температуру АЗ1
#define PS5	 BUFFER[118]	//( - , - ) АС по периоду АЗ1
#define idPS5	 55	//( - , - ) АС по периоду АЗ1
#define PS6	 BUFFER[120]	//( - , - ) АС по мощности АЗ1
#define idPS6	 56	//( - , - ) АС по мощности АЗ1
#define PS7	 BUFFER[122]	//( - , - ) Исправность АКНП АЗ2
#define idPS7	 57	//( - , - ) Исправность АКНП АЗ2
#define PS9	 BUFFER[124]	//( - , - ) АС 1 ур (д2)
#define idPS9	 58	//( - , - ) АС 1 ур (д2)
#define PS8	 BUFFER[126]	//( - , - ) Исправность АКНП АЗ1
#define idPS8	 59	//( - , - ) Исправность АКНП АЗ1
#define PS10	 BUFFER[128]	//( - , - ) АС 1 ур (д1)
#define idPS10	 60	//( - , - ) АС 1 ур (д1)
#define PS11	 BUFFER[130]	//( - , - ) АС 2 ур
#define idPS11	 61	//( - , - ) АС 2 ур
#define PS17	 BUFFER[132]	//( - , - ) Аз по Ас любого давления АЗ2
#define idPS17	 62	//( - , - ) Аз по Ас любого давления АЗ2
#define PS16	 BUFFER[134]	//( - , - ) АЗ от НУП ИС2
#define idPS16	 63	//( - , - ) АЗ от НУП ИС2
#define PS15	 BUFFER[136]	//( - , - ) АЗ от ВУ ИС2
#define idPS15	 64	//( - , - ) АЗ от ВУ ИС2
#define PS14	 BUFFER[138]	//( - , - ) Ас по температура АЗ2
#define idPS14	 65	//( - , - ) Ас по температура АЗ2
#define PS13	 BUFFER[140]	//( - , - ) АС по периоду АЗ2
#define idPS13	 66	//( - , - ) АС по периоду АЗ2
#define PS12	 BUFFER[142]	//( - , - ) Ас по мощности АЗ2
#define idPS12	 67	//( - , - ) Ас по мощности АЗ2
#define R0VZ05U	 BUFFER[144]	//( - , - ) причины сброса
#define idR0VZ05U	 68	//( - , - ) причины сброса
#define B8VC01RDU	 BUFFER[149]	//( - , SBz1DU, MBz1A1, MBz1A2, MBz1A3, MBz1A4) Координата АЗ2, мм
#define idB8VC01RDU	 69	//( - , SBz1DU, MBz1A1, MBz1A2, MBz1A3, MBz1A4) Координата АЗ2, мм
#define R0MW12IP2	 BUFFER[154]	//( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define idR0MW12IP2	 70	//( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define A2IS12LDU	 BUFFER[157]	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	 71	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define B2IS12LDU	 BUFFER[159]	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	 72	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define R0DE04LZ1	 BUFFER[161]	//(vas84:04 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
#define idR0DE04LZ1	 73	//(vas84:04 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
#define R0DE05LZ1	 BUFFER[164]	//(vds32:05 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
#define idR0DE05LZ1	 74	//(vds32:05 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
#define R0DE06LZ1	 BUFFER[167]	//(vds32:06 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
#define idR0DE06LZ1	 75	//(vds32:06 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
#define R0DE08LZ1	 BUFFER[170]	//(vds32:08 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
#define idR0DE08LZ1	 76	//(vds32:08 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
#define R0DE07LZ1	 BUFFER[173]	//(vds32:07 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
#define idR0DE07LZ1	 77	//(vds32:07 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
#define R0DE0ALZ1	 BUFFER[176]	//(fds16:0a - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
#define idR0DE0ALZ1	 78	//(fds16:0a - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
#define TTLBaz1	 BUFFER[179]	//( - , Baz1) ttl
#define idTTLBaz1	 79	//( - , Baz1) ttl
#define R0DE31LZ1	 BUFFER[182]	//(sbk:20 - S01SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 1
#define idR0DE31LZ1	 80	//(sbk:20 - S01SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 1
#define R0DE32LZ1	 BUFFER[184]	//(sbk:20 - S02SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 2
#define idR0DE32LZ1	 81	//(sbk:20 - S02SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 2
#define R0DE34LZ1	 BUFFER[186]	//(sbk:20 - S04SBK, DiagnBaz1) диагностика шкафа Баз1 температура меньше 43
#define idR0DE34LZ1	 82	//(sbk:20 - S04SBK, DiagnBaz1) диагностика шкафа Баз1 температура меньше 43
#define R0DE33LZ1	 BUFFER[188]	//(sbk:20 - S03SBK, DiagnBaz1) диагностика шкафа Баз1 двери
#define idR0DE33LZ1	 83	//(sbk:20 - S03SBK, DiagnBaz1) диагностика шкафа Баз1 двери
#define R0DE36LZ1	 BUFFER[190]	//(sbk:20 - S06SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 1
#define idR0DE36LZ1	 84	//(sbk:20 - S06SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 1
#define R0DE37LZ1	 BUFFER[192]	//(sbk:20 - S07SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 2
#define idR0DE37LZ1	 85	//(sbk:20 - S07SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 2
#define R0DE35LZ1	 BUFFER[194]	//(sbk:20 - S05SBK, DiagnBaz1) диагностика шкафа Баз1 температура больше 53
#define idR0DE35LZ1	 86	//(sbk:20 - S05SBK, DiagnBaz1) диагностика шкафа Баз1 температура больше 53
#define R0DE39LZ1	 BUFFER[196]	//(sbk:20 - S09SBK, DiagnBaz1) диагностика шкафа Баз1 МП24-2 место 4
#define idR0DE39LZ1	 87	//(sbk:20 - S09SBK, DiagnBaz1) диагностика шкафа Баз1 МП24-2 место 4
#define R0DE38LZ1	 BUFFER[198]	//(sbk:20 - S08SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3 место 3
#define idR0DE38LZ1	 88	//(sbk:20 - S08SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3 место 3
#define R0DEB1LZ1	 BUFFER[200]	//(sbk:20 - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
#define idR0DEB1LZ1	 89	//(sbk:20 - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
#define R0DEB2LZ1	 BUFFER[202]	//(sbk:20 - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
#define idR0DEB2LZ1	 90	//(sbk:20 - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
#define R0DEB4LZ1	 BUFFER[204]	//(sbk:20 - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
#define idR0DEB4LZ1	 91	//(sbk:20 - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
#define R0DEB3LZ1	 BUFFER[206]	//(sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
#define idR0DEB3LZ1	 92	//(sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
#define A0VP81LZZ	 BUFFER[208]	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define idA0VP81LZZ	 93	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define R0ET02LZ1	 BUFFER[210]	//( - , Baz1) Признак наличия неисправности по температуре АЗ2
#define idR0ET02LZ1	 94	//( - , Baz1) Признак наличия неисправности по температуре АЗ2
#define B0EP02IZ1	 BUFFER[212]	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
#define idB0EP02IZ1	 95	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
#define A0EP02IZ1	 BUFFER[215]	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
#define idA0EP02IZ1	 96	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
#define A0VP71LZ1	 BUFFER[218]	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	 97	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
#define B0VP71LZ1	 BUFFER[220]	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	 98	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
#define R0VN02RS1	 BUFFER[222]	//( - , MBz1A1) Уровень мощности канал 1
#define idR0VN02RS1	 99	//( - , MBz1A1) Уровень мощности канал 1
#define R0VN02RS2	 BUFFER[227]	//( - , MBz1A2) Уровень мощности канал 2
#define idR0VN02RS2	 100	//( - , MBz1A2) Уровень мощности канал 2
#define R0VN02RS3	 BUFFER[232]	//( - , MBz1A3) Уровень мощности канал 3
#define idR0VN02RS3	 101	//( - , MBz1A3) Уровень мощности канал 3
#define R0VN02RS4	 BUFFER[237]	//( - , MBz1A4) Уровень мощности канал 4
#define idR0VN02RS4	 102	//( - , MBz1A4) Уровень мощности канал 4
#define R0VN01RS1	 BUFFER[242]	//( - , MBz1A1) Период разгона канал 1
#define idR0VN01RS1	 103	//( - , MBz1A1) Период разгона канал 1
#define R0VN01RS2	 BUFFER[247]	//( - , MBz1A2) Период разгона канал 2
#define idR0VN01RS2	 104	//( - , MBz1A2) Период разгона канал 2
#define R0VN01RS3	 BUFFER[252]	//( - , MBz1A3) Период разгона канал 3
#define idR0VN01RS3	 105	//( - , MBz1A3) Период разгона канал 3
#define R0VN01RS4	 BUFFER[257]	//( - , MBz1A4) Период разгона канал 4
#define idR0VN01RS4	 106	//( - , MBz1A4) Период разгона канал 4
#define R0VN61LS1	 BUFFER[262]	//( - , MBz1A1) ПС по мощности канал 1
#define idR0VN61LS1	 107	//( - , MBz1A1) ПС по мощности канал 1
#define R0VN61LS2	 BUFFER[264]	//( - , MBz1A2) ПС по мощности канал 2
#define idR0VN61LS2	 108	//( - , MBz1A2) ПС по мощности канал 2
#define R0VN61LS3	 BUFFER[266]	//( - , MBz1A3) ПС по мощности канал 3
#define idR0VN61LS3	 109	//( - , MBz1A3) ПС по мощности канал 3
#define R0VN61LS4	 BUFFER[268]	//( - , MBz1A4) ПС по мощности канал 4
#define idR0VN61LS4	 110	//( - , MBz1A4) ПС по мощности канал 4
#define R0VN65LS1	 BUFFER[270]	//( - , MBz1A1) ПС по периоду разгона канал 1
#define idR0VN65LS1	 111	//( - , MBz1A1) ПС по периоду разгона канал 1
#define R0VN65LS2	 BUFFER[272]	//( - , MBz1A2) ПС по периоду разгона  канал 2
#define idR0VN65LS2	 112	//( - , MBz1A2) ПС по периоду разгона  канал 2
#define R0VN65LS3	 BUFFER[274]	//( - , MBz1A3) ПС по периоду разгона канал 3
#define idR0VN65LS3	 113	//( - , MBz1A3) ПС по периоду разгона канал 3
#define R0VN65LS4	 BUFFER[276]	//( - , MBz1A4) ПС по периоду разгона канал 4
#define idR0VN65LS4	 114	//( - , MBz1A4) ПС по периоду разгона канал 4
#define R0VN01RZ1	 BUFFER[278]	//( - , Baz1) Уровень мощности по каналу 1
#define idR0VN01RZ1	 115	//( - , Baz1) Уровень мощности по каналу 1
#define A0IT01IZ1	 BUFFER[283]	//(vas84:04 - K01VASR, - ) Температура АЗ1-1
#define idA0IT01IZ1	 116	//(vas84:04 - K01VASR, - ) Температура АЗ1-1
#define A0CT01IZ1	 BUFFER[286]	//( - , Baz1, SBz1DU) Температура АЗ1-1
#define idA0CT01IZ1	 117	//( - , Baz1, SBz1DU) Температура АЗ1-1
#define A0VT61LZ1	 BUFFER[291]	//( - , Baz1) ПС по температуре в АЗ1
#define idA0VT61LZ1	 118	//( - , Baz1) ПС по температуре в АЗ1
#define A0VT71LZ1	 BUFFER[293]	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
#define idA0VT71LZ1	 119	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
#define A1VP41LZ1	 BUFFER[295]	//( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	 120	//( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
#define B1VP41LZ1	 BUFFER[297]	//( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	 121	//( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
#define B1VP81LZZ	 BUFFER[299]	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	 122	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define A1VP81LZZ	 BUFFER[301]	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	 123	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define A2VP41LZ1	 BUFFER[303]	//( - , Baz1) Давление СБРОС РБ1 ниже АС
#define idA2VP41LZ1	 124	//( - , Baz1) Давление СБРОС РБ1 ниже АС
#define A2CP01RZ1	 BUFFER[305]	//( - , Baz1) Текущее давление СБРОС РБ1
#define idA2CP01RZ1	 125	//( - , Baz1) Текущее давление СБРОС РБ1
#define A2VP51LZ1	 BUFFER[310]	//( - , Baz1) Давление СБРОС РБ1 ниже ПС
#define idA2VP51LZ1	 126	//( - , Baz1) Давление СБРОС РБ1 ниже ПС
#define B2VP41LZ1	 BUFFER[312]	//( - , Baz1) Давление СБРОС РБ2 ниже АС
#define idB2VP41LZ1	 127	//( - , Baz1) Давление СБРОС РБ2 ниже АС
#define B2CP01RZ1	 BUFFER[314]	//( - , Baz1) Текущее давление СБРОС РБ2
#define idB2CP01RZ1	 128	//( - , Baz1) Текущее давление СБРОС РБ2
#define B2VP51LZ1	 BUFFER[319]	//( - , Baz1) Давление СБРОС РБ2 ниже ПС
#define idB2VP51LZ1	 129	//( - , Baz1) Давление СБРОС РБ2 ниже ПС
#define B2VP81LZ1	 BUFFER[321]	//( - , Baz1) Давление СБРОС РБ2 в норме
#define idB2VP81LZ1	 130	//( - , Baz1) Давление СБРОС РБ2 в норме
#define A2VP81LZ1	 BUFFER[323]	//( - , Baz1) Давление СБРОС РБ1 в норме
#define idA2VP81LZ1	 131	//( - , Baz1) Давление СБРОС РБ1 в норме
#define A2IP01IZ1	 BUFFER[325]	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	 132	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define B2IP01IZ1	 BUFFER[328]	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	 133	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define R0ET01LZ1	 BUFFER[331]	//( - , Baz1) Признак наличия неисправности по температуре  АЗ1
#define idR0ET01LZ1	 134	//( - , Baz1) Признак наличия неисправности по температуре  АЗ1
#define B0IT01IZ1	 BUFFER[333]	//(vas84:04 - K03VASR, - ) Температура АЗ2-1
#define idB0IT01IZ1	 135	//(vas84:04 - K03VASR, - ) Температура АЗ2-1
#define A0VP41LZ1	 BUFFER[336]	//( - , Baz1) Давление АЗ1 ниже АС
#define idA0VP41LZ1	 136	//( - , Baz1) Давление АЗ1 ниже АС
#define B0VP41LZ1	 BUFFER[338]	//( - , Baz1) Давление АЗ2 ниже АС
#define idB0VP41LZ1	 137	//( - , Baz1) Давление АЗ2 ниже АС
#define B0VP81LZZ	 BUFFER[340]	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	 138	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define A3VZ11LZ1	 BUFFER[342]	//( - , Baz1) АЗ от НУП ИС1
#define idA3VZ11LZ1	 139	//( - , Baz1) АЗ от НУП ИС1
#define B3VZ11LZ1	 BUFFER[344]	//( - , Baz1) АЗ от НУП ИС2
#define idB3VZ11LZ1	 140	//( - , Baz1) АЗ от НУП ИС2
#define B3IS22LDU	 BUFFER[346]	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
#define idB3IS22LDU	 141	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
#define R0VN69LZ1	 BUFFER[348]	//( - , Baz1) ПС по усредненному периоду
#define idR0VN69LZ1	 142	//( - , Baz1) ПС по усредненному периоду
#define R0VN79LZ1	 BUFFER[350]	//( - , Baz1) АС по усредненному периоду
#define idR0VN79LZ1	 143	//( - , Baz1) АС по усредненному периоду
#define R0VR02RZ1	 BUFFER[352]	//( - , Baz1) Усредненная реактивность
#define idR0VR02RZ1	 144	//( - , Baz1) Усредненная реактивность
#define R0VZ71LZ1	 BUFFER[357]	//(fds16:0a - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
#define idR0VZ71LZ1	 145	//(fds16:0a - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
#define R0VN70LZ1	 BUFFER[359]	//( - , Baz1) АЗ по АС мощности РУ
#define idR0VN70LZ1	 146	//( - , Baz1) АЗ по АС мощности РУ
#define R0VN80LZ1	 BUFFER[361]	//( - , Baz1) АЗ по АС периода разгона РУ
#define idR0VN80LZ1	 147	//( - , Baz1) АЗ по АС периода разгона РУ
#define A0EE01LS1	 BUFFER[363]	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define idA0EE01LS1	 148	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define A0EE01LS4	 BUFFER[365]	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define idA0EE01LS4	 149	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define A0EE01LS3	 BUFFER[367]	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define idA0EE01LS3	 150	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define A0EE01LZ1	 BUFFER[369]	//( - , Baz1, SBz1DU) Исправность АКНП1
#define idA0EE01LZ1	 151	//( - , Baz1, SBz1DU) Исправность АКНП1
#define A0EE04LZ1	 BUFFER[371]	//( - , Baz1, SBz1DU) Исправность АКНП4
#define idA0EE04LZ1	 152	//( - , Baz1, SBz1DU) Исправность АКНП4
#define A0EE02LZ1	 BUFFER[373]	//( - , Baz1, SBz1DU) Исправность АКНП2
#define idA0EE02LZ1	 153	//( - , Baz1, SBz1DU) Исправность АКНП2
#define A0EE03LZ1	 BUFFER[375]	//( - , Baz1, SBz1DU) Исправность АКНП3
#define idA0EE03LZ1	 154	//( - , Baz1, SBz1DU) Исправность АКНП3
#define A0EE01LS2	 BUFFER[377]	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define idA0EE01LS2	 155	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define A0EE05LZ1	 BUFFER[379]	//( - , Baz1) Исправность сети АКНП1
#define idA0EE05LZ1	 156	//( - , Baz1) Исправность сети АКНП1
#define A0EE06LZ1	 BUFFER[381]	//( - , Baz1) Исправность сети АКНП2
#define idA0EE06LZ1	 157	//( - , Baz1) Исправность сети АКНП2
#define A0EE07LZ1	 BUFFER[383]	//( - , Baz1) Исправность сети АКНП3
#define idA0EE07LZ1	 158	//( - , Baz1) Исправность сети АКНП3
#define A0EE08LZ1	 BUFFER[385]	//( - , Baz1) Исправность сети АКНП4
#define idA0EE08LZ1	 159	//( - , Baz1) Исправность сети АКНП4
#define A0VZ71LZ1	 BUFFER[387]	//( - , Baz1) Обобщенный сигнал АС по АЗ1
#define idA0VZ71LZ1	 160	//( - , Baz1) Обобщенный сигнал АС по АЗ1
#define A0EE00LZ1	 BUFFER[389]	//( - , Baz1) Исправность АКНП АЗ1
#define idA0EE00LZ1	 161	//( - , Baz1) Исправность АКНП АЗ1
#define R0VN02RZ1	 BUFFER[391]	//( - , Baz1) Уровень мощности по каналу 2
#define idR0VN02RZ1	 162	//( - , Baz1) Уровень мощности по каналу 2
#define R0VN03RZ1	 BUFFER[396]	//( - , Baz1) Уровень мощности по каналу 3
#define idR0VN03RZ1	 163	//( - , Baz1) Уровень мощности по каналу 3
#define R0VN04RZ1	 BUFFER[401]	//( - , Baz1) Уровень мощности по каналу 4
#define idR0VN04RZ1	 164	//( - , Baz1) Уровень мощности по каналу 4
#define R0VN05RZ1	 BUFFER[406]	//( - , Baz1) Период разгона по каналу 1
#define idR0VN05RZ1	 165	//( - , Baz1) Период разгона по каналу 1
#define R0VN06RZ1	 BUFFER[411]	//( - , Baz1) Период разгона по каналу 2
#define idR0VN06RZ1	 166	//( - , Baz1) Период разгона по каналу 2
#define R0VN07RZ1	 BUFFER[416]	//( - , Baz1) Период разгона по каналу 3
#define idR0VN07RZ1	 167	//( - , Baz1) Период разгона по каналу 3
#define R0VN08RZ1	 BUFFER[421]	//( - , Baz1) Период разгона по каналу 4
#define idR0VN08RZ1	 168	//( - , Baz1) Период разгона по каналу 4
#define R0VN61LZ1	 BUFFER[426]	//( - , Baz1) ПС по мощности канал 1
#define idR0VN61LZ1	 169	//( - , Baz1) ПС по мощности канал 1
#define R0VN62LZ1	 BUFFER[428]	//( - , Baz1) ПС по мощности канал 2
#define idR0VN62LZ1	 170	//( - , Baz1) ПС по мощности канал 2
#define R0VN63LZ1	 BUFFER[430]	//( - , Baz1) ПС по мощности канал 3
#define idR0VN63LZ1	 171	//( - , Baz1) ПС по мощности канал 3
#define R0VN64LZ1	 BUFFER[432]	//( - , Baz1) ПС по мощности канал 4
#define idR0VN64LZ1	 172	//( - , Baz1) ПС по мощности канал 4
#define R0VN65LZ1	 BUFFER[434]	//( - , Baz1) ПС по периоду разгона канал 1
#define idR0VN65LZ1	 173	//( - , Baz1) ПС по периоду разгона канал 1
#define R0VN66LZ1	 BUFFER[436]	//( - , Baz1) ПС по периоду разгона канал 2
#define idR0VN66LZ1	 174	//( - , Baz1) ПС по периоду разгона канал 2
#define R0VN67LZ1	 BUFFER[438]	//( - , Baz1) ПС по периоду разгона канал 3
#define idR0VN67LZ1	 175	//( - , Baz1) ПС по периоду разгона канал 3
#define R0VN68LZ1	 BUFFER[440]	//( - , Baz1) ПС по периоду разгона канал 4
#define idR0VN68LZ1	 176	//( - , Baz1) ПС по периоду разгона канал 4
#define R0VN09RZ1	 BUFFER[442]	//( - , Baz1) Усредненный период разгона
#define idR0VN09RZ1	 177	//( - , Baz1) Усредненный период разгона
#define A3IS11LDU	 BUFFER[447]	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define idA3IS11LDU	 178	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define A3IS22LDU	 BUFFER[449]	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define idA3IS22LDU	 179	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define R0AD03LZ1	 BUFFER[451]	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define idR0AD03LZ1	 180	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define B3IS11LDU	 BUFFER[453]	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define idB3IS11LDU	 181	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define A3VZ31LZ1	 BUFFER[455]	//( - , Baz1) АЗ от ВУ ИС1
#define idA3VZ31LZ1	 182	//( - , Baz1) АЗ от ВУ ИС1
#define B3VZ31LZ1	 BUFFER[457]	//( - , Baz1) АЗ от ВУ ИС2
#define idB3VZ31LZ1	 183	//( - , Baz1) АЗ от ВУ ИС2
#define R0AD05LZ1	 BUFFER[459]	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define idR0AD05LZ1	 184	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define fEM_R0UT02RZZ	 BUFFER[461]	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	 185	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RZZ	 BUFFER[466]	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	 186	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_A2UP03RZZ	 BUFFER[471]	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define idfEM_A2UP03RZZ	 187	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define fEM_A2UP04RZZ	 BUFFER[476]	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define idfEM_A2UP04RZZ	 188	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define fEM_R0UT72RZZ	 BUFFER[481]	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	 189	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	 BUFFER[486]	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	 190	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	 BUFFER[491]	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	 191	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT61RZZ	 BUFFER[496]	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	 192	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_A2UP41RZZ	 BUFFER[501]	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define idfEM_A2UP41RZZ	 193	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define fEM_A2UP42RZZ	 BUFFER[506]	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define idfEM_A2UP42RZZ	 194	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define fEM_A2UP51RZZ	 BUFFER[511]	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define idfEM_A2UP51RZZ	 195	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define fEM_A2UP81RZZ	 BUFFER[516]	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP81RZZ	 196	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP84RZZ	 BUFFER[521]	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP84RZZ	 197	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP82RZZ	 BUFFER[526]	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP82RZZ	 198	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP52RZZ	 BUFFER[531]	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define idfEM_A2UP52RZZ	 199	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define fEM_A2UP83RZZ	 BUFFER[536]	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP83RZZ	 200	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_R0UR01RZZ	 BUFFER[541]	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RZZ	 201	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R0UR04RZZ	 BUFFER[546]	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define idfEM_R0UR04RZZ	 202	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define fEM_A1UL12RZZ	 BUFFER[551]	//(A1UL12RZZ) Время задержки АЗ от НУП ИС(сек)
#define idfEM_A1UL12RZZ	 203	//(A1UL12RZZ) Время задержки АЗ от НУП ИС(сек)
#define fEM_A1UL11RZZ	 BUFFER[556]	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
#define idfEM_A1UL11RZZ	 204	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
#define fEM_R7UI73RZZ	 BUFFER[561]	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define idfEM_R7UI73RZZ	 205	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define fEM_A1UL13RZZ	 BUFFER[566]	//(A1UL13RZZ) Максимальное время цикла
#define idfEM_A1UL13RZZ	 206	//(A1UL13RZZ) Максимальное время цикла
#define bFirstEnterFlag	 BUFFER[571]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 207	//(bFirstEnterFlag) 
#define internal1_m205_TVuIs1	 BUFFER[573]	//(internal1_m205_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
#define idinternal1_m205_TVuIs1	 208	//(internal1_m205_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
#define internal1_m205_TVuIs2	 BUFFER[578]	//(internal1_m205_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
#define idinternal1_m205_TVuIs2	 209	//(internal1_m205_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
#define internal1_m205_TImVuIs	 BUFFER[583]	//(internal1_m205_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
#define idinternal1_m205_TImVuIs	 210	//(internal1_m205_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
#define internal1_m205_TNupIs1	 BUFFER[588]	//(internal1_m205_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
#define idinternal1_m205_TNupIs1	 211	//(internal1_m205_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
#define internal1_m205_TNupIs2	 BUFFER[593]	//(internal1_m205_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
#define idinternal1_m205_TNupIs2	 212	//(internal1_m205_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
#define internal1_m205_TImNupIs	 BUFFER[598]	//(internal1_m205_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
#define idinternal1_m205_TImNupIs	 213	//(internal1_m205_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
#define internal1_m205_TImAZ2UR	 BUFFER[603]	//(internal1_m205_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
#define idinternal1_m205_TImAZ2UR	 214	//(internal1_m205_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
#define internal1_m205_fef	 BUFFER[608]	//(internal1_m205_fef) fef
#define idinternal1_m205_fef	 215	//(internal1_m205_fef) fef
#define internal1_m109_tx	 BUFFER[610]	//(internal1_m109_tx) tx - время накопленное сек
#define idinternal1_m109_tx	 216	//(internal1_m109_tx) tx - время накопленное сек
#define internal1_m109_y0	 BUFFER[615]	//(internal1_m109_y0) y0
#define idinternal1_m109_y0	 217	//(internal1_m109_y0) y0
#define internal1_m107_tx	 BUFFER[616]	//(internal1_m107_tx) tx - время накопленное сек
#define idinternal1_m107_tx	 218	//(internal1_m107_tx) tx - время накопленное сек
#define internal1_m107_y0	 BUFFER[621]	//(internal1_m107_y0) y0
#define idinternal1_m107_y0	 219	//(internal1_m107_y0) y0
#define internal1_m135_tx	 BUFFER[622]	//(internal1_m135_tx) tx - время накопленное сек
#define idinternal1_m135_tx	 220	//(internal1_m135_tx) tx - время накопленное сек
#define internal1_m135_y0	 BUFFER[627]	//(internal1_m135_y0) y0
#define idinternal1_m135_y0	 221	//(internal1_m135_y0) y0
#define internal1_m134_tx	 BUFFER[628]	//(internal1_m134_tx) tx - время накопленное сек
#define idinternal1_m134_tx	 222	//(internal1_m134_tx) tx - время накопленное сек
#define internal1_m134_y0	 BUFFER[633]	//(internal1_m134_y0) y0
#define idinternal1_m134_y0	 223	//(internal1_m134_y0) y0
#define internal1_m334_sttlf	 BUFFER[634]	//(internal1_m334_sttlf) sttlf - счетчик для вещественного формата
#define idinternal1_m334_sttlf	 224	//(internal1_m334_sttlf) sttlf - счетчик для вещественного формата
#define internal1_m225_tx	 BUFFER[637]	//(internal1_m225_tx) tx - время накопленное сек
#define idinternal1_m225_tx	 225	//(internal1_m225_tx) tx - время накопленное сек
#define internal1_m225_y0	 BUFFER[642]	//(internal1_m225_y0) y0
#define idinternal1_m225_y0	 226	//(internal1_m225_y0) y0
#define internal1_m297_tx	 BUFFER[643]	//(internal1_m297_tx) tx - время накопленное сек
#define idinternal1_m297_tx	 227	//(internal1_m297_tx) tx - время накопленное сек
#define internal1_m297_y0	 BUFFER[648]	//(internal1_m297_y0) y0
#define idinternal1_m297_y0	 228	//(internal1_m297_y0) y0
#define internal1_m33_tx	 BUFFER[649]	//(internal1_m33_tx) tx - внутренний параметр
#define idinternal1_m33_tx	 229	//(internal1_m33_tx) tx - внутренний параметр
#define internal1_m148_y0	 BUFFER[652]	//(internal1_m148_y0) y0
#define idinternal1_m148_y0	 230	//(internal1_m148_y0) y0
#define internal1_m146_y0	 BUFFER[657]	//(internal1_m146_y0) y0
#define idinternal1_m146_y0	 231	//(internal1_m146_y0) y0
#define internal1_m92_y0	 BUFFER[662]	//(internal1_m92_y0) y0
#define idinternal1_m92_y0	 232	//(internal1_m92_y0) y0
#define internal1_m90_y0	 BUFFER[667]	//(internal1_m90_y0) y0
#define idinternal1_m90_y0	 233	//(internal1_m90_y0) y0
#define internal1_m159_y1	 BUFFER[672]	//(internal1_m159_y1) y1 - внутренний параметр
#define idinternal1_m159_y1	 234	//(internal1_m159_y1) y1 - внутренний параметр
#define internal1_m170_y1	 BUFFER[674]	//(internal1_m170_y1) y1 - внутренний параметр
#define idinternal1_m170_y1	 235	//(internal1_m170_y1) y1 - внутренний параметр
#define internal1_m285_q0	 BUFFER[676]	//(internal1_m285_q0) q0 - внутренний параметр
#define idinternal1_m285_q0	 236	//(internal1_m285_q0) q0 - внутренний параметр
#define internal1_m128_y0	 BUFFER[681]	//(internal1_m128_y0) state
#define idinternal1_m128_y0	 237	//(internal1_m128_y0) state
#define internal1_m124_y0	 BUFFER[683]	//(internal1_m124_y0) state
#define idinternal1_m124_y0	 238	//(internal1_m124_y0) state
#define internal1_m105_y1	 BUFFER[685]	//(internal1_m105_y1) y1 - внутренний параметр
#define idinternal1_m105_y1	 239	//(internal1_m105_y1) y1 - внутренний параметр
#define internal1_m121_y1	 BUFFER[687]	//(internal1_m121_y1) y1 - внутренний параметр
#define idinternal1_m121_y1	 240	//(internal1_m121_y1) y1 - внутренний параметр
#define internal1_m94_y1	 BUFFER[689]	//(internal1_m94_y1) y1 - внутренний параметр
#define idinternal1_m94_y1	 241	//(internal1_m94_y1) y1 - внутренний параметр
#define internal1_m103_y1	 BUFFER[691]	//(internal1_m103_y1) y1 - внутренний параметр
#define idinternal1_m103_y1	 242	//(internal1_m103_y1) y1 - внутренний параметр
#define internal1_m157_y1	 BUFFER[693]	//(internal1_m157_y1) y1 - внутренний параметр
#define idinternal1_m157_y1	 243	//(internal1_m157_y1) y1 - внутренний параметр
#define internal1_m167_y1	 BUFFER[695]	//(internal1_m167_y1) y1 - внутренний параметр
#define idinternal1_m167_y1	 244	//(internal1_m167_y1) y1 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &R7II71LZ1},	//(vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
	{ 2	,1	,1	, &R7II72LZ1},	//(vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
	{ 3	,1	,1	, &R0AD14LZ1},	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
	{ 4	,1	,1	, &R0AD21LDU},	//( - , SBz1DU) Подключить защиту от II УР
	{ 5	,1	,1	, &R0AD14LDU},	//( - , Baz1) Имитация срабатывания верхней АС II УР
	{ 6	,1	,1	, &R0MD34LP1},	//( - , Baz1) Кнопка (Квитировать)
	{ 7	,1	,1	, &R0AD04LZ1},	//(vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
	{ 8	,1	,1	, &R0AD16LDU},	//( - , Baz1) Имитация срабатывания верхней АС I УР
	{ 9	,1	,1	, &R0EE01LZ1},	//( - , MBz1S) Питание  АКНП1  отключить
	{ 10	,1	,1	, &R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 11	,1	,1	, &R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 12	,1	,1	, &R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 13	,1	,1	, &R0VN71LZ1},	//(vds32:05 - K01VDSR, Baz1) АС по мощности канал 1
	{ 14	,1	,1	, &R0VN75LZ1},	//(vds32:05 - K02VDSR, Baz1) АС по периоду разгона канал 1
	{ 15	,1	,1	, &R0VN72LZ1},	//(vds32:06 - K01VDSR, Baz1) АС по мощности канал 2
	{ 16	,1	,1	, &R0VN76LZ1},	//(vds32:06 - K02VDSR, Baz1) АС по периоду разгона канал  2
	{ 17	,1	,1	, &R0VN73LZ1},	//(vds32:08 - K01VDSR, Baz1) АС по мощности канал 3
	{ 18	,1	,1	, &R0VN77LZ1},	//(vds32:08 - K02VDSR, Baz1) АС по периоду разгона канал  3
	{ 19	,1	,1	, &R0VN74LZ1},	//(vds32:07 - K01VDSR, Baz1) АС по мощности канал 4
	{ 20	,1	,1	, &R0VN78LZ1},	//(vds32:07 - K02VDSR, Baz1) АС по периоду разгона канал  4
	{ 21	,1	,1	, &R0EE02LZ1},	//( - , MBz1S) Питание  АКНП2  отключить
	{ 22	,1	,1	, &R0EE03LZ1},	//( - , MBz1S) Питание  АКНП3  отключить
	{ 23	,1	,1	, &R0EE04LZ1},	//( - , MBz1S) Питание  АКНП4  отключить
	{ 24	,1	,1	, &B0EE00LZ1},	//( - , Baz1) Исправность АКНП АЗ2
	{ 25	,1	,1	, &B0VZ71LZ1},	//( - , Baz1) Обобщенный сигнал АС по АЗ2
	{ 26	,1	,1	, &A0VN71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
	{ 27	,1	,1	, &B0VN71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
	{ 28	,1	,1	, &A0VN81LZ1},	//( - , Baz1) АЗ по АС периода разгона АЗ1
	{ 29	,1	,1	, &B0VN81LZ1},	//( - , Baz1) АЗ по АС периода разгона АЗ2
	{ 30	,1	,1	, &R0EE02LDU},	//( - , Baz1) Питание  АКНП  отключить
	{ 31	,5	,1	, &R0VZ05UZ1},	//( - , Baz1) Индикатор причины сброса
	{ 32	,8	,1	, &R0VN11RZ1},	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
	{ 33	,1	,1	, &R0VP73LZ1},	//( - , Baz1, SBz1DU) ПС давления для РУ
	{ 34	,8	,1	, &B0CT01IZ1},	//( - , Baz1, SBz1DU) Температура АЗ2-1
	{ 35	,1	,1	, &B0VT61LZ1},	//( - , Baz1) ПС по температуре в АЗ2
	{ 36	,1	,1	, &B0VT71LZ1},	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
	{ 37	,1	,1	, &A0VN71LS1},	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
	{ 38	,1	,1	, &A0VN71LS2},	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
	{ 39	,1	,1	, &A0VN71LS3},	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
	{ 40	,1	,1	, &A0VN71LS4},	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
	{ 41	,1	,1	, &A1VN71LZ1},	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
	{ 42	,1	,1	, &A3VZ15LZ1},	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
	{ 43	,1	,1	, &A3VZ13LZ1},	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
	{ 44	,1	,1	, &R0VW13LDU},	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 45	,1	,1	, &R0VW23LDU},	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 46	,1	,1	, &R7II73LZ1},	//(vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
	{ 47	,1	,1	, &R0DE3CLZ1},	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 5
	{ 48	,1	,1	, &R0DE3DLZ1},	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 6
	{ 49	,1	,1	, &TestDiagnBaz1},	//( - , Baz1) Неисправность от диагностики
	{ 50	,3	,1	, &R0MW11IP1},	//( - , Baz1) Переключатель ВЫСТРЕЛ
	{ 51	,1	,1	, &PS1},	//( - , - ) АЗ по АС любого давления за АЗ1
	{ 52	,1	,1	, &PS2},	//( - , - ) АЗ от ВУ ИС1
	{ 53	,1	,1	, &PS3},	//( - , - ) АЗ от НУП ИС1
	{ 54	,1	,1	, &PS4},	//( - , - ) АС по температуру АЗ1
	{ 55	,1	,1	, &PS5},	//( - , - ) АС по периоду АЗ1
	{ 56	,1	,1	, &PS6},	//( - , - ) АС по мощности АЗ1
	{ 57	,1	,1	, &PS7},	//( - , - ) Исправность АКНП АЗ2
	{ 58	,1	,1	, &PS9},	//( - , - ) АС 1 ур (д2)
	{ 59	,1	,1	, &PS8},	//( - , - ) Исправность АКНП АЗ1
	{ 60	,1	,1	, &PS10},	//( - , - ) АС 1 ур (д1)
	{ 61	,1	,1	, &PS11},	//( - , - ) АС 2 ур
	{ 62	,1	,1	, &PS17},	//( - , - ) Аз по Ас любого давления АЗ2
	{ 63	,1	,1	, &PS16},	//( - , - ) АЗ от НУП ИС2
	{ 64	,1	,1	, &PS15},	//( - , - ) АЗ от ВУ ИС2
	{ 65	,1	,1	, &PS14},	//( - , - ) Ас по температура АЗ2
	{ 66	,1	,1	, &PS13},	//( - , - ) АС по периоду АЗ2
	{ 67	,1	,1	, &PS12},	//( - , - ) Ас по мощности АЗ2
	{ 68	,5	,1	, &R0VZ05U},	//( - , - ) причины сброса
	{ 69	,8	,1	, &B8VC01RDU},	//( - , SBz1DU, MBz1A1, MBz1A2, MBz1A3, MBz1A4) Координата АЗ2, мм
	{ 70	,3	,1	, &R0MW12IP2},	//( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{ 71	,1	,1	, &A2IS12LDU},	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
	{ 72	,1	,1	, &B2IS12LDU},	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
	{ 73	,3	,1	, &R0DE04LZ1},	//(vas84:04 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
	{ 74	,3	,1	, &R0DE05LZ1},	//(vds32:05 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
	{ 75	,3	,1	, &R0DE06LZ1},	//(vds32:06 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
	{ 76	,3	,1	, &R0DE08LZ1},	//(vds32:08 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
	{ 77	,3	,1	, &R0DE07LZ1},	//(vds32:07 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
	{ 78	,3	,1	, &R0DE0ALZ1},	//(fds16:0a - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
	{ 79	,3	,1	, &TTLBaz1},	//( - , Baz1) ttl
	{ 80	,1	,1	, &R0DE31LZ1},	//(sbk:20 - S01SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 1
	{ 81	,1	,1	, &R0DE32LZ1},	//(sbk:20 - S02SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 2
	{ 82	,1	,1	, &R0DE34LZ1},	//(sbk:20 - S04SBK, DiagnBaz1) диагностика шкафа Баз1 температура меньше 43
	{ 83	,1	,1	, &R0DE33LZ1},	//(sbk:20 - S03SBK, DiagnBaz1) диагностика шкафа Баз1 двери
	{ 84	,1	,1	, &R0DE36LZ1},	//(sbk:20 - S06SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 1
	{ 85	,1	,1	, &R0DE37LZ1},	//(sbk:20 - S07SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 2
	{ 86	,1	,1	, &R0DE35LZ1},	//(sbk:20 - S05SBK, DiagnBaz1) диагностика шкафа Баз1 температура больше 53
	{ 87	,1	,1	, &R0DE39LZ1},	//(sbk:20 - S09SBK, DiagnBaz1) диагностика шкафа Баз1 МП24-2 место 4
	{ 88	,1	,1	, &R0DE38LZ1},	//(sbk:20 - S08SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3 место 3
	{ 89	,1	,1	, &R0DEB1LZ1},	//(sbk:20 - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
	{ 90	,1	,1	, &R0DEB2LZ1},	//(sbk:20 - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
	{ 91	,1	,1	, &R0DEB4LZ1},	//(sbk:20 - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
	{ 92	,1	,1	, &R0DEB3LZ1},	//(sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
	{ 93	,1	,1	, &A0VP81LZZ},	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
	{ 94	,1	,1	, &R0ET02LZ1},	//( - , Baz1) Признак наличия неисправности по температуре АЗ2
	{ 95	,3	,1	, &B0EP02IZ1},	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
	{ 96	,3	,1	, &A0EP02IZ1},	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
	{ 97	,1	,1	, &A0VP71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
	{ 98	,1	,1	, &B0VP71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
	{ 99	,8	,1	, &R0VN02RS1},	//( - , MBz1A1) Уровень мощности канал 1
	{ 100	,8	,1	, &R0VN02RS2},	//( - , MBz1A2) Уровень мощности канал 2
	{ 101	,8	,1	, &R0VN02RS3},	//( - , MBz1A3) Уровень мощности канал 3
	{ 102	,8	,1	, &R0VN02RS4},	//( - , MBz1A4) Уровень мощности канал 4
	{ 103	,8	,1	, &R0VN01RS1},	//( - , MBz1A1) Период разгона канал 1
	{ 104	,8	,1	, &R0VN01RS2},	//( - , MBz1A2) Период разгона канал 2
	{ 105	,8	,1	, &R0VN01RS3},	//( - , MBz1A3) Период разгона канал 3
	{ 106	,8	,1	, &R0VN01RS4},	//( - , MBz1A4) Период разгона канал 4
	{ 107	,1	,1	, &R0VN61LS1},	//( - , MBz1A1) ПС по мощности канал 1
	{ 108	,1	,1	, &R0VN61LS2},	//( - , MBz1A2) ПС по мощности канал 2
	{ 109	,1	,1	, &R0VN61LS3},	//( - , MBz1A3) ПС по мощности канал 3
	{ 110	,1	,1	, &R0VN61LS4},	//( - , MBz1A4) ПС по мощности канал 4
	{ 111	,1	,1	, &R0VN65LS1},	//( - , MBz1A1) ПС по периоду разгона канал 1
	{ 112	,1	,1	, &R0VN65LS2},	//( - , MBz1A2) ПС по периоду разгона  канал 2
	{ 113	,1	,1	, &R0VN65LS3},	//( - , MBz1A3) ПС по периоду разгона канал 3
	{ 114	,1	,1	, &R0VN65LS4},	//( - , MBz1A4) ПС по периоду разгона канал 4
	{ 115	,8	,1	, &R0VN01RZ1},	//( - , Baz1) Уровень мощности по каналу 1
	{ 116	,3	,1	, &A0IT01IZ1},	//(vas84:04 - K01VASR, - ) Температура АЗ1-1
	{ 117	,8	,1	, &A0CT01IZ1},	//( - , Baz1, SBz1DU) Температура АЗ1-1
	{ 118	,1	,1	, &A0VT61LZ1},	//( - , Baz1) ПС по температуре в АЗ1
	{ 119	,1	,1	, &A0VT71LZ1},	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
	{ 120	,1	,1	, &A1VP41LZ1},	//( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
	{ 121	,1	,1	, &B1VP41LZ1},	//( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
	{ 122	,1	,1	, &B1VP81LZZ},	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
	{ 123	,1	,1	, &A1VP81LZZ},	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
	{ 124	,1	,1	, &A2VP41LZ1},	//( - , Baz1) Давление СБРОС РБ1 ниже АС
	{ 125	,8	,1	, &A2CP01RZ1},	//( - , Baz1) Текущее давление СБРОС РБ1
	{ 126	,1	,1	, &A2VP51LZ1},	//( - , Baz1) Давление СБРОС РБ1 ниже ПС
	{ 127	,1	,1	, &B2VP41LZ1},	//( - , Baz1) Давление СБРОС РБ2 ниже АС
	{ 128	,8	,1	, &B2CP01RZ1},	//( - , Baz1) Текущее давление СБРОС РБ2
	{ 129	,1	,1	, &B2VP51LZ1},	//( - , Baz1) Давление СБРОС РБ2 ниже ПС
	{ 130	,1	,1	, &B2VP81LZ1},	//( - , Baz1) Давление СБРОС РБ2 в норме
	{ 131	,1	,1	, &A2VP81LZ1},	//( - , Baz1) Давление СБРОС РБ1 в норме
	{ 132	,3	,1	, &A2IP01IZ1},	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
	{ 133	,3	,1	, &B2IP01IZ1},	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
	{ 134	,1	,1	, &R0ET01LZ1},	//( - , Baz1) Признак наличия неисправности по температуре  АЗ1
	{ 135	,3	,1	, &B0IT01IZ1},	//(vas84:04 - K03VASR, - ) Температура АЗ2-1
	{ 136	,1	,1	, &A0VP41LZ1},	//( - , Baz1) Давление АЗ1 ниже АС
	{ 137	,1	,1	, &B0VP41LZ1},	//( - , Baz1) Давление АЗ2 ниже АС
	{ 138	,1	,1	, &B0VP81LZZ},	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
	{ 139	,1	,1	, &A3VZ11LZ1},	//( - , Baz1) АЗ от НУП ИС1
	{ 140	,1	,1	, &B3VZ11LZ1},	//( - , Baz1) АЗ от НУП ИС2
	{ 141	,1	,1	, &B3IS22LDU},	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
	{ 142	,1	,1	, &R0VN69LZ1},	//( - , Baz1) ПС по усредненному периоду
	{ 143	,1	,1	, &R0VN79LZ1},	//( - , Baz1) АС по усредненному периоду
	{ 144	,8	,1	, &R0VR02RZ1},	//( - , Baz1) Усредненная реактивность
	{ 145	,1	,1	, &R0VZ71LZ1},	//(fds16:0a - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
	{ 146	,1	,1	, &R0VN70LZ1},	//( - , Baz1) АЗ по АС мощности РУ
	{ 147	,1	,1	, &R0VN80LZ1},	//( - , Baz1) АЗ по АС периода разгона РУ
	{ 148	,1	,1	, &A0EE01LS1},	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
	{ 149	,1	,1	, &A0EE01LS4},	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
	{ 150	,1	,1	, &A0EE01LS3},	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
	{ 151	,1	,1	, &A0EE01LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП1
	{ 152	,1	,1	, &A0EE04LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП4
	{ 153	,1	,1	, &A0EE02LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП2
	{ 154	,1	,1	, &A0EE03LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП3
	{ 155	,1	,1	, &A0EE01LS2},	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
	{ 156	,1	,1	, &A0EE05LZ1},	//( - , Baz1) Исправность сети АКНП1
	{ 157	,1	,1	, &A0EE06LZ1},	//( - , Baz1) Исправность сети АКНП2
	{ 158	,1	,1	, &A0EE07LZ1},	//( - , Baz1) Исправность сети АКНП3
	{ 159	,1	,1	, &A0EE08LZ1},	//( - , Baz1) Исправность сети АКНП4
	{ 160	,1	,1	, &A0VZ71LZ1},	//( - , Baz1) Обобщенный сигнал АС по АЗ1
	{ 161	,1	,1	, &A0EE00LZ1},	//( - , Baz1) Исправность АКНП АЗ1
	{ 162	,8	,1	, &R0VN02RZ1},	//( - , Baz1) Уровень мощности по каналу 2
	{ 163	,8	,1	, &R0VN03RZ1},	//( - , Baz1) Уровень мощности по каналу 3
	{ 164	,8	,1	, &R0VN04RZ1},	//( - , Baz1) Уровень мощности по каналу 4
	{ 165	,8	,1	, &R0VN05RZ1},	//( - , Baz1) Период разгона по каналу 1
	{ 166	,8	,1	, &R0VN06RZ1},	//( - , Baz1) Период разгона по каналу 2
	{ 167	,8	,1	, &R0VN07RZ1},	//( - , Baz1) Период разгона по каналу 3
	{ 168	,8	,1	, &R0VN08RZ1},	//( - , Baz1) Период разгона по каналу 4
	{ 169	,1	,1	, &R0VN61LZ1},	//( - , Baz1) ПС по мощности канал 1
	{ 170	,1	,1	, &R0VN62LZ1},	//( - , Baz1) ПС по мощности канал 2
	{ 171	,1	,1	, &R0VN63LZ1},	//( - , Baz1) ПС по мощности канал 3
	{ 172	,1	,1	, &R0VN64LZ1},	//( - , Baz1) ПС по мощности канал 4
	{ 173	,1	,1	, &R0VN65LZ1},	//( - , Baz1) ПС по периоду разгона канал 1
	{ 174	,1	,1	, &R0VN66LZ1},	//( - , Baz1) ПС по периоду разгона канал 2
	{ 175	,1	,1	, &R0VN67LZ1},	//( - , Baz1) ПС по периоду разгона канал 3
	{ 176	,1	,1	, &R0VN68LZ1},	//( - , Baz1) ПС по периоду разгона канал 4
	{ 177	,8	,1	, &R0VN09RZ1},	//( - , Baz1) Усредненный период разгона
	{ 178	,1	,1	, &A3IS11LDU},	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
	{ 179	,1	,1	, &A3IS22LDU},	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
	{ 180	,1	,1	, &R0AD03LZ1},	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
	{ 181	,1	,1	, &B3IS11LDU},	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
	{ 182	,1	,1	, &A3VZ31LZ1},	//( - , Baz1) АЗ от ВУ ИС1
	{ 183	,1	,1	, &B3VZ31LZ1},	//( - , Baz1) АЗ от ВУ ИС2
	{ 184	,1	,1	, &R0AD05LZ1},	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
	{ 185	,8	,1	, &fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{ 186	,8	,1	, &fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{ 187	,8	,1	, &fEM_A2UP03RZZ},	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{ 188	,8	,1	, &fEM_A2UP04RZZ},	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{ 189	,8	,1	, &fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{ 190	,8	,1	, &fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{ 191	,8	,1	, &fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{ 192	,8	,1	, &fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{ 193	,8	,1	, &fEM_A2UP41RZZ},	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{ 194	,8	,1	, &fEM_A2UP42RZZ},	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{ 195	,8	,1	, &fEM_A2UP51RZZ},	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{ 196	,8	,1	, &fEM_A2UP81RZZ},	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{ 197	,8	,1	, &fEM_A2UP84RZZ},	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{ 198	,8	,1	, &fEM_A2UP82RZZ},	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{ 199	,8	,1	, &fEM_A2UP52RZZ},	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{ 200	,8	,1	, &fEM_A2UP83RZZ},	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{ 201	,8	,1	, &fEM_R0UR01RZZ},	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
	{ 202	,8	,1	, &fEM_R0UR04RZZ},	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
	{ 203	,8	,1	, &fEM_A1UL12RZZ},	//(A1UL12RZZ) Время задержки АЗ от НУП ИС(сек)
	{ 204	,8	,1	, &fEM_A1UL11RZZ},	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
	{ 205	,8	,1	, &fEM_R7UI73RZZ},	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
	{ 206	,8	,1	, &fEM_A1UL13RZZ},	//(A1UL13RZZ) Максимальное время цикла
	{ 207	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 208	,8	,1	, &internal1_m205_TVuIs1},	//(internal1_m205_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
	{ 209	,8	,1	, &internal1_m205_TVuIs2},	//(internal1_m205_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
	{ 210	,8	,1	, &internal1_m205_TImVuIs},	//(internal1_m205_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
	{ 211	,8	,1	, &internal1_m205_TNupIs1},	//(internal1_m205_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
	{ 212	,8	,1	, &internal1_m205_TNupIs2},	//(internal1_m205_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
	{ 213	,8	,1	, &internal1_m205_TImNupIs},	//(internal1_m205_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
	{ 214	,8	,1	, &internal1_m205_TImAZ2UR},	//(internal1_m205_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
	{ 215	,1	,1	, &internal1_m205_fef},	//(internal1_m205_fef) fef
	{ 216	,8	,1	, &internal1_m109_tx},	//(internal1_m109_tx) tx - время накопленное сек
	{ 217	,18	,1	, &internal1_m109_y0},	//(internal1_m109_y0) y0
	{ 218	,8	,1	, &internal1_m107_tx},	//(internal1_m107_tx) tx - время накопленное сек
	{ 219	,18	,1	, &internal1_m107_y0},	//(internal1_m107_y0) y0
	{ 220	,8	,1	, &internal1_m135_tx},	//(internal1_m135_tx) tx - время накопленное сек
	{ 221	,18	,1	, &internal1_m135_y0},	//(internal1_m135_y0) y0
	{ 222	,8	,1	, &internal1_m134_tx},	//(internal1_m134_tx) tx - время накопленное сек
	{ 223	,18	,1	, &internal1_m134_y0},	//(internal1_m134_y0) y0
	{ 224	,3	,1	, &internal1_m334_sttlf},	//(internal1_m334_sttlf) sttlf - счетчик для вещественного формата
	{ 225	,8	,1	, &internal1_m225_tx},	//(internal1_m225_tx) tx - время накопленное сек
	{ 226	,18	,1	, &internal1_m225_y0},	//(internal1_m225_y0) y0
	{ 227	,8	,1	, &internal1_m297_tx},	//(internal1_m297_tx) tx - время накопленное сек
	{ 228	,18	,1	, &internal1_m297_y0},	//(internal1_m297_y0) y0
	{ 229	,3	,1	, &internal1_m33_tx},	//(internal1_m33_tx) tx - внутренний параметр
	{ 230	,8	,1	, &internal1_m148_y0},	//(internal1_m148_y0) y0
	{ 231	,8	,1	, &internal1_m146_y0},	//(internal1_m146_y0) y0
	{ 232	,8	,1	, &internal1_m92_y0},	//(internal1_m92_y0) y0
	{ 233	,8	,1	, &internal1_m90_y0},	//(internal1_m90_y0) y0
	{ 234	,1	,1	, &internal1_m159_y1},	//(internal1_m159_y1) y1 - внутренний параметр
	{ 235	,1	,1	, &internal1_m170_y1},	//(internal1_m170_y1) y1 - внутренний параметр
	{ 236	,5	,1	, &internal1_m285_q0},	//(internal1_m285_q0) q0 - внутренний параметр
	{ 237	,1	,1	, &internal1_m128_y0},	//(internal1_m128_y0) state
	{ 238	,1	,1	, &internal1_m124_y0},	//(internal1_m124_y0) state
	{ 239	,1	,1	, &internal1_m105_y1},	//(internal1_m105_y1) y1 - внутренний параметр
	{ 240	,1	,1	, &internal1_m121_y1},	//(internal1_m121_y1) y1 - внутренний параметр
	{ 241	,1	,1	, &internal1_m94_y1},	//(internal1_m94_y1) y1 - внутренний параметр
	{ 242	,1	,1	, &internal1_m103_y1},	//(internal1_m103_y1) y1 - внутренний параметр
	{ 243	,1	,1	, &internal1_m157_y1},	//(internal1_m157_y1) y1 - внутренний параметр
	{ 244	,1	,1	, &internal1_m167_y1},	//(internal1_m167_y1) y1 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="baz1.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{185,"fEM_R0UT02RZZ\0"}, 
{186,"fEM_R0UT01RZZ\0"}, 
{187,"fEM_A2UP03RZZ\0"}, 
{188,"fEM_A2UP04RZZ\0"}, 
{189,"fEM_R0UT72RZZ\0"}, 
{190,"fEM_R0UT71RZZ\0"}, 
{191,"fEM_R0UT62RZZ\0"}, 
{192,"fEM_R0UT61RZZ\0"}, 
{193,"fEM_A2UP41RZZ\0"}, 
{194,"fEM_A2UP42RZZ\0"}, 
{195,"fEM_A2UP51RZZ\0"}, 
{196,"fEM_A2UP81RZZ\0"}, 
{197,"fEM_A2UP84RZZ\0"}, 
{198,"fEM_A2UP82RZZ\0"}, 
{199,"fEM_A2UP52RZZ\0"}, 
{200,"fEM_A2UP83RZZ\0"}, 
{201,"fEM_R0UR01RZZ\0"}, 
{202,"fEM_R0UR04RZZ\0"}, 
{203,"fEM_A1UL12RZZ\0"}, 
{204,"fEM_A1UL11RZZ\0"}, 
{205,"fEM_R7UI73RZZ\0"}, 
{206,"fEM_A1UL13RZZ\0"}, 
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
	{&R0DE04LZ1,3,26},
	{&B0IT01IZ1,3,6},
	{&B2IP01IZ1,3,9},
	{&A2IP01IZ1,3,3},
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
	{&R0AD05LZ1,1,16},
	{&R0AD04LZ1,1,14},
	{&R0VN71LZ1,1,0},
	{&R0VN75LZ1,1,2},
	{&A0VN71LS1,1,6},
	{&R0AD03LZ1,1,12},
	{&A3IS22LDU,1,10},
	{&A2IS12LDU,1,18},
	{&B2IS12LDU,1,20},
	{&R0DE05LZ1,3,64},
	{&A3IS11LDU,1,8},
	{&A0EE01LS1,1,4},
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
	{&A0EE01LS2,1,4},
	{&R0DE06LZ1,3,64},
	{&A0VN71LS2,1,6},
	{&B3IS11LDU,1,8},
	{&R0VN76LZ1,1,2},
	{&R0VN72LZ1,1,0},
	{&B3IS22LDU,1,10},
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
	{&R0VN78LZ1,1,2},
	{&R0VN74LZ1,1,0},
	{&R0DE07LZ1,3,64},
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
	{&A0EE01LS3,1,4},
	{&B0VP81LZZ,1,22},
	{&A1VP81LZZ,1,18},
	{&B1VP81LZZ,1,24},
	{&A0VP81LZZ,1,16},
	{&R0DE08LZ1,3,64},
	{&R7II73LZ1,1,12},
	{&A0VN71LS3,1,6},
	{&R0VN77LZ1,1,2},
	{&R0VN73LZ1,1,0},
	{&R7II72LZ1,1,10},
	{&R7II71LZ1,1,8},
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
	{&R0DE31LZ1,1,0},
	{&R0DE32LZ1,1,2},
	{&R0DEB3LZ1,1,22},
	{&R0DE34LZ1,1,6},
	{&R0DEB4LZ1,1,24},
	{&R0DEB2LZ1,1,20},
	{&R0DEB1LZ1,1,18},
	{&R0DE38LZ1,1,14},
	{&R0DE39LZ1,1,16},
	{&R0DE33LZ1,1,4},
	{&R0DE35LZ1,1,8},
	{&R0DE37LZ1,1,12},
	{&R0DE36LZ1,1,10},
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
	setAsFloat(185,600);
	setAsFloat(186,0);
	setAsFloat(187,1.6);
	setAsFloat(188,0);
	setAsFloat(189,150);
	setAsFloat(190,200);
	setAsFloat(191,90);
	setAsFloat(192,100);
	setAsFloat(193,0.1);
	setAsFloat(194,0.13);
	setAsFloat(195,0.16);
	setAsFloat(196,0.17);
	setAsFloat(197,0.31);
	setAsFloat(198,0.2);
	setAsFloat(199,0.19);
	setAsFloat(200,0.28);
	setAsFloat(201,15);
	setAsFloat(202,10);
	setAsFloat(203,0.190);
	setAsFloat(204,0.020);
	setAsFloat(205,0.022);
	setAsFloat(206,0.019);
	setAsBool(10,1);
	setAsBool(11,1);
	setAsBool(12,1);
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
ssbool var19;
ssbool var20;
ssint var21;
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
ssfloat var108;
ssfloat var109;
ssbool var110;
ssfloat var111;
ssfloat var112;
ssbool var113;
ssbool var114;
ssbool var115;
ssbool var116;
ssbool var117;
ssbool var118;
ssfloat var119;
sslong var120;
sslong var121;
ssbool var122;
ssbool var123;
ssbool var124;
ssbool var125;
ssbool var126;
ssbool var127;
ssbool var128;
ssbool var129;
ssbool var130;
ssfloat var131;
ssbool var132;
ssbool var133;
ssfloat var134;
ssbool var135;
ssbool var136;
sschar var137;
ssbool var138;
sschar var139;
ssbool var140;
ssbool var141;
ssbool var142;
ssbool var143;
ssbool var144;
ssbool var145;
ssbool var146;
ssbool var147;
ssbool var148;
ssbool var149;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m347_x_1[6] = {&var18,&var17,&R0DE36LZ1,&R0DE37LZ1,&R0DE38LZ1,&R0DE39LZ1};
psint  array_m334_x_1[6] = {&R0DE04LZ1,&R0DE05LZ1,&R0DE06LZ1,&R0DE0ALZ1,&R0DE08LZ1,&R0DE07LZ1};
psfloat  array_m189_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psfloat  array_m317_x_1[4] = {&R0VN02RS1,&R0VN02RS2,&R0VN02RS3,&R0VN02RS4};
psbool  array_m317_diag_1[4] = {&var26,&var27,&var28,&var29};
psbool  array_m292_x_1[17] = {&var79,&var45,&var46,&var74,&var7,&var4,&var136,&var44,&var40,&var39,&var75,&var8,&var5,&var138,&var43,&var42,&var41};
psbool  array_m16_x_1[6] = {&var84,&var75,&var8,&var5,&var90,&var138};
psbool  array_m36_x_1[6] = {&var74,&var7,&var4,&var136,&var82,&var90};
psfloat  array_m2_x_1[4] = {&R0VN01RS1,&R0VN01RS2,&R0VN01RS3,&R0VN01RS4};
psbool  array_m2_diag_1[4] = {&var26,&var27,&var28,&var29};
psbool  array_m3_x_1[3] = {&var96,&var118,&var24};
psbool  array_m12_x_1[3] = {&var95,&var25,&var97};

/* Объявление структур */
_S_noto  S_noto_223_1 = {&R0AD14LDU,&var1};
_S_and2  S_and2_226_1 = {&var1,&var3,&var2};
_S_or3  S_or3_227_1 = {&var35,&var36,&R7II73LZ1,&var3};
_S_inicn  S_inicn_205_1 = {&A3IS11LDU,&B3IS11LDU,&R0AD03LZ1,&A3IS22LDU,&B3IS22LDU,&R0AD05LZ1,&var35,&var36,&var34,&R0AD14LDU,&fEM_A1UL11RZZ,&fEM_A1UL12RZZ,&fEM_R7UI73RZZ,&fEM_A1UL13RZZ,&var4,&var5,&var6,&var7,&var8,&var9,&var10,&internal1_m205_TVuIs1,&internal1_m205_TVuIs2,&internal1_m205_TImVuIs,&internal1_m205_TNupIs1,&internal1_m205_TNupIs2,&internal1_m205_TImNupIs,&internal1_m205_TImAZ2UR,&internal1_m205_fef};
_S_zzfs  S_zzfs_109_1 = {&B1VP81LZZ,&fRM_10000_,&var11,&internal1_m109_tx,&internal1_m109_y0};
_S_zzfs  S_zzfs_107_1 = {&A1VP81LZZ,&fRM_10000_,&var12,&internal1_m107_tx,&internal1_m107_y0};
_S_zzfs  S_zzfs_135_1 = {&B0VP81LZZ,&fRM_10000_,&var13,&internal1_m135_tx,&internal1_m135_y0};
_S_zzfs  S_zzfs_134_1 = {&A0VP81LZZ,&fRM_10000_,&var14,&internal1_m134_tx,&internal1_m134_y0};
_S_or3  S_or3_348_1 = {&var20,&var19,&var16,&var15};
_S_orn  S_orn_347_1 = {array_m347_x_1,&iRM_6_,&var16};
_S_or2  S_or2_354_1 = {&R0DEB3LZ1,&R0DEB4LZ1,&var17};
_S_or2  S_or2_345_1 = {&R0DEB1LZ1,&R0DEB2LZ1,&var18};
_S_and2  S_and2_336_1 = {&R0DE31LZ1,&R0DE32LZ1,&var19};
_S_diagndev  S_diagndev_334_1 = {array_m334_x_1,&iRM_6_,&var20,&var21,&vainSFloat,&internal1_m334_sttlf};
_S_ma  S_ma_189_1 = {array_m189_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_and2  S_and2_127_1 = {&var141,&var117,&var22};
_S_and2  S_and2_138_1 = {&var140,&var116,&var23};
_S_or2  S_or2_102_1 = {&var147,&var145,&var24};
_S_or2  S_or2_110_1 = {&var142,&var143,&var25};
_S_and2  S_and2_81_1 = {&lRM_1_,&A0EE01LS1,&var26};
_S_and2  S_and2_83_1 = {&lRM_1_,&A0EE01LS2,&var27};
_S_and2  S_and2_85_1 = {&lRM_1_,&A0EE01LS3,&var28};
_S_and2  S_and2_87_1 = {&lRM_1_,&A0EE01LS4,&var29};
_S_and2  S_and2_183_1 = {&var133,&var105,&var30};
_S_and2  S_and2_184_1 = {&var132,&var105,&var31};
_S_or2  S_or2_217_1 = {&R7II73LZ1,&var93,&var32};
_S_or2  S_or2_215_1 = {&R0AD21LDU,&R0AD14LDU,&var33};
_S_and2  S_and2_214_1 = {&var32,&var33,&var34};
_S_or2  S_or2_206_1 = {&var92,&R7II71LZ1,&var35};
_S_or2  S_or2_199_1 = {&var94,&R7II72LZ1,&var36};
_S_schl24  S_schl24_319_1 = {&A0VN71LS2,&A0VN71LS1,&A0VN71LS4,&A0VN71LS3,&var37};
_S_and2  S_and2_305_1 = {&var104,&var103,&var38};
_S_and2  S_and2_294_1 = {&var58,&var80,&var39};
_S_and2  S_and2_296_1 = {&var65,&var80,&var40};
_S_and2  S_and2_302_1 = {&R7II73LZ1,&var91,&var41};
_S_and2  S_and2_301_1 = {&var35,&var91,&var42};
_S_and2  S_and2_300_1 = {&var36,&var91,&var43};
_S_and2  S_and2_298_1 = {&var106,&var80,&var44};
_S_and2  S_and2_295_1 = {&var69,&var80,&var45};
_S_and2  S_and2_293_1 = {&var51,&var80,&var46};
_S_and2  S_and2_266_1 = {&var49,&var48,&var47};
_S_or2  S_or2_268_1 = {&R0VN75LZ1,&var130,&var48};
_S_or2  S_or2_269_1 = {&R0VN77LZ1,&var129,&var49};
_S_or2  S_or2_254_1 = {&var47,&var55,&var50};
_S_or2  S_or2_260_1 = {&var52,&var47,&var51};
_S_and2  S_and2_261_1 = {&var125,&var56,&var52};
_S_or2  S_or2_271_1 = {&R0VN78LZ1,&var127,&var53};
_S_or2  S_or2_270_1 = {&R0VN76LZ1,&var128,&var54};
_S_and2  S_and2_267_1 = {&var54,&var53,&var55};
_S_schl24  S_schl24_265_1 = {&var54,&var53,&var49,&var48,&var56};
_S_and2  S_and2_263_1 = {&var80,&var56,&var57};
_S_or2  S_or2_262_1 = {&var55,&var52,&var58};
_S_and2  S_and2_258_1 = {&var58,&var80,&var59};
_S_or2  S_or2_234_1 = {&R0VN72LZ1,&var128,&var60};
_S_and2  S_and2_249_1 = {&var69,&var80,&var61};
_S_and2  S_and2_238_1 = {&var60,&var63,&var62};
_S_or2  S_or2_235_1 = {&R0VN74LZ1,&var127,&var63};
_S_and2  S_and2_250_1 = {&var65,&var80,&var64};
_S_or2  S_or2_247_1 = {&var62,&var68,&var65};
_S_or2  S_or2_253_1 = {&var70,&var62,&var66};
_S_and2  S_and2_241_1 = {&var72,&var80,&var67};
_S_and2  S_and2_246_1 = {&var126,&var72,&var68};
_S_or2  S_or2_245_1 = {&var70,&var68,&var69};
_S_and2  S_and2_236_1 = {&var71,&var73,&var70};
_S_or2  S_or2_233_1 = {&R0VN73LZ1,&var129,&var71};
_S_schl24  S_schl24_237_1 = {&var71,&var73,&var60,&var63,&var72};
_S_or2  S_or2_232_1 = {&R0VN71LZ1,&var130,&var73};
_S_or2  S_or2_156_1 = {&var110,&var148,&var74};
_S_or2  S_or2_158_1 = {&var115,&var113,&var75};
_S_or2  S_or2_323_1 = {&var146,&var144,&var76};
_S_or2  S_or2_35_1 = {&B2IS12LDU,&A2IS12LDU,&var77};
_S_and2  S_and2_257_1 = {&var80,&var51,&var78};
_S_and2  S_and2_299_1 = {&var107,&var80,&var79};
_S_and2  S_and2_21_1 = {&var102,&var98,&var80};
_S_or2  S_or2_25_1 = {&var123,&var122,&var81};
_S_and2  S_and2_31_1 = {&var83,&var80,&var82};
_S_or3  S_or3_30_1 = {&var51,&var69,&var101,&var83};
_S_and2  S_and2_19_1 = {&var80,&var85,&var84};
_S_or3  S_or3_18_1 = {&var65,&var58,&var100,&var85};
_S_and2  S_and2_6_1 = {&var27,&var29,&var86};
_S_or2  S_or2_10_1 = {&var124,&var86,&var87};
_S_or2  S_or2_9_1 = {&var89,&var124,&var88};
_S_and2  S_and2_5_1 = {&var26,&var28,&var89};
_S_zpfs  S_zpfs_225_1 = {&var2,&fEM_R7UI73RZZ,&var90,&internal1_m225_tx,&internal1_m225_y0};
_S_zpfs  S_zpfs_297_1 = {&var38,&fRM_0_2,&var91,&internal1_m297_tx,&internal1_m297_y0};
_S_noto  S_noto_201_1 = {&R6IS67LZZ,&var92};
_S_noto  S_noto_218_1 = {&R6IS68LZZ,&var93};
_S_noto  S_noto_200_1 = {&R6IS66LZZ,&var94};
_S_noto  S_noto_137_1 = {&var13,&var95};
_S_noto  S_noto_136_1 = {&var14,&var96};
_S_noto  S_noto_112_1 = {&var11,&var97};
_S_noto  S_noto_27_1 = {&var99,&var98};
_S_ovb1  S_ovb1_33_1 = {&var77,&iRM_200_,&var99,&internal1_m33_tx};
_S_noto  S_noto_14_1 = {&var87,&var100};
_S_noto  S_noto_13_1 = {&var88,&var101};
_S_noto  S_noto_24_1 = {&R0EE02LDU,&var102};
_S_noto  S_noto_308_1 = {&R0AD16LDU,&var103};
_S_noto  S_noto_307_1 = {&R0AD04LZ1,&var104};
_S_bol  S_bol_179_1 = {&var134,&fRM_0_00001,&var105};
_S_noto  S_noto_303_1 = {&var87,&var106};
_S_noto  S_noto_304_1 = {&var88,&var107};
_S_scalzz  S_scalzz_148_1 = {&B0IT01IZ1,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var108,&internal1_m148_y0};
_S_scalzz  S_scalzz_146_1 = {&A0IT01IZ1,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var109,&internal1_m146_y0};
_S_geterr  S_geterr_150_1 = {&var109,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var110};
_S_scalzz  S_scalzz_92_1 = {&B2IP01IZ1,&iRM_3276_,&iRM_16383_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var111,&internal1_m92_y0};
_S_scalzz  S_scalzz_90_1 = {&A2IP01IZ1,&iRM_3276_,&iRM_16383_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var112,&internal1_m90_y0};
_S_drg  S_drg_159_1 = {&var108,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var113,&internal1_m159_y1};
_S_drg  S_drg_170_1 = {&var108,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var114,&internal1_m170_y1};
_S_geterr  S_geterr_152_1 = {&var108,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var115};
_S_noto  S_noto_139_1 = {&var142,&var116};
_S_noto  S_noto_126_1 = {&var147,&var117};
_S_noto  S_noto_111_1 = {&var12,&var118};
_S_srm  S_srm_317_1 = {array_m317_x_1,array_m317_diag_1,&iRM_4_,&iRM_3_,&var119,&vainSBool};
_S_rsu  S_rsu_285_1 = {&R0MD34LP1,&var121,&var120,&internal1_m285_q0};
_S_orni  S_orni_292_1 = {array_m292_x_1,&iRM_17_,&vainSBool,&var121};
_S_orn  S_orn_16_1 = {array_m16_x_1,&iRM_6_,&var122};
_S_orn  S_orn_36_1 = {array_m36_x_1,&iRM_6_,&var123};
_S_noto  S_noto_7_1 = {&var135,&var124};
_S_noto  S_noto_256_1 = {&var50,&var125};
_S_noto  S_noto_251_1 = {&var66,&var126};
_S_noto  S_noto_240_1 = {&A0EE01LS4,&var127};
_S_noto  S_noto_244_1 = {&A0EE01LS2,&var128};
_S_noto  S_noto_243_1 = {&A0EE01LS3,&var129};
_S_noto  S_noto_239_1 = {&A0EE01LS1,&var130};
_S_react  S_react_175_1 = {&var134,&var131};
_S_bol  S_bol_180_1 = {&fEM_R0UR04RZZ,&var134,&var132};
_S_bol  S_bol_178_1 = {&fEM_R0UR01RZZ,&var134,&var133};
_S_srm  S_srm_2_1 = {array_m2_x_1,array_m2_diag_1,&iRM_4_,&iRM_3_,&var134,&var135};
_S_ornc  S_ornc_3_1 = {array_m3_x_1,&iRM_3_,&var136,&var137};
_S_ornc  S_ornc_12_1 = {array_m12_x_1,&iRM_3_,&var138,&var139};
_S_tprg  S_tprg_128_1 = {&var111,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var140,&internal1_m128_y0};
_S_tprg  S_tprg_124_1 = {&var112,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var141,&internal1_m124_y0};
_S_geterr  S_geterr_101_1 = {&var111,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var142};
_S_drg  S_drg_105_1 = {&var111,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var143,&internal1_m105_y1};
_S_drg  S_drg_121_1 = {&var111,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var144,&internal1_m121_y1};
_S_drg  S_drg_94_1 = {&var112,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var145,&internal1_m94_y1};
_S_drg  S_drg_103_1 = {&var112,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var146,&internal1_m103_y1};
_S_geterr  S_geterr_98_1 = {&var112,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var147};
_S_drg  S_drg_157_1 = {&var109,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var148,&internal1_m157_y1};
_S_drg  S_drg_167_1 = {&var109,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var149,&internal1_m167_y1};


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
   var21.i=0;
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
   var106.b=0;
   var107.b=0;
   var108.f=0.0;
   var109.f=0.0;
   var110.b=0;
   var111.f=0.0;
   var112.f=0.0;
   var113.b=0;
   var114.b=0;
   var115.b=0;
   var116.b=0;
   var117.b=0;
   var118.b=0;
   var119.f=0.0;
   var120.l=0L;
   var121.l=0L;
   var122.b=0;
   var123.b=0;
   var124.b=0;
   var125.b=0;
   var126.b=0;
   var127.b=0;
   var128.b=0;
   var129.b=0;
   var130.b=0;
   var131.f=0.0;
   var132.b=0;
   var133.b=0;
   var134.f=0.0;
   var135.b=0;
   var136.b=0;
   var137.c=0;
   var138.b=0;
   var139.c=0;
   var140.b=0;
   var141.b=0;
   var142.b=0;
   var143.b=0;
   var144.b=0;
   var145.b=0;
   var146.b=0;
   var147.b=0;
   var148.b=0;
   var149.b=0;
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
  schl24(&S_schl24_319_1);
  or2(&S_or2_199_1);
  or2(&S_or2_206_1);
  or2(&S_or2_215_1);
  or2(&S_or2_217_1);
  ma(&S_ma_189_1);
  and2(&S_and2_336_1);
  or2(&S_or2_345_1);
  or2(&S_or2_354_1);
  orn(&S_orn_347_1);
  zzfs(&S_zzfs_134_1);
  zzfs(&S_zzfs_135_1);
  zzfs(&S_zzfs_107_1);
  zzfs(&S_zzfs_109_1);
  or3(&S_or3_227_1);
  noto(&S_noto_223_1);
  drg(&S_drg_167_1);
  drg(&S_drg_157_1);
  geterr(&S_geterr_98_1);
  drg(&S_drg_103_1);
  drg(&S_drg_94_1);
  drg(&S_drg_121_1);
  drg(&S_drg_105_1);
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
  noto(&S_noto_307_1);
  noto(&S_noto_308_1);
  noto(&S_noto_112_1);
  noto(&S_noto_136_1);
  noto(&S_noto_137_1);
  or2(&S_or2_35_1);
  or2(&S_or2_323_1);
  or2(&S_or2_158_1);
  or2(&S_or2_156_1);
  schl24(&S_schl24_237_1);
  and2(&S_and2_238_1);
  schl24(&S_schl24_265_1);
  and2(&S_and2_267_1);
  or2(&S_or2_254_1);
  and2(&S_and2_305_1);
  and2(&S_and2_214_1);
  and2(&S_and2_87_1);
  and2(&S_and2_85_1);
  and2(&S_and2_83_1);
  and2(&S_and2_81_1);
  or2(&S_or2_110_1);
  or2(&S_or2_102_1);
  and2(&S_and2_138_1);
  and2(&S_and2_127_1);
  diagndev(&S_diagndev_334_1);
  or3(&S_or3_348_1);
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
  srm(&S_srm_317_1);
  bol(&S_bol_179_1);
  ovb1(&S_ovb1_33_1);
  noto(&S_noto_27_1);
  zpfs(&S_zpfs_297_1);
  zpfs(&S_zpfs_225_1);
  and2(&S_and2_5_1);
  or2(&S_or2_9_1);
  and2(&S_and2_6_1);
  and2(&S_and2_21_1);
  and2(&S_and2_241_1);
  or2(&S_or2_253_1);
  and2(&S_and2_263_1);
  and2(&S_and2_261_1);
  or2(&S_or2_260_1);
  and2(&S_and2_293_1);
  and2(&S_and2_300_1);
  and2(&S_and2_301_1);
  and2(&S_and2_302_1);
  and2(&S_and2_184_1);
  and2(&S_and2_183_1);
  noto(&S_noto_251_1);
  noto(&S_noto_304_1);
  noto(&S_noto_13_1);
  or2(&S_or2_10_1);
  and2(&S_and2_299_1);
  and2(&S_and2_257_1);
  and2(&S_and2_246_1);
  or2(&S_or2_247_1);
  and2(&S_and2_250_1);
  or2(&S_or2_262_1);
  and2(&S_and2_296_1);
  and2(&S_and2_294_1);
  noto(&S_noto_303_1);
  noto(&S_noto_14_1);
  or3(&S_or3_18_1);
  and2(&S_and2_19_1);
  or2(&S_or2_245_1);
  and2(&S_and2_249_1);
  and2(&S_and2_258_1);
  and2(&S_and2_295_1);
  and2(&S_and2_298_1);
  orn(&S_orn_16_1);
  orni(&S_orni_292_1);
  rsu(&S_rsu_285_1);
  or3(&S_or3_30_1);
  and2(&S_and2_31_1);
  orn(&S_orn_36_1);
  or2(&S_or2_25_1);
  setData(idR0VZ05U,&var121);
  setData(idPS12,&var65);
  setData(idPS13,&var58);
  setData(idPS14,&var75);
  setData(idPS15,&var5);
  setData(idPS16,&var8);
  setData(idPS17,&var138);
  moveData(idPS11,idR7II73LZ1);
  setData(idPS10,&var35);
  setData(idPS8,&var88);
  setData(idPS9,&var36);
  setData(idPS7,&var87);
  setData(idPS6,&var69);
  setData(idPS5,&var51);
  setData(idPS4,&var74);
  setData(idPS3,&var7);
  setData(idPS2,&var4);
  setData(idPS1,&var136);
  setData(idTestDiagnBaz1,&var15);
  setData(idR0DE3DLZ1,&var17);
  setData(idR0DE3CLZ1,&var18);
  setData(idTTLBaz1,&var21);
  moveData(idR0EE04LZ1,idR0EE02LDU);
  moveData(idR0EE03LZ1,idR0EE02LDU);
  moveData(idR0EE02LZ1,idR0EE02LDU);
  moveData(idR0EE01LZ1,idR0EE02LDU);
  setData(idR0AD14LZ1,&var10);
  setData(idA3VZ13LZ1,&var6);
  setData(idA3VZ15LZ1,&var9);
  setData(idA1VN71LZ1,&var37);
  setData(idB0VT71LZ1,&var75);
  setData(idB0VT61LZ1,&var114);
  setData(idB0CT01IZ1,&var108);
  setData(idR0VP73LZ1,&var76);
  setData(idR0VN11RZ1,&var119);
  setData(idR0VZ05UZ1,&var120);
  setData(idB0VN81LZ1,&var59);
  setData(idA0VN81LZ1,&var78);
  setData(idB0VN71LZ1,&var64);
  setData(idA0VN71LZ1,&var61);
  setData(idB0VZ71LZ1,&var122);
  setData(idB0EE00LZ1,&var87);
  setData(idA0EE00LZ1,&var88);
  setData(idA0VZ71LZ1,&var123);
  setData(idA0EE03LZ1,&var28);
  setData(idA0EE02LZ1,&var27);
  setData(idA0EE04LZ1,&var29);
  setData(idA0EE01LZ1,&var26);
  setData(idR0VN80LZ1,&var57);
  setData(idR0VN70LZ1,&var67);
  setData(idR0VZ71LZ1,&var81);
  setData(idR0VR02RZ1,&var131);
  setData(idR0VN79LZ1,&var31);
  setData(idR0VN69LZ1,&var30);
  setData(idB3VZ11LZ1,&var8);
  setData(idA3VZ11LZ1,&var7);
  setData(idB3VZ31LZ1,&var5);
  setData(idA3VZ31LZ1,&var4);
  setData(idR0VN09RZ1,&var134);
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
  setData(idB0VP71LZ1,&var138);
  setData(idA0VP71LZ1,&var136);
  setData(idA0EP02IZ1,&var137);
  setData(idB0EP02IZ1,&var139);
  setData(idR0ET02LZ1,&var115);
  setData(idB0VP41LZ1,&var95);
  setData(idA0VP41LZ1,&var96);
  setData(idR0ET01LZ1,&var110);
  setData(idA2VP81LZ1,&var22);
  setData(idB2VP81LZ1,&var23);
  setData(idB2VP51LZ1,&var144);
  setData(idB2CP01RZ1,&var111);
  setData(idB2VP41LZ1,&var25);
  setData(idA2VP51LZ1,&var146);
  setData(idA2CP01RZ1,&var112);
  setData(idA2VP41LZ1,&var24);
  setData(idB1VP41LZ1,&var97);
  setData(idA1VP41LZ1,&var118);
  setData(idA0VT71LZ1,&var74);
  setData(idA0VT61LZ1,&var149);
  setData(idA0CT01IZ1,&var109);

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
