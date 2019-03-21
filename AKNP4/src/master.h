#ifndef AKNP4_H
#define AKNP4_H
// Подсистема AKNP4:AKNP4
static char SimulOn=0;
static short CodeSub=7;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=8;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 399
static char BUFFER[399];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.55\0", 5432, "192.168.10.155\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0EE04LZ1	 BUFFER[0]	//( - , AKNP4) Питание  АКНП4  отключить
#define idR0EE04LZ1	 1	//( - , AKNP4) Питание  АКНП4  отключить
#define R0EE04LZ2	 BUFFER[2]	//( - , AKNP4) Питание  АКНП4  отключить
#define idR0EE04LZ2	 2	//( - , AKNP4) Питание  АКНП4  отключить
#define R0DE01LS4	 BUFFER[4]	//(vchs:01 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 1 месте
#define idR0DE01LS4	 3	//(vchs:01 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 1 месте
#define R0DE02LS4	 BUFFER[7]	//(vchs:02 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 2 месте
#define idR0DE02LS4	 4	//(vchs:02 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 2 месте
#define R0DE04LS4	 BUFFER[10]	//(vds32:04 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 4 месте
#define idR0DE04LS4	 5	//(vds32:04 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 4 месте
#define R0DE05LS4	 BUFFER[13]	//(fds16:05 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 5 месте
#define idR0DE05LS4	 6	//(fds16:05 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 5 месте
#define R0DE31LS4	 BUFFER[16]	//(sbk:20 - S01SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 1
#define idR0DE31LS4	 7	//(sbk:20 - S01SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 1
#define R0DE32LS4	 BUFFER[18]	//(sbk:20 - S02SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 2
#define idR0DE32LS4	 8	//(sbk:20 - S02SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 2
#define R0DE33LS4	 BUFFER[20]	//(sbk:20 - S03SBK, DiagnAKNP4) диагностика шкафа АКНП4 двери
#define idR0DE33LS4	 9	//(sbk:20 - S03SBK, DiagnAKNP4) диагностика шкафа АКНП4 двери
#define R0DE34LS4	 BUFFER[22]	//(sbk:20 - S04SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура меньше 43
#define idR0DE34LS4	 10	//(sbk:20 - S04SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура меньше 43
#define R0DE35LS4	 BUFFER[24]	//(sbk:20 - S05SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура больше 53
#define idR0DE35LS4	 11	//(sbk:20 - S05SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура больше 53
#define R0DE36LS4	 BUFFER[26]	//(sbk:20 - S06SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 1
#define idR0DE36LS4	 12	//(sbk:20 - S06SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 1
#define R0DE37LS4	 BUFFER[28]	//(sbk:20 - S07SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 2
#define idR0DE37LS4	 13	//(sbk:20 - S07SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 2
#define R0DE38LS4	 BUFFER[30]	//(sbk:20 - S08SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3 место 3
#define idR0DE38LS4	 14	//(sbk:20 - S08SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3 место 3
#define R0DE39LS4	 BUFFER[32]	//(sbk:20 - S09SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП24-2 место 4
#define idR0DE39LS4	 15	//(sbk:20 - S09SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП24-2 место 4
#define R0DE3CLS4	 BUFFER[34]	//( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 7
#define idR0DE3CLS4	 16	//( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 7
#define R0DE3DLS4	 BUFFER[36]	//( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 8
#define idR0DE3DLS4	 17	//( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 8
#define TTLaknp4	 BUFFER[38]	//( - , AKNP4) ttl
#define idTTLaknp4	 18	//( - , AKNP4) ttl
#define TestDiagnAKNP4	 BUFFER[41]	//( - , AKNP4) Неисправность от диагностики
#define idTestDiagnAKNP4	 19	//( - , AKNP4) Неисправность от диагностики
#define R0DEB1LS4	 BUFFER[43]	//(sbk:20 - S10SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 7
#define idR0DEB1LS4	 20	//(sbk:20 - S10SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 7
#define R0DEB2LS4	 BUFFER[45]	//(sbk:20 - S11SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 7
#define idR0DEB2LS4	 21	//(sbk:20 - S11SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 7
#define R0DEB4LS4	 BUFFER[47]	//(sbk:20 - S13SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 8
#define idR0DEB4LS4	 22	//(sbk:20 - S13SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 8
#define R0DEB3LS4	 BUFFER[49]	//(sbk:20 - S12SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 8
#define idR0DEB3LS4	 23	//(sbk:20 - S12SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 8
#define R0IS01FI0	 BUFFER[51]	//( - , MA4S) Признак работы с имитатором
#define idR0IS01FI0	 24	//( - , MA4S) Признак работы с имитатором
#define R0IN01FI4	 BUFFER[54]	//( - , MA4S) Выход СНМ-11 Гц
#define idR0IN01FI4	 25	//( - , MA4S) Выход СНМ-11 Гц
#define R0IN02FS4	 BUFFER[59]	//(vchs:01 - K02VCHS, AKNP4) Выход КНК15-1 Гц
#define idR0IN02FS4	 26	//(vchs:01 - K02VCHS, AKNP4) Выход КНК15-1 Гц
#define R0IN03FI4	 BUFFER[64]	//( - , MA4S) Выход КНК53М Гц
#define idR0IN03FI4	 27	//( - , MA4S) Выход КНК53М Гц
#define R0VN02RS4	 BUFFER[69]	//( - , AKNP4) Уровень мощности канал 4
#define idR0VN02RS4	 28	//( - , AKNP4) Уровень мощности канал 4
#define R0VN01RS4	 BUFFER[74]	//( - , AKNP4) Период разгона канал 4
#define idR0VN01RS4	 29	//( - , AKNP4) Период разгона канал 4
#define R0VN61LS4	 BUFFER[79]	//( - , AKNP4) ПС по мощности канал 4
#define idR0VN61LS4	 30	//( - , AKNP4) ПС по мощности канал 4
#define R0VN74LZ1	 BUFFER[81]	//(fds16:05 - K09FDSR, - ) АС по мощности канал 4 на БАЗ1
#define idR0VN74LZ1	 31	//(fds16:05 - K09FDSR, - ) АС по мощности канал 4 на БАЗ1
#define R0VN65LS4	 BUFFER[83]	//( - , AKNP4) ПС по периоду разгона канал 4
#define idR0VN65LS4	 32	//( - , AKNP4) ПС по периоду разгона канал 4
#define R0VN78LZ1	 BUFFER[85]	//(fds16:05 - K10FDSR, - ) АС по периоду разгона канал 4 на БАЗ1
#define idR0VN78LZ1	 33	//(fds16:05 - K10FDSR, - ) АС по периоду разгона канал 4 на БАЗ1
#define A0EE01LS4	 BUFFER[87]	//(fds16:05 - K11FDSR, - ) Исправность АКНП канал 4 на БАЗ1
#define idA0EE01LS4	 34	//(fds16:05 - K11FDSR, - ) Исправность АКНП канал 4 на БАЗ1
#define R0IN01FS4	 BUFFER[89]	//(vchs:01 - K01VCHS, AKNP4) Выход СНМ-11 Гц
#define idR0IN01FS4	 35	//(vchs:01 - K01VCHS, AKNP4) Выход СНМ-11 Гц
#define R0IN02FI4	 BUFFER[94]	//( - , MA4S) Выход КНК15-1 Гц
#define idR0IN02FI4	 36	//( - , MA4S) Выход КНК15-1 Гц
#define R0VN03RS4	 BUFFER[99]	//( - , AKNP4) Измеренный нейтронный поток канал 4
#define idR0VN03RS4	 37	//( - , AKNP4) Измеренный нейтронный поток канал 4
#define R0VN04RS4	 BUFFER[104]	//( - , AKNP4) Реактивность канал 4
#define idR0VN04RS4	 38	//( - , AKNP4) Реактивность канал 4
#define A1VN71LS4	 BUFFER[109]	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
#define idA1VN71LS4	 39	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
#define R0IN03FS4	 BUFFER[111]	//(vchs:02 - K01VCHS, AKNP4) Выход КНК53М Гц
#define idR0IN03FS4	 40	//(vchs:02 - K01VCHS, AKNP4) Выход КНК53М Гц
#define A0EE02LS4	 BUFFER[116]	//( - , AKNP4) Исправность АКНП4 (от сшивки каналов) канал 4
#define idA0EE02LS4	 41	//( - , AKNP4) Исправность АКНП4 (от сшивки каналов) канал 4
#define R0IE11LS4	 BUFFER[118]	//(vds32:04 - K01VDSR, - ) Исправность ВИП 1,6 (№17) СНМ11 4 канала
#define idR0IE11LS4	 42	//(vds32:04 - K01VDSR, - ) Исправность ВИП 1,6 (№17) СНМ11 4 канала
#define R0IE12LS4	 BUFFER[120]	//(vds32:04 - K02VDSR, - ) Исправность ВИП 0,5 (№18) КНК15-1 4 канала
#define idR0IE12LS4	 43	//(vds32:04 - K02VDSR, - ) Исправность ВИП 0,5 (№18) КНК15-1 4 канала
#define R0IE13LS4	 BUFFER[122]	//(vds32:04 - K03VDSR, - ) Исправность ВИП 0,5 (№19) КНК53М 4 канала
#define idR0IE13LS4	 44	//(vds32:04 - K03VDSR, - ) Исправность ВИП 0,5 (№19) КНК53М 4 канала
#define R0VN13RS4	 BUFFER[124]	//( - , AKNP4) Нейтронный поток по камере СНМ11 канал 4
#define idR0VN13RS4	 45	//( - , AKNP4) Нейтронный поток по камере СНМ11 канал 4
#define R0VN23RS4	 BUFFER[129]	//( - , AKNP4) Нейтронный поток по камере КНК15-1 канал 4
#define idR0VN23RS4	 46	//( - , AKNP4) Нейтронный поток по камере КНК15-1 канал 4
#define R0VN33RS4	 BUFFER[134]	//( - , AKNP4) Нейтронный поток по камере КНК53М канал 4
#define idR0VN33RS4	 47	//( - , AKNP4) Нейтронный поток по камере КНК53М канал 4
#define R0VN15RS4	 BUFFER[139]	//( - , AKNP4) Номер ведущей камеры канал 4
#define idR0VN15RS4	 48	//( - , AKNP4) Номер ведущей камеры канал 4
#define R0IE01LS4	 BUFFER[142]	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 4
#define idR0IE01LS4	 49	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 4
#define R0IE02LS4	 BUFFER[144]	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 4
#define idR0IE02LS4	 50	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 4
#define A0VN71LS4	 BUFFER[146]	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
#define idA0VN71LS4	 51	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
#define R0VN74LZ2	 BUFFER[148]	//(fds16:05 - K13FDSR, - ) АС по мощности канал 4 на БАЗ2
#define idR0VN74LZ2	 52	//(fds16:05 - K13FDSR, - ) АС по мощности канал 4 на БАЗ2
#define R0VN78LZ2	 BUFFER[150]	//(fds16:05 - K14FDSR, - ) АС по периоду разгона канал 4 на БАЗ2
#define idR0VN78LZ2	 53	//(fds16:05 - K14FDSR, - ) АС по периоду разгона канал 4 на БАЗ2
#define A1EE01LS4	 BUFFER[152]	//(fds16:05 - K15FDSR, - ) Исправность АКНП канал 4 на БАЗ2
#define idA1EE01LS4	 54	//(fds16:05 - K15FDSR, - ) Исправность АКНП канал 4 на БАЗ2
#define B8VC01RDU	 BUFFER[154]	//( - , AKNP4) Координата АЗ2, мм
#define idB8VC01RDU	 55	//( - , AKNP4) Координата АЗ2, мм
#define fEM_R0UR01RSS	 BUFFER[159]	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RSS	 56	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R0UL52RSS	 BUFFER[164]	//(R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	 57	//(R0UL52RSS) Уровень АС по мощности
#define fEM_R0UL41RSS	 BUFFER[169]	//(R0UL41RSS) Уровень ПС по периоду разгона
#define idfEM_R0UL41RSS	 58	//(R0UL41RSS) Уровень ПС по периоду разгона
#define fEM_R0UL51RSS	 BUFFER[174]	//(R0UL51RSS) Уровень АС по периоду разгона
#define idfEM_R0UL51RSS	 59	//(R0UL51RSS) Уровень АС по периоду разгона
#define fEM_R0UH02RSS	 BUFFER[179]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define idfEM_R0UH02RSS	 60	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define fEM_R0UH03RSS	 BUFFER[184]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define idfEM_R0UH03RSS	 61	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define fEM_R0UL42RSS	 BUFFER[189]	//(R0UL42RSS) Уровень ПС по мощности
#define idfEM_R0UL42RSS	 62	//(R0UL42RSS) Уровень ПС по мощности
#define fEM_R7UX00RSS	 BUFFER[194]	//(R7UX00RSS) X-координата АЗ1 (см)
#define idfEM_R7UX00RSS	 63	//(R7UX00RSS) X-координата АЗ1 (см)
#define fEM_R7UY00RSS	 BUFFER[199]	//(R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	 64	//(R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UX10RSS	 BUFFER[204]	//(R7UX10RSS) X-координата камеры R7IN41
#define idfEM_R7UX10RSS	 65	//(R7UX10RSS) X-координата камеры R7IN41
#define fEM_R7UX11RSS	 BUFFER[209]	//(R7UX11RSS) X-координата камеры R7IN42
#define idfEM_R7UX11RSS	 66	//(R7UX11RSS) X-координата камеры R7IN42
#define fEM_R7UX12RSS	 BUFFER[214]	//(R7UX12RSS) X-координата камеры R7IN43
#define idfEM_R7UX12RSS	 67	//(R7UX12RSS) X-координата камеры R7IN43
#define fEM_R7UY10RSS	 BUFFER[219]	//(R7UY10RSS) Y-координата камеры R7IN41
#define idfEM_R7UY10RSS	 68	//(R7UY10RSS) Y-координата камеры R7IN41
#define fEM_R7UY11RSS	 BUFFER[224]	//(R7UY11RSS) Y-координата камеры R7IN42
#define idfEM_R7UY11RSS	 69	//(R7UY11RSS) Y-координата камеры R7IN42
#define fEM_R7UY12RSS	 BUFFER[229]	//(R7UY12RSS) Y-координата камеры R7IN43
#define idfEM_R7UY12RSS	 70	//(R7UY12RSS) Y-координата камеры R7IN43
#define fEM_A0UX00RSS	 BUFFER[234]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 71	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX10RSS	 BUFFER[239]	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define idfEM_A0UX10RSS	 72	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define fEM_A0UX11RSS	 BUFFER[244]	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define idfEM_A0UX11RSS	 73	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define fEM_A0UX12RSS	 BUFFER[249]	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define idfEM_A0UX12RSS	 74	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define fEM_B0UX10RSS	 BUFFER[254]	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define idfEM_B0UX10RSS	 75	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define fEM_B0UX11RSS	 BUFFER[259]	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define idfEM_B0UX11RSS	 76	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define fEM_B0UX12RSS	 BUFFER[264]	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define idfEM_B0UX12RSS	 77	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define fEM_R0UH05RSS	 BUFFER[269]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 78	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define iEM_R0UL01ISS	 BUFFER[274]	//(R0UL01ISS) Шаг (мс) измерения периода
#define idiEM_R0UL01ISS	 79	//(R0UL01ISS) Шаг (мс) измерения периода
#define dEM_R0UL02USS	 BUFFER[277]	//(R0UL02USS) Предельное время ожидания роста потока (мс)
#define iddEM_R0UL02USS	 80	//(R0UL02USS) Предельное время ожидания роста потока (мс)
#define fEM_R0UN03RSS	 BUFFER[282]	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN03RSS	 81	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define bFirstEnterFlag	 BUFFER[287]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 82	//(bFirstEnterFlag) 
#define internal1_m21_Nk	 BUFFER[289]	//(internal1_m21_Nk) Nk - ведущая камера
#define idinternal1_m21_Nk	 83	//(internal1_m21_Nk) Nk - ведущая камера
#define internal1_m53_tst	 BUFFER[292]	//(internal1_m53_tst) - массив времени фиксации стартовой мощности
#define idinternal1_m53_tst	 84	//(internal1_m53_tst) - массив времени фиксации стартовой мощности
#define internal1_m53_trz	 BUFFER[317]	//(internal1_m53_trz) - массив времени фиксации очередного периода
#define idinternal1_m53_trz	 85	//(internal1_m53_trz) - массив времени фиксации очередного периода
#define internal1_m53_N1	 BUFFER[342]	//(internal1_m53_N1) - массив значения мощности в начале замера
#define idinternal1_m53_N1	 86	//(internal1_m53_N1) - массив значения мощности в начале замера
#define internal1_m53_N2	 BUFFER[367]	//(internal1_m53_N2) - массив значения мощности в конце замера
#define idinternal1_m53_N2	 87	//(internal1_m53_N2) - массив значения мощности в конце замера
#define internal1_m53_Period0	 BUFFER[392]	//(internal1_m53_Period0) Per - Период разгона РУ
#define idinternal1_m53_Period0	 88	//(internal1_m53_Period0) Per - Период разгона РУ
#define internal1_m53_MyFirstEnterFlag	 BUFFER[397]	//(internal1_m53_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m53_MyFirstEnterFlag	 89	//(internal1_m53_MyFirstEnterFlag)  FirstEnterFlag
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &R0EE04LZ1},	//( - , AKNP4) Питание  АКНП4  отключить
	{ 2	,1	,1	, &R0EE04LZ2},	//( - , AKNP4) Питание  АКНП4  отключить
	{ 3	,3	,1	, &R0DE01LS4},	//(vchs:01 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 1 месте
	{ 4	,3	,1	, &R0DE02LS4},	//(vchs:02 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 2 месте
	{ 5	,3	,1	, &R0DE04LS4},	//(vds32:04 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 4 месте
	{ 6	,3	,1	, &R0DE05LS4},	//(fds16:05 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 5 месте
	{ 7	,1	,1	, &R0DE31LS4},	//(sbk:20 - S01SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 1
	{ 8	,1	,1	, &R0DE32LS4},	//(sbk:20 - S02SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 2
	{ 9	,1	,1	, &R0DE33LS4},	//(sbk:20 - S03SBK, DiagnAKNP4) диагностика шкафа АКНП4 двери
	{ 10	,1	,1	, &R0DE34LS4},	//(sbk:20 - S04SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура меньше 43
	{ 11	,1	,1	, &R0DE35LS4},	//(sbk:20 - S05SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура больше 53
	{ 12	,1	,1	, &R0DE36LS4},	//(sbk:20 - S06SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 1
	{ 13	,1	,1	, &R0DE37LS4},	//(sbk:20 - S07SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 2
	{ 14	,1	,1	, &R0DE38LS4},	//(sbk:20 - S08SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3 место 3
	{ 15	,1	,1	, &R0DE39LS4},	//(sbk:20 - S09SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП24-2 место 4
	{ 16	,1	,1	, &R0DE3CLS4},	//( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 7
	{ 17	,1	,1	, &R0DE3DLS4},	//( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 8
	{ 18	,3	,1	, &TTLaknp4},	//( - , AKNP4) ttl
	{ 19	,1	,1	, &TestDiagnAKNP4},	//( - , AKNP4) Неисправность от диагностики
	{ 20	,1	,1	, &R0DEB1LS4},	//(sbk:20 - S10SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 7
	{ 21	,1	,1	, &R0DEB2LS4},	//(sbk:20 - S11SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 7
	{ 22	,1	,1	, &R0DEB4LS4},	//(sbk:20 - S13SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 8
	{ 23	,1	,1	, &R0DEB3LS4},	//(sbk:20 - S12SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 8
	{ 24	,3	,1	, &R0IS01FI0},	//( - , MA4S) Признак работы с имитатором
	{ 25	,8	,1	, &R0IN01FI4},	//( - , MA4S) Выход СНМ-11 Гц
	{ 26	,8	,1	, &R0IN02FS4},	//(vchs:01 - K02VCHS, AKNP4) Выход КНК15-1 Гц
	{ 27	,8	,1	, &R0IN03FI4},	//( - , MA4S) Выход КНК53М Гц
	{ 28	,8	,1	, &R0VN02RS4},	//( - , AKNP4) Уровень мощности канал 4
	{ 29	,8	,1	, &R0VN01RS4},	//( - , AKNP4) Период разгона канал 4
	{ 30	,1	,1	, &R0VN61LS4},	//( - , AKNP4) ПС по мощности канал 4
	{ 31	,1	,1	, &R0VN74LZ1},	//(fds16:05 - K09FDSR, - ) АС по мощности канал 4 на БАЗ1
	{ 32	,1	,1	, &R0VN65LS4},	//( - , AKNP4) ПС по периоду разгона канал 4
	{ 33	,1	,1	, &R0VN78LZ1},	//(fds16:05 - K10FDSR, - ) АС по периоду разгона канал 4 на БАЗ1
	{ 34	,1	,1	, &A0EE01LS4},	//(fds16:05 - K11FDSR, - ) Исправность АКНП канал 4 на БАЗ1
	{ 35	,8	,1	, &R0IN01FS4},	//(vchs:01 - K01VCHS, AKNP4) Выход СНМ-11 Гц
	{ 36	,8	,1	, &R0IN02FI4},	//( - , MA4S) Выход КНК15-1 Гц
	{ 37	,8	,1	, &R0VN03RS4},	//( - , AKNP4) Измеренный нейтронный поток канал 4
	{ 38	,8	,1	, &R0VN04RS4},	//( - , AKNP4) Реактивность канал 4
	{ 39	,1	,1	, &A1VN71LS4},	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
	{ 40	,8	,1	, &R0IN03FS4},	//(vchs:02 - K01VCHS, AKNP4) Выход КНК53М Гц
	{ 41	,1	,1	, &A0EE02LS4},	//( - , AKNP4) Исправность АКНП4 (от сшивки каналов) канал 4
	{ 42	,1	,1	, &R0IE11LS4},	//(vds32:04 - K01VDSR, - ) Исправность ВИП 1,6 (№17) СНМ11 4 канала
	{ 43	,1	,1	, &R0IE12LS4},	//(vds32:04 - K02VDSR, - ) Исправность ВИП 0,5 (№18) КНК15-1 4 канала
	{ 44	,1	,1	, &R0IE13LS4},	//(vds32:04 - K03VDSR, - ) Исправность ВИП 0,5 (№19) КНК53М 4 канала
	{ 45	,8	,1	, &R0VN13RS4},	//( - , AKNP4) Нейтронный поток по камере СНМ11 канал 4
	{ 46	,8	,1	, &R0VN23RS4},	//( - , AKNP4) Нейтронный поток по камере КНК15-1 канал 4
	{ 47	,8	,1	, &R0VN33RS4},	//( - , AKNP4) Нейтронный поток по камере КНК53М канал 4
	{ 48	,3	,1	, &R0VN15RS4},	//( - , AKNP4) Номер ведущей камеры канал 4
	{ 49	,1	,1	, &R0IE01LS4},	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 4
	{ 50	,1	,1	, &R0IE02LS4},	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 4
	{ 51	,1	,1	, &A0VN71LS4},	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
	{ 52	,1	,1	, &R0VN74LZ2},	//(fds16:05 - K13FDSR, - ) АС по мощности канал 4 на БАЗ2
	{ 53	,1	,1	, &R0VN78LZ2},	//(fds16:05 - K14FDSR, - ) АС по периоду разгона канал 4 на БАЗ2
	{ 54	,1	,1	, &A1EE01LS4},	//(fds16:05 - K15FDSR, - ) Исправность АКНП канал 4 на БАЗ2
	{ 55	,8	,1	, &B8VC01RDU},	//( - , AKNP4) Координата АЗ2, мм
	{ 56	,8	,1	, &fEM_R0UR01RSS},	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
	{ 57	,8	,1	, &fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{ 58	,8	,1	, &fEM_R0UL41RSS},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{ 59	,8	,1	, &fEM_R0UL51RSS},	//(R0UL51RSS) Уровень АС по периоду разгона
	{ 60	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{ 61	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{ 62	,8	,1	, &fEM_R0UL42RSS},	//(R0UL42RSS) Уровень ПС по мощности
	{ 63	,8	,1	, &fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{ 64	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{ 65	,8	,1	, &fEM_R7UX10RSS},	//(R7UX10RSS) X-координата камеры R7IN41
	{ 66	,8	,1	, &fEM_R7UX11RSS},	//(R7UX11RSS) X-координата камеры R7IN42
	{ 67	,8	,1	, &fEM_R7UX12RSS},	//(R7UX12RSS) X-координата камеры R7IN43
	{ 68	,8	,1	, &fEM_R7UY10RSS},	//(R7UY10RSS) Y-координата камеры R7IN41
	{ 69	,8	,1	, &fEM_R7UY11RSS},	//(R7UY11RSS) Y-координата камеры R7IN42
	{ 70	,8	,1	, &fEM_R7UY12RSS},	//(R7UY12RSS) Y-координата камеры R7IN43
	{ 71	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 72	,8	,1	, &fEM_A0UX10RSS},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{ 73	,8	,1	, &fEM_A0UX11RSS},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{ 74	,8	,1	, &fEM_A0UX12RSS},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{ 75	,8	,1	, &fEM_B0UX10RSS},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{ 76	,8	,1	, &fEM_B0UX11RSS},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{ 77	,8	,1	, &fEM_B0UX12RSS},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{ 78	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 79	,3	,1	, &iEM_R0UL01ISS},	//(R0UL01ISS) Шаг (мс) измерения периода
	{ 80	,5	,1	, &dEM_R0UL02USS},	//(R0UL02USS) Предельное время ожидания роста потока (мс)
	{ 81	,8	,1	, &fEM_R0UN03RSS},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 82	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 83	,3	,1	, &internal1_m21_Nk},	//(internal1_m21_Nk) Nk - ведущая камера
	{ 84	,8	,5	, &internal1_m53_tst},	//(internal1_m53_tst) - массив времени фиксации стартовой мощности
	{ 85	,8	,5	, &internal1_m53_trz},	//(internal1_m53_trz) - массив времени фиксации очередного периода
	{ 86	,8	,5	, &internal1_m53_N1},	//(internal1_m53_N1) - массив значения мощности в начале замера
	{ 87	,8	,5	, &internal1_m53_N2},	//(internal1_m53_N2) - массив значения мощности в конце замера
	{ 88	,8	,1	, &internal1_m53_Period0},	//(internal1_m53_Period0) Per - Период разгона РУ
	{ 89	,1	,1	, &internal1_m53_MyFirstEnterFlag},	//(internal1_m53_MyFirstEnterFlag)  FirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="aknp4.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{56,"fEM_R0UR01RSS\0"}, 
{57,"fEM_R0UL52RSS\0"}, 
{58,"fEM_R0UL41RSS\0"}, 
{59,"fEM_R0UL51RSS\0"}, 
{60,"fEM_R0UH02RSS\0"}, 
{61,"fEM_R0UH03RSS\0"}, 
{62,"fEM_R0UL42RSS\0"}, 
{63,"fEM_R7UX00RSS\0"}, 
{64,"fEM_R7UY00RSS\0"}, 
{65,"fEM_R7UX10RSS\0"}, 
{66,"fEM_R7UX11RSS\0"}, 
{67,"fEM_R7UX12RSS\0"}, 
{68,"fEM_R7UY10RSS\0"}, 
{69,"fEM_R7UY11RSS\0"}, 
{70,"fEM_R7UY12RSS\0"}, 
{71,"fEM_A0UX00RSS\0"}, 
{72,"fEM_A0UX10RSS\0"}, 
{73,"fEM_A0UX11RSS\0"}, 
{74,"fEM_A0UX12RSS\0"}, 
{75,"fEM_B0UX10RSS\0"}, 
{76,"fEM_B0UX11RSS\0"}, 
{77,"fEM_B0UX12RSS\0"}, 
{78,"fEM_R0UH05RSS\0"}, 
{79,"iEM_R0UL01ISS\0"}, 
{80,"dEM_R0UL02USS\0"}, 
{81,"fEM_R0UN03RSS\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_AKNP4[]={  // 
	{&R0EE04LZ2,1,0},	//( - , AKNP4) Питание  АКНП4  отключить
	{&R0EE04LZ1,1,1},	//( - , AKNP4) Питание  АКНП4  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_AKNP4[]={  // 
	{&TestDiagnAKNP4,1,0},	//( - , AKNP4) Неисправность от диагностики
	{&A0EE02LS4,1,1},	//( - , AKNP4) Исправность АКНП4 (от сшивки каналов) канал 4
	{&R0VN65LS4,1,2},	//( - , AKNP4) ПС по периоду разгона канал 4
	{&R0VN61LS4,1,3},	//( - , AKNP4) ПС по мощности канал 4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_AKNP4[]={  // 
	{&R0IN02FS4,8,0},	//( - K02VCHS, AKNP4) Выход КНК15-1 Гц
	{&TTLaknp4,3,2},	//( - , AKNP4) ttl
	{&R0VN15RS4,3,3},	//( - , AKNP4) Номер ведущей камеры канал 4
	{&R0VN33RS4,8,4},	//( - , AKNP4) Нейтронный поток по камере КНК53М канал 4
	{&R0VN23RS4,8,6},	//( - , AKNP4) Нейтронный поток по камере КНК15-1 канал 4
	{&R0VN13RS4,8,8},	//( - , AKNP4) Нейтронный поток по камере СНМ11 канал 4
	{&R0IN03FS4,8,10},	//( - K01VCHS, AKNP4) Выход КНК53М Гц
	{&R0VN04RS4,8,12},	//( - , AKNP4) Реактивность канал 4
	{&R0VN03RS4,8,14},	//( - , AKNP4) Измеренный нейтронный поток канал 4
	{&R0IN01FS4,8,16},	//( - K01VCHS, AKNP4) Выход СНМ-11 Гц
	{&R0VN01RS4,8,18},	//( - , AKNP4) Период разгона канал 4
	{&R0VN02RS4,8,20},	//( - , AKNP4) Уровень мощности канал 4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_AKNP4[]={  // 
	{&B8VC01RDU,8,0},	//( - , AKNP4) Координата АЗ2, мм
	{&fEM_R0UR01RSS,8,2},	//( - , AKNP4) Уставка АКНП ПС  АЗ по периоду (сек)
	{&fEM_R0UL52RSS,8,4},	//( - , AKNP4) Уровень АС по мощности
	{&fEM_R0UL41RSS,8,6},	//( - , AKNP4) Уровень ПС по периоду разгона
	{&fEM_R0UL51RSS,8,8},	//( - , AKNP4) Уровень АС по периоду разгона
	{&fEM_R0UH02RSS,8,10},	//( - , AKNP4) Коэфф. преобразования частота->нейтр/с КНК15-1
	{&fEM_R0UH03RSS,8,12},	//( - , AKNP4) Коэфф. преобразования частота->нейтр/с КНК53М
	{&fEM_R0UL42RSS,8,14},	//( - , AKNP4) Уровень ПС по мощности
	{&fEM_R7UX00RSS,8,16},	//( - , AKNP4) X-координата АЗ1 (см)
	{&fEM_R7UY00RSS,8,18},	//( - , AKNP4) Y-координата АЗ1 (см)
	{&fEM_R7UX10RSS,8,20},	//( - , AKNP4) X-координата камеры R7IN41
	{&fEM_R7UX11RSS,8,22},	//( - , AKNP4) X-координата камеры R7IN42
	{&fEM_R7UX12RSS,8,24},	//( - , AKNP4) X-координата камеры R7IN43
	{&fEM_R7UY10RSS,8,26},	//( - , AKNP4) Y-координата камеры R7IN41
	{&fEM_R7UY11RSS,8,28},	//( - , AKNP4) Y-координата камеры R7IN42
	{&fEM_R7UY12RSS,8,30},	//( - , AKNP4) Y-координата камеры R7IN43
	{&fEM_A0UX00RSS,8,32},	//( - , AKNP4) Эффективный радиус АЗ
	{&fEM_A0UX10RSS,8,34},	//( - , AKNP4) Первый коэффициент калибровки камеры 10
	{&fEM_A0UX11RSS,8,36},	//( - , AKNP4) Первый коэффициент калибровки камеры 11
	{&fEM_A0UX12RSS,8,38},	//( - , AKNP4) Первый коэффициент калибровки камеры 12
	{&fEM_B0UX10RSS,8,40},	//( - , AKNP4) Второй коэффициент калибровки камеры 10
	{&fEM_B0UX11RSS,8,42},	//( - , AKNP4) Второй коэффициент калибровки камеры 11
	{&fEM_B0UX12RSS,8,44},	//( - , AKNP4) Второй коэффициент калибровки камеры 12
	{&fEM_R0UH05RSS,8,46},	//( - , AKNP4) Кол-во делений/сек на 1 ватт * E^6
	{&iEM_R0UL01ISS,3,48},	//( - , AKNP4) Шаг (мс) измерения периода
	{&dEM_R0UL02USS,5,49},	//( - , AKNP4) Предельное время ожидания роста потока (мс)
	{&fEM_R0UN03RSS,8,51},	//( - , AKNP4) Нижняя граница интервала мощности для измерения периода (ватт)
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MA4S[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MA4S[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MA4S[]={  // 
	{&R0IN01FI4,8,0},	//( - , SA4) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI4,8,2},	//( - , SA4) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI4,8,4},	//( - , SA4) Выход КНК53М Гц от ПТИ
	{&R0IS01FI0,3,6},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MA4S[]={  // 
	{NULL,0,0},
};
#pragma pop
static char MA4S_ip1[]={"192.168.10.60\0"};
static char MA4S_ip2[]={"192.168.10.60\0"};
#pragma pack(push,1)
static ModbusRegister coil_DiagnAKNP4[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnAKNP4[]={  // 
	{&R0DEB3LS4,1,0},	//( - S12SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 8
	{&R0DEB4LS4,1,1},	//( - S13SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 8
	{&R0DEB2LS4,1,2},	//( - S11SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 7
	{&R0DEB1LS4,1,3},	//( - S10SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 7
	{&R0DE3DLS4,1,4},	//( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 8
	{&R0DE3CLS4,1,5},	//( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 7
	{&R0DE39LS4,1,6},	//( - S09SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП24-2 место 4
	{&R0DE38LS4,1,7},	//( - S08SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3 место 3
	{&R0DE37LS4,1,8},	//( - S07SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 2
	{&R0DE36LS4,1,9},	//( - S06SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 1
	{&R0DE35LS4,1,10},	//( - S05SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура больше 53
	{&R0DE34LS4,1,11},	//( - S04SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура меньше 43
	{&R0DE33LS4,1,12},	//( - S03SBK, DiagnAKNP4) диагностика шкафа АКНП4 двери
	{&R0DE32LS4,1,13},	//( - S02SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 2
	{&R0DE31LS4,1,14},	//( - S01SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DiagnAKNP4[]={  // 
	{&R0DE05LS4,3,0},	//( - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 5 месте
	{&R0DE04LS4,3,1},	//( - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 4 месте
	{&R0DE02LS4,3,2},	//( - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 2 месте
	{&R0DE01LS4,3,3},	//( - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 1 месте
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
	{1,5009,&coil_MA4S[0],&di_MA4S[0],&ir_MA4S[0],&hr_MA4S[0],NULL,MA4S_ip1,MA4S_ip2,100},	 //Мастер AKNP4 в SCM
	{0,5003,&coil_DiagnAKNP4[0],&di_DiagnAKNP4[0],&ir_DiagnAKNP4[0],&hr_DiagnAKNP4[0],NULL,NULL,NULL,0},	 //Диагностика корзины АКНП4

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
	{&R0DE01LS4,3,10},
	{&R0IN02FS4,8,5},
	{&R0IN01FS4,8,0},
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
	{&R0DE02LS4,3,10},
	{&R0IN03FS4,8,0},
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
	{&R0IE12LS4,1,2},
	{&R0IE13LS4,1,4},
	{&R0DE04LS4,3,64},
	{&R0IE11LS4,1,0},
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
	{&A1EE01LS4,1,28},
	{&R0VN78LZ2,1,26},
	{&R0VN74LZ2,1,24},
	{&A0VN71LS4,1,22},
	{&R0IE02LS4,1,0},
	{&R0IE01LS4,1,2},
	{&R0DE05LS4,3,38},
	{&A1VN71LS4,1,30},
	{&R0VN74LZ1,1,16},
	{&R0VN78LZ1,1,18},
	{&A0EE01LS4,1,20},
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
	{&R0DE31LS4,1,0},
	{&R0DE32LS4,1,2},
	{&R0DEB2LS4,1,20},
	{&R0DEB4LS4,1,24},
	{&R0DEB3LS4,1,22},
	{&R0DEB1LS4,1,18},
	{&R0DE39LS4,1,16},
	{&R0DE38LS4,1,14},
	{&R0DE37LS4,1,12},
	{&R0DE36LS4,1,10},
	{&R0DE35LS4,1,8},
	{&R0DE34LS4,1,6},
	{&R0DE33LS4,1,4},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc4,0x01,12,58,def_buf_VCHS01,&table_VCHS01}, //VCHS01
	{0xc4,0x02,12,58,def_buf_VCHS02,&table_VCHS02}, //VCHS02
	{0xc2,0x04,15,66,def_buf_VDS32,&table_VDS32}, //VDS32
	{0x96,0x05,20,40,def_buf_FDS16,&table_FDS16}, //FDS16
	{0xcc,0x20,4,26,def_buf_SBKFP,&table_SBKFP}, //SBKFP
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
	setAsFloat(56,5000);
	setAsFloat(57,5100);
	setAsFloat(58,20);
	setAsFloat(59,13.0);
	setAsFloat(60,3703.704 );
	setAsFloat(61,62500.0);
	setAsFloat(62,5000);
	setAsFloat(63,1567.36);
	setAsFloat(64,506.5);
	setAsFloat(65,1555.0);
	setAsFloat(66,1281.2);
	setAsFloat(67,1269.0);
	setAsFloat(68,594.0);
	setAsFloat(69,597.2);
	setAsFloat(70,556.8);
	setAsFloat(71,11.0);
	setAsFloat(72,1.0);
	setAsFloat(73,1.0);
	setAsFloat(74,1.0);
	setAsFloat(75,0.0);
	setAsFloat(76,0.0);
	setAsFloat(77,0.0);
	setAsFloat(78,32000.0);
	setAsShort(79,500);
	setAsInt(80,100000);
	setAsFloat(81,0.005);
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
ssint iRM_1_ = {1,0}; /* x2 - второе слагаемое */ 

uspaint8 SpaEEPROMBuf[128];

/* Определение переменных */
ssbool var1;
ssfloat var2;
ssfloat var3;
ssint var4;
ssfloat var5;
ssbool var6;
ssbool var7;
ssbool var8;
ssbool var9;
ssbool var10;
ssbool var11;
ssint var12;
ssfloat var13;
ssfloat var14;
ssbool var15;
ssfloat var16;
ssfloat var17;
ssfloat var18;
ssint var19;
ssbool var20;
ssfloat var21;
ssbool var22;
ssbool var23;
ssbool var24;
ssbool var25;
ssbool var26;
ssbool var27;
ssbool var28;
ssbool var29;
ssfloat var30;
ssbool var31;
ssfloat var32;
ssfloat var33;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psfloat  array_m10_x_1[2] = {&R0IN03FS4,&R0IN03FI4};
psfloat  array_m9_x_1[2] = {&R0IN02FS4,&R0IN02FI4};
psfloat  array_m8_x_1[2] = {&R0IN01FS4,&R0IN01FI4};
psbool  array_m101_x_1[6] = {&R0DE36LS4,&R0DE37LS4,&R0DE38LS4,&R0DE39LS4,&var7,&var6};
psint  array_m87_x_1[4] = {&R0DE01LS4,&R0DE02LS4,&R0DE04LS4,&R0DE05LS4};
psfloat  array_m53_tst_1[5];
psfloat  array_m53_trz_1[5];
psfloat  array_m53_N1_1[5];
psfloat  array_m53_N2_1[5];
psbool  array_m63_x_1[2] = {&var28,&var23};
psbool  array_m62_x_1[2] = {&var28,&var29};
psbool  array_m72_x_1[5] = {&var15,&R0IE11LS4,&R0IE12LS4,&R0IE13LS4,&var1};

/* Объявление структур */
_S_noto  S_noto_103_1 = {&var8,&var1};
_S_ma  S_ma_10_1 = {array_m10_x_1,&var4,&iRM_2_,&var2};
_S_ma  S_ma_9_1 = {array_m9_x_1,&var4,&iRM_2_,&var3};
_S_fsumz  S_fsumz_2_1 = {&R0IS01FI0,&iRM_1_,&var4};
_S_ma  S_ma_8_1 = {array_m8_x_1,&var4,&iRM_2_,&var5};
_S_or2  S_or2_104_1 = {&R0DEB3LS4,&R0DEB4LS4,&var6};
_S_or2  S_or2_96_1 = {&R0DEB1LS4,&R0DEB2LS4,&var7};
_S_or3  S_or3_98_1 = {&var11,&var10,&var9,&var8};
_S_orn  S_orn_101_1 = {array_m101_x_1,&iRM_6_,&var9};
_S_and2  S_and2_89_1 = {&R0DE31LS4,&R0DE32LS4,&var10};
_S_diagndev  S_diagndev_87_1 = {array_m87_x_1,&iRM_4_,&var11,&var12};
_S_ocham  S_ocham_21_1 = {&var5,&var3,&var2,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX10RSS,&fEM_B0UX10RSS,&fEM_A0UX11RSS,&fEM_B0UX11RSS,&fEM_A0UX12RSS,&fEM_B0UX12RSS,&fEM_R7UX10RSS,&fEM_R7UY10RSS,&fEM_R7UX11RSS,&fEM_R7UY11RSS,&fEM_R7UX12RSS,&fEM_R7UY12RSS,&bRM_1_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var13,&var14,&var15,&var16,&var17,&var18,&var19,&internal1_m21_Nk};
_S_or2  S_or2_74_1 = {&R0EE04LZ1,&R0EE04LZ2,&var20};
_S_period  S_period_53_1 = {&var14,&var25,&iRM_5_,&var32,&var33,&fEM_R0UN03RSS,&var21,array_m53_tst_1,array_m53_trz_1,array_m53_N1_1,array_m53_N2_1,&internal1_m53_Period0,&internal1_m53_MyFirstEnterFlag};
_S_andn  S_andn_63_1 = {array_m63_x_1,&iRM_2_,&var22};
_S_bol  S_bol_60_1 = {&fEM_R0UL41RSS,&var21,&var23};
_S_andn  S_andn_62_1 = {array_m62_x_1,&iRM_2_,&var24};
_S_andn  S_andn_72_1 = {array_m72_x_1,&iRM_5_,&var25};
_S_bol  S_bol_43_1 = {&var14,&fEM_R0UL52RSS,&var26};
_S_bol  S_bol_48_1 = {&var14,&fEM_R0UL42RSS,&var27};
_S_bol  S_bol_59_1 = {&var14,&fEM_R0UN03RSS,&var28};
_S_bol  S_bol_58_1 = {&fEM_R0UL51RSS,&var21,&var29};
_S_react  S_react_54_1 = {&var21,&var30};
_S_bol  S_bol_39_1 = {&var14,&fEM_R0UR01RSS,&var31};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_74_1);
  diagndev(&S_diagndev_87_1);
  and2(&S_and2_89_1);
  or2(&S_or2_96_1);
  or2(&S_or2_104_1);
  fsumz(&S_fsumz_2_1);
  ma(&S_ma_9_1);
  ma(&S_ma_10_1);
  orn(&S_orn_101_1);
  or3(&S_or3_98_1);
  ma(&S_ma_8_1);
  noto(&S_noto_103_1);
  ocham(&S_ocham_21_1);
  bol(&S_bol_39_1);
  bol(&S_bol_59_1);
  bol(&S_bol_48_1);
  bol(&S_bol_43_1);
  andn(&S_andn_72_1);
  setData(&var32,&iEM_R0UL01ISS);
  setData(&var33,&dEM_R0UL02USS);
  period(&S_period_53_1);
  react(&S_react_54_1);
  bol(&S_bol_58_1);
  andn(&S_andn_62_1);
  bol(&S_bol_60_1);
  andn(&S_andn_63_1);
  setData(idTestDiagnAKNP4,&var8);
  setData(idTTLaknp4,&var12);
  setData(idR0DE3DLS4,&var6);
  setData(idR0DE3CLS4,&var7);
  setData(idA1EE01LS4,&var25);
  setData(idR0VN78LZ2,&var24);
  setData(idR0VN74LZ2,&var26);
  setData(idA0VN71LS4,&var31);
  setData(idR0IE02LS4,&var20);
  setData(idR0IE01LS4,&var20);
  setData(idR0VN15RS4,&var19);
  setData(idR0VN33RS4,&var18);
  setData(idR0VN23RS4,&var17);
  setData(idR0VN13RS4,&var16);
  setData(idA0EE02LS4,&var15);
  setData(idA1VN71LS4,&var31);
  setData(idR0VN04RS4,&var30);
  setData(idR0VN03RS4,&var13);
  setData(idA0EE01LS4,&var25);
  setData(idR0VN78LZ1,&var24);
  setData(idR0VN65LS4,&var22);
  setData(idR0VN74LZ1,&var26);
  setData(idR0VN61LS4,&var27);
  setData(idR0VN01RS4,&var21);
  setData(idR0VN02RS4,&var14);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<5;i++ )
    array_m53_tst_1[i] = &(&internal1_m53_tst)[i*5];
  for( i=0;i<5;i++ )
    array_m53_trz_1[i] = &(&internal1_m53_trz)[i*5];
  for( i=0;i<5;i++ )
    array_m53_N1_1[i] = &(&internal1_m53_N1)[i*5];
  for( i=0;i<5;i++ )
    array_m53_N2_1[i] = &(&internal1_m53_N2)[i*5];
}

#endif
