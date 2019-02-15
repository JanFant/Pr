#ifndef AKNP3_H
#define AKNP3_H
// Подсистема AKNP3:AKNP3
static char SimulOn=0;
static short CodeSub=5;
static char SimulIP[]="192.168.1.17\0";
static int SimulPort=5555;
static int StepCycle=5;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 379
static char BUFFER[379];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.53\0", 5432, "192.168.10.153\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0VN73LZ2	 BUFFER[0]	//(R0VN73LZ2) АС по мощности канал 3 на БАЗ2
#define idR0VN73LZ2	 1	//(R0VN73LZ2) АС по мощности канал 3 на БАЗ2
#define R0VN77LZ2	 BUFFER[2]	//(R0VN77LZ2) АС по периоду разгона канал 3 на БАЗ2
#define idR0VN77LZ2	 2	//(R0VN77LZ2) АС по периоду разгона канал 3 на БАЗ2
#define A1EE01LS3	 BUFFER[4]	//(A1EE01LS3) Исправность АКНП канал 3 на БАЗ2
#define idA1EE01LS3	 3	//(A1EE01LS3) Исправность АКНП канал 3 на БАЗ2
#define B8VC01RDU	 BUFFER[6]	//(B8VC01RDU) Координата АЗ2, мм
#define idB8VC01RDU	 4	//(B8VC01RDU) Координата АЗ2, мм
#define R0EE03LZ1	 BUFFER[11]	//(R0EE03LZ1) Питание  АКНП3  отключить
#define idR0EE03LZ1	 5	//(R0EE03LZ1) Питание  АКНП3  отключить
#define R0EE03LZ2	 BUFFER[13]	//(R0EE03LZ2) Питание  АКНП3  отключить
#define idR0EE03LZ2	 6	//(R0EE03LZ2) Питание  АКНП3  отключить
#define R0DE01LS3	 BUFFER[15]	//(R0DE01LS3) диагностика модуля АКНП3 на 1 месте
#define idR0DE01LS3	 7	//(R0DE01LS3) диагностика модуля АКНП3 на 1 месте
#define R0DE02LS3	 BUFFER[18]	//(R0DE02LS3) диагностика модуля АКНП3 на 2 месте
#define idR0DE02LS3	 8	//(R0DE02LS3) диагностика модуля АКНП3 на 2 месте
#define R0DE04LS3	 BUFFER[21]	//(R0DE04LS3) диагностика модуля АКНП3 на 4 месте
#define idR0DE04LS3	 9	//(R0DE04LS3) диагностика модуля АКНП3 на 4 месте
#define R0DE05LS3	 BUFFER[24]	//(R0DE05LS3) диагностика модуля АКНП3 на 5 месте
#define idR0DE05LS3	 10	//(R0DE05LS3) диагностика модуля АКНП3 на 5 месте
#define R0DE31LS3	 BUFFER[27]	//(R0DE31LS3) диагностика шкафа АКНП3 сеть 1
#define idR0DE31LS3	 11	//(R0DE31LS3) диагностика шкафа АКНП3 сеть 1
#define R0DE32LS3	 BUFFER[29]	//(R0DE32LS3) диагностика шкафа АКНП3 сеть 2
#define idR0DE32LS3	 12	//(R0DE32LS3) диагностика шкафа АКНП3 сеть 2
#define R0DE33LS3	 BUFFER[31]	//(R0DE33LS3) диагностика шкафа АКНП3 двери
#define idR0DE33LS3	 13	//(R0DE33LS3) диагностика шкафа АКНП3 двери
#define R0DE34LS3	 BUFFER[33]	//(R0DE34LS3) диагностика шкафа АКНП3 температура меньше 43
#define idR0DE34LS3	 14	//(R0DE34LS3) диагностика шкафа АКНП3 температура меньше 43
#define R0DE35LS3	 BUFFER[35]	//(R0DE35LS3) диагностика шкафа АКНП3 температура больше 53
#define idR0DE35LS3	 15	//(R0DE35LS3) диагностика шкафа АКНП3 температура больше 53
#define R0DE36LS3	 BUFFER[37]	//(R0DE36LS3) диагностика шкафа АКНП3 МП15-3.1 место 1
#define idR0DE36LS3	 16	//(R0DE36LS3) диагностика шкафа АКНП3 МП15-3.1 место 1
#define R0DE37LS3	 BUFFER[39]	//(R0DE37LS3) диагностика шкафа АКНП3 МП15-3.1 место 2
#define idR0DE37LS3	 17	//(R0DE37LS3) диагностика шкафа АКНП3 МП15-3.1 место 2
#define R0DE38LS3	 BUFFER[41]	//(R0DE38LS3) диагностика шкафа АКНП3 МП15-3 место 3
#define idR0DE38LS3	 18	//(R0DE38LS3) диагностика шкафа АКНП3 МП15-3 место 3
#define R0DE39LS3	 BUFFER[43]	//(R0DE39LS3) диагностика шкафа АКНП3 МП24-2 место 4
#define idR0DE39LS3	 19	//(R0DE39LS3) диагностика шкафа АКНП3 МП24-2 место 4
#define R0DE3ALS3	 BUFFER[45]	//(R0DE3ALS3) диагностика шкафа АКНП3 БП5/24Д место 5
#define idR0DE3ALS3	 20	//(R0DE3ALS3) диагностика шкафа АКНП3 БП5/24Д место 5
#define R0DE3BLS3	 BUFFER[47]	//(R0DE3BLS3) диагностика шкафа АКНП3 БП5/24Д место 6
#define idR0DE3BLS3	 21	//(R0DE3BLS3) диагностика шкафа АКНП3 БП5/24Д место 6
#define R0DE3CLS3	 BUFFER[49]	//(R0DE3CLS3) диагностика шкафа АКНП3 БП5/24Д место 7
#define idR0DE3CLS3	 22	//(R0DE3CLS3) диагностика шкафа АКНП3 БП5/24Д место 7
#define R0DE3DLS3	 BUFFER[51]	//(R0DE3DLS3) диагностика шкафа АКНП3 БП5/24Д место 8
#define idR0DE3DLS3	 23	//(R0DE3DLS3) диагностика шкафа АКНП3 БП5/24Д место 8
#define TTLaknp3	 BUFFER[53]	//(TTLaknp3) ttl
#define idTTLaknp3	 24	//(TTLaknp3) ttl
#define TestDiagnAKNP3	 BUFFER[56]	//(TestDiagnAKNP3) Неисправность от диагностики
#define idTestDiagnAKNP3	 25	//(TestDiagnAKNP3) Неисправность от диагностики
#define R0VN02RS3	 BUFFER[58]	//(R0VN02RS3) Уровень мощности канал 3
#define idR0VN02RS3	 26	//(R0VN02RS3) Уровень мощности канал 3
#define R0VN01RS3	 BUFFER[63]	//(R0VN01RS3) Период разгона канал 3
#define idR0VN01RS3	 27	//(R0VN01RS3) Период разгона канал 3
#define R0VN61LS3	 BUFFER[68]	//(R0VN61LS3) ПС по мощности канал 3
#define idR0VN61LS3	 28	//(R0VN61LS3) ПС по мощности канал 3
#define R0VN73LZ1	 BUFFER[70]	//(R0VN73LZ1) АС по мощности канал 3 на БАЗ1
#define idR0VN73LZ1	 29	//(R0VN73LZ1) АС по мощности канал 3 на БАЗ1
#define R0VN65LS3	 BUFFER[72]	//(R0VN65LS3) ПС по периоду разгона канал 3
#define idR0VN65LS3	 30	//(R0VN65LS3) ПС по периоду разгона канал 3
#define R0VN77LZ1	 BUFFER[74]	//(R0VN77LZ1) АС по периоду разгона канал 3 на БАЗ1
#define idR0VN77LZ1	 31	//(R0VN77LZ1) АС по периоду разгона канал 3 на БАЗ1
#define A0EE01LS3	 BUFFER[76]	//(A0EE01LS3) Исправность АКНП канал 3 на БАЗ1
#define idA0EE01LS3	 32	//(A0EE01LS3) Исправность АКНП канал 3 на БАЗ1
#define R0IN01FS3	 BUFFER[78]	//(R0IN01FS3) Выход СНМ-11 Гц
#define idR0IN01FS3	 33	//(R0IN01FS3) Выход СНМ-11 Гц
#define R0IN02FS3	 BUFFER[83]	//(R0IN02FS3) Выход КНК15-1 Гц
#define idR0IN02FS3	 34	//(R0IN02FS3) Выход КНК15-1 Гц
#define R0VN03RS3	 BUFFER[88]	//(R0VN03RS3) Измеренный нейтронный поток канал 3
#define idR0VN03RS3	 35	//(R0VN03RS3) Измеренный нейтронный поток канал 3
#define R0VN04RS3	 BUFFER[93]	//(R0VN04RS3) Реактивность канал 3
#define idR0VN04RS3	 36	//(R0VN04RS3) Реактивность канал 3
#define A1VN71LS3	 BUFFER[98]	//(A1VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
#define idA1VN71LS3	 37	//(A1VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
#define R0IN03FS3	 BUFFER[100]	//(R0IN03FS3) Выход КНК53М Гц
#define idR0IN03FS3	 38	//(R0IN03FS3) Выход КНК53М Гц
#define A0EE02LS3	 BUFFER[105]	//(A0EE02LS3) Исправность АКНП3 (от сшивки каналов) канал 3
#define idA0EE02LS3	 39	//(A0EE02LS3) Исправность АКНП3 (от сшивки каналов) канал 3
#define R0IE11LS3	 BUFFER[107]	//(R0IE11LS3) Исправность ВИП 1,6 (№14) СНМ11 3 канала
#define idR0IE11LS3	 40	//(R0IE11LS3) Исправность ВИП 1,6 (№14) СНМ11 3 канала
#define R0IE12LS3	 BUFFER[109]	//(R0IE12LS3) Исправность ВИП 0,5 (№15) КНК15-1 3 канала
#define idR0IE12LS3	 41	//(R0IE12LS3) Исправность ВИП 0,5 (№15) КНК15-1 3 канала
#define R0IE13LS3	 BUFFER[111]	//(R0IE13LS3) Исправность ВИП 0,5 (№16) КНК53М 3 канала
#define idR0IE13LS3	 42	//(R0IE13LS3) Исправность ВИП 0,5 (№16) КНК53М 3 канала
#define R0VN13RS3	 BUFFER[113]	//(R0VN13RS3) Нейтронный поток по камере СНМ11 канал 3
#define idR0VN13RS3	 43	//(R0VN13RS3) Нейтронный поток по камере СНМ11 канал 3
#define R0VN23RS3	 BUFFER[118]	//(R0VN23RS3) Нейтронный поток по камере КНК15-1 канал 3
#define idR0VN23RS3	 44	//(R0VN23RS3) Нейтронный поток по камере КНК15-1 канал 3
#define R0VN33RS3	 BUFFER[123]	//(R0VN33RS3) Нейтронный поток по камере КНК53М канал 3
#define idR0VN33RS3	 45	//(R0VN33RS3) Нейтронный поток по камере КНК53М канал 3
#define R0VN15RS3	 BUFFER[128]	//(R0VN15RS3) Номер ведущей камеры канал 3
#define idR0VN15RS3	 46	//(R0VN15RS3) Номер ведущей камеры канал 3
#define A0EE03LS3	 BUFFER[131]	//(A0EE03LS3) Подключена сеть питания АКНП канал 3
#define idA0EE03LS3	 47	//(A0EE03LS3) Подключена сеть питания АКНП канал 3
#define R0IE01LS3	 BUFFER[133]	//(R0IE01LS3) Отключение питание детекторов канал 3
#define idR0IE01LS3	 48	//(R0IE01LS3) Отключение питание детекторов канал 3
#define R0IE02LS3	 BUFFER[135]	//(R0IE02LS3) Отключить питание ПР, ПУ канал 3
#define idR0IE02LS3	 49	//(R0IE02LS3) Отключить питание ПР, ПУ канал 3
#define A0VN71LS3	 BUFFER[137]	//(A0VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
#define idA0VN71LS3	 50	//(A0VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
#define fEM_R0UR01RSS	 BUFFER[139]	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RSS	 51	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
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
#define fEM_R7UX07RSS	 BUFFER[179]	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define idfEM_R7UX07RSS	 59	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define fEM_R7UX08RSS	 BUFFER[184]	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define idfEM_R7UX08RSS	 60	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define fEM_R7UX09RSS	 BUFFER[189]	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define idfEM_R7UX09RSS	 61	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define fEM_R7UY00RSS	 BUFFER[194]	//(R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	 62	//(R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UY07RSS	 BUFFER[199]	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define idfEM_R7UY07RSS	 63	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define fEM_R7UY08RSS	 BUFFER[204]	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define idfEM_R7UY08RSS	 64	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define fEM_R7UY09RSS	 BUFFER[209]	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define idfEM_R7UY09RSS	 65	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define fEM_A0UX00RSS	 BUFFER[214]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 66	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX07RSS	 BUFFER[219]	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define idfEM_A0UX07RSS	 67	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define fEM_A0UX08RSS	 BUFFER[224]	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define idfEM_A0UX08RSS	 68	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define fEM_A0UX09RSS	 BUFFER[229]	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define idfEM_A0UX09RSS	 69	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define fEM_B0UX07RSS	 BUFFER[234]	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define idfEM_B0UX07RSS	 70	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define fEM_B0UX08RSS	 BUFFER[239]	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define idfEM_B0UX08RSS	 71	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define fEM_B0UX09RSS	 BUFFER[244]	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define idfEM_B0UX09RSS	 72	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
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
#define internal1_m17_Nk	 BUFFER[269]	//(internal1_m17_Nk) Nk - ведущая камера
#define idinternal1_m17_Nk	 78	//(internal1_m17_Nk) Nk - ведущая камера
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
	{ 1	,1	,1	, &R0VN73LZ2},	//(R0VN73LZ2) АС по мощности канал 3 на БАЗ2
	{ 2	,1	,1	, &R0VN77LZ2},	//(R0VN77LZ2) АС по периоду разгона канал 3 на БАЗ2
	{ 3	,1	,1	, &A1EE01LS3},	//(A1EE01LS3) Исправность АКНП канал 3 на БАЗ2
	{ 4	,8	,1	, &B8VC01RDU},	//(B8VC01RDU) Координата АЗ2, мм
	{ 5	,1	,1	, &R0EE03LZ1},	//(R0EE03LZ1) Питание  АКНП3  отключить
	{ 6	,1	,1	, &R0EE03LZ2},	//(R0EE03LZ2) Питание  АКНП3  отключить
	{ 7	,3	,1	, &R0DE01LS3},	//(R0DE01LS3) диагностика модуля АКНП3 на 1 месте
	{ 8	,3	,1	, &R0DE02LS3},	//(R0DE02LS3) диагностика модуля АКНП3 на 2 месте
	{ 9	,3	,1	, &R0DE04LS3},	//(R0DE04LS3) диагностика модуля АКНП3 на 4 месте
	{ 10	,3	,1	, &R0DE05LS3},	//(R0DE05LS3) диагностика модуля АКНП3 на 5 месте
	{ 11	,1	,1	, &R0DE31LS3},	//(R0DE31LS3) диагностика шкафа АКНП3 сеть 1
	{ 12	,1	,1	, &R0DE32LS3},	//(R0DE32LS3) диагностика шкафа АКНП3 сеть 2
	{ 13	,1	,1	, &R0DE33LS3},	//(R0DE33LS3) диагностика шкафа АКНП3 двери
	{ 14	,1	,1	, &R0DE34LS3},	//(R0DE34LS3) диагностика шкафа АКНП3 температура меньше 43
	{ 15	,1	,1	, &R0DE35LS3},	//(R0DE35LS3) диагностика шкафа АКНП3 температура больше 53
	{ 16	,1	,1	, &R0DE36LS3},	//(R0DE36LS3) диагностика шкафа АКНП3 МП15-3.1 место 1
	{ 17	,1	,1	, &R0DE37LS3},	//(R0DE37LS3) диагностика шкафа АКНП3 МП15-3.1 место 2
	{ 18	,1	,1	, &R0DE38LS3},	//(R0DE38LS3) диагностика шкафа АКНП3 МП15-3 место 3
	{ 19	,1	,1	, &R0DE39LS3},	//(R0DE39LS3) диагностика шкафа АКНП3 МП24-2 место 4
	{ 20	,1	,1	, &R0DE3ALS3},	//(R0DE3ALS3) диагностика шкафа АКНП3 БП5/24Д место 5
	{ 21	,1	,1	, &R0DE3BLS3},	//(R0DE3BLS3) диагностика шкафа АКНП3 БП5/24Д место 6
	{ 22	,1	,1	, &R0DE3CLS3},	//(R0DE3CLS3) диагностика шкафа АКНП3 БП5/24Д место 7
	{ 23	,1	,1	, &R0DE3DLS3},	//(R0DE3DLS3) диагностика шкафа АКНП3 БП5/24Д место 8
	{ 24	,3	,1	, &TTLaknp3},	//(TTLaknp3) ttl
	{ 25	,1	,1	, &TestDiagnAKNP3},	//(TestDiagnAKNP3) Неисправность от диагностики
	{ 26	,8	,1	, &R0VN02RS3},	//(R0VN02RS3) Уровень мощности канал 3
	{ 27	,8	,1	, &R0VN01RS3},	//(R0VN01RS3) Период разгона канал 3
	{ 28	,1	,1	, &R0VN61LS3},	//(R0VN61LS3) ПС по мощности канал 3
	{ 29	,1	,1	, &R0VN73LZ1},	//(R0VN73LZ1) АС по мощности канал 3 на БАЗ1
	{ 30	,1	,1	, &R0VN65LS3},	//(R0VN65LS3) ПС по периоду разгона канал 3
	{ 31	,1	,1	, &R0VN77LZ1},	//(R0VN77LZ1) АС по периоду разгона канал 3 на БАЗ1
	{ 32	,1	,1	, &A0EE01LS3},	//(A0EE01LS3) Исправность АКНП канал 3 на БАЗ1
	{ 33	,8	,1	, &R0IN01FS3},	//(R0IN01FS3) Выход СНМ-11 Гц
	{ 34	,8	,1	, &R0IN02FS3},	//(R0IN02FS3) Выход КНК15-1 Гц
	{ 35	,8	,1	, &R0VN03RS3},	//(R0VN03RS3) Измеренный нейтронный поток канал 3
	{ 36	,8	,1	, &R0VN04RS3},	//(R0VN04RS3) Реактивность канал 3
	{ 37	,1	,1	, &A1VN71LS3},	//(A1VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
	{ 38	,8	,1	, &R0IN03FS3},	//(R0IN03FS3) Выход КНК53М Гц
	{ 39	,1	,1	, &A0EE02LS3},	//(A0EE02LS3) Исправность АКНП3 (от сшивки каналов) канал 3
	{ 40	,1	,1	, &R0IE11LS3},	//(R0IE11LS3) Исправность ВИП 1,6 (№14) СНМ11 3 канала
	{ 41	,1	,1	, &R0IE12LS3},	//(R0IE12LS3) Исправность ВИП 0,5 (№15) КНК15-1 3 канала
	{ 42	,1	,1	, &R0IE13LS3},	//(R0IE13LS3) Исправность ВИП 0,5 (№16) КНК53М 3 канала
	{ 43	,8	,1	, &R0VN13RS3},	//(R0VN13RS3) Нейтронный поток по камере СНМ11 канал 3
	{ 44	,8	,1	, &R0VN23RS3},	//(R0VN23RS3) Нейтронный поток по камере КНК15-1 канал 3
	{ 45	,8	,1	, &R0VN33RS3},	//(R0VN33RS3) Нейтронный поток по камере КНК53М канал 3
	{ 46	,3	,1	, &R0VN15RS3},	//(R0VN15RS3) Номер ведущей камеры канал 3
	{ 47	,1	,1	, &A0EE03LS3},	//(A0EE03LS3) Подключена сеть питания АКНП канал 3
	{ 48	,1	,1	, &R0IE01LS3},	//(R0IE01LS3) Отключение питание детекторов канал 3
	{ 49	,1	,1	, &R0IE02LS3},	//(R0IE02LS3) Отключить питание ПР, ПУ канал 3
	{ 50	,1	,1	, &A0VN71LS3},	//(A0VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
	{ 51	,8	,1	, &fEM_R0UR01RSS},	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
	{ 52	,8	,1	, &fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{ 53	,8	,1	, &fEM_R0UL41RSS},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{ 54	,8	,1	, &fEM_R0UL51RSS},	//(R0UL51RSS) Уровень АС по периоду разгона
	{ 55	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{ 56	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{ 57	,8	,1	, &fEM_R0UL42RSS},	//(R0UL42RSS) Уровень ПС по мощности
	{ 58	,8	,1	, &fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{ 59	,8	,1	, &fEM_R7UX07RSS},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{ 60	,8	,1	, &fEM_R7UX08RSS},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{ 61	,8	,1	, &fEM_R7UX09RSS},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{ 62	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{ 63	,8	,1	, &fEM_R7UY07RSS},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{ 64	,8	,1	, &fEM_R7UY08RSS},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{ 65	,8	,1	, &fEM_R7UY09RSS},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{ 66	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 67	,8	,1	, &fEM_A0UX07RSS},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{ 68	,8	,1	, &fEM_A0UX08RSS},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{ 69	,8	,1	, &fEM_A0UX09RSS},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{ 70	,8	,1	, &fEM_B0UX07RSS},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{ 71	,8	,1	, &fEM_B0UX08RSS},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{ 72	,8	,1	, &fEM_B0UX09RSS},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{ 73	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 74	,3	,1	, &iEM_R0UL01ISS},	//(R0UL01ISS) Шаг (мс) измерения периода
	{ 75	,5	,1	, &dEM_R0UL02USS},	//(R0UL02USS) Предельное время ожидания роста потока (мс)
	{ 76	,8	,1	, &fEM_R0UN03RSS},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 77	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 78	,3	,1	, &internal1_m17_Nk},	//(internal1_m17_Nk) Nk - ведущая камера
	{ 79	,8	,5	, &internal1_m45_tst},	//(internal1_m45_tst) - массив времени фиксации стартовой мощности
	{ 80	,8	,5	, &internal1_m45_trz},	//(internal1_m45_trz) - массив времени фиксации очередного периода
	{ 81	,8	,5	, &internal1_m45_N1},	//(internal1_m45_N1) - массив значения мощности в начале замера
	{ 82	,8	,5	, &internal1_m45_N2},	//(internal1_m45_N2) - массив значения мощности в конце замера
	{ 83	,8	,1	, &internal1_m45_Period0},	//(internal1_m45_Period0) Per - Период разгона РУ
	{ 84	,1	,1	, &internal1_m45_MyFirstEnterFlag},	//(internal1_m45_MyFirstEnterFlag)  FirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="aknp3.bin\0";   // Имя файла для сохранения констант
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
{59,"fEM_R7UX07RSS\0"}, 
{60,"fEM_R7UX08RSS\0"}, 
{61,"fEM_R7UX09RSS\0"}, 
{62,"fEM_R7UY00RSS\0"}, 
{63,"fEM_R7UY07RSS\0"}, 
{64,"fEM_R7UY08RSS\0"}, 
{65,"fEM_R7UY09RSS\0"}, 
{66,"fEM_A0UX00RSS\0"}, 
{67,"fEM_A0UX07RSS\0"}, 
{68,"fEM_A0UX08RSS\0"}, 
{69,"fEM_A0UX09RSS\0"}, 
{70,"fEM_B0UX07RSS\0"}, 
{71,"fEM_B0UX08RSS\0"}, 
{72,"fEM_B0UX09RSS\0"}, 
{73,"fEM_R0UH05RSS\0"}, 
{74,"iEM_R0UL01ISS\0"}, 
{75,"dEM_R0UL02USS\0"}, 
{76,"fEM_R0UN03RSS\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_AKNP3[]={  // 
	{&R0EE03LZ2,1,0},	//(R0EE03LZ2) Питание  АКНП3  отключить
	{&R0EE03LZ1,1,1},	//(R0EE03LZ1) Питание  АКНП3  отключить
	{&A0EE03LS3,1,2},	//(A0EE03LS3) Подключена сеть питания АКНП канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_AKNP3[]={  // 
	{&TestDiagnAKNP3,1,0},	//(TestDiagnAKNP3) Неисправность от диагностики
	{&A0EE02LS3,1,1},	//(A0EE02LS3) Исправность АКНП3 (от сшивки каналов) канал 3
	{&R0VN65LS3,1,2},	//(R0VN65LS3) ПС по периоду разгона канал 3
	{&R0VN61LS3,1,3},	//(R0VN61LS3) ПС по мощности канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_AKNP3[]={  // 
	{&TTLaknp3,3,0},	//(TTLaknp3) ttl
	{&R0VN15RS3,3,1},	//(R0VN15RS3) Номер ведущей камеры канал 3
	{&R0VN33RS3,8,2},	//(R0VN33RS3) Нейтронный поток по камере КНК53М канал 3
	{&R0VN23RS3,8,4},	//(R0VN23RS3) Нейтронный поток по камере КНК15-1 канал 3
	{&R0VN13RS3,8,6},	//(R0VN13RS3) Нейтронный поток по камере СНМ11 канал 3
	{&R0IN03FS3,8,8},	//(R0IN03FS3) Выход КНК53М Гц
	{&R0VN04RS3,8,10},	//(R0VN04RS3) Реактивность канал 3
	{&R0VN03RS3,8,12},	//(R0VN03RS3) Измеренный нейтронный поток канал 3
	{&R0IN02FS3,8,14},	//(R0IN02FS3) Выход КНК15-1 Гц
	{&R0IN01FS3,8,16},	//(R0IN01FS3) Выход СНМ-11 Гц
	{&R0VN01RS3,8,18},	//(R0VN01RS3) Период разгона канал 3
	{&R0VN02RS3,8,20},	//(R0VN02RS3) Уровень мощности канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_AKNP3[]={  // 
	{&B8VC01RDU,8,0},	//(B8VC01RDU) Координата АЗ2, мм
	{&fEM_R0UR01RSS,8,2},	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
	{&fEM_R0UL52RSS,8,4},	//(R0UL52RSS) Уровень АС по мощности
	{&fEM_R0UL41RSS,8,6},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{&fEM_R0UL51RSS,8,8},	//(R0UL51RSS) Уровень АС по периоду разгона
	{&fEM_R0UH02RSS,8,10},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{&fEM_R0UH03RSS,8,12},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{&fEM_R0UL42RSS,8,14},	//(R0UL42RSS) Уровень ПС по мощности
	{&fEM_R7UX00RSS,8,16},	//(R7UX00RSS) X-координата АЗ1 (см)
	{&fEM_R7UX07RSS,8,18},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{&fEM_R7UX08RSS,8,20},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{&fEM_R7UX09RSS,8,22},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{&fEM_R7UY00RSS,8,24},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{&fEM_R7UY07RSS,8,26},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{&fEM_R7UY08RSS,8,28},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{&fEM_R7UY09RSS,8,30},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{&fEM_A0UX00RSS,8,32},	//(A0UX00RSS) Эффективный радиус АЗ
	{&fEM_A0UX07RSS,8,34},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{&fEM_A0UX08RSS,8,36},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{&fEM_A0UX09RSS,8,38},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{&fEM_B0UX07RSS,8,40},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{&fEM_B0UX08RSS,8,42},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{&fEM_B0UX09RSS,8,44},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{&fEM_R0UH05RSS,8,46},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{&iEM_R0UL01ISS,3,48},	//(R0UL01ISS) Шаг (мс) измерения периода
	{&dEM_R0UL02USS,5,49},	//(R0UL02USS) Предельное время ожидания роста потока (мс)
	{&fEM_R0UN03RSS,8,51},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_DiagnAKNP3[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnAKNP3[]={  // 
	{&R0DE3DLS3,1,0},	//(R0DE3DLS3) диагностика шкафа АКНП3 БП5/24Д место 8
	{&R0DE3CLS3,1,1},	//(R0DE3CLS3) диагностика шкафа АКНП3 БП5/24Д место 7
	{&R0DE3BLS3,1,2},	//(R0DE3BLS3) диагностика шкафа АКНП3 БП5/24Д место 6
	{&R0DE3ALS3,1,3},	//(R0DE3ALS3) диагностика шкафа АКНП3 БП5/24Д место 5
	{&R0DE39LS3,1,4},	//(R0DE39LS3) диагностика шкафа АКНП3 МП24-2 место 4
	{&R0DE38LS3,1,5},	//(R0DE38LS3) диагностика шкафа АКНП3 МП15-3 место 3
	{&R0DE37LS3,1,6},	//(R0DE37LS3) диагностика шкафа АКНП3 МП15-3.1 место 2
	{&R0DE36LS3,1,7},	//(R0DE36LS3) диагностика шкафа АКНП3 МП15-3.1 место 1
	{&R0DE35LS3,1,8},	//(R0DE35LS3) диагностика шкафа АКНП3 температура больше 53
	{&R0DE34LS3,1,9},	//(R0DE34LS3) диагностика шкафа АКНП3 температура меньше 43
	{&R0DE33LS3,1,10},	//(R0DE33LS3) диагностика шкафа АКНП3 двери
	{&R0DE32LS3,1,11},	//(R0DE32LS3) диагностика шкафа АКНП3 сеть 2
	{&R0DE31LS3,1,12},	//(R0DE31LS3) диагностика шкафа АКНП3 сеть 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DiagnAKNP3[]={  // 
	{&R0DE05LS3,3,0},	//(R0DE05LS3) диагностика модуля АКНП3 на 5 месте
	{&R0DE04LS3,3,1},	//(R0DE04LS3) диагностика модуля АКНП3 на 4 месте
	{&R0DE02LS3,3,2},	//(R0DE02LS3) диагностика модуля АКНП3 на 2 месте
	{&R0DE01LS3,3,3},	//(R0DE01LS3) диагностика модуля АКНП3 на 1 месте
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DiagnAKNP3[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_AKNP3[0],&di_AKNP3[0],&ir_AKNP3[0],&hr_AKNP3[0],NULL,NULL,NULL,0},	 //общий slave AKNP3
	{0,5003,&coil_DiagnAKNP3[0],&di_DiagnAKNP3[0],&ir_DiagnAKNP3[0],&hr_DiagnAKNP3[0],NULL,NULL,NULL,0},	 //Диагностика корзины АКНП3

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
	{&R0IN01FS3,8,0},
	{&R0DE01LS3,3,10},
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
	{&R0DE02LS3,3,10},
	{&R0IN03FS3,8,0},
	{&R0IN02FS3,8,0},
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
	{&R0DE04LS3,3,64},
	{&R0IE13LS3,1,4},
	{&R0IE12LS3,1,2},
	{&R0IE11LS3,1,0},
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
	{&R0VN73LZ1,1,16},
	{&R0VN77LZ1,1,18},
	{&A0EE01LS3,1,20},
	{&A1VN71LS3,1,30},
	{&R0IE01LS3,1,2},
	{&R0IE02LS3,1,0},
	{&A0VN71LS3,1,22},
	{&R0VN73LZ2,1,24},
	{&R0VN77LZ2,1,26},
	{&A1EE01LS3,1,28},
	{&R0DE05LS3,3,38},
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
	{&R0DE31LS3,1,0},
	{&R0DE32LS3,1,2},
	{&R0DE33LS3,1,4},
	{&R0DE34LS3,1,6},
	{&R0DE35LS3,1,8},
	{&R0DE3DLS3,1,24},
	{&R0DE36LS3,1,10},
	{&R0DE37LS3,1,12},
	{&R0DE3CLS3,1,22},
	{&R0DE38LS3,1,14},
	{&R0DE3BLS3,1,20},
	{&R0DE39LS3,1,16},
	{&R0DE3ALS3,1,18},
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
	setAsFloat(53,20);
	setAsFloat(54,13.0);
	setAsFloat(55,3703.704 );
	setAsFloat(56,62500.0);
	setAsFloat(57,5000);
	setAsFloat(58,1567.36);
	setAsFloat(59,1585.0);
	setAsFloat(60,1796.0);
	setAsFloat(61,1269.0);
	setAsFloat(62,506.5);
	setAsFloat(63,594.0);
	setAsFloat(64,559.0);
	setAsFloat(65,588.0);
	setAsFloat(66,11.0);
	setAsFloat(67,1.0);
	setAsFloat(68,1.0);
	setAsFloat(69,1.0);
	setAsFloat(70,0.0);
	setAsFloat(71,0);
	setAsFloat(72,0.0);
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
sschar bRM_1_ = {1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 
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
psbool  array_m88_x_1[8] = {&R0DE36LS3,&R0DE3ALS3,&R0DE37LS3,&R0DE38LS3,&R0DE39LS3,&R0DE3BLS3,&R0DE3CLS3,&R0DE3DLS3};
psint  array_m78_x_1[4] = {&R0DE01LS3,&R0DE02LS3,&R0DE04LS3,&R0DE05LS3};
psfloat  array_m45_tst_1[5];
psfloat  array_m45_trz_1[5];
psfloat  array_m45_N1_1[5];
psfloat  array_m45_N2_1[5];
psbool  array_m55_x_1[2] = {&var21,&var16};
psbool  array_m54_x_1[2] = {&var21,&var22};
psbool  array_m63_x_1[5] = {&var8,&R0IE11LS3,&R0IE12LS3,&R0IE13LS3,&A0EE03LS3};

/* Объявление структур */
_S_or3  S_or3_83_1 = {&var4,&var3,&var2,&var1};
_S_orn  S_orn_88_1 = {array_m88_x_1,&iRM_8_,&var2};
_S_and2  S_and2_79_1 = {&R0DE31LS3,&R0DE32LS3,&var3};
_S_diagndev  S_diagndev_78_1 = {array_m78_x_1,&iRM_4_,&var4,&var5};
_S_ocham  S_ocham_17_1 = {&R0IN01FS3,&R0IN02FS3,&R0IN03FS3,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX07RSS,&fEM_B0UX07RSS,&fEM_A0UX08RSS,&fEM_B0UX08RSS,&fEM_A0UX09RSS,&fEM_B0UX09RSS,&fEM_R7UX07RSS,&fEM_R7UY07RSS,&fEM_R7UX08RSS,&fEM_R7UY08RSS,&fEM_R7UX09RSS,&fEM_R7UY09RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var6,&var7,&var8,&var9,&var10,&var11,&var12,&internal1_m17_Nk};
_S_or2  S_or2_67_1 = {&R0EE03LZ1,&R0EE03LZ2,&var13};
_S_period  S_period_45_1 = {&var7,&var18,&iRM_5_,&var25,&var26,&fEM_R0UN03RSS,&var14,array_m45_tst_1,array_m45_trz_1,array_m45_N1_1,array_m45_N2_1,&internal1_m45_Period0,&internal1_m45_MyFirstEnterFlag};
_S_andn  S_andn_55_1 = {array_m55_x_1,&iRM_2_,&var15};
_S_bol  S_bol_52_1 = {&fEM_R0UL41RSS,&var14,&var16};
_S_andn  S_andn_54_1 = {array_m54_x_1,&iRM_2_,&var17};
_S_andn  S_andn_63_1 = {array_m63_x_1,&iRM_5_,&var18};
_S_bol  S_bol_35_1 = {&var7,&fEM_R0UL52RSS,&var19};
_S_bol  S_bol_40_1 = {&var7,&fEM_R0UL42RSS,&var20};
_S_bol  S_bol_51_1 = {&var7,&fEM_R0UN03RSS,&var21};
_S_bol  S_bol_50_1 = {&fEM_R0UL51RSS,&var14,&var22};
_S_react  S_react_46_1 = {&var14,&var23};
_S_bol  S_bol_31_1 = {&var7,&fEM_R0UR01RSS,&var24};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_67_1);
  diagndev(&S_diagndev_78_1);
  and2(&S_and2_79_1);
  orn(&S_orn_88_1);
  or3(&S_or3_83_1);
  ocham(&S_ocham_17_1);
  bol(&S_bol_31_1);
  bol(&S_bol_51_1);
  bol(&S_bol_40_1);
  bol(&S_bol_35_1);
  andn(&S_andn_63_1);
  setData(&var25,&iEM_R0UL01ISS);
  setData(&var26,&dEM_R0UL02USS);
  period(&S_period_45_1);
  react(&S_react_46_1);
  bol(&S_bol_50_1);
  andn(&S_andn_54_1);
  bol(&S_bol_52_1);
  andn(&S_andn_55_1);
  setData(idTestDiagnAKNP3,&var1);
  setData(idTTLaknp3,&var5);
  setData(idA1EE01LS3,&var18);
  setData(idR0VN77LZ2,&var17);
  setData(idR0VN73LZ2,&var19);
  setData(idA0VN71LS3,&var24);
  setData(idR0IE02LS3,&var13);
  setData(idR0IE01LS3,&var13);
  setData(idR0VN15RS3,&var12);
  setData(idR0VN33RS3,&var11);
  setData(idR0VN23RS3,&var10);
  setData(idR0VN13RS3,&var9);
  setData(idA0EE02LS3,&var8);
  setData(idA1VN71LS3,&var24);
  setData(idR0VN04RS3,&var23);
  setData(idR0VN03RS3,&var6);
  setData(idA0EE01LS3,&var18);
  setData(idR0VN77LZ1,&var17);
  setData(idR0VN65LS3,&var15);
  setData(idR0VN73LZ1,&var19);
  setData(idR0VN61LS3,&var20);
  setData(idR0VN01RS3,&var14);
  setData(idR0VN02RS3,&var7);

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
