#ifndef BAZ1_H
#define BAZ1_H
// Подсистема Baz1:Baz1
static char SimulOn=0;
static short CodeSub=4;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt, taktScheme=0, taktSS=0;
#define SIZE_BUFFER 686
static char BUFFER[686];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.52\0", 5432, "192.168.10.152\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R7II72LZ1	 BUFFER[0]	//(vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
#define idR7II72LZ1	 1	//(vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
#define R0AD14LZ1	 BUFFER[2]	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define idR0AD14LZ1	 2	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define R0AD21LDU	 BUFFER[4]	//( - , SBz1DU) Подключить защиту от II УР
#define idR0AD21LDU	 3	//( - , SBz1DU) Подключить защиту от II УР
#define R0AD14LDU	 BUFFER[6]	//( - , Baz1) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 4	//( - , Baz1) Имитация срабатывания верхней АС II УР
#define R0MD34LP1	 BUFFER[8]	//( - , Baz1) Кнопка (Квитировать)
#define idR0MD34LP1	 5	//( - , Baz1) Кнопка (Квитировать)
#define R0AD04LZ1	 BUFFER[10]	//(vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
#define idR0AD04LZ1	 6	//(vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
#define R0AD16LDU	 BUFFER[12]	//( - , Baz1) Имитация срабатывания верхней АС I УР
#define idR0AD16LDU	 7	//( - , Baz1) Имитация срабатывания верхней АС I УР
#define R0EE01LZ1	 BUFFER[14]	//( - , MBz1S) Питание  АКНП1  отключить
#define idR0EE01LZ1	 8	//( - , MBz1S) Питание  АКНП1  отключить
#define R6IS66LZZ	 BUFFER[16]	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 9	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[18]	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 10	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[20]	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 11	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define R0VN71LZ1	 BUFFER[22]	//(vds32:05 - K01VDSR, Baz1) АС по мощности канал 1
#define idR0VN71LZ1	 12	//(vds32:05 - K01VDSR, Baz1) АС по мощности канал 1
#define R0VN75LZ1	 BUFFER[24]	//(vds32:05 - K02VDSR, Baz1) АС по периоду разгона канал 1
#define idR0VN75LZ1	 13	//(vds32:05 - K02VDSR, Baz1) АС по периоду разгона канал 1
#define R0VN72LZ1	 BUFFER[26]	//(vds32:06 - K01VDSR, Baz1) АС по мощности канал 2
#define idR0VN72LZ1	 14	//(vds32:06 - K01VDSR, Baz1) АС по мощности канал 2
#define R0VN76LZ1	 BUFFER[28]	//(vds32:06 - K02VDSR, Baz1) АС по периоду разгона канал  2
#define idR0VN76LZ1	 15	//(vds32:06 - K02VDSR, Baz1) АС по периоду разгона канал  2
#define R0VN73LZ1	 BUFFER[30]	//(vds32:08 - K01VDSR, Baz1) АС по мощности канал 3
#define idR0VN73LZ1	 16	//(vds32:08 - K01VDSR, Baz1) АС по мощности канал 3
#define R0VN77LZ1	 BUFFER[32]	//(vds32:08 - K02VDSR, Baz1) АС по периоду разгона канал  3
#define idR0VN77LZ1	 17	//(vds32:08 - K02VDSR, Baz1) АС по периоду разгона канал  3
#define R0VN74LZ1	 BUFFER[34]	//(vds32:07 - K01VDSR, Baz1) АС по мощности канал 4
#define idR0VN74LZ1	 18	//(vds32:07 - K01VDSR, Baz1) АС по мощности канал 4
#define R0VN78LZ1	 BUFFER[36]	//(vds32:07 - K02VDSR, Baz1) АС по периоду разгона канал  4
#define idR0VN78LZ1	 19	//(vds32:07 - K02VDSR, Baz1) АС по периоду разгона канал  4
#define R0EE02LZ1	 BUFFER[38]	//( - , MBz1S) Питание  АКНП2  отключить
#define idR0EE02LZ1	 20	//( - , MBz1S) Питание  АКНП2  отключить
#define R0EE03LZ1	 BUFFER[40]	//( - , MBz1S) Питание  АКНП3  отключить
#define idR0EE03LZ1	 21	//( - , MBz1S) Питание  АКНП3  отключить
#define R0EE04LZ1	 BUFFER[42]	//( - , MBz1S) Питание  АКНП4  отключить
#define idR0EE04LZ1	 22	//( - , MBz1S) Питание  АКНП4  отключить
#define R0AD15LZ1	 BUFFER[44]	//( - , Baz1) Имитация АЗ от 1УР (датчик1)
#define idR0AD15LZ1	 23	//( - , Baz1) Имитация АЗ от 1УР (датчик1)
#define B0VZ71LZ1	 BUFFER[46]	//( - , Baz1) Обобщенный сигнал АС по АЗ2
#define idB0VZ71LZ1	 24	//( - , Baz1) Обобщенный сигнал АС по АЗ2
#define A0VN71LZ1	 BUFFER[48]	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
#define idA0VN71LZ1	 25	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
#define B0VN71LZ1	 BUFFER[50]	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
#define idB0VN71LZ1	 26	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
#define A0VN81LZ1	 BUFFER[52]	//( - , Baz1) АЗ по АС периода разгона АЗ1
#define idA0VN81LZ1	 27	//( - , Baz1) АЗ по АС периода разгона АЗ1
#define B0VN81LZ1	 BUFFER[54]	//( - , Baz1) АЗ по АС периода разгона АЗ2
#define idB0VN81LZ1	 28	//( - , Baz1) АЗ по АС периода разгона АЗ2
#define R0EE02LDU	 BUFFER[56]	//( - , Baz1) Питание  АКНП  отключить
#define idR0EE02LDU	 29	//( - , Baz1) Питание  АКНП  отключить
#define R0VZ05UZ1	 BUFFER[58]	//( - , Baz1) Индикатор причины сброса
#define idR0VZ05UZ1	 30	//( - , Baz1) Индикатор причины сброса
#define R0VN11RZ1	 BUFFER[63]	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
#define idR0VN11RZ1	 31	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
#define R0VP73LZ1	 BUFFER[68]	//( - , Baz1, SBz1DU) ПС давления для РУ
#define idR0VP73LZ1	 32	//( - , Baz1, SBz1DU) ПС давления для РУ
#define B0CT01IZ1	 BUFFER[70]	//( - , Baz1, SBz1DU) Температура АЗ2-1
#define idB0CT01IZ1	 33	//( - , Baz1, SBz1DU) Температура АЗ2-1
#define B0VT61LZ1	 BUFFER[75]	//( - , Baz1) ПС по температуре в АЗ2
#define idB0VT61LZ1	 34	//( - , Baz1) ПС по температуре в АЗ2
#define B0VT71LZ1	 BUFFER[77]	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
#define idB0VT71LZ1	 35	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
#define A0VN71LS1	 BUFFER[79]	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
#define idA0VN71LS1	 36	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
#define A0VN71LS2	 BUFFER[81]	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
#define idA0VN71LS2	 37	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
#define A0VN71LS3	 BUFFER[83]	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
#define idA0VN71LS3	 38	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
#define A0VN71LS4	 BUFFER[85]	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
#define idA0VN71LS4	 39	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
#define A1VN71LZ1	 BUFFER[87]	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	 40	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
#define A3VZ15LZ1	 BUFFER[89]	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
#define idA3VZ15LZ1	 41	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
#define A3VZ13LZ1	 BUFFER[91]	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
#define idA3VZ13LZ1	 42	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
#define R0VW13LDU	 BUFFER[93]	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 43	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	 BUFFER[95]	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 44	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R7II73LZ1	 BUFFER[97]	//(vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
#define idR7II73LZ1	 45	//(vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
#define R7II71LZ1	 BUFFER[99]	//(vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
#define idR7II71LZ1	 46	//(vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
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
#define R0AD16LZ1	 BUFFER[154]	//( - , Baz1) Имитация АЗ от 1УР (датчик2)
#define idR0AD16LZ1	 70	//( - , Baz1) Имитация АЗ от 1УР (датчик2)
#define R0MW12IP2	 BUFFER[156]	//( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define idR0MW12IP2	 71	//( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define A2IS12LDU	 BUFFER[159]	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	 72	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define B2IS12LDU	 BUFFER[161]	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	 73	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define R0DE04LZ1	 BUFFER[163]	//(vas84:04 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
#define idR0DE04LZ1	 74	//(vas84:04 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
#define R0DE05LZ1	 BUFFER[166]	//(vds32:05 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
#define idR0DE05LZ1	 75	//(vds32:05 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
#define R0DE06LZ1	 BUFFER[169]	//(vds32:06 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
#define idR0DE06LZ1	 76	//(vds32:06 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
#define R0DE08LZ1	 BUFFER[172]	//(vds32:08 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
#define idR0DE08LZ1	 77	//(vds32:08 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
#define R0DE07LZ1	 BUFFER[175]	//(vds32:07 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
#define idR0DE07LZ1	 78	//(vds32:07 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
#define R0DE0ALZ1	 BUFFER[178]	//(fds16:0a - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
#define idR0DE0ALZ1	 79	//(fds16:0a - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
#define TTLBaz1	 BUFFER[181]	//( - , Baz1) ttl
#define idTTLBaz1	 80	//( - , Baz1) ttl
#define R0DE31LZ1	 BUFFER[184]	//(sbk:20 - S01SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 1
#define idR0DE31LZ1	 81	//(sbk:20 - S01SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 1
#define R0DE32LZ1	 BUFFER[186]	//(sbk:20 - S02SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 2
#define idR0DE32LZ1	 82	//(sbk:20 - S02SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 2
#define R0DE34LZ1	 BUFFER[188]	//(sbk:20 - S04SBK, DiagnBaz1) диагностика шкафа Баз1 температура меньше 43
#define idR0DE34LZ1	 83	//(sbk:20 - S04SBK, DiagnBaz1) диагностика шкафа Баз1 температура меньше 43
#define R0DE33LZ1	 BUFFER[190]	//(sbk:20 - S03SBK, DiagnBaz1) диагностика шкафа Баз1 двери
#define idR0DE33LZ1	 84	//(sbk:20 - S03SBK, DiagnBaz1) диагностика шкафа Баз1 двери
#define R0DE36LZ1	 BUFFER[192]	//(sbk:20 - S06SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 1
#define idR0DE36LZ1	 85	//(sbk:20 - S06SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 1
#define R0DE37LZ1	 BUFFER[194]	//(sbk:20 - S07SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 2
#define idR0DE37LZ1	 86	//(sbk:20 - S07SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 2
#define R0DE35LZ1	 BUFFER[196]	//(sbk:20 - S05SBK, DiagnBaz1) диагностика шкафа Баз1 температура больше 53
#define idR0DE35LZ1	 87	//(sbk:20 - S05SBK, DiagnBaz1) диагностика шкафа Баз1 температура больше 53
#define R0DE39LZ1	 BUFFER[198]	//(sbk:20 - S09SBK, DiagnBaz1) диагностика шкафа Баз1 МП24-2 место 4
#define idR0DE39LZ1	 88	//(sbk:20 - S09SBK, DiagnBaz1) диагностика шкафа Баз1 МП24-2 место 4
#define R0DE38LZ1	 BUFFER[200]	//(sbk:20 - S08SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3 место 3
#define idR0DE38LZ1	 89	//(sbk:20 - S08SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3 место 3
#define R0DEB1LZ1	 BUFFER[202]	//(sbk:20 - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
#define idR0DEB1LZ1	 90	//(sbk:20 - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
#define R0DEB2LZ1	 BUFFER[204]	//(sbk:20 - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
#define idR0DEB2LZ1	 91	//(sbk:20 - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
#define R0DEB4LZ1	 BUFFER[206]	//(sbk:20 - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
#define idR0DEB4LZ1	 92	//(sbk:20 - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
#define R0DEB3LZ1	 BUFFER[208]	//(sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
#define idR0DEB3LZ1	 93	//(sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
#define A0VP81LZZ	 BUFFER[210]	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define idA0VP81LZZ	 94	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define R0ET02LZ1	 BUFFER[212]	//( - , Baz1) Признак наличия неисправности по температуре АЗ2
#define idR0ET02LZ1	 95	//( - , Baz1) Признак наличия неисправности по температуре АЗ2
#define B0EP02IZ1	 BUFFER[214]	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
#define idB0EP02IZ1	 96	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
#define A0EP02IZ1	 BUFFER[217]	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
#define idA0EP02IZ1	 97	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
#define A0VP71LZ1	 BUFFER[220]	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	 98	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
#define B0VP71LZ1	 BUFFER[222]	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	 99	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
#define R0VN02RS1	 BUFFER[224]	//( - , MBz1A1) Уровень мощности канал 1
#define idR0VN02RS1	 100	//( - , MBz1A1) Уровень мощности канал 1
#define R0VN02RS2	 BUFFER[229]	//( - , MBz1A2) Уровень мощности канал 2
#define idR0VN02RS2	 101	//( - , MBz1A2) Уровень мощности канал 2
#define R0VN02RS3	 BUFFER[234]	//( - , MBz1A3) Уровень мощности канал 3
#define idR0VN02RS3	 102	//( - , MBz1A3) Уровень мощности канал 3
#define R0VN02RS4	 BUFFER[239]	//( - , MBz1A4) Уровень мощности канал 4
#define idR0VN02RS4	 103	//( - , MBz1A4) Уровень мощности канал 4
#define R0VN01RS1	 BUFFER[244]	//( - , MBz1A1) Период разгона канал 1
#define idR0VN01RS1	 104	//( - , MBz1A1) Период разгона канал 1
#define R0VN01RS2	 BUFFER[249]	//( - , MBz1A2) Период разгона канал 2
#define idR0VN01RS2	 105	//( - , MBz1A2) Период разгона канал 2
#define R0VN01RS3	 BUFFER[254]	//( - , MBz1A3) Период разгона канал 3
#define idR0VN01RS3	 106	//( - , MBz1A3) Период разгона канал 3
#define R0VN01RS4	 BUFFER[259]	//( - , MBz1A4) Период разгона канал 4
#define idR0VN01RS4	 107	//( - , MBz1A4) Период разгона канал 4
#define R0VN61LS1	 BUFFER[264]	//( - , MBz1A1) ПС по мощности канал 1
#define idR0VN61LS1	 108	//( - , MBz1A1) ПС по мощности канал 1
#define R0VN61LS2	 BUFFER[266]	//( - , MBz1A2) ПС по мощности канал 2
#define idR0VN61LS2	 109	//( - , MBz1A2) ПС по мощности канал 2
#define R0VN61LS3	 BUFFER[268]	//( - , MBz1A3) ПС по мощности канал 3
#define idR0VN61LS3	 110	//( - , MBz1A3) ПС по мощности канал 3
#define R0VN61LS4	 BUFFER[270]	//( - , MBz1A4) ПС по мощности канал 4
#define idR0VN61LS4	 111	//( - , MBz1A4) ПС по мощности канал 4
#define R0VN65LS1	 BUFFER[272]	//( - , MBz1A1) ПС по периоду разгона канал 1
#define idR0VN65LS1	 112	//( - , MBz1A1) ПС по периоду разгона канал 1
#define R0VN65LS2	 BUFFER[274]	//( - , MBz1A2) ПС по периоду разгона  канал 2
#define idR0VN65LS2	 113	//( - , MBz1A2) ПС по периоду разгона  канал 2
#define R0VN65LS3	 BUFFER[276]	//( - , MBz1A3) ПС по периоду разгона канал 3
#define idR0VN65LS3	 114	//( - , MBz1A3) ПС по периоду разгона канал 3
#define R0VN65LS4	 BUFFER[278]	//( - , MBz1A4) ПС по периоду разгона канал 4
#define idR0VN65LS4	 115	//( - , MBz1A4) ПС по периоду разгона канал 4
#define R0VN01RZ1	 BUFFER[280]	//( - , Baz1) Уровень мощности по каналу 1
#define idR0VN01RZ1	 116	//( - , Baz1) Уровень мощности по каналу 1
#define A0IT01IZ1	 BUFFER[285]	//(vas84:04 - K01VASR, - ) Температура АЗ1-1
#define idA0IT01IZ1	 117	//(vas84:04 - K01VASR, - ) Температура АЗ1-1
#define A0CT01IZ1	 BUFFER[288]	//( - , Baz1, SBz1DU) Температура АЗ1-1
#define idA0CT01IZ1	 118	//( - , Baz1, SBz1DU) Температура АЗ1-1
#define A0VT61LZ1	 BUFFER[293]	//( - , Baz1) ПС по температуре в АЗ1
#define idA0VT61LZ1	 119	//( - , Baz1) ПС по температуре в АЗ1
#define A0VT71LZ1	 BUFFER[295]	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
#define idA0VT71LZ1	 120	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
#define A1VP41LZ1	 BUFFER[297]	//( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	 121	//( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
#define B1VP41LZ1	 BUFFER[299]	//( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	 122	//( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
#define B1VP81LZZ	 BUFFER[301]	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	 123	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define A1VP81LZZ	 BUFFER[303]	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	 124	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define A2VP41LZ1	 BUFFER[305]	//( - , Baz1) Давление СБРОС РБ1 ниже АС
#define idA2VP41LZ1	 125	//( - , Baz1) Давление СБРОС РБ1 ниже АС
#define A2CP01RZ1	 BUFFER[307]	//( - , Baz1) Текущее давление СБРОС РБ1
#define idA2CP01RZ1	 126	//( - , Baz1) Текущее давление СБРОС РБ1
#define A2VP51LZ1	 BUFFER[312]	//( - , Baz1) Давление СБРОС РБ1 ниже ПС
#define idA2VP51LZ1	 127	//( - , Baz1) Давление СБРОС РБ1 ниже ПС
#define B2VP41LZ1	 BUFFER[314]	//( - , Baz1) Давление СБРОС РБ2 ниже АС
#define idB2VP41LZ1	 128	//( - , Baz1) Давление СБРОС РБ2 ниже АС
#define B2CP01RZ1	 BUFFER[316]	//( - , Baz1) Текущее давление СБРОС РБ2
#define idB2CP01RZ1	 129	//( - , Baz1) Текущее давление СБРОС РБ2
#define B2VP51LZ1	 BUFFER[321]	//( - , Baz1) Давление СБРОС РБ2 ниже ПС
#define idB2VP51LZ1	 130	//( - , Baz1) Давление СБРОС РБ2 ниже ПС
#define B2VP81LZ1	 BUFFER[323]	//( - , Baz1) Давление СБРОС РБ2 в норме
#define idB2VP81LZ1	 131	//( - , Baz1) Давление СБРОС РБ2 в норме
#define A2VP81LZ1	 BUFFER[325]	//( - , Baz1) Давление СБРОС РБ1 в норме
#define idA2VP81LZ1	 132	//( - , Baz1) Давление СБРОС РБ1 в норме
#define A2IP01IZ1	 BUFFER[327]	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	 133	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define B2IP01IZ1	 BUFFER[330]	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	 134	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define R0ET01LZ1	 BUFFER[333]	//( - , Baz1) Признак наличия неисправности по температуре  АЗ1
#define idR0ET01LZ1	 135	//( - , Baz1) Признак наличия неисправности по температуре  АЗ1
#define B0IT01IZ1	 BUFFER[335]	//(vas84:04 - K03VASR, - ) Температура АЗ2-1
#define idB0IT01IZ1	 136	//(vas84:04 - K03VASR, - ) Температура АЗ2-1
#define A0VP41LZ1	 BUFFER[338]	//( - , Baz1) Давление АЗ1 ниже АС
#define idA0VP41LZ1	 137	//( - , Baz1) Давление АЗ1 ниже АС
#define B0VP41LZ1	 BUFFER[340]	//( - , Baz1) Давление АЗ2 ниже АС
#define idB0VP41LZ1	 138	//( - , Baz1) Давление АЗ2 ниже АС
#define B0VP81LZZ	 BUFFER[342]	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	 139	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
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
#define B0EE00LZ1	 BUFFER[391]	//( - , Baz1) Исправность АКНП АЗ2
#define idB0EE00LZ1	 162	//( - , Baz1) Исправность АКНП АЗ2
#define R0VN02RZ1	 BUFFER[393]	//( - , Baz1) Уровень мощности по каналу 2
#define idR0VN02RZ1	 163	//( - , Baz1) Уровень мощности по каналу 2
#define R0VN03RZ1	 BUFFER[398]	//( - , Baz1) Уровень мощности по каналу 3
#define idR0VN03RZ1	 164	//( - , Baz1) Уровень мощности по каналу 3
#define R0VN04RZ1	 BUFFER[403]	//( - , Baz1) Уровень мощности по каналу 4
#define idR0VN04RZ1	 165	//( - , Baz1) Уровень мощности по каналу 4
#define R0VN05RZ1	 BUFFER[408]	//( - , Baz1) Период разгона по каналу 1
#define idR0VN05RZ1	 166	//( - , Baz1) Период разгона по каналу 1
#define R0VN06RZ1	 BUFFER[413]	//( - , Baz1) Период разгона по каналу 2
#define idR0VN06RZ1	 167	//( - , Baz1) Период разгона по каналу 2
#define R0VN07RZ1	 BUFFER[418]	//( - , Baz1) Период разгона по каналу 3
#define idR0VN07RZ1	 168	//( - , Baz1) Период разгона по каналу 3
#define R0VN08RZ1	 BUFFER[423]	//( - , Baz1) Период разгона по каналу 4
#define idR0VN08RZ1	 169	//( - , Baz1) Период разгона по каналу 4
#define R0VN61LZ1	 BUFFER[428]	//( - , Baz1) ПС по мощности канал 1
#define idR0VN61LZ1	 170	//( - , Baz1) ПС по мощности канал 1
#define R0VN62LZ1	 BUFFER[430]	//( - , Baz1) ПС по мощности канал 2
#define idR0VN62LZ1	 171	//( - , Baz1) ПС по мощности канал 2
#define R0VN63LZ1	 BUFFER[432]	//( - , Baz1) ПС по мощности канал 3
#define idR0VN63LZ1	 172	//( - , Baz1) ПС по мощности канал 3
#define R0VN64LZ1	 BUFFER[434]	//( - , Baz1) ПС по мощности канал 4
#define idR0VN64LZ1	 173	//( - , Baz1) ПС по мощности канал 4
#define R0VN65LZ1	 BUFFER[436]	//( - , Baz1) ПС по периоду разгона канал 1
#define idR0VN65LZ1	 174	//( - , Baz1) ПС по периоду разгона канал 1
#define R0VN66LZ1	 BUFFER[438]	//( - , Baz1) ПС по периоду разгона канал 2
#define idR0VN66LZ1	 175	//( - , Baz1) ПС по периоду разгона канал 2
#define R0VN67LZ1	 BUFFER[440]	//( - , Baz1) ПС по периоду разгона канал 3
#define idR0VN67LZ1	 176	//( - , Baz1) ПС по периоду разгона канал 3
#define R0VN68LZ1	 BUFFER[442]	//( - , Baz1) ПС по периоду разгона канал 4
#define idR0VN68LZ1	 177	//( - , Baz1) ПС по периоду разгона канал 4
#define R0VN09RZ1	 BUFFER[444]	//( - , Baz1, SBz1DU) Усредненный период разгона
#define idR0VN09RZ1	 178	//( - , Baz1, SBz1DU) Усредненный период разгона
#define A3IS11LDU	 BUFFER[449]	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define idA3IS11LDU	 179	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define A3IS22LDU	 BUFFER[451]	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define idA3IS22LDU	 180	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define R0AD03LZ1	 BUFFER[453]	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define idR0AD03LZ1	 181	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define B3IS11LDU	 BUFFER[455]	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define idB3IS11LDU	 182	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define A3VZ31LZ1	 BUFFER[457]	//( - , Baz1) АЗ от ВУ ИС1
#define idA3VZ31LZ1	 183	//( - , Baz1) АЗ от ВУ ИС1
#define B3VZ31LZ1	 BUFFER[459]	//( - , Baz1) АЗ от ВУ ИС2
#define idB3VZ31LZ1	 184	//( - , Baz1) АЗ от ВУ ИС2
#define R0AD05LZ1	 BUFFER[461]	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define idR0AD05LZ1	 185	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define A3VZ11LZ1	 BUFFER[463]	//( - , Baz1) АЗ от НУП ИС1
#define idA3VZ11LZ1	 186	//( - , Baz1) АЗ от НУП ИС1
#define fEM_R0UT02RZZ	 BUFFER[465]	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	 187	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RZZ	 BUFFER[470]	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	 188	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_A2UP03RZZ	 BUFFER[475]	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define idfEM_A2UP03RZZ	 189	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define fEM_A2UP04RZZ	 BUFFER[480]	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define idfEM_A2UP04RZZ	 190	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define fEM_R0UT72RZZ	 BUFFER[485]	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	 191	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	 BUFFER[490]	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	 192	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	 BUFFER[495]	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	 193	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT61RZZ	 BUFFER[500]	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	 194	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_A2UP41RZZ	 BUFFER[505]	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define idfEM_A2UP41RZZ	 195	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define fEM_A2UP42RZZ	 BUFFER[510]	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define idfEM_A2UP42RZZ	 196	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define fEM_A2UP51RZZ	 BUFFER[515]	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define idfEM_A2UP51RZZ	 197	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define fEM_A2UP81RZZ	 BUFFER[520]	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP81RZZ	 198	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP84RZZ	 BUFFER[525]	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP84RZZ	 199	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP82RZZ	 BUFFER[530]	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP82RZZ	 200	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP52RZZ	 BUFFER[535]	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define idfEM_A2UP52RZZ	 201	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define fEM_A2UP83RZZ	 BUFFER[540]	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP83RZZ	 202	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_R0UR01RZZ	 BUFFER[545]	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RZZ	 203	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R0UR04RZZ	 BUFFER[550]	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define idfEM_R0UR04RZZ	 204	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define fEM_A1UL12RZZ	 BUFFER[555]	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
#define idfEM_A1UL12RZZ	 205	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
#define fEM_A1UL11RZZ	 BUFFER[560]	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
#define idfEM_A1UL11RZZ	 206	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
#define fEM_R7UI73RZZ	 BUFFER[565]	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define idfEM_R7UI73RZZ	 207	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define bFirstEnterFlag	 BUFFER[570]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 208	//(bFirstEnterFlag) 
#define internal1_m107_tx	 BUFFER[572]	//(internal1_m107_tx) tx - время накопленное сек
#define idinternal1_m107_tx	 209	//(internal1_m107_tx) tx - время накопленное сек
#define internal1_m107_y0	 BUFFER[577]	//(internal1_m107_y0) y0
#define idinternal1_m107_y0	 210	//(internal1_m107_y0) y0
#define internal1_m106_tx	 BUFFER[578]	//(internal1_m106_tx) tx - время накопленное сек
#define idinternal1_m106_tx	 211	//(internal1_m106_tx) tx - время накопленное сек
#define internal1_m106_y0	 BUFFER[583]	//(internal1_m106_y0) y0
#define idinternal1_m106_y0	 212	//(internal1_m106_y0) y0
#define internal1_m134_tx	 BUFFER[584]	//(internal1_m134_tx) tx - время накопленное сек
#define idinternal1_m134_tx	 213	//(internal1_m134_tx) tx - время накопленное сек
#define internal1_m134_y0	 BUFFER[589]	//(internal1_m134_y0) y0
#define idinternal1_m134_y0	 214	//(internal1_m134_y0) y0
#define internal1_m133_tx	 BUFFER[590]	//(internal1_m133_tx) tx - время накопленное сек
#define idinternal1_m133_tx	 215	//(internal1_m133_tx) tx - время накопленное сек
#define internal1_m133_y0	 BUFFER[595]	//(internal1_m133_y0) y0
#define idinternal1_m133_y0	 216	//(internal1_m133_y0) y0
#define internal1_m248_tx	 BUFFER[596]	//(internal1_m248_tx) tx - время накопленное сек
#define idinternal1_m248_tx	 217	//(internal1_m248_tx) tx - время накопленное сек
#define internal1_m248_y0	 BUFFER[601]	//(internal1_m248_y0) y0
#define idinternal1_m248_y0	 218	//(internal1_m248_y0) y0
#define internal1_m256_tx	 BUFFER[602]	//(internal1_m256_tx) tx - время накопленное сек
#define idinternal1_m256_tx	 219	//(internal1_m256_tx) tx - время накопленное сек
#define internal1_m256_y0	 BUFFER[607]	//(internal1_m256_y0) y0
#define idinternal1_m256_y0	 220	//(internal1_m256_y0) y0
#define internal1_m332_tx	 BUFFER[608]	//(internal1_m332_tx) tx - время накопленное сек
#define idinternal1_m332_tx	 221	//(internal1_m332_tx) tx - время накопленное сек
#define internal1_m332_y0	 BUFFER[613]	//(internal1_m332_y0) y0
#define idinternal1_m332_y0	 222	//(internal1_m332_y0) y0
#define internal1_m215_tx	 BUFFER[614]	//(internal1_m215_tx) tx - время накопленное сек
#define idinternal1_m215_tx	 223	//(internal1_m215_tx) tx - время накопленное сек
#define internal1_m215_y0	 BUFFER[619]	//(internal1_m215_y0) y0
#define idinternal1_m215_y0	 224	//(internal1_m215_y0) y0
#define internal1_m214_tx	 BUFFER[620]	//(internal1_m214_tx) tx - время накопленное сек
#define idinternal1_m214_tx	 225	//(internal1_m214_tx) tx - время накопленное сек
#define internal1_m214_y0	 BUFFER[625]	//(internal1_m214_y0) y0
#define idinternal1_m214_y0	 226	//(internal1_m214_y0) y0
#define internal1_m212_tx	 BUFFER[626]	//(internal1_m212_tx) tx - время накопленное сек
#define idinternal1_m212_tx	 227	//(internal1_m212_tx) tx - время накопленное сек
#define internal1_m212_y0	 BUFFER[631]	//(internal1_m212_y0) y0
#define idinternal1_m212_y0	 228	//(internal1_m212_y0) y0
#define internal1_m210_tx	 BUFFER[632]	//(internal1_m210_tx) tx - время накопленное сек
#define idinternal1_m210_tx	 229	//(internal1_m210_tx) tx - время накопленное сек
#define internal1_m210_y0	 BUFFER[637]	//(internal1_m210_y0) y0
#define idinternal1_m210_y0	 230	//(internal1_m210_y0) y0
#define internal1_m33_tx	 BUFFER[638]	//(internal1_m33_tx) tx - внутренний параметр
#define idinternal1_m33_tx	 231	//(internal1_m33_tx) tx - внутренний параметр
#define internal1_m147_y0	 BUFFER[641]	//(internal1_m147_y0) y0
#define idinternal1_m147_y0	 232	//(internal1_m147_y0) y0
#define internal1_m145_y0	 BUFFER[646]	//(internal1_m145_y0) y0
#define idinternal1_m145_y0	 233	//(internal1_m145_y0) y0
#define internal1_m91_y0	 BUFFER[651]	//(internal1_m91_y0) y0
#define idinternal1_m91_y0	 234	//(internal1_m91_y0) y0
#define internal1_m89_y0	 BUFFER[656]	//(internal1_m89_y0) y0
#define idinternal1_m89_y0	 235	//(internal1_m89_y0) y0
#define internal1_m158_y1	 BUFFER[661]	//(internal1_m158_y1) y1 - внутренний параметр
#define idinternal1_m158_y1	 236	//(internal1_m158_y1) y1 - внутренний параметр
#define internal1_m169_y1	 BUFFER[663]	//(internal1_m169_y1) y1 - внутренний параметр
#define idinternal1_m169_y1	 237	//(internal1_m169_y1) y1 - внутренний параметр
#define internal1_m320_q0	 BUFFER[665]	//(internal1_m320_q0) q0 - внутренний параметр
#define idinternal1_m320_q0	 238	//(internal1_m320_q0) q0 - внутренний параметр
#define internal1_m127_y0	 BUFFER[670]	//(internal1_m127_y0) state
#define idinternal1_m127_y0	 239	//(internal1_m127_y0) state
#define internal1_m123_y0	 BUFFER[672]	//(internal1_m123_y0) state
#define idinternal1_m123_y0	 240	//(internal1_m123_y0) state
#define internal1_m105_y1	 BUFFER[674]	//(internal1_m105_y1) y1 - внутренний параметр
#define idinternal1_m105_y1	 241	//(internal1_m105_y1) y1 - внутренний параметр
#define internal1_m116_y1	 BUFFER[676]	//(internal1_m116_y1) y1 - внутренний параметр
#define idinternal1_m116_y1	 242	//(internal1_m116_y1) y1 - внутренний параметр
#define internal1_m93_y1	 BUFFER[678]	//(internal1_m93_y1) y1 - внутренний параметр
#define idinternal1_m93_y1	 243	//(internal1_m93_y1) y1 - внутренний параметр
#define internal1_m103_y1	 BUFFER[680]	//(internal1_m103_y1) y1 - внутренний параметр
#define idinternal1_m103_y1	 244	//(internal1_m103_y1) y1 - внутренний параметр
#define internal1_m155_y1	 BUFFER[682]	//(internal1_m155_y1) y1 - внутренний параметр
#define idinternal1_m155_y1	 245	//(internal1_m155_y1) y1 - внутренний параметр
#define internal1_m165_y1	 BUFFER[684]	//(internal1_m165_y1) y1 - внутренний параметр
#define idinternal1_m165_y1	 246	//(internal1_m165_y1) y1 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &R7II72LZ1},	//(vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
	{ 2	,1	,1	, &R0AD14LZ1},	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
	{ 3	,1	,1	, &R0AD21LDU},	//( - , SBz1DU) Подключить защиту от II УР
	{ 4	,1	,1	, &R0AD14LDU},	//( - , Baz1) Имитация срабатывания верхней АС II УР
	{ 5	,1	,1	, &R0MD34LP1},	//( - , Baz1) Кнопка (Квитировать)
	{ 6	,1	,1	, &R0AD04LZ1},	//(vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
	{ 7	,1	,1	, &R0AD16LDU},	//( - , Baz1) Имитация срабатывания верхней АС I УР
	{ 8	,1	,1	, &R0EE01LZ1},	//( - , MBz1S) Питание  АКНП1  отключить
	{ 9	,1	,1	, &R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 10	,1	,1	, &R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 11	,1	,1	, &R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 12	,1	,1	, &R0VN71LZ1},	//(vds32:05 - K01VDSR, Baz1) АС по мощности канал 1
	{ 13	,1	,1	, &R0VN75LZ1},	//(vds32:05 - K02VDSR, Baz1) АС по периоду разгона канал 1
	{ 14	,1	,1	, &R0VN72LZ1},	//(vds32:06 - K01VDSR, Baz1) АС по мощности канал 2
	{ 15	,1	,1	, &R0VN76LZ1},	//(vds32:06 - K02VDSR, Baz1) АС по периоду разгона канал  2
	{ 16	,1	,1	, &R0VN73LZ1},	//(vds32:08 - K01VDSR, Baz1) АС по мощности канал 3
	{ 17	,1	,1	, &R0VN77LZ1},	//(vds32:08 - K02VDSR, Baz1) АС по периоду разгона канал  3
	{ 18	,1	,1	, &R0VN74LZ1},	//(vds32:07 - K01VDSR, Baz1) АС по мощности канал 4
	{ 19	,1	,1	, &R0VN78LZ1},	//(vds32:07 - K02VDSR, Baz1) АС по периоду разгона канал  4
	{ 20	,1	,1	, &R0EE02LZ1},	//( - , MBz1S) Питание  АКНП2  отключить
	{ 21	,1	,1	, &R0EE03LZ1},	//( - , MBz1S) Питание  АКНП3  отключить
	{ 22	,1	,1	, &R0EE04LZ1},	//( - , MBz1S) Питание  АКНП4  отключить
	{ 23	,1	,1	, &R0AD15LZ1},	//( - , Baz1) Имитация АЗ от 1УР (датчик1)
	{ 24	,1	,1	, &B0VZ71LZ1},	//( - , Baz1) Обобщенный сигнал АС по АЗ2
	{ 25	,1	,1	, &A0VN71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
	{ 26	,1	,1	, &B0VN71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
	{ 27	,1	,1	, &A0VN81LZ1},	//( - , Baz1) АЗ по АС периода разгона АЗ1
	{ 28	,1	,1	, &B0VN81LZ1},	//( - , Baz1) АЗ по АС периода разгона АЗ2
	{ 29	,1	,1	, &R0EE02LDU},	//( - , Baz1) Питание  АКНП  отключить
	{ 30	,5	,1	, &R0VZ05UZ1},	//( - , Baz1) Индикатор причины сброса
	{ 31	,8	,1	, &R0VN11RZ1},	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
	{ 32	,1	,1	, &R0VP73LZ1},	//( - , Baz1, SBz1DU) ПС давления для РУ
	{ 33	,8	,1	, &B0CT01IZ1},	//( - , Baz1, SBz1DU) Температура АЗ2-1
	{ 34	,1	,1	, &B0VT61LZ1},	//( - , Baz1) ПС по температуре в АЗ2
	{ 35	,1	,1	, &B0VT71LZ1},	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
	{ 36	,1	,1	, &A0VN71LS1},	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
	{ 37	,1	,1	, &A0VN71LS2},	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
	{ 38	,1	,1	, &A0VN71LS3},	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
	{ 39	,1	,1	, &A0VN71LS4},	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
	{ 40	,1	,1	, &A1VN71LZ1},	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
	{ 41	,1	,1	, &A3VZ15LZ1},	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
	{ 42	,1	,1	, &A3VZ13LZ1},	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
	{ 43	,1	,1	, &R0VW13LDU},	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 44	,1	,1	, &R0VW23LDU},	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 45	,1	,1	, &R7II73LZ1},	//(vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
	{ 46	,1	,1	, &R7II71LZ1},	//(vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
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
	{ 70	,1	,1	, &R0AD16LZ1},	//( - , Baz1) Имитация АЗ от 1УР (датчик2)
	{ 71	,3	,1	, &R0MW12IP2},	//( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{ 72	,1	,1	, &A2IS12LDU},	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
	{ 73	,1	,1	, &B2IS12LDU},	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
	{ 74	,3	,1	, &R0DE04LZ1},	//(vas84:04 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
	{ 75	,3	,1	, &R0DE05LZ1},	//(vds32:05 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
	{ 76	,3	,1	, &R0DE06LZ1},	//(vds32:06 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
	{ 77	,3	,1	, &R0DE08LZ1},	//(vds32:08 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
	{ 78	,3	,1	, &R0DE07LZ1},	//(vds32:07 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
	{ 79	,3	,1	, &R0DE0ALZ1},	//(fds16:0a - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
	{ 80	,3	,1	, &TTLBaz1},	//( - , Baz1) ttl
	{ 81	,1	,1	, &R0DE31LZ1},	//(sbk:20 - S01SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 1
	{ 82	,1	,1	, &R0DE32LZ1},	//(sbk:20 - S02SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 2
	{ 83	,1	,1	, &R0DE34LZ1},	//(sbk:20 - S04SBK, DiagnBaz1) диагностика шкафа Баз1 температура меньше 43
	{ 84	,1	,1	, &R0DE33LZ1},	//(sbk:20 - S03SBK, DiagnBaz1) диагностика шкафа Баз1 двери
	{ 85	,1	,1	, &R0DE36LZ1},	//(sbk:20 - S06SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 1
	{ 86	,1	,1	, &R0DE37LZ1},	//(sbk:20 - S07SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 2
	{ 87	,1	,1	, &R0DE35LZ1},	//(sbk:20 - S05SBK, DiagnBaz1) диагностика шкафа Баз1 температура больше 53
	{ 88	,1	,1	, &R0DE39LZ1},	//(sbk:20 - S09SBK, DiagnBaz1) диагностика шкафа Баз1 МП24-2 место 4
	{ 89	,1	,1	, &R0DE38LZ1},	//(sbk:20 - S08SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3 место 3
	{ 90	,1	,1	, &R0DEB1LZ1},	//(sbk:20 - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
	{ 91	,1	,1	, &R0DEB2LZ1},	//(sbk:20 - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
	{ 92	,1	,1	, &R0DEB4LZ1},	//(sbk:20 - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
	{ 93	,1	,1	, &R0DEB3LZ1},	//(sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
	{ 94	,1	,1	, &A0VP81LZZ},	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
	{ 95	,1	,1	, &R0ET02LZ1},	//( - , Baz1) Признак наличия неисправности по температуре АЗ2
	{ 96	,3	,1	, &B0EP02IZ1},	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
	{ 97	,3	,1	, &A0EP02IZ1},	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
	{ 98	,1	,1	, &A0VP71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
	{ 99	,1	,1	, &B0VP71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
	{ 100	,8	,1	, &R0VN02RS1},	//( - , MBz1A1) Уровень мощности канал 1
	{ 101	,8	,1	, &R0VN02RS2},	//( - , MBz1A2) Уровень мощности канал 2
	{ 102	,8	,1	, &R0VN02RS3},	//( - , MBz1A3) Уровень мощности канал 3
	{ 103	,8	,1	, &R0VN02RS4},	//( - , MBz1A4) Уровень мощности канал 4
	{ 104	,8	,1	, &R0VN01RS1},	//( - , MBz1A1) Период разгона канал 1
	{ 105	,8	,1	, &R0VN01RS2},	//( - , MBz1A2) Период разгона канал 2
	{ 106	,8	,1	, &R0VN01RS3},	//( - , MBz1A3) Период разгона канал 3
	{ 107	,8	,1	, &R0VN01RS4},	//( - , MBz1A4) Период разгона канал 4
	{ 108	,1	,1	, &R0VN61LS1},	//( - , MBz1A1) ПС по мощности канал 1
	{ 109	,1	,1	, &R0VN61LS2},	//( - , MBz1A2) ПС по мощности канал 2
	{ 110	,1	,1	, &R0VN61LS3},	//( - , MBz1A3) ПС по мощности канал 3
	{ 111	,1	,1	, &R0VN61LS4},	//( - , MBz1A4) ПС по мощности канал 4
	{ 112	,1	,1	, &R0VN65LS1},	//( - , MBz1A1) ПС по периоду разгона канал 1
	{ 113	,1	,1	, &R0VN65LS2},	//( - , MBz1A2) ПС по периоду разгона  канал 2
	{ 114	,1	,1	, &R0VN65LS3},	//( - , MBz1A3) ПС по периоду разгона канал 3
	{ 115	,1	,1	, &R0VN65LS4},	//( - , MBz1A4) ПС по периоду разгона канал 4
	{ 116	,8	,1	, &R0VN01RZ1},	//( - , Baz1) Уровень мощности по каналу 1
	{ 117	,3	,1	, &A0IT01IZ1},	//(vas84:04 - K01VASR, - ) Температура АЗ1-1
	{ 118	,8	,1	, &A0CT01IZ1},	//( - , Baz1, SBz1DU) Температура АЗ1-1
	{ 119	,1	,1	, &A0VT61LZ1},	//( - , Baz1) ПС по температуре в АЗ1
	{ 120	,1	,1	, &A0VT71LZ1},	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
	{ 121	,1	,1	, &A1VP41LZ1},	//( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
	{ 122	,1	,1	, &B1VP41LZ1},	//( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
	{ 123	,1	,1	, &B1VP81LZZ},	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
	{ 124	,1	,1	, &A1VP81LZZ},	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
	{ 125	,1	,1	, &A2VP41LZ1},	//( - , Baz1) Давление СБРОС РБ1 ниже АС
	{ 126	,8	,1	, &A2CP01RZ1},	//( - , Baz1) Текущее давление СБРОС РБ1
	{ 127	,1	,1	, &A2VP51LZ1},	//( - , Baz1) Давление СБРОС РБ1 ниже ПС
	{ 128	,1	,1	, &B2VP41LZ1},	//( - , Baz1) Давление СБРОС РБ2 ниже АС
	{ 129	,8	,1	, &B2CP01RZ1},	//( - , Baz1) Текущее давление СБРОС РБ2
	{ 130	,1	,1	, &B2VP51LZ1},	//( - , Baz1) Давление СБРОС РБ2 ниже ПС
	{ 131	,1	,1	, &B2VP81LZ1},	//( - , Baz1) Давление СБРОС РБ2 в норме
	{ 132	,1	,1	, &A2VP81LZ1},	//( - , Baz1) Давление СБРОС РБ1 в норме
	{ 133	,3	,1	, &A2IP01IZ1},	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
	{ 134	,3	,1	, &B2IP01IZ1},	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
	{ 135	,1	,1	, &R0ET01LZ1},	//( - , Baz1) Признак наличия неисправности по температуре  АЗ1
	{ 136	,3	,1	, &B0IT01IZ1},	//(vas84:04 - K03VASR, - ) Температура АЗ2-1
	{ 137	,1	,1	, &A0VP41LZ1},	//( - , Baz1) Давление АЗ1 ниже АС
	{ 138	,1	,1	, &B0VP41LZ1},	//( - , Baz1) Давление АЗ2 ниже АС
	{ 139	,1	,1	, &B0VP81LZZ},	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
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
	{ 162	,1	,1	, &B0EE00LZ1},	//( - , Baz1) Исправность АКНП АЗ2
	{ 163	,8	,1	, &R0VN02RZ1},	//( - , Baz1) Уровень мощности по каналу 2
	{ 164	,8	,1	, &R0VN03RZ1},	//( - , Baz1) Уровень мощности по каналу 3
	{ 165	,8	,1	, &R0VN04RZ1},	//( - , Baz1) Уровень мощности по каналу 4
	{ 166	,8	,1	, &R0VN05RZ1},	//( - , Baz1) Период разгона по каналу 1
	{ 167	,8	,1	, &R0VN06RZ1},	//( - , Baz1) Период разгона по каналу 2
	{ 168	,8	,1	, &R0VN07RZ1},	//( - , Baz1) Период разгона по каналу 3
	{ 169	,8	,1	, &R0VN08RZ1},	//( - , Baz1) Период разгона по каналу 4
	{ 170	,1	,1	, &R0VN61LZ1},	//( - , Baz1) ПС по мощности канал 1
	{ 171	,1	,1	, &R0VN62LZ1},	//( - , Baz1) ПС по мощности канал 2
	{ 172	,1	,1	, &R0VN63LZ1},	//( - , Baz1) ПС по мощности канал 3
	{ 173	,1	,1	, &R0VN64LZ1},	//( - , Baz1) ПС по мощности канал 4
	{ 174	,1	,1	, &R0VN65LZ1},	//( - , Baz1) ПС по периоду разгона канал 1
	{ 175	,1	,1	, &R0VN66LZ1},	//( - , Baz1) ПС по периоду разгона канал 2
	{ 176	,1	,1	, &R0VN67LZ1},	//( - , Baz1) ПС по периоду разгона канал 3
	{ 177	,1	,1	, &R0VN68LZ1},	//( - , Baz1) ПС по периоду разгона канал 4
	{ 178	,8	,1	, &R0VN09RZ1},	//( - , Baz1, SBz1DU) Усредненный период разгона
	{ 179	,1	,1	, &A3IS11LDU},	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
	{ 180	,1	,1	, &A3IS22LDU},	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
	{ 181	,1	,1	, &R0AD03LZ1},	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
	{ 182	,1	,1	, &B3IS11LDU},	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
	{ 183	,1	,1	, &A3VZ31LZ1},	//( - , Baz1) АЗ от ВУ ИС1
	{ 184	,1	,1	, &B3VZ31LZ1},	//( - , Baz1) АЗ от ВУ ИС2
	{ 185	,1	,1	, &R0AD05LZ1},	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
	{ 186	,1	,1	, &A3VZ11LZ1},	//( - , Baz1) АЗ от НУП ИС1
	{ 187	,8	,1	, &fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{ 188	,8	,1	, &fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{ 189	,8	,1	, &fEM_A2UP03RZZ},	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{ 190	,8	,1	, &fEM_A2UP04RZZ},	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{ 191	,8	,1	, &fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{ 192	,8	,1	, &fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{ 193	,8	,1	, &fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{ 194	,8	,1	, &fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{ 195	,8	,1	, &fEM_A2UP41RZZ},	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{ 196	,8	,1	, &fEM_A2UP42RZZ},	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{ 197	,8	,1	, &fEM_A2UP51RZZ},	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{ 198	,8	,1	, &fEM_A2UP81RZZ},	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{ 199	,8	,1	, &fEM_A2UP84RZZ},	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{ 200	,8	,1	, &fEM_A2UP82RZZ},	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{ 201	,8	,1	, &fEM_A2UP52RZZ},	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{ 202	,8	,1	, &fEM_A2UP83RZZ},	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{ 203	,8	,1	, &fEM_R0UR01RZZ},	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
	{ 204	,8	,1	, &fEM_R0UR04RZZ},	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
	{ 205	,8	,1	, &fEM_A1UL12RZZ},	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
	{ 206	,8	,1	, &fEM_A1UL11RZZ},	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
	{ 207	,8	,1	, &fEM_R7UI73RZZ},	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
	{ 208	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 209	,8	,1	, &internal1_m107_tx},	//(internal1_m107_tx) tx - время накопленное сек
	{ 210	,18	,1	, &internal1_m107_y0},	//(internal1_m107_y0) y0
	{ 211	,8	,1	, &internal1_m106_tx},	//(internal1_m106_tx) tx - время накопленное сек
	{ 212	,18	,1	, &internal1_m106_y0},	//(internal1_m106_y0) y0
	{ 213	,8	,1	, &internal1_m134_tx},	//(internal1_m134_tx) tx - время накопленное сек
	{ 214	,18	,1	, &internal1_m134_y0},	//(internal1_m134_y0) y0
	{ 215	,8	,1	, &internal1_m133_tx},	//(internal1_m133_tx) tx - время накопленное сек
	{ 216	,18	,1	, &internal1_m133_y0},	//(internal1_m133_y0) y0
	{ 217	,8	,1	, &internal1_m248_tx},	//(internal1_m248_tx) tx - время накопленное сек
	{ 218	,18	,1	, &internal1_m248_y0},	//(internal1_m248_y0) y0
	{ 219	,8	,1	, &internal1_m256_tx},	//(internal1_m256_tx) tx - время накопленное сек
	{ 220	,18	,1	, &internal1_m256_y0},	//(internal1_m256_y0) y0
	{ 221	,8	,1	, &internal1_m332_tx},	//(internal1_m332_tx) tx - время накопленное сек
	{ 222	,18	,1	, &internal1_m332_y0},	//(internal1_m332_y0) y0
	{ 223	,8	,1	, &internal1_m215_tx},	//(internal1_m215_tx) tx - время накопленное сек
	{ 224	,18	,1	, &internal1_m215_y0},	//(internal1_m215_y0) y0
	{ 225	,8	,1	, &internal1_m214_tx},	//(internal1_m214_tx) tx - время накопленное сек
	{ 226	,18	,1	, &internal1_m214_y0},	//(internal1_m214_y0) y0
	{ 227	,8	,1	, &internal1_m212_tx},	//(internal1_m212_tx) tx - время накопленное сек
	{ 228	,18	,1	, &internal1_m212_y0},	//(internal1_m212_y0) y0
	{ 229	,8	,1	, &internal1_m210_tx},	//(internal1_m210_tx) tx - время накопленное сек
	{ 230	,18	,1	, &internal1_m210_y0},	//(internal1_m210_y0) y0
	{ 231	,3	,1	, &internal1_m33_tx},	//(internal1_m33_tx) tx - внутренний параметр
	{ 232	,8	,1	, &internal1_m147_y0},	//(internal1_m147_y0) y0
	{ 233	,8	,1	, &internal1_m145_y0},	//(internal1_m145_y0) y0
	{ 234	,8	,1	, &internal1_m91_y0},	//(internal1_m91_y0) y0
	{ 235	,8	,1	, &internal1_m89_y0},	//(internal1_m89_y0) y0
	{ 236	,1	,1	, &internal1_m158_y1},	//(internal1_m158_y1) y1 - внутренний параметр
	{ 237	,1	,1	, &internal1_m169_y1},	//(internal1_m169_y1) y1 - внутренний параметр
	{ 238	,5	,1	, &internal1_m320_q0},	//(internal1_m320_q0) q0 - внутренний параметр
	{ 239	,1	,1	, &internal1_m127_y0},	//(internal1_m127_y0) state
	{ 240	,1	,1	, &internal1_m123_y0},	//(internal1_m123_y0) state
	{ 241	,1	,1	, &internal1_m105_y1},	//(internal1_m105_y1) y1 - внутренний параметр
	{ 242	,1	,1	, &internal1_m116_y1},	//(internal1_m116_y1) y1 - внутренний параметр
	{ 243	,1	,1	, &internal1_m93_y1},	//(internal1_m93_y1) y1 - внутренний параметр
	{ 244	,1	,1	, &internal1_m103_y1},	//(internal1_m103_y1) y1 - внутренний параметр
	{ 245	,1	,1	, &internal1_m155_y1},	//(internal1_m155_y1) y1 - внутренний параметр
	{ 246	,1	,1	, &internal1_m165_y1},	//(internal1_m165_y1) y1 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="baz1.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{187,"fEM_R0UT02RZZ\0"}, 
{188,"fEM_R0UT01RZZ\0"}, 
{189,"fEM_A2UP03RZZ\0"}, 
{190,"fEM_A2UP04RZZ\0"}, 
{191,"fEM_R0UT72RZZ\0"}, 
{192,"fEM_R0UT71RZZ\0"}, 
{193,"fEM_R0UT62RZZ\0"}, 
{194,"fEM_R0UT61RZZ\0"}, 
{195,"fEM_A2UP41RZZ\0"}, 
{196,"fEM_A2UP42RZZ\0"}, 
{197,"fEM_A2UP51RZZ\0"}, 
{198,"fEM_A2UP81RZZ\0"}, 
{199,"fEM_A2UP84RZZ\0"}, 
{200,"fEM_A2UP82RZZ\0"}, 
{201,"fEM_A2UP52RZZ\0"}, 
{202,"fEM_A2UP83RZZ\0"}, 
{203,"fEM_R0UR01RZZ\0"}, 
{204,"fEM_R0UR04RZZ\0"}, 
{205,"fEM_A1UL12RZZ\0"}, 
{206,"fEM_A1UL11RZZ\0"}, 
{207,"fEM_R7UI73RZZ\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_Baz1[]={  // 
	{&R0EE02LDU,1,0},	//( - , Baz1) Питание  АКНП  отключить
	{&A0EE08LZ1,1,1},	//( - , Baz1) Исправность сети АКНП4
	{&A0EE07LZ1,1,2},	//( - , Baz1) Исправность сети АКНП3
	{&A0EE06LZ1,1,3},	//( - , Baz1) Исправность сети АКНП2
	{&A0EE05LZ1,1,4},	//( - , Baz1) Исправность сети АКНП1
	{&R0AD16LDU,1,5},	//( - , Baz1) Имитация срабатывания верхней АС I УР
	{&R0MD34LP1,1,6},	//( - , Baz1) Кнопка (Квитировать)
	{&R0AD14LDU,1,7},	//( - , Baz1) Имитация срабатывания верхней АС II УР
	{&R0VW23LDU,1,8},	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,9},	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{&R0VN70LZ1,1,10},	//( - , Baz1) АЗ по АС мощности РУ
	{&R0VN64LZ1,1,11},	//( - , Baz1) ПС по мощности канал 4
	{&R0VN63LZ1,1,12},	//( - , Baz1) ПС по мощности канал 3
	{&R0VN62LZ1,1,13},	//( - , Baz1) ПС по мощности канал 2
	{&R0VN61LZ1,1,14},	//( - , Baz1) ПС по мощности канал 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_Baz1[]={  // 
	{&B0VT61LZ1,1,0},	//( - , Baz1) ПС по температуре в АЗ2
	{&R0VP73LZ1,1,1},	//( - , Baz1, SBz1DU) ПС давления для РУ
	{&B0VN81LZ1,1,2},	//( - , Baz1) АЗ по АС периода разгона АЗ2
	{&A0VN81LZ1,1,3},	//( - , Baz1) АЗ по АС периода разгона АЗ1
	{&B0VN71LZ1,1,4},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
	{&A0VN71LZ1,1,5},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
	{&B0VZ71LZ1,1,6},	//( - , Baz1) Обобщенный сигнал АС по АЗ2
	{&B0EE00LZ1,1,7},	//( - , Baz1) Исправность АКНП АЗ2
	{&A0EE00LZ1,1,8},	//( - , Baz1) Исправность АКНП АЗ1
	{&A0VZ71LZ1,1,9},	//( - , Baz1) Обобщенный сигнал АС по АЗ1
	{&A0EE03LZ1,1,10},	//( - , Baz1, SBz1DU) Исправность АКНП3
	{&A0EE02LZ1,1,11},	//( - , Baz1, SBz1DU) Исправность АКНП2
	{&A0EE04LZ1,1,12},	//( - , Baz1, SBz1DU) Исправность АКНП4
	{&A0EE01LZ1,1,13},	//( - , Baz1, SBz1DU) Исправность АКНП1
	{&R0VN80LZ1,1,14},	//( - , Baz1) АЗ по АС периода разгона РУ
	{&TestDiagnBaz1,1,15},	//( - , Baz1) Неисправность от диагностики
	{&R0AD16LZ1,1,16},	//( - , Baz1) Имитация АЗ от 1УР (датчик2)
	{&R0AD15LZ1,1,17},	//( - , Baz1) Имитация АЗ от 1УР (датчик1)
	{&R0VN78LZ1,1,18},	//( - K02VDSR, Baz1) АС по периоду разгона канал  4
	{&R0VN74LZ1,1,19},	//( - K01VDSR, Baz1) АС по мощности канал 4
	{&R0VN77LZ1,1,20},	//( - K02VDSR, Baz1) АС по периоду разгона канал  3
	{&R0VN73LZ1,1,21},	//( - K01VDSR, Baz1) АС по мощности канал 3
	{&R0VN76LZ1,1,22},	//( - K02VDSR, Baz1) АС по периоду разгона канал  2
	{&R0VN72LZ1,1,23},	//( - K01VDSR, Baz1) АС по мощности канал 2
	{&R0VN75LZ1,1,24},	//( - K02VDSR, Baz1) АС по периоду разгона канал 1
	{&R0VN71LZ1,1,25},	//( - K01VDSR, Baz1) АС по мощности канал 1
	{&R7II72LZ1,1,26},	//( - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
	{&R7II71LZ1,1,27},	//( - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
	{&R7II73LZ1,1,28},	//( - K07VDSR, Baz1) Сработала АС II УР РАД
	{&B0VT71LZ1,1,29},	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
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
	{&B1VP41LZ1,1,42},	//( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
	{&A1VP41LZ1,1,43},	//( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
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
	{&fEM_A1UL12RZZ,8,38},	//( - , Baz1) Время задержки АЗ от НУ ИС(сек)
	{&fEM_A1UL11RZZ,8,40},	//( - , Baz1) Время задержки АЗ от ВУ ИС сек
	{&fEM_R7UI73RZZ,8,42},	//( - , Baz1) Время задержки  срабатывания АС II УР
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
	{&R0VN09RZ1,8,4},	//( - , Baz1, SBz1DU) Усредненный период разгона
	{&A0CT01IZ1,8,6},	//( - , Baz1, SBz1DU) Температура АЗ1-1
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
	{1,5015,&coil_MBz1A1[0],&di_MBz1A1[0],&ir_MBz1A1[0],&hr_MBz1A1[0],NULL,MBz1A1_ip1,MBz1A1_ip2,100},	 //Мастер Баз1 в AKNP1
	{1,5016,&coil_MBz1A2[0],&di_MBz1A2[0],&ir_MBz1A2[0],&hr_MBz1A2[0],NULL,MBz1A2_ip1,MBz1A2_ip2,100},	 //Мастер Баз1 в AKNP2
	{1,5017,&coil_MBz1A3[0],&di_MBz1A3[0],&ir_MBz1A3[0],&hr_MBz1A3[0],NULL,MBz1A3_ip1,MBz1A3_ip2,100},	 //Мастер Баз1 в AKNP3
	{1,5018,&coil_MBz1A4[0],&di_MBz1A4[0],&ir_MBz1A4[0],&hr_MBz1A4[0],NULL,MBz1A4_ip1,MBz1A4_ip2,100},	 //Мастер Баз1 в AKNP4

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
	{&A0IT01IZ1,3,0},
	{&R0DE04LZ1,3,26},
	{&B0IT01IZ1,3,6},
	{&B2IP01IZ1,3,9},
	{&A2IP01IZ1,3,3},
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
	{&B2IS12LDU,1,20},
	{&R0DE05LZ1,3,64},
	{&R0AD04LZ1,1,14},
	{&A3IS22LDU,1,10},
	{&R0AD03LZ1,1,12},
	{&A2IS12LDU,1,18},
	{&R0VN71LZ1,1,0},
	{&R0VN75LZ1,1,2},
	{&R0AD05LZ1,1,16},
	{&A0VN71LS1,1,6},
	{&A0EE01LS1,1,4},
	{&A3IS11LDU,1,8},
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
	{&B3IS11LDU,1,8},
	{&A0EE01LS2,1,4},
	{&A0VN71LS2,1,6},
	{&R0DE06LZ1,3,64},
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
	{&R0VN74LZ1,1,0},
	{&R0VN78LZ1,1,2},
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
	{&R7II71LZ1,1,8},
	{&R7II73LZ1,1,12},
	{&A0VN71LS3,1,6},
	{&R0VN77LZ1,1,2},
	{&R0VN73LZ1,1,0},
	{&R7II72LZ1,1,10},
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
	{&R0VZ71LZ1,1,8},
	{&A1VN71LZ1,1,6},
	{&A3VZ15LZ1,1,2},
	{&A3VZ13LZ1,1,0},
	{&R0DE0ALZ1,3,38},
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
	{&R0DE32LZ1,1,2},
	{&R0DE34LZ1,1,6},
	{&R0DE33LZ1,1,4},
	{&R0DE36LZ1,1,10},
	{&R0DE37LZ1,1,12},
	{&R0DE35LZ1,1,8},
	{&R0DE31LZ1,1,0},
	{&R0DE39LZ1,1,16},
	{&R0DE38LZ1,1,14},
	{&R0DEB1LZ1,1,18},
	{&R0DEB2LZ1,1,20},
	{&R0DEB4LZ1,1,24},
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
	setAsFloat(187,600);
	setAsFloat(188,0);
	setAsFloat(189,1.6);
	setAsFloat(190,0);
	setAsFloat(191,150);
	setAsFloat(192,200);
	setAsFloat(193,90);
	setAsFloat(194,100);
	setAsFloat(195,0.1);
	setAsFloat(196,0.13);
	setAsFloat(197,0.16);
	setAsFloat(198,0.17);
	setAsFloat(199,0.31);
	setAsFloat(200,0.2);
	setAsFloat(201,0.19);
	setAsFloat(202,0.28);
	setAsFloat(203,15);
	setAsFloat(204,10);
	setAsFloat(205,0.180);
	setAsFloat(206,0.020);
	setAsFloat(207,0.045);
	setAsBool(9,1);
	setAsBool(10,1);
	setAsBool(11,1);
}
uspaint8 InternalBuf[127];

/* ����������� �������� ��� � ������*/
ssbool lRM_0_ = {0,0}; /* A-������� ������� ��������� � */ 
ssbool lRM_1_ = {1,0}; /* B-������� ������� ��������� � */ 
sslong dRM_0_ = {0,0}; /* lx ���� ���� */ 
sschar bRM_0_ = {0,0}; /* cx ���� �������� */ 
ssint iRM_0_ = {0,0}; /* ix ���� ����� */ 
ssint iRM_3_ = {3,0}; /* N-����� ������ */ 
ssint iRM_4_ = {4,0}; /* n - ����������� ������� */ 
ssint iRM_6_ = {6,0}; /* N-����� ������ */ 
ssint iRM_17_ = {17,0}; /* n - ����������� ������� ������� �������� */ 
ssint iRM_3276_ = {3276,0}; /* a */ 
ssint iRM_16383_ = {16383,0}; /* b */ 
ssfloat fRM_0_00001 = {0.00001,0}; /* X2 */ 
ssint iRM_200_ = {200,0}; /* tz - ������ ��������, 10-�� �� */ 
ssfloat fRM_0_2 = {0.2,0}; /* tz - ����� �������� ��� */ 
ssfloat fRM_1_0 = {1.0,0}; /* tz - ����� �������� ��� */ 
ssint iRM_7_ = {7,0}; /* n - N-����������� ������� x */ 
ssfloat fRM_0_002 = {0.002,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_0_005 = {0.005,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_0_007 = {0.007,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_0_01 = {0.01,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_0_015 = {0.015,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_0_02 = {0.02,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_1_7 = {1.7,0}; /* x - ������ ������� ���������� */ 
ssfloat fRM_10000_ = {10000,0}; /* tz - ����� �������� ��� */ 

uspaint8 SpaEEPROMBuf[105];

/* ����������� ���������� */
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
ssint var11;
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
ssfloat var137;
ssfloat var138;
ssbool var139;
ssfloat var140;
ssfloat var141;
ssbool var142;
ssbool var143;
ssbool var144;
ssbool var145;
ssbool var146;
ssbool var147;
ssfloat var148;
sslong var149;
sslong var150;
ssbool var151;
ssbool var152;
ssbool var153;
ssbool var154;
ssbool var155;
ssbool var156;
ssbool var157;
ssbool var158;
ssbool var159;
ssfloat var160;
ssbool var161;
ssbool var162;
ssfloat var163;
ssbool var164;
ssbool var165;
sschar var166;
ssbool var167;
sschar var168;
ssbool var169;
ssbool var170;
ssbool var171;
ssbool var172;
ssbool var173;
ssbool var174;
ssbool var175;
ssbool var176;
ssbool var177;
ssbool var178;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* ���������� �������� */
psbool  array_m382_x_1[6] = {&var8,&var7,&R0DE36LZ1,&R0DE37LZ1,&R0DE38LZ1,&R0DE39LZ1};
psint  array_m369_x_1[6] = {&R0DE04LZ1,&R0DE05LZ1,&R0DE06LZ1,&R0DE0ALZ1,&R0DE08LZ1,&R0DE07LZ1};
psfloat  array_m192_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psfloat  array_m352_x_1[4] = {&R0VN02RS1,&R0VN02RS2,&R0VN02RS3,&R0VN02RS4};
psbool  array_m352_diag_1[4] = {&var32,&var33,&var34,&var35};
psbool  array_m327_x_1[17] = {&var94,&var60,&var61,&var89,&var44,&var47,&var165,&var59,&var55,&var54,&var90,&var50,&var48,&var167,&var58,&var57,&var56};
psbool  array_m16_x_1[6] = {&var99,&var90,&var48,&var50,&var108,&var167};
psbool  array_m36_x_1[6] = {&var89,&var44,&var47,&var165,&var97,&var108};
psfloat  array_m2_x_1[4] = {&R0VN01RS1,&R0VN01RS2,&R0VN01RS3,&R0VN01RS4};
psbool  array_m2_diag_1[4] = {&var32,&var33,&var34,&var35};
psbool  array_m3_x_1[3] = {&var118,&var147,&var30};
psbool  array_m12_x_1[3] = {&var117,&var31,&var119};

/* ���������� �������� */
_S_zzfs  S_zzfs_107_1 = {&B1VP81LZZ,&fRM_10000_,&var1,&internal1_m107_tx,&internal1_m107_y0};
_S_zzfs  S_zzfs_106_1 = {&A1VP81LZZ,&fRM_10000_,&var2,&internal1_m106_tx,&internal1_m106_y0};
_S_zzfs  S_zzfs_134_1 = {&B0VP81LZZ,&fRM_10000_,&var3,&internal1_m134_tx,&internal1_m134_y0};
_S_zzfs  S_zzfs_133_1 = {&A0VP81LZZ,&fRM_10000_,&var4,&internal1_m133_tx,&internal1_m133_y0};
_S_or3  S_or3_383_1 = {&var10,&var9,&var6,&var5};
_S_orn  S_orn_382_1 = {array_m382_x_1,&iRM_6_,&var6};
_S_or2  S_or2_389_1 = {&R0DEB3LZ1,&R0DEB4LZ1,&var7};
_S_or2  S_or2_380_1 = {&R0DEB1LZ1,&R0DEB2LZ1,&var8};
_S_and2  S_and2_371_1 = {&R0DE31LZ1,&R0DE32LZ1,&var9};
_S_diagndev  S_diagndev_369_1 = {array_m369_x_1,&iRM_6_,&var10,&var11};
_S_ma  S_ma_192_1 = {array_m192_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_and3  S_and3_236_1 = {&var15,&var25,&var24,&var12};
_S_and3  S_and3_233_1 = {&var25,&var15,&var134,&var13};
_S_and3  S_and3_232_1 = {&var24,&var15,&var133,&var14};
_S_noto  S_noto_224_1 = {&R0AD03LZ1,&var15};
_S_and3  S_and3_230_1 = {&var18,&var21,&var20,&var16};
_S_and3  S_and3_227_1 = {&var18,&var20,&var136,&var17};
_S_noto  S_noto_218_1 = {&R0AD05LZ1,&var18};
_S_and3  S_and3_226_1 = {&var18,&var21,&var135,&var19};
_S_and2  S_and2_219_1 = {&var112,&R0VW23LDU,&var20};
_S_and2  S_and2_217_1 = {&var113,&R0VW13LDU,&var21};
_S_and3  S_and3_211_1 = {&var113,&var112,&R0AD05LZ1,&var22};
_S_and3  S_and3_216_1 = {&var111,&var110,&R0AD03LZ1,&var23};
_S_and2  S_and2_220_1 = {&var111,&R0VW13LDU,&var24};
_S_and2  S_and2_221_1 = {&R0VW23LDU,&var110,&var25};
_S_and2  S_and2_255_1 = {&var132,&var42,&var26};
_S_zzfs  S_zzfs_248_1 = {&R0AD14LDU,&fRM_1_0,&var27,&internal1_m248_tx,&internal1_m248_y0};
_S_and2  S_and2_126_1 = {&var170,&var146,&var28};
_S_and2  S_and2_137_1 = {&var169,&var145,&var29};
_S_or2  S_or2_102_1 = {&var176,&var174,&var30};
_S_or2  S_or2_108_1 = {&var171,&var172,&var31};
_S_and2  S_and2_80_1 = {&A0EE05LZ1,&A0EE01LS1,&var32};
_S_and2  S_and2_82_1 = {&A0EE06LZ1,&A0EE01LS2,&var33};
_S_and2  S_and2_84_1 = {&A0EE07LZ1,&A0EE01LS3,&var34};
_S_and2  S_and2_86_1 = {&A0EE08LZ1,&A0EE01LS4,&var35};
_S_and2  S_and2_182_1 = {&var162,&var127,&var36};
_S_and2  S_and2_183_1 = {&var161,&var127,&var37};
_S_or2  S_or2_259_1 = {&var115,&R7II73LZ1,&var38};
_S_or2  S_or2_261_1 = {&R0AD21LDU,&R0AD14LDU,&var39};
_S_and2  S_and2_260_1 = {&var39,&var38,&var40};
_S_or2  S_or2_253_1 = {&R7II71LZ1,&var114,&var41};
_S_or3  S_or3_254_1 = {&var43,&var41,&var40,&var42};
_S_or2  S_or2_247_1 = {&var116,&R7II72LZ1,&var43};
_S_or2  S_or2_234_1 = {&var19,&var16,&var44};
_S_or2  S_or2_203_1 = {&A3IS22LDU,&R0AD05LZ1,&var45};
_S_or2  S_or2_205_1 = {&B3IS22LDU,&R0AD05LZ1,&var46};
_S_or2  S_or2_237_1 = {&var14,&var12,&var47};
_S_or2  S_or2_238_1 = {&var13,&var12,&var48};
_S_or2  S_or2_206_1 = {&var131,&R0AD03LZ1,&var49};
_S_or2  S_or2_235_1 = {&var17,&var16,&var50};
_S_or2  S_or2_208_1 = {&var130,&R0AD03LZ1,&var51};
_S_schl24  S_schl24_354_1 = {&A0VN71LS2,&A0VN71LS1,&A0VN71LS4,&A0VN71LS3,&var52};
_S_and2  S_and2_340_1 = {&var126,&var125,&var53};
_S_and2  S_and2_329_1 = {&var73,&var95,&var54};
_S_and2  S_and2_331_1 = {&var80,&var95,&var55};
_S_and2  S_and2_337_1 = {&var40,&var109,&var56};
_S_and2  S_and2_336_1 = {&var41,&var109,&var57};
_S_and2  S_and2_335_1 = {&var43,&var109,&var58};
_S_and2  S_and2_333_1 = {&var128,&var95,&var59};
_S_and2  S_and2_330_1 = {&var84,&var95,&var60};
_S_and2  S_and2_328_1 = {&var66,&var95,&var61};
_S_and2  S_and2_301_1 = {&var64,&var63,&var62};
_S_or2  S_or2_303_1 = {&R0VN75LZ1,&var159,&var63};
_S_or2  S_or2_304_1 = {&R0VN77LZ1,&var158,&var64};
_S_or2  S_or2_289_1 = {&var62,&var70,&var65};
_S_or2  S_or2_295_1 = {&var67,&var62,&var66};
_S_and2  S_and2_296_1 = {&var154,&var71,&var67};
_S_or2  S_or2_306_1 = {&R0VN78LZ1,&var156,&var68};
_S_or2  S_or2_305_1 = {&R0VN76LZ1,&var157,&var69};
_S_and2  S_and2_302_1 = {&var69,&var68,&var70};
_S_schl24  S_schl24_300_1 = {&var69,&var68,&var64,&var63,&var71};
_S_and2  S_and2_298_1 = {&var95,&var71,&var72};
_S_or2  S_or2_297_1 = {&var70,&var67,&var73};
_S_and2  S_and2_293_1 = {&var73,&var95,&var74};
_S_or2  S_or2_269_1 = {&R0VN72LZ1,&var157,&var75};
_S_and2  S_and2_284_1 = {&var84,&var95,&var76};
_S_and2  S_and2_272_1 = {&var75,&var78,&var77};
_S_or2  S_or2_270_1 = {&R0VN74LZ1,&var156,&var78};
_S_and2  S_and2_285_1 = {&var80,&var95,&var79};
_S_or2  S_or2_282_1 = {&var77,&var83,&var80};
_S_or2  S_or2_288_1 = {&var85,&var77,&var81};
_S_and2  S_and2_276_1 = {&var87,&var95,&var82};
_S_and2  S_and2_281_1 = {&var155,&var87,&var83};
_S_or2  S_or2_280_1 = {&var85,&var83,&var84};
_S_and2  S_and2_271_1 = {&var86,&var88,&var85};
_S_or2  S_or2_268_1 = {&R0VN73LZ1,&var158,&var86};
_S_schl24  S_schl24_274_1 = {&var86,&var88,&var75,&var78,&var87};
_S_or2  S_or2_267_1 = {&R0VN71LZ1,&var159,&var88};
_S_or2  S_or2_154_1 = {&var139,&var177,&var89};
_S_or2  S_or2_156_1 = {&var144,&var142,&var90};
_S_or2  S_or2_358_1 = {&var175,&var173,&var91};
_S_or2  S_or2_35_1 = {&B2IS12LDU,&A2IS12LDU,&var92};
_S_and2  S_and2_292_1 = {&var95,&var66,&var93};
_S_and2  S_and2_334_1 = {&var129,&var95,&var94};
_S_and2  S_and2_21_1 = {&var124,&var120,&var95};
_S_or2  S_or2_25_1 = {&var152,&var151,&var96};
_S_and2  S_and2_31_1 = {&var98,&var95,&var97};
_S_or3  S_or3_30_1 = {&var66,&var84,&var123,&var98};
_S_and2  S_and2_19_1 = {&var95,&var100,&var99};
_S_or3  S_or3_18_1 = {&var80,&var73,&var122,&var100};
_S_and2  S_and2_6_1 = {&var33,&var35,&var101};
_S_or2  S_or2_10_1 = {&var153,&var101,&var102};
_S_or2  S_or2_9_1 = {&var104,&var153,&var103};
_S_and2  S_and2_5_1 = {&var32,&var34,&var104};
_S_and2  S_and2_193_1 = {&R0AD14LDU,&R7II72LZ1,&var105};
_S_and2  S_and2_189_1 = {&R0AD14LDU,&R7II71LZ1,&var106};
_S_and2  S_and2_186_1 = {&R0AD14LDU,&R7II73LZ1,&var107};
_S_zpfs  S_zpfs_256_1 = {&var26,&fEM_R7UI73RZZ,&var108,&internal1_m256_tx,&internal1_m256_y0};
_S_zpfs  S_zpfs_332_1 = {&var53,&fRM_0_2,&var109,&internal1_m332_tx,&internal1_m332_y0};
_S_zpfs  S_zpfs_215_1 = {&var51,&fEM_A1UL11RZZ,&var110,&internal1_m215_tx,&internal1_m215_y0};
_S_zpfs  S_zpfs_214_1 = {&var49,&fEM_A1UL11RZZ,&var111,&internal1_m214_tx,&internal1_m214_y0};
_S_zpfs  S_zpfs_212_1 = {&var46,&fEM_A1UL12RZZ,&var112,&internal1_m212_tx,&internal1_m212_y0};
_S_zpfs  S_zpfs_210_1 = {&var45,&fEM_A1UL12RZZ,&var113,&internal1_m210_tx,&internal1_m210_y0};
_S_noto  S_noto_252_1 = {&R6IS67LZZ,&var114};
_S_noto  S_noto_258_1 = {&R6IS68LZZ,&var115};
_S_noto  S_noto_241_1 = {&R6IS66LZZ,&var116};
_S_noto  S_noto_136_1 = {&var3,&var117};
_S_noto  S_noto_135_1 = {&var4,&var118};
_S_noto  S_noto_111_1 = {&var1,&var119};
_S_noto  S_noto_27_1 = {&var121,&var120};
_S_ovb1  S_ovb1_33_1 = {&var92,&iRM_200_,&var121,&internal1_m33_tx};
_S_noto  S_noto_14_1 = {&var102,&var122};
_S_noto  S_noto_13_1 = {&var103,&var123};
_S_noto  S_noto_24_1 = {&R0EE02LDU,&var124};
_S_noto  S_noto_343_1 = {&R0AD16LDU,&var125};
_S_noto  S_noto_342_1 = {&R0AD04LZ1,&var126};
_S_bol  S_bol_178_1 = {&var163,&fRM_0_00001,&var127};
_S_noto  S_noto_338_1 = {&var102,&var128};
_S_noto  S_noto_339_1 = {&var103,&var129};
_S_noto  S_noto_202_1 = {&B3IS11LDU,&var130};
_S_noto  S_noto_201_1 = {&A3IS11LDU,&var131};
_S_noto  S_noto_249_1 = {&var27,&var132};
_S_noto  S_noto_229_1 = {&R0VW23LDU,&var133};
_S_noto  S_noto_228_1 = {&R0VW13LDU,&var134};
_S_noto  S_noto_223_1 = {&R0VW23LDU,&var135};
_S_noto  S_noto_222_1 = {&R0VW13LDU,&var136};
_S_scalzz  S_scalzz_147_1 = {&B0IT01IZ1,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var137,&internal1_m147_y0};
_S_scalzz  S_scalzz_145_1 = {&A0IT01IZ1,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var138,&internal1_m145_y0};
_S_geterr  S_geterr_149_1 = {&var138,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var139};
_S_scalzz  S_scalzz_91_1 = {&B2IP01IZ1,&iRM_3276_,&iRM_16383_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var140,&internal1_m91_y0};
_S_scalzz  S_scalzz_89_1 = {&A2IP01IZ1,&iRM_3276_,&iRM_16383_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var141,&internal1_m89_y0};
_S_drg  S_drg_158_1 = {&var137,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var142,&internal1_m158_y1};
_S_drg  S_drg_169_1 = {&var137,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var143,&internal1_m169_y1};
_S_geterr  S_geterr_151_1 = {&var137,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var144};
_S_noto  S_noto_138_1 = {&var171,&var145};
_S_noto  S_noto_125_1 = {&var176,&var146};
_S_noto  S_noto_110_1 = {&var2,&var147};
_S_srm  S_srm_352_1 = {array_m352_x_1,array_m352_diag_1,&iRM_4_,&iRM_3_,&var148,&vainSBool};
_S_rsu  S_rsu_320_1 = {&R0MD34LP1,&var150,&var149,&internal1_m320_q0};
_S_orni  S_orni_327_1 = {array_m327_x_1,&iRM_17_,&vainSBool,&var150};
_S_orn  S_orn_16_1 = {array_m16_x_1,&iRM_6_,&var151};
_S_orn  S_orn_36_1 = {array_m36_x_1,&iRM_6_,&var152};
_S_noto  S_noto_7_1 = {&var164,&var153};
_S_noto  S_noto_291_1 = {&var65,&var154};
_S_noto  S_noto_286_1 = {&var81,&var155};
_S_noto  S_noto_275_1 = {&A0EE01LS4,&var156};
_S_noto  S_noto_279_1 = {&A0EE01LS2,&var157};
_S_noto  S_noto_278_1 = {&A0EE01LS3,&var158};
_S_noto  S_noto_273_1 = {&A0EE01LS1,&var159};
_S_react  S_react_174_1 = {&var163,&var160};
_S_bol  S_bol_179_1 = {&fEM_R0UR04RZZ,&var163,&var161};
_S_bol  S_bol_177_1 = {&fEM_R0UR01RZZ,&var163,&var162};
_S_srm  S_srm_2_1 = {array_m2_x_1,array_m2_diag_1,&iRM_4_,&iRM_3_,&var163,&var164};
_S_ornc  S_ornc_3_1 = {array_m3_x_1,&iRM_3_,&var165,&var166};
_S_ornc  S_ornc_12_1 = {array_m12_x_1,&iRM_3_,&var167,&var168};
_S_tprg  S_tprg_127_1 = {&var140,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var169,&internal1_m127_y0};
_S_tprg  S_tprg_123_1 = {&var141,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var170,&internal1_m123_y0};
_S_geterr  S_geterr_100_1 = {&var140,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var171};
_S_drg  S_drg_105_1 = {&var140,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var172,&internal1_m105_y1};
_S_drg  S_drg_116_1 = {&var140,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var173,&internal1_m116_y1};
_S_drg  S_drg_93_1 = {&var141,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var174,&internal1_m93_y1};
_S_drg  S_drg_103_1 = {&var141,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var175,&internal1_m103_y1};
_S_geterr  S_geterr_97_1 = {&var141,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var176};
_S_drg  S_drg_155_1 = {&var138,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var177,&internal1_m155_y1};
_S_drg  S_drg_165_1 = {&var138,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var178,&internal1_m165_y1};


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
   var11.i=0;
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
   var108.b=0;
   var109.b=0;
   var110.b=0;
   var111.b=0;
   var112.b=0;
   var113.b=0;
   var114.b=0;
   var115.b=0;
   var116.b=0;
   var117.b=0;
   var118.b=0;
   var119.b=0;
   var120.b=0;
   var121.b=0;
   var122.b=0;
   var123.b=0;
   var124.b=0;
   var125.b=0;
   var126.b=0;
   var127.b=0;
   var128.b=0;
   var129.b=0;
   var130.b=0;
   var131.b=0;
   var132.b=0;
   var133.b=0;
   var134.b=0;
   var135.b=0;
   var136.b=0;
   var137.f=0.0;
   var138.f=0.0;
   var139.b=0;
   var140.f=0.0;
   var141.f=0.0;
   var142.b=0;
   var143.b=0;
   var144.b=0;
   var145.b=0;
   var146.b=0;
   var147.b=0;
   var148.f=0.0;
   var149.l=0L;
   var150.l=0L;
   var151.b=0;
   var152.b=0;
   var153.b=0;
   var154.b=0;
   var155.b=0;
   var156.b=0;
   var157.b=0;
   var158.b=0;
   var159.b=0;
   var160.f=0.0;
   var161.b=0;
   var162.b=0;
   var163.f=0.0;
   var164.b=0;
   var165.b=0;
   var166.c=0;
   var167.b=0;
   var168.c=0;
   var169.b=0;
   var170.b=0;
   var171.b=0;
   var172.b=0;
   var173.b=0;
   var174.b=0;
   var175.b=0;
   var176.b=0;
   var177.b=0;
   var178.b=0;
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
  noto(&S_noto_273_1);
  noto(&S_noto_278_1);
  noto(&S_noto_279_1);
  noto(&S_noto_275_1);
  scalzz(&S_scalzz_89_1);
  scalzz(&S_scalzz_91_1);
  scalzz(&S_scalzz_145_1);
  scalzz(&S_scalzz_147_1);
  noto(&S_noto_223_1);
  noto(&S_noto_228_1);
  noto(&S_noto_229_1);
  noto(&S_noto_201_1);
  noto(&S_noto_202_1);
  noto(&S_noto_24_1);
  noto(&S_noto_241_1);
  noto(&S_noto_258_1);
  noto(&S_noto_252_1);
  and2(&S_and2_186_1);
  and2(&S_and2_189_1);
  and2(&S_and2_193_1);
  or2(&S_or2_267_1);
  or2(&S_or2_268_1);
  and2(&S_and2_271_1);
  or2(&S_or2_270_1);
  or2(&S_or2_269_1);
  or2(&S_or2_305_1);
  or2(&S_or2_306_1);
  or2(&S_or2_304_1);
  or2(&S_or2_303_1);
  and2(&S_and2_301_1);
  schl24(&S_schl24_354_1);
  or2(&S_or2_208_1);
  or2(&S_or2_206_1);
  or2(&S_or2_205_1);
  or2(&S_or2_203_1);
  or2(&S_or2_247_1);
  or2(&S_or2_253_1);
  or2(&S_or2_261_1);
  or2(&S_or2_259_1);
  and2(&S_and2_86_1);
  and2(&S_and2_84_1);
  and2(&S_and2_82_1);
  and2(&S_and2_80_1);
  zzfs(&S_zzfs_248_1);
  noto(&S_noto_218_1);
  noto(&S_noto_224_1);
  ma(&S_ma_192_1);
  and2(&S_and2_371_1);
  or2(&S_or2_380_1);
  or2(&S_or2_389_1);
  orn(&S_orn_382_1);
  zzfs(&S_zzfs_133_1);
  zzfs(&S_zzfs_134_1);
  zzfs(&S_zzfs_106_1);
  zzfs(&S_zzfs_107_1);
  drg(&S_drg_165_1);
  drg(&S_drg_155_1);
  geterr(&S_geterr_97_1);
  drg(&S_drg_103_1);
  drg(&S_drg_93_1);
  drg(&S_drg_116_1);
  drg(&S_drg_105_1);
  geterr(&S_geterr_100_1);
  tprg(&S_tprg_123_1);
  tprg(&S_tprg_127_1);
  srm(&S_srm_2_1);
  bol(&S_bol_177_1);
  bol(&S_bol_179_1);
  react(&S_react_174_1);
  noto(&S_noto_7_1);
  srm(&S_srm_352_1);
  noto(&S_noto_110_1);
  noto(&S_noto_125_1);
  noto(&S_noto_138_1);
  geterr(&S_geterr_151_1);
  drg(&S_drg_169_1);
  drg(&S_drg_158_1);
  geterr(&S_geterr_149_1);
  noto(&S_noto_222_1);
  noto(&S_noto_249_1);
  bol(&S_bol_178_1);
  noto(&S_noto_342_1);
  noto(&S_noto_343_1);
  noto(&S_noto_111_1);
  noto(&S_noto_135_1);
  noto(&S_noto_136_1);
  zpfs(&S_zpfs_210_1);
  zpfs(&S_zpfs_212_1);
  zpfs(&S_zpfs_214_1);
  zpfs(&S_zpfs_215_1);
  and2(&S_and2_5_1);
  or2(&S_or2_9_1);
  and2(&S_and2_6_1);
  or2(&S_or2_35_1);
  or2(&S_or2_358_1);
  or2(&S_or2_156_1);
  or2(&S_or2_154_1);
  schl24(&S_schl24_274_1);
  and2(&S_and2_272_1);
  schl24(&S_schl24_300_1);
  and2(&S_and2_302_1);
  or2(&S_or2_289_1);
  and2(&S_and2_340_1);
  and2(&S_and2_260_1);
  and2(&S_and2_183_1);
  and2(&S_and2_182_1);
  or2(&S_or2_108_1);
  or2(&S_or2_102_1);
  and2(&S_and2_137_1);
  and2(&S_and2_126_1);
  and2(&S_and2_221_1);
  and2(&S_and2_220_1);
  and3(&S_and3_216_1);
  and3(&S_and3_211_1);
  and2(&S_and2_217_1);
  and2(&S_and2_219_1);
  and3(&S_and3_226_1);
  and3(&S_and3_227_1);
  and3(&S_and3_230_1);
  and3(&S_and3_232_1);
  and3(&S_and3_233_1);
  and3(&S_and3_236_1);
  diagndev(&S_diagndev_369_1);
  or3(&S_or3_383_1);
  ornc(&S_ornc_12_1);
  ornc(&S_ornc_3_1);
  noto(&S_noto_291_1);
  noto(&S_noto_339_1);
  noto(&S_noto_13_1);
  ovb1(&S_ovb1_33_1);
  noto(&S_noto_27_1);
  zpfs(&S_zpfs_332_1);
  or2(&S_or2_10_1);
  and2(&S_and2_21_1);
  and2(&S_and2_334_1);
  and2(&S_and2_276_1);
  or2(&S_or2_288_1);
  and2(&S_and2_298_1);
  and2(&S_and2_296_1);
  or2(&S_or2_295_1);
  and2(&S_and2_328_1);
  and2(&S_and2_335_1);
  and2(&S_and2_336_1);
  and2(&S_and2_337_1);
  or2(&S_or2_235_1);
  or2(&S_or2_238_1);
  or2(&S_or2_237_1);
  or2(&S_or2_234_1);
  or3(&S_or3_254_1);
  and2(&S_and2_255_1);
  noto(&S_noto_286_1);
  noto(&S_noto_338_1);
  noto(&S_noto_14_1);
  zpfs(&S_zpfs_256_1);
  and2(&S_and2_292_1);
  and2(&S_and2_281_1);
  or2(&S_or2_282_1);
  and2(&S_and2_285_1);
  or2(&S_or2_297_1);
  and2(&S_and2_333_1);
  and2(&S_and2_331_1);
  and2(&S_and2_329_1);
  or3(&S_or3_18_1);
  and2(&S_and2_19_1);
  or2(&S_or2_280_1);
  and2(&S_and2_284_1);
  and2(&S_and2_293_1);
  and2(&S_and2_330_1);
  orn(&S_orn_16_1);
  orni(&S_orni_327_1);
  rsu(&S_rsu_320_1);
  or3(&S_or3_30_1);
  and2(&S_and2_31_1);
  orn(&S_orn_36_1);
  or2(&S_or2_25_1);
  setData(idR0VZ05U,&var150);
  setData(idPS12,&var80);
  setData(idPS13,&var73);
  setData(idPS14,&var90);
  setData(idPS15,&var48);
  setData(idPS16,&var50);
  setData(idPS17,&var167);
  setData(idPS11,&var40);
  setData(idPS10,&var41);
  setData(idPS8,&var103);
  setData(idPS9,&var43);
  setData(idPS7,&var102);
  setData(idPS6,&var84);
  setData(idPS5,&var66);
  setData(idPS4,&var89);
  setData(idPS3,&var44);
  setData(idPS2,&var47);
  setData(idPS1,&var165);
  setData(idTestDiagnBaz1,&var5);
  setData(idR0DE3DLZ1,&var7);
  setData(idR0DE3CLZ1,&var8);
  setData(idTTLBaz1,&var11);
  setData(idR0AD16LZ1,&var105);
  setData(idR0AD15LZ1,&var106);
  moveData(idR0EE04LZ1,idR0EE02LDU);
  moveData(idR0EE03LZ1,idR0EE02LDU);
  moveData(idR0EE02LZ1,idR0EE02LDU);
  moveData(idR0EE01LZ1,idR0EE02LDU);
  setData(idR0AD14LZ1,&var107);
  setData(idA3VZ13LZ1,&var23);
  setData(idA3VZ15LZ1,&var22);
  setData(idA1VN71LZ1,&var52);
  setData(idB0VT71LZ1,&var90);
  setData(idB0VT61LZ1,&var143);
  setData(idB0CT01IZ1,&var137);
  setData(idR0VP73LZ1,&var91);
  setData(idR0VN11RZ1,&var148);
  setData(idR0VZ05UZ1,&var149);
  setData(idB0VN81LZ1,&var74);
  setData(idA0VN81LZ1,&var93);
  setData(idB0VN71LZ1,&var79);
  setData(idA0VN71LZ1,&var76);
  setData(idB0VZ71LZ1,&var151);
  setData(idB0EE00LZ1,&var102);
  setData(idA0EE00LZ1,&var103);
  setData(idA0VZ71LZ1,&var152);
  setData(idA0EE03LZ1,&var34);
  setData(idA0EE02LZ1,&var33);
  setData(idA0EE04LZ1,&var35);
  setData(idA0EE01LZ1,&var32);
  setData(idR0VN80LZ1,&var72);
  setData(idR0VN70LZ1,&var82);
  setData(idR0VZ71LZ1,&var96);
  setData(idR0VR02RZ1,&var160);
  setData(idR0VN79LZ1,&var37);
  setData(idR0VN69LZ1,&var36);
  setData(idB3VZ11LZ1,&var50);
  setData(idA3VZ11LZ1,&var44);
  setData(idB3VZ31LZ1,&var48);
  setData(idA3VZ31LZ1,&var47);
  setData(idR0VN09RZ1,&var163);
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
  setData(idB0VP71LZ1,&var167);
  setData(idA0VP71LZ1,&var165);
  setData(idA0EP02IZ1,&var166);
  setData(idB0EP02IZ1,&var168);
  setData(idR0ET02LZ1,&var144);
  setData(idB0VP41LZ1,&var117);
  setData(idA0VP41LZ1,&var118);
  setData(idR0ET01LZ1,&var139);
  setData(idA2VP81LZ1,&var28);
  setData(idB2VP81LZ1,&var29);
  setData(idB2VP51LZ1,&var173);
  setData(idB2CP01RZ1,&var140);
  setData(idB2VP41LZ1,&var31);
  setData(idA2VP51LZ1,&var175);
  setData(idA2CP01RZ1,&var141);
  setData(idA2VP41LZ1,&var30);
  setData(idB1VP41LZ1,&var119);
  setData(idA1VP41LZ1,&var147);
  setData(idA0VT71LZ1,&var89);
  setData(idA0VT61LZ1,&var178);
  setData(idA0CT01IZ1,&var138);

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
