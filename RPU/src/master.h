#ifndef RPU_H
#define RPU_H
// Подсистема RPU:RPU
static char SimulOn=0;
static short CodeSub=8;
static char SimulIP[]="192.168.1.17\0";
static int SimulPort=5555;
static int StepCycle=5;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 370
static char BUFFER[370];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.31\0", 5432, "192.168.10.131\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0EE02LDU	 BUFFER[0]	//(R0EE02LDU) Питание  АКНП  отключить
#define idR0EE02LDU	 1	//(R0EE02LDU) Питание  АКНП  отключить
#define B7MZ31LRP	 BUFFER[2]	//(B7MZ31LRP) Клапан ОБДУВ АЗ2 открыть(обесточить)
#define idB7MZ31LRP	 2	//(B7MZ31LRP) Клапан ОБДУВ АЗ2 открыть(обесточить)
#define A7MZ31LRP	 BUFFER[4]	//(A7MZ31LRP) Клапан ОБДУВ АЗ1 открыть(обесточить)
#define idA7MZ31LRP	 3	//(A7MZ31LRP) Клапан ОБДУВ АЗ1 открыть(обесточить)
#define C1MZ31LRP	 BUFFER[6]	//(C1MZ31LRP) Кнопка ОБДУВ  на РПУ
#define idC1MZ31LRP	 4	//(C1MZ31LRP) Кнопка ОБДУВ  на РПУ
#define C1MD31LRP	 BUFFER[8]	//(C1MD31LRP) Кнопка ОБЩИЙ СБРОС  на РПУ
#define idC1MD31LRP	 5	//(C1MD31LRP) Кнопка ОБЩИЙ СБРОС  на РПУ
#define B3VS21LRP	 BUFFER[10]	//(B3VS21LRP) Индикация - Приход на НУ ИС2
#define idB3VS21LRP	 6	//(B3VS21LRP) Индикация - Приход на НУ ИС2
#define A3VS21LRP	 BUFFER[12]	//(A3VS21LRP) Индикация - Приход на НУ ИС1
#define idA3VS21LRP	 7	//(A3VS21LRP) Индикация - Приход на НУ ИС1
#define B2VS21LRP	 BUFFER[14]	//(B2VS21LRP) Индикация - Приход на НУ РБ2-CC
#define idB2VS21LRP	 8	//(B2VS21LRP) Индикация - Приход на НУ РБ2-CC
#define A2VS21LRP	 BUFFER[16]	//(A2VS21LRP) Индикация - Приход на НУ РБ1-CC
#define idA2VS21LRP	 9	//(A2VS21LRP) Индикация - Приход на НУ РБ1-CC
#define B1VS21LRP	 BUFFER[18]	//(B1VS21LRP) Индикация - Приход на НУ ББ2
#define idB1VS21LRP	 10	//(B1VS21LRP) Индикация - Приход на НУ ББ2
#define A1VS21LRP	 BUFFER[20]	//(A1VS21LRP) Индикация - Приход на НУ ББ1
#define idA1VS21LRP	 11	//(A1VS21LRP) Индикация - Приход на НУ ББ1
#define B2IS21LRP	 BUFFER[22]	//(B2IS21LRP) Приход на НУ РБ2-CC
#define idB2IS21LRP	 12	//(B2IS21LRP) Приход на НУ РБ2-CC
#define A2IS21LRP	 BUFFER[24]	//(A2IS21LRP) Приход на НУ РБ1-CC
#define idA2IS21LRP	 13	//(A2IS21LRP) Приход на НУ РБ1-CC
#define B1IS21LRP	 BUFFER[26]	//(B1IS21LRP) Приход на НУ ББ2
#define idB1IS21LRP	 14	//(B1IS21LRP) Приход на НУ ББ2
#define A1IS21LRP	 BUFFER[28]	//(A1IS21LRP) Приход на НУ ББ1
#define idA1IS21LRP	 15	//(A1IS21LRP) Приход на НУ ББ1
#define B3IS21LRP	 BUFFER[30]	//(B3IS21LRP) Приход на НУ ИС2
#define idB3IS21LRP	 16	//(B3IS21LRP) Приход на НУ ИС2
#define A3IS21LRP	 BUFFER[32]	//(A3IS21LRP) Приход на НУ ИС1
#define idA3IS21LRP	 17	//(A3IS21LRP) Приход на НУ ИС1
#define R7VE70LRP	 BUFFER[34]	//(R7VE70LRP) Сигнал тревоги по неисправности РПУ на диспетчера
#define idR7VE70LRP	 18	//(R7VE70LRP) Сигнал тревоги по неисправности РПУ на диспетчера
#define B6IS11LRP	 BUFFER[36]	//(B6IS11LRP) Приход на ВУ БЗ2
#define idB6IS11LRP	 19	//(B6IS11LRP) Приход на ВУ БЗ2
#define R0DE3DLRP	 BUFFER[38]	//(R0DE3DLRP) диагностика шкафа РПУ БП5/24Д место 8
#define idR0DE3DLRP	 20	//(R0DE3DLRP) диагностика шкафа РПУ БП5/24Д место 8
#define R0DE3CLRP	 BUFFER[40]	//(R0DE3CLRP) диагностика шкафа РПУ БП5/24Д место 7
#define idR0DE3CLRP	 21	//(R0DE3CLRP) диагностика шкафа РПУ БП5/24Д место 7
#define R0DE3BLRP	 BUFFER[42]	//(R0DE3BLRP) диагностика шкафа РПУ БП5/24Д место 6
#define idR0DE3BLRP	 22	//(R0DE3BLRP) диагностика шкафа РПУ БП5/24Д место 6
#define R0DE3ALRP	 BUFFER[44]	//(R0DE3ALRP) диагностика шкафа РПУ БП5/24Д место 5
#define idR0DE3ALRP	 23	//(R0DE3ALRP) диагностика шкафа РПУ БП5/24Д место 5
#define R0DE39LRP	 BUFFER[46]	//(R0DE39LRP) диагностика шкафа РПУ МП24-2 место 4
#define idR0DE39LRP	 24	//(R0DE39LRP) диагностика шкафа РПУ МП24-2 место 4
#define R0DE38LRP	 BUFFER[48]	//(R0DE38LRP) диагностика шкафа РПУ МП15-3 место 2
#define idR0DE38LRP	 25	//(R0DE38LRP) диагностика шкафа РПУ МП15-3 место 2
#define R0DE37LRP	 BUFFER[50]	//(R0DE37LRP) диагностика шкафа РПУ МП15-3.1 место 2
#define idR0DE37LRP	 26	//(R0DE37LRP) диагностика шкафа РПУ МП15-3.1 место 2
#define R0DE36LRP	 BUFFER[52]	//(R0DE36LRP) диагностика шкафа РПУ МП15-3.1 место 1
#define idR0DE36LRP	 27	//(R0DE36LRP) диагностика шкафа РПУ МП15-3.1 место 1
#define R0DE35LRP	 BUFFER[54]	//(R0DE35LRP) диагностика шкафа РПУ температура больше 53
#define idR0DE35LRP	 28	//(R0DE35LRP) диагностика шкафа РПУ температура больше 53
#define R0DE34LRP	 BUFFER[56]	//(R0DE34LRP) диагностика шкафа РПУ температура меньше 43
#define idR0DE34LRP	 29	//(R0DE34LRP) диагностика шкафа РПУ температура меньше 43
#define R0DE33LRP	 BUFFER[58]	//(R0DE33LRP) диагностика шкафа РПУ двери
#define idR0DE33LRP	 30	//(R0DE33LRP) диагностика шкафа РПУ двери
#define R0DE32LRP	 BUFFER[60]	//(R0DE32LRP) диагностика шкафа РПУ сеть 2
#define idR0DE32LRP	 31	//(R0DE32LRP) диагностика шкафа РПУ сеть 2
#define R0DE31LRP	 BUFFER[62]	//(R0DE31LRP) диагностика шкафа РПУ сеть 1
#define idR0DE31LRP	 32	//(R0DE31LRP) диагностика шкафа РПУ сеть 1
#define R0DE07LRP	 BUFFER[64]	//(R0DE07LRP) диагностика модуля РПУ-ВДС место 7
#define idR0DE07LRP	 33	//(R0DE07LRP) диагностика модуля РПУ-ВДС место 7
#define R0DE08LRP	 BUFFER[67]	//(R0DE08LRP) диагностика модуля РПУ-ФДС место 8
#define idR0DE08LRP	 34	//(R0DE08LRP) диагностика модуля РПУ-ФДС место 8
#define R0DE06LRP	 BUFFER[70]	//(R0DE06LRP) диагностика модуля РПУ-ВАС место 6
#define idR0DE06LRP	 35	//(R0DE06LRP) диагностика модуля РПУ-ВАС место 6
#define R0DE03LRP	 BUFFER[73]	//(R0DE03LRP) диагностика модуля РПУ-ВЧС место 3
#define idR0DE03LRP	 36	//(R0DE03LRP) диагностика модуля РПУ-ВЧС место 3
#define R0DE02LRP	 BUFFER[76]	//(R0DE02LRP) диагностика модуля РПУ-ВЧС место 2
#define idR0DE02LRP	 37	//(R0DE02LRP) диагностика модуля РПУ-ВЧС место 2
#define R0DE01LRP	 BUFFER[79]	//(R0DE01LRP) диагностика модуля РПУ-ВЧС место 1
#define idR0DE01LRP	 38	//(R0DE01LRP) диагностика модуля РПУ-ВЧС место 1
#define A0VT71LRP	 BUFFER[82]	//(A0VT71LRP) АС по температуре в АЗ1
#define idA0VT71LRP	 39	//(A0VT71LRP) АС по температуре в АЗ1
#define A0VT61LRP	 BUFFER[84]	//(A0VT61LRP) ПС по температуре в АЗ1
#define idA0VT61LRP	 40	//(A0VT61LRP) ПС по температуре в АЗ1
#define A0CT01IRP	 BUFFER[86]	//(A0CT01IRP) Температура АЗ1-3
#define idA0CT01IRP	 41	//(A0CT01IRP) Температура АЗ1-3
#define A0IT03IRP	 BUFFER[91]	//(A0IT03IRP) Температура АЗ1-3
#define idA0IT03IRP	 42	//(A0IT03IRP) Температура АЗ1-3
#define R0IN07RRP	 BUFFER[94]	//(R0IN07RRP) Частота СНМ-11 Гц (канал 7)
#define idR0IN07RRP	 43	//(R0IN07RRP) Частота СНМ-11 Гц (канал 7)
#define R7VN71LRP	 BUFFER[99]	//(R7VN71LRP) Сигнал тревоги по уровню нейтронного потока на диспетчера
#define idR7VN71LRP	 44	//(R7VN71LRP) Сигнал тревоги по уровню нейтронного потока на диспетчера
#define R0IN06RRP	 BUFFER[101]	//(R0IN06RRP) Частота СНМ-11 Гц (канал 6)
#define idR0IN06RRP	 45	//(R0IN06RRP) Частота СНМ-11 Гц (канал 6)
#define R0IE02LRP	 BUFFER[106]	//(R0IE02LRP) Отключить питание ПР, ПУ канал 5
#define idR0IE02LRP	 46	//(R0IE02LRP) Отключить питание ПР, ПУ канал 5
#define R0IE01LRP	 BUFFER[108]	//(R0IE01LRP) Отключение питание детекторов канал 5
#define idR0IE01LRP	 47	//(R0IE01LRP) Отключение питание детекторов канал 5
#define R0VN15RRP	 BUFFER[110]	//(R0VN15RRP) Номер ведущей камеры канал 5
#define idR0VN15RRP	 48	//(R0VN15RRP) Номер ведущей камеры канал 5
#define R0VN33RRP	 BUFFER[113]	//(R0VN33RRP) Нейтронный поток по камере КНК53М канал 5
#define idR0VN33RRP	 49	//(R0VN33RRP) Нейтронный поток по камере КНК53М канал 5
#define R0VN23RRP	 BUFFER[118]	//(R0VN23RRP) Нейтронный поток по камере КНК15-1 канал 5
#define idR0VN23RRP	 50	//(R0VN23RRP) Нейтронный поток по камере КНК15-1 канал 5
#define A0EE02LRP	 BUFFER[123]	//(A0EE02LRP) Исправность АКНП5 (от сшивки каналов) канал 5
#define idA0EE02LRP	 51	//(A0EE02LRP) Исправность АКНП5 (от сшивки каналов) канал 5
#define R0IN03RRP	 BUFFER[125]	//(R0IN03RRP) Частота КНК53М Гц (канал 5)
#define idR0IN03RRP	 52	//(R0IN03RRP) Частота КНК53М Гц (канал 5)
#define B8VC01RDU	 BUFFER[130]	//(B8VC01RDU) Координата АЗ2, мм
#define idB8VC01RDU	 53	//(B8VC01RDU) Координата АЗ2, мм
#define R0VN03RRP	 BUFFER[135]	//(R0VN03RRP) Измеренный нейтронный поток канал 5
#define idR0VN03RRP	 54	//(R0VN03RRP) Измеренный нейтронный поток канал 5
#define R0IN02RRP	 BUFFER[140]	//(R0IN02RRP) Частота КНК15-1 Гц (канал 5)
#define idR0IN02RRP	 55	//(R0IN02RRP) Частота КНК15-1 Гц (канал 5)
#define R0IN01RRP	 BUFFER[145]	//(R0IN01RRP) Частота СНМ-11 Гц (канал 5)
#define idR0IN01RRP	 56	//(R0IN01RRP) Частота СНМ-11 Гц (канал 5)
#define R0VN02RRP	 BUFFER[150]	//(R0VN02RRP) Уровень мощности канал 5
#define idR0VN02RRP	 57	//(R0VN02RRP) Уровень мощности канал 5
#define A6IS11LRP	 BUFFER[155]	//(A6IS11LRP) Приход на ВУ БЗ1
#define idA6IS11LRP	 58	//(A6IS11LRP) Приход на ВУ БЗ1
#define R0VN13RRP	 BUFFER[157]	//(R0VN13RRP) Нейтронный поток по камере  СНМ-11 канал 5
#define idR0VN13RRP	 59	//(R0VN13RRP) Нейтронный поток по камере  СНМ-11 канал 5
#define R0VN71LRP	 BUFFER[162]	//(R0VN71LRP) АС по мощности канал 5
#define idR0VN71LRP	 60	//(R0VN71LRP) АС по мощности канал 5
#define A1VT71LRP	 BUFFER[164]	//(A1VT71LRP) АС по температуре
#define idA1VT71LRP	 61	//(A1VT71LRP) АС по температуре
#define R0IE04LRP	 BUFFER[166]	//(R0IE04LRP) Отключить питание ПР, ПУ канал 6,7
#define idR0IE04LRP	 62	//(R0IE04LRP) Отключить питание ПР, ПУ канал 6,7
#define R0IE03LRP	 BUFFER[168]	//(R0IE03LRP) Отключение питание детекторов канал  6,7
#define idR0IE03LRP	 63	//(R0IE03LRP) Отключение питание детекторов канал  6,7
#define R0IE15LRP	 BUFFER[170]	//(R0IE15LRP) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
#define idR0IE15LRP	 64	//(R0IE15LRP) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
#define R0IE14LRP	 BUFFER[172]	//(R0IE14LRP) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
#define idR0IE14LRP	 65	//(R0IE14LRP) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
#define R0IE13LRP	 BUFFER[174]	//(R0IE13LRP) Исправность ВИП 0,5 -5к (№22)
#define idR0IE13LRP	 66	//(R0IE13LRP) Исправность ВИП 0,5 -5к (№22)
#define R0IE12LRP	 BUFFER[176]	//(R0IE12LRP) Исправность ВИП 0,5 -5к (№21)
#define idR0IE12LRP	 67	//(R0IE12LRP) Исправность ВИП 0,5 -5к (№21)
#define A0EE01LRP	 BUFFER[178]	//(A0EE01LRP) Исправность АКНП канал 5
#define idA0EE01LRP	 68	//(A0EE01LRP) Исправность АКНП канал 5
#define A0EE03LRP	 BUFFER[180]	//(A0EE03LRP) Неисправность от диагностики контроллера
#define idA0EE03LRP	 69	//(A0EE03LRP) Неисправность от диагностики контроллера
#define R0IE11LRP	 BUFFER[182]	//(R0IE11LRP) Исправность ВИП 1,6 (№20) СНМ11 5 канала
#define idR0IE11LRP	 70	//(R0IE11LRP) Исправность ВИП 1,6 (№20) СНМ11 5 канала
#define B0VT71LRP	 BUFFER[184]	//(B0VT71LRP) АС по температуре в АЗ2-3
#define idB0VT71LRP	 71	//(B0VT71LRP) АС по температуре в АЗ2-3
#define B0VT61LRP	 BUFFER[186]	//(B0VT61LRP) ПС по температуре в АЗ2-3
#define idB0VT61LRP	 72	//(B0VT61LRP) ПС по температуре в АЗ2-3
#define B0CT01IRP	 BUFFER[188]	//(B0CT01IRP) Температура АЗ2-3
#define idB0CT01IRP	 73	//(B0CT01IRP) Температура АЗ2-3
#define R0ET02LRP	 BUFFER[193]	//(R0ET02LRP) Признак наличия неисправности по температуре АЗ2-3
#define idR0ET02LRP	 74	//(R0ET02LRP) Признак наличия неисправности по температуре АЗ2-3
#define B0IT03IRP	 BUFFER[195]	//(B0IT03IRP) Температура АЗ2-3
#define idB0IT03IRP	 75	//(B0IT03IRP) Температура АЗ2-3
#define R0ET01LRP	 BUFFER[198]	//(R0ET01LRP) Признак наличия неисправности по температуре  АЗ1-3
#define idR0ET01LRP	 76	//(R0ET01LRP) Признак наличия неисправности по температуре  АЗ1-3
#define fEM_R0UH02RSS	 BUFFER[200]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define idfEM_R0UH02RSS	 77	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define fEM_R0UH03RSS	 BUFFER[205]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define idfEM_R0UH03RSS	 78	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define fEM_R7UX00RSS	 BUFFER[210]	//(R7UX00RSS) X-координата АЗ1 (см)
#define idfEM_R7UX00RSS	 79	//(R7UX00RSS) X-координата АЗ1 (см)
#define fEM_R7UY00RSS	 BUFFER[215]	//(R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	 80	//(R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UX13RSS	 BUFFER[220]	//(R7UX13RSS) X-координата камеры R7IN51
#define idfEM_R7UX13RSS	 81	//(R7UX13RSS) X-координата камеры R7IN51
#define fEM_R7UX14RSS	 BUFFER[225]	//(R7UX14RSS) X-координата камеры R7IN52
#define idfEM_R7UX14RSS	 82	//(R7UX14RSS) X-координата камеры R7IN52
#define fEM_R7UX15RSS	 BUFFER[230]	//(R7UX15RSS) X-координата камеры R7IN53
#define idfEM_R7UX15RSS	 83	//(R7UX15RSS) X-координата камеры R7IN53
#define fEM_R7UY13RSS	 BUFFER[235]	//(R7UY13RSS) Y-координата камеры R7IN51
#define idfEM_R7UY13RSS	 84	//(R7UY13RSS) Y-координата камеры R7IN51
#define fEM_R7UY14RSS	 BUFFER[240]	//(R7UY14RSS) Y-координата камеры R7IN52
#define idfEM_R7UY14RSS	 85	//(R7UY14RSS) Y-координата камеры R7IN52
#define fEM_R7UY15RSS	 BUFFER[245]	//(R7UY15RSS) Y-координата камеры R7IN53
#define idfEM_R7UY15RSS	 86	//(R7UY15RSS) Y-координата камеры R7IN53
#define fEM_A0UX00RSS	 BUFFER[250]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 87	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX13RSS	 BUFFER[255]	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define idfEM_A0UX13RSS	 88	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define fEM_A0UX14RSS	 BUFFER[260]	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define idfEM_A0UX14RSS	 89	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define fEM_A0UX15RSS	 BUFFER[265]	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define idfEM_A0UX15RSS	 90	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define fEM_B0UX03RSS	 BUFFER[270]	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	 91	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	 BUFFER[275]	//(B0UX04RSS) Второй коэффициент калибровки камеры4
#define idfEM_B0UX04RSS	 92	//(B0UX04RSS) Второй коэффициент калибровки камеры4
#define fEM_B0UX05RSS	 BUFFER[280]	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	 93	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_R0UH05RSS	 BUFFER[285]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 94	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UR01RRP	 BUFFER[290]	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
#define idfEM_R0UR01RRP	 95	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
#define fEM_R0UT02RZZ	 BUFFER[295]	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	 96	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RZZ	 BUFFER[300]	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	 97	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_R0UT72RZZ	 BUFFER[305]	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	 98	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	 BUFFER[310]	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	 99	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	 BUFFER[315]	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	 100	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT61RZZ	 BUFFER[320]	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	 101	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_R0UL52RSS	 BUFFER[325]	//(R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	 102	//(R0UL52RSS) Уровень АС по мощности
#define fEM_Z7UE20RRP	 BUFFER[330]	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
#define idfEM_Z7UE20RRP	 103	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
#define bFirstEnterFlag	 BUFFER[335]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 104	//(bFirstEnterFlag) 
#define internal1_m16_Nk	 BUFFER[337]	//(internal1_m16_Nk) Nk - ведущая камера
#define idinternal1_m16_Nk	 105	//(internal1_m16_Nk) Nk - ведущая камера
#define internal1_m61_tx	 BUFFER[340]	//(internal1_m61_tx) tx - время накопленное сек
#define idinternal1_m61_tx	 106	//(internal1_m61_tx) tx - время накопленное сек
#define internal1_m61_y0	 BUFFER[345]	//(internal1_m61_y0) y0
#define idinternal1_m61_y0	 107	//(internal1_m61_y0) y0
#define internal1_m70_tx	 BUFFER[346]	//(internal1_m70_tx) tx - время накопленное сек
#define idinternal1_m70_tx	 108	//(internal1_m70_tx) tx - время накопленное сек
#define internal1_m70_y0	 BUFFER[351]	//(internal1_m70_y0) y0
#define idinternal1_m70_y0	 109	//(internal1_m70_y0) y0
#define internal1_m78_y0	 BUFFER[352]	//(internal1_m78_y0) y0
#define idinternal1_m78_y0	 110	//(internal1_m78_y0) y0
#define internal1_m76_y0	 BUFFER[357]	//(internal1_m76_y0) y0
#define idinternal1_m76_y0	 111	//(internal1_m76_y0) y0
#define internal1_m90_y1	 BUFFER[362]	//(internal1_m90_y1) y1 - внутренний параметр
#define idinternal1_m90_y1	 112	//(internal1_m90_y1) y1 - внутренний параметр
#define internal1_m101_y1	 BUFFER[364]	//(internal1_m101_y1) y1 - внутренний параметр
#define idinternal1_m101_y1	 113	//(internal1_m101_y1) y1 - внутренний параметр
#define internal1_m88_y1	 BUFFER[366]	//(internal1_m88_y1) y1 - внутренний параметр
#define idinternal1_m88_y1	 114	//(internal1_m88_y1) y1 - внутренний параметр
#define internal1_m98_y1	 BUFFER[368]	//(internal1_m98_y1) y1 - внутренний параметр
#define idinternal1_m98_y1	 115	//(internal1_m98_y1) y1 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &R0EE02LDU},	//(R0EE02LDU) Питание  АКНП  отключить
	{ 2	,1	,1	, &B7MZ31LRP},	//(B7MZ31LRP) Клапан ОБДУВ АЗ2 открыть(обесточить)
	{ 3	,1	,1	, &A7MZ31LRP},	//(A7MZ31LRP) Клапан ОБДУВ АЗ1 открыть(обесточить)
	{ 4	,1	,1	, &C1MZ31LRP},	//(C1MZ31LRP) Кнопка ОБДУВ  на РПУ
	{ 5	,1	,1	, &C1MD31LRP},	//(C1MD31LRP) Кнопка ОБЩИЙ СБРОС  на РПУ
	{ 6	,1	,1	, &B3VS21LRP},	//(B3VS21LRP) Индикация - Приход на НУ ИС2
	{ 7	,1	,1	, &A3VS21LRP},	//(A3VS21LRP) Индикация - Приход на НУ ИС1
	{ 8	,1	,1	, &B2VS21LRP},	//(B2VS21LRP) Индикация - Приход на НУ РБ2-CC
	{ 9	,1	,1	, &A2VS21LRP},	//(A2VS21LRP) Индикация - Приход на НУ РБ1-CC
	{ 10	,1	,1	, &B1VS21LRP},	//(B1VS21LRP) Индикация - Приход на НУ ББ2
	{ 11	,1	,1	, &A1VS21LRP},	//(A1VS21LRP) Индикация - Приход на НУ ББ1
	{ 12	,1	,1	, &B2IS21LRP},	//(B2IS21LRP) Приход на НУ РБ2-CC
	{ 13	,1	,1	, &A2IS21LRP},	//(A2IS21LRP) Приход на НУ РБ1-CC
	{ 14	,1	,1	, &B1IS21LRP},	//(B1IS21LRP) Приход на НУ ББ2
	{ 15	,1	,1	, &A1IS21LRP},	//(A1IS21LRP) Приход на НУ ББ1
	{ 16	,1	,1	, &B3IS21LRP},	//(B3IS21LRP) Приход на НУ ИС2
	{ 17	,1	,1	, &A3IS21LRP},	//(A3IS21LRP) Приход на НУ ИС1
	{ 18	,1	,1	, &R7VE70LRP},	//(R7VE70LRP) Сигнал тревоги по неисправности РПУ на диспетчера
	{ 19	,1	,1	, &B6IS11LRP},	//(B6IS11LRP) Приход на ВУ БЗ2
	{ 20	,1	,1	, &R0DE3DLRP},	//(R0DE3DLRP) диагностика шкафа РПУ БП5/24Д место 8
	{ 21	,1	,1	, &R0DE3CLRP},	//(R0DE3CLRP) диагностика шкафа РПУ БП5/24Д место 7
	{ 22	,1	,1	, &R0DE3BLRP},	//(R0DE3BLRP) диагностика шкафа РПУ БП5/24Д место 6
	{ 23	,1	,1	, &R0DE3ALRP},	//(R0DE3ALRP) диагностика шкафа РПУ БП5/24Д место 5
	{ 24	,1	,1	, &R0DE39LRP},	//(R0DE39LRP) диагностика шкафа РПУ МП24-2 место 4
	{ 25	,1	,1	, &R0DE38LRP},	//(R0DE38LRP) диагностика шкафа РПУ МП15-3 место 2
	{ 26	,1	,1	, &R0DE37LRP},	//(R0DE37LRP) диагностика шкафа РПУ МП15-3.1 место 2
	{ 27	,1	,1	, &R0DE36LRP},	//(R0DE36LRP) диагностика шкафа РПУ МП15-3.1 место 1
	{ 28	,1	,1	, &R0DE35LRP},	//(R0DE35LRP) диагностика шкафа РПУ температура больше 53
	{ 29	,1	,1	, &R0DE34LRP},	//(R0DE34LRP) диагностика шкафа РПУ температура меньше 43
	{ 30	,1	,1	, &R0DE33LRP},	//(R0DE33LRP) диагностика шкафа РПУ двери
	{ 31	,1	,1	, &R0DE32LRP},	//(R0DE32LRP) диагностика шкафа РПУ сеть 2
	{ 32	,1	,1	, &R0DE31LRP},	//(R0DE31LRP) диагностика шкафа РПУ сеть 1
	{ 33	,3	,1	, &R0DE07LRP},	//(R0DE07LRP) диагностика модуля РПУ-ВДС место 7
	{ 34	,3	,1	, &R0DE08LRP},	//(R0DE08LRP) диагностика модуля РПУ-ФДС место 8
	{ 35	,3	,1	, &R0DE06LRP},	//(R0DE06LRP) диагностика модуля РПУ-ВАС место 6
	{ 36	,3	,1	, &R0DE03LRP},	//(R0DE03LRP) диагностика модуля РПУ-ВЧС место 3
	{ 37	,3	,1	, &R0DE02LRP},	//(R0DE02LRP) диагностика модуля РПУ-ВЧС место 2
	{ 38	,3	,1	, &R0DE01LRP},	//(R0DE01LRP) диагностика модуля РПУ-ВЧС место 1
	{ 39	,1	,1	, &A0VT71LRP},	//(A0VT71LRP) АС по температуре в АЗ1
	{ 40	,1	,1	, &A0VT61LRP},	//(A0VT61LRP) ПС по температуре в АЗ1
	{ 41	,8	,1	, &A0CT01IRP},	//(A0CT01IRP) Температура АЗ1-3
	{ 42	,3	,1	, &A0IT03IRP},	//(A0IT03IRP) Температура АЗ1-3
	{ 43	,8	,1	, &R0IN07RRP},	//(R0IN07RRP) Частота СНМ-11 Гц (канал 7)
	{ 44	,1	,1	, &R7VN71LRP},	//(R7VN71LRP) Сигнал тревоги по уровню нейтронного потока на диспетчера
	{ 45	,8	,1	, &R0IN06RRP},	//(R0IN06RRP) Частота СНМ-11 Гц (канал 6)
	{ 46	,1	,1	, &R0IE02LRP},	//(R0IE02LRP) Отключить питание ПР, ПУ канал 5
	{ 47	,1	,1	, &R0IE01LRP},	//(R0IE01LRP) Отключение питание детекторов канал 5
	{ 48	,3	,1	, &R0VN15RRP},	//(R0VN15RRP) Номер ведущей камеры канал 5
	{ 49	,8	,1	, &R0VN33RRP},	//(R0VN33RRP) Нейтронный поток по камере КНК53М канал 5
	{ 50	,8	,1	, &R0VN23RRP},	//(R0VN23RRP) Нейтронный поток по камере КНК15-1 канал 5
	{ 51	,1	,1	, &A0EE02LRP},	//(A0EE02LRP) Исправность АКНП5 (от сшивки каналов) канал 5
	{ 52	,8	,1	, &R0IN03RRP},	//(R0IN03RRP) Частота КНК53М Гц (канал 5)
	{ 53	,8	,1	, &B8VC01RDU},	//(B8VC01RDU) Координата АЗ2, мм
	{ 54	,8	,1	, &R0VN03RRP},	//(R0VN03RRP) Измеренный нейтронный поток канал 5
	{ 55	,8	,1	, &R0IN02RRP},	//(R0IN02RRP) Частота КНК15-1 Гц (канал 5)
	{ 56	,8	,1	, &R0IN01RRP},	//(R0IN01RRP) Частота СНМ-11 Гц (канал 5)
	{ 57	,8	,1	, &R0VN02RRP},	//(R0VN02RRP) Уровень мощности канал 5
	{ 58	,1	,1	, &A6IS11LRP},	//(A6IS11LRP) Приход на ВУ БЗ1
	{ 59	,8	,1	, &R0VN13RRP},	//(R0VN13RRP) Нейтронный поток по камере  СНМ-11 канал 5
	{ 60	,1	,1	, &R0VN71LRP},	//(R0VN71LRP) АС по мощности канал 5
	{ 61	,1	,1	, &A1VT71LRP},	//(A1VT71LRP) АС по температуре
	{ 62	,1	,1	, &R0IE04LRP},	//(R0IE04LRP) Отключить питание ПР, ПУ канал 6,7
	{ 63	,1	,1	, &R0IE03LRP},	//(R0IE03LRP) Отключение питание детекторов канал  6,7
	{ 64	,1	,1	, &R0IE15LRP},	//(R0IE15LRP) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
	{ 65	,1	,1	, &R0IE14LRP},	//(R0IE14LRP) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
	{ 66	,1	,1	, &R0IE13LRP},	//(R0IE13LRP) Исправность ВИП 0,5 -5к (№22)
	{ 67	,1	,1	, &R0IE12LRP},	//(R0IE12LRP) Исправность ВИП 0,5 -5к (№21)
	{ 68	,1	,1	, &A0EE01LRP},	//(A0EE01LRP) Исправность АКНП канал 5
	{ 69	,1	,1	, &A0EE03LRP},	//(A0EE03LRP) Неисправность от диагностики контроллера
	{ 70	,1	,1	, &R0IE11LRP},	//(R0IE11LRP) Исправность ВИП 1,6 (№20) СНМ11 5 канала
	{ 71	,1	,1	, &B0VT71LRP},	//(B0VT71LRP) АС по температуре в АЗ2-3
	{ 72	,1	,1	, &B0VT61LRP},	//(B0VT61LRP) ПС по температуре в АЗ2-3
	{ 73	,8	,1	, &B0CT01IRP},	//(B0CT01IRP) Температура АЗ2-3
	{ 74	,1	,1	, &R0ET02LRP},	//(R0ET02LRP) Признак наличия неисправности по температуре АЗ2-3
	{ 75	,3	,1	, &B0IT03IRP},	//(B0IT03IRP) Температура АЗ2-3
	{ 76	,1	,1	, &R0ET01LRP},	//(R0ET01LRP) Признак наличия неисправности по температуре  АЗ1-3
	{ 77	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{ 78	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{ 79	,8	,1	, &fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{ 80	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{ 81	,8	,1	, &fEM_R7UX13RSS},	//(R7UX13RSS) X-координата камеры R7IN51
	{ 82	,8	,1	, &fEM_R7UX14RSS},	//(R7UX14RSS) X-координата камеры R7IN52
	{ 83	,8	,1	, &fEM_R7UX15RSS},	//(R7UX15RSS) X-координата камеры R7IN53
	{ 84	,8	,1	, &fEM_R7UY13RSS},	//(R7UY13RSS) Y-координата камеры R7IN51
	{ 85	,8	,1	, &fEM_R7UY14RSS},	//(R7UY14RSS) Y-координата камеры R7IN52
	{ 86	,8	,1	, &fEM_R7UY15RSS},	//(R7UY15RSS) Y-координата камеры R7IN53
	{ 87	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 88	,8	,1	, &fEM_A0UX13RSS},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{ 89	,8	,1	, &fEM_A0UX14RSS},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{ 90	,8	,1	, &fEM_A0UX15RSS},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{ 91	,8	,1	, &fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{ 92	,8	,1	, &fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры4
	{ 93	,8	,1	, &fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{ 94	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 95	,8	,1	, &fEM_R0UR01RRP},	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
	{ 96	,8	,1	, &fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{ 97	,8	,1	, &fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{ 98	,8	,1	, &fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{ 99	,8	,1	, &fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{ 100	,8	,1	, &fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{ 101	,8	,1	, &fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{ 102	,8	,1	, &fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{ 103	,8	,1	, &fEM_Z7UE20RRP},	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
	{ 104	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 105	,3	,1	, &internal1_m16_Nk},	//(internal1_m16_Nk) Nk - ведущая камера
	{ 106	,8	,1	, &internal1_m61_tx},	//(internal1_m61_tx) tx - время накопленное сек
	{ 107	,18	,1	, &internal1_m61_y0},	//(internal1_m61_y0) y0
	{ 108	,8	,1	, &internal1_m70_tx},	//(internal1_m70_tx) tx - время накопленное сек
	{ 109	,18	,1	, &internal1_m70_y0},	//(internal1_m70_y0) y0
	{ 110	,8	,1	, &internal1_m78_y0},	//(internal1_m78_y0) y0
	{ 111	,8	,1	, &internal1_m76_y0},	//(internal1_m76_y0) y0
	{ 112	,1	,1	, &internal1_m90_y1},	//(internal1_m90_y1) y1 - внутренний параметр
	{ 113	,1	,1	, &internal1_m101_y1},	//(internal1_m101_y1) y1 - внутренний параметр
	{ 114	,1	,1	, &internal1_m88_y1},	//(internal1_m88_y1) y1 - внутренний параметр
	{ 115	,1	,1	, &internal1_m98_y1},	//(internal1_m98_y1) y1 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="rpu.bin\0";   // Имя файла для сохранения констант
#pragma pop
static short saveVariables[]={      // Id переменных для сохранения
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_RPU[]={  // 
	{&R0EE02LDU,1,0},	//(R0EE02LDU) Питание  АКНП  отключить
	{&C1MZ31LRP,1,1},	//(C1MZ31LRP) Кнопка ОБДУВ  на РПУ
	{&C1MD31LRP,1,2},	//(C1MD31LRP) Кнопка ОБЩИЙ СБРОС  на РПУ
	{&B2IS21LRP,1,3},	//(B2IS21LRP) Приход на НУ РБ2-CC
	{&A2IS21LRP,1,4},	//(A2IS21LRP) Приход на НУ РБ1-CC
	{&B1IS21LRP,1,5},	//(B1IS21LRP) Приход на НУ ББ2
	{&A1IS21LRP,1,6},	//(A1IS21LRP) Приход на НУ ББ1
	{&B3IS21LRP,1,7},	//(B3IS21LRP) Приход на НУ ИС2
	{&A3IS21LRP,1,8},	//(A3IS21LRP) Приход на НУ ИС1
	{&B6IS11LRP,1,9},	//(B6IS11LRP) Приход на ВУ БЗ2
	{&A6IS11LRP,1,10},	//(A6IS11LRP) Приход на ВУ БЗ1
	{&R0IE15LRP,1,11},	//(R0IE15LRP) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
	{&R0IE14LRP,1,12},	//(R0IE14LRP) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
	{&R0IE13LRP,1,13},	//(R0IE13LRP) Исправность ВИП 0,5 -5к (№22)
	{&R0IE12LRP,1,14},	//(R0IE12LRP) Исправность ВИП 0,5 -5к (№21)
	{&A0EE03LRP,1,15},	//(A0EE03LRP) Неисправность от диагностики контроллера
	{&R0IE11LRP,1,16},	//(R0IE11LRP) Исправность ВИП 1,6 (№20) СНМ11 5 канала
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_RPU[]={  // 
	{&B7MZ31LRP,1,0},	//(B7MZ31LRP) Клапан ОБДУВ АЗ2 открыть(обесточить)
	{&A7MZ31LRP,1,1},	//(A7MZ31LRP) Клапан ОБДУВ АЗ1 открыть(обесточить)
	{&B3VS21LRP,1,2},	//(B3VS21LRP) Индикация - Приход на НУ ИС2
	{&A3VS21LRP,1,3},	//(A3VS21LRP) Индикация - Приход на НУ ИС1
	{&B2VS21LRP,1,4},	//(B2VS21LRP) Индикация - Приход на НУ РБ2-CC
	{&A2VS21LRP,1,5},	//(A2VS21LRP) Индикация - Приход на НУ РБ1-CC
	{&B1VS21LRP,1,6},	//(B1VS21LRP) Индикация - Приход на НУ ББ2
	{&A1VS21LRP,1,7},	//(A1VS21LRP) Индикация - Приход на НУ ББ1
	{&R7VE70LRP,1,8},	//(R7VE70LRP) Сигнал тревоги по неисправности РПУ на диспетчера
	{&R0DE3DLRP,1,9},	//(R0DE3DLRP) диагностика шкафа РПУ БП5/24Д место 8
	{&R0DE3CLRP,1,10},	//(R0DE3CLRP) диагностика шкафа РПУ БП5/24Д место 7
	{&R0DE3BLRP,1,11},	//(R0DE3BLRP) диагностика шкафа РПУ БП5/24Д место 6
	{&R0DE3ALRP,1,12},	//(R0DE3ALRP) диагностика шкафа РПУ БП5/24Д место 5
	{&R0DE39LRP,1,13},	//(R0DE39LRP) диагностика шкафа РПУ МП24-2 место 4
	{&R0DE38LRP,1,14},	//(R0DE38LRP) диагностика шкафа РПУ МП15-3 место 2
	{&R0DE37LRP,1,15},	//(R0DE37LRP) диагностика шкафа РПУ МП15-3.1 место 2
	{&R0DE36LRP,1,16},	//(R0DE36LRP) диагностика шкафа РПУ МП15-3.1 место 1
	{&R0DE35LRP,1,17},	//(R0DE35LRP) диагностика шкафа РПУ температура больше 53
	{&R0DE34LRP,1,18},	//(R0DE34LRP) диагностика шкафа РПУ температура меньше 43
	{&R0DE33LRP,1,19},	//(R0DE33LRP) диагностика шкафа РПУ двери
	{&R0DE32LRP,1,20},	//(R0DE32LRP) диагностика шкафа РПУ сеть 2
	{&R0DE31LRP,1,21},	//(R0DE31LRP) диагностика шкафа РПУ сеть 1
	{&A0VT71LRP,1,22},	//(A0VT71LRP) АС по температуре в АЗ1
	{&A0VT61LRP,1,23},	//(A0VT61LRP) ПС по температуре в АЗ1
	{&R7VN71LRP,1,24},	//(R7VN71LRP) Сигнал тревоги по уровню нейтронного потока на диспетчера
	{&R0IE02LRP,1,25},	//(R0IE02LRP) Отключить питание ПР, ПУ канал 5
	{&R0IE01LRP,1,26},	//(R0IE01LRP) Отключение питание детекторов канал 5
	{&A0EE02LRP,1,27},	//(A0EE02LRP) Исправность АКНП5 (от сшивки каналов) канал 5
	{&R0VN71LRP,1,28},	//(R0VN71LRP) АС по мощности канал 5
	{&A1VT71LRP,1,29},	//(A1VT71LRP) АС по температуре
	{&R0IE04LRP,1,30},	//(R0IE04LRP) Отключить питание ПР, ПУ канал 6,7
	{&R0IE03LRP,1,31},	//(R0IE03LRP) Отключение питание детекторов канал  6,7
	{&A0EE01LRP,1,32},	//(A0EE01LRP) Исправность АКНП канал 5
	{&B0VT71LRP,1,33},	//(B0VT71LRP) АС по температуре в АЗ2-3
	{&B0VT61LRP,1,34},	//(B0VT61LRP) ПС по температуре в АЗ2-3
	{&R0ET02LRP,1,35},	//(R0ET02LRP) Признак наличия неисправности по температуре АЗ2-3
	{&R0ET01LRP,1,36},	//(R0ET01LRP) Признак наличия неисправности по температуре  АЗ1-3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_RPU[]={  // 
	{&R0DE07LRP,3,0},	//(R0DE07LRP) диагностика модуля РПУ-ВДС место 7
	{&R0DE08LRP,3,1},	//(R0DE08LRP) диагностика модуля РПУ-ФДС место 8
	{&R0DE06LRP,3,2},	//(R0DE06LRP) диагностика модуля РПУ-ВАС место 6
	{&R0DE03LRP,3,3},	//(R0DE03LRP) диагностика модуля РПУ-ВЧС место 3
	{&R0DE02LRP,3,4},	//(R0DE02LRP) диагностика модуля РПУ-ВЧС место 2
	{&R0DE01LRP,3,5},	//(R0DE01LRP) диагностика модуля РПУ-ВЧС место 1
	{&A0CT01IRP,8,6},	//(A0CT01IRP) Температура АЗ1-3
	{&R0VN15RRP,3,8},	//(R0VN15RRP) Номер ведущей камеры канал 5
	{&R0VN33RRP,8,9},	//(R0VN33RRP) Нейтронный поток по камере КНК53М канал 5
	{&R0VN23RRP,8,11},	//(R0VN23RRP) Нейтронный поток по камере КНК15-1 канал 5
	{&R0VN03RRP,8,13},	//(R0VN03RRP) Измеренный нейтронный поток канал 5
	{&R0VN02RRP,8,15},	//(R0VN02RRP) Уровень мощности канал 5
	{&R0VN13RRP,8,17},	//(R0VN13RRP) Нейтронный поток по камере  СНМ-11 канал 5
	{&B0CT01IRP,8,19},	//(B0CT01IRP) Температура АЗ2-3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_RPU[]={  // 
	{&A0IT03IRP,3,0},	//(A0IT03IRP) Температура АЗ1-3
	{&R0IN07RRP,8,1},	//(R0IN07RRP) Частота СНМ-11 Гц (канал 7)
	{&R0IN06RRP,8,3},	//(R0IN06RRP) Частота СНМ-11 Гц (канал 6)
	{&R0IN03RRP,8,5},	//(R0IN03RRP) Частота КНК53М Гц (канал 5)
	{&B8VC01RDU,8,7},	//(B8VC01RDU) Координата АЗ2, мм
	{&R0IN02RRP,8,9},	//(R0IN02RRP) Частота КНК15-1 Гц (канал 5)
	{&R0IN01RRP,8,11},	//(R0IN01RRP) Частота СНМ-11 Гц (канал 5)
	{&B0IT03IRP,3,13},	//(B0IT03IRP) Температура АЗ2-3
	{&fEM_R0UH02RSS,8,14},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{&fEM_R0UH03RSS,8,16},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{&fEM_R7UX00RSS,8,18},	//(R7UX00RSS) X-координата АЗ1 (см)
	{&fEM_R7UY00RSS,8,20},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{&fEM_R7UX13RSS,8,22},	//(R7UX13RSS) X-координата камеры R7IN51
	{&fEM_R7UX14RSS,8,24},	//(R7UX14RSS) X-координата камеры R7IN52
	{&fEM_R7UX15RSS,8,26},	//(R7UX15RSS) X-координата камеры R7IN53
	{&fEM_R7UY13RSS,8,28},	//(R7UY13RSS) Y-координата камеры R7IN51
	{&fEM_R7UY14RSS,8,30},	//(R7UY14RSS) Y-координата камеры R7IN52
	{&fEM_R7UY15RSS,8,32},	//(R7UY15RSS) Y-координата камеры R7IN53
	{&fEM_A0UX00RSS,8,34},	//(A0UX00RSS) Эффективный радиус АЗ
	{&fEM_A0UX13RSS,8,36},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{&fEM_A0UX14RSS,8,38},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{&fEM_A0UX15RSS,8,40},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{&fEM_B0UX03RSS,8,42},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{&fEM_B0UX04RSS,8,44},	//(B0UX04RSS) Второй коэффициент калибровки камеры4
	{&fEM_B0UX05RSS,8,46},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{&fEM_R0UH05RSS,8,48},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_R0UR01RRP,8,50},	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
	{&fEM_R0UT02RZZ,8,52},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{&fEM_R0UT01RZZ,8,54},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{&fEM_R0UT72RZZ,8,56},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{&fEM_R0UT71RZZ,8,58},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{&fEM_R0UT62RZZ,8,60},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{&fEM_R0UT61RZZ,8,62},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{&fEM_R0UL52RSS,8,64},	//(R0UL52RSS) Уровень АС по мощности
	{&fEM_Z7UE20RRP,8,66},	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
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
	{&R0DE3DLRP,1,0},	//(R0DE3DLRP) диагностика шкафа РПУ БП5/24Д место 8
	{&R0DE3CLRP,1,1},	//(R0DE3CLRP) диагностика шкафа РПУ БП5/24Д место 7
	{&R0DE3BLRP,1,2},	//(R0DE3BLRP) диагностика шкафа РПУ БП5/24Д место 6
	{&R0DE3ALRP,1,3},	//(R0DE3ALRP) диагностика шкафа РПУ БП5/24Д место 5
	{&R0DE39LRP,1,4},	//(R0DE39LRP) диагностика шкафа РПУ МП24-2 место 4
	{&R0DE38LRP,1,5},	//(R0DE38LRP) диагностика шкафа РПУ МП15-3 место 2
	{&R0DE37LRP,1,6},	//(R0DE37LRP) диагностика шкафа РПУ МП15-3.1 место 2
	{&R0DE36LRP,1,7},	//(R0DE36LRP) диагностика шкафа РПУ МП15-3.1 место 1
	{&R0DE35LRP,1,8},	//(R0DE35LRP) диагностика шкафа РПУ температура больше 53
	{&R0DE34LRP,1,9},	//(R0DE34LRP) диагностика шкафа РПУ температура меньше 43
	{&R0DE33LRP,1,10},	//(R0DE33LRP) диагностика шкафа РПУ двери
	{&R0DE32LRP,1,11},	//(R0DE32LRP) диагностика шкафа РПУ сеть 2
	{&R0DE31LRP,1,12},	//(R0DE31LRP) диагностика шкафа РПУ сеть 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DiagnRPU[]={  // 
	{&R0DE07LRP,3,0},	//(R0DE07LRP) диагностика модуля РПУ-ВДС место 7
	{&R0DE08LRP,3,1},	//(R0DE08LRP) диагностика модуля РПУ-ФДС место 8
	{&R0DE06LRP,3,2},	//(R0DE06LRP) диагностика модуля РПУ-ВАС место 6
	{&R0DE03LRP,3,3},	//(R0DE03LRP) диагностика модуля РПУ-ВЧС место 3
	{&R0DE02LRP,3,4},	//(R0DE02LRP) диагностика модуля РПУ-ВЧС место 2
	{&R0DE01LRP,3,5},	//(R0DE01LRP) диагностика модуля РПУ-ВЧС место 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DiagnRPU[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_RPU[0],&di_RPU[0],&ir_RPU[0],&hr_RPU[0],NULL,NULL,NULL,0},	 //общий slave RPU
	{0,5003,&coil_DiagnRPU[0],&di_DiagnRPU[0],&ir_DiagnRPU[0],&hr_DiagnRPU[0],NULL,NULL,NULL,0},	 //Диагностика шкафа РПУ

	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS01[670];	//VCHS01
static vchs_inipar ini_VCHS01={172,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,};
#pragma pack(push,1)
static table_drv table_VCHS01={0,0,&ini_VCHS01,buf_VCHS01,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS01[]={
	{&R0IN01RRP,8,0},
	{&R0IN02RRP,8,5},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS02[670];	//VCHS02
static vchs_inipar ini_VCHS02={172,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,};
#pragma pack(push,1)
static table_drv table_VCHS02={0,0,&ini_VCHS02,buf_VCHS02,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS02[]={
	{&R0IN03RRP,8,0},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS03[670];	//VCHS03
static vchs_inipar ini_VCHS03={172,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,};
#pragma pack(push,1)
static table_drv table_VCHS03={0,0,&ini_VCHS03,buf_VCHS03,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS03[]={
	{&R0IN06RRP,8,0},
	{&R0IN07RRP,8,5},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vas84r.h>
static char buf_VAS84[26];	//VAS84
static vas84r_inipar ini_VAS84={172,255,1,8,0xff,0,16,};
#pragma pack(push,1)
static table_drv table_VAS84={0,0,&ini_VAS84,buf_VAS84,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VAS84[]={
	{&A0IT03IRP,3,0},
	{&B0IT03IRP,3,3},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS32[64];	//VDS32
static vds32r_inipar ini_VDS32={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS32={0,0,&ini_VDS32,buf_VDS32,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32[]={
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS16[38];	//FDS16
static fds16r_inipar ini_FDS16={0x04,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS16={0,0,&ini_FDS16,buf_FDS16,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS16[]={
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/sbkfp7.h>
static char buf_SBKFP[26];	//SBKFP
static sbk_inipar ini_SBKFP={0xc2,0xff,8,8,};
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
	{&R0DE3ALRP,1,18},
	{&R0DE3BLRP,1,20},
	{&R0DE3CLRP,1,22},
	{&R0DE3DLRP,1,24},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc4,0x01,12,670,def_buf_VCHS01,&table_VCHS01}, //VCHS01
	{0xc4,0x02,12,670,def_buf_VCHS02,&table_VCHS02}, //VCHS02
	{0xc4,0x03,12,670,def_buf_VCHS03,&table_VCHS03}, //VCHS03
	{0xc6,0x06,7,26,def_buf_VAS84,&table_VAS84}, //VAS84
	{0xc2,0x07,15,64,def_buf_VDS32,&table_VDS32}, //VDS32
	{0x04,0x08,20,38,def_buf_FDS16,&table_FDS16}, //FDS16
	{0x01,0x20,4,26,def_buf_SBKFP,&table_SBKFP}, //SBKFP
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
}

// Р’СЃС‚Р°РІРєР° Рє VCHS
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
ssint iRM_819_ = {819,0}; /* a */ 
ssint iRM_4095_ = {4095,0}; /* b */ 
sschar bRM_1_ = {1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 

uspaint8 SpaEEPROMBuf[135];

/* Определение переменных */
ssfloat var1;
ssfloat var2;
ssbool var3;
ssfloat var4;
ssfloat var5;
ssfloat var6;
ssint var7;
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
sschar var20;
ssbool var21;
sschar var22;
ssbool var23;
ssbool var24;
ssbool var25;
ssbool var26;
ssbool var27;
ssfloat var28;
ssfloat var29;
sschar var30;
ssbool var31;
ssbool var32;
sschar var33;
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
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */

/* Объявление структур */
_S_ocham  S_ocham_16_1 = {&R0IN01RRP,&R0IN02RRP,&R0IN03RRP,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX13RSS,&fEM_B0UX03RSS,&fEM_A0UX14RSS,&fEM_B0UX04RSS,&fEM_A0UX15RSS,&fEM_B0UX05RSS,&fEM_R7UX13RSS,&fEM_R7UY13RSS,&fEM_R7UX14RSS,&fEM_R7UY14RSS,&fEM_R7UX15RSS,&fEM_R7UY15RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var1,&var2,&var3,&var4,&var5,&var6,&var7,&internal1_m16_Nk};
_S_or2  S_or2_57_1 = {&A6IS11LRP,&B6IS11LRP,&vainSBool};
_S_or5  S_or5_62_1 = {&var18,&var19,&A0EE03LRP,&var9,&var36,&var8};
_S_or2  S_or2_84_1 = {&var43,&var44,&var9};
_S_or4  S_or4_42_1 = {&var17,&var14,&var16,&var12,&var10};
_S_or2  S_or2_89_1 = {&var42,&var31,&var11};
_S_or2  S_or2_105_1 = {&var13,&var11,&var12};
_S_or2  S_or2_85_1 = {&var41,&var34,&var13};
_S_and3  S_and3_37_1 = {&var15,&var27,&var21,&var14};
_S_and4  S_and4_36_1 = {&R0IE11LRP,&var3,&R0IE12LRP,&R0IE13LRP,&var15};
_S_and3  S_and3_45_1 = {&var25,&R0IE14LRP,&var37,&var16};
_S_and3  S_and3_44_1 = {&R0IE15LRP,&var25,&var38,&var17};
_S_and3  S_and3_52_1 = {&R0IE14LRP,&var25,&var40,&var18};
_S_and3  S_and3_51_1 = {&var39,&R0IE15LRP,&var25,&var19};
_S_geterr  S_geterr_48_1 = {&R0IN06RRP,&dRM_0_,&iRM_0_,&bRM_0_,&var20,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_noto  S_noto_71_1 = {&var26,&var21};
_S_geterr  S_geterr_47_1 = {&R0IN07RRP,&dRM_0_,&iRM_0_,&bRM_0_,&var22,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_zzfs  S_zzfs_61_1 = {&var24,&fEM_Z7UE20RRP,&var23,&internal1_m61_tx,&internal1_m61_y0};
_S_or3  S_or3_60_1 = {&A6IS11LRP,&B6IS11LRP,&R0EE02LDU,&var24};
_S_noto  S_noto_58_1 = {&var23,&var25};
_S_zzfs  S_zzfs_70_1 = {&R0EE02LDU,&fEM_Z7UE20RRP,&var26,&internal1_m70_tx,&internal1_m70_y0};
_S_bol  S_bol_35_1 = {&var2,&fEM_R0UL52RSS,&var27};
_S_scalzz  S_scalzz_78_1 = {&B0IT03IRP,&iRM_819_,&iRM_4095_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var28,&internal1_m78_y0};
_S_scalzz  S_scalzz_76_1 = {&A0IT03IRP,&iRM_819_,&iRM_4095_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var29,&internal1_m76_y0};
_S_geterr  S_geterr_80_1 = {&var29,&dRM_0_,&iRM_0_,&bRM_0_,&var30,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_90_1 = {&var28,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var31,&internal1_m90_y1};
_S_drg  S_drg_101_1 = {&var28,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var32,&internal1_m101_y1};
_S_geterr  S_geterr_82_1 = {&var28,&dRM_0_,&iRM_0_,&bRM_0_,&var33,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_88_1 = {&var29,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var34,&internal1_m88_y1};
_S_drg  S_drg_98_1 = {&var29,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var35,&internal1_m98_y1};
_S_noto  S_noto_67_1 = {&var15,&var36};
_S_bol  S_bol_53_1 = {&R0IN07RRP,&fEM_R0UR01RRP,&var37};
_S_bol  S_bol_43_1 = {&R0IN06RRP,&fEM_R0UR01RRP,&var38};


void Scheme()
{
//if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
//  scalzz(&S_scalzz_76_1);
//  scalzz(&S_scalzz_78_1);
//  geterr(&S_geterr_47_1);
//  geterr(&S_geterr_48_1);
//  or2(&S_or2_57_1);
//  ocham(&S_ocham_16_1);
//  bol(&S_bol_43_1);
//  bol(&S_bol_53_1);
//  drg(&S_drg_98_1);
//  drg(&S_drg_88_1);
//  geterr(&S_geterr_82_1);
//  drg(&S_drg_101_1);
//  drg(&S_drg_90_1);
//  geterr(&S_geterr_80_1);
//  bol(&S_bol_35_1);
//  zzfs(&S_zzfs_70_1);
//  or3(&S_or3_60_1);
//  zzfs(&S_zzfs_61_1);
//  noto(&S_noto_71_1);
//  and4(&S_and4_36_1);
//  and3(&S_and3_37_1);
//  setData(&var41,&var30);
//  or2(&S_or2_85_1);
//  setData(&var42,&var33);
//  or2(&S_or2_89_1);
//  setData(&var43,&var30);
//  setData(&var44,&var33);
//  or2(&S_or2_84_1);
//  noto(&S_noto_67_1);
//  noto(&S_noto_58_1);
//  setData(&var39,&var22);
//  and3(&S_and3_51_1);
//  setData(&var40,&var20);
//  and3(&S_and3_52_1);
//  and3(&S_and3_44_1);
//  and3(&S_and3_45_1);
//  or2(&S_or2_105_1);
//  or4(&S_or4_42_1);
//  or5(&S_or5_62_1);
//  moveData(idB7MZ31LRP,idC1MZ31LRP);
//  moveData(idA7MZ31LRP,idC1MZ31LRP);
//  moveData(idB3VS21LRP,idB3IS21LRP);
//  moveData(idA3VS21LRP,idA3IS21LRP);
//  moveData(idB2VS21LRP,idB2IS21LRP);
//  moveData(idA2VS21LRP,idA2IS21LRP);
//  moveData(idB1VS21LRP,idB1IS21LRP);
//  moveData(idA1VS21LRP,idA1IS21LRP);
//  setData(idR7VE70LRP,&var8);
//  setData(idR0VN13RRP,&var4);
//  setData(idR0VN71LRP,&var27);
//  setData(idA1VT71LRP,&var12);
//  setData(idR0IE04LRP,&var23);
//  setData(idR0IE03LRP,&var23);
//  setData(idA0EE01LRP,&var15);
//  setData(idB0VT71LRP,&var11);
//  setData(idB0VT61LRP,&var32);
//  setData(idB0CT01IRP,&var28);
//  setData(idR0ET02LRP,&var33);
//  setData(idR0ET01LRP,&var30);
//  setData(idA0VT71LRP,&var13);
//  setData(idA0VT61LRP,&var35);
//  setData(idA0CT01IRP,&var29);
//  setData(idR7VN71LRP,&var10);
//  setData(idR0IE02LRP,&var26);
//  setData(idR0IE01LRP,&var26);
//  setData(idR0VN15RRP,&var7);
//  setData(idR0VN33RRP,&var6);
//  setData(idR0VN23RRP,&var5);
//  setData(idA0EE02LRP,&var3);
//  setData(idR0VN03RRP,&var1);
//  setData(idR0VN02RRP,&var2);
//
//  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}

#endif
