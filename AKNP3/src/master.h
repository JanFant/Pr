#ifndef AKNP3_H
#define AKNP3_H
// Подсистема AKNP3:AKNP3
static char SimulOn=0;
static short CodeSub=5;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt, taktScheme=0, taktSS=0;
#define SIZE_BUFFER 409
static char BUFFER[409];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.53\0", 5432, "192.168.10.153\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0DE04LS3	 BUFFER[0]	//(vds32:04 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 4 месте
#define idR0DE04LS3	 1	//(vds32:04 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 4 месте
#define R0DE05LS3	 BUFFER[3]	//(fds16:05 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 5 месте
#define idR0DE05LS3	 2	//(fds16:05 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 5 месте
#define R0DE31LS3	 BUFFER[6]	//(sbk:20 - S01SBK, DiagnAKNP3) диагностика шкафа АКНП3 сеть 1
#define idR0DE31LS3	 3	//(sbk:20 - S01SBK, DiagnAKNP3) диагностика шкафа АКНП3 сеть 1
#define R0DE32LS3	 BUFFER[8]	//(sbk:20 - S02SBK, DiagnAKNP3) диагностика шкафа АКНП3 сеть 2
#define idR0DE32LS3	 4	//(sbk:20 - S02SBK, DiagnAKNP3) диагностика шкафа АКНП3 сеть 2
#define R0DE33LS3	 BUFFER[10]	//(sbk:20 - S03SBK, DiagnAKNP3) диагностика шкафа АКНП3 двери
#define idR0DE33LS3	 5	//(sbk:20 - S03SBK, DiagnAKNP3) диагностика шкафа АКНП3 двери
#define R0DE34LS3	 BUFFER[12]	//(sbk:20 - S04SBK, DiagnAKNP3) диагностика шкафа АКНП3 температура меньше 43
#define idR0DE34LS3	 6	//(sbk:20 - S04SBK, DiagnAKNP3) диагностика шкафа АКНП3 температура меньше 43
#define R0DE35LS3	 BUFFER[14]	//(sbk:20 - S05SBK, DiagnAKNP3) диагностика шкафа АКНП3 температура больше 53
#define idR0DE35LS3	 7	//(sbk:20 - S05SBK, DiagnAKNP3) диагностика шкафа АКНП3 температура больше 53
#define R0DE36LS3	 BUFFER[16]	//(sbk:20 - S06SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3.1 место 1
#define idR0DE36LS3	 8	//(sbk:20 - S06SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3.1 место 1
#define R0DE37LS3	 BUFFER[18]	//(sbk:20 - S07SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3.1 место 2
#define idR0DE37LS3	 9	//(sbk:20 - S07SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3.1 место 2
#define R0DE38LS3	 BUFFER[20]	//(sbk:20 - S08SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3 место 3
#define idR0DE38LS3	 10	//(sbk:20 - S08SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3 место 3
#define R0DE39LS3	 BUFFER[22]	//(sbk:20 - S09SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП24-2 место 4
#define idR0DE39LS3	 11	//(sbk:20 - S09SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП24-2 место 4
#define R0DE3CLS3	 BUFFER[24]	//( - , DiagnAKNP3) диагностика шкафа АКНП3 БП5/24Д место 7
#define idR0DE3CLS3	 12	//( - , DiagnAKNP3) диагностика шкафа АКНП3 БП5/24Д место 7
#define R0DE3DLS3	 BUFFER[26]	//( - , DiagnAKNP3) диагностика шкафа АКНП3 БП5/24Д место 8
#define idR0DE3DLS3	 13	//( - , DiagnAKNP3) диагностика шкафа АКНП3 БП5/24Д место 8
#define TTLaknp3	 BUFFER[28]	//( - , AKNP3) ttl
#define idTTLaknp3	 14	//( - , AKNP3) ttl
#define TestDiagnAKNP3	 BUFFER[31]	//( - , AKNP3) Неисправность от диагностики
#define idTestDiagnAKNP3	 15	//( - , AKNP3) Неисправность от диагностики
#define R0DEB1LS3	 BUFFER[33]	//(sbk:20 - S10SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП5 место 7
#define idR0DEB1LS3	 16	//(sbk:20 - S10SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП5 место 7
#define R0DEB2LS3	 BUFFER[35]	//(sbk:20 - S11SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП24Д место 7
#define idR0DEB2LS3	 17	//(sbk:20 - S11SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП24Д место 7
#define R0DEB3LS3	 BUFFER[37]	//(sbk:20 - S12SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП5 место 8
#define idR0DEB3LS3	 18	//(sbk:20 - S12SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП5 место 8
#define R0DEB4LS3	 BUFFER[39]	//(sbk:20 - S13SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП24Д место 8
#define idR0DEB4LS3	 19	//(sbk:20 - S13SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП24Д место 8
#define R0IN01FS3	 BUFFER[41]	//( - , AKNP3) Выход СНМ-11 Гц
#define idR0IN01FS3	 20	//( - , AKNP3) Выход СНМ-11 Гц
#define R0IN02FI3	 BUFFER[46]	//( - , MA3S) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI3	 21	//( - , MA3S) Выход КНК15-1 Гц от ПТИ
#define R0IN03FS3	 BUFFER[51]	//( - , - ) Выход КНК53М Гц
#define idR0IN03FS3	 22	//( - , - ) Выход КНК53М Гц
#define R0IS01FI0	 BUFFER[56]	//( - , MA3S) Признак работы с имитатором
#define idR0IS01FI0	 23	//( - , MA3S) Признак работы с имитатором
#define R0IN01FI3	 BUFFER[58]	//( - , MA3S) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI3	 24	//( - , MA3S) Выход СНМ-11 Гц от ПТИ
#define R0IN02FS3	 BUFFER[63]	//( - , AKNP3) Выход КНК15-1 Гц
#define idR0IN02FS3	 25	//( - , AKNP3) Выход КНК15-1 Гц
#define R0IN03FI3	 BUFFER[68]	//( - , MA3S) Выход КНК53М Гц от ПТИ
#define idR0IN03FI3	 26	//( - , MA3S) Выход КНК53М Гц от ПТИ
#define R0IN01FV3	 BUFFER[73]	//(vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
#define idR0IN01FV3	 27	//(vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
#define R0IN02FV3	 BUFFER[78]	//(vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
#define idR0IN02FV3	 28	//(vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
#define R0IN03FV3	 BUFFER[83]	//(vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
#define idR0IN03FV3	 29	//(vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
#define R0VN02RS3	 BUFFER[88]	//( - , A3Bz1, A3Bz2) Уровень мощности канал 3
#define idR0VN02RS3	 30	//( - , A3Bz1, A3Bz2) Уровень мощности канал 3
#define R0VN01RS3	 BUFFER[93]	//( - , A3Bz1, A3Bz2) Период разгона канал 3
#define idR0VN01RS3	 31	//( - , A3Bz1, A3Bz2) Период разгона канал 3
#define R0VN61LS3	 BUFFER[98]	//( - , A3Bz1, A3Bz2) ПС по мощности канал 3
#define idR0VN61LS3	 32	//( - , A3Bz1, A3Bz2) ПС по мощности канал 3
#define R0VN73LZ1	 BUFFER[100]	//(fds16:05 - K09FDSR, - ) АС по мощности канал 3 на БАЗ1
#define idR0VN73LZ1	 33	//(fds16:05 - K09FDSR, - ) АС по мощности канал 3 на БАЗ1
#define R0VN65LS3	 BUFFER[102]	//( - , A3Bz1, A3Bz2) ПС по периоду разгона канал 3
#define idR0VN65LS3	 34	//( - , A3Bz1, A3Bz2) ПС по периоду разгона канал 3
#define R0VN77LZ1	 BUFFER[104]	//(fds16:05 - K10FDSR, - ) АС по периоду разгона канал 3 на БАЗ1
#define idR0VN77LZ1	 35	//(fds16:05 - K10FDSR, - ) АС по периоду разгона канал 3 на БАЗ1
#define A0EE01LS3	 BUFFER[106]	//(fds16:05 - K11FDSR, - ) Исправность АКНП канал 3 на БАЗ1
#define idA0EE01LS3	 36	//(fds16:05 - K11FDSR, - ) Исправность АКНП канал 3 на БАЗ1
#define R0VN03RS3	 BUFFER[108]	//( - , AKNP3) Измеренный нейтронный поток канал 3
#define idR0VN03RS3	 37	//( - , AKNP3) Измеренный нейтронный поток канал 3
#define R0VN04RS3	 BUFFER[113]	//( - , AKNP3) Реактивность канал 3
#define idR0VN04RS3	 38	//( - , AKNP3) Реактивность канал 3
#define A1VN71LS3	 BUFFER[118]	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
#define idA1VN71LS3	 39	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
#define A0EE02LS3	 BUFFER[120]	//( - , AKNP3) Исправность АКНП3 (от сшивки каналов) канал 3
#define idA0EE02LS3	 40	//( - , AKNP3) Исправность АКНП3 (от сшивки каналов) канал 3
#define R0IE11LS3	 BUFFER[122]	//( - , - ) Исправность ВИП 1,6 (№14) СНМ11 3 канала
#define idR0IE11LS3	 41	//( - , - ) Исправность ВИП 1,6 (№14) СНМ11 3 канала
#define R0IE12LS3	 BUFFER[124]	//( - , - ) Исправность ВИП 0,5 (№15) КНК15-1 3 канала
#define idR0IE12LS3	 42	//( - , - ) Исправность ВИП 0,5 (№15) КНК15-1 3 канала
#define R0IE13LS3	 BUFFER[126]	//( - , - ) Исправность ВИП 0,5 (№16) КНК53М 3 канала
#define idR0IE13LS3	 43	//( - , - ) Исправность ВИП 0,5 (№16) КНК53М 3 канала
#define R0VN13RS3	 BUFFER[128]	//( - , AKNP3) Нейтронный поток по камере СНМ11 канал 3
#define idR0VN13RS3	 44	//( - , AKNP3) Нейтронный поток по камере СНМ11 канал 3
#define R0VN23RS3	 BUFFER[133]	//( - , AKNP3) Нейтронный поток по камере КНК15-1 канал 3
#define idR0VN23RS3	 45	//( - , AKNP3) Нейтронный поток по камере КНК15-1 канал 3
#define R0VN33RS3	 BUFFER[138]	//( - , AKNP3) Нейтронный поток по камере КНК53М канал 3
#define idR0VN33RS3	 46	//( - , AKNP3) Нейтронный поток по камере КНК53М канал 3
#define R0VN15RS3	 BUFFER[143]	//( - , AKNP3) Номер ведущей камеры канал 3
#define idR0VN15RS3	 47	//( - , AKNP3) Номер ведущей камеры канал 3
#define R0IE01LS3	 BUFFER[146]	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 3
#define idR0IE01LS3	 48	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 3
#define R0IE02LS3	 BUFFER[148]	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 3
#define idR0IE02LS3	 49	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 3
#define A0VN71LS3	 BUFFER[150]	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
#define idA0VN71LS3	 50	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
#define R0VN73LZ2	 BUFFER[152]	//(fds16:05 - K13FDSR, - ) АС по мощности канал 3 на БАЗ2
#define idR0VN73LZ2	 51	//(fds16:05 - K13FDSR, - ) АС по мощности канал 3 на БАЗ2
#define R0VN77LZ2	 BUFFER[154]	//(fds16:05 - K14FDSR, - ) АС по периоду разгона канал 3 на БАЗ2
#define idR0VN77LZ2	 52	//(fds16:05 - K14FDSR, - ) АС по периоду разгона канал 3 на БАЗ2
#define A1EE01LS3	 BUFFER[156]	//(fds16:05 - K15FDSR, - ) Исправность АКНП канал 3 на БАЗ2
#define idA1EE01LS3	 53	//(fds16:05 - K15FDSR, - ) Исправность АКНП канал 3 на БАЗ2
#define B8VC01RDU	 BUFFER[158]	//( - , A3Bz1, A3Bz2) Координата АЗ2, мм
#define idB8VC01RDU	 54	//( - , A3Bz1, A3Bz2) Координата АЗ2, мм
#define R0EE03LZ1	 BUFFER[163]	//( - , AKNP3) Питание  АКНП3  отключить
#define idR0EE03LZ1	 55	//( - , AKNP3) Питание  АКНП3  отключить
#define R0EE03LZ2	 BUFFER[165]	//( - , AKNP3) Питание  АКНП3  отключить
#define idR0EE03LZ2	 56	//( - , AKNP3) Питание  АКНП3  отключить
#define R0DE01LS3	 BUFFER[167]	//(vchs:01 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 1 месте
#define idR0DE01LS3	 57	//(vchs:01 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 1 месте
#define R0DE02LS3	 BUFFER[170]	//(vchs:02 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 2 месте
#define idR0DE02LS3	 58	//(vchs:02 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 2 месте
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
#define fEM_R7UX07RSS	 BUFFER[213]	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define idfEM_R7UX07RSS	 67	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define fEM_R7UX08RSS	 BUFFER[218]	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define idfEM_R7UX08RSS	 68	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define fEM_R7UX09RSS	 BUFFER[223]	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define idfEM_R7UX09RSS	 69	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define fEM_R7UY00RSS	 BUFFER[228]	//(R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	 70	//(R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UY07RSS	 BUFFER[233]	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define idfEM_R7UY07RSS	 71	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define fEM_R7UY08RSS	 BUFFER[238]	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define idfEM_R7UY08RSS	 72	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define fEM_R7UY09RSS	 BUFFER[243]	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define idfEM_R7UY09RSS	 73	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define fEM_A0UX00RSS	 BUFFER[248]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 74	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX07RSS	 BUFFER[253]	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define idfEM_A0UX07RSS	 75	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define fEM_A0UX08RSS	 BUFFER[258]	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define idfEM_A0UX08RSS	 76	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define fEM_A0UX09RSS	 BUFFER[263]	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define idfEM_A0UX09RSS	 77	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define fEM_B0UX07RSS	 BUFFER[268]	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define idfEM_B0UX07RSS	 78	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define fEM_B0UX08RSS	 BUFFER[273]	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define idfEM_B0UX08RSS	 79	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define fEM_B0UX09RSS	 BUFFER[278]	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define idfEM_B0UX09RSS	 80	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
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
#define fEM_R0UL01RSS	 BUFFER[318]	//(R0UL01RSS) Шаг (мс) измерения периода
#define idfEM_R0UL01RSS	 88	//(R0UL01RSS) Шаг (мс) измерения периода
#define fEM_R0IN11FN3	 BUFFER[323]	//(R0IN11FN3) Коэффициент A (А3 к 1)
#define idfEM_R0IN11FN3	 89	//(R0IN11FN3) Коэффициент A (А3 к 1)
#define fEM_R0IN12FN3	 BUFFER[328]	//(R0IN12FN3) Коэффициент B (А3 к 1)
#define idfEM_R0IN12FN3	 90	//(R0IN12FN3) Коэффициент B (А3 к 1)
#define fEM_R0IN21FN3	 BUFFER[333]	//(R0IN21FN3) Коэффициент A (А3 к 2)
#define idfEM_R0IN21FN3	 91	//(R0IN21FN3) Коэффициент A (А3 к 2)
#define fEM_R0IN22FN3	 BUFFER[338]	//(R0IN22FN3) Коэффициент B (А3 к 2)
#define idfEM_R0IN22FN3	 92	//(R0IN22FN3) Коэффициент B (А3 к 2)
#define fEM_R0IN31FN3	 BUFFER[343]	//(R0IN31FN3) Коэффициент A (А3 к 3)
#define idfEM_R0IN31FN3	 93	//(R0IN31FN3) Коэффициент A (А3 к 3)
#define fEM_R0IN32FN3	 BUFFER[348]	//(R0IN32FN3) Коэффициент B (А3 к 3)
#define idfEM_R0IN32FN3	 94	//(R0IN32FN3) Коэффициент B (А3 к 3)
#define bFirstEnterFlag	 BUFFER[353]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 95	//(bFirstEnterFlag) 
#define internal1_m56_y0	 BUFFER[355]	//(internal1_m56_y0) y0 - внутренний параметр
#define idinternal1_m56_y0	 96	//(internal1_m56_y0) y0 - внутренний параметр
#define internal1_m19_Nk	 BUFFER[360]	//(internal1_m19_Nk) Nk - ведущая камера
#define idinternal1_m19_Nk	 97	//(internal1_m19_Nk) Nk - ведущая камера
#define internal1_m55_flst	 BUFFER[363]	//(internal1_m55_flst)  флаг старта измерения
#define idinternal1_m55_flst	 98	//(internal1_m55_flst)  флаг старта измерения
#define internal1_m55_chsr	 BUFFER[366]	//(internal1_m55_chsr)  счетчик усреднения
#define idinternal1_m55_chsr	 99	//(internal1_m55_chsr)  счетчик усреднения
#define internal1_m55_chizm	 BUFFER[369]	//(internal1_m55_chizm)  счетчик уменьшения мощности
#define idinternal1_m55_chizm	 100	//(internal1_m55_chizm)  счетчик уменьшения мощности
#define internal1_m55_sumtim	 BUFFER[372]	//(internal1_m55_sumtim)  время измерения мощности
#define idinternal1_m55_sumtim	 101	//(internal1_m55_sumtim)  время измерения мощности
#define internal1_m55_W1	 BUFFER[377]	//(internal1_m55_W1)  мощность на старте измерения
#define idinternal1_m55_W1	 102	//(internal1_m55_W1)  мощность на старте измерения
#define internal1_m55_W2	 BUFFER[382]	//(internal1_m55_W2)  мощность в конце измерения
#define idinternal1_m55_W2	 103	//(internal1_m55_W2)  мощность в конце измерения
#define internal1_m55_Wmin	 BUFFER[387]	//(internal1_m55_Wmin)  минимальное измерение в серии
#define idinternal1_m55_Wmin	 104	//(internal1_m55_Wmin)  минимальное измерение в серии
#define internal1_m55_Wmax	 BUFFER[392]	//(internal1_m55_Wmax)  максимальное измерение в серии
#define idinternal1_m55_Wmax	 105	//(internal1_m55_Wmax)  максимальное измерение в серии
#define internal1_m55_Wlast	 BUFFER[397]	//(internal1_m55_Wlast)  последнее растущее измерение
#define idinternal1_m55_Wlast	 106	//(internal1_m55_Wlast)  последнее растущее измерение
#define internal1_m55_y0	 BUFFER[402]	//(internal1_m55_y0) y0 - внутренний параметр
#define idinternal1_m55_y0	 107	//(internal1_m55_y0) y0 - внутренний параметр
#define internal1_m55_MyFirstEnterFlag	 BUFFER[407]	//(internal1_m55_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m55_MyFirstEnterFlag	 108	//(internal1_m55_MyFirstEnterFlag)  FirstEnterFlag
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,3	,1	, &R0DE04LS3},	//(vds32:04 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 4 месте
	{ 2	,3	,1	, &R0DE05LS3},	//(fds16:05 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 5 месте
	{ 3	,1	,1	, &R0DE31LS3},	//(sbk:20 - S01SBK, DiagnAKNP3) диагностика шкафа АКНП3 сеть 1
	{ 4	,1	,1	, &R0DE32LS3},	//(sbk:20 - S02SBK, DiagnAKNP3) диагностика шкафа АКНП3 сеть 2
	{ 5	,1	,1	, &R0DE33LS3},	//(sbk:20 - S03SBK, DiagnAKNP3) диагностика шкафа АКНП3 двери
	{ 6	,1	,1	, &R0DE34LS3},	//(sbk:20 - S04SBK, DiagnAKNP3) диагностика шкафа АКНП3 температура меньше 43
	{ 7	,1	,1	, &R0DE35LS3},	//(sbk:20 - S05SBK, DiagnAKNP3) диагностика шкафа АКНП3 температура больше 53
	{ 8	,1	,1	, &R0DE36LS3},	//(sbk:20 - S06SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3.1 место 1
	{ 9	,1	,1	, &R0DE37LS3},	//(sbk:20 - S07SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3.1 место 2
	{ 10	,1	,1	, &R0DE38LS3},	//(sbk:20 - S08SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3 место 3
	{ 11	,1	,1	, &R0DE39LS3},	//(sbk:20 - S09SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП24-2 место 4
	{ 12	,1	,1	, &R0DE3CLS3},	//( - , DiagnAKNP3) диагностика шкафа АКНП3 БП5/24Д место 7
	{ 13	,1	,1	, &R0DE3DLS3},	//( - , DiagnAKNP3) диагностика шкафа АКНП3 БП5/24Д место 8
	{ 14	,3	,1	, &TTLaknp3},	//( - , AKNP3) ttl
	{ 15	,1	,1	, &TestDiagnAKNP3},	//( - , AKNP3) Неисправность от диагностики
	{ 16	,1	,1	, &R0DEB1LS3},	//(sbk:20 - S10SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП5 место 7
	{ 17	,1	,1	, &R0DEB2LS3},	//(sbk:20 - S11SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП24Д место 7
	{ 18	,1	,1	, &R0DEB3LS3},	//(sbk:20 - S12SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП5 место 8
	{ 19	,1	,1	, &R0DEB4LS3},	//(sbk:20 - S13SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП24Д место 8
	{ 20	,8	,1	, &R0IN01FS3},	//( - , AKNP3) Выход СНМ-11 Гц
	{ 21	,8	,1	, &R0IN02FI3},	//( - , MA3S) Выход КНК15-1 Гц от ПТИ
	{ 22	,8	,1	, &R0IN03FS3},	//( - , - ) Выход КНК53М Гц
	{ 23	,1	,1	, &R0IS01FI0},	//( - , MA3S) Признак работы с имитатором
	{ 24	,8	,1	, &R0IN01FI3},	//( - , MA3S) Выход СНМ-11 Гц от ПТИ
	{ 25	,8	,1	, &R0IN02FS3},	//( - , AKNP3) Выход КНК15-1 Гц
	{ 26	,8	,1	, &R0IN03FI3},	//( - , MA3S) Выход КНК53М Гц от ПТИ
	{ 27	,8	,1	, &R0IN01FV3},	//(vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
	{ 28	,8	,1	, &R0IN02FV3},	//(vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
	{ 29	,8	,1	, &R0IN03FV3},	//(vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
	{ 30	,8	,1	, &R0VN02RS3},	//( - , A3Bz1, A3Bz2) Уровень мощности канал 3
	{ 31	,8	,1	, &R0VN01RS3},	//( - , A3Bz1, A3Bz2) Период разгона канал 3
	{ 32	,1	,1	, &R0VN61LS3},	//( - , A3Bz1, A3Bz2) ПС по мощности канал 3
	{ 33	,1	,1	, &R0VN73LZ1},	//(fds16:05 - K09FDSR, - ) АС по мощности канал 3 на БАЗ1
	{ 34	,1	,1	, &R0VN65LS3},	//( - , A3Bz1, A3Bz2) ПС по периоду разгона канал 3
	{ 35	,1	,1	, &R0VN77LZ1},	//(fds16:05 - K10FDSR, - ) АС по периоду разгона канал 3 на БАЗ1
	{ 36	,1	,1	, &A0EE01LS3},	//(fds16:05 - K11FDSR, - ) Исправность АКНП канал 3 на БАЗ1
	{ 37	,8	,1	, &R0VN03RS3},	//( - , AKNP3) Измеренный нейтронный поток канал 3
	{ 38	,8	,1	, &R0VN04RS3},	//( - , AKNP3) Реактивность канал 3
	{ 39	,1	,1	, &A1VN71LS3},	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
	{ 40	,1	,1	, &A0EE02LS3},	//( - , AKNP3) Исправность АКНП3 (от сшивки каналов) канал 3
	{ 41	,1	,1	, &R0IE11LS3},	//( - , - ) Исправность ВИП 1,6 (№14) СНМ11 3 канала
	{ 42	,1	,1	, &R0IE12LS3},	//( - , - ) Исправность ВИП 0,5 (№15) КНК15-1 3 канала
	{ 43	,1	,1	, &R0IE13LS3},	//( - , - ) Исправность ВИП 0,5 (№16) КНК53М 3 канала
	{ 44	,8	,1	, &R0VN13RS3},	//( - , AKNP3) Нейтронный поток по камере СНМ11 канал 3
	{ 45	,8	,1	, &R0VN23RS3},	//( - , AKNP3) Нейтронный поток по камере КНК15-1 канал 3
	{ 46	,8	,1	, &R0VN33RS3},	//( - , AKNP3) Нейтронный поток по камере КНК53М канал 3
	{ 47	,3	,1	, &R0VN15RS3},	//( - , AKNP3) Номер ведущей камеры канал 3
	{ 48	,1	,1	, &R0IE01LS3},	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 3
	{ 49	,1	,1	, &R0IE02LS3},	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 3
	{ 50	,1	,1	, &A0VN71LS3},	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
	{ 51	,1	,1	, &R0VN73LZ2},	//(fds16:05 - K13FDSR, - ) АС по мощности канал 3 на БАЗ2
	{ 52	,1	,1	, &R0VN77LZ2},	//(fds16:05 - K14FDSR, - ) АС по периоду разгона канал 3 на БАЗ2
	{ 53	,1	,1	, &A1EE01LS3},	//(fds16:05 - K15FDSR, - ) Исправность АКНП канал 3 на БАЗ2
	{ 54	,8	,1	, &B8VC01RDU},	//( - , A3Bz1, A3Bz2) Координата АЗ2, мм
	{ 55	,1	,1	, &R0EE03LZ1},	//( - , AKNP3) Питание  АКНП3  отключить
	{ 56	,1	,1	, &R0EE03LZ2},	//( - , AKNP3) Питание  АКНП3  отключить
	{ 57	,3	,1	, &R0DE01LS3},	//(vchs:01 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 1 месте
	{ 58	,3	,1	, &R0DE02LS3},	//(vchs:02 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 2 месте
	{ 59	,8	,1	, &fEM_R0UR01RSS},	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
	{ 60	,8	,1	, &fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{ 61	,8	,1	, &fEM_R0UL41RSS},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{ 62	,8	,1	, &fEM_R0UL51RSS},	//(R0UL51RSS) Уровень АС по периоду разгона
	{ 63	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{ 64	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{ 65	,8	,1	, &fEM_R0UL42RSS},	//(R0UL42RSS) Уровень ПС по мощности
	{ 66	,8	,1	, &fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{ 67	,8	,1	, &fEM_R7UX07RSS},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{ 68	,8	,1	, &fEM_R7UX08RSS},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{ 69	,8	,1	, &fEM_R7UX09RSS},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{ 70	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{ 71	,8	,1	, &fEM_R7UY07RSS},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{ 72	,8	,1	, &fEM_R7UY08RSS},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{ 73	,8	,1	, &fEM_R7UY09RSS},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{ 74	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 75	,8	,1	, &fEM_A0UX07RSS},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{ 76	,8	,1	, &fEM_A0UX08RSS},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{ 77	,8	,1	, &fEM_A0UX09RSS},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{ 78	,8	,1	, &fEM_B0UX07RSS},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{ 79	,8	,1	, &fEM_B0UX08RSS},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{ 80	,8	,1	, &fEM_B0UX09RSS},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{ 81	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 82	,8	,1	, &fEM_R0UN03RSS},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 83	,8	,1	, &fEM_R0UH01RSS},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
	{ 84	,8	,1	, &fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{ 85	,8	,1	, &fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{ 86	,8	,1	, &fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{ 87	,8	,1	, &fEM_R0UL02RSS},	//(R0UL02RSS) Tф-постоянная времени, с
	{ 88	,8	,1	, &fEM_R0UL01RSS},	//(R0UL01RSS) Шаг (мс) измерения периода
	{ 89	,8	,1	, &fEM_R0IN11FN3},	//(R0IN11FN3) Коэффициент A (А3 к 1)
	{ 90	,8	,1	, &fEM_R0IN12FN3},	//(R0IN12FN3) Коэффициент B (А3 к 1)
	{ 91	,8	,1	, &fEM_R0IN21FN3},	//(R0IN21FN3) Коэффициент A (А3 к 2)
	{ 92	,8	,1	, &fEM_R0IN22FN3},	//(R0IN22FN3) Коэффициент B (А3 к 2)
	{ 93	,8	,1	, &fEM_R0IN31FN3},	//(R0IN31FN3) Коэффициент A (А3 к 3)
	{ 94	,8	,1	, &fEM_R0IN32FN3},	//(R0IN32FN3) Коэффициент B (А3 к 3)
	{ 95	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 96	,8	,1	, &internal1_m56_y0},	//(internal1_m56_y0) y0 - внутренний параметр
	{ 97	,3	,1	, &internal1_m19_Nk},	//(internal1_m19_Nk) Nk - ведущая камера
	{ 98	,3	,1	, &internal1_m55_flst},	//(internal1_m55_flst)  флаг старта измерения
	{ 99	,3	,1	, &internal1_m55_chsr},	//(internal1_m55_chsr)  счетчик усреднения
	{ 100	,3	,1	, &internal1_m55_chizm},	//(internal1_m55_chizm)  счетчик уменьшения мощности
	{ 101	,8	,1	, &internal1_m55_sumtim},	//(internal1_m55_sumtim)  время измерения мощности
	{ 102	,8	,1	, &internal1_m55_W1},	//(internal1_m55_W1)  мощность на старте измерения
	{ 103	,8	,1	, &internal1_m55_W2},	//(internal1_m55_W2)  мощность в конце измерения
	{ 104	,8	,1	, &internal1_m55_Wmin},	//(internal1_m55_Wmin)  минимальное измерение в серии
	{ 105	,8	,1	, &internal1_m55_Wmax},	//(internal1_m55_Wmax)  максимальное измерение в серии
	{ 106	,8	,1	, &internal1_m55_Wlast},	//(internal1_m55_Wlast)  последнее растущее измерение
	{ 107	,8	,1	, &internal1_m55_y0},	//(internal1_m55_y0) y0 - внутренний параметр
	{ 108	,1	,1	, &internal1_m55_MyFirstEnterFlag},	//(internal1_m55_MyFirstEnterFlag)  FirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="aknp3.bin\0";   // Имя файла для сохранения констант
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
{67,"fEM_R7UX07RSS\0"}, 
{68,"fEM_R7UX08RSS\0"}, 
{69,"fEM_R7UX09RSS\0"}, 
{70,"fEM_R7UY00RSS\0"}, 
{71,"fEM_R7UY07RSS\0"}, 
{72,"fEM_R7UY08RSS\0"}, 
{73,"fEM_R7UY09RSS\0"}, 
{74,"fEM_A0UX00RSS\0"}, 
{75,"fEM_A0UX07RSS\0"}, 
{76,"fEM_A0UX08RSS\0"}, 
{77,"fEM_A0UX09RSS\0"}, 
{78,"fEM_B0UX07RSS\0"}, 
{79,"fEM_B0UX08RSS\0"}, 
{80,"fEM_B0UX09RSS\0"}, 
{81,"fEM_R0UH05RSS\0"}, 
{82,"fEM_R0UN03RSS\0"}, 
{83,"fEM_R0UH01RSS\0"}, 
{84,"fEM_R0UH21RSS\0"}, 
{85,"fEM_R0UH22RSS\0"}, 
{86,"fEM_R0UH23RSS\0"}, 
{87,"fEM_R0UL02RSS\0"}, 
{88,"fEM_R0UL01RSS\0"}, 
{89,"fEM_R0IN11FN3\0"}, 
{90,"fEM_R0IN12FN3\0"}, 
{91,"fEM_R0IN21FN3\0"}, 
{92,"fEM_R0IN22FN3\0"}, 
{93,"fEM_R0IN31FN3\0"}, 
{94,"fEM_R0IN32FN3\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_AKNP3[]={  // 
	{&R0EE03LZ1,1,0},	//( - , AKNP3) Питание  АКНП3  отключить
	{&R0EE03LZ2,1,1},	//( - , AKNP3) Питание  АКНП3  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_AKNP3[]={  // 
	{&A0EE02LS3,1,0},	//( - , AKNP3) Исправность АКНП3 (от сшивки каналов) канал 3
	{&TestDiagnAKNP3,1,1},	//( - , AKNP3) Неисправность от диагностики
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_AKNP3[]={  // 
	{&R0VN03RS3,8,0},	//( - , AKNP3) Измеренный нейтронный поток канал 3
	{&R0VN04RS3,8,2},	//( - , AKNP3) Реактивность канал 3
	{&R0VN13RS3,8,4},	//( - , AKNP3) Нейтронный поток по камере СНМ11 канал 3
	{&R0VN23RS3,8,6},	//( - , AKNP3) Нейтронный поток по камере КНК15-1 канал 3
	{&R0VN33RS3,8,8},	//( - , AKNP3) Нейтронный поток по камере КНК53М канал 3
	{&R0VN15RS3,3,10},	//( - , AKNP3) Номер ведущей камеры канал 3
	{&TTLaknp3,3,11},	//( - , AKNP3) ttl
	{&R0IN01FS3,8,12},	//( - , AKNP3) Выход СНМ-11 Гц
	{&R0IN02FS3,8,14},	//( - , AKNP3) Выход КНК15-1 Гц
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_AKNP3[]={  // 
	{&fEM_R0UR01RSS,8,0},	//( - , AKNP3) Уставка АКНП ПС  АЗ по периоду (сек)
	{&fEM_R0UL52RSS,8,2},	//( - , AKNP3) Уровень АС по мощности
	{&fEM_R0UL41RSS,8,4},	//( - , AKNP3) Уровень ПС по периоду разгона
	{&fEM_R0UL51RSS,8,6},	//( - , AKNP3) Уровень АС по периоду разгона
	{&fEM_R0UH02RSS,8,8},	//( - , AKNP3) Коэфф. преобразования частота->нейтр/с КНК15-1
	{&fEM_R0UH03RSS,8,10},	//( - , AKNP3) Коэфф. преобразования частота->нейтр/с КНК53М
	{&fEM_R0UL42RSS,8,12},	//( - , AKNP3) Уровень ПС по мощности
	{&fEM_R7UX00RSS,8,14},	//( - , AKNP3) X-координата АЗ1 (см)
	{&fEM_R7UX07RSS,8,16},	//( - , AKNP3) X-координата камеры R7IN31 (см)
	{&fEM_R7UX08RSS,8,18},	//( - , AKNP3) X-координата камеры R7IN32 (см)
	{&fEM_R7UX09RSS,8,20},	//( - , AKNP3) X-координата камеры R7IN33 (см)
	{&fEM_R7UY00RSS,8,22},	//( - , AKNP3) Y-координата АЗ1 (см)
	{&fEM_R7UY07RSS,8,24},	//( - , AKNP3) Y-координата камеры R7IN31 (см)
	{&fEM_R7UY08RSS,8,26},	//( - , AKNP3) Y-координата камеры R7IN32 (см)
	{&fEM_R7UY09RSS,8,28},	//( - , AKNP3) Y-координата камеры R7IN33 (см)
	{&fEM_A0UX00RSS,8,30},	//( - , AKNP3) Эффективный радиус АЗ
	{&fEM_A0UX07RSS,8,32},	//( - , AKNP3) Первый коэффициент калибровки камеры 7
	{&fEM_A0UX08RSS,8,34},	//( - , AKNP3) Первый коэффициент калибровки камеры 8
	{&fEM_A0UX09RSS,8,36},	//( - , AKNP3) Первый коэффициент калибровки камеры 9
	{&fEM_B0UX07RSS,8,38},	//( - , AKNP3) Второй коэффициент калибровки камеры 7
	{&fEM_B0UX08RSS,8,40},	//( - , AKNP3) Второй коэффициент калибровки камеры 8
	{&fEM_B0UX09RSS,8,42},	//( - , AKNP3) Второй коэффициент калибровки камеры 9
	{&fEM_R0UH05RSS,8,44},	//( - , AKNP3) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_R0UN03RSS,8,46},	//( - , AKNP3) Нижняя граница интервала мощности для измерения периода (ватт)
	{&fEM_R0UH01RSS,8,48},	//( - , AKNP3) Коэфф. преобразования частота->нейтр/с СНМ-11
	{&fEM_R0UH21RSS,8,50},	//( - , AKNP3) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{&fEM_R0UH22RSS,8,52},	//( - , AKNP3) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{&fEM_R0UH23RSS,8,54},	//( - , AKNP3) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{&fEM_R0UL02RSS,8,56},	//( - , AKNP3) Tф-постоянная времени, с
	{&fEM_R0UL01RSS,8,58},	//( - , AKNP3) Шаг (мс) измерения периода
	{&fEM_R0IN11FN3,8,60},	//( - , AKNP3) Коэффициент A (А3 к 1)
	{&fEM_R0IN12FN3,8,62},	//( - , AKNP3) Коэффициент B (А3 к 1)
	{&fEM_R0IN21FN3,8,64},	//( - , AKNP3) Коэффициент A (А3 к 2)
	{&fEM_R0IN22FN3,8,66},	//( - , AKNP3) Коэффициент B (А3 к 2)
	{&fEM_R0IN31FN3,8,68},	//( - , AKNP3) Коэффициент A (А3 к 3)
	{&fEM_R0IN32FN3,8,70},	//( - , AKNP3) Коэффициент B (А3 к 3)
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_A3Bz1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_A3Bz1[]={  // 
	{&R0VN61LS3,1,0},	//( - , A3Bz1, A3Bz2) ПС по мощности канал 3
	{&R0VN65LS3,1,1},	//( - , A3Bz1, A3Bz2) ПС по периоду разгона канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_A3Bz1[]={  // 
	{&R0VN02RS3,8,0},	//( - , A3Bz1, A3Bz2) Уровень мощности канал 3
	{&R0VN01RS3,8,2},	//( - , A3Bz1, A3Bz2) Период разгона канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_A3Bz1[]={  // 
	{&B8VC01RDU,8,0},	//( - , A3Bz1, A3Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_A3Bz2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_A3Bz2[]={  // 
	{&R0VN61LS3,1,0},	//( - , A3Bz1, A3Bz2) ПС по мощности канал 3
	{&R0VN65LS3,1,1},	//( - , A3Bz1, A3Bz2) ПС по периоду разгона канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_A3Bz2[]={  // 
	{&R0VN02RS3,8,0},	//( - , A3Bz1, A3Bz2) Уровень мощности канал 3
	{&R0VN01RS3,8,2},	//( - , A3Bz1, A3Bz2) Период разгона канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_A3Bz2[]={  // 
	{&B8VC01RDU,8,0},	//( - , A3Bz1, A3Bz2) Координата АЗ2, мм
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
	{&R0DEB4LS3,1,0},	//( - S13SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП24Д место 8
	{&R0DEB3LS3,1,1},	//( - S12SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП5 место 8
	{&R0DEB2LS3,1,2},	//( - S11SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП24Д место 7
	{&R0DEB1LS3,1,3},	//( - S10SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП5 место 7
	{&R0DE3DLS3,1,4},	//( - , DiagnAKNP3) диагностика шкафа АКНП3 БП5/24Д место 8
	{&R0DE3CLS3,1,5},	//( - , DiagnAKNP3) диагностика шкафа АКНП3 БП5/24Д место 7
	{&R0DE39LS3,1,6},	//( - S09SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП24-2 место 4
	{&R0DE38LS3,1,7},	//( - S08SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3 место 3
	{&R0DE37LS3,1,8},	//( - S07SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3.1 место 2
	{&R0DE36LS3,1,9},	//( - S06SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3.1 место 1
	{&R0DE35LS3,1,10},	//( - S05SBK, DiagnAKNP3) диагностика шкафа АКНП3 температура больше 53
	{&R0DE34LS3,1,11},	//( - S04SBK, DiagnAKNP3) диагностика шкафа АКНП3 температура меньше 43
	{&R0DE33LS3,1,12},	//( - S03SBK, DiagnAKNP3) диагностика шкафа АКНП3 двери
	{&R0DE32LS3,1,13},	//( - S02SBK, DiagnAKNP3) диагностика шкафа АКНП3 сеть 2
	{&R0DE31LS3,1,14},	//( - S01SBK, DiagnAKNP3) диагностика шкафа АКНП3 сеть 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DiagnAKNP3[]={  // 
	{&R0DE05LS3,3,0},	//( - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 5 месте
	{&R0DE04LS3,3,1},	//( - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 4 месте
	{&R0DE02LS3,3,2},	//( - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 2 месте
	{&R0DE01LS3,3,3},	//( - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 1 месте
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DiagnAKNP3[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MA3S[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MA3S[]={  // 
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MA3S[]={  // 
	{&R0IN01FI3,8,0},	//( - , SA3) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI3,8,2},	//( - , SA3) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI3,8,4},	//( - , SA3) Выход КНК53М Гц от ПТИ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MA3S[]={  // 
	{NULL,0,0},
};
#pragma pop
static char MA3S_ip1[]={"192.168.10.60\0"};
static char MA3S_ip2[]={"192.168.10.60\0"};
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_AKNP3[0],&di_AKNP3[0],&ir_AKNP3[0],&hr_AKNP3[0],NULL,NULL,NULL,0},	 //общий slave AKNP3
	{0,5017,&coil_A3Bz1[0],&di_A3Bz1[0],&ir_A3Bz1[0],&hr_A3Bz1[0],NULL,NULL,NULL,0},	 //slave AKNP3 - Baz1
	{0,5021,&coil_A3Bz2[0],&di_A3Bz2[0],&ir_A3Bz2[0],&hr_A3Bz2[0],NULL,NULL,NULL,0},	 //slave AKNP3 - Baz2
	{0,5003,&coil_DiagnAKNP3[0],&di_DiagnAKNP3[0],&ir_DiagnAKNP3[0],&hr_DiagnAKNP3[0],NULL,NULL,NULL,0},	 //Диагностика АКНП3
	{1,5008,&coil_MA3S[0],&di_MA3S[0],&ir_MA3S[0],&hr_MA3S[0],NULL,MA3S_ip1,MA3S_ip2,100},	 //Мастер AKNP3 в SCM

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
	{&R0DE01LS3,3,10},
	{&R0IN02FV3,8,5},
	{&R0IN01FV3,8,0},
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
	{&R0DE02LS3,3,10},
	{&R0IN03FV3,8,0},
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
	{&R0DE04LS3,3,64},
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
	{&R0VN77LZ2,1,26},
	{&R0VN73LZ2,1,24},
	{&A0VN71LS3,1,22},
	{&R0IE02LS3,1,0},
	{&R0IE01LS3,1,2},
	{&R0DE05LS3,3,38},
	{&A1VN71LS3,1,30},
	{&A0EE01LS3,1,20},
	{&R0VN77LZ1,1,18},
	{&A1EE01LS3,1,28},
	{&R0VN73LZ1,1,16},
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
	{&R0DEB4LS3,1,24},
	{&R0DEB3LS3,1,22},
	{&R0DEB2LS3,1,20},
	{&R0DEB1LS3,1,18},
	{&R0DE39LS3,1,16},
	{&R0DE31LS3,1,0},
	{&R0DE32LS3,1,2},
	{&R0DE33LS3,1,4},
	{&R0DE34LS3,1,6},
	{&R0DE35LS3,1,8},
	{&R0DE36LS3,1,10},
	{&R0DE37LS3,1,12},
	{&R0DE38LS3,1,14},
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
	setAsFloat(67,1585.0);
	setAsFloat(68,1796.0);
	setAsFloat(69,1269.0);
	setAsFloat(70,506.5);
	setAsFloat(71,594.0);
	setAsFloat(72,559.0);
	setAsFloat(73,588.0);
	setAsFloat(74,11.0);
	setAsFloat(75,1.0);
	setAsFloat(76,1.0);
	setAsFloat(77,1.0);
	setAsFloat(78,0.0);
	setAsFloat(79,0);
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
	setAsFloat(90,0);
	setAsFloat(91,1);
	setAsFloat(92,0);
	setAsFloat(93,1);
	setAsFloat(94,0);
	setAsBool(41,1);
	setAsBool(42,1);
	setAsBool(43,1);
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
ssint iRM_5_ = {5,0}; /* n - N-размерность массива входных параметров */ 
ssint iRM_2_ = {2,0}; /* n - N-размерность массива входных параметров */ 
sschar bRM_1_ = {1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива значений */ 
ssint iRM_6_ = {6,0}; /* n - N-размерность массива x */ 
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
ssint var14;
ssfloat var15;
ssfloat var16;
ssbool var17;
ssfloat var18;
ssfloat var19;
ssfloat var20;
ssint var21;
ssbool var22;
ssfloat var23;
ssbool var24;
ssbool var25;
ssbool var26;
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
psbool  array_m102_x_1[6] = {&var9,&var8,&R0DE36LS3,&R0DE37LS3,&R0DE38LS3,&R0DE39LS3};
psint  array_m88_x_1[4] = {&R0DE01LS3,&R0DE02LS3,&R0DE04LS3,&R0DE05LS3};
psbool  array_m64_x_1[2] = {&var30,&var25};
psbool  array_m63_x_1[2] = {&var30,&var31};
psbool  array_m74_x_1[5] = {&var17,&R0IE11LS3,&R0IE12LS3,&R0IE13LS3,&lRM_1_};

/* Объявление структур */
_S_mod1  S_mod1_56_1 = {&var23,&fRM_1_,&fRM_3_,&var1,&internal1_m56_y0};
_S_pogrvh  S_pogrvh_118_1 = {&R0IN03FV3,&fEM_R0IN31FN3,&fEM_R0IN32FN3,&var2};
_S_pogrvh  S_pogrvh_116_1 = {&R0IN02FV3,&fEM_R0IN21FN3,&fEM_R0IN22FN3,&var3};
_S_pogrvh  S_pogrvh_114_1 = {&R0IN01FV3,&fEM_R0IN11FN3,&fEM_R0IN12FN3,&var4};
_S_ml  S_ml_8_1 = {&R0IN03FI3,&var2,&R0IS01FI0,&var5};
_S_ml  S_ml_7_1 = {&R0IN02FI3,&var3,&R0IS01FI0,&var6};
_S_ml  S_ml_6_1 = {&R0IN01FI3,&var4,&R0IS01FI0,&var7};
_S_noto  S_noto_103_1 = {&var10,&vainSBool};
_S_or2  S_or2_105_1 = {&R0DEB3LS3,&R0DEB4LS3,&var8};
_S_or2  S_or2_97_1 = {&R0DEB1LS3,&R0DEB2LS3,&var9};
_S_or3  S_or3_99_1 = {&var13,&var12,&var11,&var10};
_S_orn  S_orn_102_1 = {array_m102_x_1,&iRM_6_,&var11};
_S_and2  S_and2_90_1 = {&R0DE31LS3,&R0DE32LS3,&var12};
_S_diagndev  S_diagndev_88_1 = {array_m88_x_1,&iRM_4_,&var13,&var14};
_S_ocham  S_ocham_19_1 = {&var7,&var6,&var5,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX07RSS,&fEM_B0UX07RSS,&fEM_A0UX08RSS,&fEM_B0UX08RSS,&fEM_A0UX09RSS,&fEM_B0UX09RSS,&fEM_R7UX07RSS,&fEM_R7UY07RSS,&fEM_R7UX08RSS,&fEM_R7UY08RSS,&fEM_R7UX09RSS,&fEM_R7UY09RSS,&bRM_1_,&fEM_R0UH01RSS,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&fEM_R0UH21RSS,&fEM_R0UH22RSS,&fEM_R0UH23RSS,&var15,&var16,&var17,&var18,&var19,&var20,&var21,&internal1_m19_Nk};
_S_or2  S_or2_76_1 = {&R0EE03LZ1,&R0EE03LZ2,&var22};
_S_period  S_period_55_1 = {&var16,&var27,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var23,&internal1_m55_flst,&internal1_m55_chsr,&internal1_m55_chizm,&internal1_m55_sumtim,&internal1_m55_W1,&internal1_m55_W2,&internal1_m55_Wmin,&internal1_m55_Wmax,&internal1_m55_Wlast,&internal1_m55_y0,&internal1_m55_MyFirstEnterFlag};
_S_andn  S_andn_64_1 = {array_m64_x_1,&iRM_2_,&var24};
_S_bol  S_bol_61_1 = {&fEM_R0UL41RSS,&var1,&var25};
_S_andn  S_andn_63_1 = {array_m63_x_1,&iRM_2_,&var26};
_S_andn  S_andn_74_1 = {array_m74_x_1,&iRM_5_,&var27};
_S_bol  S_bol_43_1 = {&var16,&fEM_R0UL52RSS,&var28};
_S_bol  S_bol_48_1 = {&var16,&fEM_R0UL42RSS,&var29};
_S_bol  S_bol_60_1 = {&var16,&fEM_R0UN03RSS,&var30};
_S_bol  S_bol_59_1 = {&fEM_R0UL51RSS,&var1,&var31};
_S_react  S_react_57_1 = {&var1,&var32};
_S_bol  S_bol_38_1 = {&var16,&fEM_R0UR01RSS,&var33};


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
   var14.i=0;
   var15.f=0.0;
   var16.f=0.0;
   var17.b=0;
   var18.f=0.0;
   var19.f=0.0;
   var20.f=0.0;
   var21.i=0;
   var22.b=0;
   var23.f=0.0;
   var24.b=0;
   var25.b=0;
   var26.b=0;
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
  and2(&S_and2_90_1);
  or2(&S_or2_97_1);
  or2(&S_or2_105_1);
  orn(&S_orn_102_1);
  or3(&S_or3_99_1);
  noto(&S_noto_103_1);
  pogrvh(&S_pogrvh_114_1);
  pogrvh(&S_pogrvh_116_1);
  pogrvh(&S_pogrvh_118_1);
  ml(&S_ml_6_1);
  ml(&S_ml_7_1);
  ml(&S_ml_8_1);
  ocham(&S_ocham_19_1);
  bol(&S_bol_38_1);
  bol(&S_bol_60_1);
  bol(&S_bol_48_1);
  bol(&S_bol_43_1);
  andn(&S_andn_74_1);
  period(&S_period_55_1);
  mod1(&S_mod1_56_1);
  react(&S_react_57_1);
  bol(&S_bol_59_1);
  andn(&S_andn_63_1);
  bol(&S_bol_61_1);
  andn(&S_andn_64_1);
  setData(idR0IN02FS3,&var3);
  setData(idR0IN03FS3,&var2);
  setData(idR0IN01FS3,&var4);
  setData(idTestDiagnAKNP3,&var10);
  setData(idTTLaknp3,&var14);
  setData(idR0DE3DLS3,&var8);
  setData(idR0DE3CLS3,&var9);
  setData(idA1EE01LS3,&var27);
  setData(idR0VN77LZ2,&var26);
  setData(idR0VN73LZ2,&var28);
  setData(idA0VN71LS3,&var33);
  setData(idR0IE02LS3,&var22);
  setData(idR0IE01LS3,&var22);
  setData(idR0VN15RS3,&var21);
  setData(idR0VN33RS3,&var20);
  setData(idR0VN23RS3,&var19);
  setData(idR0VN13RS3,&var18);
  setData(idA0EE02LS3,&var17);
  setData(idA1VN71LS3,&var33);
  setData(idR0VN04RS3,&var32);
  setData(idR0VN03RS3,&var15);
  setData(idA0EE01LS3,&var27);
  setData(idR0VN77LZ1,&var26);
  setData(idR0VN65LS3,&var24);
  setData(idR0VN73LZ1,&var28);
  setData(idR0VN61LS3,&var29);
  setData(idR0VN01RS3,&var1);
  setData(idR0VN02RS3,&var16);

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
