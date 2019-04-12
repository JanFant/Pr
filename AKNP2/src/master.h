#ifndef AKNP2_H
#define AKNP2_H
// Подсистема AKNP2:AKNP2
static char SimulOn=0;
static short CodeSub=9;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=50;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 399
static char BUFFER[399];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.57\0", 5432, "192.168.10.157\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0DE01LS2	 BUFFER[0]	//(vchs:01 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 1 месте
#define idR0DE01LS2	 1	//(vchs:01 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 1 месте
#define R0DE02LS2	 BUFFER[3]	//(vchs:02 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 2 месте
#define idR0DE02LS2	 2	//(vchs:02 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 2 месте
#define R0DE04LS2	 BUFFER[6]	//(vds32:04 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 4 месте
#define idR0DE04LS2	 3	//(vds32:04 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 4 месте
#define R0DE05LS2	 BUFFER[9]	//(fds16:05 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 5 месте
#define idR0DE05LS2	 4	//(fds16:05 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 5 месте
#define TTLaknp2	 BUFFER[12]	//( - , AKNP2) TTL
#define idTTLaknp2	 5	//( - , AKNP2) TTL
#define R0DE31LS2	 BUFFER[15]	//(sbk:20 - S01SBK, DiagnAKNP2) диагностика шкафа АКНП2 сеть 1
#define idR0DE31LS2	 6	//(sbk:20 - S01SBK, DiagnAKNP2) диагностика шкафа АКНП2 сеть 1
#define R0DE32LS2	 BUFFER[17]	//(sbk:20 - S02SBK, DiagnAKNP2) диагностика шкафа АКНП2 сеть 2
#define idR0DE32LS2	 7	//(sbk:20 - S02SBK, DiagnAKNP2) диагностика шкафа АКНП2 сеть 2
#define R0DE33LS2	 BUFFER[19]	//(sbk:20 - S03SBK, DiagnAKNP2) диагностика шкафа АКНП2 двери
#define idR0DE33LS2	 8	//(sbk:20 - S03SBK, DiagnAKNP2) диагностика шкафа АКНП2 двери
#define R0DE34LS2	 BUFFER[21]	//(sbk:20 - S04SBK, DiagnAKNP2) диагностика шкафа АКНП2 температура меньше 43
#define idR0DE34LS2	 9	//(sbk:20 - S04SBK, DiagnAKNP2) диагностика шкафа АКНП2 температура меньше 43
#define R0DE35LS2	 BUFFER[23]	//(sbk:20 - S05SBK, DiagnAKNP2) диагностика шкафа АКНП2 температура больше 53
#define idR0DE35LS2	 10	//(sbk:20 - S05SBK, DiagnAKNP2) диагностика шкафа АКНП2 температура больше 53
#define R0DE37LS2	 BUFFER[25]	//(sbk:20 - S07SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП15-3.1 место 2
#define idR0DE37LS2	 11	//(sbk:20 - S07SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП15-3.1 место 2
#define R0DE38LS2	 BUFFER[27]	//(sbk:20 - S08SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП15-3 место 3
#define idR0DE38LS2	 12	//(sbk:20 - S08SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП15-3 место 3
#define R0DE39LS2	 BUFFER[29]	//(sbk:20 - S09SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП24-2 место 4
#define idR0DE39LS2	 13	//(sbk:20 - S09SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП24-2 место 4
#define R0DE3CLS2	 BUFFER[31]	//( - , DiagnAKNP2) диагностика шкафа АКНП2 БП5/24Д место 7
#define idR0DE3CLS2	 14	//( - , DiagnAKNP2) диагностика шкафа АКНП2 БП5/24Д место 7
#define R0DE3DLS2	 BUFFER[33]	//( - , DiagnAKNP2) диагностика шкафа АКНП2 БП5/24Д место 8
#define idR0DE3DLS2	 15	//( - , DiagnAKNP2) диагностика шкафа АКНП2 БП5/24Д место 8
#define TestDiagnAKNP2	 BUFFER[35]	//( - , AKNP2) Неисправность от диагностики
#define idTestDiagnAKNP2	 16	//( - , AKNP2) Неисправность от диагностики
#define R0DEB1LS2	 BUFFER[37]	//(sbk:20 - S10SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП5 место 7
#define idR0DEB1LS2	 17	//(sbk:20 - S10SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП5 место 7
#define R0DEB2LS2	 BUFFER[39]	//(sbk:20 - S11SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП24Д место 7
#define idR0DEB2LS2	 18	//(sbk:20 - S11SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП24Д место 7
#define R0DEB3LS2	 BUFFER[41]	//(sbk:20 - S12SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП5 место 8
#define idR0DEB3LS2	 19	//(sbk:20 - S12SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП5 место 8
#define R0DEB4LS2	 BUFFER[43]	//(sbk:20 - S13SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП24Д место 8
#define idR0DEB4LS2	 20	//(sbk:20 - S13SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП24Д место 8
#define R0IN01FS2	 BUFFER[45]	//(vchs:01 - K01VCHS, - ) Выход СНМ-11 Гц
#define idR0IN01FS2	 21	//(vchs:01 - K01VCHS, - ) Выход СНМ-11 Гц
#define R0IN02FI2	 BUFFER[50]	//( - , MA2S) Выход КНК15-1 Гц
#define idR0IN02FI2	 22	//( - , MA2S) Выход КНК15-1 Гц
#define R0IN03FS2	 BUFFER[55]	//(vchs:02 - K01VCHS, - ) Выход КНК53М Гц
#define idR0IN03FS2	 23	//(vchs:02 - K01VCHS, - ) Выход КНК53М Гц
#define R0IS01FI0	 BUFFER[60]	//( - , MA2S) Признак работы с имитатором
#define idR0IS01FI0	 24	//( - , MA2S) Признак работы с имитатором
#define R0IN01FI2	 BUFFER[63]	//( - , MA2S) Выход СНМ-11 Гц
#define idR0IN01FI2	 25	//( - , MA2S) Выход СНМ-11 Гц
#define R0IN02FS2	 BUFFER[68]	//(vchs:01 - K02VCHS, - ) Выход КНК15-1 Гц
#define idR0IN02FS2	 26	//(vchs:01 - K02VCHS, - ) Выход КНК15-1 Гц
#define R0IN03FI2	 BUFFER[73]	//( - , MA2S) Выход КНК53М Гц
#define idR0IN03FI2	 27	//( - , MA2S) Выход КНК53М Гц
#define R0VN02RS2	 BUFFER[78]	//( - , A2Bz1, A2Bz2) Уровень мощности канал 2
#define idR0VN02RS2	 28	//( - , A2Bz1, A2Bz2) Уровень мощности канал 2
#define R0VN01RS2	 BUFFER[83]	//( - , A2Bz1, A2Bz2) Период разгона канал 2
#define idR0VN01RS2	 29	//( - , A2Bz1, A2Bz2) Период разгона канал 2
#define R0VN61LS2	 BUFFER[88]	//( - , A2Bz1, A2Bz2) ПС по мощности канал 2
#define idR0VN61LS2	 30	//( - , A2Bz1, A2Bz2) ПС по мощности канал 2
#define R0VN72LZ1	 BUFFER[90]	//(fds16:05 - K09FDSR, - ) АС по мощности канал 2 на БАЗ1
#define idR0VN72LZ1	 31	//(fds16:05 - K09FDSR, - ) АС по мощности канал 2 на БАЗ1
#define R0VN65LS2	 BUFFER[92]	//( - , A2Bz1, A2Bz2) ПС по периоду разгона канал 2
#define idR0VN65LS2	 32	//( - , A2Bz1, A2Bz2) ПС по периоду разгона канал 2
#define R0VN76LZ1	 BUFFER[94]	//(fds16:05 - K10FDSR, - ) АС по периоду разгона канал 2  на БАЗ1
#define idR0VN76LZ1	 33	//(fds16:05 - K10FDSR, - ) АС по периоду разгона канал 2  на БАЗ1
#define A0EE01LS2	 BUFFER[96]	//(fds16:05 - K11FDSR, - ) Исправность АКНП канал 2 на БАЗ1
#define idA0EE01LS2	 34	//(fds16:05 - K11FDSR, - ) Исправность АКНП канал 2 на БАЗ1
#define R0VN03RS2	 BUFFER[98]	//( - , AKNP2) Измеренный нейтронный поток канал 2
#define idR0VN03RS2	 35	//( - , AKNP2) Измеренный нейтронный поток канал 2
#define R0VN04RS2	 BUFFER[103]	//( - , AKNP2) Реактивность канал 2
#define idR0VN04RS2	 36	//( - , AKNP2) Реактивность канал 2
#define A1VN71LS2	 BUFFER[108]	//(fds16:05 - K16FDSR, - ) Блокировка автоматического подъёма ББ канал 2 на БАЗ2
#define idA1VN71LS2	 37	//(fds16:05 - K16FDSR, - ) Блокировка автоматического подъёма ББ канал 2 на БАЗ2
#define A0EE02LS2	 BUFFER[110]	//( - , AKNP2) Исправность АКНП2 (от сшивки каналов) канал 2
#define idA0EE02LS2	 38	//( - , AKNP2) Исправность АКНП2 (от сшивки каналов) канал 2
#define R0IE11LS2	 BUFFER[112]	//(vds32:04 - K01VDSR, - ) Исправность ВИП 1,6 (№11) СНМ11 2канала
#define idR0IE11LS2	 39	//(vds32:04 - K01VDSR, - ) Исправность ВИП 1,6 (№11) СНМ11 2канала
#define R0IE12LS2	 BUFFER[114]	//(vds32:04 - K02VDSR, - ) Исправность ВИП 0,5 (№12) КНК15-1 2 канала
#define idR0IE12LS2	 40	//(vds32:04 - K02VDSR, - ) Исправность ВИП 0,5 (№12) КНК15-1 2 канала
#define R0IE13LS2	 BUFFER[116]	//(vds32:04 - K03VDSR, - ) Исправность ВИП 0,5 (№13) КНК53М 2 канала
#define idR0IE13LS2	 41	//(vds32:04 - K03VDSR, - ) Исправность ВИП 0,5 (№13) КНК53М 2 канала
#define R0VN13RS2	 BUFFER[118]	//( - , AKNP2) Нейтронный поток по камере СНМ11 канал 2
#define idR0VN13RS2	 42	//( - , AKNP2) Нейтронный поток по камере СНМ11 канал 2
#define R0VN23RS2	 BUFFER[123]	//( - , AKNP2) Нейтронный поток по камере КНК15-1 канал 2
#define idR0VN23RS2	 43	//( - , AKNP2) Нейтронный поток по камере КНК15-1 канал 2
#define R0VN33RS2	 BUFFER[128]	//( - , AKNP2) Нейтронный поток по камере КНК53М канал 2
#define idR0VN33RS2	 44	//( - , AKNP2) Нейтронный поток по камере КНК53М канал 2
#define R0VN15RS2	 BUFFER[133]	//( - , AKNP2) Номер ведущей камеры канал 2
#define idR0VN15RS2	 45	//( - , AKNP2) Номер ведущей камеры канал 2
#define R0IE01LS2	 BUFFER[136]	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 2
#define idR0IE01LS2	 46	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 2
#define R0IE02LS2	 BUFFER[138]	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 2
#define idR0IE02LS2	 47	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 2
#define R0VN72LZ2	 BUFFER[140]	//(fds16:05 - K13FDSR, - ) АС по мощности канал 2 на БАЗ2
#define idR0VN72LZ2	 48	//(fds16:05 - K13FDSR, - ) АС по мощности канал 2 на БАЗ2
#define R0VN76LZ2	 BUFFER[142]	//(fds16:05 - K14FDSR, - ) АС по периоду разгона канал 2  на БАЗ2
#define idR0VN76LZ2	 49	//(fds16:05 - K14FDSR, - ) АС по периоду разгона канал 2  на БАЗ2
#define A1EE01LS2	 BUFFER[144]	//(fds16:05 - K15FDSR, - ) Исправность АКНП канал 2 на БАЗ2
#define idA1EE01LS2	 50	//(fds16:05 - K15FDSR, - ) Исправность АКНП канал 2 на БАЗ2
#define A0VN71LS2	 BUFFER[146]	//(fds16:05 - K12FDSR, - ) Блокировка автоматического подъёма ББ канал 2 на БАЗ1
#define idA0VN71LS2	 51	//(fds16:05 - K12FDSR, - ) Блокировка автоматического подъёма ББ канал 2 на БАЗ1
#define B8VC01RDU	 BUFFER[148]	//( - , AKNP2) Координата АЗ2, мм
#define idB8VC01RDU	 52	//( - , AKNP2) Координата АЗ2, мм
#define R0EE02LZ1	 BUFFER[153]	//( - , AKNP2) Питание  АКНП  отключить
#define idR0EE02LZ1	 53	//( - , AKNP2) Питание  АКНП  отключить
#define R0EE02LZ2	 BUFFER[155]	//( - , AKNP2) Питание  АКНП  отключить
#define idR0EE02LZ2	 54	//( - , AKNP2) Питание  АКНП  отключить
#define fEM_R0UR01RSS	 BUFFER[157]	//(R0UR01RSS) Уставка АКНП блокировки автоматического подъёма ББ(имп/сек)
#define idfEM_R0UR01RSS	 55	//(R0UR01RSS) Уставка АКНП блокировки автоматического подъёма ББ(имп/сек)
#define fEM_R0UL52RSS	 BUFFER[162]	//(R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	 56	//(R0UL52RSS) Уровень АС по мощности
#define fEM_R0UL41RSS	 BUFFER[167]	//(R0UL41RSS) Уровень ПС по периоду разгона
#define idfEM_R0UL41RSS	 57	//(R0UL41RSS) Уровень ПС по периоду разгона
#define fEM_R0UL51RSS	 BUFFER[172]	//(R0UL51RSS) Уровень АС по периоду разгона
#define idfEM_R0UL51RSS	 58	//(R0UL51RSS) Уровень АС по периоду разгона
#define fEM_R0UH02RSS	 BUFFER[177]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define idfEM_R0UH02RSS	 59	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define fEM_R0UH03RSS	 BUFFER[182]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define idfEM_R0UH03RSS	 60	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define fEM_R0UL42RSS	 BUFFER[187]	//(R0UL42RSS) Уровень ПС по мощности
#define idfEM_R0UL42RSS	 61	//(R0UL42RSS) Уровень ПС по мощности
#define fEM_R7UX00RSS	 BUFFER[192]	//(R7UX00RSS) X-координата АЗ1 (см)
#define idfEM_R7UX00RSS	 62	//(R7UX00RSS) X-координата АЗ1 (см)
#define fEM_R7UX04RSS	 BUFFER[197]	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define idfEM_R7UX04RSS	 63	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define fEM_R7UX05RSS	 BUFFER[202]	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define idfEM_R7UX05RSS	 64	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define fEM_R7UX06RSS	 BUFFER[207]	//(R7UX06RSS) Y-координата камеры R7IN23 (см)
#define idfEM_R7UX06RSS	 65	//(R7UX06RSS) Y-координата камеры R7IN23 (см)
#define fEM_R7UY00RSS	 BUFFER[212]	//(R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	 66	//(R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UY04RSS	 BUFFER[217]	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define idfEM_R7UY04RSS	 67	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define fEM_R7UY05RSS	 BUFFER[222]	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define idfEM_R7UY05RSS	 68	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define fEM_R7UY06RSS	 BUFFER[227]	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define idfEM_R7UY06RSS	 69	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define fEM_A0UX00RSS	 BUFFER[232]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 70	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX04RSS	 BUFFER[237]	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define idfEM_A0UX04RSS	 71	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define fEM_A0UX05RSS	 BUFFER[242]	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define idfEM_A0UX05RSS	 72	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define fEM_A0UX06RSS	 BUFFER[247]	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define idfEM_A0UX06RSS	 73	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define fEM_B0UX04RSS	 BUFFER[252]	//(B0UX04RSS) Второй коэффициент калибровки камеры4
#define idfEM_B0UX04RSS	 74	//(B0UX04RSS) Второй коэффициент калибровки камеры4
#define fEM_B0UX05RSS	 BUFFER[257]	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	 75	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_B0UX06RSS	 BUFFER[262]	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define idfEM_B0UX06RSS	 76	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define fEM_R0UH05RSS	 BUFFER[267]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 77	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define iEM_R0UL01ISS	 BUFFER[272]	//(R0UL01ISS) Шаг (мс) измерения периода
#define idiEM_R0UL01ISS	 78	//(R0UL01ISS) Шаг (мс) измерения периода
#define dEM_R0UL02USS	 BUFFER[275]	//(R0UL02USS) Предельное время ожидания роста потока (мс)
#define iddEM_R0UL02USS	 79	//(R0UL02USS) Предельное время ожидания роста потока (мс)
#define fEM_R0UN03RSS	 BUFFER[280]	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN03RSS	 80	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define lEM_EE01LS2	 BUFFER[285]	//(EE01LS2) Исправность АКНП2
#define idlEM_EE01LS2	 81	//(EE01LS2) Исправность АКНП2
#define bFirstEnterFlag	 BUFFER[287]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 82	//(bFirstEnterFlag) 
#define internal1_m22_Nk	 BUFFER[289]	//(internal1_m22_Nk) Nk - ведущая камера
#define idinternal1_m22_Nk	 83	//(internal1_m22_Nk) Nk - ведущая камера
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
	{ 1	,3	,1	, &R0DE01LS2},	//(vchs:01 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 1 месте
	{ 2	,3	,1	, &R0DE02LS2},	//(vchs:02 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 2 месте
	{ 3	,3	,1	, &R0DE04LS2},	//(vds32:04 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 4 месте
	{ 4	,3	,1	, &R0DE05LS2},	//(fds16:05 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 5 месте
	{ 5	,3	,1	, &TTLaknp2},	//( - , AKNP2) TTL
	{ 6	,1	,1	, &R0DE31LS2},	//(sbk:20 - S01SBK, DiagnAKNP2) диагностика шкафа АКНП2 сеть 1
	{ 7	,1	,1	, &R0DE32LS2},	//(sbk:20 - S02SBK, DiagnAKNP2) диагностика шкафа АКНП2 сеть 2
	{ 8	,1	,1	, &R0DE33LS2},	//(sbk:20 - S03SBK, DiagnAKNP2) диагностика шкафа АКНП2 двери
	{ 9	,1	,1	, &R0DE34LS2},	//(sbk:20 - S04SBK, DiagnAKNP2) диагностика шкафа АКНП2 температура меньше 43
	{ 10	,1	,1	, &R0DE35LS2},	//(sbk:20 - S05SBK, DiagnAKNP2) диагностика шкафа АКНП2 температура больше 53
	{ 11	,1	,1	, &R0DE37LS2},	//(sbk:20 - S07SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП15-3.1 место 2
	{ 12	,1	,1	, &R0DE38LS2},	//(sbk:20 - S08SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП15-3 место 3
	{ 13	,1	,1	, &R0DE39LS2},	//(sbk:20 - S09SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП24-2 место 4
	{ 14	,1	,1	, &R0DE3CLS2},	//( - , DiagnAKNP2) диагностика шкафа АКНП2 БП5/24Д место 7
	{ 15	,1	,1	, &R0DE3DLS2},	//( - , DiagnAKNP2) диагностика шкафа АКНП2 БП5/24Д место 8
	{ 16	,1	,1	, &TestDiagnAKNP2},	//( - , AKNP2) Неисправность от диагностики
	{ 17	,1	,1	, &R0DEB1LS2},	//(sbk:20 - S10SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП5 место 7
	{ 18	,1	,1	, &R0DEB2LS2},	//(sbk:20 - S11SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП24Д место 7
	{ 19	,1	,1	, &R0DEB3LS2},	//(sbk:20 - S12SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП5 место 8
	{ 20	,1	,1	, &R0DEB4LS2},	//(sbk:20 - S13SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП24Д место 8
	{ 21	,8	,1	, &R0IN01FS2},	//(vchs:01 - K01VCHS, - ) Выход СНМ-11 Гц
	{ 22	,8	,1	, &R0IN02FI2},	//( - , MA2S) Выход КНК15-1 Гц
	{ 23	,8	,1	, &R0IN03FS2},	//(vchs:02 - K01VCHS, - ) Выход КНК53М Гц
	{ 24	,3	,1	, &R0IS01FI0},	//( - , MA2S) Признак работы с имитатором
	{ 25	,8	,1	, &R0IN01FI2},	//( - , MA2S) Выход СНМ-11 Гц
	{ 26	,8	,1	, &R0IN02FS2},	//(vchs:01 - K02VCHS, - ) Выход КНК15-1 Гц
	{ 27	,8	,1	, &R0IN03FI2},	//( - , MA2S) Выход КНК53М Гц
	{ 28	,8	,1	, &R0VN02RS2},	//( - , A2Bz1, A2Bz2) Уровень мощности канал 2
	{ 29	,8	,1	, &R0VN01RS2},	//( - , A2Bz1, A2Bz2) Период разгона канал 2
	{ 30	,1	,1	, &R0VN61LS2},	//( - , A2Bz1, A2Bz2) ПС по мощности канал 2
	{ 31	,1	,1	, &R0VN72LZ1},	//(fds16:05 - K09FDSR, - ) АС по мощности канал 2 на БАЗ1
	{ 32	,1	,1	, &R0VN65LS2},	//( - , A2Bz1, A2Bz2) ПС по периоду разгона канал 2
	{ 33	,1	,1	, &R0VN76LZ1},	//(fds16:05 - K10FDSR, - ) АС по периоду разгона канал 2  на БАЗ1
	{ 34	,1	,1	, &A0EE01LS2},	//(fds16:05 - K11FDSR, - ) Исправность АКНП канал 2 на БАЗ1
	{ 35	,8	,1	, &R0VN03RS2},	//( - , AKNP2) Измеренный нейтронный поток канал 2
	{ 36	,8	,1	, &R0VN04RS2},	//( - , AKNP2) Реактивность канал 2
	{ 37	,1	,1	, &A1VN71LS2},	//(fds16:05 - K16FDSR, - ) Блокировка автоматического подъёма ББ канал 2 на БАЗ2
	{ 38	,1	,1	, &A0EE02LS2},	//( - , AKNP2) Исправность АКНП2 (от сшивки каналов) канал 2
	{ 39	,1	,1	, &R0IE11LS2},	//(vds32:04 - K01VDSR, - ) Исправность ВИП 1,6 (№11) СНМ11 2канала
	{ 40	,1	,1	, &R0IE12LS2},	//(vds32:04 - K02VDSR, - ) Исправность ВИП 0,5 (№12) КНК15-1 2 канала
	{ 41	,1	,1	, &R0IE13LS2},	//(vds32:04 - K03VDSR, - ) Исправность ВИП 0,5 (№13) КНК53М 2 канала
	{ 42	,8	,1	, &R0VN13RS2},	//( - , AKNP2) Нейтронный поток по камере СНМ11 канал 2
	{ 43	,8	,1	, &R0VN23RS2},	//( - , AKNP2) Нейтронный поток по камере КНК15-1 канал 2
	{ 44	,8	,1	, &R0VN33RS2},	//( - , AKNP2) Нейтронный поток по камере КНК53М канал 2
	{ 45	,3	,1	, &R0VN15RS2},	//( - , AKNP2) Номер ведущей камеры канал 2
	{ 46	,1	,1	, &R0IE01LS2},	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 2
	{ 47	,1	,1	, &R0IE02LS2},	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 2
	{ 48	,1	,1	, &R0VN72LZ2},	//(fds16:05 - K13FDSR, - ) АС по мощности канал 2 на БАЗ2
	{ 49	,1	,1	, &R0VN76LZ2},	//(fds16:05 - K14FDSR, - ) АС по периоду разгона канал 2  на БАЗ2
	{ 50	,1	,1	, &A1EE01LS2},	//(fds16:05 - K15FDSR, - ) Исправность АКНП канал 2 на БАЗ2
	{ 51	,1	,1	, &A0VN71LS2},	//(fds16:05 - K12FDSR, - ) Блокировка автоматического подъёма ББ канал 2 на БАЗ1
	{ 52	,8	,1	, &B8VC01RDU},	//( - , AKNP2) Координата АЗ2, мм
	{ 53	,1	,1	, &R0EE02LZ1},	//( - , AKNP2) Питание  АКНП  отключить
	{ 54	,1	,1	, &R0EE02LZ2},	//( - , AKNP2) Питание  АКНП  отключить
	{ 55	,8	,1	, &fEM_R0UR01RSS},	//(R0UR01RSS) Уставка АКНП блокировки автоматического подъёма ББ(имп/сек)
	{ 56	,8	,1	, &fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{ 57	,8	,1	, &fEM_R0UL41RSS},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{ 58	,8	,1	, &fEM_R0UL51RSS},	//(R0UL51RSS) Уровень АС по периоду разгона
	{ 59	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{ 60	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{ 61	,8	,1	, &fEM_R0UL42RSS},	//(R0UL42RSS) Уровень ПС по мощности
	{ 62	,8	,1	, &fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{ 63	,8	,1	, &fEM_R7UX04RSS},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{ 64	,8	,1	, &fEM_R7UX05RSS},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{ 65	,8	,1	, &fEM_R7UX06RSS},	//(R7UX06RSS) Y-координата камеры R7IN23 (см)
	{ 66	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{ 67	,8	,1	, &fEM_R7UY04RSS},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{ 68	,8	,1	, &fEM_R7UY05RSS},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{ 69	,8	,1	, &fEM_R7UY06RSS},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{ 70	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 71	,8	,1	, &fEM_A0UX04RSS},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{ 72	,8	,1	, &fEM_A0UX05RSS},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{ 73	,8	,1	, &fEM_A0UX06RSS},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{ 74	,8	,1	, &fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры4
	{ 75	,8	,1	, &fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{ 76	,8	,1	, &fEM_B0UX06RSS},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{ 77	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 78	,3	,1	, &iEM_R0UL01ISS},	//(R0UL01ISS) Шаг (мс) измерения периода
	{ 79	,5	,1	, &dEM_R0UL02USS},	//(R0UL02USS) Предельное время ожидания роста потока (мс)
	{ 80	,8	,1	, &fEM_R0UN03RSS},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 81	,1	,1	, &lEM_EE01LS2},	//(EE01LS2) Исправность АКНП2
	{ 82	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 83	,3	,1	, &internal1_m22_Nk},	//(internal1_m22_Nk) Nk - ведущая камера
	{ 84	,8	,5	, &internal1_m53_tst},	//(internal1_m53_tst) - массив времени фиксации стартовой мощности
	{ 85	,8	,5	, &internal1_m53_trz},	//(internal1_m53_trz) - массив времени фиксации очередного периода
	{ 86	,8	,5	, &internal1_m53_N1},	//(internal1_m53_N1) - массив значения мощности в начале замера
	{ 87	,8	,5	, &internal1_m53_N2},	//(internal1_m53_N2) - массив значения мощности в конце замера
	{ 88	,8	,1	, &internal1_m53_Period0},	//(internal1_m53_Period0) Per - Период разгона РУ
	{ 89	,1	,1	, &internal1_m53_MyFirstEnterFlag},	//(internal1_m53_MyFirstEnterFlag)  FirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="aknp2.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{55,"fEM_R0UR01RSS\0"}, 
{56,"fEM_R0UL52RSS\0"}, 
{57,"fEM_R0UL41RSS\0"}, 
{58,"fEM_R0UL51RSS\0"}, 
{59,"fEM_R0UH02RSS\0"}, 
{60,"fEM_R0UH03RSS\0"}, 
{61,"fEM_R0UL42RSS\0"}, 
{62,"fEM_R7UX00RSS\0"}, 
{63,"fEM_R7UX04RSS\0"}, 
{64,"fEM_R7UX05RSS\0"}, 
{65,"fEM_R7UX06RSS\0"}, 
{66,"fEM_R7UY00RSS\0"}, 
{67,"fEM_R7UY04RSS\0"}, 
{68,"fEM_R7UY05RSS\0"}, 
{69,"fEM_R7UY06RSS\0"}, 
{70,"fEM_A0UX00RSS\0"}, 
{71,"fEM_A0UX04RSS\0"}, 
{72,"fEM_A0UX05RSS\0"}, 
{73,"fEM_A0UX06RSS\0"}, 
{74,"fEM_B0UX04RSS\0"}, 
{75,"fEM_B0UX05RSS\0"}, 
{76,"fEM_B0UX06RSS\0"}, 
{77,"fEM_R0UH05RSS\0"}, 
{78,"iEM_R0UL01ISS\0"}, 
{79,"dEM_R0UL02USS\0"}, 
{80,"fEM_R0UN03RSS\0"}, 
{81,"lEM_EE01LS2\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_AKNP2[]={  // 
	{&R0EE02LZ1,1,0},	//( - , AKNP2) Питание  АКНП  отключить
	{&R0EE02LZ2,1,1},	//( - , AKNP2) Питание  АКНП  отключить
	{&lEM_EE01LS2,1,2},	//( - , AKNP2) Исправность АКНП2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_AKNP2[]={  // 
	{&A0EE02LS2,1,0},	//( - , AKNP2) Исправность АКНП2 (от сшивки каналов) канал 2
	{&TestDiagnAKNP2,1,1},	//( - , AKNP2) Неисправность от диагностики
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_AKNP2[]={  // 
	{&R0VN03RS2,8,0},	//( - , AKNP2) Измеренный нейтронный поток канал 2
	{&R0VN04RS2,8,2},	//( - , AKNP2) Реактивность канал 2
	{&R0VN13RS2,8,4},	//( - , AKNP2) Нейтронный поток по камере СНМ11 канал 2
	{&R0VN23RS2,8,6},	//( - , AKNP2) Нейтронный поток по камере КНК15-1 канал 2
	{&R0VN33RS2,8,8},	//( - , AKNP2) Нейтронный поток по камере КНК53М канал 2
	{&R0VN15RS2,3,10},	//( - , AKNP2) Номер ведущей камеры канал 2
	{&TTLaknp2,3,11},	//( - , AKNP2) TTL
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_AKNP2[]={  // 
	{&B8VC01RDU,8,0},	//( - , AKNP2) Координата АЗ2, мм
	{&fEM_R0UR01RSS,8,2},	//( - , AKNP2) Уставка АКНП блокировки автоматического подъёма ББ(имп/сек)
	{&fEM_R0UL52RSS,8,4},	//( - , AKNP2) Уровень АС по мощности
	{&fEM_R0UL41RSS,8,6},	//( - , AKNP2) Уровень ПС по периоду разгона
	{&fEM_R0UL51RSS,8,8},	//( - , AKNP2) Уровень АС по периоду разгона
	{&fEM_R0UH02RSS,8,10},	//( - , AKNP2) Коэфф. преобразования частота->нейтр/с КНК15-1
	{&fEM_R0UH03RSS,8,12},	//( - , AKNP2) Коэфф. преобразования частота->нейтр/с КНК53М
	{&fEM_R0UL42RSS,8,14},	//( - , AKNP2) Уровень ПС по мощности
	{&fEM_R7UX00RSS,8,16},	//( - , AKNP2) X-координата АЗ1 (см)
	{&fEM_R7UX04RSS,8,18},	//( - , AKNP2) X-координата камеры R7IN21 (см)
	{&fEM_R7UX05RSS,8,20},	//( - , AKNP2) X-координата камеры R7IN22 (см)
	{&fEM_R7UX06RSS,8,22},	//( - , AKNP2) Y-координата камеры R7IN23 (см)
	{&fEM_R7UY00RSS,8,24},	//( - , AKNP2) Y-координата АЗ1 (см)
	{&fEM_R7UY04RSS,8,26},	//( - , AKNP2) Y-координата камеры R7IN21 (см)
	{&fEM_R7UY05RSS,8,28},	//( - , AKNP2) Y-координата камеры R7IN22 (см)
	{&fEM_R7UY06RSS,8,30},	//( - , AKNP2) Y-координата камеры R7IN23 (см)
	{&fEM_A0UX00RSS,8,32},	//( - , AKNP2) Эффективный радиус АЗ
	{&fEM_A0UX04RSS,8,34},	//( - , AKNP2) Первый коэффициент калибровки камеры4
	{&fEM_A0UX05RSS,8,36},	//( - , AKNP2) Первый коэффициент калибровки камеры 5
	{&fEM_A0UX06RSS,8,38},	//( - , AKNP2) Первый коэффициент калибровки камеры 6
	{&fEM_B0UX04RSS,8,40},	//( - , AKNP2) Второй коэффициент калибровки камеры4
	{&fEM_B0UX05RSS,8,42},	//( - , AKNP2) Второй коэффициент калибровки камеры 5
	{&fEM_B0UX06RSS,8,44},	//( - , AKNP2) Второй коэффициент калибровки камеры 6
	{&fEM_R0UH05RSS,8,46},	//( - , AKNP2) Кол-во делений/сек на 1 ватт * E^6
	{&iEM_R0UL01ISS,3,48},	//( - , AKNP2) Шаг (мс) измерения периода
	{&dEM_R0UL02USS,5,49},	//( - , AKNP2) Предельное время ожидания роста потока (мс)
	{&fEM_R0UN03RSS,8,51},	//( - , AKNP2) Нижняя граница интервала мощности для измерения периода (ватт)
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_A2Bz1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_A2Bz1[]={  // 
	{&R0VN61LS2,1,0},	//( - , A2Bz1, A2Bz2) ПС по мощности канал 2
	{&R0VN65LS2,1,1},	//( - , A2Bz1, A2Bz2) ПС по периоду разгона канал 2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_A2Bz1[]={  // 
	{&R0VN02RS2,8,0},	//( - , A2Bz1, A2Bz2) Уровень мощности канал 2
	{&R0VN01RS2,8,2},	//( - , A2Bz1, A2Bz2) Период разгона канал 2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_A2Bz1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_A2Bz2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_A2Bz2[]={  // 
	{&R0VN61LS2,1,0},	//( - , A2Bz1, A2Bz2) ПС по мощности канал 2
	{&R0VN65LS2,1,1},	//( - , A2Bz1, A2Bz2) ПС по периоду разгона канал 2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_A2Bz2[]={  // 
	{&R0VN02RS2,8,0},	//( - , A2Bz1, A2Bz2) Уровень мощности канал 2
	{&R0VN01RS2,8,2},	//( - , A2Bz1, A2Bz2) Период разгона канал 2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_A2Bz2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_DiagnAKNP2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnAKNP2[]={  // 
	{&R0DEB4LS2,1,0},	//( - S13SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП24Д место 8
	{&R0DEB3LS2,1,1},	//( - S12SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП5 место 8
	{&R0DEB2LS2,1,2},	//( - S11SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП24Д место 7
	{&R0DEB1LS2,1,3},	//( - S10SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП5 место 7
	{&R0DE3DLS2,1,4},	//( - , DiagnAKNP2) диагностика шкафа АКНП2 БП5/24Д место 8
	{&R0DE3CLS2,1,5},	//( - , DiagnAKNP2) диагностика шкафа АКНП2 БП5/24Д место 7
	{&R0DE39LS2,1,6},	//( - S09SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП24-2 место 4
	{&R0DE38LS2,1,7},	//( - S08SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП15-3 место 3
	{&R0DE37LS2,1,8},	//( - S07SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП15-3.1 место 2
	{&R0DE35LS2,1,9},	//( - S05SBK, DiagnAKNP2) диагностика шкафа АКНП2 температура больше 53
	{&R0DE34LS2,1,10},	//( - S04SBK, DiagnAKNP2) диагностика шкафа АКНП2 температура меньше 43
	{&R0DE33LS2,1,11},	//( - S03SBK, DiagnAKNP2) диагностика шкафа АКНП2 двери
	{&R0DE32LS2,1,12},	//( - S02SBK, DiagnAKNP2) диагностика шкафа АКНП2 сеть 2
	{&R0DE31LS2,1,13},	//( - S01SBK, DiagnAKNP2) диагностика шкафа АКНП2 сеть 1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DiagnAKNP2[]={  // 
	{&R0DE05LS2,3,0},	//( - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 5 месте
	{&R0DE04LS2,3,1},	//( - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 4 месте
	{&R0DE02LS2,3,2},	//( - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 2 месте
	{&R0DE01LS2,3,3},	//( - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 1 месте
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DiagnAKNP2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MA2S[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MA2S[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MA2S[]={  // 
	{&R0IN01FI2,8,0},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{&R0IN02FI2,8,2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI2,8,4},	//( - , SA2) Выход КНК53М Гц от ПТИ
	{&R0IS01FI0,3,6},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MA2S[]={  // 
	{NULL,0,0},
};
#pragma pop
static char MA2S_ip1[]={"192.168.10.60\0"};
static char MA2S_ip2[]={"192.168.10.60\0"};
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_AKNP2[0],&di_AKNP2[0],&ir_AKNP2[0],&hr_AKNP2[0],NULL,NULL,NULL,0},	 //общий slave AKNP2
	{0,5016,&coil_A2Bz1[0],&di_A2Bz1[0],&ir_A2Bz1[0],&hr_A2Bz1[0],NULL,NULL,NULL,0},	 //slave AKNP2 - Baz1
	{0,5020,&coil_A2Bz2[0],&di_A2Bz2[0],&ir_A2Bz2[0],&hr_A2Bz2[0],NULL,NULL,NULL,0},	 //slave AKNP2 - Baz2
	{0,5003,&coil_DiagnAKNP2[0],&di_DiagnAKNP2[0],&ir_DiagnAKNP2[0],&hr_DiagnAKNP2[0],NULL,NULL,NULL,0},	 //Диагностика АКНП2
	{1,5007,&coil_MA2S[0],&di_MA2S[0],&ir_MA2S[0],&hr_MA2S[0],NULL,MA2S_ip1,MA2S_ip2,100},	 //Мастер AKNP2 в SCM

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
	{&R0IN02FS2,8,5},
	{&R0IN01FS2,8,0},
	{&R0DE01LS2,3,10},
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
	{&R0IN03FS2,8,0},
	{&R0DE02LS2,3,10},
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
	{&R0IE13LS2,1,4},
	{&R0IE12LS2,1,2},
	{&R0IE11LS2,1,0},
	{&R0DE04LS2,3,64},
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
	{&A1VN71LS2,1,30},
	{&A0EE01LS2,1,20},
	{&R0VN76LZ1,1,18},
	{&R0VN72LZ1,1,16},
	{&R0DE05LS2,3,38},
	{&R0IE01LS2,1,2},
	{&R0IE02LS2,1,0},
	{&R0VN72LZ2,1,24},
	{&R0VN76LZ2,1,26},
	{&A1EE01LS2,1,28},
	{&A0VN71LS2,1,22},
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
	{&R0DE31LS2,1,0},
	{&R0DE32LS2,1,2},
	{&R0DE33LS2,1,4},
	{&R0DEB3LS2,1,22},
	{&R0DEB4LS2,1,24},
	{&R0DEB2LS2,1,20},
	{&R0DEB1LS2,1,18},
	{&R0DE39LS2,1,16},
	{&R0DE38LS2,1,14},
	{&R0DE37LS2,1,12},
	{&R0DE35LS2,1,8},
	{&R0DE34LS2,1,6},
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
	setAsFloat(55,5000);
	setAsFloat(56,5100);
	setAsFloat(57,30);
	setAsFloat(58,20.0);
	setAsFloat(59,3703.704 );
	setAsFloat(60,62500.0);
	setAsFloat(61,5000);
	setAsFloat(62,1567.36);
	setAsFloat(63,1555.0);
	setAsFloat(64,1269.0);
	setAsFloat(65,1269.0);
	setAsFloat(66,506.5);
	setAsFloat(67,248.0);
	setAsFloat(68,271.6);
	setAsFloat(69,287.2);
	setAsFloat(70,11.0);
	setAsFloat(71,1.0);
	setAsFloat(72,1.0);
	setAsFloat(73,1.0);
	setAsFloat(74,0);
	setAsFloat(75,0.0);
	setAsFloat(76,0);
	setAsFloat(77,32000.0);
	setAsShort(78,500);
	setAsInt(79,100000);
	setAsFloat(80,0.005);
	setAsBool(81,1);
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
ssint iRM_5_ = {5,0}; /* n - N-����������� ������� ������� ���������� */ 
ssint iRM_2_ = {2,0}; /* n - N-����������� ������� ������� ���������� */ 
ssfloat fRM_2_0 = {2.0,0}; /* Kpr1 - �����. �������������� �������->�����/� ���-11 */ 
sschar bRM_2_ = {2,0}; /* type - ��� ������ ���-11 1- ��� ��1, 2- ��� ��2, >2 ��� */ 
ssint iRM_4_ = {4,0}; /* n - ����������� ������� �������� */ 
ssint iRM_1_ = {1,0}; /* x2 - ������ ��������� */ 

uspaint8 SpaEEPROMBuf[130];

/* ����������� ���������� */
ssbool var1;
ssfloat var2;
ssfloat var3;
ssfloat var4;
ssint var5;
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
ssfloat var29;
ssbool var30;
ssfloat var31;
ssfloat var32;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* ���������� �������� */
psfloat  array_m9_x_1[2] = {&R0IN03FS2,&R0IN03FI2};
psfloat  array_m8_x_1[2] = {&R0IN02FS2,&R0IN02FI2};
psfloat  array_m7_x_1[2] = {&R0IN01FS2,&R0IN01FI2};
psbool  array_m102_x_1[5] = {&var7,&var6,&R0DE37LS2,&R0DE38LS2,&R0DE39LS2};
psint  array_m88_x_1[4] = {&R0DE01LS2,&R0DE02LS2,&R0DE04LS2,&R0DE05LS2};
psfloat  array_m53_tst_1[5];
psfloat  array_m53_trz_1[5];
psfloat  array_m53_N1_1[5];
psfloat  array_m53_N2_1[5];
psbool  array_m63_x_1[2] = {&var27,&var23};
psbool  array_m62_x_1[2] = {&var27,&var28};
psbool  array_m72_x_1[5] = {&var15,&R0IE11LS2,&R0IE12LS2,&R0IE13LS2,&var1};

/* ���������� �������� */
_S_noto  S_noto_99_1 = {&var8,&var1};
_S_ma  S_ma_9_1 = {array_m9_x_1,&var5,&iRM_2_,&var2};
_S_ma  S_ma_8_1 = {array_m8_x_1,&var5,&iRM_2_,&var3};
_S_ma  S_ma_7_1 = {array_m7_x_1,&var5,&iRM_2_,&var4};
_S_fsumz  S_fsumz_2_1 = {&R0IS01FI0,&iRM_1_,&var5};
_S_or2  S_or2_104_1 = {&R0DEB3LS2,&R0DEB4LS2,&var6};
_S_or2  S_or2_96_1 = {&R0DEB1LS2,&R0DEB2LS2,&var7};
_S_or3  S_or3_98_1 = {&var11,&var10,&var9,&var8};
_S_orn  S_orn_102_1 = {array_m102_x_1,&iRM_5_,&var9};
_S_and2  S_and2_90_1 = {&R0DE31LS2,&R0DE32LS2,&var10};
_S_diagndev  S_diagndev_88_1 = {array_m88_x_1,&iRM_4_,&var11,&var12};
_S_ocham  S_ocham_22_1 = {&var4,&var3,&var2,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX04RSS,&fEM_B0UX04RSS,&fEM_A0UX05RSS,&fEM_B0UX05RSS,&fEM_A0UX06RSS,&fEM_B0UX06RSS,&fEM_R7UX04RSS,&fEM_R7UY04RSS,&fEM_R7UX05RSS,&fEM_R7UY05RSS,&fEM_R7UX06RSS,&fEM_R7UY06RSS,&bRM_2_,&fRM_2_0,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&var13,&var14,&var15,&var16,&var17,&var18,&var19,&internal1_m22_Nk};
_S_or2  S_or2_74_1 = {&R0EE02LZ1,&R0EE02LZ2,&var20};
_S_period  S_period_53_1 = {&var14,&lEM_EE01LS2,&iRM_5_,&var31,&var32,&fEM_R0UN03RSS,&var21,array_m53_tst_1,array_m53_trz_1,array_m53_N1_1,array_m53_N2_1,&internal1_m53_Period0,&internal1_m53_MyFirstEnterFlag};
_S_andn  S_andn_63_1 = {array_m63_x_1,&iRM_2_,&var22};
_S_bol  S_bol_60_1 = {&fEM_R0UL41RSS,&var21,&var23};
_S_andn  S_andn_62_1 = {array_m62_x_1,&iRM_2_,&var24};
_S_andn  S_andn_72_1 = {array_m72_x_1,&iRM_5_,&vainSBool};
_S_bol  S_bol_42_1 = {&var14,&fEM_R0UL52RSS,&var25};
_S_bol  S_bol_48_1 = {&var14,&fEM_R0UL42RSS,&var26};
_S_bol  S_bol_59_1 = {&var14,&fEM_R0UN03RSS,&var27};
_S_bol  S_bol_58_1 = {&fEM_R0UL51RSS,&var21,&var28};
_S_react  S_react_54_1 = {&var21,&var29};
_S_bol  S_bol_38_1 = {&var14,&fEM_R0UR01RSS,&var30};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_74_1);
  diagndev(&S_diagndev_88_1);
  and2(&S_and2_90_1);
  or2(&S_or2_96_1);
  or2(&S_or2_104_1);
  fsumz(&S_fsumz_2_1);
  ma(&S_ma_7_1);
  ma(&S_ma_8_1);
  ma(&S_ma_9_1);
  ocham(&S_ocham_22_1);
  orn(&S_orn_102_1);
  or3(&S_or3_98_1);
  noto(&S_noto_99_1);
  bol(&S_bol_38_1);
  bol(&S_bol_59_1);
  bol(&S_bol_48_1);
  bol(&S_bol_42_1);
  andn(&S_andn_72_1);
  setData(&var31,&iEM_R0UL01ISS);
  setData(&var32,&dEM_R0UL02USS);
  period(&S_period_53_1);
  react(&S_react_54_1);
  bol(&S_bol_58_1);
  andn(&S_andn_62_1);
  bol(&S_bol_60_1);
  andn(&S_andn_63_1);
  setData(idTestDiagnAKNP2,&var8);
  setData(idR0DE3DLS2,&var6);
  setData(idR0DE3CLS2,&var7);
  setData(idTTLaknp2,&var12);
  setData(idA0VN71LS2,&var30);
  setData(idA1EE01LS2,&lEM_EE01LS2);
  setData(idR0VN76LZ2,&var24);
  setData(idR0VN72LZ2,&var25);
  setData(idR0IE02LS2,&var20);
  setData(idR0IE01LS2,&var20);
  setData(idR0VN15RS2,&var19);
  setData(idR0VN33RS2,&var18);
  setData(idR0VN23RS2,&var17);
  setData(idR0VN13RS2,&var16);
  setData(idA0EE02LS2,&var15);
  setData(idA1VN71LS2,&var30);
  setData(idR0VN04RS2,&var29);
  setData(idR0VN03RS2,&var13);
  setData(idA0EE01LS2,&lEM_EE01LS2);
  setData(idR0VN76LZ1,&var24);
  setData(idR0VN65LS2,&var22);
  setData(idR0VN72LZ1,&var25);
  setData(idR0VN61LS2,&var26);
  setData(idR0VN01RS2,&var21);
  setData(idR0VN02RS2,&var14);

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
