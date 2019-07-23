#ifndef AKNP1_H
#defile AKNP1_H
// Подсистема  AKNP1:AKNP1
static char SimulOn=0;
static short CodeSub=3;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 //Время цикла мс
float takt,taktScheme=0,taktSS=0;
#define SIZE_BUFFER 539
static char BUFFER[SIZE_BUFFER];
#include <fp8/UDPTransport.h>
SetupUDP setUDP ={"192.168.10.51\0",5432,"192.168.10.151\0",5432,BUFFER,sizeof(BUFFER),};
int master=1,nomer=1;
#define A0EE01LS1	BUFFER[0]	// (fds16:05 - K11FDSR, - ) Исправность АКНП1 на БАЗ1
#define idA0EE01LS1	1	// (fds16:05 - K11FDSR, - ) Исправность АКНП1 на БАЗ1
#define A0EE02LS1	BUFFER[2]	// ( - , AKNP1) Исправность АКНП1 (от сшивки каналов) канал 1
#define idA0EE02LS1	2	// ( - , AKNP1) Исправность АКНП1 (от сшивки каналов) канал 1
#define A0VN71LS1	BUFFER[4]	// (fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ на БАЗ1
#define idA0VN71LS1	3	// (fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ на БАЗ1
#define A1EE01LS1	BUFFER[6]	// (fds16:05 - K15FDSR, - ) Исправность АКНП1 на БАЗ2
#define idA1EE01LS1	4	// (fds16:05 - K15FDSR, - ) Исправность АКНП1 на БАЗ2
#define A1VN71LS1	BUFFER[8]	// (fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ на БАЗ2
#define idA1VN71LS1	5	// (fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ на БАЗ2
#define B8VC01RDU	BUFFER[10]	// ( - , A1Bz1, A1Bz2) Координата АЗ2, мм
#define idB8VC01RDU	6	// ( - , A1Bz1, A1Bz2) Координата АЗ2, мм
#define R0DE01LS1	BUFFER[15]	// (vchs:01 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 1 месте
#define idR0DE01LS1	7	// (vchs:01 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 1 месте
#define R0DE02LS1	BUFFER[18]	// (vchs:02 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 2 месте
#define idR0DE02LS1	8	// (vchs:02 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 2 месте
#define R0DE04LS1	BUFFER[21]	// (vds32:04 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 4 месте
#define idR0DE04LS1	9	// (vds32:04 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 4 месте
#define R0DE05LS1	BUFFER[24]	// (fds16:05 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 5 месте
#define idR0DE05LS1	10	// (fds16:05 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 5 месте
#define R0DE31LS1	BUFFER[27]	// (sbk:20 - S01SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 1
#define idR0DE31LS1	11	// (sbk:20 - S01SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 1
#define R0DE32LS1	BUFFER[29]	// (sbk:20 - S02SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 2
#define idR0DE32LS1	12	// (sbk:20 - S02SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 2
#define R0DE33LS1	BUFFER[31]	// (sbk:20 - S03SBK, DiagnAKNP1) диагностика шкафа АКНП1 двери
#define idR0DE33LS1	13	// (sbk:20 - S03SBK, DiagnAKNP1) диагностика шкафа АКНП1 двери
#define R0DE34LS1	BUFFER[33]	// (sbk:20 - S04SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура меньше 43
#define idR0DE34LS1	14	// (sbk:20 - S04SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура меньше 43
#define R0DE35LS1	BUFFER[35]	// (sbk:20 - S05SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура больше 53
#define idR0DE35LS1	15	// (sbk:20 - S05SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура больше 53
#define R0DE37LS1	BUFFER[37]	// (sbk:20 - S07SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3.1 место 2
#define idR0DE37LS1	16	// (sbk:20 - S07SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3.1 место 2
#define R0DE38LS1	BUFFER[39]	// (sbk:20 - S08SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3 место 3
#define idR0DE38LS1	17	// (sbk:20 - S08SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3 место 3
#define R0DE39LS1	BUFFER[41]	// (sbk:20 - S09SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП24-2 место 4
#define idR0DE39LS1	18	// (sbk:20 - S09SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП24-2 место 4
#define R0DE3CLS1	BUFFER[43]	// ( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 7
#define idR0DE3CLS1	19	// ( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 7
#define R0DE3DLS1	BUFFER[45]	// ( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 8
#define idR0DE3DLS1	20	// ( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 8
#define R0DEB1LS1	BUFFER[47]	// (sbk:20 - S10SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 7
#define idR0DEB1LS1	21	// (sbk:20 - S10SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 7
#define R0DEB2LS1	BUFFER[49]	// (sbk:20 - S11SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 7
#define idR0DEB2LS1	22	// (sbk:20 - S11SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 7
#define R0DEB3LS1	BUFFER[51]	// (sbk:20 - S12SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 8
#define idR0DEB3LS1	23	// (sbk:20 - S12SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 8
#define R0DEB4LS1	BUFFER[53]	// (sbk:20 - S13SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 8
#define idR0DEB4LS1	24	// (sbk:20 - S13SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 8
#define R0EE01LZ1	BUFFER[55]	// ( - , AKNP1) Питание  АКНП1  отключить
#define idR0EE01LZ1	25	// ( - , AKNP1) Питание  АКНП1  отключить
#define R0EE01LZ2	BUFFER[57]	// ( - , AKNP1) Питание  АКНП1  отключить
#define idR0EE01LZ2	26	// ( - , AKNP1) Питание  АКНП1  отключить
#define R0IE01LS1	BUFFER[59]	// (fds16:05 - K02FDSR, - ) Отключение питание детекторов 1 канала
#define idR0IE01LS1	27	// (fds16:05 - K02FDSR, - ) Отключение питание детекторов 1 канала
#define R0IE02LS1	BUFFER[61]	// (fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ 1 канала
#define idR0IE02LS1	28	// (fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ 1 канала
#define R0IE11LS1	BUFFER[63]	// ( - , - ) Исправность ВИП 1,6 (№8) СНМ11 1 канала
#define idR0IE11LS1	29	// ( - , - ) Исправность ВИП 1,6 (№8) СНМ11 1 канала
#define R0IE12LS1	BUFFER[65]	// ( - , - ) Исправность ВИП 0,5 (№9) КНК15-1 1 канала
#define idR0IE12LS1	30	// ( - , - ) Исправность ВИП 0,5 (№9) КНК15-1 1 канала
#define R0IE13LS1	BUFFER[67]	// ( - , - ) Исправность ВИП 0,5 (№10) КНК53М 1 канала
#define idR0IE13LS1	31	// ( - , - ) Исправность ВИП 0,5 (№10) КНК53М 1 канала
#define R0IN01FI1	BUFFER[69]	// ( - , MA1S) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI1	32	// ( - , MA1S) Выход СНМ-11 Гц от ПТИ
#define R0IN01FS1	BUFFER[74]	// ( - , AKNP1) Выход СНМ-11 Гц
#define idR0IN01FS1	33	// ( - , AKNP1) Выход СНМ-11 Гц
#define R0IN01FV1	BUFFER[79]	// (vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
#define idR0IN01FV1	34	// (vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
#define R0IN02FI1	BUFFER[84]	// ( - , MA1S) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI1	35	// ( - , MA1S) Выход КНК15-1 Гц от ПТИ
#define R0IN02FS1	BUFFER[89]	// ( - , AKNP1) Выход КНК15-1 Гц
#define idR0IN02FS1	36	// ( - , AKNP1) Выход КНК15-1 Гц
#define R0IN02FV1	BUFFER[94]	// (vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
#define idR0IN02FV1	37	// (vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
#define R0IN03FI1	BUFFER[99]	// ( - , MA1S) Выход КНК53М Гц от ПТИ
#define idR0IN03FI1	38	// ( - , MA1S) Выход КНК53М Гц от ПТИ
#define R0IN03FS1	BUFFER[104]	// ( - , AKNP1) Выход КНК53М Гц
#define idR0IN03FS1	39	// ( - , AKNP1) Выход КНК53М Гц
#define R0IN03FV1	BUFFER[109]	// (vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
#define idR0IN03FV1	40	// (vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
#define R0IS01FI0	BUFFER[114]	// ( - , MA1S) Признак работы с имитатором
#define idR0IS01FI0	41	// ( - , MA1S) Признак работы с имитатором
#define R0VN01RS1	BUFFER[116]	// ( - , A1Bz1, A1Bz2) Период разгона канал1
#define idR0VN01RS1	42	// ( - , A1Bz1, A1Bz2) Период разгона канал1
#define R0VN02RS1	BUFFER[121]	// ( - , A1Bz1, A1Bz2) Уровень мощности
#define idR0VN02RS1	43	// ( - , A1Bz1, A1Bz2) Уровень мощности
#define R0VN03RS1	BUFFER[126]	// ( - , AKNP1) Измеренный нейтронный поток
#define idR0VN03RS1	44	// ( - , AKNP1) Измеренный нейтронный поток
#define R0VN04RS1	BUFFER[131]	// ( - , AKNP1) Реактивность канал1
#define idR0VN04RS1	45	// ( - , AKNP1) Реактивность канал1
#define R0VN13RS1	BUFFER[136]	// ( - , AKNP1) Нейтронный поток по камере СНМ11
#define idR0VN13RS1	46	// ( - , AKNP1) Нейтронный поток по камере СНМ11
#define R0VN15RS1	BUFFER[141]	// ( - , AKNP1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
#define idR0VN15RS1	47	// ( - , AKNP1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
#define R0VN23RS1	BUFFER[144]	// ( - , AKNP1) Нейтронный поток по камере КНК15-1
#define idR0VN23RS1	48	// ( - , AKNP1) Нейтронный поток по камере КНК15-1
#define R0VN33RS1	BUFFER[149]	// ( - , AKNP1) Нейтронный поток по камере КНК53М
#define idR0VN33RS1	49	// ( - , AKNP1) Нейтронный поток по камере КНК53М
#define R0VN61LS1	BUFFER[154]	// ( - , A1Bz1, A1Bz2) ПС по мощности канал1
#define idR0VN61LS1	50	// ( - , A1Bz1, A1Bz2) ПС по мощности канал1
#define R0VN65LS1	BUFFER[156]	// ( - , A1Bz1, A1Bz2) ПС по периоду разгона канал1
#define idR0VN65LS1	51	// ( - , A1Bz1, A1Bz2) ПС по периоду разгона канал1
#define R0VN71LZ1	BUFFER[158]	// (fds16:05 - K09FDSR, - ) АС по мощности на БАЗ1
#define idR0VN71LZ1	52	// (fds16:05 - K09FDSR, - ) АС по мощности на БАЗ1
#define R0VN71LZ2	BUFFER[160]	// (fds16:05 - K13FDSR, - ) АС по мощности на БАЗ2
#define idR0VN71LZ2	53	// (fds16:05 - K13FDSR, - ) АС по мощности на БАЗ2
#define R0VN75LZ1	BUFFER[162]	// (fds16:05 - K10FDSR, - ) АС по периоду разгонана БАЗ1
#define idR0VN75LZ1	54	// (fds16:05 - K10FDSR, - ) АС по периоду разгонана БАЗ1
#define R0VN75LZ2	BUFFER[164]	// (fds16:05 - K14FDSR, - ) АС по периоду разгонана БАЗ2
#define idR0VN75LZ2	55	// (fds16:05 - K14FDSR, - ) АС по периоду разгонана БАЗ2
#define TTLa1	BUFFER[166]	// ( - , AKNP1) ttl
#define idTTLa1	56	// ( - , AKNP1) ttl
#define TestDiagnAKNP1	BUFFER[169]	// ( - , AKNP1) Неисправность от диагностики
#define idTestDiagnAKNP1	57	// ( - , AKNP1) Неисправность от диагностики
#define bFirstEnterFlag	BUFFER[171]	// (bFirstEnterFlag) 
#define idbFirstEnterFlag	58	// (bFirstEnterFlag) 
#define fEM_A0UX00RSS	BUFFER[173]	// (A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	59	// (A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX01RSS	BUFFER[178]	// (A0UX01RSS) Первый коэффициент калибровки камеры 1
#define idfEM_A0UX01RSS	60	// (A0UX01RSS) Первый коэффициент калибровки камеры 1
#define fEM_A0UX02RSS	BUFFER[183]	// (A0UX02RSS) Первый коэффициент калибровки камеры 2
#define idfEM_A0UX02RSS	61	// (A0UX02RSS) Первый коэффициент калибровки камеры 2
#define fEM_A0UX03RSS	BUFFER[188]	// (A0UX03RSS) Первый коэффициент калибровки камеры 3
#define idfEM_A0UX03RSS	62	// (A0UX03RSS) Первый коэффициент калибровки камеры 3
#define fEM_B0UX01RSS	BUFFER[193]	// (B0UX01RSS) Второй коэффициент калибровки камеры 1
#define idfEM_B0UX01RSS	63	// (B0UX01RSS) Второй коэффициент калибровки камеры 1
#define fEM_B0UX02RSS	BUFFER[198]	// (B0UX02RSS) Второй коэффициент калибровки камеры 2
#define idfEM_B0UX02RSS	64	// (B0UX02RSS) Второй коэффициент калибровки камеры 2
#define fEM_B0UX03RSS	BUFFER[203]	// (B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	65	// (B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_R0IN11FN1	BUFFER[208]	// (R0IN11FN1) Коэффициент А (А1 к 1)
#define idfEM_R0IN11FN1	66	// (R0IN11FN1) Коэффициент А (А1 к 1)
#define fEM_R0IN12FN1	BUFFER[213]	// (R0IN12FN1) Коэффициент B (А1 к 1)
#define idfEM_R0IN12FN1	67	// (R0IN12FN1) Коэффициент B (А1 к 1)
#define fEM_R0IN21FN1	BUFFER[218]	// (R0IN21FN1) Коэффициент A (А1 к 2)
#define idfEM_R0IN21FN1	68	// (R0IN21FN1) Коэффициент A (А1 к 2)
#define fEM_R0IN22FN1	BUFFER[223]	// (R0IN22FN1) Коэффициент B (А1 к 2)
#define idfEM_R0IN22FN1	69	// (R0IN22FN1) Коэффициент B (А1 к 2)
#define fEM_R0IN31FN1	BUFFER[228]	// (R0IN31FN1) Коэффициент A (А1 к 3)
#define idfEM_R0IN31FN1	70	// (R0IN31FN1) Коэффициент A (А1 к 3)
#define fEM_R0IN32FN1	BUFFER[233]	// (R0IN32FN1) Коэффициент B (А1 к 3)
#define idfEM_R0IN32FN1	71	// (R0IN32FN1) Коэффициент B (А1 к 3)
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
#define fEM_R0UR01RSS	BUFFER[308]	// (R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RSS	86	// (R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R7UX00RSS	BUFFER[313]	// (R7UX00RSS) X-координата АЗ1 (см)
#define idfEM_R7UX00RSS	87	// (R7UX00RSS) X-координата АЗ1 (см)
#define fEM_R7UX01RSS	BUFFER[318]	// (R7UX01RSS) X-координата камеры R7IN11
#define idfEM_R7UX01RSS	88	// (R7UX01RSS) X-координата камеры R7IN11
#define fEM_R7UX02RSS	BUFFER[323]	// (R7UX02RSS) X-координата камеры R7IN12 (см)
#define idfEM_R7UX02RSS	89	// (R7UX02RSS) X-координата камеры R7IN12 (см)
#define fEM_R7UX03RSS	BUFFER[328]	// (R7UX03RSS) X-координата камеры R7IN13 (см)
#define idfEM_R7UX03RSS	90	// (R7UX03RSS) X-координата камеры R7IN13 (см)
#define fEM_R7UY00RSS	BUFFER[333]	// (R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	91	// (R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UY01RSS	BUFFER[338]	// (R7UY01RSS) Y-координата камеры R7IN11
#define idfEM_R7UY01RSS	92	// (R7UY01RSS) Y-координата камеры R7IN11
#define fEM_R7UY02RSS	BUFFER[343]	// (R7UY02RSS) Y-координата камеры R7IN12 (см)
#define idfEM_R7UY02RSS	93	// (R7UY02RSS) Y-координата камеры R7IN12 (см)
#define fEM_R7UY03RSS	BUFFER[348]	// (R7UY03RSS) Y-координата камеры R7IN13 (см)
#define idfEM_R7UY03RSS	94	// (R7UY03RSS) Y-координата камеры R7IN13 (см)
#define internal1_m17_Nk	BUFFER[353]	// (internal1_m17_Nk) Nk - ведущая камера
#define idinternal1_m17_Nk	95	// (internal1_m17_Nk) Nk - ведущая камера
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
#define var29	BUFFER[407]	// Внутренняя переменная var29
#define idvar29	30000	// Внутренняя переменная var29
#define var30	BUFFER[409]	// Внутренняя переменная var30
#define idvar30	30001	// Внутренняя переменная var30
#define vainSInt	BUFFER[411]	// Внутренняя переменная vainSInt
#define idvainSInt	30002	// Внутренняя переменная vainSInt
#define var7	BUFFER[414]	// Внутренняя переменная var7
#define idvar7	30003	// Внутренняя переменная var7
#define var8	BUFFER[419]	// Внутренняя переменная var8
#define idvar8	30004	// Внутренняя переменная var8
#define var12	BUFFER[421]	// Внутренняя переменная var12
#define idvar12	30005	// Внутренняя переменная var12
#define var17	BUFFER[423]	// Внутренняя переменная var17
#define idvar17	30006	// Внутренняя переменная var17
#define var27	BUFFER[425]	// Внутренняя переменная var27
#define idvar27	30007	// Внутренняя переменная var27
#define var1	BUFFER[427]	// Внутренняя переменная var1
#define idvar1	30008	// Внутренняя переменная var1
#define var10	BUFFER[432]	// Внутренняя переменная var10
#define idvar10	30009	// Внутренняя переменная var10
#define var11	BUFFER[434]	// Внутренняя переменная var11
#define idvar11	30010	// Внутренняя переменная var11
#define var14	BUFFER[436]	// Внутренняя переменная var14
#define idvar14	30011	// Внутренняя переменная var14
#define var18	BUFFER[438]	// Внутренняя переменная var18
#define idvar18	30012	// Внутренняя переменная var18
#define vainSBool	BUFFER[443]	// Внутренняя переменная vainSBool
#define idvainSBool	30013	// Внутренняя переменная vainSBool
#define var25	BUFFER[445]	// Внутренняя переменная var25
#define idvar25	30014	// Внутренняя переменная var25
#define var28	BUFFER[447]	// Внутренняя переменная var28
#define idvar28	30015	// Внутренняя переменная var28
#define var31	BUFFER[449]	// Внутренняя переменная var31
#define idvar31	30016	// Внутренняя переменная var31
#define vainSLong	BUFFER[451]	// Внутренняя переменная vainSLong
#define idvainSLong	30017	// Внутренняя переменная vainSLong
#define var13	BUFFER[460]	// Внутренняя переменная var13
#define idvar13	30018	// Внутренняя переменная var13
#define var20	BUFFER[462]	// Внутренняя переменная var20
#define idvar20	30019	// Внутренняя переменная var20
#define var21	BUFFER[464]	// Внутренняя переменная var21
#define idvar21	30020	// Внутренняя переменная var21
#define var26	BUFFER[469]	// Внутренняя переменная var26
#define idvar26	30021	// Внутренняя переменная var26
#define var33	BUFFER[474]	// Внутренняя переменная var33
#define idvar33	30022	// Внутренняя переменная var33
#define var6	BUFFER[476]	// Внутренняя переменная var6
#define idvar6	30023	// Внутренняя переменная var6
#define var15	BUFFER[481]	// Внутренняя переменная var15
#define idvar15	30024	// Внутренняя переменная var15
#define var23	BUFFER[484]	// Внутренняя переменная var23
#define idvar23	30025	// Внутренняя переменная var23
#define var32	BUFFER[489]	// Внутренняя переменная var32
#define idvar32	30026	// Внутренняя переменная var32
#define var5	BUFFER[494]	// Внутренняя переменная var5
#define idvar5	30027	// Внутренняя переменная var5
#define var16	BUFFER[499]	// Внутренняя переменная var16
#define idvar16	30028	// Внутренняя переменная var16
#define var19	BUFFER[501]	// Внутренняя переменная var19
#define idvar19	30029	// Внутренняя переменная var19
#define var22	BUFFER[506]	// Внутренняя переменная var22
#define idvar22	30030	// Внутренняя переменная var22
#define var24	BUFFER[511]	// Внутренняя переменная var24
#define idvar24	30031	// Внутренняя переменная var24
#define vainSFloat	BUFFER[514]	// Внутренняя переменная vainSFloat
#define idvainSFloat	30032	// Внутренняя переменная vainSFloat
#define vainSChar	BUFFER[519]	// Внутренняя переменная vainSChar
#define idvainSChar	30033	// Внутренняя переменная vainSChar
#define var2	BUFFER[522]	// Внутренняя переменная var2
#define idvar2	30034	// Внутренняя переменная var2
#define var3	BUFFER[527]	// Внутренняя переменная var3
#define idvar3	30035	// Внутренняя переменная var3
#define var4	BUFFER[532]	// Внутренняя переменная var4
#define idvar4	30036	// Внутренняя переменная var4
#define var9	BUFFER[537]	// Внутренняя переменная var9
#define idvar9	30037	// Внутренняя переменная var9
#pragma pack(push,1)
static VarCtrl allVariables[]={ 			 //Описание всех переменных
	 1	,1	,1	,&A0EE01LS1},	//(fds16:05 - K11FDSR, - ) Исправность АКНП1 на БАЗ1
	 2	,1	,1	,&A0EE02LS1},	//( - , AKNP1) Исправность АКНП1 (от сшивки каналов) канал 1
	 3	,1	,1	,&A0VN71LS1},	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ на БАЗ1
	 4	,1	,1	,&A1EE01LS1},	//(fds16:05 - K15FDSR, - ) Исправность АКНП1 на БАЗ2
	 5	,1	,1	,&A1VN71LS1},	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ на БАЗ2
	 6	,8	,1	,&B8VC01RDU},	//( - , A1Bz1, A1Bz2) Координата АЗ2, мм
	 7	,3	,1	,&R0DE01LS1},	//(vchs:01 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 1 месте
	 8	,3	,1	,&R0DE02LS1},	//(vchs:02 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 2 месте
	 9	,3	,1	,&R0DE04LS1},	//(vds32:04 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 4 месте
	 10	,3	,1	,&R0DE05LS1},	//(fds16:05 - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 5 месте
	 11	,1	,1	,&R0DE31LS1},	//(sbk:20 - S01SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 1
	 12	,1	,1	,&R0DE32LS1},	//(sbk:20 - S02SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 2
	 13	,1	,1	,&R0DE33LS1},	//(sbk:20 - S03SBK, DiagnAKNP1) диагностика шкафа АКНП1 двери
	 14	,1	,1	,&R0DE34LS1},	//(sbk:20 - S04SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура меньше 43
	 15	,1	,1	,&R0DE35LS1},	//(sbk:20 - S05SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура больше 53
	 16	,1	,1	,&R0DE37LS1},	//(sbk:20 - S07SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3.1 место 2
	 17	,1	,1	,&R0DE38LS1},	//(sbk:20 - S08SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3 место 3
	 18	,1	,1	,&R0DE39LS1},	//(sbk:20 - S09SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП24-2 место 4
	 19	,1	,1	,&R0DE3CLS1},	//( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 7
	 20	,1	,1	,&R0DE3DLS1},	//( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 8
	 21	,1	,1	,&R0DEB1LS1},	//(sbk:20 - S10SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 7
	 22	,1	,1	,&R0DEB2LS1},	//(sbk:20 - S11SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 7
	 23	,1	,1	,&R0DEB3LS1},	//(sbk:20 - S12SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 8
	 24	,1	,1	,&R0DEB4LS1},	//(sbk:20 - S13SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 8
	 25	,1	,1	,&R0EE01LZ1},	//( - , AKNP1) Питание  АКНП1  отключить
	 26	,1	,1	,&R0EE01LZ2},	//( - , AKNP1) Питание  АКНП1  отключить
	 27	,1	,1	,&R0IE01LS1},	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов 1 канала
	 28	,1	,1	,&R0IE02LS1},	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ 1 канала
	 29	,1	,1	,&R0IE11LS1},	//( - , - ) Исправность ВИП 1,6 (№8) СНМ11 1 канала
	 30	,1	,1	,&R0IE12LS1},	//( - , - ) Исправность ВИП 0,5 (№9) КНК15-1 1 канала
	 31	,1	,1	,&R0IE13LS1},	//( - , - ) Исправность ВИП 0,5 (№10) КНК53М 1 канала
	 32	,8	,1	,&R0IN01FI1},	//( - , MA1S) Выход СНМ-11 Гц от ПТИ
	 33	,8	,1	,&R0IN01FS1},	//( - , AKNP1) Выход СНМ-11 Гц
	 34	,8	,1	,&R0IN01FV1},	//(vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
	 35	,8	,1	,&R0IN02FI1},	//( - , MA1S) Выход КНК15-1 Гц от ПТИ
	 36	,8	,1	,&R0IN02FS1},	//( - , AKNP1) Выход КНК15-1 Гц
	 37	,8	,1	,&R0IN02FV1},	//(vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
	 38	,8	,1	,&R0IN03FI1},	//( - , MA1S) Выход КНК53М Гц от ПТИ
	 39	,8	,1	,&R0IN03FS1},	//( - , AKNP1) Выход КНК53М Гц
	 40	,8	,1	,&R0IN03FV1},	//(vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
	 41	,1	,1	,&R0IS01FI0},	//( - , MA1S) Признак работы с имитатором
	 42	,8	,1	,&R0VN01RS1},	//( - , A1Bz1, A1Bz2) Период разгона канал1
	 43	,8	,1	,&R0VN02RS1},	//( - , A1Bz1, A1Bz2) Уровень мощности
	 44	,8	,1	,&R0VN03RS1},	//( - , AKNP1) Измеренный нейтронный поток
	 45	,8	,1	,&R0VN04RS1},	//( - , AKNP1) Реактивность канал1
	 46	,8	,1	,&R0VN13RS1},	//( - , AKNP1) Нейтронный поток по камере СНМ11
	 47	,3	,1	,&R0VN15RS1},	//( - , AKNP1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
	 48	,8	,1	,&R0VN23RS1},	//( - , AKNP1) Нейтронный поток по камере КНК15-1
	 49	,8	,1	,&R0VN33RS1},	//( - , AKNP1) Нейтронный поток по камере КНК53М
	 50	,1	,1	,&R0VN61LS1},	//( - , A1Bz1, A1Bz2) ПС по мощности канал1
	 51	,1	,1	,&R0VN65LS1},	//( - , A1Bz1, A1Bz2) ПС по периоду разгона канал1
	 52	,1	,1	,&R0VN71LZ1},	//(fds16:05 - K09FDSR, - ) АС по мощности на БАЗ1
	 53	,1	,1	,&R0VN71LZ2},	//(fds16:05 - K13FDSR, - ) АС по мощности на БАЗ2
	 54	,1	,1	,&R0VN75LZ1},	//(fds16:05 - K10FDSR, - ) АС по периоду разгонана БАЗ1
	 55	,1	,1	,&R0VN75LZ2},	//(fds16:05 - K14FDSR, - ) АС по периоду разгонана БАЗ2
	 56	,3	,1	,&TTLa1},	//( - , AKNP1) ttl
	 57	,1	,1	,&TestDiagnAKNP1},	//( - , AKNP1) Неисправность от диагностики
	 58	,1	,1	,&bFirstEnterFlag},	//(bFirstEnterFlag) 
	 59	,8	,1	,&fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	 60	,8	,1	,&fEM_A0UX01RSS},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	 61	,8	,1	,&fEM_A0UX02RSS},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	 62	,8	,1	,&fEM_A0UX03RSS},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	 63	,8	,1	,&fEM_B0UX01RSS},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	 64	,8	,1	,&fEM_B0UX02RSS},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	 65	,8	,1	,&fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	 66	,8	,1	,&fEM_R0IN11FN1},	//(R0IN11FN1) Коэффициент А (А1 к 1)
	 67	,8	,1	,&fEM_R0IN12FN1},	//(R0IN12FN1) Коэффициент B (А1 к 1)
	 68	,8	,1	,&fEM_R0IN21FN1},	//(R0IN21FN1) Коэффициент A (А1 к 2)
	 69	,8	,1	,&fEM_R0IN22FN1},	//(R0IN22FN1) Коэффициент B (А1 к 2)
	 70	,8	,1	,&fEM_R0IN31FN1},	//(R0IN31FN1) Коэффициент A (А1 к 3)
	 71	,8	,1	,&fEM_R0IN32FN1},	//(R0IN32FN1) Коэффициент B (А1 к 3)
	 72	,8	,1	,&fEM_R0UH01RSS},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
	 73	,8	,1	,&fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	 74	,8	,1	,&fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	 75	,8	,1	,&fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	 76	,8	,1	,&fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	 77	,8	,1	,&fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	 78	,8	,1	,&fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	 79	,8	,1	,&fEM_R0UL01RSS},	//(R0UL01RSS) Шаг (мс) измерения периода
	 80	,8	,1	,&fEM_R0UL02RSS},	//(R0UL02RSS) Tф-постоянная времени, с
	 81	,8	,1	,&fEM_R0UL41RSS},	//(R0UL41RSS) Уровень ПС по периоду разгона
	 82	,8	,1	,&fEM_R0UL42RSS},	//(R0UL42RSS) Уровень ПС по мощности
	 83	,8	,1	,&fEM_R0UL51RSS},	//(R0UL51RSS) Уровень АС по периоду разгона
	 84	,8	,1	,&fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	 85	,8	,1	,&fEM_R0UN03RSS},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	 86	,8	,1	,&fEM_R0UR01RSS},	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
	 87	,8	,1	,&fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	 88	,8	,1	,&fEM_R7UX01RSS},	//(R7UX01RSS) X-координата камеры R7IN11
	 89	,8	,1	,&fEM_R7UX02RSS},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	 90	,8	,1	,&fEM_R7UX03RSS},	//(R7UX03RSS) X-координата камеры R7IN13 (см)
	 91	,8	,1	,&fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	 92	,8	,1	,&fEM_R7UY01RSS},	//(R7UY01RSS) Y-координата камеры R7IN11
	 93	,8	,1	,&fEM_R7UY02RSS},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	 94	,8	,1	,&fEM_R7UY03RSS},	//(R7UY03RSS) Y-координата камеры R7IN13 (см)
	 95	,3	,1	,&internal1_m17_Nk},	//(internal1_m17_Nk) Nk - ведущая камера
	 96	,1	,1	,&internal1_m55_MyFirstEnterFlag},	//(internal1_m55_MyFirstEnterFlag)  FirstEnterFlag
	 97	,8	,1	,&internal1_m55_W1},	//(internal1_m55_W1)  мощность на старте измерения
	 98	,8	,1	,&internal1_m55_W2},	//(internal1_m55_W2)  мощность в конце измерения
	 99	,8	,1	,&internal1_m55_Wlast},	//(internal1_m55_Wlast)  последнее растущее измерение
	 100	,8	,1	,&internal1_m55_Wmax},	//(internal1_m55_Wmax)  максимальное измерение в серии
	 101	,8	,1	,&internal1_m55_Wmin},	//(internal1_m55_Wmin)  минимальное измерение в серии
	 102	,3	,1	,&internal1_m55_chizm},	//(internal1_m55_chizm)  счетчик уменьшения мощности
	 103	,3	,1	,&internal1_m55_chsr},	//(internal1_m55_chsr)  счетчик усреднения
	 104	,3	,1	,&internal1_m55_flst},	//(internal1_m55_flst)  флаг старта измерения
	 105	,8	,1	,&internal1_m55_sumtim},	//(internal1_m55_sumtim)  время измерения мощности
	 106	,8	,1	,&internal1_m55_y0},	//(internal1_m55_y0) y0 - внутренний параметр
	 107	,8	,1	,&internal1_m56_y0},	//(internal1_m56_y0) y0 - внутренний параметр
	 30000	,1	,1	,&var29},	//Внутренняя переменная var29
	 30001	,1	,1	,&var30},	//Внутренняя переменная var30
	 30002	,3	,1	,&vainSInt},	//Внутренняя переменная vainSInt
	 30003	,8	,1	,&var7},	//Внутренняя переменная var7
	 30004	,1	,1	,&var8},	//Внутренняя переменная var8
	 30005	,1	,1	,&var12},	//Внутренняя переменная var12
	 30006	,1	,1	,&var17},	//Внутренняя переменная var17
	 30007	,1	,1	,&var27},	//Внутренняя переменная var27
	 30008	,8	,1	,&var1},	//Внутренняя переменная var1
	 30009	,1	,1	,&var10},	//Внутренняя переменная var10
	 30010	,1	,1	,&var11},	//Внутренняя переменная var11
	 30011	,1	,1	,&var14},	//Внутренняя переменная var14
	 30012	,8	,1	,&var18},	//Внутренняя переменная var18
	 30013	,1	,1	,&vainSBool},	//Внутренняя переменная vainSBool
	 30014	,1	,1	,&var25},	//Внутренняя переменная var25
	 30015	,1	,1	,&var28},	//Внутренняя переменная var28
	 30016	,1	,1	,&var31},	//Внутренняя переменная var31
	 30017	,11	,1	,&vainSLong},	//Внутренняя переменная vainSLong
	 30018	,1	,1	,&var13},	//Внутренняя переменная var13
	 30019	,1	,1	,&var20},	//Внутренняя переменная var20
	 30020	,8	,1	,&var21},	//Внутренняя переменная var21
	 30021	,8	,1	,&var26},	//Внутренняя переменная var26
	 30022	,1	,1	,&var33},	//Внутренняя переменная var33
	 30023	,8	,1	,&var6},	//Внутренняя переменная var6
	 30024	,3	,1	,&var15},	//Внутренняя переменная var15
	 30025	,8	,1	,&var23},	//Внутренняя переменная var23
	 30026	,8	,1	,&var32},	//Внутренняя переменная var32
	 30027	,8	,1	,&var5},	//Внутренняя переменная var5
	 30028	,1	,1	,&var16},	//Внутренняя переменная var16
	 30029	,8	,1	,&var19},	//Внутренняя переменная var19
	 30030	,8	,1	,&var22},	//Внутренняя переменная var22
	 30031	,3	,1	,&var24},	//Внутренняя переменная var24
	 30032	,8	,1	,&vainSFloat},	//Внутренняя переменная vainSFloat
	 30033	,	,1	,&vainSChar},	//Внутренняя переменная vainSChar
	 30034	,8	,1	,&var2},	//Внутренняя переменная var2
	 30035	,8	,1	,&var3},	//Внутренняя переменная var3
	 30036	,8	,1	,&var4},	//Внутренняя переменная var4
	 30037	,1	,1	,&var9},	//Внутренняя переменная var9
	{-1,0,NULL},
}
static char NameSaveFile[]="aknp1.bin\0"; //Имя файла сохранения переменных
#pragma pop
static VarSaveCtrl saveVariables[]={	//Id переменных для сохранения
	{89,"fEM_R7UX02RSS\0"},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{90,"fEM_R7UX03RSS\0"},	//(R7UX03RSS) X-координата камеры R7IN13 (см)
	{63,"fEM_B0UX01RSS\0"},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{64,"fEM_B0UX02RSS\0"},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{69,"fEM_R0IN22FN1\0"},	//(R0IN22FN1) Коэффициент B (А1 к 2)
	{82,"fEM_R0UL42RSS\0"},	//(R0UL42RSS) Уровень ПС по мощности
	{87,"fEM_R7UX00RSS\0"},	//(R7UX00RSS) X-координата АЗ1 (см)
	{85,"fEM_R0UN03RSS\0"},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{66,"fEM_R0IN11FN1\0"},	//(R0IN11FN1) Коэффициент А (А1 к 1)
	{60,"fEM_A0UX01RSS\0"},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{61,"fEM_A0UX02RSS\0"},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{79,"fEM_R0UL01RSS\0"},	//(R0UL01RSS) Шаг (мс) измерения периода
	{67,"fEM_R0IN12FN1\0"},	//(R0IN12FN1) Коэффициент B (А1 к 1)
	{68,"fEM_R0IN21FN1\0"},	//(R0IN21FN1) Коэффициент A (А1 к 2)
	{70,"fEM_R0IN31FN1\0"},	//(R0IN31FN1) Коэффициент A (А1 к 3)
	{86,"fEM_R0UR01RSS\0"},	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
	{81,"fEM_R0UL41RSS\0"},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{75,"fEM_R0UH05RSS\0"},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{72,"fEM_R0UH01RSS\0"},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
	{91,"fEM_R7UY00RSS\0"},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{93,"fEM_R7UY02RSS\0"},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{65,"fEM_B0UX03RSS\0"},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{77,"fEM_R0UH22RSS\0"},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{71,"fEM_R0IN32FN1\0"},	//(R0IN32FN1) Коэффициент B (А1 к 3)
	{84,"fEM_R0UL52RSS\0"},	//(R0UL52RSS) Уровень АС по мощности
	{59,"fEM_A0UX00RSS\0"},	//(A0UX00RSS) Эффективный радиус АЗ
	{74,"fEM_R0UH03RSS\0"},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{94,"fEM_R7UY03RSS\0"},	//(R7UY03RSS) Y-координата камеры R7IN13 (см)
	{62,"fEM_A0UX03RSS\0"},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{80,"fEM_R0UL02RSS\0"},	//(R0UL02RSS) Tф-постоянная времени, с
	{78,"fEM_R0UH23RSS\0"},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{83,"fEM_R0UL51RSS\0"},	//(R0UL51RSS) Уровень АС по периоду разгона
	{92,"fEM_R7UY01RSS\0"},	//(R7UY01RSS) Y-координата камеры R7IN11
	{76,"fEM_R0UH21RSS\0"},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{73,"fEM_R0UH02RSS\0"},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{88,"fEM_R7UX01RSS\0"},	//(R7UX01RSS) X-координата камеры R7IN11
	{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_AKNP1[]={
	{&R0EE01LZ2,2,1},	//( - , AKNP1) Питание  АКНП1  отключить
	{&R0EE01LZ1,2,0},	//( - , AKNP1) Питание  АКНП1  отключить
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_AKNP1[]={
	{&A0EE02LS1,2,0},	//( - , AKNP1) Исправность АКНП1 (от сшивки каналов) канал 1
	{&TestDiagnAKNP1,2,1},	//( - , AKNP1) Неисправность от диагностики
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_AKNP1[]={
	{&R0VN04RS1,8,2},	//( - , AKNP1) Реактивность канал1
	{&TTLa1,3,11},	//( - , AKNP1) ttl
	{&R0IN02FS1,8,16},	//( - , AKNP1) Выход КНК15-1 Гц
	{&R0VN23RS1,8,6},	//( - , AKNP1) Нейтронный поток по камере КНК15-1
	{&R0IN03FS1,8,14},	//( - , AKNP1) Выход КНК53М Гц
	{&R0VN33RS1,8,8},	//( - , AKNP1) Нейтронный поток по камере КНК53М
	{&R0VN15RS1,3,10},	//( - , AKNP1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
	{&R0IN01FS1,8,12},	//( - , AKNP1) Выход СНМ-11 Гц
	{&R0VN03RS1,8,0},	//( - , AKNP1) Измеренный нейтронный поток
	{&R0VN13RS1,8,4},	//( - , AKNP1) Нейтронный поток по камере СНМ11
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_AKNP1[]={
	{&fEM_R0UL52RSS,8,2},	//( - , AKNP1) Уровень АС по мощности
	{&fEM_R0IN22FN1,8,66},	//( - , AKNP1) Коэффициент B (А1 к 2)
	{&fEM_R0UL51RSS,8,6},	//( - , AKNP1) Уровень АС по периоду разгона
	{&fEM_R7UY00RSS,8,22},	//( - , AKNP1) Y-координата АЗ1 (см)
	{&fEM_R7UY02RSS,8,26},	//( - , AKNP1) Y-координата камеры R7IN12 (см)
	{&fEM_B0UX01RSS,8,38},	//( - , AKNP1) Второй коэффициент калибровки камеры 1
	{&fEM_R0UL02RSS,8,50},	//( - , AKNP1) Tф-постоянная времени, с
	{&fEM_A0UX01RSS,8,32},	//( - , AKNP1) Первый коэффициент калибровки камеры 1
	{&fEM_A0UX03RSS,8,36},	//( - , AKNP1) Первый коэффициент калибровки камеры 3
	{&fEM_R0UL01RSS,8,48},	//( - , AKNP1) Шаг (мс) измерения периода
	{&fEM_R0UH22RSS,8,56},	//( - , AKNP1) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{&fEM_R0IN12FN1,8,62},	//( - , AKNP1) Коэффициент B (А1 к 1)
	{&fEM_R0UL41RSS,8,4},	//( - , AKNP1) Уровень ПС по периоду разгона
	{&fEM_B0UX03RSS,8,42},	//( - , AKNP1) Второй коэффициент калибровки камеры 3
	{&fEM_R0UH21RSS,8,54},	//( - , AKNP1) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{&fEM_R7UX00RSS,8,14},	//( - , AKNP1) X-координата АЗ1 (см)
	{&fEM_R7UX02RSS,8,18},	//( - , AKNP1) X-координата камеры R7IN12 (см)
	{&fEM_R7UY03RSS,8,28},	//( - , AKNP1) Y-координата камеры R7IN13 (см)
	{&fEM_A0UX02RSS,8,34},	//( - , AKNP1) Первый коэффициент калибровки камеры 2
	{&fEM_B0UX02RSS,8,40},	//( - , AKNP1) Второй коэффициент калибровки камеры 2
	{&fEM_R0UH01RSS,8,52},	//( - , AKNP1) Коэфф. преобразования частота->нейтр/с СНМ-11
	{&fEM_R0UH02RSS,8,8},	//( - , AKNP1) Коэфф. преобразования частота->нейтр/с КНК15-1
	{&fEM_R7UY01RSS,8,24},	//( - , AKNP1) Y-координата камеры R7IN11
	{&fEM_R0UH05RSS,8,44},	//( - , AKNP1) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_R0UR01RSS,8,0},	//( - , AKNP1) Уставка АКНП ПС  АЗ по периоду (сек)
	{&fEM_R0UH03RSS,8,10},	//( - , AKNP1) Коэфф. преобразования частота->нейтр/с КНК53М
	{&fEM_R0IN21FN1,8,64},	//( - , AKNP1) Коэффициент A (А1 к 2)
	{&fEM_R0IN31FN1,8,68},	//( - , AKNP1) Коэффициент A (А1 к 3)
	{&fEM_R0IN32FN1,8,70},	//( - , AKNP1) Коэффициент B (А1 к 3)
	{&fEM_R0UL42RSS,8,12},	//( - , AKNP1) Уровень ПС по мощности
	{&fEM_R7UX01RSS,8,16},	//( - , AKNP1) X-координата камеры R7IN11
	{&fEM_R7UX03RSS,8,20},	//( - , AKNP1) X-координата камеры R7IN13 (см)
	{&fEM_A0UX00RSS,8,30},	//( - , AKNP1) Эффективный радиус АЗ
	{&fEM_R0UN03RSS,8,46},	//( - , AKNP1) Нижняя граница интервала мощности для измерения периода (ватт)
	{&fEM_R0UH23RSS,8,58},	//( - , AKNP1) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{&fEM_R0IN11FN1,8,60},	//( - , AKNP1) Коэффициент А (А1 к 1)
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_A1Bz1[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_A1Bz1[]={
	{&R0VN65LS1,2,1},	//( - , A1Bz1, A1Bz2) ПС по периоду разгона канал1
	{&R0VN61LS1,2,0},	//( - , A1Bz1, A1Bz2) ПС по мощности канал1
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_A1Bz1[]={
	{&R0VN02RS1,8,0},	//( - , A1Bz1, A1Bz2) Уровень мощности
	{&R0VN01RS1,8,2},	//( - , A1Bz1, A1Bz2) Период разгона канал1
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_A1Bz1[]={
	{&B8VC01RDU,8,0},	//( - , A1Bz1, A1Bz2) Координата АЗ2, мм
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_A1Bz2[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_A1Bz2[]={
	{&R0VN61LS1,2,0},	//( - , A1Bz1, A1Bz2) ПС по мощности канал1
	{&R0VN65LS1,2,1},	//( - , A1Bz1, A1Bz2) ПС по периоду разгона канал1
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_A1Bz2[]={
	{&R0VN02RS1,8,0},	//( - , A1Bz1, A1Bz2) Уровень мощности
	{&R0VN01RS1,8,2},	//( - , A1Bz1, A1Bz2) Период разгона канал1
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_A1Bz2[]={
	{&B8VC01RDU,8,0},	//( - , A1Bz1, A1Bz2) Координата АЗ2, мм
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_DiagnAKNP1[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnAKNP1[]={
	{&R0DE38LS1,2,7},	//( - S08SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3 место 3
	{&R0DE37LS1,2,8},	//( - S07SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП15-3.1 место 2
	{&R0DE35LS1,2,9},	//( - S05SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура больше 53
	{&R0DE31LS1,2,13},	//( - S01SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 1
	{&R0DEB1LS1,2,3},	//( - S10SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 7
	{&R0DE3CLS1,2,5},	//( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 7
	{&R0DE39LS1,2,6},	//( - S09SBK, DiagnAKNP1) диагностика шкафа АКНП1 МП24-2 место 4
	{&R0DE33LS1,2,11},	//( - S03SBK, DiagnAKNP1) диагностика шкафа АКНП1 двери
	{&R0DEB3LS1,2,0},	//( - S12SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП5 место 8
	{&R0DEB2LS1,2,2},	//( - S11SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 7
	{&R0DE34LS1,2,10},	//( - S04SBK, DiagnAKNP1) диагностика шкафа АКНП1 температура меньше 43
	{&R0DEB4LS1,2,1},	//( - S13SBK, DiagnAKNP1) диагностика шкафа АКНП1 БП24Д место 8
	{&R0DE3DLS1,2,4},	//( - , DiagnAKNP1) диагностика шкафа АКНП1 БП5/24Д место 8
	{&R0DE32LS1,2,12},	//( - S02SBK, DiagnAKNP1) диагностика шкафа АКНП1 сеть 2
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DiagnAKNP1[]={
	{&R0DE02LS1,3,2},	//( - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 2 месте
	{&R0DE01LS1,3,3},	//( - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 1 месте
	{&R0DE05LS1,3,0},	//( - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 5 месте
	{&R0DE04LS1,3,1},	//( - Diagn, DiagnAKNP1) диагностика модуля АКНП1 на 4 месте
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DiagnAKNP1[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MA1S[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MA1S[]={
	{&R0IS01FI0,2,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MA1S[]={
	{&R0IN01FI1,8,0},	//( - , SA1) Выход СНМ11 Гц от ПТИ
	{&R0IN02FI1,8,2},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI1,8,4},	//( - , SA1) Выход КНК53М Гц от ПТИ
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MA1S[]={
	{NULL,0,0},
}
#pragma pop
static char MA1S_ip1[]={"192.168.10.60\0"};
static char MA1S_ip2[]={"192.168.10.60\0"};
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_AKNP1[0],&di_AKNP1[0],&di_AKNP1[0],&hr_AKNP1[0],NULL,NULL,NULL,0},	//общий slave AKNP1
	{0,5015,&coil_A1Bz1[0],&di_A1Bz1[0],&di_A1Bz1[0],&hr_A1Bz1[0],NULL,NULL,NULL,0},	//slave AKNP1 - Baz1
	{0,5019,&coil_A1Bz2[0],&di_A1Bz2[0],&di_A1Bz2[0],&hr_A1Bz2[0],NULL,NULL,NULL,0},	//slave AKNP1 - Baz2
	{0,5003,&coil_DiagnAKNP1[0],&di_DiagnAKNP1[0],&di_DiagnAKNP1[0],&hr_DiagnAKNP1[0],NULL,NULL,NULL,0},	//Диагностика АКНП1
	{1,5006,&coil_MA1S[0],&di_MA1S[0],&di_MA1S[0],&hr_MA1S[0],NULL,MA1S_ip1,MA1S_ip2,100},	//Мастер AKNP1 в SCM
	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},
};
#pragma pop
#include <fp8/drivers/vchs2.h>/nstatic char buf_VCHS01[58];	//VCHS01
static vchs_inipar ini_VCHS01={0xc4,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,};
#pragma pack(push,1)
static table_drv table_VCHS01={0,0,&ini_VCHS01,buf_VCHS01,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS01[]={
	{(&R0DE01LS1,3,10},
	{(&R0IN02FV1,8,5},
	{(&R0IN01FV1,8,0},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vchs2.h>/nstatic char buf_VCHS02[58];	//VCHS02
static vchs_inipar ini_VCHS02={0xc4,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,};
#pragma pack(push,1)
static table_drv table_VCHS02={0,0,&ini_VCHS02,buf_VCHS02,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS02[]={
	{(&R0DE02LS1,3,10},
	{(&R0IN03FV1,8,0},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>/nstatic char buf_VDS32[132];	//VDS32
static vds32r_inipar ini_VDS32={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS32={0,0,&ini_VDS32,buf_VDS32,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32[]={
	{(&R0DE04LS1,3,64},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>/nstatic char buf_FDS16[40];	//FDS16
static fds16r_inipar ini_FDS16={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS16={0,0,&ini_FDS16,buf_FDS16,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS16[]={
	{(&A1EE01LS1,1,28},
	{(&R0VN75LZ2,1,26},
	{(&R0VN71LZ2,1,24},
	{(&R0IE02LS1,1,0},
	{(&R0IE01LS1,1,2},
	{(&R0DE05LS1,3,38},
	{(&A0VN71LS1,1,22},
	{(&A0EE01LS1,1,20},
	{(&R0VN75LZ1,1,18},
	{(&R0VN71LZ1,1,16},
	{(&A1VN71LS1,1,30},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/sbkfp7.h>/nstatic char buf_SBKFP[26];	//SBKFP
static sbk_inipar ini_SBKFP={0xcc,0xff,8,8,};
#pragma pack(push,1)
static table_drv table_SBKFP={0,0,&ini_SBKFP,buf_SBKFP,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_SBKFP[]={
	{(&R0DE38LS1,1,14},
	{(&R0DE37LS1,1,12},
	{(&R0DE35LS1,1,8},
	{(&R0DE34LS1,1,6},
	{(&R0DE33LS1,1,4},
	{(&R0DE32LS1,1,2},
	{(&R0DE31LS1,1,0},
	{(&R0DE39LS1,1,16},
	{(&R0DEB1LS1,1,18},
	{(&R0DEB2LS1,1,20},
	{(&R0DEB4LS1,1,24},
	{(&R0DEB3LS1,1,22},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Drive drivers[]={
	{0xc4,0x01,58,def_buf_VCHS01,&table_VCHS01},	//VCHS01
	{0xc4,0x02,58,def_buf_VCHS02,&table_VCHS02},	//VCHS02
	{0xc2,0x04,132,def_buf_VDS32,&table_VDS32},	//VDS32
	{0x96,0x05,40,def_buf_FDS16,&table_FDS16},	//FDS16
	{0xcc,0x20,26,def_buf_SBKFP,&table_SBKFP},	//SBKFP
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){	//Инициализация переменных для хранения
	setAsFloat(63,0);
	setAsFloat(64,0);
	setAsFloat(69,0);
	setAsFloat(82,5000);
	setAsFloat(87,1570.0);
	setAsFloat(89,1796.0);
	setAsFloat(90,1269.0);
	setAsFloat(85,0.005);
	setAsFloat(66,1);
	setAsFloat(79,0.5);
	setAsFloat(67,0);
	setAsFloat(68,1);
	setAsFloat(70,1);
	setAsFloat(86,5000);
	setAsFloat(81,20);
	setAsFloat(60,1.0);
	setAsFloat(61,1.0);
	setAsFloat(91,506.5);
	setAsFloat(93,284.5);
	setAsFloat(75,32000.0);
	setAsFloat(72,20);
	setAsFloat(71,0);
	setAsFloat(84,5100);
	setAsFloat(59,11.0);
	setAsFloat(65,0);
	setAsFloat(77,100000);
	setAsFloat(74,975000.0);
	setAsFloat(80,2.0);
	setAsFloat(78,1000000);
	setAsFloat(83,13.0);
	setAsFloat(92,248.0);
	setAsFloat(94,256.0);
	setAsFloat(62,1.0);
	setAsFloat(73,37037.04 );
	setAsFloat(88,1585.0);
	setAsFloat(76,4000);
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

}uspaint8 InternalBuf[56];
uspaint8 SpaEEPROMBuf[180];
void Scheme()
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
void InitInternalParametr(void)
void MainCycle(void){
	Scheme();
}
#endif