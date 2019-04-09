#ifndef BAZ1_H
#define BAZ1_H
// Подсистема Baz1:Baz1
static char SimulOn=0;
static short CodeSub=4;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
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
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz1A1[]={  // 
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
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz1A2[]={  // 
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
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz1A3[]={  // 
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
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz1A4[]={  // 
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
// checked_ 0  |  if( not aknp||rpu) AddCodeAknp()
// checked_ 1  | if(ExistFile(Scheme.h)) AddCode_H(  Baz1\Scheme\Scheme.h
// Baz1\Scheme\Scheme.h
#endif
