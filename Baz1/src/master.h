#ifndef BAZ1_H
#define BAZ1_H
// Подсистема Baz1:Baz1
static char SimulOn=0;
static short CodeSub=4;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=100;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 657
static char BUFFER[657];
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
#define R6IS66LZZ	 BUFFER[16]	//( - , MBz1S) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 9	//( - , MBz1S) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[18]	//( - , MBz1S) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 10	//( - , MBz1S) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[20]	//( - , MBz1S) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 11	//( - , MBz1S) Исправность ВИП 4,0 (№7) ССДИ-2
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
#define R0DEB3LZ1	 BUFFER[101]	//(sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
#define idR0DEB3LZ1	 47	//(sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
#define R0DE3CLZ1	 BUFFER[103]	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 5
#define idR0DE3CLZ1	 48	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 5
#define R0DE3DLZ1	 BUFFER[105]	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 6
#define idR0DE3DLZ1	 49	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 6
#define TestDiagnBaz1	 BUFFER[107]	//( - , Baz1) Неисправность от диагностики
#define idTestDiagnBaz1	 50	//( - , Baz1) Неисправность от диагностики
#define R0MW11IP1	 BUFFER[109]	//( - , Baz1) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 51	//( - , Baz1) Переключатель ВЫСТРЕЛ
#define PS1	 BUFFER[112]	//( - , - ) АЗ по АС любого давления за АЗ1
#define idPS1	 52	//( - , - ) АЗ по АС любого давления за АЗ1
#define PS2	 BUFFER[114]	//( - , - ) АЗ от ВУ ИС1
#define idPS2	 53	//( - , - ) АЗ от ВУ ИС1
#define PS3	 BUFFER[116]	//( - , - ) АЗ от НУП ИС1
#define idPS3	 54	//( - , - ) АЗ от НУП ИС1
#define PS4	 BUFFER[118]	//( - , - ) АС по температуру АЗ1
#define idPS4	 55	//( - , - ) АС по температуру АЗ1
#define PS5	 BUFFER[120]	//( - , - ) АС по периоду АЗ1
#define idPS5	 56	//( - , - ) АС по периоду АЗ1
#define PS6	 BUFFER[122]	//( - , - ) АС по мощности АЗ1
#define idPS6	 57	//( - , - ) АС по мощности АЗ1
#define PS7	 BUFFER[124]	//( - , - ) Исправность АКНП АЗ2
#define idPS7	 58	//( - , - ) Исправность АКНП АЗ2
#define PS9	 BUFFER[126]	//( - , - ) АС 1 ур (д2)
#define idPS9	 59	//( - , - ) АС 1 ур (д2)
#define PS8	 BUFFER[128]	//( - , - ) Исправность АКНП АЗ1
#define idPS8	 60	//( - , - ) Исправность АКНП АЗ1
#define PS10	 BUFFER[130]	//( - , - ) АС 1 ур (д1)
#define idPS10	 61	//( - , - ) АС 1 ур (д1)
#define PS11	 BUFFER[132]	//( - , - ) АС 2 ур
#define idPS11	 62	//( - , - ) АС 2 ур
#define PS17	 BUFFER[134]	//( - , - ) Аз по Ас любого давления АЗ2
#define idPS17	 63	//( - , - ) Аз по Ас любого давления АЗ2
#define PS16	 BUFFER[136]	//( - , - ) АЗ от НУП ИС2
#define idPS16	 64	//( - , - ) АЗ от НУП ИС2
#define PS15	 BUFFER[138]	//( - , - ) АЗ от ВУ ИС2
#define idPS15	 65	//( - , - ) АЗ от ВУ ИС2
#define PS14	 BUFFER[140]	//( - , - ) Ас по температура АЗ2
#define idPS14	 66	//( - , - ) Ас по температура АЗ2
#define PS13	 BUFFER[142]	//( - , - ) АС по периоду АЗ2
#define idPS13	 67	//( - , - ) АС по периоду АЗ2
#define PS12	 BUFFER[144]	//( - , - ) Ас по мощности АЗ2
#define idPS12	 68	//( - , - ) Ас по мощности АЗ2
#define R0VZ05U	 BUFFER[146]	//( - , - ) причины сброса
#define idR0VZ05U	 69	//( - , - ) причины сброса
#define R0AD16LZ1	 BUFFER[151]	//( - , Baz1) Имитация АЗ от 1УР (датчик2)
#define idR0AD16LZ1	 70	//( - , Baz1) Имитация АЗ от 1УР (датчик2)
#define R0MW12IP2	 BUFFER[153]	//( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define idR0MW12IP2	 71	//( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define A2IS12LDU	 BUFFER[156]	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	 72	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define B2IS12LDU	 BUFFER[158]	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	 73	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define R0DE04LZ1	 BUFFER[160]	//(vas84:04 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
#define idR0DE04LZ1	 74	//(vas84:04 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
#define R0DE05LZ1	 BUFFER[163]	//(vds32:05 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
#define idR0DE05LZ1	 75	//(vds32:05 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
#define R0DE06LZ1	 BUFFER[166]	//(vds32:06 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
#define idR0DE06LZ1	 76	//(vds32:06 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
#define R0DE08LZ1	 BUFFER[169]	//(vds32:08 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
#define idR0DE08LZ1	 77	//(vds32:08 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
#define R0DE07LZ1	 BUFFER[172]	//(vds32:07 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
#define idR0DE07LZ1	 78	//(vds32:07 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
#define R0DE0ALZ1	 BUFFER[175]	//(fds16:0a - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
#define idR0DE0ALZ1	 79	//(fds16:0a - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
#define TTLBaz1	 BUFFER[178]	//( - , Baz1) ttl
#define idTTLBaz1	 80	//( - , Baz1) ttl
#define R0DE31LZ1	 BUFFER[181]	//(sbk:20 - S01SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 1
#define idR0DE31LZ1	 81	//(sbk:20 - S01SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 1
#define R0DE32LZ1	 BUFFER[183]	//(sbk:20 - S02SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 2
#define idR0DE32LZ1	 82	//(sbk:20 - S02SBK, DiagnBaz1) диагностика шкафа Баз1 сеть 2
#define R0DE34LZ1	 BUFFER[185]	//(sbk:20 - S04SBK, DiagnBaz1) диагностика шкафа Баз1 температура меньше 43
#define idR0DE34LZ1	 83	//(sbk:20 - S04SBK, DiagnBaz1) диагностика шкафа Баз1 температура меньше 43
#define R0DE33LZ1	 BUFFER[187]	//(sbk:20 - S03SBK, DiagnBaz1) диагностика шкафа Баз1 двери
#define idR0DE33LZ1	 84	//(sbk:20 - S03SBK, DiagnBaz1) диагностика шкафа Баз1 двери
#define R0DE36LZ1	 BUFFER[189]	//(sbk:20 - S06SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 1
#define idR0DE36LZ1	 85	//(sbk:20 - S06SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 1
#define R0DE37LZ1	 BUFFER[191]	//(sbk:20 - S07SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 2
#define idR0DE37LZ1	 86	//(sbk:20 - S07SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3.1 место 2
#define R0DE35LZ1	 BUFFER[193]	//(sbk:20 - S05SBK, DiagnBaz1) диагностика шкафа Баз1 температура больше 53
#define idR0DE35LZ1	 87	//(sbk:20 - S05SBK, DiagnBaz1) диагностика шкафа Баз1 температура больше 53
#define R0DE39LZ1	 BUFFER[195]	//(sbk:20 - S09SBK, DiagnBaz1) диагностика шкафа Баз1 МП24-2 место 4
#define idR0DE39LZ1	 88	//(sbk:20 - S09SBK, DiagnBaz1) диагностика шкафа Баз1 МП24-2 место 4
#define R0DE38LZ1	 BUFFER[197]	//(sbk:20 - S08SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3 место 3
#define idR0DE38LZ1	 89	//(sbk:20 - S08SBK, DiagnBaz1) диагностика шкафа Баз1 МП15-3 место 3
#define R0DEB1LZ1	 BUFFER[199]	//(sbk:20 - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
#define idR0DEB1LZ1	 90	//(sbk:20 - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
#define R0DEB2LZ1	 BUFFER[201]	//(sbk:20 - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
#define idR0DEB2LZ1	 91	//(sbk:20 - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
#define R0DEB4LZ1	 BUFFER[203]	//(sbk:20 - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
#define idR0DEB4LZ1	 92	//(sbk:20 - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
#define A0VP81LZZ	 BUFFER[205]	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define idA0VP81LZZ	 93	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define R0ET02LZ1	 BUFFER[207]	//( - , Baz1) Признак наличия неисправности по температуре АЗ2
#define idR0ET02LZ1	 94	//( - , Baz1) Признак наличия неисправности по температуре АЗ2
#define B0EP02IZ1	 BUFFER[209]	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
#define idB0EP02IZ1	 95	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
#define A0EP02IZ1	 BUFFER[212]	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
#define idA0EP02IZ1	 96	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
#define A0VP71LZ1	 BUFFER[215]	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	 97	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
#define B0VP71LZ1	 BUFFER[217]	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	 98	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
#define R0VN02RS1	 BUFFER[219]	//( - , MBz1A1) Уровень мощности канал 1
#define idR0VN02RS1	 99	//( - , MBz1A1) Уровень мощности канал 1
#define R0VN02RS2	 BUFFER[224]	//( - , MBz1A2) Уровень мощности канал 2
#define idR0VN02RS2	 100	//( - , MBz1A2) Уровень мощности канал 2
#define R0VN02RS3	 BUFFER[229]	//( - , MBz1A3) Уровень мощности канал 3
#define idR0VN02RS3	 101	//( - , MBz1A3) Уровень мощности канал 3
#define R0VN02RS4	 BUFFER[234]	//( - , MBz1A4) Уровень мощности канал 4
#define idR0VN02RS4	 102	//( - , MBz1A4) Уровень мощности канал 4
#define R0VN01RS1	 BUFFER[239]	//( - , MBz1A1) Период разгона канал 1
#define idR0VN01RS1	 103	//( - , MBz1A1) Период разгона канал 1
#define R0VN01RS2	 BUFFER[244]	//( - , MBz1A2) Период разгона канал 2
#define idR0VN01RS2	 104	//( - , MBz1A2) Период разгона канал 2
#define R0VN01RS3	 BUFFER[249]	//( - , MBz1A3) Период разгона канал 3
#define idR0VN01RS3	 105	//( - , MBz1A3) Период разгона канал 3
#define R0VN01RS4	 BUFFER[254]	//( - , MBz1A4) Период разгона канал 4
#define idR0VN01RS4	 106	//( - , MBz1A4) Период разгона канал 4
#define R0VN61LS1	 BUFFER[259]	//( - , MBz1A1) ПС по мощности канал 1
#define idR0VN61LS1	 107	//( - , MBz1A1) ПС по мощности канал 1
#define R0VN61LS2	 BUFFER[261]	//( - , MBz1A2) ПС по мощности канал 2
#define idR0VN61LS2	 108	//( - , MBz1A2) ПС по мощности канал 2
#define R0VN61LS3	 BUFFER[263]	//( - , MBz1A3) ПС по мощности канал 3
#define idR0VN61LS3	 109	//( - , MBz1A3) ПС по мощности канал 3
#define R0VN61LS4	 BUFFER[265]	//( - , MBz1A4) ПС по мощности канал 4
#define idR0VN61LS4	 110	//( - , MBz1A4) ПС по мощности канал 4
#define R0VN65LS1	 BUFFER[267]	//( - , MBz1A1) ПС по периоду разгона канал 1
#define idR0VN65LS1	 111	//( - , MBz1A1) ПС по периоду разгона канал 1
#define R0VN65LS2	 BUFFER[269]	//( - , MBz1A2) ПС по периоду разгона  канал 2
#define idR0VN65LS2	 112	//( - , MBz1A2) ПС по периоду разгона  канал 2
#define R0VN65LS3	 BUFFER[271]	//( - , MBz1A3) ПС по периоду разгона канал 3
#define idR0VN65LS3	 113	//( - , MBz1A3) ПС по периоду разгона канал 3
#define R0VN65LS4	 BUFFER[273]	//( - , MBz1A4) ПС по периоду разгона канал 4
#define idR0VN65LS4	 114	//( - , MBz1A4) ПС по периоду разгона канал 4
#define R0VN01RZ1	 BUFFER[275]	//( - , Baz1) Уровень мощности по каналу 1
#define idR0VN01RZ1	 115	//( - , Baz1) Уровень мощности по каналу 1
#define A0IT01IZ1	 BUFFER[280]	//(vas84:04 - K01VASR, - ) Температура АЗ1-1
#define idA0IT01IZ1	 116	//(vas84:04 - K01VASR, - ) Температура АЗ1-1
#define A0CT01IZ1	 BUFFER[283]	//( - , Baz1, SBz1DU) Температура АЗ1-1
#define idA0CT01IZ1	 117	//( - , Baz1, SBz1DU) Температура АЗ1-1
#define A0VT61LZ1	 BUFFER[288]	//( - , Baz1) ПС по температуре в АЗ1
#define idA0VT61LZ1	 118	//( - , Baz1) ПС по температуре в АЗ1
#define A0VT71LZ1	 BUFFER[290]	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
#define idA0VT71LZ1	 119	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
#define A1VP41LZ1	 BUFFER[292]	//( - , Baz1) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	 120	//( - , Baz1) Давление СБРОС ББ1 ниже АС
#define B1VP41LZ1	 BUFFER[294]	//( - , Baz1) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	 121	//( - , Baz1) Давление СБРОС ББ2 ниже АС
#define B1VP81LZZ	 BUFFER[296]	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	 122	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define A1VP81LZZ	 BUFFER[298]	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	 123	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define A2VP41LZ1	 BUFFER[300]	//( - , Baz1) Давление СБРОС РБ1 ниже АС
#define idA2VP41LZ1	 124	//( - , Baz1) Давление СБРОС РБ1 ниже АС
#define A2CP01RZ1	 BUFFER[302]	//( - , Baz1) Текущее давление СБРОС РБ1
#define idA2CP01RZ1	 125	//( - , Baz1) Текущее давление СБРОС РБ1
#define A2VP51LZ1	 BUFFER[307]	//( - , Baz1) Давление СБРОС РБ1 ниже ПС
#define idA2VP51LZ1	 126	//( - , Baz1) Давление СБРОС РБ1 ниже ПС
#define B2VP41LZ1	 BUFFER[309]	//( - , Baz1) Давление СБРОС РБ2 ниже АС
#define idB2VP41LZ1	 127	//( - , Baz1) Давление СБРОС РБ2 ниже АС
#define B2CP01RZ1	 BUFFER[311]	//( - , Baz1) Текущее давление СБРОС РБ2
#define idB2CP01RZ1	 128	//( - , Baz1) Текущее давление СБРОС РБ2
#define B2VP51LZ1	 BUFFER[316]	//( - , Baz1) Давление СБРОС РБ2 ниже ПС
#define idB2VP51LZ1	 129	//( - , Baz1) Давление СБРОС РБ2 ниже ПС
#define B2VP81LZ1	 BUFFER[318]	//( - , Baz1) Давление СБРОС РБ2 в норме
#define idB2VP81LZ1	 130	//( - , Baz1) Давление СБРОС РБ2 в норме
#define A2VP81LZ1	 BUFFER[320]	//( - , Baz1) Давление СБРОС РБ1 в норме
#define idA2VP81LZ1	 131	//( - , Baz1) Давление СБРОС РБ1 в норме
#define A2IP01IZ1	 BUFFER[322]	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	 132	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define B2IP01IZ1	 BUFFER[325]	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	 133	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define R0ET01LZ1	 BUFFER[328]	//( - , Baz1) Признак наличия неисправности по температуре  АЗ1
#define idR0ET01LZ1	 134	//( - , Baz1) Признак наличия неисправности по температуре  АЗ1
#define B0IT01IZ1	 BUFFER[330]	//(vas84:04 - K03VASR, - ) Температура АЗ2-1
#define idB0IT01IZ1	 135	//(vas84:04 - K03VASR, - ) Температура АЗ2-1
#define A0VP41LZ1	 BUFFER[333]	//( - , Baz1) Давление АЗ1 ниже АС
#define idA0VP41LZ1	 136	//( - , Baz1) Давление АЗ1 ниже АС
#define B0VP41LZ1	 BUFFER[335]	//( - , Baz1) Давление АЗ2 ниже АС
#define idB0VP41LZ1	 137	//( - , Baz1) Давление АЗ2 ниже АС
#define B0VP81LZZ	 BUFFER[337]	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	 138	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define B3VZ11LZ1	 BUFFER[339]	//( - , Baz1) АЗ от НУП ИС2
#define idB3VZ11LZ1	 139	//( - , Baz1) АЗ от НУП ИС2
#define B3IS22LDU	 BUFFER[341]	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
#define idB3IS22LDU	 140	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
#define R0VN69LZ1	 BUFFER[343]	//( - , Baz1) ПС по усредненному периоду
#define idR0VN69LZ1	 141	//( - , Baz1) ПС по усредненному периоду
#define R0VN79LZ1	 BUFFER[345]	//( - , Baz1) АС по усредненному периоду
#define idR0VN79LZ1	 142	//( - , Baz1) АС по усредненному периоду
#define R0VR02RZ1	 BUFFER[347]	//( - , Baz1) Усредненная реактивность
#define idR0VR02RZ1	 143	//( - , Baz1) Усредненная реактивность
#define R0VZ71LZ1	 BUFFER[352]	//(fds16:0a - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
#define idR0VZ71LZ1	 144	//(fds16:0a - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
#define R0VN70LZ1	 BUFFER[354]	//( - , Baz1) АЗ по АС мощности РУ
#define idR0VN70LZ1	 145	//( - , Baz1) АЗ по АС мощности РУ
#define R0VN80LZ1	 BUFFER[356]	//( - , Baz1) АЗ по АС периода разгона РУ
#define idR0VN80LZ1	 146	//( - , Baz1) АЗ по АС периода разгона РУ
#define A0EE01LS1	 BUFFER[358]	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define idA0EE01LS1	 147	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define A0EE01LS4	 BUFFER[360]	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define idA0EE01LS4	 148	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define A0EE01LS3	 BUFFER[362]	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define idA0EE01LS3	 149	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define A0EE01LZ1	 BUFFER[364]	//( - , Baz1, SBz1DU) Исправность АКНП1
#define idA0EE01LZ1	 150	//( - , Baz1, SBz1DU) Исправность АКНП1
#define A0EE04LZ1	 BUFFER[366]	//( - , Baz1, SBz1DU) Исправность АКНП4
#define idA0EE04LZ1	 151	//( - , Baz1, SBz1DU) Исправность АКНП4
#define A0EE02LZ1	 BUFFER[368]	//( - , Baz1, SBz1DU) Исправность АКНП2
#define idA0EE02LZ1	 152	//( - , Baz1, SBz1DU) Исправность АКНП2
#define A0EE03LZ1	 BUFFER[370]	//( - , Baz1, SBz1DU) Исправность АКНП3
#define idA0EE03LZ1	 153	//( - , Baz1, SBz1DU) Исправность АКНП3
#define A0EE01LS2	 BUFFER[372]	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define idA0EE01LS2	 154	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define A0EE05LZ1	 BUFFER[374]	//( - , Baz1) Исправность сети АКНП1
#define idA0EE05LZ1	 155	//( - , Baz1) Исправность сети АКНП1
#define A0EE06LZ1	 BUFFER[376]	//( - , Baz1) Исправность сети АКНП2
#define idA0EE06LZ1	 156	//( - , Baz1) Исправность сети АКНП2
#define A0EE07LZ1	 BUFFER[378]	//( - , Baz1) Исправность сети АКНП3
#define idA0EE07LZ1	 157	//( - , Baz1) Исправность сети АКНП3
#define A0EE08LZ1	 BUFFER[380]	//( - , Baz1) Исправность сети АКНП4
#define idA0EE08LZ1	 158	//( - , Baz1) Исправность сети АКНП4
#define A0VZ71LZ1	 BUFFER[382]	//( - , Baz1) Обобщенный сигнал АС по АЗ1
#define idA0VZ71LZ1	 159	//( - , Baz1) Обобщенный сигнал АС по АЗ1
#define A0EE00LZ1	 BUFFER[384]	//( - , Baz1) Исправность АКНП АЗ1
#define idA0EE00LZ1	 160	//( - , Baz1) Исправность АКНП АЗ1
#define B0EE00LZ1	 BUFFER[386]	//( - , Baz1) Исправность АКНП АЗ2
#define idB0EE00LZ1	 161	//( - , Baz1) Исправность АКНП АЗ2
#define R0VN02RZ1	 BUFFER[388]	//( - , Baz1) Уровень мощности по каналу 2
#define idR0VN02RZ1	 162	//( - , Baz1) Уровень мощности по каналу 2
#define R0VN03RZ1	 BUFFER[393]	//( - , Baz1) Уровень мощности по каналу 3
#define idR0VN03RZ1	 163	//( - , Baz1) Уровень мощности по каналу 3
#define R0VN04RZ1	 BUFFER[398]	//( - , Baz1) Уровень мощности по каналу 4
#define idR0VN04RZ1	 164	//( - , Baz1) Уровень мощности по каналу 4
#define R0VN05RZ1	 BUFFER[403]	//( - , Baz1) Период разгона по каналу 1
#define idR0VN05RZ1	 165	//( - , Baz1) Период разгона по каналу 1
#define R0VN06RZ1	 BUFFER[408]	//( - , Baz1) Период разгона по каналу 2
#define idR0VN06RZ1	 166	//( - , Baz1) Период разгона по каналу 2
#define R0VN07RZ1	 BUFFER[413]	//( - , Baz1) Период разгона по каналу 3
#define idR0VN07RZ1	 167	//( - , Baz1) Период разгона по каналу 3
#define R0VN08RZ1	 BUFFER[418]	//( - , Baz1) Период разгона по каналу 4
#define idR0VN08RZ1	 168	//( - , Baz1) Период разгона по каналу 4
#define R0VN61LZ1	 BUFFER[423]	//( - , Baz1) ПС по мощности канал 1
#define idR0VN61LZ1	 169	//( - , Baz1) ПС по мощности канал 1
#define R0VN62LZ1	 BUFFER[425]	//( - , Baz1) ПС по мощности канал 2
#define idR0VN62LZ1	 170	//( - , Baz1) ПС по мощности канал 2
#define R0VN63LZ1	 BUFFER[427]	//( - , Baz1) ПС по мощности канал 3
#define idR0VN63LZ1	 171	//( - , Baz1) ПС по мощности канал 3
#define R0VN64LZ1	 BUFFER[429]	//( - , Baz1) ПС по мощности канал 4
#define idR0VN64LZ1	 172	//( - , Baz1) ПС по мощности канал 4
#define R0VN65LZ1	 BUFFER[431]	//( - , Baz1) ПС по периоду разгона канал 1
#define idR0VN65LZ1	 173	//( - , Baz1) ПС по периоду разгона канал 1
#define R0VN66LZ1	 BUFFER[433]	//( - , Baz1) ПС по периоду разгона канал 2
#define idR0VN66LZ1	 174	//( - , Baz1) ПС по периоду разгона канал 2
#define R0VN67LZ1	 BUFFER[435]	//( - , Baz1) ПС по периоду разгона канал 3
#define idR0VN67LZ1	 175	//( - , Baz1) ПС по периоду разгона канал 3
#define R0VN68LZ1	 BUFFER[437]	//( - , Baz1) ПС по периоду разгона канал 4
#define idR0VN68LZ1	 176	//( - , Baz1) ПС по периоду разгона канал 4
#define R0VN09RZ1	 BUFFER[439]	//( - , Baz1, SBz1DU) Усредненный период разгона
#define idR0VN09RZ1	 177	//( - , Baz1, SBz1DU) Усредненный период разгона
#define A3IS11LDU	 BUFFER[444]	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define idA3IS11LDU	 178	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define A3IS22LDU	 BUFFER[446]	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define idA3IS22LDU	 179	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define R0AD03LZ1	 BUFFER[448]	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define idR0AD03LZ1	 180	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define B3IS11LDU	 BUFFER[450]	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define idB3IS11LDU	 181	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define A3VZ31LZ1	 BUFFER[452]	//( - , Baz1) АЗ от ВУ ИС1
#define idA3VZ31LZ1	 182	//( - , Baz1) АЗ от ВУ ИС1
#define B3VZ31LZ1	 BUFFER[454]	//( - , Baz1) АЗ от ВУ ИС2
#define idB3VZ31LZ1	 183	//( - , Baz1) АЗ от ВУ ИС2
#define R0AD05LZ1	 BUFFER[456]	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define idR0AD05LZ1	 184	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define A3VZ11LZ1	 BUFFER[458]	//( - , Baz1) АЗ от НУП ИС1
#define idA3VZ11LZ1	 185	//( - , Baz1) АЗ от НУП ИС1
#define fEM_R0UT02RZZ	 BUFFER[460]	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	 186	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RZZ	 BUFFER[465]	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	 187	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_A2UP03RZZ	 BUFFER[470]	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define idfEM_A2UP03RZZ	 188	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define fEM_A2UP04RZZ	 BUFFER[475]	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define idfEM_A2UP04RZZ	 189	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define fEM_R0UT72RZZ	 BUFFER[480]	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	 190	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	 BUFFER[485]	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	 191	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	 BUFFER[490]	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	 192	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT61RZZ	 BUFFER[495]	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	 193	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_A2UP41RZZ	 BUFFER[500]	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define idfEM_A2UP41RZZ	 194	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define fEM_A2UP42RZZ	 BUFFER[505]	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define idfEM_A2UP42RZZ	 195	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define fEM_A2UP51RZZ	 BUFFER[510]	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define idfEM_A2UP51RZZ	 196	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define fEM_A2UP81RZZ	 BUFFER[515]	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP81RZZ	 197	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP84RZZ	 BUFFER[520]	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP84RZZ	 198	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP82RZZ	 BUFFER[525]	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP82RZZ	 199	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP52RZZ	 BUFFER[530]	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define idfEM_A2UP52RZZ	 200	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define fEM_A2UP83RZZ	 BUFFER[535]	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP83RZZ	 201	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_R0UR01RZZ	 BUFFER[540]	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RZZ	 202	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R0UR04RZZ	 BUFFER[545]	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define idfEM_R0UR04RZZ	 203	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define fEM_A1UL12RZZ	 BUFFER[550]	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
#define idfEM_A1UL12RZZ	 204	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
#define fEM_A1UL11RZZ	 BUFFER[555]	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
#define idfEM_A1UL11RZZ	 205	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
#define fEM_R7UI73RZZ	 BUFFER[560]	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define idfEM_R7UI73RZZ	 206	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define bFirstEnterFlag	 BUFFER[565]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 207	//(bFirstEnterFlag) 
#define internal1_m244_tx	 BUFFER[567]	//(internal1_m244_tx) tx - время накопленное сек
#define idinternal1_m244_tx	 208	//(internal1_m244_tx) tx - время накопленное сек
#define internal1_m244_y0	 BUFFER[572]	//(internal1_m244_y0) y0
#define idinternal1_m244_y0	 209	//(internal1_m244_y0) y0
#define internal1_m252_tx	 BUFFER[573]	//(internal1_m252_tx) tx - время накопленное сек
#define idinternal1_m252_tx	 210	//(internal1_m252_tx) tx - время накопленное сек
#define internal1_m252_y0	 BUFFER[578]	//(internal1_m252_y0) y0
#define idinternal1_m252_y0	 211	//(internal1_m252_y0) y0
#define internal1_m328_tx	 BUFFER[579]	//(internal1_m328_tx) tx - время накопленное сек
#define idinternal1_m328_tx	 212	//(internal1_m328_tx) tx - время накопленное сек
#define internal1_m328_y0	 BUFFER[584]	//(internal1_m328_y0) y0
#define idinternal1_m328_y0	 213	//(internal1_m328_y0) y0
#define internal1_m211_tx	 BUFFER[585]	//(internal1_m211_tx) tx - время накопленное сек
#define idinternal1_m211_tx	 214	//(internal1_m211_tx) tx - время накопленное сек
#define internal1_m211_y0	 BUFFER[590]	//(internal1_m211_y0) y0
#define idinternal1_m211_y0	 215	//(internal1_m211_y0) y0
#define internal1_m210_tx	 BUFFER[591]	//(internal1_m210_tx) tx - время накопленное сек
#define idinternal1_m210_tx	 216	//(internal1_m210_tx) tx - время накопленное сек
#define internal1_m210_y0	 BUFFER[596]	//(internal1_m210_y0) y0
#define idinternal1_m210_y0	 217	//(internal1_m210_y0) y0
#define internal1_m208_tx	 BUFFER[597]	//(internal1_m208_tx) tx - время накопленное сек
#define idinternal1_m208_tx	 218	//(internal1_m208_tx) tx - время накопленное сек
#define internal1_m208_y0	 BUFFER[602]	//(internal1_m208_y0) y0
#define idinternal1_m208_y0	 219	//(internal1_m208_y0) y0
#define internal1_m206_tx	 BUFFER[603]	//(internal1_m206_tx) tx - время накопленное сек
#define idinternal1_m206_tx	 220	//(internal1_m206_tx) tx - время накопленное сек
#define internal1_m206_y0	 BUFFER[608]	//(internal1_m206_y0) y0
#define idinternal1_m206_y0	 221	//(internal1_m206_y0) y0
#define internal1_m33_tx	 BUFFER[609]	//(internal1_m33_tx) tx - внутренний параметр
#define idinternal1_m33_tx	 222	//(internal1_m33_tx) tx - внутренний параметр
#define internal1_m143_y0	 BUFFER[612]	//(internal1_m143_y0) y0
#define idinternal1_m143_y0	 223	//(internal1_m143_y0) y0
#define internal1_m141_y0	 BUFFER[617]	//(internal1_m141_y0) y0
#define idinternal1_m141_y0	 224	//(internal1_m141_y0) y0
#define internal1_m91_y0	 BUFFER[622]	//(internal1_m91_y0) y0
#define idinternal1_m91_y0	 225	//(internal1_m91_y0) y0
#define internal1_m89_y0	 BUFFER[627]	//(internal1_m89_y0) y0
#define idinternal1_m89_y0	 226	//(internal1_m89_y0) y0
#define internal1_m154_y1	 BUFFER[632]	//(internal1_m154_y1) y1 - внутренний параметр
#define idinternal1_m154_y1	 227	//(internal1_m154_y1) y1 - внутренний параметр
#define internal1_m165_y1	 BUFFER[634]	//(internal1_m165_y1) y1 - внутренний параметр
#define idinternal1_m165_y1	 228	//(internal1_m165_y1) y1 - внутренний параметр
#define internal1_m316_q0	 BUFFER[636]	//(internal1_m316_q0) q0 - внутренний параметр
#define idinternal1_m316_q0	 229	//(internal1_m316_q0) q0 - внутренний параметр
#define internal1_m125_y0	 BUFFER[641]	//(internal1_m125_y0) state
#define idinternal1_m125_y0	 230	//(internal1_m125_y0) state
#define internal1_m121_y0	 BUFFER[643]	//(internal1_m121_y0) state
#define idinternal1_m121_y0	 231	//(internal1_m121_y0) state
#define internal1_m105_y1	 BUFFER[645]	//(internal1_m105_y1) y1 - внутренний параметр
#define idinternal1_m105_y1	 232	//(internal1_m105_y1) y1 - внутренний параметр
#define internal1_m118_y1	 BUFFER[647]	//(internal1_m118_y1) y1 - внутренний параметр
#define idinternal1_m118_y1	 233	//(internal1_m118_y1) y1 - внутренний параметр
#define internal1_m93_y1	 BUFFER[649]	//(internal1_m93_y1) y1 - внутренний параметр
#define idinternal1_m93_y1	 234	//(internal1_m93_y1) y1 - внутренний параметр
#define internal1_m103_y1	 BUFFER[651]	//(internal1_m103_y1) y1 - внутренний параметр
#define idinternal1_m103_y1	 235	//(internal1_m103_y1) y1 - внутренний параметр
#define internal1_m153_y1	 BUFFER[653]	//(internal1_m153_y1) y1 - внутренний параметр
#define idinternal1_m153_y1	 236	//(internal1_m153_y1) y1 - внутренний параметр
#define internal1_m163_y1	 BUFFER[655]	//(internal1_m163_y1) y1 - внутренний параметр
#define idinternal1_m163_y1	 237	//(internal1_m163_y1) y1 - внутренний параметр
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
	{ 9	,1	,1	, &R6IS66LZZ},	//( - , MBz1S) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 10	,1	,1	, &R6IS67LZZ},	//( - , MBz1S) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 11	,1	,1	, &R6IS68LZZ},	//( - , MBz1S) Исправность ВИП 4,0 (№7) ССДИ-2
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
	{ 47	,1	,1	, &R0DEB3LZ1},	//(sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
	{ 48	,1	,1	, &R0DE3CLZ1},	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 5
	{ 49	,1	,1	, &R0DE3DLZ1},	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 6
	{ 50	,1	,1	, &TestDiagnBaz1},	//( - , Baz1) Неисправность от диагностики
	{ 51	,3	,1	, &R0MW11IP1},	//( - , Baz1) Переключатель ВЫСТРЕЛ
	{ 52	,1	,1	, &PS1},	//( - , - ) АЗ по АС любого давления за АЗ1
	{ 53	,1	,1	, &PS2},	//( - , - ) АЗ от ВУ ИС1
	{ 54	,1	,1	, &PS3},	//( - , - ) АЗ от НУП ИС1
	{ 55	,1	,1	, &PS4},	//( - , - ) АС по температуру АЗ1
	{ 56	,1	,1	, &PS5},	//( - , - ) АС по периоду АЗ1
	{ 57	,1	,1	, &PS6},	//( - , - ) АС по мощности АЗ1
	{ 58	,1	,1	, &PS7},	//( - , - ) Исправность АКНП АЗ2
	{ 59	,1	,1	, &PS9},	//( - , - ) АС 1 ур (д2)
	{ 60	,1	,1	, &PS8},	//( - , - ) Исправность АКНП АЗ1
	{ 61	,1	,1	, &PS10},	//( - , - ) АС 1 ур (д1)
	{ 62	,1	,1	, &PS11},	//( - , - ) АС 2 ур
	{ 63	,1	,1	, &PS17},	//( - , - ) Аз по Ас любого давления АЗ2
	{ 64	,1	,1	, &PS16},	//( - , - ) АЗ от НУП ИС2
	{ 65	,1	,1	, &PS15},	//( - , - ) АЗ от ВУ ИС2
	{ 66	,1	,1	, &PS14},	//( - , - ) Ас по температура АЗ2
	{ 67	,1	,1	, &PS13},	//( - , - ) АС по периоду АЗ2
	{ 68	,1	,1	, &PS12},	//( - , - ) Ас по мощности АЗ2
	{ 69	,5	,1	, &R0VZ05U},	//( - , - ) причины сброса
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
	{ 120	,1	,1	, &A1VP41LZ1},	//( - , Baz1) Давление СБРОС ББ1 ниже АС
	{ 121	,1	,1	, &B1VP41LZ1},	//( - , Baz1) Давление СБРОС ББ2 ниже АС
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
	{ 139	,1	,1	, &B3VZ11LZ1},	//( - , Baz1) АЗ от НУП ИС2
	{ 140	,1	,1	, &B3IS22LDU},	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
	{ 141	,1	,1	, &R0VN69LZ1},	//( - , Baz1) ПС по усредненному периоду
	{ 142	,1	,1	, &R0VN79LZ1},	//( - , Baz1) АС по усредненному периоду
	{ 143	,8	,1	, &R0VR02RZ1},	//( - , Baz1) Усредненная реактивность
	{ 144	,1	,1	, &R0VZ71LZ1},	//(fds16:0a - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
	{ 145	,1	,1	, &R0VN70LZ1},	//( - , Baz1) АЗ по АС мощности РУ
	{ 146	,1	,1	, &R0VN80LZ1},	//( - , Baz1) АЗ по АС периода разгона РУ
	{ 147	,1	,1	, &A0EE01LS1},	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
	{ 148	,1	,1	, &A0EE01LS4},	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
	{ 149	,1	,1	, &A0EE01LS3},	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
	{ 150	,1	,1	, &A0EE01LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП1
	{ 151	,1	,1	, &A0EE04LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП4
	{ 152	,1	,1	, &A0EE02LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП2
	{ 153	,1	,1	, &A0EE03LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП3
	{ 154	,1	,1	, &A0EE01LS2},	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
	{ 155	,1	,1	, &A0EE05LZ1},	//( - , Baz1) Исправность сети АКНП1
	{ 156	,1	,1	, &A0EE06LZ1},	//( - , Baz1) Исправность сети АКНП2
	{ 157	,1	,1	, &A0EE07LZ1},	//( - , Baz1) Исправность сети АКНП3
	{ 158	,1	,1	, &A0EE08LZ1},	//( - , Baz1) Исправность сети АКНП4
	{ 159	,1	,1	, &A0VZ71LZ1},	//( - , Baz1) Обобщенный сигнал АС по АЗ1
	{ 160	,1	,1	, &A0EE00LZ1},	//( - , Baz1) Исправность АКНП АЗ1
	{ 161	,1	,1	, &B0EE00LZ1},	//( - , Baz1) Исправность АКНП АЗ2
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
	{ 177	,8	,1	, &R0VN09RZ1},	//( - , Baz1, SBz1DU) Усредненный период разгона
	{ 178	,1	,1	, &A3IS11LDU},	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
	{ 179	,1	,1	, &A3IS22LDU},	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
	{ 180	,1	,1	, &R0AD03LZ1},	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
	{ 181	,1	,1	, &B3IS11LDU},	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
	{ 182	,1	,1	, &A3VZ31LZ1},	//( - , Baz1) АЗ от ВУ ИС1
	{ 183	,1	,1	, &B3VZ31LZ1},	//( - , Baz1) АЗ от ВУ ИС2
	{ 184	,1	,1	, &R0AD05LZ1},	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
	{ 185	,1	,1	, &A3VZ11LZ1},	//( - , Baz1) АЗ от НУП ИС1
	{ 186	,8	,1	, &fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{ 187	,8	,1	, &fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{ 188	,8	,1	, &fEM_A2UP03RZZ},	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{ 189	,8	,1	, &fEM_A2UP04RZZ},	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{ 190	,8	,1	, &fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{ 191	,8	,1	, &fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{ 192	,8	,1	, &fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{ 193	,8	,1	, &fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{ 194	,8	,1	, &fEM_A2UP41RZZ},	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{ 195	,8	,1	, &fEM_A2UP42RZZ},	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{ 196	,8	,1	, &fEM_A2UP51RZZ},	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{ 197	,8	,1	, &fEM_A2UP81RZZ},	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{ 198	,8	,1	, &fEM_A2UP84RZZ},	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{ 199	,8	,1	, &fEM_A2UP82RZZ},	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{ 200	,8	,1	, &fEM_A2UP52RZZ},	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{ 201	,8	,1	, &fEM_A2UP83RZZ},	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{ 202	,8	,1	, &fEM_R0UR01RZZ},	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
	{ 203	,8	,1	, &fEM_R0UR04RZZ},	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
	{ 204	,8	,1	, &fEM_A1UL12RZZ},	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
	{ 205	,8	,1	, &fEM_A1UL11RZZ},	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
	{ 206	,8	,1	, &fEM_R7UI73RZZ},	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
	{ 207	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 208	,8	,1	, &internal1_m244_tx},	//(internal1_m244_tx) tx - время накопленное сек
	{ 209	,18	,1	, &internal1_m244_y0},	//(internal1_m244_y0) y0
	{ 210	,8	,1	, &internal1_m252_tx},	//(internal1_m252_tx) tx - время накопленное сек
	{ 211	,18	,1	, &internal1_m252_y0},	//(internal1_m252_y0) y0
	{ 212	,8	,1	, &internal1_m328_tx},	//(internal1_m328_tx) tx - время накопленное сек
	{ 213	,18	,1	, &internal1_m328_y0},	//(internal1_m328_y0) y0
	{ 214	,8	,1	, &internal1_m211_tx},	//(internal1_m211_tx) tx - время накопленное сек
	{ 215	,18	,1	, &internal1_m211_y0},	//(internal1_m211_y0) y0
	{ 216	,8	,1	, &internal1_m210_tx},	//(internal1_m210_tx) tx - время накопленное сек
	{ 217	,18	,1	, &internal1_m210_y0},	//(internal1_m210_y0) y0
	{ 218	,8	,1	, &internal1_m208_tx},	//(internal1_m208_tx) tx - время накопленное сек
	{ 219	,18	,1	, &internal1_m208_y0},	//(internal1_m208_y0) y0
	{ 220	,8	,1	, &internal1_m206_tx},	//(internal1_m206_tx) tx - время накопленное сек
	{ 221	,18	,1	, &internal1_m206_y0},	//(internal1_m206_y0) y0
	{ 222	,3	,1	, &internal1_m33_tx},	//(internal1_m33_tx) tx - внутренний параметр
	{ 223	,8	,1	, &internal1_m143_y0},	//(internal1_m143_y0) y0
	{ 224	,8	,1	, &internal1_m141_y0},	//(internal1_m141_y0) y0
	{ 225	,8	,1	, &internal1_m91_y0},	//(internal1_m91_y0) y0
	{ 226	,8	,1	, &internal1_m89_y0},	//(internal1_m89_y0) y0
	{ 227	,1	,1	, &internal1_m154_y1},	//(internal1_m154_y1) y1 - внутренний параметр
	{ 228	,1	,1	, &internal1_m165_y1},	//(internal1_m165_y1) y1 - внутренний параметр
	{ 229	,5	,1	, &internal1_m316_q0},	//(internal1_m316_q0) q0 - внутренний параметр
	{ 230	,1	,1	, &internal1_m125_y0},	//(internal1_m125_y0) state
	{ 231	,1	,1	, &internal1_m121_y0},	//(internal1_m121_y0) state
	{ 232	,1	,1	, &internal1_m105_y1},	//(internal1_m105_y1) y1 - внутренний параметр
	{ 233	,1	,1	, &internal1_m118_y1},	//(internal1_m118_y1) y1 - внутренний параметр
	{ 234	,1	,1	, &internal1_m93_y1},	//(internal1_m93_y1) y1 - внутренний параметр
	{ 235	,1	,1	, &internal1_m103_y1},	//(internal1_m103_y1) y1 - внутренний параметр
	{ 236	,1	,1	, &internal1_m153_y1},	//(internal1_m153_y1) y1 - внутренний параметр
	{ 237	,1	,1	, &internal1_m163_y1},	//(internal1_m163_y1) y1 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="baz1.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{186,"fEM_R0UT02RZZ\0"}, 
{187,"fEM_R0UT01RZZ\0"}, 
{188,"fEM_A2UP03RZZ\0"}, 
{189,"fEM_A2UP04RZZ\0"}, 
{190,"fEM_R0UT72RZZ\0"}, 
{191,"fEM_R0UT71RZZ\0"}, 
{192,"fEM_R0UT62RZZ\0"}, 
{193,"fEM_R0UT61RZZ\0"}, 
{194,"fEM_A2UP41RZZ\0"}, 
{195,"fEM_A2UP42RZZ\0"}, 
{196,"fEM_A2UP51RZZ\0"}, 
{197,"fEM_A2UP81RZZ\0"}, 
{198,"fEM_A2UP84RZZ\0"}, 
{199,"fEM_A2UP82RZZ\0"}, 
{200,"fEM_A2UP52RZZ\0"}, 
{201,"fEM_A2UP83RZZ\0"}, 
{202,"fEM_R0UR01RZZ\0"}, 
{203,"fEM_R0UR04RZZ\0"}, 
{204,"fEM_A1UL12RZZ\0"}, 
{205,"fEM_A1UL11RZZ\0"}, 
{206,"fEM_R7UI73RZZ\0"}, 
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
	{&R6IS66LZZ,1,0},	//( - K17DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{&R6IS67LZZ,1,1},	//( - K18DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{&R6IS68LZZ,1,2},	//( - K19DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№7) ССДИ-2
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
	{&B0IT01IZ1,3,6},
	{&R0DE04LZ1,3,26},
	{&B2IP01IZ1,3,9},
	{&A2IP01IZ1,3,3},
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
	{&B2IS12LDU,1,20},
	{&R0DE05LZ1,3,64},
	{&R0AD04LZ1,1,14},
	{&A3IS22LDU,1,10},
	{&A2IS12LDU,1,18},
	{&R0AD03LZ1,1,12},
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
static char buf_VDS322[66];	//VDS32
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
static char buf_VDS323[66];	//VDS32
static vds32r_inipar ini_VDS323={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS323={0,0,&ini_VDS323,buf_VDS323,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS323[]={
	{&R0VN74LZ1,1,0},
	{&R0VN78LZ1,1,2},
	{&A0VN71LS4,1,6},
	{&R0DE07LZ1,3,64},
	{&A0EE01LS4,1,4},
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
	{&R0DE34LZ1,1,6},
	{&R0DE33LZ1,1,4},
	{&R0DE36LZ1,1,10},
	{&R0DE37LZ1,1,12},
	{&R0DE35LZ1,1,8},
	{&R0DE39LZ1,1,16},
	{&R0DE32LZ1,1,2},
	{&R0DE31LZ1,1,0},
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
	setAsFloat(186,600);
	setAsFloat(187,0);
	setAsFloat(188,1.6);
	setAsFloat(189,0);
	setAsFloat(190,150);
	setAsFloat(191,200);
	setAsFloat(192,90);
	setAsFloat(193,100);
	setAsFloat(194,0.1);
	setAsFloat(195,0.13);
	setAsFloat(196,0.16);
	setAsFloat(197,0.17);
	setAsFloat(198,0.31);
	setAsFloat(199,0.2);
	setAsFloat(200,0.19);
	setAsFloat(201,0.28);
	setAsFloat(202,15);
	setAsFloat(203,10);
	setAsFloat(204,0.180);
	setAsFloat(205,0.020);
	setAsFloat(206,0.045);
}

uspaint8 InternalBuf[99];

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
ssint iRM_1_ = {1,0}; /* x2 - ������ ��������� */ 
ssint iRM_2_ = {2,0}; /* n - ����������� �������� ������� */ 

uspaint8 SpaEEPROMBuf[105];

/* ����������� ���������� */
ssbool var1;
ssbool var2;
ssbool var3;
ssbool var4;
ssbool var5;
ssbool var6;
ssint var7;
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
ssfloat var133;
ssfloat var134;
ssbool var135;
ssfloat var136;
ssfloat var137;
ssbool var138;
ssbool var139;
ssbool var140;
ssbool var141;
ssbool var142;
ssbool var143;
ssfloat var144;
sslong var145;
sslong var146;
ssbool var147;
ssbool var148;
ssbool var149;
ssbool var150;
ssbool var151;
ssbool var152;
ssbool var153;
ssbool var154;
ssbool var155;
ssfloat var156;
ssbool var157;
ssbool var158;
ssfloat var159;
ssbool var160;
ssbool var161;
sschar var162;
ssbool var163;
sschar var164;
ssbool var165;
ssbool var166;
ssbool var167;
ssbool var168;
ssbool var169;
ssbool var170;
ssbool var171;
ssbool var172;
ssbool var173;
ssbool var174;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* ���������� �������� */
psbool  array_m378_x_1[6] = {&var4,&var3,&R0DE36LZ1,&R0DE37LZ1,&R0DE38LZ1,&R0DE39LZ1};
psint  array_m365_x_1[6] = {&R0DE04LZ1,&R0DE05LZ1,&R0DE06LZ1,&R0DE0ALZ1,&R0DE08LZ1,&R0DE07LZ1};
psfloat  array_m188_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psfloat  array_m348_x_1[4] = {&R0VN02RS1,&R0VN02RS2,&R0VN02RS3,&R0VN02RS4};
psbool  array_m348_diag_1[4] = {&var28,&var29,&var30,&var31};
psbool  array_m323_x_1[17] = {&var90,&var56,&var57,&var85,&var40,&var43,&var161,&var55,&var51,&var50,&var86,&var46,&var44,&var163,&var54,&var53,&var52};
psbool  array_m16_x_1[6] = {&var95,&var86,&var44,&var46,&var104,&var163};
psbool  array_m36_x_1[6] = {&var85,&var40,&var43,&var161,&var93,&var104};
psfloat  array_m2_x_1[4] = {&R0VN01RS1,&R0VN01RS2,&R0VN01RS3,&R0VN01RS4};
psbool  array_m2_diag_1[4] = {&var28,&var29,&var30,&var31};
psbool  array_m3_x_1[3] = {&var114,&var143,&var26};
psbool  array_m12_x_1[3] = {&var113,&var27,&var115};

/* ���������� �������� */
_S_or3  S_or3_379_1 = {&var6,&var5,&var2,&var1};
_S_orn  S_orn_378_1 = {array_m378_x_1,&iRM_6_,&var2};
_S_or2  S_or2_384_1 = {&R0DEB3LZ1,&R0DEB4LZ1,&var3};
_S_or2  S_or2_376_1 = {&R0DEB1LZ1,&R0DEB2LZ1,&var4};
_S_and2  S_and2_367_1 = {&R0DE31LZ1,&R0DE32LZ1,&var5};
_S_diagndev  S_diagndev_365_1 = {array_m365_x_1,&iRM_6_,&var6,&var7};
_S_ma  S_ma_188_1 = {array_m188_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_and3  S_and3_232_1 = {&var11,&var21,&var20,&var8};
_S_and3  S_and3_229_1 = {&var21,&var11,&var130,&var9};
_S_and3  S_and3_228_1 = {&var20,&var11,&var129,&var10};
_S_noto  S_noto_220_1 = {&R0AD03LZ1,&var11};
_S_and3  S_and3_226_1 = {&var14,&var17,&var16,&var12};
_S_and3  S_and3_222_1 = {&var14,&var16,&var132,&var13};
_S_noto  S_noto_214_1 = {&R0AD05LZ1,&var14};
_S_and3  S_and3_221_1 = {&var14,&var17,&var131,&var15};
_S_and2  S_and2_215_1 = {&var108,&R0VW23LDU,&var16};
_S_and2  S_and2_213_1 = {&var109,&R0VW13LDU,&var17};
_S_and3  S_and3_207_1 = {&var109,&var108,&R0AD05LZ1,&var18};
_S_and3  S_and3_212_1 = {&var107,&var106,&R0AD03LZ1,&var19};
_S_and2  S_and2_216_1 = {&var107,&R0VW13LDU,&var20};
_S_and2  S_and2_217_1 = {&R0VW23LDU,&var106,&var21};
_S_and2  S_and2_251_1 = {&var128,&var38,&var22};
_S_zzfs  S_zzfs_244_1 = {&R0AD14LDU,&fRM_1_0,&var23,&internal1_m244_tx,&internal1_m244_y0};
_S_and2  S_and2_124_1 = {&var166,&var142,&var24};
_S_and2  S_and2_133_1 = {&var165,&var141,&var25};
_S_or2  S_or2_102_1 = {&var172,&var170,&var26};
_S_or2  S_or2_106_1 = {&var167,&var168,&var27};
_S_and2  S_and2_80_1 = {&A0EE05LZ1,&A0EE01LS1,&var28};
_S_and2  S_and2_82_1 = {&A0EE06LZ1,&A0EE01LS2,&var29};
_S_and2  S_and2_84_1 = {&A0EE07LZ1,&A0EE01LS3,&var30};
_S_and2  S_and2_86_1 = {&A0EE08LZ1,&A0EE01LS4,&var31};
_S_and2  S_and2_178_1 = {&var158,&var123,&var32};
_S_and2  S_and2_179_1 = {&var157,&var123,&var33};
_S_or2  S_or2_255_1 = {&var111,&R7II73LZ1,&var34};
_S_or2  S_or2_257_1 = {&R0AD21LDU,&R0AD14LDU,&var35};
_S_and2  S_and2_256_1 = {&var35,&var34,&var36};
_S_or2  S_or2_249_1 = {&R7II71LZ1,&var110,&var37};
_S_or3  S_or3_250_1 = {&var39,&var37,&var36,&var38};
_S_or2  S_or2_243_1 = {&var112,&R7II72LZ1,&var39};
_S_or2  S_or2_230_1 = {&var15,&var12,&var40};
_S_or2  S_or2_199_1 = {&A3IS22LDU,&R0AD05LZ1,&var41};
_S_or2  S_or2_201_1 = {&B3IS22LDU,&R0AD05LZ1,&var42};
_S_or2  S_or2_233_1 = {&var10,&var8,&var43};
_S_or2  S_or2_234_1 = {&var9,&var8,&var44};
_S_or2  S_or2_202_1 = {&var127,&R0AD03LZ1,&var45};
_S_or2  S_or2_231_1 = {&var13,&var12,&var46};
_S_or2  S_or2_204_1 = {&var126,&R0AD03LZ1,&var47};
_S_schl24  S_schl24_350_1 = {&A0VN71LS2,&A0VN71LS1,&A0VN71LS4,&A0VN71LS3,&var48};
_S_and2  S_and2_336_1 = {&var122,&var121,&var49};
_S_and2  S_and2_325_1 = {&var69,&var91,&var50};
_S_and2  S_and2_327_1 = {&var76,&var91,&var51};
_S_and2  S_and2_333_1 = {&var36,&var105,&var52};
_S_and2  S_and2_332_1 = {&var37,&var105,&var53};
_S_and2  S_and2_331_1 = {&var39,&var105,&var54};
_S_and2  S_and2_329_1 = {&var124,&var91,&var55};
_S_and2  S_and2_326_1 = {&var80,&var91,&var56};
_S_and2  S_and2_324_1 = {&var62,&var91,&var57};
_S_and2  S_and2_297_1 = {&var60,&var59,&var58};
_S_or2  S_or2_299_1 = {&R0VN75LZ1,&var155,&var59};
_S_or2  S_or2_300_1 = {&R0VN77LZ1,&var154,&var60};
_S_or2  S_or2_285_1 = {&var58,&var66,&var61};
_S_or2  S_or2_291_1 = {&var63,&var58,&var62};
_S_and2  S_and2_292_1 = {&var150,&var67,&var63};
_S_or2  S_or2_302_1 = {&R0VN78LZ1,&var152,&var64};
_S_or2  S_or2_301_1 = {&R0VN76LZ1,&var153,&var65};
_S_and2  S_and2_298_1 = {&var65,&var64,&var66};
_S_schl24  S_schl24_296_1 = {&var65,&var64,&var60,&var59,&var67};
_S_and2  S_and2_294_1 = {&var91,&var67,&var68};
_S_or2  S_or2_293_1 = {&var66,&var63,&var69};
_S_and2  S_and2_289_1 = {&var69,&var91,&var70};
_S_or2  S_or2_265_1 = {&R0VN72LZ1,&var153,&var71};
_S_and2  S_and2_280_1 = {&var80,&var91,&var72};
_S_and2  S_and2_269_1 = {&var71,&var74,&var73};
_S_or2  S_or2_266_1 = {&R0VN74LZ1,&var152,&var74};
_S_and2  S_and2_281_1 = {&var76,&var91,&var75};
_S_or2  S_or2_278_1 = {&var73,&var79,&var76};
_S_or2  S_or2_284_1 = {&var81,&var73,&var77};
_S_and2  S_and2_272_1 = {&var83,&var91,&var78};
_S_and2  S_and2_277_1 = {&var151,&var83,&var79};
_S_or2  S_or2_276_1 = {&var81,&var79,&var80};
_S_and2  S_and2_267_1 = {&var82,&var84,&var81};
_S_or2  S_or2_264_1 = {&R0VN73LZ1,&var154,&var82};
_S_schl24  S_schl24_268_1 = {&var82,&var84,&var71,&var74,&var83};
_S_or2  S_or2_263_1 = {&R0VN71LZ1,&var155,&var84};
_S_or2  S_or2_152_1 = {&var135,&var173,&var85};
_S_or2  S_or2_150_1 = {&var140,&var138,&var86};
_S_or2  S_or2_354_1 = {&var171,&var169,&var87};
_S_or2  S_or2_35_1 = {&B2IS12LDU,&A2IS12LDU,&var88};
_S_and2  S_and2_288_1 = {&var91,&var62,&var89};
_S_and2  S_and2_330_1 = {&var125,&var91,&var90};
_S_and2  S_and2_21_1 = {&var120,&var116,&var91};
_S_or2  S_or2_25_1 = {&var148,&var147,&var92};
_S_and2  S_and2_31_1 = {&var94,&var91,&var93};
_S_or3  S_or3_30_1 = {&var62,&var80,&var119,&var94};
_S_and2  S_and2_19_1 = {&var91,&var96,&var95};
_S_or3  S_or3_18_1 = {&var76,&var69,&var118,&var96};
_S_and2  S_and2_6_1 = {&var29,&var31,&var97};
_S_or2  S_or2_10_1 = {&var149,&var97,&var98};
_S_or2  S_or2_9_1 = {&var100,&var149,&var99};
_S_and2  S_and2_5_1 = {&var28,&var30,&var100};
_S_and2  S_and2_189_1 = {&R0AD14LDU,&R7II72LZ1,&var101};
_S_and2  S_and2_185_1 = {&R0AD14LDU,&R7II71LZ1,&var102};
_S_and2  S_and2_182_1 = {&R0AD14LDU,&R7II73LZ1,&var103};
_S_zpfs  S_zpfs_252_1 = {&var22,&fEM_R7UI73RZZ,&var104,&internal1_m252_tx,&internal1_m252_y0};
_S_zpfs  S_zpfs_328_1 = {&var49,&fRM_0_2,&var105,&internal1_m328_tx,&internal1_m328_y0};
_S_zpfs  S_zpfs_211_1 = {&var47,&fEM_A1UL11RZZ,&var106,&internal1_m211_tx,&internal1_m211_y0};
_S_zpfs  S_zpfs_210_1 = {&var45,&fEM_A1UL11RZZ,&var107,&internal1_m210_tx,&internal1_m210_y0};
_S_zpfs  S_zpfs_208_1 = {&var42,&fEM_A1UL12RZZ,&var108,&internal1_m208_tx,&internal1_m208_y0};
_S_zpfs  S_zpfs_206_1 = {&var41,&fEM_A1UL12RZZ,&var109,&internal1_m206_tx,&internal1_m206_y0};
_S_noto  S_noto_248_1 = {&R6IS67LZZ,&var110};
_S_noto  S_noto_254_1 = {&R6IS68LZZ,&var111};
_S_noto  S_noto_237_1 = {&R6IS66LZZ,&var112};
_S_noto  S_noto_132_1 = {&B0VP81LZZ,&var113};
_S_noto  S_noto_131_1 = {&A0VP81LZZ,&var114};
_S_noto  S_noto_109_1 = {&B1VP81LZZ,&var115};
_S_noto  S_noto_27_1 = {&var117,&var116};
_S_ovb1  S_ovb1_33_1 = {&var88,&iRM_200_,&var117,&internal1_m33_tx};
_S_noto  S_noto_14_1 = {&var98,&var118};
_S_noto  S_noto_13_1 = {&var99,&var119};
_S_noto  S_noto_24_1 = {&R0EE02LDU,&var120};
_S_noto  S_noto_339_1 = {&R0AD16LDU,&var121};
_S_noto  S_noto_338_1 = {&R0AD04LZ1,&var122};
_S_bol  S_bol_174_1 = {&var159,&fRM_0_00001,&var123};
_S_noto  S_noto_334_1 = {&var98,&var124};
_S_noto  S_noto_335_1 = {&var99,&var125};
_S_noto  S_noto_198_1 = {&B3IS11LDU,&var126};
_S_noto  S_noto_197_1 = {&A3IS11LDU,&var127};
_S_noto  S_noto_245_1 = {&var23,&var128};
_S_noto  S_noto_224_1 = {&R0VW23LDU,&var129};
_S_noto  S_noto_223_1 = {&R0VW13LDU,&var130};
_S_noto  S_noto_219_1 = {&R0VW23LDU,&var131};
_S_noto  S_noto_218_1 = {&R0VW13LDU,&var132};
_S_scalzz  S_scalzz_143_1 = {&B0IT01IZ1,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var133,&internal1_m143_y0};
_S_scalzz  S_scalzz_141_1 = {&A0IT01IZ1,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var134,&internal1_m141_y0};
_S_geterr  S_geterr_145_1 = {&var134,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var135};
_S_scalzz  S_scalzz_91_1 = {&B2IP01IZ1,&iRM_3276_,&iRM_16383_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var136,&internal1_m91_y0};
_S_scalzz  S_scalzz_89_1 = {&A2IP01IZ1,&iRM_3276_,&iRM_16383_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var137,&internal1_m89_y0};
_S_drg  S_drg_154_1 = {&var133,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var138,&internal1_m154_y1};
_S_drg  S_drg_165_1 = {&var133,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var139,&internal1_m165_y1};
_S_geterr  S_geterr_147_1 = {&var133,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var140};
_S_noto  S_noto_134_1 = {&var167,&var141};
_S_noto  S_noto_123_1 = {&var172,&var142};
_S_noto  S_noto_108_1 = {&A1VP81LZZ,&var143};
_S_srm  S_srm_348_1 = {array_m348_x_1,array_m348_diag_1,&iRM_4_,&iRM_3_,&var144,&vainSBool};
_S_rsu  S_rsu_316_1 = {&R0MD34LP1,&var146,&var145,&internal1_m316_q0};
_S_orni  S_orni_323_1 = {array_m323_x_1,&iRM_17_,&vainSBool,&var146};
_S_orn  S_orn_16_1 = {array_m16_x_1,&iRM_6_,&var147};
_S_orn  S_orn_36_1 = {array_m36_x_1,&iRM_6_,&var148};
_S_noto  S_noto_7_1 = {&var160,&var149};
_S_noto  S_noto_287_1 = {&var61,&var150};
_S_noto  S_noto_282_1 = {&var77,&var151};
_S_noto  S_noto_271_1 = {&A0EE01LS4,&var152};
_S_noto  S_noto_275_1 = {&A0EE01LS2,&var153};
_S_noto  S_noto_274_1 = {&A0EE01LS3,&var154};
_S_noto  S_noto_270_1 = {&A0EE01LS1,&var155};
_S_react  S_react_170_1 = {&var159,&var156};
_S_bol  S_bol_175_1 = {&fEM_R0UR04RZZ,&var159,&var157};
_S_bol  S_bol_173_1 = {&fEM_R0UR01RZZ,&var159,&var158};
_S_srm  S_srm_2_1 = {array_m2_x_1,array_m2_diag_1,&iRM_4_,&iRM_3_,&var159,&var160};
_S_ornc  S_ornc_3_1 = {array_m3_x_1,&iRM_3_,&var161,&var162};
_S_ornc  S_ornc_12_1 = {array_m12_x_1,&iRM_3_,&var163,&var164};
_S_tprg  S_tprg_125_1 = {&var136,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var165,&internal1_m125_y0};
_S_tprg  S_tprg_121_1 = {&var137,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var166,&internal1_m121_y0};
_S_geterr  S_geterr_100_1 = {&var136,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var167};
_S_drg  S_drg_105_1 = {&var136,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var168,&internal1_m105_y1};
_S_drg  S_drg_118_1 = {&var136,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var169,&internal1_m118_y1};
_S_drg  S_drg_93_1 = {&var137,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var170,&internal1_m93_y1};
_S_drg  S_drg_103_1 = {&var137,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var171,&internal1_m103_y1};
_S_geterr  S_geterr_97_1 = {&var137,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var172};
_S_drg  S_drg_153_1 = {&var134,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var173,&internal1_m153_y1};
_S_drg  S_drg_163_1 = {&var134,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var174,&internal1_m163_y1};


int freebuff = 0, delay = 0;
void Scheme()
{
if ((getAsShort(idR0MW11IP1) == 2) || (getAsShort(idR0MW11IP1) == 3)) { 
     if(delay++ < 100) return;
     freebuff = 0;
     delay = delay > 32000 ? 32000 : delay; 
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  noto(&S_noto_270_1);
  noto(&S_noto_274_1);
  noto(&S_noto_275_1);
  noto(&S_noto_271_1);
  noto(&S_noto_108_1);
  scalzz(&S_scalzz_89_1);
  scalzz(&S_scalzz_91_1);
  scalzz(&S_scalzz_141_1);
  scalzz(&S_scalzz_143_1);
  noto(&S_noto_219_1);
  noto(&S_noto_223_1);
  noto(&S_noto_224_1);
  noto(&S_noto_197_1);
  noto(&S_noto_198_1);
  noto(&S_noto_24_1);
  noto(&S_noto_109_1);
  noto(&S_noto_131_1);
  noto(&S_noto_132_1);
  noto(&S_noto_237_1);
  noto(&S_noto_254_1);
  noto(&S_noto_248_1);
  and2(&S_and2_182_1);
  and2(&S_and2_185_1);
  and2(&S_and2_189_1);
  or2(&S_or2_263_1);
  or2(&S_or2_264_1);
  and2(&S_and2_267_1);
  or2(&S_or2_266_1);
  or2(&S_or2_265_1);
  or2(&S_or2_301_1);
  or2(&S_or2_302_1);
  or2(&S_or2_300_1);
  or2(&S_or2_299_1);
  and2(&S_and2_297_1);
  schl24(&S_schl24_350_1);
  or2(&S_or2_204_1);
  or2(&S_or2_202_1);
  or2(&S_or2_201_1);
  or2(&S_or2_199_1);
  or2(&S_or2_243_1);
  or2(&S_or2_249_1);
  or2(&S_or2_257_1);
  or2(&S_or2_255_1);
  and2(&S_and2_86_1);
  and2(&S_and2_84_1);
  and2(&S_and2_82_1);
  and2(&S_and2_80_1);
  zzfs(&S_zzfs_244_1);
  noto(&S_noto_214_1);
  noto(&S_noto_220_1);
  ma(&S_ma_188_1);
  and2(&S_and2_367_1);
  or2(&S_or2_376_1);
  or2(&S_or2_384_1);
  orn(&S_orn_378_1);
  drg(&S_drg_163_1);
  drg(&S_drg_153_1);
  geterr(&S_geterr_97_1);
  drg(&S_drg_103_1);
  drg(&S_drg_93_1);
  drg(&S_drg_118_1);
  drg(&S_drg_105_1);
  geterr(&S_geterr_100_1);
  tprg(&S_tprg_121_1);
  tprg(&S_tprg_125_1);
  srm(&S_srm_2_1);
  bol(&S_bol_173_1);
  bol(&S_bol_175_1);
  react(&S_react_170_1);
  noto(&S_noto_7_1);
  srm(&S_srm_348_1);
  noto(&S_noto_123_1);
  noto(&S_noto_134_1);
  geterr(&S_geterr_147_1);
  drg(&S_drg_165_1);
  drg(&S_drg_154_1);
  geterr(&S_geterr_145_1);
  noto(&S_noto_218_1);
  noto(&S_noto_245_1);
  bol(&S_bol_174_1);
  noto(&S_noto_338_1);
  noto(&S_noto_339_1);
  zpfs(&S_zpfs_206_1);
  zpfs(&S_zpfs_208_1);
  zpfs(&S_zpfs_210_1);
  zpfs(&S_zpfs_211_1);
  and2(&S_and2_5_1);
  or2(&S_or2_9_1);
  and2(&S_and2_6_1);
  or2(&S_or2_35_1);
  or2(&S_or2_354_1);
  or2(&S_or2_150_1);
  or2(&S_or2_152_1);
  schl24(&S_schl24_268_1);
  and2(&S_and2_269_1);
  schl24(&S_schl24_296_1);
  and2(&S_and2_298_1);
  or2(&S_or2_285_1);
  and2(&S_and2_336_1);
  and2(&S_and2_256_1);
  and2(&S_and2_179_1);
  and2(&S_and2_178_1);
  or2(&S_or2_106_1);
  or2(&S_or2_102_1);
  and2(&S_and2_133_1);
  and2(&S_and2_124_1);
  and2(&S_and2_217_1);
  and2(&S_and2_216_1);
  and3(&S_and3_212_1);
  and3(&S_and3_207_1);
  and2(&S_and2_213_1);
  and2(&S_and2_215_1);
  and3(&S_and3_221_1);
  and3(&S_and3_222_1);
  and3(&S_and3_226_1);
  and3(&S_and3_228_1);
  and3(&S_and3_229_1);
  and3(&S_and3_232_1);
  diagndev(&S_diagndev_365_1);
  or3(&S_or3_379_1);
  ornc(&S_ornc_12_1);
  ornc(&S_ornc_3_1);
  noto(&S_noto_287_1);
  noto(&S_noto_335_1);
  noto(&S_noto_13_1);
  ovb1(&S_ovb1_33_1);
  noto(&S_noto_27_1);
  zpfs(&S_zpfs_328_1);
  or2(&S_or2_10_1);
  and2(&S_and2_21_1);
  and2(&S_and2_330_1);
  and2(&S_and2_272_1);
  or2(&S_or2_284_1);
  and2(&S_and2_294_1);
  and2(&S_and2_292_1);
  or2(&S_or2_291_1);
  and2(&S_and2_324_1);
  and2(&S_and2_331_1);
  and2(&S_and2_332_1);
  and2(&S_and2_333_1);
  or2(&S_or2_231_1);
  or2(&S_or2_234_1);
  or2(&S_or2_233_1);
  or2(&S_or2_230_1);
  or3(&S_or3_250_1);
  and2(&S_and2_251_1);
  noto(&S_noto_282_1);
  noto(&S_noto_334_1);
  noto(&S_noto_14_1);
  zpfs(&S_zpfs_252_1);
  and2(&S_and2_288_1);
  and2(&S_and2_277_1);
  or2(&S_or2_278_1);
  and2(&S_and2_281_1);
  or2(&S_or2_293_1);
  and2(&S_and2_329_1);
  and2(&S_and2_327_1);
  and2(&S_and2_325_1);
  or3(&S_or3_18_1);
  and2(&S_and2_19_1);
  or2(&S_or2_276_1);
  and2(&S_and2_280_1);
  and2(&S_and2_289_1);
  and2(&S_and2_326_1);
  orn(&S_orn_16_1);
  orni(&S_orni_323_1);
  rsu(&S_rsu_316_1);
  or3(&S_or3_30_1);
  and2(&S_and2_31_1);
  orn(&S_orn_36_1);
  or2(&S_or2_25_1);
  setData(idR0VZ05U,&var146);
  setData(idPS12,&var76);
  setData(idPS13,&var69);
  setData(idPS14,&var86);
  setData(idPS15,&var44);
  setData(idPS16,&var46);
  setData(idPS17,&var163);
  setData(idPS11,&var36);
  setData(idPS10,&var37);
  setData(idPS8,&var99);
  setData(idPS9,&var39);
  setData(idPS7,&var98);
  setData(idPS6,&var80);
  setData(idPS5,&var62);
  setData(idPS4,&var85);
  setData(idPS3,&var40);
  setData(idPS2,&var43);
  setData(idPS1,&var161);
  setData(idTestDiagnBaz1,&var1);
  setData(idR0DE3DLZ1,&var3);
  setData(idR0DE3CLZ1,&var4);
  setData(idTTLBaz1,&var7);
  setData(idR0AD16LZ1,&var101);
  setData(idR0AD15LZ1,&var102);
  moveData(idR0EE04LZ1,idR0EE02LDU);
  moveData(idR0EE03LZ1,idR0EE02LDU);
  moveData(idR0EE02LZ1,idR0EE02LDU);
  moveData(idR0EE01LZ1,idR0EE02LDU);
  setData(idR0AD14LZ1,&var103);
  setData(idA3VZ13LZ1,&var19);
  setData(idA3VZ15LZ1,&var18);
  setData(idA1VN71LZ1,&var48);
  setData(idB0VT71LZ1,&var86);
  setData(idB0VT61LZ1,&var139);
  setData(idB0CT01IZ1,&var133);
  setData(idR0VP73LZ1,&var87);
  setData(idR0VN11RZ1,&var144);
  setData(idR0VZ05UZ1,&var145);
  setData(idB0VN81LZ1,&var70);
  setData(idA0VN81LZ1,&var89);
  setData(idB0VN71LZ1,&var75);
  setData(idA0VN71LZ1,&var72);
  setData(idB0VZ71LZ1,&var147);
  setData(idB0EE00LZ1,&var98);
  setData(idA0EE00LZ1,&var99);
  setData(idA0VZ71LZ1,&var148);
  setData(idA0EE03LZ1,&var30);
  setData(idA0EE02LZ1,&var29);
  setData(idA0EE04LZ1,&var31);
  setData(idA0EE01LZ1,&var28);
  setData(idR0VN80LZ1,&var68);
  setData(idR0VN70LZ1,&var78);
  setData(idR0VZ71LZ1,&var92);
  setData(idR0VR02RZ1,&var156);
  setData(idR0VN79LZ1,&var33);
  setData(idR0VN69LZ1,&var32);
  setData(idB3VZ11LZ1,&var46);
  setData(idA3VZ11LZ1,&var40);
  setData(idB3VZ31LZ1,&var44);
  setData(idA3VZ31LZ1,&var43);
  setData(idR0VN09RZ1,&var159);
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
  setData(idB0VP71LZ1,&var163);
  setData(idA0VP71LZ1,&var161);
  setData(idA0EP02IZ1,&var162);
  setData(idB0EP02IZ1,&var164);
  setData(idR0ET02LZ1,&var140);
  setData(idB0VP41LZ1,&var113);
  setData(idA0VP41LZ1,&var114);
  setData(idR0ET01LZ1,&var135);
  setData(idA2VP81LZ1,&var24);
  setData(idB2VP81LZ1,&var25);
  setData(idB2VP51LZ1,&var169);
  setData(idB2CP01RZ1,&var136);
  setData(idB2VP41LZ1,&var27);
  setData(idA2VP51LZ1,&var171);
  setData(idA2CP01RZ1,&var137);
  setData(idA2VP41LZ1,&var26);
  setData(idB1VP41LZ1,&var115);
  setData(idA1VP41LZ1,&var143);
  setData(idA0VT71LZ1,&var85);
  setData(idA0VT61LZ1,&var174);
  setData(idA0CT01IZ1,&var134);

  setAsBool(idbFirstEnterFlag,1); 
 }
 else {
      delay = 0;
      if (freebuff)
            return;
       else{
           freebuff = 1;
           memset(BUFFER, 0, SIZE_BUFFER);
           InitSetConst();
           initAllDrivers(drivers);
           }
       }

}

void InitInternalParametr(void)
{
  int i;
}

#endif
