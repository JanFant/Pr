#ifndef BAZ2_H
#define BAZ2_H
// Подсистема Baz2:Baz2
static char SimulOn=0;
static short CodeSub=6;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=50;	 // Время цикла в ms
float takt, taktScheme=0, taktSS=0;
#define SIZE_BUFFER 698
static char BUFFER[698];
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
#define R6IS66LZZ	 BUFFER[8]	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 5	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[10]	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 6	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[12]	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 7	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
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
#define R0DE3CLZ2	 BUFFER[101]	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 5
#define idR0DE3CLZ2	 47	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 5
#define R0DE3DLZ2	 BUFFER[103]	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 6
#define idR0DE3DLZ2	 48	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 6
#define TestDiagnBaz2	 BUFFER[105]	//( - , Baz2) Неисправность от
#define idTestDiagnBaz2	 49	//( - , Baz2) Неисправность от
#define R0MW11IP1	 BUFFER[107]	//( - , Baz2) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 50	//( - , Baz2) Переключатель ВЫСТРЕЛ
#define PS9	 BUFFER[110]	//( - , - ) АС 1 ур (д2)
#define idPS9	 51	//( - , - ) АС 1 ур (д2)
#define PS1	 BUFFER[112]	//( - , - ) давление АЗ1
#define idPS1	 52	//( - , - ) давление АЗ1
#define PS2	 BUFFER[114]	//( - , - ) АЗ от ВУ ИС1
#define idPS2	 53	//( - , - ) АЗ от ВУ ИС1
#define PS3	 BUFFER[116]	//( - , - ) АЗ от НУП ИС1
#define idPS3	 54	//( - , - ) АЗ от НУП ИС1
#define PS4	 BUFFER[118]	//( - , - ) АЗ темп АЗ1
#define idPS4	 55	//( - , - ) АЗ темп АЗ1
#define PS5	 BUFFER[120]	//( - , - ) АС по Периоду АЗ1
#define idPS5	 56	//( - , - ) АС по Периоду АЗ1
#define PS6	 BUFFER[122]	//( - , - ) АС по мощности АЗ1
#define idPS6	 57	//( - , - ) АС по мощности АЗ1
#define PS7	 BUFFER[124]	//( - , - ) Исправность акнп А32
#define idPS7	 58	//( - , - ) Исправность акнп А32
#define PS8	 BUFFER[126]	//( - , - ) Исправность акнп А31
#define idPS8	 59	//( - , - ) Исправность акнп А31
#define PS10	 BUFFER[128]	//( - , - ) АС 1 ур (д1)
#define idPS10	 60	//( - , - ) АС 1 ур (д1)
#define PS11	 BUFFER[130]	//( - , - ) АС 2 ур
#define idPS11	 61	//( - , - ) АС 2 ур
#define PS16	 BUFFER[132]	//( - , - ) АЗ от НУП ИС2
#define idPS16	 62	//( - , - ) АЗ от НУП ИС2
#define PS17	 BUFFER[134]	//( - , - ) Аз по АС любого давления АЗ2
#define idPS17	 63	//( - , - ) Аз по АС любого давления АЗ2
#define PS15	 BUFFER[136]	//( - , - ) АЗ от ВУ ИС2
#define idPS15	 64	//( - , - ) АЗ от ВУ ИС2
#define PS14	 BUFFER[138]	//( - , - ) АС по температуре АЗ2
#define idPS14	 65	//( - , - ) АС по температуре АЗ2
#define PS12	 BUFFER[140]	//( - , - ) АС по мощности АЗ2
#define idPS12	 66	//( - , - ) АС по мощности АЗ2
#define PS13	 BUFFER[142]	//( - , - ) АС по периоду АЗ2
#define idPS13	 67	//( - , - ) АС по периоду АЗ2
#define R0VZ05U	 BUFFER[144]	//( - , - ) причины сброса
#define idR0VZ05U	 68	//( - , - ) причины сброса
#define B8VC01RDU	 BUFFER[149]	//( - , SBz2DU, MBz2A1, MBz2A2, MBz2A3, MBz2A4) Координата АЗ2, мм
#define idB8VC01RDU	 69	//( - , SBz2DU, MBz2A1, MBz2A2, MBz2A3, MBz2A4) Координата АЗ2, мм
#define R0MW12IP2	 BUFFER[154]	//( - , Baz2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define idR0MW12IP2	 70	//( - , Baz2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define A2IS12LDU	 BUFFER[157]	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	 71	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define B2IS12LDU	 BUFFER[159]	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	 72	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define R0EE02LDU	 BUFFER[161]	//( - , Baz2) Питание  АКНП  отключить
#define idR0EE02LDU	 73	//( - , Baz2) Питание  АКНП  отключить
#define R0DE04LZ2	 BUFFER[163]	//(vas84:04 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 4 месте
#define idR0DE04LZ2	 74	//(vas84:04 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 4 месте
#define R0DE05LZ2	 BUFFER[166]	//(vds32:05 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 5 месте
#define idR0DE05LZ2	 75	//(vds32:05 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 5 месте
#define R0DE06LZ2	 BUFFER[169]	//(vds32:06 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 6 месте
#define idR0DE06LZ2	 76	//(vds32:06 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 6 месте
#define R0DE07LZ2	 BUFFER[172]	//(vds32:07 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 7 месте
#define idR0DE07LZ2	 77	//(vds32:07 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 7 месте
#define R0DE0ALZ2	 BUFFER[175]	//(fds16:0a - Diagn, DiagnBaz2) диагностика модуля Баз2 на 10 месте
#define idR0DE0ALZ2	 78	//(fds16:0a - Diagn, DiagnBaz2) диагностика модуля Баз2 на 10 месте
#define R0DE31LZ2	 BUFFER[178]	//(sbk:20 - S01SBK, DiagnBaz2) диагностика шкафа Баз2 сеть 1
#define idR0DE31LZ2	 79	//(sbk:20 - S01SBK, DiagnBaz2) диагностика шкафа Баз2 сеть 1
#define R0DE08LZ2	 BUFFER[180]	//(vds32:08 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 8 месте
#define idR0DE08LZ2	 80	//(vds32:08 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 8 месте
#define TTLBaz2	 BUFFER[183]	//( - , Baz2) ttl
#define idTTLBaz2	 81	//( - , Baz2) ttl
#define R0DE32LZ2	 BUFFER[186]	//(sbk:20 - S02SBK, DiagnBaz2) диагностика шкафа Баз2 сеть 2
#define idR0DE32LZ2	 82	//(sbk:20 - S02SBK, DiagnBaz2) диагностика шкафа Баз2 сеть 2
#define R0DE33LZ2	 BUFFER[188]	//(sbk:20 - S03SBK, DiagnBaz2) диагностика шкафа Баз2 двери
#define idR0DE33LZ2	 83	//(sbk:20 - S03SBK, DiagnBaz2) диагностика шкафа Баз2 двери
#define R0DE34LZ2	 BUFFER[190]	//(sbk:20 - S04SBK, DiagnBaz2) диагностика шкафа Баз2 температура меньше 43
#define idR0DE34LZ2	 84	//(sbk:20 - S04SBK, DiagnBaz2) диагностика шкафа Баз2 температура меньше 43
#define R0DE35LZ2	 BUFFER[192]	//(sbk:20 - S05SBK, DiagnBaz2) диагностика шкафа Баз2 температура больше 53
#define idR0DE35LZ2	 85	//(sbk:20 - S05SBK, DiagnBaz2) диагностика шкафа Баз2 температура больше 53
#define R0DE38LZ2	 BUFFER[194]	//(sbk:20 - S08SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3 место 3
#define idR0DE38LZ2	 86	//(sbk:20 - S08SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3 место 3
#define R0DE37LZ2	 BUFFER[196]	//(sbk:20 - S07SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3.1 место 2
#define idR0DE37LZ2	 87	//(sbk:20 - S07SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3.1 место 2
#define R0DE39LZ2	 BUFFER[198]	//(sbk:20 - S09SBK, DiagnBaz2) диагностика шкафа Баз2 МП24-2 место 4
#define idR0DE39LZ2	 88	//(sbk:20 - S09SBK, DiagnBaz2) диагностика шкафа Баз2 МП24-2 место 4
#define R0DE36LZ2	 BUFFER[200]	//(sbk:20 - S06SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3.1 место 1
#define idR0DE36LZ2	 89	//(sbk:20 - S06SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3.1 место 1
#define R0DEB1LZ2	 BUFFER[202]	//(sbk:20 - S10SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 5
#define idR0DEB1LZ2	 90	//(sbk:20 - S10SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 5
#define R0DEB2LZ2	 BUFFER[204]	//(sbk:20 - S11SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 5
#define idR0DEB2LZ2	 91	//(sbk:20 - S11SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 5
#define R0DEB3LZ2	 BUFFER[206]	//(sbk:20 - S12SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 6
#define idR0DEB3LZ2	 92	//(sbk:20 - S12SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 6
#define R0DEB4LZ2	 BUFFER[208]	//(sbk:20 - S13SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 6
#define idR0DEB4LZ2	 93	//(sbk:20 - S13SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 6
#define A0VP81LZZ	 BUFFER[210]	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define idA0VP81LZZ	 94	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define R0ET02LZ2	 BUFFER[212]	//( - , Baz2) Признак наличия неисправности по температуре АЗ2
#define idR0ET02LZ2	 95	//( - , Baz2) Признак наличия неисправности по температуре АЗ2
#define B0EP02IZ2	 BUFFER[214]	//( - , Baz2) Индикатор -Давление  АЗ2 ниже АС
#define idB0EP02IZ2	 96	//( - , Baz2) Индикатор -Давление  АЗ2 ниже АС
#define A0EP02IZ2	 BUFFER[217]	//( - , Baz2) Индикатор -Давление  АЗ1 ниже АС
#define idA0EP02IZ2	 97	//( - , Baz2) Индикатор -Давление  АЗ1 ниже АС
#define A0VP71LZ2	 BUFFER[220]	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ2	 98	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
#define B0VP71LZ2	 BUFFER[222]	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ2	 99	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
#define R0VN02RS1	 BUFFER[224]	//( - , MBz2A1) Уровень мощности канал 1
#define idR0VN02RS1	 100	//( - , MBz2A1) Уровень мощности канал 1
#define R0VN02RS2	 BUFFER[229]	//( - , MBz2A2) Уровень мощности канал 2
#define idR0VN02RS2	 101	//( - , MBz2A2) Уровень мощности канал 2
#define R0VN02RS3	 BUFFER[234]	//( - , MBz2A3) Уровень мощности канал 3
#define idR0VN02RS3	 102	//( - , MBz2A3) Уровень мощности канал 3
#define R0VN02RS4	 BUFFER[239]	//( - , MBz2A4) Уровень мощности канал 4
#define idR0VN02RS4	 103	//( - , MBz2A4) Уровень мощности канал 4
#define R0VN01RS1	 BUFFER[244]	//( - , MBz2A1) Период разгона канал 1
#define idR0VN01RS1	 104	//( - , MBz2A1) Период разгона канал 1
#define R0VN01RS2	 BUFFER[249]	//( - , MBz2A2) Период разгона канал 2
#define idR0VN01RS2	 105	//( - , MBz2A2) Период разгона канал 2
#define R0VN01RS3	 BUFFER[254]	//( - , MBz2A3) Период разгона канал 3
#define idR0VN01RS3	 106	//( - , MBz2A3) Период разгона канал 3
#define R0VN01RS4	 BUFFER[259]	//( - , MBz2A4) Период разгона канал 4
#define idR0VN01RS4	 107	//( - , MBz2A4) Период разгона канал 4
#define R0VN61LS1	 BUFFER[264]	//( - , MBz2A1) ПС по мощности канал 1
#define idR0VN61LS1	 108	//( - , MBz2A1) ПС по мощности канал 1
#define R0VN61LS2	 BUFFER[266]	//( - , MBz2A2) ПС по мощности канал 2
#define idR0VN61LS2	 109	//( - , MBz2A2) ПС по мощности канал 2
#define R0VN61LS3	 BUFFER[268]	//( - , MBz2A3) ПС по мощности канал 3
#define idR0VN61LS3	 110	//( - , MBz2A3) ПС по мощности канал 3
#define R0VN61LS4	 BUFFER[270]	//( - , MBz2A4) ПС по мощности канал 4
#define idR0VN61LS4	 111	//( - , MBz2A4) ПС по мощности канал 4
#define R0VN65LS1	 BUFFER[272]	//( - , MBz2A1) ПС по периоду разгона канал 1
#define idR0VN65LS1	 112	//( - , MBz2A1) ПС по периоду разгона канал 1
#define R0VN65LS2	 BUFFER[274]	//( - , MBz2A2) ПС по периоду разгона  канал 2
#define idR0VN65LS2	 113	//( - , MBz2A2) ПС по периоду разгона  канал 2
#define R0VN65LS3	 BUFFER[276]	//( - , MBz2A3) ПС по периоду разгона канал 3
#define idR0VN65LS3	 114	//( - , MBz2A3) ПС по периоду разгона канал 3
#define R0VN65LS4	 BUFFER[278]	//( - , MBz2A4) ПС по периоду разгона канал 4
#define idR0VN65LS4	 115	//( - , MBz2A4) ПС по периоду разгона канал 4
#define R0VN01RZ2	 BUFFER[280]	//( - , Baz2) Уровень мощности по каналу 1
#define idR0VN01RZ2	 116	//( - , Baz2) Уровень мощности по каналу 1
#define A0IT02IZ2	 BUFFER[285]	//(vas84:04 - K01VASR, - ) Температура АЗ1-2
#define idA0IT02IZ2	 117	//(vas84:04 - K01VASR, - ) Температура АЗ1-2
#define A0CT01IZ2	 BUFFER[288]	//( - , Baz2, SBz2DU) Температура АЗ1-1
#define idA0CT01IZ2	 118	//( - , Baz2, SBz2DU) Температура АЗ1-1
#define A0VT61LZ2	 BUFFER[293]	//( - , Baz2) ПС по температуре в АЗ1
#define idA0VT61LZ2	 119	//( - , Baz2) ПС по температуре в АЗ1
#define A0VT71LZ2	 BUFFER[295]	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
#define idA0VT71LZ2	 120	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
#define A1VP41LZ2	 BUFFER[297]	//( - , Baz2, SBz2DU) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ2	 121	//( - , Baz2, SBz2DU) Давление СБРОС ББ1 ниже АС
#define B1VP41LZ2	 BUFFER[299]	//( - , Baz2, SBz2DU) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ2	 122	//( - , Baz2, SBz2DU) Давление СБРОС ББ2 ниже АС
#define B1VP81LZZ	 BUFFER[301]	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	 123	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define A1VP81LZZ	 BUFFER[303]	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	 124	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define A2VP41LZ2	 BUFFER[305]	//( - , Baz2) Давление СБРОС РБ1 ниже АС
#define idA2VP41LZ2	 125	//( - , Baz2) Давление СБРОС РБ1 ниже АС
#define A2CP01RZ2	 BUFFER[307]	//( - , Baz2) Текущее давление СБРОС РБ1
#define idA2CP01RZ2	 126	//( - , Baz2) Текущее давление СБРОС РБ1
#define A2VP51LZ2	 BUFFER[312]	//( - , Baz2) Давление СБРОС РБ1 ниже ПС
#define idA2VP51LZ2	 127	//( - , Baz2) Давление СБРОС РБ1 ниже ПС
#define B2VP41LZ2	 BUFFER[314]	//( - , Baz2) Давление СБРОС РБ2 ниже АС
#define idB2VP41LZ2	 128	//( - , Baz2) Давление СБРОС РБ2 ниже АС
#define B2CP01RZ2	 BUFFER[316]	//( - , Baz2) Текущее давление СБРОС РБ2
#define idB2CP01RZ2	 129	//( - , Baz2) Текущее давление СБРОС РБ2
#define B2VP51LZ2	 BUFFER[321]	//( - , Baz2) Давление СБРОС РБ2 ниже ПС
#define idB2VP51LZ2	 130	//( - , Baz2) Давление СБРОС РБ2 ниже ПС
#define B2VP81LZ2	 BUFFER[323]	//( - , Baz2) Давление СБРОС РБ2 в норме
#define idB2VP81LZ2	 131	//( - , Baz2) Давление СБРОС РБ2 в норме
#define A2VP81LZ2	 BUFFER[325]	//( - , Baz2) Давление СБРОС РБ1 в норме
#define idA2VP81LZ2	 132	//( - , Baz2) Давление СБРОС РБ1 в норме
#define A2IP01IZ2	 BUFFER[327]	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ2	 133	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define B2IP01IZ2	 BUFFER[330]	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ2	 134	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define R0ET01LZ2	 BUFFER[333]	//( - , Baz2) Признак наличия неисправности по температуре  АЗ1
#define idR0ET01LZ2	 135	//( - , Baz2) Признак наличия неисправности по температуре  АЗ1
#define B0IT02IZ2	 BUFFER[335]	//(vas84:04 - K03VASR, - ) Температура АЗ2-2
#define idB0IT02IZ2	 136	//(vas84:04 - K03VASR, - ) Температура АЗ2-2
#define A0VP41LZ2	 BUFFER[338]	//( - , Baz2) Давление АЗ1 ниже АС
#define idA0VP41LZ2	 137	//( - , Baz2) Давление АЗ1 ниже АС
#define B0VP41LZ2	 BUFFER[340]	//( - , Baz2) Давление АЗ2 ниже АС
#define idB0VP41LZ2	 138	//( - , Baz2) Давление АЗ2 ниже АС
#define B0VP81LZZ	 BUFFER[342]	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	 139	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define B3VZ11LZ2	 BUFFER[344]	//( - , Baz2) АЗ от НУП ИС2
#define idB3VZ11LZ2	 140	//( - , Baz2) АЗ от НУП ИС2
#define B3IS22LDU	 BUFFER[346]	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
#define idB3IS22LDU	 141	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
#define R0VN69LZ2	 BUFFER[348]	//( - , Baz2) ПС по усредненному периоду
#define idR0VN69LZ2	 142	//( - , Baz2) ПС по усредненному периоду
#define R0VN79LZ2	 BUFFER[350]	//( - , Baz2) АС по усредненному периоду
#define idR0VN79LZ2	 143	//( - , Baz2) АС по усредненному периоду
#define R0VR02RZ2	 BUFFER[352]	//( - , Baz2) Усредненная реактивность
#define idR0VR02RZ2	 144	//( - , Baz2) Усредненная реактивность
#define R0VZ71LZ2	 BUFFER[357]	//(fds16:0a - K05FDSR, Baz2) Обобщенный сигнал АЗ 2 канала
#define idR0VZ71LZ2	 145	//(fds16:0a - K05FDSR, Baz2) Обобщенный сигнал АЗ 2 канала
#define R0VN70LZ2	 BUFFER[359]	//( - , Baz2) АЗ по АС мощности РУ
#define idR0VN70LZ2	 146	//( - , Baz2) АЗ по АС мощности РУ
#define R0VN80LZ2	 BUFFER[361]	//( - , Baz2) АЗ по АС периода разгона РУ
#define idR0VN80LZ2	 147	//( - , Baz2) АЗ по АС периода разгона РУ
#define A1EE01LS1	 BUFFER[363]	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define idA1EE01LS1	 148	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define A1EE01LS4	 BUFFER[365]	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define idA1EE01LS4	 149	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define A1EE01LS3	 BUFFER[367]	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define idA1EE01LS3	 150	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define A0EE01LZ2	 BUFFER[369]	//( - , Baz2, SBz2DU) Исправность АКНП1
#define idA0EE01LZ2	 151	//( - , Baz2, SBz2DU) Исправность АКНП1
#define A0EE04LZ2	 BUFFER[371]	//( - , Baz2, SBz2DU) Исправность АКНП4
#define idA0EE04LZ2	 152	//( - , Baz2, SBz2DU) Исправность АКНП4
#define A0EE02LZ2	 BUFFER[373]	//( - , Baz2, SBz2DU) Исправность АКНП2
#define idA0EE02LZ2	 153	//( - , Baz2, SBz2DU) Исправность АКНП2
#define A0EE03LZ2	 BUFFER[375]	//( - , Baz2, SBz2DU) Исправность АКНП3
#define idA0EE03LZ2	 154	//( - , Baz2, SBz2DU) Исправность АКНП3
#define A1EE01LS2	 BUFFER[377]	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define idA1EE01LS2	 155	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define A0EE05LZ2	 BUFFER[379]	//( - , Baz2) Исправность сети АКНП1
#define idA0EE05LZ2	 156	//( - , Baz2) Исправность сети АКНП1
#define A0EE06LZ2	 BUFFER[381]	//( - , Baz2) Исправность сети АКНП2
#define idA0EE06LZ2	 157	//( - , Baz2) Исправность сети АКНП2
#define A0EE07LZ2	 BUFFER[383]	//( - , Baz2) Исправность сети АКНП3
#define idA0EE07LZ2	 158	//( - , Baz2) Исправность сети АКНП3
#define A0EE08LZ2	 BUFFER[385]	//( - , Baz2) Исправность сети АКНП4
#define idA0EE08LZ2	 159	//( - , Baz2) Исправность сети АКНП4
#define A0VZ71LZ2	 BUFFER[387]	//( - , Baz2) Обобщенный сигнал АС по АЗ1
#define idA0VZ71LZ2	 160	//( - , Baz2) Обобщенный сигнал АС по АЗ1
#define A0EE00LZ2	 BUFFER[389]	//( - , Baz2) Исправность АКНП АЗ1
#define idA0EE00LZ2	 161	//( - , Baz2) Исправность АКНП АЗ1
#define B0EE00LZ2	 BUFFER[391]	//( - , Baz2) Исправность АКНП АЗ2
#define idB0EE00LZ2	 162	//( - , Baz2) Исправность АКНП АЗ2
#define R0VN02RZ2	 BUFFER[393]	//( - , Baz2) Уровень мощности по каналу 2
#define idR0VN02RZ2	 163	//( - , Baz2) Уровень мощности по каналу 2
#define R0VN03RZ2	 BUFFER[398]	//( - , Baz2) Уровень мощности по каналу 3
#define idR0VN03RZ2	 164	//( - , Baz2) Уровень мощности по каналу 3
#define R0VN04RZ2	 BUFFER[403]	//( - , Baz2) Уровень мощности по каналу 4
#define idR0VN04RZ2	 165	//( - , Baz2) Уровень мощности по каналу 4
#define R0VN05RZ2	 BUFFER[408]	//( - , Baz2) Период разгона по каналу 1
#define idR0VN05RZ2	 166	//( - , Baz2) Период разгона по каналу 1
#define R0VN06RZ2	 BUFFER[413]	//( - , Baz2) Период разгона по каналу 2
#define idR0VN06RZ2	 167	//( - , Baz2) Период разгона по каналу 2
#define R0VN07RZ2	 BUFFER[418]	//( - , Baz2) Период разгона по каналу 3
#define idR0VN07RZ2	 168	//( - , Baz2) Период разгона по каналу 3
#define R0VN08RZ2	 BUFFER[423]	//( - , Baz2) Период разгона по каналу 4
#define idR0VN08RZ2	 169	//( - , Baz2) Период разгона по каналу 4
#define R0VN61LZ2	 BUFFER[428]	//( - , Baz2) ПС по мощности канал 1
#define idR0VN61LZ2	 170	//( - , Baz2) ПС по мощности канал 1
#define R0VN62LZ2	 BUFFER[430]	//( - , Baz2) ПС по мощности канал 2
#define idR0VN62LZ2	 171	//( - , Baz2) ПС по мощности канал 2
#define R0VN63LZ2	 BUFFER[432]	//( - , Baz2) ПС по мощности канал 3
#define idR0VN63LZ2	 172	//( - , Baz2) ПС по мощности канал 3
#define R0VN64LZ2	 BUFFER[434]	//( - , Baz2) ПС по мощности канал 4
#define idR0VN64LZ2	 173	//( - , Baz2) ПС по мощности канал 4
#define R0VN65LZ2	 BUFFER[436]	//( - , Baz2) ПС по периоду разгона канал 1
#define idR0VN65LZ2	 174	//( - , Baz2) ПС по периоду разгона канал 1
#define R0VN66LZ2	 BUFFER[438]	//( - , Baz2) ПС по периоду разгона канал 2
#define idR0VN66LZ2	 175	//( - , Baz2) ПС по периоду разгона канал 2
#define R0VN67LZ2	 BUFFER[440]	//( - , Baz2) ПС по периоду разгона канал 3
#define idR0VN67LZ2	 176	//( - , Baz2) ПС по периоду разгона канал 3
#define R0VN68LZ2	 BUFFER[442]	//( - , Baz2) ПС по периоду разгона канал 4
#define idR0VN68LZ2	 177	//( - , Baz2) ПС по периоду разгона канал 4
#define R0VN09RZ2	 BUFFER[444]	//( - , Baz2, SBz2DU) Усредненный период разгона
#define idR0VN09RZ2	 178	//( - , Baz2, SBz2DU) Усредненный период разгона
#define A3IS11LDU	 BUFFER[449]	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define idA3IS11LDU	 179	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define A3IS22LDU	 BUFFER[451]	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define idA3IS22LDU	 180	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define R0AD03LZ2	 BUFFER[453]	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define idR0AD03LZ2	 181	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define B3IS11LDU	 BUFFER[455]	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define idB3IS11LDU	 182	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define A3VZ31LZ2	 BUFFER[457]	//( - , Baz2) АЗ от ВУ ИС1
#define idA3VZ31LZ2	 183	//( - , Baz2) АЗ от ВУ ИС1
#define B3VZ31LZ2	 BUFFER[459]	//( - , Baz2) АЗ от ВУ ИС2
#define idB3VZ31LZ2	 184	//( - , Baz2) АЗ от ВУ ИС2
#define R0AD05LZ2	 BUFFER[461]	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define idR0AD05LZ2	 185	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define A3VZ11LZ2	 BUFFER[463]	//( - , Baz2) АЗ от НУП ИС1
#define idA3VZ11LZ2	 186	//( - , Baz2) АЗ от НУП ИС1
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
#define fEM_A1UL11RZZ	 BUFFER[560]	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС
#define idfEM_A1UL11RZZ	 206	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС
#define fEM_R7UI73RZZ	 BUFFER[565]	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define idfEM_R7UI73RZZ	 207	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define bFirstEnterFlag	 BUFFER[570]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 208	//(bFirstEnterFlag) 
#define internal1_m110_tx	 BUFFER[572]	//(internal1_m110_tx) tx - время накопленное сек
#define idinternal1_m110_tx	 209	//(internal1_m110_tx) tx - время накопленное сек
#define internal1_m110_y0	 BUFFER[577]	//(internal1_m110_y0) y0
#define idinternal1_m110_y0	 210	//(internal1_m110_y0) y0
#define internal1_m109_tx	 BUFFER[578]	//(internal1_m109_tx) tx - время накопленное сек
#define idinternal1_m109_tx	 211	//(internal1_m109_tx) tx - время накопленное сек
#define internal1_m109_y0	 BUFFER[583]	//(internal1_m109_y0) y0
#define idinternal1_m109_y0	 212	//(internal1_m109_y0) y0
#define internal1_m96_tx	 BUFFER[584]	//(internal1_m96_tx) tx - время накопленное сек
#define idinternal1_m96_tx	 213	//(internal1_m96_tx) tx - время накопленное сек
#define internal1_m96_y0	 BUFFER[589]	//(internal1_m96_y0) y0
#define idinternal1_m96_y0	 214	//(internal1_m96_y0) y0
#define internal1_m111_tx	 BUFFER[590]	//(internal1_m111_tx) tx - время накопленное сек
#define idinternal1_m111_tx	 215	//(internal1_m111_tx) tx - время накопленное сек
#define internal1_m111_y0	 BUFFER[595]	//(internal1_m111_y0) y0
#define idinternal1_m111_y0	 216	//(internal1_m111_y0) y0
#define internal1_m139_tx	 BUFFER[596]	//(internal1_m139_tx) tx - время накопленное сек
#define idinternal1_m139_tx	 217	//(internal1_m139_tx) tx - время накопленное сек
#define internal1_m139_y0	 BUFFER[601]	//(internal1_m139_y0) y0
#define idinternal1_m139_y0	 218	//(internal1_m139_y0) y0
#define internal1_m138_tx	 BUFFER[602]	//(internal1_m138_tx) tx - время накопленное сек
#define idinternal1_m138_tx	 219	//(internal1_m138_tx) tx - время накопленное сек
#define internal1_m138_y0	 BUFFER[607]	//(internal1_m138_y0) y0
#define idinternal1_m138_y0	 220	//(internal1_m138_y0) y0
#define internal1_m250_tx	 BUFFER[608]	//(internal1_m250_tx) tx - время накопленное сек
#define idinternal1_m250_tx	 221	//(internal1_m250_tx) tx - время накопленное сек
#define internal1_m250_y0	 BUFFER[613]	//(internal1_m250_y0) y0
#define idinternal1_m250_y0	 222	//(internal1_m250_y0) y0
#define internal1_m334_tx	 BUFFER[614]	//(internal1_m334_tx) tx - время накопленное сек
#define idinternal1_m334_tx	 223	//(internal1_m334_tx) tx - время накопленное сек
#define internal1_m334_y0	 BUFFER[619]	//(internal1_m334_y0) y0
#define idinternal1_m334_y0	 224	//(internal1_m334_y0) y0
#define internal1_m218_tx	 BUFFER[620]	//(internal1_m218_tx) tx - время накопленное сек
#define idinternal1_m218_tx	 225	//(internal1_m218_tx) tx - время накопленное сек
#define internal1_m218_y0	 BUFFER[625]	//(internal1_m218_y0) y0
#define idinternal1_m218_y0	 226	//(internal1_m218_y0) y0
#define internal1_m216_tx	 BUFFER[626]	//(internal1_m216_tx) tx - время накопленное сек
#define idinternal1_m216_tx	 227	//(internal1_m216_tx) tx - время накопленное сек
#define internal1_m216_y0	 BUFFER[631]	//(internal1_m216_y0) y0
#define idinternal1_m216_y0	 228	//(internal1_m216_y0) y0
#define internal1_m258_tx	 BUFFER[632]	//(internal1_m258_tx) tx - время накопленное сек
#define idinternal1_m258_tx	 229	//(internal1_m258_tx) tx - время накопленное сек
#define internal1_m258_y0	 BUFFER[637]	//(internal1_m258_y0) y0
#define idinternal1_m258_y0	 230	//(internal1_m258_y0) y0
#define internal1_m214_tx	 BUFFER[638]	//(internal1_m214_tx) tx - время накопленное сек
#define idinternal1_m214_tx	 231	//(internal1_m214_tx) tx - время накопленное сек
#define internal1_m214_y0	 BUFFER[643]	//(internal1_m214_y0) y0
#define idinternal1_m214_y0	 232	//(internal1_m214_y0) y0
#define internal1_m212_tx	 BUFFER[644]	//(internal1_m212_tx) tx - время накопленное сек
#define idinternal1_m212_tx	 233	//(internal1_m212_tx) tx - время накопленное сек
#define internal1_m212_y0	 BUFFER[649]	//(internal1_m212_y0) y0
#define idinternal1_m212_y0	 234	//(internal1_m212_y0) y0
#define internal1_m33_tx	 BUFFER[650]	//(internal1_m33_tx) tx - внутренний параметр
#define idinternal1_m33_tx	 235	//(internal1_m33_tx) tx - внутренний параметр
#define internal1_m149_y0	 BUFFER[653]	//(internal1_m149_y0) y0
#define idinternal1_m149_y0	 236	//(internal1_m149_y0) y0
#define internal1_m147_y0	 BUFFER[658]	//(internal1_m147_y0) y0
#define idinternal1_m147_y0	 237	//(internal1_m147_y0) y0
#define internal1_m91_y0	 BUFFER[663]	//(internal1_m91_y0) y0
#define idinternal1_m91_y0	 238	//(internal1_m91_y0) y0
#define internal1_m89_y0	 BUFFER[668]	//(internal1_m89_y0) y0
#define idinternal1_m89_y0	 239	//(internal1_m89_y0) y0
#define internal1_m160_y1	 BUFFER[673]	//(internal1_m160_y1) y1 - внутренний параметр
#define idinternal1_m160_y1	 240	//(internal1_m160_y1) y1 - внутренний параметр
#define internal1_m171_y1	 BUFFER[675]	//(internal1_m171_y1) y1 - внутренний параметр
#define idinternal1_m171_y1	 241	//(internal1_m171_y1) y1 - внутренний параметр
#define internal1_m320_q0	 BUFFER[677]	//(internal1_m320_q0) q0 - внутренний параметр
#define idinternal1_m320_q0	 242	//(internal1_m320_q0) q0 - внутренний параметр
#define internal1_m129_y0	 BUFFER[682]	//(internal1_m129_y0) state
#define idinternal1_m129_y0	 243	//(internal1_m129_y0) state
#define internal1_m123_y0	 BUFFER[684]	//(internal1_m123_y0) state
#define idinternal1_m123_y0	 244	//(internal1_m123_y0) state
#define internal1_m106_y1	 BUFFER[686]	//(internal1_m106_y1) y1 - внутренний параметр
#define idinternal1_m106_y1	 245	//(internal1_m106_y1) y1 - внутренний параметр
#define internal1_m119_y1	 BUFFER[688]	//(internal1_m119_y1) y1 - внутренний параметр
#define idinternal1_m119_y1	 246	//(internal1_m119_y1) y1 - внутренний параметр
#define internal1_m93_y1	 BUFFER[690]	//(internal1_m93_y1) y1 - внутренний параметр
#define idinternal1_m93_y1	 247	//(internal1_m93_y1) y1 - внутренний параметр
#define internal1_m104_y1	 BUFFER[692]	//(internal1_m104_y1) y1 - внутренний параметр
#define idinternal1_m104_y1	 248	//(internal1_m104_y1) y1 - внутренний параметр
#define internal1_m158_y1	 BUFFER[694]	//(internal1_m158_y1) y1 - внутренний параметр
#define idinternal1_m158_y1	 249	//(internal1_m158_y1) y1 - внутренний параметр
#define internal1_m167_y1	 BUFFER[696]	//(internal1_m167_y1) y1 - внутренний параметр
#define idinternal1_m167_y1	 250	//(internal1_m167_y1) y1 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &R0AD21LDU},	//( - , SBz2DU) Подключить защиту от II УР
	{ 2	,1	,1	, &R0MD34LP1},	//( - , Baz2) Кнопка Квитировать
	{ 3	,1	,1	, &R0AD14LDU},	//( - , Baz2) Имитация срабатывания верхней АС II УР
	{ 4	,1	,1	, &R0AD16LDU},	//( - , Baz2) Имитация срабатывания верхней АС I УР
	{ 5	,1	,1	, &R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 6	,1	,1	, &R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 7	,1	,1	, &R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
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
	{ 47	,1	,1	, &R0DE3CLZ2},	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 5
	{ 48	,1	,1	, &R0DE3DLZ2},	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 6
	{ 49	,1	,1	, &TestDiagnBaz2},	//( - , Baz2) Неисправность от
	{ 50	,3	,1	, &R0MW11IP1},	//( - , Baz2) Переключатель ВЫСТРЕЛ
	{ 51	,1	,1	, &PS9},	//( - , - ) АС 1 ур (д2)
	{ 52	,1	,1	, &PS1},	//( - , - ) давление АЗ1
	{ 53	,1	,1	, &PS2},	//( - , - ) АЗ от ВУ ИС1
	{ 54	,1	,1	, &PS3},	//( - , - ) АЗ от НУП ИС1
	{ 55	,1	,1	, &PS4},	//( - , - ) АЗ темп АЗ1
	{ 56	,1	,1	, &PS5},	//( - , - ) АС по Периоду АЗ1
	{ 57	,1	,1	, &PS6},	//( - , - ) АС по мощности АЗ1
	{ 58	,1	,1	, &PS7},	//( - , - ) Исправность акнп А32
	{ 59	,1	,1	, &PS8},	//( - , - ) Исправность акнп А31
	{ 60	,1	,1	, &PS10},	//( - , - ) АС 1 ур (д1)
	{ 61	,1	,1	, &PS11},	//( - , - ) АС 2 ур
	{ 62	,1	,1	, &PS16},	//( - , - ) АЗ от НУП ИС2
	{ 63	,1	,1	, &PS17},	//( - , - ) Аз по АС любого давления АЗ2
	{ 64	,1	,1	, &PS15},	//( - , - ) АЗ от ВУ ИС2
	{ 65	,1	,1	, &PS14},	//( - , - ) АС по температуре АЗ2
	{ 66	,1	,1	, &PS12},	//( - , - ) АС по мощности АЗ2
	{ 67	,1	,1	, &PS13},	//( - , - ) АС по периоду АЗ2
	{ 68	,5	,1	, &R0VZ05U},	//( - , - ) причины сброса
	{ 69	,8	,1	, &B8VC01RDU},	//( - , SBz2DU, MBz2A1, MBz2A2, MBz2A3, MBz2A4) Координата АЗ2, мм
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
	{ 93	,1	,1	, &R0DEB4LZ2},	//(sbk:20 - S13SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 6
	{ 94	,1	,1	, &A0VP81LZZ},	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
	{ 95	,1	,1	, &R0ET02LZ2},	//( - , Baz2) Признак наличия неисправности по температуре АЗ2
	{ 96	,3	,1	, &B0EP02IZ2},	//( - , Baz2) Индикатор -Давление  АЗ2 ниже АС
	{ 97	,3	,1	, &A0EP02IZ2},	//( - , Baz2) Индикатор -Давление  АЗ1 ниже АС
	{ 98	,1	,1	, &A0VP71LZ2},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
	{ 99	,1	,1	, &B0VP71LZ2},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
	{ 100	,8	,1	, &R0VN02RS1},	//( - , MBz2A1) Уровень мощности канал 1
	{ 101	,8	,1	, &R0VN02RS2},	//( - , MBz2A2) Уровень мощности канал 2
	{ 102	,8	,1	, &R0VN02RS3},	//( - , MBz2A3) Уровень мощности канал 3
	{ 103	,8	,1	, &R0VN02RS4},	//( - , MBz2A4) Уровень мощности канал 4
	{ 104	,8	,1	, &R0VN01RS1},	//( - , MBz2A1) Период разгона канал 1
	{ 105	,8	,1	, &R0VN01RS2},	//( - , MBz2A2) Период разгона канал 2
	{ 106	,8	,1	, &R0VN01RS3},	//( - , MBz2A3) Период разгона канал 3
	{ 107	,8	,1	, &R0VN01RS4},	//( - , MBz2A4) Период разгона канал 4
	{ 108	,1	,1	, &R0VN61LS1},	//( - , MBz2A1) ПС по мощности канал 1
	{ 109	,1	,1	, &R0VN61LS2},	//( - , MBz2A2) ПС по мощности канал 2
	{ 110	,1	,1	, &R0VN61LS3},	//( - , MBz2A3) ПС по мощности канал 3
	{ 111	,1	,1	, &R0VN61LS4},	//( - , MBz2A4) ПС по мощности канал 4
	{ 112	,1	,1	, &R0VN65LS1},	//( - , MBz2A1) ПС по периоду разгона канал 1
	{ 113	,1	,1	, &R0VN65LS2},	//( - , MBz2A2) ПС по периоду разгона  канал 2
	{ 114	,1	,1	, &R0VN65LS3},	//( - , MBz2A3) ПС по периоду разгона канал 3
	{ 115	,1	,1	, &R0VN65LS4},	//( - , MBz2A4) ПС по периоду разгона канал 4
	{ 116	,8	,1	, &R0VN01RZ2},	//( - , Baz2) Уровень мощности по каналу 1
	{ 117	,3	,1	, &A0IT02IZ2},	//(vas84:04 - K01VASR, - ) Температура АЗ1-2
	{ 118	,8	,1	, &A0CT01IZ2},	//( - , Baz2, SBz2DU) Температура АЗ1-1
	{ 119	,1	,1	, &A0VT61LZ2},	//( - , Baz2) ПС по температуре в АЗ1
	{ 120	,1	,1	, &A0VT71LZ2},	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
	{ 121	,1	,1	, &A1VP41LZ2},	//( - , Baz2, SBz2DU) Давление СБРОС ББ1 ниже АС
	{ 122	,1	,1	, &B1VP41LZ2},	//( - , Baz2, SBz2DU) Давление СБРОС ББ2 ниже АС
	{ 123	,1	,1	, &B1VP81LZZ},	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
	{ 124	,1	,1	, &A1VP81LZZ},	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
	{ 125	,1	,1	, &A2VP41LZ2},	//( - , Baz2) Давление СБРОС РБ1 ниже АС
	{ 126	,8	,1	, &A2CP01RZ2},	//( - , Baz2) Текущее давление СБРОС РБ1
	{ 127	,1	,1	, &A2VP51LZ2},	//( - , Baz2) Давление СБРОС РБ1 ниже ПС
	{ 128	,1	,1	, &B2VP41LZ2},	//( - , Baz2) Давление СБРОС РБ2 ниже АС
	{ 129	,8	,1	, &B2CP01RZ2},	//( - , Baz2) Текущее давление СБРОС РБ2
	{ 130	,1	,1	, &B2VP51LZ2},	//( - , Baz2) Давление СБРОС РБ2 ниже ПС
	{ 131	,1	,1	, &B2VP81LZ2},	//( - , Baz2) Давление СБРОС РБ2 в норме
	{ 132	,1	,1	, &A2VP81LZ2},	//( - , Baz2) Давление СБРОС РБ1 в норме
	{ 133	,3	,1	, &A2IP01IZ2},	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
	{ 134	,3	,1	, &B2IP01IZ2},	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
	{ 135	,1	,1	, &R0ET01LZ2},	//( - , Baz2) Признак наличия неисправности по температуре  АЗ1
	{ 136	,3	,1	, &B0IT02IZ2},	//(vas84:04 - K03VASR, - ) Температура АЗ2-2
	{ 137	,1	,1	, &A0VP41LZ2},	//( - , Baz2) Давление АЗ1 ниже АС
	{ 138	,1	,1	, &B0VP41LZ2},	//( - , Baz2) Давление АЗ2 ниже АС
	{ 139	,1	,1	, &B0VP81LZZ},	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
	{ 140	,1	,1	, &B3VZ11LZ2},	//( - , Baz2) АЗ от НУП ИС2
	{ 141	,1	,1	, &B3IS22LDU},	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
	{ 142	,1	,1	, &R0VN69LZ2},	//( - , Baz2) ПС по усредненному периоду
	{ 143	,1	,1	, &R0VN79LZ2},	//( - , Baz2) АС по усредненному периоду
	{ 144	,8	,1	, &R0VR02RZ2},	//( - , Baz2) Усредненная реактивность
	{ 145	,1	,1	, &R0VZ71LZ2},	//(fds16:0a - K05FDSR, Baz2) Обобщенный сигнал АЗ 2 канала
	{ 146	,1	,1	, &R0VN70LZ2},	//( - , Baz2) АЗ по АС мощности РУ
	{ 147	,1	,1	, &R0VN80LZ2},	//( - , Baz2) АЗ по АС периода разгона РУ
	{ 148	,1	,1	, &A1EE01LS1},	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
	{ 149	,1	,1	, &A1EE01LS4},	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
	{ 150	,1	,1	, &A1EE01LS3},	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
	{ 151	,1	,1	, &A0EE01LZ2},	//( - , Baz2, SBz2DU) Исправность АКНП1
	{ 152	,1	,1	, &A0EE04LZ2},	//( - , Baz2, SBz2DU) Исправность АКНП4
	{ 153	,1	,1	, &A0EE02LZ2},	//( - , Baz2, SBz2DU) Исправность АКНП2
	{ 154	,1	,1	, &A0EE03LZ2},	//( - , Baz2, SBz2DU) Исправность АКНП3
	{ 155	,1	,1	, &A1EE01LS2},	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
	{ 156	,1	,1	, &A0EE05LZ2},	//( - , Baz2) Исправность сети АКНП1
	{ 157	,1	,1	, &A0EE06LZ2},	//( - , Baz2) Исправность сети АКНП2
	{ 158	,1	,1	, &A0EE07LZ2},	//( - , Baz2) Исправность сети АКНП3
	{ 159	,1	,1	, &A0EE08LZ2},	//( - , Baz2) Исправность сети АКНП4
	{ 160	,1	,1	, &A0VZ71LZ2},	//( - , Baz2) Обобщенный сигнал АС по АЗ1
	{ 161	,1	,1	, &A0EE00LZ2},	//( - , Baz2) Исправность АКНП АЗ1
	{ 162	,1	,1	, &B0EE00LZ2},	//( - , Baz2) Исправность АКНП АЗ2
	{ 163	,8	,1	, &R0VN02RZ2},	//( - , Baz2) Уровень мощности по каналу 2
	{ 164	,8	,1	, &R0VN03RZ2},	//( - , Baz2) Уровень мощности по каналу 3
	{ 165	,8	,1	, &R0VN04RZ2},	//( - , Baz2) Уровень мощности по каналу 4
	{ 166	,8	,1	, &R0VN05RZ2},	//( - , Baz2) Период разгона по каналу 1
	{ 167	,8	,1	, &R0VN06RZ2},	//( - , Baz2) Период разгона по каналу 2
	{ 168	,8	,1	, &R0VN07RZ2},	//( - , Baz2) Период разгона по каналу 3
	{ 169	,8	,1	, &R0VN08RZ2},	//( - , Baz2) Период разгона по каналу 4
	{ 170	,1	,1	, &R0VN61LZ2},	//( - , Baz2) ПС по мощности канал 1
	{ 171	,1	,1	, &R0VN62LZ2},	//( - , Baz2) ПС по мощности канал 2
	{ 172	,1	,1	, &R0VN63LZ2},	//( - , Baz2) ПС по мощности канал 3
	{ 173	,1	,1	, &R0VN64LZ2},	//( - , Baz2) ПС по мощности канал 4
	{ 174	,1	,1	, &R0VN65LZ2},	//( - , Baz2) ПС по периоду разгона канал 1
	{ 175	,1	,1	, &R0VN66LZ2},	//( - , Baz2) ПС по периоду разгона канал 2
	{ 176	,1	,1	, &R0VN67LZ2},	//( - , Baz2) ПС по периоду разгона канал 3
	{ 177	,1	,1	, &R0VN68LZ2},	//( - , Baz2) ПС по периоду разгона канал 4
	{ 178	,8	,1	, &R0VN09RZ2},	//( - , Baz2, SBz2DU) Усредненный период разгона
	{ 179	,1	,1	, &A3IS11LDU},	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
	{ 180	,1	,1	, &A3IS22LDU},	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
	{ 181	,1	,1	, &R0AD03LZ2},	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
	{ 182	,1	,1	, &B3IS11LDU},	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
	{ 183	,1	,1	, &A3VZ31LZ2},	//( - , Baz2) АЗ от ВУ ИС1
	{ 184	,1	,1	, &B3VZ31LZ2},	//( - , Baz2) АЗ от ВУ ИС2
	{ 185	,1	,1	, &R0AD05LZ2},	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
	{ 186	,1	,1	, &A3VZ11LZ2},	//( - , Baz2) АЗ от НУП ИС1
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
	{ 206	,8	,1	, &fEM_A1UL11RZZ},	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС
	{ 207	,8	,1	, &fEM_R7UI73RZZ},	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
	{ 208	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 209	,8	,1	, &internal1_m110_tx},	//(internal1_m110_tx) tx - время накопленное сек
	{ 210	,18	,1	, &internal1_m110_y0},	//(internal1_m110_y0) y0
	{ 211	,8	,1	, &internal1_m109_tx},	//(internal1_m109_tx) tx - время накопленное сек
	{ 212	,18	,1	, &internal1_m109_y0},	//(internal1_m109_y0) y0
	{ 213	,8	,1	, &internal1_m96_tx},	//(internal1_m96_tx) tx - время накопленное сек
	{ 214	,18	,1	, &internal1_m96_y0},	//(internal1_m96_y0) y0
	{ 215	,8	,1	, &internal1_m111_tx},	//(internal1_m111_tx) tx - время накопленное сек
	{ 216	,18	,1	, &internal1_m111_y0},	//(internal1_m111_y0) y0
	{ 217	,8	,1	, &internal1_m139_tx},	//(internal1_m139_tx) tx - время накопленное сек
	{ 218	,18	,1	, &internal1_m139_y0},	//(internal1_m139_y0) y0
	{ 219	,8	,1	, &internal1_m138_tx},	//(internal1_m138_tx) tx - время накопленное сек
	{ 220	,18	,1	, &internal1_m138_y0},	//(internal1_m138_y0) y0
	{ 221	,8	,1	, &internal1_m250_tx},	//(internal1_m250_tx) tx - время накопленное сек
	{ 222	,18	,1	, &internal1_m250_y0},	//(internal1_m250_y0) y0
	{ 223	,8	,1	, &internal1_m334_tx},	//(internal1_m334_tx) tx - время накопленное сек
	{ 224	,18	,1	, &internal1_m334_y0},	//(internal1_m334_y0) y0
	{ 225	,8	,1	, &internal1_m218_tx},	//(internal1_m218_tx) tx - время накопленное сек
	{ 226	,18	,1	, &internal1_m218_y0},	//(internal1_m218_y0) y0
	{ 227	,8	,1	, &internal1_m216_tx},	//(internal1_m216_tx) tx - время накопленное сек
	{ 228	,18	,1	, &internal1_m216_y0},	//(internal1_m216_y0) y0
	{ 229	,8	,1	, &internal1_m258_tx},	//(internal1_m258_tx) tx - время накопленное сек
	{ 230	,18	,1	, &internal1_m258_y0},	//(internal1_m258_y0) y0
	{ 231	,8	,1	, &internal1_m214_tx},	//(internal1_m214_tx) tx - время накопленное сек
	{ 232	,18	,1	, &internal1_m214_y0},	//(internal1_m214_y0) y0
	{ 233	,8	,1	, &internal1_m212_tx},	//(internal1_m212_tx) tx - время накопленное сек
	{ 234	,18	,1	, &internal1_m212_y0},	//(internal1_m212_y0) y0
	{ 235	,3	,1	, &internal1_m33_tx},	//(internal1_m33_tx) tx - внутренний параметр
	{ 236	,8	,1	, &internal1_m149_y0},	//(internal1_m149_y0) y0
	{ 237	,8	,1	, &internal1_m147_y0},	//(internal1_m147_y0) y0
	{ 238	,8	,1	, &internal1_m91_y0},	//(internal1_m91_y0) y0
	{ 239	,8	,1	, &internal1_m89_y0},	//(internal1_m89_y0) y0
	{ 240	,1	,1	, &internal1_m160_y1},	//(internal1_m160_y1) y1 - внутренний параметр
	{ 241	,1	,1	, &internal1_m171_y1},	//(internal1_m171_y1) y1 - внутренний параметр
	{ 242	,5	,1	, &internal1_m320_q0},	//(internal1_m320_q0) q0 - внутренний параметр
	{ 243	,1	,1	, &internal1_m129_y0},	//(internal1_m129_y0) state
	{ 244	,1	,1	, &internal1_m123_y0},	//(internal1_m123_y0) state
	{ 245	,1	,1	, &internal1_m106_y1},	//(internal1_m106_y1) y1 - внутренний параметр
	{ 246	,1	,1	, &internal1_m119_y1},	//(internal1_m119_y1) y1 - внутренний параметр
	{ 247	,1	,1	, &internal1_m93_y1},	//(internal1_m93_y1) y1 - внутренний параметр
	{ 248	,1	,1	, &internal1_m104_y1},	//(internal1_m104_y1) y1 - внутренний параметр
	{ 249	,1	,1	, &internal1_m158_y1},	//(internal1_m158_y1) y1 - внутренний параметр
	{ 250	,1	,1	, &internal1_m167_y1},	//(internal1_m167_y1) y1 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="baz2.bin\0";   // Имя файла для сохранения констант
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
	{&B1VP41LZ2,1,42},	//( - , Baz2, SBz2DU) Давление СБРОС ББ2 ниже АС
	{&A1VP41LZ2,1,43},	//( - , Baz2, SBz2DU) Давление СБРОС ББ1 ниже АС
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
	{&R0VN09RZ2,8,4},	//( - , Baz2, SBz2DU) Усредненный период разгона
	{&A0CT01IZ2,8,6},	//( - , Baz2, SBz2DU) Температура АЗ1-1
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
	{&A0IT02IZ2,3,0},
	{&A2IP01IZ2,3,3},
	{&R0DE04LZ2,3,26},
	{&B2IP01IZ2,3,9},
	{&B0IT02IZ2,3,6},
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
	{&R0AD05LZ2,1,16},
	{&R0AD03LZ2,1,12},
	{&A3IS22LDU,1,10},
	{&A3IS11LDU,1,8},
	{&R0DE05LZ2,3,64},
	{&R0VN71LZ2,1,0},
	{&R0VN75LZ2,1,2},
	{&R0AD04LZ2,1,14},
	{&A2IS12LDU,1,18},
	{&A1EE01LS1,1,4},
	{&B2IS12LDU,1,20},
	{&A1VN71LS1,1,6},
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
	{&R0DE06LZ2,3,64},
	{&B3IS11LDU,1,8},
	{&A1EE01LS2,1,4},
	{&R0VN72LZ2,1,0},
	{&R0VN76LZ2,1,2},
	{&B3IS22LDU,1,10},
	{&A1VN71LS2,1,6},
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
	{&R0VN74LZ2,1,0},
	{&R0VN78LZ2,1,2},
	{&R0DE07LZ2,3,64},
	{&A1EE01LS4,1,4},
	{&A1VN71LS4,1,6},
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
	{&R7II73LZ2,1,12},
	{&B0VP81LZZ,1,22},
	{&A1VN71LS3,1,6},
	{&A1EE01LS3,1,4},
	{&R0DE08LZ2,3,64},
	{&A0VP81LZZ,1,16},
	{&B1VP81LZZ,1,24},
	{&R7II71LZ2,1,8},
	{&A1VP81LZZ,1,18},
	{&R7II72LZ2,1,10},
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
	setAsBool(5,1);
	setAsBool(6,1);
	setAsBool(7,1);
}
uspaint8 InternalBuf[141];

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
ssfloat fRM_10_ = {10,0}; /* tz - ����� �������� ��� */ 

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
ssbool var11;
ssbool var12;
ssint var13;
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
ssbool var138;
ssfloat var139;
ssfloat var140;
ssbool var141;
ssfloat var142;
ssfloat var143;
ssbool var144;
ssbool var145;
ssbool var146;
ssbool var147;
ssbool var148;
ssbool var149;
ssfloat var150;
sslong var151;
sslong var152;
ssbool var153;
ssbool var154;
ssbool var155;
ssbool var156;
ssbool var157;
ssbool var158;
ssbool var159;
ssbool var160;
ssbool var161;
ssfloat var162;
ssbool var163;
ssbool var164;
ssfloat var165;
ssbool var166;
ssbool var167;
sschar var168;
ssbool var169;
sschar var170;
ssbool var171;
ssbool var172;
ssbool var173;
ssbool var174;
ssbool var175;
ssbool var176;
ssbool var177;
ssbool var178;
ssbool var179;
ssbool var180;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* ���������� �������� */
psbool  array_m384_x_1[6] = {&R0DE36LZ2,&R0DE37LZ2,&R0DE38LZ2,&R0DE39LZ2,&var10,&var9};
psint  array_m371_x_1[6] = {&R0DE04LZ2,&R0DE05LZ2,&R0DE06LZ2,&R0DE0ALZ2,&R0DE08LZ2,&R0DE07LZ2};
psfloat  array_m190_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psfloat  array_m354_x_1[4] = {&R0VN02RS1,&R0VN02RS2,&R0VN02RS3,&R0VN02RS4};
psbool  array_m354_diag_1[4] = {&var18,&var19,&var20,&var21};
psbool  array_m327_x_1[17] = {&var89,&var50,&var51,&var100,&var32,&var43,&var167,&var52,&var59,&var60,&var98,&var36,&var42,&var169,&var56,&var57,&var58};
psbool  array_m16_x_1[6] = {&var93,&var98,&var42,&var36,&var111,&var169};
psbool  array_m36_x_1[6] = {&var100,&var32,&var43,&var167,&var91,&var111};
psfloat  array_m2_x_1[4] = {&R0VN01RS1,&R0VN01RS2,&R0VN01RS3,&R0VN01RS4};
psbool  array_m2_diag_1[4] = {&var18,&var19,&var20,&var21};
psbool  array_m3_x_1[3] = {&var118,&var149,&var22};
psbool  array_m12_x_1[3] = {&var117,&var25,&var119};

/* ���������� �������� */
_S_zzfs  S_zzfs_110_1 = {&B1VP81LZZ,&fRM_10000_,&var1,&internal1_m110_tx,&internal1_m110_y0};
_S_zzfs  S_zzfs_109_1 = {&A1VP81LZZ,&fRM_10000_,&var2,&internal1_m109_tx,&internal1_m109_y0};
_S_zzfs  S_zzfs_96_1 = {&var22,&fRM_10_,&var3,&internal1_m96_tx,&internal1_m96_y0};
_S_zzfs  S_zzfs_111_1 = {&var25,&fRM_10_,&var4,&internal1_m111_tx,&internal1_m111_y0};
_S_zzfs  S_zzfs_139_1 = {&B0VP81LZZ,&fRM_10000_,&var5,&internal1_m139_tx,&internal1_m139_y0};
_S_zzfs  S_zzfs_138_1 = {&A0VP81LZZ,&fRM_10000_,&var6,&internal1_m138_tx,&internal1_m138_y0};
_S_or3  S_or3_385_1 = {&var8,&var12,&var11,&var7};
_S_orn  S_orn_384_1 = {array_m384_x_1,&iRM_6_,&var8};
_S_or2  S_or2_391_1 = {&R0DEB3LZ2,&R0DEB4LZ2,&var9};
_S_or2  S_or2_382_1 = {&R0DEB1LZ2,&R0DEB2LZ2,&var10};
_S_and2  S_and2_373_1 = {&R0DE31LZ2,&R0DE32LZ2,&var11};
_S_diagndev  S_diagndev_371_1 = {array_m371_x_1,&iRM_6_,&var12,&var13};
_S_ma  S_ma_190_1 = {array_m190_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_and3  S_and3_213_1 = {&var113,&var112,&R0AD05LZ2,&var14};
_S_and3  S_and3_217_1 = {&var110,&var109,&R0AD03LZ2,&var15};
_S_and2  S_and2_257_1 = {&var41,&var134,&var16};
_S_zzfs  S_zzfs_250_1 = {&R0AD04LZ2,&fRM_1_0,&var17,&internal1_m250_tx,&internal1_m250_y0};
_S_and2  S_and2_80_1 = {&A0EE05LZ2,&A1EE01LS1,&var18};
_S_and2  S_and2_82_1 = {&A0EE06LZ2,&A1EE01LS2,&var19};
_S_and2  S_and2_84_1 = {&A0EE07LZ2,&A1EE01LS3,&var20};
_S_and2  S_and2_86_1 = {&A0EE08LZ2,&A1EE01LS4,&var21};
_S_or2  S_or2_103_1 = {&var178,&var176,&var22};
_S_and2  S_and2_135_1 = {&var171,&var147,&var23};
_S_and2  S_and2_128_1 = {&var148,&var172,&var24};
_S_or2  S_or2_107_1 = {&var173,&var174,&var25};
_S_or2  S_or2_205_1 = {&A3IS22LDU,&R0AD05LZ2,&var26};
_S_or2  S_or2_207_1 = {&B3IS22LDU,&R0AD05LZ2,&var27};
_S_or2  S_or2_208_1 = {&R0AD03LZ2,&var133,&var28};
_S_or2  S_or2_210_1 = {&var132,&R0AD03LZ2,&var29};
_S_and2  S_and2_219_1 = {&var113,&R0VW13LDU,&var30};
_S_and2  S_and2_221_1 = {&var112,&R0VW23LDU,&var31};
_S_or2  S_or2_234_1 = {&var33,&var34,&var32};
_S_and3  S_and3_235_1 = {&var128,&var31,&var30,&var33};
_S_and3  S_and3_230_1 = {&var30,&var137,&var128,&var34};
_S_and3  S_and3_231_1 = {&var31,&var138,&var128,&var35};
_S_or2  S_or2_236_1 = {&var35,&var33,&var36};
_S_or2  S_or2_249_1 = {&R7II72LZ2,&var114,&var37};
_S_or2  S_or2_255_1 = {&var115,&R7II71LZ2,&var38};
_S_or2  S_or2_261_1 = {&var116,&R7II73LZ2,&var39};
_S_or2  S_or2_263_1 = {&R0AD21LDU,&R0AD04LZ2,&var40};
_S_or3  S_or3_256_1 = {&var47,&var38,&var37,&var41};
_S_or2  S_or2_239_1 = {&var46,&var44,&var42};
_S_or2  S_or2_237_1 = {&var45,&var46,&var43};
_S_and3  S_and3_233_1 = {&var136,&var48,&var127,&var44};
_S_and3  S_and3_232_1 = {&var49,&var135,&var127,&var45};
_S_and3  S_and3_238_1 = {&var127,&var48,&var49,&var46};
_S_and2  S_and2_262_1 = {&var40,&var39,&var47};
_S_and2  S_and2_224_1 = {&var109,&R0VW23LDU,&var48};
_S_and2  S_and2_222_1 = {&var110,&R0VW13LDU,&var49};
_S_and2  S_and2_332_1 = {&var76,&var102,&var50};
_S_and2  S_and2_329_1 = {&var64,&var102,&var51};
_S_and2  S_and2_335_1 = {&var130,&var102,&var52};
_S_schl24  S_schl24_356_1 = {&A1VN71LS2,&A1VN71LS1,&A1VN71LS4,&A1VN71LS3,&var53};
_S_or2  S_or2_360_1 = {&var175,&var177,&var54};
_S_and2  S_and2_342_1 = {&var126,&var125,&var55};
_S_and2  S_and2_337_1 = {&var37,&var108,&var56};
_S_and2  S_and2_338_1 = {&var38,&var108,&var57};
_S_and2  S_and2_339_1 = {&var47,&var108,&var58};
_S_and2  S_and2_333_1 = {&var77,&var102,&var59};
_S_and2  S_and2_330_1 = {&var65,&var102,&var60};
_S_and2  S_and2_294_1 = {&var102,&var64,&var61};
_S_or2  S_or2_291_1 = {&var74,&var72,&var62};
_S_and2  S_and2_300_1 = {&var73,&var102,&var63};
_S_or2  S_or2_297_1 = {&var66,&var74,&var64};
_S_or2  S_or2_299_1 = {&var66,&var72,&var65};
_S_and2  S_and2_298_1 = {&var73,&var156,&var66};
_S_and2  S_and2_295_1 = {&var102,&var65,&var67};
_S_or2  S_or2_307_1 = {&R0VN76LZ2,&var159,&var68};
_S_or2  S_or2_308_1 = {&R0VN78LZ2,&var158,&var69};
_S_or2  S_or2_305_1 = {&R0VN75LZ2,&var161,&var70};
_S_or2  S_or2_306_1 = {&R0VN77LZ2,&var160,&var71};
_S_and2  S_and2_304_1 = {&var68,&var69,&var72};
_S_schl24  S_schl24_302_1 = {&var70,&var71,&var68,&var69,&var73};
_S_and2  S_and2_303_1 = {&var70,&var71,&var74};
_S_or2  S_or2_290_1 = {&var84,&var88,&var75};
_S_or2  S_or2_282_1 = {&var79,&var88,&var76};
_S_or2  S_or2_284_1 = {&var79,&var84,&var77};
_S_and2  S_and2_278_1 = {&var85,&var102,&var78};
_S_and2  S_and2_283_1 = {&var85,&var157,&var79};
_S_and2  S_and2_286_1 = {&var76,&var102,&var80};
_S_and2  S_and2_287_1 = {&var102,&var77,&var81};
_S_or2  S_or2_271_1 = {&R0VN72LZ2,&var159,&var82};
_S_or2  S_or2_272_1 = {&R0VN74LZ2,&var158,&var83};
_S_and2  S_and2_274_1 = {&var83,&var82,&var84};
_S_schl24  S_schl24_276_1 = {&var87,&var86,&var82,&var83,&var85};
_S_or2  S_or2_269_1 = {&R0VN71LZ2,&var161,&var86};
_S_or2  S_or2_270_1 = {&R0VN73LZ2,&var160,&var87};
_S_and2  S_and2_273_1 = {&var87,&var86,&var88};
_S_and2  S_and2_336_1 = {&var131,&var102,&var89};
_S_or3  S_or3_30_1 = {&var123,&var76,&var64,&var90};
_S_and2  S_and2_31_1 = {&var90,&var102,&var91};
_S_or2  S_or2_25_1 = {&var153,&var154,&var92};
_S_and2  S_and2_19_1 = {&var94,&var102,&var93};
_S_or3  S_or3_18_1 = {&var77,&var65,&var122,&var94};
_S_and2  S_and2_6_1 = {&var19,&var21,&var95};
_S_or2  S_or2_11_1 = {&var155,&var95,&var96};
_S_or2  S_or2_10_1 = {&var101,&var155,&var97};
_S_or2  S_or2_159_1 = {&var144,&var146,&var98};
_S_or2  S_or2_35_1 = {&B2IS12LDU,&A2IS12LDU,&var99};
_S_or2  S_or2_155_1 = {&var179,&var141,&var100};
_S_and2  S_and2_5_1 = {&var20,&var18,&var101};
_S_and2  S_and2_22_1 = {&var124,&var120,&var102};
_S_and2  S_and2_185_1 = {&var129,&var163,&var103};
_S_and2  S_and2_184_1 = {&var164,&var129,&var104};
_S_and2  S_and2_193_1 = {&R0AD04LZ2,&R7II72LZ2,&var105};
_S_and2  S_and2_191_1 = {&R0AD04LZ2,&R7II71LZ2,&var106};
_S_and2  S_and2_187_1 = {&R0AD04LZ2,&R7II73LZ2,&var107};
_S_zpfs  S_zpfs_334_1 = {&var55,&fRM_0_2,&var108,&internal1_m334_tx,&internal1_m334_y0};
_S_zpfs  S_zpfs_218_1 = {&var29,&fEM_A1UL11RZZ,&var109,&internal1_m218_tx,&internal1_m218_y0};
_S_zpfs  S_zpfs_216_1 = {&var28,&fEM_A1UL11RZZ,&var110,&internal1_m216_tx,&internal1_m216_y0};
_S_zpfs  S_zpfs_258_1 = {&var16,&fEM_R7UI73RZZ,&var111,&internal1_m258_tx,&internal1_m258_y0};
_S_zpfs  S_zpfs_214_1 = {&var27,&fEM_A1UL12RZZ,&var112,&internal1_m214_tx,&internal1_m214_y0};
_S_zpfs  S_zpfs_212_1 = {&var26,&fEM_A1UL12RZZ,&var113,&internal1_m212_tx,&internal1_m212_y0};
_S_noto  S_noto_242_1 = {&R6IS66LZZ,&var114};
_S_noto  S_noto_254_1 = {&R6IS67LZZ,&var115};
_S_noto  S_noto_260_1 = {&R6IS68LZZ,&var116};
_S_noto  S_noto_141_1 = {&var5,&var117};
_S_noto  S_noto_140_1 = {&var6,&var118};
_S_noto  S_noto_115_1 = {&var1,&var119};
_S_noto  S_noto_27_1 = {&var121,&var120};
_S_ovb1  S_ovb1_33_1 = {&var99,&iRM_200_,&var121,&internal1_m33_tx};
_S_noto  S_noto_14_1 = {&var96,&var122};
_S_noto  S_noto_13_1 = {&var97,&var123};
_S_noto  S_noto_24_1 = {&R0EE02LDU,&var124};
_S_noto  S_noto_345_1 = {&R0AD16LDU,&var125};
_S_noto  S_noto_344_1 = {&R0AD14LDU,&var126};
_S_noto  S_noto_223_1 = {&R0AD03LZ2,&var127};
_S_noto  S_noto_220_1 = {&R0AD05LZ2,&var128};
_S_bol  S_bol_180_1 = {&var165,&fRM_0_00001,&var129};
_S_noto  S_noto_340_1 = {&var96,&var130};
_S_noto  S_noto_341_1 = {&var97,&var131};
_S_noto  S_noto_204_1 = {&B3IS11LDU,&var132};
_S_noto  S_noto_203_1 = {&A3IS11LDU,&var133};
_S_noto  S_noto_251_1 = {&var17,&var134};
_S_noto  S_noto_228_1 = {&R0VW23LDU,&var135};
_S_noto  S_noto_227_1 = {&R0VW13LDU,&var136};
_S_noto  S_noto_226_1 = {&R0VW23LDU,&var137};
_S_noto  S_noto_225_1 = {&R0VW13LDU,&var138};
_S_scalzz  S_scalzz_149_1 = {&B0IT02IZ2,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var139,&internal1_m149_y0};
_S_scalzz  S_scalzz_147_1 = {&A0IT02IZ2,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var140,&internal1_m147_y0};
_S_geterr  S_geterr_151_1 = {&var140,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var141};
_S_scalzz  S_scalzz_91_1 = {&B2IP01IZ2,&iRM_3276_,&iRM_16383_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var142,&internal1_m91_y0};
_S_scalzz  S_scalzz_89_1 = {&A2IP01IZ2,&iRM_3276_,&iRM_16383_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var143,&internal1_m89_y0};
_S_drg  S_drg_160_1 = {&var139,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var144,&internal1_m160_y1};
_S_drg  S_drg_171_1 = {&var139,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var145,&internal1_m171_y1};
_S_geterr  S_geterr_153_1 = {&var139,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var146};
_S_noto  S_noto_136_1 = {&var173,&var147};
_S_noto  S_noto_127_1 = {&var178,&var148};
_S_noto  S_noto_114_1 = {&var2,&var149};
_S_srm  S_srm_354_1 = {array_m354_x_1,array_m354_diag_1,&iRM_4_,&iRM_3_,&var150,&vainSBool};
_S_rsu  S_rsu_320_1 = {&R0MD34LP1,&var152,&var151,&internal1_m320_q0};
_S_orni  S_orni_327_1 = {array_m327_x_1,&iRM_17_,&vainSBool,&var152};
_S_orn  S_orn_16_1 = {array_m16_x_1,&iRM_6_,&var153};
_S_orn  S_orn_36_1 = {array_m36_x_1,&iRM_6_,&var154};
_S_noto  S_noto_7_1 = {&var166,&var155};
_S_noto  S_noto_293_1 = {&var62,&var156};
_S_noto  S_noto_288_1 = {&var75,&var157};
_S_noto  S_noto_277_1 = {&A1EE01LS4,&var158};
_S_noto  S_noto_281_1 = {&A1EE01LS2,&var159};
_S_noto  S_noto_280_1 = {&A1EE01LS3,&var160};
_S_noto  S_noto_275_1 = {&A1EE01LS1,&var161};
_S_react  S_react_176_1 = {&var165,&var162};
_S_bol  S_bol_181_1 = {&fEM_R0UR04RZZ,&var165,&var163};
_S_bol  S_bol_179_1 = {&fEM_R0UR01RZZ,&var165,&var164};
_S_srm  S_srm_2_1 = {array_m2_x_1,array_m2_diag_1,&iRM_4_,&iRM_3_,&var165,&var166};
_S_ornc  S_ornc_3_1 = {array_m3_x_1,&iRM_3_,&var167,&var168};
_S_ornc  S_ornc_12_1 = {array_m12_x_1,&iRM_3_,&var169,&var170};
_S_tprg  S_tprg_129_1 = {&var142,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var171,&internal1_m129_y0};
_S_tprg  S_tprg_123_1 = {&var143,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var172,&internal1_m123_y0};
_S_geterr  S_geterr_99_1 = {&var142,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var173};
_S_drg  S_drg_106_1 = {&var142,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var174,&internal1_m106_y1};
_S_drg  S_drg_119_1 = {&var142,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var175,&internal1_m119_y1};
_S_drg  S_drg_93_1 = {&var143,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var176,&internal1_m93_y1};
_S_drg  S_drg_104_1 = {&var143,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var177,&internal1_m104_y1};
_S_geterr  S_geterr_95_1 = {&var143,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var178};
_S_drg  S_drg_158_1 = {&var140,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var179,&internal1_m158_y1};
_S_drg  S_drg_167_1 = {&var140,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var180,&internal1_m167_y1};


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
   var13.i=0;
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
   var137.b=0;
   var138.b=0;
   var139.f=0.0;
   var140.f=0.0;
   var141.b=0;
   var142.f=0.0;
   var143.f=0.0;
   var144.b=0;
   var145.b=0;
   var146.b=0;
   var147.b=0;
   var148.b=0;
   var149.b=0;
   var150.f=0.0;
   var151.l=0L;
   var152.l=0L;
   var153.b=0;
   var154.b=0;
   var155.b=0;
   var156.b=0;
   var157.b=0;
   var158.b=0;
   var159.b=0;
   var160.b=0;
   var161.b=0;
   var162.f=0.0;
   var163.b=0;
   var164.b=0;
   var165.f=0.0;
   var166.b=0;
   var167.b=0;
   var168.c=0;
   var169.b=0;
   var170.c=0;
   var171.b=0;
   var172.b=0;
   var173.b=0;
   var174.b=0;
   var175.b=0;
   var176.b=0;
   var177.b=0;
   var178.b=0;
   var179.b=0;
   var180.b=0;
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
  noto(&S_noto_275_1);
  noto(&S_noto_280_1);
  noto(&S_noto_281_1);
  noto(&S_noto_277_1);
  scalzz(&S_scalzz_89_1);
  scalzz(&S_scalzz_91_1);
  scalzz(&S_scalzz_147_1);
  scalzz(&S_scalzz_149_1);
  noto(&S_noto_226_1);
  noto(&S_noto_227_1);
  noto(&S_noto_228_1);
  noto(&S_noto_203_1);
  noto(&S_noto_204_1);
  noto(&S_noto_220_1);
  noto(&S_noto_223_1);
  noto(&S_noto_260_1);
  noto(&S_noto_254_1);
  noto(&S_noto_242_1);
  and2(&S_and2_187_1);
  and2(&S_and2_191_1);
  and2(&S_and2_193_1);
  or2(&S_or2_270_1);
  or2(&S_or2_269_1);
  or2(&S_or2_272_1);
  or2(&S_or2_271_1);
  or2(&S_or2_306_1);
  or2(&S_or2_305_1);
  or2(&S_or2_308_1);
  or2(&S_or2_307_1);
  schl24(&S_schl24_356_1);
  or2(&S_or2_263_1);
  or2(&S_or2_261_1);
  or2(&S_or2_255_1);
  or2(&S_or2_249_1);
  or2(&S_or2_210_1);
  or2(&S_or2_208_1);
  or2(&S_or2_207_1);
  or2(&S_or2_205_1);
  and2(&S_and2_86_1);
  and2(&S_and2_84_1);
  and2(&S_and2_82_1);
  and2(&S_and2_80_1);
  zzfs(&S_zzfs_250_1);
  ma(&S_ma_190_1);
  diagndev(&S_diagndev_371_1);
  and2(&S_and2_373_1);
  or2(&S_or2_382_1);
  or2(&S_or2_391_1);
  orn(&S_orn_384_1);
  or3(&S_or3_385_1);
  zzfs(&S_zzfs_138_1);
  zzfs(&S_zzfs_139_1);
  zzfs(&S_zzfs_109_1);
  zzfs(&S_zzfs_110_1);
  drg(&S_drg_167_1);
  drg(&S_drg_158_1);
  geterr(&S_geterr_95_1);
  drg(&S_drg_104_1);
  drg(&S_drg_93_1);
  drg(&S_drg_119_1);
  drg(&S_drg_106_1);
  geterr(&S_geterr_99_1);
  tprg(&S_tprg_123_1);
  tprg(&S_tprg_129_1);
  srm(&S_srm_2_1);
  bol(&S_bol_179_1);
  bol(&S_bol_181_1);
  react(&S_react_176_1);
  noto(&S_noto_7_1);
  srm(&S_srm_354_1);
  noto(&S_noto_114_1);
  noto(&S_noto_127_1);
  noto(&S_noto_136_1);
  geterr(&S_geterr_153_1);
  drg(&S_drg_171_1);
  drg(&S_drg_160_1);
  geterr(&S_geterr_151_1);
  noto(&S_noto_225_1);
  noto(&S_noto_251_1);
  bol(&S_bol_180_1);
  noto(&S_noto_344_1);
  noto(&S_noto_345_1);
  noto(&S_noto_24_1);
  noto(&S_noto_115_1);
  noto(&S_noto_140_1);
  noto(&S_noto_141_1);
  zpfs(&S_zpfs_212_1);
  zpfs(&S_zpfs_214_1);
  zpfs(&S_zpfs_216_1);
  zpfs(&S_zpfs_218_1);
  and2(&S_and2_184_1);
  and2(&S_and2_185_1);
  and2(&S_and2_5_1);
  or2(&S_or2_155_1);
  or2(&S_or2_35_1);
  or2(&S_or2_159_1);
  or2(&S_or2_10_1);
  and2(&S_and2_6_1);
  and2(&S_and2_273_1);
  schl24(&S_schl24_276_1);
  and2(&S_and2_274_1);
  or2(&S_or2_290_1);
  and2(&S_and2_303_1);
  schl24(&S_schl24_302_1);
  and2(&S_and2_304_1);
  or2(&S_or2_291_1);
  and2(&S_and2_342_1);
  or2(&S_or2_360_1);
  and2(&S_and2_222_1);
  and2(&S_and2_224_1);
  and2(&S_and2_262_1);
  and3(&S_and3_238_1);
  and3(&S_and3_232_1);
  and3(&S_and3_233_1);
  or2(&S_or2_237_1);
  or2(&S_or2_239_1);
  or3(&S_or3_256_1);
  and2(&S_and2_221_1);
  and2(&S_and2_219_1);
  or2(&S_or2_107_1);
  and2(&S_and2_128_1);
  and2(&S_and2_135_1);
  or2(&S_or2_103_1);
  and2(&S_and2_257_1);
  and3(&S_and3_217_1);
  and3(&S_and3_213_1);
  zzfs(&S_zzfs_111_1);
  zzfs(&S_zzfs_96_1);
  ornc(&S_ornc_12_1);
  ornc(&S_ornc_3_1);
  noto(&S_noto_288_1);
  noto(&S_noto_293_1);
  noto(&S_noto_341_1);
  noto(&S_noto_13_1);
  ovb1(&S_ovb1_33_1);
  noto(&S_noto_27_1);
  zpfs(&S_zpfs_258_1);
  zpfs(&S_zpfs_334_1);
  and2(&S_and2_22_1);
  or2(&S_or2_11_1);
  and2(&S_and2_336_1);
  and2(&S_and2_283_1);
  and2(&S_and2_278_1);
  or2(&S_or2_284_1);
  or2(&S_or2_282_1);
  and2(&S_and2_298_1);
  or2(&S_or2_299_1);
  or2(&S_or2_297_1);
  and2(&S_and2_300_1);
  and2(&S_and2_294_1);
  and2(&S_and2_330_1);
  and2(&S_and2_333_1);
  and2(&S_and2_339_1);
  and2(&S_and2_338_1);
  and2(&S_and2_337_1);
  and2(&S_and2_329_1);
  and2(&S_and2_332_1);
  and3(&S_and3_231_1);
  and3(&S_and3_230_1);
  and3(&S_and3_235_1);
  or2(&S_or2_234_1);
  noto(&S_noto_340_1);
  noto(&S_noto_14_1);
  or3(&S_or3_18_1);
  and2(&S_and2_19_1);
  or3(&S_or3_30_1);
  and2(&S_and2_287_1);
  and2(&S_and2_286_1);
  and2(&S_and2_295_1);
  and2(&S_and2_335_1);
  or2(&S_or2_236_1);
  orn(&S_orn_16_1);
  orni(&S_orni_327_1);
  rsu(&S_rsu_320_1);
  and2(&S_and2_31_1);
  orn(&S_orn_36_1);
  or2(&S_or2_25_1);
  setData(idR0VZ05U,&var152);
  setData(idPS13,&var65);
  setData(idPS12,&var77);
  setData(idPS14,&var98);
  setData(idPS15,&var42);
  setData(idPS17,&var169);
  setData(idPS16,&var36);
  setData(idPS11,&var47);
  setData(idPS10,&var38);
  setData(idPS8,&var97);
  setData(idPS7,&var96);
  setData(idPS6,&var76);
  setData(idPS5,&var64);
  setData(idPS4,&var100);
  setData(idPS3,&var32);
  setData(idPS2,&var43);
  setData(idPS1,&var167);
  setData(idPS9,&var37);
  setData(idTestDiagnBaz2,&var7);
  setData(idR0DE3DLZ2,&var9);
  setData(idR0DE3CLZ2,&var10);
  setData(idTTLBaz2,&var13);
  setData(idR0AD16LZ2,&var105);
  setData(idR0AD15LZ2,&var106);
  setData(idR0AD14LZ2,&var107);
  moveData(idR0EE04LZ2,idR0EE02LDU);
  moveData(idR0EE03LZ2,idR0EE02LDU);
  moveData(idR0EE02LZ2,idR0EE02LDU);
  moveData(idR0EE01LZ2,idR0EE02LDU);
  setData(idA3VZ13LZ2,&var15);
  setData(idA3VZ15LZ2,&var14);
  setData(idA1VN71LZ2,&var53);
  setData(idB0VT71LZ2,&var98);
  setData(idB0VT61LZ2,&var145);
  setData(idB0CT01IZ2,&var139);
  setData(idR0VP73LZ2,&var54);
  setData(idR0VN11RZ2,&var150);
  setData(idR0VZ05UZ2,&var151);
  setData(idB0VN81LZ2,&var67);
  setData(idA0VN81LZ2,&var61);
  setData(idB0VN71LZ2,&var81);
  setData(idA0VN71LZ2,&var80);
  setData(idB0VZ71LZ2,&var153);
  setData(idB0EE00LZ2,&var96);
  setData(idA0EE00LZ2,&var97);
  setData(idA0VZ71LZ2,&var154);
  setData(idA0EE03LZ2,&var20);
  setData(idA0EE02LZ2,&var19);
  setData(idA0EE04LZ2,&var21);
  setData(idA0EE01LZ2,&var18);
  setData(idR0VN80LZ2,&var63);
  setData(idR0VN70LZ2,&var78);
  setData(idR0VZ71LZ2,&var92);
  setData(idR0VR02RZ2,&var162);
  setData(idR0VN79LZ2,&var103);
  setData(idR0VN69LZ2,&var104);
  setData(idB3VZ11LZ2,&var36);
  setData(idA3VZ11LZ2,&var32);
  setData(idB3VZ31LZ2,&var42);
  setData(idA3VZ31LZ2,&var43);
  setData(idR0VN09RZ2,&var165);
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
  setData(idB0VP71LZ2,&var169);
  setData(idA0VP71LZ2,&var167);
  setData(idA0EP02IZ2,&var168);
  setData(idB0EP02IZ2,&var170);
  setData(idR0ET02LZ2,&var146);
  setData(idB0VP41LZ2,&var117);
  setData(idA0VP41LZ2,&var118);
  setData(idR0ET01LZ2,&var141);
  setData(idA2VP81LZ2,&var24);
  setData(idB2VP81LZ2,&var23);
  setData(idB2VP51LZ2,&var175);
  setData(idB2CP01RZ2,&var142);
  setData(idB2VP41LZ2,&var4);
  setData(idA2VP51LZ2,&var177);
  setData(idA2CP01RZ2,&var143);
  setData(idA2VP41LZ2,&var3);
  setData(idB1VP41LZ2,&var119);
  setData(idA1VP41LZ2,&var149);
  setData(idA0VT71LZ2,&var100);
  setData(idA0VT61LZ2,&var180);
  setData(idA0CT01IZ2,&var140);

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
