#ifndef BAZ1_H
#define BAZ1_H
// Подсистема  Baz1:Baz1
static char SimulOn=0;
static short CodeSub=4;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 //Время цикла мс
float takt,taktScheme=0,taktSS=0;
#define SIZE_BUFFER 991
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
#define A0IT01IZ1	BUFFER[34]	// (vas84:04 - K01VASR, Baz1) Температура АЗ1-1
#define idA0IT01IZ1	16	// (vas84:04 - K01VASR, Baz1) Температура АЗ1-1
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
#define A2IP01IZ1	BUFFER[72]	// (vas84:04 - K02VASR, Baz1) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	33	// (vas84:04 - K02VASR, Baz1) Текущее давление СБРОС РБ1
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
#define B0IT01IZ1	BUFFER[105]	// (vas84:04 - K03VASR, Baz1) Температура АЗ2-1
#define idB0IT01IZ1	47	// (vas84:04 - K03VASR, Baz1) Температура АЗ2-1
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
#define B2IP01IZ1	BUFFER[133]	// (vas84:04 - K04VASR, Baz1) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	59	// (vas84:04 - K04VASR, Baz1) Текущее давление СБРОС РБ2
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
#define R0EE02LDU	BUFFER[199]	// ( - , Baz1, SBz1DU) Питание  АКНП  отключить
#define idR0EE02LDU	87	// ( - , Baz1, SBz1DU) Питание  АКНП  отключить
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
#define R0VZ71LZ1	BUFFER[388]	// (fds16:0a - K16FDSR, Baz1, MBz1S) Обобщенный сигнал АЗ 1 канала
#define idR0VZ71LZ1	149	// (fds16:0a - K16FDSR, Baz1, MBz1S) Обобщенный сигнал АЗ 1 канала
#define R6IS66LZ1	BUFFER[390]	// (vds32:07 - K05VDSR, - ) Исправность БУС УР
#define idR6IS66LZ1	150	// (vds32:07 - K05VDSR, - ) Исправность БУС УР
#define R7II71LZ1	BUFFER[392]	// (vds32:06 - K07VDSR, - ) Сработала АС 1К IУР
#define idR7II71LZ1	151	// (vds32:06 - K07VDSR, - ) Сработала АС 1К IУР
#define R7II72LZ1	BUFFER[394]	// (vds32:07 - K06VDSR, - ) Сработала АС 2К IУР
#define idR7II72LZ1	152	// (vds32:07 - K06VDSR, - ) Сработала АС 2К IУР
#define R7II73LZ1	BUFFER[396]	// (vds32:08 - K05VDSR, - ) Сработала АС 3К IУР
#define idR7II73LZ1	153	// (vds32:08 - K05VDSR, - ) Сработала АС 3К IУР
#define R7II74LZ1	BUFFER[398]	// (vds32:06 - K08VDSR, - ) Сработала АС 1К IIУР
#define idR7II74LZ1	154	// (vds32:06 - K08VDSR, - ) Сработала АС 1К IIУР
#define R7II75LZ1	BUFFER[400]	// (vds32:07 - K07VDSR, - ) Сработала АС 2К IIУР
#define idR7II75LZ1	155	// (vds32:07 - K07VDSR, - ) Сработала АС 2К IIУР
#define R7II76LZ1	BUFFER[402]	// (vds32:08 - K06VDSR, - ) Сработала АС 3К IIУР
#define idR7II76LZ1	156	// (vds32:08 - K06VDSR, - ) Сработала АС 3К IIУР
#define R7II81LZ1	BUFFER[404]	// ( - , Baz1) Сработала АС IУР
#define idR7II81LZ1	157	// ( - , Baz1) Сработала АС IУР
#define R7II82LZ1	BUFFER[406]	// ( - , Baz1) Сработала АС IIУР
#define idR7II82LZ1	158	// ( - , Baz1) Сработала АС IIУР
#define TTLBaz1	BUFFER[408]	// ( - , Baz1) ttl
#define idTTLBaz1	159	// ( - , Baz1) ttl
#define TestDiagnBaz1	BUFFER[411]	// ( - , Baz1) Неисправность от диагностики
#define idTestDiagnBaz1	160	// ( - , Baz1) Неисправность от диагностики
#define bFirstEnterFlag	BUFFER[413]	// (bFirstEnterFlag) 
#define idbFirstEnterFlag	161	// (bFirstEnterFlag) 
#define fEM_A2UP03RZZ	BUFFER[415]	// (A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define idfEM_A2UP03RZZ	162	// (A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define fEM_A2UP04RZZ	BUFFER[420]	// (A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define idfEM_A2UP04RZZ	163	// (A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define fEM_A2UP41RZZ	BUFFER[425]	// (A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define idfEM_A2UP41RZZ	164	// (A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define fEM_A2UP42RZZ	BUFFER[430]	// (A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define idfEM_A2UP42RZZ	165	// (A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define fEM_A2UP51RZZ	BUFFER[435]	// (A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define idfEM_A2UP51RZZ	166	// (A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define fEM_A2UP52RZZ	BUFFER[440]	// (A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define idfEM_A2UP52RZZ	167	// (A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define fEM_A2UP81RZZ	BUFFER[445]	// (A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP81RZZ	168	// (A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP82RZZ	BUFFER[450]	// (A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP82RZZ	169	// (A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP83RZZ	BUFFER[455]	// (A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP83RZZ	170	// (A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP84RZZ	BUFFER[460]	// (A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP84RZZ	171	// (A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_R0UL05RDU	BUFFER[465]	// (R0UL05RDU) Время задержки АЗ от НУП ИС(сек)
#define idfEM_R0UL05RDU	172	// (R0UL05RDU) Время задержки АЗ от НУП ИС(сек)
#define fEM_R0UL07RDU	BUFFER[470]	// (R0UL07RDU) Время задержки  срабатывания АС II УР
#define idfEM_R0UL07RDU	173	// (R0UL07RDU) Время задержки  срабатывания АС II УР
#define fEM_R0UL25RDU	BUFFER[475]	// (R0UL25RDU) Время задержки АЗ от ВУ ИС сек
#define idfEM_R0UL25RDU	174	// (R0UL25RDU) Время задержки АЗ от ВУ ИС сек
#define fEM_R0UR01RZZ	BUFFER[480]	// (R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RZZ	175	// (R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R0UR04RZZ	BUFFER[485]	// (R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define idfEM_R0UR04RZZ	176	// (R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define fEM_R0UT01RZZ	BUFFER[490]	// (R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	177	// (R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_R0UT02RZZ	BUFFER[495]	// (R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	178	// (R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT61RZZ	BUFFER[500]	// (R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	179	// (R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	BUFFER[505]	// (R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	180	// (R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	BUFFER[510]	// (R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	181	// (R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT72RZZ	BUFFER[515]	// (R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	182	// (R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define internal1_m105_y1	BUFFER[520]	// (internal1_m105_y1) y1 - внутренний параметр
#define idinternal1_m105_y1	183	// (internal1_m105_y1) y1 - внутренний параметр
#define internal1_m107_y1	BUFFER[522]	// (internal1_m107_y1) y1 - внутренний параметр
#define idinternal1_m107_y1	184	// (internal1_m107_y1) y1 - внутренний параметр
#define internal1_m108_tx	BUFFER[524]	// (internal1_m108_tx) tx - время накопленное сек
#define idinternal1_m108_tx	185	// (internal1_m108_tx) tx - время накопленное сек
#define internal1_m108_y0	BUFFER[529]	// (internal1_m108_y0) y0
#define idinternal1_m108_y0	186	// (internal1_m108_y0) y0
#define internal1_m110_tx	BUFFER[531]	// (internal1_m110_tx) tx - время накопленное сек
#define idinternal1_m110_tx	187	// (internal1_m110_tx) tx - время накопленное сек
#define internal1_m110_y0	BUFFER[536]	// (internal1_m110_y0) y0
#define idinternal1_m110_y0	188	// (internal1_m110_y0) y0
#define internal1_m118_y1	BUFFER[538]	// (internal1_m118_y1) y1 - внутренний параметр
#define idinternal1_m118_y1	189	// (internal1_m118_y1) y1 - внутренний параметр
#define internal1_m125_y0	BUFFER[540]	// (internal1_m125_y0) state
#define idinternal1_m125_y0	190	// (internal1_m125_y0) state
#define internal1_m129_y0	BUFFER[542]	// (internal1_m129_y0) state
#define idinternal1_m129_y0	191	// (internal1_m129_y0) state
#define internal1_m135_tx	BUFFER[544]	// (internal1_m135_tx) tx - время накопленное сек
#define idinternal1_m135_tx	192	// (internal1_m135_tx) tx - время накопленное сек
#define internal1_m135_y0	BUFFER[549]	// (internal1_m135_y0) y0
#define idinternal1_m135_y0	193	// (internal1_m135_y0) y0
#define internal1_m136_tx	BUFFER[551]	// (internal1_m136_tx) tx - время накопленное сек
#define idinternal1_m136_tx	194	// (internal1_m136_tx) tx - время накопленное сек
#define internal1_m136_y0	BUFFER[556]	// (internal1_m136_y0) y0
#define idinternal1_m136_y0	195	// (internal1_m136_y0) y0
#define internal1_m147_y0	BUFFER[558]	// (internal1_m147_y0) y0
#define idinternal1_m147_y0	196	// (internal1_m147_y0) y0
#define internal1_m149_y0	BUFFER[563]	// (internal1_m149_y0) y0
#define idinternal1_m149_y0	197	// (internal1_m149_y0) y0
#define internal1_m157_y1	BUFFER[568]	// (internal1_m157_y1) y1 - внутренний параметр
#define idinternal1_m157_y1	198	// (internal1_m157_y1) y1 - внутренний параметр
#define internal1_m160_y1	BUFFER[570]	// (internal1_m160_y1) y1 - внутренний параметр
#define idinternal1_m160_y1	199	// (internal1_m160_y1) y1 - внутренний параметр
#define internal1_m168_y1	BUFFER[572]	// (internal1_m168_y1) y1 - внутренний параметр
#define idinternal1_m168_y1	200	// (internal1_m168_y1) y1 - внутренний параметр
#define internal1_m171_y1	BUFFER[574]	// (internal1_m171_y1) y1 - внутренний параметр
#define idinternal1_m171_y1	201	// (internal1_m171_y1) y1 - внутренний параметр
#define internal1_m208_TImAZ2UR	BUFFER[576]	// (internal1_m208_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
#define idinternal1_m208_TImAZ2UR	202	// (internal1_m208_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
#define internal1_m208_TImNupIs	BUFFER[581]	// (internal1_m208_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
#define idinternal1_m208_TImNupIs	203	// (internal1_m208_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
#define internal1_m208_TImVuIs	BUFFER[586]	// (internal1_m208_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
#define idinternal1_m208_TImVuIs	204	// (internal1_m208_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
#define internal1_m208_TNupIs1	BUFFER[591]	// (internal1_m208_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
#define idinternal1_m208_TNupIs1	205	// (internal1_m208_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
#define internal1_m208_TNupIs2	BUFFER[596]	// (internal1_m208_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
#define idinternal1_m208_TNupIs2	206	// (internal1_m208_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
#define internal1_m208_TVuIs1	BUFFER[601]	// (internal1_m208_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
#define idinternal1_m208_TVuIs1	207	// (internal1_m208_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
#define internal1_m208_TVuIs2	BUFFER[606]	// (internal1_m208_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
#define idinternal1_m208_TVuIs2	208	// (internal1_m208_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
#define internal1_m208_fef	BUFFER[611]	// (internal1_m208_fef) fef
#define idinternal1_m208_fef	209	// (internal1_m208_fef) fef
#define internal1_m211_tx	BUFFER[613]	// (internal1_m211_tx) tx - время накопленное сек
#define idinternal1_m211_tx	210	// (internal1_m211_tx) tx - время накопленное сек
#define internal1_m211_y0	BUFFER[618]	// (internal1_m211_y0) y0
#define idinternal1_m211_y0	211	// (internal1_m211_y0) y0
#define internal1_m228_tx	BUFFER[620]	// (internal1_m228_tx) tx - время накопленное сек
#define idinternal1_m228_tx	212	// (internal1_m228_tx) tx - время накопленное сек
#define internal1_m228_y0	BUFFER[625]	// (internal1_m228_y0) y0
#define idinternal1_m228_y0	213	// (internal1_m228_y0) y0
#define internal1_m283_q0	BUFFER[627]	// (internal1_m283_q0) q0 - внутренний параметр
#define idinternal1_m283_q0	214	// (internal1_m283_q0) q0 - внутренний параметр
#define internal1_m34_tx	BUFFER[632]	// (internal1_m34_tx) tx - внутренний параметр
#define idinternal1_m34_tx	215	// (internal1_m34_tx) tx - внутренний параметр
#define internal1_m91_y0	BUFFER[635]	// (internal1_m91_y0) y0
#define idinternal1_m91_y0	216	// (internal1_m91_y0) y0
#define internal1_m93_y0	BUFFER[640]	// (internal1_m93_y0) y0
#define idinternal1_m93_y0	217	// (internal1_m93_y0) y0
#define internal1_m95_y1	BUFFER[645]	// (internal1_m95_y1) y1 - внутренний параметр
#define idinternal1_m95_y1	218	// (internal1_m95_y1) y1 - внутренний параметр
#define ttlfa1	BUFFER[647]	// ( - , MBz1A1) ttlf float
#define idttlfa1	219	// ( - , MBz1A1) ttlf float
#define vainSBool	BUFFER[652]	// Внутренняя переменная vainSBool
#define idvainSBool	220	// Внутренняя переменная vainSBool
#define vainSFloat	BUFFER[654]	// Внутренняя переменная vainSFloat
#define idvainSFloat	221	// Внутренняя переменная vainSFloat
#define vainSInt	BUFFER[659]	// Внутренняя переменная vainSInt
#define idvainSInt	222	// Внутренняя переменная vainSInt
#define vainSLong	BUFFER[664]	// Внутренняя переменная vainSLong
#define idvainSLong	223	// Внутренняя переменная vainSLong
#define var1	BUFFER[673]	// Внутренняя переменная var1
#define idvar1	224	// Внутренняя переменная var1
#define var10	BUFFER[675]	// Внутренняя переменная var10
#define idvar10	225	// Внутренняя переменная var10
#define var100	BUFFER[677]	// Внутренняя переменная var100
#define idvar100	226	// Внутренняя переменная var100
#define var101	BUFFER[679]	// Внутренняя переменная var101
#define idvar101	227	// Внутренняя переменная var101
#define var102	BUFFER[684]	// Внутренняя переменная var102
#define idvar102	228	// Внутренняя переменная var102
#define var103	BUFFER[689]	// Внутренняя переменная var103
#define idvar103	229	// Внутренняя переменная var103
#define var104	BUFFER[691]	// Внутренняя переменная var104
#define idvar104	230	// Внутренняя переменная var104
#define var105	BUFFER[696]	// Внутренняя переменная var105
#define idvar105	231	// Внутренняя переменная var105
#define var106	BUFFER[701]	// Внутренняя переменная var106
#define idvar106	232	// Внутренняя переменная var106
#define var107	BUFFER[703]	// Внутренняя переменная var107
#define idvar107	233	// Внутренняя переменная var107
#define var108	BUFFER[705]	// Внутренняя переменная var108
#define idvar108	234	// Внутренняя переменная var108
#define var109	BUFFER[707]	// Внутренняя переменная var109
#define idvar109	235	// Внутренняя переменная var109
#define var11	BUFFER[709]	// Внутренняя переменная var11
#define idvar11	236	// Внутренняя переменная var11
#define var110	BUFFER[711]	// Внутренняя переменная var110
#define idvar110	237	// Внутренняя переменная var110
#define var111	BUFFER[713]	// Внутренняя переменная var111
#define idvar111	238	// Внутренняя переменная var111
#define var112	BUFFER[715]	// Внутренняя переменная var112
#define idvar112	239	// Внутренняя переменная var112
#define var113	BUFFER[720]	// Внутренняя переменная var113
#define idvar113	240	// Внутренняя переменная var113
#define var114	BUFFER[729]	// Внутренняя переменная var114
#define idvar114	241	// Внутренняя переменная var114
#define var115	BUFFER[738]	// Внутренняя переменная var115
#define idvar115	242	// Внутренняя переменная var115
#define var116	BUFFER[740]	// Внутренняя переменная var116
#define idvar116	243	// Внутренняя переменная var116
#define var117	BUFFER[742]	// Внутренняя переменная var117
#define idvar117	244	// Внутренняя переменная var117
#define var118	BUFFER[744]	// Внутренняя переменная var118
#define idvar118	245	// Внутренняя переменная var118
#define var119	BUFFER[746]	// Внутренняя переменная var119
#define idvar119	246	// Внутренняя переменная var119
#define var12	BUFFER[748]	// Внутренняя переменная var12
#define idvar12	247	// Внутренняя переменная var12
#define var120	BUFFER[750]	// Внутренняя переменная var120
#define idvar120	248	// Внутренняя переменная var120
#define var121	BUFFER[752]	// Внутренняя переменная var121
#define idvar121	249	// Внутренняя переменная var121
#define var122	BUFFER[754]	// Внутренняя переменная var122
#define idvar122	250	// Внутренняя переменная var122
#define var123	BUFFER[756]	// Внутренняя переменная var123
#define idvar123	251	// Внутренняя переменная var123
#define var124	BUFFER[758]	// Внутренняя переменная var124
#define idvar124	252	// Внутренняя переменная var124
#define var125	BUFFER[763]	// Внутренняя переменная var125
#define idvar125	253	// Внутренняя переменная var125
#define var126	BUFFER[765]	// Внутренняя переменная var126
#define idvar126	254	// Внутренняя переменная var126
#define var127	BUFFER[767]	// Внутренняя переменная var127
#define idvar127	255	// Внутренняя переменная var127
#define var128	BUFFER[772]	// Внутренняя переменная var128
#define idvar128	256	// Внутренняя переменная var128
#define var129	BUFFER[774]	// Внутренняя переменная var129
#define idvar129	257	// Внутренняя переменная var129
#define var13	BUFFER[776]	// Внутренняя переменная var13
#define idvar13	258	// Внутренняя переменная var13
#define var131	BUFFER[778]	// Внутренняя переменная var131
#define idvar131	259	// Внутренняя переменная var131
#define var133	BUFFER[780]	// Внутренняя переменная var133
#define idvar133	260	// Внутренняя переменная var133
#define var134	BUFFER[782]	// Внутренняя переменная var134
#define idvar134	261	// Внутренняя переменная var134
#define var135	BUFFER[784]	// Внутренняя переменная var135
#define idvar135	262	// Внутренняя переменная var135
#define var136	BUFFER[786]	// Внутренняя переменная var136
#define idvar136	263	// Внутренняя переменная var136
#define var137	BUFFER[788]	// Внутренняя переменная var137
#define idvar137	264	// Внутренняя переменная var137
#define var138	BUFFER[790]	// Внутренняя переменная var138
#define idvar138	265	// Внутренняя переменная var138
#define var139	BUFFER[792]	// Внутренняя переменная var139
#define idvar139	266	// Внутренняя переменная var139
#define var14	BUFFER[794]	// Внутренняя переменная var14
#define idvar14	267	// Внутренняя переменная var14
#define var140	BUFFER[796]	// Внутренняя переменная var140
#define idvar140	268	// Внутренняя переменная var140
#define var141	BUFFER[798]	// Внутренняя переменная var141
#define idvar141	269	// Внутренняя переменная var141
#define var142	BUFFER[800]	// Внутренняя переменная var142
#define idvar142	270	// Внутренняя переменная var142
#define var15	BUFFER[802]	// Внутренняя переменная var15
#define idvar15	271	// Внутренняя переменная var15
#define var16	BUFFER[804]	// Внутренняя переменная var16
#define idvar16	272	// Внутренняя переменная var16
#define var17	BUFFER[806]	// Внутренняя переменная var17
#define idvar17	273	// Внутренняя переменная var17
#define var18	BUFFER[808]	// Внутренняя переменная var18
#define idvar18	274	// Внутренняя переменная var18
#define var19	BUFFER[810]	// Внутренняя переменная var19
#define idvar19	275	// Внутренняя переменная var19
#define var2	BUFFER[812]	// Внутренняя переменная var2
#define idvar2	276	// Внутренняя переменная var2
#define var20	BUFFER[814]	// Внутренняя переменная var20
#define idvar20	277	// Внутренняя переменная var20
#define var21	BUFFER[816]	// Внутренняя переменная var21
#define idvar21	278	// Внутренняя переменная var21
#define var22	BUFFER[818]	// Внутренняя переменная var22
#define idvar22	279	// Внутренняя переменная var22
#define var23	BUFFER[820]	// Внутренняя переменная var23
#define idvar23	280	// Внутренняя переменная var23
#define var24	BUFFER[822]	// Внутренняя переменная var24
#define idvar24	281	// Внутренняя переменная var24
#define var25	BUFFER[827]	// Внутренняя переменная var25
#define idvar25	282	// Внутренняя переменная var25
#define var26	BUFFER[829]	// Внутренняя переменная var26
#define idvar26	283	// Внутренняя переменная var26
#define var27	BUFFER[831]	// Внутренняя переменная var27
#define idvar27	284	// Внутренняя переменная var27
#define var28	BUFFER[833]	// Внутренняя переменная var28
#define idvar28	285	// Внутренняя переменная var28
#define var29	BUFFER[835]	// Внутренняя переменная var29
#define idvar29	286	// Внутренняя переменная var29
#define var3	BUFFER[837]	// Внутренняя переменная var3
#define idvar3	287	// Внутренняя переменная var3
#define var30	BUFFER[839]	// Внутренняя переменная var30
#define idvar30	288	// Внутренняя переменная var30
#define var31	BUFFER[841]	// Внутренняя переменная var31
#define idvar31	289	// Внутренняя переменная var31
#define var32	BUFFER[843]	// Внутренняя переменная var32
#define idvar32	290	// Внутренняя переменная var32
#define var33	BUFFER[845]	// Внутренняя переменная var33
#define idvar33	291	// Внутренняя переменная var33
#define var34	BUFFER[847]	// Внутренняя переменная var34
#define idvar34	292	// Внутренняя переменная var34
#define var35	BUFFER[849]	// Внутренняя переменная var35
#define idvar35	293	// Внутренняя переменная var35
#define var36	BUFFER[851]	// Внутренняя переменная var36
#define idvar36	294	// Внутренняя переменная var36
#define var37	BUFFER[853]	// Внутренняя переменная var37
#define idvar37	295	// Внутренняя переменная var37
#define var38	BUFFER[855]	// Внутренняя переменная var38
#define idvar38	296	// Внутренняя переменная var38
#define var39	BUFFER[857]	// Внутренняя переменная var39
#define idvar39	297	// Внутренняя переменная var39
#define var4	BUFFER[859]	// Внутренняя переменная var4
#define idvar4	298	// Внутренняя переменная var4
#define var40	BUFFER[861]	// Внутренняя переменная var40
#define idvar40	299	// Внутренняя переменная var40
#define var41	BUFFER[863]	// Внутренняя переменная var41
#define idvar41	300	// Внутренняя переменная var41
#define var42	BUFFER[865]	// Внутренняя переменная var42
#define idvar42	301	// Внутренняя переменная var42
#define var43	BUFFER[867]	// Внутренняя переменная var43
#define idvar43	302	// Внутренняя переменная var43
#define var44	BUFFER[869]	// Внутренняя переменная var44
#define idvar44	303	// Внутренняя переменная var44
#define var45	BUFFER[871]	// Внутренняя переменная var45
#define idvar45	304	// Внутренняя переменная var45
#define var46	BUFFER[873]	// Внутренняя переменная var46
#define idvar46	305	// Внутренняя переменная var46
#define var47	BUFFER[875]	// Внутренняя переменная var47
#define idvar47	306	// Внутренняя переменная var47
#define var48	BUFFER[877]	// Внутренняя переменная var48
#define idvar48	307	// Внутренняя переменная var48
#define var49	BUFFER[879]	// Внутренняя переменная var49
#define idvar49	308	// Внутренняя переменная var49
#define var5	BUFFER[881]	// Внутренняя переменная var5
#define idvar5	309	// Внутренняя переменная var5
#define var50	BUFFER[883]	// Внутренняя переменная var50
#define idvar50	310	// Внутренняя переменная var50
#define var51	BUFFER[885]	// Внутренняя переменная var51
#define idvar51	311	// Внутренняя переменная var51
#define var52	BUFFER[887]	// Внутренняя переменная var52
#define idvar52	312	// Внутренняя переменная var52
#define var53	BUFFER[889]	// Внутренняя переменная var53
#define idvar53	313	// Внутренняя переменная var53
#define var54	BUFFER[891]	// Внутренняя переменная var54
#define idvar54	314	// Внутренняя переменная var54
#define var55	BUFFER[893]	// Внутренняя переменная var55
#define idvar55	315	// Внутренняя переменная var55
#define var56	BUFFER[895]	// Внутренняя переменная var56
#define idvar56	316	// Внутренняя переменная var56
#define var57	BUFFER[897]	// Внутренняя переменная var57
#define idvar57	317	// Внутренняя переменная var57
#define var58	BUFFER[899]	// Внутренняя переменная var58
#define idvar58	318	// Внутренняя переменная var58
#define var59	BUFFER[901]	// Внутренняя переменная var59
#define idvar59	319	// Внутренняя переменная var59
#define var6	BUFFER[903]	// Внутренняя переменная var6
#define idvar6	320	// Внутренняя переменная var6
#define var60	BUFFER[905]	// Внутренняя переменная var60
#define idvar60	321	// Внутренняя переменная var60
#define var61	BUFFER[907]	// Внутренняя переменная var61
#define idvar61	322	// Внутренняя переменная var61
#define var62	BUFFER[909]	// Внутренняя переменная var62
#define idvar62	323	// Внутренняя переменная var62
#define var63	BUFFER[911]	// Внутренняя переменная var63
#define idvar63	324	// Внутренняя переменная var63
#define var64	BUFFER[913]	// Внутренняя переменная var64
#define idvar64	325	// Внутренняя переменная var64
#define var65	BUFFER[915]	// Внутренняя переменная var65
#define idvar65	326	// Внутренняя переменная var65
#define var66	BUFFER[917]	// Внутренняя переменная var66
#define idvar66	327	// Внутренняя переменная var66
#define var67	BUFFER[919]	// Внутренняя переменная var67
#define idvar67	328	// Внутренняя переменная var67
#define var68	BUFFER[921]	// Внутренняя переменная var68
#define idvar68	329	// Внутренняя переменная var68
#define var69	BUFFER[923]	// Внутренняя переменная var69
#define idvar69	330	// Внутренняя переменная var69
#define var7	BUFFER[925]	// Внутренняя переменная var7
#define idvar7	331	// Внутренняя переменная var7
#define var70	BUFFER[927]	// Внутренняя переменная var70
#define idvar70	332	// Внутренняя переменная var70
#define var71	BUFFER[929]	// Внутренняя переменная var71
#define idvar71	333	// Внутренняя переменная var71
#define var72	BUFFER[931]	// Внутренняя переменная var72
#define idvar72	334	// Внутренняя переменная var72
#define var73	BUFFER[933]	// Внутренняя переменная var73
#define idvar73	335	// Внутренняя переменная var73
#define var74	BUFFER[935]	// Внутренняя переменная var74
#define idvar74	336	// Внутренняя переменная var74
#define var75	BUFFER[937]	// Внутренняя переменная var75
#define idvar75	337	// Внутренняя переменная var75
#define var76	BUFFER[939]	// Внутренняя переменная var76
#define idvar76	338	// Внутренняя переменная var76
#define var77	BUFFER[941]	// Внутренняя переменная var77
#define idvar77	339	// Внутренняя переменная var77
#define var78	BUFFER[943]	// Внутренняя переменная var78
#define idvar78	340	// Внутренняя переменная var78
#define var79	BUFFER[945]	// Внутренняя переменная var79
#define idvar79	341	// Внутренняя переменная var79
#define var8	BUFFER[947]	// Внутренняя переменная var8
#define idvar8	342	// Внутренняя переменная var8
#define var80	BUFFER[949]	// Внутренняя переменная var80
#define idvar80	343	// Внутренняя переменная var80
#define var81	BUFFER[951]	// Внутренняя переменная var81
#define idvar81	344	// Внутренняя переменная var81
#define var82	BUFFER[953]	// Внутренняя переменная var82
#define idvar82	345	// Внутренняя переменная var82
#define var83	BUFFER[955]	// Внутренняя переменная var83
#define idvar83	346	// Внутренняя переменная var83
#define var84	BUFFER[957]	// Внутренняя переменная var84
#define idvar84	347	// Внутренняя переменная var84
#define var85	BUFFER[959]	// Внутренняя переменная var85
#define idvar85	348	// Внутренняя переменная var85
#define var86	BUFFER[961]	// Внутренняя переменная var86
#define idvar86	349	// Внутренняя переменная var86
#define var87	BUFFER[963]	// Внутренняя переменная var87
#define idvar87	350	// Внутренняя переменная var87
#define var88	BUFFER[965]	// Внутренняя переменная var88
#define idvar88	351	// Внутренняя переменная var88
#define var89	BUFFER[967]	// Внутренняя переменная var89
#define idvar89	352	// Внутренняя переменная var89
#define var9	BUFFER[969]	// Внутренняя переменная var9
#define idvar9	353	// Внутренняя переменная var9
#define var90	BUFFER[971]	// Внутренняя переменная var90
#define idvar90	354	// Внутренняя переменная var90
#define var91	BUFFER[973]	// Внутренняя переменная var91
#define idvar91	355	// Внутренняя переменная var91
#define var92	BUFFER[975]	// Внутренняя переменная var92
#define idvar92	356	// Внутренняя переменная var92
#define var93	BUFFER[977]	// Внутренняя переменная var93
#define idvar93	357	// Внутренняя переменная var93
#define var94	BUFFER[979]	// Внутренняя переменная var94
#define idvar94	358	// Внутренняя переменная var94
#define var95	BUFFER[981]	// Внутренняя переменная var95
#define idvar95	359	// Внутренняя переменная var95
#define var96	BUFFER[983]	// Внутренняя переменная var96
#define idvar96	360	// Внутренняя переменная var96
#define var97	BUFFER[985]	// Внутренняя переменная var97
#define idvar97	361	// Внутренняя переменная var97
#define var98	BUFFER[987]	// Внутренняя переменная var98
#define idvar98	362	// Внутренняя переменная var98
#define var99	BUFFER[989]	// Внутренняя переменная var99
#define idvar99	363	// Внутренняя переменная var99
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
	{16	,3	,1	,&A0IT01IZ1},	//(vas84:04 - K01VASR, Baz1) Температура АЗ1-1
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
	{33	,3	,1	,&A2IP01IZ1},	//(vas84:04 - K02VASR, Baz1) Текущее давление СБРОС РБ1
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
	{47	,3	,1	,&B0IT01IZ1},	//(vas84:04 - K03VASR, Baz1) Температура АЗ2-1
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
	{59	,3	,1	,&B2IP01IZ1},	//(vas84:04 - K04VASR, Baz1) Текущее давление СБРОС РБ2
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
	{87	,1	,1	,&R0EE02LDU},	//( - , Baz1, SBz1DU) Питание  АКНП  отключить
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
	{149	,1	,1	,&R0VZ71LZ1},	//(fds16:0a - K16FDSR, Baz1, MBz1S) Обобщенный сигнал АЗ 1 канала
	{150	,1	,1	,&R6IS66LZ1},	//(vds32:07 - K05VDSR, - ) Исправность БУС УР
	{151	,1	,1	,&R7II71LZ1},	//(vds32:06 - K07VDSR, - ) Сработала АС 1К IУР
	{152	,1	,1	,&R7II72LZ1},	//(vds32:07 - K06VDSR, - ) Сработала АС 2К IУР
	{153	,1	,1	,&R7II73LZ1},	//(vds32:08 - K05VDSR, - ) Сработала АС 3К IУР
	{154	,1	,1	,&R7II74LZ1},	//(vds32:06 - K08VDSR, - ) Сработала АС 1К IIУР
	{155	,1	,1	,&R7II75LZ1},	//(vds32:07 - K07VDSR, - ) Сработала АС 2К IIУР
	{156	,1	,1	,&R7II76LZ1},	//(vds32:08 - K06VDSR, - ) Сработала АС 3К IIУР
	{157	,1	,1	,&R7II81LZ1},	//( - , Baz1) Сработала АС IУР
	{158	,1	,1	,&R7II82LZ1},	//( - , Baz1) Сработала АС IIУР
	{159	,3	,1	,&TTLBaz1},	//( - , Baz1) ttl
	{160	,1	,1	,&TestDiagnBaz1},	//( - , Baz1) Неисправность от диагностики
	{161	,1	,1	,&bFirstEnterFlag},	//(bFirstEnterFlag) 
	{162	,8	,1	,&fEM_A2UP03RZZ},	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{163	,8	,1	,&fEM_A2UP04RZZ},	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{164	,8	,1	,&fEM_A2UP41RZZ},	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{165	,8	,1	,&fEM_A2UP42RZZ},	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{166	,8	,1	,&fEM_A2UP51RZZ},	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{167	,8	,1	,&fEM_A2UP52RZZ},	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{168	,8	,1	,&fEM_A2UP81RZZ},	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{169	,8	,1	,&fEM_A2UP82RZZ},	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{170	,8	,1	,&fEM_A2UP83RZZ},	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{171	,8	,1	,&fEM_A2UP84RZZ},	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{172	,8	,1	,&fEM_R0UL05RDU},	//(R0UL05RDU) Время задержки АЗ от НУП ИС(сек)
	{173	,8	,1	,&fEM_R0UL07RDU},	//(R0UL07RDU) Время задержки  срабатывания АС II УР
	{174	,8	,1	,&fEM_R0UL25RDU},	//(R0UL25RDU) Время задержки АЗ от ВУ ИС сек
	{175	,8	,1	,&fEM_R0UR01RZZ},	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
	{176	,8	,1	,&fEM_R0UR04RZZ},	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
	{177	,8	,1	,&fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{178	,8	,1	,&fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{179	,8	,1	,&fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{180	,8	,1	,&fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{181	,8	,1	,&fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{182	,8	,1	,&fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{183	,1	,1	,&internal1_m105_y1},	//(internal1_m105_y1) y1 - внутренний параметр
	{184	,1	,1	,&internal1_m107_y1},	//(internal1_m107_y1) y1 - внутренний параметр
	{185	,8	,1	,&internal1_m108_tx},	//(internal1_m108_tx) tx - время накопленное сек
	{186	,18	,1	,&internal1_m108_y0},	//(internal1_m108_y0) y0
	{187	,8	,1	,&internal1_m110_tx},	//(internal1_m110_tx) tx - время накопленное сек
	{188	,18	,1	,&internal1_m110_y0},	//(internal1_m110_y0) y0
	{189	,1	,1	,&internal1_m118_y1},	//(internal1_m118_y1) y1 - внутренний параметр
	{190	,1	,1	,&internal1_m125_y0},	//(internal1_m125_y0) state
	{191	,1	,1	,&internal1_m129_y0},	//(internal1_m129_y0) state
	{192	,8	,1	,&internal1_m135_tx},	//(internal1_m135_tx) tx - время накопленное сек
	{193	,18	,1	,&internal1_m135_y0},	//(internal1_m135_y0) y0
	{194	,8	,1	,&internal1_m136_tx},	//(internal1_m136_tx) tx - время накопленное сек
	{195	,18	,1	,&internal1_m136_y0},	//(internal1_m136_y0) y0
	{196	,8	,1	,&internal1_m147_y0},	//(internal1_m147_y0) y0
	{197	,8	,1	,&internal1_m149_y0},	//(internal1_m149_y0) y0
	{198	,1	,1	,&internal1_m157_y1},	//(internal1_m157_y1) y1 - внутренний параметр
	{199	,1	,1	,&internal1_m160_y1},	//(internal1_m160_y1) y1 - внутренний параметр
	{200	,1	,1	,&internal1_m168_y1},	//(internal1_m168_y1) y1 - внутренний параметр
	{201	,1	,1	,&internal1_m171_y1},	//(internal1_m171_y1) y1 - внутренний параметр
	{202	,8	,1	,&internal1_m208_TImAZ2UR},	//(internal1_m208_TImAZ2UR) ImVuIs - Время до имитации срабатывания АС 2УР
	{203	,8	,1	,&internal1_m208_TImNupIs},	//(internal1_m208_TImNupIs)  Время до срабатывания имитации АС от ухода с НУП ИС
	{204	,8	,1	,&internal1_m208_TImVuIs},	//(internal1_m208_TImVuIs)  Время до срабатывания имитации АС от прихода на ВУ ИС1,ИС2 
	{205	,8	,1	,&internal1_m208_TNupIs1},	//(internal1_m208_TNupIs1)  Время до срабатывания АС от ухода с НУП ИС1
	{206	,8	,1	,&internal1_m208_TNupIs2},	//(internal1_m208_TNupIs2)  Время до срабатывания АС от ухода с НУП ИС2
	{207	,8	,1	,&internal1_m208_TVuIs1},	//(internal1_m208_TVuIs1)  Время до срабатывания АС от прихода на ВУ ИС1
	{208	,8	,1	,&internal1_m208_TVuIs2},	//(internal1_m208_TVuIs2)  Время до срабатывания АС от прихода на ВУ ИС2
	{209	,1	,1	,&internal1_m208_fef},	//(internal1_m208_fef) fef
	{210	,8	,1	,&internal1_m211_tx},	//(internal1_m211_tx) tx - время накопленное сек
	{211	,18	,1	,&internal1_m211_y0},	//(internal1_m211_y0) y0
	{212	,8	,1	,&internal1_m228_tx},	//(internal1_m228_tx) tx - время накопленное сек
	{213	,18	,1	,&internal1_m228_y0},	//(internal1_m228_y0) y0
	{214	,5	,1	,&internal1_m283_q0},	//(internal1_m283_q0) q0 - внутренний параметр
	{215	,3	,1	,&internal1_m34_tx},	//(internal1_m34_tx) tx - внутренний параметр
	{216	,8	,1	,&internal1_m91_y0},	//(internal1_m91_y0) y0
	{217	,8	,1	,&internal1_m93_y0},	//(internal1_m93_y0) y0
	{218	,1	,1	,&internal1_m95_y1},	//(internal1_m95_y1) y1 - внутренний параметр
	{219	,8	,1	,&ttlfa1},	//( - , MBz1A1) ttlf float
	{220	,1	,1	,&vainSBool},	//Внутренняя переменная vainSBool
	{221	,8	,1	,&vainSFloat},	//Внутренняя переменная vainSFloat
	{222	,5	,1	,&vainSInt},	//Внутренняя переменная vainSInt
	{223	,11	,1	,&vainSLong},	//Внутренняя переменная vainSLong
	{224	,1	,1	,&var1},	//Внутренняя переменная var1
	{225	,1	,1	,&var10},	//Внутренняя переменная var10
	{226	,1	,1	,&var100},	//Внутренняя переменная var100
	{227	,8	,1	,&var101},	//Внутренняя переменная var101
	{228	,8	,1	,&var102},	//Внутренняя переменная var102
	{229	,1	,1	,&var103},	//Внутренняя переменная var103
	{230	,8	,1	,&var104},	//Внутренняя переменная var104
	{231	,8	,1	,&var105},	//Внутренняя переменная var105
	{232	,1	,1	,&var106},	//Внутренняя переменная var106
	{233	,1	,1	,&var107},	//Внутренняя переменная var107
	{234	,1	,1	,&var108},	//Внутренняя переменная var108
	{235	,1	,1	,&var109},	//Внутренняя переменная var109
	{236	,1	,1	,&var11},	//Внутренняя переменная var11
	{237	,1	,1	,&var110},	//Внутренняя переменная var110
	{238	,1	,1	,&var111},	//Внутренняя переменная var111
	{239	,8	,1	,&var112},	//Внутренняя переменная var112
	{240	,11	,1	,&var113},	//Внутренняя переменная var113
	{241	,11	,1	,&var114},	//Внутренняя переменная var114
	{242	,1	,1	,&var115},	//Внутренняя переменная var115
	{243	,1	,1	,&var116},	//Внутренняя переменная var116
	{244	,1	,1	,&var117},	//Внутренняя переменная var117
	{245	,1	,1	,&var118},	//Внутренняя переменная var118
	{246	,1	,1	,&var119},	//Внутренняя переменная var119
	{247	,1	,1	,&var12},	//Внутренняя переменная var12
	{248	,1	,1	,&var120},	//Внутренняя переменная var120
	{249	,1	,1	,&var121},	//Внутренняя переменная var121
	{250	,1	,1	,&var122},	//Внутренняя переменная var122
	{251	,1	,1	,&var123},	//Внутренняя переменная var123
	{252	,8	,1	,&var124},	//Внутренняя переменная var124
	{253	,1	,1	,&var125},	//Внутренняя переменная var125
	{254	,1	,1	,&var126},	//Внутренняя переменная var126
	{255	,8	,1	,&var127},	//Внутренняя переменная var127
	{256	,1	,1	,&var128},	//Внутренняя переменная var128
	{257	,1	,1	,&var129},	//Внутренняя переменная var129
	{258	,1	,1	,&var13},	//Внутренняя переменная var13
	{259	,1	,1	,&var131},	//Внутренняя переменная var131
	{260	,1	,1	,&var133},	//Внутренняя переменная var133
	{261	,1	,1	,&var134},	//Внутренняя переменная var134
	{262	,1	,1	,&var135},	//Внутренняя переменная var135
	{263	,1	,1	,&var136},	//Внутренняя переменная var136
	{264	,1	,1	,&var137},	//Внутренняя переменная var137
	{265	,1	,1	,&var138},	//Внутренняя переменная var138
	{266	,1	,1	,&var139},	//Внутренняя переменная var139
	{267	,1	,1	,&var14},	//Внутренняя переменная var14
	{268	,1	,1	,&var140},	//Внутренняя переменная var140
	{269	,1	,1	,&var141},	//Внутренняя переменная var141
	{270	,1	,1	,&var142},	//Внутренняя переменная var142
	{271	,1	,1	,&var15},	//Внутренняя переменная var15
	{272	,1	,1	,&var16},	//Внутренняя переменная var16
	{273	,1	,1	,&var17},	//Внутренняя переменная var17
	{274	,1	,1	,&var18},	//Внутренняя переменная var18
	{275	,1	,1	,&var19},	//Внутренняя переменная var19
	{276	,1	,1	,&var2},	//Внутренняя переменная var2
	{277	,1	,1	,&var20},	//Внутренняя переменная var20
	{278	,1	,1	,&var21},	//Внутренняя переменная var21
	{279	,1	,1	,&var22},	//Внутренняя переменная var22
	{280	,1	,1	,&var23},	//Внутренняя переменная var23
	{281	,5	,1	,&var24},	//Внутренняя переменная var24
	{282	,1	,1	,&var25},	//Внутренняя переменная var25
	{283	,1	,1	,&var26},	//Внутренняя переменная var26
	{284	,1	,1	,&var27},	//Внутренняя переменная var27
	{285	,1	,1	,&var28},	//Внутренняя переменная var28
	{286	,1	,1	,&var29},	//Внутренняя переменная var29
	{287	,1	,1	,&var3},	//Внутренняя переменная var3
	{288	,1	,1	,&var30},	//Внутренняя переменная var30
	{289	,1	,1	,&var31},	//Внутренняя переменная var31
	{290	,1	,1	,&var32},	//Внутренняя переменная var32
	{291	,1	,1	,&var33},	//Внутренняя переменная var33
	{292	,1	,1	,&var34},	//Внутренняя переменная var34
	{293	,1	,1	,&var35},	//Внутренняя переменная var35
	{294	,1	,1	,&var36},	//Внутренняя переменная var36
	{295	,1	,1	,&var37},	//Внутренняя переменная var37
	{296	,1	,1	,&var38},	//Внутренняя переменная var38
	{297	,1	,1	,&var39},	//Внутренняя переменная var39
	{298	,1	,1	,&var4},	//Внутренняя переменная var4
	{299	,1	,1	,&var40},	//Внутренняя переменная var40
	{300	,1	,1	,&var41},	//Внутренняя переменная var41
	{301	,1	,1	,&var42},	//Внутренняя переменная var42
	{302	,1	,1	,&var43},	//Внутренняя переменная var43
	{303	,1	,1	,&var44},	//Внутренняя переменная var44
	{304	,1	,1	,&var45},	//Внутренняя переменная var45
	{305	,1	,1	,&var46},	//Внутренняя переменная var46
	{306	,1	,1	,&var47},	//Внутренняя переменная var47
	{307	,1	,1	,&var48},	//Внутренняя переменная var48
	{308	,1	,1	,&var49},	//Внутренняя переменная var49
	{309	,1	,1	,&var5},	//Внутренняя переменная var5
	{310	,1	,1	,&var50},	//Внутренняя переменная var50
	{311	,1	,1	,&var51},	//Внутренняя переменная var51
	{312	,1	,1	,&var52},	//Внутренняя переменная var52
	{313	,1	,1	,&var53},	//Внутренняя переменная var53
	{314	,1	,1	,&var54},	//Внутренняя переменная var54
	{315	,1	,1	,&var55},	//Внутренняя переменная var55
	{316	,1	,1	,&var56},	//Внутренняя переменная var56
	{317	,1	,1	,&var57},	//Внутренняя переменная var57
	{318	,1	,1	,&var58},	//Внутренняя переменная var58
	{319	,1	,1	,&var59},	//Внутренняя переменная var59
	{320	,1	,1	,&var6},	//Внутренняя переменная var6
	{321	,1	,1	,&var60},	//Внутренняя переменная var60
	{322	,1	,1	,&var61},	//Внутренняя переменная var61
	{323	,1	,1	,&var62},	//Внутренняя переменная var62
	{324	,1	,1	,&var63},	//Внутренняя переменная var63
	{325	,1	,1	,&var64},	//Внутренняя переменная var64
	{326	,1	,1	,&var65},	//Внутренняя переменная var65
	{327	,1	,1	,&var66},	//Внутренняя переменная var66
	{328	,1	,1	,&var67},	//Внутренняя переменная var67
	{329	,1	,1	,&var68},	//Внутренняя переменная var68
	{330	,1	,1	,&var69},	//Внутренняя переменная var69
	{331	,1	,1	,&var7},	//Внутренняя переменная var7
	{332	,1	,1	,&var70},	//Внутренняя переменная var70
	{333	,1	,1	,&var71},	//Внутренняя переменная var71
	{334	,1	,1	,&var72},	//Внутренняя переменная var72
	{335	,1	,1	,&var73},	//Внутренняя переменная var73
	{336	,1	,1	,&var74},	//Внутренняя переменная var74
	{337	,1	,1	,&var75},	//Внутренняя переменная var75
	{338	,1	,1	,&var76},	//Внутренняя переменная var76
	{339	,1	,1	,&var77},	//Внутренняя переменная var77
	{340	,1	,1	,&var78},	//Внутренняя переменная var78
	{341	,1	,1	,&var79},	//Внутренняя переменная var79
	{342	,1	,1	,&var8},	//Внутренняя переменная var8
	{343	,1	,1	,&var80},	//Внутренняя переменная var80
	{344	,1	,1	,&var81},	//Внутренняя переменная var81
	{345	,1	,1	,&var82},	//Внутренняя переменная var82
	{346	,1	,1	,&var83},	//Внутренняя переменная var83
	{347	,1	,1	,&var84},	//Внутренняя переменная var84
	{348	,1	,1	,&var85},	//Внутренняя переменная var85
	{349	,1	,1	,&var86},	//Внутренняя переменная var86
	{350	,1	,1	,&var87},	//Внутренняя переменная var87
	{351	,1	,1	,&var88},	//Внутренняя переменная var88
	{352	,1	,1	,&var89},	//Внутренняя переменная var89
	{353	,1	,1	,&var9},	//Внутренняя переменная var9
	{354	,1	,1	,&var90},	//Внутренняя переменная var90
	{355	,1	,1	,&var91},	//Внутренняя переменная var91
	{356	,1	,1	,&var92},	//Внутренняя переменная var92
	{357	,1	,1	,&var93},	//Внутренняя переменная var93
	{358	,1	,1	,&var94},	//Внутренняя переменная var94
	{359	,1	,1	,&var95},	//Внутренняя переменная var95
	{360	,1	,1	,&var96},	//Внутренняя переменная var96
	{361	,1	,1	,&var97},	//Внутренняя переменная var97
	{362	,1	,1	,&var98},	//Внутренняя переменная var98
	{363	,1	,1	,&var99},	//Внутренняя переменная var99
	{-1,0,NULL},
};
static char NameSaveFile[]="baz1.bin\0"; //Имя файла сохранения переменных
#pragma pop
static VarSaveCtrl saveVariables[]={	//Id переменных для сохранения
	{162,"fEM_A2UP03RZZ\0"},	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{163,"fEM_A2UP04RZZ\0"},	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{164,"fEM_A2UP41RZZ\0"},	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{165,"fEM_A2UP42RZZ\0"},	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{166,"fEM_A2UP51RZZ\0"},	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{167,"fEM_A2UP52RZZ\0"},	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{168,"fEM_A2UP81RZZ\0"},	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{169,"fEM_A2UP82RZZ\0"},	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{170,"fEM_A2UP83RZZ\0"},	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{171,"fEM_A2UP84RZZ\0"},	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{172,"fEM_R0UL05RDU\0"},	//(R0UL05RDU) Время задержки АЗ от НУП ИС(сек)
	{173,"fEM_R0UL07RDU\0"},	//(R0UL07RDU) Время задержки  срабатывания АС II УР
	{174,"fEM_R0UL25RDU\0"},	//(R0UL25RDU) Время задержки АЗ от ВУ ИС сек
	{175,"fEM_R0UR01RZZ\0"},	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
	{176,"fEM_R0UR04RZZ\0"},	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
	{177,"fEM_R0UT01RZZ\0"},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{178,"fEM_R0UT02RZZ\0"},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{179,"fEM_R0UT61RZZ\0"},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{180,"fEM_R0UT62RZZ\0"},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{181,"fEM_R0UT71RZZ\0"},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{182,"fEM_R0UT72RZZ\0"},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_Baz1[]={
	{&R0EE02LDU,1,0},	//( - , Baz1, SBz1DU) Питание  АКНП  отключить
	{&A0EE08LZ1,1,1},	//( - , Baz1) Исправность сети АКНП4
	{&A0EE07LZ1,1,2},	//( - , Baz1) Исправность сети АКНП3
	{&A0EE06LZ1,1,3},	//( - , Baz1) Исправность сети АКНП2
	{&A0EE05LZ1,1,4},	//( - , Baz1) Исправность сети АКНП1
	{&R0VN70LZ1,1,5},	//( - , Baz1) АЗ по АС мощности РУ
	{&R0MD34LP1,1,6},	//( - , Baz1) Кнопка (Квитировать)
	{&R0VW23LDU,1,7},	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,8},	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{&R0VN64LZ1,1,9},	//( - , Baz1) ПС по мощности канал 4
	{&R0VN63LZ1,1,10},	//( - , Baz1) ПС по мощности канал 3
	{&R0VN62LZ1,1,11},	//( - , Baz1) ПС по мощности канал 2
	{&R0VN61LZ1,1,12},	//( - , Baz1) ПС по мощности канал 1
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
	{&R0VZ71LZ1,1,13},	//( - K16FDSR, Baz1, MBz1S) Обобщенный сигнал АЗ 1 канала
	{&R0VN79LZ1,1,14},	//( - , Baz1) АС по усредненному периоду
	{&R0VN69LZ1,1,15},	//( - , Baz1) ПС по усредненному периоду
	{&R7II82LZ1,1,16},	//( - , Baz1) Сработала АС IIУР
	{&R7II81LZ1,1,17},	//( - , Baz1) Сработала АС IУР
	{&TestDiagnBaz1,1,18},	//( - , Baz1) Неисправность от диагностики
	{&R0VN78LZ1,1,19},	//( - K02VDSR, Baz1) АС по периоду разгона канал  4
	{&R0VN74LZ1,1,20},	//( - K01VDSR, Baz1) АС по мощности канал 4
	{&R0VN77LZ1,1,21},	//( - K02VDSR, Baz1) АС по периоду разгона канал  3
	{&R0VN73LZ1,1,22},	//( - K01VDSR, Baz1) АС по мощности канал 3
	{&R0VN76LZ1,1,23},	//( - K02VDSR, Baz1) АС по периоду разгона канал  2
	{&R0VN72LZ1,1,24},	//( - K01VDSR, Baz1) АС по мощности канал 2
	{&R0VN75LZ1,1,25},	//( - K02VDSR, Baz1) АС по периоду разгона канал 1
	{&R0VN71LZ1,1,26},	//( - K01VDSR, Baz1) АС по мощности канал 1
	{&B0VT71LZ1,1,27},	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
	{&B0VT61LZ1,1,28},	//( - , Baz1) ПС по температуре в АЗ2
	{&R0VP73LZ1,1,29},	//( - , Baz1, SBz1DU) ПС давления для РУ
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
	{&B3VZ11LZ1,1,44},	//( - , Baz1) АЗ от НУП ИС2
	{&A3VZ11LZ1,1,45},	//( - , Baz1) АЗ от НУП ИС1
	{&B3VZ31LZ1,1,46},	//( - , Baz1) АЗ от ВУ ИС2
	{&A3VZ31LZ1,1,47},	//( - , Baz1) АЗ от ВУ ИС1
	{&R0VN68LZ1,1,48},	//( - , Baz1) ПС по периоду разгона канал 4
	{&R0VN67LZ1,1,49},	//( - , Baz1) ПС по периоду разгона канал 3
	{&R0VN66LZ1,1,50},	//( - , Baz1) ПС по периоду разгона канал 2
	{&R0VN65LZ1,1,51},	//( - , Baz1) ПС по периоду разгона канал 1
	{&B0VP71LZ1,1,52},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
	{&A0VP71LZ1,1,53},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_Baz1[]={
	{&R0VR02RZ1,8,0},	//( - , Baz1) Усредненная реактивность
	{&TTLBaz1,3,2},	//( - , Baz1) ttl
	{&B0CT01IZ1,8,3},	//( - , Baz1, SBz1DU) Температура АЗ2-1
	{&R0VN11RZ1,8,5},	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
	{&R0VZ05UZ1,5,7},	//( - , Baz1) Индикатор причины сброса
	{&A0EP02IZ1,3,9},	//( - , Baz1) Индикатор -Давление  АЗ1 ниже АС
	{&B0EP02IZ1,3,10},	//( - , Baz1) Индикатор -Давление  АЗ2 ниже АС
	{&B0IT01IZ1,3,11},	//( - K03VASR, Baz1) Температура АЗ2-1
	{&B2IP01IZ1,3,12},	//( - K04VASR, Baz1) Текущее давление СБРОС РБ2
	{&A2IP01IZ1,3,13},	//( - K02VASR, Baz1) Текущее давление СБРОС РБ1
	{&B2CP01RZ1,8,14},	//( - , Baz1) Текущее давление СБРОС РБ2
	{&A2CP01RZ1,8,16},	//( - , Baz1) Текущее давление СБРОС РБ1
	{&A0CT01IZ1,8,18},	//( - , Baz1, SBz1DU) Температура АЗ1-1
	{&A0IT01IZ1,3,20},	//( - K01VASR, Baz1) Температура АЗ1-1
	{&R0VN09RZ1,8,21},	//( - , Baz1) Усредненный период разгона
	{&R0VN08RZ1,8,23},	//( - , Baz1) Период разгона по каналу 4
	{&R0VN07RZ1,8,25},	//( - , Baz1) Период разгона по каналу 3
	{&R0VN06RZ1,8,27},	//( - , Baz1) Период разгона по каналу 2
	{&R0VN05RZ1,8,29},	//( - , Baz1) Период разгона по каналу 1
	{&R0VN04RZ1,8,31},	//( - , Baz1) Уровень мощности по каналу 4
	{&R0VN03RZ1,8,33},	//( - , Baz1) Уровень мощности по каналу 3
	{&R0VN02RZ1,8,35},	//( - , Baz1) Уровень мощности по каналу 2
	{&R0VN01RZ1,8,37},	//( - , Baz1) Уровень мощности по каналу 1
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
static ModbusRegister coil_MBz1S[]={
	{&R0VZ71LZ1,1,0},	//( - , SCM, SBz1) Обобщенный сигнал по АЗ  1 канала
	{&R0EE01LZ1,1,1},	//( - , SBz1) Питание  АКНП1  отключить
	{&R0EE02LZ1,1,2},	//( - , SBz1) Питание  АКНП  отключить
	{&R0EE03LZ1,1,3},	//( - , SBz1) Питание  АКНП3  отключить
	{&R0EE04LZ1,1,4},	//( - , SBz1) Питание  АКНП4  отключить
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
static char MBz1S_ip2[]={"\0"};
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
static ModbusRegister coil_SBz1DU[]={
	{&R0AD21LDU,1,0},	//( - , SBz1DU) Подключить защиту от II УР
	{&R0VW23LDU,1,1},	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,2},	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{&R0EE02LDU,1,3},	//( - , Baz1, SBz1DU) Питание  АКНП  отключить
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
	{&ttlfa1,8,4},	//( - , AKNP1, A1Bz1, A1Bz2) ttlf float
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
	{1,5003,&coil_MBz1S[0],&di_MBz1S[0],&ir_MBz1S[0],&hr_MBz1S[0],NULL,MBz1S_ip1,MBz1S_ip2,100},	//Мастер Баз1 в SCM
	{0,5005,&coil_DiagnBaz1[0],&di_DiagnBaz1[0],&ir_DiagnBaz1[0],&hr_DiagnBaz1[0],NULL,NULL,NULL,0},	//Диагностика Baz1
	{0,5010,&coil_SBz1DU[0],&di_SBz1DU[0],&ir_SBz1DU[0],&hr_SBz1DU[0],NULL,NULL,NULL,0},	//Слэйв для DU
	{1,5015,&coil_MBz1A1[0],&di_MBz1A1[0],&ir_MBz1A1[0],&hr_MBz1A1[0],NULL,MBz1A1_ip1,MBz1A1_ip2,20},	//Мастер Баз1 в AKNP1
	{1,5016,&coil_MBz1A2[0],&di_MBz1A2[0],&ir_MBz1A2[0],&hr_MBz1A2[0],NULL,MBz1A2_ip1,MBz1A2_ip2,20},	//Мастер Баз1 в AKNP2
	{1,5017,&coil_MBz1A3[0],&di_MBz1A3[0],&ir_MBz1A3[0],&hr_MBz1A3[0],NULL,MBz1A3_ip1,MBz1A3_ip2,20},	//Мастер Баз1 в AKNP3
	{1,5018,&coil_MBz1A4[0],&di_MBz1A4[0],&ir_MBz1A4[0],&hr_MBz1A4[0],NULL,MBz1A4_ip1,MBz1A4_ip2,20},	//Мастер Баз1 в AKNP4
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
	{&A3VZ13LZ1,1,0},
	{&A3VZ15LZ1,1,2},
	{&R0AD14LZ1,1,4},
	{&A1VN71LZ1,1,6},
	{&R0VZ71LZ1,1,30},
	{&R0DE0ALZ1,3,38},
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
	{&R0DEB1LZ1,1,18},
	{&R0DEB2LZ1,1,20},
	{&R0DEB3LZ1,1,22},
	{&R0DEB4LZ1,1,24},
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
	{&A0IT01IZ1,3,0},
	{&A2IP01IZ1,3,3},
	{&B0IT01IZ1,3,6},
	{&B2IP01IZ1,3,9},
	{&R0DE04LZ1,3,26},
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
	{&R0VN71LZ1,1,0},
	{&R0VN75LZ1,1,2},
	{&A0EE01LS1,1,4},
	{&A0VN71LS1,1,6},
	{&A3IS11LDU,1,8},
	{&A3IS22LDU,1,10},
	{&R0AD03LZ1,1,12},
	{&R0AD04LZ1,1,14},
	{&R0AD05LZ1,1,16},
	{&A2IS12LDU,1,18},
	{&B2IS12LDU,1,20},
	{&R0DE05LZ1,3,64},
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
	{&R0VN72LZ1,1,0},
	{&R0VN76LZ1,1,2},
	{&A0EE01LS2,1,4},
	{&A0VN71LS2,1,6},
	{&B3IS11LDU,1,8},
	{&B3IS22LDU,1,10},
	{&R7II71LZ1,1,12},
	{&R7II74LZ1,1,14},
	{&R0DE06LZ1,3,64},
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
	{&R0VN74LZ1,1,0},
	{&R0VN78LZ1,1,2},
	{&A0EE01LS4,1,4},
	{&A0VN71LS4,1,6},
	{&R6IS66LZ1,1,8},
	{&R7II72LZ1,1,10},
	{&R7II75LZ1,1,12},
	{&R0DE07LZ1,3,64},
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
	{&R0VN73LZ1,1,0},
	{&R0VN77LZ1,1,2},
	{&A0EE01LS3,1,4},
	{&A0VN71LS3,1,6},
	{&R7II73LZ1,1,8},
	{&R7II76LZ1,1,10},
	{&R0S01LZ1,1,14},
	{&A0VP81LZZ,1,16},
	{&A1VP81LZZ,1,18},
	{&B0VP81LZZ,1,22},
	{&B1VP81LZZ,1,24},
	{&R0DE08LZ1,3,64},
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
	setAsFloat(162,0.6);
	setAsFloat(163,0);
	setAsFloat(164,0.1);
	setAsFloat(165,0.13);
	setAsFloat(166,0.16);
	setAsFloat(167,0.19);
	setAsFloat(168,0.17);
	setAsFloat(169,0.2);
	setAsFloat(170,0.28);
	setAsFloat(171,0.31);
	setAsFloat(172,0.190);
	setAsFloat(173,0.150);
	setAsFloat(174,0.170);
	setAsFloat(175,15);
	setAsFloat(176,10);
	setAsFloat(177,0);
	setAsFloat(178,600);
	setAsFloat(179,100);
	setAsFloat(180,90);
	setAsFloat(181,200);
	setAsFloat(182,150);
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
ssfloat fRM_0_3 = {0.3,0}; /* tz - время задержки сек */ 


/* Определение переменных */
sschar var130;
sschar var132;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psint  array_m309_x_1[6] = {&R0DE04LZ1,&R0DE05LZ1,&R0DE06LZ1,&R0DE0ALZ1,&R0DE08LZ1,&R0DE07LZ1};
psfloat  array_m190_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psfloat  array_m293_x_1[4] = {&R0VN02RS1,&R0VN02RS2,&R0VN02RS3,&R0VN02RS4};
psbool  array_m293_diag_1[4] = {&var29,&var30,&var31,&var32};
psbool  array_m284_x_1[16] = {&var77,&var43,&var44,&var72,&var12,&var9,&var129,&var42,&var41,&var40,&var73,&var13,&var10,&var131,&var38,&var35};
psbool  array_m16_x_1[6] = {&var82,&var73,&var13,&var10,&var88,&var131};
psbool  array_m37_x_1[6] = {&var72,&var12,&var9,&var129,&var80,&var88};
psfloat  array_m2_x_1[4] = {&R0VN01RS1,&R0VN01RS2,&R0VN01RS3,&R0VN01RS4};
psbool  array_m2_diag_1[4] = {&var29,&var30,&var31,&var32};
psbool  array_m3_x_1[3] = {&var91,&var111,&var27};
psbool  array_m12_x_1[3] = {&var90,&var28,&var92};

/* Объявление структур */
_S_noto  S_noto_26_1 = {&var79,&var1};
_S_schl24  S_schl24_225_1 = {&R7II74LZ1,&R7II75LZ1,&R7II76LZ1,&lRM_0_,&var2};
_S_schl24  S_schl24_198_1 = {&R7II71LZ1,&R7II73LZ1,&R7II72LZ1,&lRM_0_,&var3};
_S_or2  S_or2_230_1 = {&var38,&var35,&var4};
_S_or2  S_or2_280_1 = {&R0MD34LP1,&var15,&var5};
_S_zzfs  S_zzfs_211_1 = {&R0AD04LZ1,&fRM_0_3,&var6,&internal1_m211_tx,&internal1_m211_y0};
_S_noto  S_noto_219_1 = {&var6,&var7};
_S_and2  S_and2_229_1 = {&var7,&var4,&var8};
_S_inicn  S_inicn_208_1 = {&A3IS11LDU,&B3IS11LDU,&R0AD03LZ1,&A3IS22LDU,&B3IS22LDU,&R0AD05LZ1,&var38,&var37,&var6,&fEM_R0UL25RDU,&fEM_R0UL05RDU,&fEM_R0UL07RDU,&var9,&var10,&var11,&var12,&var13,&var14,&var15,&internal1_m208_TVuIs1,&internal1_m208_TVuIs2,&internal1_m208_TImVuIs,&internal1_m208_TNupIs1,&internal1_m208_TNupIs2,&internal1_m208_TImNupIs,&internal1_m208_TImAZ2UR,&internal1_m208_fef};
_S_zzfs  S_zzfs_110_1 = {&B1VP81LZZ,&fRM_10000_,&var16,&internal1_m110_tx,&internal1_m110_y0};
_S_zzfs  S_zzfs_108_1 = {&A1VP81LZZ,&fRM_10000_,&var17,&internal1_m108_tx,&internal1_m108_y0};
_S_zzfs  S_zzfs_136_1 = {&B0VP81LZZ,&fRM_10000_,&var18,&internal1_m136_tx,&internal1_m136_y0};
_S_zzfs  S_zzfs_135_1 = {&A0VP81LZZ,&fRM_10000_,&var19,&internal1_m135_tx,&internal1_m135_y0};
_S_or3  S_or3_317_1 = {&var23,&var22,&var21,&var20};
_S_or2  S_or2_319_1 = {&R0DEB3LZ1,&R0DEB4LZ1,&var21};
_S_or2  S_or2_313_1 = {&R0DEB1LZ1,&R0DEB2LZ1,&var22};
_S_diagndev  S_diagndev_309_1 = {array_m309_x_1,&iRM_6_,&var23,&var24,&vainSFloat};
_S_ma  S_ma_190_1 = {array_m190_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_and2  S_and2_128_1 = {&var134,&var110,&var25};
_S_and2  S_and2_139_1 = {&var133,&var109,&var26};
_S_or2  S_or2_104_1 = {&var140,&var138,&var27};
_S_or2  S_or2_111_1 = {&var135,&var136,&var28};
_S_and2  S_and2_82_1 = {&lRM_1_,&A0EE01LS1,&var29};
_S_and2  S_and2_84_1 = {&lRM_1_,&A0EE01LS2,&var30};
_S_and2  S_and2_86_1 = {&lRM_1_,&A0EE01LS3,&var31};
_S_and2  S_and2_88_1 = {&lRM_1_,&A0EE01LS4,&var32};
_S_and2  S_and2_184_1 = {&var126,&var98,&var33};
_S_and2  S_and2_185_1 = {&var125,&var98,&var34};
_S_or2  S_or2_227_1 = {&var2,&var89,&var35};
_S_or2  S_or2_216_1 = {&R0AD21LDU,&var6,&var36};
_S_and2  S_and2_215_1 = {&var35,&var36,&var37};
_S_or2  S_or2_206_1 = {&var89,&var3,&var38};
_S_schl24  S_schl24_299_1 = {&A0VN71LS2,&A0VN71LS1,&A0VN71LS4,&A0VN71LS3,&var39};
_S_and2  S_and2_286_1 = {&var56,&var78,&var40};
_S_and2  S_and2_288_1 = {&var63,&var78,&var41};
_S_and2  S_and2_289_1 = {&var99,&var78,&var42};
_S_and2  S_and2_287_1 = {&var67,&var78,&var43};
_S_and2  S_and2_285_1 = {&var49,&var78,&var44};
_S_and2  S_and2_269_1 = {&var47,&var46,&var45};
_S_or2  S_or2_271_1 = {&R0VN75LZ1,&var123,&var46};
_S_or2  S_or2_272_1 = {&R0VN77LZ1,&var122,&var47};
_S_or2  S_or2_257_1 = {&var45,&var53,&var48};
_S_or2  S_or2_263_1 = {&var50,&var45,&var49};
_S_and2  S_and2_264_1 = {&var118,&var54,&var50};
_S_or2  S_or2_274_1 = {&R0VN78LZ1,&var120,&var51};
_S_or2  S_or2_273_1 = {&R0VN76LZ1,&var121,&var52};
_S_and2  S_and2_270_1 = {&var52,&var51,&var53};
_S_schl24  S_schl24_268_1 = {&var52,&var51,&var47,&var46,&var54};
_S_and2  S_and2_266_1 = {&var78,&var54,&var55};
_S_or2  S_or2_265_1 = {&var53,&var50,&var56};
_S_and2  S_and2_261_1 = {&var56,&var78,&var57};
_S_or2  S_or2_237_1 = {&R0VN72LZ1,&var121,&var58};
_S_and2  S_and2_252_1 = {&var67,&var78,&var59};
_S_and2  S_and2_240_1 = {&var58,&var61,&var60};
_S_or2  S_or2_238_1 = {&R0VN74LZ1,&var120,&var61};
_S_and2  S_and2_253_1 = {&var63,&var78,&var62};
_S_or2  S_or2_250_1 = {&var60,&var66,&var63};
_S_or2  S_or2_256_1 = {&var68,&var60,&var64};
_S_and2  S_and2_244_1 = {&var70,&var78,&var65};
_S_and2  S_and2_249_1 = {&var119,&var70,&var66};
_S_or2  S_or2_248_1 = {&var68,&var66,&var67};
_S_and2  S_and2_239_1 = {&var69,&var71,&var68};
_S_or2  S_or2_236_1 = {&R0VN73LZ1,&var122,&var69};
_S_schl24  S_schl24_242_1 = {&var69,&var71,&var58,&var61,&var70};
_S_or2  S_or2_235_1 = {&R0VN71LZ1,&var123,&var71};
_S_or2  S_or2_156_1 = {&var103,&var141,&var72};
_S_or2  S_or2_158_1 = {&var108,&var106,&var73};
_S_or2  S_or2_297_1 = {&var139,&var137,&var74};
_S_or2  S_or2_36_1 = {&B2IS12LDU,&A2IS12LDU,&var75};
_S_and2  S_and2_260_1 = {&var78,&var49,&var76};
_S_and2  S_and2_290_1 = {&var100,&var78,&var77};
_S_and2  S_and2_21_1 = {&var97,&var93,&var78};
_S_or2  S_or2_25_1 = {&var116,&var115,&var79};
_S_and2  S_and2_32_1 = {&var81,&var78,&var80};
_S_or3  S_or3_31_1 = {&var49,&var67,&var96,&var81};
_S_and2  S_and2_19_1 = {&var78,&var83,&var82};
_S_or3  S_or3_18_1 = {&var63,&var56,&var95,&var83};
_S_and2  S_and2_6_1 = {&var30,&var32,&var84};
_S_or2  S_or2_9_1 = {&var117,&var84,&var85};
_S_or2  S_or2_8_1 = {&var87,&var117,&var86};
_S_and2  S_and2_5_1 = {&var29,&var31,&var87};
_S_zpfs  S_zpfs_228_1 = {&var8,&fEM_R0UL07RDU,&var88,&internal1_m228_tx,&internal1_m228_y0};
_S_noto  S_noto_207_1 = {&R6IS66LZ1,&var89};
_S_noto  S_noto_138_1 = {&var18,&var90};
_S_noto  S_noto_137_1 = {&var19,&var91};
_S_noto  S_noto_113_1 = {&var16,&var92};
_S_noto  S_noto_28_1 = {&var94,&var93};
_S_ovb1  S_ovb1_34_1 = {&var75,&iRM_200_,&var94,&internal1_m34_tx};
_S_noto  S_noto_13_1 = {&var85,&var95};
_S_noto  S_noto_15_1 = {&var86,&var96};
_S_noto  S_noto_24_1 = {&R0EE02LDU,&var97};
_S_bol  S_bol_180_1 = {&var127,&fRM_0_00001,&var98};
_S_noto  S_noto_291_1 = {&var85,&var99};
_S_noto  S_noto_292_1 = {&var86,&var100};
_S_scalzz  S_scalzz_149_1 = {&B0IT01IZ1,&iRM_3200_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var101,&internal1_m149_y0};
_S_scalzz  S_scalzz_147_1 = {&A0IT01IZ1,&iRM_3200_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var102,&internal1_m147_y0};
_S_geterr  S_geterr_151_1 = {&var102,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var103};
_S_scalzz  S_scalzz_93_1 = {&B2IP01IZ1,&iRM_3200_,&iRM_16000_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var104,&internal1_m93_y0};
_S_scalzz  S_scalzz_91_1 = {&A2IP01IZ1,&iRM_3200_,&iRM_16000_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var105,&internal1_m91_y0};
_S_drg  S_drg_160_1 = {&var101,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var106,&internal1_m160_y1};
_S_drg  S_drg_171_1 = {&var101,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var107,&internal1_m171_y1};
_S_geterr  S_geterr_153_1 = {&var101,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var108};
_S_noto  S_noto_140_1 = {&var135,&var109};
_S_noto  S_noto_127_1 = {&var140,&var110};
_S_noto  S_noto_112_1 = {&var17,&var111};
_S_srm  S_srm_293_1 = {array_m293_x_1,array_m293_diag_1,&iRM_4_,&iRM_3_,&var112,&vainSBool};
_S_rsu  S_rsu_283_1 = {&var5,&var114,&var113,&internal1_m283_q0};
_S_orni  S_orni_284_1 = {array_m284_x_1,&iRM_16_,&vainSBool,&var114};
_S_orn  S_orn_16_1 = {array_m16_x_1,&iRM_6_,&var115};
_S_orn  S_orn_37_1 = {array_m37_x_1,&iRM_6_,&var116};
_S_noto  S_noto_7_1 = {&var128,&var117};
_S_noto  S_noto_259_1 = {&var48,&var118};
_S_noto  S_noto_254_1 = {&var64,&var119};
_S_noto  S_noto_243_1 = {&A0EE01LS4,&var120};
_S_noto  S_noto_247_1 = {&A0EE01LS2,&var121};
_S_noto  S_noto_246_1 = {&A0EE01LS3,&var122};
_S_noto  S_noto_241_1 = {&A0EE01LS1,&var123};
_S_react  S_react_176_1 = {&var127,&var124};
_S_bol  S_bol_181_1 = {&fEM_R0UR04RZZ,&var127,&var125};
_S_bol  S_bol_179_1 = {&fEM_R0UR01RZZ,&var127,&var126};
_S_srm  S_srm_2_1 = {array_m2_x_1,array_m2_diag_1,&iRM_4_,&iRM_3_,&var127,&var128};
_S_ornc  S_ornc_3_1 = {array_m3_x_1,&iRM_3_,&var129,&var130};
_S_ornc  S_ornc_12_1 = {array_m12_x_1,&iRM_3_,&var131,&var132};
_S_tprg  S_tprg_129_1 = {&var104,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var133,&internal1_m129_y0};
_S_tprg  S_tprg_125_1 = {&var105,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var134,&internal1_m125_y0};
_S_geterr  S_geterr_102_1 = {&var104,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var135};
_S_drg  S_drg_107_1 = {&var104,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var136,&internal1_m107_y1};
_S_drg  S_drg_118_1 = {&var104,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var137,&internal1_m118_y1};
_S_drg  S_drg_95_1 = {&var105,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var138,&internal1_m95_y1};
_S_drg  S_drg_105_1 = {&var105,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var139,&internal1_m105_y1};
_S_geterr  S_geterr_99_1 = {&var105,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var140};
_S_drg  S_drg_157_1 = {&var102,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var141,&internal1_m157_y1};
_S_drg  S_drg_168_1 = {&var102,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var142,&internal1_m168_y1};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  noto(&S_noto_241_1);
  noto(&S_noto_246_1);
  noto(&S_noto_247_1);
  noto(&S_noto_243_1);
  scalzz(&S_scalzz_91_1);
  scalzz(&S_scalzz_93_1);
  scalzz(&S_scalzz_147_1);
  scalzz(&S_scalzz_149_1);
  noto(&S_noto_24_1);
  noto(&S_noto_207_1);
  or2(&S_or2_235_1);
  or2(&S_or2_236_1);
  and2(&S_and2_239_1);
  or2(&S_or2_238_1);
  or2(&S_or2_237_1);
  or2(&S_or2_273_1);
  or2(&S_or2_274_1);
  or2(&S_or2_272_1);
  or2(&S_or2_271_1);
  and2(&S_and2_269_1);
  schl24(&S_schl24_299_1);
  ma(&S_ma_190_1);
  or2(&S_or2_313_1);
  or2(&S_or2_319_1);
  zzfs(&S_zzfs_135_1);
  zzfs(&S_zzfs_136_1);
  zzfs(&S_zzfs_108_1);
  zzfs(&S_zzfs_110_1);
  zzfs(&S_zzfs_211_1);
  schl24(&S_schl24_198_1);
  schl24(&S_schl24_225_1);
  drg(&S_drg_168_1);
  drg(&S_drg_157_1);
  geterr(&S_geterr_99_1);
  drg(&S_drg_105_1);
  drg(&S_drg_95_1);
  drg(&S_drg_118_1);
  drg(&S_drg_107_1);
  geterr(&S_geterr_102_1);
  tprg(&S_tprg_125_1);
  tprg(&S_tprg_129_1);
  noto(&S_noto_112_1);
  noto(&S_noto_127_1);
  noto(&S_noto_140_1);
  geterr(&S_geterr_153_1);
  drg(&S_drg_171_1);
  drg(&S_drg_160_1);
  geterr(&S_geterr_151_1);
  noto(&S_noto_113_1);
  noto(&S_noto_137_1);
  noto(&S_noto_138_1);
  or2(&S_or2_36_1);
  or2(&S_or2_297_1);
  or2(&S_or2_158_1);
  or2(&S_or2_156_1);
  schl24(&S_schl24_242_1);
  and2(&S_and2_240_1);
  schl24(&S_schl24_268_1);
  and2(&S_and2_270_1);
  or2(&S_or2_257_1);
  or2(&S_or2_206_1);
  or2(&S_or2_216_1);
  or2(&S_or2_227_1);
  and2(&S_and2_88_1);
  and2(&S_and2_86_1);
  and2(&S_and2_84_1);
  and2(&S_and2_82_1);
  or2(&S_or2_111_1);
  or2(&S_or2_104_1);
  and2(&S_and2_139_1);
  and2(&S_and2_128_1);
  diagndev(&S_diagndev_309_1);
  or3(&S_or3_317_1);
  noto(&S_noto_219_1);
  or2(&S_or2_230_1);
  ornc(&S_ornc_12_1);
  ornc(&S_ornc_3_1);
  srm(&S_srm_2_1);
  bol(&S_bol_179_1);
  bol(&S_bol_181_1);
  react(&S_react_176_1);
  noto(&S_noto_259_1);
  noto(&S_noto_7_1);
  srm(&S_srm_293_1);
  bol(&S_bol_180_1);
  ovb1(&S_ovb1_34_1);
  noto(&S_noto_28_1);
  and2(&S_and2_5_1);
  or2(&S_or2_8_1);
  and2(&S_and2_6_1);
  and2(&S_and2_21_1);
  and2(&S_and2_244_1);
  or2(&S_or2_256_1);
  and2(&S_and2_266_1);
  and2(&S_and2_264_1);
  or2(&S_or2_263_1);
  and2(&S_and2_285_1);
  and2(&S_and2_215_1);
  and2(&S_and2_185_1);
  and2(&S_and2_184_1);
  inicn(&S_inicn_208_1);
  and2(&S_and2_229_1);
  or2(&S_or2_280_1);
  noto(&S_noto_254_1);
  noto(&S_noto_292_1);
  noto(&S_noto_15_1);
  zpfs(&S_zpfs_228_1);
  or2(&S_or2_9_1);
  and2(&S_and2_290_1);
  and2(&S_and2_260_1);
  and2(&S_and2_249_1);
  or2(&S_or2_250_1);
  and2(&S_and2_253_1);
  or2(&S_or2_265_1);
  and2(&S_and2_288_1);
  and2(&S_and2_286_1);
  noto(&S_noto_291_1);
  noto(&S_noto_13_1);
  or3(&S_or3_18_1);
  and2(&S_and2_19_1);
  or2(&S_or2_248_1);
  and2(&S_and2_252_1);
  and2(&S_and2_261_1);
  and2(&S_and2_287_1);
  and2(&S_and2_289_1);
  orn(&S_orn_16_1);
  orni(&S_orni_284_1);
  rsu(&S_rsu_283_1);
  or3(&S_or3_31_1);
  and2(&S_and2_32_1);
  orn(&S_orn_37_1);
  or2(&S_or2_25_1);
  noto(&S_noto_26_1);
  setData(idR7II82LZ1,&var2);
  setData(idR7II81LZ1,&var3);
  setData(idR0VZ05U,&var114);
  setData(idTestDiagnBaz1,&var20);
  setData(idR0DE3DLZ1,&var21);
  setData(idR0DE3CLZ1,&var22);
  setData(idTTLBaz1,&var24);
  moveData(idR0EE04LZ1,idR0EE02LDU);
  moveData(idR0EE03LZ1,idR0EE02LDU);
  moveData(idR0EE02LZ1,idR0EE02LDU);
  moveData(idR0EE01LZ1,idR0EE02LDU);
  setData(idR0AD14LZ1,&var15);
  setData(idA3VZ13LZ1,&var11);
  setData(idA3VZ15LZ1,&var14);
  setData(idA1VN71LZ1,&var39);
  setData(idB0VT71LZ1,&var73);
  setData(idB0VT61LZ1,&var107);
  setData(idB0CT01IZ1,&var101);
  setData(idR0VP73LZ1,&var74);
  setData(idR0VN11RZ1,&var112);
  setData(idR0VZ05UZ1,&var113);
  setData(idB0VN81LZ1,&var57);
  setData(idA0VN81LZ1,&var76);
  setData(idB0VN71LZ1,&var62);
  setData(idA0VN71LZ1,&var59);
  setData(idB0VZ71LZ1,&var115);
  setData(idB0EE00LZ1,&var85);
  setData(idA0EE00LZ1,&var86);
  setData(idA0VZ71LZ1,&var116);
  setData(idA0EE03LZ1,&var31);
  setData(idA0EE02LZ1,&var30);
  setData(idA0EE04LZ1,&var32);
  setData(idA0EE01LZ1,&var29);
  setData(idR0VN80LZ1,&var55);
  setData(idR0VN70LZ1,&var65);
  setData(idR0VZ71LZ1,&var1);
  setData(idR0VR02RZ1,&var124);
  setData(idR0VN79LZ1,&var34);
  setData(idR0VN69LZ1,&var33);
  setData(idB3VZ11LZ1,&var13);
  setData(idA3VZ11LZ1,&var12);
  setData(idB3VZ31LZ1,&var10);
  setData(idA3VZ31LZ1,&var9);
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
  setData(idA2VP81LZ1,&var25);
  setData(idB2VP81LZ1,&var26);
  setData(idB2VP51LZ1,&var137);
  setData(idB2CP01RZ1,&var104);
  setData(idB2VP41LZ1,&var28);
  setData(idA2VP51LZ1,&var139);
  setData(idA2CP01RZ1,&var105);
  setData(idA2VP41LZ1,&var27);
  setData(idB1VP41LZ1,&var92);
  setData(idA1VP41LZ1,&var111);
  setData(idA0VT71LZ1,&var72);
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