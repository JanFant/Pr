#ifndef RPU_H
#define RPU_H
// Подсистема  RPU:RPU
static char SimulOn=0;
static short CodeSub=8;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 //Время цикла мс
float takt,taktScheme=0,taktSS=0;
#define SIZE_BUFFER 851
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
#define R0IN01RRP	BUFFER[153]	// ( - , RPU) Частота СНМ-11 Гц (канал 5)
#define idR0IN01RRP	66	// ( - , RPU) Частота СНМ-11 Гц (канал 5)
#define R0IN01VRP	BUFFER[158]	// (vchs:01 - K01VCHS, RPU) Частота с ВЧС к 1
#define idR0IN01VRP	67	// (vchs:01 - K01VCHS, RPU) Частота с ВЧС к 1
#define R0IN02RRP	BUFFER[163]	// ( - , RPU) Частота КНК15-1 Гц (канал 5)
#define idR0IN02RRP	68	// ( - , RPU) Частота КНК15-1 Гц (канал 5)
#define R0IN02VRP	BUFFER[168]	// (vchs:01 - K02VCHS, RPU) Частота с ВЧС к 2
#define idR0IN02VRP	69	// (vchs:01 - K02VCHS, RPU) Частота с ВЧС к 2
#define R0IN03CYK	BUFFER[173]	// (vchs:02 - K01cykl, RPU) цикл
#define idR0IN03CYK	70	// (vchs:02 - K01cykl, RPU) цикл
#define R0IN03RRP	BUFFER[178]	// ( - , RPU) Частота КНК53М Гц (канал 5)
#define idR0IN03RRP	71	// ( - , RPU) Частота КНК53М Гц (канал 5)
#define R0IN03TEM	BUFFER[183]	// (vchs:02 - K01temp, RPU) кол-во имп
#define idR0IN03TEM	72	// (vchs:02 - K01temp, RPU) кол-во имп
#define R0IN03VRP	BUFFER[186]	// (vchs:02 - K01VCHS, RPU) Частота с ВЧС к 3
#define idR0IN03VRP	73	// (vchs:02 - K01VCHS, RPU) Частота с ВЧС к 3
#define R0IN06RRP	BUFFER[191]	// ( - , RPU) Частота СНМ-11 Гц (канал 6) от ПТИ
#define idR0IN06RRP	74	// ( - , RPU) Частота СНМ-11 Гц (канал 6) от ПТИ
#define R0IN06VRP	BUFFER[196]	// (vchs:03 - K01VCHS, RPU) Частота с ВЧС к 6
#define idR0IN06VRP	75	// (vchs:03 - K01VCHS, RPU) Частота с ВЧС к 6
#define R0IN07RRP	BUFFER[201]	// ( - , RPU) Частота СНМ-11 Гц (канал 7)
#define idR0IN07RRP	76	// ( - , RPU) Частота СНМ-11 Гц (канал 7)
#define R0IN07VRP	BUFFER[206]	// (vchs:03 - K02VCHS, RPU) Частота с ВЧС к 7
#define idR0IN07VRP	77	// (vchs:03 - K02VCHS, RPU) Частота с ВЧС к 7
#define R0VN02RRP	BUFFER[211]	// ( - , RPU) Уровень мощности канал 5
#define idR0VN02RRP	78	// ( - , RPU) Уровень мощности канал 5
#define R0VN03RRP	BUFFER[216]	// ( - , RPU) Измеренный нейтронный поток канал 5
#define idR0VN03RRP	79	// ( - , RPU) Измеренный нейтронный поток канал 5
#define R0VN13RRP	BUFFER[221]	// ( - , RPU) Нейтронный поток по камере  СНМ-11 канал 5
#define idR0VN13RRP	80	// ( - , RPU) Нейтронный поток по камере  СНМ-11 канал 5
#define R0VN15RRP	BUFFER[226]	// ( - , RPU) Номер ведущей камеры канал 5
#define idR0VN15RRP	81	// ( - , RPU) Номер ведущей камеры канал 5
#define R0VN23RRP	BUFFER[229]	// ( - , RPU) Нейтронный поток по камере КНК15-1 канал 5
#define idR0VN23RRP	82	// ( - , RPU) Нейтронный поток по камере КНК15-1 канал 5
#define R0VN33RRP	BUFFER[234]	// ( - , RPU) Нейтронный поток по камере КНК53М канал 5
#define idR0VN33RRP	83	// ( - , RPU) Нейтронный поток по камере КНК53М канал 5
#define R0VN71LRP	BUFFER[239]	// (fds16:08 - K12FDSR, - ) АС по мощности канал 5
#define idR0VN71LRP	84	// (fds16:08 - K12FDSR, - ) АС по мощности канал 5
#define R7VE70LRP	BUFFER[241]	// ( - , RPU) Сигнал тревоги по неисправности РПУ на диспетчера
#define idR7VE70LRP	85	// ( - , RPU) Сигнал тревоги по неисправности РПУ на диспетчера
#define R7VN71LRP	BUFFER[243]	// ( - , RPU) Сигнал тревоги по уровню нейтронного потока на диспетчера
#define idR7VN71LRP	86	// ( - , RPU) Сигнал тревоги по уровню нейтронного потока на диспетчера
#define TTLrpu	BUFFER[245]	// ( - , RPU) ttl
#define idTTLrpu	87	// ( - , RPU) ttl
#define TestDiagnRPU	BUFFER[248]	// ( - , RPU) Неисправность от диагностики
#define idTestDiagnRPU	88	// ( - , RPU) Неисправность от диагностики
#define VMETRP06	BUFFER[250]	// (vas84:06 - K05VASR, RPU) вход Метр Давленение 0.6
#define idVMETRP06	89	// (vas84:06 - K05VASR, RPU) вход Метр Давленение 0.6
#define VMETRP12	BUFFER[253]	// (vas84:06 - K06VASR, RPU) вход Метр Давленение 1.2
#define idVMETRP12	90	// (vas84:06 - K06VASR, RPU) вход Метр Давленение 1.2
#define aaaa	BUFFER[256]	// ( - , - ) aaaa
#define idaaaa	91	// ( - , - ) aaaa
#define bFirstEnterFlag	BUFFER[261]	// (bFirstEnterFlag) 
#define idbFirstEnterFlag	92	// (bFirstEnterFlag) 
#define fEM_A0UX00RSS	BUFFER[263]	// (A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	93	// (A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX13RSS	BUFFER[268]	// (A0UX13RSS) Первый коэффициент калибровки камеры 13
#define idfEM_A0UX13RSS	94	// (A0UX13RSS) Первый коэффициент калибровки камеры 13
#define fEM_A0UX14RSS	BUFFER[273]	// (A0UX14RSS) Первый коэффициент калибровки камеры 14
#define idfEM_A0UX14RSS	95	// (A0UX14RSS) Первый коэффициент калибровки камеры 14
#define fEM_A0UX15RSS	BUFFER[278]	// (A0UX15RSS) Первый коэффициент калибровки камеры 15
#define idfEM_A0UX15RSS	96	// (A0UX15RSS) Первый коэффициент калибровки камеры 15
#define fEM_B0UX03RSS	BUFFER[283]	// (B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	97	// (B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	BUFFER[288]	// (B0UX04RSS) Второй коэффициент калибровки камеры4
#define idfEM_B0UX04RSS	98	// (B0UX04RSS) Второй коэффициент калибровки камеры4
#define fEM_B0UX05RSS	BUFFER[293]	// (B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	99	// (B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_R0IN11NRP	BUFFER[298]	// (R0IN11NRP) Коэффициент A (РПУ к 1)
#define idfEM_R0IN11NRP	100	// (R0IN11NRP) Коэффициент A (РПУ к 1)
#define fEM_R0IN12NRP	BUFFER[303]	// (R0IN12NRP) Коэффициент B (РПУ к 1)
#define idfEM_R0IN12NRP	101	// (R0IN12NRP) Коэффициент B (РПУ к 1)
#define fEM_R0IN21NRP	BUFFER[308]	// (R0IN21NRP) Коэффициент A (РПУ к 2)
#define idfEM_R0IN21NRP	102	// (R0IN21NRP) Коэффициент A (РПУ к 2)
#define fEM_R0IN22NRP	BUFFER[313]	// (R0IN22NRP) Коэффициент B (РПУ к 2)
#define idfEM_R0IN22NRP	103	// (R0IN22NRP) Коэффициент B (РПУ к 2)
#define fEM_R0IN31NRP	BUFFER[318]	// (R0IN31NRP) Коэффициент A (РПУ к 3)
#define idfEM_R0IN31NRP	104	// (R0IN31NRP) Коэффициент A (РПУ к 3)
#define fEM_R0IN32NRP	BUFFER[323]	// (R0IN32NRP) Коэффициент B (РПУ к 3)
#define idfEM_R0IN32NRP	105	// (R0IN32NRP) Коэффициент B (РПУ к 3)
#define fEM_R0IN61NRP	BUFFER[328]	// (R0IN61NRP) Коэффициент A (РПУ к 6)
#define idfEM_R0IN61NRP	106	// (R0IN61NRP) Коэффициент A (РПУ к 6)
#define fEM_R0IN62NRP	BUFFER[333]	// (R0IN62NRP) Коэффициент B (РПУ к 6)
#define idfEM_R0IN62NRP	107	// (R0IN62NRP) Коэффициент B (РПУ к 6)
#define fEM_R0IN71NRP	BUFFER[338]	// (R0IN71NRP) Коэффициент A (РПУ к 7)
#define idfEM_R0IN71NRP	108	// (R0IN71NRP) Коэффициент A (РПУ к 7)
#define fEM_R0IN72NRP	BUFFER[343]	// (R0IN72NRP) Коэффициент B (РПУ к 7)
#define idfEM_R0IN72NRP	109	// (R0IN72NRP) Коэффициент B (РПУ к 7)
#define fEM_R0UH02RSS	BUFFER[348]	// (R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define idfEM_R0UH02RSS	110	// (R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define fEM_R0UH03RSS	BUFFER[353]	// (R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define idfEM_R0UH03RSS	111	// (R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define fEM_R0UH05RSS	BUFFER[358]	// (R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	112	// (R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UH21RSS	BUFFER[363]	// (R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	113	// (R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	BUFFER[368]	// (R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	114	// (R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	BUFFER[373]	// (R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	115	// (R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0UL52RSS	BUFFER[378]	// (R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	116	// (R0UL52RSS) Уровень АС по мощности
#define fEM_R0UR01RRP	BUFFER[383]	// (R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
#define idfEM_R0UR01RRP	117	// (R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
#define fEM_R0UT01RZZ	BUFFER[388]	// (R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	118	// (R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_R0UT02RZZ	BUFFER[393]	// (R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	119	// (R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT61RZZ	BUFFER[398]	// (R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	120	// (R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	BUFFER[403]	// (R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	121	// (R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	BUFFER[408]	// (R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	122	// (R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT72RZZ	BUFFER[413]	// (R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	123	// (R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define fEM_R7UX00RSS	BUFFER[418]	// (R7UX00RSS) X-координата АЗ1 (см)
#define idfEM_R7UX00RSS	124	// (R7UX00RSS) X-координата АЗ1 (см)
#define fEM_R7UX13RSS	BUFFER[423]	// (R7UX13RSS) X-координата камеры R7IN51
#define idfEM_R7UX13RSS	125	// (R7UX13RSS) X-координата камеры R7IN51
#define fEM_R7UX14RSS	BUFFER[428]	// (R7UX14RSS) X-координата камеры R7IN52
#define idfEM_R7UX14RSS	126	// (R7UX14RSS) X-координата камеры R7IN52
#define fEM_R7UX15RSS	BUFFER[433]	// (R7UX15RSS) X-координата камеры R7IN53
#define idfEM_R7UX15RSS	127	// (R7UX15RSS) X-координата камеры R7IN53
#define fEM_R7UY00RSS	BUFFER[438]	// (R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	128	// (R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UY13RSS	BUFFER[443]	// (R7UY13RSS) Y-координата камеры R7IN51
#define idfEM_R7UY13RSS	129	// (R7UY13RSS) Y-координата камеры R7IN51
#define fEM_R7UY14RSS	BUFFER[448]	// (R7UY14RSS) Y-координата камеры R7IN52
#define idfEM_R7UY14RSS	130	// (R7UY14RSS) Y-координата камеры R7IN52
#define fEM_R7UY15RSS	BUFFER[453]	// (R7UY15RSS) Y-координата камеры R7IN53
#define idfEM_R7UY15RSS	131	// (R7UY15RSS) Y-координата камеры R7IN53
#define fEM_R7UY22RSS	BUFFER[458]	// (R7UY22RSS) 2-й коэффициент ф-ции смещения
#define idfEM_R7UY22RSS	132	// (R7UY22RSS) 2-й коэффициент ф-ции смещения
#define fEM_R7UY32RSS	BUFFER[463]	// (R7UY32RSS) 1-й коэффициент ф-ции смещения
#define idfEM_R7UY32RSS	133	// (R7UY32RSS) 1-й коэффициент ф-ции смещения
#define fEM_R7UY42RSS	BUFFER[468]	// (R7UY42RSS) уровень корректировки
#define idfEM_R7UY42RSS	134	// (R7UY42RSS) уровень корректировки
#define fEM_Z7UE20RRP	BUFFER[473]	// (Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
#define idfEM_Z7UE20RRP	135	// (Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
#define iEM_R7UY12RSS	BUFFER[478]	// (R7UY12RSS) интервал усреднения
#define idiEM_R7UY12RSS	136	// (R7UY12RSS) интервал усреднения
#define internal1_m101_y1	BUFFER[481]	// (internal1_m101_y1) y1 - внутренний параметр
#define idinternal1_m101_y1	137	// (internal1_m101_y1) y1 - внутренний параметр
#define internal1_m104_y1	BUFFER[483]	// (internal1_m104_y1) y1 - внутренний параметр
#define idinternal1_m104_y1	138	// (internal1_m104_y1) y1 - внутренний параметр
#define internal1_m11_Nk	BUFFER[485]	// (internal1_m11_Nk) Nk - ведущая камера
#define idinternal1_m11_Nk	139	// (internal1_m11_Nk) Nk - ведущая камера
#define internal1_m174_SumS	BUFFER[488]	// (internal1_m174_SumS) внутренний параметр
#define idinternal1_m174_SumS	140	// (internal1_m174_SumS) внутренний параметр
#define internal1_m174_flst	BUFFER[493]	// (internal1_m174_flst) внутренний параметр
#define idinternal1_m174_flst	141	// (internal1_m174_flst) внутренний параметр
#define internal1_m174_stepc	BUFFER[498]	// (internal1_m174_stepc) stepc - счетчик шагов
#define idinternal1_m174_stepc	142	// (internal1_m174_stepc) stepc - счетчик шагов
#define internal1_m174_x0	BUFFER[503]	// (internal1_m174_x0) x0 - массив мгновенных значений 
#define idinternal1_m174_x0	143	// (internal1_m174_x0) x0 - массив мгновенных значений 
#define internal1_m174_xptr	BUFFER[553]	// (internal1_m174_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m174_xptr	144	// (internal1_m174_xptr) указатель текущей позиции в массиве координат
#define internal1_m175_SumS	BUFFER[556]	// (internal1_m175_SumS) внутренний параметр
#define idinternal1_m175_SumS	145	// (internal1_m175_SumS) внутренний параметр
#define internal1_m175_flst	BUFFER[561]	// (internal1_m175_flst) внутренний параметр
#define idinternal1_m175_flst	146	// (internal1_m175_flst) внутренний параметр
#define internal1_m175_stepc	BUFFER[566]	// (internal1_m175_stepc) stepc - счетчик шагов
#define idinternal1_m175_stepc	147	// (internal1_m175_stepc) stepc - счетчик шагов
#define internal1_m175_x0	BUFFER[571]	// (internal1_m175_x0) x0 - массив мгновенных значений 
#define idinternal1_m175_x0	148	// (internal1_m175_x0) x0 - массив мгновенных значений 
#define internal1_m175_xptr	BUFFER[621]	// (internal1_m175_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m175_xptr	149	// (internal1_m175_xptr) указатель текущей позиции в массиве координат
#define internal1_m190_y0	BUFFER[624]	// (internal1_m190_y0) y0
#define idinternal1_m190_y0	150	// (internal1_m190_y0) y0
#define internal1_m191_y0	BUFFER[629]	// (internal1_m191_y0) y0
#define idinternal1_m191_y0	151	// (internal1_m191_y0) y0
#define internal1_m59_tx	BUFFER[634]	// (internal1_m59_tx) tx - время накопленное сек
#define idinternal1_m59_tx	152	// (internal1_m59_tx) tx - время накопленное сек
#define internal1_m59_y0	BUFFER[639]	// (internal1_m59_y0) y0
#define idinternal1_m59_y0	153	// (internal1_m59_y0) y0
#define internal1_m67_tx	BUFFER[641]	// (internal1_m67_tx) tx - время накопленное сек
#define idinternal1_m67_tx	154	// (internal1_m67_tx) tx - время накопленное сек
#define internal1_m67_y0	BUFFER[646]	// (internal1_m67_y0) y0
#define idinternal1_m67_y0	155	// (internal1_m67_y0) y0
#define internal1_m73_y0	BUFFER[648]	// (internal1_m73_y0) y0
#define idinternal1_m73_y0	156	// (internal1_m73_y0) y0
#define internal1_m75_y0	BUFFER[653]	// (internal1_m75_y0) y0
#define idinternal1_m75_y0	157	// (internal1_m75_y0) y0
#define internal1_m87_y1	BUFFER[658]	// (internal1_m87_y1) y1 - внутренний параметр
#define idinternal1_m87_y1	158	// (internal1_m87_y1) y1 - внутренний параметр
#define internal1_m89_y1	BUFFER[660]	// (internal1_m89_y1) y1 - внутренний параметр
#define idinternal1_m89_y1	159	// (internal1_m89_y1) y1 - внутренний параметр
#define vainSBool	BUFFER[662]	// Внутренняя переменная vainSBool
#define idvainSBool	160	// Внутренняя переменная vainSBool
#define vainSFloat	BUFFER[664]	// Внутренняя переменная vainSFloat
#define idvainSFloat	161	// Внутренняя переменная vainSFloat
#define vainSInt	BUFFER[669]	// Внутренняя переменная vainSInt
#define idvainSInt	162	// Внутренняя переменная vainSInt
#define vainSLong	BUFFER[674]	// Внутренняя переменная vainSLong
#define idvainSLong	163	// Внутренняя переменная vainSLong
#define var1	BUFFER[683]	// Внутренняя переменная var1
#define idvar1	164	// Внутренняя переменная var1
#define var10	BUFFER[688]	// Внутренняя переменная var10
#define idvar10	165	// Внутренняя переменная var10
#define var11	BUFFER[690]	// Внутренняя переменная var11
#define idvar11	166	// Внутренняя переменная var11
#define var12	BUFFER[692]	// Внутренняя переменная var12
#define idvar12	167	// Внутренняя переменная var12
#define var13	BUFFER[694]	// Внутренняя переменная var13
#define idvar13	168	// Внутренняя переменная var13
#define var14	BUFFER[696]	// Внутренняя переменная var14
#define idvar14	169	// Внутренняя переменная var14
#define var15	BUFFER[698]	// Внутренняя переменная var15
#define idvar15	170	// Внутренняя переменная var15
#define var16	BUFFER[700]	// Внутренняя переменная var16
#define idvar16	171	// Внутренняя переменная var16
#define var17	BUFFER[702]	// Внутренняя переменная var17
#define idvar17	172	// Внутренняя переменная var17
#define var18	BUFFER[704]	// Внутренняя переменная var18
#define idvar18	173	// Внутренняя переменная var18
#define var19	BUFFER[706]	// Внутренняя переменная var19
#define idvar19	174	// Внутренняя переменная var19
#define var2	BUFFER[711]	// Внутренняя переменная var2
#define idvar2	175	// Внутренняя переменная var2
#define var20	BUFFER[716]	// Внутренняя переменная var20
#define idvar20	176	// Внутренняя переменная var20
#define var21	BUFFER[721]	// Внутренняя переменная var21
#define idvar21	177	// Внутренняя переменная var21
#define var22	BUFFER[726]	// Внутренняя переменная var22
#define idvar22	178	// Внутренняя переменная var22
#define var23	BUFFER[728]	// Внутренняя переменная var23
#define idvar23	179	// Внутренняя переменная var23
#define var24	BUFFER[733]	// Внутренняя переменная var24
#define idvar24	180	// Внутренняя переменная var24
#define var25	BUFFER[738]	// Внутренняя переменная var25
#define idvar25	181	// Внутренняя переменная var25
#define var26	BUFFER[743]	// Внутренняя переменная var26
#define idvar26	182	// Внутренняя переменная var26
#define var27	BUFFER[748]	// Внутренняя переменная var27
#define idvar27	183	// Внутренняя переменная var27
#define var28	BUFFER[750]	// Внутренняя переменная var28
#define idvar28	184	// Внутренняя переменная var28
#define var29	BUFFER[752]	// Внутренняя переменная var29
#define idvar29	185	// Внутренняя переменная var29
#define var3	BUFFER[754]	// Внутренняя переменная var3
#define idvar3	186	// Внутренняя переменная var3
#define var30	BUFFER[759]	// Внутренняя переменная var30
#define idvar30	187	// Внутренняя переменная var30
#define var31	BUFFER[761]	// Внутренняя переменная var31
#define idvar31	188	// Внутренняя переменная var31
#define var32	BUFFER[763]	// Внутренняя переменная var32
#define idvar32	189	// Внутренняя переменная var32
#define var33	BUFFER[765]	// Внутренняя переменная var33
#define idvar33	190	// Внутренняя переменная var33
#define var34	BUFFER[767]	// Внутренняя переменная var34
#define idvar34	191	// Внутренняя переменная var34
#define var35	BUFFER[769]	// Внутренняя переменная var35
#define idvar35	192	// Внутренняя переменная var35
#define var36	BUFFER[771]	// Внутренняя переменная var36
#define idvar36	193	// Внутренняя переменная var36
#define var38	BUFFER[773]	// Внутренняя переменная var38
#define idvar38	194	// Внутренняя переменная var38
#define var4	BUFFER[775]	// Внутренняя переменная var4
#define idvar4	195	// Внутренняя переменная var4
#define var40	BUFFER[780]	// Внутренняя переменная var40
#define idvar40	196	// Внутренняя переменная var40
#define var41	BUFFER[782]	// Внутренняя переменная var41
#define idvar41	197	// Внутренняя переменная var41
#define var42	BUFFER[784]	// Внутренняя переменная var42
#define idvar42	198	// Внутренняя переменная var42
#define var43	BUFFER[786]	// Внутренняя переменная var43
#define idvar43	199	// Внутренняя переменная var43
#define var44	BUFFER[788]	// Внутренняя переменная var44
#define idvar44	200	// Внутренняя переменная var44
#define var45	BUFFER[790]	// Внутренняя переменная var45
#define idvar45	201	// Внутренняя переменная var45
#define var46	BUFFER[795]	// Внутренняя переменная var46
#define idvar46	202	// Внутренняя переменная var46
#define var48	BUFFER[800]	// Внутренняя переменная var48
#define idvar48	203	// Внутренняя переменная var48
#define var49	BUFFER[802]	// Внутренняя переменная var49
#define idvar49	204	// Внутренняя переменная var49
#define var5	BUFFER[804]	// Внутренняя переменная var5
#define idvar5	205	// Внутренняя переменная var5
#define var51	BUFFER[809]	// Внутренняя переменная var51
#define idvar51	206	// Внутренняя переменная var51
#define var52	BUFFER[811]	// Внутренняя переменная var52
#define idvar52	207	// Внутренняя переменная var52
#define var53	BUFFER[813]	// Внутренняя переменная var53
#define idvar53	208	// Внутренняя переменная var53
#define var54	BUFFER[815]	// Внутренняя переменная var54
#define idvar54	209	// Внутренняя переменная var54
#define var55	BUFFER[817]	// Внутренняя переменная var55
#define idvar55	210	// Внутренняя переменная var55
#define var56	BUFFER[819]	// Внутренняя переменная var56
#define idvar56	211	// Внутренняя переменная var56
#define var57	BUFFER[821]	// Внутренняя переменная var57
#define idvar57	212	// Внутренняя переменная var57
#define var58	BUFFER[823]	// Внутренняя переменная var58
#define idvar58	213	// Внутренняя переменная var58
#define var59	BUFFER[825]	// Внутренняя переменная var59
#define idvar59	214	// Внутренняя переменная var59
#define var6	BUFFER[827]	// Внутренняя переменная var6
#define idvar6	215	// Внутренняя переменная var6
#define var60	BUFFER[832]	// Внутренняя переменная var60
#define idvar60	216	// Внутренняя переменная var60
#define var61	BUFFER[834]	// Внутренняя переменная var61
#define idvar61	217	// Внутренняя переменная var61
#define var7	BUFFER[836]	// Внутренняя переменная var7
#define idvar7	218	// Внутренняя переменная var7
#define var8	BUFFER[841]	// Внутренняя переменная var8
#define idvar8	219	// Внутренняя переменная var8
#define var9	BUFFER[846]	// Внутренняя переменная var9
#define idvar9	220	// Внутренняя переменная var9
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
	{66	,8	,1	,&R0IN01RRP},	//( - , RPU) Частота СНМ-11 Гц (канал 5)
	{67	,8	,1	,&R0IN01VRP},	//(vchs:01 - K01VCHS, RPU) Частота с ВЧС к 1
	{68	,8	,1	,&R0IN02RRP},	//( - , RPU) Частота КНК15-1 Гц (канал 5)
	{69	,8	,1	,&R0IN02VRP},	//(vchs:01 - K02VCHS, RPU) Частота с ВЧС к 2
	{70	,8	,1	,&R0IN03CYK},	//(vchs:02 - K01cykl, RPU) цикл
	{71	,8	,1	,&R0IN03RRP},	//( - , RPU) Частота КНК53М Гц (канал 5)
	{72	,3	,1	,&R0IN03TEM},	//(vchs:02 - K01temp, RPU) кол-во имп
	{73	,8	,1	,&R0IN03VRP},	//(vchs:02 - K01VCHS, RPU) Частота с ВЧС к 3
	{74	,8	,1	,&R0IN06RRP},	//( - , RPU) Частота СНМ-11 Гц (канал 6) от ПТИ
	{75	,8	,1	,&R0IN06VRP},	//(vchs:03 - K01VCHS, RPU) Частота с ВЧС к 6
	{76	,8	,1	,&R0IN07RRP},	//( - , RPU) Частота СНМ-11 Гц (канал 7)
	{77	,8	,1	,&R0IN07VRP},	//(vchs:03 - K02VCHS, RPU) Частота с ВЧС к 7
	{78	,8	,1	,&R0VN02RRP},	//( - , RPU) Уровень мощности канал 5
	{79	,8	,1	,&R0VN03RRP},	//( - , RPU) Измеренный нейтронный поток канал 5
	{80	,8	,1	,&R0VN13RRP},	//( - , RPU) Нейтронный поток по камере  СНМ-11 канал 5
	{81	,3	,1	,&R0VN15RRP},	//( - , RPU) Номер ведущей камеры канал 5
	{82	,8	,1	,&R0VN23RRP},	//( - , RPU) Нейтронный поток по камере КНК15-1 канал 5
	{83	,8	,1	,&R0VN33RRP},	//( - , RPU) Нейтронный поток по камере КНК53М канал 5
	{84	,1	,1	,&R0VN71LRP},	//(fds16:08 - K12FDSR, - ) АС по мощности канал 5
	{85	,1	,1	,&R7VE70LRP},	//( - , RPU) Сигнал тревоги по неисправности РПУ на диспетчера
	{86	,1	,1	,&R7VN71LRP},	//( - , RPU) Сигнал тревоги по уровню нейтронного потока на диспетчера
	{87	,3	,1	,&TTLrpu},	//( - , RPU) ttl
	{88	,1	,1	,&TestDiagnRPU},	//( - , RPU) Неисправность от диагностики
	{89	,3	,1	,&VMETRP06},	//(vas84:06 - K05VASR, RPU) вход Метр Давленение 0.6
	{90	,3	,1	,&VMETRP12},	//(vas84:06 - K06VASR, RPU) вход Метр Давленение 1.2
	{91	,8	,1	,&aaaa},	//( - , - ) aaaa
	{92	,1	,1	,&bFirstEnterFlag},	//(bFirstEnterFlag) 
	{93	,8	,1	,&fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{94	,8	,1	,&fEM_A0UX13RSS},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{95	,8	,1	,&fEM_A0UX14RSS},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{96	,8	,1	,&fEM_A0UX15RSS},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{97	,8	,1	,&fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{98	,8	,1	,&fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры4
	{99	,8	,1	,&fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{100	,8	,1	,&fEM_R0IN11NRP},	//(R0IN11NRP) Коэффициент A (РПУ к 1)
	{101	,8	,1	,&fEM_R0IN12NRP},	//(R0IN12NRP) Коэффициент B (РПУ к 1)
	{102	,8	,1	,&fEM_R0IN21NRP},	//(R0IN21NRP) Коэффициент A (РПУ к 2)
	{103	,8	,1	,&fEM_R0IN22NRP},	//(R0IN22NRP) Коэффициент B (РПУ к 2)
	{104	,8	,1	,&fEM_R0IN31NRP},	//(R0IN31NRP) Коэффициент A (РПУ к 3)
	{105	,8	,1	,&fEM_R0IN32NRP},	//(R0IN32NRP) Коэффициент B (РПУ к 3)
	{106	,8	,1	,&fEM_R0IN61NRP},	//(R0IN61NRP) Коэффициент A (РПУ к 6)
	{107	,8	,1	,&fEM_R0IN62NRP},	//(R0IN62NRP) Коэффициент B (РПУ к 6)
	{108	,8	,1	,&fEM_R0IN71NRP},	//(R0IN71NRP) Коэффициент A (РПУ к 7)
	{109	,8	,1	,&fEM_R0IN72NRP},	//(R0IN72NRP) Коэффициент B (РПУ к 7)
	{110	,8	,1	,&fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{111	,8	,1	,&fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{112	,8	,1	,&fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{113	,8	,1	,&fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{114	,8	,1	,&fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{115	,8	,1	,&fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{116	,8	,1	,&fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{117	,8	,1	,&fEM_R0UR01RRP},	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
	{118	,8	,1	,&fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{119	,8	,1	,&fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{120	,8	,1	,&fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{121	,8	,1	,&fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{122	,8	,1	,&fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{123	,8	,1	,&fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{124	,8	,1	,&fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{125	,8	,1	,&fEM_R7UX13RSS},	//(R7UX13RSS) X-координата камеры R7IN51
	{126	,8	,1	,&fEM_R7UX14RSS},	//(R7UX14RSS) X-координата камеры R7IN52
	{127	,8	,1	,&fEM_R7UX15RSS},	//(R7UX15RSS) X-координата камеры R7IN53
	{128	,8	,1	,&fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{129	,8	,1	,&fEM_R7UY13RSS},	//(R7UY13RSS) Y-координата камеры R7IN51
	{130	,8	,1	,&fEM_R7UY14RSS},	//(R7UY14RSS) Y-координата камеры R7IN52
	{131	,8	,1	,&fEM_R7UY15RSS},	//(R7UY15RSS) Y-координата камеры R7IN53
	{132	,8	,1	,&fEM_R7UY22RSS},	//(R7UY22RSS) 2-й коэффициент ф-ции смещения
	{133	,8	,1	,&fEM_R7UY32RSS},	//(R7UY32RSS) 1-й коэффициент ф-ции смещения
	{134	,8	,1	,&fEM_R7UY42RSS},	//(R7UY42RSS) уровень корректировки
	{135	,8	,1	,&fEM_Z7UE20RRP},	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
	{136	,3	,1	,&iEM_R7UY12RSS},	//(R7UY12RSS) интервал усреднения
	{137	,1	,1	,&internal1_m101_y1},	//(internal1_m101_y1) y1 - внутренний параметр
	{138	,1	,1	,&internal1_m104_y1},	//(internal1_m104_y1) y1 - внутренний параметр
	{139	,3	,1	,&internal1_m11_Nk},	//(internal1_m11_Nk) Nk - ведущая камера
	{140	,8	,1	,&internal1_m174_SumS},	//(internal1_m174_SumS) внутренний параметр
	{141	,8	,1	,&internal1_m174_flst},	//(internal1_m174_flst) внутренний параметр
	{142	,8	,1	,&internal1_m174_stepc},	//(internal1_m174_stepc) stepc - счетчик шагов
	{143	,8	,10	,&internal1_m174_x0},	//(internal1_m174_x0) x0 - массив мгновенных значений 
	{144	,3	,1	,&internal1_m174_xptr},	//(internal1_m174_xptr) указатель текущей позиции в массиве координат
	{145	,8	,1	,&internal1_m175_SumS},	//(internal1_m175_SumS) внутренний параметр
	{146	,8	,1	,&internal1_m175_flst},	//(internal1_m175_flst) внутренний параметр
	{147	,8	,1	,&internal1_m175_stepc},	//(internal1_m175_stepc) stepc - счетчик шагов
	{148	,8	,10	,&internal1_m175_x0},	//(internal1_m175_x0) x0 - массив мгновенных значений 
	{149	,3	,1	,&internal1_m175_xptr},	//(internal1_m175_xptr) указатель текущей позиции в массиве координат
	{150	,8	,1	,&internal1_m190_y0},	//(internal1_m190_y0) y0
	{151	,8	,1	,&internal1_m191_y0},	//(internal1_m191_y0) y0
	{152	,8	,1	,&internal1_m59_tx},	//(internal1_m59_tx) tx - время накопленное сек
	{153	,18	,1	,&internal1_m59_y0},	//(internal1_m59_y0) y0
	{154	,8	,1	,&internal1_m67_tx},	//(internal1_m67_tx) tx - время накопленное сек
	{155	,18	,1	,&internal1_m67_y0},	//(internal1_m67_y0) y0
	{156	,8	,1	,&internal1_m73_y0},	//(internal1_m73_y0) y0
	{157	,8	,1	,&internal1_m75_y0},	//(internal1_m75_y0) y0
	{158	,1	,1	,&internal1_m87_y1},	//(internal1_m87_y1) y1 - внутренний параметр
	{159	,1	,1	,&internal1_m89_y1},	//(internal1_m89_y1) y1 - внутренний параметр
	{160	,1	,1	,&vainSBool},	//Внутренняя переменная vainSBool
	{161	,8	,1	,&vainSFloat},	//Внутренняя переменная vainSFloat
	{162	,5	,1	,&vainSInt},	//Внутренняя переменная vainSInt
	{163	,11	,1	,&vainSLong},	//Внутренняя переменная vainSLong
	{164	,8	,1	,&var1},	//Внутренняя переменная var1
	{165	,1	,1	,&var10},	//Внутренняя переменная var10
	{166	,1	,1	,&var11},	//Внутренняя переменная var11
	{167	,1	,1	,&var12},	//Внутренняя переменная var12
	{168	,1	,1	,&var13},	//Внутренняя переменная var13
	{169	,1	,1	,&var14},	//Внутренняя переменная var14
	{170	,1	,1	,&var15},	//Внутренняя переменная var15
	{171	,1	,1	,&var16},	//Внутренняя переменная var16
	{172	,1	,1	,&var17},	//Внутренняя переменная var17
	{173	,1	,1	,&var18},	//Внутренняя переменная var18
	{174	,5	,1	,&var19},	//Внутренняя переменная var19
	{175	,8	,1	,&var2},	//Внутренняя переменная var2
	{176	,8	,1	,&var20},	//Внутренняя переменная var20
	{177	,8	,1	,&var21},	//Внутренняя переменная var21
	{178	,1	,1	,&var22},	//Внутренняя переменная var22
	{179	,8	,1	,&var23},	//Внутренняя переменная var23
	{180	,8	,1	,&var24},	//Внутренняя переменная var24
	{181	,8	,1	,&var25},	//Внутренняя переменная var25
	{182	,5	,1	,&var26},	//Внутренняя переменная var26
	{183	,1	,1	,&var27},	//Внутренняя переменная var27
	{184	,1	,1	,&var28},	//Внутренняя переменная var28
	{185	,1	,1	,&var29},	//Внутренняя переменная var29
	{186	,8	,1	,&var3},	//Внутренняя переменная var3
	{187	,1	,1	,&var30},	//Внутренняя переменная var30
	{188	,1	,1	,&var31},	//Внутренняя переменная var31
	{189	,1	,1	,&var32},	//Внутренняя переменная var32
	{190	,1	,1	,&var33},	//Внутренняя переменная var33
	{191	,1	,1	,&var34},	//Внутренняя переменная var34
	{192	,1	,1	,&var35},	//Внутренняя переменная var35
	{193	,1	,1	,&var36},	//Внутренняя переменная var36
	{194	,1	,1	,&var38},	//Внутренняя переменная var38
	{195	,8	,1	,&var4},	//Внутренняя переменная var4
	{196	,1	,1	,&var40},	//Внутренняя переменная var40
	{197	,1	,1	,&var41},	//Внутренняя переменная var41
	{198	,1	,1	,&var42},	//Внутренняя переменная var42
	{199	,1	,1	,&var43},	//Внутренняя переменная var43
	{200	,1	,1	,&var44},	//Внутренняя переменная var44
	{201	,8	,1	,&var45},	//Внутренняя переменная var45
	{202	,8	,1	,&var46},	//Внутренняя переменная var46
	{203	,1	,1	,&var48},	//Внутренняя переменная var48
	{204	,1	,1	,&var49},	//Внутренняя переменная var49
	{205	,8	,1	,&var5},	//Внутренняя переменная var5
	{206	,1	,1	,&var51},	//Внутренняя переменная var51
	{207	,1	,1	,&var52},	//Внутренняя переменная var52
	{208	,1	,1	,&var53},	//Внутренняя переменная var53
	{209	,1	,1	,&var54},	//Внутренняя переменная var54
	{210	,1	,1	,&var55},	//Внутренняя переменная var55
	{211	,1	,1	,&var56},	//Внутренняя переменная var56
	{212	,1	,1	,&var57},	//Внутренняя переменная var57
	{213	,1	,1	,&var58},	//Внутренняя переменная var58
	{214	,1	,1	,&var59},	//Внутренняя переменная var59
	{215	,8	,1	,&var6},	//Внутренняя переменная var6
	{216	,1	,1	,&var60},	//Внутренняя переменная var60
	{217	,1	,1	,&var61},	//Внутренняя переменная var61
	{218	,8	,1	,&var7},	//Внутренняя переменная var7
	{219	,8	,1	,&var8},	//Внутренняя переменная var8
	{220	,8	,1	,&var9},	//Внутренняя переменная var9
	{-1,0,NULL},
};
static char NameSaveFile[]="rpu.bin\0"; //Имя файла сохранения переменных
#pragma pop
static VarSaveCtrl saveVariables[]={	//Id переменных для сохранения
	{93,"fEM_A0UX00RSS\0"},	//(A0UX00RSS) Эффективный радиус АЗ
	{94,"fEM_A0UX13RSS\0"},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{95,"fEM_A0UX14RSS\0"},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{96,"fEM_A0UX15RSS\0"},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{97,"fEM_B0UX03RSS\0"},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{98,"fEM_B0UX04RSS\0"},	//(B0UX04RSS) Второй коэффициент калибровки камеры4
	{99,"fEM_B0UX05RSS\0"},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{100,"fEM_R0IN11NRP\0"},	//(R0IN11NRP) Коэффициент A (РПУ к 1)
	{101,"fEM_R0IN12NRP\0"},	//(R0IN12NRP) Коэффициент B (РПУ к 1)
	{102,"fEM_R0IN21NRP\0"},	//(R0IN21NRP) Коэффициент A (РПУ к 2)
	{103,"fEM_R0IN22NRP\0"},	//(R0IN22NRP) Коэффициент B (РПУ к 2)
	{104,"fEM_R0IN31NRP\0"},	//(R0IN31NRP) Коэффициент A (РПУ к 3)
	{105,"fEM_R0IN32NRP\0"},	//(R0IN32NRP) Коэффициент B (РПУ к 3)
	{106,"fEM_R0IN61NRP\0"},	//(R0IN61NRP) Коэффициент A (РПУ к 6)
	{107,"fEM_R0IN62NRP\0"},	//(R0IN62NRP) Коэффициент B (РПУ к 6)
	{108,"fEM_R0IN71NRP\0"},	//(R0IN71NRP) Коэффициент A (РПУ к 7)
	{109,"fEM_R0IN72NRP\0"},	//(R0IN72NRP) Коэффициент B (РПУ к 7)
	{110,"fEM_R0UH02RSS\0"},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{111,"fEM_R0UH03RSS\0"},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{112,"fEM_R0UH05RSS\0"},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{113,"fEM_R0UH21RSS\0"},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{114,"fEM_R0UH22RSS\0"},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{115,"fEM_R0UH23RSS\0"},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{116,"fEM_R0UL52RSS\0"},	//(R0UL52RSS) Уровень АС по мощности
	{117,"fEM_R0UR01RRP\0"},	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
	{118,"fEM_R0UT01RZZ\0"},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{119,"fEM_R0UT02RZZ\0"},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{120,"fEM_R0UT61RZZ\0"},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{121,"fEM_R0UT62RZZ\0"},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{122,"fEM_R0UT71RZZ\0"},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{123,"fEM_R0UT72RZZ\0"},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{124,"fEM_R7UX00RSS\0"},	//(R7UX00RSS) X-координата АЗ1 (см)
	{125,"fEM_R7UX13RSS\0"},	//(R7UX13RSS) X-координата камеры R7IN51
	{126,"fEM_R7UX14RSS\0"},	//(R7UX14RSS) X-координата камеры R7IN52
	{127,"fEM_R7UX15RSS\0"},	//(R7UX15RSS) X-координата камеры R7IN53
	{128,"fEM_R7UY00RSS\0"},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{129,"fEM_R7UY13RSS\0"},	//(R7UY13RSS) Y-координата камеры R7IN51
	{130,"fEM_R7UY14RSS\0"},	//(R7UY14RSS) Y-координата камеры R7IN52
	{131,"fEM_R7UY15RSS\0"},	//(R7UY15RSS) Y-координата камеры R7IN53
	{132,"fEM_R7UY22RSS\0"},	//(R7UY22RSS) 2-й коэффициент ф-ции смещения
	{133,"fEM_R7UY32RSS\0"},	//(R7UY32RSS) 1-й коэффициент ф-ции смещения
	{134,"fEM_R7UY42RSS\0"},	//(R7UY42RSS) уровень корректировки
	{135,"fEM_Z7UE20RRP\0"},	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
	{136,"iEM_R7UY12RSS\0"},	//(R7UY12RSS) интервал усреднения
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
	{&R0VN13RRP,8,0},	//( - , RPU) Нейтронный поток по камере  СНМ-11 канал 5
	{&TTLrpu,3,2},	//( - , RPU) ttl
	{&R0IN01VRP,8,3},	//( - K01VCHS, RPU) Частота с ВЧС к 1
	{&R0IN02VRP,8,5},	//( - K02VCHS, RPU) Частота с ВЧС к 2
	{&R0IN03VRP,8,7},	//( - K01VCHS, RPU) Частота с ВЧС к 3
	{&R0IN06VRP,8,9},	//( - K01VCHS, RPU) Частота с ВЧС к 6
	{&R0IN07VRP,8,11},	//( - K02VCHS, RPU) Частота с ВЧС к 7
	{&VMETRP06,3,13},	//( - K05VASR, RPU) вход Метр Давленение 0.6
	{&METRP06,8,14},	//( - , RPU) Метр давление 0.6
	{&VMETRP12,3,16},	//( - K06VASR, RPU) вход Метр Давленение 1.2
	{&METRP12,8,17},	//( - , RPU) Метр давление 1.2
	{&R0VN02RRP,8,19},	//( - , RPU) Уровень мощности канал 5
	{&R0IN01RRP,8,21},	//( - , RPU) Частота СНМ-11 Гц (канал 5)
	{&R0IN02RRP,8,23},	//( - , RPU) Частота КНК15-1 Гц (канал 5)
	{&R0VN03RRP,8,25},	//( - , RPU) Измеренный нейтронный поток канал 5
	{&R0IN03RRP,8,27},	//( - , RPU) Частота КНК53М Гц (канал 5)
	{&R0VN23RRP,8,29},	//( - , RPU) Нейтронный поток по камере КНК15-1 канал 5
	{&R0VN33RRP,8,31},	//( - , RPU) Нейтронный поток по камере КНК53М канал 5
	{&R0VN15RRP,3,33},	//( - , RPU) Номер ведущей камеры канал 5
	{&R0IN06RRP,8,34},	//( - , RPU) Частота СНМ-11 Гц (канал 6) от ПТИ
	{&R0IN07RRP,8,36},	//( - , RPU) Частота СНМ-11 Гц (канал 7)
	{&A0IT03IRP,3,38},	//( - K01VASR, RPU) Температура АЗ1-3
	{&A0CT01IRP,8,39},	//( - , RPU) Температура АЗ1-3
	{&B0IT03IRP,3,41},	//( - K02VASR, RPU) Температура АЗ2-3
	{&B0CT01IRP,8,42},	//( - , RPU) Температура АЗ2-3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_RPU[]={
	{&R0IN03TEM,3,0},	//( - K01temp, RPU) кол-во имп
	{&R0IN03CYK,8,1},	//( - K01cykl, RPU) цикл
	{&B8VC01RDU,8,3},	//( - , RPU) Координата АЗ2, мм
	{&fEM_R0UH02RSS,8,5},	//( - , RPU) Коэфф. преобразования частота->нейтр/с КНК15-1
	{&fEM_R0UH03RSS,8,7},	//( - , RPU) Коэфф. преобразования частота->нейтр/с КНК53М
	{&fEM_R7UX00RSS,8,9},	//( - , RPU) X-координата АЗ1 (см)
	{&fEM_R7UY00RSS,8,11},	//( - , RPU) Y-координата АЗ1 (см)
	{&fEM_R7UX13RSS,8,13},	//( - , RPU) X-координата камеры R7IN51
	{&fEM_R7UX14RSS,8,15},	//( - , RPU) X-координата камеры R7IN52
	{&fEM_R7UX15RSS,8,17},	//( - , RPU) X-координата камеры R7IN53
	{&fEM_R7UY13RSS,8,19},	//( - , RPU) Y-координата камеры R7IN51
	{&fEM_R7UY14RSS,8,21},	//( - , RPU) Y-координата камеры R7IN52
	{&fEM_R7UY15RSS,8,23},	//( - , RPU) Y-координата камеры R7IN53
	{&fEM_A0UX00RSS,8,25},	//( - , RPU) Эффективный радиус АЗ
	{&fEM_A0UX13RSS,8,27},	//( - , RPU) Первый коэффициент калибровки камеры 13
	{&fEM_A0UX14RSS,8,29},	//( - , RPU) Первый коэффициент калибровки камеры 14
	{&fEM_A0UX15RSS,8,31},	//( - , RPU) Первый коэффициент калибровки камеры 15
	{&fEM_B0UX03RSS,8,33},	//( - , RPU) Второй коэффициент калибровки камеры 3
	{&fEM_B0UX04RSS,8,35},	//( - , RPU) Второй коэффициент калибровки камеры4
	{&fEM_B0UX05RSS,8,37},	//( - , RPU) Второй коэффициент калибровки камеры 5
	{&fEM_R0UH05RSS,8,39},	//( - , RPU) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_R0UR01RRP,8,41},	//( - , RPU) Уставка СНМ11 в БЗ - АС по частоте
	{&fEM_R0UT02RZZ,8,43},	//( - , RPU) Верхний предел шкалы датчика температуры
	{&fEM_R0UT01RZZ,8,45},	//( - , RPU) Нижний предел шкалы датчика температуры
	{&fEM_R0UT72RZZ,8,47},	//( - , RPU) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{&fEM_R0UT71RZZ,8,49},	//( - , RPU) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{&fEM_R0UT62RZZ,8,51},	//( - , RPU) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{&fEM_R0UT61RZZ,8,53},	//( - , RPU) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{&fEM_R0UL52RSS,8,55},	//( - , RPU) Уровень АС по мощности
	{&fEM_Z7UE20RRP,8,57},	//( - , RPU) Время задержки сигнала на включение источников питания после снятия команды на отключение
	{&fEM_R0UH21RSS,8,59},	//( - , RPU) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{&fEM_R0UH22RSS,8,61},	//( - , RPU) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{&fEM_R0UH23RSS,8,63},	//( - , RPU) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{&fEM_R0IN11NRP,8,65},	//( - , RPU) Коэффициент A (РПУ к 1)
	{&fEM_R0IN12NRP,8,67},	//( - , RPU) Коэффициент B (РПУ к 1)
	{&fEM_R0IN21NRP,8,69},	//( - , RPU) Коэффициент A (РПУ к 2)
	{&fEM_R0IN22NRP,8,71},	//( - , RPU) Коэффициент B (РПУ к 2)
	{&fEM_R0IN31NRP,8,73},	//( - , RPU) Коэффициент A (РПУ к 3)
	{&fEM_R0IN32NRP,8,75},	//( - , RPU) Коэффициент B (РПУ к 3)
	{&fEM_R0IN61NRP,8,77},	//( - , RPU) Коэффициент A (РПУ к 6)
	{&fEM_R0IN62NRP,8,79},	//( - , RPU) Коэффициент B (РПУ к 6)
	{&fEM_R0IN71NRP,8,81},	//( - , RPU) Коэффициент A (РПУ к 7)
	{&fEM_R0IN72NRP,8,83},	//( - , RPU) Коэффициент B (РПУ к 7)
	{&iEM_R7UY12RSS,3,85},	//( - , RPU) интервал усреднения
	{&fEM_R7UY32RSS,8,86},	//( - , RPU) 1-й коэффициент ф-ции смещения
	{&fEM_R7UY22RSS,8,88},	//( - , RPU) 2-й коэффициент ф-ции смещения
	{&fEM_R7UY42RSS,8,90},	//( - , RPU) уровень корректировки
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
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MRPS[]={
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
static char buf_VCHS01[150];	//VCHS01
static vchs_inipar ini_VCHS01={0xc4,255,8,0xff,0,0x1,0x1,0,0,0,};
#pragma pack(push,1)
static table_drv table_VCHS01={0,0,&ini_VCHS01,buf_VCHS01,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS01[]={
	{&R0IN01VRP,8,0},
	{&R0IN02VRP,8,5},
	{&R0DE01LRP,3,26},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS02[150];	//VCHS02
static vchs_inipar ini_VCHS02={0xc4,255,8,0xff,0,0x1,0x1,0,0,0,};
#pragma pack(push,1)
static table_drv table_VCHS02={0,0,&ini_VCHS02,buf_VCHS02,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS02[]={
	{&R0IN03VRP,8,0},
	{&R0IN03TEM,3,10},
	{&R0IN03CYK,8,16},
	{&R0DE02LRP,3,26},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS03[150];	//VCHS03
static vchs_inipar ini_VCHS03={0xc4,255,8,0xff,0,0x1,0x1,0,0,0,};
#pragma pack(push,1)
static table_drv table_VCHS03={0,0,&ini_VCHS03,buf_VCHS03,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS03[]={
	{&R0IN06VRP,8,0},
	{&R0IN07VRP,8,5},
	{&R0DE03LRP,3,26},
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
	{0xc4,0x01,10,150,def_buf_VCHS01,&table_VCHS01},	//VCHS01
	{0xc4,0x02,10,150,def_buf_VCHS02,&table_VCHS02},	//VCHS02
	{0xc4,0x03,10,150,def_buf_VCHS03,&table_VCHS03},	//VCHS03
	{0xc2,0x07,7,194,def_buf_VDS32,&table_VDS32},	//VDS32
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){	//Инициализация переменных для хранения
	setAsFloat(93,11.0);
	setAsFloat(94,1.0);
	setAsFloat(95,1.0);
	setAsFloat(96,1.0);
	setAsFloat(97,0);
	setAsFloat(98,0);
	setAsFloat(99,0.0);
	setAsFloat(100,1);
	setAsFloat(101,0);
	setAsFloat(102,1);
	setAsFloat(103,0);
	setAsFloat(104,1);
	setAsFloat(105,0);
	setAsFloat(106,1);
	setAsFloat(107,0);
	setAsFloat(108,1);
	setAsFloat(109,0);
	setAsFloat(110,37037.04 );
	setAsFloat(111,975000.0);
	setAsFloat(112,32000.0);
	setAsFloat(113,4000);
	setAsFloat(114,100000);
	setAsFloat(115,1000000);
	setAsFloat(116,5100);
	setAsFloat(117,1000);
	setAsFloat(118,0);
	setAsFloat(119,600);
	setAsFloat(120,100);
	setAsFloat(121,90);
	setAsFloat(122,200);
	setAsFloat(123,150);
	setAsFloat(124,1570.0);
	setAsFloat(125,1570.0);
	setAsFloat(126,1269);
	setAsFloat(127,1281.2);
	setAsFloat(128,506.5);
	setAsFloat(129,248.0);
	setAsFloat(130,572.4);
	setAsFloat(131,246.8);
	setAsFloat(132,0.260609);
	setAsFloat(133,-0.098010);
	setAsFloat(134,9.9);
	setAsFloat(135,210);
	setAsShort(136,10);
}

// Вставка к VCHS
void init_dataVchs(vchs_data *vch_data)
{
    int i;
    for (i = 0; i < 2; i++)
    {
        vch_data->takt[i] = 0.5;
        vch_data->cykl[i] = 0.5;
        vch_data->cyklS[i] = 0.5;
        vch_data->perm[i] = 0;
        vch_data->fvch[i] = 0;
        vch_data->tempI[i] = 0;
    }
}

void VCHS_post(vchs_data *vch_data)
{
    float fslow = 0, ffast = 0, zer = 0.0;
    int i;
    for (i = 0; i < 2; i++)
    {
        if (vch_data->perm[i] <= 0)
        {
            if (vch_data->SVCHS[i] == 1)
            {
                if (vch_data->cyklS[i] == 10)
                    vch_data->cyklS[i] = 1.0;
                else
                    vch_data->cyklS[i] = 0.01;
                vch_data->SVCHS[i] = 0;
                vch_data->takt[i] = 0;
                vch_data->cykl[i] = vch_data->cyklS[i];
                continue;
            }
            ffast = vch_data->tempI[i] / vch_data->takt[i];

                if(ffast < 80 )
                    vch_data->cyklS[i] = 10;
                    else   
                    vch_data->cyklS[i] = 1 / ((ffast / 64000) + 1);

            // if (ffast < 50.0){
                
            //     if(vch_data->tempI[i] <= 1){
            //         vch_data->cyklS[i] = 50;
            //     }else{
            //          fslow = 50 / vch_data->tempI[i] * vch_data->takt[i];
            //          if(fslow < 4){
            //             vch_data->cyklS[i] = 4;    
            //          }else{
            //             vch_data->cyklS[i] = fslow;
            //          }
            //     }

            // }
            // else
            // {
            //     vch_data->cyklS[i] = 1 / ((ffast / 64000) + 1);
            // }
            vch_data->fvch[i] = ffast;
            vch_data->takt[i] = 0;
            vch_data->cykl[i] = vch_data->cyklS[i];
        }
    }
    for (i = 0; i < 2; i++)
        if (fpcomp(&vch_data->cykl[i], &zer) > 0)
        {
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
sschar var37;
sschar var39;
sschar var47;
sschar var50;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psfloat  array_m175_x0_1[10];
psfloat  array_m174_x0_1[10];
psbool  array_m145_x_1[6] = {&var13,&var14,&R0DE36LRP,&R0DE37LRP,&R0DE38LRP,&R0DE39LRP};
psint  array_m127_x_1[6] = {&R0DE01LRP,&R0DE02LRP,&R0DE03LRP,&R0DE08LRP,&R0DE06LRP,&R0DE07LRP};

/* Объявление структур */
_S_ffiltr  S_ffiltr_175_1 = {&R0IN03VRP,&fEM_R7UY42RSS,&fEM_R7UY32RSS,&fEM_R7UY22RSS,&iEM_R7UY12RSS,&iRM_10_,&var1,&internal1_m175_xptr,&internal1_m175_stepc,array_m175_x0_1,&internal1_m175_flst,&internal1_m175_SumS,&bFirstEnterFlag};
_S_ffiltr  S_ffiltr_174_1 = {&R0IN02VRP,&fEM_R7UY42RSS,&fEM_R7UY32RSS,&fEM_R7UY22RSS,&iEM_R7UY12RSS,&iRM_10_,&var2,&internal1_m174_xptr,&internal1_m174_stepc,array_m174_x0_1,&internal1_m174_flst,&internal1_m174_SumS,&bFirstEnterFlag};
_S_scalzz  S_scalzz_191_1 = {&VMETRP12,&iRM_3200_,&iRM_16000_,&fRM_0_,&fRM_1_2,&var3,&internal1_m191_y0};
_S_scalzz  S_scalzz_190_1 = {&VMETRP06,&iRM_3200_,&iRM_16000_,&fRM_0_,&fRM_0_6,&var4,&internal1_m190_y0};
_S_pogrvh  S_pogrvh_176_1 = {&R0IN07VRP,&fEM_R0IN71NRP,&fEM_R0IN72NRP,&var5};
_S_pogrvh  S_pogrvh_164_1 = {&R0IN06VRP,&fEM_R0IN61NRP,&fEM_R0IN62NRP,&var6};
_S_pogrvh  S_pogrvh_162_1 = {&R0IN03VRP,&fEM_R0IN31NRP,&fEM_R0IN32NRP,&var7};
_S_pogrvh  S_pogrvh_160_1 = {&R0IN02VRP,&fEM_R0IN21NRP,&fEM_R0IN22NRP,&var8};
_S_pogrvh  S_pogrvh_158_1 = {&R0IN01VRP,&fEM_R0IN11NRP,&fEM_R0IN12NRP,&var9};
_S_or4  S_or4_60_1 = {&var53,&var27,&var35,&var36,&var10};
_S_noto  S_noto_146_1 = {&var15,&var11};
_S_and5  S_and5_36_1 = {&var11,&R0IE11LRP,&R0IE12LRP,&R0IE13LRP,&var22,&var12};
_S_or2  S_or2_140_1 = {&R0DEB1LRP,&R0DEB2LRP,&var13};
_S_or2  S_or2_147_1 = {&R0DEB3LRP,&R0DEB4LRP,&var14};
_S_or3  S_or3_144_1 = {&var18,&var17,&var16,&var15};
_S_orn  S_orn_145_1 = {array_m145_x_1,&iRM_6_,&var16};
_S_and2  S_and2_129_1 = {&R0DE31LRP,&R0DE32LRP,&var17};
_S_diagndev  S_diagndev_127_1 = {array_m127_x_1,&iRM_6_,&var18,&var19,&vainSFloat};
_S_ocham  S_ocham_11_1 = {&var9,&var8,&var7,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX13RSS,&fEM_B0UX03RSS,&fEM_A0UX14RSS,&fEM_B0UX04RSS,&fEM_A0UX15RSS,&fEM_B0UX05RSS,&fEM_R7UX13RSS,&fEM_R7UY13RSS,&fEM_R7UX14RSS,&fEM_R7UY14RSS,&fEM_R7UX15RSS,&fEM_R7UY15RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&fEM_R0UH21RSS,&fEM_R0UH22RSS,&fEM_R0UH23RSS,&var20,&var21,&var22,&var23,&var24,&var25,&var26,&internal1_m11_Nk};
_S_or2  S_or2_55_1 = {&A6IS11LRP,&B6IS11LRP,&vainSBool};
_S_or2  S_or2_83_1 = {&var60,&var61,&var27};
_S_or4  S_or4_41_1 = {&var34,&var32,&var33,&var30,&var28};
_S_or2  S_or2_88_1 = {&var59,&var48,&var29};
_S_or2  S_or2_110_1 = {&var31,&var29,&var30};
_S_or2  S_or2_84_1 = {&var58,&var51,&var31};
_S_and3  S_and3_37_1 = {&var12,&var44,&var38,&var32};
_S_and3  S_and3_44_1 = {&var42,&R0IE14LRP,&var54,&var33};
_S_and3  S_and3_43_1 = {&R0IE15LRP,&var42,&var55,&var34};
_S_and3  S_and3_50_1 = {&R0IE14LRP,&var42,&var57,&var35};
_S_and3  S_and3_49_1 = {&var56,&R0IE15LRP,&var42,&var36};
_S_geterr  S_geterr_47_1 = {&var6,&dRM_0_,&iRM_0_,&bRM_0_,&var37,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_noto  S_noto_68_1 = {&var43,&var38};
_S_geterr  S_geterr_46_1 = {&var5,&dRM_0_,&iRM_0_,&bRM_0_,&var39,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_zzfs  S_zzfs_59_1 = {&var41,&fEM_Z7UE20RRP,&var40,&internal1_m59_tx,&internal1_m59_y0};
_S_or3  S_or3_58_1 = {&A6IS11LRP,&B6IS11LRP,&R0EE02LDU,&var41};
_S_noto  S_noto_56_1 = {&var40,&var42};
_S_zzfs  S_zzfs_67_1 = {&R0EE02LDU,&fEM_Z7UE20RRP,&var43,&internal1_m67_tx,&internal1_m67_y0};
_S_bol  S_bol_34_1 = {&var21,&fEM_R0UL52RSS,&var44};
_S_scalzz  S_scalzz_75_1 = {&B0IT03IRP,&iRM_3200_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var45,&internal1_m75_y0};
_S_scalzz  S_scalzz_73_1 = {&A0IT03IRP,&iRM_3200_,&iRM_16000_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var46,&internal1_m73_y0};
_S_geterr  S_geterr_77_1 = {&var46,&dRM_0_,&iRM_0_,&bRM_0_,&var47,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_89_1 = {&var45,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var48,&internal1_m89_y1};
_S_drg  S_drg_104_1 = {&var45,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var49,&internal1_m104_y1};
_S_geterr  S_geterr_79_1 = {&var45,&dRM_0_,&iRM_0_,&bRM_0_,&var50,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_87_1 = {&var46,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var51,&internal1_m87_y1};
_S_drg  S_drg_101_1 = {&var46,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var52,&internal1_m101_y1};
_S_noto  S_noto_64_1 = {&var12,&var53};
_S_bol  S_bol_51_1 = {&var5,&fEM_R0UR01RRP,&var54};
_S_bol  S_bol_42_1 = {&var6,&fEM_R0UR01RRP,&var55};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  scalzz(&S_scalzz_73_1);
  scalzz(&S_scalzz_75_1);
  or2(&S_or2_55_1);
  diagndev(&S_diagndev_127_1);
  and2(&S_and2_129_1);
  or2(&S_or2_147_1);
  or2(&S_or2_140_1);
  scalzz(&S_scalzz_191_1);
  ffiltr(&S_ffiltr_175_1);
  drg(&S_drg_101_1);
  drg(&S_drg_87_1);
  geterr(&S_geterr_79_1);
  drg(&S_drg_104_1);
  drg(&S_drg_89_1);
  geterr(&S_geterr_77_1);
  zzfs(&S_zzfs_67_1);
  or3(&S_or3_58_1);
  zzfs(&S_zzfs_59_1);
  noto(&S_noto_68_1);
  setData(&var58,&var47);
  or2(&S_or2_84_1);
  setData(&var59,&var50);
  or2(&S_or2_88_1);
  setData(&var60,&var47);
  setData(&var61,&var50);
  or2(&S_or2_83_1);
  orn(&S_orn_145_1);
  or3(&S_or3_144_1);
  noto(&S_noto_146_1);
  pogrvh(&S_pogrvh_158_1);
  pogrvh(&S_pogrvh_160_1);
  pogrvh(&S_pogrvh_162_1);
  pogrvh(&S_pogrvh_164_1);
  pogrvh(&S_pogrvh_176_1);
  scalzz(&S_scalzz_190_1);
  ffiltr(&S_ffiltr_174_1);
  bol(&S_bol_42_1);
  bol(&S_bol_51_1);
  noto(&S_noto_56_1);
  geterr(&S_geterr_46_1);
  geterr(&S_geterr_47_1);
  setData(&var56,&var39);
  and3(&S_and3_49_1);
  setData(&var57,&var37);
  and3(&S_and3_50_1);
  and3(&S_and3_43_1);
  and3(&S_and3_44_1);
  or2(&S_or2_110_1);
  ocham(&S_ocham_11_1);
  and5(&S_and5_36_1);
  noto(&S_noto_64_1);
  bol(&S_bol_34_1);
  and3(&S_and3_37_1);
  or4(&S_or4_41_1);
  or4(&S_or4_60_1);
  setData(idMETRP12,&var3);
  setData(idMETRP06,&var4);
  moveData(idB1VS21LRP,idB1IS21LRP);
  moveData(idA1VS21LRP,idA1IS21LRP);
  setData(idTTLrpu,&var19);
  setData(idTestDiagnRPU,&var15);
  setData(idR0DE3DLRP,&var14);
  setData(idR0DE3CLRP,&var13);
  moveData(idB7MZ31LRP,idC1MZ31LRP);
  moveData(idA7MZ31LRP,idC1MZ31LRP);
  moveData(idB3VS21LRP,idB3IS21LRP);
  moveData(idA3VS21LRP,idA3IS21LRP);
  moveData(idB2VS21LRP,idB2IS21LRP);
  moveData(idA2VS21LRP,idA2IS21LRP);
  setData(idR7VE70LRP,&var10);
  setData(idR0VN13RRP,&var23);
  setData(idR0VN71LRP,&var44);
  setData(idA1VT71LRP,&var30);
  setData(idR0IE04LRP,&var40);
  setData(idR0IE03LRP,&var40);
  setData(idA0EE01LRP,&var12);
  setData(idB0VT71LRP,&var29);
  setData(idB0VT61LRP,&var49);
  setData(idB0CT01IRP,&var45);
  setData(idR0ET02LRP,&var50);
  setData(idR0ET01LRP,&var47);
  setData(idA0VT71LRP,&var31);
  setData(idA0VT61LRP,&var52);
  setData(idA0CT01IRP,&var46);
  setData(idR0IN07RRP,&var5);
  setData(idR7VN71LRP,&var28);
  setData(idR0IN06RRP,&var6);
  setData(idR0IE02LRP,&var43);
  setData(idR0IE01LRP,&var43);
  setData(idR0VN15RRP,&var26);
  setData(idR0VN33RRP,&var25);
  setData(idR0VN23RRP,&var24);
  setData(idA0EE02LRP,&var22);
  setData(idR0IN03RRP,&var1);
  setData(idR0VN03RRP,&var20);
  setData(idR0IN02RRP,&var2);
  setData(idR0IN01RRP,&var9);
  setData(idR0VN02RRP,&var21);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<10;i++ )
    array_m175_x0_1[i] = &(&internal1_m175_x0)[i*5];
  for( i=0;i<10;i++ )
    array_m174_x0_1[i] = &(&internal1_m174_x0)[i*5];
}
void MainCycle(void){
	Scheme();
}
#endif