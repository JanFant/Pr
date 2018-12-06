#ifndef RPU_H
#define RPU_H
// Подсистема RPU:RPU
static char SimulOn=0;
static short CodeSub=8;
static char SimulIP[]="192.168.1.17\0";
static int SimulPort=5555;
static int StepCycle=5;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 328
static char BUFFER[328];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.31\0", 5432, "192.168.10.131\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0IE12LRP	 BUFFER[0]	//(R0IE12LRP) Исправность ВИП 0,5 -5к (№21)
#define idR0IE12LRP	 1	//(R0IE12LRP) Исправность ВИП 0,5 -5к (№21)
#define R0IE13LRP	 BUFFER[2]	//(R0IE13LRP) Исправность ВИП 0,5 -5к (№22)
#define idR0IE13LRP	 2	//(R0IE13LRP) Исправность ВИП 0,5 -5к (№22)
#define R0IE14LRP	 BUFFER[4]	//(R0IE14LRP) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
#define idR0IE14LRP	 3	//(R0IE14LRP) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
#define R0IE15LRP	 BUFFER[6]	//(R0IE15LRP) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
#define idR0IE15LRP	 4	//(R0IE15LRP) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
#define R0IE03LRP	 BUFFER[8]	//(R0IE03LRP) Отключение питание детекторов канал  6,7
#define idR0IE03LRP	 5	//(R0IE03LRP) Отключение питание детекторов канал  6,7
#define R0IE04LRP	 BUFFER[10]	//(R0IE04LRP) Отключить питание ПР, ПУ канал 6,7
#define idR0IE04LRP	 6	//(R0IE04LRP) Отключить питание ПР, ПУ канал 6,7
#define A1VT71LRP	 BUFFER[12]	//(A1VT71LRP) АС по температуре
#define idA1VT71LRP	 7	//(A1VT71LRP) АС по температуре
#define R0VN71LRP	 BUFFER[14]	//(R0VN71LRP) АС по мощности канал 5
#define idR0VN71LRP	 8	//(R0VN71LRP) АС по мощности канал 5
#define R0VN13RRP	 BUFFER[16]	//(R0VN13RRP) Нейтронный поток по камере  СНМ-11 канал 5
#define idR0VN13RRP	 9	//(R0VN13RRP) Нейтронный поток по камере  СНМ-11 канал 5
#define A6IS11LRP	 BUFFER[21]	//(A6IS11LRP) Приход на ВУ БЗ1
#define idA6IS11LRP	 10	//(A6IS11LRP) Приход на ВУ БЗ1
#define B6IS11LRP	 BUFFER[23]	//(B6IS11LRP) Приход на ВУ БЗ2
#define idB6IS11LRP	 11	//(B6IS11LRP) Приход на ВУ БЗ2
#define R7VE70LRP	 BUFFER[25]	//(R7VE70LRP) Сигнал тревоги по неисправности РПУ на диспетчера
#define idR7VE70LRP	 12	//(R7VE70LRP) Сигнал тревоги по неисправности РПУ на диспетчера
#define A3IS21LRP	 BUFFER[27]	//(A3IS21LRP) Приход на НУ ИС1
#define idA3IS21LRP	 13	//(A3IS21LRP) Приход на НУ ИС1
#define B3IS21LRP	 BUFFER[29]	//(B3IS21LRP) Приход на НУ ИС2
#define idB3IS21LRP	 14	//(B3IS21LRP) Приход на НУ ИС2
#define A1IS21LRP	 BUFFER[31]	//(A1IS21LRP) Приход на НУ ББ1
#define idA1IS21LRP	 15	//(A1IS21LRP) Приход на НУ ББ1
#define B1IS21LRP	 BUFFER[33]	//(B1IS21LRP) Приход на НУ ББ2
#define idB1IS21LRP	 16	//(B1IS21LRP) Приход на НУ ББ2
#define A2IS21LRP	 BUFFER[35]	//(A2IS21LRP) Приход на НУ РБ1-CC
#define idA2IS21LRP	 17	//(A2IS21LRP) Приход на НУ РБ1-CC
#define B2IS21LRP	 BUFFER[37]	//(B2IS21LRP) Приход на НУ РБ2-CC
#define idB2IS21LRP	 18	//(B2IS21LRP) Приход на НУ РБ2-CC
#define A1VS21LRP	 BUFFER[39]	//(A1VS21LRP) Индикация - Приход на НУ ББ1
#define idA1VS21LRP	 19	//(A1VS21LRP) Индикация - Приход на НУ ББ1
#define B1VS21LRP	 BUFFER[41]	//(B1VS21LRP) Индикация - Приход на НУ ББ2
#define idB1VS21LRP	 20	//(B1VS21LRP) Индикация - Приход на НУ ББ2
#define A2VS21LRP	 BUFFER[43]	//(A2VS21LRP) Индикация - Приход на НУ РБ1-CC
#define idA2VS21LRP	 21	//(A2VS21LRP) Индикация - Приход на НУ РБ1-CC
#define B2VS21LRP	 BUFFER[45]	//(B2VS21LRP) Индикация - Приход на НУ РБ2-CC
#define idB2VS21LRP	 22	//(B2VS21LRP) Индикация - Приход на НУ РБ2-CC
#define A3VS21LRP	 BUFFER[47]	//(A3VS21LRP) Индикация - Приход на НУ ИС1
#define idA3VS21LRP	 23	//(A3VS21LRP) Индикация - Приход на НУ ИС1
#define B3VS21LRP	 BUFFER[49]	//(B3VS21LRP) Индикация - Приход на НУ ИС2
#define idB3VS21LRP	 24	//(B3VS21LRP) Индикация - Приход на НУ ИС2
#define C1MD31LRP	 BUFFER[51]	//(C1MD31LRP) Кнопка ОБЩИЙ СБРОС  на РПУ
#define idC1MD31LRP	 25	//(C1MD31LRP) Кнопка ОБЩИЙ СБРОС  на РПУ
#define C1MZ31LRP	 BUFFER[53]	//(C1MZ31LRP) Кнопка ОБДУВ  на РПУ
#define idC1MZ31LRP	 26	//(C1MZ31LRP) Кнопка ОБДУВ  на РПУ
#define R0EE05LZ2	 BUFFER[55]	//(R0EE05LZ2) Питание  АКНП  РПУ отключить
#define idR0EE05LZ2	 27	//(R0EE05LZ2) Питание  АКНП  РПУ отключить
#define A7MZ31LRP	 BUFFER[57]	//(A7MZ31LRP) Клапан (ОБДУВ АЗ1) открыть(обесточить)
#define idA7MZ31LRP	 28	//(A7MZ31LRP) Клапан (ОБДУВ АЗ1) открыть(обесточить)
#define B7MZ31LRP	 BUFFER[59]	//(B7MZ31LRP) Клапан (ОБДУВ АЗ2) открыть(обесточить)
#define idB7MZ31LRP	 29	//(B7MZ31LRP) Клапан (ОБДУВ АЗ2) открыть(обесточить)
#define R0VN02RRP	 BUFFER[61]	//(R0VN02RRP) Уровень мощности канал 5
#define idR0VN02RRP	 30	//(R0VN02RRP) Уровень мощности канал 5
#define R0IN01RRP	 BUFFER[66]	//(R0IN01RRP) Частота СНМ-11 Гц (канал 5)
#define idR0IN01RRP	 31	//(R0IN01RRP) Частота СНМ-11 Гц (канал 5)
#define R0IN02RRP	 BUFFER[71]	//(R0IN02RRP) Частота КНК15-1 Гц (канал 5)
#define idR0IN02RRP	 32	//(R0IN02RRP) Частота КНК15-1 Гц (канал 5)
#define R0VN03RRP	 BUFFER[76]	//(R0VN03RRP) Измеренный нейтронный поток канал 5
#define idR0VN03RRP	 33	//(R0VN03RRP) Измеренный нейтронный поток канал 5
#define B8VC01RDU	 BUFFER[81]	//(B8VC01RDU) Координата АЗ2, мм
#define idB8VC01RDU	 34	//(B8VC01RDU) Координата АЗ2, мм
#define R0IN03RRP	 BUFFER[86]	//(R0IN03RRP) Частота КНК53М Гц (канал 5)
#define idR0IN03RRP	 35	//(R0IN03RRP) Частота КНК53М Гц (канал 5)
#define A0EE02LRP	 BUFFER[91]	//(A0EE02LRP) Исправность АКНП5 (от сшивки каналов) канал 5
#define idA0EE02LRP	 36	//(A0EE02LRP) Исправность АКНП5 (от сшивки каналов) канал 5
#define R0VN23RRP	 BUFFER[93]	//(R0VN23RRP) Нейтронный поток по камере КНК15-1 канал 5
#define idR0VN23RRP	 37	//(R0VN23RRP) Нейтронный поток по камере КНК15-1 канал 5
#define R0VN33RRP	 BUFFER[98]	//(R0VN33RRP) Нейтронный поток по камере КНК53М канал 5
#define idR0VN33RRP	 38	//(R0VN33RRP) Нейтронный поток по камере КНК53М канал 5
#define R0VN15RRP	 BUFFER[103]	//(R0VN15RRP) Номер ведущей камеры канал 5
#define idR0VN15RRP	 39	//(R0VN15RRP) Номер ведущей камеры канал 5
#define R0EE05LZ1	 BUFFER[106]	//(R0EE05LZ1) Питание  АКНП  РПУ отключить
#define idR0EE05LZ1	 40	//(R0EE05LZ1) Питание  АКНП  РПУ отключить
#define R0IE01LRP	 BUFFER[108]	//(R0IE01LRP) Отключение питание детекторов канал 5
#define idR0IE01LRP	 41	//(R0IE01LRP) Отключение питание детекторов канал 5
#define R0IE02LRP	 BUFFER[110]	//(R0IE02LRP) Отключить питание ПР, ПУ канал 5
#define idR0IE02LRP	 42	//(R0IE02LRP) Отключить питание ПР, ПУ канал 5
#define R0IN06RRP	 BUFFER[112]	//(R0IN06RRP) Частота СНМ-11 Гц (канал 6)
#define idR0IN06RRP	 43	//(R0IN06RRP) Частота СНМ-11 Гц (канал 6)
#define R7VN71LRP	 BUFFER[117]	//(R7VN71LRP) Сигнал тревоги по уровню нейтронного потока на диспетчера
#define idR7VN71LRP	 44	//(R7VN71LRP) Сигнал тревоги по уровню нейтронного потока на диспетчера
#define R0IN07RRP	 BUFFER[119]	//(R0IN07RRP) Частота СНМ-11 Гц (канал 7)
#define idR0IN07RRP	 45	//(R0IN07RRP) Частота СНМ-11 Гц (канал 7)
#define A0IT03IRP	 BUFFER[124]	//(A0IT03IRP) Температура АЗ1-3
#define idA0IT03IRP	 46	//(A0IT03IRP) Температура АЗ1-3
#define A0CT01IRP	 BUFFER[127]	//(A0CT01IRP) Температура АЗ1-3
#define idA0CT01IRP	 47	//(A0CT01IRP) Температура АЗ1-3
#define A0VT61LRP	 BUFFER[132]	//(A0VT61LRP) ПС по температуре в АЗ1
#define idA0VT61LRP	 48	//(A0VT61LRP) ПС по температуре в АЗ1
#define A0VT71LRP	 BUFFER[134]	//(A0VT71LRP) АС по температуре в АЗ1
#define idA0VT71LRP	 49	//(A0VT71LRP) АС по температуре в АЗ1
#define R0ET01LRP	 BUFFER[136]	//(R0ET01LRP) Признак наличия неисправности по температуре  АЗ1-3
#define idR0ET01LRP	 50	//(R0ET01LRP) Признак наличия неисправности по температуре  АЗ1-3
#define B0IT03IRP	 BUFFER[138]	//(B0IT03IRP) Температура АЗ2-3
#define idB0IT03IRP	 51	//(B0IT03IRP) Температура АЗ2-3
#define R0ET02LRP	 BUFFER[141]	//(R0ET02LRP) Признак наличия неисправности по температуре АЗ2-3
#define idR0ET02LRP	 52	//(R0ET02LRP) Признак наличия неисправности по температуре АЗ2-3
#define B0CT01IRP	 BUFFER[143]	//(B0CT01IRP) Температура АЗ2-3
#define idB0CT01IRP	 53	//(B0CT01IRP) Температура АЗ2-3
#define B0VT61LRP	 BUFFER[148]	//(B0VT61LRP) ПС по температуре в АЗ2-3
#define idB0VT61LRP	 54	//(B0VT61LRP) ПС по температуре в АЗ2-3
#define B0VT71LRP	 BUFFER[150]	//(B0VT71LRP) АС по температуре в АЗ2-3
#define idB0VT71LRP	 55	//(B0VT71LRP) АС по температуре в АЗ2-3
#define R0IE11LRP	 BUFFER[152]	//(R0IE11LRP) Исправность ВИП 1,6 (№20) СНМ11 5 канала
#define idR0IE11LRP	 56	//(R0IE11LRP) Исправность ВИП 1,6 (№20) СНМ11 5 канала
#define A0EE03LRP	 BUFFER[154]	//(A0EE03LRP) Неисправность от диагностики контроллера
#define idA0EE03LRP	 57	//(A0EE03LRP) Неисправность от диагностики контроллера
#define A0EE01LRP	 BUFFER[156]	//(A0EE01LRP) Исправность АКНП канал 5
#define idA0EE01LRP	 58	//(A0EE01LRP) Исправность АКНП канал 5
#define fEM_R0UH02RSS	 BUFFER[158]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define idfEM_R0UH02RSS	 59	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define fEM_R0UH03RSS	 BUFFER[163]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define idfEM_R0UH03RSS	 60	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define fEM_R7UX00RSS	 BUFFER[168]	//(R7UX00RSS) X-координата АЗ1 (см)
#define idfEM_R7UX00RSS	 61	//(R7UX00RSS) X-координата АЗ1 (см)
#define fEM_R7UY00RSS	 BUFFER[173]	//(R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	 62	//(R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UX13RSS	 BUFFER[178]	//(R7UX13RSS) X-координата камеры R7IN51
#define idfEM_R7UX13RSS	 63	//(R7UX13RSS) X-координата камеры R7IN51
#define fEM_R7UX14RSS	 BUFFER[183]	//(R7UX14RSS) X-координата камеры R7IN52
#define idfEM_R7UX14RSS	 64	//(R7UX14RSS) X-координата камеры R7IN52
#define fEM_R7UX15RSS	 BUFFER[188]	//(R7UX15RSS) X-координата камеры R7IN53
#define idfEM_R7UX15RSS	 65	//(R7UX15RSS) X-координата камеры R7IN53
#define fEM_R7UY13RSS	 BUFFER[193]	//(R7UY13RSS) Y-координата камеры R7IN51
#define idfEM_R7UY13RSS	 66	//(R7UY13RSS) Y-координата камеры R7IN51
#define fEM_R7UY14RSS	 BUFFER[198]	//(R7UY14RSS) Y-координата камеры R7IN52
#define idfEM_R7UY14RSS	 67	//(R7UY14RSS) Y-координата камеры R7IN52
#define fEM_R7UY15RSS	 BUFFER[203]	//(R7UY15RSS) Y-координата камеры R7IN53
#define idfEM_R7UY15RSS	 68	//(R7UY15RSS) Y-координата камеры R7IN53
#define fEM_A0UX00RSS	 BUFFER[208]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 69	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX13RSS	 BUFFER[213]	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define idfEM_A0UX13RSS	 70	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define fEM_A0UX14RSS	 BUFFER[218]	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define idfEM_A0UX14RSS	 71	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define fEM_A0UX15RSS	 BUFFER[223]	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define idfEM_A0UX15RSS	 72	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define fEM_B0UX03RSS	 BUFFER[228]	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	 73	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	 BUFFER[233]	//(B0UX04RSS) Второй коэффициент калибровки камеры4
#define idfEM_B0UX04RSS	 74	//(B0UX04RSS) Второй коэффициент калибровки камеры4
#define fEM_B0UX05RSS	 BUFFER[238]	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	 75	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_R0UH05RSS	 BUFFER[243]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 76	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UR01RRP	 BUFFER[248]	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
#define idfEM_R0UR01RRP	 77	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
#define fEM_R0UT02RZZ	 BUFFER[253]	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	 78	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RZZ	 BUFFER[258]	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	 79	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_R0UT72RZZ	 BUFFER[263]	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	 80	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	 BUFFER[268]	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	 81	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	 BUFFER[273]	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	 82	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT61RZZ	 BUFFER[278]	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	 83	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_R0UL52RSS	 BUFFER[283]	//(R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	 84	//(R0UL52RSS) Уровень АС по мощности
#define fEM_Z7UE20RRP	 BUFFER[288]	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
#define idfEM_Z7UE20RRP	 85	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
#define bFirstEnterFlag	 BUFFER[293]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 86	//(bFirstEnterFlag) 
#define internal1_m16_Nk	 BUFFER[295]	//(internal1_m16_Nk) Nk - ведущая камера
#define idinternal1_m16_Nk	 87	//(internal1_m16_Nk) Nk - ведущая камера
#define internal1_m61_tx	 BUFFER[298]	//(internal1_m61_tx) tx - время накопленное сек
#define idinternal1_m61_tx	 88	//(internal1_m61_tx) tx - время накопленное сек
#define internal1_m61_y0	 BUFFER[303]	//(internal1_m61_y0) y0
#define idinternal1_m61_y0	 89	//(internal1_m61_y0) y0
#define internal1_m71_tx	 BUFFER[304]	//(internal1_m71_tx) tx - время накопленное сек
#define idinternal1_m71_tx	 90	//(internal1_m71_tx) tx - время накопленное сек
#define internal1_m71_y0	 BUFFER[309]	//(internal1_m71_y0) y0
#define idinternal1_m71_y0	 91	//(internal1_m71_y0) y0
#define internal1_m80_y0	 BUFFER[310]	//(internal1_m80_y0) y0
#define idinternal1_m80_y0	 92	//(internal1_m80_y0) y0
#define internal1_m78_y0	 BUFFER[315]	//(internal1_m78_y0) y0
#define idinternal1_m78_y0	 93	//(internal1_m78_y0) y0
#define internal1_m92_y1	 BUFFER[320]	//(internal1_m92_y1) y1 - внутренний параметр
#define idinternal1_m92_y1	 94	//(internal1_m92_y1) y1 - внутренний параметр
#define internal1_m103_y1	 BUFFER[322]	//(internal1_m103_y1) y1 - внутренний параметр
#define idinternal1_m103_y1	 95	//(internal1_m103_y1) y1 - внутренний параметр
#define internal1_m90_y1	 BUFFER[324]	//(internal1_m90_y1) y1 - внутренний параметр
#define idinternal1_m90_y1	 96	//(internal1_m90_y1) y1 - внутренний параметр
#define internal1_m101_y1	 BUFFER[326]	//(internal1_m101_y1) y1 - внутренний параметр
#define idinternal1_m101_y1	 97	//(internal1_m101_y1) y1 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &R0IE12LRP},	//(R0IE12LRP) Исправность ВИП 0,5 -5к (№21)
	{ 2	,1	,1	, &R0IE13LRP},	//(R0IE13LRP) Исправность ВИП 0,5 -5к (№22)
	{ 3	,1	,1	, &R0IE14LRP},	//(R0IE14LRP) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
	{ 4	,1	,1	, &R0IE15LRP},	//(R0IE15LRP) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
	{ 5	,1	,1	, &R0IE03LRP},	//(R0IE03LRP) Отключение питание детекторов канал  6,7
	{ 6	,1	,1	, &R0IE04LRP},	//(R0IE04LRP) Отключить питание ПР, ПУ канал 6,7
	{ 7	,1	,1	, &A1VT71LRP},	//(A1VT71LRP) АС по температуре
	{ 8	,1	,1	, &R0VN71LRP},	//(R0VN71LRP) АС по мощности канал 5
	{ 9	,8	,1	, &R0VN13RRP},	//(R0VN13RRP) Нейтронный поток по камере  СНМ-11 канал 5
	{ 10	,1	,1	, &A6IS11LRP},	//(A6IS11LRP) Приход на ВУ БЗ1
	{ 11	,1	,1	, &B6IS11LRP},	//(B6IS11LRP) Приход на ВУ БЗ2
	{ 12	,1	,1	, &R7VE70LRP},	//(R7VE70LRP) Сигнал тревоги по неисправности РПУ на диспетчера
	{ 13	,1	,1	, &A3IS21LRP},	//(A3IS21LRP) Приход на НУ ИС1
	{ 14	,1	,1	, &B3IS21LRP},	//(B3IS21LRP) Приход на НУ ИС2
	{ 15	,1	,1	, &A1IS21LRP},	//(A1IS21LRP) Приход на НУ ББ1
	{ 16	,1	,1	, &B1IS21LRP},	//(B1IS21LRP) Приход на НУ ББ2
	{ 17	,1	,1	, &A2IS21LRP},	//(A2IS21LRP) Приход на НУ РБ1-CC
	{ 18	,1	,1	, &B2IS21LRP},	//(B2IS21LRP) Приход на НУ РБ2-CC
	{ 19	,1	,1	, &A1VS21LRP},	//(A1VS21LRP) Индикация - Приход на НУ ББ1
	{ 20	,1	,1	, &B1VS21LRP},	//(B1VS21LRP) Индикация - Приход на НУ ББ2
	{ 21	,1	,1	, &A2VS21LRP},	//(A2VS21LRP) Индикация - Приход на НУ РБ1-CC
	{ 22	,1	,1	, &B2VS21LRP},	//(B2VS21LRP) Индикация - Приход на НУ РБ2-CC
	{ 23	,1	,1	, &A3VS21LRP},	//(A3VS21LRP) Индикация - Приход на НУ ИС1
	{ 24	,1	,1	, &B3VS21LRP},	//(B3VS21LRP) Индикация - Приход на НУ ИС2
	{ 25	,1	,1	, &C1MD31LRP},	//(C1MD31LRP) Кнопка ОБЩИЙ СБРОС  на РПУ
	{ 26	,1	,1	, &C1MZ31LRP},	//(C1MZ31LRP) Кнопка ОБДУВ  на РПУ
	{ 27	,1	,1	, &R0EE05LZ2},	//(R0EE05LZ2) Питание  АКНП  РПУ отключить
	{ 28	,1	,1	, &A7MZ31LRP},	//(A7MZ31LRP) Клапан (ОБДУВ АЗ1) открыть(обесточить)
	{ 29	,1	,1	, &B7MZ31LRP},	//(B7MZ31LRP) Клапан (ОБДУВ АЗ2) открыть(обесточить)
	{ 30	,8	,1	, &R0VN02RRP},	//(R0VN02RRP) Уровень мощности канал 5
	{ 31	,8	,1	, &R0IN01RRP},	//(R0IN01RRP) Частота СНМ-11 Гц (канал 5)
	{ 32	,8	,1	, &R0IN02RRP},	//(R0IN02RRP) Частота КНК15-1 Гц (канал 5)
	{ 33	,8	,1	, &R0VN03RRP},	//(R0VN03RRP) Измеренный нейтронный поток канал 5
	{ 34	,8	,1	, &B8VC01RDU},	//(B8VC01RDU) Координата АЗ2, мм
	{ 35	,8	,1	, &R0IN03RRP},	//(R0IN03RRP) Частота КНК53М Гц (канал 5)
	{ 36	,1	,1	, &A0EE02LRP},	//(A0EE02LRP) Исправность АКНП5 (от сшивки каналов) канал 5
	{ 37	,8	,1	, &R0VN23RRP},	//(R0VN23RRP) Нейтронный поток по камере КНК15-1 канал 5
	{ 38	,8	,1	, &R0VN33RRP},	//(R0VN33RRP) Нейтронный поток по камере КНК53М канал 5
	{ 39	,3	,1	, &R0VN15RRP},	//(R0VN15RRP) Номер ведущей камеры канал 5
	{ 40	,1	,1	, &R0EE05LZ1},	//(R0EE05LZ1) Питание  АКНП  РПУ отключить
	{ 41	,1	,1	, &R0IE01LRP},	//(R0IE01LRP) Отключение питание детекторов канал 5
	{ 42	,1	,1	, &R0IE02LRP},	//(R0IE02LRP) Отключить питание ПР, ПУ канал 5
	{ 43	,8	,1	, &R0IN06RRP},	//(R0IN06RRP) Частота СНМ-11 Гц (канал 6)
	{ 44	,1	,1	, &R7VN71LRP},	//(R7VN71LRP) Сигнал тревоги по уровню нейтронного потока на диспетчера
	{ 45	,8	,1	, &R0IN07RRP},	//(R0IN07RRP) Частота СНМ-11 Гц (канал 7)
	{ 46	,3	,1	, &A0IT03IRP},	//(A0IT03IRP) Температура АЗ1-3
	{ 47	,8	,1	, &A0CT01IRP},	//(A0CT01IRP) Температура АЗ1-3
	{ 48	,1	,1	, &A0VT61LRP},	//(A0VT61LRP) ПС по температуре в АЗ1
	{ 49	,1	,1	, &A0VT71LRP},	//(A0VT71LRP) АС по температуре в АЗ1
	{ 50	,1	,1	, &R0ET01LRP},	//(R0ET01LRP) Признак наличия неисправности по температуре  АЗ1-3
	{ 51	,3	,1	, &B0IT03IRP},	//(B0IT03IRP) Температура АЗ2-3
	{ 52	,1	,1	, &R0ET02LRP},	//(R0ET02LRP) Признак наличия неисправности по температуре АЗ2-3
	{ 53	,8	,1	, &B0CT01IRP},	//(B0CT01IRP) Температура АЗ2-3
	{ 54	,1	,1	, &B0VT61LRP},	//(B0VT61LRP) ПС по температуре в АЗ2-3
	{ 55	,1	,1	, &B0VT71LRP},	//(B0VT71LRP) АС по температуре в АЗ2-3
	{ 56	,1	,1	, &R0IE11LRP},	//(R0IE11LRP) Исправность ВИП 1,6 (№20) СНМ11 5 канала
	{ 57	,1	,1	, &A0EE03LRP},	//(A0EE03LRP) Неисправность от диагностики контроллера
	{ 58	,1	,1	, &A0EE01LRP},	//(A0EE01LRP) Исправность АКНП канал 5
	{ 59	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{ 60	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{ 61	,8	,1	, &fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{ 62	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{ 63	,8	,1	, &fEM_R7UX13RSS},	//(R7UX13RSS) X-координата камеры R7IN51
	{ 64	,8	,1	, &fEM_R7UX14RSS},	//(R7UX14RSS) X-координата камеры R7IN52
	{ 65	,8	,1	, &fEM_R7UX15RSS},	//(R7UX15RSS) X-координата камеры R7IN53
	{ 66	,8	,1	, &fEM_R7UY13RSS},	//(R7UY13RSS) Y-координата камеры R7IN51
	{ 67	,8	,1	, &fEM_R7UY14RSS},	//(R7UY14RSS) Y-координата камеры R7IN52
	{ 68	,8	,1	, &fEM_R7UY15RSS},	//(R7UY15RSS) Y-координата камеры R7IN53
	{ 69	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 70	,8	,1	, &fEM_A0UX13RSS},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{ 71	,8	,1	, &fEM_A0UX14RSS},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{ 72	,8	,1	, &fEM_A0UX15RSS},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{ 73	,8	,1	, &fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{ 74	,8	,1	, &fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры4
	{ 75	,8	,1	, &fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{ 76	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 77	,8	,1	, &fEM_R0UR01RRP},	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
	{ 78	,8	,1	, &fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{ 79	,8	,1	, &fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{ 80	,8	,1	, &fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{ 81	,8	,1	, &fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{ 82	,8	,1	, &fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{ 83	,8	,1	, &fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{ 84	,8	,1	, &fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{ 85	,8	,1	, &fEM_Z7UE20RRP},	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
	{ 86	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 87	,3	,1	, &internal1_m16_Nk},	//(internal1_m16_Nk) Nk - ведущая камера
	{ 88	,8	,1	, &internal1_m61_tx},	//(internal1_m61_tx) tx - время накопленное сек
	{ 89	,18	,1	, &internal1_m61_y0},	//(internal1_m61_y0) y0
	{ 90	,8	,1	, &internal1_m71_tx},	//(internal1_m71_tx) tx - время накопленное сек
	{ 91	,18	,1	, &internal1_m71_y0},	//(internal1_m71_y0) y0
	{ 92	,8	,1	, &internal1_m80_y0},	//(internal1_m80_y0) y0
	{ 93	,8	,1	, &internal1_m78_y0},	//(internal1_m78_y0) y0
	{ 94	,1	,1	, &internal1_m92_y1},	//(internal1_m92_y1) y1 - внутренний параметр
	{ 95	,1	,1	, &internal1_m103_y1},	//(internal1_m103_y1) y1 - внутренний параметр
	{ 96	,1	,1	, &internal1_m90_y1},	//(internal1_m90_y1) y1 - внутренний параметр
	{ 97	,1	,1	, &internal1_m101_y1},	//(internal1_m101_y1) y1 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="rpu.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
   {59,"fEM_R0UH02RSS\0"}, 
   {60,"fEM_R0UH03RSS\0"}, 
   {61,"fEM_R7UX00RSS\0"}, 
   {62,"fEM_R7UY00RSS\0"}, 
   {63,"fEM_R7UX13RSS\0"}, 
   {64,"fEM_R7UX14RSS\0"}, 
   {65,"fEM_R7UX15RSS\0"}, 
   {66,"fEM_R7UY13RSS\0"}, 
   {67,"fEM_R7UY14RSS\0"}, 
   {68,"fEM_R7UY15RSS\0"}, 
   {69,"fEM_A0UX00RSS\0"}, 
   {70,"fEM_A0UX13RSS\0"}, 
   {71,"fEM_A0UX14RSS\0"}, 
   {72,"fEM_A0UX15RSS\0"}, 
   {73,"fEM_B0UX03RSS\0"}, 
   {74,"fEM_B0UX04RSS\0"}, 
   {75,"fEM_B0UX05RSS\0"}, 
   {76,"fEM_R0UH05RSS\0"}, 
   {77,"fEM_R0UR01RRP\0"}, 
   {78,"fEM_R0UT02RZZ\0"}, 
   {79,"fEM_R0UT01RZZ\0"}, 
   {80,"fEM_R0UT72RZZ\0"}, 
   {81,"fEM_R0UT71RZZ\0"}, 
   {82,"fEM_R0UT62RZZ\0"}, 
   {83,"fEM_R0UT61RZZ\0"}, 
   {84,"fEM_R0UL52RSS\0"}, 
   {85,"fEM_Z7UE20RRP\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_RPU[]={  // 
	{&R0EE05LZ2,1,0},	//(R0EE05LZ2) Питание  АКНП  РПУ отключить
	{&A0EE03LRP,1,1},	//(A0EE03LRP) Неисправность от диагностики контроллера
	{&R0EE05LZ1,1,2},	//(R0EE05LZ1) Питание  АКНП  РПУ отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_RPU[]={  // 
	{&B7MZ31LRP,1,0},	//(B7MZ31LRP) Клапан (ОБДУВ АЗ2) открыть(обесточить)
	{&A7MZ31LRP,1,1},	//(A7MZ31LRP) Клапан (ОБДУВ АЗ1) открыть(обесточить)
	{&R7VE70LRP,1,2},	//(R7VE70LRP) Сигнал тревоги по неисправности РПУ на диспетчера
	{&A0EE01LRP,1,3},	//(A0EE01LRP) Исправность АКНП канал 5
	{&B0VT71LRP,1,4},	//(B0VT71LRP) АС по температуре в АЗ2-3
	{&B0VT61LRP,1,5},	//(B0VT61LRP) ПС по температуре в АЗ2-3
	{&R0ET02LRP,1,6},	//(R0ET02LRP) Признак наличия неисправности по температуре АЗ2-3
	{&R0ET01LRP,1,7},	//(R0ET01LRP) Признак наличия неисправности по температуре  АЗ1-3
	{&A0VT71LRP,1,8},	//(A0VT71LRP) АС по температуре в АЗ1
	{&A0VT61LRP,1,9},	//(A0VT61LRP) ПС по температуре в АЗ1
	{&R7VN71LRP,1,10},	//(R7VN71LRP) Сигнал тревоги по уровню нейтронного потока на диспетчера
	{&A0EE02LRP,1,11},	//(A0EE02LRP) Исправность АКНП5 (от сшивки каналов) канал 5
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_RPU[]={  // 
	{&R0VN13RRP,8,0},	//(R0VN13RRP) Нейтронный поток по камере  СНМ-11 канал 5
	{&B0CT01IRP,8,2},	//(B0CT01IRP) Температура АЗ2-3
	{&A0CT01IRP,8,4},	//(A0CT01IRP) Температура АЗ1-3
	{&R0VN15RRP,3,6},	//(R0VN15RRP) Номер ведущей камеры канал 5
	{&R0VN33RRP,8,7},	//(R0VN33RRP) Нейтронный поток по камере КНК53М канал 5
	{&R0VN23RRP,8,9},	//(R0VN23RRP) Нейтронный поток по камере КНК15-1 канал 5
	{&R0VN03RRP,8,11},	//(R0VN03RRP) Измеренный нейтронный поток канал 5
	{&R0VN02RRP,8,13},	//(R0VN02RRP) Уровень мощности канал 5
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_RPU[]={  // 
	{&R0IN07RRP,8,0},	//(R0IN07RRP) Частота СНМ-11 Гц (канал 7)
	{&R0IN06RRP,8,2},	//(R0IN06RRP) Частота СНМ-11 Гц (канал 6)
	{&R0IN03RRP,8,4},	//(R0IN03RRP) Частота КНК53М Гц (канал 5)
	{&B8VC01RDU,8,6},	//(B8VC01RDU) Координата АЗ2, мм
	{&R0IN02RRP,8,8},	//(R0IN02RRP) Частота КНК15-1 Гц (канал 5)
	{&R0IN01RRP,8,10},	//(R0IN01RRP) Частота СНМ-11 Гц (канал 5)
	{&fEM_Z7UE20RRP,8,12},	//(Z7UE20RRP) Время задержки сигнала на включение источников питания после снятия команды на отключение
	{&fEM_R0UL52RSS,8,14},	//(R0UL52RSS) Уровень АС по мощности
	{&fEM_R0UT61RZZ,8,16},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{&fEM_R0UT62RZZ,8,18},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{&fEM_R0UT71RZZ,8,20},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{&fEM_R0UT72RZZ,8,22},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{&fEM_R0UT01RZZ,8,24},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{&fEM_R0UT02RZZ,8,26},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{&fEM_R0UR01RRP,8,28},	//(R0UR01RRP) Уставка СНМ11 в БЗ - АС по частоте
	{&fEM_R0UH05RSS,8,30},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_B0UX05RSS,8,32},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{&fEM_B0UX04RSS,8,34},	//(B0UX04RSS) Второй коэффициент калибровки камеры4
	{&fEM_B0UX03RSS,8,36},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{&fEM_A0UX15RSS,8,38},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{&fEM_A0UX14RSS,8,40},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{&fEM_A0UX13RSS,8,42},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{&fEM_A0UX00RSS,8,44},	//(A0UX00RSS) Эффективный радиус АЗ
	{&fEM_R7UY15RSS,8,46},	//(R7UY15RSS) Y-координата камеры R7IN53
	{&fEM_R7UY14RSS,8,48},	//(R7UY14RSS) Y-координата камеры R7IN52
	{&fEM_R7UY13RSS,8,50},	//(R7UY13RSS) Y-координата камеры R7IN51
	{&fEM_R7UX15RSS,8,52},	//(R7UX15RSS) X-координата камеры R7IN53
	{&fEM_R7UX14RSS,8,54},	//(R7UX14RSS) X-координата камеры R7IN52
	{&fEM_R7UX13RSS,8,56},	//(R7UX13RSS) X-координата камеры R7IN51
	{&fEM_R7UY00RSS,8,58},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{&fEM_R7UX00RSS,8,60},	//(R7UX00RSS) X-координата АЗ1 (см)
	{&fEM_R0UH03RSS,8,62},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{&fEM_R0UH02RSS,8,64},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,502,&coil_RPU[0],&di_RPU[0],&ir_RPU[0],&hr_RPU[0],NULL,NULL,NULL,0},	 //общий slave RPU

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
	{&R0IN07RRP,8,5},
	{&R0IN06RRP,8,0},
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
	{&B0IT03IRP,3,3},
	{&A0IT03IRP,3,0},
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
	{&B6IS11LRP,1,28},
	{&A3IS21LRP,1,14},
	{&B3IS21LRP,1,20},
	{&A6IS11LRP,1,26},
	{&A1IS21LRP,1,16},
	{&C1MZ31LRP,1,12},
	{&C1MD31LRP,1,10},
	{&B1IS21LRP,1,22},
	{&A2IS21LRP,1,18},
	{&B2IS21LRP,1,24},
	{&R0IE15LRP,1,2},
	{&R0IE14LRP,1,0},
	{&R0IE11LRP,1,4},
	{&R0IE13LRP,1,8},
	{&R0IE12LRP,1,6},
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
	{&R0IE03LRP,1,16},
	{&R0IE04LRP,1,18},
	{&A1VT71LRP,1,20},
	{&R0VN71LRP,1,22},
	{&R0IE02LRP,1,12},
	{&R0IE01LRP,1,14},
	{&A3VS21LRP,1,8},
	{&B3VS21LRP,1,10},
	{&B2VS21LRP,1,6},
	{&A1VS21LRP,1,0},
	{&B1VS21LRP,1,2},
	{&A2VS21LRP,1,4},
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
	setAsFloat(59,3703.704 );
	setAsFloat(60,62500.0);
	setAsFloat(61,1567.36);
	setAsFloat(62,506.5);
	setAsFloat(63,1570.0);
	setAsFloat(64,1269);
	setAsFloat(65,1281.2);
	setAsFloat(66,248.0);
	setAsFloat(67,572.4);
	setAsFloat(68,246.8);
	setAsFloat(69,11.0);
	setAsFloat(70,1.0);
	setAsFloat(71,1.0);
	setAsFloat(72,1.0);
	setAsFloat(73,0);
	setAsFloat(74,0);
	setAsFloat(75,0.0);
	setAsFloat(76,32000.0);
	setAsFloat(77,1000);
	setAsFloat(78,600);
	setAsFloat(79,0);
	setAsFloat(80,150);
	setAsFloat(81,200);
	setAsFloat(82,90);
	setAsFloat(83,100);
	setAsFloat(84,5100);
	setAsFloat(85,210);
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
ssbool var28;
ssfloat var29;
ssfloat var30;
sschar var31;
ssbool var32;
ssbool var33;
sschar var34;
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
ssbool var45;
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
_S_or5  S_or5_62_1 = {&var18,&var19,&A0EE03LRP,&var9,&var37,&var8};
_S_or2  S_or2_86_1 = {&var44,&var45,&var9};
_S_or4  S_or4_42_1 = {&var17,&var14,&var16,&var12,&var10};
_S_or2  S_or2_91_1 = {&var43,&var32,&var11};
_S_or2  S_or2_107_1 = {&var13,&var11,&var12};
_S_or2  S_or2_87_1 = {&var42,&var35,&var13};
_S_and3  S_and3_37_1 = {&var15,&var28,&var21,&var14};
_S_and4  S_and4_36_1 = {&R0IE11LRP,&var3,&R0IE12LRP,&R0IE13LRP,&var15};
_S_and3  S_and3_45_1 = {&var25,&R0IE14LRP,&var38,&var16};
_S_and3  S_and3_44_1 = {&R0IE15LRP,&var25,&var39,&var17};
_S_and3  S_and3_52_1 = {&R0IE14LRP,&var25,&var41,&var18};
_S_and3  S_and3_51_1 = {&var40,&R0IE15LRP,&var25,&var19};
_S_geterr  S_geterr_48_1 = {&R0IN06RRP,&dRM_0_,&iRM_0_,&bRM_0_,&var20,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_noto  S_noto_72_1 = {&var26,&var21};
_S_geterr  S_geterr_47_1 = {&R0IN07RRP,&dRM_0_,&iRM_0_,&bRM_0_,&var22,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_zzfs  S_zzfs_61_1 = {&var24,&fEM_Z7UE20RRP,&var23,&internal1_m61_tx,&internal1_m61_y0};
_S_or3  S_or3_60_1 = {&A6IS11LRP,&B6IS11LRP,&var27,&var24};
_S_noto  S_noto_58_1 = {&var23,&var25};
_S_zzfs  S_zzfs_71_1 = {&var27,&fEM_Z7UE20RRP,&var26,&internal1_m71_tx,&internal1_m71_y0};
_S_or2  S_or2_70_1 = {&R0EE05LZ1,&R0EE05LZ2,&var27};
_S_bol  S_bol_35_1 = {&var2,&fEM_R0UL52RSS,&var28};
_S_scalzz  S_scalzz_80_1 = {&B0IT03IRP,&iRM_819_,&iRM_4095_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var29,&internal1_m80_y0};
_S_scalzz  S_scalzz_78_1 = {&A0IT03IRP,&iRM_819_,&iRM_4095_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var30,&internal1_m78_y0};
_S_geterr  S_geterr_82_1 = {&var30,&dRM_0_,&iRM_0_,&bRM_0_,&var31,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_92_1 = {&var29,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var32,&internal1_m92_y1};
_S_drg  S_drg_103_1 = {&var29,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var33,&internal1_m103_y1};
_S_geterr  S_geterr_84_1 = {&var29,&dRM_0_,&iRM_0_,&bRM_0_,&var34,&vainSChar,&vainSChar,&vainSChar,&vainSBool};
_S_drg  S_drg_90_1 = {&var30,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var35,&internal1_m90_y1};
_S_drg  S_drg_101_1 = {&var30,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var36,&internal1_m101_y1};
_S_noto  S_noto_67_1 = {&var15,&var37};
_S_bol  S_bol_53_1 = {&R0IN07RRP,&fEM_R0UR01RRP,&var38};
_S_bol  S_bol_43_1 = {&R0IN06RRP,&fEM_R0UR01RRP,&var39};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  scalzz(&S_scalzz_78_1);
  scalzz(&S_scalzz_80_1);
  geterr(&S_geterr_47_1);
  geterr(&S_geterr_48_1);
  or2(&S_or2_57_1);
  ocham(&S_ocham_16_1);
  bol(&S_bol_43_1);
  bol(&S_bol_53_1);
  drg(&S_drg_101_1);
  drg(&S_drg_90_1);
  geterr(&S_geterr_84_1);
  drg(&S_drg_103_1);
  drg(&S_drg_92_1);
  geterr(&S_geterr_82_1);
  bol(&S_bol_35_1);
  or2(&S_or2_70_1);
  zzfs(&S_zzfs_71_1);
  or3(&S_or3_60_1);
  zzfs(&S_zzfs_61_1);
  noto(&S_noto_72_1);
  and4(&S_and4_36_1);
  and3(&S_and3_37_1);
  setData(&var42,&var31);
  or2(&S_or2_87_1);
  setData(&var43,&var34);
  or2(&S_or2_91_1);
  setData(&var44,&var31);
  setData(&var45,&var34);
  or2(&S_or2_86_1);
  noto(&S_noto_67_1);
  noto(&S_noto_58_1);
  setData(&var40,&var22);
  and3(&S_and3_51_1);
  setData(&var41,&var20);
  and3(&S_and3_52_1);
  and3(&S_and3_44_1);
  and3(&S_and3_45_1);
  or2(&S_or2_107_1);
  or4(&S_or4_42_1);
  or5(&S_or5_62_1);
  moveData(idB7MZ31LRP,idC1MZ31LRP);
  moveData(idA7MZ31LRP,idC1MZ31LRP);
  moveData(idB3VS21LRP,idB3IS21LRP);
  moveData(idA3VS21LRP,idA3IS21LRP);
  moveData(idB2VS21LRP,idB2IS21LRP);
  moveData(idA2VS21LRP,idA2IS21LRP);
  moveData(idB1VS21LRP,idB1IS21LRP);
  moveData(idA1VS21LRP,idA1IS21LRP);
  setData(idR7VE70LRP,&var8);
  setData(idR0VN13RRP,&var4);
  setData(idR0VN71LRP,&var28);
  setData(idA1VT71LRP,&var12);
  setData(idR0IE04LRP,&var23);
  setData(idR0IE03LRP,&var23);
  setData(idA0EE01LRP,&var15);
  setData(idB0VT71LRP,&var11);
  setData(idB0VT61LRP,&var33);
  setData(idB0CT01IRP,&var29);
  setData(idR0ET02LRP,&var34);
  setData(idR0ET01LRP,&var31);
  setData(idA0VT71LRP,&var13);
  setData(idA0VT61LRP,&var36);
  setData(idA0CT01IRP,&var30);
  setData(idR7VN71LRP,&var10);
  setData(idR0IE02LRP,&var26);
  setData(idR0IE01LRP,&var26);
  setData(idR0VN15RRP,&var7);
  setData(idR0VN33RRP,&var6);
  setData(idR0VN23RRP,&var5);
  setData(idA0EE02LRP,&var3);
  setData(idR0VN03RRP,&var1);
  setData(idR0VN02RRP,&var2);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}

#endif
