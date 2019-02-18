#ifndef AKNP4_H
#define AKNP4_H
// Подсистема AKNP4:AKNP4
static char SimulOn=0;
static short CodeSub=7;
static char SimulIP[]="192.168.1.17\0";
static int SimulPort=5555;
static int StepCycle=5;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 377
static char BUFFER[377];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.55\0", 5432, "192.168.10.155\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0VN74LZ2	 BUFFER[0]	//(R0VN74LZ2) АС по мощности канал 4 на БАЗ2
#define idR0VN74LZ2	 1	//(R0VN74LZ2) АС по мощности канал 4 на БАЗ2
#define R0VN78LZ2	 BUFFER[2]	//(R0VN78LZ2) АС по периоду разгона канал 4 на БАЗ2
#define idR0VN78LZ2	 2	//(R0VN78LZ2) АС по периоду разгона канал 4 на БАЗ2
#define A1EE01LS4	 BUFFER[4]	//(A1EE01LS4) Исправность АКНП канал 4 на БАЗ2
#define idA1EE01LS4	 3	//(A1EE01LS4) Исправность АКНП канал 4 на БАЗ2
#define B8VC01RDU	 BUFFER[6]	//(B8VC01RDU) Координата АЗ2, мм
#define idB8VC01RDU	 4	//(B8VC01RDU) Координата АЗ2, мм
#define R0EE04LZ1	 BUFFER[11]	//(R0EE04LZ1) Питание  АКНП4  отключить
#define idR0EE04LZ1	 5	//(R0EE04LZ1) Питание  АКНП4  отключить
#define R0EE04LZ2	 BUFFER[13]	//(R0EE04LZ2) Питание  АКНП4  отключить
#define idR0EE04LZ2	 6	//(R0EE04LZ2) Питание  АКНП4  отключить
#define R0DE01LS4	 BUFFER[15]	//(R0DE01LS4) диагностика модуля АКНП4 на 1 месте
#define idR0DE01LS4	 7	//(R0DE01LS4) диагностика модуля АКНП4 на 1 месте
#define R0DE02LS4	 BUFFER[18]	//(R0DE02LS4) диагностика модуля АКНП4 на 2 месте
#define idR0DE02LS4	 8	//(R0DE02LS4) диагностика модуля АКНП4 на 2 месте
#define R0DE04LS4	 BUFFER[21]	//(R0DE04LS4) диагностика модуля АКНП4 на 4 месте
#define idR0DE04LS4	 9	//(R0DE04LS4) диагностика модуля АКНП4 на 4 месте
#define R0DE05LS4	 BUFFER[24]	//(R0DE05LS4) диагностика модуля АКНП4 на 5 месте
#define idR0DE05LS4	 10	//(R0DE05LS4) диагностика модуля АКНП4 на 5 месте
#define R0DE31LS4	 BUFFER[27]	//(R0DE31LS4) диагностика шкафа АКНП4 сеть 1
#define idR0DE31LS4	 11	//(R0DE31LS4) диагностика шкафа АКНП4 сеть 1
#define R0DE32LS4	 BUFFER[29]	//(R0DE32LS4) диагностика шкафа АКНП4 сеть 2
#define idR0DE32LS4	 12	//(R0DE32LS4) диагностика шкафа АКНП4 сеть 2
#define R0DE33LS4	 BUFFER[31]	//(R0DE33LS4) диагностика шкафа АКНП4 двери
#define idR0DE33LS4	 13	//(R0DE33LS4) диагностика шкафа АКНП4 двери
#define R0DE34LS4	 BUFFER[33]	//(R0DE34LS4) диагностика шкафа АКНП4 температура меньше 43
#define idR0DE34LS4	 14	//(R0DE34LS4) диагностика шкафа АКНП4 температура меньше 43
#define R0DE35LS4	 BUFFER[35]	//(R0DE35LS4) диагностика шкафа АКНП4 температура больше 53
#define idR0DE35LS4	 15	//(R0DE35LS4) диагностика шкафа АКНП4 температура больше 53
#define R0DE36LS4	 BUFFER[37]	//(R0DE36LS4) диагностика шкафа АКНП4 МП15-3.1 место 1
#define idR0DE36LS4	 16	//(R0DE36LS4) диагностика шкафа АКНП4 МП15-3.1 место 1
#define R0DE37LS4	 BUFFER[39]	//(R0DE37LS4) диагностика шкафа АКНП4 МП15-3.1 место 2
#define idR0DE37LS4	 17	//(R0DE37LS4) диагностика шкафа АКНП4 МП15-3.1 место 2
#define R0DE38LS4	 BUFFER[41]	//(R0DE38LS4) диагностика шкафа АКНП4 МП15-3 место 3
#define idR0DE38LS4	 18	//(R0DE38LS4) диагностика шкафа АКНП4 МП15-3 место 3
#define R0DE39LS4	 BUFFER[43]	//(R0DE39LS4) диагностика шкафа АКНП4 МП24-2 место 4
#define idR0DE39LS4	 19	//(R0DE39LS4) диагностика шкафа АКНП4 МП24-2 место 4
#define R0DE3CLS4	 BUFFER[45]	//(R0DE3CLS4) диагностика шкафа АКНП4 БП5/24Д место 7
#define idR0DE3CLS4	 20	//(R0DE3CLS4) диагностика шкафа АКНП4 БП5/24Д место 7
#define R0DE3DLS4	 BUFFER[47]	//(R0DE3DLS4) диагностика шкафа АКНП4 БП5/24Д место 8
#define idR0DE3DLS4	 21	//(R0DE3DLS4) диагностика шкафа АКНП4 БП5/24Д место 8
#define TTLaknp4	 BUFFER[49]	//(TTLaknp4) ttl
#define idTTLaknp4	 22	//(TTLaknp4) ttl
#define TestDiagnAKNP4	 BUFFER[52]	//(TestDiagnAKNP4) Неисправность от диагностики
#define idTestDiagnAKNP4	 23	//(TestDiagnAKNP4) Неисправность от диагностики
#define R0DEB1LS4	 BUFFER[54]	//(R0DEB1LS4) диагностика шкафа РПУ БП5 место 7
#define idR0DEB1LS4	 24	//(R0DEB1LS4) диагностика шкафа РПУ БП5 место 7
#define R0VN02RS4	 BUFFER[56]	//(R0VN02RS4) Уровень мощности канал 4
#define idR0VN02RS4	 25	//(R0VN02RS4) Уровень мощности канал 4
#define R0VN01RS4	 BUFFER[61]	//(R0VN01RS4) Период разгона канал 4
#define idR0VN01RS4	 26	//(R0VN01RS4) Период разгона канал 4
#define R0VN61LS4	 BUFFER[66]	//(R0VN61LS4) ПС по мощности канал 4
#define idR0VN61LS4	 27	//(R0VN61LS4) ПС по мощности канал 4
#define R0VN74LZ1	 BUFFER[68]	//(R0VN74LZ1) АС по мощности канал 4 на БАЗ1
#define idR0VN74LZ1	 28	//(R0VN74LZ1) АС по мощности канал 4 на БАЗ1
#define R0VN65LS4	 BUFFER[70]	//(R0VN65LS4) ПС по периоду разгона канал 4
#define idR0VN65LS4	 29	//(R0VN65LS4) ПС по периоду разгона канал 4
#define R0VN78LZ1	 BUFFER[72]	//(R0VN78LZ1) АС по периоду разгона канал 4 на БАЗ1
#define idR0VN78LZ1	 30	//(R0VN78LZ1) АС по периоду разгона канал 4 на БАЗ1
#define A0EE01LS4	 BUFFER[74]	//(A0EE01LS4) Исправность АКНП канал 4 на БАЗ1
#define idA0EE01LS4	 31	//(A0EE01LS4) Исправность АКНП канал 4 на БАЗ1
#define R0IN01FS4	 BUFFER[76]	//(R0IN01FS4) Выход СНМ-11 Гц
#define idR0IN01FS4	 32	//(R0IN01FS4) Выход СНМ-11 Гц
#define R0IN02FS4	 BUFFER[81]	//(R0IN02FS4) Выход КНК15-1 Гц
#define idR0IN02FS4	 33	//(R0IN02FS4) Выход КНК15-1 Гц
#define R0VN03RS4	 BUFFER[86]	//(R0VN03RS4) Измеренный нейтронный поток канал 4
#define idR0VN03RS4	 34	//(R0VN03RS4) Измеренный нейтронный поток канал 4
#define R0VN04RS4	 BUFFER[91]	//(R0VN04RS4) Реактивность канал 4
#define idR0VN04RS4	 35	//(R0VN04RS4) Реактивность канал 4
#define A1VN71LS4	 BUFFER[96]	//(A1VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
#define idA1VN71LS4	 36	//(A1VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
#define R0IN03FS4	 BUFFER[98]	//(R0IN03FS4) Выход КНК53М Гц
#define idR0IN03FS4	 37	//(R0IN03FS4) Выход КНК53М Гц
#define A0EE02LS4	 BUFFER[103]	//(A0EE02LS4) Исправность АКНП4 (от сшивки каналов) канал 4
#define idA0EE02LS4	 38	//(A0EE02LS4) Исправность АКНП4 (от сшивки каналов) канал 4
#define R0IE11LS4	 BUFFER[105]	//(R0IE11LS4) Исправность ВИП 1,6 (№17) СНМ11 4 канала
#define idR0IE11LS4	 39	//(R0IE11LS4) Исправность ВИП 1,6 (№17) СНМ11 4 канала
#define R0IE12LS4	 BUFFER[107]	//(R0IE12LS4) Исправность ВИП 0,5 (№18) КНК15-1 4 канала
#define idR0IE12LS4	 40	//(R0IE12LS4) Исправность ВИП 0,5 (№18) КНК15-1 4 канала
#define R0IE13LS4	 BUFFER[109]	//(R0IE13LS4) Исправность ВИП 0,5 (№19) КНК53М 4 канала
#define idR0IE13LS4	 41	//(R0IE13LS4) Исправность ВИП 0,5 (№19) КНК53М 4 канала
#define R0VN13RS4	 BUFFER[111]	//(R0VN13RS4) Нейтронный поток по камере СНМ11 канал 4
#define idR0VN13RS4	 42	//(R0VN13RS4) Нейтронный поток по камере СНМ11 канал 4
#define R0VN23RS4	 BUFFER[116]	//(R0VN23RS4) Нейтронный поток по камере КНК15-1 канал 4
#define idR0VN23RS4	 43	//(R0VN23RS4) Нейтронный поток по камере КНК15-1 канал 4
#define R0VN33RS4	 BUFFER[121]	//(R0VN33RS4) Нейтронный поток по камере КНК53М канал 4
#define idR0VN33RS4	 44	//(R0VN33RS4) Нейтронный поток по камере КНК53М канал 4
#define R0VN15RS4	 BUFFER[126]	//(R0VN15RS4) Номер ведущей камеры канал 4
#define idR0VN15RS4	 45	//(R0VN15RS4) Номер ведущей камеры канал 4
#define A0EE03LS4	 BUFFER[129]	//(A0EE03LS4) Подключена сеть питания АКНП канал 4
#define idA0EE03LS4	 46	//(A0EE03LS4) Подключена сеть питания АКНП канал 4
#define R0IE01LS4	 BUFFER[131]	//(R0IE01LS4) Отключение питание детекторов канал 4
#define idR0IE01LS4	 47	//(R0IE01LS4) Отключение питание детекторов канал 4
#define R0IE02LS4	 BUFFER[133]	//(R0IE02LS4) Отключить питание ПР, ПУ канал 4
#define idR0IE02LS4	 48	//(R0IE02LS4) Отключить питание ПР, ПУ канал 4
#define A0VN71LS4	 BUFFER[135]	//(A0VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
#define idA0VN71LS4	 49	//(A0VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
#define fEM_R0UR01RSS	 BUFFER[137]	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RSS	 50	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R0UL52RSS	 BUFFER[142]	//(R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	 51	//(R0UL52RSS) Уровень АС по мощности
#define fEM_R0UL41RSS	 BUFFER[147]	//(R0UL41RSS) Уровень ПС по периоду разгона
#define idfEM_R0UL41RSS	 52	//(R0UL41RSS) Уровень ПС по периоду разгона
#define fEM_R0UL51RSS	 BUFFER[152]	//(R0UL51RSS) Уровень АС по периоду разгона
#define idfEM_R0UL51RSS	 53	//(R0UL51RSS) Уровень АС по периоду разгона
#define fEM_R0UH02RSS	 BUFFER[157]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define idfEM_R0UH02RSS	 54	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define fEM_R0UH03RSS	 BUFFER[162]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define idfEM_R0UH03RSS	 55	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define fEM_R0UL42RSS	 BUFFER[167]	//(R0UL42RSS) Уровень ПС по мощности
#define idfEM_R0UL42RSS	 56	//(R0UL42RSS) Уровень ПС по мощности
#define fEM_R7UX00RSS	 BUFFER[172]	//(R7UX00RSS) X-координата АЗ1 (см)
#define idfEM_R7UX00RSS	 57	//(R7UX00RSS) X-координата АЗ1 (см)
#define fEM_R7UY00RSS	 BUFFER[177]	//(R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	 58	//(R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UX10RSS	 BUFFER[182]	//(R7UX10RSS) X-координата камеры R7IN41
#define idfEM_R7UX10RSS	 59	//(R7UX10RSS) X-координата камеры R7IN41
#define fEM_R7UX11RSS	 BUFFER[187]	//(R7UX11RSS) X-координата камеры R7IN42
#define idfEM_R7UX11RSS	 60	//(R7UX11RSS) X-координата камеры R7IN42
#define fEM_R7UX12RSS	 BUFFER[192]	//(R7UX12RSS) X-координата камеры R7IN43
#define idfEM_R7UX12RSS	 61	//(R7UX12RSS) X-координата камеры R7IN43
#define fEM_R7UY10RSS	 BUFFER[197]	//(R7UY10RSS) Y-координата камеры R7IN41
#define idfEM_R7UY10RSS	 62	//(R7UY10RSS) Y-координата камеры R7IN41
#define fEM_R7UY11RSS	 BUFFER[202]	//(R7UY11RSS) Y-координата камеры R7IN42
#define idfEM_R7UY11RSS	 63	//(R7UY11RSS) Y-координата камеры R7IN42
#define fEM_R7UY12RSS	 BUFFER[207]	//(R7UY12RSS) Y-координата камеры R7IN43
#define idfEM_R7UY12RSS	 64	//(R7UY12RSS) Y-координата камеры R7IN43
#define fEM_A0UX00RSS	 BUFFER[212]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 65	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX10RSS	 BUFFER[217]	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define idfEM_A0UX10RSS	 66	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define fEM_A0UX11RSS	 BUFFER[222]	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define idfEM_A0UX11RSS	 67	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define fEM_A0UX12RSS	 BUFFER[227]	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define idfEM_A0UX12RSS	 68	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define fEM_B0UX10RSS	 BUFFER[232]	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define idfEM_B0UX10RSS	 69	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define fEM_B0UX11RSS	 BUFFER[237]	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define idfEM_B0UX11RSS	 70	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define fEM_B0UX12RSS	 BUFFER[242]	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define idfEM_B0UX12RSS	 71	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define fEM_R0UH05RSS	 BUFFER[247]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 72	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define iEM_R0UL01ISS	 BUFFER[252]	//(R0UL01ISS) Шаг (мс) измерения периода
#define idiEM_R0UL01ISS	 73	//(R0UL01ISS) Шаг (мс) измерения периода
#define dEM_R0UL02USS	 BUFFER[255]	//(R0UL02USS) Предельное время ожидания роста потока (мс)
#define iddEM_R0UL02USS	 74	//(R0UL02USS) Предельное время ожидания роста потока (мс)
#define fEM_R0UN03RSS	 BUFFER[260]	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN03RSS	 75	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define bFirstEnterFlag	 BUFFER[265]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 76	//(bFirstEnterFlag) 
#define internal1_m16_Nk	 BUFFER[267]	//(internal1_m16_Nk) Nk - ведущая камера
#define idinternal1_m16_Nk	 77	//(internal1_m16_Nk) Nk - ведущая камера
#define internal1_m45_tst	 BUFFER[270]	//(internal1_m45_tst) - массив времени фиксации стартовой мощности
#define idinternal1_m45_tst	 78	//(internal1_m45_tst) - массив времени фиксации стартовой мощности
#define internal1_m45_trz	 BUFFER[295]	//(internal1_m45_trz) - массив времени фиксации очередного периода
#define idinternal1_m45_trz	 79	//(internal1_m45_trz) - массив времени фиксации очередного периода
#define internal1_m45_N1	 BUFFER[320]	//(internal1_m45_N1) - массив значения мощности в начале замера
#define idinternal1_m45_N1	 80	//(internal1_m45_N1) - массив значения мощности в начале замера
#define internal1_m45_N2	 BUFFER[345]	//(internal1_m45_N2) - массив значения мощности в конце замера
#define idinternal1_m45_N2	 81	//(internal1_m45_N2) - массив значения мощности в конце замера
#define internal1_m45_Period0	 BUFFER[370]	//(internal1_m45_Period0) Per - Период разгона РУ
#define idinternal1_m45_Period0	 82	//(internal1_m45_Period0) Per - Период разгона РУ
#define internal1_m45_MyFirstEnterFlag	 BUFFER[375]	//(internal1_m45_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m45_MyFirstEnterFlag	 83	//(internal1_m45_MyFirstEnterFlag)  FirstEnterFlag
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &R0VN74LZ2},	//(R0VN74LZ2) АС по мощности канал 4 на БАЗ2
	{ 2	,1	,1	, &R0VN78LZ2},	//(R0VN78LZ2) АС по периоду разгона канал 4 на БАЗ2
	{ 3	,1	,1	, &A1EE01LS4},	//(A1EE01LS4) Исправность АКНП канал 4 на БАЗ2
	{ 4	,8	,1	, &B8VC01RDU},	//(B8VC01RDU) Координата АЗ2, мм
	{ 5	,1	,1	, &R0EE04LZ1},	//(R0EE04LZ1) Питание  АКНП4  отключить
	{ 6	,1	,1	, &R0EE04LZ2},	//(R0EE04LZ2) Питание  АКНП4  отключить
	{ 7	,3	,1	, &R0DE01LS4},	//(R0DE01LS4) диагностика модуля АКНП4 на 1 месте
	{ 8	,3	,1	, &R0DE02LS4},	//(R0DE02LS4) диагностика модуля АКНП4 на 2 месте
	{ 9	,3	,1	, &R0DE04LS4},	//(R0DE04LS4) диагностика модуля АКНП4 на 4 месте
	{ 10	,3	,1	, &R0DE05LS4},	//(R0DE05LS4) диагностика модуля АКНП4 на 5 месте
	{ 11	,1	,1	, &R0DE31LS4},	//(R0DE31LS4) диагностика шкафа АКНП4 сеть 1
	{ 12	,1	,1	, &R0DE32LS4},	//(R0DE32LS4) диагностика шкафа АКНП4 сеть 2
	{ 13	,1	,1	, &R0DE33LS4},	//(R0DE33LS4) диагностика шкафа АКНП4 двери
	{ 14	,1	,1	, &R0DE34LS4},	//(R0DE34LS4) диагностика шкафа АКНП4 температура меньше 43
	{ 15	,1	,1	, &R0DE35LS4},	//(R0DE35LS4) диагностика шкафа АКНП4 температура больше 53
	{ 16	,1	,1	, &R0DE36LS4},	//(R0DE36LS4) диагностика шкафа АКНП4 МП15-3.1 место 1
	{ 17	,1	,1	, &R0DE37LS4},	//(R0DE37LS4) диагностика шкафа АКНП4 МП15-3.1 место 2
	{ 18	,1	,1	, &R0DE38LS4},	//(R0DE38LS4) диагностика шкафа АКНП4 МП15-3 место 3
	{ 19	,1	,1	, &R0DE39LS4},	//(R0DE39LS4) диагностика шкафа АКНП4 МП24-2 место 4
	{ 20	,1	,1	, &R0DE3CLS4},	//(R0DE3CLS4) диагностика шкафа АКНП4 БП5/24Д место 7
	{ 21	,1	,1	, &R0DE3DLS4},	//(R0DE3DLS4) диагностика шкафа АКНП4 БП5/24Д место 8
	{ 22	,3	,1	, &TTLaknp4},	//(TTLaknp4) ttl
	{ 23	,1	,1	, &TestDiagnAKNP4},	//(TestDiagnAKNP4) Неисправность от диагностики
	{ 24	,1	,1	, &R0DEB1LS4},	//(R0DEB1LS4) диагностика шкафа РПУ БП5 место 7
	{ 25	,8	,1	, &R0VN02RS4},	//(R0VN02RS4) Уровень мощности канал 4
	{ 26	,8	,1	, &R0VN01RS4},	//(R0VN01RS4) Период разгона канал 4
	{ 27	,1	,1	, &R0VN61LS4},	//(R0VN61LS4) ПС по мощности канал 4
	{ 28	,1	,1	, &R0VN74LZ1},	//(R0VN74LZ1) АС по мощности канал 4 на БАЗ1
	{ 29	,1	,1	, &R0VN65LS4},	//(R0VN65LS4) ПС по периоду разгона канал 4
	{ 30	,1	,1	, &R0VN78LZ1},	//(R0VN78LZ1) АС по периоду разгона канал 4 на БАЗ1
	{ 31	,1	,1	, &A0EE01LS4},	//(A0EE01LS4) Исправность АКНП канал 4 на БАЗ1
	{ 32	,8	,1	, &R0IN01FS4},	//(R0IN01FS4) Выход СНМ-11 Гц
	{ 33	,8	,1	, &R0IN02FS4},	//(R0IN02FS4) Выход КНК15-1 Гц
	{ 34	,8	,1	, &R0VN03RS4},	//(R0VN03RS4) Измеренный нейтронный поток канал 4
	{ 35	,8	,1	, &R0VN04RS4},	//(R0VN04RS4) Реактивность канал 4
	{ 36	,1	,1	, &A1VN71LS4},	//(A1VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
	{ 37	,8	,1	, &R0IN03FS4},	//(R0IN03FS4) Выход КНК53М Гц
	{ 38	,1	,1	, &A0EE02LS4},	//(A0EE02LS4) Исправность АКНП4 (от сшивки каналов) канал 4
	{ 39	,1	,1	, &R0IE11LS4},	//(R0IE11LS4) Исправность ВИП 1,6 (№17) СНМ11 4 канала
	{ 40	,1	,1	, &R0IE12LS4},	//(R0IE12LS4) Исправность ВИП 0,5 (№18) КНК15-1 4 канала
	{ 41	,1	,1	, &R0IE13LS4},	//(R0IE13LS4) Исправность ВИП 0,5 (№19) КНК53М 4 канала
	{ 42	,8	,1	, &R0VN13RS4},	//(R0VN13RS4) Нейтронный поток по камере СНМ11 канал 4
	{ 43	,8	,1	, &R0VN23RS4},	//(R0VN23RS4) Нейтронный поток по камере КНК15-1 канал 4
	{ 44	,8	,1	, &R0VN33RS4},	//(R0VN33RS4) Нейтронный поток по камере КНК53М канал 4
	{ 45	,3	,1	, &R0VN15RS4},	//(R0VN15RS4) Номер ведущей камеры канал 4
	{ 46	,1	,1	, &A0EE03LS4},	//(A0EE03LS4) Подключена сеть питания АКНП канал 4
	{ 47	,1	,1	, &R0IE01LS4},	//(R0IE01LS4) Отключение питание детекторов канал 4
	{ 48	,1	,1	, &R0IE02LS4},	//(R0IE02LS4) Отключить питание ПР, ПУ канал 4
	{ 49	,1	,1	, &A0VN71LS4},	//(A0VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
	{ 50	,8	,1	, &fEM_R0UR01RSS},	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
	{ 51	,8	,1	, &fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{ 52	,8	,1	, &fEM_R0UL41RSS},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{ 53	,8	,1	, &fEM_R0UL51RSS},	//(R0UL51RSS) Уровень АС по периоду разгона
	{ 54	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{ 55	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{ 56	,8	,1	, &fEM_R0UL42RSS},	//(R0UL42RSS) Уровень ПС по мощности
	{ 57	,8	,1	, &fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{ 58	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{ 59	,8	,1	, &fEM_R7UX10RSS},	//(R7UX10RSS) X-координата камеры R7IN41
	{ 60	,8	,1	, &fEM_R7UX11RSS},	//(R7UX11RSS) X-координата камеры R7IN42
	{ 61	,8	,1	, &fEM_R7UX12RSS},	//(R7UX12RSS) X-координата камеры R7IN43
	{ 62	,8	,1	, &fEM_R7UY10RSS},	//(R7UY10RSS) Y-координата камеры R7IN41
	{ 63	,8	,1	, &fEM_R7UY11RSS},	//(R7UY11RSS) Y-координата камеры R7IN42
	{ 64	,8	,1	, &fEM_R7UY12RSS},	//(R7UY12RSS) Y-координата камеры R7IN43
	{ 65	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 66	,8	,1	, &fEM_A0UX10RSS},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{ 67	,8	,1	, &fEM_A0UX11RSS},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{ 68	,8	,1	, &fEM_A0UX12RSS},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{ 69	,8	,1	, &fEM_B0UX10RSS},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{ 70	,8	,1	, &fEM_B0UX11RSS},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{ 71	,8	,1	, &fEM_B0UX12RSS},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{ 72	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 73	,3	,1	, &iEM_R0UL01ISS},	//(R0UL01ISS) Шаг (мс) измерения периода
	{ 74	,5	,1	, &dEM_R0UL02USS},	//(R0UL02USS) Предельное время ожидания роста потока (мс)
	{ 75	,8	,1	, &fEM_R0UN03RSS},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 76	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 77	,3	,1	, &internal1_m16_Nk},	//(internal1_m16_Nk) Nk - ведущая камера
	{ 78	,8	,5	, &internal1_m45_tst},	//(internal1_m45_tst) - массив времени фиксации стартовой мощности
	{ 79	,8	,5	, &internal1_m45_trz},	//(internal1_m45_trz) - массив времени фиксации очередного периода
	{ 80	,8	,5	, &internal1_m45_N1},	//(internal1_m45_N1) - массив значения мощности в начале замера
	{ 81	,8	,5	, &internal1_m45_N2},	//(internal1_m45_N2) - массив значения мощности в конце замера
	{ 82	,8	,1	, &internal1_m45_Period0},	//(internal1_m45_Period0) Per - Период разгона РУ
	{ 83	,1	,1	, &internal1_m45_MyFirstEnterFlag},	//(internal1_m45_MyFirstEnterFlag)  FirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="aknp4.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{50,"fEM_R0UR01RSS\0"}, 
{51,"fEM_R0UL52RSS\0"}, 
{52,"fEM_R0UL41RSS\0"}, 
{53,"fEM_R0UL51RSS\0"}, 
{54,"fEM_R0UH02RSS\0"}, 
{55,"fEM_R0UH03RSS\0"}, 
{56,"fEM_R0UL42RSS\0"}, 
{57,"fEM_R7UX00RSS\0"}, 
{58,"fEM_R7UY00RSS\0"}, 
{59,"fEM_R7UX10RSS\0"}, 
{60,"fEM_R7UX11RSS\0"}, 
{61,"fEM_R7UX12RSS\0"}, 
{62,"fEM_R7UY10RSS\0"}, 
{63,"fEM_R7UY11RSS\0"}, 
{64,"fEM_R7UY12RSS\0"}, 
{65,"fEM_A0UX00RSS\0"}, 
{66,"fEM_A0UX10RSS\0"}, 
{67,"fEM_A0UX11RSS\0"}, 
{68,"fEM_A0UX12RSS\0"}, 
{69,"fEM_B0UX10RSS\0"}, 
{70,"fEM_B0UX11RSS\0"}, 
{71,"fEM_B0UX12RSS\0"}, 
{72,"fEM_R0UH05RSS\0"}, 
{73,"iEM_R0UL01ISS\0"}, 
{74,"dEM_R0UL02USS\0"}, 
{75,"fEM_R0UN03RSS\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_AKNP4[]={  // 
	{&R0EE04LZ2,1,0},	//(R0EE04LZ2) Питание  АКНП4  отключить
	{&R0EE04LZ1,1,1},	//(R0EE04LZ1) Питание  АКНП4  отключить
	{&A0EE03LS4,1,2},	//(A0EE03LS4) Подключена сеть питания АКНП канал 4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_AKNP4[]={  // 
	{&TestDiagnAKNP4,1,0},	//(TestDiagnAKNP4) Неисправность от диагностики
	{&A0EE02LS4,1,1},	//(A0EE02LS4) Исправность АКНП4 (от сшивки каналов) канал 4
	{&R0VN65LS4,1,2},	//(R0VN65LS4) ПС по периоду разгона канал 4
	{&R0VN61LS4,1,3},	//(R0VN61LS4) ПС по мощности канал 4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_AKNP4[]={  // 
	{&TTLaknp4,3,0},	//(TTLaknp4) ttl
	{&R0VN15RS4,3,1},	//(R0VN15RS4) Номер ведущей камеры канал 4
	{&R0VN33RS4,8,2},	//(R0VN33RS4) Нейтронный поток по камере КНК53М канал 4
	{&R0VN23RS4,8,4},	//(R0VN23RS4) Нейтронный поток по камере КНК15-1 канал 4
	{&R0VN13RS4,8,6},	//(R0VN13RS4) Нейтронный поток по камере СНМ11 канал 4
	{&R0IN03FS4,8,8},	//(R0IN03FS4) Выход КНК53М Гц
	{&R0VN04RS4,8,10},	//(R0VN04RS4) Реактивность канал 4
	{&R0VN03RS4,8,12},	//(R0VN03RS4) Измеренный нейтронный поток канал 4
	{&R0IN02FS4,8,14},	//(R0IN02FS4) Выход КНК15-1 Гц
	{&R0IN01FS4,8,16},	//(R0IN01FS4) Выход СНМ-11 Гц
	{&R0VN01RS4,8,18},	//(R0VN01RS4) Период разгона канал 4
	{&R0VN02RS4,8,20},	//(R0VN02RS4) Уровень мощности канал 4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_AKNP4[]={  // 
	{&B8VC01RDU,8,0},	//(B8VC01RDU) Координата АЗ2, мм
	{&fEM_R0UR01RSS,8,2},	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
	{&fEM_R0UL52RSS,8,4},	//(R0UL52RSS) Уровень АС по мощности
	{&fEM_R0UL41RSS,8,6},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{&fEM_R0UL51RSS,8,8},	//(R0UL51RSS) Уровень АС по периоду разгона
	{&fEM_R0UH02RSS,8,10},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{&fEM_R0UH03RSS,8,12},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{&fEM_R0UL42RSS,8,14},	//(R0UL42RSS) Уровень ПС по мощности
	{&fEM_R7UX00RSS,8,16},	//(R7UX00RSS) X-координата АЗ1 (см)
	{&fEM_R7UY00RSS,8,18},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{&fEM_R7UX10RSS,8,20},	//(R7UX10RSS) X-координата камеры R7IN41
	{&fEM_R7UX11RSS,8,22},	//(R7UX11RSS) X-координата камеры R7IN42
	{&fEM_R7UX12RSS,8,24},	//(R7UX12RSS) X-координата камеры R7IN43
	{&fEM_R7UY10RSS,8,26},	//(R7UY10RSS) Y-координата камеры R7IN41
	{&fEM_R7UY11RSS,8,28},	//(R7UY11RSS) Y-координата камеры R7IN42
	{&fEM_R7UY12RSS,8,30},	//(R7UY12RSS) Y-координата камеры R7IN43
	{&fEM_A0UX00RSS,8,32},	//(A0UX00RSS) Эффективный радиус АЗ
	{&fEM_A0UX10RSS,8,34},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{&fEM_A0UX11RSS,8,36},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{&fEM_A0UX12RSS,8,38},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{&fEM_B0UX10RSS,8,40},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{&fEM_B0UX11RSS,8,42},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{&fEM_B0UX12RSS,8,44},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{&fEM_R0UH05RSS,8,46},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{&iEM_R0UL01ISS,3,48},	//(R0UL01ISS) Шаг (мс) измерения периода
	{&dEM_R0UL02USS,5,49},	//(R0UL02USS) Предельное время ожидания роста потока (мс)
	{&fEM_R0UN03RSS,8,51},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_DiagnAKNP4[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnAKNP4[]={  // 
	{&R0DE31LS4,1,0},	//(R0DE31LS4) диагностика шкафа АКНП4 сеть 1
	{&R0DE32LS4,1,1},	//(R0DE32LS4) диагностика шкафа АКНП4 сеть 2
	{&R0DE33LS4,1,2},	//(R0DE33LS4) диагностика шкафа АКНП4 двери
	{&R0DE34LS4,1,3},	//(R0DE34LS4) диагностика шкафа АКНП4 температура меньше 43
	{&R0DE35LS4,1,4},	//(R0DE35LS4) диагностика шкафа АКНП4 температура больше 53
	{&R0DE36LS4,1,5},	//(R0DE36LS4) диагностика шкафа АКНП4 МП15-3.1 место 1
	{&R0DE37LS4,1,6},	//(R0DE37LS4) диагностика шкафа АКНП4 МП15-3.1 место 2
	{&R0DE38LS4,1,7},	//(R0DE38LS4) диагностика шкафа АКНП4 МП15-3 место 3
	{&R0DE39LS4,1,8},	//(R0DE39LS4) диагностика шкафа АКНП4 МП24-2 место 4
	{&R0DE3CLS4,1,9},	//(R0DE3CLS4) диагностика шкафа АКНП4 БП5/24Д место 7
	{&R0DE3DLS4,1,10},	//(R0DE3DLS4) диагностика шкафа АКНП4 БП5/24Д место 8
	{&R0DEB1LS4,1,11},	//(R0DEB1LS4) диагностика шкафа РПУ БП5 место 7
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DiagnAKNP4[]={  // 
	{&R0DE01LS4,3,0},	//(R0DE01LS4) диагностика модуля АКНП4 на 1 месте
	{&R0DE02LS4,3,1},	//(R0DE02LS4) диагностика модуля АКНП4 на 2 месте
	{&R0DE04LS4,3,2},	//(R0DE04LS4) диагностика модуля АКНП4 на 4 месте
	{&R0DE05LS4,3,3},	//(R0DE05LS4) диагностика модуля АКНП4 на 5 месте
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DiagnAKNP4[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_AKNP4[0],&di_AKNP4[0],&ir_AKNP4[0],&hr_AKNP4[0],NULL,NULL,NULL,0},	 //общий slave AKNP4
	{0,5003,&coil_DiagnAKNP4[0],&di_DiagnAKNP4[0],&ir_DiagnAKNP4[0],&hr_DiagnAKNP4[0],NULL,NULL,NULL,0},	 //Диагностика корзины АКНП4

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
	{&R0IN02FS4,8,5},
	{&R0IN01FS4,8,0},
	{&R0DE01LS4,3,10},
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
	{&R0IN03FS4,8,0},
	{&R0DE02LS4,3,10},
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
	{&R0IE11LS4,1,0},
	{&R0IE12LS4,1,2},
	{&R0IE13LS4,1,4},
	{&R0DE04LS4,3,64},
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
	{&A1VN71LS4,1,30},
	{&A0EE01LS4,1,20},
	{&R0VN78LZ1,1,18},
	{&R0VN74LZ1,1,16},
	{&R0IE01LS4,1,2},
	{&R0IE02LS4,1,0},
	{&A0VN71LS4,1,22},
	{&R0VN74LZ2,1,24},
	{&R0VN78LZ2,1,26},
	{&A1EE01LS4,1,28},
	{&R0DE05LS4,3,38},
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
	{&R0DE31LS4,1,0},
	{&R0DE32LS4,1,2},
	{&R0DE33LS4,1,4},
	{&R0DE34LS4,1,6},
	{&R0DE35LS4,1,8},
	{&R0DE36LS4,1,10},
	{&R0DE37LS4,1,12},
	{&R0DE38LS4,1,14},
	{&R0DE39LS4,1,16},
	{&R0DEB1LS4,1,18},
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
	setAsFloat(50,5000);
	setAsFloat(51,5100);
	setAsFloat(52,20);
	setAsFloat(53,13.0);
	setAsFloat(54,3703.704 );
	setAsFloat(55,62500.0);
	setAsFloat(56,5000);
	setAsFloat(57,1567.36);
	setAsFloat(58,506.5);
	setAsFloat(59,1555.0);
	setAsFloat(60,1281.2);
	setAsFloat(61,1269.0);
	setAsFloat(62,594.0);
	setAsFloat(63,597.2);
	setAsFloat(64,556.8);
	setAsFloat(65,11.0);
	setAsFloat(66,1.0);
	setAsFloat(67,1.0);
	setAsFloat(68,1.0);
	setAsFloat(69,0.0);
	setAsFloat(70,0.0);
	setAsFloat(71,0.0);
	setAsFloat(72,32000.0);
	setAsShort(73,500);
	setAsInt(74,100000);
	setAsFloat(75,0.005);
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
sschar bRM_1_ = {1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива значений */ 
ssint iRM_6_ = {6,0}; /* n - N-размерность массива x */ 

uspaint8 SpaEEPROMBuf[128];

/* Определение переменных */
ssbool var1;
ssbool var2;
ssbool var3;
ssbool var4;
ssbool var5;
ssbool var6;
ssint var7;
ssfloat var8;
ssfloat var9;
ssbool var10;
ssfloat var11;
ssfloat var12;
ssfloat var13;
ssint var14;
ssbool var15;
ssfloat var16;
ssbool var17;
ssbool var18;
ssbool var19;
ssbool var20;
ssbool var21;
ssbool var22;
ssbool var23;
ssbool var24;
ssfloat var25;
ssbool var26;
ssfloat var27;
ssfloat var28;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m94_x_1[6] = {&R0DE36LS4,&R0DE37LS4,&R0DE38LS4,&R0DE39LS4,&var2,&var1};
psint  array_m80_x_1[4] = {&R0DE01LS4,&R0DE02LS4,&R0DE04LS4,&R0DE05LS4};
psfloat  array_m45_tst_1[5];
psfloat  array_m45_trz_1[5];
psfloat  array_m45_N1_1[5];
psfloat  array_m45_N2_1[5];
psbool  array_m55_x_1[2] = {&var23,&var18};
psbool  array_m54_x_1[2] = {&var23,&var24};
psbool  array_m63_x_1[5] = {&var10,&R0IE11LS4,&R0IE12LS4,&R0IE13LS4,&A0EE03LS4};

/* Объявление структур */
_S_or2  S_or2_95_1 = {&R0DEB1LS4,&R0DEB1LS4,&var1};
_S_or2  S_or2_89_1 = {&R0DEB1LS4,&R0DEB1LS4,&var2};
_S_or3  S_or3_91_1 = {&var6,&var5,&var4,&var3};
_S_orn  S_orn_94_1 = {array_m94_x_1,&iRM_6_,&var4};
_S_and2  S_and2_82_1 = {&R0DE31LS4,&R0DE32LS4,&var5};
_S_diagndev  S_diagndev_80_1 = {array_m80_x_1,&iRM_4_,&var6,&var7};
_S_ocham  S_ocham_16_1 = {&R0IN01FS4,&R0IN02FS4,&R0IN03FS4,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX10RSS,&fEM_B0UX10RSS,&fEM_A0UX11RSS,&fEM_B0UX11RSS,&fEM_A0UX12RSS,&fEM_B0UX12RSS,&fEM_R7UX10RSS,&fEM_R7UY10RSS,&fEM_R7UX11RSS,&fEM_R7UY11RSS,&fEM_R7UX12RSS,&fEM_R7UY12RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var8,&var9,&var10,&var11,&var12,&var13,&var14,&internal1_m16_Nk};
_S_or2  S_or2_66_1 = {&R0EE04LZ1,&R0EE04LZ2,&var15};
_S_period  S_period_45_1 = {&var9,&var20,&iRM_5_,&var27,&var28,&fEM_R0UN03RSS,&var16,array_m45_tst_1,array_m45_trz_1,array_m45_N1_1,array_m45_N2_1,&internal1_m45_Period0,&internal1_m45_MyFirstEnterFlag};
_S_andn  S_andn_55_1 = {array_m55_x_1,&iRM_2_,&var17};
_S_bol  S_bol_52_1 = {&fEM_R0UL41RSS,&var16,&var18};
_S_andn  S_andn_54_1 = {array_m54_x_1,&iRM_2_,&var19};
_S_andn  S_andn_63_1 = {array_m63_x_1,&iRM_5_,&var20};
_S_bol  S_bol_35_1 = {&var9,&fEM_R0UL52RSS,&var21};
_S_bol  S_bol_40_1 = {&var9,&fEM_R0UL42RSS,&var22};
_S_bol  S_bol_51_1 = {&var9,&fEM_R0UN03RSS,&var23};
_S_bol  S_bol_50_1 = {&fEM_R0UL51RSS,&var16,&var24};
_S_react  S_react_46_1 = {&var16,&var25};
_S_bol  S_bol_31_1 = {&var9,&fEM_R0UR01RSS,&var26};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
//   or2(&S_or2_66_1);
//   ocham(&S_ocham_16_1);
  diagndev(&S_diagndev_80_1);
  and2(&S_and2_82_1);
  or2(&S_or2_89_1);
  or2(&S_or2_95_1);
//   bol(&S_bol_31_1);
//   bol(&S_bol_51_1);
//   bol(&S_bol_40_1);
//   bol(&S_bol_35_1);
//   andn(&S_andn_63_1);
//   setData(&var27,&iEM_R0UL01ISS);
//   setData(&var28,&dEM_R0UL02USS);
//   period(&S_period_45_1);
  orn(&S_orn_94_1);
  or3(&S_or3_91_1);
//   react(&S_react_46_1);
//   bol(&S_bol_50_1);
//   andn(&S_andn_54_1);
//   bol(&S_bol_52_1);
//   andn(&S_andn_55_1);
  setData(idTestDiagnAKNP4,&var3);
  setData(idTTLaknp4,&var7);
  setData(idR0DE3DLS4,&var1);
  setData(idR0DE3CLS4,&var2);
//   setData(idA1EE01LS4,&var20);
//   setData(idR0VN78LZ2,&var19);
//   setData(idR0VN74LZ2,&var21);
//   setData(idA0VN71LS4,&var26);
//   setData(idR0IE02LS4,&var15);
//   setData(idR0IE01LS4,&var15);
//   setData(idR0VN15RS4,&var14);
//   setData(idR0VN33RS4,&var13);
//   setData(idR0VN23RS4,&var12);
//   setData(idR0VN13RS4,&var11);
//   setData(idA0EE02LS4,&var10);
//   setData(idA1VN71LS4,&var26);
//   setData(idR0VN04RS4,&var25);
//   setData(idR0VN03RS4,&var8);
//   setData(idA0EE01LS4,&var20);
//   setData(idR0VN78LZ1,&var19);
//   setData(idR0VN65LS4,&var17);
//   setData(idR0VN74LZ1,&var21);
//   setData(idR0VN61LS4,&var22);
//   setData(idR0VN01RS4,&var16);
//   setData(idR0VN02RS4,&var9);

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
