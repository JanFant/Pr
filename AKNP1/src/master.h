#ifndef AKNP1_H
#define AKNP1_H
// Подсистема AKNP1:AKNP1
static char SimulOn=0;
static short CodeSub=3;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt, taktScheme=0, taktSS=0;
#define SIZE_BUFFER 407
static char BUFFER[407];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.51\0", 5432, "192.168.10.151\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0DE04LS1	 BUFFER[0]	//(vds32:04 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 4 месте
#define idR0DE04LS1	 1	//(vds32:04 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 4 месте
#define R0DE05LS1	 BUFFER[3]	//(fds16:05 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 5 месте
#define idR0DE05LS1	 2	//(fds16:05 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 5 месте
#define TTLa1	 BUFFER[6]	//( - , AKNP1) ttl
#define idTTLa1	 3	//( - , AKNP1) ttl
#define R0DE31LS1	 BUFFER[9]	//(sbk:20 - S01SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 1
#define idR0DE31LS1	 4	//(sbk:20 - S01SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 1
#define R0DE32LS1	 BUFFER[11]	//(sbk:20 - S02SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 2
#define idR0DE32LS1	 5	//(sbk:20 - S02SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 2
#define R0DE33LS1	 BUFFER[13]	//(sbk:20 - S03SBK, DiagnAKNP1) диагностика шкафа АКНП1 двери
#define idR0DE33LS1	 6	//(sbk:20 - S03SBK, DiagnAKNP1) диагностика шкафа АКНП1 двери
#define R0DE34LS1	 BUFFER[15]	//(sbk:20 - S04SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура меньше 43
#define idR0DE34LS1	 7	//(sbk:20 - S04SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура меньше 43
#define R0DE35LS1	 BUFFER[17]	//(sbk:20 - S05SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура больше 53
#define idR0DE35LS1	 8	//(sbk:20 - S05SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура больше 53
#define R0DE37LS1	 BUFFER[19]	//(sbk:20 - S07SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3.1 место 2
#define idR0DE37LS1	 9	//(sbk:20 - S07SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3.1 место 2
#define R0DE38LS1	 BUFFER[21]	//(sbk:20 - S08SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3 место 3
#define idR0DE38LS1	 10	//(sbk:20 - S08SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3 место 3
#define R0DE39LS1	 BUFFER[23]	//(sbk:20 - S09SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП24-2 место 4
#define idR0DE39LS1	 11	//(sbk:20 - S09SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП24-2 место 4
#define R0DE3CLS1	 BUFFER[25]	//( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 7
#define idR0DE3CLS1	 12	//( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 7
#define R0DE3DLS1	 BUFFER[27]	//( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 8
#define idR0DE3DLS1	 13	//( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 8
#define TestDiagnAKNP1	 BUFFER[29]	//( - , AKNP1) Неисправность от диагностики
#define idTestDiagnAKNP1	 14	//( - , AKNP1) Неисправность от диагностики
#define R0DEB1LS1	 BUFFER[31]	//(sbk:20 - S10SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 7
#define idR0DEB1LS1	 15	//(sbk:20 - S10SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 7
#define R0DEB2LS1	 BUFFER[33]	//(sbk:20 - S11SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 7
#define idR0DEB2LS1	 16	//(sbk:20 - S11SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 7
#define R0DEB4LS1	 BUFFER[35]	//(sbk:20 - S13SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 8
#define idR0DEB4LS1	 17	//(sbk:20 - S13SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 8
#define R0DEB3LS1	 BUFFER[37]	//(sbk:20 - S12SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 8
#define idR0DEB3LS1	 18	//(sbk:20 - S12SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 8
#define R0IN01FS1	 BUFFER[39]	//( - , AKNP1) Выход СНМ-11 Гц
#define idR0IN01FS1	 19	//( - , AKNP1) Выход СНМ-11 Гц
#define R0IN02FI1	 BUFFER[44]	//( - , MA1S) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI1	 20	//( - , MA1S) Выход КНК15-1 Гц от ПТИ
#define R0IN03FS1	 BUFFER[49]	//( - , AKNP1) Выход КНК53М Гц
#define idR0IN03FS1	 21	//( - , AKNP1) Выход КНК53М Гц
#define R0IS01FI0	 BUFFER[54]	//( - , MA1S) Признак работы с имитатором
#define idR0IS01FI0	 22	//( - , MA1S) Признак работы с имитатором
#define R0IN01FI1	 BUFFER[56]	//( - , MA1S) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI1	 23	//( - , MA1S) Выход СНМ-11 Гц от ПТИ
#define R0IN02FS1	 BUFFER[61]	//( - , AKNP1) Выход КНК15-1 Гц
#define idR0IN02FS1	 24	//( - , AKNP1) Выход КНК15-1 Гц
#define R0IN03FI1	 BUFFER[66]	//( - , MA1S) Выход КНК53М Гц от ПТИ
#define idR0IN03FI1	 25	//( - , MA1S) Выход КНК53М Гц от ПТИ
#define R0IN01FV1	 BUFFER[71]	//(vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
#define idR0IN01FV1	 26	//(vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
#define R0IN02FV1	 BUFFER[76]	//(vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
#define idR0IN02FV1	 27	//(vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
#define R0IN03FV1	 BUFFER[81]	//(vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
#define idR0IN03FV1	 28	//(vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
#define R0VN02RS1	 BUFFER[86]	//( - , A1Bz1, A1Bz2) Уровень мощности
#define idR0VN02RS1	 29	//( - , A1Bz1, A1Bz2) Уровень мощности
#define R0VN01RS1	 BUFFER[91]	//( - , A1Bz1, A1Bz2) Период разгона канал1
#define idR0VN01RS1	 30	//( - , A1Bz1, A1Bz2) Период разгона канал1
#define R0VN61LS1	 BUFFER[96]	//( - , A1Bz1, A1Bz2) ПС по мощности канал1
#define idR0VN61LS1	 31	//( - , A1Bz1, A1Bz2) ПС по мощности канал1
#define R0VN71LZ1	 BUFFER[98]	//(fds16:05 - K09FDSR, - ) АС по мощности на БАЗ1
#define idR0VN71LZ1	 32	//(fds16:05 - K09FDSR, - ) АС по мощности на БАЗ1
#define R0VN65LS1	 BUFFER[100]	//( - , A1Bz1, A1Bz2) ПС по периоду разгона канал1
#define idR0VN65LS1	 33	//( - , A1Bz1, A1Bz2) ПС по периоду разгона канал1
#define R0VN75LZ1	 BUFFER[102]	//(fds16:05 - K10FDSR, - ) АС по периоду разгонана БАЗ1
#define idR0VN75LZ1	 34	//(fds16:05 - K10FDSR, - ) АС по периоду разгонана БАЗ1
#define A0EE01LS1	 BUFFER[104]	//(fds16:05 - K11FDSR, - ) Исправность АКНП1 на БАЗ1
#define idA0EE01LS1	 35	//(fds16:05 - K11FDSR, - ) Исправность АКНП1 на БАЗ1
#define R0VN03RS1	 BUFFER[106]	//( - , AKNP1) Измеренный нейтронный поток
#define idR0VN03RS1	 36	//( - , AKNP1) Измеренный нейтронный поток
#define R0VN04RS1	 BUFFER[111]	//( - , AKNP1) Реактивность канал1
#define idR0VN04RS1	 37	//( - , AKNP1) Реактивность канал1
#define A0VN71LS1	 BUFFER[116]	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ на БАЗ1
#define idA0VN71LS1	 38	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ на БАЗ1
#define A0EE02LS1	 BUFFER[118]	//( - , AKNP1) Исправность АКНП1 (от сшивки каналов) канал 1
#define idA0EE02LS1	 39	//( - , AKNP1) Исправность АКНП1 (от сшивки каналов) канал 1
#define R0IE11LS1	 BUFFER[120]	//( - , - ) Исправность ВИП 1,6 (№8) СНМ11 1 канала
#define idR0IE11LS1	 40	//( - , - ) Исправность ВИП 1,6 (№8) СНМ11 1 канала
#define R0IE12LS1	 BUFFER[122]	//( - , - ) Исправность ВИП 0,5 (№9) КНК15-1 1 канала
#define idR0IE12LS1	 41	//( - , - ) Исправность ВИП 0,5 (№9) КНК15-1 1 канала
#define R0IE13LS1	 BUFFER[124]	//( - , - ) Исправность ВИП 0,5 (№10) КНК53М 1 канала
#define idR0IE13LS1	 42	//( - , - ) Исправность ВИП 0,5 (№10) КНК53М 1 канала
#define R0VN13RS1	 BUFFER[126]	//( - , AKNP1) Нейтронный поток по камере СНМ11
#define idR0VN13RS1	 43	//( - , AKNP1) Нейтронный поток по камере СНМ11
#define R0VN23RS1	 BUFFER[131]	//( - , AKNP1) Нейтронный поток по камере КНК15-1
#define idR0VN23RS1	 44	//( - , AKNP1) Нейтронный поток по камере КНК15-1
#define R0VN33RS1	 BUFFER[136]	//( - , AKNP1) Нейтронный поток по камере КНК53М
#define idR0VN33RS1	 45	//( - , AKNP1) Нейтронный поток по камере КНК53М
#define R0VN15RS1	 BUFFER[141]	//( - , AKNP1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
#define idR0VN15RS1	 46	//( - , AKNP1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
#define R0IE01LS1	 BUFFER[144]	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов 1 канала
#define idR0IE01LS1	 47	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов 1 канала
#define R0IE02LS1	 BUFFER[146]	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ 1 канала
#define idR0IE02LS1	 48	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ 1 канала
#define R0VN71LZ2	 BUFFER[148]	//(fds16:05 - K13FDSR, - ) АС по мощности на БАЗ2
#define idR0VN71LZ2	 49	//(fds16:05 - K13FDSR, - ) АС по мощности на БАЗ2
#define R0VN75LZ2	 BUFFER[150]	//(fds16:05 - K14FDSR, - ) АС по периоду разгонана БАЗ2
#define idR0VN75LZ2	 50	//(fds16:05 - K14FDSR, - ) АС по периоду разгонана БАЗ2
#define A1EE01LS1	 BUFFER[152]	//(fds16:05 - K15FDSR, - ) Исправность АКНП1 на БАЗ2
#define idA1EE01LS1	 51	//(fds16:05 - K15FDSR, - ) Исправность АКНП1 на БАЗ2
#define A1VN71LS1	 BUFFER[154]	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ на БАЗ2
#define idA1VN71LS1	 52	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ на БАЗ2
#define B8VC01RDU	 BUFFER[156]	//( - , A1Bz1, A1Bz2) Координата АЗ2, мм
#define idB8VC01RDU	 53	//( - , A1Bz1, A1Bz2) Координата АЗ2, мм
#define R0EE01LZ1	 BUFFER[161]	//( - , AKNP1) Питание  АКНП1  отключить
#define idR0EE01LZ1	 54	//( - , AKNP1) Питание  АКНП1  отключить
#define R0EE01LZ2	 BUFFER[163]	//( - , AKNP1) Питание  АКНП1  отключить
#define idR0EE01LZ2	 55	//( - , AKNP1) Питание  АКНП1  отключить
#define R0DE01LS1	 BUFFER[165]	//(vchs:01 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 1 месте
#define idR0DE01LS1	 56	//(vchs:01 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 1 месте
#define R0DE02LS1	 BUFFER[168]	//(vchs:02 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 2 месте
#define idR0DE02LS1	 57	//(vchs:02 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 2 месте
#define fEM_R0UR01RSS	 BUFFER[171]	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RSS	 58	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R0UL52RSS	 BUFFER[176]	//(R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	 59	//(R0UL52RSS) Уровень АС по мощности
#define fEM_R0UL41RSS	 BUFFER[181]	//(R0UL41RSS) Уровень ПС по периоду разгона
#define idfEM_R0UL41RSS	 60	//(R0UL41RSS) Уровень ПС по периоду разгона
#define fEM_R0UL51RSS	 BUFFER[186]	//(R0UL51RSS) Уровень АС по периоду разгона
#define idfEM_R0UL51RSS	 61	//(R0UL51RSS) Уровень АС по периоду разгона
#define fEM_R0UH02RSS	 BUFFER[191]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define idfEM_R0UH02RSS	 62	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define fEM_R0UH03RSS	 BUFFER[196]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define idfEM_R0UH03RSS	 63	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define fEM_R0UL42RSS	 BUFFER[201]	//(R0UL42RSS) Уровень ПС по мощности
#define idfEM_R0UL42RSS	 64	//(R0UL42RSS) Уровень ПС по мощности
#define fEM_R7UX00RSS	 BUFFER[206]	//(R7UX00RSS) X-координата АЗ1 (см)
#define idfEM_R7UX00RSS	 65	//(R7UX00RSS) X-координата АЗ1 (см)
#define fEM_R7UX01RSS	 BUFFER[211]	//(R7UX01RSS) X-координата камеры R7IN11
#define idfEM_R7UX01RSS	 66	//(R7UX01RSS) X-координата камеры R7IN11
#define fEM_R7UX02RSS	 BUFFER[216]	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define idfEM_R7UX02RSS	 67	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define fEM_R7UX03RSS	 BUFFER[221]	//(R7UX03RSS) X-координата камеры R7IN13 (см)
#define idfEM_R7UX03RSS	 68	//(R7UX03RSS) X-координата камеры R7IN13 (см)
#define fEM_R7UY00RSS	 BUFFER[226]	//(R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	 69	//(R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UY01RSS	 BUFFER[231]	//(R7UY01RSS) Y-координата камеры R7IN11
#define idfEM_R7UY01RSS	 70	//(R7UY01RSS) Y-координата камеры R7IN11
#define fEM_R7UY02RSS	 BUFFER[236]	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define idfEM_R7UY02RSS	 71	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define fEM_R7UY03RSS	 BUFFER[241]	//(R7UY03RSS) Y-координата камеры R7IN13 (см)
#define idfEM_R7UY03RSS	 72	//(R7UY03RSS) Y-координата камеры R7IN13 (см)
#define fEM_A0UX00RSS	 BUFFER[246]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 73	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX01RSS	 BUFFER[251]	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define idfEM_A0UX01RSS	 74	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define fEM_A0UX02RSS	 BUFFER[256]	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define idfEM_A0UX02RSS	 75	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define fEM_A0UX03RSS	 BUFFER[261]	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define idfEM_A0UX03RSS	 76	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define fEM_B0UX01RSS	 BUFFER[266]	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define idfEM_B0UX01RSS	 77	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define fEM_B0UX02RSS	 BUFFER[271]	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define idfEM_B0UX02RSS	 78	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define fEM_B0UX03RSS	 BUFFER[276]	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	 79	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_R0UH05RSS	 BUFFER[281]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 80	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UN03RSS	 BUFFER[286]	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN03RSS	 81	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R0UL01RSS	 BUFFER[291]	//(R0UL01RSS) Шаг (мс) измерения периода
#define idfEM_R0UL01RSS	 82	//(R0UL01RSS) Шаг (мс) измерения периода
#define fEM_R0UL02RSS	 BUFFER[296]	//(R0UL02RSS) Tф-постоянная времени, с
#define idfEM_R0UL02RSS	 83	//(R0UL02RSS) Tф-постоянная времени, с
#define fEM_R0UH01RSS	 BUFFER[301]	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
#define idfEM_R0UH01RSS	 84	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
#define fEM_R0UH21RSS	 BUFFER[306]	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	 85	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	 BUFFER[311]	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	 86	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	 BUFFER[316]	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	 87	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0IN11FN1	 BUFFER[321]	//(R0IN11FN1) Коэффициент А (А1 к 1)
#define idfEM_R0IN11FN1	 88	//(R0IN11FN1) Коэффициент А (А1 к 1)
#define fEM_R0IN12FN1	 BUFFER[326]	//(R0IN12FN1) Коэффициент B (А1 к 1)
#define idfEM_R0IN12FN1	 89	//(R0IN12FN1) Коэффициент B (А1 к 1)
#define fEM_R0IN21FN1	 BUFFER[331]	//(R0IN21FN1) Коэффициент A (А1 к 2)
#define idfEM_R0IN21FN1	 90	//(R0IN21FN1) Коэффициент A (А1 к 2)
#define fEM_R0IN22FN1	 BUFFER[336]	//(R0IN22FN1) Коэффициент B (А1 к 2)
#define idfEM_R0IN22FN1	 91	//(R0IN22FN1) Коэффициент B (А1 к 2)
#define fEM_R0IN31FN1	 BUFFER[341]	//(R0IN31FN1) Коэффициент A (А1 к 3)
#define idfEM_R0IN31FN1	 92	//(R0IN31FN1) Коэффициент A (А1 к 3)
#define fEM_R0IN32FN1	 BUFFER[346]	//(R0IN32FN1) Коэффициент B (А1 к 3)
#define idfEM_R0IN32FN1	 93	//(R0IN32FN1) Коэффициент B (А1 к 3)
#define bFirstEnterFlag	 BUFFER[351]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 94	//(bFirstEnterFlag) 
#define internal1_m56_y0	 BUFFER[353]	//(internal1_m56_y0) y0 - внутренний параметр
#define idinternal1_m56_y0	 95	//(internal1_m56_y0) y0 - внутренний параметр
#define internal1_m17_Nk	 BUFFER[358]	//(internal1_m17_Nk) Nk - ведущая камера
#define idinternal1_m17_Nk	 96	//(internal1_m17_Nk) Nk - ведущая камера
#define internal1_m55_flst	 BUFFER[361]	//(internal1_m55_flst)  флаг старта измерения
#define idinternal1_m55_flst	 97	//(internal1_m55_flst)  флаг старта измерения
#define internal1_m55_chsr	 BUFFER[364]	//(internal1_m55_chsr)  счетчик усреднения
#define idinternal1_m55_chsr	 98	//(internal1_m55_chsr)  счетчик усреднения
#define internal1_m55_chizm	 BUFFER[367]	//(internal1_m55_chizm)  счетчик уменьшения мощности
#define idinternal1_m55_chizm	 99	//(internal1_m55_chizm)  счетчик уменьшения мощности
#define internal1_m55_sumtim	 BUFFER[370]	//(internal1_m55_sumtim)  время измерения мощности
#define idinternal1_m55_sumtim	 100	//(internal1_m55_sumtim)  время измерения мощности
#define internal1_m55_W1	 BUFFER[375]	//(internal1_m55_W1)  мощность на старте измерения
#define idinternal1_m55_W1	 101	//(internal1_m55_W1)  мощность на старте измерения
#define internal1_m55_W2	 BUFFER[380]	//(internal1_m55_W2)  мощность в конце измерения
#define idinternal1_m55_W2	 102	//(internal1_m55_W2)  мощность в конце измерения
#define internal1_m55_Wmin	 BUFFER[385]	//(internal1_m55_Wmin)  минимальное измерение в серии
#define idinternal1_m55_Wmin	 103	//(internal1_m55_Wmin)  минимальное измерение в серии
#define internal1_m55_Wmax	 BUFFER[390]	//(internal1_m55_Wmax)  максимальное измерение в серии
#define idinternal1_m55_Wmax	 104	//(internal1_m55_Wmax)  максимальное измерение в серии
#define internal1_m55_Wlast	 BUFFER[395]	//(internal1_m55_Wlast)  последнее растущее измерение
#define idinternal1_m55_Wlast	 105	//(internal1_m55_Wlast)  последнее растущее измерение
#define internal1_m55_y0	 BUFFER[400]	//(internal1_m55_y0) y0 - внутренний параметр
#define idinternal1_m55_y0	 106	//(internal1_m55_y0) y0 - внутренний параметр
#define internal1_m55_MyFirstEnterFlag	 BUFFER[405]	//(internal1_m55_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m55_MyFirstEnterFlag	 107	//(internal1_m55_MyFirstEnterFlag)  FirstEnterFlag
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,3	,1	, &R0DE04LS1},	//(vds32:04 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 4 месте
	{ 2	,3	,1	, &R0DE05LS1},	//(fds16:05 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 5 месте
	{ 3	,3	,1	, &TTLa1},	//( - , AKNP1) ttl
	{ 4	,1	,1	, &R0DE31LS1},	//(sbk:20 - S01SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 1
	{ 5	,1	,1	, &R0DE32LS1},	//(sbk:20 - S02SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 2
	{ 6	,1	,1	, &R0DE33LS1},	//(sbk:20 - S03SBK, DiagnAKNP1) диагностика шкафа АКНП1 двери
	{ 7	,1	,1	, &R0DE34LS1},	//(sbk:20 - S04SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура меньше 43
	{ 8	,1	,1	, &R0DE35LS1},	//(sbk:20 - S05SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура больше 53
	{ 9	,1	,1	, &R0DE37LS1},	//(sbk:20 - S07SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3.1 место 2
	{ 10	,1	,1	, &R0DE38LS1},	//(sbk:20 - S08SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3 место 3
	{ 11	,1	,1	, &R0DE39LS1},	//(sbk:20 - S09SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП24-2 место 4
	{ 12	,1	,1	, &R0DE3CLS1},	//( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 7
	{ 13	,1	,1	, &R0DE3DLS1},	//( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 8
	{ 14	,1	,1	, &TestDiagnAKNP1},	//( - , AKNP1) Неисправность от диагностики
	{ 15	,1	,1	, &R0DEB1LS1},	//(sbk:20 - S10SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 7
	{ 16	,1	,1	, &R0DEB2LS1},	//(sbk:20 - S11SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 7
	{ 17	,1	,1	, &R0DEB4LS1},	//(sbk:20 - S13SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 8
	{ 18	,1	,1	, &R0DEB3LS1},	//(sbk:20 - S12SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 8
	{ 19	,8	,1	, &R0IN01FS1},	//( - , AKNP1) Выход СНМ-11 Гц
	{ 20	,8	,1	, &R0IN02FI1},	//( - , MA1S) Выход КНК15-1 Гц от ПТИ
	{ 21	,8	,1	, &R0IN03FS1},	//( - , AKNP1) Выход КНК53М Гц
	{ 22	,1	,1	, &R0IS01FI0},	//( - , MA1S) Признак работы с имитатором
	{ 23	,8	,1	, &R0IN01FI1},	//( - , MA1S) Выход СНМ-11 Гц от ПТИ
	{ 24	,8	,1	, &R0IN02FS1},	//( - , AKNP1) Выход КНК15-1 Гц
	{ 25	,8	,1	, &R0IN03FI1},	//( - , MA1S) Выход КНК53М Гц от ПТИ
	{ 26	,8	,1	, &R0IN01FV1},	//(vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
	{ 27	,8	,1	, &R0IN02FV1},	//(vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
	{ 28	,8	,1	, &R0IN03FV1},	//(vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
	{ 29	,8	,1	, &R0VN02RS1},	//( - , A1Bz1, A1Bz2) Уровень мощности
	{ 30	,8	,1	, &R0VN01RS1},	//( - , A1Bz1, A1Bz2) Период разгона канал1
	{ 31	,1	,1	, &R0VN61LS1},	//( - , A1Bz1, A1Bz2) ПС по мощности канал1
	{ 32	,1	,1	, &R0VN71LZ1},	//(fds16:05 - K09FDSR, - ) АС по мощности на БАЗ1
	{ 33	,1	,1	, &R0VN65LS1},	//( - , A1Bz1, A1Bz2) ПС по периоду разгона канал1
	{ 34	,1	,1	, &R0VN75LZ1},	//(fds16:05 - K10FDSR, - ) АС по периоду разгонана БАЗ1
	{ 35	,1	,1	, &A0EE01LS1},	//(fds16:05 - K11FDSR, - ) Исправность АКНП1 на БАЗ1
	{ 36	,8	,1	, &R0VN03RS1},	//( - , AKNP1) Измеренный нейтронный поток
	{ 37	,8	,1	, &R0VN04RS1},	//( - , AKNP1) Реактивность канал1
	{ 38	,1	,1	, &A0VN71LS1},	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ на БАЗ1
	{ 39	,1	,1	, &A0EE02LS1},	//( - , AKNP1) Исправность АКНП1 (от сшивки каналов) канал 1
	{ 40	,1	,1	, &R0IE11LS1},	//( - , - ) Исправность ВИП 1,6 (№8) СНМ11 1 канала
	{ 41	,1	,1	, &R0IE12LS1},	//( - , - ) Исправность ВИП 0,5 (№9) КНК15-1 1 канала
	{ 42	,1	,1	, &R0IE13LS1},	//( - , - ) Исправность ВИП 0,5 (№10) КНК53М 1 канала
	{ 43	,8	,1	, &R0VN13RS1},	//( - , AKNP1) Нейтронный поток по камере СНМ11
	{ 44	,8	,1	, &R0VN23RS1},	//( - , AKNP1) Нейтронный поток по камере КНК15-1
	{ 45	,8	,1	, &R0VN33RS1},	//( - , AKNP1) Нейтронный поток по камере КНК53М
	{ 46	,3	,1	, &R0VN15RS1},	//( - , AKNP1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
	{ 47	,1	,1	, &R0IE01LS1},	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов 1 канала
	{ 48	,1	,1	, &R0IE02LS1},	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ 1 канала
	{ 49	,1	,1	, &R0VN71LZ2},	//(fds16:05 - K13FDSR, - ) АС по мощности на БАЗ2
	{ 50	,1	,1	, &R0VN75LZ2},	//(fds16:05 - K14FDSR, - ) АС по периоду разгонана БАЗ2
	{ 51	,1	,1	, &A1EE01LS1},	//(fds16:05 - K15FDSR, - ) Исправность АКНП1 на БАЗ2
	{ 52	,1	,1	, &A1VN71LS1},	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ на БАЗ2
	{ 53	,8	,1	, &B8VC01RDU},	//( - , A1Bz1, A1Bz2) Координата АЗ2, мм
	{ 54	,1	,1	, &R0EE01LZ1},	//( - , AKNP1) Питание  АКНП1  отключить
	{ 55	,1	,1	, &R0EE01LZ2},	//( - , AKNP1) Питание  АКНП1  отключить
	{ 56	,3	,1	, &R0DE01LS1},	//(vchs:01 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 1 месте
	{ 57	,3	,1	, &R0DE02LS1},	//(vchs:02 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 2 месте
	{ 58	,8	,1	, &fEM_R0UR01RSS},	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
	{ 59	,8	,1	, &fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{ 60	,8	,1	, &fEM_R0UL41RSS},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{ 61	,8	,1	, &fEM_R0UL51RSS},	//(R0UL51RSS) Уровень АС по периоду разгона
	{ 62	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{ 63	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{ 64	,8	,1	, &fEM_R0UL42RSS},	//(R0UL42RSS) Уровень ПС по мощности
	{ 65	,8	,1	, &fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{ 66	,8	,1	, &fEM_R7UX01RSS},	//(R7UX01RSS) X-координата камеры R7IN11
	{ 67	,8	,1	, &fEM_R7UX02RSS},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{ 68	,8	,1	, &fEM_R7UX03RSS},	//(R7UX03RSS) X-координата камеры R7IN13 (см)
	{ 69	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{ 70	,8	,1	, &fEM_R7UY01RSS},	//(R7UY01RSS) Y-координата камеры R7IN11
	{ 71	,8	,1	, &fEM_R7UY02RSS},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{ 72	,8	,1	, &fEM_R7UY03RSS},	//(R7UY03RSS) Y-координата камеры R7IN13 (см)
	{ 73	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 74	,8	,1	, &fEM_A0UX01RSS},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{ 75	,8	,1	, &fEM_A0UX02RSS},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{ 76	,8	,1	, &fEM_A0UX03RSS},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{ 77	,8	,1	, &fEM_B0UX01RSS},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{ 78	,8	,1	, &fEM_B0UX02RSS},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{ 79	,8	,1	, &fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{ 80	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 81	,8	,1	, &fEM_R0UN03RSS},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 82	,8	,1	, &fEM_R0UL01RSS},	//(R0UL01RSS) Шаг (мс) измерения периода
	{ 83	,8	,1	, &fEM_R0UL02RSS},	//(R0UL02RSS) Tф-постоянная времени, с
	{ 84	,8	,1	, &fEM_R0UH01RSS},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
	{ 85	,8	,1	, &fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{ 86	,8	,1	, &fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{ 87	,8	,1	, &fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{ 88	,8	,1	, &fEM_R0IN11FN1},	//(R0IN11FN1) Коэффициент А (А1 к 1)
	{ 89	,8	,1	, &fEM_R0IN12FN1},	//(R0IN12FN1) Коэффициент B (А1 к 1)
	{ 90	,8	,1	, &fEM_R0IN21FN1},	//(R0IN21FN1) Коэффициент A (А1 к 2)
	{ 91	,8	,1	, &fEM_R0IN22FN1},	//(R0IN22FN1) Коэффициент B (А1 к 2)
	{ 92	,8	,1	, &fEM_R0IN31FN1},	//(R0IN31FN1) Коэффициент A (А1 к 3)
	{ 93	,8	,1	, &fEM_R0IN32FN1},	//(R0IN32FN1) Коэффициент B (А1 к 3)
	{ 94	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 95	,8	,1	, &internal1_m56_y0},	//(internal1_m56_y0) y0 - внутренний параметр
	{ 96	,3	,1	, &internal1_m17_Nk},	//(internal1_m17_Nk) Nk - ведущая камера
	{ 97	,3	,1	, &internal1_m55_flst},	//(internal1_m55_flst)  флаг старта измерения
	{ 98	,3	,1	, &internal1_m55_chsr},	//(internal1_m55_chsr)  счетчик усреднения
	{ 99	,3	,1	, &internal1_m55_chizm},	//(internal1_m55_chizm)  счетчик уменьшения мощности
	{ 100	,8	,1	, &internal1_m55_sumtim},	//(internal1_m55_sumtim)  время измерения мощности
	{ 101	,8	,1	, &internal1_m55_W1},	//(internal1_m55_W1)  мощность на старте измерения
	{ 102	,8	,1	, &internal1_m55_W2},	//(internal1_m55_W2)  мощность в конце измерения
	{ 103	,8	,1	, &internal1_m55_Wmin},	//(internal1_m55_Wmin)  минимальное измерение в серии
	{ 104	,8	,1	, &internal1_m55_Wmax},	//(internal1_m55_Wmax)  максимальное измерение в серии
	{ 105	,8	,1	, &internal1_m55_Wlast},	//(internal1_m55_Wlast)  последнее растущее измерение
	{ 106	,8	,1	, &internal1_m55_y0},	//(internal1_m55_y0) y0 - внутренний параметр
	{ 107	,1	,1	, &internal1_m55_MyFirstEnterFlag},	//(internal1_m55_MyFirstEnterFlag)  FirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="aknp1.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{58,"fEM_R0UR01RSS\0"}, 
{59,"fEM_R0UL52RSS\0"}, 
{60,"fEM_R0UL41RSS\0"}, 
{61,"fEM_R0UL51RSS\0"}, 
{62,"fEM_R0UH02RSS\0"}, 
{63,"fEM_R0UH03RSS\0"}, 
{64,"fEM_R0UL42RSS\0"}, 
{65,"fEM_R7UX00RSS\0"}, 
{66,"fEM_R7UX01RSS\0"}, 
{67,"fEM_R7UX02RSS\0"}, 
{68,"fEM_R7UX03RSS\0"}, 
{69,"fEM_R7UY00RSS\0"}, 
{70,"fEM_R7UY01RSS\0"}, 
{71,"fEM_R7UY02RSS\0"}, 
{72,"fEM_R7UY03RSS\0"}, 
{73,"fEM_A0UX00RSS\0"}, 
{74,"fEM_A0UX01RSS\0"}, 
{75,"fEM_A0UX02RSS\0"}, 
{76,"fEM_A0UX03RSS\0"}, 
{77,"fEM_B0UX01RSS\0"}, 
{78,"fEM_B0UX02RSS\0"}, 
{79,"fEM_B0UX03RSS\0"}, 
{80,"fEM_R0UH05RSS\0"}, 
{81,"fEM_R0UN03RSS\0"}, 
{82,"fEM_R0UL01RSS\0"}, 
{83,"fEM_R0UL02RSS\0"}, 
{84,"fEM_R0UH01RSS\0"}, 
{85,"fEM_R0UH21RSS\0"}, 
{86,"fEM_R0UH22RSS\0"}, 
{87,"fEM_R0UH23RSS\0"}, 
{88,"fEM_R0IN11FN1\0"}, 
{89,"fEM_R0IN12FN1\0"}, 
{90,"fEM_R0IN21FN1\0"}, 
{91,"fEM_R0IN22FN1\0"}, 
{92,"fEM_R0IN31FN1\0"}, 
{93,"fEM_R0IN32FN1\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_AKNP1[]={  // 
	{&R0EE01LZ1,1,0},	//( - , AKNP1) Питание  АКНП1  отключить
	{&R0EE01LZ2,1,1},	//( - , AKNP1) Питание  АКНП1  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_AKNP1[]={  // 
	{&A0EE02LS1,1,0},	//( - , AKNP1) Исправность АКНП1 (от сшивки каналов) канал 1
	{&TestDiagnAKNP1,1,1},	//( - , AKNP1) Неисправность от диагностики
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_AKNP1[]={  // 
	{&R0VN03RS1,8,0},	//( - , AKNP1) Измеренный нейтронный поток
	{&R0VN04RS1,8,2},	//( - , AKNP1) Реактивность канал1
	{&R0VN13RS1,8,4},	//( - , AKNP1) Нейтронный поток по камере СНМ11
	{&R0VN23RS1,8,6},	//( - , AKNP1) Нейтронный поток по камере КНК15-1
	{&R0VN33RS1,8,8},	//( - , AKNP1) Нейтронный поток по камере КНК53М
	{&R0VN15RS1,3,10},	//( - , AKNP1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
	{&TTLa1,3,11},	//( - , AKNP1) ttl
	{&R0IN01FS1,8,12},	//( - , AKNP1) Выход СНМ-11 Гц
	{&R0IN03FS1,8,14},	//( - , AKNP1) Выход КНК53М Гц
	{&R0IN02FS1,8,16},	//( - , AKNP1) Выход КНК15-1 Гц
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_AKNP1[]={  // 
	{&fEM_R0UR01RSS,8,0},	//( - , AKNP1) Уставка АКНП ПС  АЗ по периоду (сек)
	{&fEM_R0UL52RSS,8,2},	//( - , AKNP1) Уровень АС по мощности
	{&fEM_R0UL41RSS,8,4},	//( - , AKNP1) Уровень ПС по периоду разгона
	{&fEM_R0UL51RSS,8,6},	//( - , AKNP1) Уровень АС по периоду разгона
	{&fEM_R0UH02RSS,8,8},	//( - , AKNP1) Коэфф. преобразования частота->нейтр/с КНК15-1
	{&fEM_R0UH03RSS,8,10},	//( - , AKNP1) Коэфф. преобразования частота->нейтр/с КНК53М
	{&fEM_R0UL42RSS,8,12},	//( - , AKNP1) Уровень ПС по мощности
	{&fEM_R7UX00RSS,8,14},	//( - , AKNP1) X-координата АЗ1 (см)
	{&fEM_R7UX01RSS,8,16},	//( - , AKNP1) X-координата камеры R7IN11
	{&fEM_R7UX02RSS,8,18},	//( - , AKNP1) X-координата камеры R7IN12 (см)
	{&fEM_R7UX03RSS,8,20},	//( - , AKNP1) X-координата камеры R7IN13 (см)
	{&fEM_R7UY00RSS,8,22},	//( - , AKNP1) Y-координата АЗ1 (см)
	{&fEM_R7UY01RSS,8,24},	//( - , AKNP1) Y-координата камеры R7IN11
	{&fEM_R7UY02RSS,8,26},	//( - , AKNP1) Y-координата камеры R7IN12 (см)
	{&fEM_R7UY03RSS,8,28},	//( - , AKNP1) Y-координата камеры R7IN13 (см)
	{&fEM_A0UX00RSS,8,30},	//( - , AKNP1) Эффективный радиус АЗ
	{&fEM_A0UX01RSS,8,32},	//( - , AKNP1) Первый коэффициент калибровки камеры 1
	{&fEM_A0UX02RSS,8,34},	//( - , AKNP1) Первый коэффициент калибровки камеры 2
	{&fEM_A0UX03RSS,8,36},	//( - , AKNP1) Первый коэффициент калибровки камеры 3
	{&fEM_B0UX01RSS,8,38},	//( - , AKNP1) Второй коэффициент калибровки камеры 1
	{&fEM_B0UX02RSS,8,40},	//( - , AKNP1) Второй коэффициент калибровки камеры 2
	{&fEM_B0UX03RSS,8,42},	//( - , AKNP1) Второй коэффициент калибровки камеры 3
	{&fEM_R0UH05RSS,8,44},	//( - , AKNP1) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_R0UN03RSS,8,46},	//( - , AKNP1) Нижняя граница интервала мощности для измерения периода (ватт)
	{&fEM_R0UL01RSS,8,48},	//( - , AKNP1) Шаг (мс) измерения периода
	{&fEM_R0UL02RSS,8,50},	//( - , AKNP1) Tф-постоянная времени, с
	{&fEM_R0UH01RSS,8,52},	//( - , AKNP1) Коэфф. преобразования частота->нейтр/с СНМ-11
	{&fEM_R0UH21RSS,8,54},	//( - , AKNP1) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{&fEM_R0UH22RSS,8,56},	//( - , AKNP1) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{&fEM_R0UH23RSS,8,58},	//( - , AKNP1) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{&fEM_R0IN11FN1,8,60},	//( - , AKNP1) Коэффициент А (А1 к 1)
	{&fEM_R0IN12FN1,8,62},	//( - , AKNP1) Коэффициент B (А1 к 1)
	{&fEM_R0IN21FN1,8,64},	//( - , AKNP1) Коэффициент A (А1 к 2)
	{&fEM_R0IN22FN1,8,66},	//( - , AKNP1) Коэффициент B (А1 к 2)
	{&fEM_R0IN31FN1,8,68},	//( - , AKNP1) Коэффициент A (А1 к 3)
	{&fEM_R0IN32FN1,8,70},	//( - , AKNP1) Коэффициент B (А1 к 3)
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_A1Bz1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_A1Bz1[]={  // 
	{&R0VN61LS1,1,0},	//( - , A1Bz1, A1Bz2) ПС по мощности канал1
	{&R0VN65LS1,1,1},	//( - , A1Bz1, A1Bz2) ПС по периоду разгона канал1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_A1Bz1[]={  // 
	{&R0VN02RS1,8,0},	//( - , A1Bz1, A1Bz2) Уровень мощности
	{&R0VN01RS1,8,2},	//( - , A1Bz1, A1Bz2) Период разгона канал1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_A1Bz1[]={  // 
	{&B8VC01RDU,8,0},	//( - , A1Bz1, A1Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_A1Bz2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_A1Bz2[]={  // 
	{&R0VN61LS1,1,0},	//( - , A1Bz1, A1Bz2) ПС по мощности канал1
	{&R0VN65LS1,1,1},	//( - , A1Bz1, A1Bz2) ПС по периоду разгона канал1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_A1Bz2[]={  // 
	{&R0VN02RS1,8,0},	//( - , A1Bz1, A1Bz2) Уровень мощности
	{&R0VN01RS1,8,2},	//( - , A1Bz1, A1Bz2) Период разгона канал1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_A1Bz2[]={  // 
	{&B8VC01RDU,8,0},	//( - , A1Bz1, A1Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_DiagnAKNP1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnAKNP1[]={  // 
	{&R0DEB3LS1,1,0},	//( - S12SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 8
	{&R0DEB4LS1,1,1},	//( - S13SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 8
	{&R0DEB2LS1,1,2},	//( - S11SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 7
	{&R0DEB1LS1,1,3},	//( - S10SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 7
	{&R0DE3DLS1,1,4},	//( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 8
	{&R0DE3CLS1,1,5},	//( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 7
	{&R0DE39LS1,1,6},	//( - S09SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП24-2 место 4
	{&R0DE38LS1,1,7},	//( - S08SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3 место 3
	{&R0DE37LS1,1,8},	//( - S07SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3.1 место 2
	{&R0DE35LS1,1,9},	//( - S05SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура больше 53
	{&R0DE34LS1,1,10},	//( - S04SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура меньше 43
	{&R0DE33LS1,1,11},	//( - S03SBK, DiagnAKNP1) диагностика шкафа АКНП1 двери
	{&R0DE32LS1,1,12},	//( - S02SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 2
	{&R0DE31LS1,1,13},	//( - S01SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DiagnAKNP1[]={  // 
	{&R0DE05LS1,3,0},	//( - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 5 месте
	{&R0DE04LS1,3,1},	//( - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 4 месте
	{&R0DE02LS1,3,2},	//( - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 2 месте
	{&R0DE01LS1,3,3},	//( - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 1 месте
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DiagnAKNP1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MA1S[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MA1S[]={  // 
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MA1S[]={  // 
	{&R0IN01FI1,8,0},	//( - , SA1) Выход СНМ11 Гц от ПТИ
	{&R0IN02FI1,8,2},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI1,8,4},	//( - , SA1) Выход КНК53М Гц от ПТИ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MA1S[]={  // 
	{NULL,0,0},
};
#pragma pop
static char MA1S_ip1[]={"192.168.10.60\0"};
static char MA1S_ip2[]={"192.168.10.60\0"};
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_AKNP1[0],&di_AKNP1[0],&ir_AKNP1[0],&hr_AKNP1[0],NULL,NULL,NULL,0},	 //общий slave AKNP1
	{0,5015,&coil_A1Bz1[0],&di_A1Bz1[0],&ir_A1Bz1[0],&hr_A1Bz1[0],NULL,NULL,NULL,0},	 //slave AKNP1 - Baz1
	{0,5019,&coil_A1Bz2[0],&di_A1Bz2[0],&ir_A1Bz2[0],&hr_A1Bz2[0],NULL,NULL,NULL,0},	 //slave AKNP1 - Baz2
	{0,5003,&coil_DiagnAKNP1[0],&di_DiagnAKNP1[0],&ir_DiagnAKNP1[0],&hr_DiagnAKNP1[0],NULL,NULL,NULL,0},	 //Диагностика АКНП1
	{1,5006,&coil_MA1S[0],&di_MA1S[0],&ir_MA1S[0],&hr_MA1S[0],NULL,MA1S_ip1,MA1S_ip2,100},	 //Мастер AKNP1 в SCM

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
	{&R0DE01LS1,3,10},
	{&R0IN02FV1,8,5},
	{&R0IN01FV1,8,0},
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
	{&R0DE02LS1,3,10},
	{&R0IN03FV1,8,0},
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
	{&R0DE04LS1,3,64},
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
	{&A1EE01LS1,1,28},
	{&R0VN75LZ2,1,26},
	{&R0VN71LZ2,1,24},
	{&R0IE02LS1,1,0},
	{&R0IE01LS1,1,2},
	{&R0DE05LS1,3,38},
	{&A0VN71LS1,1,22},
	{&A0EE01LS1,1,20},
	{&R0VN75LZ1,1,18},
	{&R0VN71LZ1,1,16},
	{&A1VN71LS1,1,30},
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
	{&R0DE38LS1,1,14},
	{&R0DE37LS1,1,12},
	{&R0DE35LS1,1,8},
	{&R0DE34LS1,1,6},
	{&R0DE33LS1,1,4},
	{&R0DE32LS1,1,2},
	{&R0DE31LS1,1,0},
	{&R0DE39LS1,1,16},
	{&R0DEB1LS1,1,18},
	{&R0DEB2LS1,1,20},
	{&R0DEB4LS1,1,24},
	{&R0DEB3LS1,1,22},
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
	setAsFloat(58,5000);
	setAsFloat(59,5100);
	setAsFloat(60,20);
	setAsFloat(61,13.0);
	setAsFloat(62,37037.04 );
	setAsFloat(63,975000.0);
	setAsFloat(64,5000);
	setAsFloat(65,1570.0);
	setAsFloat(66,1585.0);
	setAsFloat(67,1796.0);
	setAsFloat(68,1269.0);
	setAsFloat(69,506.5);
	setAsFloat(70,248.0);
	setAsFloat(71,284.5);
	setAsFloat(72,256.0);
	setAsFloat(73,11.0);
	setAsFloat(74,1.0);
	setAsFloat(75,1.0);
	setAsFloat(76,1.0);
	setAsFloat(77,0);
	setAsFloat(78,0);
	setAsFloat(79,0);
	setAsFloat(80,32000.0);
	setAsFloat(81,0.005);
	setAsFloat(82,0.5);
	setAsFloat(83,2.0);
	setAsFloat(84,20);
	setAsFloat(85,4000);
	setAsFloat(86,100000);
	setAsFloat(87,1000000);
	setAsFloat(88,1);
	setAsFloat(89,0);
	setAsFloat(90,1);
	setAsFloat(91,0);
	setAsFloat(92,1);
	setAsFloat(93,0);
	setAsBool(40,1);
	setAsBool(41,1);
	setAsBool(42,1);
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

uspaint8 InternalBuf[56];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_5_ = {5,0}; /* n - N-размерность массива x */ 
sschar bRM_2_ = {2,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива значений */ 
ssbool lRM_1_ = {1,0}; /*  */ 
ssfloat fRM_1_ = {1,0}; /* k - Kф-коэффициент усиления */ 
ssfloat fRM_3_ = {3,0}; /* tau - Tф-постоянная времени, с */ 

uspaint8 SpaEEPROMBuf[180];

/* Определение переменных */
ssfloat var1;
ssfloat var2;
ssfloat var3;
ssfloat var4;
ssfloat var5;
ssfloat var6;
ssfloat var7;
ssbool var8;
ssbool var9;
ssbool var10;
ssbool var11;
ssbool var12;
ssbool var13;
ssbool var14;
ssint var15;
ssbool var16;
ssbool var17;
ssfloat var18;
ssfloat var19;
ssbool var20;
ssfloat var21;
ssfloat var22;
ssfloat var23;
ssint var24;
ssbool var25;
ssfloat var26;
ssbool var27;
ssbool var28;
ssbool var29;
ssbool var30;
ssbool var31;
ssfloat var32;
ssbool var33;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m71_x_1[5] = {&lRM_1_,&var20,&R0IE13LS1,&R0IE12LS1,&R0IE11LS1};
psbool  array_m98_x_1[5] = {&var10,&var9,&R0DE37LS1,&R0DE38LS1,&R0DE39LS1};
psint  array_m88_x_1[4] = {&R0DE01LS1,&R0DE02LS1,&R0DE04LS1,&R0DE05LS1};

/* Объявление структур */
_S_mod1  S_mod1_56_1 = {&var26,&fRM_1_,&fRM_3_,&var1,&internal1_m56_y0};
_S_pogrvh  S_pogrvh_117_1 = {&R0IN03FV1,&fEM_R0IN31FN1,&fEM_R0IN32FN1,&var2};
_S_pogrvh  S_pogrvh_115_1 = {&R0IN02FV1,&fEM_R0IN21FN1,&fEM_R0IN22FN1,&var3};
_S_pogrvh  S_pogrvh_113_1 = {&R0IN01FV1,&fEM_R0IN11FN1,&fEM_R0IN12FN1,&var4};
_S_ml  S_ml_9_1 = {&R0IN03FI1,&var2,&R0IS01FI0,&var5};
_S_ml  S_ml_8_1 = {&R0IN02FI1,&var3,&R0IS01FI0,&var6};
_S_ml  S_ml_7_1 = {&R0IN01FI1,&var4,&R0IS01FI0,&var7};
_S_noto  S_noto_102_1 = {&var12,&vainSBool};
_S_andn  S_andn_71_1 = {array_m71_x_1,&iRM_5_,&var8};
_S_or2  S_or2_103_1 = {&R0DEB3LS1,&R0DEB4LS1,&var9};
_S_or2  S_or2_96_1 = {&R0DEB1LS1,&R0DEB2LS1,&var10};
_S_orn  S_orn_98_1 = {array_m98_x_1,&iRM_5_,&var11};
_S_or3  S_or3_101_1 = {&var14,&var13,&var11,&var12};
_S_and2  S_and2_89_1 = {&R0DE31LS1,&R0DE32LS1,&var13};
_S_diagndev  S_diagndev_88_1 = {array_m88_x_1,&iRM_4_,&var14,&var15};
_S_and2  S_and2_67_1 = {&var30,&var27,&var16};
_S_and2  S_and2_66_1 = {&var31,&var30,&var17};
_S_ocham  S_ocham_17_1 = {&var7,&var6,&var5,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX01RSS,&fEM_B0UX01RSS,&fEM_A0UX02RSS,&fEM_B0UX02RSS,&fEM_A0UX03RSS,&fEM_B0UX03RSS,&fEM_R7UX01RSS,&fEM_R7UY01RSS,&fEM_R7UX02RSS,&fEM_R7UY02RSS,&fEM_R7UX03RSS,&fEM_R7UY03RSS,&bRM_2_,&fEM_R0UH01RSS,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&fEM_R0UH21RSS,&fEM_R0UH22RSS,&fEM_R0UH23RSS,&var18,&var19,&var20,&var21,&var22,&var23,&var24,&internal1_m17_Nk};
_S_or2  S_or2_76_1 = {&R0EE01LZ1,&R0EE01LZ2,&var25};
_S_period  S_period_55_1 = {&var19,&var8,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var26,&internal1_m55_flst,&internal1_m55_chsr,&internal1_m55_chizm,&internal1_m55_sumtim,&internal1_m55_W1,&internal1_m55_W2,&internal1_m55_Wmin,&internal1_m55_Wmax,&internal1_m55_Wlast,&internal1_m55_y0,&internal1_m55_MyFirstEnterFlag};
_S_bol  S_bol_60_1 = {&fEM_R0UL41RSS,&var1,&var27};
_S_bol  S_bol_42_1 = {&var19,&fEM_R0UL52RSS,&var28};
_S_bol  S_bol_37_1 = {&var19,&fEM_R0UL42RSS,&var29};
_S_bol  S_bol_59_1 = {&var19,&fEM_R0UN03RSS,&var30};
_S_bol  S_bol_58_1 = {&fEM_R0UL51RSS,&var1,&var31};
_S_react  S_react_57_1 = {&var1,&var32};
_S_bol  S_bol_47_1 = {&var19,&fEM_R0UR01RSS,&var33};


void ZeroVar()
{
   var1.f=0.0;
   var2.f=0.0;
   var3.f=0.0;
   var4.f=0.0;
   var5.f=0.0;
   var6.f=0.0;
   var7.f=0.0;
   var8.b=0;
   var9.b=0;
   var10.b=0;
   var11.b=0;
   var12.b=0;
   var13.b=0;
   var14.b=0;
   var15.i=0;
   var16.b=0;
   var17.b=0;
   var18.f=0.0;
   var19.f=0.0;
   var20.b=0;
   var21.f=0.0;
   var22.f=0.0;
   var23.f=0.0;
   var24.i=0;
   var25.b=0;
   var26.f=0.0;
   var27.b=0;
   var28.b=0;
   var29.b=0;
   var30.b=0;
   var31.b=0;
   var32.f=0.0;
   var33.b=0;
   vainSLong.l=0L;
   vainSFloat.f=0.0;
   vainSInt.i=0;
   vainSBool.b=0;
   vainSChar.c=0;

}
void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_76_1);
  diagndev(&S_diagndev_88_1);
  and2(&S_and2_89_1);
  or2(&S_or2_96_1);
  or2(&S_or2_103_1);
  orn(&S_orn_98_1);
  pogrvh(&S_pogrvh_113_1);
  pogrvh(&S_pogrvh_115_1);
  pogrvh(&S_pogrvh_117_1);
  or3(&S_or3_101_1);
  noto(&S_noto_102_1);
  ml(&S_ml_7_1);
  ml(&S_ml_8_1);
  ml(&S_ml_9_1);
  ocham(&S_ocham_17_1);
  andn(&S_andn_71_1);
  bol(&S_bol_47_1);
  bol(&S_bol_59_1);
  bol(&S_bol_37_1);
  bol(&S_bol_42_1);
  period(&S_period_55_1);
  mod1(&S_mod1_56_1);
  react(&S_react_57_1);
  bol(&S_bol_58_1);
  bol(&S_bol_60_1);
  and2(&S_and2_66_1);
  and2(&S_and2_67_1);
  setData(idR0IN02FS1,&var3);
  setData(idR0IN03FS1,&var2);
  setData(idR0IN01FS1,&var4);
  setData(idTestDiagnAKNP1,&var12);
  setData(idR0DE3DLS1,&var9);
  setData(idR0DE3CLS1,&var10);
  setData(idTTLa1,&var15);
  setData(idA1VN71LS1,&var33);
  setData(idA1EE01LS1,&var8);
  setData(idR0VN75LZ2,&var17);
  setData(idR0VN71LZ2,&var28);
  setData(idR0IE02LS1,&var25);
  setData(idR0IE01LS1,&var25);
  setData(idR0VN15RS1,&var24);
  setData(idR0VN33RS1,&var23);
  setData(idR0VN23RS1,&var22);
  setData(idR0VN13RS1,&var21);
  setData(idA0EE02LS1,&var20);
  setData(idA0VN71LS1,&var33);
  setData(idR0VN04RS1,&var32);
  setData(idR0VN03RS1,&var18);
  setData(idA0EE01LS1,&var8);
  setData(idR0VN75LZ1,&var17);
  setData(idR0VN65LS1,&var16);
  setData(idR0VN71LZ1,&var28);
  setData(idR0VN61LS1,&var29);
  setData(idR0VN01RS1,&var1);
  setData(idR0VN02RS1,&var19);

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
