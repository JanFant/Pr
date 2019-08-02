#ifndef AKNP3_H
#define AKNP3_H
// Подсистема  AKNP3:AKNP3
static char SimulOn=0;
static short CodeSub=5;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 //Время цикла мс
float takt,taktScheme=0,taktSS=0;
#define SIZE_BUFFER 544
static char BUFFER[SIZE_BUFFER];
#include <fp8/UDPTransport.h>
SetupUDP setUDP ={"192.168.10.53\0",5432,"192.168.10.153\0",5432,BUFFER,sizeof(BUFFER),};
int master=1,nomer=1;
#define A0EE01LS3	BUFFER[0]	// (fds16:05 - K11FDSR, - ) Исправность АКНП канал 3 на БАЗ1
#define idA0EE01LS3	1	// (fds16:05 - K11FDSR, - ) Исправность АКНП канал 3 на БАЗ1
#define A0EE02LS3	BUFFER[2]	// ( - , AKNP3) Исправность АКНП3 (от сшивки каналов) канал 3
#define idA0EE02LS3	2	// ( - , AKNP3) Исправность АКНП3 (от сшивки каналов) канал 3
#define A0VN71LS3	BUFFER[4]	// (fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
#define idA0VN71LS3	3	// (fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
#define A1EE01LS3	BUFFER[6]	// (fds16:05 - K15FDSR, - ) Исправность АКНП канал 3 на БАЗ2
#define idA1EE01LS3	4	// (fds16:05 - K15FDSR, - ) Исправность АКНП канал 3 на БАЗ2
#define A1VN71LS3	BUFFER[8]	// (fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
#define idA1VN71LS3	5	// (fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
#define B8VC01RDU	BUFFER[10]	// ( - , A3Bz1, A3Bz2) Координата АЗ2, мм
#define idB8VC01RDU	6	// ( - , A3Bz1, A3Bz2) Координата АЗ2, мм
#define R0DE01LS3	BUFFER[15]	// (vchs:01 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 1 месте
#define idR0DE01LS3	7	// (vchs:01 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 1 месте
#define R0DE02LS3	BUFFER[18]	// (vchs:02 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 2 месте
#define idR0DE02LS3	8	// (vchs:02 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 2 месте
#define R0DE04LS3	BUFFER[21]	// (vds32:04 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 4 месте
#define idR0DE04LS3	9	// (vds32:04 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 4 месте
#define R0DE05LS3	BUFFER[24]	// (fds16:05 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 5 месте
#define idR0DE05LS3	10	// (fds16:05 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 5 месте
#define R0DE31LS3	BUFFER[27]	// (sbk:20 - S01SBK, DiagnAKNP3) диагностика шкафа АКНП3 сеть 1
#define idR0DE31LS3	11	// (sbk:20 - S01SBK, DiagnAKNP3) диагностика шкафа АКНП3 сеть 1
#define R0DE32LS3	BUFFER[29]	// (sbk:20 - S02SBK, DiagnAKNP3) диагностика шкафа АКНП3 сеть 2
#define idR0DE32LS3	12	// (sbk:20 - S02SBK, DiagnAKNP3) диагностика шкафа АКНП3 сеть 2
#define R0DE33LS3	BUFFER[31]	// (sbk:20 - S03SBK, DiagnAKNP3) диагностика шкафа АКНП3 двери
#define idR0DE33LS3	13	// (sbk:20 - S03SBK, DiagnAKNP3) диагностика шкафа АКНП3 двери
#define R0DE34LS3	BUFFER[33]	// (sbk:20 - S04SBK, DiagnAKNP3) диагностика шкафа АКНП3 температура меньше 43
#define idR0DE34LS3	14	// (sbk:20 - S04SBK, DiagnAKNP3) диагностика шкафа АКНП3 температура меньше 43
#define R0DE35LS3	BUFFER[35]	// (sbk:20 - S05SBK, DiagnAKNP3) диагностика шкафа АКНП3 температура больше 53
#define idR0DE35LS3	15	// (sbk:20 - S05SBK, DiagnAKNP3) диагностика шкафа АКНП3 температура больше 53
#define R0DE36LS3	BUFFER[37]	// (sbk:20 - S06SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3.1 место 1
#define idR0DE36LS3	16	// (sbk:20 - S06SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3.1 место 1
#define R0DE37LS3	BUFFER[39]	// (sbk:20 - S07SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3.1 место 2
#define idR0DE37LS3	17	// (sbk:20 - S07SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3.1 место 2
#define R0DE38LS3	BUFFER[41]	// (sbk:20 - S08SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3 место 3
#define idR0DE38LS3	18	// (sbk:20 - S08SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3 место 3
#define R0DE39LS3	BUFFER[43]	// (sbk:20 - S09SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП24-2 место 4
#define idR0DE39LS3	19	// (sbk:20 - S09SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП24-2 место 4
#define R0DE3CLS3	BUFFER[45]	// ( - , DiagnAKNP3) диагностика шкафа АКНП3 БП5/24Д место 7
#define idR0DE3CLS3	20	// ( - , DiagnAKNP3) диагностика шкафа АКНП3 БП5/24Д место 7
#define R0DE3DLS3	BUFFER[47]	// ( - , DiagnAKNP3) диагностика шкафа АКНП3 БП5/24Д место 8
#define idR0DE3DLS3	21	// ( - , DiagnAKNP3) диагностика шкафа АКНП3 БП5/24Д место 8
#define R0DEB1LS3	BUFFER[49]	// (sbk:20 - S10SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП5 место 7
#define idR0DEB1LS3	22	// (sbk:20 - S10SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП5 место 7
#define R0DEB2LS3	BUFFER[51]	// (sbk:20 - S11SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП24Д место 7
#define idR0DEB2LS3	23	// (sbk:20 - S11SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП24Д место 7
#define R0DEB3LS3	BUFFER[53]	// (sbk:20 - S12SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП5 место 8
#define idR0DEB3LS3	24	// (sbk:20 - S12SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП5 место 8
#define R0DEB4LS3	BUFFER[55]	// (sbk:20 - S13SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП24Д место 8
#define idR0DEB4LS3	25	// (sbk:20 - S13SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП24Д место 8
#define R0EE03LZ1	BUFFER[57]	// ( - , AKNP3) Питание  АКНП3  отключить
#define idR0EE03LZ1	26	// ( - , AKNP3) Питание  АКНП3  отключить
#define R0EE03LZ2	BUFFER[59]	// ( - , AKNP3) Питание  АКНП3  отключить
#define idR0EE03LZ2	27	// ( - , AKNP3) Питание  АКНП3  отключить
#define R0IE01LS3	BUFFER[61]	// (fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 3
#define idR0IE01LS3	28	// (fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 3
#define R0IE02LS3	BUFFER[63]	// (fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 3
#define idR0IE02LS3	29	// (fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 3
#define R0IE11LS3	BUFFER[65]	// ( - , - ) Исправность ВИП 1,6 (№14) СНМ11 3 канала
#define idR0IE11LS3	30	// ( - , - ) Исправность ВИП 1,6 (№14) СНМ11 3 канала
#define R0IE12LS3	BUFFER[67]	// ( - , - ) Исправность ВИП 0,5 (№15) КНК15-1 3 канала
#define idR0IE12LS3	31	// ( - , - ) Исправность ВИП 0,5 (№15) КНК15-1 3 канала
#define R0IE13LS3	BUFFER[69]	// ( - , - ) Исправность ВИП 0,5 (№16) КНК53М 3 канала
#define idR0IE13LS3	32	// ( - , - ) Исправность ВИП 0,5 (№16) КНК53М 3 канала
#define R0IN01FI3	BUFFER[71]	// ( - , MA3S) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI3	33	// ( - , MA3S) Выход СНМ-11 Гц от ПТИ
#define R0IN01FS3	BUFFER[76]	// ( - , AKNP3) Выход СНМ-11 Гц
#define idR0IN01FS3	34	// ( - , AKNP3) Выход СНМ-11 Гц
#define R0IN01FV3	BUFFER[81]	// (vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
#define idR0IN01FV3	35	// (vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
#define R0IN02FI3	BUFFER[86]	// ( - , MA3S) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI3	36	// ( - , MA3S) Выход КНК15-1 Гц от ПТИ
#define R0IN02FS3	BUFFER[91]	// ( - , AKNP3) Выход КНК15-1 Гц
#define idR0IN02FS3	37	// ( - , AKNP3) Выход КНК15-1 Гц
#define R0IN02FV3	BUFFER[96]	// (vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
#define idR0IN02FV3	38	// (vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
#define R0IN03FI3	BUFFER[101]	// ( - , MA3S) Выход КНК53М Гц от ПТИ
#define idR0IN03FI3	39	// ( - , MA3S) Выход КНК53М Гц от ПТИ
#define R0IN03FS3	BUFFER[106]	// ( - , - ) Выход КНК53М Гц
#define idR0IN03FS3	40	// ( - , - ) Выход КНК53М Гц
#define R0IN03FV3	BUFFER[111]	// (vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
#define idR0IN03FV3	41	// (vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
#define R0IS01FI0	BUFFER[116]	// ( - , MA3S) Признак работы с имитатором
#define idR0IS01FI0	42	// ( - , MA3S) Признак работы с имитатором
#define R0VN01RS3	BUFFER[118]	// ( - , A3Bz1, A3Bz2) Период разгона канал 3
#define idR0VN01RS3	43	// ( - , A3Bz1, A3Bz2) Период разгона канал 3
#define R0VN02RS3	BUFFER[123]	// ( - , A3Bz1, A3Bz2) Уровень мощности канал 3
#define idR0VN02RS3	44	// ( - , A3Bz1, A3Bz2) Уровень мощности канал 3
#define R0VN03RS3	BUFFER[128]	// ( - , AKNP3) Измеренный нейтронный поток канал 3
#define idR0VN03RS3	45	// ( - , AKNP3) Измеренный нейтронный поток канал 3
#define R0VN04RS3	BUFFER[133]	// ( - , AKNP3) Реактивность канал 3
#define idR0VN04RS3	46	// ( - , AKNP3) Реактивность канал 3
#define R0VN13RS3	BUFFER[138]	// ( - , AKNP3) Нейтронный поток по камере СНМ11 канал 3
#define idR0VN13RS3	47	// ( - , AKNP3) Нейтронный поток по камере СНМ11 канал 3
#define R0VN15RS3	BUFFER[143]	// ( - , AKNP3) Номер ведущей камеры канал 3
#define idR0VN15RS3	48	// ( - , AKNP3) Номер ведущей камеры канал 3
#define R0VN23RS3	BUFFER[146]	// ( - , AKNP3) Нейтронный поток по камере КНК15-1 канал 3
#define idR0VN23RS3	49	// ( - , AKNP3) Нейтронный поток по камере КНК15-1 канал 3
#define R0VN33RS3	BUFFER[151]	// ( - , AKNP3) Нейтронный поток по камере КНК53М канал 3
#define idR0VN33RS3	50	// ( - , AKNP3) Нейтронный поток по камере КНК53М канал 3
#define R0VN61LS3	BUFFER[156]	// ( - , A3Bz1, A3Bz2) ПС по мощности канал 3
#define idR0VN61LS3	51	// ( - , A3Bz1, A3Bz2) ПС по мощности канал 3
#define R0VN65LS3	BUFFER[158]	// ( - , A3Bz1, A3Bz2) ПС по периоду разгона канал 3
#define idR0VN65LS3	52	// ( - , A3Bz1, A3Bz2) ПС по периоду разгона канал 3
#define R0VN73LZ1	BUFFER[160]	// (fds16:05 - K09FDSR, - ) АС по мощности канал 3 на БАЗ1
#define idR0VN73LZ1	53	// (fds16:05 - K09FDSR, - ) АС по мощности канал 3 на БАЗ1
#define R0VN73LZ2	BUFFER[162]	// (fds16:05 - K13FDSR, - ) АС по мощности канал 3 на БАЗ2
#define idR0VN73LZ2	54	// (fds16:05 - K13FDSR, - ) АС по мощности канал 3 на БАЗ2
#define R0VN77LZ1	BUFFER[164]	// (fds16:05 - K10FDSR, - ) АС по периоду разгона канал 3 на БАЗ1
#define idR0VN77LZ1	55	// (fds16:05 - K10FDSR, - ) АС по периоду разгона канал 3 на БАЗ1
#define R0VN77LZ2	BUFFER[166]	// (fds16:05 - K14FDSR, - ) АС по периоду разгона канал 3 на БАЗ2
#define idR0VN77LZ2	56	// (fds16:05 - K14FDSR, - ) АС по периоду разгона канал 3 на БАЗ2
#define TTLaknp3	BUFFER[168]	// ( - , AKNP3) ttl
#define idTTLaknp3	57	// ( - , AKNP3) ttl
#define TestDiagnAKNP3	BUFFER[171]	// ( - , AKNP3) Неисправность от диагностики
#define idTestDiagnAKNP3	58	// ( - , AKNP3) Неисправность от диагностики
#define bFirstEnterFlag	BUFFER[173]	// (bFirstEnterFlag) 
#define idbFirstEnterFlag	59	// (bFirstEnterFlag) 
#define fEM_A0UX00RSS	BUFFER[175]	// (A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	60	// (A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX07RSS	BUFFER[180]	// (A0UX07RSS) Первый коэффициент калибровки камеры 7
#define idfEM_A0UX07RSS	61	// (A0UX07RSS) Первый коэффициент калибровки камеры 7
#define fEM_A0UX08RSS	BUFFER[185]	// (A0UX08RSS) Первый коэффициент калибровки камеры 8
#define idfEM_A0UX08RSS	62	// (A0UX08RSS) Первый коэффициент калибровки камеры 8
#define fEM_A0UX09RSS	BUFFER[190]	// (A0UX09RSS) Первый коэффициент калибровки камеры 9
#define idfEM_A0UX09RSS	63	// (A0UX09RSS) Первый коэффициент калибровки камеры 9
#define fEM_B0UX07RSS	BUFFER[195]	// (B0UX07RSS) Второй коэффициент калибровки камеры 7
#define idfEM_B0UX07RSS	64	// (B0UX07RSS) Второй коэффициент калибровки камеры 7
#define fEM_B0UX08RSS	BUFFER[200]	// (B0UX08RSS) Второй коэффициент калибровки камеры 8
#define idfEM_B0UX08RSS	65	// (B0UX08RSS) Второй коэффициент калибровки камеры 8
#define fEM_B0UX09RSS	BUFFER[205]	// (B0UX09RSS) Второй коэффициент калибровки камеры 9
#define idfEM_B0UX09RSS	66	// (B0UX09RSS) Второй коэффициент калибровки камеры 9
#define fEM_R0IN11FN3	BUFFER[210]	// (R0IN11FN3) Коэффициент A (А3 к 1)
#define idfEM_R0IN11FN3	67	// (R0IN11FN3) Коэффициент A (А3 к 1)
#define fEM_R0IN12FN3	BUFFER[215]	// (R0IN12FN3) Коэффициент B (А3 к 1)
#define idfEM_R0IN12FN3	68	// (R0IN12FN3) Коэффициент B (А3 к 1)
#define fEM_R0IN21FN3	BUFFER[220]	// (R0IN21FN3) Коэффициент A (А3 к 2)
#define idfEM_R0IN21FN3	69	// (R0IN21FN3) Коэффициент A (А3 к 2)
#define fEM_R0IN22FN3	BUFFER[225]	// (R0IN22FN3) Коэффициент B (А3 к 2)
#define idfEM_R0IN22FN3	70	// (R0IN22FN3) Коэффициент B (А3 к 2)
#define fEM_R0IN31FN3	BUFFER[230]	// (R0IN31FN3) Коэффициент A (А3 к 3)
#define idfEM_R0IN31FN3	71	// (R0IN31FN3) Коэффициент A (А3 к 3)
#define fEM_R0IN32FN3	BUFFER[235]	// (R0IN32FN3) Коэффициент B (А3 к 3)
#define idfEM_R0IN32FN3	72	// (R0IN32FN3) Коэффициент B (А3 к 3)
#define fEM_R0UH01RSS	BUFFER[240]	// (R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
#define idfEM_R0UH01RSS	73	// (R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
#define fEM_R0UH02RSS	BUFFER[245]	// (R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define idfEM_R0UH02RSS	74	// (R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
#define fEM_R0UH03RSS	BUFFER[250]	// (R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define idfEM_R0UH03RSS	75	// (R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
#define fEM_R0UH05RSS	BUFFER[255]	// (R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	76	// (R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UH21RSS	BUFFER[260]	// (R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	77	// (R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	BUFFER[265]	// (R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	78	// (R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	BUFFER[270]	// (R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	79	// (R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0UL01RSS	BUFFER[275]	// (R0UL01RSS) Шаг (мс) измерения периода
#define idfEM_R0UL01RSS	80	// (R0UL01RSS) Шаг (мс) измерения периода
#define fEM_R0UL02RSS	BUFFER[280]	// (R0UL02RSS) Tф-постоянная времени, с
#define idfEM_R0UL02RSS	81	// (R0UL02RSS) Tф-постоянная времени, с
#define fEM_R0UL41RSS	BUFFER[285]	// (R0UL41RSS) Уровень ПС по периоду разгона
#define idfEM_R0UL41RSS	82	// (R0UL41RSS) Уровень ПС по периоду разгона
#define fEM_R0UL42RSS	BUFFER[290]	// (R0UL42RSS) Уровень ПС по мощности
#define idfEM_R0UL42RSS	83	// (R0UL42RSS) Уровень ПС по мощности
#define fEM_R0UL51RSS	BUFFER[295]	// (R0UL51RSS) Уровень АС по периоду разгона
#define idfEM_R0UL51RSS	84	// (R0UL51RSS) Уровень АС по периоду разгона
#define fEM_R0UL52RSS	BUFFER[300]	// (R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	85	// (R0UL52RSS) Уровень АС по мощности
#define fEM_R0UN03RSS	BUFFER[305]	// (R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN03RSS	86	// (R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R0UR01RSS	BUFFER[310]	// (R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RSS	87	// (R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R7UX00RSS	BUFFER[315]	// (R7UX00RSS) X-координата АЗ1 (см)
#define idfEM_R7UX00RSS	88	// (R7UX00RSS) X-координата АЗ1 (см)
#define fEM_R7UX07RSS	BUFFER[320]	// (R7UX07RSS) X-координата камеры R7IN31 (см)
#define idfEM_R7UX07RSS	89	// (R7UX07RSS) X-координата камеры R7IN31 (см)
#define fEM_R7UX08RSS	BUFFER[325]	// (R7UX08RSS) X-координата камеры R7IN32 (см)
#define idfEM_R7UX08RSS	90	// (R7UX08RSS) X-координата камеры R7IN32 (см)
#define fEM_R7UX09RSS	BUFFER[330]	// (R7UX09RSS) X-координата камеры R7IN33 (см)
#define idfEM_R7UX09RSS	91	// (R7UX09RSS) X-координата камеры R7IN33 (см)
#define fEM_R7UY00RSS	BUFFER[335]	// (R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	92	// (R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UY07RSS	BUFFER[340]	// (R7UY07RSS) Y-координата камеры R7IN31 (см)
#define idfEM_R7UY07RSS	93	// (R7UY07RSS) Y-координата камеры R7IN31 (см)
#define fEM_R7UY08RSS	BUFFER[345]	// (R7UY08RSS) Y-координата камеры R7IN32 (см)
#define idfEM_R7UY08RSS	94	// (R7UY08RSS) Y-координата камеры R7IN32 (см)
#define fEM_R7UY09RSS	BUFFER[350]	// (R7UY09RSS) Y-координата камеры R7IN33 (см)
#define idfEM_R7UY09RSS	95	// (R7UY09RSS) Y-координата камеры R7IN33 (см)
#define internal1_m19_Nk	BUFFER[355]	// (internal1_m19_Nk) Nk - ведущая камера
#define idinternal1_m19_Nk	96	// (internal1_m19_Nk) Nk - ведущая камера
#define internal1_m55_MyFirstEnterFlag	BUFFER[358]	// (internal1_m55_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m55_MyFirstEnterFlag	97	// (internal1_m55_MyFirstEnterFlag)  FirstEnterFlag
#define internal1_m55_W1	BUFFER[360]	// (internal1_m55_W1)  мощность на старте измерения
#define idinternal1_m55_W1	98	// (internal1_m55_W1)  мощность на старте измерения
#define internal1_m55_W2	BUFFER[365]	// (internal1_m55_W2)  мощность в конце измерения
#define idinternal1_m55_W2	99	// (internal1_m55_W2)  мощность в конце измерения
#define internal1_m55_Wlast	BUFFER[370]	// (internal1_m55_Wlast)  последнее растущее измерение
#define idinternal1_m55_Wlast	100	// (internal1_m55_Wlast)  последнее растущее измерение
#define internal1_m55_Wmax	BUFFER[375]	// (internal1_m55_Wmax)  максимальное измерение в серии
#define idinternal1_m55_Wmax	101	// (internal1_m55_Wmax)  максимальное измерение в серии
#define internal1_m55_Wmin	BUFFER[380]	// (internal1_m55_Wmin)  минимальное измерение в серии
#define idinternal1_m55_Wmin	102	// (internal1_m55_Wmin)  минимальное измерение в серии
#define internal1_m55_chizm	BUFFER[385]	// (internal1_m55_chizm)  счетчик уменьшения мощности
#define idinternal1_m55_chizm	103	// (internal1_m55_chizm)  счетчик уменьшения мощности
#define internal1_m55_chsr	BUFFER[388]	// (internal1_m55_chsr)  счетчик усреднения
#define idinternal1_m55_chsr	104	// (internal1_m55_chsr)  счетчик усреднения
#define internal1_m55_flst	BUFFER[391]	// (internal1_m55_flst)  флаг старта измерения
#define idinternal1_m55_flst	105	// (internal1_m55_flst)  флаг старта измерения
#define internal1_m55_sumtim	BUFFER[394]	// (internal1_m55_sumtim)  время измерения мощности
#define idinternal1_m55_sumtim	106	// (internal1_m55_sumtim)  время измерения мощности
#define internal1_m55_y0	BUFFER[399]	// (internal1_m55_y0) y0 - внутренний параметр
#define idinternal1_m55_y0	107	// (internal1_m55_y0) y0 - внутренний параметр
#define internal1_m56_y0	BUFFER[404]	// (internal1_m56_y0) y0 - внутренний параметр
#define idinternal1_m56_y0	108	// (internal1_m56_y0) y0 - внутренний параметр
#define var5	BUFFER[409]	// Внутренняя переменная var5
#define idvar5	109	// Внутренняя переменная var5
#define var8	BUFFER[414]	// Внутренняя переменная var8
#define idvar8	110	// Внутренняя переменная var8
#define var10	BUFFER[416]	// Внутренняя переменная var10
#define idvar10	111	// Внутренняя переменная var10
#define var27	BUFFER[418]	// Внутренняя переменная var27
#define idvar27	112	// Внутренняя переменная var27
#define var6	BUFFER[420]	// Внутренняя переменная var6
#define idvar6	113	// Внутренняя переменная var6
#define var14	BUFFER[425]	// Внутренняя переменная var14
#define idvar14	114	// Внутренняя переменная var14
#define var22	BUFFER[430]	// Внутренняя переменная var22
#define idvar22	115	// Внутренняя переменная var22
#define var31	BUFFER[432]	// Внутренняя переменная var31
#define idvar31	116	// Внутренняя переменная var31
#define vainSFloat	BUFFER[434]	// Внутренняя переменная vainSFloat
#define idvainSFloat	117	// Внутренняя переменная vainSFloat
#define var19	BUFFER[439]	// Внутренняя переменная var19
#define idvar19	118	// Внутренняя переменная var19
#define var20	BUFFER[444]	// Внутренняя переменная var20
#define idvar20	119	// Внутренняя переменная var20
#define var24	BUFFER[449]	// Внутренняя переменная var24
#define idvar24	120	// Внутренняя переменная var24
#define var4	BUFFER[451]	// Внутренняя переменная var4
#define idvar4	121	// Внутренняя переменная var4
#define var13	BUFFER[456]	// Внутренняя переменная var13
#define idvar13	122	// Внутренняя переменная var13
#define var15	BUFFER[458]	// Внутренняя переменная var15
#define idvar15	123	// Внутренняя переменная var15
#define var32	BUFFER[463]	// Внутренняя переменная var32
#define idvar32	124	// Внутренняя переменная var32
#define vainSLong	BUFFER[468]	// Внутренняя переменная vainSLong
#define idvainSLong	125	// Внутренняя переменная vainSLong
#define vainSInt	BUFFER[477]	// Внутренняя переменная vainSInt
#define idvainSInt	126	// Внутренняя переменная vainSInt
#define var7	BUFFER[482]	// Внутренняя переменная var7
#define idvar7	127	// Внутренняя переменная var7
#define var9	BUFFER[487]	// Внутренняя переменная var9
#define idvar9	128	// Внутренняя переменная var9
#define var11	BUFFER[489]	// Внутренняя переменная var11
#define idvar11	129	// Внутренняя переменная var11
#define var26	BUFFER[491]	// Внутренняя переменная var26
#define idvar26	130	// Внутренняя переменная var26
#define var30	BUFFER[493]	// Внутренняя переменная var30
#define idvar30	131	// Внутренняя переменная var30
#define var3	BUFFER[495]	// Внутренняя переменная var3
#define idvar3	132	// Внутренняя переменная var3
#define var12	BUFFER[500]	// Внутренняя переменная var12
#define idvar12	133	// Внутренняя переменная var12
#define var23	BUFFER[502]	// Внутренняя переменная var23
#define idvar23	134	// Внутренняя переменная var23
#define var25	BUFFER[507]	// Внутренняя переменная var25
#define idvar25	135	// Внутренняя переменная var25
#define var28	BUFFER[509]	// Внутренняя переменная var28
#define idvar28	136	// Внутренняя переменная var28
#define var33	BUFFER[511]	// Внутренняя переменная var33
#define idvar33	137	// Внутренняя переменная var33
#define var1	BUFFER[513]	// Внутренняя переменная var1
#define idvar1	138	// Внутренняя переменная var1
#define var2	BUFFER[518]	// Внутренняя переменная var2
#define idvar2	139	// Внутренняя переменная var2
#define var16	BUFFER[523]	// Внутренняя переменная var16
#define idvar16	140	// Внутренняя переменная var16
#define var17	BUFFER[528]	// Внутренняя переменная var17
#define idvar17	141	// Внутренняя переменная var17
#define var18	BUFFER[530]	// Внутренняя переменная var18
#define idvar18	142	// Внутренняя переменная var18
#define var21	BUFFER[535]	// Внутренняя переменная var21
#define idvar21	143	// Внутренняя переменная var21
#define var29	BUFFER[540]	// Внутренняя переменная var29
#define idvar29	144	// Внутренняя переменная var29
#define vainSBool	BUFFER[542]	// Внутренняя переменная vainSBool
#define idvainSBool	145	// Внутренняя переменная vainSBool
#pragma pack(push,1)
static VarCtrl allVariables[]={ 			 //Описание всех переменных
	{1	,1	,1	,&A0EE01LS3},	//(fds16:05 - K11FDSR, - ) Исправность АКНП канал 3 на БАЗ1
	{2	,1	,1	,&A0EE02LS3},	//( - , AKNP3) Исправность АКНП3 (от сшивки каналов) канал 3
	{3	,1	,1	,&A0VN71LS3},	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
	{4	,1	,1	,&A1EE01LS3},	//(fds16:05 - K15FDSR, - ) Исправность АКНП канал 3 на БАЗ2
	{5	,1	,1	,&A1VN71LS3},	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
	{6	,8	,1	,&B8VC01RDU},	//( - , A3Bz1, A3Bz2) Координата АЗ2, мм
	{7	,3	,1	,&R0DE01LS3},	//(vchs:01 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 1 месте
	{8	,3	,1	,&R0DE02LS3},	//(vchs:02 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 2 месте
	{9	,3	,1	,&R0DE04LS3},	//(vds32:04 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 4 месте
	{10	,3	,1	,&R0DE05LS3},	//(fds16:05 - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 5 месте
	{11	,1	,1	,&R0DE31LS3},	//(sbk:20 - S01SBK, DiagnAKNP3) диагностика шкафа АКНП3 сеть 1
	{12	,1	,1	,&R0DE32LS3},	//(sbk:20 - S02SBK, DiagnAKNP3) диагностика шкафа АКНП3 сеть 2
	{13	,1	,1	,&R0DE33LS3},	//(sbk:20 - S03SBK, DiagnAKNP3) диагностика шкафа АКНП3 двери
	{14	,1	,1	,&R0DE34LS3},	//(sbk:20 - S04SBK, DiagnAKNP3) диагностика шкафа АКНП3 температура меньше 43
	{15	,1	,1	,&R0DE35LS3},	//(sbk:20 - S05SBK, DiagnAKNP3) диагностика шкафа АКНП3 температура больше 53
	{16	,1	,1	,&R0DE36LS3},	//(sbk:20 - S06SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3.1 место 1
	{17	,1	,1	,&R0DE37LS3},	//(sbk:20 - S07SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3.1 место 2
	{18	,1	,1	,&R0DE38LS3},	//(sbk:20 - S08SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП15-3 место 3
	{19	,1	,1	,&R0DE39LS3},	//(sbk:20 - S09SBK, DiagnAKNP3) диагностика шкафа АКНП3 МП24-2 место 4
	{20	,1	,1	,&R0DE3CLS3},	//( - , DiagnAKNP3) диагностика шкафа АКНП3 БП5/24Д место 7
	{21	,1	,1	,&R0DE3DLS3},	//( - , DiagnAKNP3) диагностика шкафа АКНП3 БП5/24Д место 8
	{22	,1	,1	,&R0DEB1LS3},	//(sbk:20 - S10SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП5 место 7
	{23	,1	,1	,&R0DEB2LS3},	//(sbk:20 - S11SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП24Д место 7
	{24	,1	,1	,&R0DEB3LS3},	//(sbk:20 - S12SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП5 место 8
	{25	,1	,1	,&R0DEB4LS3},	//(sbk:20 - S13SBK, DiagnAKNP3) диагностика шкафа АКНП3 БП24Д место 8
	{26	,1	,1	,&R0EE03LZ1},	//( - , AKNP3) Питание  АКНП3  отключить
	{27	,1	,1	,&R0EE03LZ2},	//( - , AKNP3) Питание  АКНП3  отключить
	{28	,1	,1	,&R0IE01LS3},	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 3
	{29	,1	,1	,&R0IE02LS3},	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 3
	{30	,1	,1	,&R0IE11LS3},	//( - , - ) Исправность ВИП 1,6 (№14) СНМ11 3 канала
	{31	,1	,1	,&R0IE12LS3},	//( - , - ) Исправность ВИП 0,5 (№15) КНК15-1 3 канала
	{32	,1	,1	,&R0IE13LS3},	//( - , - ) Исправность ВИП 0,5 (№16) КНК53М 3 канала
	{33	,8	,1	,&R0IN01FI3},	//( - , MA3S) Выход СНМ-11 Гц от ПТИ
	{34	,8	,1	,&R0IN01FS3},	//( - , AKNP3) Выход СНМ-11 Гц
	{35	,8	,1	,&R0IN01FV3},	//(vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
	{36	,8	,1	,&R0IN02FI3},	//( - , MA3S) Выход КНК15-1 Гц от ПТИ
	{37	,8	,1	,&R0IN02FS3},	//( - , AKNP3) Выход КНК15-1 Гц
	{38	,8	,1	,&R0IN02FV3},	//(vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
	{39	,8	,1	,&R0IN03FI3},	//( - , MA3S) Выход КНК53М Гц от ПТИ
	{40	,8	,1	,&R0IN03FS3},	//( - , - ) Выход КНК53М Гц
	{41	,8	,1	,&R0IN03FV3},	//(vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
	{42	,1	,1	,&R0IS01FI0},	//( - , MA3S) Признак работы с имитатором
	{43	,8	,1	,&R0VN01RS3},	//( - , A3Bz1, A3Bz2) Период разгона канал 3
	{44	,8	,1	,&R0VN02RS3},	//( - , A3Bz1, A3Bz2) Уровень мощности канал 3
	{45	,8	,1	,&R0VN03RS3},	//( - , AKNP3) Измеренный нейтронный поток канал 3
	{46	,8	,1	,&R0VN04RS3},	//( - , AKNP3) Реактивность канал 3
	{47	,8	,1	,&R0VN13RS3},	//( - , AKNP3) Нейтронный поток по камере СНМ11 канал 3
	{48	,3	,1	,&R0VN15RS3},	//( - , AKNP3) Номер ведущей камеры канал 3
	{49	,8	,1	,&R0VN23RS3},	//( - , AKNP3) Нейтронный поток по камере КНК15-1 канал 3
	{50	,8	,1	,&R0VN33RS3},	//( - , AKNP3) Нейтронный поток по камере КНК53М канал 3
	{51	,1	,1	,&R0VN61LS3},	//( - , A3Bz1, A3Bz2) ПС по мощности канал 3
	{52	,1	,1	,&R0VN65LS3},	//( - , A3Bz1, A3Bz2) ПС по периоду разгона канал 3
	{53	,1	,1	,&R0VN73LZ1},	//(fds16:05 - K09FDSR, - ) АС по мощности канал 3 на БАЗ1
	{54	,1	,1	,&R0VN73LZ2},	//(fds16:05 - K13FDSR, - ) АС по мощности канал 3 на БАЗ2
	{55	,1	,1	,&R0VN77LZ1},	//(fds16:05 - K10FDSR, - ) АС по периоду разгона канал 3 на БАЗ1
	{56	,1	,1	,&R0VN77LZ2},	//(fds16:05 - K14FDSR, - ) АС по периоду разгона канал 3 на БАЗ2
	{57	,3	,1	,&TTLaknp3},	//( - , AKNP3) ttl
	{58	,1	,1	,&TestDiagnAKNP3},	//( - , AKNP3) Неисправность от диагностики
	{59	,1	,1	,&bFirstEnterFlag},	//(bFirstEnterFlag) 
	{60	,8	,1	,&fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{61	,8	,1	,&fEM_A0UX07RSS},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{62	,8	,1	,&fEM_A0UX08RSS},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{63	,8	,1	,&fEM_A0UX09RSS},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{64	,8	,1	,&fEM_B0UX07RSS},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{65	,8	,1	,&fEM_B0UX08RSS},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{66	,8	,1	,&fEM_B0UX09RSS},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{67	,8	,1	,&fEM_R0IN11FN3},	//(R0IN11FN3) Коэффициент A (А3 к 1)
	{68	,8	,1	,&fEM_R0IN12FN3},	//(R0IN12FN3) Коэффициент B (А3 к 1)
	{69	,8	,1	,&fEM_R0IN21FN3},	//(R0IN21FN3) Коэффициент A (А3 к 2)
	{70	,8	,1	,&fEM_R0IN22FN3},	//(R0IN22FN3) Коэффициент B (А3 к 2)
	{71	,8	,1	,&fEM_R0IN31FN3},	//(R0IN31FN3) Коэффициент A (А3 к 3)
	{72	,8	,1	,&fEM_R0IN32FN3},	//(R0IN32FN3) Коэффициент B (А3 к 3)
	{73	,8	,1	,&fEM_R0UH01RSS},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
	{74	,8	,1	,&fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{75	,8	,1	,&fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{76	,8	,1	,&fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{77	,8	,1	,&fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{78	,8	,1	,&fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{79	,8	,1	,&fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{80	,8	,1	,&fEM_R0UL01RSS},	//(R0UL01RSS) Шаг (мс) измерения периода
	{81	,8	,1	,&fEM_R0UL02RSS},	//(R0UL02RSS) Tф-постоянная времени, с
	{82	,8	,1	,&fEM_R0UL41RSS},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{83	,8	,1	,&fEM_R0UL42RSS},	//(R0UL42RSS) Уровень ПС по мощности
	{84	,8	,1	,&fEM_R0UL51RSS},	//(R0UL51RSS) Уровень АС по периоду разгона
	{85	,8	,1	,&fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{86	,8	,1	,&fEM_R0UN03RSS},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{87	,8	,1	,&fEM_R0UR01RSS},	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
	{88	,8	,1	,&fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	{89	,8	,1	,&fEM_R7UX07RSS},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{90	,8	,1	,&fEM_R7UX08RSS},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{91	,8	,1	,&fEM_R7UX09RSS},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{92	,8	,1	,&fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{93	,8	,1	,&fEM_R7UY07RSS},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{94	,8	,1	,&fEM_R7UY08RSS},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{95	,8	,1	,&fEM_R7UY09RSS},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{96	,3	,1	,&internal1_m19_Nk},	//(internal1_m19_Nk) Nk - ведущая камера
	{97	,1	,1	,&internal1_m55_MyFirstEnterFlag},	//(internal1_m55_MyFirstEnterFlag)  FirstEnterFlag
	{98	,8	,1	,&internal1_m55_W1},	//(internal1_m55_W1)  мощность на старте измерения
	{99	,8	,1	,&internal1_m55_W2},	//(internal1_m55_W2)  мощность в конце измерения
	{100	,8	,1	,&internal1_m55_Wlast},	//(internal1_m55_Wlast)  последнее растущее измерение
	{101	,8	,1	,&internal1_m55_Wmax},	//(internal1_m55_Wmax)  максимальное измерение в серии
	{102	,8	,1	,&internal1_m55_Wmin},	//(internal1_m55_Wmin)  минимальное измерение в серии
	{103	,3	,1	,&internal1_m55_chizm},	//(internal1_m55_chizm)  счетчик уменьшения мощности
	{104	,3	,1	,&internal1_m55_chsr},	//(internal1_m55_chsr)  счетчик усреднения
	{105	,3	,1	,&internal1_m55_flst},	//(internal1_m55_flst)  флаг старта измерения
	{106	,8	,1	,&internal1_m55_sumtim},	//(internal1_m55_sumtim)  время измерения мощности
	{107	,8	,1	,&internal1_m55_y0},	//(internal1_m55_y0) y0 - внутренний параметр
	{108	,8	,1	,&internal1_m56_y0},	//(internal1_m56_y0) y0 - внутренний параметр
	{109	,8	,1	,&var5},	//Внутренняя переменная var5
	{110	,1	,1	,&var8},	//Внутренняя переменная var8
	{111	,1	,1	,&var10},	//Внутренняя переменная var10
	{112	,1	,1	,&var27},	//Внутренняя переменная var27
	{113	,8	,1	,&var6},	//Внутренняя переменная var6
	{114	,5	,1	,&var14},	//Внутренняя переменная var14
	{115	,1	,1	,&var22},	//Внутренняя переменная var22
	{116	,1	,1	,&var31},	//Внутренняя переменная var31
	{117	,8	,1	,&vainSFloat},	//Внутренняя переменная vainSFloat
	{118	,8	,1	,&var19},	//Внутренняя переменная var19
	{119	,8	,1	,&var20},	//Внутренняя переменная var20
	{120	,1	,1	,&var24},	//Внутренняя переменная var24
	{121	,8	,1	,&var4},	//Внутренняя переменная var4
	{122	,1	,1	,&var13},	//Внутренняя переменная var13
	{123	,8	,1	,&var15},	//Внутренняя переменная var15
	{124	,8	,1	,&var32},	//Внутренняя переменная var32
	{125	,11	,1	,&vainSLong},	//Внутренняя переменная vainSLong
	{126	,5	,1	,&vainSInt},	//Внутренняя переменная vainSInt
	{127	,8	,1	,&var7},	//Внутренняя переменная var7
	{128	,1	,1	,&var9},	//Внутренняя переменная var9
	{129	,1	,1	,&var11},	//Внутренняя переменная var11
	{130	,1	,1	,&var26},	//Внутренняя переменная var26
	{131	,1	,1	,&var30},	//Внутренняя переменная var30
	{132	,8	,1	,&var3},	//Внутренняя переменная var3
	{133	,1	,1	,&var12},	//Внутренняя переменная var12
	{134	,8	,1	,&var23},	//Внутренняя переменная var23
	{135	,1	,1	,&var25},	//Внутренняя переменная var25
	{136	,1	,1	,&var28},	//Внутренняя переменная var28
	{137	,1	,1	,&var33},	//Внутренняя переменная var33
	{138	,8	,1	,&var1},	//Внутренняя переменная var1
	{139	,8	,1	,&var2},	//Внутренняя переменная var2
	{140	,8	,1	,&var16},	//Внутренняя переменная var16
	{141	,1	,1	,&var17},	//Внутренняя переменная var17
	{142	,8	,1	,&var18},	//Внутренняя переменная var18
	{143	,5	,1	,&var21},	//Внутренняя переменная var21
	{144	,1	,1	,&var29},	//Внутренняя переменная var29
	{145	,1	,1	,&vainSBool},	//Внутренняя переменная vainSBool
	{-1,0,NULL},
};
static char NameSaveFile[]="aknp3.bin\0"; //Имя файла сохранения переменных
#pragma pop
static VarSaveCtrl saveVariables[]={	//Id переменных для сохранения
	{84,"fEM_R0UL51RSS\0"},	//(R0UL51RSS) Уровень АС по периоду разгона
	{93,"fEM_R7UY07RSS\0"},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{61,"fEM_A0UX07RSS\0"},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{64,"fEM_B0UX07RSS\0"},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{71,"fEM_R0IN31FN3\0"},	//(R0IN31FN3) Коэффициент A (А3 к 3)
	{92,"fEM_R7UY00RSS\0"},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{65,"fEM_B0UX08RSS\0"},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{87,"fEM_R0UR01RSS\0"},	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
	{83,"fEM_R0UL42RSS\0"},	//(R0UL42RSS) Уровень ПС по мощности
	{94,"fEM_R7UY08RSS\0"},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{63,"fEM_A0UX09RSS\0"},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{75,"fEM_R0UH03RSS\0"},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{67,"fEM_R0IN11FN3\0"},	//(R0IN11FN3) Коэффициент A (А3 к 1)
	{70,"fEM_R0IN22FN3\0"},	//(R0IN22FN3) Коэффициент B (А3 к 2)
	{88,"fEM_R7UX00RSS\0"},	//(R7UX00RSS) X-координата АЗ1 (см)
	{91,"fEM_R7UX09RSS\0"},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{95,"fEM_R7UY09RSS\0"},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{81,"fEM_R0UL02RSS\0"},	//(R0UL02RSS) Tф-постоянная времени, с
	{69,"fEM_R0IN21FN3\0"},	//(R0IN21FN3) Коэффициент A (А3 к 2)
	{78,"fEM_R0UH22RSS\0"},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{72,"fEM_R0IN32FN3\0"},	//(R0IN32FN3) Коэффициент B (А3 к 3)
	{73,"fEM_R0UH01RSS\0"},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
	{77,"fEM_R0UH21RSS\0"},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{85,"fEM_R0UL52RSS\0"},	//(R0UL52RSS) Уровень АС по мощности
	{82,"fEM_R0UL41RSS\0"},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{89,"fEM_R7UX07RSS\0"},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{60,"fEM_A0UX00RSS\0"},	//(A0UX00RSS) Эффективный радиус АЗ
	{76,"fEM_R0UH05RSS\0"},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{86,"fEM_R0UN03RSS\0"},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{80,"fEM_R0UL01RSS\0"},	//(R0UL01RSS) Шаг (мс) измерения периода
	{68,"fEM_R0IN12FN3\0"},	//(R0IN12FN3) Коэффициент B (А3 к 1)
	{74,"fEM_R0UH02RSS\0"},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{90,"fEM_R7UX08RSS\0"},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{62,"fEM_A0UX08RSS\0"},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{66,"fEM_B0UX09RSS\0"},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{79,"fEM_R0UH23RSS\0"},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_AKNP3[]={
	{&R0EE03LZ1,1,0},	//( - , AKNP3) Питание  АКНП3  отключить
	{&R0EE03LZ2,1,1},	//( - , AKNP3) Питание  АКНП3  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_AKNP3[]={
	{&A0EE02LS3,1,0},	//( - , AKNP3) Исправность АКНП3 (от сшивки каналов) канал 3
	{&TestDiagnAKNP3,1,1},	//( - , AKNP3) Неисправность от диагностики
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_AKNP3[]={
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
static ModbusRegister hr_AKNP3[]={
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
static ModbusRegister coil_A3Bz1[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_A3Bz1[]={
	{&R0VN61LS3,1,0},	//( - , A3Bz1, A3Bz2) ПС по мощности канал 3
	{&R0VN65LS3,1,1},	//( - , A3Bz1, A3Bz2) ПС по периоду разгона канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_A3Bz1[]={
	{&R0VN02RS3,8,0},	//( - , A3Bz1, A3Bz2) Уровень мощности канал 3
	{&R0VN01RS3,8,2},	//( - , A3Bz1, A3Bz2) Период разгона канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_A3Bz1[]={
	{&B8VC01RDU,8,0},	//( - , A3Bz1, A3Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_A3Bz2[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_A3Bz2[]={
	{&R0VN61LS3,1,0},	//( - , A3Bz1, A3Bz2) ПС по мощности канал 3
	{&R0VN65LS3,1,1},	//( - , A3Bz1, A3Bz2) ПС по периоду разгона канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_A3Bz2[]={
	{&R0VN02RS3,8,0},	//( - , A3Bz1, A3Bz2) Уровень мощности канал 3
	{&R0VN01RS3,8,2},	//( - , A3Bz1, A3Bz2) Период разгона канал 3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_A3Bz2[]={
	{&B8VC01RDU,8,0},	//( - , A3Bz1, A3Bz2) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_DiagnAKNP3[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnAKNP3[]={
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
static ModbusRegister ir_DiagnAKNP3[]={
	{&R0DE05LS3,3,0},	//( - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 5 месте
	{&R0DE04LS3,3,1},	//( - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 4 месте
	{&R0DE02LS3,3,2},	//( - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 2 месте
	{&R0DE01LS3,3,3},	//( - Diagn, DiagnAKNP3) диагностика модуля АКНП3 на 1 месте
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DiagnAKNP3[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MA3S[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MA3S[]={
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MA3S[]={
	{&R0IN01FI3,8,0},	//( - , SA3) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI3,8,2},	//( - , SA3) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI3,8,4},	//( - , SA3) Выход КНК53М Гц от ПТИ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MA3S[]={
	{NULL,0,0},
};
#pragma pop
static char MA3S_ip1[]={"192.168.10.60\0"};
static char MA3S_ip2[]={"192.168.10.160\0"};
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_AKNP3[0],&di_AKNP3[0],&ir_AKNP3[0],&hr_AKNP3[0],NULL,NULL,NULL,0},	//общий slave AKNP3
	{0,5017,&coil_A3Bz1[0],&di_A3Bz1[0],&ir_A3Bz1[0],&hr_A3Bz1[0],NULL,NULL,NULL,0},	//slave AKNP3 - Baz1
	{0,5021,&coil_A3Bz2[0],&di_A3Bz2[0],&ir_A3Bz2[0],&hr_A3Bz2[0],NULL,NULL,NULL,0},	//slave AKNP3 - Baz2
	{0,5003,&coil_DiagnAKNP3[0],&di_DiagnAKNP3[0],&ir_DiagnAKNP3[0],&hr_DiagnAKNP3[0],NULL,NULL,NULL,0},	//Диагностика АКНП3
	{1,5008,&coil_MA3S[0],&di_MA3S[0],&ir_MA3S[0],&hr_MA3S[0],NULL,MA3S_ip1,MA3S_ip2,100},	//Мастер AKNP3 в SCM
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
	{&R0DE02LS3,3,10},
	{&R0IN03FV3,8,0},
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
	{&R0DE04LS3,3,64},
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
static char buf_SBKFP[90];	//SBKFP
static sbk_inipar ini_SBKFP={0xcc,0xff,8,8,0,0,0,};
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
#include <fp8/drivers/vchs2.h>
static char buf_VCHS01[122];	//VCHS01
static vchs_inipar ini_VCHS01={0xc4,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
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
#pragma pack(push,1)
static Driver drivers[]={
	{0xc4,0x01,27,122,def_buf_VCHS01,&table_VCHS01},	//VCHS01
	{0xc4,0x02,27,122,def_buf_VCHS02,&table_VCHS02},	//VCHS02
	{0xc2,0x04,19,194,def_buf_VDS32,&table_VDS32},	//VDS32
	{0x96,0x05,23,104,def_buf_FDS16,&table_FDS16},	//FDS16
	{0xcc,0x20,7,90,def_buf_SBKFP,&table_SBKFP},	//SBKFP
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){	//Инициализация переменных для хранения
	setAsFloat(88,1570.0);
	setAsFloat(91,1269.0);
	setAsFloat(95,588.0);
	setAsFloat(81,2.0);
	setAsFloat(69,1);
	setAsFloat(78,100000);
	setAsFloat(72,0);
	setAsFloat(86,0.005);
	setAsFloat(73,20);
	setAsFloat(77,4000);
	setAsFloat(85,5100);
	setAsFloat(82,20);
	setAsFloat(89,1585.0);
	setAsFloat(60,11.0);
	setAsFloat(76,32000.0);
	setAsFloat(80,0.5);
	setAsFloat(68,0);
	setAsFloat(74,37037.04 );
	setAsFloat(90,1796.0);
	setAsFloat(62,1.0);
	setAsFloat(66,0.0);
	setAsFloat(79,1000000);
	setAsFloat(84,13.0);
	setAsFloat(93,594.0);
	setAsFloat(61,1.0);
	setAsFloat(64,0.0);
	setAsFloat(71,1);
	setAsFloat(92,506.5);
	setAsFloat(65,0);
	setAsFloat(87,5000);
	setAsFloat(83,5000);
	setAsFloat(94,559.0);
	setAsFloat(63,1.0);
	setAsFloat(75,975000.0);
	setAsFloat(67,1);
	setAsFloat(70,0);
	setAsBool(30,1);
	setAsBool(31,1);
	setAsBool(32,1);
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
sschar bRM_1_ = {1,0}; /* type - тип камеры СНМ-11 1- для АЗ1, 2- для аз2, >2 РПУ */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива значений */ 
ssint iRM_6_ = {6,0}; /* n - N-размерность массива x */ 
ssbool lRM_1_ = {1,0}; /*  */ 
ssfloat fRM_1_ = {1,0}; /* k - Kф-коэффициент усиления */ 
ssfloat fRM_3_ = {3,0}; /* tau - Tф-постоянная времени, с */ 


/* Определение переменных */
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
_S_diagndev  S_diagndev_88_1 = {array_m88_x_1,&iRM_4_,&var13,&var14,&vainSFloat};
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
void MainCycle(void){
	Scheme();
}
#endif