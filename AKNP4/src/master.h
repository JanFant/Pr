#ifndef AKNP4_H
#define AKNP4_H
// Подсистема AKNP4:AKNP4
static char SimulOn=0;
static short CodeSub=7;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt, taktScheme=0, taktSS=0;
#define SIZE_BUFFER 407
static char BUFFER[407];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.55\0", 5432, "192.168.10.155\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0EE04LZ2	 BUFFER[0]	//( - , AKNP4) Питание  АКНП4  отключить
#define idR0EE04LZ2	 1	//( - , AKNP4) Питание  АКНП4  отключить
#define R0DE01LS4	 BUFFER[2]	//(vchs:01 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 1 месте
#define idR0DE01LS4	 2	//(vchs:01 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 1 месте
#define R0DE02LS4	 BUFFER[5]	//(vchs:02 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 2 месте
#define idR0DE02LS4	 3	//(vchs:02 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 2 месте
#define R0DE04LS4	 BUFFER[8]	//(vds32:04 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 4 месте
#define idR0DE04LS4	 4	//(vds32:04 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 4 месте
#define R0DE05LS4	 BUFFER[11]	//(fds16:05 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 5 месте
#define idR0DE05LS4	 5	//(fds16:05 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 5 месте
#define R0DE31LS4	 BUFFER[14]	//(sbk:20 - S01SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 1
#define idR0DE31LS4	 6	//(sbk:20 - S01SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 1
#define R0DE32LS4	 BUFFER[16]	//(sbk:20 - S02SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 2
#define idR0DE32LS4	 7	//(sbk:20 - S02SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 2
#define R0DE33LS4	 BUFFER[18]	//(sbk:20 - S03SBK, DiagnAKNP4) диагностика шкафа АКНП4 двери
#define idR0DE33LS4	 8	//(sbk:20 - S03SBK, DiagnAKNP4) диагностика шкафа АКНП4 двери
#define R0DE34LS4	 BUFFER[20]	//(sbk:20 - S04SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура меньше 43
#define idR0DE34LS4	 9	//(sbk:20 - S04SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура меньше 43
#define R0DE35LS4	 BUFFER[22]	//(sbk:20 - S05SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура больше 53
#define idR0DE35LS4	 10	//(sbk:20 - S05SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура больше 53
#define R0DE36LS4	 BUFFER[24]	//(sbk:20 - S06SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 1
#define idR0DE36LS4	 11	//(sbk:20 - S06SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 1
#define R0DE37LS4	 BUFFER[26]	//(sbk:20 - S07SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 2
#define idR0DE37LS4	 12	//(sbk:20 - S07SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 2
#define R0DE38LS4	 BUFFER[28]	//(sbk:20 - S08SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3 место 3
#define idR0DE38LS4	 13	//(sbk:20 - S08SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3 место 3
#define R0DE39LS4	 BUFFER[30]	//(sbk:20 - S09SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП24-2 место 4
#define idR0DE39LS4	 14	//(sbk:20 - S09SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП24-2 место 4
#define R0DE3CLS4	 BUFFER[32]	//( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 7
#define idR0DE3CLS4	 15	//( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 7
#define R0DE3DLS4	 BUFFER[34]	//( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 8
#define idR0DE3DLS4	 16	//( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 8
#define TTLaknp4	 BUFFER[36]	//( - , AKNP4) ttl
#define idTTLaknp4	 17	//( - , AKNP4) ttl
#define TestDiagnAKNP4	 BUFFER[39]	//( - , AKNP4) Неисправность от диагностики
#define idTestDiagnAKNP4	 18	//( - , AKNP4) Неисправность от диагностики
#define R0DEB1LS4	 BUFFER[41]	//(sbk:20 - S10SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 7
#define idR0DEB1LS4	 19	//(sbk:20 - S10SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 7
#define R0DEB2LS4	 BUFFER[43]	//(sbk:20 - S11SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 7
#define idR0DEB2LS4	 20	//(sbk:20 - S11SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 7
#define R0DEB4LS4	 BUFFER[45]	//(sbk:20 - S13SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 8
#define idR0DEB4LS4	 21	//(sbk:20 - S13SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 8
#define R0DEB3LS4	 BUFFER[47]	//(sbk:20 - S12SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 8
#define idR0DEB3LS4	 22	//(sbk:20 - S12SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 8
#define R0IS01FI0	 BUFFER[49]	//( - , MA4S) Признак работы с имитатором
#define idR0IS01FI0	 23	//( - , MA4S) Признак работы с имитатором
#define R0IN01FI4	 BUFFER[51]	//( - , MA4S) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI4	 24	//( - , MA4S) Выход СНМ-11 Гц от ПТИ
#define R0IN02FS4	 BUFFER[56]	//( - , AKNP4) Выход КНК15-1 Гц
#define idR0IN02FS4	 25	//( - , AKNP4) Выход КНК15-1 Гц
#define R0IN03FI4	 BUFFER[61]	//( - , MA4S) Выход КНК53М Гц от ПТИ
#define idR0IN03FI4	 26	//( - , MA4S) Выход КНК53М Гц от ПТИ
#define R0IN01FV4	 BUFFER[66]	//(vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
#define idR0IN01FV4	 27	//(vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
#define R0IN02FV4	 BUFFER[71]	//(vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
#define idR0IN02FV4	 28	//(vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
#define R0IN03FV4	 BUFFER[76]	//(vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
#define idR0IN03FV4	 29	//(vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
#define R0VN02RS4	 BUFFER[81]	//( - , A4Bz1, A4Bz2) Уровень мощности канал 4
#define idR0VN02RS4	 30	//( - , A4Bz1, A4Bz2) Уровень мощности канал 4
#define R0VN01RS4	 BUFFER[86]	//( - , A4Bz1, A4Bz2) Период разгона канал 4
#define idR0VN01RS4	 31	//( - , A4Bz1, A4Bz2) Период разгона канал 4
#define R0VN61LS4	 BUFFER[91]	//( - , A4Bz1, A4Bz2) ПС по мощности канал 4
#define idR0VN61LS4	 32	//( - , A4Bz1, A4Bz2) ПС по мощности канал 4
#define R0VN74LZ1	 BUFFER[93]	//(fds16:05 - K09FDSR, - ) АС по мощности канал 4 на БАЗ1
#define idR0VN74LZ1	 33	//(fds16:05 - K09FDSR, - ) АС по мощности канал 4 на БАЗ1
#define R0VN65LS4	 BUFFER[95]	//( - , A4Bz1, A4Bz2) ПС по периоду разгона канал 4
#define idR0VN65LS4	 34	//( - , A4Bz1, A4Bz2) ПС по периоду разгона канал 4
#define R0VN78LZ1	 BUFFER[97]	//(fds16:05 - K10FDSR, - ) АС по периоду разгона канал 4 на БАЗ1
#define idR0VN78LZ1	 35	//(fds16:05 - K10FDSR, - ) АС по периоду разгона канал 4 на БАЗ1
#define A0EE01LS4	 BUFFER[99]	//(fds16:05 - K11FDSR, - ) Исправность АКНП канал 4 на БАЗ1
#define idA0EE01LS4	 36	//(fds16:05 - K11FDSR, - ) Исправность АКНП канал 4 на БАЗ1
#define R0IN01FS4	 BUFFER[101]	//( - , AKNP4) Выход СНМ-11 Гц
#define idR0IN01FS4	 37	//( - , AKNP4) Выход СНМ-11 Гц
#define R0IN02FI4	 BUFFER[106]	//( - , MA4S) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI4	 38	//( - , MA4S) Выход КНК15-1 Гц от ПТИ
#define R0VN03RS4	 BUFFER[111]	//( - , AKNP4) Измеренный нейтронный поток канал 4
#define idR0VN03RS4	 39	//( - , AKNP4) Измеренный нейтронный поток канал 4
#define R0VN04RS4	 BUFFER[116]	//( - , AKNP4) Реактивность канал 4
#define idR0VN04RS4	 40	//( - , AKNP4) Реактивность канал 4
#define A1VN71LS4	 BUFFER[121]	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
#define idA1VN71LS4	 41	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
#define R0IN03FS4	 BUFFER[123]	//( - , AKNP4) Выход КНК53М Гц
#define idR0IN03FS4	 42	//( - , AKNP4) Выход КНК53М Гц
#define A0EE02LS4	 BUFFER[128]	//( - , AKNP4) Исправность АКНП4 (от сшивки каналов) канал 4
#define idA0EE02LS4	 43	//( - , AKNP4) Исправность АКНП4 (от сшивки каналов) канал 4
#define R0IE11LS4	 BUFFER[130]	//( - , - ) Исправность ВИП 1,6 (№17) СНМ11 4 канала
#define idR0IE11LS4	 44	//( - , - ) Исправность ВИП 1,6 (№17) СНМ11 4 канала
#define R0IE12LS4	 BUFFER[132]	//( - , - ) Исправность ВИП 0,5 (№18) КНК15-1 4 канала
#define idR0IE12LS4	 45	//( - , - ) Исправность ВИП 0,5 (№18) КНК15-1 4 канала
#define R0IE13LS4	 BUFFER[134]	//( - , - ) Исправность ВИП 0,5 (№19) КНК53М 4 канала
#define idR0IE13LS4	 46	//( - , - ) Исправность ВИП 0,5 (№19) КНК53М 4 канала
#define R0VN13RS4	 BUFFER[136]	//( - , AKNP4) Нейтронный поток по камере СНМ11 канал 4
#define idR0VN13RS4	 47	//( - , AKNP4) Нейтронный поток по камере СНМ11 канал 4
#define R0VN23RS4	 BUFFER[141]	//( - , AKNP4) Нейтронный поток по камере КНК15-1 канал 4
#define idR0VN23RS4	 48	//( - , AKNP4) Нейтронный поток по камере КНК15-1 канал 4
#define R0VN33RS4	 BUFFER[146]	//( - , AKNP4) Нейтронный поток по камере КНК53М канал 4
#define idR0VN33RS4	 49	//( - , AKNP4) Нейтронный поток по камере КНК53М канал 4
#define R0VN15RS4	 BUFFER[151]	//( - , AKNP4) Номер ведущей камеры канал 4
#define idR0VN15RS4	 50	//( - , AKNP4) Номер ведущей камеры канал 4
#define R0IE01LS4	 BUFFER[154]	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 4
#define idR0IE01LS4	 51	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 4
#define R0IE02LS4	 BUFFER[156]	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 4
#define idR0IE02LS4	 52	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 4
#define A0VN71LS4	 BUFFER[158]	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
#define idA0VN71LS4	 53	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
#define R0VN74LZ2	 BUFFER[160]	//(fds16:05 - K13FDSR, - ) АС по мощности канал 4 на БАЗ2
#define idR0VN74LZ2	 54	//(fds16:05 - K13FDSR, - ) АС по мощности канал 4 на БАЗ2
#define R0VN78LZ2	 BUFFER[162]	//(fds16:05 - K14FDSR, - ) АС по периоду разгона канал 4 на БАЗ2
#define idR0VN78LZ2	 55	//(fds16:05 - K14FDSR, - ) АС по периоду разгона канал 4 на БАЗ2
#define A1EE01LS4	 BUFFER[164]	//(fds16:05 - K15FDSR, - ) Исправность АКНП канал 4 на БАЗ2
#define idA1EE01LS4	 56	//(fds16:05 - K15FDSR, - ) Исправность АКНП канал 4 на БАЗ2
#define B8VC01RDU	 BUFFER[166]	//( - , A4Bz1, A4Bz2) Координата АЗ2, мм
#define idB8VC01RDU	 57	//( - , A4Bz1, A4Bz2) Координата АЗ2, мм
#define R0EE04LZ1	 BUFFER[171]	//( - , AKNP4) Питание  АКНП4  отключить
#define idR0EE04LZ1	 58	//( - , AKNP4) Питание  АКНП4  отключить
#define fEM_R0UR01RSS	 BUFFER[173]	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RSS	 59	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R0UL52RSS	 BUFFER[178]	//(R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	 60	//(R0UL52RSS) Уровень АС по мощности
#define fEM_R0UL41RSS	 BUFFER[183]	//(R0UL41RSS) Уровень ПС по периоду разгона
#define idfEM_R0UL41RSS	 61	//(R0UL41RSS) Уровень ПС по периоду разгона
#define fEM_R0UL51RSS	 BUFFER[188]	//(R0UL51RSS) Уровень АС по периоду разгона
#define idfEM_R0UL51RSS	 62	//(R0UL51RSS) Уровень АС по периоду разгона
#define fEM_R0UH02RSS	 BUFFER[193]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define idfEM_R0UH02RSS	 63	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define fEM_R0UH03RSS	 BUFFER[198]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define idfEM_R0UH03RSS	 64	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define fEM_R0UL42RSS	 BUFFER[203]	//(R0UL42RSS) Уровень ПС по мощности
#define idfEM_R0UL42RSS	 65	//(R0UL42RSS) Уровень ПС по мощности
#define fEM_R7UX00RSS	 BUFFER[208]	//(R7UX00RSS) X-координата АЗ1 (см)
#define idfEM_R7UX00RSS	 66	//(R7UX00RSS) X-координата АЗ1 (см)
#define fEM_R7UY00RSS	 BUFFER[213]	//(R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	 67	//(R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UX10RSS	 BUFFER[218]	//(R7UX10RSS) X-координата камеры R7IN41
#define idfEM_R7UX10RSS	 68	//(R7UX10RSS) X-координата камеры R7IN41
#define fEM_R7UX11RSS	 BUFFER[223]	//(R7UX11RSS) X-координата камеры R7IN42
#define idfEM_R7UX11RSS	 69	//(R7UX11RSS) X-координата камеры R7IN42
#define fEM_R7UX12RSS	 BUFFER[228]	//(R7UX12RSS) X-координата камеры R7IN43
#define idfEM_R7UX12RSS	 70	//(R7UX12RSS) X-координата камеры R7IN43
#define fEM_R7UY10RSS	 BUFFER[233]	//(R7UY10RSS) Y-координата камеры R7IN41
#define idfEM_R7UY10RSS	 71	//(R7UY10RSS) Y-координата камеры R7IN41
#define fEM_R7UY11RSS	 BUFFER[238]	//(R7UY11RSS) Y-координата камеры R7IN42
#define idfEM_R7UY11RSS	 72	//(R7UY11RSS) Y-координата камеры R7IN42
#define fEM_R7UY12RSS	 BUFFER[243]	//(R7UY12RSS) Y-координата камеры R7IN43
#define idfEM_R7UY12RSS	 73	//(R7UY12RSS) Y-координата камеры R7IN43
#define fEM_A0UX00RSS	 BUFFER[248]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 74	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX10RSS	 BUFFER[253]	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define idfEM_A0UX10RSS	 75	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define fEM_A0UX11RSS	 BUFFER[258]	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define idfEM_A0UX11RSS	 76	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define fEM_A0UX12RSS	 BUFFER[263]	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define idfEM_A0UX12RSS	 77	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define fEM_B0UX10RSS	 BUFFER[268]	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define idfEM_B0UX10RSS	 78	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define fEM_B0UX11RSS	 BUFFER[273]	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define idfEM_B0UX11RSS	 79	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define fEM_B0UX12RSS	 BUFFER[278]	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define idfEM_B0UX12RSS	 80	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define fEM_R0UH05RSS	 BUFFER[283]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 81	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UN03RSS	 BUFFER[288]	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN03RSS	 82	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R0UH01RSS	 BUFFER[293]	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
#define idfEM_R0UH01RSS	 83	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
#define fEM_R0UH21RSS	 BUFFER[298]	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	 84	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	 BUFFER[303]	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	 85	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	 BUFFER[308]	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	 86	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0UL02RSS	 BUFFER[313]	//(R0UL02RSS) Tф-постоянная времени, с
#define idfEM_R0UL02RSS	 87	//(R0UL02RSS) Tф-постоянная времени, с
#define fEM_R0UL01RSS	 BUFFER[318]	//(R0UL01RSS) Шаг (с) измерения периода
#define idfEM_R0UL01RSS	 88	//(R0UL01RSS) Шаг (с) измерения периода
#define fEM_R0IN11FN4	 BUFFER[323]	//(R0IN11FN4) Коэффициент A (А4 к 1)
#define idfEM_R0IN11FN4	 89	//(R0IN11FN4) Коэффициент A (А4 к 1)
#define fEM_R0IN21FN4	 BUFFER[328]	//(R0IN21FN4) Коэффициент A (А4 к 2)
#define idfEM_R0IN21FN4	 90	//(R0IN21FN4) Коэффициент A (А4 к 2)
#define fEM_R0IN12FN4	 BUFFER[333]	//(R0IN12FN4) Коэффициент B (А4 к 1)
#define idfEM_R0IN12FN4	 91	//(R0IN12FN4) Коэффициент B (А4 к 1)
#define fEM_R0IN22FN4	 BUFFER[338]	//(R0IN22FN4) Коэффициент B (А4 к 2)
#define idfEM_R0IN22FN4	 92	//(R0IN22FN4) Коэффициент B (А4 к 2)
#define fEM_R0IN31FN4	 BUFFER[343]	//(R0IN31FN4) Коэффициент A (А4 к 3)
#define idfEM_R0IN31FN4	 93	//(R0IN31FN4) Коэффициент A (А4 к 3)
#define fEM_R0IN32FN4	 BUFFER[348]	//(R0IN32FN4) Коэффициент B (А4 к 3)
#define idfEM_R0IN32FN4	 94	//(R0IN32FN4) Коэффициент B (А4 к 3)
#define bFirstEnterFlag	 BUFFER[353]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 95	//(bFirstEnterFlag) 
#define internal1_m87_sttlf	 BUFFER[355]	//(internal1_m87_sttlf) sttlf - счетчик для вещественного формата
#define idinternal1_m87_sttlf	 96	//(internal1_m87_sttlf) sttlf - счетчик для вещественного формата
#define internal1_m18_Nk	 BUFFER[358]	//(internal1_m18_Nk) Nk - ведущая камера
#define idinternal1_m18_Nk	 97	//(internal1_m18_Nk) Nk - ведущая камера
#define internal1_m56_flst	 BUFFER[361]	//(internal1_m56_flst)  флаг старта измерения
#define idinternal1_m56_flst	 98	//(internal1_m56_flst)  флаг старта измерения
#define internal1_m56_chsr	 BUFFER[364]	//(internal1_m56_chsr)  счетчик усреднения
#define idinternal1_m56_chsr	 99	//(internal1_m56_chsr)  счетчик усреднения
#define internal1_m56_chizm	 BUFFER[367]	//(internal1_m56_chizm)  счетчик уменьшения мощности
#define idinternal1_m56_chizm	 100	//(internal1_m56_chizm)  счетчик уменьшения мощности
#define internal1_m56_sumtim	 BUFFER[370]	//(internal1_m56_sumtim)  время измерения мощности
#define idinternal1_m56_sumtim	 101	//(internal1_m56_sumtim)  время измерения мощности
#define internal1_m56_W1	 BUFFER[375]	//(internal1_m56_W1)  мощность на старте измерения
#define idinternal1_m56_W1	 102	//(internal1_m56_W1)  мощность на старте измерения
#define internal1_m56_W2	 BUFFER[380]	//(internal1_m56_W2)  мощность в конце измерения
#define idinternal1_m56_W2	 103	//(internal1_m56_W2)  мощность в конце измерения
#define internal1_m56_Wmin	 BUFFER[385]	//(internal1_m56_Wmin)  минимальное измерение в серии
#define idinternal1_m56_Wmin	 104	//(internal1_m56_Wmin)  минимальное измерение в серии
#define internal1_m56_Wmax	 BUFFER[390]	//(internal1_m56_Wmax)  максимальное измерение в серии
#define idinternal1_m56_Wmax	 105	//(internal1_m56_Wmax)  максимальное измерение в серии
#define internal1_m56_Wlast	 BUFFER[395]	//(internal1_m56_Wlast)  последнее растущее измерение
#define idinternal1_m56_Wlast	 106	//(internal1_m56_Wlast)  последнее растущее измерение
#define internal1_m56_y0	 BUFFER[400]	//(internal1_m56_y0) y0 - внутренний параметр
#define idinternal1_m56_y0	 107	//(internal1_m56_y0) y0 - внутренний параметр
#define internal1_m56_MyFirstEnterFlag	 BUFFER[405]	//(internal1_m56_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m56_MyFirstEnterFlag	 108	//(internal1_m56_MyFirstEnterFlag)  FirstEnterFlag
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &R0EE04LZ2},	//( - , AKNP4) Питание  АКНП4  отключить
	{ 2	,3	,1	, &R0DE01LS4},	//(vchs:01 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 1 месте
	{ 3	,3	,1	, &R0DE02LS4},	//(vchs:02 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 2 месте
	{ 4	,3	,1	, &R0DE04LS4},	//(vds32:04 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 4 месте
	{ 5	,3	,1	, &R0DE05LS4},	//(fds16:05 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 5 месте
	{ 6	,1	,1	, &R0DE31LS4},	//(sbk:20 - S01SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 1
	{ 7	,1	,1	, &R0DE32LS4},	//(sbk:20 - S02SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 2
	{ 8	,1	,1	, &R0DE33LS4},	//(sbk:20 - S03SBK, DiagnAKNP4) диагностика шкафа АКНП4 двери
	{ 9	,1	,1	, &R0DE34LS4},	//(sbk:20 - S04SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура меньше 43
	{ 10	,1	,1	, &R0DE35LS4},	//(sbk:20 - S05SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура больше 53
	{ 11	,1	,1	, &R0DE36LS4},	//(sbk:20 - S06SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 1
	{ 12	,1	,1	, &R0DE37LS4},	//(sbk:20 - S07SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 2
	{ 13	,1	,1	, &R0DE38LS4},	//(sbk:20 - S08SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3 место 3
	{ 14	,1	,1	, &R0DE39LS4},	//(sbk:20 - S09SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП24-2 место 4
	{ 15	,1	,1	, &R0DE3CLS4},	//( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 7
	{ 16	,1	,1	, &R0DE3DLS4},	//( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 8
	{ 17	,3	,1	, &TTLaknp4},	//( - , AKNP4) ttl
	{ 18	,1	,1	, &TestDiagnAKNP4},	//( - , AKNP4) Неисправность от диагностики
	{ 19	,1	,1	, &R0DEB1LS4},	//(sbk:20 - S10SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 7
	{ 20	,1	,1	, &R0DEB2LS4},	//(sbk:20 - S11SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 7
	{ 21	,1	,1	, &R0DEB4LS4},	//(sbk:20 - S13SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 8
	{ 22	,1	,1	, &R0DEB3LS4},	//(sbk:20 - S12SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 8
	{ 23	,1	,1	, &R0IS01FI0},	//( - , MA4S) Признак работы с имитатором
	{ 24	,8	,1	, &R0IN01FI4},	//( - , MA4S) Выход СНМ-11 Гц от ПТИ
	{ 25	,8	,1	, &R0IN02FS4},	//( - , AKNP4) Выход КНК15-1 Гц
	{ 26	,8	,1	, &R0IN03FI4},	//( - , MA4S) Выход КНК53М Гц от ПТИ
	{ 27	,8	,1	, &R0IN01FV4},	//(vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
	{ 28	,8	,1	, &R0IN02FV4},	//(vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
	{ 29	,8	,1	, &R0IN03FV4},	//(vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
	{ 30	,8	,1	, &R0VN02RS4},	//( - , A4Bz1, A4Bz2) Уровень мощности канал 4
	{ 31	,8	,1	, &R0VN01RS4},	//( - , A4Bz1, A4Bz2) Период разгона канал 4
	{ 32	,1	,1	, &R0VN61LS4},	//( - , A4Bz1, A4Bz2) ПС по мощности канал 4
	{ 33	,1	,1	, &R0VN74LZ1},	//(fds16:05 - K09FDSR, - ) АС по мощности канал 4 на БАЗ1
	{ 34	,1	,1	, &R0VN65LS4},	//( - , A4Bz1, A4Bz2) ПС по периоду разгона канал 4
	{ 35	,1	,1	, &R0VN78LZ1},	//(fds16:05 - K10FDSR, - ) АС по периоду разгона канал 4 на БАЗ1
	{ 36	,1	,1	, &A0EE01LS4},	//(fds16:05 - K11FDSR, - ) Исправность АКНП канал 4 на БАЗ1
	{ 37	,8	,1	, &R0IN01FS4},	//( - , AKNP4) Выход СНМ-11 Гц
	{ 38	,8	,1	, &R0IN02FI4},	//( - , MA4S) Выход КНК15-1 Гц от ПТИ
	{ 39	,8	,1	, &R0VN03RS4},	//( - , AKNP4) Измеренный нейтронный поток канал 4
	{ 40	,8	,1	, &R0VN04RS4},	//( - , AKNP4) Реактивность канал 4
	{ 41	,1	,1	, &A1VN71LS4},	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
	{ 42	,8	,1	, &R0IN03FS4},	//( - , AKNP4) Выход КНК53М Гц
	{ 43	,1	,1	, &A0EE02LS4},	//( - , AKNP4) Исправность АКНП4 (от сшивки каналов) канал 4
	{ 44	,1	,1	, &R0IE11LS4},	//( - , - ) Исправность ВИП 1,6 (№17) СНМ11 4 канала
	{ 45	,1	,1	, &R0IE12LS4},	//( - , - ) Исправность ВИП 0,5 (№18) КНК15-1 4 канала
	{ 46	,1	,1	, &R0IE13LS4},	//( - , - ) Исправность ВИП 0,5 (№19) КНК53М 4 канала
	{ 47	,8	,1	, &R0VN13RS4},	//( - , AKNP4) Нейтронный поток по камере СНМ11 канал 4
	{ 48	,8	,1	, &R0VN23RS4},	//( - , AKNP4) Нейтронный поток по камере КНК15-1 канал 4
	{ 49	,8	,1	, &R0VN33RS4},	//( - , AKNP4) Нейтронный поток по камере КНК53М канал 4
	{ 50	,3	,1	, &R0VN15RS4},	//( - , AKNP4) Номер ведущей камеры канал 4
	{ 51	,1	,1	, &R0IE01LS4},	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 4
	{ 52	,1	,1	, &R0IE02LS4},	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 4
	{ 53	,1	,1	, &A0VN71LS4},	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
	{ 54	,1	,1	, &R0VN74LZ2},	//(fds16:05 - K13FDSR, - ) АС по мощности канал 4 на БАЗ2
	{ 55	,1	,1	, &R0VN78LZ2},	//(fds16:05 - K14FDSR, - ) АС по периоду разгона канал 4 на БАЗ2
	{ 56	,1	,1	, &A1EE01LS4},	//(fds16:05 - K15FDSR, - ) Исправность АКНП канал 4 на БАЗ2
	{ 57	,8	,1	, &B8VC01RDU},	//( - , A4Bz1, A4Bz2) Координата АЗ2, мм
	{ 58	,1	,1	, &R0EE04LZ1},	//( - , AKNP4) Питание  АКНП4  отключить
	{ 59	,8	,1	, &fEM_R0UR01RSS},	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
	{ 60	,8	,1	, &fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{ 61	,8	,1	, &fEM_R0UL41RSS},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{ 62	,8	,1	, &fEM_R0UL51RSS},	//(R0UL51RSS) Уровень АС по периоду разгона
	{ 63	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{ 64	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{ 65	,8	,1	, &fEM_R0UL42RSS},	//(R0UL42RSS) Уровень ПС по мощности
	{ 66	,8	,1	, &fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{ 67	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{ 68	,8	,1	, &fEM_R7UX10RSS},	//(R7UX10RSS) X-координата камеры R7IN41
	{ 69	,8	,1	, &fEM_R7UX11RSS},	//(R7UX11RSS) X-координата камеры R7IN42
	{ 70	,8	,1	, &fEM_R7UX12RSS},	//(R7UX12RSS) X-координата камеры R7IN43
	{ 71	,8	,1	, &fEM_R7UY10RSS},	//(R7UY10RSS) Y-координата камеры R7IN41
	{ 72	,8	,1	, &fEM_R7UY11RSS},	//(R7UY11RSS) Y-координата камеры R7IN42
	{ 73	,8	,1	, &fEM_R7UY12RSS},	//(R7UY12RSS) Y-координата камеры R7IN43
	{ 74	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 75	,8	,1	, &fEM_A0UX10RSS},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{ 76	,8	,1	, &fEM_A0UX11RSS},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{ 77	,8	,1	, &fEM_A0UX12RSS},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{ 78	,8	,1	, &fEM_B0UX10RSS},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{ 79	,8	,1	, &fEM_B0UX11RSS},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{ 80	,8	,1	, &fEM_B0UX12RSS},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{ 81	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 82	,8	,1	, &fEM_R0UN03RSS},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 83	,8	,1	, &fEM_R0UH01RSS},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
	{ 84	,8	,1	, &fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{ 85	,8	,1	, &fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{ 86	,8	,1	, &fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{ 87	,8	,1	, &fEM_R0UL02RSS},	//(R0UL02RSS) Tф-постоянная времени, с
	{ 88	,8	,1	, &fEM_R0UL01RSS},	//(R0UL01RSS) Шаг (с) измерения периода
	{ 89	,8	,1	, &fEM_R0IN11FN4},	//(R0IN11FN4) Коэффициент A (А4 к 1)
	{ 90	,8	,1	, &fEM_R0IN21FN4},	//(R0IN21FN4) Коэффициент A (А4 к 2)
	{ 91	,8	,1	, &fEM_R0IN12FN4},	//(R0IN12FN4) Коэффициент B (А4 к 1)
	{ 92	,8	,1	, &fEM_R0IN22FN4},	//(R0IN22FN4) Коэффициент B (А4 к 2)
	{ 93	,8	,1	, &fEM_R0IN31FN4},	//(R0IN31FN4) Коэффициент A (А4 к 3)
	{ 94	,8	,1	, &fEM_R0IN32FN4},	//(R0IN32FN4) Коэффициент B (А4 к 3)
	{ 95	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 96	,3	,1	, &internal1_m87_sttlf},	//(internal1_m87_sttlf) sttlf - счетчик для вещественного формата
	{ 97	,3	,1	, &internal1_m18_Nk},	//(internal1_m18_Nk) Nk - ведущая камера
	{ 98	,3	,1	, &internal1_m56_flst},	//(internal1_m56_flst)  флаг старта измерения
	{ 99	,3	,1	, &internal1_m56_chsr},	//(internal1_m56_chsr)  счетчик усреднения
	{ 100	,3	,1	, &internal1_m56_chizm},	//(internal1_m56_chizm)  счетчик уменьшения мощности
	{ 101	,8	,1	, &internal1_m56_sumtim},	//(internal1_m56_sumtim)  время измерения мощности
	{ 102	,8	,1	, &internal1_m56_W1},	//(internal1_m56_W1)  мощность на старте измерения
	{ 103	,8	,1	, &internal1_m56_W2},	//(internal1_m56_W2)  мощность в конце измерения
	{ 104	,8	,1	, &internal1_m56_Wmin},	//(internal1_m56_Wmin)  минимальное измерение в серии
	{ 105	,8	,1	, &internal1_m56_Wmax},	//(internal1_m56_Wmax)  максимальное измерение в серии
	{ 106	,8	,1	, &internal1_m56_Wlast},	//(internal1_m56_Wlast)  последнее растущее измерение
	{ 107	,8	,1	, &internal1_m56_y0},	//(internal1_m56_y0) y0 - внутренний параметр
	{ 108	,1	,1	, &internal1_m56_MyFirstEnterFlag},	//(internal1_m56_MyFirstEnterFlag)  FirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="aknp4.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{59,"fEM_R0UR01RSS\0"}, 
{60,"fEM_R0UL52RSS\0"}, 
{61,"fEM_R0UL41RSS\0"}, 
{62,"fEM_R0UL51RSS\0"}, 
{63,"fEM_R0UH02RSS\0"}, 
{64,"fEM_R0UH03RSS\0"}, 
{65,"fEM_R0UL42RSS\0"}, 
{66,"fEM_R7UX00RSS\0"}, 
{67,"fEM_R7UY00RSS\0"}, 
{68,"fEM_R7UX10RSS\0"}, 
{69,"fEM_R7UX11RSS\0"}, 
{70,"fEM_R7UX12RSS\0"}, 
{71,"fEM_R7UY10RSS\0"}, 
{72,"fEM_R7UY11RSS\0"}, 
{73,"fEM_R7UY12RSS\0"}, 
{74,"fEM_A0UX00RSS\0"}, 
{75,"fEM_A0UX10RSS\0"}, 
{76,"fEM_A0UX11RSS\0"}, 
{77,"fEM_A0UX12RSS\0"}, 
{78,"fEM_B0UX10RSS\0"}, 
{79,"fEM_B0UX11RSS\0"}, 
{80,"fEM_B0UX12RSS\0"}, 
{81,"fEM_R0UH05RSS\0"}, 
{82,"fEM_R0UN03RSS\0"}, 
{83,"fEM_R0UH01RSS\0"}, 
{84,"fEM_R0UH21RSS\0"}, 
{85,"fEM_R0UH22RSS\0"}, 
{86,"fEM_R0UH23RSS\0"}, 
{87,"fEM_R0UL02RSS\0"}, 
{88,"fEM_R0UL01RSS\0"}, 
{89,"fEM_R0IN11FN4\0"}, 
{90,"fEM_R0IN21FN4\0"}, 
{91,"fEM_R0IN12FN4\0"}, 
{92,"fEM_R0IN22FN4\0"}, 
{93,"fEM_R0IN31FN4\0"}, 
{94,"fEM_R0IN32FN4\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_AKNP4[]={  // 
	{&R0EE04LZ1,1,0},	//( - , AKNP4) Питание  АКНП4  отключить
	{&R0EE04LZ2,1,1},	//( - , AKNP4) Питание  АКНП4  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_AKNP4[]={  // 
	{&A0EE02LS4,1,0},	//( - , AKNP4) Исправность АКНП4 (от сшивки каналов) канал 4
	{&TestDiagnAKNP4,1,1},	//( - , AKNP4) Неисправность от диагностики
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_AKNP4[]={  // 
	{&R0IN01FS4,8,0},	//( - , AKNP4) Выход СНМ-11 Гц
	{&R0VN03RS4,8,2},	//( - , AKNP4) Измеренный нейтронный поток канал 4
	{&R0VN04RS4,8,4},	//( - , AKNP4) Реактивность канал 4
	{&R0IN03FS4,8,6},	//( - , AKNP4) Выход КНК53М Гц
	{&R0VN13RS4,8,8},	//( - , AKNP4) Нейтронный поток по камере СНМ11 канал 4
	{&R0VN23RS4,8,10},	//( - , AKNP4) Нейтронный поток по камере КНК15-1 канал 4
	{&R0VN33RS4,8,12},	//( - , AKNP4) Нейтронный поток по камере КНК53М канал 4
	{&R0VN15RS4,3,14},	//( - , AKNP4) Номер ведущей камеры канал 4
	{&TTLaknp4,3,15},	//( - , AKNP4) ttl
	{&R0IN02FS4,8,16},	//( - , AKNP4) Выход КНК15-1 Гц
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_AKNP4[]={  // 
	{&fEM_R0UR01RSS,8,0},	//( - , AKNP4) Уставка АКНП ПС  АЗ по периоду (сек)
	{&fEM_R0UL52RSS,8,2},	//( - , AKNP4) Уровень АС по мощности
	{&fEM_R0UL41RSS,8,4},	//( - , AKNP4) Уровень ПС по периоду разгона
	{&fEM_R0UL51RSS,8,6},	//( - , AKNP4) Уровень АС по периоду разгона
	{&fEM_R0UH02RSS,8,8},	//( - , AKNP4) Коэфф. преобразования частота->нейтр/с КНК15-1
	{&fEM_R0UH03RSS,8,10},	//( - , AKNP4) Коэфф. преобразования частота->нейтр/с КНК53М
	{&fEM_R0UL42RSS,8,12},	//( - , AKNP4) Уровень ПС по мощности
	{&fEM_R7UX00RSS,8,14},	//( - , AKNP4) X-координата АЗ1 (см)
	{&fEM_R7UY00RSS,8,16},	//( - , AKNP4) Y-координата АЗ1 (см)
	{&fEM_R7UX10RSS,8,18},	//( - , AKNP4) X-координата камеры R7IN41
	{&fEM_R7UX11RSS,8,20},	//( - , AKNP4) X-координата камеры R7IN42
	{&fEM_R7UX12RSS,8,22},	//( - , AKNP4) X-координата камеры R7IN43
	{&fEM_R7UY10RSS,8,24},	//( - , AKNP4) Y-координата камеры R7IN41
	{&fEM_R7UY11RSS,8,26},	//( - , AKNP4) Y-координата камеры R7IN42
	{&fEM_R7UY12RSS,8,28},	//( - , AKNP4) Y-координата камеры R7IN43
	{&fEM_A0UX00RSS,8,30},	//( - , AKNP4) Эффективный радиус АЗ
	{&fEM_A0UX10RSS,8,32},	//( - , AKNP4) Первый коэффициент калибровки камеры 10
	{&fEM_A0UX11RSS,8,34},	//( - , AKNP4) Первый коэффициент калибровки камеры 11
	{&fEM_A0UX12RSS,8,36},	//( - , AKNP4) Первый коэффициент калибровки камеры 12
	{&fEM_B0UX10RSS,8,38},	//( - , AKNP4) Второй коэффициент калибровки камеры 10
	{&fEM_B0UX11RSS,8,40},	//( - , AKNP4) Второй коэффициент калибровки камеры 11
	{&fEM_B0UX12RSS,8,42},	//( - , AKNP4) Второй коэффициент калибровки камеры 12
	{&fEM_R0UH05RSS,8,44},	//( - , AKNP4) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_R0UN03RSS,8,46},	//( - , AKNP4) Нижняя граница интервала мощности для измерения периода (ватт)
	{&fEM_R0UH01RSS,8,48},	//( - , AKNP4) Коэфф. преобразования частота->нейтр/с СНМ-11
	{&fEM_R0UH21RSS,8,50},	//( - , AKNP4) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{&fEM_R0UH22RSS,8,52},	//( - , AKNP4) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{&fEM_R0UH23RSS,8,54},	//( - , AKNP4) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{&fEM_R0UL02RSS,8,56},	//( - , AKNP4) Tф-постоянная времени, с
	{&fEM_R0UL01RSS,8,58},	//( - , AKNP4) Шаг (с) измерения периода
	{&fEM_R0IN11FN4,8,60},	//( - , AKNP4) Коэффициент A (А4 к 1)
	{&fEM_R0IN21FN4,8,62},	//( - , AKNP4) Коэффициент A (А4 к 2)
	{&fEM_R0IN12FN4,8,64},	//( - , AKNP4) Коэффициент B (А4 к 1)
	{&fEM_R0IN22FN4,8,66},	//( - , AKNP4) Коэффициент B (А4 к 2)
	{&fEM_R0IN31FN4,8,68},	//( - , AKNP4) Коэффициент A (А4 к 3)
	{&fEM_R0IN32FN4,8,70},	//( - , AKNP4) Коэффициент B (А4 к 3)
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_A4Bz1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_A4Bz1[]={  // 
	{&R0VN61LS4,1,0},	//( - , A4Bz1, A4Bz2) ПС по мощности канал 4
	{&R0VN65LS4,1,1},	//( - , A4Bz1, A4Bz2) ПС по периоду разгона канал 4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_A4Bz1[]={  // 
	{&R0VN02RS4,8,0},	//( - , A4Bz1, A4Bz2) Уровень мощности канал 4
	{&R0VN01RS4,8,2},	//( - , A4Bz1, A4Bz2) Период разгона канал 4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_A4Bz1[]={  // 
	{&B8VC01RDU,8,0},	//( - , A4Bz1, A4Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_A4Bz2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_A4Bz2[]={  // 
	{&R0VN61LS4,1,0},	//( - , A4Bz1, A4Bz2) ПС по мощности канал 4
	{&R0VN65LS4,1,1},	//( - , A4Bz1, A4Bz2) ПС по периоду разгона канал 4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_A4Bz2[]={  // 
	{&R0VN02RS4,8,0},	//( - , A4Bz1, A4Bz2) Уровень мощности канал 4
	{&R0VN01RS4,8,2},	//( - , A4Bz1, A4Bz2) Период разгона канал 4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_A4Bz2[]={  // 
	{&B8VC01RDU,8,0},	//( - , A4Bz1, A4Bz2) Координата АЗ2, мм
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
static ModbusRegister coil_MA4S[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MA4S[]={  // 
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MA4S[]={  // 
	{&R0IN01FI4,8,0},	//( - , SA4) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI4,8,2},	//( - , SA4) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI4,8,4},	//( - , SA4) Выход КНК53М Гц от ПТИ
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
static ModbusDevice modbuses[]={
	{0,5002,&coil_AKNP4[0],&di_AKNP4[0],&ir_AKNP4[0],&hr_AKNP4[0],NULL,NULL,NULL,0},	 //общий slave AKNP4
	{0,5018,&coil_A4Bz1[0],&di_A4Bz1[0],&ir_A4Bz1[0],&hr_A4Bz1[0],NULL,NULL,NULL,0},	 //slave AKNP4 - Baz1
	{0,5022,&coil_A4Bz2[0],&di_A4Bz2[0],&ir_A4Bz2[0],&hr_A4Bz2[0],NULL,NULL,NULL,0},	 //slave AKNP4 - Baz2
	{0,5003,&coil_DiagnAKNP4[0],&di_DiagnAKNP4[0],&ir_DiagnAKNP4[0],&hr_DiagnAKNP4[0],NULL,NULL,NULL,0},	 //Диагностика АКНП4
	{1,5009,&coil_MA4S[0],&di_MA4S[0],&ir_MA4S[0],&hr_MA4S[0],NULL,MA4S_ip1,MA4S_ip2,100},	 //Мастер AKNP4 в SCM

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
	{&R0IN01FV4,8,0},
	{&R0DE01LS4,3,10},
	{&R0IN02FV4,8,5},
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
	{&R0IN03FV4,8,0},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS32[132];	//VDS32
static vds32r_inipar ini_VDS32={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS32={0,0,&ini_VDS32,buf_VDS32,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32[]={
	{&R0DE04LS4,3,64},
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
	{&R0VN74LZ1,1,16},
	{&R0IE02LS4,1,0},
	{&R0VN78LZ1,1,18},
	{&A0EE01LS4,1,20},
	{&R0IE01LS4,1,2},
	{&R0DE05LS4,3,38},
	{&A1VN71LS4,1,30},
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
	{&R0DE33LS4,1,4},
	{&R0DE34LS4,1,6},
	{&R0DE35LS4,1,8},
	{&R0DE36LS4,1,10},
	{&R0DE37LS4,1,12},
	{&R0DE38LS4,1,14},
	{&R0DE39LS4,1,16},
	{&R0DEB3LS4,1,22},
	{&R0DEB4LS4,1,24},
	{&R0DEB2LS4,1,20},
	{&R0DEB1LS4,1,18},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc4,0x01,12,58,def_buf_VCHS01,&table_VCHS01}, //VCHS01
	{0xc4,0x02,12,58,def_buf_VCHS02,&table_VCHS02}, //VCHS02
	{0xc2,0x04,15,132,def_buf_VDS32,&table_VDS32}, //VDS32
	{0x96,0x05,20,40,def_buf_FDS16,&table_FDS16}, //FDS16
	{0xcc,0x20,4,26,def_buf_SBKFP,&table_SBKFP}, //SBKFP
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
	setAsFloat(59,5000);
	setAsFloat(60,5100);
	setAsFloat(61,20);
	setAsFloat(62,13.0);
	setAsFloat(63,37037.04 );
	setAsFloat(64,975000.0);
	setAsFloat(65,5000);
	setAsFloat(66,1570.0);
	setAsFloat(67,506.5);
	setAsFloat(68,1555.0);
	setAsFloat(69,1281.2);
	setAsFloat(70,1269.0);
	setAsFloat(71,594.0);
	setAsFloat(72,597.2);
	setAsFloat(73,556.8);
	setAsFloat(74,11.0);
	setAsFloat(75,1.0);
	setAsFloat(76,1.0);
	setAsFloat(77,1.0);
	setAsFloat(78,0.0);
	setAsFloat(79,0.0);
	setAsFloat(80,0.0);
	setAsFloat(81,32000.0);
	setAsFloat(82,0.005);
	setAsFloat(83,20);
	setAsFloat(84,4000);
	setAsFloat(85,100000);
	setAsFloat(86,1000000);
	setAsFloat(87,2.0);
	setAsFloat(88,0.5);
	setAsFloat(89,1);
	setAsFloat(90,1);
	setAsFloat(91,0);
	setAsFloat(92,0);
	setAsFloat(93,1);
	setAsFloat(94,0);
	setAsBool(44,1);
	setAsBool(45,1);
	setAsBool(46,1);
}

// Вставка к VCHS
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

uspaint8 InternalBuf[54];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_5_ = {5,0}; /* n - N-размерность массива входных параметров */ 
ssint iRM_2_ = {2,0}; /* n - N-размерность массива входных параметров */ 
sschar bRM_1_ = {1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива значений */ 
ssint iRM_6_ = {6,0}; /* n - N-размерность массива x */ 
ssbool lRM_1_ = {1,0}; /*  */ 

uspaint8 SpaEEPROMBuf[180];

/* Определение переменных */
ssfloat var1;
ssfloat var2;
ssfloat var3;
ssfloat var4;
ssfloat var5;
ssfloat var6;
ssbool var7;
ssbool var8;
ssbool var9;
ssbool var10;
ssbool var11;
ssbool var12;
ssint var13;
ssfloat var14;
ssfloat var15;
ssbool var16;
ssfloat var17;
ssfloat var18;
ssfloat var19;
ssint var20;
ssbool var21;
ssfloat var22;
ssbool var23;
ssbool var24;
ssbool var25;
ssbool var26;
ssbool var27;
ssbool var28;
ssbool var29;
ssbool var30;
ssfloat var31;
ssbool var32;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m101_x_1[6] = {&R0DE36LS4,&R0DE37LS4,&R0DE38LS4,&R0DE39LS4,&var8,&var7};
psint  array_m87_x_1[4] = {&R0DE01LS4,&R0DE02LS4,&R0DE04LS4,&R0DE05LS4};
psbool  array_m63_x_1[2] = {&var29,&var24};
psbool  array_m62_x_1[2] = {&var29,&var30};
psbool  array_m73_x_1[5] = {&var16,&R0IE11LS4,&R0IE12LS4,&R0IE13LS4,&lRM_1_};

/* Объявление структур */
_S_pogrvh  S_pogrvh_115_1 = {&R0IN02FV4,&fEM_R0IN21FN4,&fEM_R0IN22FN4,&var1};
_S_pogrvh  S_pogrvh_117_1 = {&R0IN03FV4,&fEM_R0IN31FN4,&fEM_R0IN32FN4,&var2};
_S_pogrvh  S_pogrvh_113_1 = {&R0IN01FV4,&fEM_R0IN11FN4,&fEM_R0IN12FN4,&var3};
_S_ml  S_ml_9_1 = {&R0IN03FI4,&var2,&R0IS01FI0,&var4};
_S_ml  S_ml_8_1 = {&R0IN02FI4,&var1,&R0IS01FI0,&var5};
_S_ml  S_ml_7_1 = {&R0IN01FI4,&var3,&R0IS01FI0,&var6};
_S_noto  S_noto_103_1 = {&var9,&vainSBool};
_S_or2  S_or2_104_1 = {&R0DEB3LS4,&R0DEB4LS4,&var7};
_S_or2  S_or2_96_1 = {&R0DEB1LS4,&R0DEB2LS4,&var8};
_S_or3  S_or3_98_1 = {&var12,&var11,&var10,&var9};
_S_orn  S_orn_101_1 = {array_m101_x_1,&iRM_6_,&var10};
_S_and2  S_and2_89_1 = {&R0DE31LS4,&R0DE32LS4,&var11};
_S_diagndev  S_diagndev_87_1 = {array_m87_x_1,&iRM_4_,&var12,&var13,&vainSFloat,&internal1_m87_sttlf};
_S_ocham  S_ocham_18_1 = {&var6,&var5,&var4,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX10RSS,&fEM_B0UX10RSS,&fEM_A0UX11RSS,&fEM_B0UX11RSS,&fEM_A0UX12RSS,&fEM_B0UX12RSS,&fEM_R7UX10RSS,&fEM_R7UY10RSS,&fEM_R7UX11RSS,&fEM_R7UY11RSS,&fEM_R7UX12RSS,&fEM_R7UY12RSS,&bRM_1_,&fEM_R0UH01RSS,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&fEM_R0UH21RSS,&fEM_R0UH22RSS,&fEM_R0UH23RSS,&var14,&var15,&var16,&var17,&var18,&var19,&var20,&internal1_m18_Nk};
_S_or2  S_or2_74_1 = {&R0EE04LZ1,&R0EE04LZ2,&var21};
_S_period  S_period_56_1 = {&var15,&var26,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var22,&internal1_m56_flst,&internal1_m56_chsr,&internal1_m56_chizm,&internal1_m56_sumtim,&internal1_m56_W1,&internal1_m56_W2,&internal1_m56_Wmin,&internal1_m56_Wmax,&internal1_m56_Wlast,&internal1_m56_y0,&internal1_m56_MyFirstEnterFlag};
_S_andn  S_andn_63_1 = {array_m63_x_1,&iRM_2_,&var23};
_S_bol  S_bol_60_1 = {&fEM_R0UL41RSS,&var22,&var24};
_S_andn  S_andn_62_1 = {array_m62_x_1,&iRM_2_,&var25};
_S_andn  S_andn_73_1 = {array_m73_x_1,&iRM_5_,&var26};
_S_bol  S_bol_43_1 = {&var15,&fEM_R0UL52RSS,&var27};
_S_bol  S_bol_48_1 = {&var15,&fEM_R0UL42RSS,&var28};
_S_bol  S_bol_59_1 = {&var15,&fEM_R0UN03RSS,&var29};
_S_bol  S_bol_58_1 = {&fEM_R0UL51RSS,&var22,&var30};
_S_react  S_react_53_1 = {&var22,&var31};
_S_bol  S_bol_39_1 = {&var15,&fEM_R0UR01RSS,&var32};


void ZeroVar()
{
   var1.f=0.0;
   var2.f=0.0;
   var3.f=0.0;
   var4.f=0.0;
   var5.f=0.0;
   var6.f=0.0;
   var7.b=0;
   var8.b=0;
   var9.b=0;
   var10.b=0;
   var11.b=0;
   var12.b=0;
   var13.i=0;
   var14.f=0.0;
   var15.f=0.0;
   var16.b=0;
   var17.f=0.0;
   var18.f=0.0;
   var19.f=0.0;
   var20.i=0;
   var21.b=0;
   var22.f=0.0;
   var23.b=0;
   var24.b=0;
   var25.b=0;
   var26.b=0;
   var27.b=0;
   var28.b=0;
   var29.b=0;
   var30.b=0;
   var31.f=0.0;
   var32.b=0;
   vainSLong.l=0L;
   vainSFloat.f=0.0;
   vainSInt.i=0;
   vainSBool.b=0;
   vainSChar.c=0;

}
void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_74_1);
  diagndev(&S_diagndev_87_1);
  and2(&S_and2_89_1);
  or2(&S_or2_96_1);
  or2(&S_or2_104_1);
  orn(&S_orn_101_1);
  or3(&S_or3_98_1);
  noto(&S_noto_103_1);
  pogrvh(&S_pogrvh_113_1);
  pogrvh(&S_pogrvh_117_1);
  pogrvh(&S_pogrvh_115_1);
  ml(&S_ml_7_1);
  ml(&S_ml_8_1);
  ml(&S_ml_9_1);
  ocham(&S_ocham_18_1);
  bol(&S_bol_39_1);
  bol(&S_bol_59_1);
  bol(&S_bol_48_1);
  bol(&S_bol_43_1);
  andn(&S_andn_73_1);
  period(&S_period_56_1);
  react(&S_react_53_1);
  bol(&S_bol_58_1);
  andn(&S_andn_62_1);
  bol(&S_bol_60_1);
  andn(&S_andn_63_1);
  setData(idR0IN02FS4,&var1);
  setData(idTestDiagnAKNP4,&var9);
  setData(idTTLaknp4,&var13);
  setData(idR0DE3DLS4,&var7);
  setData(idR0DE3CLS4,&var8);
  setData(idA1EE01LS4,&var26);
  setData(idR0VN78LZ2,&var25);
  setData(idR0VN74LZ2,&var27);
  setData(idA0VN71LS4,&var32);
  setData(idR0IE02LS4,&var21);
  setData(idR0IE01LS4,&var21);
  setData(idR0VN15RS4,&var20);
  setData(idR0VN33RS4,&var19);
  setData(idR0VN23RS4,&var18);
  setData(idR0VN13RS4,&var17);
  setData(idA0EE02LS4,&var16);
  setData(idR0IN03FS4,&var2);
  setData(idA1VN71LS4,&var32);
  setData(idR0VN04RS4,&var31);
  setData(idR0VN03RS4,&var14);
  setData(idR0IN01FS4,&var3);
  setData(idA0EE01LS4,&var26);
  setData(idR0VN78LZ1,&var25);
  setData(idR0VN65LS4,&var23);
  setData(idR0VN74LZ1,&var27);
  setData(idR0VN61LS4,&var28);
  setData(idR0VN01RS4,&var22);
  setData(idR0VN02RS4,&var15);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}

void MainCycle(void)
{
     Scheme();

}
#endif
