#ifndef RPU_H
#define RPU_H
// Подсистема RPU:RPU
static char SimulOn=1;
static short CodeSub=8;
static char SimulIP[]="192.168.1.17\0";
static int SimulPort=5555;
static int StepCycle=5;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 375
static char BUFFER[375];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.31\0", 5432, "192.168.10.131\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0DE01LRP	 BUFFER[0]	//(R0DE01LRP) диагностика модуля РПУ-ВЧС место 1
#define idR0DE01LRP	 1	//(R0DE01LRP) диагностика модуля РПУ-ВЧС место 1
#define R0EE02LDU	 BUFFER[3]	//(R0EE02LDU) Питание  АКНП  отключить
#define idR0EE02LDU	 2	//(R0EE02LDU) Питание  АКНП  отключить
#define B7MZ31LRP	 BUFFER[5]	//(B7MZ31LRP) Клапан ОБДУВ АЗ2 открыть(обесточить)
#define idB7MZ31LRP	 3	//(B7MZ31LRP) Клапан ОБДУВ АЗ2 открыть(обесточить)
#define A7MZ31LRP	 BUFFER[7]	//(A7MZ31LRP) Клапан ОБДУВ АЗ1 открыть(обесточить)
#define idA7MZ31LRP	 4	//(A7MZ31LRP) Клапан ОБДУВ АЗ1 открыть(обесточить)
#define C1MZ31LRP	 BUFFER[9]	//(C1MZ31LRP) Кнопка ОБДУВ  на РПУ
#define idC1MZ31LRP	 5	//(C1MZ31LRP) Кнопка ОБДУВ  на РПУ
#define C1MD31LRP	 BUFFER[11]	//(C1MD31LRP) Кнопка ОБЩИЙ СБРОС  на РПУ
#define idC1MD31LRP	 6	//(C1MD31LRP) Кнопка ОБЩИЙ СБРОС  на РПУ
#define B3VS21LRP	 BUFFER[13]	//(B3VS21LRP) Индикация - Приход на НУ ИС2
#define idB3VS21LRP	 7	//(B3VS21LRP) Индикация - Приход на НУ ИС2
#define A3VS21LRP	 BUFFER[15]	//(A3VS21LRP) Индикация - Приход на НУ ИС1
#define idA3VS21LRP	 8	//(A3VS21LRP) Индикация - Приход на НУ ИС1
#define B2VS21LRP	 BUFFER[17]	//(B2VS21LRP) Индикация - Приход на НУ РБ2-CC
#define idB2VS21LRP	 9	//(B2VS21LRP) Индикация - Приход на НУ РБ2-CC
#define A2VS21LRP	 BUFFER[19]	//(A2VS21LRP) Индикация - Приход на НУ РБ1-CC
#define idA2VS21LRP	 10	//(A2VS21LRP) Индикация - Приход на НУ РБ1-CC
#define B1VS21LRP	 BUFFER[21]	//(B1VS21LRP) Индикация - Приход на НУ ББ2
#define idB1VS21LRP	 11	//(B1VS21LRP) Индикация - Приход на НУ ББ2
#define A1VS21LRP	 BUFFER[23]	//(A1VS21LRP) Индикация - Приход на НУ ББ1
#define idA1VS21LRP	 12	//(A1VS21LRP) Индикация - Приход на НУ ББ1
#define B2IS21LRP	 BUFFER[25]	//(B2IS21LRP) Приход на НУ РБ2-CC
#define idB2IS21LRP	 13	//(B2IS21LRP) Приход на НУ РБ2-CC
#define A2IS21LRP	 BUFFER[27]	//(A2IS21LRP) Приход на НУ РБ1-CC
#define idA2IS21LRP	 14	//(A2IS21LRP) Приход на НУ РБ1-CC
#define B1IS21LRP	 BUFFER[29]	//(B1IS21LRP) Приход на НУ ББ2
#define idB1IS21LRP	 15	//(B1IS21LRP) Приход на НУ ББ2
#define A1IS21LRP	 BUFFER[31]	//(A1IS21LRP) Приход на НУ ББ1
#define idA1IS21LRP	 16	//(A1IS21LRP) Приход на НУ ББ1
#define B3IS21LRP	 BUFFER[33]	//(B3IS21LRP) Приход на НУ ИС2
#define idB3IS21LRP	 17	//(B3IS21LRP) Приход на НУ ИС2
#define A3IS21LRP	 BUFFER[35]	//(A3IS21LRP) Приход на НУ ИС1
#define idA3IS21LRP	 18	//(A3IS21LRP) Приход на НУ ИС1
#define R7VE70LRP	 BUFFER[37]	//(R7VE70LRP) Сигнал тревоги по неисправности РПУ на диспетчера
#define idR7VE70LRP	 19	//(R7VE70LRP) Сигнал тревоги по неисправности РПУ на диспетчера
#define ttl	 BUFFER[39]	//(ttl) ttl
#define idttl	 20	//(ttl) ttl
#define TestDiagn	 BUFFER[42]	//(TestDiagn) Неисправность от диагностики
#define idTestDiagn	 21	//(TestDiagn) Неисправность от диагностики
#define R0DE3DLRP	 BUFFER[44]	//(R0DE3DLRP) диагностика шкафа РПУ БП5/24Д место 8
#define idR0DE3DLRP	 22	//(R0DE3DLRP) диагностика шкафа РПУ БП5/24Д место 8
#define R0DE3CLRP	 BUFFER[46]	//(R0DE3CLRP) диагностика шкафа РПУ БП5/24Д место 7
#define idR0DE3CLRP	 23	//(R0DE3CLRP) диагностика шкафа РПУ БП5/24Д место 7
#define R0DE3BLRP	 BUFFER[48]	//(R0DE3BLRP) диагностика шкафа РПУ БП5/24Д место 6
#define idR0DE3BLRP	 24	//(R0DE3BLRP) диагностика шкафа РПУ БП5/24Д место 6
#define R0DE3ALRP	 BUFFER[50]	//(R0DE3ALRP) диагностика шкафа РПУ БП5/24Д место 5
#define idR0DE3ALRP	 25	//(R0DE3ALRP) диагностика шкафа РПУ БП5/24Д место 5
#define R0DE39LRP	 BUFFER[52]	//(R0DE39LRP) диагностика шкафа РПУ МП24-2 место 4
#define idR0DE39LRP	 26	//(R0DE39LRP) диагностика шкафа РПУ МП24-2 место 4
#define R0DE38LRP	 BUFFER[54]	//(R0DE38LRP) диагностика шкафа РПУ МП15-3 место 3
#define idR0DE38LRP	 27	//(R0DE38LRP) диагностика шкафа РПУ МП15-3 место 3
#define R0DE37LRP	 BUFFER[56]	//(R0DE37LRP) диагностика шкафа РПУ МП15-3.1 место 2
#define idR0DE37LRP	 28	//(R0DE37LRP) диагностика шкафа РПУ МП15-3.1 место 2
#define R0DE36LRP	 BUFFER[58]	//(R0DE36LRP) диагностика шкафа РПУ МП15-3.1 место 1
#define idR0DE36LRP	 29	//(R0DE36LRP) диагностика шкафа РПУ МП15-3.1 место 1
#define R0DE35LRP	 BUFFER[60]	//(R0DE35LRP) диагностика шкафа РПУ температура больше 53
#define idR0DE35LRP	 30	//(R0DE35LRP) диагностика шкафа РПУ температура больше 53
#define R0DE34LRP	 BUFFER[62]	//(R0DE34LRP) диагностика шкафа РПУ температура меньше 43
#define idR0DE34LRP	 31	//(R0DE34LRP) диагностика шкафа РПУ температура меньше 43
#define R0DE33LRP	 BUFFER[64]	//(R0DE33LRP) диагностика шкафа РПУ двери
#define idR0DE33LRP	 32	//(R0DE33LRP) диагностика шкафа РПУ двери
#define R0DE32LRP	 BUFFER[66]	//(R0DE32LRP) диагностика шкафа РПУ сеть 2
#define idR0DE32LRP	 33	//(R0DE32LRP) диагностика шкафа РПУ сеть 2
#define R0DE31LRP	 BUFFER[68]	//(R0DE31LRP) диагностика шкафа РПУ сеть 1
#define idR0DE31LRP	 34	//(R0DE31LRP) диагностика шкафа РПУ сеть 1
#define R0DE07LRP	 BUFFER[70]	//(R0DE07LRP) диагностика модуля РПУ-ВДС место 7
#define idR0DE07LRP	 35	//(R0DE07LRP) диагностика модуля РПУ-ВДС место 7
#define R0DE08LRP	 BUFFER[73]	//(R0DE08LRP) диагностика модуля РПУ-ФДС место 8
#define idR0DE08LRP	 36	//(R0DE08LRP) диагностика модуля РПУ-ФДС место 8
#define R0DE06LRP	 BUFFER[76]	//(R0DE06LRP) диагностика модуля РПУ-ВАС место 6
#define idR0DE06LRP	 37	//(R0DE06LRP) диагностика модуля РПУ-ВАС место 6
#define R0DE03LRP	 BUFFER[79]	//(R0DE03LRP) диагностика модуля РПУ-ВЧС место 3
#define idR0DE03LRP	 38	//(R0DE03LRP) диагностика модуля РПУ-ВЧС место 3
#define R0DE02LRP	 BUFFER[82]	//(R0DE02LRP) диагностика модуля РПУ-ВЧС место 2
#define idR0DE02LRP	 39	//(R0DE02LRP) диагностика модуля РПУ-ВЧС место 2
#define A0VT71LRP	 BUFFER[85]	//(A0VT71LRP) АС по температуре в АЗ1
#define idA0VT71LRP	 40	//(A0VT71LRP) АС по температуре в АЗ1
#define A0VT61LRP	 BUFFER[87]	//(A0VT61LRP) ПС по температуре в АЗ1
#define idA0VT61LRP	 41	//(A0VT61LRP) ПС по температуре в АЗ1
#define A0CT01IRP	 BUFFER[89]	//(A0CT01IRP) Температура АЗ1-3
#define idA0CT01IRP	 42	//(A0CT01IRP) Температура АЗ1-3
#define A0IT03IRP	 BUFFER[94]	//(A0IT03IRP) Температура АЗ1-3
#define idA0IT03IRP	 43	//(A0IT03IRP) Температура АЗ1-3
#define R0IN07RRP	 BUFFER[97]	//(R0IN07RRP) Частота СНМ-11 Гц (канал 7)
#define idR0IN07RRP	 44	//(R0IN07RRP) Частота СНМ-11 Гц (канал 7)
#define R7VN71LRP	 BUFFER[102]	//(R7VN71LRP) Сигнал тревоги по уровню нейтронного потока на диспетчера
#define idR7VN71LRP	 45	//(R7VN71LRP) Сигнал тревоги по уровню нейтронного потока на диспетчера
#define R0IN06RRP	 BUFFER[104]	//(R0IN06RRP) Частота СНМ-11 Гц (канал 6)
#define idR0IN06RRP	 46	//(R0IN06RRP) Частота СНМ-11 Гц (канал 6)
#define R0IE02LRP	 BUFFER[109]	//(R0IE02LRP) Отключить питание ПР, ПУ канал 5
#define idR0IE02LRP	 47	//(R0IE02LRP) Отключить питание ПР, ПУ канал 5
#define R0IE01LRP	 BUFFER[111]	//(R0IE01LRP) Отключение питание детекторов канал 5
#define idR0IE01LRP	 48	//(R0IE01LRP) Отключение питание детекторов канал 5
#define R0VN15RRP	 BUFFER[113]	//(R0VN15RRP) Номер ведущей камеры канал 5
#define idR0VN15RRP	 49	//(R0VN15RRP) Номер ведущей камеры канал 5
#define R0VN33RRP	 BUFFER[116]	//(R0VN33RRP) Нейтронный поток по камере КНК53М канал 5
#define idR0VN33RRP	 50	//(R0VN33RRP) Нейтронный поток по камере КНК53М канал 5
#define R0VN23RRP	 BUFFER[121]	//(R0VN23RRP) Нейтронный поток по камере КНК15-1 канал 5
#define idR0VN23RRP	 51	//(R0VN23RRP) Нейтронный поток по камере КНК15-1 канал 5
#define A0EE02LRP	 BUFFER[126]	//(A0EE02LRP) Исправность АКНП5 (от сшивки каналов) канал 5
#define idA0EE02LRP	 52	//(A0EE02LRP) Исправность АКНП5 (от сшивки каналов) канал 5
#define R0IN03RRP	 BUFFER[128]	//(R0IN03RRP) Частота КНК53М Гц (канал 5)
#define idR0IN03RRP	 53	//(R0IN03RRP) Частота КНК53М Гц (канал 5)
#define B8VC01RDU	 BUFFER[133]	//(B8VC01RDU) Координата АЗ2, мм
#define idB8VC01RDU	 54	//(B8VC01RDU) Координата АЗ2, мм
#define R0VN03RRP	 BUFFER[138]	//(R0VN03RRP) Измеренный нейтронный поток канал 5
#define idR0VN03RRP	 55	//(R0VN03RRP) Измеренный нейтронный поток канал 5
#define R0IN02RRP	 BUFFER[143]	//(R0IN02RRP) Частота КНК15-1 Гц (канал 5)
#define idR0IN02RRP	 56	//(R0IN02RRP) Частота КНК15-1 Гц (канал 5)
#define R0IN01RRP	 BUFFER[148]	//(R0IN01RRP) Частота СНМ-11 Гц (канал 5)
#define idR0IN01RRP	 57	//(R0IN01RRP) Частота СНМ-11 Гц (канал 5)
#define R0VN02RRP	 BUFFER[153]	//(R0VN02RRP) Уровень мощности канал 5
#define idR0VN02RRP	 58	//(R0VN02RRP) Уровень мощности канал 5
#define B6IS11LRP	 BUFFER[158]	//(B6IS11LRP) Приход на ВУ БЗ2
#define idB6IS11LRP	 59	//(B6IS11LRP) Приход на ВУ БЗ2
#define A6IS11LRP	 BUFFER[160]	//(A6IS11LRP) Приход на ВУ БЗ1
#define idA6IS11LRP	 60	//(A6IS11LRP) Приход на ВУ БЗ1
#define R0VN13RRP	 BUFFER[162]	//(R0VN13RRP) Нейтронный поток по камере  СНМ-11 канал 5
#define idR0VN13RRP	 61	//(R0VN13RRP) Нейтронный поток по камере  СНМ-11 канал 5
#define R0VN71LRP	 BUFFER[167]	//(R0VN71LRP) АС по мощности канал 5
#define idR0VN71LRP	 62	//(R0VN71LRP) АС по мощности канал 5
#define A1VT71LRP	 BUFFER[169]	//(A1VT71LRP) АС по температуре
#define idA1VT71LRP	 63	//(A1VT71LRP) АС по температуре
#define R0IE04LRP	 BUFFER[171]	//(R0IE04LRP) Отключить питание ПР, ПУ канал 6,7
#define idR0IE04LRP	 64	//(R0IE04LRP) Отключить питание ПР, ПУ канал 6,7
#define R0IE03LRP	 BUFFER[173]	//(R0IE03LRP) Отключение питание детекторов канал  6,7
#define idR0IE03LRP	 65	//(R0IE03LRP) Отключение питание детекторов канал  6,7
#define R0IE15LRP	 BUFFER[175]	//(R0IE15LRP) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
#define idR0IE15LRP	 66	//(R0IE15LRP) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
#define R0IE14LRP	 BUFFER[177]	//(R0IE14LRP) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
#define idR0IE14LRP	 67	//(R0IE14LRP) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
#define R0IE13LRP	 BUFFER[179]	//(R0IE13LRP) Исправность ВИП 0,5 -5к (№22)
#define idR0IE13LRP	 68	//(R0IE13LRP) Исправность ВИП 0,5 -5к (№22)
#define R0IE12LRP	 BUFFER[181]	//(R0IE12LRP) Исправность ВИП 0,5 -5к (№21)
#define idR0IE12LRP	 69	//(R0IE12LRP) Исправность ВИП 0,5 -5к (№21)
#define A0EE01LRP	 BUFFER[183]	//(A0EE01LRP) Исправность АКНП канал 5
#define idA0EE01LRP	 70	//(A0EE01LRP) Исправность АКНП канал 5
#define A0EE03LRP	 BUFFER[185]	//(A0EE03LRP) Неисправность от диагностики контроллера
#define idA0EE03LRP	 71	//(A0EE03LRP) Неисправность от диагностики контроллера
#define R0IE11LRP	 BUFFER[187]	//(R0IE11LRP) Исправность ВИП 1,6 (№20) СНМ11 5 канала
#define idR0IE11LRP	 72	//(R0IE11LRP) Исправность ВИП 1,6 (№20) СНМ11 5 канала
#define B0VT71LRP	 BUFFER[189]	//(B0VT71LRP) АС по температуре в АЗ2-3
#define idB0VT71LRP	 73	//(B0VT71LRP) АС по температуре в АЗ2-3
#define B0VT61LRP	 BUFFER[191]	//(B0VT61LRP) ПС по температуре в АЗ2-3
#define idB0VT61LRP	 74	//(B0VT61LRP) ПС по температуре в АЗ2-3
#define B0CT01IRP	 BUFFER[193]	//(B0CT01IRP) Температура АЗ2-3
#define idB0CT01IRP	 75	//(B0CT01IRP) Температура АЗ2-3
#define R0ET02LRP	 BUFFER[198]	//(R0ET02LRP) Признак наличия неисправности по температуре АЗ2-3
#define idR0ET02LRP	 76	//(R0ET02LRP) Признак наличия неисправности по температуре АЗ2-3
#define B0IT03IRP	 BUFFER[200]	//(B0IT03IRP) Температура АЗ2-3
#define idB0IT03IRP	 77	//(B0IT03IRP) Температура АЗ2-3
#define R0ET01LRP	 BUFFER[203]	//(R0ET01LRP) Признак наличия неисправности по температуре  АЗ1-3
#define idR0ET01LRP	 78	//(R0ET01LRP) Признак наличия неисправности по температуре  АЗ1-3
#define fEM_R0UH02RSS	 BUFFER[205]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define idfEM_R0UH02RSS	 79	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define fEM_R0UH03RSS	 BUFFER[210]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define idfEM_R0UH03RSS	 80	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define fEM_R7UX00RSS	 BUFFER[215]	//(R7UX00RSS) X-координата АЗ1 (см)
#define idfEM_R7UX00RSS	 81	//(R7UX00RSS) X-координата АЗ1 (см)
#define fEM_R7UY00RSS	 BUFFER[220]	//(R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	 82	//(R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UX13RSS	 BUFFER[225]	//(R7UX13RSS) X-координата камеры R7IN51
#define idfEM_R7UX13RSS	 83	//(R7UX13RSS) X-координата камеры R7IN51
#define fEM_R7UX14RSS	 BUFFER[230]	//(R7UX14RSS) X-координата камеры R7IN52
#define idfEM_R7UX14RSS	 84	//(R7UX14RSS) X-координата камеры R7IN52
#define fEM_R7UX15RSS	 BUFFER[235]	//(R7UX15RSS) X-координата камеры R7IN53
#define idfEM_R7UX15RSS	 85	//(R7UX15RSS) X-координата камеры R7IN53
#define fEM_R7UY13RSS	 BUFFER[240]	//(R7UY13RSS) Y-координата камеры R7IN51
#define idfEM_R7UY13RSS	 86	//(R7UY13RSS) Y-координата камеры R7IN51
#define fEM_R7UY14RSS	 BUFFER[245]	//(R7UY14RSS) Y-координата камеры R7IN52
#define idfEM_R7UY14RSS	 87	//(R7UY14RSS) Y-координата камеры R7IN52
#define fEM_R7UY15RSS	 BUFFER[250]	//(R7UY15RSS) Y-координата камеры R7IN53
#define idfEM_R7UY15RSS	 88	//(R7UY15RSS) Y-координата камеры R7IN53
#define fEM_A0UX00RSS	 BUFFER[255]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 89	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX13RSS	 BUFFER[260]	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define idfEM_A0UX13RSS	 90	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define fEM_A0UX14RSS	 BUFFER[265]	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define idfEM_A0UX14RSS	 91	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define fEM_A0UX15RSS	 BUFFER[270]	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define idfEM_A0UX15RSS	 92	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define fEM_B0UX03RSS	 BUFFER[275]	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	 93	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	 BUFFER[280]	//(B0UX04RSS) Второй коэффициент калибровки камеры4
#define idfEM_B0UX04RSS	 94	//(B0UX04RSS) Второй коэффициент калибровки камеры4
#define fEM_B0UX05RSS	 BUFFER[285]	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	 95	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_R0UH05RSS	 BUFFER[290]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 96	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UR01RRP	 BUFFER[295]	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
#define idfEM_R0UR01RRP	 97	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
#define fEM_R0UT02RZZ	 BUFFER[300]	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	 98	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RZZ	 BUFFER[305]	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	 99	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_R0UT72RZZ	 BUFFER[310]	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	 100	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	 BUFFER[315]	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	 101	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	 BUFFER[320]	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	 102	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT61RZZ	 BUFFER[325]	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	 103	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_R0UL52RSS	 BUFFER[330]	//(R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	 104	//(R0UL52RSS) Уровень АС по мощности
#define fEM_Z7UE20RRP	 BUFFER[335]	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
#define idfEM_Z7UE20RRP	 105	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
#define bFirstEnterFlag	 BUFFER[340]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 106	//(bFirstEnterFlag) 
#define internal1_m16_Nk	 BUFFER[342]	//(internal1_m16_Nk) Nk - ведущая камера
#define idinternal1_m16_Nk	 107	//(internal1_m16_Nk) Nk - ведущая камера
#define internal1_m61_tx	 BUFFER[345]	//(internal1_m61_tx) tx - время накопленное сек
#define idinternal1_m61_tx	 108	//(internal1_m61_tx) tx - время накопленное сек
#define internal1_m61_y0	 BUFFER[350]	//(internal1_m61_y0) y0
#define idinternal1_m61_y0	 109	//(internal1_m61_y0) y0
#define internal1_m70_tx	 BUFFER[351]	//(internal1_m70_tx) tx - время накопленное сек
#define idinternal1_m70_tx	 110	//(internal1_m70_tx) tx - время накопленное сек
#define internal1_m70_y0	 BUFFER[356]	//(internal1_m70_y0) y0
#define idinternal1_m70_y0	 111	//(internal1_m70_y0) y0
#define internal1_m78_y0	 BUFFER[357]	//(internal1_m78_y0) y0
#define idinternal1_m78_y0	 112	//(internal1_m78_y0) y0
#define internal1_m76_y0	 BUFFER[362]	//(internal1_m76_y0) y0
#define idinternal1_m76_y0	 113	//(internal1_m76_y0) y0
#define internal1_m90_y1	 BUFFER[367]	//(internal1_m90_y1) y1 - внутренний параметр
#define idinternal1_m90_y1	 114	//(internal1_m90_y1) y1 - внутренний параметр
#define internal1_m101_y1	 BUFFER[369]	//(internal1_m101_y1) y1 - внутренний параметр
#define idinternal1_m101_y1	 115	//(internal1_m101_y1) y1 - внутренний параметр
#define internal1_m88_y1	 BUFFER[371]	//(internal1_m88_y1) y1 - внутренний параметр
#define idinternal1_m88_y1	 116	//(internal1_m88_y1) y1 - внутренний параметр
#define internal1_m99_y1	 BUFFER[373]	//(internal1_m99_y1) y1 - внутренний параметр
#define idinternal1_m99_y1	 117	//(internal1_m99_y1) y1 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,3	,1	, &R0DE01LRP},	//(R0DE01LRP) диагностика модуля РПУ-ВЧС место 1
	{ 2	,1	,1	, &R0EE02LDU},	//(R0EE02LDU) Питание  АКНП  отключить
	{ 3	,1	,1	, &B7MZ31LRP},	//(B7MZ31LRP) Клапан ОБДУВ АЗ2 открыть(обесточить)
	{ 4	,1	,1	, &A7MZ31LRP},	//(A7MZ31LRP) Клапан ОБДУВ АЗ1 открыть(обесточить)
	{ 5	,1	,1	, &C1MZ31LRP},	//(C1MZ31LRP) Кнопка ОБДУВ  на РПУ
	{ 6	,1	,1	, &C1MD31LRP},	//(C1MD31LRP) Кнопка ОБЩИЙ СБРОС  на РПУ
	{ 7	,1	,1	, &B3VS21LRP},	//(B3VS21LRP) Индикация - Приход на НУ ИС2
	{ 8	,1	,1	, &A3VS21LRP},	//(A3VS21LRP) Индикация - Приход на НУ ИС1
	{ 9	,1	,1	, &B2VS21LRP},	//(B2VS21LRP) Индикация - Приход на НУ РБ2-CC
	{ 10	,1	,1	, &A2VS21LRP},	//(A2VS21LRP) Индикация - Приход на НУ РБ1-CC
	{ 11	,1	,1	, &B1VS21LRP},	//(B1VS21LRP) Индикация - Приход на НУ ББ2
	{ 12	,1	,1	, &A1VS21LRP},	//(A1VS21LRP) Индикация - Приход на НУ ББ1
	{ 13	,1	,1	, &B2IS21LRP},	//(B2IS21LRP) Приход на НУ РБ2-CC
	{ 14	,1	,1	, &A2IS21LRP},	//(A2IS21LRP) Приход на НУ РБ1-CC
	{ 15	,1	,1	, &B1IS21LRP},	//(B1IS21LRP) Приход на НУ ББ2
	{ 16	,1	,1	, &A1IS21LRP},	//(A1IS21LRP) Приход на НУ ББ1
	{ 17	,1	,1	, &B3IS21LRP},	//(B3IS21LRP) Приход на НУ ИС2
	{ 18	,1	,1	, &A3IS21LRP},	//(A3IS21LRP) Приход на НУ ИС1
	{ 19	,1	,1	, &R7VE70LRP},	//(R7VE70LRP) Сигнал тревоги по неисправности РПУ на диспетчера
	{ 20	,3	,1	, &ttl},	//(ttl) ttl
	{ 21	,1	,1	, &TestDiagn},	//(TestDiagn) Неисправность от диагностики
	{ 22	,1	,1	, &R0DE3DLRP},	//(R0DE3DLRP) диагностика шкафа РПУ БП5/24Д место 8
	{ 23	,1	,1	, &R0DE3CLRP},	//(R0DE3CLRP) диагностика шкафа РПУ БП5/24Д место 7
	{ 24	,1	,1	, &R0DE3BLRP},	//(R0DE3BLRP) диагностика шкафа РПУ БП5/24Д место 6
	{ 25	,1	,1	, &R0DE3ALRP},	//(R0DE3ALRP) диагностика шкафа РПУ БП5/24Д место 5
	{ 26	,1	,1	, &R0DE39LRP},	//(R0DE39LRP) диагностика шкафа РПУ МП24-2 место 4
	{ 27	,1	,1	, &R0DE38LRP},	//(R0DE38LRP) диагностика шкафа РПУ МП15-3 место 3
	{ 28	,1	,1	, &R0DE37LRP},	//(R0DE37LRP) диагностика шкафа РПУ МП15-3.1 место 2
	{ 29	,1	,1	, &R0DE36LRP},	//(R0DE36LRP) диагностика шкафа РПУ МП15-3.1 место 1
	{ 30	,1	,1	, &R0DE35LRP},	//(R0DE35LRP) диагностика шкафа РПУ температура больше 53
	{ 31	,1	,1	, &R0DE34LRP},	//(R0DE34LRP) диагностика шкафа РПУ температура меньше 43
	{ 32	,1	,1	, &R0DE33LRP},	//(R0DE33LRP) диагностика шкафа РПУ двери
	{ 33	,1	,1	, &R0DE32LRP},	//(R0DE32LRP) диагностика шкафа РПУ сеть 2
	{ 34	,1	,1	, &R0DE31LRP},	//(R0DE31LRP) диагностика шкафа РПУ сеть 1
	{ 35	,3	,1	, &R0DE07LRP},	//(R0DE07LRP) диагностика модуля РПУ-ВДС место 7
	{ 36	,3	,1	, &R0DE08LRP},	//(R0DE08LRP) диагностика модуля РПУ-ФДС место 8
	{ 37	,3	,1	, &R0DE06LRP},	//(R0DE06LRP) диагностика модуля РПУ-ВАС место 6
	{ 38	,3	,1	, &R0DE03LRP},	//(R0DE03LRP) диагностика модуля РПУ-ВЧС место 3
	{ 39	,3	,1	, &R0DE02LRP},	//(R0DE02LRP) диагностика модуля РПУ-ВЧС место 2
	{ 40	,1	,1	, &A0VT71LRP},	//(A0VT71LRP) АС по температуре в АЗ1
	{ 41	,1	,1	, &A0VT61LRP},	//(A0VT61LRP) ПС по температуре в АЗ1
	{ 42	,8	,1	, &A0CT01IRP},	//(A0CT01IRP) Температура АЗ1-3
	{ 43	,3	,1	, &A0IT03IRP},	//(A0IT03IRP) Температура АЗ1-3
	{ 44	,8	,1	, &R0IN07RRP},	//(R0IN07RRP) Частота СНМ-11 Гц (канал 7)
	{ 45	,1	,1	, &R7VN71LRP},	//(R7VN71LRP) Сигнал тревоги по уровню нейтронного потока на диспетчера
	{ 46	,8	,1	, &R0IN06RRP},	//(R0IN06RRP) Частота СНМ-11 Гц (канал 6)
	{ 47	,1	,1	, &R0IE02LRP},	//(R0IE02LRP) Отключить питание ПР, ПУ канал 5
	{ 48	,1	,1	, &R0IE01LRP},	//(R0IE01LRP) Отключение питание детекторов канал 5
	{ 49	,3	,1	, &R0VN15RRP},	//(R0VN15RRP) Номер ведущей камеры канал 5
	{ 50	,8	,1	, &R0VN33RRP},	//(R0VN33RRP) Нейтронный поток по камере КНК53М канал 5
	{ 51	,8	,1	, &R0VN23RRP},	//(R0VN23RRP) Нейтронный поток по камере КНК15-1 канал 5
	{ 52	,1	,1	, &A0EE02LRP},	//(A0EE02LRP) Исправность АКНП5 (от сшивки каналов) канал 5
	{ 53	,8	,1	, &R0IN03RRP},	//(R0IN03RRP) Частота КНК53М Гц (канал 5)
	{ 54	,8	,1	, &B8VC01RDU},	//(B8VC01RDU) Координата АЗ2, мм
	{ 55	,8	,1	, &R0VN03RRP},	//(R0VN03RRP) Измеренный нейтронный поток канал 5
	{ 56	,8	,1	, &R0IN02RRP},	//(R0IN02RRP) Частота КНК15-1 Гц (канал 5)
	{ 57	,8	,1	, &R0IN01RRP},	//(R0IN01RRP) Частота СНМ-11 Гц (канал 5)
	{ 58	,8	,1	, &R0VN02RRP},	//(R0VN02RRP) Уровень мощности канал 5
	{ 59	,1	,1	, &B6IS11LRP},	//(B6IS11LRP) Приход на ВУ БЗ2
	{ 60	,1	,1	, &A6IS11LRP},	//(A6IS11LRP) Приход на ВУ БЗ1
	{ 61	,8	,1	, &R0VN13RRP},	//(R0VN13RRP) Нейтронный поток по камере  СНМ-11 канал 5
	{ 62	,1	,1	, &R0VN71LRP},	//(R0VN71LRP) АС по мощности канал 5
	{ 63	,1	,1	, &A1VT71LRP},	//(A1VT71LRP) АС по температуре
	{ 64	,1	,1	, &R0IE04LRP},	//(R0IE04LRP) Отключить питание ПР, ПУ канал 6,7
	{ 65	,1	,1	, &R0IE03LRP},	//(R0IE03LRP) Отключение питание детекторов канал  6,7
	{ 66	,1	,1	, &R0IE15LRP},	//(R0IE15LRP) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
	{ 67	,1	,1	, &R0IE14LRP},	//(R0IE14LRP) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
	{ 68	,1	,1	, &R0IE13LRP},	//(R0IE13LRP) Исправность ВИП 0,5 -5к (№22)
	{ 69	,1	,1	, &R0IE12LRP},	//(R0IE12LRP) Исправность ВИП 0,5 -5к (№21)
	{ 70	,1	,1	, &A0EE01LRP},	//(A0EE01LRP) Исправность АКНП канал 5
	{ 71	,1	,1	, &A0EE03LRP},	//(A0EE03LRP) Неисправность от диагностики контроллера
	{ 72	,1	,1	, &R0IE11LRP},	//(R0IE11LRP) Исправность ВИП 1,6 (№20) СНМ11 5 канала
	{ 73	,1	,1	, &B0VT71LRP},	//(B0VT71LRP) АС по температуре в АЗ2-3
	{ 74	,1	,1	, &B0VT61LRP},	//(B0VT61LRP) ПС по температуре в АЗ2-3
	{ 75	,8	,1	, &B0CT01IRP},	//(B0CT01IRP) Температура АЗ2-3
	{ 76	,1	,1	, &R0ET02LRP},	//(R0ET02LRP) Признак наличия неисправности по температуре АЗ2-3
	{ 77	,3	,1	, &B0IT03IRP},	//(B0IT03IRP) Температура АЗ2-3
	{ 78	,1	,1	, &R0ET01LRP},	//(R0ET01LRP) Признак наличия неисправности по температуре  АЗ1-3
	{ 79	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{ 80	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{ 81	,8	,1	, &fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{ 82	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{ 83	,8	,1	, &fEM_R7UX13RSS},	//(R7UX13RSS) X-координата камеры R7IN51
	{ 84	,8	,1	, &fEM_R7UX14RSS},	//(R7UX14RSS) X-координата камеры R7IN52
	{ 85	,8	,1	, &fEM_R7UX15RSS},	//(R7UX15RSS) X-координата камеры R7IN53
	{ 86	,8	,1	, &fEM_R7UY13RSS},	//(R7UY13RSS) Y-координата камеры R7IN51
	{ 87	,8	,1	, &fEM_R7UY14RSS},	//(R7UY14RSS) Y-координата камеры R7IN52
	{ 88	,8	,1	, &fEM_R7UY15RSS},	//(R7UY15RSS) Y-координата камеры R7IN53
	{ 89	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 90	,8	,1	, &fEM_A0UX13RSS},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{ 91	,8	,1	, &fEM_A0UX14RSS},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{ 92	,8	,1	, &fEM_A0UX15RSS},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{ 93	,8	,1	, &fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{ 94	,8	,1	, &fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры4
	{ 95	,8	,1	, &fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{ 96	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 97	,8	,1	, &fEM_R0UR01RRP},	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
	{ 98	,8	,1	, &fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{ 99	,8	,1	, &fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{ 100	,8	,1	, &fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{ 101	,8	,1	, &fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{ 102	,8	,1	, &fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{ 103	,8	,1	, &fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{ 104	,8	,1	, &fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{ 105	,8	,1	, &fEM_Z7UE20RRP},	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
	{ 106	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 107	,3	,1	, &internal1_m16_Nk},	//(internal1_m16_Nk) Nk - ведущая камера
	{ 108	,8	,1	, &internal1_m61_tx},	//(internal1_m61_tx) tx - время накопленное сек
	{ 109	,18	,1	, &internal1_m61_y0},	//(internal1_m61_y0) y0
	{ 110	,8	,1	, &internal1_m70_tx},	//(internal1_m70_tx) tx - время накопленное сек
	{ 111	,18	,1	, &internal1_m70_y0},	//(internal1_m70_y0) y0
	{ 112	,8	,1	, &internal1_m78_y0},	//(internal1_m78_y0) y0
	{ 113	,8	,1	, &internal1_m76_y0},	//(internal1_m76_y0) y0
	{ 114	,1	,1	, &internal1_m90_y1},	//(internal1_m90_y1) y1 - внутренний параметр
	{ 115	,1	,1	, &internal1_m101_y1},	//(internal1_m101_y1) y1 - внутренний параметр
	{ 116	,1	,1	, &internal1_m88_y1},	//(internal1_m88_y1) y1 - внутренний параметр
	{ 117	,1	,1	, &internal1_m99_y1},	//(internal1_m99_y1) y1 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="rpu.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{79,"fEM_R0UH02RSS\0"}, 
{80,"fEM_R0UH03RSS\0"}, 
{81,"fEM_R7UX00RSS\0"}, 
{82,"fEM_R7UY00RSS\0"}, 
{83,"fEM_R7UX13RSS\0"}, 
{84,"fEM_R7UX14RSS\0"}, 
{85,"fEM_R7UX15RSS\0"}, 
{86,"fEM_R7UY13RSS\0"}, 
{87,"fEM_R7UY14RSS\0"}, 
{88,"fEM_R7UY15RSS\0"}, 
{89,"fEM_A0UX00RSS\0"}, 
{90,"fEM_A0UX13RSS\0"}, 
{91,"fEM_A0UX14RSS\0"}, 
{92,"fEM_A0UX15RSS\0"}, 
{93,"fEM_B0UX03RSS\0"}, 
{94,"fEM_B0UX04RSS\0"}, 
{95,"fEM_B0UX05RSS\0"}, 
{96,"fEM_R0UH05RSS\0"}, 
{97,"fEM_R0UR01RRP\0"}, 
{98,"fEM_R0UT02RZZ\0"}, 
{99,"fEM_R0UT01RZZ\0"}, 
{100,"fEM_R0UT72RZZ\0"}, 
{101,"fEM_R0UT71RZZ\0"}, 
{102,"fEM_R0UT62RZZ\0"}, 
{103,"fEM_R0UT61RZZ\0"}, 
{104,"fEM_R0UL52RSS\0"}, 
{105,"fEM_Z7UE20RRP\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_RPU[]={  // 
	{&R0EE02LDU,1,0},	//(R0EE02LDU) Питание  АКНП  отключить
	{&A0EE03LRP,1,1},	//(A0EE03LRP) Неисправность от диагностики контроллера
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_RPU[]={  // 
	{&TestDiagn,1,0},	//(TestDiagn) Неисправность от диагностики
	{&B7MZ31LRP,1,1},	//(B7MZ31LRP) Клапан ОБДУВ АЗ2 открыть(обесточить)
	{&A7MZ31LRP,1,2},	//(A7MZ31LRP) Клапан ОБДУВ АЗ1 открыть(обесточить)
	{&R7VE70LRP,1,3},	//(R7VE70LRP) Сигнал тревоги по неисправности РПУ на диспетчера
	{&A0EE01LRP,1,4},	//(A0EE01LRP) Исправность АКНП канал 5
	{&B0VT71LRP,1,5},	//(B0VT71LRP) АС по температуре в АЗ2-3
	{&B0VT61LRP,1,6},	//(B0VT61LRP) ПС по температуре в АЗ2-3
	{&R0ET02LRP,1,7},	//(R0ET02LRP) Признак наличия неисправности по температуре АЗ2-3
	{&R0ET01LRP,1,8},	//(R0ET01LRP) Признак наличия неисправности по температуре  АЗ1-3
	{&A0VT71LRP,1,9},	//(A0VT71LRP) АС по температуре в АЗ1
	{&A0VT61LRP,1,10},	//(A0VT61LRP) ПС по температуре в АЗ1
	{&R7VN71LRP,1,11},	//(R7VN71LRP) Сигнал тревоги по уровню нейтронного потока на диспетчера
	{&A0EE02LRP,1,12},	//(A0EE02LRP) Исправность АКНП5 (от сшивки каналов) канал 5
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_RPU[]={  // 
	{&ttl,3,0},	//(ttl) ttl
	{&R0VN13RRP,8,1},	//(R0VN13RRP) Нейтронный поток по камере  СНМ-11 канал 5
	{&B0CT01IRP,8,3},	//(B0CT01IRP) Температура АЗ2-3
	{&A0CT01IRP,8,5},	//(A0CT01IRP) Температура АЗ1-3
	{&R0IN07RRP,8,7},	//(R0IN07RRP) Частота СНМ-11 Гц (канал 7)
	{&R0IN06RRP,8,9},	//(R0IN06RRP) Частота СНМ-11 Гц (канал 6)
	{&R0VN15RRP,3,11},	//(R0VN15RRP) Номер ведущей камеры канал 5
	{&R0VN33RRP,8,12},	//(R0VN33RRP) Нейтронный поток по камере КНК53М канал 5
	{&R0VN23RRP,8,14},	//(R0VN23RRP) Нейтронный поток по камере КНК15-1 канал 5
	{&R0IN03RRP,8,16},	//(R0IN03RRP) Частота КНК53М Гц (канал 5)
	{&B8VC01RDU,8,18},	//(B8VC01RDU) Координата АЗ2, мм
	{&R0VN03RRP,8,20},	//(R0VN03RRP) Измеренный нейтронный поток канал 5
	{&R0IN02RRP,8,22},	//(R0IN02RRP) Частота КНК15-1 Гц (канал 5)
	{&R0IN01RRP,8,24},	//(R0IN01RRP) Частота СНМ-11 Гц (канал 5)
	{&R0VN02RRP,8,26},	//(R0VN02RRP) Уровень мощности канал 5
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_RPU[]={  // 
	{&fEM_R0UH02RSS,8,0},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{&fEM_R0UH03RSS,8,2},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{&fEM_R7UX00RSS,8,4},	//(R7UX00RSS) X-координата АЗ1 (см)
	{&fEM_R7UY00RSS,8,6},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{&fEM_R7UX13RSS,8,8},	//(R7UX13RSS) X-координата камеры R7IN51
	{&fEM_R7UX14RSS,8,10},	//(R7UX14RSS) X-координата камеры R7IN52
	{&fEM_R7UX15RSS,8,12},	//(R7UX15RSS) X-координата камеры R7IN53
	{&fEM_R7UY13RSS,8,14},	//(R7UY13RSS) Y-координата камеры R7IN51
	{&fEM_R7UY14RSS,8,16},	//(R7UY14RSS) Y-координата камеры R7IN52
	{&fEM_R7UY15RSS,8,18},	//(R7UY15RSS) Y-координата камеры R7IN53
	{&fEM_A0UX00RSS,8,20},	//(A0UX00RSS) Эффективный радиус АЗ
	{&fEM_A0UX13RSS,8,22},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{&fEM_A0UX14RSS,8,24},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{&fEM_A0UX15RSS,8,26},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{&fEM_B0UX03RSS,8,28},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{&fEM_B0UX04RSS,8,30},	//(B0UX04RSS) Второй коэффициент калибровки камеры4
	{&fEM_B0UX05RSS,8,32},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{&fEM_R0UH05RSS,8,34},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_R0UR01RRP,8,36},	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
	{&fEM_R0UT02RZZ,8,38},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{&fEM_R0UT01RZZ,8,40},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{&fEM_R0UT72RZZ,8,42},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{&fEM_R0UT71RZZ,8,44},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{&fEM_R0UT62RZZ,8,46},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{&fEM_R0UT61RZZ,8,48},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{&fEM_R0UL52RSS,8,50},	//(R0UL52RSS) Уровень АС по мощности
	{&fEM_Z7UE20RRP,8,52},	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
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
	{&R0DE38LRP,1,5},	//(R0DE38LRP) диагностика шкафа РПУ МП15-3 место 3
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
static char buf_VCHS01[58];	//VCHS01
static vchs_inipar ini_VCHS01={172,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,};
#pragma pack(push,1)
static table_drv table_VCHS01={0,0,&ini_VCHS01,buf_VCHS01,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS01[]={
	{&R0DE01LRP,3,10},
	{&R0IN01RRP,8,0},
	{&R0IN02RRP,8,5},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS02[58];	//VCHS02
static vchs_inipar ini_VCHS02={172,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,};
#pragma pack(push,1)
static table_drv table_VCHS02={0,0,&ini_VCHS02,buf_VCHS02,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS02[]={
	{&R0IN03RRP,8,0},
	{&R0DE02LRP,3,10},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS03[58];	//VCHS03
static vchs_inipar ini_VCHS03={172,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,};
#pragma pack(push,1)
static table_drv table_VCHS03={0,0,&ini_VCHS03,buf_VCHS03,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS03[]={
	{&R0DE03LRP,3,10},
	{&R0IN06RRP,8,0},
	{&R0IN07RRP,8,5},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vas84r.h>
static char buf_VAS84[28];	//VAS84
static vas84r_inipar ini_VAS84={172,255,1,8,0xff,0,16,};
#pragma pack(push,1)
static table_drv table_VAS84={0,0,&ini_VAS84,buf_VAS84,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VAS84[]={
	{&R0DE06LRP,3,26},
	{&A0IT03IRP,3,0},
	{&B0IT03IRP,3,3},
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
	{&R0DE07LRP,3,64},
	{&A3IS21LRP,1,14},
	{&B3IS21LRP,1,20},
	{&C1MZ31LRP,1,12},
	{&R0IE11LRP,1,4},
	{&C1MD31LRP,1,10},
	{&R0IE12LRP,1,6},
	{&R0IE13LRP,1,8},
	{&R0IE14LRP,1,0},
	{&R0IE15LRP,1,2},
	{&A1IS21LRP,1,16},
	{&B1IS21LRP,1,22},
	{&A2IS21LRP,1,18},
	{&B2IS21LRP,1,24},
	{&A6IS11LRP,1,26},
	{&B6IS11LRP,1,28},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS16[40];	//FDS16
static fds16r_inipar ini_FDS16={0x04,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS16={0,0,&ini_FDS16,buf_FDS16,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS16[]={
	{&A2VS21LRP,1,4},
	{&B1VS21LRP,1,2},
	{&B2VS21LRP,1,6},
	{&A1VS21LRP,1,0},
	{&A3VS21LRP,1,8},
	{&R0VN71LRP,1,22},
	{&A1VT71LRP,1,20},
	{&R0IE01LRP,1,14},
	{&R0IE02LRP,1,12},
	{&R0IE04LRP,1,18},
	{&R0IE03LRP,1,16},
	{&R0DE08LRP,3,38},
	{&B3VS21LRP,1,10},
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
	{&R0DE3DLRP,1,24},
	{&R0DE3ALRP,1,18},
	{&R0DE39LRP,1,16},
	{&R0DE38LRP,1,14},
	{&R0DE37LRP,1,12},
	{&R0DE36LRP,1,10},
	{&R0DE35LRP,1,8},
	{&R0DE34LRP,1,6},
	{&R0DE33LRP,1,4},
	{&R0DE32LRP,1,2},
	{&R0DE31LRP,1,0},
	{&R0DE3BLRP,1,20},
	{&R0DE3CLRP,1,22},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc4,0x01,12,58,def_buf_VCHS01,&table_VCHS01}, //VCHS01
	{0xc4,0x02,12,58,def_buf_VCHS02,&table_VCHS02}, //VCHS02
	{0xc4,0x03,12,58,def_buf_VCHS03,&table_VCHS03}, //VCHS03
	{0xc6,0x06,7,28,def_buf_VAS84,&table_VAS84}, //VAS84
	{0xc2,0x07,15,66,def_buf_VDS32,&table_VDS32}, //VDS32
	{0x04,0x08,20,40,def_buf_FDS16,&table_FDS16}, //FDS16
	{0x01,0x20,4,26,def_buf_SBKFP,&table_SBKFP}, //SBKFP
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
	setAsFloat(79,3703.704 );
	setAsFloat(80,62500.0);
	setAsFloat(81,1567.36);
	setAsFloat(82,506.5);
	setAsFloat(83,1570.0);
	setAsFloat(84,1269);
	setAsFloat(85,1281.2);
	setAsFloat(86,248.0);
	setAsFloat(87,572.4);
	setAsFloat(88,246.8);
	setAsFloat(89,11.0);
	setAsFloat(90,1.0);
	setAsFloat(91,1.0);
	setAsFloat(92,1.0);
	setAsFloat(93,0);
	setAsFloat(94,0);
	setAsFloat(95,0.0);
	setAsFloat(96,32000.0);
	setAsFloat(97,1000);
	setAsFloat(98,600);
	setAsFloat(99,0);
	setAsFloat(100,150);
	setAsFloat(101,200);
	setAsFloat(102,90);
	setAsFloat(103,100);
	setAsFloat(104,5100);
	setAsFloat(105,210);
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
ssint iRM_6_ = {6,0}; /* n - размерность массива значений */ 
ssint iRM_8_ = {8,0}; /* n - N-размерность массива x */ 

uspaint8 SpaEEPROMBuf[135];

/* Определение переменных */
ssbool var1;
ssbool var2;
ssbool var3;
ssbool var4;
ssint var5;
ssfloat var6;
ssfloat var7;
ssbool var8;
ssfloat var9;
ssfloat var10;
ssfloat var11;
ssint var12;
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
sschar var25;
ssbool var26;
sschar var27;
ssbool var28;
ssbool var29;
ssbool var30;
ssbool var31;
ssbool var32;
ssfloat var33;
ssfloat var34;
sschar var35;
ssbool var36;
ssbool var37;
sschar var38;
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
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m144_x_1[8] = {&R0DE36LRP,&R0DE39LRP,&R0DE3CLRP,&R0DE37LRP,&R0DE3DLRP,&R0DE38LRP,&R0DE3BLRP,&R0DE3ALRP};
psint  array_m134_x_1[6] = {&R0DE01LRP,&R0DE02LRP,&R0DE03LRP,&R0DE08LRP,&R0DE06LRP,&R0DE07LRP};

/* Объявление структур */
_S_or3  S_or3_137_1 = {&var4,&var3,&var2,&var1};
_S_orn  S_orn_144_1 = {array_m144_x_1,&iRM_8_,&var2};
_S_and2  S_and2_133_1 = {&R0DE31LRP,&R0DE32LRP,&var3};
_S_diagndev  S_diagndev_134_1 = {array_m134_x_1,&iRM_6_,&var4,&var5};
_S_ocham  S_ocham_16_1 = {&R0IN01RRP,&R0IN02RRP,&R0IN03RRP,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX13RSS,&fEM_B0UX03RSS,&fEM_A0UX14RSS,&fEM_B0UX04RSS,&fEM_A0UX15RSS,&fEM_B0UX05RSS,&fEM_R7UX13RSS,&fEM_R7UY13RSS,&fEM_R7UX14RSS,&fEM_R7UY14RSS,&fEM_R7UX15RSS,&fEM_R7UY15RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var6,&var7,&var8,&var9,&var10,&var11,&var12,&internal1_m16_Nk};
_S_or2  S_or2_57_1 = {&A6IS11LRP,&B6IS11LRP,&vainSBool};
_S_or5  S_or5_62_1 = {&var23,&var24,&A0EE03LRP,&var14,&var41,&var13};
_S_or2  S_or2_84_1 = {&var48,&var49,&var14};
_S_or4  S_or4_42_1 = {&var22,&var19,&var21,&var17,&var15};
_S_or2  S_or2_89_1 = {&var47,&var36,&var16};
_S_or2  S_or2_105_1 = {&var18,&var16,&var17};
_S_or2  S_or2_85_1 = {&var46,&var39,&var18};
_S_and3  S_and3_37_1 = {&var20,&var32,&var26,&var19};
_S_and4  S_and4_36_1 = {&R0IE11LRP,&var8,&R0IE12LRP,&R0IE13LRP,&var20};
_S_and3  S_and3_45_1 = {&var30,&R0IE14LRP,&var42,&var21};
_S_and3  S_and3_44_1 = {&R0IE15LRP,&var30,&var43,&var22};
_S_and3  S_and3_52_1 = {&R0IE14LRP,&var30,&var45,&var23};
_S_and3  S_and3_51_1 = {&var44,&R0IE15LRP,&var30,&var24};
_S_geterr  S_geterr_48_1 = {&R0IN06RRP,&dRM_0_,&iRM_0_,&bRM_0_,&var25,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_noto  S_noto_71_1 = {&var31,&var26};
_S_geterr  S_geterr_47_1 = {&R0IN07RRP,&dRM_0_,&iRM_0_,&bRM_0_,&var27,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_zzfs  S_zzfs_61_1 = {&var29,&fEM_Z7UE20RRP,&var28,&internal1_m61_tx,&internal1_m61_y0};
_S_or3  S_or3_60_1 = {&A6IS11LRP,&B6IS11LRP,&R0EE02LDU,&var29};
_S_noto  S_noto_58_1 = {&var28,&var30};
_S_zzfs  S_zzfs_70_1 = {&R0EE02LDU,&fEM_Z7UE20RRP,&var31,&internal1_m70_tx,&internal1_m70_y0};
_S_bol  S_bol_35_1 = {&var7,&fEM_R0UL52RSS,&var32};
_S_scalzz  S_scalzz_78_1 = {&B0IT03IRP,&iRM_819_,&iRM_4095_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var33,&internal1_m78_y0};
_S_scalzz  S_scalzz_76_1 = {&A0IT03IRP,&iRM_819_,&iRM_4095_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var34,&internal1_m76_y0};
_S_geterr  S_geterr_80_1 = {&var34,&dRM_0_,&iRM_0_,&bRM_0_,&var35,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_90_1 = {&var33,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var36,&internal1_m90_y1};
_S_drg  S_drg_101_1 = {&var33,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var37,&internal1_m101_y1};
_S_geterr  S_geterr_82_1 = {&var33,&dRM_0_,&iRM_0_,&bRM_0_,&var38,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_88_1 = {&var34,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var39,&internal1_m88_y1};
_S_drg  S_drg_99_1 = {&var34,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var40,&internal1_m99_y1};
_S_noto  S_noto_67_1 = {&var20,&var41};
_S_bol  S_bol_53_1 = {&R0IN07RRP,&fEM_R0UR01RRP,&var42};
_S_bol  S_bol_43_1 = {&R0IN06RRP,&fEM_R0UR01RRP,&var43};


void Scheme()
{
// if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
//   scalzz(&S_scalzz_76_1);
//   scalzz(&S_scalzz_78_1);
//   geterr(&S_geterr_47_1);
//   geterr(&S_geterr_48_1);
//   or2(&S_or2_57_1);
//   ocham(&S_ocham_16_1);
//   diagndev(&S_diagndev_134_1);
//   and2(&S_and2_133_1);
//   orn(&S_orn_144_1);
//   or3(&S_or3_137_1);
//   bol(&S_bol_43_1);
//   bol(&S_bol_53_1);
//   drg(&S_drg_99_1);
//   drg(&S_drg_88_1);
//   geterr(&S_geterr_82_1);
//   drg(&S_drg_101_1);
//   drg(&S_drg_90_1);
//   geterr(&S_geterr_80_1);
//   bol(&S_bol_35_1);
//   zzfs(&S_zzfs_70_1);
//   or3(&S_or3_60_1);
//   zzfs(&S_zzfs_61_1);
//   noto(&S_noto_71_1);
//   and4(&S_and4_36_1);
//   and3(&S_and3_37_1);
//   setData(&var46,&var35);
//   or2(&S_or2_85_1);
//   setData(&var47,&var38);
//   or2(&S_or2_89_1);
//   setData(&var48,&var35);
//   setData(&var49,&var38);
//   or2(&S_or2_84_1);
//   noto(&S_noto_67_1);
//   noto(&S_noto_58_1);
//   setData(&var44,&var27);
//   and3(&S_and3_51_1);
//   setData(&var45,&var25);
//   and3(&S_and3_52_1);
//   and3(&S_and3_44_1);
//   and3(&S_and3_45_1);
//   or2(&S_or2_105_1);
//   or4(&S_or4_42_1);
//   or5(&S_or5_62_1);
//   setData(idttl,&var5);
//   setData(idTestDiagn,&var1);
//   moveData(idB7MZ31LRP,idC1MZ31LRP);
//   moveData(idA7MZ31LRP,idC1MZ31LRP);
//   moveData(idB3VS21LRP,idB3IS21LRP);
//   moveData(idA3VS21LRP,idA3IS21LRP);
//   moveData(idB2VS21LRP,idB2IS21LRP);
//   moveData(idA2VS21LRP,idA2IS21LRP);
//   moveData(idB1VS21LRP,idB1IS21LRP);
//   moveData(idA1VS21LRP,idA1IS21LRP);
//   setData(idR7VE70LRP,&var13);
//   setData(idR0VN13RRP,&var9);
//   setData(idR0VN71LRP,&var32);
//   setData(idA1VT71LRP,&var17);
//   setData(idR0IE04LRP,&var28);
//   setData(idR0IE03LRP,&var28);
//   setData(idA0EE01LRP,&var20);
//   setData(idB0VT71LRP,&var16);
//   setData(idB0VT61LRP,&var37);
//   setData(idB0CT01IRP,&var33);
//   setData(idR0ET02LRP,&var38);
//   setData(idR0ET01LRP,&var35);
//   setData(idA0VT71LRP,&var18);
//   setData(idA0VT61LRP,&var40);
//   setData(idA0CT01IRP,&var34);
//   setData(idR7VN71LRP,&var15);
//   setData(idR0IE02LRP,&var31);
//   setData(idR0IE01LRP,&var31);
//   setData(idR0VN15RRP,&var12);
//   setData(idR0VN33RRP,&var11);
//   setData(idR0VN23RRP,&var10);
//   setData(idA0EE02LRP,&var8);
//   setData(idR0VN03RRP,&var6);
//   setData(idR0VN02RRP,&var7);

//   setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}

#endif
