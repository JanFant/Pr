#ifndef AKNP3_H
#define AKNP3_H
// Подсистема AKNP3:AKNP3
static char SimulOn=0;
static short CodeSub=5;
static char SimulIP[]="192.168.1.17\0";
static int SimulPort=5555;
static int StepCycle=5;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 338
static char BUFFER[338];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.53\0", 5432, "192.168.10.153\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0EE03LZ2	 BUFFER[0]	//(R0EE03LZ2) Питание  АКНП3  отключить
#define idR0EE03LZ2	 1	//(R0EE03LZ2) Питание  АКНП3  отключить
#define R0EE03LZ1	 BUFFER[2]	//(R0EE03LZ1) Питание  АКНП3  отключить
#define idR0EE03LZ1	 2	//(R0EE03LZ1) Питание  АКНП3  отключить
#define B8VC01RDU	 BUFFER[4]	//(B8VC01RDU) Координата АЗ2, мм
#define idB8VC01RDU	 3	//(B8VC01RDU) Координата АЗ2, мм
#define A1EE01LS3	 BUFFER[9]	//(A1EE01LS3) Исправность АКНП канал 3 на БАЗ2
#define idA1EE01LS3	 4	//(A1EE01LS3) Исправность АКНП канал 3 на БАЗ2
#define R0VN77LZ2	 BUFFER[11]	//(R0VN77LZ2) АС по периоду разгона канал 3 на БАЗ2
#define idR0VN77LZ2	 5	//(R0VN77LZ2) АС по периоду разгона канал 3 на БАЗ2
#define R0VN73LZ2	 BUFFER[13]	//(R0VN73LZ2) АС по мощности канал 3 на БАЗ2
#define idR0VN73LZ2	 6	//(R0VN73LZ2) АС по мощности канал 3 на БАЗ2
#define A0VN71LS3	 BUFFER[15]	//(A0VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
#define idA0VN71LS3	 7	//(A0VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
#define R0IE02LS3	 BUFFER[17]	//(R0IE02LS3) Отключить питание ПР, ПУ канал 3
#define idR0IE02LS3	 8	//(R0IE02LS3) Отключить питание ПР, ПУ канал 3
#define R0IE01LS3	 BUFFER[19]	//(R0IE01LS3) Отключение питание детекторов канал 3
#define idR0IE01LS3	 9	//(R0IE01LS3) Отключение питание детекторов канал 3
#define A0EE03LS3	 BUFFER[21]	//(A0EE03LS3) Подключена сеть питания АКНП канал 3
#define idA0EE03LS3	 10	//(A0EE03LS3) Подключена сеть питания АКНП канал 3
#define R0VN15RS3	 BUFFER[23]	//(R0VN15RS3) Номер ведущей камеры канал 3
#define idR0VN15RS3	 11	//(R0VN15RS3) Номер ведущей камеры канал 3
#define R0VN33RS3	 BUFFER[26]	//(R0VN33RS3) Нейтронный поток по камере КНК53М канал 3
#define idR0VN33RS3	 12	//(R0VN33RS3) Нейтронный поток по камере КНК53М канал 3
#define R0VN23RS3	 BUFFER[31]	//(R0VN23RS3) Нейтронный поток по камере КНК15-1 канал 3
#define idR0VN23RS3	 13	//(R0VN23RS3) Нейтронный поток по камере КНК15-1 канал 3
#define R0VN13RS3	 BUFFER[36]	//(R0VN13RS3) Нейтронный поток по камере СНМ11 канал 3
#define idR0VN13RS3	 14	//(R0VN13RS3) Нейтронный поток по камере СНМ11 канал 3
#define R0IE13LS3	 BUFFER[41]	//(R0IE13LS3) Исправность ВИП 0,5 (№16) КНК53М 3 канала
#define idR0IE13LS3	 15	//(R0IE13LS3) Исправность ВИП 0,5 (№16) КНК53М 3 канала
#define R0IE12LS3	 BUFFER[43]	//(R0IE12LS3) Исправность ВИП 0,5 (№15) КНК15-1 3 канала
#define idR0IE12LS3	 16	//(R0IE12LS3) Исправность ВИП 0,5 (№15) КНК15-1 3 канала
#define R0IE11LS3	 BUFFER[45]	//(R0IE11LS3) Исправность ВИП 1,6 (№14) СНМ11 3 канала
#define idR0IE11LS3	 17	//(R0IE11LS3) Исправность ВИП 1,6 (№14) СНМ11 3 канала
#define A0EE02LS3	 BUFFER[47]	//(A0EE02LS3) Исправность АКНП3 (от сшивки каналов) канал 3
#define idA0EE02LS3	 18	//(A0EE02LS3) Исправность АКНП3 (от сшивки каналов) канал 3
#define R0IN03FS3	 BUFFER[49]	//(R0IN03FS3) Выход КНК53М Гц
#define idR0IN03FS3	 19	//(R0IN03FS3) Выход КНК53М Гц
#define A1VN71LS3	 BUFFER[54]	//(A1VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
#define idA1VN71LS3	 20	//(A1VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
#define R0VN04RS3	 BUFFER[56]	//(R0VN04RS3) Реактивность канал 3
#define idR0VN04RS3	 21	//(R0VN04RS3) Реактивность канал 3
#define R0VN03RS3	 BUFFER[61]	//(R0VN03RS3) Измеренный нейтронный поток канал 3
#define idR0VN03RS3	 22	//(R0VN03RS3) Измеренный нейтронный поток канал 3
#define R0IN02FS3	 BUFFER[66]	//(R0IN02FS3) Выход КНК15-1 Гц
#define idR0IN02FS3	 23	//(R0IN02FS3) Выход КНК15-1 Гц
#define R0IN01FS3	 BUFFER[71]	//(R0IN01FS3) Выход СНМ-11 Гц
#define idR0IN01FS3	 24	//(R0IN01FS3) Выход СНМ-11 Гц
#define A0EE01LS3	 BUFFER[76]	//(A0EE01LS3) Исправность АКНП канал 3 на БАЗ1
#define idA0EE01LS3	 25	//(A0EE01LS3) Исправность АКНП канал 3 на БАЗ1
#define R0VN77LZ1	 BUFFER[78]	//(R0VN77LZ1) АС по периоду разгона канал 3 на БАЗ1
#define idR0VN77LZ1	 26	//(R0VN77LZ1) АС по периоду разгона канал 3 на БАЗ1
#define R0VN65LS3	 BUFFER[80]	//(R0VN65LS3) ПС по периоду разгона канал 3
#define idR0VN65LS3	 27	//(R0VN65LS3) ПС по периоду разгона канал 3
#define R0VN73LZ1	 BUFFER[82]	//(R0VN73LZ1) АС по мощности канал 3 на БАЗ1
#define idR0VN73LZ1	 28	//(R0VN73LZ1) АС по мощности канал 3 на БАЗ1
#define R0VN61LS3	 BUFFER[84]	//(R0VN61LS3) ПС по мощности канал 3
#define idR0VN61LS3	 29	//(R0VN61LS3) ПС по мощности канал 3
#define R0VN01RS3	 BUFFER[86]	//(R0VN01RS3) Период разгона канал 3
#define idR0VN01RS3	 30	//(R0VN01RS3) Период разгона канал 3
#define R0VN02RS3	 BUFFER[91]	//(R0VN02RS3) Уровень мощности канал 3
#define idR0VN02RS3	 31	//(R0VN02RS3) Уровень мощности канал 3
#define fEM_R0UR01RSS	 BUFFER[96]	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RSS	 32	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R0UL52RSS	 BUFFER[101]	//(R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	 33	//(R0UL52RSS) Уровень АС по мощности
#define fEM_R0UL41RSS	 BUFFER[106]	//(R0UL41RSS) Уровень ПС по периоду разгона
#define idfEM_R0UL41RSS	 34	//(R0UL41RSS) Уровень ПС по периоду разгона
#define fEM_R0UL51RSS	 BUFFER[111]	//(R0UL51RSS) Уровень АС по периоду разгона
#define idfEM_R0UL51RSS	 35	//(R0UL51RSS) Уровень АС по периоду разгона
#define fEM_R0UH02RSS	 BUFFER[116]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define idfEM_R0UH02RSS	 36	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define fEM_R0UH03RSS	 BUFFER[121]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define idfEM_R0UH03RSS	 37	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define fEM_R0UL42RSS	 BUFFER[126]	//(R0UL42RSS) Уровень ПС по мощности
#define idfEM_R0UL42RSS	 38	//(R0UL42RSS) Уровень ПС по мощности
#define fEM_R7UX00RSS	 BUFFER[131]	//(R7UX00RSS) X-координата АЗ1 (см)
#define idfEM_R7UX00RSS	 39	//(R7UX00RSS) X-координата АЗ1 (см)
#define fEM_R7UX07RSS	 BUFFER[136]	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define idfEM_R7UX07RSS	 40	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define fEM_R7UX08RSS	 BUFFER[141]	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define idfEM_R7UX08RSS	 41	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define fEM_R7UX09RSS	 BUFFER[146]	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define idfEM_R7UX09RSS	 42	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define fEM_R7UY00RSS	 BUFFER[151]	//(R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	 43	//(R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UY07RSS	 BUFFER[156]	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define idfEM_R7UY07RSS	 44	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define fEM_R7UY08RSS	 BUFFER[161]	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define idfEM_R7UY08RSS	 45	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define fEM_R7UY09RSS	 BUFFER[166]	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define idfEM_R7UY09RSS	 46	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define fEM_A0UX00RSS	 BUFFER[171]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 47	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX07RSS	 BUFFER[176]	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define idfEM_A0UX07RSS	 48	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define fEM_A0UX08RSS	 BUFFER[181]	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define idfEM_A0UX08RSS	 49	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define fEM_A0UX09RSS	 BUFFER[186]	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define idfEM_A0UX09RSS	 50	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define fEM_B0UX07RSS	 BUFFER[191]	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define idfEM_B0UX07RSS	 51	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define fEM_B0UX08RSS	 BUFFER[196]	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define idfEM_B0UX08RSS	 52	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define fEM_B0UX09RSS	 BUFFER[201]	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define idfEM_B0UX09RSS	 53	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define fEM_R0UH05RSS	 BUFFER[206]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 54	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UN03RSS	 BUFFER[211]	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN03RSS	 55	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R0UL01RSS	 BUFFER[216]	//(R0UL01RSS) Шаг (мс) измерения периода
#define idfEM_R0UL01RSS	 56	//(R0UL01RSS) Шаг (мс) измерения периода
#define fEM_R0UL02RSS	 BUFFER[221]	//(R0UL02RSS) Предельное время ожидания роста потока (мс)
#define idfEM_R0UL02RSS	 57	//(R0UL02RSS) Предельное время ожидания роста потока (мс)
#define bFirstEnterFlag	 BUFFER[226]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 58	//(bFirstEnterFlag) 
#define internal1_m17_Nk	 BUFFER[228]	//(internal1_m17_Nk) Nk - ведущая камера
#define idinternal1_m17_Nk	 59	//(internal1_m17_Nk) Nk - ведущая камера
#define internal1_m45_tst	 BUFFER[231]	//(internal1_m45_tst) - массив времени фиксации стартовой мощности
#define idinternal1_m45_tst	 60	//(internal1_m45_tst) - массив времени фиксации стартовой мощности
#define internal1_m45_trz	 BUFFER[256]	//(internal1_m45_trz) - массив времени фиксации очередного периода
#define idinternal1_m45_trz	 61	//(internal1_m45_trz) - массив времени фиксации очередного периода
#define internal1_m45_N1	 BUFFER[281]	//(internal1_m45_N1) - массив значения мощности в начале замера
#define idinternal1_m45_N1	 62	//(internal1_m45_N1) - массив значения мощности в начале замера
#define internal1_m45_N2	 BUFFER[306]	//(internal1_m45_N2) - массив значения мощности в конце замера
#define idinternal1_m45_N2	 63	//(internal1_m45_N2) - массив значения мощности в конце замера
#define internal1_m45_Period0	 BUFFER[331]	//(internal1_m45_Period0) Per - Период разгона РУ
#define idinternal1_m45_Period0	 64	//(internal1_m45_Period0) Per - Период разгона РУ
#define internal1_m45_MyFirstEnterFlag	 BUFFER[336]	//(internal1_m45_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m45_MyFirstEnterFlag	 65	//(internal1_m45_MyFirstEnterFlag)  FirstEnterFlag
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &R0EE03LZ2},	//(R0EE03LZ2) Питание  АКНП3  отключить
	{ 2	,1	,1	, &R0EE03LZ1},	//(R0EE03LZ1) Питание  АКНП3  отключить
	{ 3	,8	,1	, &B8VC01RDU},	//(B8VC01RDU) Координата АЗ2, мм
	{ 4	,1	,1	, &A1EE01LS3},	//(A1EE01LS3) Исправность АКНП канал 3 на БАЗ2
	{ 5	,1	,1	, &R0VN77LZ2},	//(R0VN77LZ2) АС по периоду разгона канал 3 на БАЗ2
	{ 6	,1	,1	, &R0VN73LZ2},	//(R0VN73LZ2) АС по мощности канал 3 на БАЗ2
	{ 7	,1	,1	, &A0VN71LS3},	//(A0VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
	{ 8	,1	,1	, &R0IE02LS3},	//(R0IE02LS3) Отключить питание ПР, ПУ канал 3
	{ 9	,1	,1	, &R0IE01LS3},	//(R0IE01LS3) Отключение питание детекторов канал 3
	{ 10	,1	,1	, &A0EE03LS3},	//(A0EE03LS3) Подключена сеть питания АКНП канал 3
	{ 11	,3	,1	, &R0VN15RS3},	//(R0VN15RS3) Номер ведущей камеры канал 3
	{ 12	,8	,1	, &R0VN33RS3},	//(R0VN33RS3) Нейтронный поток по камере КНК53М канал 3
	{ 13	,8	,1	, &R0VN23RS3},	//(R0VN23RS3) Нейтронный поток по камере КНК15-1 канал 3
	{ 14	,8	,1	, &R0VN13RS3},	//(R0VN13RS3) Нейтронный поток по камере СНМ11 канал 3
	{ 15	,1	,1	, &R0IE13LS3},	//(R0IE13LS3) Исправность ВИП 0,5 (№16) КНК53М 3 канала
	{ 16	,1	,1	, &R0IE12LS3},	//(R0IE12LS3) Исправность ВИП 0,5 (№15) КНК15-1 3 канала
	{ 17	,1	,1	, &R0IE11LS3},	//(R0IE11LS3) Исправность ВИП 1,6 (№14) СНМ11 3 канала
	{ 18	,1	,1	, &A0EE02LS3},	//(A0EE02LS3) Исправность АКНП3 (от сшивки каналов) канал 3
	{ 19	,8	,1	, &R0IN03FS3},	//(R0IN03FS3) Выход КНК53М Гц
	{ 20	,1	,1	, &A1VN71LS3},	//(A1VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
	{ 21	,8	,1	, &R0VN04RS3},	//(R0VN04RS3) Реактивность канал 3
	{ 22	,8	,1	, &R0VN03RS3},	//(R0VN03RS3) Измеренный нейтронный поток канал 3
	{ 23	,8	,1	, &R0IN02FS3},	//(R0IN02FS3) Выход КНК15-1 Гц
	{ 24	,8	,1	, &R0IN01FS3},	//(R0IN01FS3) Выход СНМ-11 Гц
	{ 25	,1	,1	, &A0EE01LS3},	//(A0EE01LS3) Исправность АКНП канал 3 на БАЗ1
	{ 26	,1	,1	, &R0VN77LZ1},	//(R0VN77LZ1) АС по периоду разгона канал 3 на БАЗ1
	{ 27	,1	,1	, &R0VN65LS3},	//(R0VN65LS3) ПС по периоду разгона канал 3
	{ 28	,1	,1	, &R0VN73LZ1},	//(R0VN73LZ1) АС по мощности канал 3 на БАЗ1
	{ 29	,1	,1	, &R0VN61LS3},	//(R0VN61LS3) ПС по мощности канал 3
	{ 30	,8	,1	, &R0VN01RS3},	//(R0VN01RS3) Период разгона канал 3
	{ 31	,8	,1	, &R0VN02RS3},	//(R0VN02RS3) Уровень мощности канал 3
	{ 32	,8	,1	, &fEM_R0UR01RSS},	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
	{ 33	,8	,1	, &fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{ 34	,8	,1	, &fEM_R0UL41RSS},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{ 35	,8	,1	, &fEM_R0UL51RSS},	//(R0UL51RSS) Уровень АС по периоду разгона
	{ 36	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{ 37	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{ 38	,8	,1	, &fEM_R0UL42RSS},	//(R0UL42RSS) Уровень ПС по мощности
	{ 39	,8	,1	, &fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{ 40	,8	,1	, &fEM_R7UX07RSS},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{ 41	,8	,1	, &fEM_R7UX08RSS},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{ 42	,8	,1	, &fEM_R7UX09RSS},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{ 43	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{ 44	,8	,1	, &fEM_R7UY07RSS},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{ 45	,8	,1	, &fEM_R7UY08RSS},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{ 46	,8	,1	, &fEM_R7UY09RSS},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{ 47	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 48	,8	,1	, &fEM_A0UX07RSS},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{ 49	,8	,1	, &fEM_A0UX08RSS},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{ 50	,8	,1	, &fEM_A0UX09RSS},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{ 51	,8	,1	, &fEM_B0UX07RSS},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{ 52	,8	,1	, &fEM_B0UX08RSS},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{ 53	,8	,1	, &fEM_B0UX09RSS},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{ 54	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 55	,8	,1	, &fEM_R0UN03RSS},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 56	,8	,1	, &fEM_R0UL01RSS},	//(R0UL01RSS) Шаг (мс) измерения периода
	{ 57	,8	,1	, &fEM_R0UL02RSS},	//(R0UL02RSS) Предельное время ожидания роста потока (мс)
	{ 58	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 59	,3	,1	, &internal1_m17_Nk},	//(internal1_m17_Nk) Nk - ведущая камера
	{ 60	,8	,5	, &internal1_m45_tst},	//(internal1_m45_tst) - массив времени фиксации стартовой мощности
	{ 61	,8	,5	, &internal1_m45_trz},	//(internal1_m45_trz) - массив времени фиксации очередного периода
	{ 62	,8	,5	, &internal1_m45_N1},	//(internal1_m45_N1) - массив значения мощности в начале замера
	{ 63	,8	,5	, &internal1_m45_N2},	//(internal1_m45_N2) - массив значения мощности в конце замера
	{ 64	,8	,1	, &internal1_m45_Period0},	//(internal1_m45_Period0) Per - Период разгона РУ
	{ 65	,1	,1	, &internal1_m45_MyFirstEnterFlag},	//(internal1_m45_MyFirstEnterFlag)  FirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="aknp3.bin\0";   // Имя файла для сохранения констант
#pragma pop
static short saveVariables[]={      // Id переменных для сохранения
32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,-1,};
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
	{&A0EE02LS3,1,0},	//(A0EE02LS3) Исправность АКНП3 (от сшивки каналов) канал 3
	{&R0VN65LS3,1,1},	//(R0VN65LS3) ПС по периоду разгона канал 3
	{&R0VN61LS3,1,2},	//(R0VN61LS3) ПС по мощности канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_AKNP3[]={  // 
	{&R0VN15RS3,3,0},	//(R0VN15RS3) Номер ведущей камеры канал 3
	{&R0VN33RS3,8,1},	//(R0VN33RS3) Нейтронный поток по камере КНК53М канал 3
	{&R0VN23RS3,8,3},	//(R0VN23RS3) Нейтронный поток по камере КНК15-1 канал 3
	{&R0VN13RS3,8,5},	//(R0VN13RS3) Нейтронный поток по камере СНМ11 канал 3
	{&R0VN04RS3,8,7},	//(R0VN04RS3) Реактивность канал 3
	{&R0VN03RS3,8,9},	//(R0VN03RS3) Измеренный нейтронный поток канал 3
	{&R0VN01RS3,8,11},	//(R0VN01RS3) Период разгона канал 3
	{&R0VN02RS3,8,13},	//(R0VN02RS3) Уровень мощности канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_AKNP3[]={  // 
	{&B8VC01RDU,8,0},	//(B8VC01RDU) Координата АЗ2, мм
	{&R0IN03FS3,8,2},	//(R0IN03FS3) Выход КНК53М Гц
	{&R0IN02FS3,8,4},	//(R0IN02FS3) Выход КНК15-1 Гц
	{&R0IN01FS3,8,6},	//(R0IN01FS3) Выход СНМ-11 Гц
	{&fEM_R0UR01RSS,8,8},	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
	{&fEM_R0UL52RSS,8,10},	//(R0UL52RSS) Уровень АС по мощности
	{&fEM_R0UL41RSS,8,12},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{&fEM_R0UL51RSS,8,14},	//(R0UL51RSS) Уровень АС по периоду разгона
	{&fEM_R0UH02RSS,8,16},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{&fEM_R0UH03RSS,8,18},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{&fEM_R0UL42RSS,8,20},	//(R0UL42RSS) Уровень ПС по мощности
	{&fEM_R7UX00RSS,8,22},	//(R7UX00RSS) X-координата АЗ1 (см)
	{&fEM_R7UX07RSS,8,24},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{&fEM_R7UX08RSS,8,26},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{&fEM_R7UX09RSS,8,28},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{&fEM_R7UY00RSS,8,30},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{&fEM_R7UY07RSS,8,32},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{&fEM_R7UY08RSS,8,34},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{&fEM_R7UY09RSS,8,36},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{&fEM_A0UX00RSS,8,38},	//(A0UX00RSS) Эффективный радиус АЗ
	{&fEM_A0UX07RSS,8,40},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{&fEM_A0UX08RSS,8,42},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{&fEM_A0UX09RSS,8,44},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{&fEM_B0UX07RSS,8,46},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{&fEM_B0UX08RSS,8,48},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{&fEM_B0UX09RSS,8,50},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{&fEM_R0UH05RSS,8,52},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_R0UN03RSS,8,54},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{&fEM_R0UL01RSS,8,56},	//(R0UL01RSS) Шаг (мс) измерения периода
	{&fEM_R0UL02RSS,8,58},	//(R0UL02RSS) Предельное время ожидания роста потока (мс)
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,502,&coil_AKNP3[0],&di_AKNP3[0],&ir_AKNP3[0],&hr_AKNP3[0],NULL,NULL,NULL,0},	 //общий slave AKNP3

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
	{&R0IN02FS3,8,5},
	{&R0IN01FS3,8,0},
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
	{&R0IN03FS3,8,0},
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
	{&R0IE11LS3,1,0},
	{&R0IE12LS3,1,2},
	{&R0IE13LS3,1,4},
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
	{&R0IE01LS3,1,2},
	{&R0VN73LZ1,1,16},
	{&A1EE01LS3,1,28},
	{&R0VN77LZ1,1,18},
	{&A0EE01LS3,1,20},
	{&R0VN77LZ2,1,26},
	{&R0VN73LZ2,1,24},
	{&A1VN71LS3,1,30},
	{&A0VN71LS3,1,22},
	{&R0IE02LS3,1,0},
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
	{0xc2,0x04,15,64,def_buf_VDS32,&table_VDS32}, //VDS32
	{0x04,0x05,20,38,def_buf_FDS16,&table_FDS16}, //FDS16
	{0x01,0x20,4,26,def_buf_SBKFP,&table_SBKFP}, //SBKFP
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
	setAsFloat(32,10.0);
	setAsFloat(33,5100);
	setAsFloat(34,20);
	setAsFloat(35,13.0);
	setAsFloat(36,3703.704 );
	setAsFloat(37,62500.0);
	setAsFloat(38,5000);
	setAsFloat(39,1567.36);
	setAsFloat(40,1585.0);
	setAsFloat(41,1796.0);
	setAsFloat(42,1269.0);
	setAsFloat(43,506.6);
	setAsFloat(44,594.0);
	setAsFloat(45,559.0);
	setAsFloat(46,588.0);
	setAsFloat(47,11.0);
	setAsFloat(48,1.0);
	setAsFloat(49,1.0);
	setAsFloat(50,1.0);
	setAsFloat(51,0.0);
	setAsFloat(52,0);
	setAsFloat(53,0.0);
	setAsFloat(54,32000.0);
	setAsFloat(55,0.005);
	setAsFloat(56,0.5);
	setAsFloat(57,100.0);
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

void Scheme(void)
{
}
#endif
