#ifndef AKNP4_H
#defile AKNP4_H
// Подсистема  AKNP4:AKNP4
static char SimulOn=0;
static short CodeSub=7;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 //Время цикла мс
float takt,taktScheme=0,taktSS=0;
#define SIZE_BUFFER 541
static char BUFFER[SIZE_BUFFER];
#include <fp8/UDPTransport.h>
SetupUDP setUDP ={"192.168.10.55\0",5432,"192.168.10.155\0",5432,BUFFER,sizeof(BUFFER),};
int master=1,nomer=1;
#define A0EE01LS4	BUFFER[0]	// (fds16:05 - K11FDSR, - ) Исправность АКНП канал 4 на БАЗ1
#define idA0EE01LS4	1	// (fds16:05 - K11FDSR, - ) Исправность АКНП канал 4 на БАЗ1
#define A0EE02LS4	BUFFER[2]	// ( - , AKNP4) Исправность АКНП4 (от сшивки каналов) канал 4
#define idA0EE02LS4	2	// ( - , AKNP4) Исправность АКНП4 (от сшивки каналов) канал 4
#define A0VN71LS4	BUFFER[4]	// (fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
#define idA0VN71LS4	3	// (fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
#define A1EE01L	BUFFER[6]	// (fds16:05 - K15FDSR, - ) Исправность АКНП канал 4 на БАЗ2
#define idA1EE01L	4	// (fds16:05 - K15FDSR, - ) Исправность АКНП канал 4 на БАЗ2
#define A1VN71LS4	BUFFER[8]	// (fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
#define idA1VN71LS4	5	// (fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
#define B8VC01RDU	BUFFER[10]	// ( - , A4Bz1, A4Bz2) Координата АЗ2, мм
#define idB8VC01RDU	6	// ( - , A4Bz1, A4Bz2) Координата АЗ2, мм
#define R0DE01LS4	BUFFER[15]	// (vchs:01 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 1 месте
#define idR0DE01LS4	7	// (vchs:01 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 1 месте
#define R0DE02LS4	BUFFER[18]	// (vchs:02 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 2 месте
#define idR0DE02LS4	8	// (vchs:02 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 2 месте
#define R0DE04LS4	BUFFER[21]	// (vds32:04 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 4 месте
#define idR0DE04LS4	9	// (vds32:04 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 4 месте
#define R0DE05LS4	BUFFER[24]	// (fds16:05 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 5 месте
#define idR0DE05LS4	10	// (fds16:05 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 5 месте
#define R0DE31LS4	BUFFER[27]	// (sbk:20 - S01SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 1
#define idR0DE31LS4	11	// (sbk:20 - S01SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 1
#define R0DE32LS4	BUFFER[29]	// (sbk:20 - S02SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 2
#define idR0DE32LS4	12	// (sbk:20 - S02SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 2
#define R0DE33LS4	BUFFER[31]	// (sbk:20 - S03SBK, DiagnAKNP4) диагностика шкафа АКНП4 двери
#define idR0DE33LS4	13	// (sbk:20 - S03SBK, DiagnAKNP4) диагностика шкафа АКНП4 двери
#define R0DE34LS4	BUFFER[33]	// (sbk:20 - S04SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура меньше 43
#define idR0DE34LS4	14	// (sbk:20 - S04SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура меньше 43
#define R0DE35LS4	BUFFER[35]	// (sbk:20 - S05SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура больше 53
#define idR0DE35LS4	15	// (sbk:20 - S05SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура больше 53
#define R0DE36LS4	BUFFER[37]	// (sbk:20 - S06SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 1
#define idR0DE36LS4	16	// (sbk:20 - S06SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 1
#define R0DE37LS4	BUFFER[39]	// (sbk:20 - S07SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 2
#define idR0DE37LS4	17	// (sbk:20 - S07SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 2
#define R0DE38LS4	BUFFER[41]	// (sbk:20 - S08SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3 место 3
#define idR0DE38LS4	18	// (sbk:20 - S08SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3 место 3
#define R0DE39LS4	BUFFER[43]	// (sbk:20 - S09SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП24-2 место 4
#define idR0DE39LS4	19	// (sbk:20 - S09SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП24-2 место 4
#define R0DE3CLS4	BUFFER[45]	// ( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 7
#define idR0DE3CLS4	20	// ( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 7
#define R0DE3DLS4	BUFFER[47]	// ( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 8
#define idR0DE3DLS4	21	// ( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 8
#define R0DEB1LS4	BUFFER[49]	// (sbk:20 - S10SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 7
#define idR0DEB1LS4	22	// (sbk:20 - S10SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 7
#define R0DEB2LS4	BUFFER[51]	// (sbk:20 - S11SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 7
#define idR0DEB2LS4	23	// (sbk:20 - S11SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 7
#define R0DEB3LS4	BUFFER[53]	// (sbk:20 - S12SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 8
#define idR0DEB3LS4	24	// (sbk:20 - S12SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 8
#define R0DEB4LS4	BUFFER[55]	// (sbk:20 - S13SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 8
#define idR0DEB4LS4	25	// (sbk:20 - S13SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 8
#define R0EE04LZ1	BUFFER[57]	// ( - , AKNP4) Питание  АКНП4  отключить
#define idR0EE04LZ1	26	// ( - , AKNP4) Питание  АКНП4  отключить
#define R0EE04LZ2	BUFFER[59]	// ( - , AKNP4) Питание  АКНП4  отключить
#define idR0EE04LZ2	27	// ( - , AKNP4) Питание  АКНП4  отключить
#define R0IE01LS4	BUFFER[61]	// (fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 4
#define idR0IE01LS4	28	// (fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 4
#define R0IE02LS4	BUFFER[63]	// (fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 4
#define idR0IE02LS4	29	// (fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 4
#define R0IE11LS4	BUFFER[65]	// ( - , - ) Исправность ВИП 1,6 (№17) СНМ11 4 канала
#define idR0IE11LS4	30	// ( - , - ) Исправность ВИП 1,6 (№17) СНМ11 4 канала
#define R0IE12LS4	BUFFER[67]	// ( - , - ) Исправность ВИП 0,5 (№18) КНК15-1 4 канала
#define idR0IE12LS4	31	// ( - , - ) Исправность ВИП 0,5 (№18) КНК15-1 4 канала
#define R0IE13LS4	BUFFER[69]	// ( - , - ) Исправность ВИП 0,5 (№19) КНК53М 4 канала
#define idR0IE13LS4	32	// ( - , - ) Исправность ВИП 0,5 (№19) КНК53М 4 канала
#define R0IN01FI4	BUFFER[71]	// ( - , MA4S) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI4	33	// ( - , MA4S) Выход СНМ-11 Гц от ПТИ
#define R0IN01FS4	BUFFER[76]	// ( - , AKNP4) Выход СНМ-11 Гц
#define idR0IN01FS4	34	// ( - , AKNP4) Выход СНМ-11 Гц
#define R0IN01FV4	BUFFER[81]	// (vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
#define idR0IN01FV4	35	// (vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
#define R0IN02FI4	BUFFER[86]	// ( - , MA4S) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI4	36	// ( - , MA4S) Выход КНК15-1 Гц от ПТИ
#define R0IN02FS4	BUFFER[91]	// ( - , AKNP4) Выход КНК15-1 Гц
#define idR0IN02FS4	37	// ( - , AKNP4) Выход КНК15-1 Гц
#define R0IN02FV4	BUFFER[96]	// (vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
#define idR0IN02FV4	38	// (vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
#define R0IN03FI4	BUFFER[101]	// ( - , MA4S) Выход КНК53М Гц от ПТИ
#define idR0IN03FI4	39	// ( - , MA4S) Выход КНК53М Гц от ПТИ
#define R0IN03FS4	BUFFER[106]	// ( - , AKNP4) Выход КНК53М Гц
#define idR0IN03FS4	40	// ( - , AKNP4) Выход КНК53М Гц
#define R0IN03FV4	BUFFER[111]	// (vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
#define idR0IN03FV4	41	// (vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
#define R0IS01FI0	BUFFER[116]	// ( - , MA4S) Признак работы с имитатором
#define idR0IS01FI0	42	// ( - , MA4S) Признак работы с имитатором
#define R0VN01RS4	BUFFER[118]	// ( - , A4Bz1, A4Bz2) Период разгона канал 4
#define idR0VN01RS4	43	// ( - , A4Bz1, A4Bz2) Период разгона канал 4
#define R0VN02RS4	BUFFER[123]	// ( - , A4Bz1, A4Bz2) Уровень мощности канал 4
#define idR0VN02RS4	44	// ( - , A4Bz1, A4Bz2) Уровень мощности канал 4
#define R0VN03RS4	BUFFER[128]	// ( - , AKNP4) Измеренный нейтронный поток канал 4
#define idR0VN03RS4	45	// ( - , AKNP4) Измеренный нейтронный поток канал 4
#define R0VN04RS4	BUFFER[133]	// ( - , AKNP4) Реактивность канал 4
#define idR0VN04RS4	46	// ( - , AKNP4) Реактивность канал 4
#define R0VN13RS4	BUFFER[138]	// ( - , AKNP4) Нейтронный поток по камере СНМ11 канал 4
#define idR0VN13RS4	47	// ( - , AKNP4) Нейтронный поток по камере СНМ11 канал 4
#define R0VN15RS4	BUFFER[143]	// ( - , AKNP4) Номер ведущей камеры канал 4
#define idR0VN15RS4	48	// ( - , AKNP4) Номер ведущей камеры канал 4
#define R0VN23RS4	BUFFER[146]	// ( - , AKNP4) Нейтронный поток по камере КНК15-1 канал 4
#define idR0VN23RS4	49	// ( - , AKNP4) Нейтронный поток по камере КНК15-1 канал 4
#define R0VN33RS4	BUFFER[151]	// ( - , AKNP4) Нейтронный поток по камере КНК53М канал 4
#define idR0VN33RS4	50	// ( - , AKNP4) Нейтронный поток по камере КНК53М канал 4
#define R0VN61LS4	BUFFER[156]	// ( - , A4Bz1, A4Bz2) ПС по мощности канал 4
#define idR0VN61LS4	51	// ( - , A4Bz1, A4Bz2) ПС по мощности канал 4
#define R0VN65LS4	BUFFER[158]	// ( - , A4Bz1, A4Bz2) ПС по периоду разгона канал 4
#define idR0VN65LS4	52	// ( - , A4Bz1, A4Bz2) ПС по периоду разгона канал 4
#define R0VN74LZ1	BUFFER[160]	// (fds16:05 - K09FDSR, - ) АС по мощности канал 4 на БАЗ1
#define idR0VN74LZ1	53	// (fds16:05 - K09FDSR, - ) АС по мощности канал 4 на БАЗ1
#define R0VN74LZ2	BUFFER[162]	// (fds16:05 - K13FDSR, - ) АС по мощности канал 4 на БАЗ2
#define idR0VN74LZ2	54	// (fds16:05 - K13FDSR, - ) АС по мощности канал 4 на БАЗ2
#define R0VN78LZ1	BUFFER[164]	// (fds16:05 - K10FDSR, - ) АС по периоду разгона канал 4 на БАЗ1
#define idR0VN78LZ1	55	// (fds16:05 - K10FDSR, - ) АС по периоду разгона канал 4 на БАЗ1
#define R0VN78LZ2	BUFFER[166]	// (fds16:05 - K14FDSR, - ) АС по периоду разгона канал 4 на БАЗ2
#define idR0VN78LZ2	56	// (fds16:05 - K14FDSR, - ) АС по периоду разгона канал 4 на БАЗ2
#define TTLaknp4	BUFFER[168]	// ( - , AKNP4) ttl
#define idTTLaknp4	57	// ( - , AKNP4) ttl
#define TestDiagnAKNP4	BUFFER[171]	// ( - , AKNP4) Неисправность от диагностики
#define idTestDiagnAKNP4	58	// ( - , AKNP4) Неисправность от диагностики
#define bFirstEnterFlag	BUFFER[173]	// (bFirstEnterFlag) 
#define idbFirstEnterFlag	59	// (bFirstEnterFlag) 
#define fEM_A0UX00RSS	BUFFER[175]	// (A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	60	// (A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX10RSS	BUFFER[180]	// (A0UX10RSS) Первый коэффициент калибровки камеры 10
#define idfEM_A0UX10RSS	61	// (A0UX10RSS) Первый коэффициент калибровки камеры 10
#define fEM_A0UX11RSS	BUFFER[185]	// (A0UX11RSS) Первый коэффициент калибровки камеры 11
#define idfEM_A0UX11RSS	62	// (A0UX11RSS) Первый коэффициент калибровки камеры 11
#define fEM_A0UX12RSS	BUFFER[190]	// (A0UX12RSS) Первый коэффициент калибровки камеры 12
#define idfEM_A0UX12RSS	63	// (A0UX12RSS) Первый коэффициент калибровки камеры 12
#define fEM_B0UX10RSS	BUFFER[195]	// (B0UX10RSS) Второй коэффициент калибровки камеры 10
#define idfEM_B0UX10RSS	64	// (B0UX10RSS) Второй коэффициент калибровки камеры 10
#define fEM_B0UX11RSS	BUFFER[200]	// (B0UX11RSS) Второй коэффициент калибровки камеры 11
#define idfEM_B0UX11RSS	65	// (B0UX11RSS) Второй коэффициент калибровки камеры 11
#define fEM_B0UX12RSS	BUFFER[205]	// (B0UX12RSS) Второй коэффициент калибровки камеры 12
#define idfEM_B0UX12RSS	66	// (B0UX12RSS) Второй коэффициент калибровки камеры 12
#define fEM_R0IN11FN4	BUFFER[210]	// (R0IN11FN4) Коэффициент A (А4 к 1)
#define idfEM_R0IN11FN4	67	// (R0IN11FN4) Коэффициент A (А4 к 1)
#define fEM_R0IN12FN4	BUFFER[215]	// (R0IN12FN4) Коэффициент B (А4 к 1)
#define idfEM_R0IN12FN4	68	// (R0IN12FN4) Коэффициент B (А4 к 1)
#define fEM_R0IN21FN4	BUFFER[220]	// (R0IN21FN4) Коэффициент A (А4 к 2)
#define idfEM_R0IN21FN4	69	// (R0IN21FN4) Коэффициент A (А4 к 2)
#define fEM_R0IN22FN4	BUFFER[225]	// (R0IN22FN4) Коэффициент B (А4 к 2)
#define idfEM_R0IN22FN4	70	// (R0IN22FN4) Коэффициент B (А4 к 2)
#define fEM_R0IN31FN4	BUFFER[230]	// (R0IN31FN4) Коэффициент A (А4 к 3)
#define idfEM_R0IN31FN4	71	// (R0IN31FN4) Коэффициент A (А4 к 3)
#define fEM_R0IN32FN4	BUFFER[235]	// (R0IN32FN4) Коэффициент B (А4 к 3)
#define idfEM_R0IN32FN4	72	// (R0IN32FN4) Коэффициент B (А4 к 3)
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
#define fEM_R0UL01RSS	BUFFER[275]	// (R0UL01RSS) Шаг (с) измерения периода
#define idfEM_R0UL01RSS	80	// (R0UL01RSS) Шаг (с) измерения периода
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
#define fEM_R7UX10RSS	BUFFER[320]	// (R7UX10RSS) X-координата камеры R7IN41
#define idfEM_R7UX10RSS	89	// (R7UX10RSS) X-координата камеры R7IN41
#define fEM_R7UX11RSS	BUFFER[325]	// (R7UX11RSS) X-координата камеры R7IN42
#define idfEM_R7UX11RSS	90	// (R7UX11RSS) X-координата камеры R7IN42
#define fEM_R7UX12RSS	BUFFER[330]	// (R7UX12RSS) X-координата камеры R7IN43
#define idfEM_R7UX12RSS	91	// (R7UX12RSS) X-координата камеры R7IN43
#define fEM_R7UY00RSS	BUFFER[335]	// (R7UY00RSS) Y-координата АЗ1 (см)
#define idfEM_R7UY00RSS	92	// (R7UY00RSS) Y-координата АЗ1 (см)
#define fEM_R7UY10RSS	BUFFER[340]	// (R7UY10RSS) Y-координата камеры R7IN41
#define idfEM_R7UY10RSS	93	// (R7UY10RSS) Y-координата камеры R7IN41
#define fEM_R7UY11RSS	BUFFER[345]	// (R7UY11RSS) Y-координата камеры R7IN42
#define idfEM_R7UY11RSS	94	// (R7UY11RSS) Y-координата камеры R7IN42
#define fEM_R7UY12RSS	BUFFER[350]	// (R7UY12RSS) Y-координата камеры R7IN43
#define idfEM_R7UY12RSS	95	// (R7UY12RSS) Y-координата камеры R7IN43
#define internal1_m18_Nk	BUFFER[355]	// (internal1_m18_Nk) Nk - ведущая камера
#define idinternal1_m18_Nk	96	// (internal1_m18_Nk) Nk - ведущая камера
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
#define var2	BUFFER[409]	// Внутренняя переменная var2
#define idvar2	30000	// Внутренняя переменная var2
#define var9	BUFFER[414]	// Внутренняя переменная var9
#define idvar9	30001	// Внутренняя переменная var9
#define var10	BUFFER[416]	// Внутренняя переменная var10
#define idvar10	30002	// Внутренняя переменная var10
#define var16	BUFFER[418]	// Внутренняя переменная var16
#define idvar16	30003	// Внутренняя переменная var16
#define var32	BUFFER[423]	// Внутренняя переменная var32
#define idvar32	30004	// Внутренняя переменная var32
#define var3	BUFFER[428]	// Внутренняя переменная var3
#define idvar3	30005	// Внутренняя переменная var3
#define var5	BUFFER[433]	// Внутренняя переменная var5
#define idvar5	30006	// Внутренняя переменная var5
#define var11	BUFFER[438]	// Внутренняя переменная var11
#define idvar11	30007	// Внутренняя переменная var11
#define var26	BUFFER[440]	// Внутренняя переменная var26
#define idvar26	30008	// Внутренняя переменная var26
#define var29	BUFFER[442]	// Внутренняя переменная var29
#define idvar29	30009	// Внутренняя переменная var29
#define vainSChar	BUFFER[444]	// Внутренняя переменная vainSChar
#define idvainSChar	30010	// Внутренняя переменная vainSChar
#define var12	BUFFER[447]	// Внутренняя переменная var12
#define idvar12	30011	// Внутренняя переменная var12
#define var22	BUFFER[449]	// Внутренняя переменная var22
#define idvar22	30012	// Внутренняя переменная var22
#define var27	BUFFER[451]	// Внутренняя переменная var27
#define idvar27	30013	// Внутренняя переменная var27
#define var33	BUFFER[453]	// Внутренняя переменная var33
#define idvar33	30014	// Внутренняя переменная var33
#define vainSInt	BUFFER[455]	// Внутренняя переменная vainSInt
#define idvainSInt	30015	// Внутренняя переменная vainSInt
#define var25	BUFFER[458]	// Внутренняя переменная var25
#define idvar25	30016	// Внутренняя переменная var25
#define var30	BUFFER[460]	// Внутренняя переменная var30
#define idvar30	30017	// Внутренняя переменная var30
#define vainSFloat	BUFFER[462]	// Внутренняя переменная vainSFloat
#define idvainSFloat	30018	// Внутренняя переменная vainSFloat
#define var13	BUFFER[467]	// Внутренняя переменная var13
#define idvar13	30019	// Внутренняя переменная var13
#define var17	BUFFER[469]	// Внутренняя переменная var17
#define idvar17	30020	// Внутренняя переменная var17
#define var21	BUFFER[471]	// Внутренняя переменная var21
#define idvar21	30021	// Внутренняя переменная var21
#define var23	BUFFER[474]	// Внутренняя переменная var23
#define idvar23	30022	// Внутренняя переменная var23
#define var24	BUFFER[479]	// Внутренняя переменная var24
#define idvar24	30023	// Внутренняя переменная var24
#define var7	BUFFER[481]	// Внутренняя переменная var7
#define idvar7	30024	// Внутренняя переменная var7
#define var8	BUFFER[486]	// Внутренняя переменная var8
#define idvar8	30025	// Внутренняя переменная var8
#define var14	BUFFER[488]	// Внутренняя переменная var14
#define idvar14	30026	// Внутренняя переменная var14
#define var18	BUFFER[491]	// Внутренняя переменная var18
#define idvar18	30027	// Внутренняя переменная var18
#define var31	BUFFER[496]	// Внутренняя переменная var31
#define idvar31	30028	// Внутренняя переменная var31
#define var4	BUFFER[498]	// Внутренняя переменная var4
#define idvar4	30029	// Внутренняя переменная var4
#define var20	BUFFER[503]	// Внутренняя переменная var20
#define idvar20	30030	// Внутренняя переменная var20
#define var28	BUFFER[508]	// Внутренняя переменная var28
#define idvar28	30031	// Внутренняя переменная var28
#define vainSLong	BUFFER[510]	// Внутренняя переменная vainSLong
#define idvainSLong	30032	// Внутренняя переменная vainSLong
#define vainSBool	BUFFER[519]	// Внутренняя переменная vainSBool
#define idvainSBool	30033	// Внутренняя переменная vainSBool
#define var1	BUFFER[521]	// Внутренняя переменная var1
#define idvar1	30034	// Внутренняя переменная var1
#define var6	BUFFER[526]	// Внутренняя переменная var6
#define idvar6	30035	// Внутренняя переменная var6
#define var15	BUFFER[531]	// Внутренняя переменная var15
#define idvar15	30036	// Внутренняя переменная var15
#define var19	BUFFER[536]	// Внутренняя переменная var19
#define idvar19	30037	// Внутренняя переменная var19
#pragma pack(push,1)
static VarCtrl allVariables[]={ 			 //Описание всех переменных
	 1	,1	,1	,&A0EE01LS4},	//(fds16:05 - K11FDSR, - ) Исправность АКНП канал 4 на БАЗ1
	 2	,1	,1	,&A0EE02LS4},	//( - , AKNP4) Исправность АКНП4 (от сшивки каналов) канал 4
	 3	,1	,1	,&A0VN71LS4},	//(fds16:05 - K12FDSR, - ) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
	 4	,1	,1	,&A1EE01L},	//(fds16:05 - K15FDSR, - ) Исправность АКНП канал 4 на БАЗ2
	 5	,1	,1	,&A1VN71LS4},	//(fds16:05 - K16FDSR, - ) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
	 6	,8	,1	,&B8VC01RDU},	//( - , A4Bz1, A4Bz2) Координата АЗ2, мм
	 7	,3	,1	,&R0DE01LS4},	//(vchs:01 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 1 месте
	 8	,3	,1	,&R0DE02LS4},	//(vchs:02 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 2 месте
	 9	,3	,1	,&R0DE04LS4},	//(vds32:04 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 4 месте
	 10	,3	,1	,&R0DE05LS4},	//(fds16:05 - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 5 месте
	 11	,1	,1	,&R0DE31LS4},	//(sbk:20 - S01SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 1
	 12	,1	,1	,&R0DE32LS4},	//(sbk:20 - S02SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 2
	 13	,1	,1	,&R0DE33LS4},	//(sbk:20 - S03SBK, DiagnAKNP4) диагностика шкафа АКНП4 двери
	 14	,1	,1	,&R0DE34LS4},	//(sbk:20 - S04SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура меньше 43
	 15	,1	,1	,&R0DE35LS4},	//(sbk:20 - S05SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура больше 53
	 16	,1	,1	,&R0DE36LS4},	//(sbk:20 - S06SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 1
	 17	,1	,1	,&R0DE37LS4},	//(sbk:20 - S07SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 2
	 18	,1	,1	,&R0DE38LS4},	//(sbk:20 - S08SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3 место 3
	 19	,1	,1	,&R0DE39LS4},	//(sbk:20 - S09SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП24-2 место 4
	 20	,1	,1	,&R0DE3CLS4},	//( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 7
	 21	,1	,1	,&R0DE3DLS4},	//( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 8
	 22	,1	,1	,&R0DEB1LS4},	//(sbk:20 - S10SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 7
	 23	,1	,1	,&R0DEB2LS4},	//(sbk:20 - S11SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 7
	 24	,1	,1	,&R0DEB3LS4},	//(sbk:20 - S12SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 8
	 25	,1	,1	,&R0DEB4LS4},	//(sbk:20 - S13SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 8
	 26	,1	,1	,&R0EE04LZ1},	//( - , AKNP4) Питание  АКНП4  отключить
	 27	,1	,1	,&R0EE04LZ2},	//( - , AKNP4) Питание  АКНП4  отключить
	 28	,1	,1	,&R0IE01LS4},	//(fds16:05 - K02FDSR, - ) Отключение питание детекторов канал 4
	 29	,1	,1	,&R0IE02LS4},	//(fds16:05 - K01FDSR, - ) Отключить питание ПР, ПУ канал 4
	 30	,1	,1	,&R0IE11LS4},	//( - , - ) Исправность ВИП 1,6 (№17) СНМ11 4 канала
	 31	,1	,1	,&R0IE12LS4},	//( - , - ) Исправность ВИП 0,5 (№18) КНК15-1 4 канала
	 32	,1	,1	,&R0IE13LS4},	//( - , - ) Исправность ВИП 0,5 (№19) КНК53М 4 канала
	 33	,8	,1	,&R0IN01FI4},	//( - , MA4S) Выход СНМ-11 Гц от ПТИ
	 34	,8	,1	,&R0IN01FS4},	//( - , AKNP4) Выход СНМ-11 Гц
	 35	,8	,1	,&R0IN01FV4},	//(vchs:01 - K01VCHS, - ) Частота с ВЧС к 1
	 36	,8	,1	,&R0IN02FI4},	//( - , MA4S) Выход КНК15-1 Гц от ПТИ
	 37	,8	,1	,&R0IN02FS4},	//( - , AKNP4) Выход КНК15-1 Гц
	 38	,8	,1	,&R0IN02FV4},	//(vchs:01 - K02VCHS, - ) Частота с ВЧС к 2
	 39	,8	,1	,&R0IN03FI4},	//( - , MA4S) Выход КНК53М Гц от ПТИ
	 40	,8	,1	,&R0IN03FS4},	//( - , AKNP4) Выход КНК53М Гц
	 41	,8	,1	,&R0IN03FV4},	//(vchs:02 - K01VCHS, - ) Частота с ВЧС к 3
	 42	,1	,1	,&R0IS01FI0},	//( - , MA4S) Признак работы с имитатором
	 43	,8	,1	,&R0VN01RS4},	//( - , A4Bz1, A4Bz2) Период разгона канал 4
	 44	,8	,1	,&R0VN02RS4},	//( - , A4Bz1, A4Bz2) Уровень мощности канал 4
	 45	,8	,1	,&R0VN03RS4},	//( - , AKNP4) Измеренный нейтронный поток канал 4
	 46	,8	,1	,&R0VN04RS4},	//( - , AKNP4) Реактивность канал 4
	 47	,8	,1	,&R0VN13RS4},	//( - , AKNP4) Нейтронный поток по камере СНМ11 канал 4
	 48	,3	,1	,&R0VN15RS4},	//( - , AKNP4) Номер ведущей камеры канал 4
	 49	,8	,1	,&R0VN23RS4},	//( - , AKNP4) Нейтронный поток по камере КНК15-1 канал 4
	 50	,8	,1	,&R0VN33RS4},	//( - , AKNP4) Нейтронный поток по камере КНК53М канал 4
	 51	,1	,1	,&R0VN61LS4},	//( - , A4Bz1, A4Bz2) ПС по мощности канал 4
	 52	,1	,1	,&R0VN65LS4},	//( - , A4Bz1, A4Bz2) ПС по периоду разгона канал 4
	 53	,1	,1	,&R0VN74LZ1},	//(fds16:05 - K09FDSR, - ) АС по мощности канал 4 на БАЗ1
	 54	,1	,1	,&R0VN74LZ2},	//(fds16:05 - K13FDSR, - ) АС по мощности канал 4 на БАЗ2
	 55	,1	,1	,&R0VN78LZ1},	//(fds16:05 - K10FDSR, - ) АС по периоду разгона канал 4 на БАЗ1
	 56	,1	,1	,&R0VN78LZ2},	//(fds16:05 - K14FDSR, - ) АС по периоду разгона канал 4 на БАЗ2
	 57	,3	,1	,&TTLaknp4},	//( - , AKNP4) ttl
	 58	,1	,1	,&TestDiagnAKNP4},	//( - , AKNP4) Неисправность от диагностики
	 59	,1	,1	,&bFirstEnterFlag},	//(bFirstEnterFlag) 
	 60	,8	,1	,&fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	 61	,8	,1	,&fEM_A0UX10RSS},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	 62	,8	,1	,&fEM_A0UX11RSS},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	 63	,8	,1	,&fEM_A0UX12RSS},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	 64	,8	,1	,&fEM_B0UX10RSS},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	 65	,8	,1	,&fEM_B0UX11RSS},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	 66	,8	,1	,&fEM_B0UX12RSS},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	 67	,8	,1	,&fEM_R0IN11FN4},	//(R0IN11FN4) Коэффициент A (А4 к 1)
	 68	,8	,1	,&fEM_R0IN12FN4},	//(R0IN12FN4) Коэффициент B (А4 к 1)
	 69	,8	,1	,&fEM_R0IN21FN4},	//(R0IN21FN4) Коэффициент A (А4 к 2)
	 70	,8	,1	,&fEM_R0IN22FN4},	//(R0IN22FN4) Коэффициент B (А4 к 2)
	 71	,8	,1	,&fEM_R0IN31FN4},	//(R0IN31FN4) Коэффициент A (А4 к 3)
	 72	,8	,1	,&fEM_R0IN32FN4},	//(R0IN32FN4) Коэффициент B (А4 к 3)
	 73	,8	,1	,&fEM_R0UH01RSS},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
	 74	,8	,1	,&fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	 75	,8	,1	,&fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	 76	,8	,1	,&fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	 77	,8	,1	,&fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	 78	,8	,1	,&fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	 79	,8	,1	,&fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	 80	,8	,1	,&fEM_R0UL01RSS},	//(R0UL01RSS) Шаг (с) измерения периода
	 81	,8	,1	,&fEM_R0UL02RSS},	//(R0UL02RSS) Tф-постоянная времени, с
	 82	,8	,1	,&fEM_R0UL41RSS},	//(R0UL41RSS) Уровень ПС по периоду разгона
	 83	,8	,1	,&fEM_R0UL42RSS},	//(R0UL42RSS) Уровень ПС по мощности
	 84	,8	,1	,&fEM_R0UL51RSS},	//(R0UL51RSS) Уровень АС по периоду разгона
	 85	,8	,1	,&fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	 86	,8	,1	,&fEM_R0UN03RSS},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	 87	,8	,1	,&fEM_R0UR01RSS},	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
	 88	,8	,1	,&fEM_R7UX00RSS},	//(R7UX00RSS) X-координата АЗ1 (см)
	 89	,8	,1	,&fEM_R7UX10RSS},	//(R7UX10RSS) X-координата камеры R7IN41
	 90	,8	,1	,&fEM_R7UX11RSS},	//(R7UX11RSS) X-координата камеры R7IN42
	 91	,8	,1	,&fEM_R7UX12RSS},	//(R7UX12RSS) X-координата камеры R7IN43
	 92	,8	,1	,&fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 (см)
	 93	,8	,1	,&fEM_R7UY10RSS},	//(R7UY10RSS) Y-координата камеры R7IN41
	 94	,8	,1	,&fEM_R7UY11RSS},	//(R7UY11RSS) Y-координата камеры R7IN42
	 95	,8	,1	,&fEM_R7UY12RSS},	//(R7UY12RSS) Y-координата камеры R7IN43
	 96	,3	,1	,&internal1_m18_Nk},	//(internal1_m18_Nk) Nk - ведущая камера
	 97	,1	,1	,&internal1_m55_MyFirstEnterFlag},	//(internal1_m55_MyFirstEnterFlag)  FirstEnterFlag
	 98	,8	,1	,&internal1_m55_W1},	//(internal1_m55_W1)  мощность на старте измерения
	 99	,8	,1	,&internal1_m55_W2},	//(internal1_m55_W2)  мощность в конце измерения
	 100	,8	,1	,&internal1_m55_Wlast},	//(internal1_m55_Wlast)  последнее растущее измерение
	 101	,8	,1	,&internal1_m55_Wmax},	//(internal1_m55_Wmax)  максимальное измерение в серии
	 102	,8	,1	,&internal1_m55_Wmin},	//(internal1_m55_Wmin)  минимальное измерение в серии
	 103	,3	,1	,&internal1_m55_chizm},	//(internal1_m55_chizm)  счетчик уменьшения мощности
	 104	,3	,1	,&internal1_m55_chsr},	//(internal1_m55_chsr)  счетчик усреднения
	 105	,3	,1	,&internal1_m55_flst},	//(internal1_m55_flst)  флаг старта измерения
	 106	,8	,1	,&internal1_m55_sumtim},	//(internal1_m55_sumtim)  время измерения мощности
	 107	,8	,1	,&internal1_m55_y0},	//(internal1_m55_y0) y0 - внутренний параметр
	 108	,8	,1	,&internal1_m56_y0},	//(internal1_m56_y0) y0 - внутренний параметр
	 30000	,8	,1	,&var2},	//Внутренняя переменная var2
	 30001	,1	,1	,&var9},	//Внутренняя переменная var9
	 30002	,1	,1	,&var10},	//Внутренняя переменная var10
	 30003	,8	,1	,&var16},	//Внутренняя переменная var16
	 30004	,8	,1	,&var32},	//Внутренняя переменная var32
	 30005	,8	,1	,&var3},	//Внутренняя переменная var3
	 30006	,8	,1	,&var5},	//Внутренняя переменная var5
	 30007	,1	,1	,&var11},	//Внутренняя переменная var11
	 30008	,1	,1	,&var26},	//Внутренняя переменная var26
	 30009	,1	,1	,&var29},	//Внутренняя переменная var29
	 30010	,	,1	,&vainSChar},	//Внутренняя переменная vainSChar
	 30011	,1	,1	,&var12},	//Внутренняя переменная var12
	 30012	,1	,1	,&var22},	//Внутренняя переменная var22
	 30013	,1	,1	,&var27},	//Внутренняя переменная var27
	 30014	,1	,1	,&var33},	//Внутренняя переменная var33
	 30015	,3	,1	,&vainSInt},	//Внутренняя переменная vainSInt
	 30016	,1	,1	,&var25},	//Внутренняя переменная var25
	 30017	,1	,1	,&var30},	//Внутренняя переменная var30
	 30018	,8	,1	,&vainSFloat},	//Внутренняя переменная vainSFloat
	 30019	,1	,1	,&var13},	//Внутренняя переменная var13
	 30020	,1	,1	,&var17},	//Внутренняя переменная var17
	 30021	,3	,1	,&var21},	//Внутренняя переменная var21
	 30022	,8	,1	,&var23},	//Внутренняя переменная var23
	 30023	,1	,1	,&var24},	//Внутренняя переменная var24
	 30024	,8	,1	,&var7},	//Внутренняя переменная var7
	 30025	,1	,1	,&var8},	//Внутренняя переменная var8
	 30026	,3	,1	,&var14},	//Внутренняя переменная var14
	 30027	,8	,1	,&var18},	//Внутренняя переменная var18
	 30028	,1	,1	,&var31},	//Внутренняя переменная var31
	 30029	,8	,1	,&var4},	//Внутренняя переменная var4
	 30030	,8	,1	,&var20},	//Внутренняя переменная var20
	 30031	,1	,1	,&var28},	//Внутренняя переменная var28
	 30032	,11	,1	,&vainSLong},	//Внутренняя переменная vainSLong
	 30033	,1	,1	,&vainSBool},	//Внутренняя переменная vainSBool
	 30034	,8	,1	,&var1},	//Внутренняя переменная var1
	 30035	,8	,1	,&var6},	//Внутренняя переменная var6
	 30036	,8	,1	,&var15},	//Внутренняя переменная var15
	 30037	,8	,1	,&var19},	//Внутренняя переменная var19
	{-1,0,NULL},
}
static char NameSaveFile[]="aknp4.bin\0"; //Имя файла сохранения переменных
#pragma pop
static VarSaveCtrl saveVariables[]={	//Id переменных для сохранения
	{94,"fEM_R7UY11RSS\0"},	//(R7UY11RSS) Y-координата камеры R7IN42
	{64,"fEM_B0UX10RSS\0"},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{80,"fEM_R0UL01RSS\0"},	//(R0UL01RSS) Шаг (с) измерения периода
	{77,"fEM_R0UH21RSS\0"},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{69,"fEM_R0IN21FN4\0"},	//(R0IN21FN4) Коэффициент A (А4 к 2)
	{87,"fEM_R0UR01RSS\0"},	//(R0UR01RSS) Уставка АКНП ПС  АЗ по периоду (сек)
	{83,"fEM_R0UL42RSS\0"},	//(R0UL42RSS) Уровень ПС по мощности
	{62,"fEM_A0UX11RSS\0"},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{86,"fEM_R0UN03RSS\0"},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{93,"fEM_R7UY10RSS\0"},	//(R7UY10RSS) Y-координата камеры R7IN41
	{95,"fEM_R7UY12RSS\0"},	//(R7UY12RSS) Y-координата камеры R7IN43
	{76,"fEM_R0UH05RSS\0"},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{68,"fEM_R0IN12FN4\0"},	//(R0IN12FN4) Коэффициент B (А4 к 1)
	{85,"fEM_R0UL52RSS\0"},	//(R0UL52RSS) Уровень АС по мощности
	{88,"fEM_R7UX00RSS\0"},	//(R7UX00RSS) X-координата АЗ1 (см)
	{89,"fEM_R7UX10RSS\0"},	//(R7UX10RSS) X-координата камеры R7IN41
	{91,"fEM_R7UX12RSS\0"},	//(R7UX12RSS) X-координата камеры R7IN43
	{92,"fEM_R7UY00RSS\0"},	//(R7UY00RSS) Y-координата АЗ1 (см)
	{60,"fEM_A0UX00RSS\0"},	//(A0UX00RSS) Эффективный радиус АЗ
	{73,"fEM_R0UH01RSS\0"},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с СНМ-11
	{79,"fEM_R0UH23RSS\0"},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{75,"fEM_R0UH03RSS\0"},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с КНК53М
	{66,"fEM_B0UX12RSS\0"},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{78,"fEM_R0UH22RSS\0"},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{72,"fEM_R0IN32FN4\0"},	//(R0IN32FN4) Коэффициент B (А4 к 3)
	{84,"fEM_R0UL51RSS\0"},	//(R0UL51RSS) Уровень АС по периоду разгона
	{90,"fEM_R7UX11RSS\0"},	//(R7UX11RSS) X-координата камеры R7IN42
	{63,"fEM_A0UX12RSS\0"},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{81,"fEM_R0UL02RSS\0"},	//(R0UL02RSS) Tф-постоянная времени, с
	{67,"fEM_R0IN11FN4\0"},	//(R0IN11FN4) Коэффициент A (А4 к 1)
	{70,"fEM_R0IN22FN4\0"},	//(R0IN22FN4) Коэффициент B (А4 к 2)
	{82,"fEM_R0UL41RSS\0"},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{74,"fEM_R0UH02RSS\0"},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с КНК15-1
	{61,"fEM_A0UX10RSS\0"},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{65,"fEM_B0UX11RSS\0"},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{71,"fEM_R0IN31FN4\0"},	//(R0IN31FN4) Коэффициент A (А4 к 3)
	{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_AKNP4[]={
	{&R0EE04LZ2,2,1},	//( - , AKNP4) Питание  АКНП4  отключить
	{&R0EE04LZ1,2,0},	//( - , AKNP4) Питание  АКНП4  отключить
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_AKNP4[]={
	{&A0EE02LS4,2,0},	//( - , AKNP4) Исправность АКНП4 (от сшивки каналов) канал 4
	{&TestDiagnAKNP4,2,1},	//( - , AKNP4) Неисправность от диагностики
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_AKNP4[]={
	{&R0VN03RS4,8,2},	//( - , AKNP4) Измеренный нейтронный поток канал 4
	{&R0VN13RS4,8,8},	//( - , AKNP4) Нейтронный поток по камере СНМ11 канал 4
	{&R0IN03FS4,8,6},	//( - , AKNP4) Выход КНК53М Гц
	{&R0IN01FS4,8,0},	//( - , AKNP4) Выход СНМ-11 Гц
	{&R0VN33RS4,8,12},	//( - , AKNP4) Нейтронный поток по камере КНК53М канал 4
	{&R0IN02FS4,8,16},	//( - , AKNP4) Выход КНК15-1 Гц
	{&TTLaknp4,3,15},	//( - , AKNP4) ttl
	{&R0VN23RS4,8,10},	//( - , AKNP4) Нейтронный поток по камере КНК15-1 канал 4
	{&R0VN04RS4,8,4},	//( - , AKNP4) Реактивность канал 4
	{&R0VN15RS4,3,14},	//( - , AKNP4) Номер ведущей камеры канал 4
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_AKNP4[]={
	{&fEM_R0UH03RSS,8,10},	//( - , AKNP4) Коэфф. преобразования частота->нейтр/с КНК53М
	{&fEM_R0UL42RSS,8,12},	//( - , AKNP4) Уровень ПС по мощности
	{&fEM_R0UR01RSS,8,0},	//( - , AKNP4) Уставка АКНП ПС  АЗ по периоду (сек)
	{&fEM_R0UL52RSS,8,2},	//( - , AKNP4) Уровень АС по мощности
	{&fEM_R0UL41RSS,8,4},	//( - , AKNP4) Уровень ПС по периоду разгона
	{&fEM_R0UL02RSS,8,56},	//( - , AKNP4) Tф-постоянная времени, с
	{&fEM_R0IN11FN4,8,60},	//( - , AKNP4) Коэффициент A (А4 к 1)
	{&fEM_R7UX00RSS,8,14},	//( - , AKNP4) X-координата АЗ1 (см)
	{&fEM_B0UX10RSS,8,38},	//( - , AKNP4) Второй коэффициент калибровки камеры 10
	{&fEM_R0UH21RSS,8,50},	//( - , AKNP4) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{&fEM_R0IN21FN4,8,62},	//( - , AKNP4) Коэффициент A (А4 к 2)
	{&fEM_R0UN03RSS,8,46},	//( - , AKNP4) Нижняя граница интервала мощности для измерения периода (ватт)
	{&fEM_R0UH01RSS,8,48},	//( - , AKNP4) Коэфф. преобразования частота->нейтр/с СНМ-11
	{&fEM_A0UX10RSS,8,32},	//( - , AKNP4) Первый коэффициент калибровки камеры 10
	{&fEM_B0UX12RSS,8,42},	//( - , AKNP4) Второй коэффициент калибровки камеры 12
	{&fEM_R0IN31FN4,8,68},	//( - , AKNP4) Коэффициент A (А4 к 3)
	{&fEM_A0UX12RSS,8,36},	//( - , AKNP4) Первый коэффициент калибровки камеры 12
	{&fEM_R0UH22RSS,8,52},	//( - , AKNP4) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{&fEM_R0IN32FN4,8,70},	//( - , AKNP4) Коэффициент B (А4 к 3)
	{&fEM_R7UY10RSS,8,24},	//( - , AKNP4) Y-координата камеры R7IN41
	{&fEM_R7UY11RSS,8,26},	//( - , AKNP4) Y-координата камеры R7IN42
	{&fEM_R0UH23RSS,8,54},	//( - , AKNP4) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{&fEM_R0UL01RSS,8,58},	//( - , AKNP4) Шаг (с) измерения периода
	{&fEM_R0IN12FN4,8,64},	//( - , AKNP4) Коэффициент B (А4 к 1)
	{&fEM_B0UX11RSS,8,40},	//( - , AKNP4) Второй коэффициент калибровки камеры 11
	{&fEM_R0UH05RSS,8,44},	//( - , AKNP4) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_R0UL51RSS,8,6},	//( - , AKNP4) Уровень АС по периоду разгона
	{&fEM_R7UX11RSS,8,20},	//( - , AKNP4) X-координата камеры R7IN42
	{&fEM_R7UX12RSS,8,22},	//( - , AKNP4) X-координата камеры R7IN43
	{&fEM_R7UY12RSS,8,28},	//( - , AKNP4) Y-координата камеры R7IN43
	{&fEM_A0UX11RSS,8,34},	//( - , AKNP4) Первый коэффициент калибровки камеры 11
	{&fEM_R0IN22FN4,8,66},	//( - , AKNP4) Коэффициент B (А4 к 2)
	{&fEM_R7UX10RSS,8,18},	//( - , AKNP4) X-координата камеры R7IN41
	{&fEM_R0UH02RSS,8,8},	//( - , AKNP4) Коэфф. преобразования частота->нейтр/с КНК15-1
	{&fEM_R7UY00RSS,8,16},	//( - , AKNP4) Y-координата АЗ1 (см)
	{&fEM_A0UX00RSS,8,30},	//( - , AKNP4) Эффективный радиус АЗ
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_A4Bz1[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_A4Bz1[]={
	{&R0VN61LS4,2,0},	//( - , A4Bz1, A4Bz2) ПС по мощности канал 4
	{&R0VN65LS4,2,1},	//( - , A4Bz1, A4Bz2) ПС по периоду разгона канал 4
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_A4Bz1[]={
	{&R0VN01RS4,8,2},	//( - , A4Bz1, A4Bz2) Период разгона канал 4
	{&R0VN02RS4,8,0},	//( - , A4Bz1, A4Bz2) Уровень мощности канал 4
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_A4Bz1[]={
	{&B8VC01RDU,8,0},	//( - , A4Bz1, A4Bz2) Координата АЗ2, мм
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_A4Bz2[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_A4Bz2[]={
	{&R0VN61LS4,2,0},	//( - , A4Bz1, A4Bz2) ПС по мощности канал 4
	{&R0VN65LS4,2,1},	//( - , A4Bz1, A4Bz2) ПС по периоду разгона канал 4
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_A4Bz2[]={
	{&R0VN02RS4,8,0},	//( - , A4Bz1, A4Bz2) Уровень мощности канал 4
	{&R0VN01RS4,8,2},	//( - , A4Bz1, A4Bz2) Период разгона канал 4
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_A4Bz2[]={
	{&B8VC01RDU,8,0},	//( - , A4Bz1, A4Bz2) Координата АЗ2, мм
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_DiagnAKNP4[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnAKNP4[]={
	{&R0DE39LS4,2,6},	//( - S09SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП24-2 место 4
	{&R0DE3CLS4,2,5},	//( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 7
	{&R0DEB4LS4,2,1},	//( - S13SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 8
	{&R0DEB2LS4,2,2},	//( - S11SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП24Д место 7
	{&R0DE38LS4,2,7},	//( - S08SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3 место 3
	{&R0DE35LS4,2,10},	//( - S05SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура больше 53
	{&R0DE34LS4,2,11},	//( - S04SBK, DiagnAKNP4) диагностика шкафа АКНП4 температура меньше 43
	{&R0DE33LS4,2,12},	//( - S03SBK, DiagnAKNP4) диагностика шкафа АКНП4 двери
	{&R0DE32LS4,2,13},	//( - S02SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 2
	{&R0DEB3LS4,2,0},	//( - S12SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 8
	{&R0DE3DLS4,2,4},	//( - , DiagnAKNP4) диагностика шкафа АКНП4 БП5/24Д место 8
	{&R0DEB1LS4,2,3},	//( - S10SBK, DiagnAKNP4) диагностика шкафа АКНП4 БП5 место 7
	{&R0DE36LS4,2,9},	//( - S06SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 1
	{&R0DE31LS4,2,14},	//( - S01SBK, DiagnAKNP4) диагностика шкафа АКНП4 сеть 1
	{&R0DE37LS4,2,8},	//( - S07SBK, DiagnAKNP4) диагностика шкафа АКНП4 МП15-3.1 место 2
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DiagnAKNP4[]={
	{&R0DE05LS4,3,0},	//( - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 5 месте
	{&R0DE04LS4,3,1},	//( - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 4 месте
	{&R0DE01LS4,3,3},	//( - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 1 месте
	{&R0DE02LS4,3,2},	//( - Diagn, DiagnAKNP4) диагностика модуля АКНП4 на 2 месте
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DiagnAKNP4[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MA4S[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MA4S[]={
	{&R0IS01FI0,2,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MA4S[]={
	{&R0IN02FI4,8,2},	//( - , SA4) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI4,8,4},	//( - , SA4) Выход КНК53М Гц от ПТИ
	{&R0IN01FI4,8,0},	//( - , SA4) Выход СНМ-11 Гц от ПТИ
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MA4S[]={
	{NULL,0,0},
}
#pragma pop
static char MA4S_ip1[]={"192.168.10.60\0"};
static char MA4S_ip2[]={"192.168.10.60\0"};
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_AKNP4[0],&di_AKNP4[0],&di_AKNP4[0],&hr_AKNP4[0],NULL,NULL,NULL,0},	//общий slave AKNP4
	{0,5018,&coil_A4Bz1[0],&di_A4Bz1[0],&di_A4Bz1[0],&hr_A4Bz1[0],NULL,NULL,NULL,0},	//slave AKNP4 - Baz1
	{0,5022,&coil_A4Bz2[0],&di_A4Bz2[0],&di_A4Bz2[0],&hr_A4Bz2[0],NULL,NULL,NULL,0},	//slave AKNP4 - Baz2
	{0,5003,&coil_DiagnAKNP4[0],&di_DiagnAKNP4[0],&di_DiagnAKNP4[0],&hr_DiagnAKNP4[0],NULL,NULL,NULL,0},	//Диагностика АКНП4
	{1,5009,&coil_MA4S[0],&di_MA4S[0],&di_MA4S[0],&hr_MA4S[0],NULL,MA4S_ip1,MA4S_ip2,100},	//Мастер AKNP4 в SCM
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
	{(&R0IN01FV4,8,0},
	{(&R0DE01LS4,3,10},
	{(&R0IN02FV4,8,5},
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
	{(&R0DE02LS4,3,10},
	{(&R0IN03FV4,8,0},
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
	{(&R0DE04LS4,3,64},
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
	{(&A1EE01LS4,1,28},
	{(&R0VN78LZ2,1,26},
	{(&R0VN74LZ2,1,24},
	{(&A0VN71LS4,1,22},
	{(&R0VN74LZ1,1,16},
	{(&R0IE02LS4,1,0},
	{(&R0VN78LZ1,1,18},
	{(&A0EE01LS4,1,20},
	{(&R0IE01LS4,1,2},
	{(&R0DE05LS4,3,38},
	{(&A1VN71LS4,1,30},
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
	{(&R0DE31LS4,1,0},
	{(&R0DE32LS4,1,2},
	{(&R0DE33LS4,1,4},
	{(&R0DE34LS4,1,6},
	{(&R0DE35LS4,1,8},
	{(&R0DE36LS4,1,10},
	{(&R0DE37LS4,1,12},
	{(&R0DE38LS4,1,14},
	{(&R0DE39LS4,1,16},
	{(&R0DEB3LS4,1,22},
	{(&R0DEB4LS4,1,24},
	{(&R0DEB2LS4,1,20},
	{(&R0DEB1LS4,1,18},
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
	setAsFloat(61,1.0);
	setAsFloat(65,0.0);
	setAsFloat(67,1);
	setAsFloat(70,0);
	setAsFloat(82,20);
	setAsFloat(74,37037.04 );
	setAsFloat(71,1);
	setAsFloat(80,0.5);
	setAsFloat(94,597.2);
	setAsFloat(64,0.0);
	setAsFloat(62,1.0);
	setAsFloat(86,0.005);
	setAsFloat(77,4000);
	setAsFloat(69,1);
	setAsFloat(87,5000);
	setAsFloat(83,5000);
	setAsFloat(89,1555.0);
	setAsFloat(91,1269.0);
	setAsFloat(93,594.0);
	setAsFloat(95,556.8);
	setAsFloat(76,32000.0);
	setAsFloat(68,0);
	setAsFloat(85,5100);
	setAsFloat(88,1570.0);
	setAsFloat(73,20);
	setAsFloat(79,1000000);
	setAsFloat(92,506.5);
	setAsFloat(60,11.0);
	setAsFloat(78,100000);
	setAsFloat(75,975000.0);
	setAsFloat(66,0.0);
	setAsFloat(63,1.0);
	setAsFloat(81,2.0);
	setAsFloat(72,0);
	setAsFloat(84,13.0);
	setAsFloat(90,1281.2);
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