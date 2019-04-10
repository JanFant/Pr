#ifndef BAZ2_H
#define BAZ2_H
// Подсистема Baz2:Baz2
static char SimulOn=0;
static short CodeSub=6;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 657
static char BUFFER[657];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.54\0", 5432, "192.168.10.154\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0AD21LDU	 BUFFER[0]	//( - , SBz2DU) Подключить защиту от II УР
#define idR0AD21LDU	 1	//( - , SBz2DU) Подключить защиту от II УР
#define R0MD34LP1	 BUFFER[2]	//( - , Baz2) Кнопка Квитировать
#define idR0MD34LP1	 2	//( - , Baz2) Кнопка Квитировать
#define R0AD14LDU	 BUFFER[4]	//( - , Baz2) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 3	//( - , Baz2) Имитация срабатывания верхней АС II УР
#define R0AD16LDU	 BUFFER[6]	//( - , Baz2) Имитация срабатывания верхней АС I УР
#define idR0AD16LDU	 4	//( - , Baz2) Имитация срабатывания верхней АС I УР
#define R6IS66LZZ	 BUFFER[8]	//( - , MBz2S) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 5	//( - , MBz2S) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[10]	//( - , MBz2S) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 6	//( - , MBz2S) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[12]	//( - , MBz2S) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 7	//( - , MBz2S) Исправность ВИП 4,0 (№7) ССДИ-2
#define R0VN71LZ2	 BUFFER[14]	//(vds32:05 - K01VDSR, Baz2) АС по мощности канал 1
#define idR0VN71LZ2	 8	//(vds32:05 - K01VDSR, Baz2) АС по мощности канал 1
#define R0VN75LZ2	 BUFFER[16]	//(vds32:05 - K02VDSR, Baz2) АС по периоду разгона канал 1
#define idR0VN75LZ2	 9	//(vds32:05 - K02VDSR, Baz2) АС по периоду разгона канал 1
#define R0VN72LZ2	 BUFFER[18]	//(vds32:06 - K01VDSR, Baz2) АС по мощности канал 2
#define idR0VN72LZ2	 10	//(vds32:06 - K01VDSR, Baz2) АС по мощности канал 2
#define R0VN76LZ2	 BUFFER[20]	//(vds32:06 - K02VDSR, Baz2) АС по периоду разгона канал  2
#define idR0VN76LZ2	 11	//(vds32:06 - K02VDSR, Baz2) АС по периоду разгона канал  2
#define R0VN73LZ2	 BUFFER[22]	//(vds32:08 - K01VDSR, Baz2) АС по мощности канал 3
#define idR0VN73LZ2	 12	//(vds32:08 - K01VDSR, Baz2) АС по мощности канал 3
#define R0VN74LZ2	 BUFFER[24]	//(vds32:07 - K01VDSR, Baz2) АС по мощности канал 4
#define idR0VN74LZ2	 13	//(vds32:07 - K01VDSR, Baz2) АС по мощности канал 4
#define R0VN77LZ2	 BUFFER[26]	//(vds32:08 - K02VDSR, Baz2) АС по периоду разгона канал  3
#define idR0VN77LZ2	 14	//(vds32:08 - K02VDSR, Baz2) АС по периоду разгона канал  3
#define R0VN78LZ2	 BUFFER[28]	//(vds32:07 - K02VDSR, Baz2) АС по периоду разгона канал  4
#define idR0VN78LZ2	 15	//(vds32:07 - K02VDSR, Baz2) АС по периоду разгона канал  4
#define R0AD04LZ2	 BUFFER[30]	//(vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
#define idR0AD04LZ2	 16	//(vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
#define R0EE01LZ2	 BUFFER[32]	//( - , MBz2S) Питание  АКНП1  отключить
#define idR0EE01LZ2	 17	//( - , MBz2S) Питание  АКНП1  отключить
#define R0EE02LZ2	 BUFFER[34]	//( - , MBz2S) Питание  АКНП2  отключить
#define idR0EE02LZ2	 18	//( - , MBz2S) Питание  АКНП2  отключить
#define R0EE03LZ2	 BUFFER[36]	//( - , MBz2S) Питание  АКНП3  отключить
#define idR0EE03LZ2	 19	//( - , MBz2S) Питание  АКНП3  отключить
#define R0EE04LZ2	 BUFFER[38]	//( - , MBz2S) Питание  АКНП4  отключить
#define idR0EE04LZ2	 20	//( - , MBz2S) Питание  АКНП4  отключить
#define R0AD14LZ2	 BUFFER[40]	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define idR0AD14LZ2	 21	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define R0AD15LZ2	 BUFFER[42]	//( - , Baz2) Имитация АЗ от 1УР (датчик1)
#define idR0AD15LZ2	 22	//( - , Baz2) Имитация АЗ от 1УР (датчик1)
#define R0AD16LZ2	 BUFFER[44]	//( - , Baz2) Имитация АЗ от 1УР (датчик2)
#define idR0AD16LZ2	 23	//( - , Baz2) Имитация АЗ от 1УР (датчик2)
#define B0VZ71LZ2	 BUFFER[46]	//( - , Baz2) Обобщенный сигнал АС по АЗ2
#define idB0VZ71LZ2	 24	//( - , Baz2) Обобщенный сигнал АС по АЗ2
#define A0VN71LZ2	 BUFFER[48]	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ1
#define idA0VN71LZ2	 25	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ1
#define B0VN71LZ2	 BUFFER[50]	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ2
#define idB0VN71LZ2	 26	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ2
#define A0VN81LZ2	 BUFFER[52]	//( - , Baz2) АЗ по АС периода разгона АЗ1
#define idA0VN81LZ2	 27	//( - , Baz2) АЗ по АС периода разгона АЗ1
#define B0VN81LZ2	 BUFFER[54]	//( - , Baz2) АЗ по АС периода разгона АЗ2
#define idB0VN81LZ2	 28	//( - , Baz2) АЗ по АС периода разгона АЗ2
#define R0VZ05UZ2	 BUFFER[56]	//( - , Baz2) Индикатор причины сброса
#define idR0VZ05UZ2	 29	//( - , Baz2) Индикатор причины сброса
#define R0VN11RZ2	 BUFFER[61]	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ1
#define idR0VN11RZ2	 30	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ1
#define R0VP73LZ2	 BUFFER[66]	//( - , Baz2, SBz2DU) ПС давления для РУ
#define idR0VP73LZ2	 31	//( - , Baz2, SBz2DU) ПС давления для РУ
#define B0CT01IZ2	 BUFFER[68]	//( - , Baz2, SBz2DU) Температура АЗ2-1
#define idB0CT01IZ2	 32	//( - , Baz2, SBz2DU) Температура АЗ2-1
#define B0VT61LZ2	 BUFFER[73]	//( - , Baz2) ПС по температуре в АЗ2
#define idB0VT61LZ2	 33	//( - , Baz2) ПС по температуре в АЗ2
#define B0VT71LZ2	 BUFFER[75]	//( - , Baz2, SBz2DU) АС по температуре в АЗ2
#define idB0VT71LZ2	 34	//( - , Baz2, SBz2DU) АС по температуре в АЗ2
#define A1VN71LS1	 BUFFER[77]	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
#define idA1VN71LS1	 35	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
#define A1VN71LS2	 BUFFER[79]	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
#define idA1VN71LS2	 36	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
#define A1VN71LS3	 BUFFER[81]	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
#define idA1VN71LS3	 37	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
#define A1VN71LS4	 BUFFER[83]	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
#define idA1VN71LS4	 38	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
#define A1VN71LZ2	 BUFFER[85]	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
#define idA1VN71LZ2	 39	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
#define A3VZ15LZ2	 BUFFER[87]	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
#define idA3VZ15LZ2	 40	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
#define A3VZ13LZ2	 BUFFER[89]	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
#define idA3VZ13LZ2	 41	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
#define R0VW13LDU	 BUFFER[91]	//( - , Baz2, SBz2DU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 42	//( - , Baz2, SBz2DU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	 BUFFER[93]	//( - , Baz2, SBz2DU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 43	//( - , Baz2, SBz2DU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R7II73LZ2	 BUFFER[95]	//(vds32:08 - K07VDSR, Baz2) Сработала АС II УР РАД
#define idR7II73LZ2	 44	//(vds32:08 - K07VDSR, Baz2) Сработала АС II УР РАД
#define R7II71LZ2	 BUFFER[97]	//(vds32:08 - K05VDSR, Baz2) Сработала АС IУР РАД (датчик 1)
#define idR7II71LZ2	 45	//(vds32:08 - K05VDSR, Baz2) Сработала АС IУР РАД (датчик 1)
#define R7II72LZ2	 BUFFER[99]	//(vds32:08 - K06VDSR, Baz2) Сработала АС IУР РАД (датчик 2)
#define idR7II72LZ2	 46	//(vds32:08 - K06VDSR, Baz2) Сработала АС IУР РАД (датчик 2)
#define R0DEB4LZ2	 BUFFER[101]	//(sbk:20 - S13SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 6
#define idR0DEB4LZ2	 47	//(sbk:20 - S13SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 6
#define R0DE3CLZ2	 BUFFER[103]	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 5
#define idR0DE3CLZ2	 48	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 5
#define R0DE3DLZ2	 BUFFER[105]	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 6
#define idR0DE3DLZ2	 49	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 6
#define TestDiagnBaz2	 BUFFER[107]	//( - , Baz2) Неисправность от
#define idTestDiagnBaz2	 50	//( - , Baz2) Неисправность от
#define R0MW11IP1	 BUFFER[109]	//( - , Baz2) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 51	//( - , Baz2) Переключатель ВЫСТРЕЛ
#define PS9	 BUFFER[112]	//( - , - ) АС 1 ур (д2)
#define idPS9	 52	//( - , - ) АС 1 ур (д2)
#define PS1	 BUFFER[114]	//( - , - ) давление АЗ1
#define idPS1	 53	//( - , - ) давление АЗ1
#define PS2	 BUFFER[116]	//( - , - ) АЗ от ВУ ИС1
#define idPS2	 54	//( - , - ) АЗ от ВУ ИС1
#define PS3	 BUFFER[118]	//( - , - ) АЗ от НУП ИС1
#define idPS3	 55	//( - , - ) АЗ от НУП ИС1
#define PS4	 BUFFER[120]	//( - , - ) АЗ темп АЗ1
#define idPS4	 56	//( - , - ) АЗ темп АЗ1
#define PS5	 BUFFER[122]	//( - , - ) АС по Периоду АЗ1
#define idPS5	 57	//( - , - ) АС по Периоду АЗ1
#define PS6	 BUFFER[124]	//( - , - ) АС по мощности АЗ1
#define idPS6	 58	//( - , - ) АС по мощности АЗ1
#define PS7	 BUFFER[126]	//( - , - ) Исправность акнп А32
#define idPS7	 59	//( - , - ) Исправность акнп А32
#define PS8	 BUFFER[128]	//( - , - ) Исправность акнп А31
#define idPS8	 60	//( - , - ) Исправность акнп А31
#define PS10	 BUFFER[130]	//( - , - ) АС 1 ур (д1)
#define idPS10	 61	//( - , - ) АС 1 ур (д1)
#define PS11	 BUFFER[132]	//( - , - ) АС 2 ур
#define idPS11	 62	//( - , - ) АС 2 ур
#define PS16	 BUFFER[134]	//( - , - ) АЗ от НУП ИС2
#define idPS16	 63	//( - , - ) АЗ от НУП ИС2
#define PS17	 BUFFER[136]	//( - , - ) Аз по АС любого давления АЗ2
#define idPS17	 64	//( - , - ) Аз по АС любого давления АЗ2
#define PS15	 BUFFER[138]	//( - , - ) АЗ от ВУ ИС2
#define idPS15	 65	//( - , - ) АЗ от ВУ ИС2
#define PS14	 BUFFER[140]	//( - , - ) АС по температуре АЗ2
#define idPS14	 66	//( - , - ) АС по температуре АЗ2
#define PS12	 BUFFER[142]	//( - , - ) АС по мощности АЗ2
#define idPS12	 67	//( - , - ) АС по мощности АЗ2
#define PS13	 BUFFER[144]	//( - , - ) АС по периоду АЗ2
#define idPS13	 68	//( - , - ) АС по периоду АЗ2
#define R0VZ05U	 BUFFER[146]	//( - , - ) причины сброса
#define idR0VZ05U	 69	//( - , - ) причины сброса
#define R0MW12IP2	 BUFFER[151]	//( - , Baz2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define idR0MW12IP2	 70	//( - , Baz2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define A2IS12LDU	 BUFFER[154]	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	 71	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define B2IS12LDU	 BUFFER[156]	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	 72	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define R0EE02LDU	 BUFFER[158]	//( - , Baz2) Питание  АКНП  отключить
#define idR0EE02LDU	 73	//( - , Baz2) Питание  АКНП  отключить
#define R0DE04LZ2	 BUFFER[160]	//(vas84:04 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 4 месте
#define idR0DE04LZ2	 74	//(vas84:04 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 4 месте
#define R0DE05LZ2	 BUFFER[163]	//(vds32:05 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 5 месте
#define idR0DE05LZ2	 75	//(vds32:05 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 5 месте
#define R0DE06LZ2	 BUFFER[166]	//(vds32:06 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 6 месте
#define idR0DE06LZ2	 76	//(vds32:06 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 6 месте
#define R0DE07LZ2	 BUFFER[169]	//(vds32:07 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 7 месте
#define idR0DE07LZ2	 77	//(vds32:07 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 7 месте
#define R0DE0ALZ2	 BUFFER[172]	//(fds16:0a - Diagn, DiagnBaz2) диагностика модуля Баз2 на 10 месте
#define idR0DE0ALZ2	 78	//(fds16:0a - Diagn, DiagnBaz2) диагностика модуля Баз2 на 10 месте
#define R0DE31LZ2	 BUFFER[175]	//(sbk:20 - S01SBK, DiagnBaz2) диагностика шкафа Баз2 сеть 1
#define idR0DE31LZ2	 79	//(sbk:20 - S01SBK, DiagnBaz2) диагностика шкафа Баз2 сеть 1
#define R0DE08LZ2	 BUFFER[177]	//(vds32:08 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 8 месте
#define idR0DE08LZ2	 80	//(vds32:08 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 8 месте
#define TTLBaz2	 BUFFER[180]	//( - , Baz2) ttl
#define idTTLBaz2	 81	//( - , Baz2) ttl
#define R0DE32LZ2	 BUFFER[183]	//(sbk:20 - S02SBK, DiagnBaz2) диагностика шкафа Баз2 сеть 2
#define idR0DE32LZ2	 82	//(sbk:20 - S02SBK, DiagnBaz2) диагностика шкафа Баз2 сеть 2
#define R0DE33LZ2	 BUFFER[185]	//(sbk:20 - S03SBK, DiagnBaz2) диагностика шкафа Баз2 двери
#define idR0DE33LZ2	 83	//(sbk:20 - S03SBK, DiagnBaz2) диагностика шкафа Баз2 двери
#define R0DE34LZ2	 BUFFER[187]	//(sbk:20 - S04SBK, DiagnBaz2) диагностика шкафа Баз2 температура меньше 43
#define idR0DE34LZ2	 84	//(sbk:20 - S04SBK, DiagnBaz2) диагностика шкафа Баз2 температура меньше 43
#define R0DE35LZ2	 BUFFER[189]	//(sbk:20 - S05SBK, DiagnBaz2) диагностика шкафа Баз2 температура больше 53
#define idR0DE35LZ2	 85	//(sbk:20 - S05SBK, DiagnBaz2) диагностика шкафа Баз2 температура больше 53
#define R0DE38LZ2	 BUFFER[191]	//(sbk:20 - S08SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3 место 3
#define idR0DE38LZ2	 86	//(sbk:20 - S08SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3 место 3
#define R0DE37LZ2	 BUFFER[193]	//(sbk:20 - S07SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3.1 место 2
#define idR0DE37LZ2	 87	//(sbk:20 - S07SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3.1 место 2
#define R0DE39LZ2	 BUFFER[195]	//(sbk:20 - S09SBK, DiagnBaz2) диагностика шкафа Баз2 МП24-2 место 4
#define idR0DE39LZ2	 88	//(sbk:20 - S09SBK, DiagnBaz2) диагностика шкафа Баз2 МП24-2 место 4
#define R0DE36LZ2	 BUFFER[197]	//(sbk:20 - S06SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3.1 место 1
#define idR0DE36LZ2	 89	//(sbk:20 - S06SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3.1 место 1
#define R0DEB1LZ2	 BUFFER[199]	//(sbk:20 - S10SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 5
#define idR0DEB1LZ2	 90	//(sbk:20 - S10SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 5
#define R0DEB2LZ2	 BUFFER[201]	//(sbk:20 - S11SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 5
#define idR0DEB2LZ2	 91	//(sbk:20 - S11SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 5
#define R0DEB3LZ2	 BUFFER[203]	//(sbk:20 - S12SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 6
#define idR0DEB3LZ2	 92	//(sbk:20 - S12SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 6
#define A0VP81LZZ	 BUFFER[205]	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define idA0VP81LZZ	 93	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define R0ET02LZ2	 BUFFER[207]	//( - , Baz2) Признак наличия неисправности по температуре АЗ2
#define idR0ET02LZ2	 94	//( - , Baz2) Признак наличия неисправности по температуре АЗ2
#define B0EP02IZ2	 BUFFER[209]	//( - , Baz2) Индикатор -Давление  АЗ2 ниже АС
#define idB0EP02IZ2	 95	//( - , Baz2) Индикатор -Давление  АЗ2 ниже АС
#define A0EP02IZ2	 BUFFER[212]	//( - , Baz2) Индикатор -Давление  АЗ1 ниже АС
#define idA0EP02IZ2	 96	//( - , Baz2) Индикатор -Давление  АЗ1 ниже АС
#define A0VP71LZ2	 BUFFER[215]	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ2	 97	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
#define B0VP71LZ2	 BUFFER[217]	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ2	 98	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
#define R0VN02RS1	 BUFFER[219]	//( - , MBz2A1) Уровень мощности канал 1
#define idR0VN02RS1	 99	//( - , MBz2A1) Уровень мощности канал 1
#define R0VN02RS2	 BUFFER[224]	//( - , MBz2A2) Уровень мощности канал 2
#define idR0VN02RS2	 100	//( - , MBz2A2) Уровень мощности канал 2
#define R0VN02RS3	 BUFFER[229]	//( - , MBz2A3) Уровень мощности канал 3
#define idR0VN02RS3	 101	//( - , MBz2A3) Уровень мощности канал 3
#define R0VN02RS4	 BUFFER[234]	//( - , MBz2A4) Уровень мощности канал 4
#define idR0VN02RS4	 102	//( - , MBz2A4) Уровень мощности канал 4
#define R0VN01RS1	 BUFFER[239]	//( - , MBz2A1) Период разгона канал 1
#define idR0VN01RS1	 103	//( - , MBz2A1) Период разгона канал 1
#define R0VN01RS2	 BUFFER[244]	//( - , MBz2A2) Период разгона канал 2
#define idR0VN01RS2	 104	//( - , MBz2A2) Период разгона канал 2
#define R0VN01RS3	 BUFFER[249]	//( - , MBz2A3) Период разгона канал 3
#define idR0VN01RS3	 105	//( - , MBz2A3) Период разгона канал 3
#define R0VN01RS4	 BUFFER[254]	//( - , MBz2A4) Период разгона канал 4
#define idR0VN01RS4	 106	//( - , MBz2A4) Период разгона канал 4
#define R0VN61LS1	 BUFFER[259]	//( - , MBz2A1) ПС по мощности канал 1
#define idR0VN61LS1	 107	//( - , MBz2A1) ПС по мощности канал 1
#define R0VN61LS2	 BUFFER[261]	//( - , MBz2A2) ПС по мощности канал 2
#define idR0VN61LS2	 108	//( - , MBz2A2) ПС по мощности канал 2
#define R0VN61LS3	 BUFFER[263]	//( - , MBz2A3) ПС по мощности канал 3
#define idR0VN61LS3	 109	//( - , MBz2A3) ПС по мощности канал 3
#define R0VN61LS4	 BUFFER[265]	//( - , MBz2A4) ПС по мощности канал 4
#define idR0VN61LS4	 110	//( - , MBz2A4) ПС по мощности канал 4
#define R0VN65LS1	 BUFFER[267]	//( - , MBz2A1) ПС по периоду разгона канал 1
#define idR0VN65LS1	 111	//( - , MBz2A1) ПС по периоду разгона канал 1
#define R0VN65LS2	 BUFFER[269]	//( - , MBz2A2) ПС по периоду разгона  канал 2
#define idR0VN65LS2	 112	//( - , MBz2A2) ПС по периоду разгона  канал 2
#define R0VN65LS3	 BUFFER[271]	//( - , MBz2A3) ПС по периоду разгона канал 3
#define idR0VN65LS3	 113	//( - , MBz2A3) ПС по периоду разгона канал 3
#define R0VN65LS4	 BUFFER[273]	//( - , MBz2A4) ПС по периоду разгона канал 4
#define idR0VN65LS4	 114	//( - , MBz2A4) ПС по периоду разгона канал 4
#define R0VN01RZ2	 BUFFER[275]	//( - , Baz2) Уровень мощности по каналу 1
#define idR0VN01RZ2	 115	//( - , Baz2) Уровень мощности по каналу 1
#define A0IT02IZ2	 BUFFER[280]	//(vas84:04 - K01VASR, - ) Температура АЗ1-2
#define idA0IT02IZ2	 116	//(vas84:04 - K01VASR, - ) Температура АЗ1-2
#define A0CT01IZ2	 BUFFER[283]	//( - , Baz2, SBz2DU) Температура АЗ1-1
#define idA0CT01IZ2	 117	//( - , Baz2, SBz2DU) Температура АЗ1-1
#define A0VT61LZ2	 BUFFER[288]	//( - , Baz2) ПС по температуре в АЗ1
#define idA0VT61LZ2	 118	//( - , Baz2) ПС по температуре в АЗ1
#define A0VT71LZ2	 BUFFER[290]	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
#define idA0VT71LZ2	 119	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
#define A1VP41LZ2	 BUFFER[292]	//( - , Baz2) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ2	 120	//( - , Baz2) Давление СБРОС ББ1 ниже АС
#define B1VP41LZ2	 BUFFER[294]	//( - , Baz2) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ2	 121	//( - , Baz2) Давление СБРОС ББ2 ниже АС
#define B1VP81LZZ	 BUFFER[296]	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	 122	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define A1VP81LZZ	 BUFFER[298]	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	 123	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define A2VP41LZ2	 BUFFER[300]	//( - , Baz2) Давление СБРОС РБ1 ниже АС
#define idA2VP41LZ2	 124	//( - , Baz2) Давление СБРОС РБ1 ниже АС
#define A2CP01RZ2	 BUFFER[302]	//( - , Baz2) Текущее давление СБРОС РБ1
#define idA2CP01RZ2	 125	//( - , Baz2) Текущее давление СБРОС РБ1
#define A2VP51LZ2	 BUFFER[307]	//( - , Baz2) Давление СБРОС РБ1 ниже ПС
#define idA2VP51LZ2	 126	//( - , Baz2) Давление СБРОС РБ1 ниже ПС
#define B2VP41LZ2	 BUFFER[309]	//( - , Baz2) Давление СБРОС РБ2 ниже АС
#define idB2VP41LZ2	 127	//( - , Baz2) Давление СБРОС РБ2 ниже АС
#define B2CP01RZ2	 BUFFER[311]	//( - , Baz2) Текущее давление СБРОС РБ2
#define idB2CP01RZ2	 128	//( - , Baz2) Текущее давление СБРОС РБ2
#define B2VP51LZ2	 BUFFER[316]	//( - , Baz2) Давление СБРОС РБ2 ниже ПС
#define idB2VP51LZ2	 129	//( - , Baz2) Давление СБРОС РБ2 ниже ПС
#define B2VP81LZ2	 BUFFER[318]	//( - , Baz2) Давление СБРОС РБ2 в норме
#define idB2VP81LZ2	 130	//( - , Baz2) Давление СБРОС РБ2 в норме
#define A2VP81LZ2	 BUFFER[320]	//( - , Baz2) Давление СБРОС РБ1 в норме
#define idA2VP81LZ2	 131	//( - , Baz2) Давление СБРОС РБ1 в норме
#define A2IP01IZ2	 BUFFER[322]	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ2	 132	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define B2IP01IZ2	 BUFFER[325]	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ2	 133	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define R0ET01LZ2	 BUFFER[328]	//( - , Baz2) Признак наличия неисправности по температуре  АЗ1
#define idR0ET01LZ2	 134	//( - , Baz2) Признак наличия неисправности по температуре  АЗ1
#define B0IT02IZ2	 BUFFER[330]	//(vas84:04 - K03VASR, - ) Температура АЗ2-2
#define idB0IT02IZ2	 135	//(vas84:04 - K03VASR, - ) Температура АЗ2-2
#define A0VP41LZ2	 BUFFER[333]	//( - , Baz2) Давление АЗ1 ниже АС
#define idA0VP41LZ2	 136	//( - , Baz2) Давление АЗ1 ниже АС
#define B0VP41LZ2	 BUFFER[335]	//( - , Baz2) Давление АЗ2 ниже АС
#define idB0VP41LZ2	 137	//( - , Baz2) Давление АЗ2 ниже АС
#define B0VP81LZZ	 BUFFER[337]	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	 138	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define B3VZ11LZ2	 BUFFER[339]	//( - , Baz2) АЗ от НУП ИС2
#define idB3VZ11LZ2	 139	//( - , Baz2) АЗ от НУП ИС2
#define B3IS22LDU	 BUFFER[341]	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
#define idB3IS22LDU	 140	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
#define R0VN69LZ2	 BUFFER[343]	//( - , Baz2) ПС по усредненному периоду
#define idR0VN69LZ2	 141	//( - , Baz2) ПС по усредненному периоду
#define R0VN79LZ2	 BUFFER[345]	//( - , Baz2) АС по усредненному периоду
#define idR0VN79LZ2	 142	//( - , Baz2) АС по усредненному периоду
#define R0VR02RZ2	 BUFFER[347]	//( - , Baz2) Усредненная реактивность
#define idR0VR02RZ2	 143	//( - , Baz2) Усредненная реактивность
#define R0VZ71LZ2	 BUFFER[352]	//(fds16:0a - K05FDSR, Baz2) Обобщенный сигнал АЗ 2 канала
#define idR0VZ71LZ2	 144	//(fds16:0a - K05FDSR, Baz2) Обобщенный сигнал АЗ 2 канала
#define R0VN70LZ2	 BUFFER[354]	//( - , Baz2) АЗ по АС мощности РУ
#define idR0VN70LZ2	 145	//( - , Baz2) АЗ по АС мощности РУ
#define R0VN80LZ2	 BUFFER[356]	//( - , Baz2) АЗ по АС периода разгона РУ
#define idR0VN80LZ2	 146	//( - , Baz2) АЗ по АС периода разгона РУ
#define A1EE01LS1	 BUFFER[358]	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define idA1EE01LS1	 147	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define A1EE01LS4	 BUFFER[360]	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define idA1EE01LS4	 148	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define A1EE01LS3	 BUFFER[362]	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define idA1EE01LS3	 149	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define A0EE01LZ2	 BUFFER[364]	//( - , Baz2, SBz2DU) Исправность АКНП1
#define idA0EE01LZ2	 150	//( - , Baz2, SBz2DU) Исправность АКНП1
#define A0EE04LZ2	 BUFFER[366]	//( - , Baz2, SBz2DU) Исправность АКНП4
#define idA0EE04LZ2	 151	//( - , Baz2, SBz2DU) Исправность АКНП4
#define A0EE02LZ2	 BUFFER[368]	//( - , Baz2, SBz2DU) Исправность АКНП2
#define idA0EE02LZ2	 152	//( - , Baz2, SBz2DU) Исправность АКНП2
#define A0EE03LZ2	 BUFFER[370]	//( - , Baz2, SBz2DU) Исправность АКНП3
#define idA0EE03LZ2	 153	//( - , Baz2, SBz2DU) Исправность АКНП3
#define A1EE01LS2	 BUFFER[372]	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define idA1EE01LS2	 154	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define A0EE05LZ2	 BUFFER[374]	//( - , Baz2) Исправность сети АКНП1
#define idA0EE05LZ2	 155	//( - , Baz2) Исправность сети АКНП1
#define A0EE06LZ2	 BUFFER[376]	//( - , Baz2) Исправность сети АКНП2
#define idA0EE06LZ2	 156	//( - , Baz2) Исправность сети АКНП2
#define A0EE07LZ2	 BUFFER[378]	//( - , Baz2) Исправность сети АКНП3
#define idA0EE07LZ2	 157	//( - , Baz2) Исправность сети АКНП3
#define A0EE08LZ2	 BUFFER[380]	//( - , Baz2) Исправность сети АКНП4
#define idA0EE08LZ2	 158	//( - , Baz2) Исправность сети АКНП4
#define A0VZ71LZ2	 BUFFER[382]	//( - , Baz2) Обобщенный сигнал АС по АЗ1
#define idA0VZ71LZ2	 159	//( - , Baz2) Обобщенный сигнал АС по АЗ1
#define A0EE00LZ2	 BUFFER[384]	//( - , Baz2) Исправность АКНП АЗ1
#define idA0EE00LZ2	 160	//( - , Baz2) Исправность АКНП АЗ1
#define B0EE00LZ2	 BUFFER[386]	//( - , Baz2) Исправность АКНП АЗ2
#define idB0EE00LZ2	 161	//( - , Baz2) Исправность АКНП АЗ2
#define R0VN02RZ2	 BUFFER[388]	//( - , Baz2) Уровень мощности по каналу 2
#define idR0VN02RZ2	 162	//( - , Baz2) Уровень мощности по каналу 2
#define R0VN03RZ2	 BUFFER[393]	//( - , Baz2) Уровень мощности по каналу 3
#define idR0VN03RZ2	 163	//( - , Baz2) Уровень мощности по каналу 3
#define R0VN04RZ2	 BUFFER[398]	//( - , Baz2) Уровень мощности по каналу 4
#define idR0VN04RZ2	 164	//( - , Baz2) Уровень мощности по каналу 4
#define R0VN05RZ2	 BUFFER[403]	//( - , Baz2) Период разгона по каналу 1
#define idR0VN05RZ2	 165	//( - , Baz2) Период разгона по каналу 1
#define R0VN06RZ2	 BUFFER[408]	//( - , Baz2) Период разгона по каналу 2
#define idR0VN06RZ2	 166	//( - , Baz2) Период разгона по каналу 2
#define R0VN07RZ2	 BUFFER[413]	//( - , Baz2) Период разгона по каналу 3
#define idR0VN07RZ2	 167	//( - , Baz2) Период разгона по каналу 3
#define R0VN08RZ2	 BUFFER[418]	//( - , Baz2) Период разгона по каналу 4
#define idR0VN08RZ2	 168	//( - , Baz2) Период разгона по каналу 4
#define R0VN61LZ2	 BUFFER[423]	//( - , Baz2) ПС по мощности канал 1
#define idR0VN61LZ2	 169	//( - , Baz2) ПС по мощности канал 1
#define R0VN62LZ2	 BUFFER[425]	//( - , Baz2) ПС по мощности канал 2
#define idR0VN62LZ2	 170	//( - , Baz2) ПС по мощности канал 2
#define R0VN63LZ2	 BUFFER[427]	//( - , Baz2) ПС по мощности канал 3
#define idR0VN63LZ2	 171	//( - , Baz2) ПС по мощности канал 3
#define R0VN64LZ2	 BUFFER[429]	//( - , Baz2) ПС по мощности канал 4
#define idR0VN64LZ2	 172	//( - , Baz2) ПС по мощности канал 4
#define R0VN65LZ2	 BUFFER[431]	//( - , Baz2) ПС по периоду разгона канал 1
#define idR0VN65LZ2	 173	//( - , Baz2) ПС по периоду разгона канал 1
#define R0VN66LZ2	 BUFFER[433]	//( - , Baz2) ПС по периоду разгона канал 2
#define idR0VN66LZ2	 174	//( - , Baz2) ПС по периоду разгона канал 2
#define R0VN67LZ2	 BUFFER[435]	//( - , Baz2) ПС по периоду разгона канал 3
#define idR0VN67LZ2	 175	//( - , Baz2) ПС по периоду разгона канал 3
#define R0VN68LZ2	 BUFFER[437]	//( - , Baz2) ПС по периоду разгона канал 4
#define idR0VN68LZ2	 176	//( - , Baz2) ПС по периоду разгона канал 4
#define R0VN09RZ2	 BUFFER[439]	//( - , Baz2, SBz2DU) Усредненный период разгона
#define idR0VN09RZ2	 177	//( - , Baz2, SBz2DU) Усредненный период разгона
#define A3IS11LDU	 BUFFER[444]	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define idA3IS11LDU	 178	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define A3IS22LDU	 BUFFER[446]	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define idA3IS22LDU	 179	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define R0AD03LZ2	 BUFFER[448]	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define idR0AD03LZ2	 180	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define B3IS11LDU	 BUFFER[450]	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define idB3IS11LDU	 181	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define A3VZ31LZ2	 BUFFER[452]	//( - , Baz2) АЗ от ВУ ИС1
#define idA3VZ31LZ2	 182	//( - , Baz2) АЗ от ВУ ИС1
#define B3VZ31LZ2	 BUFFER[454]	//( - , Baz2) АЗ от ВУ ИС2
#define idB3VZ31LZ2	 183	//( - , Baz2) АЗ от ВУ ИС2
#define R0AD05LZ2	 BUFFER[456]	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define idR0AD05LZ2	 184	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define A3VZ11LZ2	 BUFFER[458]	//( - , Baz2) АЗ от НУП ИС1
#define idA3VZ11LZ2	 185	//( - , Baz2) АЗ от НУП ИС1
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
#define fEM_A1UL11RZZ	 BUFFER[555]	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС
#define idfEM_A1UL11RZZ	 205	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС
#define fEM_R7UI73RZZ	 BUFFER[560]	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define idfEM_R7UI73RZZ	 206	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define bFirstEnterFlag	 BUFFER[565]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 207	//(bFirstEnterFlag) 
#define internal1_m244_tx	 BUFFER[567]	//(internal1_m244_tx) tx - время накопленное сек
#define idinternal1_m244_tx	 208	//(internal1_m244_tx) tx - время накопленное сек
#define internal1_m244_y0	 BUFFER[572]	//(internal1_m244_y0) y0
#define idinternal1_m244_y0	 209	//(internal1_m244_y0) y0
#define internal1_m328_tx	 BUFFER[573]	//(internal1_m328_tx) tx - время накопленное сек
#define idinternal1_m328_tx	 210	//(internal1_m328_tx) tx - время накопленное сек
#define internal1_m328_y0	 BUFFER[578]	//(internal1_m328_y0) y0
#define idinternal1_m328_y0	 211	//(internal1_m328_y0) y0
#define internal1_m212_tx	 BUFFER[579]	//(internal1_m212_tx) tx - время накопленное сек
#define idinternal1_m212_tx	 212	//(internal1_m212_tx) tx - время накопленное сек
#define internal1_m212_y0	 BUFFER[584]	//(internal1_m212_y0) y0
#define idinternal1_m212_y0	 213	//(internal1_m212_y0) y0
#define internal1_m210_tx	 BUFFER[585]	//(internal1_m210_tx) tx - время накопленное сек
#define idinternal1_m210_tx	 214	//(internal1_m210_tx) tx - время накопленное сек
#define internal1_m210_y0	 BUFFER[590]	//(internal1_m210_y0) y0
#define idinternal1_m210_y0	 215	//(internal1_m210_y0) y0
#define internal1_m252_tx	 BUFFER[591]	//(internal1_m252_tx) tx - время накопленное сек
#define idinternal1_m252_tx	 216	//(internal1_m252_tx) tx - время накопленное сек
#define internal1_m252_y0	 BUFFER[596]	//(internal1_m252_y0) y0
#define idinternal1_m252_y0	 217	//(internal1_m252_y0) y0
#define internal1_m209_tx	 BUFFER[597]	//(internal1_m209_tx) tx - время накопленное сек
#define idinternal1_m209_tx	 218	//(internal1_m209_tx) tx - время накопленное сек
#define internal1_m209_y0	 BUFFER[602]	//(internal1_m209_y0) y0
#define idinternal1_m209_y0	 219	//(internal1_m209_y0) y0
#define internal1_m207_tx	 BUFFER[603]	//(internal1_m207_tx) tx - время накопленное сек
#define idinternal1_m207_tx	 220	//(internal1_m207_tx) tx - время накопленное сек
#define internal1_m207_y0	 BUFFER[608]	//(internal1_m207_y0) y0
#define idinternal1_m207_y0	 221	//(internal1_m207_y0) y0
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
#define internal1_m314_q0	 BUFFER[636]	//(internal1_m314_q0) q0 - внутренний параметр
#define idinternal1_m314_q0	 229	//(internal1_m314_q0) q0 - внутренний параметр
#define internal1_m125_y0	 BUFFER[641]	//(internal1_m125_y0) state
#define idinternal1_m125_y0	 230	//(internal1_m125_y0) state
#define internal1_m119_y0	 BUFFER[643]	//(internal1_m119_y0) state
#define idinternal1_m119_y0	 231	//(internal1_m119_y0) state
#define internal1_m105_y1	 BUFFER[645]	//(internal1_m105_y1) y1 - внутренний параметр
#define idinternal1_m105_y1	 232	//(internal1_m105_y1) y1 - внутренний параметр
#define internal1_m114_y1	 BUFFER[647]	//(internal1_m114_y1) y1 - внутренний параметр
#define idinternal1_m114_y1	 233	//(internal1_m114_y1) y1 - внутренний параметр
#define internal1_m93_y1	 BUFFER[649]	//(internal1_m93_y1) y1 - внутренний параметр
#define idinternal1_m93_y1	 234	//(internal1_m93_y1) y1 - внутренний параметр
#define internal1_m103_y1	 BUFFER[651]	//(internal1_m103_y1) y1 - внутренний параметр
#define idinternal1_m103_y1	 235	//(internal1_m103_y1) y1 - внутренний параметр
#define internal1_m153_y1	 BUFFER[653]	//(internal1_m153_y1) y1 - внутренний параметр
#define idinternal1_m153_y1	 236	//(internal1_m153_y1) y1 - внутренний параметр
#define internal1_m161_y1	 BUFFER[655]	//(internal1_m161_y1) y1 - внутренний параметр
#define idinternal1_m161_y1	 237	//(internal1_m161_y1) y1 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &R0AD21LDU},	//( - , SBz2DU) Подключить защиту от II УР
	{ 2	,1	,1	, &R0MD34LP1},	//( - , Baz2) Кнопка Квитировать
	{ 3	,1	,1	, &R0AD14LDU},	//( - , Baz2) Имитация срабатывания верхней АС II УР
	{ 4	,1	,1	, &R0AD16LDU},	//( - , Baz2) Имитация срабатывания верхней АС I УР
	{ 5	,1	,1	, &R6IS66LZZ},	//( - , MBz2S) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 6	,1	,1	, &R6IS67LZZ},	//( - , MBz2S) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 7	,1	,1	, &R6IS68LZZ},	//( - , MBz2S) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 8	,1	,1	, &R0VN71LZ2},	//(vds32:05 - K01VDSR, Baz2) АС по мощности канал 1
	{ 9	,1	,1	, &R0VN75LZ2},	//(vds32:05 - K02VDSR, Baz2) АС по периоду разгона канал 1
	{ 10	,1	,1	, &R0VN72LZ2},	//(vds32:06 - K01VDSR, Baz2) АС по мощности канал 2
	{ 11	,1	,1	, &R0VN76LZ2},	//(vds32:06 - K02VDSR, Baz2) АС по периоду разгона канал  2
	{ 12	,1	,1	, &R0VN73LZ2},	//(vds32:08 - K01VDSR, Baz2) АС по мощности канал 3
	{ 13	,1	,1	, &R0VN74LZ2},	//(vds32:07 - K01VDSR, Baz2) АС по мощности канал 4
	{ 14	,1	,1	, &R0VN77LZ2},	//(vds32:08 - K02VDSR, Baz2) АС по периоду разгона канал  3
	{ 15	,1	,1	, &R0VN78LZ2},	//(vds32:07 - K02VDSR, Baz2) АС по периоду разгона канал  4
	{ 16	,1	,1	, &R0AD04LZ2},	//(vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
	{ 17	,1	,1	, &R0EE01LZ2},	//( - , MBz2S) Питание  АКНП1  отключить
	{ 18	,1	,1	, &R0EE02LZ2},	//( - , MBz2S) Питание  АКНП2  отключить
	{ 19	,1	,1	, &R0EE03LZ2},	//( - , MBz2S) Питание  АКНП3  отключить
	{ 20	,1	,1	, &R0EE04LZ2},	//( - , MBz2S) Питание  АКНП4  отключить
	{ 21	,1	,1	, &R0AD14LZ2},	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
	{ 22	,1	,1	, &R0AD15LZ2},	//( - , Baz2) Имитация АЗ от 1УР (датчик1)
	{ 23	,1	,1	, &R0AD16LZ2},	//( - , Baz2) Имитация АЗ от 1УР (датчик2)
	{ 24	,1	,1	, &B0VZ71LZ2},	//( - , Baz2) Обобщенный сигнал АС по АЗ2
	{ 25	,1	,1	, &A0VN71LZ2},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ1
	{ 26	,1	,1	, &B0VN71LZ2},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ2
	{ 27	,1	,1	, &A0VN81LZ2},	//( - , Baz2) АЗ по АС периода разгона АЗ1
	{ 28	,1	,1	, &B0VN81LZ2},	//( - , Baz2) АЗ по АС периода разгона АЗ2
	{ 29	,5	,1	, &R0VZ05UZ2},	//( - , Baz2) Индикатор причины сброса
	{ 30	,8	,1	, &R0VN11RZ2},	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ1
	{ 31	,1	,1	, &R0VP73LZ2},	//( - , Baz2, SBz2DU) ПС давления для РУ
	{ 32	,8	,1	, &B0CT01IZ2},	//( - , Baz2, SBz2DU) Температура АЗ2-1
	{ 33	,1	,1	, &B0VT61LZ2},	//( - , Baz2) ПС по температуре в АЗ2
	{ 34	,1	,1	, &B0VT71LZ2},	//( - , Baz2, SBz2DU) АС по температуре в АЗ2
	{ 35	,1	,1	, &A1VN71LS1},	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
	{ 36	,1	,1	, &A1VN71LS2},	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
	{ 37	,1	,1	, &A1VN71LS3},	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
	{ 38	,1	,1	, &A1VN71LS4},	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
	{ 39	,1	,1	, &A1VN71LZ2},	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
	{ 40	,1	,1	, &A3VZ15LZ2},	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
	{ 41	,1	,1	, &A3VZ13LZ2},	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
	{ 42	,1	,1	, &R0VW13LDU},	//( - , Baz2, SBz2DU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 43	,1	,1	, &R0VW23LDU},	//( - , Baz2, SBz2DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 44	,1	,1	, &R7II73LZ2},	//(vds32:08 - K07VDSR, Baz2) Сработала АС II УР РАД
	{ 45	,1	,1	, &R7II71LZ2},	//(vds32:08 - K05VDSR, Baz2) Сработала АС IУР РАД (датчик 1)
	{ 46	,1	,1	, &R7II72LZ2},	//(vds32:08 - K06VDSR, Baz2) Сработала АС IУР РАД (датчик 2)
	{ 47	,1	,1	, &R0DEB4LZ2},	//(sbk:20 - S13SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 6
	{ 48	,1	,1	, &R0DE3CLZ2},	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 5
	{ 49	,1	,1	, &R0DE3DLZ2},	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 6
	{ 50	,1	,1	, &TestDiagnBaz2},	//( - , Baz2) Неисправность от
	{ 51	,3	,1	, &R0MW11IP1},	//( - , Baz2) Переключатель ВЫСТРЕЛ
	{ 52	,1	,1	, &PS9},	//( - , - ) АС 1 ур (д2)
	{ 53	,1	,1	, &PS1},	//( - , - ) давление АЗ1
	{ 54	,1	,1	, &PS2},	//( - , - ) АЗ от ВУ ИС1
	{ 55	,1	,1	, &PS3},	//( - , - ) АЗ от НУП ИС1
	{ 56	,1	,1	, &PS4},	//( - , - ) АЗ темп АЗ1
	{ 57	,1	,1	, &PS5},	//( - , - ) АС по Периоду АЗ1
	{ 58	,1	,1	, &PS6},	//( - , - ) АС по мощности АЗ1
	{ 59	,1	,1	, &PS7},	//( - , - ) Исправность акнп А32
	{ 60	,1	,1	, &PS8},	//( - , - ) Исправность акнп А31
	{ 61	,1	,1	, &PS10},	//( - , - ) АС 1 ур (д1)
	{ 62	,1	,1	, &PS11},	//( - , - ) АС 2 ур
	{ 63	,1	,1	, &PS16},	//( - , - ) АЗ от НУП ИС2
	{ 64	,1	,1	, &PS17},	//( - , - ) Аз по АС любого давления АЗ2
	{ 65	,1	,1	, &PS15},	//( - , - ) АЗ от ВУ ИС2
	{ 66	,1	,1	, &PS14},	//( - , - ) АС по температуре АЗ2
	{ 67	,1	,1	, &PS12},	//( - , - ) АС по мощности АЗ2
	{ 68	,1	,1	, &PS13},	//( - , - ) АС по периоду АЗ2
	{ 69	,5	,1	, &R0VZ05U},	//( - , - ) причины сброса
	{ 70	,3	,1	, &R0MW12IP2},	//( - , Baz2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{ 71	,1	,1	, &A2IS12LDU},	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
	{ 72	,1	,1	, &B2IS12LDU},	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
	{ 73	,1	,1	, &R0EE02LDU},	//( - , Baz2) Питание  АКНП  отключить
	{ 74	,3	,1	, &R0DE04LZ2},	//(vas84:04 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 4 месте
	{ 75	,3	,1	, &R0DE05LZ2},	//(vds32:05 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 5 месте
	{ 76	,3	,1	, &R0DE06LZ2},	//(vds32:06 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 6 месте
	{ 77	,3	,1	, &R0DE07LZ2},	//(vds32:07 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 7 месте
	{ 78	,3	,1	, &R0DE0ALZ2},	//(fds16:0a - Diagn, DiagnBaz2) диагностика модуля Баз2 на 10 месте
	{ 79	,1	,1	, &R0DE31LZ2},	//(sbk:20 - S01SBK, DiagnBaz2) диагностика шкафа Баз2 сеть 1
	{ 80	,3	,1	, &R0DE08LZ2},	//(vds32:08 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 8 месте
	{ 81	,3	,1	, &TTLBaz2},	//( - , Baz2) ttl
	{ 82	,1	,1	, &R0DE32LZ2},	//(sbk:20 - S02SBK, DiagnBaz2) диагностика шкафа Баз2 сеть 2
	{ 83	,1	,1	, &R0DE33LZ2},	//(sbk:20 - S03SBK, DiagnBaz2) диагностика шкафа Баз2 двери
	{ 84	,1	,1	, &R0DE34LZ2},	//(sbk:20 - S04SBK, DiagnBaz2) диагностика шкафа Баз2 температура меньше 43
	{ 85	,1	,1	, &R0DE35LZ2},	//(sbk:20 - S05SBK, DiagnBaz2) диагностика шкафа Баз2 температура больше 53
	{ 86	,1	,1	, &R0DE38LZ2},	//(sbk:20 - S08SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3 место 3
	{ 87	,1	,1	, &R0DE37LZ2},	//(sbk:20 - S07SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3.1 место 2
	{ 88	,1	,1	, &R0DE39LZ2},	//(sbk:20 - S09SBK, DiagnBaz2) диагностика шкафа Баз2 МП24-2 место 4
	{ 89	,1	,1	, &R0DE36LZ2},	//(sbk:20 - S06SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3.1 место 1
	{ 90	,1	,1	, &R0DEB1LZ2},	//(sbk:20 - S10SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 5
	{ 91	,1	,1	, &R0DEB2LZ2},	//(sbk:20 - S11SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 5
	{ 92	,1	,1	, &R0DEB3LZ2},	//(sbk:20 - S12SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 6
	{ 93	,1	,1	, &A0VP81LZZ},	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
	{ 94	,1	,1	, &R0ET02LZ2},	//( - , Baz2) Признак наличия неисправности по температуре АЗ2
	{ 95	,3	,1	, &B0EP02IZ2},	//( - , Baz2) Индикатор -Давление  АЗ2 ниже АС
	{ 96	,3	,1	, &A0EP02IZ2},	//( - , Baz2) Индикатор -Давление  АЗ1 ниже АС
	{ 97	,1	,1	, &A0VP71LZ2},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
	{ 98	,1	,1	, &B0VP71LZ2},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
	{ 99	,8	,1	, &R0VN02RS1},	//( - , MBz2A1) Уровень мощности канал 1
	{ 100	,8	,1	, &R0VN02RS2},	//( - , MBz2A2) Уровень мощности канал 2
	{ 101	,8	,1	, &R0VN02RS3},	//( - , MBz2A3) Уровень мощности канал 3
	{ 102	,8	,1	, &R0VN02RS4},	//( - , MBz2A4) Уровень мощности канал 4
	{ 103	,8	,1	, &R0VN01RS1},	//( - , MBz2A1) Период разгона канал 1
	{ 104	,8	,1	, &R0VN01RS2},	//( - , MBz2A2) Период разгона канал 2
	{ 105	,8	,1	, &R0VN01RS3},	//( - , MBz2A3) Период разгона канал 3
	{ 106	,8	,1	, &R0VN01RS4},	//( - , MBz2A4) Период разгона канал 4
	{ 107	,1	,1	, &R0VN61LS1},	//( - , MBz2A1) ПС по мощности канал 1
	{ 108	,1	,1	, &R0VN61LS2},	//( - , MBz2A2) ПС по мощности канал 2
	{ 109	,1	,1	, &R0VN61LS3},	//( - , MBz2A3) ПС по мощности канал 3
	{ 110	,1	,1	, &R0VN61LS4},	//( - , MBz2A4) ПС по мощности канал 4
	{ 111	,1	,1	, &R0VN65LS1},	//( - , MBz2A1) ПС по периоду разгона канал 1
	{ 112	,1	,1	, &R0VN65LS2},	//( - , MBz2A2) ПС по периоду разгона  канал 2
	{ 113	,1	,1	, &R0VN65LS3},	//( - , MBz2A3) ПС по периоду разгона канал 3
	{ 114	,1	,1	, &R0VN65LS4},	//( - , MBz2A4) ПС по периоду разгона канал 4
	{ 115	,8	,1	, &R0VN01RZ2},	//( - , Baz2) Уровень мощности по каналу 1
	{ 116	,3	,1	, &A0IT02IZ2},	//(vas84:04 - K01VASR, - ) Температура АЗ1-2
	{ 117	,8	,1	, &A0CT01IZ2},	//( - , Baz2, SBz2DU) Температура АЗ1-1
	{ 118	,1	,1	, &A0VT61LZ2},	//( - , Baz2) ПС по температуре в АЗ1
	{ 119	,1	,1	, &A0VT71LZ2},	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
	{ 120	,1	,1	, &A1VP41LZ2},	//( - , Baz2) Давление СБРОС ББ1 ниже АС
	{ 121	,1	,1	, &B1VP41LZ2},	//( - , Baz2) Давление СБРОС ББ2 ниже АС
	{ 122	,1	,1	, &B1VP81LZZ},	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
	{ 123	,1	,1	, &A1VP81LZZ},	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
	{ 124	,1	,1	, &A2VP41LZ2},	//( - , Baz2) Давление СБРОС РБ1 ниже АС
	{ 125	,8	,1	, &A2CP01RZ2},	//( - , Baz2) Текущее давление СБРОС РБ1
	{ 126	,1	,1	, &A2VP51LZ2},	//( - , Baz2) Давление СБРОС РБ1 ниже ПС
	{ 127	,1	,1	, &B2VP41LZ2},	//( - , Baz2) Давление СБРОС РБ2 ниже АС
	{ 128	,8	,1	, &B2CP01RZ2},	//( - , Baz2) Текущее давление СБРОС РБ2
	{ 129	,1	,1	, &B2VP51LZ2},	//( - , Baz2) Давление СБРОС РБ2 ниже ПС
	{ 130	,1	,1	, &B2VP81LZ2},	//( - , Baz2) Давление СБРОС РБ2 в норме
	{ 131	,1	,1	, &A2VP81LZ2},	//( - , Baz2) Давление СБРОС РБ1 в норме
	{ 132	,3	,1	, &A2IP01IZ2},	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
	{ 133	,3	,1	, &B2IP01IZ2},	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
	{ 134	,1	,1	, &R0ET01LZ2},	//( - , Baz2) Признак наличия неисправности по температуре  АЗ1
	{ 135	,3	,1	, &B0IT02IZ2},	//(vas84:04 - K03VASR, - ) Температура АЗ2-2
	{ 136	,1	,1	, &A0VP41LZ2},	//( - , Baz2) Давление АЗ1 ниже АС
	{ 137	,1	,1	, &B0VP41LZ2},	//( - , Baz2) Давление АЗ2 ниже АС
	{ 138	,1	,1	, &B0VP81LZZ},	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
	{ 139	,1	,1	, &B3VZ11LZ2},	//( - , Baz2) АЗ от НУП ИС2
	{ 140	,1	,1	, &B3IS22LDU},	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
	{ 141	,1	,1	, &R0VN69LZ2},	//( - , Baz2) ПС по усредненному периоду
	{ 142	,1	,1	, &R0VN79LZ2},	//( - , Baz2) АС по усредненному периоду
	{ 143	,8	,1	, &R0VR02RZ2},	//( - , Baz2) Усредненная реактивность
	{ 144	,1	,1	, &R0VZ71LZ2},	//(fds16:0a - K05FDSR, Baz2) Обобщенный сигнал АЗ 2 канала
	{ 145	,1	,1	, &R0VN70LZ2},	//( - , Baz2) АЗ по АС мощности РУ
	{ 146	,1	,1	, &R0VN80LZ2},	//( - , Baz2) АЗ по АС периода разгона РУ
	{ 147	,1	,1	, &A1EE01LS1},	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
	{ 148	,1	,1	, &A1EE01LS4},	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
	{ 149	,1	,1	, &A1EE01LS3},	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
	{ 150	,1	,1	, &A0EE01LZ2},	//( - , Baz2, SBz2DU) Исправность АКНП1
	{ 151	,1	,1	, &A0EE04LZ2},	//( - , Baz2, SBz2DU) Исправность АКНП4
	{ 152	,1	,1	, &A0EE02LZ2},	//( - , Baz2, SBz2DU) Исправность АКНП2
	{ 153	,1	,1	, &A0EE03LZ2},	//( - , Baz2, SBz2DU) Исправность АКНП3
	{ 154	,1	,1	, &A1EE01LS2},	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
	{ 155	,1	,1	, &A0EE05LZ2},	//( - , Baz2) Исправность сети АКНП1
	{ 156	,1	,1	, &A0EE06LZ2},	//( - , Baz2) Исправность сети АКНП2
	{ 157	,1	,1	, &A0EE07LZ2},	//( - , Baz2) Исправность сети АКНП3
	{ 158	,1	,1	, &A0EE08LZ2},	//( - , Baz2) Исправность сети АКНП4
	{ 159	,1	,1	, &A0VZ71LZ2},	//( - , Baz2) Обобщенный сигнал АС по АЗ1
	{ 160	,1	,1	, &A0EE00LZ2},	//( - , Baz2) Исправность АКНП АЗ1
	{ 161	,1	,1	, &B0EE00LZ2},	//( - , Baz2) Исправность АКНП АЗ2
	{ 162	,8	,1	, &R0VN02RZ2},	//( - , Baz2) Уровень мощности по каналу 2
	{ 163	,8	,1	, &R0VN03RZ2},	//( - , Baz2) Уровень мощности по каналу 3
	{ 164	,8	,1	, &R0VN04RZ2},	//( - , Baz2) Уровень мощности по каналу 4
	{ 165	,8	,1	, &R0VN05RZ2},	//( - , Baz2) Период разгона по каналу 1
	{ 166	,8	,1	, &R0VN06RZ2},	//( - , Baz2) Период разгона по каналу 2
	{ 167	,8	,1	, &R0VN07RZ2},	//( - , Baz2) Период разгона по каналу 3
	{ 168	,8	,1	, &R0VN08RZ2},	//( - , Baz2) Период разгона по каналу 4
	{ 169	,1	,1	, &R0VN61LZ2},	//( - , Baz2) ПС по мощности канал 1
	{ 170	,1	,1	, &R0VN62LZ2},	//( - , Baz2) ПС по мощности канал 2
	{ 171	,1	,1	, &R0VN63LZ2},	//( - , Baz2) ПС по мощности канал 3
	{ 172	,1	,1	, &R0VN64LZ2},	//( - , Baz2) ПС по мощности канал 4
	{ 173	,1	,1	, &R0VN65LZ2},	//( - , Baz2) ПС по периоду разгона канал 1
	{ 174	,1	,1	, &R0VN66LZ2},	//( - , Baz2) ПС по периоду разгона канал 2
	{ 175	,1	,1	, &R0VN67LZ2},	//( - , Baz2) ПС по периоду разгона канал 3
	{ 176	,1	,1	, &R0VN68LZ2},	//( - , Baz2) ПС по периоду разгона канал 4
	{ 177	,8	,1	, &R0VN09RZ2},	//( - , Baz2, SBz2DU) Усредненный период разгона
	{ 178	,1	,1	, &A3IS11LDU},	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
	{ 179	,1	,1	, &A3IS22LDU},	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
	{ 180	,1	,1	, &R0AD03LZ2},	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
	{ 181	,1	,1	, &B3IS11LDU},	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
	{ 182	,1	,1	, &A3VZ31LZ2},	//( - , Baz2) АЗ от ВУ ИС1
	{ 183	,1	,1	, &B3VZ31LZ2},	//( - , Baz2) АЗ от ВУ ИС2
	{ 184	,1	,1	, &R0AD05LZ2},	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
	{ 185	,1	,1	, &A3VZ11LZ2},	//( - , Baz2) АЗ от НУП ИС1
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
	{ 205	,8	,1	, &fEM_A1UL11RZZ},	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС
	{ 206	,8	,1	, &fEM_R7UI73RZZ},	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
	{ 207	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 208	,8	,1	, &internal1_m244_tx},	//(internal1_m244_tx) tx - время накопленное сек
	{ 209	,18	,1	, &internal1_m244_y0},	//(internal1_m244_y0) y0
	{ 210	,8	,1	, &internal1_m328_tx},	//(internal1_m328_tx) tx - время накопленное сек
	{ 211	,18	,1	, &internal1_m328_y0},	//(internal1_m328_y0) y0
	{ 212	,8	,1	, &internal1_m212_tx},	//(internal1_m212_tx) tx - время накопленное сек
	{ 213	,18	,1	, &internal1_m212_y0},	//(internal1_m212_y0) y0
	{ 214	,8	,1	, &internal1_m210_tx},	//(internal1_m210_tx) tx - время накопленное сек
	{ 215	,18	,1	, &internal1_m210_y0},	//(internal1_m210_y0) y0
	{ 216	,8	,1	, &internal1_m252_tx},	//(internal1_m252_tx) tx - время накопленное сек
	{ 217	,18	,1	, &internal1_m252_y0},	//(internal1_m252_y0) y0
	{ 218	,8	,1	, &internal1_m209_tx},	//(internal1_m209_tx) tx - время накопленное сек
	{ 219	,18	,1	, &internal1_m209_y0},	//(internal1_m209_y0) y0
	{ 220	,8	,1	, &internal1_m207_tx},	//(internal1_m207_tx) tx - время накопленное сек
	{ 221	,18	,1	, &internal1_m207_y0},	//(internal1_m207_y0) y0
	{ 222	,3	,1	, &internal1_m33_tx},	//(internal1_m33_tx) tx - внутренний параметр
	{ 223	,8	,1	, &internal1_m143_y0},	//(internal1_m143_y0) y0
	{ 224	,8	,1	, &internal1_m141_y0},	//(internal1_m141_y0) y0
	{ 225	,8	,1	, &internal1_m91_y0},	//(internal1_m91_y0) y0
	{ 226	,8	,1	, &internal1_m89_y0},	//(internal1_m89_y0) y0
	{ 227	,1	,1	, &internal1_m154_y1},	//(internal1_m154_y1) y1 - внутренний параметр
	{ 228	,1	,1	, &internal1_m165_y1},	//(internal1_m165_y1) y1 - внутренний параметр
	{ 229	,5	,1	, &internal1_m314_q0},	//(internal1_m314_q0) q0 - внутренний параметр
	{ 230	,1	,1	, &internal1_m125_y0},	//(internal1_m125_y0) state
	{ 231	,1	,1	, &internal1_m119_y0},	//(internal1_m119_y0) state
	{ 232	,1	,1	, &internal1_m105_y1},	//(internal1_m105_y1) y1 - внутренний параметр
	{ 233	,1	,1	, &internal1_m114_y1},	//(internal1_m114_y1) y1 - внутренний параметр
	{ 234	,1	,1	, &internal1_m93_y1},	//(internal1_m93_y1) y1 - внутренний параметр
	{ 235	,1	,1	, &internal1_m103_y1},	//(internal1_m103_y1) y1 - внутренний параметр
	{ 236	,1	,1	, &internal1_m153_y1},	//(internal1_m153_y1) y1 - внутренний параметр
	{ 237	,1	,1	, &internal1_m161_y1},	//(internal1_m161_y1) y1 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="baz2.bin\0";   // Имя файла для сохранения констант
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
static ModbusRegister coil_Baz2[]={  // 
	{&A0EE08LZ2,1,0},	//( - , Baz2) Исправность сети АКНП4
	{&A0EE07LZ2,1,1},	//( - , Baz2) Исправность сети АКНП3
	{&A0EE06LZ2,1,2},	//( - , Baz2) Исправность сети АКНП2
	{&A0EE05LZ2,1,3},	//( - , Baz2) Исправность сети АКНП1
	{&R0EE02LDU,1,4},	//( - , Baz2) Питание  АКНП  отключить
	{&R0AD16LDU,1,5},	//( - , Baz2) Имитация срабатывания верхней АС I УР
	{&R0AD14LDU,1,6},	//( - , Baz2) Имитация срабатывания верхней АС II УР
	{&R0MD34LP1,1,7},	//( - , Baz2) Кнопка Квитировать
	{&R0VW23LDU,1,8},	//( - , Baz2, SBz2DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,9},	//( - , Baz2, SBz2DU) Индикация выбора АЗ1 или АЗ1+АЗ2
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
	{&A0EE01LZ2,1,14},	//( - , Baz2, SBz2DU) Исправность АКНП1
	{&R0VN80LZ2,1,15},	//( - , Baz2) АЗ по АС периода разгона РУ
	{&TestDiagnBaz2,1,16},	//( - , Baz2) Неисправность от
	{&R0AD16LZ2,1,17},	//( - , Baz2) Имитация АЗ от 1УР (датчик2)
	{&R0AD15LZ2,1,18},	//( - , Baz2) Имитация АЗ от 1УР (датчик1)
	{&R0VN78LZ2,1,19},	//( - K02VDSR, Baz2) АС по периоду разгона канал  4
	{&R0VN77LZ2,1,20},	//( - K02VDSR, Baz2) АС по периоду разгона канал  3
	{&R0VN74LZ2,1,21},	//( - K01VDSR, Baz2) АС по мощности канал 4
	{&R0VN73LZ2,1,22},	//( - K01VDSR, Baz2) АС по мощности канал 3
	{&R0VN76LZ2,1,23},	//( - K02VDSR, Baz2) АС по периоду разгона канал  2
	{&R0VN72LZ2,1,24},	//( - K01VDSR, Baz2) АС по мощности канал 2
	{&R0VN75LZ2,1,25},	//( - K02VDSR, Baz2) АС по периоду разгона канал 1
	{&R0VN71LZ2,1,26},	//( - K01VDSR, Baz2) АС по мощности канал 1
	{&R7II72LZ2,1,27},	//( - K06VDSR, Baz2) Сработала АС IУР РАД (датчик 2)
	{&R7II71LZ2,1,28},	//( - K05VDSR, Baz2) Сработала АС IУР РАД (датчик 1)
	{&R7II73LZ2,1,29},	//( - K07VDSR, Baz2) Сработала АС II УР РАД
	{&B0VP71LZ2,1,30},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
	{&A0VP71LZ2,1,31},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
	{&R0ET02LZ2,1,32},	//( - , Baz2) Признак наличия неисправности по температуре АЗ2
	{&B0VP41LZ2,1,33},	//( - , Baz2) Давление АЗ2 ниже АС
	{&A0VP41LZ2,1,34},	//( - , Baz2) Давление АЗ1 ниже АС
	{&R0ET01LZ2,1,35},	//( - , Baz2) Признак наличия неисправности по температуре  АЗ1
	{&A2VP81LZ2,1,36},	//( - , Baz2) Давление СБРОС РБ1 в норме
	{&B2VP81LZ2,1,37},	//( - , Baz2) Давление СБРОС РБ2 в норме
	{&B2VP51LZ2,1,38},	//( - , Baz2) Давление СБРОС РБ2 ниже ПС
	{&B2VP41LZ2,1,39},	//( - , Baz2) Давление СБРОС РБ2 ниже АС
	{&A2VP51LZ2,1,40},	//( - , Baz2) Давление СБРОС РБ1 ниже ПС
	{&A2VP41LZ2,1,41},	//( - , Baz2) Давление СБРОС РБ1 ниже АС
	{&B1VP41LZ2,1,42},	//( - , Baz2) Давление СБРОС ББ2 ниже АС
	{&A1VP41LZ2,1,43},	//( - , Baz2) Давление СБРОС ББ1 ниже АС
	{&A0VT71LZ2,1,44},	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
	{&A0VT61LZ2,1,45},	//( - , Baz2) ПС по температуре в АЗ1
	{&R0VN70LZ2,1,46},	//( - , Baz2) АЗ по АС мощности РУ
	{&R0VZ71LZ2,1,47},	//( - K05FDSR, Baz2) Обобщенный сигнал АЗ 2 канала
	{&R0VN79LZ2,1,48},	//( - , Baz2) АС по усредненному периоду
	{&R0VN69LZ2,1,49},	//( - , Baz2) ПС по усредненному периоду
	{&B3VZ11LZ2,1,50},	//( - , Baz2) АЗ от НУП ИС2
	{&A3VZ11LZ2,1,51},	//( - , Baz2) АЗ от НУП ИС1
	{&B3VZ31LZ2,1,52},	//( - , Baz2) АЗ от ВУ ИС2
	{&A3VZ31LZ2,1,53},	//( - , Baz2) АЗ от ВУ ИС1
	{&R0VN68LZ2,1,54},	//( - , Baz2) ПС по периоду разгона канал 4
	{&R0VN67LZ2,1,55},	//( - , Baz2) ПС по периоду разгона канал 3
	{&R0VN66LZ2,1,56},	//( - , Baz2) ПС по периоду разгона канал 2
	{&R0VN65LZ2,1,57},	//( - , Baz2) ПС по периоду разгона канал 1
	{&R0VN64LZ2,1,58},	//( - , Baz2) ПС по мощности канал 4
	{&R0VN63LZ2,1,59},	//( - , Baz2) ПС по мощности канал 3
	{&R0VN62LZ2,1,60},	//( - , Baz2) ПС по мощности канал 2
	{&R0VN61LZ2,1,61},	//( - , Baz2) ПС по мощности канал 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_Baz2[]={  // 
	{&B0CT01IZ2,8,0},	//( - , Baz2, SBz2DU) Температура АЗ2-1
	{&R0VN11RZ2,8,2},	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ1
	{&R0VZ05UZ2,5,4},	//( - , Baz2) Индикатор причины сброса
	{&TTLBaz2,3,6},	//( - , Baz2) ttl
	{&R0VN02RZ2,8,7},	//( - , Baz2) Уровень мощности по каналу 2
	{&R0VN01RZ2,8,9},	//( - , Baz2) Уровень мощности по каналу 1
	{&A0EP02IZ2,3,11},	//( - , Baz2) Индикатор -Давление  АЗ1 ниже АС
	{&B0EP02IZ2,3,12},	//( - , Baz2) Индикатор -Давление  АЗ2 ниже АС
	{&B2CP01RZ2,8,13},	//( - , Baz2) Текущее давление СБРОС РБ2
	{&A2CP01RZ2,8,15},	//( - , Baz2) Текущее давление СБРОС РБ1
	{&A0CT01IZ2,8,17},	//( - , Baz2, SBz2DU) Температура АЗ1-1
	{&R0VR02RZ2,8,19},	//( - , Baz2) Усредненная реактивность
	{&R0VN09RZ2,8,21},	//( - , Baz2, SBz2DU) Усредненный период разгона
	{&R0VN08RZ2,8,23},	//( - , Baz2) Период разгона по каналу 4
	{&R0VN07RZ2,8,25},	//( - , Baz2) Период разгона по каналу 3
	{&R0VN06RZ2,8,27},	//( - , Baz2) Период разгона по каналу 2
	{&R0VN05RZ2,8,29},	//( - , Baz2) Период разгона по каналу 1
	{&R0VN04RZ2,8,31},	//( - , Baz2) Уровень мощности по каналу 4
	{&R0VN03RZ2,8,33},	//( - , Baz2) Уровень мощности по каналу 3
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
	{&fEM_A1UL12RZZ,8,38},	//( - , Baz2) Время задержки АЗ от НУ ИС(сек)
	{&fEM_A1UL11RZZ,8,40},	//( - , Baz2) Время задержки АЗ от ВУ ИС
	{&fEM_R7UI73RZZ,8,42},	//( - , Baz2) Время задержки  срабатывания АС II УР
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SBz2DU[]={  // 
	{&R0AD21LDU,1,0},	//( - , SBz2DU) Подключить защиту от II УР
	{&R0VW23LDU,1,1},	//( - , Baz2, SBz2DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,2},	//( - , Baz2, SBz2DU) Индикация выбора АЗ1 или АЗ1+АЗ2
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
	{&A0VT71LZ2,1,10},	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SBz2DU[]={  // 
	{&B0CT01IZ2,8,0},	//( - , Baz2, SBz2DU) Температура АЗ2-1
	{&R0VN11RZ2,8,2},	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ1
	{&R0VN09RZ2,8,4},	//( - , Baz2, SBz2DU) Усредненный период разгона
	{&A0CT01IZ2,8,6},	//( - , Baz2, SBz2DU) Температура АЗ1-1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SBz2DU[]={  // 
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
	{&R0DE3DLZ2,1,0},	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 6
	{&R0DE3CLZ2,1,1},	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 5
	{&R0DEB4LZ2,1,2},	//( - S13SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 6
	{&R0DEB3LZ2,1,3},	//( - S12SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 6
	{&R0DEB2LZ2,1,4},	//( - S11SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 5
	{&R0DEB1LZ2,1,5},	//( - S10SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 5
	{&R0DE36LZ2,1,6},	//( - S06SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3.1 место 1
	{&R0DE39LZ2,1,7},	//( - S09SBK, DiagnBaz2) диагностика шкафа Баз2 МП24-2 место 4
	{&R0DE37LZ2,1,8},	//( - S07SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3.1 место 2
	{&R0DE38LZ2,1,9},	//( - S08SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3 место 3
	{&R0DE35LZ2,1,10},	//( - S05SBK, DiagnBaz2) диагностика шкафа Баз2 температура больше 53
	{&R0DE34LZ2,1,11},	//( - S04SBK, DiagnBaz2) диагностика шкафа Баз2 температура меньше 43
	{&R0DE33LZ2,1,12},	//( - S03SBK, DiagnBaz2) диагностика шкафа Баз2 двери
	{&R0DE32LZ2,1,13},	//( - S02SBK, DiagnBaz2) диагностика шкафа Баз2 сеть 2
	{&R0DE31LZ2,1,14},	//( - S01SBK, DiagnBaz2) диагностика шкафа Баз2 сеть 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DiagnBaz2[]={  // 
	{&R0DE08LZ2,3,0},	//( - Diagn, DiagnBaz2) диагностика модуля Баз2 на 8 месте
	{&R0DE0ALZ2,3,1},	//( - Diagn, DiagnBaz2) диагностика модуля Баз2 на 10 месте
	{&R0DE07LZ2,3,2},	//( - Diagn, DiagnBaz2) диагностика модуля Баз2 на 7 месте
	{&R0DE06LZ2,3,3},	//( - Diagn, DiagnBaz2) диагностика модуля Баз2 на 6 месте
	{&R0DE05LZ2,3,4},	//( - Diagn, DiagnBaz2) диагностика модуля Баз2 на 5 месте
	{&R0DE04LZ2,3,5},	//( - Diagn, DiagnBaz2) диагностика модуля Баз2 на 4 месте
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
	{&R6IS66LZZ,1,0},	//( - K17DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{&R6IS67LZZ,1,1},	//( - K18DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{&R6IS68LZZ,1,2},	//( - K19DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№7) ССДИ-2
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
	{1,5019,&coil_MBz2A1[0],&di_MBz2A1[0],&ir_MBz2A1[0],&hr_MBz2A1[0],NULL,MBz2A1_ip1,MBz2A1_ip2,100},	 //Мастер Баз2 в AKNP1
	{1,5020,&coil_MBz2A2[0],&di_MBz2A2[0],&ir_MBz2A2[0],&hr_MBz2A2[0],NULL,MBz2A2_ip1,MBz2A2_ip2,100},	 //Мастер Баз2 в AKNP2
	{1,5021,&coil_MBz2A3[0],&di_MBz2A3[0],&ir_MBz2A3[0],&hr_MBz2A3[0],NULL,MBz2A3_ip1,MBz2A3_ip2,100},	 //Мастер Баз2 в AKNP3
	{1,5022,&coil_MBz2A4[0],&di_MBz2A4[0],&ir_MBz2A4[0],&hr_MBz2A4[0],NULL,MBz2A4_ip1,MBz2A4_ip2,100},	 //Мастер Баз2 в AKNP4

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
	{&A0IT02IZ2,3,0},
	{&B2IP01IZ2,3,9},
	{&R0DE04LZ2,3,26},
	{&A2IP01IZ2,3,3},
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
	{&R0AD04LZ2,1,14},
	{&R0VN75LZ2,1,2},
	{&R0VN71LZ2,1,0},
	{&R0DE05LZ2,3,64},
	{&A1VN71LS1,1,6},
	{&A3IS11LDU,1,8},
	{&A3IS22LDU,1,10},
	{&B2IS12LDU,1,20},
	{&A2IS12LDU,1,18},
	{&R0AD03LZ2,1,12},
	{&A1EE01LS1,1,4},
	{&R0AD05LZ2,1,16},
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
	{&B3IS11LDU,1,8},
	{&R0VN72LZ2,1,0},
	{&R0VN76LZ2,1,2},
	{&R0DE06LZ2,3,64},
	{&A1VN71LS2,1,6},
	{&B3IS22LDU,1,10},
	{&A1EE01LS2,1,4},
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
	{&R0VN78LZ2,1,2},
	{&R0VN74LZ2,1,0},
	{&R0DE07LZ2,3,64},
	{&A1VN71LS4,1,6},
	{&A1EE01LS4,1,4},
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
	{&A1VP81LZZ,1,18},
	{&B1VP81LZZ,1,24},
	{&R7II73LZ2,1,12},
	{&A1EE01LS3,1,4},
	{&A0VP81LZZ,1,16},
	{&R7II72LZ2,1,10},
	{&R0DE08LZ2,3,64},
	{&B0VP81LZZ,1,22},
	{&A1VN71LS3,1,6},
	{&R7II71LZ2,1,8},
	{&R0VN73LZ2,1,0},
	{&R0VN77LZ2,1,2},
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
	{&R0VZ71LZ2,1,8},
	{&R0AD14LZ2,1,4},
	{&A1VN71LZ2,1,6},
	{&A3VZ15LZ2,1,2},
	{&A3VZ13LZ2,1,0},
	{&R0DE0ALZ2,3,38},
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
	{&R0DE31LZ2,1,0},
	{&R0DE32LZ2,1,2},
	{&R0DE33LZ2,1,4},
	{&R0DE34LZ2,1,6},
	{&R0DE35LZ2,1,8},
	{&R0DE38LZ2,1,14},
	{&R0DE37LZ2,1,12},
	{&R0DE39LZ2,1,16},
	{&R0DE36LZ2,1,10},
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
// checked_ 1  | if(ExistFile(Scheme.h)) AddCode_H(  Baz2\Scheme\Scheme.h
// Baz2\Scheme\Scheme.h
#endif
