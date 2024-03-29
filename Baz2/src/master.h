#ifndef BAZ2_H
#define BAZ2_H
// Подсистема  Baz2:Baz2
static char SimulOn=0;
static short CodeSub=6;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 //Время цикла мс
float takt,taktScheme=0,taktSS=0;
#define SIZE_BUFFER 1014
static char BUFFER[SIZE_BUFFER];
#include <fp8/UDPTransport.h>
SetupUDP setUDP ={"192.168.10.54\0",5432,"192.168.10.154\0",5432,BUFFER,sizeof(BUFFER),};
int master=1,nomer=1;
#define A0CT01IZ2	BUFFER[0]	// ( - , Baz2, SBz2DU) Температура АЗ1-1
#define idA0CT01IZ2	1	// ( - , Baz2, SBz2DU) Температура АЗ1-1
#define A0EE00LZ2	BUFFER[5]	// ( - , Baz2) Исправность АКНП АЗ1
#define idA0EE00LZ2	2	// ( - , Baz2) Исправность АКНП АЗ1
#define A0EE01LZ2	BUFFER[7]	// ( - , Baz2, SBz2DU) Исправность АКНП1
#define idA0EE01LZ2	3	// ( - , Baz2, SBz2DU) Исправность АКНП1
#define A0EE02LZ2	BUFFER[9]	// ( - , Baz2, SBz2DU) Исправность АКНП2
#define idA0EE02LZ2	4	// ( - , Baz2, SBz2DU) Исправность АКНП2
#define A0EE03LZ2	BUFFER[11]	// ( - , Baz2, SBz2DU) Исправность АКНП3
#define idA0EE03LZ2	5	// ( - , Baz2, SBz2DU) Исправность АКНП3
#define A0EE04LZ2	BUFFER[13]	// ( - , Baz2, SBz2DU) Исправность АКНП4
#define idA0EE04LZ2	6	// ( - , Baz2, SBz2DU) Исправность АКНП4
#define A0EE05LZ2	BUFFER[15]	// ( - , Baz2) Исправность сети АКНП1
#define idA0EE05LZ2	7	// ( - , Baz2) Исправность сети АКНП1
#define A0EE06LZ2	BUFFER[17]	// ( - , Baz2) Исправность сети АКНП2
#define idA0EE06LZ2	8	// ( - , Baz2) Исправность сети АКНП2
#define A0EE07LZ2	BUFFER[19]	// ( - , Baz2) Исправность сети АКНП3
#define idA0EE07LZ2	9	// ( - , Baz2) Исправность сети АКНП3
#define A0EE08LZ2	BUFFER[21]	// ( - , Baz2) Исправность сети АКНП4
#define idA0EE08LZ2	10	// ( - , Baz2) Исправность сети АКНП4
#define A0EP02IZ2	BUFFER[23]	// ( - , Baz2) Индикатор -Давление  АЗ1 ниже АС
#define idA0EP02IZ2	11	// ( - , Baz2) Индикатор -Давление  АЗ1 ниже АС
#define A0IT02IZ2	BUFFER[26]	// (vas84:04 - K01VASR, Baz2) Температура АЗ1-2
#define idA0IT02IZ2	12	// (vas84:04 - K01VASR, Baz2) Температура АЗ1-2
#define A0VN71LZ2	BUFFER[29]	// ( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ1
#define idA0VN71LZ2	13	// ( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ1
#define A0VN81LZ2	BUFFER[31]	// ( - , Baz2) АЗ по АС периода разгона АЗ1
#define idA0VN81LZ2	14	// ( - , Baz2) АЗ по АС периода разгона АЗ1
#define A0VP41LZ2	BUFFER[33]	// ( - , Baz2) Давление АЗ1 ниже АС
#define idA0VP41LZ2	15	// ( - , Baz2) Давление АЗ1 ниже АС
#define A0VP71LZ2	BUFFER[35]	// ( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ2	16	// ( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
#define A0VP81LZZ	BUFFER[37]	// (vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define idA0VP81LZZ	17	// (vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define A0VT61LZ2	BUFFER[39]	// ( - , Baz2) ПС по температуре в АЗ1
#define idA0VT61LZ2	18	// ( - , Baz2) ПС по температуре в АЗ1
#define A0VT71LZ2	BUFFER[41]	// ( - , Baz2, SBz2DU) АС по температуре в АЗ1
#define idA0VT71LZ2	19	// ( - , Baz2, SBz2DU) АС по температуре в АЗ1
#define A0VZ71LZ2	BUFFER[43]	// ( - , Baz2) Обобщенный сигнал АС по АЗ1
#define idA0VZ71LZ2	20	// ( - , Baz2) Обобщенный сигнал АС по АЗ1
#define A1EE01LS1	BUFFER[45]	// (vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define idA1EE01LS1	21	// (vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define A1EE01LS2	BUFFER[47]	// (vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define idA1EE01LS2	22	// (vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define A1EE01LS3	BUFFER[49]	// (vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define idA1EE01LS3	23	// (vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define A1EE01LS4	BUFFER[51]	// (vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define idA1EE01LS4	24	// (vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define A1VN71LS1	BUFFER[53]	// (vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
#define idA1VN71LS1	25	// (vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
#define A1VN71LS2	BUFFER[55]	// (vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
#define idA1VN71LS2	26	// (vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
#define A1VN71LS3	BUFFER[57]	// (vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
#define idA1VN71LS3	27	// (vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
#define A1VN71LS4	BUFFER[59]	// (vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
#define idA1VN71LS4	28	// (vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
#define A1VN71LZ2	BUFFER[61]	// (fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
#define idA1VN71LZ2	29	// (fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
#define A1VP41LZ2	BUFFER[63]	// ( - , Baz2, SBz2DU) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ2	30	// ( - , Baz2, SBz2DU) Давление СБРОС ББ1 ниже АС
#define A1VP81LZZ	BUFFER[65]	// (vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	31	// (vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define A2CP01RZ2	BUFFER[67]	// ( - , Baz2) Текущее давление СБРОС РБ1
#define idA2CP01RZ2	32	// ( - , Baz2) Текущее давление СБРОС РБ1
#define A2IP01IZ2	BUFFER[72]	// (vas84:04 - K02VASR, Baz2) Текущее давление СБРОС РБ1
#define idA2IP01IZ2	33	// (vas84:04 - K02VASR, Baz2) Текущее давление СБРОС РБ1
#define A2IS12LDU	BUFFER[75]	// (vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	34	// (vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define A2VP41LZ2	BUFFER[77]	// ( - , Baz2) Давление СБРОС РБ1 ниже АС
#define idA2VP41LZ2	35	// ( - , Baz2) Давление СБРОС РБ1 ниже АС
#define A2VP51LZ2	BUFFER[79]	// ( - , Baz2) Давление СБРОС РБ1 ниже ПС
#define idA2VP51LZ2	36	// ( - , Baz2) Давление СБРОС РБ1 ниже ПС
#define A2VP81LZ2	BUFFER[81]	// ( - , Baz2) Давление СБРОС РБ1 в норме
#define idA2VP81LZ2	37	// ( - , Baz2) Давление СБРОС РБ1 в норме
#define A3IS11LDU	BUFFER[83]	// (vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define idA3IS11LDU	38	// (vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define A3IS22LDU	BUFFER[85]	// (vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define idA3IS22LDU	39	// (vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define A3VZ11LZ2	BUFFER[87]	// ( - , Baz2) АЗ от НУП ИС1
#define idA3VZ11LZ2	40	// ( - , Baz2) АЗ от НУП ИС1
#define A3VZ13LZ2	BUFFER[89]	// (fds16:0a - K01FDSR, Baz2) Имитация АЗ от ВУ ИС
#define idA3VZ13LZ2	41	// (fds16:0a - K01FDSR, Baz2) Имитация АЗ от ВУ ИС
#define A3VZ15LZ2	BUFFER[91]	// (fds16:0a - K02FDSR, Baz2) Имитация АЗ от НУП ИС
#define idA3VZ15LZ2	42	// (fds16:0a - K02FDSR, Baz2) Имитация АЗ от НУП ИС
#define A3VZ31LZ2	BUFFER[93]	// ( - , Baz2) АЗ от ВУ ИС1
#define idA3VZ31LZ2	43	// ( - , Baz2) АЗ от ВУ ИС1
#define B0CT01IZ2	BUFFER[95]	// ( - , Baz2, SBz2DU) Температура АЗ2-1
#define idB0CT01IZ2	44	// ( - , Baz2, SBz2DU) Температура АЗ2-1
#define B0EE00LZ2	BUFFER[100]	// ( - , Baz2) Исправность АКНП АЗ2
#define idB0EE00LZ2	45	// ( - , Baz2) Исправность АКНП АЗ2
#define B0EP02IZ2	BUFFER[102]	// ( - , Baz2) Индикатор -Давление  АЗ2 ниже АС
#define idB0EP02IZ2	46	// ( - , Baz2) Индикатор -Давление  АЗ2 ниже АС
#define B0IT02IZ2	BUFFER[105]	// (vas84:04 - K03VASR, Baz2) Температура АЗ2-2
#define idB0IT02IZ2	47	// (vas84:04 - K03VASR, Baz2) Температура АЗ2-2
#define B0VN71LZ2	BUFFER[108]	// ( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ2
#define idB0VN71LZ2	48	// ( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ2
#define B0VN81LZ2	BUFFER[110]	// ( - , Baz2) АЗ по АС периода разгона АЗ2
#define idB0VN81LZ2	49	// ( - , Baz2) АЗ по АС периода разгона АЗ2
#define B0VP41LZ2	BUFFER[112]	// ( - , Baz2) Давление АЗ2 ниже АС
#define idB0VP41LZ2	50	// ( - , Baz2) Давление АЗ2 ниже АС
#define B0VP71LZ2	BUFFER[114]	// ( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ2	51	// ( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
#define B0VP81LZZ	BUFFER[116]	// (vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	52	// (vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define B0VT61LZ2	BUFFER[118]	// ( - , Baz2) ПС по температуре в АЗ2
#define idB0VT61LZ2	53	// ( - , Baz2) ПС по температуре в АЗ2
#define B0VT71LZ2	BUFFER[120]	// ( - , Baz2, SBz2DU) АС по температуре в АЗ2
#define idB0VT71LZ2	54	// ( - , Baz2, SBz2DU) АС по температуре в АЗ2
#define B0VZ71LZ2	BUFFER[122]	// ( - , Baz2) Обобщенный сигнал АС по АЗ2
#define idB0VZ71LZ2	55	// ( - , Baz2) Обобщенный сигнал АС по АЗ2
#define B1VP41LZ2	BUFFER[124]	// ( - , Baz2, SBz2DU) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ2	56	// ( - , Baz2, SBz2DU) Давление СБРОС ББ2 ниже АС
#define B1VP81LZZ	BUFFER[126]	// (vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	57	// (vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define B2CP01RZ2	BUFFER[128]	// ( - , Baz2) Текущее давление СБРОС РБ2
#define idB2CP01RZ2	58	// ( - , Baz2) Текущее давление СБРОС РБ2
#define B2IP01IZ2	BUFFER[133]	// (vas84:04 - K04VASR, Baz2) Текущее давление СБРОС РБ2
#define idB2IP01IZ2	59	// (vas84:04 - K04VASR, Baz2) Текущее давление СБРОС РБ2
#define B2IS12LDU	BUFFER[136]	// (vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	60	// (vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define B2VP41LZ2	BUFFER[138]	// ( - , Baz2) Давление СБРОС РБ2 ниже АС
#define idB2VP41LZ2	61	// ( - , Baz2) Давление СБРОС РБ2 ниже АС
#define B2VP51LZ2	BUFFER[140]	// ( - , Baz2) Давление СБРОС РБ2 ниже ПС
#define idB2VP51LZ2	62	// ( - , Baz2) Давление СБРОС РБ2 ниже ПС
#define B2VP81LZ2	BUFFER[142]	// ( - , Baz2) Давление СБРОС РБ2 в норме
#define idB2VP81LZ2	63	// ( - , Baz2) Давление СБРОС РБ2 в норме
#define B3IS11LDU	BUFFER[144]	// (vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define idB3IS11LDU	64	// (vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define B3IS22LDU	BUFFER[146]	// (vds32:06 - K06VDSR, - ) Приход на НУП ИС2
#define idB3IS22LDU	65	// (vds32:06 - K06VDSR, - ) Приход на НУП ИС2
#define B3VZ11LZ2	BUFFER[148]	// ( - , Baz2) АЗ от НУП ИС2
#define idB3VZ11LZ2	66	// ( - , Baz2) АЗ от НУП ИС2
#define B3VZ31LZ2	BUFFER[150]	// ( - , Baz2) АЗ от ВУ ИС2
#define idB3VZ31LZ2	67	// ( - , Baz2) АЗ от ВУ ИС2
#define B8VC01RDU	BUFFER[152]	// ( - , SBz2DU, MBz2A1, MBz2A2, MBz2A3, MBz2A4) Координата АЗ2, мм
#define idB8VC01RDU	68	// ( - , SBz2DU, MBz2A1, MBz2A2, MBz2A3, MBz2A4) Координата АЗ2, мм
#define R0AD03LZ2	BUFFER[157]	// (vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define idR0AD03LZ2	69	// (vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define R0AD04LZ2	BUFFER[159]	// (vds32:05 - K08VDSR, - ) Имитация срабатывания АС II УР рад (БАЗ2)
#define idR0AD04LZ2	70	// (vds32:05 - K08VDSR, - ) Имитация срабатывания АС II УР рад (БАЗ2)
#define R0AD05LZ2	BUFFER[161]	// (vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define idR0AD05LZ2	71	// (vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define R0AD14LZ2	BUFFER[163]	// (fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define idR0AD14LZ2	72	// (fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define R0AD21LDU	BUFFER[165]	// ( - , SBz2DU) Подключить защиту от II УР
#define idR0AD21LDU	73	// ( - , SBz2DU) Подключить защиту от II УР
#define R0DE04LZ2	BUFFER[167]	// (vas84:04 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 4 месте
#define idR0DE04LZ2	74	// (vas84:04 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 4 месте
#define R0DE05LZ2	BUFFER[170]	// (vds32:05 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 5 месте
#define idR0DE05LZ2	75	// (vds32:05 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 5 месте
#define R0DE06LZ2	BUFFER[173]	// (vds32:06 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 6 месте
#define idR0DE06LZ2	76	// (vds32:06 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 6 месте
#define R0DE07LZ2	BUFFER[176]	// (vds32:07 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 7 месте
#define idR0DE07LZ2	77	// (vds32:07 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 7 месте
#define R0DE08LZ2	BUFFER[179]	// (vds32:08 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 8 месте
#define idR0DE08LZ2	78	// (vds32:08 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 8 месте
#define R0DE0ALZ2	BUFFER[182]	// (fds16:0a - Diagn, DiagnBaz2) диагностика модуля Баз2 на 10 месте
#define idR0DE0ALZ2	79	// (fds16:0a - Diagn, DiagnBaz2) диагностика модуля Баз2 на 10 месте
#define R0DE3CLZ2	BUFFER[185]	// ( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 5
#define idR0DE3CLZ2	80	// ( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 5
#define R0DE3DLZ2	BUFFER[187]	// ( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 6
#define idR0DE3DLZ2	81	// ( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 6
#define R0DEB1LZ2	BUFFER[189]	// (sbk:20 - S10SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 5
#define idR0DEB1LZ2	82	// (sbk:20 - S10SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 5
#define R0DEB2LZ2	BUFFER[191]	// (sbk:20 - S11SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 5
#define idR0DEB2LZ2	83	// (sbk:20 - S11SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 5
#define R0DEB3LZ2	BUFFER[193]	// (sbk:20 - S12SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 6
#define idR0DEB3LZ2	84	// (sbk:20 - S12SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 6
#define R0DEB4LZ2	BUFFER[195]	// (sbk:20 - S13SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 6
#define idR0DEB4LZ2	85	// (sbk:20 - S13SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 6
#define R0EE01LZ2	BUFFER[197]	// ( - , MBz2S) Питание  АКНП1  отключить
#define idR0EE01LZ2	86	// ( - , MBz2S) Питание  АКНП1  отключить
#define R0EE02LDU	BUFFER[199]	// ( - , Baz2, SBz2DU) Питание  АКНП  отключить
#define idR0EE02LDU	87	// ( - , Baz2, SBz2DU) Питание  АКНП  отключить
#define R0EE02LZ2	BUFFER[201]	// ( - , MBz2S) Питание  АКНП2  отключить
#define idR0EE02LZ2	88	// ( - , MBz2S) Питание  АКНП2  отключить
#define R0EE03LZ2	BUFFER[203]	// ( - , MBz2S) Питание  АКНП3  отключить
#define idR0EE03LZ2	89	// ( - , MBz2S) Питание  АКНП3  отключить
#define R0EE04LZ2	BUFFER[205]	// ( - , MBz2S) Питание  АКНП4  отключить
#define idR0EE04LZ2	90	// ( - , MBz2S) Питание  АКНП4  отключить
#define R0ET01LZ2	BUFFER[207]	// ( - , Baz2) Признак наличия неисправности по температуре  АЗ1
#define idR0ET01LZ2	91	// ( - , Baz2) Признак наличия неисправности по температуре  АЗ1
#define R0ET02LZ2	BUFFER[209]	// ( - , Baz2) Признак наличия неисправности по температуре АЗ2
#define idR0ET02LZ2	92	// ( - , Baz2) Признак наличия неисправности по температуре АЗ2
#define R0MD34LP1	BUFFER[211]	// ( - , Baz2) Кнопка Квитировать
#define idR0MD34LP1	93	// ( - , Baz2) Кнопка Квитировать
#define R0MW11IP1	BUFFER[213]	// ( - , Baz2) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	94	// ( - , Baz2) Переключатель ВЫСТРЕЛ
#define R0MW12IP2	BUFFER[216]	// ( - , Baz2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define idR0MW12IP2	95	// ( - , Baz2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define R0S01LZ2	BUFFER[219]	// (vds32:08 - K08VDSR, - ) Отключение сетевых передач в Баз2
#define idR0S01LZ2	96	// (vds32:08 - K08VDSR, - ) Отключение сетевых передач в Баз2
#define R0VN01RS1	BUFFER[221]	// ( - , MBz2A1) Период разгона канал 1
#define idR0VN01RS1	97	// ( - , MBz2A1) Период разгона канал 1
#define R0VN01RS2	BUFFER[226]	// ( - , MBz2A2) Период разгона канал 2
#define idR0VN01RS2	98	// ( - , MBz2A2) Период разгона канал 2
#define R0VN01RS3	BUFFER[231]	// ( - , MBz2A3) Период разгона канал 3
#define idR0VN01RS3	99	// ( - , MBz2A3) Период разгона канал 3
#define R0VN01RS4	BUFFER[236]	// ( - , MBz2A4) Период разгона канал 4
#define idR0VN01RS4	100	// ( - , MBz2A4) Период разгона канал 4
#define R0VN01RZ2	BUFFER[241]	// ( - , Baz2) Уровень мощности по каналу 1
#define idR0VN01RZ2	101	// ( - , Baz2) Уровень мощности по каналу 1
#define R0VN02RS1	BUFFER[246]	// ( - , MBz2A1) Уровень мощности канал 1
#define idR0VN02RS1	102	// ( - , MBz2A1) Уровень мощности канал 1
#define R0VN02RS2	BUFFER[251]	// ( - , MBz2A2) Уровень мощности канал 2
#define idR0VN02RS2	103	// ( - , MBz2A2) Уровень мощности канал 2
#define R0VN02RS3	BUFFER[256]	// ( - , MBz2A3) Уровень мощности канал 3
#define idR0VN02RS3	104	// ( - , MBz2A3) Уровень мощности канал 3
#define R0VN02RS4	BUFFER[261]	// ( - , MBz2A4) Уровень мощности канал 4
#define idR0VN02RS4	105	// ( - , MBz2A4) Уровень мощности канал 4
#define R0VN02RZ2	BUFFER[266]	// ( - , Baz2) Уровень мощности по каналу 2
#define idR0VN02RZ2	106	// ( - , Baz2) Уровень мощности по каналу 2
#define R0VN03RZ2	BUFFER[271]	// ( - , Baz2) Уровень мощности по каналу 3
#define idR0VN03RZ2	107	// ( - , Baz2) Уровень мощности по каналу 3
#define R0VN04RZ2	BUFFER[276]	// ( - , Baz2) Уровень мощности по каналу 4
#define idR0VN04RZ2	108	// ( - , Baz2) Уровень мощности по каналу 4
#define R0VN05RZ2	BUFFER[281]	// ( - , Baz2) Период разгона по каналу 1
#define idR0VN05RZ2	109	// ( - , Baz2) Период разгона по каналу 1
#define R0VN06RZ2	BUFFER[286]	// ( - , Baz2) Период разгона по каналу 2
#define idR0VN06RZ2	110	// ( - , Baz2) Период разгона по каналу 2
#define R0VN07RZ2	BUFFER[291]	// ( - , Baz2) Период разгона по каналу 3
#define idR0VN07RZ2	111	// ( - , Baz2) Период разгона по каналу 3
#define R0VN08RZ2	BUFFER[296]	// ( - , Baz2) Период разгона по каналу 4
#define idR0VN08RZ2	112	// ( - , Baz2) Период разгона по каналу 4
#define R0VN09RZ2	BUFFER[301]	// ( - , Baz2) Усредненный период разгона
#define idR0VN09RZ2	113	// ( - , Baz2) Усредненный период разгона
#define R0VN11RZ2	BUFFER[306]	// ( - , Baz2, SBz2DU) Средняя мощность по БАЗ2
#define idR0VN11RZ2	114	// ( - , Baz2, SBz2DU) Средняя мощность по БАЗ2
#define R0VN61LS1	BUFFER[311]	// ( - , MBz2A1) ПС по мощности канал 1
#define idR0VN61LS1	115	// ( - , MBz2A1) ПС по мощности канал 1
#define R0VN61LS2	BUFFER[313]	// ( - , MBz2A2) ПС по мощности канал 2
#define idR0VN61LS2	116	// ( - , MBz2A2) ПС по мощности канал 2
#define R0VN61LS3	BUFFER[315]	// ( - , MBz2A3) ПС по мощности канал 3
#define idR0VN61LS3	117	// ( - , MBz2A3) ПС по мощности канал 3
#define R0VN61LS4	BUFFER[317]	// ( - , MBz2A4) ПС по мощности канал 4
#define idR0VN61LS4	118	// ( - , MBz2A4) ПС по мощности канал 4
#define R0VN61LZ2	BUFFER[319]	// ( - , Baz2) ПС по мощности канал 1
#define idR0VN61LZ2	119	// ( - , Baz2) ПС по мощности канал 1
#define R0VN62LZ2	BUFFER[321]	// ( - , Baz2) ПС по мощности канал 2
#define idR0VN62LZ2	120	// ( - , Baz2) ПС по мощности канал 2
#define R0VN63LZ2	BUFFER[323]	// ( - , Baz2) ПС по мощности канал 3
#define idR0VN63LZ2	121	// ( - , Baz2) ПС по мощности канал 3
#define R0VN64LZ2	BUFFER[325]	// ( - , Baz2) ПС по мощности канал 4
#define idR0VN64LZ2	122	// ( - , Baz2) ПС по мощности канал 4
#define R0VN65LS1	BUFFER[327]	// ( - , MBz2A1) ПС по периоду разгона канал 1
#define idR0VN65LS1	123	// ( - , MBz2A1) ПС по периоду разгона канал 1
#define R0VN65LS2	BUFFER[329]	// ( - , MBz2A2) ПС по периоду разгона  канал 2
#define idR0VN65LS2	124	// ( - , MBz2A2) ПС по периоду разгона  канал 2
#define R0VN65LS3	BUFFER[331]	// ( - , MBz2A3) ПС по периоду разгона канал 3
#define idR0VN65LS3	125	// ( - , MBz2A3) ПС по периоду разгона канал 3
#define R0VN65LS4	BUFFER[333]	// ( - , MBz2A4) ПС по периоду разгона канал 4
#define idR0VN65LS4	126	// ( - , MBz2A4) ПС по периоду разгона канал 4
#define R0VN65LZ2	BUFFER[335]	// ( - , Baz2) ПС по периоду разгона канал 1
#define idR0VN65LZ2	127	// ( - , Baz2) ПС по периоду разгона канал 1
#define R0VN66LZ2	BUFFER[337]	// ( - , Baz2) ПС по периоду разгона канал 2
#define idR0VN66LZ2	128	// ( - , Baz2) ПС по периоду разгона канал 2
#define R0VN67LZ2	BUFFER[339]	// ( - , Baz2) ПС по периоду разгона канал 3
#define idR0VN67LZ2	129	// ( - , Baz2) ПС по периоду разгона канал 3
#define R0VN68LZ2	BUFFER[341]	// ( - , Baz2) ПС по периоду разгона канал 4
#define idR0VN68LZ2	130	// ( - , Baz2) ПС по периоду разгона канал 4
#define R0VN69LZ2	BUFFER[343]	// ( - , Baz2) ПС по усредненному периоду
#define idR0VN69LZ2	131	// ( - , Baz2) ПС по усредненному периоду
#define R0VN70LZ2	BUFFER[345]	// ( - , Baz2) АЗ по АС мощности РУ
#define idR0VN70LZ2	132	// ( - , Baz2) АЗ по АС мощности РУ
#define R0VN71LZ2	BUFFER[347]	// (vds32:05 - K01VDSR, Baz2) АС по мощности канал 1
#define idR0VN71LZ2	133	// (vds32:05 - K01VDSR, Baz2) АС по мощности канал 1
#define R0VN72LZ2	BUFFER[349]	// (vds32:06 - K01VDSR, Baz2) АС по мощности канал 2
#define idR0VN72LZ2	134	// (vds32:06 - K01VDSR, Baz2) АС по мощности канал 2
#define R0VN73LZ2	BUFFER[351]	// (vds32:08 - K01VDSR, Baz2) АС по мощности канал 3
#define idR0VN73LZ2	135	// (vds32:08 - K01VDSR, Baz2) АС по мощности канал 3
#define R0VN74LZ2	BUFFER[353]	// (vds32:07 - K01VDSR, Baz2) АС по мощности канал 4
#define idR0VN74LZ2	136	// (vds32:07 - K01VDSR, Baz2) АС по мощности канал 4
#define R0VN75LZ2	BUFFER[355]	// (vds32:05 - K02VDSR, Baz2) АС по периоду разгона канал 1
#define idR0VN75LZ2	137	// (vds32:05 - K02VDSR, Baz2) АС по периоду разгона канал 1
#define R0VN76LZ2	BUFFER[357]	// (vds32:06 - K02VDSR, Baz2) АС по периоду разгона канал  2
#define idR0VN76LZ2	138	// (vds32:06 - K02VDSR, Baz2) АС по периоду разгона канал  2
#define R0VN77LZ2	BUFFER[359]	// (vds32:08 - K02VDSR, Baz2) АС по периоду разгона канал  3
#define idR0VN77LZ2	139	// (vds32:08 - K02VDSR, Baz2) АС по периоду разгона канал  3
#define R0VN78LZ2	BUFFER[361]	// (vds32:07 - K02VDSR, Baz2) АС по периоду разгона канал  4
#define idR0VN78LZ2	140	// (vds32:07 - K02VDSR, Baz2) АС по периоду разгона канал  4
#define R0VN79LZ2	BUFFER[363]	// ( - , Baz2) АС по усредненному периоду
#define idR0VN79LZ2	141	// ( - , Baz2) АС по усредненному периоду
#define R0VN80LZ2	BUFFER[365]	// ( - , Baz2) АЗ по АС периода разгона РУ
#define idR0VN80LZ2	142	// ( - , Baz2) АЗ по АС периода разгона РУ
#define R0VP73LZ2	BUFFER[367]	// ( - , Baz2, SBz2DU) ПС давления для РУ
#define idR0VP73LZ2	143	// ( - , Baz2, SBz2DU) ПС давления для РУ
#define R0VR02RZ2	BUFFER[369]	// ( - , Baz2) Усредненная реактивность
#define idR0VR02RZ2	144	// ( - , Baz2) Усредненная реактивность
#define R0VZ05U	BUFFER[374]	// ( - , - ) причины сброса
#define idR0VZ05U	145	// ( - , - ) причины сброса
#define R0VZ05UZ2	BUFFER[379]	// ( - , Baz2) Индикатор причины сброса
#define idR0VZ05UZ2	146	// ( - , Baz2) Индикатор причины сброса
#define R0VZ71LZ2	BUFFER[384]	// (fds16:0a - K16FDSR, Baz2, MBz2S) Обобщенный сигнал АЗ 2 канала
#define idR0VZ71LZ2	147	// (fds16:0a - K16FDSR, Baz2, MBz2S) Обобщенный сигнал АЗ 2 канала
#define R6IS66LZ2	BUFFER[386]	// (vds32:07 - K05VDSR, - ) Исправность БУ САС
#define idR6IS66LZ2	148	// (vds32:07 - K05VDSR, - ) Исправность БУ САС
#define R7II71LZ2	BUFFER[388]	// (vds32:06 - K07VDSR, - ) Сработала АС 1К IУР
#define idR7II71LZ2	149	// (vds32:06 - K07VDSR, - ) Сработала АС 1К IУР
#define R7II72LZ2	BUFFER[390]	// (vds32:07 - K06VDSR, - ) Сработала АС 2К IУР
#define idR7II72LZ2	150	// (vds32:07 - K06VDSR, - ) Сработала АС 2К IУР
#define R7II73LZ2	BUFFER[392]	// (vds32:08 - K05VDSR, - ) Сработала АС 3К IУР
#define idR7II73LZ2	151	// (vds32:08 - K05VDSR, - ) Сработала АС 3К IУР
#define R7II74LZ2	BUFFER[394]	// (vds32:06 - K08VDSR, - ) Сработала АС 1К IIУР
#define idR7II74LZ2	152	// (vds32:06 - K08VDSR, - ) Сработала АС 1К IIУР
#define R7II75LZ2	BUFFER[396]	// (vds32:07 - K07VDSR, - ) Сработала АС 2К IIУР
#define idR7II75LZ2	153	// (vds32:07 - K07VDSR, - ) Сработала АС 2К IIУР
#define R7II76LZ2	BUFFER[398]	// (vds32:08 - K06VDSR, - ) Сработала АС 3К IIУР
#define idR7II76LZ2	154	// (vds32:08 - K06VDSR, - ) Сработала АС 3К IIУР
#define R7II81LZ2	BUFFER[400]	// ( - , Baz2) Сработала АС IУР
#define idR7II81LZ2	155	// ( - , Baz2) Сработала АС IУР
#define R7II82LZ2	BUFFER[402]	// ( - , Baz2) Сработала АС IIУР
#define idR7II82LZ2	156	// ( - , Baz2) Сработала АС IIУР
#define TTLBaz2	BUFFER[404]	// ( - , Baz2) ttl
#define idTTLBaz2	157	// ( - , Baz2) ttl
#define TestDiagnBaz2	BUFFER[407]	// ( - , Baz2) Неисправность от
#define idTestDiagnBaz2	158	// ( - , Baz2) Неисправность от
#define bFirstEnterFlag	BUFFER[409]	// (bFirstEnterFlag) 
#define idbFirstEnterFlag	159	// (bFirstEnterFlag) 
#define fEM_A2UP03RZZ	BUFFER[411]	// (A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define idfEM_A2UP03RZZ	160	// (A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define fEM_A2UP04RZZ	BUFFER[416]	// (A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define idfEM_A2UP04RZZ	161	// (A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define fEM_A2UP41RZZ	BUFFER[421]	// (A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define idfEM_A2UP41RZZ	162	// (A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define fEM_A2UP42RZZ	BUFFER[426]	// (A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define idfEM_A2UP42RZZ	163	// (A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define fEM_A2UP51RZZ	BUFFER[431]	// (A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define idfEM_A2UP51RZZ	164	// (A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define fEM_A2UP52RZZ	BUFFER[436]	// (A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define idfEM_A2UP52RZZ	165	// (A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define fEM_A2UP81RZZ	BUFFER[441]	// (A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP81RZZ	166	// (A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP82RZZ	BUFFER[446]	// (A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP82RZZ	167	// (A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP83RZZ	BUFFER[451]	// (A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP83RZZ	168	// (A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP84RZZ	BUFFER[456]	// (A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP84RZZ	169	// (A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_R0UL05RDU	BUFFER[461]	// (R0UL05RDU) Время задержки АЗ от НУП ИС(сек)
#define idfEM_R0UL05RDU	170	// (R0UL05RDU) Время задержки АЗ от НУП ИС(сек)
#define fEM_R0UL07RDU	BUFFER[466]	// (R0UL07RDU) Время задержки  срабатывания АС II УР
#define idfEM_R0UL07RDU	171	// (R0UL07RDU) Время задержки  срабатывания АС II УР
#define fEM_R0UL25RDU	BUFFER[471]	// (R0UL25RDU) Время задержки АЗ от ВУ ИС сек
#define idfEM_R0UL25RDU	172	// (R0UL25RDU) Время задержки АЗ от ВУ ИС сек
#define fEM_R0UR01RZZ	BUFFER[476]	// (R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RZZ	173	// (R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R0UR04RZZ	BUFFER[481]	// (R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define idfEM_R0UR04RZZ	174	// (R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define fEM_R0UT01RZZ	BUFFER[486]	// (R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	175	// (R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_R0UT02RZZ	BUFFER[491]	// (R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	176	// (R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT61RZZ	BUFFER[496]	// (R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	177	// (R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	BUFFER[501]	// (R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	178	// (R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	BUFFER[506]	// (R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	179	// (R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT72RZZ	BUFFER[511]	// (R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	180	// (R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define internal1_m106_y1	BUFFER[516]	// (internal1_m106_y1) y1 - внутренний параметр
#define idinternal1_m106_y1	181	// (internal1_m106_y1) y1 - внутренний параметр
#define internal1_m108_y1	BUFFER[518]	// (internal1_m108_y1) y1 - внутренний параметр
#define idinternal1_m108_y1	182	// (internal1_m108_y1) y1 - внутренний параметр
#define internal1_m111_tx	BUFFER[520]	// (internal1_m111_tx) tx - время накопленное сек
#define idinternal1_m111_tx	183	// (internal1_m111_tx) tx - время накопленное сек
#define internal1_m111_y0	BUFFER[525]	// (internal1_m111_y0) y0
#define idinternal1_m111_y0	184	// (internal1_m111_y0) y0
#define internal1_m112_tx	BUFFER[527]	// (internal1_m112_tx) tx - время накопленное сек
#define idinternal1_m112_tx	185	// (internal1_m112_tx) tx - время накопленное сек
#define internal1_m112_y0	BUFFER[532]	// (internal1_m112_y0) y0
#define idinternal1_m112_y0	186	// (internal1_m112_y0) y0
#define internal1_m113_tx	BUFFER[534]	// (internal1_m113_tx) tx - время накопленное сек
#define idinternal1_m113_tx	187	// (internal1_m113_tx) tx - время накопленное сек
#define internal1_m113_y0	BUFFER[539]	// (internal1_m113_y0) y0
#define idinternal1_m113_y0	188	// (internal1_m113_y0) y0
#define internal1_m120_y1	BUFFER[541]	// (internal1_m120_y1) y1 - внутренний параметр
#define idinternal1_m120_y1	189	// (internal1_m120_y1) y1 - внутренний параметр
#define internal1_m125_y0	BUFFER[543]	// (internal1_m125_y0) state
#define idinternal1_m125_y0	190	// (internal1_m125_y0) state
#define internal1_m131_y0	BUFFER[545]	// (internal1_m131_y0) state
#define idinternal1_m131_y0	191	// (internal1_m131_y0) state
#define internal1_m140_tx	BUFFER[547]	// (internal1_m140_tx) tx - время накопленное сек
#define idinternal1_m140_tx	192	// (internal1_m140_tx) tx - время накопленное сек
#define internal1_m140_y0	BUFFER[552]	// (internal1_m140_y0) y0
#define idinternal1_m140_y0	193	// (internal1_m140_y0) y0
#define internal1_m141_tx	BUFFER[554]	// (internal1_m141_tx) tx - время накопленное сек
#define idinternal1_m141_tx	194	// (internal1_m141_tx) tx - время накопленное сек
#define internal1_m141_y0	BUFFER[559]	// (internal1_m141_y0) y0
#define idinternal1_m141_y0	195	// (internal1_m141_y0) y0
#define internal1_m149_y0	BUFFER[561]	// (internal1_m149_y0) y0
#define idinternal1_m149_y0	196	// (internal1_m149_y0) y0
#define internal1_m151_y0	BUFFER[566]	// (internal1_m151_y0) y0
#define idinternal1_m151_y0	197	// (internal1_m151_y0) y0
#define internal1_m161_y1	BUFFER[571]	// (internal1_m161_y1) y1 - внутренний параметр
#define idinternal1_m161_y1	198	// (internal1_m161_y1) y1 - внутренний параметр
#define internal1_m162_y1	BUFFER[573]	// (internal1_m162_y1) y1 - внутренний параметр
#define idinternal1_m162_y1	199	// (internal1_m162_y1) y1 - внутренний параметр
#define internal1_m169_y1	BUFFER[575]	// (internal1_m169_y1) y1 - внутренний параметр
#define idinternal1_m169_y1	200	// (internal1_m169_y1) y1 - внутренний параметр
#define internal1_m173_y1	BUFFER[577]	// (internal1_m173_y1) y1 - внутренний параметр
#define idinternal1_m173_y1	201	// (internal1_m173_y1) y1 - внутренний параметр
#define internal1_m206_TImAZ2UR	BUFFER[579]	// (internal1_m206_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
#define idinternal1_m206_TImAZ2UR	202	// (internal1_m206_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
#define internal1_m206_TImNupIs	BUFFER[584]	// (internal1_m206_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
#define idinternal1_m206_TImNupIs	203	// (internal1_m206_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
#define internal1_m206_TImVuIs	BUFFER[589]	// (internal1_m206_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
#define idinternal1_m206_TImVuIs	204	// (internal1_m206_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
#define internal1_m206_TNupIs1	BUFFER[594]	// (internal1_m206_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
#define idinternal1_m206_TNupIs1	205	// (internal1_m206_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
#define internal1_m206_TNupIs2	BUFFER[599]	// (internal1_m206_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
#define idinternal1_m206_TNupIs2	206	// (internal1_m206_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
#define internal1_m206_TVuIs1	BUFFER[604]	// (internal1_m206_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
#define idinternal1_m206_TVuIs1	207	// (internal1_m206_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
#define internal1_m206_TVuIs2	BUFFER[609]	// (internal1_m206_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
#define idinternal1_m206_TVuIs2	208	// (internal1_m206_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
#define internal1_m206_fef	BUFFER[614]	// (internal1_m206_fef) fef
#define idinternal1_m206_fef	209	// (internal1_m206_fef) fef
#define internal1_m211_tx	BUFFER[616]	// (internal1_m211_tx) tx - время накопленное сек
#define idinternal1_m211_tx	210	// (internal1_m211_tx) tx - время накопленное сек
#define internal1_m211_y0	BUFFER[621]	// (internal1_m211_y0) y0
#define idinternal1_m211_y0	211	// (internal1_m211_y0) y0
#define internal1_m215_tx	BUFFER[623]	// (internal1_m215_tx) tx - время накопленное сек
#define idinternal1_m215_tx	212	// (internal1_m215_tx) tx - время накопленное сек
#define internal1_m215_y0	BUFFER[628]	// (internal1_m215_y0) y0
#define idinternal1_m215_y0	213	// (internal1_m215_y0) y0
#define internal1_m228_tx	BUFFER[630]	// (internal1_m228_tx) tx - время накопленное сек
#define idinternal1_m228_tx	214	// (internal1_m228_tx) tx - время накопленное сек
#define internal1_m228_y0	BUFFER[635]	// (internal1_m228_y0) y0
#define idinternal1_m228_y0	215	// (internal1_m228_y0) y0
#define internal1_m284_q0	BUFFER[637]	// (internal1_m284_q0) q0 - внутренний параметр
#define idinternal1_m284_q0	216	// (internal1_m284_q0) q0 - внутренний параметр
#define internal1_m30_tx	BUFFER[642]	// (internal1_m30_tx) tx - внутренний параметр
#define idinternal1_m30_tx	217	// (internal1_m30_tx) tx - внутренний параметр
#define internal1_m91_y0	BUFFER[645]	// (internal1_m91_y0) y0
#define idinternal1_m91_y0	218	// (internal1_m91_y0) y0
#define internal1_m93_y0	BUFFER[650]	// (internal1_m93_y0) y0
#define idinternal1_m93_y0	219	// (internal1_m93_y0) y0
#define internal1_m95_y1	BUFFER[655]	// (internal1_m95_y1) y1 - внутренний параметр
#define idinternal1_m95_y1	220	// (internal1_m95_y1) y1 - внутренний параметр
#define internal1_m99_tx	BUFFER[657]	// (internal1_m99_tx) tx - время накопленное сек
#define idinternal1_m99_tx	221	// (internal1_m99_tx) tx - время накопленное сек
#define internal1_m99_y0	BUFFER[662]	// (internal1_m99_y0) y0
#define idinternal1_m99_y0	222	// (internal1_m99_y0) y0
#define ttlfa1	BUFFER[664]	// ( - , MBz2A1) ttlf float
#define idttlfa1	223	// ( - , MBz2A1) ttlf float
#define vainSBool	BUFFER[669]	// Внутренняя переменная vainSBool
#define idvainSBool	224	// Внутренняя переменная vainSBool
#define vainSFloat	BUFFER[671]	// Внутренняя переменная vainSFloat
#define idvainSFloat	225	// Внутренняя переменная vainSFloat
#define vainSInt	BUFFER[676]	// Внутренняя переменная vainSInt
#define idvainSInt	226	// Внутренняя переменная vainSInt
#define vainSLong	BUFFER[681]	// Внутренняя переменная vainSLong
#define idvainSLong	227	// Внутренняя переменная vainSLong
#define var1	BUFFER[690]	// Внутренняя переменная var1
#define idvar1	228	// Внутренняя переменная var1
#define var10	BUFFER[692]	// Внутренняя переменная var10
#define idvar10	229	// Внутренняя переменная var10
#define var100	BUFFER[694]	// Внутренняя переменная var100
#define idvar100	230	// Внутренняя переменная var100
#define var101	BUFFER[696]	// Внутренняя переменная var101
#define idvar101	231	// Внутренняя переменная var101
#define var102	BUFFER[698]	// Внутренняя переменная var102
#define idvar102	232	// Внутренняя переменная var102
#define var103	BUFFER[700]	// Внутренняя переменная var103
#define idvar103	233	// Внутренняя переменная var103
#define var104	BUFFER[702]	// Внутренняя переменная var104
#define idvar104	234	// Внутренняя переменная var104
#define var105	BUFFER[707]	// Внутренняя переменная var105
#define idvar105	235	// Внутренняя переменная var105
#define var106	BUFFER[712]	// Внутренняя переменная var106
#define idvar106	236	// Внутренняя переменная var106
#define var107	BUFFER[714]	// Внутренняя переменная var107
#define idvar107	237	// Внутренняя переменная var107
#define var108	BUFFER[719]	// Внутренняя переменная var108
#define idvar108	238	// Внутренняя переменная var108
#define var109	BUFFER[724]	// Внутренняя переменная var109
#define idvar109	239	// Внутренняя переменная var109
#define var11	BUFFER[726]	// Внутренняя переменная var11
#define idvar11	240	// Внутренняя переменная var11
#define var110	BUFFER[728]	// Внутренняя переменная var110
#define idvar110	241	// Внутренняя переменная var110
#define var111	BUFFER[730]	// Внутренняя переменная var111
#define idvar111	242	// Внутренняя переменная var111
#define var112	BUFFER[732]	// Внутренняя переменная var112
#define idvar112	243	// Внутренняя переменная var112
#define var113	BUFFER[734]	// Внутренняя переменная var113
#define idvar113	244	// Внутренняя переменная var113
#define var114	BUFFER[736]	// Внутренняя переменная var114
#define idvar114	245	// Внутренняя переменная var114
#define var115	BUFFER[738]	// Внутренняя переменная var115
#define idvar115	246	// Внутренняя переменная var115
#define var116	BUFFER[743]	// Внутренняя переменная var116
#define idvar116	247	// Внутренняя переменная var116
#define var117	BUFFER[752]	// Внутренняя переменная var117
#define idvar117	248	// Внутренняя переменная var117
#define var118	BUFFER[761]	// Внутренняя переменная var118
#define idvar118	249	// Внутренняя переменная var118
#define var119	BUFFER[763]	// Внутренняя переменная var119
#define idvar119	250	// Внутренняя переменная var119
#define var12	BUFFER[765]	// Внутренняя переменная var12
#define idvar12	251	// Внутренняя переменная var12
#define var120	BUFFER[767]	// Внутренняя переменная var120
#define idvar120	252	// Внутренняя переменная var120
#define var121	BUFFER[769]	// Внутренняя переменная var121
#define idvar121	253	// Внутренняя переменная var121
#define var122	BUFFER[771]	// Внутренняя переменная var122
#define idvar122	254	// Внутренняя переменная var122
#define var123	BUFFER[773]	// Внутренняя переменная var123
#define idvar123	255	// Внутренняя переменная var123
#define var124	BUFFER[775]	// Внутренняя переменная var124
#define idvar124	256	// Внутренняя переменная var124
#define var125	BUFFER[777]	// Внутренняя переменная var125
#define idvar125	257	// Внутренняя переменная var125
#define var126	BUFFER[779]	// Внутренняя переменная var126
#define idvar126	258	// Внутренняя переменная var126
#define var127	BUFFER[781]	// Внутренняя переменная var127
#define idvar127	259	// Внутренняя переменная var127
#define var128	BUFFER[786]	// Внутренняя переменная var128
#define idvar128	260	// Внутренняя переменная var128
#define var129	BUFFER[788]	// Внутренняя переменная var129
#define idvar129	261	// Внутренняя переменная var129
#define var13	BUFFER[790]	// Внутренняя переменная var13
#define idvar13	262	// Внутренняя переменная var13
#define var130	BUFFER[792]	// Внутренняя переменная var130
#define idvar130	263	// Внутренняя переменная var130
#define var131	BUFFER[797]	// Внутренняя переменная var131
#define idvar131	264	// Внутренняя переменная var131
#define var132	BUFFER[799]	// Внутренняя переменная var132
#define idvar132	265	// Внутренняя переменная var132
#define var134	BUFFER[801]	// Внутренняя переменная var134
#define idvar134	266	// Внутренняя переменная var134
#define var136	BUFFER[803]	// Внутренняя переменная var136
#define idvar136	267	// Внутренняя переменная var136
#define var137	BUFFER[805]	// Внутренняя переменная var137
#define idvar137	268	// Внутренняя переменная var137
#define var138	BUFFER[807]	// Внутренняя переменная var138
#define idvar138	269	// Внутренняя переменная var138
#define var139	BUFFER[809]	// Внутренняя переменная var139
#define idvar139	270	// Внутренняя переменная var139
#define var14	BUFFER[811]	// Внутренняя переменная var14
#define idvar14	271	// Внутренняя переменная var14
#define var140	BUFFER[813]	// Внутренняя переменная var140
#define idvar140	272	// Внутренняя переменная var140
#define var141	BUFFER[815]	// Внутренняя переменная var141
#define idvar141	273	// Внутренняя переменная var141
#define var142	BUFFER[817]	// Внутренняя переменная var142
#define idvar142	274	// Внутренняя переменная var142
#define var143	BUFFER[819]	// Внутренняя переменная var143
#define idvar143	275	// Внутренняя переменная var143
#define var144	BUFFER[821]	// Внутренняя переменная var144
#define idvar144	276	// Внутренняя переменная var144
#define var145	BUFFER[823]	// Внутренняя переменная var145
#define idvar145	277	// Внутренняя переменная var145
#define var15	BUFFER[825]	// Внутренняя переменная var15
#define idvar15	278	// Внутренняя переменная var15
#define var16	BUFFER[827]	// Внутренняя переменная var16
#define idvar16	279	// Внутренняя переменная var16
#define var17	BUFFER[829]	// Внутренняя переменная var17
#define idvar17	280	// Внутренняя переменная var17
#define var18	BUFFER[831]	// Внутренняя переменная var18
#define idvar18	281	// Внутренняя переменная var18
#define var19	BUFFER[833]	// Внутренняя переменная var19
#define idvar19	282	// Внутренняя переменная var19
#define var2	BUFFER[835]	// Внутренняя переменная var2
#define idvar2	283	// Внутренняя переменная var2
#define var20	BUFFER[837]	// Внутренняя переменная var20
#define idvar20	284	// Внутренняя переменная var20
#define var21	BUFFER[839]	// Внутренняя переменная var21
#define idvar21	285	// Внутренняя переменная var21
#define var22	BUFFER[841]	// Внутренняя переменная var22
#define idvar22	286	// Внутренняя переменная var22
#define var23	BUFFER[843]	// Внутренняя переменная var23
#define idvar23	287	// Внутренняя переменная var23
#define var24	BUFFER[845]	// Внутренняя переменная var24
#define idvar24	288	// Внутренняя переменная var24
#define var25	BUFFER[847]	// Внутренняя переменная var25
#define idvar25	289	// Внутренняя переменная var25
#define var26	BUFFER[849]	// Внутренняя переменная var26
#define idvar26	290	// Внутренняя переменная var26
#define var27	BUFFER[851]	// Внутренняя переменная var27
#define idvar27	291	// Внутренняя переменная var27
#define var28	BUFFER[853]	// Внутренняя переменная var28
#define idvar28	292	// Внутренняя переменная var28
#define var29	BUFFER[855]	// Внутренняя переменная var29
#define idvar29	293	// Внутренняя переменная var29
#define var3	BUFFER[857]	// Внутренняя переменная var3
#define idvar3	294	// Внутренняя переменная var3
#define var30	BUFFER[859]	// Внутренняя переменная var30
#define idvar30	295	// Внутренняя переменная var30
#define var31	BUFFER[861]	// Внутренняя переменная var31
#define idvar31	296	// Внутренняя переменная var31
#define var32	BUFFER[863]	// Внутренняя переменная var32
#define idvar32	297	// Внутренняя переменная var32
#define var33	BUFFER[865]	// Внутренняя переменная var33
#define idvar33	298	// Внутренняя переменная var33
#define var34	BUFFER[870]	// Внутренняя переменная var34
#define idvar34	299	// Внутренняя переменная var34
#define var35	BUFFER[872]	// Внутренняя переменная var35
#define idvar35	300	// Внутренняя переменная var35
#define var36	BUFFER[874]	// Внутренняя переменная var36
#define idvar36	301	// Внутренняя переменная var36
#define var37	BUFFER[876]	// Внутренняя переменная var37
#define idvar37	302	// Внутренняя переменная var37
#define var38	BUFFER[878]	// Внутренняя переменная var38
#define idvar38	303	// Внутренняя переменная var38
#define var39	BUFFER[880]	// Внутренняя переменная var39
#define idvar39	304	// Внутренняя переменная var39
#define var4	BUFFER[882]	// Внутренняя переменная var4
#define idvar4	305	// Внутренняя переменная var4
#define var40	BUFFER[884]	// Внутренняя переменная var40
#define idvar40	306	// Внутренняя переменная var40
#define var41	BUFFER[886]	// Внутренняя переменная var41
#define idvar41	307	// Внутренняя переменная var41
#define var42	BUFFER[888]	// Внутренняя переменная var42
#define idvar42	308	// Внутренняя переменная var42
#define var43	BUFFER[890]	// Внутренняя переменная var43
#define idvar43	309	// Внутренняя переменная var43
#define var44	BUFFER[892]	// Внутренняя переменная var44
#define idvar44	310	// Внутренняя переменная var44
#define var45	BUFFER[894]	// Внутренняя переменная var45
#define idvar45	311	// Внутренняя переменная var45
#define var46	BUFFER[896]	// Внутренняя переменная var46
#define idvar46	312	// Внутренняя переменная var46
#define var47	BUFFER[898]	// Внутренняя переменная var47
#define idvar47	313	// Внутренняя переменная var47
#define var48	BUFFER[900]	// Внутренняя переменная var48
#define idvar48	314	// Внутренняя переменная var48
#define var49	BUFFER[902]	// Внутренняя переменная var49
#define idvar49	315	// Внутренняя переменная var49
#define var5	BUFFER[904]	// Внутренняя переменная var5
#define idvar5	316	// Внутренняя переменная var5
#define var50	BUFFER[906]	// Внутренняя переменная var50
#define idvar50	317	// Внутренняя переменная var50
#define var51	BUFFER[908]	// Внутренняя переменная var51
#define idvar51	318	// Внутренняя переменная var51
#define var52	BUFFER[910]	// Внутренняя переменная var52
#define idvar52	319	// Внутренняя переменная var52
#define var53	BUFFER[912]	// Внутренняя переменная var53
#define idvar53	320	// Внутренняя переменная var53
#define var54	BUFFER[914]	// Внутренняя переменная var54
#define idvar54	321	// Внутренняя переменная var54
#define var55	BUFFER[916]	// Внутренняя переменная var55
#define idvar55	322	// Внутренняя переменная var55
#define var56	BUFFER[918]	// Внутренняя переменная var56
#define idvar56	323	// Внутренняя переменная var56
#define var57	BUFFER[920]	// Внутренняя переменная var57
#define idvar57	324	// Внутренняя переменная var57
#define var58	BUFFER[922]	// Внутренняя переменная var58
#define idvar58	325	// Внутренняя переменная var58
#define var59	BUFFER[924]	// Внутренняя переменная var59
#define idvar59	326	// Внутренняя переменная var59
#define var6	BUFFER[926]	// Внутренняя переменная var6
#define idvar6	327	// Внутренняя переменная var6
#define var60	BUFFER[928]	// Внутренняя переменная var60
#define idvar60	328	// Внутренняя переменная var60
#define var61	BUFFER[930]	// Внутренняя переменная var61
#define idvar61	329	// Внутренняя переменная var61
#define var62	BUFFER[932]	// Внутренняя переменная var62
#define idvar62	330	// Внутренняя переменная var62
#define var63	BUFFER[934]	// Внутренняя переменная var63
#define idvar63	331	// Внутренняя переменная var63
#define var64	BUFFER[936]	// Внутренняя переменная var64
#define idvar64	332	// Внутренняя переменная var64
#define var65	BUFFER[938]	// Внутренняя переменная var65
#define idvar65	333	// Внутренняя переменная var65
#define var66	BUFFER[940]	// Внутренняя переменная var66
#define idvar66	334	// Внутренняя переменная var66
#define var67	BUFFER[942]	// Внутренняя переменная var67
#define idvar67	335	// Внутренняя переменная var67
#define var68	BUFFER[944]	// Внутренняя переменная var68
#define idvar68	336	// Внутренняя переменная var68
#define var69	BUFFER[946]	// Внутренняя переменная var69
#define idvar69	337	// Внутренняя переменная var69
#define var7	BUFFER[948]	// Внутренняя переменная var7
#define idvar7	338	// Внутренняя переменная var7
#define var70	BUFFER[950]	// Внутренняя переменная var70
#define idvar70	339	// Внутренняя переменная var70
#define var71	BUFFER[952]	// Внутренняя переменная var71
#define idvar71	340	// Внутренняя переменная var71
#define var72	BUFFER[954]	// Внутренняя переменная var72
#define idvar72	341	// Внутренняя переменная var72
#define var73	BUFFER[956]	// Внутренняя переменная var73
#define idvar73	342	// Внутренняя переменная var73
#define var74	BUFFER[958]	// Внутренняя переменная var74
#define idvar74	343	// Внутренняя переменная var74
#define var75	BUFFER[960]	// Внутренняя переменная var75
#define idvar75	344	// Внутренняя переменная var75
#define var76	BUFFER[962]	// Внутренняя переменная var76
#define idvar76	345	// Внутренняя переменная var76
#define var77	BUFFER[964]	// Внутренняя переменная var77
#define idvar77	346	// Внутренняя переменная var77
#define var78	BUFFER[966]	// Внутренняя переменная var78
#define idvar78	347	// Внутренняя переменная var78
#define var79	BUFFER[968]	// Внутренняя переменная var79
#define idvar79	348	// Внутренняя переменная var79
#define var8	BUFFER[970]	// Внутренняя переменная var8
#define idvar8	349	// Внутренняя переменная var8
#define var80	BUFFER[972]	// Внутренняя переменная var80
#define idvar80	350	// Внутренняя переменная var80
#define var81	BUFFER[974]	// Внутренняя переменная var81
#define idvar81	351	// Внутренняя переменная var81
#define var82	BUFFER[976]	// Внутренняя переменная var82
#define idvar82	352	// Внутренняя переменная var82
#define var83	BUFFER[978]	// Внутренняя переменная var83
#define idvar83	353	// Внутренняя переменная var83
#define var84	BUFFER[980]	// Внутренняя переменная var84
#define idvar84	354	// Внутренняя переменная var84
#define var85	BUFFER[982]	// Внутренняя переменная var85
#define idvar85	355	// Внутренняя переменная var85
#define var86	BUFFER[984]	// Внутренняя переменная var86
#define idvar86	356	// Внутренняя переменная var86
#define var87	BUFFER[986]	// Внутренняя переменная var87
#define idvar87	357	// Внутренняя переменная var87
#define var88	BUFFER[988]	// Внутренняя переменная var88
#define idvar88	358	// Внутренняя переменная var88
#define var89	BUFFER[990]	// Внутренняя переменная var89
#define idvar89	359	// Внутренняя переменная var89
#define var9	BUFFER[992]	// Внутренняя переменная var9
#define idvar9	360	// Внутренняя переменная var9
#define var90	BUFFER[994]	// Внутренняя переменная var90
#define idvar90	361	// Внутренняя переменная var90
#define var91	BUFFER[996]	// Внутренняя переменная var91
#define idvar91	362	// Внутренняя переменная var91
#define var92	BUFFER[998]	// Внутренняя переменная var92
#define idvar92	363	// Внутренняя переменная var92
#define var93	BUFFER[1000]	// Внутренняя переменная var93
#define idvar93	364	// Внутренняя переменная var93
#define var94	BUFFER[1002]	// Внутренняя переменная var94
#define idvar94	365	// Внутренняя переменная var94
#define var95	BUFFER[1004]	// Внутренняя переменная var95
#define idvar95	366	// Внутренняя переменная var95
#define var96	BUFFER[1006]	// Внутренняя переменная var96
#define idvar96	367	// Внутренняя переменная var96
#define var97	BUFFER[1008]	// Внутренняя переменная var97
#define idvar97	368	// Внутренняя переменная var97
#define var98	BUFFER[1010]	// Внутренняя переменная var98
#define idvar98	369	// Внутренняя переменная var98
#define var99	BUFFER[1012]	// Внутренняя переменная var99
#define idvar99	370	// Внутренняя переменная var99
#pragma pack(push,1)
static VarCtrl allVariables[]={ 			 //Описание всех переменных
	{1	,8	,1	,&A0CT01IZ2},	//( - , Baz2, SBz2DU) Температура АЗ1-1
	{2	,1	,1	,&A0EE00LZ2},	//( - , Baz2) Исправность АКНП АЗ1
	{3	,1	,1	,&A0EE01LZ2},	//( - , Baz2, SBz2DU) Исправность АКНП1
	{4	,1	,1	,&A0EE02LZ2},	//( - , Baz2, SBz2DU) Исправность АКНП2
	{5	,1	,1	,&A0EE03LZ2},	//( - , Baz2, SBz2DU) Исправность АКНП3
	{6	,1	,1	,&A0EE04LZ2},	//( - , Baz2, SBz2DU) Исправность АКНП4
	{7	,1	,1	,&A0EE05LZ2},	//( - , Baz2) Исправность сети АКНП1
	{8	,1	,1	,&A0EE06LZ2},	//( - , Baz2) Исправность сети АКНП2
	{9	,1	,1	,&A0EE07LZ2},	//( - , Baz2) Исправность сети АКНП3
	{10	,1	,1	,&A0EE08LZ2},	//( - , Baz2) Исправность сети АКНП4
	{11	,3	,1	,&A0EP02IZ2},	//( - , Baz2) Индикатор -Давление  АЗ1 ниже АС
	{12	,3	,1	,&A0IT02IZ2},	//(vas84:04 - K01VASR, Baz2) Температура АЗ1-2
	{13	,1	,1	,&A0VN71LZ2},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ1
	{14	,1	,1	,&A0VN81LZ2},	//( - , Baz2) АЗ по АС периода разгона АЗ1
	{15	,1	,1	,&A0VP41LZ2},	//( - , Baz2) Давление АЗ1 ниже АС
	{16	,1	,1	,&A0VP71LZ2},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
	{17	,1	,1	,&A0VP81LZZ},	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
	{18	,1	,1	,&A0VT61LZ2},	//( - , Baz2) ПС по температуре в АЗ1
	{19	,1	,1	,&A0VT71LZ2},	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
	{20	,1	,1	,&A0VZ71LZ2},	//( - , Baz2) Обобщенный сигнал АС по АЗ1
	{21	,1	,1	,&A1EE01LS1},	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
	{22	,1	,1	,&A1EE01LS2},	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
	{23	,1	,1	,&A1EE01LS3},	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
	{24	,1	,1	,&A1EE01LS4},	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
	{25	,1	,1	,&A1VN71LS1},	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
	{26	,1	,1	,&A1VN71LS2},	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
	{27	,1	,1	,&A1VN71LS3},	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
	{28	,1	,1	,&A1VN71LS4},	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
	{29	,1	,1	,&A1VN71LZ2},	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
	{30	,1	,1	,&A1VP41LZ2},	//( - , Baz2, SBz2DU) Давление СБРОС ББ1 ниже АС
	{31	,1	,1	,&A1VP81LZZ},	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
	{32	,8	,1	,&A2CP01RZ2},	//( - , Baz2) Текущее давление СБРОС РБ1
	{33	,3	,1	,&A2IP01IZ2},	//(vas84:04 - K02VASR, Baz2) Текущее давление СБРОС РБ1
	{34	,1	,1	,&A2IS12LDU},	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
	{35	,1	,1	,&A2VP41LZ2},	//( - , Baz2) Давление СБРОС РБ1 ниже АС
	{36	,1	,1	,&A2VP51LZ2},	//( - , Baz2) Давление СБРОС РБ1 ниже ПС
	{37	,1	,1	,&A2VP81LZ2},	//( - , Baz2) Давление СБРОС РБ1 в норме
	{38	,1	,1	,&A3IS11LDU},	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
	{39	,1	,1	,&A3IS22LDU},	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
	{40	,1	,1	,&A3VZ11LZ2},	//( - , Baz2) АЗ от НУП ИС1
	{41	,1	,1	,&A3VZ13LZ2},	//(fds16:0a - K01FDSR, Baz2) Имитация АЗ от ВУ ИС
	{42	,1	,1	,&A3VZ15LZ2},	//(fds16:0a - K02FDSR, Baz2) Имитация АЗ от НУП ИС
	{43	,1	,1	,&A3VZ31LZ2},	//( - , Baz2) АЗ от ВУ ИС1
	{44	,8	,1	,&B0CT01IZ2},	//( - , Baz2, SBz2DU) Температура АЗ2-1
	{45	,1	,1	,&B0EE00LZ2},	//( - , Baz2) Исправность АКНП АЗ2
	{46	,3	,1	,&B0EP02IZ2},	//( - , Baz2) Индикатор -Давление  АЗ2 ниже АС
	{47	,3	,1	,&B0IT02IZ2},	//(vas84:04 - K03VASR, Baz2) Температура АЗ2-2
	{48	,1	,1	,&B0VN71LZ2},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ2
	{49	,1	,1	,&B0VN81LZ2},	//( - , Baz2) АЗ по АС периода разгона АЗ2
	{50	,1	,1	,&B0VP41LZ2},	//( - , Baz2) Давление АЗ2 ниже АС
	{51	,1	,1	,&B0VP71LZ2},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
	{52	,1	,1	,&B0VP81LZZ},	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
	{53	,1	,1	,&B0VT61LZ2},	//( - , Baz2) ПС по температуре в АЗ2
	{54	,1	,1	,&B0VT71LZ2},	//( - , Baz2, SBz2DU) АС по температуре в АЗ2
	{55	,1	,1	,&B0VZ71LZ2},	//( - , Baz2) Обобщенный сигнал АС по АЗ2
	{56	,1	,1	,&B1VP41LZ2},	//( - , Baz2, SBz2DU) Давление СБРОС ББ2 ниже АС
	{57	,1	,1	,&B1VP81LZZ},	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
	{58	,8	,1	,&B2CP01RZ2},	//( - , Baz2) Текущее давление СБРОС РБ2
	{59	,3	,1	,&B2IP01IZ2},	//(vas84:04 - K04VASR, Baz2) Текущее давление СБРОС РБ2
	{60	,1	,1	,&B2IS12LDU},	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
	{61	,1	,1	,&B2VP41LZ2},	//( - , Baz2) Давление СБРОС РБ2 ниже АС
	{62	,1	,1	,&B2VP51LZ2},	//( - , Baz2) Давление СБРОС РБ2 ниже ПС
	{63	,1	,1	,&B2VP81LZ2},	//( - , Baz2) Давление СБРОС РБ2 в норме
	{64	,1	,1	,&B3IS11LDU},	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
	{65	,1	,1	,&B3IS22LDU},	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
	{66	,1	,1	,&B3VZ11LZ2},	//( - , Baz2) АЗ от НУП ИС2
	{67	,1	,1	,&B3VZ31LZ2},	//( - , Baz2) АЗ от ВУ ИС2
	{68	,8	,1	,&B8VC01RDU},	//( - , SBz2DU, MBz2A1, MBz2A2, MBz2A3, MBz2A4) Координата АЗ2, мм
	{69	,1	,1	,&R0AD03LZ2},	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
	{70	,1	,1	,&R0AD04LZ2},	//(vds32:05 - K08VDSR, - ) Имитация срабатывания АС II УР рад (БАЗ2)
	{71	,1	,1	,&R0AD05LZ2},	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
	{72	,1	,1	,&R0AD14LZ2},	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
	{73	,1	,1	,&R0AD21LDU},	//( - , SBz2DU) Подключить защиту от II УР
	{74	,3	,1	,&R0DE04LZ2},	//(vas84:04 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 4 месте
	{75	,3	,1	,&R0DE05LZ2},	//(vds32:05 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 5 месте
	{76	,3	,1	,&R0DE06LZ2},	//(vds32:06 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 6 месте
	{77	,3	,1	,&R0DE07LZ2},	//(vds32:07 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 7 месте
	{78	,3	,1	,&R0DE08LZ2},	//(vds32:08 - Diagn, DiagnBaz2) диагностика модуля Баз2 на 8 месте
	{79	,3	,1	,&R0DE0ALZ2},	//(fds16:0a - Diagn, DiagnBaz2) диагностика модуля Баз2 на 10 месте
	{80	,1	,1	,&R0DE3CLZ2},	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 5
	{81	,1	,1	,&R0DE3DLZ2},	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 6
	{82	,1	,1	,&R0DEB1LZ2},	//(sbk:20 - S10SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 5
	{83	,1	,1	,&R0DEB2LZ2},	//(sbk:20 - S11SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 5
	{84	,1	,1	,&R0DEB3LZ2},	//(sbk:20 - S12SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 6
	{85	,1	,1	,&R0DEB4LZ2},	//(sbk:20 - S13SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 6
	{86	,1	,1	,&R0EE01LZ2},	//( - , MBz2S) Питание  АКНП1  отключить
	{87	,1	,1	,&R0EE02LDU},	//( - , Baz2, SBz2DU) Питание  АКНП  отключить
	{88	,1	,1	,&R0EE02LZ2},	//( - , MBz2S) Питание  АКНП2  отключить
	{89	,1	,1	,&R0EE03LZ2},	//( - , MBz2S) Питание  АКНП3  отключить
	{90	,1	,1	,&R0EE04LZ2},	//( - , MBz2S) Питание  АКНП4  отключить
	{91	,1	,1	,&R0ET01LZ2},	//( - , Baz2) Признак наличия неисправности по температуре  АЗ1
	{92	,1	,1	,&R0ET02LZ2},	//( - , Baz2) Признак наличия неисправности по температуре АЗ2
	{93	,1	,1	,&R0MD34LP1},	//( - , Baz2) Кнопка Квитировать
	{94	,3	,1	,&R0MW11IP1},	//( - , Baz2) Переключатель ВЫСТРЕЛ
	{95	,3	,1	,&R0MW12IP2},	//( - , Baz2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{96	,1	,1	,&R0S01LZ2},	//(vds32:08 - K08VDSR, - ) Отключение сетевых передач в Баз2
	{97	,8	,1	,&R0VN01RS1},	//( - , MBz2A1) Период разгона канал 1
	{98	,8	,1	,&R0VN01RS2},	//( - , MBz2A2) Период разгона канал 2
	{99	,8	,1	,&R0VN01RS3},	//( - , MBz2A3) Период разгона канал 3
	{100	,8	,1	,&R0VN01RS4},	//( - , MBz2A4) Период разгона канал 4
	{101	,8	,1	,&R0VN01RZ2},	//( - , Baz2) Уровень мощности по каналу 1
	{102	,8	,1	,&R0VN02RS1},	//( - , MBz2A1) Уровень мощности канал 1
	{103	,8	,1	,&R0VN02RS2},	//( - , MBz2A2) Уровень мощности канал 2
	{104	,8	,1	,&R0VN02RS3},	//( - , MBz2A3) Уровень мощности канал 3
	{105	,8	,1	,&R0VN02RS4},	//( - , MBz2A4) Уровень мощности канал 4
	{106	,8	,1	,&R0VN02RZ2},	//( - , Baz2) Уровень мощности по каналу 2
	{107	,8	,1	,&R0VN03RZ2},	//( - , Baz2) Уровень мощности по каналу 3
	{108	,8	,1	,&R0VN04RZ2},	//( - , Baz2) Уровень мощности по каналу 4
	{109	,8	,1	,&R0VN05RZ2},	//( - , Baz2) Период разгона по каналу 1
	{110	,8	,1	,&R0VN06RZ2},	//( - , Baz2) Период разгона по каналу 2
	{111	,8	,1	,&R0VN07RZ2},	//( - , Baz2) Период разгона по каналу 3
	{112	,8	,1	,&R0VN08RZ2},	//( - , Baz2) Период разгона по каналу 4
	{113	,8	,1	,&R0VN09RZ2},	//( - , Baz2) Усредненный период разгона
	{114	,8	,1	,&R0VN11RZ2},	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ2
	{115	,1	,1	,&R0VN61LS1},	//( - , MBz2A1) ПС по мощности канал 1
	{116	,1	,1	,&R0VN61LS2},	//( - , MBz2A2) ПС по мощности канал 2
	{117	,1	,1	,&R0VN61LS3},	//( - , MBz2A3) ПС по мощности канал 3
	{118	,1	,1	,&R0VN61LS4},	//( - , MBz2A4) ПС по мощности канал 4
	{119	,1	,1	,&R0VN61LZ2},	//( - , Baz2) ПС по мощности канал 1
	{120	,1	,1	,&R0VN62LZ2},	//( - , Baz2) ПС по мощности канал 2
	{121	,1	,1	,&R0VN63LZ2},	//( - , Baz2) ПС по мощности канал 3
	{122	,1	,1	,&R0VN64LZ2},	//( - , Baz2) ПС по мощности канал 4
	{123	,1	,1	,&R0VN65LS1},	//( - , MBz2A1) ПС по периоду разгона канал 1
	{124	,1	,1	,&R0VN65LS2},	//( - , MBz2A2) ПС по периоду разгона  канал 2
	{125	,1	,1	,&R0VN65LS3},	//( - , MBz2A3) ПС по периоду разгона канал 3
	{126	,1	,1	,&R0VN65LS4},	//( - , MBz2A4) ПС по периоду разгона канал 4
	{127	,1	,1	,&R0VN65LZ2},	//( - , Baz2) ПС по периоду разгона канал 1
	{128	,1	,1	,&R0VN66LZ2},	//( - , Baz2) ПС по периоду разгона канал 2
	{129	,1	,1	,&R0VN67LZ2},	//( - , Baz2) ПС по периоду разгона канал 3
	{130	,1	,1	,&R0VN68LZ2},	//( - , Baz2) ПС по периоду разгона канал 4
	{131	,1	,1	,&R0VN69LZ2},	//( - , Baz2) ПС по усредненному периоду
	{132	,1	,1	,&R0VN70LZ2},	//( - , Baz2) АЗ по АС мощности РУ
	{133	,1	,1	,&R0VN71LZ2},	//(vds32:05 - K01VDSR, Baz2) АС по мощности канал 1
	{134	,1	,1	,&R0VN72LZ2},	//(vds32:06 - K01VDSR, Baz2) АС по мощности канал 2
	{135	,1	,1	,&R0VN73LZ2},	//(vds32:08 - K01VDSR, Baz2) АС по мощности канал 3
	{136	,1	,1	,&R0VN74LZ2},	//(vds32:07 - K01VDSR, Baz2) АС по мощности канал 4
	{137	,1	,1	,&R0VN75LZ2},	//(vds32:05 - K02VDSR, Baz2) АС по периоду разгона канал 1
	{138	,1	,1	,&R0VN76LZ2},	//(vds32:06 - K02VDSR, Baz2) АС по периоду разгона канал  2
	{139	,1	,1	,&R0VN77LZ2},	//(vds32:08 - K02VDSR, Baz2) АС по периоду разгона канал  3
	{140	,1	,1	,&R0VN78LZ2},	//(vds32:07 - K02VDSR, Baz2) АС по периоду разгона канал  4
	{141	,1	,1	,&R0VN79LZ2},	//( - , Baz2) АС по усредненному периоду
	{142	,1	,1	,&R0VN80LZ2},	//( - , Baz2) АЗ по АС периода разгона РУ
	{143	,1	,1	,&R0VP73LZ2},	//( - , Baz2, SBz2DU) ПС давления для РУ
	{144	,8	,1	,&R0VR02RZ2},	//( - , Baz2) Усредненная реактивность
	{145	,5	,1	,&R0VZ05U},	//( - , - ) причины сброса
	{146	,5	,1	,&R0VZ05UZ2},	//( - , Baz2) Индикатор причины сброса
	{147	,1	,1	,&R0VZ71LZ2},	//(fds16:0a - K16FDSR, Baz2, MBz2S) Обобщенный сигнал АЗ 2 канала
	{148	,1	,1	,&R6IS66LZ2},	//(vds32:07 - K05VDSR, - ) Исправность БУ САС
	{149	,1	,1	,&R7II71LZ2},	//(vds32:06 - K07VDSR, - ) Сработала АС 1К IУР
	{150	,1	,1	,&R7II72LZ2},	//(vds32:07 - K06VDSR, - ) Сработала АС 2К IУР
	{151	,1	,1	,&R7II73LZ2},	//(vds32:08 - K05VDSR, - ) Сработала АС 3К IУР
	{152	,1	,1	,&R7II74LZ2},	//(vds32:06 - K08VDSR, - ) Сработала АС 1К IIУР
	{153	,1	,1	,&R7II75LZ2},	//(vds32:07 - K07VDSR, - ) Сработала АС 2К IIУР
	{154	,1	,1	,&R7II76LZ2},	//(vds32:08 - K06VDSR, - ) Сработала АС 3К IIУР
	{155	,1	,1	,&R7II81LZ2},	//( - , Baz2) Сработала АС IУР
	{156	,1	,1	,&R7II82LZ2},	//( - , Baz2) Сработала АС IIУР
	{157	,3	,1	,&TTLBaz2},	//( - , Baz2) ttl
	{158	,1	,1	,&TestDiagnBaz2},	//( - , Baz2) Неисправность от
	{159	,1	,1	,&bFirstEnterFlag},	//(bFirstEnterFlag) 
	{160	,8	,1	,&fEM_A2UP03RZZ},	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{161	,8	,1	,&fEM_A2UP04RZZ},	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{162	,8	,1	,&fEM_A2UP41RZZ},	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{163	,8	,1	,&fEM_A2UP42RZZ},	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{164	,8	,1	,&fEM_A2UP51RZZ},	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{165	,8	,1	,&fEM_A2UP52RZZ},	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{166	,8	,1	,&fEM_A2UP81RZZ},	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{167	,8	,1	,&fEM_A2UP82RZZ},	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{168	,8	,1	,&fEM_A2UP83RZZ},	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{169	,8	,1	,&fEM_A2UP84RZZ},	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{170	,8	,1	,&fEM_R0UL05RDU},	//(R0UL05RDU) Время задержки АЗ от НУП ИС(сек)
	{171	,8	,1	,&fEM_R0UL07RDU},	//(R0UL07RDU) Время задержки  срабатывания АС II УР
	{172	,8	,1	,&fEM_R0UL25RDU},	//(R0UL25RDU) Время задержки АЗ от ВУ ИС сек
	{173	,8	,1	,&fEM_R0UR01RZZ},	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
	{174	,8	,1	,&fEM_R0UR04RZZ},	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
	{175	,8	,1	,&fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{176	,8	,1	,&fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{177	,8	,1	,&fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{178	,8	,1	,&fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{179	,8	,1	,&fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{180	,8	,1	,&fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{181	,1	,1	,&internal1_m106_y1},	//(internal1_m106_y1) y1 - внутренний параметр
	{182	,1	,1	,&internal1_m108_y1},	//(internal1_m108_y1) y1 - внутренний параметр
	{183	,8	,1	,&internal1_m111_tx},	//(internal1_m111_tx) tx - время накопленное сек
	{184	,18	,1	,&internal1_m111_y0},	//(internal1_m111_y0) y0
	{185	,8	,1	,&internal1_m112_tx},	//(internal1_m112_tx) tx - время накопленное сек
	{186	,18	,1	,&internal1_m112_y0},	//(internal1_m112_y0) y0
	{187	,8	,1	,&internal1_m113_tx},	//(internal1_m113_tx) tx - время накопленное сек
	{188	,18	,1	,&internal1_m113_y0},	//(internal1_m113_y0) y0
	{189	,1	,1	,&internal1_m120_y1},	//(internal1_m120_y1) y1 - внутренний параметр
	{190	,1	,1	,&internal1_m125_y0},	//(internal1_m125_y0) state
	{191	,1	,1	,&internal1_m131_y0},	//(internal1_m131_y0) state
	{192	,8	,1	,&internal1_m140_tx},	//(internal1_m140_tx) tx - время накопленное сек
	{193	,18	,1	,&internal1_m140_y0},	//(internal1_m140_y0) y0
	{194	,8	,1	,&internal1_m141_tx},	//(internal1_m141_tx) tx - время накопленное сек
	{195	,18	,1	,&internal1_m141_y0},	//(internal1_m141_y0) y0
	{196	,8	,1	,&internal1_m149_y0},	//(internal1_m149_y0) y0
	{197	,8	,1	,&internal1_m151_y0},	//(internal1_m151_y0) y0
	{198	,1	,1	,&internal1_m161_y1},	//(internal1_m161_y1) y1 - внутренний параметр
	{199	,1	,1	,&internal1_m162_y1},	//(internal1_m162_y1) y1 - внутренний параметр
	{200	,1	,1	,&internal1_m169_y1},	//(internal1_m169_y1) y1 - внутренний параметр
	{201	,1	,1	,&internal1_m173_y1},	//(internal1_m173_y1) y1 - внутренний параметр
	{202	,8	,1	,&internal1_m206_TImAZ2UR},	//(internal1_m206_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
	{203	,8	,1	,&internal1_m206_TImNupIs},	//(internal1_m206_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
	{204	,8	,1	,&internal1_m206_TImVuIs},	//(internal1_m206_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
	{205	,8	,1	,&internal1_m206_TNupIs1},	//(internal1_m206_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
	{206	,8	,1	,&internal1_m206_TNupIs2},	//(internal1_m206_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
	{207	,8	,1	,&internal1_m206_TVuIs1},	//(internal1_m206_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
	{208	,8	,1	,&internal1_m206_TVuIs2},	//(internal1_m206_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
	{209	,1	,1	,&internal1_m206_fef},	//(internal1_m206_fef) fef
	{210	,8	,1	,&internal1_m211_tx},	//(internal1_m211_tx) tx - время накопленное сек
	{211	,18	,1	,&internal1_m211_y0},	//(internal1_m211_y0) y0
	{212	,8	,1	,&internal1_m215_tx},	//(internal1_m215_tx) tx - время накопленное сек
	{213	,18	,1	,&internal1_m215_y0},	//(internal1_m215_y0) y0
	{214	,8	,1	,&internal1_m228_tx},	//(internal1_m228_tx) tx - время накопленное сек
	{215	,18	,1	,&internal1_m228_y0},	//(internal1_m228_y0) y0
	{216	,5	,1	,&internal1_m284_q0},	//(internal1_m284_q0) q0 - внутренний параметр
	{217	,3	,1	,&internal1_m30_tx},	//(internal1_m30_tx) tx - внутренний параметр
	{218	,8	,1	,&internal1_m91_y0},	//(internal1_m91_y0) y0
	{219	,8	,1	,&internal1_m93_y0},	//(internal1_m93_y0) y0
	{220	,1	,1	,&internal1_m95_y1},	//(internal1_m95_y1) y1 - внутренний параметр
	{221	,8	,1	,&internal1_m99_tx},	//(internal1_m99_tx) tx - время накопленное сек
	{222	,18	,1	,&internal1_m99_y0},	//(internal1_m99_y0) y0
	{223	,8	,1	,&ttlfa1},	//( - , MBz2A1) ttlf float
	{224	,1	,1	,&vainSBool},	//Внутренняя переменная vainSBool
	{225	,8	,1	,&vainSFloat},	//Внутренняя переменная vainSFloat
	{226	,5	,1	,&vainSInt},	//Внутренняя переменная vainSInt
	{227	,11	,1	,&vainSLong},	//Внутренняя переменная vainSLong
	{228	,1	,1	,&var1},	//Внутренняя переменная var1
	{229	,1	,1	,&var10},	//Внутренняя переменная var10
	{230	,1	,1	,&var100},	//Внутренняя переменная var100
	{231	,1	,1	,&var101},	//Внутренняя переменная var101
	{232	,1	,1	,&var102},	//Внутренняя переменная var102
	{233	,1	,1	,&var103},	//Внутренняя переменная var103
	{234	,8	,1	,&var104},	//Внутренняя переменная var104
	{235	,8	,1	,&var105},	//Внутренняя переменная var105
	{236	,1	,1	,&var106},	//Внутренняя переменная var106
	{237	,8	,1	,&var107},	//Внутренняя переменная var107
	{238	,8	,1	,&var108},	//Внутренняя переменная var108
	{239	,1	,1	,&var109},	//Внутренняя переменная var109
	{240	,1	,1	,&var11},	//Внутренняя переменная var11
	{241	,1	,1	,&var110},	//Внутренняя переменная var110
	{242	,1	,1	,&var111},	//Внутренняя переменная var111
	{243	,1	,1	,&var112},	//Внутренняя переменная var112
	{244	,1	,1	,&var113},	//Внутренняя переменная var113
	{245	,1	,1	,&var114},	//Внутренняя переменная var114
	{246	,8	,1	,&var115},	//Внутренняя переменная var115
	{247	,11	,1	,&var116},	//Внутренняя переменная var116
	{248	,11	,1	,&var117},	//Внутренняя переменная var117
	{249	,1	,1	,&var118},	//Внутренняя переменная var118
	{250	,1	,1	,&var119},	//Внутренняя переменная var119
	{251	,1	,1	,&var12},	//Внутренняя переменная var12
	{252	,1	,1	,&var120},	//Внутренняя переменная var120
	{253	,1	,1	,&var121},	//Внутренняя переменная var121
	{254	,1	,1	,&var122},	//Внутренняя переменная var122
	{255	,1	,1	,&var123},	//Внутренняя переменная var123
	{256	,1	,1	,&var124},	//Внутренняя переменная var124
	{257	,1	,1	,&var125},	//Внутренняя переменная var125
	{258	,1	,1	,&var126},	//Внутренняя переменная var126
	{259	,8	,1	,&var127},	//Внутренняя переменная var127
	{260	,1	,1	,&var128},	//Внутренняя переменная var128
	{261	,1	,1	,&var129},	//Внутренняя переменная var129
	{262	,1	,1	,&var13},	//Внутренняя переменная var13
	{263	,8	,1	,&var130},	//Внутренняя переменная var130
	{264	,1	,1	,&var131},	//Внутренняя переменная var131
	{265	,1	,1	,&var132},	//Внутренняя переменная var132
	{266	,1	,1	,&var134},	//Внутренняя переменная var134
	{267	,1	,1	,&var136},	//Внутренняя переменная var136
	{268	,1	,1	,&var137},	//Внутренняя переменная var137
	{269	,1	,1	,&var138},	//Внутренняя переменная var138
	{270	,1	,1	,&var139},	//Внутренняя переменная var139
	{271	,1	,1	,&var14},	//Внутренняя переменная var14
	{272	,1	,1	,&var140},	//Внутренняя переменная var140
	{273	,1	,1	,&var141},	//Внутренняя переменная var141
	{274	,1	,1	,&var142},	//Внутренняя переменная var142
	{275	,1	,1	,&var143},	//Внутренняя переменная var143
	{276	,1	,1	,&var144},	//Внутренняя переменная var144
	{277	,1	,1	,&var145},	//Внутренняя переменная var145
	{278	,1	,1	,&var15},	//Внутренняя переменная var15
	{279	,1	,1	,&var16},	//Внутренняя переменная var16
	{280	,1	,1	,&var17},	//Внутренняя переменная var17
	{281	,1	,1	,&var18},	//Внутренняя переменная var18
	{282	,1	,1	,&var19},	//Внутренняя переменная var19
	{283	,1	,1	,&var2},	//Внутренняя переменная var2
	{284	,1	,1	,&var20},	//Внутренняя переменная var20
	{285	,1	,1	,&var21},	//Внутренняя переменная var21
	{286	,1	,1	,&var22},	//Внутренняя переменная var22
	{287	,1	,1	,&var23},	//Внутренняя переменная var23
	{288	,1	,1	,&var24},	//Внутренняя переменная var24
	{289	,1	,1	,&var25},	//Внутренняя переменная var25
	{290	,1	,1	,&var26},	//Внутренняя переменная var26
	{291	,1	,1	,&var27},	//Внутренняя переменная var27
	{292	,1	,1	,&var28},	//Внутренняя переменная var28
	{293	,1	,1	,&var29},	//Внутренняя переменная var29
	{294	,1	,1	,&var3},	//Внутренняя переменная var3
	{295	,1	,1	,&var30},	//Внутренняя переменная var30
	{296	,1	,1	,&var31},	//Внутренняя переменная var31
	{297	,1	,1	,&var32},	//Внутренняя переменная var32
	{298	,5	,1	,&var33},	//Внутренняя переменная var33
	{299	,1	,1	,&var34},	//Внутренняя переменная var34
	{300	,1	,1	,&var35},	//Внутренняя переменная var35
	{301	,1	,1	,&var36},	//Внутренняя переменная var36
	{302	,1	,1	,&var37},	//Внутренняя переменная var37
	{303	,1	,1	,&var38},	//Внутренняя переменная var38
	{304	,1	,1	,&var39},	//Внутренняя переменная var39
	{305	,1	,1	,&var4},	//Внутренняя переменная var4
	{306	,1	,1	,&var40},	//Внутренняя переменная var40
	{307	,1	,1	,&var41},	//Внутренняя переменная var41
	{308	,1	,1	,&var42},	//Внутренняя переменная var42
	{309	,1	,1	,&var43},	//Внутренняя переменная var43
	{310	,1	,1	,&var44},	//Внутренняя переменная var44
	{311	,1	,1	,&var45},	//Внутренняя переменная var45
	{312	,1	,1	,&var46},	//Внутренняя переменная var46
	{313	,1	,1	,&var47},	//Внутренняя переменная var47
	{314	,1	,1	,&var48},	//Внутренняя переменная var48
	{315	,1	,1	,&var49},	//Внутренняя переменная var49
	{316	,1	,1	,&var5},	//Внутренняя переменная var5
	{317	,1	,1	,&var50},	//Внутренняя переменная var50
	{318	,1	,1	,&var51},	//Внутренняя переменная var51
	{319	,1	,1	,&var52},	//Внутренняя переменная var52
	{320	,1	,1	,&var53},	//Внутренняя переменная var53
	{321	,1	,1	,&var54},	//Внутренняя переменная var54
	{322	,1	,1	,&var55},	//Внутренняя переменная var55
	{323	,1	,1	,&var56},	//Внутренняя переменная var56
	{324	,1	,1	,&var57},	//Внутренняя переменная var57
	{325	,1	,1	,&var58},	//Внутренняя переменная var58
	{326	,1	,1	,&var59},	//Внутренняя переменная var59
	{327	,1	,1	,&var6},	//Внутренняя переменная var6
	{328	,1	,1	,&var60},	//Внутренняя переменная var60
	{329	,1	,1	,&var61},	//Внутренняя переменная var61
	{330	,1	,1	,&var62},	//Внутренняя переменная var62
	{331	,1	,1	,&var63},	//Внутренняя переменная var63
	{332	,1	,1	,&var64},	//Внутренняя переменная var64
	{333	,1	,1	,&var65},	//Внутренняя переменная var65
	{334	,1	,1	,&var66},	//Внутренняя переменная var66
	{335	,1	,1	,&var67},	//Внутренняя переменная var67
	{336	,1	,1	,&var68},	//Внутренняя переменная var68
	{337	,1	,1	,&var69},	//Внутренняя переменная var69
	{338	,1	,1	,&var7},	//Внутренняя переменная var7
	{339	,1	,1	,&var70},	//Внутренняя переменная var70
	{340	,1	,1	,&var71},	//Внутренняя переменная var71
	{341	,1	,1	,&var72},	//Внутренняя переменная var72
	{342	,1	,1	,&var73},	//Внутренняя переменная var73
	{343	,1	,1	,&var74},	//Внутренняя переменная var74
	{344	,1	,1	,&var75},	//Внутренняя переменная var75
	{345	,1	,1	,&var76},	//Внутренняя переменная var76
	{346	,1	,1	,&var77},	//Внутренняя переменная var77
	{347	,1	,1	,&var78},	//Внутренняя переменная var78
	{348	,1	,1	,&var79},	//Внутренняя переменная var79
	{349	,1	,1	,&var8},	//Внутренняя переменная var8
	{350	,1	,1	,&var80},	//Внутренняя переменная var80
	{351	,1	,1	,&var81},	//Внутренняя переменная var81
	{352	,1	,1	,&var82},	//Внутренняя переменная var82
	{353	,1	,1	,&var83},	//Внутренняя переменная var83
	{354	,1	,1	,&var84},	//Внутренняя переменная var84
	{355	,1	,1	,&var85},	//Внутренняя переменная var85
	{356	,1	,1	,&var86},	//Внутренняя переменная var86
	{357	,1	,1	,&var87},	//Внутренняя переменная var87
	{358	,1	,1	,&var88},	//Внутренняя переменная var88
	{359	,1	,1	,&var89},	//Внутренняя переменная var89
	{360	,1	,1	,&var9},	//Внутренняя переменная var9
	{361	,1	,1	,&var90},	//Внутренняя переменная var90
	{362	,1	,1	,&var91},	//Внутренняя переменная var91
	{363	,1	,1	,&var92},	//Внутренняя переменная var92
	{364	,1	,1	,&var93},	//Внутренняя переменная var93
	{365	,1	,1	,&var94},	//Внутренняя переменная var94
	{366	,1	,1	,&var95},	//Внутренняя переменная var95
	{367	,1	,1	,&var96},	//Внутренняя переменная var96
	{368	,1	,1	,&var97},	//Внутренняя переменная var97
	{369	,1	,1	,&var98},	//Внутренняя переменная var98
	{370	,1	,1	,&var99},	//Внутренняя переменная var99
	{-1,0,NULL},
};
static char NameSaveFile[]="baz2.bin\0"; //Имя файла сохранения переменных
#pragma pop
static VarSaveCtrl saveVariables[]={	//Id переменных для сохранения
	{160,"fEM_A2UP03RZZ\0"},	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{161,"fEM_A2UP04RZZ\0"},	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{162,"fEM_A2UP41RZZ\0"},	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{163,"fEM_A2UP42RZZ\0"},	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{164,"fEM_A2UP51RZZ\0"},	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{165,"fEM_A2UP52RZZ\0"},	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{166,"fEM_A2UP81RZZ\0"},	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{167,"fEM_A2UP82RZZ\0"},	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{168,"fEM_A2UP83RZZ\0"},	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{169,"fEM_A2UP84RZZ\0"},	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{170,"fEM_R0UL05RDU\0"},	//(R0UL05RDU) Время задержки АЗ от НУП ИС(сек)
	{171,"fEM_R0UL07RDU\0"},	//(R0UL07RDU) Время задержки  срабатывания АС II УР
	{172,"fEM_R0UL25RDU\0"},	//(R0UL25RDU) Время задержки АЗ от ВУ ИС сек
	{173,"fEM_R0UR01RZZ\0"},	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
	{174,"fEM_R0UR04RZZ\0"},	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
	{175,"fEM_R0UT01RZZ\0"},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{176,"fEM_R0UT02RZZ\0"},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{177,"fEM_R0UT61RZZ\0"},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{178,"fEM_R0UT62RZZ\0"},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{179,"fEM_R0UT71RZZ\0"},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{180,"fEM_R0UT72RZZ\0"},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_Baz2[]={
	{&A0EE08LZ2,1,0},	//( - , Baz2) Исправность сети АКНП4
	{&A0EE07LZ2,1,1},	//( - , Baz2) Исправность сети АКНП3
	{&A0EE06LZ2,1,2},	//( - , Baz2) Исправность сети АКНП2
	{&A0EE05LZ2,1,3},	//( - , Baz2) Исправность сети АКНП1
	{&R0EE02LDU,1,4},	//( - , Baz2, SBz2DU) Питание  АКНП  отключить
	{&R0MD34LP1,1,5},	//( - , Baz2) Кнопка Квитировать
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_Baz2[]={
	{&B0VT61LZ2,1,0},	//( - , Baz2) ПС по температуре в АЗ2
	{&R0VP73LZ2,1,1},	//( - , Baz2, SBz2DU) ПС давления для РУ
	{&B0VN81LZ2,1,2},	//( - , Baz2) АЗ по АС периода разгона АЗ2
	{&A0VN81LZ2,1,3},	//( - , Baz2) АЗ по АС периода разгона АЗ1
	{&B0VN71LZ2,1,4},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ2
	{&A0VN71LZ2,1,5},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ1
	{&B0VZ71LZ2,1,6},	//( - , Baz2) Обобщенный сигнал АС по АЗ2
	{&B0EE00LZ2,1,7},	//( - , Baz2) Исправность АКНП АЗ2
	{&A0EE00LZ2,1,8},	//( - , Baz2) Исправность АКНП АЗ1
	{&A0VZ71LZ2,1,9},	//( - , Baz2) Обобщенный сигнал АС по АЗ1
	{&A0EE03LZ2,1,10},	//( - , Baz2, SBz2DU) Исправность АКНП3
	{&A0EE02LZ2,1,11},	//( - , Baz2, SBz2DU) Исправность АКНП2
	{&A0EE04LZ2,1,12},	//( - , Baz2, SBz2DU) Исправность АКНП4
	{&A0EE01LZ2,1,13},	//( - , Baz2, SBz2DU) Исправность АКНП1
	{&R0VN80LZ2,1,14},	//( - , Baz2) АЗ по АС периода разгона РУ
	{&R0VN70LZ2,1,15},	//( - , Baz2) АЗ по АС мощности РУ
	{&R7II82LZ2,1,16},	//( - , Baz2) Сработала АС IIУР
	{&R7II81LZ2,1,17},	//( - , Baz2) Сработала АС IУР
	{&A3VZ13LZ2,1,18},	//( - K01FDSR, Baz2) Имитация АЗ от ВУ ИС
	{&A3VZ15LZ2,1,19},	//( - K02FDSR, Baz2) Имитация АЗ от НУП ИС
	{&B3VZ11LZ2,1,20},	//( - , Baz2) АЗ от НУП ИС2
	{&A3VZ11LZ2,1,21},	//( - , Baz2) АЗ от НУП ИС1
	{&B3VZ31LZ2,1,22},	//( - , Baz2) АЗ от ВУ ИС2
	{&A3VZ31LZ2,1,23},	//( - , Baz2) АЗ от ВУ ИС1
	{&TestDiagnBaz2,1,24},	//( - , Baz2) Неисправность от
	{&R0VN78LZ2,1,25},	//( - K02VDSR, Baz2) АС по периоду разгона канал  4
	{&R0VN77LZ2,1,26},	//( - K02VDSR, Baz2) АС по периоду разгона канал  3
	{&R0VN74LZ2,1,27},	//( - K01VDSR, Baz2) АС по мощности канал 4
	{&R0VN73LZ2,1,28},	//( - K01VDSR, Baz2) АС по мощности канал 3
	{&R0VN76LZ2,1,29},	//( - K02VDSR, Baz2) АС по периоду разгона канал  2
	{&R0VN72LZ2,1,30},	//( - K01VDSR, Baz2) АС по мощности канал 2
	{&R0VN75LZ2,1,31},	//( - K02VDSR, Baz2) АС по периоду разгона канал 1
	{&R0VN71LZ2,1,32},	//( - K01VDSR, Baz2) АС по мощности канал 1
	{&B0VT71LZ2,1,33},	//( - , Baz2, SBz2DU) АС по температуре в АЗ2
	{&R0ET02LZ2,1,34},	//( - , Baz2) Признак наличия неисправности по температуре АЗ2
	{&B0VP41LZ2,1,35},	//( - , Baz2) Давление АЗ2 ниже АС
	{&A0VP41LZ2,1,36},	//( - , Baz2) Давление АЗ1 ниже АС
	{&R0ET01LZ2,1,37},	//( - , Baz2) Признак наличия неисправности по температуре  АЗ1
	{&A2VP81LZ2,1,38},	//( - , Baz2) Давление СБРОС РБ1 в норме
	{&B2VP81LZ2,1,39},	//( - , Baz2) Давление СБРОС РБ2 в норме
	{&B2VP51LZ2,1,40},	//( - , Baz2) Давление СБРОС РБ2 ниже ПС
	{&B2VP41LZ2,1,41},	//( - , Baz2) Давление СБРОС РБ2 ниже АС
	{&A2VP51LZ2,1,42},	//( - , Baz2) Давление СБРОС РБ1 ниже ПС
	{&A2VP41LZ2,1,43},	//( - , Baz2) Давление СБРОС РБ1 ниже АС
	{&B1VP41LZ2,1,44},	//( - , Baz2, SBz2DU) Давление СБРОС ББ2 ниже АС
	{&A1VP41LZ2,1,45},	//( - , Baz2, SBz2DU) Давление СБРОС ББ1 ниже АС
	{&A0VT71LZ2,1,46},	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
	{&A0VT61LZ2,1,47},	//( - , Baz2) ПС по температуре в АЗ1
	{&R0VZ71LZ2,1,48},	//( - K16FDSR, Baz2, MBz2S) Обобщенный сигнал АЗ 2 канала
	{&R0VN79LZ2,1,49},	//( - , Baz2) АС по усредненному периоду
	{&R0VN69LZ2,1,50},	//( - , Baz2) ПС по усредненному периоду
	{&R0VN68LZ2,1,51},	//( - , Baz2) ПС по периоду разгона канал 4
	{&R0VN67LZ2,1,52},	//( - , Baz2) ПС по периоду разгона канал 3
	{&R0VN66LZ2,1,53},	//( - , Baz2) ПС по периоду разгона канал 2
	{&R0VN65LZ2,1,54},	//( - , Baz2) ПС по периоду разгона канал 1
	{&R0VN64LZ2,1,55},	//( - , Baz2) ПС по мощности канал 4
	{&R0VN63LZ2,1,56},	//( - , Baz2) ПС по мощности канал 3
	{&R0VN62LZ2,1,57},	//( - , Baz2) ПС по мощности канал 2
	{&R0VN61LZ2,1,58},	//( - , Baz2) ПС по мощности канал 1
	{&B0VP71LZ2,1,59},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
	{&A0VP71LZ2,1,60},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_Baz2[]={
	{&B0CT01IZ2,8,0},	//( - , Baz2, SBz2DU) Температура АЗ2-1
	{&R0VN11RZ2,8,2},	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ2
	{&R0VZ05UZ2,5,4},	//( - , Baz2) Индикатор причины сброса
	{&TTLBaz2,3,6},	//( - , Baz2) ttl
	{&A0EP02IZ2,3,7},	//( - , Baz2) Индикатор -Давление  АЗ1 ниже АС
	{&B0EP02IZ2,3,8},	//( - , Baz2) Индикатор -Давление  АЗ2 ниже АС
	{&B0IT02IZ2,3,9},	//( - K03VASR, Baz2) Температура АЗ2-2
	{&B2IP01IZ2,3,10},	//( - K04VASR, Baz2) Текущее давление СБРОС РБ2
	{&A2IP01IZ2,3,11},	//( - K02VASR, Baz2) Текущее давление СБРОС РБ1
	{&B2CP01RZ2,8,12},	//( - , Baz2) Текущее давление СБРОС РБ2
	{&A2CP01RZ2,8,14},	//( - , Baz2) Текущее давление СБРОС РБ1
	{&A0CT01IZ2,8,16},	//( - , Baz2, SBz2DU) Температура АЗ1-1
	{&A0IT02IZ2,3,18},	//( - K01VASR, Baz2) Температура АЗ1-2
	{&R0VR02RZ2,8,19},	//( - , Baz2) Усредненная реактивность
	{&R0VN09RZ2,8,21},	//( - , Baz2) Усредненный период разгона
	{&R0VN08RZ2,8,23},	//( - , Baz2) Период разгона по каналу 4
	{&R0VN07RZ2,8,25},	//( - , Baz2) Период разгона по каналу 3
	{&R0VN06RZ2,8,27},	//( - , Baz2) Период разгона по каналу 2
	{&R0VN05RZ2,8,29},	//( - , Baz2) Период разгона по каналу 1
	{&R0VN04RZ2,8,31},	//( - , Baz2) Уровень мощности по каналу 4
	{&R0VN03RZ2,8,33},	//( - , Baz2) Уровень мощности по каналу 3
	{&R0VN02RZ2,8,35},	//( - , Baz2) Уровень мощности по каналу 2
	{&R0VN01RZ2,8,37},	//( - , Baz2) Уровень мощности по каналу 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_Baz2[]={
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
	{&fEM_R0UL05RDU,8,38},	//( - , Baz2) Время задержки АЗ от НУП ИС(сек)
	{&fEM_R0UL25RDU,8,40},	//( - , Baz2) Время задержки АЗ от ВУ ИС сек
	{&fEM_R0UL07RDU,8,42},	//( - , Baz2) Время задержки  срабатывания АС II УР
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MBz2S[]={
	{&R0VZ71LZ2,1,0},	//( - , SCM, SBz2) Обобщенный сигнал по АЗ  2 канала
	{&R0EE01LZ2,1,1},	//( - , SBz2) Питание  АКНП1  отключить
	{&R0EE02LZ2,1,2},	//( - , SBz2) Питание  АКНП  отключить
	{&R0EE03LZ2,1,3},	//( - , SBz2) Питание  АКНП3  отключить
	{&R0EE04LZ2,1,4},	//( - , SBz2) Питание  АКНП4  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz2S[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz2S[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz2S[]={
	{NULL,0,0},
};
#pragma pop
static char MBz2S_ip1[]={"192.168.10.60\0"};
static char MBz2S_ip2[]={"\0"};
#pragma pack(push,1)
static ModbusRegister coil_DiagnBaz2[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnBaz2[]={
	{&R0DEB1LZ2,1,0},	//( - S10SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 5
	{&R0DEB2LZ2,1,1},	//( - S11SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 5
	{&R0DEB3LZ2,1,2},	//( - S12SBK, DiagnBaz2) диагностика шкафа Баз2 БП5 место 6
	{&R0DEB4LZ2,1,3},	//( - S13SBK, DiagnBaz2) диагностика шкафа Баз2 БП24Д место 6
	{&R0DE3CLZ2,1,4},	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 5
	{&R0DE3DLZ2,1,5},	//( - , DiagnBaz2) диагностика шкафа Баз2 БП5/24Д место 6
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DiagnBaz2[]={
	{&R0DE04LZ2,3,0},	//( - Diagn, DiagnBaz2) диагностика модуля Баз2 на 4 месте
	{&R0DE05LZ2,3,1},	//( - Diagn, DiagnBaz2) диагностика модуля Баз2 на 5 месте
	{&R0DE06LZ2,3,2},	//( - Diagn, DiagnBaz2) диагностика модуля Баз2 на 6 месте
	{&R0DE07LZ2,3,3},	//( - Diagn, DiagnBaz2) диагностика модуля Баз2 на 7 месте
	{&R0DE0ALZ2,3,4},	//( - Diagn, DiagnBaz2) диагностика модуля Баз2 на 10 месте
	{&R0DE08LZ2,3,5},	//( - Diagn, DiagnBaz2) диагностика модуля Баз2 на 8 месте
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DiagnBaz2[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SBz2DU[]={
	{&R0AD21LDU,1,0},	//( - , SBz2DU) Подключить защиту от II УР
	{&R0EE02LDU,1,1},	//( - , Baz2, SBz2DU) Питание  АКНП  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz2DU[]={
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
static ModbusRegister ir_SBz2DU[]={
	{&B0CT01IZ2,8,0},	//( - , Baz2, SBz2DU) Температура АЗ2-1
	{&R0VN11RZ2,8,2},	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ2
	{&A0CT01IZ2,8,4},	//( - , Baz2, SBz2DU) Температура АЗ1-1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SBz2DU[]={
	{&B8VC01RDU,8,0},	//( - , SBz2DU, MBz2A1, MBz2A2, MBz2A3, MBz2A4) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MBz2A1[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz2A1[]={
	{&R0VN61LS1,1,0},	//( - , A1Bz1, A1Bz2) ПС по мощности канал1
	{&R0VN65LS1,1,1},	//( - , A1Bz1, A1Bz2) ПС по периоду разгона канал1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz2A1[]={
	{&R0VN02RS1,8,0},	//( - , A1Bz1, A1Bz2) Уровень мощности
	{&R0VN01RS1,8,2},	//( - , A1Bz1, A1Bz2) Период разгона канал1
	{&ttlfa1,8,4},	//( - , AKNP1, A1Bz1, A1Bz2) ttlf float
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz2A1[]={
	{&B8VC01RDU,8,0},	//( - , A1Bz1, A1Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
static char MBz2A1_ip1[]={"192.168.10.51\0"};
static char MBz2A1_ip2[]={"192.168.10.151\0"};
#pragma pack(push,1)
static ModbusRegister coil_MBz2A2[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz2A2[]={
	{&R0VN61LS2,1,0},	//( - , A2Bz1, A2Bz2) ПС по мощности канал 2
	{&R0VN65LS2,1,1},	//( - , A2Bz1, A2Bz2) ПС по периоду разгона канал 2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz2A2[]={
	{&R0VN02RS2,8,0},	//( - , A2Bz1, A2Bz2) Уровень мощности канал 2
	{&R0VN01RS2,8,2},	//( - , A2Bz1, A2Bz2) Период разгона канал 2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz2A2[]={
	{&B8VC01RDU,8,0},	//( - , A2Bz1, A2Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
static char MBz2A2_ip1[]={"192.168.10.57\0"};
static char MBz2A2_ip2[]={"192.168.10.157\0"};
#pragma pack(push,1)
static ModbusRegister coil_MBz2A3[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz2A3[]={
	{&R0VN61LS3,1,0},	//( - , A3Bz1, A3Bz2) ПС по мощности канал 3
	{&R0VN65LS3,1,1},	//( - , A3Bz1, A3Bz2) ПС по периоду разгона канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz2A3[]={
	{&R0VN02RS3,8,0},	//( - , A3Bz1, A3Bz2) Уровень мощности канал 3
	{&R0VN01RS3,8,2},	//( - , A3Bz1, A3Bz2) Период разгона канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz2A3[]={
	{&B8VC01RDU,8,0},	//( - , A3Bz1, A3Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
static char MBz2A3_ip1[]={"192.168.10.53\0"};
static char MBz2A3_ip2[]={"192.168.10.153\0"};
#pragma pack(push,1)
static ModbusRegister coil_MBz2A4[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz2A4[]={
	{&R0VN61LS4,1,0},	//( - , A4Bz1, A4Bz2) ПС по мощности канал 4
	{&R0VN65LS4,1,1},	//( - , A4Bz1, A4Bz2) ПС по периоду разгона канал 4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz2A4[]={
	{&R0VN02RS4,8,0},	//( - , A4Bz1, A4Bz2) Уровень мощности канал 4
	{&R0VN01RS4,8,2},	//( - , A4Bz1, A4Bz2) Период разгона канал 4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz2A4[]={
	{&B8VC01RDU,8,0},	//( - , A4Bz1, A4Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
static char MBz2A4_ip1[]={"192.168.10.55\0"};
static char MBz2A4_ip2[]={"192.168.10.155\0"};
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_Baz2[0],&di_Baz2[0],&ir_Baz2[0],&hr_Baz2[0],NULL,NULL,NULL,0},	//Общий слэйв
	{1,5004,&coil_MBz2S[0],&di_MBz2S[0],&ir_MBz2S[0],&hr_MBz2S[0],NULL,MBz2S_ip1,MBz2S_ip2,100},	//Мастер Баз2 в SCM
	{0,5005,&coil_DiagnBaz2[0],&di_DiagnBaz2[0],&ir_DiagnBaz2[0],&hr_DiagnBaz2[0],NULL,NULL,NULL,0},	//Диагностика Baz2
	{0,5009,&coil_SBz2DU[0],&di_SBz2DU[0],&ir_SBz2DU[0],&hr_SBz2DU[0],NULL,NULL,NULL,0},	//Слэйв для DU
	{1,5019,&coil_MBz2A1[0],&di_MBz2A1[0],&ir_MBz2A1[0],&hr_MBz2A1[0],NULL,MBz2A1_ip1,MBz2A1_ip2,20},	//Мастер Баз2 в AKNP1
	{1,5020,&coil_MBz2A2[0],&di_MBz2A2[0],&ir_MBz2A2[0],&hr_MBz2A2[0],NULL,MBz2A2_ip1,MBz2A2_ip2,20},	//Мастер Баз2 в AKNP2
	{1,5021,&coil_MBz2A3[0],&di_MBz2A3[0],&ir_MBz2A3[0],&hr_MBz2A3[0],NULL,MBz2A3_ip1,MBz2A3_ip2,20},	//Мастер Баз2 в AKNP3
	{1,5022,&coil_MBz2A4[0],&di_MBz2A4[0],&ir_MBz2A4[0],&hr_MBz2A4[0],NULL,MBz2A4_ip1,MBz2A4_ip2,20},	//Мастер Баз2 в AKNP4
	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS16[104];	//FDS16
static fds16r_inipar ini_FDS16={0x96,0xff,8,0,0,};
#pragma pack(push,1)
static table_drv table_FDS16={0,0,&ini_FDS16,buf_FDS16,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS16[]={
	{&A3VZ13LZ2,1,0},
	{&A3VZ15LZ2,1,2},
	{&R0AD14LZ2,1,4},
	{&A1VN71LZ2,1,6},
	{&R0VZ71LZ2,1,30},
	{&R0DE0ALZ2,3,38},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/sbkfp7.h>
static char buf_SBKFP[90];	//SBKFP
static sbk_inipar ini_SBKFP={0,0,0,};
#pragma pack(push,1)
static table_drv table_SBKFP={0,0,&ini_SBKFP,buf_SBKFP,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_SBKFP[]={
	{&R0DEB1LZ2,1,18},
	{&R0DEB2LZ2,1,20},
	{&R0DEB3LZ2,1,22},
	{&R0DEB4LZ2,1,24},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vas84r.h>
static char buf_VAS84[64];	//VAS84
static vas84r_inipar ini_VAS84={0xc6,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VAS84={0,0,&ini_VAS84,buf_VAS84,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VAS84[]={
	{&A0IT02IZ2,3,0},
	{&A2IP01IZ2,3,3},
	{&B0IT02IZ2,3,6},
	{&B2IP01IZ2,3,9},
	{&R0DE04LZ2,3,26},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS321[194];	//VDS321
static vds32r_inipar ini_VDS321={0xc2,0xff,0,255,255,0,0,};
#pragma pack(push,1)
static table_drv table_VDS321={0,0,&ini_VDS321,buf_VDS321,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS321[]={
	{&R0VN71LZ2,1,0},
	{&R0VN75LZ2,1,2},
	{&A1EE01LS1,1,4},
	{&A1VN71LS1,1,6},
	{&A3IS11LDU,1,8},
	{&A3IS22LDU,1,10},
	{&R0AD03LZ2,1,12},
	{&R0AD04LZ2,1,14},
	{&R0AD05LZ2,1,16},
	{&A2IS12LDU,1,18},
	{&B2IS12LDU,1,20},
	{&R0DE05LZ2,3,64},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS322[194];	//VDS322
static vds32r_inipar ini_VDS322={0xc2,0xff,0,255,255,0,0,};
#pragma pack(push,1)
static table_drv table_VDS322={0,0,&ini_VDS322,buf_VDS322,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS322[]={
	{&R0VN72LZ2,1,0},
	{&R0VN76LZ2,1,2},
	{&A1EE01LS2,1,4},
	{&A1VN71LS2,1,6},
	{&B3IS11LDU,1,8},
	{&B3IS22LDU,1,10},
	{&R7II71LZ2,1,12},
	{&R7II74LZ2,1,14},
	{&R0DE06LZ2,3,64},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS323[194];	//VDS323
static vds32r_inipar ini_VDS323={0xc2,0xff,0,255,255,0,0,};
#pragma pack(push,1)
static table_drv table_VDS323={0,0,&ini_VDS323,buf_VDS323,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS323[]={
	{&R0VN74LZ2,1,0},
	{&R0VN78LZ2,1,2},
	{&A1EE01LS4,1,4},
	{&A1VN71LS4,1,6},
	{&R6IS66LZ2,1,8},
	{&R7II72LZ2,1,10},
	{&R7II75LZ2,1,12},
	{&R0DE07LZ2,3,64},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS324[194];	//VDS324
static vds32r_inipar ini_VDS324={0xc2,0xff,0,255,255,0,0,};
#pragma pack(push,1)
static table_drv table_VDS324={0,0,&ini_VDS324,buf_VDS324,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS324[]={
	{&R0VN73LZ2,1,0},
	{&R0VN77LZ2,1,2},
	{&A1EE01LS3,1,4},
	{&A1VN71LS3,1,6},
	{&R7II73LZ2,1,8},
	{&R7II76LZ2,1,10},
	{&R0S01LZ2,1,14},
	{&A0VP81LZZ,1,16},
	{&A1VP81LZZ,1,18},
	{&B0VP81LZZ,1,22},
	{&B1VP81LZZ,1,24},
	{&R0DE08LZ2,3,64},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0x96,0x0a,5,104,def_buf_FDS16,&table_FDS16},	//FDS16
	{0xcc,0x20,3,90,def_buf_SBKFP,&table_SBKFP},	//SBKFP
	{0xc6,0x04,5,64,def_buf_VAS84,&table_VAS84},	//VAS84
	{0xc2,0x05,7,194,def_buf_VDS321,&table_VDS321},	//VDS32
	{0xc2,0x06,7,194,def_buf_VDS322,&table_VDS322},	//VDS32
	{0xc2,0x07,7,194,def_buf_VDS323,&table_VDS323},	//VDS32
	{0xc2,0x08,7,194,def_buf_VDS324,&table_VDS324},	//VDS32
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){	//Инициализация переменных для хранения
	setAsFloat(160,0.6);
	setAsFloat(161,0);
	setAsFloat(162,0.1);
	setAsFloat(163,0.13);
	setAsFloat(164,0.16);
	setAsFloat(165,0.19);
	setAsFloat(166,0.17);
	setAsFloat(167,0.2);
	setAsFloat(168,0.28);
	setAsFloat(169,0.31);
	setAsFloat(170,0.190);
	setAsFloat(171,0.150);
	setAsFloat(172,0.170);
	setAsFloat(173,15);
	setAsFloat(174,10);
	setAsFloat(175,0);
	setAsFloat(176,600);
	setAsFloat(177,100);
	setAsFloat(178,90);
	setAsFloat(179,200);
	setAsFloat(180,150);
	setAsShort(0,1);
	setAsShort(0,1);
	setAsShort(0,1);
}
int freebuff=0;
int delay=0;
/* Определение внутренних параметров */

/* Определение констант ПЗУ и ЭСППЗУ*/
ssbool lRM_0_ = {0,0}; /* A-Граница участка насыщения А */ 
ssbool lRM_1_ = {1,0}; /* B-Граница участка насыщения В */ 
sslong dRM_0_ = {0,0}; /* lx вход лонг */ 
sschar bRM_0_ = {0,0}; /* cx вход байтовый */ 
ssint iRM_0_ = {0,0}; /* ix вход целый */ 
ssint iRM_3_ = {3,0}; /* N-число входов */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива */ 
ssint iRM_6_ = {6,0}; /* N-число входов */ 
ssint iRM_16_ = {16,0}; /* n - размерность массива входных сигналов */ 
ssint iRM_3200_ = {3200,0}; /* a */ 
ssint iRM_16000_ = {16000,0}; /* b */ 
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
ssfloat fRM_10_ = {10,0}; /* tz - время задержки сек */ 
ssfloat fRM_0_3 = {0.3,0}; /* tz - время задержки сек */ 


/* Определение переменных */
sschar var133;
sschar var135;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psint  array_m310_x_1[6] = {&R0DE04LZ2,&R0DE05LZ2,&R0DE06LZ2,&R0DE0ALZ2,&R0DE08LZ2,&R0DE07LZ2};
psfloat  array_m190_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psfloat  array_m294_x_1[4] = {&R0VN02RS1,&R0VN02RS2,&R0VN02RS3,&R0VN02RS4};
psbool  array_m294_diag_1[4] = {&var34,&var35,&var36,&var37};
psbool  array_m285_x_1[16] = {&var77,&var42,&var43,&var88,&var13,&var10,&var132,&var44,&var47,&var48,&var86,&var14,&var11,&var134,&var20,&var17};
psbool  array_m16_x_1[6] = {&var81,&var86,&var14,&var11,&var21,&var134};
psbool  array_m37_x_1[6] = {&var88,&var10,&var13,&var132,&var79,&var21};
psfloat  array_m2_x_1[4] = {&R0VN01RS1,&R0VN01RS2,&R0VN01RS3,&R0VN01RS4};
psbool  array_m2_diag_1[4] = {&var34,&var35,&var36,&var37};
psbool  array_m3_x_1[3] = {&var94,&var114,&var38};
psbool  array_m12_x_1[3] = {&var93,&var41,&var95};

/* Объявление структур */
_S_noto  S_noto_26_1 = {&var80,&var1};
_S_schl24  S_schl24_225_1 = {&R7II74LZ2,&R7II75LZ2,&R7II76LZ2,&lRM_0_,&var2};
_S_schl24  S_schl24_199_1 = {&R7II71LZ2,&R7II72LZ2,&R7II73LZ2,&lRM_0_,&var3};
_S_or2  S_or2_230_1 = {&var17,&var20,&var4};
_S_zzfs  S_zzfs_215_1 = {&var16,&fRM_0_3,&var5,&internal1_m215_tx,&internal1_m215_y0};
_S_or2  S_or2_282_1 = {&R0MD34LP1,&var5,&var6};
_S_zzfs  S_zzfs_211_1 = {&R0AD04LZ2,&fRM_0_3,&var7,&internal1_m211_tx,&internal1_m211_y0};
_S_noto  S_noto_224_1 = {&var7,&var8};
_S_and2  S_and2_229_1 = {&var8,&var4,&var9};
_S_inicn  S_inicn_206_1 = {&A3IS11LDU,&B3IS11LDU,&R0AD03LZ2,&A3IS22LDU,&B3IS22LDU,&R0AD05LZ2,&var20,&var19,&var7,&fEM_R0UL25RDU,&fEM_R0UL05RDU,&fEM_R0UL07RDU,&var10,&var11,&var12,&var13,&var14,&var15,&var16,&internal1_m206_TVuIs1,&internal1_m206_TVuIs2,&internal1_m206_TImVuIs,&internal1_m206_TNupIs1,&internal1_m206_TNupIs2,&internal1_m206_TImNupIs,&internal1_m206_TImAZ2UR,&internal1_m206_fef};
_S_or2  S_or2_219_1 = {&var2,&var22,&var17};
_S_or2  S_or2_217_1 = {&R0AD21LDU,&var7,&var18};
_S_and2  S_and2_216_1 = {&var17,&var18,&var19};
_S_or2  S_or2_207_1 = {&var22,&var3,&var20};
_S_zpfs  S_zpfs_228_1 = {&var9,&fEM_R0UL07RDU,&var21,&internal1_m228_tx,&internal1_m228_y0};
_S_noto  S_noto_208_1 = {&R6IS66LZ2,&var22};
_S_zzfs  S_zzfs_112_1 = {&B1VP81LZZ,&fRM_10000_,&var23,&internal1_m112_tx,&internal1_m112_y0};
_S_zzfs  S_zzfs_111_1 = {&A1VP81LZZ,&fRM_10000_,&var24,&internal1_m111_tx,&internal1_m111_y0};
_S_zzfs  S_zzfs_99_1 = {&var38,&fRM_10_,&var25,&internal1_m99_tx,&internal1_m99_y0};
_S_zzfs  S_zzfs_113_1 = {&var41,&fRM_10_,&var26,&internal1_m113_tx,&internal1_m113_y0};
_S_zzfs  S_zzfs_141_1 = {&B0VP81LZZ,&fRM_10000_,&var27,&internal1_m141_tx,&internal1_m141_y0};
_S_zzfs  S_zzfs_140_1 = {&A0VP81LZZ,&fRM_10000_,&var28,&internal1_m140_tx,&internal1_m140_y0};
_S_or3  S_or3_316_1 = {&var32,&var31,&var30,&var29};
_S_or2  S_or2_320_1 = {&R0DEB3LZ2,&R0DEB4LZ2,&var30};
_S_or2  S_or2_314_1 = {&R0DEB1LZ2,&R0DEB2LZ2,&var31};
_S_diagndev  S_diagndev_310_1 = {array_m310_x_1,&iRM_6_,&var32,&var33,&vainSFloat};
_S_ma  S_ma_190_1 = {array_m190_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_and2  S_and2_82_1 = {&lRM_1_,&A1EE01LS1,&var34};
_S_and2  S_and2_84_1 = {&lRM_1_,&A1EE01LS2,&var35};
_S_and2  S_and2_86_1 = {&lRM_1_,&A1EE01LS3,&var36};
_S_and2  S_and2_88_1 = {&lRM_1_,&A1EE01LS4,&var37};
_S_or2  S_or2_105_1 = {&var143,&var141,&var38};
_S_and2  S_and2_137_1 = {&var136,&var112,&var39};
_S_and2  S_and2_130_1 = {&var113,&var137,&var40};
_S_or2  S_or2_109_1 = {&var138,&var139,&var41};
_S_and2  S_and2_288_1 = {&var64,&var90,&var42};
_S_and2  S_and2_286_1 = {&var52,&var90,&var43};
_S_and2  S_and2_290_1 = {&var102,&var90,&var44};
_S_schl24  S_schl24_300_1 = {&A1VN71LS2,&A1VN71LS1,&A1VN71LS4,&A1VN71LS3,&var45};
_S_or2  S_or2_298_1 = {&var140,&var142,&var46};
_S_and2  S_and2_289_1 = {&var65,&var90,&var47};
_S_and2  S_and2_287_1 = {&var53,&var90,&var48};
_S_and2  S_and2_261_1 = {&var90,&var52,&var49};
_S_or2  S_or2_258_1 = {&var62,&var60,&var50};
_S_and2  S_and2_267_1 = {&var61,&var90,&var51};
_S_or2  S_or2_264_1 = {&var54,&var62,&var52};
_S_or2  S_or2_266_1 = {&var54,&var60,&var53};
_S_and2  S_and2_265_1 = {&var61,&var121,&var54};
_S_and2  S_and2_262_1 = {&var90,&var53,&var55};
_S_or2  S_or2_274_1 = {&R0VN76LZ2,&var124,&var56};
_S_or2  S_or2_275_1 = {&R0VN78LZ2,&var123,&var57};
_S_or2  S_or2_272_1 = {&R0VN75LZ2,&var126,&var58};
_S_or2  S_or2_273_1 = {&R0VN77LZ2,&var125,&var59};
_S_and2  S_and2_271_1 = {&var56,&var57,&var60};
_S_schl24  S_schl24_269_1 = {&var58,&var59,&var56,&var57,&var61};
_S_and2  S_and2_270_1 = {&var58,&var59,&var62};
_S_or2  S_or2_257_1 = {&var72,&var76,&var63};
_S_or2  S_or2_249_1 = {&var67,&var76,&var64};
_S_or2  S_or2_251_1 = {&var67,&var72,&var65};
_S_and2  S_and2_245_1 = {&var73,&var90,&var66};
_S_and2  S_and2_250_1 = {&var73,&var122,&var67};
_S_and2  S_and2_253_1 = {&var64,&var90,&var68};
_S_and2  S_and2_254_1 = {&var90,&var65,&var69};
_S_or2  S_or2_238_1 = {&R0VN72LZ2,&var124,&var70};
_S_or2  S_or2_239_1 = {&R0VN74LZ2,&var123,&var71};
_S_and2  S_and2_241_1 = {&var71,&var70,&var72};
_S_schl24  S_schl24_243_1 = {&var75,&var74,&var70,&var71,&var73};
_S_or2  S_or2_236_1 = {&R0VN71LZ2,&var126,&var74};
_S_or2  S_or2_237_1 = {&R0VN73LZ2,&var125,&var75};
_S_and2  S_and2_240_1 = {&var75,&var74,&var76};
_S_and2  S_and2_291_1 = {&var103,&var90,&var77};
_S_or3  S_or3_32_1 = {&var99,&var64,&var52,&var78};
_S_and2  S_and2_33_1 = {&var78,&var90,&var79};
_S_or2  S_or2_25_1 = {&var118,&var119,&var80};
_S_and2  S_and2_19_1 = {&var82,&var90,&var81};
_S_or3  S_or3_18_1 = {&var65,&var53,&var98,&var82};
_S_and2  S_and2_6_1 = {&var35,&var37,&var83};
_S_or2  S_or2_11_1 = {&var120,&var83,&var84};
_S_or2  S_or2_10_1 = {&var89,&var120,&var85};
_S_or2  S_or2_159_1 = {&var109,&var111,&var86};
_S_or2  S_or2_36_1 = {&B2IS12LDU,&A2IS12LDU,&var87};
_S_or2  S_or2_157_1 = {&var144,&var106,&var88};
_S_and2  S_and2_5_1 = {&var36,&var34,&var89};
_S_and2  S_and2_22_1 = {&var100,&var96,&var90};
_S_and2  S_and2_187_1 = {&var101,&var128,&var91};
_S_and2  S_and2_186_1 = {&var129,&var101,&var92};
_S_noto  S_noto_143_1 = {&var27,&var93};
_S_noto  S_noto_142_1 = {&var28,&var94};
_S_noto  S_noto_117_1 = {&var23,&var95};
_S_noto  S_noto_28_1 = {&var97,&var96};
_S_ovb1  S_ovb1_30_1 = {&var87,&iRM_200_,&var97,&internal1_m30_tx};
_S_noto  S_noto_14_1 = {&var84,&var98};
_S_noto  S_noto_13_1 = {&var85,&var99};
_S_noto  S_noto_24_1 = {&R0EE02LDU,&var100};
_S_bol  S_bol_182_1 = {&var130,&fRM_0_00001,&var101};
_S_noto  S_noto_292_1 = {&var84,&var102};
_S_noto  S_noto_293_1 = {&var85,&var103};
_S_scalzz  S_scalzz_151_1 = {&B0IT02IZ2,&iRM_3200_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var104,&internal1_m151_y0};
_S_scalzz  S_scalzz_149_1 = {&A0IT02IZ2,&iRM_3200_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var105,&internal1_m149_y0};
_S_geterr  S_geterr_153_1 = {&var105,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var106};
_S_scalzz  S_scalzz_93_1 = {&B2IP01IZ2,&iRM_3200_,&iRM_16000_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var107,&internal1_m93_y0};
_S_scalzz  S_scalzz_91_1 = {&A2IP01IZ2,&iRM_3200_,&iRM_16000_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var108,&internal1_m91_y0};
_S_drg  S_drg_162_1 = {&var104,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var109,&internal1_m162_y1};
_S_drg  S_drg_173_1 = {&var104,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var110,&internal1_m173_y1};
_S_geterr  S_geterr_155_1 = {&var104,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var111};
_S_noto  S_noto_138_1 = {&var138,&var112};
_S_noto  S_noto_129_1 = {&var143,&var113};
_S_noto  S_noto_116_1 = {&var24,&var114};
_S_srm  S_srm_294_1 = {array_m294_x_1,array_m294_diag_1,&iRM_4_,&iRM_3_,&var115,&vainSBool};
_S_rsu  S_rsu_284_1 = {&var6,&var117,&var116,&internal1_m284_q0};
_S_orni  S_orni_285_1 = {array_m285_x_1,&iRM_16_,&vainSBool,&var117};
_S_orn  S_orn_16_1 = {array_m16_x_1,&iRM_6_,&var118};
_S_orn  S_orn_37_1 = {array_m37_x_1,&iRM_6_,&var119};
_S_noto  S_noto_7_1 = {&var131,&var120};
_S_noto  S_noto_260_1 = {&var50,&var121};
_S_noto  S_noto_255_1 = {&var63,&var122};
_S_noto  S_noto_244_1 = {&A1EE01LS4,&var123};
_S_noto  S_noto_248_1 = {&A1EE01LS2,&var124};
_S_noto  S_noto_247_1 = {&A1EE01LS3,&var125};
_S_noto  S_noto_242_1 = {&A1EE01LS1,&var126};
_S_react  S_react_178_1 = {&var130,&var127};
_S_bol  S_bol_183_1 = {&fEM_R0UR04RZZ,&var130,&var128};
_S_bol  S_bol_181_1 = {&fEM_R0UR01RZZ,&var130,&var129};
_S_srm  S_srm_2_1 = {array_m2_x_1,array_m2_diag_1,&iRM_4_,&iRM_3_,&var130,&var131};
_S_ornc  S_ornc_3_1 = {array_m3_x_1,&iRM_3_,&var132,&var133};
_S_ornc  S_ornc_12_1 = {array_m12_x_1,&iRM_3_,&var134,&var135};
_S_tprg  S_tprg_131_1 = {&var107,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var136,&internal1_m131_y0};
_S_tprg  S_tprg_125_1 = {&var108,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var137,&internal1_m125_y0};
_S_geterr  S_geterr_101_1 = {&var107,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var138};
_S_drg  S_drg_108_1 = {&var107,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var139,&internal1_m108_y1};
_S_drg  S_drg_120_1 = {&var107,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var140,&internal1_m120_y1};
_S_drg  S_drg_95_1 = {&var108,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var141,&internal1_m95_y1};
_S_drg  S_drg_106_1 = {&var108,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var142,&internal1_m106_y1};
_S_geterr  S_geterr_97_1 = {&var108,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var143};
_S_drg  S_drg_161_1 = {&var105,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var144,&internal1_m161_y1};
_S_drg  S_drg_169_1 = {&var105,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var145,&internal1_m169_y1};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  noto(&S_noto_242_1);
  noto(&S_noto_247_1);
  noto(&S_noto_248_1);
  noto(&S_noto_244_1);
  scalzz(&S_scalzz_91_1);
  scalzz(&S_scalzz_93_1);
  scalzz(&S_scalzz_149_1);
  scalzz(&S_scalzz_151_1);
  or2(&S_or2_237_1);
  or2(&S_or2_236_1);
  or2(&S_or2_239_1);
  or2(&S_or2_238_1);
  or2(&S_or2_273_1);
  or2(&S_or2_272_1);
  or2(&S_or2_275_1);
  or2(&S_or2_274_1);
  schl24(&S_schl24_300_1);
  ma(&S_ma_190_1);
  diagndev(&S_diagndev_310_1);
  or2(&S_or2_314_1);
  or2(&S_or2_320_1);
  or3(&S_or3_316_1);
  zzfs(&S_zzfs_140_1);
  zzfs(&S_zzfs_141_1);
  zzfs(&S_zzfs_111_1);
  zzfs(&S_zzfs_112_1);
  noto(&S_noto_208_1);
  zzfs(&S_zzfs_211_1);
  schl24(&S_schl24_199_1);
  schl24(&S_schl24_225_1);
  drg(&S_drg_169_1);
  drg(&S_drg_161_1);
  geterr(&S_geterr_97_1);
  drg(&S_drg_106_1);
  drg(&S_drg_95_1);
  drg(&S_drg_120_1);
  drg(&S_drg_108_1);
  geterr(&S_geterr_101_1);
  tprg(&S_tprg_125_1);
  tprg(&S_tprg_131_1);
  noto(&S_noto_116_1);
  noto(&S_noto_129_1);
  noto(&S_noto_138_1);
  geterr(&S_geterr_155_1);
  drg(&S_drg_173_1);
  drg(&S_drg_162_1);
  geterr(&S_geterr_153_1);
  noto(&S_noto_24_1);
  noto(&S_noto_117_1);
  noto(&S_noto_142_1);
  noto(&S_noto_143_1);
  or2(&S_or2_157_1);
  or2(&S_or2_36_1);
  or2(&S_or2_159_1);
  and2(&S_and2_240_1);
  schl24(&S_schl24_243_1);
  and2(&S_and2_241_1);
  or2(&S_or2_257_1);
  and2(&S_and2_270_1);
  schl24(&S_schl24_269_1);
  and2(&S_and2_271_1);
  or2(&S_or2_258_1);
  or2(&S_or2_298_1);
  or2(&S_or2_109_1);
  and2(&S_and2_130_1);
  and2(&S_and2_137_1);
  or2(&S_or2_105_1);
  and2(&S_and2_88_1);
  and2(&S_and2_86_1);
  and2(&S_and2_84_1);
  and2(&S_and2_82_1);
  zzfs(&S_zzfs_113_1);
  zzfs(&S_zzfs_99_1);
  or2(&S_or2_207_1);
  or2(&S_or2_217_1);
  or2(&S_or2_219_1);
  noto(&S_noto_224_1);
  or2(&S_or2_230_1);
  ornc(&S_ornc_12_1);
  ornc(&S_ornc_3_1);
  srm(&S_srm_2_1);
  bol(&S_bol_181_1);
  bol(&S_bol_183_1);
  react(&S_react_178_1);
  noto(&S_noto_255_1);
  noto(&S_noto_260_1);
  noto(&S_noto_7_1);
  srm(&S_srm_294_1);
  bol(&S_bol_182_1);
  ovb1(&S_ovb1_30_1);
  noto(&S_noto_28_1);
  and2(&S_and2_186_1);
  and2(&S_and2_187_1);
  and2(&S_and2_22_1);
  and2(&S_and2_5_1);
  or2(&S_or2_10_1);
  and2(&S_and2_6_1);
  and2(&S_and2_250_1);
  and2(&S_and2_245_1);
  or2(&S_or2_251_1);
  or2(&S_or2_249_1);
  and2(&S_and2_265_1);
  or2(&S_or2_266_1);
  or2(&S_or2_264_1);
  and2(&S_and2_267_1);
  and2(&S_and2_261_1);
  and2(&S_and2_287_1);
  and2(&S_and2_289_1);
  and2(&S_and2_286_1);
  and2(&S_and2_288_1);
  and2(&S_and2_216_1);
  inicn(&S_inicn_206_1);
  and2(&S_and2_229_1);
  zzfs(&S_zzfs_215_1);
  noto(&S_noto_293_1);
  noto(&S_noto_13_1);
  or2(&S_or2_11_1);
  or3(&S_or3_32_1);
  and2(&S_and2_291_1);
  and2(&S_and2_254_1);
  and2(&S_and2_253_1);
  and2(&S_and2_262_1);
  zpfs(&S_zpfs_228_1);
  or2(&S_or2_282_1);
  noto(&S_noto_292_1);
  noto(&S_noto_14_1);
  or3(&S_or3_18_1);
  and2(&S_and2_19_1);
  and2(&S_and2_33_1);
  and2(&S_and2_290_1);
  orn(&S_orn_37_1);
  orn(&S_orn_16_1);
  orni(&S_orni_285_1);
  rsu(&S_rsu_284_1);
  or2(&S_or2_25_1);
  noto(&S_noto_26_1);
  setData(idR7II82LZ2,&var2);
  setData(idR7II81LZ2,&var3);
  setData(idR0AD14LZ2,&var16);
  setData(idA3VZ13LZ2,&var12);
  setData(idA3VZ15LZ2,&var15);
  setData(idB3VZ11LZ2,&var14);
  setData(idA3VZ11LZ2,&var13);
  setData(idB3VZ31LZ2,&var11);
  setData(idA3VZ31LZ2,&var10);
  setData(idR0VZ05U,&var117);
  setData(idTestDiagnBaz2,&var29);
  setData(idR0DE3DLZ2,&var30);
  setData(idR0DE3CLZ2,&var31);
  setData(idTTLBaz2,&var33);
  moveData(idR0EE04LZ2,idR0EE02LDU);
  moveData(idR0EE03LZ2,idR0EE02LDU);
  moveData(idR0EE02LZ2,idR0EE02LDU);
  moveData(idR0EE01LZ2,idR0EE02LDU);
  setData(idA1VN71LZ2,&var45);
  setData(idB0VT71LZ2,&var86);
  setData(idB0VT61LZ2,&var110);
  setData(idB0CT01IZ2,&var104);
  setData(idR0VP73LZ2,&var46);
  setData(idR0VN11RZ2,&var115);
  setData(idR0VZ05UZ2,&var116);
  setData(idB0VN81LZ2,&var55);
  setData(idA0VN81LZ2,&var49);
  setData(idB0VN71LZ2,&var69);
  setData(idA0VN71LZ2,&var68);
  setData(idB0VZ71LZ2,&var118);
  setData(idB0EE00LZ2,&var84);
  setData(idA0EE00LZ2,&var85);
  setData(idA0VZ71LZ2,&var119);
  setData(idA0EE03LZ2,&var36);
  setData(idA0EE02LZ2,&var35);
  setData(idA0EE04LZ2,&var37);
  setData(idA0EE01LZ2,&var34);
  setData(idR0VN80LZ2,&var51);
  setData(idR0VN70LZ2,&var66);
  setData(idR0VZ71LZ2,&var1);
  setData(idR0VR02RZ2,&var127);
  setData(idR0VN79LZ2,&var91);
  setData(idR0VN69LZ2,&var92);
  setData(idR0VN09RZ2,&var130);
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
  setData(idB0VP71LZ2,&var134);
  setData(idA0VP71LZ2,&var132);
  setData(idA0EP02IZ2,&var133);
  setData(idB0EP02IZ2,&var135);
  setData(idR0ET02LZ2,&var111);
  setData(idB0VP41LZ2,&var93);
  setData(idA0VP41LZ2,&var94);
  setData(idR0ET01LZ2,&var106);
  setData(idA2VP81LZ2,&var40);
  setData(idB2VP81LZ2,&var39);
  setData(idB2VP51LZ2,&var140);
  setData(idB2CP01RZ2,&var107);
  setData(idB2VP41LZ2,&var26);
  setData(idA2VP51LZ2,&var142);
  setData(idA2CP01RZ2,&var108);
  setData(idA2VP41LZ2,&var25);
  setData(idB1VP41LZ2,&var95);
  setData(idA1VP41LZ2,&var114);
  setData(idA0VT71LZ2,&var88);
  setData(idA0VT61LZ2,&var145);
  setData(idA0CT01IZ2,&var105);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}
void MainCycle(void){
	if ((getAsShort(idR0MW11IP1) == 2) || (getAsShort(idR0MW11IP1) == 3)) {
		if(delay++<(2000/20)) return;
		delay=delay>32000?32000:delay;
		freebuff = 0;
		Scheme();
	} else {
		delay=0;
		if (freebuff) return;
		freebuff = 1;
		memset(BUFFER, 0, SIZE_BUFFER);
		InitSetConst();
		if (SimulOn) initAllSimul(CodeSub, drivers, SimulIP, SimulPort);
		else initAllDrivers(drivers);
	}
}
#endif