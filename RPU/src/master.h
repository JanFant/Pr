#ifndef RPU_H
#define RPU_H
// Подсистема RPU:RPU
static char SimulOn=0;
static short CodeSub=8;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt, taktScheme=0, taktSS=0;
#define SIZE_BUFFER 494
static char BUFFER[494];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.31\0", 5432, "192.168.10.131\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0DE39LRP	 BUFFER[0]	//(sbk:20 - S09SBK, DiagnRPU) диагностика шкафа РПУ МП24-2 место 4
#define idR0DE39LRP	 1	//(sbk:20 - S09SBK, DiagnRPU) диагностика шкафа РПУ МП24-2 место 4
#define R0DE38LRP	 BUFFER[2]	//(sbk:20 - S08SBK, DiagnRPU) диагностика шкафа РПУ МП15-3 место 3
#define idR0DE38LRP	 2	//(sbk:20 - S08SBK, DiagnRPU) диагностика шкафа РПУ МП15-3 место 3
#define R0DE37LRP	 BUFFER[4]	//(sbk:20 - S07SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 2
#define idR0DE37LRP	 3	//(sbk:20 - S07SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 2
#define R0DE36LRP	 BUFFER[6]	//(sbk:20 - S06SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 1
#define idR0DE36LRP	 4	//(sbk:20 - S06SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 1
#define R0DE35LRP	 BUFFER[8]	//(sbk:20 - S05SBK, DiagnRPU) диагностика шкафа РПУ температура больше 53
#define idR0DE35LRP	 5	//(sbk:20 - S05SBK, DiagnRPU) диагностика шкафа РПУ температура больше 53
#define R0DE34LRP	 BUFFER[10]	//(sbk:20 - S04SBK, DiagnRPU) диагностика шкафа РПУ температура меньше 43
#define idR0DE34LRP	 6	//(sbk:20 - S04SBK, DiagnRPU) диагностика шкафа РПУ температура меньше 43
#define R0DE33LRP	 BUFFER[12]	//(sbk:20 - S03SBK, DiagnRPU) диагностика шкафа РПУ двери
#define idR0DE33LRP	 7	//(sbk:20 - S03SBK, DiagnRPU) диагностика шкафа РПУ двери
#define R0DE32LRP	 BUFFER[14]	//(sbk:20 - S02SBK, DiagnRPU) диагностика шкафа РПУ сеть 2
#define idR0DE32LRP	 8	//(sbk:20 - S02SBK, DiagnRPU) диагностика шкафа РПУ сеть 2
#define R0DE31LRP	 BUFFER[16]	//(sbk:20 - S01SBK, DiagnRPU) диагностика шкафа РПУ сеть 1
#define idR0DE31LRP	 9	//(sbk:20 - S01SBK, DiagnRPU) диагностика шкафа РПУ сеть 1
#define R0DE07LRP	 BUFFER[18]	//(vds32:07 - Diagn, DiagnRPU) диагностика модуля РПУ-ВДС место 7
#define idR0DE07LRP	 10	//(vds32:07 - Diagn, DiagnRPU) диагностика модуля РПУ-ВДС место 7
#define R0DE08LRP	 BUFFER[21]	//(fds16:08 - Diagn, DiagnRPU) диагностика модуля РПУ-ФДС место 8
#define idR0DE08LRP	 11	//(fds16:08 - Diagn, DiagnRPU) диагностика модуля РПУ-ФДС место 8
#define R0DE06LRP	 BUFFER[24]	//(vas84:06 - Diagn, DiagnRPU) диагностика модуля РПУ-ВАС место 6
#define idR0DE06LRP	 12	//(vas84:06 - Diagn, DiagnRPU) диагностика модуля РПУ-ВАС место 6
#define R0DE03LRP	 BUFFER[27]	//(vchs:03 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 3
#define idR0DE03LRP	 13	//(vchs:03 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 3
#define R0DE02LRP	 BUFFER[30]	//(vchs:02 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 2
#define idR0DE02LRP	 14	//(vchs:02 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 2
#define R0DE01LRP	 BUFFER[33]	//(vchs:01 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 1
#define idR0DE01LRP	 15	//(vchs:01 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 1
#define R0EE02LDU	 BUFFER[36]	//( - , RPU) Питание  АКНП  отключить
#define idR0EE02LDU	 16	//( - , RPU) Питание  АКНП  отключить
#define B7MZ31LRP	 BUFFER[38]	//( - , RPU) Клапан ОБДУВ АЗ2 открыть(обесточить)
#define idB7MZ31LRP	 17	//( - , RPU) Клапан ОБДУВ АЗ2 открыть(обесточить)
#define A7MZ31LRP	 BUFFER[40]	//( - , RPU) Клапан ОБДУВ АЗ1 открыть(обесточить)
#define idA7MZ31LRP	 18	//( - , RPU) Клапан ОБДУВ АЗ1 открыть(обесточить)
#define C1MZ31LRP	 BUFFER[42]	//(vds32:07 - K07VDSR, - ) Кнопка ОБДУВ  на РПУ
#define idC1MZ31LRP	 19	//(vds32:07 - K07VDSR, - ) Кнопка ОБДУВ  на РПУ
#define C1MD31LRP	 BUFFER[44]	//(vds32:07 - K06VDSR, - ) Кнопка ОБЩИЙ СБРОС  на РПУ
#define idC1MD31LRP	 20	//(vds32:07 - K06VDSR, - ) Кнопка ОБЩИЙ СБРОС  на РПУ
#define B3VS21LRP	 BUFFER[46]	//(fds16:08 - K06FDSR, - ) Индикация - Приход на НУ ИС2
#define idB3VS21LRP	 21	//(fds16:08 - K06FDSR, - ) Индикация - Приход на НУ ИС2
#define A3VS21LRP	 BUFFER[48]	//(fds16:08 - K05FDSR, - ) Индикация - Приход на НУ ИС1
#define idA3VS21LRP	 22	//(fds16:08 - K05FDSR, - ) Индикация - Приход на НУ ИС1
#define R0IN07VRP	 BUFFER[50]	//(vchs:03 - K02VCHS, - ) Частота с ВЧС к 7
#define idR0IN07VRP	 23	//(vchs:03 - K02VCHS, - ) Частота с ВЧС к 7
#define R0IN06VRP	 BUFFER[55]	//(vchs:03 - K01VCHS, - ) Частота с ВЧС к 6
#define idR0IN06VRP	 24	//(vchs:03 - K01VCHS, - ) Частота с ВЧС к 6
#define R0IN03VRP	 BUFFER[60]	//(vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
#define idR0IN03VRP	 25	//(vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
#define R0IN02VRP	 BUFFER[65]	//(vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
#define idR0IN02VRP	 26	//(vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
#define R0IN01VRP	 BUFFER[70]	//(vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
#define idR0IN01VRP	 27	//(vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
#define B1VS21LRP	 BUFFER[75]	//(fds16:08 - K02FDSR, - ) Индикация - Приход на НУ ББ2
#define idB1VS21LRP	 28	//(fds16:08 - K02FDSR, - ) Индикация - Приход на НУ ББ2
#define B1IS21LRP	 BUFFER[77]	//(vds32:07 - K12VDSR, - ) Приход на НУ ББ2
#define idB1IS21LRP	 29	//(vds32:07 - K12VDSR, - ) Приход на НУ ББ2
#define A1VS21LRP	 BUFFER[79]	//(fds16:08 - K01FDSR, - ) Индикация - Приход на НУ ББ1
#define idA1VS21LRP	 30	//(fds16:08 - K01FDSR, - ) Индикация - Приход на НУ ББ1
#define A1IS21LRP	 BUFFER[81]	//(vds32:07 - K09VDSR, - ) Приход на НУ ББ1
#define idA1IS21LRP	 31	//(vds32:07 - K09VDSR, - ) Приход на НУ ББ1
#define R0IN07RIP	 BUFFER[83]	//( - , MRPS) Частота СНМ-11 Гц (канал 7) от ПТИ
#define idR0IN07RIP	 32	//( - , MRPS) Частота СНМ-11 Гц (канал 7) от ПТИ
#define R0IN06RIP	 BUFFER[88]	//( - , MRPS) Частота СНМ-11 Гц (канал 6) от ПТИ
#define idR0IN06RIP	 33	//( - , MRPS) Частота СНМ-11 Гц (канал 6) от ПТИ
#define R0IN03RIP	 BUFFER[93]	//( - , MRPS) Частота КНК53М Гц (канал 5) от ПТИ
#define idR0IN03RIP	 34	//( - , MRPS) Частота КНК53М Гц (канал 5) от ПТИ
#define R0IN02RIP	 BUFFER[98]	//( - , MRPS) Частота КНК15-1 Гц (канал 5) от ПТИ
#define idR0IN02RIP	 35	//( - , MRPS) Частота КНК15-1 Гц (канал 5) от ПТИ
#define R0IN01RIP	 BUFFER[103]	//( - , MRPS) Частота СНМ-11 Гц (канал 5) от ПТИ
#define idR0IN01RIP	 36	//( - , MRPS) Частота СНМ-11 Гц (канал 5) от ПТИ
#define R0IS01FI0	 BUFFER[108]	//( - , MRPS) Признак работы с имитатором
#define idR0IS01FI0	 37	//( - , MRPS) Признак работы с имитатором
#define R0DEB3LRP	 BUFFER[110]	//(sbk:20 - S12SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 8
#define idR0DEB3LRP	 38	//(sbk:20 - S12SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 8
#define R0DEB4LRP	 BUFFER[112]	//(sbk:20 - S13SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 8
#define idR0DEB4LRP	 39	//(sbk:20 - S13SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 8
#define R0DEB2LRP	 BUFFER[114]	//(sbk:20 - S11SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 7
#define idR0DEB2LRP	 40	//(sbk:20 - S11SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 7
#define R0DEB1LRP	 BUFFER[116]	//(sbk:20 - S10SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 7
#define idR0DEB1LRP	 41	//(sbk:20 - S10SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 7
#define TTLrpu	 BUFFER[118]	//( - , RPU) ttl
#define idTTLrpu	 42	//( - , RPU) ttl
#define TestDiagnRPU	 BUFFER[121]	//( - , RPU) Неисправность от диагностики
#define idTestDiagnRPU	 43	//( - , RPU) Неисправность от диагностики
#define R0DE3DLRP	 BUFFER[123]	//( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 8
#define idR0DE3DLRP	 44	//( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 8
#define R0DE3CLRP	 BUFFER[125]	//( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 7
#define idR0DE3CLRP	 45	//( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 7
#define R0ET02LRP	 BUFFER[127]	//( - , RPU) Признак наличия неисправности по температуре АЗ2-3
#define idR0ET02LRP	 46	//( - , RPU) Признак наличия неисправности по температуре АЗ2-3
#define B0IT03IRP	 BUFFER[129]	//(vas84:06 - K02VASR, - ) Температура АЗ2-3
#define idB0IT03IRP	 47	//(vas84:06 - K02VASR, - ) Температура АЗ2-3
#define R0ET01LRP	 BUFFER[132]	//( - , RPU) Признак наличия неисправности по температуре  АЗ1-3
#define idR0ET01LRP	 48	//( - , RPU) Признак наличия неисправности по температуре  АЗ1-3
#define A0VT71LRP	 BUFFER[134]	//( - , RPU) АС по температуре в АЗ1
#define idA0VT71LRP	 49	//( - , RPU) АС по температуре в АЗ1
#define A0VT61LRP	 BUFFER[136]	//( - , RPU) ПС по температуре в АЗ1
#define idA0VT61LRP	 50	//( - , RPU) ПС по температуре в АЗ1
#define A0CT01IRP	 BUFFER[138]	//( - , RPU) Температура АЗ1-3
#define idA0CT01IRP	 51	//( - , RPU) Температура АЗ1-3
#define A0IT03IRP	 BUFFER[143]	//(vas84:06 - K01VASR, - ) Температура АЗ1-3
#define idA0IT03IRP	 52	//(vas84:06 - K01VASR, - ) Температура АЗ1-3
#define R0IN07RRP	 BUFFER[146]	//( - , RPU) Частота СНМ-11 Гц (канал 7)
#define idR0IN07RRP	 53	//( - , RPU) Частота СНМ-11 Гц (канал 7)
#define R7VN71LRP	 BUFFER[151]	//( - , RPU) Сигнал тревоги по уровню нейтронного потока на диспетчера
#define idR7VN71LRP	 54	//( - , RPU) Сигнал тревоги по уровню нейтронного потока на диспетчера
#define R0IN06RRP	 BUFFER[153]	//( - , RPU) Частота СНМ-11 Гц (канал 6) от ПТИ
#define idR0IN06RRP	 55	//( - , RPU) Частота СНМ-11 Гц (канал 6) от ПТИ
#define R0IE02LRP	 BUFFER[158]	//(fds16:08 - K07FDSR, - ) Отключить питание ПР, ПУ канал 5
#define idR0IE02LRP	 56	//(fds16:08 - K07FDSR, - ) Отключить питание ПР, ПУ канал 5
#define R0IE01LRP	 BUFFER[160]	//(fds16:08 - K08FDSR, - ) Отключение питание детекторов канал 5
#define idR0IE01LRP	 57	//(fds16:08 - K08FDSR, - ) Отключение питание детекторов канал 5
#define R0VN15RRP	 BUFFER[162]	//( - , RPU) Номер ведущей камеры канал 5
#define idR0VN15RRP	 58	//( - , RPU) Номер ведущей камеры канал 5
#define R0VN33RRP	 BUFFER[165]	//( - , RPU) Нейтронный поток по камере КНК53М канал 5
#define idR0VN33RRP	 59	//( - , RPU) Нейтронный поток по камере КНК53М канал 5
#define R0VN23RRP	 BUFFER[170]	//( - , RPU) Нейтронный поток по камере КНК15-1 канал 5
#define idR0VN23RRP	 60	//( - , RPU) Нейтронный поток по камере КНК15-1 канал 5
#define A0EE02LRP	 BUFFER[175]	//( - , RPU) Исправность АКНП5 (от сшивки каналов) канал 5
#define idA0EE02LRP	 61	//( - , RPU) Исправность АКНП5 (от сшивки каналов) канал 5
#define R0IN03RRP	 BUFFER[177]	//( - , RPU) Частота КНК53М Гц (канал 5)
#define idR0IN03RRP	 62	//( - , RPU) Частота КНК53М Гц (канал 5)
#define B8VC01RDU	 BUFFER[182]	//( - , RPU) Координата АЗ2, мм
#define idB8VC01RDU	 63	//( - , RPU) Координата АЗ2, мм
#define R0VN03RRP	 BUFFER[187]	//( - , RPU) Измеренный нейтронный поток канал 5
#define idR0VN03RRP	 64	//( - , RPU) Измеренный нейтронный поток канал 5
#define R0IN02RRP	 BUFFER[192]	//( - , RPU) Частота КНК15-1 Гц (канал 5)
#define idR0IN02RRP	 65	//( - , RPU) Частота КНК15-1 Гц (канал 5)
#define R0IN01RRP	 BUFFER[197]	//( - , RPU) Частота СНМ-11 Гц (канал 5)
#define idR0IN01RRP	 66	//( - , RPU) Частота СНМ-11 Гц (канал 5)
#define R0VN02RRP	 BUFFER[202]	//( - , RPU) Уровень мощности канал 5
#define idR0VN02RRP	 67	//( - , RPU) Уровень мощности канал 5
#define B2VS21LRP	 BUFFER[207]	//(fds16:08 - K04FDSR, - ) Индикация - Приход на НУ РБ2-CC
#define idB2VS21LRP	 68	//(fds16:08 - K04FDSR, - ) Индикация - Приход на НУ РБ2-CC
#define A2VS21LRP	 BUFFER[209]	//(fds16:08 - K03FDSR, - ) Индикация - Приход на НУ РБ1-CC
#define idA2VS21LRP	 69	//(fds16:08 - K03FDSR, - ) Индикация - Приход на НУ РБ1-CC
#define B2IS21LRP	 BUFFER[211]	//(vds32:07 - K13VDSR, - ) Приход на НУ РБ2-CC
#define idB2IS21LRP	 70	//(vds32:07 - K13VDSR, - ) Приход на НУ РБ2-CC
#define A2IS21LRP	 BUFFER[213]	//(vds32:07 - K10VDSR, - ) Приход на НУ РБ1-CC
#define idA2IS21LRP	 71	//(vds32:07 - K10VDSR, - ) Приход на НУ РБ1-CC
#define B3IS21LRP	 BUFFER[215]	//(vds32:07 - K11VDSR, - ) Приход на НУ ИС2
#define idB3IS21LRP	 72	//(vds32:07 - K11VDSR, - ) Приход на НУ ИС2
#define A3IS21LRP	 BUFFER[217]	//(vds32:07 - K08VDSR, - ) Приход на НУ ИС1
#define idA3IS21LRP	 73	//(vds32:07 - K08VDSR, - ) Приход на НУ ИС1
#define R7VE70LRP	 BUFFER[219]	//( - , RPU) Сигнал тревоги по неисправности РПУ на диспетчера
#define idR7VE70LRP	 74	//( - , RPU) Сигнал тревоги по неисправности РПУ на диспетчера
#define B6IS11LRP	 BUFFER[221]	//(vds32:07 - K15VDSR, - ) Приход на ВУ БЗ2
#define idB6IS11LRP	 75	//(vds32:07 - K15VDSR, - ) Приход на ВУ БЗ2
#define A6IS11LRP	 BUFFER[223]	//(vds32:07 - K14VDSR, - ) Приход на ВУ БЗ1
#define idA6IS11LRP	 76	//(vds32:07 - K14VDSR, - ) Приход на ВУ БЗ1
#define R0VN13RRP	 BUFFER[225]	//( - , RPU) Нейтронный поток по камере  СНМ-11 канал 5
#define idR0VN13RRP	 77	//( - , RPU) Нейтронный поток по камере  СНМ-11 канал 5
#define R0VN71LRP	 BUFFER[230]	//(fds16:08 - K12FDSR, - ) АС по мощности канал 5
#define idR0VN71LRP	 78	//(fds16:08 - K12FDSR, - ) АС по мощности канал 5
#define A1VT71LRP	 BUFFER[232]	//(fds16:08 - K11FDSR, - ) АС по температуре
#define idA1VT71LRP	 79	//(fds16:08 - K11FDSR, - ) АС по температуре
#define R0IE04LRP	 BUFFER[234]	//(fds16:08 - K10FDSR, - ) Отключить питание ПР, ПУ канал 6,7
#define idR0IE04LRP	 80	//(fds16:08 - K10FDSR, - ) Отключить питание ПР, ПУ канал 6,7
#define R0IE03LRP	 BUFFER[236]	//(fds16:08 - K09FDSR, - ) Отключение питание детекторов канал  6,7
#define idR0IE03LRP	 81	//(fds16:08 - K09FDSR, - ) Отключение питание детекторов канал  6,7
#define R0IE15LRP	 BUFFER[238]	//(vds32:07 - K02VDSR, - ) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
#define idR0IE15LRP	 82	//(vds32:07 - K02VDSR, - ) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
#define R0IE14LRP	 BUFFER[240]	//(vds32:07 - K01VDSR, - ) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
#define idR0IE14LRP	 83	//(vds32:07 - K01VDSR, - ) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
#define R0IE13LRP	 BUFFER[242]	//(vds32:07 - K05VDSR, - ) Исправность ВИП 0,5 -5к (№22)
#define idR0IE13LRP	 84	//(vds32:07 - K05VDSR, - ) Исправность ВИП 0,5 -5к (№22)
#define R0IE12LRP	 BUFFER[244]	//(vds32:07 - K04VDSR, - ) Исправность ВИП 0,5 -5к (№21)
#define idR0IE12LRP	 85	//(vds32:07 - K04VDSR, - ) Исправность ВИП 0,5 -5к (№21)
#define A0EE01LRP	 BUFFER[246]	//( - , RPU) Исправность АКНП канал 5
#define idA0EE01LRP	 86	//( - , RPU) Исправность АКНП канал 5
#define R0IE11LRP	 BUFFER[248]	//(vds32:07 - K03VDSR, - ) Исправность ВИП 1,6 (№20) СНМ11 5 канала
#define idR0IE11LRP	 87	//(vds32:07 - K03VDSR, - ) Исправность ВИП 1,6 (№20) СНМ11 5 канала
#define B0VT71LRP	 BUFFER[250]	//( - , RPU) АС по температуре в АЗ2-3
#define idB0VT71LRP	 88	//( - , RPU) АС по температуре в АЗ2-3
#define B0VT61LRP	 BUFFER[252]	//( - , RPU) ПС по температуре в АЗ2-3
#define idB0VT61LRP	 89	//( - , RPU) ПС по температуре в АЗ2-3
#define B0CT01IRP	 BUFFER[254]	//( - , RPU) Температура АЗ2-3
#define idB0CT01IRP	 90	//( - , RPU) Температура АЗ2-3
#define fEM_R0UH02RSS	 BUFFER[259]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define idfEM_R0UH02RSS	 91	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define fEM_R0UH03RSS	 BUFFER[264]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define idfEM_R0UH03RSS	 92	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define fEM_R7UX00RSS	 BUFFER[269]	//(R7UX00RSS) X-координата АЗ1 (см)
#define idfEM_R7UX00RSS	 93	//(R7UX00RSS) X-координата АЗ1 (см)
#define fEM_R7UY00RSS	 BUFFER[274]	//(R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	 94	//(R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UX13RSS	 BUFFER[279]	//(R7UX13RSS) X-координата камеры R7IN51
#define idfEM_R7UX13RSS	 95	//(R7UX13RSS) X-координата камеры R7IN51
#define fEM_R7UX14RSS	 BUFFER[284]	//(R7UX14RSS) X-координата камеры R7IN52
#define idfEM_R7UX14RSS	 96	//(R7UX14RSS) X-координата камеры R7IN52
#define fEM_R7UX15RSS	 BUFFER[289]	//(R7UX15RSS) X-координата камеры R7IN53
#define idfEM_R7UX15RSS	 97	//(R7UX15RSS) X-координата камеры R7IN53
#define fEM_R7UY13RSS	 BUFFER[294]	//(R7UY13RSS) Y-координата камеры R7IN51
#define idfEM_R7UY13RSS	 98	//(R7UY13RSS) Y-координата камеры R7IN51
#define fEM_R7UY14RSS	 BUFFER[299]	//(R7UY14RSS) Y-координата камеры R7IN52
#define idfEM_R7UY14RSS	 99	//(R7UY14RSS) Y-координата камеры R7IN52
#define fEM_R7UY15RSS	 BUFFER[304]	//(R7UY15RSS) Y-координата камеры R7IN53
#define idfEM_R7UY15RSS	 100	//(R7UY15RSS) Y-координата камеры R7IN53
#define fEM_A0UX00RSS	 BUFFER[309]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 101	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX13RSS	 BUFFER[314]	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define idfEM_A0UX13RSS	 102	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define fEM_A0UX14RSS	 BUFFER[319]	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define idfEM_A0UX14RSS	 103	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define fEM_A0UX15RSS	 BUFFER[324]	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define idfEM_A0UX15RSS	 104	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define fEM_B0UX03RSS	 BUFFER[329]	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	 105	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	 BUFFER[334]	//(B0UX04RSS) Второй коэффициент калибровки камеры4
#define idfEM_B0UX04RSS	 106	//(B0UX04RSS) Второй коэффициент калибровки камеры4
#define fEM_B0UX05RSS	 BUFFER[339]	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	 107	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_R0UH05RSS	 BUFFER[344]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 108	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UR01RRP	 BUFFER[349]	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
#define idfEM_R0UR01RRP	 109	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
#define fEM_R0UT02RZZ	 BUFFER[354]	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	 110	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RZZ	 BUFFER[359]	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	 111	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_R0UT72RZZ	 BUFFER[364]	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	 112	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	 BUFFER[369]	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	 113	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	 BUFFER[374]	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	 114	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT61RZZ	 BUFFER[379]	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	 115	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_R0UL52RSS	 BUFFER[384]	//(R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	 116	//(R0UL52RSS) Уровень АС по мощности
#define fEM_Z7UE20RRP	 BUFFER[389]	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
#define idfEM_Z7UE20RRP	 117	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
#define fEM_R0UH21RSS	 BUFFER[394]	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	 118	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	 BUFFER[399]	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	 119	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	 BUFFER[404]	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	 120	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0IN11NRP	 BUFFER[409]	//(R0IN11NRP) Коэффициент A (РПУ к 1)
#define idfEM_R0IN11NRP	 121	//(R0IN11NRP) Коэффициент A (РПУ к 1)
#define fEM_R0IN12NRP	 BUFFER[414]	//(R0IN12NRP) Коэффициент B (РПУ к 1)
#define idfEM_R0IN12NRP	 122	//(R0IN12NRP) Коэффициент B (РПУ к 1)
#define fEM_R0IN21NRP	 BUFFER[419]	//(R0IN21NRP) Коэффициент A (РПУ к 2)
#define idfEM_R0IN21NRP	 123	//(R0IN21NRP) Коэффициент A (РПУ к 2)
#define fEM_R0IN22NRP	 BUFFER[424]	//(R0IN22NRP) Коэффициент B (РПУ к 2)
#define idfEM_R0IN22NRP	 124	//(R0IN22NRP) Коэффициент B (РПУ к 2)
#define fEM_R0IN31NRP	 BUFFER[429]	//(R0IN31NRP) Коэффициент A (РПУ к 3)
#define idfEM_R0IN31NRP	 125	//(R0IN31NRP) Коэффициент A (РПУ к 3)
#define fEM_R0IN32NRP	 BUFFER[434]	//(R0IN32NRP) Коэффициент B (РПУ к 3)
#define idfEM_R0IN32NRP	 126	//(R0IN32NRP) Коэффициент B (РПУ к 3)
#define fEM_R0IN61NRP	 BUFFER[439]	//(R0IN61NRP) Коэффициент A (РПУ к 6)
#define idfEM_R0IN61NRP	 127	//(R0IN61NRP) Коэффициент A (РПУ к 6)
#define fEM_R0IN62NRP	 BUFFER[444]	//(R0IN62NRP) Коэффициент B (РПУ к 6)
#define idfEM_R0IN62NRP	 128	//(R0IN62NRP) Коэффициент B (РПУ к 6)
#define fEM_R0IN71NRP	 BUFFER[449]	//(R0IN71NRP) Коэффициент A (РПУ к 7)
#define idfEM_R0IN71NRP	 129	//(R0IN71NRP) Коэффициент A (РПУ к 7)
#define fEM_R0IN72NRP	 BUFFER[454]	//(R0IN72NRP) Коэффициент B (РПУ к 7)
#define idfEM_R0IN72NRP	 130	//(R0IN72NRP) Коэффициент B (РПУ к 7)
#define bFirstEnterFlag	 BUFFER[459]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 131	//(bFirstEnterFlag) 
#define internal1_m18_Nk	 BUFFER[461]	//(internal1_m18_Nk) Nk - ведущая камера
#define idinternal1_m18_Nk	 132	//(internal1_m18_Nk) Nk - ведущая камера
#define internal1_m70_tx	 BUFFER[464]	//(internal1_m70_tx) tx - время накопленное сек
#define idinternal1_m70_tx	 133	//(internal1_m70_tx) tx - время накопленное сек
#define internal1_m70_y0	 BUFFER[469]	//(internal1_m70_y0) y0
#define idinternal1_m70_y0	 134	//(internal1_m70_y0) y0
#define internal1_m78_tx	 BUFFER[470]	//(internal1_m78_tx) tx - время накопленное сек
#define idinternal1_m78_tx	 135	//(internal1_m78_tx) tx - время накопленное сек
#define internal1_m78_y0	 BUFFER[475]	//(internal1_m78_y0) y0
#define idinternal1_m78_y0	 136	//(internal1_m78_y0) y0
#define internal1_m86_y0	 BUFFER[476]	//(internal1_m86_y0) y0
#define idinternal1_m86_y0	 137	//(internal1_m86_y0) y0
#define internal1_m84_y0	 BUFFER[481]	//(internal1_m84_y0) y0
#define idinternal1_m84_y0	 138	//(internal1_m84_y0) y0
#define internal1_m100_y1	 BUFFER[486]	//(internal1_m100_y1) y1 - внутренний параметр
#define idinternal1_m100_y1	 139	//(internal1_m100_y1) y1 - внутренний параметр
#define internal1_m115_y1	 BUFFER[488]	//(internal1_m115_y1) y1 - внутренний параметр
#define idinternal1_m115_y1	 140	//(internal1_m115_y1) y1 - внутренний параметр
#define internal1_m98_y1	 BUFFER[490]	//(internal1_m98_y1) y1 - внутренний параметр
#define idinternal1_m98_y1	 141	//(internal1_m98_y1) y1 - внутренний параметр
#define internal1_m111_y1	 BUFFER[492]	//(internal1_m111_y1) y1 - внутренний параметр
#define idinternal1_m111_y1	 142	//(internal1_m111_y1) y1 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &R0DE39LRP},	//(sbk:20 - S09SBK, DiagnRPU) диагностика шкафа РПУ МП24-2 место 4
	{ 2	,1	,1	, &R0DE38LRP},	//(sbk:20 - S08SBK, DiagnRPU) диагностика шкафа РПУ МП15-3 место 3
	{ 3	,1	,1	, &R0DE37LRP},	//(sbk:20 - S07SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 2
	{ 4	,1	,1	, &R0DE36LRP},	//(sbk:20 - S06SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 1
	{ 5	,1	,1	, &R0DE35LRP},	//(sbk:20 - S05SBK, DiagnRPU) диагностика шкафа РПУ температура больше 53
	{ 6	,1	,1	, &R0DE34LRP},	//(sbk:20 - S04SBK, DiagnRPU) диагностика шкафа РПУ температура меньше 43
	{ 7	,1	,1	, &R0DE33LRP},	//(sbk:20 - S03SBK, DiagnRPU) диагностика шкафа РПУ двери
	{ 8	,1	,1	, &R0DE32LRP},	//(sbk:20 - S02SBK, DiagnRPU) диагностика шкафа РПУ сеть 2
	{ 9	,1	,1	, &R0DE31LRP},	//(sbk:20 - S01SBK, DiagnRPU) диагностика шкафа РПУ сеть 1
	{ 10	,3	,1	, &R0DE07LRP},	//(vds32:07 - Diagn, DiagnRPU) диагностика модуля РПУ-ВДС место 7
	{ 11	,3	,1	, &R0DE08LRP},	//(fds16:08 - Diagn, DiagnRPU) диагностика модуля РПУ-ФДС место 8
	{ 12	,3	,1	, &R0DE06LRP},	//(vas84:06 - Diagn, DiagnRPU) диагностика модуля РПУ-ВАС место 6
	{ 13	,3	,1	, &R0DE03LRP},	//(vchs:03 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 3
	{ 14	,3	,1	, &R0DE02LRP},	//(vchs:02 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 2
	{ 15	,3	,1	, &R0DE01LRP},	//(vchs:01 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 1
	{ 16	,1	,1	, &R0EE02LDU},	//( - , RPU) Питание  АКНП  отключить
	{ 17	,1	,1	, &B7MZ31LRP},	//( - , RPU) Клапан ОБДУВ АЗ2 открыть(обесточить)
	{ 18	,1	,1	, &A7MZ31LRP},	//( - , RPU) Клапан ОБДУВ АЗ1 открыть(обесточить)
	{ 19	,1	,1	, &C1MZ31LRP},	//(vds32:07 - K07VDSR, - ) Кнопка ОБДУВ  на РПУ
	{ 20	,1	,1	, &C1MD31LRP},	//(vds32:07 - K06VDSR, - ) Кнопка ОБЩИЙ СБРОС  на РПУ
	{ 21	,1	,1	, &B3VS21LRP},	//(fds16:08 - K06FDSR, - ) Индикация - Приход на НУ ИС2
	{ 22	,1	,1	, &A3VS21LRP},	//(fds16:08 - K05FDSR, - ) Индикация - Приход на НУ ИС1
	{ 23	,8	,1	, &R0IN07VRP},	//(vchs:03 - K02VCHS, - ) Частота с ВЧС к 7
	{ 24	,8	,1	, &R0IN06VRP},	//(vchs:03 - K01VCHS, - ) Частота с ВЧС к 6
	{ 25	,8	,1	, &R0IN03VRP},	//(vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
	{ 26	,8	,1	, &R0IN02VRP},	//(vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
	{ 27	,8	,1	, &R0IN01VRP},	//(vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
	{ 28	,1	,1	, &B1VS21LRP},	//(fds16:08 - K02FDSR, - ) Индикация - Приход на НУ ББ2
	{ 29	,1	,1	, &B1IS21LRP},	//(vds32:07 - K12VDSR, - ) Приход на НУ ББ2
	{ 30	,1	,1	, &A1VS21LRP},	//(fds16:08 - K01FDSR, - ) Индикация - Приход на НУ ББ1
	{ 31	,1	,1	, &A1IS21LRP},	//(vds32:07 - K09VDSR, - ) Приход на НУ ББ1
	{ 32	,8	,1	, &R0IN07RIP},	//( - , MRPS) Частота СНМ-11 Гц (канал 7) от ПТИ
	{ 33	,8	,1	, &R0IN06RIP},	//( - , MRPS) Частота СНМ-11 Гц (канал 6) от ПТИ
	{ 34	,8	,1	, &R0IN03RIP},	//( - , MRPS) Частота КНК53М Гц (канал 5) от ПТИ
	{ 35	,8	,1	, &R0IN02RIP},	//( - , MRPS) Частота КНК15-1 Гц (канал 5) от ПТИ
	{ 36	,8	,1	, &R0IN01RIP},	//( - , MRPS) Частота СНМ-11 Гц (канал 5) от ПТИ
	{ 37	,1	,1	, &R0IS01FI0},	//( - , MRPS) Признак работы с имитатором
	{ 38	,1	,1	, &R0DEB3LRP},	//(sbk:20 - S12SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 8
	{ 39	,1	,1	, &R0DEB4LRP},	//(sbk:20 - S13SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 8
	{ 40	,1	,1	, &R0DEB2LRP},	//(sbk:20 - S11SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 7
	{ 41	,1	,1	, &R0DEB1LRP},	//(sbk:20 - S10SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 7
	{ 42	,3	,1	, &TTLrpu},	//( - , RPU) ttl
	{ 43	,1	,1	, &TestDiagnRPU},	//( - , RPU) Неисправность от диагностики
	{ 44	,1	,1	, &R0DE3DLRP},	//( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 8
	{ 45	,1	,1	, &R0DE3CLRP},	//( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 7
	{ 46	,1	,1	, &R0ET02LRP},	//( - , RPU) Признак наличия неисправности по температуре АЗ2-3
	{ 47	,3	,1	, &B0IT03IRP},	//(vas84:06 - K02VASR, - ) Температура АЗ2-3
	{ 48	,1	,1	, &R0ET01LRP},	//( - , RPU) Признак наличия неисправности по температуре  АЗ1-3
	{ 49	,1	,1	, &A0VT71LRP},	//( - , RPU) АС по температуре в АЗ1
	{ 50	,1	,1	, &A0VT61LRP},	//( - , RPU) ПС по температуре в АЗ1
	{ 51	,8	,1	, &A0CT01IRP},	//( - , RPU) Температура АЗ1-3
	{ 52	,3	,1	, &A0IT03IRP},	//(vas84:06 - K01VASR, - ) Температура АЗ1-3
	{ 53	,8	,1	, &R0IN07RRP},	//( - , RPU) Частота СНМ-11 Гц (канал 7)
	{ 54	,1	,1	, &R7VN71LRP},	//( - , RPU) Сигнал тревоги по уровню нейтронного потока на диспетчера
	{ 55	,8	,1	, &R0IN06RRP},	//( - , RPU) Частота СНМ-11 Гц (канал 6) от ПТИ
	{ 56	,1	,1	, &R0IE02LRP},	//(fds16:08 - K07FDSR, - ) Отключить питание ПР, ПУ канал 5
	{ 57	,1	,1	, &R0IE01LRP},	//(fds16:08 - K08FDSR, - ) Отключение питание детекторов канал 5
	{ 58	,3	,1	, &R0VN15RRP},	//( - , RPU) Номер ведущей камеры канал 5
	{ 59	,8	,1	, &R0VN33RRP},	//( - , RPU) Нейтронный поток по камере КНК53М канал 5
	{ 60	,8	,1	, &R0VN23RRP},	//( - , RPU) Нейтронный поток по камере КНК15-1 канал 5
	{ 61	,1	,1	, &A0EE02LRP},	//( - , RPU) Исправность АКНП5 (от сшивки каналов) канал 5
	{ 62	,8	,1	, &R0IN03RRP},	//( - , RPU) Частота КНК53М Гц (канал 5)
	{ 63	,8	,1	, &B8VC01RDU},	//( - , RPU) Координата АЗ2, мм
	{ 64	,8	,1	, &R0VN03RRP},	//( - , RPU) Измеренный нейтронный поток канал 5
	{ 65	,8	,1	, &R0IN02RRP},	//( - , RPU) Частота КНК15-1 Гц (канал 5)
	{ 66	,8	,1	, &R0IN01RRP},	//( - , RPU) Частота СНМ-11 Гц (канал 5)
	{ 67	,8	,1	, &R0VN02RRP},	//( - , RPU) Уровень мощности канал 5
	{ 68	,1	,1	, &B2VS21LRP},	//(fds16:08 - K04FDSR, - ) Индикация - Приход на НУ РБ2-CC
	{ 69	,1	,1	, &A2VS21LRP},	//(fds16:08 - K03FDSR, - ) Индикация - Приход на НУ РБ1-CC
	{ 70	,1	,1	, &B2IS21LRP},	//(vds32:07 - K13VDSR, - ) Приход на НУ РБ2-CC
	{ 71	,1	,1	, &A2IS21LRP},	//(vds32:07 - K10VDSR, - ) Приход на НУ РБ1-CC
	{ 72	,1	,1	, &B3IS21LRP},	//(vds32:07 - K11VDSR, - ) Приход на НУ ИС2
	{ 73	,1	,1	, &A3IS21LRP},	//(vds32:07 - K08VDSR, - ) Приход на НУ ИС1
	{ 74	,1	,1	, &R7VE70LRP},	//( - , RPU) Сигнал тревоги по неисправности РПУ на диспетчера
	{ 75	,1	,1	, &B6IS11LRP},	//(vds32:07 - K15VDSR, - ) Приход на ВУ БЗ2
	{ 76	,1	,1	, &A6IS11LRP},	//(vds32:07 - K14VDSR, - ) Приход на ВУ БЗ1
	{ 77	,8	,1	, &R0VN13RRP},	//( - , RPU) Нейтронный поток по камере  СНМ-11 канал 5
	{ 78	,1	,1	, &R0VN71LRP},	//(fds16:08 - K12FDSR, - ) АС по мощности канал 5
	{ 79	,1	,1	, &A1VT71LRP},	//(fds16:08 - K11FDSR, - ) АС по температуре
	{ 80	,1	,1	, &R0IE04LRP},	//(fds16:08 - K10FDSR, - ) Отключить питание ПР, ПУ канал 6,7
	{ 81	,1	,1	, &R0IE03LRP},	//(fds16:08 - K09FDSR, - ) Отключение питание детекторов канал  6,7
	{ 82	,1	,1	, &R0IE15LRP},	//(vds32:07 - K02VDSR, - ) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
	{ 83	,1	,1	, &R0IE14LRP},	//(vds32:07 - K01VDSR, - ) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
	{ 84	,1	,1	, &R0IE13LRP},	//(vds32:07 - K05VDSR, - ) Исправность ВИП 0,5 -5к (№22)
	{ 85	,1	,1	, &R0IE12LRP},	//(vds32:07 - K04VDSR, - ) Исправность ВИП 0,5 -5к (№21)
	{ 86	,1	,1	, &A0EE01LRP},	//( - , RPU) Исправность АКНП канал 5
	{ 87	,1	,1	, &R0IE11LRP},	//(vds32:07 - K03VDSR, - ) Исправность ВИП 1,6 (№20) СНМ11 5 канала
	{ 88	,1	,1	, &B0VT71LRP},	//( - , RPU) АС по температуре в АЗ2-3
	{ 89	,1	,1	, &B0VT61LRP},	//( - , RPU) ПС по температуре в АЗ2-3
	{ 90	,8	,1	, &B0CT01IRP},	//( - , RPU) Температура АЗ2-3
	{ 91	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{ 92	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{ 93	,8	,1	, &fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{ 94	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{ 95	,8	,1	, &fEM_R7UX13RSS},	//(R7UX13RSS) X-координата камеры R7IN51
	{ 96	,8	,1	, &fEM_R7UX14RSS},	//(R7UX14RSS) X-координата камеры R7IN52
	{ 97	,8	,1	, &fEM_R7UX15RSS},	//(R7UX15RSS) X-координата камеры R7IN53
	{ 98	,8	,1	, &fEM_R7UY13RSS},	//(R7UY13RSS) Y-координата камеры R7IN51
	{ 99	,8	,1	, &fEM_R7UY14RSS},	//(R7UY14RSS) Y-координата камеры R7IN52
	{ 100	,8	,1	, &fEM_R7UY15RSS},	//(R7UY15RSS) Y-координата камеры R7IN53
	{ 101	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 102	,8	,1	, &fEM_A0UX13RSS},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{ 103	,8	,1	, &fEM_A0UX14RSS},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{ 104	,8	,1	, &fEM_A0UX15RSS},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{ 105	,8	,1	, &fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{ 106	,8	,1	, &fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры4
	{ 107	,8	,1	, &fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{ 108	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 109	,8	,1	, &fEM_R0UR01RRP},	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
	{ 110	,8	,1	, &fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{ 111	,8	,1	, &fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{ 112	,8	,1	, &fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{ 113	,8	,1	, &fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{ 114	,8	,1	, &fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{ 115	,8	,1	, &fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{ 116	,8	,1	, &fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{ 117	,8	,1	, &fEM_Z7UE20RRP},	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
	{ 118	,8	,1	, &fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{ 119	,8	,1	, &fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{ 120	,8	,1	, &fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{ 121	,8	,1	, &fEM_R0IN11NRP},	//(R0IN11NRP) Коэффициент A (РПУ к 1)
	{ 122	,8	,1	, &fEM_R0IN12NRP},	//(R0IN12NRP) Коэффициент B (РПУ к 1)
	{ 123	,8	,1	, &fEM_R0IN21NRP},	//(R0IN21NRP) Коэффициент A (РПУ к 2)
	{ 124	,8	,1	, &fEM_R0IN22NRP},	//(R0IN22NRP) Коэффициент B (РПУ к 2)
	{ 125	,8	,1	, &fEM_R0IN31NRP},	//(R0IN31NRP) Коэффициент A (РПУ к 3)
	{ 126	,8	,1	, &fEM_R0IN32NRP},	//(R0IN32NRP) Коэффициент B (РПУ к 3)
	{ 127	,8	,1	, &fEM_R0IN61NRP},	//(R0IN61NRP) Коэффициент A (РПУ к 6)
	{ 128	,8	,1	, &fEM_R0IN62NRP},	//(R0IN62NRP) Коэффициент B (РПУ к 6)
	{ 129	,8	,1	, &fEM_R0IN71NRP},	//(R0IN71NRP) Коэффициент A (РПУ к 7)
	{ 130	,8	,1	, &fEM_R0IN72NRP},	//(R0IN72NRP) Коэффициент B (РПУ к 7)
	{ 131	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 132	,3	,1	, &internal1_m18_Nk},	//(internal1_m18_Nk) Nk - ведущая камера
	{ 133	,8	,1	, &internal1_m70_tx},	//(internal1_m70_tx) tx - время накопленное сек
	{ 134	,18	,1	, &internal1_m70_y0},	//(internal1_m70_y0) y0
	{ 135	,8	,1	, &internal1_m78_tx},	//(internal1_m78_tx) tx - время накопленное сек
	{ 136	,18	,1	, &internal1_m78_y0},	//(internal1_m78_y0) y0
	{ 137	,8	,1	, &internal1_m86_y0},	//(internal1_m86_y0) y0
	{ 138	,8	,1	, &internal1_m84_y0},	//(internal1_m84_y0) y0
	{ 139	,1	,1	, &internal1_m100_y1},	//(internal1_m100_y1) y1 - внутренний параметр
	{ 140	,1	,1	, &internal1_m115_y1},	//(internal1_m115_y1) y1 - внутренний параметр
	{ 141	,1	,1	, &internal1_m98_y1},	//(internal1_m98_y1) y1 - внутренний параметр
	{ 142	,1	,1	, &internal1_m111_y1},	//(internal1_m111_y1) y1 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="rpu.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{91,"fEM_R0UH02RSS\0"}, 
{92,"fEM_R0UH03RSS\0"}, 
{93,"fEM_R7UX00RSS\0"}, 
{94,"fEM_R7UY00RSS\0"}, 
{95,"fEM_R7UX13RSS\0"}, 
{96,"fEM_R7UX14RSS\0"}, 
{97,"fEM_R7UX15RSS\0"}, 
{98,"fEM_R7UY13RSS\0"}, 
{99,"fEM_R7UY14RSS\0"}, 
{100,"fEM_R7UY15RSS\0"}, 
{101,"fEM_A0UX00RSS\0"}, 
{102,"fEM_A0UX13RSS\0"}, 
{103,"fEM_A0UX14RSS\0"}, 
{104,"fEM_A0UX15RSS\0"}, 
{105,"fEM_B0UX03RSS\0"}, 
{106,"fEM_B0UX04RSS\0"}, 
{107,"fEM_B0UX05RSS\0"}, 
{108,"fEM_R0UH05RSS\0"}, 
{109,"fEM_R0UR01RRP\0"}, 
{110,"fEM_R0UT02RZZ\0"}, 
{111,"fEM_R0UT01RZZ\0"}, 
{112,"fEM_R0UT72RZZ\0"}, 
{113,"fEM_R0UT71RZZ\0"}, 
{114,"fEM_R0UT62RZZ\0"}, 
{115,"fEM_R0UT61RZZ\0"}, 
{116,"fEM_R0UL52RSS\0"}, 
{117,"fEM_Z7UE20RRP\0"}, 
{118,"fEM_R0UH21RSS\0"}, 
{119,"fEM_R0UH22RSS\0"}, 
{120,"fEM_R0UH23RSS\0"}, 
{121,"fEM_R0IN11NRP\0"}, 
{122,"fEM_R0IN12NRP\0"}, 
{123,"fEM_R0IN21NRP\0"}, 
{124,"fEM_R0IN22NRP\0"}, 
{125,"fEM_R0IN31NRP\0"}, 
{126,"fEM_R0IN32NRP\0"}, 
{127,"fEM_R0IN61NRP\0"}, 
{128,"fEM_R0IN62NRP\0"}, 
{129,"fEM_R0IN71NRP\0"}, 
{130,"fEM_R0IN72NRP\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_RPU[]={  // 
	{&R0EE02LDU,1,0},	//( - , RPU) Питание  АКНП  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_RPU[]={  // 
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
static ModbusRegister ir_RPU[]={  // 
	{&TTLrpu,3,0},	//( - , RPU) ttl
	{&R0VN13RRP,8,1},	//( - , RPU) Нейтронный поток по камере  СНМ-11 канал 5
	{&B0CT01IRP,8,3},	//( - , RPU) Температура АЗ2-3
	{&A0CT01IRP,8,5},	//( - , RPU) Температура АЗ1-3
	{&R0IN07RRP,8,7},	//( - , RPU) Частота СНМ-11 Гц (канал 7)
	{&R0IN06RRP,8,9},	//( - , RPU) Частота СНМ-11 Гц (канал 6) от ПТИ
	{&R0VN15RRP,3,11},	//( - , RPU) Номер ведущей камеры канал 5
	{&R0VN33RRP,8,12},	//( - , RPU) Нейтронный поток по камере КНК53М канал 5
	{&R0VN23RRP,8,14},	//( - , RPU) Нейтронный поток по камере КНК15-1 канал 5
	{&R0IN03RRP,8,16},	//( - , RPU) Частота КНК53М Гц (канал 5)
	{&R0VN03RRP,8,18},	//( - , RPU) Измеренный нейтронный поток канал 5
	{&R0IN02RRP,8,20},	//( - , RPU) Частота КНК15-1 Гц (канал 5)
	{&R0IN01RRP,8,22},	//( - , RPU) Частота СНМ-11 Гц (канал 5)
	{&R0VN02RRP,8,24},	//( - , RPU) Уровень мощности канал 5
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_RPU[]={  // 
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
static ModbusRegister coil_DiagnRPU[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnRPU[]={  // 
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
static ModbusRegister ir_DiagnRPU[]={  // 
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
static ModbusRegister hr_DiagnRPU[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MRPS[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MRPS[]={  // 
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MRPS[]={  // 
	{&R0IN01RIP,8,0},	//( - , SRP) Выход СНМ-11 Гц от ПТИ
	{&R0IN02RIP,8,2},	//( - , SRP) Выход КНК15- Гц от ПТИ
	{&R0IN03RIP,8,4},	//( - , SRP) Выход КНК53М Гц от ПТИ
	{&R0IN06RIP,8,6},	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
	{&R0IN07RIP,8,8},	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MRPS[]={  // 
	{NULL,0,0},
};
#pragma pop
static char MRPS_ip1[]={"192.168.10.60\0"};
static char MRPS_ip2[]={"192.168.10.60\0"};
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_RPU[0],&di_RPU[0],&ir_RPU[0],&hr_RPU[0],NULL,NULL,NULL,0},	 //общий slave RPU
	{0,5003,&coil_DiagnRPU[0],&di_DiagnRPU[0],&ir_DiagnRPU[0],&hr_DiagnRPU[0],NULL,NULL,NULL,0},	 //Диагностика РПУ
	{1,5010,&coil_MRPS[0],&di_MRPS[0],&ir_MRPS[0],&hr_MRPS[0],NULL,MRPS_ip1,MRPS_ip2,100},	 //Мастер RPU в SCM

	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS01[58];	//VCHS01
static vchs_inipar ini_VCHS01={0xc4,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,};
#pragma pack(push,1)
static table_drv table_VCHS01={0,0,&ini_VCHS01,buf_VCHS01,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS01[]={
	{&R0DE01LRP,3,10},
	{&R0IN01VRP,8,0},
	{&R0IN02VRP,8,5},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS02[58];	//VCHS02
static vchs_inipar ini_VCHS02={0xc4,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,};
#pragma pack(push,1)
static table_drv table_VCHS02={0,0,&ini_VCHS02,buf_VCHS02,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS02[]={
	{&R0DE02LRP,3,10},
	{&R0IN03VRP,8,0},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS03[58];	//VCHS03
static vchs_inipar ini_VCHS03={0xc4,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,};
#pragma pack(push,1)
static table_drv table_VCHS03={0,0,&ini_VCHS03,buf_VCHS03,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS03[]={
	{&R0DE03LRP,3,10},
	{&R0IN07VRP,8,5},
	{&R0IN06VRP,8,0},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vas84r.h>
static char buf_VAS84[30];	//VAS84
static vas84r_inipar ini_VAS84={0xc6,255,1,8,0xff,0,16,};
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
#include <fp8/drivers/vds32r.h>
static char buf_VDS32[132];	//VDS32
static vds32r_inipar ini_VDS32={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS32={0,0,&ini_VDS32,buf_VDS32,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32[]={
	{&R0IE15LRP,1,2},
	{&R0IE14LRP,1,0},
	{&R0IE13LRP,1,8},
	{&R0IE12LRP,1,6},
	{&R0IE11LRP,1,4},
	{&B1IS21LRP,1,22},
	{&A1IS21LRP,1,16},
	{&A6IS11LRP,1,26},
	{&B6IS11LRP,1,28},
	{&A3IS21LRP,1,14},
	{&B3IS21LRP,1,20},
	{&A2IS21LRP,1,18},
	{&B2IS21LRP,1,24},
	{&C1MD31LRP,1,10},
	{&C1MZ31LRP,1,12},
	{&R0DE07LRP,3,64},
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
	{&R0DE08LRP,3,38},
	{&R0IE01LRP,1,14},
	{&R0IE02LRP,1,12},
	{&B3VS21LRP,1,10},
	{&A3VS21LRP,1,8},
	{&B2VS21LRP,1,6},
	{&A2VS21LRP,1,4},
	{&R0VN71LRP,1,22},
	{&A1VT71LRP,1,20},
	{&B1VS21LRP,1,2},
	{&R0IE04LRP,1,18},
	{&R0IE03LRP,1,16},
	{&A1VS21LRP,1,0},
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
	{&R0DE35LRP,1,8},
	{&R0DE34LRP,1,6},
	{&R0DE33LRP,1,4},
	{&R0DE32LRP,1,2},
	{&R0DE31LRP,1,0},
	{&R0DE36LRP,1,10},
	{&R0DE37LRP,1,12},
	{&R0DE38LRP,1,14},
	{&R0DE39LRP,1,16},
	{&R0DEB2LRP,1,20},
	{&R0DEB1LRP,1,18},
	{&R0DEB4LRP,1,24},
	{&R0DEB3LRP,1,22},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc4,0x01,12,58,def_buf_VCHS01,&table_VCHS01}, //VCHS01
	{0xc4,0x02,12,58,def_buf_VCHS02,&table_VCHS02}, //VCHS02
	{0xc4,0x03,12,58,def_buf_VCHS03,&table_VCHS03}, //VCHS03
	{0xc6,0x06,7,30,def_buf_VAS84,&table_VAS84}, //VAS84
	{0xc2,0x07,15,132,def_buf_VDS32,&table_VDS32}, //VDS32
	{0x96,0x08,20,40,def_buf_FDS16,&table_FDS16}, //FDS16
	{0xcc,0x20,4,26,def_buf_SBKFP,&table_SBKFP}, //SBKFP
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
	setAsFloat(91,37037.04 );
	setAsFloat(92,975000.0);
	setAsFloat(93,1570.0);
	setAsFloat(94,506.5);
	setAsFloat(95,1570.0);
	setAsFloat(96,1269);
	setAsFloat(97,1281.2);
	setAsFloat(98,248.0);
	setAsFloat(99,572.4);
	setAsFloat(100,246.8);
	setAsFloat(101,11.0);
	setAsFloat(102,1.0);
	setAsFloat(103,1.0);
	setAsFloat(104,1.0);
	setAsFloat(105,0);
	setAsFloat(106,0);
	setAsFloat(107,0.0);
	setAsFloat(108,32000.0);
	setAsFloat(109,1000);
	setAsFloat(110,600);
	setAsFloat(111,0);
	setAsFloat(112,150);
	setAsFloat(113,200);
	setAsFloat(114,90);
	setAsFloat(115,100);
	setAsFloat(116,5100);
	setAsFloat(117,210);
	setAsFloat(118,4000);
	setAsFloat(119,100000);
	setAsFloat(120,1000000);
	setAsFloat(121,1);
	setAsFloat(122,0);
	setAsFloat(123,1);
	setAsFloat(124,0);
	setAsFloat(125,1);
	setAsFloat(126,0);
	setAsFloat(127,1);
	setAsFloat(128,0);
	setAsFloat(129,1);
	setAsFloat(130,0);
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

}

uspaint8 InternalBuf[37];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssbool lRM_0_ = {0,0}; /* A-Граница участка насыщения А */ 
ssbool lRM_1_ = {1,0}; /* B-Граница участка насыщения В */ 
sslong dRM_0_ = {0,0}; /* lx вход лонг */ 
sschar bRM_0_ = {0,0}; /* cx вход байтовый */ 
ssint iRM_0_ = {0,0}; /* ix вход целый */ 
ssint iRM_3276_ = {3276,0}; /* a */ 
ssint iRM_16383_ = {16383,0}; /* b */ 
sschar bRM_1_ = {1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 
ssint iRM_6_ = {6,0}; /* n - размерность массива значений */ 

uspaint8 SpaEEPROMBuf[200];

/* Определение переменных */
ssfloat var1;
ssfloat var2;
ssfloat var3;
ssfloat var4;
ssfloat var5;
ssfloat var6;
ssfloat var7;
ssfloat var8;
ssfloat var9;
ssfloat var10;
ssbool var11;
ssbool var12;
ssbool var13;
ssbool var14;
ssbool var15;
ssbool var16;
ssbool var17;
ssbool var18;
ssbool var19;
ssint var20;
ssfloat var21;
ssfloat var22;
ssbool var23;
ssfloat var24;
ssfloat var25;
ssfloat var26;
ssint var27;
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
sschar var38;
ssbool var39;
sschar var40;
ssbool var41;
ssbool var42;
ssbool var43;
ssbool var44;
ssbool var45;
ssfloat var46;
ssfloat var47;
sschar var48;
ssbool var49;
ssbool var50;
sschar var51;
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
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
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
_S_diagndev  S_diagndev_138_1 = {array_m138_x_1,&iRM_6_,&var19,&var20};
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
_S_scalzz  S_scalzz_86_1 = {&B0IT03IRP,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var46,&internal1_m86_y0};
_S_scalzz  S_scalzz_84_1 = {&A0IT03IRP,&iRM_3276_,&iRM_16383_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var47,&internal1_m84_y0};
_S_geterr  S_geterr_88_1 = {&var47,&dRM_0_,&iRM_0_,&bRM_0_,&var48,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_100_1 = {&var46,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var49,&internal1_m100_y1};
_S_drg  S_drg_115_1 = {&var46,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var50,&internal1_m115_y1};
_S_geterr  S_geterr_90_1 = {&var46,&dRM_0_,&iRM_0_,&bRM_0_,&var51,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_98_1 = {&var47,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var52,&internal1_m98_y1};
_S_drg  S_drg_111_1 = {&var47,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var53,&internal1_m111_y1};
_S_noto  S_noto_75_1 = {&var13,&var54};
_S_bol  S_bol_61_1 = {&var6,&fEM_R0UR01RRP,&var55};
_S_bol  S_bol_50_1 = {&var7,&fEM_R0UR01RRP,&var56};


void ZeroVar()
{
   var1.f=0.0;
   var2.f=0.0;
   var3.f=0.0;
   var4.f=0.0;
   var5.f=0.0;
   var6.f=0.0;
   var7.f=0.0;
   var8.f=0.0;
   var9.f=0.0;
   var10.f=0.0;
   var11.b=0;
   var12.b=0;
   var13.b=0;
   var14.b=0;
   var15.b=0;
   var16.b=0;
   var17.b=0;
   var18.b=0;
   var19.b=0;
   var20.i=0;
   var21.f=0.0;
   var22.f=0.0;
   var23.b=0;
   var24.f=0.0;
   var25.f=0.0;
   var26.f=0.0;
   var27.i=0;
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
   var38.c=0;
   var39.b=0;
   var40.c=0;
   var41.b=0;
   var42.b=0;
   var43.b=0;
   var44.b=0;
   var45.b=0;
   var46.f=0.0;
   var47.f=0.0;
   var48.c=0;
   var49.b=0;
   var50.b=0;
   var51.c=0;
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
   vainSLong.l=0L;
   vainSFloat.f=0.0;
   vainSInt.i=0;
   vainSBool.b=0;
   vainSChar.c=0;

}
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

void MainCycle(void)
{
     Scheme();

}
#endif
