#ifndef AKNP3_H
#define AKNP3_H
// Подсистема AKNP3:AKNP3
static char SimulOn=0;
static short CodeSub=5;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt, taktScheme=0, taktSS=0;
#define SIZE_BUFFER 354
static char BUFFER[354];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.53\0", 5432, "192.168.10.153\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0DE02LS3	 BUFFER[0]	//(vchs:02 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 2 месте
#define idR0DE02LS3	 1	//(vchs:02 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 2 месте
#define R0DE04LS3	 BUFFER[3]	//(vds32:04 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 4 месте
#define idR0DE04LS3	 2	//(vds32:04 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 4 месте
#define R0DE05LS3	 BUFFER[6]	//(fds16:05 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 5 месте
#define idR0DE05LS3	 3	//(fds16:05 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 5 месте
#define R0DE31LS3	 BUFFER[9]	//(sbk:20 - S01SBK, DiagnAKNP3) диагностика шкафа АКНП3 сеть 1
#define idR0DE31LS3	 4	//(sbk:20 - S01SBK, DiagnAKNP3) диагностика шкафа АКНП3 сеть 1
#define R0DE32LS3	 BUFFER[11]	//(sbk:20 - S02SBK, DiagnAKNP3) диагностика шкафа АКНП3 сеть 2
#define idR0DE32LS3	 5	//(sbk:20 - S02SBK, DiagnAKNP3) диагностика шкафа АКНП3 сеть 2
#define R0DE33LS3	 BUFFER[13]	//(sbk:20 - S03SBK, DiagnAKNP3) диагностика шкафа АКНП3 двери
#define idR0DE33LS3	 6	//(sbk:20 - S03SBK, DiagnAKNP3) диагностика шкафа АКНП3 двери
#define R0DE34LS3	 BUFFER[15]	//(sbk:20 - S04SBK, DiagnAKNP3) диагностика шкафа АКНП3 температура меньше 43
#define idR0DE34LS3	 7	//(sbk:20 - S04SBK, DiagnAKNP3) диагностика шкафа АКНП3 температура меньше 43
#define R0DE35LS3	 BUFFER[17]	//(sbk:20 - S05SBK, DiagnAKNP3) диагностика шкафа АКНП3 температура больше 53
#define idR0DE35LS3	 8	//(sbk:20 - S05SBK, DiagnAKNP3) диагностика шкафа АКНП3 температура больше 53
#define R0DE36LS3	 BUFFER[19]	//(sbk:20 - S06SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3.1 место 1
#define idR0DE36LS3	 9	//(sbk:20 - S06SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3.1 место 1
#define R0DE37LS3	 BUFFER[21]	//(sbk:20 - S07SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3.1 место 2
#define idR0DE37LS3	 10	//(sbk:20 - S07SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3.1 место 2
#define R0DE38LS3	 BUFFER[23]	//(sbk:20 - S08SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3 место 3
#define idR0DE38LS3	 11	//(sbk:20 - S08SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3 место 3
#define R0DE39LS3	 BUFFER[25]	//(sbk:20 - S09SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП24-2 место 4
#define idR0DE39LS3	 12	//(sbk:20 - S09SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП24-2 место 4
#define R0DE3CLS3	 BUFFER[27]	//( - , DiagnAKNP3) диагностика шкафа АКНП3 БП5/24Д место 7
#define idR0DE3CLS3	 13	//( - , DiagnAKNP3) диагностика шкафа АКНП3 БП5/24Д место 7
#define R0DE3DLS3	 BUFFER[29]	//( - , DiagnAKNP3) диагностика шкафа АКНП3 БП5/24Д место 8
#define idR0DE3DLS3	 14	//( - , DiagnAKNP3) диагностика шкафа АКНП3 БП5/24Д место 8
#define TTLaknp3	 BUFFER[31]	//( - , AKNP3) ttl
#define idTTLaknp3	 15	//( - , AKNP3) ttl
#define TestDiagnAKNP3	 BUFFER[34]	//( - , AKNP3) Неисправность от диагностики
#define idTestDiagnAKNP3	 16	//( - , AKNP3) Неисправность от диагностики
#define R0DEB1LS3	 BUFFER[36]	//(sbk:20 - S10SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП5 место 7
#define idR0DEB1LS3	 17	//(sbk:20 - S10SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП5 место 7
#define R0DEB2LS3	 BUFFER[38]	//(sbk:20 - S11SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП24Д место 7
#define idR0DEB2LS3	 18	//(sbk:20 - S11SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП24Д место 7
#define R0DEB3LS3	 BUFFER[40]	//(sbk:20 - S12SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП5 место 8
#define idR0DEB3LS3	 19	//(sbk:20 - S12SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП5 место 8
#define R0DEB4LS3	 BUFFER[42]	//(sbk:20 - S13SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП24Д место 8
#define idR0DEB4LS3	 20	//(sbk:20 - S13SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП24Д место 8
#define R0IN01FS3	 BUFFER[44]	//(vchs:01 - K01VCHS, - ) Выход СНМ-11 Гц
#define idR0IN01FS3	 21	//(vchs:01 - K01VCHS, - ) Выход СНМ-11 Гц
#define R0IN02FI3	 BUFFER[49]	//( - , MA3S) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI3	 22	//( - , MA3S) Выход КНК15-1 Гц от ПТИ
#define R0IN03FS3	 BUFFER[54]	//(vchs:02 - K01VCHS, - ) Выход КНК53М Гц
#define idR0IN03FS3	 23	//(vchs:02 - K01VCHS, - ) Выход КНК53М Гц
#define R0IS01FI0	 BUFFER[59]	//( - , MA3S) Признак работы с имитатором
#define idR0IS01FI0	 24	//( - , MA3S) Признак работы с имитатором
#define R0IN01FI3	 BUFFER[61]	//( - , MA3S) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI3	 25	//( - , MA3S) Выход СНМ-11 Гц от ПТИ
#define R0IN02FS3	 BUFFER[66]	//(vchs:01 - K02VCHS, - ) Выход КНК15-1 Гц
#define idR0IN02FS3	 26	//(vchs:01 - K02VCHS, - ) Выход КНК15-1 Гц
#define R0IN03FI3	 BUFFER[71]	//( - , MA3S) Выход КНК53М Гц от ПТИ
#define idR0IN03FI3	 27	//( - , MA3S) Выход КНК53М Гц от ПТИ
#define R0VN02RS3	 BUFFER[76]	//( - , A3Bz1, A3Bz2) Уровень мощности канал 3
#define idR0VN02RS3	 28	//( - , A3Bz1, A3Bz2) Уровень мощности канал 3
#define R0VN01RS3	 BUFFER[81]	//( - , A3Bz1, A3Bz2) Период разгона канал 3
#define idR0VN01RS3	 29	//( - , A3Bz1, A3Bz2) Период разгона канал 3
#define R0VN61LS3	 BUFFER[86]	//( - , A3Bz1, A3Bz2) ПС по мощности канал 3
#define idR0VN61LS3	 30	//( - , A3Bz1, A3Bz2) ПС по мощности канал 3
#define R0VN73LZ1	 BUFFER[88]	//(fds16:05 - K09FDSR, - ) АС по мощности канал 3 на БАЗ1
#define idR0VN73LZ1	 31	//(fds16:05 - K09FDSR, - ) АС по мощности канал 3 на БАЗ1
#define R0VN65LS3	 BUFFER[90]	//( - , A3Bz1, A3Bz2) ПС по периоду разгона канал 3
#define idR0VN65LS3	 32	//( - , A3Bz1, A3Bz2) ПС по периоду разгона канал 3
#define R0VN77LZ1	 BUFFER[92]	//(fds16:05 - K10FDSR, - ) АС по периоду разгона канал 3 на БАЗ1
#define idR0VN77LZ1	 33	//(fds16:05 - K10FDSR, - ) АС по периоду разгона канал 3 на БАЗ1
#define A0EE01LS3	 BUFFER[94]	//(fds16:05 - K11FDSR, - ) Исправность АКНП канал 3 на БАЗ1
#define idA0EE01LS3	 34	//(fds16:05 - K11FDSR, - ) Исправность АКНП канал 3 на БАЗ1
#define R0VN03RS3	 BUFFER[96]	//( - , AKNP3) Измеренный нейтронный поток канал 3
#define idR0VN03RS3	 35	//( - , AKNP3) Измеренный нейтронный поток канал 3
#define R0VN04RS3	 BUFFER[101]	//( - , AKNP3) Реактивность канал 3
#define idR0VN04RS3	 36	//( - , AKNP3) Реактивность канал 3
#define A1VN71LS3	 BUFFER[106]	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
#define idA1VN71LS3	 37	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
#define A0EE02LS3	 BUFFER[108]	//( - , AKNP3) Исправность АКНП3 (от сшивки каналов) канал 3
#define idA0EE02LS3	 38	//( - , AKNP3) Исправность АКНП3 (от сшивки каналов) канал 3
#define R0IE11LS3	 BUFFER[110]	//( - , - ) Исправность ВИП 1,6 (№14) СНМ11 3 канала
#define idR0IE11LS3	 39	//( - , - ) Исправность ВИП 1,6 (№14) СНМ11 3 канала
#define R0IE12LS3	 BUFFER[112]	//( - , - ) Исправность ВИП 0,5 (№15) КНК15-1 3 канала
#define idR0IE12LS3	 40	//( - , - ) Исправность ВИП 0,5 (№15) КНК15-1 3 канала
#define R0IE13LS3	 BUFFER[114]	//( - , - ) Исправность ВИП 0,5 (№16) КНК53М 3 канала
#define idR0IE13LS3	 41	//( - , - ) Исправность ВИП 0,5 (№16) КНК53М 3 канала
#define R0VN13RS3	 BUFFER[116]	//( - , AKNP3) Нейтронный поток по камере СНМ11 канал 3
#define idR0VN13RS3	 42	//( - , AKNP3) Нейтронный поток по камере СНМ11 канал 3
#define R0VN23RS3	 BUFFER[121]	//( - , AKNP3) Нейтронный поток по камере КНК15-1 канал 3
#define idR0VN23RS3	 43	//( - , AKNP3) Нейтронный поток по камере КНК15-1 канал 3
#define R0VN33RS3	 BUFFER[126]	//( - , AKNP3) Нейтронный поток по камере КНК53М канал 3
#define idR0VN33RS3	 44	//( - , AKNP3) Нейтронный поток по камере КНК53М канал 3
#define R0VN15RS3	 BUFFER[131]	//( - , AKNP3) Номер ведущей камеры канал 3
#define idR0VN15RS3	 45	//( - , AKNP3) Номер ведущей камеры канал 3
#define R0IE01LS3	 BUFFER[134]	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 3
#define idR0IE01LS3	 46	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 3
#define R0IE02LS3	 BUFFER[136]	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 3
#define idR0IE02LS3	 47	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 3
#define A0VN71LS3	 BUFFER[138]	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
#define idA0VN71LS3	 48	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
#define R0VN73LZ2	 BUFFER[140]	//(fds16:05 - K13FDSR, - ) АС по мощности канал 3 на БАЗ2
#define idR0VN73LZ2	 49	//(fds16:05 - K13FDSR, - ) АС по мощности канал 3 на БАЗ2
#define R0VN77LZ2	 BUFFER[142]	//(fds16:05 - K14FDSR, - ) АС по периоду разгона канал 3 на БАЗ2
#define idR0VN77LZ2	 50	//(fds16:05 - K14FDSR, - ) АС по периоду разгона канал 3 на БАЗ2
#define A1EE01LS3	 BUFFER[144]	//(fds16:05 - K15FDSR, - ) Исправность АКНП канал 3 на БАЗ2
#define idA1EE01LS3	 51	//(fds16:05 - K15FDSR, - ) Исправность АКНП канал 3 на БАЗ2
#define B8VC01RDU	 BUFFER[146]	//( - , A3Bz1, A3Bz2) Координата АЗ2, мм
#define idB8VC01RDU	 52	//( - , A3Bz1, A3Bz2) Координата АЗ2, мм
#define R0EE03LZ1	 BUFFER[151]	//( - , AKNP3) Питание  АКНП3  отключить
#define idR0EE03LZ1	 53	//( - , AKNP3) Питание  АКНП3  отключить
#define R0EE03LZ2	 BUFFER[153]	//( - , AKNP3) Питание  АКНП3  отключить
#define idR0EE03LZ2	 54	//( - , AKNP3) Питание  АКНП3  отключить
#define R0DE01LS3	 BUFFER[155]	//(vchs:01 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 1 месте
#define idR0DE01LS3	 55	//(vchs:01 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 1 месте
#define fEM_R0UR01RSS	 BUFFER[158]	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RSS	 56	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R0UL52RSS	 BUFFER[163]	//(R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	 57	//(R0UL52RSS) Уровень АС по мощности
#define fEM_R0UL41RSS	 BUFFER[168]	//(R0UL41RSS) Уровень ПС по периоду разгона
#define idfEM_R0UL41RSS	 58	//(R0UL41RSS) Уровень ПС по периоду разгона
#define fEM_R0UL51RSS	 BUFFER[173]	//(R0UL51RSS) Уровень АС по периоду разгона
#define idfEM_R0UL51RSS	 59	//(R0UL51RSS) Уровень АС по периоду разгона
#define fEM_R0UH02RSS	 BUFFER[178]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define idfEM_R0UH02RSS	 60	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define fEM_R0UH03RSS	 BUFFER[183]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define idfEM_R0UH03RSS	 61	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define fEM_R0UL42RSS	 BUFFER[188]	//(R0UL42RSS) Уровень ПС по мощности
#define idfEM_R0UL42RSS	 62	//(R0UL42RSS) Уровень ПС по мощности
#define fEM_R7UX00RSS	 BUFFER[193]	//(R7UX00RSS) X-координата АЗ1 (см)
#define idfEM_R7UX00RSS	 63	//(R7UX00RSS) X-координата АЗ1 (см)
#define fEM_R7UX07RSS	 BUFFER[198]	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define idfEM_R7UX07RSS	 64	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define fEM_R7UX08RSS	 BUFFER[203]	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define idfEM_R7UX08RSS	 65	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define fEM_R7UX09RSS	 BUFFER[208]	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define idfEM_R7UX09RSS	 66	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define fEM_R7UY00RSS	 BUFFER[213]	//(R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	 67	//(R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UY07RSS	 BUFFER[218]	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define idfEM_R7UY07RSS	 68	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define fEM_R7UY08RSS	 BUFFER[223]	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define idfEM_R7UY08RSS	 69	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define fEM_R7UY09RSS	 BUFFER[228]	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define idfEM_R7UY09RSS	 70	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define fEM_A0UX00RSS	 BUFFER[233]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 71	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX07RSS	 BUFFER[238]	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define idfEM_A0UX07RSS	 72	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define fEM_A0UX08RSS	 BUFFER[243]	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define idfEM_A0UX08RSS	 73	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define fEM_A0UX09RSS	 BUFFER[248]	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define idfEM_A0UX09RSS	 74	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define fEM_B0UX07RSS	 BUFFER[253]	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define idfEM_B0UX07RSS	 75	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define fEM_B0UX08RSS	 BUFFER[258]	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define idfEM_B0UX08RSS	 76	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define fEM_B0UX09RSS	 BUFFER[263]	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define idfEM_B0UX09RSS	 77	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define fEM_R0UH05RSS	 BUFFER[268]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 78	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UN03RSS	 BUFFER[273]	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN03RSS	 79	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R0UH01RSS	 BUFFER[278]	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
#define idfEM_R0UH01RSS	 80	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
#define fEM_R0UH21RSS	 BUFFER[283]	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	 81	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	 BUFFER[288]	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	 82	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	 BUFFER[293]	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	 83	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0UL02RSS	 BUFFER[298]	//(R0UL02RSS) Tф-постоянная времени, с
#define idfEM_R0UL02RSS	 84	//(R0UL02RSS) Tф-постоянная времени, с
#define fEM_R0UL01RSS	 BUFFER[303]	//(R0UL01RSS) Шаг (мс) измерения периода
#define idfEM_R0UL01RSS	 85	//(R0UL01RSS) Шаг (мс) измерения периода
#define bFirstEnterFlag	 BUFFER[308]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 86	//(bFirstEnterFlag) 
#define internal1_m22_Nk	 BUFFER[310]	//(internal1_m22_Nk) Nk - ведущая камера
#define idinternal1_m22_Nk	 87	//(internal1_m22_Nk) Nk - ведущая камера
#define internal1_m57_flst	 BUFFER[313]	//(internal1_m57_flst)  флаг старта измерения
#define idinternal1_m57_flst	 88	//(internal1_m57_flst)  флаг старта измерения
#define internal1_m57_chsr	 BUFFER[316]	//(internal1_m57_chsr)  счетчик усреднения
#define idinternal1_m57_chsr	 89	//(internal1_m57_chsr)  счетчик усреднения
#define internal1_m57_chizm	 BUFFER[319]	//(internal1_m57_chizm)  счетчик уменьшения мощности
#define idinternal1_m57_chizm	 90	//(internal1_m57_chizm)  счетчик уменьшения мощности
#define internal1_m57_sumtim	 BUFFER[322]	//(internal1_m57_sumtim)  время измерения мощности
#define idinternal1_m57_sumtim	 91	//(internal1_m57_sumtim)  время измерения мощности
#define internal1_m57_W1	 BUFFER[327]	//(internal1_m57_W1)  мощность на старте измерения
#define idinternal1_m57_W1	 92	//(internal1_m57_W1)  мощность на старте измерения
#define internal1_m57_W2	 BUFFER[332]	//(internal1_m57_W2)  мощность в конце измерения
#define idinternal1_m57_W2	 93	//(internal1_m57_W2)  мощность в конце измерения
#define internal1_m57_Wmin	 BUFFER[337]	//(internal1_m57_Wmin)  минимальное измерение в серии
#define idinternal1_m57_Wmin	 94	//(internal1_m57_Wmin)  минимальное измерение в серии
#define internal1_m57_Wmax	 BUFFER[342]	//(internal1_m57_Wmax)  максимальное измерение в серии
#define idinternal1_m57_Wmax	 95	//(internal1_m57_Wmax)  максимальное измерение в серии
#define internal1_m57_y0	 BUFFER[347]	//(internal1_m57_y0) y0 - внутренний параметр
#define idinternal1_m57_y0	 96	//(internal1_m57_y0) y0 - внутренний параметр
#define internal1_m57_MyFirstEnterFlag	 BUFFER[352]	//(internal1_m57_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m57_MyFirstEnterFlag	 97	//(internal1_m57_MyFirstEnterFlag)  FirstEnterFlag
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,3	,1	, &R0DE02LS3},	//(vchs:02 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 2 месте
	{ 2	,3	,1	, &R0DE04LS3},	//(vds32:04 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 4 месте
	{ 3	,3	,1	, &R0DE05LS3},	//(fds16:05 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 5 месте
	{ 4	,1	,1	, &R0DE31LS3},	//(sbk:20 - S01SBK, DiagnAKNP3) диагностика шкафа АКНП3 сеть 1
	{ 5	,1	,1	, &R0DE32LS3},	//(sbk:20 - S02SBK, DiagnAKNP3) диагностика шкафа АКНП3 сеть 2
	{ 6	,1	,1	, &R0DE33LS3},	//(sbk:20 - S03SBK, DiagnAKNP3) диагностика шкафа АКНП3 двери
	{ 7	,1	,1	, &R0DE34LS3},	//(sbk:20 - S04SBK, DiagnAKNP3) диагностика шкафа АКНП3 температура меньше 43
	{ 8	,1	,1	, &R0DE35LS3},	//(sbk:20 - S05SBK, DiagnAKNP3) диагностика шкафа АКНП3 температура больше 53
	{ 9	,1	,1	, &R0DE36LS3},	//(sbk:20 - S06SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3.1 место 1
	{ 10	,1	,1	, &R0DE37LS3},	//(sbk:20 - S07SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3.1 место 2
	{ 11	,1	,1	, &R0DE38LS3},	//(sbk:20 - S08SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3 место 3
	{ 12	,1	,1	, &R0DE39LS3},	//(sbk:20 - S09SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП24-2 место 4
	{ 13	,1	,1	, &R0DE3CLS3},	//( - , DiagnAKNP3) диагностика шкафа АКНП3 БП5/24Д место 7
	{ 14	,1	,1	, &R0DE3DLS3},	//( - , DiagnAKNP3) диагностика шкафа АКНП3 БП5/24Д место 8
	{ 15	,3	,1	, &TTLaknp3},	//( - , AKNP3) ttl
	{ 16	,1	,1	, &TestDiagnAKNP3},	//( - , AKNP3) Неисправность от диагностики
	{ 17	,1	,1	, &R0DEB1LS3},	//(sbk:20 - S10SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП5 место 7
	{ 18	,1	,1	, &R0DEB2LS3},	//(sbk:20 - S11SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП24Д место 7
	{ 19	,1	,1	, &R0DEB3LS3},	//(sbk:20 - S12SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП5 место 8
	{ 20	,1	,1	, &R0DEB4LS3},	//(sbk:20 - S13SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП24Д место 8
	{ 21	,8	,1	, &R0IN01FS3},	//(vchs:01 - K01VCHS, - ) Выход СНМ-11 Гц
	{ 22	,8	,1	, &R0IN02FI3},	//( - , MA3S) Выход КНК15-1 Гц от ПТИ
	{ 23	,8	,1	, &R0IN03FS3},	//(vchs:02 - K01VCHS, - ) Выход КНК53М Гц
	{ 24	,1	,1	, &R0IS01FI0},	//( - , MA3S) Признак работы с имитатором
	{ 25	,8	,1	, &R0IN01FI3},	//( - , MA3S) Выход СНМ-11 Гц от ПТИ
	{ 26	,8	,1	, &R0IN02FS3},	//(vchs:01 - K02VCHS, - ) Выход КНК15-1 Гц
	{ 27	,8	,1	, &R0IN03FI3},	//( - , MA3S) Выход КНК53М Гц от ПТИ
	{ 28	,8	,1	, &R0VN02RS3},	//( - , A3Bz1, A3Bz2) Уровень мощности канал 3
	{ 29	,8	,1	, &R0VN01RS3},	//( - , A3Bz1, A3Bz2) Период разгона канал 3
	{ 30	,1	,1	, &R0VN61LS3},	//( - , A3Bz1, A3Bz2) ПС по мощности канал 3
	{ 31	,1	,1	, &R0VN73LZ1},	//(fds16:05 - K09FDSR, - ) АС по мощности канал 3 на БАЗ1
	{ 32	,1	,1	, &R0VN65LS3},	//( - , A3Bz1, A3Bz2) ПС по периоду разгона канал 3
	{ 33	,1	,1	, &R0VN77LZ1},	//(fds16:05 - K10FDSR, - ) АС по периоду разгона канал 3 на БАЗ1
	{ 34	,1	,1	, &A0EE01LS3},	//(fds16:05 - K11FDSR, - ) Исправность АКНП канал 3 на БАЗ1
	{ 35	,8	,1	, &R0VN03RS3},	//( - , AKNP3) Измеренный нейтронный поток канал 3
	{ 36	,8	,1	, &R0VN04RS3},	//( - , AKNP3) Реактивность канал 3
	{ 37	,1	,1	, &A1VN71LS3},	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
	{ 38	,1	,1	, &A0EE02LS3},	//( - , AKNP3) Исправность АКНП3 (от сшивки каналов) канал 3
	{ 39	,1	,1	, &R0IE11LS3},	//( - , - ) Исправность ВИП 1,6 (№14) СНМ11 3 канала
	{ 40	,1	,1	, &R0IE12LS3},	//( - , - ) Исправность ВИП 0,5 (№15) КНК15-1 3 канала
	{ 41	,1	,1	, &R0IE13LS3},	//( - , - ) Исправность ВИП 0,5 (№16) КНК53М 3 канала
	{ 42	,8	,1	, &R0VN13RS3},	//( - , AKNP3) Нейтронный поток по камере СНМ11 канал 3
	{ 43	,8	,1	, &R0VN23RS3},	//( - , AKNP3) Нейтронный поток по камере КНК15-1 канал 3
	{ 44	,8	,1	, &R0VN33RS3},	//( - , AKNP3) Нейтронный поток по камере КНК53М канал 3
	{ 45	,3	,1	, &R0VN15RS3},	//( - , AKNP3) Номер ведущей камеры канал 3
	{ 46	,1	,1	, &R0IE01LS3},	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 3
	{ 47	,1	,1	, &R0IE02LS3},	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 3
	{ 48	,1	,1	, &A0VN71LS3},	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
	{ 49	,1	,1	, &R0VN73LZ2},	//(fds16:05 - K13FDSR, - ) АС по мощности канал 3 на БАЗ2
	{ 50	,1	,1	, &R0VN77LZ2},	//(fds16:05 - K14FDSR, - ) АС по периоду разгона канал 3 на БАЗ2
	{ 51	,1	,1	, &A1EE01LS3},	//(fds16:05 - K15FDSR, - ) Исправность АКНП канал 3 на БАЗ2
	{ 52	,8	,1	, &B8VC01RDU},	//( - , A3Bz1, A3Bz2) Координата АЗ2, мм
	{ 53	,1	,1	, &R0EE03LZ1},	//( - , AKNP3) Питание  АКНП3  отключить
	{ 54	,1	,1	, &R0EE03LZ2},	//( - , AKNP3) Питание  АКНП3  отключить
	{ 55	,3	,1	, &R0DE01LS3},	//(vchs:01 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 1 месте
	{ 56	,8	,1	, &fEM_R0UR01RSS},	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
	{ 57	,8	,1	, &fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{ 58	,8	,1	, &fEM_R0UL41RSS},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{ 59	,8	,1	, &fEM_R0UL51RSS},	//(R0UL51RSS) Уровень АС по периоду разгона
	{ 60	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{ 61	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{ 62	,8	,1	, &fEM_R0UL42RSS},	//(R0UL42RSS) Уровень ПС по мощности
	{ 63	,8	,1	, &fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{ 64	,8	,1	, &fEM_R7UX07RSS},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{ 65	,8	,1	, &fEM_R7UX08RSS},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{ 66	,8	,1	, &fEM_R7UX09RSS},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{ 67	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{ 68	,8	,1	, &fEM_R7UY07RSS},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{ 69	,8	,1	, &fEM_R7UY08RSS},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{ 70	,8	,1	, &fEM_R7UY09RSS},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{ 71	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 72	,8	,1	, &fEM_A0UX07RSS},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{ 73	,8	,1	, &fEM_A0UX08RSS},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{ 74	,8	,1	, &fEM_A0UX09RSS},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{ 75	,8	,1	, &fEM_B0UX07RSS},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{ 76	,8	,1	, &fEM_B0UX08RSS},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{ 77	,8	,1	, &fEM_B0UX09RSS},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{ 78	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 79	,8	,1	, &fEM_R0UN03RSS},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 80	,8	,1	, &fEM_R0UH01RSS},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
	{ 81	,8	,1	, &fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{ 82	,8	,1	, &fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{ 83	,8	,1	, &fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{ 84	,8	,1	, &fEM_R0UL02RSS},	//(R0UL02RSS) Tф-постоянная времени, с
	{ 85	,8	,1	, &fEM_R0UL01RSS},	//(R0UL01RSS) Шаг (мс) измерения периода
	{ 86	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 87	,3	,1	, &internal1_m22_Nk},	//(internal1_m22_Nk) Nk - ведущая камера
	{ 88	,3	,1	, &internal1_m57_flst},	//(internal1_m57_flst)  флаг старта измерения
	{ 89	,3	,1	, &internal1_m57_chsr},	//(internal1_m57_chsr)  счетчик усреднения
	{ 90	,3	,1	, &internal1_m57_chizm},	//(internal1_m57_chizm)  счетчик уменьшения мощности
	{ 91	,8	,1	, &internal1_m57_sumtim},	//(internal1_m57_sumtim)  время измерения мощности
	{ 92	,8	,1	, &internal1_m57_W1},	//(internal1_m57_W1)  мощность на старте измерения
	{ 93	,8	,1	, &internal1_m57_W2},	//(internal1_m57_W2)  мощность в конце измерения
	{ 94	,8	,1	, &internal1_m57_Wmin},	//(internal1_m57_Wmin)  минимальное измерение в серии
	{ 95	,8	,1	, &internal1_m57_Wmax},	//(internal1_m57_Wmax)  максимальное измерение в серии
	{ 96	,8	,1	, &internal1_m57_y0},	//(internal1_m57_y0) y0 - внутренний параметр
	{ 97	,1	,1	, &internal1_m57_MyFirstEnterFlag},	//(internal1_m57_MyFirstEnterFlag)  FirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="aknp3.bin\0";   // Имя файла для сохранения констант
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
{64,"fEM_R7UX07RSS\0"}, 
{65,"fEM_R7UX08RSS\0"}, 
{66,"fEM_R7UX09RSS\0"}, 
{67,"fEM_R7UY00RSS\0"}, 
{68,"fEM_R7UY07RSS\0"}, 
{69,"fEM_R7UY08RSS\0"}, 
{70,"fEM_R7UY09RSS\0"}, 
{71,"fEM_A0UX00RSS\0"}, 
{72,"fEM_A0UX07RSS\0"}, 
{73,"fEM_A0UX08RSS\0"}, 
{74,"fEM_A0UX09RSS\0"}, 
{75,"fEM_B0UX07RSS\0"}, 
{76,"fEM_B0UX08RSS\0"}, 
{77,"fEM_B0UX09RSS\0"}, 
{78,"fEM_R0UH05RSS\0"}, 
{79,"fEM_R0UN03RSS\0"}, 
{80,"fEM_R0UH01RSS\0"}, 
{81,"fEM_R0UH21RSS\0"}, 
{82,"fEM_R0UH22RSS\0"}, 
{83,"fEM_R0UH23RSS\0"}, 
{84,"fEM_R0UL02RSS\0"}, 
{85,"fEM_R0UL01RSS\0"}, 
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
	{&fEM_R0UL01RSS,8,48},	//( - , AKNP3) Шаг (мс) измерения периода
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
	{&R0IN02FS3,8,5},
	{&R0IN01FS3,8,0},
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
	{&R0IN03FS3,8,0},
	{&R0DE02LS3,3,10},
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
	{&A1VN71LS3,1,30},
	{&R0IE01LS3,1,2},
	{&R0IE02LS3,1,0},
	{&A0VN71LS3,1,22},
	{&R0VN73LZ2,1,24},
	{&A0EE01LS3,1,20},
	{&R0VN77LZ2,1,26},
	{&R0VN77LZ1,1,18},
	{&R0VN73LZ1,1,16},
	{&A1EE01LS3,1,28},
	{&R0DE05LS3,3,38},
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
	{&R0DE31LS3,1,0},
	{&R0DE32LS3,1,2},
	{&R0DE33LS3,1,4},
	{&R0DE34LS3,1,6},
	{&R0DE35LS3,1,8},
	{&R0DE36LS3,1,10},
	{&R0DE37LS3,1,12},
	{&R0DE38LS3,1,14},
	{&R0DE39LS3,1,16},
	{&R0DEB1LS3,1,18},
	{&R0DEB2LS3,1,20},
	{&R0DEB3LS3,1,22},
	{&R0DEB4LS3,1,24},
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
	setAsFloat(56,5000);
	setAsFloat(57,5100);
	setAsFloat(58,20);
	setAsFloat(59,13.0);
	setAsFloat(60,37037.04 );
	setAsFloat(61,975000.0);
	setAsFloat(62,5000);
	setAsFloat(63,1570.0);
	setAsFloat(64,1585.0);
	setAsFloat(65,1796.0);
	setAsFloat(66,1269.0);
	setAsFloat(67,506.5);
	setAsFloat(68,594.0);
	setAsFloat(69,559.0);
	setAsFloat(70,588.0);
	setAsFloat(71,11.0);
	setAsFloat(72,1.0);
	setAsFloat(73,1.0);
	setAsFloat(74,1.0);
	setAsFloat(75,0.0);
	setAsFloat(76,0);
	setAsFloat(77,0.0);
	setAsFloat(78,32000.0);
	setAsFloat(79,0.005);
	setAsFloat(80,20);
	setAsFloat(81,4000);
	setAsFloat(82,100000);
	setAsFloat(83,1000000);
	setAsFloat(84,2.0);
	setAsFloat(85,0.5);
	setAsBool(39,1);
	setAsBool(40,1);
	setAsBool(41,1);
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

uspaint8 InternalBuf[46];

/* ����������� �������� ��� � ������*/
ssint iRM_5_ = {5,0}; /* n - N-����������� ������� ������� ���������� */ 
ssint iRM_2_ = {2,0}; /* n - N-����������� ������� ������� ���������� */ 
sschar bRM_1_ = {1,0}; /* type - ��� ������ ���-11 1- ��� ��1, 2- ��� ��2, >2 ��� */ 
ssint iRM_4_ = {4,0}; /* n - ����������� ������� �������� */ 
ssint iRM_6_ = {6,0}; /* n - N-����������� ������� x */ 
ssbool lRM_1_ = {1,0}; /*  */ 
ssfloat fRM_1_0 = {1.0,0}; /* k - K�-����������� �������� */ 

uspaint8 SpaEEPROMBuf[150];

/* ����������� ���������� */
ssfloat var1;
ssfloat var2;
ssfloat var3;
ssbool var4;
ssbool var5;
ssbool var6;
ssbool var7;
ssbool var8;
ssbool var9;
ssint var10;
ssfloat var11;
ssfloat var12;
ssbool var13;
ssfloat var14;
ssfloat var15;
ssfloat var16;
ssint var17;
ssbool var18;
ssfloat var19;
ssbool var20;
ssbool var21;
ssbool var22;
ssbool var23;
ssbool var24;
ssbool var25;
ssbool var26;
ssbool var27;
ssfloat var28;
ssbool var29;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* ���������� �������� */
psbool  array_m104_x_1[6] = {&var5,&var4,&R0DE36LS3,&R0DE37LS3,&R0DE38LS3,&R0DE39LS3};
psint  array_m90_x_1[4] = {&R0DE01LS3,&R0DE02LS3,&R0DE04LS3,&R0DE05LS3};
psbool  array_m66_x_1[2] = {&var26,&var21};
psbool  array_m65_x_1[2] = {&var26,&var27};
psbool  array_m76_x_1[5] = {&var13,&R0IE11LS3,&R0IE12LS3,&R0IE13LS3,&lRM_1_};

/* ���������� �������� */
_S_ml  S_ml_8_1 = {&R0IN03FI3,&R0IN03FS3,&R0IS01FI0,&var1};
_S_ml  S_ml_7_1 = {&R0IN02FI3,&R0IN02FS3,&R0IS01FI0,&var2};
_S_ml  S_ml_6_1 = {&R0IN01FI3,&R0IN01FS3,&R0IS01FI0,&var3};
_S_noto  S_noto_105_1 = {&var6,&vainSBool};
_S_or2  S_or2_107_1 = {&R0DEB3LS3,&R0DEB4LS3,&var4};
_S_or2  S_or2_99_1 = {&R0DEB1LS3,&R0DEB2LS3,&var5};
_S_or3  S_or3_101_1 = {&var9,&var8,&var7,&var6};
_S_orn  S_orn_104_1 = {array_m104_x_1,&iRM_6_,&var7};
_S_and2  S_and2_92_1 = {&R0DE31LS3,&R0DE32LS3,&var8};
_S_diagndev  S_diagndev_90_1 = {array_m90_x_1,&iRM_4_,&var9,&var10};
_S_ocham  S_ocham_22_1 = {&var3,&var2,&var1,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX07RSS,&fEM_B0UX07RSS,&fEM_A0UX08RSS,&fEM_B0UX08RSS,&fEM_A0UX09RSS,&fEM_B0UX09RSS,&fEM_R7UX07RSS,&fEM_R7UY07RSS,&fEM_R7UX08RSS,&fEM_R7UY08RSS,&fEM_R7UX09RSS,&fEM_R7UY09RSS,&bRM_1_,&fEM_R0UH01RSS,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&fEM_R0UH21RSS,&fEM_R0UH22RSS,&fEM_R0UH23RSS,&var11,&var12,&var13,&var14,&var15,&var16,&var17,&internal1_m22_Nk};
_S_or2  S_or2_78_1 = {&R0EE03LZ1,&R0EE03LZ2,&var18};
_S_period  S_period_57_1 = {&var12,&var23,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var19,&internal1_m57_flst,&internal1_m57_chsr,&internal1_m57_chizm,&internal1_m57_sumtim,&internal1_m57_W1,&internal1_m57_W2,&internal1_m57_Wmin,&internal1_m57_Wmax,&internal1_m57_y0,&internal1_m57_MyFirstEnterFlag};
_S_andn  S_andn_66_1 = {array_m66_x_1,&iRM_2_,&var20};
_S_bol  S_bol_63_1 = {&fEM_R0UL41RSS,&var19,&var21};
_S_andn  S_andn_65_1 = {array_m65_x_1,&iRM_2_,&var22};
_S_andn  S_andn_76_1 = {array_m76_x_1,&iRM_5_,&var23};
_S_bol  S_bol_46_1 = {&var12,&fEM_R0UL52RSS,&var24};
_S_bol  S_bol_51_1 = {&var12,&fEM_R0UL42RSS,&var25};
_S_bol  S_bol_62_1 = {&var12,&fEM_R0UN03RSS,&var26};
_S_bol  S_bol_61_1 = {&fEM_R0UL51RSS,&var19,&var27};
_S_react  S_react_58_1 = {&var19,&var28};
_S_bol  S_bol_41_1 = {&var12,&fEM_R0UR01RSS,&var29};


void ZeroVar()
{
   var1.f=0.0;
   var2.f=0.0;
   var3.f=0.0;
   var4.b=0;
   var5.b=0;
   var6.b=0;
   var7.b=0;
   var8.b=0;
   var9.b=0;
   var10.i=0;
   var11.f=0.0;
   var12.f=0.0;
   var13.b=0;
   var14.f=0.0;
   var15.f=0.0;
   var16.f=0.0;
   var17.i=0;
   var18.b=0;
   var19.f=0.0;
   var20.b=0;
   var21.b=0;
   var22.b=0;
   var23.b=0;
   var24.b=0;
   var25.b=0;
   var26.b=0;
   var27.b=0;
   var28.f=0.0;
   var29.b=0;
   vainSLong.l=0L;
   vainSFloat.f=0.0;
   vainSInt.i=0;
   vainSBool.b=0;
   vainSChar.c=0;

}
void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_78_1);
  diagndev(&S_diagndev_90_1);
  and2(&S_and2_92_1);
  or2(&S_or2_99_1);
  or2(&S_or2_107_1);
  ml(&S_ml_6_1);
  ml(&S_ml_7_1);
  ml(&S_ml_8_1);
  ocham(&S_ocham_22_1);
  orn(&S_orn_104_1);
  or3(&S_or3_101_1);
  noto(&S_noto_105_1);
  bol(&S_bol_41_1);
  bol(&S_bol_62_1);
  bol(&S_bol_51_1);
  bol(&S_bol_46_1);
  andn(&S_andn_76_1);
  period(&S_period_57_1);
  react(&S_react_58_1);
  bol(&S_bol_61_1);
  andn(&S_andn_65_1);
  bol(&S_bol_63_1);
  andn(&S_andn_66_1);
  setData(idTestDiagnAKNP3,&var6);
  setData(idTTLaknp3,&var10);
  setData(idR0DE3DLS3,&var4);
  setData(idR0DE3CLS3,&var5);
  setData(idA1EE01LS3,&var23);
  setData(idR0VN77LZ2,&var22);
  setData(idR0VN73LZ2,&var24);
  setData(idA0VN71LS3,&var29);
  setData(idR0IE02LS3,&var18);
  setData(idR0IE01LS3,&var18);
  setData(idR0VN15RS3,&var17);
  setData(idR0VN33RS3,&var16);
  setData(idR0VN23RS3,&var15);
  setData(idR0VN13RS3,&var14);
  setData(idA0EE02LS3,&var13);
  setData(idA1VN71LS3,&var29);
  setData(idR0VN04RS3,&var28);
  setData(idR0VN03RS3,&var11);
  setData(idA0EE01LS3,&var23);
  setData(idR0VN77LZ1,&var22);
  setData(idR0VN65LS3,&var20);
  setData(idR0VN73LZ1,&var24);
  setData(idR0VN61LS3,&var25);
  setData(idR0VN01RS3,&var19);
  setData(idR0VN02RS3,&var12);

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
