#ifndef RPU_H
#define RPU_H
// Подсистема RPU:RPU
static char SimulOn=0;
static short CodeSub=8;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=8;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 405
static char BUFFER[405];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.31\0", 5432, "192.168.10.131\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0DE36LRP	 BUFFER[0]	//(sbk:20 - S06SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 1
#define idR0DE36LRP	 1	//(sbk:20 - S06SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 1
#define R0DE35LRP	 BUFFER[2]	//(sbk:20 - S05SBK, DiagnRPU) диагностика шкафа РПУ температура больше 53
#define idR0DE35LRP	 2	//(sbk:20 - S05SBK, DiagnRPU) диагностика шкафа РПУ температура больше 53
#define R0DE34LRP	 BUFFER[4]	//(sbk:20 - S04SBK, DiagnRPU) диагностика шкафа РПУ температура меньше 43
#define idR0DE34LRP	 3	//(sbk:20 - S04SBK, DiagnRPU) диагностика шкафа РПУ температура меньше 43
#define R0DE33LRP	 BUFFER[6]	//(sbk:20 - S03SBK, DiagnRPU) диагностика шкафа РПУ двери
#define idR0DE33LRP	 4	//(sbk:20 - S03SBK, DiagnRPU) диагностика шкафа РПУ двери
#define R0DE32LRP	 BUFFER[8]	//(sbk:20 - S02SBK, DiagnRPU) диагностика шкафа РПУ сеть 2
#define idR0DE32LRP	 5	//(sbk:20 - S02SBK, DiagnRPU) диагностика шкафа РПУ сеть 2
#define R0DE31LRP	 BUFFER[10]	//(sbk:20 - S01SBK, DiagnRPU) диагностика шкафа РПУ сеть 1
#define idR0DE31LRP	 6	//(sbk:20 - S01SBK, DiagnRPU) диагностика шкафа РПУ сеть 1
#define R0DE07LRP	 BUFFER[12]	//(vds32:07 - Diagn, DiagnRPU) диагностика модуля РПУ-ВДС место 7
#define idR0DE07LRP	 7	//(vds32:07 - Diagn, DiagnRPU) диагностика модуля РПУ-ВДС место 7
#define R0DE08LRP	 BUFFER[15]	//(fds16:08 - Diagn, DiagnRPU) диагностика модуля РПУ-ФДС место 8
#define idR0DE08LRP	 8	//(fds16:08 - Diagn, DiagnRPU) диагностика модуля РПУ-ФДС место 8
#define R0DE06LRP	 BUFFER[18]	//(vas84:06 - Diagn, DiagnRPU) диагностика модуля РПУ-ВАС место 6
#define idR0DE06LRP	 9	//(vas84:06 - Diagn, DiagnRPU) диагностика модуля РПУ-ВАС место 6
#define R0DE03LRP	 BUFFER[21]	//(vchs:03 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 3
#define idR0DE03LRP	 10	//(vchs:03 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 3
#define R0DE02LRP	 BUFFER[24]	//(vchs:02 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 2
#define idR0DE02LRP	 11	//(vchs:02 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 2
#define R0DE01LRP	 BUFFER[27]	//(vchs:01 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 1
#define idR0DE01LRP	 12	//(vchs:01 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 1
#define R0EE02LDU	 BUFFER[30]	//( - , RPU) Питание  АКНП  отключить
#define idR0EE02LDU	 13	//( - , RPU) Питание  АКНП  отключить
#define B7MZ31LRP	 BUFFER[32]	//( - , RPU) Клапан ОБДУВ АЗ2 открыть(обесточить)
#define idB7MZ31LRP	 14	//( - , RPU) Клапан ОБДУВ АЗ2 открыть(обесточить)
#define A7MZ31LRP	 BUFFER[34]	//( - , RPU) Клапан ОБДУВ АЗ1 открыть(обесточить)
#define idA7MZ31LRP	 15	//( - , RPU) Клапан ОБДУВ АЗ1 открыть(обесточить)
#define C1MZ31LRP	 BUFFER[36]	//(vds32:07 - K07VDSR, - ) Кнопка ОБДУВ  на РПУ
#define idC1MZ31LRP	 16	//(vds32:07 - K07VDSR, - ) Кнопка ОБДУВ  на РПУ
#define C1MD31LRP	 BUFFER[38]	//(vds32:07 - K06VDSR, - ) Кнопка ОБЩИЙ СБРОС  на РПУ
#define idC1MD31LRP	 17	//(vds32:07 - K06VDSR, - ) Кнопка ОБЩИЙ СБРОС  на РПУ
#define B3VS21LRP	 BUFFER[40]	//(fds16:08 - K06FDSR, - ) Индикация - Приход на НУ ИС2
#define idB3VS21LRP	 18	//(fds16:08 - K06FDSR, - ) Индикация - Приход на НУ ИС2
#define A3VS21LRP	 BUFFER[42]	//(fds16:08 - K05FDSR, - ) Индикация - Приход на НУ ИС1
#define idA3VS21LRP	 19	//(fds16:08 - K05FDSR, - ) Индикация - Приход на НУ ИС1
#define B2VS21LRP	 BUFFER[44]	//(fds16:08 - K04FDSR, - ) Индикация - Приход на НУ РБ2-CC
#define idB2VS21LRP	 20	//(fds16:08 - K04FDSR, - ) Индикация - Приход на НУ РБ2-CC
#define A2VS21LRP	 BUFFER[46]	//(fds16:08 - K03FDSR, - ) Индикация - Приход на НУ РБ1-CC
#define idA2VS21LRP	 21	//(fds16:08 - K03FDSR, - ) Индикация - Приход на НУ РБ1-CC
#define B1VS21LRP	 BUFFER[48]	//(fds16:08 - K02FDSR, - ) Индикация - Приход на НУ ББ2
#define idB1VS21LRP	 22	//(fds16:08 - K02FDSR, - ) Индикация - Приход на НУ ББ2
#define B1IS21LRP	 BUFFER[50]	//(vds32:07 - K12VDSR, - ) Приход на НУ ББ2
#define idB1IS21LRP	 23	//(vds32:07 - K12VDSR, - ) Приход на НУ ББ2
#define A1VS21LRP	 BUFFER[52]	//(fds16:08 - K01FDSR, - ) Индикация - Приход на НУ ББ1
#define idA1VS21LRP	 24	//(fds16:08 - K01FDSR, - ) Индикация - Приход на НУ ББ1
#define A1IS21LRP	 BUFFER[54]	//(vds32:07 - K09VDSR, - ) Приход на НУ ББ1
#define idA1IS21LRP	 25	//(vds32:07 - K09VDSR, - ) Приход на НУ ББ1
#define R0IN07RIP	 BUFFER[56]	//( - , MRPS) Частота СНМ-11 Гц (канал 7) от ПТИ
#define idR0IN07RIP	 26	//( - , MRPS) Частота СНМ-11 Гц (канал 7) от ПТИ
#define R0IN06RIP	 BUFFER[61]	//( - , MRPS) Частота СНМ-11 Гц (канал 6) от ПТИ
#define idR0IN06RIP	 27	//( - , MRPS) Частота СНМ-11 Гц (канал 6) от ПТИ
#define R0IN03RIP	 BUFFER[66]	//( - , MRPS) Частота КНК53М Гц (канал 5) от ПТИ
#define idR0IN03RIP	 28	//( - , MRPS) Частота КНК53М Гц (канал 5) от ПТИ
#define R0IN02RIP	 BUFFER[71]	//( - , MRPS) Частота КНК15-1 Гц (канал 5) от ПТИ
#define idR0IN02RIP	 29	//( - , MRPS) Частота КНК15-1 Гц (канал 5) от ПТИ
#define R0IN01RIP	 BUFFER[76]	//( - , MRPS) Частота СНМ-11 Гц (канал 5) от ПТИ
#define idR0IN01RIP	 30	//( - , MRPS) Частота СНМ-11 Гц (канал 5) от ПТИ
#define R0IS01FI0	 BUFFER[81]	//( - , MRPS) Признак работы с имитатором
#define idR0IS01FI0	 31	//( - , MRPS) Признак работы с имитатором
#define R0DEB3LRP	 BUFFER[84]	//(sbk:20 - S12SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 8
#define idR0DEB3LRP	 32	//(sbk:20 - S12SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 8
#define R0DEB4LRP	 BUFFER[86]	//(sbk:20 - S13SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 8
#define idR0DEB4LRP	 33	//(sbk:20 - S13SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 8
#define R0DEB2LRP	 BUFFER[88]	//(sbk:20 - S11SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 7
#define idR0DEB2LRP	 34	//(sbk:20 - S11SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 7
#define R0DEB1LRP	 BUFFER[90]	//(sbk:20 - S10SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 7
#define idR0DEB1LRP	 35	//(sbk:20 - S10SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 7
#define TTLrpu	 BUFFER[92]	//( - , RPU) ttl
#define idTTLrpu	 36	//( - , RPU) ttl
#define TestDiagnRPU	 BUFFER[95]	//( - , RPU) Неисправность от диагностики
#define idTestDiagnRPU	 37	//( - , RPU) Неисправность от диагностики
#define R0DE3DLRP	 BUFFER[97]	//( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 8
#define idR0DE3DLRP	 38	//( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 8
#define R0DE3CLRP	 BUFFER[99]	//( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 7
#define idR0DE3CLRP	 39	//( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 7
#define R0DE39LRP	 BUFFER[101]	//(sbk:20 - S09SBK, DiagnRPU) диагностика шкафа РПУ МП24-2 место 4
#define idR0DE39LRP	 40	//(sbk:20 - S09SBK, DiagnRPU) диагностика шкафа РПУ МП24-2 место 4
#define R0DE38LRP	 BUFFER[103]	//(sbk:20 - S08SBK, DiagnRPU) диагностика шкафа РПУ МП15-3 место 3
#define idR0DE38LRP	 41	//(sbk:20 - S08SBK, DiagnRPU) диагностика шкафа РПУ МП15-3 место 3
#define R0DE37LRP	 BUFFER[105]	//(sbk:20 - S07SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 2
#define idR0DE37LRP	 42	//(sbk:20 - S07SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 2
#define B0IT03IRP	 BUFFER[107]	//(vas84:06 - K02VASR, - ) Температура АЗ2-3
#define idB0IT03IRP	 43	//(vas84:06 - K02VASR, - ) Температура АЗ2-3
#define R0ET01LRP	 BUFFER[110]	//( - , RPU) Признак наличия неисправности по температуре  АЗ1-3
#define idR0ET01LRP	 44	//( - , RPU) Признак наличия неисправности по температуре  АЗ1-3
#define A0VT71LRP	 BUFFER[112]	//( - , RPU) АС по температуре в АЗ1
#define idA0VT71LRP	 45	//( - , RPU) АС по температуре в АЗ1
#define A0VT61LRP	 BUFFER[114]	//( - , RPU) ПС по температуре в АЗ1
#define idA0VT61LRP	 46	//( - , RPU) ПС по температуре в АЗ1
#define A0CT01IRP	 BUFFER[116]	//( - , RPU) Температура АЗ1-3
#define idA0CT01IRP	 47	//( - , RPU) Температура АЗ1-3
#define A0IT03IRP	 BUFFER[121]	//(vas84:06 - K01VASR, - ) Температура АЗ1-3
#define idA0IT03IRP	 48	//(vas84:06 - K01VASR, - ) Температура АЗ1-3
#define R0IN07RRP	 BUFFER[124]	//(vchs:03 - K02VCHS, RPU) Частота СНМ-11 Гц (канал 7)
#define idR0IN07RRP	 49	//(vchs:03 - K02VCHS, RPU) Частота СНМ-11 Гц (канал 7)
#define R7VN71LRP	 BUFFER[129]	//( - , RPU) Сигнал тревоги по уровню нейтронного потока на диспетчера
#define idR7VN71LRP	 50	//( - , RPU) Сигнал тревоги по уровню нейтронного потока на диспетчера
#define R0IN06RRP	 BUFFER[131]	//(vchs:03 - K01VCHS, RPU) Частота СНМ-11 Гц (канал 6) от ПТИ
#define idR0IN06RRP	 51	//(vchs:03 - K01VCHS, RPU) Частота СНМ-11 Гц (канал 6) от ПТИ
#define R0IE02LRP	 BUFFER[136]	//(fds16:08 - K07FDSR, - ) Отключить питание ПР, ПУ канал 5
#define idR0IE02LRP	 52	//(fds16:08 - K07FDSR, - ) Отключить питание ПР, ПУ канал 5
#define R0IE01LRP	 BUFFER[138]	//(fds16:08 - K08FDSR, - ) Отключение питание детекторов канал 5
#define idR0IE01LRP	 53	//(fds16:08 - K08FDSR, - ) Отключение питание детекторов канал 5
#define R0VN15RRP	 BUFFER[140]	//( - , RPU) Номер ведущей камеры канал 5
#define idR0VN15RRP	 54	//( - , RPU) Номер ведущей камеры канал 5
#define R0VN33RRP	 BUFFER[143]	//( - , RPU) Нейтронный поток по камере КНК53М канал 5
#define idR0VN33RRP	 55	//( - , RPU) Нейтронный поток по камере КНК53М канал 5
#define R0VN23RRP	 BUFFER[148]	//( - , RPU) Нейтронный поток по камере КНК15-1 канал 5
#define idR0VN23RRP	 56	//( - , RPU) Нейтронный поток по камере КНК15-1 канал 5
#define A0EE02LRP	 BUFFER[153]	//( - , RPU) Исправность АКНП5 (от сшивки каналов) канал 5
#define idA0EE02LRP	 57	//( - , RPU) Исправность АКНП5 (от сшивки каналов) канал 5
#define R0IN03RRP	 BUFFER[155]	//(vchs:02 - K01VCHS, RPU) Частота КНК53М Гц (канал 5)
#define idR0IN03RRP	 58	//(vchs:02 - K01VCHS, RPU) Частота КНК53М Гц (канал 5)
#define B8VC01RDU	 BUFFER[160]	//( - , RPU) Координата АЗ2, мм
#define idB8VC01RDU	 59	//( - , RPU) Координата АЗ2, мм
#define R0VN03RRP	 BUFFER[165]	//( - , RPU) Измеренный нейтронный поток канал 5
#define idR0VN03RRP	 60	//( - , RPU) Измеренный нейтронный поток канал 5
#define R0IN02RRP	 BUFFER[170]	//(vchs:01 - K02VCHS, RPU) Частота КНК15-1 Гц (канал 5)
#define idR0IN02RRP	 61	//(vchs:01 - K02VCHS, RPU) Частота КНК15-1 Гц (канал 5)
#define R0IN01RRP	 BUFFER[175]	//(vchs:01 - K01VCHS, RPU) Частота СНМ-11 Гц (канал 5)
#define idR0IN01RRP	 62	//(vchs:01 - K01VCHS, RPU) Частота СНМ-11 Гц (канал 5)
#define R0VN02RRP	 BUFFER[180]	//( - , RPU) Уровень мощности канал 5
#define idR0VN02RRP	 63	//( - , RPU) Уровень мощности канал 5
#define B2IS21LRP	 BUFFER[185]	//(vds32:07 - K13VDSR, - ) Приход на НУ РБ2-CC
#define idB2IS21LRP	 64	//(vds32:07 - K13VDSR, - ) Приход на НУ РБ2-CC
#define A2IS21LRP	 BUFFER[187]	//(vds32:07 - K10VDSR, - ) Приход на НУ РБ1-CC
#define idA2IS21LRP	 65	//(vds32:07 - K10VDSR, - ) Приход на НУ РБ1-CC
#define B3IS21LRP	 BUFFER[189]	//(vds32:07 - K11VDSR, - ) Приход на НУ ИС2
#define idB3IS21LRP	 66	//(vds32:07 - K11VDSR, - ) Приход на НУ ИС2
#define A3IS21LRP	 BUFFER[191]	//(vds32:07 - K08VDSR, - ) Приход на НУ ИС1
#define idA3IS21LRP	 67	//(vds32:07 - K08VDSR, - ) Приход на НУ ИС1
#define R7VE70LRP	 BUFFER[193]	//( - , RPU) Сигнал тревоги по неисправности РПУ на диспетчера
#define idR7VE70LRP	 68	//( - , RPU) Сигнал тревоги по неисправности РПУ на диспетчера
#define B6IS11LRP	 BUFFER[195]	//(vds32:07 - K15VDSR, - ) Приход на ВУ БЗ2
#define idB6IS11LRP	 69	//(vds32:07 - K15VDSR, - ) Приход на ВУ БЗ2
#define A6IS11LRP	 BUFFER[197]	//(vds32:07 - K14VDSR, - ) Приход на ВУ БЗ1
#define idA6IS11LRP	 70	//(vds32:07 - K14VDSR, - ) Приход на ВУ БЗ1
#define R0VN13RRP	 BUFFER[199]	//( - , RPU) Нейтронный поток по камере  СНМ-11 канал 5
#define idR0VN13RRP	 71	//( - , RPU) Нейтронный поток по камере  СНМ-11 канал 5
#define R0VN71LRP	 BUFFER[204]	//(fds16:08 - K12FDSR, - ) АС по мощности канал 5
#define idR0VN71LRP	 72	//(fds16:08 - K12FDSR, - ) АС по мощности канал 5
#define A1VT71LRP	 BUFFER[206]	//(fds16:08 - K11FDSR, - ) АС по температуре
#define idA1VT71LRP	 73	//(fds16:08 - K11FDSR, - ) АС по температуре
#define R0IE04LRP	 BUFFER[208]	//(fds16:08 - K10FDSR, - ) Отключить питание ПР, ПУ канал 6,7
#define idR0IE04LRP	 74	//(fds16:08 - K10FDSR, - ) Отключить питание ПР, ПУ канал 6,7
#define R0IE03LRP	 BUFFER[210]	//(fds16:08 - K09FDSR, - ) Отключение питание детекторов канал  6,7
#define idR0IE03LRP	 75	//(fds16:08 - K09FDSR, - ) Отключение питание детекторов канал  6,7
#define R0IE15LRP	 BUFFER[212]	//(vds32:07 - K02VDSR, - ) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
#define idR0IE15LRP	 76	//(vds32:07 - K02VDSR, - ) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
#define R0IE14LRP	 BUFFER[214]	//(vds32:07 - K01VDSR, - ) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
#define idR0IE14LRP	 77	//(vds32:07 - K01VDSR, - ) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
#define R0IE13LRP	 BUFFER[216]	//(vds32:07 - K05VDSR, - ) Исправность ВИП 0,5 -5к (№22)
#define idR0IE13LRP	 78	//(vds32:07 - K05VDSR, - ) Исправность ВИП 0,5 -5к (№22)
#define R0IE12LRP	 BUFFER[218]	//(vds32:07 - K04VDSR, - ) Исправность ВИП 0,5 -5к (№21)
#define idR0IE12LRP	 79	//(vds32:07 - K04VDSR, - ) Исправность ВИП 0,5 -5к (№21)
#define A0EE01LRP	 BUFFER[220]	//( - , RPU) Исправность АКНП канал 5
#define idA0EE01LRP	 80	//( - , RPU) Исправность АКНП канал 5
#define R0IE11LRP	 BUFFER[222]	//(vds32:07 - K03VDSR, - ) Исправность ВИП 1,6 (№20) СНМ11 5 канала
#define idR0IE11LRP	 81	//(vds32:07 - K03VDSR, - ) Исправность ВИП 1,6 (№20) СНМ11 5 канала
#define B0VT71LRP	 BUFFER[224]	//( - , RPU) АС по температуре в АЗ2-3
#define idB0VT71LRP	 82	//( - , RPU) АС по температуре в АЗ2-3
#define B0VT61LRP	 BUFFER[226]	//( - , RPU) ПС по температуре в АЗ2-3
#define idB0VT61LRP	 83	//( - , RPU) ПС по температуре в АЗ2-3
#define B0CT01IRP	 BUFFER[228]	//( - , RPU) Температура АЗ2-3
#define idB0CT01IRP	 84	//( - , RPU) Температура АЗ2-3
#define R0ET02LRP	 BUFFER[233]	//( - , RPU) Признак наличия неисправности по температуре АЗ2-3
#define idR0ET02LRP	 85	//( - , RPU) Признак наличия неисправности по температуре АЗ2-3
#define fEM_R0UH02RSS	 BUFFER[235]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define idfEM_R0UH02RSS	 86	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define fEM_R0UH03RSS	 BUFFER[240]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define idfEM_R0UH03RSS	 87	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define fEM_R7UX00RSS	 BUFFER[245]	//(R7UX00RSS) X-координата АЗ1 (см)
#define idfEM_R7UX00RSS	 88	//(R7UX00RSS) X-координата АЗ1 (см)
#define fEM_R7UY00RSS	 BUFFER[250]	//(R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	 89	//(R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UX13RSS	 BUFFER[255]	//(R7UX13RSS) X-координата камеры R7IN51
#define idfEM_R7UX13RSS	 90	//(R7UX13RSS) X-координата камеры R7IN51
#define fEM_R7UX14RSS	 BUFFER[260]	//(R7UX14RSS) X-координата камеры R7IN52
#define idfEM_R7UX14RSS	 91	//(R7UX14RSS) X-координата камеры R7IN52
#define fEM_R7UX15RSS	 BUFFER[265]	//(R7UX15RSS) X-координата камеры R7IN53
#define idfEM_R7UX15RSS	 92	//(R7UX15RSS) X-координата камеры R7IN53
#define fEM_R7UY13RSS	 BUFFER[270]	//(R7UY13RSS) Y-координата камеры R7IN51
#define idfEM_R7UY13RSS	 93	//(R7UY13RSS) Y-координата камеры R7IN51
#define fEM_R7UY14RSS	 BUFFER[275]	//(R7UY14RSS) Y-координата камеры R7IN52
#define idfEM_R7UY14RSS	 94	//(R7UY14RSS) Y-координата камеры R7IN52
#define fEM_R7UY15RSS	 BUFFER[280]	//(R7UY15RSS) Y-координата камеры R7IN53
#define idfEM_R7UY15RSS	 95	//(R7UY15RSS) Y-координата камеры R7IN53
#define fEM_A0UX00RSS	 BUFFER[285]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 96	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX13RSS	 BUFFER[290]	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define idfEM_A0UX13RSS	 97	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define fEM_A0UX14RSS	 BUFFER[295]	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define idfEM_A0UX14RSS	 98	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define fEM_A0UX15RSS	 BUFFER[300]	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define idfEM_A0UX15RSS	 99	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define fEM_B0UX03RSS	 BUFFER[305]	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	 100	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	 BUFFER[310]	//(B0UX04RSS) Второй коэффициент калибровки камеры4
#define idfEM_B0UX04RSS	 101	//(B0UX04RSS) Второй коэффициент калибровки камеры4
#define fEM_B0UX05RSS	 BUFFER[315]	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	 102	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_R0UH05RSS	 BUFFER[320]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 103	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UR01RRP	 BUFFER[325]	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
#define idfEM_R0UR01RRP	 104	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
#define fEM_R0UT02RZZ	 BUFFER[330]	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	 105	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RZZ	 BUFFER[335]	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	 106	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_R0UT72RZZ	 BUFFER[340]	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	 107	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	 BUFFER[345]	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	 108	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	 BUFFER[350]	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	 109	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT61RZZ	 BUFFER[355]	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	 110	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_R0UL52RSS	 BUFFER[360]	//(R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	 111	//(R0UL52RSS) Уровень АС по мощности
#define fEM_Z7UE20RRP	 BUFFER[365]	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
#define idfEM_Z7UE20RRP	 112	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
#define bFirstEnterFlag	 BUFFER[370]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 113	//(bFirstEnterFlag) 
#define internal1_m22_Nk	 BUFFER[372]	//(internal1_m22_Nk) Nk - ведущая камера
#define idinternal1_m22_Nk	 114	//(internal1_m22_Nk) Nk - ведущая камера
#define internal1_m73_tx	 BUFFER[375]	//(internal1_m73_tx) tx - время накопленное сек
#define idinternal1_m73_tx	 115	//(internal1_m73_tx) tx - время накопленное сек
#define internal1_m73_y0	 BUFFER[380]	//(internal1_m73_y0) y0
#define idinternal1_m73_y0	 116	//(internal1_m73_y0) y0
#define internal1_m81_tx	 BUFFER[381]	//(internal1_m81_tx) tx - время накопленное сек
#define idinternal1_m81_tx	 117	//(internal1_m81_tx) tx - время накопленное сек
#define internal1_m81_y0	 BUFFER[386]	//(internal1_m81_y0) y0
#define idinternal1_m81_y0	 118	//(internal1_m81_y0) y0
#define internal1_m89_y0	 BUFFER[387]	//(internal1_m89_y0) y0
#define idinternal1_m89_y0	 119	//(internal1_m89_y0) y0
#define internal1_m87_y0	 BUFFER[392]	//(internal1_m87_y0) y0
#define idinternal1_m87_y0	 120	//(internal1_m87_y0) y0
#define internal1_m103_y1	 BUFFER[397]	//(internal1_m103_y1) y1 - внутренний параметр
#define idinternal1_m103_y1	 121	//(internal1_m103_y1) y1 - внутренний параметр
#define internal1_m118_y1	 BUFFER[399]	//(internal1_m118_y1) y1 - внутренний параметр
#define idinternal1_m118_y1	 122	//(internal1_m118_y1) y1 - внутренний параметр
#define internal1_m101_y1	 BUFFER[401]	//(internal1_m101_y1) y1 - внутренний параметр
#define idinternal1_m101_y1	 123	//(internal1_m101_y1) y1 - внутренний параметр
#define internal1_m115_y1	 BUFFER[403]	//(internal1_m115_y1) y1 - внутренний параметр
#define idinternal1_m115_y1	 124	//(internal1_m115_y1) y1 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &R0DE36LRP},	//(sbk:20 - S06SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 1
	{ 2	,1	,1	, &R0DE35LRP},	//(sbk:20 - S05SBK, DiagnRPU) диагностика шкафа РПУ температура больше 53
	{ 3	,1	,1	, &R0DE34LRP},	//(sbk:20 - S04SBK, DiagnRPU) диагностика шкафа РПУ температура меньше 43
	{ 4	,1	,1	, &R0DE33LRP},	//(sbk:20 - S03SBK, DiagnRPU) диагностика шкафа РПУ двери
	{ 5	,1	,1	, &R0DE32LRP},	//(sbk:20 - S02SBK, DiagnRPU) диагностика шкафа РПУ сеть 2
	{ 6	,1	,1	, &R0DE31LRP},	//(sbk:20 - S01SBK, DiagnRPU) диагностика шкафа РПУ сеть 1
	{ 7	,3	,1	, &R0DE07LRP},	//(vds32:07 - Diagn, DiagnRPU) диагностика модуля РПУ-ВДС место 7
	{ 8	,3	,1	, &R0DE08LRP},	//(fds16:08 - Diagn, DiagnRPU) диагностика модуля РПУ-ФДС место 8
	{ 9	,3	,1	, &R0DE06LRP},	//(vas84:06 - Diagn, DiagnRPU) диагностика модуля РПУ-ВАС место 6
	{ 10	,3	,1	, &R0DE03LRP},	//(vchs:03 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 3
	{ 11	,3	,1	, &R0DE02LRP},	//(vchs:02 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 2
	{ 12	,3	,1	, &R0DE01LRP},	//(vchs:01 - Diagn, DiagnRPU) диагностика модуля РПУ-ВЧС место 1
	{ 13	,1	,1	, &R0EE02LDU},	//( - , RPU) Питание  АКНП  отключить
	{ 14	,1	,1	, &B7MZ31LRP},	//( - , RPU) Клапан ОБДУВ АЗ2 открыть(обесточить)
	{ 15	,1	,1	, &A7MZ31LRP},	//( - , RPU) Клапан ОБДУВ АЗ1 открыть(обесточить)
	{ 16	,1	,1	, &C1MZ31LRP},	//(vds32:07 - K07VDSR, - ) Кнопка ОБДУВ  на РПУ
	{ 17	,1	,1	, &C1MD31LRP},	//(vds32:07 - K06VDSR, - ) Кнопка ОБЩИЙ СБРОС  на РПУ
	{ 18	,1	,1	, &B3VS21LRP},	//(fds16:08 - K06FDSR, - ) Индикация - Приход на НУ ИС2
	{ 19	,1	,1	, &A3VS21LRP},	//(fds16:08 - K05FDSR, - ) Индикация - Приход на НУ ИС1
	{ 20	,1	,1	, &B2VS21LRP},	//(fds16:08 - K04FDSR, - ) Индикация - Приход на НУ РБ2-CC
	{ 21	,1	,1	, &A2VS21LRP},	//(fds16:08 - K03FDSR, - ) Индикация - Приход на НУ РБ1-CC
	{ 22	,1	,1	, &B1VS21LRP},	//(fds16:08 - K02FDSR, - ) Индикация - Приход на НУ ББ2
	{ 23	,1	,1	, &B1IS21LRP},	//(vds32:07 - K12VDSR, - ) Приход на НУ ББ2
	{ 24	,1	,1	, &A1VS21LRP},	//(fds16:08 - K01FDSR, - ) Индикация - Приход на НУ ББ1
	{ 25	,1	,1	, &A1IS21LRP},	//(vds32:07 - K09VDSR, - ) Приход на НУ ББ1
	{ 26	,8	,1	, &R0IN07RIP},	//( - , MRPS) Частота СНМ-11 Гц (канал 7) от ПТИ
	{ 27	,8	,1	, &R0IN06RIP},	//( - , MRPS) Частота СНМ-11 Гц (канал 6) от ПТИ
	{ 28	,8	,1	, &R0IN03RIP},	//( - , MRPS) Частота КНК53М Гц (канал 5) от ПТИ
	{ 29	,8	,1	, &R0IN02RIP},	//( - , MRPS) Частота КНК15-1 Гц (канал 5) от ПТИ
	{ 30	,8	,1	, &R0IN01RIP},	//( - , MRPS) Частота СНМ-11 Гц (канал 5) от ПТИ
	{ 31	,3	,1	, &R0IS01FI0},	//( - , MRPS) Признак работы с имитатором
	{ 32	,1	,1	, &R0DEB3LRP},	//(sbk:20 - S12SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 8
	{ 33	,1	,1	, &R0DEB4LRP},	//(sbk:20 - S13SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 8
	{ 34	,1	,1	, &R0DEB2LRP},	//(sbk:20 - S11SBK, DiagnRPU) диагностика шкафа РПУ БП24Д место 7
	{ 35	,1	,1	, &R0DEB1LRP},	//(sbk:20 - S10SBK, DiagnRPU) диагностика шкафа РПУ БП5 место 7
	{ 36	,3	,1	, &TTLrpu},	//( - , RPU) ttl
	{ 37	,1	,1	, &TestDiagnRPU},	//( - , RPU) Неисправность от диагностики
	{ 38	,1	,1	, &R0DE3DLRP},	//( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 8
	{ 39	,1	,1	, &R0DE3CLRP},	//( - , DiagnRPU) диагностика шкафа РПУ БП5/24Д место 7
	{ 40	,1	,1	, &R0DE39LRP},	//(sbk:20 - S09SBK, DiagnRPU) диагностика шкафа РПУ МП24-2 место 4
	{ 41	,1	,1	, &R0DE38LRP},	//(sbk:20 - S08SBK, DiagnRPU) диагностика шкафа РПУ МП15-3 место 3
	{ 42	,1	,1	, &R0DE37LRP},	//(sbk:20 - S07SBK, DiagnRPU) диагностика шкафа РПУ МП15-3.1 место 2
	{ 43	,3	,1	, &B0IT03IRP},	//(vas84:06 - K02VASR, - ) Температура АЗ2-3
	{ 44	,1	,1	, &R0ET01LRP},	//( - , RPU) Признак наличия неисправности по температуре  АЗ1-3
	{ 45	,1	,1	, &A0VT71LRP},	//( - , RPU) АС по температуре в АЗ1
	{ 46	,1	,1	, &A0VT61LRP},	//( - , RPU) ПС по температуре в АЗ1
	{ 47	,8	,1	, &A0CT01IRP},	//( - , RPU) Температура АЗ1-3
	{ 48	,3	,1	, &A0IT03IRP},	//(vas84:06 - K01VASR, - ) Температура АЗ1-3
	{ 49	,8	,1	, &R0IN07RRP},	//(vchs:03 - K02VCHS, RPU) Частота СНМ-11 Гц (канал 7)
	{ 50	,1	,1	, &R7VN71LRP},	//( - , RPU) Сигнал тревоги по уровню нейтронного потока на диспетчера
	{ 51	,8	,1	, &R0IN06RRP},	//(vchs:03 - K01VCHS, RPU) Частота СНМ-11 Гц (канал 6) от ПТИ
	{ 52	,1	,1	, &R0IE02LRP},	//(fds16:08 - K07FDSR, - ) Отключить питание ПР, ПУ канал 5
	{ 53	,1	,1	, &R0IE01LRP},	//(fds16:08 - K08FDSR, - ) Отключение питание детекторов канал 5
	{ 54	,3	,1	, &R0VN15RRP},	//( - , RPU) Номер ведущей камеры канал 5
	{ 55	,8	,1	, &R0VN33RRP},	//( - , RPU) Нейтронный поток по камере КНК53М канал 5
	{ 56	,8	,1	, &R0VN23RRP},	//( - , RPU) Нейтронный поток по камере КНК15-1 канал 5
	{ 57	,1	,1	, &A0EE02LRP},	//( - , RPU) Исправность АКНП5 (от сшивки каналов) канал 5
	{ 58	,8	,1	, &R0IN03RRP},	//(vchs:02 - K01VCHS, RPU) Частота КНК53М Гц (канал 5)
	{ 59	,8	,1	, &B8VC01RDU},	//( - , RPU) Координата АЗ2, мм
	{ 60	,8	,1	, &R0VN03RRP},	//( - , RPU) Измеренный нейтронный поток канал 5
	{ 61	,8	,1	, &R0IN02RRP},	//(vchs:01 - K02VCHS, RPU) Частота КНК15-1 Гц (канал 5)
	{ 62	,8	,1	, &R0IN01RRP},	//(vchs:01 - K01VCHS, RPU) Частота СНМ-11 Гц (канал 5)
	{ 63	,8	,1	, &R0VN02RRP},	//( - , RPU) Уровень мощности канал 5
	{ 64	,1	,1	, &B2IS21LRP},	//(vds32:07 - K13VDSR, - ) Приход на НУ РБ2-CC
	{ 65	,1	,1	, &A2IS21LRP},	//(vds32:07 - K10VDSR, - ) Приход на НУ РБ1-CC
	{ 66	,1	,1	, &B3IS21LRP},	//(vds32:07 - K11VDSR, - ) Приход на НУ ИС2
	{ 67	,1	,1	, &A3IS21LRP},	//(vds32:07 - K08VDSR, - ) Приход на НУ ИС1
	{ 68	,1	,1	, &R7VE70LRP},	//( - , RPU) Сигнал тревоги по неисправности РПУ на диспетчера
	{ 69	,1	,1	, &B6IS11LRP},	//(vds32:07 - K15VDSR, - ) Приход на ВУ БЗ2
	{ 70	,1	,1	, &A6IS11LRP},	//(vds32:07 - K14VDSR, - ) Приход на ВУ БЗ1
	{ 71	,8	,1	, &R0VN13RRP},	//( - , RPU) Нейтронный поток по камере  СНМ-11 канал 5
	{ 72	,1	,1	, &R0VN71LRP},	//(fds16:08 - K12FDSR, - ) АС по мощности канал 5
	{ 73	,1	,1	, &A1VT71LRP},	//(fds16:08 - K11FDSR, - ) АС по температуре
	{ 74	,1	,1	, &R0IE04LRP},	//(fds16:08 - K10FDSR, - ) Отключить питание ПР, ПУ канал 6,7
	{ 75	,1	,1	, &R0IE03LRP},	//(fds16:08 - K09FDSR, - ) Отключение питание детекторов канал  6,7
	{ 76	,1	,1	, &R0IE15LRP},	//(vds32:07 - K02VDSR, - ) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
	{ 77	,1	,1	, &R0IE14LRP},	//(vds32:07 - K01VDSR, - ) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
	{ 78	,1	,1	, &R0IE13LRP},	//(vds32:07 - K05VDSR, - ) Исправность ВИП 0,5 -5к (№22)
	{ 79	,1	,1	, &R0IE12LRP},	//(vds32:07 - K04VDSR, - ) Исправность ВИП 0,5 -5к (№21)
	{ 80	,1	,1	, &A0EE01LRP},	//( - , RPU) Исправность АКНП канал 5
	{ 81	,1	,1	, &R0IE11LRP},	//(vds32:07 - K03VDSR, - ) Исправность ВИП 1,6 (№20) СНМ11 5 канала
	{ 82	,1	,1	, &B0VT71LRP},	//( - , RPU) АС по температуре в АЗ2-3
	{ 83	,1	,1	, &B0VT61LRP},	//( - , RPU) ПС по температуре в АЗ2-3
	{ 84	,8	,1	, &B0CT01IRP},	//( - , RPU) Температура АЗ2-3
	{ 85	,1	,1	, &R0ET02LRP},	//( - , RPU) Признак наличия неисправности по температуре АЗ2-3
	{ 86	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{ 87	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{ 88	,8	,1	, &fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{ 89	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{ 90	,8	,1	, &fEM_R7UX13RSS},	//(R7UX13RSS) X-координата камеры R7IN51
	{ 91	,8	,1	, &fEM_R7UX14RSS},	//(R7UX14RSS) X-координата камеры R7IN52
	{ 92	,8	,1	, &fEM_R7UX15RSS},	//(R7UX15RSS) X-координата камеры R7IN53
	{ 93	,8	,1	, &fEM_R7UY13RSS},	//(R7UY13RSS) Y-координата камеры R7IN51
	{ 94	,8	,1	, &fEM_R7UY14RSS},	//(R7UY14RSS) Y-координата камеры R7IN52
	{ 95	,8	,1	, &fEM_R7UY15RSS},	//(R7UY15RSS) Y-координата камеры R7IN53
	{ 96	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 97	,8	,1	, &fEM_A0UX13RSS},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{ 98	,8	,1	, &fEM_A0UX14RSS},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{ 99	,8	,1	, &fEM_A0UX15RSS},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{ 100	,8	,1	, &fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{ 101	,8	,1	, &fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры4
	{ 102	,8	,1	, &fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{ 103	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 104	,8	,1	, &fEM_R0UR01RRP},	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
	{ 105	,8	,1	, &fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{ 106	,8	,1	, &fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{ 107	,8	,1	, &fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{ 108	,8	,1	, &fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{ 109	,8	,1	, &fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{ 110	,8	,1	, &fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{ 111	,8	,1	, &fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{ 112	,8	,1	, &fEM_Z7UE20RRP},	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
	{ 113	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 114	,3	,1	, &internal1_m22_Nk},	//(internal1_m22_Nk) Nk - ведущая камера
	{ 115	,8	,1	, &internal1_m73_tx},	//(internal1_m73_tx) tx - время накопленное сек
	{ 116	,18	,1	, &internal1_m73_y0},	//(internal1_m73_y0) y0
	{ 117	,8	,1	, &internal1_m81_tx},	//(internal1_m81_tx) tx - время накопленное сек
	{ 118	,18	,1	, &internal1_m81_y0},	//(internal1_m81_y0) y0
	{ 119	,8	,1	, &internal1_m89_y0},	//(internal1_m89_y0) y0
	{ 120	,8	,1	, &internal1_m87_y0},	//(internal1_m87_y0) y0
	{ 121	,1	,1	, &internal1_m103_y1},	//(internal1_m103_y1) y1 - внутренний параметр
	{ 122	,1	,1	, &internal1_m118_y1},	//(internal1_m118_y1) y1 - внутренний параметр
	{ 123	,1	,1	, &internal1_m101_y1},	//(internal1_m101_y1) y1 - внутренний параметр
	{ 124	,1	,1	, &internal1_m115_y1},	//(internal1_m115_y1) y1 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="rpu.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{86,"fEM_R0UH02RSS\0"}, 
{87,"fEM_R0UH03RSS\0"}, 
{88,"fEM_R7UX00RSS\0"}, 
{89,"fEM_R7UY00RSS\0"}, 
{90,"fEM_R7UX13RSS\0"}, 
{91,"fEM_R7UX14RSS\0"}, 
{92,"fEM_R7UX15RSS\0"}, 
{93,"fEM_R7UY13RSS\0"}, 
{94,"fEM_R7UY14RSS\0"}, 
{95,"fEM_R7UY15RSS\0"}, 
{96,"fEM_A0UX00RSS\0"}, 
{97,"fEM_A0UX13RSS\0"}, 
{98,"fEM_A0UX14RSS\0"}, 
{99,"fEM_A0UX15RSS\0"}, 
{100,"fEM_B0UX03RSS\0"}, 
{101,"fEM_B0UX04RSS\0"}, 
{102,"fEM_B0UX05RSS\0"}, 
{103,"fEM_R0UH05RSS\0"}, 
{104,"fEM_R0UR01RRP\0"}, 
{105,"fEM_R0UT02RZZ\0"}, 
{106,"fEM_R0UT01RZZ\0"}, 
{107,"fEM_R0UT72RZZ\0"}, 
{108,"fEM_R0UT71RZZ\0"}, 
{109,"fEM_R0UT62RZZ\0"}, 
{110,"fEM_R0UT61RZZ\0"}, 
{111,"fEM_R0UL52RSS\0"}, 
{112,"fEM_Z7UE20RRP\0"}, 
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
	{&R0IN07RRP,8,7},	//( - K02VCHS, RPU) Частота СНМ-11 Гц (канал 7)
	{&R0IN06RRP,8,9},	//( - K01VCHS, RPU) Частота СНМ-11 Гц (канал 6) от ПТИ
	{&R0VN15RRP,3,11},	//( - , RPU) Номер ведущей камеры канал 5
	{&R0VN33RRP,8,12},	//( - , RPU) Нейтронный поток по камере КНК53М канал 5
	{&R0VN23RRP,8,14},	//( - , RPU) Нейтронный поток по камере КНК15-1 канал 5
	{&R0IN03RRP,8,16},	//( - K01VCHS, RPU) Частота КНК53М Гц (канал 5)
	{&B8VC01RDU,8,18},	//( - , RPU) Координата АЗ2, мм
	{&R0VN03RRP,8,20},	//( - , RPU) Измеренный нейтронный поток канал 5
	{&R0IN02RRP,8,22},	//( - K02VCHS, RPU) Частота КНК15-1 Гц (канал 5)
	{&R0IN01RRP,8,24},	//( - K01VCHS, RPU) Частота СНМ-11 Гц (канал 5)
	{&R0VN02RRP,8,26},	//( - , RPU) Уровень мощности канал 5
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_RPU[]={  // 
	{&fEM_R0UH02RSS,8,0},	//( - , RPU) Коэфф. преобразования частота->нейтр/с КНК15-1
	{&fEM_R0UH03RSS,8,2},	//( - , RPU) Коэфф. преобразования частота->нейтр/с КНК53М
	{&fEM_R7UX00RSS,8,4},	//( - , RPU) X-координата АЗ1 (см)
	{&fEM_R7UY00RSS,8,6},	//( - , RPU) Y-координата АЗ1 (см)
	{&fEM_R7UX13RSS,8,8},	//( - , RPU) X-координата камеры R7IN51
	{&fEM_R7UX14RSS,8,10},	//( - , RPU) X-координата камеры R7IN52
	{&fEM_R7UX15RSS,8,12},	//( - , RPU) X-координата камеры R7IN53
	{&fEM_R7UY13RSS,8,14},	//( - , RPU) Y-координата камеры R7IN51
	{&fEM_R7UY14RSS,8,16},	//( - , RPU) Y-координата камеры R7IN52
	{&fEM_R7UY15RSS,8,18},	//( - , RPU) Y-координата камеры R7IN53
	{&fEM_A0UX00RSS,8,20},	//( - , RPU) Эффективный радиус АЗ
	{&fEM_A0UX13RSS,8,22},	//( - , RPU) Первый коэффициент калибровки камеры 13
	{&fEM_A0UX14RSS,8,24},	//( - , RPU) Первый коэффициент калибровки камеры 14
	{&fEM_A0UX15RSS,8,26},	//( - , RPU) Первый коэффициент калибровки камеры 15
	{&fEM_B0UX03RSS,8,28},	//( - , RPU) Второй коэффициент калибровки камеры 3
	{&fEM_B0UX04RSS,8,30},	//( - , RPU) Второй коэффициент калибровки камеры4
	{&fEM_B0UX05RSS,8,32},	//( - , RPU) Второй коэффициент калибровки камеры 5
	{&fEM_R0UH05RSS,8,34},	//( - , RPU) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_R0UR01RRP,8,36},	//( - , RPU) Уставка СНМ11 в БЗ - АС по частоте
	{&fEM_R0UT02RZZ,8,38},	//( - , RPU) Верхний предел шкалы датчика температуры
	{&fEM_R0UT01RZZ,8,40},	//( - , RPU) Нижний предел шкалы датчика температуры
	{&fEM_R0UT72RZZ,8,42},	//( - , RPU) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{&fEM_R0UT71RZZ,8,44},	//( - , RPU) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{&fEM_R0UT62RZZ,8,46},	//( - , RPU) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{&fEM_R0UT61RZZ,8,48},	//( - , RPU) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{&fEM_R0UL52RSS,8,50},	//( - , RPU) Уровень АС по мощности
	{&fEM_Z7UE20RRP,8,52},	//( - , RPU) Время задержки сигнала на включение источников питания после снятия команды на отключение
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
	{&R0IS01FI0,3,10},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
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
	{&R0IN02RRP,8,5},
	{&R0IN01RRP,8,0},
	{&R0DE01LRP,3,10},
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
	{&R0IN03RRP,8,0},
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
	{&R0IN07RRP,8,5},
	{&R0IN06RRP,8,0},
	{&R0DE03LRP,3,10},
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
	{&R0DE06LRP,3,26},
	{&B0IT03IRP,3,3},
	{&A0IT03IRP,3,0},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS32[66];	//VDS32
static vds32r_inipar ini_VDS32={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS32={0,0,&ini_VDS32,buf_VDS32,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32[]={
	{&R0IE11LRP,1,4},
	{&A1IS21LRP,1,16},
	{&R0IE12LRP,1,6},
	{&R0IE13LRP,1,8},
	{&R0IE14LRP,1,0},
	{&R0IE15LRP,1,2},
	{&R0DE07LRP,3,64},
	{&B1IS21LRP,1,22},
	{&A6IS11LRP,1,26},
	{&B6IS11LRP,1,28},
	{&A3IS21LRP,1,14},
	{&B3IS21LRP,1,20},
	{&A2IS21LRP,1,18},
	{&B2IS21LRP,1,24},
	{&C1MZ31LRP,1,12},
	{&C1MD31LRP,1,10},
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
	{&B3VS21LRP,1,10},
	{&R0VN71LRP,1,22},
	{&R0IE01LRP,1,14},
	{&A1VT71LRP,1,20},
	{&R0DE08LRP,3,38},
	{&R0IE04LRP,1,18},
	{&R0IE03LRP,1,16},
	{&R0IE02LRP,1,12},
	{&A3VS21LRP,1,8},
	{&A1VS21LRP,1,0},
	{&B2VS21LRP,1,6},
	{&B1VS21LRP,1,2},
	{&A2VS21LRP,1,4},
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
	{&R0DE36LRP,1,10},
	{&R0DE37LRP,1,12},
	{&R0DE35LRP,1,8},
	{&R0DE34LRP,1,6},
	{&R0DE38LRP,1,14},
	{&R0DE33LRP,1,4},
	{&R0DE39LRP,1,16},
	{&R0DEB1LRP,1,18},
	{&R0DEB2LRP,1,20},
	{&R0DEB4LRP,1,24},
	{&R0DEB3LRP,1,22},
	{&R0DE32LRP,1,2},
	{&R0DE31LRP,1,0},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc4,0x01,12,58,def_buf_VCHS01,&table_VCHS01}, //VCHS01
	{0xc4,0x02,12,58,def_buf_VCHS02,&table_VCHS02}, //VCHS02
	{0xc4,0x03,12,58,def_buf_VCHS03,&table_VCHS03}, //VCHS03
	{0xc6,0x06,7,30,def_buf_VAS84,&table_VAS84}, //VAS84
	{0xc2,0x07,15,66,def_buf_VDS32,&table_VDS32}, //VDS32
	{0x96,0x08,20,40,def_buf_FDS16,&table_FDS16}, //FDS16
	{0xcc,0x20,4,26,def_buf_SBKFP,&table_SBKFP}, //SBKFP
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
	setAsFloat(86,3703.704 );
	setAsFloat(87,62500.0);
	setAsFloat(88,1567.36);
	setAsFloat(89,506.5);
	setAsFloat(90,1570.0);
	setAsFloat(91,1269);
	setAsFloat(92,1281.2);
	setAsFloat(93,248.0);
	setAsFloat(94,572.4);
	setAsFloat(95,246.8);
	setAsFloat(96,11.0);
	setAsFloat(97,1.0);
	setAsFloat(98,1.0);
	setAsFloat(99,1.0);
	setAsFloat(100,0);
	setAsFloat(101,0);
	setAsFloat(102,0.0);
	setAsFloat(103,32000.0);
	setAsFloat(104,1000);
	setAsFloat(105,600);
	setAsFloat(106,0);
	setAsFloat(107,150);
	setAsFloat(108,200);
	setAsFloat(109,90);
	setAsFloat(110,100);
	setAsFloat(111,5100);
	setAsFloat(112,210);
}
// checked_ 0  |  if(aknp||rpu) AddCodeAknp()
// checked_ 1  | if(ExistFile(Scheme.h)) AddCode_H(  RPU\Scheme\Scheme.h
// RPU\Scheme\Scheme.h
#endif
