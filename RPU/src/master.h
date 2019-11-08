#ifndef RPU_H
#define RPU_H
// Подсистема  RPU:RPU
static char SimulOn=0;
static short CodeSub=8;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 //Время цикла мс
float takt,taktScheme=0,taktSS=0;
#define SIZE_BUFFER 891
static char BUFFER[SIZE_BUFFER];
#include <fp8/UDPTransport.h>
SetupUDP setUDP ={"192.168.10.31\0",5432,"192.168.10.131\0",5432,BUFFER,sizeof(BUFFER),};
int master=1,nomer=1;
#define A0CT01IRP	BUFFER[0]	// ( - , RPU) Температура АЗ1-3
#define idA0CT01IRP	1	// ( - , RPU) Температура АЗ1-3
#define A0EE01LRP	BUFFER[5]	// ( - , RPU) Исправность АКНП канал 5
#define idA0EE01LRP	2	// ( - , RPU) Исправность АКНП канал 5
#define A0EE02LRP	BUFFER[7]	// ( - , RPU) Исправность АКНП5 (от сшивки каналов) канал 5
#define idA0EE02LRP	3	// ( - , RPU) Исправность АКНП5 (от сшивки каналов) канал 5
#define A0IT03IRP	BUFFER[9]	// (vas84:06 - K01VASR, RPU) Температура АЗ1-3
#define idA0IT03IRP	4	// (vas84:06 - K01VASR, RPU) Температура АЗ1-3
#define A0VT61LRP	BUFFER[12]	// ( - , RPU) ПС по температуре в АЗ1
#define idA0VT61LRP	5	// ( - , RPU) ПС по температуре в АЗ1
#define A0VT71LRP	BUFFER[14]	// ( - , RPU) АС по температуре в АЗ1
#define idA0VT71LRP	6	// ( - , RPU) АС по температуре в АЗ1
#define A1IS21LRP	BUFFER[16]	// (vds32:07 - K09VDSR, - ) Приход на НУ ББ1
#define idA1IS21LRP	7	// (vds32:07 - K09VDSR, - ) Приход на НУ ББ1
#define A1VS21LRP	BUFFER[18]	// (fds16:08 - K01FDSR, - ) Индикация - Приход на НУ ББ1
#define idA1VS21LRP	8	// (fds16:08 - K01FDSR, - ) Индикация - Приход на НУ ББ1
#define A1VT71LRP	BUFFER[20]	// (fds16:08 - K11FDSR, - ) АС по температуре
#define idA1VT71LRP	9	// (fds16:08 - K11FDSR, - ) АС по температуре
#define A2IS21LRP	BUFFER[22]	// (vds32:07 - K10VDSR, - ) Приход на НУ РБ1-CC
#define idA2IS21LRP	10	// (vds32:07 - K10VDSR, - ) Приход на НУ РБ1-CC
#define A2VS21LRP	BUFFER[24]	// (fds16:08 - K03FDSR, - ) Индикация - Приход на НУ РБ1-CC
#define idA2VS21LRP	11	// (fds16:08 - K03FDSR, - ) Индикация - Приход на НУ РБ1-CC
#define A3IS21LRP	BUFFER[26]	// (vds32:07 - K08VDSR, - ) Приход на НУ ИС1
#define idA3IS21LRP	12	// (vds32:07 - K08VDSR, - ) Приход на НУ ИС1
#define A3VS21LRP	BUFFER[28]	// (fds16:08 - K05FDSR, - ) Индикация - Приход на НУ ИС1
#define idA3VS21LRP	13	// (fds16:08 - K05FDSR, - ) Индикация - Приход на НУ ИС1
#define A6IS11LRP	BUFFER[30]	// (vds32:07 - K14VDSR, - ) Приход на ВУ БЗ1
#define idA6IS11LRP	14	// (vds32:07 - K14VDSR, - ) Приход на ВУ БЗ1
#define A7MZ31LRP	BUFFER[32]	// ( - , RPU) Клапан ОБДУВ АЗ1 открыть(обесточить)
#define idA7MZ31LRP	15	// ( - , RPU) Клапан ОБДУВ АЗ1 открыть(обесточить)
#define B0CT01IRP	BUFFER[34]	// ( - , RPU) Температура АЗ2-3
#define idB0CT01IRP	16	// ( - , RPU) Температура АЗ2-3
#define B0IT03IRP	BUFFER[39]	// (vas84:06 - K02VASR, RPU) Температура АЗ2-3
#define idB0IT03IRP	17	// (vas84:06 - K02VASR, RPU) Температура АЗ2-3
#define B0VT61LRP	BUFFER[42]	// ( - , RPU) ПС по температуре в АЗ2-3
#define idB0VT61LRP	18	// ( - , RPU) ПС по температуре в АЗ2-3
#define B0VT71LRP	BUFFER[44]	// ( - , RPU) АС по температуре в АЗ2-3
#define idB0VT71LRP	19	// ( - , RPU) АС по температуре в АЗ2-3
#define B1IS21LRP	BUFFER[46]	// (vds32:07 - K12VDSR, - ) Приход на НУ ББ2
#define idB1IS21LRP	20	// (vds32:07 - K12VDSR, - ) Приход на НУ ББ2
#define B1VS21LRP	BUFFER[48]	// (fds16:08 - K02FDSR, - ) Индикация - Приход на НУ ББ2
#define idB1VS21LRP	21	// (fds16:08 - K02FDSR, - ) Индикация - Приход на НУ ББ2
#define B2IS21LRP	BUFFER[50]	// (vds32:07 - K13VDSR, - ) Приход на НУ РБ2-CC
#define idB2IS21LRP	22	// (vds32:07 - K13VDSR, - ) Приход на НУ РБ2-CC
#define B2VS21LRP	BUFFER[52]	// (fds16:08 - K04FDSR, - ) Индикация - Приход на НУ РБ2-CC
#define idB2VS21LRP	23	// (fds16:08 - K04FDSR, - ) Индикация - Приход на НУ РБ2-CC
#define B3IS21LRP	BUFFER[54]	// (vds32:07 - K11VDSR, - ) Приход на НУ ИС2
#define idB3IS21LRP	24	// (vds32:07 - K11VDSR, - ) Приход на НУ ИС2
#define B3VS21LRP	BUFFER[56]	// (fds16:08 - K06FDSR, - ) Индикация - Приход на НУ ИС2
#define idB3VS21LRP	25	// (fds16:08 - K06FDSR, - ) Индикация - Приход на НУ ИС2
#define B6IS11LRP	BUFFER[58]	// (vds32:07 - K15VDSR, - ) Приход на ВУ БЗ2
#define idB6IS11LRP	26	// (vds32:07 - K15VDSR, - ) Приход на ВУ БЗ2
#define B7MZ31LRP	BUFFER[60]	// ( - , RPU) Клапан ОБДУВ АЗ2 открыть(обесточить)
#define idB7MZ31LRP	27	// ( - , RPU) Клапан ОБДУВ АЗ2 открыть(обесточить)
#define B8VC01RDU	BUFFER[62]	// ( - , RPU) Координата АЗ2, мм
#define idB8VC01RDU	28	// ( - , RPU) Координата АЗ2, мм
#define C1MD31LRP	BUFFER[67]	// (vds32:07 - K06VDSR, - ) Кнопка ОБЩИЙ СБРОС  на РПУ
#define idC1MD31LRP	29	// (vds32:07 - K06VDSR, - ) Кнопка ОБЩИЙ СБРОС  на РПУ
#define C1MZ31LRP	BUFFER[69]	// (vds32:07 - K07VDSR, - ) Кнопка ОБДУВ  на РПУ
#define idC1MZ31LRP	30	// (vds32:07 - K07VDSR, - ) Кнопка ОБДУВ  на РПУ
#define METRP06	BUFFER[71]	// ( - , RPU) Метр давление 0.6
#define idMETRP06	31	// ( - , RPU) Метр давление 0.6
#define METRP12	BUFFER[76]	// ( - , RPU) Метр давление 1.2
#define idMETRP12	32	// ( - , RPU) Метр давление 1.2
#define R0DE01LRP	BUFFER[81]	// (vchs:01 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 1
#define idR0DE01LRP	33	// (vchs:01 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 1
#define R0DE02LRP	BUFFER[84]	// (vchs:02 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 2
#define idR0DE02LRP	34	// (vchs:02 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 2
#define R0DE03LRP	BUFFER[87]	// (vchs:03 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 3
#define idR0DE03LRP	35	// (vchs:03 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 3
#define R0DE06LRP	BUFFER[90]	// (vas84:06 - Diagn, DiagnRPU) диагностика модуля РПУ-ВАС место 6
#define idR0DE06LRP	36	// (vas84:06 - Diagn, DiagnRPU) диагностика модуля РПУ-ВАС место 6
#define R0DE07LRP	BUFFER[93]	// (vds32:07 - Diagn, DiagnRPU) диагностика модуля РПУ-ВДС место 7
#define idR0DE07LRP	37	// (vds32:07 - Diagn, DiagnRPU) диагностика модуля РПУ-ВДС место 7
#define R0DE08LRP	BUFFER[96]	// (fds16:08 - Diagn, DiagnRPU) диагностика модуля РПУ-ФДС место 8
#define idR0DE08LRP	38	// (fds16:08 - Diagn, DiagnRPU) диагностика модуля РПУ-ФДС место 8
#define R0DE31LRP	BUFFER[99]	// (sbk:20 - S01SBK, DiagnRPU) диагностика шкафа РПУ сеть 1
#define idR0DE31LRP	39	// (sbk:20 - S01SBK, DiagnRPU) диагностика шкафа РПУ сеть 1
#define R0DE32LRP	BUFFER[101]	// (sbk:20 - S02SBK, DiagnRPU) диагностика шкафа РПУ сеть 2
#define idR0DE32LRP	40	// (sbk:20 - S02SBK, DiagnRPU) диагностика шкафа РПУ сеть 2
#define R0DE33LRP	BUFFER[103]	// (sbk:20 - S03SBK, DiagnRPU) диагностика шкафа РПУ двери
#define idR0DE33LRP	41	// (sbk:20 - S03SBK, DiagnRPU) диагностика шкафа РПУ двери
#define R0DE34LRP	BUFFER[105]	// (sbk:20 - S04SBK, DiagnRPU) диагностика шкафа РПУ температура меньше 43
#define idR0DE34LRP	42	// (sbk:20 - S04SBK, DiagnRPU) диагностика шкафа РПУ температура меньше 43
#define R0DE35LRP	BUFFER[107]	// (sbk:20 - S05SBK, DiagnRPU) диагностика шкафа РПУ температура больше 53
#define idR0DE35LRP	43	// (sbk:20 - S05SBK, DiagnRPU) диагностика шкафа РПУ температура больше 53
#define R0DE36LRP	BUFFER[109]	// (sbk:20 - S06SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 1
#define idR0DE36LRP	44	// (sbk:20 - S06SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 1
#define R0DE37LRP	BUFFER[111]	// (sbk:20 - S07SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 2
#define idR0DE37LRP	45	// (sbk:20 - S07SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 2
#define R0DE38LRP	BUFFER[113]	// (sbk:20 - S08SBK, DiagnRPU) диагностика шкафа РПУ МП15-3 место 3
#define idR0DE38LRP	46	// (sbk:20 - S08SBK, DiagnRPU) диагностика шкафа РПУ МП15-3 место 3
#define R0DE39LRP	BUFFER[115]	// (sbk:20 - S09SBK, DiagnRPU) диагностика шкафа РПУ МП24-2 место 4
#define idR0DE39LRP	47	// (sbk:20 - S09SBK, DiagnRPU) диагностика шкафа РПУ МП24-2 место 4
#define R0DE3CLRP	BUFFER[117]	// ( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 7
#define idR0DE3CLRP	48	// ( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 7
#define R0DE3DLRP	BUFFER[119]	// ( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 8
#define idR0DE3DLRP	49	// ( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 8
#define R0DEB1LRP	BUFFER[121]	// (sbk:20 - S10SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 7
#define idR0DEB1LRP	50	// (sbk:20 - S10SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 7
#define R0DEB2LRP	BUFFER[123]	// (sbk:20 - S11SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 7
#define idR0DEB2LRP	51	// (sbk:20 - S11SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 7
#define R0DEB3LRP	BUFFER[125]	// (sbk:20 - S12SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 8
#define idR0DEB3LRP	52	// (sbk:20 - S12SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 8
#define R0DEB4LRP	BUFFER[127]	// (sbk:20 - S13SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 8
#define idR0DEB4LRP	53	// (sbk:20 - S13SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 8
#define R0EE02LDU	BUFFER[129]	// ( - , RPU) Питание  АКНП  отключить
#define idR0EE02LDU	54	// ( - , RPU) Питание  АКНП  отключить
#define R0ET01LRP	BUFFER[131]	// ( - , RPU) Признак наличия неисправности по температуре  АЗ1-3
#define idR0ET01LRP	55	// ( - , RPU) Признак наличия неисправности по температуре  АЗ1-3
#define R0ET02LRP	BUFFER[133]	// ( - , RPU) Признак наличия неисправности по температуре АЗ2-3
#define idR0ET02LRP	56	// ( - , RPU) Признак наличия неисправности по температуре АЗ2-3
#define R0IE01LRP	BUFFER[135]	// (fds16:08 - K08FDSR, - ) Отключение питание детекторов канал 5
#define idR0IE01LRP	57	// (fds16:08 - K08FDSR, - ) Отключение питание детекторов канал 5
#define R0IE02LRP	BUFFER[137]	// (fds16:08 - K07FDSR, - ) Отключить питание ПР, ПУ канал 5
#define idR0IE02LRP	58	// (fds16:08 - K07FDSR, - ) Отключить питание ПР, ПУ канал 5
#define R0IE03LRP	BUFFER[139]	// (fds16:08 - K09FDSR, - ) Отключение питание детекторов канал  6,7
#define idR0IE03LRP	59	// (fds16:08 - K09FDSR, - ) Отключение питание детекторов канал  6,7
#define R0IE04LRP	BUFFER[141]	// (fds16:08 - K10FDSR, - ) Отключить питание ПР, ПУ канал 6,7
#define idR0IE04LRP	60	// (fds16:08 - K10FDSR, - ) Отключить питание ПР, ПУ канал 6,7
#define R0IE11LRP	BUFFER[143]	// (vds32:07 - K03VDSR, - ) Исправность ВИП 1,6 (№20) СНМ11 5 канала
#define idR0IE11LRP	61	// (vds32:07 - K03VDSR, - ) Исправность ВИП 1,6 (№20) СНМ11 5 канала
#define R0IE12LRP	BUFFER[145]	// (vds32:07 - K04VDSR, - ) Исправность ВИП 0,5 -5к (№21)
#define idR0IE12LRP	62	// (vds32:07 - K04VDSR, - ) Исправность ВИП 0,5 -5к (№21)
#define R0IE13LRP	BUFFER[147]	// (vds32:07 - K05VDSR, - ) Исправность ВИП 0,5 -5к (№22)
#define idR0IE13LRP	63	// (vds32:07 - K05VDSR, - ) Исправность ВИП 0,5 -5к (№22)
#define R0IE14LRP	BUFFER[149]	// (vds32:07 - K01VDSR, - ) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
#define idR0IE14LRP	64	// (vds32:07 - K01VDSR, - ) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
#define R0IE15LRP	BUFFER[151]	// (vds32:07 - K02VDSR, - ) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
#define idR0IE15LRP	65	// (vds32:07 - K02VDSR, - ) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
#define R0IN01RIP	BUFFER[153]	// ( - , MRPS) Частота СНМ-11 Гц (канал 5) от ПТИ
#define idR0IN01RIP	66	// ( - , MRPS) Частота СНМ-11 Гц (канал 5) от ПТИ
#define R0IN01RRP	BUFFER[158]	// ( - , RPU) Частота СНМ-11 Гц (канал 5)
#define idR0IN01RRP	67	// ( - , RPU) Частота СНМ-11 Гц (канал 5)
#define R0IN01VRP	BUFFER[163]	// (vchs:01 - K01VCHS, RPU) Частота с ВЧС к 1
#define idR0IN01VRP	68	// (vchs:01 - K01VCHS, RPU) Частота с ВЧС к 1
#define R0IN02RIP	BUFFER[168]	// ( - , MRPS) Частота КНК15-1 Гц (канал 5) от ПТИ
#define idR0IN02RIP	69	// ( - , MRPS) Частота КНК15-1 Гц (канал 5) от ПТИ
#define R0IN02RRP	BUFFER[173]	// ( - , RPU) Частота КНК15-1 Гц (канал 5)
#define idR0IN02RRP	70	// ( - , RPU) Частота КНК15-1 Гц (канал 5)
#define R0IN02VRP	BUFFER[178]	// (vchs:01 - K02VCHS, RPU) Частота с ВЧС к 2
#define idR0IN02VRP	71	// (vchs:01 - K02VCHS, RPU) Частота с ВЧС к 2
#define R0IN03RIP	BUFFER[183]	// ( - , MRPS) Частота КНК53М Гц (канал 5) от ПТИ
#define idR0IN03RIP	72	// ( - , MRPS) Частота КНК53М Гц (канал 5) от ПТИ
#define R0IN03RRP	BUFFER[188]	// ( - , RPU) Частота КНК53М Гц (канал 5)
#define idR0IN03RRP	73	// ( - , RPU) Частота КНК53М Гц (канал 5)
#define R0IN03VRP	BUFFER[193]	// (vchs:02 - K01VCHS, RPU) Частота с ВЧС к 3
#define idR0IN03VRP	74	// (vchs:02 - K01VCHS, RPU) Частота с ВЧС к 3
#define R0IN06RIP	BUFFER[198]	// ( - , MRPS) Частота СНМ-11 Гц (канал 6) от ПТИ
#define idR0IN06RIP	75	// ( - , MRPS) Частота СНМ-11 Гц (канал 6) от ПТИ
#define R0IN06RRP	BUFFER[203]	// ( - , RPU) Частота СНМ-11 Гц (канал 6) от ПТИ
#define idR0IN06RRP	76	// ( - , RPU) Частота СНМ-11 Гц (канал 6) от ПТИ
#define R0IN06VRP	BUFFER[208]	// (vchs:03 - K01VCHS, RPU) Частота с ВЧС к 6
#define idR0IN06VRP	77	// (vchs:03 - K01VCHS, RPU) Частота с ВЧС к 6
#define R0IN07RIP	BUFFER[213]	// ( - , MRPS) Частота СНМ-11 Гц (канал 7) от ПТИ
#define idR0IN07RIP	78	// ( - , MRPS) Частота СНМ-11 Гц (канал 7) от ПТИ
#define R0IN07RRP	BUFFER[218]	// ( - , RPU) Частота СНМ-11 Гц (канал 7)
#define idR0IN07RRP	79	// ( - , RPU) Частота СНМ-11 Гц (канал 7)
#define R0IN07VRP	BUFFER[223]	// (vchs:03 - K02VCHS, RPU) Частота с ВЧС к 7
#define idR0IN07VRP	80	// (vchs:03 - K02VCHS, RPU) Частота с ВЧС к 7
#define R0IS01FI0	BUFFER[228]	// ( - , MRPS) Признак работы с имитатором
#define idR0IS01FI0	81	// ( - , MRPS) Признак работы с имитатором
#define R0VN02RRP	BUFFER[230]	// ( - , RPU) Уровень мощности канал 5
#define idR0VN02RRP	82	// ( - , RPU) Уровень мощности канал 5
#define R0VN03RRP	BUFFER[235]	// ( - , RPU) Измеренный нейтронный поток канал 5
#define idR0VN03RRP	83	// ( - , RPU) Измеренный нейтронный поток канал 5
#define R0VN13RRP	BUFFER[240]	// ( - , RPU) Нейтронный поток по камере  СНМ-11 канал 5
#define idR0VN13RRP	84	// ( - , RPU) Нейтронный поток по камере  СНМ-11 канал 5
#define R0VN15RRP	BUFFER[245]	// ( - , RPU) Номер ведущей камеры канал 5
#define idR0VN15RRP	85	// ( - , RPU) Номер ведущей камеры канал 5
#define R0VN23RRP	BUFFER[248]	// ( - , RPU) Нейтронный поток по камере КНК15-1 канал 5
#define idR0VN23RRP	86	// ( - , RPU) Нейтронный поток по камере КНК15-1 канал 5
#define R0VN33RRP	BUFFER[253]	// ( - , RPU) Нейтронный поток по камере КНК53М канал 5
#define idR0VN33RRP	87	// ( - , RPU) Нейтронный поток по камере КНК53М канал 5
#define R0VN71LRP	BUFFER[258]	// (fds16:08 - K12FDSR, - ) АС по мощности канал 5
#define idR0VN71LRP	88	// (fds16:08 - K12FDSR, - ) АС по мощности канал 5
#define R7VE70LRP	BUFFER[260]	// ( - , RPU) Сигнал тревоги по неисправности РПУ на диспетчера
#define idR7VE70LRP	89	// ( - , RPU) Сигнал тревоги по неисправности РПУ на диспетчера
#define R7VN71LRP	BUFFER[262]	// ( - , RPU) Сигнал тревоги по уровню нейтронного потока на диспетчера
#define idR7VN71LRP	90	// ( - , RPU) Сигнал тревоги по уровню нейтронного потока на диспетчера
#define TTLrpu	BUFFER[264]	// ( - , RPU) ttl
#define idTTLrpu	91	// ( - , RPU) ttl
#define TestDiagnRPU	BUFFER[267]	// ( - , RPU) Неисправность от диагностики
#define idTestDiagnRPU	92	// ( - , RPU) Неисправность от диагностики
#define VMETRP06	BUFFER[269]	// (vas84:06 - K05VASR, RPU) вход Метр Давленение 0.6
#define idVMETRP06	93	// (vas84:06 - K05VASR, RPU) вход Метр Давленение 0.6
#define VMETRP12	BUFFER[272]	// (vas84:06 - K06VASR, RPU) вход Метр Давленение 1.2
#define idVMETRP12	94	// (vas84:06 - K06VASR, RPU) вход Метр Давленение 1.2
#define aaaa	BUFFER[275]	// ( - , - ) aaaa
#define idaaaa	95	// ( - , - ) aaaa
#define bFirstEnterFlag	BUFFER[280]	// (bFirstEnterFlag) 
#define idbFirstEnterFlag	96	// (bFirstEnterFlag) 
#define fEM_A0UX00RSS	BUFFER[282]	// (A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	97	// (A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX13RSS	BUFFER[287]	// (A0UX13RSS) Первый коэффициент калибровки камеры 13
#define idfEM_A0UX13RSS	98	// (A0UX13RSS) Первый коэффициент калибровки камеры 13
#define fEM_A0UX14RSS	BUFFER[292]	// (A0UX14RSS) Первый коэффициент калибровки камеры 14
#define idfEM_A0UX14RSS	99	// (A0UX14RSS) Первый коэффициент калибровки камеры 14
#define fEM_A0UX15RSS	BUFFER[297]	// (A0UX15RSS) Первый коэффициент калибровки камеры 15
#define idfEM_A0UX15RSS	100	// (A0UX15RSS) Первый коэффициент калибровки камеры 15
#define fEM_B0UX03RSS	BUFFER[302]	// (B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	101	// (B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	BUFFER[307]	// (B0UX04RSS) Второй коэффициент калибровки камеры4
#define idfEM_B0UX04RSS	102	// (B0UX04RSS) Второй коэффициент калибровки камеры4
#define fEM_B0UX05RSS	BUFFER[312]	// (B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	103	// (B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_R0IN11NRP	BUFFER[317]	// (R0IN11NRP) Коэффициент A (РПУ к 1)
#define idfEM_R0IN11NRP	104	// (R0IN11NRP) Коэффициент A (РПУ к 1)
#define fEM_R0IN12NRP	BUFFER[322]	// (R0IN12NRP) Коэффициент B (РПУ к 1)
#define idfEM_R0IN12NRP	105	// (R0IN12NRP) Коэффициент B (РПУ к 1)
#define fEM_R0IN21NRP	BUFFER[327]	// (R0IN21NRP) Коэффициент A (РПУ к 2)
#define idfEM_R0IN21NRP	106	// (R0IN21NRP) Коэффициент A (РПУ к 2)
#define fEM_R0IN22NRP	BUFFER[332]	// (R0IN22NRP) Коэффициент B (РПУ к 2)
#define idfEM_R0IN22NRP	107	// (R0IN22NRP) Коэффициент B (РПУ к 2)
#define fEM_R0IN31NRP	BUFFER[337]	// (R0IN31NRP) Коэффициент A (РПУ к 3)
#define idfEM_R0IN31NRP	108	// (R0IN31NRP) Коэффициент A (РПУ к 3)
#define fEM_R0IN32NRP	BUFFER[342]	// (R0IN32NRP) Коэффициент B (РПУ к 3)
#define idfEM_R0IN32NRP	109	// (R0IN32NRP) Коэффициент B (РПУ к 3)
#define fEM_R0IN61NRP	BUFFER[347]	// (R0IN61NRP) Коэффициент A (РПУ к 6)
#define idfEM_R0IN61NRP	110	// (R0IN61NRP) Коэффициент A (РПУ к 6)
#define fEM_R0IN62NRP	BUFFER[352]	// (R0IN62NRP) Коэффициент B (РПУ к 6)
#define idfEM_R0IN62NRP	111	// (R0IN62NRP) Коэффициент B (РПУ к 6)
#define fEM_R0IN71NRP	BUFFER[357]	// (R0IN71NRP) Коэффициент A (РПУ к 7)
#define idfEM_R0IN71NRP	112	// (R0IN71NRP) Коэффициент A (РПУ к 7)
#define fEM_R0IN72NRP	BUFFER[362]	// (R0IN72NRP) Коэффициент B (РПУ к 7)
#define idfEM_R0IN72NRP	113	// (R0IN72NRP) Коэффициент B (РПУ к 7)
#define fEM_R0UH02RSS	BUFFER[367]	// (R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define idfEM_R0UH02RSS	114	// (R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define fEM_R0UH03RSS	BUFFER[372]	// (R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define idfEM_R0UH03RSS	115	// (R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define fEM_R0UH05RSS	BUFFER[377]	// (R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	116	// (R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UH21RSS	BUFFER[382]	// (R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	117	// (R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	BUFFER[387]	// (R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	118	// (R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	BUFFER[392]	// (R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	119	// (R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0UL52RSS	BUFFER[397]	// (R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	120	// (R0UL52RSS) Уровень АС по мощности
#define fEM_R0UR01RRP	BUFFER[402]	// (R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
#define idfEM_R0UR01RRP	121	// (R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
#define fEM_R0UT01RZZ	BUFFER[407]	// (R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	122	// (R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_R0UT02RZZ	BUFFER[412]	// (R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	123	// (R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT61RZZ	BUFFER[417]	// (R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	124	// (R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	BUFFER[422]	// (R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	125	// (R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	BUFFER[427]	// (R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	126	// (R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT72RZZ	BUFFER[432]	// (R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	127	// (R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define fEM_R7UX00RSS	BUFFER[437]	// (R7UX00RSS) X-координата АЗ1 (см)
#define idfEM_R7UX00RSS	128	// (R7UX00RSS) X-координата АЗ1 (см)
#define fEM_R7UX13RSS	BUFFER[442]	// (R7UX13RSS) X-координата камеры R7IN51
#define idfEM_R7UX13RSS	129	// (R7UX13RSS) X-координата камеры R7IN51
#define fEM_R7UX14RSS	BUFFER[447]	// (R7UX14RSS) X-координата камеры R7IN52
#define idfEM_R7UX14RSS	130	// (R7UX14RSS) X-координата камеры R7IN52
#define fEM_R7UX15RSS	BUFFER[452]	// (R7UX15RSS) X-координата камеры R7IN53
#define idfEM_R7UX15RSS	131	// (R7UX15RSS) X-координата камеры R7IN53
#define fEM_R7UY00RSS	BUFFER[457]	// (R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	132	// (R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UY13RSS	BUFFER[462]	// (R7UY13RSS) Y-координата камеры R7IN51
#define idfEM_R7UY13RSS	133	// (R7UY13RSS) Y-координата камеры R7IN51
#define fEM_R7UY14RSS	BUFFER[467]	// (R7UY14RSS) Y-координата камеры R7IN52
#define idfEM_R7UY14RSS	134	// (R7UY14RSS) Y-координата камеры R7IN52
#define fEM_R7UY15RSS	BUFFER[472]	// (R7UY15RSS) Y-координата камеры R7IN53
#define idfEM_R7UY15RSS	135	// (R7UY15RSS) Y-координата камеры R7IN53
#define fEM_R7UY22RSS	BUFFER[477]	// (R7UY22RSS) 2-й коэффициент ф-ции смещения
#define idfEM_R7UY22RSS	136	// (R7UY22RSS) 2-й коэффициент ф-ции смещения
#define fEM_R7UY32RSS	BUFFER[482]	// (R7UY32RSS) 1-й коэффициент ф-ции смещения
#define idfEM_R7UY32RSS	137	// (R7UY32RSS) 1-й коэффициент ф-ции смещения
#define fEM_R7UY42RSS	BUFFER[487]	// (R7UY42RSS) уровень корректировки
#define idfEM_R7UY42RSS	138	// (R7UY42RSS) уровень корректировки
#define fEM_Z7UE20RRP	BUFFER[492]	// (Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
#define idfEM_Z7UE20RRP	139	// (Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
#define iEM_R7UY12RSS	BUFFER[497]	// (R7UY12RSS) интервал усреднения
#define idiEM_R7UY12RSS	140	// (R7UY12RSS) интервал усреднения
#define internal1_m100_y1	BUFFER[500]	// (internal1_m100_y1) y1 - внутренний параметр
#define idinternal1_m100_y1	141	// (internal1_m100_y1) y1 - внутренний параметр
#define internal1_m112_y1	BUFFER[502]	// (internal1_m112_y1) y1 - внутренний параметр
#define idinternal1_m112_y1	142	// (internal1_m112_y1) y1 - внутренний параметр
#define internal1_m115_y1	BUFFER[504]	// (internal1_m115_y1) y1 - внутренний параметр
#define idinternal1_m115_y1	143	// (internal1_m115_y1) y1 - внутренний параметр
#define internal1_m183_SumS	BUFFER[506]	// (internal1_m183_SumS) внутренний параметр
#define idinternal1_m183_SumS	144	// (internal1_m183_SumS) внутренний параметр
#define internal1_m183_flst	BUFFER[511]	// (internal1_m183_flst) внутренний параметр
#define idinternal1_m183_flst	145	// (internal1_m183_flst) внутренний параметр
#define internal1_m183_stepc	BUFFER[516]	// (internal1_m183_stepc) stepc - счетчик шагов
#define idinternal1_m183_stepc	146	// (internal1_m183_stepc) stepc - счетчик шагов
#define internal1_m183_x0	BUFFER[519]	// (internal1_m183_x0) x0 - массив мгновенных значений 
#define idinternal1_m183_x0	147	// (internal1_m183_x0) x0 - массив мгновенных значений 
#define internal1_m183_xptr	BUFFER[569]	// (internal1_m183_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m183_xptr	148	// (internal1_m183_xptr) указатель текущей позиции в массиве координат
#define internal1_m184_SumS	BUFFER[572]	// (internal1_m184_SumS) внутренний параметр
#define idinternal1_m184_SumS	149	// (internal1_m184_SumS) внутренний параметр
#define internal1_m184_flst	BUFFER[577]	// (internal1_m184_flst) внутренний параметр
#define idinternal1_m184_flst	150	// (internal1_m184_flst) внутренний параметр
#define internal1_m184_stepc	BUFFER[582]	// (internal1_m184_stepc) stepc - счетчик шагов
#define idinternal1_m184_stepc	151	// (internal1_m184_stepc) stepc - счетчик шагов
#define internal1_m184_x0	BUFFER[585]	// (internal1_m184_x0) x0 - массив мгновенных значений 
#define idinternal1_m184_x0	152	// (internal1_m184_x0) x0 - массив мгновенных значений 
#define internal1_m184_xptr	BUFFER[635]	// (internal1_m184_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m184_xptr	153	// (internal1_m184_xptr) указатель текущей позиции в массиве координат
#define internal1_m18_Nk	BUFFER[638]	// (internal1_m18_Nk) Nk - ведущая камера
#define idinternal1_m18_Nk	154	// (internal1_m18_Nk) Nk - ведущая камера
#define internal1_m199_y0	BUFFER[641]	// (internal1_m199_y0) y0
#define idinternal1_m199_y0	155	// (internal1_m199_y0) y0
#define internal1_m200_y0	BUFFER[646]	// (internal1_m200_y0) y0
#define idinternal1_m200_y0	156	// (internal1_m200_y0) y0
#define internal1_m70_tx	BUFFER[651]	// (internal1_m70_tx) tx - время накопленное сек
#define idinternal1_m70_tx	157	// (internal1_m70_tx) tx - время накопленное сек
#define internal1_m70_y0	BUFFER[656]	// (internal1_m70_y0) y0
#define idinternal1_m70_y0	158	// (internal1_m70_y0) y0
#define internal1_m78_tx	BUFFER[658]	// (internal1_m78_tx) tx - время накопленное сек
#define idinternal1_m78_tx	159	// (internal1_m78_tx) tx - время накопленное сек
#define internal1_m78_y0	BUFFER[663]	// (internal1_m78_y0) y0
#define idinternal1_m78_y0	160	// (internal1_m78_y0) y0
#define internal1_m84_y0	BUFFER[665]	// (internal1_m84_y0) y0
#define idinternal1_m84_y0	161	// (internal1_m84_y0) y0
#define internal1_m86_y0	BUFFER[670]	// (internal1_m86_y0) y0
#define idinternal1_m86_y0	162	// (internal1_m86_y0) y0
#define internal1_m98_y1	BUFFER[675]	// (internal1_m98_y1) y1 - внутренний параметр
#define idinternal1_m98_y1	163	// (internal1_m98_y1) y1 - внутренний параметр
#define vainSBool	BUFFER[677]	// Внутренняя переменная vainSBool
#define idvainSBool	164	// Внутренняя переменная vainSBool
#define vainSFloat	BUFFER[679]	// Внутренняя переменная vainSFloat
#define idvainSFloat	165	// Внутренняя переменная vainSFloat
#define vainSInt	BUFFER[684]	// Внутренняя переменная vainSInt
#define idvainSInt	166	// Внутренняя переменная vainSInt
#define vainSLong	BUFFER[689]	// Внутренняя переменная vainSLong
#define idvainSLong	167	// Внутренняя переменная vainSLong
#define var1	BUFFER[698]	// Внутренняя переменная var1
#define idvar1	168	// Внутренняя переменная var1
#define var10	BUFFER[703]	// Внутренняя переменная var10
#define idvar10	169	// Внутренняя переменная var10
#define var11	BUFFER[708]	// Внутренняя переменная var11
#define idvar11	170	// Внутренняя переменная var11
#define var12	BUFFER[713]	// Внутренняя переменная var12
#define idvar12	171	// Внутренняя переменная var12
#define var13	BUFFER[718]	// Внутренняя переменная var13
#define idvar13	172	// Внутренняя переменная var13
#define var14	BUFFER[723]	// Внутренняя переменная var14
#define idvar14	173	// Внутренняя переменная var14
#define var15	BUFFER[728]	// Внутренняя переменная var15
#define idvar15	174	// Внутренняя переменная var15
#define var16	BUFFER[730]	// Внутренняя переменная var16
#define idvar16	175	// Внутренняя переменная var16
#define var17	BUFFER[732]	// Внутренняя переменная var17
#define idvar17	176	// Внутренняя переменная var17
#define var18	BUFFER[734]	// Внутренняя переменная var18
#define idvar18	177	// Внутренняя переменная var18
#define var19	BUFFER[736]	// Внутренняя переменная var19
#define idvar19	178	// Внутренняя переменная var19
#define var2	BUFFER[738]	// Внутренняя переменная var2
#define idvar2	179	// Внутренняя переменная var2
#define var20	BUFFER[743]	// Внутренняя переменная var20
#define idvar20	180	// Внутренняя переменная var20
#define var21	BUFFER[745]	// Внутренняя переменная var21
#define idvar21	181	// Внутренняя переменная var21
#define var22	BUFFER[747]	// Внутренняя переменная var22
#define idvar22	182	// Внутренняя переменная var22
#define var23	BUFFER[749]	// Внутренняя переменная var23
#define idvar23	183	// Внутренняя переменная var23
#define var24	BUFFER[751]	// Внутренняя переменная var24
#define idvar24	184	// Внутренняя переменная var24
#define var25	BUFFER[756]	// Внутренняя переменная var25
#define idvar25	185	// Внутренняя переменная var25
#define var26	BUFFER[761]	// Внутренняя переменная var26
#define idvar26	186	// Внутренняя переменная var26
#define var27	BUFFER[766]	// Внутренняя переменная var27
#define idvar27	187	// Внутренняя переменная var27
#define var28	BUFFER[768]	// Внутренняя переменная var28
#define idvar28	188	// Внутренняя переменная var28
#define var29	BUFFER[773]	// Внутренняя переменная var29
#define idvar29	189	// Внутренняя переменная var29
#define var3	BUFFER[778]	// Внутренняя переменная var3
#define idvar3	190	// Внутренняя переменная var3
#define var30	BUFFER[783]	// Внутренняя переменная var30
#define idvar30	191	// Внутренняя переменная var30
#define var31	BUFFER[788]	// Внутренняя переменная var31
#define idvar31	192	// Внутренняя переменная var31
#define var32	BUFFER[793]	// Внутренняя переменная var32
#define idvar32	193	// Внутренняя переменная var32
#define var33	BUFFER[795]	// Внутренняя переменная var33
#define idvar33	194	// Внутренняя переменная var33
#define var34	BUFFER[797]	// Внутренняя переменная var34
#define idvar34	195	// Внутренняя переменная var34
#define var35	BUFFER[799]	// Внутренняя переменная var35
#define idvar35	196	// Внутренняя переменная var35
#define var36	BUFFER[801]	// Внутренняя переменная var36
#define idvar36	197	// Внутренняя переменная var36
#define var37	BUFFER[803]	// Внутренняя переменная var37
#define idvar37	198	// Внутренняя переменная var37
#define var38	BUFFER[805]	// Внутренняя переменная var38
#define idvar38	199	// Внутренняя переменная var38
#define var39	BUFFER[807]	// Внутренняя переменная var39
#define idvar39	200	// Внутренняя переменная var39
#define var4	BUFFER[809]	// Внутренняя переменная var4
#define idvar4	201	// Внутренняя переменная var4
#define var40	BUFFER[814]	// Внутренняя переменная var40
#define idvar40	202	// Внутренняя переменная var40
#define var41	BUFFER[816]	// Внутренняя переменная var41
#define idvar41	203	// Внутренняя переменная var41
#define var43	BUFFER[818]	// Внутренняя переменная var43
#define idvar43	204	// Внутренняя переменная var43
#define var45	BUFFER[820]	// Внутренняя переменная var45
#define idvar45	205	// Внутренняя переменная var45
#define var46	BUFFER[822]	// Внутренняя переменная var46
#define idvar46	206	// Внутренняя переменная var46
#define var47	BUFFER[824]	// Внутренняя переменная var47
#define idvar47	207	// Внутренняя переменная var47
#define var48	BUFFER[826]	// Внутренняя переменная var48
#define idvar48	208	// Внутренняя переменная var48
#define var49	BUFFER[828]	// Внутренняя переменная var49
#define idvar49	209	// Внутренняя переменная var49
#define var5	BUFFER[830]	// Внутренняя переменная var5
#define idvar5	210	// Внутренняя переменная var5
#define var50	BUFFER[835]	// Внутренняя переменная var50
#define idvar50	211	// Внутренняя переменная var50
#define var51	BUFFER[840]	// Внутренняя переменная var51
#define idvar51	212	// Внутренняя переменная var51
#define var53	BUFFER[845]	// Внутренняя переменная var53
#define idvar53	213	// Внутренняя переменная var53
#define var54	BUFFER[847]	// Внутренняя переменная var54
#define idvar54	214	// Внутренняя переменная var54
#define var56	BUFFER[849]	// Внутренняя переменная var56
#define idvar56	215	// Внутренняя переменная var56
#define var57	BUFFER[851]	// Внутренняя переменная var57
#define idvar57	216	// Внутренняя переменная var57
#define var58	BUFFER[853]	// Внутренняя переменная var58
#define idvar58	217	// Внутренняя переменная var58
#define var59	BUFFER[855]	// Внутренняя переменная var59
#define idvar59	218	// Внутренняя переменная var59
#define var6	BUFFER[857]	// Внутренняя переменная var6
#define idvar6	219	// Внутренняя переменная var6
#define var60	BUFFER[862]	// Внутренняя переменная var60
#define idvar60	220	// Внутренняя переменная var60
#define var61	BUFFER[864]	// Внутренняя переменная var61
#define idvar61	221	// Внутренняя переменная var61
#define var62	BUFFER[866]	// Внутренняя переменная var62
#define idvar62	222	// Внутренняя переменная var62
#define var63	BUFFER[868]	// Внутренняя переменная var63
#define idvar63	223	// Внутренняя переменная var63
#define var64	BUFFER[870]	// Внутренняя переменная var64
#define idvar64	224	// Внутренняя переменная var64
#define var65	BUFFER[872]	// Внутренняя переменная var65
#define idvar65	225	// Внутренняя переменная var65
#define var66	BUFFER[874]	// Внутренняя переменная var66
#define idvar66	226	// Внутренняя переменная var66
#define var7	BUFFER[876]	// Внутренняя переменная var7
#define idvar7	227	// Внутренняя переменная var7
#define var8	BUFFER[881]	// Внутренняя переменная var8
#define idvar8	228	// Внутренняя переменная var8
#define var9	BUFFER[886]	// Внутренняя переменная var9
#define idvar9	229	// Внутренняя переменная var9
#pragma pack(push,1)
static VarCtrl allVariables[]={ 			 //Описание всех переменных
	{1	,8	,1	,&A0CT01IRP},	//( - , RPU) Температура АЗ1-3
	{2	,1	,1	,&A0EE01LRP},	//( - , RPU) Исправность АКНП канал 5
	{3	,1	,1	,&A0EE02LRP},	//( - , RPU) Исправность АКНП5 (от сшивки каналов) канал 5
	{4	,3	,1	,&A0IT03IRP},	//(vas84:06 - K01VASR, RPU) Температура АЗ1-3
	{5	,1	,1	,&A0VT61LRP},	//( - , RPU) ПС по температуре в АЗ1
	{6	,1	,1	,&A0VT71LRP},	//( - , RPU) АС по температуре в АЗ1
	{7	,1	,1	,&A1IS21LRP},	//(vds32:07 - K09VDSR, - ) Приход на НУ ББ1
	{8	,1	,1	,&A1VS21LRP},	//(fds16:08 - K01FDSR, - ) Индикация - Приход на НУ ББ1
	{9	,1	,1	,&A1VT71LRP},	//(fds16:08 - K11FDSR, - ) АС по температуре
	{10	,1	,1	,&A2IS21LRP},	//(vds32:07 - K10VDSR, - ) Приход на НУ РБ1-CC
	{11	,1	,1	,&A2VS21LRP},	//(fds16:08 - K03FDSR, - ) Индикация - Приход на НУ РБ1-CC
	{12	,1	,1	,&A3IS21LRP},	//(vds32:07 - K08VDSR, - ) Приход на НУ ИС1
	{13	,1	,1	,&A3VS21LRP},	//(fds16:08 - K05FDSR, - ) Индикация - Приход на НУ ИС1
	{14	,1	,1	,&A6IS11LRP},	//(vds32:07 - K14VDSR, - ) Приход на ВУ БЗ1
	{15	,1	,1	,&A7MZ31LRP},	//( - , RPU) Клапан ОБДУВ АЗ1 открыть(обесточить)
	{16	,8	,1	,&B0CT01IRP},	//( - , RPU) Температура АЗ2-3
	{17	,3	,1	,&B0IT03IRP},	//(vas84:06 - K02VASR, RPU) Температура АЗ2-3
	{18	,1	,1	,&B0VT61LRP},	//( - , RPU) ПС по температуре в АЗ2-3
	{19	,1	,1	,&B0VT71LRP},	//( - , RPU) АС по температуре в АЗ2-3
	{20	,1	,1	,&B1IS21LRP},	//(vds32:07 - K12VDSR, - ) Приход на НУ ББ2
	{21	,1	,1	,&B1VS21LRP},	//(fds16:08 - K02FDSR, - ) Индикация - Приход на НУ ББ2
	{22	,1	,1	,&B2IS21LRP},	//(vds32:07 - K13VDSR, - ) Приход на НУ РБ2-CC
	{23	,1	,1	,&B2VS21LRP},	//(fds16:08 - K04FDSR, - ) Индикация - Приход на НУ РБ2-CC
	{24	,1	,1	,&B3IS21LRP},	//(vds32:07 - K11VDSR, - ) Приход на НУ ИС2
	{25	,1	,1	,&B3VS21LRP},	//(fds16:08 - K06FDSR, - ) Индикация - Приход на НУ ИС2
	{26	,1	,1	,&B6IS11LRP},	//(vds32:07 - K15VDSR, - ) Приход на ВУ БЗ2
	{27	,1	,1	,&B7MZ31LRP},	//( - , RPU) Клапан ОБДУВ АЗ2 открыть(обесточить)
	{28	,8	,1	,&B8VC01RDU},	//( - , RPU) Координата АЗ2, мм
	{29	,1	,1	,&C1MD31LRP},	//(vds32:07 - K06VDSR, - ) Кнопка ОБЩИЙ СБРОС  на РПУ
	{30	,1	,1	,&C1MZ31LRP},	//(vds32:07 - K07VDSR, - ) Кнопка ОБДУВ  на РПУ
	{31	,8	,1	,&METRP06},	//( - , RPU) Метр давление 0.6
	{32	,8	,1	,&METRP12},	//( - , RPU) Метр давление 1.2
	{33	,3	,1	,&R0DE01LRP},	//(vchs:01 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 1
	{34	,3	,1	,&R0DE02LRP},	//(vchs:02 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 2
	{35	,3	,1	,&R0DE03LRP},	//(vchs:03 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 3
	{36	,3	,1	,&R0DE06LRP},	//(vas84:06 - Diagn, DiagnRPU) диагностика модуля РПУ-ВАС место 6
	{37	,3	,1	,&R0DE07LRP},	//(vds32:07 - Diagn, DiagnRPU) диагностика модуля РПУ-ВДС место 7
	{38	,3	,1	,&R0DE08LRP},	//(fds16:08 - Diagn, DiagnRPU) диагностика модуля РПУ-ФДС место 8
	{39	,1	,1	,&R0DE31LRP},	//(sbk:20 - S01SBK, DiagnRPU) диагностика шкафа РПУ сеть 1
	{40	,1	,1	,&R0DE32LRP},	//(sbk:20 - S02SBK, DiagnRPU) диагностика шкафа РПУ сеть 2
	{41	,1	,1	,&R0DE33LRP},	//(sbk:20 - S03SBK, DiagnRPU) диагностика шкафа РПУ двери
	{42	,1	,1	,&R0DE34LRP},	//(sbk:20 - S04SBK, DiagnRPU) диагностика шкафа РПУ температура меньше 43
	{43	,1	,1	,&R0DE35LRP},	//(sbk:20 - S05SBK, DiagnRPU) диагностика шкафа РПУ температура больше 53
	{44	,1	,1	,&R0DE36LRP},	//(sbk:20 - S06SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 1
	{45	,1	,1	,&R0DE37LRP},	//(sbk:20 - S07SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 2
	{46	,1	,1	,&R0DE38LRP},	//(sbk:20 - S08SBK, DiagnRPU) диагностика шкафа РПУ МП15-3 место 3
	{47	,1	,1	,&R0DE39LRP},	//(sbk:20 - S09SBK, DiagnRPU) диагностика шкафа РПУ МП24-2 место 4
	{48	,1	,1	,&R0DE3CLRP},	//( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 7
	{49	,1	,1	,&R0DE3DLRP},	//( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 8
	{50	,1	,1	,&R0DEB1LRP},	//(sbk:20 - S10SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 7
	{51	,1	,1	,&R0DEB2LRP},	//(sbk:20 - S11SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 7
	{52	,1	,1	,&R0DEB3LRP},	//(sbk:20 - S12SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 8
	{53	,1	,1	,&R0DEB4LRP},	//(sbk:20 - S13SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 8
	{54	,1	,1	,&R0EE02LDU},	//( - , RPU) Питание  АКНП  отключить
	{55	,1	,1	,&R0ET01LRP},	//( - , RPU) Признак наличия неисправности по температуре  АЗ1-3
	{56	,1	,1	,&R0ET02LRP},	//( - , RPU) Признак наличия неисправности по температуре АЗ2-3
	{57	,1	,1	,&R0IE01LRP},	//(fds16:08 - K08FDSR, - ) Отключение питание детекторов канал 5
	{58	,1	,1	,&R0IE02LRP},	//(fds16:08 - K07FDSR, - ) Отключить питание ПР, ПУ канал 5
	{59	,1	,1	,&R0IE03LRP},	//(fds16:08 - K09FDSR, - ) Отключение питание детекторов канал  6,7
	{60	,1	,1	,&R0IE04LRP},	//(fds16:08 - K10FDSR, - ) Отключить питание ПР, ПУ канал 6,7
	{61	,1	,1	,&R0IE11LRP},	//(vds32:07 - K03VDSR, - ) Исправность ВИП 1,6 (№20) СНМ11 5 канала
	{62	,1	,1	,&R0IE12LRP},	//(vds32:07 - K04VDSR, - ) Исправность ВИП 0,5 -5к (№21)
	{63	,1	,1	,&R0IE13LRP},	//(vds32:07 - K05VDSR, - ) Исправность ВИП 0,5 -5к (№22)
	{64	,1	,1	,&R0IE14LRP},	//(vds32:07 - K01VDSR, - ) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
	{65	,1	,1	,&R0IE15LRP},	//(vds32:07 - K02VDSR, - ) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
	{66	,8	,1	,&R0IN01RIP},	//( - , MRPS) Частота СНМ-11 Гц (канал 5) от ПТИ
	{67	,8	,1	,&R0IN01RRP},	//( - , RPU) Частота СНМ-11 Гц (канал 5)
	{68	,8	,1	,&R0IN01VRP},	//(vchs:01 - K01VCHS, RPU) Частота с ВЧС к 1
	{69	,8	,1	,&R0IN02RIP},	//( - , MRPS) Частота КНК15-1 Гц (канал 5) от ПТИ
	{70	,8	,1	,&R0IN02RRP},	//( - , RPU) Частота КНК15-1 Гц (канал 5)
	{71	,8	,1	,&R0IN02VRP},	//(vchs:01 - K02VCHS, RPU) Частота с ВЧС к 2
	{72	,8	,1	,&R0IN03RIP},	//( - , MRPS) Частота КНК53М Гц (канал 5) от ПТИ
	{73	,8	,1	,&R0IN03RRP},	//( - , RPU) Частота КНК53М Гц (канал 5)
	{74	,8	,1	,&R0IN03VRP},	//(vchs:02 - K01VCHS, RPU) Частота с ВЧС к 3
	{75	,8	,1	,&R0IN06RIP},	//( - , MRPS) Частота СНМ-11 Гц (канал 6) от ПТИ
	{76	,8	,1	,&R0IN06RRP},	//( - , RPU) Частота СНМ-11 Гц (канал 6) от ПТИ
	{77	,8	,1	,&R0IN06VRP},	//(vchs:03 - K01VCHS, RPU) Частота с ВЧС к 6
	{78	,8	,1	,&R0IN07RIP},	//( - , MRPS) Частота СНМ-11 Гц (канал 7) от ПТИ
	{79	,8	,1	,&R0IN07RRP},	//( - , RPU) Частота СНМ-11 Гц (канал 7)
	{80	,8	,1	,&R0IN07VRP},	//(vchs:03 - K02VCHS, RPU) Частота с ВЧС к 7
	{81	,1	,1	,&R0IS01FI0},	//( - , MRPS) Признак работы с имитатором
	{82	,8	,1	,&R0VN02RRP},	//( - , RPU) Уровень мощности канал 5
	{83	,8	,1	,&R0VN03RRP},	//( - , RPU) Измеренный нейтронный поток канал 5
	{84	,8	,1	,&R0VN13RRP},	//( - , RPU) Нейтронный поток по камере  СНМ-11 канал 5
	{85	,3	,1	,&R0VN15RRP},	//( - , RPU) Номер ведущей камеры канал 5
	{86	,8	,1	,&R0VN23RRP},	//( - , RPU) Нейтронный поток по камере КНК15-1 канал 5
	{87	,8	,1	,&R0VN33RRP},	//( - , RPU) Нейтронный поток по камере КНК53М канал 5
	{88	,1	,1	,&R0VN71LRP},	//(fds16:08 - K12FDSR, - ) АС по мощности канал 5
	{89	,1	,1	,&R7VE70LRP},	//( - , RPU) Сигнал тревоги по неисправности РПУ на диспетчера
	{90	,1	,1	,&R7VN71LRP},	//( - , RPU) Сигнал тревоги по уровню нейтронного потока на диспетчера
	{91	,3	,1	,&TTLrpu},	//( - , RPU) ttl
	{92	,1	,1	,&TestDiagnRPU},	//( - , RPU) Неисправность от диагностики
	{93	,3	,1	,&VMETRP06},	//(vas84:06 - K05VASR, RPU) вход Метр Давленение 0.6
	{94	,3	,1	,&VMETRP12},	//(vas84:06 - K06VASR, RPU) вход Метр Давленение 1.2
	{95	,8	,1	,&aaaa},	//( - , - ) aaaa
	{96	,1	,1	,&bFirstEnterFlag},	//(bFirstEnterFlag) 
	{97	,8	,1	,&fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{98	,8	,1	,&fEM_A0UX13RSS},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{99	,8	,1	,&fEM_A0UX14RSS},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{100	,8	,1	,&fEM_A0UX15RSS},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{101	,8	,1	,&fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{102	,8	,1	,&fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры4
	{103	,8	,1	,&fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{104	,8	,1	,&fEM_R0IN11NRP},	//(R0IN11NRP) Коэффициент A (РПУ к 1)
	{105	,8	,1	,&fEM_R0IN12NRP},	//(R0IN12NRP) Коэффициент B (РПУ к 1)
	{106	,8	,1	,&fEM_R0IN21NRP},	//(R0IN21NRP) Коэффициент A (РПУ к 2)
	{107	,8	,1	,&fEM_R0IN22NRP},	//(R0IN22NRP) Коэффициент B (РПУ к 2)
	{108	,8	,1	,&fEM_R0IN31NRP},	//(R0IN31NRP) Коэффициент A (РПУ к 3)
	{109	,8	,1	,&fEM_R0IN32NRP},	//(R0IN32NRP) Коэффициент B (РПУ к 3)
	{110	,8	,1	,&fEM_R0IN61NRP},	//(R0IN61NRP) Коэффициент A (РПУ к 6)
	{111	,8	,1	,&fEM_R0IN62NRP},	//(R0IN62NRP) Коэффициент B (РПУ к 6)
	{112	,8	,1	,&fEM_R0IN71NRP},	//(R0IN71NRP) Коэффициент A (РПУ к 7)
	{113	,8	,1	,&fEM_R0IN72NRP},	//(R0IN72NRP) Коэффициент B (РПУ к 7)
	{114	,8	,1	,&fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{115	,8	,1	,&fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{116	,8	,1	,&fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{117	,8	,1	,&fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{118	,8	,1	,&fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{119	,8	,1	,&fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{120	,8	,1	,&fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{121	,8	,1	,&fEM_R0UR01RRP},	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
	{122	,8	,1	,&fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{123	,8	,1	,&fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{124	,8	,1	,&fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{125	,8	,1	,&fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{126	,8	,1	,&fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{127	,8	,1	,&fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{128	,8	,1	,&fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{129	,8	,1	,&fEM_R7UX13RSS},	//(R7UX13RSS) X-координата камеры R7IN51
	{130	,8	,1	,&fEM_R7UX14RSS},	//(R7UX14RSS) X-координата камеры R7IN52
	{131	,8	,1	,&fEM_R7UX15RSS},	//(R7UX15RSS) X-координата камеры R7IN53
	{132	,8	,1	,&fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{133	,8	,1	,&fEM_R7UY13RSS},	//(R7UY13RSS) Y-координата камеры R7IN51
	{134	,8	,1	,&fEM_R7UY14RSS},	//(R7UY14RSS) Y-координата камеры R7IN52
	{135	,8	,1	,&fEM_R7UY15RSS},	//(R7UY15RSS) Y-координата камеры R7IN53
	{136	,8	,1	,&fEM_R7UY22RSS},	//(R7UY22RSS) 2-й коэффициент ф-ции смещения
	{137	,8	,1	,&fEM_R7UY32RSS},	//(R7UY32RSS) 1-й коэффициент ф-ции смещения
	{138	,8	,1	,&fEM_R7UY42RSS},	//(R7UY42RSS) уровень корректировки
	{139	,8	,1	,&fEM_Z7UE20RRP},	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
	{140	,3	,1	,&iEM_R7UY12RSS},	//(R7UY12RSS) интервал усреднения
	{141	,1	,1	,&internal1_m100_y1},	//(internal1_m100_y1) y1 - внутренний параметр
	{142	,1	,1	,&internal1_m112_y1},	//(internal1_m112_y1) y1 - внутренний параметр
	{143	,1	,1	,&internal1_m115_y1},	//(internal1_m115_y1) y1 - внутренний параметр
	{144	,8	,1	,&internal1_m183_SumS},	//(internal1_m183_SumS) внутренний параметр
	{145	,8	,1	,&internal1_m183_flst},	//(internal1_m183_flst) внутренний параметр
	{146	,3	,1	,&internal1_m183_stepc},	//(internal1_m183_stepc) stepc - счетчик шагов
	{147	,8	,10	,&internal1_m183_x0},	//(internal1_m183_x0) x0 - массив мгновенных значений 
	{148	,3	,1	,&internal1_m183_xptr},	//(internal1_m183_xptr) указатель текущей позиции в массиве координат
	{149	,8	,1	,&internal1_m184_SumS},	//(internal1_m184_SumS) внутренний параметр
	{150	,8	,1	,&internal1_m184_flst},	//(internal1_m184_flst) внутренний параметр
	{151	,3	,1	,&internal1_m184_stepc},	//(internal1_m184_stepc) stepc - счетчик шагов
	{152	,8	,10	,&internal1_m184_x0},	//(internal1_m184_x0) x0 - массив мгновенных значений 
	{153	,3	,1	,&internal1_m184_xptr},	//(internal1_m184_xptr) указатель текущей позиции в массиве координат
	{154	,3	,1	,&internal1_m18_Nk},	//(internal1_m18_Nk) Nk - ведущая камера
	{155	,8	,1	,&internal1_m199_y0},	//(internal1_m199_y0) y0
	{156	,8	,1	,&internal1_m200_y0},	//(internal1_m200_y0) y0
	{157	,8	,1	,&internal1_m70_tx},	//(internal1_m70_tx) tx - время накопленное сек
	{158	,18	,1	,&internal1_m70_y0},	//(internal1_m70_y0) y0
	{159	,8	,1	,&internal1_m78_tx},	//(internal1_m78_tx) tx - время накопленное сек
	{160	,18	,1	,&internal1_m78_y0},	//(internal1_m78_y0) y0
	{161	,8	,1	,&internal1_m84_y0},	//(internal1_m84_y0) y0
	{162	,8	,1	,&internal1_m86_y0},	//(internal1_m86_y0) y0
	{163	,1	,1	,&internal1_m98_y1},	//(internal1_m98_y1) y1 - внутренний параметр
	{164	,1	,1	,&vainSBool},	//Внутренняя переменная vainSBool
	{165	,8	,1	,&vainSFloat},	//Внутренняя переменная vainSFloat
	{166	,5	,1	,&vainSInt},	//Внутренняя переменная vainSInt
	{167	,11	,1	,&vainSLong},	//Внутренняя переменная vainSLong
	{168	,8	,1	,&var1},	//Внутренняя переменная var1
	{169	,8	,1	,&var10},	//Внутренняя переменная var10
	{170	,8	,1	,&var11},	//Внутренняя переменная var11
	{171	,8	,1	,&var12},	//Внутренняя переменная var12
	{172	,8	,1	,&var13},	//Внутренняя переменная var13
	{173	,8	,1	,&var14},	//Внутренняя переменная var14
	{174	,1	,1	,&var15},	//Внутренняя переменная var15
	{175	,1	,1	,&var16},	//Внутренняя переменная var16
	{176	,1	,1	,&var17},	//Внутренняя переменная var17
	{177	,1	,1	,&var18},	//Внутренняя переменная var18
	{178	,1	,1	,&var19},	//Внутренняя переменная var19
	{179	,8	,1	,&var2},	//Внутренняя переменная var2
	{180	,1	,1	,&var20},	//Внутренняя переменная var20
	{181	,1	,1	,&var21},	//Внутренняя переменная var21
	{182	,1	,1	,&var22},	//Внутренняя переменная var22
	{183	,1	,1	,&var23},	//Внутренняя переменная var23
	{184	,5	,1	,&var24},	//Внутренняя переменная var24
	{185	,8	,1	,&var25},	//Внутренняя переменная var25
	{186	,8	,1	,&var26},	//Внутренняя переменная var26
	{187	,1	,1	,&var27},	//Внутренняя переменная var27
	{188	,8	,1	,&var28},	//Внутренняя переменная var28
	{189	,8	,1	,&var29},	//Внутренняя переменная var29
	{190	,8	,1	,&var3},	//Внутренняя переменная var3
	{191	,8	,1	,&var30},	//Внутренняя переменная var30
	{192	,5	,1	,&var31},	//Внутренняя переменная var31
	{193	,1	,1	,&var32},	//Внутренняя переменная var32
	{194	,1	,1	,&var33},	//Внутренняя переменная var33
	{195	,1	,1	,&var34},	//Внутренняя переменная var34
	{196	,1	,1	,&var35},	//Внутренняя переменная var35
	{197	,1	,1	,&var36},	//Внутренняя переменная var36
	{198	,1	,1	,&var37},	//Внутренняя переменная var37
	{199	,1	,1	,&var38},	//Внутренняя переменная var38
	{200	,1	,1	,&var39},	//Внутренняя переменная var39
	{201	,8	,1	,&var4},	//Внутренняя переменная var4
	{202	,1	,1	,&var40},	//Внутренняя переменная var40
	{203	,1	,1	,&var41},	//Внутренняя переменная var41
	{204	,1	,1	,&var43},	//Внутренняя переменная var43
	{205	,1	,1	,&var45},	//Внутренняя переменная var45
	{206	,1	,1	,&var46},	//Внутренняя переменная var46
	{207	,1	,1	,&var47},	//Внутренняя переменная var47
	{208	,1	,1	,&var48},	//Внутренняя переменная var48
	{209	,1	,1	,&var49},	//Внутренняя переменная var49
	{210	,8	,1	,&var5},	//Внутренняя переменная var5
	{211	,8	,1	,&var50},	//Внутренняя переменная var50
	{212	,8	,1	,&var51},	//Внутренняя переменная var51
	{213	,1	,1	,&var53},	//Внутренняя переменная var53
	{214	,1	,1	,&var54},	//Внутренняя переменная var54
	{215	,1	,1	,&var56},	//Внутренняя переменная var56
	{216	,1	,1	,&var57},	//Внутренняя переменная var57
	{217	,1	,1	,&var58},	//Внутренняя переменная var58
	{218	,1	,1	,&var59},	//Внутренняя переменная var59
	{219	,8	,1	,&var6},	//Внутренняя переменная var6
	{220	,1	,1	,&var60},	//Внутренняя переменная var60
	{221	,1	,1	,&var61},	//Внутренняя переменная var61
	{222	,1	,1	,&var62},	//Внутренняя переменная var62
	{223	,1	,1	,&var63},	//Внутренняя переменная var63
	{224	,1	,1	,&var64},	//Внутренняя переменная var64
	{225	,1	,1	,&var65},	//Внутренняя переменная var65
	{226	,1	,1	,&var66},	//Внутренняя переменная var66
	{227	,8	,1	,&var7},	//Внутренняя переменная var7
	{228	,8	,1	,&var8},	//Внутренняя переменная var8
	{229	,8	,1	,&var9},	//Внутренняя переменная var9
	{-1,0,NULL},
};
static char NameSaveFile[]="rpu.bin\0"; //Имя файла сохранения переменных
#pragma pop
static VarSaveCtrl saveVariables[]={	//Id переменных для сохранения
	{97,"fEM_A0UX00RSS\0"},	//(A0UX00RSS) Эффективный радиус АЗ
	{98,"fEM_A0UX13RSS\0"},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{99,"fEM_A0UX14RSS\0"},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{100,"fEM_A0UX15RSS\0"},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{101,"fEM_B0UX03RSS\0"},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{102,"fEM_B0UX04RSS\0"},	//(B0UX04RSS) Второй коэффициент калибровки камеры4
	{103,"fEM_B0UX05RSS\0"},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{104,"fEM_R0IN11NRP\0"},	//(R0IN11NRP) Коэффициент A (РПУ к 1)
	{105,"fEM_R0IN12NRP\0"},	//(R0IN12NRP) Коэффициент B (РПУ к 1)
	{106,"fEM_R0IN21NRP\0"},	//(R0IN21NRP) Коэффициент A (РПУ к 2)
	{107,"fEM_R0IN22NRP\0"},	//(R0IN22NRP) Коэффициент B (РПУ к 2)
	{108,"fEM_R0IN31NRP\0"},	//(R0IN31NRP) Коэффициент A (РПУ к 3)
	{109,"fEM_R0IN32NRP\0"},	//(R0IN32NRP) Коэффициент B (РПУ к 3)
	{110,"fEM_R0IN61NRP\0"},	//(R0IN61NRP) Коэффициент A (РПУ к 6)
	{111,"fEM_R0IN62NRP\0"},	//(R0IN62NRP) Коэффициент B (РПУ к 6)
	{112,"fEM_R0IN71NRP\0"},	//(R0IN71NRP) Коэффициент A (РПУ к 7)
	{113,"fEM_R0IN72NRP\0"},	//(R0IN72NRP) Коэффициент B (РПУ к 7)
	{114,"fEM_R0UH02RSS\0"},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{115,"fEM_R0UH03RSS\0"},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{116,"fEM_R0UH05RSS\0"},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{117,"fEM_R0UH21RSS\0"},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{118,"fEM_R0UH22RSS\0"},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{119,"fEM_R0UH23RSS\0"},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{120,"fEM_R0UL52RSS\0"},	//(R0UL52RSS) Уровень АС по мощности
	{121,"fEM_R0UR01RRP\0"},	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
	{122,"fEM_R0UT01RZZ\0"},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{123,"fEM_R0UT02RZZ\0"},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{124,"fEM_R0UT61RZZ\0"},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{125,"fEM_R0UT62RZZ\0"},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{126,"fEM_R0UT71RZZ\0"},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{127,"fEM_R0UT72RZZ\0"},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{128,"fEM_R7UX00RSS\0"},	//(R7UX00RSS) X-координата АЗ1 (см)
	{129,"fEM_R7UX13RSS\0"},	//(R7UX13RSS) X-координата камеры R7IN51
	{130,"fEM_R7UX14RSS\0"},	//(R7UX14RSS) X-координата камеры R7IN52
	{131,"fEM_R7UX15RSS\0"},	//(R7UX15RSS) X-координата камеры R7IN53
	{132,"fEM_R7UY00RSS\0"},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{133,"fEM_R7UY13RSS\0"},	//(R7UY13RSS) Y-координата камеры R7IN51
	{134,"fEM_R7UY14RSS\0"},	//(R7UY14RSS) Y-координата камеры R7IN52
	{135,"fEM_R7UY15RSS\0"},	//(R7UY15RSS) Y-координата камеры R7IN53
	{136,"fEM_R7UY22RSS\0"},	//(R7UY22RSS) 2-й коэффициент ф-ции смещения
	{137,"fEM_R7UY32RSS\0"},	//(R7UY32RSS) 1-й коэффициент ф-ции смещения
	{138,"fEM_R7UY42RSS\0"},	//(R7UY42RSS) уровень корректировки
	{139,"fEM_Z7UE20RRP\0"},	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
	{140,"iEM_R7UY12RSS\0"},	//(R7UY12RSS) интервал усреднения
	{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_RPU[]={
	{&R0EE02LDU,1,0},	//( - , RPU) Питание  АКНП  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_RPU[]={
	{&B0VT61LRP,1,0},	//( - , RPU) ПС по температуре в АЗ2-3
	{&B0VT71LRP,1,1},	//( - , RPU) АС по температуре в АЗ2-3
	{&A0EE01LRP,1,2},	//( - , RPU) Исправность АКНП канал 5
	{&R7VE70LRP,1,3},	//( - , RPU) Сигнал тревоги по неисправности РПУ на диспетчера
	{&A7MZ31LRP,1,4},	//( - , RPU) Клапан ОБДУВ АЗ1 открыть(обесточить)
	{&B7MZ31LRP,1,5},	//( - , RPU) Клапан ОБДУВ АЗ2 открыть(обесточить)
	{&TestDiagnRPU,1,6},	//( - , RPU) Неисправность от диагностики
	{&A0EE02LRP,1,7},	//( - , RPU) Исправность АКНП5 (от сшивки каналов) канал 5
	{&R7VN71LRP,1,8},	//( - , RPU) Сигнал тревоги по уровню нейтронного потока на диспетчера
	{&A0VT61LRP,1,9},	//( - , RPU) ПС по температуре в АЗ1
	{&A0VT71LRP,1,10},	//( - , RPU) АС по температуре в АЗ1
	{&R0ET01LRP,1,11},	//( - , RPU) Признак наличия неисправности по температуре  АЗ1-3
	{&R0ET02LRP,1,12},	//( - , RPU) Признак наличия неисправности по температуре АЗ2-3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_RPU[]={
	{&B0CT01IRP,8,0},	//( - , RPU) Температура АЗ2-3
	{&R0VN13RRP,8,2},	//( - , RPU) Нейтронный поток по камере  СНМ-11 канал 5
	{&TTLrpu,3,4},	//( - , RPU) ttl
	{&R0IN01VRP,8,5},	//( - K01VCHS, RPU) Частота с ВЧС к 1
	{&R0IN02VRP,8,7},	//( - K02VCHS, RPU) Частота с ВЧС к 2
	{&R0IN03VRP,8,9},	//( - K01VCHS, RPU) Частота с ВЧС к 3
	{&R0IN06VRP,8,11},	//( - K01VCHS, RPU) Частота с ВЧС к 6
	{&R0IN07VRP,8,13},	//( - K02VCHS, RPU) Частота с ВЧС к 7
	{&VMETRP06,3,15},	//( - K05VASR, RPU) вход Метр Давленение 0.6
	{&METRP06,8,16},	//( - , RPU) Метр давление 0.6
	{&VMETRP12,3,18},	//( - K06VASR, RPU) вход Метр Давленение 1.2
	{&METRP12,8,19},	//( - , RPU) Метр давление 1.2
	{&R0VN02RRP,8,21},	//( - , RPU) Уровень мощности канал 5
	{&R0IN01RRP,8,23},	//( - , RPU) Частота СНМ-11 Гц (канал 5)
	{&R0IN02RRP,8,25},	//( - , RPU) Частота КНК15-1 Гц (канал 5)
	{&R0VN03RRP,8,27},	//( - , RPU) Измеренный нейтронный поток канал 5
	{&R0IN03RRP,8,29},	//( - , RPU) Частота КНК53М Гц (канал 5)
	{&R0VN23RRP,8,31},	//( - , RPU) Нейтронный поток по камере КНК15-1 канал 5
	{&R0VN33RRP,8,33},	//( - , RPU) Нейтронный поток по камере КНК53М канал 5
	{&R0VN15RRP,3,35},	//( - , RPU) Номер ведущей камеры канал 5
	{&R0IN06RRP,8,36},	//( - , RPU) Частота СНМ-11 Гц (канал 6) от ПТИ
	{&R0IN07RRP,8,38},	//( - , RPU) Частота СНМ-11 Гц (канал 7)
	{&A0IT03IRP,3,40},	//( - K01VASR, RPU) Температура АЗ1-3
	{&A0CT01IRP,8,41},	//( - , RPU) Температура АЗ1-3
	{&B0IT03IRP,3,43},	//( - K02VASR, RPU) Температура АЗ2-3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_RPU[]={
	{&B8VC01RDU,8,0},	//( - , RPU) Координата АЗ2, мм
	{&fEM_R0UH02RSS,8,2},	//( - , RPU) Коэфф. преобразования частота->нейтр/с КНК15-1
	{&fEM_R0UH03RSS,8,4},	//( - , RPU) Коэфф. преобразования частота->нейтр/с КНК53М
	{&fEM_R7UX00RSS,8,6},	//( - , RPU) X-координата АЗ1 (см)
	{&fEM_R7UY00RSS,8,8},	//( - , RPU) Y-координата АЗ1 (см)
	{&fEM_R7UX13RSS,8,10},	//( - , RPU) X-координата камеры R7IN51
	{&fEM_R7UX14RSS,8,12},	//( - , RPU) X-координата камеры R7IN52
	{&fEM_R7UX15RSS,8,14},	//( - , RPU) X-координата камеры R7IN53
	{&fEM_R7UY13RSS,8,16},	//( - , RPU) Y-координата камеры R7IN51
	{&fEM_R7UY14RSS,8,18},	//( - , RPU) Y-координата камеры R7IN52
	{&fEM_R7UY15RSS,8,20},	//( - , RPU) Y-координата камеры R7IN53
	{&fEM_A0UX00RSS,8,22},	//( - , RPU) Эффективный радиус АЗ
	{&fEM_A0UX13RSS,8,24},	//( - , RPU) Первый коэффициент калибровки камеры 13
	{&fEM_A0UX14RSS,8,26},	//( - , RPU) Первый коэффициент калибровки камеры 14
	{&fEM_A0UX15RSS,8,28},	//( - , RPU) Первый коэффициент калибровки камеры 15
	{&fEM_B0UX03RSS,8,30},	//( - , RPU) Второй коэффициент калибровки камеры 3
	{&fEM_B0UX04RSS,8,32},	//( - , RPU) Второй коэффициент калибровки камеры4
	{&fEM_B0UX05RSS,8,34},	//( - , RPU) Второй коэффициент калибровки камеры 5
	{&fEM_R0UH05RSS,8,36},	//( - , RPU) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_R0UR01RRP,8,38},	//( - , RPU) Уставка СНМ11 в БЗ - АС по частоте
	{&fEM_R0UT02RZZ,8,40},	//( - , RPU) Верхний предел шкалы датчика температуры
	{&fEM_R0UT01RZZ,8,42},	//( - , RPU) Нижний предел шкалы датчика температуры
	{&fEM_R0UT72RZZ,8,44},	//( - , RPU) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{&fEM_R0UT71RZZ,8,46},	//( - , RPU) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{&fEM_R0UT62RZZ,8,48},	//( - , RPU) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{&fEM_R0UT61RZZ,8,50},	//( - , RPU) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{&fEM_R0UL52RSS,8,52},	//( - , RPU) Уровень АС по мощности
	{&fEM_Z7UE20RRP,8,54},	//( - , RPU) Время задержки сигнала на включение источников питания после снятия команды на отключение
	{&fEM_R0UH21RSS,8,56},	//( - , RPU) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{&fEM_R0UH22RSS,8,58},	//( - , RPU) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{&fEM_R0UH23RSS,8,60},	//( - , RPU) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{&fEM_R0IN11NRP,8,62},	//( - , RPU) Коэффициент A (РПУ к 1)
	{&fEM_R0IN12NRP,8,64},	//( - , RPU) Коэффициент B (РПУ к 1)
	{&fEM_R0IN21NRP,8,66},	//( - , RPU) Коэффициент A (РПУ к 2)
	{&fEM_R0IN22NRP,8,68},	//( - , RPU) Коэффициент B (РПУ к 2)
	{&fEM_R0IN31NRP,8,70},	//( - , RPU) Коэффициент A (РПУ к 3)
	{&fEM_R0IN32NRP,8,72},	//( - , RPU) Коэффициент B (РПУ к 3)
	{&fEM_R0IN61NRP,8,74},	//( - , RPU) Коэффициент A (РПУ к 6)
	{&fEM_R0IN62NRP,8,76},	//( - , RPU) Коэффициент B (РПУ к 6)
	{&fEM_R0IN71NRP,8,78},	//( - , RPU) Коэффициент A (РПУ к 7)
	{&fEM_R0IN72NRP,8,80},	//( - , RPU) Коэффициент B (РПУ к 7)
	{&iEM_R7UY12RSS,3,82},	//( - , RPU) интервал усреднения
	{&fEM_R7UY42RSS,8,83},	//( - , RPU) уровень корректировки
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_DiagnRPU[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnRPU[]={
	{&R0DEB3LRP,1,0},	//( - S12SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 8
	{&R0DEB4LRP,1,1},	//( - S13SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 8
	{&R0DEB2LRP,1,2},	//( - S11SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 7
	{&R0DEB1LRP,1,3},	//( - S10SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 7
	{&R0DE3DLRP,1,4},	//( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 8
	{&R0DE3CLRP,1,5},	//( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 7
	{&R0DE39LRP,1,6},	//( - S09SBK, DiagnRPU) диагностика шкафа РПУ МП24-2 место 4
	{&R0DE38LRP,1,7},	//( - S08SBK, DiagnRPU) диагностика шкафа РПУ МП15-3 место 3
	{&R0DE37LRP,1,8},	//( - S07SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 2
	{&R0DE36LRP,1,9},	//( - S06SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 1
	{&R0DE35LRP,1,10},	//( - S05SBK, DiagnRPU) диагностика шкафа РПУ температура больше 53
	{&R0DE34LRP,1,11},	//( - S04SBK, DiagnRPU) диагностика шкафа РПУ температура меньше 43
	{&R0DE33LRP,1,12},	//( - S03SBK, DiagnRPU) диагностика шкафа РПУ двери
	{&R0DE32LRP,1,13},	//( - S02SBK, DiagnRPU) диагностика шкафа РПУ сеть 2
	{&R0DE31LRP,1,14},	//( - S01SBK, DiagnRPU) диагностика шкафа РПУ сеть 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DiagnRPU[]={
	{&R0DE07LRP,3,0},	//( - Diagn, DiagnRPU) диагностика модуля РПУ-ВДС место 7
	{&R0DE08LRP,3,1},	//( - Diagn, DiagnRPU) диагностика модуля РПУ-ФДС место 8
	{&R0DE06LRP,3,2},	//( - Diagn, DiagnRPU) диагностика модуля РПУ-ВАС место 6
	{&R0DE03LRP,3,3},	//( - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 3
	{&R0DE02LRP,3,4},	//( - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 2
	{&R0DE01LRP,3,5},	//( - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DiagnRPU[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MRPS[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MRPS[]={
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MRPS[]={
	{&R0IN01RIP,8,0},	//( - , SRP) Выход СНМ-11 Гц от ПТИ
	{&R0IN02RIP,8,2},	//( - , SRP) Выход КНК15- Гц от ПТИ
	{&R0IN03RIP,8,4},	//( - , SRP) Выход КНК53М Гц от ПТИ
	{&R0IN06RIP,8,6},	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
	{&R0IN07RIP,8,8},	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MRPS[]={
	{NULL,0,0},
};
#pragma pop
static char MRPS_ip1[]={"192.168.10.60\0"};
static char MRPS_ip2[]={"\0"};
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_RPU[0],&di_RPU[0],&ir_RPU[0],&hr_RPU[0],NULL,NULL,NULL,0},	//общий slave RPU
	{0,5003,&coil_DiagnRPU[0],&di_DiagnRPU[0],&ir_DiagnRPU[0],&hr_DiagnRPU[0],NULL,NULL,NULL,0},	//Диагностика РПУ
	{1,5010,&coil_MRPS[0],&di_MRPS[0],&ir_MRPS[0],&hr_MRPS[0],NULL,MRPS_ip1,MRPS_ip2,100},	//Мастер RPU в SCM
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
	{&A1VS21LRP,1,0},
	{&B1VS21LRP,1,2},
	{&A2VS21LRP,1,4},
	{&B2VS21LRP,1,6},
	{&A3VS21LRP,1,8},
	{&B3VS21LRP,1,10},
	{&R0IE02LRP,1,12},
	{&R0IE01LRP,1,14},
	{&R0IE03LRP,1,16},
	{&R0IE04LRP,1,18},
	{&A1VT71LRP,1,20},
	{&R0VN71LRP,1,22},
	{&R0DE08LRP,3,38},
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
	{&R0DE31LRP,1,0},
	{&R0DE32LRP,1,2},
	{&R0DE33LRP,1,4},
	{&R0DE34LRP,1,6},
	{&R0DE35LRP,1,8},
	{&R0DE36LRP,1,10},
	{&R0DE37LRP,1,12},
	{&R0DE38LRP,1,14},
	{&R0DE39LRP,1,16},
	{&R0DEB1LRP,1,18},
	{&R0DEB2LRP,1,20},
	{&R0DEB3LRP,1,22},
	{&R0DEB4LRP,1,24},
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
	{&A0IT03IRP,3,0},
	{&B0IT03IRP,3,3},
	{&VMETRP06,3,12},
	{&VMETRP12,3,15},
	{&R0DE06LRP,3,26},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS01[122];	//VCHS01
static vchs_inipar ini_VCHS01={0xc4,255,8,0xff,0,0x1,0x1,0,0,0,};
#pragma pack(push,1)
static table_drv table_VCHS01={0,0,&ini_VCHS01,buf_VCHS01,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS01[]={
	{&R0IN01VRP,8,0},
	{&R0IN02VRP,8,5},
	{&R0DE01LRP,3,10},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS02[122];	//VCHS02
static vchs_inipar ini_VCHS02={0xc4,255,8,0xff,0,0x1,0x1,0,0,0,};
#pragma pack(push,1)
static table_drv table_VCHS02={0,0,&ini_VCHS02,buf_VCHS02,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS02[]={
	{&R0IN03VRP,8,0},
	{&R0DE02LRP,3,10},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS03[122];	//VCHS03
static vchs_inipar ini_VCHS03={0xc4,255,8,0xff,0,0x1,0x1,0,0,0,};
#pragma pack(push,1)
static table_drv table_VCHS03={0,0,&ini_VCHS03,buf_VCHS03,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS03[]={
	{&R0IN06VRP,8,0},
	{&R0IN07VRP,8,5},
	{&R0DE03LRP,3,10},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS32[194];	//VDS32
static vds32r_inipar ini_VDS32={0xc2,0xff,0,255,255,0,0,};
#pragma pack(push,1)
static table_drv table_VDS32={0,0,&ini_VDS32,buf_VDS32,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32[]={
	{&R0IE14LRP,1,0},
	{&R0IE15LRP,1,2},
	{&R0IE11LRP,1,4},
	{&R0IE12LRP,1,6},
	{&R0IE13LRP,1,8},
	{&C1MD31LRP,1,10},
	{&C1MZ31LRP,1,12},
	{&A3IS21LRP,1,14},
	{&A1IS21LRP,1,16},
	{&A2IS21LRP,1,18},
	{&B3IS21LRP,1,20},
	{&B1IS21LRP,1,22},
	{&B2IS21LRP,1,24},
	{&A6IS11LRP,1,26},
	{&B6IS11LRP,1,28},
	{&R0DE07LRP,3,64},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0x96,0x08,5,104,def_buf_FDS16,&table_FDS16},	//FDS16
	{0xcc,0x20,3,90,def_buf_SBKFP,&table_SBKFP},	//SBKFP
	{0xc6,0x06,5,64,def_buf_VAS84,&table_VAS84},	//VAS84
	{0xc4,0x01,10,122,def_buf_VCHS01,&table_VCHS01},	//VCHS01
	{0xc4,0x02,10,122,def_buf_VCHS02,&table_VCHS02},	//VCHS02
	{0xc4,0x03,10,122,def_buf_VCHS03,&table_VCHS03},	//VCHS03
	{0xc2,0x07,7,194,def_buf_VDS32,&table_VDS32},	//VDS32
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){	//Инициализация переменных для хранения
	setAsFloat(97,11.0);
	setAsFloat(98,1.0);
	setAsFloat(99,1.0);
	setAsFloat(100,1.0);
	setAsFloat(101,0);
	setAsFloat(102,0);
	setAsFloat(103,0.0);
	setAsFloat(104,1);
	setAsFloat(105,0);
	setAsFloat(106,1);
	setAsFloat(107,0);
	setAsFloat(108,1);
	setAsFloat(109,0);
	setAsFloat(110,1);
	setAsFloat(111,0);
	setAsFloat(112,1);
	setAsFloat(113,0);
	setAsFloat(114,37037.04 );
	setAsFloat(115,975000.0);
	setAsFloat(116,32000.0);
	setAsFloat(117,4000);
	setAsFloat(118,100000);
	setAsFloat(119,1000000);
	setAsFloat(120,5100);
	setAsFloat(121,1000);
	setAsFloat(122,0);
	setAsFloat(123,600);
	setAsFloat(124,100);
	setAsFloat(125,90);
	setAsFloat(126,200);
	setAsFloat(127,150);
	setAsFloat(128,1570.0);
	setAsFloat(129,1570.0);
	setAsFloat(130,1269);
	setAsFloat(131,1281.2);
	setAsFloat(132,506.5);
	setAsFloat(133,248.0);
	setAsFloat(134,572.4);
	setAsFloat(135,246.8);
	setAsFloat(136,0.260609);
	setAsFloat(137,-0.098010);
	setAsFloat(138,9.9);
	setAsFloat(139,210);
	setAsShort(140,10);
}

// Вставка к VCHS
void init_dataVchs(vchs_data *vch_data) {
    int i;
    for (i = 0; i < 2; i++) {
        vch_data->takt[i] = 0.5;
        vch_data->cykl[i] = 0.5;
        vch_data->cyklS[i] = 0.5;
        vch_data->perm[i] = 0;
        vch_data->fvch[i] = 0;
        vch_data->tempI[i] = 0;
    }
}

void VCHS_post(vchs_data *vch_data) {
    float fslow = 0, ffast = 0, zer = 0.0;
    int i;
    for (i = 0; i < 2; i++) {
        if (vch_data->perm[i] <= 0) {
                if(vch_data->SVCHS[i] == 1){
                    if( vch_data->cyklS[i] == 10)
                        vch_data->cyklS[i] = 1.0;
                    else
                        vch_data->cyklS[i] = 0.01;
                    vch_data->SVCHS[i] = 0;
                    vch_data->takt[i] = 0;                    
                    vch_data->cykl[i] = vch_data->cyklS[i]; 
                    continue;
                }    
                ffast = vch_data->tempI[i] / vch_data->takt[i];
                vch_data->fvch[i] = ffast;
                vch_data->takt[i] = 0;
                if(ffast < 40.0 )
                    vch_data->cyklS[i] = 10;
                    else   
                    vch_data->cyklS[i] = 1 / ((ffast / 64000) + 1);

                vch_data->cykl[i] = vch_data->cyklS[i]; 
        }
    }
    for (i = 0; i < 2; i++)
        if (fpcomp(&vch_data->cykl[i], &zer) > 0) {
            vch_data->takt[i] += takt;
            vch_data->cykl[i] -= takt;
            vch_data->perm[i] = fpcomp(&vch_data->cykl[i], &zer);
        }
    vch_data->K01VCHS.f = vch_data->fvch[0];
    vch_data->K02VCHS.f = vch_data->fvch[1];

}/* Определение внутренних параметров */

/* Определение констант ПЗУ и ЭСППЗУ*/
ssbool lRM_0_ = {0,0}; /* A-Граница участка насыщения А */ 
ssbool lRM_1_ = {1,0}; /* B-Граница участка насыщения В */ 
sslong dRM_0_ = {0,0}; /* lx вход лонг */ 
sschar bRM_0_ = {0,0}; /* cx вход байтовый */ 
ssint iRM_0_ = {0,0}; /* ix вход целый */ 
ssint iRM_3200_ = {3200,0}; /* a */ 
ssint iRM_16000_ = {16000,0}; /* b */ 
sschar bRM_1_ = {1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 
ssint iRM_6_ = {6,0}; /* n - размерность массива значений */ 
ssfloat fRM_0_ = {0,0}; /* c */ 
ssfloat fRM_0_6 = {0.6,0}; /* d */ 
ssfloat fRM_1_2 = {1.2,0}; /* d */ 
ssint iRM_10_ = {10,0}; /* n - размерность массива мгновенных значений */ 


/* Определение переменных */
sschar var42;
sschar var44;
sschar var52;
sschar var55;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psfloat  array_m184_x0_1[10];
psfloat  array_m183_x0_1[10];
psbool  array_m156_x_1[6] = {&var18,&var19,&R0DE36LRP,&R0DE37LRP,&R0DE38LRP,&R0DE39LRP};
psint  array_m138_x_1[6] = {&R0DE01LRP,&R0DE02LRP,&R0DE03LRP,&R0DE08LRP,&R0DE06LRP,&R0DE07LRP};

/* Объявление структур */
_S_ffiltr  S_ffiltr_184_1 = {&R0IN03VRP,&fEM_R7UY42RSS,&fEM_R7UY32RSS,&fEM_R7UY22RSS,&iEM_R7UY12RSS,&iRM_10_,&var1,&internal1_m184_xptr,&internal1_m184_stepc,array_m184_x0_1,&internal1_m184_flst,&internal1_m184_SumS,&bFirstEnterFlag};
_S_ffiltr  S_ffiltr_183_1 = {&R0IN02VRP,&fEM_R7UY42RSS,&fEM_R7UY32RSS,&fEM_R7UY22RSS,&iEM_R7UY12RSS,&iRM_10_,&var2,&internal1_m183_xptr,&internal1_m183_stepc,array_m183_x0_1,&internal1_m183_flst,&internal1_m183_SumS,&bFirstEnterFlag};
_S_scalzz  S_scalzz_200_1 = {&VMETRP12,&iRM_3200_,&iRM_16000_,&fRM_0_,&fRM_1_2,&var3,&internal1_m200_y0};
_S_scalzz  S_scalzz_199_1 = {&VMETRP06,&iRM_3200_,&iRM_16000_,&fRM_0_,&fRM_0_6,&var4,&internal1_m199_y0};
_S_pogrvh  S_pogrvh_185_1 = {&R0IN07VRP,&fEM_R0IN71NRP,&fEM_R0IN72NRP,&var5};
_S_pogrvh  S_pogrvh_175_1 = {&R0IN06VRP,&fEM_R0IN61NRP,&fEM_R0IN62NRP,&var6};
_S_pogrvh  S_pogrvh_173_1 = {&R0IN03VRP,&fEM_R0IN31NRP,&fEM_R0IN32NRP,&var7};
_S_pogrvh  S_pogrvh_171_1 = {&R0IN02VRP,&fEM_R0IN21NRP,&fEM_R0IN22NRP,&var8};
_S_pogrvh  S_pogrvh_169_1 = {&R0IN01VRP,&fEM_R0IN11NRP,&fEM_R0IN12NRP,&var9};
_S_ml  S_ml_57_1 = {&R0IN07RIP,&var5,&R0IS01FI0,&var10};
_S_ml  S_ml_49_1 = {&R0IN06RIP,&var6,&R0IS01FI0,&var11};
_S_ml  S_ml_8_1 = {&R0IN03RIP,&var7,&R0IS01FI0,&var12};
_S_ml  S_ml_7_1 = {&R0IN02RIP,&var8,&R0IS01FI0,&var13};
_S_ml  S_ml_6_1 = {&R0IN01RIP,&var9,&R0IS01FI0,&var14};
_S_or4  S_or4_71_1 = {&var58,&var32,&var40,&var41,&var15};
_S_noto  S_noto_157_1 = {&var20,&var16};
_S_and5  S_and5_43_1 = {&var16,&R0IE11LRP,&R0IE12LRP,&R0IE13LRP,&var27,&var17};
_S_or2  S_or2_151_1 = {&R0DEB1LRP,&R0DEB2LRP,&var18};
_S_or2  S_or2_158_1 = {&R0DEB3LRP,&R0DEB4LRP,&var19};
_S_or3  S_or3_155_1 = {&var23,&var22,&var21,&var20};
_S_orn  S_orn_156_1 = {array_m156_x_1,&iRM_6_,&var21};
_S_and2  S_and2_140_1 = {&R0DE31LRP,&R0DE32LRP,&var22};
_S_diagndev  S_diagndev_138_1 = {array_m138_x_1,&iRM_6_,&var23,&var24,&vainSFloat};
_S_ocham  S_ocham_18_1 = {&var14,&var13,&var12,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX13RSS,&fEM_B0UX03RSS,&fEM_A0UX14RSS,&fEM_B0UX04RSS,&fEM_A0UX15RSS,&fEM_B0UX05RSS,&fEM_R7UX13RSS,&fEM_R7UY13RSS,&fEM_R7UX14RSS,&fEM_R7UY14RSS,&fEM_R7UX15RSS,&fEM_R7UY15RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&fEM_R0UH21RSS,&fEM_R0UH22RSS,&fEM_R0UH23RSS,&var25,&var26,&var27,&var28,&var29,&var30,&var31,&internal1_m18_Nk};
_S_or2  S_or2_66_1 = {&A6IS11LRP,&B6IS11LRP,&vainSBool};
_S_or2  S_or2_94_1 = {&var65,&var66,&var32};
_S_or4  S_or4_48_1 = {&var39,&var37,&var38,&var35,&var33};
_S_or2  S_or2_99_1 = {&var64,&var53,&var34};
_S_or2  S_or2_123_1 = {&var36,&var34,&var35};
_S_or2  S_or2_95_1 = {&var63,&var56,&var36};
_S_and3  S_and3_44_1 = {&var17,&var49,&var43,&var37};
_S_and3  S_and3_52_1 = {&var47,&R0IE14LRP,&var59,&var38};
_S_and3  S_and3_51_1 = {&R0IE15LRP,&var47,&var60,&var39};
_S_and3  S_and3_60_1 = {&R0IE14LRP,&var47,&var62,&var40};
_S_and3  S_and3_59_1 = {&var61,&R0IE15LRP,&var47,&var41};
_S_geterr  S_geterr_56_1 = {&var11,&dRM_0_,&iRM_0_,&bRM_0_,&var42,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_noto  S_noto_79_1 = {&var48,&var43};
_S_geterr  S_geterr_55_1 = {&var10,&dRM_0_,&iRM_0_,&bRM_0_,&var44,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_zzfs  S_zzfs_70_1 = {&var46,&fEM_Z7UE20RRP,&var45,&internal1_m70_tx,&internal1_m70_y0};
_S_or3  S_or3_69_1 = {&A6IS11LRP,&B6IS11LRP,&R0EE02LDU,&var46};
_S_noto  S_noto_67_1 = {&var45,&var47};
_S_zzfs  S_zzfs_78_1 = {&R0EE02LDU,&fEM_Z7UE20RRP,&var48,&internal1_m78_tx,&internal1_m78_y0};
_S_bol  S_bol_41_1 = {&var26,&fEM_R0UL52RSS,&var49};
_S_scalzz  S_scalzz_86_1 = {&B0IT03IRP,&iRM_3200_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var50,&internal1_m86_y0};
_S_scalzz  S_scalzz_84_1 = {&A0IT03IRP,&iRM_3200_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var51,&internal1_m84_y0};
_S_geterr  S_geterr_88_1 = {&var51,&dRM_0_,&iRM_0_,&bRM_0_,&var52,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_100_1 = {&var50,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var53,&internal1_m100_y1};
_S_drg  S_drg_115_1 = {&var50,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var54,&internal1_m115_y1};
_S_geterr  S_geterr_90_1 = {&var50,&dRM_0_,&iRM_0_,&bRM_0_,&var55,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_98_1 = {&var51,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var56,&internal1_m98_y1};
_S_drg  S_drg_112_1 = {&var51,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var57,&internal1_m112_y1};
_S_noto  S_noto_75_1 = {&var17,&var58};
_S_bol  S_bol_61_1 = {&var10,&fEM_R0UR01RRP,&var59};
_S_bol  S_bol_50_1 = {&var11,&fEM_R0UR01RRP,&var60};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  scalzz(&S_scalzz_84_1);
  scalzz(&S_scalzz_86_1);
  or2(&S_or2_66_1);
  diagndev(&S_diagndev_138_1);
  and2(&S_and2_140_1);
  or2(&S_or2_158_1);
  or2(&S_or2_151_1);
  scalzz(&S_scalzz_200_1);
  ffiltr(&S_ffiltr_184_1);
  drg(&S_drg_112_1);
  drg(&S_drg_98_1);
  geterr(&S_geterr_90_1);
  drg(&S_drg_115_1);
  drg(&S_drg_100_1);
  geterr(&S_geterr_88_1);
  zzfs(&S_zzfs_78_1);
  or3(&S_or3_69_1);
  zzfs(&S_zzfs_70_1);
  noto(&S_noto_79_1);
  setData(&var63,&var52);
  or2(&S_or2_95_1);
  setData(&var64,&var55);
  or2(&S_or2_99_1);
  setData(&var65,&var52);
  setData(&var66,&var55);
  or2(&S_or2_94_1);
  orn(&S_orn_156_1);
  or3(&S_or3_155_1);
  noto(&S_noto_157_1);
  pogrvh(&S_pogrvh_169_1);
  pogrvh(&S_pogrvh_171_1);
  pogrvh(&S_pogrvh_173_1);
  pogrvh(&S_pogrvh_175_1);
  pogrvh(&S_pogrvh_185_1);
  scalzz(&S_scalzz_199_1);
  ffiltr(&S_ffiltr_183_1);
  noto(&S_noto_67_1);
  or2(&S_or2_123_1);
  ml(&S_ml_6_1);
  ml(&S_ml_7_1);
  ml(&S_ml_8_1);
  ml(&S_ml_49_1);
  ml(&S_ml_57_1);
  bol(&S_bol_50_1);
  bol(&S_bol_61_1);
  geterr(&S_geterr_55_1);
  geterr(&S_geterr_56_1);
  setData(&var61,&var44);
  and3(&S_and3_59_1);
  setData(&var62,&var42);
  and3(&S_and3_60_1);
  and3(&S_and3_51_1);
  and3(&S_and3_52_1);
  ocham(&S_ocham_18_1);
  and5(&S_and5_43_1);
  noto(&S_noto_75_1);
  bol(&S_bol_41_1);
  and3(&S_and3_44_1);
  or4(&S_or4_48_1);
  or4(&S_or4_71_1);
  setData(idMETRP12,&var3);
  setData(idMETRP06,&var4);
  moveData(idB1VS21LRP,idB1IS21LRP);
  moveData(idA1VS21LRP,idA1IS21LRP);
  setData(idTTLrpu,&var24);
  setData(idTestDiagnRPU,&var20);
  setData(idR0DE3DLRP,&var19);
  setData(idR0DE3CLRP,&var18);
  moveData(idB7MZ31LRP,idC1MZ31LRP);
  moveData(idA7MZ31LRP,idC1MZ31LRP);
  moveData(idB3VS21LRP,idB3IS21LRP);
  moveData(idA3VS21LRP,idA3IS21LRP);
  moveData(idB2VS21LRP,idB2IS21LRP);
  moveData(idA2VS21LRP,idA2IS21LRP);
  setData(idR7VE70LRP,&var15);
  setData(idR0VN13RRP,&var28);
  setData(idR0VN71LRP,&var49);
  setData(idA1VT71LRP,&var35);
  setData(idR0IE04LRP,&var45);
  setData(idR0IE03LRP,&var45);
  setData(idA0EE01LRP,&var17);
  setData(idB0VT71LRP,&var34);
  setData(idB0VT61LRP,&var54);
  setData(idB0CT01IRP,&var50);
  setData(idR0ET02LRP,&var55);
  setData(idR0ET01LRP,&var52);
  setData(idA0VT71LRP,&var36);
  setData(idA0VT61LRP,&var57);
  setData(idA0CT01IRP,&var51);
  setData(idR0IN07RRP,&var5);
  setData(idR7VN71LRP,&var33);
  setData(idR0IN06RRP,&var6);
  setData(idR0IE02LRP,&var48);
  setData(idR0IE01LRP,&var48);
  setData(idR0VN15RRP,&var31);
  setData(idR0VN33RRP,&var30);
  setData(idR0VN23RRP,&var29);
  setData(idA0EE02LRP,&var27);
  setData(idR0IN03RRP,&var1);
  setData(idR0VN03RRP,&var25);
  setData(idR0IN02RRP,&var2);
  setData(idR0IN01RRP,&var9);
  setData(idR0VN02RRP,&var26);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<10;i++ )
    array_m184_x0_1[i] = &(&internal1_m184_x0)[i*5];
  for( i=0;i<10;i++ )
    array_m183_x0_1[i] = &(&internal1_m183_x0)[i*5];
}
void MainCycle(void){
	Scheme();
}
#endif