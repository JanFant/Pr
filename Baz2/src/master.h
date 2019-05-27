#ifndef BAZ2_H
#define BAZ2_H
// Подсистема Baz2:Baz2
static char SimulOn=0;
static short CodeSub=6;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=50;	 // Время цикла в ms
float takt, taktScheme=0, taktSS=0;
#define SIZE_BUFFER 713
static char BUFFER[713];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.54\0", 5432, "192.168.10.154\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0EE04LZ2	 BUFFER[0]	//( - , MBz2S) Питание  АКНП4  отключить
#define idR0EE04LZ2	 1	//( - , MBz2S) Питание  АКНП4  отключить
#define R0AD14LZ2	 BUFFER[2]	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define idR0AD14LZ2	 2	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define R0AD15LZ2	 BUFFER[4]	//( - , Baz2) Имитация АЗ от 1УР (датчик1)
#define idR0AD15LZ2	 3	//( - , Baz2) Имитация АЗ от 1УР (датчик1)
#define R0AD16LZ2	 BUFFER[6]	//( - , Baz2) Имитация АЗ от 1УР (датчик2)
#define idR0AD16LZ2	 4	//( - , Baz2) Имитация АЗ от 1УР (датчик2)
#define R0MW12IP2	 BUFFER[8]	//( - , Baz2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define idR0MW12IP2	 5	//( - , Baz2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define A2IS12LDU	 BUFFER[11]	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	 6	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define B2IS12LDU	 BUFFER[13]	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	 7	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define R0EE02LDU	 BUFFER[15]	//( - , Baz2) Питание  АКНП  отключить
#define idR0EE02LDU	 8	//( - , Baz2) Питание  АКНП  отключить
#define R0DE04LZ2	 BUFFER[17]	//(vas84:04 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 4 месте
#define idR0DE04LZ2	 9	//(vas84:04 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 4 месте
#define R0DE05LZ2	 BUFFER[20]	//(vds32:05 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 5 месте
#define idR0DE05LZ2	 10	//(vds32:05 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 5 месте
#define R0DE06LZ2	 BUFFER[23]	//(vds32:06 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 6 месте
#define idR0DE06LZ2	 11	//(vds32:06 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 6 месте
#define R0DE07LZ2	 BUFFER[26]	//(vds32:07 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 7 месте
#define idR0DE07LZ2	 12	//(vds32:07 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 7 месте
#define R0DE0ALZ2	 BUFFER[29]	//(fds16:0a - Diagn, DiagnBaz2) диагностика модуля Баз2 на 10 месте
#define idR0DE0ALZ2	 13	//(fds16:0a - Diagn, DiagnBaz2) диагностика модуля Баз2 на 10 месте
#define R0DE31LZ2	 BUFFER[32]	//(sbk:20 - S01SBK, DiagnBaz2) диагностика шкафа Баз2 сеть 1
#define idR0DE31LZ2	 14	//(sbk:20 - S01SBK, DiagnBaz2) диагностика шкафа Баз2 сеть 1
#define R0DE08LZ2	 BUFFER[34]	//(vds32:08 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 8 месте
#define idR0DE08LZ2	 15	//(vds32:08 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 8 месте
#define TTLBaz2	 BUFFER[37]	//( - , Baz2) ttl
#define idTTLBaz2	 16	//( - , Baz2) ttl
#define R0DE32LZ2	 BUFFER[40]	//(sbk:20 - S02SBK, DiagnBaz2) диагностика шкафа Баз2 сеть 2
#define idR0DE32LZ2	 17	//(sbk:20 - S02SBK, DiagnBaz2) диагностика шкафа Баз2 сеть 2
#define R0DE33LZ2	 BUFFER[42]	//(sbk:20 - S03SBK, DiagnBaz2) диагностика шкафа Баз2 двери
#define idR0DE33LZ2	 18	//(sbk:20 - S03SBK, DiagnBaz2) диагностика шкафа Баз2 двери
#define R0DE34LZ2	 BUFFER[44]	//(sbk:20 - S04SBK, DiagnBaz2) диагностика шкафа Баз2 температура меньше 43
#define idR0DE34LZ2	 19	//(sbk:20 - S04SBK, DiagnBaz2) диагностика шкафа Баз2 температура меньше 43
#define R0DE35LZ2	 BUFFER[46]	//(sbk:20 - S05SBK, DiagnBaz2) диагностика шкафа Баз2 температура больше 53
#define idR0DE35LZ2	 20	//(sbk:20 - S05SBK, DiagnBaz2) диагностика шкафа Баз2 температура больше 53
#define R0DE38LZ2	 BUFFER[48]	//(sbk:20 - S08SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3 место 3
#define idR0DE38LZ2	 21	//(sbk:20 - S08SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3 место 3
#define R0DE37LZ2	 BUFFER[50]	//(sbk:20 - S07SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3.1 место 2
#define idR0DE37LZ2	 22	//(sbk:20 - S07SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3.1 место 2
#define R0DE39LZ2	 BUFFER[52]	//(sbk:20 - S09SBK, DiagnBaz2) диагностика шкафа Баз2 МП24-2 место 4
#define idR0DE39LZ2	 23	//(sbk:20 - S09SBK, DiagnBaz2) диагностика шкафа Баз2 МП24-2 место 4
#define B0CT01IZ2	 BUFFER[54]	//( - , Baz2, SBz2DU) Температура АЗ2-1
#define idB0CT01IZ2	 24	//( - , Baz2, SBz2DU) Температура АЗ2-1
#define B0VT61LZ2	 BUFFER[59]	//( - , Baz2) ПС по температуре в АЗ2
#define idB0VT61LZ2	 25	//( - , Baz2) ПС по температуре в АЗ2
#define B0VT71LZ2	 BUFFER[61]	//( - , Baz2, SBz2DU) АС по температуре в АЗ2
#define idB0VT71LZ2	 26	//( - , Baz2, SBz2DU) АС по температуре в АЗ2
#define A1VN71LS1	 BUFFER[63]	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
#define idA1VN71LS1	 27	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
#define A1VN71LS2	 BUFFER[65]	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
#define idA1VN71LS2	 28	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
#define A1VN71LS3	 BUFFER[67]	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
#define idA1VN71LS3	 29	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
#define A1VN71LS4	 BUFFER[69]	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
#define idA1VN71LS4	 30	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
#define A1VN71LZ2	 BUFFER[71]	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
#define idA1VN71LZ2	 31	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
#define A3VZ13LZ2	 BUFFER[73]	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
#define idA3VZ13LZ2	 32	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
#define R0MD34LP1	 BUFFER[75]	//( - , Baz2) Кнопка Квитировать
#define idR0MD34LP1	 33	//( - , Baz2) Кнопка Квитировать
#define R0AD14LDU	 BUFFER[77]	//( - , Baz2) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 34	//( - , Baz2) Имитация срабатывания верхней АС II УР
#define R0AD16LDU	 BUFFER[79]	//( - , Baz2) Имитация срабатывания верхней АС I УР
#define idR0AD16LDU	 35	//( - , Baz2) Имитация срабатывания верхней АС I УР
#define R0VN71LZ2	 BUFFER[81]	//(vds32:05 - K01VDSR, Baz2) АС по мощности канал 1
#define idR0VN71LZ2	 36	//(vds32:05 - K01VDSR, Baz2) АС по мощности канал 1
#define R0VN75LZ2	 BUFFER[83]	//(vds32:05 - K02VDSR, Baz2) АС по периоду разгона канал 1
#define idR0VN75LZ2	 37	//(vds32:05 - K02VDSR, Baz2) АС по периоду разгона канал 1
#define R0VN72LZ2	 BUFFER[85]	//(vds32:06 - K01VDSR, Baz2) АС по мощности канал 2
#define idR0VN72LZ2	 38	//(vds32:06 - K01VDSR, Baz2) АС по мощности канал 2
#define R0VN76LZ2	 BUFFER[87]	//(vds32:06 - K02VDSR, Baz2) АС по периоду разгона канал  2
#define idR0VN76LZ2	 39	//(vds32:06 - K02VDSR, Baz2) АС по периоду разгона канал  2
#define R0VN73LZ2	 BUFFER[89]	//(vds32:08 - K01VDSR, Baz2) АС по мощности канал 3
#define idR0VN73LZ2	 40	//(vds32:08 - K01VDSR, Baz2) АС по мощности канал 3
#define R0VN74LZ2	 BUFFER[91]	//(vds32:07 - K01VDSR, Baz2) АС по мощности канал 4
#define idR0VN74LZ2	 41	//(vds32:07 - K01VDSR, Baz2) АС по мощности канал 4
#define R0VN77LZ2	 BUFFER[93]	//(vds32:08 - K02VDSR, Baz2) АС по периоду разгона канал  3
#define idR0VN77LZ2	 42	//(vds32:08 - K02VDSR, Baz2) АС по периоду разгона канал  3
#define R0VN78LZ2	 BUFFER[95]	//(vds32:07 - K02VDSR, Baz2) АС по периоду разгона канал  4
#define idR0VN78LZ2	 43	//(vds32:07 - K02VDSR, Baz2) АС по периоду разгона канал  4
#define R0EE01LZ2	 BUFFER[97]	//( - , MBz2S) Питание  АКНП1  отключить
#define idR0EE01LZ2	 44	//( - , MBz2S) Питание  АКНП1  отключить
#define R0EE02LZ2	 BUFFER[99]	//( - , MBz2S) Питание  АКНП2  отключить
#define idR0EE02LZ2	 45	//( - , MBz2S) Питание  АКНП2  отключить
#define R0EE03LZ2	 BUFFER[101]	//( - , MBz2S) Питание  АКНП3  отключить
#define idR0EE03LZ2	 46	//( - , MBz2S) Питание  АКНП3  отключить
#define PS12	 BUFFER[103]	//( - , - ) АС по мощности АЗ2
#define idPS12	 47	//( - , - ) АС по мощности АЗ2
#define PS13	 BUFFER[105]	//( - , - ) АС по периоду АЗ2
#define idPS13	 48	//( - , - ) АС по периоду АЗ2
#define R0VZ05U	 BUFFER[107]	//( - , - ) причины сброса
#define idR0VZ05U	 49	//( - , - ) причины сброса
#define B8VC01RDU	 BUFFER[112]	//( - , SBz2DU, MBz2A1, MBz2A2, MBz2A3, MBz2A4) Координата АЗ2, мм
#define idB8VC01RDU	 50	//( - , SBz2DU, MBz2A1, MBz2A2, MBz2A3, MBz2A4) Координата АЗ2, мм
#define A3IS11LDU	 BUFFER[117]	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define idA3IS11LDU	 51	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define A3IS22LDU	 BUFFER[119]	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define idA3IS22LDU	 52	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define R0AD03LZ1	 BUFFER[121]	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define idR0AD03LZ1	 53	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define A3VZ31LZ1	 BUFFER[123]	//( - , Baz1) АЗ от ВУ ИС1
#define idA3VZ31LZ1	 54	//( - , Baz1) АЗ от ВУ ИС1
#define B3VZ31LZ1	 BUFFER[125]	//( - , Baz1) АЗ от ВУ ИС2
#define idB3VZ31LZ1	 55	//( - , Baz1) АЗ от ВУ ИС2
#define R0AD05LZ1	 BUFFER[127]	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define idR0AD05LZ1	 56	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define A3VZ11LZ1	 BUFFER[129]	//( - , Baz1) АЗ от НУП ИС1
#define idA3VZ11LZ1	 57	//( - , Baz1) АЗ от НУП ИС1
#define B3VZ11LZ1	 BUFFER[131]	//( - , Baz1) АЗ от НУП ИС2
#define idB3VZ11LZ1	 58	//( - , Baz1) АЗ от НУП ИС2
#define B3IS22LDU	 BUFFER[133]	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
#define idB3IS22LDU	 59	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
#define A3VZ15LZ1	 BUFFER[135]	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
#define idA3VZ15LZ1	 60	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
#define A3VZ13LZ1	 BUFFER[137]	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
#define idA3VZ13LZ1	 61	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
#define R7II73LZ1	 BUFFER[139]	//(vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
#define idR7II73LZ1	 62	//(vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
#define R7II71LZ1	 BUFFER[141]	//(vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
#define idR7II71LZ1	 63	//(vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
#define R7II72LZ1	 BUFFER[143]	//(vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
#define idR7II72LZ1	 64	//(vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
#define R0AD14LZ1	 BUFFER[145]	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define idR0AD14LZ1	 65	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define R0AD21LDU	 BUFFER[147]	//( - , SBz2DU) Подключить защиту от II УР
#define idR0AD21LDU	 66	//( - , SBz2DU) Подключить защиту от II УР
#define R6IS66LZZ	 BUFFER[149]	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 67	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[151]	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 68	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[153]	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 69	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define R0DE36LZ2	 BUFFER[155]	//(sbk:20 - S06SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3.1 место 1
#define idR0DE36LZ2	 70	//(sbk:20 - S06SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3.1 место 1
#define R0DEB1LZ2	 BUFFER[157]	//(sbk:20 - S10SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 5
#define idR0DEB1LZ2	 71	//(sbk:20 - S10SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 5
#define R0DEB2LZ2	 BUFFER[159]	//(sbk:20 - S11SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 5
#define idR0DEB2LZ2	 72	//(sbk:20 - S11SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 5
#define R0DEB3LZ2	 BUFFER[161]	//(sbk:20 - S12SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 6
#define idR0DEB3LZ2	 73	//(sbk:20 - S12SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 6
#define R0DEB4LZ2	 BUFFER[163]	//(sbk:20 - S13SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 6
#define idR0DEB4LZ2	 74	//(sbk:20 - S13SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 6
#define R0DE3CLZ2	 BUFFER[165]	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 5
#define idR0DE3CLZ2	 75	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 5
#define R0DE3DLZ2	 BUFFER[167]	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 6
#define idR0DE3DLZ2	 76	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 6
#define TestDiagnBaz2	 BUFFER[169]	//( - , Baz2) Неисправность от
#define idTestDiagnBaz2	 77	//( - , Baz2) Неисправность от
#define R0MW11IP1	 BUFFER[171]	//( - , Baz2) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 78	//( - , Baz2) Переключатель ВЫСТРЕЛ
#define PS9	 BUFFER[174]	//( - , - ) АС 1 ур (д2)
#define idPS9	 79	//( - , - ) АС 1 ур (д2)
#define PS1	 BUFFER[176]	//( - , - ) давление АЗ1
#define idPS1	 80	//( - , - ) давление АЗ1
#define PS2	 BUFFER[178]	//( - , - ) АЗ от ВУ ИС1
#define idPS2	 81	//( - , - ) АЗ от ВУ ИС1
#define PS3	 BUFFER[180]	//( - , - ) АЗ от НУП ИС1
#define idPS3	 82	//( - , - ) АЗ от НУП ИС1
#define PS4	 BUFFER[182]	//( - , - ) АЗ темп АЗ1
#define idPS4	 83	//( - , - ) АЗ темп АЗ1
#define PS5	 BUFFER[184]	//( - , - ) АС по Периоду АЗ1
#define idPS5	 84	//( - , - ) АС по Периоду АЗ1
#define PS6	 BUFFER[186]	//( - , - ) АС по мощности АЗ1
#define idPS6	 85	//( - , - ) АС по мощности АЗ1
#define PS7	 BUFFER[188]	//( - , - ) Исправность акнп А32
#define idPS7	 86	//( - , - ) Исправность акнп А32
#define PS8	 BUFFER[190]	//( - , - ) Исправность акнп А31
#define idPS8	 87	//( - , - ) Исправность акнп А31
#define PS10	 BUFFER[192]	//( - , - ) АС 1 ур (д1)
#define idPS10	 88	//( - , - ) АС 1 ур (д1)
#define PS11	 BUFFER[194]	//( - , - ) АС 2 ур
#define idPS11	 89	//( - , - ) АС 2 ур
#define PS16	 BUFFER[196]	//( - , - ) АЗ от НУП ИС2
#define idPS16	 90	//( - , - ) АЗ от НУП ИС2
#define PS17	 BUFFER[198]	//( - , - ) Аз по АС любого давления АЗ2
#define idPS17	 91	//( - , - ) Аз по АС любого давления АЗ2
#define PS15	 BUFFER[200]	//( - , - ) АЗ от ВУ ИС2
#define idPS15	 92	//( - , - ) АЗ от ВУ ИС2
#define PS14	 BUFFER[202]	//( - , - ) АС по температуре АЗ2
#define idPS14	 93	//( - , - ) АС по температуре АЗ2
#define A0VP81LZZ	 BUFFER[204]	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define idA0VP81LZZ	 94	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define R0ET02LZ2	 BUFFER[206]	//( - , Baz2) Признак наличия неисправности по температуре АЗ2
#define idR0ET02LZ2	 95	//( - , Baz2) Признак наличия неисправности по температуре АЗ2
#define B0EP02IZ2	 BUFFER[208]	//( - , Baz2) Индикатор -Давление  АЗ2 ниже АС
#define idB0EP02IZ2	 96	//( - , Baz2) Индикатор -Давление  АЗ2 ниже АС
#define A0EP02IZ2	 BUFFER[211]	//( - , Baz2) Индикатор -Давление  АЗ1 ниже АС
#define idA0EP02IZ2	 97	//( - , Baz2) Индикатор -Давление  АЗ1 ниже АС
#define A0VP71LZ2	 BUFFER[214]	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ2	 98	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
#define B0VP71LZ2	 BUFFER[216]	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ2	 99	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
#define R0VN02RS1	 BUFFER[218]	//( - , MBz2A1) Уровень мощности канал 1
#define idR0VN02RS1	 100	//( - , MBz2A1) Уровень мощности канал 1
#define R0VN02RS2	 BUFFER[223]	//( - , MBz2A2) Уровень мощности канал 2
#define idR0VN02RS2	 101	//( - , MBz2A2) Уровень мощности канал 2
#define R0VN02RS3	 BUFFER[228]	//( - , MBz2A3) Уровень мощности канал 3
#define idR0VN02RS3	 102	//( - , MBz2A3) Уровень мощности канал 3
#define R0VN02RS4	 BUFFER[233]	//( - , MBz2A4) Уровень мощности канал 4
#define idR0VN02RS4	 103	//( - , MBz2A4) Уровень мощности канал 4
#define R0VN01RS1	 BUFFER[238]	//( - , MBz2A1) Период разгона канал 1
#define idR0VN01RS1	 104	//( - , MBz2A1) Период разгона канал 1
#define R0VN01RS2	 BUFFER[243]	//( - , MBz2A2) Период разгона канал 2
#define idR0VN01RS2	 105	//( - , MBz2A2) Период разгона канал 2
#define R0VN01RS3	 BUFFER[248]	//( - , MBz2A3) Период разгона канал 3
#define idR0VN01RS3	 106	//( - , MBz2A3) Период разгона канал 3
#define R0VN01RS4	 BUFFER[253]	//( - , MBz2A4) Период разгона канал 4
#define idR0VN01RS4	 107	//( - , MBz2A4) Период разгона канал 4
#define R0VN61LS1	 BUFFER[258]	//( - , MBz2A1) ПС по мощности канал 1
#define idR0VN61LS1	 108	//( - , MBz2A1) ПС по мощности канал 1
#define R0VN61LS2	 BUFFER[260]	//( - , MBz2A2) ПС по мощности канал 2
#define idR0VN61LS2	 109	//( - , MBz2A2) ПС по мощности канал 2
#define R0VN61LS3	 BUFFER[262]	//( - , MBz2A3) ПС по мощности канал 3
#define idR0VN61LS3	 110	//( - , MBz2A3) ПС по мощности канал 3
#define R0VN61LS4	 BUFFER[264]	//( - , MBz2A4) ПС по мощности канал 4
#define idR0VN61LS4	 111	//( - , MBz2A4) ПС по мощности канал 4
#define R0VN65LS1	 BUFFER[266]	//( - , MBz2A1) ПС по периоду разгона канал 1
#define idR0VN65LS1	 112	//( - , MBz2A1) ПС по периоду разгона канал 1
#define R0VN65LS2	 BUFFER[268]	//( - , MBz2A2) ПС по периоду разгона  канал 2
#define idR0VN65LS2	 113	//( - , MBz2A2) ПС по периоду разгона  канал 2
#define R0VN65LS3	 BUFFER[270]	//( - , MBz2A3) ПС по периоду разгона канал 3
#define idR0VN65LS3	 114	//( - , MBz2A3) ПС по периоду разгона канал 3
#define R0VN65LS4	 BUFFER[272]	//( - , MBz2A4) ПС по периоду разгона канал 4
#define idR0VN65LS4	 115	//( - , MBz2A4) ПС по периоду разгона канал 4
#define R0VN01RZ2	 BUFFER[274]	//( - , Baz2) Уровень мощности по каналу 1
#define idR0VN01RZ2	 116	//( - , Baz2) Уровень мощности по каналу 1
#define A0IT02IZ2	 BUFFER[279]	//(vas84:04 - K01VASR, - ) Температура АЗ1-2
#define idA0IT02IZ2	 117	//(vas84:04 - K01VASR, - ) Температура АЗ1-2
#define A0CT01IZ2	 BUFFER[282]	//( - , Baz2, SBz2DU) Температура АЗ1-1
#define idA0CT01IZ2	 118	//( - , Baz2, SBz2DU) Температура АЗ1-1
#define A0VT61LZ2	 BUFFER[287]	//( - , Baz2) ПС по температуре в АЗ1
#define idA0VT61LZ2	 119	//( - , Baz2) ПС по температуре в АЗ1
#define A0VT71LZ2	 BUFFER[289]	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
#define idA0VT71LZ2	 120	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
#define A1VP41LZ2	 BUFFER[291]	//( - , Baz2, SBz2DU) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ2	 121	//( - , Baz2, SBz2DU) Давление СБРОС ББ1 ниже АС
#define B1VP41LZ2	 BUFFER[293]	//( - , Baz2, SBz2DU) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ2	 122	//( - , Baz2, SBz2DU) Давление СБРОС ББ2 ниже АС
#define B1VP81LZZ	 BUFFER[295]	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	 123	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define A1VP81LZZ	 BUFFER[297]	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	 124	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define A2VP41LZ2	 BUFFER[299]	//( - , Baz2) Давление СБРОС РБ1 ниже АС
#define idA2VP41LZ2	 125	//( - , Baz2) Давление СБРОС РБ1 ниже АС
#define A2CP01RZ2	 BUFFER[301]	//( - , Baz2) Текущее давление СБРОС РБ1
#define idA2CP01RZ2	 126	//( - , Baz2) Текущее давление СБРОС РБ1
#define A2VP51LZ2	 BUFFER[306]	//( - , Baz2) Давление СБРОС РБ1 ниже ПС
#define idA2VP51LZ2	 127	//( - , Baz2) Давление СБРОС РБ1 ниже ПС
#define B2VP41LZ2	 BUFFER[308]	//( - , Baz2) Давление СБРОС РБ2 ниже АС
#define idB2VP41LZ2	 128	//( - , Baz2) Давление СБРОС РБ2 ниже АС
#define B2CP01RZ2	 BUFFER[310]	//( - , Baz2) Текущее давление СБРОС РБ2
#define idB2CP01RZ2	 129	//( - , Baz2) Текущее давление СБРОС РБ2
#define B2VP51LZ2	 BUFFER[315]	//( - , Baz2) Давление СБРОС РБ2 ниже ПС
#define idB2VP51LZ2	 130	//( - , Baz2) Давление СБРОС РБ2 ниже ПС
#define B2VP81LZ2	 BUFFER[317]	//( - , Baz2) Давление СБРОС РБ2 в норме
#define idB2VP81LZ2	 131	//( - , Baz2) Давление СБРОС РБ2 в норме
#define A2VP81LZ2	 BUFFER[319]	//( - , Baz2) Давление СБРОС РБ1 в норме
#define idA2VP81LZ2	 132	//( - , Baz2) Давление СБРОС РБ1 в норме
#define A2IP01IZ2	 BUFFER[321]	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ2	 133	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define B2IP01IZ2	 BUFFER[324]	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ2	 134	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define R0ET01LZ2	 BUFFER[327]	//( - , Baz2) Признак наличия неисправности по температуре  АЗ1
#define idR0ET01LZ2	 135	//( - , Baz2) Признак наличия неисправности по температуре  АЗ1
#define B0IT02IZ2	 BUFFER[329]	//(vas84:04 - K03VASR, - ) Температура АЗ2-2
#define idB0IT02IZ2	 136	//(vas84:04 - K03VASR, - ) Температура АЗ2-2
#define A0VP41LZ2	 BUFFER[332]	//( - , Baz2) Давление АЗ1 ниже АС
#define idA0VP41LZ2	 137	//( - , Baz2) Давление АЗ1 ниже АС
#define B0VP41LZ2	 BUFFER[334]	//( - , Baz2) Давление АЗ2 ниже АС
#define idB0VP41LZ2	 138	//( - , Baz2) Давление АЗ2 ниже АС
#define B0VP81LZZ	 BUFFER[336]	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	 139	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define A1EE01LS1	 BUFFER[338]	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define idA1EE01LS1	 140	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define A1EE01LS4	 BUFFER[340]	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define idA1EE01LS4	 141	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define A1EE01LS3	 BUFFER[342]	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define idA1EE01LS3	 142	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define A0EE01LZ2	 BUFFER[344]	//( - , Baz2, SBz2DU) Исправность АКНП1
#define idA0EE01LZ2	 143	//( - , Baz2, SBz2DU) Исправность АКНП1
#define A0EE04LZ2	 BUFFER[346]	//( - , Baz2, SBz2DU) Исправность АКНП4
#define idA0EE04LZ2	 144	//( - , Baz2, SBz2DU) Исправность АКНП4
#define A0EE02LZ2	 BUFFER[348]	//( - , Baz2, SBz2DU) Исправность АКНП2
#define idA0EE02LZ2	 145	//( - , Baz2, SBz2DU) Исправность АКНП2
#define A0EE03LZ2	 BUFFER[350]	//( - , Baz2, SBz2DU) Исправность АКНП3
#define idA0EE03LZ2	 146	//( - , Baz2, SBz2DU) Исправность АКНП3
#define A1EE01LS2	 BUFFER[352]	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define idA1EE01LS2	 147	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define A0EE05LZ2	 BUFFER[354]	//( - , Baz2) Исправность сети АКНП1
#define idA0EE05LZ2	 148	//( - , Baz2) Исправность сети АКНП1
#define A0EE06LZ2	 BUFFER[356]	//( - , Baz2) Исправность сети АКНП2
#define idA0EE06LZ2	 149	//( - , Baz2) Исправность сети АКНП2
#define A0EE07LZ2	 BUFFER[358]	//( - , Baz2) Исправность сети АКНП3
#define idA0EE07LZ2	 150	//( - , Baz2) Исправность сети АКНП3
#define A0EE08LZ2	 BUFFER[360]	//( - , Baz2) Исправность сети АКНП4
#define idA0EE08LZ2	 151	//( - , Baz2) Исправность сети АКНП4
#define A0VZ71LZ2	 BUFFER[362]	//( - , Baz2) Обобщенный сигнал АС по АЗ1
#define idA0VZ71LZ2	 152	//( - , Baz2) Обобщенный сигнал АС по АЗ1
#define A0EE00LZ2	 BUFFER[364]	//( - , Baz2) Исправность АКНП АЗ1
#define idA0EE00LZ2	 153	//( - , Baz2) Исправность АКНП АЗ1
#define B0EE00LZ2	 BUFFER[366]	//( - , Baz2) Исправность АКНП АЗ2
#define idB0EE00LZ2	 154	//( - , Baz2) Исправность АКНП АЗ2
#define B0VZ71LZ2	 BUFFER[368]	//( - , Baz2) Обобщенный сигнал АС по АЗ2
#define idB0VZ71LZ2	 155	//( - , Baz2) Обобщенный сигнал АС по АЗ2
#define A0VN71LZ2	 BUFFER[370]	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ1
#define idA0VN71LZ2	 156	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ1
#define B0VN71LZ2	 BUFFER[372]	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ2
#define idB0VN71LZ2	 157	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ2
#define A0VN81LZ2	 BUFFER[374]	//( - , Baz2) АЗ по АС периода разгона АЗ1
#define idA0VN81LZ2	 158	//( - , Baz2) АЗ по АС периода разгона АЗ1
#define B0VN81LZ2	 BUFFER[376]	//( - , Baz2) АЗ по АС периода разгона АЗ2
#define idB0VN81LZ2	 159	//( - , Baz2) АЗ по АС периода разгона АЗ2
#define R0VZ05UZ2	 BUFFER[378]	//( - , Baz2) Индикатор причины сброса
#define idR0VZ05UZ2	 160	//( - , Baz2) Индикатор причины сброса
#define R0VN11RZ2	 BUFFER[383]	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ1
#define idR0VN11RZ2	 161	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ1
#define R0VP73LZ2	 BUFFER[388]	//( - , Baz2, SBz2DU) ПС давления для РУ
#define idR0VP73LZ2	 162	//( - , Baz2, SBz2DU) ПС давления для РУ
#define R0VN02RZ2	 BUFFER[390]	//( - , Baz2) Уровень мощности по каналу 2
#define idR0VN02RZ2	 163	//( - , Baz2) Уровень мощности по каналу 2
#define R0VN03RZ2	 BUFFER[395]	//( - , Baz2) Уровень мощности по каналу 3
#define idR0VN03RZ2	 164	//( - , Baz2) Уровень мощности по каналу 3
#define R0VN04RZ2	 BUFFER[400]	//( - , Baz2) Уровень мощности по каналу 4
#define idR0VN04RZ2	 165	//( - , Baz2) Уровень мощности по каналу 4
#define R0VN05RZ2	 BUFFER[405]	//( - , Baz2) Период разгона по каналу 1
#define idR0VN05RZ2	 166	//( - , Baz2) Период разгона по каналу 1
#define R0VN06RZ2	 BUFFER[410]	//( - , Baz2) Период разгона по каналу 2
#define idR0VN06RZ2	 167	//( - , Baz2) Период разгона по каналу 2
#define R0VN07RZ2	 BUFFER[415]	//( - , Baz2) Период разгона по каналу 3
#define idR0VN07RZ2	 168	//( - , Baz2) Период разгона по каналу 3
#define R0VN08RZ2	 BUFFER[420]	//( - , Baz2) Период разгона по каналу 4
#define idR0VN08RZ2	 169	//( - , Baz2) Период разгона по каналу 4
#define R0VN61LZ2	 BUFFER[425]	//( - , Baz2) ПС по мощности канал 1
#define idR0VN61LZ2	 170	//( - , Baz2) ПС по мощности канал 1
#define R0VN62LZ2	 BUFFER[427]	//( - , Baz2) ПС по мощности канал 2
#define idR0VN62LZ2	 171	//( - , Baz2) ПС по мощности канал 2
#define R0VN63LZ2	 BUFFER[429]	//( - , Baz2) ПС по мощности канал 3
#define idR0VN63LZ2	 172	//( - , Baz2) ПС по мощности канал 3
#define R0VN64LZ2	 BUFFER[431]	//( - , Baz2) ПС по мощности канал 4
#define idR0VN64LZ2	 173	//( - , Baz2) ПС по мощности канал 4
#define R0VN65LZ2	 BUFFER[433]	//( - , Baz2) ПС по периоду разгона канал 1
#define idR0VN65LZ2	 174	//( - , Baz2) ПС по периоду разгона канал 1
#define R0VN66LZ2	 BUFFER[435]	//( - , Baz2) ПС по периоду разгона канал 2
#define idR0VN66LZ2	 175	//( - , Baz2) ПС по периоду разгона канал 2
#define R0VN67LZ2	 BUFFER[437]	//( - , Baz2) ПС по периоду разгона канал 3
#define idR0VN67LZ2	 176	//( - , Baz2) ПС по периоду разгона канал 3
#define R0VN68LZ2	 BUFFER[439]	//( - , Baz2) ПС по периоду разгона канал 4
#define idR0VN68LZ2	 177	//( - , Baz2) ПС по периоду разгона канал 4
#define R0VN09RZ2	 BUFFER[441]	//( - , Baz2) Усредненный период разгона
#define idR0VN09RZ2	 178	//( - , Baz2) Усредненный период разгона
#define R0AD03LZ2	 BUFFER[446]	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define idR0AD03LZ2	 179	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define B3IS11LDU	 BUFFER[448]	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define idB3IS11LDU	 180	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define R0VN69LZ2	 BUFFER[450]	//( - , Baz2) ПС по усредненному периоду
#define idR0VN69LZ2	 181	//( - , Baz2) ПС по усредненному периоду
#define R0VN79LZ2	 BUFFER[452]	//( - , Baz2) АС по усредненному периоду
#define idR0VN79LZ2	 182	//( - , Baz2) АС по усредненному периоду
#define R0VR02RZ2	 BUFFER[454]	//( - , Baz2) Усредненная реактивность
#define idR0VR02RZ2	 183	//( - , Baz2) Усредненная реактивность
#define R0VZ71LZ2	 BUFFER[459]	//(fds16:0a - K05FDSR, Baz2) Обобщенный сигнал АЗ 2 канала
#define idR0VZ71LZ2	 184	//(fds16:0a - K05FDSR, Baz2) Обобщенный сигнал АЗ 2 канала
#define R0VN70LZ2	 BUFFER[461]	//( - , Baz2) АЗ по АС мощности РУ
#define idR0VN70LZ2	 185	//( - , Baz2) АЗ по АС мощности РУ
#define R0VN80LZ2	 BUFFER[463]	//( - , Baz2) АЗ по АС периода разгона РУ
#define idR0VN80LZ2	 186	//( - , Baz2) АЗ по АС периода разгона РУ
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
#define fEM_A1UL12RZZ	 BUFFER[555]	//(A1UL12RZZ) Время задержки АЗ от НУП ИС(сек)
#define idfEM_A1UL12RZZ	 205	//(A1UL12RZZ) Время задержки АЗ от НУП ИС(сек)
#define fEM_A1UL11RZZ	 BUFFER[560]	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
#define idfEM_A1UL11RZZ	 206	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
#define fEM_R7UI73RZZ	 BUFFER[565]	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define idfEM_R7UI73RZZ	 207	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define fEM_A1UL13RZZ	 BUFFER[570]	//(A1UL13RZZ) Максимальное время цикла
#define idfEM_A1UL13RZZ	 208	//(A1UL13RZZ) Максимальное время цикла
#define bFirstEnterFlag	 BUFFER[575]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 209	//(bFirstEnterFlag) 
#define internal1_m211_TVuIs1	 BUFFER[577]	//(internal1_m211_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
#define idinternal1_m211_TVuIs1	 210	//(internal1_m211_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
#define internal1_m211_TVuIs2	 BUFFER[582]	//(internal1_m211_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
#define idinternal1_m211_TVuIs2	 211	//(internal1_m211_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
#define internal1_m211_TImVuIs	 BUFFER[587]	//(internal1_m211_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
#define idinternal1_m211_TImVuIs	 212	//(internal1_m211_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
#define internal1_m211_TNupIs1	 BUFFER[592]	//(internal1_m211_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
#define idinternal1_m211_TNupIs1	 213	//(internal1_m211_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
#define internal1_m211_TNupIs2	 BUFFER[597]	//(internal1_m211_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
#define idinternal1_m211_TNupIs2	 214	//(internal1_m211_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
#define internal1_m211_TImNupIs	 BUFFER[602]	//(internal1_m211_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
#define idinternal1_m211_TImNupIs	 215	//(internal1_m211_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
#define internal1_m211_TImAZ2UR	 BUFFER[607]	//(internal1_m211_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
#define idinternal1_m211_TImAZ2UR	 216	//(internal1_m211_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
#define internal1_m211_fef	 BUFFER[612]	//(internal1_m211_fef) fef
#define idinternal1_m211_fef	 217	//(internal1_m211_fef) fef
#define internal1_m231_tx	 BUFFER[614]	//(internal1_m231_tx) tx - время накопленное сек
#define idinternal1_m231_tx	 218	//(internal1_m231_tx) tx - время накопленное сек
#define internal1_m231_y0	 BUFFER[619]	//(internal1_m231_y0) y0
#define idinternal1_m231_y0	 219	//(internal1_m231_y0) y0
#define internal1_m111_tx	 BUFFER[620]	//(internal1_m111_tx) tx - время накопленное сек
#define idinternal1_m111_tx	 220	//(internal1_m111_tx) tx - время накопленное сек
#define internal1_m111_y0	 BUFFER[625]	//(internal1_m111_y0) y0
#define idinternal1_m111_y0	 221	//(internal1_m111_y0) y0
#define internal1_m110_tx	 BUFFER[626]	//(internal1_m110_tx) tx - время накопленное сек
#define idinternal1_m110_tx	 222	//(internal1_m110_tx) tx - время накопленное сек
#define internal1_m110_y0	 BUFFER[631]	//(internal1_m110_y0) y0
#define idinternal1_m110_y0	 223	//(internal1_m110_y0) y0
#define internal1_m98_tx	 BUFFER[632]	//(internal1_m98_tx) tx - время накопленное сек
#define idinternal1_m98_tx	 224	//(internal1_m98_tx) tx - время накопленное сек
#define internal1_m98_y0	 BUFFER[637]	//(internal1_m98_y0) y0
#define idinternal1_m98_y0	 225	//(internal1_m98_y0) y0
#define internal1_m112_tx	 BUFFER[638]	//(internal1_m112_tx) tx - время накопленное сек
#define idinternal1_m112_tx	 226	//(internal1_m112_tx) tx - время накопленное сек
#define internal1_m112_y0	 BUFFER[643]	//(internal1_m112_y0) y0
#define idinternal1_m112_y0	 227	//(internal1_m112_y0) y0
#define internal1_m140_tx	 BUFFER[644]	//(internal1_m140_tx) tx - время накопленное сек
#define idinternal1_m140_tx	 228	//(internal1_m140_tx) tx - время накопленное сек
#define internal1_m140_y0	 BUFFER[649]	//(internal1_m140_y0) y0
#define idinternal1_m140_y0	 229	//(internal1_m140_y0) y0
#define internal1_m139_tx	 BUFFER[650]	//(internal1_m139_tx) tx - время накопленное сек
#define idinternal1_m139_tx	 230	//(internal1_m139_tx) tx - время накопленное сек
#define internal1_m139_y0	 BUFFER[655]	//(internal1_m139_y0) y0
#define idinternal1_m139_y0	 231	//(internal1_m139_y0) y0
#define internal1_m340_sttlf	 BUFFER[656]	//(internal1_m340_sttlf) sttlf - счетчик для вещественного формата
#define idinternal1_m340_sttlf	 232	//(internal1_m340_sttlf) sttlf - счетчик для вещественного формата
#define internal1_m303_tx	 BUFFER[659]	//(internal1_m303_tx) tx - время накопленное сек
#define idinternal1_m303_tx	 233	//(internal1_m303_tx) tx - время накопленное сек
#define internal1_m303_y0	 BUFFER[664]	//(internal1_m303_y0) y0
#define idinternal1_m303_y0	 234	//(internal1_m303_y0) y0
#define internal1_m33_tx	 BUFFER[665]	//(internal1_m33_tx) tx - внутренний параметр
#define idinternal1_m33_tx	 235	//(internal1_m33_tx) tx - внутренний параметр
#define internal1_m150_y0	 BUFFER[668]	//(internal1_m150_y0) y0
#define idinternal1_m150_y0	 236	//(internal1_m150_y0) y0
#define internal1_m148_y0	 BUFFER[673]	//(internal1_m148_y0) y0
#define idinternal1_m148_y0	 237	//(internal1_m148_y0) y0
#define internal1_m92_y0	 BUFFER[678]	//(internal1_m92_y0) y0
#define idinternal1_m92_y0	 238	//(internal1_m92_y0) y0
#define internal1_m90_y0	 BUFFER[683]	//(internal1_m90_y0) y0
#define idinternal1_m90_y0	 239	//(internal1_m90_y0) y0
#define internal1_m161_y1	 BUFFER[688]	//(internal1_m161_y1) y1 - внутренний параметр
#define idinternal1_m161_y1	 240	//(internal1_m161_y1) y1 - внутренний параметр
#define internal1_m172_y1	 BUFFER[690]	//(internal1_m172_y1) y1 - внутренний параметр
#define idinternal1_m172_y1	 241	//(internal1_m172_y1) y1 - внутренний параметр
#define internal1_m289_q0	 BUFFER[692]	//(internal1_m289_q0) q0 - внутренний параметр
#define idinternal1_m289_q0	 242	//(internal1_m289_q0) q0 - внутренний параметр
#define internal1_m130_y0	 BUFFER[697]	//(internal1_m130_y0) state
#define idinternal1_m130_y0	 243	//(internal1_m130_y0) state
#define internal1_m124_y0	 BUFFER[699]	//(internal1_m124_y0) state
#define idinternal1_m124_y0	 244	//(internal1_m124_y0) state
#define internal1_m107_y1	 BUFFER[701]	//(internal1_m107_y1) y1 - внутренний параметр
#define idinternal1_m107_y1	 245	//(internal1_m107_y1) y1 - внутренний параметр
#define internal1_m123_y1	 BUFFER[703]	//(internal1_m123_y1) y1 - внутренний параметр
#define idinternal1_m123_y1	 246	//(internal1_m123_y1) y1 - внутренний параметр
#define internal1_m94_y1	 BUFFER[705]	//(internal1_m94_y1) y1 - внутренний параметр
#define idinternal1_m94_y1	 247	//(internal1_m94_y1) y1 - внутренний параметр
#define internal1_m105_y1	 BUFFER[707]	//(internal1_m105_y1) y1 - внутренний параметр
#define idinternal1_m105_y1	 248	//(internal1_m105_y1) y1 - внутренний параметр
#define internal1_m158_y1	 BUFFER[709]	//(internal1_m158_y1) y1 - внутренний параметр
#define idinternal1_m158_y1	 249	//(internal1_m158_y1) y1 - внутренний параметр
#define internal1_m169_y1	 BUFFER[711]	//(internal1_m169_y1) y1 - внутренний параметр
#define idinternal1_m169_y1	 250	//(internal1_m169_y1) y1 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &R0EE04LZ2},	//( - , MBz2S) Питание  АКНП4  отключить
	{ 2	,1	,1	, &R0AD14LZ2},	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
	{ 3	,1	,1	, &R0AD15LZ2},	//( - , Baz2) Имитация АЗ от 1УР (датчик1)
	{ 4	,1	,1	, &R0AD16LZ2},	//( - , Baz2) Имитация АЗ от 1УР (датчик2)
	{ 5	,3	,1	, &R0MW12IP2},	//( - , Baz2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{ 6	,1	,1	, &A2IS12LDU},	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
	{ 7	,1	,1	, &B2IS12LDU},	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
	{ 8	,1	,1	, &R0EE02LDU},	//( - , Baz2) Питание  АКНП  отключить
	{ 9	,3	,1	, &R0DE04LZ2},	//(vas84:04 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 4 месте
	{ 10	,3	,1	, &R0DE05LZ2},	//(vds32:05 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 5 месте
	{ 11	,3	,1	, &R0DE06LZ2},	//(vds32:06 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 6 месте
	{ 12	,3	,1	, &R0DE07LZ2},	//(vds32:07 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 7 месте
	{ 13	,3	,1	, &R0DE0ALZ2},	//(fds16:0a - Diagn, DiagnBaz2) диагностика модуля Баз2 на 10 месте
	{ 14	,1	,1	, &R0DE31LZ2},	//(sbk:20 - S01SBK, DiagnBaz2) диагностика шкафа Баз2 сеть 1
	{ 15	,3	,1	, &R0DE08LZ2},	//(vds32:08 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 8 месте
	{ 16	,3	,1	, &TTLBaz2},	//( - , Baz2) ttl
	{ 17	,1	,1	, &R0DE32LZ2},	//(sbk:20 - S02SBK, DiagnBaz2) диагностика шкафа Баз2 сеть 2
	{ 18	,1	,1	, &R0DE33LZ2},	//(sbk:20 - S03SBK, DiagnBaz2) диагностика шкафа Баз2 двери
	{ 19	,1	,1	, &R0DE34LZ2},	//(sbk:20 - S04SBK, DiagnBaz2) диагностика шкафа Баз2 температура меньше 43
	{ 20	,1	,1	, &R0DE35LZ2},	//(sbk:20 - S05SBK, DiagnBaz2) диагностика шкафа Баз2 температура больше 53
	{ 21	,1	,1	, &R0DE38LZ2},	//(sbk:20 - S08SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3 место 3
	{ 22	,1	,1	, &R0DE37LZ2},	//(sbk:20 - S07SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3.1 место 2
	{ 23	,1	,1	, &R0DE39LZ2},	//(sbk:20 - S09SBK, DiagnBaz2) диагностика шкафа Баз2 МП24-2 место 4
	{ 24	,8	,1	, &B0CT01IZ2},	//( - , Baz2, SBz2DU) Температура АЗ2-1
	{ 25	,1	,1	, &B0VT61LZ2},	//( - , Baz2) ПС по температуре в АЗ2
	{ 26	,1	,1	, &B0VT71LZ2},	//( - , Baz2, SBz2DU) АС по температуре в АЗ2
	{ 27	,1	,1	, &A1VN71LS1},	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
	{ 28	,1	,1	, &A1VN71LS2},	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
	{ 29	,1	,1	, &A1VN71LS3},	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
	{ 30	,1	,1	, &A1VN71LS4},	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
	{ 31	,1	,1	, &A1VN71LZ2},	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
	{ 32	,1	,1	, &A3VZ13LZ2},	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
	{ 33	,1	,1	, &R0MD34LP1},	//( - , Baz2) Кнопка Квитировать
	{ 34	,1	,1	, &R0AD14LDU},	//( - , Baz2) Имитация срабатывания верхней АС II УР
	{ 35	,1	,1	, &R0AD16LDU},	//( - , Baz2) Имитация срабатывания верхней АС I УР
	{ 36	,1	,1	, &R0VN71LZ2},	//(vds32:05 - K01VDSR, Baz2) АС по мощности канал 1
	{ 37	,1	,1	, &R0VN75LZ2},	//(vds32:05 - K02VDSR, Baz2) АС по периоду разгона канал 1
	{ 38	,1	,1	, &R0VN72LZ2},	//(vds32:06 - K01VDSR, Baz2) АС по мощности канал 2
	{ 39	,1	,1	, &R0VN76LZ2},	//(vds32:06 - K02VDSR, Baz2) АС по периоду разгона канал  2
	{ 40	,1	,1	, &R0VN73LZ2},	//(vds32:08 - K01VDSR, Baz2) АС по мощности канал 3
	{ 41	,1	,1	, &R0VN74LZ2},	//(vds32:07 - K01VDSR, Baz2) АС по мощности канал 4
	{ 42	,1	,1	, &R0VN77LZ2},	//(vds32:08 - K02VDSR, Baz2) АС по периоду разгона канал  3
	{ 43	,1	,1	, &R0VN78LZ2},	//(vds32:07 - K02VDSR, Baz2) АС по периоду разгона канал  4
	{ 44	,1	,1	, &R0EE01LZ2},	//( - , MBz2S) Питание  АКНП1  отключить
	{ 45	,1	,1	, &R0EE02LZ2},	//( - , MBz2S) Питание  АКНП2  отключить
	{ 46	,1	,1	, &R0EE03LZ2},	//( - , MBz2S) Питание  АКНП3  отключить
	{ 47	,1	,1	, &PS12},	//( - , - ) АС по мощности АЗ2
	{ 48	,1	,1	, &PS13},	//( - , - ) АС по периоду АЗ2
	{ 49	,5	,1	, &R0VZ05U},	//( - , - ) причины сброса
	{ 50	,8	,1	, &B8VC01RDU},	//( - , SBz2DU, MBz2A1, MBz2A2, MBz2A3, MBz2A4) Координата АЗ2, мм
	{ 51	,1	,1	, &A3IS11LDU},	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
	{ 52	,1	,1	, &A3IS22LDU},	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
	{ 53	,1	,1	, &R0AD03LZ1},	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
	{ 54	,1	,1	, &A3VZ31LZ1},	//( - , Baz1) АЗ от ВУ ИС1
	{ 55	,1	,1	, &B3VZ31LZ1},	//( - , Baz1) АЗ от ВУ ИС2
	{ 56	,1	,1	, &R0AD05LZ1},	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
	{ 57	,1	,1	, &A3VZ11LZ1},	//( - , Baz1) АЗ от НУП ИС1
	{ 58	,1	,1	, &B3VZ11LZ1},	//( - , Baz1) АЗ от НУП ИС2
	{ 59	,1	,1	, &B3IS22LDU},	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
	{ 60	,1	,1	, &A3VZ15LZ1},	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
	{ 61	,1	,1	, &A3VZ13LZ1},	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
	{ 62	,1	,1	, &R7II73LZ1},	//(vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
	{ 63	,1	,1	, &R7II71LZ1},	//(vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
	{ 64	,1	,1	, &R7II72LZ1},	//(vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
	{ 65	,1	,1	, &R0AD14LZ1},	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
	{ 66	,1	,1	, &R0AD21LDU},	//( - , SBz2DU) Подключить защиту от II УР
	{ 67	,1	,1	, &R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 68	,1	,1	, &R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 69	,1	,1	, &R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 70	,1	,1	, &R0DE36LZ2},	//(sbk:20 - S06SBK, DiagnBaz2) диагностика шкафа Баз2 МП15-3.1 место 1
	{ 71	,1	,1	, &R0DEB1LZ2},	//(sbk:20 - S10SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 5
	{ 72	,1	,1	, &R0DEB2LZ2},	//(sbk:20 - S11SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 5
	{ 73	,1	,1	, &R0DEB3LZ2},	//(sbk:20 - S12SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 6
	{ 74	,1	,1	, &R0DEB4LZ2},	//(sbk:20 - S13SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 6
	{ 75	,1	,1	, &R0DE3CLZ2},	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 5
	{ 76	,1	,1	, &R0DE3DLZ2},	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 6
	{ 77	,1	,1	, &TestDiagnBaz2},	//( - , Baz2) Неисправность от
	{ 78	,3	,1	, &R0MW11IP1},	//( - , Baz2) Переключатель ВЫСТРЕЛ
	{ 79	,1	,1	, &PS9},	//( - , - ) АС 1 ур (д2)
	{ 80	,1	,1	, &PS1},	//( - , - ) давление АЗ1
	{ 81	,1	,1	, &PS2},	//( - , - ) АЗ от ВУ ИС1
	{ 82	,1	,1	, &PS3},	//( - , - ) АЗ от НУП ИС1
	{ 83	,1	,1	, &PS4},	//( - , - ) АЗ темп АЗ1
	{ 84	,1	,1	, &PS5},	//( - , - ) АС по Периоду АЗ1
	{ 85	,1	,1	, &PS6},	//( - , - ) АС по мощности АЗ1
	{ 86	,1	,1	, &PS7},	//( - , - ) Исправность акнп А32
	{ 87	,1	,1	, &PS8},	//( - , - ) Исправность акнп А31
	{ 88	,1	,1	, &PS10},	//( - , - ) АС 1 ур (д1)
	{ 89	,1	,1	, &PS11},	//( - , - ) АС 2 ур
	{ 90	,1	,1	, &PS16},	//( - , - ) АЗ от НУП ИС2
	{ 91	,1	,1	, &PS17},	//( - , - ) Аз по АС любого давления АЗ2
	{ 92	,1	,1	, &PS15},	//( - , - ) АЗ от ВУ ИС2
	{ 93	,1	,1	, &PS14},	//( - , - ) АС по температуре АЗ2
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
	{ 140	,1	,1	, &A1EE01LS1},	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
	{ 141	,1	,1	, &A1EE01LS4},	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
	{ 142	,1	,1	, &A1EE01LS3},	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
	{ 143	,1	,1	, &A0EE01LZ2},	//( - , Baz2, SBz2DU) Исправность АКНП1
	{ 144	,1	,1	, &A0EE04LZ2},	//( - , Baz2, SBz2DU) Исправность АКНП4
	{ 145	,1	,1	, &A0EE02LZ2},	//( - , Baz2, SBz2DU) Исправность АКНП2
	{ 146	,1	,1	, &A0EE03LZ2},	//( - , Baz2, SBz2DU) Исправность АКНП3
	{ 147	,1	,1	, &A1EE01LS2},	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
	{ 148	,1	,1	, &A0EE05LZ2},	//( - , Baz2) Исправность сети АКНП1
	{ 149	,1	,1	, &A0EE06LZ2},	//( - , Baz2) Исправность сети АКНП2
	{ 150	,1	,1	, &A0EE07LZ2},	//( - , Baz2) Исправность сети АКНП3
	{ 151	,1	,1	, &A0EE08LZ2},	//( - , Baz2) Исправность сети АКНП4
	{ 152	,1	,1	, &A0VZ71LZ2},	//( - , Baz2) Обобщенный сигнал АС по АЗ1
	{ 153	,1	,1	, &A0EE00LZ2},	//( - , Baz2) Исправность АКНП АЗ1
	{ 154	,1	,1	, &B0EE00LZ2},	//( - , Baz2) Исправность АКНП АЗ2
	{ 155	,1	,1	, &B0VZ71LZ2},	//( - , Baz2) Обобщенный сигнал АС по АЗ2
	{ 156	,1	,1	, &A0VN71LZ2},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ1
	{ 157	,1	,1	, &B0VN71LZ2},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ2
	{ 158	,1	,1	, &A0VN81LZ2},	//( - , Baz2) АЗ по АС периода разгона АЗ1
	{ 159	,1	,1	, &B0VN81LZ2},	//( - , Baz2) АЗ по АС периода разгона АЗ2
	{ 160	,5	,1	, &R0VZ05UZ2},	//( - , Baz2) Индикатор причины сброса
	{ 161	,8	,1	, &R0VN11RZ2},	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ1
	{ 162	,1	,1	, &R0VP73LZ2},	//( - , Baz2, SBz2DU) ПС давления для РУ
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
	{ 178	,8	,1	, &R0VN09RZ2},	//( - , Baz2) Усредненный период разгона
	{ 179	,1	,1	, &R0AD03LZ2},	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
	{ 180	,1	,1	, &B3IS11LDU},	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
	{ 181	,1	,1	, &R0VN69LZ2},	//( - , Baz2) ПС по усредненному периоду
	{ 182	,1	,1	, &R0VN79LZ2},	//( - , Baz2) АС по усредненному периоду
	{ 183	,8	,1	, &R0VR02RZ2},	//( - , Baz2) Усредненная реактивность
	{ 184	,1	,1	, &R0VZ71LZ2},	//(fds16:0a - K05FDSR, Baz2) Обобщенный сигнал АЗ 2 канала
	{ 185	,1	,1	, &R0VN70LZ2},	//( - , Baz2) АЗ по АС мощности РУ
	{ 186	,1	,1	, &R0VN80LZ2},	//( - , Baz2) АЗ по АС периода разгона РУ
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
	{ 205	,8	,1	, &fEM_A1UL12RZZ},	//(A1UL12RZZ) Время задержки АЗ от НУП ИС(сек)
	{ 206	,8	,1	, &fEM_A1UL11RZZ},	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
	{ 207	,8	,1	, &fEM_R7UI73RZZ},	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
	{ 208	,8	,1	, &fEM_A1UL13RZZ},	//(A1UL13RZZ) Максимальное время цикла
	{ 209	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 210	,8	,1	, &internal1_m211_TVuIs1},	//(internal1_m211_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
	{ 211	,8	,1	, &internal1_m211_TVuIs2},	//(internal1_m211_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
	{ 212	,8	,1	, &internal1_m211_TImVuIs},	//(internal1_m211_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
	{ 213	,8	,1	, &internal1_m211_TNupIs1},	//(internal1_m211_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
	{ 214	,8	,1	, &internal1_m211_TNupIs2},	//(internal1_m211_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
	{ 215	,8	,1	, &internal1_m211_TImNupIs},	//(internal1_m211_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
	{ 216	,8	,1	, &internal1_m211_TImAZ2UR},	//(internal1_m211_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
	{ 217	,1	,1	, &internal1_m211_fef},	//(internal1_m211_fef) fef
	{ 218	,8	,1	, &internal1_m231_tx},	//(internal1_m231_tx) tx - время накопленное сек
	{ 219	,18	,1	, &internal1_m231_y0},	//(internal1_m231_y0) y0
	{ 220	,8	,1	, &internal1_m111_tx},	//(internal1_m111_tx) tx - время накопленное сек
	{ 221	,18	,1	, &internal1_m111_y0},	//(internal1_m111_y0) y0
	{ 222	,8	,1	, &internal1_m110_tx},	//(internal1_m110_tx) tx - время накопленное сек
	{ 223	,18	,1	, &internal1_m110_y0},	//(internal1_m110_y0) y0
	{ 224	,8	,1	, &internal1_m98_tx},	//(internal1_m98_tx) tx - время накопленное сек
	{ 225	,18	,1	, &internal1_m98_y0},	//(internal1_m98_y0) y0
	{ 226	,8	,1	, &internal1_m112_tx},	//(internal1_m112_tx) tx - время накопленное сек
	{ 227	,18	,1	, &internal1_m112_y0},	//(internal1_m112_y0) y0
	{ 228	,8	,1	, &internal1_m140_tx},	//(internal1_m140_tx) tx - время накопленное сек
	{ 229	,18	,1	, &internal1_m140_y0},	//(internal1_m140_y0) y0
	{ 230	,8	,1	, &internal1_m139_tx},	//(internal1_m139_tx) tx - время накопленное сек
	{ 231	,18	,1	, &internal1_m139_y0},	//(internal1_m139_y0) y0
	{ 232	,3	,1	, &internal1_m340_sttlf},	//(internal1_m340_sttlf) sttlf - счетчик для вещественного формата
	{ 233	,8	,1	, &internal1_m303_tx},	//(internal1_m303_tx) tx - время накопленное сек
	{ 234	,18	,1	, &internal1_m303_y0},	//(internal1_m303_y0) y0
	{ 235	,3	,1	, &internal1_m33_tx},	//(internal1_m33_tx) tx - внутренний параметр
	{ 236	,8	,1	, &internal1_m150_y0},	//(internal1_m150_y0) y0
	{ 237	,8	,1	, &internal1_m148_y0},	//(internal1_m148_y0) y0
	{ 238	,8	,1	, &internal1_m92_y0},	//(internal1_m92_y0) y0
	{ 239	,8	,1	, &internal1_m90_y0},	//(internal1_m90_y0) y0
	{ 240	,1	,1	, &internal1_m161_y1},	//(internal1_m161_y1) y1 - внутренний параметр
	{ 241	,1	,1	, &internal1_m172_y1},	//(internal1_m172_y1) y1 - внутренний параметр
	{ 242	,5	,1	, &internal1_m289_q0},	//(internal1_m289_q0) q0 - внутренний параметр
	{ 243	,1	,1	, &internal1_m130_y0},	//(internal1_m130_y0) state
	{ 244	,1	,1	, &internal1_m124_y0},	//(internal1_m124_y0) state
	{ 245	,1	,1	, &internal1_m107_y1},	//(internal1_m107_y1) y1 - внутренний параметр
	{ 246	,1	,1	, &internal1_m123_y1},	//(internal1_m123_y1) y1 - внутренний параметр
	{ 247	,1	,1	, &internal1_m94_y1},	//(internal1_m94_y1) y1 - внутренний параметр
	{ 248	,1	,1	, &internal1_m105_y1},	//(internal1_m105_y1) y1 - внутренний параметр
	{ 249	,1	,1	, &internal1_m158_y1},	//(internal1_m158_y1) y1 - внутренний параметр
	{ 250	,1	,1	, &internal1_m169_y1},	//(internal1_m169_y1) y1 - внутренний параметр
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
{208,"fEM_A1UL13RZZ\0"}, 
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
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_Baz2[]={  // 
	{&R0VP73LZ2,1,0},	//( - , Baz2, SBz2DU) ПС давления для РУ
	{&B0VN81LZ2,1,1},	//( - , Baz2) АЗ по АС периода разгона АЗ2
	{&A0VN81LZ2,1,2},	//( - , Baz2) АЗ по АС периода разгона АЗ1
	{&B0VN71LZ2,1,3},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ2
	{&A0VN71LZ2,1,4},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ1
	{&B0VZ71LZ2,1,5},	//( - , Baz2) Обобщенный сигнал АС по АЗ2
	{&B0EE00LZ2,1,6},	//( - , Baz2) Исправность АКНП АЗ2
	{&A0EE00LZ2,1,7},	//( - , Baz2) Исправность АКНП АЗ1
	{&A0VZ71LZ2,1,8},	//( - , Baz2) Обобщенный сигнал АС по АЗ1
	{&A0EE03LZ2,1,9},	//( - , Baz2, SBz2DU) Исправность АКНП3
	{&A0EE02LZ2,1,10},	//( - , Baz2, SBz2DU) Исправность АКНП2
	{&A0EE04LZ2,1,11},	//( - , Baz2, SBz2DU) Исправность АКНП4
	{&A0EE01LZ2,1,12},	//( - , Baz2, SBz2DU) Исправность АКНП1
	{&R0VN80LZ2,1,13},	//( - , Baz2) АЗ по АС периода разгона РУ
	{&R0VN70LZ2,1,14},	//( - , Baz2) АЗ по АС мощности РУ
	{&TestDiagnBaz2,1,15},	//( - , Baz2) Неисправность от
	{&R0AD16LZ2,1,16},	//( - , Baz2) Имитация АЗ от 1УР (датчик2)
	{&R0AD15LZ2,1,17},	//( - , Baz2) Имитация АЗ от 1УР (датчик1)
	{&R0VN78LZ2,1,18},	//( - K02VDSR, Baz2) АС по периоду разгона канал  4
	{&R0VN77LZ2,1,19},	//( - K02VDSR, Baz2) АС по периоду разгона канал  3
	{&R0VN74LZ2,1,20},	//( - K01VDSR, Baz2) АС по мощности канал 4
	{&R0VN73LZ2,1,21},	//( - K01VDSR, Baz2) АС по мощности канал 3
	{&R0VN76LZ2,1,22},	//( - K02VDSR, Baz2) АС по периоду разгона канал  2
	{&R0VN72LZ2,1,23},	//( - K01VDSR, Baz2) АС по мощности канал 2
	{&R0VN75LZ2,1,24},	//( - K02VDSR, Baz2) АС по периоду разгона канал 1
	{&R0VN71LZ2,1,25},	//( - K01VDSR, Baz2) АС по мощности канал 1
	{&B0VT71LZ2,1,26},	//( - , Baz2, SBz2DU) АС по температуре в АЗ2
	{&B0VT61LZ2,1,27},	//( - , Baz2) ПС по температуре в АЗ2
	{&B0VP71LZ2,1,28},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
	{&A0VP71LZ2,1,29},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
	{&R0ET02LZ2,1,30},	//( - , Baz2) Признак наличия неисправности по температуре АЗ2
	{&B0VP41LZ2,1,31},	//( - , Baz2) Давление АЗ2 ниже АС
	{&A0VP41LZ2,1,32},	//( - , Baz2) Давление АЗ1 ниже АС
	{&R0ET01LZ2,1,33},	//( - , Baz2) Признак наличия неисправности по температуре  АЗ1
	{&A2VP81LZ2,1,34},	//( - , Baz2) Давление СБРОС РБ1 в норме
	{&B2VP81LZ2,1,35},	//( - , Baz2) Давление СБРОС РБ2 в норме
	{&B2VP51LZ2,1,36},	//( - , Baz2) Давление СБРОС РБ2 ниже ПС
	{&B2VP41LZ2,1,37},	//( - , Baz2) Давление СБРОС РБ2 ниже АС
	{&A2VP51LZ2,1,38},	//( - , Baz2) Давление СБРОС РБ1 ниже ПС
	{&A2VP41LZ2,1,39},	//( - , Baz2) Давление СБРОС РБ1 ниже АС
	{&B1VP41LZ2,1,40},	//( - , Baz2, SBz2DU) Давление СБРОС ББ2 ниже АС
	{&A1VP41LZ2,1,41},	//( - , Baz2, SBz2DU) Давление СБРОС ББ1 ниже АС
	{&A0VT71LZ2,1,42},	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
	{&A0VT61LZ2,1,43},	//( - , Baz2) ПС по температуре в АЗ1
	{&R0VZ71LZ2,1,44},	//( - K05FDSR, Baz2) Обобщенный сигнал АЗ 2 канала
	{&R0VN79LZ2,1,45},	//( - , Baz2) АС по усредненному периоду
	{&R0VN69LZ2,1,46},	//( - , Baz2) ПС по усредненному периоду
	{&R0VN68LZ2,1,47},	//( - , Baz2) ПС по периоду разгона канал 4
	{&R0VN67LZ2,1,48},	//( - , Baz2) ПС по периоду разгона канал 3
	{&R0VN66LZ2,1,49},	//( - , Baz2) ПС по периоду разгона канал 2
	{&R0VN65LZ2,1,50},	//( - , Baz2) ПС по периоду разгона канал 1
	{&R0VN64LZ2,1,51},	//( - , Baz2) ПС по мощности канал 4
	{&R0VN63LZ2,1,52},	//( - , Baz2) ПС по мощности канал 3
	{&R0VN62LZ2,1,53},	//( - , Baz2) ПС по мощности канал 2
	{&R0VN61LZ2,1,54},	//( - , Baz2) ПС по мощности канал 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_Baz2[]={  // 
	{&R0VN11RZ2,8,0},	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ1
	{&R0VZ05UZ2,5,2},	//( - , Baz2) Индикатор причины сброса
	{&TTLBaz2,3,4},	//( - , Baz2) ttl
	{&B0CT01IZ2,8,5},	//( - , Baz2, SBz2DU) Температура АЗ2-1
	{&A0EP02IZ2,3,7},	//( - , Baz2) Индикатор -Давление  АЗ1 ниже АС
	{&B0EP02IZ2,3,8},	//( - , Baz2) Индикатор -Давление  АЗ2 ниже АС
	{&B2CP01RZ2,8,9},	//( - , Baz2) Текущее давление СБРОС РБ2
	{&A2CP01RZ2,8,11},	//( - , Baz2) Текущее давление СБРОС РБ1
	{&A0CT01IZ2,8,13},	//( - , Baz2, SBz2DU) Температура АЗ1-1
	{&R0VR02RZ2,8,15},	//( - , Baz2) Усредненная реактивность
	{&R0VN09RZ2,8,17},	//( - , Baz2) Усредненный период разгона
	{&R0VN08RZ2,8,19},	//( - , Baz2) Период разгона по каналу 4
	{&R0VN07RZ2,8,21},	//( - , Baz2) Период разгона по каналу 3
	{&R0VN06RZ2,8,23},	//( - , Baz2) Период разгона по каналу 2
	{&R0VN05RZ2,8,25},	//( - , Baz2) Период разгона по каналу 1
	{&R0VN04RZ2,8,27},	//( - , Baz2) Уровень мощности по каналу 4
	{&R0VN03RZ2,8,29},	//( - , Baz2) Уровень мощности по каналу 3
	{&R0VN02RZ2,8,31},	//( - , Baz2) Уровень мощности по каналу 2
	{&R0VN01RZ2,8,33},	//( - , Baz2) Уровень мощности по каналу 1
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
	{1,5019,&coil_MBz2A1[0],&di_MBz2A1[0],&ir_MBz2A1[0],&hr_MBz2A1[0],NULL,MBz2A1_ip1,MBz2A1_ip2,50},	 //Мастер Баз2 в AKNP1
	{1,5020,&coil_MBz2A2[0],&di_MBz2A2[0],&ir_MBz2A2[0],&hr_MBz2A2[0],NULL,MBz2A2_ip1,MBz2A2_ip2,50},	 //Мастер Баз2 в AKNP2
	{1,5021,&coil_MBz2A3[0],&di_MBz2A3[0],&ir_MBz2A3[0],&hr_MBz2A3[0],NULL,MBz2A3_ip1,MBz2A3_ip2,50},	 //Мастер Баз2 в AKNP3
	{1,5022,&coil_MBz2A4[0],&di_MBz2A4[0],&ir_MBz2A4[0],&hr_MBz2A4[0],NULL,MBz2A4_ip1,MBz2A4_ip2,50},	 //Мастер Баз2 в AKNP4

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
	{&B2IP01IZ2,3,9},
	{&A2IP01IZ2,3,3},
	{&A0IT02IZ2,3,0},
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
	{&R0DE05LZ2,3,64},
	{&B2IS12LDU,1,20},
	{&A2IS12LDU,1,18},
	{&R0AD03LZ2,1,12},
	{&A1VN71LS1,1,6},
	{&R0AD05LZ1,1,16},
	{&R0AD03LZ1,1,12},
	{&R0VN71LZ2,1,0},
	{&R0VN75LZ2,1,2},
	{&A3IS22LDU,1,10},
	{&A3IS11LDU,1,8},
	{&A1EE01LS1,1,4},
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
	{&B3IS22LDU,1,10},
	{&A1EE01LS2,1,4},
	{&R0VN72LZ2,1,0},
	{&R0VN76LZ2,1,2},
	{&B3IS11LDU,1,8},
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
	{&R0VN78LZ2,1,2},
	{&R0DE07LZ2,3,64},
	{&R0VN74LZ2,1,0},
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
	{&B0VP81LZZ,1,22},
	{&R0VN77LZ2,1,2},
	{&R0DE08LZ2,3,64},
	{&A1VP81LZZ,1,18},
	{&B1VP81LZZ,1,24},
	{&A1EE01LS3,1,4},
	{&R0VN73LZ2,1,0},
	{&A0VP81LZZ,1,16},
	{&A1VN71LS3,1,6},
	{&R7II73LZ1,1,12},
	{&R7II71LZ1,1,8},
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
	{&A1VN71LZ2,1,6},
	{&A3VZ13LZ2,1,0},
	{&R0AD14LZ2,1,4},
	{&R0VZ71LZ2,1,8},
	{&A3VZ13LZ1,1,0},
	{&A3VZ15LZ1,1,2},
	{&R0DE0ALZ2,3,38},
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
	{&R0DE36LZ2,1,10},
	{&R0DEB1LZ2,1,18},
	{&R0DEB2LZ2,1,20},
	{&R0DE39LZ2,1,16},
	{&R0DE37LZ2,1,12},
	{&R0DE38LZ2,1,14},
	{&R0DE35LZ2,1,8},
	{&R0DE34LZ2,1,6},
	{&R0DE33LZ2,1,4},
	{&R0DE32LZ2,1,2},
	{&R0DEB3LZ2,1,22},
	{&R0DE31LZ2,1,0},
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
	setAsFloat(205,0.190);
	setAsFloat(206,0.020);
	setAsFloat(207,0.022);
	setAsFloat(208,0.019);
	setAsBool(67,1);
	setAsBool(68,1);
	setAsBool(69,1);
}
uspaint8 InternalBuf[146];

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
ssfloat fRM_10_ = {10,0}; /* tz - время задержки сек */ 

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
ssint var32;
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
ssfloat var110;
ssfloat var111;
ssbool var112;
ssfloat var113;
ssfloat var114;
ssbool var115;
ssbool var116;
ssbool var117;
ssbool var118;
ssbool var119;
ssbool var120;
ssfloat var121;
sslong var122;
sslong var123;
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
ssbool var134;
ssbool var135;
ssfloat var136;
ssbool var137;
ssbool var138;
sschar var139;
ssbool var140;
sschar var141;
ssbool var142;
ssbool var143;
ssbool var144;
ssbool var145;
ssbool var146;
ssbool var147;
ssbool var148;
ssbool var149;
ssbool var150;
ssbool var151;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m353_x_1[6] = {&R0DE36LZ2,&R0DE37LZ2,&R0DE38LZ2,&R0DE39LZ2,&var29,&var28};
psint  array_m340_x_1[6] = {&R0DE04LZ2,&R0DE05LZ2,&R0DE06LZ2,&R0DE0ALZ2,&R0DE08LZ2,&R0DE07LZ2};
psfloat  array_m190_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psfloat  array_m323_x_1[4] = {&R0VN02RS1,&R0VN02RS2,&R0VN02RS3,&R0VN02RS4};
psbool  array_m323_diag_1[4] = {&var33,&var34,&var35,&var36};
psbool  array_m296_x_1[17] = {&var80,&var41,&var42,&var91,&var7,&var4,&var138,&var43,&var50,&var51,&var89,&var8,&var5,&var140,&var47,&var48,&var49};
psbool  array_m16_x_1[6] = {&var84,&var89,&var8,&var5,&var16,&var140};
psbool  array_m36_x_1[6] = {&var91,&var4,&var7,&var138,&var82,&var16};
psfloat  array_m2_x_1[4] = {&R0VN01RS1,&R0VN01RS2,&R0VN01RS3,&R0VN01RS4};
psbool  array_m2_diag_1[4] = {&var33,&var34,&var35,&var36};
psbool  array_m3_x_1[3] = {&var98,&var120,&var37};
psbool  array_m12_x_1[3] = {&var97,&var40,&var99};

/* Объявление структур */
_S_noto  S_noto_229_1 = {&R0AD14LDU,&var1};
_S_and2  S_and2_232_1 = {&var1,&var3,&var2};
_S_or3  S_or3_233_1 = {&var14,&var15,&R7II73LZ1,&var3};
_S_inicn  S_inicn_211_1 = {&A3IS11LDU,&B3IS11LDU,&R0AD03LZ1,&A3IS22LDU,&B3IS22LDU,&R0AD05LZ1,&var14,&var15,&var13,&R0AD14LDU,&fEM_A1UL11RZZ,&fEM_A1UL12RZZ,&fEM_R7UI73RZZ,&fEM_A1UL13RZZ,&var4,&var5,&var6,&var7,&var8,&var9,&var10,&internal1_m211_TVuIs1,&internal1_m211_TVuIs2,&internal1_m211_TImVuIs,&internal1_m211_TNupIs1,&internal1_m211_TNupIs2,&internal1_m211_TImNupIs,&internal1_m211_TImAZ2UR,&internal1_m211_fef};
_S_or2  S_or2_223_1 = {&R7II73LZ1,&var18,&var11};
_S_or2  S_or2_221_1 = {&R0AD21LDU,&R0AD14LDU,&var12};
_S_and2  S_and2_220_1 = {&var11,&var12,&var13};
_S_or2  S_or2_212_1 = {&var17,&R7II71LZ1,&var14};
_S_or2  S_or2_205_1 = {&var19,&R7II72LZ1,&var15};
_S_zpfs  S_zpfs_231_1 = {&var2,&fEM_R7UI73RZZ,&var16,&internal1_m231_tx,&internal1_m231_y0};
_S_noto  S_noto_207_1 = {&R6IS67LZZ,&var17};
_S_noto  S_noto_224_1 = {&R6IS68LZZ,&var18};
_S_noto  S_noto_206_1 = {&R6IS66LZZ,&var19};
_S_zzfs  S_zzfs_111_1 = {&B1VP81LZZ,&fRM_10000_,&var20,&internal1_m111_tx,&internal1_m111_y0};
_S_zzfs  S_zzfs_110_1 = {&A1VP81LZZ,&fRM_10000_,&var21,&internal1_m110_tx,&internal1_m110_y0};
_S_zzfs  S_zzfs_98_1 = {&var37,&fRM_10_,&var22,&internal1_m98_tx,&internal1_m98_y0};
_S_zzfs  S_zzfs_112_1 = {&var40,&fRM_10_,&var23,&internal1_m112_tx,&internal1_m112_y0};
_S_zzfs  S_zzfs_140_1 = {&B0VP81LZZ,&fRM_10000_,&var24,&internal1_m140_tx,&internal1_m140_y0};
_S_zzfs  S_zzfs_139_1 = {&A0VP81LZZ,&fRM_10000_,&var25,&internal1_m139_tx,&internal1_m139_y0};
_S_or3  S_or3_354_1 = {&var27,&var31,&var30,&var26};
_S_orn  S_orn_353_1 = {array_m353_x_1,&iRM_6_,&var27};
_S_or2  S_or2_360_1 = {&R0DEB3LZ2,&R0DEB4LZ2,&var28};
_S_or2  S_or2_351_1 = {&R0DEB1LZ2,&R0DEB2LZ2,&var29};
_S_and2  S_and2_342_1 = {&R0DE31LZ2,&R0DE32LZ2,&var30};
_S_diagndev  S_diagndev_340_1 = {array_m340_x_1,&iRM_6_,&var31,&var32,&vainSFloat,&internal1_m340_sttlf};
_S_ma  S_ma_190_1 = {array_m190_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_and2  S_and2_81_1 = {&lRM_1_,&A1EE01LS1,&var33};
_S_and2  S_and2_83_1 = {&lRM_1_,&A1EE01LS2,&var34};
_S_and2  S_and2_85_1 = {&lRM_1_,&A1EE01LS3,&var35};
_S_and2  S_and2_87_1 = {&lRM_1_,&A1EE01LS4,&var36};
_S_or2  S_or2_104_1 = {&var149,&var147,&var37};
_S_and2  S_and2_136_1 = {&var142,&var118,&var38};
_S_and2  S_and2_129_1 = {&var119,&var143,&var39};
_S_or2  S_or2_108_1 = {&var144,&var145,&var40};
_S_and2  S_and2_301_1 = {&var67,&var93,&var41};
_S_and2  S_and2_298_1 = {&var55,&var93,&var42};
_S_and2  S_and2_304_1 = {&var108,&var93,&var43};
_S_schl24  S_schl24_325_1 = {&A1VN71LS2,&A1VN71LS1,&A1VN71LS4,&A1VN71LS3,&var44};
_S_or2  S_or2_329_1 = {&var146,&var148,&var45};
_S_and2  S_and2_311_1 = {&var106,&var105,&var46};
_S_and2  S_and2_306_1 = {&R7II72LZ1,&var96,&var47};
_S_and2  S_and2_307_1 = {&R7II71LZ1,&var96,&var48};
_S_and2  S_and2_308_1 = {&R7II73LZ1,&var96,&var49};
_S_and2  S_and2_302_1 = {&var68,&var93,&var50};
_S_and2  S_and2_299_1 = {&var56,&var93,&var51};
_S_and2  S_and2_263_1 = {&var93,&var55,&var52};
_S_or2  S_or2_260_1 = {&var65,&var63,&var53};
_S_and2  S_and2_269_1 = {&var64,&var93,&var54};
_S_or2  S_or2_266_1 = {&var57,&var65,&var55};
_S_or2  S_or2_268_1 = {&var57,&var63,&var56};
_S_and2  S_and2_267_1 = {&var64,&var127,&var57};
_S_and2  S_and2_264_1 = {&var93,&var56,&var58};
_S_or2  S_or2_276_1 = {&R0VN76LZ2,&var130,&var59};
_S_or2  S_or2_277_1 = {&R0VN78LZ2,&var129,&var60};
_S_or2  S_or2_274_1 = {&R0VN75LZ2,&var132,&var61};
_S_or2  S_or2_275_1 = {&R0VN77LZ2,&var131,&var62};
_S_and2  S_and2_273_1 = {&var59,&var60,&var63};
_S_schl24  S_schl24_271_1 = {&var61,&var62,&var59,&var60,&var64};
_S_and2  S_and2_272_1 = {&var61,&var62,&var65};
_S_or2  S_or2_259_1 = {&var75,&var79,&var66};
_S_or2  S_or2_251_1 = {&var70,&var79,&var67};
_S_or2  S_or2_253_1 = {&var70,&var75,&var68};
_S_and2  S_and2_247_1 = {&var76,&var93,&var69};
_S_and2  S_and2_252_1 = {&var76,&var128,&var70};
_S_and2  S_and2_255_1 = {&var67,&var93,&var71};
_S_and2  S_and2_256_1 = {&var93,&var68,&var72};
_S_or2  S_or2_240_1 = {&R0VN72LZ2,&var130,&var73};
_S_or2  S_or2_241_1 = {&R0VN74LZ2,&var129,&var74};
_S_and2  S_and2_243_1 = {&var74,&var73,&var75};
_S_schl24  S_schl24_245_1 = {&var78,&var77,&var73,&var74,&var76};
_S_or2  S_or2_238_1 = {&R0VN71LZ2,&var132,&var77};
_S_or2  S_or2_239_1 = {&R0VN73LZ2,&var131,&var78};
_S_and2  S_and2_242_1 = {&var78,&var77,&var79};
_S_and2  S_and2_305_1 = {&var109,&var93,&var80};
_S_or3  S_or3_30_1 = {&var103,&var67,&var55,&var81};
_S_and2  S_and2_31_1 = {&var81,&var93,&var82};
_S_or2  S_or2_25_1 = {&var124,&var125,&var83};
_S_and2  S_and2_19_1 = {&var85,&var93,&var84};
_S_or3  S_or3_18_1 = {&var68,&var56,&var102,&var85};
_S_and2  S_and2_6_1 = {&var34,&var36,&var86};
_S_or2  S_or2_10_1 = {&var126,&var86,&var87};
_S_or2  S_or2_9_1 = {&var92,&var126,&var88};
_S_or2  S_or2_159_1 = {&var115,&var117,&var89};
_S_or2  S_or2_35_1 = {&B2IS12LDU,&A2IS12LDU,&var90};
_S_or2  S_or2_156_1 = {&var150,&var112,&var91};
_S_and2  S_and2_5_1 = {&var35,&var33,&var92};
_S_and2  S_and2_22_1 = {&var104,&var100,&var93};
_S_and2  S_and2_186_1 = {&var107,&var134,&var94};
_S_and2  S_and2_185_1 = {&var135,&var107,&var95};
_S_zpfs  S_zpfs_303_1 = {&var46,&fRM_0_2,&var96,&internal1_m303_tx,&internal1_m303_y0};
_S_noto  S_noto_142_1 = {&var24,&var97};
_S_noto  S_noto_141_1 = {&var25,&var98};
_S_noto  S_noto_116_1 = {&var20,&var99};
_S_noto  S_noto_27_1 = {&var101,&var100};
_S_ovb1  S_ovb1_33_1 = {&var90,&iRM_200_,&var101,&internal1_m33_tx};
_S_noto  S_noto_14_1 = {&var87,&var102};
_S_noto  S_noto_13_1 = {&var88,&var103};
_S_noto  S_noto_24_1 = {&R0EE02LDU,&var104};
_S_noto  S_noto_314_1 = {&R0AD16LDU,&var105};
_S_noto  S_noto_313_1 = {&R0AD14LDU,&var106};
_S_bol  S_bol_181_1 = {&var136,&fRM_0_00001,&var107};
_S_noto  S_noto_309_1 = {&var87,&var108};
_S_noto  S_noto_310_1 = {&var88,&var109};
_S_scalzz  S_scalzz_150_1 = {&B0IT02IZ2,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var110,&internal1_m150_y0};
_S_scalzz  S_scalzz_148_1 = {&A0IT02IZ2,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var111,&internal1_m148_y0};
_S_geterr  S_geterr_152_1 = {&var111,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var112};
_S_scalzz  S_scalzz_92_1 = {&B2IP01IZ2,&iRM_3276_,&iRM_16383_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var113,&internal1_m92_y0};
_S_scalzz  S_scalzz_90_1 = {&A2IP01IZ2,&iRM_3276_,&iRM_16383_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var114,&internal1_m90_y0};
_S_drg  S_drg_161_1 = {&var110,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var115,&internal1_m161_y1};
_S_drg  S_drg_172_1 = {&var110,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var116,&internal1_m172_y1};
_S_geterr  S_geterr_154_1 = {&var110,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var117};
_S_noto  S_noto_137_1 = {&var144,&var118};
_S_noto  S_noto_128_1 = {&var149,&var119};
_S_noto  S_noto_115_1 = {&var21,&var120};
_S_srm  S_srm_323_1 = {array_m323_x_1,array_m323_diag_1,&iRM_4_,&iRM_3_,&var121,&vainSBool};
_S_rsu  S_rsu_289_1 = {&R0MD34LP1,&var123,&var122,&internal1_m289_q0};
_S_orni  S_orni_296_1 = {array_m296_x_1,&iRM_17_,&vainSBool,&var123};
_S_orn  S_orn_16_1 = {array_m16_x_1,&iRM_6_,&var124};
_S_orn  S_orn_36_1 = {array_m36_x_1,&iRM_6_,&var125};
_S_noto  S_noto_7_1 = {&var137,&var126};
_S_noto  S_noto_262_1 = {&var53,&var127};
_S_noto  S_noto_257_1 = {&var66,&var128};
_S_noto  S_noto_246_1 = {&A1EE01LS4,&var129};
_S_noto  S_noto_250_1 = {&A1EE01LS2,&var130};
_S_noto  S_noto_249_1 = {&A1EE01LS3,&var131};
_S_noto  S_noto_244_1 = {&A1EE01LS1,&var132};
_S_react  S_react_177_1 = {&var136,&var133};
_S_bol  S_bol_182_1 = {&fEM_R0UR04RZZ,&var136,&var134};
_S_bol  S_bol_180_1 = {&fEM_R0UR01RZZ,&var136,&var135};
_S_srm  S_srm_2_1 = {array_m2_x_1,array_m2_diag_1,&iRM_4_,&iRM_3_,&var136,&var137};
_S_ornc  S_ornc_3_1 = {array_m3_x_1,&iRM_3_,&var138,&var139};
_S_ornc  S_ornc_12_1 = {array_m12_x_1,&iRM_3_,&var140,&var141};
_S_tprg  S_tprg_130_1 = {&var113,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var142,&internal1_m130_y0};
_S_tprg  S_tprg_124_1 = {&var114,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var143,&internal1_m124_y0};
_S_geterr  S_geterr_100_1 = {&var113,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var144};
_S_drg  S_drg_107_1 = {&var113,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var145,&internal1_m107_y1};
_S_drg  S_drg_123_1 = {&var113,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var146,&internal1_m123_y1};
_S_drg  S_drg_94_1 = {&var114,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var147,&internal1_m94_y1};
_S_drg  S_drg_105_1 = {&var114,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var148,&internal1_m105_y1};
_S_geterr  S_geterr_96_1 = {&var114,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var149};
_S_drg  S_drg_158_1 = {&var111,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var150,&internal1_m158_y1};
_S_drg  S_drg_169_1 = {&var111,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var151,&internal1_m169_y1};


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
   var32.i=0;
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
   var110.f=0.0;
   var111.f=0.0;
   var112.b=0;
   var113.f=0.0;
   var114.f=0.0;
   var115.b=0;
   var116.b=0;
   var117.b=0;
   var118.b=0;
   var119.b=0;
   var120.b=0;
   var121.f=0.0;
   var122.l=0L;
   var123.l=0L;
   var124.b=0;
   var125.b=0;
   var126.b=0;
   var127.b=0;
   var128.b=0;
   var129.b=0;
   var130.b=0;
   var131.b=0;
   var132.b=0;
   var133.f=0.0;
   var134.b=0;
   var135.b=0;
   var136.f=0.0;
   var137.b=0;
   var138.b=0;
   var139.c=0;
   var140.b=0;
   var141.c=0;
   var142.b=0;
   var143.b=0;
   var144.b=0;
   var145.b=0;
   var146.b=0;
   var147.b=0;
   var148.b=0;
   var149.b=0;
   var150.b=0;
   var151.b=0;
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
  noto(&S_noto_244_1);
  noto(&S_noto_249_1);
  noto(&S_noto_250_1);
  noto(&S_noto_246_1);
  scalzz(&S_scalzz_90_1);
  scalzz(&S_scalzz_92_1);
  scalzz(&S_scalzz_148_1);
  scalzz(&S_scalzz_150_1);
  or2(&S_or2_239_1);
  or2(&S_or2_238_1);
  or2(&S_or2_241_1);
  or2(&S_or2_240_1);
  or2(&S_or2_275_1);
  or2(&S_or2_274_1);
  or2(&S_or2_277_1);
  or2(&S_or2_276_1);
  schl24(&S_schl24_325_1);
  ma(&S_ma_190_1);
  diagndev(&S_diagndev_340_1);
  and2(&S_and2_342_1);
  or2(&S_or2_351_1);
  or2(&S_or2_360_1);
  orn(&S_orn_353_1);
  or3(&S_or3_354_1);
  zzfs(&S_zzfs_139_1);
  zzfs(&S_zzfs_140_1);
  zzfs(&S_zzfs_110_1);
  zzfs(&S_zzfs_111_1);
  noto(&S_noto_206_1);
  noto(&S_noto_224_1);
  noto(&S_noto_207_1);
  or2(&S_or2_205_1);
  or2(&S_or2_212_1);
  or2(&S_or2_221_1);
  or2(&S_or2_223_1);
  or3(&S_or3_233_1);
  noto(&S_noto_229_1);
  drg(&S_drg_169_1);
  drg(&S_drg_158_1);
  geterr(&S_geterr_96_1);
  drg(&S_drg_105_1);
  drg(&S_drg_94_1);
  drg(&S_drg_123_1);
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
  noto(&S_noto_313_1);
  noto(&S_noto_314_1);
  noto(&S_noto_24_1);
  noto(&S_noto_116_1);
  noto(&S_noto_141_1);
  noto(&S_noto_142_1);
  or2(&S_or2_156_1);
  or2(&S_or2_35_1);
  or2(&S_or2_159_1);
  and2(&S_and2_242_1);
  schl24(&S_schl24_245_1);
  and2(&S_and2_243_1);
  or2(&S_or2_259_1);
  and2(&S_and2_272_1);
  schl24(&S_schl24_271_1);
  and2(&S_and2_273_1);
  or2(&S_or2_260_1);
  and2(&S_and2_311_1);
  or2(&S_or2_329_1);
  or2(&S_or2_108_1);
  and2(&S_and2_129_1);
  and2(&S_and2_136_1);
  or2(&S_or2_104_1);
  and2(&S_and2_87_1);
  and2(&S_and2_85_1);
  and2(&S_and2_83_1);
  and2(&S_and2_81_1);
  zzfs(&S_zzfs_112_1);
  zzfs(&S_zzfs_98_1);
  and2(&S_and2_220_1);
  inicn(&S_inicn_211_1);
  and2(&S_and2_232_1);
  ornc(&S_ornc_12_1);
  ornc(&S_ornc_3_1);
  srm(&S_srm_2_1);
  bol(&S_bol_180_1);
  bol(&S_bol_182_1);
  react(&S_react_177_1);
  noto(&S_noto_257_1);
  noto(&S_noto_262_1);
  noto(&S_noto_7_1);
  srm(&S_srm_323_1);
  bol(&S_bol_181_1);
  ovb1(&S_ovb1_33_1);
  noto(&S_noto_27_1);
  zpfs(&S_zpfs_303_1);
  and2(&S_and2_185_1);
  and2(&S_and2_186_1);
  and2(&S_and2_22_1);
  and2(&S_and2_5_1);
  or2(&S_or2_9_1);
  and2(&S_and2_6_1);
  and2(&S_and2_252_1);
  and2(&S_and2_247_1);
  or2(&S_or2_253_1);
  or2(&S_or2_251_1);
  and2(&S_and2_267_1);
  or2(&S_or2_268_1);
  or2(&S_or2_266_1);
  and2(&S_and2_269_1);
  and2(&S_and2_263_1);
  and2(&S_and2_299_1);
  and2(&S_and2_302_1);
  and2(&S_and2_308_1);
  and2(&S_and2_307_1);
  and2(&S_and2_306_1);
  and2(&S_and2_298_1);
  and2(&S_and2_301_1);
  zpfs(&S_zpfs_231_1);
  noto(&S_noto_310_1);
  noto(&S_noto_13_1);
  or2(&S_or2_10_1);
  or3(&S_or3_30_1);
  and2(&S_and2_305_1);
  and2(&S_and2_256_1);
  and2(&S_and2_255_1);
  and2(&S_and2_264_1);
  noto(&S_noto_309_1);
  noto(&S_noto_14_1);
  or3(&S_or3_18_1);
  and2(&S_and2_19_1);
  and2(&S_and2_31_1);
  and2(&S_and2_304_1);
  orn(&S_orn_36_1);
  orn(&S_orn_16_1);
  orni(&S_orni_296_1);
  rsu(&S_rsu_289_1);
  or2(&S_or2_25_1);
  setData(idR0AD14LZ1,&var10);
  setData(idA3VZ13LZ1,&var6);
  setData(idA3VZ15LZ1,&var9);
  setData(idB3VZ11LZ1,&var8);
  setData(idA3VZ11LZ1,&var7);
  setData(idB3VZ31LZ1,&var5);
  setData(idA3VZ31LZ1,&var4);
  setData(idR0VZ05U,&var123);
  setData(idPS13,&var56);
  setData(idPS12,&var68);
  setData(idPS14,&var89);
  setData(idPS15,&var5);
  setData(idPS17,&var140);
  setData(idPS16,&var8);
  setData(idPS8,&var88);
  setData(idPS7,&var87);
  setData(idPS6,&var67);
  setData(idPS5,&var55);
  setData(idPS4,&var91);
  setData(idPS3,&var7);
  setData(idPS2,&var4);
  setData(idPS1,&var138);
  setData(idTestDiagnBaz2,&var26);
  setData(idR0DE3DLZ2,&var28);
  setData(idR0DE3CLZ2,&var29);
  setData(idTTLBaz2,&var32);
  moveData(idR0EE04LZ2,idR0EE02LDU);
  moveData(idR0EE03LZ2,idR0EE02LDU);
  moveData(idR0EE02LZ2,idR0EE02LDU);
  moveData(idR0EE01LZ2,idR0EE02LDU);
  setData(idA1VN71LZ2,&var44);
  setData(idB0VT71LZ2,&var89);
  setData(idB0VT61LZ2,&var116);
  setData(idB0CT01IZ2,&var110);
  setData(idR0VP73LZ2,&var45);
  setData(idR0VN11RZ2,&var121);
  setData(idR0VZ05UZ2,&var122);
  setData(idB0VN81LZ2,&var58);
  setData(idA0VN81LZ2,&var52);
  setData(idB0VN71LZ2,&var72);
  setData(idA0VN71LZ2,&var71);
  setData(idB0VZ71LZ2,&var124);
  setData(idB0EE00LZ2,&var87);
  setData(idA0EE00LZ2,&var88);
  setData(idA0VZ71LZ2,&var125);
  setData(idA0EE03LZ2,&var35);
  setData(idA0EE02LZ2,&var34);
  setData(idA0EE04LZ2,&var36);
  setData(idA0EE01LZ2,&var33);
  setData(idR0VN80LZ2,&var54);
  setData(idR0VN70LZ2,&var69);
  setData(idR0VZ71LZ2,&var83);
  setData(idR0VR02RZ2,&var133);
  setData(idR0VN79LZ2,&var94);
  setData(idR0VN69LZ2,&var95);
  setData(idR0VN09RZ2,&var136);
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
  setData(idB0VP71LZ2,&var140);
  setData(idA0VP71LZ2,&var138);
  setData(idA0EP02IZ2,&var139);
  setData(idB0EP02IZ2,&var141);
  setData(idR0ET02LZ2,&var117);
  setData(idB0VP41LZ2,&var97);
  setData(idA0VP41LZ2,&var98);
  setData(idR0ET01LZ2,&var112);
  setData(idA2VP81LZ2,&var39);
  setData(idB2VP81LZ2,&var38);
  setData(idB2VP51LZ2,&var146);
  setData(idB2CP01RZ2,&var113);
  setData(idB2VP41LZ2,&var23);
  setData(idA2VP51LZ2,&var148);
  setData(idA2CP01RZ2,&var114);
  setData(idA2VP41LZ2,&var22);
  setData(idB1VP41LZ2,&var99);
  setData(idA1VP41LZ2,&var120);
  setData(idA0VT71LZ2,&var91);
  setData(idA0VT61LZ2,&var151);
  setData(idA0CT01IZ2,&var111);

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
