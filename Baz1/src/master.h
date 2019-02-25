#ifndef BAZ1_H
#define BAZ1_H
// Подсистема Baz1:Baz1
static char SimulOn=1;
static short CodeSub=4;
static char SimulIP[]="192.168.10.1\0";
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
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{144,"fEM_R0UT02RZZ\0"}, 
{145,"fEM_R0UT01RZZ\0"}, 
{146,"fEM_A2UP03RZZ\0"}, 
{147,"fEM_A2UP04RZZ\0"}, 
{148,"fEM_R0UT72RZZ\0"}, 
{149,"fEM_R0UT71RZZ\0"}, 
{150,"fEM_R0UT62RZZ\0"}, 
{151,"fEM_R0UT61RZZ\0"}, 
{152,"fEM_A2UP41RZZ\0"}, 
{153,"fEM_A2UP42RZZ\0"}, 
{154,"fEM_A2UP51RZZ\0"}, 
{155,"fEM_A2UP81RZZ\0"}, 
{156,"fEM_A2UP84RZZ\0"}, 
{157,"fEM_A2UP82RZZ\0"}, 
{158,"fEM_A2UP52RZZ\0"}, 
{159,"fEM_A2UP83RZZ\0"}, 
{160,"fEM_R0UR01RZZ\0"}, 
{161,"fEM_R0UR04RZZ\0"}, 
{162,"fEM_A1UL12RZZ\0"}, 
{163,"fEM_A1UL11RZZ\0"}, 
{164,"fEM_R7UI73RZZ\0"}, 
{0,NULL}
};
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
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MBz1S[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MBz1S[]={  // 
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
	{0,5002,&coil_Baz1[0],&di_Baz1[0],&ir_Baz1[0],&hr_Baz1[0],NULL,NULL,NULL,0},	 //Общий слэйв
	{0,5003,&coil_SBz1DU[0],&di_SBz1DU[0],&ir_SBz1DU[0],&hr_SBz1DU[0],NULL,NULL,NULL,0},	 //Слэйв для DU
	{1,5003,&coil_MBz1S[0],&di_MBz1S[0],&ir_MBz1S[0],&hr_MBz1S[0],NULL,MBz1S_ip1,MBz1S_ip2,100},	 //Мастер Баз1 в SCM

	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},};
#pragma pop
#include <fp8/drivers/vas84r.h>
static char buf_VAS84[28];	//VAS84
static vas84r_inipar ini_VAS84={0xc6,255,1,8,0xff,0,16,};
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
static char buf_VDS321[66];	//VDS32
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
static char buf_VDS322[66];	//VDS32
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
static char buf_VDS323[66];	//VDS32
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
static char buf_VDS324[66];	//VDS32
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
static char buf_FDS16[40];	//FDS16
static fds16r_inipar ini_FDS16={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
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
	{0xc6,0x04,7,28,def_buf_VAS84,&table_VAS84}, //VAS84
	{0xc2,0x05,15,66,def_buf_VDS321,&table_VDS321}, //VDS32
	{0xc2,0x06,15,66,def_buf_VDS322,&table_VDS322}, //VDS32
	{0xc2,0x07,15,66,def_buf_VDS323,&table_VDS323}, //VDS32
	{0xc2,0x08,15,66,def_buf_VDS324,&table_VDS324}, //VDS32
	{0x96,0x0a,20,40,def_buf_FDS16,&table_FDS16}, //FDS16
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
uspaint8 InternalBuf[99];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssbool lRM_0_ = {0,0}; /* A-Граница участка насыщения А */ 
ssbool lRM_1_ = {1,0}; /* B-Граница участка насыщения В */ 
sslong dRM_0_ = {0,0}; /* lx вход лонг */ 
sschar bRM_0_ = {0,0}; /* cx вход байтовый */ 
ssint iRM_0_ = {0,0}; /* ix вход целый */ 
ssint iRM_3_ = {3,0}; /* N-число входов */ 
ssint iRM_4_ = {4,0}; /* n - размерность массива */ 
ssint iRM_6_ = {6,0}; /* N-число входов */ 
ssint iRM_17_ = {17,0}; /* n - размерность массива входных сигналов */ 
ssint iRM_819_ = {819,0}; /* a */ 
ssint iRM_4095_ = {4095,0}; /* b */ 
ssfloat fRM_0_00001 = {0.00001,0}; /* X2 */ 
ssint iRM_200_ = {200,0}; /* tz - ширина импульса, 10-ки мс */ 
ssfloat fRM_0_2 = {0.2,0}; /* tz - время задержки сек */ 
ssfloat fRM_1_0 = {1.0,0}; /* tz - время задержки сек */ 
ssint iRM_7_ = {7,0}; /* n - N-размерность массива x */ 
ssfloat fRM_0_002 = {0.002,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_005 = {0.005,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_007 = {0.007,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_01 = {0.01,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_015 = {0.015,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_02 = {0.02,0}; /* x - массив входных параметров */ 
ssfloat fRM_1_7 = {1.7,0}; /* x - массив входных параметров */ 

uspaint8 SpaEEPROMBuf[105];

/* Определение переменных */
ssbool var1;
ssbool var2;
ssbool var3;
ssbool var4;
ssbool var5;
ssbool var6;
ssbool var7;
ssbool var8;
ssbool var9;
ssbool var10;
ssbool var11;
ssbool var12;
ssbool var13;
ssbool var14;
ssbool var15;
ssbool var16;
ssbool var17;
ssbool var18;
ssbool var19;
ssbool var20;
ssbool var21;
ssbool var22;
ssbool var23;
ssbool var24;
ssbool var25;
ssbool var26;
ssbool var27;
ssbool var28;
ssbool var29;
ssbool var30;
ssbool var31;
ssbool var32;
ssbool var33;
ssbool var34;
ssbool var35;
ssbool var36;
ssbool var37;
ssbool var38;
ssbool var39;
ssbool var40;
ssbool var41;
ssbool var42;
ssbool var43;
ssbool var44;
ssbool var45;
ssbool var46;
ssbool var47;
ssbool var48;
ssbool var49;
ssbool var50;
ssbool var51;
ssbool var52;
ssbool var53;
ssbool var54;
ssbool var55;
ssbool var56;
ssbool var57;
ssbool var58;
ssbool var59;
ssbool var60;
ssbool var61;
ssbool var62;
ssbool var63;
ssbool var64;
ssbool var65;
ssbool var66;
ssbool var67;
ssbool var68;
ssbool var69;
ssbool var70;
ssbool var71;
ssbool var72;
ssbool var73;
ssbool var74;
ssbool var75;
ssbool var76;
ssbool var77;
ssbool var78;
ssbool var79;
ssbool var80;
ssbool var81;
ssbool var82;
ssbool var83;
ssbool var84;
ssbool var85;
ssbool var86;
ssbool var87;
ssbool var88;
ssbool var89;
ssbool var90;
ssbool var91;
ssbool var92;
ssbool var93;
ssbool var94;
ssbool var95;
ssbool var96;
ssbool var97;
ssbool var98;
ssbool var99;
ssbool var100;
ssbool var101;
ssbool var102;
ssbool var103;
ssbool var104;
ssbool var105;
ssbool var106;
ssbool var107;
ssbool var108;
ssbool var109;
ssbool var110;
ssbool var111;
ssbool var112;
ssbool var113;
ssbool var114;
ssbool var115;
ssbool var116;
ssbool var117;
ssbool var118;
ssbool var119;
ssbool var120;
ssbool var121;
ssbool var122;
ssbool var123;
ssbool var124;
ssbool var125;
ssfloat var126;
ssfloat var127;
ssbool var128;
ssfloat var129;
ssfloat var130;
ssbool var131;
ssbool var132;
ssbool var133;
ssbool var134;
ssbool var135;
ssbool var136;
ssfloat var137;
sslong var138;
sslong var139;
ssbool var140;
ssbool var141;
ssbool var142;
ssbool var143;
ssbool var144;
ssbool var145;
ssbool var146;
ssbool var147;
ssbool var148;
ssfloat var149;
ssbool var150;
ssbool var151;
ssfloat var152;
ssbool var153;
ssbool var154;
sschar var155;
ssbool var156;
sschar var157;
ssbool var158;
ssbool var159;
ssbool var160;
ssbool var161;
ssbool var162;
ssbool var163;
ssbool var164;
ssbool var165;
ssbool var166;
ssbool var167;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psfloat  array_m188_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psfloat  array_m330_x_1[4] = {&R0VN02RS1,&R0VN02RS2,&R0VN02RS3,&R0VN02RS4};
psbool  array_m330_diag_1[4] = {&var21,&var22,&var23,&var24};
psbool  array_m310_x_1[17] = {&var83,&var49,&var50,&var78,&var33,&var36,&var154,&var48,&var44,&var43,&var79,&var39,&var37,&var156,&var47,&var46,&var45};
psbool  array_m16_x_1[6] = {&var88,&var79,&var37,&var39,&var97,&var156};
psbool  array_m36_x_1[6] = {&var78,&var33,&var36,&var154,&var86,&var97};
psfloat  array_m2_x_1[4] = {&R0VN01RS1,&R0VN01RS2,&R0VN01RS3,&R0VN01RS4};
psbool  array_m2_diag_1[4] = {&var21,&var22,&var23,&var24};
psbool  array_m3_x_1[3] = {&var107,&var136,&var19};
psbool  array_m12_x_1[3] = {&var106,&var20,&var108};

/* Объявление структур */
_S_ma  S_ma_188_1 = {array_m188_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_and3  S_and3_232_1 = {&var4,&var14,&var13,&var1};
_S_and3  S_and3_229_1 = {&var14,&var4,&var123,&var2};
_S_and3  S_and3_228_1 = {&var13,&var4,&var122,&var3};
_S_noto  S_noto_220_1 = {&R0AD03LZ1,&var4};
_S_and3  S_and3_226_1 = {&var7,&var10,&var9,&var5};
_S_and3  S_and3_223_1 = {&var7,&var9,&var125,&var6};
_S_noto  S_noto_214_1 = {&R0AD05LZ1,&var7};
_S_and3  S_and3_222_1 = {&var7,&var10,&var124,&var8};
_S_and2  S_and2_215_1 = {&var101,&R0VW23LDU,&var9};
_S_and2  S_and2_213_1 = {&var102,&R0VW13LDU,&var10};
_S_and3  S_and3_207_1 = {&var102,&var101,&R0AD05LZ1,&var11};
_S_and3  S_and3_212_1 = {&var100,&var99,&R0AD03LZ1,&var12};
_S_and2  S_and2_216_1 = {&var100,&R0VW13LDU,&var13};
_S_and2  S_and2_217_1 = {&R0VW23LDU,&var99,&var14};
_S_and2  S_and2_251_1 = {&var121,&var31,&var15};
_S_zzfs  S_zzfs_244_1 = {&R0AD14LDU,&fRM_1_0,&var16,&internal1_m244_tx,&internal1_m244_y0};
_S_and2  S_and2_126_1 = {&var159,&var135,&var17};
_S_and2  S_and2_133_1 = {&var158,&var134,&var18};
_S_or2  S_or2_103_1 = {&var165,&var163,&var19};
_S_or2  S_or2_110_1 = {&var160,&var161,&var20};
_S_and2  S_and2_80_1 = {&A0EE05LZ1,&A0EE01LS1,&var21};
_S_and2  S_and2_82_1 = {&A0EE06LZ1,&A0EE01LS2,&var22};
_S_and2  S_and2_84_1 = {&A0EE07LZ1,&A0EE01LS3,&var23};
_S_and2  S_and2_86_1 = {&A0EE08LZ1,&A0EE01LS4,&var24};
_S_and2  S_and2_178_1 = {&var151,&var116,&var25};
_S_and2  S_and2_179_1 = {&var150,&var116,&var26};
_S_or2  S_or2_255_1 = {&var104,&R7II73LZ1,&var27};
_S_or2  S_or2_257_1 = {&R0AD21LDU,&R0AD14LDU,&var28};
_S_and2  S_and2_256_1 = {&var28,&var27,&var29};
_S_or2  S_or2_249_1 = {&R7II71LZ1,&var103,&var30};
_S_or3  S_or3_250_1 = {&var32,&var30,&var29,&var31};
_S_or2  S_or2_243_1 = {&var105,&R7II72LZ1,&var32};
_S_or2  S_or2_230_1 = {&var8,&var5,&var33};
_S_or2  S_or2_199_1 = {&A3IS22LDU,&R0AD05LZ1,&var34};
_S_or2  S_or2_201_1 = {&B3IS22LDU,&R0AD05LZ1,&var35};
_S_or2  S_or2_233_1 = {&var3,&var1,&var36};
_S_or2  S_or2_234_1 = {&var2,&var1,&var37};
_S_or2  S_or2_202_1 = {&var120,&R0AD03LZ1,&var38};
_S_or2  S_or2_231_1 = {&var6,&var5,&var39};
_S_or2  S_or2_204_1 = {&var119,&R0AD03LZ1,&var40};
_S_schl24  S_schl24_332_1 = {&A0VN71LS2,&A0VN71LS1,&A0VN71LS4,&A0VN71LS3,&var41};
_S_and2  S_and2_323_1 = {&var115,&var114,&var42};
_S_and2  S_and2_312_1 = {&var62,&var84,&var43};
_S_and2  S_and2_314_1 = {&var69,&var84,&var44};
_S_and2  S_and2_320_1 = {&var29,&var98,&var45};
_S_and2  S_and2_319_1 = {&var30,&var98,&var46};
_S_and2  S_and2_318_1 = {&var32,&var98,&var47};
_S_and2  S_and2_316_1 = {&var117,&var84,&var48};
_S_and2  S_and2_313_1 = {&var73,&var84,&var49};
_S_and2  S_and2_311_1 = {&var55,&var84,&var50};
_S_and2  S_and2_297_1 = {&var53,&var52,&var51};
_S_or2  S_or2_299_1 = {&R0VN75LZ1,&var148,&var52};
_S_or2  S_or2_300_1 = {&R0VN77LZ1,&var147,&var53};
_S_or2  S_or2_285_1 = {&var51,&var59,&var54};
_S_or2  S_or2_291_1 = {&var56,&var51,&var55};
_S_and2  S_and2_292_1 = {&var143,&var60,&var56};
_S_or2  S_or2_302_1 = {&R0VN78LZ1,&var145,&var57};
_S_or2  S_or2_301_1 = {&R0VN76LZ1,&var146,&var58};
_S_and2  S_and2_298_1 = {&var58,&var57,&var59};
_S_schl24  S_schl24_296_1 = {&var58,&var57,&var53,&var52,&var60};
_S_and2  S_and2_294_1 = {&var84,&var60,&var61};
_S_or2  S_or2_293_1 = {&var59,&var56,&var62};
_S_and2  S_and2_289_1 = {&var62,&var84,&var63};
_S_or2  S_or2_265_1 = {&R0VN72LZ1,&var146,&var64};
_S_and2  S_and2_280_1 = {&var73,&var84,&var65};
_S_and2  S_and2_270_1 = {&var64,&var67,&var66};
_S_or2  S_or2_266_1 = {&R0VN74LZ1,&var145,&var67};
_S_and2  S_and2_281_1 = {&var69,&var84,&var68};
_S_or2  S_or2_278_1 = {&var66,&var72,&var69};
_S_or2  S_or2_284_1 = {&var74,&var66,&var70};
_S_and2  S_and2_272_1 = {&var76,&var84,&var71};
_S_and2  S_and2_277_1 = {&var144,&var76,&var72};
_S_or2  S_or2_276_1 = {&var74,&var72,&var73};
_S_and2  S_and2_267_1 = {&var75,&var77,&var74};
_S_or2  S_or2_264_1 = {&R0VN73LZ1,&var147,&var75};
_S_schl24  S_schl24_269_1 = {&var75,&var77,&var64,&var67,&var76};
_S_or2  S_or2_263_1 = {&R0VN71LZ1,&var148,&var77};
_S_or2  S_or2_152_1 = {&var128,&var166,&var78};
_S_or2  S_or2_150_1 = {&var133,&var131,&var79};
_S_or2  S_or2_336_1 = {&var164,&var162,&var80};
_S_or2  S_or2_35_1 = {&B2IS12LDU,&A2IS12LDU,&var81};
_S_and2  S_and2_288_1 = {&var84,&var55,&var82};
_S_and2  S_and2_317_1 = {&var118,&var84,&var83};
_S_and2  S_and2_22_1 = {&var113,&var109,&var84};
_S_or2  S_or2_26_1 = {&var141,&var140,&var85};
_S_and2  S_and2_31_1 = {&var87,&var84,&var86};
_S_or3  S_or3_30_1 = {&var55,&var73,&var112,&var87};
_S_and2  S_and2_19_1 = {&var84,&var89,&var88};
_S_or3  S_or3_18_1 = {&var69,&var62,&var111,&var89};
_S_and2  S_and2_6_1 = {&var22,&var24,&var90};
_S_or2  S_or2_9_1 = {&var142,&var90,&var91};
_S_or2  S_or2_8_1 = {&var93,&var142,&var92};
_S_and2  S_and2_5_1 = {&var21,&var23,&var93};
_S_and2  S_and2_189_1 = {&R0AD14LDU,&R7II72LZ1,&var94};
_S_and2  S_and2_185_1 = {&R0AD14LDU,&R7II71LZ1,&var95};
_S_and2  S_and2_182_1 = {&R0AD14LDU,&R7II73LZ1,&var96};
_S_zpfs  S_zpfs_252_1 = {&var15,&fEM_R7UI73RZZ,&var97,&internal1_m252_tx,&internal1_m252_y0};
_S_zpfs  S_zpfs_315_1 = {&var42,&fRM_0_2,&var98,&internal1_m315_tx,&internal1_m315_y0};
_S_zpfs  S_zpfs_211_1 = {&var40,&fEM_A1UL11RZZ,&var99,&internal1_m211_tx,&internal1_m211_y0};
_S_zpfs  S_zpfs_210_1 = {&var38,&fEM_A1UL11RZZ,&var100,&internal1_m210_tx,&internal1_m210_y0};
_S_zpfs  S_zpfs_208_1 = {&var35,&fEM_A1UL12RZZ,&var101,&internal1_m208_tx,&internal1_m208_y0};
_S_zpfs  S_zpfs_206_1 = {&var34,&fEM_A1UL12RZZ,&var102,&internal1_m206_tx,&internal1_m206_y0};
_S_noto  S_noto_248_1 = {&R6IS67LZZ,&var103};
_S_noto  S_noto_254_1 = {&R6IS68LZZ,&var104};
_S_noto  S_noto_237_1 = {&R6IS66LZZ,&var105};
_S_noto  S_noto_129_1 = {&B0VP81LZZ,&var106};
_S_noto  S_noto_128_1 = {&A0VP81LZZ,&var107};
_S_noto  S_noto_96_1 = {&B1VP81LZZ,&var108};
_S_noto  S_noto_27_1 = {&var110,&var109};
_S_ovb1  S_ovb1_33_1 = {&var81,&iRM_200_,&var110,&internal1_m33_tx};
_S_noto  S_noto_13_1 = {&var91,&var111};
_S_noto  S_noto_15_1 = {&var92,&var112};
_S_noto  S_noto_25_1 = {&R0EE02LDU,&var113};
_S_noto  S_noto_325_1 = {&R0AD16LDU,&var114};
_S_noto  S_noto_324_1 = {&R0AD04LZ1,&var115};
_S_bol  S_bol_174_1 = {&var152,&fRM_0_00001,&var116};
_S_noto  S_noto_321_1 = {&var91,&var117};
_S_noto  S_noto_322_1 = {&var92,&var118};
_S_noto  S_noto_198_1 = {&B3IS11LDU,&var119};
_S_noto  S_noto_197_1 = {&A3IS11LDU,&var120};
_S_noto  S_noto_245_1 = {&var16,&var121};
_S_noto  S_noto_225_1 = {&R0VW23LDU,&var122};
_S_noto  S_noto_224_1 = {&R0VW13LDU,&var123};
_S_noto  S_noto_219_1 = {&R0VW23LDU,&var124};
_S_noto  S_noto_218_1 = {&R0VW13LDU,&var125};
_S_scalzz  S_scalzz_143_1 = {&B0IT01IZ1,&iRM_819_,&iRM_4095_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var126,&internal1_m143_y0};
_S_scalzz  S_scalzz_141_1 = {&A0IT01IZ1,&iRM_819_,&iRM_4095_,&fEM_R0UT01RZZ,&fEM_R0UT02RZZ,&var127,&internal1_m141_y0};
_S_geterr  S_geterr_145_1 = {&var127,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var128};
_S_scalzz  S_scalzz_93_1 = {&B2IP01IZ1,&iRM_819_,&iRM_4095_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var129,&internal1_m93_y0};
_S_scalzz  S_scalzz_91_1 = {&A2IP01IZ1,&iRM_819_,&iRM_4095_,&fEM_A2UP04RZZ,&fEM_A2UP03RZZ,&var130,&internal1_m91_y0};
_S_drg  S_drg_154_1 = {&var126,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var131,&internal1_m154_y1};
_S_drg  S_drg_165_1 = {&var126,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var132,&internal1_m165_y1};
_S_geterr  S_geterr_147_1 = {&var126,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var133};
_S_noto  S_noto_134_1 = {&var160,&var134};
_S_noto  S_noto_125_1 = {&var165,&var135};
_S_noto  S_noto_95_1 = {&A1VP81LZZ,&var136};
_S_srm  S_srm_330_1 = {array_m330_x_1,array_m330_diag_1,&iRM_4_,&iRM_3_,&var137,&vainSBool};
_S_rsu  S_rsu_308_1 = {&R0MD34LP1,&var139,&var138,&internal1_m308_q0};
_S_orni  S_orni_310_1 = {array_m310_x_1,&iRM_17_,&vainSBool,&var139};
_S_orn  S_orn_16_1 = {array_m16_x_1,&iRM_6_,&var140};
_S_orn  S_orn_36_1 = {array_m36_x_1,&iRM_6_,&var141};
_S_noto  S_noto_7_1 = {&var153,&var142};
_S_noto  S_noto_287_1 = {&var54,&var143};
_S_noto  S_noto_282_1 = {&var70,&var144};
_S_noto  S_noto_271_1 = {&A0EE01LS4,&var145};
_S_noto  S_noto_275_1 = {&A0EE01LS2,&var146};
_S_noto  S_noto_274_1 = {&A0EE01LS3,&var147};
_S_noto  S_noto_268_1 = {&A0EE01LS1,&var148};
_S_react  S_react_170_1 = {&var152,&var149};
_S_bol  S_bol_175_1 = {&fEM_R0UR04RZZ,&var152,&var150};
_S_bol  S_bol_173_1 = {&fEM_R0UR01RZZ,&var152,&var151};
_S_srm  S_srm_2_1 = {array_m2_x_1,array_m2_diag_1,&iRM_4_,&iRM_3_,&var152,&var153};
_S_ornc  S_ornc_3_1 = {array_m3_x_1,&iRM_3_,&var154,&var155};
_S_ornc  S_ornc_12_1 = {array_m12_x_1,&iRM_3_,&var156,&var157};
_S_tprg  S_tprg_130_1 = {&var129,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var158,&internal1_m130_y0};
_S_tprg  S_tprg_123_1 = {&var130,&fEM_A2UP81RZZ,&fEM_A2UP82RZZ,&fEM_A2UP83RZZ,&fEM_A2UP84RZZ,&var159,&internal1_m123_y0};
_S_geterr  S_geterr_102_1 = {&var129,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var160};
_S_drg  S_drg_106_1 = {&var129,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var161,&internal1_m106_y1};
_S_drg  S_drg_116_1 = {&var129,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var162,&internal1_m116_y1};
_S_drg  S_drg_97_1 = {&var130,&lRM_1_,&lRM_0_,&fEM_A2UP41RZZ,&fEM_A2UP42RZZ,&var163,&internal1_m97_y1};
_S_drg  S_drg_104_1 = {&var130,&lRM_1_,&lRM_0_,&fEM_A2UP51RZZ,&fEM_A2UP52RZZ,&var164,&internal1_m104_y1};
_S_geterr  S_geterr_99_1 = {&var130,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var165};
_S_drg  S_drg_153_1 = {&var127,&lRM_0_,&lRM_1_,&fEM_R0UT72RZZ,&fEM_R0UT71RZZ,&var166,&internal1_m153_y1};
_S_drg  S_drg_163_1 = {&var127,&lRM_0_,&lRM_1_,&fEM_R0UT62RZZ,&fEM_R0UT61RZZ,&var167,&internal1_m163_y1};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  noto(&S_noto_268_1);
  noto(&S_noto_274_1);
  noto(&S_noto_275_1);
  noto(&S_noto_271_1);
  noto(&S_noto_95_1);
  scalzz(&S_scalzz_91_1);
  scalzz(&S_scalzz_93_1);
  scalzz(&S_scalzz_141_1);
  scalzz(&S_scalzz_143_1);
  noto(&S_noto_219_1);
  noto(&S_noto_224_1);
  noto(&S_noto_225_1);
  noto(&S_noto_197_1);
  noto(&S_noto_198_1);
  noto(&S_noto_25_1);
  noto(&S_noto_96_1);
  noto(&S_noto_128_1);
  noto(&S_noto_129_1);
  noto(&S_noto_237_1);
  noto(&S_noto_254_1);
  noto(&S_noto_248_1);
  and2(&S_and2_182_1);
  and2(&S_and2_185_1);
  and2(&S_and2_189_1);
  or2(&S_or2_263_1);
  or2(&S_or2_264_1);
  and2(&S_and2_267_1);
  or2(&S_or2_266_1);
  or2(&S_or2_265_1);
  or2(&S_or2_301_1);
  or2(&S_or2_302_1);
  or2(&S_or2_300_1);
  or2(&S_or2_299_1);
  and2(&S_and2_297_1);
  schl24(&S_schl24_332_1);
  or2(&S_or2_204_1);
  or2(&S_or2_202_1);
  or2(&S_or2_201_1);
  or2(&S_or2_199_1);
  or2(&S_or2_243_1);
  or2(&S_or2_249_1);
  or2(&S_or2_257_1);
  or2(&S_or2_255_1);
  and2(&S_and2_86_1);
  and2(&S_and2_84_1);
  and2(&S_and2_82_1);
  and2(&S_and2_80_1);
  zzfs(&S_zzfs_244_1);
  noto(&S_noto_214_1);
  noto(&S_noto_220_1);
  ma(&S_ma_188_1);
  drg(&S_drg_163_1);
  drg(&S_drg_153_1);
  geterr(&S_geterr_99_1);
  drg(&S_drg_104_1);
  drg(&S_drg_97_1);
  drg(&S_drg_116_1);
  drg(&S_drg_106_1);
  geterr(&S_geterr_102_1);
  tprg(&S_tprg_123_1);
  tprg(&S_tprg_130_1);
  srm(&S_srm_2_1);
  bol(&S_bol_173_1);
  bol(&S_bol_175_1);
  react(&S_react_170_1);
  noto(&S_noto_7_1);
  srm(&S_srm_330_1);
  noto(&S_noto_125_1);
  noto(&S_noto_134_1);
  geterr(&S_geterr_147_1);
  drg(&S_drg_165_1);
  drg(&S_drg_154_1);
  geterr(&S_geterr_145_1);
  noto(&S_noto_218_1);
  noto(&S_noto_245_1);
  bol(&S_bol_174_1);
  noto(&S_noto_324_1);
  noto(&S_noto_325_1);
  zpfs(&S_zpfs_206_1);
  zpfs(&S_zpfs_208_1);
  zpfs(&S_zpfs_210_1);
  zpfs(&S_zpfs_211_1);
  and2(&S_and2_5_1);
  or2(&S_or2_8_1);
  and2(&S_and2_6_1);
  or2(&S_or2_35_1);
  or2(&S_or2_336_1);
  or2(&S_or2_150_1);
  or2(&S_or2_152_1);
  schl24(&S_schl24_269_1);
  and2(&S_and2_270_1);
  schl24(&S_schl24_296_1);
  and2(&S_and2_298_1);
  or2(&S_or2_285_1);
  and2(&S_and2_323_1);
  and2(&S_and2_256_1);
  and2(&S_and2_179_1);
  and2(&S_and2_178_1);
  or2(&S_or2_110_1);
  or2(&S_or2_103_1);
  and2(&S_and2_133_1);
  and2(&S_and2_126_1);
  and2(&S_and2_217_1);
  and2(&S_and2_216_1);
  and3(&S_and3_212_1);
  and3(&S_and3_207_1);
  and2(&S_and2_213_1);
  and2(&S_and2_215_1);
  and3(&S_and3_222_1);
  and3(&S_and3_223_1);
  and3(&S_and3_226_1);
  and3(&S_and3_228_1);
  and3(&S_and3_229_1);
  and3(&S_and3_232_1);
  ornc(&S_ornc_12_1);
  ornc(&S_ornc_3_1);
  noto(&S_noto_287_1);
  noto(&S_noto_322_1);
  noto(&S_noto_15_1);
  ovb1(&S_ovb1_33_1);
  noto(&S_noto_27_1);
  zpfs(&S_zpfs_315_1);
  or2(&S_or2_9_1);
  and2(&S_and2_22_1);
  and2(&S_and2_317_1);
  and2(&S_and2_272_1);
  or2(&S_or2_284_1);
  and2(&S_and2_294_1);
  and2(&S_and2_292_1);
  or2(&S_or2_291_1);
  and2(&S_and2_311_1);
  and2(&S_and2_318_1);
  and2(&S_and2_319_1);
  and2(&S_and2_320_1);
  or2(&S_or2_231_1);
  or2(&S_or2_234_1);
  or2(&S_or2_233_1);
  or2(&S_or2_230_1);
  or3(&S_or3_250_1);
  and2(&S_and2_251_1);
  noto(&S_noto_282_1);
  noto(&S_noto_321_1);
  noto(&S_noto_13_1);
  zpfs(&S_zpfs_252_1);
  and2(&S_and2_288_1);
  and2(&S_and2_277_1);
  or2(&S_or2_278_1);
  and2(&S_and2_281_1);
  or2(&S_or2_293_1);
  and2(&S_and2_316_1);
  and2(&S_and2_314_1);
  and2(&S_and2_312_1);
  or3(&S_or3_18_1);
  and2(&S_and2_19_1);
  or2(&S_or2_276_1);
  and2(&S_and2_280_1);
  and2(&S_and2_289_1);
  and2(&S_and2_313_1);
  orn(&S_orn_16_1);
  orni(&S_orni_310_1);
  rsu(&S_rsu_308_1);
  or3(&S_or3_30_1);
  and2(&S_and2_31_1);
  orn(&S_orn_36_1);
  or2(&S_or2_26_1);
  setData(idR0AD16LZ1,&var94);
  setData(idR0AD15LZ1,&var95);
  moveData(idR0EE04LZ1,idR0EE02LDU);
  moveData(idR0EE03LZ1,idR0EE02LDU);
  moveData(idR0EE02LZ1,idR0EE02LDU);
  moveData(idR0EE01LZ1,idR0EE02LDU);
  setData(idR0AD14LZ1,&var96);
  setData(idA3VZ13LZ1,&var12);
  setData(idA3VZ15LZ1,&var11);
  setData(idA1VN71LZ1,&var41);
  setData(idB0VT71LZ1,&var79);
  setData(idB0VT61LZ1,&var132);
  setData(idB0CT01IZ1,&var126);
  setData(idR0VP73LZ1,&var80);
  setData(idR0VN11RZ1,&var137);
  setData(idR0VZ05UZ1,&var138);
  setData(idB0VN81LZ1,&var63);
  setData(idA0VN81LZ1,&var82);
  setData(idB0VN71LZ1,&var68);
  setData(idA0VN71LZ1,&var65);
  setData(idB0VZ71LZ1,&var140);
  setData(idB0EE00LZ1,&var91);
  setData(idA0EE00LZ1,&var92);
  setData(idA0VZ71LZ1,&var141);
  setData(idA0EE03LZ1,&var23);
  setData(idA0EE02LZ1,&var22);
  setData(idA0EE04LZ1,&var24);
  setData(idA0EE01LZ1,&var21);
  setData(idR0VN80LZ1,&var61);
  setData(idR0VN70LZ1,&var71);
  setData(idR0VZ71LZ1,&var85);
  setData(idR0VR02RZ1,&var149);
  setData(idR0VN79LZ1,&var26);
  setData(idR0VN69LZ1,&var25);
  setData(idB3VZ11LZ1,&var39);
  setData(idA3VZ11LZ1,&var33);
  setData(idB3VZ31LZ1,&var37);
  setData(idA3VZ31LZ1,&var36);
  setData(idR0VN09RZ1,&var152);
  moveData(idR0VN68LZ1,idR0VN65LS4);
  moveData(idR0VN67LZ1,idR0VN65LS3);
  moveData(idR0VN66LZ1,idR0VN65LS2);
  moveData(idR0VN65LZ1,idR0VN65LS1);
  moveData(idR0VN64LZ1,idR0VN61LS4);
  moveData(idR0VN63LZ1,idR0VN61LS3);
  moveData(idR0VN62LZ1,idR0VN61LS2);
  moveData(idR0VN61LZ1,idR0VN61LS1);
  moveData(idR0VN08RZ1,idR0VN01RS4);
  moveData(idR0VN07RZ1,idR0VN01RS3);
  moveData(idR0VN06RZ1,idR0VN01RS2);
  moveData(idR0VN05RZ1,idR0VN01RS1);
  moveData(idR0VN04RZ1,idR0VN02RS4);
  moveData(idR0VN03RZ1,idR0VN02RS3);
  moveData(idR0VN02RZ1,idR0VN02RS2);
  moveData(idR0VN01RZ1,idR0VN02RS1);
  setData(idB0VP71LZ1,&var156);
  setData(idA0VP71LZ1,&var154);
  setData(idA0EP02IZ1,&var155);
  setData(idB0EP02IZ1,&var157);
  setData(idR0ET02LZ1,&var133);
  setData(idB0VP41LZ1,&var106);
  setData(idA0VP41LZ1,&var107);
  setData(idR0ET01LZ1,&var128);
  setData(idA2VP81LZ1,&var17);
  setData(idB2VP81LZ1,&var18);
  setData(idB2VP51LZ1,&var162);
  setData(idB2CP01RZ1,&var129);
  setData(idB2VP41LZ1,&var20);
  setData(idA2VP51LZ1,&var164);
  setData(idA2CP01RZ1,&var130);
  setData(idA2VP41LZ1,&var19);
  setData(idB1VP41LZ1,&var108);
  setData(idA1VP41LZ1,&var136);
  setData(idA0VT71LZ1,&var78);
  setData(idA0VT61LZ1,&var167);
  setData(idA0CT01IZ1,&var127);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}

#endif
