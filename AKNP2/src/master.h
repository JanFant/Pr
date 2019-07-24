#ifndef AKNP2_H
#define AKNP2_H
// Подсистема  AKNP2:AKNP2
static char SimulOn=0;
static short CodeSub=9;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 //Время цикла мс
float takt,taktScheme=0,taktSS=0;
#define SIZE_BUFFER 542
static char BUFFER[SIZE_BUFFER];
#include <fp8/UDPTransport.h>
SetupUDP setUDP ={"192.168.10.57\0",5432,"192.168.10.157\0",5432,BUFFER,sizeof(BUFFER),};
int master=1,nomer=1;
#define A0EE01LS2	BUFFER[0]	// (fds16:05 - K11FDSR, - ) Исправность АКНП канал 2 на БАЗ1
#define idA0EE01LS2	1	// (fds16:05 - K11FDSR, - ) Исправность АКНП канал 2 на БАЗ1
#define A0EE02LS2	BUFFER[2]	// ( - , AKNP2) Исправность АКНП2 (от сшивки каналов) канал 2
#define idA0EE02LS2	2	// ( - , AKNP2) Исправность АКНП2 (от сшивки каналов) канал 2
#define A0VN71LS2	BUFFER[4]	// (fds16:05 - K12FDSR, - ) Блокировка автоматического подъёма ББ канал 2 на БАЗ1
#define idA0VN71LS2	3	// (fds16:05 - K12FDSR, - ) Блокировка автоматического подъёма ББ канал 2 на БАЗ1
#define A1EE01LS2	BUFFER[6]	// (fds16:05 - K15FDSR, - ) Исправность АКНП канал 2 на БАЗ2
#define idA1EE01LS2	4	// (fds16:05 - K15FDSR, - ) Исправность АКНП канал 2 на БАЗ2
#define A1VN71LS2	BUFFER[8]	// (fds16:05 - K16FDSR, - ) Блокировка автоматического подъёма ББ канал 2 на БАЗ2
#define idA1VN71LS2	5	// (fds16:05 - K16FDSR, - ) Блокировка автоматического подъёма ББ канал 2 на БАЗ2
#define B8VC01RDU	BUFFER[10]	// ( - , A2Bz1, A2Bz2) Координата АЗ2, мм
#define idB8VC01RDU	6	// ( - , A2Bz1, A2Bz2) Координата АЗ2, мм
#define R0DE01LS2	BUFFER[15]	// (vchs:01 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 1 месте
#define idR0DE01LS2	7	// (vchs:01 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 1 месте
#define R0DE02LS2	BUFFER[18]	// (vchs:02 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 2 месте
#define idR0DE02LS2	8	// (vchs:02 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 2 месте
#define R0DE04LS2	BUFFER[21]	// (vds32:04 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 4 месте
#define idR0DE04LS2	9	// (vds32:04 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 4 месте
#define R0DE05LS2	BUFFER[24]	// (fds16:05 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 5 месте
#define idR0DE05LS2	10	// (fds16:05 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 5 месте
#define R0DE31LS2	BUFFER[27]	// (sbk:20 - S01SBK, DiagnAKNP2) диагностика шкафа АКНП2 сеть 1
#define idR0DE31LS2	11	// (sbk:20 - S01SBK, DiagnAKNP2) диагностика шкафа АКНП2 сеть 1
#define R0DE32LS2	BUFFER[29]	// (sbk:20 - S02SBK, DiagnAKNP2) диагностика шкафа АКНП2 сеть 2
#define idR0DE32LS2	12	// (sbk:20 - S02SBK, DiagnAKNP2) диагностика шкафа АКНП2 сеть 2
#define R0DE33LS2	BUFFER[31]	// (sbk:20 - S03SBK, DiagnAKNP2) диагностика шкафа АКНП2 двери
#define idR0DE33LS2	13	// (sbk:20 - S03SBK, DiagnAKNP2) диагностика шкафа АКНП2 двери
#define R0DE34LS2	BUFFER[33]	// (sbk:20 - S04SBK, DiagnAKNP2) диагностика шкафа АКНП2 температура меньше 43
#define idR0DE34LS2	14	// (sbk:20 - S04SBK, DiagnAKNP2) диагностика шкафа АКНП2 температура меньше 43
#define R0DE35LS2	BUFFER[35]	// (sbk:20 - S05SBK, DiagnAKNP2) диагностика шкафа АКНП2 температура больше 53
#define idR0DE35LS2	15	// (sbk:20 - S05SBK, DiagnAKNP2) диагностика шкафа АКНП2 температура больше 53
#define R0DE37LS2	BUFFER[37]	// (sbk:20 - S07SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП15-3.1 место 2
#define idR0DE37LS2	16	// (sbk:20 - S07SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП15-3.1 место 2
#define R0DE38LS2	BUFFER[39]	// (sbk:20 - S08SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП15-3 место 3
#define idR0DE38LS2	17	// (sbk:20 - S08SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП15-3 место 3
#define R0DE39LS2	BUFFER[41]	// (sbk:20 - S09SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП24-2 место 4
#define idR0DE39LS2	18	// (sbk:20 - S09SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП24-2 место 4
#define R0DE3CLS2	BUFFER[43]	// ( - , DiagnAKNP2) диагностика шкафа АКНП2 БП5/24Д место 7
#define idR0DE3CLS2	19	// ( - , DiagnAKNP2) диагностика шкафа АКНП2 БП5/24Д место 7
#define R0DE3DLS2	BUFFER[45]	// ( - , DiagnAKNP2) диагностика шкафа АКНП2 БП5/24Д место 8
#define idR0DE3DLS2	20	// ( - , DiagnAKNP2) диагностика шкафа АКНП2 БП5/24Д место 8
#define R0DEB1LS2	BUFFER[47]	// (sbk:20 - S10SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП5 место 7
#define idR0DEB1LS2	21	// (sbk:20 - S10SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП5 место 7
#define R0DEB2LS2	BUFFER[49]	// (sbk:20 - S11SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП24Д место 7
#define idR0DEB2LS2	22	// (sbk:20 - S11SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП24Д место 7
#define R0DEB3LS2	BUFFER[51]	// (sbk:20 - S12SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП5 место 8
#define idR0DEB3LS2	23	// (sbk:20 - S12SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП5 место 8
#define R0DEB4LS2	BUFFER[53]	// (sbk:20 - S13SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП24Д место 8
#define idR0DEB4LS2	24	// (sbk:20 - S13SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП24Д место 8
#define R0EE02LZ1	BUFFER[55]	// ( - , AKNP2) Питание  АКНП  отключить
#define idR0EE02LZ1	25	// ( - , AKNP2) Питание  АКНП  отключить
#define R0EE02LZ2	BUFFER[57]	// ( - , AKNP2) Питание  АКНП  отключить
#define idR0EE02LZ2	26	// ( - , AKNP2) Питание  АКНП  отключить
#define R0IE01LS2	BUFFER[59]	// (fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 2
#define idR0IE01LS2	27	// (fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 2
#define R0IE02LS2	BUFFER[61]	// (fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 2
#define idR0IE02LS2	28	// (fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 2
#define R0IE11LS2	BUFFER[63]	// ( - , - ) Исправность ВИП 1,6 (№11) СНМ11 2канала
#define idR0IE11LS2	29	// ( - , - ) Исправность ВИП 1,6 (№11) СНМ11 2канала
#define R0IE12LS2	BUFFER[65]	// ( - , - ) Исправность ВИП 0,5 (№12) КНК15-1 2 канала
#define idR0IE12LS2	30	// ( - , - ) Исправность ВИП 0,5 (№12) КНК15-1 2 канала
#define R0IE13LS2	BUFFER[67]	// ( - , - ) Исправность ВИП 0,5 (№13) КНК53М 2 канала
#define idR0IE13LS2	31	// ( - , - ) Исправность ВИП 0,5 (№13) КНК53М 2 канала
#define R0IN01FI2	BUFFER[69]	// ( - , MA2S) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI2	32	// ( - , MA2S) Выход СНМ-11 Гц от ПТИ
#define R0IN01FS2	BUFFER[74]	// ( - , AKNP2) Выход СНМ-11 Гц
#define idR0IN01FS2	33	// ( - , AKNP2) Выход СНМ-11 Гц
#define R0IN01FV2	BUFFER[79]	// (vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
#define idR0IN01FV2	34	// (vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
#define R0IN02FI2	BUFFER[84]	// ( - , MA2S) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI2	35	// ( - , MA2S) Выход КНК15-1 Гц от ПТИ
#define R0IN02FS2	BUFFER[89]	// ( - , AKNP2) Выход КНК15-1 Гц
#define idR0IN02FS2	36	// ( - , AKNP2) Выход КНК15-1 Гц
#define R0IN02FV2	BUFFER[94]	// (vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
#define idR0IN02FV2	37	// (vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
#define R0IN03FI2	BUFFER[99]	// ( - , MA2S) Выход КНК53М Гц от ПТИ
#define idR0IN03FI2	38	// ( - , MA2S) Выход КНК53М Гц от ПТИ
#define R0IN03FS2	BUFFER[104]	// ( - , AKNP2) Выход КНК53М Гц
#define idR0IN03FS2	39	// ( - , AKNP2) Выход КНК53М Гц
#define R0IN03FV2	BUFFER[109]	// (vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
#define idR0IN03FV2	40	// (vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
#define R0IS01FI0	BUFFER[114]	// ( - , MA2S) Признак работы с имитатором
#define idR0IS01FI0	41	// ( - , MA2S) Признак работы с имитатором
#define R0VN01RS2	BUFFER[116]	// ( - , A2Bz1, A2Bz2) Период разгона канал 2
#define idR0VN01RS2	42	// ( - , A2Bz1, A2Bz2) Период разгона канал 2
#define R0VN02RS2	BUFFER[121]	// ( - , A2Bz1, A2Bz2) Уровень мощности канал 2
#define idR0VN02RS2	43	// ( - , A2Bz1, A2Bz2) Уровень мощности канал 2
#define R0VN03RS2	BUFFER[126]	// ( - , AKNP2) Измеренный нейтронный поток канал 2
#define idR0VN03RS2	44	// ( - , AKNP2) Измеренный нейтронный поток канал 2
#define R0VN04RS2	BUFFER[131]	// ( - , AKNP2) Реактивность канал 2
#define idR0VN04RS2	45	// ( - , AKNP2) Реактивность канал 2
#define R0VN13RS2	BUFFER[136]	// ( - , AKNP2) Нейтронный поток по камере СНМ11 канал 2
#define idR0VN13RS2	46	// ( - , AKNP2) Нейтронный поток по камере СНМ11 канал 2
#define R0VN15RS2	BUFFER[141]	// ( - , AKNP2) Номер ведущей камеры канал 2
#define idR0VN15RS2	47	// ( - , AKNP2) Номер ведущей камеры канал 2
#define R0VN23RS2	BUFFER[144]	// ( - , AKNP2) Нейтронный поток по камере КНК15-1 канал 2
#define idR0VN23RS2	48	// ( - , AKNP2) Нейтронный поток по камере КНК15-1 канал 2
#define R0VN33RS2	BUFFER[149]	// ( - , AKNP2) Нейтронный поток по камере КНК53М канал 2
#define idR0VN33RS2	49	// ( - , AKNP2) Нейтронный поток по камере КНК53М канал 2
#define R0VN61LS2	BUFFER[154]	// ( - , A2Bz1, A2Bz2) ПС по мощности канал 2
#define idR0VN61LS2	50	// ( - , A2Bz1, A2Bz2) ПС по мощности канал 2
#define R0VN65LS2	BUFFER[156]	// ( - , A2Bz1, A2Bz2) ПС по периоду разгона канал 2
#define idR0VN65LS2	51	// ( - , A2Bz1, A2Bz2) ПС по периоду разгона канал 2
#define R0VN72LZ1	BUFFER[158]	// (fds16:05 - K09FDSR, - ) АС по мощности канал 2 на БАЗ1
#define idR0VN72LZ1	52	// (fds16:05 - K09FDSR, - ) АС по мощности канал 2 на БАЗ1
#define R0VN72LZ2	BUFFER[160]	// (fds16:05 - K13FDSR, - ) АС по мощности канал 2 на БАЗ2
#define idR0VN72LZ2	53	// (fds16:05 - K13FDSR, - ) АС по мощности канал 2 на БАЗ2
#define R0VN76LZ1	BUFFER[162]	// (fds16:05 - K10FDSR, - ) АС по периоду разгона канал 2  на БАЗ1
#define idR0VN76LZ1	54	// (fds16:05 - K10FDSR, - ) АС по периоду разгона канал 2  на БАЗ1
#define R0VN76LZ2	BUFFER[164]	// (fds16:05 - K14FDSR, - ) АС по периоду разгона канал 2  на БАЗ2
#define idR0VN76LZ2	55	// (fds16:05 - K14FDSR, - ) АС по периоду разгона канал 2  на БАЗ2
#define TTLaknp2	BUFFER[166]	// ( - , AKNP2) TTL
#define idTTLaknp2	56	// ( - , AKNP2) TTL
#define TestDiagnAKNP2	BUFFER[169]	// ( - , AKNP2) Неисправность от диагностики
#define idTestDiagnAKNP2	57	// ( - , AKNP2) Неисправность от диагностики
#define bFirstEnterFlag	BUFFER[171]	// (bFirstEnterFlag) 
#define idbFirstEnterFlag	58	// (bFirstEnterFlag) 
#define fEM_A0UX00RSS	BUFFER[173]	// (A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	59	// (A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX04RSS	BUFFER[178]	// (A0UX04RSS) Первый коэффициент калибровки камеры4
#define idfEM_A0UX04RSS	60	// (A0UX04RSS) Первый коэффициент калибровки камеры4
#define fEM_A0UX05RSS	BUFFER[183]	// (A0UX05RSS) Первый коэффициент калибровки камеры 5
#define idfEM_A0UX05RSS	61	// (A0UX05RSS) Первый коэффициент калибровки камеры 5
#define fEM_A0UX06RSS	BUFFER[188]	// (A0UX06RSS) Первый коэффициент калибровки камеры 6
#define idfEM_A0UX06RSS	62	// (A0UX06RSS) Первый коэффициент калибровки камеры 6
#define fEM_B0UX04RSS	BUFFER[193]	// (B0UX04RSS) Второй коэффициент калибровки камеры4
#define idfEM_B0UX04RSS	63	// (B0UX04RSS) Второй коэффициент калибровки камеры4
#define fEM_B0UX05RSS	BUFFER[198]	// (B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	64	// (B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_B0UX06RSS	BUFFER[203]	// (B0UX06RSS) Второй коэффициент калибровки камеры 6
#define idfEM_B0UX06RSS	65	// (B0UX06RSS) Второй коэффициент калибровки камеры 6
#define fEM_R0IN11FN2	BUFFER[208]	// (R0IN11FN2) Коэффициент A (А2 к 1)
#define idfEM_R0IN11FN2	66	// (R0IN11FN2) Коэффициент A (А2 к 1)
#define fEM_R0IN12FN2	BUFFER[213]	// (R0IN12FN2) Коэффициент B (А2 к 1)
#define idfEM_R0IN12FN2	67	// (R0IN12FN2) Коэффициент B (А2 к 1)
#define fEM_R0IN21FN2	BUFFER[218]	// (R0IN21FN2) Коэффициент A (А2 к 2)
#define idfEM_R0IN21FN2	68	// (R0IN21FN2) Коэффициент A (А2 к 2)
#define fEM_R0IN22FN2	BUFFER[223]	// (R0IN22FN2) Коэффициент B (А2 к 2)
#define idfEM_R0IN22FN2	69	// (R0IN22FN2) Коэффициент B (А2 к 2)
#define fEM_R0IN31FN2	BUFFER[228]	// (R0IN31FN2) Коэффициент A (А2 к 3)
#define idfEM_R0IN31FN2	70	// (R0IN31FN2) Коэффициент A (А2 к 3)
#define fEM_R0IN32FN2	BUFFER[233]	// (R0IN32FN2) Коэффициент B (А2 к 3)
#define idfEM_R0IN32FN2	71	// (R0IN32FN2) Коэффициент B (А2 к 3)
#define fEM_R0UH01RSS	BUFFER[238]	// (R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
#define idfEM_R0UH01RSS	72	// (R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
#define fEM_R0UH02RSS	BUFFER[243]	// (R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define idfEM_R0UH02RSS	73	// (R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define fEM_R0UH03RSS	BUFFER[248]	// (R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define idfEM_R0UH03RSS	74	// (R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define fEM_R0UH05RSS	BUFFER[253]	// (R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	75	// (R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UH21RSS	BUFFER[258]	// (R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	76	// (R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	BUFFER[263]	// (R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	77	// (R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	BUFFER[268]	// (R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	78	// (R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0UL01RSS	BUFFER[273]	// (R0UL01RSS) Шаг (мс) измерения периода
#define idfEM_R0UL01RSS	79	// (R0UL01RSS) Шаг (мс) измерения периода
#define fEM_R0UL02RSS	BUFFER[278]	// (R0UL02RSS) Tф-постоянная времени, с
#define idfEM_R0UL02RSS	80	// (R0UL02RSS) Tф-постоянная времени, с
#define fEM_R0UL41RSS	BUFFER[283]	// (R0UL41RSS) Уровень ПС по периоду разгона
#define idfEM_R0UL41RSS	81	// (R0UL41RSS) Уровень ПС по периоду разгона
#define fEM_R0UL42RSS	BUFFER[288]	// (R0UL42RSS) Уровень ПС по мощности
#define idfEM_R0UL42RSS	82	// (R0UL42RSS) Уровень ПС по мощности
#define fEM_R0UL51RSS	BUFFER[293]	// (R0UL51RSS) Уровень АС по периоду разгона
#define idfEM_R0UL51RSS	83	// (R0UL51RSS) Уровень АС по периоду разгона
#define fEM_R0UL52RSS	BUFFER[298]	// (R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	84	// (R0UL52RSS) Уровень АС по мощности
#define fEM_R0UN03RSS	BUFFER[303]	// (R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN03RSS	85	// (R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R0UR01RSS	BUFFER[308]	// (R0UR01RSS) Уставка АКНП блокировки автоматического подъёма ББ(имп/сек)
#define idfEM_R0UR01RSS	86	// (R0UR01RSS) Уставка АКНП блокировки автоматического подъёма ББ(имп/сек)
#define fEM_R7UX00RSS	BUFFER[313]	// (R7UX00RSS) X-координата АЗ1 (см)
#define idfEM_R7UX00RSS	87	// (R7UX00RSS) X-координата АЗ1 (см)
#define fEM_R7UX04RSS	BUFFER[318]	// (R7UX04RSS) X-координата камеры R7IN21 (см)
#define idfEM_R7UX04RSS	88	// (R7UX04RSS) X-координата камеры R7IN21 (см)
#define fEM_R7UX05RSS	BUFFER[323]	// (R7UX05RSS) X-координата камеры R7IN22 (см)
#define idfEM_R7UX05RSS	89	// (R7UX05RSS) X-координата камеры R7IN22 (см)
#define fEM_R7UX06RSS	BUFFER[328]	// (R7UX06RSS) Y-координата камеры R7IN23 (см)
#define idfEM_R7UX06RSS	90	// (R7UX06RSS) Y-координата камеры R7IN23 (см)
#define fEM_R7UY00RSS	BUFFER[333]	// (R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	91	// (R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UY04RSS	BUFFER[338]	// (R7UY04RSS) Y-координата камеры R7IN21 (см)
#define idfEM_R7UY04RSS	92	// (R7UY04RSS) Y-координата камеры R7IN21 (см)
#define fEM_R7UY05RSS	BUFFER[343]	// (R7UY05RSS) Y-координата камеры R7IN22 (см)
#define idfEM_R7UY05RSS	93	// (R7UY05RSS) Y-координата камеры R7IN22 (см)
#define fEM_R7UY06RSS	BUFFER[348]	// (R7UY06RSS) Y-координата камеры R7IN23 (см)
#define idfEM_R7UY06RSS	94	// (R7UY06RSS) Y-координата камеры R7IN23 (см)
#define internal1_m19_Nk	BUFFER[353]	// (internal1_m19_Nk) Nk - ведущая камера
#define idinternal1_m19_Nk	95	// (internal1_m19_Nk) Nk - ведущая камера
#define internal1_m55_MyFirstEnterFlag	BUFFER[356]	// (internal1_m55_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m55_MyFirstEnterFlag	96	// (internal1_m55_MyFirstEnterFlag)  FirstEnterFlag
#define internal1_m55_W1	BUFFER[358]	// (internal1_m55_W1)  мощность на старте измерения
#define idinternal1_m55_W1	97	// (internal1_m55_W1)  мощность на старте измерения
#define internal1_m55_W2	BUFFER[363]	// (internal1_m55_W2)  мощность в конце измерения
#define idinternal1_m55_W2	98	// (internal1_m55_W2)  мощность в конце измерения
#define internal1_m55_Wlast	BUFFER[368]	// (internal1_m55_Wlast)  последнее растущее измерение
#define idinternal1_m55_Wlast	99	// (internal1_m55_Wlast)  последнее растущее измерение
#define internal1_m55_Wmax	BUFFER[373]	// (internal1_m55_Wmax)  максимальное измерение в серии
#define idinternal1_m55_Wmax	100	// (internal1_m55_Wmax)  максимальное измерение в серии
#define internal1_m55_Wmin	BUFFER[378]	// (internal1_m55_Wmin)  минимальное измерение в серии
#define idinternal1_m55_Wmin	101	// (internal1_m55_Wmin)  минимальное измерение в серии
#define internal1_m55_chizm	BUFFER[383]	// (internal1_m55_chizm)  счетчик уменьшения мощности
#define idinternal1_m55_chizm	102	// (internal1_m55_chizm)  счетчик уменьшения мощности
#define internal1_m55_chsr	BUFFER[386]	// (internal1_m55_chsr)  счетчик усреднения
#define idinternal1_m55_chsr	103	// (internal1_m55_chsr)  счетчик усреднения
#define internal1_m55_flst	BUFFER[389]	// (internal1_m55_flst)  флаг старта измерения
#define idinternal1_m55_flst	104	// (internal1_m55_flst)  флаг старта измерения
#define internal1_m55_sumtim	BUFFER[392]	// (internal1_m55_sumtim)  время измерения мощности
#define idinternal1_m55_sumtim	105	// (internal1_m55_sumtim)  время измерения мощности
#define internal1_m55_y0	BUFFER[397]	// (internal1_m55_y0) y0 - внутренний параметр
#define idinternal1_m55_y0	106	// (internal1_m55_y0) y0 - внутренний параметр
#define internal1_m56_y0	BUFFER[402]	// (internal1_m56_y0) y0 - внутренний параметр
#define idinternal1_m56_y0	107	// (internal1_m56_y0) y0 - внутренний параметр
#define var3	BUFFER[407]	// Внутренняя переменная var3
#define idvar3	108	// Внутренняя переменная var3
#define var6	BUFFER[412]	// Внутренняя переменная var6
#define idvar6	109	// Внутренняя переменная var6
#define var25	BUFFER[417]	// Внутренняя переменная var25
#define idvar25	110	// Внутренняя переменная var25
#define vainSFloat	BUFFER[419]	// Внутренняя переменная vainSFloat
#define idvainSFloat	111	// Внутренняя переменная vainSFloat
#define var4	BUFFER[424]	// Внутренняя переменная var4
#define idvar4	112	// Внутренняя переменная var4
#define var10	BUFFER[429]	// Внутренняя переменная var10
#define idvar10	113	// Внутренняя переменная var10
#define var14	BUFFER[431]	// Внутренняя переменная var14
#define idvar14	114	// Внутренняя переменная var14
#define var16	BUFFER[436]	// Внутренняя переменная var16
#define idvar16	115	// Внутренняя переменная var16
#define var26	BUFFER[441]	// Внутренняя переменная var26
#define idvar26	116	// Внутренняя переменная var26
#define vainSInt	BUFFER[443]	// Внутренняя переменная vainSInt
#define idvainSInt	117	// Внутренняя переменная vainSInt
#define var9	BUFFER[448]	// Внутренняя переменная var9
#define idvar9	118	// Внутренняя переменная var9
#define var20	BUFFER[450]	// Внутренняя переменная var20
#define idvar20	119	// Внутренняя переменная var20
#define var23	BUFFER[455]	// Внутренняя переменная var23
#define idvar23	120	// Внутренняя переменная var23
#define var30	BUFFER[460]	// Внутренняя переменная var30
#define idvar30	121	// Внутренняя переменная var30
#define var31	BUFFER[462]	// Внутренняя переменная var31
#define idvar31	122	// Внутренняя переменная var31
#define var11	BUFFER[464]	// Внутренняя переменная var11
#define idvar11	123	// Внутренняя переменная var11
#define var15	BUFFER[466]	// Внутренняя переменная var15
#define idvar15	124	// Внутренняя переменная var15
#define var17	BUFFER[471]	// Внутренняя переменная var17
#define idvar17	125	// Внутренняя переменная var17
#define var19	BUFFER[473]	// Внутренняя переменная var19
#define idvar19	126	// Внутренняя переменная var19
#define var32	BUFFER[478]	// Внутренняя переменная var32
#define idvar32	127	// Внутренняя переменная var32
#define vainSLong	BUFFER[483]	// Внутренняя переменная vainSLong
#define idvainSLong	128	// Внутренняя переменная vainSLong
#define vainSBool	BUFFER[492]	// Внутренняя переменная vainSBool
#define idvainSBool	129	// Внутренняя переменная vainSBool
#define var8	BUFFER[494]	// Внутренняя переменная var8
#define idvar8	130	// Внутренняя переменная var8
#define var12	BUFFER[496]	// Внутренняя переменная var12
#define idvar12	131	// Внутренняя переменная var12
#define var18	BUFFER[498]	// Внутренняя переменная var18
#define idvar18	132	// Внутренняя переменная var18
#define var28	BUFFER[503]	// Внутренняя переменная var28
#define idvar28	133	// Внутренняя переменная var28
#define var29	BUFFER[505]	// Внутренняя переменная var29
#define idvar29	134	// Внутренняя переменная var29
#define var1	BUFFER[507]	// Внутренняя переменная var1
#define idvar1	135	// Внутренняя переменная var1
#define var2	BUFFER[512]	// Внутренняя переменная var2
#define idvar2	136	// Внутренняя переменная var2
#define var5	BUFFER[517]	// Внутренняя переменная var5
#define idvar5	137	// Внутренняя переменная var5
#define var22	BUFFER[522]	// Внутренняя переменная var22
#define idvar22	138	// Внутренняя переменная var22
#define var24	BUFFER[524]	// Внутренняя переменная var24
#define idvar24	139	// Внутренняя переменная var24
#define var27	BUFFER[526]	// Внутренняя переменная var27
#define idvar27	140	// Внутренняя переменная var27
#define var7	BUFFER[528]	// Внутренняя переменная var7
#define idvar7	141	// Внутренняя переменная var7
#define var13	BUFFER[533]	// Внутренняя переменная var13
#define idvar13	142	// Внутренняя переменная var13
#define var21	BUFFER[535]	// Внутренняя переменная var21
#define idvar21	143	// Внутренняя переменная var21
#define var33	BUFFER[540]	// Внутренняя переменная var33
#define idvar33	144	// Внутренняя переменная var33
#pragma pack(push,1)
static VarCtrl allVariables[]={ 			 //Описание всех переменных
	{1	,1	,1	,&A0EE01LS2},	//(fds16:05 - K11FDSR, - ) Исправность АКНП канал 2 на БАЗ1
	{2	,1	,1	,&A0EE02LS2},	//( - , AKNP2) Исправность АКНП2 (от сшивки каналов) канал 2
	{3	,1	,1	,&A0VN71LS2},	//(fds16:05 - K12FDSR, - ) Блокировка автоматического подъёма ББ канал 2 на БАЗ1
	{4	,1	,1	,&A1EE01LS2},	//(fds16:05 - K15FDSR, - ) Исправность АКНП канал 2 на БАЗ2
	{5	,1	,1	,&A1VN71LS2},	//(fds16:05 - K16FDSR, - ) Блокировка автоматического подъёма ББ канал 2 на БАЗ2
	{6	,8	,1	,&B8VC01RDU},	//( - , A2Bz1, A2Bz2) Координата АЗ2, мм
	{7	,3	,1	,&R0DE01LS2},	//(vchs:01 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 1 месте
	{8	,3	,1	,&R0DE02LS2},	//(vchs:02 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 2 месте
	{9	,3	,1	,&R0DE04LS2},	//(vds32:04 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 4 месте
	{10	,3	,1	,&R0DE05LS2},	//(fds16:05 - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 5 месте
	{11	,1	,1	,&R0DE31LS2},	//(sbk:20 - S01SBK, DiagnAKNP2) диагностика шкафа АКНП2 сеть 1
	{12	,1	,1	,&R0DE32LS2},	//(sbk:20 - S02SBK, DiagnAKNP2) диагностика шкафа АКНП2 сеть 2
	{13	,1	,1	,&R0DE33LS2},	//(sbk:20 - S03SBK, DiagnAKNP2) диагностика шкафа АКНП2 двери
	{14	,1	,1	,&R0DE34LS2},	//(sbk:20 - S04SBK, DiagnAKNP2) диагностика шкафа АКНП2 температура меньше 43
	{15	,1	,1	,&R0DE35LS2},	//(sbk:20 - S05SBK, DiagnAKNP2) диагностика шкафа АКНП2 температура больше 53
	{16	,1	,1	,&R0DE37LS2},	//(sbk:20 - S07SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП15-3.1 место 2
	{17	,1	,1	,&R0DE38LS2},	//(sbk:20 - S08SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП15-3 место 3
	{18	,1	,1	,&R0DE39LS2},	//(sbk:20 - S09SBK, DiagnAKNP2) диагностика шкафа АКНП2 МП24-2 место 4
	{19	,1	,1	,&R0DE3CLS2},	//( - , DiagnAKNP2) диагностика шкафа АКНП2 БП5/24Д место 7
	{20	,1	,1	,&R0DE3DLS2},	//( - , DiagnAKNP2) диагностика шкафа АКНП2 БП5/24Д место 8
	{21	,1	,1	,&R0DEB1LS2},	//(sbk:20 - S10SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП5 место 7
	{22	,1	,1	,&R0DEB2LS2},	//(sbk:20 - S11SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП24Д место 7
	{23	,1	,1	,&R0DEB3LS2},	//(sbk:20 - S12SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП5 место 8
	{24	,1	,1	,&R0DEB4LS2},	//(sbk:20 - S13SBK, DiagnAKNP2) диагностика шкафа АКНП2 БП24Д место 8
	{25	,1	,1	,&R0EE02LZ1},	//( - , AKNP2) Питание  АКНП  отключить
	{26	,1	,1	,&R0EE02LZ2},	//( - , AKNP2) Питание  АКНП  отключить
	{27	,1	,1	,&R0IE01LS2},	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 2
	{28	,1	,1	,&R0IE02LS2},	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 2
	{29	,1	,1	,&R0IE11LS2},	//( - , - ) Исправность ВИП 1,6 (№11) СНМ11 2канала
	{30	,1	,1	,&R0IE12LS2},	//( - , - ) Исправность ВИП 0,5 (№12) КНК15-1 2 канала
	{31	,1	,1	,&R0IE13LS2},	//( - , - ) Исправность ВИП 0,5 (№13) КНК53М 2 канала
	{32	,8	,1	,&R0IN01FI2},	//( - , MA2S) Выход СНМ-11 Гц от ПТИ
	{33	,8	,1	,&R0IN01FS2},	//( - , AKNP2) Выход СНМ-11 Гц
	{34	,8	,1	,&R0IN01FV2},	//(vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
	{35	,8	,1	,&R0IN02FI2},	//( - , MA2S) Выход КНК15-1 Гц от ПТИ
	{36	,8	,1	,&R0IN02FS2},	//( - , AKNP2) Выход КНК15-1 Гц
	{37	,8	,1	,&R0IN02FV2},	//(vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
	{38	,8	,1	,&R0IN03FI2},	//( - , MA2S) Выход КНК53М Гц от ПТИ
	{39	,8	,1	,&R0IN03FS2},	//( - , AKNP2) Выход КНК53М Гц
	{40	,8	,1	,&R0IN03FV2},	//(vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
	{41	,1	,1	,&R0IS01FI0},	//( - , MA2S) Признак работы с имитатором
	{42	,8	,1	,&R0VN01RS2},	//( - , A2Bz1, A2Bz2) Период разгона канал 2
	{43	,8	,1	,&R0VN02RS2},	//( - , A2Bz1, A2Bz2) Уровень мощности канал 2
	{44	,8	,1	,&R0VN03RS2},	//( - , AKNP2) Измеренный нейтронный поток канал 2
	{45	,8	,1	,&R0VN04RS2},	//( - , AKNP2) Реактивность канал 2
	{46	,8	,1	,&R0VN13RS2},	//( - , AKNP2) Нейтронный поток по камере СНМ11 канал 2
	{47	,3	,1	,&R0VN15RS2},	//( - , AKNP2) Номер ведущей камеры канал 2
	{48	,8	,1	,&R0VN23RS2},	//( - , AKNP2) Нейтронный поток по камере КНК15-1 канал 2
	{49	,8	,1	,&R0VN33RS2},	//( - , AKNP2) Нейтронный поток по камере КНК53М канал 2
	{50	,1	,1	,&R0VN61LS2},	//( - , A2Bz1, A2Bz2) ПС по мощности канал 2
	{51	,1	,1	,&R0VN65LS2},	//( - , A2Bz1, A2Bz2) ПС по периоду разгона канал 2
	{52	,1	,1	,&R0VN72LZ1},	//(fds16:05 - K09FDSR, - ) АС по мощности канал 2 на БАЗ1
	{53	,1	,1	,&R0VN72LZ2},	//(fds16:05 - K13FDSR, - ) АС по мощности канал 2 на БАЗ2
	{54	,1	,1	,&R0VN76LZ1},	//(fds16:05 - K10FDSR, - ) АС по периоду разгона канал 2  на БАЗ1
	{55	,1	,1	,&R0VN76LZ2},	//(fds16:05 - K14FDSR, - ) АС по периоду разгона канал 2  на БАЗ2
	{56	,3	,1	,&TTLaknp2},	//( - , AKNP2) TTL
	{57	,1	,1	,&TestDiagnAKNP2},	//( - , AKNP2) Неисправность от диагностики
	{58	,1	,1	,&bFirstEnterFlag},	//(bFirstEnterFlag) 
	{59	,8	,1	,&fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{60	,8	,1	,&fEM_A0UX04RSS},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{61	,8	,1	,&fEM_A0UX05RSS},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{62	,8	,1	,&fEM_A0UX06RSS},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{63	,8	,1	,&fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры4
	{64	,8	,1	,&fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{65	,8	,1	,&fEM_B0UX06RSS},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{66	,8	,1	,&fEM_R0IN11FN2},	//(R0IN11FN2) Коэффициент A (А2 к 1)
	{67	,8	,1	,&fEM_R0IN12FN2},	//(R0IN12FN2) Коэффициент B (А2 к 1)
	{68	,8	,1	,&fEM_R0IN21FN2},	//(R0IN21FN2) Коэффициент A (А2 к 2)
	{69	,8	,1	,&fEM_R0IN22FN2},	//(R0IN22FN2) Коэффициент B (А2 к 2)
	{70	,8	,1	,&fEM_R0IN31FN2},	//(R0IN31FN2) Коэффициент A (А2 к 3)
	{71	,8	,1	,&fEM_R0IN32FN2},	//(R0IN32FN2) Коэффициент B (А2 к 3)
	{72	,8	,1	,&fEM_R0UH01RSS},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
	{73	,8	,1	,&fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{74	,8	,1	,&fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{75	,8	,1	,&fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{76	,8	,1	,&fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{77	,8	,1	,&fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{78	,8	,1	,&fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{79	,8	,1	,&fEM_R0UL01RSS},	//(R0UL01RSS) Шаг (мс) измерения периода
	{80	,8	,1	,&fEM_R0UL02RSS},	//(R0UL02RSS) Tф-постоянная времени, с
	{81	,8	,1	,&fEM_R0UL41RSS},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{82	,8	,1	,&fEM_R0UL42RSS},	//(R0UL42RSS) Уровень ПС по мощности
	{83	,8	,1	,&fEM_R0UL51RSS},	//(R0UL51RSS) Уровень АС по периоду разгона
	{84	,8	,1	,&fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{85	,8	,1	,&fEM_R0UN03RSS},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{86	,8	,1	,&fEM_R0UR01RSS},	//(R0UR01RSS) Уставка АКНП блокировки автоматического подъёма ББ(имп/сек)
	{87	,8	,1	,&fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{88	,8	,1	,&fEM_R7UX04RSS},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{89	,8	,1	,&fEM_R7UX05RSS},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{90	,8	,1	,&fEM_R7UX06RSS},	//(R7UX06RSS) Y-координата камеры R7IN23 (см)
	{91	,8	,1	,&fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{92	,8	,1	,&fEM_R7UY04RSS},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{93	,8	,1	,&fEM_R7UY05RSS},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{94	,8	,1	,&fEM_R7UY06RSS},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{95	,3	,1	,&internal1_m19_Nk},	//(internal1_m19_Nk) Nk - ведущая камера
	{96	,1	,1	,&internal1_m55_MyFirstEnterFlag},	//(internal1_m55_MyFirstEnterFlag)  FirstEnterFlag
	{97	,8	,1	,&internal1_m55_W1},	//(internal1_m55_W1)  мощность на старте измерения
	{98	,8	,1	,&internal1_m55_W2},	//(internal1_m55_W2)  мощность в конце измерения
	{99	,8	,1	,&internal1_m55_Wlast},	//(internal1_m55_Wlast)  последнее растущее измерение
	{100	,8	,1	,&internal1_m55_Wmax},	//(internal1_m55_Wmax)  максимальное измерение в серии
	{101	,8	,1	,&internal1_m55_Wmin},	//(internal1_m55_Wmin)  минимальное измерение в серии
	{102	,3	,1	,&internal1_m55_chizm},	//(internal1_m55_chizm)  счетчик уменьшения мощности
	{103	,3	,1	,&internal1_m55_chsr},	//(internal1_m55_chsr)  счетчик усреднения
	{104	,3	,1	,&internal1_m55_flst},	//(internal1_m55_flst)  флаг старта измерения
	{105	,8	,1	,&internal1_m55_sumtim},	//(internal1_m55_sumtim)  время измерения мощности
	{106	,8	,1	,&internal1_m55_y0},	//(internal1_m55_y0) y0 - внутренний параметр
	{107	,8	,1	,&internal1_m56_y0},	//(internal1_m56_y0) y0 - внутренний параметр
	{108	,8	,1	,&var3},	//Внутренняя переменная var3
	{109	,8	,1	,&var6},	//Внутренняя переменная var6
	{110	,1	,1	,&var25},	//Внутренняя переменная var25
	{111	,8	,1	,&vainSFloat},	//Внутренняя переменная vainSFloat
	{112	,8	,1	,&var4},	//Внутренняя переменная var4
	{113	,1	,1	,&var10},	//Внутренняя переменная var10
	{114	,5	,1	,&var14},	//Внутренняя переменная var14
	{115	,8	,1	,&var16},	//Внутренняя переменная var16
	{116	,1	,1	,&var26},	//Внутренняя переменная var26
	{117	,5	,1	,&vainSInt},	//Внутренняя переменная vainSInt
	{118	,1	,1	,&var9},	//Внутренняя переменная var9
	{119	,8	,1	,&var20},	//Внутренняя переменная var20
	{120	,8	,1	,&var23},	//Внутренняя переменная var23
	{121	,1	,1	,&var30},	//Внутренняя переменная var30
	{122	,1	,1	,&var31},	//Внутренняя переменная var31
	{123	,1	,1	,&var11},	//Внутренняя переменная var11
	{124	,8	,1	,&var15},	//Внутренняя переменная var15
	{125	,1	,1	,&var17},	//Внутренняя переменная var17
	{126	,8	,1	,&var19},	//Внутренняя переменная var19
	{127	,8	,1	,&var32},	//Внутренняя переменная var32
	{128	,11	,1	,&vainSLong},	//Внутренняя переменная vainSLong
	{129	,1	,1	,&vainSBool},	//Внутренняя переменная vainSBool
	{130	,1	,1	,&var8},	//Внутренняя переменная var8
	{131	,1	,1	,&var12},	//Внутренняя переменная var12
	{132	,8	,1	,&var18},	//Внутренняя переменная var18
	{133	,1	,1	,&var28},	//Внутренняя переменная var28
	{134	,1	,1	,&var29},	//Внутренняя переменная var29
	{135	,8	,1	,&var1},	//Внутренняя переменная var1
	{136	,8	,1	,&var2},	//Внутренняя переменная var2
	{137	,8	,1	,&var5},	//Внутренняя переменная var5
	{138	,1	,1	,&var22},	//Внутренняя переменная var22
	{139	,1	,1	,&var24},	//Внутренняя переменная var24
	{140	,1	,1	,&var27},	//Внутренняя переменная var27
	{141	,8	,1	,&var7},	//Внутренняя переменная var7
	{142	,1	,1	,&var13},	//Внутренняя переменная var13
	{143	,5	,1	,&var21},	//Внутренняя переменная var21
	{144	,1	,1	,&var33},	//Внутренняя переменная var33
	{-1,0,NULL},
};
static char NameSaveFile[]="aknp2.bin\0"; //Имя файла сохранения переменных
#pragma pop
static VarSaveCtrl saveVariables[]={	//Id переменных для сохранения
	{86,"fEM_R0UR01RSS\0"},	//(R0UR01RSS) Уставка АКНП блокировки автоматического подъёма ББ(имп/сек)
	{84,"fEM_R0UL52RSS\0"},	//(R0UL52RSS) Уровень АС по мощности
	{82,"fEM_R0UL42RSS\0"},	//(R0UL42RSS) Уровень ПС по мощности
	{80,"fEM_R0UL02RSS\0"},	//(R0UL02RSS) Tф-постоянная времени, с
	{79,"fEM_R0UL01RSS\0"},	//(R0UL01RSS) Шаг (мс) измерения периода
	{89,"fEM_R7UX05RSS\0"},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{94,"fEM_R7UY06RSS\0"},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{67,"fEM_R0IN12FN2\0"},	//(R0IN12FN2) Коэффициент B (А2 к 1)
	{59,"fEM_A0UX00RSS\0"},	//(A0UX00RSS) Эффективный радиус АЗ
	{60,"fEM_A0UX04RSS\0"},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{72,"fEM_R0UH01RSS\0"},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
	{73,"fEM_R0UH02RSS\0"},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{88,"fEM_R7UX04RSS\0"},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{77,"fEM_R0UH22RSS\0"},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{66,"fEM_R0IN11FN2\0"},	//(R0IN11FN2) Коэффициент A (А2 к 1)
	{85,"fEM_R0UN03RSS\0"},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{61,"fEM_A0UX05RSS\0"},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{62,"fEM_A0UX06RSS\0"},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{64,"fEM_B0UX05RSS\0"},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{78,"fEM_R0UH23RSS\0"},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{69,"fEM_R0IN22FN2\0"},	//(R0IN22FN2) Коэффициент B (А2 к 2)
	{71,"fEM_R0IN32FN2\0"},	//(R0IN32FN2) Коэффициент B (А2 к 3)
	{81,"fEM_R0UL41RSS\0"},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{90,"fEM_R7UX06RSS\0"},	//(R7UX06RSS) Y-координата камеры R7IN23 (см)
	{92,"fEM_R7UY04RSS\0"},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{93,"fEM_R7UY05RSS\0"},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{63,"fEM_B0UX04RSS\0"},	//(B0UX04RSS) Второй коэффициент калибровки камеры4
	{68,"fEM_R0IN21FN2\0"},	//(R0IN21FN2) Коэффициент A (А2 к 2)
	{76,"fEM_R0UH21RSS\0"},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{70,"fEM_R0IN31FN2\0"},	//(R0IN31FN2) Коэффициент A (А2 к 3)
	{83,"fEM_R0UL51RSS\0"},	//(R0UL51RSS) Уровень АС по периоду разгона
	{74,"fEM_R0UH03RSS\0"},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{87,"fEM_R7UX00RSS\0"},	//(R7UX00RSS) X-координата АЗ1 (см)
	{91,"fEM_R7UY00RSS\0"},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{65,"fEM_B0UX06RSS\0"},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{75,"fEM_R0UH05RSS\0"},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_AKNP2[]={
	{&R0EE02LZ1,1,0},	//( - , AKNP2) Питание  АКНП  отключить
	{&R0EE02LZ2,1,1},	//( - , AKNP2) Питание  АКНП  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_AKNP2[]={
	{&A0EE02LS2,1,0},	//( - , AKNP2) Исправность АКНП2 (от сшивки каналов) канал 2
	{&TestDiagnAKNP2,1,1},	//( - , AKNP2) Неисправность от диагностики
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_AKNP2[]={
	{&R0VN03RS2,8,0},	//( - , AKNP2) Измеренный нейтронный поток канал 2
	{&R0VN04RS2,8,2},	//( - , AKNP2) Реактивность канал 2
	{&R0VN13RS2,8,4},	//( - , AKNP2) Нейтронный поток по камере СНМ11 канал 2
	{&R0VN23RS2,8,6},	//( - , AKNP2) Нейтронный поток по камере КНК15-1 канал 2
	{&R0VN33RS2,8,8},	//( - , AKNP2) Нейтронный поток по камере КНК53М канал 2
	{&R0VN15RS2,3,10},	//( - , AKNP2) Номер ведущей камеры канал 2
	{&TTLaknp2,3,11},	//( - , AKNP2) TTL
	{&R0IN01FS2,8,12},	//( - , AKNP2) Выход СНМ-11 Гц
	{&R0IN03FS2,8,14},	//( - , AKNP2) Выход КНК53М Гц
	{&R0IN02FS2,8,16},	//( - , AKNP2) Выход КНК15-1 Гц
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_AKNP2[]={
	{&fEM_R0UR01RSS,8,0},	//( - , AKNP2) Уставка АКНП блокировки автоматического подъёма ББ(имп/сек)
	{&fEM_R0UL52RSS,8,2},	//( - , AKNP2) Уровень АС по мощности
	{&fEM_R0UL41RSS,8,4},	//( - , AKNP2) Уровень ПС по периоду разгона
	{&fEM_R0UL51RSS,8,6},	//( - , AKNP2) Уровень АС по периоду разгона
	{&fEM_R0UH02RSS,8,8},	//( - , AKNP2) Коэфф. преобразования частота->нейтр/с КНК15-1
	{&fEM_R0UH03RSS,8,10},	//( - , AKNP2) Коэфф. преобразования частота->нейтр/с КНК53М
	{&fEM_R0UL42RSS,8,12},	//( - , AKNP2) Уровень ПС по мощности
	{&fEM_R7UX00RSS,8,14},	//( - , AKNP2) X-координата АЗ1 (см)
	{&fEM_R7UX04RSS,8,16},	//( - , AKNP2) X-координата камеры R7IN21 (см)
	{&fEM_R7UX05RSS,8,18},	//( - , AKNP2) X-координата камеры R7IN22 (см)
	{&fEM_R7UX06RSS,8,20},	//( - , AKNP2) Y-координата камеры R7IN23 (см)
	{&fEM_R7UY00RSS,8,22},	//( - , AKNP2) Y-координата АЗ1 (см)
	{&fEM_R7UY04RSS,8,24},	//( - , AKNP2) Y-координата камеры R7IN21 (см)
	{&fEM_R7UY05RSS,8,26},	//( - , AKNP2) Y-координата камеры R7IN22 (см)
	{&fEM_R7UY06RSS,8,28},	//( - , AKNP2) Y-координата камеры R7IN23 (см)
	{&fEM_A0UX00RSS,8,30},	//( - , AKNP2) Эффективный радиус АЗ
	{&fEM_A0UX04RSS,8,32},	//( - , AKNP2) Первый коэффициент калибровки камеры4
	{&fEM_A0UX05RSS,8,34},	//( - , AKNP2) Первый коэффициент калибровки камеры 5
	{&fEM_A0UX06RSS,8,36},	//( - , AKNP2) Первый коэффициент калибровки камеры 6
	{&fEM_B0UX04RSS,8,38},	//( - , AKNP2) Второй коэффициент калибровки камеры4
	{&fEM_B0UX05RSS,8,40},	//( - , AKNP2) Второй коэффициент калибровки камеры 5
	{&fEM_B0UX06RSS,8,42},	//( - , AKNP2) Второй коэффициент калибровки камеры 6
	{&fEM_R0UH05RSS,8,44},	//( - , AKNP2) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_R0UN03RSS,8,46},	//( - , AKNP2) Нижняя граница интервала мощности для измерения периода (ватт)
	{&fEM_R0UH01RSS,8,48},	//( - , AKNP2) Коэфф. преобразования частота->нейтр/с СНМ-11
	{&fEM_R0UH21RSS,8,50},	//( - , AKNP2) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{&fEM_R0UH22RSS,8,52},	//( - , AKNP2) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{&fEM_R0UH23RSS,8,54},	//( - , AKNP2) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{&fEM_R0UL02RSS,8,56},	//( - , AKNP2) Tф-постоянная времени, с
	{&fEM_R0UL01RSS,8,58},	//( - , AKNP2) Шаг (мс) измерения периода
	{&fEM_R0IN11FN2,8,60},	//( - , AKNP2) Коэффициент A (А2 к 1)
	{&fEM_R0IN12FN2,8,62},	//( - , AKNP2) Коэффициент B (А2 к 1)
	{&fEM_R0IN21FN2,8,64},	//( - , AKNP2) Коэффициент A (А2 к 2)
	{&fEM_R0IN22FN2,8,66},	//( - , AKNP2) Коэффициент B (А2 к 2)
	{&fEM_R0IN31FN2,8,68},	//( - , AKNP2) Коэффициент A (А2 к 3)
	{&fEM_R0IN32FN2,8,70},	//( - , AKNP2) Коэффициент B (А2 к 3)
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_A2Bz1[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_A2Bz1[]={
	{&R0VN61LS2,1,0},	//( - , A2Bz1, A2Bz2) ПС по мощности канал 2
	{&R0VN65LS2,1,1},	//( - , A2Bz1, A2Bz2) ПС по периоду разгона канал 2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_A2Bz1[]={
	{&R0VN02RS2,8,0},	//( - , A2Bz1, A2Bz2) Уровень мощности канал 2
	{&R0VN01RS2,8,2},	//( - , A2Bz1, A2Bz2) Период разгона канал 2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_A2Bz1[]={
	{&B8VC01RDU,8,0},	//( - , A2Bz1, A2Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_A2Bz2[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_A2Bz2[]={
	{&R0VN61LS2,1,0},	//( - , A2Bz1, A2Bz2) ПС по мощности канал 2
	{&R0VN65LS2,1,1},	//( - , A2Bz1, A2Bz2) ПС по периоду разгона канал 2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_A2Bz2[]={
	{&R0VN02RS2,8,0},	//( - , A2Bz1, A2Bz2) Уровень мощности канал 2
	{&R0VN01RS2,8,2},	//( - , A2Bz1, A2Bz2) Период разгона канал 2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_A2Bz2[]={
	{&B8VC01RDU,8,0},	//( - , A2Bz1, A2Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_DiagnAKNP2[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnAKNP2[]={
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
static ModbusRegister ir_DiagnAKNP2[]={
	{&R0DE05LS2,3,0},	//( - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 5 месте
	{&R0DE04LS2,3,1},	//( - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 4 месте
	{&R0DE02LS2,3,2},	//( - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 2 месте
	{&R0DE01LS2,3,3},	//( - Diagn, DiagnAKNP2) диагностика модуля АКНП2 на 1 месте
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DiagnAKNP2[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MA2S[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MA2S[]={
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MA2S[]={
	{&R0IN01FI2,8,0},	//( - , SA2) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI2,8,2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI2,8,4},	//( - , SA2) Выход КНК53М Гц от ПТИ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MA2S[]={
	{NULL,0,0},
};
#pragma pop
static char MA2S_ip1[]={"192.168.10.60\0"};
static char MA2S_ip2[]={"192.168.10.60\0"};
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_AKNP2[0],&di_AKNP2[0],&ir_AKNP2[0],&hr_AKNP2[0],NULL,NULL,NULL,0},	//общий slave AKNP2
	{0,5016,&coil_A2Bz1[0],&di_A2Bz1[0],&ir_A2Bz1[0],&hr_A2Bz1[0],NULL,NULL,NULL,0},	//slave AKNP2 - Baz1
	{0,5020,&coil_A2Bz2[0],&di_A2Bz2[0],&ir_A2Bz2[0],&hr_A2Bz2[0],NULL,NULL,NULL,0},	//slave AKNP2 - Baz2
	{0,5003,&coil_DiagnAKNP2[0],&di_DiagnAKNP2[0],&ir_DiagnAKNP2[0],&hr_DiagnAKNP2[0],NULL,NULL,NULL,0},	//Диагностика АКНП2
	{1,5007,&coil_MA2S[0],&di_MA2S[0],&ir_MA2S[0],&hr_MA2S[0],NULL,MA2S_ip1,MA2S_ip2,100},	//Мастер AKNP2 в SCM
	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},
};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS02[122];	//VCHS02
static vchs_inipar ini_VCHS02={0xc4,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_VCHS02={0,0,&ini_VCHS02,buf_VCHS02,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS02[]={
	{&R0DE02LS2,3,10},
	{&R0IN03FV2,8,0},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS32[194];	//VDS32
static vds32r_inipar ini_VDS32={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS32={0,0,&ini_VDS32,buf_VDS32,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32[]={
	{&R0DE04LS2,3,64},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS16[104];	//FDS16
static fds16r_inipar ini_FDS16={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS16={0,0,&ini_FDS16,buf_FDS16,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS16[]={
	{&A1EE01LS2,1,28},
	{&R0VN76LZ2,1,26},
	{&R0VN72LZ2,1,24},
	{&R0IE02LS2,1,0},
	{&R0IE01LS2,1,2},
	{&R0DE05LS2,3,38},
	{&A1VN71LS2,1,30},
	{&A0EE01LS2,1,20},
	{&R0VN76LZ1,1,18},
	{&R0VN72LZ1,1,16},
	{&A0VN71LS2,1,22},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/sbkfp7.h>
static char buf_SBKFP[90];	//SBKFP
static sbk_inipar ini_SBKFP={0xcc,0xff,8,8,0,0,0,};
#pragma pack(push,1)
static table_drv table_SBKFP={0,0,&ini_SBKFP,buf_SBKFP,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_SBKFP[]={
	{&R0DE38LS2,1,14},
	{&R0DE37LS2,1,12},
	{&R0DE35LS2,1,8},
	{&R0DE34LS2,1,6},
	{&R0DE33LS2,1,4},
	{&R0DE32LS2,1,2},
	{&R0DE31LS2,1,0},
	{&R0DE39LS2,1,16},
	{&R0DEB1LS2,1,18},
	{&R0DEB2LS2,1,20},
	{&R0DEB3LS2,1,22},
	{&R0DEB4LS2,1,24},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS01[122];	//VCHS01
static vchs_inipar ini_VCHS01={0xc4,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_VCHS01={0,0,&ini_VCHS01,buf_VCHS01,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS01[]={
	{&R0DE01LS2,3,10},
	{&R0IN02FV2,8,5},
	{&R0IN01FV2,8,0},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc2,0x04,19,194,def_buf_VDS32,&table_VDS32},	//VDS32
	{0x96,0x05,23,104,def_buf_FDS16,&table_FDS16},	//FDS16
	{0xcc,0x20,7,90,def_buf_SBKFP,&table_SBKFP},	//SBKFP
	{0xc4,0x01,27,122,def_buf_VCHS01,&table_VCHS01},	//VCHS01
	{0xc4,0x02,27,122,def_buf_VCHS02,&table_VCHS02},	//VCHS02
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){	//Инициализация переменных для хранения
	setAsFloat(89,1269.0);
	setAsFloat(94,287.2);
	setAsFloat(67,0);
	setAsFloat(59,11.0);
	setAsFloat(60,1.0);
	setAsFloat(72,20);
	setAsFloat(66,1);
	setAsFloat(73,37037.04 );
	setAsFloat(88,1555.0);
	setAsFloat(77,100000);
	setAsFloat(85,0.005);
	setAsFloat(78,1000000);
	setAsFloat(69,0);
	setAsFloat(61,1.0);
	setAsFloat(62,1.0);
	setAsFloat(64,0.0);
	setAsFloat(93,271.6);
	setAsFloat(63,0);
	setAsFloat(68,1);
	setAsFloat(71,0);
	setAsFloat(81,20);
	setAsFloat(90,1269.0);
	setAsFloat(92,248.0);
	setAsFloat(91,506.5);
	setAsFloat(65,0);
	setAsFloat(75,32000.0);
	setAsFloat(76,4000);
	setAsFloat(70,1);
	setAsFloat(83,13.0);
	setAsFloat(74,975000.0);
	setAsFloat(87,1570.00);
	setAsFloat(80,2.0);
	setAsFloat(79,0.5);
	setAsFloat(86,5000);
	setAsFloat(84,5100);
	setAsFloat(82,5000);
	setAsBool(29,1);
	setAsBool(30,1);
	setAsBool(31,1);
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

}/* Определение внутренних параметров */

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_5_ = {5,0}; /* n - N-размерность массива входных параметров */ 
ssint iRM_2_ = {2,0}; /* n - N-размерность массива входных параметров */ 
sschar bRM_2_ = {2,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива значений */ 
ssbool lRM_1_ = {1,0}; /*  */ 
ssfloat fRM_1_ = {1,0}; /* k - Kф-коэффициент усиления */ 
ssfloat fRM_3_ = {3,0}; /* tau - Tф-постоянная времени, с */ 


/* Определение переменных */
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m102_x_1[5] = {&var9,&var8,&R0DE37LS2,&R0DE38LS2,&R0DE39LS2};
psint  array_m88_x_1[4] = {&R0DE01LS2,&R0DE02LS2,&R0DE04LS2,&R0DE05LS2};
psbool  array_m64_x_1[2] = {&var30,&var25};
psbool  array_m63_x_1[2] = {&var30,&var31};
psbool  array_m72_x_1[5] = {&var17,&R0IE11LS2,&R0IE12LS2,&R0IE13LS2,&lRM_1_};

/* Объявление структур */
_S_mod1  S_mod1_56_1 = {&var23,&fRM_1_,&fRM_3_,&var1,&internal1_m56_y0};
_S_pogrvh  S_pogrvh_117_1 = {&R0IN03FV2,&fEM_R0IN31FN2,&fEM_R0IN32FN2,&var2};
_S_pogrvh  S_pogrvh_115_1 = {&R0IN02FV2,&fEM_R0IN21FN2,&fEM_R0IN22FN2,&var3};
_S_pogrvh  S_pogrvh_113_1 = {&R0IN01FV2,&fEM_R0IN11FN2,&fEM_R0IN12FN2,&var4};
_S_ml  S_ml_8_1 = {&R0IN03FI2,&var2,&R0IS01FI0,&var5};
_S_ml  S_ml_7_1 = {&R0IN02FI2,&var3,&R0IS01FI0,&var6};
_S_ml  S_ml_6_1 = {&R0IN01FI2,&var4,&R0IS01FI0,&var7};
_S_noto  S_noto_99_1 = {&var10,&vainSBool};
_S_or2  S_or2_105_1 = {&R0DEB3LS2,&R0DEB4LS2,&var8};
_S_or2  S_or2_96_1 = {&R0DEB1LS2,&R0DEB2LS2,&var9};
_S_or3  S_or3_98_1 = {&var13,&var12,&var11,&var10};
_S_orn  S_orn_102_1 = {array_m102_x_1,&iRM_5_,&var11};
_S_and2  S_and2_90_1 = {&R0DE31LS2,&R0DE32LS2,&var12};
_S_diagndev  S_diagndev_88_1 = {array_m88_x_1,&iRM_4_,&var13,&var14};
_S_ocham  S_ocham_19_1 = {&var7,&var6,&var5,&B8VC01RDU,&fEM_R7UX00RSS,&fEM_R7UY00RSS,&fEM_A0UX00RSS,&fEM_A0UX04RSS,&fEM_B0UX04RSS,&fEM_A0UX05RSS,&fEM_B0UX05RSS,&fEM_A0UX06RSS,&fEM_B0UX06RSS,&fEM_R7UX04RSS,&fEM_R7UY04RSS,&fEM_R7UX05RSS,&fEM_R7UY05RSS,&fEM_R7UX06RSS,&fEM_R7UY06RSS,&bRM_2_,&fEM_R0UH01RSS,&fEM_R0UH02RSS,&fEM_R0UH03RSS,&fEM_R0UH05RSS,&fEM_R0UH21RSS,&fEM_R0UH22RSS,&fEM_R0UH23RSS,&var15,&var16,&var17,&var18,&var19,&var20,&var21,&internal1_m19_Nk};
_S_or2  S_or2_75_1 = {&R0EE02LZ1,&R0EE02LZ2,&var22};
_S_period  S_period_55_1 = {&var16,&var27,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var23,&internal1_m55_flst,&internal1_m55_chsr,&internal1_m55_chizm,&internal1_m55_sumtim,&internal1_m55_W1,&internal1_m55_W2,&internal1_m55_Wmin,&internal1_m55_Wmax,&internal1_m55_Wlast,&internal1_m55_y0,&internal1_m55_MyFirstEnterFlag};
_S_andn  S_andn_64_1 = {array_m64_x_1,&iRM_2_,&var24};
_S_bol  S_bol_61_1 = {&fEM_R0UL41RSS,&var1,&var25};
_S_andn  S_andn_63_1 = {array_m63_x_1,&iRM_2_,&var26};
_S_andn  S_andn_72_1 = {array_m72_x_1,&iRM_5_,&var27};
_S_bol  S_bol_42_1 = {&var16,&fEM_R0UL52RSS,&var28};
_S_bol  S_bol_48_1 = {&var16,&fEM_R0UL42RSS,&var29};
_S_bol  S_bol_60_1 = {&var16,&fEM_R0UN03RSS,&var30};
_S_bol  S_bol_59_1 = {&fEM_R0UL51RSS,&var1,&var31};
_S_react  S_react_57_1 = {&var1,&var32};
_S_bol  S_bol_38_1 = {&var16,&fEM_R0UR01RSS,&var33};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  or2(&S_or2_75_1);
  diagndev(&S_diagndev_88_1);
  and2(&S_and2_90_1);
  or2(&S_or2_96_1);
  or2(&S_or2_105_1);
  orn(&S_orn_102_1);
  or3(&S_or3_98_1);
  noto(&S_noto_99_1);
  pogrvh(&S_pogrvh_113_1);
  pogrvh(&S_pogrvh_115_1);
  pogrvh(&S_pogrvh_117_1);
  ml(&S_ml_6_1);
  ml(&S_ml_7_1);
  ml(&S_ml_8_1);
  ocham(&S_ocham_19_1);
  bol(&S_bol_38_1);
  bol(&S_bol_60_1);
  bol(&S_bol_48_1);
  bol(&S_bol_42_1);
  andn(&S_andn_72_1);
  period(&S_period_55_1);
  mod1(&S_mod1_56_1);
  react(&S_react_57_1);
  bol(&S_bol_59_1);
  andn(&S_andn_63_1);
  bol(&S_bol_61_1);
  andn(&S_andn_64_1);
  setData(idR0IN02FS2,&var3);
  setData(idR0IN03FS2,&var2);
  setData(idR0IN01FS2,&var4);
  setData(idTestDiagnAKNP2,&var10);
  setData(idR0DE3DLS2,&var8);
  setData(idR0DE3CLS2,&var9);
  setData(idTTLaknp2,&var14);
  setData(idA0VN71LS2,&var33);
  setData(idA1EE01LS2,&var27);
  setData(idR0VN76LZ2,&var26);
  setData(idR0VN72LZ2,&var28);
  setData(idR0IE02LS2,&var22);
  setData(idR0IE01LS2,&var22);
  setData(idR0VN15RS2,&var21);
  setData(idR0VN33RS2,&var20);
  setData(idR0VN23RS2,&var19);
  setData(idR0VN13RS2,&var18);
  setData(idA0EE02LS2,&var17);
  setData(idA1VN71LS2,&var33);
  setData(idR0VN04RS2,&var32);
  setData(idR0VN03RS2,&var15);
  setData(idA0EE01LS2,&var27);
  setData(idR0VN76LZ1,&var26);
  setData(idR0VN65LS2,&var24);
  setData(idR0VN72LZ1,&var28);
  setData(idR0VN61LS2,&var29);
  setData(idR0VN01RS2,&var1);
  setData(idR0VN02RS2,&var16);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}
void MainCycle(void){
	Scheme();
}
#endif