#ifndef BAZ1_H
#define BAZ1_H
// Подсистема  Baz1:Baz1
static char SimulOn=0;
static short CodeSub=4;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 //Время цикла мс
float takt,taktScheme=0,taktSS=0;
#define SIZE_BUFFER 980
static char BUFFER[SIZE_BUFFER];
#include <fp8/UDPTransport.h>
SetupUDP setUDP ={"192.168.10.52\0",5432,"192.168.10.152\0",5432,BUFFER,sizeof(BUFFER),};
int master=1,nomer=1;
#define A0CT01IZ1	BUFFER[0]	// ( - , Baz1, SBz1DU) Температура АЗ1-1
#define idA0CT01IZ1	1	// ( - , Baz1, SBz1DU) Температура АЗ1-1
#define A0EE00LZ1	BUFFER[5]	// ( - , Baz1) Исправность АКНП АЗ1
#define idA0EE00LZ1	2	// ( - , Baz1) Исправность АКНП АЗ1
#define A0EE01LS1	BUFFER[7]	// (vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define idA0EE01LS1	3	// (vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
#define A0EE01LS2	BUFFER[9]	// (vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define idA0EE01LS2	4	// (vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
#define A0EE01LS3	BUFFER[11]	// (vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define idA0EE01LS3	5	// (vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
#define A0EE01LS4	BUFFER[13]	// (vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define idA0EE01LS4	6	// (vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
#define A0EE01LZ1	BUFFER[15]	// ( - , Baz1, SBz1DU) Исправность АКНП1
#define idA0EE01LZ1	7	// ( - , Baz1, SBz1DU) Исправность АКНП1
#define A0EE02LZ1	BUFFER[17]	// ( - , Baz1, SBz1DU) Исправность АКНП2
#define idA0EE02LZ1	8	// ( - , Baz1, SBz1DU) Исправность АКНП2
#define A0EE03LZ1	BUFFER[19]	// ( - , Baz1, SBz1DU) Исправность АКНП3
#define idA0EE03LZ1	9	// ( - , Baz1, SBz1DU) Исправность АКНП3
#define A0EE04LZ1	BUFFER[21]	// ( - , Baz1, SBz1DU) Исправность АКНП4
#define idA0EE04LZ1	10	// ( - , Baz1, SBz1DU) Исправность АКНП4
#define A0EE05LZ1	BUFFER[23]	// ( - , Baz1) Исправность сети АКНП1
#define idA0EE05LZ1	11	// ( - , Baz1) Исправность сети АКНП1
#define A0EE06LZ1	BUFFER[25]	// ( - , Baz1) Исправность сети АКНП2
#define idA0EE06LZ1	12	// ( - , Baz1) Исправность сети АКНП2
#define A0EE07LZ1	BUFFER[27]	// ( - , Baz1) Исправность сети АКНП3
#define idA0EE07LZ1	13	// ( - , Baz1) Исправность сети АКНП3
#define A0EE08LZ1	BUFFER[29]	// ( - , Baz1) Исправность сети АКНП4
#define idA0EE08LZ1	14	// ( - , Baz1) Исправность сети АКНП4
#define A0EP02IZ1	BUFFER[31]	// ( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
#define idA0EP02IZ1	15	// ( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
#define A0IT01IZ1	BUFFER[34]	// (vas84:04 - K01VASR, - ) Температура АЗ1-1
#define idA0IT01IZ1	16	// (vas84:04 - K01VASR, - ) Температура АЗ1-1
#define A0VN71LS1	BUFFER[37]	// (vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
#define idA0VN71LS1	17	// (vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
#define A0VN71LS2	BUFFER[39]	// (vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
#define idA0VN71LS2	18	// (vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
#define A0VN71LS3	BUFFER[41]	// (vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
#define idA0VN71LS3	19	// (vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
#define A0VN71LS4	BUFFER[43]	// (vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
#define idA0VN71LS4	20	// (vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
#define A0VN71LZ1	BUFFER[45]	// ( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
#define idA0VN71LZ1	21	// ( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
#define A0VN81LZ1	BUFFER[47]	// ( - , Baz1) АЗ по АС периода разгона АЗ1
#define idA0VN81LZ1	22	// ( - , Baz1) АЗ по АС периода разгона АЗ1
#define A0VP41LZ1	BUFFER[49]	// ( - , Baz1) Давление АЗ1 ниже АС
#define idA0VP41LZ1	23	// ( - , Baz1) Давление АЗ1 ниже АС
#define A0VP71LZ1	BUFFER[51]	// ( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	24	// ( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
#define A0VP81LZZ	BUFFER[53]	// (vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define idA0VP81LZZ	25	// (vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
#define A0VT61LZ1	BUFFER[55]	// ( - , Baz1) ПС по температуре в АЗ1
#define idA0VT61LZ1	26	// ( - , Baz1) ПС по температуре в АЗ1
#define A0VT71LZ1	BUFFER[57]	// ( - , Baz1, SBz1DU) АС по температуре в АЗ1
#define idA0VT71LZ1	27	// ( - , Baz1, SBz1DU) АС по температуре в АЗ1
#define A0VZ71LZ1	BUFFER[59]	// ( - , Baz1) Обобщенный сигнал АС по АЗ1
#define idA0VZ71LZ1	28	// ( - , Baz1) Обобщенный сигнал АС по АЗ1
#define A1VN71LZ1	BUFFER[61]	// (fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	29	// (fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
#define A1VP41LZ1	BUFFER[63]	// ( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	30	// ( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
#define A1VP81LZZ	BUFFER[65]	// (vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	31	// (vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
#define A2CP01RZ1	BUFFER[67]	// ( - , Baz1) Текущее давление СБРОС РБ1
#define idA2CP01RZ1	32	// ( - , Baz1) Текущее давление СБРОС РБ1
#define A2IP01IZ1	BUFFER[72]	// (vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	33	// (vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
#define A2IS12LDU	BUFFER[75]	// (vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	34	// (vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
#define A2VP41LZ1	BUFFER[77]	// ( - , Baz1) Давление СБРОС РБ1 ниже АС
#define idA2VP41LZ1	35	// ( - , Baz1) Давление СБРОС РБ1 ниже АС
#define A2VP51LZ1	BUFFER[79]	// ( - , Baz1) Давление СБРОС РБ1 ниже ПС
#define idA2VP51LZ1	36	// ( - , Baz1) Давление СБРОС РБ1 ниже ПС
#define A2VP81LZ1	BUFFER[81]	// ( - , Baz1) Давление СБРОС РБ1 в норме
#define idA2VP81LZ1	37	// ( - , Baz1) Давление СБРОС РБ1 в норме
#define A3IS11LDU	BUFFER[83]	// (vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define idA3IS11LDU	38	// (vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
#define A3IS22LDU	BUFFER[85]	// (vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define idA3IS22LDU	39	// (vds32:05 - K06VDSR, - ) Приход на НУП ИС1
#define A3VZ11LZ1	BUFFER[87]	// ( - , Baz1) АЗ от НУП ИС1
#define idA3VZ11LZ1	40	// ( - , Baz1) АЗ от НУП ИС1
#define A3VZ13LZ1	BUFFER[89]	// (fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
#define idA3VZ13LZ1	41	// (fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
#define A3VZ15LZ1	BUFFER[91]	// (fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
#define idA3VZ15LZ1	42	// (fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
#define A3VZ31LZ1	BUFFER[93]	// ( - , Baz1) АЗ от ВУ ИС1
#define idA3VZ31LZ1	43	// ( - , Baz1) АЗ от ВУ ИС1
#define B0CT01IZ1	BUFFER[95]	// ( - , Baz1, SBz1DU) Температура АЗ2-1
#define idB0CT01IZ1	44	// ( - , Baz1, SBz1DU) Температура АЗ2-1
#define B0EE00LZ1	BUFFER[100]	// ( - , Baz1) Исправность АКНП АЗ2
#define idB0EE00LZ1	45	// ( - , Baz1) Исправность АКНП АЗ2
#define B0EP02IZ1	BUFFER[102]	// ( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
#define idB0EP02IZ1	46	// ( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
#define B0IT01IZ1	BUFFER[105]	// (vas84:04 - K03VASR, - ) Температура АЗ2-1
#define idB0IT01IZ1	47	// (vas84:04 - K03VASR, - ) Температура АЗ2-1
#define B0VN71LZ1	BUFFER[108]	// ( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
#define idB0VN71LZ1	48	// ( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
#define B0VN81LZ1	BUFFER[110]	// ( - , Baz1) АЗ по АС периода разгона АЗ2
#define idB0VN81LZ1	49	// ( - , Baz1) АЗ по АС периода разгона АЗ2
#define B0VP41LZ1	BUFFER[112]	// ( - , Baz1) Давление АЗ2 ниже АС
#define idB0VP41LZ1	50	// ( - , Baz1) Давление АЗ2 ниже АС
#define B0VP71LZ1	BUFFER[114]	// ( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	51	// ( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
#define B0VP81LZZ	BUFFER[116]	// (vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	52	// (vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
#define B0VT61LZ1	BUFFER[118]	// ( - , Baz1) ПС по температуре в АЗ2
#define idB0VT61LZ1	53	// ( - , Baz1) ПС по температуре в АЗ2
#define B0VT71LZ1	BUFFER[120]	// ( - , Baz1, SBz1DU) АС по температуре в АЗ2
#define idB0VT71LZ1	54	// ( - , Baz1, SBz1DU) АС по температуре в АЗ2
#define B0VZ71LZ1	BUFFER[122]	// ( - , Baz1) Обобщенный сигнал АС по АЗ2
#define idB0VZ71LZ1	55	// ( - , Baz1) Обобщенный сигнал АС по АЗ2
#define B1VP41LZ1	BUFFER[124]	// ( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	56	// ( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
#define B1VP81LZZ	BUFFER[126]	// (vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	57	// (vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
#define B2CP01RZ1	BUFFER[128]	// ( - , Baz1) Текущее давление СБРОС РБ2
#define idB2CP01RZ1	58	// ( - , Baz1) Текущее давление СБРОС РБ2
#define B2IP01IZ1	BUFFER[133]	// (vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	59	// (vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
#define B2IS12LDU	BUFFER[136]	// (vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	60	// (vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
#define B2VP41LZ1	BUFFER[138]	// ( - , Baz1) Давление СБРОС РБ2 ниже АС
#define idB2VP41LZ1	61	// ( - , Baz1) Давление СБРОС РБ2 ниже АС
#define B2VP51LZ1	BUFFER[140]	// ( - , Baz1) Давление СБРОС РБ2 ниже ПС
#define idB2VP51LZ1	62	// ( - , Baz1) Давление СБРОС РБ2 ниже ПС
#define B2VP81LZ1	BUFFER[142]	// ( - , Baz1) Давление СБРОС РБ2 в норме
#define idB2VP81LZ1	63	// ( - , Baz1) Давление СБРОС РБ2 в норме
#define B3IS11LDU	BUFFER[144]	// (vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define idB3IS11LDU	64	// (vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
#define B3IS22LDU	BUFFER[146]	// (vds32:06 - K06VDSR, - ) Приход на НУП ИС2
#define idB3IS22LDU	65	// (vds32:06 - K06VDSR, - ) Приход на НУП ИС2
#define B3VZ11LZ1	BUFFER[148]	// ( - , Baz1) АЗ от НУП ИС2
#define idB3VZ11LZ1	66	// ( - , Baz1) АЗ от НУП ИС2
#define B3VZ31LZ1	BUFFER[150]	// ( - , Baz1) АЗ от ВУ ИС2
#define idB3VZ31LZ1	67	// ( - , Baz1) АЗ от ВУ ИС2
#define B8VC01RDU	BUFFER[152]	// ( - , SBz1DU, MBz1A1, MBz1A2, MBz1A3, MBz1A4) Координата АЗ2, мм
#define idB8VC01RDU	68	// ( - , SBz1DU, MBz1A1, MBz1A2, MBz1A3, MBz1A4) Координата АЗ2, мм
#define R0AD03LZ1	BUFFER[157]	// (vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define idR0AD03LZ1	69	// (vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
#define R0AD04LZ1	BUFFER[159]	// (vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
#define idR0AD04LZ1	70	// (vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
#define R0AD05LZ1	BUFFER[161]	// (vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define idR0AD05LZ1	71	// (vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
#define R0AD14LZ1	BUFFER[163]	// (fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define idR0AD14LZ1	72	// (fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
#define R0AD21LDU	BUFFER[165]	// ( - , SBz1DU) Подключить защиту от II УР
#define idR0AD21LDU	73	// ( - , SBz1DU) Подключить защиту от II УР
#define R0DE04LZ1	BUFFER[167]	// (vas84:04 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
#define idR0DE04LZ1	74	// (vas84:04 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
#define R0DE05LZ1	BUFFER[170]	// (vds32:05 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
#define idR0DE05LZ1	75	// (vds32:05 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
#define R0DE06LZ1	BUFFER[173]	// (vds32:06 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
#define idR0DE06LZ1	76	// (vds32:06 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
#define R0DE07LZ1	BUFFER[176]	// (vds32:07 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
#define idR0DE07LZ1	77	// (vds32:07 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
#define R0DE08LZ1	BUFFER[179]	// (vds32:08 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
#define idR0DE08LZ1	78	// (vds32:08 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
#define R0DE0ALZ1	BUFFER[182]	// (fds16:0a - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
#define idR0DE0ALZ1	79	// (fds16:0a - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
#define R0DE3CLZ1	BUFFER[185]	// ( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 5
#define idR0DE3CLZ1	80	// ( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 5
#define R0DE3DLZ1	BUFFER[187]	// ( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 6
#define idR0DE3DLZ1	81	// ( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 6
#define R0DEB1LZ1	BUFFER[189]	// (sbk:20 - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
#define idR0DEB1LZ1	82	// (sbk:20 - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
#define R0DEB2LZ1	BUFFER[191]	// (sbk:20 - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
#define idR0DEB2LZ1	83	// (sbk:20 - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
#define R0DEB3LZ1	BUFFER[193]	// (sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
#define idR0DEB3LZ1	84	// (sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
#define R0DEB4LZ1	BUFFER[195]	// (sbk:20 - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
#define idR0DEB4LZ1	85	// (sbk:20 - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
#define R0EE01LZ1	BUFFER[197]	// ( - , MBz1S) Питание  АКНП1  отключить
#define idR0EE01LZ1	86	// ( - , MBz1S) Питание  АКНП1  отключить
#define R0EE02LDU	BUFFER[199]	// ( - , Baz1) Питание  АКНП  отключить
#define idR0EE02LDU	87	// ( - , Baz1) Питание  АКНП  отключить
#define R0EE02LZ1	BUFFER[201]	// ( - , MBz1S) Питание  АКНП2  отключить
#define idR0EE02LZ1	88	// ( - , MBz1S) Питание  АКНП2  отключить
#define R0EE03LZ1	BUFFER[203]	// ( - , MBz1S) Питание  АКНП3  отключить
#define idR0EE03LZ1	89	// ( - , MBz1S) Питание  АКНП3  отключить
#define R0EE04LZ1	BUFFER[205]	// ( - , MBz1S) Питание  АКНП4  отключить
#define idR0EE04LZ1	90	// ( - , MBz1S) Питание  АКНП4  отключить
#define R0ET01LZ1	BUFFER[207]	// ( - , Baz1) Признак наличия неисправности по температуре  АЗ1
#define idR0ET01LZ1	91	// ( - , Baz1) Признак наличия неисправности по температуре  АЗ1
#define R0ET02LZ1	BUFFER[209]	// ( - , Baz1) Признак наличия неисправности по температуре АЗ2
#define idR0ET02LZ1	92	// ( - , Baz1) Признак наличия неисправности по температуре АЗ2
#define R0MD34LP1	BUFFER[211]	// ( - , Baz1) Кнопка (Квитировать)
#define idR0MD34LP1	93	// ( - , Baz1) Кнопка (Квитировать)
#define R0MW11IP1	BUFFER[213]	// ( - , Baz1) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	94	// ( - , Baz1) Переключатель ВЫСТРЕЛ
#define R0MW12IP2	BUFFER[216]	// ( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define idR0MW12IP2	95	// ( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define R0S01LZ1	BUFFER[219]	// (vds32:08 - K08VDSR, - ) Отключение сетевых передач в Баз1
#define idR0S01LZ1	96	// (vds32:08 - K08VDSR, - ) Отключение сетевых передач в Баз1
#define R0VN01RS1	BUFFER[221]	// ( - , MBz1A1) Период разгона канал 1
#define idR0VN01RS1	97	// ( - , MBz1A1) Период разгона канал 1
#define R0VN01RS2	BUFFER[226]	// ( - , MBz1A2) Период разгона канал 2
#define idR0VN01RS2	98	// ( - , MBz1A2) Период разгона канал 2
#define R0VN01RS3	BUFFER[231]	// ( - , MBz1A3) Период разгона канал 3
#define idR0VN01RS3	99	// ( - , MBz1A3) Период разгона канал 3
#define R0VN01RS4	BUFFER[236]	// ( - , MBz1A4) Период разгона канал 4
#define idR0VN01RS4	100	// ( - , MBz1A4) Период разгона канал 4
#define R0VN01RZ1	BUFFER[241]	// ( - , Baz1) Уровень мощности по каналу 1
#define idR0VN01RZ1	101	// ( - , Baz1) Уровень мощности по каналу 1
#define R0VN02RS1	BUFFER[246]	// ( - , MBz1A1) Уровень мощности канал 1
#define idR0VN02RS1	102	// ( - , MBz1A1) Уровень мощности канал 1
#define R0VN02RS2	BUFFER[251]	// ( - , MBz1A2) Уровень мощности канал 2
#define idR0VN02RS2	103	// ( - , MBz1A2) Уровень мощности канал 2
#define R0VN02RS3	BUFFER[256]	// ( - , MBz1A3) Уровень мощности канал 3
#define idR0VN02RS3	104	// ( - , MBz1A3) Уровень мощности канал 3
#define R0VN02RS4	BUFFER[261]	// ( - , MBz1A4) Уровень мощности канал 4
#define idR0VN02RS4	105	// ( - , MBz1A4) Уровень мощности канал 4
#define R0VN02RZ1	BUFFER[266]	// ( - , Baz1) Уровень мощности по каналу 2
#define idR0VN02RZ1	106	// ( - , Baz1) Уровень мощности по каналу 2
#define R0VN03RZ1	BUFFER[271]	// ( - , Baz1) Уровень мощности по каналу 3
#define idR0VN03RZ1	107	// ( - , Baz1) Уровень мощности по каналу 3
#define R0VN04RZ1	BUFFER[276]	// ( - , Baz1) Уровень мощности по каналу 4
#define idR0VN04RZ1	108	// ( - , Baz1) Уровень мощности по каналу 4
#define R0VN05RZ1	BUFFER[281]	// ( - , Baz1) Период разгона по каналу 1
#define idR0VN05RZ1	109	// ( - , Baz1) Период разгона по каналу 1
#define R0VN06RZ1	BUFFER[286]	// ( - , Baz1) Период разгона по каналу 2
#define idR0VN06RZ1	110	// ( - , Baz1) Период разгона по каналу 2
#define R0VN07RZ1	BUFFER[291]	// ( - , Baz1) Период разгона по каналу 3
#define idR0VN07RZ1	111	// ( - , Baz1) Период разгона по каналу 3
#define R0VN08RZ1	BUFFER[296]	// ( - , Baz1) Период разгона по каналу 4
#define idR0VN08RZ1	112	// ( - , Baz1) Период разгона по каналу 4
#define R0VN09RZ1	BUFFER[301]	// ( - , Baz1) Усредненный период разгона
#define idR0VN09RZ1	113	// ( - , Baz1) Усредненный период разгона
#define R0VN11RZ1	BUFFER[306]	// ( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
#define idR0VN11RZ1	114	// ( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
#define R0VN61LS1	BUFFER[311]	// ( - , MBz1A1) ПС по мощности канал 1
#define idR0VN61LS1	115	// ( - , MBz1A1) ПС по мощности канал 1
#define R0VN61LS2	BUFFER[313]	// ( - , MBz1A2) ПС по мощности канал 2
#define idR0VN61LS2	116	// ( - , MBz1A2) ПС по мощности канал 2
#define R0VN61LS3	BUFFER[315]	// ( - , MBz1A3) ПС по мощности канал 3
#define idR0VN61LS3	117	// ( - , MBz1A3) ПС по мощности канал 3
#define R0VN61LS4	BUFFER[317]	// ( - , MBz1A4) ПС по мощности канал 4
#define idR0VN61LS4	118	// ( - , MBz1A4) ПС по мощности канал 4
#define R0VN61LZ1	BUFFER[319]	// ( - , Baz1) ПС по мощности канал 1
#define idR0VN61LZ1	119	// ( - , Baz1) ПС по мощности канал 1
#define R0VN62LZ1	BUFFER[321]	// ( - , Baz1) ПС по мощности канал 2
#define idR0VN62LZ1	120	// ( - , Baz1) ПС по мощности канал 2
#define R0VN63LZ1	BUFFER[323]	// ( - , Baz1) ПС по мощности канал 3
#define idR0VN63LZ1	121	// ( - , Baz1) ПС по мощности канал 3
#define R0VN64LZ1	BUFFER[325]	// ( - , Baz1) ПС по мощности канал 4
#define idR0VN64LZ1	122	// ( - , Baz1) ПС по мощности канал 4
#define R0VN65LS1	BUFFER[327]	// ( - , MBz1A1) ПС по периоду разгона канал 1
#define idR0VN65LS1	123	// ( - , MBz1A1) ПС по периоду разгона канал 1
#define R0VN65LS2	BUFFER[329]	// ( - , MBz1A2) ПС по периоду разгона  канал 2
#define idR0VN65LS2	124	// ( - , MBz1A2) ПС по периоду разгона  канал 2
#define R0VN65LS3	BUFFER[331]	// ( - , MBz1A3) ПС по периоду разгона канал 3
#define idR0VN65LS3	125	// ( - , MBz1A3) ПС по периоду разгона канал 3
#define R0VN65LS4	BUFFER[333]	// ( - , MBz1A4) ПС по периоду разгона канал 4
#define idR0VN65LS4	126	// ( - , MBz1A4) ПС по периоду разгона канал 4
#define R0VN65LZ1	BUFFER[335]	// ( - , Baz1) ПС по периоду разгона канал 1
#define idR0VN65LZ1	127	// ( - , Baz1) ПС по периоду разгона канал 1
#define R0VN66LZ1	BUFFER[337]	// ( - , Baz1) ПС по периоду разгона канал 2
#define idR0VN66LZ1	128	// ( - , Baz1) ПС по периоду разгона канал 2
#define R0VN67LZ1	BUFFER[339]	// ( - , Baz1) ПС по периоду разгона канал 3
#define idR0VN67LZ1	129	// ( - , Baz1) ПС по периоду разгона канал 3
#define R0VN68LZ1	BUFFER[341]	// ( - , Baz1) ПС по периоду разгона канал 4
#define idR0VN68LZ1	130	// ( - , Baz1) ПС по периоду разгона канал 4
#define R0VN69LZ1	BUFFER[343]	// ( - , Baz1) ПС по усредненному периоду
#define idR0VN69LZ1	131	// ( - , Baz1) ПС по усредненному периоду
#define R0VN70LZ1	BUFFER[345]	// ( - , Baz1) АЗ по АС мощности РУ
#define idR0VN70LZ1	132	// ( - , Baz1) АЗ по АС мощности РУ
#define R0VN71LZ1	BUFFER[347]	// (vds32:05 - K01VDSR, Baz1) АС по мощности канал 1
#define idR0VN71LZ1	133	// (vds32:05 - K01VDSR, Baz1) АС по мощности канал 1
#define R0VN72LZ1	BUFFER[349]	// (vds32:06 - K01VDSR, Baz1) АС по мощности канал 2
#define idR0VN72LZ1	134	// (vds32:06 - K01VDSR, Baz1) АС по мощности канал 2
#define R0VN73LZ1	BUFFER[351]	// (vds32:08 - K01VDSR, Baz1) АС по мощности канал 3
#define idR0VN73LZ1	135	// (vds32:08 - K01VDSR, Baz1) АС по мощности канал 3
#define R0VN74LZ1	BUFFER[353]	// (vds32:07 - K01VDSR, Baz1) АС по мощности канал 4
#define idR0VN74LZ1	136	// (vds32:07 - K01VDSR, Baz1) АС по мощности канал 4
#define R0VN75LZ1	BUFFER[355]	// (vds32:05 - K02VDSR, Baz1) АС по периоду разгона канал 1
#define idR0VN75LZ1	137	// (vds32:05 - K02VDSR, Baz1) АС по периоду разгона канал 1
#define R0VN76LZ1	BUFFER[357]	// (vds32:06 - K02VDSR, Baz1) АС по периоду разгона канал  2
#define idR0VN76LZ1	138	// (vds32:06 - K02VDSR, Baz1) АС по периоду разгона канал  2
#define R0VN77LZ1	BUFFER[359]	// (vds32:08 - K02VDSR, Baz1) АС по периоду разгона канал  3
#define idR0VN77LZ1	139	// (vds32:08 - K02VDSR, Baz1) АС по периоду разгона канал  3
#define R0VN78LZ1	BUFFER[361]	// (vds32:07 - K02VDSR, Baz1) АС по периоду разгона канал  4
#define idR0VN78LZ1	140	// (vds32:07 - K02VDSR, Baz1) АС по периоду разгона канал  4
#define R0VN79LZ1	BUFFER[363]	// ( - , Baz1) АС по усредненному периоду
#define idR0VN79LZ1	141	// ( - , Baz1) АС по усредненному периоду
#define R0VN80LZ1	BUFFER[365]	// ( - , Baz1) АЗ по АС периода разгона РУ
#define idR0VN80LZ1	142	// ( - , Baz1) АЗ по АС периода разгона РУ
#define R0VP73LZ1	BUFFER[367]	// ( - , Baz1, SBz1DU) ПС давления для РУ
#define idR0VP73LZ1	143	// ( - , Baz1, SBz1DU) ПС давления для РУ
#define R0VR02RZ1	BUFFER[369]	// ( - , Baz1) Усредненная реактивность
#define idR0VR02RZ1	144	// ( - , Baz1) Усредненная реактивность
#define R0VW13LDU	BUFFER[374]	// ( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	145	// ( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	BUFFER[376]	// ( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	146	// ( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R0VZ05U	BUFFER[378]	// ( - , - ) причины сброса
#define idR0VZ05U	147	// ( - , - ) причины сброса
#define R0VZ05UZ1	BUFFER[383]	// ( - , Baz1) Индикатор причины сброса
#define idR0VZ05UZ1	148	// ( - , Baz1) Индикатор причины сброса
#define R0VZ71LZ1	BUFFER[388]	// (fds16:0a - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
#define idR0VZ71LZ1	149	// (fds16:0a - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
#define R6IS66LZZ	BUFFER[390]	// ( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	150	// ( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	BUFFER[392]	// ( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	151	// ( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	BUFFER[394]	// ( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	152	// ( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define R7II71LZ1	BUFFER[396]	// (vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
#define idR7II71LZ1	153	// (vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
#define R7II72LZ1	BUFFER[398]	// (vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
#define idR7II72LZ1	154	// (vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
#define R7II73LZ1	BUFFER[400]	// (vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
#define idR7II73LZ1	155	// (vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
#define TTLBaz1	BUFFER[402]	// ( - , Baz1) ttl
#define idTTLBaz1	156	// ( - , Baz1) ttl
#define TestDiagnBaz1	BUFFER[405]	// ( - , Baz1) Неисправность от диагностики
#define idTestDiagnBaz1	157	// ( - , Baz1) Неисправность от диагностики
#define bFirstEnterFlag	BUFFER[407]	// (bFirstEnterFlag) 
#define idbFirstEnterFlag	158	// (bFirstEnterFlag) 
#define fEM_A2UP03RZZ	BUFFER[409]	// (A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define idfEM_A2UP03RZZ	159	// (A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define fEM_A2UP04RZZ	BUFFER[414]	// (A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define idfEM_A2UP04RZZ	160	// (A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define fEM_A2UP41RZZ	BUFFER[419]	// (A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define idfEM_A2UP41RZZ	161	// (A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define fEM_A2UP42RZZ	BUFFER[424]	// (A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define idfEM_A2UP42RZZ	162	// (A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define fEM_A2UP51RZZ	BUFFER[429]	// (A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define idfEM_A2UP51RZZ	163	// (A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define fEM_A2UP52RZZ	BUFFER[434]	// (A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define idfEM_A2UP52RZZ	164	// (A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define fEM_A2UP81RZZ	BUFFER[439]	// (A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP81RZZ	165	// (A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP82RZZ	BUFFER[444]	// (A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP82RZZ	166	// (A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP83RZZ	BUFFER[449]	// (A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP83RZZ	167	// (A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP84RZZ	BUFFER[454]	// (A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP84RZZ	168	// (A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_R0UL05RDU	BUFFER[459]	// (R0UL05RDU) Время задержки АЗ от НУП ИС(сек)
#define idfEM_R0UL05RDU	169	// (R0UL05RDU) Время задержки АЗ от НУП ИС(сек)
#define fEM_R0UL07RDU	BUFFER[464]	// (R0UL07RDU) Время задержки  срабатывания АС II УР
#define idfEM_R0UL07RDU	170	// (R0UL07RDU) Время задержки  срабатывания АС II УР
#define fEM_R0UL25RDU	BUFFER[469]	// (R0UL25RDU) Время задержки АЗ от ВУ ИС сек
#define idfEM_R0UL25RDU	171	// (R0UL25RDU) Время задержки АЗ от ВУ ИС сек
#define fEM_R0UR01RZZ	BUFFER[474]	// (R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RZZ	172	// (R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R0UR04RZZ	BUFFER[479]	// (R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define idfEM_R0UR04RZZ	173	// (R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define fEM_R0UT01RZZ	BUFFER[484]	// (R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	174	// (R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_R0UT02RZZ	BUFFER[489]	// (R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	175	// (R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT61RZZ	BUFFER[494]	// (R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	176	// (R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	BUFFER[499]	// (R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	177	// (R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	BUFFER[504]	// (R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	178	// (R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT72RZZ	BUFFER[509]	// (R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	179	// (R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define internal1_m104_y1	BUFFER[514]	// (internal1_m104_y1) y1 - внутренний параметр
#define idinternal1_m104_y1	180	// (internal1_m104_y1) y1 - внутренний параметр
#define internal1_m106_y1	BUFFER[516]	// (internal1_m106_y1) y1 - внутренний параметр
#define idinternal1_m106_y1	181	// (internal1_m106_y1) y1 - внутренний параметр
#define internal1_m107_tx	BUFFER[518]	// (internal1_m107_tx) tx - время накопленное сек
#define idinternal1_m107_tx	182	// (internal1_m107_tx) tx - время накопленное сек
#define internal1_m107_y0	BUFFER[523]	// (internal1_m107_y0) y0
#define idinternal1_m107_y0	183	// (internal1_m107_y0) y0
#define internal1_m110_tx	BUFFER[525]	// (internal1_m110_tx) tx - время накопленное сек
#define idinternal1_m110_tx	184	// (internal1_m110_tx) tx - время накопленное сек
#define internal1_m110_y0	BUFFER[530]	// (internal1_m110_y0) y0
#define idinternal1_m110_y0	185	// (internal1_m110_y0) y0
#define internal1_m121_y1	BUFFER[532]	// (internal1_m121_y1) y1 - внутренний параметр
#define idinternal1_m121_y1	186	// (internal1_m121_y1) y1 - внутренний параметр
#define internal1_m124_y0	BUFFER[534]	// (internal1_m124_y0) state
#define idinternal1_m124_y0	187	// (internal1_m124_y0) state
#define internal1_m128_y0	BUFFER[536]	// (internal1_m128_y0) state
#define idinternal1_m128_y0	188	// (internal1_m128_y0) state
#define internal1_m134_tx	BUFFER[538]	// (internal1_m134_tx) tx - время накопленное сек
#define idinternal1_m134_tx	189	// (internal1_m134_tx) tx - время накопленное сек
#define internal1_m134_y0	BUFFER[543]	// (internal1_m134_y0) y0
#define idinternal1_m134_y0	190	// (internal1_m134_y0) y0
#define internal1_m135_tx	BUFFER[545]	// (internal1_m135_tx) tx - время накопленное сек
#define idinternal1_m135_tx	191	// (internal1_m135_tx) tx - время накопленное сек
#define internal1_m135_y0	BUFFER[550]	// (internal1_m135_y0) y0
#define idinternal1_m135_y0	192	// (internal1_m135_y0) y0
#define internal1_m146_y0	BUFFER[552]	// (internal1_m146_y0) y0
#define idinternal1_m146_y0	193	// (internal1_m146_y0) y0
#define internal1_m148_y0	BUFFER[557]	// (internal1_m148_y0) y0
#define idinternal1_m148_y0	194	// (internal1_m148_y0) y0
#define internal1_m156_y1	BUFFER[562]	// (internal1_m156_y1) y1 - внутренний параметр
#define idinternal1_m156_y1	195	// (internal1_m156_y1) y1 - внутренний параметр
#define internal1_m159_y1	BUFFER[564]	// (internal1_m159_y1) y1 - внутренний параметр
#define idinternal1_m159_y1	196	// (internal1_m159_y1) y1 - внутренний параметр
#define internal1_m167_y1	BUFFER[566]	// (internal1_m167_y1) y1 - внутренний параметр
#define idinternal1_m167_y1	197	// (internal1_m167_y1) y1 - внутренний параметр
#define internal1_m170_y1	BUFFER[568]	// (internal1_m170_y1) y1 - внутренний параметр
#define idinternal1_m170_y1	198	// (internal1_m170_y1) y1 - внутренний параметр
#define internal1_m205_TImAZ2UR	BUFFER[570]	// (internal1_m205_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
#define idinternal1_m205_TImAZ2UR	199	// (internal1_m205_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
#define internal1_m205_TImNupIs	BUFFER[575]	// (internal1_m205_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
#define idinternal1_m205_TImNupIs	200	// (internal1_m205_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
#define internal1_m205_TImVuIs	BUFFER[580]	// (internal1_m205_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
#define idinternal1_m205_TImVuIs	201	// (internal1_m205_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
#define internal1_m205_TNupIs1	BUFFER[585]	// (internal1_m205_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
#define idinternal1_m205_TNupIs1	202	// (internal1_m205_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
#define internal1_m205_TNupIs2	BUFFER[590]	// (internal1_m205_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
#define idinternal1_m205_TNupIs2	203	// (internal1_m205_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
#define internal1_m205_TVuIs1	BUFFER[595]	// (internal1_m205_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
#define idinternal1_m205_TVuIs1	204	// (internal1_m205_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
#define internal1_m205_TVuIs2	BUFFER[600]	// (internal1_m205_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
#define idinternal1_m205_TVuIs2	205	// (internal1_m205_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
#define internal1_m205_fef	BUFFER[605]	// (internal1_m205_fef) fef
#define idinternal1_m205_fef	206	// (internal1_m205_fef) fef
#define internal1_m210_tx	BUFFER[607]	// (internal1_m210_tx) tx - время накопленное сек
#define idinternal1_m210_tx	207	// (internal1_m210_tx) tx - время накопленное сек
#define internal1_m210_y0	BUFFER[612]	// (internal1_m210_y0) y0
#define idinternal1_m210_y0	208	// (internal1_m210_y0) y0
#define internal1_m225_tx	BUFFER[614]	// (internal1_m225_tx) tx - время накопленное сек
#define idinternal1_m225_tx	209	// (internal1_m225_tx) tx - время накопленное сек
#define internal1_m225_y0	BUFFER[619]	// (internal1_m225_y0) y0
#define idinternal1_m225_y0	210	// (internal1_m225_y0) y0
#define internal1_m280_q0	BUFFER[621]	// (internal1_m280_q0) q0 - внутренний параметр
#define idinternal1_m280_q0	211	// (internal1_m280_q0) q0 - внутренний параметр
#define internal1_m33_tx	BUFFER[626]	// (internal1_m33_tx) tx - внутренний параметр
#define idinternal1_m33_tx	212	// (internal1_m33_tx) tx - внутренний параметр
#define internal1_m90_y0	BUFFER[629]	// (internal1_m90_y0) y0
#define idinternal1_m90_y0	213	// (internal1_m90_y0) y0
#define internal1_m92_y0	BUFFER[634]	// (internal1_m92_y0) y0
#define idinternal1_m92_y0	214	// (internal1_m92_y0) y0
#define internal1_m94_y1	BUFFER[639]	// (internal1_m94_y1) y1 - внутренний параметр
#define idinternal1_m94_y1	215	// (internal1_m94_y1) y1 - внутренний параметр
#define var16	BUFFER[641]	// Внутренняя переменная var16
#define idvar16	216	// Внутренняя переменная var16
#define var26	BUFFER[643]	// Внутренняя переменная var26
#define idvar26	217	// Внутренняя переменная var26
#define var83	BUFFER[645]	// Внутренняя переменная var83
#define idvar83	218	// Внутренняя переменная var83
#define var115	BUFFER[647]	// Внутренняя переменная var115
#define idvar115	219	// Внутренняя переменная var115
#define var8	BUFFER[649]	// Внутренняя переменная var8
#define idvar8	220	// Внутренняя переменная var8
#define var13	BUFFER[651]	// Внутренняя переменная var13
#define idvar13	221	// Внутренняя переменная var13
#define var51	BUFFER[653]	// Внутренняя переменная var51
#define idvar51	222	// Внутренняя переменная var51
#define var117	BUFFER[655]	// Внутренняя переменная var117
#define idvar117	223	// Внутренняя переменная var117
#define var139	BUFFER[657]	// Внутренняя переменная var139
#define idvar139	224	// Внутренняя переменная var139
#define vainSBool	BUFFER[659]	// Внутренняя переменная vainSBool
#define idvainSBool	225	// Внутренняя переменная vainSBool
#define var33	BUFFER[661]	// Внутренняя переменная var33
#define idvar33	226	// Внутренняя переменная var33
#define var38	BUFFER[663]	// Внутренняя переменная var38
#define idvar38	227	// Внутренняя переменная var38
#define var93	BUFFER[665]	// Внутренняя переменная var93
#define idvar93	228	// Внутренняя переменная var93
#define var95	BUFFER[667]	// Внутренняя переменная var95
#define idvar95	229	// Внутренняя переменная var95
#define var124	BUFFER[669]	// Внутренняя переменная var124
#define idvar124	230	// Внутренняя переменная var124
#define var131	BUFFER[674]	// Внутренняя переменная var131
#define idvar131	231	// Внутренняя переменная var131
#define vainSInt	BUFFER[676]	// Внутренняя переменная vainSInt
#define idvainSInt	232	// Внутренняя переменная vainSInt
#define var17	BUFFER[681]	// Внутренняя переменная var17
#define idvar17	233	// Внутренняя переменная var17
#define var88	BUFFER[683]	// Внутренняя переменная var88
#define idvar88	234	// Внутренняя переменная var88
#define var121	BUFFER[685]	// Внутренняя переменная var121
#define idvar121	235	// Внутренняя переменная var121
#define var54	BUFFER[687]	// Внутренняя переменная var54
#define idvar54	236	// Внутренняя переменная var54
#define var66	BUFFER[689]	// Внутренняя переменная var66
#define idvar66	237	// Внутренняя переменная var66
#define var49	BUFFER[691]	// Внутренняя переменная var49
#define idvar49	238	// Внутренняя переменная var49
#define var52	BUFFER[693]	// Внутренняя переменная var52
#define idvar52	239	// Внутренняя переменная var52
#define var61	BUFFER[695]	// Внутренняя переменная var61
#define idvar61	240	// Внутренняя переменная var61
#define var75	BUFFER[697]	// Внутренняя переменная var75
#define idvar75	241	// Внутренняя переменная var75
#define var84	BUFFER[699]	// Внутренняя переменная var84
#define idvar84	242	// Внутренняя переменная var84
#define var103	BUFFER[701]	// Внутренняя переменная var103
#define idvar103	243	// Внутренняя переменная var103
#define var127	BUFFER[703]	// Внутренняя переменная var127
#define idvar127	244	// Внутренняя переменная var127
#define var128	BUFFER[708]	// Внутренняя переменная var128
#define idvar128	245	// Внутренняя переменная var128
#define var58	BUFFER[710]	// Внутренняя переменная var58
#define idvar58	246	// Внутренняя переменная var58
#define var67	BUFFER[712]	// Внутренняя переменная var67
#define idvar67	247	// Внутренняя переменная var67
#define var62	BUFFER[714]	// Внутренняя переменная var62
#define idvar62	248	// Внутренняя переменная var62
#define var82	BUFFER[716]	// Внутренняя переменная var82
#define idvar82	249	// Внутренняя переменная var82
#define var112	BUFFER[718]	// Внутренняя переменная var112
#define idvar112	250	// Внутренняя переменная var112
#define var129	BUFFER[723]	// Внутренняя переменная var129
#define idvar129	251	// Внутренняя переменная var129
#define var12	BUFFER[725]	// Внутренняя переменная var12
#define idvar12	252	// Внутренняя переменная var12
#define var44	BUFFER[727]	// Внутренняя переменная var44
#define idvar44	253	// Внутренняя переменная var44
#define var47	BUFFER[729]	// Внутренняя переменная var47
#define idvar47	254	// Внутренняя переменная var47
#define var53	BUFFER[731]	// Внутренняя переменная var53
#define idvar53	255	// Внутренняя переменная var53
#define var73	BUFFER[733]	// Внутренняя переменная var73
#define idvar73	256	// Внутренняя переменная var73
#define var91	BUFFER[735]	// Внутренняя переменная var91
#define idvar91	257	// Внутренняя переменная var91
#define var105	BUFFER[737]	// Внутренняя переменная var105
#define idvar105	258	// Внутренняя переменная var105
#define var5	BUFFER[742]	// Внутренняя переменная var5
#define idvar5	259	// Внутренняя переменная var5
#define var19	BUFFER[744]	// Внутренняя переменная var19
#define idvar19	260	// Внутренняя переменная var19
#define var78	BUFFER[746]	// Внутренняя переменная var78
#define idvar78	261	// Внутренняя переменная var78
#define var102	BUFFER[748]	// Внутренняя переменная var102
#define idvar102	262	// Внутренняя переменная var102
#define var136	BUFFER[753]	// Внутренняя переменная var136
#define idvar136	263	// Внутренняя переменная var136
#define var20	BUFFER[755]	// Внутренняя переменная var20
#define idvar20	264	// Внутренняя переменная var20
#define var25	BUFFER[757]	// Внутренняя переменная var25
#define idvar25	265	// Внутренняя переменная var25
#define var133	BUFFER[759]	// Внутренняя переменная var133
#define idvar133	266	// Внутренняя переменная var133
#define var118	BUFFER[761]	// Внутренняя переменная var118
#define idvar118	267	// Внутренняя переменная var118
#define var120	BUFFER[763]	// Внутренняя переменная var120
#define idvar120	268	// Внутренняя переменная var120
#define var99	BUFFER[765]	// Внутренняя переменная var99
#define idvar99	269	// Внутренняя переменная var99
#define var43	BUFFER[767]	// Внутренняя переменная var43
#define idvar43	270	// Внутренняя переменная var43
#define var94	BUFFER[769]	// Внутренняя переменная var94
#define idvar94	271	// Внутренняя переменная var94
#define var77	BUFFER[771]	// Внутренняя переменная var77
#define idvar77	272	// Внутренняя переменная var77
#define var92	BUFFER[773]	// Внутренняя переменная var92
#define idvar92	273	// Внутренняя переменная var92
#define var14	BUFFER[775]	// Внутренняя переменная var14
#define idvar14	274	// Внутренняя переменная var14
#define var31	BUFFER[777]	// Внутренняя переменная var31
#define idvar31	275	// Внутренняя переменная var31
#define var34	BUFFER[779]	// Внутренняя переменная var34
#define idvar34	276	// Внутренняя переменная var34
#define var72	BUFFER[781]	// Внутренняя переменная var72
#define idvar72	277	// Внутренняя переменная var72
#define var74	BUFFER[783]	// Внутренняя переменная var74
#define idvar74	278	// Внутренняя переменная var74
#define var87	BUFFER[785]	// Внутренняя переменная var87
#define idvar87	279	// Внутренняя переменная var87
#define var64	BUFFER[787]	// Внутренняя переменная var64
#define idvar64	280	// Внутренняя переменная var64
#define var65	BUFFER[789]	// Внутренняя переменная var65
#define idvar65	281	// Внутренняя переменная var65
#define var76	BUFFER[791]	// Внутренняя переменная var76
#define idvar76	282	// Внутренняя переменная var76
#define var79	BUFFER[793]	// Внутренняя переменная var79
#define idvar79	283	// Внутренняя переменная var79
#define var28	BUFFER[795]	// Внутренняя переменная var28
#define idvar28	284	// Внутренняя переменная var28
#define var40	BUFFER[797]	// Внутренняя переменная var40
#define idvar40	285	// Внутренняя переменная var40
#define var122	BUFFER[799]	// Внутренняя переменная var122
#define idvar122	286	// Внутренняя переменная var122
#define var125	BUFFER[801]	// Внутренняя переменная var125
#define idvar125	287	// Внутренняя переменная var125
#define var126	BUFFER[803]	// Внутренняя переменная var126
#define idvar126	288	// Внутренняя переменная var126
#define var42	BUFFER[805]	// Внутренняя переменная var42
#define idvar42	289	// Внутренняя переменная var42
#define var116	BUFFER[807]	// Внутренняя переменная var116
#define idvar116	290	// Внутренняя переменная var116
#define var23	BUFFER[809]	// Внутренняя переменная var23
#define idvar23	291	// Внутренняя переменная var23
#define var55	BUFFER[811]	// Внутренняя переменная var55
#define idvar55	292	// Внутренняя переменная var55
#define var89	BUFFER[813]	// Внутренняя переменная var89
#define idvar89	293	// Внутренняя переменная var89
#define var100	BUFFER[815]	// Внутренняя переменная var100
#define idvar100	294	// Внутренняя переменная var100
#define var4	BUFFER[817]	// Внутренняя переменная var4
#define idvar4	295	// Внутренняя переменная var4
#define var11	BUFFER[819]	// Внутренняя переменная var11
#define idvar11	296	// Внутренняя переменная var11
#define var37	BUFFER[821]	// Внутренняя переменная var37
#define idvar37	297	// Внутренняя переменная var37
#define var69	BUFFER[823]	// Внутренняя переменная var69
#define idvar69	298	// Внутренняя переменная var69
#define var81	BUFFER[825]	// Внутренняя переменная var81
#define idvar81	299	// Внутренняя переменная var81
#define var111	BUFFER[827]	// Внутренняя переменная var111
#define idvar111	300	// Внутренняя переменная var111
#define var135	BUFFER[829]	// Внутренняя переменная var135
#define idvar135	301	// Внутренняя переменная var135
#define var1	BUFFER[831]	// Внутренняя переменная var1
#define idvar1	302	// Внутренняя переменная var1
#define var24	BUFFER[833]	// Внутренняя переменная var24
#define idvar24	303	// Внутренняя переменная var24
#define vainSFloat	BUFFER[835]	// Внутренняя переменная vainSFloat
#define idvainSFloat	304	// Внутренняя переменная vainSFloat
#define var22	BUFFER[840]	// Внутренняя переменная var22
#define idvar22	305	// Внутренняя переменная var22
#define var45	BUFFER[842]	// Внутренняя переменная var45
#define idvar45	306	// Внутренняя переменная var45
#define var59	BUFFER[844]	// Внутренняя переменная var59
#define idvar59	307	// Внутренняя переменная var59
#define var140	BUFFER[846]	// Внутренняя переменная var140
#define idvar140	308	// Внутренняя переменная var140
#define var2	BUFFER[848]	// Внутренняя переменная var2
#define idvar2	309	// Внутренняя переменная var2
#define var15	BUFFER[850]	// Внутренняя переменная var15
#define idvar15	310	// Внутренняя переменная var15
#define var60	BUFFER[852]	// Внутренняя переменная var60
#define idvar60	311	// Внутренняя переменная var60
#define var104	BUFFER[854]	// Внутренняя переменная var104
#define idvar104	312	// Внутренняя переменная var104
#define var141	BUFFER[859]	// Внутренняя переменная var141
#define idvar141	313	// Внутренняя переменная var141
#define var27	BUFFER[861]	// Внутренняя переменная var27
#define idvar27	314	// Внутренняя переменная var27
#define var30	BUFFER[863]	// Внутренняя переменная var30
#define idvar30	315	// Внутренняя переменная var30
#define var98	BUFFER[865]	// Внутренняя переменная var98
#define idvar98	316	// Внутренняя переменная var98
#define var109	BUFFER[867]	// Внутренняя переменная var109
#define idvar109	317	// Внутренняя переменная var109
#define var113	BUFFER[869]	// Внутренняя переменная var113
#define idvar113	318	// Внутренняя переменная var113
#define vainSLong	BUFFER[878]	// Внутренняя переменная vainSLong
#define idvainSLong	319	// Внутренняя переменная vainSLong
#define var41	BUFFER[887]	// Внутренняя переменная var41
#define idvar41	320	// Внутренняя переменная var41
#define var97	BUFFER[889]	// Внутренняя переменная var97
#define idvar97	321	// Внутренняя переменная var97
#define var63	BUFFER[891]	// Внутренняя переменная var63
#define idvar63	322	// Внутренняя переменная var63
#define var114	BUFFER[893]	// Внутренняя переменная var114
#define idvar114	323	// Внутренняя переменная var114
#define var123	BUFFER[902]	// Внутренняя переменная var123
#define idvar123	324	// Внутренняя переменная var123
#define var134	BUFFER[904]	// Внутренняя переменная var134
#define idvar134	325	// Внутренняя переменная var134
#define var138	BUFFER[906]	// Внутренняя переменная var138
#define idvar138	326	// Внутренняя переменная var138
#define var142	BUFFER[908]	// Внутренняя переменная var142
#define idvar142	327	// Внутренняя переменная var142
#define var6	BUFFER[910]	// Внутренняя переменная var6
#define idvar6	328	// Внутренняя переменная var6
#define var57	BUFFER[912]	// Внутренняя переменная var57
#define idvar57	329	// Внутренняя переменная var57
#define var29	BUFFER[914]	// Внутренняя переменная var29
#define idvar29	330	// Внутренняя переменная var29
#define var35	BUFFER[916]	// Внутренняя переменная var35
#define idvar35	331	// Внутренняя переменная var35
#define var108	BUFFER[918]	// Внутренняя переменная var108
#define idvar108	332	// Внутренняя переменная var108
#define var119	BUFFER[920]	// Внутренняя переменная var119
#define idvar119	333	// Внутренняя переменная var119
#define var10	BUFFER[922]	// Внутренняя переменная var10
#define idvar10	334	// Внутренняя переменная var10
#define var86	BUFFER[924]	// Внутренняя переменная var86
#define idvar86	335	// Внутренняя переменная var86
#define var71	BUFFER[926]	// Внутренняя переменная var71
#define idvar71	336	// Внутренняя переменная var71
#define var96	BUFFER[928]	// Внутренняя переменная var96
#define idvar96	337	// Внутренняя переменная var96
#define var101	BUFFER[930]	// Внутренняя переменная var101
#define idvar101	338	// Внутренняя переменная var101
#define var107	BUFFER[935]	// Внутренняя переменная var107
#define idvar107	339	// Внутренняя переменная var107
#define var36	BUFFER[937]	// Внутренняя переменная var36
#define idvar36	340	// Внутренняя переменная var36
#define var56	BUFFER[939]	// Внутренняя переменная var56
#define idvar56	341	// Внутренняя переменная var56
#define var21	BUFFER[941]	// Внутренняя переменная var21
#define idvar21	342	// Внутренняя переменная var21
#define var7	BUFFER[946]	// Внутренняя переменная var7
#define idvar7	343	// Внутренняя переменная var7
#define var9	BUFFER[948]	// Внутренняя переменная var9
#define idvar9	344	// Внутренняя переменная var9
#define var106	BUFFER[950]	// Внутренняя переменная var106
#define idvar106	345	// Внутренняя переменная var106
#define var137	BUFFER[952]	// Внутренняя переменная var137
#define idvar137	346	// Внутренняя переменная var137
#define var68	BUFFER[954]	// Внутренняя переменная var68
#define idvar68	347	// Внутренняя переменная var68
#define var90	BUFFER[956]	// Внутренняя переменная var90
#define idvar90	348	// Внутренняя переменная var90
#define var39	BUFFER[958]	// Внутренняя переменная var39
#define idvar39	349	// Внутренняя переменная var39
#define var46	BUFFER[960]	// Внутренняя переменная var46
#define idvar46	350	// Внутренняя переменная var46
#define var3	BUFFER[962]	// Внутренняя переменная var3
#define idvar3	351	// Внутренняя переменная var3
#define var32	BUFFER[964]	// Внутренняя переменная var32
#define idvar32	352	// Внутренняя переменная var32
#define var18	BUFFER[966]	// Внутренняя переменная var18
#define idvar18	353	// Внутренняя переменная var18
#define var70	BUFFER[968]	// Внутренняя переменная var70
#define idvar70	354	// Внутренняя переменная var70
#define var80	BUFFER[970]	// Внутренняя переменная var80
#define idvar80	355	// Внутренняя переменная var80
#define var85	BUFFER[972]	// Внутренняя переменная var85
#define idvar85	356	// Внутренняя переменная var85
#define var110	BUFFER[974]	// Внутренняя переменная var110
#define idvar110	357	// Внутренняя переменная var110
#define var48	BUFFER[976]	// Внутренняя переменная var48
#define idvar48	358	// Внутренняя переменная var48
#define var50	BUFFER[978]	// Внутренняя переменная var50
#define idvar50	359	// Внутренняя переменная var50
#pragma pack(push,1)
static VarCtrl allVariables[]={ 			 //Описание всех переменных
	{1	,8	,1	,&A0CT01IZ1},	//( - , Baz1, SBz1DU) Температура АЗ1-1
	{2	,1	,1	,&A0EE00LZ1},	//( - , Baz1) Исправность АКНП АЗ1
	{3	,1	,1	,&A0EE01LS1},	//(vds32:05 - K03VDSR, - ) Исправность АКНП канал 1
	{4	,1	,1	,&A0EE01LS2},	//(vds32:06 - K03VDSR, - ) Исправность АКНП  канал 2
	{5	,1	,1	,&A0EE01LS3},	//(vds32:08 - K03VDSR, - ) Исправность АКНП канал 3
	{6	,1	,1	,&A0EE01LS4},	//(vds32:07 - K03VDSR, - ) Исправность АКНП канал 4
	{7	,1	,1	,&A0EE01LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП1
	{8	,1	,1	,&A0EE02LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП2
	{9	,1	,1	,&A0EE03LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП3
	{10	,1	,1	,&A0EE04LZ1},	//( - , Baz1, SBz1DU) Исправность АКНП4
	{11	,1	,1	,&A0EE05LZ1},	//( - , Baz1) Исправность сети АКНП1
	{12	,1	,1	,&A0EE06LZ1},	//( - , Baz1) Исправность сети АКНП2
	{13	,1	,1	,&A0EE07LZ1},	//( - , Baz1) Исправность сети АКНП3
	{14	,1	,1	,&A0EE08LZ1},	//( - , Baz1) Исправность сети АКНП4
	{15	,3	,1	,&A0EP02IZ1},	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
	{16	,3	,1	,&A0IT01IZ1},	//(vas84:04 - K01VASR, - ) Температура АЗ1-1
	{17	,1	,1	,&A0VN71LS1},	//(vds32:05 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 1
	{18	,1	,1	,&A0VN71LS2},	//(vds32:06 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 2
	{19	,1	,1	,&A0VN71LS3},	//(vds32:08 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 3
	{20	,1	,1	,&A0VN71LS4},	//(vds32:07 - K04VDSR, - ) Блокировка автоматического подъёма ББ канал 4
	{21	,1	,1	,&A0VN71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
	{22	,1	,1	,&A0VN81LZ1},	//( - , Baz1) АЗ по АС периода разгона АЗ1
	{23	,1	,1	,&A0VP41LZ1},	//( - , Baz1) Давление АЗ1 ниже АС
	{24	,1	,1	,&A0VP71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
	{25	,1	,1	,&A0VP81LZZ},	//(vds32:08 - K09VDSR, - ) Давление  АЗ1 в норме
	{26	,1	,1	,&A0VT61LZ1},	//( - , Baz1) ПС по температуре в АЗ1
	{27	,1	,1	,&A0VT71LZ1},	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
	{28	,1	,1	,&A0VZ71LZ1},	//( - , Baz1) Обобщенный сигнал АС по АЗ1
	{29	,1	,1	,&A1VN71LZ1},	//(fds16:0a - K04FDSR, - ) Блокировка автоматического подъёма ББ
	{30	,1	,1	,&A1VP41LZ1},	//( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
	{31	,1	,1	,&A1VP81LZZ},	//(vds32:08 - K10VDSR, - ) Давление СБРОС ББ1 в норме
	{32	,8	,1	,&A2CP01RZ1},	//( - , Baz1) Текущее давление СБРОС РБ1
	{33	,3	,1	,&A2IP01IZ1},	//(vas84:04 - K02VASR, - ) Текущее давление СБРОС РБ1
	{34	,1	,1	,&A2IS12LDU},	//(vds32:05 - K10VDSR, - ) Магнит РБ1 зацеплен
	{35	,1	,1	,&A2VP41LZ1},	//( - , Baz1) Давление СБРОС РБ1 ниже АС
	{36	,1	,1	,&A2VP51LZ1},	//( - , Baz1) Давление СБРОС РБ1 ниже ПС
	{37	,1	,1	,&A2VP81LZ1},	//( - , Baz1) Давление СБРОС РБ1 в норме
	{38	,1	,1	,&A3IS11LDU},	//(vds32:05 - K05VDSR, - ) Приход на ВУ ИС1
	{39	,1	,1	,&A3IS22LDU},	//(vds32:05 - K06VDSR, - ) Приход на НУП ИС1
	{40	,1	,1	,&A3VZ11LZ1},	//( - , Baz1) АЗ от НУП ИС1
	{41	,1	,1	,&A3VZ13LZ1},	//(fds16:0a - K01FDSR, - ) Имитация АЗ от ВУ ИС
	{42	,1	,1	,&A3VZ15LZ1},	//(fds16:0a - K02FDSR, - ) Имитация АЗ от НУП ИС
	{43	,1	,1	,&A3VZ31LZ1},	//( - , Baz1) АЗ от ВУ ИС1
	{44	,8	,1	,&B0CT01IZ1},	//( - , Baz1, SBz1DU) Температура АЗ2-1
	{45	,1	,1	,&B0EE00LZ1},	//( - , Baz1) Исправность АКНП АЗ2
	{46	,3	,1	,&B0EP02IZ1},	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
	{47	,3	,1	,&B0IT01IZ1},	//(vas84:04 - K03VASR, - ) Температура АЗ2-1
	{48	,1	,1	,&B0VN71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
	{49	,1	,1	,&B0VN81LZ1},	//( - , Baz1) АЗ по АС периода разгона АЗ2
	{50	,1	,1	,&B0VP41LZ1},	//( - , Baz1) Давление АЗ2 ниже АС
	{51	,1	,1	,&B0VP71LZ1},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
	{52	,1	,1	,&B0VP81LZZ},	//(vds32:08 - K12VDSR, - ) Давление АЗ2 в норме
	{53	,1	,1	,&B0VT61LZ1},	//( - , Baz1) ПС по температуре в АЗ2
	{54	,1	,1	,&B0VT71LZ1},	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
	{55	,1	,1	,&B0VZ71LZ1},	//( - , Baz1) Обобщенный сигнал АС по АЗ2
	{56	,1	,1	,&B1VP41LZ1},	//( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
	{57	,1	,1	,&B1VP81LZZ},	//(vds32:08 - K13VDSR, - ) Давление СБРОС ББ2 в норме
	{58	,8	,1	,&B2CP01RZ1},	//( - , Baz1) Текущее давление СБРОС РБ2
	{59	,3	,1	,&B2IP01IZ1},	//(vas84:04 - K04VASR, - ) Текущее давление СБРОС РБ2
	{60	,1	,1	,&B2IS12LDU},	//(vds32:05 - K11VDSR, - ) Магнит РБ2 зацеплен
	{61	,1	,1	,&B2VP41LZ1},	//( - , Baz1) Давление СБРОС РБ2 ниже АС
	{62	,1	,1	,&B2VP51LZ1},	//( - , Baz1) Давление СБРОС РБ2 ниже ПС
	{63	,1	,1	,&B2VP81LZ1},	//( - , Baz1) Давление СБРОС РБ2 в норме
	{64	,1	,1	,&B3IS11LDU},	//(vds32:06 - K05VDSR, - ) Приход на ВУ ИС2
	{65	,1	,1	,&B3IS22LDU},	//(vds32:06 - K06VDSR, - ) Приход на НУП ИС2
	{66	,1	,1	,&B3VZ11LZ1},	//( - , Baz1) АЗ от НУП ИС2
	{67	,1	,1	,&B3VZ31LZ1},	//( - , Baz1) АЗ от ВУ ИС2
	{68	,8	,1	,&B8VC01RDU},	//( - , SBz1DU, MBz1A1, MBz1A2, MBz1A3, MBz1A4) Координата АЗ2, мм
	{69	,1	,1	,&R0AD03LZ1},	//(vds32:05 - K07VDSR, - ) Имитация прихода на ВУ ИС
	{70	,1	,1	,&R0AD04LZ1},	//(vds32:05 - K08VDSR, - ) Имитация срабатывания верхней АС II УР
	{71	,1	,1	,&R0AD05LZ1},	//(vds32:05 - K09VDSR, - ) Имитация ухода с НУП ИС
	{72	,1	,1	,&R0AD14LZ1},	//(fds16:0a - K03FDSR, - ) Имитация АЗ от IIУР
	{73	,1	,1	,&R0AD21LDU},	//( - , SBz1DU) Подключить защиту от II УР
	{74	,3	,1	,&R0DE04LZ1},	//(vas84:04 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 4 месте
	{75	,3	,1	,&R0DE05LZ1},	//(vds32:05 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 5 месте
	{76	,3	,1	,&R0DE06LZ1},	//(vds32:06 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 6 месте
	{77	,3	,1	,&R0DE07LZ1},	//(vds32:07 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 7 месте
	{78	,3	,1	,&R0DE08LZ1},	//(vds32:08 - Diagn, DiagnBaz1) диагностика модуля Баз1 на 8 месте
	{79	,3	,1	,&R0DE0ALZ1},	//(fds16:0a - Diagn, DiagnBaz1) диагностика модуля Баз1 на 10 месте
	{80	,1	,1	,&R0DE3CLZ1},	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 5
	{81	,1	,1	,&R0DE3DLZ1},	//( - , DiagnBaz1) диагностика шкафа Баз1 БП5/24Д место 6
	{82	,1	,1	,&R0DEB1LZ1},	//(sbk:20 - S10SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 5
	{83	,1	,1	,&R0DEB2LZ1},	//(sbk:20 - S11SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 5
	{84	,1	,1	,&R0DEB3LZ1},	//(sbk:20 - S12SBK, DiagnBaz1) диагностика шкафа Баз1 БП5 место 6
	{85	,1	,1	,&R0DEB4LZ1},	//(sbk:20 - S13SBK, DiagnBaz1) диагностика шкафа Баз1 БП24Д место 6
	{86	,1	,1	,&R0EE01LZ1},	//( - , MBz1S) Питание  АКНП1  отключить
	{87	,1	,1	,&R0EE02LDU},	//( - , Baz1) Питание  АКНП  отключить
	{88	,1	,1	,&R0EE02LZ1},	//( - , MBz1S) Питание  АКНП2  отключить
	{89	,1	,1	,&R0EE03LZ1},	//( - , MBz1S) Питание  АКНП3  отключить
	{90	,1	,1	,&R0EE04LZ1},	//( - , MBz1S) Питание  АКНП4  отключить
	{91	,1	,1	,&R0ET01LZ1},	//( - , Baz1) Признак наличия неисправности по температуре  АЗ1
	{92	,1	,1	,&R0ET02LZ1},	//( - , Baz1) Признак наличия неисправности по температуре АЗ2
	{93	,1	,1	,&R0MD34LP1},	//( - , Baz1) Кнопка (Квитировать)
	{94	,3	,1	,&R0MW11IP1},	//( - , Baz1) Переключатель ВЫСТРЕЛ
	{95	,3	,1	,&R0MW12IP2},	//( - , Baz1) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{96	,1	,1	,&R0S01LZ1},	//(vds32:08 - K08VDSR, - ) Отключение сетевых передач в Баз1
	{97	,8	,1	,&R0VN01RS1},	//( - , MBz1A1) Период разгона канал 1
	{98	,8	,1	,&R0VN01RS2},	//( - , MBz1A2) Период разгона канал 2
	{99	,8	,1	,&R0VN01RS3},	//( - , MBz1A3) Период разгона канал 3
	{100	,8	,1	,&R0VN01RS4},	//( - , MBz1A4) Период разгона канал 4
	{101	,8	,1	,&R0VN01RZ1},	//( - , Baz1) Уровень мощности по каналу 1
	{102	,8	,1	,&R0VN02RS1},	//( - , MBz1A1) Уровень мощности канал 1
	{103	,8	,1	,&R0VN02RS2},	//( - , MBz1A2) Уровень мощности канал 2
	{104	,8	,1	,&R0VN02RS3},	//( - , MBz1A3) Уровень мощности канал 3
	{105	,8	,1	,&R0VN02RS4},	//( - , MBz1A4) Уровень мощности канал 4
	{106	,8	,1	,&R0VN02RZ1},	//( - , Baz1) Уровень мощности по каналу 2
	{107	,8	,1	,&R0VN03RZ1},	//( - , Baz1) Уровень мощности по каналу 3
	{108	,8	,1	,&R0VN04RZ1},	//( - , Baz1) Уровень мощности по каналу 4
	{109	,8	,1	,&R0VN05RZ1},	//( - , Baz1) Период разгона по каналу 1
	{110	,8	,1	,&R0VN06RZ1},	//( - , Baz1) Период разгона по каналу 2
	{111	,8	,1	,&R0VN07RZ1},	//( - , Baz1) Период разгона по каналу 3
	{112	,8	,1	,&R0VN08RZ1},	//( - , Baz1) Период разгона по каналу 4
	{113	,8	,1	,&R0VN09RZ1},	//( - , Baz1) Усредненный период разгона
	{114	,8	,1	,&R0VN11RZ1},	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
	{115	,1	,1	,&R0VN61LS1},	//( - , MBz1A1) ПС по мощности канал 1
	{116	,1	,1	,&R0VN61LS2},	//( - , MBz1A2) ПС по мощности канал 2
	{117	,1	,1	,&R0VN61LS3},	//( - , MBz1A3) ПС по мощности канал 3
	{118	,1	,1	,&R0VN61LS4},	//( - , MBz1A4) ПС по мощности канал 4
	{119	,1	,1	,&R0VN61LZ1},	//( - , Baz1) ПС по мощности канал 1
	{120	,1	,1	,&R0VN62LZ1},	//( - , Baz1) ПС по мощности канал 2
	{121	,1	,1	,&R0VN63LZ1},	//( - , Baz1) ПС по мощности канал 3
	{122	,1	,1	,&R0VN64LZ1},	//( - , Baz1) ПС по мощности канал 4
	{123	,1	,1	,&R0VN65LS1},	//( - , MBz1A1) ПС по периоду разгона канал 1
	{124	,1	,1	,&R0VN65LS2},	//( - , MBz1A2) ПС по периоду разгона  канал 2
	{125	,1	,1	,&R0VN65LS3},	//( - , MBz1A3) ПС по периоду разгона канал 3
	{126	,1	,1	,&R0VN65LS4},	//( - , MBz1A4) ПС по периоду разгона канал 4
	{127	,1	,1	,&R0VN65LZ1},	//( - , Baz1) ПС по периоду разгона канал 1
	{128	,1	,1	,&R0VN66LZ1},	//( - , Baz1) ПС по периоду разгона канал 2
	{129	,1	,1	,&R0VN67LZ1},	//( - , Baz1) ПС по периоду разгона канал 3
	{130	,1	,1	,&R0VN68LZ1},	//( - , Baz1) ПС по периоду разгона канал 4
	{131	,1	,1	,&R0VN69LZ1},	//( - , Baz1) ПС по усредненному периоду
	{132	,1	,1	,&R0VN70LZ1},	//( - , Baz1) АЗ по АС мощности РУ
	{133	,1	,1	,&R0VN71LZ1},	//(vds32:05 - K01VDSR, Baz1) АС по мощности канал 1
	{134	,1	,1	,&R0VN72LZ1},	//(vds32:06 - K01VDSR, Baz1) АС по мощности канал 2
	{135	,1	,1	,&R0VN73LZ1},	//(vds32:08 - K01VDSR, Baz1) АС по мощности канал 3
	{136	,1	,1	,&R0VN74LZ1},	//(vds32:07 - K01VDSR, Baz1) АС по мощности канал 4
	{137	,1	,1	,&R0VN75LZ1},	//(vds32:05 - K02VDSR, Baz1) АС по периоду разгона канал 1
	{138	,1	,1	,&R0VN76LZ1},	//(vds32:06 - K02VDSR, Baz1) АС по периоду разгона канал  2
	{139	,1	,1	,&R0VN77LZ1},	//(vds32:08 - K02VDSR, Baz1) АС по периоду разгона канал  3
	{140	,1	,1	,&R0VN78LZ1},	//(vds32:07 - K02VDSR, Baz1) АС по периоду разгона канал  4
	{141	,1	,1	,&R0VN79LZ1},	//( - , Baz1) АС по усредненному периоду
	{142	,1	,1	,&R0VN80LZ1},	//( - , Baz1) АЗ по АС периода разгона РУ
	{143	,1	,1	,&R0VP73LZ1},	//( - , Baz1, SBz1DU) ПС давления для РУ
	{144	,8	,1	,&R0VR02RZ1},	//( - , Baz1) Усредненная реактивность
	{145	,1	,1	,&R0VW13LDU},	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{146	,1	,1	,&R0VW23LDU},	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{147	,5	,1	,&R0VZ05U},	//( - , - ) причины сброса
	{148	,5	,1	,&R0VZ05UZ1},	//( - , Baz1) Индикатор причины сброса
	{149	,1	,1	,&R0VZ71LZ1},	//(fds16:0a - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
	{150	,1	,1	,&R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{151	,1	,1	,&R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{152	,1	,1	,&R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{153	,1	,1	,&R7II71LZ1},	//(vds32:08 - K05VDSR, Baz1) Сработала АС IУР РАД (датчик 1)
	{154	,1	,1	,&R7II72LZ1},	//(vds32:08 - K06VDSR, Baz1) Сработала АС IУР РАД  (датчик 2)
	{155	,1	,1	,&R7II73LZ1},	//(vds32:08 - K07VDSR, Baz1) Сработала АС II УР РАД
	{156	,3	,1	,&TTLBaz1},	//( - , Baz1) ttl
	{157	,1	,1	,&TestDiagnBaz1},	//( - , Baz1) Неисправность от диагностики
	{158	,1	,1	,&bFirstEnterFlag},	//(bFirstEnterFlag) 
	{159	,8	,1	,&fEM_A2UP03RZZ},	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{160	,8	,1	,&fEM_A2UP04RZZ},	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{161	,8	,1	,&fEM_A2UP41RZZ},	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{162	,8	,1	,&fEM_A2UP42RZZ},	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{163	,8	,1	,&fEM_A2UP51RZZ},	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{164	,8	,1	,&fEM_A2UP52RZZ},	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{165	,8	,1	,&fEM_A2UP81RZZ},	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{166	,8	,1	,&fEM_A2UP82RZZ},	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{167	,8	,1	,&fEM_A2UP83RZZ},	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{168	,8	,1	,&fEM_A2UP84RZZ},	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{169	,8	,1	,&fEM_R0UL05RDU},	//(R0UL05RDU) Время задержки АЗ от НУП ИС(сек)
	{170	,8	,1	,&fEM_R0UL07RDU},	//(R0UL07RDU) Время задержки  срабатывания АС II УР
	{171	,8	,1	,&fEM_R0UL25RDU},	//(R0UL25RDU) Время задержки АЗ от ВУ ИС сек
	{172	,8	,1	,&fEM_R0UR01RZZ},	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
	{173	,8	,1	,&fEM_R0UR04RZZ},	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
	{174	,8	,1	,&fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{175	,8	,1	,&fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{176	,8	,1	,&fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{177	,8	,1	,&fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{178	,8	,1	,&fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{179	,8	,1	,&fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{180	,1	,1	,&internal1_m104_y1},	//(internal1_m104_y1) y1 - внутренний параметр
	{181	,1	,1	,&internal1_m106_y1},	//(internal1_m106_y1) y1 - внутренний параметр
	{182	,8	,1	,&internal1_m107_tx},	//(internal1_m107_tx) tx - время накопленное сек
	{183	,18	,1	,&internal1_m107_y0},	//(internal1_m107_y0) y0
	{184	,8	,1	,&internal1_m110_tx},	//(internal1_m110_tx) tx - время накопленное сек
	{185	,18	,1	,&internal1_m110_y0},	//(internal1_m110_y0) y0
	{186	,1	,1	,&internal1_m121_y1},	//(internal1_m121_y1) y1 - внутренний параметр
	{187	,1	,1	,&internal1_m124_y0},	//(internal1_m124_y0) state
	{188	,1	,1	,&internal1_m128_y0},	//(internal1_m128_y0) state
	{189	,8	,1	,&internal1_m134_tx},	//(internal1_m134_tx) tx - время накопленное сек
	{190	,18	,1	,&internal1_m134_y0},	//(internal1_m134_y0) y0
	{191	,8	,1	,&internal1_m135_tx},	//(internal1_m135_tx) tx - время накопленное сек
	{192	,18	,1	,&internal1_m135_y0},	//(internal1_m135_y0) y0
	{193	,8	,1	,&internal1_m146_y0},	//(internal1_m146_y0) y0
	{194	,8	,1	,&internal1_m148_y0},	//(internal1_m148_y0) y0
	{195	,1	,1	,&internal1_m156_y1},	//(internal1_m156_y1) y1 - внутренний параметр
	{196	,1	,1	,&internal1_m159_y1},	//(internal1_m159_y1) y1 - внутренний параметр
	{197	,1	,1	,&internal1_m167_y1},	//(internal1_m167_y1) y1 - внутренний параметр
	{198	,1	,1	,&internal1_m170_y1},	//(internal1_m170_y1) y1 - внутренний параметр
	{199	,8	,1	,&internal1_m205_TImAZ2UR},	//(internal1_m205_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
	{200	,8	,1	,&internal1_m205_TImNupIs},	//(internal1_m205_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
	{201	,8	,1	,&internal1_m205_TImVuIs},	//(internal1_m205_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
	{202	,8	,1	,&internal1_m205_TNupIs1},	//(internal1_m205_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
	{203	,8	,1	,&internal1_m205_TNupIs2},	//(internal1_m205_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
	{204	,8	,1	,&internal1_m205_TVuIs1},	//(internal1_m205_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
	{205	,8	,1	,&internal1_m205_TVuIs2},	//(internal1_m205_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
	{206	,1	,1	,&internal1_m205_fef},	//(internal1_m205_fef) fef
	{207	,8	,1	,&internal1_m210_tx},	//(internal1_m210_tx) tx - время накопленное сек
	{208	,18	,1	,&internal1_m210_y0},	//(internal1_m210_y0) y0
	{209	,8	,1	,&internal1_m225_tx},	//(internal1_m225_tx) tx - время накопленное сек
	{210	,18	,1	,&internal1_m225_y0},	//(internal1_m225_y0) y0
	{211	,5	,1	,&internal1_m280_q0},	//(internal1_m280_q0) q0 - внутренний параметр
	{212	,3	,1	,&internal1_m33_tx},	//(internal1_m33_tx) tx - внутренний параметр
	{213	,8	,1	,&internal1_m90_y0},	//(internal1_m90_y0) y0
	{214	,8	,1	,&internal1_m92_y0},	//(internal1_m92_y0) y0
	{215	,1	,1	,&internal1_m94_y1},	//(internal1_m94_y1) y1 - внутренний параметр
	{216	,1	,1	,&var16},	//Внутренняя переменная var16
	{217	,1	,1	,&var26},	//Внутренняя переменная var26
	{218	,1	,1	,&var83},	//Внутренняя переменная var83
	{219	,1	,1	,&var115},	//Внутренняя переменная var115
	{220	,1	,1	,&var8},	//Внутренняя переменная var8
	{221	,1	,1	,&var13},	//Внутренняя переменная var13
	{222	,1	,1	,&var51},	//Внутренняя переменная var51
	{223	,1	,1	,&var117},	//Внутренняя переменная var117
	{224	,1	,1	,&var139},	//Внутренняя переменная var139
	{225	,1	,1	,&vainSBool},	//Внутренняя переменная vainSBool
	{226	,1	,1	,&var33},	//Внутренняя переменная var33
	{227	,1	,1	,&var38},	//Внутренняя переменная var38
	{228	,1	,1	,&var93},	//Внутренняя переменная var93
	{229	,1	,1	,&var95},	//Внутренняя переменная var95
	{230	,8	,1	,&var124},	//Внутренняя переменная var124
	{231	,1	,1	,&var131},	//Внутренняя переменная var131
	{232	,5	,1	,&vainSInt},	//Внутренняя переменная vainSInt
	{233	,1	,1	,&var17},	//Внутренняя переменная var17
	{234	,1	,1	,&var88},	//Внутренняя переменная var88
	{235	,1	,1	,&var121},	//Внутренняя переменная var121
	{236	,1	,1	,&var54},	//Внутренняя переменная var54
	{237	,1	,1	,&var66},	//Внутренняя переменная var66
	{238	,1	,1	,&var49},	//Внутренняя переменная var49
	{239	,1	,1	,&var52},	//Внутренняя переменная var52
	{240	,1	,1	,&var61},	//Внутренняя переменная var61
	{241	,1	,1	,&var75},	//Внутренняя переменная var75
	{242	,1	,1	,&var84},	//Внутренняя переменная var84
	{243	,1	,1	,&var103},	//Внутренняя переменная var103
	{244	,8	,1	,&var127},	//Внутренняя переменная var127
	{245	,1	,1	,&var128},	//Внутренняя переменная var128
	{246	,1	,1	,&var58},	//Внутренняя переменная var58
	{247	,1	,1	,&var67},	//Внутренняя переменная var67
	{248	,1	,1	,&var62},	//Внутренняя переменная var62
	{249	,1	,1	,&var82},	//Внутренняя переменная var82
	{250	,8	,1	,&var112},	//Внутренняя переменная var112
	{251	,1	,1	,&var129},	//Внутренняя переменная var129
	{252	,1	,1	,&var12},	//Внутренняя переменная var12
	{253	,1	,1	,&var44},	//Внутренняя переменная var44
	{254	,1	,1	,&var47},	//Внутренняя переменная var47
	{255	,1	,1	,&var53},	//Внутренняя переменная var53
	{256	,1	,1	,&var73},	//Внутренняя переменная var73
	{257	,1	,1	,&var91},	//Внутренняя переменная var91
	{258	,8	,1	,&var105},	//Внутренняя переменная var105
	{259	,1	,1	,&var5},	//Внутренняя переменная var5
	{260	,1	,1	,&var19},	//Внутренняя переменная var19
	{261	,1	,1	,&var78},	//Внутренняя переменная var78
	{262	,8	,1	,&var102},	//Внутренняя переменная var102
	{263	,1	,1	,&var136},	//Внутренняя переменная var136
	{264	,1	,1	,&var20},	//Внутренняя переменная var20
	{265	,1	,1	,&var25},	//Внутренняя переменная var25
	{266	,1	,1	,&var133},	//Внутренняя переменная var133
	{267	,1	,1	,&var118},	//Внутренняя переменная var118
	{268	,1	,1	,&var120},	//Внутренняя переменная var120
	{269	,1	,1	,&var99},	//Внутренняя переменная var99
	{270	,1	,1	,&var43},	//Внутренняя переменная var43
	{271	,1	,1	,&var94},	//Внутренняя переменная var94
	{272	,1	,1	,&var77},	//Внутренняя переменная var77
	{273	,1	,1	,&var92},	//Внутренняя переменная var92
	{274	,1	,1	,&var14},	//Внутренняя переменная var14
	{275	,1	,1	,&var31},	//Внутренняя переменная var31
	{276	,1	,1	,&var34},	//Внутренняя переменная var34
	{277	,1	,1	,&var72},	//Внутренняя переменная var72
	{278	,1	,1	,&var74},	//Внутренняя переменная var74
	{279	,1	,1	,&var87},	//Внутренняя переменная var87
	{280	,1	,1	,&var64},	//Внутренняя переменная var64
	{281	,1	,1	,&var65},	//Внутренняя переменная var65
	{282	,1	,1	,&var76},	//Внутренняя переменная var76
	{283	,1	,1	,&var79},	//Внутренняя переменная var79
	{284	,1	,1	,&var28},	//Внутренняя переменная var28
	{285	,1	,1	,&var40},	//Внутренняя переменная var40
	{286	,1	,1	,&var122},	//Внутренняя переменная var122
	{287	,1	,1	,&var125},	//Внутренняя переменная var125
	{288	,1	,1	,&var126},	//Внутренняя переменная var126
	{289	,1	,1	,&var42},	//Внутренняя переменная var42
	{290	,1	,1	,&var116},	//Внутренняя переменная var116
	{291	,1	,1	,&var23},	//Внутренняя переменная var23
	{292	,1	,1	,&var55},	//Внутренняя переменная var55
	{293	,1	,1	,&var89},	//Внутренняя переменная var89
	{294	,1	,1	,&var100},	//Внутренняя переменная var100
	{295	,1	,1	,&var4},	//Внутренняя переменная var4
	{296	,1	,1	,&var11},	//Внутренняя переменная var11
	{297	,1	,1	,&var37},	//Внутренняя переменная var37
	{298	,1	,1	,&var69},	//Внутренняя переменная var69
	{299	,1	,1	,&var81},	//Внутренняя переменная var81
	{300	,1	,1	,&var111},	//Внутренняя переменная var111
	{301	,1	,1	,&var135},	//Внутренняя переменная var135
	{302	,1	,1	,&var1},	//Внутренняя переменная var1
	{303	,1	,1	,&var24},	//Внутренняя переменная var24
	{304	,8	,1	,&vainSFloat},	//Внутренняя переменная vainSFloat
	{305	,1	,1	,&var22},	//Внутренняя переменная var22
	{306	,1	,1	,&var45},	//Внутренняя переменная var45
	{307	,1	,1	,&var59},	//Внутренняя переменная var59
	{308	,1	,1	,&var140},	//Внутренняя переменная var140
	{309	,1	,1	,&var2},	//Внутренняя переменная var2
	{310	,1	,1	,&var15},	//Внутренняя переменная var15
	{311	,1	,1	,&var60},	//Внутренняя переменная var60
	{312	,8	,1	,&var104},	//Внутренняя переменная var104
	{313	,1	,1	,&var141},	//Внутренняя переменная var141
	{314	,1	,1	,&var27},	//Внутренняя переменная var27
	{315	,1	,1	,&var30},	//Внутренняя переменная var30
	{316	,1	,1	,&var98},	//Внутренняя переменная var98
	{317	,1	,1	,&var109},	//Внутренняя переменная var109
	{318	,11	,1	,&var113},	//Внутренняя переменная var113
	{319	,11	,1	,&vainSLong},	//Внутренняя переменная vainSLong
	{320	,1	,1	,&var41},	//Внутренняя переменная var41
	{321	,1	,1	,&var97},	//Внутренняя переменная var97
	{322	,1	,1	,&var63},	//Внутренняя переменная var63
	{323	,11	,1	,&var114},	//Внутренняя переменная var114
	{324	,1	,1	,&var123},	//Внутренняя переменная var123
	{325	,1	,1	,&var134},	//Внутренняя переменная var134
	{326	,1	,1	,&var138},	//Внутренняя переменная var138
	{327	,1	,1	,&var142},	//Внутренняя переменная var142
	{328	,1	,1	,&var6},	//Внутренняя переменная var6
	{329	,1	,1	,&var57},	//Внутренняя переменная var57
	{330	,1	,1	,&var29},	//Внутренняя переменная var29
	{331	,1	,1	,&var35},	//Внутренняя переменная var35
	{332	,1	,1	,&var108},	//Внутренняя переменная var108
	{333	,1	,1	,&var119},	//Внутренняя переменная var119
	{334	,1	,1	,&var10},	//Внутренняя переменная var10
	{335	,1	,1	,&var86},	//Внутренняя переменная var86
	{336	,1	,1	,&var71},	//Внутренняя переменная var71
	{337	,1	,1	,&var96},	//Внутренняя переменная var96
	{338	,8	,1	,&var101},	//Внутренняя переменная var101
	{339	,1	,1	,&var107},	//Внутренняя переменная var107
	{340	,1	,1	,&var36},	//Внутренняя переменная var36
	{341	,1	,1	,&var56},	//Внутренняя переменная var56
	{342	,5	,1	,&var21},	//Внутренняя переменная var21
	{343	,1	,1	,&var7},	//Внутренняя переменная var7
	{344	,1	,1	,&var9},	//Внутренняя переменная var9
	{345	,1	,1	,&var106},	//Внутренняя переменная var106
	{346	,1	,1	,&var137},	//Внутренняя переменная var137
	{347	,1	,1	,&var68},	//Внутренняя переменная var68
	{348	,1	,1	,&var90},	//Внутренняя переменная var90
	{349	,1	,1	,&var39},	//Внутренняя переменная var39
	{350	,1	,1	,&var46},	//Внутренняя переменная var46
	{351	,1	,1	,&var3},	//Внутренняя переменная var3
	{352	,1	,1	,&var32},	//Внутренняя переменная var32
	{353	,1	,1	,&var18},	//Внутренняя переменная var18
	{354	,1	,1	,&var70},	//Внутренняя переменная var70
	{355	,1	,1	,&var80},	//Внутренняя переменная var80
	{356	,1	,1	,&var85},	//Внутренняя переменная var85
	{357	,1	,1	,&var110},	//Внутренняя переменная var110
	{358	,1	,1	,&var48},	//Внутренняя переменная var48
	{359	,1	,1	,&var50},	//Внутренняя переменная var50
	{-1,0,NULL},
};
static char NameSaveFile[]="baz1.bin\0"; //Имя файла сохранения переменных
#pragma pop
static VarSaveCtrl saveVariables[]={	//Id переменных для сохранения
	{164,"fEM_A2UP52RZZ\0"},	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{179,"fEM_R0UT72RZZ\0"},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{161,"fEM_A2UP41RZZ\0"},	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{165,"fEM_A2UP81RZZ\0"},	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{166,"fEM_A2UP82RZZ\0"},	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{167,"fEM_A2UP83RZZ\0"},	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{173,"fEM_R0UR04RZZ\0"},	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
	{171,"fEM_R0UL25RDU\0"},	//(R0UL25RDU) Время задержки АЗ от ВУ ИС сек
	{174,"fEM_R0UT01RZZ\0"},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{178,"fEM_R0UT71RZZ\0"},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{177,"fEM_R0UT62RZZ\0"},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{169,"fEM_R0UL05RDU\0"},	//(R0UL05RDU) Время задержки АЗ от НУП ИС(сек)
	{170,"fEM_R0UL07RDU\0"},	//(R0UL07RDU) Время задержки  срабатывания АС II УР
	{175,"fEM_R0UT02RZZ\0"},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{163,"fEM_A2UP51RZZ\0"},	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{168,"fEM_A2UP84RZZ\0"},	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{162,"fEM_A2UP42RZZ\0"},	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{172,"fEM_R0UR01RZZ\0"},	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
	{159,"fEM_A2UP03RZZ\0"},	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{160,"fEM_A2UP04RZZ\0"},	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{176,"fEM_R0UT61RZZ\0"},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_Baz1[]={
	{&R0EE02LDU,1,0},	//( - , Baz1) Питание  АКНП  отключить
	{&A0EE08LZ1,1,1},	//( - , Baz1) Исправность сети АКНП4
	{&A0EE07LZ1,1,2},	//( - , Baz1) Исправность сети АКНП3
	{&A0EE06LZ1,1,3},	//( - , Baz1) Исправность сети АКНП2
	{&A0EE05LZ1,1,4},	//( - , Baz1) Исправность сети АКНП1
	{&R0VN70LZ1,1,5},	//( - , Baz1) АЗ по АС мощности РУ
	{&R0MD34LP1,1,6},	//( - , Baz1) Кнопка (Квитировать)
	{&R7II73LZ1,1,7},	//( - K07VDSR, Baz1) Сработала АС II УР РАД
	{&R0VW23LDU,1,8},	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,9},	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{&R0VN64LZ1,1,10},	//( - , Baz1) ПС по мощности канал 4
	{&R0VN63LZ1,1,11},	//( - , Baz1) ПС по мощности канал 3
	{&R0VN62LZ1,1,12},	//( - , Baz1) ПС по мощности канал 2
	{&R0VN61LZ1,1,13},	//( - , Baz1) ПС по мощности канал 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_Baz1[]={
	{&B0VN81LZ1,1,0},	//( - , Baz1) АЗ по АС периода разгона АЗ2
	{&A0VN81LZ1,1,1},	//( - , Baz1) АЗ по АС периода разгона АЗ1
	{&B0VN71LZ1,1,2},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
	{&A0VN71LZ1,1,3},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
	{&B0VZ71LZ1,1,4},	//( - , Baz1) Обобщенный сигнал АС по АЗ2
	{&B0EE00LZ1,1,5},	//( - , Baz1) Исправность АКНП АЗ2
	{&A0EE00LZ1,1,6},	//( - , Baz1) Исправность АКНП АЗ1
	{&A0VZ71LZ1,1,7},	//( - , Baz1) Обобщенный сигнал АС по АЗ1
	{&A0EE03LZ1,1,8},	//( - , Baz1, SBz1DU) Исправность АКНП3
	{&A0EE02LZ1,1,9},	//( - , Baz1, SBz1DU) Исправность АКНП2
	{&A0EE04LZ1,1,10},	//( - , Baz1, SBz1DU) Исправность АКНП4
	{&A0EE01LZ1,1,11},	//( - , Baz1, SBz1DU) Исправность АКНП1
	{&R0VN80LZ1,1,12},	//( - , Baz1) АЗ по АС периода разгона РУ
	{&R0VZ71LZ1,1,13},	//( - K05FDSR, Baz1) Обобщенный сигнал АЗ 1 канала
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
	{&B0VT71LZ1,1,25},	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
	{&B0VT61LZ1,1,26},	//( - , Baz1) ПС по температуре в АЗ2
	{&R0VP73LZ1,1,27},	//( - , Baz1, SBz1DU) ПС давления для РУ
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
	{&R0VN79LZ1,1,44},	//( - , Baz1) АС по усредненному периоду
	{&R0VN69LZ1,1,45},	//( - , Baz1) ПС по усредненному периоду
	{&B3VZ11LZ1,1,46},	//( - , Baz1) АЗ от НУП ИС2
	{&A3VZ11LZ1,1,47},	//( - , Baz1) АЗ от НУП ИС1
	{&B3VZ31LZ1,1,48},	//( - , Baz1) АЗ от ВУ ИС2
	{&A3VZ31LZ1,1,49},	//( - , Baz1) АЗ от ВУ ИС1
	{&R0VN68LZ1,1,50},	//( - , Baz1) ПС по периоду разгона канал 4
	{&R0VN67LZ1,1,51},	//( - , Baz1) ПС по периоду разгона канал 3
	{&R0VN66LZ1,1,52},	//( - , Baz1) ПС по периоду разгона канал 2
	{&R0VN65LZ1,1,53},	//( - , Baz1) ПС по периоду разгона канал 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_Baz1[]={
	{&R0VN11RZ1,8,0},	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
	{&R0VZ05UZ1,5,2},	//( - , Baz1) Индикатор причины сброса
	{&TTLBaz1,3,4},	//( - , Baz1) ttl
	{&B0CT01IZ1,8,5},	//( - , Baz1, SBz1DU) Температура АЗ2-1
	{&R0VN01RZ1,8,7},	//( - , Baz1) Уровень мощности по каналу 1
	{&A0EP02IZ1,3,9},	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
	{&B0EP02IZ1,3,10},	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
	{&B2CP01RZ1,8,11},	//( - , Baz1) Текущее давление СБРОС РБ2
	{&A2CP01RZ1,8,13},	//( - , Baz1) Текущее давление СБРОС РБ1
	{&A0CT01IZ1,8,15},	//( - , Baz1, SBz1DU) Температура АЗ1-1
	{&R0VR02RZ1,8,17},	//( - , Baz1) Усредненная реактивность
	{&R0VN09RZ1,8,19},	//( - , Baz1) Усредненный период разгона
	{&R0VN08RZ1,8,21},	//( - , Baz1) Период разгона по каналу 4
	{&R0VN07RZ1,8,23},	//( - , Baz1) Период разгона по каналу 3
	{&R0VN06RZ1,8,25},	//( - , Baz1) Период разгона по каналу 2
	{&R0VN05RZ1,8,27},	//( - , Baz1) Период разгона по каналу 1
	{&R0VN04RZ1,8,29},	//( - , Baz1) Уровень мощности по каналу 4
	{&R0VN03RZ1,8,31},	//( - , Baz1) Уровень мощности по каналу 3
	{&R0VN02RZ1,8,33},	//( - , Baz1) Уровень мощности по каналу 2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_Baz1[]={
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
	{&fEM_R0UL05RDU,8,38},	//( - , Baz1) Время задержки АЗ от НУП ИС(сек)
	{&fEM_R0UL25RDU,8,40},	//( - , Baz1) Время задержки АЗ от ВУ ИС сек
	{&fEM_R0UL07RDU,8,42},	//( - , Baz1) Время задержки  срабатывания АС II УР
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SBz1DU[]={
	{&R0AD21LDU,1,0},	//( - , SBz1DU) Подключить защиту от II УР
	{&R0VW23LDU,1,1},	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,2},	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz1DU[]={
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
static ModbusRegister ir_SBz1DU[]={
	{&B0CT01IZ1,8,0},	//( - , Baz1, SBz1DU) Температура АЗ2-1
	{&R0VN11RZ1,8,2},	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
	{&A0CT01IZ1,8,4},	//( - , Baz1, SBz1DU) Температура АЗ1-1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SBz1DU[]={
	{&B8VC01RDU,8,0},	//( - , SBz1DU, MBz1A1, MBz1A2, MBz1A3, MBz1A4) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_DiagnBaz1[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnBaz1[]={
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
static ModbusRegister ir_DiagnBaz1[]={
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
static ModbusRegister hr_DiagnBaz1[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MBz1S[]={
	{&R0EE01LZ1,1,0},	//( - , SBz1) Питание  АКНП1  отключить
	{&R0EE02LZ1,1,1},	//( - , SBz1) Питание  АКНП  отключить
	{&R0EE03LZ1,1,2},	//( - , SBz1) Питание  АКНП3  отключить
	{&R0EE04LZ1,1,3},	//( - , SBz1) Питание  АКНП4  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz1S[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz1S[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz1S[]={
	{NULL,0,0},
};
#pragma pop
static char MBz1S_ip1[]={"192.168.10.60\0"};
static char MBz1S_ip2[]={"192.168.10.60\0"};
#pragma pack(push,1)
static ModbusRegister coil_MBz1A1[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz1A1[]={
	{&R0VN61LS1,1,0},	//( - , A1Bz1, A1Bz2) ПС по мощности канал1
	{&R0VN65LS1,1,1},	//( - , A1Bz1, A1Bz2) ПС по периоду разгона канал1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz1A1[]={
	{&R0VN02RS1,8,0},	//( - , A1Bz1, A1Bz2) Уровень мощности
	{&R0VN01RS1,8,2},	//( - , A1Bz1, A1Bz2) Период разгона канал1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz1A1[]={
	{&B8VC01RDU,8,0},	//( - , A1Bz1, A1Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
static char MBz1A1_ip1[]={"192.168.10.51\0"};
static char MBz1A1_ip2[]={"192.168.10.151\0"};
#pragma pack(push,1)
static ModbusRegister coil_MBz1A2[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz1A2[]={
	{&R0VN61LS2,1,0},	//( - , A2Bz1, A2Bz2) ПС по мощности канал 2
	{&R0VN65LS2,1,1},	//( - , A2Bz1, A2Bz2) ПС по периоду разгона канал 2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz1A2[]={
	{&R0VN02RS2,8,0},	//( - , A2Bz1, A2Bz2) Уровень мощности канал 2
	{&R0VN01RS2,8,2},	//( - , A2Bz1, A2Bz2) Период разгона канал 2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz1A2[]={
	{&B8VC01RDU,8,0},	//( - , A2Bz1, A2Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
static char MBz1A2_ip1[]={"192.168.10.57\0"};
static char MBz1A2_ip2[]={"192.168.10.157\0"};
#pragma pack(push,1)
static ModbusRegister coil_MBz1A3[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz1A3[]={
	{&R0VN61LS3,1,0},	//( - , A3Bz1, A3Bz2) ПС по мощности канал 3
	{&R0VN65LS3,1,1},	//( - , A3Bz1, A3Bz2) ПС по периоду разгона канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz1A3[]={
	{&R0VN02RS3,8,0},	//( - , A3Bz1, A3Bz2) Уровень мощности канал 3
	{&R0VN01RS3,8,2},	//( - , A3Bz1, A3Bz2) Период разгона канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz1A3[]={
	{&B8VC01RDU,8,0},	//( - , A3Bz1, A3Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
static char MBz1A3_ip1[]={"192.168.10.53\0"};
static char MBz1A3_ip2[]={"192.168.10.153\0"};
#pragma pack(push,1)
static ModbusRegister coil_MBz1A4[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz1A4[]={
	{&R0VN61LS4,1,0},	//( - , A4Bz1, A4Bz2) ПС по мощности канал 4
	{&R0VN65LS4,1,1},	//( - , A4Bz1, A4Bz2) ПС по периоду разгона канал 4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz1A4[]={
	{&R0VN02RS4,8,0},	//( - , A4Bz1, A4Bz2) Уровень мощности канал 4
	{&R0VN01RS4,8,2},	//( - , A4Bz1, A4Bz2) Период разгона канал 4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz1A4[]={
	{&B8VC01RDU,8,0},	//( - , A4Bz1, A4Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
static char MBz1A4_ip1[]={"192.168.10.55\0"};
static char MBz1A4_ip2[]={"192.168.10.155\0"};
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_Baz1[0],&di_Baz1[0],&ir_Baz1[0],&hr_Baz1[0],NULL,NULL,NULL,0},	//Общий слэйв
	{0,5010,&coil_SBz1DU[0],&di_SBz1DU[0],&ir_SBz1DU[0],&hr_SBz1DU[0],NULL,NULL,NULL,0},	//Слэйв для DU
	{0,5005,&coil_DiagnBaz1[0],&di_DiagnBaz1[0],&ir_DiagnBaz1[0],&hr_DiagnBaz1[0],NULL,NULL,NULL,0},	//Диагностика Baz1
	{1,5003,&coil_MBz1S[0],&di_MBz1S[0],&ir_MBz1S[0],&hr_MBz1S[0],NULL,MBz1S_ip1,MBz1S_ip2,100},	//Мастер Баз1 в SCM
	{1,5015,&coil_MBz1A1[0],&di_MBz1A1[0],&ir_MBz1A1[0],&hr_MBz1A1[0],NULL,MBz1A1_ip1,MBz1A1_ip2,20},	//Мастер Баз1 в AKNP1
	{1,5016,&coil_MBz1A2[0],&di_MBz1A2[0],&ir_MBz1A2[0],&hr_MBz1A2[0],NULL,MBz1A2_ip1,MBz1A2_ip2,20},	//Мастер Баз1 в AKNP2
	{1,5017,&coil_MBz1A3[0],&di_MBz1A3[0],&ir_MBz1A3[0],&hr_MBz1A3[0],NULL,MBz1A3_ip1,MBz1A3_ip2,20},	//Мастер Баз1 в AKNP3
	{1,5018,&coil_MBz1A4[0],&di_MBz1A4[0],&ir_MBz1A4[0],&hr_MBz1A4[0],NULL,MBz1A4_ip1,MBz1A4_ip2,20},	//Мастер Баз1 в AKNP4
	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS16[104];	//FDS16
static fds16r_inipar ini_FDS16={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
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
static char buf_SBKFP[90];	//SBKFP
static sbk_inipar ini_SBKFP={0xcc,0xff,8,8,0,0,0,};
#pragma pack(push,1)
static table_drv table_SBKFP={0,0,&ini_SBKFP,buf_SBKFP,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_SBKFP[]={
	{&R0DEB4LZ1,1,24},
	{&R0DEB2LZ1,1,20},
	{&R0DEB1LZ1,1,18},
	{&R0DEB3LZ1,1,22},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vas84r.h>
static char buf_VAS84[64];	//VAS84
static vas84r_inipar ini_VAS84={0xc6,255,1,8,0xff,0,16,0,0,0,};
#pragma pack(push,1)
static table_drv table_VAS84={0,0,&ini_VAS84,buf_VAS84,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VAS84[]={
	{&R0DE04LZ1,3,26},
	{&A2IP01IZ1,3,3},
	{&B2IP01IZ1,3,9},
	{&B0IT01IZ1,3,6},
	{&A0IT01IZ1,3,0},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS321[194];	//VDS321
static vds32r_inipar ini_VDS321={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS321={0,0,&ini_VDS321,buf_VDS321,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS321[]={
	{&A2IS12LDU,1,18},
	{&A0EE01LS1,1,4},
	{&R0AD05LZ1,1,16},
	{&R0VN71LZ1,1,0},
	{&R0VN75LZ1,1,2},
	{&R0AD03LZ1,1,12},
	{&A3IS22LDU,1,10},
	{&A3IS11LDU,1,8},
	{&R0AD04LZ1,1,14},
	{&A0VN71LS1,1,6},
	{&R0DE05LZ1,3,64},
	{&B2IS12LDU,1,20},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS322[194];	//VDS322
static vds32r_inipar ini_VDS322={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS322={0,0,&ini_VDS322,buf_VDS322,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS322[]={
	{&R0VN76LZ1,1,2},
	{&R0VN72LZ1,1,0},
	{&A0VN71LS2,1,6},
	{&B3IS22LDU,1,10},
	{&A0EE01LS2,1,4},
	{&B3IS11LDU,1,8},
	{&R0DE06LZ1,3,64},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS323[194];	//VDS323
static vds32r_inipar ini_VDS323={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS323={0,0,&ini_VDS323,buf_VDS323,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS323[]={
	{&R0DE07LZ1,3,64},
	{&A0EE01LS4,1,4},
	{&R0VN74LZ1,1,0},
	{&R0VN78LZ1,1,2},
	{&A0VN71LS4,1,6},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS324[194];	//VDS324
static vds32r_inipar ini_VDS324={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS324={0,0,&ini_VDS324,buf_VDS324,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS324[]={
	{&R0DE08LZ1,3,64},
	{&R0VN73LZ1,1,0},
	{&R0VN77LZ1,1,2},
	{&B1VP81LZZ,1,24},
	{&A0VN71LS3,1,6},
	{&A1VP81LZZ,1,18},
	{&R0S01LZ1,1,14},
	{&A0VP81LZZ,1,16},
	{&B0VP81LZZ,1,22},
	{&R7II73LZ1,1,12},
	{&R7II71LZ1,1,8},
	{&R7II72LZ1,1,10},
	{&A0EE01LS3,1,4},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc2,0x06,19,194,def_buf_VDS322,&table_VDS322},	//VDS32
	{0xc2,0x07,19,194,def_buf_VDS323,&table_VDS323},	//VDS32
	{0xc2,0x08,19,194,def_buf_VDS324,&table_VDS324},	//VDS32
	{0x96,0x0a,23,104,def_buf_FDS16,&table_FDS16},	//FDS16
	{0xcc,0x20,7,90,def_buf_SBKFP,&table_SBKFP},	//SBKFP
	{0xc6,0x04,10,64,def_buf_VAS84,&table_VAS84},	//VAS84
	{0xc2,0x05,19,194,def_buf_VDS321,&table_VDS321},	//VDS32
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){	//Инициализация переменных для хранения
	setAsFloat(159,1.6);
	setAsFloat(160,0);
	setAsFloat(176,100);
	setAsFloat(162,0.13);
	setAsFloat(172,15);
	setAsFloat(179,150);
	setAsFloat(161,0.1);
	setAsFloat(165,0.17);
	setAsFloat(164,0.19);
	setAsFloat(173,10);
	setAsFloat(171,0.170);
	setAsFloat(174,0);
	setAsFloat(178,200);
	setAsFloat(177,90);
	setAsFloat(166,0.2);
	setAsFloat(167,0.28);
	setAsFloat(175,600);
	setAsFloat(163,0.16);
	setAsFloat(168,0.31);
	setAsFloat(169,0.190);
	setAsFloat(170,0.150);
	setAsBool(150,1);
	setAsBool(151,1);
	setAsBool(152,1);
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
ssint iRM_17_ = {17,0}; /* n - размерность массива входных сигналов */ 
ssint iRM_3276_ = {3276,0}; /* a */ 
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
ssfloat fRM_0_3 = {0.3,0}; /* tz - время задержки сек */ 


/* Определение переменных */
sschar var130;
sschar var132;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psint  array_m306_x_1[6] = {&R0DE04LZ1,&R0DE05LZ1,&R0DE06LZ1,&R0DE0ALZ1,&R0DE08LZ1,&R0DE07LZ1};
psfloat  array_m189_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psfloat  array_m290_x_1[4] = {&R0VN02RS1,&R0VN02RS2,&R0VN02RS3,&R0VN02RS4};
psbool  array_m290_diag_1[4] = {&var26,&var27,&var28,&var29};
psbool  array_m281_x_1[17] = {&var75,&var41,&var42,&var70,&var9,&var6,&var129,&var40,&var39,&var38,&var71,&var10,&var7,&var131,&var36,&var35,&R7II73LZ1};
psbool  array_m16_x_1[6] = {&var80,&var71,&var10,&var7,&var86,&var131};
psbool  array_m36_x_1[6] = {&var70,&var9,&var6,&var129,&var78,&var86};
psfloat  array_m2_x_1[4] = {&R0VN01RS1,&R0VN01RS2,&R0VN01RS3,&R0VN01RS4};
psbool  array_m2_diag_1[4] = {&var26,&var27,&var28,&var29};
psbool  array_m3_x_1[3] = {&var91,&var111,&var24};
psbool  array_m12_x_1[3] = {&var90,&var25,&var92};

/* Объявление структур */
_S_or2  S_or2_277_1 = {&R0MD34LP1,&var12,&var1};
_S_zzfs  S_zzfs_210_1 = {&R0AD04LZ1,&fRM_0_3,&var2,&internal1_m210_tx,&internal1_m210_y0};
_S_noto  S_noto_223_1 = {&var2,&var3};
_S_and2  S_and2_226_1 = {&var3,&var5,&var4};
_S_or3  S_or3_227_1 = {&var35,&var36,&R7II73LZ1,&var5};
_S_inicn  S_inicn_205_1 = {&A3IS11LDU,&B3IS11LDU,&R0AD03LZ1,&A3IS22LDU,&B3IS22LDU,&R0AD05LZ1,&var35,&var36,&var34,&var2,&fEM_R0UL25RDU,&fEM_R0UL05RDU,&fEM_R0UL07RDU,&var6,&var7,&var8,&var9,&var10,&var11,&var12,&internal1_m205_TVuIs1,&internal1_m205_TVuIs2,&internal1_m205_TImVuIs,&internal1_m205_TNupIs1,&internal1_m205_TNupIs2,&internal1_m205_TImNupIs,&internal1_m205_TImAZ2UR,&internal1_m205_fef};
_S_zzfs  S_zzfs_110_1 = {&B1VP81LZZ,&fRM_10000_,&var13,&internal1_m110_tx,&internal1_m110_y0};
_S_zzfs  S_zzfs_107_1 = {&A1VP81LZZ,&fRM_10000_,&var14,&internal1_m107_tx,&internal1_m107_y0};
_S_zzfs  S_zzfs_135_1 = {&B0VP81LZZ,&fRM_10000_,&var15,&internal1_m135_tx,&internal1_m135_y0};
_S_zzfs  S_zzfs_134_1 = {&A0VP81LZZ,&fRM_10000_,&var16,&internal1_m134_tx,&internal1_m134_y0};
_S_or3  S_or3_314_1 = {&var20,&var19,&var18,&var17};
_S_or2  S_or2_316_1 = {&R0DEB3LZ1,&R0DEB4LZ1,&var18};
_S_or2  S_or2_310_1 = {&R0DEB1LZ1,&R0DEB2LZ1,&var19};
_S_diagndev  S_diagndev_306_1 = {array_m306_x_1,&iRM_6_,&var20,&var21};
_S_ma  S_ma_189_1 = {array_m189_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_and2  S_and2_127_1 = {&var134,&var110,&var22};
_S_and2  S_and2_138_1 = {&var133,&var109,&var23};
_S_or2  S_or2_103_1 = {&var140,&var138,&var24};
_S_or2  S_or2_108_1 = {&var135,&var136,&var25};
_S_and2  S_and2_81_1 = {&lRM_1_,&A0EE01LS1,&var26};
_S_and2  S_and2_83_1 = {&lRM_1_,&A0EE01LS2,&var27};
_S_and2  S_and2_85_1 = {&lRM_1_,&A0EE01LS3,&var28};
_S_and2  S_and2_87_1 = {&lRM_1_,&A0EE01LS4,&var29};
_S_and2  S_and2_183_1 = {&var126,&var98,&var30};
_S_and2  S_and2_184_1 = {&var125,&var98,&var31};
_S_or2  S_or2_217_1 = {&R7II73LZ1,&var88,&var32};
_S_or2  S_or2_215_1 = {&R0AD21LDU,&var2,&var33};
_S_and2  S_and2_214_1 = {&var32,&var33,&var34};
_S_or2  S_or2_206_1 = {&var87,&R7II71LZ1,&var35};
_S_or2  S_or2_199_1 = {&var89,&R7II72LZ1,&var36};
_S_schl24  S_schl24_296_1 = {&A0VN71LS2,&A0VN71LS1,&A0VN71LS4,&A0VN71LS3,&var37};
_S_and2  S_and2_283_1 = {&var54,&var76,&var38};
_S_and2  S_and2_285_1 = {&var61,&var76,&var39};
_S_and2  S_and2_286_1 = {&var99,&var76,&var40};
_S_and2  S_and2_284_1 = {&var65,&var76,&var41};
_S_and2  S_and2_282_1 = {&var47,&var76,&var42};
_S_and2  S_and2_266_1 = {&var45,&var44,&var43};
_S_or2  S_or2_268_1 = {&R0VN75LZ1,&var123,&var44};
_S_or2  S_or2_269_1 = {&R0VN77LZ1,&var122,&var45};
_S_or2  S_or2_254_1 = {&var43,&var51,&var46};
_S_or2  S_or2_260_1 = {&var48,&var43,&var47};
_S_and2  S_and2_261_1 = {&var118,&var52,&var48};
_S_or2  S_or2_271_1 = {&R0VN78LZ1,&var120,&var49};
_S_or2  S_or2_270_1 = {&R0VN76LZ1,&var121,&var50};
_S_and2  S_and2_267_1 = {&var50,&var49,&var51};
_S_schl24  S_schl24_265_1 = {&var50,&var49,&var45,&var44,&var52};
_S_and2  S_and2_263_1 = {&var76,&var52,&var53};
_S_or2  S_or2_262_1 = {&var51,&var48,&var54};
_S_and2  S_and2_258_1 = {&var54,&var76,&var55};
_S_or2  S_or2_234_1 = {&R0VN72LZ1,&var121,&var56};
_S_and2  S_and2_249_1 = {&var65,&var76,&var57};
_S_and2  S_and2_239_1 = {&var56,&var59,&var58};
_S_or2  S_or2_235_1 = {&R0VN74LZ1,&var120,&var59};
_S_and2  S_and2_250_1 = {&var61,&var76,&var60};
_S_or2  S_or2_247_1 = {&var58,&var64,&var61};
_S_or2  S_or2_253_1 = {&var66,&var58,&var62};
_S_and2  S_and2_241_1 = {&var68,&var76,&var63};
_S_and2  S_and2_246_1 = {&var119,&var68,&var64};
_S_or2  S_or2_245_1 = {&var66,&var64,&var65};
_S_and2  S_and2_236_1 = {&var67,&var69,&var66};
_S_or2  S_or2_233_1 = {&R0VN73LZ1,&var122,&var67};
_S_schl24  S_schl24_238_1 = {&var67,&var69,&var56,&var59,&var68};
_S_or2  S_or2_232_1 = {&R0VN71LZ1,&var123,&var69};
_S_or2  S_or2_155_1 = {&var103,&var141,&var70};
_S_or2  S_or2_157_1 = {&var108,&var106,&var71};
_S_or2  S_or2_294_1 = {&var139,&var137,&var72};
_S_or2  S_or2_35_1 = {&B2IS12LDU,&A2IS12LDU,&var73};
_S_and2  S_and2_257_1 = {&var76,&var47,&var74};
_S_and2  S_and2_287_1 = {&var100,&var76,&var75};
_S_and2  S_and2_21_1 = {&var97,&var93,&var76};
_S_or2  S_or2_25_1 = {&var116,&var115,&var77};
_S_and2  S_and2_31_1 = {&var79,&var76,&var78};
_S_or3  S_or3_30_1 = {&var47,&var65,&var96,&var79};
_S_and2  S_and2_19_1 = {&var76,&var81,&var80};
_S_or3  S_or3_18_1 = {&var61,&var54,&var95,&var81};
_S_and2  S_and2_6_1 = {&var27,&var29,&var82};
_S_or2  S_or2_11_1 = {&var117,&var82,&var83};
_S_or2  S_or2_10_1 = {&var85,&var117,&var84};
_S_and2  S_and2_5_1 = {&var26,&var28,&var85};
_S_zpfs  S_zpfs_225_1 = {&var4,&fEM_R0UL07RDU,&var86,&internal1_m225_tx,&internal1_m225_y0};
_S_noto  S_noto_201_1 = {&R6IS67LZZ,&var87};
_S_noto  S_noto_218_1 = {&R6IS68LZZ,&var88};
_S_noto  S_noto_200_1 = {&R6IS66LZZ,&var89};
_S_noto  S_noto_137_1 = {&var15,&var90};
_S_noto  S_noto_136_1 = {&var16,&var91};
_S_noto  S_noto_112_1 = {&var13,&var92};
_S_noto  S_noto_27_1 = {&var94,&var93};
_S_ovb1  S_ovb1_33_1 = {&var73,&iRM_200_,&var94,&internal1_m33_tx};
_S_noto  S_noto_15_1 = {&var83,&var95};
_S_noto  S_noto_14_1 = {&var84,&var96};
_S_noto  S_noto_24_1 = {&R0EE02LDU,&var97};
_S_bol  S_bol_179_1 = {&var127,&fRM_0_00001,&var98};
_S_noto  S_noto_288_1 = {&var83,&var99};
_S_noto  S_noto_289_1 = {&var84,&var100};
_S_scalzz  S_scalzz_148_1 = {&B0IT01IZ1,&iRM_3276_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var101,&internal1_m148_y0};
_S_scalzz  S_scalzz_146_1 = {&A0IT01IZ1,&iRM_3276_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var102,&internal1_m146_y0};
_S_geterr  S_geterr_150_1 = {&var102,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var103};
_S_scalzz  S_scalzz_92_1 = {&B2IP01IZ1,&iRM_3276_,&iRM_16000_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var104,&internal1_m92_y0};
_S_scalzz  S_scalzz_90_1 = {&A2IP01IZ1,&iRM_3276_,&iRM_16000_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var105,&internal1_m90_y0};
_S_drg  S_drg_159_1 = {&var101,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var106,&internal1_m159_y1};
_S_drg  S_drg_170_1 = {&var101,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var107,&internal1_m170_y1};
_S_geterr  S_geterr_152_1 = {&var101,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var108};
_S_noto  S_noto_139_1 = {&var135,&var109};
_S_noto  S_noto_126_1 = {&var140,&var110};
_S_noto  S_noto_111_1 = {&var14,&var111};
_S_srm  S_srm_290_1 = {array_m290_x_1,array_m290_diag_1,&iRM_4_,&iRM_3_,&var112,&vainSBool};
_S_rsu  S_rsu_280_1 = {&var1,&var114,&var113,&internal1_m280_q0};
_S_orni  S_orni_281_1 = {array_m281_x_1,&iRM_17_,&vainSBool,&var114};
_S_orn  S_orn_16_1 = {array_m16_x_1,&iRM_6_,&var115};
_S_orn  S_orn_36_1 = {array_m36_x_1,&iRM_6_,&var116};
_S_noto  S_noto_7_1 = {&var128,&var117};
_S_noto  S_noto_256_1 = {&var46,&var118};
_S_noto  S_noto_251_1 = {&var62,&var119};
_S_noto  S_noto_240_1 = {&A0EE01LS4,&var120};
_S_noto  S_noto_244_1 = {&A0EE01LS2,&var121};
_S_noto  S_noto_243_1 = {&A0EE01LS3,&var122};
_S_noto  S_noto_237_1 = {&A0EE01LS1,&var123};
_S_react  S_react_175_1 = {&var127,&var124};
_S_bol  S_bol_180_1 = {&fEM_R0UR04RZZ,&var127,&var125};
_S_bol  S_bol_178_1 = {&fEM_R0UR01RZZ,&var127,&var126};
_S_srm  S_srm_2_1 = {array_m2_x_1,array_m2_diag_1,&iRM_4_,&iRM_3_,&var127,&var128};
_S_ornc  S_ornc_3_1 = {array_m3_x_1,&iRM_3_,&var129,&var130};
_S_ornc  S_ornc_12_1 = {array_m12_x_1,&iRM_3_,&var131,&var132};
_S_tprg  S_tprg_128_1 = {&var104,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var133,&internal1_m128_y0};
_S_tprg  S_tprg_124_1 = {&var105,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var134,&internal1_m124_y0};
_S_geterr  S_geterr_101_1 = {&var104,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var135};
_S_drg  S_drg_106_1 = {&var104,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var136,&internal1_m106_y1};
_S_drg  S_drg_121_1 = {&var104,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var137,&internal1_m121_y1};
_S_drg  S_drg_94_1 = {&var105,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var138,&internal1_m94_y1};
_S_drg  S_drg_104_1 = {&var105,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var139,&internal1_m104_y1};
_S_geterr  S_geterr_98_1 = {&var105,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var140};
_S_drg  S_drg_156_1 = {&var102,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var141,&internal1_m156_y1};
_S_drg  S_drg_167_1 = {&var102,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var142,&internal1_m167_y1};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  noto(&S_noto_237_1);
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
  schl24(&S_schl24_296_1);
  or2(&S_or2_199_1);
  or2(&S_or2_206_1);
  or2(&S_or2_217_1);
  ma(&S_ma_189_1);
  or2(&S_or2_310_1);
  or2(&S_or2_316_1);
  zzfs(&S_zzfs_134_1);
  zzfs(&S_zzfs_135_1);
  zzfs(&S_zzfs_107_1);
  zzfs(&S_zzfs_110_1);
  or3(&S_or3_227_1);
  zzfs(&S_zzfs_210_1);
  drg(&S_drg_167_1);
  drg(&S_drg_156_1);
  geterr(&S_geterr_98_1);
  drg(&S_drg_104_1);
  drg(&S_drg_94_1);
  drg(&S_drg_121_1);
  drg(&S_drg_106_1);
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
  noto(&S_noto_112_1);
  noto(&S_noto_136_1);
  noto(&S_noto_137_1);
  or2(&S_or2_35_1);
  or2(&S_or2_294_1);
  or2(&S_or2_157_1);
  or2(&S_or2_155_1);
  schl24(&S_schl24_238_1);
  and2(&S_and2_239_1);
  schl24(&S_schl24_265_1);
  and2(&S_and2_267_1);
  or2(&S_or2_254_1);
  or2(&S_or2_215_1);
  and2(&S_and2_87_1);
  and2(&S_and2_85_1);
  and2(&S_and2_83_1);
  and2(&S_and2_81_1);
  or2(&S_or2_108_1);
  or2(&S_or2_103_1);
  and2(&S_and2_138_1);
  and2(&S_and2_127_1);
  diagndev(&S_diagndev_306_1);
  or3(&S_or3_314_1);
  noto(&S_noto_223_1);
  ornc(&S_ornc_12_1);
  ornc(&S_ornc_3_1);
  srm(&S_srm_2_1);
  bol(&S_bol_178_1);
  bol(&S_bol_180_1);
  react(&S_react_175_1);
  noto(&S_noto_256_1);
  noto(&S_noto_7_1);
  srm(&S_srm_290_1);
  bol(&S_bol_179_1);
  ovb1(&S_ovb1_33_1);
  noto(&S_noto_27_1);
  and2(&S_and2_5_1);
  or2(&S_or2_10_1);
  and2(&S_and2_6_1);
  and2(&S_and2_21_1);
  and2(&S_and2_241_1);
  or2(&S_or2_253_1);
  and2(&S_and2_263_1);
  and2(&S_and2_261_1);
  or2(&S_or2_260_1);
  and2(&S_and2_282_1);
  and2(&S_and2_214_1);
  and2(&S_and2_184_1);
  and2(&S_and2_183_1);
  inicn(&S_inicn_205_1);
  and2(&S_and2_226_1);
  or2(&S_or2_277_1);
  noto(&S_noto_251_1);
  noto(&S_noto_289_1);
  noto(&S_noto_14_1);
  zpfs(&S_zpfs_225_1);
  or2(&S_or2_11_1);
  and2(&S_and2_287_1);
  and2(&S_and2_257_1);
  and2(&S_and2_246_1);
  or2(&S_or2_247_1);
  and2(&S_and2_250_1);
  or2(&S_or2_262_1);
  and2(&S_and2_285_1);
  and2(&S_and2_283_1);
  noto(&S_noto_288_1);
  noto(&S_noto_15_1);
  or3(&S_or3_18_1);
  and2(&S_and2_19_1);
  or2(&S_or2_245_1);
  and2(&S_and2_249_1);
  and2(&S_and2_258_1);
  and2(&S_and2_284_1);
  and2(&S_and2_286_1);
  orn(&S_orn_16_1);
  orni(&S_orni_281_1);
  rsu(&S_rsu_280_1);
  or3(&S_or3_30_1);
  and2(&S_and2_31_1);
  orn(&S_orn_36_1);
  or2(&S_or2_25_1);
  setData(idR0VZ05U,&var114);
  setData(idTestDiagnBaz1,&var17);
  setData(idR0DE3DLZ1,&var18);
  setData(idR0DE3CLZ1,&var19);
  setData(idTTLBaz1,&var21);
  moveData(idR0EE04LZ1,idR0EE02LDU);
  moveData(idR0EE03LZ1,idR0EE02LDU);
  moveData(idR0EE02LZ1,idR0EE02LDU);
  moveData(idR0EE01LZ1,idR0EE02LDU);
  setData(idR0AD14LZ1,&var12);
  setData(idA3VZ13LZ1,&var8);
  setData(idA3VZ15LZ1,&var11);
  setData(idA1VN71LZ1,&var37);
  setData(idB0VT71LZ1,&var71);
  setData(idB0VT61LZ1,&var107);
  setData(idB0CT01IZ1,&var101);
  setData(idR0VP73LZ1,&var72);
  setData(idR0VN11RZ1,&var112);
  setData(idR0VZ05UZ1,&var113);
  setData(idB0VN81LZ1,&var55);
  setData(idA0VN81LZ1,&var74);
  setData(idB0VN71LZ1,&var60);
  setData(idA0VN71LZ1,&var57);
  setData(idB0VZ71LZ1,&var115);
  setData(idB0EE00LZ1,&var83);
  setData(idA0EE00LZ1,&var84);
  setData(idA0VZ71LZ1,&var116);
  setData(idA0EE03LZ1,&var28);
  setData(idA0EE02LZ1,&var27);
  setData(idA0EE04LZ1,&var29);
  setData(idA0EE01LZ1,&var26);
  setData(idR0VN80LZ1,&var53);
  setData(idR0VN70LZ1,&var63);
  setData(idR0VZ71LZ1,&var77);
  setData(idR0VR02RZ1,&var124);
  setData(idR0VN79LZ1,&var31);
  setData(idR0VN69LZ1,&var30);
  setData(idB3VZ11LZ1,&var10);
  setData(idA3VZ11LZ1,&var9);
  setData(idB3VZ31LZ1,&var7);
  setData(idA3VZ31LZ1,&var6);
  setData(idR0VN09RZ1,&var127);
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
  setData(idB0VP71LZ1,&var131);
  setData(idA0VP71LZ1,&var129);
  setData(idA0EP02IZ1,&var130);
  setData(idB0EP02IZ1,&var132);
  setData(idR0ET02LZ1,&var108);
  setData(idB0VP41LZ1,&var90);
  setData(idA0VP41LZ1,&var91);
  setData(idR0ET01LZ1,&var103);
  setData(idA2VP81LZ1,&var22);
  setData(idB2VP81LZ1,&var23);
  setData(idB2VP51LZ1,&var137);
  setData(idB2CP01RZ1,&var104);
  setData(idB2VP41LZ1,&var25);
  setData(idA2VP51LZ1,&var139);
  setData(idA2CP01RZ1,&var105);
  setData(idA2VP41LZ1,&var24);
  setData(idB1VP41LZ1,&var92);
  setData(idA1VP41LZ1,&var111);
  setData(idA0VT71LZ1,&var70);
  setData(idA0VT61LZ1,&var142);
  setData(idA0CT01IZ1,&var102);

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