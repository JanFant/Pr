#ifndef AKNP1_H
#define AKNP1_H
// Подсистема AKNP1:AKNP1_DU
static char SimulOn=0;
static short CodeSub=3;
static char SimulIP[]="192.168.1.17\0";
static int SimulPort=5555;
static int StepCycle=5;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 338
static char BUFFER[338];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.51\0", 5432, "192.168.10.151\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0EE01LZ2	 BUFFER[0]	//(R0EE01LZ2) Питание  АКНП1  отключить
#define idR0EE01LZ2	 1	//(R0EE01LZ2) Питание  АКНП1  отключить
#define R0EE01LZ1	 BUFFER[2]	//(R0EE01LZ1) Питание  АКНП1  отключить
#define idR0EE01LZ1	 2	//(R0EE01LZ1) Питание  АКНП1  отключить
#define B8VC01RDU	 BUFFER[4]	//(B8VC01RDU) Координата АЗ2, мм
#define idB8VC01RDU	 3	//(B8VC01RDU) Координата АЗ2, мм
#define A1VN71LS1	 BUFFER[9]	//(A1VN71LS1) Блокировка автоматического  подъёма ББ на БАЗ2
#define idA1VN71LS1	 4	//(A1VN71LS1) Блокировка автоматического  подъёма ББ на БАЗ2
#define A1EE01LS1	 BUFFER[11]	//(A1EE01LS1) Исправность АКНП на БАЗ2
#define idA1EE01LS1	 5	//(A1EE01LS1) Исправность АКНП на БАЗ2
#define R0VN75LZ2	 BUFFER[13]	//(R0VN75LZ2) АС по периоду разгонана БАЗ2
#define idR0VN75LZ2	 6	//(R0VN75LZ2) АС по периоду разгонана БАЗ2
#define R0VN71LZ2	 BUFFER[15]	//(R0VN71LZ2) АС по мощности на БАЗ2
#define idR0VN71LZ2	 7	//(R0VN71LZ2) АС по мощности на БАЗ2
#define R0IE02LS1	 BUFFER[17]	//(R0IE02LS1) Отключить питание ПР, ПУ
#define idR0IE02LS1	 8	//(R0IE02LS1) Отключить питание ПР, ПУ
#define R0IE01LS1	 BUFFER[19]	//(R0IE01LS1) Отключение питание детекторов
#define idR0IE01LS1	 9	//(R0IE01LS1) Отключение питание детекторов
#define A0EE03LS1	 BUFFER[21]	//(A0EE03LS1) Подключена сеть питания АКНП
#define idA0EE03LS1	 10	//(A0EE03LS1) Подключена сеть питания АКНП
#define R0VN15RS1	 BUFFER[23]	//(R0VN15RS1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
#define idR0VN15RS1	 11	//(R0VN15RS1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
#define R0VN33RS1	 BUFFER[26]	//(R0VN33RS1) Нейтронный поток по камере КНК53М
#define idR0VN33RS1	 12	//(R0VN33RS1) Нейтронный поток по камере КНК53М
#define R0VN23RS1	 BUFFER[31]	//(R0VN23RS1) Нейтронный поток по камере КНК15-1
#define idR0VN23RS1	 13	//(R0VN23RS1) Нейтронный поток по камере КНК15-1
#define R0VN13RS1	 BUFFER[36]	//(R0VN13RS1) Нейтронный поток по камере СНМ11
#define idR0VN13RS1	 14	//(R0VN13RS1) Нейтронный поток по камере СНМ11
#define R0IE13LS1	 BUFFER[41]	//(R0IE13LS1) Исправность ВИП 0,5 (№10) КНК53М 1 канала
#define idR0IE13LS1	 15	//(R0IE13LS1) Исправность ВИП 0,5 (№10) КНК53М 1 канала
#define R0IE12LS1	 BUFFER[43]	//(R0IE12LS1) Исправность ВИП 0,5 (№9) КНК15-1 1 канала
#define idR0IE12LS1	 16	//(R0IE12LS1) Исправность ВИП 0,5 (№9) КНК15-1 1 канала
#define R0IE11LS1	 BUFFER[45]	//(R0IE11LS1) Исправность ВИП 1,6 (№8) СНМ11 1 канала
#define idR0IE11LS1	 17	//(R0IE11LS1) Исправность ВИП 1,6 (№8) СНМ11 1 канала
#define A0EE02LS1	 BUFFER[47]	//(A0EE02LS1) Исправность АКНП1 (от сшивки каналов) канал 1
#define idA0EE02LS1	 18	//(A0EE02LS1) Исправность АКНП1 (от сшивки каналов) канал 1
#define R0IN03FS1	 BUFFER[49]	//(R0IN03FS1) Выход КНК53М  Гц
#define idR0IN03FS1	 19	//(R0IN03FS1) Выход КНК53М  Гц
#define A0VN71LS1	 BUFFER[54]	//(A0VN71LS1) Блокировка автоматического  подъёма ББ на БАЗ1
#define idA0VN71LS1	 20	//(A0VN71LS1) Блокировка автоматического  подъёма ББ на БАЗ1
#define R0VN04RS1	 BUFFER[56]	//(R0VN04RS1) Реактивность канал1
#define idR0VN04RS1	 21	//(R0VN04RS1) Реактивность канал1
#define R0VN03RS1	 BUFFER[61]	//(R0VN03RS1) Измеренный нейтронный поток
#define idR0VN03RS1	 22	//(R0VN03RS1) Измеренный нейтронный поток
#define R0IN02FS1	 BUFFER[66]	//(R0IN02FS1) Выход КНК15-1 Гц
#define idR0IN02FS1	 23	//(R0IN02FS1) Выход КНК15-1 Гц
#define R0IN01FS1	 BUFFER[71]	//(R0IN01FS1) Выход СНМ-11 Гц
#define idR0IN01FS1	 24	//(R0IN01FS1) Выход СНМ-11 Гц
#define A0EE01LS1	 BUFFER[76]	//(A0EE01LS1) Исправность АКНП на БАЗ1
#define idA0EE01LS1	 25	//(A0EE01LS1) Исправность АКНП на БАЗ1
#define R0VN75LZ1	 BUFFER[78]	//(R0VN75LZ1) АС по периоду разгонана БАЗ1
#define idR0VN75LZ1	 26	//(R0VN75LZ1) АС по периоду разгонана БАЗ1
#define R0VN65LS1	 BUFFER[80]	//(R0VN65LS1) ПС по периоду разгона канал1
#define idR0VN65LS1	 27	//(R0VN65LS1) ПС по периоду разгона канал1
#define R0VN71LZ1	 BUFFER[82]	//(R0VN71LZ1) АС по мощности на БАЗ1
#define idR0VN71LZ1	 28	//(R0VN71LZ1) АС по мощности на БАЗ1
#define R0VN61LS1	 BUFFER[84]	//(R0VN61LS1) ПС по мощности канал1
#define idR0VN61LS1	 29	//(R0VN61LS1) ПС по мощности канал1
#define R0VN01RS1	 BUFFER[86]	//(R0VN01RS1) Период разгона канал1
#define idR0VN01RS1	 30	//(R0VN01RS1) Период разгона канал1
#define R0VN02RS1	 BUFFER[91]	//(R0VN02RS1) Уровень мощности
#define idR0VN02RS1	 31	//(R0VN02RS1) Уровень мощности
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
#define fEM_R7UX01RSS	 BUFFER[136]	//(R7UX01RSS) X-координата камеры R7IN11
#define idfEM_R7UX01RSS	 40	//(R7UX01RSS) X-координата камеры R7IN11
#define fEM_R7UX02RSS	 BUFFER[141]	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define idfEM_R7UX02RSS	 41	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define fEM_R7UX03RSS	 BUFFER[146]	//(R7UX03RSS) X-координата камеры R7IN13 (см)
#define idfEM_R7UX03RSS	 42	//(R7UX03RSS) X-координата камеры R7IN13 (см)
#define fEM_R7UY00RSS	 BUFFER[151]	//(R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	 43	//(R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UY01RSS	 BUFFER[156]	//(R7UY01RSS) Y-координата камеры R7IN11
#define idfEM_R7UY01RSS	 44	//(R7UY01RSS) Y-координата камеры R7IN11
#define fEM_R7UY02RSS	 BUFFER[161]	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define idfEM_R7UY02RSS	 45	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define fEM_R7UY03RSS	 BUFFER[166]	//(R7UY03RSS) Y-координата камеры R7IN13 (см)
#define idfEM_R7UY03RSS	 46	//(R7UY03RSS) Y-координата камеры R7IN13 (см)
#define fEM_A0UX00RSS	 BUFFER[171]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 47	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX01RSS	 BUFFER[176]	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define idfEM_A0UX01RSS	 48	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define fEM_A0UX02RSS	 BUFFER[181]	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define idfEM_A0UX02RSS	 49	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define fEM_A0UX03RSS	 BUFFER[186]	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define idfEM_A0UX03RSS	 50	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define fEM_B0UX01RSS	 BUFFER[191]	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define idfEM_B0UX01RSS	 51	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define fEM_B0UX02RSS	 BUFFER[196]	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define idfEM_B0UX02RSS	 52	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define fEM_B0UX03RSS	 BUFFER[201]	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	 53	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
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
#define internal1_m13_Nk	 BUFFER[228]	//(internal1_m13_Nk) Nk - ведущая камера
#define idinternal1_m13_Nk	 59	//(internal1_m13_Nk) Nk - ведущая камера
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
	{ 1	,1	,1	, &R0EE01LZ2},	//(R0EE01LZ2) Питание  АКНП1  отключить
	{ 2	,1	,1	, &R0EE01LZ1},	//(R0EE01LZ1) Питание  АКНП1  отключить
	{ 3	,8	,1	, &B8VC01RDU},	//(B8VC01RDU) Координата АЗ2, мм
	{ 4	,1	,1	, &A1VN71LS1},	//(A1VN71LS1) Блокировка автоматического  подъёма ББ на БАЗ2
	{ 5	,1	,1	, &A1EE01LS1},	//(A1EE01LS1) Исправность АКНП на БАЗ2
	{ 6	,1	,1	, &R0VN75LZ2},	//(R0VN75LZ2) АС по периоду разгонана БАЗ2
	{ 7	,1	,1	, &R0VN71LZ2},	//(R0VN71LZ2) АС по мощности на БАЗ2
	{ 8	,1	,1	, &R0IE02LS1},	//(R0IE02LS1) Отключить питание ПР, ПУ
	{ 9	,1	,1	, &R0IE01LS1},	//(R0IE01LS1) Отключение питание детекторов
	{ 10	,1	,1	, &A0EE03LS1},	//(A0EE03LS1) Подключена сеть питания АКНП
	{ 11	,3	,1	, &R0VN15RS1},	//(R0VN15RS1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
	{ 12	,8	,1	, &R0VN33RS1},	//(R0VN33RS1) Нейтронный поток по камере КНК53М
	{ 13	,8	,1	, &R0VN23RS1},	//(R0VN23RS1) Нейтронный поток по камере КНК15-1
	{ 14	,8	,1	, &R0VN13RS1},	//(R0VN13RS1) Нейтронный поток по камере СНМ11
	{ 15	,1	,1	, &R0IE13LS1},	//(R0IE13LS1) Исправность ВИП 0,5 (№10) КНК53М 1 канала
	{ 16	,1	,1	, &R0IE12LS1},	//(R0IE12LS1) Исправность ВИП 0,5 (№9) КНК15-1 1 канала
	{ 17	,1	,1	, &R0IE11LS1},	//(R0IE11LS1) Исправность ВИП 1,6 (№8) СНМ11 1 канала
	{ 18	,1	,1	, &A0EE02LS1},	//(A0EE02LS1) Исправность АКНП1 (от сшивки каналов) канал 1
	{ 19	,8	,1	, &R0IN03FS1},	//(R0IN03FS1) Выход КНК53М  Гц
	{ 20	,1	,1	, &A0VN71LS1},	//(A0VN71LS1) Блокировка автоматического  подъёма ББ на БАЗ1
	{ 21	,8	,1	, &R0VN04RS1},	//(R0VN04RS1) Реактивность канал1
	{ 22	,8	,1	, &R0VN03RS1},	//(R0VN03RS1) Измеренный нейтронный поток
	{ 23	,8	,1	, &R0IN02FS1},	//(R0IN02FS1) Выход КНК15-1 Гц
	{ 24	,8	,1	, &R0IN01FS1},	//(R0IN01FS1) Выход СНМ-11 Гц
	{ 25	,1	,1	, &A0EE01LS1},	//(A0EE01LS1) Исправность АКНП на БАЗ1
	{ 26	,1	,1	, &R0VN75LZ1},	//(R0VN75LZ1) АС по периоду разгонана БАЗ1
	{ 27	,1	,1	, &R0VN65LS1},	//(R0VN65LS1) ПС по периоду разгона канал1
	{ 28	,1	,1	, &R0VN71LZ1},	//(R0VN71LZ1) АС по мощности на БАЗ1
	{ 29	,1	,1	, &R0VN61LS1},	//(R0VN61LS1) ПС по мощности канал1
	{ 30	,8	,1	, &R0VN01RS1},	//(R0VN01RS1) Период разгона канал1
	{ 31	,8	,1	, &R0VN02RS1},	//(R0VN02RS1) Уровень мощности
	{ 32	,8	,1	, &fEM_R0UR01RSS},	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
	{ 33	,8	,1	, &fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{ 34	,8	,1	, &fEM_R0UL41RSS},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{ 35	,8	,1	, &fEM_R0UL51RSS},	//(R0UL51RSS) Уровень АС по периоду разгона
	{ 36	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{ 37	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{ 38	,8	,1	, &fEM_R0UL42RSS},	//(R0UL42RSS) Уровень ПС по мощности
	{ 39	,8	,1	, &fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{ 40	,8	,1	, &fEM_R7UX01RSS},	//(R7UX01RSS) X-координата камеры R7IN11
	{ 41	,8	,1	, &fEM_R7UX02RSS},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{ 42	,8	,1	, &fEM_R7UX03RSS},	//(R7UX03RSS) X-координата камеры R7IN13 (см)
	{ 43	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{ 44	,8	,1	, &fEM_R7UY01RSS},	//(R7UY01RSS) Y-координата камеры R7IN11
	{ 45	,8	,1	, &fEM_R7UY02RSS},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{ 46	,8	,1	, &fEM_R7UY03RSS},	//(R7UY03RSS) Y-координата камеры R7IN13 (см)
	{ 47	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 48	,8	,1	, &fEM_A0UX01RSS},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{ 49	,8	,1	, &fEM_A0UX02RSS},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{ 50	,8	,1	, &fEM_A0UX03RSS},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{ 51	,8	,1	, &fEM_B0UX01RSS},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{ 52	,8	,1	, &fEM_B0UX02RSS},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{ 53	,8	,1	, &fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{ 54	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 55	,8	,1	, &fEM_R0UN03RSS},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 56	,8	,1	, &fEM_R0UL01RSS},	//(R0UL01RSS) Шаг (мс) измерения периода
	{ 57	,8	,1	, &fEM_R0UL02RSS},	//(R0UL02RSS) Предельное время ожидания роста потока (мс)
	{ 58	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 59	,3	,1	, &internal1_m13_Nk},	//(internal1_m13_Nk) Nk - ведущая камера
	{ 60	,8	,5	, &internal1_m45_tst},	//(internal1_m45_tst) - массив времени фиксации стартовой мощности
	{ 61	,8	,5	, &internal1_m45_trz},	//(internal1_m45_trz) - массив времени фиксации очередного периода
	{ 62	,8	,5	, &internal1_m45_N1},	//(internal1_m45_N1) - массив значения мощности в начале замера
	{ 63	,8	,5	, &internal1_m45_N2},	//(internal1_m45_N2) - массив значения мощности в конце замера
	{ 64	,8	,1	, &internal1_m45_Period0},	//(internal1_m45_Period0) Per - Период разгона РУ
	{ 65	,1	,1	, &internal1_m45_MyFirstEnterFlag},	//(internal1_m45_MyFirstEnterFlag)  FirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="aknp1.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
   {32,"fEM_R0UR01RSS\0"}, 
   {33,"fEM_R0UL52RSS\0"}, 
   {34,"fEM_R0UL41RSS\0"}, 
   {35,"fEM_R0UL51RSS\0"}, 
   {36,"fEM_R0UH02RSS\0"}, 
   {37,"fEM_R0UH03RSS\0"}, 
   {38,"fEM_R0UL42RSS\0"}, 
   {39,"fEM_R7UX00RSS\0"}, 
   {40,"fEM_R7UX01RSS\0"}, 
   {41,"fEM_R7UX02RSS\0"}, 
   {42,"fEM_R7UX03RSS\0"}, 
   {43,"fEM_R7UY00RSS\0"}, 
   {44,"fEM_R7UY01RSS\0"}, 
   {45,"fEM_R7UY02RSS\0"}, 
   {46,"fEM_R7UY03RSS\0"}, 
   {47,"fEM_A0UX00RSS\0"}, 
   {48,"fEM_A0UX01RSS\0"}, 
   {49,"fEM_A0UX02RSS\0"}, 
   {50,"fEM_A0UX03RSS\0"}, 
   {51,"fEM_B0UX01RSS\0"}, 
   {52,"fEM_B0UX02RSS\0"}, 
   {53,"fEM_B0UX03RSS\0"}, 
   {54,"fEM_R0UH05RSS\0"}, 
   {55,"fEM_R0UN03RSS\0"}, 
   {56,"fEM_R0UL01RSS\0"}, 
   {57,"fEM_R0UL02RSS\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_AKNP1[]={  // 
	{&R0EE01LZ2,1,0},	//(R0EE01LZ2) Питание  АКНП1  отключить
	{&R0EE01LZ1,1,1},	//(R0EE01LZ1) Питание  АКНП1  отключить
	{&A0EE03LS1,1,2},	//(A0EE03LS1) Подключена сеть питания АКНП
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_AKNP1[]={  // 
	{&A0EE02LS1,1,0},	//(A0EE02LS1) Исправность АКНП1 (от сшивки каналов) канал 1
	{&R0VN65LS1,1,1},	//(R0VN65LS1) ПС по периоду разгона канал1
	{&R0VN61LS1,1,2},	//(R0VN61LS1) ПС по мощности канал1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_AKNP1[]={  // 
	{&R0VN15RS1,3,0},	//(R0VN15RS1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
	{&R0VN33RS1,8,1},	//(R0VN33RS1) Нейтронный поток по камере КНК53М
	{&R0VN23RS1,8,3},	//(R0VN23RS1) Нейтронный поток по камере КНК15-1
	{&R0VN13RS1,8,5},	//(R0VN13RS1) Нейтронный поток по камере СНМ11
	{&R0IN03FS1,8,7},	//(R0IN03FS1) Выход КНК53М  Гц
	{&R0VN04RS1,8,9},	//(R0VN04RS1) Реактивность канал1
	{&R0VN03RS1,8,11},	//(R0VN03RS1) Измеренный нейтронный поток
	{&R0IN02FS1,8,13},	//(R0IN02FS1) Выход КНК15-1 Гц
	{&R0VN01RS1,8,15},	//(R0VN01RS1) Период разгона канал1
	{&R0VN02RS1,8,17},	//(R0VN02RS1) Уровень мощности
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_AKNP1[]={  // 
	{&B8VC01RDU,8,0},	//(B8VC01RDU) Координата АЗ2, мм
	{&R0IN01FS1,8,2},	//(R0IN01FS1) Выход СНМ-11 Гц
	{&fEM_R0UR01RSS,8,4},	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
	{&fEM_R0UL52RSS,8,6},	//(R0UL52RSS) Уровень АС по мощности
	{&fEM_R0UL41RSS,8,8},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{&fEM_R0UL51RSS,8,10},	//(R0UL51RSS) Уровень АС по периоду разгона
	{&fEM_R0UH02RSS,8,12},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{&fEM_R0UH03RSS,8,14},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{&fEM_R0UL42RSS,8,16},	//(R0UL42RSS) Уровень ПС по мощности
	{&fEM_R7UX00RSS,8,18},	//(R7UX00RSS) X-координата АЗ1 (см)
	{&fEM_R7UX01RSS,8,20},	//(R7UX01RSS) X-координата камеры R7IN11
	{&fEM_R7UX02RSS,8,22},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{&fEM_R7UX03RSS,8,24},	//(R7UX03RSS) X-координата камеры R7IN13 (см)
	{&fEM_R7UY00RSS,8,26},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{&fEM_R7UY01RSS,8,28},	//(R7UY01RSS) Y-координата камеры R7IN11
	{&fEM_R7UY02RSS,8,30},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{&fEM_R7UY03RSS,8,32},	//(R7UY03RSS) Y-координата камеры R7IN13 (см)
	{&fEM_A0UX00RSS,8,34},	//(A0UX00RSS) Эффективный радиус АЗ
	{&fEM_A0UX01RSS,8,36},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{&fEM_A0UX02RSS,8,38},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{&fEM_A0UX03RSS,8,40},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{&fEM_B0UX01RSS,8,42},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{&fEM_B0UX02RSS,8,44},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{&fEM_B0UX03RSS,8,46},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{&fEM_R0UH05RSS,8,48},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_R0UN03RSS,8,50},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{&fEM_R0UL01RSS,8,52},	//(R0UL01RSS) Шаг (мс) измерения периода
	{&fEM_R0UL02RSS,8,54},	//(R0UL02RSS) Предельное время ожидания роста потока (мс)
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,502,&coil_AKNP1[0],&di_AKNP1[0],&ir_AKNP1[0],&hr_AKNP1[0],NULL,NULL,NULL,0},	 //общий slave

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
	{&R0IN02FS1,8,5},
	{&R0IN01FS1,8,0},
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
	{&R0IN03FS1,8,0},
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
	{&R0IE11LS1,1,0},
	{&R0IE12LS1,1,2},
	{&R0IE13LS1,1,4},
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
	{&R0IE01LS1,1,2},
	{&R0VN71LZ1,1,16},
	{&A1VN71LS1,1,30},
	{&R0VN75LZ1,1,18},
	{&A0EE01LS1,1,20},
	{&A1EE01LS1,1,28},
	{&R0VN75LZ2,1,26},
	{&A0VN71LS1,1,22},
	{&R0VN71LZ2,1,24},
	{&R0IE02LS1,1,0},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc4,0x01,12,670,def_buf_VCHS01,&table_VCHS01}, //VCHS01
	{0xc4,0x02,12,670,def_buf_VCHS02,&table_VCHS02}, //VCHS02
	{0xc2,0x04,15,64,def_buf_VDS32,&table_VDS32}, //VDS32
	{0x04,0x05,20,38,def_buf_FDS16,&table_FDS16}, //FDS16
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
	setAsFloat(32,10);
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
	setAsFloat(44,248.0);
	setAsFloat(45,284.5);
	setAsFloat(46,256.0);
	setAsFloat(47,11.0);
	setAsFloat(48,1.0);
	setAsFloat(49,1.0);
	setAsFloat(50,1.0);
	setAsFloat(51,0);
	setAsFloat(52,0);
	setAsFloat(53,0);
	setAsFloat(54,32000.0);
	setAsFloat(55,0.005);
	setAsFloat(56,0.5);
	setAsFloat(57,100);
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
ssint iRM_5_ = {5,0}; /* n - N-размерность массива x */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - коэфф. преобразования частота->нейтр/с СНМ-11 */ 
sschar bRM_2_ = {2,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 

uspaint8 SpaEEPROMBuf[130];

/* Определение переменных */
ssbool var1;
ssbool var2;
ssbool var3;
ssfloat var4;
ssfloat var5;
ssbool var6;
ssfloat var7;
ssfloat var8;
ssfloat var9;
ssint var10;
ssbool var11;
ssfloat var12;
ssbool var13;
ssbool var14;
ssbool var15;
ssbool var16;
ssbool var17;
ssfloat var18;
ssbool var19;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psfloat  array_m45_tst_1[5];
psfloat  array_m45_trz_1[5];
psfloat  array_m45_N1_1[5];
psfloat  array_m45_N2_1[5];

/* Объявление структур */
_S_and5  S_and5_62_1 = {&var6,&R0IE13LS1,&A0EE03LS1,&R0IE11LS1,&R0IE12LS1,&var1};
_S_and2  S_and2_58_1 = {&var16,&var13,&var2};
_S_and2  S_and2_57_1 = {&var17,&var16,&var3};
_S_ocham  S_ocham_13_1 = {&R0IN03FS1,&R0IN02FS1,&R0IN01FS1,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX01RSS,&fEM_B0UX01RSS,&fEM_A0UX02RSS,&fEM_B0UX02RSS,&fEM_A0UX03RSS,&fEM_B0UX03RSS,&fEM_R7UX01RSS,&fEM_R7UY01RSS,&fEM_R7UX02RSS,&fEM_R7UY02RSS,&fEM_R7UX03RSS,&fEM_R7UY03RSS,&bRM_2_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var4,&var5,&var6,&var7,&var8,&var9,&var10,&internal1_m13_Nk};
_S_or2  S_or2_68_1 = {&R0EE01LZ1,&R0EE01LZ2,&var11};
_S_period  S_period_45_1 = {&var5,&var1,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var12,array_m45_tst_1,array_m45_trz_1,array_m45_N1_1,array_m45_N2_1,&internal1_m45_Period0,&internal1_m45_MyFirstEnterFlag};
_S_bol  S_bol_51_1 = {&fEM_R0UL41RSS,&var12,&var13};
_S_bol  S_bol_36_1 = {&var5,&fEM_R0UL52RSS,&var14};
_S_bol  S_bol_31_1 = {&var5,&fEM_R0UL42RSS,&var15};
_S_bol  S_bol_50_1 = {&var5,&fEM_R0UN03RSS,&var16};
_S_bol  S_bol_49_1 = {&fEM_R0UL51RSS,&var12,&var17};
_S_react  S_react_46_1 = {&var12,&var18};
_S_bol  S_bol_39_1 = {&var5,&fEM_R0UR01RSS,&var19};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_68_1);
  ocham(&S_ocham_13_1);
  and5(&S_and5_62_1);
  bol(&S_bol_39_1);
  bol(&S_bol_50_1);
  bol(&S_bol_31_1);
  bol(&S_bol_36_1);
  period(&S_period_45_1);
  react(&S_react_46_1);
  bol(&S_bol_49_1);
  bol(&S_bol_51_1);
  and2(&S_and2_57_1);
  and2(&S_and2_58_1);
  setData(idA1VN71LS1,&var19);
  setData(idA1EE01LS1,&var1);
  setData(idR0VN75LZ2,&var3);
  setData(idR0VN71LZ2,&var14);
  setData(idR0IE02LS1,&var11);
  setData(idR0IE01LS1,&var11);
  setData(idR0VN15RS1,&var10);
  setData(idR0VN33RS1,&var9);
  setData(idR0VN23RS1,&var8);
  setData(idR0VN13RS1,&var7);
  setData(idA0EE02LS1,&var6);
  setData(idA0VN71LS1,&var19);
  setData(idR0VN04RS1,&var18);
  setData(idR0VN03RS1,&var4);
  setData(idA0EE01LS1,&var1);
  setData(idR0VN75LZ1,&var3);
  setData(idR0VN65LS1,&var2);
  setData(idR0VN71LZ1,&var14);
  setData(idR0VN61LS1,&var15);
  setData(idR0VN01RS1,&var12);
  setData(idR0VN02RS1,&var5);

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
