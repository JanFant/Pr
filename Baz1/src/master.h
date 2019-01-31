#ifndef BAZ1_H
#define BAZ1_H
// Подсистема Baz1:Baz1
static char SimulOn=0;
static short CodeSub=4;
static char SimulIP[]="192.168.1.17\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 562
static char BUFFER[562];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.52\0", 5432, "192.168.10.152\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define A0IT01IZ1	 BUFFER[0]	//(A0IT01IZ1) Температура АЗ1-1
#define idA0IT01IZ1	 1	//(A0IT01IZ1) Температура АЗ1-1
#define A0CT01IZ1	 BUFFER[3]	//(A0CT01IZ1) Температура АЗ1-1
#define idA0CT01IZ1	 2	//(A0CT01IZ1) Температура АЗ1-1
#define A0VT61LZ1	 BUFFER[8]	//(A0VT61LZ1) ПС по температуре в АЗ1
#define idA0VT61LZ1	 3	//(A0VT61LZ1) ПС по температуре в АЗ1
#define A0VT71LZ1	 BUFFER[10]	//(A0VT71LZ1) АС по температуре в АЗ1
#define idA0VT71LZ1	 4	//(A0VT71LZ1) АС по температуре в АЗ1
#define A1VP41LZ1	 BUFFER[12]	//(A1VP41LZ1) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	 5	//(A1VP41LZ1) Давление СБРОС ББ1 ниже АС
#define B1VP41LZ1	 BUFFER[14]	//(B1VP41LZ1) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	 6	//(B1VP41LZ1) Давление СБРОС ББ2 ниже АС
#define B1VP81LZZ	 BUFFER[16]	//(B1VP81LZZ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	 7	//(B1VP81LZZ) Давление СБРОС ББ2 в норме
#define A1VP81LZZ	 BUFFER[18]	//(A1VP81LZZ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	 8	//(A1VP81LZZ) Давление СБРОС ББ1 в норме
#define A2VP41LZ1	 BUFFER[20]	//(A2VP41LZ1) Давление СБРОС РБ1 ниже АС
#define idA2VP41LZ1	 9	//(A2VP41LZ1) Давление СБРОС РБ1 ниже АС
#define A2CP01RZ1	 BUFFER[22]	//(A2CP01RZ1) Текущее давление СБРОС РБ1
#define idA2CP01RZ1	 10	//(A2CP01RZ1) Текущее давление СБРОС РБ1
#define A2VP51LZ1	 BUFFER[27]	//(A2VP51LZ1) Давление СБРОС РБ1 ниже ПС
#define idA2VP51LZ1	 11	//(A2VP51LZ1) Давление СБРОС РБ1 ниже ПС
#define B2VP41LZ1	 BUFFER[29]	//(B2VP41LZ1) Давление СБРОС РБ2 ниже АС
#define idB2VP41LZ1	 12	//(B2VP41LZ1) Давление СБРОС РБ2 ниже АС
#define B2CP01RZ1	 BUFFER[31]	//(B2CP01RZ1) Текущее давление СБРОС РБ2
#define idB2CP01RZ1	 13	//(B2CP01RZ1) Текущее давление СБРОС РБ2
#define B2VP51LZ1	 BUFFER[36]	//(B2VP51LZ1) Давление СБРОС РБ2 ниже ПС
#define idB2VP51LZ1	 14	//(B2VP51LZ1) Давление СБРОС РБ2 ниже ПС
#define B2VP81LZ1	 BUFFER[38]	//(B2VP81LZ1) Давление СБРОС РБ2 в норме
#define idB2VP81LZ1	 15	//(B2VP81LZ1) Давление СБРОС РБ2 в норме
#define A2VP81LZ1	 BUFFER[40]	//(A2VP81LZ1) Давление СБРОС РБ1 в норме
#define idA2VP81LZ1	 16	//(A2VP81LZ1) Давление СБРОС РБ1 в норме
#define A2IP01IZ1	 BUFFER[42]	//(A2IP01IZ1) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	 17	//(A2IP01IZ1) Текущее давление СБРОС РБ1
#define B2IP01IZ1	 BUFFER[45]	//(B2IP01IZ1) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	 18	//(B2IP01IZ1) Текущее давление СБРОС РБ2
#define R0ET01LZ1	 BUFFER[48]	//(R0ET01LZ1) Признак наличия неисправности по температуре  АЗ1
#define idR0ET01LZ1	 19	//(R0ET01LZ1) Признак наличия неисправности по температуре  АЗ1
#define B0IT01IZ1	 BUFFER[50]	//(B0IT01IZ1) Температура АЗ2-1
#define idB0IT01IZ1	 20	//(B0IT01IZ1) Температура АЗ2-1
#define A0VP41LZ1	 BUFFER[53]	//(A0VP41LZ1) Давление АЗ1 ниже АС
#define idA0VP41LZ1	 21	//(A0VP41LZ1) Давление АЗ1 ниже АС
#define B0VP41LZ1	 BUFFER[55]	//(B0VP41LZ1) Давление АЗ2 ниже АС
#define idB0VP41LZ1	 22	//(B0VP41LZ1) Давление АЗ2 ниже АС
#define B0VP81LZZ	 BUFFER[57]	//(B0VP81LZZ) Давление АЗ2 в норме
#define idB0VP81LZZ	 23	//(B0VP81LZZ) Давление АЗ2 в норме
#define A0VP81LZZ	 BUFFER[59]	//(A0VP81LZZ) Давление  АЗ1 в норме
#define idA0VP81LZZ	 24	//(A0VP81LZZ) Давление  АЗ1 в норме
#define R0ET02LZ1	 BUFFER[61]	//(R0ET02LZ1) Признак наличия неисправности по температуре АЗ2
#define idR0ET02LZ1	 25	//(R0ET02LZ1) Признак наличия неисправности по температуре АЗ2
#define B0EP02IZ1	 BUFFER[63]	//(B0EP02IZ1) Индикатор -Давление  АЗ2 ниже АС
#define idB0EP02IZ1	 26	//(B0EP02IZ1) Индикатор -Давление  АЗ2 ниже АС
#define A0EP02IZ1	 BUFFER[66]	//(A0EP02IZ1) Индикатор -Давление  АЗ1 ниже АС
#define idA0EP02IZ1	 27	//(A0EP02IZ1) Индикатор -Давление  АЗ1 ниже АС
#define A0VP71LZ1	 BUFFER[69]	//(A0VP71LZ1) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	 28	//(A0VP71LZ1) АЗ по АС любого давления для АЗ1
#define B0VP71LZ1	 BUFFER[71]	//(B0VP71LZ1) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	 29	//(B0VP71LZ1) АЗ по АС любого давления для АЗ2
#define R0VN02RS1	 BUFFER[73]	//(R0VN02RS1) Уровень мощности канал 1
#define idR0VN02RS1	 30	//(R0VN02RS1) Уровень мощности канал 1
#define R0VN02RS2	 BUFFER[78]	//(R0VN02RS2) Уровень мощности канал 2
#define idR0VN02RS2	 31	//(R0VN02RS2) Уровень мощности канал 2
#define R0VN02RS3	 BUFFER[83]	//(R0VN02RS3) Уровень мощности канал 3
#define idR0VN02RS3	 32	//(R0VN02RS3) Уровень мощности канал 3
#define R0VN02RS4	 BUFFER[88]	//(R0VN02RS4) Уровень мощности канал 4
#define idR0VN02RS4	 33	//(R0VN02RS4) Уровень мощности канал 4
#define R0VN01RS1	 BUFFER[93]	//(R0VN01RS1) Период разгона канал 1
#define idR0VN01RS1	 34	//(R0VN01RS1) Период разгона канал 1
#define R0VN01RS2	 BUFFER[98]	//(R0VN01RS2) Период разгона канал 2
#define idR0VN01RS2	 35	//(R0VN01RS2) Период разгона канал 2
#define R0VN01RS3	 BUFFER[103]	//(R0VN01RS3) Период разгона канал 3
#define idR0VN01RS3	 36	//(R0VN01RS3) Период разгона канал 3
#define R0VN01RS4	 BUFFER[108]	//(R0VN01RS4) Период разгона канал 4
#define idR0VN01RS4	 37	//(R0VN01RS4) Период разгона канал 4
#define R0VN61LS1	 BUFFER[113]	//(R0VN61LS1) ПС по мощности канал 1
#define idR0VN61LS1	 38	//(R0VN61LS1) ПС по мощности канал 1
#define R0VN61LS2	 BUFFER[115]	//(R0VN61LS2) ПС по мощности канал 2
#define idR0VN61LS2	 39	//(R0VN61LS2) ПС по мощности канал 2
#define R0VN61LS3	 BUFFER[117]	//(R0VN61LS3) ПС по мощности канал 3
#define idR0VN61LS3	 40	//(R0VN61LS3) ПС по мощности канал 3
#define R0VN61LS4	 BUFFER[119]	//(R0VN61LS4) ПС по мощности канал 4
#define idR0VN61LS4	 41	//(R0VN61LS4) ПС по мощности канал 4
#define R0VN65LS1	 BUFFER[121]	//(R0VN65LS1) ПС по периоду разгона канал 1
#define idR0VN65LS1	 42	//(R0VN65LS1) ПС по периоду разгона канал 1
#define R0VN65LS2	 BUFFER[123]	//(R0VN65LS2) ПС по периоду разгона  канал 2
#define idR0VN65LS2	 43	//(R0VN65LS2) ПС по периоду разгона  канал 2
#define R0VN65LS3	 BUFFER[125]	//(R0VN65LS3) ПС по периоду разгона канал 3
#define idR0VN65LS3	 44	//(R0VN65LS3) ПС по периоду разгона канал 3
#define R0VN65LS4	 BUFFER[127]	//(R0VN65LS4) ПС по периоду разгона канал 4
#define idR0VN65LS4	 45	//(R0VN65LS4) ПС по периоду разгона канал 4
#define R0VN01RZ1	 BUFFER[129]	//(R0VN01RZ1) Уровень мощности по каналу 1
#define idR0VN01RZ1	 46	//(R0VN01RZ1) Уровень мощности по каналу 1
#define R0VN02RZ1	 BUFFER[134]	//(R0VN02RZ1) Уровень мощности по каналу 2
#define idR0VN02RZ1	 47	//(R0VN02RZ1) Уровень мощности по каналу 2
#define R0VN03RZ1	 BUFFER[139]	//(R0VN03RZ1) Уровень мощности по каналу 3
#define idR0VN03RZ1	 48	//(R0VN03RZ1) Уровень мощности по каналу 3
#define R0VN04RZ1	 BUFFER[144]	//(R0VN04RZ1) Уровень мощности по каналу 4
#define idR0VN04RZ1	 49	//(R0VN04RZ1) Уровень мощности по каналу 4
#define R0VN05RZ1	 BUFFER[149]	//(R0VN05RZ1) Период разгона по каналу 1
#define idR0VN05RZ1	 50	//(R0VN05RZ1) Период разгона по каналу 1
#define R0VN06RZ1	 BUFFER[154]	//(R0VN06RZ1) Период разгона по каналу 2
#define idR0VN06RZ1	 51	//(R0VN06RZ1) Период разгона по каналу 2
#define R0VN07RZ1	 BUFFER[159]	//(R0VN07RZ1) Период разгона по каналу 3
#define idR0VN07RZ1	 52	//(R0VN07RZ1) Период разгона по каналу 3
#define R0VN08RZ1	 BUFFER[164]	//(R0VN08RZ1) Период разгона по каналу 4
#define idR0VN08RZ1	 53	//(R0VN08RZ1) Период разгона по каналу 4
#define R0VN61LZ1	 BUFFER[169]	//(R0VN61LZ1) ПС по мощности канал 1
#define idR0VN61LZ1	 54	//(R0VN61LZ1) ПС по мощности канал 1
#define R0VN62LZ1	 BUFFER[171]	//(R0VN62LZ1) ПС по мощности канал 2
#define idR0VN62LZ1	 55	//(R0VN62LZ1) ПС по мощности канал 2
#define R0VN63LZ1	 BUFFER[173]	//(R0VN63LZ1) ПС по мощности канал 3
#define idR0VN63LZ1	 56	//(R0VN63LZ1) ПС по мощности канал 3
#define R0VN64LZ1	 BUFFER[175]	//(R0VN64LZ1) ПС по мощности канал 4
#define idR0VN64LZ1	 57	//(R0VN64LZ1) ПС по мощности канал 4
#define R0VN65LZ1	 BUFFER[177]	//(R0VN65LZ1) ПС по периоду разгона канал 1
#define idR0VN65LZ1	 58	//(R0VN65LZ1) ПС по периоду разгона канал 1
#define R0VN66LZ1	 BUFFER[179]	//(R0VN66LZ1) ПС по периоду разгона канал 2
#define idR0VN66LZ1	 59	//(R0VN66LZ1) ПС по периоду разгона канал 2
#define R0VN67LZ1	 BUFFER[181]	//(R0VN67LZ1) ПС по периоду разгона канал 3
#define idR0VN67LZ1	 60	//(R0VN67LZ1) ПС по периоду разгона канал 3
#define R0VN68LZ1	 BUFFER[183]	//(R0VN68LZ1) ПС по периоду разгона канал 4
#define idR0VN68LZ1	 61	//(R0VN68LZ1) ПС по периоду разгона канал 4
#define R0VN09RZ1	 BUFFER[185]	//(R0VN09RZ1) Усредненный период разгона
#define idR0VN09RZ1	 62	//(R0VN09RZ1) Усредненный период разгона
#define A3IS11LDU	 BUFFER[190]	//(A3IS11LDU) Приход на ВУ ИС1
#define idA3IS11LDU	 63	//(A3IS11LDU) Приход на ВУ ИС1
#define A3IS22LDU	 BUFFER[192]	//(A3IS22LDU) Приход на НУП ИС1
#define idA3IS22LDU	 64	//(A3IS22LDU) Приход на НУП ИС1
#define R0AD03LZ1	 BUFFER[194]	//(R0AD03LZ1) Имитация прихода на ВУ ИС
#define idR0AD03LZ1	 65	//(R0AD03LZ1) Имитация прихода на ВУ ИС
#define B3IS11LDU	 BUFFER[196]	//(B3IS11LDU) Приход на ВУ ИС2
#define idB3IS11LDU	 66	//(B3IS11LDU) Приход на ВУ ИС2
#define A3VZ31LZ1	 BUFFER[198]	//(A3VZ31LZ1) АЗ от ВУ ИС1
#define idA3VZ31LZ1	 67	//(A3VZ31LZ1) АЗ от ВУ ИС1
#define B3VZ31LZ1	 BUFFER[200]	//(B3VZ31LZ1) АЗ от ВУ ИС2
#define idB3VZ31LZ1	 68	//(B3VZ31LZ1) АЗ от ВУ ИС2
#define R0AD05LZ1	 BUFFER[202]	//(R0AD05LZ1) Имитация ухода с НУП ИС
#define idR0AD05LZ1	 69	//(R0AD05LZ1) Имитация ухода с НУП ИС
#define A3VZ11LZ1	 BUFFER[204]	//(A3VZ11LZ1) АЗ от НУП ИС1
#define idA3VZ11LZ1	 70	//(A3VZ11LZ1) АЗ от НУП ИС1
#define B3VZ11LZ1	 BUFFER[206]	//(B3VZ11LZ1) АЗ от НУП ИС2
#define idB3VZ11LZ1	 71	//(B3VZ11LZ1) АЗ от НУП ИС2
#define B3IS22LDU	 BUFFER[208]	//(B3IS22LDU) Приход на НУП ИС2
#define idB3IS22LDU	 72	//(B3IS22LDU) Приход на НУП ИС2
#define R0VN69LZ1	 BUFFER[210]	//(R0VN69LZ1) ПС по усредненному периоду
#define idR0VN69LZ1	 73	//(R0VN69LZ1) ПС по усредненному периоду
#define R0VN79LZ1	 BUFFER[212]	//(R0VN79LZ1) АС по усредненному периоду
#define idR0VN79LZ1	 74	//(R0VN79LZ1) АС по усредненному периоду
#define R0VR02RZ1	 BUFFER[214]	//(R0VR02RZ1) Усредненная реактивность
#define idR0VR02RZ1	 75	//(R0VR02RZ1) Усредненная реактивность
#define R0VZ71LZ1	 BUFFER[219]	//(R0VZ71LZ1) Обобщенный сигнал АЗ 1 канала
#define idR0VZ71LZ1	 76	//(R0VZ71LZ1) Обобщенный сигнал АЗ 1 канала
#define R0VN70LZ1	 BUFFER[221]	//(R0VN70LZ1) АЗ по АС мощности РУ
#define idR0VN70LZ1	 77	//(R0VN70LZ1) АЗ по АС мощности РУ
#define R0VN80LZ1	 BUFFER[223]	//(R0VN80LZ1) АЗ по АС периода разгона РУ
#define idR0VN80LZ1	 78	//(R0VN80LZ1) АЗ по АС периода разгона РУ
#define A0EE01LS1	 BUFFER[225]	//(A0EE01LS1) Исправность АКНП канал 1
#define idA0EE01LS1	 79	//(A0EE01LS1) Исправность АКНП канал 1
#define A0EE01LS4	 BUFFER[227]	//(A0EE01LS4) Исправность АКНП канал 4
#define idA0EE01LS4	 80	//(A0EE01LS4) Исправность АКНП канал 4
#define A0EE01LS3	 BUFFER[229]	//(A0EE01LS3) Исправность АКНП канал 3
#define idA0EE01LS3	 81	//(A0EE01LS3) Исправность АКНП канал 3
#define A0EE01LZ1	 BUFFER[231]	//(A0EE01LZ1) Исправность АКНП1
#define idA0EE01LZ1	 82	//(A0EE01LZ1) Исправность АКНП1
#define A0EE04LZ1	 BUFFER[233]	//(A0EE04LZ1) Исправность АКНП4
#define idA0EE04LZ1	 83	//(A0EE04LZ1) Исправность АКНП4
#define A0EE02LZ1	 BUFFER[235]	//(A0EE02LZ1) Исправность АКНП2
#define idA0EE02LZ1	 84	//(A0EE02LZ1) Исправность АКНП2
#define A0EE03LZ1	 BUFFER[237]	//(A0EE03LZ1) Исправность АКНП3
#define idA0EE03LZ1	 85	//(A0EE03LZ1) Исправность АКНП3
#define A0EE01LS2	 BUFFER[239]	//(A0EE01LS2) Исправность АКНП  канал 2
#define idA0EE01LS2	 86	//(A0EE01LS2) Исправность АКНП  канал 2
#define A0EE05LZ1	 BUFFER[241]	//(A0EE05LZ1) Исправность сети АКНП1
#define idA0EE05LZ1	 87	//(A0EE05LZ1) Исправность сети АКНП1
#define A0EE06LZ1	 BUFFER[243]	//(A0EE06LZ1) Исправность сети АКНП2
#define idA0EE06LZ1	 88	//(A0EE06LZ1) Исправность сети АКНП2
#define A0EE07LZ1	 BUFFER[245]	//(A0EE07LZ1) Исправность сети АКНП3
#define idA0EE07LZ1	 89	//(A0EE07LZ1) Исправность сети АКНП3
#define A0EE08LZ1	 BUFFER[247]	//(A0EE08LZ1) Исправность сети АКНП4
#define idA0EE08LZ1	 90	//(A0EE08LZ1) Исправность сети АКНП4
#define A0VZ71LZ1	 BUFFER[249]	//(A0VZ71LZ1) Обобщенный сигнал АС по АЗ1
#define idA0VZ71LZ1	 91	//(A0VZ71LZ1) Обобщенный сигнал АС по АЗ1
#define A0EE00LZ1	 BUFFER[251]	//(A0EE00LZ1) Исправность АКНП АЗ1
#define idA0EE00LZ1	 92	//(A0EE00LZ1) Исправность АКНП АЗ1
#define B0EE00LZ1	 BUFFER[253]	//(B0EE00LZ1) Исправность АКНП АЗ2
#define idB0EE00LZ1	 93	//(B0EE00LZ1) Исправность АКНП АЗ2
#define B0VZ71LZ1	 BUFFER[255]	//(B0VZ71LZ1) Обобщенный сигнал АС по АЗ2
#define idB0VZ71LZ1	 94	//(B0VZ71LZ1) Обобщенный сигнал АС по АЗ2
#define A0VN71LZ1	 BUFFER[257]	//(A0VN71LZ1) АЗ по АС мощности  АЗ1
#define idA0VN71LZ1	 95	//(A0VN71LZ1) АЗ по АС мощности  АЗ1
#define B0VN71LZ1	 BUFFER[259]	//(B0VN71LZ1) АЗ по АС мощности  АЗ2
#define idB0VN71LZ1	 96	//(B0VN71LZ1) АЗ по АС мощности  АЗ2
#define A0VN81LZ1	 BUFFER[261]	//(A0VN81LZ1) АЗ по АС периода разгона АЗ1
#define idA0VN81LZ1	 97	//(A0VN81LZ1) АЗ по АС периода разгона АЗ1
#define B0VN81LZ1	 BUFFER[263]	//(B0VN81LZ1) АЗ по АС периода разгона АЗ2
#define idB0VN81LZ1	 98	//(B0VN81LZ1) АЗ по АС периода разгона АЗ2
#define R0EE02LDU	 BUFFER[265]	//(R0EE02LDU) Питание  АКНП  отключить
#define idR0EE02LDU	 99	//(R0EE02LDU) Питание  АКНП  отключить
#define R0VZ05UZ1	 BUFFER[267]	//(R0VZ05UZ1) Индикатор причины сброса
#define idR0VZ05UZ1	 100	//(R0VZ05UZ1) Индикатор причины сброса
#define R0VN11RZ1	 BUFFER[272]	//(R0VN11RZ1) Средняя мощность по БАЗ1
#define idR0VN11RZ1	 101	//(R0VN11RZ1) Средняя мощность по БАЗ1
#define R0VP73LZ1	 BUFFER[277]	//(R0VP73LZ1) ПС давления для РУ
#define idR0VP73LZ1	 102	//(R0VP73LZ1) ПС давления для РУ
#define B0CT01IZ1	 BUFFER[279]	//(B0CT01IZ1) Температура АЗ2-1
#define idB0CT01IZ1	 103	//(B0CT01IZ1) Температура АЗ2-1
#define B0VT61LZ1	 BUFFER[284]	//(B0VT61LZ1) ПС по температуре в АЗ2
#define idB0VT61LZ1	 104	//(B0VT61LZ1) ПС по температуре в АЗ2
#define B0VT71LZ1	 BUFFER[286]	//(B0VT71LZ1) АС по температуре в АЗ2
#define idB0VT71LZ1	 105	//(B0VT71LZ1) АС по температуре в АЗ2
#define A0VN71LS1	 BUFFER[288]	//(A0VN71LS1) Блокировка автоматического подъёма ББ канал 1
#define idA0VN71LS1	 106	//(A0VN71LS1) Блокировка автоматического подъёма ББ канал 1
#define A0VN71LS2	 BUFFER[290]	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2
#define idA0VN71LS2	 107	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2
#define A0VN71LS3	 BUFFER[292]	//(A0VN71LS3) Блокировка автоматического подъёма ББ канал 3
#define idA0VN71LS3	 108	//(A0VN71LS3) Блокировка автоматического подъёма ББ канал 3
#define A0VN71LS4	 BUFFER[294]	//(A0VN71LS4) Блокировка автоматического подъёма ББ канал 4
#define idA0VN71LS4	 109	//(A0VN71LS4) Блокировка автоматического подъёма ББ канал 4
#define A1VN71LZ1	 BUFFER[296]	//(A1VN71LZ1) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	 110	//(A1VN71LZ1) Блокировка автоматического подъёма ББ
#define A3VZ15LZ1	 BUFFER[298]	//(A3VZ15LZ1) Имитация АЗ от НУП ИС
#define idA3VZ15LZ1	 111	//(A3VZ15LZ1) Имитация АЗ от НУП ИС
#define A3VZ13LZ1	 BUFFER[300]	//(A3VZ13LZ1) Имитация АЗ от ВУ ИС
#define idA3VZ13LZ1	 112	//(A3VZ13LZ1) Имитация АЗ от ВУ ИС
#define R0VW13LDU	 BUFFER[302]	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 113	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	 BUFFER[304]	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 114	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R7II73LZ1	 BUFFER[306]	//(R7II73LZ1) Сработала АС II УР РАД
#define idR7II73LZ1	 115	//(R7II73LZ1) Сработала АС II УР РАД
#define R7II71LZ1	 BUFFER[308]	//(R7II71LZ1) Сработала АС IУР РАД (датчик 1)
#define idR7II71LZ1	 116	//(R7II71LZ1) Сработала АС IУР РАД (датчик 1)
#define R7II72LZ1	 BUFFER[310]	//(R7II72LZ1) Сработала АС IУР РАД  (датчик 2)
#define idR7II72LZ1	 117	//(R7II72LZ1) Сработала АС IУР РАД  (датчик 2)
#define R0AD14LZ1	 BUFFER[312]	//(R0AD14LZ1) Имитация АЗ от IIУР
#define idR0AD14LZ1	 118	//(R0AD14LZ1) Имитация АЗ от IIУР
#define R0AD21LDU	 BUFFER[314]	//(R0AD21LDU) Подключить защиту от II УР
#define idR0AD21LDU	 119	//(R0AD21LDU) Подключить защиту от II УР
#define R0AD14LDU	 BUFFER[316]	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 120	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
#define R0MD34LP1	 BUFFER[318]	//(R0MD34LP1) Кнопка (Квитировать)
#define idR0MD34LP1	 121	//(R0MD34LP1) Кнопка (Квитировать)
#define R0AD04LZ1	 BUFFER[320]	//(R0AD04LZ1) Имитация срабатывания верхней АС II УР
#define idR0AD04LZ1	 122	//(R0AD04LZ1) Имитация срабатывания верхней АС II УР
#define R0AD16LDU	 BUFFER[322]	//(R0AD16LDU) Имитация срабатывания верхней АС I УР
#define idR0AD16LDU	 123	//(R0AD16LDU) Имитация срабатывания верхней АС I УР
#define R0EE01LZ1	 BUFFER[324]	//(R0EE01LZ1) Питание  АКНП1  отключить
#define idR0EE01LZ1	 124	//(R0EE01LZ1) Питание  АКНП1  отключить
#define R6IS66LZZ	 BUFFER[326]	//(R6IS66LZZ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 125	//(R6IS66LZZ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[328]	//(R6IS67LZZ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 126	//(R6IS67LZZ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[330]	//(R6IS68LZZ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 127	//(R6IS68LZZ) Исправность ВИП 4,0 (№7) ССДИ-2
#define R0VN71LZ1	 BUFFER[332]	//(R0VN71LZ1) АС по мощности канал 1
#define idR0VN71LZ1	 128	//(R0VN71LZ1) АС по мощности канал 1
#define R0VN75LZ1	 BUFFER[334]	//(R0VN75LZ1) АС по периоду разгона канал 1
#define idR0VN75LZ1	 129	//(R0VN75LZ1) АС по периоду разгона канал 1
#define R0VN72LZ1	 BUFFER[336]	//(R0VN72LZ1) АС по мощности канал 2
#define idR0VN72LZ1	 130	//(R0VN72LZ1) АС по мощности канал 2
#define R0VN76LZ1	 BUFFER[338]	//(R0VN76LZ1) АС по периоду разгона канал  2
#define idR0VN76LZ1	 131	//(R0VN76LZ1) АС по периоду разгона канал  2
#define R0VN73LZ1	 BUFFER[340]	//(R0VN73LZ1) АС по мощности канал 3
#define idR0VN73LZ1	 132	//(R0VN73LZ1) АС по мощности канал 3
#define R0VN77LZ1	 BUFFER[342]	//(R0VN77LZ1) АС по периоду разгона канал  3
#define idR0VN77LZ1	 133	//(R0VN77LZ1) АС по периоду разгона канал  3
#define R0VN74LZ1	 BUFFER[344]	//(R0VN74LZ1) АС по мощности канал 4
#define idR0VN74LZ1	 134	//(R0VN74LZ1) АС по мощности канал 4
#define R0VN78LZ1	 BUFFER[346]	//(R0VN78LZ1) АС по периоду разгона канал  4
#define idR0VN78LZ1	 135	//(R0VN78LZ1) АС по периоду разгона канал  4
#define R0EE02LZ1	 BUFFER[348]	//(R0EE02LZ1) Питание  АКНП2  отключить
#define idR0EE02LZ1	 136	//(R0EE02LZ1) Питание  АКНП2  отключить
#define R0EE03LZ1	 BUFFER[350]	//(R0EE03LZ1) Питание  АКНП3  отключить
#define idR0EE03LZ1	 137	//(R0EE03LZ1) Питание  АКНП3  отключить
#define R0EE04LZ1	 BUFFER[352]	//(R0EE04LZ1) Питание  АКНП4  отключить
#define idR0EE04LZ1	 138	//(R0EE04LZ1) Питание  АКНП4  отключить
#define R0AD15LZ1	 BUFFER[354]	//(R0AD15LZ1) Имитация АЗ от 1УР (датчик1)
#define idR0AD15LZ1	 139	//(R0AD15LZ1) Имитация АЗ от 1УР (датчик1)
#define R0AD16LZ1	 BUFFER[356]	//(R0AD16LZ1) Имитация АЗ от 1УР (датчик2)
#define idR0AD16LZ1	 140	//(R0AD16LZ1) Имитация АЗ от 1УР (датчик2)
#define R0MW12IP2	 BUFFER[358]	//(R0MW12IP2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define idR0MW12IP2	 141	//(R0MW12IP2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
#define A2IS12LDU	 BUFFER[361]	//(A2IS12LDU) Магнит РБ1 зацеплен
#define idA2IS12LDU	 142	//(A2IS12LDU) Магнит РБ1 зацеплен
#define B2IS12LDU	 BUFFER[363]	//(B2IS12LDU) Магнит РБ2 зацеплен
#define idB2IS12LDU	 143	//(B2IS12LDU) Магнит РБ2 зацеплен
#define fEM_R0UT02RZZ	 BUFFER[365]	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RZZ	 144	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RZZ	 BUFFER[370]	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RZZ	 145	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
#define fEM_A2UP03RZZ	 BUFFER[375]	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define idfEM_A2UP03RZZ	 146	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
#define fEM_A2UP04RZZ	 BUFFER[380]	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define idfEM_A2UP04RZZ	 147	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
#define fEM_R0UT72RZZ	 BUFFER[385]	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define idfEM_R0UT72RZZ	 148	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
#define fEM_R0UT71RZZ	 BUFFER[390]	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define idfEM_R0UT71RZZ	 149	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
#define fEM_R0UT62RZZ	 BUFFER[395]	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define idfEM_R0UT62RZZ	 150	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
#define fEM_R0UT61RZZ	 BUFFER[400]	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define idfEM_R0UT61RZZ	 151	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
#define fEM_A2UP41RZZ	 BUFFER[405]	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define idfEM_A2UP41RZZ	 152	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
#define fEM_A2UP42RZZ	 BUFFER[410]	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define idfEM_A2UP42RZZ	 153	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
#define fEM_A2UP51RZZ	 BUFFER[415]	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define idfEM_A2UP51RZZ	 154	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
#define fEM_A2UP81RZZ	 BUFFER[420]	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP81RZZ	 155	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP84RZZ	 BUFFER[425]	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP84RZZ	 156	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP82RZZ	 BUFFER[430]	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP82RZZ	 157	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_A2UP52RZZ	 BUFFER[435]	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define idfEM_A2UP52RZZ	 158	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
#define fEM_A2UP83RZZ	 BUFFER[440]	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define idfEM_A2UP83RZZ	 159	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
#define fEM_R0UR01RZZ	 BUFFER[445]	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define idfEM_R0UR01RZZ	 160	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
#define fEM_R0UR04RZZ	 BUFFER[450]	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define idfEM_R0UR04RZZ	 161	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
#define fEM_A1UL12RZZ	 BUFFER[455]	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
#define idfEM_A1UL12RZZ	 162	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
#define fEM_A1UL11RZZ	 BUFFER[460]	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
#define idfEM_A1UL11RZZ	 163	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
#define fEM_R7UI73RZZ	 BUFFER[465]	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define idfEM_R7UI73RZZ	 164	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
#define bFirstEnterFlag	 BUFFER[470]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 165	//(bFirstEnterFlag) 
#define internal1_m244_tx	 BUFFER[472]	//(internal1_m244_tx) tx - время накопленное сек
#define idinternal1_m244_tx	 166	//(internal1_m244_tx) tx - время накопленное сек
#define internal1_m244_y0	 BUFFER[477]	//(internal1_m244_y0) y0
#define idinternal1_m244_y0	 167	//(internal1_m244_y0) y0
#define internal1_m252_tx	 BUFFER[478]	//(internal1_m252_tx) tx - время накопленное сек
#define idinternal1_m252_tx	 168	//(internal1_m252_tx) tx - время накопленное сек
#define internal1_m252_y0	 BUFFER[483]	//(internal1_m252_y0) y0
#define idinternal1_m252_y0	 169	//(internal1_m252_y0) y0
#define internal1_m315_tx	 BUFFER[484]	//(internal1_m315_tx) tx - время накопленное сек
#define idinternal1_m315_tx	 170	//(internal1_m315_tx) tx - время накопленное сек
#define internal1_m315_y0	 BUFFER[489]	//(internal1_m315_y0) y0
#define idinternal1_m315_y0	 171	//(internal1_m315_y0) y0
#define internal1_m211_tx	 BUFFER[490]	//(internal1_m211_tx) tx - время накопленное сек
#define idinternal1_m211_tx	 172	//(internal1_m211_tx) tx - время накопленное сек
#define internal1_m211_y0	 BUFFER[495]	//(internal1_m211_y0) y0
#define idinternal1_m211_y0	 173	//(internal1_m211_y0) y0
#define internal1_m210_tx	 BUFFER[496]	//(internal1_m210_tx) tx - время накопленное сек
#define idinternal1_m210_tx	 174	//(internal1_m210_tx) tx - время накопленное сек
#define internal1_m210_y0	 BUFFER[501]	//(internal1_m210_y0) y0
#define idinternal1_m210_y0	 175	//(internal1_m210_y0) y0
#define internal1_m208_tx	 BUFFER[502]	//(internal1_m208_tx) tx - время накопленное сек
#define idinternal1_m208_tx	 176	//(internal1_m208_tx) tx - время накопленное сек
#define internal1_m208_y0	 BUFFER[507]	//(internal1_m208_y0) y0
#define idinternal1_m208_y0	 177	//(internal1_m208_y0) y0
#define internal1_m206_tx	 BUFFER[508]	//(internal1_m206_tx) tx - время накопленное сек
#define idinternal1_m206_tx	 178	//(internal1_m206_tx) tx - время накопленное сек
#define internal1_m206_y0	 BUFFER[513]	//(internal1_m206_y0) y0
#define idinternal1_m206_y0	 179	//(internal1_m206_y0) y0
#define internal1_m33_tx	 BUFFER[514]	//(internal1_m33_tx) tx - внутренний параметр
#define idinternal1_m33_tx	 180	//(internal1_m33_tx) tx - внутренний параметр
#define internal1_m143_y0	 BUFFER[517]	//(internal1_m143_y0) y0
#define idinternal1_m143_y0	 181	//(internal1_m143_y0) y0
#define internal1_m141_y0	 BUFFER[522]	//(internal1_m141_y0) y0
#define idinternal1_m141_y0	 182	//(internal1_m141_y0) y0
#define internal1_m93_y0	 BUFFER[527]	//(internal1_m93_y0) y0
#define idinternal1_m93_y0	 183	//(internal1_m93_y0) y0
#define internal1_m91_y0	 BUFFER[532]	//(internal1_m91_y0) y0
#define idinternal1_m91_y0	 184	//(internal1_m91_y0) y0
#define internal1_m154_y1	 BUFFER[537]	//(internal1_m154_y1) y1 - внутренний параметр
#define idinternal1_m154_y1	 185	//(internal1_m154_y1) y1 - внутренний параметр
#define internal1_m165_y1	 BUFFER[539]	//(internal1_m165_y1) y1 - внутренний параметр
#define idinternal1_m165_y1	 186	//(internal1_m165_y1) y1 - внутренний параметр
#define internal1_m308_q0	 BUFFER[541]	//(internal1_m308_q0) q0 - внутренний параметр
#define idinternal1_m308_q0	 187	//(internal1_m308_q0) q0 - внутренний параметр
#define internal1_m130_y0	 BUFFER[546]	//(internal1_m130_y0) state
#define idinternal1_m130_y0	 188	//(internal1_m130_y0) state
#define internal1_m123_y0	 BUFFER[548]	//(internal1_m123_y0) state
#define idinternal1_m123_y0	 189	//(internal1_m123_y0) state
#define internal1_m106_y1	 BUFFER[550]	//(internal1_m106_y1) y1 - внутренний параметр
#define idinternal1_m106_y1	 190	//(internal1_m106_y1) y1 - внутренний параметр
#define internal1_m116_y1	 BUFFER[552]	//(internal1_m116_y1) y1 - внутренний параметр
#define idinternal1_m116_y1	 191	//(internal1_m116_y1) y1 - внутренний параметр
#define internal1_m97_y1	 BUFFER[554]	//(internal1_m97_y1) y1 - внутренний параметр
#define idinternal1_m97_y1	 192	//(internal1_m97_y1) y1 - внутренний параметр
#define internal1_m104_y1	 BUFFER[556]	//(internal1_m104_y1) y1 - внутренний параметр
#define idinternal1_m104_y1	 193	//(internal1_m104_y1) y1 - внутренний параметр
#define internal1_m153_y1	 BUFFER[558]	//(internal1_m153_y1) y1 - внутренний параметр
#define idinternal1_m153_y1	 194	//(internal1_m153_y1) y1 - внутренний параметр
#define internal1_m163_y1	 BUFFER[560]	//(internal1_m163_y1) y1 - внутренний параметр
#define idinternal1_m163_y1	 195	//(internal1_m163_y1) y1 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,3	,1	, &A0IT01IZ1},	//(A0IT01IZ1) Температура АЗ1-1
	{ 2	,8	,1	, &A0CT01IZ1},	//(A0CT01IZ1) Температура АЗ1-1
	{ 3	,1	,1	, &A0VT61LZ1},	//(A0VT61LZ1) ПС по температуре в АЗ1
	{ 4	,1	,1	, &A0VT71LZ1},	//(A0VT71LZ1) АС по температуре в АЗ1
	{ 5	,1	,1	, &A1VP41LZ1},	//(A1VP41LZ1) Давление СБРОС ББ1 ниже АС
	{ 6	,1	,1	, &B1VP41LZ1},	//(B1VP41LZ1) Давление СБРОС ББ2 ниже АС
	{ 7	,1	,1	, &B1VP81LZZ},	//(B1VP81LZZ) Давление СБРОС ББ2 в норме
	{ 8	,1	,1	, &A1VP81LZZ},	//(A1VP81LZZ) Давление СБРОС ББ1 в норме
	{ 9	,1	,1	, &A2VP41LZ1},	//(A2VP41LZ1) Давление СБРОС РБ1 ниже АС
	{ 10	,8	,1	, &A2CP01RZ1},	//(A2CP01RZ1) Текущее давление СБРОС РБ1
	{ 11	,1	,1	, &A2VP51LZ1},	//(A2VP51LZ1) Давление СБРОС РБ1 ниже ПС
	{ 12	,1	,1	, &B2VP41LZ1},	//(B2VP41LZ1) Давление СБРОС РБ2 ниже АС
	{ 13	,8	,1	, &B2CP01RZ1},	//(B2CP01RZ1) Текущее давление СБРОС РБ2
	{ 14	,1	,1	, &B2VP51LZ1},	//(B2VP51LZ1) Давление СБРОС РБ2 ниже ПС
	{ 15	,1	,1	, &B2VP81LZ1},	//(B2VP81LZ1) Давление СБРОС РБ2 в норме
	{ 16	,1	,1	, &A2VP81LZ1},	//(A2VP81LZ1) Давление СБРОС РБ1 в норме
	{ 17	,3	,1	, &A2IP01IZ1},	//(A2IP01IZ1) Текущее давление СБРОС РБ1
	{ 18	,3	,1	, &B2IP01IZ1},	//(B2IP01IZ1) Текущее давление СБРОС РБ2
	{ 19	,1	,1	, &R0ET01LZ1},	//(R0ET01LZ1) Признак наличия неисправности по температуре  АЗ1
	{ 20	,3	,1	, &B0IT01IZ1},	//(B0IT01IZ1) Температура АЗ2-1
	{ 21	,1	,1	, &A0VP41LZ1},	//(A0VP41LZ1) Давление АЗ1 ниже АС
	{ 22	,1	,1	, &B0VP41LZ1},	//(B0VP41LZ1) Давление АЗ2 ниже АС
	{ 23	,1	,1	, &B0VP81LZZ},	//(B0VP81LZZ) Давление АЗ2 в норме
	{ 24	,1	,1	, &A0VP81LZZ},	//(A0VP81LZZ) Давление  АЗ1 в норме
	{ 25	,1	,1	, &R0ET02LZ1},	//(R0ET02LZ1) Признак наличия неисправности по температуре АЗ2
	{ 26	,3	,1	, &B0EP02IZ1},	//(B0EP02IZ1) Индикатор -Давление  АЗ2 ниже АС
	{ 27	,3	,1	, &A0EP02IZ1},	//(A0EP02IZ1) Индикатор -Давление  АЗ1 ниже АС
	{ 28	,1	,1	, &A0VP71LZ1},	//(A0VP71LZ1) АЗ по АС любого давления для АЗ1
	{ 29	,1	,1	, &B0VP71LZ1},	//(B0VP71LZ1) АЗ по АС любого давления для АЗ2
	{ 30	,8	,1	, &R0VN02RS1},	//(R0VN02RS1) Уровень мощности канал 1
	{ 31	,8	,1	, &R0VN02RS2},	//(R0VN02RS2) Уровень мощности канал 2
	{ 32	,8	,1	, &R0VN02RS3},	//(R0VN02RS3) Уровень мощности канал 3
	{ 33	,8	,1	, &R0VN02RS4},	//(R0VN02RS4) Уровень мощности канал 4
	{ 34	,8	,1	, &R0VN01RS1},	//(R0VN01RS1) Период разгона канал 1
	{ 35	,8	,1	, &R0VN01RS2},	//(R0VN01RS2) Период разгона канал 2
	{ 36	,8	,1	, &R0VN01RS3},	//(R0VN01RS3) Период разгона канал 3
	{ 37	,8	,1	, &R0VN01RS4},	//(R0VN01RS4) Период разгона канал 4
	{ 38	,1	,1	, &R0VN61LS1},	//(R0VN61LS1) ПС по мощности канал 1
	{ 39	,1	,1	, &R0VN61LS2},	//(R0VN61LS2) ПС по мощности канал 2
	{ 40	,1	,1	, &R0VN61LS3},	//(R0VN61LS3) ПС по мощности канал 3
	{ 41	,1	,1	, &R0VN61LS4},	//(R0VN61LS4) ПС по мощности канал 4
	{ 42	,1	,1	, &R0VN65LS1},	//(R0VN65LS1) ПС по периоду разгона канал 1
	{ 43	,1	,1	, &R0VN65LS2},	//(R0VN65LS2) ПС по периоду разгона  канал 2
	{ 44	,1	,1	, &R0VN65LS3},	//(R0VN65LS3) ПС по периоду разгона канал 3
	{ 45	,1	,1	, &R0VN65LS4},	//(R0VN65LS4) ПС по периоду разгона канал 4
	{ 46	,8	,1	, &R0VN01RZ1},	//(R0VN01RZ1) Уровень мощности по каналу 1
	{ 47	,8	,1	, &R0VN02RZ1},	//(R0VN02RZ1) Уровень мощности по каналу 2
	{ 48	,8	,1	, &R0VN03RZ1},	//(R0VN03RZ1) Уровень мощности по каналу 3
	{ 49	,8	,1	, &R0VN04RZ1},	//(R0VN04RZ1) Уровень мощности по каналу 4
	{ 50	,8	,1	, &R0VN05RZ1},	//(R0VN05RZ1) Период разгона по каналу 1
	{ 51	,8	,1	, &R0VN06RZ1},	//(R0VN06RZ1) Период разгона по каналу 2
	{ 52	,8	,1	, &R0VN07RZ1},	//(R0VN07RZ1) Период разгона по каналу 3
	{ 53	,8	,1	, &R0VN08RZ1},	//(R0VN08RZ1) Период разгона по каналу 4
	{ 54	,1	,1	, &R0VN61LZ1},	//(R0VN61LZ1) ПС по мощности канал 1
	{ 55	,1	,1	, &R0VN62LZ1},	//(R0VN62LZ1) ПС по мощности канал 2
	{ 56	,1	,1	, &R0VN63LZ1},	//(R0VN63LZ1) ПС по мощности канал 3
	{ 57	,1	,1	, &R0VN64LZ1},	//(R0VN64LZ1) ПС по мощности канал 4
	{ 58	,1	,1	, &R0VN65LZ1},	//(R0VN65LZ1) ПС по периоду разгона канал 1
	{ 59	,1	,1	, &R0VN66LZ1},	//(R0VN66LZ1) ПС по периоду разгона канал 2
	{ 60	,1	,1	, &R0VN67LZ1},	//(R0VN67LZ1) ПС по периоду разгона канал 3
	{ 61	,1	,1	, &R0VN68LZ1},	//(R0VN68LZ1) ПС по периоду разгона канал 4
	{ 62	,8	,1	, &R0VN09RZ1},	//(R0VN09RZ1) Усредненный период разгона
	{ 63	,1	,1	, &A3IS11LDU},	//(A3IS11LDU) Приход на ВУ ИС1
	{ 64	,1	,1	, &A3IS22LDU},	//(A3IS22LDU) Приход на НУП ИС1
	{ 65	,1	,1	, &R0AD03LZ1},	//(R0AD03LZ1) Имитация прихода на ВУ ИС
	{ 66	,1	,1	, &B3IS11LDU},	//(B3IS11LDU) Приход на ВУ ИС2
	{ 67	,1	,1	, &A3VZ31LZ1},	//(A3VZ31LZ1) АЗ от ВУ ИС1
	{ 68	,1	,1	, &B3VZ31LZ1},	//(B3VZ31LZ1) АЗ от ВУ ИС2
	{ 69	,1	,1	, &R0AD05LZ1},	//(R0AD05LZ1) Имитация ухода с НУП ИС
	{ 70	,1	,1	, &A3VZ11LZ1},	//(A3VZ11LZ1) АЗ от НУП ИС1
	{ 71	,1	,1	, &B3VZ11LZ1},	//(B3VZ11LZ1) АЗ от НУП ИС2
	{ 72	,1	,1	, &B3IS22LDU},	//(B3IS22LDU) Приход на НУП ИС2
	{ 73	,1	,1	, &R0VN69LZ1},	//(R0VN69LZ1) ПС по усредненному периоду
	{ 74	,1	,1	, &R0VN79LZ1},	//(R0VN79LZ1) АС по усредненному периоду
	{ 75	,8	,1	, &R0VR02RZ1},	//(R0VR02RZ1) Усредненная реактивность
	{ 76	,1	,1	, &R0VZ71LZ1},	//(R0VZ71LZ1) Обобщенный сигнал АЗ 1 канала
	{ 77	,1	,1	, &R0VN70LZ1},	//(R0VN70LZ1) АЗ по АС мощности РУ
	{ 78	,1	,1	, &R0VN80LZ1},	//(R0VN80LZ1) АЗ по АС периода разгона РУ
	{ 79	,1	,1	, &A0EE01LS1},	//(A0EE01LS1) Исправность АКНП канал 1
	{ 80	,1	,1	, &A0EE01LS4},	//(A0EE01LS4) Исправность АКНП канал 4
	{ 81	,1	,1	, &A0EE01LS3},	//(A0EE01LS3) Исправность АКНП канал 3
	{ 82	,1	,1	, &A0EE01LZ1},	//(A0EE01LZ1) Исправность АКНП1
	{ 83	,1	,1	, &A0EE04LZ1},	//(A0EE04LZ1) Исправность АКНП4
	{ 84	,1	,1	, &A0EE02LZ1},	//(A0EE02LZ1) Исправность АКНП2
	{ 85	,1	,1	, &A0EE03LZ1},	//(A0EE03LZ1) Исправность АКНП3
	{ 86	,1	,1	, &A0EE01LS2},	//(A0EE01LS2) Исправность АКНП  канал 2
	{ 87	,1	,1	, &A0EE05LZ1},	//(A0EE05LZ1) Исправность сети АКНП1
	{ 88	,1	,1	, &A0EE06LZ1},	//(A0EE06LZ1) Исправность сети АКНП2
	{ 89	,1	,1	, &A0EE07LZ1},	//(A0EE07LZ1) Исправность сети АКНП3
	{ 90	,1	,1	, &A0EE08LZ1},	//(A0EE08LZ1) Исправность сети АКНП4
	{ 91	,1	,1	, &A0VZ71LZ1},	//(A0VZ71LZ1) Обобщенный сигнал АС по АЗ1
	{ 92	,1	,1	, &A0EE00LZ1},	//(A0EE00LZ1) Исправность АКНП АЗ1
	{ 93	,1	,1	, &B0EE00LZ1},	//(B0EE00LZ1) Исправность АКНП АЗ2
	{ 94	,1	,1	, &B0VZ71LZ1},	//(B0VZ71LZ1) Обобщенный сигнал АС по АЗ2
	{ 95	,1	,1	, &A0VN71LZ1},	//(A0VN71LZ1) АЗ по АС мощности  АЗ1
	{ 96	,1	,1	, &B0VN71LZ1},	//(B0VN71LZ1) АЗ по АС мощности  АЗ2
	{ 97	,1	,1	, &A0VN81LZ1},	//(A0VN81LZ1) АЗ по АС периода разгона АЗ1
	{ 98	,1	,1	, &B0VN81LZ1},	//(B0VN81LZ1) АЗ по АС периода разгона АЗ2
	{ 99	,1	,1	, &R0EE02LDU},	//(R0EE02LDU) Питание  АКНП  отключить
	{ 100	,5	,1	, &R0VZ05UZ1},	//(R0VZ05UZ1) Индикатор причины сброса
	{ 101	,8	,1	, &R0VN11RZ1},	//(R0VN11RZ1) Средняя мощность по БАЗ1
	{ 102	,1	,1	, &R0VP73LZ1},	//(R0VP73LZ1) ПС давления для РУ
	{ 103	,8	,1	, &B0CT01IZ1},	//(B0CT01IZ1) Температура АЗ2-1
	{ 104	,1	,1	, &B0VT61LZ1},	//(B0VT61LZ1) ПС по температуре в АЗ2
	{ 105	,1	,1	, &B0VT71LZ1},	//(B0VT71LZ1) АС по температуре в АЗ2
	{ 106	,1	,1	, &A0VN71LS1},	//(A0VN71LS1) Блокировка автоматического подъёма ББ канал 1
	{ 107	,1	,1	, &A0VN71LS2},	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2
	{ 108	,1	,1	, &A0VN71LS3},	//(A0VN71LS3) Блокировка автоматического подъёма ББ канал 3
	{ 109	,1	,1	, &A0VN71LS4},	//(A0VN71LS4) Блокировка автоматического подъёма ББ канал 4
	{ 110	,1	,1	, &A1VN71LZ1},	//(A1VN71LZ1) Блокировка автоматического подъёма ББ
	{ 111	,1	,1	, &A3VZ15LZ1},	//(A3VZ15LZ1) Имитация АЗ от НУП ИС
	{ 112	,1	,1	, &A3VZ13LZ1},	//(A3VZ13LZ1) Имитация АЗ от ВУ ИС
	{ 113	,1	,1	, &R0VW13LDU},	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 114	,1	,1	, &R0VW23LDU},	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 115	,1	,1	, &R7II73LZ1},	//(R7II73LZ1) Сработала АС II УР РАД
	{ 116	,1	,1	, &R7II71LZ1},	//(R7II71LZ1) Сработала АС IУР РАД (датчик 1)
	{ 117	,1	,1	, &R7II72LZ1},	//(R7II72LZ1) Сработала АС IУР РАД  (датчик 2)
	{ 118	,1	,1	, &R0AD14LZ1},	//(R0AD14LZ1) Имитация АЗ от IIУР
	{ 119	,1	,1	, &R0AD21LDU},	//(R0AD21LDU) Подключить защиту от II УР
	{ 120	,1	,1	, &R0AD14LDU},	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
	{ 121	,1	,1	, &R0MD34LP1},	//(R0MD34LP1) Кнопка (Квитировать)
	{ 122	,1	,1	, &R0AD04LZ1},	//(R0AD04LZ1) Имитация срабатывания верхней АС II УР
	{ 123	,1	,1	, &R0AD16LDU},	//(R0AD16LDU) Имитация срабатывания верхней АС I УР
	{ 124	,1	,1	, &R0EE01LZ1},	//(R0EE01LZ1) Питание  АКНП1  отключить
	{ 125	,1	,1	, &R6IS66LZZ},	//(R6IS66LZZ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 126	,1	,1	, &R6IS67LZZ},	//(R6IS67LZZ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 127	,1	,1	, &R6IS68LZZ},	//(R6IS68LZZ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 128	,1	,1	, &R0VN71LZ1},	//(R0VN71LZ1) АС по мощности канал 1
	{ 129	,1	,1	, &R0VN75LZ1},	//(R0VN75LZ1) АС по периоду разгона канал 1
	{ 130	,1	,1	, &R0VN72LZ1},	//(R0VN72LZ1) АС по мощности канал 2
	{ 131	,1	,1	, &R0VN76LZ1},	//(R0VN76LZ1) АС по периоду разгона канал  2
	{ 132	,1	,1	, &R0VN73LZ1},	//(R0VN73LZ1) АС по мощности канал 3
	{ 133	,1	,1	, &R0VN77LZ1},	//(R0VN77LZ1) АС по периоду разгона канал  3
	{ 134	,1	,1	, &R0VN74LZ1},	//(R0VN74LZ1) АС по мощности канал 4
	{ 135	,1	,1	, &R0VN78LZ1},	//(R0VN78LZ1) АС по периоду разгона канал  4
	{ 136	,1	,1	, &R0EE02LZ1},	//(R0EE02LZ1) Питание  АКНП2  отключить
	{ 137	,1	,1	, &R0EE03LZ1},	//(R0EE03LZ1) Питание  АКНП3  отключить
	{ 138	,1	,1	, &R0EE04LZ1},	//(R0EE04LZ1) Питание  АКНП4  отключить
	{ 139	,1	,1	, &R0AD15LZ1},	//(R0AD15LZ1) Имитация АЗ от 1УР (датчик1)
	{ 140	,1	,1	, &R0AD16LZ1},	//(R0AD16LZ1) Имитация АЗ от 1УР (датчик2)
	{ 141	,3	,1	, &R0MW12IP2},	//(R0MW12IP2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{ 142	,1	,1	, &A2IS12LDU},	//(A2IS12LDU) Магнит РБ1 зацеплен
	{ 143	,1	,1	, &B2IS12LDU},	//(B2IS12LDU) Магнит РБ2 зацеплен
	{ 144	,8	,1	, &fEM_R0UT02RZZ},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{ 145	,8	,1	, &fEM_R0UT01RZZ},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{ 146	,8	,1	, &fEM_A2UP03RZZ},	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{ 147	,8	,1	, &fEM_A2UP04RZZ},	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{ 148	,8	,1	, &fEM_R0UT72RZZ},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{ 149	,8	,1	, &fEM_R0UT71RZZ},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{ 150	,8	,1	, &fEM_R0UT62RZZ},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{ 151	,8	,1	, &fEM_R0UT61RZZ},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{ 152	,8	,1	, &fEM_A2UP41RZZ},	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{ 153	,8	,1	, &fEM_A2UP42RZZ},	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{ 154	,8	,1	, &fEM_A2UP51RZZ},	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{ 155	,8	,1	, &fEM_A2UP81RZZ},	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{ 156	,8	,1	, &fEM_A2UP84RZZ},	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{ 157	,8	,1	, &fEM_A2UP82RZZ},	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{ 158	,8	,1	, &fEM_A2UP52RZZ},	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{ 159	,8	,1	, &fEM_A2UP83RZZ},	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{ 160	,8	,1	, &fEM_R0UR01RZZ},	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
	{ 161	,8	,1	, &fEM_R0UR04RZZ},	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
	{ 162	,8	,1	, &fEM_A1UL12RZZ},	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
	{ 163	,8	,1	, &fEM_A1UL11RZZ},	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
	{ 164	,8	,1	, &fEM_R7UI73RZZ},	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
	{ 165	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 166	,8	,1	, &internal1_m244_tx},	//(internal1_m244_tx) tx - время накопленное сек
	{ 167	,18	,1	, &internal1_m244_y0},	//(internal1_m244_y0) y0
	{ 168	,8	,1	, &internal1_m252_tx},	//(internal1_m252_tx) tx - время накопленное сек
	{ 169	,18	,1	, &internal1_m252_y0},	//(internal1_m252_y0) y0
	{ 170	,8	,1	, &internal1_m315_tx},	//(internal1_m315_tx) tx - время накопленное сек
	{ 171	,18	,1	, &internal1_m315_y0},	//(internal1_m315_y0) y0
	{ 172	,8	,1	, &internal1_m211_tx},	//(internal1_m211_tx) tx - время накопленное сек
	{ 173	,18	,1	, &internal1_m211_y0},	//(internal1_m211_y0) y0
	{ 174	,8	,1	, &internal1_m210_tx},	//(internal1_m210_tx) tx - время накопленное сек
	{ 175	,18	,1	, &internal1_m210_y0},	//(internal1_m210_y0) y0
	{ 176	,8	,1	, &internal1_m208_tx},	//(internal1_m208_tx) tx - время накопленное сек
	{ 177	,18	,1	, &internal1_m208_y0},	//(internal1_m208_y0) y0
	{ 178	,8	,1	, &internal1_m206_tx},	//(internal1_m206_tx) tx - время накопленное сек
	{ 179	,18	,1	, &internal1_m206_y0},	//(internal1_m206_y0) y0
	{ 180	,3	,1	, &internal1_m33_tx},	//(internal1_m33_tx) tx - внутренний параметр
	{ 181	,8	,1	, &internal1_m143_y0},	//(internal1_m143_y0) y0
	{ 182	,8	,1	, &internal1_m141_y0},	//(internal1_m141_y0) y0
	{ 183	,8	,1	, &internal1_m93_y0},	//(internal1_m93_y0) y0
	{ 184	,8	,1	, &internal1_m91_y0},	//(internal1_m91_y0) y0
	{ 185	,1	,1	, &internal1_m154_y1},	//(internal1_m154_y1) y1 - внутренний параметр
	{ 186	,1	,1	, &internal1_m165_y1},	//(internal1_m165_y1) y1 - внутренний параметр
	{ 187	,5	,1	, &internal1_m308_q0},	//(internal1_m308_q0) q0 - внутренний параметр
	{ 188	,1	,1	, &internal1_m130_y0},	//(internal1_m130_y0) state
	{ 189	,1	,1	, &internal1_m123_y0},	//(internal1_m123_y0) state
	{ 190	,1	,1	, &internal1_m106_y1},	//(internal1_m106_y1) y1 - внутренний параметр
	{ 191	,1	,1	, &internal1_m116_y1},	//(internal1_m116_y1) y1 - внутренний параметр
	{ 192	,1	,1	, &internal1_m97_y1},	//(internal1_m97_y1) y1 - внутренний параметр
	{ 193	,1	,1	, &internal1_m104_y1},	//(internal1_m104_y1) y1 - внутренний параметр
	{ 194	,1	,1	, &internal1_m153_y1},	//(internal1_m153_y1) y1 - внутренний параметр
	{ 195	,1	,1	, &internal1_m163_y1},	//(internal1_m163_y1) y1 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="baz1.bin\0";   // Имя файла для сохранения констант
#pragma pop
static short saveVariables[]={      // Id переменных для сохранения
144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,-1,};
#pragma pack(push,1)
static ModbusRegister coil_Baz1[]={  // 
	{&R0VN61LZ1,1,0},	//(R0VN61LZ1) ПС по мощности канал 1
	{&R0VN62LZ1,1,1},	//(R0VN62LZ1) ПС по мощности канал 2
	{&R0VN63LZ1,1,2},	//(R0VN63LZ1) ПС по мощности канал 3
	{&R0VN64LZ1,1,3},	//(R0VN64LZ1) ПС по мощности канал 4
	{&R0VZ71LZ1,1,4},	//(R0VZ71LZ1) Обобщенный сигнал АЗ 1 канала
	{&R0VN70LZ1,1,5},	//(R0VN70LZ1) АЗ по АС мощности РУ
	{&A0EE05LZ1,1,6},	//(A0EE05LZ1) Исправность сети АКНП1
	{&A0EE06LZ1,1,7},	//(A0EE06LZ1) Исправность сети АКНП2
	{&A0EE07LZ1,1,8},	//(A0EE07LZ1) Исправность сети АКНП3
	{&A0EE08LZ1,1,9},	//(A0EE08LZ1) Исправность сети АКНП4
	{&R0EE02LDU,1,10},	//(R0EE02LDU) Питание  АКНП  отключить
	{&R0VW13LDU,1,11},	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{&R0VW23LDU,1,12},	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R7II73LZ1,1,13},	//(R7II73LZ1) Сработала АС II УР РАД
	{&R7II71LZ1,1,14},	//(R7II71LZ1) Сработала АС IУР РАД (датчик 1)
	{&R7II72LZ1,1,15},	//(R7II72LZ1) Сработала АС IУР РАД  (датчик 2)
	{&R0AD14LDU,1,16},	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
	{&R0MD34LP1,1,17},	//(R0MD34LP1) Кнопка (Квитировать)
	{&R0AD16LDU,1,18},	//(R0AD16LDU) Имитация срабатывания верхней АС I УР
	{&R0VN71LZ1,1,19},	//(R0VN71LZ1) АС по мощности канал 1
	{&R0VN75LZ1,1,20},	//(R0VN75LZ1) АС по периоду разгона канал 1
	{&R0VN72LZ1,1,21},	//(R0VN72LZ1) АС по мощности канал 2
	{&R0VN76LZ1,1,22},	//(R0VN76LZ1) АС по периоду разгона канал  2
	{&R0VN73LZ1,1,23},	//(R0VN73LZ1) АС по мощности канал 3
	{&R0VN77LZ1,1,24},	//(R0VN77LZ1) АС по периоду разгона канал  3
	{&R0VN74LZ1,1,25},	//(R0VN74LZ1) АС по мощности канал 4
	{&R0VN78LZ1,1,26},	//(R0VN78LZ1) АС по периоду разгона канал  4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_Baz1[]={  // 
	{&A0VT61LZ1,1,0},	//(A0VT61LZ1) ПС по температуре в АЗ1
	{&A0VT71LZ1,1,1},	//(A0VT71LZ1) АС по температуре в АЗ1
	{&A1VP41LZ1,1,2},	//(A1VP41LZ1) Давление СБРОС ББ1 ниже АС
	{&B1VP41LZ1,1,3},	//(B1VP41LZ1) Давление СБРОС ББ2 ниже АС
	{&A2VP41LZ1,1,4},	//(A2VP41LZ1) Давление СБРОС РБ1 ниже АС
	{&A2VP51LZ1,1,5},	//(A2VP51LZ1) Давление СБРОС РБ1 ниже ПС
	{&B2VP41LZ1,1,6},	//(B2VP41LZ1) Давление СБРОС РБ2 ниже АС
	{&B2VP51LZ1,1,7},	//(B2VP51LZ1) Давление СБРОС РБ2 ниже ПС
	{&B2VP81LZ1,1,8},	//(B2VP81LZ1) Давление СБРОС РБ2 в норме
	{&A2VP81LZ1,1,9},	//(A2VP81LZ1) Давление СБРОС РБ1 в норме
	{&R0ET01LZ1,1,10},	//(R0ET01LZ1) Признак наличия неисправности по температуре  АЗ1
	{&A0VP41LZ1,1,11},	//(A0VP41LZ1) Давление АЗ1 ниже АС
	{&B0VP41LZ1,1,12},	//(B0VP41LZ1) Давление АЗ2 ниже АС
	{&R0ET02LZ1,1,13},	//(R0ET02LZ1) Признак наличия неисправности по температуре АЗ2
	{&A0VP71LZ1,1,14},	//(A0VP71LZ1) АЗ по АС любого давления для АЗ1
	{&B0VP71LZ1,1,15},	//(B0VP71LZ1) АЗ по АС любого давления для АЗ2
	{&R0VN65LZ1,1,16},	//(R0VN65LZ1) ПС по периоду разгона канал 1
	{&R0VN66LZ1,1,17},	//(R0VN66LZ1) ПС по периоду разгона канал 2
	{&R0VN67LZ1,1,18},	//(R0VN67LZ1) ПС по периоду разгона канал 3
	{&R0VN68LZ1,1,19},	//(R0VN68LZ1) ПС по периоду разгона канал 4
	{&A3VZ31LZ1,1,20},	//(A3VZ31LZ1) АЗ от ВУ ИС1
	{&B3VZ31LZ1,1,21},	//(B3VZ31LZ1) АЗ от ВУ ИС2
	{&A3VZ11LZ1,1,22},	//(A3VZ11LZ1) АЗ от НУП ИС1
	{&B3VZ11LZ1,1,23},	//(B3VZ11LZ1) АЗ от НУП ИС2
	{&R0VN69LZ1,1,24},	//(R0VN69LZ1) ПС по усредненному периоду
	{&R0VN79LZ1,1,25},	//(R0VN79LZ1) АС по усредненному периоду
	{&R0VN80LZ1,1,26},	//(R0VN80LZ1) АЗ по АС периода разгона РУ
	{&A0EE01LZ1,1,27},	//(A0EE01LZ1) Исправность АКНП1
	{&A0EE04LZ1,1,28},	//(A0EE04LZ1) Исправность АКНП4
	{&A0EE02LZ1,1,29},	//(A0EE02LZ1) Исправность АКНП2
	{&A0EE03LZ1,1,30},	//(A0EE03LZ1) Исправность АКНП3
	{&A0VZ71LZ1,1,31},	//(A0VZ71LZ1) Обобщенный сигнал АС по АЗ1
	{&A0EE00LZ1,1,32},	//(A0EE00LZ1) Исправность АКНП АЗ1
	{&B0EE00LZ1,1,33},	//(B0EE00LZ1) Исправность АКНП АЗ2
	{&B0VZ71LZ1,1,34},	//(B0VZ71LZ1) Обобщенный сигнал АС по АЗ2
	{&A0VN71LZ1,1,35},	//(A0VN71LZ1) АЗ по АС мощности  АЗ1
	{&B0VN71LZ1,1,36},	//(B0VN71LZ1) АЗ по АС мощности  АЗ2
	{&A0VN81LZ1,1,37},	//(A0VN81LZ1) АЗ по АС периода разгона АЗ1
	{&B0VN81LZ1,1,38},	//(B0VN81LZ1) АЗ по АС периода разгона АЗ2
	{&R0VP73LZ1,1,39},	//(R0VP73LZ1) ПС давления для РУ
	{&B0VT61LZ1,1,40},	//(B0VT61LZ1) ПС по температуре в АЗ2
	{&B0VT71LZ1,1,41},	//(B0VT71LZ1) АС по температуре в АЗ2
	{&R0AD15LZ1,1,42},	//(R0AD15LZ1) Имитация АЗ от 1УР (датчик1)
	{&R0AD16LZ1,1,43},	//(R0AD16LZ1) Имитация АЗ от 1УР (датчик2)
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_Baz1[]={  // 
	{&A0CT01IZ1,8,0},	//(A0CT01IZ1) Температура АЗ1-1
	{&A2CP01RZ1,8,2},	//(A2CP01RZ1) Текущее давление СБРОС РБ1
	{&B2CP01RZ1,8,4},	//(B2CP01RZ1) Текущее давление СБРОС РБ2
	{&B0EP02IZ1,3,6},	//(B0EP02IZ1) Индикатор -Давление  АЗ2 ниже АС
	{&A0EP02IZ1,3,7},	//(A0EP02IZ1) Индикатор -Давление  АЗ1 ниже АС
	{&R0VN01RZ1,8,8},	//(R0VN01RZ1) Уровень мощности по каналу 1
	{&R0VN02RZ1,8,10},	//(R0VN02RZ1) Уровень мощности по каналу 2
	{&R0VN03RZ1,8,12},	//(R0VN03RZ1) Уровень мощности по каналу 3
	{&R0VN04RZ1,8,14},	//(R0VN04RZ1) Уровень мощности по каналу 4
	{&R0VN05RZ1,8,16},	//(R0VN05RZ1) Период разгона по каналу 1
	{&R0VN06RZ1,8,18},	//(R0VN06RZ1) Период разгона по каналу 2
	{&R0VN07RZ1,8,20},	//(R0VN07RZ1) Период разгона по каналу 3
	{&R0VN08RZ1,8,22},	//(R0VN08RZ1) Период разгона по каналу 4
	{&R0VN09RZ1,8,24},	//(R0VN09RZ1) Усредненный период разгона
	{&R0VR02RZ1,8,26},	//(R0VR02RZ1) Усредненная реактивность
	{&R0VZ05UZ1,5,28},	//(R0VZ05UZ1) Индикатор причины сброса
	{&R0VN11RZ1,8,30},	//(R0VN11RZ1) Средняя мощность по БАЗ1
	{&B0CT01IZ1,8,32},	//(B0CT01IZ1) Температура АЗ2-1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_Baz1[]={  // 
	{&R0MW12IP2,3,0},	//(R0MW12IP2) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ ИС
	{&fEM_R0UT02RZZ,8,1},	//(R0UT02RZZ) Верхний предел шкалы датчика температуры
	{&fEM_R0UT01RZZ,8,3},	//(R0UT01RZZ) Нижний предел шкалы датчика температуры
	{&fEM_A2UP03RZZ,8,5},	//(A2UP03RZZ) Верхний предел шкалы датчика давления на подъем/сброс РБ,ББ
	{&fEM_A2UP04RZZ,8,7},	//(A2UP04RZZ) Нижний предел шкалы датчика давления на подъем/сброс РБ.ББ
	{&fEM_R0UT72RZZ,8,9},	//(R0UT72RZZ) Граница неоднозначности срабатывания аварийной сигнализации по температуре АЗ (град)
	{&fEM_R0UT71RZZ,8,11},	//(R0UT71RZZ) Уровень срабатывания аварийной сигнализации по температуре АЗ
	{&fEM_R0UT62RZZ,8,13},	//(R0UT62RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по температуре АЗ (град)
	{&fEM_R0UT61RZZ,8,15},	//(R0UT61RZZ) Уровень срабатывания предупредительной сигнализации по температуре АЗ
	{&fEM_A2UP41RZZ,8,17},	//(A2UP41RZZ) Уровень срабатывания аварийной сигнализации по давлению СБРОС РБ
	{&fEM_A2UP42RZZ,8,19},	//(A2UP42RZZ) Граница неоднозначности срабатывания аварийной сигнализации по давлению СБРОС РБ (МПа)
	{&fEM_A2UP51RZZ,8,21},	//(A2UP51RZZ) Уровень срабатывания предупредительной по давлению СБРОС РБ (МПа)
	{&fEM_A2UP81RZZ,8,23},	//(A2UP81RZZ) Нижняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{&fEM_A2UP84RZZ,8,25},	//(A2UP84RZZ) Верхняя граница неоднозначности нормализации давления СБРОС РБ (МПа)
	{&fEM_A2UP82RZZ,8,27},	//(A2UP82RZZ) Нижняя граница нормализации давления СБРОС РБ (МПа)
	{&fEM_A2UP52RZZ,8,29},	//(A2UP52RZZ) Граница неоднозначности срабатывания предупредительной сигнализации по давлению СБРОС РБ(МПа)
	{&fEM_A2UP83RZZ,8,31},	//(A2UP83RZZ) Верхняя граница нормализации давления СБРОС РБ (МПа)
	{&fEM_R0UR01RZZ,8,33},	//(R0UR01RZZ) Уставка АКНП ПС  АЗ по периоду (сек)
	{&fEM_R0UR04RZZ,8,35},	//(R0UR04RZZ) Уставка АКНП АС  АЗ по периоду (сек)
	{&fEM_A1UL12RZZ,8,37},	//(A1UL12RZZ) Время задержки АЗ от НУ ИС(сек)
	{&fEM_A1UL11RZZ,8,39},	//(A1UL11RZZ) Время задержки АЗ от ВУ ИС сек
	{&fEM_R7UI73RZZ,8,41},	//(R7UI73RZZ) Время задержки  срабатывания АС II УР
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SBz1DU[]={  // 
	{&R0VW13LDU,1,0},	//(R0VW13LDU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{&R0VW23LDU,1,1},	//(R0VW23LDU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0AD21LDU,1,2},	//(R0AD21LDU) Подключить защиту от II УР
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz1DU[]={  // 
	{&A0VT71LZ1,1,0},	//(A0VT71LZ1) АС по температуре в АЗ1
	{&A0VP71LZ1,1,1},	//(A0VP71LZ1) АЗ по АС любого давления для АЗ1
	{&B0VP71LZ1,1,2},	//(B0VP71LZ1) АЗ по АС любого давления для АЗ2
	{&A0EE01LZ1,1,3},	//(A0EE01LZ1) Исправность АКНП1
	{&A0EE04LZ1,1,4},	//(A0EE04LZ1) Исправность АКНП4
	{&A0EE02LZ1,1,5},	//(A0EE02LZ1) Исправность АКНП2
	{&A0EE03LZ1,1,6},	//(A0EE03LZ1) Исправность АКНП3
	{&A0VN71LZ1,1,7},	//(A0VN71LZ1) АЗ по АС мощности  АЗ1
	{&B0VN71LZ1,1,8},	//(B0VN71LZ1) АЗ по АС мощности  АЗ2
	{&R0VP73LZ1,1,9},	//(R0VP73LZ1) ПС давления для РУ
	{&B0VT71LZ1,1,10},	//(B0VT71LZ1) АС по температуре в АЗ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SBz1DU[]={  // 
	{&A0CT01IZ1,8,0},	//(A0CT01IZ1) Температура АЗ1-1
	{&R0VN09RZ1,8,2},	//(R0VN09RZ1) Усредненный период разгона
	{&R0VN11RZ1,8,4},	//(R0VN11RZ1) Средняя мощность по БАЗ1
	{&B0CT01IZ1,8,6},	//(B0CT01IZ1) Температура АЗ2-1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SBz1DU[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MBz1S[]={  // 
	{&R0EE01LZ1,1,0},	//(R0EE01LZ1) Питание  АКНП1  отключить
	{&R0EE02LZ1,1,1},	//(R0EE02LZ1) Питание  АКНП  отключить
	{&R0EE03LZ1,1,2},	//(R0EE03LZ1) Питание  АКНП3  отключить
	{&R0EE04LZ1,1,3},	//(R0EE04LZ1) Питание  АКНП4  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz1S[]={  // 
	{&R0VN61LS1,1,0},	//(R0VN61LS1) ПС по мощности канал1
	{&R0VN65LS1,1,1},	//(R0VN65LS1) ПС по периоду разгона канал1
	{&R0VN61LS2,1,2},	//(R0VN61LS2) ПС по мощности канал 2
	{&R0VN65LS2,1,3},	//(R0VN65LS2) ПС по периоду разгона канал 2
	{&R0VN61LS3,1,4},	//(R0VN61LS3) ПС по мощности канал 3
	{&R0VN65LS3,1,5},	//(R0VN65LS3) ПС по периоду разгона канал 3
	{&R0VN61LS4,1,6},	//(R0VN61LS4) ПС по мощности канал 4
	{&R0VN65LS4,1,7},	//(R0VN65LS4) ПС по периоду разгона канал 4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz1S[]={  // 
	{&R0VN02RS1,8,0},	//(R0VN02RS1) Уровень мощности канал1
	{&R0VN01RS1,8,2},	//(R0VN01RS1) Период разгона канал1
	{&R0VN02RS2,8,4},	//(R0VN02RS2) Уровень мощности канал 2
	{&R0VN01RS2,8,6},	//(R0VN01RS2) Период разгона канал 2
	{&R0VN02RS3,8,8},	//(R0VN02RS3) Уровень мощности канал 3
	{&R0VN01RS3,8,10},	//(R0VN01RS3) Период разгона канал 3
	{&R0VN02RS4,8,12},	//(R0VN02RS4) Уровень мощности канал 4
	{&R0VN01RS4,8,14},	//(R0VN01RS4) Период разгона канал 4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MBz1S[]={  // 
	{NULL,0,0},
};
#pragma pop
static char MBz1S_ip1[]={"192.168.10.60\0"};
static char MBz1S_ip2[]={"192.168.10.60\0"};
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,502,&coil_Baz1[0],&di_Baz1[0],&ir_Baz1[0],&hr_Baz1[0],NULL,NULL,NULL,0},	 //Общий слэйв
	{0,503,&coil_SBz1DU[0],&di_SBz1DU[0],&ir_SBz1DU[0],&hr_SBz1DU[0],NULL,NULL,NULL,0},	 //Слэйв для DU
	{1,503,&coil_MBz1S[0],&di_MBz1S[0],&ir_MBz1S[0],&hr_MBz1S[0],NULL,MBz1S_ip1,MBz1S_ip2,100},	 //Мастер Баз1 в SCM

	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},};
#pragma pop
#include <fp8/drivers/vas84r.h>
static char buf_VAS84[26];	//VAS84
static vas84r_inipar ini_VAS84={172,255,1,8,0xff,0,16,};
#pragma pack(push,1)
static table_drv table_VAS84={0,0,&ini_VAS84,buf_VAS84,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VAS84[]={
	{&A0IT01IZ1,3,0},
	{&B0IT01IZ1,3,6},
	{&A2IP01IZ1,3,3},
	{&B2IP01IZ1,3,9},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS321[64];	//VDS32
static vds32r_inipar ini_VDS321={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS321={0,0,&ini_VDS321,buf_VDS321,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS321[]={
	{&R0AD04LZ1,1,14},
	{&B2IS12LDU,1,20},
	{&A2IS12LDU,1,18},
	{&R0VN71LZ1,1,0},
	{&R0VN75LZ1,1,2},
	{&A3IS11LDU,1,8},
	{&A3IS22LDU,1,10},
	{&R0AD03LZ1,1,12},
	{&A0VN71LS1,1,6},
	{&A0EE01LS1,1,4},
	{&R0AD05LZ1,1,16},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS322[64];	//VDS32
static vds32r_inipar ini_VDS322={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS322={0,0,&ini_VDS322,buf_VDS322,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS322[]={
	{&B3IS11LDU,1,8},
	{&A0VN71LS2,1,6},
	{&A0EE01LS2,1,4},
	{&R0VN76LZ1,1,2},
	{&R0VN72LZ1,1,0},
	{&B3IS22LDU,1,22},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS323[64];	//VDS32
static vds32r_inipar ini_VDS323={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS323={0,0,&ini_VDS323,buf_VDS323,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS323[]={
	{&R0VN78LZ1,1,2},
	{&R0VN74LZ1,1,0},
	{&R6IS68LZZ,1,12},
	{&R6IS67LZZ,1,10},
	{&R6IS66LZZ,1,8},
	{&A0EE01LS4,1,4},
	{&A0VN71LS4,1,6},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS324[64];	//VDS32
static vds32r_inipar ini_VDS324={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS324={0,0,&ini_VDS324,buf_VDS324,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS324[]={
	{&R0VN73LZ1,1,0},
	{&R0VN77LZ1,1,2},
	{&A0EE01LS3,1,4},
	{&A0VN71LS3,1,6},
	{&R7II72LZ1,1,10},
	{&R7II71LZ1,1,8},
	{&R7II73LZ1,1,12},
	{&A0VP81LZZ,1,16},
	{&B0VP81LZZ,1,22},
	{&A1VP81LZZ,1,18},
	{&B1VP81LZZ,1,24},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS16[38];	//FDS16
static fds16r_inipar ini_FDS16={0x04,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS16={0,0,&ini_FDS16,buf_FDS16,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS16[]={
	{&A3VZ13LZ1,1,0},
	{&A3VZ15LZ1,1,2},
	{&A1VN71LZ1,1,6},
	{&R0AD14LZ1,1,4},
	{&R0VZ71LZ1,1,8},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc6,0x04,7,26,def_buf_VAS84,&table_VAS84}, //VAS84
	{0xc2,0x05,15,64,def_buf_VDS321,&table_VDS321}, //VDS32
	{0xc2,0x06,15,64,def_buf_VDS322,&table_VDS322}, //VDS32
	{0xc2,0x07,15,64,def_buf_VDS323,&table_VDS323}, //VDS32
	{0xc2,0x08,15,64,def_buf_VDS324,&table_VDS324}, //VDS32
	{0x04,0x0a,20,38,def_buf_FDS16,&table_FDS16}, //FDS16
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
	setAsFloat(144,600);
	setAsFloat(145,0);
	setAsFloat(146,1.6);
	setAsFloat(147,0);
	setAsFloat(148,150);
	setAsFloat(149,200);
	setAsFloat(150,90);
	setAsFloat(151,100);
	setAsFloat(152,0.1);
	setAsFloat(153,0.13);
	setAsFloat(154,0.16);
	setAsFloat(155,0.17);
	setAsFloat(156,0.31);
	setAsFloat(157,0.2);
	setAsFloat(158,0.19);
	setAsFloat(159,0.28);
	setAsFloat(160,15);
	setAsFloat(161,10);
	setAsFloat(162,0.180);
	setAsFloat(163,0.020);
	setAsFloat(164,0.045);
}
void Scheme(void)
{
}
#endif
