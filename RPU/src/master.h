#ifndef RPU_H
#define RPU_H
// Подсистема  RPU:RPU
static char SimulOn=0;
static short CodeSub=8;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 //Время цикла мс
float takt,taktScheme=0,taktSS=0;
#define SIZE_BUFFER 690
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
#define R0DE01LRP	BUFFER[71]	// (vchs:01 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 1
#define idR0DE01LRP	31	// (vchs:01 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 1
#define R0DE02LRP	BUFFER[74]	// (vchs:02 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 2
#define idR0DE02LRP	32	// (vchs:02 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 2
#define R0DE03LRP	BUFFER[77]	// (vchs:03 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 3
#define idR0DE03LRP	33	// (vchs:03 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 3
#define R0DE06LRP	BUFFER[80]	// (vas84:06 - Diagn, DiagnRPU) диагностика модуля РПУ-ВАС место 6
#define idR0DE06LRP	34	// (vas84:06 - Diagn, DiagnRPU) диагностика модуля РПУ-ВАС место 6
#define R0DE07LRP	BUFFER[83]	// (vds32:07 - Diagn, DiagnRPU) диагностика модуля РПУ-ВДС место 7
#define idR0DE07LRP	35	// (vds32:07 - Diagn, DiagnRPU) диагностика модуля РПУ-ВДС место 7
#define R0DE08LRP	BUFFER[86]	// (fds16:08 - Diagn, DiagnRPU) диагностика модуля РПУ-ФДС место 8
#define idR0DE08LRP	36	// (fds16:08 - Diagn, DiagnRPU) диагностика модуля РПУ-ФДС место 8
#define R0DE31LRP	BUFFER[89]	// (sbk:20 - S01SBK, DiagnRPU) диагностика шкафа РПУ сеть 1
#define idR0DE31LRP	37	// (sbk:20 - S01SBK, DiagnRPU) диагностика шкафа РПУ сеть 1
#define R0DE32LRP	BUFFER[91]	// (sbk:20 - S02SBK, DiagnRPU) диагностика шкафа РПУ сеть 2
#define idR0DE32LRP	38	// (sbk:20 - S02SBK, DiagnRPU) диагностика шкафа РПУ сеть 2
#define R0DE33LRP	BUFFER[93]	// (sbk:20 - S03SBK, DiagnRPU) диагностика шкафа РПУ двери
#define idR0DE33LRP	39	// (sbk:20 - S03SBK, DiagnRPU) диагностика шкафа РПУ двери
#define R0DE34LRP	BUFFER[95]	// (sbk:20 - S04SBK, DiagnRPU) диагностика шкафа РПУ температура меньше 43
#define idR0DE34LRP	40	// (sbk:20 - S04SBK, DiagnRPU) диагностика шкафа РПУ температура меньше 43
#define R0DE35LRP	BUFFER[97]	// (sbk:20 - S05SBK, DiagnRPU) диагностика шкафа РПУ температура больше 53
#define idR0DE35LRP	41	// (sbk:20 - S05SBK, DiagnRPU) диагностика шкафа РПУ температура больше 53
#define R0DE36LRP	BUFFER[99]	// (sbk:20 - S06SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 1
#define idR0DE36LRP	42	// (sbk:20 - S06SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 1
#define R0DE37LRP	BUFFER[101]	// (sbk:20 - S07SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 2
#define idR0DE37LRP	43	// (sbk:20 - S07SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 2
#define R0DE38LRP	BUFFER[103]	// (sbk:20 - S08SBK, DiagnRPU) диагностика шкафа РПУ МП15-3 место 3
#define idR0DE38LRP	44	// (sbk:20 - S08SBK, DiagnRPU) диагностика шкафа РПУ МП15-3 место 3
#define R0DE39LRP	BUFFER[105]	// (sbk:20 - S09SBK, DiagnRPU) диагностика шкафа РПУ МП24-2 место 4
#define idR0DE39LRP	45	// (sbk:20 - S09SBK, DiagnRPU) диагностика шкафа РПУ МП24-2 место 4
#define R0DE3CLRP	BUFFER[107]	// ( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 7
#define idR0DE3CLRP	46	// ( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 7
#define R0DE3DLRP	BUFFER[109]	// ( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 8
#define idR0DE3DLRP	47	// ( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 8
#define R0DEB1LRP	BUFFER[111]	// (sbk:20 - S10SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 7
#define idR0DEB1LRP	48	// (sbk:20 - S10SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 7
#define R0DEB2LRP	BUFFER[113]	// (sbk:20 - S11SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 7
#define idR0DEB2LRP	49	// (sbk:20 - S11SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 7
#define R0DEB3LRP	BUFFER[115]	// (sbk:20 - S12SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 8
#define idR0DEB3LRP	50	// (sbk:20 - S12SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 8
#define R0DEB4LRP	BUFFER[117]	// (sbk:20 - S13SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 8
#define idR0DEB4LRP	51	// (sbk:20 - S13SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 8
#define R0EE02LDU	BUFFER[119]	// ( - , RPU) Питание  АКНП  отключить
#define idR0EE02LDU	52	// ( - , RPU) Питание  АКНП  отключить
#define R0ET01LRP	BUFFER[121]	// ( - , RPU) Признак наличия неисправности по температуре  АЗ1-3
#define idR0ET01LRP	53	// ( - , RPU) Признак наличия неисправности по температуре  АЗ1-3
#define R0ET02LRP	BUFFER[123]	// ( - , RPU) Признак наличия неисправности по температуре АЗ2-3
#define idR0ET02LRP	54	// ( - , RPU) Признак наличия неисправности по температуре АЗ2-3
#define R0IE01LRP	BUFFER[125]	// (fds16:08 - K08FDSR, - ) Отключение питание детекторов канал 5
#define idR0IE01LRP	55	// (fds16:08 - K08FDSR, - ) Отключение питание детекторов канал 5
#define R0IE02LRP	BUFFER[127]	// (fds16:08 - K07FDSR, - ) Отключить питание ПР, ПУ канал 5
#define idR0IE02LRP	56	// (fds16:08 - K07FDSR, - ) Отключить питание ПР, ПУ канал 5
#define R0IE03LRP	BUFFER[129]	// (fds16:08 - K09FDSR, - ) Отключение питание детекторов канал  6,7
#define idR0IE03LRP	57	// (fds16:08 - K09FDSR, - ) Отключение питание детекторов канал  6,7
#define R0IE04LRP	BUFFER[131]	// (fds16:08 - K10FDSR, - ) Отключить питание ПР, ПУ канал 6,7
#define idR0IE04LRP	58	// (fds16:08 - K10FDSR, - ) Отключить питание ПР, ПУ канал 6,7
#define R0IE11LRP	BUFFER[133]	// (vds32:07 - K03VDSR, - ) Исправность ВИП 1,6 (№20) СНМ11 5 канала
#define idR0IE11LRP	59	// (vds32:07 - K03VDSR, - ) Исправность ВИП 1,6 (№20) СНМ11 5 канала
#define R0IE12LRP	BUFFER[135]	// (vds32:07 - K04VDSR, - ) Исправность ВИП 0,5 -5к (№21)
#define idR0IE12LRP	60	// (vds32:07 - K04VDSR, - ) Исправность ВИП 0,5 -5к (№21)
#define R0IE13LRP	BUFFER[137]	// (vds32:07 - K05VDSR, - ) Исправность ВИП 0,5 -5к (№22)
#define idR0IE13LRP	61	// (vds32:07 - K05VDSR, - ) Исправность ВИП 0,5 -5к (№22)
#define R0IE14LRP	BUFFER[139]	// (vds32:07 - K01VDSR, - ) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
#define idR0IE14LRP	62	// (vds32:07 - K01VDSR, - ) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
#define R0IE15LRP	BUFFER[141]	// (vds32:07 - K02VDSR, - ) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
#define idR0IE15LRP	63	// (vds32:07 - K02VDSR, - ) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
#define R0IN01RIP	BUFFER[143]	// ( - , MRPS) Частота СНМ-11 Гц (канал 5) от ПТИ
#define idR0IN01RIP	64	// ( - , MRPS) Частота СНМ-11 Гц (канал 5) от ПТИ
#define R0IN01RRP	BUFFER[148]	// ( - , RPU) Частота СНМ-11 Гц (канал 5)
#define idR0IN01RRP	65	// ( - , RPU) Частота СНМ-11 Гц (канал 5)
#define R0IN01VRP	BUFFER[153]	// (vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
#define idR0IN01VRP	66	// (vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
#define R0IN02RIP	BUFFER[158]	// ( - , MRPS) Частота КНК15-1 Гц (канал 5) от ПТИ
#define idR0IN02RIP	67	// ( - , MRPS) Частота КНК15-1 Гц (канал 5) от ПТИ
#define R0IN02RRP	BUFFER[163]	// ( - , RPU) Частота КНК15-1 Гц (канал 5)
#define idR0IN02RRP	68	// ( - , RPU) Частота КНК15-1 Гц (канал 5)
#define R0IN02VRP	BUFFER[168]	// (vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
#define idR0IN02VRP	69	// (vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
#define R0IN03RIP	BUFFER[173]	// ( - , MRPS) Частота КНК53М Гц (канал 5) от ПТИ
#define idR0IN03RIP	70	// ( - , MRPS) Частота КНК53М Гц (канал 5) от ПТИ
#define R0IN03RRP	BUFFER[178]	// ( - , RPU) Частота КНК53М Гц (канал 5)
#define idR0IN03RRP	71	// ( - , RPU) Частота КНК53М Гц (канал 5)
#define R0IN03VRP	BUFFER[183]	// (vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
#define idR0IN03VRP	72	// (vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
#define R0IN06RIP	BUFFER[188]	// ( - , MRPS) Частота СНМ-11 Гц (канал 6) от ПТИ
#define idR0IN06RIP	73	// ( - , MRPS) Частота СНМ-11 Гц (канал 6) от ПТИ
#define R0IN06RRP	BUFFER[193]	// ( - , RPU) Частота СНМ-11 Гц (канал 6) от ПТИ
#define idR0IN06RRP	74	// ( - , RPU) Частота СНМ-11 Гц (канал 6) от ПТИ
#define R0IN06VRP	BUFFER[198]	// (vchs:03 - K01VCHS, - ) Частота с ВЧС к 6
#define idR0IN06VRP	75	// (vchs:03 - K01VCHS, - ) Частота с ВЧС к 6
#define R0IN07RIP	BUFFER[203]	// ( - , MRPS) Частота СНМ-11 Гц (канал 7) от ПТИ
#define idR0IN07RIP	76	// ( - , MRPS) Частота СНМ-11 Гц (канал 7) от ПТИ
#define R0IN07RRP	BUFFER[208]	// ( - , RPU) Частота СНМ-11 Гц (канал 7)
#define idR0IN07RRP	77	// ( - , RPU) Частота СНМ-11 Гц (канал 7)
#define R0IN07VRP	BUFFER[213]	// (vchs:03 - K02VCHS, - ) Частота с ВЧС к 7
#define idR0IN07VRP	78	// (vchs:03 - K02VCHS, - ) Частота с ВЧС к 7
#define R0IS01FI0	BUFFER[218]	// ( - , MRPS) Признак работы с имитатором
#define idR0IS01FI0	79	// ( - , MRPS) Признак работы с имитатором
#define R0VN02RRP	BUFFER[220]	// ( - , RPU) Уровень мощности канал 5
#define idR0VN02RRP	80	// ( - , RPU) Уровень мощности канал 5
#define R0VN03RRP	BUFFER[225]	// ( - , RPU) Измеренный нейтронный поток канал 5
#define idR0VN03RRP	81	// ( - , RPU) Измеренный нейтронный поток канал 5
#define R0VN13RRP	BUFFER[230]	// ( - , RPU) Нейтронный поток по камере  СНМ-11 канал 5
#define idR0VN13RRP	82	// ( - , RPU) Нейтронный поток по камере  СНМ-11 канал 5
#define R0VN15RRP	BUFFER[235]	// ( - , RPU) Номер ведущей камеры канал 5
#define idR0VN15RRP	83	// ( - , RPU) Номер ведущей камеры канал 5
#define R0VN23RRP	BUFFER[238]	// ( - , RPU) Нейтронный поток по камере КНК15-1 канал 5
#define idR0VN23RRP	84	// ( - , RPU) Нейтронный поток по камере КНК15-1 канал 5
#define R0VN33RRP	BUFFER[243]	// ( - , RPU) Нейтронный поток по камере КНК53М канал 5
#define idR0VN33RRP	85	// ( - , RPU) Нейтронный поток по камере КНК53М канал 5
#define R0VN71LRP	BUFFER[248]	// (fds16:08 - K12FDSR, - ) АС по мощности канал 5
#define idR0VN71LRP	86	// (fds16:08 - K12FDSR, - ) АС по мощности канал 5
#define R7VE70LRP	BUFFER[250]	// ( - , RPU) Сигнал тревоги по неисправности РПУ на диспетчера
#define idR7VE70LRP	87	// ( - , RPU) Сигнал тревоги по неисправности РПУ на диспетчера
#define R7VN71LRP	BUFFER[252]	// ( - , RPU) Сигнал тревоги по уровню нейтронного потока на диспетчера
#define idR7VN71LRP	88	// ( - , RPU) Сигнал тревоги по уровню нейтронного потока на диспетчера
#define TTLrpu	BUFFER[254]	// ( - , RPU) ttl
#define idTTLrpu	89	// ( - , RPU) ttl
#define TestDiagnRPU	BUFFER[257]	// ( - , RPU) Неисправность от диагностики
#define idTestDiagnRPU	90	// ( - , RPU) Неисправность от диагностики
#define bFirstEnterFlag	BUFFER[259]	// (bFirstEnterFlag) 
#define idbFirstEnterFlag	91	// (bFirstEnterFlag) 
#define fEM_A0UX00RSS	BUFFER[261]	// (A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	92	// (A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX13RSS	BUFFER[266]	// (A0UX13RSS) Первый коэффициент калибровки камеры 13
#define idfEM_A0UX13RSS	93	// (A0UX13RSS) Первый коэффициент калибровки камеры 13
#define fEM_A0UX14RSS	BUFFER[271]	// (A0UX14RSS) Первый коэффициент калибровки камеры 14
#define idfEM_A0UX14RSS	94	// (A0UX14RSS) Первый коэффициент калибровки камеры 14
#define fEM_A0UX15RSS	BUFFER[276]	// (A0UX15RSS) Первый коэффициент калибровки камеры 15
#define idfEM_A0UX15RSS	95	// (A0UX15RSS) Первый коэффициент калибровки камеры 15
#define fEM_B0UX03RSS	BUFFER[281]	// (B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	96	// (B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	BUFFER[286]	// (B0UX04RSS) Второй коэффициент калибровки камеры4
#define idfEM_B0UX04RSS	97	// (B0UX04RSS) Второй коэффициент калибровки камеры4
#define fEM_B0UX05RSS	BUFFER[291]	// (B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	98	// (B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_R0IN11NRP	BUFFER[296]	// (R0IN11NRP) Коэффициент A (РПУ к 1)
#define idfEM_R0IN11NRP	99	// (R0IN11NRP) Коэффициент A (РПУ к 1)
#define fEM_R0IN12NRP	BUFFER[301]	// (R0IN12NRP) Коэффициент B (РПУ к 1)
#define idfEM_R0IN12NRP	100	// (R0IN12NRP) Коэффициент B (РПУ к 1)
#define fEM_R0IN21NRP	BUFFER[306]	// (R0IN21NRP) Коэффициент A (РПУ к 2)
#define idfEM_R0IN21NRP	101	// (R0IN21NRP) Коэффициент A (РПУ к 2)
#define fEM_R0IN22NRP	BUFFER[311]	// (R0IN22NRP) Коэффициент B (РПУ к 2)
#define idfEM_R0IN22NRP	102	// (R0IN22NRP) Коэффициент B (РПУ к 2)
#define fEM_R0IN31NRP	BUFFER[316]	// (R0IN31NRP) Коэффициент A (РПУ к 3)
#define idfEM_R0IN31NRP	103	// (R0IN31NRP) Коэффициент A (РПУ к 3)
#define fEM_R0IN32NRP	BUFFER[321]	// (R0IN32NRP) Коэффициент B (РПУ к 3)
#define idfEM_R0IN32NRP	104	// (R0IN32NRP) Коэффициент B (РПУ к 3)
#define fEM_R0IN61NRP	BUFFER[326]	// (R0IN61NRP) Коэффициент A (РПУ к 6)
#define idfEM_R0IN61NRP	105	// (R0IN61NRP) Коэффициент A (РПУ к 6)
#define fEM_R0IN62NRP	BUFFER[331]	// (R0IN62NRP) Коэффициент B (РПУ к 6)
#define idfEM_R0IN62NRP	106	// (R0IN62NRP) Коэффициент B (РПУ к 6)
#define fEM_R0IN71NRP	BUFFER[336]	// (R0IN71NRP) Коэффициент A (РПУ к 7)
#define idfEM_R0IN71NRP	107	// (R0IN71NRP) Коэффициент A (РПУ к 7)
#define fEM_R0IN72NRP	BUFFER[341]	// (R0IN72NRP) Коэффициент B (РПУ к 7)
#define idfEM_R0IN72NRP	108	// (R0IN72NRP) Коэффициент B (РПУ к 7)
#define fEM_R0UH02RSS	BUFFER[346]	// (R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define idfEM_R0UH02RSS	109	// (R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define fEM_R0UH03RSS	BUFFER[351]	// (R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define idfEM_R0UH03RSS	110	// (R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define fEM_R0UH05RSS	BUFFER[356]	// (R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	111	// (R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UH21RSS	BUFFER[361]	// (R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	112	// (R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	BUFFER[366]	// (R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	113	// (R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	BUFFER[371]	// (R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	114	// (R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0UL52RSS	BUFFER[376]	// (R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	115	// (R0UL52RSS) Уровень АС по мощности
#define fEM_R0UR01RRP	BUFFER[381]	// (R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
#define idfEM_R0UR01RRP	116	// (R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
#define fEM_R0UT01RZZ	BUFFER[386]	// (R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	117	// (R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_R0UT02RZZ	BUFFER[391]	// (R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	118	// (R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT61RZZ	BUFFER[396]	// (R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	119	// (R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	BUFFER[401]	// (R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	120	// (R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	BUFFER[406]	// (R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	121	// (R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT72RZZ	BUFFER[411]	// (R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	122	// (R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define fEM_R7UX00RSS	BUFFER[416]	// (R7UX00RSS) X-координата АЗ1 (см)
#define idfEM_R7UX00RSS	123	// (R7UX00RSS) X-координата АЗ1 (см)
#define fEM_R7UX13RSS	BUFFER[421]	// (R7UX13RSS) X-координата камеры R7IN51
#define idfEM_R7UX13RSS	124	// (R7UX13RSS) X-координата камеры R7IN51
#define fEM_R7UX14RSS	BUFFER[426]	// (R7UX14RSS) X-координата камеры R7IN52
#define idfEM_R7UX14RSS	125	// (R7UX14RSS) X-координата камеры R7IN52
#define fEM_R7UX15RSS	BUFFER[431]	// (R7UX15RSS) X-координата камеры R7IN53
#define idfEM_R7UX15RSS	126	// (R7UX15RSS) X-координата камеры R7IN53
#define fEM_R7UY00RSS	BUFFER[436]	// (R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	127	// (R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UY13RSS	BUFFER[441]	// (R7UY13RSS) Y-координата камеры R7IN51
#define idfEM_R7UY13RSS	128	// (R7UY13RSS) Y-координата камеры R7IN51
#define fEM_R7UY14RSS	BUFFER[446]	// (R7UY14RSS) Y-координата камеры R7IN52
#define idfEM_R7UY14RSS	129	// (R7UY14RSS) Y-координата камеры R7IN52
#define fEM_R7UY15RSS	BUFFER[451]	// (R7UY15RSS) Y-координата камеры R7IN53
#define idfEM_R7UY15RSS	130	// (R7UY15RSS) Y-координата камеры R7IN53
#define fEM_Z7UE20RRP	BUFFER[456]	// (Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
#define idfEM_Z7UE20RRP	131	// (Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
#define internal1_m100_y1	BUFFER[461]	// (internal1_m100_y1) y1 - внутренний параметр
#define idinternal1_m100_y1	132	// (internal1_m100_y1) y1 - внутренний параметр
#define internal1_m111_y1	BUFFER[463]	// (internal1_m111_y1) y1 - внутренний параметр
#define idinternal1_m111_y1	133	// (internal1_m111_y1) y1 - внутренний параметр
#define internal1_m115_y1	BUFFER[465]	// (internal1_m115_y1) y1 - внутренний параметр
#define idinternal1_m115_y1	134	// (internal1_m115_y1) y1 - внутренний параметр
#define internal1_m18_Nk	BUFFER[467]	// (internal1_m18_Nk) Nk - ведущая камера
#define idinternal1_m18_Nk	135	// (internal1_m18_Nk) Nk - ведущая камера
#define internal1_m70_tx	BUFFER[470]	// (internal1_m70_tx) tx - время накопленное сек
#define idinternal1_m70_tx	136	// (internal1_m70_tx) tx - время накопленное сек
#define internal1_m70_y0	BUFFER[475]	// (internal1_m70_y0) y0
#define idinternal1_m70_y0	137	// (internal1_m70_y0) y0
#define internal1_m78_tx	BUFFER[477]	// (internal1_m78_tx) tx - время накопленное сек
#define idinternal1_m78_tx	138	// (internal1_m78_tx) tx - время накопленное сек
#define internal1_m78_y0	BUFFER[482]	// (internal1_m78_y0) y0
#define idinternal1_m78_y0	139	// (internal1_m78_y0) y0
#define internal1_m84_y0	BUFFER[484]	// (internal1_m84_y0) y0
#define idinternal1_m84_y0	140	// (internal1_m84_y0) y0
#define internal1_m86_y0	BUFFER[489]	// (internal1_m86_y0) y0
#define idinternal1_m86_y0	141	// (internal1_m86_y0) y0
#define internal1_m98_y1	BUFFER[494]	// (internal1_m98_y1) y1 - внутренний параметр
#define idinternal1_m98_y1	142	// (internal1_m98_y1) y1 - внутренний параметр
#define vainSBool	BUFFER[496]	// Внутренняя переменная vainSBool
#define idvainSBool	143	// Внутренняя переменная vainSBool
#define vainSFloat	BUFFER[498]	// Внутренняя переменная vainSFloat
#define idvainSFloat	144	// Внутренняя переменная vainSFloat
#define vainSInt	BUFFER[503]	// Внутренняя переменная vainSInt
#define idvainSInt	145	// Внутренняя переменная vainSInt
#define vainSLong	BUFFER[508]	// Внутренняя переменная vainSLong
#define idvainSLong	146	// Внутренняя переменная vainSLong
#define var1	BUFFER[517]	// Внутренняя переменная var1
#define idvar1	147	// Внутренняя переменная var1
#define var10	BUFFER[522]	// Внутренняя переменная var10
#define idvar10	148	// Внутренняя переменная var10
#define var11	BUFFER[527]	// Внутренняя переменная var11
#define idvar11	149	// Внутренняя переменная var11
#define var12	BUFFER[529]	// Внутренняя переменная var12
#define idvar12	150	// Внутренняя переменная var12
#define var13	BUFFER[531]	// Внутренняя переменная var13
#define idvar13	151	// Внутренняя переменная var13
#define var14	BUFFER[533]	// Внутренняя переменная var14
#define idvar14	152	// Внутренняя переменная var14
#define var15	BUFFER[535]	// Внутренняя переменная var15
#define idvar15	153	// Внутренняя переменная var15
#define var16	BUFFER[537]	// Внутренняя переменная var16
#define idvar16	154	// Внутренняя переменная var16
#define var17	BUFFER[539]	// Внутренняя переменная var17
#define idvar17	155	// Внутренняя переменная var17
#define var18	BUFFER[541]	// Внутренняя переменная var18
#define idvar18	156	// Внутренняя переменная var18
#define var19	BUFFER[543]	// Внутренняя переменная var19
#define idvar19	157	// Внутренняя переменная var19
#define var2	BUFFER[545]	// Внутренняя переменная var2
#define idvar2	158	// Внутренняя переменная var2
#define var20	BUFFER[550]	// Внутренняя переменная var20
#define idvar20	159	// Внутренняя переменная var20
#define var21	BUFFER[555]	// Внутренняя переменная var21
#define idvar21	160	// Внутренняя переменная var21
#define var22	BUFFER[560]	// Внутренняя переменная var22
#define idvar22	161	// Внутренняя переменная var22
#define var23	BUFFER[565]	// Внутренняя переменная var23
#define idvar23	162	// Внутренняя переменная var23
#define var24	BUFFER[567]	// Внутренняя переменная var24
#define idvar24	163	// Внутренняя переменная var24
#define var25	BUFFER[572]	// Внутренняя переменная var25
#define idvar25	164	// Внутренняя переменная var25
#define var26	BUFFER[577]	// Внутренняя переменная var26
#define idvar26	165	// Внутренняя переменная var26
#define var27	BUFFER[582]	// Внутренняя переменная var27
#define idvar27	166	// Внутренняя переменная var27
#define var28	BUFFER[587]	// Внутренняя переменная var28
#define idvar28	167	// Внутренняя переменная var28
#define var29	BUFFER[589]	// Внутренняя переменная var29
#define idvar29	168	// Внутренняя переменная var29
#define var3	BUFFER[591]	// Внутренняя переменная var3
#define idvar3	169	// Внутренняя переменная var3
#define var30	BUFFER[596]	// Внутренняя переменная var30
#define idvar30	170	// Внутренняя переменная var30
#define var31	BUFFER[598]	// Внутренняя переменная var31
#define idvar31	171	// Внутренняя переменная var31
#define var32	BUFFER[600]	// Внутренняя переменная var32
#define idvar32	172	// Внутренняя переменная var32
#define var33	BUFFER[602]	// Внутренняя переменная var33
#define idvar33	173	// Внутренняя переменная var33
#define var34	BUFFER[604]	// Внутренняя переменная var34
#define idvar34	174	// Внутренняя переменная var34
#define var35	BUFFER[606]	// Внутренняя переменная var35
#define idvar35	175	// Внутренняя переменная var35
#define var36	BUFFER[608]	// Внутренняя переменная var36
#define idvar36	176	// Внутренняя переменная var36
#define var37	BUFFER[610]	// Внутренняя переменная var37
#define idvar37	177	// Внутренняя переменная var37
#define var39	BUFFER[612]	// Внутренняя переменная var39
#define idvar39	178	// Внутренняя переменная var39
#define var4	BUFFER[614]	// Внутренняя переменная var4
#define idvar4	179	// Внутренняя переменная var4
#define var41	BUFFER[619]	// Внутренняя переменная var41
#define idvar41	180	// Внутренняя переменная var41
#define var42	BUFFER[621]	// Внутренняя переменная var42
#define idvar42	181	// Внутренняя переменная var42
#define var43	BUFFER[623]	// Внутренняя переменная var43
#define idvar43	182	// Внутренняя переменная var43
#define var44	BUFFER[625]	// Внутренняя переменная var44
#define idvar44	183	// Внутренняя переменная var44
#define var45	BUFFER[627]	// Внутренняя переменная var45
#define idvar45	184	// Внутренняя переменная var45
#define var46	BUFFER[629]	// Внутренняя переменная var46
#define idvar46	185	// Внутренняя переменная var46
#define var47	BUFFER[634]	// Внутренняя переменная var47
#define idvar47	186	// Внутренняя переменная var47
#define var49	BUFFER[639]	// Внутренняя переменная var49
#define idvar49	187	// Внутренняя переменная var49
#define var5	BUFFER[641]	// Внутренняя переменная var5
#define idvar5	188	// Внутренняя переменная var5
#define var50	BUFFER[646]	// Внутренняя переменная var50
#define idvar50	189	// Внутренняя переменная var50
#define var52	BUFFER[648]	// Внутренняя переменная var52
#define idvar52	190	// Внутренняя переменная var52
#define var53	BUFFER[650]	// Внутренняя переменная var53
#define idvar53	191	// Внутренняя переменная var53
#define var54	BUFFER[652]	// Внутренняя переменная var54
#define idvar54	192	// Внутренняя переменная var54
#define var55	BUFFER[654]	// Внутренняя переменная var55
#define idvar55	193	// Внутренняя переменная var55
#define var56	BUFFER[656]	// Внутренняя переменная var56
#define idvar56	194	// Внутренняя переменная var56
#define var57	BUFFER[658]	// Внутренняя переменная var57
#define idvar57	195	// Внутренняя переменная var57
#define var58	BUFFER[660]	// Внутренняя переменная var58
#define idvar58	196	// Внутренняя переменная var58
#define var59	BUFFER[662]	// Внутренняя переменная var59
#define idvar59	197	// Внутренняя переменная var59
#define var6	BUFFER[664]	// Внутренняя переменная var6
#define idvar6	198	// Внутренняя переменная var6
#define var60	BUFFER[669]	// Внутренняя переменная var60
#define idvar60	199	// Внутренняя переменная var60
#define var61	BUFFER[671]	// Внутренняя переменная var61
#define idvar61	200	// Внутренняя переменная var61
#define var62	BUFFER[673]	// Внутренняя переменная var62
#define idvar62	201	// Внутренняя переменная var62
#define var7	BUFFER[675]	// Внутренняя переменная var7
#define idvar7	202	// Внутренняя переменная var7
#define var8	BUFFER[680]	// Внутренняя переменная var8
#define idvar8	203	// Внутренняя переменная var8
#define var9	BUFFER[685]	// Внутренняя переменная var9
#define idvar9	204	// Внутренняя переменная var9
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
	{31	,3	,1	,&R0DE01LRP},	//(vchs:01 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 1
	{32	,3	,1	,&R0DE02LRP},	//(vchs:02 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 2
	{33	,3	,1	,&R0DE03LRP},	//(vchs:03 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 3
	{34	,3	,1	,&R0DE06LRP},	//(vas84:06 - Diagn, DiagnRPU) диагностика модуля РПУ-ВАС место 6
	{35	,3	,1	,&R0DE07LRP},	//(vds32:07 - Diagn, DiagnRPU) диагностика модуля РПУ-ВДС место 7
	{36	,3	,1	,&R0DE08LRP},	//(fds16:08 - Diagn, DiagnRPU) диагностика модуля РПУ-ФДС место 8
	{37	,1	,1	,&R0DE31LRP},	//(sbk:20 - S01SBK, DiagnRPU) диагностика шкафа РПУ сеть 1
	{38	,1	,1	,&R0DE32LRP},	//(sbk:20 - S02SBK, DiagnRPU) диагностика шкафа РПУ сеть 2
	{39	,1	,1	,&R0DE33LRP},	//(sbk:20 - S03SBK, DiagnRPU) диагностика шкафа РПУ двери
	{40	,1	,1	,&R0DE34LRP},	//(sbk:20 - S04SBK, DiagnRPU) диагностика шкафа РПУ температура меньше 43
	{41	,1	,1	,&R0DE35LRP},	//(sbk:20 - S05SBK, DiagnRPU) диагностика шкафа РПУ температура больше 53
	{42	,1	,1	,&R0DE36LRP},	//(sbk:20 - S06SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 1
	{43	,1	,1	,&R0DE37LRP},	//(sbk:20 - S07SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 2
	{44	,1	,1	,&R0DE38LRP},	//(sbk:20 - S08SBK, DiagnRPU) диагностика шкафа РПУ МП15-3 место 3
	{45	,1	,1	,&R0DE39LRP},	//(sbk:20 - S09SBK, DiagnRPU) диагностика шкафа РПУ МП24-2 место 4
	{46	,1	,1	,&R0DE3CLRP},	//( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 7
	{47	,1	,1	,&R0DE3DLRP},	//( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 8
	{48	,1	,1	,&R0DEB1LRP},	//(sbk:20 - S10SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 7
	{49	,1	,1	,&R0DEB2LRP},	//(sbk:20 - S11SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 7
	{50	,1	,1	,&R0DEB3LRP},	//(sbk:20 - S12SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 8
	{51	,1	,1	,&R0DEB4LRP},	//(sbk:20 - S13SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 8
	{52	,1	,1	,&R0EE02LDU},	//( - , RPU) Питание  АКНП  отключить
	{53	,1	,1	,&R0ET01LRP},	//( - , RPU) Признак наличия неисправности по температуре  АЗ1-3
	{54	,1	,1	,&R0ET02LRP},	//( - , RPU) Признак наличия неисправности по температуре АЗ2-3
	{55	,1	,1	,&R0IE01LRP},	//(fds16:08 - K08FDSR, - ) Отключение питание детекторов канал 5
	{56	,1	,1	,&R0IE02LRP},	//(fds16:08 - K07FDSR, - ) Отключить питание ПР, ПУ канал 5
	{57	,1	,1	,&R0IE03LRP},	//(fds16:08 - K09FDSR, - ) Отключение питание детекторов канал  6,7
	{58	,1	,1	,&R0IE04LRP},	//(fds16:08 - K10FDSR, - ) Отключить питание ПР, ПУ канал 6,7
	{59	,1	,1	,&R0IE11LRP},	//(vds32:07 - K03VDSR, - ) Исправность ВИП 1,6 (№20) СНМ11 5 канала
	{60	,1	,1	,&R0IE12LRP},	//(vds32:07 - K04VDSR, - ) Исправность ВИП 0,5 -5к (№21)
	{61	,1	,1	,&R0IE13LRP},	//(vds32:07 - K05VDSR, - ) Исправность ВИП 0,5 -5к (№22)
	{62	,1	,1	,&R0IE14LRP},	//(vds32:07 - K01VDSR, - ) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
	{63	,1	,1	,&R0IE15LRP},	//(vds32:07 - K02VDSR, - ) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
	{64	,8	,1	,&R0IN01RIP},	//( - , MRPS) Частота СНМ-11 Гц (канал 5) от ПТИ
	{65	,8	,1	,&R0IN01RRP},	//( - , RPU) Частота СНМ-11 Гц (канал 5)
	{66	,8	,1	,&R0IN01VRP},	//(vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
	{67	,8	,1	,&R0IN02RIP},	//( - , MRPS) Частота КНК15-1 Гц (канал 5) от ПТИ
	{68	,8	,1	,&R0IN02RRP},	//( - , RPU) Частота КНК15-1 Гц (канал 5)
	{69	,8	,1	,&R0IN02VRP},	//(vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
	{70	,8	,1	,&R0IN03RIP},	//( - , MRPS) Частота КНК53М Гц (канал 5) от ПТИ
	{71	,8	,1	,&R0IN03RRP},	//( - , RPU) Частота КНК53М Гц (канал 5)
	{72	,8	,1	,&R0IN03VRP},	//(vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
	{73	,8	,1	,&R0IN06RIP},	//( - , MRPS) Частота СНМ-11 Гц (канал 6) от ПТИ
	{74	,8	,1	,&R0IN06RRP},	//( - , RPU) Частота СНМ-11 Гц (канал 6) от ПТИ
	{75	,8	,1	,&R0IN06VRP},	//(vchs:03 - K01VCHS, - ) Частота с ВЧС к 6
	{76	,8	,1	,&R0IN07RIP},	//( - , MRPS) Частота СНМ-11 Гц (канал 7) от ПТИ
	{77	,8	,1	,&R0IN07RRP},	//( - , RPU) Частота СНМ-11 Гц (канал 7)
	{78	,8	,1	,&R0IN07VRP},	//(vchs:03 - K02VCHS, - ) Частота с ВЧС к 7
	{79	,1	,1	,&R0IS01FI0},	//( - , MRPS) Признак работы с имитатором
	{80	,8	,1	,&R0VN02RRP},	//( - , RPU) Уровень мощности канал 5
	{81	,8	,1	,&R0VN03RRP},	//( - , RPU) Измеренный нейтронный поток канал 5
	{82	,8	,1	,&R0VN13RRP},	//( - , RPU) Нейтронный поток по камере  СНМ-11 канал 5
	{83	,3	,1	,&R0VN15RRP},	//( - , RPU) Номер ведущей камеры канал 5
	{84	,8	,1	,&R0VN23RRP},	//( - , RPU) Нейтронный поток по камере КНК15-1 канал 5
	{85	,8	,1	,&R0VN33RRP},	//( - , RPU) Нейтронный поток по камере КНК53М канал 5
	{86	,1	,1	,&R0VN71LRP},	//(fds16:08 - K12FDSR, - ) АС по мощности канал 5
	{87	,1	,1	,&R7VE70LRP},	//( - , RPU) Сигнал тревоги по неисправности РПУ на диспетчера
	{88	,1	,1	,&R7VN71LRP},	//( - , RPU) Сигнал тревоги по уровню нейтронного потока на диспетчера
	{89	,3	,1	,&TTLrpu},	//( - , RPU) ttl
	{90	,1	,1	,&TestDiagnRPU},	//( - , RPU) Неисправность от диагностики
	{91	,1	,1	,&bFirstEnterFlag},	//(bFirstEnterFlag) 
	{92	,8	,1	,&fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{93	,8	,1	,&fEM_A0UX13RSS},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{94	,8	,1	,&fEM_A0UX14RSS},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{95	,8	,1	,&fEM_A0UX15RSS},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{96	,8	,1	,&fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{97	,8	,1	,&fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры4
	{98	,8	,1	,&fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{99	,8	,1	,&fEM_R0IN11NRP},	//(R0IN11NRP) Коэффициент A (РПУ к 1)
	{100	,8	,1	,&fEM_R0IN12NRP},	//(R0IN12NRP) Коэффициент B (РПУ к 1)
	{101	,8	,1	,&fEM_R0IN21NRP},	//(R0IN21NRP) Коэффициент A (РПУ к 2)
	{102	,8	,1	,&fEM_R0IN22NRP},	//(R0IN22NRP) Коэффициент B (РПУ к 2)
	{103	,8	,1	,&fEM_R0IN31NRP},	//(R0IN31NRP) Коэффициент A (РПУ к 3)
	{104	,8	,1	,&fEM_R0IN32NRP},	//(R0IN32NRP) Коэффициент B (РПУ к 3)
	{105	,8	,1	,&fEM_R0IN61NRP},	//(R0IN61NRP) Коэффициент A (РПУ к 6)
	{106	,8	,1	,&fEM_R0IN62NRP},	//(R0IN62NRP) Коэффициент B (РПУ к 6)
	{107	,8	,1	,&fEM_R0IN71NRP},	//(R0IN71NRP) Коэффициент A (РПУ к 7)
	{108	,8	,1	,&fEM_R0IN72NRP},	//(R0IN72NRP) Коэффициент B (РПУ к 7)
	{109	,8	,1	,&fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{110	,8	,1	,&fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{111	,8	,1	,&fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{112	,8	,1	,&fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{113	,8	,1	,&fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{114	,8	,1	,&fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{115	,8	,1	,&fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{116	,8	,1	,&fEM_R0UR01RRP},	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
	{117	,8	,1	,&fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{118	,8	,1	,&fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{119	,8	,1	,&fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{120	,8	,1	,&fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{121	,8	,1	,&fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{122	,8	,1	,&fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{123	,8	,1	,&fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{124	,8	,1	,&fEM_R7UX13RSS},	//(R7UX13RSS) X-координата камеры R7IN51
	{125	,8	,1	,&fEM_R7UX14RSS},	//(R7UX14RSS) X-координата камеры R7IN52
	{126	,8	,1	,&fEM_R7UX15RSS},	//(R7UX15RSS) X-координата камеры R7IN53
	{127	,8	,1	,&fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{128	,8	,1	,&fEM_R7UY13RSS},	//(R7UY13RSS) Y-координата камеры R7IN51
	{129	,8	,1	,&fEM_R7UY14RSS},	//(R7UY14RSS) Y-координата камеры R7IN52
	{130	,8	,1	,&fEM_R7UY15RSS},	//(R7UY15RSS) Y-координата камеры R7IN53
	{131	,8	,1	,&fEM_Z7UE20RRP},	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
	{132	,1	,1	,&internal1_m100_y1},	//(internal1_m100_y1) y1 - внутренний параметр
	{133	,1	,1	,&internal1_m111_y1},	//(internal1_m111_y1) y1 - внутренний параметр
	{134	,1	,1	,&internal1_m115_y1},	//(internal1_m115_y1) y1 - внутренний параметр
	{135	,3	,1	,&internal1_m18_Nk},	//(internal1_m18_Nk) Nk - ведущая камера
	{136	,8	,1	,&internal1_m70_tx},	//(internal1_m70_tx) tx - время накопленное сек
	{137	,18	,1	,&internal1_m70_y0},	//(internal1_m70_y0) y0
	{138	,8	,1	,&internal1_m78_tx},	//(internal1_m78_tx) tx - время накопленное сек
	{139	,18	,1	,&internal1_m78_y0},	//(internal1_m78_y0) y0
	{140	,8	,1	,&internal1_m84_y0},	//(internal1_m84_y0) y0
	{141	,8	,1	,&internal1_m86_y0},	//(internal1_m86_y0) y0
	{142	,1	,1	,&internal1_m98_y1},	//(internal1_m98_y1) y1 - внутренний параметр
	{143	,1	,1	,&vainSBool},	//Внутренняя переменная vainSBool
	{144	,8	,1	,&vainSFloat},	//Внутренняя переменная vainSFloat
	{145	,5	,1	,&vainSInt},	//Внутренняя переменная vainSInt
	{146	,11	,1	,&vainSLong},	//Внутренняя переменная vainSLong
	{147	,8	,1	,&var1},	//Внутренняя переменная var1
	{148	,8	,1	,&var10},	//Внутренняя переменная var10
	{149	,1	,1	,&var11},	//Внутренняя переменная var11
	{150	,1	,1	,&var12},	//Внутренняя переменная var12
	{151	,1	,1	,&var13},	//Внутренняя переменная var13
	{152	,1	,1	,&var14},	//Внутренняя переменная var14
	{153	,1	,1	,&var15},	//Внутренняя переменная var15
	{154	,1	,1	,&var16},	//Внутренняя переменная var16
	{155	,1	,1	,&var17},	//Внутренняя переменная var17
	{156	,1	,1	,&var18},	//Внутренняя переменная var18
	{157	,1	,1	,&var19},	//Внутренняя переменная var19
	{158	,8	,1	,&var2},	//Внутренняя переменная var2
	{159	,5	,1	,&var20},	//Внутренняя переменная var20
	{160	,8	,1	,&var21},	//Внутренняя переменная var21
	{161	,8	,1	,&var22},	//Внутренняя переменная var22
	{162	,1	,1	,&var23},	//Внутренняя переменная var23
	{163	,8	,1	,&var24},	//Внутренняя переменная var24
	{164	,8	,1	,&var25},	//Внутренняя переменная var25
	{165	,8	,1	,&var26},	//Внутренняя переменная var26
	{166	,5	,1	,&var27},	//Внутренняя переменная var27
	{167	,1	,1	,&var28},	//Внутренняя переменная var28
	{168	,1	,1	,&var29},	//Внутренняя переменная var29
	{169	,8	,1	,&var3},	//Внутренняя переменная var3
	{170	,1	,1	,&var30},	//Внутренняя переменная var30
	{171	,1	,1	,&var31},	//Внутренняя переменная var31
	{172	,1	,1	,&var32},	//Внутренняя переменная var32
	{173	,1	,1	,&var33},	//Внутренняя переменная var33
	{174	,1	,1	,&var34},	//Внутренняя переменная var34
	{175	,1	,1	,&var35},	//Внутренняя переменная var35
	{176	,1	,1	,&var36},	//Внутренняя переменная var36
	{177	,1	,1	,&var37},	//Внутренняя переменная var37
	{178	,1	,1	,&var39},	//Внутренняя переменная var39
	{179	,8	,1	,&var4},	//Внутренняя переменная var4
	{180	,1	,1	,&var41},	//Внутренняя переменная var41
	{181	,1	,1	,&var42},	//Внутренняя переменная var42
	{182	,1	,1	,&var43},	//Внутренняя переменная var43
	{183	,1	,1	,&var44},	//Внутренняя переменная var44
	{184	,1	,1	,&var45},	//Внутренняя переменная var45
	{185	,8	,1	,&var46},	//Внутренняя переменная var46
	{186	,8	,1	,&var47},	//Внутренняя переменная var47
	{187	,1	,1	,&var49},	//Внутренняя переменная var49
	{188	,8	,1	,&var5},	//Внутренняя переменная var5
	{189	,1	,1	,&var50},	//Внутренняя переменная var50
	{190	,1	,1	,&var52},	//Внутренняя переменная var52
	{191	,1	,1	,&var53},	//Внутренняя переменная var53
	{192	,1	,1	,&var54},	//Внутренняя переменная var54
	{193	,1	,1	,&var55},	//Внутренняя переменная var55
	{194	,1	,1	,&var56},	//Внутренняя переменная var56
	{195	,1	,1	,&var57},	//Внутренняя переменная var57
	{196	,1	,1	,&var58},	//Внутренняя переменная var58
	{197	,1	,1	,&var59},	//Внутренняя переменная var59
	{198	,8	,1	,&var6},	//Внутренняя переменная var6
	{199	,1	,1	,&var60},	//Внутренняя переменная var60
	{200	,1	,1	,&var61},	//Внутренняя переменная var61
	{201	,1	,1	,&var62},	//Внутренняя переменная var62
	{202	,8	,1	,&var7},	//Внутренняя переменная var7
	{203	,8	,1	,&var8},	//Внутренняя переменная var8
	{204	,8	,1	,&var9},	//Внутренняя переменная var9
	{-1,0,NULL},
};
static char NameSaveFile[]="rpu.bin\0"; //Имя файла сохранения переменных
#pragma pop
static VarSaveCtrl saveVariables[]={	//Id переменных для сохранения
	{92,"fEM_A0UX00RSS\0"},	//(A0UX00RSS) Эффективный радиус АЗ
	{93,"fEM_A0UX13RSS\0"},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{94,"fEM_A0UX14RSS\0"},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{95,"fEM_A0UX15RSS\0"},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{96,"fEM_B0UX03RSS\0"},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{97,"fEM_B0UX04RSS\0"},	//(B0UX04RSS) Второй коэффициент калибровки камеры4
	{98,"fEM_B0UX05RSS\0"},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{99,"fEM_R0IN11NRP\0"},	//(R0IN11NRP) Коэффициент A (РПУ к 1)
	{100,"fEM_R0IN12NRP\0"},	//(R0IN12NRP) Коэффициент B (РПУ к 1)
	{101,"fEM_R0IN21NRP\0"},	//(R0IN21NRP) Коэффициент A (РПУ к 2)
	{102,"fEM_R0IN22NRP\0"},	//(R0IN22NRP) Коэффициент B (РПУ к 2)
	{103,"fEM_R0IN31NRP\0"},	//(R0IN31NRP) Коэффициент A (РПУ к 3)
	{104,"fEM_R0IN32NRP\0"},	//(R0IN32NRP) Коэффициент B (РПУ к 3)
	{105,"fEM_R0IN61NRP\0"},	//(R0IN61NRP) Коэффициент A (РПУ к 6)
	{106,"fEM_R0IN62NRP\0"},	//(R0IN62NRP) Коэффициент B (РПУ к 6)
	{107,"fEM_R0IN71NRP\0"},	//(R0IN71NRP) Коэффициент A (РПУ к 7)
	{108,"fEM_R0IN72NRP\0"},	//(R0IN72NRP) Коэффициент B (РПУ к 7)
	{109,"fEM_R0UH02RSS\0"},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{110,"fEM_R0UH03RSS\0"},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{111,"fEM_R0UH05RSS\0"},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{112,"fEM_R0UH21RSS\0"},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{113,"fEM_R0UH22RSS\0"},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{114,"fEM_R0UH23RSS\0"},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{115,"fEM_R0UL52RSS\0"},	//(R0UL52RSS) Уровень АС по мощности
	{116,"fEM_R0UR01RRP\0"},	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
	{117,"fEM_R0UT01RZZ\0"},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{118,"fEM_R0UT02RZZ\0"},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{119,"fEM_R0UT61RZZ\0"},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{120,"fEM_R0UT62RZZ\0"},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{121,"fEM_R0UT71RZZ\0"},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{122,"fEM_R0UT72RZZ\0"},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{123,"fEM_R7UX00RSS\0"},	//(R7UX00RSS) X-координата АЗ1 (см)
	{124,"fEM_R7UX13RSS\0"},	//(R7UX13RSS) X-координата камеры R7IN51
	{125,"fEM_R7UX14RSS\0"},	//(R7UX14RSS) X-координата камеры R7IN52
	{126,"fEM_R7UX15RSS\0"},	//(R7UX15RSS) X-координата камеры R7IN53
	{127,"fEM_R7UY00RSS\0"},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{128,"fEM_R7UY13RSS\0"},	//(R7UY13RSS) Y-координата камеры R7IN51
	{129,"fEM_R7UY14RSS\0"},	//(R7UY14RSS) Y-координата камеры R7IN52
	{130,"fEM_R7UY15RSS\0"},	//(R7UY15RSS) Y-координата камеры R7IN53
	{131,"fEM_Z7UE20RRP\0"},	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
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
	{&TestDiagnRPU,1,0},	//( - , RPU) Неисправность от диагностики
	{&B7MZ31LRP,1,1},	//( - , RPU) Клапан ОБДУВ АЗ2 открыть(обесточить)
	{&A7MZ31LRP,1,2},	//( - , RPU) Клапан ОБДУВ АЗ1 открыть(обесточить)
	{&R7VE70LRP,1,3},	//( - , RPU) Сигнал тревоги по неисправности РПУ на диспетчера
	{&A0EE01LRP,1,4},	//( - , RPU) Исправность АКНП канал 5
	{&B0VT71LRP,1,5},	//( - , RPU) АС по температуре в АЗ2-3
	{&B0VT61LRP,1,6},	//( - , RPU) ПС по температуре в АЗ2-3
	{&R0ET02LRP,1,7},	//( - , RPU) Признак наличия неисправности по температуре АЗ2-3
	{&R0ET01LRP,1,8},	//( - , RPU) Признак наличия неисправности по температуре  АЗ1-3
	{&A0VT71LRP,1,9},	//( - , RPU) АС по температуре в АЗ1
	{&A0VT61LRP,1,10},	//( - , RPU) ПС по температуре в АЗ1
	{&R7VN71LRP,1,11},	//( - , RPU) Сигнал тревоги по уровню нейтронного потока на диспетчера
	{&A0EE02LRP,1,12},	//( - , RPU) Исправность АКНП5 (от сшивки каналов) канал 5
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_RPU[]={
	{&TTLrpu,3,0},	//( - , RPU) ttl
	{&R0VN13RRP,8,1},	//( - , RPU) Нейтронный поток по камере  СНМ-11 канал 5
	{&B0CT01IRP,8,3},	//( - , RPU) Температура АЗ2-3
	{&B0IT03IRP,3,5},	//( - K02VASR, RPU) Температура АЗ2-3
	{&A0CT01IRP,8,6},	//( - , RPU) Температура АЗ1-3
	{&A0IT03IRP,3,8},	//( - K01VASR, RPU) Температура АЗ1-3
	{&R0IN07RRP,8,9},	//( - , RPU) Частота СНМ-11 Гц (канал 7)
	{&R0IN06RRP,8,11},	//( - , RPU) Частота СНМ-11 Гц (канал 6) от ПТИ
	{&R0VN15RRP,3,13},	//( - , RPU) Номер ведущей камеры канал 5
	{&R0VN33RRP,8,14},	//( - , RPU) Нейтронный поток по камере КНК53М канал 5
	{&R0VN23RRP,8,16},	//( - , RPU) Нейтронный поток по камере КНК15-1 канал 5
	{&R0IN03RRP,8,18},	//( - , RPU) Частота КНК53М Гц (канал 5)
	{&R0VN03RRP,8,20},	//( - , RPU) Измеренный нейтронный поток канал 5
	{&R0IN02RRP,8,22},	//( - , RPU) Частота КНК15-1 Гц (канал 5)
	{&R0IN01RRP,8,24},	//( - , RPU) Частота СНМ-11 Гц (канал 5)
	{&R0VN02RRP,8,26},	//( - , RPU) Уровень мощности канал 5
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
static char MRPS_ip2[]={"192.168.10.160\0"};
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
	setAsFloat(92,11.0);
	setAsFloat(93,1.0);
	setAsFloat(94,1.0);
	setAsFloat(95,1.0);
	setAsFloat(96,0);
	setAsFloat(97,0);
	setAsFloat(98,0.0);
	setAsFloat(99,1);
	setAsFloat(100,0);
	setAsFloat(101,1);
	setAsFloat(102,0);
	setAsFloat(103,1);
	setAsFloat(104,0);
	setAsFloat(105,1);
	setAsFloat(106,0);
	setAsFloat(107,1);
	setAsFloat(108,0);
	setAsFloat(109,37037.04 );
	setAsFloat(110,975000.0);
	setAsFloat(111,32000.0);
	setAsFloat(112,4000);
	setAsFloat(113,100000);
	setAsFloat(114,1000000);
	setAsFloat(115,5100);
	setAsFloat(116,1000);
	setAsFloat(117,0);
	setAsFloat(118,600);
	setAsFloat(119,100);
	setAsFloat(120,90);
	setAsFloat(121,200);
	setAsFloat(122,150);
	setAsFloat(123,1570.0);
	setAsFloat(124,1570.0);
	setAsFloat(125,1269);
	setAsFloat(126,1281.2);
	setAsFloat(127,506.5);
	setAsFloat(128,248.0);
	setAsFloat(129,572.4);
	setAsFloat(130,246.8);
	setAsFloat(131,210);
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
                if(ffast < 1.0 )
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


/* Определение переменных */
sschar var38;
sschar var40;
sschar var48;
sschar var51;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m156_x_1[6] = {&var14,&var15,&R0DE36LRP,&R0DE37LRP,&R0DE38LRP,&R0DE39LRP};
psint  array_m138_x_1[6] = {&R0DE01LRP,&R0DE02LRP,&R0DE03LRP,&R0DE08LRP,&R0DE06LRP,&R0DE07LRP};

/* Объявление структур */
_S_pogrvh  S_pogrvh_183_1 = {&R0IN07VRP,&fEM_R0IN71NRP,&fEM_R0IN72NRP,&var1};
_S_pogrvh  S_pogrvh_175_1 = {&R0IN06VRP,&fEM_R0IN61NRP,&fEM_R0IN62NRP,&var2};
_S_pogrvh  S_pogrvh_173_1 = {&R0IN03VRP,&fEM_R0IN31NRP,&fEM_R0IN32NRP,&var3};
_S_pogrvh  S_pogrvh_171_1 = {&R0IN02VRP,&fEM_R0IN21NRP,&fEM_R0IN22NRP,&var4};
_S_pogrvh  S_pogrvh_169_1 = {&R0IN01VRP,&fEM_R0IN11NRP,&fEM_R0IN12NRP,&var5};
_S_ml  S_ml_57_1 = {&R0IN07RIP,&var1,&R0IS01FI0,&var6};
_S_ml  S_ml_49_1 = {&R0IN06RIP,&var2,&R0IS01FI0,&var7};
_S_ml  S_ml_8_1 = {&R0IN03RIP,&var3,&R0IS01FI0,&var8};
_S_ml  S_ml_7_1 = {&R0IN02RIP,&var4,&R0IS01FI0,&var9};
_S_ml  S_ml_6_1 = {&R0IN01RIP,&var5,&R0IS01FI0,&var10};
_S_or4  S_or4_71_1 = {&var54,&var28,&var36,&var37,&var11};
_S_noto  S_noto_157_1 = {&var16,&var12};
_S_and5  S_and5_43_1 = {&var12,&R0IE11LRP,&R0IE12LRP,&R0IE13LRP,&var23,&var13};
_S_or2  S_or2_151_1 = {&R0DEB1LRP,&R0DEB2LRP,&var14};
_S_or2  S_or2_158_1 = {&R0DEB3LRP,&R0DEB4LRP,&var15};
_S_or3  S_or3_155_1 = {&var19,&var18,&var17,&var16};
_S_orn  S_orn_156_1 = {array_m156_x_1,&iRM_6_,&var17};
_S_and2  S_and2_140_1 = {&R0DE31LRP,&R0DE32LRP,&var18};
_S_diagndev  S_diagndev_138_1 = {array_m138_x_1,&iRM_6_,&var19,&var20,&vainSFloat};
_S_ocham  S_ocham_18_1 = {&var10,&var9,&var8,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX13RSS,&fEM_B0UX03RSS,&fEM_A0UX14RSS,&fEM_B0UX04RSS,&fEM_A0UX15RSS,&fEM_B0UX05RSS,&fEM_R7UX13RSS,&fEM_R7UY13RSS,&fEM_R7UX14RSS,&fEM_R7UY14RSS,&fEM_R7UX15RSS,&fEM_R7UY15RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&fEM_R0UH21RSS,&fEM_R0UH22RSS,&fEM_R0UH23RSS,&var21,&var22,&var23,&var24,&var25,&var26,&var27,&internal1_m18_Nk};
_S_or2  S_or2_66_1 = {&A6IS11LRP,&B6IS11LRP,&vainSBool};
_S_or2  S_or2_94_1 = {&var61,&var62,&var28};
_S_or4  S_or4_48_1 = {&var35,&var33,&var34,&var31,&var29};
_S_or2  S_or2_99_1 = {&var60,&var49,&var30};
_S_or2  S_or2_123_1 = {&var32,&var30,&var31};
_S_or2  S_or2_95_1 = {&var59,&var52,&var32};
_S_and3  S_and3_44_1 = {&var13,&var45,&var39,&var33};
_S_and3  S_and3_52_1 = {&var43,&R0IE14LRP,&var55,&var34};
_S_and3  S_and3_51_1 = {&R0IE15LRP,&var43,&var56,&var35};
_S_and3  S_and3_60_1 = {&R0IE14LRP,&var43,&var58,&var36};
_S_and3  S_and3_59_1 = {&var57,&R0IE15LRP,&var43,&var37};
_S_geterr  S_geterr_56_1 = {&var7,&dRM_0_,&iRM_0_,&bRM_0_,&var38,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_noto  S_noto_79_1 = {&var44,&var39};
_S_geterr  S_geterr_55_1 = {&var6,&dRM_0_,&iRM_0_,&bRM_0_,&var40,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_zzfs  S_zzfs_70_1 = {&var42,&fEM_Z7UE20RRP,&var41,&internal1_m70_tx,&internal1_m70_y0};
_S_or3  S_or3_69_1 = {&A6IS11LRP,&B6IS11LRP,&R0EE02LDU,&var42};
_S_noto  S_noto_67_1 = {&var41,&var43};
_S_zzfs  S_zzfs_78_1 = {&R0EE02LDU,&fEM_Z7UE20RRP,&var44,&internal1_m78_tx,&internal1_m78_y0};
_S_bol  S_bol_41_1 = {&var22,&fEM_R0UL52RSS,&var45};
_S_scalzz  S_scalzz_86_1 = {&B0IT03IRP,&iRM_3200_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var46,&internal1_m86_y0};
_S_scalzz  S_scalzz_84_1 = {&A0IT03IRP,&iRM_3200_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var47,&internal1_m84_y0};
_S_geterr  S_geterr_88_1 = {&var47,&dRM_0_,&iRM_0_,&bRM_0_,&var48,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_100_1 = {&var46,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var49,&internal1_m100_y1};
_S_drg  S_drg_115_1 = {&var46,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var50,&internal1_m115_y1};
_S_geterr  S_geterr_90_1 = {&var46,&dRM_0_,&iRM_0_,&bRM_0_,&var51,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_98_1 = {&var47,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var52,&internal1_m98_y1};
_S_drg  S_drg_111_1 = {&var47,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var53,&internal1_m111_y1};
_S_noto  S_noto_75_1 = {&var13,&var54};
_S_bol  S_bol_61_1 = {&var6,&fEM_R0UR01RRP,&var55};
_S_bol  S_bol_50_1 = {&var7,&fEM_R0UR01RRP,&var56};


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
  drg(&S_drg_111_1);
  drg(&S_drg_98_1);
  geterr(&S_geterr_90_1);
  drg(&S_drg_115_1);
  drg(&S_drg_100_1);
  geterr(&S_geterr_88_1);
  zzfs(&S_zzfs_78_1);
  or3(&S_or3_69_1);
  zzfs(&S_zzfs_70_1);
  noto(&S_noto_79_1);
  setData(&var59,&var48);
  or2(&S_or2_95_1);
  setData(&var60,&var51);
  or2(&S_or2_99_1);
  setData(&var61,&var48);
  setData(&var62,&var51);
  or2(&S_or2_94_1);
  orn(&S_orn_156_1);
  or3(&S_or3_155_1);
  noto(&S_noto_157_1);
  pogrvh(&S_pogrvh_169_1);
  pogrvh(&S_pogrvh_171_1);
  pogrvh(&S_pogrvh_173_1);
  pogrvh(&S_pogrvh_175_1);
  pogrvh(&S_pogrvh_183_1);
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
  setData(&var57,&var40);
  and3(&S_and3_59_1);
  setData(&var58,&var38);
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
  moveData(idB1VS21LRP,idB1IS21LRP);
  moveData(idA1VS21LRP,idA1IS21LRP);
  setData(idTTLrpu,&var20);
  setData(idTestDiagnRPU,&var16);
  setData(idR0DE3DLRP,&var15);
  setData(idR0DE3CLRP,&var14);
  moveData(idB7MZ31LRP,idC1MZ31LRP);
  moveData(idA7MZ31LRP,idC1MZ31LRP);
  moveData(idB3VS21LRP,idB3IS21LRP);
  moveData(idA3VS21LRP,idA3IS21LRP);
  moveData(idB2VS21LRP,idB2IS21LRP);
  moveData(idA2VS21LRP,idA2IS21LRP);
  setData(idR7VE70LRP,&var11);
  setData(idR0VN13RRP,&var24);
  setData(idR0VN71LRP,&var45);
  setData(idA1VT71LRP,&var31);
  setData(idR0IE04LRP,&var41);
  setData(idR0IE03LRP,&var41);
  setData(idA0EE01LRP,&var13);
  setData(idB0VT71LRP,&var30);
  setData(idB0VT61LRP,&var50);
  setData(idB0CT01IRP,&var46);
  setData(idR0ET02LRP,&var51);
  setData(idR0ET01LRP,&var48);
  setData(idA0VT71LRP,&var32);
  setData(idA0VT61LRP,&var53);
  setData(idA0CT01IRP,&var47);
  setData(idR0IN07RRP,&var1);
  setData(idR7VN71LRP,&var29);
  setData(idR0IN06RRP,&var2);
  setData(idR0IE02LRP,&var44);
  setData(idR0IE01LRP,&var44);
  setData(idR0VN15RRP,&var27);
  setData(idR0VN33RRP,&var26);
  setData(idR0VN23RRP,&var25);
  setData(idA0EE02LRP,&var23);
  setData(idR0IN03RRP,&var3);
  setData(idR0VN03RRP,&var21);
  setData(idR0IN02RRP,&var4);
  setData(idR0IN01RRP,&var5);
  setData(idR0VN02RRP,&var22);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}
void MainCycle(void){
	Scheme();
}
#endif