#ifndef AKNP2_H
#define AKNP2_H
// Подсистема AKNP2:AKNP2
static char SimulOn=0;
static short CodeSub=9;
static char SimulIP[]="192.168.1.17\0";
static int SimulPort=5555;
static int StepCycle=5;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 379
static char BUFFER[379];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.57\0", 5432, "192.168.10.157\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0VN02RS2	 BUFFER[0]	//(R0VN02RS2) Уровень мощности канал 2
#define idR0VN02RS2	 1	//(R0VN02RS2) Уровень мощности канал 2
#define R0VN01RS2	 BUFFER[5]	//(R0VN01RS2) Период разгона канал 2
#define idR0VN01RS2	 2	//(R0VN01RS2) Период разгона канал 2
#define R0VN61LS2	 BUFFER[10]	//(R0VN61LS2) ПС по мощности канал 2
#define idR0VN61LS2	 3	//(R0VN61LS2) ПС по мощности канал 2
#define R0VN72LZ1	 BUFFER[12]	//(R0VN72LZ1) АС по мощности канал 2 на БАЗ1
#define idR0VN72LZ1	 4	//(R0VN72LZ1) АС по мощности канал 2 на БАЗ1
#define R0VN65LS2	 BUFFER[14]	//(R0VN65LS2) ПС по периоду разгона канал 2
#define idR0VN65LS2	 5	//(R0VN65LS2) ПС по периоду разгона канал 2
#define R0VN76LZ1	 BUFFER[16]	//(R0VN76LZ1) АС по периоду разгона канал 2  на БАЗ1
#define idR0VN76LZ1	 6	//(R0VN76LZ1) АС по периоду разгона канал 2  на БАЗ1
#define A0EE01LS2	 BUFFER[18]	//(A0EE01LS2) Исправность АКНП канал 2 на БАЗ1
#define idA0EE01LS2	 7	//(A0EE01LS2) Исправность АКНП канал 2 на БАЗ1
#define R0IN01FS2	 BUFFER[20]	//(R0IN01FS2) Выход СНМ-11 Гц
#define idR0IN01FS2	 8	//(R0IN01FS2) Выход СНМ-11 Гц
#define R0IN02FS2	 BUFFER[25]	//(R0IN02FS2) Выход КНК15-1  Гц
#define idR0IN02FS2	 9	//(R0IN02FS2) Выход КНК15-1  Гц
#define R0VN03RS2	 BUFFER[30]	//(R0VN03RS2) Измеренный нейтронный поток канал 2
#define idR0VN03RS2	 10	//(R0VN03RS2) Измеренный нейтронный поток канал 2
#define R0VN04RS2	 BUFFER[35]	//(R0VN04RS2) Реактивность канал 2
#define idR0VN04RS2	 11	//(R0VN04RS2) Реактивность канал 2
#define A1VN71LS2	 BUFFER[40]	//(A1VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ2
#define idA1VN71LS2	 12	//(A1VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ2
#define R0IN03FS2	 BUFFER[42]	//(R0IN03FS2) Выход КНК53М Гц
#define idR0IN03FS2	 13	//(R0IN03FS2) Выход КНК53М Гц
#define A0EE02LS2	 BUFFER[47]	//(A0EE02LS2) Исправность АКНП2 (от сшивки каналов) канал 2
#define idA0EE02LS2	 14	//(A0EE02LS2) Исправность АКНП2 (от сшивки каналов) канал 2
#define R0IE11LS2	 BUFFER[49]	//(R0IE11LS2) Исправность ВИП 1,6 (№11) СНМ11 2канала
#define idR0IE11LS2	 15	//(R0IE11LS2) Исправность ВИП 1,6 (№11) СНМ11 2канала
#define R0IE12LS2	 BUFFER[51]	//(R0IE12LS2) Исправность ВИП 0,5 (№12) КНК15-1 2 канала
#define idR0IE12LS2	 16	//(R0IE12LS2) Исправность ВИП 0,5 (№12) КНК15-1 2 канала
#define R0IE13LS2	 BUFFER[53]	//(R0IE13LS2) Исправность ВИП 0,5 (№13) КНК53М 2 канала
#define idR0IE13LS2	 17	//(R0IE13LS2) Исправность ВИП 0,5 (№13) КНК53М 2 канала
#define R0VN13RS2	 BUFFER[55]	//(R0VN13RS2) Нейтронный поток по камере СНМ11 канал 2
#define idR0VN13RS2	 18	//(R0VN13RS2) Нейтронный поток по камере СНМ11 канал 2
#define R0VN23RS2	 BUFFER[60]	//(R0VN23RS2) Нейтронный поток по камере КНК15-1 канал 2
#define idR0VN23RS2	 19	//(R0VN23RS2) Нейтронный поток по камере КНК15-1 канал 2
#define R0VN33RS2	 BUFFER[65]	//(R0VN33RS2) Нейтронный поток по камере КНК53М канал 2
#define idR0VN33RS2	 20	//(R0VN33RS2) Нейтронный поток по камере КНК53М канал 2
#define R0VN15RS2	 BUFFER[70]	//(R0VN15RS2) Номер ведущей камеры канал 2
#define idR0VN15RS2	 21	//(R0VN15RS2) Номер ведущей камеры канал 2
#define A0EE03LS2	 BUFFER[73]	//(A0EE03LS2) Подключена сеть питания АКНП канал 2
#define idA0EE03LS2	 22	//(A0EE03LS2) Подключена сеть питания АКНП канал 2
#define R0IE01LS2	 BUFFER[75]	//(R0IE01LS2) Отключение питание детекторов канал 2
#define idR0IE01LS2	 23	//(R0IE01LS2) Отключение питание детекторов канал 2
#define R0IE02LS2	 BUFFER[77]	//(R0IE02LS2) Отключить питание ПР, ПУ канал 2
#define idR0IE02LS2	 24	//(R0IE02LS2) Отключить питание ПР, ПУ канал 2
#define R0VN72LZ2	 BUFFER[79]	//(R0VN72LZ2) АС по мощности канал 2 на БАЗ2
#define idR0VN72LZ2	 25	//(R0VN72LZ2) АС по мощности канал 2 на БАЗ2
#define R0VN76LZ2	 BUFFER[81]	//(R0VN76LZ2) АС по периоду разгона канал 2  на БАЗ2
#define idR0VN76LZ2	 26	//(R0VN76LZ2) АС по периоду разгона канал 2  на БАЗ2
#define A1EE01LS2	 BUFFER[83]	//(A1EE01LS2) Исправность АКНП канал 2 на БАЗ2
#define idA1EE01LS2	 27	//(A1EE01LS2) Исправность АКНП канал 2 на БАЗ2
#define A0VN71LS2	 BUFFER[85]	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ1
#define idA0VN71LS2	 28	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ1
#define B8VC01RDU	 BUFFER[87]	//(B8VC01RDU) Координата АЗ2, мм
#define idB8VC01RDU	 29	//(B8VC01RDU) Координата АЗ2, мм
#define R0EE02LZ1	 BUFFER[92]	//(R0EE02LZ1) Питание  АКНП  отключить
#define idR0EE02LZ1	 30	//(R0EE02LZ1) Питание  АКНП  отключить
#define R0EE02LZ2	 BUFFER[94]	//(R0EE02LZ2) Питание  АКНП  отключить
#define idR0EE02LZ2	 31	//(R0EE02LZ2) Питание  АКНП  отключить
#define R0DE01LS2	 BUFFER[96]	//(R0DE01LS2) диагностика модуля АКНП2 на 1 месте
#define idR0DE01LS2	 32	//(R0DE01LS2) диагностика модуля АКНП2 на 1 месте
#define R0DE02LS2	 BUFFER[99]	//(R0DE02LS2) диагностика модуля АКНП2 на 2 месте
#define idR0DE02LS2	 33	//(R0DE02LS2) диагностика модуля АКНП2 на 2 месте
#define R0DE04LS2	 BUFFER[102]	//(R0DE04LS2) диагностика модуля АКНП2 на 4 месте
#define idR0DE04LS2	 34	//(R0DE04LS2) диагностика модуля АКНП2 на 4 месте
#define R0DE05LS2	 BUFFER[105]	//(R0DE05LS2) диагностика модуля АКНП2 на 5 месте
#define idR0DE05LS2	 35	//(R0DE05LS2) диагностика модуля АКНП2 на 5 месте
#define TTLaknp2	 BUFFER[108]	//(TTLaknp2) TTL
#define idTTLaknp2	 36	//(TTLaknp2) TTL
#define R0DE31LS2	 BUFFER[111]	//(R0DE31LS2) диагностика шкафа АКНП2 сеть 1
#define idR0DE31LS2	 37	//(R0DE31LS2) диагностика шкафа АКНП2 сеть 1
#define R0DE32LS2	 BUFFER[113]	//(R0DE32LS2) диагностика шкафа АКНП2 сеть 2
#define idR0DE32LS2	 38	//(R0DE32LS2) диагностика шкафа АКНП2 сеть 2
#define R0DE33LS2	 BUFFER[115]	//(R0DE33LS2) диагностика шкафа АКНП2 двери
#define idR0DE33LS2	 39	//(R0DE33LS2) диагностика шкафа АКНП2 двери
#define R0DE34LS2	 BUFFER[117]	//(R0DE34LS2) диагностика шкафа АКНП2 температура меньше 43
#define idR0DE34LS2	 40	//(R0DE34LS2) диагностика шкафа АКНП2 температура меньше 43
#define R0DE35LS2	 BUFFER[119]	//(R0DE35LS2) диагностика шкафа АКНП2 температура больше 53
#define idR0DE35LS2	 41	//(R0DE35LS2) диагностика шкафа АКНП2 температура больше 53
#define R0DE36LS2	 BUFFER[121]	//(R0DE36LS2) диагностика шкафа АКНП2 МП15-3.1 место 1
#define idR0DE36LS2	 42	//(R0DE36LS2) диагностика шкафа АКНП2 МП15-3.1 место 1
#define R0DE37LS2	 BUFFER[123]	//(R0DE37LS2) диагностика шкафа АКНП2 МП15-3.1 место 2
#define idR0DE37LS2	 43	//(R0DE37LS2) диагностика шкафа АКНП2 МП15-3.1 место 2
#define R0DE38LS2	 BUFFER[125]	//(R0DE38LS2) диагностика шкафа АКНП2 МП15-3 место 3
#define idR0DE38LS2	 44	//(R0DE38LS2) диагностика шкафа АКНП2 МП15-3 место 3
#define R0DE39LS2	 BUFFER[127]	//(R0DE39LS2) диагностика шкафа АКНП2 МП24-2 место 4
#define idR0DE39LS2	 45	//(R0DE39LS2) диагностика шкафа АКНП2 МП24-2 место 4
#define R0DE3ALS2	 BUFFER[129]	//(R0DE3ALS2) диагностика шкафа АКНП2 БП5/24Д место 5
#define idR0DE3ALS2	 46	//(R0DE3ALS2) диагностика шкафа АКНП2 БП5/24Д место 5
#define R0DE3BLS2	 BUFFER[131]	//(R0DE3BLS2) диагностика шкафа АКНП2 БП5/24Д место 6
#define idR0DE3BLS2	 47	//(R0DE3BLS2) диагностика шкафа АКНП2 БП5/24Д место 6
#define R0DE3CLS2	 BUFFER[133]	//(R0DE3CLS2) диагностика шкафа АКНП2 БП5/24Д место 7
#define idR0DE3CLS2	 48	//(R0DE3CLS2) диагностика шкафа АКНП2 БП5/24Д место 7
#define R0DE3DLS2	 BUFFER[135]	//(R0DE3DLS2) диагностика шкафа АКНП2 БП5/24Д место 8
#define idR0DE3DLS2	 49	//(R0DE3DLS2) диагностика шкафа АКНП2 БП5/24Д место 8
#define TestDiagnAKNP2	 BUFFER[137]	//(TestDiagnAKNP2) Неисправность от диагностики
#define idTestDiagnAKNP2	 50	//(TestDiagnAKNP2) Неисправность от диагностики
#define fEM_R0UR01RSS	 BUFFER[139]	//(R0UR01RSS) Уставка АКНП блокировки автоматического подъёма ББ(имп/сек)
#define idfEM_R0UR01RSS	 51	//(R0UR01RSS) Уставка АКНП блокировки автоматического подъёма ББ(имп/сек)
#define fEM_R0UL52RSS	 BUFFER[144]	//(R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	 52	//(R0UL52RSS) Уровень АС по мощности
#define fEM_R0UL41RSS	 BUFFER[149]	//(R0UL41RSS) Уровень ПС по периоду разгона
#define idfEM_R0UL41RSS	 53	//(R0UL41RSS) Уровень ПС по периоду разгона
#define fEM_R0UL51RSS	 BUFFER[154]	//(R0UL51RSS) Уровень АС по периоду разгона
#define idfEM_R0UL51RSS	 54	//(R0UL51RSS) Уровень АС по периоду разгона
#define fEM_R0UH02RSS	 BUFFER[159]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define idfEM_R0UH02RSS	 55	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define fEM_R0UH03RSS	 BUFFER[164]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define idfEM_R0UH03RSS	 56	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define fEM_R0UL42RSS	 BUFFER[169]	//(R0UL42RSS) Уровень ПС по мощности
#define idfEM_R0UL42RSS	 57	//(R0UL42RSS) Уровень ПС по мощности
#define fEM_R7UX00RSS	 BUFFER[174]	//(R7UX00RSS) X-координата АЗ1 (см)
#define idfEM_R7UX00RSS	 58	//(R7UX00RSS) X-координата АЗ1 (см)
#define fEM_R7UX04RSS	 BUFFER[179]	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define idfEM_R7UX04RSS	 59	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define fEM_R7UX05RSS	 BUFFER[184]	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define idfEM_R7UX05RSS	 60	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define fEM_R7UX06RSS	 BUFFER[189]	//(R7UX06RSS) Y-координата камеры R7IN23 (см)
#define idfEM_R7UX06RSS	 61	//(R7UX06RSS) Y-координата камеры R7IN23 (см)
#define fEM_R7UY00RSS	 BUFFER[194]	//(R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	 62	//(R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UY04RSS	 BUFFER[199]	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define idfEM_R7UY04RSS	 63	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define fEM_R7UY05RSS	 BUFFER[204]	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define idfEM_R7UY05RSS	 64	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define fEM_R7UY06RSS	 BUFFER[209]	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define idfEM_R7UY06RSS	 65	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define fEM_A0UX00RSS	 BUFFER[214]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 66	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX04RSS	 BUFFER[219]	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define idfEM_A0UX04RSS	 67	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define fEM_A0UX05RSS	 BUFFER[224]	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define idfEM_A0UX05RSS	 68	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define fEM_A0UX06RSS	 BUFFER[229]	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define idfEM_A0UX06RSS	 69	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define fEM_B0UX04RSS	 BUFFER[234]	//(B0UX04RSS) Второй коэффициент калибровки камеры4
#define idfEM_B0UX04RSS	 70	//(B0UX04RSS) Второй коэффициент калибровки камеры4
#define fEM_B0UX05RSS	 BUFFER[239]	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	 71	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_B0UX06RSS	 BUFFER[244]	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define idfEM_B0UX06RSS	 72	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define fEM_R0UH05RSS	 BUFFER[249]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 73	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define iEM_R0UL01ISS	 BUFFER[254]	//(R0UL01ISS) Шаг (мс) измерения периода
#define idiEM_R0UL01ISS	 74	//(R0UL01ISS) Шаг (мс) измерения периода
#define dEM_R0UL02USS	 BUFFER[257]	//(R0UL02USS) Предельное время ожидания роста потока (мс)
#define iddEM_R0UL02USS	 75	//(R0UL02USS) Предельное время ожидания роста потока (мс)
#define fEM_R0UN03RSS	 BUFFER[262]	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN03RSS	 76	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define bFirstEnterFlag	 BUFFER[267]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 77	//(bFirstEnterFlag) 
#define internal1_m15_Nk	 BUFFER[269]	//(internal1_m15_Nk) Nk - ведущая камера
#define idinternal1_m15_Nk	 78	//(internal1_m15_Nk) Nk - ведущая камера
#define internal1_m45_tst	 BUFFER[272]	//(internal1_m45_tst) - массив времени фиксации стартовой мощности
#define idinternal1_m45_tst	 79	//(internal1_m45_tst) - массив времени фиксации стартовой мощности
#define internal1_m45_trz	 BUFFER[297]	//(internal1_m45_trz) - массив времени фиксации очередного периода
#define idinternal1_m45_trz	 80	//(internal1_m45_trz) - массив времени фиксации очередного периода
#define internal1_m45_N1	 BUFFER[322]	//(internal1_m45_N1) - массив значения мощности в начале замера
#define idinternal1_m45_N1	 81	//(internal1_m45_N1) - массив значения мощности в начале замера
#define internal1_m45_N2	 BUFFER[347]	//(internal1_m45_N2) - массив значения мощности в конце замера
#define idinternal1_m45_N2	 82	//(internal1_m45_N2) - массив значения мощности в конце замера
#define internal1_m45_Period0	 BUFFER[372]	//(internal1_m45_Period0) Per - Период разгона РУ
#define idinternal1_m45_Period0	 83	//(internal1_m45_Period0) Per - Период разгона РУ
#define internal1_m45_MyFirstEnterFlag	 BUFFER[377]	//(internal1_m45_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m45_MyFirstEnterFlag	 84	//(internal1_m45_MyFirstEnterFlag)  FirstEnterFlag
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,8	,1	, &R0VN02RS2},	//(R0VN02RS2) Уровень мощности канал 2
	{ 2	,8	,1	, &R0VN01RS2},	//(R0VN01RS2) Период разгона канал 2
	{ 3	,1	,1	, &R0VN61LS2},	//(R0VN61LS2) ПС по мощности канал 2
	{ 4	,1	,1	, &R0VN72LZ1},	//(R0VN72LZ1) АС по мощности канал 2 на БАЗ1
	{ 5	,1	,1	, &R0VN65LS2},	//(R0VN65LS2) ПС по периоду разгона канал 2
	{ 6	,1	,1	, &R0VN76LZ1},	//(R0VN76LZ1) АС по периоду разгона канал 2  на БАЗ1
	{ 7	,1	,1	, &A0EE01LS2},	//(A0EE01LS2) Исправность АКНП канал 2 на БАЗ1
	{ 8	,8	,1	, &R0IN01FS2},	//(R0IN01FS2) Выход СНМ-11 Гц
	{ 9	,8	,1	, &R0IN02FS2},	//(R0IN02FS2) Выход КНК15-1  Гц
	{ 10	,8	,1	, &R0VN03RS2},	//(R0VN03RS2) Измеренный нейтронный поток канал 2
	{ 11	,8	,1	, &R0VN04RS2},	//(R0VN04RS2) Реактивность канал 2
	{ 12	,1	,1	, &A1VN71LS2},	//(A1VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ2
	{ 13	,8	,1	, &R0IN03FS2},	//(R0IN03FS2) Выход КНК53М Гц
	{ 14	,1	,1	, &A0EE02LS2},	//(A0EE02LS2) Исправность АКНП2 (от сшивки каналов) канал 2
	{ 15	,1	,1	, &R0IE11LS2},	//(R0IE11LS2) Исправность ВИП 1,6 (№11) СНМ11 2канала
	{ 16	,1	,1	, &R0IE12LS2},	//(R0IE12LS2) Исправность ВИП 0,5 (№12) КНК15-1 2 канала
	{ 17	,1	,1	, &R0IE13LS2},	//(R0IE13LS2) Исправность ВИП 0,5 (№13) КНК53М 2 канала
	{ 18	,8	,1	, &R0VN13RS2},	//(R0VN13RS2) Нейтронный поток по камере СНМ11 канал 2
	{ 19	,8	,1	, &R0VN23RS2},	//(R0VN23RS2) Нейтронный поток по камере КНК15-1 канал 2
	{ 20	,8	,1	, &R0VN33RS2},	//(R0VN33RS2) Нейтронный поток по камере КНК53М канал 2
	{ 21	,3	,1	, &R0VN15RS2},	//(R0VN15RS2) Номер ведущей камеры канал 2
	{ 22	,1	,1	, &A0EE03LS2},	//(A0EE03LS2) Подключена сеть питания АКНП канал 2
	{ 23	,1	,1	, &R0IE01LS2},	//(R0IE01LS2) Отключение питание детекторов канал 2
	{ 24	,1	,1	, &R0IE02LS2},	//(R0IE02LS2) Отключить питание ПР, ПУ канал 2
	{ 25	,1	,1	, &R0VN72LZ2},	//(R0VN72LZ2) АС по мощности канал 2 на БАЗ2
	{ 26	,1	,1	, &R0VN76LZ2},	//(R0VN76LZ2) АС по периоду разгона канал 2  на БАЗ2
	{ 27	,1	,1	, &A1EE01LS2},	//(A1EE01LS2) Исправность АКНП канал 2 на БАЗ2
	{ 28	,1	,1	, &A0VN71LS2},	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ1
	{ 29	,8	,1	, &B8VC01RDU},	//(B8VC01RDU) Координата АЗ2, мм
	{ 30	,1	,1	, &R0EE02LZ1},	//(R0EE02LZ1) Питание  АКНП  отключить
	{ 31	,1	,1	, &R0EE02LZ2},	//(R0EE02LZ2) Питание  АКНП  отключить
	{ 32	,3	,1	, &R0DE01LS2},	//(R0DE01LS2) диагностика модуля АКНП2 на 1 месте
	{ 33	,3	,1	, &R0DE02LS2},	//(R0DE02LS2) диагностика модуля АКНП2 на 2 месте
	{ 34	,3	,1	, &R0DE04LS2},	//(R0DE04LS2) диагностика модуля АКНП2 на 4 месте
	{ 35	,3	,1	, &R0DE05LS2},	//(R0DE05LS2) диагностика модуля АКНП2 на 5 месте
	{ 36	,3	,1	, &TTLaknp2},	//(TTLaknp2) TTL
	{ 37	,1	,1	, &R0DE31LS2},	//(R0DE31LS2) диагностика шкафа АКНП2 сеть 1
	{ 38	,1	,1	, &R0DE32LS2},	//(R0DE32LS2) диагностика шкафа АКНП2 сеть 2
	{ 39	,1	,1	, &R0DE33LS2},	//(R0DE33LS2) диагностика шкафа АКНП2 двери
	{ 40	,1	,1	, &R0DE34LS2},	//(R0DE34LS2) диагностика шкафа АКНП2 температура меньше 43
	{ 41	,1	,1	, &R0DE35LS2},	//(R0DE35LS2) диагностика шкафа АКНП2 температура больше 53
	{ 42	,1	,1	, &R0DE36LS2},	//(R0DE36LS2) диагностика шкафа АКНП2 МП15-3.1 место 1
	{ 43	,1	,1	, &R0DE37LS2},	//(R0DE37LS2) диагностика шкафа АКНП2 МП15-3.1 место 2
	{ 44	,1	,1	, &R0DE38LS2},	//(R0DE38LS2) диагностика шкафа АКНП2 МП15-3 место 3
	{ 45	,1	,1	, &R0DE39LS2},	//(R0DE39LS2) диагностика шкафа АКНП2 МП24-2 место 4
	{ 46	,1	,1	, &R0DE3ALS2},	//(R0DE3ALS2) диагностика шкафа АКНП2 БП5/24Д место 5
	{ 47	,1	,1	, &R0DE3BLS2},	//(R0DE3BLS2) диагностика шкафа АКНП2 БП5/24Д место 6
	{ 48	,1	,1	, &R0DE3CLS2},	//(R0DE3CLS2) диагностика шкафа АКНП2 БП5/24Д место 7
	{ 49	,1	,1	, &R0DE3DLS2},	//(R0DE3DLS2) диагностика шкафа АКНП2 БП5/24Д место 8
	{ 50	,1	,1	, &TestDiagnAKNP2},	//(TestDiagnAKNP2) Неисправность от диагностики
	{ 51	,8	,1	, &fEM_R0UR01RSS},	//(R0UR01RSS) Уставка АКНП блокировки автоматического подъёма ББ(имп/сек)
	{ 52	,8	,1	, &fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{ 53	,8	,1	, &fEM_R0UL41RSS},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{ 54	,8	,1	, &fEM_R0UL51RSS},	//(R0UL51RSS) Уровень АС по периоду разгона
	{ 55	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{ 56	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{ 57	,8	,1	, &fEM_R0UL42RSS},	//(R0UL42RSS) Уровень ПС по мощности
	{ 58	,8	,1	, &fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{ 59	,8	,1	, &fEM_R7UX04RSS},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{ 60	,8	,1	, &fEM_R7UX05RSS},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{ 61	,8	,1	, &fEM_R7UX06RSS},	//(R7UX06RSS) Y-координата камеры R7IN23 (см)
	{ 62	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{ 63	,8	,1	, &fEM_R7UY04RSS},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{ 64	,8	,1	, &fEM_R7UY05RSS},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{ 65	,8	,1	, &fEM_R7UY06RSS},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{ 66	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 67	,8	,1	, &fEM_A0UX04RSS},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{ 68	,8	,1	, &fEM_A0UX05RSS},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{ 69	,8	,1	, &fEM_A0UX06RSS},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{ 70	,8	,1	, &fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры4
	{ 71	,8	,1	, &fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{ 72	,8	,1	, &fEM_B0UX06RSS},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{ 73	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 74	,3	,1	, &iEM_R0UL01ISS},	//(R0UL01ISS) Шаг (мс) измерения периода
	{ 75	,5	,1	, &dEM_R0UL02USS},	//(R0UL02USS) Предельное время ожидания роста потока (мс)
	{ 76	,8	,1	, &fEM_R0UN03RSS},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 77	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 78	,3	,1	, &internal1_m15_Nk},	//(internal1_m15_Nk) Nk - ведущая камера
	{ 79	,8	,5	, &internal1_m45_tst},	//(internal1_m45_tst) - массив времени фиксации стартовой мощности
	{ 80	,8	,5	, &internal1_m45_trz},	//(internal1_m45_trz) - массив времени фиксации очередного периода
	{ 81	,8	,5	, &internal1_m45_N1},	//(internal1_m45_N1) - массив значения мощности в начале замера
	{ 82	,8	,5	, &internal1_m45_N2},	//(internal1_m45_N2) - массив значения мощности в конце замера
	{ 83	,8	,1	, &internal1_m45_Period0},	//(internal1_m45_Period0) Per - Период разгона РУ
	{ 84	,1	,1	, &internal1_m45_MyFirstEnterFlag},	//(internal1_m45_MyFirstEnterFlag)  FirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="aknp2.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{51,"fEM_R0UR01RSS\0"}, 
{52,"fEM_R0UL52RSS\0"}, 
{53,"fEM_R0UL41RSS\0"}, 
{54,"fEM_R0UL51RSS\0"}, 
{55,"fEM_R0UH02RSS\0"}, 
{56,"fEM_R0UH03RSS\0"}, 
{57,"fEM_R0UL42RSS\0"}, 
{58,"fEM_R7UX00RSS\0"}, 
{59,"fEM_R7UX04RSS\0"}, 
{60,"fEM_R7UX05RSS\0"}, 
{61,"fEM_R7UX06RSS\0"}, 
{62,"fEM_R7UY00RSS\0"}, 
{63,"fEM_R7UY04RSS\0"}, 
{64,"fEM_R7UY05RSS\0"}, 
{65,"fEM_R7UY06RSS\0"}, 
{66,"fEM_A0UX00RSS\0"}, 
{67,"fEM_A0UX04RSS\0"}, 
{68,"fEM_A0UX05RSS\0"}, 
{69,"fEM_A0UX06RSS\0"}, 
{70,"fEM_B0UX04RSS\0"}, 
{71,"fEM_B0UX05RSS\0"}, 
{72,"fEM_B0UX06RSS\0"}, 
{73,"fEM_R0UH05RSS\0"}, 
{74,"iEM_R0UL01ISS\0"}, 
{75,"dEM_R0UL02USS\0"}, 
{76,"fEM_R0UN03RSS\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_AKNP2[]={  // 
	{&A0EE03LS2,1,0},	//(A0EE03LS2) Подключена сеть питания АКНП канал 2
	{&R0EE02LZ1,1,1},	//(R0EE02LZ1) Питание  АКНП  отключить
	{&R0EE02LZ2,1,2},	//(R0EE02LZ2) Питание  АКНП  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_AKNP2[]={  // 
	{&R0VN61LS2,1,0},	//(R0VN61LS2) ПС по мощности канал 2
	{&R0VN65LS2,1,1},	//(R0VN65LS2) ПС по периоду разгона канал 2
	{&A0EE02LS2,1,2},	//(A0EE02LS2) Исправность АКНП2 (от сшивки каналов) канал 2
	{&TestDiagnAKNP2,1,3},	//(TestDiagnAKNP2) Неисправность от диагностики
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_AKNP2[]={  // 
	{&R0VN02RS2,8,0},	//(R0VN02RS2) Уровень мощности канал 2
	{&R0VN01RS2,8,2},	//(R0VN01RS2) Период разгона канал 2
	{&R0IN01FS2,8,4},	//(R0IN01FS2) Выход СНМ-11 Гц
	{&R0IN02FS2,8,6},	//(R0IN02FS2) Выход КНК15-1  Гц
	{&R0VN03RS2,8,8},	//(R0VN03RS2) Измеренный нейтронный поток канал 2
	{&R0VN04RS2,8,10},	//(R0VN04RS2) Реактивность канал 2
	{&R0IN03FS2,8,12},	//(R0IN03FS2) Выход КНК53М Гц
	{&R0VN13RS2,8,14},	//(R0VN13RS2) Нейтронный поток по камере СНМ11 канал 2
	{&R0VN23RS2,8,16},	//(R0VN23RS2) Нейтронный поток по камере КНК15-1 канал 2
	{&R0VN33RS2,8,18},	//(R0VN33RS2) Нейтронный поток по камере КНК53М канал 2
	{&R0VN15RS2,3,20},	//(R0VN15RS2) Номер ведущей камеры канал 2
	{&TTLaknp2,3,21},	//(TTLaknp2) TTL
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_AKNP2[]={  // 
	{&B8VC01RDU,8,0},	//(B8VC01RDU) Координата АЗ2, мм
	{&fEM_R0UR01RSS,8,2},	//(R0UR01RSS) Уставка АКНП блокировки автоматического подъёма ББ(имп/сек)
	{&fEM_R0UL52RSS,8,4},	//(R0UL52RSS) Уровень АС по мощности
	{&fEM_R0UL41RSS,8,6},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{&fEM_R0UL51RSS,8,8},	//(R0UL51RSS) Уровень АС по периоду разгона
	{&fEM_R0UH02RSS,8,10},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{&fEM_R0UH03RSS,8,12},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{&fEM_R0UL42RSS,8,14},	//(R0UL42RSS) Уровень ПС по мощности
	{&fEM_R7UX00RSS,8,16},	//(R7UX00RSS) X-координата АЗ1 (см)
	{&fEM_R7UX04RSS,8,18},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{&fEM_R7UX05RSS,8,20},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{&fEM_R7UX06RSS,8,22},	//(R7UX06RSS) Y-координата камеры R7IN23 (см)
	{&fEM_R7UY00RSS,8,24},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{&fEM_R7UY04RSS,8,26},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{&fEM_R7UY05RSS,8,28},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{&fEM_R7UY06RSS,8,30},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{&fEM_A0UX00RSS,8,32},	//(A0UX00RSS) Эффективный радиус АЗ
	{&fEM_A0UX04RSS,8,34},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{&fEM_A0UX05RSS,8,36},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{&fEM_A0UX06RSS,8,38},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{&fEM_B0UX04RSS,8,40},	//(B0UX04RSS) Второй коэффициент калибровки камеры4
	{&fEM_B0UX05RSS,8,42},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{&fEM_B0UX06RSS,8,44},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{&fEM_R0UH05RSS,8,46},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{&iEM_R0UL01ISS,3,48},	//(R0UL01ISS) Шаг (мс) измерения периода
	{&dEM_R0UL02USS,5,49},	//(R0UL02USS) Предельное время ожидания роста потока (мс)
	{&fEM_R0UN03RSS,8,51},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_DiagnAKNP2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnAKNP2[]={  // 
	{&R0DE31LS2,1,0},	//(R0DE31LS2) диагностика шкафа АКНП2 сеть 1
	{&R0DE32LS2,1,1},	//(R0DE32LS2) диагностика шкафа АКНП2 сеть 2
	{&R0DE33LS2,1,2},	//(R0DE33LS2) диагностика шкафа АКНП2 двери
	{&R0DE34LS2,1,3},	//(R0DE34LS2) диагностика шкафа АКНП2 температура меньше 43
	{&R0DE35LS2,1,4},	//(R0DE35LS2) диагностика шкафа АКНП2 температура больше 53
	{&R0DE36LS2,1,5},	//(R0DE36LS2) диагностика шкафа АКНП2 МП15-3.1 место 1
	{&R0DE37LS2,1,6},	//(R0DE37LS2) диагностика шкафа АКНП2 МП15-3.1 место 2
	{&R0DE38LS2,1,7},	//(R0DE38LS2) диагностика шкафа АКНП2 МП15-3 место 3
	{&R0DE39LS2,1,8},	//(R0DE39LS2) диагностика шкафа АКНП2 МП24-2 место 4
	{&R0DE3ALS2,1,9},	//(R0DE3ALS2) диагностика шкафа АКНП2 БП5/24Д место 5
	{&R0DE3BLS2,1,10},	//(R0DE3BLS2) диагностика шкафа АКНП2 БП5/24Д место 6
	{&R0DE3CLS2,1,11},	//(R0DE3CLS2) диагностика шкафа АКНП2 БП5/24Д место 7
	{&R0DE3DLS2,1,12},	//(R0DE3DLS2) диагностика шкафа АКНП2 БП5/24Д место 8
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DiagnAKNP2[]={  // 
	{&R0DE01LS2,3,0},	//(R0DE01LS2) диагностика модуля АКНП2 на 1 месте
	{&R0DE02LS2,3,1},	//(R0DE02LS2) диагностика модуля АКНП2 на 2 месте
	{&R0DE04LS2,3,2},	//(R0DE04LS2) диагностика модуля АКНП2 на 4 месте
	{&R0DE05LS2,3,3},	//(R0DE05LS2) диагностика модуля АКНП2 на 5 месте
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DiagnAKNP2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_AKNP2[0],&di_AKNP2[0],&ir_AKNP2[0],&hr_AKNP2[0],NULL,NULL,NULL,0},	 //общий slave AKNP2
	{0,5003,&coil_DiagnAKNP2[0],&di_DiagnAKNP2[0],&ir_DiagnAKNP2[0],&hr_DiagnAKNP2[0],NULL,NULL,NULL,0},	 //Диагностика корзины АКНП2

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
	{&R0DE01LS2,3,10},
	{&R0IN01FS2,8,0},
	{&R0IN02FS2,8,5},
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
	{&R0IN03FS2,8,0},
	{&R0DE02LS2,3,10},
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
	{&R0DE04LS2,3,64},
	{&R0IE11LS2,1,0},
	{&R0IE12LS2,1,2},
	{&R0IE13LS2,1,4},
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
	{&R0DE05LS2,3,38},
	{&R0VN72LZ1,1,16},
	{&A0VN71LS2,1,22},
	{&A1EE01LS2,1,28},
	{&R0VN76LZ2,1,26},
	{&R0VN72LZ2,1,24},
	{&R0IE02LS2,1,0},
	{&R0IE01LS2,1,2},
	{&R0VN76LZ1,1,18},
	{&A0EE01LS2,1,20},
	{&A1VN71LS2,1,30},
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
	{&R0DE38LS2,1,14},
	{&R0DE37LS2,1,12},
	{&R0DE39LS2,1,16},
	{&R0DE3ALS2,1,18},
	{&R0DE36LS2,1,10},
	{&R0DE35LS2,1,8},
	{&R0DE34LS2,1,6},
	{&R0DE33LS2,1,4},
	{&R0DE32LS2,1,2},
	{&R0DE31LS2,1,0},
	{&R0DE3BLS2,1,20},
	{&R0DE3CLS2,1,22},
	{&R0DE3DLS2,1,24},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc4,0x01,12,58,def_buf_VCHS01,&table_VCHS01}, //VCHS01
	{0xc4,0x02,12,58,def_buf_VCHS02,&table_VCHS02}, //VCHS02
	{0xc2,0x04,15,66,def_buf_VDS32,&table_VDS32}, //VDS32
	{0x04,0x05,20,40,def_buf_FDS16,&table_FDS16}, //FDS16
	{0x01,0x20,4,26,def_buf_SBKFP,&table_SBKFP}, //SBKFP
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
	setAsFloat(51,5000);
	setAsFloat(52,5100);
	setAsFloat(53,30);
	setAsFloat(54,20.0);
	setAsFloat(55,3703.704 );
	setAsFloat(56,62500.0);
	setAsFloat(57,5000);
	setAsFloat(58,1567.36);
	setAsFloat(59,1555.0);
	setAsFloat(60,1269.0);
	setAsFloat(61,1269.0);
	setAsFloat(62,506.5);
	setAsFloat(63,248.0);
	setAsFloat(64,271.6);
	setAsFloat(65,287.2);
	setAsFloat(66,11.0);
	setAsFloat(67,1.0);
	setAsFloat(68,1.0);
	setAsFloat(69,1.0);
	setAsFloat(70,0);
	setAsFloat(71,0.0);
	setAsFloat(72,0);
	setAsFloat(73,32000.0);
	setAsShort(74,500);
	setAsInt(75,100000);
	setAsFloat(76,0.005);
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

uspaint8 InternalBuf[112];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_5_ = {5,0}; /* n - N-размерность массива входных параметров */ 
ssint iRM_2_ = {2,0}; /* n - N-размерность массива входных параметров */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 
sschar bRM_2_ = {2,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssint iRM_4_ = {4,0}; /*  */ 
ssint iRM_8_ = {8,0}; /*  */ 

uspaint8 SpaEEPROMBuf[128];

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
ssfloat var14;
ssbool var15;
ssbool var16;
ssbool var17;
ssbool var18;
ssbool var19;
ssbool var20;
ssbool var21;
ssbool var22;
ssfloat var23;
ssbool var24;
ssfloat var25;
ssfloat var26;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m88_x_1[8] = {&R0DE36LS2,&R0DE3CLS2,&R0DE37LS2,&R0DE38LS2,&R0DE39LS2,&R0DE3ALS2,&R0DE3BLS2,&R0DE3DLS2};
psint  array_m78_x_1[4] = {&R0DE01LS2,&R0DE02LS2,&R0DE04LS2,&R0DE05LS2};
psfloat  array_m45_tst_1[5];
psfloat  array_m45_trz_1[5];
psfloat  array_m45_N1_1[5];
psfloat  array_m45_N2_1[5];
psbool  array_m55_x_1[2] = {&var21,&var16};
psbool  array_m54_x_1[2] = {&var21,&var22};
psbool  array_m65_x_1[5] = {&var8,&R0IE11LS2,&R0IE12LS2,&R0IE13LS2,&A0EE03LS2};

/* Объявление структур */
_S_or3  S_or3_83_1 = {&var4,&var3,&var2,&var1};
_S_orn  S_orn_88_1 = {array_m88_x_1,&iRM_8_,&var2};
_S_and2  S_and2_79_1 = {&R0DE31LS2,&R0DE32LS2,&var3};
_S_diagndev  S_diagndev_78_1 = {array_m78_x_1,&iRM_4_,&var4,&var5};
_S_ocham  S_ocham_15_1 = {&R0IN01FS2,&R0IN02FS2,&R0IN03FS2,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX04RSS,&fEM_B0UX04RSS,&fEM_A0UX05RSS,&fEM_B0UX05RSS,&fEM_A0UX06RSS,&fEM_B0UX06RSS,&fEM_R7UX04RSS,&fEM_R7UY04RSS,&fEM_R7UX05RSS,&fEM_R7UY05RSS,&fEM_R7UX06RSS,&fEM_R7UY06RSS,&bRM_2_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var6,&var7,&var8,&var9,&var10,&var11,&var12,&internal1_m15_Nk};
_S_or2  S_or2_66_1 = {&R0EE02LZ1,&R0EE02LZ2,&var13};
_S_period  S_period_45_1 = {&var7,&var18,&iRM_5_,&var25,&var26,&fEM_R0UN03RSS,&var14,array_m45_tst_1,array_m45_trz_1,array_m45_N1_1,array_m45_N2_1,&internal1_m45_Period0,&internal1_m45_MyFirstEnterFlag};
_S_andn  S_andn_55_1 = {array_m55_x_1,&iRM_2_,&var15};
_S_bol  S_bol_52_1 = {&fEM_R0UL41RSS,&var14,&var16};
_S_andn  S_andn_54_1 = {array_m54_x_1,&iRM_2_,&var17};
_S_andn  S_andn_65_1 = {array_m65_x_1,&iRM_5_,&var18};
_S_bol  S_bol_35_1 = {&var7,&fEM_R0UL52RSS,&var19};
_S_bol  S_bol_40_1 = {&var7,&fEM_R0UL42RSS,&var20};
_S_bol  S_bol_51_1 = {&var7,&fEM_R0UN03RSS,&var21};
_S_bol  S_bol_50_1 = {&fEM_R0UL51RSS,&var14,&var22};
_S_react  S_react_46_1 = {&var14,&var23};
_S_bol  S_bol_31_1 = {&var7,&fEM_R0UR01RSS,&var24};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_66_1);
  ocham(&S_ocham_15_1);
  diagndev(&S_diagndev_78_1);
  and2(&S_and2_79_1);
  orn(&S_orn_88_1);
  or3(&S_or3_83_1);
  bol(&S_bol_31_1);
  bol(&S_bol_51_1);
  bol(&S_bol_40_1);
  bol(&S_bol_35_1);
  andn(&S_andn_65_1);
  setData(&var25,&iEM_R0UL01ISS);
  setData(&var26,&dEM_R0UL02USS);
  period(&S_period_45_1);
  react(&S_react_46_1);
  bol(&S_bol_50_1);
  andn(&S_andn_54_1);
  bol(&S_bol_52_1);
  andn(&S_andn_55_1);
  setData(idTestDiagnAKNP2,&var1);
  setData(idTTLaknp2,&var5);
  setData(idA0VN71LS2,&var24);
  setData(idA1EE01LS2,&var18);
  setData(idR0VN76LZ2,&var17);
  setData(idR0VN72LZ2,&var19);
  setData(idR0IE02LS2,&var13);
  setData(idR0IE01LS2,&var13);
  setData(idR0VN15RS2,&var12);
  setData(idR0VN33RS2,&var11);
  setData(idR0VN23RS2,&var10);
  setData(idR0VN13RS2,&var9);
  setData(idA0EE02LS2,&var8);
  setData(idA1VN71LS2,&var24);
  setData(idR0VN04RS2,&var23);
  setData(idR0VN03RS2,&var6);
  setData(idA0EE01LS2,&var18);
  setData(idR0VN76LZ1,&var17);
  setData(idR0VN65LS2,&var15);
  setData(idR0VN72LZ1,&var19);
  setData(idR0VN61LS2,&var20);
  setData(idR0VN01RS2,&var14);
  setData(idR0VN02RS2,&var7);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<5;i++ )
    array_m45_tst_1[i] = &(&internal1_m45_tst)[i*5];
  for( i=0;i<5;i++ )
    array_m45_trz_1[i] = &(&internal1_m45_trz)[i*5];
  for( i=0;i<5;i++ )
    array_m45_N1_1[i] = &(&internal1_m45_N1)[i*5];
  for( i=0;i<5;i++ )
    array_m45_N2_1[i] = &(&internal1_m45_N2)[i*5];
}

#endif
