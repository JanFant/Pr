#ifndef AKNP1_H
#define AKNP1_H
// Подсистема AKNP1:AKNP1
static char SimulOn=0;
static short CodeSub=3;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=50;	 // Время цикла в ms
float takt, taktScheme=0, taktSS=0;
#define SIZE_BUFFER 406
static char BUFFER[406];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.51\0", 5432, "192.168.10.151\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0DE02LS1	 BUFFER[0]	//(vchs:02 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 2 месте
#define idR0DE02LS1	 1	//(vchs:02 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 2 месте
#define R0DE04LS1	 BUFFER[3]	//(vds32:04 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 4 месте
#define idR0DE04LS1	 2	//(vds32:04 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 4 месте
#define R0DE05LS1	 BUFFER[6]	//(fds16:05 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 5 месте
#define idR0DE05LS1	 3	//(fds16:05 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 5 месте
#define TTLaknp1	 BUFFER[9]	//( - , AKNP1) ttl
#define idTTLaknp1	 4	//( - , AKNP1) ttl
#define R0DE31LS1	 BUFFER[12]	//(sbk:20 - S01SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 1
#define idR0DE31LS1	 5	//(sbk:20 - S01SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 1
#define R0DE32LS1	 BUFFER[14]	//(sbk:20 - S02SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 2
#define idR0DE32LS1	 6	//(sbk:20 - S02SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 2
#define R0DE33LS1	 BUFFER[16]	//(sbk:20 - S03SBK, DiagnAKNP1) диагностика шкафа АКНП1 двери
#define idR0DE33LS1	 7	//(sbk:20 - S03SBK, DiagnAKNP1) диагностика шкафа АКНП1 двери
#define R0DE34LS1	 BUFFER[18]	//(sbk:20 - S04SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура меньше 43
#define idR0DE34LS1	 8	//(sbk:20 - S04SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура меньше 43
#define R0DE35LS1	 BUFFER[20]	//(sbk:20 - S05SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура больше 53
#define idR0DE35LS1	 9	//(sbk:20 - S05SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура больше 53
#define R0DE37LS1	 BUFFER[22]	//(sbk:20 - S07SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3.1 место 2
#define idR0DE37LS1	 10	//(sbk:20 - S07SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3.1 место 2
#define R0DE38LS1	 BUFFER[24]	//(sbk:20 - S08SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3 место 3
#define idR0DE38LS1	 11	//(sbk:20 - S08SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3 место 3
#define R0DE39LS1	 BUFFER[26]	//(sbk:20 - S09SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП24-2 место 4
#define idR0DE39LS1	 12	//(sbk:20 - S09SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП24-2 место 4
#define R0DE3CLS1	 BUFFER[28]	//( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 7
#define idR0DE3CLS1	 13	//( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 7
#define R0DE3DLS1	 BUFFER[30]	//( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 8
#define idR0DE3DLS1	 14	//( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 8
#define TestDiagnAKNP1	 BUFFER[32]	//( - , AKNP1) Неисправность от диагностики
#define idTestDiagnAKNP1	 15	//( - , AKNP1) Неисправность от диагностики
#define R0DEB1LS1	 BUFFER[34]	//(sbk:20 - S10SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 7
#define idR0DEB1LS1	 16	//(sbk:20 - S10SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 7
#define R0DEB2LS1	 BUFFER[36]	//(sbk:20 - S11SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 7
#define idR0DEB2LS1	 17	//(sbk:20 - S11SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 7
#define R0DEB4LS1	 BUFFER[38]	//(sbk:20 - S13SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 8
#define idR0DEB4LS1	 18	//(sbk:20 - S13SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 8
#define R0DEB3LS1	 BUFFER[40]	//(sbk:20 - S12SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 8
#define idR0DEB3LS1	 19	//(sbk:20 - S12SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 8
#define R0IN01FS1	 BUFFER[42]	//(vchs:01 - K01VCHS, - ) Выход СНМ-11 Гц
#define idR0IN01FS1	 20	//(vchs:01 - K01VCHS, - ) Выход СНМ-11 Гц
#define R0IN02FI1	 BUFFER[47]	//( - , MA1S) Выход КНК15-1 Гц
#define idR0IN02FI1	 21	//( - , MA1S) Выход КНК15-1 Гц
#define R0IN03FS1	 BUFFER[52]	//(vchs:02 - K01VCHS, - ) Выход КНК53М Гц
#define idR0IN03FS1	 22	//(vchs:02 - K01VCHS, - ) Выход КНК53М Гц
#define R0IS01FI0	 BUFFER[57]	//( - , MA1S) Признак работы с имитатором
#define idR0IS01FI0	 23	//( - , MA1S) Признак работы с имитатором
#define R0IN01FI1	 BUFFER[60]	//( - , MA1S) Выход СНМ-11 Гц
#define idR0IN01FI1	 24	//( - , MA1S) Выход СНМ-11 Гц
#define R0IN02FS1	 BUFFER[65]	//(vchs:01 - K02VCHS, - ) Выход КНК15-1 Гц
#define idR0IN02FS1	 25	//(vchs:01 - K02VCHS, - ) Выход КНК15-1 Гц
#define R0IN03FI1	 BUFFER[70]	//( - , MA1S) Выход КНК53М Гц
#define idR0IN03FI1	 26	//( - , MA1S) Выход КНК53М Гц
#define B8IC01UDU	 BUFFER[75]	//( - , MA1S) Координата АЗ2 (дел. енк)
#define idB8IC01UDU	 27	//( - , MA1S) Координата АЗ2 (дел. енк)
#define R0VN02RS1	 BUFFER[80]	//( - , A1Bz1, A1Bz2) Уровень мощности
#define idR0VN02RS1	 28	//( - , A1Bz1, A1Bz2) Уровень мощности
#define R0VN01RS1	 BUFFER[85]	//( - , A1Bz1, A1Bz2) Период разгона канал1
#define idR0VN01RS1	 29	//( - , A1Bz1, A1Bz2) Период разгона канал1
#define R0VN61LS1	 BUFFER[90]	//( - , A1Bz1, A1Bz2) ПС по мощности канал1
#define idR0VN61LS1	 30	//( - , A1Bz1, A1Bz2) ПС по мощности канал1
#define R0VN71LZ1	 BUFFER[92]	//(fds16:05 - K09FDSR, - ) АС по мощности на БАЗ1
#define idR0VN71LZ1	 31	//(fds16:05 - K09FDSR, - ) АС по мощности на БАЗ1
#define R0VN65LS1	 BUFFER[94]	//( - , A1Bz1, A1Bz2) ПС по периоду разгона канал1
#define idR0VN65LS1	 32	//( - , A1Bz1, A1Bz2) ПС по периоду разгона канал1
#define R0VN75LZ1	 BUFFER[96]	//(fds16:05 - K10FDSR, - ) АС по периоду разгонана БАЗ1
#define idR0VN75LZ1	 33	//(fds16:05 - K10FDSR, - ) АС по периоду разгонана БАЗ1
#define A0EE01LS1	 BUFFER[98]	//(fds16:05 - K11FDSR, - ) Исправность АКНП1 на БАЗ1
#define idA0EE01LS1	 34	//(fds16:05 - K11FDSR, - ) Исправность АКНП1 на БАЗ1
#define R0VN03RS1	 BUFFER[100]	//( - , AKNP1) Измеренный нейтронный поток
#define idR0VN03RS1	 35	//( - , AKNP1) Измеренный нейтронный поток
#define R0VN04RS1	 BUFFER[105]	//( - , AKNP1) Реактивность канал1
#define idR0VN04RS1	 36	//( - , AKNP1) Реактивность канал1
#define A0VN71LS1	 BUFFER[110]	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ на БАЗ1
#define idA0VN71LS1	 37	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ на БАЗ1
#define A0EE02LS1	 BUFFER[112]	//( - , AKNP1) Исправность АКНП1 (от сшивки каналов) канал 1
#define idA0EE02LS1	 38	//( - , AKNP1) Исправность АКНП1 (от сшивки каналов) канал 1
#define R0IE11LS1	 BUFFER[114]	//(vds32:04 - K01VDSR, - ) Исправность ВИП 1,6 (№8) СНМ11 1 канала
#define idR0IE11LS1	 39	//(vds32:04 - K01VDSR, - ) Исправность ВИП 1,6 (№8) СНМ11 1 канала
#define R0IE12LS1	 BUFFER[116]	//(vds32:04 - K02VDSR, - ) Исправность ВИП 0,5 (№9) КНК15-1 1 канала
#define idR0IE12LS1	 40	//(vds32:04 - K02VDSR, - ) Исправность ВИП 0,5 (№9) КНК15-1 1 канала
#define R0IE13LS1	 BUFFER[118]	//(vds32:04 - K03VDSR, - ) Исправность ВИП 0,5 (№10) КНК53М 1 канала
#define idR0IE13LS1	 41	//(vds32:04 - K03VDSR, - ) Исправность ВИП 0,5 (№10) КНК53М 1 канала
#define R0VN13RS1	 BUFFER[120]	//( - , AKNP1) Нейтронный поток по камере СНМ11
#define idR0VN13RS1	 42	//( - , AKNP1) Нейтронный поток по камере СНМ11
#define R0VN23RS1	 BUFFER[125]	//( - , AKNP1) Нейтронный поток по камере КНК15-1
#define idR0VN23RS1	 43	//( - , AKNP1) Нейтронный поток по камере КНК15-1
#define R0VN33RS1	 BUFFER[130]	//( - , AKNP1) Нейтронный поток по камере КНК53М
#define idR0VN33RS1	 44	//( - , AKNP1) Нейтронный поток по камере КНК53М
#define R0VN15RS1	 BUFFER[135]	//( - , AKNP1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
#define idR0VN15RS1	 45	//( - , AKNP1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
#define R0IE01LS1	 BUFFER[138]	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов 1 канала
#define idR0IE01LS1	 46	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов 1 канала
#define R0IE02LS1	 BUFFER[140]	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ 1 канала
#define idR0IE02LS1	 47	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ 1 канала
#define R0VN71LZ2	 BUFFER[142]	//(fds16:05 - K13FDSR, - ) АС по мощности на БАЗ2
#define idR0VN71LZ2	 48	//(fds16:05 - K13FDSR, - ) АС по мощности на БАЗ2
#define R0VN75LZ2	 BUFFER[144]	//(fds16:05 - K14FDSR, - ) АС по периоду разгонана БАЗ2
#define idR0VN75LZ2	 49	//(fds16:05 - K14FDSR, - ) АС по периоду разгонана БАЗ2
#define A1EE01LS1	 BUFFER[146]	//(fds16:05 - K15FDSR, - ) Исправность АКНП1 на БАЗ2
#define idA1EE01LS1	 50	//(fds16:05 - K15FDSR, - ) Исправность АКНП1 на БАЗ2
#define A1VN71LS1	 BUFFER[148]	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ на БАЗ2
#define idA1VN71LS1	 51	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ на БАЗ2
#define B8VC01RDU	 BUFFER[150]	//( - , AKNP1) Координата АЗ2, мм
#define idB8VC01RDU	 52	//( - , AKNP1) Координата АЗ2, мм
#define R0EE01LZ1	 BUFFER[155]	//( - , AKNP1) Питание  АКНП1  отключить
#define idR0EE01LZ1	 53	//( - , AKNP1) Питание  АКНП1  отключить
#define R0EE01LZ2	 BUFFER[157]	//( - , AKNP1) Питание  АКНП1  отключить
#define idR0EE01LZ2	 54	//( - , AKNP1) Питание  АКНП1  отключить
#define R0DE01LS1	 BUFFER[159]	//(vchs:01 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 1 месте
#define idR0DE01LS1	 55	//(vchs:01 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 1 месте
#define fEM_R0UR01RSS	 BUFFER[162]	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RSS	 56	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R0UL52RSS	 BUFFER[167]	//(R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	 57	//(R0UL52RSS) Уровень АС по мощности
#define fEM_R0UL41RSS	 BUFFER[172]	//(R0UL41RSS) Уровень ПС по периоду разгона
#define idfEM_R0UL41RSS	 58	//(R0UL41RSS) Уровень ПС по периоду разгона
#define fEM_R0UL51RSS	 BUFFER[177]	//(R0UL51RSS) Уровень АС по периоду разгона
#define idfEM_R0UL51RSS	 59	//(R0UL51RSS) Уровень АС по периоду разгона
#define fEM_R0UH02RSS	 BUFFER[182]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define idfEM_R0UH02RSS	 60	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define fEM_R0UH03RSS	 BUFFER[187]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define idfEM_R0UH03RSS	 61	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define fEM_R0UL42RSS	 BUFFER[192]	//(R0UL42RSS) Уровень ПС по мощности
#define idfEM_R0UL42RSS	 62	//(R0UL42RSS) Уровень ПС по мощности
#define fEM_R7UX00RSS	 BUFFER[197]	//(R7UX00RSS) X-координата АЗ1 (см)
#define idfEM_R7UX00RSS	 63	//(R7UX00RSS) X-координата АЗ1 (см)
#define fEM_R7UX01RSS	 BUFFER[202]	//(R7UX01RSS) X-координата камеры R7IN11
#define idfEM_R7UX01RSS	 64	//(R7UX01RSS) X-координата камеры R7IN11
#define fEM_R7UX02RSS	 BUFFER[207]	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define idfEM_R7UX02RSS	 65	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define fEM_R7UX03RSS	 BUFFER[212]	//(R7UX03RSS) X-координата камеры R7IN13 (см)
#define idfEM_R7UX03RSS	 66	//(R7UX03RSS) X-координата камеры R7IN13 (см)
#define fEM_R7UY00RSS	 BUFFER[217]	//(R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	 67	//(R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UY01RSS	 BUFFER[222]	//(R7UY01RSS) Y-координата камеры R7IN11
#define idfEM_R7UY01RSS	 68	//(R7UY01RSS) Y-координата камеры R7IN11
#define fEM_R7UY02RSS	 BUFFER[227]	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define idfEM_R7UY02RSS	 69	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define fEM_R7UY03RSS	 BUFFER[232]	//(R7UY03RSS) Y-координата камеры R7IN13 (см)
#define idfEM_R7UY03RSS	 70	//(R7UY03RSS) Y-координата камеры R7IN13 (см)
#define fEM_A0UX00RSS	 BUFFER[237]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 71	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX01RSS	 BUFFER[242]	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define idfEM_A0UX01RSS	 72	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define fEM_A0UX02RSS	 BUFFER[247]	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define idfEM_A0UX02RSS	 73	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define fEM_A0UX03RSS	 BUFFER[252]	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define idfEM_A0UX03RSS	 74	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define fEM_B0UX01RSS	 BUFFER[257]	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define idfEM_B0UX01RSS	 75	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define fEM_B0UX02RSS	 BUFFER[262]	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define idfEM_B0UX02RSS	 76	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define fEM_B0UX03RSS	 BUFFER[267]	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	 77	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_R0UH05RSS	 BUFFER[272]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 78	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UN03RSS	 BUFFER[277]	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN03RSS	 79	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R0UL01RSS	 BUFFER[282]	//(R0UL01RSS) Шаг (мс) измерения периода
#define idfEM_R0UL01RSS	 80	//(R0UL01RSS) Шаг (мс) измерения периода
#define fEM_R0UL02RSS	 BUFFER[287]	//(R0UL02RSS) Предельное время ожидания роста потока (мс)
#define idfEM_R0UL02RSS	 81	//(R0UL02RSS) Предельное время ожидания роста потока (мс)
#define lEM_EE01LS1	 BUFFER[292]	//(EE01LS1) исправность АКНП1
#define idlEM_EE01LS1	 82	//(EE01LS1) исправность АКНП1
#define bFirstEnterFlag	 BUFFER[294]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 83	//(bFirstEnterFlag) 
#define internal1_m20_Nk	 BUFFER[296]	//(internal1_m20_Nk) Nk - ведущая камера
#define idinternal1_m20_Nk	 84	//(internal1_m20_Nk) Nk - ведущая камера
#define internal1_m55_tst	 BUFFER[299]	//(internal1_m55_tst) - массив времени фиксации стартовой мощности
#define idinternal1_m55_tst	 85	//(internal1_m55_tst) - массив времени фиксации стартовой мощности
#define internal1_m55_trz	 BUFFER[324]	//(internal1_m55_trz) - массив времени фиксации очередного периода
#define idinternal1_m55_trz	 86	//(internal1_m55_trz) - массив времени фиксации очередного периода
#define internal1_m55_N1	 BUFFER[349]	//(internal1_m55_N1) - массив значения мощности в начале замера
#define idinternal1_m55_N1	 87	//(internal1_m55_N1) - массив значения мощности в начале замера
#define internal1_m55_N2	 BUFFER[374]	//(internal1_m55_N2) - массив значения мощности в конце замера
#define idinternal1_m55_N2	 88	//(internal1_m55_N2) - массив значения мощности в конце замера
#define internal1_m55_Period0	 BUFFER[399]	//(internal1_m55_Period0) Per - Период разгона РУ
#define idinternal1_m55_Period0	 89	//(internal1_m55_Period0) Per - Период разгона РУ
#define internal1_m55_MyFirstEnterFlag	 BUFFER[404]	//(internal1_m55_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m55_MyFirstEnterFlag	 90	//(internal1_m55_MyFirstEnterFlag)  FirstEnterFlag
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,3	,1	, &R0DE02LS1},	//(vchs:02 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 2 месте
	{ 2	,3	,1	, &R0DE04LS1},	//(vds32:04 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 4 месте
	{ 3	,3	,1	, &R0DE05LS1},	//(fds16:05 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 5 месте
	{ 4	,3	,1	, &TTLaknp1},	//( - , AKNP1) ttl
	{ 5	,1	,1	, &R0DE31LS1},	//(sbk:20 - S01SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 1
	{ 6	,1	,1	, &R0DE32LS1},	//(sbk:20 - S02SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 2
	{ 7	,1	,1	, &R0DE33LS1},	//(sbk:20 - S03SBK, DiagnAKNP1) диагностика шкафа АКНП1 двери
	{ 8	,1	,1	, &R0DE34LS1},	//(sbk:20 - S04SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура меньше 43
	{ 9	,1	,1	, &R0DE35LS1},	//(sbk:20 - S05SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура больше 53
	{ 10	,1	,1	, &R0DE37LS1},	//(sbk:20 - S07SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3.1 место 2
	{ 11	,1	,1	, &R0DE38LS1},	//(sbk:20 - S08SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3 место 3
	{ 12	,1	,1	, &R0DE39LS1},	//(sbk:20 - S09SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП24-2 место 4
	{ 13	,1	,1	, &R0DE3CLS1},	//( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 7
	{ 14	,1	,1	, &R0DE3DLS1},	//( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 8
	{ 15	,1	,1	, &TestDiagnAKNP1},	//( - , AKNP1) Неисправность от диагностики
	{ 16	,1	,1	, &R0DEB1LS1},	//(sbk:20 - S10SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 7
	{ 17	,1	,1	, &R0DEB2LS1},	//(sbk:20 - S11SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 7
	{ 18	,1	,1	, &R0DEB4LS1},	//(sbk:20 - S13SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 8
	{ 19	,1	,1	, &R0DEB3LS1},	//(sbk:20 - S12SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 8
	{ 20	,8	,1	, &R0IN01FS1},	//(vchs:01 - K01VCHS, - ) Выход СНМ-11 Гц
	{ 21	,8	,1	, &R0IN02FI1},	//( - , MA1S) Выход КНК15-1 Гц
	{ 22	,8	,1	, &R0IN03FS1},	//(vchs:02 - K01VCHS, - ) Выход КНК53М Гц
	{ 23	,3	,1	, &R0IS01FI0},	//( - , MA1S) Признак работы с имитатором
	{ 24	,8	,1	, &R0IN01FI1},	//( - , MA1S) Выход СНМ-11 Гц
	{ 25	,8	,1	, &R0IN02FS1},	//(vchs:01 - K02VCHS, - ) Выход КНК15-1 Гц
	{ 26	,8	,1	, &R0IN03FI1},	//( - , MA1S) Выход КНК53М Гц
	{ 27	,5	,1	, &B8IC01UDU},	//( - , MA1S) Координата АЗ2 (дел. енк)
	{ 28	,8	,1	, &R0VN02RS1},	//( - , A1Bz1, A1Bz2) Уровень мощности
	{ 29	,8	,1	, &R0VN01RS1},	//( - , A1Bz1, A1Bz2) Период разгона канал1
	{ 30	,1	,1	, &R0VN61LS1},	//( - , A1Bz1, A1Bz2) ПС по мощности канал1
	{ 31	,1	,1	, &R0VN71LZ1},	//(fds16:05 - K09FDSR, - ) АС по мощности на БАЗ1
	{ 32	,1	,1	, &R0VN65LS1},	//( - , A1Bz1, A1Bz2) ПС по периоду разгона канал1
	{ 33	,1	,1	, &R0VN75LZ1},	//(fds16:05 - K10FDSR, - ) АС по периоду разгонана БАЗ1
	{ 34	,1	,1	, &A0EE01LS1},	//(fds16:05 - K11FDSR, - ) Исправность АКНП1 на БАЗ1
	{ 35	,8	,1	, &R0VN03RS1},	//( - , AKNP1) Измеренный нейтронный поток
	{ 36	,8	,1	, &R0VN04RS1},	//( - , AKNP1) Реактивность канал1
	{ 37	,1	,1	, &A0VN71LS1},	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ на БАЗ1
	{ 38	,1	,1	, &A0EE02LS1},	//( - , AKNP1) Исправность АКНП1 (от сшивки каналов) канал 1
	{ 39	,1	,1	, &R0IE11LS1},	//(vds32:04 - K01VDSR, - ) Исправность ВИП 1,6 (№8) СНМ11 1 канала
	{ 40	,1	,1	, &R0IE12LS1},	//(vds32:04 - K02VDSR, - ) Исправность ВИП 0,5 (№9) КНК15-1 1 канала
	{ 41	,1	,1	, &R0IE13LS1},	//(vds32:04 - K03VDSR, - ) Исправность ВИП 0,5 (№10) КНК53М 1 канала
	{ 42	,8	,1	, &R0VN13RS1},	//( - , AKNP1) Нейтронный поток по камере СНМ11
	{ 43	,8	,1	, &R0VN23RS1},	//( - , AKNP1) Нейтронный поток по камере КНК15-1
	{ 44	,8	,1	, &R0VN33RS1},	//( - , AKNP1) Нейтронный поток по камере КНК53М
	{ 45	,3	,1	, &R0VN15RS1},	//( - , AKNP1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
	{ 46	,1	,1	, &R0IE01LS1},	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов 1 канала
	{ 47	,1	,1	, &R0IE02LS1},	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ 1 канала
	{ 48	,1	,1	, &R0VN71LZ2},	//(fds16:05 - K13FDSR, - ) АС по мощности на БАЗ2
	{ 49	,1	,1	, &R0VN75LZ2},	//(fds16:05 - K14FDSR, - ) АС по периоду разгонана БАЗ2
	{ 50	,1	,1	, &A1EE01LS1},	//(fds16:05 - K15FDSR, - ) Исправность АКНП1 на БАЗ2
	{ 51	,1	,1	, &A1VN71LS1},	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ на БАЗ2
	{ 52	,8	,1	, &B8VC01RDU},	//( - , AKNP1) Координата АЗ2, мм
	{ 53	,1	,1	, &R0EE01LZ1},	//( - , AKNP1) Питание  АКНП1  отключить
	{ 54	,1	,1	, &R0EE01LZ2},	//( - , AKNP1) Питание  АКНП1  отключить
	{ 55	,3	,1	, &R0DE01LS1},	//(vchs:01 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 1 месте
	{ 56	,8	,1	, &fEM_R0UR01RSS},	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
	{ 57	,8	,1	, &fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{ 58	,8	,1	, &fEM_R0UL41RSS},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{ 59	,8	,1	, &fEM_R0UL51RSS},	//(R0UL51RSS) Уровень АС по периоду разгона
	{ 60	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{ 61	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{ 62	,8	,1	, &fEM_R0UL42RSS},	//(R0UL42RSS) Уровень ПС по мощности
	{ 63	,8	,1	, &fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{ 64	,8	,1	, &fEM_R7UX01RSS},	//(R7UX01RSS) X-координата камеры R7IN11
	{ 65	,8	,1	, &fEM_R7UX02RSS},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{ 66	,8	,1	, &fEM_R7UX03RSS},	//(R7UX03RSS) X-координата камеры R7IN13 (см)
	{ 67	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{ 68	,8	,1	, &fEM_R7UY01RSS},	//(R7UY01RSS) Y-координата камеры R7IN11
	{ 69	,8	,1	, &fEM_R7UY02RSS},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{ 70	,8	,1	, &fEM_R7UY03RSS},	//(R7UY03RSS) Y-координата камеры R7IN13 (см)
	{ 71	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 72	,8	,1	, &fEM_A0UX01RSS},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{ 73	,8	,1	, &fEM_A0UX02RSS},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{ 74	,8	,1	, &fEM_A0UX03RSS},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{ 75	,8	,1	, &fEM_B0UX01RSS},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{ 76	,8	,1	, &fEM_B0UX02RSS},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{ 77	,8	,1	, &fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{ 78	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 79	,8	,1	, &fEM_R0UN03RSS},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 80	,8	,1	, &fEM_R0UL01RSS},	//(R0UL01RSS) Шаг (мс) измерения периода
	{ 81	,8	,1	, &fEM_R0UL02RSS},	//(R0UL02RSS) Предельное время ожидания роста потока (мс)
	{ 82	,1	,1	, &lEM_EE01LS1},	//(EE01LS1) исправность АКНП1
	{ 83	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 84	,3	,1	, &internal1_m20_Nk},	//(internal1_m20_Nk) Nk - ведущая камера
	{ 85	,8	,5	, &internal1_m55_tst},	//(internal1_m55_tst) - массив времени фиксации стартовой мощности
	{ 86	,8	,5	, &internal1_m55_trz},	//(internal1_m55_trz) - массив времени фиксации очередного периода
	{ 87	,8	,5	, &internal1_m55_N1},	//(internal1_m55_N1) - массив значения мощности в начале замера
	{ 88	,8	,5	, &internal1_m55_N2},	//(internal1_m55_N2) - массив значения мощности в конце замера
	{ 89	,8	,1	, &internal1_m55_Period0},	//(internal1_m55_Period0) Per - Период разгона РУ
	{ 90	,1	,1	, &internal1_m55_MyFirstEnterFlag},	//(internal1_m55_MyFirstEnterFlag)  FirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="aknp1.bin\0";   // Имя файла для сохранения констант
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
{64,"fEM_R7UX01RSS\0"}, 
{65,"fEM_R7UX02RSS\0"}, 
{66,"fEM_R7UX03RSS\0"}, 
{67,"fEM_R7UY00RSS\0"}, 
{68,"fEM_R7UY01RSS\0"}, 
{69,"fEM_R7UY02RSS\0"}, 
{70,"fEM_R7UY03RSS\0"}, 
{71,"fEM_A0UX00RSS\0"}, 
{72,"fEM_A0UX01RSS\0"}, 
{73,"fEM_A0UX02RSS\0"}, 
{74,"fEM_A0UX03RSS\0"}, 
{75,"fEM_B0UX01RSS\0"}, 
{76,"fEM_B0UX02RSS\0"}, 
{77,"fEM_B0UX03RSS\0"}, 
{78,"fEM_R0UH05RSS\0"}, 
{79,"fEM_R0UN03RSS\0"}, 
{80,"fEM_R0UL01RSS\0"}, 
{81,"fEM_R0UL02RSS\0"}, 
{82,"lEM_EE01LS1\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_AKNP1[]={  // 
	{&R0EE01LZ1,1,0},	//( - , AKNP1) Питание  АКНП1  отключить
	{&R0EE01LZ2,1,1},	//( - , AKNP1) Питание  АКНП1  отключить
	{&lEM_EE01LS1,1,2},	//( - , AKNP1) исправность АКНП1
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
	{&TTLaknp1,3,11},	//( - , AKNP1) ttl
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_AKNP1[]={  // 
	{&B8VC01RDU,8,0},	//( - , AKNP1) Координата АЗ2, мм
	{&fEM_R0UR01RSS,8,2},	//( - , AKNP1) Уставка АКНП ПС  АЗ по периоду (сек)
	{&fEM_R0UL52RSS,8,4},	//( - , AKNP1) Уровень АС по мощности
	{&fEM_R0UL41RSS,8,6},	//( - , AKNP1) Уровень ПС по периоду разгона
	{&fEM_R0UL51RSS,8,8},	//( - , AKNP1) Уровень АС по периоду разгона
	{&fEM_R0UH02RSS,8,10},	//( - , AKNP1) Коэфф. преобразования частота->нейтр/с КНК15-1
	{&fEM_R0UH03RSS,8,12},	//( - , AKNP1) Коэфф. преобразования частота->нейтр/с КНК53М
	{&fEM_R0UL42RSS,8,14},	//( - , AKNP1) Уровень ПС по мощности
	{&fEM_R7UX00RSS,8,16},	//( - , AKNP1) X-координата АЗ1 (см)
	{&fEM_R7UX01RSS,8,18},	//( - , AKNP1) X-координата камеры R7IN11
	{&fEM_R7UX02RSS,8,20},	//( - , AKNP1) X-координата камеры R7IN12 (см)
	{&fEM_R7UX03RSS,8,22},	//( - , AKNP1) X-координата камеры R7IN13 (см)
	{&fEM_R7UY00RSS,8,24},	//( - , AKNP1) Y-координата АЗ1 (см)
	{&fEM_R7UY01RSS,8,26},	//( - , AKNP1) Y-координата камеры R7IN11
	{&fEM_R7UY02RSS,8,28},	//( - , AKNP1) Y-координата камеры R7IN12 (см)
	{&fEM_R7UY03RSS,8,30},	//( - , AKNP1) Y-координата камеры R7IN13 (см)
	{&fEM_A0UX00RSS,8,32},	//( - , AKNP1) Эффективный радиус АЗ
	{&fEM_A0UX01RSS,8,34},	//( - , AKNP1) Первый коэффициент калибровки камеры 1
	{&fEM_A0UX02RSS,8,36},	//( - , AKNP1) Первый коэффициент калибровки камеры 2
	{&fEM_A0UX03RSS,8,38},	//( - , AKNP1) Первый коэффициент калибровки камеры 3
	{&fEM_B0UX01RSS,8,40},	//( - , AKNP1) Второй коэффициент калибровки камеры 1
	{&fEM_B0UX02RSS,8,42},	//( - , AKNP1) Второй коэффициент калибровки камеры 2
	{&fEM_B0UX03RSS,8,44},	//( - , AKNP1) Второй коэффициент калибровки камеры 3
	{&fEM_R0UH05RSS,8,46},	//( - , AKNP1) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_R0UN03RSS,8,48},	//( - , AKNP1) Нижняя граница интервала мощности для измерения периода (ватт)
	{&fEM_R0UL01RSS,8,50},	//( - , AKNP1) Шаг (мс) измерения периода
	{&fEM_R0UL02RSS,8,52},	//( - , AKNP1) Предельное время ожидания роста потока (мс)
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
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MA1S[]={  // 
	{&B8IC01UDU,5,0},	//( - , SDu, SA1, SA2, SA3, SA4, SRP) Координата АЗ2
	{&R0IN01FI1,8,2},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{&R0IN02FI1,8,4},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI1,8,6},	//( - , SA1) Выход КНК53М Гц от ПТИ
	{&R0IS01FI0,3,8},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
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
	{&R0IN02FS1,8,5},
	{&R0IN01FS1,8,0},
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
	{&R0IN03FS1,8,0},
	{&R0DE02LS1,3,10},
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
	{&R0IE13LS1,1,4},
	{&R0IE12LS1,1,2},
	{&R0IE11LS1,1,0},
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
	{&R0VN75LZ1,1,18},
	{&A0EE01LS1,1,20},
	{&A0VN71LS1,1,22},
	{&A1EE01LS1,1,28},
	{&R0VN75LZ2,1,26},
	{&R0VN71LZ2,1,24},
	{&R0IE01LS1,1,2},
	{&R0IE02LS1,1,0},
	{&R0VN71LZ1,1,16},
	{&A1VN71LS1,1,30},
	{&R0DE05LS1,3,38},
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
	{&R0DEB3LS1,1,22},
	{&R0DEB4LS1,1,24},
	{&R0DEB2LS1,1,20},
	{&R0DEB1LS1,1,18},
	{&R0DE39LS1,1,16},
	{&R0DE38LS1,1,14},
	{&R0DE37LS1,1,12},
	{&R0DE35LS1,1,8},
	{&R0DE34LS1,1,6},
	{&R0DE33LS1,1,4},
	{&R0DE32LS1,1,2},
	{&R0DE31LS1,1,0},
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
	setAsFloat(56,10);
	setAsFloat(57,5100);
	setAsFloat(58,20);
	setAsFloat(59,13.0);
	setAsFloat(60,3703.704 );
	setAsFloat(61,62500.0);
	setAsFloat(62,5000);
	setAsFloat(63,1567.36);
	setAsFloat(64,1585.0);
	setAsFloat(65,1796.0);
	setAsFloat(66,1269.0);
	setAsFloat(67,506.6);
	setAsFloat(68,248.0);
	setAsFloat(69,284.5);
	setAsFloat(70,256.0);
	setAsFloat(71,11.0);
	setAsFloat(72,1.0);
	setAsFloat(73,1.0);
	setAsFloat(74,1.0);
	setAsFloat(75,0);
	setAsFloat(76,0);
	setAsFloat(77,0);
	setAsFloat(78,32000.0);
	setAsFloat(79,0.005);
	setAsFloat(80,0.5);
	setAsFloat(81,100);
	setAsBool(82,1);
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

uspaint8 InternalBuf[112];

/* ����������� �������� ��� � ������*/
ssint iRM_5_ = {5,0}; /* n - N-����������� ������� x */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - �����. �������������� �������->�����/� ���-11 */ 
sschar bRM_2_ = {2,0}; /* type - ��� ������ ���-11 1- ��� ��1, 2- ��� ��2, >2 ��� */ 
ssint iRM_4_ = {4,0}; /* n - ����������� ������� �������� */ 
ssint iRM_2_ = {2,0}; /* n - N-����������� ������� x */ 
ssint iRM_1_ = {1,0}; /* x2 - ������ ��������� */ 
ssfloat fRM_0_0009765625 = {0.0009765625,0}; /*  */ 

uspaint8 SpaEEPROMBuf[132];

/* ����������� ���������� */
ssfloat var1;
ssbool var2;
ssfloat var3;
ssfloat var4;
ssfloat var5;
ssint var6;
ssbool var7;
ssbool var8;
ssbool var9;
ssbool var10;
ssbool var11;
ssbool var12;
ssint var13;
ssbool var14;
ssbool var15;
ssfloat var16;
ssfloat var17;
ssbool var18;
ssfloat var19;
ssfloat var20;
ssfloat var21;
ssint var22;
ssbool var23;
ssfloat var24;
ssbool var25;
ssbool var26;
ssbool var27;
ssbool var28;
ssbool var29;
ssfloat var30;
ssbool var31;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* ���������� �������� */
psbool  array_m72_x_1[5] = {&var2,&var18,&R0IE13LS1,&R0IE12LS1,&R0IE11LS1};
psfloat  array_m9_x_1[2] = {&R0IN03FS1,&R0IN03FI1};
psfloat  array_m8_x_1[2] = {&R0IN02FS1,&R0IN02FI1};
psfloat  array_m7_x_1[2] = {&R0IN01FS1,&R0IN01FI1};
psbool  array_m100_x_1[5] = {&var8,&var7,&R0DE37LS1,&R0DE38LS1,&R0DE39LS1};
psint  array_m90_x_1[4] = {&R0DE01LS1,&R0DE02LS1,&R0DE04LS1,&R0DE05LS1};
psfloat  array_m55_tst_1[5];
psfloat  array_m55_trz_1[5];
psfloat  array_m55_N1_1[5];
psfloat  array_m55_N2_1[5];

/* ���������� �������� */
_S_ampll  S_ampll_46_1 = {&B8IC01UDU,&fRM_0_0009765625,&var1};
_S_noto  S_noto_104_1 = {&var10,&var2};
_S_andn  S_andn_72_1 = {array_m72_x_1,&iRM_5_,&vainSBool};
_S_ma  S_ma_9_1 = {array_m9_x_1,&var6,&iRM_2_,&var3};
_S_ma  S_ma_8_1 = {array_m8_x_1,&var6,&iRM_2_,&var4};
_S_ma  S_ma_7_1 = {array_m7_x_1,&var6,&iRM_2_,&var5};
_S_fsumz  S_fsumz_2_1 = {&R0IS01FI0,&iRM_1_,&var6};
_S_or2  S_or2_105_1 = {&R0DEB3LS1,&R0DEB4LS1,&var7};
_S_or2  S_or2_98_1 = {&R0DEB1LS1,&R0DEB2LS1,&var8};
_S_orn  S_orn_100_1 = {array_m100_x_1,&iRM_5_,&var9};
_S_or3  S_or3_103_1 = {&var12,&var11,&var9,&var10};
_S_and2  S_and2_92_1 = {&R0DE31LS1,&R0DE32LS1,&var11};
_S_diagndev  S_diagndev_90_1 = {array_m90_x_1,&iRM_4_,&var12,&var13};
_S_and2  S_and2_68_1 = {&var28,&var25,&var14};
_S_and2  S_and2_67_1 = {&var29,&var28,&var15};
_S_ocham  S_ocham_20_1 = {&var5,&var4,&var3,&var1,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX01RSS,&fEM_B0UX01RSS,&fEM_A0UX02RSS,&fEM_B0UX02RSS,&fEM_A0UX03RSS,&fEM_B0UX03RSS,&fEM_R7UX01RSS,&fEM_R7UY01RSS,&fEM_R7UX02RSS,&fEM_R7UY02RSS,&fEM_R7UX03RSS,&fEM_R7UY03RSS,&bRM_2_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var16,&var17,&var18,&var19,&var20,&var21,&var22,&internal1_m20_Nk};
_S_or2  S_or2_78_1 = {&R0EE01LZ1,&R0EE01LZ2,&var23};
_S_period  S_period_55_1 = {&var17,&lEM_EE01LS1,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var24,array_m55_tst_1,array_m55_trz_1,array_m55_N1_1,array_m55_N2_1,&internal1_m55_Period0,&internal1_m55_MyFirstEnterFlag};
_S_bol  S_bol_61_1 = {&fEM_R0UL41RSS,&var24,&var25};
_S_bol  S_bol_44_1 = {&var17,&fEM_R0UL52RSS,&var26};
_S_bol  S_bol_38_1 = {&var17,&fEM_R0UL42RSS,&var27};
_S_bol  S_bol_60_1 = {&var17,&fEM_R0UN03RSS,&var28};
_S_bol  S_bol_59_1 = {&fEM_R0UL51RSS,&var24,&var29};
_S_react  S_react_56_1 = {&var24,&var30};
_S_bol  S_bol_49_1 = {&var17,&fEM_R0UR01RSS,&var31};


void ZeroVar()
{
   var1.f=0.0;
   var2.b=0;
   var3.f=0.0;
   var4.f=0.0;
   var5.f=0.0;
   var6.i=0;
   var7.b=0;
   var8.b=0;
   var9.b=0;
   var10.b=0;
   var11.b=0;
   var12.b=0;
   var13.i=0;
   var14.b=0;
   var15.b=0;
   var16.f=0.0;
   var17.f=0.0;
   var18.b=0;
   var19.f=0.0;
   var20.f=0.0;
   var21.f=0.0;
   var22.i=0;
   var23.b=0;
   var24.f=0.0;
   var25.b=0;
   var26.b=0;
   var27.b=0;
   var28.b=0;
   var29.b=0;
   var30.f=0.0;
   var31.b=0;
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
  or2(&S_or2_98_1);
  or2(&S_or2_105_1);
  fsumz(&S_fsumz_2_1);
  ma(&S_ma_7_1);
  ma(&S_ma_8_1);
  ma(&S_ma_9_1);
  ampll(&S_ampll_46_1);
  ocham(&S_ocham_20_1);
  orn(&S_orn_100_1);
  bol(&S_bol_49_1);
  bol(&S_bol_60_1);
  bol(&S_bol_38_1);
  bol(&S_bol_44_1);
  period(&S_period_55_1);
  or3(&S_or3_103_1);
  noto(&S_noto_104_1);
  react(&S_react_56_1);
  bol(&S_bol_59_1);
  bol(&S_bol_61_1);
  and2(&S_and2_67_1);
  and2(&S_and2_68_1);
  andn(&S_andn_72_1);
  setData(idTestDiagnAKNP1,&var10);
  setData(idR0DE3DLS1,&var7);
  setData(idR0DE3CLS1,&var8);
  setData(idTTLaknp1,&var13);
  setData(idA1VN71LS1,&var31);
  setData(idA1EE01LS1,&lEM_EE01LS1);
  setData(idR0VN75LZ2,&var15);
  setData(idR0VN71LZ2,&var26);
  setData(idR0IE02LS1,&var23);
  setData(idR0IE01LS1,&var23);
  setData(idR0VN15RS1,&var22);
  setData(idR0VN33RS1,&var21);
  setData(idR0VN23RS1,&var20);
  setData(idR0VN13RS1,&var19);
  setData(idA0EE02LS1,&var18);
  setData(idA0VN71LS1,&var31);
  setData(idR0VN04RS1,&var30);
  setData(idR0VN03RS1,&var16);
  setData(idA0EE01LS1,&lEM_EE01LS1);
  setData(idR0VN75LZ1,&var15);
  setData(idR0VN65LS1,&var14);
  setData(idR0VN71LZ1,&var26);
  setData(idR0VN61LS1,&var27);
  setData(idR0VN01RS1,&var24);
  setData(idR0VN02RS1,&var17);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<5;i++ )
    array_m55_tst_1[i] = &(&internal1_m55_tst)[i*5];
  for( i=0;i<5;i++ )
    array_m55_trz_1[i] = &(&internal1_m55_trz)[i*5];
  for( i=0;i<5;i++ )
    array_m55_N1_1[i] = &(&internal1_m55_N1)[i*5];
  for( i=0;i<5;i++ )
    array_m55_N2_1[i] = &(&internal1_m55_N2)[i*5];
}

void MainCycle(void)
{
     Scheme();

}
#endif
