#ifndef DU_H
#define DU_H
// Подсистема DU:DU
static char SimulOn=0;
static short CodeSub=2;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt, taktScheme=0, taktSS=0;
#define SIZE_BUFFER 12297
static char BUFFER[12297];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.50\0", 5432, "192.168.10.150\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define B2AB15LDU	 BUFFER[0]	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idB2AB15LDU	 1	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define R0AD21LDU	 BUFFER[2]	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define idR0AD21LDU	 2	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define R0VX02LDU	 BUFFER[4]	//( - , DU) Импульс разрешен
#define idR0VX02LDU	 3	//( - , DU) Импульс разрешен
#define R0EE03LDU	 BUFFER[6]	//( - , DU) ВПИС ИС
#define idR0EE03LDU	 4	//( - , DU) ВПИС ИС
#define R0AB07LDU	 BUFFER[8]	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define idR0AB07LDU	 5	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define C2MD31LP1	 BUFFER[10]	//( - , DU) Кнопка СБРОС РБ
#define idC2MD31LP1	 6	//( - , DU) Кнопка СБРОС РБ
#define B6VS01IDU	 BUFFER[12]	//( - , DU) Готовность к управлению БЗ2
#define idB6VS01IDU	 7	//( - , DU) Готовность к управлению БЗ2
#define R2AD20LDU	 BUFFER[15]	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	 8	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define R2AD10LDU	 BUFFER[17]	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define idR2AD10LDU	 9	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define B8VS01IDU	 BUFFER[19]	//( - , DU) Готовность к управлению АЗ2
#define idB8VS01IDU	 10	//( - , DU) Готовность к управлению АЗ2
#define A8VS01IDU	 BUFFER[22]	//( - , DU) Готовность к управлению ДС2
#define idA8VS01IDU	 11	//( - , DU) Готовность к управлению ДС2
#define A1IE03LDU	 BUFFER[25]	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 12	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[27]	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 13	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define A2IE03LDU	 BUFFER[29]	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define idA2IE03LDU	 14	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define A2IE04LDU	 BUFFER[31]	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define idA2IE04LDU	 15	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define A3IE03LDU	 BUFFER[33]	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define idA3IE03LDU	 16	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define A3IE04LDU	 BUFFER[35]	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define idA3IE04LDU	 17	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define B1IE03LDU	 BUFFER[37]	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 18	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define B1IE04LDU	 BUFFER[39]	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 19	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define B2IE03LDU	 BUFFER[41]	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define idB2IE03LDU	 20	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define B2IE04LDU	 BUFFER[43]	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define idB2IE04LDU	 21	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define B3IE03LDU	 BUFFER[45]	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define idB3IE03LDU	 22	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define B3IE04LDU	 BUFFER[47]	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define idB3IE04LDU	 23	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define R0AD14LZ1	 BUFFER[49]	//(vds32:02 - K20VDSR, DU) Имитация срабатывания АЗ от II УР
#define idR0AD14LZ1	 24	//(vds32:02 - K20VDSR, DU) Имитация срабатывания АЗ от II УР
#define R0AD14LZ2	 BUFFER[51]	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define idR0AD14LZ2	 25	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define A3VZ13LZ2	 BUFFER[53]	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ2	 26	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ13LZ1	 BUFFER[55]	//(vds32:02 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ1	 27	//(vds32:02 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ15LZ1	 BUFFER[57]	//(vds32:02 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ1	 28	//(vds32:02 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define A3VZ15LZ2	 BUFFER[59]	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ2	 29	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define B2IS33LDU	 BUFFER[61]	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define idB2IS33LDU	 30	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define B3IS31LDU	 BUFFER[63]	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define idB3IS31LDU	 31	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define B3IS33LDU	 BUFFER[65]	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define idB3IS33LDU	 32	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define B3IS35LDU	 BUFFER[67]	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define idB3IS35LDU	 33	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define B4IS10LDU	 BUFFER[69]	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define idB4IS10LDU	 34	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define R6IS31LDU	 BUFFER[71]	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define idR6IS31LDU	 35	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define R6IS32LDU	 BUFFER[73]	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define idR6IS32LDU	 36	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define R6IS42LDU	 BUFFER[75]	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define idR6IS42LDU	 37	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define R6IS41LDU	 BUFFER[77]	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define idR6IS41LDU	 38	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define R6IS52LDU	 BUFFER[79]	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define idR6IS52LDU	 39	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define R6IS51LDU	 BUFFER[81]	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define idR6IS51LDU	 40	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define R3IS11LDU	 BUFFER[83]	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	 41	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define R3IS21LDU	 BUFFER[85]	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define idR3IS21LDU	 42	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define R0AB03LDU	 BUFFER[87]	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define idR0AB03LDU	 43	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define R0AB05LDU	 BUFFER[89]	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define idR0AB05LDU	 44	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define R0VN11RZ1	 BUFFER[91]	//( - , MDuBz1) Средняя мощность по BAZ1
#define idR0VN11RZ1	 45	//( - , MDuBz1) Средняя мощность по BAZ1
#define R0VN11RZ2	 BUFFER[96]	//( - , MDuBz2) Средняя мощность по BAZ2
#define idR0VN11RZ2	 46	//( - , MDuBz2) Средняя мощность по BAZ2
#define A2AB15LDU	 BUFFER[101]	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idA2AB15LDU	 47	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define R0AB14LDU	 BUFFER[103]	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define idR0AB14LDU	 48	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define R0AB15LDU	 BUFFER[105]	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define idR0AB15LDU	 49	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define A3IS12LDU	 BUFFER[107]	//( - , DU) Приход на ВУ штока ИС1
#define idA3IS12LDU	 50	//( - , DU) Приход на ВУ штока ИС1
#define B3IS12LDU	 BUFFER[109]	//( - , DU) Приход на ВУ штока ИС2
#define idB3IS12LDU	 51	//( - , DU) Приход на ВУ штока ИС2
#define A1ZAV	 BUFFER[111]	//( - , DU) 
#define idA1ZAV	 52	//( - , DU) 
#define A3ZAV	 BUFFER[113]	//( - , DU) 
#define idA3ZAV	 53	//( - , DU) 
#define B1AB19LDU	 BUFFER[115]	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define idB1AB19LDU	 54	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define R0AB16LDU	 BUFFER[117]	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define idR0AB16LDU	 55	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define R0AB17LDU	 BUFFER[119]	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define idR0AB17LDU	 56	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define R0AB18LDU	 BUFFER[121]	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define idR0AB18LDU	 57	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define A0CT01IZ1	 BUFFER[123]	//( - , MDuBz1) Температура АЗ1-1
#define idA0CT01IZ1	 58	//( - , MDuBz1) Температура АЗ1-1
#define B0CT01IZ1	 BUFFER[128]	//( - , MDuBz1) Температура АЗ2-1
#define idB0CT01IZ1	 59	//( - , MDuBz1) Температура АЗ2-1
#define A0CT01IZ2	 BUFFER[133]	//( - , MDuBz2) Температура АЗ1-2
#define idA0CT01IZ2	 60	//( - , MDuBz2) Температура АЗ1-2
#define B0CT01IZ2	 BUFFER[138]	//( - , MDuBz2) Температура АЗ2-2
#define idB0CT01IZ2	 61	//( - , MDuBz2) Температура АЗ2-2
#define A3MC01RDU	 BUFFER[143]	//( - , DU) Заданная координата положения ИС от регулятора мм
#define idA3MC01RDU	 62	//( - , DU) Заданная координата положения ИС от регулятора мм
#define A3MC02RDU	 BUFFER[148]	//( - , DU) Температурная корректировка координаты ИМ
#define idA3MC02RDU	 63	//( - , DU) Температурная корректировка координаты ИМ
#define R0CN91LDU	 BUFFER[153]	//( - , DU) Рассчётная реактивность от регулятора
#define idR0CN91LDU	 64	//( - , DU) Рассчётная реактивность от регулятора
#define A3MC03RDU	 BUFFER[158]	//( - , DU) Координата положения ИМ 0-й реактивности
#define idA3MC03RDU	 65	//( - , DU) Координата положения ИМ 0-й реактивности
#define A3AB15LDU	 BUFFER[163]	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define idA3AB15LDU	 66	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define R0AB20LDU	 BUFFER[165]	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define idR0AB20LDU	 67	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define R0CN92LDU	 BUFFER[167]	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define idR0CN92LDU	 68	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define R0VN11RDU	 BUFFER[172]	//( - , DU) Текущая мощность РУ
#define idR0VN11RDU	 69	//( - , DU) Текущая мощность РУ
#define R0VN12RDU	 BUFFER[177]	//( - , DU) Заданная мощность РУ
#define idR0VN12RDU	 70	//( - , DU) Заданная мощность РУ
#define R0VS11LDU	 BUFFER[182]	//( - , DU) РУ не готова к работе
#define idR0VS11LDU	 71	//( - , DU) РУ не готова к работе
#define B6AB05LDU	 BUFFER[184]	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define idB6AB05LDU	 72	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define R0AB08LDU	 BUFFER[186]	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define idR0AB08LDU	 73	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define A1MC01RP1	 BUFFER[188]	//( - , DU) Заданная координата положения ББ1 мм
#define idA1MC01RP1	 74	//( - , DU) Заданная координата положения ББ1 мм
#define B1MC01RP1	 BUFFER[193]	//( - , DU) Заданная координата положения ББ2  мм
#define idB1MC01RP1	 75	//( - , DU) Заданная координата положения ББ2  мм
#define A3MC01RP1	 BUFFER[198]	//( - , DU) Заданная координата положения ИС1 мм
#define idA3MC01RP1	 76	//( - , DU) Заданная координата положения ИС1 мм
#define B3MC01RP1	 BUFFER[203]	//( - , DU) Заданная координата положения ИС2 мм
#define idB3MC01RP1	 77	//( - , DU) Заданная координата положения ИС2 мм
#define B8MC01RP2	 BUFFER[208]	//( - , DU) Заданная координата АЗ2 мм
#define idB8MC01RP2	 78	//( - , DU) Заданная координата АЗ2 мм
#define R0AB09LDU	 BUFFER[213]	//( - , DU) Ошибка в заданной координате ББ1
#define idR0AB09LDU	 79	//( - , DU) Ошибка в заданной координате ББ1
#define R0AB10LDU	 BUFFER[215]	//( - , DU) Ошибка в заданной координате ББ2
#define idR0AB10LDU	 80	//( - , DU) Ошибка в заданной координате ББ2
#define R0AB11LDU	 BUFFER[217]	//( - , DU) Ошибка в заданной координате  ИС1
#define idR0AB11LDU	 81	//( - , DU) Ошибка в заданной координате  ИС1
#define R0AB12LDU	 BUFFER[219]	//( - , DU) Ошибка в заданной координате  ИС2
#define idR0AB12LDU	 82	//( - , DU) Ошибка в заданной координате  ИС2
#define R0AB13LDU	 BUFFER[221]	//( - , DU) Ошибка в заданной координате  АЗ2
#define idR0AB13LDU	 83	//( - , DU) Ошибка в заданной координате  АЗ2
#define A4ZAV	 BUFFER[223]	//( - , DU) 
#define idA4ZAV	 84	//( - , DU) 
#define A6ZAV	 BUFFER[225]	//( - , DU) 
#define idA6ZAV	 85	//( - , DU) 
#define R2ZAV	 BUFFER[227]	//( - , DU) 
#define idR2ZAV	 86	//( - , DU) 
#define A5ZAV	 BUFFER[229]	//( - , DU) 
#define idA5ZAV	 87	//( - , DU) 
#define B8ZAV	 BUFFER[231]	//( - , DU) 
#define idB8ZAV	 88	//( - , DU) 
#define A2ZAV	 BUFFER[233]	//( - , DU) Завершение РБ1,2
#define idA2ZAV	 89	//( - , DU) Завершение РБ1,2
#define A8ZAV	 BUFFER[235]	//( - , DU) 
#define idA8ZAV	 90	//( - , DU) 
#define A9ZAV	 BUFFER[237]	//( - , DU) Завершение НИ ДС1(2)
#define idA9ZAV	 91	//( - , DU) Завершение НИ ДС1(2)
#define R4ABL	 BUFFER[239]	//( - , DU) Блокировка тележки -
#define idR4ABL	 92	//( - , DU) Блокировка тележки -
#define A4UP	 BUFFER[241]	//( - , DU) 
#define idA4UP	 93	//( - , DU) 
#define A4DW	 BUFFER[243]	//( - , DU) 
#define idA4DW	 94	//( - , DU) 
#define A3IS22LDU	 BUFFER[245]	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define idA3IS22LDU	 95	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define B3IS22LDU	 BUFFER[247]	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define idB3IS22LDU	 96	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define A2AD33LDU	 BUFFER[249]	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define idA2AD33LDU	 97	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define B2AD33LDU	 BUFFER[251]	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define idB2AD33LDU	 98	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define A3AD33LDU	 BUFFER[253]	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define idA3AD33LDU	 99	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define A3AD34LDU	 BUFFER[255]	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define idA3AD34LDU	 100	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define A3AD31LDU	 BUFFER[257]	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define idA3AD31LDU	 101	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define B3AD34LDU	 BUFFER[259]	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define idB3AD34LDU	 102	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define B3AD31LDU	 BUFFER[261]	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define idB3AD31LDU	 103	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define A2IS11LDU	 BUFFER[263]	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define idA2IS11LDU	 104	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define B2IS11LDU	 BUFFER[265]	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define idB2IS11LDU	 105	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define A3MD12LP1	 BUFFER[267]	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define idA3MD12LP1	 106	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define A3MD11LP1	 BUFFER[269]	//( - , DU) Кнопка ПУСК ИС1
#define idA3MD11LP1	 107	//( - , DU) Кнопка ПУСК ИС1
#define R0MD33LP1	 BUFFER[271]	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define idR0MD33LP1	 108	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define A1MD12LP1	 BUFFER[273]	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define idA1MD12LP1	 109	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define A1MD11LP1	 BUFFER[275]	//( - , DU) Кнопка ПУСК ББ1
#define idA1MD11LP1	 110	//( - , DU) Кнопка ПУСК ББ1
#define R0MW14IP2	 BUFFER[277]	//( - , DU) Переключатель ОБДУВ
#define idR0MW14IP2	 111	//( - , DU) Переключатель ОБДУВ
#define A7AP31LDU	 BUFFER[280]	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define idA7AP31LDU	 112	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define B7AP31LDU	 BUFFER[282]	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define idB7AP31LDU	 113	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define R0MW12IP2	 BUFFER[284]	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define idR0MW12IP2	 114	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define R0MW17LP1	 BUFFER[287]	//( - , DU) Переключатель АВТ/Р
#define idR0MW17LP1	 115	//( - , DU) Переключатель АВТ/Р
#define R0VW13LDU	 BUFFER[289]	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 116	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	 BUFFER[291]	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 117	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define A4VS12LDU	 BUFFER[293]	//( - , DU) Движение НИ1 в сторону ВУ
#define idA4VS12LDU	 118	//( - , DU) Движение НИ1 в сторону ВУ
#define A4VS22LDU	 BUFFER[295]	//( - , DU) Движение НИ1 в сторону НУ
#define idA4VS22LDU	 119	//( - , DU) Движение НИ1 в сторону НУ
#define B4VS01IDU	 BUFFER[297]	//( - , DU) Готовность к управлению НИ2
#define idB4VS01IDU	 120	//( - , DU) Готовность к управлению НИ2
#define B4VS12LDU	 BUFFER[300]	//( - , DU) Движение НИ2 в сторону ВУ
#define idB4VS12LDU	 121	//( - , DU) Движение НИ2 в сторону ВУ
#define B4VS22LDU	 BUFFER[302]	//( - , DU) Движение НИ2 в сторону НУ
#define idB4VS22LDU	 122	//( - , DU) Движение НИ2 в сторону НУ
#define A5VS01IDU	 BUFFER[304]	//( - , DU) Готовность к управлению НЛ1
#define idA5VS01IDU	 123	//( - , DU) Готовность к управлению НЛ1
#define B5VS01IDU	 BUFFER[307]	//( - , DU) Готовность к управлению НЛ2
#define idB5VS01IDU	 124	//( - , DU) Готовность к управлению НЛ2
#define A6VS01IDU	 BUFFER[310]	//( - , DU) Готовность к управлению БЗ1
#define idA6VS01IDU	 125	//( - , DU) Готовность к управлению БЗ1
#define R4VS01IDU	 BUFFER[313]	//( - , DU) Готовность к управлению тележкой реактора
#define idR4VS01IDU	 126	//( - , DU) Готовность к управлению тележкой реактора
#define R2VS01IDU	 BUFFER[316]	//( - , DU) Готовность к управлению МДЗ2
#define idR2VS01IDU	 127	//( - , DU) Готовность к управлению МДЗ2
#define R1VS01IDU	 BUFFER[319]	//( - , DU) Готовность к управлению МДЗ1
#define idR1VS01IDU	 128	//( - , DU) Готовность к управлению МДЗ1
#define A9IS11LDU	 BUFFER[322]	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 129	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define A9IS21LDU	 BUFFER[324]	//(vds32:02 - K24VDSR, DU) Приход на НУ НИ ДС1
#define idA9IS21LDU	 130	//(vds32:02 - K24VDSR, DU) Приход на НУ НИ ДС1
#define B9IS11LDU	 BUFFER[326]	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 131	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define B9IS21LDU	 BUFFER[328]	//(vds32:02 - K26VDSR, DU) Приход на НУ НИ ДС2
#define idB9IS21LDU	 132	//(vds32:02 - K26VDSR, DU) Приход на НУ НИ ДС2
#define B9AD10LDU	 BUFFER[330]	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define idB9AD10LDU	 133	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define A9AD10LDU	 BUFFER[332]	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define idA9AD10LDU	 134	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define A9AZ03LDU	 BUFFER[334]	//( - , DU) Несанкционированное перемещение НИ ДС1
#define idA9AZ03LDU	 135	//( - , DU) Несанкционированное перемещение НИ ДС1
#define A9AB01LDU	 BUFFER[336]	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define idA9AB01LDU	 136	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define A9AB02LDU	 BUFFER[338]	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define idA9AB02LDU	 137	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define B9AZ03LDU	 BUFFER[340]	//( - , DU) Несанкционированное перемещение НИ ДС2
#define idB9AZ03LDU	 138	//( - , DU) Несанкционированное перемещение НИ ДС2
#define B9AB01LDU	 BUFFER[342]	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define idB9AB01LDU	 139	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define B9AB02LDU	 BUFFER[344]	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define idB9AB02LDU	 140	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define R0AB01LDU	 BUFFER[346]	//( - , DU) Режим проверки разрешён
#define idR0AB01LDU	 141	//( - , DU) Режим проверки разрешён
#define A0VT71LZ2	 BUFFER[348]	//( - , MDuBz2) АС по температуре в АЗ1
#define idA0VT71LZ2	 142	//( - , MDuBz2) АС по температуре в АЗ1
#define B0VT71LZ2	 BUFFER[350]	//( - , MDuBz2) АС по температуре в АЗ2
#define idB0VT71LZ2	 143	//( - , MDuBz2) АС по температуре в АЗ2
#define B2VS11LDU	 BUFFER[352]	//( - , DU) Движение РБ2 в сторону ВУ
#define idB2VS11LDU	 144	//( - , DU) Движение РБ2 в сторону ВУ
#define B2VS21LDU	 BUFFER[354]	//( - , DU) Движение РБ2 в сторону НУ
#define idB2VS21LDU	 145	//( - , DU) Движение РБ2 в сторону НУ
#define B2VS01IDU	 BUFFER[356]	//( - , DU) Готовность к управлению РБ2
#define idB2VS01IDU	 146	//( - , DU) Готовность к управлению РБ2
#define A7AS31LDU	 BUFFER[359]	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define idA7AS31LDU	 147	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define B7AS31LDU	 BUFFER[361]	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define idB7AS31LDU	 148	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define A7AZ03LDU	 BUFFER[363]	//( - , DU) Несанкционированное включение обдува АЗ1
#define idA7AZ03LDU	 149	//( - , DU) Несанкционированное включение обдува АЗ1
#define B7AZ03LDU	 BUFFER[365]	//( - , DU) Несанкционированное включение обдува АЗ2
#define idB7AZ03LDU	 150	//( - , DU) Несанкционированное включение обдува АЗ2
#define B3MD12LP1	 BUFFER[367]	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define idB3MD12LP1	 151	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define B3MD11LP1	 BUFFER[369]	//( - , DU) Кнопка ПУСК ИС2
#define idB3MD11LP1	 152	//( - , DU) Кнопка ПУСК ИС2
#define R0VL01RDU	 BUFFER[371]	//( - , DU) Индикация Время задержки
#define idR0VL01RDU	 153	//( - , DU) Индикация Время задержки
#define R0VZ71LZ2	 BUFFER[376]	//(vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
#define idR0VZ71LZ2	 154	//(vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
#define R0VZ71LZ1	 BUFFER[378]	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define idR0VZ71LZ1	 155	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define R0VZ71LDU	 BUFFER[380]	//( - , DU) Обобщенный сигнал АЗ
#define idR0VZ71LDU	 156	//( - , DU) Обобщенный сигнал АЗ
#define A2IS33LDU	 BUFFER[382]	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define idA2IS33LDU	 157	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define A3IS31LDU	 BUFFER[384]	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define idA3IS31LDU	 158	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define A3IS33LDU	 BUFFER[386]	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define idA3IS33LDU	 159	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define A3IS35LDU	 BUFFER[388]	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define idA3IS35LDU	 160	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define A4IS10LDU	 BUFFER[390]	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define idA4IS10LDU	 161	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define A1VN71LZ1	 BUFFER[392]	//(vds32:02 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	 162	//(vds32:02 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define A1VN71LZ2	 BUFFER[394]	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define idA1VN71LZ2	 163	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define A1AB19LDU	 BUFFER[396]	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define idA1AB19LDU	 164	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define R0VX08IDU	 BUFFER[398]	//( - , DU) Индикация Режим
#define idR0VX08IDU	 165	//( - , DU) Индикация Режим
#define R0VX09LDU	 BUFFER[401]	//( - , DU) Индикация регулятор мощности включен/отключен
#define idR0VX09LDU	 166	//( - , DU) Индикация регулятор мощности включен/отключен
#define R0VS17LDU	 BUFFER[403]	//( - , DU) Индикация выбора АВТОМАТ
#define idR0VS17LDU	 167	//( - , DU) Индикация выбора АВТОМАТ
#define A2VS32LDU	 BUFFER[405]	//( - , DU) Индикация  СБРОС РБ1
#define idA2VS32LDU	 168	//( - , DU) Индикация  СБРОС РБ1
#define B2VS32LDU	 BUFFER[407]	//( - , DU) Индикация  СБРОС РБ2
#define idB2VS32LDU	 169	//( - , DU) Индикация  СБРОС РБ2
#define A3VX01LDU	 BUFFER[409]	//( - , DU) Индикация Выстрел ИС1
#define idA3VX01LDU	 170	//( - , DU) Индикация Выстрел ИС1
#define B3VX01LDU	 BUFFER[411]	//( - , DU) Индикация Выстрел ИС2
#define idB3VX01LDU	 171	//( - , DU) Индикация Выстрел ИС2
#define R0VS18LDU	 BUFFER[413]	//( - , DU) Индикация  Проверка схем сброса
#define idR0VS18LDU	 172	//( - , DU) Индикация  Проверка схем сброса
#define B1MD11LP1	 BUFFER[415]	//( - , DU) Кнопка ПУСК ББ2
#define idB1MD11LP1	 173	//( - , DU) Кнопка ПУСК ББ2
#define B1MD12LP1	 BUFFER[417]	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define idB1MD12LP1	 174	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define B2MD11LP1	 BUFFER[419]	//( - , DU) Кнопка ПУСК РБ2
#define idB2MD11LP1	 175	//( - , DU) Кнопка ПУСК РБ2
#define B2MD12LP1	 BUFFER[421]	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define idB2MD12LP1	 176	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define A2MD11LP1	 BUFFER[423]	//( - , DU) Кнопка ПУСК РБ1
#define idA2MD11LP1	 177	//( - , DU) Кнопка ПУСК РБ1
#define A2MD12LP1	 BUFFER[425]	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define idA2MD12LP1	 178	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define B3IS11LDU	 BUFFER[427]	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define idB3IS11LDU	 179	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define A3IS11LDU	 BUFFER[429]	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define idA3IS11LDU	 180	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define R0IS01LDU	 BUFFER[431]	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define idR0IS01LDU	 181	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define R0IS02LDU	 BUFFER[433]	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define idR0IS02LDU	 182	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define R0VP73LZ1	 BUFFER[435]	//( - , MDuBz1) ПС давления для РУ
#define idR0VP73LZ1	 183	//( - , MDuBz1) ПС давления для РУ
#define R0VP73LZ2	 BUFFER[437]	//( - , MDuBz2) ПС давления для РУ
#define idR0VP73LZ2	 184	//( - , MDuBz2) ПС давления для РУ
#define R0VP73LDU	 BUFFER[439]	//( - , DU) ПС давления для РУ
#define idR0VP73LDU	 185	//( - , DU) ПС давления для РУ
#define R0MD34LP1	 BUFFER[441]	//( - , DU) Кнопка КВИТИРОВАТЬ
#define idR0MD34LP1	 186	//( - , DU) Кнопка КВИТИРОВАТЬ
#define A0VT71LZ1	 BUFFER[443]	//( - , MDuBz1) АС по температуре в АЗ1
#define idA0VT71LZ1	 187	//( - , MDuBz1) АС по температуре в АЗ1
#define B0VT71LZ1	 BUFFER[445]	//( - , MDuBz1) АС по температуре в АЗ2
#define idB0VT71LZ1	 188	//( - , MDuBz1) АС по температуре в АЗ2
#define B8MC01LC1	 BUFFER[447]	//( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC1	 189	//( - , DU) Настроить энкодер АЗ2
#define B8MC01LC2	 BUFFER[449]	//( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC2	 190	//( - , DU) Настроить энкодер АЗ2
#define A8MC01LC1	 BUFFER[451]	//( - , DU) Настроить энкодер ДС2
#define idA8MC01LC1	 191	//( - , DU) Настроить энкодер ДС2
#define A8MC01LC2	 BUFFER[453]	//( - , DU) Настроить энкодер ДС2
#define idA8MC01LC2	 192	//( - , DU) Настроить энкодер ДС2
#define A3VP42LDU	 BUFFER[455]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define idA3VP42LDU	 193	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define A3CP02RDU	 BUFFER[457]	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define idA3CP02RDU	 194	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define A3VP52LDU	 BUFFER[462]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define idA3VP52LDU	 195	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define B3VP42LDU	 BUFFER[464]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define idB3VP42LDU	 196	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define B3CP02RDU	 BUFFER[466]	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define idB3CP02RDU	 197	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define B3VP52LDU	 BUFFER[471]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define idB3VP52LDU	 198	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define B3VP82LDU	 BUFFER[473]	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define idB3VP82LDU	 199	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define A3VP82LDU	 BUFFER[475]	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define idA3VP82LDU	 200	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define A3IP02IDU	 BUFFER[477]	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 201	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define B3IP02IDU	 BUFFER[480]	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define idB3IP02IDU	 202	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define A0VE01LDU	 BUFFER[483]	//( - , DU) Напряжение в системы АЗ1 подано
#define idA0VE01LDU	 203	//( - , DU) Напряжение в системы АЗ1 подано
#define B0VE01LDU	 BUFFER[485]	//( - , DU) Напряжение в системы АЗ2 подано
#define idB0VE01LDU	 204	//( - , DU) Напряжение в системы АЗ2 подано
#define A0VP01LDU	 BUFFER[487]	//( - , DU) Давление в системы АЗ1 подано
#define idA0VP01LDU	 205	//( - , DU) Давление в системы АЗ1 подано
#define B0VP01LDU	 BUFFER[489]	//( - , DU) Давление в системы АЗ2 подано
#define idB0VP01LDU	 206	//( - , DU) Давление в системы АЗ2 подано
#define A0EE01LZ1	 BUFFER[491]	//( - , MDuBz1) Исправность АКНП1
#define idA0EE01LZ1	 207	//( - , MDuBz1) Исправность АКНП1
#define A0EE03LZ1	 BUFFER[493]	//( - , MDuBz1) Исправность АКНП3
#define idA0EE03LZ1	 208	//( - , MDuBz1) Исправность АКНП3
#define A0EE02LZ1	 BUFFER[495]	//( - , MDuBz1) Исправность АКНП2
#define idA0EE02LZ1	 209	//( - , MDuBz1) Исправность АКНП2
#define A0EE04LZ1	 BUFFER[497]	//( - , MDuBz1) Исправность АКНП4
#define idA0EE04LZ1	 210	//( - , MDuBz1) Исправность АКНП4
#define A0VN01LDU	 BUFFER[499]	//( - , DU) Каналы АЗ1 проверены
#define idA0VN01LDU	 211	//( - , DU) Каналы АЗ1 проверены
#define B1IS11LDU	 BUFFER[501]	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define idB1IS11LDU	 212	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define A2IC01UDU	 BUFFER[503]	//( - , MDuS) Координата штока РБ1 (дел.энк)
#define idA2IC01UDU	 213	//( - , MDuS) Координата штока РБ1 (дел.энк)
#define B2IC01UDU	 BUFFER[508]	//( - , MDuS) Координата штока РБ2 (дел.энк)
#define idB2IC01UDU	 214	//( - , MDuS) Координата штока РБ2 (дел.энк)
#define A3IC01UDU	 BUFFER[513]	//( - , MDuS) Координата штока ИС1 (дел.энк)
#define idA3IC01UDU	 215	//( - , MDuS) Координата штока ИС1 (дел.энк)
#define B3IC01UDU	 BUFFER[518]	//( - , MDuS) Координата штока ИС2 (дел.энк)
#define idB3IC01UDU	 216	//( - , MDuS) Координата штока ИС2 (дел.энк)
#define B3VC01RDU	 BUFFER[523]	//( - , DU) Координата ИС2, мм
#define idB3VC01RDU	 217	//( - , DU) Координата ИС2, мм
#define A8IC01UDU	 BUFFER[528]	//( - , MDuS) Координата ДС2 (дел.энк)
#define idA8IC01UDU	 218	//( - , MDuS) Координата ДС2 (дел.энк)
#define A8VC01RDU	 BUFFER[533]	//( - , DU) Координата ДС2, мм
#define idA8VC01RDU	 219	//( - , DU) Координата ДС2, мм
#define B8IC01UDU	 BUFFER[538]	//( - , MDuS) Координата АЗ2 (дел.энк)
#define idB8IC01UDU	 220	//( - , MDuS) Координата АЗ2 (дел.энк)
#define A1IC01UDU	 BUFFER[543]	//( - , MDuS) Координата штока ББ1 (дел.энк)
#define idA1IC01UDU	 221	//( - , MDuS) Координата штока ББ1 (дел.энк)
#define A1VC01RDU	 BUFFER[548]	//( - , DU) Координата ББ1, мм
#define idA1VC01RDU	 222	//( - , DU) Координата ББ1, мм
#define A1IS11LDU	 BUFFER[553]	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define idA1IS11LDU	 223	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define B1MC01LC1	 BUFFER[555]	//( - , DU) Настроить энкодер ББ2
#define idB1MC01LC1	 224	//( - , DU) Настроить энкодер ББ2
#define B1MC01LC2	 BUFFER[557]	//( - , DU) Настроить энкодер ББ2
#define idB1MC01LC2	 225	//( - , DU) Настроить энкодер ББ2
#define A1MC01LC1	 BUFFER[559]	//( - , DU) Настроить энкодер ББ1
#define idA1MC01LC1	 226	//( - , DU) Настроить энкодер ББ1
#define A1MC01LC2	 BUFFER[561]	//( - , DU) Настроить энкодер ББ1
#define idA1MC01LC2	 227	//( - , DU) Настроить энкодер ББ1
#define B2MC01LC1	 BUFFER[563]	//( - , DU) Настроить энкодер РБ2
#define idB2MC01LC1	 228	//( - , DU) Настроить энкодер РБ2
#define B2MC01LC2	 BUFFER[565]	//( - , DU) Настроить энкодер РБ2
#define idB2MC01LC2	 229	//( - , DU) Настроить энкодер РБ2
#define A2MC01LC1	 BUFFER[567]	//( - , DU) Настроить энкодер РБ1
#define idA2MC01LC1	 230	//( - , DU) Настроить энкодер РБ1
#define A2MC01LC2	 BUFFER[569]	//( - , DU) Настроить энкодер РБ1
#define idA2MC01LC2	 231	//( - , DU) Настроить энкодер РБ1
#define B3MC01LC1	 BUFFER[571]	//( - , DU) Настроить энкодер ИС2
#define idB3MC01LC1	 232	//( - , DU) Настроить энкодер ИС2
#define B3MC01LC2	 BUFFER[573]	//( - , DU) Настроить энкодер ИС2
#define idB3MC01LC2	 233	//( - , DU) Настроить энкодер ИС2
#define A3MC01LC1	 BUFFER[575]	//( - , DU) Настроить энкодер ИС1
#define idA3MC01LC1	 234	//( - , DU) Настроить энкодер ИС1
#define A3MC01LC2	 BUFFER[577]	//( - , DU) Настроить энкодер ИС1
#define idA3MC01LC2	 235	//( - , DU) Настроить энкодер ИС1
#define R0IE01LDU	 BUFFER[579]	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define idR0IE01LDU	 236	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define A6IE01LDU	 BUFFER[581]	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define idA6IE01LDU	 237	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define B6IE01LDU	 BUFFER[583]	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define idB6IE01LDU	 238	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define A8IE01LDU	 BUFFER[585]	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define idA8IE01LDU	 239	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define B5IE01LDU	 BUFFER[587]	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define idB5IE01LDU	 240	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define A5IE02LDU	 BUFFER[589]	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define idA5IE02LDU	 241	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define R1IE01LDU	 BUFFER[591]	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define idR1IE01LDU	 242	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define R2IE01LDU	 BUFFER[593]	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define idR2IE01LDU	 243	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define R6IS61LDU	 BUFFER[595]	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define idR6IS61LDU	 244	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define R6IS66LZZ	 BUFFER[597]	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 245	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[599]	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 246	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[601]	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 247	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define A3VC01RDU	 BUFFER[603]	//( - , DU) Координата ИС1, мм
#define idA3VC01RDU	 248	//( - , DU) Координата ИС1, мм
#define A2VC01RDU	 BUFFER[608]	//( - , DU) Координата РБ1, мм
#define idA2VC01RDU	 249	//( - , DU) Координата РБ1, мм
#define B2VC01RDU	 BUFFER[613]	//( - , DU) Координата РБ2, мм
#define idB2VC01RDU	 250	//( - , DU) Координата РБ2, мм
#define B8VC01RDU	 BUFFER[618]	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
#define idB8VC01RDU	 251	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
#define A4VP82LDU	 BUFFER[623]	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 252	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define B4VP82LDU	 BUFFER[625]	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 253	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define A2VP82LDU	 BUFFER[627]	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 254	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define B2VP82LDU	 BUFFER[629]	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 255	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define A3VP81LDU	 BUFFER[631]	//( - , - ) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 256	//( - , - ) Давление СПУСК ИС1 в норме
#define B3VP81LDU	 BUFFER[633]	//( - , - ) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 257	//( - , - ) Давление СПУСК ИС2 в норме
#define R0EE02LDU	 BUFFER[635]	//( - , DU) Питание  АКНП  отключить
#define idR0EE02LDU	 258	//( - , DU) Питание  АКНП  отключить
#define B0VN01LDU	 BUFFER[637]	//( - , DU) Каналы АЗ2 проверены
#define idB0VN01LDU	 259	//( - , DU) Каналы АЗ2 проверены
#define A0EE01LZ2	 BUFFER[639]	//( - , MDuBz2) Исправность АКНП1
#define idA0EE01LZ2	 260	//( - , MDuBz2) Исправность АКНП1
#define A0EE03LZ2	 BUFFER[641]	//( - , MDuBz2) Исправность АКНП3
#define idA0EE03LZ2	 261	//( - , MDuBz2) Исправность АКНП3
#define A0EE02LZ2	 BUFFER[643]	//( - , MDuBz2) Исправность АКНП2
#define idA0EE02LZ2	 262	//( - , MDuBz2) Исправность АКНП2
#define A0EE04LZ2	 BUFFER[645]	//( - , MDuBz2) Исправность АКНП4
#define idA0EE04LZ2	 263	//( - , MDuBz2) Исправность АКНП4
#define A0VP71LZ1	 BUFFER[647]	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	 264	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define A0VP71LZ2	 BUFFER[649]	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ2	 265	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define B0VP71LZ1	 BUFFER[651]	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	 266	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define B0VP71LZ2	 BUFFER[653]	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ2	 267	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define A0VS11LDU	 BUFFER[655]	//( - , DU) АЗ1 готова к работе
#define idA0VS11LDU	 268	//( - , DU) АЗ1 готова к работе
#define B0VS11LDU	 BUFFER[657]	//( - , DU) АЗ2 готова к работе
#define idB0VS11LDU	 269	//( - , DU) АЗ2 готова к работе
#define A1IE01LDU	 BUFFER[659]	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define idA1IE01LDU	 270	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define A3IE01LDU	 BUFFER[661]	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define idA3IE01LDU	 271	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define A2IE01LDU	 BUFFER[663]	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define idA2IE01LDU	 272	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define A1IE02LDU	 BUFFER[665]	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define idA1IE02LDU	 273	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define A3IE02LDU	 BUFFER[667]	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define idA3IE02LDU	 274	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define A2IE02LDU	 BUFFER[669]	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define idA2IE02LDU	 275	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define B1IE01LDU	 BUFFER[671]	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define idB1IE01LDU	 276	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define B2IE01LDU	 BUFFER[673]	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define idB2IE01LDU	 277	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define B3IE01LDU	 BUFFER[675]	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define idB3IE01LDU	 278	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define B1IE02LDU	 BUFFER[677]	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define idB1IE02LDU	 279	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define B3IE02LDU	 BUFFER[679]	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define idB3IE02LDU	 280	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define B2IE02LDU	 BUFFER[681]	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define idB2IE02LDU	 281	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define R0IE02LDU	 BUFFER[683]	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define idR0IE02LDU	 282	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define R5VS22LDU	 BUFFER[685]	//( - , DU) Движение ворот отстойной зоны к закрыты
#define idR5VS22LDU	 283	//( - , DU) Движение ворот отстойной зоны к закрыты
#define R5VS12LDU	 BUFFER[687]	//( - , DU) Движение ворот отстойной зоны к открыты
#define idR5VS12LDU	 284	//( - , DU) Движение ворот отстойной зоны к открыты
#define R5VS01IDU	 BUFFER[689]	//( - , DU) Готовность к управлению ворот отстойной зоны
#define idR5VS01IDU	 285	//( - , DU) Готовность к управлению ворот отстойной зоны
#define R3VS22LDU	 BUFFER[692]	//( - , DU) Движение гомогенных дверей к закрыты
#define idR3VS22LDU	 286	//( - , DU) Движение гомогенных дверей к закрыты
#define R3VS12LDU	 BUFFER[694]	//( - , DU) Движение гомогенных дверей к открыты
#define idR3VS12LDU	 287	//( - , DU) Движение гомогенных дверей к открыты
#define R3VS01IDU	 BUFFER[696]	//( - , DU) Готовность к управлению гомогенных дверей
#define idR3VS01IDU	 288	//( - , DU) Готовность к управлению гомогенных дверей
#define A3AB13LDU	 BUFFER[699]	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define idA3AB13LDU	 289	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define B3AB13LDU	 BUFFER[701]	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define idB3AB13LDU	 290	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define R0DE02LDU	 BUFFER[703]	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define idR0DE02LDU	 291	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define R0DE03LDU	 BUFFER[706]	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define idR0DE03LDU	 292	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define R0DE04LDU	 BUFFER[709]	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define idR0DE04LDU	 293	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define R0DE08LDU	 BUFFER[712]	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define idR0DE08LDU	 294	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define R0DE05LDU	 BUFFER[715]	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define idR0DE05LDU	 295	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define R0DE09LDU	 BUFFER[718]	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define idR0DE09LDU	 296	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define R0DE0ALDU	 BUFFER[721]	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define idR0DE0ALDU	 297	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define R0DE07LDU	 BUFFER[724]	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define idR0DE07LDU	 298	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define R0DE0CLDU	 BUFFER[727]	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define idR0DE0CLDU	 299	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define R0DE0BLDU	 BUFFER[730]	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define idR0DE0BLDU	 300	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define R0DE0DLDU	 BUFFER[733]	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define idR0DE0DLDU	 301	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define R0DE0FLDU	 BUFFER[736]	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define idR0DE0FLDU	 302	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define TTLDU	 BUFFER[739]	//( - , DU) ttl
#define idTTLDU	 303	//( - , DU) ttl
#define R0DEB3LDU	 BUFFER[742]	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define idR0DEB3LDU	 304	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define R0DEB2LDU	 BUFFER[744]	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define idR0DEB2LDU	 305	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define R0AB19LDU	 BUFFER[746]	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define idR0AB19LDU	 306	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define R0CN93LDU	 BUFFER[748]	//( - , DU) время работы на мощности более 100Вт, сек
#define idR0CN93LDU	 307	//( - , DU) время работы на мощности более 100Вт, сек
#define R0CN94LDU	 BUFFER[753]	//( - , DU) Скорость изменения мощности
#define idR0CN94LDU	 308	//( - , DU) Скорость изменения мощности
#define R0CN95LDU	 BUFFER[758]	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define idR0CN95LDU	 309	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define R0AD03LZ1	 BUFFER[761]	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define idR0AD03LZ1	 310	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define R0AD03LZ2	 BUFFER[763]	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define idR0AD03LZ2	 311	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define R0AD04LZ1	 BUFFER[765]	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define idR0AD04LZ1	 312	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define R0AD04LZ2	 BUFFER[767]	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define idR0AD04LZ2	 313	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define R0AD05LZ1	 BUFFER[769]	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define idR0AD05LZ1	 314	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define R0AD05LZ2	 BUFFER[771]	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define idR0AD05LZ2	 315	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define B8IS12LDU	 BUFFER[773]	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define idB8IS12LDU	 316	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define B8IS21LDU	 BUFFER[775]	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define idB8IS21LDU	 317	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define A1VP41LZ1	 BUFFER[777]	//( - , MDuBz1) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	 318	//( - , MDuBz1) Давление СБРОС ББ1 ниже АС
#define A1VP41LZ2	 BUFFER[779]	//( - , MDuBz2) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ2	 319	//( - , MDuBz2) Давление СБРОС ББ1 ниже АС
#define R0VL22LDU	 BUFFER[781]	//( - , DU) Конец программы 200сек
#define idR0VL22LDU	 320	//( - , DU) Конец программы 200сек
#define R0VL23LDU	 BUFFER[783]	//( - , DU) Конец программы 20мин
#define idR0VL23LDU	 321	//( - , DU) Конец программы 20мин
#define B1VP41LZ1	 BUFFER[785]	//( - , MDuBz1) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	 322	//( - , MDuBz1) Давление СБРОС ББ2 ниже АС
#define B1VP41LZ2	 BUFFER[787]	//( - , MDuBz2) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ2	 323	//( - , MDuBz2) Давление СБРОС ББ2 ниже АС
#define A3AB19LDU	 BUFFER[789]	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define idA3AB19LDU	 324	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define B3AB19LDU	 BUFFER[791]	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define idB3AB19LDU	 325	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define A3EE03LDU	 BUFFER[793]	//( - , DU) ВПИС ИС1
#define idA3EE03LDU	 326	//( - , DU) ВПИС ИС1
#define B3EE03LDU	 BUFFER[795]	//( - , DU) ВПИС ИС2
#define idB3EE03LDU	 327	//( - , DU) ВПИС ИС2
#define B3AB15LDU	 BUFFER[797]	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define idB3AB15LDU	 328	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define R5IS21LDU	 BUFFER[799]	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 329	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define psz1	 BUFFER[801]	//( - , DU) 
#define idpsz1	 330	//( - , DU) 
#define psz2	 BUFFER[803]	//( - , DU) 
#define idpsz2	 331	//( - , DU) 
#define psz3	 BUFFER[805]	//( - , DU) 
#define idpsz3	 332	//( - , DU) 
#define psz4	 BUFFER[807]	//( - , DU) 
#define idpsz4	 333	//( - , DU) 
#define psz5	 BUFFER[809]	//( - , DU) 
#define idpsz5	 334	//( - , DU) 
#define psz6	 BUFFER[811]	//( - , DU) 
#define idpsz6	 335	//( - , DU) 
#define psz7	 BUFFER[813]	//( - , DU) 
#define idpsz7	 336	//( - , DU) 
#define psz8	 BUFFER[815]	//( - , DU) 
#define idpsz8	 337	//( - , DU) 
#define psz9	 BUFFER[817]	//( - , DU) 
#define idpsz9	 338	//( - , DU) 
#define psz10	 BUFFER[819]	//( - , DU) 
#define idpsz10	 339	//( - , DU) 
#define psz11	 BUFFER[821]	//( - , DU) 
#define idpsz11	 340	//( - , DU) 
#define psz12	 BUFFER[823]	//( - , DU) 
#define idpsz12	 341	//( - , DU) 
#define psz13	 BUFFER[825]	//( - , DU) 
#define idpsz13	 342	//( - , DU) 
#define psz14	 BUFFER[827]	//( - , DU) 
#define idpsz14	 343	//( - , DU) 
#define psz21	 BUFFER[829]	//( - , DU) 
#define idpsz21	 344	//( - , DU) 
#define psz22	 BUFFER[831]	//( - , DU) 
#define idpsz22	 345	//( - , DU) 
#define psz23	 BUFFER[833]	//( - , DU) 
#define idpsz23	 346	//( - , DU) 
#define psz24	 BUFFER[835]	//( - , DU) 
#define idpsz24	 347	//( - , DU) 
#define psz25	 BUFFER[837]	//( - , DU) 
#define idpsz25	 348	//( - , DU) 
#define psz26	 BUFFER[839]	//( - , DU) 
#define idpsz26	 349	//( - , DU) 
#define psz27	 BUFFER[841]	//( - , DU) 
#define idpsz27	 350	//( - , DU) 
#define psz28	 BUFFER[843]	//( - , DU) 
#define idpsz28	 351	//( - , DU) 
#define B1IC01UDU	 BUFFER[845]	//( - , MDuS) Координата штока ББ2 (дел.энк)
#define idB1IC01UDU	 352	//( - , MDuS) Координата штока ББ2 (дел.энк)
#define B1VC01RDU	 BUFFER[850]	//( - , DU) Координата ББ2, мм
#define idB1VC01RDU	 353	//( - , DU) Координата ББ2, мм
#define R0DEB1LDU	 BUFFER[855]	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define idR0DEB1LDU	 354	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define R0DEB4LDU	 BUFFER[857]	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define idR0DEB4LDU	 355	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define R0DE3DLDU	 BUFFER[859]	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define idR0DE3DLDU	 356	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define R0DE3CLDU	 BUFFER[861]	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define idR0DE3CLDU	 357	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define TestDiagnDU	 BUFFER[863]	//( - , DU) Неисправность от
#define idTestDiagnDU	 358	//( - , DU) Неисправность от
#define B3CV01RDU	 BUFFER[865]	//( - , DU) Измеренная скорость перемещения ИС2
#define idB3CV01RDU	 359	//( - , DU) Измеренная скорость перемещения ИС2
#define R0DE01LDU	 BUFFER[870]	//(vencf8l:01 - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
#define idR0DE01LDU	 360	//(vencf8l:01 - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
#define R0DE06LDU	 BUFFER[873]	//(vencf8l:01 - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
#define idR0DE06LDU	 361	//(vencf8l:01 - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
#define venc01	 BUFFER[876]	//(vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
#define idvenc01	 362	//(vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
#define venc02	 BUFFER[881]	//(vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
#define idvenc02	 363	//(vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
#define venc03	 BUFFER[886]	//(vencf8l:01 - venc03, - ) заначение реального энкодера Ис1
#define idvenc03	 364	//(vencf8l:01 - venc03, - ) заначение реального энкодера Ис1
#define venc04	 BUFFER[891]	//(vencf8l:01 - venc04, - ) заначение реального энкодера ДС1
#define idvenc04	 365	//(vencf8l:01 - venc04, - ) заначение реального энкодера ДС1
#define venc05	 BUFFER[896]	//(vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
#define idvenc05	 366	//(vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
#define venc06	 BUFFER[901]	//(vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
#define idvenc06	 367	//(vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
#define venc07	 BUFFER[906]	//(vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
#define idvenc07	 368	//(vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
#define venc08	 BUFFER[911]	//(vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
#define idvenc08	 369	//(vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
#define R0VN15RDU	 BUFFER[916]	//( - , DU) Период разгона РУ
#define idR0VN15RDU	 370	//( - , DU) Период разгона РУ
#define R8AD21LDU	 BUFFER[921]	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define idR8AD21LDU	 371	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define R8AD22LDU	 BUFFER[923]	//(vds32:02 - K15VDSR, - ) Сигнал синхронизации с импульсом
#define idR8AD22LDU	 372	//(vds32:02 - K15VDSR, - ) Сигнал синхронизации с импульсом
#define R0S01LDU	 BUFFER[925]	//( - , - ) Отключение сетевых передач ДУ
#define idR0S01LDU	 373	//( - , - ) Отключение сетевых передач ДУ
#define R0S01LZ1	 BUFFER[927]	//(fds16:07 - K15FDSR, - ) Отключение сетевых передач в Баз1
#define idR0S01LZ1	 374	//(fds16:07 - K15FDSR, - ) Отключение сетевых передач в Баз1
#define R0S01LZ2	 BUFFER[929]	//(fds16:07 - K16FDSR, - ) Отключение сетевых передач в Баз2
#define idR0S01LZ2	 375	//(fds16:07 - K16FDSR, - ) Отключение сетевых передач в Баз2
#define R0AD16LDU	 BUFFER[931]	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define idR0AD16LDU	 376	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define R0S01LIM	 BUFFER[933]	//(fds16:08 - K15FDSR, - ) Отключение сетевых передач ПТИ
#define idR0S01LIM	 377	//(fds16:08 - K15FDSR, - ) Отключение сетевых передач ПТИ
#define B6AB06LDU	 BUFFER[935]	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define idB6AB06LDU	 378	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define B6AB07LDU	 BUFFER[937]	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define idB6AB07LDU	 379	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define B6AB08LDU	 BUFFER[939]	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define idB6AB08LDU	 380	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define B6AB09LDU	 BUFFER[941]	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define idB6AB09LDU	 381	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define A6AB05LDU	 BUFFER[943]	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define idA6AB05LDU	 382	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define B8VS12LDU	 BUFFER[945]	//( - , DU) Движение АЗ2 в сторону ВУ
#define idB8VS12LDU	 383	//( - , DU) Движение АЗ2 в сторону ВУ
#define B8CV01RDU	 BUFFER[947]	//( - , DU) Измеренная скорость перемещения АЗ2
#define idB8CV01RDU	 384	//( - , DU) Измеренная скорость перемещения АЗ2
#define B8AB06LDU	 BUFFER[952]	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define idB8AB06LDU	 385	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define B8AB07LDU	 BUFFER[954]	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define idB8AB07LDU	 386	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define B8AB05LDU	 BUFFER[956]	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define idB8AB05LDU	 387	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define B8VS22LDU	 BUFFER[958]	//( - , DU) Движение АЗ2 в сторону НУ
#define idB8VS22LDU	 388	//( - , DU) Движение АЗ2 в сторону НУ
#define B8AZ03LDU	 BUFFER[960]	//( - , DU) Несанкционированное перемещение АЗ2
#define idB8AZ03LDU	 389	//( - , DU) Несанкционированное перемещение АЗ2
#define R0MD11LP1	 BUFFER[962]	//( - , DU) Кнопка ПУСК
#define idR0MD11LP1	 390	//( - , DU) Кнопка ПУСК
#define B8AD10LDU	 BUFFER[964]	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define idB8AD10LDU	 391	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define B8AD20LDU	 BUFFER[966]	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define idB8AD20LDU	 392	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define B8IS11LDU	 BUFFER[968]	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define idB8IS11LDU	 393	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define B8AB01LDU	 BUFFER[970]	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define idB8AB01LDU	 394	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define B8AB04LDU	 BUFFER[972]	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define idB8AB04LDU	 395	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define B8AB08LDU	 BUFFER[974]	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define idB8AB08LDU	 396	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define B8AB09LDU	 BUFFER[976]	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define idB8AB09LDU	 397	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define B8AB10LDU	 BUFFER[978]	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define idB8AB10LDU	 398	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define B8AB11LDU	 BUFFER[980]	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define idB8AB11LDU	 399	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define B8AB12LDU	 BUFFER[982]	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define idB8AB12LDU	 400	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define B5AZ03LDU	 BUFFER[984]	//( - , DU) Несанкционированное перемещение НЛ2
#define idB5AZ03LDU	 401	//( - , DU) Несанкционированное перемещение НЛ2
#define B5AB01LDU	 BUFFER[986]	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define idB5AB01LDU	 402	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define B5AB02LDU	 BUFFER[988]	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define idB5AB02LDU	 403	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define A4IS21LDU	 BUFFER[990]	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define idA4IS21LDU	 404	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define B4IS21LDU	 BUFFER[992]	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define idB4IS21LDU	 405	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define B4AD10LDU	 BUFFER[994]	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define idB4AD10LDU	 406	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define A4AD10LDU	 BUFFER[996]	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define idA4AD10LDU	 407	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define A4AZ03LDU	 BUFFER[998]	//( - , DU) Несанкционированное перемещение НИ1
#define idA4AZ03LDU	 408	//( - , DU) Несанкционированное перемещение НИ1
#define A4AB01LDU	 BUFFER[1000]	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define idA4AB01LDU	 409	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define A4AB02LDU	 BUFFER[1002]	//( - , DU) Блокировка движения НИ1 - Нет перемещения
#define idA4AB02LDU	 410	//( - , DU) Блокировка движения НИ1 - Нет перемещения
#define B4AZ03LDU	 BUFFER[1004]	//( - , DU) Несанкционированное перемещение НИ2
#define idB4AZ03LDU	 411	//( - , DU) Несанкционированное перемещение НИ2
#define B4AB01LDU	 BUFFER[1006]	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define idB4AB01LDU	 412	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define B4AB02LDU	 BUFFER[1008]	//( - , DU) Блокировка движения НИ2 - Нет перемещения
#define idB4AB02LDU	 413	//( - , DU) Блокировка движения НИ2 - Нет перемещения
#define A5AB04LDU	 BUFFER[1010]	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define idA5AB04LDU	 414	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define B5AB04LDU	 BUFFER[1012]	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define idB5AB04LDU	 415	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define A1IS12LDU	 BUFFER[1014]	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define idA1IS12LDU	 416	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define A2IS12LDU	 BUFFER[1016]	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define idA2IS12LDU	 417	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define B1IS12LDU	 BUFFER[1018]	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define idB1IS12LDU	 418	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define B2IS12LDU	 BUFFER[1020]	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define idB2IS12LDU	 419	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define R4IS11LDU	 BUFFER[1022]	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define idR4IS11LDU	 420	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define A6AB06LDU	 BUFFER[1024]	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define idA6AB06LDU	 421	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define A6AB07LDU	 BUFFER[1026]	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define idA6AB07LDU	 422	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define A6AB08LDU	 BUFFER[1028]	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define idA6AB08LDU	 423	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define A6AB09LDU	 BUFFER[1030]	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define idA6AB09LDU	 424	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define A8AB01LDU	 BUFFER[1032]	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define idA8AB01LDU	 425	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define A2VS11LDU	 BUFFER[1034]	//( - , DU) Движение РБ1 в сторону ВУ
#define idA2VS11LDU	 426	//( - , DU) Движение РБ1 в сторону ВУ
#define A2CV01RDU	 BUFFER[1036]	//( - , DU) Измеренная скорость перемещения РБ1
#define idA2CV01RDU	 427	//( - , DU) Измеренная скорость перемещения РБ1
#define A2AB04LDU	 BUFFER[1041]	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define idA2AB04LDU	 428	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define A2AB02LDU	 BUFFER[1043]	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define idA2AB02LDU	 429	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define A2AB01LDU	 BUFFER[1045]	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define idA2AB01LDU	 430	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define A2VS21LDU	 BUFFER[1047]	//( - , DU) Движение РБ1 в сторону НУ
#define idA2VS21LDU	 431	//( - , DU) Движение РБ1 в сторону НУ
#define A2AZ03LDU	 BUFFER[1049]	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define idA2AZ03LDU	 432	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define A2AD11LDU	 BUFFER[1051]	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 433	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define A2AD21LDU	 BUFFER[1053]	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 434	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define A2AD02LDU	 BUFFER[1055]	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define idA2AD02LDU	 435	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[1057]	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define idA2AD03LDU	 436	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define A2AD04LDU	 BUFFER[1059]	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define idA2AD04LDU	 437	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define A2AD05LDU	 BUFFER[1061]	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define idA2AD05LDU	 438	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define A2AB07LDU	 BUFFER[1063]	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define idA2AB07LDU	 439	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define A2AB08LDU	 BUFFER[1065]	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define idA2AB08LDU	 440	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define A2AB05LDU	 BUFFER[1067]	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define idA2AB05LDU	 441	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define A2AB06LDU	 BUFFER[1069]	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA2AB06LDU	 442	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define A2AB09LDU	 BUFFER[1071]	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define idA2AB09LDU	 443	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define A2AB10LDU	 BUFFER[1073]	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define idA2AB10LDU	 444	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define A2AB11LDU	 BUFFER[1075]	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define idA2AB11LDU	 445	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define A2AB12LDU	 BUFFER[1077]	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA2AB12LDU	 446	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A2AB13LDU	 BUFFER[1079]	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define idA2AB13LDU	 447	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define B8AB13LDU	 BUFFER[1081]	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define idB8AB13LDU	 448	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define B8AB14LDU	 BUFFER[1083]	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define idB8AB14LDU	 449	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define B8AB02LDU	 BUFFER[1085]	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define idB8AB02LDU	 450	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define A8VS12LDU	 BUFFER[1087]	//( - , DU) Движение ДС2 в сторону ВУ
#define idA8VS12LDU	 451	//( - , DU) Движение ДС2 в сторону ВУ
#define A8CV01RDU	 BUFFER[1089]	//( - , DU) Измеренная скорость перемещения ДС2
#define idA8CV01RDU	 452	//( - , DU) Измеренная скорость перемещения ДС2
#define A8AB06LDU	 BUFFER[1094]	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define idA8AB06LDU	 453	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define A8AB07LDU	 BUFFER[1096]	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define idA8AB07LDU	 454	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define A8AB05LDU	 BUFFER[1098]	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define idA8AB05LDU	 455	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define A8VS22LDU	 BUFFER[1100]	//( - , DU) Движение ДС2 в сторону НУ
#define idA8VS22LDU	 456	//( - , DU) Движение ДС2 в сторону НУ
#define A8AZ03LDU	 BUFFER[1102]	//( - , DU) Несанкционированное перемещение ДС2
#define idA8AZ03LDU	 457	//( - , DU) Несанкционированное перемещение ДС2
#define A8AD10LDU	 BUFFER[1104]	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define idA8AD10LDU	 458	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define A8AD20LDU	 BUFFER[1106]	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define idA8AD20LDU	 459	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define B8IS22LDU	 BUFFER[1108]	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define idB8IS22LDU	 460	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define A8IS12LDU	 BUFFER[1110]	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define idA8IS12LDU	 461	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define A8AB04LDU	 BUFFER[1112]	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define idA8AB04LDU	 462	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define A8IS22LDU	 BUFFER[1114]	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define idA8IS22LDU	 463	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define A8AB08LDU	 BUFFER[1116]	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define idA8AB08LDU	 464	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define A8AB09LDU	 BUFFER[1118]	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define idA8AB09LDU	 465	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define A8AB10LDU	 BUFFER[1120]	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define idA8AB10LDU	 466	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define A8AB11LDU	 BUFFER[1122]	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define idA8AB11LDU	 467	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define A8AB12LDU	 BUFFER[1124]	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define idA8AB12LDU	 468	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define A8AB13LDU	 BUFFER[1126]	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define idA8AB13LDU	 469	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define A8AB14LDU	 BUFFER[1128]	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define idA8AB14LDU	 470	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define A8AB02LDU	 BUFFER[1130]	//( - , DU) Блокировка движения ДС2- АНИ не установлен
#define idA8AB02LDU	 471	//( - , DU) Блокировка движения ДС2- АНИ не установлен
#define A6VS22LDU	 BUFFER[1132]	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	 472	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define A6VS12LDU	 BUFFER[1134]	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	 473	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define B6VS22LDU	 BUFFER[1136]	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define idB6VS22LDU	 474	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define B6VS12LDU	 BUFFER[1138]	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define idB6VS12LDU	 475	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define A6AD10LDU	 BUFFER[1140]	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
#define idA6AD10LDU	 476	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
#define A6AD20LDU	 BUFFER[1142]	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define idA6AD20LDU	 477	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define B6AD10LDU	 BUFFER[1144]	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
#define idB6AD10LDU	 478	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
#define B6AD20LDU	 BUFFER[1146]	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define idB6AD20LDU	 479	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define A6AZ03LDU	 BUFFER[1148]	//( - , DU) Несанкционированное перемещение БЗ1
#define idA6AZ03LDU	 480	//( - , DU) Несанкционированное перемещение БЗ1
#define A6AB01LDU	 BUFFER[1150]	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define idA6AB01LDU	 481	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define A6AB02LDU	 BUFFER[1152]	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define idA6AB02LDU	 482	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define B6AZ03LDU	 BUFFER[1154]	//( - , DU) Несанкционированное перемещение БЗ2
#define idB6AZ03LDU	 483	//( - , DU) Несанкционированное перемещение БЗ2
#define B6AB01LDU	 BUFFER[1156]	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define idB6AB01LDU	 484	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define B6AB02LDU	 BUFFER[1158]	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define idB6AB02LDU	 485	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define A6AB04LDU	 BUFFER[1160]	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define idA6AB04LDU	 486	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define B6AB04LDU	 BUFFER[1162]	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define idB6AB04LDU	 487	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define R4AB01LDU	 BUFFER[1164]	//( - , DU) Блокировка движения тележки - АНИ не установлен
#define idR4AB01LDU	 488	//( - , DU) Блокировка движения тележки - АНИ не установлен
#define R8IS11LDU	 BUFFER[1166]	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define idR8IS11LDU	 489	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define R6IS21LDU	 BUFFER[1168]	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	 490	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define A0VN71LZ2	 BUFFER[1170]	//( - , MDuBz2) АЗ по АС мощности для АЗ1
#define idA0VN71LZ2	 491	//( - , MDuBz2) АЗ по АС мощности для АЗ1
#define A0VN71LZ1	 BUFFER[1172]	//( - , MDuBz1) АЗ по АС мощности для АЗ1
#define idA0VN71LZ1	 492	//( - , MDuBz1) АЗ по АС мощности для АЗ1
#define R0NE01LDU	 BUFFER[1174]	//( - , DU) Потеря связи с БАЗ1
#define idR0NE01LDU	 493	//( - , DU) Потеря связи с БАЗ1
#define R0NE02LDU	 BUFFER[1176]	//( - , DU) Потеря связи с БАЗ2
#define idR0NE02LDU	 494	//( - , DU) Потеря связи с БАЗ2
#define R0MW15IP1	 BUFFER[1178]	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define idR0MW15IP1	 495	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define R0MW14IP1	 BUFFER[1181]	//( - , DU) Переключатель ПРОГРАММЫ
#define idR0MW14IP1	 496	//( - , DU) Переключатель ПРОГРАММЫ
#define R0MW12IP1	 BUFFER[1184]	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define idR0MW12IP1	 497	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define R0MW13IP1	 BUFFER[1187]	//( - , DU) Переключатель ВЫБОР ЗОН
#define idR0MW13IP1	 498	//( - , DU) Переключатель ВЫБОР ЗОН
#define R0MW16IP1	 BUFFER[1190]	//( - , DU) Переключатель ВИД ПРОВЕРКИ
#define idR0MW16IP1	 499	//( - , DU) Переключатель ВИД ПРОВЕРКИ
#define R0MW11IP1	 BUFFER[1193]	//( - , DU) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 500	//( - , DU) Переключатель ВЫСТРЕЛ
#define R0MW11IP2	 BUFFER[1196]	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define idR0MW11IP2	 501	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define R0MW13LP2	 BUFFER[1199]	//( - , DU) Переключатель СЕТЬ
#define idR0MW13LP2	 502	//( - , DU) Переключатель СЕТЬ
#define R0MD32LP1	 BUFFER[1201]	//( - , DU) Кнопка СПУСК
#define idR0MD32LP1	 503	//( - , DU) Кнопка СПУСК
#define R0MD31LP1	 BUFFER[1203]	//( - , DU) Кнопка СТОП
#define idR0MD31LP1	 504	//( - , DU) Кнопка СТОП
#define A1IS21LDU	 BUFFER[1205]	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define idA1IS21LDU	 505	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define A2IS21LDU	 BUFFER[1207]	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define idA2IS21LDU	 506	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define A3IS21LDU	 BUFFER[1209]	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define idA3IS21LDU	 507	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define B1IS21LDU	 BUFFER[1211]	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define idB1IS21LDU	 508	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define B2IS21LDU	 BUFFER[1213]	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define idB2IS21LDU	 509	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define B3IS21LDU	 BUFFER[1215]	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define idB3IS21LDU	 510	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define R0ES01LDU	 BUFFER[1217]	//( - , DU) ОРР не в исходном состоянии
#define idR0ES01LDU	 511	//( - , DU) ОРР не в исходном состоянии
#define R4MD11LP2	 BUFFER[1219]	//( - , DU) Кнопка ВПЕРЁД  (тележки)
#define idR4MD11LP2	 512	//( - , DU) Кнопка ВПЕРЁД  (тележки)
#define R4MD31LP2	 BUFFER[1221]	//( - , DU) Кнопка СТОП  (тележки)
#define idR4MD31LP2	 513	//( - , DU) Кнопка СТОП  (тележки)
#define R4MD21LP2	 BUFFER[1223]	//( - , DU) Кнопка НАЗАД  (тележки)
#define idR4MD21LP2	 514	//( - , DU) Кнопка НАЗАД  (тележки)
#define A6IS11LDU	 BUFFER[1225]	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define idA6IS11LDU	 515	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define A6IS21LDU	 BUFFER[1227]	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define idA6IS21LDU	 516	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define B6IS11LDU	 BUFFER[1229]	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define idB6IS11LDU	 517	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define B6IS21LDU	 BUFFER[1231]	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define idB6IS21LDU	 518	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define R4AB13LDU	 BUFFER[1233]	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define idR4AB13LDU	 519	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define R4AB14LDU	 BUFFER[1235]	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define idR4AB14LDU	 520	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define R4AB15LDU	 BUFFER[1237]	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define idR4AB15LDU	 521	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define R5IS11LDU	 BUFFER[1239]	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 522	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define R4AB16LDU	 BUFFER[1241]	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define idR4AB16LDU	 523	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define R4AB17LDU	 BUFFER[1243]	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define idR4AB17LDU	 524	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define R4AB18LDU	 BUFFER[1245]	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define idR4AB18LDU	 525	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define R4AD10LDU	 BUFFER[1247]	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	 526	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define R4AD20LDU	 BUFFER[1249]	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define idR4AD20LDU	 527	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define A5VS22LDU	 BUFFER[1251]	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 528	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define A5VS12LDU	 BUFFER[1253]	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 529	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define B5VS22LDU	 BUFFER[1255]	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 530	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define B5VS12LDU	 BUFFER[1257]	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 531	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define B5AD10LDU	 BUFFER[1259]	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
#define idB5AD10LDU	 532	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
#define B5AD20LDU	 BUFFER[1261]	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
#define idB5AD20LDU	 533	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
#define A5AD10LDU	 BUFFER[1263]	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
#define idA5AD10LDU	 534	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
#define A5AD20LDU	 BUFFER[1265]	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
#define idA5AD20LDU	 535	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
#define A5IS11LDU	 BUFFER[1267]	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define idA5IS11LDU	 536	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define A5IS21LDU	 BUFFER[1269]	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define idA5IS21LDU	 537	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define B5IS11LDU	 BUFFER[1271]	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define idB5IS11LDU	 538	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define B5IS21LDU	 BUFFER[1273]	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define idB5IS21LDU	 539	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define A5AZ03LDU	 BUFFER[1275]	//( - , DU) Несанкционированное перемещение НЛ1
#define idA5AZ03LDU	 540	//( - , DU) Несанкционированное перемещение НЛ1
#define A5AB01LDU	 BUFFER[1277]	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define idA5AB01LDU	 541	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define A5AB02LDU	 BUFFER[1279]	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define idA5AB02LDU	 542	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define R4AB02LDU	 BUFFER[1281]	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define idR4AB02LDU	 543	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define R0NE08LDU	 BUFFER[1283]	//( - , DU) Потеря связи с ОПУ
#define idR0NE08LDU	 544	//( - , DU) Потеря связи с ОПУ
#define R4IS21LDU	 BUFFER[1285]	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define idR4IS21LDU	 545	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define R4IS22LDU	 BUFFER[1287]	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define idR4IS22LDU	 546	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define R4IS12LDU	 BUFFER[1289]	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define idR4IS12LDU	 547	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define R4VS22LDU	 BUFFER[1291]	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define idR4VS22LDU	 548	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define R4VS12LDU	 BUFFER[1293]	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define idR4VS12LDU	 549	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define R4AZ03LDU	 BUFFER[1295]	//( - , DU) Несанкционированное перемещение тележки
#define idR4AZ03LDU	 550	//( - , DU) Несанкционированное перемещение тележки
#define R4AB03LDU	 BUFFER[1297]	//( - , DU) Блокировка движения тележки - Самоход любого механизма
#define idR4AB03LDU	 551	//( - , DU) Блокировка движения тележки - Самоход любого механизма
#define R1IS21LDU	 BUFFER[1299]	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define idR1IS21LDU	 552	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define R2IS21LDU	 BUFFER[1301]	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define idR2IS21LDU	 553	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define R4AB04LDU	 BUFFER[1303]	//( - , DU) Блокировка движения тележки - Превышение времени движения
#define idR4AB04LDU	 554	//( - , DU) Блокировка движения тележки - Превышение времени движения
#define R4AB05LDU	 BUFFER[1305]	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define idR4AB05LDU	 555	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define R4AB06LDU	 BUFFER[1307]	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define idR4AB06LDU	 556	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define R4AB07LDU	 BUFFER[1309]	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define idR4AB07LDU	 557	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define R4AB08LDU	 BUFFER[1311]	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define idR4AB08LDU	 558	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define R4AB09LDU	 BUFFER[1313]	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define idR4AB09LDU	 559	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define B0VN71LZ1	 BUFFER[1315]	//( - , MDuBz1) АЗ по АС мощности для АЗ2
#define idB0VN71LZ1	 560	//( - , MDuBz1) АЗ по АС мощности для АЗ2
#define B0VN71LZ2	 BUFFER[1317]	//( - , MDuBz2) АЗ по АС мощности для АЗ2
#define idB0VN71LZ2	 561	//( - , MDuBz2) АЗ по АС мощности для АЗ2
#define R4AB10LDU	 BUFFER[1319]	//( - , DU) Блокировка тележки - не открыта биологическая защита
#define idR4AB10LDU	 562	//( - , DU) Блокировка тележки - не открыта биологическая защита
#define R4AB11LDU	 BUFFER[1321]	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define idR4AB11LDU	 563	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define R4AB12LDU	 BUFFER[1323]	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define idR4AB12LDU	 564	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define A4IS11LDU	 BUFFER[1325]	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define idA4IS11LDU	 565	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define B4IS11LDU	 BUFFER[1327]	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define idB4IS11LDU	 566	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define A3AB05LDU	 BUFFER[1329]	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define idA3AB05LDU	 567	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define A3AB06LDU	 BUFFER[1331]	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define idA3AB06LDU	 568	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define A3AB09LDU	 BUFFER[1333]	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define idA3AB09LDU	 569	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define A3AB10LDU	 BUFFER[1335]	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define idA3AB10LDU	 570	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define A3AB11LDU	 BUFFER[1337]	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define idA3AB11LDU	 571	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define A3AB12LDU	 BUFFER[1339]	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA3AB12LDU	 572	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A3AB14LDU	 BUFFER[1341]	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define idA3AB14LDU	 573	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define A3AB16LDU	 BUFFER[1343]	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define idA3AB16LDU	 574	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define A3AB17LDU	 BUFFER[1345]	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define idA3AB17LDU	 575	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define A3AB18LDU	 BUFFER[1347]	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define idA3AB18LDU	 576	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define A3AB20LDU	 BUFFER[1349]	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define idA3AB20LDU	 577	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define B3VS12LDU	 BUFFER[1351]	//( - , DU) Движение ИС2 в сторону ВУ
#define idB3VS12LDU	 578	//( - , DU) Движение ИС2 в сторону ВУ
#define B3AB04LDU	 BUFFER[1353]	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define idB3AB04LDU	 579	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define B3AB02LDU	 BUFFER[1355]	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define idB3AB02LDU	 580	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define B3AB01LDU	 BUFFER[1357]	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define idB3AB01LDU	 581	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define B3VS22LDU	 BUFFER[1359]	//( - , DU) Движение ИС2 в сторону НУ
#define idB3VS22LDU	 582	//( - , DU) Движение ИС2 в сторону НУ
#define B3AZ03LDU	 BUFFER[1361]	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define idB3AZ03LDU	 583	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define B3AD11LDU	 BUFFER[1363]	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 584	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define B3AD21LDU	 BUFFER[1365]	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 585	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define B3AD02LDU	 BUFFER[1367]	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define idB3AD02LDU	 586	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[1369]	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define idB3AD03LDU	 587	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define B3AD04LDU	 BUFFER[1371]	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define idB3AD04LDU	 588	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define B3AD05LDU	 BUFFER[1373]	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define idB3AD05LDU	 589	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define B1AB11LDU	 BUFFER[1375]	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define idB1AB11LDU	 590	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define B1AB12LDU	 BUFFER[1377]	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idB1AB12LDU	 591	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define B1AB13LDU	 BUFFER[1379]	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define idB1AB13LDU	 592	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define B1AB14LDU	 BUFFER[1381]	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define idB1AB14LDU	 593	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define B1AB16LDU	 BUFFER[1383]	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define idB1AB16LDU	 594	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define B1AB17LDU	 BUFFER[1385]	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define idB1AB17LDU	 595	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define B1AB18LDU	 BUFFER[1387]	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define idB1AB18LDU	 596	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define A3VS12LDU	 BUFFER[1389]	//( - , DU) Движение ИС1 в сторону ВУ
#define idA3VS12LDU	 597	//( - , DU) Движение ИС1 в сторону ВУ
#define A3CV01RDU	 BUFFER[1391]	//( - , DU) Измеренная скорость перемещения ИС1
#define idA3CV01RDU	 598	//( - , DU) Измеренная скорость перемещения ИС1
#define A3AB04LDU	 BUFFER[1396]	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define idA3AB04LDU	 599	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define A3AB02LDU	 BUFFER[1398]	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define idA3AB02LDU	 600	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define A3AB01LDU	 BUFFER[1400]	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define idA3AB01LDU	 601	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define A3VS22LDU	 BUFFER[1402]	//( - , DU) Движение ИС1 в сторону НУ
#define idA3VS22LDU	 602	//( - , DU) Движение ИС1 в сторону НУ
#define A3AZ03LDU	 BUFFER[1404]	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define idA3AZ03LDU	 603	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define A3AD11LDU	 BUFFER[1406]	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 604	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define A3AD21LDU	 BUFFER[1408]	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 605	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define A3AD02LDU	 BUFFER[1410]	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define idA3AD02LDU	 606	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define A3AD03LDU	 BUFFER[1412]	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define idA3AD03LDU	 607	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define A3AD04LDU	 BUFFER[1414]	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define idA3AD04LDU	 608	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define A3AD05LDU	 BUFFER[1416]	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define idA3AD05LDU	 609	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define A3AD01LDU	 BUFFER[1418]	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define idA3AD01LDU	 610	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define A3CV02RDU	 BUFFER[1420]	//( - , DU) Заданная скорость перемещения ИС1
#define idA3CV02RDU	 611	//( - , DU) Заданная скорость перемещения ИС1
#define A3AB07LDU	 BUFFER[1425]	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define idA3AB07LDU	 612	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define A3AB08LDU	 BUFFER[1427]	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define idA3AB08LDU	 613	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define B1AD32LDU	 BUFFER[1429]	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define idB1AD32LDU	 614	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define R0MD11LP2	 BUFFER[1431]	//( - , DU) Кнопка Пуск проверки схем сброса
#define idR0MD11LP2	 615	//( - , DU) Кнопка Пуск проверки схем сброса
#define R0VX01LDU	 BUFFER[1433]	//( - , DU) ДО ИМПУЛЬСА
#define idR0VX01LDU	 616	//( - , DU) ДО ИМПУЛЬСА
#define R0VL01IDU	 BUFFER[1435]	//( - , DU) До импульса минут
#define idR0VL01IDU	 617	//( - , DU) До импульса минут
#define R0VL11IDU	 BUFFER[1438]	//( - , DU) До импульса секунд
#define idR0VL11IDU	 618	//( - , DU) До импульса секунд
#define R0VL06RDU	 BUFFER[1441]	//( - , DU) Индикация (Время задержки от ВУ РБ)
#define idR0VL06RDU	 619	//( - , DU) Индикация (Время задержки от ВУ РБ)
#define B3AD33LDU	 BUFFER[1446]	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define idB3AD33LDU	 620	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define R0VL02RDU	 BUFFER[1448]	//( - , DU) Индикация (Время задержки ИНИ)
#define idR0VL02RDU	 621	//( - , DU) Индикация (Время задержки ИНИ)
#define R0VL04RDU	 BUFFER[1453]	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define idR0VL04RDU	 622	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define R0AB04LDU	 BUFFER[1458]	//( - , DU) Нарушение времени срабатывания верхней АС II УР
#define idR0AB04LDU	 623	//( - , DU) Нарушение времени срабатывания верхней АС II УР
#define R0AB06LDU	 BUFFER[1460]	//( - , DU) Нарушение времени задержки от ВУ РБ
#define idR0AB06LDU	 624	//( - , DU) Нарушение времени задержки от ВУ РБ
#define R0AB02LDU	 BUFFER[1462]	//( - , DU) Нарушение времени задержки ИНИ
#define idR0AB02LDU	 625	//( - , DU) Нарушение времени задержки ИНИ
#define R0VL03RDU	 BUFFER[1464]	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define idR0VL03RDU	 626	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define R0VL05RDU	 BUFFER[1469]	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define idR0VL05RDU	 627	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define R0VL21IDU	 BUFFER[1474]	//( - , DU) Декатрон
#define idR0VL21IDU	 628	//( - , DU) Декатрон
#define R0VX03LDU	 BUFFER[1477]	//( - , DU) Готовность 2 мин
#define idR0VX03LDU	 629	//( - , DU) Готовность 2 мин
#define R0VS21IDU	 BUFFER[1479]	//( - , DU) Индикация ВИД ПРОВЕРКИ
#define idR0VS21IDU	 630	//( - , DU) Индикация ВИД ПРОВЕРКИ
#define A1VS01IDU	 BUFFER[1482]	//( - , DU) Готовность к управлению ББ1
#define idA1VS01IDU	 631	//( - , DU) Готовность к управлению ББ1
#define B1VS01IDU	 BUFFER[1485]	//( - , DU) Готовность к управлению ББ2
#define idB1VS01IDU	 632	//( - , DU) Готовность к управлению ББ2
#define A3VS01IDU	 BUFFER[1488]	//( - , DU) Готовность к управлению ИС1
#define idA3VS01IDU	 633	//( - , DU) Готовность к управлению ИС1
#define B3VS01IDU	 BUFFER[1491]	//( - , DU) Готовность к управлению ИС2
#define idB3VS01IDU	 634	//( - , DU) Готовность к управлению ИС2
#define A2VS01IDU	 BUFFER[1494]	//( - , DU) Готовность к управлению РБ1
#define idA2VS01IDU	 635	//( - , DU) Готовность к управлению РБ1
#define A4VS01IDU	 BUFFER[1497]	//( - , DU) Готовность к управлению НИ1
#define idA4VS01IDU	 636	//( - , DU) Готовность к управлению НИ1
#define B3AD01LDU	 BUFFER[1500]	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define idB3AD01LDU	 637	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define B3CV02RDU	 BUFFER[1502]	//( - , DU) Заданная скорость перемещения ИС2
#define idB3CV02RDU	 638	//( - , DU) Заданная скорость перемещения ИС2
#define B3AB07LDU	 BUFFER[1507]	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define idB3AB07LDU	 639	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define B3AB08LDU	 BUFFER[1509]	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define idB3AB08LDU	 640	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define B3AB05LDU	 BUFFER[1511]	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define idB3AB05LDU	 641	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define B3AB06LDU	 BUFFER[1513]	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define idB3AB06LDU	 642	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define B3AB09LDU	 BUFFER[1515]	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define idB3AB09LDU	 643	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define B3AB10LDU	 BUFFER[1517]	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define idB3AB10LDU	 644	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define B3AB11LDU	 BUFFER[1519]	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define idB3AB11LDU	 645	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define B3AB12LDU	 BUFFER[1521]	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB3AB12LDU	 646	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B3AB14LDU	 BUFFER[1523]	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define idB3AB14LDU	 647	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define B3AB16LDU	 BUFFER[1525]	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define idB3AB16LDU	 648	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define B3AB17LDU	 BUFFER[1527]	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define idB3AB17LDU	 649	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define B3AB18LDU	 BUFFER[1529]	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define idB3AB18LDU	 650	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define B3AB20LDU	 BUFFER[1531]	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define idB3AB20LDU	 651	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define C1MD31LP1	 BUFFER[1533]	//( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP1	 652	//( - , DU) Кнопка СБРОС ББ
#define C1MD31LP2	 BUFFER[1535]	//( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP2	 653	//( - , DU) Кнопка СБРОС ББ
#define A2AD31LDU	 BUFFER[1537]	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define idA2AD31LDU	 654	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define B2AD31LDU	 BUFFER[1539]	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define idB2AD31LDU	 655	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define A1AD31LDU	 BUFFER[1541]	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define idA1AD31LDU	 656	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define B1AD31LDU	 BUFFER[1543]	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define idB1AD31LDU	 657	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define A2AD32LDU	 BUFFER[1545]	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define idA2AD32LDU	 658	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define B2AD32LDU	 BUFFER[1547]	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define idB2AD32LDU	 659	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define A1AD32LDU	 BUFFER[1549]	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define idA1AD32LDU	 660	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define B2AB11LDU	 BUFFER[1551]	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define idB2AB11LDU	 661	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define B2AB12LDU	 BUFFER[1553]	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB2AB12LDU	 662	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B2AB13LDU	 BUFFER[1555]	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define idB2AB13LDU	 663	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define B2AB14LDU	 BUFFER[1557]	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define idB2AB14LDU	 664	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define B2AB16LDU	 BUFFER[1559]	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define idB2AB16LDU	 665	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define B2AB17LDU	 BUFFER[1561]	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define idB2AB17LDU	 666	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define R1AZ03LDU	 BUFFER[1563]	//( - , DU) Несанкционированное перемещение МДЗ1
#define idR1AZ03LDU	 667	//( - , DU) Несанкционированное перемещение МДЗ1
#define R1AB01LDU	 BUFFER[1565]	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define idR1AB01LDU	 668	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define R1AB02LDU	 BUFFER[1567]	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define idR1AB02LDU	 669	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define R2AZ03LDU	 BUFFER[1569]	//( - , DU) Несанкционированное перемещение МДЗ2
#define idR2AZ03LDU	 670	//( - , DU) Несанкционированное перемещение МДЗ2
#define R2AB01LDU	 BUFFER[1571]	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define idR2AB01LDU	 671	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define R2AB02LDU	 BUFFER[1573]	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define idR2AB02LDU	 672	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define R1AB04LDU	 BUFFER[1575]	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define idR1AB04LDU	 673	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define R2AB04LDU	 BUFFER[1577]	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define idR2AB04LDU	 674	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define R1AD10LDU	 BUFFER[1579]	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define idR1AD10LDU	 675	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define R1AD20LDU	 BUFFER[1581]	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	 676	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define R1IS11LDU	 BUFFER[1583]	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define idR1IS11LDU	 677	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define R1VS22LDU	 BUFFER[1585]	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 678	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define R2VS22LDU	 BUFFER[1587]	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 679	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define R2VS12LDU	 BUFFER[1589]	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 680	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define R1VS12LDU	 BUFFER[1591]	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 681	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define R2IS11LDU	 BUFFER[1593]	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define idR2IS11LDU	 682	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define A1VS12LDU	 BUFFER[1595]	//( - , DU) Движение ББ1 в сторону ВУ
#define idA1VS12LDU	 683	//( - , DU) Движение ББ1 в сторону ВУ
#define A2AB14LDU	 BUFFER[1597]	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define idA2AB14LDU	 684	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define A2AB16LDU	 BUFFER[1599]	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define idA2AB16LDU	 685	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define A2AB17LDU	 BUFFER[1601]	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define idA2AB17LDU	 686	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define A2AD01LDU	 BUFFER[1603]	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define idA2AD01LDU	 687	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define A2CV02RDU	 BUFFER[1605]	//( - , DU) Заданная скорость перемещения РБ1
#define idA2CV02RDU	 688	//( - , DU) Заданная скорость перемещения РБ1
#define B2CV01RDU	 BUFFER[1610]	//( - , DU) Измеренная скорость перемещения РБ2
#define idB2CV01RDU	 689	//( - , DU) Измеренная скорость перемещения РБ2
#define B2AB04LDU	 BUFFER[1615]	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define idB2AB04LDU	 690	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define B2AB02LDU	 BUFFER[1617]	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define idB2AB02LDU	 691	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define B2AB01LDU	 BUFFER[1619]	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define idB2AB01LDU	 692	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define B2AZ03LDU	 BUFFER[1621]	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define idB2AZ03LDU	 693	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define B2AD11LDU	 BUFFER[1623]	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 694	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define B2AD21LDU	 BUFFER[1625]	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 695	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define B2AD02LDU	 BUFFER[1627]	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define idB2AD02LDU	 696	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[1629]	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define idB2AD03LDU	 697	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define B2AD04LDU	 BUFFER[1631]	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define idB2AD04LDU	 698	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define B2AD05LDU	 BUFFER[1633]	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define idB2AD05LDU	 699	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define B2AD01LDU	 BUFFER[1635]	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define idB2AD01LDU	 700	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define B2CV02RDU	 BUFFER[1637]	//( - , DU) Заданная скорость перемещения РБ2
#define idB2CV02RDU	 701	//( - , DU) Заданная скорость перемещения РБ2
#define B2AB07LDU	 BUFFER[1642]	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define idB2AB07LDU	 702	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define B2AB08LDU	 BUFFER[1644]	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define idB2AB08LDU	 703	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define B2AB05LDU	 BUFFER[1646]	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define idB2AB05LDU	 704	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define B2AB06LDU	 BUFFER[1648]	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB2AB06LDU	 705	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define B2AB09LDU	 BUFFER[1650]	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define idB2AB09LDU	 706	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define B2AB10LDU	 BUFFER[1652]	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define idB2AB10LDU	 707	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define A1AB16LDU	 BUFFER[1654]	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define idA1AB16LDU	 708	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define A1AB17LDU	 BUFFER[1656]	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define idA1AB17LDU	 709	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define A1AB18LDU	 BUFFER[1658]	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define idA1AB18LDU	 710	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define B1VS12LDU	 BUFFER[1660]	//( - , DU) Движение ББ2 в сторону ВУ
#define idB1VS12LDU	 711	//( - , DU) Движение ББ2 в сторону ВУ
#define B1CV01RDU	 BUFFER[1662]	//( - , DU) Измеренная скорость перемещения ББ2
#define idB1CV01RDU	 712	//( - , DU) Измеренная скорость перемещения ББ2
#define B1AB04LDU	 BUFFER[1667]	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define idB1AB04LDU	 713	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define B1AB02LDU	 BUFFER[1669]	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define idB1AB02LDU	 714	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define B1AB01LDU	 BUFFER[1671]	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define idB1AB01LDU	 715	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define B1VS22LDU	 BUFFER[1673]	//( - , DU) Движение ББ2 в сторону НУ
#define idB1VS22LDU	 716	//( - , DU) Движение ББ2 в сторону НУ
#define B1AZ03LDU	 BUFFER[1675]	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define idB1AZ03LDU	 717	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define B1AD11LDU	 BUFFER[1677]	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 718	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define B1AD21LDU	 BUFFER[1679]	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 719	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define B1AD02LDU	 BUFFER[1681]	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define idB1AD02LDU	 720	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[1683]	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define idB1AD03LDU	 721	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define B1AD04LDU	 BUFFER[1685]	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define idB1AD04LDU	 722	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define B1AD05LDU	 BUFFER[1687]	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define idB1AD05LDU	 723	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define B1AD01LDU	 BUFFER[1689]	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define idB1AD01LDU	 724	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define B1CV02RDU	 BUFFER[1691]	//( - , DU) Заданная скорость перемещения ББ2
#define idB1CV02RDU	 725	//( - , DU) Заданная скорость перемещения ББ2
#define B1AB07LDU	 BUFFER[1696]	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define idB1AB07LDU	 726	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define B1AB08LDU	 BUFFER[1698]	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define idB1AB08LDU	 727	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define B1AB05LDU	 BUFFER[1700]	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define idB1AB05LDU	 728	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define B1AB06LDU	 BUFFER[1702]	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB1AB06LDU	 729	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define B1AB09LDU	 BUFFER[1704]	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define idB1AB09LDU	 730	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define B1AB10LDU	 BUFFER[1706]	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define idB1AB10LDU	 731	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define A1CV01RDU	 BUFFER[1708]	//( - , DU) Измеренная скорость перемещения ББ1
#define idA1CV01RDU	 732	//( - , DU) Измеренная скорость перемещения ББ1
#define A1AB04LDU	 BUFFER[1713]	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define idA1AB04LDU	 733	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define A1AB02LDU	 BUFFER[1715]	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define idA1AB02LDU	 734	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define A1AB01LDU	 BUFFER[1717]	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define idA1AB01LDU	 735	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define A1VS22LDU	 BUFFER[1719]	//( - , DU) Движение ББ1 в сторону НУ
#define idA1VS22LDU	 736	//( - , DU) Движение ББ1 в сторону НУ
#define A1AZ03LDU	 BUFFER[1721]	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define idA1AZ03LDU	 737	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define A1AD11LDU	 BUFFER[1723]	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 738	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define A1AD21LDU	 BUFFER[1725]	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 739	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define A1AD02LDU	 BUFFER[1727]	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define idA1AD02LDU	 740	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[1729]	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define idA1AD03LDU	 741	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define A1AD04LDU	 BUFFER[1731]	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define idA1AD04LDU	 742	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define A1AD05LDU	 BUFFER[1733]	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define idA1AD05LDU	 743	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define A1AD01LDU	 BUFFER[1735]	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define idA1AD01LDU	 744	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define A1CV02RDU	 BUFFER[1737]	//( - , DU) Заданная скорость перемещения ББ1
#define idA1CV02RDU	 745	//( - , DU) Заданная скорость перемещения ББ1
#define A1AB07LDU	 BUFFER[1742]	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define idA1AB07LDU	 746	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define A1AB08LDU	 BUFFER[1744]	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define idA1AB08LDU	 747	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define A1AB05LDU	 BUFFER[1746]	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define idA1AB05LDU	 748	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define A1AB06LDU	 BUFFER[1748]	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA1AB06LDU	 749	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define A1AB09LDU	 BUFFER[1750]	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define idA1AB09LDU	 750	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define A1AB10LDU	 BUFFER[1752]	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define idA1AB10LDU	 751	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define A1AB11LDU	 BUFFER[1754]	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define idA1AB11LDU	 752	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define A1AB12LDU	 BUFFER[1756]	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA1AB12LDU	 753	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A1AB13LDU	 BUFFER[1758]	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define idA1AB13LDU	 754	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define A1AB14LDU	 BUFFER[1760]	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define idA1AB14LDU	 755	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define fEM_A1UC03RDU	 BUFFER[1762]	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define idfEM_A1UC03RDU	 756	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define dEM_A1UC05UDU	 BUFFER[1767]	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC05UDU	 757	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define dEM_A1UC06UDU	 BUFFER[1772]	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC06UDU	 758	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define dEM_A2UC06UDU	 BUFFER[1777]	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC06UDU	 759	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define dEM_A2UC05UDU	 BUFFER[1782]	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC05UDU	 760	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define fEM_A2UC03RDU	 BUFFER[1787]	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define idfEM_A2UC03RDU	 761	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define dEM_A3UC06UDU	 BUFFER[1792]	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC06UDU	 762	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define dEM_A3UC05UDU	 BUFFER[1797]	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC05UDU	 763	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define fEM_A3UC03RDU	 BUFFER[1802]	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define idfEM_A3UC03RDU	 764	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define dEM_A8UC06UDU	 BUFFER[1807]	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define iddEM_A8UC06UDU	 765	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define fEM_A8UC03RDU	 BUFFER[1812]	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define idfEM_A8UC03RDU	 766	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define dEM_A8UC05UDU	 BUFFER[1817]	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define iddEM_A8UC05UDU	 767	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define fEM_R0UV81RDU	 BUFFER[1822]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 768	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1827]	//(R0UV82RDU) 2-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 769	//(R0UV82RDU) 2-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1832]	//(R0UV83RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 770	//(R0UV83RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1837]	//(R0UV84RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 771	//(R0UV84RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1842]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 772	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1847]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 773	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV87RDU	 BUFFER[1852]	//(R0UV87RDU) 8-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 774	//(R0UV87RDU) 8-я скорость перемещения ББ (шагов/секунду)
#define fEM_A3UP03RDU	 BUFFER[1857]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 775	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1862]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 776	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP43RDU	 BUFFER[1867]	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define idfEM_A3UP43RDU	 777	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define fEM_A3UP44RDU	 BUFFER[1872]	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP44RDU	 778	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP53RDU	 BUFFER[1877]	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP53RDU	 779	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP85RDU	 BUFFER[1882]	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP85RDU	 780	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP88RDU	 BUFFER[1887]	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP88RDU	 781	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP86RDU	 BUFFER[1892]	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP86RDU	 782	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_B8UV01RDU	 BUFFER[1897]	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define idfEM_B8UV01RDU	 783	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define fEM_B8UV02RDU	 BUFFER[1902]	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define idfEM_B8UV02RDU	 784	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define fEM_B8UV03RDU	 BUFFER[1907]	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define idfEM_B8UV03RDU	 785	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define fEM_B8UL04RDU	 BUFFER[1912]	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define idfEM_B8UL04RDU	 786	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define iEM_A2UV03CDU	 BUFFER[1917]	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define idiEM_A2UV03CDU	 787	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define fEM_A2UV01RDU	 BUFFER[1920]	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define idfEM_A2UV01RDU	 788	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define fEM_A2UV02RDU	 BUFFER[1925]	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define idfEM_A2UV02RDU	 789	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define fEM_A1UV01RDU	 BUFFER[1930]	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define idfEM_A1UV01RDU	 790	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define fEM_A1UV02RDU	 BUFFER[1935]	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define idfEM_A1UV02RDU	 791	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define fEM_A1UC06RDU	 BUFFER[1940]	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define idfEM_A1UC06RDU	 792	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define fEM_A1UC05RDU	 BUFFER[1945]	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A1UC05RDU	 793	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A1UL04RDU	 BUFFER[1950]	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define idfEM_A1UL04RDU	 794	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define fEM_A3UV01RDU	 BUFFER[1955]	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define idfEM_A3UV01RDU	 795	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define fEM_A3UV02RDU	 BUFFER[1960]	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define idfEM_A3UV02RDU	 796	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define fEM_A3UC06RDU	 BUFFER[1965]	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define idfEM_A3UC06RDU	 797	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define fEM_A3UC05RDU	 BUFFER[1970]	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A3UC05RDU	 798	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A3UL04RDU	 BUFFER[1975]	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define idfEM_A3UL04RDU	 799	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define fEM_A3UP54RDU	 BUFFER[1980]	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define idfEM_A3UP54RDU	 800	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define fEM_A3UP87RDU	 BUFFER[1985]	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP87RDU	 801	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_R0UL05RDU	 BUFFER[1990]	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define idfEM_R0UL05RDU	 802	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define fEM_R0UL20RDU	 BUFFER[1995]	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define idfEM_R0UL20RDU	 803	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define fEM_B8UV04RDU	 BUFFER[2000]	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define idfEM_B8UV04RDU	 804	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define fEM_B8UC06RDU	 BUFFER[2005]	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define idfEM_B8UC06RDU	 805	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define fEM_B8UC05RDU	 BUFFER[2010]	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_B8UC05RDU	 806	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL05RDU	 BUFFER[2015]	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define idfEM_A2UL05RDU	 807	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define fEM_A2UL03RDU	 BUFFER[2020]	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL03RDU	 808	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A2UC06RDU	 BUFFER[2025]	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define idfEM_A2UC06RDU	 809	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define fEM_A2UC05RDU	 BUFFER[2030]	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A2UC05RDU	 810	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL04RDU	 BUFFER[2035]	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define idfEM_A2UL04RDU	 811	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define fEM_A1UL03RDU	 BUFFER[2040]	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define idfEM_A1UL03RDU	 812	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define fEM_A1UL05RDU	 BUFFER[2045]	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define idfEM_A1UL05RDU	 813	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define fEM_A3UL03RDU	 BUFFER[2050]	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define idfEM_A3UL03RDU	 814	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define fEM_A3UL05RDU	 BUFFER[2055]	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define idfEM_A3UL05RDU	 815	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define fEM_A1UC08RDU	 BUFFER[2060]	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define idfEM_A1UC08RDU	 816	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define fEM_A3UC08RDU	 BUFFER[2065]	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define idfEM_A3UC08RDU	 817	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define fEM_A1UC07RDU	 BUFFER[2070]	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define idfEM_A1UC07RDU	 818	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define fEM_A1UL01RDU	 BUFFER[2075]	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A1UL01RDU	 819	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A3UC07RDU	 BUFFER[2080]	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define idfEM_A3UC07RDU	 820	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define fEM_A3UL01RDU	 BUFFER[2085]	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A3UL01RDU	 821	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A2UC08RDU	 BUFFER[2090]	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define idfEM_A2UC08RDU	 822	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define fEM_A2UC07RDU	 BUFFER[2095]	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define idfEM_A2UC07RDU	 823	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define fEM_A2UL01RDU	 BUFFER[2100]	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A2UL01RDU	 824	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UC01RDU	 BUFFER[2105]	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define idfEM_B8UC01RDU	 825	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define fEM_B8UL07RDU	 BUFFER[2110]	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define idfEM_B8UL07RDU	 826	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define fEM_B8UC02RDU	 BUFFER[2115]	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define idfEM_B8UC02RDU	 827	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define fEM_B8UL01RDU	 BUFFER[2120]	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_B8UL01RDU	 828	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UL05RDU	 BUFFER[2125]	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define idfEM_B8UL05RDU	 829	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define fEM_B8UL03RDU	 BUFFER[2130]	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define idfEM_B8UL03RDU	 830	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define fEM_B8UL06RDU	 BUFFER[2135]	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define idfEM_B8UL06RDU	 831	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define fEM_A9UZ03RDU	 BUFFER[2140]	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define idfEM_A9UZ03RDU	 832	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define fEM_A9UZ04RDU	 BUFFER[2145]	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define idfEM_A9UZ04RDU	 833	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define fEM_A9UZ05RDU	 BUFFER[2150]	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define idfEM_A9UZ05RDU	 834	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define fEM_R4UZ04RDU	 BUFFER[2155]	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define idfEM_R4UZ04RDU	 835	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define fEM_R4UZ03RDU	 BUFFER[2160]	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define idfEM_R4UZ03RDU	 836	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define fEM_R4UZ05RDU	 BUFFER[2165]	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define idfEM_R4UZ05RDU	 837	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define fEM_A5UZ03RDU	 BUFFER[2170]	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define idfEM_A5UZ03RDU	 838	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define fEM_A5UZ04RDU	 BUFFER[2175]	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define idfEM_A5UZ04RDU	 839	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define fEM_A5UZ05RDU	 BUFFER[2180]	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define idfEM_A5UZ05RDU	 840	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define fEM_A4UZ03RDU	 BUFFER[2185]	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define idfEM_A4UZ03RDU	 841	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define fEM_A4UZ04RDU	 BUFFER[2190]	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define idfEM_A4UZ04RDU	 842	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define fEM_A4UZ05RDU	 BUFFER[2195]	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define idfEM_A4UZ05RDU	 843	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define fEM_A6UZ03RDU	 BUFFER[2200]	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define idfEM_A6UZ03RDU	 844	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define fEM_A6UZ04RDU	 BUFFER[2205]	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define idfEM_A6UZ04RDU	 845	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define fEM_A6UZ05RDU	 BUFFER[2210]	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define idfEM_A6UZ05RDU	 846	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define fEM_R1UZ03RDU	 BUFFER[2215]	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define idfEM_R1UZ03RDU	 847	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define fEM_R1UZ04RDU	 BUFFER[2220]	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define idfEM_R1UZ04RDU	 848	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define fEM_R1UZ05RDU	 BUFFER[2225]	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define idfEM_R1UZ05RDU	 849	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define fEM_R0UL04RDU	 BUFFER[2230]	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define idfEM_R0UL04RDU	 850	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define fEM_R0UL06RDU	 BUFFER[2235]	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define idfEM_R0UL06RDU	 851	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define fEM_R0UL03RDU	 BUFFER[2240]	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define idfEM_R0UL03RDU	 852	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define fEM_R0UL17RDU	 BUFFER[2245]	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define idfEM_R0UL17RDU	 853	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define fEM_R0UL19RDU	 BUFFER[2250]	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL19RDU	 854	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define fEM_R0UL07RDU	 BUFFER[2255]	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define idfEM_R0UL07RDU	 855	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define fEM_R0UL18RDU	 BUFFER[2260]	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define idfEM_R0UL18RDU	 856	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define fEM_R0UL16RDU	 BUFFER[2265]	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define idfEM_R0UL16RDU	 857	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define fEM_R0UL02RDU	 BUFFER[2270]	//(R0UL02RDU) Время задержки  ИНИ
#define idfEM_R0UL02RDU	 858	//(R0UL02RDU) Время задержки  ИНИ
#define fEM_R0UN08RDU	 BUFFER[2275]	//(R0UN08RDU) 8-я заданная мощность
#define idfEM_R0UN08RDU	 859	//(R0UN08RDU) 8-я заданная мощность
#define fEM_R0UN07RDU	 BUFFER[2280]	//(R0UN07RDU) 7-я заданная мощность
#define idfEM_R0UN07RDU	 860	//(R0UN07RDU) 7-я заданная мощность
#define fEM_R0UN06RDU	 BUFFER[2285]	//(R0UN06RDU) 6-я заданная мощность
#define idfEM_R0UN06RDU	 861	//(R0UN06RDU) 6-я заданная мощность
#define fEM_R0UN05RDU	 BUFFER[2290]	//(R0UN05RDU) 5-я заданная мощность
#define idfEM_R0UN05RDU	 862	//(R0UN05RDU) 5-я заданная мощность
#define fEM_R0UN04RDU	 BUFFER[2295]	//(R0UN04RDU) 4-я заданная мощность
#define idfEM_R0UN04RDU	 863	//(R0UN04RDU) 4-я заданная мощность
#define fEM_R0UN03RDU	 BUFFER[2300]	//(R0UN03RDU) Ограничение 3 по мощности
#define idfEM_R0UN03RDU	 864	//(R0UN03RDU) Ограничение 3 по мощности
#define fEM_R0UN02RDU	 BUFFER[2305]	//(R0UN02RDU) 2-я заданная мощность
#define idfEM_R0UN02RDU	 865	//(R0UN02RDU) 2-я заданная мощность
#define fEM_R0UN01RDU	 BUFFER[2310]	//(R0UN01RDU) 1-я заданная мощность
#define idfEM_R0UN01RDU	 866	//(R0UN01RDU) 1-я заданная мощность
#define fEM_A2UC82RDU	 BUFFER[2315]	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC82RDU	 867	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define fEM_A2UC83RDU	 BUFFER[2320]	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define idfEM_A2UC83RDU	 868	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define fEM_A1UC83RDU	 BUFFER[2325]	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define idfEM_A1UC83RDU	 869	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define fEM_A2UC81RDU	 BUFFER[2330]	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC81RDU	 870	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define fEM_A1UC81RDU	 BUFFER[2335]	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC81RDU	 871	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define fEM_A1UC82RDU	 BUFFER[2340]	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC82RDU	 872	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define fEM_A2UL83RDU	 BUFFER[2345]	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL83RDU	 873	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A3UC81RDU	 BUFFER[2350]	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define idfEM_A3UC81RDU	 874	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define fEM_A3UC82RDU	 BUFFER[2355]	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define idfEM_A3UC82RDU	 875	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define fEM_R0UN80RDU	 BUFFER[2360]	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define idfEM_R0UN80RDU	 876	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define iEM_A2UV01IDU	 BUFFER[2365]	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV01IDU	 877	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define iEM_A2UV02IDU	 BUFFER[2368]	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV02IDU	 878	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define iEM_A1UV01IDU	 BUFFER[2371]	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV01IDU	 879	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define iEM_A1UV02IDU	 BUFFER[2374]	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV02IDU	 880	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define iEM_A1UV03IDU	 BUFFER[2377]	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define idiEM_A1UV03IDU	 881	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define iEM_A3UV01IDU	 BUFFER[2380]	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define idiEM_A3UV01IDU	 882	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define iEM_A3UV02IDU	 BUFFER[2383]	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define idiEM_A3UV02IDU	 883	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define lEM_R0MD01LC1	 BUFFER[2386]	//(R0MD01LC1) Ручное управление ОРР
#define idlEM_R0MD01LC1	 884	//(R0MD01LC1) Ручное управление ОРР
#define fEM_A3UC09RDU	 BUFFER[2388]	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC09RDU	 885	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define fEM_A2UC02RDU	 BUFFER[2393]	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define idfEM_A2UC02RDU	 886	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define fEM_A1UC02RDU	 BUFFER[2398]	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define idfEM_A1UC02RDU	 887	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define fEM_A3UC02RDU	 BUFFER[2403]	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define idfEM_A3UC02RDU	 888	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define fEM_R0UL21RDU	 BUFFER[2408]	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define idfEM_R0UL21RDU	 889	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define fEM_R0UN09RDU	 BUFFER[2413]	//(R0UN09RDU) Минимальный период при регулировании мощности
#define idfEM_R0UN09RDU	 890	//(R0UN09RDU) Минимальный период при регулировании мощности
#define fEM_R0UN11RDU	 BUFFER[2418]	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define idfEM_R0UN11RDU	 891	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define fEM_R0UN12RDU	 BUFFER[2423]	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define idfEM_R0UN12RDU	 892	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define fEM_R0UN13RDU	 BUFFER[2428]	//(R0UN13RDU) Минимальное изменение координаты, мм
#define idfEM_R0UN13RDU	 893	//(R0UN13RDU) Минимальное изменение координаты, мм
#define fEM_R0UN14RDU	 BUFFER[2433]	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define idfEM_R0UN14RDU	 894	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define fEM_R0UN16RDU	 BUFFER[2438]	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN16RDU	 895	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN17RDU	 BUFFER[2443]	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN17RDU	 896	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN18RDU	 BUFFER[2448]	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define idfEM_R0UN18RDU	 897	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define fEM_R0UN19RDU	 BUFFER[2453]	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define idfEM_R0UN19RDU	 898	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define fEM_R0UN70LDU	 BUFFER[2458]	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN70LDU	 899	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN71LDU	 BUFFER[2463]	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN71LDU	 900	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN72LDU	 BUFFER[2468]	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN72LDU	 901	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN73LDU	 BUFFER[2473]	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN73LDU	 902	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN74LDU	 BUFFER[2478]	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN74LDU	 903	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN75LDU	 BUFFER[2483]	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN75LDU	 904	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN80LDU	 BUFFER[2488]	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN80LDU	 905	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define fEM_R0UN81LDU	 BUFFER[2493]	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN81LDU	 906	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define fEM_R0UN82LDU	 BUFFER[2498]	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN82LDU	 907	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define fEM_R0UN83LDU	 BUFFER[2503]	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN83LDU	 908	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define fEM_R0UN84LDU	 BUFFER[2508]	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN84LDU	 909	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define fEM_R0UN85LDU	 BUFFER[2513]	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN85LDU	 910	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define fEM_R0UT20RDU	 BUFFER[2518]	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define idfEM_R0UT20RDU	 911	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define fEM_R0UN25RDU	 BUFFER[2523]	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define idfEM_R0UN25RDU	 912	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define fEM_R0UN15RDU	 BUFFER[2528]	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define idfEM_R0UN15RDU	 913	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define fEM_R0UN26RDU	 BUFFER[2533]	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN26RDU	 914	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN27RDU	 BUFFER[2538]	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN27RDU	 915	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN24RDU	 BUFFER[2543]	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN24RDU	 916	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R0UL25RDU	 BUFFER[2548]	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL25RDU	 917	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define fEM_R0UL01RSS	 BUFFER[2553]	//(R0UL01RSS) Шаг измерения периода (сек)
#define idfEM_R0UL01RSS	 918	//(R0UL01RSS) Шаг измерения периода (сек)
#define fEM_R0UL02RSS	 BUFFER[2558]	//(R0UL02RSS) Tф-постоянная времени, с
#define idfEM_R0UL02RSS	 919	//(R0UL02RSS) Tф-постоянная времени, с
#define fEM_R0UN03RSS	 BUFFER[2563]	//(R0UN03RSS) нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN03RSS	 920	//(R0UN03RSS) нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R7UI76RDU	 BUFFER[2568]	//(R7UI76RDU) Время срабатывания сигнала II УР при имитации
#define idfEM_R7UI76RDU	 921	//(R7UI76RDU) Время срабатывания сигнала II УР при имитации
#define fEM_R0UL00RDU	 BUFFER[2573]	//(R0UL00RDU) Время ожидания передачи  сигнала отключения сети
#define idfEM_R0UL00RDU	 922	//(R0UL00RDU) Время ожидания передачи  сигнала отключения сети
#define bFirstEnterFlag	 BUFFER[2578]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 923	//(bFirstEnterFlag) 
#define internal2_m182_tx	 BUFFER[2580]	//(internal2_m182_tx) tx - время накопленное сек
#define idinternal2_m182_tx	 924	//(internal2_m182_tx) tx - время накопленное сек
#define internal2_m182_y0	 BUFFER[2585]	//(internal2_m182_y0) y0
#define idinternal2_m182_y0	 925	//(internal2_m182_y0) y0
#define internal2_m176_tx	 BUFFER[2586]	//(internal2_m176_tx) tx - время накопленное сек
#define idinternal2_m176_tx	 926	//(internal2_m176_tx) tx - время накопленное сек
#define internal2_m176_y0	 BUFFER[2591]	//(internal2_m176_y0) y0
#define idinternal2_m176_y0	 927	//(internal2_m176_y0) y0
#define internal2_m173_tx	 BUFFER[2592]	//(internal2_m173_tx) tx - время накопленное сек
#define idinternal2_m173_tx	 928	//(internal2_m173_tx) tx - время накопленное сек
#define internal2_m173_y0	 BUFFER[2597]	//(internal2_m173_y0) y0
#define idinternal2_m173_y0	 929	//(internal2_m173_y0) y0
#define internal2_m165_tx	 BUFFER[2598]	//(internal2_m165_tx) tx - время накопленное сек
#define idinternal2_m165_tx	 930	//(internal2_m165_tx) tx - время накопленное сек
#define internal2_m165_y0	 BUFFER[2603]	//(internal2_m165_y0) y0
#define idinternal2_m165_y0	 931	//(internal2_m165_y0) y0
#define internal2_m158_tx	 BUFFER[2604]	//(internal2_m158_tx) tx - время накопленное сек
#define idinternal2_m158_tx	 932	//(internal2_m158_tx) tx - время накопленное сек
#define internal2_m158_y0	 BUFFER[2609]	//(internal2_m158_y0) y0
#define idinternal2_m158_y0	 933	//(internal2_m158_y0) y0
#define internal2_m155_tx	 BUFFER[2610]	//(internal2_m155_tx) tx - время накопленное сек
#define idinternal2_m155_tx	 934	//(internal2_m155_tx) tx - время накопленное сек
#define internal2_m155_y0	 BUFFER[2615]	//(internal2_m155_y0) y0
#define idinternal2_m155_y0	 935	//(internal2_m155_y0) y0
#define internal2_m149_tx	 BUFFER[2616]	//(internal2_m149_tx) tx - время накопленное сек
#define idinternal2_m149_tx	 936	//(internal2_m149_tx) tx - время накопленное сек
#define internal2_m149_y0	 BUFFER[2621]	//(internal2_m149_y0) y0
#define idinternal2_m149_y0	 937	//(internal2_m149_y0) y0
#define internal2_m144_tx	 BUFFER[2622]	//(internal2_m144_tx) tx - время накопленное сек
#define idinternal2_m144_tx	 938	//(internal2_m144_tx) tx - время накопленное сек
#define internal2_m144_y0	 BUFFER[2627]	//(internal2_m144_y0) y0
#define idinternal2_m144_y0	 939	//(internal2_m144_y0) y0
#define internal2_m141_tx	 BUFFER[2628]	//(internal2_m141_tx) tx - время накопленное сек
#define idinternal2_m141_tx	 940	//(internal2_m141_tx) tx - время накопленное сек
#define internal2_m141_y0	 BUFFER[2633]	//(internal2_m141_y0) y0
#define idinternal2_m141_y0	 941	//(internal2_m141_y0) y0
#define internal2_m134_tx	 BUFFER[2634]	//(internal2_m134_tx) tx - время накопленное сек
#define idinternal2_m134_tx	 942	//(internal2_m134_tx) tx - время накопленное сек
#define internal2_m134_y0	 BUFFER[2639]	//(internal2_m134_y0) y0
#define idinternal2_m134_y0	 943	//(internal2_m134_y0) y0
#define internal2_m132_tx	 BUFFER[2640]	//(internal2_m132_tx) tx - время накопленное сек
#define idinternal2_m132_tx	 944	//(internal2_m132_tx) tx - время накопленное сек
#define internal2_m132_y0	 BUFFER[2645]	//(internal2_m132_y0) y0
#define idinternal2_m132_y0	 945	//(internal2_m132_y0) y0
#define internal2_m127_tx	 BUFFER[2646]	//(internal2_m127_tx) tx - время накопленное сек
#define idinternal2_m127_tx	 946	//(internal2_m127_tx) tx - время накопленное сек
#define internal2_m127_y0	 BUFFER[2651]	//(internal2_m127_y0) y0
#define idinternal2_m127_y0	 947	//(internal2_m127_y0) y0
#define internal2_m195_y0	 BUFFER[2652]	//(internal2_m195_y0) y0
#define idinternal2_m195_y0	 948	//(internal2_m195_y0) y0
#define internal2_m193_y0	 BUFFER[2657]	//(internal2_m193_y0) y0
#define idinternal2_m193_y0	 949	//(internal2_m193_y0) y0
#define internal2_m228_y0	 BUFFER[2662]	//(internal2_m228_y0) state
#define idinternal2_m228_y0	 950	//(internal2_m228_y0) state
#define internal2_m220_y0	 BUFFER[2664]	//(internal2_m220_y0) state
#define idinternal2_m220_y0	 951	//(internal2_m220_y0) state
#define internal2_m208_y1	 BUFFER[2666]	//(internal2_m208_y1) y1 - внутренний параметр
#define idinternal2_m208_y1	 952	//(internal2_m208_y1) y1 - внутренний параметр
#define internal2_m214_y1	 BUFFER[2668]	//(internal2_m214_y1) y1 - внутренний параметр
#define idinternal2_m214_y1	 953	//(internal2_m214_y1) y1 - внутренний параметр
#define internal2_m198_y1	 BUFFER[2670]	//(internal2_m198_y1) y1 - внутренний параметр
#define idinternal2_m198_y1	 954	//(internal2_m198_y1) y1 - внутренний параметр
#define internal2_m205_y1	 BUFFER[2672]	//(internal2_m205_y1) y1 - внутренний параметр
#define idinternal2_m205_y1	 955	//(internal2_m205_y1) y1 - внутренний параметр
#define internal2_m17_Nk0	 BUFFER[2674]	//(internal2_m17_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m17_Nk0	 956	//(internal2_m17_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m17_SetFlag	 BUFFER[2679]	//(internal2_m17_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m17_SetFlag	 957	//(internal2_m17_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m110_Nk0	 BUFFER[2681]	//(internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m110_Nk0	 958	//(internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m110_SetFlag	 BUFFER[2686]	//(internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m110_SetFlag	 959	//(internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m106_Nk0	 BUFFER[2688]	//(internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m106_Nk0	 960	//(internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m106_SetFlag	 BUFFER[2693]	//(internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m106_SetFlag	 961	//(internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m75_Nk0	 BUFFER[2695]	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m75_Nk0	 962	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m75_SetFlag	 BUFFER[2700]	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m75_SetFlag	 963	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m77_Nk0	 BUFFER[2702]	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m77_Nk0	 964	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m77_SetFlag	 BUFFER[2707]	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m77_SetFlag	 965	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m49_Nk0	 BUFFER[2709]	//(internal2_m49_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m49_Nk0	 966	//(internal2_m49_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m49_SetFlag	 BUFFER[2714]	//(internal2_m49_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m49_SetFlag	 967	//(internal2_m49_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m53_Nk0	 BUFFER[2716]	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m53_Nk0	 968	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m53_SetFlag	 BUFFER[2721]	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m53_SetFlag	 969	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m15_Nk0	 BUFFER[2723]	//(internal2_m15_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m15_Nk0	 970	//(internal2_m15_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m15_SetFlag	 BUFFER[2728]	//(internal2_m15_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m15_SetFlag	 971	//(internal2_m15_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal1_m2562_tx	 BUFFER[2730]	//(internal1_m2562_tx) tx - время накопленное сек
#define idinternal1_m2562_tx	 972	//(internal1_m2562_tx) tx - время накопленное сек
#define internal1_m2562_y0	 BUFFER[2735]	//(internal1_m2562_y0) y0
#define idinternal1_m2562_y0	 973	//(internal1_m2562_y0) y0
#define internal1_m2560_tx	 BUFFER[2736]	//(internal1_m2560_tx) tx - время накопленное сек
#define idinternal1_m2560_tx	 974	//(internal1_m2560_tx) tx - время накопленное сек
#define internal1_m2560_y0	 BUFFER[2741]	//(internal1_m2560_y0) y0
#define idinternal1_m2560_y0	 975	//(internal1_m2560_y0) y0
#define internal1_m2558_tx	 BUFFER[2742]	//(internal1_m2558_tx) tx - время накопленное сек
#define idinternal1_m2558_tx	 976	//(internal1_m2558_tx) tx - время накопленное сек
#define internal1_m2558_y0	 BUFFER[2747]	//(internal1_m2558_y0) y0
#define idinternal1_m2558_y0	 977	//(internal1_m2558_y0) y0
#define internal1_m2554_tx	 BUFFER[2748]	//(internal1_m2554_tx) tx - время накопленное сек
#define idinternal1_m2554_tx	 978	//(internal1_m2554_tx) tx - время накопленное сек
#define internal1_m2554_y0	 BUFFER[2753]	//(internal1_m2554_y0) y0
#define idinternal1_m2554_y0	 979	//(internal1_m2554_y0) y0
#define internal1_m2552_tx	 BUFFER[2754]	//(internal1_m2552_tx) tx - время накопленное сек
#define idinternal1_m2552_tx	 980	//(internal1_m2552_tx) tx - время накопленное сек
#define internal1_m2552_y0	 BUFFER[2759]	//(internal1_m2552_y0) y0
#define idinternal1_m2552_y0	 981	//(internal1_m2552_y0) y0
#define internal1_m2556_tx	 BUFFER[2760]	//(internal1_m2556_tx) tx - время накопленное сек
#define idinternal1_m2556_tx	 982	//(internal1_m2556_tx) tx - время накопленное сек
#define internal1_m2556_y0	 BUFFER[2765]	//(internal1_m2556_y0) y0
#define idinternal1_m2556_y0	 983	//(internal1_m2556_y0) y0
#define internal1_m2550_tx	 BUFFER[2766]	//(internal1_m2550_tx) tx - время накопленное сек
#define idinternal1_m2550_tx	 984	//(internal1_m2550_tx) tx - время накопленное сек
#define internal1_m2550_y0	 BUFFER[2771]	//(internal1_m2550_y0) y0
#define idinternal1_m2550_y0	 985	//(internal1_m2550_y0) y0
#define internal1_m2548_tx	 BUFFER[2772]	//(internal1_m2548_tx) tx - время накопленное сек
#define idinternal1_m2548_tx	 986	//(internal1_m2548_tx) tx - время накопленное сек
#define internal1_m2548_y0	 BUFFER[2777]	//(internal1_m2548_y0) y0
#define idinternal1_m2548_y0	 987	//(internal1_m2548_y0) y0
#define internal1_m2582_tx	 BUFFER[2778]	//(internal1_m2582_tx) tx - время накопленное сек
#define idinternal1_m2582_tx	 988	//(internal1_m2582_tx) tx - время накопленное сек
#define internal1_m2582_y0	 BUFFER[2783]	//(internal1_m2582_y0) y0
#define idinternal1_m2582_y0	 989	//(internal1_m2582_y0) y0
#define internal1_m2590_tx	 BUFFER[2784]	//(internal1_m2590_tx) tx - время накопленное сек
#define idinternal1_m2590_tx	 990	//(internal1_m2590_tx) tx - время накопленное сек
#define internal1_m2590_y0	 BUFFER[2789]	//(internal1_m2590_y0) y0
#define idinternal1_m2590_y0	 991	//(internal1_m2590_y0) y0
#define internal1_m2588_tx	 BUFFER[2790]	//(internal1_m2588_tx) tx - время накопленное сек
#define idinternal1_m2588_tx	 992	//(internal1_m2588_tx) tx - время накопленное сек
#define internal1_m2588_y0	 BUFFER[2795]	//(internal1_m2588_y0) y0
#define idinternal1_m2588_y0	 993	//(internal1_m2588_y0) y0
#define internal1_m2586_tx	 BUFFER[2796]	//(internal1_m2586_tx) tx - время накопленное сек
#define idinternal1_m2586_tx	 994	//(internal1_m2586_tx) tx - время накопленное сек
#define internal1_m2586_y0	 BUFFER[2801]	//(internal1_m2586_y0) y0
#define idinternal1_m2586_y0	 995	//(internal1_m2586_y0) y0
#define internal1_m2584_tx	 BUFFER[2802]	//(internal1_m2584_tx) tx - время накопленное сек
#define idinternal1_m2584_tx	 996	//(internal1_m2584_tx) tx - время накопленное сек
#define internal1_m2584_y0	 BUFFER[2807]	//(internal1_m2584_y0) y0
#define idinternal1_m2584_y0	 997	//(internal1_m2584_y0) y0
#define internal1_m2580_tx	 BUFFER[2808]	//(internal1_m2580_tx) tx - время накопленное сек
#define idinternal1_m2580_tx	 998	//(internal1_m2580_tx) tx - время накопленное сек
#define internal1_m2580_y0	 BUFFER[2813]	//(internal1_m2580_y0) y0
#define idinternal1_m2580_y0	 999	//(internal1_m2580_y0) y0
#define internal1_m2578_tx	 BUFFER[2814]	//(internal1_m2578_tx) tx - время накопленное сек
#define idinternal1_m2578_tx	 1000	//(internal1_m2578_tx) tx - время накопленное сек
#define internal1_m2578_y0	 BUFFER[2819]	//(internal1_m2578_y0) y0
#define idinternal1_m2578_y0	 1001	//(internal1_m2578_y0) y0
#define internal1_m2576_tx	 BUFFER[2820]	//(internal1_m2576_tx) tx - время накопленное сек
#define idinternal1_m2576_tx	 1002	//(internal1_m2576_tx) tx - время накопленное сек
#define internal1_m2576_y0	 BUFFER[2825]	//(internal1_m2576_y0) y0
#define idinternal1_m2576_y0	 1003	//(internal1_m2576_y0) y0
#define internal1_m2574_tx	 BUFFER[2826]	//(internal1_m2574_tx) tx - время накопленное сек
#define idinternal1_m2574_tx	 1004	//(internal1_m2574_tx) tx - время накопленное сек
#define internal1_m2574_y0	 BUFFER[2831]	//(internal1_m2574_y0) y0
#define idinternal1_m2574_y0	 1005	//(internal1_m2574_y0) y0
#define internal1_m2572_tx	 BUFFER[2832]	//(internal1_m2572_tx) tx - время накопленное сек
#define idinternal1_m2572_tx	 1006	//(internal1_m2572_tx) tx - время накопленное сек
#define internal1_m2572_y0	 BUFFER[2837]	//(internal1_m2572_y0) y0
#define idinternal1_m2572_y0	 1007	//(internal1_m2572_y0) y0
#define internal1_m2570_tx	 BUFFER[2838]	//(internal1_m2570_tx) tx - время накопленное сек
#define idinternal1_m2570_tx	 1008	//(internal1_m2570_tx) tx - время накопленное сек
#define internal1_m2570_y0	 BUFFER[2843]	//(internal1_m2570_y0) y0
#define idinternal1_m2570_y0	 1009	//(internal1_m2570_y0) y0
#define internal1_m2568_tx	 BUFFER[2844]	//(internal1_m2568_tx) tx - время накопленное сек
#define idinternal1_m2568_tx	 1010	//(internal1_m2568_tx) tx - время накопленное сек
#define internal1_m2568_y0	 BUFFER[2849]	//(internal1_m2568_y0) y0
#define idinternal1_m2568_y0	 1011	//(internal1_m2568_y0) y0
#define internal1_m2566_tx	 BUFFER[2850]	//(internal1_m2566_tx) tx - время накопленное сек
#define idinternal1_m2566_tx	 1012	//(internal1_m2566_tx) tx - время накопленное сек
#define internal1_m2566_y0	 BUFFER[2855]	//(internal1_m2566_y0) y0
#define idinternal1_m2566_y0	 1013	//(internal1_m2566_y0) y0
#define internal1_m2564_tx	 BUFFER[2856]	//(internal1_m2564_tx) tx - время накопленное сек
#define idinternal1_m2564_tx	 1014	//(internal1_m2564_tx) tx - время накопленное сек
#define internal1_m2564_y0	 BUFFER[2861]	//(internal1_m2564_y0) y0
#define idinternal1_m2564_y0	 1015	//(internal1_m2564_y0) y0
#define internal1_m2097_x0	 BUFFER[2862]	//(internal1_m2097_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m2097_x0	 1016	//(internal1_m2097_x0) - значение входного параметра на предыдущем шаге
#define internal1_m2097_tim	 BUFFER[2864]	//(internal1_m2097_tim) - время задержки выходного сигнала
#define idinternal1_m2097_tim	 1017	//(internal1_m2097_tim) - время задержки выходного сигнала
#define internal1_m1673_tx	 BUFFER[2869]	//(internal1_m1673_tx) tx - время накопленное сек
#define idinternal1_m1673_tx	 1018	//(internal1_m1673_tx) tx - время накопленное сек
#define internal1_m1673_y0	 BUFFER[2874]	//(internal1_m1673_y0) y0
#define idinternal1_m1673_y0	 1019	//(internal1_m1673_y0) y0
#define internal1_m79_flst	 BUFFER[2875]	//(internal1_m79_flst)  флаг старта измерения
#define idinternal1_m79_flst	 1020	//(internal1_m79_flst)  флаг старта измерения
#define internal1_m79_chsr	 BUFFER[2878]	//(internal1_m79_chsr)  счетчик усреднения
#define idinternal1_m79_chsr	 1021	//(internal1_m79_chsr)  счетчик усреднения
#define internal1_m79_chizm	 BUFFER[2881]	//(internal1_m79_chizm)  счетчик уменьшения мощности
#define idinternal1_m79_chizm	 1022	//(internal1_m79_chizm)  счетчик уменьшения мощности
#define internal1_m79_sumtim	 BUFFER[2884]	//(internal1_m79_sumtim)  время измерения мощности
#define idinternal1_m79_sumtim	 1023	//(internal1_m79_sumtim)  время измерения мощности
#define internal1_m79_W1	 BUFFER[2889]	//(internal1_m79_W1)  мощность на старте измерения
#define idinternal1_m79_W1	 1024	//(internal1_m79_W1)  мощность на старте измерения
#define internal1_m79_W2	 BUFFER[2894]	//(internal1_m79_W2)  мощность в конце измерения
#define idinternal1_m79_W2	 1025	//(internal1_m79_W2)  мощность в конце измерения
#define internal1_m79_Wmin	 BUFFER[2899]	//(internal1_m79_Wmin)  минимальное измерение в серии
#define idinternal1_m79_Wmin	 1026	//(internal1_m79_Wmin)  минимальное измерение в серии
#define internal1_m79_Wmax	 BUFFER[2904]	//(internal1_m79_Wmax)  максимальное измерение в серии
#define idinternal1_m79_Wmax	 1027	//(internal1_m79_Wmax)  максимальное измерение в серии
#define internal1_m79_Wlast	 BUFFER[2909]	//(internal1_m79_Wlast)  последнее растущее измерение
#define idinternal1_m79_Wlast	 1028	//(internal1_m79_Wlast)  последнее растущее измерение
#define internal1_m79_y0	 BUFFER[2914]	//(internal1_m79_y0) y0 - внутренний параметр
#define idinternal1_m79_y0	 1029	//(internal1_m79_y0) y0 - внутренний параметр
#define internal1_m79_MyFirstEnterFlag	 BUFFER[2919]	//(internal1_m79_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m79_MyFirstEnterFlag	 1030	//(internal1_m79_MyFirstEnterFlag)  FirstEnterFlag
#define internal1_m2062_tx	 BUFFER[2921]	//(internal1_m2062_tx) tx - внутренний параметр
#define idinternal1_m2062_tx	 1031	//(internal1_m2062_tx) tx - внутренний параметр
#define internal1_m2061_tx	 BUFFER[2926]	//(internal1_m2061_tx) tx - внутренний параметр
#define idinternal1_m2061_tx	 1032	//(internal1_m2061_tx) tx - внутренний параметр
#define internal1_m781_tx	 BUFFER[2931]	//(internal1_m781_tx) tx - внутренний параметр
#define idinternal1_m781_tx	 1033	//(internal1_m781_tx) tx - внутренний параметр
#define internal1_m738_tx	 BUFFER[2936]	//(internal1_m738_tx) tx - внутренний параметр
#define idinternal1_m738_tx	 1034	//(internal1_m738_tx) tx - внутренний параметр
#define internal1_m795_tx	 BUFFER[2941]	//(internal1_m795_tx) tx - внутренний параметр
#define idinternal1_m795_tx	 1035	//(internal1_m795_tx) tx - внутренний параметр
#define internal1_m792_tx	 BUFFER[2946]	//(internal1_m792_tx) tx - внутренний параметр
#define idinternal1_m792_tx	 1036	//(internal1_m792_tx) tx - внутренний параметр
#define internal1_m791_tx	 BUFFER[2951]	//(internal1_m791_tx) tx - внутренний параметр
#define idinternal1_m791_tx	 1037	//(internal1_m791_tx) tx - внутренний параметр
#define internal1_m748_tx	 BUFFER[2956]	//(internal1_m748_tx) tx - внутренний параметр
#define idinternal1_m748_tx	 1038	//(internal1_m748_tx) tx - внутренний параметр
#define internal1_m731_tx	 BUFFER[2961]	//(internal1_m731_tx) tx - внутренний параметр
#define idinternal1_m731_tx	 1039	//(internal1_m731_tx) tx - внутренний параметр
#define internal1_m742_tx	 BUFFER[2966]	//(internal1_m742_tx) tx - внутренний параметр
#define idinternal1_m742_tx	 1040	//(internal1_m742_tx) tx - внутренний параметр
#define internal1_m773_tx	 BUFFER[2971]	//(internal1_m773_tx) tx - внутренний параметр
#define idinternal1_m773_tx	 1041	//(internal1_m773_tx) tx - внутренний параметр
#define internal1_m790_tx	 BUFFER[2976]	//(internal1_m790_tx) tx - внутренний параметр
#define idinternal1_m790_tx	 1042	//(internal1_m790_tx) tx - внутренний параметр
#define internal1_m763_tx	 BUFFER[2981]	//(internal1_m763_tx) tx - внутренний параметр
#define idinternal1_m763_tx	 1043	//(internal1_m763_tx) tx - внутренний параметр
#define internal1_m394_tx	 BUFFER[2986]	//(internal1_m394_tx) tx - внутренний параметр
#define idinternal1_m394_tx	 1044	//(internal1_m394_tx) tx - внутренний параметр
#define internal1_m393_tx	 BUFFER[2991]	//(internal1_m393_tx) tx - внутренний параметр
#define idinternal1_m393_tx	 1045	//(internal1_m393_tx) tx - внутренний параметр
#define internal1_m392_tx	 BUFFER[2996]	//(internal1_m392_tx) tx - внутренний параметр
#define idinternal1_m392_tx	 1046	//(internal1_m392_tx) tx - внутренний параметр
#define internal1_m391_tx	 BUFFER[3001]	//(internal1_m391_tx) tx - внутренний параметр
#define idinternal1_m391_tx	 1047	//(internal1_m391_tx) tx - внутренний параметр
#define internal1_m762_tx	 BUFFER[3006]	//(internal1_m762_tx) tx - внутренний параметр
#define idinternal1_m762_tx	 1048	//(internal1_m762_tx) tx - внутренний параметр
#define internal1_m757_tx	 BUFFER[3011]	//(internal1_m757_tx) tx - внутренний параметр
#define idinternal1_m757_tx	 1049	//(internal1_m757_tx) tx - внутренний параметр
#define internal1_m765_tx	 BUFFER[3016]	//(internal1_m765_tx) tx - внутренний параметр
#define idinternal1_m765_tx	 1050	//(internal1_m765_tx) tx - внутренний параметр
#define internal1_m771_tx	 BUFFER[3021]	//(internal1_m771_tx) tx - внутренний параметр
#define idinternal1_m771_tx	 1051	//(internal1_m771_tx) tx - внутренний параметр
#define internal1_m527_tx	 BUFFER[3026]	//(internal1_m527_tx) tx - внутренний параметр
#define idinternal1_m527_tx	 1052	//(internal1_m527_tx) tx - внутренний параметр
#define internal1_m526_tx	 BUFFER[3031]	//(internal1_m526_tx) tx - внутренний параметр
#define idinternal1_m526_tx	 1053	//(internal1_m526_tx) tx - внутренний параметр
#define internal1_m525_tx	 BUFFER[3036]	//(internal1_m525_tx) tx - внутренний параметр
#define idinternal1_m525_tx	 1054	//(internal1_m525_tx) tx - внутренний параметр
#define internal1_m521_tx	 BUFFER[3041]	//(internal1_m521_tx) tx - внутренний параметр
#define idinternal1_m521_tx	 1055	//(internal1_m521_tx) tx - внутренний параметр
#define internal1_m498_tx	 BUFFER[3046]	//(internal1_m498_tx) tx - внутренний параметр
#define idinternal1_m498_tx	 1056	//(internal1_m498_tx) tx - внутренний параметр
#define internal1_m497_tx	 BUFFER[3051]	//(internal1_m497_tx) tx - внутренний параметр
#define idinternal1_m497_tx	 1057	//(internal1_m497_tx) tx - внутренний параметр
#define internal1_m496_tx	 BUFFER[3056]	//(internal1_m496_tx) tx - внутренний параметр
#define idinternal1_m496_tx	 1058	//(internal1_m496_tx) tx - внутренний параметр
#define internal1_m499_tx	 BUFFER[3061]	//(internal1_m499_tx) tx - внутренний параметр
#define idinternal1_m499_tx	 1059	//(internal1_m499_tx) tx - внутренний параметр
#define internal1_m2468_tx	 BUFFER[3066]	//(internal1_m2468_tx) tx - внутренний параметр
#define idinternal1_m2468_tx	 1060	//(internal1_m2468_tx) tx - внутренний параметр
#define internal1_m2178_tx	 BUFFER[3071]	//(internal1_m2178_tx) tx - внутренний параметр
#define idinternal1_m2178_tx	 1061	//(internal1_m2178_tx) tx - внутренний параметр
#define internal1_m2467_tx	 BUFFER[3076]	//(internal1_m2467_tx) tx - внутренний параметр
#define idinternal1_m2467_tx	 1062	//(internal1_m2467_tx) tx - внутренний параметр
#define internal1_m2466_tx	 BUFFER[3081]	//(internal1_m2466_tx) tx - внутренний параметр
#define idinternal1_m2466_tx	 1063	//(internal1_m2466_tx) tx - внутренний параметр
#define internal1_m2464_tx	 BUFFER[3086]	//(internal1_m2464_tx) tx - внутренний параметр
#define idinternal1_m2464_tx	 1064	//(internal1_m2464_tx) tx - внутренний параметр
#define internal1_m108_tx	 BUFFER[3091]	//(internal1_m108_tx) tx - внутренний параметр
#define idinternal1_m108_tx	 1065	//(internal1_m108_tx) tx - внутренний параметр
#define internal1_m1144_tx	 BUFFER[3096]	//(internal1_m1144_tx) tx - внутренний параметр
#define idinternal1_m1144_tx	 1066	//(internal1_m1144_tx) tx - внутренний параметр
#define internal1_m2326_tx	 BUFFER[3101]	//(internal1_m2326_tx) tx - внутренний параметр
#define idinternal1_m2326_tx	 1067	//(internal1_m2326_tx) tx - внутренний параметр
#define internal1_m2325_tx	 BUFFER[3106]	//(internal1_m2325_tx) tx - внутренний параметр
#define idinternal1_m2325_tx	 1068	//(internal1_m2325_tx) tx - внутренний параметр
#define internal1_m2324_tx	 BUFFER[3111]	//(internal1_m2324_tx) tx - внутренний параметр
#define idinternal1_m2324_tx	 1069	//(internal1_m2324_tx) tx - внутренний параметр
#define internal1_m1256_tx	 BUFFER[3116]	//(internal1_m1256_tx) tx - внутренний параметр
#define idinternal1_m1256_tx	 1070	//(internal1_m1256_tx) tx - внутренний параметр
#define internal1_m1255_tx	 BUFFER[3121]	//(internal1_m1255_tx) tx - внутренний параметр
#define idinternal1_m1255_tx	 1071	//(internal1_m1255_tx) tx - внутренний параметр
#define internal1_m1251_tx	 BUFFER[3126]	//(internal1_m1251_tx) tx - внутренний параметр
#define idinternal1_m1251_tx	 1072	//(internal1_m1251_tx) tx - внутренний параметр
#define internal1_m1244_tx	 BUFFER[3131]	//(internal1_m1244_tx) tx - внутренний параметр
#define idinternal1_m1244_tx	 1073	//(internal1_m1244_tx) tx - внутренний параметр
#define internal1_m1242_tx	 BUFFER[3136]	//(internal1_m1242_tx) tx - внутренний параметр
#define idinternal1_m1242_tx	 1074	//(internal1_m1242_tx) tx - внутренний параметр
#define internal1_m1240_tx	 BUFFER[3141]	//(internal1_m1240_tx) tx - внутренний параметр
#define idinternal1_m1240_tx	 1075	//(internal1_m1240_tx) tx - внутренний параметр
#define internal1_m1238_tx	 BUFFER[3146]	//(internal1_m1238_tx) tx - внутренний параметр
#define idinternal1_m1238_tx	 1076	//(internal1_m1238_tx) tx - внутренний параметр
#define internal1_m1281_tx	 BUFFER[3151]	//(internal1_m1281_tx) tx - внутренний параметр
#define idinternal1_m1281_tx	 1077	//(internal1_m1281_tx) tx - внутренний параметр
#define internal1_m1288_tx	 BUFFER[3156]	//(internal1_m1288_tx) tx - внутренний параметр
#define idinternal1_m1288_tx	 1078	//(internal1_m1288_tx) tx - внутренний параметр
#define internal1_m1293_tx	 BUFFER[3161]	//(internal1_m1293_tx) tx - внутренний параметр
#define idinternal1_m1293_tx	 1079	//(internal1_m1293_tx) tx - внутренний параметр
#define internal1_m1299_tx	 BUFFER[3166]	//(internal1_m1299_tx) tx - внутренний параметр
#define idinternal1_m1299_tx	 1080	//(internal1_m1299_tx) tx - внутренний параметр
#define internal1_m1259_tx	 BUFFER[3171]	//(internal1_m1259_tx) tx - внутренний параметр
#define idinternal1_m1259_tx	 1081	//(internal1_m1259_tx) tx - внутренний параметр
#define internal1_m1280_tx	 BUFFER[3176]	//(internal1_m1280_tx) tx - внутренний параметр
#define idinternal1_m1280_tx	 1082	//(internal1_m1280_tx) tx - внутренний параметр
#define internal1_m1294_tx	 BUFFER[3181]	//(internal1_m1294_tx) tx - внутренний параметр
#define idinternal1_m1294_tx	 1083	//(internal1_m1294_tx) tx - внутренний параметр
#define internal1_m476_tx	 BUFFER[3186]	//(internal1_m476_tx) tx - внутренний параметр
#define idinternal1_m476_tx	 1084	//(internal1_m476_tx) tx - внутренний параметр
#define internal1_m470_tx	 BUFFER[3191]	//(internal1_m470_tx) tx - внутренний параметр
#define idinternal1_m470_tx	 1085	//(internal1_m470_tx) tx - внутренний параметр
#define internal1_m472_tx	 BUFFER[3196]	//(internal1_m472_tx) tx - внутренний параметр
#define idinternal1_m472_tx	 1086	//(internal1_m472_tx) tx - внутренний параметр
#define internal1_m474_tx	 BUFFER[3201]	//(internal1_m474_tx) tx - внутренний параметр
#define idinternal1_m474_tx	 1087	//(internal1_m474_tx) tx - внутренний параметр
#define internal1_m481_tx	 BUFFER[3206]	//(internal1_m481_tx) tx - внутренний параметр
#define idinternal1_m481_tx	 1088	//(internal1_m481_tx) tx - внутренний параметр
#define internal1_m435_tx	 BUFFER[3211]	//(internal1_m435_tx) tx - внутренний параметр
#define idinternal1_m435_tx	 1089	//(internal1_m435_tx) tx - внутренний параметр
#define internal1_m433_tx	 BUFFER[3216]	//(internal1_m433_tx) tx - внутренний параметр
#define idinternal1_m433_tx	 1090	//(internal1_m433_tx) tx - внутренний параметр
#define internal1_m434_tx	 BUFFER[3221]	//(internal1_m434_tx) tx - внутренний параметр
#define idinternal1_m434_tx	 1091	//(internal1_m434_tx) tx - внутренний параметр
#define internal1_m427_tx	 BUFFER[3226]	//(internal1_m427_tx) tx - внутренний параметр
#define idinternal1_m427_tx	 1092	//(internal1_m427_tx) tx - внутренний параметр
#define internal1_m889_tx	 BUFFER[3231]	//(internal1_m889_tx) tx - внутренний параметр
#define idinternal1_m889_tx	 1093	//(internal1_m889_tx) tx - внутренний параметр
#define internal1_m888_tx	 BUFFER[3236]	//(internal1_m888_tx) tx - внутренний параметр
#define idinternal1_m888_tx	 1094	//(internal1_m888_tx) tx - внутренний параметр
#define internal1_m887_tx	 BUFFER[3241]	//(internal1_m887_tx) tx - внутренний параметр
#define idinternal1_m887_tx	 1095	//(internal1_m887_tx) tx - внутренний параметр
#define internal1_m883_tx	 BUFFER[3246]	//(internal1_m883_tx) tx - внутренний параметр
#define idinternal1_m883_tx	 1096	//(internal1_m883_tx) tx - внутренний параметр
#define internal1_m1345_tx	 BUFFER[3251]	//(internal1_m1345_tx) tx - внутренний параметр
#define idinternal1_m1345_tx	 1097	//(internal1_m1345_tx) tx - внутренний параметр
#define internal1_m1344_tx	 BUFFER[3256]	//(internal1_m1344_tx) tx - внутренний параметр
#define idinternal1_m1344_tx	 1098	//(internal1_m1344_tx) tx - внутренний параметр
#define internal1_m1343_tx	 BUFFER[3261]	//(internal1_m1343_tx) tx - внутренний параметр
#define idinternal1_m1343_tx	 1099	//(internal1_m1343_tx) tx - внутренний параметр
#define internal1_m1556_tx	 BUFFER[3266]	//(internal1_m1556_tx) tx - внутренний параметр
#define idinternal1_m1556_tx	 1100	//(internal1_m1556_tx) tx - внутренний параметр
#define internal1_m1569_tx	 BUFFER[3271]	//(internal1_m1569_tx) tx - внутренний параметр
#define idinternal1_m1569_tx	 1101	//(internal1_m1569_tx) tx - внутренний параметр
#define internal1_m1568_tx	 BUFFER[3276]	//(internal1_m1568_tx) tx - внутренний параметр
#define idinternal1_m1568_tx	 1102	//(internal1_m1568_tx) tx - внутренний параметр
#define internal1_m1567_tx	 BUFFER[3281]	//(internal1_m1567_tx) tx - внутренний параметр
#define idinternal1_m1567_tx	 1103	//(internal1_m1567_tx) tx - внутренний параметр
#define internal1_m1558_tx	 BUFFER[3286]	//(internal1_m1558_tx) tx - внутренний параметр
#define idinternal1_m1558_tx	 1104	//(internal1_m1558_tx) tx - внутренний параметр
#define internal1_m2296_tx	 BUFFER[3291]	//(internal1_m2296_tx) tx - внутренний параметр
#define idinternal1_m2296_tx	 1105	//(internal1_m2296_tx) tx - внутренний параметр
#define internal1_m2279_tx	 BUFFER[3296]	//(internal1_m2279_tx) tx - внутренний параметр
#define idinternal1_m2279_tx	 1106	//(internal1_m2279_tx) tx - внутренний параметр
#define internal1_m2256_tx	 BUFFER[3301]	//(internal1_m2256_tx) tx - внутренний параметр
#define idinternal1_m2256_tx	 1107	//(internal1_m2256_tx) tx - внутренний параметр
#define internal1_m1566_tx	 BUFFER[3306]	//(internal1_m1566_tx) tx - внутренний параметр
#define idinternal1_m1566_tx	 1108	//(internal1_m1566_tx) tx - внутренний параметр
#define internal1_m1545_tx	 BUFFER[3311]	//(internal1_m1545_tx) tx - внутренний параметр
#define idinternal1_m1545_tx	 1109	//(internal1_m1545_tx) tx - внутренний параметр
#define internal1_m1544_tx	 BUFFER[3316]	//(internal1_m1544_tx) tx - внутренний параметр
#define idinternal1_m1544_tx	 1110	//(internal1_m1544_tx) tx - внутренний параметр
#define internal1_m1543_tx	 BUFFER[3321]	//(internal1_m1543_tx) tx - внутренний параметр
#define idinternal1_m1543_tx	 1111	//(internal1_m1543_tx) tx - внутренний параметр
#define internal1_m1565_tx	 BUFFER[3326]	//(internal1_m1565_tx) tx - внутренний параметр
#define idinternal1_m1565_tx	 1112	//(internal1_m1565_tx) tx - внутренний параметр
#define internal1_m1531_tx	 BUFFER[3331]	//(internal1_m1531_tx) tx - внутренний параметр
#define idinternal1_m1531_tx	 1113	//(internal1_m1531_tx) tx - внутренний параметр
#define internal1_m1533_tx	 BUFFER[3336]	//(internal1_m1533_tx) tx - внутренний параметр
#define idinternal1_m1533_tx	 1114	//(internal1_m1533_tx) tx - внутренний параметр
#define internal1_m1530_tx	 BUFFER[3341]	//(internal1_m1530_tx) tx - внутренний параметр
#define idinternal1_m1530_tx	 1115	//(internal1_m1530_tx) tx - внутренний параметр
#define internal1_m1503_tx	 BUFFER[3346]	//(internal1_m1503_tx) tx - внутренний параметр
#define idinternal1_m1503_tx	 1116	//(internal1_m1503_tx) tx - внутренний параметр
#define internal1_m1502_tx	 BUFFER[3351]	//(internal1_m1502_tx) tx - внутренний параметр
#define idinternal1_m1502_tx	 1117	//(internal1_m1502_tx) tx - внутренний параметр
#define internal1_m1511_tx	 BUFFER[3356]	//(internal1_m1511_tx) tx - внутренний параметр
#define idinternal1_m1511_tx	 1118	//(internal1_m1511_tx) tx - внутренний параметр
#define internal1_m1515_tx	 BUFFER[3361]	//(internal1_m1515_tx) tx - внутренний параметр
#define idinternal1_m1515_tx	 1119	//(internal1_m1515_tx) tx - внутренний параметр
#define internal1_m982_tx	 BUFFER[3366]	//(internal1_m982_tx) tx - внутренний параметр
#define idinternal1_m982_tx	 1120	//(internal1_m982_tx) tx - внутренний параметр
#define internal1_m985_tx	 BUFFER[3371]	//(internal1_m985_tx) tx - внутренний параметр
#define idinternal1_m985_tx	 1121	//(internal1_m985_tx) tx - внутренний параметр
#define internal1_m2247_tx	 BUFFER[3376]	//(internal1_m2247_tx) tx - внутренний параметр
#define idinternal1_m2247_tx	 1122	//(internal1_m2247_tx) tx - внутренний параметр
#define internal1_m975_tx	 BUFFER[3381]	//(internal1_m975_tx) tx - внутренний параметр
#define idinternal1_m975_tx	 1123	//(internal1_m975_tx) tx - внутренний параметр
#define internal1_m973_tx	 BUFFER[3386]	//(internal1_m973_tx) tx - внутренний параметр
#define idinternal1_m973_tx	 1124	//(internal1_m973_tx) tx - внутренний параметр
#define internal1_m981_tx	 BUFFER[3391]	//(internal1_m981_tx) tx - внутренний параметр
#define idinternal1_m981_tx	 1125	//(internal1_m981_tx) tx - внутренний параметр
#define internal1_m965_tx	 BUFFER[3396]	//(internal1_m965_tx) tx - внутренний параметр
#define idinternal1_m965_tx	 1126	//(internal1_m965_tx) tx - внутренний параметр
#define internal1_m963_tx	 BUFFER[3401]	//(internal1_m963_tx) tx - внутренний параметр
#define idinternal1_m963_tx	 1127	//(internal1_m963_tx) tx - внутренний параметр
#define internal1_m959_tx	 BUFFER[3406]	//(internal1_m959_tx) tx - внутренний параметр
#define idinternal1_m959_tx	 1128	//(internal1_m959_tx) tx - внутренний параметр
#define internal1_m980_tx	 BUFFER[3411]	//(internal1_m980_tx) tx - внутренний параметр
#define idinternal1_m980_tx	 1129	//(internal1_m980_tx) tx - внутренний параметр
#define internal1_m947_tx	 BUFFER[3416]	//(internal1_m947_tx) tx - внутренний параметр
#define idinternal1_m947_tx	 1130	//(internal1_m947_tx) tx - внутренний параметр
#define internal1_m948_tx	 BUFFER[3421]	//(internal1_m948_tx) tx - внутренний параметр
#define idinternal1_m948_tx	 1131	//(internal1_m948_tx) tx - внутренний параметр
#define internal1_m945_tx	 BUFFER[3426]	//(internal1_m945_tx) tx - внутренний параметр
#define idinternal1_m945_tx	 1132	//(internal1_m945_tx) tx - внутренний параметр
#define internal1_m633_tx	 BUFFER[3431]	//(internal1_m633_tx) tx - внутренний параметр
#define idinternal1_m633_tx	 1133	//(internal1_m633_tx) tx - внутренний параметр
#define internal1_m636_tx	 BUFFER[3436]	//(internal1_m636_tx) tx - внутренний параметр
#define idinternal1_m636_tx	 1134	//(internal1_m636_tx) tx - внутренний параметр
#define internal1_m635_tx	 BUFFER[3441]	//(internal1_m635_tx) tx - внутренний параметр
#define idinternal1_m635_tx	 1135	//(internal1_m635_tx) tx - внутренний параметр
#define internal1_m622_tx	 BUFFER[3446]	//(internal1_m622_tx) tx - внутренний параметр
#define idinternal1_m622_tx	 1136	//(internal1_m622_tx) tx - внутренний параметр
#define internal1_m621_tx	 BUFFER[3451]	//(internal1_m621_tx) tx - внутренний параметр
#define idinternal1_m621_tx	 1137	//(internal1_m621_tx) tx - внутренний параметр
#define internal1_m618_tx	 BUFFER[3456]	//(internal1_m618_tx) tx - внутренний параметр
#define idinternal1_m618_tx	 1138	//(internal1_m618_tx) tx - внутренний параметр
#define internal1_m631_tx	 BUFFER[3461]	//(internal1_m631_tx) tx - внутренний параметр
#define idinternal1_m631_tx	 1139	//(internal1_m631_tx) tx - внутренний параметр
#define internal1_m608_tx	 BUFFER[3466]	//(internal1_m608_tx) tx - внутренний параметр
#define idinternal1_m608_tx	 1140	//(internal1_m608_tx) tx - внутренний параметр
#define internal1_m607_tx	 BUFFER[3471]	//(internal1_m607_tx) tx - внутренний параметр
#define idinternal1_m607_tx	 1141	//(internal1_m607_tx) tx - внутренний параметр
#define internal1_m603_tx	 BUFFER[3476]	//(internal1_m603_tx) tx - внутренний параметр
#define idinternal1_m603_tx	 1142	//(internal1_m603_tx) tx - внутренний параметр
#define internal1_m634_tx	 BUFFER[3481]	//(internal1_m634_tx) tx - внутренний параметр
#define idinternal1_m634_tx	 1143	//(internal1_m634_tx) tx - внутренний параметр
#define internal1_m591_tx	 BUFFER[3486]	//(internal1_m591_tx) tx - внутренний параметр
#define idinternal1_m591_tx	 1144	//(internal1_m591_tx) tx - внутренний параметр
#define internal1_m590_tx	 BUFFER[3491]	//(internal1_m590_tx) tx - внутренний параметр
#define idinternal1_m590_tx	 1145	//(internal1_m590_tx) tx - внутренний параметр
#define internal1_m593_tx	 BUFFER[3496]	//(internal1_m593_tx) tx - внутренний параметр
#define idinternal1_m593_tx	 1146	//(internal1_m593_tx) tx - внутренний параметр
#define internal1_m570_tx	 BUFFER[3501]	//(internal1_m570_tx) tx - внутренний параметр
#define idinternal1_m570_tx	 1147	//(internal1_m570_tx) tx - внутренний параметр
#define internal1_m571_tx	 BUFFER[3506]	//(internal1_m571_tx) tx - внутренний параметр
#define idinternal1_m571_tx	 1148	//(internal1_m571_tx) tx - внутренний параметр
#define internal1_m572_tx	 BUFFER[3511]	//(internal1_m572_tx) tx - внутренний параметр
#define idinternal1_m572_tx	 1149	//(internal1_m572_tx) tx - внутренний параметр
#define internal1_m577_tx	 BUFFER[3516]	//(internal1_m577_tx) tx - внутренний параметр
#define idinternal1_m577_tx	 1150	//(internal1_m577_tx) tx - внутренний параметр
#define internal1_m2309_tx	 BUFFER[3521]	//(internal1_m2309_tx) tx - внутренний параметр
#define idinternal1_m2309_tx	 1151	//(internal1_m2309_tx) tx - внутренний параметр
#define internal1_m2310_tx	 BUFFER[3526]	//(internal1_m2310_tx) tx - внутренний параметр
#define idinternal1_m2310_tx	 1152	//(internal1_m2310_tx) tx - внутренний параметр
#define internal1_m2311_tx	 BUFFER[3531]	//(internal1_m2311_tx) tx - внутренний параметр
#define idinternal1_m2311_tx	 1153	//(internal1_m2311_tx) tx - внутренний параметр
#define internal1_m1788_tx	 BUFFER[3536]	//(internal1_m1788_tx) tx - внутренний параметр
#define idinternal1_m1788_tx	 1154	//(internal1_m1788_tx) tx - внутренний параметр
#define internal1_m1787_tx	 BUFFER[3541]	//(internal1_m1787_tx) tx - внутренний параметр
#define idinternal1_m1787_tx	 1155	//(internal1_m1787_tx) tx - внутренний параметр
#define internal1_m1782_tx	 BUFFER[3546]	//(internal1_m1782_tx) tx - внутренний параметр
#define idinternal1_m1782_tx	 1156	//(internal1_m1782_tx) tx - внутренний параметр
#define internal1_m1773_tx	 BUFFER[3551]	//(internal1_m1773_tx) tx - внутренний параметр
#define idinternal1_m1773_tx	 1157	//(internal1_m1773_tx) tx - внутренний параметр
#define internal1_m1771_tx	 BUFFER[3556]	//(internal1_m1771_tx) tx - внутренний параметр
#define idinternal1_m1771_tx	 1158	//(internal1_m1771_tx) tx - внутренний параметр
#define internal1_m1769_tx	 BUFFER[3561]	//(internal1_m1769_tx) tx - внутренний параметр
#define idinternal1_m1769_tx	 1159	//(internal1_m1769_tx) tx - внутренний параметр
#define internal1_m1768_tx	 BUFFER[3566]	//(internal1_m1768_tx) tx - внутренний параметр
#define idinternal1_m1768_tx	 1160	//(internal1_m1768_tx) tx - внутренний параметр
#define internal1_m1809_tx	 BUFFER[3571]	//(internal1_m1809_tx) tx - внутренний параметр
#define idinternal1_m1809_tx	 1161	//(internal1_m1809_tx) tx - внутренний параметр
#define internal1_m1817_tx	 BUFFER[3576]	//(internal1_m1817_tx) tx - внутренний параметр
#define idinternal1_m1817_tx	 1162	//(internal1_m1817_tx) tx - внутренний параметр
#define internal1_m1824_tx	 BUFFER[3581]	//(internal1_m1824_tx) tx - внутренний параметр
#define idinternal1_m1824_tx	 1163	//(internal1_m1824_tx) tx - внутренний параметр
#define internal1_m1825_tx	 BUFFER[3586]	//(internal1_m1825_tx) tx - внутренний параметр
#define idinternal1_m1825_tx	 1164	//(internal1_m1825_tx) tx - внутренний параметр
#define internal1_m1815_tx	 BUFFER[3591]	//(internal1_m1815_tx) tx - внутренний параметр
#define idinternal1_m1815_tx	 1165	//(internal1_m1815_tx) tx - внутренний параметр
#define internal1_m1790_tx	 BUFFER[3596]	//(internal1_m1790_tx) tx - внутренний параметр
#define idinternal1_m1790_tx	 1166	//(internal1_m1790_tx) tx - внутренний параметр
#define internal1_m1804_tx	 BUFFER[3601]	//(internal1_m1804_tx) tx - внутренний параметр
#define idinternal1_m1804_tx	 1167	//(internal1_m1804_tx) tx - внутренний параметр
#define internal1_m453_tx	 BUFFER[3606]	//(internal1_m453_tx) tx - внутренний параметр
#define idinternal1_m453_tx	 1168	//(internal1_m453_tx) tx - внутренний параметр
#define internal1_m444_tx	 BUFFER[3611]	//(internal1_m444_tx) tx - внутренний параметр
#define idinternal1_m444_tx	 1169	//(internal1_m444_tx) tx - внутренний параметр
#define internal1_m445_tx	 BUFFER[3616]	//(internal1_m445_tx) tx - внутренний параметр
#define idinternal1_m445_tx	 1170	//(internal1_m445_tx) tx - внутренний параметр
#define internal1_m447_tx	 BUFFER[3621]	//(internal1_m447_tx) tx - внутренний параметр
#define idinternal1_m447_tx	 1171	//(internal1_m447_tx) tx - внутренний параметр
#define internal1_m461_tx	 BUFFER[3626]	//(internal1_m461_tx) tx - внутренний параметр
#define idinternal1_m461_tx	 1172	//(internal1_m461_tx) tx - внутренний параметр
#define internal1_m411_tx	 BUFFER[3631]	//(internal1_m411_tx) tx - внутренний параметр
#define idinternal1_m411_tx	 1173	//(internal1_m411_tx) tx - внутренний параметр
#define internal1_m408_tx	 BUFFER[3636]	//(internal1_m408_tx) tx - внутренний параметр
#define idinternal1_m408_tx	 1174	//(internal1_m408_tx) tx - внутренний параметр
#define internal1_m407_tx	 BUFFER[3641]	//(internal1_m407_tx) tx - внутренний параметр
#define idinternal1_m407_tx	 1175	//(internal1_m407_tx) tx - внутренний параметр
#define internal1_m406_tx	 BUFFER[3646]	//(internal1_m406_tx) tx - внутренний параметр
#define idinternal1_m406_tx	 1176	//(internal1_m406_tx) tx - внутренний параметр
#define internal1_m866_tx	 BUFFER[3651]	//(internal1_m866_tx) tx - внутренний параметр
#define idinternal1_m866_tx	 1177	//(internal1_m866_tx) tx - внутренний параметр
#define internal1_m862_tx	 BUFFER[3656]	//(internal1_m862_tx) tx - внутренний параметр
#define idinternal1_m862_tx	 1178	//(internal1_m862_tx) tx - внутренний параметр
#define internal1_m861_tx	 BUFFER[3661]	//(internal1_m861_tx) tx - внутренний параметр
#define idinternal1_m861_tx	 1179	//(internal1_m861_tx) tx - внутренний параметр
#define internal1_m860_tx	 BUFFER[3666]	//(internal1_m860_tx) tx - внутренний параметр
#define idinternal1_m860_tx	 1180	//(internal1_m860_tx) tx - внутренний параметр
#define internal1_m1326_tx	 BUFFER[3671]	//(internal1_m1326_tx) tx - внутренний параметр
#define idinternal1_m1326_tx	 1181	//(internal1_m1326_tx) tx - внутренний параметр
#define internal1_m1323_tx	 BUFFER[3676]	//(internal1_m1323_tx) tx - внутренний параметр
#define idinternal1_m1323_tx	 1182	//(internal1_m1323_tx) tx - внутренний параметр
#define internal1_m1322_tx	 BUFFER[3681]	//(internal1_m1322_tx) tx - внутренний параметр
#define idinternal1_m1322_tx	 1183	//(internal1_m1322_tx) tx - внутренний параметр
#define internal1_m1083_tx	 BUFFER[3686]	//(internal1_m1083_tx) tx - внутренний параметр
#define idinternal1_m1083_tx	 1184	//(internal1_m1083_tx) tx - внутренний параметр
#define internal1_m2268_tx	 BUFFER[3691]	//(internal1_m2268_tx) tx - внутренний параметр
#define idinternal1_m2268_tx	 1185	//(internal1_m2268_tx) tx - внутренний параметр
#define internal1_m1094_tx	 BUFFER[3696]	//(internal1_m1094_tx) tx - внутренний параметр
#define idinternal1_m1094_tx	 1186	//(internal1_m1094_tx) tx - внутренний параметр
#define internal1_m1096_tx	 BUFFER[3701]	//(internal1_m1096_tx) tx - внутренний параметр
#define idinternal1_m1096_tx	 1187	//(internal1_m1096_tx) tx - внутренний параметр
#define internal1_m1095_tx	 BUFFER[3706]	//(internal1_m1095_tx) tx - внутренний параметр
#define idinternal1_m1095_tx	 1188	//(internal1_m1095_tx) tx - внутренний параметр
#define internal1_m2262_tx	 BUFFER[3711]	//(internal1_m2262_tx) tx - внутренний параметр
#define idinternal1_m2262_tx	 1189	//(internal1_m2262_tx) tx - внутренний параметр
#define internal1_m1085_tx	 BUFFER[3716]	//(internal1_m1085_tx) tx - внутренний параметр
#define idinternal1_m1085_tx	 1190	//(internal1_m1085_tx) tx - внутренний параметр
#define internal1_m2267_tx	 BUFFER[3721]	//(internal1_m2267_tx) tx - внутренний параметр
#define idinternal1_m2267_tx	 1191	//(internal1_m2267_tx) tx - внутренний параметр
#define internal1_m1093_tx	 BUFFER[3726]	//(internal1_m1093_tx) tx - внутренний параметр
#define idinternal1_m1093_tx	 1192	//(internal1_m1093_tx) tx - внутренний параметр
#define internal1_m1074_tx	 BUFFER[3731]	//(internal1_m1074_tx) tx - внутренний параметр
#define idinternal1_m1074_tx	 1193	//(internal1_m1074_tx) tx - внутренний параметр
#define internal1_m1073_tx	 BUFFER[3736]	//(internal1_m1073_tx) tx - внутренний параметр
#define idinternal1_m1073_tx	 1194	//(internal1_m1073_tx) tx - внутренний параметр
#define internal1_m1070_tx	 BUFFER[3741]	//(internal1_m1070_tx) tx - внутренний параметр
#define idinternal1_m1070_tx	 1195	//(internal1_m1070_tx) tx - внутренний параметр
#define internal1_m1092_tx	 BUFFER[3746]	//(internal1_m1092_tx) tx - внутренний параметр
#define idinternal1_m1092_tx	 1196	//(internal1_m1092_tx) tx - внутренний параметр
#define internal1_m1060_tx	 BUFFER[3751]	//(internal1_m1060_tx) tx - внутренний параметр
#define idinternal1_m1060_tx	 1197	//(internal1_m1060_tx) tx - внутренний параметр
#define internal1_m1058_tx	 BUFFER[3756]	//(internal1_m1058_tx) tx - внутренний параметр
#define idinternal1_m1058_tx	 1198	//(internal1_m1058_tx) tx - внутренний параметр
#define internal1_m1057_tx	 BUFFER[3761]	//(internal1_m1057_tx) tx - внутренний параметр
#define idinternal1_m1057_tx	 1199	//(internal1_m1057_tx) tx - внутренний параметр
#define internal1_m1036_tx	 BUFFER[3766]	//(internal1_m1036_tx) tx - внутренний параметр
#define idinternal1_m1036_tx	 1200	//(internal1_m1036_tx) tx - внутренний параметр
#define internal1_m1035_tx	 BUFFER[3771]	//(internal1_m1035_tx) tx - внутренний параметр
#define idinternal1_m1035_tx	 1201	//(internal1_m1035_tx) tx - внутренний параметр
#define internal1_m1025_tx	 BUFFER[3776]	//(internal1_m1025_tx) tx - внутренний параметр
#define idinternal1_m1025_tx	 1202	//(internal1_m1025_tx) tx - внутренний параметр
#define internal1_m1042_tx	 BUFFER[3781]	//(internal1_m1042_tx) tx - внутренний параметр
#define idinternal1_m1042_tx	 1203	//(internal1_m1042_tx) tx - внутренний параметр
#define internal1_m1461_tx	 BUFFER[3786]	//(internal1_m1461_tx) tx - внутренний параметр
#define idinternal1_m1461_tx	 1204	//(internal1_m1461_tx) tx - внутренний параметр
#define internal1_m1460_tx	 BUFFER[3791]	//(internal1_m1460_tx) tx - внутренний параметр
#define idinternal1_m1460_tx	 1205	//(internal1_m1460_tx) tx - внутренний параметр
#define internal1_m2214_tx	 BUFFER[3796]	//(internal1_m2214_tx) tx - внутренний параметр
#define idinternal1_m2214_tx	 1206	//(internal1_m2214_tx) tx - внутренний параметр
#define internal1_m1451_tx	 BUFFER[3801]	//(internal1_m1451_tx) tx - внутренний параметр
#define idinternal1_m1451_tx	 1207	//(internal1_m1451_tx) tx - внутренний параметр
#define internal1_m1452_tx	 BUFFER[3806]	//(internal1_m1452_tx) tx - внутренний параметр
#define idinternal1_m1452_tx	 1208	//(internal1_m1452_tx) tx - внутренний параметр
#define internal1_m1459_tx	 BUFFER[3811]	//(internal1_m1459_tx) tx - внутренний параметр
#define idinternal1_m1459_tx	 1209	//(internal1_m1459_tx) tx - внутренний параметр
#define internal1_m1441_tx	 BUFFER[3816]	//(internal1_m1441_tx) tx - внутренний параметр
#define idinternal1_m1441_tx	 1210	//(internal1_m1441_tx) tx - внутренний параметр
#define internal1_m1440_tx	 BUFFER[3821]	//(internal1_m1440_tx) tx - внутренний параметр
#define idinternal1_m1440_tx	 1211	//(internal1_m1440_tx) tx - внутренний параметр
#define internal1_m1437_tx	 BUFFER[3826]	//(internal1_m1437_tx) tx - внутренний параметр
#define idinternal1_m1437_tx	 1212	//(internal1_m1437_tx) tx - внутренний параметр
#define internal1_m1458_tx	 BUFFER[3831]	//(internal1_m1458_tx) tx - внутренний параметр
#define idinternal1_m1458_tx	 1213	//(internal1_m1458_tx) tx - внутренний параметр
#define internal1_m1424_tx	 BUFFER[3836]	//(internal1_m1424_tx) tx - внутренний параметр
#define idinternal1_m1424_tx	 1214	//(internal1_m1424_tx) tx - внутренний параметр
#define internal1_m1422_tx	 BUFFER[3841]	//(internal1_m1422_tx) tx - внутренний параметр
#define idinternal1_m1422_tx	 1215	//(internal1_m1422_tx) tx - внутренний параметр
#define internal1_m1426_tx	 BUFFER[3846]	//(internal1_m1426_tx) tx - внутренний параметр
#define idinternal1_m1426_tx	 1216	//(internal1_m1426_tx) tx - внутренний параметр
#define internal1_m251_tx	 BUFFER[3851]	//(internal1_m251_tx) tx - внутренний параметр
#define idinternal1_m251_tx	 1217	//(internal1_m251_tx) tx - внутренний параметр
#define internal1_m266_tx	 BUFFER[3856]	//(internal1_m266_tx) tx - внутренний параметр
#define idinternal1_m266_tx	 1218	//(internal1_m266_tx) tx - внутренний параметр
#define internal1_m274_tx	 BUFFER[3861]	//(internal1_m274_tx) tx - внутренний параметр
#define idinternal1_m274_tx	 1219	//(internal1_m274_tx) tx - внутренний параметр
#define internal1_m273_tx	 BUFFER[3866]	//(internal1_m273_tx) tx - внутренний параметр
#define idinternal1_m273_tx	 1220	//(internal1_m273_tx) tx - внутренний параметр
#define internal1_m259_tx	 BUFFER[3871]	//(internal1_m259_tx) tx - внутренний параметр
#define idinternal1_m259_tx	 1221	//(internal1_m259_tx) tx - внутренний параметр
#define internal1_m254_tx	 BUFFER[3876]	//(internal1_m254_tx) tx - внутренний параметр
#define idinternal1_m254_tx	 1222	//(internal1_m254_tx) tx - внутренний параметр
#define internal1_m270_tx	 BUFFER[3881]	//(internal1_m270_tx) tx - внутренний параметр
#define idinternal1_m270_tx	 1223	//(internal1_m270_tx) tx - внутренний параметр
#define internal1_m243_tx	 BUFFER[3886]	//(internal1_m243_tx) tx - внутренний параметр
#define idinternal1_m243_tx	 1224	//(internal1_m243_tx) tx - внутренний параметр
#define internal1_m242_tx	 BUFFER[3891]	//(internal1_m242_tx) tx - внутренний параметр
#define idinternal1_m242_tx	 1225	//(internal1_m242_tx) tx - внутренний параметр
#define internal1_m237_tx	 BUFFER[3896]	//(internal1_m237_tx) tx - внутренний параметр
#define idinternal1_m237_tx	 1226	//(internal1_m237_tx) tx - внутренний параметр
#define internal1_m269_tx	 BUFFER[3901]	//(internal1_m269_tx) tx - внутренний параметр
#define idinternal1_m269_tx	 1227	//(internal1_m269_tx) tx - внутренний параметр
#define internal1_m226_tx	 BUFFER[3906]	//(internal1_m226_tx) tx - внутренний параметр
#define idinternal1_m226_tx	 1228	//(internal1_m226_tx) tx - внутренний параметр
#define internal1_m228_tx	 BUFFER[3911]	//(internal1_m228_tx) tx - внутренний параметр
#define idinternal1_m228_tx	 1229	//(internal1_m228_tx) tx - внутренний параметр
#define internal1_m225_tx	 BUFFER[3916]	//(internal1_m225_tx) tx - внутренний параметр
#define idinternal1_m225_tx	 1230	//(internal1_m225_tx) tx - внутренний параметр
#define internal1_m204_tx	 BUFFER[3921]	//(internal1_m204_tx) tx - внутренний параметр
#define idinternal1_m204_tx	 1231	//(internal1_m204_tx) tx - внутренний параметр
#define internal1_m203_tx	 BUFFER[3926]	//(internal1_m203_tx) tx - внутренний параметр
#define idinternal1_m203_tx	 1232	//(internal1_m203_tx) tx - внутренний параметр
#define internal1_m202_tx	 BUFFER[3931]	//(internal1_m202_tx) tx - внутренний параметр
#define idinternal1_m202_tx	 1233	//(internal1_m202_tx) tx - внутренний параметр
#define internal1_m210_tx	 BUFFER[3936]	//(internal1_m210_tx) tx - внутренний параметр
#define idinternal1_m210_tx	 1234	//(internal1_m210_tx) tx - внутренний параметр
#define internal1_m1404_tx	 BUFFER[3941]	//(internal1_m1404_tx) tx - внутренний параметр
#define idinternal1_m1404_tx	 1235	//(internal1_m1404_tx) tx - внутренний параметр
#define internal1_m1386_tx	 BUFFER[3946]	//(internal1_m1386_tx) tx - внутренний параметр
#define idinternal1_m1386_tx	 1236	//(internal1_m1386_tx) tx - внутренний параметр
#define internal1_m1391_tx	 BUFFER[3951]	//(internal1_m1391_tx) tx - внутренний параметр
#define idinternal1_m1391_tx	 1237	//(internal1_m1391_tx) tx - внутренний параметр
#define internal1_m1408_tx	 BUFFER[3956]	//(internal1_m1408_tx) tx - внутренний параметр
#define idinternal1_m1408_tx	 1238	//(internal1_m1408_tx) tx - внутренний параметр
#define internal1_m925_tx	 BUFFER[3961]	//(internal1_m925_tx) tx - внутренний параметр
#define idinternal1_m925_tx	 1239	//(internal1_m925_tx) tx - внутренний параметр
#define internal1_m930_tx	 BUFFER[3966]	//(internal1_m930_tx) tx - внутренний параметр
#define idinternal1_m930_tx	 1240	//(internal1_m930_tx) tx - внутренний параметр
#define internal1_m920_tx	 BUFFER[3971]	//(internal1_m920_tx) tx - внутренний параметр
#define idinternal1_m920_tx	 1241	//(internal1_m920_tx) tx - внутренний параметр
#define internal1_m921_tx	 BUFFER[3976]	//(internal1_m921_tx) tx - внутренний параметр
#define idinternal1_m921_tx	 1242	//(internal1_m921_tx) tx - внутренний параметр
#define internal1_m1909_q0	 BUFFER[3981]	//(internal1_m1909_q0) q0 - внутренний параметр
#define idinternal1_m1909_q0	 1243	//(internal1_m1909_q0) q0 - внутренний параметр
#define internal1_m2351_q0	 BUFFER[3983]	//(internal1_m2351_q0) q0 - внутренний параметр
#define idinternal1_m2351_q0	 1244	//(internal1_m2351_q0) q0 - внутренний параметр
#define internal1_m2335_q0	 BUFFER[3985]	//(internal1_m2335_q0) q0 - внутренний параметр
#define idinternal1_m2335_q0	 1245	//(internal1_m2335_q0) q0 - внутренний параметр
#define internal1_m2382_q0	 BUFFER[3987]	//(internal1_m2382_q0) q0 - внутренний параметр
#define idinternal1_m2382_q0	 1246	//(internal1_m2382_q0) q0 - внутренний параметр
#define internal1_m2366_q0	 BUFFER[3989]	//(internal1_m2366_q0) q0 - внутренний параметр
#define idinternal1_m2366_q0	 1247	//(internal1_m2366_q0) q0 - внутренний параметр
#define internal1_m2357_q0	 BUFFER[3991]	//(internal1_m2357_q0) q0 - внутренний параметр
#define idinternal1_m2357_q0	 1248	//(internal1_m2357_q0) q0 - внутренний параметр
#define internal1_m2338_q0	 BUFFER[3993]	//(internal1_m2338_q0) q0 - внутренний параметр
#define idinternal1_m2338_q0	 1249	//(internal1_m2338_q0) q0 - внутренний параметр
#define internal1_m2355_q0	 BUFFER[3995]	//(internal1_m2355_q0) q0 - внутренний параметр
#define idinternal1_m2355_q0	 1250	//(internal1_m2355_q0) q0 - внутренний параметр
#define internal1_m2336_q0	 BUFFER[3997]	//(internal1_m2336_q0) q0 - внутренний параметр
#define idinternal1_m2336_q0	 1251	//(internal1_m2336_q0) q0 - внутренний параметр
#define internal1_m2334_q0	 BUFFER[3999]	//(internal1_m2334_q0) q0 - внутренний параметр
#define idinternal1_m2334_q0	 1252	//(internal1_m2334_q0) q0 - внутренний параметр
#define internal1_m2333_q0	 BUFFER[4001]	//(internal1_m2333_q0) q0 - внутренний параметр
#define idinternal1_m2333_q0	 1253	//(internal1_m2333_q0) q0 - внутренний параметр
#define internal1_m2347_q0	 BUFFER[4003]	//(internal1_m2347_q0) q0 - внутренний параметр
#define idinternal1_m2347_q0	 1254	//(internal1_m2347_q0) q0 - внутренний параметр
#define internal1_m2345_q0	 BUFFER[4005]	//(internal1_m2345_q0) q0 - внутренний параметр
#define idinternal1_m2345_q0	 1255	//(internal1_m2345_q0) q0 - внутренний параметр
#define internal1_m2353_q0	 BUFFER[4007]	//(internal1_m2353_q0) q0 - внутренний параметр
#define idinternal1_m2353_q0	 1256	//(internal1_m2353_q0) q0 - внутренний параметр
#define internal1_m2349_q0	 BUFFER[4009]	//(internal1_m2349_q0) q0 - внутренний параметр
#define idinternal1_m2349_q0	 1257	//(internal1_m2349_q0) q0 - внутренний параметр
#define internal1_m2388_q0	 BUFFER[4011]	//(internal1_m2388_q0) q0 - внутренний параметр
#define idinternal1_m2388_q0	 1258	//(internal1_m2388_q0) q0 - внутренний параметр
#define internal1_m2369_q0	 BUFFER[4013]	//(internal1_m2369_q0) q0 - внутренний параметр
#define idinternal1_m2369_q0	 1259	//(internal1_m2369_q0) q0 - внутренний параметр
#define internal1_m2386_q0	 BUFFER[4015]	//(internal1_m2386_q0) q0 - внутренний параметр
#define idinternal1_m2386_q0	 1260	//(internal1_m2386_q0) q0 - внутренний параметр
#define internal1_m2368_q0	 BUFFER[4017]	//(internal1_m2368_q0) q0 - внутренний параметр
#define idinternal1_m2368_q0	 1261	//(internal1_m2368_q0) q0 - внутренний параметр
#define internal1_m2365_q0	 BUFFER[4019]	//(internal1_m2365_q0) q0 - внутренний параметр
#define idinternal1_m2365_q0	 1262	//(internal1_m2365_q0) q0 - внутренний параметр
#define internal1_m2364_q0	 BUFFER[4021]	//(internal1_m2364_q0) q0 - внутренний параметр
#define idinternal1_m2364_q0	 1263	//(internal1_m2364_q0) q0 - внутренний параметр
#define internal1_m2378_q0	 BUFFER[4023]	//(internal1_m2378_q0) q0 - внутренний параметр
#define idinternal1_m2378_q0	 1264	//(internal1_m2378_q0) q0 - внутренний параметр
#define internal1_m2376_q0	 BUFFER[4025]	//(internal1_m2376_q0) q0 - внутренний параметр
#define idinternal1_m2376_q0	 1265	//(internal1_m2376_q0) q0 - внутренний параметр
#define internal1_m2239_tx	 BUFFER[4027]	//(internal1_m2239_tx) tx - внутренний параметр
#define idinternal1_m2239_tx	 1266	//(internal1_m2239_tx) tx - внутренний параметр
#define internal1_m2218_tx	 BUFFER[4032]	//(internal1_m2218_tx) tx - внутренний параметр
#define idinternal1_m2218_tx	 1267	//(internal1_m2218_tx) tx - внутренний параметр
#define internal1_m1931_Pv0	 BUFFER[4037]	//(internal1_m1931_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1931_Pv0	 1268	//(internal1_m1931_Pv0)  - Пер. выключатель механизма
#define internal1_m1931_Zv0	 BUFFER[4039]	//(internal1_m1931_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1931_Zv0	 1269	//(internal1_m1931_Zv0)  - Зад. выключатель механизма
#define internal1_m1931_MyFirstEnterFlag	 BUFFER[4041]	//(internal1_m1931_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1931_MyFirstEnterFlag	 1270	//(internal1_m1931_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m1930_Pv0	 BUFFER[4043]	//(internal1_m1930_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1930_Pv0	 1271	//(internal1_m1930_Pv0)  - Пер. выключатель механизма
#define internal1_m1930_Zv0	 BUFFER[4045]	//(internal1_m1930_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1930_Zv0	 1272	//(internal1_m1930_Zv0)  - Зад. выключатель механизма
#define internal1_m1930_MyFirstEnterFlag	 BUFFER[4047]	//(internal1_m1930_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1930_MyFirstEnterFlag	 1273	//(internal1_m1930_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m2405_tx	 BUFFER[4049]	//(internal1_m2405_tx) tx - время накопленное сек
#define idinternal1_m2405_tx	 1274	//(internal1_m2405_tx) tx - время накопленное сек
#define internal1_m2405_y0	 BUFFER[4054]	//(internal1_m2405_y0) y0
#define idinternal1_m2405_y0	 1275	//(internal1_m2405_y0) y0
#define internal1_m2410_tx	 BUFFER[4055]	//(internal1_m2410_tx) tx - время накопленное сек
#define idinternal1_m2410_tx	 1276	//(internal1_m2410_tx) tx - время накопленное сек
#define internal1_m2410_y0	 BUFFER[4060]	//(internal1_m2410_y0) y0
#define idinternal1_m2410_y0	 1277	//(internal1_m2410_y0) y0
#define internal1_m2409_tx	 BUFFER[4061]	//(internal1_m2409_tx) tx - время накопленное сек
#define idinternal1_m2409_tx	 1278	//(internal1_m2409_tx) tx - время накопленное сек
#define internal1_m2409_y0	 BUFFER[4066]	//(internal1_m2409_y0) y0
#define idinternal1_m2409_y0	 1279	//(internal1_m2409_y0) y0
#define internal1_m2446_tx	 BUFFER[4067]	//(internal1_m2446_tx) tx - внутренний параметр
#define idinternal1_m2446_tx	 1280	//(internal1_m2446_tx) tx - внутренний параметр
#define internal1_m2444_tx	 BUFFER[4072]	//(internal1_m2444_tx) tx - время накопленное сек
#define idinternal1_m2444_tx	 1281	//(internal1_m2444_tx) tx - время накопленное сек
#define internal1_m2444_y0	 BUFFER[4077]	//(internal1_m2444_y0) y0
#define idinternal1_m2444_y0	 1282	//(internal1_m2444_y0) y0
#define internal1_m2449_q0	 BUFFER[4078]	//(internal1_m2449_q0) q0 - внутренний параметр
#define idinternal1_m2449_q0	 1283	//(internal1_m2449_q0) q0 - внутренний параметр
#define internal1_m2416_q0	 BUFFER[4080]	//(internal1_m2416_q0) q0 - внутренний параметр
#define idinternal1_m2416_q0	 1284	//(internal1_m2416_q0) q0 - внутренний параметр
#define internal1_m2424_tx	 BUFFER[4082]	//(internal1_m2424_tx) tx - внутренний параметр
#define idinternal1_m2424_tx	 1285	//(internal1_m2424_tx) tx - внутренний параметр
#define internal1_m2422_q0	 BUFFER[4087]	//(internal1_m2422_q0) q0 - внутренний параметр
#define idinternal1_m2422_q0	 1286	//(internal1_m2422_q0) q0 - внутренний параметр
#define internal1_m2408_fVf0	 BUFFER[4089]	//(internal1_m2408_fVf0)  - скорость изменения мощности 
#define idinternal1_m2408_fVf0	 1287	//(internal1_m2408_fVf0)  - скорость изменения мощности 
#define internal1_m2408_fRsg	 BUFFER[4094]	//(internal1_m2408_fRsg)  - рассогласование между текущей и заданной мощностью 
#define idinternal1_m2408_fRsg	 1288	//(internal1_m2408_fRsg)  - рассогласование между текущей и заданной мощностью 
#define internal1_m2408_fRct	 BUFFER[4099]	//(internal1_m2408_fRct)  - стартовая реактивность регулятора 
#define idinternal1_m2408_fRct	 1289	//(internal1_m2408_fRct)  - стартовая реактивность регулятора 
#define internal1_m2408_fVfMin	 BUFFER[4104]	//(internal1_m2408_fVfMin)  - минимальная скорость 
#define idinternal1_m2408_fVfMin	 1290	//(internal1_m2408_fVfMin)  - минимальная скорость 
#define internal1_m2408_fStw0	 BUFFER[4109]	//(internal1_m2408_fStw0)  - значение стартовой мощности включения ИМ 
#define idinternal1_m2408_fStw0	 1291	//(internal1_m2408_fStw0)  - значение стартовой мощности включения ИМ 
#define internal1_m2408_fMaxDk	 BUFFER[4114]	//(internal1_m2408_fMaxDk)  - изменение координаты при смене задания 
#define idinternal1_m2408_fMaxDk	 1292	//(internal1_m2408_fMaxDk)  - изменение координаты при смене задания 
#define internal1_m2408_fkizm	 BUFFER[4119]	//(internal1_m2408_fkizm)  - стартовая координата положения ИМ 0-й реактивности 
#define idinternal1_m2408_fkizm	 1293	//(internal1_m2408_fkizm)  - стартовая координата положения ИМ 0-й реактивности 
#define internal1_m2408_fwt0	 BUFFER[4124]	//(internal1_m2408_fwt0)  - мощность на предыдущем шаге 
#define idinternal1_m2408_fwt0	 1294	//(internal1_m2408_fwt0)  - мощность на предыдущем шаге 
#define internal1_m2408_fwz0	 BUFFER[4129]	//(internal1_m2408_fwz0)  - заданная мощность на предыдущем шаге 
#define idinternal1_m2408_fwz0	 1295	//(internal1_m2408_fwz0)  - заданная мощность на предыдущем шаге 
#define internal1_m2408_ftf0	 BUFFER[4134]	//(internal1_m2408_ftf0)  - время от фиксации предыдущей мощности 
#define idinternal1_m2408_ftf0	 1296	//(internal1_m2408_ftf0)  - время от фиксации предыдущей мощности 
#define internal1_m2408_fTk0	 BUFFER[4139]	//(internal1_m2408_fTk0)  - последняя температура 
#define idinternal1_m2408_fTk0	 1297	//(internal1_m2408_fTk0)  - последняя температура 
#define internal1_m2408_FlPar	 BUFFER[4144]	//(internal1_m2408_FlPar) - стартовый этап регулирования
#define idinternal1_m2408_FlPar	 1298	//(internal1_m2408_FlPar) - стартовый этап регулирования
#define internal1_m2408_FlIzm	 BUFFER[4147]	//(internal1_m2408_FlIzm) - флаг изменения направления изменения мощности
#define idinternal1_m2408_FlIzm	 1299	//(internal1_m2408_FlIzm) - флаг изменения направления изменения мощности
#define internal1_m2408_FlCmp	 BUFFER[4150]	//(internal1_m2408_FlCmp) - текущее направление изменения мощности
#define idinternal1_m2408_FlCmp	 1300	//(internal1_m2408_FlCmp) - текущее направление изменения мощности
#define internal1_m2408_StabCoun	 BUFFER[4153]	//(internal1_m2408_StabCoun) - счётчик стабильности
#define idinternal1_m2408_StabCoun	 1301	//(internal1_m2408_StabCoun) - счётчик стабильности
#define internal1_m2408_ZerCoun	 BUFFER[4156]	//(internal1_m2408_ZerCoun) - счётчик полной остановки
#define idinternal1_m2408_ZerCoun	 1302	//(internal1_m2408_ZerCoun) - счётчик полной остановки
#define internal1_m2408_SrCoun	 BUFFER[4159]	//(internal1_m2408_SrCoun)  - счётчик усреднения
#define idinternal1_m2408_SrCoun	 1303	//(internal1_m2408_SrCoun)  - счётчик усреднения
#define internal1_m2408_LastStage	 BUFFER[4162]	//(internal1_m2408_LastStage)  - последний этап
#define idinternal1_m2408_LastStage	 1304	//(internal1_m2408_LastStage)  - последний этап
#define internal1_m2408_fef	 BUFFER[4165]	//(internal1_m2408_fef)  - первый вход
#define idinternal1_m2408_fef	 1305	//(internal1_m2408_fef)  - первый вход
#define internal1_m2233_tx	 BUFFER[4167]	//(internal1_m2233_tx) tx - время накопленное сек
#define idinternal1_m2233_tx	 1306	//(internal1_m2233_tx) tx - время накопленное сек
#define internal1_m2233_y0	 BUFFER[4172]	//(internal1_m2233_y0) y0
#define idinternal1_m2233_y0	 1307	//(internal1_m2233_y0) y0
#define internal1_m2225_tx	 BUFFER[4173]	//(internal1_m2225_tx) tx - время накопленное сек
#define idinternal1_m2225_tx	 1308	//(internal1_m2225_tx) tx - время накопленное сек
#define internal1_m2225_y0	 BUFFER[4178]	//(internal1_m2225_y0) y0
#define idinternal1_m2225_y0	 1309	//(internal1_m2225_y0) y0
#define internal1_m1919_q0	 BUFFER[4179]	//(internal1_m1919_q0) q0 - внутренний параметр
#define idinternal1_m1919_q0	 1310	//(internal1_m1919_q0) q0 - внутренний параметр
#define internal1_m1924_q0	 BUFFER[4181]	//(internal1_m1924_q0) q0 - внутренний параметр
#define idinternal1_m1924_q0	 1311	//(internal1_m1924_q0) q0 - внутренний параметр
#define internal1_m1916_q0	 BUFFER[4183]	//(internal1_m1916_q0) q0 - внутренний параметр
#define idinternal1_m1916_q0	 1312	//(internal1_m1916_q0) q0 - внутренний параметр
#define internal1_m1958_q0	 BUFFER[4185]	//(internal1_m1958_q0) q0 - внутренний параметр
#define idinternal1_m1958_q0	 1313	//(internal1_m1958_q0) q0 - внутренний параметр
#define internal1_m830_tx	 BUFFER[4187]	//(internal1_m830_tx) tx - время накопленное сек
#define idinternal1_m830_tx	 1314	//(internal1_m830_tx) tx - время накопленное сек
#define internal1_m830_y0	 BUFFER[4192]	//(internal1_m830_y0) y0
#define idinternal1_m830_y0	 1315	//(internal1_m830_y0) y0
#define internal1_m2229_tx	 BUFFER[4193]	//(internal1_m2229_tx) tx - внутренний параметр
#define idinternal1_m2229_tx	 1316	//(internal1_m2229_tx) tx - внутренний параметр
#define internal1_m2232_q0	 BUFFER[4198]	//(internal1_m2232_q0) q0 - внутренний параметр
#define idinternal1_m2232_q0	 1317	//(internal1_m2232_q0) q0 - внутренний параметр
#define internal1_m2224_q0	 BUFFER[4200]	//(internal1_m2224_q0) q0 - внутренний параметр
#define idinternal1_m2224_q0	 1318	//(internal1_m2224_q0) q0 - внутренний параметр
#define internal1_m2193_tx	 BUFFER[4202]	//(internal1_m2193_tx) tx - внутренний параметр
#define idinternal1_m2193_tx	 1319	//(internal1_m2193_tx) tx - внутренний параметр
#define internal1_m2204_tx	 BUFFER[4207]	//(internal1_m2204_tx) tx - внутренний параметр
#define idinternal1_m2204_tx	 1320	//(internal1_m2204_tx) tx - внутренний параметр
#define internal1_m2190_tx	 BUFFER[4212]	//(internal1_m2190_tx) tx - внутренний параметр
#define idinternal1_m2190_tx	 1321	//(internal1_m2190_tx) tx - внутренний параметр
#define internal1_m2196_q0	 BUFFER[4217]	//(internal1_m2196_q0) q0 - внутренний параметр
#define idinternal1_m2196_q0	 1322	//(internal1_m2196_q0) q0 - внутренний параметр
#define internal1_m2208_q0	 BUFFER[4219]	//(internal1_m2208_q0) q0 - внутренний параметр
#define idinternal1_m2208_q0	 1323	//(internal1_m2208_q0) q0 - внутренний параметр
#define internal1_m2165_tx	 BUFFER[4221]	//(internal1_m2165_tx) tx - внутренний параметр
#define idinternal1_m2165_tx	 1324	//(internal1_m2165_tx) tx - внутренний параметр
#define internal1_m52_tx	 BUFFER[4226]	//(internal1_m52_tx) tx - внутренний параметр
#define idinternal1_m52_tx	 1325	//(internal1_m52_tx) tx - внутренний параметр
#define internal1_m364_tx	 BUFFER[4231]	//(internal1_m364_tx) tx - внутренний параметр
#define idinternal1_m364_tx	 1326	//(internal1_m364_tx) tx - внутренний параметр
#define internal1_m317_tx	 BUFFER[4236]	//(internal1_m317_tx) tx - внутренний параметр
#define idinternal1_m317_tx	 1327	//(internal1_m317_tx) tx - внутренний параметр
#define internal1_m831_tx	 BUFFER[4241]	//(internal1_m831_tx) tx - внутренний параметр
#define idinternal1_m831_tx	 1328	//(internal1_m831_tx) tx - внутренний параметр
#define internal1_m1623_tx	 BUFFER[4246]	//(internal1_m1623_tx) tx - внутренний параметр
#define idinternal1_m1623_tx	 1329	//(internal1_m1623_tx) tx - внутренний параметр
#define internal1_m120_tx	 BUFFER[4251]	//(internal1_m120_tx) tx - внутренний параметр
#define idinternal1_m120_tx	 1330	//(internal1_m120_tx) tx - внутренний параметр
#define internal1_m122_tx	 BUFFER[4256]	//(internal1_m122_tx) tx - внутренний параметр
#define idinternal1_m122_tx	 1331	//(internal1_m122_tx) tx - внутренний параметр
#define internal1_m127_tx	 BUFFER[4261]	//(internal1_m127_tx) tx - внутренний параметр
#define idinternal1_m127_tx	 1332	//(internal1_m127_tx) tx - внутренний параметр
#define internal1_m21_tx	 BUFFER[4266]	//(internal1_m21_tx) tx - внутренний параметр
#define idinternal1_m21_tx	 1333	//(internal1_m21_tx) tx - внутренний параметр
#define internal1_m13_tx	 BUFFER[4271]	//(internal1_m13_tx) tx - внутренний параметр
#define idinternal1_m13_tx	 1334	//(internal1_m13_tx) tx - внутренний параметр
#define internal1_m2175_tx	 BUFFER[4276]	//(internal1_m2175_tx) tx - внутренний параметр
#define idinternal1_m2175_tx	 1335	//(internal1_m2175_tx) tx - внутренний параметр
#define internal1_m2162_tx	 BUFFER[4281]	//(internal1_m2162_tx) tx - внутренний параметр
#define idinternal1_m2162_tx	 1336	//(internal1_m2162_tx) tx - внутренний параметр
#define internal1_m2280_tx	 BUFFER[4286]	//(internal1_m2280_tx) tx - внутренний параметр
#define idinternal1_m2280_tx	 1337	//(internal1_m2280_tx) tx - внутренний параметр
#define internal1_m2282_tx	 BUFFER[4291]	//(internal1_m2282_tx) tx - внутренний параметр
#define idinternal1_m2282_tx	 1338	//(internal1_m2282_tx) tx - внутренний параметр
#define internal1_m82_tx	 BUFFER[4296]	//(internal1_m82_tx) tx - внутренний параметр
#define idinternal1_m82_tx	 1339	//(internal1_m82_tx) tx - внутренний параметр
#define internal1_m335_tx	 BUFFER[4301]	//(internal1_m335_tx) tx - время накопленное сек
#define idinternal1_m335_tx	 1340	//(internal1_m335_tx) tx - время накопленное сек
#define internal1_m335_y0	 BUFFER[4306]	//(internal1_m335_y0) y0
#define idinternal1_m335_y0	 1341	//(internal1_m335_y0) y0
#define internal1_m2073_tx	 BUFFER[4307]	//(internal1_m2073_tx) tx - время накопленное сек
#define idinternal1_m2073_tx	 1342	//(internal1_m2073_tx) tx - время накопленное сек
#define internal1_m2073_y0	 BUFFER[4312]	//(internal1_m2073_y0) y0
#define idinternal1_m2073_y0	 1343	//(internal1_m2073_y0) y0
#define internal1_m2087_q0	 BUFFER[4313]	//(internal1_m2087_q0) q0 - внутренний параметр
#define idinternal1_m2087_q0	 1344	//(internal1_m2087_q0) q0 - внутренний параметр
#define internal1_m1644_q0	 BUFFER[4318]	//(internal1_m1644_q0) q0 - внутренний параметр
#define idinternal1_m1644_q0	 1345	//(internal1_m1644_q0) q0 - внутренний параметр
#define internal1_m1682_q0	 BUFFER[4323]	//(internal1_m1682_q0) q0 - внутренний параметр
#define idinternal1_m1682_q0	 1346	//(internal1_m1682_q0) q0 - внутренний параметр
#define internal1_m1685_q0	 BUFFER[4328]	//(internal1_m1685_q0) q0 - внутренний параметр
#define idinternal1_m1685_q0	 1347	//(internal1_m1685_q0) q0 - внутренний параметр
#define internal1_m2127_q0	 BUFFER[4333]	//(internal1_m2127_q0) q0 - внутренний параметр
#define idinternal1_m2127_q0	 1348	//(internal1_m2127_q0) q0 - внутренний параметр
#define internal1_m2105_tx	 BUFFER[4338]	//(internal1_m2105_tx) tx - время накопленное сек
#define idinternal1_m2105_tx	 1349	//(internal1_m2105_tx) tx - время накопленное сек
#define internal1_m2105_y0	 BUFFER[4343]	//(internal1_m2105_y0) y0
#define idinternal1_m2105_y0	 1350	//(internal1_m2105_y0) y0
#define internal1_m2120_tx	 BUFFER[4344]	//(internal1_m2120_tx) tx - время накопленное сек
#define idinternal1_m2120_tx	 1351	//(internal1_m2120_tx) tx - время накопленное сек
#define internal1_m2120_y0	 BUFFER[4349]	//(internal1_m2120_y0) y0
#define idinternal1_m2120_y0	 1352	//(internal1_m2120_y0) y0
#define internal1_m2117_tx	 BUFFER[4350]	//(internal1_m2117_tx) tx - время накопленное сек
#define idinternal1_m2117_tx	 1353	//(internal1_m2117_tx) tx - время накопленное сек
#define internal1_m2117_y0	 BUFFER[4355]	//(internal1_m2117_y0) y0
#define idinternal1_m2117_y0	 1354	//(internal1_m2117_y0) y0
#define internal1_m2260_tx	 BUFFER[4356]	//(internal1_m2260_tx) tx - время накопленное сек
#define idinternal1_m2260_tx	 1355	//(internal1_m2260_tx) tx - время накопленное сек
#define internal1_m2260_y0	 BUFFER[4361]	//(internal1_m2260_y0) y0
#define idinternal1_m2260_y0	 1356	//(internal1_m2260_y0) y0
#define internal1_m2271_tx	 BUFFER[4362]	//(internal1_m2271_tx) tx - время накопленное сек
#define idinternal1_m2271_tx	 1357	//(internal1_m2271_tx) tx - время накопленное сек
#define internal1_m2271_y0	 BUFFER[4367]	//(internal1_m2271_y0) y0
#define idinternal1_m2271_y0	 1358	//(internal1_m2271_y0) y0
#define internal1_m2026_tx	 BUFFER[4368]	//(internal1_m2026_tx) tx - время накопленное сек
#define idinternal1_m2026_tx	 1359	//(internal1_m2026_tx) tx - время накопленное сек
#define internal1_m2026_y0	 BUFFER[4373]	//(internal1_m2026_y0) y0
#define idinternal1_m2026_y0	 1360	//(internal1_m2026_y0) y0
#define internal1_m2025_tx	 BUFFER[4374]	//(internal1_m2025_tx) tx - время накопленное сек
#define idinternal1_m2025_tx	 1361	//(internal1_m2025_tx) tx - время накопленное сек
#define internal1_m2025_y0	 BUFFER[4379]	//(internal1_m2025_y0) y0
#define idinternal1_m2025_y0	 1362	//(internal1_m2025_y0) y0
#define internal1_m2024_tx	 BUFFER[4380]	//(internal1_m2024_tx) tx - время накопленное сек
#define idinternal1_m2024_tx	 1363	//(internal1_m2024_tx) tx - время накопленное сек
#define internal1_m2024_y0	 BUFFER[4385]	//(internal1_m2024_y0) y0
#define idinternal1_m2024_y0	 1364	//(internal1_m2024_y0) y0
#define internal1_m2023_tx	 BUFFER[4386]	//(internal1_m2023_tx) tx - время накопленное сек
#define idinternal1_m2023_tx	 1365	//(internal1_m2023_tx) tx - время накопленное сек
#define internal1_m2023_y0	 BUFFER[4391]	//(internal1_m2023_y0) y0
#define idinternal1_m2023_y0	 1366	//(internal1_m2023_y0) y0
#define internal1_m1699_tx	 BUFFER[4392]	//(internal1_m1699_tx) tx - время накопленное сек
#define idinternal1_m1699_tx	 1367	//(internal1_m1699_tx) tx - время накопленное сек
#define internal1_m1699_y0	 BUFFER[4397]	//(internal1_m1699_y0) y0
#define idinternal1_m1699_y0	 1368	//(internal1_m1699_y0) y0
#define internal1_m1692_tx	 BUFFER[4398]	//(internal1_m1692_tx) tx - время накопленное сек
#define idinternal1_m1692_tx	 1369	//(internal1_m1692_tx) tx - время накопленное сек
#define internal1_m1692_y0	 BUFFER[4403]	//(internal1_m1692_y0) y0
#define idinternal1_m1692_y0	 1370	//(internal1_m1692_y0) y0
#define internal1_m1639_tx	 BUFFER[4404]	//(internal1_m1639_tx) tx - время накопленное сек
#define idinternal1_m1639_tx	 1371	//(internal1_m1639_tx) tx - время накопленное сек
#define internal1_m1639_y0	 BUFFER[4409]	//(internal1_m1639_y0) y0
#define idinternal1_m1639_y0	 1372	//(internal1_m1639_y0) y0
#define internal1_m918_tx	 BUFFER[4410]	//(internal1_m918_tx) tx - время накопленное сек
#define idinternal1_m918_tx	 1373	//(internal1_m918_tx) tx - время накопленное сек
#define internal1_m918_y0	 BUFFER[4415]	//(internal1_m918_y0) y0
#define idinternal1_m918_y0	 1374	//(internal1_m918_y0) y0
#define internal1_m917_tx	 BUFFER[4416]	//(internal1_m917_tx) tx - время накопленное сек
#define idinternal1_m917_tx	 1375	//(internal1_m917_tx) tx - время накопленное сек
#define internal1_m917_y0	 BUFFER[4421]	//(internal1_m917_y0) y0
#define idinternal1_m917_y0	 1376	//(internal1_m917_y0) y0
#define internal1_m935_tx	 BUFFER[4422]	//(internal1_m935_tx) tx - время накопленное сек
#define idinternal1_m935_tx	 1377	//(internal1_m935_tx) tx - время накопленное сек
#define internal1_m935_y0	 BUFFER[4427]	//(internal1_m935_y0) y0
#define idinternal1_m935_y0	 1378	//(internal1_m935_y0) y0
#define internal1_m194_tx	 BUFFER[4428]	//(internal1_m194_tx) tx - время накопленное сек
#define idinternal1_m194_tx	 1379	//(internal1_m194_tx) tx - время накопленное сек
#define internal1_m194_y0	 BUFFER[4433]	//(internal1_m194_y0) y0
#define idinternal1_m194_y0	 1380	//(internal1_m194_y0) y0
#define internal1_m193_tx	 BUFFER[4434]	//(internal1_m193_tx) tx - время накопленное сек
#define idinternal1_m193_tx	 1381	//(internal1_m193_tx) tx - время накопленное сек
#define internal1_m193_y0	 BUFFER[4439]	//(internal1_m193_y0) y0
#define idinternal1_m193_y0	 1382	//(internal1_m193_y0) y0
#define internal1_m215_tx	 BUFFER[4440]	//(internal1_m215_tx) tx - время накопленное сек
#define idinternal1_m215_tx	 1383	//(internal1_m215_tx) tx - время накопленное сек
#define internal1_m215_y0	 BUFFER[4445]	//(internal1_m215_y0) y0
#define idinternal1_m215_y0	 1384	//(internal1_m215_y0) y0
#define internal1_m584_tx	 BUFFER[4446]	//(internal1_m584_tx) tx - время накопленное сек
#define idinternal1_m584_tx	 1385	//(internal1_m584_tx) tx - время накопленное сек
#define internal1_m584_y0	 BUFFER[4451]	//(internal1_m584_y0) y0
#define idinternal1_m584_y0	 1386	//(internal1_m584_y0) y0
#define internal1_m2316_tx	 BUFFER[4452]	//(internal1_m2316_tx) tx - внутренний параметр
#define idinternal1_m2316_tx	 1387	//(internal1_m2316_tx) tx - внутренний параметр
#define internal1_m1336_tx	 BUFFER[4457]	//(internal1_m1336_tx) tx - внутренний параметр
#define idinternal1_m1336_tx	 1388	//(internal1_m1336_tx) tx - внутренний параметр
#define internal1_m1828_tx	 BUFFER[4462]	//(internal1_m1828_tx) tx - время накопленное сек
#define idinternal1_m1828_tx	 1389	//(internal1_m1828_tx) tx - время накопленное сек
#define internal1_m1828_y0	 BUFFER[4467]	//(internal1_m1828_y0) y0
#define idinternal1_m1828_y0	 1390	//(internal1_m1828_y0) y0
#define internal1_m1303_tx	 BUFFER[4468]	//(internal1_m1303_tx) tx - время накопленное сек
#define idinternal1_m1303_tx	 1391	//(internal1_m1303_tx) tx - время накопленное сек
#define internal1_m1303_y0	 BUFFER[4473]	//(internal1_m1303_y0) y0
#define idinternal1_m1303_y0	 1392	//(internal1_m1303_y0) y0
#define internal1_m1521_tx	 BUFFER[4474]	//(internal1_m1521_tx) tx - время накопленное сек
#define idinternal1_m1521_tx	 1393	//(internal1_m1521_tx) tx - время накопленное сек
#define internal1_m1521_y0	 BUFFER[4479]	//(internal1_m1521_y0) y0
#define idinternal1_m1521_y0	 1394	//(internal1_m1521_y0) y0
#define internal1_m1048_tx	 BUFFER[4480]	//(internal1_m1048_tx) tx - время накопленное сек
#define idinternal1_m1048_tx	 1395	//(internal1_m1048_tx) tx - время накопленное сек
#define internal1_m1048_y0	 BUFFER[4485]	//(internal1_m1048_y0) y0
#define idinternal1_m1048_y0	 1396	//(internal1_m1048_y0) y0
#define internal1_m1411_tx	 BUFFER[4486]	//(internal1_m1411_tx) tx - время накопленное сек
#define idinternal1_m1411_tx	 1397	//(internal1_m1411_tx) tx - время накопленное сек
#define internal1_m1411_y0	 BUFFER[4491]	//(internal1_m1411_y0) y0
#define idinternal1_m1411_y0	 1398	//(internal1_m1411_y0) y0
#define internal1_m1205_q0	 BUFFER[4492]	//(internal1_m1205_q0) q0 - внутренний параметр
#define idinternal1_m1205_q0	 1399	//(internal1_m1205_q0) q0 - внутренний параметр
#define internal1_m1203_q0	 BUFFER[4494]	//(internal1_m1203_q0) q0 - внутренний параметр
#define idinternal1_m1203_q0	 1400	//(internal1_m1203_q0) q0 - внутренний параметр
#define internal1_m1202_q0	 BUFFER[4496]	//(internal1_m1202_q0) q0 - внутренний параметр
#define idinternal1_m1202_q0	 1401	//(internal1_m1202_q0) q0 - внутренний параметр
#define internal1_m1200_q0	 BUFFER[4498]	//(internal1_m1200_q0) q0 - внутренний параметр
#define idinternal1_m1200_q0	 1402	//(internal1_m1200_q0) q0 - внутренний параметр
#define internal1_m1199_q0	 BUFFER[4500]	//(internal1_m1199_q0) q0 - внутренний параметр
#define idinternal1_m1199_q0	 1403	//(internal1_m1199_q0) q0 - внутренний параметр
#define internal1_m1197_q0	 BUFFER[4502]	//(internal1_m1197_q0) q0 - внутренний параметр
#define idinternal1_m1197_q0	 1404	//(internal1_m1197_q0) q0 - внутренний параметр
#define internal1_m1196_q0	 BUFFER[4504]	//(internal1_m1196_q0) q0 - внутренний параметр
#define idinternal1_m1196_q0	 1405	//(internal1_m1196_q0) q0 - внутренний параметр
#define internal1_m1194_q0	 BUFFER[4506]	//(internal1_m1194_q0) q0 - внутренний параметр
#define idinternal1_m1194_q0	 1406	//(internal1_m1194_q0) q0 - внутренний параметр
#define internal1_m1193_q0	 BUFFER[4508]	//(internal1_m1193_q0) q0 - внутренний параметр
#define idinternal1_m1193_q0	 1407	//(internal1_m1193_q0) q0 - внутренний параметр
#define internal1_m54_x0	 BUFFER[4510]	//(internal1_m54_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m54_x0	 1408	//(internal1_m54_x0) - значение входного параметра на предыдущем шаге
#define internal1_m54_tim	 BUFFER[4512]	//(internal1_m54_tim) - время задержки выходного сигнала
#define idinternal1_m54_tim	 1409	//(internal1_m54_tim) - время задержки выходного сигнала
#define internal1_m1112_q0	 BUFFER[4517]	//(internal1_m1112_q0) q0 - внутренний параметр
#define idinternal1_m1112_q0	 1410	//(internal1_m1112_q0) q0 - внутренний параметр
#define internal1_m1633_x0	 BUFFER[4519]	//(internal1_m1633_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m1633_x0	 1411	//(internal1_m1633_x0) - значение входного параметра на предыдущем шаге
#define internal1_m1633_tim	 BUFFER[4521]	//(internal1_m1633_tim) - время задержки выходного сигнала
#define idinternal1_m1633_tim	 1412	//(internal1_m1633_tim) - время задержки выходного сигнала
#define internal1_m1681_x0	 BUFFER[4526]	//(internal1_m1681_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m1681_x0	 1413	//(internal1_m1681_x0) - значение входного параметра на предыдущем шаге
#define internal1_m1681_tim	 BUFFER[4528]	//(internal1_m1681_tim) - время задержки выходного сигнала
#define idinternal1_m1681_tim	 1414	//(internal1_m1681_tim) - время задержки выходного сигнала
#define internal1_m1684_x0	 BUFFER[4533]	//(internal1_m1684_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m1684_x0	 1415	//(internal1_m1684_x0) - значение входного параметра на предыдущем шаге
#define internal1_m1684_tim	 BUFFER[4535]	//(internal1_m1684_tim) - время задержки выходного сигнала
#define idinternal1_m1684_tim	 1416	//(internal1_m1684_tim) - время задержки выходного сигнала
#define internal1_m2068_x0	 BUFFER[4540]	//(internal1_m2068_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m2068_x0	 1417	//(internal1_m2068_x0) - значение входного параметра на предыдущем шаге
#define internal1_m2068_tim	 BUFFER[4542]	//(internal1_m2068_tim) - время задержки выходного сигнала
#define idinternal1_m2068_tim	 1418	//(internal1_m2068_tim) - время задержки выходного сигнала
#define internal1_m1152_q0	 BUFFER[4547]	//(internal1_m1152_q0) q0 - внутренний параметр
#define idinternal1_m1152_q0	 1419	//(internal1_m1152_q0) q0 - внутренний параметр
#define internal1_m1158_q0	 BUFFER[4549]	//(internal1_m1158_q0) q0 - внутренний параметр
#define idinternal1_m1158_q0	 1420	//(internal1_m1158_q0) q0 - внутренний параметр
#define internal1_m1176_q0	 BUFFER[4551]	//(internal1_m1176_q0) q0 - внутренний параметр
#define idinternal1_m1176_q0	 1421	//(internal1_m1176_q0) q0 - внутренний параметр
#define internal1_m1186_q0	 BUFFER[4553]	//(internal1_m1186_q0) q0 - внутренний параметр
#define idinternal1_m1186_q0	 1422	//(internal1_m1186_q0) q0 - внутренний параметр
#define internal1_m1164_q0	 BUFFER[4555]	//(internal1_m1164_q0) q0 - внутренний параметр
#define idinternal1_m1164_q0	 1423	//(internal1_m1164_q0) q0 - внутренний параметр
#define internal1_m1178_q0	 BUFFER[4557]	//(internal1_m1178_q0) q0 - внутренний параметр
#define idinternal1_m1178_q0	 1424	//(internal1_m1178_q0) q0 - внутренний параметр
#define internal1_m2154_q0	 BUFFER[4559]	//(internal1_m2154_q0) q0 - внутренний параметр
#define idinternal1_m2154_q0	 1425	//(internal1_m2154_q0) q0 - внутренний параметр
#define internal1_m2153_q0	 BUFFER[4561]	//(internal1_m2153_q0) q0 - внутренний параметр
#define idinternal1_m2153_q0	 1426	//(internal1_m2153_q0) q0 - внутренний параметр
#define internal1_m352_Step	 BUFFER[4563]	//(internal1_m352_Step)  - текущий шаг программы
#define idinternal1_m352_Step	 1427	//(internal1_m352_Step)  - текущий шаг программы
#define internal1_m352_rz	 BUFFER[4566]	//(internal1_m352_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m352_rz	 1428	//(internal1_m352_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m352_TimS	 BUFFER[4576]	//(internal1_m352_TimS) Время от старта программы
#define idinternal1_m352_TimS	 1429	//(internal1_m352_TimS) Время от старта программы
#define internal1_m352_FinPr0	 BUFFER[4581]	//(internal1_m352_FinPr0) FinPr - конец программы
#define idinternal1_m352_FinPr0	 1430	//(internal1_m352_FinPr0) FinPr - конец программы
#define internal1_m352_ErrPr0	 BUFFER[4583]	//(internal1_m352_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m352_ErrPr0	 1431	//(internal1_m352_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m352_sbINI0	 BUFFER[4585]	//(internal1_m352_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m352_sbINI0	 1432	//(internal1_m352_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m352_sbVuIS0	 BUFFER[4587]	//(internal1_m352_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m352_sbVuIS0	 1433	//(internal1_m352_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m352_sb2UR0	 BUFFER[4589]	//(internal1_m352_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m352_sb2UR0	 1434	//(internal1_m352_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m352_sbNupIS0	 BUFFER[4591]	//(internal1_m352_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m352_sbNupIS0	 1435	//(internal1_m352_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m352_sbVuRB0	 BUFFER[4593]	//(internal1_m352_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m352_sbVuRB0	 1436	//(internal1_m352_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m352_MyFirstEnterFlag	 BUFFER[4595]	//(internal1_m352_MyFirstEnterFlag)  
#define idinternal1_m352_MyFirstEnterFlag	 1437	//(internal1_m352_MyFirstEnterFlag)  
#define internal1_m360_x0	 BUFFER[4597]	//(internal1_m360_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m360_x0	 1438	//(internal1_m360_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m319_TimS	 BUFFER[4602]	//(internal1_m319_TimS) Время до нулевого отсчета
#define idinternal1_m319_TimS	 1439	//(internal1_m319_TimS) Время до нулевого отсчета
#define internal1_m319_pusk0	 BUFFER[4607]	//(internal1_m319_pusk0) pusk - разрешение выполнения программы
#define idinternal1_m319_pusk0	 1440	//(internal1_m319_pusk0) pusk - разрешение выполнения программы
#define internal1_m294_Step	 BUFFER[4609]	//(internal1_m294_Step)  - текущий шаг программы
#define idinternal1_m294_Step	 1441	//(internal1_m294_Step)  - текущий шаг программы
#define internal1_m294_rz	 BUFFER[4612]	//(internal1_m294_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m294_rz	 1442	//(internal1_m294_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m294_TimS	 BUFFER[4622]	//(internal1_m294_TimS) Время от старта программы
#define idinternal1_m294_TimS	 1443	//(internal1_m294_TimS) Время от старта программы
#define internal1_m294_FinPr0	 BUFFER[4627]	//(internal1_m294_FinPr0) FinPr - конец программы
#define idinternal1_m294_FinPr0	 1444	//(internal1_m294_FinPr0) FinPr - конец программы
#define internal1_m294_ErrPr0	 BUFFER[4629]	//(internal1_m294_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m294_ErrPr0	 1445	//(internal1_m294_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m294_sbINI0	 BUFFER[4631]	//(internal1_m294_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m294_sbINI0	 1446	//(internal1_m294_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m294_sbVuIS0	 BUFFER[4633]	//(internal1_m294_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m294_sbVuIS0	 1447	//(internal1_m294_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m294_sb2UR0	 BUFFER[4635]	//(internal1_m294_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m294_sb2UR0	 1448	//(internal1_m294_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m294_sbNupIS0	 BUFFER[4637]	//(internal1_m294_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m294_sbNupIS0	 1449	//(internal1_m294_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m294_sbVuRB0	 BUFFER[4639]	//(internal1_m294_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m294_sbVuRB0	 1450	//(internal1_m294_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m294_MyFirstEnterFlag	 BUFFER[4641]	//(internal1_m294_MyFirstEnterFlag)  
#define idinternal1_m294_MyFirstEnterFlag	 1451	//(internal1_m294_MyFirstEnterFlag)  
#define internal1_m1595_q0	 BUFFER[4643]	//(internal1_m1595_q0) q0 - внутренний параметр
#define idinternal1_m1595_q0	 1452	//(internal1_m1595_q0) q0 - внутренний параметр
#define internal1_m1596_Step	 BUFFER[4645]	//(internal1_m1596_Step)  - текущий шаг программы
#define idinternal1_m1596_Step	 1453	//(internal1_m1596_Step)  - текущий шаг программы
#define internal1_m1596_rz	 BUFFER[4648]	//(internal1_m1596_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m1596_rz	 1454	//(internal1_m1596_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m1596_TimS	 BUFFER[4654]	//(internal1_m1596_TimS) Время от старта программы
#define idinternal1_m1596_TimS	 1455	//(internal1_m1596_TimS) Время от старта программы
#define internal1_m1596_FinPr0	 BUFFER[4659]	//(internal1_m1596_FinPr0) FinPr - конец программы
#define idinternal1_m1596_FinPr0	 1456	//(internal1_m1596_FinPr0) FinPr - конец программы
#define internal1_m1596_ErrPr0	 BUFFER[4661]	//(internal1_m1596_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m1596_ErrPr0	 1457	//(internal1_m1596_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m1596_sbINI0	 BUFFER[4663]	//(internal1_m1596_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m1596_sbINI0	 1458	//(internal1_m1596_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m1596_sbVuIS0	 BUFFER[4665]	//(internal1_m1596_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m1596_sbVuIS0	 1459	//(internal1_m1596_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m1596_sb2UR0	 BUFFER[4667]	//(internal1_m1596_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m1596_sb2UR0	 1460	//(internal1_m1596_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m1596_sbNupIS0	 BUFFER[4669]	//(internal1_m1596_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m1596_sbNupIS0	 1461	//(internal1_m1596_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m1596_sbVuRB0	 BUFFER[4671]	//(internal1_m1596_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m1596_sbVuRB0	 1462	//(internal1_m1596_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m1596_MyFirstEnterFlag	 BUFFER[4673]	//(internal1_m1596_MyFirstEnterFlag)  
#define idinternal1_m1596_MyFirstEnterFlag	 1463	//(internal1_m1596_MyFirstEnterFlag)  
#define internal1_m1148_q0	 BUFFER[4675]	//(internal1_m1148_q0) q0 - внутренний параметр
#define idinternal1_m1148_q0	 1464	//(internal1_m1148_q0) q0 - внутренний параметр
#define internal1_m1145_q0	 BUFFER[4677]	//(internal1_m1145_q0) q0 - внутренний параметр
#define idinternal1_m1145_q0	 1465	//(internal1_m1145_q0) q0 - внутренний параметр
#define internal1_m1147_q0	 BUFFER[4679]	//(internal1_m1147_q0) q0 - внутренний параметр
#define idinternal1_m1147_q0	 1466	//(internal1_m1147_q0) q0 - внутренний параметр
#define internal1_m1141_q0	 BUFFER[4681]	//(internal1_m1141_q0) q0 - внутренний параметр
#define idinternal1_m1141_q0	 1467	//(internal1_m1141_q0) q0 - внутренний параметр
#define internal1_m832_q0	 BUFFER[4683]	//(internal1_m832_q0) q0 - внутренний параметр
#define idinternal1_m832_q0	 1468	//(internal1_m832_q0) q0 - внутренний параметр
#define internal1_m362_q0	 BUFFER[4685]	//(internal1_m362_q0) q0 - внутренний параметр
#define idinternal1_m362_q0	 1469	//(internal1_m362_q0) q0 - внутренний параметр
#define internal1_m358_q0	 BUFFER[4687]	//(internal1_m358_q0) q0 - внутренний параметр
#define idinternal1_m358_q0	 1470	//(internal1_m358_q0) q0 - внутренний параметр
#define internal1_m314_q0	 BUFFER[4689]	//(internal1_m314_q0) q0 - внутренний параметр
#define idinternal1_m314_q0	 1471	//(internal1_m314_q0) q0 - внутренний параметр
#define internal1_m313_x0	 BUFFER[4691]	//(internal1_m313_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m313_x0	 1472	//(internal1_m313_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m2083_q0	 BUFFER[4696]	//(internal1_m2083_q0) q0 - внутренний параметр
#define idinternal1_m2083_q0	 1473	//(internal1_m2083_q0) q0 - внутренний параметр
#define internal1_m2076_q0	 BUFFER[4698]	//(internal1_m2076_q0) q0 - внутренний параметр
#define idinternal1_m2076_q0	 1474	//(internal1_m2076_q0) q0 - внутренний параметр
#define internal1_m2071_q0	 BUFFER[4700]	//(internal1_m2071_q0) q0 - внутренний параметр
#define idinternal1_m2071_q0	 1475	//(internal1_m2071_q0) q0 - внутренний параметр
#define internal1_m2137_q0	 BUFFER[4702]	//(internal1_m2137_q0) q0 - внутренний параметр
#define idinternal1_m2137_q0	 1476	//(internal1_m2137_q0) q0 - внутренний параметр
#define internal1_m2108_q0	 BUFFER[4704]	//(internal1_m2108_q0) q0 - внутренний параметр
#define idinternal1_m2108_q0	 1477	//(internal1_m2108_q0) q0 - внутренний параметр
#define internal1_m2096_q0	 BUFFER[4706]	//(internal1_m2096_q0) q0 - внутренний параметр
#define idinternal1_m2096_q0	 1478	//(internal1_m2096_q0) q0 - внутренний параметр
#define internal1_m1660_q0	 BUFFER[4708]	//(internal1_m1660_q0) q0 - внутренний параметр
#define idinternal1_m1660_q0	 1479	//(internal1_m1660_q0) q0 - внутренний параметр
#define internal1_m1647_x0	 BUFFER[4710]	//(internal1_m1647_x0) был приход сигнала x1
#define idinternal1_m1647_x0	 1480	//(internal1_m1647_x0) был приход сигнала x1
#define internal1_m1647_y0	 BUFFER[4712]	//(internal1_m1647_y0) интервал между сигналами х1 и х2
#define idinternal1_m1647_y0	 1481	//(internal1_m1647_y0) интервал между сигналами х1 и х2
#define internal1_m1647_fef	 BUFFER[4717]	//(internal1_m1647_fef) FirstEnterFlag
#define idinternal1_m1647_fef	 1482	//(internal1_m1647_fef) FirstEnterFlag
#define internal1_m1642_q0	 BUFFER[4719]	//(internal1_m1642_q0) q0 - внутренний параметр
#define idinternal1_m1642_q0	 1483	//(internal1_m1642_q0) q0 - внутренний параметр
#define internal1_m1632_q0	 BUFFER[4721]	//(internal1_m1632_q0) q0 - внутренний параметр
#define idinternal1_m1632_q0	 1484	//(internal1_m1632_q0) q0 - внутренний параметр
#define internal1_m1695_q0	 BUFFER[4723]	//(internal1_m1695_q0) q0 - внутренний параметр
#define idinternal1_m1695_q0	 1485	//(internal1_m1695_q0) q0 - внутренний параметр
#define internal1_m1716_q0	 BUFFER[4725]	//(internal1_m1716_q0) q0 - внутренний параметр
#define idinternal1_m1716_q0	 1486	//(internal1_m1716_q0) q0 - внутренний параметр
#define internal1_m1680_q0	 BUFFER[4727]	//(internal1_m1680_q0) q0 - внутренний параметр
#define idinternal1_m1680_q0	 1487	//(internal1_m1680_q0) q0 - внутренний параметр
#define internal1_m1696_x0	 BUFFER[4729]	//(internal1_m1696_x0) был приход сигнала x1
#define idinternal1_m1696_x0	 1488	//(internal1_m1696_x0) был приход сигнала x1
#define internal1_m1696_y0	 BUFFER[4731]	//(internal1_m1696_y0) интервал между сигналами х1 и х2
#define idinternal1_m1696_y0	 1489	//(internal1_m1696_y0) интервал между сигналами х1 и х2
#define internal1_m1696_fef	 BUFFER[4736]	//(internal1_m1696_fef) FirstEnterFlag
#define idinternal1_m1696_fef	 1490	//(internal1_m1696_fef) FirstEnterFlag
#define internal1_m1613_x0	 BUFFER[4738]	//(internal1_m1613_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1613_x0	 1491	//(internal1_m1613_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1702_q0	 BUFFER[4743]	//(internal1_m1702_q0) q0 - внутренний параметр
#define idinternal1_m1702_q0	 1492	//(internal1_m1702_q0) q0 - внутренний параметр
#define internal1_m26_q0	 BUFFER[4745]	//(internal1_m26_q0) q0 - внутренний параметр
#define idinternal1_m26_q0	 1493	//(internal1_m26_q0) q0 - внутренний параметр
#define internal1_m1717_q0	 BUFFER[4747]	//(internal1_m1717_q0) q0 - внутренний параметр
#define idinternal1_m1717_q0	 1494	//(internal1_m1717_q0) q0 - внутренний параметр
#define internal1_m707_q0	 BUFFER[4749]	//(internal1_m707_q0) q0 - внутренний параметр
#define idinternal1_m707_q0	 1495	//(internal1_m707_q0) q0 - внутренний параметр
#define internal1_m692_q0	 BUFFER[4751]	//(internal1_m692_q0) q0 - внутренний параметр
#define idinternal1_m692_q0	 1496	//(internal1_m692_q0) q0 - внутренний параметр
#define internal1_m719_q0	 BUFFER[4753]	//(internal1_m719_q0) q0 - внутренний параметр
#define idinternal1_m719_q0	 1497	//(internal1_m719_q0) q0 - внутренний параметр
#define internal1_m703_q0	 BUFFER[4755]	//(internal1_m703_q0) q0 - внутренний параметр
#define idinternal1_m703_q0	 1498	//(internal1_m703_q0) q0 - внутренний параметр
#define internal1_m687_q0	 BUFFER[4757]	//(internal1_m687_q0) q0 - внутренний параметр
#define idinternal1_m687_q0	 1499	//(internal1_m687_q0) q0 - внутренний параметр
#define internal1_m685_q0	 BUFFER[4759]	//(internal1_m685_q0) q0 - внутренний параметр
#define idinternal1_m685_q0	 1500	//(internal1_m685_q0) q0 - внутренний параметр
#define internal1_m673_q0	 BUFFER[4761]	//(internal1_m673_q0) q0 - внутренний параметр
#define idinternal1_m673_q0	 1501	//(internal1_m673_q0) q0 - внутренний параметр
#define internal1_m1598_q0	 BUFFER[4763]	//(internal1_m1598_q0) q0 - внутренний параметр
#define idinternal1_m1598_q0	 1502	//(internal1_m1598_q0) q0 - внутренний параметр
#define internal1_m683_q0	 BUFFER[4768]	//(internal1_m683_q0) q0 - внутренний параметр
#define idinternal1_m683_q0	 1503	//(internal1_m683_q0) q0 - внутренний параметр
#define internal1_m116_q0	 BUFFER[4770]	//(internal1_m116_q0) q0 - внутренний параметр
#define idinternal1_m116_q0	 1504	//(internal1_m116_q0) q0 - внутренний параметр
#define internal1_m1863_q0	 BUFFER[4772]	//(internal1_m1863_q0) q0 - внутренний параметр
#define idinternal1_m1863_q0	 1505	//(internal1_m1863_q0) q0 - внутренний параметр
#define internal1_m1862_q0	 BUFFER[4774]	//(internal1_m1862_q0) q0 - внутренний параметр
#define idinternal1_m1862_q0	 1506	//(internal1_m1862_q0) q0 - внутренний параметр
#define internal1_m1861_q0	 BUFFER[4776]	//(internal1_m1861_q0) q0 - внутренний параметр
#define idinternal1_m1861_q0	 1507	//(internal1_m1861_q0) q0 - внутренний параметр
#define internal1_m1860_q0	 BUFFER[4778]	//(internal1_m1860_q0) q0 - внутренний параметр
#define idinternal1_m1860_q0	 1508	//(internal1_m1860_q0) q0 - внутренний параметр
#define internal1_m1896_q0	 BUFFER[4780]	//(internal1_m1896_q0) q0 - внутренний параметр
#define idinternal1_m1896_q0	 1509	//(internal1_m1896_q0) q0 - внутренний параметр
#define internal1_m1895_q0	 BUFFER[4782]	//(internal1_m1895_q0) q0 - внутренний параметр
#define idinternal1_m1895_q0	 1510	//(internal1_m1895_q0) q0 - внутренний параметр
#define internal1_m1894_q0	 BUFFER[4784]	//(internal1_m1894_q0) q0 - внутренний параметр
#define idinternal1_m1894_q0	 1511	//(internal1_m1894_q0) q0 - внутренний параметр
#define internal1_m2168_q0	 BUFFER[4786]	//(internal1_m2168_q0) q0 - внутренний параметр
#define idinternal1_m2168_q0	 1512	//(internal1_m2168_q0) q0 - внутренний параметр
#define internal1_m1956_q0	 BUFFER[4788]	//(internal1_m1956_q0) q0 - внутренний параметр
#define idinternal1_m1956_q0	 1513	//(internal1_m1956_q0) q0 - внутренний параметр
#define internal1_m1945_q0	 BUFFER[4790]	//(internal1_m1945_q0) q0 - внутренний параметр
#define idinternal1_m1945_q0	 1514	//(internal1_m1945_q0) q0 - внутренний параметр
#define internal1_m1953_q0	 BUFFER[4792]	//(internal1_m1953_q0) q0 - внутренний параметр
#define idinternal1_m1953_q0	 1515	//(internal1_m1953_q0) q0 - внутренний параметр
#define internal1_m1942_q0	 BUFFER[4794]	//(internal1_m1942_q0) q0 - внутренний параметр
#define idinternal1_m1942_q0	 1516	//(internal1_m1942_q0) q0 - внутренний параметр
#define internal1_m1950_q0	 BUFFER[4796]	//(internal1_m1950_q0) q0 - внутренний параметр
#define idinternal1_m1950_q0	 1517	//(internal1_m1950_q0) q0 - внутренний параметр
#define internal1_m2384_q0	 BUFFER[4798]	//(internal1_m2384_q0) q0 - внутренний параметр
#define idinternal1_m2384_q0	 1518	//(internal1_m2384_q0) q0 - внутренний параметр
#define internal1_m2380_q0	 BUFFER[4800]	//(internal1_m2380_q0) q0 - внутренний параметр
#define idinternal1_m2380_q0	 1519	//(internal1_m2380_q0) q0 - внутренний параметр
#define internal1_m1921_q0	 BUFFER[4802]	//(internal1_m1921_q0) q0 - внутренний параметр
#define idinternal1_m1921_q0	 1520	//(internal1_m1921_q0) q0 - внутренний параметр
#define internal1_m1913_q0	 BUFFER[4804]	//(internal1_m1913_q0) q0 - внутренний параметр
#define idinternal1_m1913_q0	 1521	//(internal1_m1913_q0) q0 - внутренний параметр
#define internal1_m1911_q0	 BUFFER[4806]	//(internal1_m1911_q0) q0 - внутренний параметр
#define idinternal1_m1911_q0	 1522	//(internal1_m1911_q0) q0 - внутренний параметр
#define internal1_m1907_q0	 BUFFER[4808]	//(internal1_m1907_q0) q0 - внутренний параметр
#define idinternal1_m1907_q0	 1523	//(internal1_m1907_q0) q0 - внутренний параметр
#define internal1_m1903_q0	 BUFFER[4810]	//(internal1_m1903_q0) q0 - внутренний параметр
#define idinternal1_m1903_q0	 1524	//(internal1_m1903_q0) q0 - внутренний параметр
#define internal1_m1905_q0	 BUFFER[4812]	//(internal1_m1905_q0) q0 - внутренний параметр
#define idinternal1_m1905_q0	 1525	//(internal1_m1905_q0) q0 - внутренний параметр
#define internal1_m19_q0	 BUFFER[4814]	//(internal1_m19_q0) q0 - внутренний параметр
#define idinternal1_m19_q0	 1526	//(internal1_m19_q0) q0 - внутренний параметр
#define internal1_m1886_q0	 BUFFER[4816]	//(internal1_m1886_q0) q0 - внутренний параметр
#define idinternal1_m1886_q0	 1527	//(internal1_m1886_q0) q0 - внутренний параметр
#define internal1_m1884_q0	 BUFFER[4818]	//(internal1_m1884_q0) q0 - внутренний параметр
#define idinternal1_m1884_q0	 1528	//(internal1_m1884_q0) q0 - внутренний параметр
#define internal1_m1880_q0	 BUFFER[4820]	//(internal1_m1880_q0) q0 - внутренний параметр
#define idinternal1_m1880_q0	 1529	//(internal1_m1880_q0) q0 - внутренний параметр
#define internal1_m1882_q0	 BUFFER[4822]	//(internal1_m1882_q0) q0 - внутренний параметр
#define idinternal1_m1882_q0	 1530	//(internal1_m1882_q0) q0 - внутренний параметр
#define internal1_m1878_q0	 BUFFER[4824]	//(internal1_m1878_q0) q0 - внутренний параметр
#define idinternal1_m1878_q0	 1531	//(internal1_m1878_q0) q0 - внутренний параметр
#define internal1_m1876_q0	 BUFFER[4826]	//(internal1_m1876_q0) q0 - внутренний параметр
#define idinternal1_m1876_q0	 1532	//(internal1_m1876_q0) q0 - внутренний параметр
#define internal1_m2293_q0	 BUFFER[4828]	//(internal1_m2293_q0) q0 - внутренний параметр
#define idinternal1_m2293_q0	 1533	//(internal1_m2293_q0) q0 - внутренний параметр
#define internal1_m2288_q0	 BUFFER[4830]	//(internal1_m2288_q0) q0 - внутренний параметр
#define idinternal1_m2288_q0	 1534	//(internal1_m2288_q0) q0 - внутренний параметр
#define internal1_m2265_q0	 BUFFER[4832]	//(internal1_m2265_q0) q0 - внутренний параметр
#define idinternal1_m2265_q0	 1535	//(internal1_m2265_q0) q0 - внутренний параметр
#define internal1_m2249_q0	 BUFFER[4834]	//(internal1_m2249_q0) q0 - внутренний параметр
#define idinternal1_m2249_q0	 1536	//(internal1_m2249_q0) q0 - внутренний параметр
#define internal1_m2180_q0	 BUFFER[4836]	//(internal1_m2180_q0) q0 - внутренний параметр
#define idinternal1_m2180_q0	 1537	//(internal1_m2180_q0) q0 - внутренний параметр
#define internal1_m1872_q0	 BUFFER[4838]	//(internal1_m1872_q0) q0 - внутренний параметр
#define idinternal1_m1872_q0	 1538	//(internal1_m1872_q0) q0 - внутренний параметр
#define internal1_m1874_q0	 BUFFER[4840]	//(internal1_m1874_q0) q0 - внутренний параметр
#define idinternal1_m1874_q0	 1539	//(internal1_m1874_q0) q0 - внутренний параметр
#define internal1_m1858_q0	 BUFFER[4842]	//(internal1_m1858_q0) q0 - внутренний параметр
#define idinternal1_m1858_q0	 1540	//(internal1_m1858_q0) q0 - внутренний параметр
#define internal1_m1856_q0	 BUFFER[4844]	//(internal1_m1856_q0) q0 - внутренний параметр
#define idinternal1_m1856_q0	 1541	//(internal1_m1856_q0) q0 - внутренний параметр
#define internal1_m1854_q0	 BUFFER[4846]	//(internal1_m1854_q0) q0 - внутренний параметр
#define idinternal1_m1854_q0	 1542	//(internal1_m1854_q0) q0 - внутренний параметр
#define internal1_m1852_q0	 BUFFER[4848]	//(internal1_m1852_q0) q0 - внутренний параметр
#define idinternal1_m1852_q0	 1543	//(internal1_m1852_q0) q0 - внутренний параметр
#define internal1_m1851_q0	 BUFFER[4850]	//(internal1_m1851_q0) q0 - внутренний параметр
#define idinternal1_m1851_q0	 1544	//(internal1_m1851_q0) q0 - внутренний параметр
#define internal1_m1849_q0	 BUFFER[4852]	//(internal1_m1849_q0) q0 - внутренний параметр
#define idinternal1_m1849_q0	 1545	//(internal1_m1849_q0) q0 - внутренний параметр
#define internal1_m1848_q0	 BUFFER[4854]	//(internal1_m1848_q0) q0 - внутренний параметр
#define idinternal1_m1848_q0	 1546	//(internal1_m1848_q0) q0 - внутренний параметр
#define internal1_m1846_q0	 BUFFER[4856]	//(internal1_m1846_q0) q0 - внутренний параметр
#define idinternal1_m1846_q0	 1547	//(internal1_m1846_q0) q0 - внутренний параметр
#define internal1_m2321_DvUp0	 BUFFER[4858]	//(internal1_m2321_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2321_DvUp0	 1548	//(internal1_m2321_DvUp0) - есть команда на движение вперёд
#define internal1_m2321_DvDw0	 BUFFER[4859]	//(internal1_m2321_DvDw0) - есть команда на движение назад
#define idinternal1_m2321_DvDw0	 1549	//(internal1_m2321_DvDw0) - есть команда на движение назад
#define internal1_m2321_FDvUp0	 BUFFER[4860]	//(internal1_m2321_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2321_FDvUp0	 1550	//(internal1_m2321_FDvUp0) - есть команда на движение вперёд
#define internal1_m2321_FDvDw0	 BUFFER[4861]	//(internal1_m2321_FDvDw0) - есть команда на движение назад
#define idinternal1_m2321_FDvDw0	 1551	//(internal1_m2321_FDvDw0) - есть команда на движение назад
#define internal1_m2321_BlDv0	 BUFFER[4862]	//(internal1_m2321_BlDv0) - была блокировка
#define idinternal1_m2321_BlDv0	 1552	//(internal1_m2321_BlDv0) - была блокировка
#define internal1_m2321_Pkv0	 BUFFER[4863]	//(internal1_m2321_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2321_Pkv0	 1553	//(internal1_m2321_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2321_Pkav0	 BUFFER[4864]	//(internal1_m2321_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2321_Pkav0	 1554	//(internal1_m2321_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2321_Zkv0	 BUFFER[4865]	//(internal1_m2321_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2321_Zkv0	 1555	//(internal1_m2321_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2321_Zkav0	 BUFFER[4866]	//(internal1_m2321_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2321_Zkav0	 1556	//(internal1_m2321_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2321_txNm	 BUFFER[4867]	//(internal1_m2321_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2321_txNm	 1557	//(internal1_m2321_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2321_txSm	 BUFFER[4872]	//(internal1_m2321_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2321_txSm	 1558	//(internal1_m2321_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2321_txHr	 BUFFER[4877]	//(internal1_m2321_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2321_txHr	 1559	//(internal1_m2321_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2321_txLd	 BUFFER[4882]	//(internal1_m2321_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2321_txLd	 1560	//(internal1_m2321_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2321_fef	 BUFFER[4887]	//(internal1_m2321_fef) fef
#define idinternal1_m2321_fef	 1561	//(internal1_m2321_fef) fef
#define internal1_m2315_DvUp0	 BUFFER[4888]	//(internal1_m2315_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2315_DvUp0	 1562	//(internal1_m2315_DvUp0) - есть команда на движение вперёд
#define internal1_m2315_DvDw0	 BUFFER[4889]	//(internal1_m2315_DvDw0) - есть команда на движение назад
#define idinternal1_m2315_DvDw0	 1563	//(internal1_m2315_DvDw0) - есть команда на движение назад
#define internal1_m2315_FDvUp0	 BUFFER[4890]	//(internal1_m2315_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2315_FDvUp0	 1564	//(internal1_m2315_FDvUp0) - есть команда на движение вперёд
#define internal1_m2315_FDvDw0	 BUFFER[4891]	//(internal1_m2315_FDvDw0) - есть команда на движение назад
#define idinternal1_m2315_FDvDw0	 1565	//(internal1_m2315_FDvDw0) - есть команда на движение назад
#define internal1_m2315_BlDv0	 BUFFER[4892]	//(internal1_m2315_BlDv0) - была блокировка
#define idinternal1_m2315_BlDv0	 1566	//(internal1_m2315_BlDv0) - была блокировка
#define internal1_m2315_Pkv0	 BUFFER[4893]	//(internal1_m2315_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2315_Pkv0	 1567	//(internal1_m2315_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2315_Pkav0	 BUFFER[4894]	//(internal1_m2315_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2315_Pkav0	 1568	//(internal1_m2315_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2315_Zkv0	 BUFFER[4895]	//(internal1_m2315_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2315_Zkv0	 1569	//(internal1_m2315_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2315_Zkav0	 BUFFER[4896]	//(internal1_m2315_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2315_Zkav0	 1570	//(internal1_m2315_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2315_txNm	 BUFFER[4897]	//(internal1_m2315_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2315_txNm	 1571	//(internal1_m2315_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2315_txSm	 BUFFER[4902]	//(internal1_m2315_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2315_txSm	 1572	//(internal1_m2315_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2315_txHr	 BUFFER[4907]	//(internal1_m2315_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2315_txHr	 1573	//(internal1_m2315_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2315_txLd	 BUFFER[4912]	//(internal1_m2315_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2315_txLd	 1574	//(internal1_m2315_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2315_fef	 BUFFER[4917]	//(internal1_m2315_fef) fef
#define idinternal1_m2315_fef	 1575	//(internal1_m2315_fef) fef
#define internal1_m1675_q0	 BUFFER[4918]	//(internal1_m1675_q0) q0 - внутренний параметр
#define idinternal1_m1675_q0	 1576	//(internal1_m1675_q0) q0 - внутренний параметр
#define internal1_m1697_x0	 BUFFER[4920]	//(internal1_m1697_x0) был приход сигнала x1
#define idinternal1_m1697_x0	 1577	//(internal1_m1697_x0) был приход сигнала x1
#define internal1_m1697_y0	 BUFFER[4922]	//(internal1_m1697_y0) интервал между сигналами х1 и х2
#define idinternal1_m1697_y0	 1578	//(internal1_m1697_y0) интервал между сигналами х1 и х2
#define internal1_m1697_fef	 BUFFER[4927]	//(internal1_m1697_fef) FirstEnterFlag
#define idinternal1_m1697_fef	 1579	//(internal1_m1697_fef) FirstEnterFlag
#define internal1_m2119_x0	 BUFFER[4929]	//(internal1_m2119_x0) был приход сигнала x1
#define idinternal1_m2119_x0	 1580	//(internal1_m2119_x0) был приход сигнала x1
#define internal1_m2119_y0	 BUFFER[4931]	//(internal1_m2119_y0) интервал между сигналами х1 и х2
#define idinternal1_m2119_y0	 1581	//(internal1_m2119_y0) интервал между сигналами х1 и х2
#define internal1_m2119_fef	 BUFFER[4936]	//(internal1_m2119_fef) FirstEnterFlag
#define idinternal1_m2119_fef	 1582	//(internal1_m2119_fef) FirstEnterFlag
#define internal1_m2078_x0	 BUFFER[4938]	//(internal1_m2078_x0) был приход сигнала x1
#define idinternal1_m2078_x0	 1583	//(internal1_m2078_x0) был приход сигнала x1
#define internal1_m2078_y0	 BUFFER[4940]	//(internal1_m2078_y0) интервал между сигналами х1 и х2
#define idinternal1_m2078_y0	 1584	//(internal1_m2078_y0) интервал между сигналами х1 и х2
#define internal1_m2078_fef	 BUFFER[4945]	//(internal1_m2078_fef) FirstEnterFlag
#define idinternal1_m2078_fef	 1585	//(internal1_m2078_fef) FirstEnterFlag
#define internal1_m305_q0	 BUFFER[4947]	//(internal1_m305_q0) q0 - внутренний параметр
#define idinternal1_m305_q0	 1586	//(internal1_m305_q0) q0 - внутренний параметр
#define internal1_m1120_q0	 BUFFER[4949]	//(internal1_m1120_q0) q0 - внутренний параметр
#define idinternal1_m1120_q0	 1587	//(internal1_m1120_q0) q0 - внутренний параметр
#define internal1_m695_q0	 BUFFER[4951]	//(internal1_m695_q0) q0 - внутренний параметр
#define idinternal1_m695_q0	 1588	//(internal1_m695_q0) q0 - внутренний параметр
#define internal1_m1479_X0	 BUFFER[4953]	//(internal1_m1479_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1479_X0	 1589	//(internal1_m1479_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1479_t0	 BUFFER[4958]	//(internal1_m1479_t0) время нахождения в зоне возврата
#define idinternal1_m1479_t0	 1590	//(internal1_m1479_t0) время нахождения в зоне возврата
#define internal1_m1479_BLDv0	 BUFFER[4963]	//(internal1_m1479_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1479_BLDv0	 1591	//(internal1_m1479_BLDv0) BlDv - Блокировка движения
#define internal1_m1496_tx	 BUFFER[4964]	//(internal1_m1496_tx) tx - время накопленное сек
#define idinternal1_m1496_tx	 1592	//(internal1_m1496_tx) tx - время накопленное сек
#define internal1_m1496_y0	 BUFFER[4969]	//(internal1_m1496_y0) y0
#define idinternal1_m1496_y0	 1593	//(internal1_m1496_y0) y0
#define internal1_m1497_tx	 BUFFER[4970]	//(internal1_m1497_tx) tx - время накопленное сек
#define idinternal1_m1497_tx	 1594	//(internal1_m1497_tx) tx - время накопленное сек
#define internal1_m1497_y0	 BUFFER[4975]	//(internal1_m1497_y0) y0
#define idinternal1_m1497_y0	 1595	//(internal1_m1497_y0) y0
#define internal1_m1505_xptr	 BUFFER[4976]	//(internal1_m1505_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1505_xptr	 1596	//(internal1_m1505_xptr) указатель текущей позиции в массиве координат
#define internal1_m1505_x0	 BUFFER[4979]	//(internal1_m1505_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1505_x0	 1597	//(internal1_m1505_x0) x0 - массив мгновенных значений координат
#define internal1_m1505_tim0	 BUFFER[5279]	//(internal1_m1505_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1505_tim0	 1598	//(internal1_m1505_tim0) tim0 - массив значений времени цикла
#define internal1_m1505_sumtim	 BUFFER[5579]	//(internal1_m1505_sumtim) sumtim - время в пути
#define idinternal1_m1505_sumtim	 1599	//(internal1_m1505_sumtim) sumtim - время в пути
#define internal1_m1505_StSpeed	 BUFFER[5584]	//(internal1_m1505_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1505_StSpeed	 1600	//(internal1_m1505_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1505_Vz0	 BUFFER[5589]	//(internal1_m1505_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1505_Vz0	 1601	//(internal1_m1505_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1505_flRazg	 BUFFER[5594]	//(internal1_m1505_flRazg) признак разгона/торможения
#define idinternal1_m1505_flRazg	 1602	//(internal1_m1505_flRazg) признак разгона/торможения
#define internal1_m1505_DelSp	 BUFFER[5597]	//(internal1_m1505_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1505_DelSp	 1603	//(internal1_m1505_DelSp) DelSp - время переключения скоростей
#define internal1_m1505_z0	 BUFFER[5602]	//(internal1_m1505_z0) z0 - точка прекращения движения
#define idinternal1_m1505_z0	 1604	//(internal1_m1505_z0) z0 - точка прекращения движения
#define internal1_m1505_txZS	 BUFFER[5607]	//(internal1_m1505_txZS) txZS
#define idinternal1_m1505_txZS	 1605	//(internal1_m1505_txZS) txZS
#define internal1_m1505_tx	 BUFFER[5612]	//(internal1_m1505_tx) tx
#define idinternal1_m1505_tx	 1606	//(internal1_m1505_tx) tx
#define internal1_m1505_txd	 BUFFER[5617]	//(internal1_m1505_txd) txd
#define idinternal1_m1505_txd	 1607	//(internal1_m1505_txd) txd
#define internal1_m1505_txMBl	 BUFFER[5622]	//(internal1_m1505_txMBl) tx
#define idinternal1_m1505_txMBl	 1608	//(internal1_m1505_txMBl) tx
#define internal1_m1505_txBl	 BUFFER[5627]	//(internal1_m1505_txBl) tx
#define idinternal1_m1505_txBl	 1609	//(internal1_m1505_txBl) tx
#define internal1_m1505_Speed0	 BUFFER[5632]	//(internal1_m1505_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1505_Speed0	 1610	//(internal1_m1505_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1505_xz0	 BUFFER[5637]	//(internal1_m1505_xz0) xz0 - новое задание мм
#define idinternal1_m1505_xz0	 1611	//(internal1_m1505_xz0) xz0 - новое задание мм
#define internal1_m1505_tz0	 BUFFER[5642]	//(internal1_m1505_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1505_tz0	 1612	//(internal1_m1505_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1505_Shift0	 BUFFER[5647]	//(internal1_m1505_Shift0) Shift0 - признак самохода
#define idinternal1_m1505_Shift0	 1613	//(internal1_m1505_Shift0) Shift0 - признак самохода
#define internal1_m1505_ShCntlSp0	 BUFFER[5649]	//(internal1_m1505_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1505_ShCntlSp0	 1614	//(internal1_m1505_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1505_ShiftControl	 BUFFER[5651]	//(internal1_m1505_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1505_ShiftControl	 1615	//(internal1_m1505_ShiftControl) ShiftControl - признак самохода
#define internal1_m693_q0	 BUFFER[5653]	//(internal1_m693_q0) q0 - внутренний параметр
#define idinternal1_m693_q0	 1616	//(internal1_m693_q0) q0 - внутренний параметр
#define internal1_m1001_X0	 BUFFER[5655]	//(internal1_m1001_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1001_X0	 1617	//(internal1_m1001_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1001_t0	 BUFFER[5660]	//(internal1_m1001_t0) время нахождения в зоне возврата
#define idinternal1_m1001_t0	 1618	//(internal1_m1001_t0) время нахождения в зоне возврата
#define internal1_m1001_BLDv0	 BUFFER[5665]	//(internal1_m1001_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1001_BLDv0	 1619	//(internal1_m1001_BLDv0) BlDv - Блокировка движения
#define internal1_m1024_tx	 BUFFER[5666]	//(internal1_m1024_tx) tx - время накопленное сек
#define idinternal1_m1024_tx	 1620	//(internal1_m1024_tx) tx - время накопленное сек
#define internal1_m1024_y0	 BUFFER[5671]	//(internal1_m1024_y0) y0
#define idinternal1_m1024_y0	 1621	//(internal1_m1024_y0) y0
#define internal1_m1023_tx	 BUFFER[5672]	//(internal1_m1023_tx) tx - время накопленное сек
#define idinternal1_m1023_tx	 1622	//(internal1_m1023_tx) tx - время накопленное сек
#define internal1_m1023_y0	 BUFFER[5677]	//(internal1_m1023_y0) y0
#define idinternal1_m1023_y0	 1623	//(internal1_m1023_y0) y0
#define internal1_m1031_xptr	 BUFFER[5678]	//(internal1_m1031_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1031_xptr	 1624	//(internal1_m1031_xptr) указатель текущей позиции в массиве координат
#define internal1_m1031_x0	 BUFFER[5681]	//(internal1_m1031_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1031_x0	 1625	//(internal1_m1031_x0) x0 - массив мгновенных значений координат
#define internal1_m1031_tim0	 BUFFER[5981]	//(internal1_m1031_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1031_tim0	 1626	//(internal1_m1031_tim0) tim0 - массив значений времени цикла
#define internal1_m1031_sumtim	 BUFFER[6281]	//(internal1_m1031_sumtim) sumtim - время в пути
#define idinternal1_m1031_sumtim	 1627	//(internal1_m1031_sumtim) sumtim - время в пути
#define internal1_m1031_StSpeed	 BUFFER[6286]	//(internal1_m1031_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1031_StSpeed	 1628	//(internal1_m1031_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1031_Vz0	 BUFFER[6291]	//(internal1_m1031_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1031_Vz0	 1629	//(internal1_m1031_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1031_flRazg	 BUFFER[6296]	//(internal1_m1031_flRazg) признак разгона/торможения
#define idinternal1_m1031_flRazg	 1630	//(internal1_m1031_flRazg) признак разгона/торможения
#define internal1_m1031_DelSp	 BUFFER[6299]	//(internal1_m1031_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1031_DelSp	 1631	//(internal1_m1031_DelSp) DelSp - время переключения скоростей
#define internal1_m1031_z0	 BUFFER[6304]	//(internal1_m1031_z0) z0 - точка прекращения движения
#define idinternal1_m1031_z0	 1632	//(internal1_m1031_z0) z0 - точка прекращения движения
#define internal1_m1031_txZS	 BUFFER[6309]	//(internal1_m1031_txZS) txZS
#define idinternal1_m1031_txZS	 1633	//(internal1_m1031_txZS) txZS
#define internal1_m1031_tx	 BUFFER[6314]	//(internal1_m1031_tx) tx
#define idinternal1_m1031_tx	 1634	//(internal1_m1031_tx) tx
#define internal1_m1031_txd	 BUFFER[6319]	//(internal1_m1031_txd) txd
#define idinternal1_m1031_txd	 1635	//(internal1_m1031_txd) txd
#define internal1_m1031_txMBl	 BUFFER[6324]	//(internal1_m1031_txMBl) tx
#define idinternal1_m1031_txMBl	 1636	//(internal1_m1031_txMBl) tx
#define internal1_m1031_txBl	 BUFFER[6329]	//(internal1_m1031_txBl) tx
#define idinternal1_m1031_txBl	 1637	//(internal1_m1031_txBl) tx
#define internal1_m1031_Speed0	 BUFFER[6334]	//(internal1_m1031_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1031_Speed0	 1638	//(internal1_m1031_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1031_xz0	 BUFFER[6339]	//(internal1_m1031_xz0) xz0 - новое задание мм
#define idinternal1_m1031_xz0	 1639	//(internal1_m1031_xz0) xz0 - новое задание мм
#define internal1_m1031_tz0	 BUFFER[6344]	//(internal1_m1031_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1031_tz0	 1640	//(internal1_m1031_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1031_Shift0	 BUFFER[6349]	//(internal1_m1031_Shift0) Shift0 - признак самохода
#define idinternal1_m1031_Shift0	 1641	//(internal1_m1031_Shift0) Shift0 - признак самохода
#define internal1_m1031_ShCntlSp0	 BUFFER[6351]	//(internal1_m1031_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1031_ShCntlSp0	 1642	//(internal1_m1031_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1031_ShiftControl	 BUFFER[6353]	//(internal1_m1031_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1031_ShiftControl	 1643	//(internal1_m1031_ShiftControl) ShiftControl - признак самохода
#define internal1_m546_X0	 BUFFER[6355]	//(internal1_m546_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m546_X0	 1644	//(internal1_m546_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m546_t0	 BUFFER[6360]	//(internal1_m546_t0) время нахождения в зоне возврата
#define idinternal1_m546_t0	 1645	//(internal1_m546_t0) время нахождения в зоне возврата
#define internal1_m546_BLDv0	 BUFFER[6365]	//(internal1_m546_BLDv0) BlDv - Блокировка движения
#define idinternal1_m546_BLDv0	 1646	//(internal1_m546_BLDv0) BlDv - Блокировка движения
#define internal1_m565_tx	 BUFFER[6366]	//(internal1_m565_tx) tx - время накопленное сек
#define idinternal1_m565_tx	 1647	//(internal1_m565_tx) tx - время накопленное сек
#define internal1_m565_y0	 BUFFER[6371]	//(internal1_m565_y0) y0
#define idinternal1_m565_y0	 1648	//(internal1_m565_y0) y0
#define internal1_m564_tx	 BUFFER[6372]	//(internal1_m564_tx) tx - время накопленное сек
#define idinternal1_m564_tx	 1649	//(internal1_m564_tx) tx - время накопленное сек
#define internal1_m564_y0	 BUFFER[6377]	//(internal1_m564_y0) y0
#define idinternal1_m564_y0	 1650	//(internal1_m564_y0) y0
#define internal1_m569_xptr	 BUFFER[6378]	//(internal1_m569_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m569_xptr	 1651	//(internal1_m569_xptr) указатель текущей позиции в массиве координат
#define internal1_m569_x0	 BUFFER[6381]	//(internal1_m569_x0) x0 - массив мгновенных значений координат
#define idinternal1_m569_x0	 1652	//(internal1_m569_x0) x0 - массив мгновенных значений координат
#define internal1_m569_tim0	 BUFFER[7131]	//(internal1_m569_tim0) tim0 - массив значений времени цикла
#define idinternal1_m569_tim0	 1653	//(internal1_m569_tim0) tim0 - массив значений времени цикла
#define internal1_m569_sumtim	 BUFFER[7881]	//(internal1_m569_sumtim) sumtim - время в пути
#define idinternal1_m569_sumtim	 1654	//(internal1_m569_sumtim) sumtim - время в пути
#define internal1_m569_StSpeed	 BUFFER[7886]	//(internal1_m569_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m569_StSpeed	 1655	//(internal1_m569_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m569_Vz0	 BUFFER[7891]	//(internal1_m569_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m569_Vz0	 1656	//(internal1_m569_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m569_flRazg	 BUFFER[7896]	//(internal1_m569_flRazg) признак разгона/торможения
#define idinternal1_m569_flRazg	 1657	//(internal1_m569_flRazg) признак разгона/торможения
#define internal1_m569_DelSp	 BUFFER[7899]	//(internal1_m569_DelSp) DelSp - время переключения скоростей
#define idinternal1_m569_DelSp	 1658	//(internal1_m569_DelSp) DelSp - время переключения скоростей
#define internal1_m569_z0	 BUFFER[7904]	//(internal1_m569_z0) z0 - точка прекращения движения
#define idinternal1_m569_z0	 1659	//(internal1_m569_z0) z0 - точка прекращения движения
#define internal1_m569_txZS	 BUFFER[7909]	//(internal1_m569_txZS) txZS
#define idinternal1_m569_txZS	 1660	//(internal1_m569_txZS) txZS
#define internal1_m569_tx	 BUFFER[7914]	//(internal1_m569_tx) tx
#define idinternal1_m569_tx	 1661	//(internal1_m569_tx) tx
#define internal1_m569_txd	 BUFFER[7919]	//(internal1_m569_txd) txd
#define idinternal1_m569_txd	 1662	//(internal1_m569_txd) txd
#define internal1_m569_txMBl	 BUFFER[7924]	//(internal1_m569_txMBl) tx
#define idinternal1_m569_txMBl	 1663	//(internal1_m569_txMBl) tx
#define internal1_m569_txBl	 BUFFER[7929]	//(internal1_m569_txBl) tx
#define idinternal1_m569_txBl	 1664	//(internal1_m569_txBl) tx
#define internal1_m569_Speed0	 BUFFER[7934]	//(internal1_m569_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m569_Speed0	 1665	//(internal1_m569_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m569_xz0	 BUFFER[7939]	//(internal1_m569_xz0) xz0 - новое задание мм
#define idinternal1_m569_xz0	 1666	//(internal1_m569_xz0) xz0 - новое задание мм
#define internal1_m569_tz0	 BUFFER[7944]	//(internal1_m569_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m569_tz0	 1667	//(internal1_m569_tz0) tz0 - время защиты от нового задания сек
#define internal1_m569_Shift0	 BUFFER[7949]	//(internal1_m569_Shift0) Shift0 - признак самохода
#define idinternal1_m569_Shift0	 1668	//(internal1_m569_Shift0) Shift0 - признак самохода
#define internal1_m569_ShCntlSp0	 BUFFER[7951]	//(internal1_m569_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m569_ShCntlSp0	 1669	//(internal1_m569_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m569_ShiftControl	 BUFFER[7953]	//(internal1_m569_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m569_ShiftControl	 1670	//(internal1_m569_ShiftControl) ShiftControl - признак самохода
#define internal1_m690_q0	 BUFFER[7955]	//(internal1_m690_q0) q0 - внутренний параметр
#define idinternal1_m690_q0	 1671	//(internal1_m690_q0) q0 - внутренний параметр
#define internal1_m176_X0	 BUFFER[7957]	//(internal1_m176_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m176_X0	 1672	//(internal1_m176_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m176_t0	 BUFFER[7962]	//(internal1_m176_t0) время нахождения в зоне возврата
#define idinternal1_m176_t0	 1673	//(internal1_m176_t0) время нахождения в зоне возврата
#define internal1_m176_BLDv0	 BUFFER[7967]	//(internal1_m176_BLDv0) BlDv - Блокировка движения
#define idinternal1_m176_BLDv0	 1674	//(internal1_m176_BLDv0) BlDv - Блокировка движения
#define internal1_m201_xptr	 BUFFER[7968]	//(internal1_m201_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m201_xptr	 1675	//(internal1_m201_xptr) указатель текущей позиции в массиве координат
#define internal1_m201_x0	 BUFFER[7971]	//(internal1_m201_x0) x0 - массив мгновенных значений координат
#define idinternal1_m201_x0	 1676	//(internal1_m201_x0) x0 - массив мгновенных значений координат
#define internal1_m201_tim0	 BUFFER[8721]	//(internal1_m201_tim0) tim0 - массив значений времени цикла
#define idinternal1_m201_tim0	 1677	//(internal1_m201_tim0) tim0 - массив значений времени цикла
#define internal1_m201_sumtim	 BUFFER[9471]	//(internal1_m201_sumtim) sumtim - время в пути
#define idinternal1_m201_sumtim	 1678	//(internal1_m201_sumtim) sumtim - время в пути
#define internal1_m201_StSpeed	 BUFFER[9476]	//(internal1_m201_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m201_StSpeed	 1679	//(internal1_m201_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m201_Vz0	 BUFFER[9481]	//(internal1_m201_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m201_Vz0	 1680	//(internal1_m201_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m201_flRazg	 BUFFER[9486]	//(internal1_m201_flRazg) признак разгона/торможения
#define idinternal1_m201_flRazg	 1681	//(internal1_m201_flRazg) признак разгона/торможения
#define internal1_m201_DelSp	 BUFFER[9489]	//(internal1_m201_DelSp) DelSp - время переключения скоростей
#define idinternal1_m201_DelSp	 1682	//(internal1_m201_DelSp) DelSp - время переключения скоростей
#define internal1_m201_z0	 BUFFER[9494]	//(internal1_m201_z0) z0 - точка прекращения движения
#define idinternal1_m201_z0	 1683	//(internal1_m201_z0) z0 - точка прекращения движения
#define internal1_m201_txZS	 BUFFER[9499]	//(internal1_m201_txZS) txZS
#define idinternal1_m201_txZS	 1684	//(internal1_m201_txZS) txZS
#define internal1_m201_tx	 BUFFER[9504]	//(internal1_m201_tx) tx
#define idinternal1_m201_tx	 1685	//(internal1_m201_tx) tx
#define internal1_m201_txd	 BUFFER[9509]	//(internal1_m201_txd) txd
#define idinternal1_m201_txd	 1686	//(internal1_m201_txd) txd
#define internal1_m201_txMBl	 BUFFER[9514]	//(internal1_m201_txMBl) tx
#define idinternal1_m201_txMBl	 1687	//(internal1_m201_txMBl) tx
#define internal1_m201_txBl	 BUFFER[9519]	//(internal1_m201_txBl) tx
#define idinternal1_m201_txBl	 1688	//(internal1_m201_txBl) tx
#define internal1_m201_Speed0	 BUFFER[9524]	//(internal1_m201_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m201_Speed0	 1689	//(internal1_m201_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m201_xz0	 BUFFER[9529]	//(internal1_m201_xz0) xz0 - новое задание мм
#define idinternal1_m201_xz0	 1690	//(internal1_m201_xz0) xz0 - новое задание мм
#define internal1_m201_tz0	 BUFFER[9534]	//(internal1_m201_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m201_tz0	 1691	//(internal1_m201_tz0) tz0 - время защиты от нового задания сек
#define internal1_m201_Shift0	 BUFFER[9539]	//(internal1_m201_Shift0) Shift0 - признак самохода
#define idinternal1_m201_Shift0	 1692	//(internal1_m201_Shift0) Shift0 - признак самохода
#define internal1_m201_ShCntlSp0	 BUFFER[9541]	//(internal1_m201_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m201_ShCntlSp0	 1693	//(internal1_m201_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m201_ShiftControl	 BUFFER[9543]	//(internal1_m201_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m201_ShiftControl	 1694	//(internal1_m201_ShiftControl) ShiftControl - признак самохода
#define internal1_m716_q0	 BUFFER[9545]	//(internal1_m716_q0) q0 - внутренний параметр
#define idinternal1_m716_q0	 1695	//(internal1_m716_q0) q0 - внутренний параметр
#define internal1_m513_DvUp0	 BUFFER[9547]	//(internal1_m513_DvUp0) - есть команда на движение вперёд
#define idinternal1_m513_DvUp0	 1696	//(internal1_m513_DvUp0) - есть команда на движение вперёд
#define internal1_m513_DvDw0	 BUFFER[9548]	//(internal1_m513_DvDw0) - есть команда на движение назад
#define idinternal1_m513_DvDw0	 1697	//(internal1_m513_DvDw0) - есть команда на движение назад
#define internal1_m513_FDvUp0	 BUFFER[9549]	//(internal1_m513_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m513_FDvUp0	 1698	//(internal1_m513_FDvUp0) - есть команда на движение вперёд
#define internal1_m513_FDvDw0	 BUFFER[9550]	//(internal1_m513_FDvDw0) - есть команда на движение назад
#define idinternal1_m513_FDvDw0	 1699	//(internal1_m513_FDvDw0) - есть команда на движение назад
#define internal1_m513_BlDv0	 BUFFER[9551]	//(internal1_m513_BlDv0) - была блокировка
#define idinternal1_m513_BlDv0	 1700	//(internal1_m513_BlDv0) - была блокировка
#define internal1_m513_Pkv0	 BUFFER[9552]	//(internal1_m513_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m513_Pkv0	 1701	//(internal1_m513_Pkv0) Pkv - передний конечный выключатель
#define internal1_m513_Pkav0	 BUFFER[9553]	//(internal1_m513_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m513_Pkav0	 1702	//(internal1_m513_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m513_Zkv0	 BUFFER[9554]	//(internal1_m513_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m513_Zkv0	 1703	//(internal1_m513_Zkv0) Zkv - задний конечный выключатель
#define internal1_m513_Zkav0	 BUFFER[9555]	//(internal1_m513_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m513_Zkav0	 1704	//(internal1_m513_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m513_txNm	 BUFFER[9556]	//(internal1_m513_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m513_txNm	 1705	//(internal1_m513_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m513_txSm	 BUFFER[9561]	//(internal1_m513_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m513_txSm	 1706	//(internal1_m513_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m513_txHr	 BUFFER[9566]	//(internal1_m513_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m513_txHr	 1707	//(internal1_m513_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m513_txLd	 BUFFER[9571]	//(internal1_m513_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m513_txLd	 1708	//(internal1_m513_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m513_fef	 BUFFER[9576]	//(internal1_m513_fef) fef
#define idinternal1_m513_fef	 1709	//(internal1_m513_fef) fef
#define internal1_m507_DvUp0	 BUFFER[9577]	//(internal1_m507_DvUp0) - есть команда на движение вперёд
#define idinternal1_m507_DvUp0	 1710	//(internal1_m507_DvUp0) - есть команда на движение вперёд
#define internal1_m507_DvDw0	 BUFFER[9578]	//(internal1_m507_DvDw0) - есть команда на движение назад
#define idinternal1_m507_DvDw0	 1711	//(internal1_m507_DvDw0) - есть команда на движение назад
#define internal1_m507_FDvUp0	 BUFFER[9579]	//(internal1_m507_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m507_FDvUp0	 1712	//(internal1_m507_FDvUp0) - есть команда на движение вперёд
#define internal1_m507_FDvDw0	 BUFFER[9580]	//(internal1_m507_FDvDw0) - есть команда на движение назад
#define idinternal1_m507_FDvDw0	 1713	//(internal1_m507_FDvDw0) - есть команда на движение назад
#define internal1_m507_BlDv0	 BUFFER[9581]	//(internal1_m507_BlDv0) - была блокировка
#define idinternal1_m507_BlDv0	 1714	//(internal1_m507_BlDv0) - была блокировка
#define internal1_m507_Pkv0	 BUFFER[9582]	//(internal1_m507_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m507_Pkv0	 1715	//(internal1_m507_Pkv0) Pkv - передний конечный выключатель
#define internal1_m507_Pkav0	 BUFFER[9583]	//(internal1_m507_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m507_Pkav0	 1716	//(internal1_m507_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m507_Zkv0	 BUFFER[9584]	//(internal1_m507_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m507_Zkv0	 1717	//(internal1_m507_Zkv0) Zkv - задний конечный выключатель
#define internal1_m507_Zkav0	 BUFFER[9585]	//(internal1_m507_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m507_Zkav0	 1718	//(internal1_m507_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m507_txNm	 BUFFER[9586]	//(internal1_m507_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m507_txNm	 1719	//(internal1_m507_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m507_txSm	 BUFFER[9591]	//(internal1_m507_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m507_txSm	 1720	//(internal1_m507_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m507_txHr	 BUFFER[9596]	//(internal1_m507_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m507_txHr	 1721	//(internal1_m507_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m507_txLd	 BUFFER[9601]	//(internal1_m507_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m507_txLd	 1722	//(internal1_m507_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m507_fef	 BUFFER[9606]	//(internal1_m507_fef) fef
#define idinternal1_m507_fef	 1723	//(internal1_m507_fef) fef
#define internal1_m905_X0	 BUFFER[9607]	//(internal1_m905_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m905_X0	 1724	//(internal1_m905_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m905_t0	 BUFFER[9612]	//(internal1_m905_t0) время нахождения в зоне возврата
#define idinternal1_m905_t0	 1725	//(internal1_m905_t0) время нахождения в зоне возврата
#define internal1_m905_BLDv0	 BUFFER[9617]	//(internal1_m905_BLDv0) BlDv - Блокировка движения
#define idinternal1_m905_BLDv0	 1726	//(internal1_m905_BLDv0) BlDv - Блокировка движения
#define internal1_m923_xptr	 BUFFER[9618]	//(internal1_m923_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m923_xptr	 1727	//(internal1_m923_xptr) указатель текущей позиции в массиве координат
#define internal1_m923_x0	 BUFFER[9621]	//(internal1_m923_x0) x0 - массив мгновенных значений координат
#define idinternal1_m923_x0	 1728	//(internal1_m923_x0) x0 - массив мгновенных значений координат
#define internal1_m923_tim0	 BUFFER[10021]	//(internal1_m923_tim0) tim0 - массив значений времени цикла
#define idinternal1_m923_tim0	 1729	//(internal1_m923_tim0) tim0 - массив значений времени цикла
#define internal1_m923_sumtim	 BUFFER[10421]	//(internal1_m923_sumtim) sumtim - время в пути
#define idinternal1_m923_sumtim	 1730	//(internal1_m923_sumtim) sumtim - время в пути
#define internal1_m923_StSpeed	 BUFFER[10426]	//(internal1_m923_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m923_StSpeed	 1731	//(internal1_m923_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m923_Vz0	 BUFFER[10431]	//(internal1_m923_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m923_Vz0	 1732	//(internal1_m923_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m923_flRazg	 BUFFER[10436]	//(internal1_m923_flRazg) признак разгона/торможения
#define idinternal1_m923_flRazg	 1733	//(internal1_m923_flRazg) признак разгона/торможения
#define internal1_m923_DelSp	 BUFFER[10439]	//(internal1_m923_DelSp) DelSp - время переключения скоростей
#define idinternal1_m923_DelSp	 1734	//(internal1_m923_DelSp) DelSp - время переключения скоростей
#define internal1_m923_z0	 BUFFER[10444]	//(internal1_m923_z0) z0 - точка прекращения движения
#define idinternal1_m923_z0	 1735	//(internal1_m923_z0) z0 - точка прекращения движения
#define internal1_m923_txZS	 BUFFER[10449]	//(internal1_m923_txZS) txZS
#define idinternal1_m923_txZS	 1736	//(internal1_m923_txZS) txZS
#define internal1_m923_tx	 BUFFER[10454]	//(internal1_m923_tx) tx
#define idinternal1_m923_tx	 1737	//(internal1_m923_tx) tx
#define internal1_m923_txd	 BUFFER[10459]	//(internal1_m923_txd) txd
#define idinternal1_m923_txd	 1738	//(internal1_m923_txd) txd
#define internal1_m923_txMBl	 BUFFER[10464]	//(internal1_m923_txMBl) tx
#define idinternal1_m923_txMBl	 1739	//(internal1_m923_txMBl) tx
#define internal1_m923_txBl	 BUFFER[10469]	//(internal1_m923_txBl) tx
#define idinternal1_m923_txBl	 1740	//(internal1_m923_txBl) tx
#define internal1_m923_Speed0	 BUFFER[10474]	//(internal1_m923_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m923_Speed0	 1741	//(internal1_m923_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m923_xz0	 BUFFER[10479]	//(internal1_m923_xz0) xz0 - новое задание мм
#define idinternal1_m923_xz0	 1742	//(internal1_m923_xz0) xz0 - новое задание мм
#define internal1_m923_tz0	 BUFFER[10484]	//(internal1_m923_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m923_tz0	 1743	//(internal1_m923_tz0) tz0 - время защиты от нового задания сек
#define internal1_m923_Shift0	 BUFFER[10489]	//(internal1_m923_Shift0) Shift0 - признак самохода
#define idinternal1_m923_Shift0	 1744	//(internal1_m923_Shift0) Shift0 - признак самохода
#define internal1_m923_ShCntlSp0	 BUFFER[10491]	//(internal1_m923_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m923_ShCntlSp0	 1745	//(internal1_m923_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m923_ShiftControl	 BUFFER[10493]	//(internal1_m923_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m923_ShiftControl	 1746	//(internal1_m923_ShiftControl) ShiftControl - признак самохода
#define internal1_m1800_X0	 BUFFER[10495]	//(internal1_m1800_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1800_X0	 1747	//(internal1_m1800_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1800_t0	 BUFFER[10500]	//(internal1_m1800_t0) время нахождения в зоне возврата
#define idinternal1_m1800_t0	 1748	//(internal1_m1800_t0) время нахождения в зоне возврата
#define internal1_m1800_BLDv0	 BUFFER[10505]	//(internal1_m1800_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1800_BLDv0	 1749	//(internal1_m1800_BLDv0) BlDv - Блокировка движения
#define internal1_m1270_X0	 BUFFER[10506]	//(internal1_m1270_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1270_X0	 1750	//(internal1_m1270_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1270_t0	 BUFFER[10511]	//(internal1_m1270_t0) время нахождения в зоне возврата
#define idinternal1_m1270_t0	 1751	//(internal1_m1270_t0) время нахождения в зоне возврата
#define internal1_m1270_BLDv0	 BUFFER[10516]	//(internal1_m1270_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1270_BLDv0	 1752	//(internal1_m1270_BLDv0) BlDv - Блокировка движения
#define internal1_m688_q0	 BUFFER[10517]	//(internal1_m688_q0) q0 - внутренний параметр
#define idinternal1_m688_q0	 1753	//(internal1_m688_q0) q0 - внутренний параметр
#define internal1_m1366_X0	 BUFFER[10519]	//(internal1_m1366_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1366_X0	 1754	//(internal1_m1366_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1366_t0	 BUFFER[10524]	//(internal1_m1366_t0) время нахождения в зоне возврата
#define idinternal1_m1366_t0	 1755	//(internal1_m1366_t0) время нахождения в зоне возврата
#define internal1_m1366_BLDv0	 BUFFER[10529]	//(internal1_m1366_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1366_BLDv0	 1756	//(internal1_m1366_BLDv0) BlDv - Блокировка движения
#define internal1_m1396_tx	 BUFFER[10530]	//(internal1_m1396_tx) tx - время накопленное сек
#define idinternal1_m1396_tx	 1757	//(internal1_m1396_tx) tx - время накопленное сек
#define internal1_m1396_y0	 BUFFER[10535]	//(internal1_m1396_y0) y0
#define idinternal1_m1396_y0	 1758	//(internal1_m1396_y0) y0
#define internal1_m1395_tx	 BUFFER[10536]	//(internal1_m1395_tx) tx - время накопленное сек
#define idinternal1_m1395_tx	 1759	//(internal1_m1395_tx) tx - время накопленное сек
#define internal1_m1395_y0	 BUFFER[10541]	//(internal1_m1395_y0) y0
#define idinternal1_m1395_y0	 1760	//(internal1_m1395_y0) y0
#define internal1_m1401_xptr	 BUFFER[10542]	//(internal1_m1401_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1401_xptr	 1761	//(internal1_m1401_xptr) указатель текущей позиции в массиве координат
#define internal1_m1401_x0	 BUFFER[10545]	//(internal1_m1401_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1401_x0	 1762	//(internal1_m1401_x0) x0 - массив мгновенных значений координат
#define internal1_m1401_tim0	 BUFFER[10945]	//(internal1_m1401_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1401_tim0	 1763	//(internal1_m1401_tim0) tim0 - массив значений времени цикла
#define internal1_m1401_sumtim	 BUFFER[11345]	//(internal1_m1401_sumtim) sumtim - время в пути
#define idinternal1_m1401_sumtim	 1764	//(internal1_m1401_sumtim) sumtim - время в пути
#define internal1_m1401_StSpeed	 BUFFER[11350]	//(internal1_m1401_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1401_StSpeed	 1765	//(internal1_m1401_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1401_Vz0	 BUFFER[11355]	//(internal1_m1401_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1401_Vz0	 1766	//(internal1_m1401_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1401_flRazg	 BUFFER[11360]	//(internal1_m1401_flRazg) признак разгона/торможения
#define idinternal1_m1401_flRazg	 1767	//(internal1_m1401_flRazg) признак разгона/торможения
#define internal1_m1401_DelSp	 BUFFER[11363]	//(internal1_m1401_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1401_DelSp	 1768	//(internal1_m1401_DelSp) DelSp - время переключения скоростей
#define internal1_m1401_z0	 BUFFER[11368]	//(internal1_m1401_z0) z0 - точка прекращения движения
#define idinternal1_m1401_z0	 1769	//(internal1_m1401_z0) z0 - точка прекращения движения
#define internal1_m1401_txZS	 BUFFER[11373]	//(internal1_m1401_txZS) txZS
#define idinternal1_m1401_txZS	 1770	//(internal1_m1401_txZS) txZS
#define internal1_m1401_tx	 BUFFER[11378]	//(internal1_m1401_tx) tx
#define idinternal1_m1401_tx	 1771	//(internal1_m1401_tx) tx
#define internal1_m1401_txd	 BUFFER[11383]	//(internal1_m1401_txd) txd
#define idinternal1_m1401_txd	 1772	//(internal1_m1401_txd) txd
#define internal1_m1401_txMBl	 BUFFER[11388]	//(internal1_m1401_txMBl) tx
#define idinternal1_m1401_txMBl	 1773	//(internal1_m1401_txMBl) tx
#define internal1_m1401_txBl	 BUFFER[11393]	//(internal1_m1401_txBl) tx
#define idinternal1_m1401_txBl	 1774	//(internal1_m1401_txBl) tx
#define internal1_m1401_Speed0	 BUFFER[11398]	//(internal1_m1401_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1401_Speed0	 1775	//(internal1_m1401_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1401_xz0	 BUFFER[11403]	//(internal1_m1401_xz0) xz0 - новое задание мм
#define idinternal1_m1401_xz0	 1776	//(internal1_m1401_xz0) xz0 - новое задание мм
#define internal1_m1401_tz0	 BUFFER[11408]	//(internal1_m1401_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1401_tz0	 1777	//(internal1_m1401_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1401_Shift0	 BUFFER[11413]	//(internal1_m1401_Shift0) Shift0 - признак самохода
#define idinternal1_m1401_Shift0	 1778	//(internal1_m1401_Shift0) Shift0 - признак самохода
#define internal1_m1401_ShCntlSp0	 BUFFER[11415]	//(internal1_m1401_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1401_ShCntlSp0	 1779	//(internal1_m1401_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1401_ShiftControl	 BUFFER[11417]	//(internal1_m1401_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1401_ShiftControl	 1780	//(internal1_m1401_ShiftControl) ShiftControl - признак самохода
#define internal1_m708_q0	 BUFFER[11419]	//(internal1_m708_q0) q0 - внутренний параметр
#define idinternal1_m708_q0	 1781	//(internal1_m708_q0) q0 - внутренний параметр
#define internal1_m1814_tx	 BUFFER[11421]	//(internal1_m1814_tx) tx - время накопленное сек
#define idinternal1_m1814_tx	 1782	//(internal1_m1814_tx) tx - время накопленное сек
#define internal1_m1814_y0	 BUFFER[11426]	//(internal1_m1814_y0) y0
#define idinternal1_m1814_y0	 1783	//(internal1_m1814_y0) y0
#define internal1_m1818_tx	 BUFFER[11427]	//(internal1_m1818_tx) tx - время накопленное сек
#define idinternal1_m1818_tx	 1784	//(internal1_m1818_tx) tx - время накопленное сек
#define internal1_m1818_y0	 BUFFER[11432]	//(internal1_m1818_y0) y0
#define idinternal1_m1818_y0	 1785	//(internal1_m1818_y0) y0
#define internal1_m1803_DvUp0	 BUFFER[11433]	//(internal1_m1803_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1803_DvUp0	 1786	//(internal1_m1803_DvUp0) - есть команда на движение вперёд
#define internal1_m1803_DvDw0	 BUFFER[11434]	//(internal1_m1803_DvDw0) - есть команда на движение назад
#define idinternal1_m1803_DvDw0	 1787	//(internal1_m1803_DvDw0) - есть команда на движение назад
#define internal1_m1803_FDvUp0	 BUFFER[11435]	//(internal1_m1803_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1803_FDvUp0	 1788	//(internal1_m1803_FDvUp0) - есть команда на движение вперёд
#define internal1_m1803_FDvDw0	 BUFFER[11436]	//(internal1_m1803_FDvDw0) - есть команда на движение назад
#define idinternal1_m1803_FDvDw0	 1789	//(internal1_m1803_FDvDw0) - есть команда на движение назад
#define internal1_m1803_BlDv0	 BUFFER[11437]	//(internal1_m1803_BlDv0) - была блокировка
#define idinternal1_m1803_BlDv0	 1790	//(internal1_m1803_BlDv0) - была блокировка
#define internal1_m1803_Pkv0	 BUFFER[11438]	//(internal1_m1803_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1803_Pkv0	 1791	//(internal1_m1803_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1803_Pkav0	 BUFFER[11439]	//(internal1_m1803_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1803_Pkav0	 1792	//(internal1_m1803_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1803_Zkv0	 BUFFER[11440]	//(internal1_m1803_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1803_Zkv0	 1793	//(internal1_m1803_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1803_Zkav0	 BUFFER[11441]	//(internal1_m1803_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1803_Zkav0	 1794	//(internal1_m1803_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1803_txNm	 BUFFER[11442]	//(internal1_m1803_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1803_txNm	 1795	//(internal1_m1803_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1803_txSm	 BUFFER[11447]	//(internal1_m1803_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1803_txSm	 1796	//(internal1_m1803_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1803_txHr	 BUFFER[11452]	//(internal1_m1803_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1803_txHr	 1797	//(internal1_m1803_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1803_txLd	 BUFFER[11457]	//(internal1_m1803_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1803_txLd	 1798	//(internal1_m1803_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1803_fef	 BUFFER[11462]	//(internal1_m1803_fef) fef
#define idinternal1_m1803_fef	 1799	//(internal1_m1803_fef) fef
#define internal1_m1822_xptr	 BUFFER[11463]	//(internal1_m1822_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1822_xptr	 1800	//(internal1_m1822_xptr) указатель текущей позиции в массиве координат
#define internal1_m1822_x0	 BUFFER[11466]	//(internal1_m1822_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1822_x0	 1801	//(internal1_m1822_x0) x0 - массив мгновенных значений координат
#define internal1_m1822_tim0	 BUFFER[11566]	//(internal1_m1822_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1822_tim0	 1802	//(internal1_m1822_tim0) tim0 - массив значений времени цикла
#define internal1_m1822_sumtim	 BUFFER[11666]	//(internal1_m1822_sumtim) sumtim - время в пути
#define idinternal1_m1822_sumtim	 1803	//(internal1_m1822_sumtim) sumtim - время в пути
#define internal1_m1822_StSpeed	 BUFFER[11671]	//(internal1_m1822_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1822_StSpeed	 1804	//(internal1_m1822_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1822_Vz0	 BUFFER[11676]	//(internal1_m1822_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1822_Vz0	 1805	//(internal1_m1822_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1822_flRazg	 BUFFER[11681]	//(internal1_m1822_flRazg) признак разгона/торможения
#define idinternal1_m1822_flRazg	 1806	//(internal1_m1822_flRazg) признак разгона/торможения
#define internal1_m1822_DelSp	 BUFFER[11684]	//(internal1_m1822_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1822_DelSp	 1807	//(internal1_m1822_DelSp) DelSp - время переключения скоростей
#define internal1_m1822_z0	 BUFFER[11689]	//(internal1_m1822_z0) z0 - точка прекращения движения
#define idinternal1_m1822_z0	 1808	//(internal1_m1822_z0) z0 - точка прекращения движения
#define internal1_m1822_txZS	 BUFFER[11694]	//(internal1_m1822_txZS) txZS
#define idinternal1_m1822_txZS	 1809	//(internal1_m1822_txZS) txZS
#define internal1_m1822_tx	 BUFFER[11699]	//(internal1_m1822_tx) tx
#define idinternal1_m1822_tx	 1810	//(internal1_m1822_tx) tx
#define internal1_m1822_txd	 BUFFER[11704]	//(internal1_m1822_txd) txd
#define idinternal1_m1822_txd	 1811	//(internal1_m1822_txd) txd
#define internal1_m1822_txMBl	 BUFFER[11709]	//(internal1_m1822_txMBl) tx
#define idinternal1_m1822_txMBl	 1812	//(internal1_m1822_txMBl) tx
#define internal1_m1822_txBl	 BUFFER[11714]	//(internal1_m1822_txBl) tx
#define idinternal1_m1822_txBl	 1813	//(internal1_m1822_txBl) tx
#define internal1_m1822_Speed0	 BUFFER[11719]	//(internal1_m1822_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1822_Speed0	 1814	//(internal1_m1822_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1822_xz0	 BUFFER[11724]	//(internal1_m1822_xz0) xz0 - новое задание мм
#define idinternal1_m1822_xz0	 1815	//(internal1_m1822_xz0) xz0 - новое задание мм
#define internal1_m1822_tz0	 BUFFER[11729]	//(internal1_m1822_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1822_tz0	 1816	//(internal1_m1822_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1822_Shift0	 BUFFER[11734]	//(internal1_m1822_Shift0) Shift0 - признак самохода
#define idinternal1_m1822_Shift0	 1817	//(internal1_m1822_Shift0) Shift0 - признак самохода
#define internal1_m1822_ShCntlSp0	 BUFFER[11736]	//(internal1_m1822_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1822_ShCntlSp0	 1818	//(internal1_m1822_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1822_ShiftControl	 BUFFER[11738]	//(internal1_m1822_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1822_ShiftControl	 1819	//(internal1_m1822_ShiftControl) ShiftControl - признак самохода
#define internal1_m1286_tx	 BUFFER[11740]	//(internal1_m1286_tx) tx - время накопленное сек
#define idinternal1_m1286_tx	 1820	//(internal1_m1286_tx) tx - время накопленное сек
#define internal1_m1286_y0	 BUFFER[11745]	//(internal1_m1286_y0) y0
#define idinternal1_m1286_y0	 1821	//(internal1_m1286_y0) y0
#define internal1_m1290_tx	 BUFFER[11746]	//(internal1_m1290_tx) tx - время накопленное сек
#define idinternal1_m1290_tx	 1822	//(internal1_m1290_tx) tx - время накопленное сек
#define internal1_m1290_y0	 BUFFER[11751]	//(internal1_m1290_y0) y0
#define idinternal1_m1290_y0	 1823	//(internal1_m1290_y0) y0
#define internal1_m698_q0	 BUFFER[11752]	//(internal1_m698_q0) q0 - внутренний параметр
#define idinternal1_m698_q0	 1824	//(internal1_m698_q0) q0 - внутренний параметр
#define internal1_m663_q0	 BUFFER[11754]	//(internal1_m663_q0) q0 - внутренний параметр
#define idinternal1_m663_q0	 1825	//(internal1_m663_q0) q0 - внутренний параметр
#define internal1_m1276_DvUp0	 BUFFER[11756]	//(internal1_m1276_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1276_DvUp0	 1826	//(internal1_m1276_DvUp0) - есть команда на движение вперёд
#define internal1_m1276_DvDw0	 BUFFER[11757]	//(internal1_m1276_DvDw0) - есть команда на движение назад
#define idinternal1_m1276_DvDw0	 1827	//(internal1_m1276_DvDw0) - есть команда на движение назад
#define internal1_m1276_FDvUp0	 BUFFER[11758]	//(internal1_m1276_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1276_FDvUp0	 1828	//(internal1_m1276_FDvUp0) - есть команда на движение вперёд
#define internal1_m1276_FDvDw0	 BUFFER[11759]	//(internal1_m1276_FDvDw0) - есть команда на движение назад
#define idinternal1_m1276_FDvDw0	 1829	//(internal1_m1276_FDvDw0) - есть команда на движение назад
#define internal1_m1276_BlDv0	 BUFFER[11760]	//(internal1_m1276_BlDv0) - была блокировка
#define idinternal1_m1276_BlDv0	 1830	//(internal1_m1276_BlDv0) - была блокировка
#define internal1_m1276_Pkv0	 BUFFER[11761]	//(internal1_m1276_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1276_Pkv0	 1831	//(internal1_m1276_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1276_Pkav0	 BUFFER[11762]	//(internal1_m1276_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1276_Pkav0	 1832	//(internal1_m1276_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1276_Zkv0	 BUFFER[11763]	//(internal1_m1276_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1276_Zkv0	 1833	//(internal1_m1276_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1276_Zkav0	 BUFFER[11764]	//(internal1_m1276_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1276_Zkav0	 1834	//(internal1_m1276_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1276_txNm	 BUFFER[11765]	//(internal1_m1276_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1276_txNm	 1835	//(internal1_m1276_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1276_txSm	 BUFFER[11770]	//(internal1_m1276_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1276_txSm	 1836	//(internal1_m1276_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1276_txHr	 BUFFER[11775]	//(internal1_m1276_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1276_txHr	 1837	//(internal1_m1276_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1276_txLd	 BUFFER[11780]	//(internal1_m1276_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1276_txLd	 1838	//(internal1_m1276_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1276_fef	 BUFFER[11785]	//(internal1_m1276_fef) fef
#define idinternal1_m1276_fef	 1839	//(internal1_m1276_fef) fef
#define internal1_m1296_xptr	 BUFFER[11786]	//(internal1_m1296_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1296_xptr	 1840	//(internal1_m1296_xptr) указатель текущей позиции в массиве координат
#define internal1_m1296_x0	 BUFFER[11789]	//(internal1_m1296_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1296_x0	 1841	//(internal1_m1296_x0) x0 - массив мгновенных значений координат
#define internal1_m1296_tim0	 BUFFER[11889]	//(internal1_m1296_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1296_tim0	 1842	//(internal1_m1296_tim0) tim0 - массив значений времени цикла
#define internal1_m1296_sumtim	 BUFFER[11989]	//(internal1_m1296_sumtim) sumtim - время в пути
#define idinternal1_m1296_sumtim	 1843	//(internal1_m1296_sumtim) sumtim - время в пути
#define internal1_m1296_StSpeed	 BUFFER[11994]	//(internal1_m1296_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1296_StSpeed	 1844	//(internal1_m1296_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1296_Vz0	 BUFFER[11999]	//(internal1_m1296_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1296_Vz0	 1845	//(internal1_m1296_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1296_flRazg	 BUFFER[12004]	//(internal1_m1296_flRazg) признак разгона/торможения
#define idinternal1_m1296_flRazg	 1846	//(internal1_m1296_flRazg) признак разгона/торможения
#define internal1_m1296_DelSp	 BUFFER[12007]	//(internal1_m1296_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1296_DelSp	 1847	//(internal1_m1296_DelSp) DelSp - время переключения скоростей
#define internal1_m1296_z0	 BUFFER[12012]	//(internal1_m1296_z0) z0 - точка прекращения движения
#define idinternal1_m1296_z0	 1848	//(internal1_m1296_z0) z0 - точка прекращения движения
#define internal1_m1296_txZS	 BUFFER[12017]	//(internal1_m1296_txZS) txZS
#define idinternal1_m1296_txZS	 1849	//(internal1_m1296_txZS) txZS
#define internal1_m1296_tx	 BUFFER[12022]	//(internal1_m1296_tx) tx
#define idinternal1_m1296_tx	 1850	//(internal1_m1296_tx) tx
#define internal1_m1296_txd	 BUFFER[12027]	//(internal1_m1296_txd) txd
#define idinternal1_m1296_txd	 1851	//(internal1_m1296_txd) txd
#define internal1_m1296_txMBl	 BUFFER[12032]	//(internal1_m1296_txMBl) tx
#define idinternal1_m1296_txMBl	 1852	//(internal1_m1296_txMBl) tx
#define internal1_m1296_txBl	 BUFFER[12037]	//(internal1_m1296_txBl) tx
#define idinternal1_m1296_txBl	 1853	//(internal1_m1296_txBl) tx
#define internal1_m1296_Speed0	 BUFFER[12042]	//(internal1_m1296_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1296_Speed0	 1854	//(internal1_m1296_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1296_xz0	 BUFFER[12047]	//(internal1_m1296_xz0) xz0 - новое задание мм
#define idinternal1_m1296_xz0	 1855	//(internal1_m1296_xz0) xz0 - новое задание мм
#define internal1_m1296_tz0	 BUFFER[12052]	//(internal1_m1296_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1296_tz0	 1856	//(internal1_m1296_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1296_Shift0	 BUFFER[12057]	//(internal1_m1296_Shift0) Shift0 - признак самохода
#define idinternal1_m1296_Shift0	 1857	//(internal1_m1296_Shift0) Shift0 - признак самохода
#define internal1_m1296_ShCntlSp0	 BUFFER[12059]	//(internal1_m1296_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1296_ShCntlSp0	 1858	//(internal1_m1296_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1296_ShiftControl	 BUFFER[12061]	//(internal1_m1296_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1296_ShiftControl	 1859	//(internal1_m1296_ShiftControl) ShiftControl - признак самохода
#define internal1_m826_x0	 BUFFER[12063]	//(internal1_m826_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m826_x0	 1860	//(internal1_m826_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m794_x0	 BUFFER[12065]	//(internal1_m794_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m794_x0	 1861	//(internal1_m794_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m737_x0	 BUFFER[12067]	//(internal1_m737_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m737_x0	 1862	//(internal1_m737_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m851_q0	 BUFFER[12069]	//(internal1_m851_q0) q0 - внутренний параметр
#define idinternal1_m851_q0	 1863	//(internal1_m851_q0) q0 - внутренний параметр
#define internal1_m846_q0	 BUFFER[12071]	//(internal1_m846_q0) q0 - внутренний параметр
#define idinternal1_m846_q0	 1864	//(internal1_m846_q0) q0 - внутренний параметр
#define internal1_m814_q0	 BUFFER[12073]	//(internal1_m814_q0) q0 - внутренний параметр
#define idinternal1_m814_q0	 1865	//(internal1_m814_q0) q0 - внутренний параметр
#define internal1_m818_q0	 BUFFER[12075]	//(internal1_m818_q0) q0 - внутренний параметр
#define idinternal1_m818_q0	 1866	//(internal1_m818_q0) q0 - внутренний параметр
#define internal1_m827_q0	 BUFFER[12077]	//(internal1_m827_q0) q0 - внутренний параметр
#define idinternal1_m827_q0	 1867	//(internal1_m827_q0) q0 - внутренний параметр
#define internal1_m839_q0	 BUFFER[12079]	//(internal1_m839_q0) q0 - внутренний параметр
#define idinternal1_m839_q0	 1868	//(internal1_m839_q0) q0 - внутренний параметр
#define internal1_m816_q0	 BUFFER[12081]	//(internal1_m816_q0) q0 - внутренний параметр
#define idinternal1_m816_q0	 1869	//(internal1_m816_q0) q0 - внутренний параметр
#define internal1_m1338_DvUp0	 BUFFER[12083]	//(internal1_m1338_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1338_DvUp0	 1870	//(internal1_m1338_DvUp0) - есть команда на движение вперёд
#define internal1_m1338_DvDw0	 BUFFER[12084]	//(internal1_m1338_DvDw0) - есть команда на движение назад
#define idinternal1_m1338_DvDw0	 1871	//(internal1_m1338_DvDw0) - есть команда на движение назад
#define internal1_m1338_FDvUp0	 BUFFER[12085]	//(internal1_m1338_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1338_FDvUp0	 1872	//(internal1_m1338_FDvUp0) - есть команда на движение вперёд
#define internal1_m1338_FDvDw0	 BUFFER[12086]	//(internal1_m1338_FDvDw0) - есть команда на движение назад
#define idinternal1_m1338_FDvDw0	 1873	//(internal1_m1338_FDvDw0) - есть команда на движение назад
#define internal1_m1338_BlDv0	 BUFFER[12087]	//(internal1_m1338_BlDv0) - была блокировка
#define idinternal1_m1338_BlDv0	 1874	//(internal1_m1338_BlDv0) - была блокировка
#define internal1_m1338_Pkv0	 BUFFER[12088]	//(internal1_m1338_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1338_Pkv0	 1875	//(internal1_m1338_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1338_Pkav0	 BUFFER[12089]	//(internal1_m1338_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1338_Pkav0	 1876	//(internal1_m1338_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1338_Zkv0	 BUFFER[12090]	//(internal1_m1338_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1338_Zkv0	 1877	//(internal1_m1338_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1338_Zkav0	 BUFFER[12091]	//(internal1_m1338_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1338_Zkav0	 1878	//(internal1_m1338_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1338_txNm	 BUFFER[12092]	//(internal1_m1338_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1338_txNm	 1879	//(internal1_m1338_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1338_txSm	 BUFFER[12097]	//(internal1_m1338_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1338_txSm	 1880	//(internal1_m1338_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1338_txHr	 BUFFER[12102]	//(internal1_m1338_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1338_txHr	 1881	//(internal1_m1338_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1338_txLd	 BUFFER[12107]	//(internal1_m1338_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1338_txLd	 1882	//(internal1_m1338_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1338_fef	 BUFFER[12112]	//(internal1_m1338_fef) fef
#define idinternal1_m1338_fef	 1883	//(internal1_m1338_fef) fef
#define internal1_m1329_DvUp0	 BUFFER[12113]	//(internal1_m1329_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1329_DvUp0	 1884	//(internal1_m1329_DvUp0) - есть команда на движение вперёд
#define internal1_m1329_DvDw0	 BUFFER[12114]	//(internal1_m1329_DvDw0) - есть команда на движение назад
#define idinternal1_m1329_DvDw0	 1885	//(internal1_m1329_DvDw0) - есть команда на движение назад
#define internal1_m1329_FDvUp0	 BUFFER[12115]	//(internal1_m1329_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1329_FDvUp0	 1886	//(internal1_m1329_FDvUp0) - есть команда на движение вперёд
#define internal1_m1329_FDvDw0	 BUFFER[12116]	//(internal1_m1329_FDvDw0) - есть команда на движение назад
#define idinternal1_m1329_FDvDw0	 1887	//(internal1_m1329_FDvDw0) - есть команда на движение назад
#define internal1_m1329_BlDv0	 BUFFER[12117]	//(internal1_m1329_BlDv0) - была блокировка
#define idinternal1_m1329_BlDv0	 1888	//(internal1_m1329_BlDv0) - была блокировка
#define internal1_m1329_Pkv0	 BUFFER[12118]	//(internal1_m1329_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1329_Pkv0	 1889	//(internal1_m1329_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1329_Pkav0	 BUFFER[12119]	//(internal1_m1329_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1329_Pkav0	 1890	//(internal1_m1329_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1329_Zkv0	 BUFFER[12120]	//(internal1_m1329_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1329_Zkv0	 1891	//(internal1_m1329_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1329_Zkav0	 BUFFER[12121]	//(internal1_m1329_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1329_Zkav0	 1892	//(internal1_m1329_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1329_txNm	 BUFFER[12122]	//(internal1_m1329_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1329_txNm	 1893	//(internal1_m1329_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1329_txSm	 BUFFER[12127]	//(internal1_m1329_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1329_txSm	 1894	//(internal1_m1329_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1329_txHr	 BUFFER[12132]	//(internal1_m1329_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1329_txHr	 1895	//(internal1_m1329_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1329_txLd	 BUFFER[12137]	//(internal1_m1329_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1329_txLd	 1896	//(internal1_m1329_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1329_fef	 BUFFER[12142]	//(internal1_m1329_fef) fef
#define idinternal1_m1329_fef	 1897	//(internal1_m1329_fef) fef
#define internal1_m875_DvUp0	 BUFFER[12143]	//(internal1_m875_DvUp0) - есть команда на движение вперёд
#define idinternal1_m875_DvUp0	 1898	//(internal1_m875_DvUp0) - есть команда на движение вперёд
#define internal1_m875_DvDw0	 BUFFER[12144]	//(internal1_m875_DvDw0) - есть команда на движение назад
#define idinternal1_m875_DvDw0	 1899	//(internal1_m875_DvDw0) - есть команда на движение назад
#define internal1_m875_FDvUp0	 BUFFER[12145]	//(internal1_m875_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m875_FDvUp0	 1900	//(internal1_m875_FDvUp0) - есть команда на движение вперёд
#define internal1_m875_FDvDw0	 BUFFER[12146]	//(internal1_m875_FDvDw0) - есть команда на движение назад
#define idinternal1_m875_FDvDw0	 1901	//(internal1_m875_FDvDw0) - есть команда на движение назад
#define internal1_m875_BlDv0	 BUFFER[12147]	//(internal1_m875_BlDv0) - была блокировка
#define idinternal1_m875_BlDv0	 1902	//(internal1_m875_BlDv0) - была блокировка
#define internal1_m875_Pkv0	 BUFFER[12148]	//(internal1_m875_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m875_Pkv0	 1903	//(internal1_m875_Pkv0) Pkv - передний конечный выключатель
#define internal1_m875_Pkav0	 BUFFER[12149]	//(internal1_m875_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m875_Pkav0	 1904	//(internal1_m875_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m875_Zkv0	 BUFFER[12150]	//(internal1_m875_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m875_Zkv0	 1905	//(internal1_m875_Zkv0) Zkv - задний конечный выключатель
#define internal1_m875_Zkav0	 BUFFER[12151]	//(internal1_m875_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m875_Zkav0	 1906	//(internal1_m875_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m875_txNm	 BUFFER[12152]	//(internal1_m875_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m875_txNm	 1907	//(internal1_m875_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m875_txSm	 BUFFER[12157]	//(internal1_m875_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m875_txSm	 1908	//(internal1_m875_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m875_txHr	 BUFFER[12162]	//(internal1_m875_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m875_txHr	 1909	//(internal1_m875_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m875_txLd	 BUFFER[12167]	//(internal1_m875_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m875_txLd	 1910	//(internal1_m875_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m875_fef	 BUFFER[12172]	//(internal1_m875_fef) fef
#define idinternal1_m875_fef	 1911	//(internal1_m875_fef) fef
#define internal1_m871_DvUp0	 BUFFER[12173]	//(internal1_m871_DvUp0) - есть команда на движение вперёд
#define idinternal1_m871_DvUp0	 1912	//(internal1_m871_DvUp0) - есть команда на движение вперёд
#define internal1_m871_DvDw0	 BUFFER[12174]	//(internal1_m871_DvDw0) - есть команда на движение назад
#define idinternal1_m871_DvDw0	 1913	//(internal1_m871_DvDw0) - есть команда на движение назад
#define internal1_m871_FDvUp0	 BUFFER[12175]	//(internal1_m871_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m871_FDvUp0	 1914	//(internal1_m871_FDvUp0) - есть команда на движение вперёд
#define internal1_m871_FDvDw0	 BUFFER[12176]	//(internal1_m871_FDvDw0) - есть команда на движение назад
#define idinternal1_m871_FDvDw0	 1915	//(internal1_m871_FDvDw0) - есть команда на движение назад
#define internal1_m871_BlDv0	 BUFFER[12177]	//(internal1_m871_BlDv0) - была блокировка
#define idinternal1_m871_BlDv0	 1916	//(internal1_m871_BlDv0) - была блокировка
#define internal1_m871_Pkv0	 BUFFER[12178]	//(internal1_m871_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m871_Pkv0	 1917	//(internal1_m871_Pkv0) Pkv - передний конечный выключатель
#define internal1_m871_Pkav0	 BUFFER[12179]	//(internal1_m871_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m871_Pkav0	 1918	//(internal1_m871_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m871_Zkv0	 BUFFER[12180]	//(internal1_m871_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m871_Zkv0	 1919	//(internal1_m871_Zkv0) Zkv - задний конечный выключатель
#define internal1_m871_Zkav0	 BUFFER[12181]	//(internal1_m871_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m871_Zkav0	 1920	//(internal1_m871_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m871_txNm	 BUFFER[12182]	//(internal1_m871_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m871_txNm	 1921	//(internal1_m871_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m871_txSm	 BUFFER[12187]	//(internal1_m871_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m871_txSm	 1922	//(internal1_m871_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m871_txHr	 BUFFER[12192]	//(internal1_m871_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m871_txHr	 1923	//(internal1_m871_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m871_txLd	 BUFFER[12197]	//(internal1_m871_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m871_txLd	 1924	//(internal1_m871_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m871_fef	 BUFFER[12202]	//(internal1_m871_fef) fef
#define idinternal1_m871_fef	 1925	//(internal1_m871_fef) fef
#define internal1_m386_DvUp0	 BUFFER[12203]	//(internal1_m386_DvUp0) - есть команда на движение вперёд
#define idinternal1_m386_DvUp0	 1926	//(internal1_m386_DvUp0) - есть команда на движение вперёд
#define internal1_m386_DvDw0	 BUFFER[12204]	//(internal1_m386_DvDw0) - есть команда на движение назад
#define idinternal1_m386_DvDw0	 1927	//(internal1_m386_DvDw0) - есть команда на движение назад
#define internal1_m386_FDvUp0	 BUFFER[12205]	//(internal1_m386_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m386_FDvUp0	 1928	//(internal1_m386_FDvUp0) - есть команда на движение вперёд
#define internal1_m386_FDvDw0	 BUFFER[12206]	//(internal1_m386_FDvDw0) - есть команда на движение назад
#define idinternal1_m386_FDvDw0	 1929	//(internal1_m386_FDvDw0) - есть команда на движение назад
#define internal1_m386_BlDv0	 BUFFER[12207]	//(internal1_m386_BlDv0) - была блокировка
#define idinternal1_m386_BlDv0	 1930	//(internal1_m386_BlDv0) - была блокировка
#define internal1_m386_Pkv0	 BUFFER[12208]	//(internal1_m386_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m386_Pkv0	 1931	//(internal1_m386_Pkv0) Pkv - передний конечный выключатель
#define internal1_m386_Pkav0	 BUFFER[12209]	//(internal1_m386_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m386_Pkav0	 1932	//(internal1_m386_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m386_Zkv0	 BUFFER[12210]	//(internal1_m386_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m386_Zkv0	 1933	//(internal1_m386_Zkv0) Zkv - задний конечный выключатель
#define internal1_m386_Zkav0	 BUFFER[12211]	//(internal1_m386_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m386_Zkav0	 1934	//(internal1_m386_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m386_txNm	 BUFFER[12212]	//(internal1_m386_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m386_txNm	 1935	//(internal1_m386_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m386_txSm	 BUFFER[12217]	//(internal1_m386_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m386_txSm	 1936	//(internal1_m386_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m386_txHr	 BUFFER[12222]	//(internal1_m386_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m386_txHr	 1937	//(internal1_m386_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m386_txLd	 BUFFER[12227]	//(internal1_m386_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m386_txLd	 1938	//(internal1_m386_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m386_fef	 BUFFER[12232]	//(internal1_m386_fef) fef
#define idinternal1_m386_fef	 1939	//(internal1_m386_fef) fef
#define internal1_m423_DvUp0	 BUFFER[12233]	//(internal1_m423_DvUp0) - есть команда на движение вперёд
#define idinternal1_m423_DvUp0	 1940	//(internal1_m423_DvUp0) - есть команда на движение вперёд
#define internal1_m423_DvDw0	 BUFFER[12234]	//(internal1_m423_DvDw0) - есть команда на движение назад
#define idinternal1_m423_DvDw0	 1941	//(internal1_m423_DvDw0) - есть команда на движение назад
#define internal1_m423_FDvUp0	 BUFFER[12235]	//(internal1_m423_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m423_FDvUp0	 1942	//(internal1_m423_FDvUp0) - есть команда на движение вперёд
#define internal1_m423_FDvDw0	 BUFFER[12236]	//(internal1_m423_FDvDw0) - есть команда на движение назад
#define idinternal1_m423_FDvDw0	 1943	//(internal1_m423_FDvDw0) - есть команда на движение назад
#define internal1_m423_BlDv0	 BUFFER[12237]	//(internal1_m423_BlDv0) - была блокировка
#define idinternal1_m423_BlDv0	 1944	//(internal1_m423_BlDv0) - была блокировка
#define internal1_m423_Pkv0	 BUFFER[12238]	//(internal1_m423_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m423_Pkv0	 1945	//(internal1_m423_Pkv0) Pkv - передний конечный выключатель
#define internal1_m423_Pkav0	 BUFFER[12239]	//(internal1_m423_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m423_Pkav0	 1946	//(internal1_m423_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m423_Zkv0	 BUFFER[12240]	//(internal1_m423_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m423_Zkv0	 1947	//(internal1_m423_Zkv0) Zkv - задний конечный выключатель
#define internal1_m423_Zkav0	 BUFFER[12241]	//(internal1_m423_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m423_Zkav0	 1948	//(internal1_m423_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m423_txNm	 BUFFER[12242]	//(internal1_m423_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m423_txNm	 1949	//(internal1_m423_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m423_txSm	 BUFFER[12247]	//(internal1_m423_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m423_txSm	 1950	//(internal1_m423_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m423_txHr	 BUFFER[12252]	//(internal1_m423_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m423_txHr	 1951	//(internal1_m423_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m423_txLd	 BUFFER[12257]	//(internal1_m423_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m423_txLd	 1952	//(internal1_m423_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m423_fef	 BUFFER[12262]	//(internal1_m423_fef) fef
#define idinternal1_m423_fef	 1953	//(internal1_m423_fef) fef
#define internal1_m417_DvUp0	 BUFFER[12263]	//(internal1_m417_DvUp0) - есть команда на движение вперёд
#define idinternal1_m417_DvUp0	 1954	//(internal1_m417_DvUp0) - есть команда на движение вперёд
#define internal1_m417_DvDw0	 BUFFER[12264]	//(internal1_m417_DvDw0) - есть команда на движение назад
#define idinternal1_m417_DvDw0	 1955	//(internal1_m417_DvDw0) - есть команда на движение назад
#define internal1_m417_FDvUp0	 BUFFER[12265]	//(internal1_m417_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m417_FDvUp0	 1956	//(internal1_m417_FDvUp0) - есть команда на движение вперёд
#define internal1_m417_FDvDw0	 BUFFER[12266]	//(internal1_m417_FDvDw0) - есть команда на движение назад
#define idinternal1_m417_FDvDw0	 1957	//(internal1_m417_FDvDw0) - есть команда на движение назад
#define internal1_m417_BlDv0	 BUFFER[12267]	//(internal1_m417_BlDv0) - была блокировка
#define idinternal1_m417_BlDv0	 1958	//(internal1_m417_BlDv0) - была блокировка
#define internal1_m417_Pkv0	 BUFFER[12268]	//(internal1_m417_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m417_Pkv0	 1959	//(internal1_m417_Pkv0) Pkv - передний конечный выключатель
#define internal1_m417_Pkav0	 BUFFER[12269]	//(internal1_m417_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m417_Pkav0	 1960	//(internal1_m417_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m417_Zkv0	 BUFFER[12270]	//(internal1_m417_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m417_Zkv0	 1961	//(internal1_m417_Zkv0) Zkv - задний конечный выключатель
#define internal1_m417_Zkav0	 BUFFER[12271]	//(internal1_m417_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m417_Zkav0	 1962	//(internal1_m417_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m417_txNm	 BUFFER[12272]	//(internal1_m417_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m417_txNm	 1963	//(internal1_m417_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m417_txSm	 BUFFER[12277]	//(internal1_m417_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m417_txSm	 1964	//(internal1_m417_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m417_txHr	 BUFFER[12282]	//(internal1_m417_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m417_txHr	 1965	//(internal1_m417_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m417_txLd	 BUFFER[12287]	//(internal1_m417_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m417_txLd	 1966	//(internal1_m417_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m417_fef	 BUFFER[12292]	//(internal1_m417_fef) fef
#define idinternal1_m417_fef	 1967	//(internal1_m417_fef) fef
#define internal1_m823_q0	 BUFFER[12293]	//(internal1_m823_q0) q0 - внутренний параметр
#define idinternal1_m823_q0	 1968	//(internal1_m823_q0) q0 - внутренний параметр
#define internal1_m820_q0	 BUFFER[12295]	//(internal1_m820_q0) q0 - внутренний параметр
#define idinternal1_m820_q0	 1969	//(internal1_m820_q0) q0 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &B2AB15LDU},	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 2	,1	,1	, &R0AD21LDU},	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
	{ 3	,1	,1	, &R0VX02LDU},	//( - , DU) Импульс разрешен
	{ 4	,1	,1	, &R0EE03LDU},	//( - , DU) ВПИС ИС
	{ 5	,1	,1	, &R0AB07LDU},	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{ 6	,1	,1	, &C2MD31LP1},	//( - , DU) Кнопка СБРОС РБ
	{ 7	,3	,1	, &B6VS01IDU},	//( - , DU) Готовность к управлению БЗ2
	{ 8	,1	,1	, &R2AD20LDU},	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
	{ 9	,1	,1	, &R2AD10LDU},	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
	{ 10	,3	,1	, &B8VS01IDU},	//( - , DU) Готовность к управлению АЗ2
	{ 11	,3	,1	, &A8VS01IDU},	//( - , DU) Готовность к управлению ДС2
	{ 12	,1	,1	, &A1IE03LDU},	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
	{ 13	,1	,1	, &A1IE04LDU},	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
	{ 14	,1	,1	, &A2IE03LDU},	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
	{ 15	,1	,1	, &A2IE04LDU},	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
	{ 16	,1	,1	, &A3IE03LDU},	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
	{ 17	,1	,1	, &A3IE04LDU},	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
	{ 18	,1	,1	, &B1IE03LDU},	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
	{ 19	,1	,1	, &B1IE04LDU},	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
	{ 20	,1	,1	, &B2IE03LDU},	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
	{ 21	,1	,1	, &B2IE04LDU},	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
	{ 22	,1	,1	, &B3IE03LDU},	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
	{ 23	,1	,1	, &B3IE04LDU},	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
	{ 24	,1	,1	, &R0AD14LZ1},	//(vds32:02 - K20VDSR, DU) Имитация срабатывания АЗ от II УР
	{ 25	,1	,1	, &R0AD14LZ2},	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	{ 26	,1	,1	, &A3VZ13LZ2},	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{ 27	,1	,1	, &A3VZ13LZ1},	//(vds32:02 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{ 28	,1	,1	, &A3VZ15LZ1},	//(vds32:02 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{ 29	,1	,1	, &A3VZ15LZ2},	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{ 30	,1	,1	, &B2IS33LDU},	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
	{ 31	,1	,1	, &B3IS31LDU},	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
	{ 32	,1	,1	, &B3IS33LDU},	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
	{ 33	,1	,1	, &B3IS35LDU},	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
	{ 34	,1	,1	, &B4IS10LDU},	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
	{ 35	,1	,1	, &R6IS31LDU},	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
	{ 36	,1	,1	, &R6IS32LDU},	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
	{ 37	,1	,1	, &R6IS42LDU},	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
	{ 38	,1	,1	, &R6IS41LDU},	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
	{ 39	,1	,1	, &R6IS52LDU},	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
	{ 40	,1	,1	, &R6IS51LDU},	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
	{ 41	,1	,1	, &R3IS11LDU},	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
	{ 42	,1	,1	, &R3IS21LDU},	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
	{ 43	,1	,1	, &R0AB03LDU},	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
	{ 44	,1	,1	, &R0AB05LDU},	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
	{ 45	,8	,1	, &R0VN11RZ1},	//( - , MDuBz1) Средняя мощность по BAZ1
	{ 46	,8	,1	, &R0VN11RZ2},	//( - , MDuBz2) Средняя мощность по BAZ2
	{ 47	,1	,1	, &A2AB15LDU},	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 48	,1	,1	, &R0AB14LDU},	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{ 49	,1	,1	, &R0AB15LDU},	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{ 50	,1	,1	, &A3IS12LDU},	//( - , DU) Приход на ВУ штока ИС1
	{ 51	,1	,1	, &B3IS12LDU},	//( - , DU) Приход на ВУ штока ИС2
	{ 52	,1	,1	, &A1ZAV},	//( - , DU) 
	{ 53	,1	,1	, &A3ZAV},	//( - , DU) 
	{ 54	,1	,1	, &B1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{ 55	,1	,1	, &R0AB16LDU},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{ 56	,1	,1	, &R0AB17LDU},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{ 57	,1	,1	, &R0AB18LDU},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{ 58	,8	,1	, &A0CT01IZ1},	//( - , MDuBz1) Температура АЗ1-1
	{ 59	,8	,1	, &B0CT01IZ1},	//( - , MDuBz1) Температура АЗ2-1
	{ 60	,8	,1	, &A0CT01IZ2},	//( - , MDuBz2) Температура АЗ1-2
	{ 61	,8	,1	, &B0CT01IZ2},	//( - , MDuBz2) Температура АЗ2-2
	{ 62	,8	,1	, &A3MC01RDU},	//( - , DU) Заданная координата положения ИС от регулятора мм
	{ 63	,8	,1	, &A3MC02RDU},	//( - , DU) Температурная корректировка координаты ИМ
	{ 64	,8	,1	, &R0CN91LDU},	//( - , DU) Рассчётная реактивность от регулятора
	{ 65	,8	,1	, &A3MC03RDU},	//( - , DU) Координата положения ИМ 0-й реактивности
	{ 66	,1	,1	, &A3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	{ 67	,1	,1	, &R0AB20LDU},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	{ 68	,8	,1	, &R0CN92LDU},	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
	{ 69	,8	,1	, &R0VN11RDU},	//( - , DU) Текущая мощность РУ
	{ 70	,8	,1	, &R0VN12RDU},	//( - , DU) Заданная мощность РУ
	{ 71	,1	,1	, &R0VS11LDU},	//( - , DU) РУ не готова к работе
	{ 72	,1	,1	, &B6AB05LDU},	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
	{ 73	,1	,1	, &R0AB08LDU},	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
	{ 74	,8	,1	, &A1MC01RP1},	//( - , DU) Заданная координата положения ББ1 мм
	{ 75	,8	,1	, &B1MC01RP1},	//( - , DU) Заданная координата положения ББ2  мм
	{ 76	,8	,1	, &A3MC01RP1},	//( - , DU) Заданная координата положения ИС1 мм
	{ 77	,8	,1	, &B3MC01RP1},	//( - , DU) Заданная координата положения ИС2 мм
	{ 78	,8	,1	, &B8MC01RP2},	//( - , DU) Заданная координата АЗ2 мм
	{ 79	,1	,1	, &R0AB09LDU},	//( - , DU) Ошибка в заданной координате ББ1
	{ 80	,1	,1	, &R0AB10LDU},	//( - , DU) Ошибка в заданной координате ББ2
	{ 81	,1	,1	, &R0AB11LDU},	//( - , DU) Ошибка в заданной координате  ИС1
	{ 82	,1	,1	, &R0AB12LDU},	//( - , DU) Ошибка в заданной координате  ИС2
	{ 83	,1	,1	, &R0AB13LDU},	//( - , DU) Ошибка в заданной координате  АЗ2
	{ 84	,1	,1	, &A4ZAV},	//( - , DU) 
	{ 85	,1	,1	, &A6ZAV},	//( - , DU) 
	{ 86	,1	,1	, &R2ZAV},	//( - , DU) 
	{ 87	,1	,1	, &A5ZAV},	//( - , DU) 
	{ 88	,1	,1	, &B8ZAV},	//( - , DU) 
	{ 89	,1	,1	, &A2ZAV},	//( - , DU) Завершение РБ1,2
	{ 90	,1	,1	, &A8ZAV},	//( - , DU) 
	{ 91	,1	,1	, &A9ZAV},	//( - , DU) Завершение НИ ДС1(2)
	{ 92	,1	,1	, &R4ABL},	//( - , DU) Блокировка тележки -
	{ 93	,1	,1	, &A4UP},	//( - , DU) 
	{ 94	,1	,1	, &A4DW},	//( - , DU) 
	{ 95	,1	,1	, &A3IS22LDU},	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
	{ 96	,1	,1	, &B3IS22LDU},	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
	{ 97	,1	,1	, &A2AD33LDU},	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
	{ 98	,1	,1	, &B2AD33LDU},	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
	{ 99	,1	,1	, &A3AD33LDU},	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
	{ 100	,1	,1	, &A3AD34LDU},	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
	{ 101	,1	,1	, &A3AD31LDU},	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
	{ 102	,1	,1	, &B3AD34LDU},	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
	{ 103	,1	,1	, &B3AD31LDU},	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
	{ 104	,1	,1	, &A2IS11LDU},	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
	{ 105	,1	,1	, &B2IS11LDU},	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
	{ 106	,1	,1	, &A3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
	{ 107	,1	,1	, &A3MD11LP1},	//( - , DU) Кнопка ПУСК ИС1
	{ 108	,1	,1	, &R0MD33LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
	{ 109	,1	,1	, &A1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
	{ 110	,1	,1	, &A1MD11LP1},	//( - , DU) Кнопка ПУСК ББ1
	{ 111	,3	,1	, &R0MW14IP2},	//( - , DU) Переключатель ОБДУВ
	{ 112	,1	,1	, &A7AP31LDU},	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
	{ 113	,1	,1	, &B7AP31LDU},	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
	{ 114	,3	,1	, &R0MW12IP2},	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
	{ 115	,1	,1	, &R0MW17LP1},	//( - , DU) Переключатель АВТ/Р
	{ 116	,1	,1	, &R0VW13LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 117	,1	,1	, &R0VW23LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 118	,1	,1	, &A4VS12LDU},	//( - , DU) Движение НИ1 в сторону ВУ
	{ 119	,1	,1	, &A4VS22LDU},	//( - , DU) Движение НИ1 в сторону НУ
	{ 120	,3	,1	, &B4VS01IDU},	//( - , DU) Готовность к управлению НИ2
	{ 121	,1	,1	, &B4VS12LDU},	//( - , DU) Движение НИ2 в сторону ВУ
	{ 122	,1	,1	, &B4VS22LDU},	//( - , DU) Движение НИ2 в сторону НУ
	{ 123	,3	,1	, &A5VS01IDU},	//( - , DU) Готовность к управлению НЛ1
	{ 124	,3	,1	, &B5VS01IDU},	//( - , DU) Готовность к управлению НЛ2
	{ 125	,3	,1	, &A6VS01IDU},	//( - , DU) Готовность к управлению БЗ1
	{ 126	,3	,1	, &R4VS01IDU},	//( - , DU) Готовность к управлению тележкой реактора
	{ 127	,3	,1	, &R2VS01IDU},	//( - , DU) Готовность к управлению МДЗ2
	{ 128	,3	,1	, &R1VS01IDU},	//( - , DU) Готовность к управлению МДЗ1
	{ 129	,1	,1	, &A9IS11LDU},	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
	{ 130	,1	,1	, &A9IS21LDU},	//(vds32:02 - K24VDSR, DU) Приход на НУ НИ ДС1
	{ 131	,1	,1	, &B9IS11LDU},	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
	{ 132	,1	,1	, &B9IS21LDU},	//(vds32:02 - K26VDSR, DU) Приход на НУ НИ ДС2
	{ 133	,1	,1	, &B9AD10LDU},	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
	{ 134	,1	,1	, &A9AD10LDU},	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
	{ 135	,1	,1	, &A9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС1
	{ 136	,1	,1	, &A9AB01LDU},	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
	{ 137	,1	,1	, &A9AB02LDU},	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
	{ 138	,1	,1	, &B9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС2
	{ 139	,1	,1	, &B9AB01LDU},	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
	{ 140	,1	,1	, &B9AB02LDU},	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
	{ 141	,1	,1	, &R0AB01LDU},	//( - , DU) Режим проверки разрешён
	{ 142	,1	,1	, &A0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ1
	{ 143	,1	,1	, &B0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ2
	{ 144	,1	,1	, &B2VS11LDU},	//( - , DU) Движение РБ2 в сторону ВУ
	{ 145	,1	,1	, &B2VS21LDU},	//( - , DU) Движение РБ2 в сторону НУ
	{ 146	,3	,1	, &B2VS01IDU},	//( - , DU) Готовность к управлению РБ2
	{ 147	,1	,1	, &A7AS31LDU},	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
	{ 148	,1	,1	, &B7AS31LDU},	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
	{ 149	,1	,1	, &A7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ1
	{ 150	,1	,1	, &B7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ2
	{ 151	,1	,1	, &B3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
	{ 152	,1	,1	, &B3MD11LP1},	//( - , DU) Кнопка ПУСК ИС2
	{ 153	,8	,1	, &R0VL01RDU},	//( - , DU) Индикация Время задержки
	{ 154	,1	,1	, &R0VZ71LZ2},	//(vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
	{ 155	,1	,1	, &R0VZ71LZ1},	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
	{ 156	,1	,1	, &R0VZ71LDU},	//( - , DU) Обобщенный сигнал АЗ
	{ 157	,1	,1	, &A2IS33LDU},	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	{ 158	,1	,1	, &A3IS31LDU},	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	{ 159	,1	,1	, &A3IS33LDU},	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	{ 160	,1	,1	, &A3IS35LDU},	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	{ 161	,1	,1	, &A4IS10LDU},	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	{ 162	,1	,1	, &A1VN71LZ1},	//(vds32:02 - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{ 163	,1	,1	, &A1VN71LZ2},	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{ 164	,1	,1	, &A1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{ 165	,3	,1	, &R0VX08IDU},	//( - , DU) Индикация Режим
	{ 166	,1	,1	, &R0VX09LDU},	//( - , DU) Индикация регулятор мощности включен/отключен
	{ 167	,1	,1	, &R0VS17LDU},	//( - , DU) Индикация выбора АВТОМАТ
	{ 168	,1	,1	, &A2VS32LDU},	//( - , DU) Индикация  СБРОС РБ1
	{ 169	,1	,1	, &B2VS32LDU},	//( - , DU) Индикация  СБРОС РБ2
	{ 170	,1	,1	, &A3VX01LDU},	//( - , DU) Индикация Выстрел ИС1
	{ 171	,1	,1	, &B3VX01LDU},	//( - , DU) Индикация Выстрел ИС2
	{ 172	,1	,1	, &R0VS18LDU},	//( - , DU) Индикация  Проверка схем сброса
	{ 173	,1	,1	, &B1MD11LP1},	//( - , DU) Кнопка ПУСК ББ2
	{ 174	,1	,1	, &B1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	{ 175	,1	,1	, &B2MD11LP1},	//( - , DU) Кнопка ПУСК РБ2
	{ 176	,1	,1	, &B2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	{ 177	,1	,1	, &A2MD11LP1},	//( - , DU) Кнопка ПУСК РБ1
	{ 178	,1	,1	, &A2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
	{ 179	,1	,1	, &B3IS11LDU},	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
	{ 180	,1	,1	, &A3IS11LDU},	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
	{ 181	,1	,1	, &R0IS01LDU},	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
	{ 182	,1	,1	, &R0IS02LDU},	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
	{ 183	,1	,1	, &R0VP73LZ1},	//( - , MDuBz1) ПС давления для РУ
	{ 184	,1	,1	, &R0VP73LZ2},	//( - , MDuBz2) ПС давления для РУ
	{ 185	,1	,1	, &R0VP73LDU},	//( - , DU) ПС давления для РУ
	{ 186	,1	,1	, &R0MD34LP1},	//( - , DU) Кнопка КВИТИРОВАТЬ
	{ 187	,1	,1	, &A0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ1
	{ 188	,1	,1	, &B0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ2
	{ 189	,1	,1	, &B8MC01LC1},	//( - , DU) Настроить энкодер АЗ2
	{ 190	,1	,1	, &B8MC01LC2},	//( - , DU) Настроить энкодер АЗ2
	{ 191	,1	,1	, &A8MC01LC1},	//( - , DU) Настроить энкодер ДС2
	{ 192	,1	,1	, &A8MC01LC2},	//( - , DU) Настроить энкодер ДС2
	{ 193	,1	,1	, &A3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
	{ 194	,8	,1	, &A3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
	{ 195	,1	,1	, &A3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{ 196	,1	,1	, &B3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
	{ 197	,8	,1	, &B3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
	{ 198	,1	,1	, &B3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{ 199	,1	,1	, &B3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
	{ 200	,1	,1	, &A3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
	{ 201	,3	,1	, &A3IP02IDU},	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
	{ 202	,3	,1	, &B3IP02IDU},	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
	{ 203	,1	,1	, &A0VE01LDU},	//( - , DU) Напряжение в системы АЗ1 подано
	{ 204	,1	,1	, &B0VE01LDU},	//( - , DU) Напряжение в системы АЗ2 подано
	{ 205	,1	,1	, &A0VP01LDU},	//( - , DU) Давление в системы АЗ1 подано
	{ 206	,1	,1	, &B0VP01LDU},	//( - , DU) Давление в системы АЗ2 подано
	{ 207	,1	,1	, &A0EE01LZ1},	//( - , MDuBz1) Исправность АКНП1
	{ 208	,1	,1	, &A0EE03LZ1},	//( - , MDuBz1) Исправность АКНП3
	{ 209	,1	,1	, &A0EE02LZ1},	//( - , MDuBz1) Исправность АКНП2
	{ 210	,1	,1	, &A0EE04LZ1},	//( - , MDuBz1) Исправность АКНП4
	{ 211	,1	,1	, &A0VN01LDU},	//( - , DU) Каналы АЗ1 проверены
	{ 212	,1	,1	, &B1IS11LDU},	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
	{ 213	,5	,1	, &A2IC01UDU},	//( - , MDuS) Координата штока РБ1 (дел.энк)
	{ 214	,5	,1	, &B2IC01UDU},	//( - , MDuS) Координата штока РБ2 (дел.энк)
	{ 215	,5	,1	, &A3IC01UDU},	//( - , MDuS) Координата штока ИС1 (дел.энк)
	{ 216	,5	,1	, &B3IC01UDU},	//( - , MDuS) Координата штока ИС2 (дел.энк)
	{ 217	,8	,1	, &B3VC01RDU},	//( - , DU) Координата ИС2, мм
	{ 218	,5	,1	, &A8IC01UDU},	//( - , MDuS) Координата ДС2 (дел.энк)
	{ 219	,8	,1	, &A8VC01RDU},	//( - , DU) Координата ДС2, мм
	{ 220	,5	,1	, &B8IC01UDU},	//( - , MDuS) Координата АЗ2 (дел.энк)
	{ 221	,5	,1	, &A1IC01UDU},	//( - , MDuS) Координата штока ББ1 (дел.энк)
	{ 222	,8	,1	, &A1VC01RDU},	//( - , DU) Координата ББ1, мм
	{ 223	,1	,1	, &A1IS11LDU},	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
	{ 224	,1	,1	, &B1MC01LC1},	//( - , DU) Настроить энкодер ББ2
	{ 225	,1	,1	, &B1MC01LC2},	//( - , DU) Настроить энкодер ББ2
	{ 226	,1	,1	, &A1MC01LC1},	//( - , DU) Настроить энкодер ББ1
	{ 227	,1	,1	, &A1MC01LC2},	//( - , DU) Настроить энкодер ББ1
	{ 228	,1	,1	, &B2MC01LC1},	//( - , DU) Настроить энкодер РБ2
	{ 229	,1	,1	, &B2MC01LC2},	//( - , DU) Настроить энкодер РБ2
	{ 230	,1	,1	, &A2MC01LC1},	//( - , DU) Настроить энкодер РБ1
	{ 231	,1	,1	, &A2MC01LC2},	//( - , DU) Настроить энкодер РБ1
	{ 232	,1	,1	, &B3MC01LC1},	//( - , DU) Настроить энкодер ИС2
	{ 233	,1	,1	, &B3MC01LC2},	//( - , DU) Настроить энкодер ИС2
	{ 234	,1	,1	, &A3MC01LC1},	//( - , DU) Настроить энкодер ИС1
	{ 235	,1	,1	, &A3MC01LC2},	//( - , DU) Настроить энкодер ИС1
	{ 236	,1	,1	, &R0IE01LDU},	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
	{ 237	,1	,1	, &A6IE01LDU},	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
	{ 238	,1	,1	, &B6IE01LDU},	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
	{ 239	,1	,1	, &A8IE01LDU},	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
	{ 240	,1	,1	, &B5IE01LDU},	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
	{ 241	,1	,1	, &A5IE02LDU},	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
	{ 242	,1	,1	, &R1IE01LDU},	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
	{ 243	,1	,1	, &R2IE01LDU},	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
	{ 244	,1	,1	, &R6IS61LDU},	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
	{ 245	,1	,1	, &R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 246	,1	,1	, &R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 247	,1	,1	, &R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 248	,8	,1	, &A3VC01RDU},	//( - , DU) Координата ИС1, мм
	{ 249	,8	,1	, &A2VC01RDU},	//( - , DU) Координата РБ1, мм
	{ 250	,8	,1	, &B2VC01RDU},	//( - , DU) Координата РБ2, мм
	{ 251	,8	,1	, &B8VC01RDU},	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
	{ 252	,1	,1	, &A4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
	{ 253	,1	,1	, &B4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
	{ 254	,1	,1	, &A2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
	{ 255	,1	,1	, &B2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
	{ 256	,1	,1	, &A3VP81LDU},	//( - , - ) Давление СПУСК ИС1 в норме
	{ 257	,1	,1	, &B3VP81LDU},	//( - , - ) Давление СПУСК ИС2 в норме
	{ 258	,1	,1	, &R0EE02LDU},	//( - , DU) Питание  АКНП  отключить
	{ 259	,1	,1	, &B0VN01LDU},	//( - , DU) Каналы АЗ2 проверены
	{ 260	,1	,1	, &A0EE01LZ2},	//( - , MDuBz2) Исправность АКНП1
	{ 261	,1	,1	, &A0EE03LZ2},	//( - , MDuBz2) Исправность АКНП3
	{ 262	,1	,1	, &A0EE02LZ2},	//( - , MDuBz2) Исправность АКНП2
	{ 263	,1	,1	, &A0EE04LZ2},	//( - , MDuBz2) Исправность АКНП4
	{ 264	,1	,1	, &A0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
	{ 265	,1	,1	, &A0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
	{ 266	,1	,1	, &B0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
	{ 267	,1	,1	, &B0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
	{ 268	,1	,1	, &A0VS11LDU},	//( - , DU) АЗ1 готова к работе
	{ 269	,1	,1	, &B0VS11LDU},	//( - , DU) АЗ2 готова к работе
	{ 270	,1	,1	, &A1IE01LDU},	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
	{ 271	,1	,1	, &A3IE01LDU},	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
	{ 272	,1	,1	, &A2IE01LDU},	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
	{ 273	,1	,1	, &A1IE02LDU},	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
	{ 274	,1	,1	, &A3IE02LDU},	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
	{ 275	,1	,1	, &A2IE02LDU},	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
	{ 276	,1	,1	, &B1IE01LDU},	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
	{ 277	,1	,1	, &B2IE01LDU},	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
	{ 278	,1	,1	, &B3IE01LDU},	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
	{ 279	,1	,1	, &B1IE02LDU},	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
	{ 280	,1	,1	, &B3IE02LDU},	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
	{ 281	,1	,1	, &B2IE02LDU},	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
	{ 282	,1	,1	, &R0IE02LDU},	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
	{ 283	,1	,1	, &R5VS22LDU},	//( - , DU) Движение ворот отстойной зоны к закрыты
	{ 284	,1	,1	, &R5VS12LDU},	//( - , DU) Движение ворот отстойной зоны к открыты
	{ 285	,3	,1	, &R5VS01IDU},	//( - , DU) Готовность к управлению ворот отстойной зоны
	{ 286	,1	,1	, &R3VS22LDU},	//( - , DU) Движение гомогенных дверей к закрыты
	{ 287	,1	,1	, &R3VS12LDU},	//( - , DU) Движение гомогенных дверей к открыты
	{ 288	,3	,1	, &R3VS01IDU},	//( - , DU) Готовность к управлению гомогенных дверей
	{ 289	,1	,1	, &A3AB13LDU},	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
	{ 290	,1	,1	, &B3AB13LDU},	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{ 291	,3	,1	, &R0DE02LDU},	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
	{ 292	,3	,1	, &R0DE03LDU},	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
	{ 293	,3	,1	, &R0DE04LDU},	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
	{ 294	,3	,1	, &R0DE08LDU},	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
	{ 295	,3	,1	, &R0DE05LDU},	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
	{ 296	,3	,1	, &R0DE09LDU},	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
	{ 297	,3	,1	, &R0DE0ALDU},	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
	{ 298	,3	,1	, &R0DE07LDU},	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
	{ 299	,3	,1	, &R0DE0CLDU},	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
	{ 300	,3	,1	, &R0DE0BLDU},	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
	{ 301	,3	,1	, &R0DE0DLDU},	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
	{ 302	,3	,1	, &R0DE0FLDU},	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
	{ 303	,3	,1	, &TTLDU},	//( - , DU) ttl
	{ 304	,1	,1	, &R0DEB3LDU},	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
	{ 305	,1	,1	, &R0DEB2LDU},	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
	{ 306	,1	,1	, &R0AB19LDU},	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
	{ 307	,8	,1	, &R0CN93LDU},	//( - , DU) время работы на мощности более 100Вт, сек
	{ 308	,8	,1	, &R0CN94LDU},	//( - , DU) Скорость изменения мощности
	{ 309	,3	,1	, &R0CN95LDU},	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
	{ 310	,1	,1	, &R0AD03LZ1},	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
	{ 311	,1	,1	, &R0AD03LZ2},	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
	{ 312	,1	,1	, &R0AD04LZ1},	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
	{ 313	,1	,1	, &R0AD04LZ2},	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
	{ 314	,1	,1	, &R0AD05LZ1},	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
	{ 315	,1	,1	, &R0AD05LZ2},	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
	{ 316	,1	,1	, &B8IS12LDU},	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
	{ 317	,1	,1	, &B8IS21LDU},	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
	{ 318	,1	,1	, &A1VP41LZ1},	//( - , MDuBz1) Давление СБРОС ББ1 ниже АС
	{ 319	,1	,1	, &A1VP41LZ2},	//( - , MDuBz2) Давление СБРОС ББ1 ниже АС
	{ 320	,1	,1	, &R0VL22LDU},	//( - , DU) Конец программы 200сек
	{ 321	,1	,1	, &R0VL23LDU},	//( - , DU) Конец программы 20мин
	{ 322	,1	,1	, &B1VP41LZ1},	//( - , MDuBz1) Давление СБРОС ББ2 ниже АС
	{ 323	,1	,1	, &B1VP41LZ2},	//( - , MDuBz2) Давление СБРОС ББ2 ниже АС
	{ 324	,1	,1	, &A3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
	{ 325	,1	,1	, &B3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
	{ 326	,1	,1	, &A3EE03LDU},	//( - , DU) ВПИС ИС1
	{ 327	,1	,1	, &B3EE03LDU},	//( - , DU) ВПИС ИС2
	{ 328	,1	,1	, &B3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
	{ 329	,1	,1	, &R5IS21LDU},	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
	{ 330	,1	,1	, &psz1},	//( - , DU) 
	{ 331	,1	,1	, &psz2},	//( - , DU) 
	{ 332	,1	,1	, &psz3},	//( - , DU) 
	{ 333	,1	,1	, &psz4},	//( - , DU) 
	{ 334	,1	,1	, &psz5},	//( - , DU) 
	{ 335	,1	,1	, &psz6},	//( - , DU) 
	{ 336	,1	,1	, &psz7},	//( - , DU) 
	{ 337	,1	,1	, &psz8},	//( - , DU) 
	{ 338	,1	,1	, &psz9},	//( - , DU) 
	{ 339	,1	,1	, &psz10},	//( - , DU) 
	{ 340	,1	,1	, &psz11},	//( - , DU) 
	{ 341	,1	,1	, &psz12},	//( - , DU) 
	{ 342	,1	,1	, &psz13},	//( - , DU) 
	{ 343	,1	,1	, &psz14},	//( - , DU) 
	{ 344	,1	,1	, &psz21},	//( - , DU) 
	{ 345	,1	,1	, &psz22},	//( - , DU) 
	{ 346	,1	,1	, &psz23},	//( - , DU) 
	{ 347	,1	,1	, &psz24},	//( - , DU) 
	{ 348	,1	,1	, &psz25},	//( - , DU) 
	{ 349	,1	,1	, &psz26},	//( - , DU) 
	{ 350	,1	,1	, &psz27},	//( - , DU) 
	{ 351	,1	,1	, &psz28},	//( - , DU) 
	{ 352	,5	,1	, &B1IC01UDU},	//( - , MDuS) Координата штока ББ2 (дел.энк)
	{ 353	,8	,1	, &B1VC01RDU},	//( - , DU) Координата ББ2, мм
	{ 354	,1	,1	, &R0DEB1LDU},	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
	{ 355	,1	,1	, &R0DEB4LDU},	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
	{ 356	,1	,1	, &R0DE3DLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
	{ 357	,1	,1	, &R0DE3CLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
	{ 358	,1	,1	, &TestDiagnDU},	//( - , DU) Неисправность от
	{ 359	,8	,1	, &B3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС2
	{ 360	,3	,1	, &R0DE01LDU},	//(vencf8l:01 - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
	{ 361	,3	,1	, &R0DE06LDU},	//(vencf8l:01 - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
	{ 362	,5	,1	, &venc01},	//(vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
	{ 363	,5	,1	, &venc02},	//(vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
	{ 364	,5	,1	, &venc03},	//(vencf8l:01 - venc03, - ) заначение реального энкодера Ис1
	{ 365	,5	,1	, &venc04},	//(vencf8l:01 - venc04, - ) заначение реального энкодера ДС1
	{ 366	,5	,1	, &venc05},	//(vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
	{ 367	,5	,1	, &venc06},	//(vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
	{ 368	,5	,1	, &venc07},	//(vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
	{ 369	,5	,1	, &venc08},	//(vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
	{ 370	,8	,1	, &R0VN15RDU},	//( - , DU) Период разгона РУ
	{ 371	,1	,1	, &R8AD21LDU},	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
	{ 372	,1	,1	, &R8AD22LDU},	//(vds32:02 - K15VDSR, - ) Сигнал синхронизации с импульсом
	{ 373	,1	,1	, &R0S01LDU},	//( - , - ) Отключение сетевых передач ДУ
	{ 374	,1	,1	, &R0S01LZ1},	//(fds16:07 - K15FDSR, - ) Отключение сетевых передач в Баз1
	{ 375	,1	,1	, &R0S01LZ2},	//(fds16:07 - K16FDSR, - ) Отключение сетевых передач в Баз2
	{ 376	,1	,1	, &R0AD16LDU},	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
	{ 377	,1	,1	, &R0S01LIM},	//(fds16:08 - K15FDSR, - ) Отключение сетевых передач ПТИ
	{ 378	,1	,1	, &B6AB06LDU},	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
	{ 379	,1	,1	, &B6AB07LDU},	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
	{ 380	,1	,1	, &B6AB08LDU},	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
	{ 381	,1	,1	, &B6AB09LDU},	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
	{ 382	,1	,1	, &A6AB05LDU},	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
	{ 383	,1	,1	, &B8VS12LDU},	//( - , DU) Движение АЗ2 в сторону ВУ
	{ 384	,8	,1	, &B8CV01RDU},	//( - , DU) Измеренная скорость перемещения АЗ2
	{ 385	,1	,1	, &B8AB06LDU},	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
	{ 386	,1	,1	, &B8AB07LDU},	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
	{ 387	,1	,1	, &B8AB05LDU},	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
	{ 388	,1	,1	, &B8VS22LDU},	//( - , DU) Движение АЗ2 в сторону НУ
	{ 389	,1	,1	, &B8AZ03LDU},	//( - , DU) Несанкционированное перемещение АЗ2
	{ 390	,1	,1	, &R0MD11LP1},	//( - , DU) Кнопка ПУСК
	{ 391	,1	,1	, &B8AD10LDU},	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
	{ 392	,1	,1	, &B8AD20LDU},	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
	{ 393	,1	,1	, &B8IS11LDU},	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
	{ 394	,1	,1	, &B8AB01LDU},	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
	{ 395	,1	,1	, &B8AB04LDU},	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
	{ 396	,1	,1	, &B8AB08LDU},	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
	{ 397	,1	,1	, &B8AB09LDU},	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
	{ 398	,1	,1	, &B8AB10LDU},	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
	{ 399	,1	,1	, &B8AB11LDU},	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
	{ 400	,1	,1	, &B8AB12LDU},	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
	{ 401	,1	,1	, &B5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ2
	{ 402	,1	,1	, &B5AB01LDU},	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
	{ 403	,1	,1	, &B5AB02LDU},	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
	{ 404	,1	,1	, &A4IS21LDU},	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
	{ 405	,1	,1	, &B4IS21LDU},	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
	{ 406	,1	,1	, &B4AD10LDU},	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
	{ 407	,1	,1	, &A4AD10LDU},	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
	{ 408	,1	,1	, &A4AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ1
	{ 409	,1	,1	, &A4AB01LDU},	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
	{ 410	,1	,1	, &A4AB02LDU},	//( - , DU) Блокировка движения НИ1 - Нет перемещения
	{ 411	,1	,1	, &B4AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ2
	{ 412	,1	,1	, &B4AB01LDU},	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
	{ 413	,1	,1	, &B4AB02LDU},	//( - , DU) Блокировка движения НИ2 - Нет перемещения
	{ 414	,1	,1	, &A5AB04LDU},	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
	{ 415	,1	,1	, &B5AB04LDU},	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
	{ 416	,1	,1	, &A1IS12LDU},	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
	{ 417	,1	,1	, &A2IS12LDU},	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
	{ 418	,1	,1	, &B1IS12LDU},	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
	{ 419	,1	,1	, &B2IS12LDU},	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
	{ 420	,1	,1	, &R4IS11LDU},	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
	{ 421	,1	,1	, &A6AB06LDU},	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
	{ 422	,1	,1	, &A6AB07LDU},	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
	{ 423	,1	,1	, &A6AB08LDU},	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
	{ 424	,1	,1	, &A6AB09LDU},	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
	{ 425	,1	,1	, &A8AB01LDU},	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
	{ 426	,1	,1	, &A2VS11LDU},	//( - , DU) Движение РБ1 в сторону ВУ
	{ 427	,8	,1	, &A2CV01RDU},	//( - , DU) Измеренная скорость перемещения РБ1
	{ 428	,1	,1	, &A2AB04LDU},	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
	{ 429	,1	,1	, &A2AB02LDU},	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
	{ 430	,1	,1	, &A2AB01LDU},	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
	{ 431	,1	,1	, &A2VS21LDU},	//( - , DU) Движение РБ1 в сторону НУ
	{ 432	,1	,1	, &A2AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
	{ 433	,1	,1	, &A2AD11LDU},	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
	{ 434	,1	,1	, &A2AD21LDU},	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
	{ 435	,1	,1	, &A2AD02LDU},	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
	{ 436	,1	,1	, &A2AD03LDU},	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
	{ 437	,1	,1	, &A2AD04LDU},	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
	{ 438	,1	,1	, &A2AD05LDU},	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
	{ 439	,1	,1	, &A2AB07LDU},	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
	{ 440	,1	,1	, &A2AB08LDU},	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
	{ 441	,1	,1	, &A2AB05LDU},	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
	{ 442	,1	,1	, &A2AB06LDU},	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
	{ 443	,1	,1	, &A2AB09LDU},	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
	{ 444	,1	,1	, &A2AB10LDU},	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
	{ 445	,1	,1	, &A2AB11LDU},	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	{ 446	,1	,1	, &A2AB12LDU},	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 447	,1	,1	, &A2AB13LDU},	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
	{ 448	,1	,1	, &B8AB13LDU},	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
	{ 449	,1	,1	, &B8AB14LDU},	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
	{ 450	,1	,1	, &B8AB02LDU},	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
	{ 451	,1	,1	, &A8VS12LDU},	//( - , DU) Движение ДС2 в сторону ВУ
	{ 452	,8	,1	, &A8CV01RDU},	//( - , DU) Измеренная скорость перемещения ДС2
	{ 453	,1	,1	, &A8AB06LDU},	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
	{ 454	,1	,1	, &A8AB07LDU},	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
	{ 455	,1	,1	, &A8AB05LDU},	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
	{ 456	,1	,1	, &A8VS22LDU},	//( - , DU) Движение ДС2 в сторону НУ
	{ 457	,1	,1	, &A8AZ03LDU},	//( - , DU) Несанкционированное перемещение ДС2
	{ 458	,1	,1	, &A8AD10LDU},	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
	{ 459	,1	,1	, &A8AD20LDU},	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
	{ 460	,1	,1	, &B8IS22LDU},	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
	{ 461	,1	,1	, &A8IS12LDU},	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
	{ 462	,1	,1	, &A8AB04LDU},	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
	{ 463	,1	,1	, &A8IS22LDU},	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
	{ 464	,1	,1	, &A8AB08LDU},	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{ 465	,1	,1	, &A8AB09LDU},	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
	{ 466	,1	,1	, &A8AB10LDU},	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
	{ 467	,1	,1	, &A8AB11LDU},	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	{ 468	,1	,1	, &A8AB12LDU},	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
	{ 469	,1	,1	, &A8AB13LDU},	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
	{ 470	,1	,1	, &A8AB14LDU},	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
	{ 471	,1	,1	, &A8AB02LDU},	//( - , DU) Блокировка движения ДС2- АНИ не установлен
	{ 472	,1	,1	, &A6VS22LDU},	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
	{ 473	,1	,1	, &A6VS12LDU},	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
	{ 474	,1	,1	, &B6VS22LDU},	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
	{ 475	,1	,1	, &B6VS12LDU},	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
	{ 476	,1	,1	, &A6AD10LDU},	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
	{ 477	,1	,1	, &A6AD20LDU},	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
	{ 478	,1	,1	, &B6AD10LDU},	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
	{ 479	,1	,1	, &B6AD20LDU},	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
	{ 480	,1	,1	, &A6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ1
	{ 481	,1	,1	, &A6AB01LDU},	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
	{ 482	,1	,1	, &A6AB02LDU},	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
	{ 483	,1	,1	, &B6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ2
	{ 484	,1	,1	, &B6AB01LDU},	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
	{ 485	,1	,1	, &B6AB02LDU},	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
	{ 486	,1	,1	, &A6AB04LDU},	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
	{ 487	,1	,1	, &B6AB04LDU},	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
	{ 488	,1	,1	, &R4AB01LDU},	//( - , DU) Блокировка движения тележки - АНИ не установлен
	{ 489	,1	,1	, &R8IS11LDU},	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
	{ 490	,1	,1	, &R6IS21LDU},	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
	{ 491	,1	,1	, &A0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ1
	{ 492	,1	,1	, &A0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ1
	{ 493	,1	,1	, &R0NE01LDU},	//( - , DU) Потеря связи с БАЗ1
	{ 494	,1	,1	, &R0NE02LDU},	//( - , DU) Потеря связи с БАЗ2
	{ 495	,3	,1	, &R0MW15IP1},	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
	{ 496	,3	,1	, &R0MW14IP1},	//( - , DU) Переключатель ПРОГРАММЫ
	{ 497	,3	,1	, &R0MW12IP1},	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
	{ 498	,3	,1	, &R0MW13IP1},	//( - , DU) Переключатель ВЫБОР ЗОН
	{ 499	,3	,1	, &R0MW16IP1},	//( - , DU) Переключатель ВИД ПРОВЕРКИ
	{ 500	,3	,1	, &R0MW11IP1},	//( - , DU) Переключатель ВЫСТРЕЛ
	{ 501	,3	,1	, &R0MW11IP2},	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
	{ 502	,1	,1	, &R0MW13LP2},	//( - , DU) Переключатель СЕТЬ
	{ 503	,1	,1	, &R0MD32LP1},	//( - , DU) Кнопка СПУСК
	{ 504	,1	,1	, &R0MD31LP1},	//( - , DU) Кнопка СТОП
	{ 505	,1	,1	, &A1IS21LDU},	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
	{ 506	,1	,1	, &A2IS21LDU},	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
	{ 507	,1	,1	, &A3IS21LDU},	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
	{ 508	,1	,1	, &B1IS21LDU},	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
	{ 509	,1	,1	, &B2IS21LDU},	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
	{ 510	,1	,1	, &B3IS21LDU},	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
	{ 511	,1	,1	, &R0ES01LDU},	//( - , DU) ОРР не в исходном состоянии
	{ 512	,1	,1	, &R4MD11LP2},	//( - , DU) Кнопка ВПЕРЁД  (тележки)
	{ 513	,1	,1	, &R4MD31LP2},	//( - , DU) Кнопка СТОП  (тележки)
	{ 514	,1	,1	, &R4MD21LP2},	//( - , DU) Кнопка НАЗАД  (тележки)
	{ 515	,1	,1	, &A6IS11LDU},	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
	{ 516	,1	,1	, &A6IS21LDU},	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
	{ 517	,1	,1	, &B6IS11LDU},	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
	{ 518	,1	,1	, &B6IS21LDU},	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
	{ 519	,1	,1	, &R4AB13LDU},	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
	{ 520	,1	,1	, &R4AB14LDU},	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
	{ 521	,1	,1	, &R4AB15LDU},	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
	{ 522	,1	,1	, &R5IS11LDU},	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
	{ 523	,1	,1	, &R4AB16LDU},	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
	{ 524	,1	,1	, &R4AB17LDU},	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	{ 525	,1	,1	, &R4AB18LDU},	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	{ 526	,1	,1	, &R4AD10LDU},	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
	{ 527	,1	,1	, &R4AD20LDU},	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
	{ 528	,1	,1	, &A5VS22LDU},	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
	{ 529	,1	,1	, &A5VS12LDU},	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
	{ 530	,1	,1	, &B5VS22LDU},	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
	{ 531	,1	,1	, &B5VS12LDU},	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
	{ 532	,1	,1	, &B5AD10LDU},	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
	{ 533	,1	,1	, &B5AD20LDU},	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
	{ 534	,1	,1	, &A5AD10LDU},	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
	{ 535	,1	,1	, &A5AD20LDU},	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
	{ 536	,1	,1	, &A5IS11LDU},	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
	{ 537	,1	,1	, &A5IS21LDU},	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
	{ 538	,1	,1	, &B5IS11LDU},	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
	{ 539	,1	,1	, &B5IS21LDU},	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
	{ 540	,1	,1	, &A5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ1
	{ 541	,1	,1	, &A5AB01LDU},	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
	{ 542	,1	,1	, &A5AB02LDU},	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
	{ 543	,1	,1	, &R4AB02LDU},	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
	{ 544	,1	,1	, &R0NE08LDU},	//( - , DU) Потеря связи с ОПУ
	{ 545	,1	,1	, &R4IS21LDU},	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
	{ 546	,1	,1	, &R4IS22LDU},	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
	{ 547	,1	,1	, &R4IS12LDU},	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
	{ 548	,1	,1	, &R4VS22LDU},	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
	{ 549	,1	,1	, &R4VS12LDU},	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
	{ 550	,1	,1	, &R4AZ03LDU},	//( - , DU) Несанкционированное перемещение тележки
	{ 551	,1	,1	, &R4AB03LDU},	//( - , DU) Блокировка движения тележки - Самоход любого механизма
	{ 552	,1	,1	, &R1IS21LDU},	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
	{ 553	,1	,1	, &R2IS21LDU},	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
	{ 554	,1	,1	, &R4AB04LDU},	//( - , DU) Блокировка движения тележки - Превышение времени движения
	{ 555	,1	,1	, &R4AB05LDU},	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
	{ 556	,1	,1	, &R4AB06LDU},	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
	{ 557	,1	,1	, &R4AB07LDU},	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
	{ 558	,1	,1	, &R4AB08LDU},	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	{ 559	,1	,1	, &R4AB09LDU},	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
	{ 560	,1	,1	, &B0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ2
	{ 561	,1	,1	, &B0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ2
	{ 562	,1	,1	, &R4AB10LDU},	//( - , DU) Блокировка тележки - не открыта биологическая защита
	{ 563	,1	,1	, &R4AB11LDU},	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
	{ 564	,1	,1	, &R4AB12LDU},	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
	{ 565	,1	,1	, &A4IS11LDU},	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
	{ 566	,1	,1	, &B4IS11LDU},	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
	{ 567	,1	,1	, &A3AB05LDU},	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	{ 568	,1	,1	, &A3AB06LDU},	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	{ 569	,1	,1	, &A3AB09LDU},	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
	{ 570	,1	,1	, &A3AB10LDU},	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
	{ 571	,1	,1	, &A3AB11LDU},	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	{ 572	,1	,1	, &A3AB12LDU},	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 573	,1	,1	, &A3AB14LDU},	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	{ 574	,1	,1	, &A3AB16LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
	{ 575	,1	,1	, &A3AB17LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
	{ 576	,1	,1	, &A3AB18LDU},	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	{ 577	,1	,1	, &A3AB20LDU},	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
	{ 578	,1	,1	, &B3VS12LDU},	//( - , DU) Движение ИС2 в сторону ВУ
	{ 579	,1	,1	, &B3AB04LDU},	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
	{ 580	,1	,1	, &B3AB02LDU},	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
	{ 581	,1	,1	, &B3AB01LDU},	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
	{ 582	,1	,1	, &B3VS22LDU},	//( - , DU) Движение ИС2 в сторону НУ
	{ 583	,1	,1	, &B3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
	{ 584	,1	,1	, &B3AD11LDU},	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
	{ 585	,1	,1	, &B3AD21LDU},	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
	{ 586	,1	,1	, &B3AD02LDU},	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
	{ 587	,1	,1	, &B3AD03LDU},	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
	{ 588	,1	,1	, &B3AD04LDU},	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
	{ 589	,1	,1	, &B3AD05LDU},	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
	{ 590	,1	,1	, &B1AB11LDU},	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{ 591	,1	,1	, &B1AB12LDU},	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 592	,1	,1	, &B1AB13LDU},	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
	{ 593	,1	,1	, &B1AB14LDU},	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{ 594	,1	,1	, &B1AB16LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
	{ 595	,1	,1	, &B1AB17LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{ 596	,1	,1	, &B1AB18LDU},	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{ 597	,1	,1	, &A3VS12LDU},	//( - , DU) Движение ИС1 в сторону ВУ
	{ 598	,8	,1	, &A3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС1
	{ 599	,1	,1	, &A3AB04LDU},	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
	{ 600	,1	,1	, &A3AB02LDU},	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
	{ 601	,1	,1	, &A3AB01LDU},	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
	{ 602	,1	,1	, &A3VS22LDU},	//( - , DU) Движение ИС1 в сторону НУ
	{ 603	,1	,1	, &A3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
	{ 604	,1	,1	, &A3AD11LDU},	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
	{ 605	,1	,1	, &A3AD21LDU},	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
	{ 606	,1	,1	, &A3AD02LDU},	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
	{ 607	,1	,1	, &A3AD03LDU},	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
	{ 608	,1	,1	, &A3AD04LDU},	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
	{ 609	,1	,1	, &A3AD05LDU},	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
	{ 610	,1	,1	, &A3AD01LDU},	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
	{ 611	,8	,1	, &A3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС1
	{ 612	,1	,1	, &A3AB07LDU},	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	{ 613	,1	,1	, &A3AB08LDU},	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	{ 614	,1	,1	, &B1AD32LDU},	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
	{ 615	,1	,1	, &R0MD11LP2},	//( - , DU) Кнопка Пуск проверки схем сброса
	{ 616	,1	,1	, &R0VX01LDU},	//( - , DU) ДО ИМПУЛЬСА
	{ 617	,3	,1	, &R0VL01IDU},	//( - , DU) До импульса минут
	{ 618	,3	,1	, &R0VL11IDU},	//( - , DU) До импульса секунд
	{ 619	,8	,1	, &R0VL06RDU},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	{ 620	,1	,1	, &B3AD33LDU},	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
	{ 621	,8	,1	, &R0VL02RDU},	//( - , DU) Индикация (Время задержки ИНИ)
	{ 622	,8	,1	, &R0VL04RDU},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	{ 623	,1	,1	, &R0AB04LDU},	//( - , DU) Нарушение времени срабатывания верхней АС II УР
	{ 624	,1	,1	, &R0AB06LDU},	//( - , DU) Нарушение времени задержки от ВУ РБ
	{ 625	,1	,1	, &R0AB02LDU},	//( - , DU) Нарушение времени задержки ИНИ
	{ 626	,8	,1	, &R0VL03RDU},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{ 627	,8	,1	, &R0VL05RDU},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	{ 628	,3	,1	, &R0VL21IDU},	//( - , DU) Декатрон
	{ 629	,1	,1	, &R0VX03LDU},	//( - , DU) Готовность 2 мин
	{ 630	,3	,1	, &R0VS21IDU},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	{ 631	,3	,1	, &A1VS01IDU},	//( - , DU) Готовность к управлению ББ1
	{ 632	,3	,1	, &B1VS01IDU},	//( - , DU) Готовность к управлению ББ2
	{ 633	,3	,1	, &A3VS01IDU},	//( - , DU) Готовность к управлению ИС1
	{ 634	,3	,1	, &B3VS01IDU},	//( - , DU) Готовность к управлению ИС2
	{ 635	,3	,1	, &A2VS01IDU},	//( - , DU) Готовность к управлению РБ1
	{ 636	,3	,1	, &A4VS01IDU},	//( - , DU) Готовность к управлению НИ1
	{ 637	,1	,1	, &B3AD01LDU},	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
	{ 638	,8	,1	, &B3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС2
	{ 639	,1	,1	, &B3AB07LDU},	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	{ 640	,1	,1	, &B3AB08LDU},	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	{ 641	,1	,1	, &B3AB05LDU},	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	{ 642	,1	,1	, &B3AB06LDU},	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	{ 643	,1	,1	, &B3AB09LDU},	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
	{ 644	,1	,1	, &B3AB10LDU},	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
	{ 645	,1	,1	, &B3AB11LDU},	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	{ 646	,1	,1	, &B3AB12LDU},	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 647	,1	,1	, &B3AB14LDU},	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	{ 648	,1	,1	, &B3AB16LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
	{ 649	,1	,1	, &B3AB17LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
	{ 650	,1	,1	, &B3AB18LDU},	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	{ 651	,1	,1	, &B3AB20LDU},	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
	{ 652	,1	,1	, &C1MD31LP1},	//( - , DU) Кнопка СБРОС ББ
	{ 653	,1	,1	, &C1MD31LP2},	//( - , DU) Кнопка СБРОС ББ
	{ 654	,1	,1	, &A2AD31LDU},	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
	{ 655	,1	,1	, &B2AD31LDU},	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
	{ 656	,1	,1	, &A1AD31LDU},	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
	{ 657	,1	,1	, &B1AD31LDU},	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
	{ 658	,1	,1	, &A2AD32LDU},	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
	{ 659	,1	,1	, &B2AD32LDU},	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
	{ 660	,1	,1	, &A1AD32LDU},	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
	{ 661	,1	,1	, &B2AB11LDU},	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{ 662	,1	,1	, &B2AB12LDU},	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 663	,1	,1	, &B2AB13LDU},	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
	{ 664	,1	,1	, &B2AB14LDU},	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{ 665	,1	,1	, &B2AB16LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
	{ 666	,1	,1	, &B2AB17LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{ 667	,1	,1	, &R1AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ1
	{ 668	,1	,1	, &R1AB01LDU},	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
	{ 669	,1	,1	, &R1AB02LDU},	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
	{ 670	,1	,1	, &R2AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ2
	{ 671	,1	,1	, &R2AB01LDU},	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
	{ 672	,1	,1	, &R2AB02LDU},	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
	{ 673	,1	,1	, &R1AB04LDU},	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
	{ 674	,1	,1	, &R2AB04LDU},	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
	{ 675	,1	,1	, &R1AD10LDU},	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
	{ 676	,1	,1	, &R1AD20LDU},	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
	{ 677	,1	,1	, &R1IS11LDU},	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
	{ 678	,1	,1	, &R1VS22LDU},	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
	{ 679	,1	,1	, &R2VS22LDU},	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
	{ 680	,1	,1	, &R2VS12LDU},	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
	{ 681	,1	,1	, &R1VS12LDU},	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
	{ 682	,1	,1	, &R2IS11LDU},	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
	{ 683	,1	,1	, &A1VS12LDU},	//( - , DU) Движение ББ1 в сторону ВУ
	{ 684	,1	,1	, &A2AB14LDU},	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	{ 685	,1	,1	, &A2AB16LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
	{ 686	,1	,1	, &A2AB17LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{ 687	,1	,1	, &A2AD01LDU},	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
	{ 688	,8	,1	, &A2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ1
	{ 689	,8	,1	, &B2CV01RDU},	//( - , DU) Измеренная скорость перемещения РБ2
	{ 690	,1	,1	, &B2AB04LDU},	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
	{ 691	,1	,1	, &B2AB02LDU},	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
	{ 692	,1	,1	, &B2AB01LDU},	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
	{ 693	,1	,1	, &B2AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
	{ 694	,1	,1	, &B2AD11LDU},	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
	{ 695	,1	,1	, &B2AD21LDU},	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
	{ 696	,1	,1	, &B2AD02LDU},	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
	{ 697	,1	,1	, &B2AD03LDU},	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
	{ 698	,1	,1	, &B2AD04LDU},	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
	{ 699	,1	,1	, &B2AD05LDU},	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
	{ 700	,1	,1	, &B2AD01LDU},	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
	{ 701	,8	,1	, &B2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ2
	{ 702	,1	,1	, &B2AB07LDU},	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	{ 703	,1	,1	, &B2AB08LDU},	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{ 704	,1	,1	, &B2AB05LDU},	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{ 705	,1	,1	, &B2AB06LDU},	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{ 706	,1	,1	, &B2AB09LDU},	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
	{ 707	,1	,1	, &B2AB10LDU},	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{ 708	,1	,1	, &A1AB16LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
	{ 709	,1	,1	, &A1AB17LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
	{ 710	,1	,1	, &A1AB18LDU},	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	{ 711	,1	,1	, &B1VS12LDU},	//( - , DU) Движение ББ2 в сторону ВУ
	{ 712	,8	,1	, &B1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ2
	{ 713	,1	,1	, &B1AB04LDU},	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
	{ 714	,1	,1	, &B1AB02LDU},	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
	{ 715	,1	,1	, &B1AB01LDU},	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
	{ 716	,1	,1	, &B1VS22LDU},	//( - , DU) Движение ББ2 в сторону НУ
	{ 717	,1	,1	, &B1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
	{ 718	,1	,1	, &B1AD11LDU},	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
	{ 719	,1	,1	, &B1AD21LDU},	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
	{ 720	,1	,1	, &B1AD02LDU},	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
	{ 721	,1	,1	, &B1AD03LDU},	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
	{ 722	,1	,1	, &B1AD04LDU},	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
	{ 723	,1	,1	, &B1AD05LDU},	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
	{ 724	,1	,1	, &B1AD01LDU},	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
	{ 725	,8	,1	, &B1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ2
	{ 726	,1	,1	, &B1AB07LDU},	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{ 727	,1	,1	, &B1AB08LDU},	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{ 728	,1	,1	, &B1AB05LDU},	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{ 729	,1	,1	, &B1AB06LDU},	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{ 730	,1	,1	, &B1AB09LDU},	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
	{ 731	,1	,1	, &B1AB10LDU},	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{ 732	,8	,1	, &A1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ1
	{ 733	,1	,1	, &A1AB04LDU},	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
	{ 734	,1	,1	, &A1AB02LDU},	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
	{ 735	,1	,1	, &A1AB01LDU},	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
	{ 736	,1	,1	, &A1VS22LDU},	//( - , DU) Движение ББ1 в сторону НУ
	{ 737	,1	,1	, &A1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
	{ 738	,1	,1	, &A1AD11LDU},	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
	{ 739	,1	,1	, &A1AD21LDU},	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
	{ 740	,1	,1	, &A1AD02LDU},	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
	{ 741	,1	,1	, &A1AD03LDU},	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
	{ 742	,1	,1	, &A1AD04LDU},	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
	{ 743	,1	,1	, &A1AD05LDU},	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
	{ 744	,1	,1	, &A1AD01LDU},	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
	{ 745	,8	,1	, &A1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ1
	{ 746	,1	,1	, &A1AB07LDU},	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	{ 747	,1	,1	, &A1AB08LDU},	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	{ 748	,1	,1	, &A1AB05LDU},	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	{ 749	,1	,1	, &A1AB06LDU},	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{ 750	,1	,1	, &A1AB09LDU},	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
	{ 751	,1	,1	, &A1AB10LDU},	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
	{ 752	,1	,1	, &A1AB11LDU},	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	{ 753	,1	,1	, &A1AB12LDU},	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 754	,1	,1	, &A1AB13LDU},	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
	{ 755	,1	,1	, &A1AB14LDU},	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	{ 756	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
	{ 757	,5	,1	, &dEM_A1UC05UDU},	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
	{ 758	,5	,1	, &dEM_A1UC06UDU},	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
	{ 759	,5	,1	, &dEM_A2UC06UDU},	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
	{ 760	,5	,1	, &dEM_A2UC05UDU},	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
	{ 761	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
	{ 762	,5	,1	, &dEM_A3UC06UDU},	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
	{ 763	,5	,1	, &dEM_A3UC05UDU},	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
	{ 764	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
	{ 765	,5	,1	, &dEM_A8UC06UDU},	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
	{ 766	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
	{ 767	,5	,1	, &dEM_A8UC05UDU},	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
	{ 768	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 769	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 2-я частота двигателя (шагов/секунду)
	{ 770	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 3-я частота двигателя (шагов/секунду)
	{ 771	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 4-я частота двигателя (шагов/секунду)
	{ 772	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 773	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 774	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 8-я скорость перемещения ББ (шагов/секунду)
	{ 775	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 776	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 777	,8	,1	, &fEM_A3UP43RDU},	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
	{ 778	,8	,1	, &fEM_A3UP44RDU},	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
	{ 779	,8	,1	, &fEM_A3UP53RDU},	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
	{ 780	,8	,1	, &fEM_A3UP85RDU},	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 781	,8	,1	, &fEM_A3UP88RDU},	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 782	,8	,1	, &fEM_A3UP86RDU},	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 783	,8	,1	, &fEM_B8UV01RDU},	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
	{ 784	,8	,1	, &fEM_B8UV02RDU},	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
	{ 785	,8	,1	, &fEM_B8UV03RDU},	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
	{ 786	,8	,1	, &fEM_B8UL04RDU},	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
	{ 787	,3	,1	, &iEM_A2UV03CDU},	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
	{ 788	,8	,1	, &fEM_A2UV01RDU},	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
	{ 789	,8	,1	, &fEM_A2UV02RDU},	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
	{ 790	,8	,1	, &fEM_A1UV01RDU},	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
	{ 791	,8	,1	, &fEM_A1UV02RDU},	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
	{ 792	,8	,1	, &fEM_A1UC06RDU},	//(A1UC06RDU) Уставка определения самохода ББ  мм
	{ 793	,8	,1	, &fEM_A1UC05RDU},	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
	{ 794	,8	,1	, &fEM_A1UL04RDU},	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
	{ 795	,8	,1	, &fEM_A3UV01RDU},	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
	{ 796	,8	,1	, &fEM_A3UV02RDU},	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
	{ 797	,8	,1	, &fEM_A3UC06RDU},	//(A3UC06RDU) Уставка определения самохода ИС1  мм
	{ 798	,8	,1	, &fEM_A3UC05RDU},	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
	{ 799	,8	,1	, &fEM_A3UL04RDU},	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
	{ 800	,8	,1	, &fEM_A3UP54RDU},	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
	{ 801	,8	,1	, &fEM_A3UP87RDU},	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 802	,8	,1	, &fEM_R0UL05RDU},	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
	{ 803	,8	,1	, &fEM_R0UL20RDU},	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
	{ 804	,8	,1	, &fEM_B8UV04RDU},	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
	{ 805	,8	,1	, &fEM_B8UC06RDU},	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
	{ 806	,8	,1	, &fEM_B8UC05RDU},	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
	{ 807	,8	,1	, &fEM_A2UL05RDU},	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
	{ 808	,8	,1	, &fEM_A2UL03RDU},	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 809	,8	,1	, &fEM_A2UC06RDU},	//(A2UC06RDU) Уставка определения самохода РБ  мм
	{ 810	,8	,1	, &fEM_A2UC05RDU},	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
	{ 811	,8	,1	, &fEM_A2UL04RDU},	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
	{ 812	,8	,1	, &fEM_A1UL03RDU},	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
	{ 813	,8	,1	, &fEM_A1UL05RDU},	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
	{ 814	,8	,1	, &fEM_A3UL03RDU},	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
	{ 815	,8	,1	, &fEM_A3UL05RDU},	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
	{ 816	,8	,1	, &fEM_A1UC08RDU},	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
	{ 817	,8	,1	, &fEM_A3UC08RDU},	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
	{ 818	,8	,1	, &fEM_A1UC07RDU},	//(A1UC07RDU) Зона возврата при наведении ББ мм
	{ 819	,8	,1	, &fEM_A1UL01RDU},	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 820	,8	,1	, &fEM_A3UC07RDU},	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
	{ 821	,8	,1	, &fEM_A3UL01RDU},	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 822	,8	,1	, &fEM_A2UC08RDU},	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
	{ 823	,8	,1	, &fEM_A2UC07RDU},	//(A2UC07RDU) Зона возврата при наведении РБ  мм
	{ 824	,8	,1	, &fEM_A2UL01RDU},	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 825	,8	,1	, &fEM_B8UC01RDU},	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
	{ 826	,8	,1	, &fEM_B8UL07RDU},	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
	{ 827	,8	,1	, &fEM_B8UC02RDU},	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
	{ 828	,8	,1	, &fEM_B8UL01RDU},	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 829	,8	,1	, &fEM_B8UL05RDU},	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
	{ 830	,8	,1	, &fEM_B8UL03RDU},	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
	{ 831	,8	,1	, &fEM_B8UL06RDU},	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
	{ 832	,8	,1	, &fEM_A9UZ03RDU},	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
	{ 833	,8	,1	, &fEM_A9UZ04RDU},	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
	{ 834	,8	,1	, &fEM_A9UZ05RDU},	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
	{ 835	,8	,1	, &fEM_R4UZ04RDU},	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
	{ 836	,8	,1	, &fEM_R4UZ03RDU},	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
	{ 837	,8	,1	, &fEM_R4UZ05RDU},	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
	{ 838	,8	,1	, &fEM_A5UZ03RDU},	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
	{ 839	,8	,1	, &fEM_A5UZ04RDU},	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
	{ 840	,8	,1	, &fEM_A5UZ05RDU},	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
	{ 841	,8	,1	, &fEM_A4UZ03RDU},	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
	{ 842	,8	,1	, &fEM_A4UZ04RDU},	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
	{ 843	,8	,1	, &fEM_A4UZ05RDU},	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
	{ 844	,8	,1	, &fEM_A6UZ03RDU},	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
	{ 845	,8	,1	, &fEM_A6UZ04RDU},	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
	{ 846	,8	,1	, &fEM_A6UZ05RDU},	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
	{ 847	,8	,1	, &fEM_R1UZ03RDU},	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
	{ 848	,8	,1	, &fEM_R1UZ04RDU},	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
	{ 849	,8	,1	, &fEM_R1UZ05RDU},	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
	{ 850	,8	,1	, &fEM_R0UL04RDU},	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
	{ 851	,8	,1	, &fEM_R0UL06RDU},	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
	{ 852	,8	,1	, &fEM_R0UL03RDU},	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
	{ 853	,8	,1	, &fEM_R0UL17RDU},	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
	{ 854	,8	,1	, &fEM_R0UL19RDU},	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 855	,8	,1	, &fEM_R0UL07RDU},	//(R0UL07RDU) Время срабатывания верхней АС II УР
	{ 856	,8	,1	, &fEM_R0UL18RDU},	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
	{ 857	,8	,1	, &fEM_R0UL16RDU},	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
	{ 858	,8	,1	, &fEM_R0UL02RDU},	//(R0UL02RDU) Время задержки  ИНИ
	{ 859	,8	,1	, &fEM_R0UN08RDU},	//(R0UN08RDU) 8-я заданная мощность
	{ 860	,8	,1	, &fEM_R0UN07RDU},	//(R0UN07RDU) 7-я заданная мощность
	{ 861	,8	,1	, &fEM_R0UN06RDU},	//(R0UN06RDU) 6-я заданная мощность
	{ 862	,8	,1	, &fEM_R0UN05RDU},	//(R0UN05RDU) 5-я заданная мощность
	{ 863	,8	,1	, &fEM_R0UN04RDU},	//(R0UN04RDU) 4-я заданная мощность
	{ 864	,8	,1	, &fEM_R0UN03RDU},	//(R0UN03RDU) Ограничение 3 по мощности
	{ 865	,8	,1	, &fEM_R0UN02RDU},	//(R0UN02RDU) 2-я заданная мощность
	{ 866	,8	,1	, &fEM_R0UN01RDU},	//(R0UN01RDU) 1-я заданная мощность
	{ 867	,8	,1	, &fEM_A2UC82RDU},	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
	{ 868	,8	,1	, &fEM_A2UC83RDU},	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
	{ 869	,8	,1	, &fEM_A1UC83RDU},	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
	{ 870	,8	,1	, &fEM_A2UC81RDU},	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
	{ 871	,8	,1	, &fEM_A1UC81RDU},	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
	{ 872	,8	,1	, &fEM_A1UC82RDU},	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
	{ 873	,8	,1	, &fEM_A2UL83RDU},	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 874	,8	,1	, &fEM_A3UC81RDU},	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
	{ 875	,8	,1	, &fEM_A3UC82RDU},	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
	{ 876	,8	,1	, &fEM_R0UN80RDU},	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
	{ 877	,3	,1	, &iEM_A2UV01IDU},	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
	{ 878	,3	,1	, &iEM_A2UV02IDU},	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
	{ 879	,3	,1	, &iEM_A1UV01IDU},	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
	{ 880	,3	,1	, &iEM_A1UV02IDU},	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
	{ 881	,3	,1	, &iEM_A1UV03IDU},	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
	{ 882	,3	,1	, &iEM_A3UV01IDU},	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
	{ 883	,3	,1	, &iEM_A3UV02IDU},	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
	{ 884	,1	,1	, &lEM_R0MD01LC1},	//(R0MD01LC1) Ручное управление ОРР
	{ 885	,8	,1	, &fEM_A3UC09RDU},	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
	{ 886	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
	{ 887	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
	{ 888	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
	{ 889	,8	,1	, &fEM_R0UL21RDU},	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
	{ 890	,8	,1	, &fEM_R0UN09RDU},	//(R0UN09RDU) Минимальный период при регулировании мощности
	{ 891	,8	,1	, &fEM_R0UN11RDU},	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
	{ 892	,8	,1	, &fEM_R0UN12RDU},	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
	{ 893	,8	,1	, &fEM_R0UN13RDU},	//(R0UN13RDU) Минимальное изменение координаты, мм
	{ 894	,8	,1	, &fEM_R0UN14RDU},	//(R0UN14RDU) Максимальная координата штока ИМ, мм
	{ 895	,8	,1	, &fEM_R0UN16RDU},	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
	{ 896	,8	,1	, &fEM_R0UN17RDU},	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
	{ 897	,8	,1	, &fEM_R0UN18RDU},	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
	{ 898	,8	,1	, &fEM_R0UN19RDU},	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
	{ 899	,8	,1	, &fEM_R0UN70LDU},	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
	{ 900	,8	,1	, &fEM_R0UN71LDU},	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
	{ 901	,8	,1	, &fEM_R0UN72LDU},	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
	{ 902	,8	,1	, &fEM_R0UN73LDU},	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
	{ 903	,8	,1	, &fEM_R0UN74LDU},	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
	{ 904	,8	,1	, &fEM_R0UN75LDU},	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
	{ 905	,8	,1	, &fEM_R0UN80LDU},	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
	{ 906	,8	,1	, &fEM_R0UN81LDU},	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
	{ 907	,8	,1	, &fEM_R0UN82LDU},	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
	{ 908	,8	,1	, &fEM_R0UN83LDU},	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
	{ 909	,8	,1	, &fEM_R0UN84LDU},	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
	{ 910	,8	,1	, &fEM_R0UN85LDU},	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
	{ 911	,8	,1	, &fEM_R0UT20RDU},	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
	{ 912	,8	,1	, &fEM_R0UN25RDU},	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
	{ 913	,8	,1	, &fEM_R0UN15RDU},	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
	{ 914	,8	,1	, &fEM_R0UN26RDU},	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 915	,8	,1	, &fEM_R0UN27RDU},	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 916	,8	,1	, &fEM_R0UN24RDU},	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 917	,8	,1	, &fEM_R0UL25RDU},	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 918	,8	,1	, &fEM_R0UL01RSS},	//(R0UL01RSS) Шаг измерения периода (сек)
	{ 919	,8	,1	, &fEM_R0UL02RSS},	//(R0UL02RSS) Tф-постоянная времени, с
	{ 920	,8	,1	, &fEM_R0UN03RSS},	//(R0UN03RSS) нижняя граница интервала мощности для измерения периода (ватт)
	{ 921	,8	,1	, &fEM_R7UI76RDU},	//(R7UI76RDU) Время срабатывания сигнала II УР при имитации
	{ 922	,8	,1	, &fEM_R0UL00RDU},	//(R0UL00RDU) Время ожидания передачи  сигнала отключения сети
	{ 923	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 924	,8	,1	, &internal2_m182_tx},	//(internal2_m182_tx) tx - время накопленное сек
	{ 925	,18	,1	, &internal2_m182_y0},	//(internal2_m182_y0) y0
	{ 926	,8	,1	, &internal2_m176_tx},	//(internal2_m176_tx) tx - время накопленное сек
	{ 927	,18	,1	, &internal2_m176_y0},	//(internal2_m176_y0) y0
	{ 928	,8	,1	, &internal2_m173_tx},	//(internal2_m173_tx) tx - время накопленное сек
	{ 929	,18	,1	, &internal2_m173_y0},	//(internal2_m173_y0) y0
	{ 930	,8	,1	, &internal2_m165_tx},	//(internal2_m165_tx) tx - время накопленное сек
	{ 931	,18	,1	, &internal2_m165_y0},	//(internal2_m165_y0) y0
	{ 932	,8	,1	, &internal2_m158_tx},	//(internal2_m158_tx) tx - время накопленное сек
	{ 933	,18	,1	, &internal2_m158_y0},	//(internal2_m158_y0) y0
	{ 934	,8	,1	, &internal2_m155_tx},	//(internal2_m155_tx) tx - время накопленное сек
	{ 935	,18	,1	, &internal2_m155_y0},	//(internal2_m155_y0) y0
	{ 936	,8	,1	, &internal2_m149_tx},	//(internal2_m149_tx) tx - время накопленное сек
	{ 937	,18	,1	, &internal2_m149_y0},	//(internal2_m149_y0) y0
	{ 938	,8	,1	, &internal2_m144_tx},	//(internal2_m144_tx) tx - время накопленное сек
	{ 939	,18	,1	, &internal2_m144_y0},	//(internal2_m144_y0) y0
	{ 940	,8	,1	, &internal2_m141_tx},	//(internal2_m141_tx) tx - время накопленное сек
	{ 941	,18	,1	, &internal2_m141_y0},	//(internal2_m141_y0) y0
	{ 942	,8	,1	, &internal2_m134_tx},	//(internal2_m134_tx) tx - время накопленное сек
	{ 943	,18	,1	, &internal2_m134_y0},	//(internal2_m134_y0) y0
	{ 944	,8	,1	, &internal2_m132_tx},	//(internal2_m132_tx) tx - время накопленное сек
	{ 945	,18	,1	, &internal2_m132_y0},	//(internal2_m132_y0) y0
	{ 946	,8	,1	, &internal2_m127_tx},	//(internal2_m127_tx) tx - время накопленное сек
	{ 947	,18	,1	, &internal2_m127_y0},	//(internal2_m127_y0) y0
	{ 948	,8	,1	, &internal2_m195_y0},	//(internal2_m195_y0) y0
	{ 949	,8	,1	, &internal2_m193_y0},	//(internal2_m193_y0) y0
	{ 950	,1	,1	, &internal2_m228_y0},	//(internal2_m228_y0) state
	{ 951	,1	,1	, &internal2_m220_y0},	//(internal2_m220_y0) state
	{ 952	,1	,1	, &internal2_m208_y1},	//(internal2_m208_y1) y1 - внутренний параметр
	{ 953	,1	,1	, &internal2_m214_y1},	//(internal2_m214_y1) y1 - внутренний параметр
	{ 954	,1	,1	, &internal2_m198_y1},	//(internal2_m198_y1) y1 - внутренний параметр
	{ 955	,1	,1	, &internal2_m205_y1},	//(internal2_m205_y1) y1 - внутренний параметр
	{ 956	,5	,1	, &internal2_m17_Nk0},	//(internal2_m17_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 957	,1	,1	, &internal2_m17_SetFlag},	//(internal2_m17_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 958	,5	,1	, &internal2_m110_Nk0},	//(internal2_m110_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 959	,1	,1	, &internal2_m110_SetFlag},	//(internal2_m110_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 960	,5	,1	, &internal2_m106_Nk0},	//(internal2_m106_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 961	,1	,1	, &internal2_m106_SetFlag},	//(internal2_m106_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 962	,5	,1	, &internal2_m75_Nk0},	//(internal2_m75_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 963	,1	,1	, &internal2_m75_SetFlag},	//(internal2_m75_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 964	,5	,1	, &internal2_m77_Nk0},	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 965	,1	,1	, &internal2_m77_SetFlag},	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 966	,5	,1	, &internal2_m49_Nk0},	//(internal2_m49_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 967	,1	,1	, &internal2_m49_SetFlag},	//(internal2_m49_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 968	,5	,1	, &internal2_m53_Nk0},	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 969	,1	,1	, &internal2_m53_SetFlag},	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 970	,5	,1	, &internal2_m15_Nk0},	//(internal2_m15_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 971	,1	,1	, &internal2_m15_SetFlag},	//(internal2_m15_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 972	,8	,1	, &internal1_m2562_tx},	//(internal1_m2562_tx) tx - время накопленное сек
	{ 973	,18	,1	, &internal1_m2562_y0},	//(internal1_m2562_y0) y0
	{ 974	,8	,1	, &internal1_m2560_tx},	//(internal1_m2560_tx) tx - время накопленное сек
	{ 975	,18	,1	, &internal1_m2560_y0},	//(internal1_m2560_y0) y0
	{ 976	,8	,1	, &internal1_m2558_tx},	//(internal1_m2558_tx) tx - время накопленное сек
	{ 977	,18	,1	, &internal1_m2558_y0},	//(internal1_m2558_y0) y0
	{ 978	,8	,1	, &internal1_m2554_tx},	//(internal1_m2554_tx) tx - время накопленное сек
	{ 979	,18	,1	, &internal1_m2554_y0},	//(internal1_m2554_y0) y0
	{ 980	,8	,1	, &internal1_m2552_tx},	//(internal1_m2552_tx) tx - время накопленное сек
	{ 981	,18	,1	, &internal1_m2552_y0},	//(internal1_m2552_y0) y0
	{ 982	,8	,1	, &internal1_m2556_tx},	//(internal1_m2556_tx) tx - время накопленное сек
	{ 983	,18	,1	, &internal1_m2556_y0},	//(internal1_m2556_y0) y0
	{ 984	,8	,1	, &internal1_m2550_tx},	//(internal1_m2550_tx) tx - время накопленное сек
	{ 985	,18	,1	, &internal1_m2550_y0},	//(internal1_m2550_y0) y0
	{ 986	,8	,1	, &internal1_m2548_tx},	//(internal1_m2548_tx) tx - время накопленное сек
	{ 987	,18	,1	, &internal1_m2548_y0},	//(internal1_m2548_y0) y0
	{ 988	,8	,1	, &internal1_m2582_tx},	//(internal1_m2582_tx) tx - время накопленное сек
	{ 989	,18	,1	, &internal1_m2582_y0},	//(internal1_m2582_y0) y0
	{ 990	,8	,1	, &internal1_m2590_tx},	//(internal1_m2590_tx) tx - время накопленное сек
	{ 991	,18	,1	, &internal1_m2590_y0},	//(internal1_m2590_y0) y0
	{ 992	,8	,1	, &internal1_m2588_tx},	//(internal1_m2588_tx) tx - время накопленное сек
	{ 993	,18	,1	, &internal1_m2588_y0},	//(internal1_m2588_y0) y0
	{ 994	,8	,1	, &internal1_m2586_tx},	//(internal1_m2586_tx) tx - время накопленное сек
	{ 995	,18	,1	, &internal1_m2586_y0},	//(internal1_m2586_y0) y0
	{ 996	,8	,1	, &internal1_m2584_tx},	//(internal1_m2584_tx) tx - время накопленное сек
	{ 997	,18	,1	, &internal1_m2584_y0},	//(internal1_m2584_y0) y0
	{ 998	,8	,1	, &internal1_m2580_tx},	//(internal1_m2580_tx) tx - время накопленное сек
	{ 999	,18	,1	, &internal1_m2580_y0},	//(internal1_m2580_y0) y0
	{ 1000	,8	,1	, &internal1_m2578_tx},	//(internal1_m2578_tx) tx - время накопленное сек
	{ 1001	,18	,1	, &internal1_m2578_y0},	//(internal1_m2578_y0) y0
	{ 1002	,8	,1	, &internal1_m2576_tx},	//(internal1_m2576_tx) tx - время накопленное сек
	{ 1003	,18	,1	, &internal1_m2576_y0},	//(internal1_m2576_y0) y0
	{ 1004	,8	,1	, &internal1_m2574_tx},	//(internal1_m2574_tx) tx - время накопленное сек
	{ 1005	,18	,1	, &internal1_m2574_y0},	//(internal1_m2574_y0) y0
	{ 1006	,8	,1	, &internal1_m2572_tx},	//(internal1_m2572_tx) tx - время накопленное сек
	{ 1007	,18	,1	, &internal1_m2572_y0},	//(internal1_m2572_y0) y0
	{ 1008	,8	,1	, &internal1_m2570_tx},	//(internal1_m2570_tx) tx - время накопленное сек
	{ 1009	,18	,1	, &internal1_m2570_y0},	//(internal1_m2570_y0) y0
	{ 1010	,8	,1	, &internal1_m2568_tx},	//(internal1_m2568_tx) tx - время накопленное сек
	{ 1011	,18	,1	, &internal1_m2568_y0},	//(internal1_m2568_y0) y0
	{ 1012	,8	,1	, &internal1_m2566_tx},	//(internal1_m2566_tx) tx - время накопленное сек
	{ 1013	,18	,1	, &internal1_m2566_y0},	//(internal1_m2566_y0) y0
	{ 1014	,8	,1	, &internal1_m2564_tx},	//(internal1_m2564_tx) tx - время накопленное сек
	{ 1015	,18	,1	, &internal1_m2564_y0},	//(internal1_m2564_y0) y0
	{ 1016	,1	,1	, &internal1_m2097_x0},	//(internal1_m2097_x0) - значение входного параметра на предыдущем шаге
	{ 1017	,8	,1	, &internal1_m2097_tim},	//(internal1_m2097_tim) - время задержки выходного сигнала
	{ 1018	,8	,1	, &internal1_m1673_tx},	//(internal1_m1673_tx) tx - время накопленное сек
	{ 1019	,18	,1	, &internal1_m1673_y0},	//(internal1_m1673_y0) y0
	{ 1020	,3	,1	, &internal1_m79_flst},	//(internal1_m79_flst)  флаг старта измерения
	{ 1021	,3	,1	, &internal1_m79_chsr},	//(internal1_m79_chsr)  счетчик усреднения
	{ 1022	,3	,1	, &internal1_m79_chizm},	//(internal1_m79_chizm)  счетчик уменьшения мощности
	{ 1023	,8	,1	, &internal1_m79_sumtim},	//(internal1_m79_sumtim)  время измерения мощности
	{ 1024	,8	,1	, &internal1_m79_W1},	//(internal1_m79_W1)  мощность на старте измерения
	{ 1025	,8	,1	, &internal1_m79_W2},	//(internal1_m79_W2)  мощность в конце измерения
	{ 1026	,8	,1	, &internal1_m79_Wmin},	//(internal1_m79_Wmin)  минимальное измерение в серии
	{ 1027	,8	,1	, &internal1_m79_Wmax},	//(internal1_m79_Wmax)  максимальное измерение в серии
	{ 1028	,8	,1	, &internal1_m79_Wlast},	//(internal1_m79_Wlast)  последнее растущее измерение
	{ 1029	,8	,1	, &internal1_m79_y0},	//(internal1_m79_y0) y0 - внутренний параметр
	{ 1030	,1	,1	, &internal1_m79_MyFirstEnterFlag},	//(internal1_m79_MyFirstEnterFlag)  FirstEnterFlag
	{ 1031	,8	,1	, &internal1_m2062_tx},	//(internal1_m2062_tx) tx - внутренний параметр
	{ 1032	,8	,1	, &internal1_m2061_tx},	//(internal1_m2061_tx) tx - внутренний параметр
	{ 1033	,8	,1	, &internal1_m781_tx},	//(internal1_m781_tx) tx - внутренний параметр
	{ 1034	,8	,1	, &internal1_m738_tx},	//(internal1_m738_tx) tx - внутренний параметр
	{ 1035	,8	,1	, &internal1_m795_tx},	//(internal1_m795_tx) tx - внутренний параметр
	{ 1036	,8	,1	, &internal1_m792_tx},	//(internal1_m792_tx) tx - внутренний параметр
	{ 1037	,8	,1	, &internal1_m791_tx},	//(internal1_m791_tx) tx - внутренний параметр
	{ 1038	,8	,1	, &internal1_m748_tx},	//(internal1_m748_tx) tx - внутренний параметр
	{ 1039	,8	,1	, &internal1_m731_tx},	//(internal1_m731_tx) tx - внутренний параметр
	{ 1040	,8	,1	, &internal1_m742_tx},	//(internal1_m742_tx) tx - внутренний параметр
	{ 1041	,8	,1	, &internal1_m773_tx},	//(internal1_m773_tx) tx - внутренний параметр
	{ 1042	,8	,1	, &internal1_m790_tx},	//(internal1_m790_tx) tx - внутренний параметр
	{ 1043	,8	,1	, &internal1_m763_tx},	//(internal1_m763_tx) tx - внутренний параметр
	{ 1044	,8	,1	, &internal1_m394_tx},	//(internal1_m394_tx) tx - внутренний параметр
	{ 1045	,8	,1	, &internal1_m393_tx},	//(internal1_m393_tx) tx - внутренний параметр
	{ 1046	,8	,1	, &internal1_m392_tx},	//(internal1_m392_tx) tx - внутренний параметр
	{ 1047	,8	,1	, &internal1_m391_tx},	//(internal1_m391_tx) tx - внутренний параметр
	{ 1048	,8	,1	, &internal1_m762_tx},	//(internal1_m762_tx) tx - внутренний параметр
	{ 1049	,8	,1	, &internal1_m757_tx},	//(internal1_m757_tx) tx - внутренний параметр
	{ 1050	,8	,1	, &internal1_m765_tx},	//(internal1_m765_tx) tx - внутренний параметр
	{ 1051	,8	,1	, &internal1_m771_tx},	//(internal1_m771_tx) tx - внутренний параметр
	{ 1052	,8	,1	, &internal1_m527_tx},	//(internal1_m527_tx) tx - внутренний параметр
	{ 1053	,8	,1	, &internal1_m526_tx},	//(internal1_m526_tx) tx - внутренний параметр
	{ 1054	,8	,1	, &internal1_m525_tx},	//(internal1_m525_tx) tx - внутренний параметр
	{ 1055	,8	,1	, &internal1_m521_tx},	//(internal1_m521_tx) tx - внутренний параметр
	{ 1056	,8	,1	, &internal1_m498_tx},	//(internal1_m498_tx) tx - внутренний параметр
	{ 1057	,8	,1	, &internal1_m497_tx},	//(internal1_m497_tx) tx - внутренний параметр
	{ 1058	,8	,1	, &internal1_m496_tx},	//(internal1_m496_tx) tx - внутренний параметр
	{ 1059	,8	,1	, &internal1_m499_tx},	//(internal1_m499_tx) tx - внутренний параметр
	{ 1060	,8	,1	, &internal1_m2468_tx},	//(internal1_m2468_tx) tx - внутренний параметр
	{ 1061	,8	,1	, &internal1_m2178_tx},	//(internal1_m2178_tx) tx - внутренний параметр
	{ 1062	,8	,1	, &internal1_m2467_tx},	//(internal1_m2467_tx) tx - внутренний параметр
	{ 1063	,8	,1	, &internal1_m2466_tx},	//(internal1_m2466_tx) tx - внутренний параметр
	{ 1064	,8	,1	, &internal1_m2464_tx},	//(internal1_m2464_tx) tx - внутренний параметр
	{ 1065	,8	,1	, &internal1_m108_tx},	//(internal1_m108_tx) tx - внутренний параметр
	{ 1066	,8	,1	, &internal1_m1144_tx},	//(internal1_m1144_tx) tx - внутренний параметр
	{ 1067	,8	,1	, &internal1_m2326_tx},	//(internal1_m2326_tx) tx - внутренний параметр
	{ 1068	,8	,1	, &internal1_m2325_tx},	//(internal1_m2325_tx) tx - внутренний параметр
	{ 1069	,8	,1	, &internal1_m2324_tx},	//(internal1_m2324_tx) tx - внутренний параметр
	{ 1070	,8	,1	, &internal1_m1256_tx},	//(internal1_m1256_tx) tx - внутренний параметр
	{ 1071	,8	,1	, &internal1_m1255_tx},	//(internal1_m1255_tx) tx - внутренний параметр
	{ 1072	,8	,1	, &internal1_m1251_tx},	//(internal1_m1251_tx) tx - внутренний параметр
	{ 1073	,8	,1	, &internal1_m1244_tx},	//(internal1_m1244_tx) tx - внутренний параметр
	{ 1074	,8	,1	, &internal1_m1242_tx},	//(internal1_m1242_tx) tx - внутренний параметр
	{ 1075	,8	,1	, &internal1_m1240_tx},	//(internal1_m1240_tx) tx - внутренний параметр
	{ 1076	,8	,1	, &internal1_m1238_tx},	//(internal1_m1238_tx) tx - внутренний параметр
	{ 1077	,8	,1	, &internal1_m1281_tx},	//(internal1_m1281_tx) tx - внутренний параметр
	{ 1078	,8	,1	, &internal1_m1288_tx},	//(internal1_m1288_tx) tx - внутренний параметр
	{ 1079	,8	,1	, &internal1_m1293_tx},	//(internal1_m1293_tx) tx - внутренний параметр
	{ 1080	,8	,1	, &internal1_m1299_tx},	//(internal1_m1299_tx) tx - внутренний параметр
	{ 1081	,8	,1	, &internal1_m1259_tx},	//(internal1_m1259_tx) tx - внутренний параметр
	{ 1082	,8	,1	, &internal1_m1280_tx},	//(internal1_m1280_tx) tx - внутренний параметр
	{ 1083	,8	,1	, &internal1_m1294_tx},	//(internal1_m1294_tx) tx - внутренний параметр
	{ 1084	,8	,1	, &internal1_m476_tx},	//(internal1_m476_tx) tx - внутренний параметр
	{ 1085	,8	,1	, &internal1_m470_tx},	//(internal1_m470_tx) tx - внутренний параметр
	{ 1086	,8	,1	, &internal1_m472_tx},	//(internal1_m472_tx) tx - внутренний параметр
	{ 1087	,8	,1	, &internal1_m474_tx},	//(internal1_m474_tx) tx - внутренний параметр
	{ 1088	,8	,1	, &internal1_m481_tx},	//(internal1_m481_tx) tx - внутренний параметр
	{ 1089	,8	,1	, &internal1_m435_tx},	//(internal1_m435_tx) tx - внутренний параметр
	{ 1090	,8	,1	, &internal1_m433_tx},	//(internal1_m433_tx) tx - внутренний параметр
	{ 1091	,8	,1	, &internal1_m434_tx},	//(internal1_m434_tx) tx - внутренний параметр
	{ 1092	,8	,1	, &internal1_m427_tx},	//(internal1_m427_tx) tx - внутренний параметр
	{ 1093	,8	,1	, &internal1_m889_tx},	//(internal1_m889_tx) tx - внутренний параметр
	{ 1094	,8	,1	, &internal1_m888_tx},	//(internal1_m888_tx) tx - внутренний параметр
	{ 1095	,8	,1	, &internal1_m887_tx},	//(internal1_m887_tx) tx - внутренний параметр
	{ 1096	,8	,1	, &internal1_m883_tx},	//(internal1_m883_tx) tx - внутренний параметр
	{ 1097	,8	,1	, &internal1_m1345_tx},	//(internal1_m1345_tx) tx - внутренний параметр
	{ 1098	,8	,1	, &internal1_m1344_tx},	//(internal1_m1344_tx) tx - внутренний параметр
	{ 1099	,8	,1	, &internal1_m1343_tx},	//(internal1_m1343_tx) tx - внутренний параметр
	{ 1100	,8	,1	, &internal1_m1556_tx},	//(internal1_m1556_tx) tx - внутренний параметр
	{ 1101	,8	,1	, &internal1_m1569_tx},	//(internal1_m1569_tx) tx - внутренний параметр
	{ 1102	,8	,1	, &internal1_m1568_tx},	//(internal1_m1568_tx) tx - внутренний параметр
	{ 1103	,8	,1	, &internal1_m1567_tx},	//(internal1_m1567_tx) tx - внутренний параметр
	{ 1104	,8	,1	, &internal1_m1558_tx},	//(internal1_m1558_tx) tx - внутренний параметр
	{ 1105	,8	,1	, &internal1_m2296_tx},	//(internal1_m2296_tx) tx - внутренний параметр
	{ 1106	,8	,1	, &internal1_m2279_tx},	//(internal1_m2279_tx) tx - внутренний параметр
	{ 1107	,8	,1	, &internal1_m2256_tx},	//(internal1_m2256_tx) tx - внутренний параметр
	{ 1108	,8	,1	, &internal1_m1566_tx},	//(internal1_m1566_tx) tx - внутренний параметр
	{ 1109	,8	,1	, &internal1_m1545_tx},	//(internal1_m1545_tx) tx - внутренний параметр
	{ 1110	,8	,1	, &internal1_m1544_tx},	//(internal1_m1544_tx) tx - внутренний параметр
	{ 1111	,8	,1	, &internal1_m1543_tx},	//(internal1_m1543_tx) tx - внутренний параметр
	{ 1112	,8	,1	, &internal1_m1565_tx},	//(internal1_m1565_tx) tx - внутренний параметр
	{ 1113	,8	,1	, &internal1_m1531_tx},	//(internal1_m1531_tx) tx - внутренний параметр
	{ 1114	,8	,1	, &internal1_m1533_tx},	//(internal1_m1533_tx) tx - внутренний параметр
	{ 1115	,8	,1	, &internal1_m1530_tx},	//(internal1_m1530_tx) tx - внутренний параметр
	{ 1116	,8	,1	, &internal1_m1503_tx},	//(internal1_m1503_tx) tx - внутренний параметр
	{ 1117	,8	,1	, &internal1_m1502_tx},	//(internal1_m1502_tx) tx - внутренний параметр
	{ 1118	,8	,1	, &internal1_m1511_tx},	//(internal1_m1511_tx) tx - внутренний параметр
	{ 1119	,8	,1	, &internal1_m1515_tx},	//(internal1_m1515_tx) tx - внутренний параметр
	{ 1120	,8	,1	, &internal1_m982_tx},	//(internal1_m982_tx) tx - внутренний параметр
	{ 1121	,8	,1	, &internal1_m985_tx},	//(internal1_m985_tx) tx - внутренний параметр
	{ 1122	,8	,1	, &internal1_m2247_tx},	//(internal1_m2247_tx) tx - внутренний параметр
	{ 1123	,8	,1	, &internal1_m975_tx},	//(internal1_m975_tx) tx - внутренний параметр
	{ 1124	,8	,1	, &internal1_m973_tx},	//(internal1_m973_tx) tx - внутренний параметр
	{ 1125	,8	,1	, &internal1_m981_tx},	//(internal1_m981_tx) tx - внутренний параметр
	{ 1126	,8	,1	, &internal1_m965_tx},	//(internal1_m965_tx) tx - внутренний параметр
	{ 1127	,8	,1	, &internal1_m963_tx},	//(internal1_m963_tx) tx - внутренний параметр
	{ 1128	,8	,1	, &internal1_m959_tx},	//(internal1_m959_tx) tx - внутренний параметр
	{ 1129	,8	,1	, &internal1_m980_tx},	//(internal1_m980_tx) tx - внутренний параметр
	{ 1130	,8	,1	, &internal1_m947_tx},	//(internal1_m947_tx) tx - внутренний параметр
	{ 1131	,8	,1	, &internal1_m948_tx},	//(internal1_m948_tx) tx - внутренний параметр
	{ 1132	,8	,1	, &internal1_m945_tx},	//(internal1_m945_tx) tx - внутренний параметр
	{ 1133	,8	,1	, &internal1_m633_tx},	//(internal1_m633_tx) tx - внутренний параметр
	{ 1134	,8	,1	, &internal1_m636_tx},	//(internal1_m636_tx) tx - внутренний параметр
	{ 1135	,8	,1	, &internal1_m635_tx},	//(internal1_m635_tx) tx - внутренний параметр
	{ 1136	,8	,1	, &internal1_m622_tx},	//(internal1_m622_tx) tx - внутренний параметр
	{ 1137	,8	,1	, &internal1_m621_tx},	//(internal1_m621_tx) tx - внутренний параметр
	{ 1138	,8	,1	, &internal1_m618_tx},	//(internal1_m618_tx) tx - внутренний параметр
	{ 1139	,8	,1	, &internal1_m631_tx},	//(internal1_m631_tx) tx - внутренний параметр
	{ 1140	,8	,1	, &internal1_m608_tx},	//(internal1_m608_tx) tx - внутренний параметр
	{ 1141	,8	,1	, &internal1_m607_tx},	//(internal1_m607_tx) tx - внутренний параметр
	{ 1142	,8	,1	, &internal1_m603_tx},	//(internal1_m603_tx) tx - внутренний параметр
	{ 1143	,8	,1	, &internal1_m634_tx},	//(internal1_m634_tx) tx - внутренний параметр
	{ 1144	,8	,1	, &internal1_m591_tx},	//(internal1_m591_tx) tx - внутренний параметр
	{ 1145	,8	,1	, &internal1_m590_tx},	//(internal1_m590_tx) tx - внутренний параметр
	{ 1146	,8	,1	, &internal1_m593_tx},	//(internal1_m593_tx) tx - внутренний параметр
	{ 1147	,8	,1	, &internal1_m570_tx},	//(internal1_m570_tx) tx - внутренний параметр
	{ 1148	,8	,1	, &internal1_m571_tx},	//(internal1_m571_tx) tx - внутренний параметр
	{ 1149	,8	,1	, &internal1_m572_tx},	//(internal1_m572_tx) tx - внутренний параметр
	{ 1150	,8	,1	, &internal1_m577_tx},	//(internal1_m577_tx) tx - внутренний параметр
	{ 1151	,8	,1	, &internal1_m2309_tx},	//(internal1_m2309_tx) tx - внутренний параметр
	{ 1152	,8	,1	, &internal1_m2310_tx},	//(internal1_m2310_tx) tx - внутренний параметр
	{ 1153	,8	,1	, &internal1_m2311_tx},	//(internal1_m2311_tx) tx - внутренний параметр
	{ 1154	,8	,1	, &internal1_m1788_tx},	//(internal1_m1788_tx) tx - внутренний параметр
	{ 1155	,8	,1	, &internal1_m1787_tx},	//(internal1_m1787_tx) tx - внутренний параметр
	{ 1156	,8	,1	, &internal1_m1782_tx},	//(internal1_m1782_tx) tx - внутренний параметр
	{ 1157	,8	,1	, &internal1_m1773_tx},	//(internal1_m1773_tx) tx - внутренний параметр
	{ 1158	,8	,1	, &internal1_m1771_tx},	//(internal1_m1771_tx) tx - внутренний параметр
	{ 1159	,8	,1	, &internal1_m1769_tx},	//(internal1_m1769_tx) tx - внутренний параметр
	{ 1160	,8	,1	, &internal1_m1768_tx},	//(internal1_m1768_tx) tx - внутренний параметр
	{ 1161	,8	,1	, &internal1_m1809_tx},	//(internal1_m1809_tx) tx - внутренний параметр
	{ 1162	,8	,1	, &internal1_m1817_tx},	//(internal1_m1817_tx) tx - внутренний параметр
	{ 1163	,8	,1	, &internal1_m1824_tx},	//(internal1_m1824_tx) tx - внутренний параметр
	{ 1164	,8	,1	, &internal1_m1825_tx},	//(internal1_m1825_tx) tx - внутренний параметр
	{ 1165	,8	,1	, &internal1_m1815_tx},	//(internal1_m1815_tx) tx - внутренний параметр
	{ 1166	,8	,1	, &internal1_m1790_tx},	//(internal1_m1790_tx) tx - внутренний параметр
	{ 1167	,8	,1	, &internal1_m1804_tx},	//(internal1_m1804_tx) tx - внутренний параметр
	{ 1168	,8	,1	, &internal1_m453_tx},	//(internal1_m453_tx) tx - внутренний параметр
	{ 1169	,8	,1	, &internal1_m444_tx},	//(internal1_m444_tx) tx - внутренний параметр
	{ 1170	,8	,1	, &internal1_m445_tx},	//(internal1_m445_tx) tx - внутренний параметр
	{ 1171	,8	,1	, &internal1_m447_tx},	//(internal1_m447_tx) tx - внутренний параметр
	{ 1172	,8	,1	, &internal1_m461_tx},	//(internal1_m461_tx) tx - внутренний параметр
	{ 1173	,8	,1	, &internal1_m411_tx},	//(internal1_m411_tx) tx - внутренний параметр
	{ 1174	,8	,1	, &internal1_m408_tx},	//(internal1_m408_tx) tx - внутренний параметр
	{ 1175	,8	,1	, &internal1_m407_tx},	//(internal1_m407_tx) tx - внутренний параметр
	{ 1176	,8	,1	, &internal1_m406_tx},	//(internal1_m406_tx) tx - внутренний параметр
	{ 1177	,8	,1	, &internal1_m866_tx},	//(internal1_m866_tx) tx - внутренний параметр
	{ 1178	,8	,1	, &internal1_m862_tx},	//(internal1_m862_tx) tx - внутренний параметр
	{ 1179	,8	,1	, &internal1_m861_tx},	//(internal1_m861_tx) tx - внутренний параметр
	{ 1180	,8	,1	, &internal1_m860_tx},	//(internal1_m860_tx) tx - внутренний параметр
	{ 1181	,8	,1	, &internal1_m1326_tx},	//(internal1_m1326_tx) tx - внутренний параметр
	{ 1182	,8	,1	, &internal1_m1323_tx},	//(internal1_m1323_tx) tx - внутренний параметр
	{ 1183	,8	,1	, &internal1_m1322_tx},	//(internal1_m1322_tx) tx - внутренний параметр
	{ 1184	,8	,1	, &internal1_m1083_tx},	//(internal1_m1083_tx) tx - внутренний параметр
	{ 1185	,8	,1	, &internal1_m2268_tx},	//(internal1_m2268_tx) tx - внутренний параметр
	{ 1186	,8	,1	, &internal1_m1094_tx},	//(internal1_m1094_tx) tx - внутренний параметр
	{ 1187	,8	,1	, &internal1_m1096_tx},	//(internal1_m1096_tx) tx - внутренний параметр
	{ 1188	,8	,1	, &internal1_m1095_tx},	//(internal1_m1095_tx) tx - внутренний параметр
	{ 1189	,8	,1	, &internal1_m2262_tx},	//(internal1_m2262_tx) tx - внутренний параметр
	{ 1190	,8	,1	, &internal1_m1085_tx},	//(internal1_m1085_tx) tx - внутренний параметр
	{ 1191	,8	,1	, &internal1_m2267_tx},	//(internal1_m2267_tx) tx - внутренний параметр
	{ 1192	,8	,1	, &internal1_m1093_tx},	//(internal1_m1093_tx) tx - внутренний параметр
	{ 1193	,8	,1	, &internal1_m1074_tx},	//(internal1_m1074_tx) tx - внутренний параметр
	{ 1194	,8	,1	, &internal1_m1073_tx},	//(internal1_m1073_tx) tx - внутренний параметр
	{ 1195	,8	,1	, &internal1_m1070_tx},	//(internal1_m1070_tx) tx - внутренний параметр
	{ 1196	,8	,1	, &internal1_m1092_tx},	//(internal1_m1092_tx) tx - внутренний параметр
	{ 1197	,8	,1	, &internal1_m1060_tx},	//(internal1_m1060_tx) tx - внутренний параметр
	{ 1198	,8	,1	, &internal1_m1058_tx},	//(internal1_m1058_tx) tx - внутренний параметр
	{ 1199	,8	,1	, &internal1_m1057_tx},	//(internal1_m1057_tx) tx - внутренний параметр
	{ 1200	,8	,1	, &internal1_m1036_tx},	//(internal1_m1036_tx) tx - внутренний параметр
	{ 1201	,8	,1	, &internal1_m1035_tx},	//(internal1_m1035_tx) tx - внутренний параметр
	{ 1202	,8	,1	, &internal1_m1025_tx},	//(internal1_m1025_tx) tx - внутренний параметр
	{ 1203	,8	,1	, &internal1_m1042_tx},	//(internal1_m1042_tx) tx - внутренний параметр
	{ 1204	,8	,1	, &internal1_m1461_tx},	//(internal1_m1461_tx) tx - внутренний параметр
	{ 1205	,8	,1	, &internal1_m1460_tx},	//(internal1_m1460_tx) tx - внутренний параметр
	{ 1206	,8	,1	, &internal1_m2214_tx},	//(internal1_m2214_tx) tx - внутренний параметр
	{ 1207	,8	,1	, &internal1_m1451_tx},	//(internal1_m1451_tx) tx - внутренний параметр
	{ 1208	,8	,1	, &internal1_m1452_tx},	//(internal1_m1452_tx) tx - внутренний параметр
	{ 1209	,8	,1	, &internal1_m1459_tx},	//(internal1_m1459_tx) tx - внутренний параметр
	{ 1210	,8	,1	, &internal1_m1441_tx},	//(internal1_m1441_tx) tx - внутренний параметр
	{ 1211	,8	,1	, &internal1_m1440_tx},	//(internal1_m1440_tx) tx - внутренний параметр
	{ 1212	,8	,1	, &internal1_m1437_tx},	//(internal1_m1437_tx) tx - внутренний параметр
	{ 1213	,8	,1	, &internal1_m1458_tx},	//(internal1_m1458_tx) tx - внутренний параметр
	{ 1214	,8	,1	, &internal1_m1424_tx},	//(internal1_m1424_tx) tx - внутренний параметр
	{ 1215	,8	,1	, &internal1_m1422_tx},	//(internal1_m1422_tx) tx - внутренний параметр
	{ 1216	,8	,1	, &internal1_m1426_tx},	//(internal1_m1426_tx) tx - внутренний параметр
	{ 1217	,8	,1	, &internal1_m251_tx},	//(internal1_m251_tx) tx - внутренний параметр
	{ 1218	,8	,1	, &internal1_m266_tx},	//(internal1_m266_tx) tx - внутренний параметр
	{ 1219	,8	,1	, &internal1_m274_tx},	//(internal1_m274_tx) tx - внутренний параметр
	{ 1220	,8	,1	, &internal1_m273_tx},	//(internal1_m273_tx) tx - внутренний параметр
	{ 1221	,8	,1	, &internal1_m259_tx},	//(internal1_m259_tx) tx - внутренний параметр
	{ 1222	,8	,1	, &internal1_m254_tx},	//(internal1_m254_tx) tx - внутренний параметр
	{ 1223	,8	,1	, &internal1_m270_tx},	//(internal1_m270_tx) tx - внутренний параметр
	{ 1224	,8	,1	, &internal1_m243_tx},	//(internal1_m243_tx) tx - внутренний параметр
	{ 1225	,8	,1	, &internal1_m242_tx},	//(internal1_m242_tx) tx - внутренний параметр
	{ 1226	,8	,1	, &internal1_m237_tx},	//(internal1_m237_tx) tx - внутренний параметр
	{ 1227	,8	,1	, &internal1_m269_tx},	//(internal1_m269_tx) tx - внутренний параметр
	{ 1228	,8	,1	, &internal1_m226_tx},	//(internal1_m226_tx) tx - внутренний параметр
	{ 1229	,8	,1	, &internal1_m228_tx},	//(internal1_m228_tx) tx - внутренний параметр
	{ 1230	,8	,1	, &internal1_m225_tx},	//(internal1_m225_tx) tx - внутренний параметр
	{ 1231	,8	,1	, &internal1_m204_tx},	//(internal1_m204_tx) tx - внутренний параметр
	{ 1232	,8	,1	, &internal1_m203_tx},	//(internal1_m203_tx) tx - внутренний параметр
	{ 1233	,8	,1	, &internal1_m202_tx},	//(internal1_m202_tx) tx - внутренний параметр
	{ 1234	,8	,1	, &internal1_m210_tx},	//(internal1_m210_tx) tx - внутренний параметр
	{ 1235	,8	,1	, &internal1_m1404_tx},	//(internal1_m1404_tx) tx - внутренний параметр
	{ 1236	,8	,1	, &internal1_m1386_tx},	//(internal1_m1386_tx) tx - внутренний параметр
	{ 1237	,8	,1	, &internal1_m1391_tx},	//(internal1_m1391_tx) tx - внутренний параметр
	{ 1238	,8	,1	, &internal1_m1408_tx},	//(internal1_m1408_tx) tx - внутренний параметр
	{ 1239	,8	,1	, &internal1_m925_tx},	//(internal1_m925_tx) tx - внутренний параметр
	{ 1240	,8	,1	, &internal1_m930_tx},	//(internal1_m930_tx) tx - внутренний параметр
	{ 1241	,8	,1	, &internal1_m920_tx},	//(internal1_m920_tx) tx - внутренний параметр
	{ 1242	,8	,1	, &internal1_m921_tx},	//(internal1_m921_tx) tx - внутренний параметр
	{ 1243	,1	,1	, &internal1_m1909_q0},	//(internal1_m1909_q0) q0 - внутренний параметр
	{ 1244	,1	,1	, &internal1_m2351_q0},	//(internal1_m2351_q0) q0 - внутренний параметр
	{ 1245	,1	,1	, &internal1_m2335_q0},	//(internal1_m2335_q0) q0 - внутренний параметр
	{ 1246	,1	,1	, &internal1_m2382_q0},	//(internal1_m2382_q0) q0 - внутренний параметр
	{ 1247	,1	,1	, &internal1_m2366_q0},	//(internal1_m2366_q0) q0 - внутренний параметр
	{ 1248	,1	,1	, &internal1_m2357_q0},	//(internal1_m2357_q0) q0 - внутренний параметр
	{ 1249	,1	,1	, &internal1_m2338_q0},	//(internal1_m2338_q0) q0 - внутренний параметр
	{ 1250	,1	,1	, &internal1_m2355_q0},	//(internal1_m2355_q0) q0 - внутренний параметр
	{ 1251	,1	,1	, &internal1_m2336_q0},	//(internal1_m2336_q0) q0 - внутренний параметр
	{ 1252	,1	,1	, &internal1_m2334_q0},	//(internal1_m2334_q0) q0 - внутренний параметр
	{ 1253	,1	,1	, &internal1_m2333_q0},	//(internal1_m2333_q0) q0 - внутренний параметр
	{ 1254	,1	,1	, &internal1_m2347_q0},	//(internal1_m2347_q0) q0 - внутренний параметр
	{ 1255	,1	,1	, &internal1_m2345_q0},	//(internal1_m2345_q0) q0 - внутренний параметр
	{ 1256	,1	,1	, &internal1_m2353_q0},	//(internal1_m2353_q0) q0 - внутренний параметр
	{ 1257	,1	,1	, &internal1_m2349_q0},	//(internal1_m2349_q0) q0 - внутренний параметр
	{ 1258	,1	,1	, &internal1_m2388_q0},	//(internal1_m2388_q0) q0 - внутренний параметр
	{ 1259	,1	,1	, &internal1_m2369_q0},	//(internal1_m2369_q0) q0 - внутренний параметр
	{ 1260	,1	,1	, &internal1_m2386_q0},	//(internal1_m2386_q0) q0 - внутренний параметр
	{ 1261	,1	,1	, &internal1_m2368_q0},	//(internal1_m2368_q0) q0 - внутренний параметр
	{ 1262	,1	,1	, &internal1_m2365_q0},	//(internal1_m2365_q0) q0 - внутренний параметр
	{ 1263	,1	,1	, &internal1_m2364_q0},	//(internal1_m2364_q0) q0 - внутренний параметр
	{ 1264	,1	,1	, &internal1_m2378_q0},	//(internal1_m2378_q0) q0 - внутренний параметр
	{ 1265	,1	,1	, &internal1_m2376_q0},	//(internal1_m2376_q0) q0 - внутренний параметр
	{ 1266	,8	,1	, &internal1_m2239_tx},	//(internal1_m2239_tx) tx - внутренний параметр
	{ 1267	,8	,1	, &internal1_m2218_tx},	//(internal1_m2218_tx) tx - внутренний параметр
	{ 1268	,1	,1	, &internal1_m1931_Pv0},	//(internal1_m1931_Pv0)  - Пер. выключатель механизма
	{ 1269	,1	,1	, &internal1_m1931_Zv0},	//(internal1_m1931_Zv0)  - Зад. выключатель механизма
	{ 1270	,1	,1	, &internal1_m1931_MyFirstEnterFlag},	//(internal1_m1931_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1271	,1	,1	, &internal1_m1930_Pv0},	//(internal1_m1930_Pv0)  - Пер. выключатель механизма
	{ 1272	,1	,1	, &internal1_m1930_Zv0},	//(internal1_m1930_Zv0)  - Зад. выключатель механизма
	{ 1273	,1	,1	, &internal1_m1930_MyFirstEnterFlag},	//(internal1_m1930_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1274	,8	,1	, &internal1_m2405_tx},	//(internal1_m2405_tx) tx - время накопленное сек
	{ 1275	,18	,1	, &internal1_m2405_y0},	//(internal1_m2405_y0) y0
	{ 1276	,8	,1	, &internal1_m2410_tx},	//(internal1_m2410_tx) tx - время накопленное сек
	{ 1277	,18	,1	, &internal1_m2410_y0},	//(internal1_m2410_y0) y0
	{ 1278	,8	,1	, &internal1_m2409_tx},	//(internal1_m2409_tx) tx - время накопленное сек
	{ 1279	,18	,1	, &internal1_m2409_y0},	//(internal1_m2409_y0) y0
	{ 1280	,8	,1	, &internal1_m2446_tx},	//(internal1_m2446_tx) tx - внутренний параметр
	{ 1281	,8	,1	, &internal1_m2444_tx},	//(internal1_m2444_tx) tx - время накопленное сек
	{ 1282	,18	,1	, &internal1_m2444_y0},	//(internal1_m2444_y0) y0
	{ 1283	,1	,1	, &internal1_m2449_q0},	//(internal1_m2449_q0) q0 - внутренний параметр
	{ 1284	,1	,1	, &internal1_m2416_q0},	//(internal1_m2416_q0) q0 - внутренний параметр
	{ 1285	,8	,1	, &internal1_m2424_tx},	//(internal1_m2424_tx) tx - внутренний параметр
	{ 1286	,1	,1	, &internal1_m2422_q0},	//(internal1_m2422_q0) q0 - внутренний параметр
	{ 1287	,8	,1	, &internal1_m2408_fVf0},	//(internal1_m2408_fVf0)  - скорость изменения мощности 
	{ 1288	,8	,1	, &internal1_m2408_fRsg},	//(internal1_m2408_fRsg)  - рассогласование между текущей и заданной мощностью 
	{ 1289	,8	,1	, &internal1_m2408_fRct},	//(internal1_m2408_fRct)  - стартовая реактивность регулятора 
	{ 1290	,8	,1	, &internal1_m2408_fVfMin},	//(internal1_m2408_fVfMin)  - минимальная скорость 
	{ 1291	,8	,1	, &internal1_m2408_fStw0},	//(internal1_m2408_fStw0)  - значение стартовой мощности включения ИМ 
	{ 1292	,8	,1	, &internal1_m2408_fMaxDk},	//(internal1_m2408_fMaxDk)  - изменение координаты при смене задания 
	{ 1293	,8	,1	, &internal1_m2408_fkizm},	//(internal1_m2408_fkizm)  - стартовая координата положения ИМ 0-й реактивности 
	{ 1294	,8	,1	, &internal1_m2408_fwt0},	//(internal1_m2408_fwt0)  - мощность на предыдущем шаге 
	{ 1295	,8	,1	, &internal1_m2408_fwz0},	//(internal1_m2408_fwz0)  - заданная мощность на предыдущем шаге 
	{ 1296	,8	,1	, &internal1_m2408_ftf0},	//(internal1_m2408_ftf0)  - время от фиксации предыдущей мощности 
	{ 1297	,8	,1	, &internal1_m2408_fTk0},	//(internal1_m2408_fTk0)  - последняя температура 
	{ 1298	,3	,1	, &internal1_m2408_FlPar},	//(internal1_m2408_FlPar) - стартовый этап регулирования
	{ 1299	,3	,1	, &internal1_m2408_FlIzm},	//(internal1_m2408_FlIzm) - флаг изменения направления изменения мощности
	{ 1300	,3	,1	, &internal1_m2408_FlCmp},	//(internal1_m2408_FlCmp) - текущее направление изменения мощности
	{ 1301	,3	,1	, &internal1_m2408_StabCoun},	//(internal1_m2408_StabCoun) - счётчик стабильности
	{ 1302	,3	,1	, &internal1_m2408_ZerCoun},	//(internal1_m2408_ZerCoun) - счётчик полной остановки
	{ 1303	,3	,1	, &internal1_m2408_SrCoun},	//(internal1_m2408_SrCoun)  - счётчик усреднения
	{ 1304	,3	,1	, &internal1_m2408_LastStage},	//(internal1_m2408_LastStage)  - последний этап
	{ 1305	,1	,1	, &internal1_m2408_fef},	//(internal1_m2408_fef)  - первый вход
	{ 1306	,8	,1	, &internal1_m2233_tx},	//(internal1_m2233_tx) tx - время накопленное сек
	{ 1307	,18	,1	, &internal1_m2233_y0},	//(internal1_m2233_y0) y0
	{ 1308	,8	,1	, &internal1_m2225_tx},	//(internal1_m2225_tx) tx - время накопленное сек
	{ 1309	,18	,1	, &internal1_m2225_y0},	//(internal1_m2225_y0) y0
	{ 1310	,1	,1	, &internal1_m1919_q0},	//(internal1_m1919_q0) q0 - внутренний параметр
	{ 1311	,1	,1	, &internal1_m1924_q0},	//(internal1_m1924_q0) q0 - внутренний параметр
	{ 1312	,1	,1	, &internal1_m1916_q0},	//(internal1_m1916_q0) q0 - внутренний параметр
	{ 1313	,1	,1	, &internal1_m1958_q0},	//(internal1_m1958_q0) q0 - внутренний параметр
	{ 1314	,8	,1	, &internal1_m830_tx},	//(internal1_m830_tx) tx - время накопленное сек
	{ 1315	,18	,1	, &internal1_m830_y0},	//(internal1_m830_y0) y0
	{ 1316	,8	,1	, &internal1_m2229_tx},	//(internal1_m2229_tx) tx - внутренний параметр
	{ 1317	,1	,1	, &internal1_m2232_q0},	//(internal1_m2232_q0) q0 - внутренний параметр
	{ 1318	,1	,1	, &internal1_m2224_q0},	//(internal1_m2224_q0) q0 - внутренний параметр
	{ 1319	,8	,1	, &internal1_m2193_tx},	//(internal1_m2193_tx) tx - внутренний параметр
	{ 1320	,8	,1	, &internal1_m2204_tx},	//(internal1_m2204_tx) tx - внутренний параметр
	{ 1321	,8	,1	, &internal1_m2190_tx},	//(internal1_m2190_tx) tx - внутренний параметр
	{ 1322	,1	,1	, &internal1_m2196_q0},	//(internal1_m2196_q0) q0 - внутренний параметр
	{ 1323	,1	,1	, &internal1_m2208_q0},	//(internal1_m2208_q0) q0 - внутренний параметр
	{ 1324	,8	,1	, &internal1_m2165_tx},	//(internal1_m2165_tx) tx - внутренний параметр
	{ 1325	,8	,1	, &internal1_m52_tx},	//(internal1_m52_tx) tx - внутренний параметр
	{ 1326	,8	,1	, &internal1_m364_tx},	//(internal1_m364_tx) tx - внутренний параметр
	{ 1327	,8	,1	, &internal1_m317_tx},	//(internal1_m317_tx) tx - внутренний параметр
	{ 1328	,8	,1	, &internal1_m831_tx},	//(internal1_m831_tx) tx - внутренний параметр
	{ 1329	,8	,1	, &internal1_m1623_tx},	//(internal1_m1623_tx) tx - внутренний параметр
	{ 1330	,8	,1	, &internal1_m120_tx},	//(internal1_m120_tx) tx - внутренний параметр
	{ 1331	,8	,1	, &internal1_m122_tx},	//(internal1_m122_tx) tx - внутренний параметр
	{ 1332	,8	,1	, &internal1_m127_tx},	//(internal1_m127_tx) tx - внутренний параметр
	{ 1333	,8	,1	, &internal1_m21_tx},	//(internal1_m21_tx) tx - внутренний параметр
	{ 1334	,8	,1	, &internal1_m13_tx},	//(internal1_m13_tx) tx - внутренний параметр
	{ 1335	,8	,1	, &internal1_m2175_tx},	//(internal1_m2175_tx) tx - внутренний параметр
	{ 1336	,8	,1	, &internal1_m2162_tx},	//(internal1_m2162_tx) tx - внутренний параметр
	{ 1337	,8	,1	, &internal1_m2280_tx},	//(internal1_m2280_tx) tx - внутренний параметр
	{ 1338	,8	,1	, &internal1_m2282_tx},	//(internal1_m2282_tx) tx - внутренний параметр
	{ 1339	,8	,1	, &internal1_m82_tx},	//(internal1_m82_tx) tx - внутренний параметр
	{ 1340	,8	,1	, &internal1_m335_tx},	//(internal1_m335_tx) tx - время накопленное сек
	{ 1341	,18	,1	, &internal1_m335_y0},	//(internal1_m335_y0) y0
	{ 1342	,8	,1	, &internal1_m2073_tx},	//(internal1_m2073_tx) tx - время накопленное сек
	{ 1343	,18	,1	, &internal1_m2073_y0},	//(internal1_m2073_y0) y0
	{ 1344	,8	,1	, &internal1_m2087_q0},	//(internal1_m2087_q0) q0 - внутренний параметр
	{ 1345	,8	,1	, &internal1_m1644_q0},	//(internal1_m1644_q0) q0 - внутренний параметр
	{ 1346	,8	,1	, &internal1_m1682_q0},	//(internal1_m1682_q0) q0 - внутренний параметр
	{ 1347	,8	,1	, &internal1_m1685_q0},	//(internal1_m1685_q0) q0 - внутренний параметр
	{ 1348	,8	,1	, &internal1_m2127_q0},	//(internal1_m2127_q0) q0 - внутренний параметр
	{ 1349	,8	,1	, &internal1_m2105_tx},	//(internal1_m2105_tx) tx - время накопленное сек
	{ 1350	,18	,1	, &internal1_m2105_y0},	//(internal1_m2105_y0) y0
	{ 1351	,8	,1	, &internal1_m2120_tx},	//(internal1_m2120_tx) tx - время накопленное сек
	{ 1352	,18	,1	, &internal1_m2120_y0},	//(internal1_m2120_y0) y0
	{ 1353	,8	,1	, &internal1_m2117_tx},	//(internal1_m2117_tx) tx - время накопленное сек
	{ 1354	,18	,1	, &internal1_m2117_y0},	//(internal1_m2117_y0) y0
	{ 1355	,8	,1	, &internal1_m2260_tx},	//(internal1_m2260_tx) tx - время накопленное сек
	{ 1356	,18	,1	, &internal1_m2260_y0},	//(internal1_m2260_y0) y0
	{ 1357	,8	,1	, &internal1_m2271_tx},	//(internal1_m2271_tx) tx - время накопленное сек
	{ 1358	,18	,1	, &internal1_m2271_y0},	//(internal1_m2271_y0) y0
	{ 1359	,8	,1	, &internal1_m2026_tx},	//(internal1_m2026_tx) tx - время накопленное сек
	{ 1360	,18	,1	, &internal1_m2026_y0},	//(internal1_m2026_y0) y0
	{ 1361	,8	,1	, &internal1_m2025_tx},	//(internal1_m2025_tx) tx - время накопленное сек
	{ 1362	,18	,1	, &internal1_m2025_y0},	//(internal1_m2025_y0) y0
	{ 1363	,8	,1	, &internal1_m2024_tx},	//(internal1_m2024_tx) tx - время накопленное сек
	{ 1364	,18	,1	, &internal1_m2024_y0},	//(internal1_m2024_y0) y0
	{ 1365	,8	,1	, &internal1_m2023_tx},	//(internal1_m2023_tx) tx - время накопленное сек
	{ 1366	,18	,1	, &internal1_m2023_y0},	//(internal1_m2023_y0) y0
	{ 1367	,8	,1	, &internal1_m1699_tx},	//(internal1_m1699_tx) tx - время накопленное сек
	{ 1368	,18	,1	, &internal1_m1699_y0},	//(internal1_m1699_y0) y0
	{ 1369	,8	,1	, &internal1_m1692_tx},	//(internal1_m1692_tx) tx - время накопленное сек
	{ 1370	,18	,1	, &internal1_m1692_y0},	//(internal1_m1692_y0) y0
	{ 1371	,8	,1	, &internal1_m1639_tx},	//(internal1_m1639_tx) tx - время накопленное сек
	{ 1372	,18	,1	, &internal1_m1639_y0},	//(internal1_m1639_y0) y0
	{ 1373	,8	,1	, &internal1_m918_tx},	//(internal1_m918_tx) tx - время накопленное сек
	{ 1374	,18	,1	, &internal1_m918_y0},	//(internal1_m918_y0) y0
	{ 1375	,8	,1	, &internal1_m917_tx},	//(internal1_m917_tx) tx - время накопленное сек
	{ 1376	,18	,1	, &internal1_m917_y0},	//(internal1_m917_y0) y0
	{ 1377	,8	,1	, &internal1_m935_tx},	//(internal1_m935_tx) tx - время накопленное сек
	{ 1378	,18	,1	, &internal1_m935_y0},	//(internal1_m935_y0) y0
	{ 1379	,8	,1	, &internal1_m194_tx},	//(internal1_m194_tx) tx - время накопленное сек
	{ 1380	,18	,1	, &internal1_m194_y0},	//(internal1_m194_y0) y0
	{ 1381	,8	,1	, &internal1_m193_tx},	//(internal1_m193_tx) tx - время накопленное сек
	{ 1382	,18	,1	, &internal1_m193_y0},	//(internal1_m193_y0) y0
	{ 1383	,8	,1	, &internal1_m215_tx},	//(internal1_m215_tx) tx - время накопленное сек
	{ 1384	,18	,1	, &internal1_m215_y0},	//(internal1_m215_y0) y0
	{ 1385	,8	,1	, &internal1_m584_tx},	//(internal1_m584_tx) tx - время накопленное сек
	{ 1386	,18	,1	, &internal1_m584_y0},	//(internal1_m584_y0) y0
	{ 1387	,8	,1	, &internal1_m2316_tx},	//(internal1_m2316_tx) tx - внутренний параметр
	{ 1388	,8	,1	, &internal1_m1336_tx},	//(internal1_m1336_tx) tx - внутренний параметр
	{ 1389	,8	,1	, &internal1_m1828_tx},	//(internal1_m1828_tx) tx - время накопленное сек
	{ 1390	,18	,1	, &internal1_m1828_y0},	//(internal1_m1828_y0) y0
	{ 1391	,8	,1	, &internal1_m1303_tx},	//(internal1_m1303_tx) tx - время накопленное сек
	{ 1392	,18	,1	, &internal1_m1303_y0},	//(internal1_m1303_y0) y0
	{ 1393	,8	,1	, &internal1_m1521_tx},	//(internal1_m1521_tx) tx - время накопленное сек
	{ 1394	,18	,1	, &internal1_m1521_y0},	//(internal1_m1521_y0) y0
	{ 1395	,8	,1	, &internal1_m1048_tx},	//(internal1_m1048_tx) tx - время накопленное сек
	{ 1396	,18	,1	, &internal1_m1048_y0},	//(internal1_m1048_y0) y0
	{ 1397	,8	,1	, &internal1_m1411_tx},	//(internal1_m1411_tx) tx - время накопленное сек
	{ 1398	,18	,1	, &internal1_m1411_y0},	//(internal1_m1411_y0) y0
	{ 1399	,1	,1	, &internal1_m1205_q0},	//(internal1_m1205_q0) q0 - внутренний параметр
	{ 1400	,1	,1	, &internal1_m1203_q0},	//(internal1_m1203_q0) q0 - внутренний параметр
	{ 1401	,1	,1	, &internal1_m1202_q0},	//(internal1_m1202_q0) q0 - внутренний параметр
	{ 1402	,1	,1	, &internal1_m1200_q0},	//(internal1_m1200_q0) q0 - внутренний параметр
	{ 1403	,1	,1	, &internal1_m1199_q0},	//(internal1_m1199_q0) q0 - внутренний параметр
	{ 1404	,1	,1	, &internal1_m1197_q0},	//(internal1_m1197_q0) q0 - внутренний параметр
	{ 1405	,1	,1	, &internal1_m1196_q0},	//(internal1_m1196_q0) q0 - внутренний параметр
	{ 1406	,1	,1	, &internal1_m1194_q0},	//(internal1_m1194_q0) q0 - внутренний параметр
	{ 1407	,1	,1	, &internal1_m1193_q0},	//(internal1_m1193_q0) q0 - внутренний параметр
	{ 1408	,1	,1	, &internal1_m54_x0},	//(internal1_m54_x0) - значение входного параметра на предыдущем шаге
	{ 1409	,8	,1	, &internal1_m54_tim},	//(internal1_m54_tim) - время задержки выходного сигнала
	{ 1410	,1	,1	, &internal1_m1112_q0},	//(internal1_m1112_q0) q0 - внутренний параметр
	{ 1411	,1	,1	, &internal1_m1633_x0},	//(internal1_m1633_x0) - значение входного параметра на предыдущем шаге
	{ 1412	,8	,1	, &internal1_m1633_tim},	//(internal1_m1633_tim) - время задержки выходного сигнала
	{ 1413	,1	,1	, &internal1_m1681_x0},	//(internal1_m1681_x0) - значение входного параметра на предыдущем шаге
	{ 1414	,8	,1	, &internal1_m1681_tim},	//(internal1_m1681_tim) - время задержки выходного сигнала
	{ 1415	,1	,1	, &internal1_m1684_x0},	//(internal1_m1684_x0) - значение входного параметра на предыдущем шаге
	{ 1416	,8	,1	, &internal1_m1684_tim},	//(internal1_m1684_tim) - время задержки выходного сигнала
	{ 1417	,1	,1	, &internal1_m2068_x0},	//(internal1_m2068_x0) - значение входного параметра на предыдущем шаге
	{ 1418	,8	,1	, &internal1_m2068_tim},	//(internal1_m2068_tim) - время задержки выходного сигнала
	{ 1419	,1	,1	, &internal1_m1152_q0},	//(internal1_m1152_q0) q0 - внутренний параметр
	{ 1420	,1	,1	, &internal1_m1158_q0},	//(internal1_m1158_q0) q0 - внутренний параметр
	{ 1421	,1	,1	, &internal1_m1176_q0},	//(internal1_m1176_q0) q0 - внутренний параметр
	{ 1422	,1	,1	, &internal1_m1186_q0},	//(internal1_m1186_q0) q0 - внутренний параметр
	{ 1423	,1	,1	, &internal1_m1164_q0},	//(internal1_m1164_q0) q0 - внутренний параметр
	{ 1424	,1	,1	, &internal1_m1178_q0},	//(internal1_m1178_q0) q0 - внутренний параметр
	{ 1425	,1	,1	, &internal1_m2154_q0},	//(internal1_m2154_q0) q0 - внутренний параметр
	{ 1426	,1	,1	, &internal1_m2153_q0},	//(internal1_m2153_q0) q0 - внутренний параметр
	{ 1427	,3	,1	, &internal1_m352_Step},	//(internal1_m352_Step)  - текущий шаг программы
	{ 1428	,18	,10	, &internal1_m352_rz},	//(internal1_m352_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1429	,8	,1	, &internal1_m352_TimS},	//(internal1_m352_TimS) Время от старта программы
	{ 1430	,1	,1	, &internal1_m352_FinPr0},	//(internal1_m352_FinPr0) FinPr - конец программы
	{ 1431	,1	,1	, &internal1_m352_ErrPr0},	//(internal1_m352_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1432	,1	,1	, &internal1_m352_sbINI0},	//(internal1_m352_sbINI0) sbINI - запуск проверки ИНИ
	{ 1433	,1	,1	, &internal1_m352_sbVuIS0},	//(internal1_m352_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1434	,1	,1	, &internal1_m352_sb2UR0},	//(internal1_m352_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1435	,1	,1	, &internal1_m352_sbNupIS0},	//(internal1_m352_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1436	,1	,1	, &internal1_m352_sbVuRB0},	//(internal1_m352_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1437	,1	,1	, &internal1_m352_MyFirstEnterFlag},	//(internal1_m352_MyFirstEnterFlag)  
	{ 1438	,5	,1	, &internal1_m360_x0},	//(internal1_m360_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1439	,8	,1	, &internal1_m319_TimS},	//(internal1_m319_TimS) Время до нулевого отсчета
	{ 1440	,1	,1	, &internal1_m319_pusk0},	//(internal1_m319_pusk0) pusk - разрешение выполнения программы
	{ 1441	,3	,1	, &internal1_m294_Step},	//(internal1_m294_Step)  - текущий шаг программы
	{ 1442	,18	,10	, &internal1_m294_rz},	//(internal1_m294_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1443	,8	,1	, &internal1_m294_TimS},	//(internal1_m294_TimS) Время от старта программы
	{ 1444	,1	,1	, &internal1_m294_FinPr0},	//(internal1_m294_FinPr0) FinPr - конец программы
	{ 1445	,1	,1	, &internal1_m294_ErrPr0},	//(internal1_m294_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1446	,1	,1	, &internal1_m294_sbINI0},	//(internal1_m294_sbINI0) sbINI - запуск проверки ИНИ
	{ 1447	,1	,1	, &internal1_m294_sbVuIS0},	//(internal1_m294_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1448	,1	,1	, &internal1_m294_sb2UR0},	//(internal1_m294_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1449	,1	,1	, &internal1_m294_sbNupIS0},	//(internal1_m294_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1450	,1	,1	, &internal1_m294_sbVuRB0},	//(internal1_m294_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1451	,1	,1	, &internal1_m294_MyFirstEnterFlag},	//(internal1_m294_MyFirstEnterFlag)  
	{ 1452	,1	,1	, &internal1_m1595_q0},	//(internal1_m1595_q0) q0 - внутренний параметр
	{ 1453	,3	,1	, &internal1_m1596_Step},	//(internal1_m1596_Step)  - текущий шаг программы
	{ 1454	,18	,6	, &internal1_m1596_rz},	//(internal1_m1596_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1455	,8	,1	, &internal1_m1596_TimS},	//(internal1_m1596_TimS) Время от старта программы
	{ 1456	,1	,1	, &internal1_m1596_FinPr0},	//(internal1_m1596_FinPr0) FinPr - конец программы
	{ 1457	,1	,1	, &internal1_m1596_ErrPr0},	//(internal1_m1596_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1458	,1	,1	, &internal1_m1596_sbINI0},	//(internal1_m1596_sbINI0) sbINI - запуск проверки ИНИ
	{ 1459	,1	,1	, &internal1_m1596_sbVuIS0},	//(internal1_m1596_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1460	,1	,1	, &internal1_m1596_sb2UR0},	//(internal1_m1596_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1461	,1	,1	, &internal1_m1596_sbNupIS0},	//(internal1_m1596_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1462	,1	,1	, &internal1_m1596_sbVuRB0},	//(internal1_m1596_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1463	,1	,1	, &internal1_m1596_MyFirstEnterFlag},	//(internal1_m1596_MyFirstEnterFlag)  
	{ 1464	,1	,1	, &internal1_m1148_q0},	//(internal1_m1148_q0) q0 - внутренний параметр
	{ 1465	,1	,1	, &internal1_m1145_q0},	//(internal1_m1145_q0) q0 - внутренний параметр
	{ 1466	,1	,1	, &internal1_m1147_q0},	//(internal1_m1147_q0) q0 - внутренний параметр
	{ 1467	,1	,1	, &internal1_m1141_q0},	//(internal1_m1141_q0) q0 - внутренний параметр
	{ 1468	,1	,1	, &internal1_m832_q0},	//(internal1_m832_q0) q0 - внутренний параметр
	{ 1469	,1	,1	, &internal1_m362_q0},	//(internal1_m362_q0) q0 - внутренний параметр
	{ 1470	,1	,1	, &internal1_m358_q0},	//(internal1_m358_q0) q0 - внутренний параметр
	{ 1471	,1	,1	, &internal1_m314_q0},	//(internal1_m314_q0) q0 - внутренний параметр
	{ 1472	,5	,1	, &internal1_m313_x0},	//(internal1_m313_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1473	,1	,1	, &internal1_m2083_q0},	//(internal1_m2083_q0) q0 - внутренний параметр
	{ 1474	,1	,1	, &internal1_m2076_q0},	//(internal1_m2076_q0) q0 - внутренний параметр
	{ 1475	,1	,1	, &internal1_m2071_q0},	//(internal1_m2071_q0) q0 - внутренний параметр
	{ 1476	,1	,1	, &internal1_m2137_q0},	//(internal1_m2137_q0) q0 - внутренний параметр
	{ 1477	,1	,1	, &internal1_m2108_q0},	//(internal1_m2108_q0) q0 - внутренний параметр
	{ 1478	,1	,1	, &internal1_m2096_q0},	//(internal1_m2096_q0) q0 - внутренний параметр
	{ 1479	,1	,1	, &internal1_m1660_q0},	//(internal1_m1660_q0) q0 - внутренний параметр
	{ 1480	,1	,1	, &internal1_m1647_x0},	//(internal1_m1647_x0) был приход сигнала x1
	{ 1481	,8	,1	, &internal1_m1647_y0},	//(internal1_m1647_y0) интервал между сигналами х1 и х2
	{ 1482	,1	,1	, &internal1_m1647_fef},	//(internal1_m1647_fef) FirstEnterFlag
	{ 1483	,1	,1	, &internal1_m1642_q0},	//(internal1_m1642_q0) q0 - внутренний параметр
	{ 1484	,1	,1	, &internal1_m1632_q0},	//(internal1_m1632_q0) q0 - внутренний параметр
	{ 1485	,1	,1	, &internal1_m1695_q0},	//(internal1_m1695_q0) q0 - внутренний параметр
	{ 1486	,1	,1	, &internal1_m1716_q0},	//(internal1_m1716_q0) q0 - внутренний параметр
	{ 1487	,1	,1	, &internal1_m1680_q0},	//(internal1_m1680_q0) q0 - внутренний параметр
	{ 1488	,1	,1	, &internal1_m1696_x0},	//(internal1_m1696_x0) был приход сигнала x1
	{ 1489	,8	,1	, &internal1_m1696_y0},	//(internal1_m1696_y0) интервал между сигналами х1 и х2
	{ 1490	,1	,1	, &internal1_m1696_fef},	//(internal1_m1696_fef) FirstEnterFlag
	{ 1491	,5	,1	, &internal1_m1613_x0},	//(internal1_m1613_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1492	,1	,1	, &internal1_m1702_q0},	//(internal1_m1702_q0) q0 - внутренний параметр
	{ 1493	,1	,1	, &internal1_m26_q0},	//(internal1_m26_q0) q0 - внутренний параметр
	{ 1494	,1	,1	, &internal1_m1717_q0},	//(internal1_m1717_q0) q0 - внутренний параметр
	{ 1495	,1	,1	, &internal1_m707_q0},	//(internal1_m707_q0) q0 - внутренний параметр
	{ 1496	,1	,1	, &internal1_m692_q0},	//(internal1_m692_q0) q0 - внутренний параметр
	{ 1497	,1	,1	, &internal1_m719_q0},	//(internal1_m719_q0) q0 - внутренний параметр
	{ 1498	,1	,1	, &internal1_m703_q0},	//(internal1_m703_q0) q0 - внутренний параметр
	{ 1499	,1	,1	, &internal1_m687_q0},	//(internal1_m687_q0) q0 - внутренний параметр
	{ 1500	,1	,1	, &internal1_m685_q0},	//(internal1_m685_q0) q0 - внутренний параметр
	{ 1501	,1	,1	, &internal1_m673_q0},	//(internal1_m673_q0) q0 - внутренний параметр
	{ 1502	,5	,1	, &internal1_m1598_q0},	//(internal1_m1598_q0) q0 - внутренний параметр
	{ 1503	,1	,1	, &internal1_m683_q0},	//(internal1_m683_q0) q0 - внутренний параметр
	{ 1504	,1	,1	, &internal1_m116_q0},	//(internal1_m116_q0) q0 - внутренний параметр
	{ 1505	,1	,1	, &internal1_m1863_q0},	//(internal1_m1863_q0) q0 - внутренний параметр
	{ 1506	,1	,1	, &internal1_m1862_q0},	//(internal1_m1862_q0) q0 - внутренний параметр
	{ 1507	,1	,1	, &internal1_m1861_q0},	//(internal1_m1861_q0) q0 - внутренний параметр
	{ 1508	,1	,1	, &internal1_m1860_q0},	//(internal1_m1860_q0) q0 - внутренний параметр
	{ 1509	,1	,1	, &internal1_m1896_q0},	//(internal1_m1896_q0) q0 - внутренний параметр
	{ 1510	,1	,1	, &internal1_m1895_q0},	//(internal1_m1895_q0) q0 - внутренний параметр
	{ 1511	,1	,1	, &internal1_m1894_q0},	//(internal1_m1894_q0) q0 - внутренний параметр
	{ 1512	,1	,1	, &internal1_m2168_q0},	//(internal1_m2168_q0) q0 - внутренний параметр
	{ 1513	,1	,1	, &internal1_m1956_q0},	//(internal1_m1956_q0) q0 - внутренний параметр
	{ 1514	,1	,1	, &internal1_m1945_q0},	//(internal1_m1945_q0) q0 - внутренний параметр
	{ 1515	,1	,1	, &internal1_m1953_q0},	//(internal1_m1953_q0) q0 - внутренний параметр
	{ 1516	,1	,1	, &internal1_m1942_q0},	//(internal1_m1942_q0) q0 - внутренний параметр
	{ 1517	,1	,1	, &internal1_m1950_q0},	//(internal1_m1950_q0) q0 - внутренний параметр
	{ 1518	,1	,1	, &internal1_m2384_q0},	//(internal1_m2384_q0) q0 - внутренний параметр
	{ 1519	,1	,1	, &internal1_m2380_q0},	//(internal1_m2380_q0) q0 - внутренний параметр
	{ 1520	,1	,1	, &internal1_m1921_q0},	//(internal1_m1921_q0) q0 - внутренний параметр
	{ 1521	,1	,1	, &internal1_m1913_q0},	//(internal1_m1913_q0) q0 - внутренний параметр
	{ 1522	,1	,1	, &internal1_m1911_q0},	//(internal1_m1911_q0) q0 - внутренний параметр
	{ 1523	,1	,1	, &internal1_m1907_q0},	//(internal1_m1907_q0) q0 - внутренний параметр
	{ 1524	,1	,1	, &internal1_m1903_q0},	//(internal1_m1903_q0) q0 - внутренний параметр
	{ 1525	,1	,1	, &internal1_m1905_q0},	//(internal1_m1905_q0) q0 - внутренний параметр
	{ 1526	,1	,1	, &internal1_m19_q0},	//(internal1_m19_q0) q0 - внутренний параметр
	{ 1527	,1	,1	, &internal1_m1886_q0},	//(internal1_m1886_q0) q0 - внутренний параметр
	{ 1528	,1	,1	, &internal1_m1884_q0},	//(internal1_m1884_q0) q0 - внутренний параметр
	{ 1529	,1	,1	, &internal1_m1880_q0},	//(internal1_m1880_q0) q0 - внутренний параметр
	{ 1530	,1	,1	, &internal1_m1882_q0},	//(internal1_m1882_q0) q0 - внутренний параметр
	{ 1531	,1	,1	, &internal1_m1878_q0},	//(internal1_m1878_q0) q0 - внутренний параметр
	{ 1532	,1	,1	, &internal1_m1876_q0},	//(internal1_m1876_q0) q0 - внутренний параметр
	{ 1533	,1	,1	, &internal1_m2293_q0},	//(internal1_m2293_q0) q0 - внутренний параметр
	{ 1534	,1	,1	, &internal1_m2288_q0},	//(internal1_m2288_q0) q0 - внутренний параметр
	{ 1535	,1	,1	, &internal1_m2265_q0},	//(internal1_m2265_q0) q0 - внутренний параметр
	{ 1536	,1	,1	, &internal1_m2249_q0},	//(internal1_m2249_q0) q0 - внутренний параметр
	{ 1537	,1	,1	, &internal1_m2180_q0},	//(internal1_m2180_q0) q0 - внутренний параметр
	{ 1538	,1	,1	, &internal1_m1872_q0},	//(internal1_m1872_q0) q0 - внутренний параметр
	{ 1539	,1	,1	, &internal1_m1874_q0},	//(internal1_m1874_q0) q0 - внутренний параметр
	{ 1540	,1	,1	, &internal1_m1858_q0},	//(internal1_m1858_q0) q0 - внутренний параметр
	{ 1541	,1	,1	, &internal1_m1856_q0},	//(internal1_m1856_q0) q0 - внутренний параметр
	{ 1542	,1	,1	, &internal1_m1854_q0},	//(internal1_m1854_q0) q0 - внутренний параметр
	{ 1543	,1	,1	, &internal1_m1852_q0},	//(internal1_m1852_q0) q0 - внутренний параметр
	{ 1544	,1	,1	, &internal1_m1851_q0},	//(internal1_m1851_q0) q0 - внутренний параметр
	{ 1545	,1	,1	, &internal1_m1849_q0},	//(internal1_m1849_q0) q0 - внутренний параметр
	{ 1546	,1	,1	, &internal1_m1848_q0},	//(internal1_m1848_q0) q0 - внутренний параметр
	{ 1547	,1	,1	, &internal1_m1846_q0},	//(internal1_m1846_q0) q0 - внутренний параметр
	{ 1548	,18	,1	, &internal1_m2321_DvUp0},	//(internal1_m2321_DvUp0) - есть команда на движение вперёд
	{ 1549	,18	,1	, &internal1_m2321_DvDw0},	//(internal1_m2321_DvDw0) - есть команда на движение назад
	{ 1550	,18	,1	, &internal1_m2321_FDvUp0},	//(internal1_m2321_FDvUp0) - есть команда на движение вперёд
	{ 1551	,18	,1	, &internal1_m2321_FDvDw0},	//(internal1_m2321_FDvDw0) - есть команда на движение назад
	{ 1552	,18	,1	, &internal1_m2321_BlDv0},	//(internal1_m2321_BlDv0) - была блокировка
	{ 1553	,18	,1	, &internal1_m2321_Pkv0},	//(internal1_m2321_Pkv0) Pkv - передний конечный выключатель
	{ 1554	,18	,1	, &internal1_m2321_Pkav0},	//(internal1_m2321_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1555	,18	,1	, &internal1_m2321_Zkv0},	//(internal1_m2321_Zkv0) Zkv - задний конечный выключатель
	{ 1556	,18	,1	, &internal1_m2321_Zkav0},	//(internal1_m2321_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1557	,8	,1	, &internal1_m2321_txNm},	//(internal1_m2321_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1558	,8	,1	, &internal1_m2321_txSm},	//(internal1_m2321_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1559	,8	,1	, &internal1_m2321_txHr},	//(internal1_m2321_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1560	,8	,1	, &internal1_m2321_txLd},	//(internal1_m2321_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1561	,18	,1	, &internal1_m2321_fef},	//(internal1_m2321_fef) fef
	{ 1562	,18	,1	, &internal1_m2315_DvUp0},	//(internal1_m2315_DvUp0) - есть команда на движение вперёд
	{ 1563	,18	,1	, &internal1_m2315_DvDw0},	//(internal1_m2315_DvDw0) - есть команда на движение назад
	{ 1564	,18	,1	, &internal1_m2315_FDvUp0},	//(internal1_m2315_FDvUp0) - есть команда на движение вперёд
	{ 1565	,18	,1	, &internal1_m2315_FDvDw0},	//(internal1_m2315_FDvDw0) - есть команда на движение назад
	{ 1566	,18	,1	, &internal1_m2315_BlDv0},	//(internal1_m2315_BlDv0) - была блокировка
	{ 1567	,18	,1	, &internal1_m2315_Pkv0},	//(internal1_m2315_Pkv0) Pkv - передний конечный выключатель
	{ 1568	,18	,1	, &internal1_m2315_Pkav0},	//(internal1_m2315_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1569	,18	,1	, &internal1_m2315_Zkv0},	//(internal1_m2315_Zkv0) Zkv - задний конечный выключатель
	{ 1570	,18	,1	, &internal1_m2315_Zkav0},	//(internal1_m2315_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1571	,8	,1	, &internal1_m2315_txNm},	//(internal1_m2315_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1572	,8	,1	, &internal1_m2315_txSm},	//(internal1_m2315_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1573	,8	,1	, &internal1_m2315_txHr},	//(internal1_m2315_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1574	,8	,1	, &internal1_m2315_txLd},	//(internal1_m2315_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1575	,18	,1	, &internal1_m2315_fef},	//(internal1_m2315_fef) fef
	{ 1576	,1	,1	, &internal1_m1675_q0},	//(internal1_m1675_q0) q0 - внутренний параметр
	{ 1577	,1	,1	, &internal1_m1697_x0},	//(internal1_m1697_x0) был приход сигнала x1
	{ 1578	,8	,1	, &internal1_m1697_y0},	//(internal1_m1697_y0) интервал между сигналами х1 и х2
	{ 1579	,1	,1	, &internal1_m1697_fef},	//(internal1_m1697_fef) FirstEnterFlag
	{ 1580	,1	,1	, &internal1_m2119_x0},	//(internal1_m2119_x0) был приход сигнала x1
	{ 1581	,8	,1	, &internal1_m2119_y0},	//(internal1_m2119_y0) интервал между сигналами х1 и х2
	{ 1582	,1	,1	, &internal1_m2119_fef},	//(internal1_m2119_fef) FirstEnterFlag
	{ 1583	,1	,1	, &internal1_m2078_x0},	//(internal1_m2078_x0) был приход сигнала x1
	{ 1584	,8	,1	, &internal1_m2078_y0},	//(internal1_m2078_y0) интервал между сигналами х1 и х2
	{ 1585	,1	,1	, &internal1_m2078_fef},	//(internal1_m2078_fef) FirstEnterFlag
	{ 1586	,1	,1	, &internal1_m305_q0},	//(internal1_m305_q0) q0 - внутренний параметр
	{ 1587	,1	,1	, &internal1_m1120_q0},	//(internal1_m1120_q0) q0 - внутренний параметр
	{ 1588	,1	,1	, &internal1_m695_q0},	//(internal1_m695_q0) q0 - внутренний параметр
	{ 1589	,8	,1	, &internal1_m1479_X0},	//(internal1_m1479_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1590	,8	,1	, &internal1_m1479_t0},	//(internal1_m1479_t0) время нахождения в зоне возврата
	{ 1591	,18	,1	, &internal1_m1479_BLDv0},	//(internal1_m1479_BLDv0) BlDv - Блокировка движения
	{ 1592	,8	,1	, &internal1_m1496_tx},	//(internal1_m1496_tx) tx - время накопленное сек
	{ 1593	,18	,1	, &internal1_m1496_y0},	//(internal1_m1496_y0) y0
	{ 1594	,8	,1	, &internal1_m1497_tx},	//(internal1_m1497_tx) tx - время накопленное сек
	{ 1595	,18	,1	, &internal1_m1497_y0},	//(internal1_m1497_y0) y0
	{ 1596	,3	,1	, &internal1_m1505_xptr},	//(internal1_m1505_xptr) указатель текущей позиции в массиве координат
	{ 1597	,8	,60	, &internal1_m1505_x0},	//(internal1_m1505_x0) x0 - массив мгновенных значений координат
	{ 1598	,8	,60	, &internal1_m1505_tim0},	//(internal1_m1505_tim0) tim0 - массив значений времени цикла
	{ 1599	,8	,1	, &internal1_m1505_sumtim},	//(internal1_m1505_sumtim) sumtim - время в пути
	{ 1600	,8	,1	, &internal1_m1505_StSpeed},	//(internal1_m1505_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1601	,8	,1	, &internal1_m1505_Vz0},	//(internal1_m1505_Vz0) Vz0 - предыдущая заданная скорость
	{ 1602	,3	,1	, &internal1_m1505_flRazg},	//(internal1_m1505_flRazg) признак разгона/торможения
	{ 1603	,8	,1	, &internal1_m1505_DelSp},	//(internal1_m1505_DelSp) DelSp - время переключения скоростей
	{ 1604	,8	,1	, &internal1_m1505_z0},	//(internal1_m1505_z0) z0 - точка прекращения движения
	{ 1605	,8	,1	, &internal1_m1505_txZS},	//(internal1_m1505_txZS) txZS
	{ 1606	,8	,1	, &internal1_m1505_tx},	//(internal1_m1505_tx) tx
	{ 1607	,8	,1	, &internal1_m1505_txd},	//(internal1_m1505_txd) txd
	{ 1608	,8	,1	, &internal1_m1505_txMBl},	//(internal1_m1505_txMBl) tx
	{ 1609	,8	,1	, &internal1_m1505_txBl},	//(internal1_m1505_txBl) tx
	{ 1610	,8	,1	, &internal1_m1505_Speed0},	//(internal1_m1505_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1611	,8	,1	, &internal1_m1505_xz0},	//(internal1_m1505_xz0) xz0 - новое задание мм
	{ 1612	,8	,1	, &internal1_m1505_tz0},	//(internal1_m1505_tz0) tz0 - время защиты от нового задания сек
	{ 1613	,1	,1	, &internal1_m1505_Shift0},	//(internal1_m1505_Shift0) Shift0 - признак самохода
	{ 1614	,1	,1	, &internal1_m1505_ShCntlSp0},	//(internal1_m1505_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1615	,1	,1	, &internal1_m1505_ShiftControl},	//(internal1_m1505_ShiftControl) ShiftControl - признак самохода
	{ 1616	,1	,1	, &internal1_m693_q0},	//(internal1_m693_q0) q0 - внутренний параметр
	{ 1617	,8	,1	, &internal1_m1001_X0},	//(internal1_m1001_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1618	,8	,1	, &internal1_m1001_t0},	//(internal1_m1001_t0) время нахождения в зоне возврата
	{ 1619	,18	,1	, &internal1_m1001_BLDv0},	//(internal1_m1001_BLDv0) BlDv - Блокировка движения
	{ 1620	,8	,1	, &internal1_m1024_tx},	//(internal1_m1024_tx) tx - время накопленное сек
	{ 1621	,18	,1	, &internal1_m1024_y0},	//(internal1_m1024_y0) y0
	{ 1622	,8	,1	, &internal1_m1023_tx},	//(internal1_m1023_tx) tx - время накопленное сек
	{ 1623	,18	,1	, &internal1_m1023_y0},	//(internal1_m1023_y0) y0
	{ 1624	,3	,1	, &internal1_m1031_xptr},	//(internal1_m1031_xptr) указатель текущей позиции в массиве координат
	{ 1625	,8	,60	, &internal1_m1031_x0},	//(internal1_m1031_x0) x0 - массив мгновенных значений координат
	{ 1626	,8	,60	, &internal1_m1031_tim0},	//(internal1_m1031_tim0) tim0 - массив значений времени цикла
	{ 1627	,8	,1	, &internal1_m1031_sumtim},	//(internal1_m1031_sumtim) sumtim - время в пути
	{ 1628	,8	,1	, &internal1_m1031_StSpeed},	//(internal1_m1031_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1629	,8	,1	, &internal1_m1031_Vz0},	//(internal1_m1031_Vz0) Vz0 - предыдущая заданная скорость
	{ 1630	,3	,1	, &internal1_m1031_flRazg},	//(internal1_m1031_flRazg) признак разгона/торможения
	{ 1631	,8	,1	, &internal1_m1031_DelSp},	//(internal1_m1031_DelSp) DelSp - время переключения скоростей
	{ 1632	,8	,1	, &internal1_m1031_z0},	//(internal1_m1031_z0) z0 - точка прекращения движения
	{ 1633	,8	,1	, &internal1_m1031_txZS},	//(internal1_m1031_txZS) txZS
	{ 1634	,8	,1	, &internal1_m1031_tx},	//(internal1_m1031_tx) tx
	{ 1635	,8	,1	, &internal1_m1031_txd},	//(internal1_m1031_txd) txd
	{ 1636	,8	,1	, &internal1_m1031_txMBl},	//(internal1_m1031_txMBl) tx
	{ 1637	,8	,1	, &internal1_m1031_txBl},	//(internal1_m1031_txBl) tx
	{ 1638	,8	,1	, &internal1_m1031_Speed0},	//(internal1_m1031_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1639	,8	,1	, &internal1_m1031_xz0},	//(internal1_m1031_xz0) xz0 - новое задание мм
	{ 1640	,8	,1	, &internal1_m1031_tz0},	//(internal1_m1031_tz0) tz0 - время защиты от нового задания сек
	{ 1641	,1	,1	, &internal1_m1031_Shift0},	//(internal1_m1031_Shift0) Shift0 - признак самохода
	{ 1642	,1	,1	, &internal1_m1031_ShCntlSp0},	//(internal1_m1031_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1643	,1	,1	, &internal1_m1031_ShiftControl},	//(internal1_m1031_ShiftControl) ShiftControl - признак самохода
	{ 1644	,8	,1	, &internal1_m546_X0},	//(internal1_m546_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1645	,8	,1	, &internal1_m546_t0},	//(internal1_m546_t0) время нахождения в зоне возврата
	{ 1646	,18	,1	, &internal1_m546_BLDv0},	//(internal1_m546_BLDv0) BlDv - Блокировка движения
	{ 1647	,8	,1	, &internal1_m565_tx},	//(internal1_m565_tx) tx - время накопленное сек
	{ 1648	,18	,1	, &internal1_m565_y0},	//(internal1_m565_y0) y0
	{ 1649	,8	,1	, &internal1_m564_tx},	//(internal1_m564_tx) tx - время накопленное сек
	{ 1650	,18	,1	, &internal1_m564_y0},	//(internal1_m564_y0) y0
	{ 1651	,3	,1	, &internal1_m569_xptr},	//(internal1_m569_xptr) указатель текущей позиции в массиве координат
	{ 1652	,8	,150	, &internal1_m569_x0},	//(internal1_m569_x0) x0 - массив мгновенных значений координат
	{ 1653	,8	,150	, &internal1_m569_tim0},	//(internal1_m569_tim0) tim0 - массив значений времени цикла
	{ 1654	,8	,1	, &internal1_m569_sumtim},	//(internal1_m569_sumtim) sumtim - время в пути
	{ 1655	,8	,1	, &internal1_m569_StSpeed},	//(internal1_m569_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1656	,8	,1	, &internal1_m569_Vz0},	//(internal1_m569_Vz0) Vz0 - предыдущая заданная скорость
	{ 1657	,3	,1	, &internal1_m569_flRazg},	//(internal1_m569_flRazg) признак разгона/торможения
	{ 1658	,8	,1	, &internal1_m569_DelSp},	//(internal1_m569_DelSp) DelSp - время переключения скоростей
	{ 1659	,8	,1	, &internal1_m569_z0},	//(internal1_m569_z0) z0 - точка прекращения движения
	{ 1660	,8	,1	, &internal1_m569_txZS},	//(internal1_m569_txZS) txZS
	{ 1661	,8	,1	, &internal1_m569_tx},	//(internal1_m569_tx) tx
	{ 1662	,8	,1	, &internal1_m569_txd},	//(internal1_m569_txd) txd
	{ 1663	,8	,1	, &internal1_m569_txMBl},	//(internal1_m569_txMBl) tx
	{ 1664	,8	,1	, &internal1_m569_txBl},	//(internal1_m569_txBl) tx
	{ 1665	,8	,1	, &internal1_m569_Speed0},	//(internal1_m569_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1666	,8	,1	, &internal1_m569_xz0},	//(internal1_m569_xz0) xz0 - новое задание мм
	{ 1667	,8	,1	, &internal1_m569_tz0},	//(internal1_m569_tz0) tz0 - время защиты от нового задания сек
	{ 1668	,1	,1	, &internal1_m569_Shift0},	//(internal1_m569_Shift0) Shift0 - признак самохода
	{ 1669	,1	,1	, &internal1_m569_ShCntlSp0},	//(internal1_m569_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1670	,1	,1	, &internal1_m569_ShiftControl},	//(internal1_m569_ShiftControl) ShiftControl - признак самохода
	{ 1671	,1	,1	, &internal1_m690_q0},	//(internal1_m690_q0) q0 - внутренний параметр
	{ 1672	,8	,1	, &internal1_m176_X0},	//(internal1_m176_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1673	,8	,1	, &internal1_m176_t0},	//(internal1_m176_t0) время нахождения в зоне возврата
	{ 1674	,18	,1	, &internal1_m176_BLDv0},	//(internal1_m176_BLDv0) BlDv - Блокировка движения
	{ 1675	,3	,1	, &internal1_m201_xptr},	//(internal1_m201_xptr) указатель текущей позиции в массиве координат
	{ 1676	,8	,150	, &internal1_m201_x0},	//(internal1_m201_x0) x0 - массив мгновенных значений координат
	{ 1677	,8	,150	, &internal1_m201_tim0},	//(internal1_m201_tim0) tim0 - массив значений времени цикла
	{ 1678	,8	,1	, &internal1_m201_sumtim},	//(internal1_m201_sumtim) sumtim - время в пути
	{ 1679	,8	,1	, &internal1_m201_StSpeed},	//(internal1_m201_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1680	,8	,1	, &internal1_m201_Vz0},	//(internal1_m201_Vz0) Vz0 - предыдущая заданная скорость
	{ 1681	,3	,1	, &internal1_m201_flRazg},	//(internal1_m201_flRazg) признак разгона/торможения
	{ 1682	,8	,1	, &internal1_m201_DelSp},	//(internal1_m201_DelSp) DelSp - время переключения скоростей
	{ 1683	,8	,1	, &internal1_m201_z0},	//(internal1_m201_z0) z0 - точка прекращения движения
	{ 1684	,8	,1	, &internal1_m201_txZS},	//(internal1_m201_txZS) txZS
	{ 1685	,8	,1	, &internal1_m201_tx},	//(internal1_m201_tx) tx
	{ 1686	,8	,1	, &internal1_m201_txd},	//(internal1_m201_txd) txd
	{ 1687	,8	,1	, &internal1_m201_txMBl},	//(internal1_m201_txMBl) tx
	{ 1688	,8	,1	, &internal1_m201_txBl},	//(internal1_m201_txBl) tx
	{ 1689	,8	,1	, &internal1_m201_Speed0},	//(internal1_m201_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1690	,8	,1	, &internal1_m201_xz0},	//(internal1_m201_xz0) xz0 - новое задание мм
	{ 1691	,8	,1	, &internal1_m201_tz0},	//(internal1_m201_tz0) tz0 - время защиты от нового задания сек
	{ 1692	,1	,1	, &internal1_m201_Shift0},	//(internal1_m201_Shift0) Shift0 - признак самохода
	{ 1693	,1	,1	, &internal1_m201_ShCntlSp0},	//(internal1_m201_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1694	,1	,1	, &internal1_m201_ShiftControl},	//(internal1_m201_ShiftControl) ShiftControl - признак самохода
	{ 1695	,1	,1	, &internal1_m716_q0},	//(internal1_m716_q0) q0 - внутренний параметр
	{ 1696	,18	,1	, &internal1_m513_DvUp0},	//(internal1_m513_DvUp0) - есть команда на движение вперёд
	{ 1697	,18	,1	, &internal1_m513_DvDw0},	//(internal1_m513_DvDw0) - есть команда на движение назад
	{ 1698	,18	,1	, &internal1_m513_FDvUp0},	//(internal1_m513_FDvUp0) - есть команда на движение вперёд
	{ 1699	,18	,1	, &internal1_m513_FDvDw0},	//(internal1_m513_FDvDw0) - есть команда на движение назад
	{ 1700	,18	,1	, &internal1_m513_BlDv0},	//(internal1_m513_BlDv0) - была блокировка
	{ 1701	,18	,1	, &internal1_m513_Pkv0},	//(internal1_m513_Pkv0) Pkv - передний конечный выключатель
	{ 1702	,18	,1	, &internal1_m513_Pkav0},	//(internal1_m513_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1703	,18	,1	, &internal1_m513_Zkv0},	//(internal1_m513_Zkv0) Zkv - задний конечный выключатель
	{ 1704	,18	,1	, &internal1_m513_Zkav0},	//(internal1_m513_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1705	,8	,1	, &internal1_m513_txNm},	//(internal1_m513_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1706	,8	,1	, &internal1_m513_txSm},	//(internal1_m513_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1707	,8	,1	, &internal1_m513_txHr},	//(internal1_m513_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1708	,8	,1	, &internal1_m513_txLd},	//(internal1_m513_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1709	,18	,1	, &internal1_m513_fef},	//(internal1_m513_fef) fef
	{ 1710	,18	,1	, &internal1_m507_DvUp0},	//(internal1_m507_DvUp0) - есть команда на движение вперёд
	{ 1711	,18	,1	, &internal1_m507_DvDw0},	//(internal1_m507_DvDw0) - есть команда на движение назад
	{ 1712	,18	,1	, &internal1_m507_FDvUp0},	//(internal1_m507_FDvUp0) - есть команда на движение вперёд
	{ 1713	,18	,1	, &internal1_m507_FDvDw0},	//(internal1_m507_FDvDw0) - есть команда на движение назад
	{ 1714	,18	,1	, &internal1_m507_BlDv0},	//(internal1_m507_BlDv0) - была блокировка
	{ 1715	,18	,1	, &internal1_m507_Pkv0},	//(internal1_m507_Pkv0) Pkv - передний конечный выключатель
	{ 1716	,18	,1	, &internal1_m507_Pkav0},	//(internal1_m507_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1717	,18	,1	, &internal1_m507_Zkv0},	//(internal1_m507_Zkv0) Zkv - задний конечный выключатель
	{ 1718	,18	,1	, &internal1_m507_Zkav0},	//(internal1_m507_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1719	,8	,1	, &internal1_m507_txNm},	//(internal1_m507_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1720	,8	,1	, &internal1_m507_txSm},	//(internal1_m507_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1721	,8	,1	, &internal1_m507_txHr},	//(internal1_m507_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1722	,8	,1	, &internal1_m507_txLd},	//(internal1_m507_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1723	,18	,1	, &internal1_m507_fef},	//(internal1_m507_fef) fef
	{ 1724	,8	,1	, &internal1_m905_X0},	//(internal1_m905_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1725	,8	,1	, &internal1_m905_t0},	//(internal1_m905_t0) время нахождения в зоне возврата
	{ 1726	,18	,1	, &internal1_m905_BLDv0},	//(internal1_m905_BLDv0) BlDv - Блокировка движения
	{ 1727	,3	,1	, &internal1_m923_xptr},	//(internal1_m923_xptr) указатель текущей позиции в массиве координат
	{ 1728	,8	,80	, &internal1_m923_x0},	//(internal1_m923_x0) x0 - массив мгновенных значений координат
	{ 1729	,8	,80	, &internal1_m923_tim0},	//(internal1_m923_tim0) tim0 - массив значений времени цикла
	{ 1730	,8	,1	, &internal1_m923_sumtim},	//(internal1_m923_sumtim) sumtim - время в пути
	{ 1731	,8	,1	, &internal1_m923_StSpeed},	//(internal1_m923_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1732	,8	,1	, &internal1_m923_Vz0},	//(internal1_m923_Vz0) Vz0 - предыдущая заданная скорость
	{ 1733	,3	,1	, &internal1_m923_flRazg},	//(internal1_m923_flRazg) признак разгона/торможения
	{ 1734	,8	,1	, &internal1_m923_DelSp},	//(internal1_m923_DelSp) DelSp - время переключения скоростей
	{ 1735	,8	,1	, &internal1_m923_z0},	//(internal1_m923_z0) z0 - точка прекращения движения
	{ 1736	,8	,1	, &internal1_m923_txZS},	//(internal1_m923_txZS) txZS
	{ 1737	,8	,1	, &internal1_m923_tx},	//(internal1_m923_tx) tx
	{ 1738	,8	,1	, &internal1_m923_txd},	//(internal1_m923_txd) txd
	{ 1739	,8	,1	, &internal1_m923_txMBl},	//(internal1_m923_txMBl) tx
	{ 1740	,8	,1	, &internal1_m923_txBl},	//(internal1_m923_txBl) tx
	{ 1741	,8	,1	, &internal1_m923_Speed0},	//(internal1_m923_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1742	,8	,1	, &internal1_m923_xz0},	//(internal1_m923_xz0) xz0 - новое задание мм
	{ 1743	,8	,1	, &internal1_m923_tz0},	//(internal1_m923_tz0) tz0 - время защиты от нового задания сек
	{ 1744	,1	,1	, &internal1_m923_Shift0},	//(internal1_m923_Shift0) Shift0 - признак самохода
	{ 1745	,1	,1	, &internal1_m923_ShCntlSp0},	//(internal1_m923_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1746	,1	,1	, &internal1_m923_ShiftControl},	//(internal1_m923_ShiftControl) ShiftControl - признак самохода
	{ 1747	,8	,1	, &internal1_m1800_X0},	//(internal1_m1800_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1748	,8	,1	, &internal1_m1800_t0},	//(internal1_m1800_t0) время нахождения в зоне возврата
	{ 1749	,18	,1	, &internal1_m1800_BLDv0},	//(internal1_m1800_BLDv0) BlDv - Блокировка движения
	{ 1750	,8	,1	, &internal1_m1270_X0},	//(internal1_m1270_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1751	,8	,1	, &internal1_m1270_t0},	//(internal1_m1270_t0) время нахождения в зоне возврата
	{ 1752	,18	,1	, &internal1_m1270_BLDv0},	//(internal1_m1270_BLDv0) BlDv - Блокировка движения
	{ 1753	,1	,1	, &internal1_m688_q0},	//(internal1_m688_q0) q0 - внутренний параметр
	{ 1754	,8	,1	, &internal1_m1366_X0},	//(internal1_m1366_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1755	,8	,1	, &internal1_m1366_t0},	//(internal1_m1366_t0) время нахождения в зоне возврата
	{ 1756	,18	,1	, &internal1_m1366_BLDv0},	//(internal1_m1366_BLDv0) BlDv - Блокировка движения
	{ 1757	,8	,1	, &internal1_m1396_tx},	//(internal1_m1396_tx) tx - время накопленное сек
	{ 1758	,18	,1	, &internal1_m1396_y0},	//(internal1_m1396_y0) y0
	{ 1759	,8	,1	, &internal1_m1395_tx},	//(internal1_m1395_tx) tx - время накопленное сек
	{ 1760	,18	,1	, &internal1_m1395_y0},	//(internal1_m1395_y0) y0
	{ 1761	,3	,1	, &internal1_m1401_xptr},	//(internal1_m1401_xptr) указатель текущей позиции в массиве координат
	{ 1762	,8	,80	, &internal1_m1401_x0},	//(internal1_m1401_x0) x0 - массив мгновенных значений координат
	{ 1763	,8	,80	, &internal1_m1401_tim0},	//(internal1_m1401_tim0) tim0 - массив значений времени цикла
	{ 1764	,8	,1	, &internal1_m1401_sumtim},	//(internal1_m1401_sumtim) sumtim - время в пути
	{ 1765	,8	,1	, &internal1_m1401_StSpeed},	//(internal1_m1401_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1766	,8	,1	, &internal1_m1401_Vz0},	//(internal1_m1401_Vz0) Vz0 - предыдущая заданная скорость
	{ 1767	,3	,1	, &internal1_m1401_flRazg},	//(internal1_m1401_flRazg) признак разгона/торможения
	{ 1768	,8	,1	, &internal1_m1401_DelSp},	//(internal1_m1401_DelSp) DelSp - время переключения скоростей
	{ 1769	,8	,1	, &internal1_m1401_z0},	//(internal1_m1401_z0) z0 - точка прекращения движения
	{ 1770	,8	,1	, &internal1_m1401_txZS},	//(internal1_m1401_txZS) txZS
	{ 1771	,8	,1	, &internal1_m1401_tx},	//(internal1_m1401_tx) tx
	{ 1772	,8	,1	, &internal1_m1401_txd},	//(internal1_m1401_txd) txd
	{ 1773	,8	,1	, &internal1_m1401_txMBl},	//(internal1_m1401_txMBl) tx
	{ 1774	,8	,1	, &internal1_m1401_txBl},	//(internal1_m1401_txBl) tx
	{ 1775	,8	,1	, &internal1_m1401_Speed0},	//(internal1_m1401_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1776	,8	,1	, &internal1_m1401_xz0},	//(internal1_m1401_xz0) xz0 - новое задание мм
	{ 1777	,8	,1	, &internal1_m1401_tz0},	//(internal1_m1401_tz0) tz0 - время защиты от нового задания сек
	{ 1778	,1	,1	, &internal1_m1401_Shift0},	//(internal1_m1401_Shift0) Shift0 - признак самохода
	{ 1779	,1	,1	, &internal1_m1401_ShCntlSp0},	//(internal1_m1401_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1780	,1	,1	, &internal1_m1401_ShiftControl},	//(internal1_m1401_ShiftControl) ShiftControl - признак самохода
	{ 1781	,1	,1	, &internal1_m708_q0},	//(internal1_m708_q0) q0 - внутренний параметр
	{ 1782	,8	,1	, &internal1_m1814_tx},	//(internal1_m1814_tx) tx - время накопленное сек
	{ 1783	,18	,1	, &internal1_m1814_y0},	//(internal1_m1814_y0) y0
	{ 1784	,8	,1	, &internal1_m1818_tx},	//(internal1_m1818_tx) tx - время накопленное сек
	{ 1785	,18	,1	, &internal1_m1818_y0},	//(internal1_m1818_y0) y0
	{ 1786	,18	,1	, &internal1_m1803_DvUp0},	//(internal1_m1803_DvUp0) - есть команда на движение вперёд
	{ 1787	,18	,1	, &internal1_m1803_DvDw0},	//(internal1_m1803_DvDw0) - есть команда на движение назад
	{ 1788	,18	,1	, &internal1_m1803_FDvUp0},	//(internal1_m1803_FDvUp0) - есть команда на движение вперёд
	{ 1789	,18	,1	, &internal1_m1803_FDvDw0},	//(internal1_m1803_FDvDw0) - есть команда на движение назад
	{ 1790	,18	,1	, &internal1_m1803_BlDv0},	//(internal1_m1803_BlDv0) - была блокировка
	{ 1791	,18	,1	, &internal1_m1803_Pkv0},	//(internal1_m1803_Pkv0) Pkv - передний конечный выключатель
	{ 1792	,18	,1	, &internal1_m1803_Pkav0},	//(internal1_m1803_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1793	,18	,1	, &internal1_m1803_Zkv0},	//(internal1_m1803_Zkv0) Zkv - задний конечный выключатель
	{ 1794	,18	,1	, &internal1_m1803_Zkav0},	//(internal1_m1803_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1795	,8	,1	, &internal1_m1803_txNm},	//(internal1_m1803_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1796	,8	,1	, &internal1_m1803_txSm},	//(internal1_m1803_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1797	,8	,1	, &internal1_m1803_txHr},	//(internal1_m1803_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1798	,8	,1	, &internal1_m1803_txLd},	//(internal1_m1803_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1799	,18	,1	, &internal1_m1803_fef},	//(internal1_m1803_fef) fef
	{ 1800	,3	,1	, &internal1_m1822_xptr},	//(internal1_m1822_xptr) указатель текущей позиции в массиве координат
	{ 1801	,8	,20	, &internal1_m1822_x0},	//(internal1_m1822_x0) x0 - массив мгновенных значений координат
	{ 1802	,8	,20	, &internal1_m1822_tim0},	//(internal1_m1822_tim0) tim0 - массив значений времени цикла
	{ 1803	,8	,1	, &internal1_m1822_sumtim},	//(internal1_m1822_sumtim) sumtim - время в пути
	{ 1804	,8	,1	, &internal1_m1822_StSpeed},	//(internal1_m1822_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1805	,8	,1	, &internal1_m1822_Vz0},	//(internal1_m1822_Vz0) Vz0 - предыдущая заданная скорость
	{ 1806	,3	,1	, &internal1_m1822_flRazg},	//(internal1_m1822_flRazg) признак разгона/торможения
	{ 1807	,8	,1	, &internal1_m1822_DelSp},	//(internal1_m1822_DelSp) DelSp - время переключения скоростей
	{ 1808	,8	,1	, &internal1_m1822_z0},	//(internal1_m1822_z0) z0 - точка прекращения движения
	{ 1809	,8	,1	, &internal1_m1822_txZS},	//(internal1_m1822_txZS) txZS
	{ 1810	,8	,1	, &internal1_m1822_tx},	//(internal1_m1822_tx) tx
	{ 1811	,8	,1	, &internal1_m1822_txd},	//(internal1_m1822_txd) txd
	{ 1812	,8	,1	, &internal1_m1822_txMBl},	//(internal1_m1822_txMBl) tx
	{ 1813	,8	,1	, &internal1_m1822_txBl},	//(internal1_m1822_txBl) tx
	{ 1814	,8	,1	, &internal1_m1822_Speed0},	//(internal1_m1822_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1815	,8	,1	, &internal1_m1822_xz0},	//(internal1_m1822_xz0) xz0 - новое задание мм
	{ 1816	,8	,1	, &internal1_m1822_tz0},	//(internal1_m1822_tz0) tz0 - время защиты от нового задания сек
	{ 1817	,1	,1	, &internal1_m1822_Shift0},	//(internal1_m1822_Shift0) Shift0 - признак самохода
	{ 1818	,1	,1	, &internal1_m1822_ShCntlSp0},	//(internal1_m1822_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1819	,1	,1	, &internal1_m1822_ShiftControl},	//(internal1_m1822_ShiftControl) ShiftControl - признак самохода
	{ 1820	,8	,1	, &internal1_m1286_tx},	//(internal1_m1286_tx) tx - время накопленное сек
	{ 1821	,18	,1	, &internal1_m1286_y0},	//(internal1_m1286_y0) y0
	{ 1822	,8	,1	, &internal1_m1290_tx},	//(internal1_m1290_tx) tx - время накопленное сек
	{ 1823	,18	,1	, &internal1_m1290_y0},	//(internal1_m1290_y0) y0
	{ 1824	,1	,1	, &internal1_m698_q0},	//(internal1_m698_q0) q0 - внутренний параметр
	{ 1825	,1	,1	, &internal1_m663_q0},	//(internal1_m663_q0) q0 - внутренний параметр
	{ 1826	,18	,1	, &internal1_m1276_DvUp0},	//(internal1_m1276_DvUp0) - есть команда на движение вперёд
	{ 1827	,18	,1	, &internal1_m1276_DvDw0},	//(internal1_m1276_DvDw0) - есть команда на движение назад
	{ 1828	,18	,1	, &internal1_m1276_FDvUp0},	//(internal1_m1276_FDvUp0) - есть команда на движение вперёд
	{ 1829	,18	,1	, &internal1_m1276_FDvDw0},	//(internal1_m1276_FDvDw0) - есть команда на движение назад
	{ 1830	,18	,1	, &internal1_m1276_BlDv0},	//(internal1_m1276_BlDv0) - была блокировка
	{ 1831	,18	,1	, &internal1_m1276_Pkv0},	//(internal1_m1276_Pkv0) Pkv - передний конечный выключатель
	{ 1832	,18	,1	, &internal1_m1276_Pkav0},	//(internal1_m1276_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1833	,18	,1	, &internal1_m1276_Zkv0},	//(internal1_m1276_Zkv0) Zkv - задний конечный выключатель
	{ 1834	,18	,1	, &internal1_m1276_Zkav0},	//(internal1_m1276_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1835	,8	,1	, &internal1_m1276_txNm},	//(internal1_m1276_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1836	,8	,1	, &internal1_m1276_txSm},	//(internal1_m1276_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1837	,8	,1	, &internal1_m1276_txHr},	//(internal1_m1276_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1838	,8	,1	, &internal1_m1276_txLd},	//(internal1_m1276_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1839	,18	,1	, &internal1_m1276_fef},	//(internal1_m1276_fef) fef
	{ 1840	,3	,1	, &internal1_m1296_xptr},	//(internal1_m1296_xptr) указатель текущей позиции в массиве координат
	{ 1841	,8	,20	, &internal1_m1296_x0},	//(internal1_m1296_x0) x0 - массив мгновенных значений координат
	{ 1842	,8	,20	, &internal1_m1296_tim0},	//(internal1_m1296_tim0) tim0 - массив значений времени цикла
	{ 1843	,8	,1	, &internal1_m1296_sumtim},	//(internal1_m1296_sumtim) sumtim - время в пути
	{ 1844	,8	,1	, &internal1_m1296_StSpeed},	//(internal1_m1296_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1845	,8	,1	, &internal1_m1296_Vz0},	//(internal1_m1296_Vz0) Vz0 - предыдущая заданная скорость
	{ 1846	,3	,1	, &internal1_m1296_flRazg},	//(internal1_m1296_flRazg) признак разгона/торможения
	{ 1847	,8	,1	, &internal1_m1296_DelSp},	//(internal1_m1296_DelSp) DelSp - время переключения скоростей
	{ 1848	,8	,1	, &internal1_m1296_z0},	//(internal1_m1296_z0) z0 - точка прекращения движения
	{ 1849	,8	,1	, &internal1_m1296_txZS},	//(internal1_m1296_txZS) txZS
	{ 1850	,8	,1	, &internal1_m1296_tx},	//(internal1_m1296_tx) tx
	{ 1851	,8	,1	, &internal1_m1296_txd},	//(internal1_m1296_txd) txd
	{ 1852	,8	,1	, &internal1_m1296_txMBl},	//(internal1_m1296_txMBl) tx
	{ 1853	,8	,1	, &internal1_m1296_txBl},	//(internal1_m1296_txBl) tx
	{ 1854	,8	,1	, &internal1_m1296_Speed0},	//(internal1_m1296_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1855	,8	,1	, &internal1_m1296_xz0},	//(internal1_m1296_xz0) xz0 - новое задание мм
	{ 1856	,8	,1	, &internal1_m1296_tz0},	//(internal1_m1296_tz0) tz0 - время защиты от нового задания сек
	{ 1857	,1	,1	, &internal1_m1296_Shift0},	//(internal1_m1296_Shift0) Shift0 - признак самохода
	{ 1858	,1	,1	, &internal1_m1296_ShCntlSp0},	//(internal1_m1296_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1859	,1	,1	, &internal1_m1296_ShiftControl},	//(internal1_m1296_ShiftControl) ShiftControl - признак самохода
	{ 1860	,1	,1	, &internal1_m826_x0},	//(internal1_m826_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1861	,1	,1	, &internal1_m794_x0},	//(internal1_m794_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1862	,1	,1	, &internal1_m737_x0},	//(internal1_m737_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1863	,1	,1	, &internal1_m851_q0},	//(internal1_m851_q0) q0 - внутренний параметр
	{ 1864	,1	,1	, &internal1_m846_q0},	//(internal1_m846_q0) q0 - внутренний параметр
	{ 1865	,1	,1	, &internal1_m814_q0},	//(internal1_m814_q0) q0 - внутренний параметр
	{ 1866	,1	,1	, &internal1_m818_q0},	//(internal1_m818_q0) q0 - внутренний параметр
	{ 1867	,1	,1	, &internal1_m827_q0},	//(internal1_m827_q0) q0 - внутренний параметр
	{ 1868	,1	,1	, &internal1_m839_q0},	//(internal1_m839_q0) q0 - внутренний параметр
	{ 1869	,1	,1	, &internal1_m816_q0},	//(internal1_m816_q0) q0 - внутренний параметр
	{ 1870	,18	,1	, &internal1_m1338_DvUp0},	//(internal1_m1338_DvUp0) - есть команда на движение вперёд
	{ 1871	,18	,1	, &internal1_m1338_DvDw0},	//(internal1_m1338_DvDw0) - есть команда на движение назад
	{ 1872	,18	,1	, &internal1_m1338_FDvUp0},	//(internal1_m1338_FDvUp0) - есть команда на движение вперёд
	{ 1873	,18	,1	, &internal1_m1338_FDvDw0},	//(internal1_m1338_FDvDw0) - есть команда на движение назад
	{ 1874	,18	,1	, &internal1_m1338_BlDv0},	//(internal1_m1338_BlDv0) - была блокировка
	{ 1875	,18	,1	, &internal1_m1338_Pkv0},	//(internal1_m1338_Pkv0) Pkv - передний конечный выключатель
	{ 1876	,18	,1	, &internal1_m1338_Pkav0},	//(internal1_m1338_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1877	,18	,1	, &internal1_m1338_Zkv0},	//(internal1_m1338_Zkv0) Zkv - задний конечный выключатель
	{ 1878	,18	,1	, &internal1_m1338_Zkav0},	//(internal1_m1338_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1879	,8	,1	, &internal1_m1338_txNm},	//(internal1_m1338_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1880	,8	,1	, &internal1_m1338_txSm},	//(internal1_m1338_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1881	,8	,1	, &internal1_m1338_txHr},	//(internal1_m1338_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1882	,8	,1	, &internal1_m1338_txLd},	//(internal1_m1338_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1883	,18	,1	, &internal1_m1338_fef},	//(internal1_m1338_fef) fef
	{ 1884	,18	,1	, &internal1_m1329_DvUp0},	//(internal1_m1329_DvUp0) - есть команда на движение вперёд
	{ 1885	,18	,1	, &internal1_m1329_DvDw0},	//(internal1_m1329_DvDw0) - есть команда на движение назад
	{ 1886	,18	,1	, &internal1_m1329_FDvUp0},	//(internal1_m1329_FDvUp0) - есть команда на движение вперёд
	{ 1887	,18	,1	, &internal1_m1329_FDvDw0},	//(internal1_m1329_FDvDw0) - есть команда на движение назад
	{ 1888	,18	,1	, &internal1_m1329_BlDv0},	//(internal1_m1329_BlDv0) - была блокировка
	{ 1889	,18	,1	, &internal1_m1329_Pkv0},	//(internal1_m1329_Pkv0) Pkv - передний конечный выключатель
	{ 1890	,18	,1	, &internal1_m1329_Pkav0},	//(internal1_m1329_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1891	,18	,1	, &internal1_m1329_Zkv0},	//(internal1_m1329_Zkv0) Zkv - задний конечный выключатель
	{ 1892	,18	,1	, &internal1_m1329_Zkav0},	//(internal1_m1329_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1893	,8	,1	, &internal1_m1329_txNm},	//(internal1_m1329_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1894	,8	,1	, &internal1_m1329_txSm},	//(internal1_m1329_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1895	,8	,1	, &internal1_m1329_txHr},	//(internal1_m1329_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1896	,8	,1	, &internal1_m1329_txLd},	//(internal1_m1329_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1897	,18	,1	, &internal1_m1329_fef},	//(internal1_m1329_fef) fef
	{ 1898	,18	,1	, &internal1_m875_DvUp0},	//(internal1_m875_DvUp0) - есть команда на движение вперёд
	{ 1899	,18	,1	, &internal1_m875_DvDw0},	//(internal1_m875_DvDw0) - есть команда на движение назад
	{ 1900	,18	,1	, &internal1_m875_FDvUp0},	//(internal1_m875_FDvUp0) - есть команда на движение вперёд
	{ 1901	,18	,1	, &internal1_m875_FDvDw0},	//(internal1_m875_FDvDw0) - есть команда на движение назад
	{ 1902	,18	,1	, &internal1_m875_BlDv0},	//(internal1_m875_BlDv0) - была блокировка
	{ 1903	,18	,1	, &internal1_m875_Pkv0},	//(internal1_m875_Pkv0) Pkv - передний конечный выключатель
	{ 1904	,18	,1	, &internal1_m875_Pkav0},	//(internal1_m875_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1905	,18	,1	, &internal1_m875_Zkv0},	//(internal1_m875_Zkv0) Zkv - задний конечный выключатель
	{ 1906	,18	,1	, &internal1_m875_Zkav0},	//(internal1_m875_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1907	,8	,1	, &internal1_m875_txNm},	//(internal1_m875_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1908	,8	,1	, &internal1_m875_txSm},	//(internal1_m875_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1909	,8	,1	, &internal1_m875_txHr},	//(internal1_m875_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1910	,8	,1	, &internal1_m875_txLd},	//(internal1_m875_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1911	,18	,1	, &internal1_m875_fef},	//(internal1_m875_fef) fef
	{ 1912	,18	,1	, &internal1_m871_DvUp0},	//(internal1_m871_DvUp0) - есть команда на движение вперёд
	{ 1913	,18	,1	, &internal1_m871_DvDw0},	//(internal1_m871_DvDw0) - есть команда на движение назад
	{ 1914	,18	,1	, &internal1_m871_FDvUp0},	//(internal1_m871_FDvUp0) - есть команда на движение вперёд
	{ 1915	,18	,1	, &internal1_m871_FDvDw0},	//(internal1_m871_FDvDw0) - есть команда на движение назад
	{ 1916	,18	,1	, &internal1_m871_BlDv0},	//(internal1_m871_BlDv0) - была блокировка
	{ 1917	,18	,1	, &internal1_m871_Pkv0},	//(internal1_m871_Pkv0) Pkv - передний конечный выключатель
	{ 1918	,18	,1	, &internal1_m871_Pkav0},	//(internal1_m871_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1919	,18	,1	, &internal1_m871_Zkv0},	//(internal1_m871_Zkv0) Zkv - задний конечный выключатель
	{ 1920	,18	,1	, &internal1_m871_Zkav0},	//(internal1_m871_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1921	,8	,1	, &internal1_m871_txNm},	//(internal1_m871_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1922	,8	,1	, &internal1_m871_txSm},	//(internal1_m871_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1923	,8	,1	, &internal1_m871_txHr},	//(internal1_m871_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1924	,8	,1	, &internal1_m871_txLd},	//(internal1_m871_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1925	,18	,1	, &internal1_m871_fef},	//(internal1_m871_fef) fef
	{ 1926	,18	,1	, &internal1_m386_DvUp0},	//(internal1_m386_DvUp0) - есть команда на движение вперёд
	{ 1927	,18	,1	, &internal1_m386_DvDw0},	//(internal1_m386_DvDw0) - есть команда на движение назад
	{ 1928	,18	,1	, &internal1_m386_FDvUp0},	//(internal1_m386_FDvUp0) - есть команда на движение вперёд
	{ 1929	,18	,1	, &internal1_m386_FDvDw0},	//(internal1_m386_FDvDw0) - есть команда на движение назад
	{ 1930	,18	,1	, &internal1_m386_BlDv0},	//(internal1_m386_BlDv0) - была блокировка
	{ 1931	,18	,1	, &internal1_m386_Pkv0},	//(internal1_m386_Pkv0) Pkv - передний конечный выключатель
	{ 1932	,18	,1	, &internal1_m386_Pkav0},	//(internal1_m386_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1933	,18	,1	, &internal1_m386_Zkv0},	//(internal1_m386_Zkv0) Zkv - задний конечный выключатель
	{ 1934	,18	,1	, &internal1_m386_Zkav0},	//(internal1_m386_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1935	,8	,1	, &internal1_m386_txNm},	//(internal1_m386_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1936	,8	,1	, &internal1_m386_txSm},	//(internal1_m386_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1937	,8	,1	, &internal1_m386_txHr},	//(internal1_m386_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1938	,8	,1	, &internal1_m386_txLd},	//(internal1_m386_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1939	,18	,1	, &internal1_m386_fef},	//(internal1_m386_fef) fef
	{ 1940	,18	,1	, &internal1_m423_DvUp0},	//(internal1_m423_DvUp0) - есть команда на движение вперёд
	{ 1941	,18	,1	, &internal1_m423_DvDw0},	//(internal1_m423_DvDw0) - есть команда на движение назад
	{ 1942	,18	,1	, &internal1_m423_FDvUp0},	//(internal1_m423_FDvUp0) - есть команда на движение вперёд
	{ 1943	,18	,1	, &internal1_m423_FDvDw0},	//(internal1_m423_FDvDw0) - есть команда на движение назад
	{ 1944	,18	,1	, &internal1_m423_BlDv0},	//(internal1_m423_BlDv0) - была блокировка
	{ 1945	,18	,1	, &internal1_m423_Pkv0},	//(internal1_m423_Pkv0) Pkv - передний конечный выключатель
	{ 1946	,18	,1	, &internal1_m423_Pkav0},	//(internal1_m423_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1947	,18	,1	, &internal1_m423_Zkv0},	//(internal1_m423_Zkv0) Zkv - задний конечный выключатель
	{ 1948	,18	,1	, &internal1_m423_Zkav0},	//(internal1_m423_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1949	,8	,1	, &internal1_m423_txNm},	//(internal1_m423_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1950	,8	,1	, &internal1_m423_txSm},	//(internal1_m423_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1951	,8	,1	, &internal1_m423_txHr},	//(internal1_m423_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1952	,8	,1	, &internal1_m423_txLd},	//(internal1_m423_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1953	,18	,1	, &internal1_m423_fef},	//(internal1_m423_fef) fef
	{ 1954	,18	,1	, &internal1_m417_DvUp0},	//(internal1_m417_DvUp0) - есть команда на движение вперёд
	{ 1955	,18	,1	, &internal1_m417_DvDw0},	//(internal1_m417_DvDw0) - есть команда на движение назад
	{ 1956	,18	,1	, &internal1_m417_FDvUp0},	//(internal1_m417_FDvUp0) - есть команда на движение вперёд
	{ 1957	,18	,1	, &internal1_m417_FDvDw0},	//(internal1_m417_FDvDw0) - есть команда на движение назад
	{ 1958	,18	,1	, &internal1_m417_BlDv0},	//(internal1_m417_BlDv0) - была блокировка
	{ 1959	,18	,1	, &internal1_m417_Pkv0},	//(internal1_m417_Pkv0) Pkv - передний конечный выключатель
	{ 1960	,18	,1	, &internal1_m417_Pkav0},	//(internal1_m417_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1961	,18	,1	, &internal1_m417_Zkv0},	//(internal1_m417_Zkv0) Zkv - задний конечный выключатель
	{ 1962	,18	,1	, &internal1_m417_Zkav0},	//(internal1_m417_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1963	,8	,1	, &internal1_m417_txNm},	//(internal1_m417_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1964	,8	,1	, &internal1_m417_txSm},	//(internal1_m417_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1965	,8	,1	, &internal1_m417_txHr},	//(internal1_m417_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1966	,8	,1	, &internal1_m417_txLd},	//(internal1_m417_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1967	,18	,1	, &internal1_m417_fef},	//(internal1_m417_fef) fef
	{ 1968	,1	,1	, &internal1_m823_q0},	//(internal1_m823_q0) q0 - внутренний параметр
	{ 1969	,1	,1	, &internal1_m820_q0},	//(internal1_m820_q0) q0 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="du.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{756,"fEM_A1UC03RDU\0"}, 
{757,"dEM_A1UC05UDU\0"}, 
{758,"dEM_A1UC06UDU\0"}, 
{759,"dEM_A2UC06UDU\0"}, 
{760,"dEM_A2UC05UDU\0"}, 
{761,"fEM_A2UC03RDU\0"}, 
{762,"dEM_A3UC06UDU\0"}, 
{763,"dEM_A3UC05UDU\0"}, 
{764,"fEM_A3UC03RDU\0"}, 
{765,"dEM_A8UC06UDU\0"}, 
{766,"fEM_A8UC03RDU\0"}, 
{767,"dEM_A8UC05UDU\0"}, 
{768,"fEM_R0UV81RDU\0"}, 
{769,"fEM_R0UV82RDU\0"}, 
{770,"fEM_R0UV83RDU\0"}, 
{771,"fEM_R0UV84RDU\0"}, 
{772,"fEM_R0UV86RDU\0"}, 
{773,"fEM_R0UV85RDU\0"}, 
{774,"fEM_R0UV87RDU\0"}, 
{775,"fEM_A3UP03RDU\0"}, 
{776,"fEM_A3UP04RDU\0"}, 
{777,"fEM_A3UP43RDU\0"}, 
{778,"fEM_A3UP44RDU\0"}, 
{779,"fEM_A3UP53RDU\0"}, 
{780,"fEM_A3UP85RDU\0"}, 
{781,"fEM_A3UP88RDU\0"}, 
{782,"fEM_A3UP86RDU\0"}, 
{783,"fEM_B8UV01RDU\0"}, 
{784,"fEM_B8UV02RDU\0"}, 
{785,"fEM_B8UV03RDU\0"}, 
{786,"fEM_B8UL04RDU\0"}, 
{787,"iEM_A2UV03CDU\0"}, 
{788,"fEM_A2UV01RDU\0"}, 
{789,"fEM_A2UV02RDU\0"}, 
{790,"fEM_A1UV01RDU\0"}, 
{791,"fEM_A1UV02RDU\0"}, 
{792,"fEM_A1UC06RDU\0"}, 
{793,"fEM_A1UC05RDU\0"}, 
{794,"fEM_A1UL04RDU\0"}, 
{795,"fEM_A3UV01RDU\0"}, 
{796,"fEM_A3UV02RDU\0"}, 
{797,"fEM_A3UC06RDU\0"}, 
{798,"fEM_A3UC05RDU\0"}, 
{799,"fEM_A3UL04RDU\0"}, 
{800,"fEM_A3UP54RDU\0"}, 
{801,"fEM_A3UP87RDU\0"}, 
{802,"fEM_R0UL05RDU\0"}, 
{803,"fEM_R0UL20RDU\0"}, 
{804,"fEM_B8UV04RDU\0"}, 
{805,"fEM_B8UC06RDU\0"}, 
{806,"fEM_B8UC05RDU\0"}, 
{807,"fEM_A2UL05RDU\0"}, 
{808,"fEM_A2UL03RDU\0"}, 
{809,"fEM_A2UC06RDU\0"}, 
{810,"fEM_A2UC05RDU\0"}, 
{811,"fEM_A2UL04RDU\0"}, 
{812,"fEM_A1UL03RDU\0"}, 
{813,"fEM_A1UL05RDU\0"}, 
{814,"fEM_A3UL03RDU\0"}, 
{815,"fEM_A3UL05RDU\0"}, 
{816,"fEM_A1UC08RDU\0"}, 
{817,"fEM_A3UC08RDU\0"}, 
{818,"fEM_A1UC07RDU\0"}, 
{819,"fEM_A1UL01RDU\0"}, 
{820,"fEM_A3UC07RDU\0"}, 
{821,"fEM_A3UL01RDU\0"}, 
{822,"fEM_A2UC08RDU\0"}, 
{823,"fEM_A2UC07RDU\0"}, 
{824,"fEM_A2UL01RDU\0"}, 
{825,"fEM_B8UC01RDU\0"}, 
{826,"fEM_B8UL07RDU\0"}, 
{827,"fEM_B8UC02RDU\0"}, 
{828,"fEM_B8UL01RDU\0"}, 
{829,"fEM_B8UL05RDU\0"}, 
{830,"fEM_B8UL03RDU\0"}, 
{831,"fEM_B8UL06RDU\0"}, 
{832,"fEM_A9UZ03RDU\0"}, 
{833,"fEM_A9UZ04RDU\0"}, 
{834,"fEM_A9UZ05RDU\0"}, 
{835,"fEM_R4UZ04RDU\0"}, 
{836,"fEM_R4UZ03RDU\0"}, 
{837,"fEM_R4UZ05RDU\0"}, 
{838,"fEM_A5UZ03RDU\0"}, 
{839,"fEM_A5UZ04RDU\0"}, 
{840,"fEM_A5UZ05RDU\0"}, 
{841,"fEM_A4UZ03RDU\0"}, 
{842,"fEM_A4UZ04RDU\0"}, 
{843,"fEM_A4UZ05RDU\0"}, 
{844,"fEM_A6UZ03RDU\0"}, 
{845,"fEM_A6UZ04RDU\0"}, 
{846,"fEM_A6UZ05RDU\0"}, 
{847,"fEM_R1UZ03RDU\0"}, 
{848,"fEM_R1UZ04RDU\0"}, 
{849,"fEM_R1UZ05RDU\0"}, 
{850,"fEM_R0UL04RDU\0"}, 
{851,"fEM_R0UL06RDU\0"}, 
{852,"fEM_R0UL03RDU\0"}, 
{853,"fEM_R0UL17RDU\0"}, 
{854,"fEM_R0UL19RDU\0"}, 
{855,"fEM_R0UL07RDU\0"}, 
{856,"fEM_R0UL18RDU\0"}, 
{857,"fEM_R0UL16RDU\0"}, 
{858,"fEM_R0UL02RDU\0"}, 
{859,"fEM_R0UN08RDU\0"}, 
{860,"fEM_R0UN07RDU\0"}, 
{861,"fEM_R0UN06RDU\0"}, 
{862,"fEM_R0UN05RDU\0"}, 
{863,"fEM_R0UN04RDU\0"}, 
{864,"fEM_R0UN03RDU\0"}, 
{865,"fEM_R0UN02RDU\0"}, 
{866,"fEM_R0UN01RDU\0"}, 
{867,"fEM_A2UC82RDU\0"}, 
{868,"fEM_A2UC83RDU\0"}, 
{869,"fEM_A1UC83RDU\0"}, 
{870,"fEM_A2UC81RDU\0"}, 
{871,"fEM_A1UC81RDU\0"}, 
{872,"fEM_A1UC82RDU\0"}, 
{873,"fEM_A2UL83RDU\0"}, 
{874,"fEM_A3UC81RDU\0"}, 
{875,"fEM_A3UC82RDU\0"}, 
{876,"fEM_R0UN80RDU\0"}, 
{877,"iEM_A2UV01IDU\0"}, 
{878,"iEM_A2UV02IDU\0"}, 
{879,"iEM_A1UV01IDU\0"}, 
{880,"iEM_A1UV02IDU\0"}, 
{881,"iEM_A1UV03IDU\0"}, 
{882,"iEM_A3UV01IDU\0"}, 
{883,"iEM_A3UV02IDU\0"}, 
{884,"lEM_R0MD01LC1\0"}, 
{885,"fEM_A3UC09RDU\0"}, 
{886,"fEM_A2UC02RDU\0"}, 
{887,"fEM_A1UC02RDU\0"}, 
{888,"fEM_A3UC02RDU\0"}, 
{889,"fEM_R0UL21RDU\0"}, 
{890,"fEM_R0UN09RDU\0"}, 
{891,"fEM_R0UN11RDU\0"}, 
{892,"fEM_R0UN12RDU\0"}, 
{893,"fEM_R0UN13RDU\0"}, 
{894,"fEM_R0UN14RDU\0"}, 
{895,"fEM_R0UN16RDU\0"}, 
{896,"fEM_R0UN17RDU\0"}, 
{897,"fEM_R0UN18RDU\0"}, 
{898,"fEM_R0UN19RDU\0"}, 
{899,"fEM_R0UN70LDU\0"}, 
{900,"fEM_R0UN71LDU\0"}, 
{901,"fEM_R0UN72LDU\0"}, 
{902,"fEM_R0UN73LDU\0"}, 
{903,"fEM_R0UN74LDU\0"}, 
{904,"fEM_R0UN75LDU\0"}, 
{905,"fEM_R0UN80LDU\0"}, 
{906,"fEM_R0UN81LDU\0"}, 
{907,"fEM_R0UN82LDU\0"}, 
{908,"fEM_R0UN83LDU\0"}, 
{909,"fEM_R0UN84LDU\0"}, 
{910,"fEM_R0UN85LDU\0"}, 
{911,"fEM_R0UT20RDU\0"}, 
{912,"fEM_R0UN25RDU\0"}, 
{913,"fEM_R0UN15RDU\0"}, 
{914,"fEM_R0UN26RDU\0"}, 
{915,"fEM_R0UN27RDU\0"}, 
{916,"fEM_R0UN24RDU\0"}, 
{917,"fEM_R0UL25RDU\0"}, 
{918,"fEM_R0UL01RSS\0"}, 
{919,"fEM_R0UL02RSS\0"}, 
{920,"fEM_R0UN03RSS\0"}, 
{921,"fEM_R7UI76RDU\0"}, 
{922,"fEM_R0UL00RDU\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_DU[]={  // 
	{&R0MD34LP1,1,0},	//( - , DU) Кнопка КВИТИРОВАТЬ
	{&A2MD12LP1,1,1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
	{&A2MD11LP1,1,2},	//( - , DU) Кнопка ПУСК РБ1
	{&B2MD12LP1,1,3},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	{&A1MD11LP1,1,4},	//( - , DU) Кнопка ПУСК ББ1
	{&R0MW17LP1,1,5},	//( - , DU) Переключатель АВТ/Р
	{&B1MD11LP1,1,6},	//( - , DU) Кнопка ПУСК ББ2
	{&B1MD12LP1,1,7},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	{&B2MD11LP1,1,8},	//( - , DU) Кнопка ПУСК РБ2
	{&C2MD31LP1,1,9},	//( - , DU) Кнопка СБРОС РБ
	{&B3MD12LP1,1,10},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
	{&B3MD11LP1,1,11},	//( - , DU) Кнопка ПУСК ИС2
	{&R0MD11LP2,1,12},	//( - , DU) Кнопка Пуск проверки схем сброса
	{&C1MD31LP1,1,13},	//( - , DU) Кнопка СБРОС ББ
	{&C1MD31LP2,1,14},	//( - , DU) Кнопка СБРОС ББ
	{&A3MD12LP1,1,15},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
	{&A3MD11LP1,1,16},	//( - , DU) Кнопка ПУСК ИС1
	{&R0MD33LP1,1,17},	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
	{&A1MD12LP1,1,18},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
	{&B1MC01LC1,1,19},	//( - , DU) Настроить энкодер ББ2
	{&B1MC01LC2,1,20},	//( - , DU) Настроить энкодер ББ2
	{&A1MC01LC1,1,21},	//( - , DU) Настроить энкодер ББ1
	{&A1MC01LC2,1,22},	//( - , DU) Настроить энкодер ББ1
	{&B2MC01LC1,1,23},	//( - , DU) Настроить энкодер РБ2
	{&B2MC01LC2,1,24},	//( - , DU) Настроить энкодер РБ2
	{&A2MC01LC1,1,25},	//( - , DU) Настроить энкодер РБ1
	{&A2MC01LC2,1,26},	//( - , DU) Настроить энкодер РБ1
	{&B3MC01LC1,1,27},	//( - , DU) Настроить энкодер ИС2
	{&B3MC01LC2,1,28},	//( - , DU) Настроить энкодер ИС2
	{&A3MC01LC1,1,29},	//( - , DU) Настроить энкодер ИС1
	{&A3MC01LC2,1,30},	//( - , DU) Настроить энкодер ИС1
	{&B8MC01LC1,1,31},	//( - , DU) Настроить энкодер АЗ2
	{&B8MC01LC2,1,32},	//( - , DU) Настроить энкодер АЗ2
	{&A8MC01LC1,1,33},	//( - , DU) Настроить энкодер ДС2
	{&A8MC01LC2,1,34},	//( - , DU) Настроить энкодер ДС2
	{&R0MD11LP1,1,35},	//( - , DU) Кнопка ПУСК
	{&R4MD11LP2,1,36},	//( - , DU) Кнопка ВПЕРЁД  (тележки)
	{&R4MD31LP2,1,37},	//( - , DU) Кнопка СТОП  (тележки)
	{&R4MD21LP2,1,38},	//( - , DU) Кнопка НАЗАД  (тележки)
	{&R0MW13LP2,1,39},	//( - , DU) Переключатель СЕТЬ
	{&R0MD32LP1,1,40},	//( - , DU) Кнопка СПУСК
	{&R0MD31LP1,1,41},	//( - , DU) Кнопка СТОП
	{&R0NE01LDU,1,42},	//( - , DU) Потеря связи с БАЗ1
	{&R0NE02LDU,1,43},	//( - , DU) Потеря связи с БАЗ2
	{&R0NE08LDU,1,44},	//( - , DU) Потеря связи с ОПУ
	{&lEM_R0MD01LC1,1,45},	//( - , DU) Ручное управление ОРР
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DU[]={  // 
	{&B7AZ03LDU,1,0},	//( - , DU) Несанкционированное включение обдува АЗ2
	{&A7AZ03LDU,1,1},	//( - , DU) Несанкционированное включение обдува АЗ1
	{&B7AS31LDU,1,2},	//( - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
	{&A7AS31LDU,1,3},	//( - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
	{&B2VS21LDU,1,4},	//( - , DU) Движение РБ2 в сторону НУ
	{&B2VS11LDU,1,5},	//( - , DU) Движение РБ2 в сторону ВУ
	{&R0VP73LDU,1,6},	//( - , DU) ПС давления для РУ
	{&R0IS02LDU,1,7},	//( - K30VDSR, DU) Разрешение ввода от имитатора
	{&R0IS01LDU,1,8},	//( - K29VDSR, DU) Признак работы с имитатором
	{&A3IS11LDU,1,9},	//( - K01VDSR, DU) Приход на ВУ ИС1
	{&B3IS11LDU,1,10},	//( - K03VDSR, DU) Приход на ВУ ИС2
	{&R0VW13LDU,1,11},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
	{&R0VW23LDU,1,12},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VX09LDU,1,13},	//( - , DU) Индикация регулятор мощности включен/отключен
	{&R0VS17LDU,1,14},	//( - , DU) Индикация выбора АВТОМАТ
	{&A2VS32LDU,1,15},	//( - , DU) Индикация  СБРОС РБ1
	{&B2VS32LDU,1,16},	//( - , DU) Индикация  СБРОС РБ2
	{&A3VX01LDU,1,17},	//( - , DU) Индикация Выстрел ИС1
	{&B3VX01LDU,1,18},	//( - , DU) Индикация Выстрел ИС2
	{&R0VS18LDU,1,19},	//( - , DU) Индикация  Проверка схем сброса
	{&A3VZ15LZ2,1,20},	//( - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{&B2IS33LDU,1,21},	//( - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
	{&B3IS31LDU,1,22},	//( - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
	{&B3IS33LDU,1,23},	//( - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
	{&B3IS35LDU,1,24},	//( - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
	{&B4IS10LDU,1,25},	//( - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
	{&R3IS11LDU,1,26},	//( - K17VDSR, DU) Приход на ВУ гомогенных дверей
	{&R3IS21LDU,1,27},	//( - K18VDSR, DU) Приход на НУ гомогенных дверей
	{&R0AB03LDU,1,28},	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
	{&R0AB05LDU,1,29},	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
	{&A2AB15LDU,1,30},	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{&B2AB15LDU,1,31},	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{&R0VX02LDU,1,32},	//( - , DU) Импульс разрешен
	{&R0EE03LDU,1,33},	//( - , DU) ВПИС ИС
	{&R0AB07LDU,1,34},	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{&R0VZ71LDU,1,35},	//( - , DU) Обобщенный сигнал АЗ
	{&A2IS33LDU,1,36},	//( - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	{&A3IS31LDU,1,37},	//( - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	{&A3IS33LDU,1,38},	//( - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	{&A3IS35LDU,1,39},	//( - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	{&A4IS10LDU,1,40},	//( - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	{&A1VN71LZ1,1,41},	//( - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{&A1VN71LZ2,1,42},	//( - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{&A1AB19LDU,1,43},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{&R0AD14LZ1,1,44},	//( - K20VDSR, DU) Имитация срабатывания АЗ от II УР
	{&R0AD14LZ2,1,45},	//( - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	{&A3VZ13LZ2,1,46},	//( - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{&A3VZ13LZ1,1,47},	//( - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{&A3VZ15LZ1,1,48},	//( - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{&R0VX01LDU,1,49},	//( - , DU) ДО ИМПУЛЬСА
	{&R0AB04LDU,1,50},	//( - , DU) Нарушение времени срабатывания верхней АС II УР
	{&R0AB06LDU,1,51},	//( - , DU) Нарушение времени задержки от ВУ РБ
	{&R0AB02LDU,1,52},	//( - , DU) Нарушение времени задержки ИНИ
	{&R0VX03LDU,1,53},	//( - , DU) Готовность 2 мин
	{&B3AB05LDU,1,54},	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	{&B3AB06LDU,1,55},	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	{&B3AB09LDU,1,56},	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
	{&B3AB10LDU,1,57},	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
	{&B3AB11LDU,1,58},	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	{&B3AB12LDU,1,59},	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{&B3AB14LDU,1,60},	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	{&B3AB16LDU,1,61},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
	{&B3AB17LDU,1,62},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
	{&B3AB18LDU,1,63},	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	{&B3AB20LDU,1,64},	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
	{&A2AD31LDU,1,65},	//( - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
	{&B2AD31LDU,1,66},	//( - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
	{&A1AD31LDU,1,67},	//( - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
	{&B1AD31LDU,1,68},	//( - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
	{&B9IS11LDU,1,69},	//( - K25VDSR, DU) Приход на ВУ НИ ДС2
	{&B9IS21LDU,1,70},	//( - K26VDSR, DU) Приход на НУ НИ ДС2
	{&A9AZ03LDU,1,71},	//( - , DU) Несанкционированное перемещение НИ ДС1
	{&A9AB01LDU,1,72},	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
	{&A9AB02LDU,1,73},	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
	{&B9AZ03LDU,1,74},	//( - , DU) Несанкционированное перемещение НИ ДС2
	{&B9AB01LDU,1,75},	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
	{&B9AB02LDU,1,76},	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
	{&R0AB01LDU,1,77},	//( - , DU) Режим проверки разрешён
	{&A3IS22LDU,1,78},	//( - K02VDSR, DU) Приход на НУП ИС1
	{&B3IS22LDU,1,79},	//( - K04VDSR, DU) Приход на НУП ИС2
	{&A2IS11LDU,1,80},	//( - K11VDSR, DU) Приход на ВУ РБ1-СТР
	{&B2IS11LDU,1,81},	//( - K11VDSR, DU) Приход на ВУ РБ2-СТР
	{&A4VS12LDU,1,82},	//( - , DU) Движение НИ1 в сторону ВУ
	{&A4VS22LDU,1,83},	//( - , DU) Движение НИ1 в сторону НУ
	{&B4VS12LDU,1,84},	//( - , DU) Движение НИ2 в сторону ВУ
	{&B4VS22LDU,1,85},	//( - , DU) Движение НИ2 в сторону НУ
	{&A9IS11LDU,1,86},	//( - K23VDSR, DU) Приход на ВУ НИ ДС1
	{&A9IS21LDU,1,87},	//( - K24VDSR, DU) Приход на НУ НИ ДС1
	{&psz21,1,88},	//( - , DU) 
	{&psz22,1,89},	//( - , DU) 
	{&psz23,1,90},	//( - , DU) 
	{&psz24,1,91},	//( - , DU) 
	{&psz25,1,92},	//( - , DU) 
	{&psz26,1,93},	//( - , DU) 
	{&psz27,1,94},	//( - , DU) 
	{&psz28,1,95},	//( - , DU) 
	{&B1IS11LDU,1,96},	//( - K08VDSR, DU) Приход на ВУ ББ2
	{&A1IS11LDU,1,97},	//( - K08VDSR, DU) Приход на ВУ ББ1
	{&TestDiagnDU,1,98},	//( - , DU) Неисправность от
	{&psz1,1,99},	//( - , DU) 
	{&psz2,1,100},	//( - , DU) 
	{&psz3,1,101},	//( - , DU) 
	{&psz4,1,102},	//( - , DU) 
	{&psz5,1,103},	//( - , DU) 
	{&psz6,1,104},	//( - , DU) 
	{&psz7,1,105},	//( - , DU) 
	{&psz8,1,106},	//( - , DU) 
	{&psz9,1,107},	//( - , DU) 
	{&psz10,1,108},	//( - , DU) 
	{&psz11,1,109},	//( - , DU) 
	{&psz12,1,110},	//( - , DU) 
	{&psz13,1,111},	//( - , DU) 
	{&psz14,1,112},	//( - , DU) 
	{&B3VP52LDU,1,113},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{&B3VP82LDU,1,114},	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
	{&A3VP82LDU,1,115},	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
	{&A0VE01LDU,1,116},	//( - , DU) Напряжение в системы АЗ1 подано
	{&B0VE01LDU,1,117},	//( - , DU) Напряжение в системы АЗ2 подано
	{&A0VP01LDU,1,118},	//( - , DU) Давление в системы АЗ1 подано
	{&B0VP01LDU,1,119},	//( - , DU) Давление в системы АЗ2 подано
	{&A0VN01LDU,1,120},	//( - , DU) Каналы АЗ1 проверены
	{&B0VN01LDU,1,121},	//( - , DU) Каналы АЗ2 проверены
	{&A0VS11LDU,1,122},	//( - , DU) АЗ1 готова к работе
	{&B0VS11LDU,1,123},	//( - , DU) АЗ2 готова к работе
	{&R0EE02LDU,1,124},	//( - , DU) Питание  АКНП  отключить
	{&A3VP42LDU,1,125},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
	{&A3VP52LDU,1,126},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{&B3VP42LDU,1,127},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
	{&R2ZAV,1,128},	//( - , DU) 
	{&A5ZAV,1,129},	//( - , DU) 
	{&B8ZAV,1,130},	//( - , DU) 
	{&A2ZAV,1,131},	//( - , DU) Завершение РБ1,2
	{&A8ZAV,1,132},	//( - , DU) 
	{&A9ZAV,1,133},	//( - , DU) Завершение НИ ДС1(2)
	{&R4ABL,1,134},	//( - , DU) Блокировка тележки -
	{&A4UP,1,135},	//( - , DU) 
	{&A4DW,1,136},	//( - , DU) 
	{&R0AB14LDU,1,137},	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{&R0AB15LDU,1,138},	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{&A3IS12LDU,1,139},	//( - , DU) Приход на ВУ штока ИС1
	{&B3IS12LDU,1,140},	//( - , DU) Приход на ВУ штока ИС2
	{&A1ZAV,1,141},	//( - , DU) 
	{&A3ZAV,1,142},	//( - , DU) 
	{&B1AB19LDU,1,143},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{&R0AB16LDU,1,144},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{&R0VS11LDU,1,145},	//( - , DU) РУ не готова к работе
	{&B6AB05LDU,1,146},	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
	{&R0AB08LDU,1,147},	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
	{&R0AB09LDU,1,148},	//( - , DU) Ошибка в заданной координате ББ1
	{&R0AB10LDU,1,149},	//( - , DU) Ошибка в заданной координате ББ2
	{&R0AB11LDU,1,150},	//( - , DU) Ошибка в заданной координате  ИС1
	{&R0AB12LDU,1,151},	//( - , DU) Ошибка в заданной координате  ИС2
	{&R0AB13LDU,1,152},	//( - , DU) Ошибка в заданной координате  АЗ2
	{&A4ZAV,1,153},	//( - , DU) 
	{&A6ZAV,1,154},	//( - , DU) 
	{&R0VL22LDU,1,155},	//( - , DU) Конец программы 200сек
	{&R0VL23LDU,1,156},	//( - , DU) Конец программы 20мин
	{&A3AB19LDU,1,157},	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
	{&B3AB19LDU,1,158},	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
	{&A3EE03LDU,1,159},	//( - , DU) ВПИС ИС1
	{&B3EE03LDU,1,160},	//( - , DU) ВПИС ИС2
	{&B3AB15LDU,1,161},	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
	{&R5IS21LDU,1,162},	//( - K26VDSR, DU) Приход на НУ ворот отстойной зоны
	{&R5VS22LDU,1,163},	//( - , DU) Движение ворот отстойной зоны к закрыты
	{&R5VS12LDU,1,164},	//( - , DU) Движение ворот отстойной зоны к открыты
	{&R3VS22LDU,1,165},	//( - , DU) Движение гомогенных дверей к закрыты
	{&R3VS12LDU,1,166},	//( - , DU) Движение гомогенных дверей к открыты
	{&A3AB13LDU,1,167},	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
	{&B3AB13LDU,1,168},	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{&R0AB17LDU,1,169},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{&R0AB18LDU,1,170},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{&A3AB15LDU,1,171},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	{&R0AB20LDU,1,172},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	{&R0AB19LDU,1,173},	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
	{&B8IS12LDU,1,174},	//( - K21VDSR, DU) Приход на ВУ2 АЗ2
	{&B8IS21LDU,1,175},	//( - K20VDSR, DU) Приход на НУ1 АЗ2
	{&A6AB07LDU,1,176},	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
	{&A6AB06LDU,1,177},	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
	{&R4IS11LDU,1,178},	//( - K05VDSR, DU) Приход на ВУ1 тележки
	{&B2IS12LDU,1,179},	//( - K10VDSR, DU) Магнит РБ2 зацеплен
	{&B1IS12LDU,1,180},	//( - K07VDSR, DU) Магнит ББ2 зацеплен
	{&A2IS12LDU,1,181},	//( - K10VDSR, DU) Магнит РБ1 зацеплен
	{&A1IS12LDU,1,182},	//( - K07VDSR, DU) Магнит ББ1 зацеплен
	{&B5AB04LDU,1,183},	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
	{&A5AB04LDU,1,184},	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
	{&B4AB02LDU,1,185},	//( - , DU) Блокировка движения НИ2 - Нет перемещения
	{&B4AB01LDU,1,186},	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
	{&B4AZ03LDU,1,187},	//( - , DU) Несанкционированное перемещение НИ2
	{&A4AB02LDU,1,188},	//( - , DU) Блокировка движения НИ1 - Нет перемещения
	{&A4AB01LDU,1,189},	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
	{&A4AZ03LDU,1,190},	//( - , DU) Несанкционированное перемещение НИ1
	{&B4IS21LDU,1,191},	//( - K32VDSR, DU) Приход на НУ НИ2
	{&R4AB18LDU,1,192},	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	{&R4AD20LDU,1,193},	//( - K14FDSR, DU) Перемещение тележки назад
	{&A5VS22LDU,1,194},	//( - K12VDSR, DU) Движение НЛ1 в сторону НУ
	{&A5VS12LDU,1,195},	//( - K11VDSR, DU) Движение НЛ1 в сторону ВУ
	{&B5VS22LDU,1,196},	//( - K15VDSR, DU) Движение НЛ2 в сторону НУ
	{&B5VS12LDU,1,197},	//( - K14VDSR, DU) Движение НЛ2 в сторону ВУ
	{&A5IS11LDU,1,198},	//( - K11VDSR, DU) Приход на ВУ НЛ1
	{&A5IS21LDU,1,199},	//( - K12VDSR, DU) Приход на НУ НЛ1
	{&B5IS11LDU,1,200},	//( - K15VDSR, DU) Приход на ВУ НЛ2
	{&B5IS21LDU,1,201},	//( - K16VDSR, DU) Приход на НУ НЛ2
	{&A5AZ03LDU,1,202},	//( - , DU) Несанкционированное перемещение НЛ1
	{&A5AB01LDU,1,203},	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
	{&A5AB02LDU,1,204},	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
	{&B5AZ03LDU,1,205},	//( - , DU) Несанкционированное перемещение НЛ2
	{&B5AB01LDU,1,206},	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
	{&B5AB02LDU,1,207},	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
	{&A4IS21LDU,1,208},	//( - K15VDSR, DU) Приход на НУ НИ1
	{&B8AB04LDU,1,209},	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
	{&B8AB08LDU,1,210},	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
	{&B8AB09LDU,1,211},	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
	{&B8AB10LDU,1,212},	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
	{&B8AB11LDU,1,213},	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
	{&B8AB12LDU,1,214},	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
	{&B8AB13LDU,1,215},	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
	{&B8AB14LDU,1,216},	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
	{&B8AB02LDU,1,217},	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
	{&A8VS12LDU,1,218},	//( - , DU) Движение ДС2 в сторону ВУ
	{&A8AB06LDU,1,219},	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
	{&A8AB07LDU,1,220},	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
	{&A8AB05LDU,1,221},	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
	{&A8VS22LDU,1,222},	//( - , DU) Движение ДС2 в сторону НУ
	{&A8AZ03LDU,1,223},	//( - , DU) Несанкционированное перемещение ДС2
	{&B8IS22LDU,1,224},	//( - K22VDSR, DU) Приход на НУ2 АЗ2
	{&A6AB08LDU,1,225},	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
	{&A6AB09LDU,1,226},	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
	{&B6AB06LDU,1,227},	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
	{&B6AB07LDU,1,228},	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
	{&B6AB08LDU,1,229},	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
	{&B6AB09LDU,1,230},	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
	{&A6AB05LDU,1,231},	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
	{&B8VS12LDU,1,232},	//( - , DU) Движение АЗ2 в сторону ВУ
	{&B8AB06LDU,1,233},	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
	{&B8AB07LDU,1,234},	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
	{&B8AB05LDU,1,235},	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
	{&B8VS22LDU,1,236},	//( - , DU) Движение АЗ2 в сторону НУ
	{&B8AZ03LDU,1,237},	//( - , DU) Несанкционированное перемещение АЗ2
	{&B8IS11LDU,1,238},	//( - K19VDSR, DU) Приход на ВУ1 АЗ2
	{&B8AB01LDU,1,239},	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
	{&A6IS11LDU,1,240},	//( - K09VDSR, DU) Приход на ВУ БЗ1
	{&A6IS21LDU,1,241},	//( - K10VDSR, DU) Приход на НУ БЗ1
	{&B6IS11LDU,1,242},	//( - K13VDSR, DU) Приход на ВУ БЗ2
	{&B6IS21LDU,1,243},	//( - K14VDSR, DU) Приход на НУ БЗ2
	{&A6VS22LDU,1,244},	//( - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
	{&A6VS12LDU,1,245},	//( - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
	{&B6VS22LDU,1,246},	//( - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
	{&B6VS12LDU,1,247},	//( - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
	{&A6AZ03LDU,1,248},	//( - , DU) Несанкционированное перемещение БЗ1
	{&A6AB01LDU,1,249},	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
	{&A6AB02LDU,1,250},	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
	{&B6AZ03LDU,1,251},	//( - , DU) Несанкционированное перемещение БЗ2
	{&B6AB01LDU,1,252},	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
	{&B6AB02LDU,1,253},	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
	{&A1IS21LDU,1,254},	//( - K09VDSR, DU) Приход на НУ ББ1
	{&A2IS21LDU,1,255},	//( - K12VDSR, DU) Приход на НУ РБ1-СС
	{&A3IS21LDU,1,256},	//( - K13VDSR, DU) Приход на НУ ИС1
	{&B1IS21LDU,1,257},	//( - K09VDSR, DU) Приход на НУ ББ2
	{&B2IS21LDU,1,258},	//( - K12VDSR, DU) Приход на НУ РБ2-СС
	{&B3IS21LDU,1,259},	//( - K13VDSR, DU) Приход на НУ ИС2
	{&R0ES01LDU,1,260},	//( - , DU) ОРР не в исходном состоянии
	{&R4AB04LDU,1,261},	//( - , DU) Блокировка движения тележки - Превышение времени движения
	{&R4AB05LDU,1,262},	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
	{&R4AB06LDU,1,263},	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
	{&R4AB07LDU,1,264},	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
	{&R4AB08LDU,1,265},	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	{&R4AB09LDU,1,266},	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
	{&R4AB10LDU,1,267},	//( - , DU) Блокировка тележки - не открыта биологическая защита
	{&R4AB11LDU,1,268},	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
	{&R4AB12LDU,1,269},	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
	{&A4IS11LDU,1,270},	//( - K14VDSR, DU) Приход на ВУ НИ1
	{&B4IS11LDU,1,271},	//( - K31VDSR, DU) Приход на ВУ НИ2
	{&R4AB13LDU,1,272},	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
	{&R4AB14LDU,1,273},	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
	{&R4AB15LDU,1,274},	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
	{&R5IS11LDU,1,275},	//( - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
	{&R4AB16LDU,1,276},	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
	{&R4AB17LDU,1,277},	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	{&A6AB04LDU,1,278},	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
	{&B6AB04LDU,1,279},	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
	{&R4AB01LDU,1,280},	//( - , DU) Блокировка движения тележки - АНИ не установлен
	{&R8IS11LDU,1,281},	//( - K14VDSR, DU) Аварийный НИ установлен
	{&R4AB02LDU,1,282},	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
	{&R4IS21LDU,1,283},	//( - K07VDSR, DU) Приход на НУ1 тележки
	{&R4IS22LDU,1,284},	//( - K08VDSR, DU) Приход на НУ2 тележки
	{&R4IS12LDU,1,285},	//( - K06VDSR, DU) Приход на ВУ2 тележки
	{&R4VS22LDU,1,286},	//( - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
	{&R4VS12LDU,1,287},	//( - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
	{&R4AZ03LDU,1,288},	//( - , DU) Несанкционированное перемещение тележки
	{&R4AB03LDU,1,289},	//( - , DU) Блокировка движения тележки - Самоход любого механизма
	{&R1IS21LDU,1,290},	//( - K28VDSR, DU) Приход на НУ МДЗ1
	{&R2IS21LDU,1,291},	//( - K30VDSR, DU) Приход на НУ МДЗ2
	{&B1VS12LDU,1,292},	//( - , DU) Движение ББ2 в сторону ВУ
	{&B1AB04LDU,1,293},	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
	{&B1AB02LDU,1,294},	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
	{&B1AB01LDU,1,295},	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
	{&B1VS22LDU,1,296},	//( - , DU) Движение ББ2 в сторону НУ
	{&B1AZ03LDU,1,297},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
	{&B1AB07LDU,1,298},	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{&B1AB08LDU,1,299},	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{&B1AB05LDU,1,300},	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{&B1AB06LDU,1,301},	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{&B1AB09LDU,1,302},	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
	{&B1AB10LDU,1,303},	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{&B1AB11LDU,1,304},	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{&B1AB12LDU,1,305},	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&B1AB13LDU,1,306},	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
	{&A1AB01LDU,1,307},	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
	{&A1VS22LDU,1,308},	//( - , DU) Движение ББ1 в сторону НУ
	{&A1AZ03LDU,1,309},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
	{&A1AB07LDU,1,310},	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	{&A1AB08LDU,1,311},	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	{&A1AB05LDU,1,312},	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	{&A1AB06LDU,1,313},	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{&A1AB09LDU,1,314},	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
	{&A1AB10LDU,1,315},	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
	{&A1AB11LDU,1,316},	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	{&A1AB12LDU,1,317},	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A1AB13LDU,1,318},	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
	{&A1AB14LDU,1,319},	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	{&A1AB16LDU,1,320},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
	{&A1AB17LDU,1,321},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
	{&A1AB18LDU,1,322},	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	{&A3AB10LDU,1,323},	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
	{&A3AB11LDU,1,324},	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	{&A3AB12LDU,1,325},	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A3AB14LDU,1,326},	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	{&A3AB16LDU,1,327},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
	{&A3AB17LDU,1,328},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
	{&A3AB18LDU,1,329},	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	{&A3AB20LDU,1,330},	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
	{&B3VS12LDU,1,331},	//( - , DU) Движение ИС2 в сторону ВУ
	{&B3AB04LDU,1,332},	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
	{&B3AB02LDU,1,333},	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
	{&B3AB01LDU,1,334},	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
	{&B3VS22LDU,1,335},	//( - , DU) Движение ИС2 в сторону НУ
	{&B3AZ03LDU,1,336},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
	{&B3AB07LDU,1,337},	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	{&B3AB08LDU,1,338},	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	{&B1AB14LDU,1,339},	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{&B1AB16LDU,1,340},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
	{&B1AB17LDU,1,341},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{&B1AB18LDU,1,342},	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{&A3VS12LDU,1,343},	//( - , DU) Движение ИС1 в сторону ВУ
	{&A3AB04LDU,1,344},	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
	{&A3AB02LDU,1,345},	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
	{&A3AB01LDU,1,346},	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
	{&A3VS22LDU,1,347},	//( - , DU) Движение ИС1 в сторону НУ
	{&A3AZ03LDU,1,348},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
	{&A3AB07LDU,1,349},	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	{&A3AB08LDU,1,350},	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	{&A3AB05LDU,1,351},	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	{&A3AB06LDU,1,352},	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	{&A3AB09LDU,1,353},	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
	{&A2VS21LDU,1,354},	//( - , DU) Движение РБ1 в сторону НУ
	{&A2AZ03LDU,1,355},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
	{&A2AB07LDU,1,356},	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
	{&A2AB08LDU,1,357},	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
	{&A2AB05LDU,1,358},	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
	{&A2AB06LDU,1,359},	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
	{&A2AB09LDU,1,360},	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
	{&A2AB10LDU,1,361},	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
	{&A2AB11LDU,1,362},	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	{&A2AB12LDU,1,363},	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A2AB13LDU,1,364},	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
	{&A2AB14LDU,1,365},	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	{&A2AB16LDU,1,366},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
	{&A2AB17LDU,1,367},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{&B2AB04LDU,1,368},	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
	{&A8IS12LDU,1,369},	//( - K30VDSR, DU) Приход на механический ВУ ДС2
	{&A8AB04LDU,1,370},	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
	{&A8IS22LDU,1,371},	//( - K31VDSR, DU) Приход на механический НУ ДС2
	{&A8AB08LDU,1,372},	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{&A8AB09LDU,1,373},	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
	{&A8AB10LDU,1,374},	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
	{&A8AB11LDU,1,375},	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	{&A8AB12LDU,1,376},	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
	{&A8AB13LDU,1,377},	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
	{&A8AB14LDU,1,378},	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
	{&A8AB02LDU,1,379},	//( - , DU) Блокировка движения ДС2- АНИ не установлен
	{&A8AB01LDU,1,380},	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
	{&A2VS11LDU,1,381},	//( - , DU) Движение РБ1 в сторону ВУ
	{&A2AB04LDU,1,382},	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
	{&A2AB02LDU,1,383},	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
	{&A2AB01LDU,1,384},	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
	{&R1AB01LDU,1,385},	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
	{&R1AB02LDU,1,386},	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
	{&R2AZ03LDU,1,387},	//( - , DU) Несанкционированное перемещение МДЗ2
	{&R2AB01LDU,1,388},	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
	{&R2AB02LDU,1,389},	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
	{&R1AB04LDU,1,390},	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
	{&R2AB04LDU,1,391},	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
	{&R1IS11LDU,1,392},	//( - K27VDSR, DU) Приход на ВУ МДЗ1
	{&R1VS22LDU,1,393},	//( - K06VDSR, DU) Движение МДЗ1 в сторону НУ
	{&R2VS22LDU,1,394},	//( - K09VDSR, DU) Движение МДЗ2 в сторону НУ
	{&R2VS12LDU,1,395},	//( - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
	{&R1VS12LDU,1,396},	//( - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
	{&R2IS11LDU,1,397},	//( - K29VDSR, DU) Приход на ВУ МДЗ2
	{&A1VS12LDU,1,398},	//( - , DU) Движение ББ1 в сторону ВУ
	{&A1AB04LDU,1,399},	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
	{&A1AB02LDU,1,400},	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
	{&B2AB02LDU,1,401},	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
	{&B2AB01LDU,1,402},	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
	{&B2AZ03LDU,1,403},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
	{&B2AB07LDU,1,404},	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	{&B2AB08LDU,1,405},	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{&B2AB05LDU,1,406},	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{&B2AB06LDU,1,407},	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{&B2AB09LDU,1,408},	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
	{&B2AB10LDU,1,409},	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{&B2AB11LDU,1,410},	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{&B2AB12LDU,1,411},	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{&B2AB13LDU,1,412},	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
	{&B2AB14LDU,1,413},	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{&B2AB16LDU,1,414},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
	{&B2AB17LDU,1,415},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{&R1AZ03LDU,1,416},	//( - , DU) Несанкционированное перемещение МДЗ1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DU[]={  // 
	{&B2VS01IDU,3,0},	//( - , DU) Готовность к управлению РБ2
	{&R0VX08IDU,3,1},	//( - , DU) Индикация Режим
	{&B6VS01IDU,3,2},	//( - , DU) Готовность к управлению БЗ2
	{&R0VL01RDU,8,3},	//( - , DU) Индикация Время задержки
	{&R0VL01IDU,3,5},	//( - , DU) До импульса минут
	{&R0VL11IDU,3,6},	//( - , DU) До импульса секунд
	{&R0VL06RDU,8,7},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	{&R0VL02RDU,8,9},	//( - , DU) Индикация (Время задержки ИНИ)
	{&R0VL04RDU,8,11},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	{&R0VL03RDU,8,13},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{&R0VL05RDU,8,15},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	{&R0VL21IDU,3,17},	//( - , DU) Декатрон
	{&R0VS21IDU,3,18},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	{&A1VS01IDU,3,19},	//( - , DU) Готовность к управлению ББ1
	{&B1VS01IDU,3,20},	//( - , DU) Готовность к управлению ББ2
	{&A3VS01IDU,3,21},	//( - , DU) Готовность к управлению ИС1
	{&B3VS01IDU,3,22},	//( - , DU) Готовность к управлению ИС2
	{&A2VS01IDU,3,23},	//( - , DU) Готовность к управлению РБ1
	{&A4VS01IDU,3,24},	//( - , DU) Готовность к управлению НИ1
	{&B4VS01IDU,3,25},	//( - , DU) Готовность к управлению НИ2
	{&A5VS01IDU,3,26},	//( - , DU) Готовность к управлению НЛ1
	{&B5VS01IDU,3,27},	//( - , DU) Готовность к управлению НЛ2
	{&A6VS01IDU,3,28},	//( - , DU) Готовность к управлению БЗ1
	{&R4VS01IDU,3,29},	//( - , DU) Готовность к управлению тележкой реактора
	{&R2VS01IDU,3,30},	//( - , DU) Готовность к управлению МДЗ2
	{&R1VS01IDU,3,31},	//( - , DU) Готовность к управлению МДЗ1
	{&B1VC01RDU,8,32},	//( - , DU) Координата ББ2, мм
	{&B3VC01RDU,8,34},	//( - , DU) Координата ИС2, мм
	{&A8VC01RDU,8,36},	//( - , DU) Координата ДС2, мм
	{&A1VC01RDU,8,38},	//( - , DU) Координата ББ1, мм
	{&B3CV01RDU,8,40},	//( - , DU) Измеренная скорость перемещения ИС2
	{&R0VN15RDU,8,42},	//( - , DU) Период разгона РУ
	{&B3CP02RDU,8,44},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
	{&A3VC01RDU,8,46},	//( - , DU) Координата ИС1, мм
	{&A2VC01RDU,8,48},	//( - , DU) Координата РБ1, мм
	{&B2VC01RDU,8,50},	//( - , DU) Координата РБ2, мм
	{&B8VC01RDU,8,52},	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
	{&A3CP02RDU,8,54},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
	{&B8VS01IDU,3,56},	//( - , DU) Готовность к управлению АЗ2
	{&A8VS01IDU,3,57},	//( - , DU) Готовность к управлению ДС2
	{&R5VS01IDU,3,58},	//( - , DU) Готовность к управлению ворот отстойной зоны
	{&R3VS01IDU,3,59},	//( - , DU) Готовность к управлению гомогенных дверей
	{&TTLDU,3,60},	//( - , DU) ttl
	{&A3MC01RDU,8,61},	//( - , DU) Заданная координата положения ИС от регулятора мм
	{&A3MC02RDU,8,63},	//( - , DU) Температурная корректировка координаты ИМ
	{&R0CN91LDU,8,65},	//( - , DU) Рассчётная реактивность от регулятора
	{&A3MC03RDU,8,67},	//( - , DU) Координата положения ИМ 0-й реактивности
	{&R0CN92LDU,8,69},	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
	{&R0VN11RDU,8,71},	//( - , DU) Текущая мощность РУ
	{&R0VN12RDU,8,73},	//( - , DU) Заданная мощность РУ
	{&R0CN93LDU,8,75},	//( - , DU) время работы на мощности более 100Вт, сек
	{&R0CN94LDU,8,77},	//( - , DU) Скорость изменения мощности
	{&R0CN95LDU,3,79},	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
	{&A8CV01RDU,8,80},	//( - , DU) Измеренная скорость перемещения ДС2
	{&B8CV01RDU,8,82},	//( - , DU) Измеренная скорость перемещения АЗ2
	{&B1CV01RDU,8,84},	//( - , DU) Измеренная скорость перемещения ББ2
	{&B1CV02RDU,8,86},	//( - , DU) Заданная скорость перемещения ББ2
	{&A1CV02RDU,8,88},	//( - , DU) Заданная скорость перемещения ББ1
	{&B3CV02RDU,8,90},	//( - , DU) Заданная скорость перемещения ИС2
	{&A3CV01RDU,8,92},	//( - , DU) Измеренная скорость перемещения ИС1
	{&A3CV02RDU,8,94},	//( - , DU) Заданная скорость перемещения ИС1
	{&A2CV02RDU,8,96},	//( - , DU) Заданная скорость перемещения РБ1
	{&B2CV01RDU,8,98},	//( - , DU) Измеренная скорость перемещения РБ2
	{&A2CV01RDU,8,100},	//( - , DU) Измеренная скорость перемещения РБ1
	{&A1CV01RDU,8,102},	//( - , DU) Измеренная скорость перемещения ББ1
	{&B2CV02RDU,8,104},	//( - , DU) Заданная скорость перемещения РБ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DU[]={  // 
	{&R0MW14IP2,3,0},	//( - , DU) Переключатель ОБДУВ
	{&R0MW12IP2,3,1},	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
	{&A1MC01RP1,8,2},	//( - , DU) Заданная координата положения ББ1 мм
	{&B1MC01RP1,8,4},	//( - , DU) Заданная координата положения ББ2  мм
	{&A3MC01RP1,8,6},	//( - , DU) Заданная координата положения ИС1 мм
	{&B3MC01RP1,8,8},	//( - , DU) Заданная координата положения ИС2 мм
	{&B8MC01RP2,8,10},	//( - , DU) Заданная координата АЗ2 мм
	{&R0MW15IP1,3,12},	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
	{&R0MW14IP1,3,13},	//( - , DU) Переключатель ПРОГРАММЫ
	{&R0MW12IP1,3,14},	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
	{&R0MW13IP1,3,15},	//( - , DU) Переключатель ВЫБОР ЗОН
	{&R0MW16IP1,3,16},	//( - , DU) Переключатель ВИД ПРОВЕРКИ
	{&R0MW11IP1,3,17},	//( - , DU) Переключатель ВЫСТРЕЛ
	{&R0MW11IP2,3,18},	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
	{&fEM_A1UC03RDU,8,19},	//( - , DU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
	{&dEM_A1UC05UDU,5,21},	//( - , DU) Верхняя граница показания энкодера ББ, деления энкодера
	{&dEM_A1UC06UDU,5,23},	//( - , DU) Нижняя граница показания энкодера ББ, деления энкодера
	{&dEM_A2UC06UDU,5,25},	//( - , DU) Нижняя граница показания энкодера РБ, деления энкодера
	{&dEM_A2UC05UDU,5,27},	//( - , DU) Верхняя граница показания энкодера РБ, деления энкодера
	{&fEM_A2UC03RDU,8,29},	//( - , DU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
	{&dEM_A3UC06UDU,5,31},	//( - , DU) Нижняя граница показания энкодера ИС, деления энкодера
	{&dEM_A3UC05UDU,5,33},	//( - , DU) Верхняя граница показания энкодера ИС, деления энкодера
	{&fEM_A3UC03RDU,8,35},	//( - , DU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
	{&dEM_A8UC06UDU,5,37},	//( - , DU) Нижняя граница показания энкодера АЗ2, деления энкодера
	{&fEM_A8UC03RDU,8,39},	//( - , DU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
	{&dEM_A8UC05UDU,5,41},	//( - , DU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
	{&fEM_R0UV81RDU,8,43},	//( - , DU) 1-я частота двигателя (шагов/секунду)
	{&fEM_R0UV82RDU,8,45},	//( - , DU) 2-я частота двигателя (шагов/секунду)
	{&fEM_R0UV83RDU,8,47},	//( - , DU) 3-я частота двигателя (шагов/секунду)
	{&fEM_R0UV84RDU,8,49},	//( - , DU) 4-я частота двигателя (шагов/секунду)
	{&fEM_R0UV86RDU,8,51},	//( - , DU) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV85RDU,8,53},	//( - , DU) 6-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV87RDU,8,55},	//( - , DU) 8-я скорость перемещения ББ (шагов/секунду)
	{&fEM_A3UP03RDU,8,57},	//( - , DU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A3UP04RDU,8,59},	//( - , DU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A3UP43RDU,8,61},	//( - , DU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
	{&fEM_A3UP44RDU,8,63},	//( - , DU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
	{&fEM_A3UP53RDU,8,65},	//( - , DU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
	{&fEM_A3UP85RDU,8,67},	//( - , DU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{&fEM_A3UP88RDU,8,69},	//( - , DU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{&fEM_A3UP86RDU,8,71},	//( - , DU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{&fEM_B8UV01RDU,8,73},	//( - , DU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
	{&fEM_B8UV02RDU,8,75},	//( - , DU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
	{&fEM_B8UV03RDU,8,77},	//( - , DU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
	{&fEM_B8UL04RDU,8,79},	//( - , DU) Задержка определения самохода АЗ-ДС после команды на останов, сек
	{&iEM_A2UV03CDU,3,81},	//( - , DU) Скорость 1-го диапазона РБ назад (вниз)
	{&fEM_A2UV01RDU,8,82},	//( - , DU) Допустимое превышение заданной скорости РБ мм/с
	{&fEM_A2UV02RDU,8,84},	//( - , DU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
	{&fEM_A1UV01RDU,8,86},	//( - , DU) Допустимое превышение заданной скорости ББ мм/с
	{&fEM_A1UV02RDU,8,88},	//( - , DU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
	{&fEM_A1UC06RDU,8,90},	//( - , DU) Уставка определения самохода ББ  мм
	{&fEM_A1UC05RDU,8,92},	//( - , DU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
	{&fEM_A1UL04RDU,8,94},	//( - , DU) Задержка определения самохода ББ после команды на останов, сек
	{&fEM_A3UV01RDU,8,96},	//( - , DU) Допустимое превышение заданной скорости ИС мм/с
	{&fEM_A3UV02RDU,8,98},	//( - , DU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
	{&fEM_A3UC06RDU,8,100},	//( - , DU) Уставка определения самохода ИС1  мм
	{&fEM_A3UC05RDU,8,102},	//( - , DU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
	{&fEM_A3UL04RDU,8,104},	//( - , DU) Задержка определения самохода ИС после команды на останов, сек
	{&fEM_A3UP54RDU,8,106},	//( - , DU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
	{&fEM_A3UP87RDU,8,108},	//( - , DU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{&fEM_R0UL05RDU,8,110},	//( - , DU) Время срабатывания сброса от НУП ИС
	{&fEM_R0UL20RDU,8,112},	//( - , DU) Предельное отклонение от времени задержки  сброса от II УР
	{&fEM_B8UV04RDU,8,114},	//( - , DU) Время разгона механизма при переходе на новую скорость сек
	{&fEM_B8UC06RDU,8,116},	//( - , DU) Уставка определения самохода АЗ-ДС,  мм
	{&fEM_B8UC05RDU,8,118},	//( - , DU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
	{&fEM_A2UL05RDU,8,120},	//( - , DU) Время задержки блокировки РБ по недвижению сек
	{&fEM_A2UL03RDU,8,122},	//( - , DU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{&fEM_A2UC06RDU,8,124},	//( - , DU) Уставка определения самохода РБ  мм
	{&fEM_A2UC05RDU,8,126},	//( - , DU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
	{&fEM_A2UL04RDU,8,128},	//( - , DU) Задержка определения самохода РБ после команды на останов, с
	{&fEM_A1UL03RDU,8,130},	//( - , DU) Задержка определения самохода ББ после останова (достижения скорости 0), с
	{&fEM_A1UL05RDU,8,132},	//( - , DU) Время задержки блокировки ББ по недвижению с
	{&fEM_A3UL03RDU,8,134},	//( - , DU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
	{&fEM_A3UL05RDU,8,136},	//( - , DU) Время задержки блокировки ИС по недвижению сек
	{&fEM_A1UC08RDU,8,138},	//( - , DU) Зона нечувствительности при наведении ББ  мм
	{&fEM_A3UC08RDU,8,140},	//( - , DU) Зона нечувствительности при наведении ИС 0.01 мм
	{&fEM_A1UC07RDU,8,142},	//( - , DU) Зона возврата при наведении ББ мм
	{&fEM_A1UL01RDU,8,144},	//( - , DU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{&fEM_A3UC07RDU,8,146},	//( - , DU) Зона возврата при наведении ИС 0.01 мм
	{&fEM_A3UL01RDU,8,148},	//( - , DU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{&fEM_A2UC08RDU,8,150},	//( - , DU) Зона нечувствительности при наведении РБ мм
	{&fEM_A2UC07RDU,8,152},	//( - , DU) Зона возврата при наведении РБ  мм
	{&fEM_A2UL01RDU,8,154},	//( - , DU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{&fEM_B8UC01RDU,8,156},	//( - , DU) Зона нечувствительности при наведении АЗ2,ДС2 мм
	{&fEM_B8UL07RDU,8,158},	//( - , DU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
	{&fEM_B8UC02RDU,8,160},	//( - , DU) Зона возврата при наведении АЗ2,ДС2  мм
	{&fEM_B8UL01RDU,8,162},	//( - , DU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{&fEM_B8UL05RDU,8,164},	//( - , DU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
	{&fEM_B8UL03RDU,8,166},	//( - , DU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
	{&fEM_B8UL06RDU,8,168},	//( - , DU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
	{&fEM_A9UZ03RDU,8,170},	//( - , DU) Время задержки блокировки НИ  ДС по самоходу сек
	{&fEM_A9UZ04RDU,8,172},	//( - , DU) Время задержки блокировки НИ ДС по превышению времени движения сек
	{&fEM_A9UZ05RDU,8,174},	//( - , DU) Время задержки блокировки НИ ДС по недвижению сек
	{&fEM_R4UZ04RDU,8,176},	//( - , DU) Время задержки блокировки тележки по превышению времени движения сек
	{&fEM_R4UZ03RDU,8,178},	//( - , DU) Время задержки блокировки тележки по самоходу сек
	{&fEM_R4UZ05RDU,8,180},	//( - , DU) Время задержки блокировки тележки по недвижению сек
	{&fEM_A5UZ03RDU,8,182},	//( - , DU) Время задержки блокировки НЛ по самоходу сек
	{&fEM_A5UZ04RDU,8,184},	//( - , DU) Время задержки блокировки НЛ по превышению времени движения сек
	{&fEM_A5UZ05RDU,8,186},	//( - , DU) Время задержки блокировки НЛ по недвижению сек
	{&fEM_A4UZ03RDU,8,188},	//( - , DU) Время задержки блокировки НИ по самоходу сек
	{&fEM_A4UZ04RDU,8,190},	//( - , DU) Время задержки блокировки НИ по превышению времени движения сек
	{&fEM_A4UZ05RDU,8,192},	//( - , DU) Время задержки блокировки НИ по недвижению сек
	{&fEM_A6UZ03RDU,8,194},	//( - , DU) Время задержки блокировки БЗ по самоходу сек
	{&fEM_A6UZ04RDU,8,196},	//( - , DU) Время задержки блокировки БЗ по превышению времени движения сек
	{&fEM_A6UZ05RDU,8,198},	//( - , DU) Время задержки блокировки БЗ по недвижению сек
	{&fEM_R1UZ03RDU,8,200},	//( - , DU) Время задержки блокировки МДЗ по самоходу сек
	{&fEM_R1UZ04RDU,8,202},	//( - , DU) Время задержки блокировки МДЗ по превышению времени движения сек
	{&fEM_R1UZ05RDU,8,204},	//( - , DU) Время задержки блокировки МДЗ по недвижению сек
	{&fEM_R0UL04RDU,8,206},	//( - , DU) Предельное время ожидания срабатывания АЗ от НУП ИС
	{&fEM_R0UL06RDU,8,208},	//( - , DU) Предельное время срабатывания верхней АС II УР
	{&fEM_R0UL03RDU,8,210},	//( - , DU) Время срабатывания сброса от ВУ РБ
	{&fEM_R0UL17RDU,8,212},	//( - , DU) Предельное отклонение от времени задержки  сброса от ВУ РБ
	{&fEM_R0UL19RDU,8,214},	//( - , DU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{&fEM_R0UL07RDU,8,216},	//( - , DU) Время срабатывания верхней АС II УР
	{&fEM_R0UL18RDU,8,218},	//( - , DU) Предельное отклонение от времени задержки  сброса от НУП ИС
	{&fEM_R0UL16RDU,8,220},	//( - , DU) Предельное отклонение от времени задержки  ИНИ
	{&fEM_R0UL02RDU,8,222},	//( - , DU) Время задержки  ИНИ
	{&fEM_R0UN08RDU,8,224},	//( - , DU) 8-я заданная мощность
	{&fEM_R0UN07RDU,8,226},	//( - , DU) 7-я заданная мощность
	{&fEM_R0UN06RDU,8,228},	//( - , DU) 6-я заданная мощность
	{&fEM_R0UN05RDU,8,230},	//( - , DU) 5-я заданная мощность
	{&fEM_R0UN04RDU,8,232},	//( - , DU) 4-я заданная мощность
	{&fEM_R0UN03RDU,8,234},	//( - , DU) Ограничение 3 по мощности
	{&fEM_R0UN02RDU,8,236},	//( - , DU) 2-я заданная мощность
	{&fEM_R0UN01RDU,8,238},	//( - , DU) 1-я заданная мощность
	{&fEM_A2UC82RDU,8,240},	//( - , DU) Граница 2-го диапазона РБ вперёд (вверх)
	{&fEM_A2UC83RDU,8,242},	//( - , DU) Граница 1-го диапазона РБ назад (вниз)
	{&fEM_A1UC83RDU,8,244},	//( - , DU) Граница 1-го диапазона ББ назад (вниз)
	{&fEM_A2UC81RDU,8,246},	//( - , DU) Граница 1-го диапазона РБ вперёд (вверх)
	{&fEM_A1UC81RDU,8,248},	//( - , DU) Граница 1-го диапазона ББ вперёд (вверх)
	{&fEM_A1UC82RDU,8,250},	//( - , DU) Граница 2-го диапазона ББ вперёд (вверх)
	{&fEM_A2UL83RDU,8,252},	//( - , DU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{&fEM_A3UC81RDU,8,254},	//( - , DU) Граница 1-го диапазона ИС вперёд (вверх)
	{&fEM_A3UC82RDU,8,256},	//( - , DU) Граница 1-го диапазона ИС назад (вниз)
	{&fEM_R0UN80RDU,8,258},	//( - , DU) Ограничение по мощности в режиме калибровка и имульс
	{&iEM_A2UV01IDU,3,260},	//( - , DU) Скорость 1-го диапазона РБ вперёд (вверх)
	{&iEM_A2UV02IDU,3,261},	//( - , DU) Скорость 2-го диапазона РБ вперёд (вверх)
	{&iEM_A1UV01IDU,3,262},	//( - , DU) Скорость 1-го диапазона ББ вперёд (вверх)
	{&iEM_A1UV02IDU,3,263},	//( - , DU) Скорость 2-го диапазона ББ вперёд (вверх)
	{&iEM_A1UV03IDU,3,264},	//( - , DU) Скорость1-го диапазона ББ назад (вниз)
	{&iEM_A3UV01IDU,3,265},	//( - , DU) Скорость ИС для 1-го диапазона вперёд (вверх)
	{&iEM_A3UV02IDU,3,266},	//( - , DU) Скорость ИС для 1-го диапазона назад (вниз)
	{&fEM_A3UC09RDU,8,267},	//( - , DU) Координата переднего аварийного выключателя ИС мм
	{&fEM_A2UC02RDU,8,269},	//( - , DU) Коэффициент преобразования частота-скорость(мм/сек)
	{&fEM_A1UC02RDU,8,271},	//( - , DU) Коэффициент преобразования частота-скорость(мм/сек) ББ
	{&fEM_A3UC02RDU,8,273},	//( - , DU) Коэффициент преобразования частота-скорость (мм/сек) ИС
	{&fEM_R0UL21RDU,8,275},	//( - , DU) Предельное время задержки  сброса от ВУ РБ
	{&fEM_R0UN09RDU,8,277},	//( - , DU) Минимальный период при регулировании мощности
	{&fEM_R0UN11RDU,8,279},	//( - , DU) Допустимое превышение заданной мощности  при регулировании
	{&fEM_R0UN12RDU,8,281},	//( - , DU) Зона нечувствительности при регулировании мощности %
	{&fEM_R0UN13RDU,8,283},	//( - , DU) Минимальное изменение координаты, мм
	{&fEM_R0UN14RDU,8,285},	//( - , DU) Максимальная координата штока ИМ, мм
	{&fEM_R0UN16RDU,8,287},	//( - , DU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
	{&fEM_R0UN17RDU,8,289},	//( - , DU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
	{&fEM_R0UN18RDU,8,291},	//( - , DU) Коэффициент t1 ф-ции температурной корректировки ИМ
	{&fEM_R0UN19RDU,8,293},	//( - , DU) Коэффициент t0 ф-ции температурной корректировки ИМ
	{&fEM_R0UN70LDU,8,295},	//( - , DU) 0 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN71LDU,8,297},	//( - , DU) 1 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN72LDU,8,299},	//( - , DU) 2 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN73LDU,8,301},	//( - , DU) 3 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN74LDU,8,303},	//( - , DU) 4 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN75LDU,8,305},	//( - , DU) 5 - Коэффициент реактивности функции опережения старта ИМ
	{&fEM_R0UN80LDU,8,307},	//( - , DU) 0 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN81LDU,8,309},	//( - , DU) 1 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN82LDU,8,311},	//( - , DU) 2 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN83LDU,8,313},	//( - , DU) 3 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN84LDU,8,315},	//( - , DU) 4 - Коэффициент  опережения старта ИМ
	{&fEM_R0UN85LDU,8,317},	//( - , DU) 5 - Коэффициент  опережения старта ИМ
	{&fEM_R0UT20RDU,8,319},	//( - , DU) Предельное время работы на мощности более 100 Вт, сек
	{&fEM_R0UN25RDU,8,321},	//( - , DU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
	{&fEM_R0UN15RDU,8,323},	//( - , DU) коэффициент рассогласования по координате для транспортной реактивности %
	{&fEM_R0UN26RDU,8,325},	//( - , DU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
	{&fEM_R0UN27RDU,8,327},	//( - , DU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
	{&fEM_R0UN24RDU,8,329},	//( - , DU) Нижняя граница интервала мощности для измерения периода (ватт)
	{&fEM_R0UL25RDU,8,331},	//( - , DU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{&fEM_R0UL01RSS,8,333},	//( - , DU) Шаг измерения периода (сек)
	{&fEM_R0UL02RSS,8,335},	//( - , DU) Tф-постоянная времени, с
	{&fEM_R0UN03RSS,8,337},	//( - , DU) нижняя граница интервала мощности для измерения периода (ватт)
	{&fEM_R7UI76RDU,8,339},	//( - , DU) Время срабатывания сигнала II УР при имитации
	{&fEM_R0UL00RDU,8,341},	//( - , DU) Время ожидания передачи  сигнала отключения сети
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_DiagnDU[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_DiagnDU[]={  // 
	{&R0DE3CLDU,1,0},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
	{&R0DE3DLDU,1,1},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
	{&R0DEB4LDU,1,2},	//( - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
	{&R0DEB1LDU,1,3},	//( - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
	{&R0DEB2LDU,1,4},	//( - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
	{&R0DEB3LDU,1,5},	//( - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DiagnDU[]={  // 
	{&R0DE06LDU,3,0},	//( - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
	{&R0DE01LDU,3,1},	//( - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
	{&R0DE0FLDU,3,2},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
	{&R0DE0DLDU,3,3},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
	{&R0DE0BLDU,3,4},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
	{&R0DE0CLDU,3,5},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
	{&R0DE07LDU,3,6},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
	{&R0DE0ALDU,3,7},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
	{&R0DE09LDU,3,8},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
	{&R0DE05LDU,3,9},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
	{&R0DE08LDU,3,10},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
	{&R0DE04LDU,3,11},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
	{&R0DE03LDU,3,12},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
	{&R0DE02LDU,3,13},	//( - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DiagnDU[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_MDuBz1[]={  // 
	{&R0AD21LDU,1,0},	//( - , SBz1DU) Подключить защиту от II УР
	{&R0VW23LDU,1,1},	//( - , Baz1, SBz1DU) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,2},	//( - , Baz1, SBz1DU) Индикация выбора АЗ1 или АЗ1+АЗ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MDuBz1[]={  // 
	{&B0VT71LZ1,1,0},	//( - , Baz1, SBz1DU) АС по температуре в АЗ2
	{&R0VP73LZ1,1,1},	//( - , Baz1, SBz1DU) ПС давления для РУ
	{&B0VN71LZ1,1,2},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ2
	{&A0VN71LZ1,1,3},	//( - , Baz1, SBz1DU) АЗ по АС мощности  АЗ1
	{&A0EE03LZ1,1,4},	//( - , Baz1, SBz1DU) Исправность АКНП3
	{&A0EE02LZ1,1,5},	//( - , Baz1, SBz1DU) Исправность АКНП2
	{&A0EE04LZ1,1,6},	//( - , Baz1, SBz1DU) Исправность АКНП4
	{&A0EE01LZ1,1,7},	//( - , Baz1, SBz1DU) Исправность АКНП1
	{&B0VP71LZ1,1,8},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ2
	{&A0VP71LZ1,1,9},	//( - , Baz1, SBz1DU) АЗ по АС любого давления для АЗ1
	{&B1VP41LZ1,1,10},	//( - , Baz1, SBz1DU) Давление СБРОС ББ2 ниже АС
	{&A1VP41LZ1,1,11},	//( - , Baz1, SBz1DU) Давление СБРОС ББ1 ниже АС
	{&A0VT71LZ1,1,12},	//( - , Baz1, SBz1DU) АС по температуре в АЗ1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MDuBz1[]={  // 
	{&B0CT01IZ1,8,0},	//( - , Baz1, SBz1DU) Температура АЗ2-1
	{&R0VN11RZ1,8,2},	//( - , Baz1, SBz1DU) Средняя мощность по БАЗ1
	{&A0CT01IZ1,8,4},	//( - , Baz1, SBz1DU) Температура АЗ1-1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MDuBz1[]={  // 
	{&B8VC01RDU,8,0},	//( - , SBz1DU, MBz1A1, MBz1A2, MBz1A3, MBz1A4) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
static char MDuBz1_ip1[]={"192.168.10.52\0"};
static char MDuBz1_ip2[]={"192.168.10.152\0"};
#pragma pack(push,1)
static ModbusRegister coil_MDuBz2[]={  // 
	{&R0AD21LDU,1,0},	//( - , SBz2DU) Подключить защиту от II УР
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MDuBz2[]={  // 
	{&B0VT71LZ2,1,0},	//( - , Baz2, SBz2DU) АС по температуре в АЗ2
	{&R0VP73LZ2,1,1},	//( - , Baz2, SBz2DU) ПС давления для РУ
	{&B0VN71LZ2,1,2},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ2
	{&A0VN71LZ2,1,3},	//( - , Baz2, SBz2DU) АЗ по АС мощности  АЗ1
	{&A0EE03LZ2,1,4},	//( - , Baz2, SBz2DU) Исправность АКНП3
	{&A0EE02LZ2,1,5},	//( - , Baz2, SBz2DU) Исправность АКНП2
	{&A0EE04LZ2,1,6},	//( - , Baz2, SBz2DU) Исправность АКНП4
	{&A0EE01LZ2,1,7},	//( - , Baz2, SBz2DU) Исправность АКНП1
	{&B0VP71LZ2,1,8},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ2
	{&A0VP71LZ2,1,9},	//( - , Baz2, SBz2DU) АЗ по АС любого давления для АЗ1
	{&B1VP41LZ2,1,10},	//( - , Baz2, SBz2DU) Давление СБРОС ББ2 ниже АС
	{&A1VP41LZ2,1,11},	//( - , Baz2, SBz2DU) Давление СБРОС ББ1 ниже АС
	{&A0VT71LZ2,1,12},	//( - , Baz2, SBz2DU) АС по температуре в АЗ1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MDuBz2[]={  // 
	{&B0CT01IZ2,8,0},	//( - , Baz2, SBz2DU) Температура АЗ2-1
	{&R0VN11RZ2,8,2},	//( - , Baz2, SBz2DU) Средняя мощность по БАЗ1
	{&A0CT01IZ2,8,4},	//( - , Baz2, SBz2DU) Температура АЗ1-1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MDuBz2[]={  // 
	{&B8VC01RDU,8,0},	//( - , SBz2DU, MBz2A1, MBz2A2, MBz2A3, MBz2A4) Координата АЗ2, мм
	{NULL,0,0},
};
#pragma pop
static char MDuBz2_ip1[]={"192.168.10.54\0"};
static char MDuBz2_ip2[]={"192.168.10.154\0"};
#pragma pack(push,1)
static ModbusRegister coil_MDuS[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_MDuS[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_MDuS[]={  // 
	{&A2IC01UDU,5,0},	//( - , SDu) Координата штока РБ1
	{&A3IC01UDU,5,2},	//( - , SDu) Координата штока ИС1
	{&B3IC01UDU,5,4},	//( - , SDu) Координата штока ИС2
	{&A8IC01UDU,5,6},	//( - , SDu) Координата ДС2
	{&B8IC01UDU,5,8},	//( - , SDu) Координата АЗ2, мм
	{&B2IC01UDU,5,10},	//( - , SDu) Координата штока РБ2
	{&A1IC01UDU,5,12},	//( - , SDu) Координата штока ББ1
	{&B1IC01UDU,5,14},	//( - , SDu) Координата штока ББ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_MDuS[]={  // 
	{NULL,0,0},
};
#pragma pop
static char MDuS_ip1[]={"192.168.10.60\0"};
static char MDuS_ip2[]={"192.168.10.60\0"};
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_DU[0],&di_DU[0],&ir_DU[0],&hr_DU[0],NULL,NULL,NULL,0},	 //Общий слэйв
	{0,5006,&coil_DiagnDU[0],&di_DiagnDU[0],&ir_DiagnDU[0],&hr_DiagnDU[0],NULL,NULL,NULL,0},	 //Диагностика DU
	{1,5010,&coil_MDuBz1[0],&di_MDuBz1[0],&ir_MDuBz1[0],&hr_MDuBz1[0],NULL,MDuBz1_ip1,MDuBz1_ip2,100},	 //Мастер ДУ в Баз1
	{1,5009,&coil_MDuBz2[0],&di_MDuBz2[0],&ir_MDuBz2[0],&hr_MDuBz2[0],NULL,MDuBz2_ip1,MDuBz2_ip2,100},	 //Мастер ДУ в Баз2
	{1,5005,&coil_MDuS[0],&di_MDuS[0],&ir_MDuS[0],&hr_MDuS[0],NULL,MDuS_ip1,MDuS_ip2,10},	 //Мастер ДУ в SCM

	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},};
#pragma pop
#include <fp8/drivers/vencf8l.h>
static char buf_VENCF[86];	//VENCF
static vencf8_inipar ini_VENCF={0xc2,0xff,0,0x6,0x96,};
#pragma pack(push,1)
static table_drv table_VENCF={0,0,&ini_VENCF,buf_VENCF,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VENCF[]={
	{&venc06,5,65},
	{&venc07,5,70},
	{&venc08,5,75},
	{&venc05,5,60},
	{&venc04,5,55},
	{&venc03,5,50},
	{&venc02,5,45},
	{&venc01,5,40},
	{&R0DE06LDU,3,80},
	{&R0DE01LDU,3,82},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3202[132];	//VDS32-02
static vds32r_inipar ini_VDS3202={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3202={0,0,&ini_VDS3202,buf_VDS3202,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3202[]={
	{&A1VN71LZ1,1,40},
	{&B3IS21LDU,1,24},
	{&B2IS21LDU,1,22},
	{&B1IS21LDU,1,16},
	{&R8IS11LDU,1,26},
	{&B1IS11LDU,1,14},
	{&B2IS12LDU,1,18},
	{&B1IS12LDU,1,12},
	{&B4IS21LDU,1,62},
	{&R1IS11LDU,1,52},
	{&R2IS11LDU,1,56},
	{&R8AD22LDU,1,28},
	{&B4IS10LDU,1,6},
	{&B3IS35LDU,1,0},
	{&B3IS33LDU,1,2},
	{&B3IS31LDU,1,8},
	{&B2IS33LDU,1,4},
	{&A3VZ15LZ1,1,36},
	{&A3VZ13LZ1,1,34},
	{&R0AD14LZ1,1,38},
	{&R0DE02LDU,3,64},
	{&A9IS11LDU,1,44},
	{&A9IS21LDU,1,46},
	{&B9IS11LDU,1,48},
	{&B9IS21LDU,1,50},
	{&B4IS11LDU,1,60},
	{&R2IS21LDU,1,58},
	{&R1IS21LDU,1,54},
	{&B7AS31LDU,1,10},
	{&B2IS11LDU,1,20},
	{&R0VZ71LZ1,1,42},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3203[132];	//VDS32-03
static vds32r_inipar ini_VDS3203={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3203={0,0,&ini_VDS3203,buf_VDS3203,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3203[]={
	{&A4IS21LDU,1,28},
	{&R0VZ71LZ2,1,42},
	{&A1IS12LDU,1,12},
	{&A2IS12LDU,1,18},
	{&A2IS11LDU,1,20},
	{&A1IS11LDU,1,14},
	{&A3VZ15LZ2,1,36},
	{&A3IS35LDU,1,0},
	{&A7AS31LDU,1,10},
	{&A3VZ13LZ2,1,34},
	{&R0AD14LZ2,1,38},
	{&A4IS11LDU,1,26},
	{&A3IS33LDU,1,2},
	{&R0IS02LDU,1,58},
	{&R0IS01LDU,1,56},
	{&A3IS31LDU,1,8},
	{&R0DE03LDU,3,64},
	{&A1IS21LDU,1,16},
	{&A2IS21LDU,1,22},
	{&A3IS21LDU,1,24},
	{&A4IS10LDU,1,6},
	{&A2IS33LDU,1,4},
	{&A1VN71LZ2,1,40},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3204[132];	//VDS32-04
static vds32r_inipar ini_VDS3204={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3204={0,0,&ini_VDS3204,buf_VDS3204,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3204[]={
	{&R4IS21LDU,1,12},
	{&R4IS22LDU,1,14},
	{&B8IS11LDU,1,36},
	{&R4IS12LDU,1,10},
	{&B8IS12LDU,1,40},
	{&R3IS21LDU,1,34},
	{&R3IS11LDU,1,32},
	{&B8IS21LDU,1,38},
	{&R5IS11LDU,1,48},
	{&A6IS21LDU,1,18},
	{&B6IS11LDU,1,24},
	{&B6IS21LDU,1,26},
	{&R0DE04LDU,3,64},
	{&R5IS21LDU,1,50},
	{&A8IS22LDU,1,60},
	{&A8IS12LDU,1,58},
	{&B8IS22LDU,1,42},
	{&A3IS22LDU,1,2},
	{&B3IS22LDU,1,6},
	{&A5IS21LDU,1,22},
	{&R4IS11LDU,1,8},
	{&B5IS11LDU,1,28},
	{&B5IS21LDU,1,30},
	{&A3IS11LDU,1,0},
	{&B3IS11LDU,1,4},
	{&R6IS21LDU,1,56},
	{&A6IS11LDU,1,16},
	{&A5IS11LDU,1,20},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3205[132];	//VDS32-05
static vds32r_inipar ini_VDS3205={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3205={0,0,&ini_VDS3205,buf_VDS3205,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3205[]={
	{&R6IS32LDU,1,50},
	{&R6IS31LDU,1,48},
	{&B1IE03LDU,1,28},
	{&R0DE05LDU,3,64},
	{&B1IE04LDU,1,30},
	{&B2IE03LDU,1,36},
	{&B2IE04LDU,1,38},
	{&A1IE01LDU,1,2},
	{&A3IE01LDU,1,18},
	{&A2IE01LDU,1,10},
	{&A1IE02LDU,1,0},
	{&A3IE02LDU,1,16},
	{&A2IE02LDU,1,8},
	{&B3IE03LDU,1,44},
	{&B3IE04LDU,1,46},
	{&B2IE02LDU,1,32},
	{&B3IE02LDU,1,40},
	{&B1IE02LDU,1,24},
	{&B3IE01LDU,1,42},
	{&B2IE01LDU,1,34},
	{&B1IE01LDU,1,26},
	{&A1IE03LDU,1,4},
	{&A1IE04LDU,1,6},
	{&A2IE03LDU,1,12},
	{&A2IE04LDU,1,14},
	{&A3IE03LDU,1,20},
	{&A3IE04LDU,1,22},
	{&R6IS51LDU,1,56},
	{&R6IS52LDU,1,58},
	{&R6IS41LDU,1,52},
	{&R6IS42LDU,1,54},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1607[40];	//FDS16-07
static fds16r_inipar ini_FDS1607={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1607={0,0,&ini_FDS1607,buf_FDS1607,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1607[]={
	{&B2AD05LDU,1,26},
	{&A2AD05LDU,1,12},
	{&A2AD04LDU,1,10},
	{&A2AD01LDU,1,4},
	{&A2AD11LDU,1,0},
	{&B2AD01LDU,1,18},
	{&A2AD03LDU,1,8},
	{&A2AD02LDU,1,6},
	{&A2AD21LDU,1,2},
	{&B2AD04LDU,1,24},
	{&B2AD03LDU,1,22},
	{&B2AD02LDU,1,20},
	{&B2AD21LDU,1,16},
	{&B2AD11LDU,1,14},
	{&R0S01LZ1,1,28},
	{&R0S01LZ2,1,30},
	{&R0DE07LDU,3,38},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1608[40];	//FDS16-08
static fds16r_inipar ini_FDS1608={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1608={0,0,&ini_FDS1608,buf_FDS1608,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1608[]={
	{&B1AD05LDU,1,26},
	{&B1AD01LDU,1,18},
	{&R0DE08LDU,3,38},
	{&A1AD01LDU,1,4},
	{&A1AD11LDU,1,0},
	{&A1AD21LDU,1,2},
	{&A1AD02LDU,1,6},
	{&A1AD03LDU,1,8},
	{&A1AD04LDU,1,10},
	{&A1AD05LDU,1,12},
	{&R0S01LIM,1,28},
	{&B1AD11LDU,1,14},
	{&B1AD21LDU,1,16},
	{&B1AD02LDU,1,20},
	{&B1AD04LDU,1,24},
	{&B1AD03LDU,1,22},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1609[40];	//FDS16-09
static fds16r_inipar ini_FDS1609={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1609={0,0,&ini_FDS1609,buf_FDS1609,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1609[]={
	{&A8AD20LDU,1,14},
	{&A8AD10LDU,1,12},
	{&A6AD10LDU,1,16},
	{&B7AP31LDU,1,10},
	{&B3AD31LDU,1,8},
	{&A6AD20LDU,1,18},
	{&B3AD34LDU,1,0},
	{&B4AD10LDU,1,6},
	{&R0DE09LDU,3,38},
	{&B8AD20LDU,1,30},
	{&B8AD10LDU,1,28},
	{&B6AD20LDU,1,22},
	{&B2AD33LDU,1,4},
	{&B3AD33LDU,1,2},
	{&B6AD10LDU,1,20},
	{&R4AD20LDU,1,26},
	{&R4AD10LDU,1,24},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1610[40];	//FDS16-10
static fds16r_inipar ini_FDS1610={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1610={0,0,&ini_FDS1610,buf_FDS1610,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1610[]={
	{&R2AD10LDU,1,16},
	{&A7AP31LDU,1,10},
	{&R0DE0ALDU,3,38},
	{&R2AD20LDU,1,18},
	{&B5AD10LDU,1,24},
	{&B5AD20LDU,1,26},
	{&A4AD10LDU,1,6},
	{&R1AD20LDU,1,14},
	{&R1AD10LDU,1,12},
	{&A3AD31LDU,1,8},
	{&A3AD34LDU,1,0},
	{&A3AD33LDU,1,2},
	{&A2AD33LDU,1,4},
	{&A5AD10LDU,1,20},
	{&A5AD20LDU,1,22},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1611[40];	//FDS16-11
static fds16r_inipar ini_FDS1611={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1611={0,0,&ini_FDS1611,buf_FDS1611,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1611[]={
	{&R0DE0BLDU,3,38},
	{&B3AD11LDU,1,14},
	{&B3AD21LDU,1,16},
	{&B3AD02LDU,1,20},
	{&B3AD03LDU,1,22},
	{&B3AD04LDU,1,24},
	{&B3AD05LDU,1,26},
	{&B3AD01LDU,1,18},
	{&A3AD11LDU,1,0},
	{&A3AD03LDU,1,8},
	{&A3AD04LDU,1,10},
	{&B9AD10LDU,1,30},
	{&A9AD10LDU,1,28},
	{&A3AD05LDU,1,12},
	{&A3AD01LDU,1,4},
	{&A3AD21LDU,1,2},
	{&A3AD02LDU,1,6},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vas84r.h>
static char buf_VAS8412[30];	//VAS84-12
static vas84r_inipar ini_VAS8412={0xc6,255,1,8,0xff,0,16,};
#pragma pack(push,1)
static table_drv table_VAS8412={0,0,&ini_VAS8412,buf_VAS8412,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VAS8412[]={
	{&R0DE0CLDU,3,26},
	{&A3IP02IDU,3,0},
	{&B3IP02IDU,3,3},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS3213[132];	//VDS32-13
static vds32r_inipar ini_VDS3213={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS3213={0,0,&ini_VDS3213,buf_VDS3213,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS3213[]={
	{&A5VS22LDU,1,22},
	{&R0DE0DLDU,3,64},
	{&A5VS12LDU,1,20},
	{&B5VS22LDU,1,28},
	{&B5VS12LDU,1,26},
	{&R0IE02LDU,1,44},
	{&B5IE01LDU,1,30},
	{&A8IE01LDU,1,6},
	{&R1VS22LDU,1,10},
	{&R2VS22LDU,1,16},
	{&R2VS12LDU,1,14},
	{&R1VS12LDU,1,8},
	{&B6IE01LDU,1,42},
	{&A5IE02LDU,1,24},
	{&R1IE01LDU,1,12},
	{&R2IE01LDU,1,18},
	{&R6IS61LDU,1,0},
	{&A6IE01LDU,1,36},
	{&R0IE01LDU,1,46},
	{&R4VS22LDU,1,4},
	{&R4VS12LDU,1,2},
	{&A6VS22LDU,1,34},
	{&A6VS12LDU,1,32},
	{&B6VS22LDU,1,40},
	{&B6VS12LDU,1,38},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS1615[40];	//FDS16-15
static fds16r_inipar ini_FDS1615={0x96,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS1615={0,0,&ini_FDS1615,buf_FDS1615,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS1615[]={
	{&R0AD03LZ1,1,16},
	{&A1AD31LDU,1,2},
	{&A2AD32LDU,1,4},
	{&R0DE0FLDU,3,38},
	{&B1AD31LDU,1,10},
	{&A2AD31LDU,1,6},
	{&B2AD31LDU,1,14},
	{&R0AD03LZ2,1,26},
	{&R0AD04LZ1,1,18},
	{&R0AD04LZ2,1,28},
	{&R0AD05LZ1,1,20},
	{&R0AD05LZ2,1,30},
	{&B2AD32LDU,1,12},
	{&A1AD32LDU,1,0},
	{&R0AD16LDU,1,24},
	{&R8AD21LDU,1,22},
	{&B1AD32LDU,1,8},
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
	{&R0DEB3LDU,1,22},
	{&R0DEB2LDU,1,20},
	{&R0DEB1LDU,1,18},
	{&R0DEB4LDU,1,24},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0x02,0x01,5,86,def_buf_VENCF,&table_VENCF}, //VENCF
	{0xc2,0x02,15,132,def_buf_VDS3202,&table_VDS3202}, //VDS32-02
	{0xc2,0x03,15,132,def_buf_VDS3203,&table_VDS3203}, //VDS32-03
	{0xc2,0x04,15,132,def_buf_VDS3204,&table_VDS3204}, //VDS32-04
	{0xc2,0x05,15,132,def_buf_VDS3205,&table_VDS3205}, //VDS32-05
	{0x96,0x07,20,40,def_buf_FDS1607,&table_FDS1607}, //FDS16-07
	{0x96,0x08,20,40,def_buf_FDS1608,&table_FDS1608}, //FDS16-08
	{0x96,0x09,20,40,def_buf_FDS1609,&table_FDS1609}, //FDS16-09
	{0x96,0x0a,20,40,def_buf_FDS1610,&table_FDS1610}, //FDS16-10
	{0x96,0x0b,20,40,def_buf_FDS1611,&table_FDS1611}, //FDS16-11
	{0xc6,0x0c,7,30,def_buf_VAS8412,&table_VAS8412}, //VAS84-12
	{0xc2,0x0d,15,132,def_buf_VDS3213,&table_VDS3213}, //VDS32-13
	{0x96,0x0f,20,40,def_buf_FDS1615,&table_FDS1615}, //FDS16-15
	{0xcc,0x20,4,26,def_buf_SBKFP,&table_SBKFP}, //SBKFP
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
	setAsFloat(756,0.00009765625);
	setAsInt(757,1024200);
	setAsInt(758,-200);
	setAsInt(759,-200);
	setAsInt(760,1024200);
	setAsFloat(761,0.00009765625);
	setAsInt(762,-200);
	setAsInt(763,1689599);
	setAsFloat(764,0.00009765625);
	setAsInt(765,-200);
	setAsFloat(766,0.0009765625);
	setAsInt(767,1536200);
	setAsFloat(768,100);
	setAsFloat(769,200);
	setAsFloat(770,300);
	setAsFloat(771,400);
	setAsFloat(772,600);
	setAsFloat(773,500);
	setAsFloat(774,750);
	setAsFloat(775,2.5);
	setAsFloat(776,0);
	setAsFloat(777,0.46);
	setAsFloat(778,0.49);
	setAsFloat(779,0.52);
	setAsFloat(780,0.53);
	setAsFloat(781,0.67);
	setAsFloat(782,0.56);
	setAsFloat(783,4);
	setAsFloat(784,4);
	setAsFloat(785,10.91);
	setAsFloat(786,3);
	setAsShort(787,4);
	setAsFloat(788,0.4);
	setAsFloat(789,0.4);
	setAsFloat(790,0.4);
	setAsFloat(791,0.4);
	setAsFloat(792,0.03);
	setAsFloat(793,0.04);
	setAsFloat(794,3);
	setAsFloat(795,0.4);
	setAsFloat(796,0.4);
	setAsFloat(797,0.07);
	setAsFloat(798,0.04);
	setAsFloat(799,3);
	setAsFloat(800,0.55);
	setAsFloat(801,0.64);
	setAsFloat(802,0.190);
	setAsFloat(803,0.045);
	setAsFloat(804,0.1);
	setAsFloat(805,2);
	setAsFloat(806,0.3);
	setAsFloat(807,3);
	setAsFloat(808,1.50);
	setAsFloat(809,0.04);
	setAsFloat(810,0.05);
	setAsFloat(811,3);
	setAsFloat(812,1.50);
	setAsFloat(813,3);
	setAsFloat(814,1.50);
	setAsFloat(815,2);
	setAsFloat(816,0.004);
	setAsFloat(817,0.006);
	setAsFloat(818,0.006);
	setAsFloat(819,1.0);
	setAsFloat(820,0.01);
	setAsFloat(821,1);
	setAsFloat(822,0.008);
	setAsFloat(823,0.01);
	setAsFloat(824,1);
	setAsFloat(825,0.4);
	setAsFloat(826,120);
	setAsFloat(827,0.6);
	setAsFloat(828,1);
	setAsFloat(829,2);
	setAsFloat(830,1.50);
	setAsFloat(831,2.0);
	setAsFloat(832,1);
	setAsFloat(833,15);
	setAsFloat(834,0.50);
	setAsFloat(835,360);
	setAsFloat(836,1);
	setAsFloat(837,2);
	setAsFloat(838,1.0);
	setAsFloat(839,6.0);
	setAsFloat(840,0.50);
	setAsFloat(841,1.0);
	setAsFloat(842,16.0);
	setAsFloat(843,3.0);
	setAsFloat(844,1.0);
	setAsFloat(845,60.0);
	setAsFloat(846,0.50);
	setAsFloat(847,1.0);
	setAsFloat(848,20.0);
	setAsFloat(849,1);
	setAsFloat(850,2.0);
	setAsFloat(851,2.0);
	setAsFloat(852,1.5);
	setAsFloat(853,0.045);
	setAsFloat(854,0.045);
	setAsFloat(855,0.150);
	setAsFloat(856,0.045);
	setAsFloat(857,0.045);
	setAsFloat(858,0.015);
	setAsFloat(859,2000.0);
	setAsFloat(860,1500.0);
	setAsFloat(861,1000.0);
	setAsFloat(862,800.0);
	setAsFloat(863,500.0);
	setAsFloat(864,200.0);
	setAsFloat(865,100.0);
	setAsFloat(866,0.001);
	setAsFloat(867,100);
	setAsFloat(868,100);
	setAsFloat(869,110.0);
	setAsFloat(870,20);
	setAsFloat(871,30.0);
	setAsFloat(872,100.0);
	setAsFloat(873,1.50);
	setAsFloat(874,170);
	setAsFloat(875,170);
	setAsFloat(876,10);
	setAsShort(877,1);
	setAsShort(878,4);
	setAsShort(879,1);
	setAsShort(880,4);
	setAsShort(881,4);
	setAsShort(882,4);
	setAsShort(883,4);
	setAsBool(884,0);
	setAsFloat(885,159.99);
	setAsFloat(886,0.002375);
	setAsFloat(887,0.000877);
	setAsFloat(888,0.001675);
	setAsFloat(889,2.5);
	setAsFloat(890,30);
	setAsFloat(891,500);
	setAsFloat(892,0.01);
	setAsFloat(893,0.05);
	setAsFloat(894,160.0);
	setAsFloat(895,-141.21);
	setAsFloat(896,71.40565);
	setAsFloat(897,0.271145);
	setAsFloat(898,24.93556615);
	setAsFloat(899,0.1268);
	setAsFloat(900,0.1567);
	setAsFloat(901,0.1858);
	setAsFloat(902,0.2066);
	setAsFloat(903,0.2646);
	setAsFloat(904,0.2995);
	setAsFloat(905,0.839554030);
	setAsFloat(906,0.78859401);
	setAsFloat(907,0.765962);
	setAsFloat(908,0.67256403);
	setAsFloat(909,0.42476001);
	setAsFloat(910,0.25501999);
	setAsFloat(911,3600.0);
	setAsFloat(912,0.935);
	setAsFloat(913,0.1);
	setAsFloat(914,0.006792308);
	setAsFloat(915,0.000418877);
	setAsFloat(916,0.001);
	setAsFloat(917,0.190);
	setAsFloat(918,0.5);
	setAsFloat(919,2.0);
	setAsFloat(920,0.005);
	setAsFloat(921,0.08);
	setAsFloat(922,0.100);
	setAsBool(254,1);
	setAsBool(256,1);
	setAsBool(252,1);
	setAsBool(255,1);
	setAsBool(257,1);
	setAsBool(253,1);
	setAsBool(245,1);
	setAsBool(246,1);
	setAsBool(247,1);
}
uspaint8 InternalBuf[9963];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssint iRM_8_ = {8,0}; /* N-число входов */ 
sslong dRM_16777215_ = {16777215,0}; /*  */ 
sschar bRM_1_ = {1,0}; /* FileN - номер файла ЭСППЗУ */ 
ssint iRM_0_ = {0,0}; /* FileOffs - смещение в файле ЭСППЗУ */ 
ssint iRM_4_ = {4,0}; /* p */ 
ssfloat fRM_0_0 = {0.0,0}; /* Стартовая координата ИС по умолчанию */ 
ssfloat fRM_1500_0 = {1500.0,0}; /* Стартовая координата АЗ2/ДС2 по умолчанию */ 
ssfloat fRM_100_ = {100,0}; /* Стартовая координата ББ по умолчанию */ 
ssint iRM_2_ = {2,0}; /* p */ 
ssint iRM_1_ = {1,0}; /* p */ 
ssint iRM_3_ = {3,0}; /* p */ 
ssint iRM_11_ = {11,0}; /* p */ 
ssint iRM_5_ = {5,0}; /* p */ 
ssint iRM_6_ = {6,0}; /* p */ 
ssbool lRM_1_ = {1,0}; /* A-Граница участка насыщения А */ 
ssbool lRM_0_ = {0,0}; /* B-Граница участка насыщения В */ 
sslong dRM_0_ = {0,0}; /* lx вход лонг */ 
sschar bRM_0_ = {0,0}; /* cx вход байтовый */ 
ssint iRM_21_ = {21,0}; /* N-число входов */ 
ssint iRM_17_ = {17,0}; /* N-число входов */ 
ssint iRM_7_ = {7,0}; /* N-число входов */ 
ssint iRM_20_ = {20,0}; /* N-число входов */ 
ssint iRM_18_ = {18,0}; /* N-число входов */ 
ssint iRM_80_ = {80,0}; /* N-число входов */ 
ssint iRM_10_ = {10,0}; /* N-число входов */ 
ssint iRM_150_ = {150,0}; /* N-число входов */ 
ssint iRM_12_ = {12,0}; /* N-число входов */ 
ssint iRM_60_ = {60,0}; /* N-число входов */ 
ssint iRM_9_ = {9,0}; /* p */ 
ssint iRM_16_ = {16,0}; /* n - N-размерность массива x */ 
ssfloat fRM_0_ = {0,0}; /* x - массив входных параметров */ 
ssint iRM_13_ = {13,0}; /* N-число входов */ 
ssint iRM_3276_ = {3276,0}; /* a */ 
ssint iRM_16000_ = {16000,0}; /* b */ 
sschar bRM_2_ = {2,0}; /* type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец */ 
sschar bRM_3_ = {3,0}; /* type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец */ 
sschar bRM_4_ = {4,0}; /* type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец */ 
sschar bRM_5_ = {5,0}; /* type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец */ 
sschar bRM_6_ = {6,0}; /* type - тип проверки 1-ини,2-ву ис,3-2ур,4-нуп ис,5-ву рб, 6-конец */ 
ssfloat fRM_160_ = {160,0}; /* x - массив входных параметров */ 
ssfloat fRM_20_ = {20,0}; /* x - массив входных параметров */ 
ssfloat fRM_20_03 = {20.03,0}; /* X2 */ 
ssfloat fRM_20_0 = {20.0,0}; /* X2 */ 
ssfloat fRM_2_0 = {2.0,0}; /* tz - время задержки */ 
ssfloat fRM_3_0 = {3.0,0}; /* tz - время задержки */ 
ssfloat fRM_2_5 = {2.5,0}; /* tz - время задержки */ 
ssfloat fRM_15_0 = {15.0,0}; /* tz - время задержки */ 
ssfloat fRM_0_002 = {0.002,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_005 = {0.005,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_007 = {0.007,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_01 = {0.01,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_015 = {0.015,0}; /* x - массив входных параметров */ 
ssfloat fRM_0_02 = {0.02,0}; /* x - массив входных параметров */ 
ssfloat fRM_1_7 = {1.7,0}; /* x - массив входных параметров */ 
ssfloat fRM_10_0 = {10.0,0}; /* tz - время задержки */ 
ssfloat fRM_0_15 = {0.15,0}; /* tz - ширина импульса, sek */ 
ssfloat fRM_0_2 = {0.2,0}; /* tz - ширина импульса, sek */ 
ssfloat fRM_0_5 = {0.5,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_3_5 = {3.5,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_6_5 = {6.5,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_9_5 = {9.5,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_12_5 = {12.5,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_15_5 = {15.5,0}; /* Tpr - время завершения проверки сек от старта программы */ 
ssfloat fRM_30_0 = {30.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_50_0 = {50.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_70_0 = {70.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_90_0 = {90.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_110_0 = {110.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_130_0 = {130.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_150_0 = {150.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_170_0 = {170.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_200_0 = {200.0,0}; /* Tpr - время окончания проверки сек от старта программы */ 
ssfloat fRM_6_0 = {6.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_126_0 = {126.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_246_0 = {246.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_366_0 = {366.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_486_0 = {486.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_606_0 = {606.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_726_0 = {726.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_846_0 = {846.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_966_0 = {966.0,0}; /* Tpr - время начала проверки сек от старта программы */ 
ssfloat fRM_1200_0 = {1200.0,0}; /* Tpr - время завершения проверки сек от старта программы */ 
ssfloat fRM_2000_ = {2000,0}; /* Lt_bw - шкала координат выбора скорости движения назад(мм) */ 
ssfloat fRM_390_ = {390,0}; /* Kt - текущее, известное(контрольное) положение механизма, мм */ 
ssfloat fRM_390_0 = {390.0,0}; /* Kt - текущее, известное(контрольное) положение механизма, мм */ 
ssfloat fRM_1000_ = {1000,0}; /* Lt_fw - шкала координат выбора скорости движения вперёд(мм) */ 
ssfloat fRM_210_0 = {210.0,0}; /* Время задержки подъёма ОРР после сброса (сек) */ 
ssfloat fRM_100_0001 = {100.0001,0}; /* X2 */ 
ssfloat fRM_0_0001 = {0.0001,0}; /* X1 */ 
ssfloat fRM_100_0 = {100.0,0}; /* x1 - первый входной параметр */ 
ssfloat fRM_160_0001 = {160.0001,0}; /* X2 */ 
ssfloat fRM_160_00001 = {160.00001,0}; /* X2 */ 
ssfloat fRM_389_99 = {389.99,0}; /* X1 */ 
ssfloat fRM_1500_0001 = {1500.0001,0}; /* X2 */ 
ssint iRM_47_ = {47,0}; /* n - N-размерность массива входных параметров */ 
ssfloat fRM_3_ = {3,0}; /* tz - время задержки сек */ 
ssfloat fRM_55_0 = {55.0,0}; /* X1 */ 
ssint iRM_14_ = {14,0}; /* n - N-размерность массива входных параметров */ 
ssfloat fRM_1_0 = {1.0,0}; /* tz - ширина импульса, sek */ 
ssfloat fRM_1_ = {1,0}; /*  */ 

uspaint8 SpaEEPROMBuf[816];

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
ssfloat var62;
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
ssbool var126;
ssbool var127;
ssbool var128;
ssbool var129;
ssbool var130;
ssbool var131;
ssbool var132;
ssbool var133;
ssbool var134;
ssbool var135;
ssbool var136;
ssbool var137;
ssbool var138;
ssbool var139;
ssbool var140;
ssbool var141;
ssbool var142;
ssbool var143;
ssbool var144;
ssbool var145;
ssbool var146;
ssbool var147;
ssbool var148;
ssbool var149;
ssbool var150;
ssbool var151;
ssbool var152;
ssbool var153;
ssbool var154;
ssbool var155;
ssbool var156;
ssbool var157;
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
ssbool var168;
ssbool var169;
ssbool var170;
ssbool var171;
ssbool var172;
ssbool var173;
ssbool var174;
ssbool var175;
ssbool var176;
ssbool var177;
ssbool var178;
ssbool var179;
ssbool var180;
ssbool var181;
ssbool var182;
ssbool var183;
ssbool var184;
ssbool var185;
ssbool var186;
ssbool var187;
ssbool var188;
ssbool var189;
ssbool var190;
ssbool var191;
ssbool var192;
ssbool var193;
ssbool var194;
ssbool var195;
ssbool var196;
ssbool var197;
ssbool var198;
ssbool var199;
ssbool var200;
ssbool var201;
ssbool var202;
ssbool var203;
ssbool var204;
ssbool var205;
ssbool var206;
ssbool var207;
ssbool var208;
ssbool var209;
ssbool var210;
ssbool var211;
ssbool var212;
ssbool var213;
ssbool var214;
ssbool var215;
ssbool var216;
ssbool var217;
ssbool var218;
ssbool var219;
ssbool var220;
ssbool var221;
ssbool var222;
ssbool var223;
ssbool var224;
ssbool var225;
ssbool var226;
ssbool var227;
ssbool var228;
ssbool var229;
ssbool var230;
ssbool var231;
ssbool var232;
ssbool var233;
ssbool var234;
ssbool var235;
ssbool var236;
ssbool var237;
ssbool var238;
ssbool var239;
ssbool var240;
ssbool var241;
ssbool var242;
ssbool var243;
ssbool var244;
ssbool var245;
ssbool var246;
ssbool var247;
ssbool var248;
ssbool var249;
ssbool var250;
ssbool var251;
ssbool var252;
ssbool var253;
ssbool var254;
ssbool var255;
ssbool var256;
ssbool var257;
ssbool var258;
ssbool var259;
ssbool var260;
ssbool var261;
ssbool var262;
ssbool var263;
ssbool var264;
ssbool var265;
ssbool var266;
ssbool var267;
ssbool var268;
ssbool var269;
ssbool var270;
ssbool var271;
ssbool var272;
ssbool var273;
ssbool var274;
ssbool var275;
ssbool var276;
ssbool var277;
ssbool var278;
ssint var279;
ssbool var280;
ssbool var281;
ssbool var282;
ssbool var283;
ssbool var284;
ssbool var285;
ssbool var286;
ssbool var287;
ssbool var288;
ssbool var289;
ssbool var290;
ssbool var291;
ssbool var292;
ssbool var293;
ssbool var294;
ssbool var295;
ssbool var296;
ssbool var297;
ssbool var298;
ssbool var299;
ssbool var300;
ssbool var301;
ssbool var302;
ssbool var303;
ssbool var304;
ssbool var305;
ssbool var306;
ssbool var307;
ssbool var308;
ssbool var309;
ssbool var310;
ssbool var311;
ssbool var312;
ssbool var313;
ssbool var314;
ssbool var315;
ssbool var316;
ssbool var317;
ssbool var318;
ssbool var319;
ssbool var320;
ssbool var321;
ssbool var322;
ssbool var323;
ssbool var324;
ssbool var325;
ssbool var326;
ssbool var327;
ssbool var328;
ssbool var329;
ssbool var330;
ssbool var331;
ssbool var332;
ssbool var333;
ssbool var334;
ssbool var335;
ssbool var336;
ssbool var337;
ssbool var338;
ssbool var339;
ssbool var340;
ssbool var341;
ssbool var342;
ssbool var343;
ssbool var344;
ssbool var345;
ssbool var346;
ssbool var347;
ssbool var348;
ssbool var349;
ssbool var350;
ssbool var351;
ssbool var352;
ssbool var353;
ssbool var354;
ssbool var355;
ssbool var356;
ssbool var357;
ssbool var358;
ssbool var359;
ssbool var360;
ssbool var361;
ssbool var362;
ssbool var363;
ssbool var364;
ssbool var365;
ssbool var366;
ssbool var367;
ssbool var368;
ssbool var369;
ssbool var370;
ssbool var371;
ssbool var372;
ssbool var373;
ssbool var374;
ssbool var375;
ssbool var376;
ssbool var377;
ssbool var378;
ssbool var379;
ssbool var380;
ssbool var381;
ssbool var382;
ssbool var383;
ssbool var384;
ssbool var385;
ssbool var386;
ssbool var387;
ssbool var388;
ssbool var389;
ssbool var390;
ssbool var391;
ssbool var392;
ssbool var393;
ssbool var394;
ssbool var395;
ssbool var396;
ssbool var397;
ssbool var398;
ssbool var399;
ssbool var400;
ssbool var401;
ssbool var402;
ssbool var403;
ssbool var404;
ssint var405;
ssbool var406;
ssbool var407;
ssint var408;
ssbool var409;
ssbool var410;
ssbool var411;
ssbool var412;
ssbool var413;
ssbool var414;
ssbool var415;
ssbool var416;
ssbool var417;
ssbool var418;
ssbool var419;
ssbool var420;
ssbool var421;
ssbool var422;
ssbool var423;
ssbool var424;
ssbool var425;
ssbool var426;
ssbool var427;
ssbool var428;
ssbool var429;
ssbool var430;
ssbool var431;
ssbool var432;
ssbool var433;
ssbool var434;
ssbool var435;
ssbool var436;
ssbool var437;
ssbool var438;
ssbool var439;
ssbool var440;
ssbool var441;
ssbool var442;
ssbool var443;
ssbool var444;
ssbool var445;
ssbool var446;
ssbool var447;
ssbool var448;
ssfloat var449;
ssbool var450;
ssbool var451;
ssbool var452;
ssbool var453;
ssbool var454;
ssbool var455;
ssbool var456;
ssbool var457;
ssbool var458;
ssfloat var459;
ssfloat var460;
ssbool var461;
ssbool var462;
ssbool var463;
ssfloat var464;
ssbool var465;
ssbool var466;
ssfloat var467;
ssbool var468;
ssbool var469;
ssbool var470;
ssbool var471;
ssbool var472;
ssbool var473;
ssbool var474;
ssbool var475;
ssfloat var476;
ssfloat var477;
ssfloat var478;
ssfloat var479;
ssbool var480;
ssfloat var481;
ssfloat var482;
ssint var483;
ssbool var484;
ssbool var485;
ssbool var486;
ssbool var487;
ssbool var488;
ssbool var489;
ssbool var490;
ssbool var491;
ssbool var492;
ssbool var493;
ssbool var494;
ssbool var495;
ssbool var496;
ssbool var497;
ssbool var498;
ssbool var499;
ssbool var500;
ssbool var501;
ssbool var502;
ssbool var503;
ssbool var504;
ssbool var505;
ssbool var506;
ssbool var507;
ssbool var508;
ssbool var509;
ssbool var510;
ssbool var511;
ssbool var512;
ssbool var513;
ssbool var514;
ssbool var515;
ssbool var516;
ssbool var517;
ssbool var518;
ssbool var519;
ssbool var520;
ssbool var521;
ssbool var522;
ssbool var523;
ssbool var524;
ssbool var525;
ssbool var526;
ssbool var527;
ssbool var528;
ssbool var529;
ssbool var530;
ssbool var531;
ssbool var532;
ssbool var533;
ssbool var534;
ssbool var535;
ssbool var536;
ssbool var537;
ssbool var538;
ssbool var539;
ssbool var540;
ssbool var541;
ssbool var542;
ssbool var543;
ssbool var544;
ssbool var545;
ssbool var546;
ssbool var547;
ssbool var548;
ssbool var549;
ssbool var550;
ssbool var551;
ssbool var552;
ssbool var553;
ssbool var554;
ssbool var555;
ssbool var556;
ssbool var557;
ssbool var558;
ssbool var559;
ssbool var560;
ssbool var561;
ssbool var562;
ssbool var563;
ssbool var564;
ssbool var565;
ssbool var566;
ssbool var567;
ssbool var568;
ssbool var569;
ssbool var570;
ssbool var571;
ssbool var572;
ssbool var573;
ssfloat var574;
ssbool var575;
ssbool var576;
ssbool var577;
ssfloat var578;
ssbool var579;
ssbool var580;
ssbool var581;
ssfloat var582;
ssbool var583;
ssbool var584;
ssbool var585;
ssfloat var586;
ssbool var587;
ssbool var588;
ssbool var589;
ssfloat var590;
ssbool var591;
ssbool var592;
ssbool var593;
ssbool var594;
ssbool var595;
ssbool var596;
ssbool var597;
ssbool var598;
ssbool var599;
ssbool var600;
ssbool var601;
ssbool var602;
ssbool var603;
ssbool var604;
ssbool var605;
ssbool var606;
ssbool var607;
ssbool var608;
ssbool var609;
ssbool var610;
ssbool var611;
ssbool var612;
ssbool var613;
ssbool var614;
ssbool var615;
ssbool var616;
ssbool var617;
ssbool var618;
ssbool var619;
ssbool var620;
ssbool var621;
ssbool var622;
ssbool var623;
ssbool var624;
ssbool var625;
ssbool var626;
ssbool var627;
ssbool var628;
ssbool var629;
ssbool var630;
ssbool var631;
ssbool var632;
ssbool var633;
ssbool var634;
ssbool var635;
ssbool var636;
ssbool var637;
ssbool var638;
ssbool var639;
ssbool var640;
ssbool var641;
ssbool var642;
ssbool var643;
ssbool var644;
ssbool var645;
ssbool var646;
ssbool var647;
ssbool var648;
ssbool var649;
ssbool var650;
ssbool var651;
ssbool var652;
ssbool var653;
ssbool var654;
ssbool var655;
ssbool var656;
ssbool var657;
ssbool var658;
ssbool var659;
ssbool var660;
ssbool var661;
ssbool var662;
ssbool var663;
ssbool var664;
ssbool var665;
ssbool var666;
ssbool var667;
ssbool var668;
ssbool var669;
ssbool var670;
ssbool var671;
ssbool var672;
ssbool var673;
ssbool var674;
ssbool var675;
ssfloat var676;
ssfloat var677;
ssbool var678;
ssfloat var679;
ssfloat var680;
ssbool var681;
ssfloat var682;
ssfloat var683;
ssbool var684;
ssfloat var685;
ssfloat var686;
ssbool var687;
ssbool var688;
ssfloat var689;
ssfloat var690;
ssbool var691;
ssbool var692;
ssbool var693;
ssbool var694;
ssbool var695;
ssbool var696;
ssbool var697;
ssbool var698;
ssbool var699;
ssbool var700;
ssbool var701;
ssbool var702;
ssbool var703;
ssbool var704;
ssbool var705;
ssbool var706;
ssbool var707;
ssbool var708;
ssbool var709;
ssbool var710;
ssbool var711;
ssbool var712;
ssbool var713;
ssbool var714;
ssbool var715;
ssbool var716;
ssbool var717;
ssbool var718;
ssbool var719;
ssbool var720;
ssbool var721;
ssbool var722;
ssbool var723;
ssbool var724;
ssbool var725;
ssbool var726;
ssbool var727;
ssbool var728;
ssbool var729;
ssbool var730;
ssbool var731;
ssbool var732;
ssbool var733;
ssbool var734;
ssbool var735;
ssbool var736;
ssbool var737;
ssbool var738;
ssbool var739;
ssbool var740;
ssbool var741;
ssbool var742;
ssbool var743;
ssbool var744;
ssbool var745;
ssbool var746;
ssbool var747;
ssbool var748;
ssbool var749;
ssbool var750;
ssbool var751;
ssbool var752;
ssbool var753;
ssbool var754;
ssbool var755;
ssbool var756;
ssbool var757;
ssbool var758;
ssbool var759;
ssbool var760;
ssbool var761;
ssbool var762;
ssbool var763;
ssbool var764;
ssbool var765;
ssbool var766;
ssbool var767;
ssbool var768;
ssbool var769;
ssbool var770;
ssbool var771;
ssbool var772;
ssbool var773;
ssbool var774;
ssbool var775;
ssbool var776;
ssbool var777;
ssbool var778;
ssbool var779;
ssbool var780;
ssbool var781;
ssbool var782;
ssbool var783;
ssbool var784;
ssbool var785;
ssbool var786;
ssbool var787;
ssbool var788;
ssbool var789;
ssbool var790;
ssbool var791;
ssbool var792;
ssbool var793;
ssbool var794;
ssbool var795;
ssbool var796;
ssbool var797;
ssbool var798;
ssbool var799;
ssbool var800;
ssbool var801;
ssbool var802;
ssbool var803;
ssbool var804;
ssbool var805;
ssbool var806;
ssbool var807;
ssbool var808;
ssbool var809;
ssbool var810;
ssbool var811;
ssbool var812;
ssbool var813;
ssbool var814;
ssbool var815;
ssbool var816;
ssbool var817;
ssbool var818;
ssbool var819;
sslong var820;
ssbool var821;
ssbool var822;
ssbool var823;
ssbool var824;
ssbool var825;
ssbool var826;
ssbool var827;
ssbool var828;
ssbool var829;
ssbool var830;
ssbool var831;
ssbool var832;
ssbool var833;
ssbool var834;
ssbool var835;
ssbool var836;
ssbool var837;
ssbool var838;
ssbool var839;
ssbool var840;
ssbool var841;
ssbool var842;
ssbool var843;
ssbool var844;
ssbool var845;
ssbool var846;
ssbool var847;
ssbool var848;
ssbool var849;
ssbool var850;
ssbool var851;
ssbool var852;
ssbool var853;
ssbool var854;
ssbool var855;
ssbool var856;
ssbool var857;
ssbool var858;
ssbool var859;
ssbool var860;
ssbool var861;
ssbool var862;
ssbool var863;
ssbool var864;
ssbool var865;
ssbool var866;
ssbool var867;
ssbool var868;
ssbool var869;
ssbool var870;
ssbool var871;
ssbool var872;
ssbool var873;
ssbool var874;
ssbool var875;
ssbool var876;
ssbool var877;
ssbool var878;
ssbool var879;
ssbool var880;
ssbool var881;
ssbool var882;
ssbool var883;
ssbool var884;
ssbool var885;
ssbool var886;
ssbool var887;
ssbool var888;
ssbool var889;
ssbool var890;
ssbool var891;
ssbool var892;
ssbool var893;
ssbool var894;
ssbool var895;
ssbool var896;
ssbool var897;
ssbool var898;
ssbool var899;
ssbool var900;
ssbool var901;
ssbool var902;
ssbool var903;
ssbool var904;
ssbool var905;
ssbool var906;
ssbool var907;
ssbool var908;
ssbool var909;
ssbool var910;
ssbool var911;
ssbool var912;
ssbool var913;
ssbool var914;
ssbool var915;
ssbool var916;
ssbool var917;
ssbool var918;
ssbool var919;
ssbool var920;
ssbool var921;
ssbool var922;
ssbool var923;
ssbool var924;
ssbool var925;
ssbool var926;
ssbool var927;
ssbool var928;
ssbool var929;
ssbool var930;
ssbool var931;
ssbool var932;
ssbool var933;
ssbool var934;
ssbool var935;
ssbool var936;
ssbool var937;
ssbool var938;
ssbool var939;
ssbool var940;
ssbool var941;
ssbool var942;
ssbool var943;
ssbool var944;
ssbool var945;
ssbool var946;
ssbool var947;
ssbool var948;
ssbool var949;
ssbool var950;
ssbool var951;
ssbool var952;
ssbool var953;
ssbool var954;
ssbool var955;
ssbool var956;
ssbool var957;
ssbool var958;
ssbool var959;
ssbool var960;
ssbool var961;
ssbool var962;
ssbool var963;
ssbool var964;
ssbool var965;
ssbool var966;
ssbool var967;
ssbool var968;
ssbool var969;
ssbool var970;
ssbool var971;
ssbool var972;
ssbool var973;
ssbool var974;
ssbool var975;
ssbool var976;
ssbool var977;
ssbool var978;
ssbool var979;
ssbool var980;
ssbool var981;
ssbool var982;
ssbool var983;
ssbool var984;
ssbool var985;
ssbool var986;
ssbool var987;
ssbool var988;
ssbool var989;
ssbool var990;
ssbool var991;
ssbool var992;
ssbool var993;
ssbool var994;
ssbool var995;
ssbool var996;
ssbool var997;
ssbool var998;
ssbool var999;
ssbool var1000;
ssbool var1001;
ssbool var1002;
ssbool var1003;
ssbool var1004;
ssbool var1005;
ssbool var1006;
ssbool var1007;
ssbool var1008;
ssbool var1009;
ssbool var1010;
ssbool var1011;
ssbool var1012;
ssbool var1013;
ssbool var1014;
ssbool var1015;
ssbool var1016;
ssbool var1017;
ssbool var1018;
ssbool var1019;
ssbool var1020;
ssbool var1021;
ssbool var1022;
ssbool var1023;
ssbool var1024;
ssbool var1025;
ssbool var1026;
ssbool var1027;
ssbool var1028;
ssbool var1029;
ssbool var1030;
ssbool var1031;
ssbool var1032;
ssbool var1033;
ssbool var1034;
ssbool var1035;
ssbool var1036;
ssbool var1037;
ssbool var1038;
ssbool var1039;
ssbool var1040;
ssbool var1041;
ssbool var1042;
ssbool var1043;
ssbool var1044;
ssbool var1045;
ssbool var1046;
ssbool var1047;
ssbool var1048;
ssbool var1049;
ssbool var1050;
ssbool var1051;
ssbool var1052;
ssbool var1053;
ssbool var1054;
ssbool var1055;
ssbool var1056;
ssbool var1057;
ssbool var1058;
ssbool var1059;
ssbool var1060;
ssbool var1061;
ssbool var1062;
ssbool var1063;
ssbool var1064;
ssbool var1065;
ssbool var1066;
ssbool var1067;
ssbool var1068;
ssbool var1069;
ssbool var1070;
ssbool var1071;
ssbool var1072;
ssbool var1073;
ssbool var1074;
ssbool var1075;
ssbool var1076;
ssbool var1077;
ssbool var1078;
ssbool var1079;
ssbool var1080;
ssbool var1081;
ssbool var1082;
ssbool var1083;
ssbool var1084;
ssbool var1085;
ssbool var1086;
ssbool var1087;
ssbool var1088;
ssbool var1089;
ssbool var1090;
ssbool var1091;
ssbool var1092;
ssbool var1093;
ssbool var1094;
ssbool var1095;
ssbool var1096;
ssbool var1097;
ssbool var1098;
ssbool var1099;
ssbool var1100;
ssbool var1101;
ssbool var1102;
ssbool var1103;
ssbool var1104;
ssbool var1105;
ssbool var1106;
ssbool var1107;
ssbool var1108;
ssbool var1109;
ssbool var1110;
ssbool var1111;
ssbool var1112;
ssbool var1113;
ssbool var1114;
ssbool var1115;
ssbool var1116;
ssbool var1117;
ssbool var1118;
ssbool var1119;
ssbool var1120;
ssbool var1121;
ssbool var1122;
ssbool var1123;
ssbool var1124;
ssbool var1125;
ssbool var1126;
ssbool var1127;
ssbool var1128;
ssbool var1129;
ssbool var1130;
ssbool var1131;
ssbool var1132;
ssbool var1133;
ssbool var1134;
ssbool var1135;
ssbool var1136;
ssbool var1137;
ssbool var1138;
ssbool var1139;
ssbool var1140;
ssbool var1141;
ssbool var1142;
ssbool var1143;
ssbool var1144;
ssbool var1145;
ssbool var1146;
ssbool var1147;
ssbool var1148;
ssbool var1149;
ssbool var1150;
ssbool var1151;
ssbool var1152;
ssbool var1153;
ssbool var1154;
ssbool var1155;
ssbool var1156;
ssbool var1157;
ssbool var1158;
ssbool var1159;
ssbool var1160;
ssbool var1161;
ssbool var1162;
ssbool var1163;
ssbool var1164;
ssbool var1165;
ssbool var1166;
ssbool var1167;
ssbool var1168;
ssbool var1169;
ssbool var1170;
ssbool var1171;
ssbool var1172;
ssbool var1173;
ssbool var1174;
ssbool var1175;
ssbool var1176;
ssbool var1177;
ssbool var1178;
ssbool var1179;
ssbool var1180;
ssbool var1181;
ssbool var1182;
ssbool var1183;
ssbool var1184;
ssbool var1185;
ssbool var1186;
ssbool var1187;
ssbool var1188;
ssbool var1189;
ssbool var1190;
ssbool var1191;
ssbool var1192;
ssbool var1193;
ssbool var1194;
ssbool var1195;
ssbool var1196;
ssbool var1197;
ssbool var1198;
ssbool var1199;
ssbool var1200;
ssbool var1201;
ssbool var1202;
ssbool var1203;
ssbool var1204;
ssbool var1205;
ssbool var1206;
ssbool var1207;
ssbool var1208;
ssbool var1209;
ssbool var1210;
ssbool var1211;
ssbool var1212;
ssbool var1213;
ssbool var1214;
ssbool var1215;
ssbool var1216;
ssbool var1217;
ssbool var1218;
ssbool var1219;
ssbool var1220;
ssbool var1221;
ssbool var1222;
ssbool var1223;
ssbool var1224;
ssbool var1225;
ssbool var1226;
ssbool var1227;
ssbool var1228;
ssbool var1229;
ssfloat var1230;
ssbool var1231;
ssfloat var1232;
ssbool var1233;
ssfloat var1234;
ssbool var1235;
ssbool var1236;
ssbool var1237;
ssbool var1238;
ssfloat var1239;
ssfloat var1240;
ssfloat var1241;
ssfloat var1242;
ssfloat var1243;
ssfloat var1244;
ssbool var1245;
ssbool var1246;
ssbool var1247;
ssbool var1248;
ssbool var1249;
ssbool var1250;
ssbool var1251;
ssbool var1252;
ssbool var1253;
ssbool var1254;
ssbool var1255;
ssbool var1256;
ssbool var1257;
ssbool var1258;
ssbool var1259;
ssbool var1260;
ssbool var1261;
ssbool var1262;
ssbool var1263;
ssbool var1264;
ssbool var1265;
ssbool var1266;
ssbool var1267;
ssbool var1268;
ssbool var1269;
ssbool var1270;
ssbool var1271;
ssbool var1272;
ssbool var1273;
ssbool var1274;
ssbool var1275;
ssbool var1276;
ssbool var1277;
ssbool var1278;
ssbool var1279;
ssbool var1280;
ssbool var1281;
ssbool var1282;
ssbool var1283;
ssbool var1284;
ssbool var1285;
ssbool var1286;
ssbool var1287;
ssbool var1288;
ssbool var1289;
ssbool var1290;
ssbool var1291;
ssbool var1292;
ssbool var1293;
ssbool var1294;
ssbool var1295;
ssbool var1296;
ssbool var1297;
ssbool var1298;
ssbool var1299;
ssbool var1300;
ssbool var1301;
ssbool var1302;
ssbool var1303;
ssint var1304;
ssint var1305;
ssbool var1306;
ssbool var1307;
ssbool var1308;
ssbool var1309;
ssbool var1310;
ssbool var1311;
sslong var1312;
ssbool var1313;
ssbool var1314;
ssbool var1315;
ssint var1316;
ssbool var1317;
ssbool var1318;
ssbool var1319;
ssbool var1320;
ssbool var1321;
ssbool var1322;
ssbool var1323;
ssbool var1324;
ssbool var1325;
ssint var1326;
ssint var1327;
ssbool var1328;
ssbool var1329;
ssbool var1330;
ssbool var1331;
ssbool var1332;
ssbool var1333;
ssbool var1334;
ssbool var1335;
ssbool var1336;
ssbool var1337;
ssbool var1338;
ssbool var1339;
ssbool var1340;
ssbool var1341;
ssbool var1342;
ssbool var1343;
ssbool var1344;
ssbool var1345;
ssbool var1346;
ssbool var1347;
ssbool var1348;
ssbool var1349;
ssbool var1350;
ssbool var1351;
ssbool var1352;
ssbool var1353;
ssbool var1354;
ssbool var1355;
ssbool var1356;
ssbool var1357;
ssbool var1358;
ssbool var1359;
ssbool var1360;
ssbool var1361;
ssbool var1362;
ssbool var1363;
ssbool var1364;
ssbool var1365;
ssbool var1366;
sslong var1367;
ssbool var1368;
ssbool var1369;
ssbool var1370;
ssbool var1371;
ssbool var1372;
ssbool var1373;
ssbool var1374;
ssbool var1375;
ssbool var1376;
ssbool var1377;
ssbool var1378;
ssbool var1379;
ssbool var1380;
ssbool var1381;
ssbool var1382;
ssbool var1383;
ssbool var1384;
ssbool var1385;
ssfloat var1386;
ssbool var1387;
ssbool var1388;
ssbool var1389;
ssbool var1390;
ssbool var1391;
ssfloat var1392;
ssbool var1393;
ssbool var1394;
ssbool var1395;
ssbool var1396;
ssbool var1397;
ssbool var1398;
ssbool var1399;
ssbool var1400;
ssbool var1401;
ssbool var1402;
ssbool var1403;
ssbool var1404;
ssbool var1405;
ssint var1406;
ssbool var1407;
ssbool var1408;
ssbool var1409;
ssbool var1410;
ssbool var1411;
ssbool var1412;
ssbool var1413;
ssbool var1414;
ssbool var1415;
ssbool var1416;
ssbool var1417;
ssbool var1418;
ssbool var1419;
ssbool var1420;
ssbool var1421;
ssbool var1422;
ssbool var1423;
ssbool var1424;
ssbool var1425;
ssbool var1426;
ssbool var1427;
ssbool var1428;
ssbool var1429;
ssbool var1430;
ssfloat var1431;
ssbool var1432;
ssbool var1433;
ssbool var1434;
ssbool var1435;
ssbool var1436;
ssbool var1437;
ssbool var1438;
ssbool var1439;
ssbool var1440;
ssbool var1441;
ssbool var1442;
ssbool var1443;
ssbool var1444;
ssbool var1445;
ssbool var1446;
ssbool var1447;
ssbool var1448;
ssbool var1449;
ssbool var1450;
ssbool var1451;
ssbool var1452;
ssbool var1453;
ssbool var1454;
ssbool var1455;
ssbool var1456;
ssbool var1457;
ssbool var1458;
ssbool var1459;
ssbool var1460;
ssbool var1461;
ssbool var1462;
ssbool var1463;
ssbool var1464;
ssbool var1465;
ssbool var1466;
ssbool var1467;
ssbool var1468;
ssbool var1469;
ssbool var1470;
ssbool var1471;
ssbool var1472;
ssbool var1473;
ssbool var1474;
ssbool var1475;
ssbool var1476;
ssbool var1477;
ssbool var1478;
ssbool var1479;
ssbool var1480;
ssbool var1481;
ssbool var1482;
ssbool var1483;
ssbool var1484;
ssbool var1485;
ssbool var1486;
ssbool var1487;
ssbool var1488;
ssbool var1489;
ssbool var1490;
ssbool var1491;
ssbool var1492;
ssbool var1493;
ssbool var1494;
ssbool var1495;
ssbool var1496;
ssbool var1497;
ssbool var1498;
ssbool var1499;
ssbool var1500;
ssbool var1501;
ssbool var1502;
ssbool var1503;
ssbool var1504;
ssbool var1505;
ssbool var1506;
ssbool var1507;
ssbool var1508;
ssbool var1509;
ssbool var1510;
ssbool var1511;
ssbool var1512;
ssbool var1513;
ssbool var1514;
ssbool var1515;
ssbool var1516;
ssbool var1517;
ssbool var1518;
ssbool var1519;
ssbool var1520;
ssbool var1521;
ssbool var1522;
ssbool var1523;
ssbool var1524;
sslong var1525;
ssbool var1526;
ssint var1527;
ssint var1528;
ssbool var1529;
ssfloat var1530;
ssfloat var1531;
ssfloat var1532;
ssbool var1533;
ssbool var1534;
ssbool var1535;
ssbool var1536;
ssbool var1537;
ssbool var1538;
ssbool var1539;
ssbool var1540;
ssbool var1541;
ssbool var1542;
ssbool var1543;
ssbool var1544;
ssbool var1545;
ssbool var1546;
ssbool var1547;
ssbool var1548;
ssint var1549;
ssbool var1550;
sschar var1551;
ssint var1552;
ssbool var1553;
ssfloat var1554;
ssbool var1555;
ssbool var1556;
ssbool var1557;
ssbool var1558;
ssbool var1559;
ssbool var1560;
ssbool var1561;
ssfloat var1562;
sschar var1563;
ssbool var1564;
ssbool var1565;
ssbool var1566;
ssbool var1567;
ssfloat var1568;
ssbool var1569;
ssbool var1570;
ssbool var1571;
ssbool var1572;
ssbool var1573;
ssbool var1574;
ssbool var1575;
ssbool var1576;
ssbool var1577;
ssbool var1578;
ssbool var1579;
ssbool var1580;
ssint var1581;
ssbool var1582;
sschar var1583;
ssint var1584;
ssbool var1585;
ssfloat var1586;
ssbool var1587;
ssbool var1588;
ssbool var1589;
ssbool var1590;
ssbool var1591;
ssbool var1592;
ssbool var1593;
ssfloat var1594;
sschar var1595;
ssbool var1596;
ssbool var1597;
ssbool var1598;
ssbool var1599;
ssfloat var1600;
ssbool var1601;
ssbool var1602;
ssbool var1603;
ssbool var1604;
ssbool var1605;
ssbool var1606;
ssbool var1607;
ssbool var1608;
ssbool var1609;
ssint var1610;
ssbool var1611;
sschar var1612;
ssint var1613;
ssbool var1614;
ssfloat var1615;
ssbool var1616;
ssbool var1617;
ssbool var1618;
ssbool var1619;
ssbool var1620;
ssbool var1621;
ssbool var1622;
ssfloat var1623;
sschar var1624;
ssbool var1625;
ssbool var1626;
ssbool var1627;
ssbool var1628;
ssfloat var1629;
ssbool var1630;
ssbool var1631;
ssbool var1632;
ssbool var1633;
ssbool var1634;
ssbool var1635;
ssbool var1636;
ssbool var1637;
ssbool var1638;
ssbool var1639;
ssbool var1640;
ssbool var1641;
ssbool var1642;
ssint var1643;
ssbool var1644;
sschar var1645;
ssint var1646;
ssbool var1647;
ssfloat var1648;
ssbool var1649;
ssbool var1650;
ssbool var1651;
ssbool var1652;
ssbool var1653;
ssbool var1654;
ssbool var1655;
ssfloat var1656;
sschar var1657;
ssbool var1658;
ssbool var1659;
ssfloat var1660;
ssbool var1661;
ssbool var1662;
ssbool var1663;
ssbool var1664;
ssbool var1665;
ssbool var1666;
ssbool var1667;
ssbool var1668;
ssbool var1669;
ssbool var1670;
ssbool var1671;
ssbool var1672;
ssint var1673;
ssbool var1674;
ssbool var1675;
ssbool var1676;
ssbool var1677;
ssbool var1678;
ssbool var1679;
ssbool var1680;
ssbool var1681;
ssint var1682;
ssbool var1683;
ssbool var1684;
ssbool var1685;
ssbool var1686;
ssbool var1687;
ssbool var1688;
ssbool var1689;
ssint var1690;
ssbool var1691;
sschar var1692;
ssint var1693;
ssbool var1694;
ssfloat var1695;
ssbool var1696;
ssbool var1697;
ssbool var1698;
ssbool var1699;
ssbool var1700;
ssbool var1701;
ssbool var1702;
ssfloat var1703;
sschar var1704;
ssbool var1705;
ssbool var1706;
ssfloat var1707;
ssbool var1708;
ssbool var1709;
ssbool var1710;
ssbool var1711;
ssbool var1712;
ssbool var1713;
ssbool var1714;
ssbool var1715;
sschar var1716;
ssbool var1717;
ssbool var1718;
ssbool var1719;
ssbool var1720;
ssbool var1721;
ssbool var1722;
ssbool var1723;
ssbool var1724;
ssbool var1725;
sschar var1726;
ssbool var1727;
ssbool var1728;
ssint var1729;
ssbool var1730;
sschar var1731;
ssbool var1732;
ssint var1733;
ssbool var1734;
ssbool var1735;
ssfloat var1736;
ssbool var1737;
ssbool var1738;
ssbool var1739;
ssbool var1740;
ssbool var1741;
ssbool var1742;
ssbool var1743;
ssfloat var1744;
sschar var1745;
ssbool var1746;
ssbool var1747;
ssbool var1748;
ssbool var1749;
ssfloat var1750;
ssbool var1751;
ssbool var1752;
ssbool var1753;
ssbool var1754;
ssbool var1755;
ssbool var1756;
ssbool var1757;
ssbool var1758;
ssbool var1759;
ssbool var1760;
ssbool var1761;
ssbool var1762;
ssfloat var1763;
ssbool var1764;
ssbool var1765;
ssbool var1766;
ssbool var1767;
ssbool var1768;
ssbool var1769;
ssbool var1770;
ssbool var1771;
ssbool var1772;
ssbool var1773;
ssbool var1774;
ssbool var1775;
ssbool var1776;
ssbool var1777;
ssbool var1778;
ssbool var1779;
ssfloat var1780;
ssbool var1781;
ssbool var1782;
ssbool var1783;
ssbool var1784;
ssbool var1785;
ssbool var1786;
ssbool var1787;
ssbool var1788;
ssbool var1789;
ssbool var1790;
ssbool var1791;
ssbool var1792;
ssbool var1793;
ssbool var1794;
ssbool var1795;
ssbool var1796;
ssbool var1797;
ssbool var1798;
ssbool var1799;
ssbool var1800;
ssbool var1801;
ssbool var1802;
ssbool var1803;
ssbool var1804;
ssbool var1805;
ssbool var1806;
ssbool var1807;
ssbool var1808;
ssbool var1809;
ssbool var1810;
ssbool var1811;
ssbool var1812;
ssbool var1813;
ssbool var1814;
ssbool var1815;
ssbool var1816;
ssbool var1817;
ssint var1818;
ssbool var1819;
ssbool var1820;
ssbool var1821;
ssbool var1822;
ssbool var1823;
ssbool var1824;
ssbool var1825;
ssbool var1826;
ssint var1827;
ssbool var1828;
ssbool var1829;
ssbool var1830;
ssbool var1831;
ssbool var1832;
ssbool var1833;
ssbool var1834;
ssbool var1835;
ssint var1836;
ssbool var1837;
ssbool var1838;
ssbool var1839;
ssbool var1840;
ssbool var1841;
ssbool var1842;
ssbool var1843;
ssbool var1844;
ssint var1845;
ssbool var1846;
ssbool var1847;
ssbool var1848;
ssbool var1849;
ssbool var1850;
ssbool var1851;
ssbool var1852;
ssbool var1853;
ssint var1854;
ssbool var1855;
ssbool var1856;
ssbool var1857;
ssbool var1858;
ssbool var1859;
ssbool var1860;
ssbool var1861;
ssbool var1862;
ssint var1863;
ssbool var1864;
ssbool var1865;
ssbool var1866;
ssbool var1867;
ssbool var1868;
ssbool var1869;
ssbool var1870;
ssbool var1871;
ssint var1872;
ssbool var1873;
ssbool var1874;
ssbool var1875;
ssbool var1876;
ssbool var1877;
ssbool var1878;
ssbool var1879;
ssbool var1880;
ssbool var1881;
ssbool var1882;
ssbool var1883;
ssbool var1884;
ssbool var1885;
ssbool var1886;
ssbool var1887;
ssbool var1888;
ssbool var1889;
ssbool var1890;
ssbool var1891;
ssbool var1892;
ssbool var1893;
ssbool var1894;
ssbool var1895;
ssbool var1896;
ssbool var1897;
ssbool var1898;
ssbool var1899;
ssbool var1900;
ssbool var1901;
ssbool var1902;
ssbool var1903;
ssbool var1904;
ssbool var1905;
ssbool var1906;
ssbool var1907;
ssbool var1908;
ssbool var1909;
ssbool var1910;
ssbool var1911;
ssbool var1912;
ssbool var1913;
ssbool var1914;
ssbool var1915;
ssbool var1916;
ssbool var1917;
ssbool var1918;
ssbool var1919;
ssbool var1920;
ssfloat var1921;
ssbool var1922;
ssbool var1923;
ssbool var1924;
ssbool var1925;
ssbool var1926;
ssbool var1927;
ssbool var1928;
ssbool var1929;
ssbool var1930;
ssbool var1931;
ssbool var1932;
ssbool var1933;
ssbool var1934;
ssbool var1935;
ssbool var1936;
ssbool var1937;
ssbool var1938;
ssbool var1939;
ssbool var1940;
ssbool var1941;
ssbool var1942;
ssbool var1943;
ssbool var1944;
ssbool var1945;
ssbool var1946;
ssbool var1947;
ssbool var1948;
ssbool var1949;
ssbool var1950;
ssbool var1951;
ssbool var1952;
ssbool var1953;
ssbool var1954;
ssbool var1955;
ssfloat var1956;
ssfloat var1957;
ssbool var1958;
ssbool var1959;
ssbool var1960;
ssbool var1961;
ssbool var1962;
ssbool var1963;
ssbool var1964;
ssbool var1965;
ssbool var1966;
ssbool var1967;
ssbool var1968;
ssbool var1969;
ssbool var1970;
ssbool var1971;
ssbool var1972;
ssbool var1973;
ssbool var1974;
ssbool var1975;
ssbool var1976;
ssbool var1977;
ssbool var1978;
ssbool var1979;
ssbool var1980;
ssbool var1981;
ssbool var1982;
ssbool var1983;
ssfloat var1984;
ssbool var1985;
ssbool var1986;
ssfloat var1987;
ssbool var1988;
ssbool var1989;
ssfloat var1990;
ssbool var1991;
ssbool var1992;
ssfloat var1993;
ssbool var1994;
ssbool var1995;
ssfloat var1996;
ssbool var1997;
ssbool var1998;
ssfloat var1999;
ssbool var2000;
ssbool var2001;
ssfloat var2002;
ssbool var2003;
ssbool var2004;
ssbool var2005;
ssfloat var2006;
ssbool var2007;
ssbool var2008;
ssbool var2009;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m179_x_2[13] = {&R0IE02LDU,&R0IE01LDU,&R1IE01LDU,&R2IE01LDU,&A5IE02LDU,&B5IE01LDU,&A6IE01LDU,&R6IS61LDU,&R6IS67LZZ,&R6IS68LZZ,&B6IE01LDU,&A8IE01LDU,&R6IS66LZZ};
psbool  array_m166_x_2[6] = {&var1903,&var1902,&var1901,&var1900,&var1899,&var1898};
psbool  array_m138_x_2[6] = {&var1909,&var1908,&var1907,&var1906,&var1905,&var1904};
psbool  array_m254_x_2[6] = {&var1968,&var1960,&var1974,&B0VT71LZ1,&B0VT71LZ2,&var1919};
psbool  array_m243_x_2[6] = {&var1969,&var1962,&var1975,&A0VT71LZ1,&A0VT71LZ2,&var1919};
psbool  array_m266_x_2[6] = {&var1953,&B0VP71LZ1,&B0VP71LZ2,&var1924,&var1923,&var1922};
psbool  array_m245_x_2[6] = {&var1954,&A0VP71LZ1,&A0VP71LZ2,&var1927,&var1926,&var1925};
psbool  array_m124_x_2[8] = {&var1986,&var2008,&var2004,&var2001,&var1998,&var1995,&var1989,&var1992};
psint  array_m2519_x_1[14] = {&R0DE0DLDU,&R0DE0FLDU,&R0DE02LDU,&R0DE03LDU,&R0DE04LDU,&R0DE05LDU,&R0DE07LDU,&R0DE08LDU,&R0DE09LDU,&R0DE0ALDU,&R0DE0BLDU,&R0DE0CLDU,&R0DE01LDU,&R0DE06LDU};
psbool  array_m894_x_1[6] = {&var850,&var1488,&var1464,&var1453,&var1255,&var355};
psbool  array_m1355_x_1[6] = {&var849,&var1468,&var282,&var1490,&var1255,&var375};
psbool  array_m662_x_1[6] = {&var1045,&var1358,&var1775,&var1319,&var1734,&var1352};
psbool  array_m661_x_1[6] = {&var1045,&var1359,&var1775,&var1319,&var1734,&var1351};
psfloat  array_m2426_a_1[6] = {&fEM_R0UN70LDU,&fEM_R0UN71LDU,&fEM_R0UN72LDU,&fEM_R0UN73LDU,&fEM_R0UN74LDU,&fEM_R0UN75LDU};
psfloat  array_m2426_b_1[6] = {&fEM_R0UN80LDU,&fEM_R0UN81LDU,&fEM_R0UN82LDU,&fEM_R0UN83LDU,&fEM_R0UN84LDU,&fEM_R0UN85LDU};
psfloat  array_m2437_x_1[4] = {&B0CT01IZ1,&A0CT01IZ1,&B0CT01IZ2,&A0CT01IZ2};
psbool  array_m2429_x_1[14] = {&var463,&var436,&var1079,&var496,&var498,&var434,&var1897,&var1477,&var1475,&var1920,&var462,&var451,&var447,&var470};
psbool  array_m1_x_1[47] = {&var1440,&var1880,&var595,&var330,&var734,&var1644,&var968,&R0MD34LP1,&var882,&R0MD34LP1,&var941,&R0MD34LP1,&var1175,&R0MD34LP1,&var995,&R0MD34LP1,&var1173,&var1671,&A2IS12LDU,&var651,&var1471,&var1366,&var1364,&var1277,&var1088,&R0MD34LP1,&var671,&var712,&var1515,&var1825,&R0MD34LP1,&var54,&var818,&var773,&B3IS35LDU,&B3IS35LDU,&var517,&var328,&var745,&var564,&var1876,&var1834,&var1861,&var1194,&var1848,&R2IS21LDU,&var437};
psfloat  array_m1665_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psbool  array_m1616_x_1[5] = {&var54,&var53,&var52,&var51,&var50};
psbool  array_m612_x_1[12] = {&var993,&var999,&var1000,&var991,&var992,&var1177,&var1178,&var490,&var988,&var989,&var987,&var995};
psfloat  array_m88_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m90_x_1[8] = {&fEM_R0UN01RDU,&fEM_R0UN02RDU,&fEM_R0UN03RDU,&fEM_R0UN04RDU,&fEM_R0UN05RDU,&fEM_R0UN06RDU,&fEM_R0UN07RDU,&fEM_R0UN08RDU};
psfloat  array_m1188_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m1365_x_1[8] = {&var1736,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m903_x_1[8] = {&var1695,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m1000_x_1[8] = {&var1586,&var460,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m1478_x_1[8] = {&var1554,&var459,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m544_x_1[8] = {&var1615,&var586,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m173_x_1[8] = {&var1648,&var590,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m352_Tpr_1[10] = {&fRM_6_0,&fRM_126_0,&fRM_246_0,&fRM_366_0,&fRM_486_0,&fRM_606_0,&fRM_726_0,&fRM_846_0,&fRM_966_0,&fRM_1200_0};
pschar  array_m352_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m352_rz_1[10];
psbool  array_m356_x_1[5] = {&var1307,&var1308,&var1309,&var1310,&var1311};
psbool  array_m290_x_1[7] = {&var1079,&var492,&var1286,&var1283,&var498,&var496,&var494};
psfloat  array_m294_Tpr_1[10] = {&fRM_10_0,&fRM_30_0,&fRM_50_0,&fRM_70_0,&fRM_90_0,&fRM_110_0,&fRM_130_0,&fRM_150_0,&fRM_170_0,&fRM_200_0};
pschar  array_m294_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m294_rz_1[10];
psfloat  array_m1596_Tpr_1[6] = {&fRM_0_5,&fRM_3_5,&fRM_6_5,&fRM_9_5,&fRM_12_5,&fRM_15_5};
pschar  array_m1596_type_1[6] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_6_};
pschar  array_m1596_rz_1[6];
psbool  array_m310_x_1[5] = {&var1329,&var1330,&var1331,&var1332,&var1333};
psbool  array_m1340_x_1[5] = {&var1452,&var1062,&var1807,&var1457,&var508};
psbool  array_m1324_x_1[4] = {&var1363,&var1405,&var1279,&var1455};
psfloat  array_m1649_x_1[16] = {&var676,&var685,&fRM_0_,&var682,&fRM_0_,&fRM_0_,&fRM_0_,&var679,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&var689};
psbool  array_m1984_x_1[17] = {&var756,&var757,&var763,&var758,&var754,&var755,&var1212,&var759,&var760,&var1504,&var761,&var762,&var1496,&var1497,&var1506,&var502,&var503};
psbool  array_m1600_x_1[5] = {&var668,&var791,&var808,&var809,&var698};
psint  array_m329_x_1[3] = {&var1305,&iRM_0_,&var1327};
psint  array_m320_x_1[3] = {&var1304,&iRM_0_,&var1326};
psbool  array_m664_x_1[5] = {&var1028,&var1774,&var1541,&var1256,&var468};
psbool  array_m1548_x_1[8] = {&var912,&var913,&var914,&var909,&var908,&var907,&var1173,&var905};
psbool  array_m1477_x_1[3] = {&var357,&lRM_0_,&var356};
psfloat  array_m1479_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m1479_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m1479_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m1479_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m1505_x0_1[60];
psfloat  array_m1505_tim0_1[60];
psbool  array_m1077_x_1[8] = {&var927,&var929,&var930,&var922,&var928,&var924,&var1175,&var666};
psbool  array_m999_x_1[3] = {&var383,&lRM_0_,&var378};
psfloat  array_m1001_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m1001_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m1001_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m1001_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m1031_x0_1[60];
psfloat  array_m1031_tim0_1[60];
psbool  array_m543_x_1[3] = {&var1004,&lRM_0_,&var1005};
psfloat  array_m546_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m546_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m546_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m546_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m569_x0_1[150];
psfloat  array_m569_tim0_1[150];
psbool  array_m238_x_1[12] = {&var973,&var975,&var974,&var971,&var969,&var968,&var967,&var1181,&var1180,&var962,&var965,&var491};
psbool  array_m172_x_1[3] = {&var1151,&lRM_0_,&var1152};
psfloat  array_m176_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m176_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m176_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m176_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m201_x0_1[150];
psfloat  array_m201_tim0_1[150];
psbool  array_m964_x_1[10] = {&var939,&var940,&var946,&var947,&var945,&var943,&var942,&var1183,&var1182,&var941};
psbool  array_m902_x_1[3] = {&var359,&var957,&var358};
psfloat  array_m905_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m905_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m905_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m905_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m923_x0_1[80];
psfloat  array_m923_tim0_1[80];
psfloat  array_m1800_Lt_fw_1[1] = {&fRM_1000_};
psint  array_m1800_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1800_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1800_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1445_x_1[10] = {&var878,&var879,&var881,&var880,&var882,&var884,&var886,&var883,&var885,&var887};
psbool  array_m154_x_1[5] = {&A1IS21LDU,&A3IS21LDU,&A2IS21LDU,&var1198,&var1197};
psfloat  array_m1270_Lt_fw_1[1] = {&fRM_2000_};
psint  array_m1270_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1270_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1270_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1364_x_1[3] = {&var387,&var872,&var374};
psfloat  array_m1366_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m1366_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m1366_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m1366_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m1401_x0_1[80];
psfloat  array_m1401_tim0_1[80];
psfloat  array_m1822_x0_1[20];
psfloat  array_m1822_tim0_1[20];
psbool  array_m1232_x_1[8] = {&var1089,&var1086,&var1087,&var1088,&var1085,&var1084,&var1083,&var1082};
psbool  array_m665_x_1[18] = {&R0MD31LP1,&var781,&var1103,&var783,&var1101,&var873,&var1008,&var956,&var983,&var1003,&var932,&var897,&var1159,&var607,&var606,&var863,&var524,&var461};
psfloat  array_m1296_x0_1[20];
psfloat  array_m1296_tim0_1[20];
psbool  array_m477_x_1[7] = {&var1204,&var1203,&var1202,&var1201,&var1878,&var1193,&var635};
psbool  array_m455_x_1[7] = {&var1206,&var1878,&var1194,&var1207,&var1205,&var1192,&var411};
psbool  array_m850_x_1[17] = {&var1104,&var1149,&var1148,&var1145,&var1144,&var1141,&var1106,&var1143,&var1111,&var1140,&var1136,&var1138,&var1137,&var1108,&var1102,&var1191,&var959};
psbool  array_m140_x_1[21] = {&var982,&var1002,&var1247,&var955,&var1246,&var1245,&var1812,&var1821,&var1839,&var1830,&var1866,&var1857,&var734,&var636,&var1237,&var1238,&var1518,&var1512,&var1676,&var1667,&var1848};

/* Объявление структур */
_S_zzfs  S_zzfs_182_2 = {&B2IE02LDU,&fRM_1_,&var1898,&internal2_m182_tx,&internal2_m182_y0};
_S_zzfs  S_zzfs_176_2 = {&B3IE01LDU,&fRM_1_,&var1899,&internal2_m176_tx,&internal2_m176_y0};
_S_zzfs  S_zzfs_173_2 = {&B1IE01LDU,&fRM_1_,&var1900,&internal2_m173_tx,&internal2_m173_y0};
_S_zzfs  S_zzfs_165_2 = {&B2IE01LDU,&fRM_1_,&var1901,&internal2_m165_tx,&internal2_m165_y0};
_S_zzfs  S_zzfs_158_2 = {&B1IE02LDU,&fRM_1_,&var1902,&internal2_m158_tx,&internal2_m158_y0};
_S_zzfs  S_zzfs_155_2 = {&B3IE02LDU,&fRM_1_,&var1903,&internal2_m155_tx,&internal2_m155_y0};
_S_zzfs  S_zzfs_149_2 = {&A3IE02LDU,&fRM_1_,&var1904,&internal2_m149_tx,&internal2_m149_y0};
_S_zzfs  S_zzfs_144_2 = {&A3IE01LDU,&fRM_1_,&var1905,&internal2_m144_tx,&internal2_m144_y0};
_S_zzfs  S_zzfs_141_2 = {&A2IE01LDU,&fRM_1_,&var1906,&internal2_m141_tx,&internal2_m141_y0};
_S_zzfs  S_zzfs_134_2 = {&A1IE01LDU,&fRM_1_,&var1907,&internal2_m134_tx,&internal2_m134_y0};
_S_zzfs  S_zzfs_132_2 = {&A2IE02LDU,&fRM_1_,&var1908,&internal2_m132_tx,&internal2_m132_y0};
_S_zzfs  S_zzfs_127_2 = {&A1IE02LDU,&fRM_1_,&var1909,&internal2_m127_tx,&internal2_m127_y0};
_S_and4  S_and4_108_2 = {&var2005,&var1940,&B8IS11LDU,&B8IS12LDU,&var1910};
_S_lkb  S_lkb_112_2 = {&lRM_1_,&var1938,&var1911};
_S_lkb  S_lkb_109_2 = {&lRM_1_,&var1910,&var1912};
_S_lkb  S_lkb_80_2 = {&lRM_1_,&var1941,&var1913};
_S_lkb  S_lkb_52_2 = {&lRM_1_,&var1946,&var1914};
_S_lkb  S_lkb_83_2 = {&lRM_1_,&var1944,&var1915};
_S_lkb  S_lkb_48_2 = {&lRM_1_,&var1950,&var1916};
_S_lkb  S_lkb_24_2 = {&lRM_1_,&var1948,&var1917};
_S_lkb  S_lkb_21_2 = {&lRM_1_,&var1952,&var1918};
_S_or2  S_or2_269_2 = {&var2009,&var1958,&var1919};
_S_bol  S_bol_234_2 = {&fRM_0_5,&var1921,&var1920};
_S_fsumo  S_fsumo_233_2 = {&var1957,&var1956,&var1921};
_S_noto  S_noto_262_2 = {&B3VP81LDU,&var1922};
_S_noto  S_noto_261_2 = {&B2VP82LDU,&var1923};
_S_noto  S_noto_260_2 = {&B4VP82LDU,&var1924};
_S_noto  S_noto_242_2 = {&A3VP81LDU,&var1925};
_S_noto  S_noto_241_2 = {&A2VP82LDU,&var1926};
_S_noto  S_noto_240_2 = {&A4VP82LDU,&var1927};
_S_schl24  S_schl24_151_2 = {&A0EE02LZ1,&A0EE03LZ1,&A0EE01LZ1,&A0EE04LZ1,&var1928};
_S_schl24  S_schl24_147_2 = {&A0EE03LZ2,&A0EE01LZ2,&A0EE02LZ2,&A0EE04LZ2,&var1929};
_S_or2  S_or2_207_2 = {&var1978,&var1979,&var1930};
_S_or2  S_or2_203_2 = {&var1981,&var1982,&var1931};
_S_and2  S_and2_223_2 = {&var1966,&var1977,&var1932};
_S_or2  S_or2_255_2 = {&var1973,&var1972,&var1933};
_S_and4  S_and4_162_2 = {&A0EE02LZ1,&A0EE04LZ1,&A0EE02LZ2,&A0EE04LZ2,&var1934};
_S_or3  S_or3_161_2 = {&var1934,&var1067,&var1928,&var1935};
_S_and4  S_and4_136_2 = {&A0EE03LZ1,&A0EE01LZ1,&A0EE01LZ2,&A0EE03LZ2,&var1936};
_S_or3  S_or3_135_2 = {&var1936,&var1929,&var1067,&var1937};
_S_and3  S_and3_111_2 = {&var1939,&var2005,&A8IS12LDU,&var1938};
_S_or2  S_or2_104_2 = {&A8MC01LC2,&A8MC01LC1,&var1939};
_S_or2  S_or2_103_2 = {&B8MC01LC2,&B8MC01LC1,&var1940};
_S_and3  S_and3_79_2 = {&var2005,&B3IS11LDU,&var1942,&var1941};
_S_or2  S_or2_71_2 = {&B3MC01LC2,&B3MC01LC1,&var1942};
_S_or2  S_or2_74_2 = {&A3MC01LC2,&A3MC01LC1,&var1943};
_S_and3  S_and3_82_2 = {&var2005,&var1943,&A3IS11LDU,&var1944};
_S_or2  S_or2_43_2 = {&A2MC01LC2,&A2MC01LC1,&var1945};
_S_and3  S_and3_51_2 = {&var2005,&A2IS11LDU,&var1945,&var1946};
_S_or2  S_or2_13_2 = {&A1MC01LC2,&A1MC01LC1,&var1947};
_S_and3  S_and3_23_2 = {&var1947,&var2005,&A1IS11LDU,&var1948};
_S_or2  S_or2_42_2 = {&B2MC01LC1,&B2MC01LC2,&var1949};
_S_and3  S_and3_47_2 = {&var2005,&B2IS11LDU,&var1949,&var1950};
_S_or2  S_or2_11_2 = {&B1MC01LC2,&B1MC01LC1,&var1951};
_S_and3  S_and3_20_2 = {&var2005,&B1IS11LDU,&var1951,&var1952};
_S_and2  S_and2_265_2 = {&var658,&var1930,&var1953};
_S_and2  S_and2_244_2 = {&var658,&var1931,&var1954};
_S_and2  S_and2_230_2 = {&var1967,&var1976,&var1955};
_S_scalzz  S_scalzz_195_2 = {&B3IP02IDU,&iRM_3276_,&iRM_16000_,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&var1956,&internal2_m195_y0};
_S_scalzz  S_scalzz_193_2 = {&A3IP02IDU,&iRM_3276_,&iRM_16000_,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&var1957,&internal2_m193_y0};
_S_noto  S_noto_180_2 = {&var1959,&var1958};
_S_andn  S_andn_179_2 = {array_m179_x_2,&iRM_13_,&var1959};
_S_noto  S_noto_177_2 = {&var1961,&var1960};
_S_andn  S_andn_166_2 = {array_m166_x_2,&iRM_6_,&var1961};
_S_noto  S_noto_145_2 = {&var1963,&var1962};
_S_andn  S_andn_138_2 = {array_m138_x_2,&iRM_6_,&var1963};
_S_noto  S_noto_264_2 = {&var1972,&var1964};
_S_noto  S_noto_246_2 = {&var1973,&var1965};
_S_noto  S_noto_222_2 = {&var1981,&var1966};
_S_noto  S_noto_231_2 = {&var1978,&var1967};
_S_noto  S_noto_160_2 = {&var1935,&var1968};
_S_noto  S_noto_142_2 = {&var1937,&var1969};
_S_noto  S_noto_267_2 = {&var1974,&var1970};
_S_noto  S_noto_251_2 = {&var1975,&var1971};
_S_ornc  S_ornc_254_2 = {array_m254_x_2,&iRM_6_,&var1972,&vainSChar};
_S_ornc  S_ornc_243_2 = {array_m243_x_2,&iRM_6_,&var1973,&vainSChar};
_S_ornc  S_ornc_266_2 = {array_m266_x_2,&iRM_6_,&var1974,&vainSChar};
_S_ornc  S_ornc_245_2 = {array_m245_x_2,&iRM_6_,&var1975,&vainSChar};
_S_tprg  S_tprg_228_2 = {&var1956,&fEM_A3UP85RDU,&fEM_A3UP86RDU,&fEM_A3UP87RDU,&fEM_A3UP88RDU,&var1976,&internal2_m228_y0};
_S_tprg  S_tprg_220_2 = {&var1957,&fEM_A3UP85RDU,&fEM_A3UP86RDU,&fEM_A3UP87RDU,&fEM_A3UP88RDU,&var1977,&internal2_m220_y0};
_S_geterr  S_geterr_200_2 = {&var1956,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1978};
_S_drg  S_drg_208_2 = {&var1956,&lRM_1_,&lRM_0_,&fEM_A3UP43RDU,&fEM_A3UP44RDU,&var1979,&internal2_m208_y1};
_S_drg  S_drg_214_2 = {&var1956,&lRM_1_,&lRM_0_,&fEM_A3UP53RDU,&fEM_A3UP54RDU,&var1980,&internal2_m214_y1};
_S_geterr  S_geterr_197_2 = {&var1957,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1981};
_S_drg  S_drg_198_2 = {&var1957,&lRM_1_,&lRM_0_,&fEM_A3UP43RDU,&fEM_A3UP44RDU,&var1982,&internal2_m198_y1};
_S_drg  S_drg_205_2 = {&var1957,&lRM_1_,&lRM_0_,&fEM_A3UP53RDU,&fEM_A3UP54RDU,&var1983,&internal2_m205_y1};
_S_enctkb  S_enctkb_17_2 = {&var1917,&fRM_0_0,&A1IC01UDU,&dEM_A1UC06UDU,&dEM_A1UC05UDU,&fEM_A1UC03RDU,&fRM_100_,&dRM_0_,&var1984,&var1985,&var1986,&internal2_m17_Nk0,&internal2_m17_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_110_2 = {&var1912,&fRM_390_,&B8IC01UDU,&dEM_A8UC06UDU,&dEM_A8UC05UDU,&fEM_A8UC03RDU,&fRM_1500_0,&dRM_0_,&var1987,&var1988,&var1989,&internal2_m110_Nk0,&internal2_m110_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_106_2 = {&var1911,&fRM_390_0,&A8IC01UDU,&dEM_A8UC06UDU,&dEM_A8UC05UDU,&fEM_A8UC03RDU,&fRM_1500_0,&dRM_0_,&var1990,&var1991,&var1992,&internal2_m106_Nk0,&internal2_m106_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_75_2 = {&var1913,&fRM_0_,&B3IC01UDU,&dEM_A3UC06UDU,&dEM_A3UC05UDU,&fEM_A3UC03RDU,&fRM_0_0,&dRM_0_,&var1993,&var1994,&var1995,&internal2_m75_Nk0,&internal2_m75_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_77_2 = {&var1915,&fRM_0_0,&A3IC01UDU,&dEM_A3UC06UDU,&dEM_A3UC05UDU,&fEM_A3UC03RDU,&fRM_0_0,&dRM_0_,&var1996,&var1997,&var1998,&internal2_m77_Nk0,&internal2_m77_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_49_2 = {&var1916,&fRM_0_0,&B2IC01UDU,&dEM_A2UC06UDU,&dEM_A2UC05UDU,&fEM_A2UC03RDU,&fRM_100_,&dRM_0_,&var1999,&var2000,&var2001,&internal2_m49_Nk0,&internal2_m49_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_53_2 = {&var1914,&fRM_0_0,&A2IC01UDU,&dEM_A2UC06UDU,&dEM_A2UC05UDU,&fEM_A2UC03RDU,&fRM_100_,&dRM_0_,&var2002,&var2003,&var2004,&internal2_m53_Nk0,&internal2_m53_SetFlag,&bFirstEnterFlag};
_S_equz_p  S_equz_p_19_2 = {&R0MW12IP1,&iRM_4_,&var2005};
_S_enctkb  S_enctkb_15_2 = {&var1918,&fRM_0_0,&B1IC01UDU,&dEM_A1UC06UDU,&dEM_A1UC05UDU,&fEM_A1UC03RDU,&fRM_100_,&dRM_0_,&var2006,&var2007,&var2008,&internal2_m15_Nk0,&internal2_m15_SetFlag,&bFirstEnterFlag};
_S_ornc  S_ornc_124_2 = {array_m124_x_2,&iRM_8_,&var2009,&vainSChar};
_S_zzfs  S_zzfs_2562_1 = {&var1245,&fRM_1_,&var1,&internal1_m2562_tx,&internal1_m2562_y0};
_S_zzfs  S_zzfs_2560_1 = {&var1246,&fRM_1_,&var2,&internal1_m2560_tx,&internal1_m2560_y0};
_S_zzfs  S_zzfs_2558_1 = {&C2MD31LP1,&fRM_1_,&var3,&internal1_m2558_tx,&internal1_m2558_y0};
_S_zzfs  S_zzfs_2554_1 = {&var955,&fRM_1_,&var4,&internal1_m2554_tx,&internal1_m2554_y0};
_S_zzfs  S_zzfs_2552_1 = {&var1060,&fRM_1_,&var5,&internal1_m2552_tx,&internal1_m2552_y0};
_S_zzfs  S_zzfs_2556_1 = {&var1247,&fRM_1_,&var6,&internal1_m2556_tx,&internal1_m2556_y0};
_S_zzfs  S_zzfs_2550_1 = {&var445,&fRM_1_,&var7,&internal1_m2550_tx,&internal1_m2550_y0};
_S_zzfs  S_zzfs_2548_1 = {&var1170,&fRM_1_,&var8,&internal1_m2548_tx,&internal1_m2548_y0};
_S_zpfs  S_zpfs_2582_1 = {&var1920,&fRM_1_,&var9,&internal1_m2582_tx,&internal1_m2582_y0};
_S_zpfs  S_zpfs_2590_1 = {&var1897,&fRM_1_,&var10,&internal1_m2590_tx,&internal1_m2590_y0};
_S_zpfs  S_zpfs_2588_1 = {&var470,&fRM_1_,&var11,&internal1_m2588_tx,&internal1_m2588_y0};
_S_zpfs  S_zpfs_2586_1 = {&var447,&fRM_1_,&var12,&internal1_m2586_tx,&internal1_m2586_y0};
_S_zpfs  S_zpfs_2584_1 = {&var451,&fRM_1_,&var13,&internal1_m2584_tx,&internal1_m2584_y0};
_S_zpfs  S_zpfs_2580_1 = {&var1475,&fRM_1_,&var14,&internal1_m2580_tx,&internal1_m2580_y0};
_S_zpfs  S_zpfs_2578_1 = {&var1477,&fRM_1_,&var15,&internal1_m2578_tx,&internal1_m2578_y0};
_S_zpfs  S_zpfs_2576_1 = {&var462,&fRM_1_,&var16,&internal1_m2576_tx,&internal1_m2576_y0};
_S_zpfs  S_zpfs_2574_1 = {&var498,&fRM_1_,&var17,&internal1_m2574_tx,&internal1_m2574_y0};
_S_zpfs  S_zpfs_2572_1 = {&var496,&fRM_1_,&var18,&internal1_m2572_tx,&internal1_m2572_y0};
_S_zpfs  S_zpfs_2570_1 = {&var1079,&fRM_1_,&var19,&internal1_m2570_tx,&internal1_m2570_y0};
_S_zpfs  S_zpfs_2568_1 = {&var463,&fRM_1_,&var20,&internal1_m2568_tx,&internal1_m2568_y0};
_S_zpfs  S_zpfs_2566_1 = {&var436,&fRM_1_,&var21,&internal1_m2566_tx,&internal1_m2566_y0};
_S_zpfs  S_zpfs_2564_1 = {&var434,&fRM_1_,&var22,&internal1_m2564_tx,&internal1_m2564_y0};
_S_or2  S_or2_1225_1 = {&R2IS11LDU,&R1IS11LDU,&var23};
_S_or3  S_or3_1223_1 = {&A3IS21LDU,&B3IS21LDU,&var25,&var24};
_S_noto  S_noto_1230_1 = {&var26,&var25};
_S_and2  S_and2_1231_1 = {&var1585,&var1553,&var26};
_S_or3  S_or3_1221_1 = {&A1IS21LDU,&B1IS21LDU,&var28,&var27};
_S_noto  S_noto_1228_1 = {&var29,&var28};
_S_and2  S_and2_1229_1 = {&var1647,&var1614,&var29};
_S_or3  S_or3_1219_1 = {&A2IS21LDU,&B2IS21LDU,&var31,&var30};
_S_noto  S_noto_1226_1 = {&var32,&var31};
_S_and2  S_and2_1227_1 = {&var1735,&var1694,&var32};
_S_noto  S_noto_1217_1 = {&var23,&var33};
_S_or3  S_or3_1204_1 = {&R0MD34LP1,&var33,&var1248,&var34};
_S_noto  S_noto_1215_1 = {&var24,&var35};
_S_or3  S_or3_1201_1 = {&R0MD34LP1,&var35,&var1250,&var36};
_S_noto  S_noto_1213_1 = {&var27,&var37};
_S_or3  S_or3_1198_1 = {&R0MD34LP1,&var37,&var1252,&var38};
_S_noto  S_noto_1211_1 = {&var30,&var39};
_S_or3  S_or3_1195_1 = {&var1254,&var39,&R0MD34LP1,&var40};
_S_noto  S_noto_132_1 = {&var468,&var41};
_S_and2  S_and2_53_1 = {&var643,&var41,&var42};
_S_or2  S_or2_2303_1 = {&var416,&var718,&var43};
_S_or2  S_or2_2302_1 = {&var733,&var718,&var44};
_S_swtakt  S_swtakt_2097_1 = {&var1384,&var45,&fEM_R0UL00RDU,&var46,&internal1_m2097_x0,&internal1_m2097_tim};
_S_zpfs  S_zpfs_1673_1 = {&var1266,&fEM_R7UI76RDU,&var47,&internal1_m1673_tx,&internal1_m1673_y0};
_S_or4  S_or4_2542_1 = {&var1269,&var1264,&var1259,&var1267,&var48};
_S_or3  S_or3_2543_1 = {&var46,&var1271,&var48,&var49};
_S_or2  S_or2_1622_1 = {&var1879,&var1340,&var50};
_S_or2  S_or2_1615_1 = {&var1880,&var1339,&var51};
_S_or2  S_or2_1610_1 = {&var1881,&var1338,&var52};
_S_or2  S_or2_1606_1 = {&var1882,&var1337,&var53};
_S_or2  S_or2_1602_1 = {&var1883,&var1336,&var54};
_S_noto  S_noto_58_1 = {&var643,&vainSBool};
_S_and2  S_and2_1609_1 = {&var1881,&R0MD11LP2,&var55};
_S_and2  S_and2_1614_1 = {&var1880,&R0MD11LP2,&var56};
_S_and2  S_and2_1605_1 = {&var1882,&R0MD11LP2,&var57};
_S_and2  S_and2_1621_1 = {&var1879,&R0MD11LP2,&var58};
_S_and2  S_and2_1601_1 = {&var1883,&R0MD11LP2,&var59};
_S_and2  S_and2_1625_1 = {&var1334,&var1340,&var60};
_S_or2  S_or2_2084_1 = {&R8AD22LDU,&var671,&var61};
_S_period  S_period_79_1 = {&var1230,&lRM_1_,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var62,&internal1_m79_flst,&internal1_m79_chsr,&internal1_m79_chizm,&internal1_m79_sumtim,&internal1_m79_W1,&internal1_m79_W2,&internal1_m79_Wmin,&internal1_m79_Wmax,&internal1_m79_Wlast,&internal1_m79_y0,&internal1_m79_MyFirstEnterFlag};
_S_ovbsb  S_ovbsb_2062_1 = {&var636,&var63,&internal1_m2062_tx};
_S_ovbsb  S_ovbsb_2061_1 = {&var734,&var64,&internal1_m2061_tx};
_S_ovbsb  S_ovbsb_781_1 = {&var1135,&var65,&internal1_m781_tx};
_S_ovbsb  S_ovbsb_738_1 = {&var1134,&var66,&internal1_m738_tx};
_S_ovbsb  S_ovbsb_795_1 = {&var1137,&var67,&internal1_m795_tx};
_S_ovbsb  S_ovbsb_792_1 = {&var1136,&var68,&internal1_m792_tx};
_S_ovbsb  S_ovbsb_791_1 = {&var1138,&var69,&internal1_m791_tx};
_S_ovbsb  S_ovbsb_748_1 = {&var1106,&var70,&internal1_m748_tx};
_S_ovbsb  S_ovbsb_731_1 = {&var1111,&var71,&internal1_m731_tx};
_S_ovbsb  S_ovbsb_742_1 = {&var1108,&var72,&internal1_m742_tx};
_S_ovbsb  S_ovbsb_773_1 = {&var1141,&var73,&internal1_m773_tx};
_S_ovbsb  S_ovbsb_790_1 = {&var1140,&var74,&internal1_m790_tx};
_S_ovbsb  S_ovbsb_763_1 = {&var1144,&var75,&internal1_m763_tx};
_S_ovbsb  S_ovbsb_394_1 = {&var1850,&var76,&internal1_m394_tx};
_S_ovbsb  S_ovbsb_393_1 = {&var1849,&var77,&internal1_m393_tx};
_S_ovbsb  S_ovbsb_392_1 = {&var1851,&var78,&internal1_m392_tx};
_S_ovbsb  S_ovbsb_391_1 = {&var1848,&var79,&internal1_m391_tx};
_S_ovbsb  S_ovbsb_762_1 = {&var1145,&var80,&internal1_m762_tx};
_S_ovbsb  S_ovbsb_757_1 = {&var1148,&var81,&internal1_m757_tx};
_S_ovbsb  S_ovbsb_765_1 = {&var1149,&var82,&internal1_m765_tx};
_S_ovbsb  S_ovbsb_771_1 = {&var1143,&var83,&internal1_m771_tx};
_S_ovbsb  S_ovbsb_527_1 = {&var1669,&var84,&internal1_m527_tx};
_S_ovbsb  S_ovbsb_526_1 = {&var1668,&var85,&internal1_m526_tx};
_S_ovbsb  S_ovbsb_525_1 = {&var1670,&var86,&internal1_m525_tx};
_S_ovbsb  S_ovbsb_521_1 = {&var1667,&var87,&internal1_m521_tx};
_S_ovbsb  S_ovbsb_498_1 = {&var1678,&var88,&internal1_m498_tx};
_S_ovbsb  S_ovbsb_497_1 = {&var1677,&var89,&internal1_m497_tx};
_S_ovbsb  S_ovbsb_496_1 = {&var1679,&var90,&internal1_m496_tx};
_S_ovbsb  S_ovbsb_499_1 = {&var1676,&var91,&internal1_m499_tx};
_S_ovbsb  S_ovbsb_2468_1 = {&var461,&var92,&internal1_m2468_tx};
_S_ovbsb  S_ovbsb_2178_1 = {&var445,&var93,&internal1_m2178_tx};
_S_ovbsb  S_ovbsb_2467_1 = {&var465,&var94,&internal1_m2467_tx};
_S_ovbsb  S_ovbsb_2466_1 = {&var472,&var95,&internal1_m2466_tx};
_S_ovbsb  S_ovbsb_2464_1 = {&var473,&var96,&internal1_m2464_tx};
_S_ovbsb  S_ovbsb_108_1 = {&var593,&var97,&internal1_m108_tx};
_S_ovbsb  S_ovbsb_1144_1 = {&var863,&var98,&internal1_m1144_tx};
_S_ovbsb  S_ovbsb_2326_1 = {&var1513,&var99,&internal1_m2326_tx};
_S_ovbsb  S_ovbsb_2325_1 = {&var1514,&var100,&internal1_m2325_tx};
_S_ovbsb  S_ovbsb_2324_1 = {&var1512,&var101,&internal1_m2324_tx};
_S_ovbsb  S_ovbsb_1256_1 = {&var1083,&var102,&internal1_m1256_tx};
_S_ovbsb  S_ovbsb_1255_1 = {&var1084,&var103,&internal1_m1255_tx};
_S_ovbsb  S_ovbsb_1251_1 = {&var1085,&var104,&internal1_m1251_tx};
_S_ovbsb  S_ovbsb_1244_1 = {&var1089,&var105,&internal1_m1244_tx};
_S_ovbsb  S_ovbsb_1242_1 = {&var1086,&var106,&internal1_m1242_tx};
_S_ovbsb  S_ovbsb_1240_1 = {&var1087,&var107,&internal1_m1240_tx};
_S_ovbsb  S_ovbsb_1238_1 = {&var1088,&var108,&internal1_m1238_tx};
_S_ovbsb  S_ovbsb_1281_1 = {&var1768,&var109,&internal1_m1281_tx};
_S_ovbsb  S_ovbsb_1288_1 = {&var1769,&var110,&internal1_m1288_tx};
_S_ovbsb  S_ovbsb_1293_1 = {&var1782,&var111,&internal1_m1293_tx};
_S_ovbsb  S_ovbsb_1299_1 = {&var1238,&var112,&internal1_m1299_tx};
_S_ovbsb  S_ovbsb_1259_1 = {&var1082,&var113,&internal1_m1259_tx};
_S_ovbsb  S_ovbsb_1280_1 = {&var1776,&var114,&internal1_m1280_tx};
_S_ovbsb  S_ovbsb_1294_1 = {&var1777,&var115,&internal1_m1294_tx};
_S_ovbsb  S_ovbsb_476_1 = {&var1204,&var116,&internal1_m476_tx};
_S_ovbsb  S_ovbsb_470_1 = {&var1203,&var117,&internal1_m470_tx};
_S_ovbsb  S_ovbsb_472_1 = {&var1202,&var118,&internal1_m472_tx};
_S_ovbsb  S_ovbsb_474_1 = {&var1201,&var119,&internal1_m474_tx};
_S_ovbsb  S_ovbsb_481_1 = {&var635,&var120,&internal1_m481_tx};
_S_ovbsb  S_ovbsb_435_1 = {&var1859,&var121,&internal1_m435_tx};
_S_ovbsb  S_ovbsb_433_1 = {&var1860,&var122,&internal1_m433_tx};
_S_ovbsb  S_ovbsb_434_1 = {&var1858,&var123,&internal1_m434_tx};
_S_ovbsb  S_ovbsb_427_1 = {&var1857,&var124,&internal1_m427_tx};
_S_ovbsb  S_ovbsb_889_1 = {&var1832,&var125,&internal1_m889_tx};
_S_ovbsb  S_ovbsb_888_1 = {&var1831,&var126,&internal1_m888_tx};
_S_ovbsb  S_ovbsb_887_1 = {&var1833,&var127,&internal1_m887_tx};
_S_ovbsb  S_ovbsb_883_1 = {&var1830,&var128,&internal1_m883_tx};
_S_ovbsb  S_ovbsb_1345_1 = {&var1813,&var129,&internal1_m1345_tx};
_S_ovbsb  S_ovbsb_1344_1 = {&var1814,&var130,&internal1_m1344_tx};
_S_ovbsb  S_ovbsb_1343_1 = {&var1812,&var131,&internal1_m1343_tx};
_S_ovbsb  S_ovbsb_1556_1 = {&var905,&var132,&internal1_m1556_tx};
_S_ovbsb  S_ovbsb_1569_1 = {&var898,&var133,&internal1_m1569_tx};
_S_ovbsb  S_ovbsb_1568_1 = {&var899,&var134,&internal1_m1568_tx};
_S_ovbsb  S_ovbsb_1567_1 = {&var902,&var135,&internal1_m1567_tx};
_S_ovbsb  S_ovbsb_1558_1 = {&var1173,&var136,&internal1_m1558_tx};
_S_ovbsb  S_ovbsb_2296_1 = {&var399,&var137,&internal1_m2296_tx};
_S_ovbsb  S_ovbsb_2279_1 = {&var417,&var138,&internal1_m2279_tx};
_S_ovbsb  S_ovbsb_2256_1 = {&var412,&var139,&internal1_m2256_tx};
_S_ovbsb  S_ovbsb_1566_1 = {&var903,&var140,&internal1_m1566_tx};
_S_ovbsb  S_ovbsb_1545_1 = {&var907,&var141,&internal1_m1545_tx};
_S_ovbsb  S_ovbsb_1544_1 = {&var908,&var142,&internal1_m1544_tx};
_S_ovbsb  S_ovbsb_1543_1 = {&var909,&var143,&internal1_m1543_tx};
_S_ovbsb  S_ovbsb_1565_1 = {&var904,&var144,&internal1_m1565_tx};
_S_ovbsb  S_ovbsb_1531_1 = {&var913,&var145,&internal1_m1531_tx};
_S_ovbsb  S_ovbsb_1533_1 = {&var912,&var146,&internal1_m1533_tx};
_S_ovbsb  S_ovbsb_1530_1 = {&var914,&var147,&internal1_m1530_tx};
_S_ovbsb  S_ovbsb_1503_1 = {&var1565,&var148,&internal1_m1503_tx};
_S_ovbsb  S_ovbsb_1502_1 = {&var1564,&var149,&internal1_m1502_tx};
_S_ovbsb  S_ovbsb_1511_1 = {&var1570,&var150,&internal1_m1511_tx};
_S_ovbsb  S_ovbsb_1515_1 = {&var1245,&var151,&internal1_m1515_tx};
_S_ovbsb  S_ovbsb_982_1 = {&var938,&var152,&internal1_m982_tx};
_S_ovbsb  S_ovbsb_985_1 = {&var937,&var153,&internal1_m985_tx};
_S_ovbsb  S_ovbsb_2247_1 = {&var606,&var154,&internal1_m2247_tx};
_S_ovbsb  S_ovbsb_975_1 = {&var1182,&var155,&internal1_m975_tx};
_S_ovbsb  S_ovbsb_973_1 = {&var1183,&var156,&internal1_m973_tx};
_S_ovbsb  S_ovbsb_981_1 = {&var939,&var157,&internal1_m981_tx};
_S_ovbsb  S_ovbsb_965_1 = {&var943,&var158,&internal1_m965_tx};
_S_ovbsb  S_ovbsb_963_1 = {&var942,&var159,&internal1_m963_tx};
_S_ovbsb  S_ovbsb_959_1 = {&var941,&var160,&internal1_m959_tx};
_S_ovbsb  S_ovbsb_980_1 = {&var940,&var161,&internal1_m980_tx};
_S_ovbsb  S_ovbsb_947_1 = {&var947,&var162,&internal1_m947_tx};
_S_ovbsb  S_ovbsb_948_1 = {&var946,&var163,&internal1_m948_tx};
_S_ovbsb  S_ovbsb_945_1 = {&var945,&var164,&internal1_m945_tx};
_S_ovbsb  S_ovbsb_633_1 = {&var989,&var165,&internal1_m633_tx};
_S_ovbsb  S_ovbsb_636_1 = {&var1158,&var166,&internal1_m636_tx};
_S_ovbsb  S_ovbsb_635_1 = {&var1157,&var167,&internal1_m635_tx};
_S_ovbsb  S_ovbsb_622_1 = {&var490,&var168,&internal1_m622_tx};
_S_ovbsb  S_ovbsb_621_1 = {&var1177,&var169,&internal1_m621_tx};
_S_ovbsb  S_ovbsb_618_1 = {&var1178,&var170,&internal1_m618_tx};
_S_ovbsb  S_ovbsb_631_1 = {&var987,&var171,&internal1_m631_tx};
_S_ovbsb  S_ovbsb_608_1 = {&var991,&var172,&internal1_m608_tx};
_S_ovbsb  S_ovbsb_607_1 = {&var992,&var173,&internal1_m607_tx};
_S_ovbsb  S_ovbsb_603_1 = {&var995,&var174,&internal1_m603_tx};
_S_ovbsb  S_ovbsb_634_1 = {&var988,&var175,&internal1_m634_tx};
_S_ovbsb  S_ovbsb_591_1 = {&var993,&var176,&internal1_m591_tx};
_S_ovbsb  S_ovbsb_590_1 = {&var999,&var177,&internal1_m590_tx};
_S_ovbsb  S_ovbsb_593_1 = {&var1000,&var178,&internal1_m593_tx};
_S_ovbsb  S_ovbsb_570_1 = {&var1625,&var179,&internal1_m570_tx};
_S_ovbsb  S_ovbsb_571_1 = {&var1626,&var180,&internal1_m571_tx};
_S_ovbsb  S_ovbsb_572_1 = {&var1631,&var181,&internal1_m572_tx};
_S_ovbsb  S_ovbsb_577_1 = {&var1002,&var182,&internal1_m577_tx};
_S_ovbsb  S_ovbsb_2309_1 = {&var1518,&var183,&internal1_m2309_tx};
_S_ovbsb  S_ovbsb_2310_1 = {&var1520,&var184,&internal1_m2310_tx};
_S_ovbsb  S_ovbsb_2311_1 = {&var1519,&var185,&internal1_m2311_tx};
_S_ovbsb  S_ovbsb_1788_1 = {&var766,&var186,&internal1_m1788_tx};
_S_ovbsb  S_ovbsb_1787_1 = {&var767,&var187,&internal1_m1787_tx};
_S_ovbsb  S_ovbsb_1782_1 = {&var769,&var188,&internal1_m1782_tx};
_S_ovbsb  S_ovbsb_1773_1 = {&var770,&var189,&internal1_m1773_tx};
_S_ovbsb  S_ovbsb_1771_1 = {&var771,&var190,&internal1_m1771_tx};
_S_ovbsb  S_ovbsb_1769_1 = {&var772,&var191,&internal1_m1769_tx};
_S_ovbsb  S_ovbsb_1768_1 = {&var773,&var192,&internal1_m1768_tx};
_S_ovbsb  S_ovbsb_1809_1 = {&var1757,&var193,&internal1_m1809_tx};
_S_ovbsb  S_ovbsb_1817_1 = {&var1758,&var194,&internal1_m1817_tx};
_S_ovbsb  S_ovbsb_1824_1 = {&var1765,&var195,&internal1_m1824_tx};
_S_ovbsb  S_ovbsb_1825_1 = {&var1237,&var196,&internal1_m1825_tx};
_S_ovbsb  S_ovbsb_1815_1 = {&var1760,&var197,&internal1_m1815_tx};
_S_ovbsb  S_ovbsb_1790_1 = {&var765,&var198,&internal1_m1790_tx};
_S_ovbsb  S_ovbsb_1804_1 = {&var1759,&var199,&internal1_m1804_tx};
_S_ovbsb  S_ovbsb_453_1 = {&var1206,&var200,&internal1_m453_tx};
_S_ovbsb  S_ovbsb_444_1 = {&var1192,&var201,&internal1_m444_tx};
_S_ovbsb  S_ovbsb_445_1 = {&var411,&var202,&internal1_m445_tx};
_S_ovbsb  S_ovbsb_447_1 = {&var1207,&var203,&internal1_m447_tx};
_S_ovbsb  S_ovbsb_461_1 = {&var1205,&var204,&internal1_m461_tx};
_S_ovbsb  S_ovbsb_411_1 = {&var1866,&var205,&internal1_m411_tx};
_S_ovbsb  S_ovbsb_408_1 = {&var1868,&var206,&internal1_m408_tx};
_S_ovbsb  S_ovbsb_407_1 = {&var1867,&var207,&internal1_m407_tx};
_S_ovbsb  S_ovbsb_406_1 = {&var1869,&var208,&internal1_m406_tx};
_S_ovbsb  S_ovbsb_866_1 = {&var1839,&var209,&internal1_m866_tx};
_S_ovbsb  S_ovbsb_862_1 = {&var1841,&var210,&internal1_m862_tx};
_S_ovbsb  S_ovbsb_861_1 = {&var1840,&var211,&internal1_m861_tx};
_S_ovbsb  S_ovbsb_860_1 = {&var1842,&var212,&internal1_m860_tx};
_S_ovbsb  S_ovbsb_1326_1 = {&var1821,&var213,&internal1_m1326_tx};
_S_ovbsb  S_ovbsb_1323_1 = {&var1822,&var214,&internal1_m1323_tx};
_S_ovbsb  S_ovbsb_1322_1 = {&var1823,&var215,&internal1_m1322_tx};
_S_ovbsb  S_ovbsb_1083_1 = {&var666,&var216,&internal1_m1083_tx};
_S_ovbsb  S_ovbsb_2268_1 = {&var418,&var217,&internal1_m2268_tx};
_S_ovbsb  S_ovbsb_1094_1 = {&var919,&var218,&internal1_m1094_tx};
_S_ovbsb  S_ovbsb_1096_1 = {&var917,&var219,&internal1_m1096_tx};
_S_ovbsb  S_ovbsb_1095_1 = {&var916,&var220,&internal1_m1095_tx};
_S_ovbsb  S_ovbsb_2262_1 = {&var413,&var221,&internal1_m2262_tx};
_S_ovbsb  S_ovbsb_1085_1 = {&var1175,&var222,&internal1_m1085_tx};
_S_ovbsb  S_ovbsb_2267_1 = {&var402,&var223,&internal1_m2267_tx};
_S_ovbsb  S_ovbsb_1093_1 = {&var920,&var224,&internal1_m1093_tx};
_S_ovbsb  S_ovbsb_1074_1 = {&var924,&var225,&internal1_m1074_tx};
_S_ovbsb  S_ovbsb_1073_1 = {&var928,&var226,&internal1_m1073_tx};
_S_ovbsb  S_ovbsb_1070_1 = {&var922,&var227,&internal1_m1070_tx};
_S_ovbsb  S_ovbsb_1092_1 = {&var921,&var228,&internal1_m1092_tx};
_S_ovbsb  S_ovbsb_1060_1 = {&var927,&var229,&internal1_m1060_tx};
_S_ovbsb  S_ovbsb_1058_1 = {&var929,&var230,&internal1_m1058_tx};
_S_ovbsb  S_ovbsb_1057_1 = {&var930,&var231,&internal1_m1057_tx};
_S_ovbsb  S_ovbsb_1036_1 = {&var1596,&var232,&internal1_m1036_tx};
_S_ovbsb  S_ovbsb_1035_1 = {&var1597,&var233,&internal1_m1035_tx};
_S_ovbsb  S_ovbsb_1025_1 = {&var1602,&var234,&internal1_m1025_tx};
_S_ovbsb  S_ovbsb_1042_1 = {&var1246,&var235,&internal1_m1042_tx};
_S_ovbsb  S_ovbsb_1461_1 = {&var876,&var236,&internal1_m1461_tx};
_S_ovbsb  S_ovbsb_1460_1 = {&var877,&var237,&internal1_m1460_tx};
_S_ovbsb  S_ovbsb_2214_1 = {&var607,&var238,&internal1_m2214_tx};
_S_ovbsb  S_ovbsb_1451_1 = {&var880,&var239,&internal1_m1451_tx};
_S_ovbsb  S_ovbsb_1452_1 = {&var881,&var240,&internal1_m1452_tx};
_S_ovbsb  S_ovbsb_1459_1 = {&var878,&var241,&internal1_m1459_tx};
_S_ovbsb  S_ovbsb_1441_1 = {&var886,&var242,&internal1_m1441_tx};
_S_ovbsb  S_ovbsb_1440_1 = {&var884,&var243,&internal1_m1440_tx};
_S_ovbsb  S_ovbsb_1437_1 = {&var882,&var244,&internal1_m1437_tx};
_S_ovbsb  S_ovbsb_1458_1 = {&var879,&var245,&internal1_m1458_tx};
_S_ovbsb  S_ovbsb_1424_1 = {&var887,&var246,&internal1_m1424_tx};
_S_ovbsb  S_ovbsb_1422_1 = {&var885,&var247,&internal1_m1422_tx};
_S_ovbsb  S_ovbsb_1426_1 = {&var883,&var248,&internal1_m1426_tx};
_S_ovbsb  S_ovbsb_251_1 = {&var491,&var249,&internal1_m251_tx};
_S_ovbsb  S_ovbsb_266_1 = {&var965,&var250,&internal1_m266_tx};
_S_ovbsb  S_ovbsb_274_1 = {&var964,&var251,&internal1_m274_tx};
_S_ovbsb  S_ovbsb_273_1 = {&var966,&var252,&internal1_m273_tx};
_S_ovbsb  S_ovbsb_259_1 = {&var1180,&var253,&internal1_m259_tx};
_S_ovbsb  S_ovbsb_254_1 = {&var1181,&var254,&internal1_m254_tx};
_S_ovbsb  S_ovbsb_270_1 = {&var962,&var255,&internal1_m270_tx};
_S_ovbsb  S_ovbsb_243_1 = {&var971,&var256,&internal1_m243_tx};
_S_ovbsb  S_ovbsb_242_1 = {&var969,&var257,&internal1_m242_tx};
_S_ovbsb  S_ovbsb_237_1 = {&var968,&var258,&internal1_m237_tx};
_S_ovbsb  S_ovbsb_269_1 = {&var967,&var259,&internal1_m269_tx};
_S_ovbsb  S_ovbsb_226_1 = {&var975,&var260,&internal1_m226_tx};
_S_ovbsb  S_ovbsb_228_1 = {&var973,&var261,&internal1_m228_tx};
_S_ovbsb  S_ovbsb_225_1 = {&var974,&var262,&internal1_m225_tx};
_S_ovbsb  S_ovbsb_204_1 = {&var1662,&var263,&internal1_m204_tx};
_S_ovbsb  S_ovbsb_203_1 = {&var1663,&var264,&internal1_m203_tx};
_S_ovbsb  S_ovbsb_202_1 = {&var1664,&var265,&internal1_m202_tx};
_S_ovbsb  S_ovbsb_210_1 = {&var982,&var266,&internal1_m210_tx};
_S_ovbsb  S_ovbsb_1404_1 = {&var1752,&var267,&internal1_m1404_tx};
_S_ovbsb  S_ovbsb_1386_1 = {&var1747,&var268,&internal1_m1386_tx};
_S_ovbsb  S_ovbsb_1391_1 = {&var1746,&var269,&internal1_m1391_tx};
_S_ovbsb  S_ovbsb_1408_1 = {&var1247,&var270,&internal1_m1408_tx};
_S_ovbsb  S_ovbsb_925_1 = {&var1709,&var271,&internal1_m925_tx};
_S_ovbsb  S_ovbsb_930_1 = {&var955,&var272,&internal1_m930_tx};
_S_ovbsb  S_ovbsb_920_1 = {&var954,&var273,&internal1_m920_tx};
_S_ovbsb  S_ovbsb_921_1 = {&var953,&var274,&internal1_m921_tx};
_S_or3  S_or3_2527_1 = {&var278,&var277,&var276,&var275};
_S_or2  S_or2_2531_1 = {&R0DEB3LDU,&R0DEB4LDU,&var276};
_S_or2  S_or2_2525_1 = {&R0DEB1LDU,&R0DEB2LDU,&var277};
_S_diagndev  S_diagndev_2519_1 = {array_m2519_x_1,&iRM_14_,&var278,&var279};
_S_or2  S_or2_1910_1 = {&var510,&var328,&var280};
_S_and2  S_and2_1900_1 = {&var566,&var1461,&var281};
_S_rs  S_rs_1909_1 = {&var280,&var281,&var282,&vainSBool,&internal1_m1909_q0};
_S_or2  S_or2_1904_1 = {&var566,&var513,&var283};
_S_or2  S_or2_1847_1 = {&var1511,&var566,&var284};
_S_or2  S_or2_1875_1 = {&var565,&var328,&var285};
_S_or2  S_or2_1877_1 = {&var398,&var328,&var286};
_S_or2  S_or2_2358_1 = {&var510,&var324,&var287};
_S_or2  S_or2_2356_1 = {&var324,&var517,&var288};
_S_or2  S_or2_2354_1 = {&var337,&var324,&var289};
_S_and2  S_and2_2337_1 = {&var1458,&var564,&var290};
_S_or2  S_or2_2352_1 = {&var564,&var324,&var291};
_S_noto  S_noto_2360_1 = {&B3IS11LDU,&var292};
_S_or2  S_or2_2387_1 = {&var328,&var517,&var293};
_S_and2  S_and2_2367_1 = {&var1458,&var565,&var294};
_S_noto  S_noto_2391_1 = {&A3IS11LDU,&var295};
_S_or2  S_or2_2389_1 = {&var510,&var328,&var296};
_S_or2  S_or2_2385_1 = {&var328,&var338,&var297};
_S_or2  S_or2_2383_1 = {&var328,&var565,&var298};
_S_or2  S_or2_1855_1 = {&var510,&var328,&var299};
_S_or2  S_or2_1859_1 = {&var510,&var324,&var300};
_S_or2  S_or2_1850_1 = {&var566,&var1511,&var301};
_S_or2  S_or2_1885_1 = {&var324,&var397,&var302};
_S_or2  S_or2_1883_1 = {&var564,&var324,&var303};
_S_or2  S_or2_1926_1 = {&var517,&var324,&var304};
_S_or2  S_or2_1923_1 = {&var517,&var328,&var305};
_S_or2  S_or2_1955_1 = {&var523,&var324,&var306};
_S_or2  S_or2_1952_1 = {&var523,&var328,&var307};
_S_or2  S_or2_1912_1 = {&var510,&var324,&var308};
_S_or2  S_or2_1879_1 = {&var510,&var328,&var309};
_S_or2  S_or2_1887_1 = {&var510,&var324,&var310};
_S_or3  S_or3_2348_1 = {&var517,&var564,&var324,&var311};
_S_or3  S_or3_2350_1 = {&var567,&var564,&var324,&var312};
_S_or3  S_or3_2381_1 = {&var328,&var568,&var565,&var313};
_S_or3  S_or3_2379_1 = {&var517,&var328,&var565,&var314};
_S_or3  S_or3_2346_1 = {&var564,&var510,&var324,&var315};
_S_or3  S_or3_2377_1 = {&var510,&var565,&var328,&var316};
_S_or3  S_or3_1853_1 = {&var510,&var565,&var328,&var317};
_S_or3  S_or3_1857_1 = {&var564,&var510,&var324,&var318};
_S_or3  S_or3_1873_1 = {&var510,&var565,&var328,&var319};
_S_or3  S_or3_1881_1 = {&var510,&var564,&var324,&var320};
_S_or3  S_or3_1908_1 = {&var510,&var566,&var324,&var321};
_S_or3  S_or3_1906_1 = {&var510,&var328,&var566,&var322};
_S_or3  S_or3_1954_1 = {&var324,&var564,&var523,&var323};
_S_noto  S_noto_1949_1 = {&var1164,&var324};
_S_or3  S_or3_1925_1 = {&var324,&var517,&var564,&var325};
_S_or3  S_or3_1922_1 = {&var517,&var328,&var565,&var326};
_S_or3  S_or3_1951_1 = {&var523,&var328,&var565,&var327};
_S_noto  S_noto_1948_1 = {&var1163,&var328};
_S_regch  S_regch_133_1 = {&R0MW12IP1,&var1153,&var329};
_S_or2  S_or2_136_1 = {&var331,&var329,&var330};
_S_or2  S_or2_135_1 = {&R0VZ71LZ1,&R0VZ71LZ2,&var331};
_S_and3  S_and3_1591_1 = {&R0MD11LP2,&var1212,&var335,&var332};
_S_and2  S_and2_813_1 = {&R4MD21LP2,&var335,&var333};
_S_and2  S_and2_811_1 = {&R4MD11LP2,&var335,&var334};
_S_noto  S_noto_114_1 = {&var1888,&var335};
_S_and2  S_and2_112_1 = {&R0MD11LP1,&var335,&var336};
_S_noto  S_noto_2361_1 = {&B3IS22LDU,&var337};
_S_noto  S_noto_2392_1 = {&A3IS22LDU,&var338};
_S_and2  S_and2_2277_1 = {&var730,&var1440,&var339};
_S_or3  S_or3_2270_1 = {&var729,&var437,&var379,&var340};
_S_and2  S_and2_2259_1 = {&var726,&var1440,&var341};
_S_or3  S_or3_2255_1 = {&var437,&var727,&var362,&var342};
_S_or2  S_or2_1671_1 = {&var1268,&var1458,&var343};
_S_or2  S_or2_1636_1 = {&var1265,&var1458,&var344};
_S_rs  S_rs_2351_1 = {&var291,&var348,&var345,&vainSBool,&internal1_m2351_q0};
_S_rs  S_rs_2335_1 = {&var292,&var367,&var346,&vainSBool,&internal1_m2335_q0};
_S_noto  S_noto_2359_1 = {&var1980,&var347};
_S_and2  S_and2_2342_1 = {&var347,&var346,&var348};
_S_rs  S_rs_2382_1 = {&var298,&var351,&var349,&vainSBool,&internal1_m2382_q0};
_S_noto  S_noto_2390_1 = {&var1983,&var350};
_S_and2  S_and2_2373_1 = {&var352,&var350,&var351};
_S_rs  S_rs_2366_1 = {&var295,&var385,&var352,&vainSBool,&internal1_m2366_q0};
_S_and4  S_and4_1537_1 = {&var1212,&var1458,&var528,&var1503,&var353};
_S_and4  S_and4_1064_1 = {&var1212,&var1458,&var528,&var1503,&var354};
_S_rs  S_rs_2357_1 = {&var287,&var360,&var355,&vainSBool,&internal1_m2357_q0};
_S_or4  S_or4_1467_1 = {&var848,&var550,&var1251,&var362,&var356};
_S_or4  S_or4_1476_1 = {&var426,&var553,&var1024,&var368,&var357};
_S_orn  S_orn_894_1 = {array_m894_x_1,&iRM_6_,&var358};
_S_or3  S_or3_906_1 = {&var1043,&var1454,&var371,&var359};
_S_and2  S_and2_2344_1 = {&var517,&var361,&var360};
_S_rs  S_rs_2338_1 = {&var287,&var363,&var361,&vainSBool,&internal1_m2338_q0};
_S_rs  S_rs_2355_1 = {&var288,&var363,&var362,&vainSBool,&internal1_m2355_q0};
_S_and2  S_and2_2343_1 = {&var364,&var337,&var363};
_S_rs  S_rs_2336_1 = {&var288,&var290,&var364,&vainSBool,&internal1_m2336_q0};
_S_rs  S_rs_2334_1 = {&var347,&var369,&var365,&vainSBool,&internal1_m2334_q0};
_S_rs  S_rs_2333_1 = {&var311,&var370,&var366,&vainSBool,&internal1_m2333_q0};
_S_and2  S_and2_2341_1 = {&var517,&var365,&var367};
_S_rs  S_rs_2347_1 = {&var311,&var369,&var368,&vainSBool,&internal1_m2347_q0};
_S_and2  S_and2_2340_1 = {&var366,&var510,&var369};
_S_and2  S_and2_2339_1 = {&var567,&var1458,&var370};
_S_rs  S_rs_2345_1 = {&var315,&var370,&var371,&vainSBool,&internal1_m2345_q0};
_S_rs  S_rs_2353_1 = {&var289,&var290,&var372,&vainSBool,&internal1_m2353_q0};
_S_rs  S_rs_2349_1 = {&var312,&var367,&var373,&vainSBool,&internal1_m2349_q0};
_S_orn  S_orn_1355_1 = {array_m1355_x_1,&iRM_6_,&var374};
_S_rs  S_rs_2388_1 = {&var296,&var376,&var375,&vainSBool,&internal1_m2388_q0};
_S_and2  S_and2_2375_1 = {&var517,&var377,&var376};
_S_rs  S_rs_2369_1 = {&var296,&var380,&var377,&vainSBool,&internal1_m2369_q0};
_S_or4  S_or4_989_1 = {&var847,&var554,&var1251,&var379,&var378};
_S_rs  S_rs_2386_1 = {&var293,&var380,&var379,&vainSBool,&internal1_m2386_q0};
_S_and2  S_and2_2374_1 = {&var381,&var338,&var380};
_S_rs  S_rs_2368_1 = {&var293,&var294,&var381,&vainSBool,&internal1_m2368_q0};
_S_rs  S_rs_2365_1 = {&var350,&var388,&var382,&vainSBool,&internal1_m2365_q0};
_S_or4  S_or4_998_1 = {&var1451,&var426,&var1034,&var386,&var383};
_S_rs  S_rs_2364_1 = {&var314,&var389,&var384,&vainSBool,&internal1_m2364_q0};
_S_and2  S_and2_2372_1 = {&var517,&var382,&var385};
_S_rs  S_rs_2378_1 = {&var314,&var388,&var386,&vainSBool,&internal1_m2378_q0};
_S_or3  S_or3_1367_1 = {&var1042,&var1456,&var390,&var387};
_S_and2  S_and2_2371_1 = {&var384,&var510,&var388};
_S_and2  S_and2_2370_1 = {&var568,&var1458,&var389};
_S_rs  S_rs_2376_1 = {&var316,&var389,&var390,&vainSBool,&internal1_m2376_q0};
_S_or2  S_or2_2237_1 = {&var428,&var1287,&var391};
_S_ovbs  S_ovbs_2239_1 = {&var486,&fRM_2_0,&var392,&internal1_m2239_tx};
_S_or2  S_or2_2240_1 = {&var1467,&var392,&var393};
_S_ovbs  S_ovbs_2218_1 = {&var487,&fRM_2_0,&var394,&internal1_m2218_tx};
_S_or2  S_or2_2216_1 = {&var429,&var1288,&var395};
_S_or2  S_or2_2219_1 = {&var1487,&var394,&var396};
_S_noto  S_noto_1889_1 = {&B2IS21LDU,&var397};
_S_noto  S_noto_1888_1 = {&A2IS21LDU,&var398};
_S_and2  S_and2_2297_1 = {&var1980,&var731,&var399};
_S_or5  S_or5_2300_1 = {&var905,&var1897,&var43,&var372,&var399,&var400};
_S_or5  S_or5_2299_1 = {&var666,&var1449,&var44,&var1897,&var402,&var401};
_S_and2  S_and2_2272_1 = {&var1983,&var732,&var402};
_S_nocnm  S_nocnm_1931_1 = {&R5IS21LDU,&R5IS11LDU,&var403,&var404,&var405,&internal1_m1931_Pv0,&internal1_m1931_Zv0,&internal1_m1931_MyFirstEnterFlag,&bFirstEnterFlag};
_S_nocnm  S_nocnm_1930_1 = {&R3IS11LDU,&R3IS21LDU,&var406,&var407,&var408,&internal1_m1930_Pv0,&internal1_m1930_Zv0,&internal1_m1930_MyFirstEnterFlag,&bFirstEnterFlag};
_S_or5  S_or5_2186_1 = {&var1247,&var955,&C2MD31LP1,&var1246,&var1245,&var409};
_S_or4  S_or4_2161_1 = {&C1MD31LP2,&C1MD31LP1,&var982,&var1002,&var410};
_S_and3  S_and3_450_1 = {&B8IS22LDU,&B8IS21LDU,&var1870,&var411};
_S_and2  S_and2_2257_1 = {&var725,&var437,&var412};
_S_and2  S_and2_2263_1 = {&var728,&var437,&var413};
_S_or4  S_or4_1105_1 = {&var1576,&var917,&var916,&var919,&var414};
_S_or4  S_or4_1579_1 = {&var1544,&var899,&var898,&var902,&var415};
_S_and2  S_and2_2301_1 = {&var656,&var1440,&var416};
_S_and2  S_and2_2286_1 = {&var731,&var1897,&var417};
_S_and2  S_and2_2273_1 = {&var732,&var1897,&var418};
_S_or2  S_or2_614_1 = {&B1VP41LZ2,&B1VP41LZ1,&var419};
_S_or2  S_or2_248_1 = {&A1VP41LZ2,&A1VP41LZ1,&var420};
_S_or2  S_or2_1269_1 = {&B8IS22LDU,&B8IS21LDU,&var421};
_S_or2  S_or2_1266_1 = {&B8IS11LDU,&B8IS12LDU,&var422};
_S_or2  S_or2_376_1 = {&R4IS11LDU,&R4IS12LDU,&var423};
_S_or2  S_or2_389_1 = {&R4IS21LDU,&R4IS22LDU,&var424};
_S_noto  S_noto_2417_1 = {&var1897,&var425};
_S_zzfs  S_zzfs_2405_1 = {&var443,&fRM_0_5,&var426,&internal1_m2405_tx,&internal1_m2405_y0};
_S_or2  S_or2_2440_1 = {&var618,&var1256,&var427};
_S_andn  S_andn_662_1 = {array_m662_x_1,&iRM_6_,&var428};
_S_andn  S_andn_661_1 = {array_m661_x_1,&iRM_6_,&var429};
_S_or2  S_or2_2457_1 = {&var932,&var897,&var430};
_S_noto  S_noto_2402_1 = {&var1286,&var431};
_S_noto  S_noto_2401_1 = {&var1283,&var432};
_S_zpfs  S_zpfs_2410_1 = {&var431,&fRM_30_0,&var433,&internal1_m2410_tx,&internal1_m2410_y0};
_S_noto  S_noto_2415_1 = {&var433,&var434};
_S_zpfs  S_zpfs_2409_1 = {&var432,&fRM_30_0,&var435,&internal1_m2409_tx,&internal1_m2409_y0};
_S_noto  S_noto_2414_1 = {&var435,&var436};
_S_and3  S_and3_2407_1 = {&var475,&var456,&lRM_1_,&var437};
_S_and2  S_and2_1018_1 = {&var1602,&var439,&var438};
_S_noto  S_noto_1004_1 = {&var426,&var439};
_S_and2  S_and2_1493_1 = {&var1570,&var441,&var440};
_S_noto  S_noto_1490_1 = {&var426,&var441};
_S_or2  S_or2_2450_1 = {&var452,&var453,&var442};
_S_and2  S_and2_2404_1 = {&var444,&var437,&var443};
_S_abs_subf  S_abs_subf_2397_1 = {&var1996,&var476,&fEM_A3UC08RDU,&vainSFloat,&var444};
_S_and2  S_and2_2452_1 = {&var437,&var452,&var445};
_S_or4  S_or4_2187_1 = {&var409,&var1060,&var1170,&var445,&var446};
_S_noto  S_noto_2456_1 = {&var430,&var447};
_S_or2  S_or2_2432_1 = {&var469,&var480,&var448};
_S_inf  S_inf_2426_1 = {&var478,array_m2426_a_1,array_m2426_b_1,&iRM_6_,&var449,&vainSInt};
_S_or3  S_or3_2455_1 = {&var465,&var472,&var473,&var450};
_S_noto  S_noto_2454_1 = {&var450,&var451};
_S_noto  S_noto_2451_1 = {&var475,&var452};
_S_ovbs  S_ovbs_2446_1 = {&var455,&fRM_15_0,&var453,&internal1_m2446_tx};
_S_zpfs  S_zpfs_2444_1 = {&var456,&fRM_10_0,&var454,&internal1_m2444_tx,&internal1_m2444_y0};
_S_and2  S_and2_2445_1 = {&var454,&R0MW17LP1,&var455};
_S_rs  S_rs_2449_1 = {&var442,&R0MW17LP1,&var456,&vainSBool,&internal1_m2449_q0};
_S_rs  S_rs_2416_1 = {&var469,&var437,&var457,&vainSBool,&internal1_m2416_q0};
_S_and3  S_and3_2423_1 = {&var471,&var425,&var457,&var458};
_S_ml  S_ml_1471_1 = {&var476,&var578,&var426,&var459};
_S_ml  S_ml_993_1 = {&var476,&var582,&var426,&var460};
_S_and2  S_and2_2474_1 = {&var437,&var595,&var461};
_S_noto  S_noto_2436_1 = {&var427,&var462};
_S_noto  S_noto_2421_1 = {&var1541,&var463};
_S_sr  S_sr_2437_1 = {array_m2437_x_1,&iRM_4_,&var464};
_S_and2  S_and2_2475_1 = {&var466,&var437,&var465};
_S_abs_subf  S_abs_subf_2469_1 = {&B3MC01RP1,&A3MC01RP1,&fRM_0_01,&vainSFloat,&var466};
_S_fsumo  S_fsumo_86_1 = {&var1232,&fEM_R0UN11RDU,&var467};
_S_or3  S_or3_134_1 = {&var410,&var330,&var448,&var468};
_S_ovbs  S_ovbs_2424_1 = {&var458,&fRM_1_0,&var469,&internal1_m2424_tx};
_S_noto  S_noto_2431_1 = {&var448,&var470};
_S_rs  S_rs_2422_1 = {&var469,&var1897,&var471,&vainSBool,&internal1_m2422_q0};
_S_and2  S_and2_2472_1 = {&var480,&var437,&var472};
_S_and2  S_and2_2470_1 = {&var474,&var437,&var473};
_S_bol  S_bol_2461_1 = {&fEM_R0UN09RDU,&var62,&var474};
_S_andn  S_andn_2429_1 = {array_m2429_x_1,&iRM_14_,&var475};
_S_irm  S_irm_2408_1 = {&var1232,&var1230,&B3MC01RP1,&var1996,&var62,&var464,&var437,&var1256,&fEM_R0UN12RDU,&fEM_R0UN13RDU,&fEM_R0UN14RDU,&fEM_R0UT20RDU,&var449,&fEM_R0UN15RDU,&fEM_R0UN25RDU,&fEM_R0UN16RDU,&fEM_R0UN17RDU,&fEM_R0UN18RDU,&fEM_R0UN19RDU,&fEM_R0UN27RDU,&fEM_R0UN26RDU,&fEM_R0UN24RDU,&var476,&var477,&var478,&var479,&var480,&var481,&var482,&var483,&internal1_m2408_fVf0,&internal1_m2408_fRsg,&internal1_m2408_fRct,&internal1_m2408_fVfMin,&internal1_m2408_fStw0,&internal1_m2408_fMaxDk,&internal1_m2408_fkizm,&internal1_m2408_fwt0,&internal1_m2408_fwz0,&internal1_m2408_ftf0,&internal1_m2408_fTk0,&internal1_m2408_FlPar,&internal1_m2408_FlIzm,&internal1_m2408_FlCmp,&internal1_m2408_StabCoun,&internal1_m2408_ZerCoun,&internal1_m2408_SrCoun,&internal1_m2408_LastStage,&internal1_m2408_fef};
_S_noto  S_noto_2246_1 = {&var606,&var484};
_S_noto  S_noto_2215_1 = {&var607,&var485};
_S_and4  S_and4_2238_1 = {&var629,&var391,&var599,&var484,&var486};
_S_and4  S_and4_2217_1 = {&var630,&var395,&var599,&var485,&var487};
_S_zpfs  S_zpfs_2233_1 = {&var613,&fRM_210_0,&var488,&internal1_m2233_tx,&internal1_m2233_y0};
_S_zpfs  S_zpfs_2225_1 = {&var614,&fRM_210_0,&var489,&internal1_m2225_tx,&internal1_m2225_y0};
_S_and2  S_and2_617_1 = {&var1617,&var660,&var490};
_S_and2  S_and2_252_1 = {&var660,&var1650,&var491};
_S_noto  S_noto_1758_1 = {&var493,&var492};
_S_abs_subf  S_abs_subf_1751_1 = {&var1993,&var578,&fEM_A3UC07RDU,&vainSFloat,&var493};
_S_noto  S_noto_1741_1 = {&var495,&var494};
_S_abs_subf  S_abs_subf_1729_1 = {&var582,&var1996,&fEM_A3UC07RDU,&vainSFloat,&var495};
_S_noto  S_noto_1756_1 = {&var497,&var496};
_S_abs_subf  S_abs_subf_1750_1 = {&var586,&var2006,&fEM_A1UC07RDU,&vainSFloat,&var497};
_S_noto  S_noto_1737_1 = {&var499,&var498};
_S_abs_subf  S_abs_subf_1728_1 = {&var590,&var1984,&fEM_A1UC07RDU,&vainSFloat,&var499};
_S_bol  S_bol_1489_1 = {&var1993,&fEM_A3UC09RDU,&var500};
_S_bol  S_bol_1014_1 = {&var1996,&fEM_A3UC09RDU,&var501};
_S_noto  S_noto_1996_1 = {&var506,&var502};
_S_noto  S_noto_1985_1 = {&var504,&var503};
_S_and3  S_and3_1978_1 = {&var1164,&var505,&var1458,&var504};
_S_bol  S_bol_1970_1 = {&fRM_55_0,&var578,&var505};
_S_and3  S_and3_1997_1 = {&var507,&var1163,&var1458,&var506};
_S_bol  S_bol_2006_1 = {&fRM_55_0,&var582,&var507};
_S_and4  S_and4_46_1 = {&var1888,&var1162,&var1345,&var1440,&var508};
_S_noto  S_noto_1389_1 = {&var1212,&var509};
_S_and2  S_and2_1394_1 = {&var1717,&var1212,&var510};
_S_and2  S_and2_1390_1 = {&var1717,&var509,&var511};
_S_noto  S_noto_1335_1 = {&var1212,&var512};
_S_and2  S_and2_1339_1 = {&var1212,&var1791,&var513};
_S_and2  S_and2_1332_1 = {&var1791,&var512,&var514};
_S_noto  S_noto_1021_1 = {&var1212,&var515};
_S_and2  S_and2_1022_1 = {&var515,&var1573,&var516};
_S_and2  S_and2_1019_1 = {&var1573,&var1212,&var517};
_S_noto  S_noto_514_1 = {&var1212,&var518};
_S_and2  S_and2_515_1 = {&var518,&var1666,&var519};
_S_and2  S_and2_518_1 = {&var1666,&var1212,&var520};
_S_noto  S_noto_195_1 = {&var1212,&var521};
_S_and2  S_and2_196_1 = {&var521,&var1636,&var522};
_S_and2  S_and2_198_1 = {&var1212,&var1636,&var523};
_S_and2  S_and2_128_1 = {&var526,&var650,&var524};
_S_and2  S_and2_129_1 = {&var1212,&var650,&var525};
_S_noto  S_noto_123_1 = {&var1212,&var526};
_S_and2  S_and2_124_1 = {&var526,&var649,&var527};
_S_and2  S_and2_125_1 = {&var1212,&var649,&var528};
_S_and2  S_and2_1845_1 = {&var564,&var1462,&var529};
_S_and2  S_and2_1844_1 = {&var567,&var1462,&var530};
_S_and2  S_and2_1843_1 = {&var565,&var1462,&var531};
_S_and2  S_and2_1842_1 = {&var1462,&var568,&var532};
_S_and2  S_and2_1841_1 = {&var774,&var566,&var533};
_S_and2  S_and2_1840_1 = {&var774,&var569,&var534};
_S_and2  S_and2_1839_1 = {&var775,&var566,&var535};
_S_and2  S_and2_1838_1 = {&var775,&var569,&var536};
_S_and2  S_and2_1871_1 = {&var302,&var1421,&var537};
_S_and2  S_and2_1870_1 = {&var564,&var1463,&var538};
_S_and2  S_and2_1869_1 = {&var1422,&var510,&var539};
_S_and2  S_and2_1868_1 = {&var1463,&var567,&var540};
_S_and2  S_and2_1867_1 = {&var398,&var1423,&var541};
_S_and2  S_and2_1866_1 = {&var1463,&var565,&var542};
_S_and2  S_and2_1865_1 = {&var1424,&var510,&var543};
_S_and2  S_and2_1864_1 = {&var1463,&var568,&var544};
_S_and2  S_and2_1902_1 = {&var510,&var1425,&var545};
_S_and2  S_and2_1901_1 = {&var566,&var1461,&var546};
_S_and2  S_and2_1899_1 = {&var1426,&var513,&var547};
_S_and2  S_and2_1898_1 = {&var1427,&var513,&var548};
_S_and2  S_and2_1897_1 = {&var569,&var1461,&var549};
_S_rs  S_rs_1919_1 = {&var304,&var551,&var550,&vainSBool,&internal1_m1919_q0};
_S_and2  S_and2_1918_1 = {&var1459,&var564,&var551};
_S_and2  S_and2_1917_1 = {&var1459,&var567,&var552};
_S_rs  S_rs_1924_1 = {&var325,&var552,&var553,&vainSBool,&internal1_m1924_q0};
_S_rs  S_rs_1916_1 = {&var305,&var555,&var554,&vainSBool,&internal1_m1916_q0};
_S_and2  S_and2_1915_1 = {&var565,&var1459,&var555};
_S_and2  S_and2_1914_1 = {&var1459,&var568,&var556};
_S_and2  S_and2_1947_1 = {&var566,&var1890,&var557};
_S_rs  S_rs_1958_1 = {&var520,&var557,&var558,&vainSBool,&internal1_m1958_q0};
_S_and2  S_and2_1946_1 = {&var1890,&var569,&var559};
_S_and2  S_and2_1944_1 = {&var564,&var1447,&var560};
_S_and2  S_and2_1943_1 = {&var1447,&var567,&var561};
_S_and2  S_and2_1941_1 = {&var565,&var1447,&var562};
_S_and2  S_and2_1940_1 = {&var1447,&var568,&var563};
_S_and2  S_and2_1960_1 = {&var1164,&var566,&var564};
_S_and2  S_and2_1939_1 = {&var1163,&var566,&var565};
_S_and2  S_and2_1962_1 = {&var525,&var1503,&var566};
_S_and2  S_and2_1959_1 = {&var569,&var1164,&var567};
_S_and2  S_and2_1938_1 = {&var569,&var1163,&var568};
_S_and2  S_and2_1961_1 = {&var528,&var1503,&var569};
_S_zpfs  S_zpfs_830_1 = {&var1128,&fRM_3_,&var570,&internal1_m830_tx,&internal1_m830_y0};
_S_or4  S_or4_1775_1 = {&var765,&var766,&var767,&var769,&var571};
_S_or5  S_or5_1762_1 = {&var773,&var772,&var771,&var770,&var571,&var572};
_S_andn  S_andn_1_1 = {array_m1_x_1,&iRM_47_,&vainSBool};
_S_or2  S_or2_1743_1 = {&var575,&var576,&var573};
_S_ml  S_ml_1731_1 = {&fRM_1500_0,&B8MC01RP2,&var573,&var574};
_S_bol  S_bol_1734_1 = {&B8MC01RP2,&fRM_1500_0001,&var575};
_S_bol  S_bol_1745_1 = {&fRM_389_99,&B8MC01RP2,&var576};
_S_or2  S_or2_1757_1 = {&var579,&var580,&var577};
_S_ml  S_ml_1749_1 = {&fRM_0_0,&B3MC01RP1,&var577,&var578};
_S_bol  S_bol_1753_1 = {&B3MC01RP1,&fRM_160_00001,&var579};
_S_bol  S_bol_1761_1 = {&fRM_0_0001,&B3MC01RP1,&var580};
_S_or2  S_or2_1739_1 = {&var583,&var584,&var581};
_S_ml  S_ml_1727_1 = {&fRM_0_0,&A3MC01RP1,&var581,&var582};
_S_bol  S_bol_1733_1 = {&A3MC01RP1,&fRM_160_0001,&var583};
_S_bol  S_bol_1740_1 = {&fRM_0_0001,&A3MC01RP1,&var584};
_S_or2  S_or2_1755_1 = {&var587,&var588,&var585};
_S_ml  S_ml_1747_1 = {&fRM_100_0,&B1MC01RP1,&var585,&var586};
_S_bol  S_bol_1752_1 = {&B1MC01RP1,&fRM_100_0001,&var587};
_S_bol  S_bol_1759_1 = {&fRM_0_0001,&B1MC01RP1,&var588};
_S_or2  S_or2_1736_1 = {&var591,&var592,&var589};
_S_ml  S_ml_1725_1 = {&fRM_100_0,&A1MC01RP1,&var589,&var590};
_S_bol  S_bol_1732_1 = {&A1MC01RP1,&fRM_100_0001,&var591};
_S_bol  S_bol_1744_1 = {&fRM_0_0001,&A1MC01RP1,&var592};
_S_and2  S_and2_109_1 = {&var336,&var423,&var593};
_S_noto  S_noto_110_1 = {&var423,&var594};
_S_and2  S_and2_113_1 = {&var336,&var594,&var595};
_S_and2  S_and2_2203_1 = {&var597,&var598,&var596};
_S_or3  S_or3_2202_1 = {&var1465,&var718,&var446,&var597};
_S_noto  S_noto_2241_1 = {&var393,&var598};
_S_noto  S_noto_2230_1 = {&var600,&var599};
_S_ovbs  S_ovbs_2229_1 = {&var1357,&fRM_2_0,&var600,&internal1_m2229_tx};
_S_noto  S_noto_2220_1 = {&var396,&var601};
_S_and2  S_and2_2189_1 = {&var603,&var601,&var602};
_S_or3  S_or3_2188_1 = {&var446,&var1469,&var718,&var603};
_S_noto  S_noto_2235_1 = {&var611,&var604};
_S_and2  S_and2_2236_1 = {&var1440,&var604,&var605};
_S_and2  S_and2_2244_1 = {&var605,&var391,&var606};
_S_and2  S_and2_2223_1 = {&var608,&var395,&var607};
_S_and2  S_and2_2228_1 = {&var609,&var1440,&var608};
_S_noto  S_noto_2227_1 = {&var1155,&var609};
_S_noto  S_noto_2243_1 = {&var613,&var610};
_S_or2  S_or2_2234_1 = {&var488,&var610,&var611};
_S_noto  S_noto_2222_1 = {&var614,&var612};
_S_rs  S_rs_2232_1 = {&var488,&var619,&var613,&vainSBool,&internal1_m2232_q0};
_S_rs  S_rs_2224_1 = {&var489,&var620,&var614,&vainSBool,&internal1_m2224_q0};
_S_and2  S_and2_2212_1 = {&var617,&var624,&var615};
_S_and2  S_and2_2200_1 = {&var617,&var621,&var616};
_S_noto  S_noto_2194_1 = {&var618,&var617};
_S_ovbs  S_ovbs_2193_1 = {&var446,&fRM_10_0,&var618,&internal1_m2193_tx};
_S_ovbs  S_ovbs_2204_1 = {&var596,&fRM_2_0,&var619,&internal1_m2204_tx};
_S_ovbs  S_ovbs_2190_1 = {&var602,&fRM_2_0,&var620,&internal1_m2190_tx};
_S_or2  S_or2_2199_1 = {&var651,&var1217,&var621};
_S_or2  S_or2_2195_1 = {&var652,&var602,&var622};
_S_or2  S_or2_2207_1 = {&var652,&var596,&var623};
_S_or2  S_or2_2211_1 = {&var651,&var1214,&var624};
_S_rs  S_rs_2196_1 = {&var616,&var622,&var625,&vainSBool,&internal1_m2196_q0};
_S_noto  S_noto_2209_1 = {&var627,&var626};
_S_rs  S_rs_2208_1 = {&var615,&var623,&var627,&vainSBool,&internal1_m2208_q0};
_S_noto  S_noto_2197_1 = {&var625,&var628};
_S_noto  S_noto_2205_1 = {&var619,&var629};
_S_noto  S_noto_2191_1 = {&var620,&var630};
_S_and2  S_and2_2184_1 = {&var633,&var724,&var631};
_S_and2  S_and2_2174_1 = {&var633,&var721,&var632};
_S_noto  S_noto_2166_1 = {&var634,&var633};
_S_ovbs  S_ovbs_2165_1 = {&var410,&fRM_3_0,&var634,&internal1_m2165_tx};
_S_and2  S_and2_482_1 = {&var1862,&var1804,&var635};
_S_and2  S_and2_2059_1 = {&var1416,&B7AS31LDU,&var636};
_S_and2  S_and2_494_1 = {&var1163,&var1009,&var637};
_S_and2  S_and2_485_1 = {&var1010,&var1163,&var638};
_S_and2  S_and2_528_1 = {&var1009,&var1164,&var639};
_S_and2  S_and2_523_1 = {&var1010,&var1164,&var640};
_S_or2  S_or2_387_1 = {&var1875,&var1135,&var641};
_S_or2  S_or2_383_1 = {&var1875,&var1134,&var642};
_S_ovbs  S_ovbs_52_1 = {&var1887,&fRM_15_0,&var643,&internal1_m52_tx};
_S_ovbs  S_ovbs_364_1 = {&var1364,&fRM_0_02,&var644,&internal1_m364_tx};
_S_ovbs  S_ovbs_317_1 = {&var1366,&fRM_0_02,&var645,&internal1_m317_tx};
_S_ovbs  S_ovbs_831_1 = {&var570,&fRM_0_2,&var646,&internal1_m831_tx};
_S_ovbs  S_ovbs_1623_1 = {&R0MD31LP1,&fRM_10_0,&var647,&internal1_m1623_tx};
_S_ovbs  S_ovbs_120_1 = {&R0MD31LP1,&fRM_0_15,&var648,&internal1_m120_tx};
_S_ovbs  S_ovbs_122_1 = {&var595,&fRM_0_02,&var649,&internal1_m122_tx};
_S_ovbs  S_ovbs_127_1 = {&R0MD32LP1,&fRM_0_02,&var650,&internal1_m127_tx};
_S_ovbs  S_ovbs_21_1 = {&var1440,&fRM_3_0,&var651,&internal1_m21_tx};
_S_ovbs  S_ovbs_13_1 = {&var1212,&fRM_3_0,&var652,&internal1_m13_tx};
_S_ovbs  S_ovbs_2175_1 = {&var410,&fRM_2_0,&var653,&internal1_m2175_tx};
_S_ovbs  S_ovbs_2162_1 = {&var410,&fRM_2_0,&var654,&internal1_m2162_tx};
_S_ovbs  S_ovbs_2280_1 = {&var1449,&fRM_2_0,&var655,&internal1_m2280_tx};
_S_ovbs  S_ovbs_2282_1 = {&var372,&fRM_2_0,&var656,&internal1_m2282_tx};
_S_ovbs  S_ovbs_82_1 = {&R0MW13LP2,&fRM_10_0,&var657,&internal1_m82_tx};
_S_zpfs  S_zpfs_335_1 = {&var1066,&fRM_10_0,&var658,&internal1_m335_tx,&internal1_m335_y0};
_S_or2  S_or2_1154_1 = {&var1277,&var836,&var659};
_S_or2  S_or2_253_1 = {&A1VN71LZ1,&A1VN71LZ2,&var660};
_S_or2  S_or2_275_1 = {&var961,&var1229,&var661};
_S_or5  S_or5_157_1 = {&B1IS21LDU,&B3IS21LDU,&B2IS21LDU,&var1199,&var1200,&var662};
_S_and2  S_and2_1151_1 = {&var1712,&var1348,&var663};
_S_or3  S_or3_1108_1 = {&var414,&var921,&var920,&var664};
_S_or3  S_or3_1581_1 = {&var904,&var903,&var415,&var665};
_S_and2  S_and2_1082_1 = {&var1477,&var1258,&var666};
_S_and3  S_and3_2082_1 = {&var675,&var61,&var668,&var667};
_S_or2  S_or2_2069_1 = {&var1270,&var1380,&var668};
_S_or3  S_or3_2075_1 = {&var673,&var1380,&var671,&var669};
_S_and2  S_and2_2081_1 = {&var1270,&var61,&var670};
_S_and2  S_and2_2074_1 = {&var1372,&var672,&var671};
_S_zpfs  S_zpfs_2073_1 = {&var1270,&fEM_R0UL04RDU,&var672,&internal1_m2073_tx,&internal1_m2073_y0};
_S_and2  S_and2_2066_1 = {&var1375,&var821,&var673};
_S_or3  S_or3_2067_1 = {&var1329,&var827,&var1307,&var674};
_S_abs_subf  S_abs_subf_2088_1 = {&fEM_R0UL02RDU,&var676,&fEM_R0UL16RDU,&vainSFloat,&var675};
_S_rsfn  S_rsfn_2087_1 = {&var818,&var677,&var676,&internal1_m2087_q0};
_S_lk  S_lk_2085_1 = {&var1532,&var61,&var677};
_S_abs_subf  S_abs_subf_1653_1 = {&fEM_R0UL05RDU,&var679,&fEM_R0UL18RDU,&vainSFloat,&var678};
_S_rsfn  S_rsfn_1644_1 = {&var818,&var680,&var679,&internal1_m1644_q0};
_S_lk  S_lk_1648_1 = {&var1386,&var805,&var680};
_S_abs_subf  S_abs_subf_1698_1 = {&fEM_R0UL07RDU,&var682,&fEM_R0UL20RDU,&vainSFloat,&var681};
_S_rsfn  S_rsfn_1682_1 = {&var818,&var683,&var682,&internal1_m1682_q0};
_S_lk  S_lk_1689_1 = {&var1392,&var795,&var683};
_S_ma  S_ma_1665_1 = {array_m1665_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_abs_subf  S_abs_subf_1703_1 = {&fEM_R0UL25RDU,&var685,&fEM_R0UL19RDU,&vainSFloat,&var684};
_S_rsfn  S_rsfn_1685_1 = {&var818,&var686,&var685,&internal1_m1685_q0};
_S_lk  S_lk_1691_1 = {&var1530,&var786,&var686};
_S_and3  S_and3_2132_1 = {&var688,&var691,&var698,&var687};
_S_abs_subf  S_abs_subf_2129_1 = {&var689,&fEM_R0UL03RDU,&fEM_R0UL17RDU,&vainSFloat,&var688};
_S_rsfn  S_rsfn_2127_1 = {&var818,&var690,&var689,&internal1_m2127_q0};
_S_lk  S_lk_2123_1 = {&var1531,&var691,&var690};
_S_or3  S_or3_2122_1 = {&var696,&var702,&var701,&var691};
_S_and4  S_and4_2126_1 = {&var701,&var1537,&var714,&var712,&var692};
_S_and4  S_and4_2124_1 = {&var702,&var1537,&var714,&var712,&var693};
_S_and2  S_and2_2116_1 = {&var45,&var691,&var694};
_S_and2  S_and2_2102_1 = {&var821,&var1374,&var695};
_S_and2  S_and2_2106_1 = {&var699,&var1373,&var696};
_S_or3  S_or3_2107_1 = {&var696,&var695,&var1383,&var697};
_S_or2  S_or2_2098_1 = {&var45,&var1383,&var698};
_S_zpfs  S_zpfs_2105_1 = {&var45,&fEM_R0UL21RDU,&var699,&internal1_m2105_tx,&internal1_m2105_y0};
_S_or3  S_or3_2095_1 = {&var823,&var1333,&var1311,&var700};
_S_zpfs  S_zpfs_2120_1 = {&var704,&fEM_R0UL03RDU,&var701,&internal1_m2120_tx,&internal1_m2120_y0};
_S_zpfs  S_zpfs_2117_1 = {&var705,&fEM_R0UL03RDU,&var702,&internal1_m2117_tx,&internal1_m2117_y0};
_S_or2  S_or2_2114_1 = {&var705,&var704,&var703};
_S_or2  S_or2_2115_1 = {&var706,&var45,&var704};
_S_or2  S_or2_2113_1 = {&var707,&var45,&var705};
_S_and4  S_and4_2110_1 = {&var1438,&var1164,&B2IS12LDU,&var708,&var706};
_S_and4  S_and4_2104_1 = {&var1439,&A2IS12LDU,&var1163,&var708,&var707};
_S_and2  S_and2_2103_1 = {&var1186,&var712,&var708};
_S_and3  S_and3_2141_1 = {&var1164,&var1295,&var711,&var709};
_S_and3  S_and3_2140_1 = {&var1163,&var1296,&var711,&var710};
_S_and4  S_and4_2139_1 = {&var1257,&var1056,&var1058,&var712,&var711};
_S_and2  S_and2_2133_1 = {&var1069,&var1258,&var712};
_S_or2  S_or2_2135_1 = {&var1541,&var1256,&var713};
_S_or3  S_or3_2144_1 = {&var717,&var716,&var719,&var714};
_S_and2  S_and2_2134_1 = {&var1299,&A2IS12LDU,&var715};
_S_and2  S_and2_2138_1 = {&var1196,&var715,&var716};
_S_and3  S_and3_2143_1 = {&var1536,&var720,&var715,&var717};
_S_or2  S_or2_2152_1 = {&lRM_0_,&var713,&var718};
_S_and2  S_and2_2149_1 = {&var1211,&var720,&var719};
_S_and2  S_and2_2151_1 = {&var1298,&B2IS12LDU,&var720};
_S_or2  S_or2_2173_1 = {&var1216,&var651,&var721};
_S_or2  S_or2_2167_1 = {&var652,&var410,&var722};
_S_or2  S_or2_2179_1 = {&var410,&var652,&var723};
_S_or2  S_or2_2183_1 = {&var651,&var1215,&var724};
_S_or2  S_or2_2248_1 = {&var1064,&var1450,&var725};
_S_or2  S_or2_2258_1 = {&var1258,&var1471,&var726};
_S_zpfs  S_zpfs_2260_1 = {&var341,&fRM_15_0,&var727,&internal1_m2260_tx,&internal1_m2260_y0};
_S_or2  S_or2_2264_1 = {&var1063,&var373,&var728};
_S_zpfs  S_zpfs_2271_1 = {&var339,&fRM_15_0,&var729,&internal1_m2271_tx,&internal1_m2271_y0};
_S_or2  S_or2_2276_1 = {&var1258,&var1470,&var730};
_S_or2  S_or2_2292_1 = {&var345,&var692,&var731};
_S_or2  S_or2_2287_1 = {&var693,&var349,&var732};
_S_and2  S_and2_2298_1 = {&var1440,&var655,&var733};
_S_and2  S_and2_2058_1 = {&var1417,&A7AS31LDU,&var734};
_S_or3  S_or3_2031_1 = {&var739,&var743,&var741,&var735};
_S_or3  S_or3_2032_1 = {&var742,&var741,&var738,&var736};
_S_or2  S_or2_2045_1 = {&B0VT71LZ1,&B0VT71LZ2,&var737};
_S_and2  S_and2_2036_1 = {&var744,&var737,&var738};
_S_and2  S_and2_2030_1 = {&var744,&var740,&var739};
_S_or2  S_or2_2029_1 = {&A0VT71LZ1,&A0VT71LZ2,&var740};
_S_zpfs  S_zpfs_2026_1 = {&var1434,&fRM_2_5,&var741,&internal1_m2026_tx,&internal1_m2026_y0};
_S_zpfs  S_zpfs_2025_1 = {&var1435,&fRM_2_5,&var742,&internal1_m2025_tx,&internal1_m2025_y0};
_S_zpfs  S_zpfs_2024_1 = {&var1436,&fRM_2_5,&var743,&internal1_m2024_tx,&internal1_m2024_y0};
_S_zpfs  S_zpfs_2023_1 = {&var1437,&fRM_2_5,&var744,&internal1_m2023_tx,&internal1_m2023_y0};
_S_or2  S_or2_2054_1 = {&R0VP73LZ2,&R0VP73LZ1,&var745};
_S_and2  S_and2_2048_1 = {&var372,&var1418,&var746};
_S_or2  S_or2_2044_1 = {&var749,&var746,&var747};
_S_or2  S_or2_2046_1 = {&var345,&var372,&var748};
_S_and2  S_and2_2043_1 = {&var345,&var1408,&var749};
_S_and2  S_and2_2027_1 = {&var1449,&var1419,&var750};
_S_or2  S_or2_2028_1 = {&var753,&var750,&var751};
_S_or2  S_or2_2021_1 = {&var349,&var1449,&var752};
_S_and2  S_and2_2020_1 = {&var349,&var1409,&var753};
_S_or3  S_or3_1990_1 = {&var1500,&var1458,&var1459,&var754};
_S_or3  S_or3_1991_1 = {&var1498,&var1458,&var1459,&var755};
_S_or2  S_or2_1982_1 = {&var1493,&var1458,&var756};
_S_or2  S_or2_1983_1 = {&var1492,&var1458,&var757};
_S_or2  S_or2_1989_1 = {&var1502,&var1461,&var758};
_S_or4  S_or4_1987_1 = {&var1461,&var1499,&var1462,&var1463,&var759};
_S_or4  S_or4_1986_1 = {&var1461,&var1505,&var1462,&var1463,&var760};
_S_or2  S_or2_1980_1 = {&var1494,&var1463,&var761};
_S_or2  S_or2_1979_1 = {&var1495,&var1463,&var762};
_S_or2  S_or2_1988_1 = {&var1461,&var1501,&var763};
_S_or2  S_or2_1957_1 = {&var520,&var566,&var764};
_S_and2  S_and2_1780_1 = {&var1755,&var1713,&var765};
_S_and2  S_and2_1779_1 = {&var1878,&var1713,&var766};
_S_and2  S_and2_1778_1 = {&var1153,&var1713,&var767};
_S_or2  S_or2_1777_1 = {&B4IS11LDU,&A4IS11LDU,&var768};
_S_and2  S_and2_1776_1 = {&var768,&var1713,&var769};
_S_and2  S_and2_1766_1 = {&var1933,&var1713,&var770};
_S_and2  S_and2_1765_1 = {&var423,&var1713,&var771};
_S_and2  S_and2_1764_1 = {&var1142,&var1713,&var772};
_S_and2  S_and2_1763_1 = {&R3IS21LDU,&var1713,&var773};
_S_or2  S_or2_1837_1 = {&var1891,&var1892,&var774};
_S_or2  S_or2_1836_1 = {&var1893,&var1891,&var775};
_S_or2  S_or2_2317_1 = {&var1235,&R0MD34LP1,&var776};
_S_or3  S_or3_2323_1 = {&var1512,&var1514,&var1513,&var777};
_S_or3  S_or3_2314_1 = {&var1518,&var1520,&var1519,&var778};
_S_or2  S_or2_1821_1 = {&var1991,&var1713,&var779};
_S_or2  S_or2_1793_1 = {&var1756,&var1348,&var780};
_S_or5  S_or5_1279_1 = {&var1771,&var782,&var1782,&var1768,&var1769,&var781};
_S_or3  S_or3_1283_1 = {&var1776,&var1777,&var1238,&var782};
_S_or5  S_or5_1808_1 = {&var572,&var784,&var1765,&var1757,&var1758,&var783};
_S_or3  S_or3_1811_1 = {&var1237,&var1760,&var1759,&var784};
_S_and3  S_and3_1712_1 = {&var786,&var791,&var684,&var785};
_S_and2  S_and2_1715_1 = {&var787,&var1268,&var786};
_S_or3  S_or3_1714_1 = {&A3VZ13LZ2,&A3VZ13LZ1,&var790,&var787};
_S_zpfs  S_zpfs_1699_1 = {&var1268,&fRM_0_2,&var788,&internal1_m1699_tx,&internal1_m1699_y0};
_S_or3  S_or3_1701_1 = {&var1394,&var790,&var792,&var789};
_S_and2  S_and2_1700_1 = {&var1371,&var788,&var790};
_S_or2  S_or2_1690_1 = {&var1268,&var1394,&var791};
_S_and2  S_and2_1677_1 = {&var1376,&var821,&var792};
_S_or3  S_or3_1683_1 = {&var1308,&var1330,&var826,&var793};
_S_or3  S_or3_1708_1 = {&R0AD14LZ1,&R0AD14LZ2,&var797,&var794};
_S_and2  S_and2_1709_1 = {&var794,&var1266,&var795};
_S_zpfs  S_zpfs_1692_1 = {&var1266,&fEM_R0UL06RDU,&var796,&internal1_m1692_tx,&internal1_m1692_y0};
_S_and2  S_and2_1693_1 = {&var796,&var1370,&var797};
_S_or3  S_or3_1694_1 = {&var1389,&var797,&var800,&var798};
_S_or3  S_or3_1667_1 = {&var825,&var1331,&var1309,&var799};
_S_and2  S_and2_1672_1 = {&var1377,&var821,&var800};
_S_and3  S_and3_1711_1 = {&var681,&var795,&var808,&var801};
_S_zpfs  S_zpfs_1639_1 = {&var1265,&fEM_R0UL04RDU,&var802,&internal1_m1639_tx,&internal1_m1639_y0};
_S_and2  S_and2_1640_1 = {&var802,&var1369,&var803};
_S_and3  S_and3_1657_1 = {&var678,&var805,&var809,&var804};
_S_and2  S_and2_1651_1 = {&var806,&var1265,&var805};
_S_or3  S_or3_1650_1 = {&A3VZ15LZ1,&A3VZ15LZ2,&var803,&var806};
_S_or3  S_or3_1641_1 = {&var810,&var803,&var1387,&var807};
_S_or2  S_or2_1686_1 = {&var1266,&var1389,&var808};
_S_or2  S_or2_1637_1 = {&var1265,&var1387,&var809};
_S_and2  S_and2_1629_1 = {&var1378,&var821,&var810};
_S_or3  S_or3_1627_1 = {&var1310,&var1332,&var824,&var811};
_S_or2  S_or2_1590_1 = {&var1884,&var813,&var812};
_S_and2  S_and2_1589_1 = {&var814,&var1432,&var813};
_S_or2  S_or2_1588_1 = {&var1209,&var1161,&var814};
_S_or2  S_or2_1585_1 = {&var1303,&var1325,&var815};
_S_and2  S_and2_1583_1 = {&var1397,&var1398,&var816};
_S_and2  S_and2_1586_1 = {&var815,&var814,&var817};
_S_or5  S_or5_1587_1 = {&var645,&var644,&var816,&var817,&R0MD34LP1,&var818};
_S_orni  S_orni_1616_1 = {array_m1616_x_1,&iRM_5_,&var819,&var820};
_S_or5  S_or5_1618_1 = {&var1393,&var1368,&var818,&var1313,&var647,&var821};
_S_and2  S_and2_1617_1 = {&var819,&var1524,&var822};
_S_or2  S_or2_1626_1 = {&var58,&var60,&var823};
_S_or2  S_or2_1620_1 = {&var56,&var828,&var824};
_S_or2  S_or2_1612_1 = {&var55,&var829,&var825};
_S_or2  S_or2_1608_1 = {&var57,&var830,&var826};
_S_or2  S_or2_1604_1 = {&var59,&var831,&var827};
_S_and2  S_and2_1619_1 = {&var1339,&var1334,&var828};
_S_and2  S_and2_1611_1 = {&var1338,&var1334,&var829};
_S_and2  S_and2_1607_1 = {&var1334,&var1337,&var830};
_S_and2  S_and2_1603_1 = {&var1336,&var1334,&var831};
_S_and2  S_and2_1594_1 = {&var1884,&var332,&var832};
_S_and3  S_and3_1184_1 = {&var514,&var837,&var855,&var833};
_S_or2  S_or2_1149_1 = {&var1350,&var1346,&var834};
_S_or2  S_or2_1174_1 = {&var1346,&var1280,&var835};
_S_and2  S_and2_1142_1 = {&var1722,&var1347,&var836};
_S_and2  S_and2_1137_1 = {&var1541,&var857,&var837};
_S_or3  S_or3_1146_1 = {&var1346,&var1276,&var1349,&var838};
_S_and2  S_and2_1150_1 = {&var511,&var1541,&var839};
_S_and2  S_and2_1175_1 = {&var522,&var1541,&var840};
_S_and2  S_and2_1183_1 = {&var516,&var1541,&var841};
_S_and2  S_and2_1190_1 = {&var519,&var1541,&var842};
_S_and3  S_and3_1132_1 = {&var845,&var1262,&var1541,&var843};
_S_and3  S_and3_1126_1 = {&var846,&var1262,&var1541,&var844};
_S_and2  S_and2_1134_1 = {&var1163,&var1540,&var845};
_S_and2  S_and2_1124_1 = {&var1164,&var1540,&var846};
_S_and4  S_and4_1133_1 = {&var845,&var1541,&var1273,&var1260,&var847};
_S_and4  S_and4_1127_1 = {&var846,&var1541,&var1273,&var1260,&var848};
_S_and4  S_and4_1131_1 = {&var1541,&var845,&var853,&var1261,&var849};
_S_and4  S_and4_1125_1 = {&var1541,&var846,&var853,&var1261,&var850};
_S_and2  S_and2_1118_1 = {&var1274,&var1541,&var851};
_S_or4  S_or4_1121_1 = {&R0MD31LP1,&var1775,&var527,&var864,&var852};
_S_and3  S_and3_1167_1 = {&var1275,&var1274,&var1273,&var853};
_S_and2  S_and2_1155_1 = {&var855,&var659,&var854};
_S_and2  S_and2_1159_1 = {&var1272,&var853,&var855};
_S_or2  S_or2_1168_1 = {&var1342,&var1284,&var856};
_S_and2  S_and2_1177_1 = {&var858,&var856,&var857};
_S_or2  S_or2_1169_1 = {&var1283,&var1285,&var858};
_S_or2  S_or2_1170_1 = {&var1282,&var1283,&var859};
_S_or2  S_or2_1172_1 = {&var1281,&var1286,&var860};
_S_and2  S_and2_1173_1 = {&var859,&var860,&var861};
_S_or2  S_or2_1162_1 = {&var1342,&var1341,&var862};
_S_and2  S_and2_1163_1 = {&var862,&var1278,&var863};
_S_and5  S_and5_1114_1 = {&var865,&var1362,&var1283,&var1342,&var854,&var864};
_S_and2  S_and2_1115_1 = {&var1317,&var1318,&var865};
_S_and2  S_and2_1405_1 = {&var1411,&var867,&var866};
_S_or2  S_or2_1400_1 = {&A2MD12LP1,&var868,&var867};
_S_and2  S_and2_1388_1 = {&A2MD11LP1,&var1428,&var868};
_S_or2  S_or2_1381_1 = {&var871,&B2MD12LP1,&var869};
_S_and2  S_and2_1383_1 = {&var869,&var1411,&var870};
_S_and2  S_and2_1375_1 = {&B2MD11LP1,&var1429,&var871};
_S_or3  S_or3_1363_1 = {&var1491,&var1486,&var1027,&var872};
_S_or5  S_or5_1378_1 = {&var875,&var1247,&var1752,&var1747,&var1746,&var873};
_S_or2  S_or2_1399_1 = {&var2003,&var1737,&var874};
_S_or3  S_or3_1466_1 = {&var1718,&var876,&var877,&var875};
_S_and2  S_and2_1457_1 = {&var1737,&var1210,&var876};
_S_and2  S_and2_1456_1 = {&var1160,&var1737,&var877};
_S_and3  S_and3_1455_1 = {&var662,&var1196,&var892,&var878};
_S_and2  S_and2_1454_1 = {&var423,&var892,&var879};
_S_and3  S_and3_1448_1 = {&var1185,&var1231,&var892,&var880};
_S_and2  S_and2_1447_1 = {&var745,&var892,&var881};
_S_and2  S_and2_1432_1 = {&var1728,&var892,&var882};
_S_and2  S_and2_1416_1 = {&var1933,&var892,&var883};
_S_and2  S_and2_1434_1 = {&var330,&var892,&var884};
_S_and2  S_and2_1417_1 = {&R3IS21LDU,&var892,&var885};
_S_and2  S_and2_1435_1 = {&var888,&var892,&var886};
_S_and3  S_and3_1418_1 = {&var889,&var1727,&var892,&var887};
_S_or2  S_or2_1436_1 = {&var1720,&var1721,&var888};
_S_or2  S_or2_1420_1 = {&A4IS11LDU,&B4IS11LDU,&var889};
_S_and3  S_and3_1431_1 = {&var1461,&var528,&var1212,&var890};
_S_and3  S_and3_1430_1 = {&var1463,&var528,&var1212,&var891};
_S_or3  S_or3_1419_1 = {&var1738,&var891,&var890,&var892};
_S_and2  S_and2_1513_1 = {&var894,&var1411,&var893};
_S_or2  S_or2_1512_1 = {&var895,&B3MD12LP1,&var894};
_S_and2  S_and2_1499_1 = {&B3MD11LP1,&var1407,&var895};
_S_or2  S_or2_1504_1 = {&var1994,&var1555,&var896};
_S_or5  S_or5_1492_1 = {&var665,&var1564,&var1565,&var440,&var1245,&var897};
_S_and2  S_and2_1564_1 = {&var1555,&var1210,&var898};
_S_and2  S_and2_1563_1 = {&var1555,&var1160,&var899};
_S_and2  S_and2_1577_1 = {&var1226,&var1543,&var900};
_S_or2  S_or2_1570_1 = {&var900,&var1227,&var901};
_S_and3  S_and3_1562_1 = {&var1420,&var901,&var910,&var902};
_S_and3  S_and3_1561_1 = {&var662,&var1211,&var910,&var903};
_S_and2  S_and2_1560_1 = {&var423,&var910,&var904};
_S_and2  S_and2_1555_1 = {&var1475,&var1258,&var905};
_S_or2  S_or2_1542_1 = {&var1546,&var1545,&var906};
_S_and2  S_and2_1541_1 = {&var906,&var910,&var907};
_S_and2  S_and2_1540_1 = {&var330,&var910,&var908};
_S_and2  S_and2_1538_1 = {&var1548,&var910,&var909};
_S_or2  S_or2_1527_1 = {&var1557,&var353,&var910};
_S_or2  S_or2_1528_1 = {&B4IS11LDU,&A4IS11LDU,&var911};
_S_and3  S_and3_1525_1 = {&var1547,&var911,&var910,&var912};
_S_and2  S_and2_1524_1 = {&R3IS21LDU,&var910,&var913};
_S_and2  S_and2_1523_1 = {&var1933,&var910,&var914};
_S_and2  S_and2_1101_1 = {&var1224,&var1575,&var915};
_S_and2  S_and2_1090_1 = {&var1160,&var1587,&var916};
_S_and2  S_and2_1091_1 = {&var1210,&var1587,&var917};
_S_or2  S_or2_1097_1 = {&var1225,&var915,&var918};
_S_and3  S_and3_1089_1 = {&var1420,&var918,&var925,&var919};
_S_and3  S_and3_1088_1 = {&var1196,&var662,&var925,&var920};
_S_and2  S_and2_1087_1 = {&var423,&var925,&var921};
_S_and2  S_and2_1065_1 = {&var1580,&var925,&var922};
_S_or2  S_or2_1069_1 = {&var1578,&var1577,&var923};
_S_and2  S_and2_1068_1 = {&var923,&var925,&var924};
_S_or2  S_or2_1055_1 = {&var1589,&var354,&var925};
_S_or2  S_or2_1053_1 = {&B4IS11LDU,&A4IS11LDU,&var926};
_S_and3  S_and3_1052_1 = {&var926,&var1579,&var925,&var927};
_S_and2  S_and2_1067_1 = {&var330,&var925,&var928};
_S_and2  S_and2_1051_1 = {&R3IS21LDU,&var925,&var929};
_S_and2  S_and2_1050_1 = {&var1933,&var925,&var930};
_S_or2  S_or2_1030_1 = {&var1587,&var1997,&var931};
_S_or5  S_or5_1017_1 = {&var664,&var1246,&var438,&var1596,&var1597,&var932};
_S_and2  S_and2_1043_1 = {&var1411,&var934,&var933};
_S_or2  S_or2_1038_1 = {&var935,&A3MD12LP1,&var934};
_S_and2  S_and2_1027_1 = {&A3MD11LP1,&var1460,&var935};
_S_or3  S_or3_988_1 = {&var1685,&var938,&var937,&var936};
_S_and2  S_and2_978_1 = {&var1696,&var1160,&var937};
_S_and2  S_and2_979_1 = {&var1696,&var1210,&var938};
_S_and3  S_and3_977_1 = {&var1719,&var1211,&var950,&var939};
_S_and2  S_and2_976_1 = {&var423,&var950,&var940};
_S_and2  S_and2_954_1 = {&var1689,&var950,&var941};
_S_and2  S_and2_956_1 = {&var330,&var950,&var942};
_S_and2  S_and2_957_1 = {&var944,&var950,&var943};
_S_or2  S_or2_958_1 = {&var1687,&var1686,&var944};
_S_and2  S_and2_938_1 = {&var1933,&var950,&var945};
_S_and3  S_and3_940_1 = {&var1688,&var951,&var950,&var946};
_S_and2  S_and2_939_1 = {&R3IS21LDU,&var950,&var947};
_S_and3  S_and3_953_1 = {&var1461,&var528,&var1212,&var948};
_S_and3  S_and3_952_1 = {&var528,&var1463,&var1212,&var949};
_S_or3  S_or3_943_1 = {&var1697,&var948,&var949,&var950};
_S_or2  S_or2_941_1 = {&B4IS11LDU,&A4IS11LDU,&var951};
_S_or2  S_or2_922_1 = {&var2000,&var1696,&var952};
_S_zpfs  S_zpfs_918_1 = {&var1710,&fRM_3_0,&var953,&internal1_m918_tx,&internal1_m918_y0};
_S_zpfs  S_zpfs_917_1 = {&var1711,&fRM_2_0,&var954,&internal1_m917_tx,&internal1_m917_y0};
_S_zpfs  S_zpfs_935_1 = {&var1708,&fEM_A2UL83RDU,&var955,&internal1_m935_tx,&internal1_m935_y0};
_S_or5  S_or5_914_1 = {&var936,&var955,&var1709,&var954,&var953,&var956};
_S_or3  S_or3_901_1 = {&var1466,&var1489,&var1022,&var957};
_S_or4  S_or4_882_1 = {&var1832,&var1830,&var1831,&var1833,&var958};
_S_or2  S_or2_874_1 = {&var960,&var958,&var959};
_S_or4  S_or4_867_1 = {&var1841,&var1840,&var1839,&var1842,&var960};
_S_and2  S_and2_278_1 = {&var1228,&var1635,&var961};
_S_and3  S_and3_264_1 = {&var1196,&var662,&var1650,&var962};
_S_or3  S_or3_282_1 = {&var964,&var966,&var1638,&var963};
_S_and2  S_and2_268_1 = {&var1649,&var1210,&var964};
_S_and3  S_and3_265_1 = {&var661,&var1420,&var1650,&var965};
_S_and2  S_and2_267_1 = {&var1160,&var1649,&var966};
_S_and2  S_and2_263_1 = {&var423,&var1650,&var967};
_S_and2  S_and2_232_1 = {&var1642,&var1650,&var968};
_S_and2  S_and2_234_1 = {&var330,&var1650,&var969};
_S_or2  S_or2_236_1 = {&var1639,&var1640,&var970};
_S_and2  S_and2_235_1 = {&var970,&var1650,&var971};
_S_or2  S_or2_222_1 = {&B4IS11LDU,&A4IS11LDU,&var972};
_S_and3  S_and3_221_1 = {&var1641,&var972,&var1650,&var973};
_S_and2  S_and2_219_1 = {&var1933,&var1650,&var974};
_S_and2  S_and2_220_1 = {&R3IS21LDU,&var1650,&var975};
_S_and2  S_and2_191_1 = {&var1411,&var978,&var976};
_S_and2  S_and2_184_1 = {&A1MD11LP1,&var1448,&var977};
_S_or2  S_or2_190_1 = {&A1MD12LP1,&var977,&var978};
_S_or2  S_or2_200_1 = {&var1649,&var1985,&var979};
_S_zpfs  S_zpfs_194_1 = {&var1664,&fRM_2_0,&var980,&internal1_m194_tx,&internal1_m194_y0};
_S_zpfs  S_zpfs_193_1 = {&var1663,&fRM_2_0,&var981,&internal1_m193_tx,&internal1_m193_y0};
_S_zpfs  S_zpfs_215_1 = {&var1661,&fEM_A1UL03RDU,&var982,&internal1_m215_tx,&internal1_m215_y0};
_S_or5  S_or5_188_1 = {&var963,&var982,&var981,&var980,&var1662,&var983};
_S_orn  S_orn_612_1 = {array_m612_x_1,&iRM_12_,&var984};
_S_and2  S_and2_641_1 = {&var1605,&var1223,&var985};
_S_or2  S_or2_637_1 = {&var1222,&var985,&var986};
_S_and3  S_and3_627_1 = {&var1211,&var1719,&var1617,&var987};
_S_and2  S_and2_626_1 = {&var423,&var1617,&var988};
_S_and3  S_and3_628_1 = {&var1420,&var1617,&var986,&var989};
_S_or2  S_or2_602_1 = {&var1607,&var1606,&var990};
_S_and2  S_and2_601_1 = {&var990,&var1617,&var991};
_S_and2  S_and2_600_1 = {&var1617,&var330,&var992};
_S_and3  S_and3_587_1 = {&var1608,&var994,&var1617,&var993};
_S_or2  S_or2_588_1 = {&B4IS11LDU,&A4IS11LDU,&var994};
_S_and2  S_and2_598_1 = {&var1617,&var1609,&var995};
_S_or2  S_or2_561_1 = {&B1MD12LP1,&var998,&var996};
_S_and2  S_and2_563_1 = {&var1411,&var996,&var997};
_S_and2  S_and2_555_1 = {&B1MD11LP1,&var1430,&var998};
_S_and2  S_and2_586_1 = {&var1617,&R3IS21LDU,&var999};
_S_and2  S_and2_585_1 = {&var1617,&var1933,&var1000};
_S_or2  S_or2_568_1 = {&var1616,&var2007,&var1001};
_S_zpfs  S_zpfs_584_1 = {&var1630,&fEM_A1UL03RDU,&var1002,&internal1_m584_tx,&internal1_m584_y0};
_S_or5  S_or5_557_1 = {&var1156,&var1002,&var1631,&var1625,&var1626,&var1003};
_S_or2  S_or2_545_1 = {&var1444,&var1023,&var1004};
_S_or3  S_or3_535_1 = {&var844,&var1443,&var1253,&var1005};
_S_or4  S_or4_522_1 = {&var1670,&var1667,&var1669,&var1668,&var1006};
_S_or4  S_or4_503_1 = {&var1678,&var1676,&var1677,&var1679,&var1007};
_S_or2  S_or2_510_1 = {&var1007,&var1006,&var1008};
_S_and3  S_and3_492_1 = {&var1011,&var1411,&R0MD33LP1,&var1009};
_S_and3  S_and3_493_1 = {&var1411,&var1012,&R0MD33LP1,&var1010};
_S_or3  S_or3_483_1 = {&var558,&var1263,&var1249,&var1011};
_S_or2  S_or2_484_1 = {&var1665,&var1442,&var1012};
_S_or2  S_or2_833_1 = {&var1800,&var1801,&var1013};
_S_and2  S_and2_354_1 = {&var1302,&var1364,&var1014};
_S_or2  S_or2_373_1 = {&B4IS21LDU,&A4IS21LDU,&var1015};
_S_or2  S_or2_368_1 = {&A2IS21LDU,&B2IS21LDU,&var1016};
_S_or2  S_or2_363_1 = {&var1019,&var1306,&var1017};
_S_and3  S_and3_361_1 = {&var1365,&var1360,&var1361,&var1018};
_S_or4  S_or4_359_1 = {&var1291,&var468,&R0MD31LP1,&var1301,&var1019};
_S_and4  S_and4_355_1 = {&var1209,&var1077,&var527,&var1167,&var1020};
_S_or2  S_or2_350_1 = {&R0MD34LP1,&var1301,&var1021};
_S_and3  S_and3_672_1 = {&var1044,&var1542,&B2IS12LDU,&var1022};
_S_and2  S_and2_671_1 = {&var1044,&var1574,&var1023};
_S_and2  S_and2_670_1 = {&var1044,&var1637,&var1024};
_S_or2  S_or2_714_1 = {&A2IS12LDU,&B2IS12LDU,&var1025};
_S_or2  S_or2_691_1 = {&var1772,&var1400,&var1026};
_S_and3  S_and3_682_1 = {&A2IS12LDU,&var1542,&var1045,&var1027};
_S_and2  S_and2_713_1 = {&var1029,&var1542,&var1028};
_S_or2  S_or2_715_1 = {&var1343,&var511,&var1029};
_S_or2  S_or2_696_1 = {&var1772,&var1399,&var1030};
_S_or2  S_or2_694_1 = {&var1032,&var1772,&var1031};
_S_and2  S_and2_706_1 = {&var1574,&var522,&var1032};
_S_and2  S_and2_681_1 = {&var1045,&var1574,&var1033};
_S_and2  S_and2_680_1 = {&var1045,&var1637,&var1034};
_S_and2  S_and2_705_1 = {&var516,&var1637,&var1035};
_S_and2  S_and2_721_1 = {&var519,&var1665,&var1036};
_S_or2  S_or2_717_1 = {&var1772,&var1401,&var1037};
_S_or2  S_or2_712_1 = {&var1039,&var1036,&var1038};
_S_and2  S_and2_704_1 = {&var1047,&var1634,&var1039};
_S_and2  S_and2_710_1 = {&var1047,&R0MD33LP1,&var1040};
_S_or2  S_or2_660_1 = {&var1220,&var1221,&var1041};
_S_and4  S_and4_679_1 = {&var1220,&var1045,&var1734,&A2IS12LDU,&var1042};
_S_and4  S_and4_669_1 = {&var1044,&var1221,&var1734,&B2IS12LDU,&var1043};
_S_and2  S_and2_668_1 = {&var1164,&var1732,&var1044};
_S_and2  S_and2_678_1 = {&var1163,&var1732,&var1045};
_S_or2  S_or2_709_1 = {&var1344,&var511,&var1046};
_S_and2  S_and2_702_1 = {&var1046,&var1734,&var1047};
_S_or2  S_or2_689_1 = {&var1772,&var1402,&var1048};
_S_or2  S_or2_701_1 = {&var1712,&var1357,&var1049};
_S_and2  S_and2_700_1 = {&var1049,&var1756,&var1050};
_S_or2  S_or2_686_1 = {&var1772,&var1403,&var1051};
_S_and2  S_and2_699_1 = {&var1773,&var1722,&var1052};
_S_or2  S_or2_684_1 = {&var1772,&var1404,&var1053};
_S_and2  S_and2_697_1 = {&var514,&var1775,&var1054};
_S_or2  S_or2_676_1 = {&var1412,&var1772,&var1055};
_S_and2  S_and2_328_1 = {&var1472,&var1058,&var1056};
_S_and2  S_and2_316_1 = {&var1058,&var1289,&var1057};
_S_or2  S_or2_311_1 = {&var1303,&var1325,&var1058};
_S_and3  S_and3_307_1 = {&var1538,&var1360,&var1361,&var1059};
_S_and3  S_and3_322_1 = {&var1016,&var1290,&var1061,&var1060};
_S_or2  S_or2_312_1 = {&var1538,&var1365,&var1061};
_S_and2  S_and2_321_1 = {&var1015,&var1061,&var1062};
_S_and2  S_and2_342_1 = {&var1067,&var1164,&var1063};
_S_and2  S_and2_343_1 = {&var1163,&var1067,&var1064};
_S_and2  S_and2_348_1 = {&var1258,&var1056,&var1065};
_S_and2  S_and2_336_1 = {&var1067,&var1258,&var1066};
_S_and2  S_and2_341_1 = {&var1440,&var1068,&var1067};
_S_or2  S_or2_337_1 = {&var1069,&var1014,&var1068};
_S_or2  S_or2_338_1 = {&var1070,&var1014,&var1069};
_S_and4  S_and4_339_1 = {&var1366,&var1314,&var1315,&var1161,&var1070};
_S_or2  S_or2_324_1 = {&var1366,&var1364,&var1071};
_S_and2  S_and2_309_1 = {&var1328,&var1297,&var1072};
_S_or2  S_or2_315_1 = {&var1075,&var1072,&var1073};
_S_or2  S_or2_289_1 = {&R0MD34LP1,&var1300,&var1074};
_S_or4  S_or4_306_1 = {&var1291,&R0MD31LP1,&var468,&var1300,&var1075};
_S_and3  S_and3_299_1 = {&var1077,&var1166,&var527,&var1076};
_S_or2  S_or2_298_1 = {&var1319,&var1503,&var1077};
_S_and3  S_and3_301_1 = {&var1320,&var1322,&var1321,&var1078};
_S_or2  S_or2_291_1 = {&var1080,&var1078,&var1079};
_S_and3  S_and3_285_1 = {&R0MD33LP1,&var1324,&var1323,&var1080};
_S_or2  S_or2_1246_1 = {&B4IS11LDU,&A4IS11LDU,&var1081};
_S_and2  S_and2_1249_1 = {&var1723,&var1770,&var1082};
_S_and2  S_and2_1248_1 = {&var1723,&var1878,&var1083};
_S_and2  S_and2_1247_1 = {&var1723,&var1153,&var1084};
_S_and2  S_and2_1245_1 = {&var1723,&var1081,&var1085};
_S_and2  S_and2_1235_1 = {&var1723,&var423,&var1086};
_S_and2  S_and2_1234_1 = {&var1142,&var1723,&var1087};
_S_and2  S_and2_1233_1 = {&var1723,&R3IS21LDU,&var1088};
_S_and2  S_and2_1236_1 = {&var1723,&var1933,&var1089};
_S_and2  S_and2_1206_1 = {&var511,&var1255,&var1090};
_S_and2  S_and2_1207_1 = {&var522,&var1253,&var1091};
_S_and2  S_and2_1208_1 = {&var516,&var1251,&var1092};
_S_and2  S_and2_1209_1 = {&var519,&var1249,&var1093};
_S_or2  S_or2_1191_1 = {&R0MD31LP1,&var1095,&var1094};
_S_and4  S_and4_1192_1 = {&var34,&var38,&var36,&var40,&var1095};
_S_or2  S_or2_1295_1 = {&var1723,&var1988,&var1096};
_S_or2  S_or2_1268_1 = {&var1773,&var1347,&var1097};
_S_or2  S_or2_1342_1 = {&var1814,&var1813,&var1098};
_S_or2  S_or2_1328_1 = {&var1823,&var1822,&var1099};
_S_or2  S_or2_1337_1 = {&var1236,&R0MD34LP1,&var1100};
_S_or2  S_or2_1312_1 = {&var1098,&var1878,&var1101};
_S_or2  S_or2_1310_1 = {&var1103,&var1101,&var1102};
_S_or2  S_or2_1311_1 = {&var1099,&var1878,&var1103};
_S_or4  S_or4_385_1 = {&var1850,&var1849,&var1851,&var1848,&var1104};
_S_or2  S_or2_736_1 = {&B5IS11LDU,&A5IS11LDU,&var1105};
_S_and2  S_and2_735_1 = {&var1110,&var1105,&var1106};
_S_or2  S_or2_734_1 = {&B6IS11LDU,&A6IS11LDU,&var1107};
_S_and2  S_and2_733_1 = {&var1110,&var1107,&var1108};
_S_or2  S_or2_732_1 = {&A4IS11LDU,&B4IS11LDU,&var1109};
_S_or2  S_or2_723_1 = {&var1112,&var1113,&var1110};
_S_and2  S_and2_729_1 = {&var1110,&var1109,&var1111};
_S_and2  S_and2_726_1 = {&var423,&var1123,&var1112};
_S_and2  S_and2_722_1 = {&var424,&var1116,&var1113};
_S_and2  S_and2_853_1 = {&var1876,&var1794,&var1114};
_S_and2  S_and2_849_1 = {&var1876,&var1795,&var1115};
_S_and3  S_and3_844_1 = {&var1876,&var424,&var1801,&var1116};
_S_or2  S_or2_852_1 = {&var1796,&var1790,&var1117};
_S_or2  S_or2_847_1 = {&var1794,&var1796,&var1118};
_S_or2  S_or2_843_1 = {&var1796,&var1795,&var1119};
_S_and2  S_and2_825_1 = {&var1790,&var1876,&var1120};
_S_or2  S_or2_819_1 = {&var1797,&var1798,&var1121};
_S_or2  S_or2_810_1 = {&var1855,&var1797,&var1122};
_S_and2  S_and2_809_1 = {&var1798,&var1877,&var1123};
_S_and2  S_and2_808_1 = {&var1855,&var1877,&var1124};
_S_and2  S_and2_837_1 = {&var514,&var1876,&var1125};
_S_and2  S_and2_817_1 = {&var514,&var1807,&var1126};
_S_and2  S_and2_835_1 = {&var1877,&var514,&var1127};
_S_or2  S_or2_829_1 = {&var1877,&var1876,&var1128};
_S_or3  S_or3_822_1 = {&var334,&var1131,&var1132,&var1129};
_S_or4  S_or4_821_1 = {&var1131,&var333,&var1133,&var1786,&var1130};
_S_or3  S_or3_812_1 = {&R4MD31LP2,&var1120,&var1124,&var1131};
_S_or2  S_or2_841_1 = {&var1875,&var1135,&var1132};
_S_or2  S_or2_840_1 = {&var1875,&var1134,&var1133};
_S_and2  S_and2_747_1 = {&var334,&var1789,&var1134};
_S_and3  S_and3_784_1 = {&var1788,&var1802,&var333,&var1135};
_S_and2  S_and2_789_1 = {&R5IS11LDU,&var1150,&var1136};
_S_and3  S_and3_787_1 = {&var1440,&R3IS21LDU,&var1150,&var1137};
_S_and2  S_and2_788_1 = {&R6IS21LDU,&var1150,&var1138};
_S_or2  S_or2_786_1 = {&B8IS22LDU,&A8IS22LDU,&var1139};
_S_and2  S_and2_785_1 = {&var1139,&var1150,&var1140};
_S_and2  S_and2_768_1 = {&var1150,&var1142,&var1141};
_S_or4  S_or4_769_1 = {&A0VN71LZ1,&B0VN71LZ1,&B0VN71LZ2,&A0VN71LZ2,&var1142};
_S_and2  S_and2_766_1 = {&var1147,&var1150,&var1143};
_S_and2  S_and2_754_1 = {&var1153,&var1150,&var1144};
_S_and2  S_and2_753_1 = {&var1878,&var1150,&var1145};
_S_or3  S_or3_752_1 = {&R0NE01LDU,&R0NE02LDU,&R0NE08LDU,&var1146};
_S_or2  S_or2_767_1 = {&R1IS21LDU,&R2IS21LDU,&var1147};
_S_and2  S_and2_751_1 = {&var1150,&var1146,&var1148};
_S_and2  S_and2_749_1 = {&var1856,&var1150,&var1149};
_S_or2  S_or2_739_1 = {&var1877,&var1876,&var1150};
_S_or2  S_or2_174_1 = {&var1446,&var1033,&var1151};
_S_or3  S_or3_164_1 = {&var843,&var1445,&var1253,&var1152};
_S_or2  S_or2_156_1 = {&var1719,&var662,&var1153};
_S_or3  S_or3_115_1 = {&var1410,&var649,&var650,&var1154};
_S_or2  S_or2_2226_1 = {&var612,&var489,&var1155};
_S_or3  S_or3_644_1 = {&var1157,&var1158,&var984,&var1156};
_S_and2  S_and2_629_1 = {&var1616,&var1160,&var1157};
_S_and2  S_and2_630_1 = {&var1616,&var1210,&var1158};
_S_or2  S_or2_63_1 = {&var1210,&var1160,&var1159};
_S_and2  S_and2_66_1 = {&var1161,&var1293,&var1160};
_S_and2  S_and2_65_1 = {&var1885,&var1294,&var1161};
_S_or2  S_or2_49_1 = {&A4IS21LDU,&B4IS21LDU,&var1162};
_S_or2  S_or2_35_1 = {&var1536,&var1533,&var1163};
_S_or2  S_or2_39_1 = {&var1536,&var1535,&var1164};
_S_or2  S_or2_20_1 = {&var1440,&var1395,&var1165};
_S_or2  S_or2_8_1 = {&var1895,&var1212,&var1166};
_S_or2  S_or2_14_1 = {&var1212,&var1896,&var1167};
_S_and3  S_and3_1113_1 = {&var524,&var1889,&var1187,&var1168};
_S_and3  S_and3_658_1 = {&var1187,&var527,&var1889,&var1169};
_S_and2  S_and2_1180_1 = {&var1233,&var1171,&var1170};
_S_or2  S_or2_1187_1 = {&var1896,&var1895,&var1171};
_S_or2  S_or2_1554_1 = {&var1897,&var1895,&var1172};
_S_and3  S_and3_1553_1 = {&var1231,&var1172,&var910,&var1173};
_S_or2  S_or2_1081_1 = {&var1897,&var1895,&var1174};
_S_and3  S_and3_1080_1 = {&var1231,&var1174,&var925,&var1175};
_S_or2  S_or2_616_1 = {&var1897,&var1895,&var1176};
_S_and3  S_and3_615_1 = {&var1231,&var1176,&var1617,&var1177};
_S_and2  S_and2_613_1 = {&var419,&var1617,&var1178};
_S_or2  S_or2_250_1 = {&var1897,&var1895,&var1179};
_S_and3  S_and3_249_1 = {&var1231,&var1179,&var1650,&var1180};
_S_and2  S_and2_247_1 = {&var1650,&var420,&var1181};
_S_and3  S_and3_970_1 = {&var1231,&var1184,&var950,&var1182};
_S_and2  S_and2_969_1 = {&var745,&var950,&var1183};
_S_or2  S_or2_971_1 = {&var1897,&var1895,&var1184};
_S_or2  S_or2_1449_1 = {&var1897,&var1895,&var1185};
_S_or2  S_or2_6_1 = {&var1896,&var1895,&var1186};
_S_or3  S_or3_5_1 = {&var1897,&var1896,&var1895,&var1187};
_S_or2  S_or2_828_1 = {&var1797,&var1799,&var1188};
_S_or2  S_or2_479_1 = {&var1878,&var1193,&var1189};
_S_or2  S_or2_457_1 = {&var1878,&var1194,&var1190};
_S_or4  S_or4_458_1 = {&var1190,&var1806,&var1805,&var1189,&var1191};
_S_and2  S_and2_449_1 = {&A8IS22LDU,&var1870,&var1192};
_S_or3  S_or3_429_1 = {&var1860,&var1858,&var1859,&var1193};
_S_or3  S_or3_413_1 = {&var1868,&var1867,&var1869,&var1194};
_S_and2  S_and2_815_1 = {&var1877,&var1799,&var1195};
_S_and2  S_and2_38_1 = {&var1533,&var1534,&var1196};
_S_and2  S_and2_150_1 = {&var1809,&var1433,&var1197};
_S_and2  S_and2_158_1 = {&var1811,&var1433,&var1198};
_S_and2  S_and2_161_1 = {&var1808,&var1433,&var1199};
_S_and2  S_and2_153_1 = {&var1433,&var1810,&var1200};
_S_and2  S_and2_475_1 = {&var1153,&var1862,&var1201};
_S_and2  S_and2_473_1 = {&B8IS22LDU,&var1862,&var1202};
_S_and2  S_and2_471_1 = {&A8IS22LDU,&var1862,&var1203};
_S_and2  S_and2_469_1 = {&R5IS11LDU,&var1862,&var1204};
_S_and2  S_and2_460_1 = {&var1804,&var1870,&var1205};
_S_and2  S_and2_448_1 = {&R5IS11LDU,&var1870,&var1206};
_S_and2  S_and2_452_1 = {&var1153,&var1870,&var1207};
_S_and2  S_and2_119_1 = {&var1212,&var648,&var1208};
_S_and2  S_and2_61_1 = {&var1886,&var1294,&var1209};
_S_and2  S_and2_62_1 = {&var1209,&var1292,&var1210};
_S_and2  S_and2_42_1 = {&var1534,&var1535,&var1211};
_S_and2  S_and2_11_1 = {&var1894,&var1526,&var1212};
_S_and2  S_and2_31_1 = {&var1457,&var513,&var1213};
_S_and2  S_and2_30_1 = {&var1353,&var1440,&var1214};
_S_and2  S_and2_29_1 = {&var1354,&var1440,&var1215};
_S_and2  S_and2_28_1 = {&var1355,&var1440,&var1216};
_S_and2  S_and2_27_1 = {&var1356,&var1440,&var1217};
_S_and2  S_and2_842_1 = {&var1793,&var1801,&var1218};
_S_and2  S_and2_824_1 = {&var1800,&var1877,&var1219};
_S_bol  S_bol_659_1 = {&var2002,&fRM_20_0,&var1220};
_S_bol  S_bol_653_1 = {&var1999,&fRM_20_0,&var1221};
_S_bol  S_bol_646_1 = {&var1999,&fRM_20_03,&var1222};
_S_bol  S_bol_640_1 = {&var2002,&fRM_20_03,&var1223};
_S_bol  S_bol_1100_1 = {&var1999,&fRM_20_03,&var1224};
_S_bol  S_bol_1107_1 = {&var2002,&fRM_20_03,&var1225};
_S_bol  S_bol_1576_1 = {&var2002,&fRM_20_03,&var1226};
_S_bol  S_bol_1578_1 = {&var1999,&fRM_20_03,&var1227};
_S_bol  S_bol_277_1 = {&var1999,&fRM_20_03,&var1228};
_S_bol  S_bol_281_1 = {&var2002,&fRM_20_03,&var1229};
_S_sr  S_sr_88_1 = {array_m88_x_1,&iRM_2_,&var1230};
_S_bol  S_bol_87_1 = {&var1230,&var467,&var1231};
_S_ma  S_ma_90_1 = {array_m90_x_1,&R0MW15IP1,&iRM_8_,&var1232};
_S_bol  S_bol_1181_1 = {&var1234,&fEM_R0UN80RDU,&var1233};
_S_sr  S_sr_1188_1 = {array_m1188_x_1,&iRM_2_,&var1234};
_S_ovbs  S_ovbs_2316_1 = {&lRM_1_,&fEM_A9UZ04RDU,&var1235,&internal1_m2316_tx};
_S_ovbs  S_ovbs_1336_1 = {&lRM_1_,&fEM_A4UZ04RDU,&var1236,&internal1_m1336_tx};
_S_zpfs  S_zpfs_1828_1 = {&var1764,&fEM_B8UL03RDU,&var1237,&internal1_m1828_tx,&internal1_m1828_y0};
_S_zpfs  S_zpfs_1303_1 = {&var1781,&fEM_B8UL03RDU,&var1238,&internal1_m1303_tx,&internal1_m1303_y0};
_S_ma  S_ma_1365_1 = {array_m1365_x_1,&var1733,&iRM_8_,&var1239};
_S_ma  S_ma_903_1 = {array_m903_x_1,&var1693,&iRM_8_,&var1240};
_S_ma  S_ma_1000_1 = {array_m1000_x_1,&var1584,&iRM_8_,&var1241};
_S_ma  S_ma_1478_1 = {array_m1478_x_1,&var1552,&iRM_8_,&var1242};
_S_ma  S_ma_544_1 = {array_m544_x_1,&var1613,&iRM_8_,&var1243};
_S_ma  S_ma_173_1 = {array_m173_x_1,&var1646,&iRM_8_,&var1244};
_S_zpfs  S_zpfs_1521_1 = {&var1569,&fEM_A3UL03RDU,&var1245,&internal1_m1521_tx,&internal1_m1521_y0};
_S_zpfs  S_zpfs_1048_1 = {&var1601,&fEM_A3UL03RDU,&var1246,&internal1_m1048_tx,&internal1_m1048_y0};
_S_zpfs  S_zpfs_1411_1 = {&var1751,&fEM_A2UL03RDU,&var1247,&internal1_m1411_tx,&internal1_m1411_y0};
_S_rs  S_rs_1205_1 = {&var1094,&var1093,&var1248,&vainSBool,&internal1_m1205_q0};
_S_rs  S_rs_1203_1 = {&var34,&var1256,&var1249,&vainSBool,&internal1_m1203_q0};
_S_rs  S_rs_1202_1 = {&var1094,&var1092,&var1250,&vainSBool,&internal1_m1202_q0};
_S_rs  S_rs_1200_1 = {&var36,&var1256,&var1251,&vainSBool,&internal1_m1200_q0};
_S_rs  S_rs_1199_1 = {&var1094,&var1091,&var1252,&vainSBool,&internal1_m1199_q0};
_S_rs  S_rs_1197_1 = {&var38,&var1256,&var1253,&vainSBool,&internal1_m1197_q0};
_S_rs  S_rs_1196_1 = {&var1094,&var1090,&var1254,&vainSBool,&internal1_m1196_q0};
_S_rs  S_rs_1194_1 = {&var40,&var1256,&var1255,&vainSBool,&internal1_m1194_q0};
_S_rs  S_rs_1193_1 = {&var1094,&var468,&var1256,&vainSBool,&internal1_m1193_q0};
_S_noto  S_noto_2136_1 = {&var713,&var1257};
_S_swtakt  S_swtakt_54_1 = {&var42,&var1258,&fEM_R0UL00RDU,&var1259,&internal1_m54_x0,&internal1_m54_tim};
_S_noto  S_noto_1179_1 = {&var1274,&var1260};
_S_noto  S_noto_1153_1 = {&var1272,&var1261};
_S_noto  S_noto_1165_1 = {&var1273,&var1262};
_S_rs  S_rs_1112_1 = {&var1275,&var851,&var1263,&vainSBool,&internal1_m1112_q0};
_S_swtakt  S_swtakt_1633_1 = {&var1388,&var1264,&fEM_R0UL00RDU,&var1265,&internal1_m1633_x0,&internal1_m1633_tim};
_S_swtakt  S_swtakt_1681_1 = {&var1391,&var1266,&fEM_R0UL00RDU,&var1267,&internal1_m1681_x0,&internal1_m1681_tim};
_S_swtakt  S_swtakt_1684_1 = {&var1529,&var1268,&fEM_R0UL00RDU,&var1269,&internal1_m1684_x0,&internal1_m1684_tim};
_S_swtakt  S_swtakt_2068_1 = {&var1381,&var1270,&fEM_R0UL00RDU,&var1271,&internal1_m2068_x0,&internal1_m2068_tim};
_S_rs  S_rs_1152_1 = {&var1346,&var839,&var1272,&vainSBool,&internal1_m1152_q0};
_S_rs  S_rs_1158_1 = {&var1346,&var840,&var1273,&vainSBool,&internal1_m1158_q0};
_S_rs  S_rs_1176_1 = {&var1346,&var841,&var1274,&vainSBool,&internal1_m1176_q0};
_S_rs  S_rs_1186_1 = {&var1346,&var842,&var1275,&vainSBool,&internal1_m1186_q0};
_S_noto  S_noto_1138_1 = {&var857,&var1276};
_S_noto  S_noto_1166_1 = {&var857,&var1277};
_S_noto  S_noto_1171_1 = {&var861,&var1278};
_S_rs  S_rs_1164_1 = {&var835,&var837,&var1279,&vainSBool,&internal1_m1164_q0};
_S_rs  S_rs_1178_1 = {&var1346,&var833,&var1280,&vainSBool,&internal1_m1178_q0};
_S_bol  S_bol_1161_1 = {&var1987,&var574,&var1281};
_S_bol  S_bol_1160_1 = {&var1990,&var574,&var1282};
_S_noto  S_noto_1119_1 = {&var1341,&var1283};
_S_bol  S_bol_1157_1 = {&var574,&var1987,&var1284};
_S_bol  S_bol_1156_1 = {&var574,&var1990,&var1285};
_S_noto  S_noto_1143_1 = {&var1342,&var1286};
_S_rs  S_rs_2154_1 = {&var718,&var709,&var1287,&vainSBool,&internal1_m2154_q0};
_S_rs  S_rs_2153_1 = {&var718,&var710,&var1288,&vainSBool,&internal1_m2153_q0};
_S_noto  S_noto_349_1 = {&var1065,&var1289};
_S_noto  S_noto_330_1 = {&var1058,&var1290};
_S_noto  S_noto_300_1 = {&var1077,&var1291};
_S_noto  S_noto_59_1 = {&var1303,&var1292};
_S_noto  S_noto_70_1 = {&var1325,&var1293};
_S_noto  S_noto_69_1 = {&var1256,&var1294};
_S_noto  S_noto_2148_1 = {&B2IS11LDU,&var1295};
_S_noto  S_noto_2146_1 = {&A2IS11LDU,&var1296};
_S_noto  S_noto_308_1 = {&var527,&var1297};
_S_noto  S_noto_2155_1 = {&B2IS11LDU,&var1298};
_S_noto  S_noto_2130_1 = {&A2IS11LDU,&var1299};
_S_noto  S_noto_295_1 = {&var1161,&var1300};
_S_noto  S_noto_353_1 = {&var1209,&var1301};
_S_bolz  S_bolz_357_1 = {&iRM_2_,&var1304,&var1302};
_S_provsbr  S_provsbr_352_1 = {&var1364,&var1021,&var1379,&var1396,&var1390,&var1385,&var1382,&var1380,&var1394,&var1389,&var1387,&var1383,&iRM_10_,array_m352_Tpr_1,array_m352_type_1,&var1303,&var1304,&var1305,&var1306,&var1307,&var1308,&var1309,&var1310,&var1311,&vainSBool,&internal1_m352_Step,array_m352_rz_1,&internal1_m352_TimS,&internal1_m352_FinPr0,&internal1_m352_ErrPr0,&internal1_m352_sbINI0,&internal1_m352_sbVuIS0,&internal1_m352_sb2UR0,&internal1_m352_sbNupIS0,&internal1_m352_sbVuRB0,&internal1_m352_MyFirstEnterFlag};
_S_orni  S_orni_356_1 = {array_m356_x_1,&iRM_5_,&vainSBool,&var1312};
_S_cntch  S_cntch_360_1 = {&var1312,&var1313,&internal1_m360_x0};
_S_bolz  S_bolz_334_1 = {&iRM_20_,&var1327,&var1314};
_S_equz_p  S_equz_p_333_1 = {&var1326,&iRM_0_,&var1315};
_S_decatron  S_decatron_319_1 = {&var1057,&var1316,&internal1_m319_TimS,&internal1_m319_pusk0};
_S_noto  S_noto_1116_1 = {&R2IS21LDU,&var1317};
_S_noto  S_noto_1110_1 = {&R1IS21LDU,&var1318};
_S_andn  S_andn_290_1 = {array_m290_x_1,&iRM_7_,&var1319};
_S_noto  S_noto_292_1 = {&R0MD33LP1,&var1320};
_S_noto  S_noto_302_1 = {&R2IS21LDU,&var1321};
_S_noto  S_noto_296_1 = {&R1IS21LDU,&var1322};
_S_noto  S_noto_287_1 = {&R1IS11LDU,&var1323};
_S_noto  S_noto_284_1 = {&R2IS11LDU,&var1324};
_S_provsbr  S_provsbr_294_1 = {&var1366,&var1074,&var1379,&var1396,&var1390,&var1385,&var1382,&var1380,&var1394,&var1389,&var1387,&var1383,&iRM_10_,array_m294_Tpr_1,array_m294_type_1,&var1325,&var1326,&var1327,&var1328,&var1329,&var1330,&var1331,&var1332,&var1333,&vainSBool,&internal1_m294_Step,array_m294_rz_1,&internal1_m294_TimS,&internal1_m294_FinPr0,&internal1_m294_ErrPr0,&internal1_m294_sbINI0,&internal1_m294_sbVuIS0,&internal1_m294_sb2UR0,&internal1_m294_sbNupIS0,&internal1_m294_sbVuRB0,&internal1_m294_MyFirstEnterFlag};
_S_rs  S_rs_1595_1 = {&var1335,&var832,&var1334,&vainSBool,&internal1_m1595_q0};
_S_provsbr  S_provsbr_1596_1 = {&var1334,&R0MD34LP1,&var1379,&var1396,&var1390,&var1385,&var1382,&var1380,&var1394,&var1389,&var1387,&var1383,&iRM_6_,array_m1596_Tpr_1,array_m1596_type_1,&var1335,&vainSInt,&vainSInt,&vainSBool,&var1336,&var1337,&var1338,&var1339,&var1340,&vainSBool,&internal1_m1596_Step,array_m1596_rz_1,&internal1_m1596_TimS,&internal1_m1596_FinPr0,&internal1_m1596_ErrPr0,&internal1_m1596_sbINI0,&internal1_m1596_sbVuIS0,&internal1_m1596_sb2UR0,&internal1_m1596_sbNupIS0,&internal1_m1596_sbVuRB0,&internal1_m1596_MyFirstEnterFlag};
_S_abs_subf  S_abs_subf_1122_1 = {&var574,&var1990,&fEM_B8UC01RDU,&vainSFloat,&var1341};
_S_abs_subf  S_abs_subf_1135_1 = {&var1987,&var574,&fEM_B8UC01RDU,&vainSFloat,&var1342};
_S_noto  S_noto_718_1 = {&var1025,&var1343};
_S_noto  S_noto_666_1 = {&var1041,&var1344};
_S_noto  S_noto_50_1 = {&var570,&var1345};
_S_noto  S_noto_1139_1 = {&var1541,&var1346};
_S_rs  S_rs_1148_1 = {&var834,&var663,&var1347,&vainSBool,&internal1_m1148_q0};
_S_rs  S_rs_1145_1 = {&var838,&var833,&var1348,&vainSBool,&internal1_m1145_q0};
_S_rs  S_rs_1147_1 = {&var1346,&var663,&var1349,&vainSBool,&internal1_m1147_q0};
_S_rs  S_rs_1141_1 = {&var1346,&var836,&var1350,&vainSBool,&internal1_m1141_q0};
_S_noto  S_noto_655_1 = {&A2IS21LDU,&var1351};
_S_noto  S_noto_657_1 = {&B2IS21LDU,&var1352};
_S_noto  S_noto_25_1 = {&B2IS21LDU,&var1353};
_S_noto  S_noto_24_1 = {&B1IS21LDU,&var1354};
_S_noto  S_noto_23_1 = {&A1IS21LDU,&var1355};
_S_noto  S_noto_22_1 = {&A2IS21LDU,&var1356};
_S_newstage  S_newstage_667_1 = {&var396,&var393,&A2IS12LDU,&B2IS12LDU,&var1357};
_S_noto  S_noto_656_1 = {&B2IS12LDU,&var1358};
_S_noto  S_noto_654_1 = {&A2IS12LDU,&var1359};
_S_noto  S_noto_366_1 = {&var1016,&var1360};
_S_noto  S_noto_370_1 = {&var1015,&var1361};
_S_noto  S_noto_1109_1 = {&var1153,&var1362};
_S_rs  S_rs_832_1 = {&var1013,&var646,&var1363,&vainSBool,&internal1_m832_q0};
_S_rs  S_rs_362_1 = {&var1017,&var1018,&var1364,&vainSBool,&internal1_m362_q0};
_S_rs  S_rs_358_1 = {&var1019,&var1020,&var1365,&vainSBool,&internal1_m358_q0};
_S_rs  S_rs_314_1 = {&var1073,&var1059,&var1366,&vainSBool,&internal1_m314_q0};
_S_orni  S_orni_310_1 = {array_m310_x_1,&iRM_5_,&vainSBool,&var1367};
_S_cntch  S_cntch_313_1 = {&var1367,&var1368,&internal1_m313_x0};
_S_noto  S_noto_1646_1 = {&var1387,&var1369};
_S_noto  S_noto_1705_1 = {&var1389,&var1370};
_S_noto  S_noto_1707_1 = {&var1394,&var1371};
_S_noto  S_noto_2080_1 = {&var1380,&var1372};
_S_noto  S_noto_2112_1 = {&var1383,&var1373};
_S_noto  S_noto_2092_1 = {&var1384,&var1374};
_S_noto  S_noto_2065_1 = {&var1381,&var1375};
_S_noto  S_noto_1676_1 = {&var1529,&var1376};
_S_noto  S_noto_1668_1 = {&var1391,&var1377};
_S_noto  S_noto_1628_1 = {&var1388,&var1378};
_S_rs  S_rs_2083_1 = {&var818,&var667,&var1379,&vainSBool,&internal1_m2083_q0};
_S_rs  S_rs_2076_1 = {&var673,&var670,&var1380,&vainSBool,&internal1_m2076_q0};
_S_rs  S_rs_2071_1 = {&var669,&var674,&var1381,&vainSBool,&internal1_m2071_q0};
_S_rs  S_rs_2137_1 = {&var818,&var687,&var1382,&vainSBool,&internal1_m2137_q0};
_S_rs  S_rs_2108_1 = {&var695,&var694,&var1383,&vainSBool,&internal1_m2108_q0};
_S_rs  S_rs_2096_1 = {&var697,&var700,&var1384,&vainSBool,&internal1_m2096_q0};
_S_rs  S_rs_1660_1 = {&var818,&var804,&var1385,&vainSBool,&internal1_m1660_q0};
_S_kvf  S_kvf_1647_1 = {&var1265,&var805,&fRM_0_0,&var1386,&vainSInt,&vainSInt,&internal1_m1647_x0,&internal1_m1647_y0,&internal1_m1647_fef};
_S_rs  S_rs_1642_1 = {&var810,&var805,&var1387,&vainSBool,&internal1_m1642_q0};
_S_rs  S_rs_1632_1 = {&var807,&var811,&var1388,&vainSBool,&internal1_m1632_q0};
_S_rs  S_rs_1695_1 = {&var800,&var795,&var1389,&vainSBool,&internal1_m1695_q0};
_S_rs  S_rs_1716_1 = {&var818,&var801,&var1390,&vainSBool,&internal1_m1716_q0};
_S_rs  S_rs_1680_1 = {&var798,&var799,&var1391,&vainSBool,&internal1_m1680_q0};
_S_kvf  S_kvf_1696_1 = {&var47,&var795,&fRM_0_0,&var1392,&vainSInt,&vainSInt,&internal1_m1696_x0,&internal1_m1696_y0,&internal1_m1696_fef};
_S_cntch  S_cntch_1613_1 = {&var820,&var1393,&internal1_m1613_x0};
_S_rs  S_rs_1702_1 = {&var792,&var786,&var1394,&vainSBool,&internal1_m1702_q0};
_S_rs  S_rs_26_1 = {&var1440,&var1213,&var1395,&vainSBool,&internal1_m26_q0};
_S_rs  S_rs_1717_1 = {&var818,&var785,&var1396,&vainSBool,&internal1_m1717_q0};
_S_noto  S_noto_1584_1 = {&var814,&var1397};
_S_noto  S_noto_1582_1 = {&var1212,&var1398};
_S_rs  S_rs_707_1 = {&var1772,&var1028,&var1399,&vainSBool,&internal1_m707_q0};
_S_rs  S_rs_692_1 = {&var1772,&var1035,&var1400,&vainSBool,&internal1_m692_q0};
_S_rs  S_rs_719_1 = {&var1772,&var1036,&var1401,&vainSBool,&internal1_m719_q0};
_S_rs  S_rs_703_1 = {&var1772,&var1047,&var1402,&vainSBool,&internal1_m703_q0};
_S_rs  S_rs_687_1 = {&var1772,&var1050,&var1403,&vainSBool,&internal1_m687_q0};
_S_rs  S_rs_685_1 = {&var1772,&var1052,&var1404,&vainSBool,&internal1_m685_q0};
_S_rs  S_rs_673_1 = {&var1055,&var1775,&var1405,&vainSBool,&internal1_m673_q0};
_S_rsun  S_rsun_1598_1 = {&var818,&var1525,&vainSLong,&var1406,&internal1_m1598_q0};
_S_noto  S_noto_1506_1 = {&B3MD12LP1,&var1407};
_S_noto  S_noto_2039_1 = {&B3IS11LDU,&var1408};
_S_noto  S_noto_2013_1 = {&A3IS11LDU,&var1409};
_S_noto  S_noto_118_1 = {&var1212,&var1410};
_S_noto  S_noto_117_1 = {&var1415,&var1411};
_S_rs  S_rs_683_1 = {&var1772,&var1054,&var1412,&vainSBool,&internal1_m683_q0};
_S_orni  S_orni_1340_1 = {array_m1340_x_1,&iRM_5_,&var1413,&vainSLong};
_S_orni  S_orni_1324_1 = {array_m1324_x_1,&iRM_4_,&var1414,&vainSLong};
_S_rs  S_rs_116_1 = {&var1154,&var1208,&var1415,&vainSBool,&internal1_m116_q0};
_S_noto  S_noto_2042_1 = {&var736,&var1416};
_S_noto  S_noto_2041_1 = {&var735,&var1417};
_S_noto  S_noto_2053_1 = {&B3IS22LDU,&var1418};
_S_noto  S_noto_2034_1 = {&A3IS22LDU,&var1419};
_S_newstage  S_newstage_2037_1 = {&var752,&var748,&var751,&var747,&vainSBool};
_S_noto  S_noto_1981_1 = {&var1503,&var1420};
_S_rs  S_rs_1863_1 = {&var310,&var538,&var1421,&vainSBool,&internal1_m1863_q0};
_S_rs  S_rs_1862_1 = {&var303,&var540,&var1422,&vainSBool,&internal1_m1862_q0};
_S_rs  S_rs_1861_1 = {&var309,&var542,&var1423,&vainSBool,&internal1_m1861_q0};
_S_rs  S_rs_1860_1 = {&var285,&var544,&var1424,&vainSBool,&internal1_m1860_q0};
_S_rs  S_rs_1896_1 = {&var513,&var546,&var1425,&vainSBool,&internal1_m1896_q0};
_S_rs  S_rs_1895_1 = {&var321,&var549,&var1426,&vainSBool,&internal1_m1895_q0};
_S_rs  S_rs_1894_1 = {&var322,&var549,&var1427,&vainSBool,&internal1_m1894_q0};
_S_noto  S_noto_1393_1 = {&A2MD12LP1,&var1428};
_S_noto  S_noto_1376_1 = {&B2MD12LP1,&var1429};
_S_noto  S_noto_559_1 = {&B1MD12LP1,&var1430};
_S_ma  S_ma_1649_1 = {array_m1649_x_1,&var1406,&iRM_16_,&var1431};
_S_noto  S_noto_1592_1 = {&var1069,&var1432};
_S_noto  S_noto_148_1 = {&var1212,&var1433};
_S_equz_p  S_equz_p_2019_1 = {&R0MW14IP2,&iRM_5_,&var1434};
_S_equz_p  S_equz_p_2018_1 = {&R0MW14IP2,&iRM_4_,&var1435};
_S_equz_p  S_equz_p_2017_1 = {&R0MW14IP2,&iRM_3_,&var1436};
_S_equz_p  S_equz_p_2015_1 = {&R0MW14IP2,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_2016_1 = {&R0MW14IP2,&iRM_2_,&var1437};
_S_noto  S_noto_2101_1 = {&B2IS11LDU,&var1438};
_S_noto  S_noto_2109_1 = {&A2IS11LDU,&var1439};
_S_noto  S_noto_12_1 = {&var1894,&var1440};
_S_rs  S_rs_2168_1 = {&var632,&var722,&var1441,&vainSBool,&internal1_m2168_q0};
_S_rs  S_rs_1956_1 = {&var764,&var559,&var1442,&vainSBool,&internal1_m1956_q0};
_S_rs  S_rs_1945_1 = {&var306,&var560,&var1443,&vainSBool,&internal1_m1945_q0};
_S_rs  S_rs_1953_1 = {&var323,&var561,&var1444,&vainSBool,&internal1_m1953_q0};
_S_rs  S_rs_1942_1 = {&var307,&var562,&var1445,&vainSBool,&internal1_m1942_q0};
_S_rs  S_rs_1950_1 = {&var327,&var563,&var1446,&vainSBool,&internal1_m1950_q0};
_S_equz_p  S_equz_p_105_1 = {&R0MW16IP1,&iRM_10_,&var1447};
_S_noto  S_noto_186_1 = {&A1MD12LP1,&var1448};
_S_rs  S_rs_2384_1 = {&var297,&var294,&var1449,&vainSBool,&internal1_m2384_q0};
_S_rs  S_rs_2380_1 = {&var313,&var385,&var1450,&vainSBool,&internal1_m2380_q0};
_S_rs  S_rs_1921_1 = {&var326,&var556,&var1451,&vainSBool,&internal1_m1921_q0};
_S_rs  S_rs_1913_1 = {&var513,&var545,&var1452,&vainSBool,&internal1_m1913_q0};
_S_rs  S_rs_1911_1 = {&var308,&var546,&var1453,&vainSBool,&internal1_m1911_q0};
_S_rs  S_rs_1907_1 = {&var321,&var547,&var1454,&vainSBool,&internal1_m1907_q0};
_S_rs  S_rs_1903_1 = {&var283,&var549,&var1455,&vainSBool,&internal1_m1903_q0};
_S_rs  S_rs_1905_1 = {&var322,&var548,&var1456,&vainSBool,&internal1_m1905_q0};
_S_rs  S_rs_19_1 = {&var1165,&var652,&var1457,&vainSBool,&internal1_m19_q0};
_S_equz_p  S_equz_p_104_1 = {&R0MW16IP1,&iRM_9_,&var1458};
_S_equz_p  S_equz_p_103_1 = {&R0MW16IP1,&iRM_8_,&var1459};
_S_noto  S_noto_1034_1 = {&A3MD12LP1,&var1460};
_S_equz_p  S_equz_p_102_1 = {&R0MW16IP1,&iRM_7_,&var1461};
_S_equz_p  S_equz_p_101_1 = {&R0MW16IP1,&iRM_6_,&var1462};
_S_equz_p  S_equz_p_100_1 = {&R0MW16IP1,&iRM_5_,&var1463};
_S_rs  S_rs_1886_1 = {&var310,&var537,&var1464,&vainSBool,&internal1_m1886_q0};
_S_rs  S_rs_1884_1 = {&var302,&var538,&var1465,&vainSBool,&internal1_m1884_q0};
_S_rs  S_rs_1880_1 = {&var320,&var540,&var1466,&vainSBool,&internal1_m1880_q0};
_S_rs  S_rs_1882_1 = {&var303,&var539,&var1467,&vainSBool,&internal1_m1882_q0};
_S_rs  S_rs_1878_1 = {&var309,&var541,&var1468,&vainSBool,&internal1_m1878_q0};
_S_rs  S_rs_1876_1 = {&var286,&var542,&var1469,&vainSBool,&internal1_m1876_q0};
_S_rs  S_rs_2293_1 = {&var400,&var731,&var1470,&vainSBool,&internal1_m2293_q0};
_S_rs  S_rs_2288_1 = {&var401,&var732,&var1471,&vainSBool,&internal1_m2288_q0};
_S_equz_p  S_equz_p_323_1 = {&var1316,&iRM_0_,&var1472};
_S_noto  S_noto_2294_1 = {&var1470,&var1473};
_S_noto  S_noto_2283_1 = {&var656,&var1474};
_S_noto  S_noto_2266_1 = {&var1476,&var1475};
_S_rs  S_rs_2265_1 = {&var340,&var728,&var1476,&vainSBool,&internal1_m2265_q0};
_S_noto  S_noto_2250_1 = {&var1478,&var1477};
_S_rs  S_rs_2249_1 = {&var342,&var725,&var1478,&vainSBool,&internal1_m2249_q0};
_S_noto  S_noto_2289_1 = {&var1471,&var1479};
_S_noto  S_noto_2281_1 = {&var655,&var1480};
_S_noto  S_noto_2181_1 = {&var1482,&var1481};
_S_rs  S_rs_2180_1 = {&var631,&var723,&var1482,&vainSBool,&internal1_m2180_q0};
_S_noto  S_noto_2169_1 = {&var1441,&var1483};
_S_noto  S_noto_2176_1 = {&var653,&var1484};
_S_noto  S_noto_2163_1 = {&var654,&var1485};
_S_rs  S_rs_1872_1 = {&var319,&var544,&var1486,&vainSBool,&internal1_m1872_q0};
_S_rs  S_rs_1874_1 = {&var285,&var543,&var1487,&vainSBool,&internal1_m1874_q0};
_S_rs  S_rs_1858_1 = {&var300,&var529,&var1488,&vainSBool,&internal1_m1858_q0};
_S_rs  S_rs_1856_1 = {&var318,&var530,&var1489,&vainSBool,&internal1_m1856_q0};
_S_rs  S_rs_1854_1 = {&var299,&var531,&var1490,&vainSBool,&internal1_m1854_q0};
_S_rs  S_rs_1852_1 = {&var317,&var532,&var1491,&vainSBool,&internal1_m1852_q0};
_S_noto  S_noto_1976_1 = {&B3IS22LDU,&var1492};
_S_noto  S_noto_1975_1 = {&A3IS22LDU,&var1493};
_S_noto  S_noto_1974_1 = {&B2IS12LDU,&var1494};
_S_noto  S_noto_1973_1 = {&A2IS12LDU,&var1495};
_S_noto  S_noto_1972_1 = {&B1IS12LDU,&var1496};
_S_noto  S_noto_1971_1 = {&A1IS12LDU,&var1497};
_S_noto  S_noto_2001_1 = {&B3IS21LDU,&var1498};
_S_noto  S_noto_1995_1 = {&B2IS21LDU,&var1499};
_S_noto  S_noto_2000_1 = {&A3IS21LDU,&var1500};
_S_noto  S_noto_1998_1 = {&B4IS21LDU,&var1501};
_S_noto  S_noto_1999_1 = {&A4IS21LDU,&var1502};
_S_andn  S_andn_1984_1 = {array_m1984_x_1,&iRM_17_,&var1503};
_S_noto  S_noto_1993_1 = {&B1IS21LDU,&var1504};
_S_noto  S_noto_1994_1 = {&A2IS21LDU,&var1505};
_S_noto  S_noto_1992_1 = {&A1IS21LDU,&var1506};
_S_rs  S_rs_1851_1 = {&var1511,&var533,&var1507,&vainSBool,&internal1_m1851_q0};
_S_rs  S_rs_1849_1 = {&var301,&var534,&var1508,&vainSBool,&internal1_m1849_q0};
_S_rs  S_rs_1848_1 = {&var1511,&var535,&var1509,&vainSBool,&internal1_m1848_q0};
_S_rs  S_rs_1846_1 = {&var284,&var536,&var1510,&vainSBool,&internal1_m1846_q0};
_S_newstage  S_newstage_2319_1 = {&var1523,&var1517,&var1522,&var1516,&var1511};
_S_samhd  S_samhd_2321_1 = {&var776,&var777,&var777,&var1508,&var1507,&var1508,&var1507,&B9IS11LDU,&B9IS11LDU,&B9IS21LDU,&B9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1512,&var1513,&var1514,&vainSBool,&var1515,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1516,&var1517,&internal1_m2321_DvUp0,&internal1_m2321_DvDw0,&internal1_m2321_FDvUp0,&internal1_m2321_FDvDw0,&internal1_m2321_BlDv0,&internal1_m2321_Pkv0,&internal1_m2321_Pkav0,&internal1_m2321_Zkv0,&internal1_m2321_Zkav0,&internal1_m2321_txNm,&internal1_m2321_txSm,&internal1_m2321_txHr,&internal1_m2321_txLd,&internal1_m2321_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_2315_1 = {&var776,&var778,&var778,&var1510,&var1509,&var1510,&var1509,&A9IS11LDU,&A9IS11LDU,&A9IS21LDU,&A9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1518,&var1519,&var1520,&vainSBool,&var1521,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1522,&var1523,&internal1_m2315_DvUp0,&internal1_m2315_DvDw0,&internal1_m2315_FDvUp0,&internal1_m2315_FDvDw0,&internal1_m2315_BlDv0,&internal1_m2315_Pkv0,&internal1_m2315_Pkav0,&internal1_m2315_Zkv0,&internal1_m2315_Zkav0,&internal1_m2315_txNm,&internal1_m2315_txSm,&internal1_m2315_txHr,&internal1_m2315_txLd,&internal1_m2315_fef,&bFirstEnterFlag};
_S_orni  S_orni_1600_1 = {array_m1600_x_1,&iRM_5_,&var1524,&var1525};
_S_noto  S_noto_83_1 = {&var657,&var1526};
_S_maz  S_maz_329_1 = {array_m329_x_1,&R0MW12IP1,&iRM_3_,&var1527};
_S_maz  S_maz_320_1 = {array_m320_x_1,&R0MW12IP1,&iRM_3_,&var1528};
_S_rs  S_rs_1675_1 = {&var789,&var793,&var1529,&vainSBool,&internal1_m1675_q0};
_S_kvf  S_kvf_1697_1 = {&var1268,&var786,&fRM_0_0,&var1530,&vainSInt,&vainSInt,&internal1_m1697_x0,&internal1_m1697_y0,&internal1_m1697_fef};
_S_kvf  S_kvf_2119_1 = {&var703,&var691,&fRM_0_0,&var1531,&vainSInt,&vainSInt,&internal1_m2119_x0,&internal1_m2119_y0,&internal1_m2119_fef};
_S_kvf  S_kvf_2078_1 = {&var1270,&var61,&fRM_0_0,&var1532,&vainSInt,&vainSInt,&internal1_m2078_x0,&internal1_m2078_y0,&internal1_m2078_fef};
_S_equz_p  S_equz_p_37_1 = {&R0MW13IP1,&iRM_1_,&var1533};
_S_noto  S_noto_34_1 = {&var1536,&var1534};
_S_equz_p  S_equz_p_41_1 = {&R0MW13IP1,&iRM_2_,&var1535};
_S_equz_p  S_equz_p_32_1 = {&R0MW13IP1,&iRM_3_,&var1536};
_S_noto  S_noto_2121_1 = {&var45,&var1537};
_S_rs  S_rs_305_1 = {&var1075,&var1076,&var1538,&vainSBool,&internal1_m305_q0};
_S_orn  S_orn_664_1 = {array_m664_x_1,&iRM_5_,&var1539};
_S_noto  S_noto_1129_1 = {&lEM_R0MD01LC1,&var1540};
_S_rs  S_rs_1120_1 = {&var852,&var1168,&var1541,&vainSBool,&internal1_m1120_q0};
_S_rs  S_rs_695_1 = {&var1030,&var1032,&var1542,&vainSBool,&internal1_m695_q0};
_S_noto  S_noto_1580_1 = {&var1211,&var1543};
_S_orn  S_orn_1548_1 = {array_m1548_x_1,&iRM_8_,&var1544};
_S_noto  S_noto_1547_1 = {&var1712,&var1545};
_S_noto  S_noto_1546_1 = {&var1722,&var1546};
_S_noto  S_noto_1526_1 = {&var1212,&var1547};
_S_noto  S_noto_1539_1 = {&R8IS11LDU,&var1548};
_S_charint  S_charint_1469_1 = {&var1551,&var1549};
_S_ornc  S_ornc_1477_1 = {array_m1477_x_1,&iRM_3_,&var1550,&var1551};
_S_fsumz  S_fsumz_1470_1 = {&var1549,&iRM_1_,&var1552};
_S_cnshd  S_cnshd_1479_1 = {&R0MD34LP1,&var1993,&var1242,&var578,&var1550,&var897,&var893,&iRM_1_,array_m1479_Lt_fw_1,array_m1479_Vr_fw_1,&iRM_1_,array_m1479_Lt_bw_1,array_m1479_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1553,&vainSBool,&var1554,&var1555,&var1556,&var1557,&var1558,&var1559,&var1560,&var1561,&var1562,&var1563,&internal1_m1479_X0,&internal1_m1479_t0,&internal1_m1479_BLDv0};
_S_zpfs  S_zpfs_1496_1 = {&var1572,&fRM_2_0,&var1564,&internal1_m1496_tx,&internal1_m1496_y0};
_S_zpfs  S_zpfs_1497_1 = {&var1571,&fRM_3_0,&var1565,&internal1_m1497_tx,&internal1_m1497_y0};
_S_fnapb  S_fnapb_1505_1 = {&var1993,&var1242,&var896,&R0MD34LP1,&var1555,&var1562,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1566,&var1567,&var1568,&var1569,&var1570,&var1571,&var1572,&vainSFloat,&internal1_m1505_xptr,array_m1505_x0_1,array_m1505_tim0_1,&internal1_m1505_sumtim,&internal1_m1505_StSpeed,&internal1_m1505_Vz0,&internal1_m1505_flRazg,&internal1_m1505_DelSp,&internal1_m1505_z0,&internal1_m1505_txZS,&internal1_m1505_tx,&internal1_m1505_txd,&internal1_m1505_txMBl,&internal1_m1505_txBl,&internal1_m1505_Speed0,&internal1_m1505_xz0,&internal1_m1505_tz0,&internal1_m1505_Shift0,&internal1_m1505_ShCntlSp0,&internal1_m1505_ShiftControl,&bFirstEnterFlag};
_S_newstage  S_newstage_1013_1 = {&var1582,&var1550,&var1585,&var1553,&var1573};
_S_rs  S_rs_693_1 = {&var1031,&var1035,&var1574,&vainSBool,&internal1_m693_q0};
_S_noto  S_noto_1106_1 = {&var1196,&var1575};
_S_orn  S_orn_1077_1 = {array_m1077_x_1,&iRM_8_,&var1576};
_S_noto  S_noto_1076_1 = {&var1712,&var1577};
_S_noto  S_noto_1075_1 = {&var1722,&var1578};
_S_noto  S_noto_1054_1 = {&var1212,&var1579};
_S_noto  S_noto_1066_1 = {&R8IS11LDU,&var1580};
_S_charint  S_charint_991_1 = {&var1583,&var1581};
_S_ornc  S_ornc_999_1 = {array_m999_x_1,&iRM_3_,&var1582,&var1583};
_S_fsumz  S_fsumz_992_1 = {&var1581,&iRM_1_,&var1584};
_S_cnshd  S_cnshd_1001_1 = {&R0MD34LP1,&var1996,&var1241,&var582,&var1582,&var932,&var933,&iRM_1_,array_m1001_Lt_fw_1,array_m1001_Vr_fw_1,&iRM_1_,array_m1001_Lt_bw_1,array_m1001_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1585,&vainSBool,&var1586,&var1587,&var1588,&var1589,&var1590,&var1591,&var1592,&var1593,&var1594,&var1595,&internal1_m1001_X0,&internal1_m1001_t0,&internal1_m1001_BLDv0};
_S_zpfs  S_zpfs_1024_1 = {&var1604,&fRM_2_0,&var1596,&internal1_m1024_tx,&internal1_m1024_y0};
_S_zpfs  S_zpfs_1023_1 = {&var1603,&fRM_3_0,&var1597,&internal1_m1023_tx,&internal1_m1023_y0};
_S_fnapb  S_fnapb_1031_1 = {&var1996,&var1241,&var931,&R0MD34LP1,&var1587,&var1594,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1598,&var1599,&var1600,&var1601,&var1602,&var1603,&var1604,&vainSFloat,&internal1_m1031_xptr,array_m1031_x0_1,array_m1031_tim0_1,&internal1_m1031_sumtim,&internal1_m1031_StSpeed,&internal1_m1031_Vz0,&internal1_m1031_flRazg,&internal1_m1031_DelSp,&internal1_m1031_z0,&internal1_m1031_txZS,&internal1_m1031_tx,&internal1_m1031_txd,&internal1_m1031_txMBl,&internal1_m1031_txBl,&internal1_m1031_Speed0,&internal1_m1031_xz0,&internal1_m1031_tz0,&internal1_m1031_Shift0,&internal1_m1031_ShCntlSp0,&internal1_m1031_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_645_1 = {&var1211,&var1605};
_S_noto  S_noto_611_1 = {&var1712,&var1606};
_S_noto  S_noto_610_1 = {&var1722,&var1607};
_S_noto  S_noto_589_1 = {&var1212,&var1608};
_S_noto  S_noto_599_1 = {&R8IS11LDU,&var1609};
_S_charint  S_charint_537_1 = {&var1612,&var1610};
_S_ornc  S_ornc_543_1 = {array_m543_x_1,&iRM_3_,&var1611,&var1612};
_S_fsumz  S_fsumz_538_1 = {&var1610,&iRM_1_,&var1613};
_S_cnshd  S_cnshd_546_1 = {&R0MD34LP1,&var2006,&var1243,&var586,&var1611,&var1003,&var997,&iRM_2_,array_m546_Lt_fw_1,array_m546_Vr_fw_1,&iRM_1_,array_m546_Lt_bw_1,array_m546_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1614,&vainSBool,&var1615,&var1616,&var1617,&var1618,&var1619,&var1620,&var1621,&var1622,&var1623,&var1624,&internal1_m546_X0,&internal1_m546_t0,&internal1_m546_BLDv0};
_S_zpfs  S_zpfs_565_1 = {&var1633,&fRM_2_0,&var1625,&internal1_m565_tx,&internal1_m565_y0};
_S_zpfs  S_zpfs_564_1 = {&var1632,&fRM_3_0,&var1626,&internal1_m564_tx,&internal1_m564_y0};
_S_fnapb  S_fnapb_569_1 = {&var2006,&var1243,&var1001,&R0MD34LP1,&var1616,&var1623,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1627,&var1628,&var1629,&var1630,&var1631,&var1632,&var1633,&vainSFloat,&internal1_m569_xptr,array_m569_x0_1,array_m569_tim0_1,&internal1_m569_sumtim,&internal1_m569_StSpeed,&internal1_m569_Vz0,&internal1_m569_flRazg,&internal1_m569_DelSp,&internal1_m569_z0,&internal1_m569_txZS,&internal1_m569_tx,&internal1_m569_txd,&internal1_m569_txMBl,&internal1_m569_txBl,&internal1_m569_Speed0,&internal1_m569_xz0,&internal1_m569_tz0,&internal1_m569_Shift0,&internal1_m569_ShCntlSp0,&internal1_m569_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_711_1 = {&R0MD33LP1,&var1634};
_S_noto  S_noto_283_1 = {&var1196,&var1635};
_S_newstage  S_newstage_211_1 = {&var1644,&var1611,&var1647,&var1614,&var1636};
_S_rs  S_rs_690_1 = {&var1026,&var1038,&var1637,&vainSBool,&internal1_m690_q0};
_S_orn  S_orn_238_1 = {array_m238_x_1,&iRM_12_,&var1638};
_S_noto  S_noto_246_1 = {&var1712,&var1639};
_S_noto  S_noto_245_1 = {&var1722,&var1640};
_S_noto  S_noto_223_1 = {&var1212,&var1641};
_S_noto  S_noto_233_1 = {&R8IS11LDU,&var1642};
_S_charint  S_charint_165_1 = {&var1645,&var1643};
_S_ornc  S_ornc_172_1 = {array_m172_x_1,&iRM_3_,&var1644,&var1645};
_S_fsumz  S_fsumz_166_1 = {&var1643,&iRM_1_,&var1646};
_S_cnshd  S_cnshd_176_1 = {&R0MD34LP1,&var1984,&var1244,&var590,&var1644,&var983,&var976,&iRM_2_,array_m176_Lt_fw_1,array_m176_Vr_fw_1,&iRM_1_,array_m176_Lt_bw_1,array_m176_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1647,&vainSBool,&var1648,&var1649,&var1650,&var1651,&var1652,&var1653,&var1654,&var1655,&var1656,&var1657,&internal1_m176_X0,&internal1_m176_t0,&internal1_m176_BLDv0};
_S_fnapb  S_fnapb_201_1 = {&var1984,&var1244,&var979,&R0MD34LP1,&var1649,&var1656,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1658,&var1659,&var1660,&var1661,&var1662,&var1663,&var1664,&vainSFloat,&internal1_m201_xptr,array_m201_x0_1,array_m201_tim0_1,&internal1_m201_sumtim,&internal1_m201_StSpeed,&internal1_m201_Vz0,&internal1_m201_flRazg,&internal1_m201_DelSp,&internal1_m201_z0,&internal1_m201_txZS,&internal1_m201_tx,&internal1_m201_txd,&internal1_m201_txMBl,&internal1_m201_txBl,&internal1_m201_Speed0,&internal1_m201_xz0,&internal1_m201_tz0,&internal1_m201_Shift0,&internal1_m201_ShCntlSp0,&internal1_m201_ShiftControl,&bFirstEnterFlag};
_S_rs  S_rs_716_1 = {&var1037,&var1040,&var1665,&vainSBool,&internal1_m716_q0};
_S_newstage  S_newstage_509_1 = {&var1684,&var1675,&var1683,&var1674,&var1666};
_S_samhd  S_samhd_513_1 = {&R0MD34LP1,&var1006,&var1006,&var640,&var639,&R2VS12LDU,&R2VS22LDU,&R2IS11LDU,&R2IS11LDU,&R2IS21LDU,&R2IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1667,&var1668,&var1669,&var1670,&var1671,&var1672,&vainSBool,&vainSBool,&var1673,&var1674,&var1675,&internal1_m513_DvUp0,&internal1_m513_DvDw0,&internal1_m513_FDvUp0,&internal1_m513_FDvDw0,&internal1_m513_BlDv0,&internal1_m513_Pkv0,&internal1_m513_Pkav0,&internal1_m513_Zkv0,&internal1_m513_Zkav0,&internal1_m513_txNm,&internal1_m513_txSm,&internal1_m513_txHr,&internal1_m513_txLd,&internal1_m513_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_507_1 = {&R0MD34LP1,&var1007,&var1007,&var638,&var637,&R1VS12LDU,&R1VS22LDU,&R1IS11LDU,&R1IS11LDU,&R1IS21LDU,&R1IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1676,&var1677,&var1678,&var1679,&var1680,&var1681,&vainSBool,&vainSBool,&var1682,&var1683,&var1684,&internal1_m507_DvUp0,&internal1_m507_DvDw0,&internal1_m507_FDvUp0,&internal1_m507_FDvDw0,&internal1_m507_BlDv0,&internal1_m507_Pkv0,&internal1_m507_Pkav0,&internal1_m507_Zkv0,&internal1_m507_Zkav0,&internal1_m507_txNm,&internal1_m507_txSm,&internal1_m507_txHr,&internal1_m507_txLd,&internal1_m507_fef,&bFirstEnterFlag};
_S_orn  S_orn_964_1 = {array_m964_x_1,&iRM_10_,&var1685};
_S_noto  S_noto_968_1 = {&var1712,&var1686};
_S_noto  S_noto_967_1 = {&var1722,&var1687};
_S_noto  S_noto_942_1 = {&var1212,&var1688};
_S_noto  S_noto_955_1 = {&R8IS11LDU,&var1689};
_S_charint  S_charint_895_1 = {&var1692,&var1690};
_S_ornc  S_ornc_902_1 = {array_m902_x_1,&iRM_3_,&var1691,&var1692};
_S_fsumz  S_fsumz_896_1 = {&var1690,&iRM_1_,&var1693};
_S_cnshd  S_cnshd_905_1 = {&R0MD34LP1,&var1999,&var1240,&var1240,&var1691,&var956,&var870,&iRM_2_,array_m905_Lt_fw_1,array_m905_Vr_fw_1,&iRM_1_,array_m905_Lt_bw_1,array_m905_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1694,&vainSBool,&var1695,&var1696,&var1697,&var1698,&var1699,&var1700,&var1701,&var1702,&var1703,&var1704,&internal1_m905_X0,&internal1_m905_t0,&internal1_m905_BLDv0};
_S_fnapb  S_fnapb_923_1 = {&var1999,&var1240,&var952,&R0MD34LP1,&var1696,&var1703,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL83RDU,&var1705,&var1706,&var1707,&var1708,&var1709,&var1710,&var1711,&vainSFloat,&internal1_m923_xptr,array_m923_x0_1,array_m923_tim0_1,&internal1_m923_sumtim,&internal1_m923_StSpeed,&internal1_m923_Vz0,&internal1_m923_flRazg,&internal1_m923_DelSp,&internal1_m923_z0,&internal1_m923_txZS,&internal1_m923_tx,&internal1_m923_txd,&internal1_m923_txMBl,&internal1_m923_txBl,&internal1_m923_Speed0,&internal1_m923_xz0,&internal1_m923_tz0,&internal1_m923_Shift0,&internal1_m923_ShCntlSp0,&internal1_m923_ShiftControl,&bFirstEnterFlag};
_S_cnshd  S_cnshd_1800_1 = {&R0MD34LP1,&var1990,&var574,&var574,&var780,&var783,&lRM_1_,&iRM_1_,array_m1800_Lt_fw_1,array_m1800_Vr_fw_1,&iRM_1_,array_m1800_Lt_bw_1,array_m1800_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1712,&vainSBool,&vainSFloat,&var1713,&var1714,&var1715,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1716,&internal1_m1800_X0,&internal1_m1800_t0,&internal1_m1800_BLDv0};
_S_newstage  S_newstage_1406_1 = {&var1730,&var1691,&var1735,&var1694,&var1717};
_S_orn  S_orn_1445_1 = {array_m1445_x_1,&iRM_10_,&var1718};
_S_orn  S_orn_154_1 = {array_m154_x_1,&iRM_5_,&var1719};
_S_noto  S_noto_1444_1 = {&var1712,&var1720};
_S_noto  S_noto_1443_1 = {&var1722,&var1721};
_S_cnshd  S_cnshd_1270_1 = {&R0MD34LP1,&var1987,&var574,&var574,&var1097,&var781,&lRM_1_,&iRM_1_,array_m1270_Lt_fw_1,array_m1270_Vr_fw_1,&iRM_1_,array_m1270_Lt_bw_1,array_m1270_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1722,&vainSBool,&vainSFloat,&var1723,&var1724,&var1725,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1726,&internal1_m1270_X0,&internal1_m1270_t0,&internal1_m1270_BLDv0};
_S_noto  S_noto_1421_1 = {&var1212,&var1727};
_S_noto  S_noto_1433_1 = {&R8IS11LDU,&var1728};
_S_charint  S_charint_1356_1 = {&var1731,&var1729};
_S_ornc  S_ornc_1364_1 = {array_m1364_x_1,&iRM_3_,&var1730,&var1731};
_S_noto  S_noto_675_1 = {&lEM_R0MD01LC1,&var1732};
_S_fsumz  S_fsumz_1357_1 = {&var1729,&iRM_1_,&var1733};
_S_rs  S_rs_688_1 = {&var1048,&var1050,&var1734,&vainSBool,&internal1_m688_q0};
_S_cnshd  S_cnshd_1366_1 = {&R0MD34LP1,&var2002,&var1239,&var1239,&var1730,&var873,&var866,&iRM_2_,array_m1366_Lt_fw_1,array_m1366_Vr_fw_1,&iRM_1_,array_m1366_Lt_bw_1,array_m1366_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1735,&vainSBool,&var1736,&var1737,&var1738,&var1739,&var1740,&var1741,&var1742,&var1743,&var1744,&var1745,&internal1_m1366_X0,&internal1_m1366_t0,&internal1_m1366_BLDv0};
_S_zpfs  S_zpfs_1396_1 = {&var1754,&fRM_2_0,&var1746,&internal1_m1396_tx,&internal1_m1396_y0};
_S_zpfs  S_zpfs_1395_1 = {&var1753,&fRM_3_0,&var1747,&internal1_m1395_tx,&internal1_m1395_y0};
_S_fnapb  S_fnapb_1401_1 = {&var2002,&var1239,&var874,&R0MD34LP1,&var1737,&var1744,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL03RDU,&var1748,&var1749,&var1750,&var1751,&var1752,&var1753,&var1754,&vainSFloat,&internal1_m1401_xptr,array_m1401_x0_1,array_m1401_tim0_1,&internal1_m1401_sumtim,&internal1_m1401_StSpeed,&internal1_m1401_Vz0,&internal1_m1401_flRazg,&internal1_m1401_DelSp,&internal1_m1401_z0,&internal1_m1401_txZS,&internal1_m1401_tx,&internal1_m1401_txd,&internal1_m1401_txMBl,&internal1_m1401_txBl,&internal1_m1401_Speed0,&internal1_m1401_xz0,&internal1_m1401_tz0,&internal1_m1401_Shift0,&internal1_m1401_ShCntlSp0,&internal1_m1401_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_1781_1 = {&R8IS11LDU,&var1755};
_S_rs  S_rs_708_1 = {&var1051,&var1052,&var1756,&vainSBool,&internal1_m708_q0};
_S_zpfs  S_zpfs_1814_1 = {&var1767,&fRM_2_0,&var1757,&internal1_m1814_tx,&internal1_m1814_y0};
_S_zpfs  S_zpfs_1818_1 = {&var1766,&fRM_3_0,&var1758,&internal1_m1818_tx,&internal1_m1818_y0};
_S_samhd  S_samhd_1803_1 = {&R0MD34LP1,&var783,&var783,&var1714,&var1715,&var1761,&var1762,&A8IS12LDU,&A8IS12LDU,&A8IS22LDU,&A8IS22LDU,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&var1759,&var1760,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&internal1_m1803_DvUp0,&internal1_m1803_DvDw0,&internal1_m1803_FDvUp0,&internal1_m1803_FDvDw0,&internal1_m1803_BlDv0,&internal1_m1803_Pkv0,&internal1_m1803_Pkav0,&internal1_m1803_Zkv0,&internal1_m1803_Zkav0,&internal1_m1803_txNm,&internal1_m1803_txSm,&internal1_m1803_txHr,&internal1_m1803_txLd,&internal1_m1803_fef,&bFirstEnterFlag};
_S_fnapb  S_fnapb_1822_1 = {&var1990,&var574,&var779,&R0MD34LP1,&var1713,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&var1761,&var1762,&var1763,&var1764,&var1765,&var1766,&var1767,&vainSFloat,&internal1_m1822_xptr,array_m1822_x0_1,array_m1822_tim0_1,&internal1_m1822_sumtim,&internal1_m1822_StSpeed,&internal1_m1822_Vz0,&internal1_m1822_flRazg,&internal1_m1822_DelSp,&internal1_m1822_z0,&internal1_m1822_txZS,&internal1_m1822_tx,&internal1_m1822_txd,&internal1_m1822_txMBl,&internal1_m1822_txBl,&internal1_m1822_Speed0,&internal1_m1822_xz0,&internal1_m1822_tz0,&internal1_m1822_Shift0,&internal1_m1822_ShCntlSp0,&internal1_m1822_ShiftControl,&bFirstEnterFlag};
_S_zpfs  S_zpfs_1286_1 = {&var1784,&fRM_2_0,&var1768,&internal1_m1286_tx,&internal1_m1286_y0};
_S_zpfs  S_zpfs_1290_1 = {&var1783,&fRM_3_0,&var1769,&internal1_m1290_tx,&internal1_m1290_y0};
_S_noto  S_noto_1250_1 = {&R8IS11LDU,&var1770};
_S_orn  S_orn_1232_1 = {array_m1232_x_1,&iRM_8_,&var1771};
_S_noto  S_noto_677_1 = {&var1775,&var1772};
_S_rs  S_rs_698_1 = {&var1053,&var1054,&var1773,&vainSBool,&internal1_m698_q0};
_S_orn  S_orn_665_1 = {array_m665_x_1,&iRM_18_,&var1774};
_S_rs  S_rs_663_1 = {&var1539,&var1169,&var1775,&vainSBool,&internal1_m663_q0};
_S_samhd  S_samhd_1276_1 = {&R0MD34LP1,&var781,&var781,&var1724,&var1725,&var1778,&var1779,&var422,&var422,&var421,&var421,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&vainSBool,&vainSBool,&var1776,&var1777,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&internal1_m1276_DvUp0,&internal1_m1276_DvDw0,&internal1_m1276_FDvUp0,&internal1_m1276_FDvDw0,&internal1_m1276_BlDv0,&internal1_m1276_Pkv0,&internal1_m1276_Pkav0,&internal1_m1276_Zkv0,&internal1_m1276_Zkav0,&internal1_m1276_txNm,&internal1_m1276_txSm,&internal1_m1276_txHr,&internal1_m1276_txLd,&internal1_m1276_fef,&bFirstEnterFlag};
_S_fnapb  S_fnapb_1296_1 = {&var1987,&var574,&var1096,&R0MD34LP1,&var1723,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL06RDU,&fEM_B8UL03RDU,&var1778,&var1779,&var1780,&var1781,&var1782,&var1783,&var1784,&vainSFloat,&internal1_m1296_xptr,array_m1296_x0_1,array_m1296_tim0_1,&internal1_m1296_sumtim,&internal1_m1296_StSpeed,&internal1_m1296_Vz0,&internal1_m1296_flRazg,&internal1_m1296_DelSp,&internal1_m1296_z0,&internal1_m1296_txZS,&internal1_m1296_tx,&internal1_m1296_txd,&internal1_m1296_txMBl,&internal1_m1296_txBl,&internal1_m1296_Speed0,&internal1_m1296_xz0,&internal1_m1296_tz0,&internal1_m1296_Shift0,&internal1_m1296_ShCntlSp0,&internal1_m1296_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_803_1 = {&A5IS21LDU,&var1785};
_S_vmemb  S_vmemb_826_1 = {&var1787,&var1786,&internal1_m826_x0};
_S_noto  S_noto_834_1 = {&var423,&var1787};
_S_vmemb  S_vmemb_794_1 = {&var1785,&var1788,&internal1_m794_x0};
_S_vmemb  S_vmemb_737_1 = {&var1803,&var1789,&internal1_m737_x0};
_S_newstage  S_newstage_873_1 = {&var1847,&var1838,&var1846,&var1837,&var1790};
_S_newstage  S_newstage_1334_1 = {&var1829,&var1820,&var1828,&var1819,&var1791};
_S_newstage  S_newstage_420_1 = {&var1874,&var1865,&var1873,&var1864,&var1792};
_S_noto  S_noto_845_1 = {&var424,&var1793};
_S_rs  S_rs_851_1 = {&var1117,&var1792,&var1794,&vainSBool,&internal1_m851_q0};
_S_rs  S_rs_846_1 = {&var1118,&var1218,&var1795,&vainSBool,&internal1_m846_q0};
_S_noto  S_noto_838_1 = {&var1876,&var1796};
_S_noto  S_noto_836_1 = {&var1877,&var1797};
_S_rs  S_rs_814_1 = {&var1122,&var1792,&var1798,&vainSBool,&internal1_m814_q0};
_S_rs  S_rs_818_1 = {&var1121,&var1790,&var1799,&vainSBool,&internal1_m818_q0};
_S_rs  S_rs_827_1 = {&var1188,&var1127,&var1800,&vainSBool,&internal1_m827_q0};
_S_rs  S_rs_839_1 = {&var1119,&var1125,&var1801,&vainSBool,&internal1_m839_q0};
_S_noto  S_noto_793_1 = {&var424,&var1802};
_S_noto  S_noto_730_1 = {&var423,&var1803};
_S_noto  S_noto_459_1 = {&R8IS11LDU,&var1804};
_S_orn  S_orn_477_1 = {array_m477_x_1,&iRM_7_,&var1805};
_S_orn  S_orn_455_1 = {array_m455_x_1,&iRM_7_,&var1806};
_S_rs  S_rs_816_1 = {&var1126,&var1131,&var1807,&vainSBool,&internal1_m816_q0};
_S_noto  S_noto_162_1 = {&B2IS12LDU,&var1808};
_S_noto  S_noto_151_1 = {&A2IS12LDU,&var1809};
_S_noto  S_noto_152_1 = {&B1IS12LDU,&var1810};
_S_noto  S_noto_160_1 = {&A1IS12LDU,&var1811};
_S_samhd  S_samhd_1338_1 = {&var1100,&var1101,&var1101,&var1414,&var1413,&var1414,&var1413,&B4IS11LDU,&B4IS11LDU,&B4IS21LDU,&B4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1812,&var1813,&var1814,&vainSBool,&var1815,&vainSBool,&var1816,&var1817,&var1818,&var1819,&var1820,&internal1_m1338_DvUp0,&internal1_m1338_DvDw0,&internal1_m1338_FDvUp0,&internal1_m1338_FDvDw0,&internal1_m1338_BlDv0,&internal1_m1338_Pkv0,&internal1_m1338_Pkav0,&internal1_m1338_Zkv0,&internal1_m1338_Zkav0,&internal1_m1338_txNm,&internal1_m1338_txSm,&internal1_m1338_txHr,&internal1_m1338_txLd,&internal1_m1338_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_1329_1 = {&var1100,&var1103,&var1103,&var1414,&var1413,&var1414,&var1413,&A4IS11LDU,&A4IS11LDU,&A4IS21LDU,&A4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1821,&var1822,&var1823,&vainSBool,&var1824,&vainSBool,&var1825,&var1826,&var1827,&var1828,&var1829,&internal1_m1329_DvUp0,&internal1_m1329_DvDw0,&internal1_m1329_FDvUp0,&internal1_m1329_FDvDw0,&internal1_m1329_BlDv0,&internal1_m1329_Pkv0,&internal1_m1329_Pkav0,&internal1_m1329_Zkv0,&internal1_m1329_Zkav0,&internal1_m1329_txNm,&internal1_m1329_txSm,&internal1_m1329_txHr,&internal1_m1329_txLd,&internal1_m1329_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_875_1 = {&R0MD34LP1,&var958,&var958,&var1219,&var1114,&B5VS12LDU,&B5VS22LDU,&B5IS11LDU,&B5IS11LDU,&B5IS21LDU,&B5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1830,&var1831,&var1832,&var1833,&var1834,&var1835,&vainSBool,&vainSBool,&var1836,&var1837,&var1838,&internal1_m875_DvUp0,&internal1_m875_DvDw0,&internal1_m875_FDvUp0,&internal1_m875_FDvDw0,&internal1_m875_BlDv0,&internal1_m875_Pkv0,&internal1_m875_Pkav0,&internal1_m875_Zkv0,&internal1_m875_Zkav0,&internal1_m875_txNm,&internal1_m875_txSm,&internal1_m875_txHr,&internal1_m875_txLd,&internal1_m875_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_871_1 = {&R0MD34LP1,&var960,&var960,&var1219,&var1114,&A5VS12LDU,&A5VS22LDU,&A5IS11LDU,&A5IS11LDU,&A5IS21LDU,&A5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1839,&var1840,&var1841,&var1842,&var1843,&var1844,&vainSBool,&vainSBool,&var1845,&var1846,&var1847,&internal1_m871_DvUp0,&internal1_m871_DvDw0,&internal1_m871_FDvUp0,&internal1_m871_FDvDw0,&internal1_m871_BlDv0,&internal1_m871_Pkv0,&internal1_m871_Pkav0,&internal1_m871_Zkv0,&internal1_m871_Zkav0,&internal1_m871_txNm,&internal1_m871_txSm,&internal1_m871_txHr,&internal1_m871_txLd,&internal1_m871_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_386_1 = {&R0MD34LP1,&var642,&var641,&var1123,&var1116,&R4VS12LDU,&R4VS22LDU,&R4IS11LDU,&R4IS12LDU,&R4IS21LDU,&R4IS22LDU,&bRM_0_,&fEM_R4UZ05RDU,&fEM_R4UZ03RDU,&fEM_R4UZ04RDU,&var1848,&var1849,&var1850,&var1851,&var1852,&var1853,&vainSBool,&vainSBool,&var1854,&var1855,&vainSBool,&internal1_m386_DvUp0,&internal1_m386_DvDw0,&internal1_m386_FDvUp0,&internal1_m386_FDvDw0,&internal1_m386_BlDv0,&internal1_m386_Pkv0,&internal1_m386_Pkav0,&internal1_m386_Zkv0,&internal1_m386_Zkav0,&internal1_m386_txNm,&internal1_m386_txSm,&internal1_m386_txHr,&internal1_m386_txLd,&internal1_m386_fef,&bFirstEnterFlag};
_S_noto  S_noto_750_1 = {&R8IS11LDU,&var1856};
_S_samhd  S_samhd_423_1 = {&R0MD34LP1,&var1805,&var1189,&var1195,&var1115,&B6VS12LDU,&B6VS22LDU,&B6IS11LDU,&B6IS11LDU,&B6IS21LDU,&B6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1857,&var1858,&var1859,&var1860,&var1861,&var1862,&vainSBool,&vainSBool,&var1863,&var1864,&var1865,&internal1_m423_DvUp0,&internal1_m423_DvDw0,&internal1_m423_FDvUp0,&internal1_m423_FDvDw0,&internal1_m423_BlDv0,&internal1_m423_Pkv0,&internal1_m423_Pkav0,&internal1_m423_Zkv0,&internal1_m423_Zkav0,&internal1_m423_txNm,&internal1_m423_txSm,&internal1_m423_txHr,&internal1_m423_txLd,&internal1_m423_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_417_1 = {&R0MD34LP1,&var1806,&var1190,&var1195,&var1115,&A6VS12LDU,&A6VS22LDU,&A6IS11LDU,&A6IS11LDU,&A6IS21LDU,&A6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1866,&var1867,&var1868,&var1869,&var1870,&var1871,&vainSBool,&vainSBool,&var1872,&var1873,&var1874,&internal1_m417_DvUp0,&internal1_m417_DvDw0,&internal1_m417_FDvUp0,&internal1_m417_FDvDw0,&internal1_m417_BlDv0,&internal1_m417_Pkv0,&internal1_m417_Pkav0,&internal1_m417_Zkv0,&internal1_m417_Zkav0,&internal1_m417_txNm,&internal1_m417_txSm,&internal1_m417_txHr,&internal1_m417_txLd,&internal1_m417_fef,&bFirstEnterFlag};
_S_orn  S_orn_850_1 = {array_m850_x_1,&iRM_17_,&var1875};
_S_rs  S_rs_823_1 = {&var1129,&var333,&var1876,&vainSBool,&internal1_m823_q0};
_S_rs  S_rs_820_1 = {&var1130,&var334,&var1877,&vainSBool,&internal1_m820_q0};
_S_orni  S_orni_140_1 = {array_m140_x_1,&iRM_21_,&var1878,&vainSLong};
_S_equz_p  S_equz_p_80_1 = {&R0MW11IP2,&iRM_6_,&var1879};
_S_equz_p  S_equz_p_77_1 = {&R0MW11IP2,&iRM_5_,&var1880};
_S_equz_p  S_equz_p_76_1 = {&R0MW11IP2,&iRM_4_,&var1881};
_S_equz_p  S_equz_p_72_1 = {&R0MW11IP2,&iRM_3_,&var1882};
_S_equz_p  S_equz_p_71_1 = {&R0MW11IP2,&iRM_2_,&var1883};
_S_equz_p  S_equz_p_68_1 = {&R0MW11IP2,&iRM_1_,&var1884};
_S_equz_p  S_equz_p_64_1 = {&R0MW14IP1,&iRM_3_,&var1885};
_S_equz_p  S_equz_p_57_1 = {&R0MW14IP1,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_60_1 = {&R0MW14IP1,&iRM_2_,&var1886};
_S_equz_p  S_equz_p_51_1 = {&R0MW11IP1,&iRM_3_,&var1887};
_S_equz_p  S_equz_p_43_1 = {&R0MW11IP1,&iRM_1_,&var1888};
_S_equz_p  S_equz_p_47_1 = {&R0MW11IP1,&iRM_2_,&var1889};
_S_equz_p  S_equz_p_106_1 = {&R0MW16IP1,&iRM_11_,&var1890};
_S_equz_p  S_equz_p_99_1 = {&R0MW16IP1,&iRM_4_,&var1891};
_S_equz_p  S_equz_p_98_1 = {&R0MW16IP1,&iRM_3_,&var1892};
_S_equz_p  S_equz_p_97_1 = {&R0MW16IP1,&iRM_2_,&var1893};
_S_equz_p  S_equz_p_10_1 = {&R0MW12IP1,&iRM_4_,&var1894};
_S_equz_p  S_equz_p_7_1 = {&R0MW12IP1,&iRM_3_,&var1895};
_S_equz_p  S_equz_p_2_1 = {&R0MW12IP1,&iRM_1_,&var1896};
_S_equz_p  S_equz_p_4_1 = {&R0MW12IP1,&iRM_2_,&var1897};


void ZeroVar()
{
   var1.b=0;
   var2.b=0;
   var3.b=0;
   var4.b=0;
   var5.b=0;
   var6.b=0;
   var7.b=0;
   var8.b=0;
   var9.b=0;
   var10.b=0;
   var11.b=0;
   var12.b=0;
   var13.b=0;
   var14.b=0;
   var15.b=0;
   var16.b=0;
   var17.b=0;
   var18.b=0;
   var19.b=0;
   var20.b=0;
   var21.b=0;
   var22.b=0;
   var23.b=0;
   var24.b=0;
   var25.b=0;
   var26.b=0;
   var27.b=0;
   var28.b=0;
   var29.b=0;
   var30.b=0;
   var31.b=0;
   var32.b=0;
   var33.b=0;
   var34.b=0;
   var35.b=0;
   var36.b=0;
   var37.b=0;
   var38.b=0;
   var39.b=0;
   var40.b=0;
   var41.b=0;
   var42.b=0;
   var43.b=0;
   var44.b=0;
   var45.b=0;
   var46.b=0;
   var47.b=0;
   var48.b=0;
   var49.b=0;
   var50.b=0;
   var51.b=0;
   var52.b=0;
   var53.b=0;
   var54.b=0;
   var55.b=0;
   var56.b=0;
   var57.b=0;
   var58.b=0;
   var59.b=0;
   var60.b=0;
   var61.b=0;
   var62.f=0.0;
   var63.b=0;
   var64.b=0;
   var65.b=0;
   var66.b=0;
   var67.b=0;
   var68.b=0;
   var69.b=0;
   var70.b=0;
   var71.b=0;
   var72.b=0;
   var73.b=0;
   var74.b=0;
   var75.b=0;
   var76.b=0;
   var77.b=0;
   var78.b=0;
   var79.b=0;
   var80.b=0;
   var81.b=0;
   var82.b=0;
   var83.b=0;
   var84.b=0;
   var85.b=0;
   var86.b=0;
   var87.b=0;
   var88.b=0;
   var89.b=0;
   var90.b=0;
   var91.b=0;
   var92.b=0;
   var93.b=0;
   var94.b=0;
   var95.b=0;
   var96.b=0;
   var97.b=0;
   var98.b=0;
   var99.b=0;
   var100.b=0;
   var101.b=0;
   var102.b=0;
   var103.b=0;
   var104.b=0;
   var105.b=0;
   var106.b=0;
   var107.b=0;
   var108.b=0;
   var109.b=0;
   var110.b=0;
   var111.b=0;
   var112.b=0;
   var113.b=0;
   var114.b=0;
   var115.b=0;
   var116.b=0;
   var117.b=0;
   var118.b=0;
   var119.b=0;
   var120.b=0;
   var121.b=0;
   var122.b=0;
   var123.b=0;
   var124.b=0;
   var125.b=0;
   var126.b=0;
   var127.b=0;
   var128.b=0;
   var129.b=0;
   var130.b=0;
   var131.b=0;
   var132.b=0;
   var133.b=0;
   var134.b=0;
   var135.b=0;
   var136.b=0;
   var137.b=0;
   var138.b=0;
   var139.b=0;
   var140.b=0;
   var141.b=0;
   var142.b=0;
   var143.b=0;
   var144.b=0;
   var145.b=0;
   var146.b=0;
   var147.b=0;
   var148.b=0;
   var149.b=0;
   var150.b=0;
   var151.b=0;
   var152.b=0;
   var153.b=0;
   var154.b=0;
   var155.b=0;
   var156.b=0;
   var157.b=0;
   var158.b=0;
   var159.b=0;
   var160.b=0;
   var161.b=0;
   var162.b=0;
   var163.b=0;
   var164.b=0;
   var165.b=0;
   var166.b=0;
   var167.b=0;
   var168.b=0;
   var169.b=0;
   var170.b=0;
   var171.b=0;
   var172.b=0;
   var173.b=0;
   var174.b=0;
   var175.b=0;
   var176.b=0;
   var177.b=0;
   var178.b=0;
   var179.b=0;
   var180.b=0;
   var181.b=0;
   var182.b=0;
   var183.b=0;
   var184.b=0;
   var185.b=0;
   var186.b=0;
   var187.b=0;
   var188.b=0;
   var189.b=0;
   var190.b=0;
   var191.b=0;
   var192.b=0;
   var193.b=0;
   var194.b=0;
   var195.b=0;
   var196.b=0;
   var197.b=0;
   var198.b=0;
   var199.b=0;
   var200.b=0;
   var201.b=0;
   var202.b=0;
   var203.b=0;
   var204.b=0;
   var205.b=0;
   var206.b=0;
   var207.b=0;
   var208.b=0;
   var209.b=0;
   var210.b=0;
   var211.b=0;
   var212.b=0;
   var213.b=0;
   var214.b=0;
   var215.b=0;
   var216.b=0;
   var217.b=0;
   var218.b=0;
   var219.b=0;
   var220.b=0;
   var221.b=0;
   var222.b=0;
   var223.b=0;
   var224.b=0;
   var225.b=0;
   var226.b=0;
   var227.b=0;
   var228.b=0;
   var229.b=0;
   var230.b=0;
   var231.b=0;
   var232.b=0;
   var233.b=0;
   var234.b=0;
   var235.b=0;
   var236.b=0;
   var237.b=0;
   var238.b=0;
   var239.b=0;
   var240.b=0;
   var241.b=0;
   var242.b=0;
   var243.b=0;
   var244.b=0;
   var245.b=0;
   var246.b=0;
   var247.b=0;
   var248.b=0;
   var249.b=0;
   var250.b=0;
   var251.b=0;
   var252.b=0;
   var253.b=0;
   var254.b=0;
   var255.b=0;
   var256.b=0;
   var257.b=0;
   var258.b=0;
   var259.b=0;
   var260.b=0;
   var261.b=0;
   var262.b=0;
   var263.b=0;
   var264.b=0;
   var265.b=0;
   var266.b=0;
   var267.b=0;
   var268.b=0;
   var269.b=0;
   var270.b=0;
   var271.b=0;
   var272.b=0;
   var273.b=0;
   var274.b=0;
   var275.b=0;
   var276.b=0;
   var277.b=0;
   var278.b=0;
   var279.i=0;
   var280.b=0;
   var281.b=0;
   var282.b=0;
   var283.b=0;
   var284.b=0;
   var285.b=0;
   var286.b=0;
   var287.b=0;
   var288.b=0;
   var289.b=0;
   var290.b=0;
   var291.b=0;
   var292.b=0;
   var293.b=0;
   var294.b=0;
   var295.b=0;
   var296.b=0;
   var297.b=0;
   var298.b=0;
   var299.b=0;
   var300.b=0;
   var301.b=0;
   var302.b=0;
   var303.b=0;
   var304.b=0;
   var305.b=0;
   var306.b=0;
   var307.b=0;
   var308.b=0;
   var309.b=0;
   var310.b=0;
   var311.b=0;
   var312.b=0;
   var313.b=0;
   var314.b=0;
   var315.b=0;
   var316.b=0;
   var317.b=0;
   var318.b=0;
   var319.b=0;
   var320.b=0;
   var321.b=0;
   var322.b=0;
   var323.b=0;
   var324.b=0;
   var325.b=0;
   var326.b=0;
   var327.b=0;
   var328.b=0;
   var329.b=0;
   var330.b=0;
   var331.b=0;
   var332.b=0;
   var333.b=0;
   var334.b=0;
   var335.b=0;
   var336.b=0;
   var337.b=0;
   var338.b=0;
   var339.b=0;
   var340.b=0;
   var341.b=0;
   var342.b=0;
   var343.b=0;
   var344.b=0;
   var345.b=0;
   var346.b=0;
   var347.b=0;
   var348.b=0;
   var349.b=0;
   var350.b=0;
   var351.b=0;
   var352.b=0;
   var353.b=0;
   var354.b=0;
   var355.b=0;
   var356.b=0;
   var357.b=0;
   var358.b=0;
   var359.b=0;
   var360.b=0;
   var361.b=0;
   var362.b=0;
   var363.b=0;
   var364.b=0;
   var365.b=0;
   var366.b=0;
   var367.b=0;
   var368.b=0;
   var369.b=0;
   var370.b=0;
   var371.b=0;
   var372.b=0;
   var373.b=0;
   var374.b=0;
   var375.b=0;
   var376.b=0;
   var377.b=0;
   var378.b=0;
   var379.b=0;
   var380.b=0;
   var381.b=0;
   var382.b=0;
   var383.b=0;
   var384.b=0;
   var385.b=0;
   var386.b=0;
   var387.b=0;
   var388.b=0;
   var389.b=0;
   var390.b=0;
   var391.b=0;
   var392.b=0;
   var393.b=0;
   var394.b=0;
   var395.b=0;
   var396.b=0;
   var397.b=0;
   var398.b=0;
   var399.b=0;
   var400.b=0;
   var401.b=0;
   var402.b=0;
   var403.b=0;
   var404.b=0;
   var405.i=0;
   var406.b=0;
   var407.b=0;
   var408.i=0;
   var409.b=0;
   var410.b=0;
   var411.b=0;
   var412.b=0;
   var413.b=0;
   var414.b=0;
   var415.b=0;
   var416.b=0;
   var417.b=0;
   var418.b=0;
   var419.b=0;
   var420.b=0;
   var421.b=0;
   var422.b=0;
   var423.b=0;
   var424.b=0;
   var425.b=0;
   var426.b=0;
   var427.b=0;
   var428.b=0;
   var429.b=0;
   var430.b=0;
   var431.b=0;
   var432.b=0;
   var433.b=0;
   var434.b=0;
   var435.b=0;
   var436.b=0;
   var437.b=0;
   var438.b=0;
   var439.b=0;
   var440.b=0;
   var441.b=0;
   var442.b=0;
   var443.b=0;
   var444.b=0;
   var445.b=0;
   var446.b=0;
   var447.b=0;
   var448.b=0;
   var449.f=0.0;
   var450.b=0;
   var451.b=0;
   var452.b=0;
   var453.b=0;
   var454.b=0;
   var455.b=0;
   var456.b=0;
   var457.b=0;
   var458.b=0;
   var459.f=0.0;
   var460.f=0.0;
   var461.b=0;
   var462.b=0;
   var463.b=0;
   var464.f=0.0;
   var465.b=0;
   var466.b=0;
   var467.f=0.0;
   var468.b=0;
   var469.b=0;
   var470.b=0;
   var471.b=0;
   var472.b=0;
   var473.b=0;
   var474.b=0;
   var475.b=0;
   var476.f=0.0;
   var477.f=0.0;
   var478.f=0.0;
   var479.f=0.0;
   var480.b=0;
   var481.f=0.0;
   var482.f=0.0;
   var483.i=0;
   var484.b=0;
   var485.b=0;
   var486.b=0;
   var487.b=0;
   var488.b=0;
   var489.b=0;
   var490.b=0;
   var491.b=0;
   var492.b=0;
   var493.b=0;
   var494.b=0;
   var495.b=0;
   var496.b=0;
   var497.b=0;
   var498.b=0;
   var499.b=0;
   var500.b=0;
   var501.b=0;
   var502.b=0;
   var503.b=0;
   var504.b=0;
   var505.b=0;
   var506.b=0;
   var507.b=0;
   var508.b=0;
   var509.b=0;
   var510.b=0;
   var511.b=0;
   var512.b=0;
   var513.b=0;
   var514.b=0;
   var515.b=0;
   var516.b=0;
   var517.b=0;
   var518.b=0;
   var519.b=0;
   var520.b=0;
   var521.b=0;
   var522.b=0;
   var523.b=0;
   var524.b=0;
   var525.b=0;
   var526.b=0;
   var527.b=0;
   var528.b=0;
   var529.b=0;
   var530.b=0;
   var531.b=0;
   var532.b=0;
   var533.b=0;
   var534.b=0;
   var535.b=0;
   var536.b=0;
   var537.b=0;
   var538.b=0;
   var539.b=0;
   var540.b=0;
   var541.b=0;
   var542.b=0;
   var543.b=0;
   var544.b=0;
   var545.b=0;
   var546.b=0;
   var547.b=0;
   var548.b=0;
   var549.b=0;
   var550.b=0;
   var551.b=0;
   var552.b=0;
   var553.b=0;
   var554.b=0;
   var555.b=0;
   var556.b=0;
   var557.b=0;
   var558.b=0;
   var559.b=0;
   var560.b=0;
   var561.b=0;
   var562.b=0;
   var563.b=0;
   var564.b=0;
   var565.b=0;
   var566.b=0;
   var567.b=0;
   var568.b=0;
   var569.b=0;
   var570.b=0;
   var571.b=0;
   var572.b=0;
   var573.b=0;
   var574.f=0.0;
   var575.b=0;
   var576.b=0;
   var577.b=0;
   var578.f=0.0;
   var579.b=0;
   var580.b=0;
   var581.b=0;
   var582.f=0.0;
   var583.b=0;
   var584.b=0;
   var585.b=0;
   var586.f=0.0;
   var587.b=0;
   var588.b=0;
   var589.b=0;
   var590.f=0.0;
   var591.b=0;
   var592.b=0;
   var593.b=0;
   var594.b=0;
   var595.b=0;
   var596.b=0;
   var597.b=0;
   var598.b=0;
   var599.b=0;
   var600.b=0;
   var601.b=0;
   var602.b=0;
   var603.b=0;
   var604.b=0;
   var605.b=0;
   var606.b=0;
   var607.b=0;
   var608.b=0;
   var609.b=0;
   var610.b=0;
   var611.b=0;
   var612.b=0;
   var613.b=0;
   var614.b=0;
   var615.b=0;
   var616.b=0;
   var617.b=0;
   var618.b=0;
   var619.b=0;
   var620.b=0;
   var621.b=0;
   var622.b=0;
   var623.b=0;
   var624.b=0;
   var625.b=0;
   var626.b=0;
   var627.b=0;
   var628.b=0;
   var629.b=0;
   var630.b=0;
   var631.b=0;
   var632.b=0;
   var633.b=0;
   var634.b=0;
   var635.b=0;
   var636.b=0;
   var637.b=0;
   var638.b=0;
   var639.b=0;
   var640.b=0;
   var641.b=0;
   var642.b=0;
   var643.b=0;
   var644.b=0;
   var645.b=0;
   var646.b=0;
   var647.b=0;
   var648.b=0;
   var649.b=0;
   var650.b=0;
   var651.b=0;
   var652.b=0;
   var653.b=0;
   var654.b=0;
   var655.b=0;
   var656.b=0;
   var657.b=0;
   var658.b=0;
   var659.b=0;
   var660.b=0;
   var661.b=0;
   var662.b=0;
   var663.b=0;
   var664.b=0;
   var665.b=0;
   var666.b=0;
   var667.b=0;
   var668.b=0;
   var669.b=0;
   var670.b=0;
   var671.b=0;
   var672.b=0;
   var673.b=0;
   var674.b=0;
   var675.b=0;
   var676.f=0.0;
   var677.f=0.0;
   var678.b=0;
   var679.f=0.0;
   var680.f=0.0;
   var681.b=0;
   var682.f=0.0;
   var683.f=0.0;
   var684.b=0;
   var685.f=0.0;
   var686.f=0.0;
   var687.b=0;
   var688.b=0;
   var689.f=0.0;
   var690.f=0.0;
   var691.b=0;
   var692.b=0;
   var693.b=0;
   var694.b=0;
   var695.b=0;
   var696.b=0;
   var697.b=0;
   var698.b=0;
   var699.b=0;
   var700.b=0;
   var701.b=0;
   var702.b=0;
   var703.b=0;
   var704.b=0;
   var705.b=0;
   var706.b=0;
   var707.b=0;
   var708.b=0;
   var709.b=0;
   var710.b=0;
   var711.b=0;
   var712.b=0;
   var713.b=0;
   var714.b=0;
   var715.b=0;
   var716.b=0;
   var717.b=0;
   var718.b=0;
   var719.b=0;
   var720.b=0;
   var721.b=0;
   var722.b=0;
   var723.b=0;
   var724.b=0;
   var725.b=0;
   var726.b=0;
   var727.b=0;
   var728.b=0;
   var729.b=0;
   var730.b=0;
   var731.b=0;
   var732.b=0;
   var733.b=0;
   var734.b=0;
   var735.b=0;
   var736.b=0;
   var737.b=0;
   var738.b=0;
   var739.b=0;
   var740.b=0;
   var741.b=0;
   var742.b=0;
   var743.b=0;
   var744.b=0;
   var745.b=0;
   var746.b=0;
   var747.b=0;
   var748.b=0;
   var749.b=0;
   var750.b=0;
   var751.b=0;
   var752.b=0;
   var753.b=0;
   var754.b=0;
   var755.b=0;
   var756.b=0;
   var757.b=0;
   var758.b=0;
   var759.b=0;
   var760.b=0;
   var761.b=0;
   var762.b=0;
   var763.b=0;
   var764.b=0;
   var765.b=0;
   var766.b=0;
   var767.b=0;
   var768.b=0;
   var769.b=0;
   var770.b=0;
   var771.b=0;
   var772.b=0;
   var773.b=0;
   var774.b=0;
   var775.b=0;
   var776.b=0;
   var777.b=0;
   var778.b=0;
   var779.b=0;
   var780.b=0;
   var781.b=0;
   var782.b=0;
   var783.b=0;
   var784.b=0;
   var785.b=0;
   var786.b=0;
   var787.b=0;
   var788.b=0;
   var789.b=0;
   var790.b=0;
   var791.b=0;
   var792.b=0;
   var793.b=0;
   var794.b=0;
   var795.b=0;
   var796.b=0;
   var797.b=0;
   var798.b=0;
   var799.b=0;
   var800.b=0;
   var801.b=0;
   var802.b=0;
   var803.b=0;
   var804.b=0;
   var805.b=0;
   var806.b=0;
   var807.b=0;
   var808.b=0;
   var809.b=0;
   var810.b=0;
   var811.b=0;
   var812.b=0;
   var813.b=0;
   var814.b=0;
   var815.b=0;
   var816.b=0;
   var817.b=0;
   var818.b=0;
   var819.b=0;
   var820.l=0L;
   var821.b=0;
   var822.b=0;
   var823.b=0;
   var824.b=0;
   var825.b=0;
   var826.b=0;
   var827.b=0;
   var828.b=0;
   var829.b=0;
   var830.b=0;
   var831.b=0;
   var832.b=0;
   var833.b=0;
   var834.b=0;
   var835.b=0;
   var836.b=0;
   var837.b=0;
   var838.b=0;
   var839.b=0;
   var840.b=0;
   var841.b=0;
   var842.b=0;
   var843.b=0;
   var844.b=0;
   var845.b=0;
   var846.b=0;
   var847.b=0;
   var848.b=0;
   var849.b=0;
   var850.b=0;
   var851.b=0;
   var852.b=0;
   var853.b=0;
   var854.b=0;
   var855.b=0;
   var856.b=0;
   var857.b=0;
   var858.b=0;
   var859.b=0;
   var860.b=0;
   var861.b=0;
   var862.b=0;
   var863.b=0;
   var864.b=0;
   var865.b=0;
   var866.b=0;
   var867.b=0;
   var868.b=0;
   var869.b=0;
   var870.b=0;
   var871.b=0;
   var872.b=0;
   var873.b=0;
   var874.b=0;
   var875.b=0;
   var876.b=0;
   var877.b=0;
   var878.b=0;
   var879.b=0;
   var880.b=0;
   var881.b=0;
   var882.b=0;
   var883.b=0;
   var884.b=0;
   var885.b=0;
   var886.b=0;
   var887.b=0;
   var888.b=0;
   var889.b=0;
   var890.b=0;
   var891.b=0;
   var892.b=0;
   var893.b=0;
   var894.b=0;
   var895.b=0;
   var896.b=0;
   var897.b=0;
   var898.b=0;
   var899.b=0;
   var900.b=0;
   var901.b=0;
   var902.b=0;
   var903.b=0;
   var904.b=0;
   var905.b=0;
   var906.b=0;
   var907.b=0;
   var908.b=0;
   var909.b=0;
   var910.b=0;
   var911.b=0;
   var912.b=0;
   var913.b=0;
   var914.b=0;
   var915.b=0;
   var916.b=0;
   var917.b=0;
   var918.b=0;
   var919.b=0;
   var920.b=0;
   var921.b=0;
   var922.b=0;
   var923.b=0;
   var924.b=0;
   var925.b=0;
   var926.b=0;
   var927.b=0;
   var928.b=0;
   var929.b=0;
   var930.b=0;
   var931.b=0;
   var932.b=0;
   var933.b=0;
   var934.b=0;
   var935.b=0;
   var936.b=0;
   var937.b=0;
   var938.b=0;
   var939.b=0;
   var940.b=0;
   var941.b=0;
   var942.b=0;
   var943.b=0;
   var944.b=0;
   var945.b=0;
   var946.b=0;
   var947.b=0;
   var948.b=0;
   var949.b=0;
   var950.b=0;
   var951.b=0;
   var952.b=0;
   var953.b=0;
   var954.b=0;
   var955.b=0;
   var956.b=0;
   var957.b=0;
   var958.b=0;
   var959.b=0;
   var960.b=0;
   var961.b=0;
   var962.b=0;
   var963.b=0;
   var964.b=0;
   var965.b=0;
   var966.b=0;
   var967.b=0;
   var968.b=0;
   var969.b=0;
   var970.b=0;
   var971.b=0;
   var972.b=0;
   var973.b=0;
   var974.b=0;
   var975.b=0;
   var976.b=0;
   var977.b=0;
   var978.b=0;
   var979.b=0;
   var980.b=0;
   var981.b=0;
   var982.b=0;
   var983.b=0;
   var984.b=0;
   var985.b=0;
   var986.b=0;
   var987.b=0;
   var988.b=0;
   var989.b=0;
   var990.b=0;
   var991.b=0;
   var992.b=0;
   var993.b=0;
   var994.b=0;
   var995.b=0;
   var996.b=0;
   var997.b=0;
   var998.b=0;
   var999.b=0;
   var1000.b=0;
   var1001.b=0;
   var1002.b=0;
   var1003.b=0;
   var1004.b=0;
   var1005.b=0;
   var1006.b=0;
   var1007.b=0;
   var1008.b=0;
   var1009.b=0;
   var1010.b=0;
   var1011.b=0;
   var1012.b=0;
   var1013.b=0;
   var1014.b=0;
   var1015.b=0;
   var1016.b=0;
   var1017.b=0;
   var1018.b=0;
   var1019.b=0;
   var1020.b=0;
   var1021.b=0;
   var1022.b=0;
   var1023.b=0;
   var1024.b=0;
   var1025.b=0;
   var1026.b=0;
   var1027.b=0;
   var1028.b=0;
   var1029.b=0;
   var1030.b=0;
   var1031.b=0;
   var1032.b=0;
   var1033.b=0;
   var1034.b=0;
   var1035.b=0;
   var1036.b=0;
   var1037.b=0;
   var1038.b=0;
   var1039.b=0;
   var1040.b=0;
   var1041.b=0;
   var1042.b=0;
   var1043.b=0;
   var1044.b=0;
   var1045.b=0;
   var1046.b=0;
   var1047.b=0;
   var1048.b=0;
   var1049.b=0;
   var1050.b=0;
   var1051.b=0;
   var1052.b=0;
   var1053.b=0;
   var1054.b=0;
   var1055.b=0;
   var1056.b=0;
   var1057.b=0;
   var1058.b=0;
   var1059.b=0;
   var1060.b=0;
   var1061.b=0;
   var1062.b=0;
   var1063.b=0;
   var1064.b=0;
   var1065.b=0;
   var1066.b=0;
   var1067.b=0;
   var1068.b=0;
   var1069.b=0;
   var1070.b=0;
   var1071.b=0;
   var1072.b=0;
   var1073.b=0;
   var1074.b=0;
   var1075.b=0;
   var1076.b=0;
   var1077.b=0;
   var1078.b=0;
   var1079.b=0;
   var1080.b=0;
   var1081.b=0;
   var1082.b=0;
   var1083.b=0;
   var1084.b=0;
   var1085.b=0;
   var1086.b=0;
   var1087.b=0;
   var1088.b=0;
   var1089.b=0;
   var1090.b=0;
   var1091.b=0;
   var1092.b=0;
   var1093.b=0;
   var1094.b=0;
   var1095.b=0;
   var1096.b=0;
   var1097.b=0;
   var1098.b=0;
   var1099.b=0;
   var1100.b=0;
   var1101.b=0;
   var1102.b=0;
   var1103.b=0;
   var1104.b=0;
   var1105.b=0;
   var1106.b=0;
   var1107.b=0;
   var1108.b=0;
   var1109.b=0;
   var1110.b=0;
   var1111.b=0;
   var1112.b=0;
   var1113.b=0;
   var1114.b=0;
   var1115.b=0;
   var1116.b=0;
   var1117.b=0;
   var1118.b=0;
   var1119.b=0;
   var1120.b=0;
   var1121.b=0;
   var1122.b=0;
   var1123.b=0;
   var1124.b=0;
   var1125.b=0;
   var1126.b=0;
   var1127.b=0;
   var1128.b=0;
   var1129.b=0;
   var1130.b=0;
   var1131.b=0;
   var1132.b=0;
   var1133.b=0;
   var1134.b=0;
   var1135.b=0;
   var1136.b=0;
   var1137.b=0;
   var1138.b=0;
   var1139.b=0;
   var1140.b=0;
   var1141.b=0;
   var1142.b=0;
   var1143.b=0;
   var1144.b=0;
   var1145.b=0;
   var1146.b=0;
   var1147.b=0;
   var1148.b=0;
   var1149.b=0;
   var1150.b=0;
   var1151.b=0;
   var1152.b=0;
   var1153.b=0;
   var1154.b=0;
   var1155.b=0;
   var1156.b=0;
   var1157.b=0;
   var1158.b=0;
   var1159.b=0;
   var1160.b=0;
   var1161.b=0;
   var1162.b=0;
   var1163.b=0;
   var1164.b=0;
   var1165.b=0;
   var1166.b=0;
   var1167.b=0;
   var1168.b=0;
   var1169.b=0;
   var1170.b=0;
   var1171.b=0;
   var1172.b=0;
   var1173.b=0;
   var1174.b=0;
   var1175.b=0;
   var1176.b=0;
   var1177.b=0;
   var1178.b=0;
   var1179.b=0;
   var1180.b=0;
   var1181.b=0;
   var1182.b=0;
   var1183.b=0;
   var1184.b=0;
   var1185.b=0;
   var1186.b=0;
   var1187.b=0;
   var1188.b=0;
   var1189.b=0;
   var1190.b=0;
   var1191.b=0;
   var1192.b=0;
   var1193.b=0;
   var1194.b=0;
   var1195.b=0;
   var1196.b=0;
   var1197.b=0;
   var1198.b=0;
   var1199.b=0;
   var1200.b=0;
   var1201.b=0;
   var1202.b=0;
   var1203.b=0;
   var1204.b=0;
   var1205.b=0;
   var1206.b=0;
   var1207.b=0;
   var1208.b=0;
   var1209.b=0;
   var1210.b=0;
   var1211.b=0;
   var1212.b=0;
   var1213.b=0;
   var1214.b=0;
   var1215.b=0;
   var1216.b=0;
   var1217.b=0;
   var1218.b=0;
   var1219.b=0;
   var1220.b=0;
   var1221.b=0;
   var1222.b=0;
   var1223.b=0;
   var1224.b=0;
   var1225.b=0;
   var1226.b=0;
   var1227.b=0;
   var1228.b=0;
   var1229.b=0;
   var1230.f=0.0;
   var1231.b=0;
   var1232.f=0.0;
   var1233.b=0;
   var1234.f=0.0;
   var1235.b=0;
   var1236.b=0;
   var1237.b=0;
   var1238.b=0;
   var1239.f=0.0;
   var1240.f=0.0;
   var1241.f=0.0;
   var1242.f=0.0;
   var1243.f=0.0;
   var1244.f=0.0;
   var1245.b=0;
   var1246.b=0;
   var1247.b=0;
   var1248.b=0;
   var1249.b=0;
   var1250.b=0;
   var1251.b=0;
   var1252.b=0;
   var1253.b=0;
   var1254.b=0;
   var1255.b=0;
   var1256.b=0;
   var1257.b=0;
   var1258.b=0;
   var1259.b=0;
   var1260.b=0;
   var1261.b=0;
   var1262.b=0;
   var1263.b=0;
   var1264.b=0;
   var1265.b=0;
   var1266.b=0;
   var1267.b=0;
   var1268.b=0;
   var1269.b=0;
   var1270.b=0;
   var1271.b=0;
   var1272.b=0;
   var1273.b=0;
   var1274.b=0;
   var1275.b=0;
   var1276.b=0;
   var1277.b=0;
   var1278.b=0;
   var1279.b=0;
   var1280.b=0;
   var1281.b=0;
   var1282.b=0;
   var1283.b=0;
   var1284.b=0;
   var1285.b=0;
   var1286.b=0;
   var1287.b=0;
   var1288.b=0;
   var1289.b=0;
   var1290.b=0;
   var1291.b=0;
   var1292.b=0;
   var1293.b=0;
   var1294.b=0;
   var1295.b=0;
   var1296.b=0;
   var1297.b=0;
   var1298.b=0;
   var1299.b=0;
   var1300.b=0;
   var1301.b=0;
   var1302.b=0;
   var1303.b=0;
   var1304.i=0;
   var1305.i=0;
   var1306.b=0;
   var1307.b=0;
   var1308.b=0;
   var1309.b=0;
   var1310.b=0;
   var1311.b=0;
   var1312.l=0L;
   var1313.b=0;
   var1314.b=0;
   var1315.b=0;
   var1316.i=0;
   var1317.b=0;
   var1318.b=0;
   var1319.b=0;
   var1320.b=0;
   var1321.b=0;
   var1322.b=0;
   var1323.b=0;
   var1324.b=0;
   var1325.b=0;
   var1326.i=0;
   var1327.i=0;
   var1328.b=0;
   var1329.b=0;
   var1330.b=0;
   var1331.b=0;
   var1332.b=0;
   var1333.b=0;
   var1334.b=0;
   var1335.b=0;
   var1336.b=0;
   var1337.b=0;
   var1338.b=0;
   var1339.b=0;
   var1340.b=0;
   var1341.b=0;
   var1342.b=0;
   var1343.b=0;
   var1344.b=0;
   var1345.b=0;
   var1346.b=0;
   var1347.b=0;
   var1348.b=0;
   var1349.b=0;
   var1350.b=0;
   var1351.b=0;
   var1352.b=0;
   var1353.b=0;
   var1354.b=0;
   var1355.b=0;
   var1356.b=0;
   var1357.b=0;
   var1358.b=0;
   var1359.b=0;
   var1360.b=0;
   var1361.b=0;
   var1362.b=0;
   var1363.b=0;
   var1364.b=0;
   var1365.b=0;
   var1366.b=0;
   var1367.l=0L;
   var1368.b=0;
   var1369.b=0;
   var1370.b=0;
   var1371.b=0;
   var1372.b=0;
   var1373.b=0;
   var1374.b=0;
   var1375.b=0;
   var1376.b=0;
   var1377.b=0;
   var1378.b=0;
   var1379.b=0;
   var1380.b=0;
   var1381.b=0;
   var1382.b=0;
   var1383.b=0;
   var1384.b=0;
   var1385.b=0;
   var1386.f=0.0;
   var1387.b=0;
   var1388.b=0;
   var1389.b=0;
   var1390.b=0;
   var1391.b=0;
   var1392.f=0.0;
   var1393.b=0;
   var1394.b=0;
   var1395.b=0;
   var1396.b=0;
   var1397.b=0;
   var1398.b=0;
   var1399.b=0;
   var1400.b=0;
   var1401.b=0;
   var1402.b=0;
   var1403.b=0;
   var1404.b=0;
   var1405.b=0;
   var1406.i=0;
   var1407.b=0;
   var1408.b=0;
   var1409.b=0;
   var1410.b=0;
   var1411.b=0;
   var1412.b=0;
   var1413.b=0;
   var1414.b=0;
   var1415.b=0;
   var1416.b=0;
   var1417.b=0;
   var1418.b=0;
   var1419.b=0;
   var1420.b=0;
   var1421.b=0;
   var1422.b=0;
   var1423.b=0;
   var1424.b=0;
   var1425.b=0;
   var1426.b=0;
   var1427.b=0;
   var1428.b=0;
   var1429.b=0;
   var1430.b=0;
   var1431.f=0.0;
   var1432.b=0;
   var1433.b=0;
   var1434.b=0;
   var1435.b=0;
   var1436.b=0;
   var1437.b=0;
   var1438.b=0;
   var1439.b=0;
   var1440.b=0;
   var1441.b=0;
   var1442.b=0;
   var1443.b=0;
   var1444.b=0;
   var1445.b=0;
   var1446.b=0;
   var1447.b=0;
   var1448.b=0;
   var1449.b=0;
   var1450.b=0;
   var1451.b=0;
   var1452.b=0;
   var1453.b=0;
   var1454.b=0;
   var1455.b=0;
   var1456.b=0;
   var1457.b=0;
   var1458.b=0;
   var1459.b=0;
   var1460.b=0;
   var1461.b=0;
   var1462.b=0;
   var1463.b=0;
   var1464.b=0;
   var1465.b=0;
   var1466.b=0;
   var1467.b=0;
   var1468.b=0;
   var1469.b=0;
   var1470.b=0;
   var1471.b=0;
   var1472.b=0;
   var1473.b=0;
   var1474.b=0;
   var1475.b=0;
   var1476.b=0;
   var1477.b=0;
   var1478.b=0;
   var1479.b=0;
   var1480.b=0;
   var1481.b=0;
   var1482.b=0;
   var1483.b=0;
   var1484.b=0;
   var1485.b=0;
   var1486.b=0;
   var1487.b=0;
   var1488.b=0;
   var1489.b=0;
   var1490.b=0;
   var1491.b=0;
   var1492.b=0;
   var1493.b=0;
   var1494.b=0;
   var1495.b=0;
   var1496.b=0;
   var1497.b=0;
   var1498.b=0;
   var1499.b=0;
   var1500.b=0;
   var1501.b=0;
   var1502.b=0;
   var1503.b=0;
   var1504.b=0;
   var1505.b=0;
   var1506.b=0;
   var1507.b=0;
   var1508.b=0;
   var1509.b=0;
   var1510.b=0;
   var1511.b=0;
   var1512.b=0;
   var1513.b=0;
   var1514.b=0;
   var1515.b=0;
   var1516.b=0;
   var1517.b=0;
   var1518.b=0;
   var1519.b=0;
   var1520.b=0;
   var1521.b=0;
   var1522.b=0;
   var1523.b=0;
   var1524.b=0;
   var1525.l=0L;
   var1526.b=0;
   var1527.i=0;
   var1528.i=0;
   var1529.b=0;
   var1530.f=0.0;
   var1531.f=0.0;
   var1532.f=0.0;
   var1533.b=0;
   var1534.b=0;
   var1535.b=0;
   var1536.b=0;
   var1537.b=0;
   var1538.b=0;
   var1539.b=0;
   var1540.b=0;
   var1541.b=0;
   var1542.b=0;
   var1543.b=0;
   var1544.b=0;
   var1545.b=0;
   var1546.b=0;
   var1547.b=0;
   var1548.b=0;
   var1549.i=0;
   var1550.b=0;
   var1551.c=0;
   var1552.i=0;
   var1553.b=0;
   var1554.f=0.0;
   var1555.b=0;
   var1556.b=0;
   var1557.b=0;
   var1558.b=0;
   var1559.b=0;
   var1560.b=0;
   var1561.b=0;
   var1562.f=0.0;
   var1563.c=0;
   var1564.b=0;
   var1565.b=0;
   var1566.b=0;
   var1567.b=0;
   var1568.f=0.0;
   var1569.b=0;
   var1570.b=0;
   var1571.b=0;
   var1572.b=0;
   var1573.b=0;
   var1574.b=0;
   var1575.b=0;
   var1576.b=0;
   var1577.b=0;
   var1578.b=0;
   var1579.b=0;
   var1580.b=0;
   var1581.i=0;
   var1582.b=0;
   var1583.c=0;
   var1584.i=0;
   var1585.b=0;
   var1586.f=0.0;
   var1587.b=0;
   var1588.b=0;
   var1589.b=0;
   var1590.b=0;
   var1591.b=0;
   var1592.b=0;
   var1593.b=0;
   var1594.f=0.0;
   var1595.c=0;
   var1596.b=0;
   var1597.b=0;
   var1598.b=0;
   var1599.b=0;
   var1600.f=0.0;
   var1601.b=0;
   var1602.b=0;
   var1603.b=0;
   var1604.b=0;
   var1605.b=0;
   var1606.b=0;
   var1607.b=0;
   var1608.b=0;
   var1609.b=0;
   var1610.i=0;
   var1611.b=0;
   var1612.c=0;
   var1613.i=0;
   var1614.b=0;
   var1615.f=0.0;
   var1616.b=0;
   var1617.b=0;
   var1618.b=0;
   var1619.b=0;
   var1620.b=0;
   var1621.b=0;
   var1622.b=0;
   var1623.f=0.0;
   var1624.c=0;
   var1625.b=0;
   var1626.b=0;
   var1627.b=0;
   var1628.b=0;
   var1629.f=0.0;
   var1630.b=0;
   var1631.b=0;
   var1632.b=0;
   var1633.b=0;
   var1634.b=0;
   var1635.b=0;
   var1636.b=0;
   var1637.b=0;
   var1638.b=0;
   var1639.b=0;
   var1640.b=0;
   var1641.b=0;
   var1642.b=0;
   var1643.i=0;
   var1644.b=0;
   var1645.c=0;
   var1646.i=0;
   var1647.b=0;
   var1648.f=0.0;
   var1649.b=0;
   var1650.b=0;
   var1651.b=0;
   var1652.b=0;
   var1653.b=0;
   var1654.b=0;
   var1655.b=0;
   var1656.f=0.0;
   var1657.c=0;
   var1658.b=0;
   var1659.b=0;
   var1660.f=0.0;
   var1661.b=0;
   var1662.b=0;
   var1663.b=0;
   var1664.b=0;
   var1665.b=0;
   var1666.b=0;
   var1667.b=0;
   var1668.b=0;
   var1669.b=0;
   var1670.b=0;
   var1671.b=0;
   var1672.b=0;
   var1673.i=0;
   var1674.b=0;
   var1675.b=0;
   var1676.b=0;
   var1677.b=0;
   var1678.b=0;
   var1679.b=0;
   var1680.b=0;
   var1681.b=0;
   var1682.i=0;
   var1683.b=0;
   var1684.b=0;
   var1685.b=0;
   var1686.b=0;
   var1687.b=0;
   var1688.b=0;
   var1689.b=0;
   var1690.i=0;
   var1691.b=0;
   var1692.c=0;
   var1693.i=0;
   var1694.b=0;
   var1695.f=0.0;
   var1696.b=0;
   var1697.b=0;
   var1698.b=0;
   var1699.b=0;
   var1700.b=0;
   var1701.b=0;
   var1702.b=0;
   var1703.f=0.0;
   var1704.c=0;
   var1705.b=0;
   var1706.b=0;
   var1707.f=0.0;
   var1708.b=0;
   var1709.b=0;
   var1710.b=0;
   var1711.b=0;
   var1712.b=0;
   var1713.b=0;
   var1714.b=0;
   var1715.b=0;
   var1716.c=0;
   var1717.b=0;
   var1718.b=0;
   var1719.b=0;
   var1720.b=0;
   var1721.b=0;
   var1722.b=0;
   var1723.b=0;
   var1724.b=0;
   var1725.b=0;
   var1726.c=0;
   var1727.b=0;
   var1728.b=0;
   var1729.i=0;
   var1730.b=0;
   var1731.c=0;
   var1732.b=0;
   var1733.i=0;
   var1734.b=0;
   var1735.b=0;
   var1736.f=0.0;
   var1737.b=0;
   var1738.b=0;
   var1739.b=0;
   var1740.b=0;
   var1741.b=0;
   var1742.b=0;
   var1743.b=0;
   var1744.f=0.0;
   var1745.c=0;
   var1746.b=0;
   var1747.b=0;
   var1748.b=0;
   var1749.b=0;
   var1750.f=0.0;
   var1751.b=0;
   var1752.b=0;
   var1753.b=0;
   var1754.b=0;
   var1755.b=0;
   var1756.b=0;
   var1757.b=0;
   var1758.b=0;
   var1759.b=0;
   var1760.b=0;
   var1761.b=0;
   var1762.b=0;
   var1763.f=0.0;
   var1764.b=0;
   var1765.b=0;
   var1766.b=0;
   var1767.b=0;
   var1768.b=0;
   var1769.b=0;
   var1770.b=0;
   var1771.b=0;
   var1772.b=0;
   var1773.b=0;
   var1774.b=0;
   var1775.b=0;
   var1776.b=0;
   var1777.b=0;
   var1778.b=0;
   var1779.b=0;
   var1780.f=0.0;
   var1781.b=0;
   var1782.b=0;
   var1783.b=0;
   var1784.b=0;
   var1785.b=0;
   var1786.b=0;
   var1787.b=0;
   var1788.b=0;
   var1789.b=0;
   var1790.b=0;
   var1791.b=0;
   var1792.b=0;
   var1793.b=0;
   var1794.b=0;
   var1795.b=0;
   var1796.b=0;
   var1797.b=0;
   var1798.b=0;
   var1799.b=0;
   var1800.b=0;
   var1801.b=0;
   var1802.b=0;
   var1803.b=0;
   var1804.b=0;
   var1805.b=0;
   var1806.b=0;
   var1807.b=0;
   var1808.b=0;
   var1809.b=0;
   var1810.b=0;
   var1811.b=0;
   var1812.b=0;
   var1813.b=0;
   var1814.b=0;
   var1815.b=0;
   var1816.b=0;
   var1817.b=0;
   var1818.i=0;
   var1819.b=0;
   var1820.b=0;
   var1821.b=0;
   var1822.b=0;
   var1823.b=0;
   var1824.b=0;
   var1825.b=0;
   var1826.b=0;
   var1827.i=0;
   var1828.b=0;
   var1829.b=0;
   var1830.b=0;
   var1831.b=0;
   var1832.b=0;
   var1833.b=0;
   var1834.b=0;
   var1835.b=0;
   var1836.i=0;
   var1837.b=0;
   var1838.b=0;
   var1839.b=0;
   var1840.b=0;
   var1841.b=0;
   var1842.b=0;
   var1843.b=0;
   var1844.b=0;
   var1845.i=0;
   var1846.b=0;
   var1847.b=0;
   var1848.b=0;
   var1849.b=0;
   var1850.b=0;
   var1851.b=0;
   var1852.b=0;
   var1853.b=0;
   var1854.i=0;
   var1855.b=0;
   var1856.b=0;
   var1857.b=0;
   var1858.b=0;
   var1859.b=0;
   var1860.b=0;
   var1861.b=0;
   var1862.b=0;
   var1863.i=0;
   var1864.b=0;
   var1865.b=0;
   var1866.b=0;
   var1867.b=0;
   var1868.b=0;
   var1869.b=0;
   var1870.b=0;
   var1871.b=0;
   var1872.i=0;
   var1873.b=0;
   var1874.b=0;
   var1875.b=0;
   var1876.b=0;
   var1877.b=0;
   var1878.b=0;
   var1879.b=0;
   var1880.b=0;
   var1881.b=0;
   var1882.b=0;
   var1883.b=0;
   var1884.b=0;
   var1885.b=0;
   var1886.b=0;
   var1887.b=0;
   var1888.b=0;
   var1889.b=0;
   var1890.b=0;
   var1891.b=0;
   var1892.b=0;
   var1893.b=0;
   var1894.b=0;
   var1895.b=0;
   var1896.b=0;
   var1897.b=0;
   var1898.b=0;
   var1899.b=0;
   var1900.b=0;
   var1901.b=0;
   var1902.b=0;
   var1903.b=0;
   var1904.b=0;
   var1905.b=0;
   var1906.b=0;
   var1907.b=0;
   var1908.b=0;
   var1909.b=0;
   var1910.b=0;
   var1911.b=0;
   var1912.b=0;
   var1913.b=0;
   var1914.b=0;
   var1915.b=0;
   var1916.b=0;
   var1917.b=0;
   var1918.b=0;
   var1919.b=0;
   var1920.b=0;
   var1921.f=0.0;
   var1922.b=0;
   var1923.b=0;
   var1924.b=0;
   var1925.b=0;
   var1926.b=0;
   var1927.b=0;
   var1928.b=0;
   var1929.b=0;
   var1930.b=0;
   var1931.b=0;
   var1932.b=0;
   var1933.b=0;
   var1934.b=0;
   var1935.b=0;
   var1936.b=0;
   var1937.b=0;
   var1938.b=0;
   var1939.b=0;
   var1940.b=0;
   var1941.b=0;
   var1942.b=0;
   var1943.b=0;
   var1944.b=0;
   var1945.b=0;
   var1946.b=0;
   var1947.b=0;
   var1948.b=0;
   var1949.b=0;
   var1950.b=0;
   var1951.b=0;
   var1952.b=0;
   var1953.b=0;
   var1954.b=0;
   var1955.b=0;
   var1956.f=0.0;
   var1957.f=0.0;
   var1958.b=0;
   var1959.b=0;
   var1960.b=0;
   var1961.b=0;
   var1962.b=0;
   var1963.b=0;
   var1964.b=0;
   var1965.b=0;
   var1966.b=0;
   var1967.b=0;
   var1968.b=0;
   var1969.b=0;
   var1970.b=0;
   var1971.b=0;
   var1972.b=0;
   var1973.b=0;
   var1974.b=0;
   var1975.b=0;
   var1976.b=0;
   var1977.b=0;
   var1978.b=0;
   var1979.b=0;
   var1980.b=0;
   var1981.b=0;
   var1982.b=0;
   var1983.b=0;
   var1984.f=0.0;
   var1985.b=0;
   var1986.b=0;
   var1987.f=0.0;
   var1988.b=0;
   var1989.b=0;
   var1990.f=0.0;
   var1991.b=0;
   var1992.b=0;
   var1993.f=0.0;
   var1994.b=0;
   var1995.b=0;
   var1996.f=0.0;
   var1997.b=0;
   var1998.b=0;
   var1999.f=0.0;
   var2000.b=0;
   var2001.b=0;
   var2002.f=0.0;
   var2003.b=0;
   var2004.b=0;
   var2005.b=0;
   var2006.f=0.0;
   var2007.b=0;
   var2008.b=0;
   var2009.b=0;
   vainSLong.l=0L;
   vainSFloat.f=0.0;
   vainSInt.i=0;
   vainSBool.b=0;
   vainSChar.c=0;

}
int freebuff = 0, delay = 0;
void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  equz_p(&S_equz_p_19_2);
  scalzz(&S_scalzz_193_2);
  scalzz(&S_scalzz_195_2);
  or2(&S_or2_11_2);
  or2(&S_or2_42_2);
  or2(&S_or2_13_2);
  or2(&S_or2_43_2);
  or2(&S_or2_74_2);
  or2(&S_or2_71_2);
  and3(&S_and3_79_2);
  or2(&S_or2_103_2);
  or2(&S_or2_104_2);
  and3(&S_and3_111_2);
  and4(&S_and4_136_2);
  and4(&S_and4_162_2);
  schl24(&S_schl24_147_2);
  schl24(&S_schl24_151_2);
  noto(&S_noto_240_2);
  noto(&S_noto_241_2);
  noto(&S_noto_242_2);
  noto(&S_noto_260_2);
  noto(&S_noto_261_2);
  noto(&S_noto_262_2);
  fsumo(&S_fsumo_233_2);
  bol(&S_bol_234_2);
  lkb(&S_lkb_80_2);
  lkb(&S_lkb_112_2);
  and4(&S_and4_108_2);
  zzfs(&S_zzfs_127_2);
  zzfs(&S_zzfs_132_2);
  zzfs(&S_zzfs_134_2);
  zzfs(&S_zzfs_141_2);
  zzfs(&S_zzfs_144_2);
  zzfs(&S_zzfs_149_2);
  zzfs(&S_zzfs_155_2);
  zzfs(&S_zzfs_158_2);
  zzfs(&S_zzfs_165_2);
  zzfs(&S_zzfs_173_2);
  zzfs(&S_zzfs_176_2);
  zzfs(&S_zzfs_182_2);
  enctkb(&S_enctkb_75_2);
  enctkb(&S_enctkb_106_2);
  drg(&S_drg_205_2);
  drg(&S_drg_198_2);
  geterr(&S_geterr_197_2);
  drg(&S_drg_214_2);
  drg(&S_drg_208_2);
  geterr(&S_geterr_200_2);
  tprg(&S_tprg_220_2);
  tprg(&S_tprg_228_2);
  noto(&S_noto_231_2);
  noto(&S_noto_222_2);
  andn(&S_andn_138_2);
  noto(&S_noto_145_2);
  andn(&S_andn_166_2);
  noto(&S_noto_177_2);
  andn(&S_andn_179_2);
  noto(&S_noto_180_2);
  and2(&S_and2_230_2);
  and3(&S_and3_20_2);
  and3(&S_and3_47_2);
  and3(&S_and3_23_2);
  and3(&S_and3_51_2);
  and3(&S_and3_82_2);
  or3(&S_or3_135_2);
  or3(&S_or3_161_2);
  and2(&S_and2_223_2);
  or2(&S_or2_203_2);
  or2(&S_or2_207_2);
  lkb(&S_lkb_21_2);
  lkb(&S_lkb_24_2);
  lkb(&S_lkb_48_2);
  lkb(&S_lkb_83_2);
  lkb(&S_lkb_52_2);
  lkb(&S_lkb_109_2);
  enctkb(&S_enctkb_15_2);
  enctkb(&S_enctkb_53_2);
  enctkb(&S_enctkb_49_2);
  enctkb(&S_enctkb_77_2);
  enctkb(&S_enctkb_110_2);
  enctkb(&S_enctkb_17_2);
  noto(&S_noto_142_2);
  noto(&S_noto_160_2);
  and2(&S_and2_244_2);
  and2(&S_and2_265_2);
  ornc(&S_ornc_124_2);
  ornc(&S_ornc_245_2);
  ornc(&S_ornc_266_2);
  noto(&S_noto_251_2);
  noto(&S_noto_267_2);
  or2(&S_or2_269_2);
  ornc(&S_ornc_243_2);
  ornc(&S_ornc_254_2);
  noto(&S_noto_246_2);
  noto(&S_noto_264_2);
  or2(&S_or2_255_2);
  setData(idR0EE02LDU,&var1067);
  setData(idB8VC01RDU,&var1987);
  setData(idB2VC01RDU,&var1999);
  setData(idA2VC01RDU,&var2002);
  setData(idA3VC01RDU,&var1996);
  setData(idB0VS11LDU,&var1964);
  setData(idA0VS11LDU,&var1965);
  setData(idB0VN01LDU,&var1934);
  setData(idA0VN01LDU,&var1936);
  setData(idB0VP01LDU,&var1970);
  setData(idA0VP01LDU,&var1971);
  setData(idB0VE01LDU,&var1961);
  setData(idA0VE01LDU,&var1963);
  setData(idA3VP82LDU,&var1932);
  setData(idB3VP82LDU,&var1955);
  setData(idB3VP52LDU,&var1980);
  setData(idB3CP02RDU,&var1956);
  setData(idB3VP42LDU,&var1930);
  setData(idA3VP52LDU,&var1983);
  setData(idA3CP02RDU,&var1957);
  setData(idA3VP42LDU,&var1931);
  setData(idA1VC01RDU,&var1984);
  setData(idA8VC01RDU,&var1990);
  setData(idB3VC01RDU,&var1993);
  setData(idB1VC01RDU,&var2006);
  equz_p(&S_equz_p_4_1);
  equz_p(&S_equz_p_2_1);
  equz_p(&S_equz_p_7_1);
  equz_p(&S_equz_p_10_1);
  equz_p(&S_equz_p_97_1);
  equz_p(&S_equz_p_98_1);
  equz_p(&S_equz_p_99_1);
  equz_p(&S_equz_p_106_1);
  equz_p(&S_equz_p_47_1);
  equz_p(&S_equz_p_43_1);
  equz_p(&S_equz_p_51_1);
  equz_p(&S_equz_p_60_1);
  equz_p(&S_equz_p_57_1);
  equz_p(&S_equz_p_64_1);
  equz_p(&S_equz_p_68_1);
  equz_p(&S_equz_p_71_1);
  equz_p(&S_equz_p_72_1);
  equz_p(&S_equz_p_76_1);
  equz_p(&S_equz_p_77_1);
  equz_p(&S_equz_p_80_1);
  noto(&S_noto_152_1);
  noto(&S_noto_151_1);
  noto(&S_noto_162_1);
  noto(&S_noto_836_1);
  noto(&S_noto_803_1);
  noto(&S_noto_1250_1);
  noto(&S_noto_1781_1);
  noto(&S_noto_1433_1);
  noto(&S_noto_955_1);
  noto(&S_noto_233_1);
  noto(&S_noto_599_1);
  noto(&S_noto_1066_1);
  rs(&S_rs_693_1);
  noto(&S_noto_1539_1);
  equz_p(&S_equz_p_32_1);
  equz_p(&S_equz_p_41_1);
  noto(&S_noto_34_1);
  equz_p(&S_equz_p_37_1);
  noto(&S_noto_1994_1);
  noto(&S_noto_1993_1);
  noto(&S_noto_1999_1);
  noto(&S_noto_1995_1);
  noto(&S_noto_2001_1);
  noto(&S_noto_1972_1);
  noto(&S_noto_1973_1);
  noto(&S_noto_1974_1);
  noto(&S_noto_1975_1);
  noto(&S_noto_1976_1);
  noto(&S_noto_2289_1);
  equz_p(&S_equz_p_100_1);
  equz_p(&S_equz_p_101_1);
  equz_p(&S_equz_p_102_1);
  noto(&S_noto_1034_1);
  equz_p(&S_equz_p_103_1);
  equz_p(&S_equz_p_104_1);
  noto(&S_noto_186_1);
  equz_p(&S_equz_p_105_1);
  noto(&S_noto_12_1);
  equz_p(&S_equz_p_2016_1);
  equz_p(&S_equz_p_2015_1);
  equz_p(&S_equz_p_2017_1);
  equz_p(&S_equz_p_2018_1);
  equz_p(&S_equz_p_2019_1);
  noto(&S_noto_1981_1);
  noto(&S_noto_2034_1);
  noto(&S_noto_2053_1);
  rs(&S_rs_683_1);
  noto(&S_noto_2013_1);
  noto(&S_noto_2039_1);
  noto(&S_noto_1506_1);
  rsun(&S_rsun_1598_1);
  rs(&S_rs_685_1);
  rs(&S_rs_687_1);
  rs(&S_rs_703_1);
  rs(&S_rs_719_1);
  rs(&S_rs_692_1);
  rs(&S_rs_707_1);
  rs(&S_rs_26_1);
  noto(&S_noto_2112_1);
  noto(&S_noto_2080_1);
  noto(&S_noto_1705_1);
  orni(&S_orni_310_1);
  noto(&S_noto_654_1);
  noto(&S_noto_22_1);
  noto(&S_noto_23_1);
  noto(&S_noto_24_1);
  noto(&S_noto_25_1);
  noto(&S_noto_657_1);
  noto(&S_noto_655_1);
  noto(&S_noto_50_1);
  noto(&S_noto_284_1);
  noto(&S_noto_287_1);
  noto(&S_noto_296_1);
  noto(&S_noto_302_1);
  noto(&S_noto_292_1);
  noto(&S_noto_1110_1);
  noto(&S_noto_1116_1);
  orni(&S_orni_356_1);
  noto(&S_noto_2146_1);
  noto(&S_noto_2148_1);
  ovbs(&S_ovbs_1336_1);
  ovbs(&S_ovbs_2316_1);
  sr(&S_sr_1188_1);
  bol(&S_bol_1181_1);
  ma(&S_ma_90_1);
  sr(&S_sr_88_1);
  bol(&S_bol_281_1);
  bol(&S_bol_277_1);
  bol(&S_bol_1578_1);
  bol(&S_bol_1576_1);
  bol(&S_bol_1107_1);
  bol(&S_bol_1100_1);
  bol(&S_bol_640_1);
  bol(&S_bol_646_1);
  bol(&S_bol_653_1);
  bol(&S_bol_659_1);
  and2(&S_and2_824_1);
  and2(&S_and2_27_1);
  and2(&S_and2_28_1);
  and2(&S_and2_29_1);
  and2(&S_and2_30_1);
  and2(&S_and2_42_1);
  and2(&S_and2_38_1);
  and2(&S_and2_815_1);
  or4(&S_or4_458_1);
  or2(&S_or2_828_1);
  or3(&S_or3_5_1);
  or2(&S_or2_6_1);
  or2(&S_or2_1449_1);
  or2(&S_or2_971_1);
  or2(&S_or2_250_1);
  or2(&S_or2_616_1);
  or2(&S_or2_1081_1);
  or2(&S_or2_1554_1);
  or2(&S_or2_1187_1);
  and2(&S_and2_1180_1);
  or2(&S_or2_20_1);
  or2(&S_or2_39_1);
  or2(&S_or2_35_1);
  or2(&S_or2_49_1);
  or2(&S_or2_767_1);
  or3(&S_or3_752_1);
  or4(&S_or4_769_1);
  or2(&S_or2_786_1);
  or3(&S_or3_812_1);
  and2(&S_and2_835_1);
  and2(&S_and2_809_1);
  or2(&S_or2_819_1);
  or2(&S_or2_732_1);
  or2(&S_or2_734_1);
  or2(&S_or2_736_1);
  or2(&S_or2_1310_1);
  or2(&S_or2_1337_1);
  or2(&S_or2_1191_1);
  and2(&S_and2_1206_1);
  or2(&S_or2_1246_1);
  and3(&S_and3_285_1);
  and3(&S_and3_301_1);
  or2(&S_or2_676_1);
  or2(&S_or2_684_1);
  or2(&S_or2_686_1);
  or2(&S_or2_689_1);
  or2(&S_or2_660_1);
  and2(&S_and2_710_1);
  or2(&S_or2_717_1);
  and2(&S_and2_681_1);
  or2(&S_or2_696_1);
  or2(&S_or2_691_1);
  or2(&S_or2_714_1);
  and2(&S_and2_671_1);
  or2(&S_or2_368_1);
  or2(&S_or2_373_1);
  or2(&S_or2_833_1);
  or2(&S_or2_510_1);
  and2(&S_and2_585_1);
  and2(&S_and2_586_1);
  and2(&S_and2_598_1);
  or2(&S_or2_588_1);
  and2(&S_and2_184_1);
  and2(&S_and2_220_1);
  and2(&S_and2_219_1);
  or2(&S_or2_222_1);
  and2(&S_and2_232_1);
  or2(&S_or2_874_1);
  or2(&S_or2_941_1);
  and2(&S_and2_1027_1);
  or2(&S_or2_1038_1);
  or2(&S_or2_1053_1);
  or2(&S_or2_1528_1);
  and2(&S_and2_1499_1);
  or2(&S_or2_1512_1);
  or2(&S_or2_1420_1);
  and2(&S_and2_1115_1);
  or3(&S_or3_1627_1);
  or3(&S_or3_1667_1);
  or3(&S_or3_1683_1);
  or2(&S_or2_2317_1);
  or2(&S_or2_1836_1);
  or2(&S_or2_1837_1);
  or2(&S_or2_1777_1);
  or2(&S_or2_1979_1);
  or2(&S_or2_1980_1);
  or4(&S_or4_1986_1);
  or4(&S_or4_1987_1);
  or2(&S_or2_1989_1);
  or2(&S_or2_1983_1);
  or2(&S_or2_1982_1);
  or3(&S_or3_1991_1);
  and2(&S_and2_2020_1);
  or2(&S_or2_2021_1);
  and2(&S_and2_2027_1);
  and2(&S_and2_2043_1);
  or2(&S_or2_2054_1);
  zpfs(&S_zpfs_2023_1);
  zpfs(&S_zpfs_2024_1);
  zpfs(&S_zpfs_2025_1);
  zpfs(&S_zpfs_2026_1);
  or2(&S_or2_2029_1);
  and2(&S_and2_2030_1);
  or2(&S_or2_2045_1);
  or3(&S_or3_2031_1);
  or3(&S_or3_2095_1);
  ma(&S_ma_1665_1);
  or3(&S_or3_2067_1);
  or2(&S_or2_253_1);
  ovbs(&S_ovbs_82_1);
  ovbs(&S_ovbs_21_1);
  ovbs(&S_ovbs_127_1);
  ovbs(&S_ovbs_120_1);
  ovbs(&S_ovbs_1623_1);
  ovbs(&S_ovbs_831_1);
  ovbs(&S_ovbs_317_1);
  ovbs(&S_ovbs_364_1);
  ovbs(&S_ovbs_52_1);
  or2(&S_or2_2211_1);
  or2(&S_or2_2199_1);
  noto(&S_noto_2230_1);
  bol(&S_bol_1759_1);
  bol(&S_bol_1752_1);
  or2(&S_or2_1755_1);
  bol(&S_bol_1740_1);
  bol(&S_bol_1733_1);
  or2(&S_or2_1739_1);
  bol(&S_bol_1761_1);
  bol(&S_bol_1753_1);
  or2(&S_or2_1757_1);
  bol(&S_bol_1745_1);
  bol(&S_bol_1734_1);
  or2(&S_or2_1743_1);
  and4(&S_and4_46_1);
  abs_subf(&S_abs_subf_1750_1);
  noto(&S_noto_1756_1);
  and2(&S_and2_252_1);
  and2(&S_and2_617_1);
  and2(&S_and2_2472_1);
  rs(&S_rs_2422_1);
  sr(&S_sr_2437_1);
  rs(&S_rs_2416_1);
  zpfs(&S_zpfs_2444_1);
  or2(&S_or2_2432_1);
  abs_subf(&S_abs_subf_2397_1);
  and2(&S_and2_2404_1);
  noto(&S_noto_1004_1);
  or2(&S_or2_2457_1);
  zzfs(&S_zzfs_2405_1);
  noto(&S_noto_2417_1);
  or2(&S_or2_389_1);
  or2(&S_or2_376_1);
  or2(&S_or2_1266_1);
  or2(&S_or2_1269_1);
  or2(&S_or2_248_1);
  or2(&S_or2_614_1);
  nocnm(&S_nocnm_1930_1);
  nocnm(&S_nocnm_1931_1);
  noto(&S_noto_1888_1);
  noto(&S_noto_1889_1);
  noto(&S_noto_2390_1);
  noto(&S_noto_2359_1);
  noto(&S_noto_2392_1);
  noto(&S_noto_2361_1);
  noto(&S_noto_114_1);
  and2(&S_and2_811_1);
  and2(&S_and2_813_1);
  or2(&S_or2_135_1);
  noto(&S_noto_1948_1);
  noto(&S_noto_1949_1);
  or2(&S_or2_1912_1);
  or2(&S_or2_1952_1);
  or2(&S_or2_1955_1);
  or2(&S_or2_1923_1);
  or2(&S_or2_1926_1);
  or2(&S_or2_1885_1);
  or2(&S_or2_1859_1);
  or2(&S_or2_1855_1);
  or2(&S_or2_2385_1);
  or2(&S_or2_2389_1);
  or2(&S_or2_2387_1);
  or2(&S_or2_2354_1);
  or2(&S_or2_2356_1);
  or2(&S_or2_2358_1);
  or2(&S_or2_1877_1);
  or2(&S_or2_1910_1);
  or2(&S_or2_2525_1);
  or2(&S_or2_2531_1);
  ovbsb(&S_ovbsb_225_1);
  ovbsb(&S_ovbsb_226_1);
  ovbsb(&S_ovbsb_237_1);
  ovbsb(&S_ovbsb_251_1);
  ovbsb(&S_ovbsb_593_1);
  ovbsb(&S_ovbsb_590_1);
  ovbsb(&S_ovbsb_603_1);
  ovbsb(&S_ovbsb_622_1);
  ovbsb(&S_ovbsb_2466_1);
  ovbsb(&S_ovbsb_391_1);
  and2(&S_and2_1601_1);
  and2(&S_and2_1621_1);
  and2(&S_and2_1605_1);
  and2(&S_and2_1614_1);
  and2(&S_and2_1609_1);
  noto(&S_noto_58_1);
  or2(&S_or2_1225_1);
  zzfs(&S_zzfs_2548_1);
  zzfs(&S_zzfs_2558_1);
  noto(&S_noto_750_1);
  noto(&S_noto_160_1);
  rs(&S_rs_816_1);
  noto(&S_noto_459_1);
  noto(&S_noto_730_1);
  noto(&S_noto_793_1);
  rs(&S_rs_827_1);
  noto(&S_noto_845_1);
  vmemb(&S_vmemb_737_1);
  vmemb(&S_vmemb_794_1);
  noto(&S_noto_834_1);
  vmemb(&S_vmemb_826_1);
  rs(&S_rs_698_1);
  rs(&S_rs_708_1);
  rs(&S_rs_688_1);
  noto(&S_noto_675_1);
  rs(&S_rs_716_1);
  noto(&S_noto_283_1);
  noto(&S_noto_711_1);
  noto(&S_noto_645_1);
  noto(&S_noto_1106_1);
  noto(&S_noto_1580_1);
  noto(&S_noto_1129_1);
  rs(&S_rs_1675_1);
  noto(&S_noto_83_1);
  samhd(&S_samhd_2315_1);
  samhd(&S_samhd_2321_1);
  newstage(&S_newstage_2319_1);
  noto(&S_noto_1992_1);
  noto(&S_noto_1998_1);
  noto(&S_noto_2000_1);
  noto(&S_noto_1971_1);
  noto(&S_noto_2109_1);
  noto(&S_noto_2101_1);
  noto(&S_noto_559_1);
  noto(&S_noto_1376_1);
  noto(&S_noto_1393_1);
  noto(&S_noto_2041_1);
  rs(&S_rs_1680_1);
  rs(&S_rs_1632_1);
  rs(&S_rs_2096_1);
  rs(&S_rs_2071_1);
  noto(&S_noto_1628_1);
  noto(&S_noto_1668_1);
  noto(&S_noto_1676_1);
  noto(&S_noto_2065_1);
  noto(&S_noto_2092_1);
  cntch(&S_cntch_313_1);
  rs(&S_rs_832_1);
  noto(&S_noto_370_1);
  noto(&S_noto_366_1);
  noto(&S_noto_656_1);
  noto(&S_noto_666_1);
  noto(&S_noto_718_1);
  cntch(&S_cntch_360_1);
  noto(&S_noto_2130_1);
  noto(&S_noto_2155_1);
  swtakt(&S_swtakt_2068_1);
  swtakt(&S_swtakt_1684_1);
  swtakt(&S_swtakt_1681_1);
  swtakt(&S_swtakt_1633_1);
  rs(&S_rs_1196_1);
  and2(&S_and2_842_1);
  and2(&S_and2_11_1);
  and2(&S_and2_119_1);
  and2(&S_and2_247_1);
  and2(&S_and2_613_1);
  or2(&S_or2_14_1);
  or2(&S_or2_8_1);
  or2(&S_or2_174_1);
  and3(&S_and3_784_1);
  and2(&S_and2_747_1);
  or3(&S_or3_822_1);
  and2(&S_and2_817_1);
  and2(&S_and2_726_1);
  or2(&S_or2_291_1);
  and3(&S_and3_307_1);
  or2(&S_or2_709_1);
  and2(&S_and2_678_1);
  and2(&S_and2_668_1);
  and4(&S_and4_669_1);
  and4(&S_and4_679_1);
  and2(&S_and2_704_1);
  or2(&S_or2_712_1);
  or2(&S_or2_715_1);
  and3(&S_and3_361_1);
  and2(&S_and2_555_1);
  or2(&S_or2_561_1);
  and2(&S_and2_626_1);
  and2(&S_and2_641_1);
  or2(&S_or2_190_1);
  and2(&S_and2_263_1);
  and2(&S_and2_278_1);
  and2(&S_and2_1101_1);
  and2(&S_and2_1577_1);
  and2(&S_and2_1375_1);
  or2(&S_or2_1381_1);
  and2(&S_and2_1388_1);
  or2(&S_or2_1400_1);
  and2(&S_and2_1124_1);
  and2(&S_and2_1134_1);
  and2(&S_and2_1629_1);
  or2(&S_or2_1686_1);
  zpfs(&S_zpfs_1639_1);
  and2(&S_and2_1672_1);
  zpfs(&S_zpfs_1692_1);
  and2(&S_and2_1677_1);
  zpfs(&S_zpfs_1699_1);
  or3(&S_or3_2314_1);
  or3(&S_or3_2323_1);
  or2(&S_or2_1988_1);
  or3(&S_or3_1990_1);
  or2(&S_or2_2028_1);
  and2(&S_and2_2036_1);
  or3(&S_or3_2032_1);
  and2(&S_and2_2058_1);
  or2(&S_or2_2183_1);
  or2(&S_or2_2173_1);
  and2(&S_and2_2151_1);
  and2(&S_and2_2149_1);
  and2(&S_and2_2134_1);
  zpfs(&S_zpfs_2073_1);
  and2(&S_and2_2074_1);
  or2(&S_or2_2069_1);
  or2(&S_or2_275_1);
  ovbs(&S_ovbs_13_1);
  noto(&S_noto_110_1);
  bol(&S_bol_1744_1);
  bol(&S_bol_1732_1);
  or2(&S_or2_1736_1);
  ml(&S_ml_1747_1);
  ml(&S_ml_1727_1);
  ml(&S_ml_1749_1);
  ml(&S_ml_1731_1);
  and2(&S_and2_125_1);
  noto(&S_noto_123_1);
  and2(&S_and2_129_1);
  and2(&S_and2_128_1);
  noto(&S_noto_195_1);
  noto(&S_noto_514_1);
  noto(&S_noto_1021_1);
  noto(&S_noto_1335_1);
  noto(&S_noto_1389_1);
  bol(&S_bol_2006_1);
  and3(&S_and3_1997_1);
  bol(&S_bol_1970_1);
  and3(&S_and3_1978_1);
  noto(&S_noto_1985_1);
  noto(&S_noto_1996_1);
  bol(&S_bol_1014_1);
  bol(&S_bol_1489_1);
  abs_subf(&S_abs_subf_1729_1);
  noto(&S_noto_1741_1);
  abs_subf(&S_abs_subf_1751_1);
  noto(&S_noto_1758_1);
  noto(&S_noto_2431_1);
  fsumo(&S_fsumo_86_1);
  abs_subf(&S_abs_subf_2469_1);
  and2(&S_and2_2475_1);
  ml(&S_ml_993_1);
  ml(&S_ml_1471_1);
  and3(&S_and3_2423_1);
  and2(&S_and2_2445_1);
  ovbs(&S_ovbs_2446_1);
  inf(&S_inf_2426_1);
  noto(&S_noto_2456_1);
  noto(&S_noto_1490_1);
  or2(&S_or2_1636_1);
  or2(&S_or2_1671_1);
  and2(&S_and2_112_1);
  and3(&S_and3_1591_1);
  noto(&S_noto_2391_1);
  noto(&S_noto_2360_1);
  diagndev(&S_diagndev_2519_1);
  or3(&S_or3_2527_1);
  ovbsb(&S_ovbsb_269_1);
  ovbsb(&S_ovbsb_254_1);
  ovbsb(&S_ovbsb_2311_1);
  ovbsb(&S_ovbsb_2310_1);
  ovbsb(&S_ovbsb_2309_1);
  ovbsb(&S_ovbsb_634_1);
  ovbsb(&S_ovbsb_618_1);
  ovbsb(&S_ovbsb_2324_1);
  ovbsb(&S_ovbsb_2325_1);
  ovbsb(&S_ovbsb_2326_1);
  ovbsb(&S_ovbsb_2467_1);
  ovbsb(&S_ovbsb_738_1);
  ovbsb(&S_ovbsb_781_1);
  ovbsb(&S_ovbsb_2061_1);
  period(&S_period_79_1);
  or2(&S_or2_2084_1);
  zpfs(&S_zpfs_1673_1);
  swtakt(&S_swtakt_2097_1);
  noto(&S_noto_1217_1);
  zpfs(&S_zpfs_2570_1);
  zpfs(&S_zpfs_2572_1);
  zpfs(&S_zpfs_2576_1);
  zpfs(&S_zpfs_2578_1);
  zpfs(&S_zpfs_2580_1);
  zpfs(&S_zpfs_2586_1);
  zpfs(&S_zpfs_2588_1);
  zpfs(&S_zpfs_2590_1);
  zpfs(&S_zpfs_2582_1);
  rs(&S_rs_823_1);
  noto(&S_noto_838_1);
  noto(&S_noto_1421_1);
  noto(&S_noto_942_1);
  noto(&S_noto_223_1);
  rs(&S_rs_690_1);
  noto(&S_noto_589_1);
  noto(&S_noto_1054_1);
  noto(&S_noto_1526_1);
  noto(&S_noto_2121_1);
  kvf(&S_kvf_2078_1);
  andn(&S_andn_1984_1);
  rs(&S_rs_19_1);
  noto(&S_noto_148_1);
  noto(&S_noto_2042_1);
  noto(&S_noto_118_1);
  noto(&S_noto_1582_1);
  abs_subf(&S_abs_subf_1135_1);
  abs_subf(&S_abs_subf_1122_1);
  noto(&S_noto_1143_1);
  bol(&S_bol_1156_1);
  bol(&S_bol_1157_1);
  noto(&S_noto_1119_1);
  bol(&S_bol_1160_1);
  bol(&S_bol_1161_1);
  bol(&S_bol_87_1);
  and2(&S_and2_31_1);
  and2(&S_and2_153_1);
  and2(&S_and2_161_1);
  and2(&S_and2_158_1);
  and2(&S_and2_150_1);
  and3(&S_and3_249_1);
  and3(&S_and3_615_1);
  and3(&S_and3_1113_1);
  or3(&S_or3_115_1);
  or2(&S_or2_739_1);
  and2(&S_and2_749_1);
  and2(&S_and2_751_1);
  and2(&S_and2_766_1);
  and2(&S_and2_768_1);
  and2(&S_and2_785_1);
  and2(&S_and2_788_1);
  and3(&S_and3_787_1);
  and2(&S_and2_789_1);
  or2(&S_or2_829_1);
  and2(&S_and2_837_1);
  or2(&S_or2_843_1);
  or2(&S_or2_847_1);
  and3(&S_and3_844_1);
  and2(&S_and2_849_1);
  and2(&S_and2_853_1);
  and2(&S_and2_722_1);
  or2(&S_or2_723_1);
  and2(&S_and2_733_1);
  and2(&S_and2_735_1);
  and2(&S_and2_702_1);
  and2(&S_and2_680_1);
  and2(&S_and2_670_1);
  and3(&S_and3_587_1);
  or2(&S_or2_637_1);
  and3(&S_and3_221_1);
  and3(&S_and3_265_1);
  and3(&S_and3_952_1);
  and3(&S_and3_953_1);
  or2(&S_or2_1097_1);
  or2(&S_or2_1570_1);
  and3(&S_and3_1430_1);
  and3(&S_and3_1431_1);
  or2(&S_or2_1162_1);
  or2(&S_or2_1172_1);
  or2(&S_or2_1170_1);
  or2(&S_or2_1169_1);
  or2(&S_or2_1168_1);
  and2(&S_and2_1594_1);
  and2(&S_and2_1640_1);
  and2(&S_and2_1693_1);
  or3(&S_or3_1708_1);
  and2(&S_and2_1700_1);
  or3(&S_or3_1714_1);
  and2(&S_and2_1715_1);
  and3(&S_and3_2143_1);
  and2(&S_and2_2138_1);
  or3(&S_or3_2144_1);
  zpfs(&S_zpfs_2105_1);
  or2(&S_or2_2098_1);
  and2(&S_and2_2106_1);
  lk(&S_lk_2085_1);
  rsfn(&S_rsfn_2087_1);
  abs_subf(&S_abs_subf_2088_1);
  and2(&S_and2_2081_1);
  and3(&S_and3_2082_1);
  or5(&S_or5_157_1);
  and2(&S_and2_2059_1);
  and2(&S_and2_113_1);
  and2(&S_and2_109_1);
  ml(&S_ml_1725_1);
  zpfs(&S_zpfs_830_1);
  and2(&S_and2_1961_1);
  and2(&S_and2_1938_1);
  and2(&S_and2_1959_1);
  and2(&S_and2_1962_1);
  and2(&S_and2_1939_1);
  and2(&S_and2_1960_1);
  and2(&S_and2_1940_1);
  and2(&S_and2_1941_1);
  and2(&S_and2_1943_1);
  and2(&S_and2_1944_1);
  and2(&S_and2_1946_1);
  and2(&S_and2_1947_1);
  and2(&S_and2_1914_1);
  and2(&S_and2_1915_1);
  rs(&S_rs_1916_1);
  and2(&S_and2_1917_1);
  and2(&S_and2_1918_1);
  rs(&S_rs_1919_1);
  and2(&S_and2_1897_1);
  and2(&S_and2_1901_1);
  and2(&S_and2_1864_1);
  and2(&S_and2_1866_1);
  and2(&S_and2_1868_1);
  and2(&S_and2_1870_1);
  and2(&S_and2_1838_1);
  and2(&S_and2_1839_1);
  and2(&S_and2_1840_1);
  and2(&S_and2_1841_1);
  and2(&S_and2_1842_1);
  and2(&S_and2_1843_1);
  and2(&S_and2_1844_1);
  and2(&S_and2_1845_1);
  and2(&S_and2_124_1);
  abs_subf(&S_abs_subf_1728_1);
  noto(&S_noto_1737_1);
  bol(&S_bol_2461_1);
  and2(&S_and2_2470_1);
  ovbs(&S_ovbs_2424_1);
  and2(&S_and2_2474_1);
  or3(&S_or3_2455_1);
  noto(&S_noto_2401_1);
  noto(&S_noto_2402_1);
  and2(&S_and2_2370_1);
  or4(&S_or4_998_1);
  and2(&S_and2_2339_1);
  or4(&S_or4_1476_1);
  and4(&S_and4_1064_1);
  and4(&S_and4_1537_1);
  or3(&S_or3_1951_1);
  or3(&S_or3_1922_1);
  or3(&S_or3_1925_1);
  or3(&S_or3_1954_1);
  or3(&S_or3_1906_1);
  or3(&S_or3_1908_1);
  or3(&S_or3_1857_1);
  or3(&S_or3_1853_1);
  or3(&S_or3_2377_1);
  or3(&S_or3_2346_1);
  or3(&S_or3_2379_1);
  or3(&S_or3_2381_1);
  or3(&S_or3_2350_1);
  or3(&S_or3_2348_1);
  or2(&S_or2_1883_1);
  or2(&S_or2_1850_1);
  or2(&S_or2_2383_1);
  and2(&S_and2_2367_1);
  or2(&S_or2_2352_1);
  and2(&S_and2_2337_1);
  or2(&S_or2_1875_1);
  or2(&S_or2_1847_1);
  or2(&S_or2_1904_1);
  and2(&S_and2_1900_1);
  ovbsb(&S_ovbsb_228_1);
  ovbsb(&S_ovbsb_259_1);
  ovbsb(&S_ovbsb_266_1);
  ovbsb(&S_ovbsb_591_1);
  ovbsb(&S_ovbsb_621_1);
  ovbsb(&S_ovbsb_108_1);
  ovbsb(&S_ovbsb_2464_1);
  ovbsb(&S_ovbsb_2468_1);
  ovbsb(&S_ovbsb_771_1);
  ovbsb(&S_ovbsb_765_1);
  ovbsb(&S_ovbsb_757_1);
  ovbsb(&S_ovbsb_790_1);
  ovbsb(&S_ovbsb_773_1);
  ovbsb(&S_ovbsb_742_1);
  ovbsb(&S_ovbsb_748_1);
  ovbsb(&S_ovbsb_791_1);
  ovbsb(&S_ovbsb_792_1);
  ovbsb(&S_ovbsb_795_1);
  ovbsb(&S_ovbsb_2062_1);
  zpfs(&S_zpfs_2574_1);
  samhd(&S_samhd_417_1);
  samhd(&S_samhd_423_1);
  samhd(&S_samhd_871_1);
  samhd(&S_samhd_875_1);
  rs(&S_rs_839_1);
  rs(&S_rs_846_1);
  newstage(&S_newstage_420_1);
  newstage(&S_newstage_873_1);
  orn(&S_orn_154_1);
  kvf(&S_kvf_1697_1);
  rs(&S_rs_1846_1);
  rs(&S_rs_1848_1);
  rs(&S_rs_1849_1);
  rs(&S_rs_1851_1);
  rs(&S_rs_1852_1);
  rs(&S_rs_1854_1);
  rs(&S_rs_1856_1);
  rs(&S_rs_1858_1);
  rs(&S_rs_1876_1);
  rs(&S_rs_1884_1);
  rs(&S_rs_1903_1);
  rs(&S_rs_1911_1);
  rs(&S_rs_1921_1);
  rs(&S_rs_2384_1);
  rs(&S_rs_1950_1);
  rs(&S_rs_1942_1);
  rs(&S_rs_1953_1);
  rs(&S_rs_1945_1);
  rs(&S_rs_1956_1);
  rs(&S_rs_1894_1);
  rs(&S_rs_1895_1);
  rs(&S_rs_1896_1);
  rs(&S_rs_1860_1);
  rs(&S_rs_1861_1);
  rs(&S_rs_1862_1);
  rs(&S_rs_1863_1);
  rs(&S_rs_116_1);
  noto(&S_noto_117_1);
  rs(&S_rs_1702_1);
  rs(&S_rs_2083_1);
  noto(&S_noto_1707_1);
  andn(&S_andn_290_1);
  noto(&S_noto_308_1);
  and2(&S_and2_448_1);
  and2(&S_and2_460_1);
  and2(&S_and2_469_1);
  and2(&S_and2_471_1);
  and2(&S_and2_473_1);
  or3(&S_or3_413_1);
  or3(&S_or3_429_1);
  and2(&S_and2_449_1);
  and3(&S_and3_658_1);
  or2(&S_or2_156_1);
  and2(&S_and2_754_1);
  and2(&S_and2_825_1);
  or2(&S_or2_852_1);
  and2(&S_and2_729_1);
  or2(&S_or2_298_1);
  and3(&S_and3_299_1);
  or2(&S_or2_484_1);
  and3(&S_and3_493_1);
  or2(&S_or2_545_1);
  and2(&S_and2_563_1);
  and3(&S_and3_628_1);
  and3(&S_and3_627_1);
  and2(&S_and2_191_1);
  and3(&S_and3_264_1);
  or4(&S_or4_867_1);
  or4(&S_or4_882_1);
  or3(&S_or3_943_1);
  and2(&S_and2_939_1);
  and3(&S_and3_940_1);
  and2(&S_and2_938_1);
  and2(&S_and2_954_1);
  and2(&S_and2_976_1);
  and3(&S_and3_977_1);
  and2(&S_and2_1043_1);
  or2(&S_or2_1055_1);
  and2(&S_and2_1065_1);
  and2(&S_and2_1087_1);
  and3(&S_and3_1088_1);
  and3(&S_and3_1089_1);
  or2(&S_or2_1527_1);
  and2(&S_and2_1538_1);
  and2(&S_and2_1560_1);
  and3(&S_and3_1561_1);
  and3(&S_and3_1562_1);
  and2(&S_and2_1513_1);
  or3(&S_or3_1419_1);
  and3(&S_and3_1418_1);
  and2(&S_and2_1417_1);
  and2(&S_and2_1416_1);
  and2(&S_and2_1432_1);
  and2(&S_and2_1447_1);
  and3(&S_and3_1448_1);
  and2(&S_and2_1454_1);
  and3(&S_and3_1455_1);
  and2(&S_and2_1383_1);
  and2(&S_and2_1405_1);
  and2(&S_and2_1173_1);
  and2(&S_and2_1177_1);
  or3(&S_or3_1650_1);
  and2(&S_and2_1651_1);
  or3(&S_or3_1694_1);
  and2(&S_and2_1709_1);
  or2(&S_or2_1690_1);
  or3(&S_or3_1701_1);
  or2(&S_or2_1957_1);
  lk(&S_lk_1691_1);
  rsfn(&S_rsfn_1685_1);
  abs_subf(&S_abs_subf_1703_1);
  ovbs(&S_ovbs_2280_1);
  ovbs(&S_ovbs_122_1);
  and2(&S_and2_523_1);
  and2(&S_and2_485_1);
  and2(&S_and2_482_1);
  rs(&S_rs_1958_1);
  rs(&S_rs_1924_1);
  and2(&S_and2_1898_1);
  and2(&S_and2_1899_1);
  and2(&S_and2_1902_1);
  and2(&S_and2_1867_1);
  and2(&S_and2_1871_1);
  noto(&S_noto_2454_1);
  zpfs(&S_zpfs_2409_1);
  zpfs(&S_zpfs_2410_1);
  and3(&S_and3_450_1);
  rs(&S_rs_2376_1);
  rs(&S_rs_2364_1);
  rs(&S_rs_2368_1);
  and2(&S_and2_2374_1);
  rs(&S_rs_2386_1);
  rs(&S_rs_2369_1);
  and2(&S_and2_2375_1);
  rs(&S_rs_2388_1);
  rs(&S_rs_2353_1);
  rs(&S_rs_2345_1);
  rs(&S_rs_2333_1);
  rs(&S_rs_2336_1);
  and2(&S_and2_2343_1);
  rs(&S_rs_2355_1);
  rs(&S_rs_2338_1);
  and2(&S_and2_2344_1);
  rs(&S_rs_2357_1);
  regch(&S_regch_133_1);
  rs(&S_rs_1909_1);
  ovbsb(&S_ovbsb_270_1);
  ovbsb(&S_ovbsb_1426_1);
  ovbsb(&S_ovbsb_1422_1);
  ovbsb(&S_ovbsb_1424_1);
  ovbsb(&S_ovbsb_1458_1);
  ovbsb(&S_ovbsb_1437_1);
  ovbsb(&S_ovbsb_1459_1);
  ovbsb(&S_ovbsb_1452_1);
  ovbsb(&S_ovbsb_1451_1);
  ovbsb(&S_ovbsb_1092_1);
  ovbsb(&S_ovbsb_1070_1);
  ovbsb(&S_ovbsb_1093_1);
  ovbsb(&S_ovbsb_1094_1);
  ovbsb(&S_ovbsb_860_1);
  ovbsb(&S_ovbsb_861_1);
  ovbsb(&S_ovbsb_862_1);
  ovbsb(&S_ovbsb_866_1);
  ovbsb(&S_ovbsb_406_1);
  ovbsb(&S_ovbsb_407_1);
  ovbsb(&S_ovbsb_408_1);
  ovbsb(&S_ovbsb_411_1);
  ovbsb(&S_ovbsb_461_1);
  ovbsb(&S_ovbsb_445_1);
  ovbsb(&S_ovbsb_444_1);
  ovbsb(&S_ovbsb_453_1);
  ovbsb(&S_ovbsb_631_1);
  ovbsb(&S_ovbsb_633_1);
  ovbsb(&S_ovbsb_945_1);
  ovbsb(&S_ovbsb_948_1);
  ovbsb(&S_ovbsb_947_1);
  ovbsb(&S_ovbsb_980_1);
  ovbsb(&S_ovbsb_959_1);
  ovbsb(&S_ovbsb_981_1);
  ovbsb(&S_ovbsb_1565_1);
  ovbsb(&S_ovbsb_1543_1);
  ovbsb(&S_ovbsb_1566_1);
  ovbsb(&S_ovbsb_1567_1);
  ovbsb(&S_ovbsb_883_1);
  ovbsb(&S_ovbsb_887_1);
  ovbsb(&S_ovbsb_888_1);
  ovbsb(&S_ovbsb_889_1);
  ovbsb(&S_ovbsb_427_1);
  ovbsb(&S_ovbsb_434_1);
  ovbsb(&S_ovbsb_433_1);
  ovbsb(&S_ovbsb_435_1);
  ovbsb(&S_ovbsb_481_1);
  ovbsb(&S_ovbsb_472_1);
  ovbsb(&S_ovbsb_470_1);
  ovbsb(&S_ovbsb_476_1);
  ovbsb(&S_ovbsb_763_1);
  ovbsb(&S_ovbsb_731_1);
  zpfs(&S_zpfs_2584_1);
  rs(&S_rs_818_1);
  rs(&S_rs_851_1);
  rs(&S_rs_663_1);
  noto(&S_noto_677_1);
  noto(&S_noto_2281_1);
  rs(&S_rs_1878_1);
  rs(&S_rs_1886_1);
  rs(&S_rs_1905_1);
  rs(&S_rs_1907_1);
  rs(&S_rs_1913_1);
  rs(&S_rs_673_1);
  kvf(&S_kvf_1696_1);
  rs(&S_rs_1695_1);
  rs(&S_rs_1642_1);
  kvf(&S_kvf_1647_1);
  noto(&S_noto_1646_1);
  noto(&S_noto_1109_1);
  noto(&S_noto_300_1);
  noto(&S_noto_1171_1);
  noto(&S_noto_1166_1);
  noto(&S_noto_1138_1);
  and2(&S_and2_452_1);
  and2(&S_and2_475_1);
  and2(&S_and2_969_1);
  and3(&S_and3_970_1);
  and3(&S_and3_1080_1);
  and3(&S_and3_1553_1);
  and2(&S_and2_697_1);
  and2(&S_and2_1050_1);
  and2(&S_and2_1051_1);
  and3(&S_and3_1052_1);
  and2(&S_and2_1523_1);
  and2(&S_and2_1524_1);
  and3(&S_and3_1525_1);
  and5(&S_and5_1114_1);
  and2(&S_and2_1163_1);
  or4(&S_or4_1121_1);
  or2(&S_or2_1637_1);
  or3(&S_or3_1641_1);
  and3(&S_and3_1712_1);
  or2(&S_or2_2046_1);
  and2(&S_and2_2048_1);
  and2(&S_and2_2298_1);
  lk(&S_lk_1689_1);
  rsfn(&S_rsfn_1682_1);
  abs_subf(&S_abs_subf_1698_1);
  lk(&S_lk_1648_1);
  rsfn(&S_rsfn_1644_1);
  abs_subf(&S_abs_subf_1653_1);
  ovbs(&S_ovbs_2282_1);
  noto(&S_noto_2414_1);
  noto(&S_noto_2415_1);
  andn(&S_andn_661_1);
  andn(&S_andn_662_1);
  and2(&S_and2_2301_1);
  and2(&S_and2_2371_1);
  or3(&S_or3_1367_1);
  rs(&S_rs_2378_1);
  rs(&S_rs_2365_1);
  and2(&S_and2_2340_1);
  rs(&S_rs_2347_1);
  rs(&S_rs_2334_1);
  or3(&S_or3_906_1);
  or2(&S_or2_136_1);
  ovbsb(&S_ovbsb_1057_1);
  ovbsb(&S_ovbsb_1058_1);
  ovbsb(&S_ovbsb_1060_1);
  ovbsb(&S_ovbsb_1085_1);
  ovbsb(&S_ovbsb_447_1);
  ovbsb(&S_ovbsb_973_1);
  ovbsb(&S_ovbsb_975_1);
  ovbsb(&S_ovbsb_1530_1);
  ovbsb(&S_ovbsb_1533_1);
  ovbsb(&S_ovbsb_1531_1);
  ovbsb(&S_ovbsb_1558_1);
  ovbsb(&S_ovbsb_474_1);
  ovbsb(&S_ovbsb_1144_1);
  zpfs(&S_zpfs_2564_1);
  zpfs(&S_zpfs_2566_1);
  rs(&S_rs_1120_1);
  orni(&S_orni_1600_1);
  noto(&S_noto_2283_1);
  rs(&S_rs_1717_1);
  noto(&S_noto_1139_1);
  and2(&S_and2_600_1);
  and2(&S_and2_234_1);
  and2(&S_and2_956_1);
  and2(&S_and2_1067_1);
  and2(&S_and2_1540_1);
  and2(&S_and2_1434_1);
  and3(&S_and3_1126_1);
  and3(&S_and3_1132_1);
  and2(&S_and2_1150_1);
  and2(&S_and2_1137_1);
  and3(&S_and3_1184_1);
  and3(&S_and3_1657_1);
  and3(&S_and3_1711_1);
  or2(&S_or2_2044_1);
  noto(&S_noto_2421_1);
  and2(&S_and2_2372_1);
  and2(&S_and2_2341_1);
  rs(&S_rs_2366_1);
  and2(&S_and2_2373_1);
  rs(&S_rs_2382_1);
  rs(&S_rs_2335_1);
  ovbsb(&S_ovbsb_242_1);
  ovbsb(&S_ovbsb_1440_1);
  ovbsb(&S_ovbsb_1073_1);
  ovbsb(&S_ovbsb_607_1);
  ovbsb(&S_ovbsb_963_1);
  ovbsb(&S_ovbsb_1544_1);
  zpfs(&S_zpfs_2568_1);
  rs(&S_rs_2380_1);
  newstage(&S_newstage_2037_1);
  rs(&S_rs_1716_1);
  rs(&S_rs_1660_1);
  rs(&S_rs_1145_1);
  rs(&S_rs_1178_1);
  rs(&S_rs_1152_1);
  noto(&S_noto_1153_1);
  or3(&S_or3_164_1);
  or3(&S_or3_535_1);
  or2(&S_or2_1174_1);
  or2(&S_or2_1793_1);
  andn(&S_andn_2429_1);
  noto(&S_noto_2451_1);
  and2(&S_and2_2452_1);
  or2(&S_or2_2450_1);
  and3(&S_and3_2407_1);
  rs(&S_rs_2349_1);
  and2(&S_and2_2342_1);
  rs(&S_rs_2351_1);
  ovbsb(&S_ovbsb_2178_1);
  zzfs(&S_zzfs_2550_1);
  cnshd(&S_cnshd_1800_1);
  noto(&S_noto_968_1);
  ornc(&S_ornc_172_1);
  charint(&S_charint_165_1);
  noto(&S_noto_246_1);
  ornc(&S_ornc_543_1);
  charint(&S_charint_537_1);
  noto(&S_noto_611_1);
  noto(&S_noto_1076_1);
  noto(&S_noto_1547_1);
  rs(&S_rs_1164_1);
  or2(&S_or2_1821_1);
  and2(&S_and2_1763_1);
  and2(&S_and2_1764_1);
  and2(&S_and2_1765_1);
  and2(&S_and2_1766_1);
  and2(&S_and2_1776_1);
  and2(&S_and2_1778_1);
  and2(&S_and2_1780_1);
  and2(&S_and2_1151_1);
  rs(&S_rs_2449_1);
  ovbsb(&S_ovbsb_1790_1);
  ovbsb(&S_ovbsb_1768_1);
  ovbsb(&S_ovbsb_1769_1);
  ovbsb(&S_ovbsb_1771_1);
  ovbsb(&S_ovbsb_1773_1);
  ovbsb(&S_ovbsb_1782_1);
  ovbsb(&S_ovbsb_1787_1);
  fnapb(&S_fnapb_1822_1);
  samhd(&S_samhd_1803_1);
  zpfs(&S_zpfs_1818_1);
  zpfs(&S_zpfs_1814_1);
  noto(&S_noto_1444_1);
  fsumz(&S_fsumz_166_1);
  fsumz(&S_fsumz_538_1);
  orni(&S_orni_1324_1);
  rs(&S_rs_1147_1);
  rs(&S_rs_1148_1);
  ma(&S_ma_173_1);
  ma(&S_ma_544_1);
  zpfs(&S_zpfs_1828_1);
  or2(&S_or2_1268_1);
  or3(&S_or3_1146_1);
  or3(&S_or3_1811_1);
  ovbsb(&S_ovbsb_1804_1);
  ovbsb(&S_ovbsb_1815_1);
  ovbsb(&S_ovbsb_1825_1);
  ovbsb(&S_ovbsb_1824_1);
  ovbsb(&S_ovbsb_1817_1);
  ovbsb(&S_ovbsb_1809_1);
  samhd(&S_samhd_1329_1);
  samhd(&S_samhd_1338_1);
  newstage(&S_newstage_1334_1);
  cnshd(&S_cnshd_1270_1);
  noto(&S_noto_1443_1);
  noto(&S_noto_967_1);
  cnshd(&S_cnshd_176_1);
  noto(&S_noto_245_1);
  cnshd(&S_cnshd_546_1);
  noto(&S_noto_610_1);
  noto(&S_noto_1075_1);
  noto(&S_noto_1546_1);
  or2(&S_or2_1328_1);
  or2(&S_or2_1342_1);
  or2(&S_or2_1295_1);
  and2(&S_and2_1236_1);
  and2(&S_and2_1233_1);
  and2(&S_and2_1234_1);
  and2(&S_and2_1235_1);
  and2(&S_and2_1245_1);
  and2(&S_and2_1247_1);
  and2(&S_and2_1249_1);
  and2(&S_and2_699_1);
  or2(&S_or2_568_1);
  or2(&S_or2_602_1);
  or2(&S_or2_200_1);
  or2(&S_or2_236_1);
  or2(&S_or2_958_1);
  and2(&S_and2_957_1);
  or2(&S_or2_1069_1);
  or2(&S_or2_1542_1);
  or2(&S_or2_1436_1);
  and2(&S_and2_1435_1);
  and2(&S_and2_1142_1);
  or2(&S_or2_1154_1);
  and2(&S_and2_1332_1);
  and2(&S_and2_1339_1);
  ovbsb(&S_ovbsb_1441_1);
  ovbsb(&S_ovbsb_1322_1);
  ovbsb(&S_ovbsb_1323_1);
  ovbsb(&S_ovbsb_1326_1);
  ovbsb(&S_ovbsb_965_1);
  ovbsb(&S_ovbsb_1343_1);
  ovbsb(&S_ovbsb_1344_1);
  ovbsb(&S_ovbsb_1345_1);
  ovbsb(&S_ovbsb_1259_1);
  ovbsb(&S_ovbsb_1238_1);
  ovbsb(&S_ovbsb_1240_1);
  ovbsb(&S_ovbsb_1242_1);
  ovbsb(&S_ovbsb_1244_1);
  ovbsb(&S_ovbsb_1251_1);
  ovbsb(&S_ovbsb_1255_1);
  and2(&S_and2_1229_1);
  noto(&S_noto_1228_1);
  or3(&S_or3_1221_1);
  fnapb(&S_fnapb_1296_1);
  samhd(&S_samhd_1276_1);
  zpfs(&S_zpfs_1290_1);
  zpfs(&S_zpfs_1286_1);
  orn(&S_orn_1445_1);
  orn(&S_orn_964_1);
  fnapb(&S_fnapb_201_1);
  newstage(&S_newstage_211_1);
  fnapb(&S_fnapb_569_1);
  zpfs(&S_zpfs_564_1);
  zpfs(&S_zpfs_565_1);
  rs(&S_rs_1141_1);
  zpfs(&S_zpfs_1303_1);
  zpfs(&S_zpfs_584_1);
  and2(&S_and2_601_1);
  orn(&S_orn_612_1);
  zpfs(&S_zpfs_215_1);
  zpfs(&S_zpfs_193_1);
  zpfs(&S_zpfs_194_1);
  and2(&S_and2_235_1);
  and2(&S_and2_1068_1);
  and2(&S_and2_1541_1);
  and2(&S_and2_1155_1);
  or2(&S_or2_1149_1);
  or3(&S_or3_1283_1);
  and2(&S_and2_198_1);
  and2(&S_and2_196_1);
  or4(&S_or4_2161_1);
  ovbsb(&S_ovbsb_210_1);
  ovbsb(&S_ovbsb_202_1);
  ovbsb(&S_ovbsb_203_1);
  ovbsb(&S_ovbsb_204_1);
  ovbsb(&S_ovbsb_243_1);
  ovbsb(&S_ovbsb_1074_1);
  ovbsb(&S_ovbsb_577_1);
  ovbsb(&S_ovbsb_572_1);
  ovbsb(&S_ovbsb_571_1);
  ovbsb(&S_ovbsb_570_1);
  ovbsb(&S_ovbsb_608_1);
  ovbsb(&S_ovbsb_1545_1);
  ovbsb(&S_ovbsb_1294_1);
  ovbsb(&S_ovbsb_1280_1);
  ovbsb(&S_ovbsb_1299_1);
  ovbsb(&S_ovbsb_1293_1);
  ovbsb(&S_ovbsb_1288_1);
  ovbsb(&S_ovbsb_1281_1);
  noto(&S_noto_1213_1);
  orn(&S_orn_238_1);
  and2(&S_and2_1207_1);
  and2(&S_and2_706_1);
  or2(&S_or2_694_1);
  and2(&S_and2_1175_1);
  or2(&S_or2_2179_1);
  or2(&S_or2_2167_1);
  ovbs(&S_ovbs_2162_1);
  ovbs(&S_ovbs_2175_1);
  ovbs(&S_ovbs_2165_1);
  noto(&S_noto_2166_1);
  and2(&S_and2_2174_1);
  and2(&S_and2_2184_1);
  or3(&S_or3_134_1);
  noto(&S_noto_132_1);
  rs(&S_rs_695_1);
  noto(&S_noto_2163_1);
  noto(&S_noto_2176_1);
  rs(&S_rs_2180_1);
  noto(&S_noto_2181_1);
  rs(&S_rs_2168_1);
  rs(&S_rs_1158_1);
  noto(&S_noto_1165_1);
  rs(&S_rs_1193_1);
  rs(&S_rs_1199_1);
  and2(&S_and2_713_1);
  and3(&S_and3_682_1);
  and3(&S_and3_672_1);
  or3(&S_or3_901_1);
  or3(&S_or3_1363_1);
  and4(&S_and4_1127_1);
  and4(&S_and4_1133_1);
  or2(&S_or2_2135_1);
  irm(&S_irm_2408_1);
  or4(&S_or4_989_1);
  or4(&S_or4_1467_1);
  and2(&S_and2_53_1);
  or3(&S_or3_1198_1);
  ornc(&S_ornc_999_1);
  charint(&S_charint_991_1);
  ornc(&S_ornc_1477_1);
  charint(&S_charint_1469_1);
  noto(&S_noto_2169_1);
  noto(&S_noto_69_1);
  swtakt(&S_swtakt_54_1);
  noto(&S_noto_2136_1);
  rs(&S_rs_1197_1);
  and2(&S_and2_61_1);
  and2(&S_and2_65_1);
  and4(&S_and4_355_1);
  and2(&S_and2_1555_1);
  or2(&S_or2_1588_1);
  or2(&S_or2_2258_1);
  or2(&S_or2_2152_1);
  and2(&S_and2_2133_1);
  and2(&S_and2_2103_1);
  and4(&S_and4_2104_1);
  and4(&S_and4_2110_1);
  or2(&S_or2_2113_1);
  or2(&S_or2_2115_1);
  or2(&S_or2_2114_1);
  zpfs(&S_zpfs_2117_1);
  zpfs(&S_zpfs_2120_1);
  and4(&S_and4_2124_1);
  and4(&S_and4_2126_1);
  or3(&S_or3_2122_1);
  and2(&S_and2_1082_1);
  and2(&S_and2_2259_1);
  ovbsb(&S_ovbsb_1083_1);
  ovbsb(&S_ovbsb_1556_1);
  or4(&S_or4_2542_1);
  or2(&S_or2_2302_1);
  or2(&S_or2_2303_1);
  fsumz(&S_fsumz_992_1);
  orn(&S_orn_1077_1);
  fsumz(&S_fsumz_1470_1);
  orn(&S_orn_1548_1);
  kvf(&S_kvf_2119_1);
  noto(&S_noto_1584_1);
  rs(&S_rs_358_1);
  noto(&S_noto_353_1);
  noto(&S_noto_295_1);
  rs(&S_rs_2153_1);
  rs(&S_rs_2154_1);
  ma(&S_ma_1478_1);
  ma(&S_ma_1000_1);
  or4(&S_or4_306_1);
  or2(&S_or2_289_1);
  or2(&S_or2_312_1);
  or2(&S_or2_350_1);
  or4(&S_or4_359_1);
  and2(&S_and2_1583_1);
  or2(&S_or2_2287_1);
  or2(&S_or2_2292_1);
  zpfs(&S_zpfs_2260_1);
  and2(&S_and2_2116_1);
  lk(&S_lk_2123_1);
  rsfn(&S_rsfn_2127_1);
  abs_subf(&S_abs_subf_2129_1);
  and3(&S_and3_2132_1);
  and2(&S_and2_2273_1);
  and2(&S_and2_2286_1);
  and2(&S_and2_2272_1);
  or5(&S_or5_2299_1);
  and2(&S_and2_2297_1);
  or2(&S_or2_2216_1);
  or2(&S_or2_2237_1);
  or3(&S_or3_2255_1);
  ovbsb(&S_ovbsb_2267_1);
  ovbsb(&S_ovbsb_2268_1);
  ovbsb(&S_ovbsb_2279_1);
  ovbsb(&S_ovbsb_2296_1);
  or3(&S_or3_2543_1);
  cnshd(&S_cnshd_1001_1);
  cnshd(&S_cnshd_1479_1);
  rs(&S_rs_305_1);
  rs(&S_rs_2288_1);
  ma(&S_ma_1649_1);
  rs(&S_rs_2137_1);
  provsbr(&S_provsbr_1596_1);
  rs(&S_rs_1595_1);
  provsbr(&S_provsbr_294_1);
  equz_p(&S_equz_p_333_1);
  bolz(&S_bolz_334_1);
  provsbr(&S_provsbr_352_1);
  bolz(&S_bolz_357_1);
  noto(&S_noto_70_1);
  noto(&S_noto_59_1);
  and2(&S_and2_62_1);
  and2(&S_and2_66_1);
  or2(&S_or2_63_1);
  and2(&S_and2_630_1);
  and2(&S_and2_629_1);
  or3(&S_or3_644_1);
  and2(&S_and2_309_1);
  and4(&S_and4_339_1);
  and2(&S_and2_321_1);
  or2(&S_or2_311_1);
  and2(&S_and2_316_1);
  or2(&S_or2_363_1);
  and2(&S_and2_354_1);
  or5(&S_or5_557_1);
  and2(&S_and2_267_1);
  and2(&S_and2_268_1);
  or3(&S_or3_282_1);
  or2(&S_or2_1030_1);
  and2(&S_and2_1091_1);
  and2(&S_and2_1090_1);
  and2(&S_and2_1563_1);
  and2(&S_and2_1564_1);
  or2(&S_or2_1504_1);
  and2(&S_and2_1603_1);
  and2(&S_and2_1607_1);
  and2(&S_and2_1611_1);
  and2(&S_and2_1619_1);
  or2(&S_or2_1604_1);
  or2(&S_or2_1608_1);
  or2(&S_or2_1612_1);
  or2(&S_or2_1620_1);
  or2(&S_or2_1585_1);
  or4(&S_or4_1579_1);
  or4(&S_or4_1105_1);
  or5(&S_or5_2300_1);
  ovbsb(&S_ovbsb_273_1);
  ovbsb(&S_ovbsb_274_1);
  ovbsb(&S_ovbsb_1095_1);
  ovbsb(&S_ovbsb_1096_1);
  ovbsb(&S_ovbsb_635_1);
  ovbsb(&S_ovbsb_636_1);
  ovbsb(&S_ovbsb_1568_1);
  ovbsb(&S_ovbsb_1569_1);
  and2(&S_and2_1625_1);
  or2(&S_or2_1602_1);
  or2(&S_or2_1606_1);
  or2(&S_or2_1610_1);
  or2(&S_or2_1615_1);
  or2(&S_or2_1622_1);
  and2(&S_and2_1231_1);
  noto(&S_noto_1230_1);
  or3(&S_or3_1223_1);
  fnapb(&S_fnapb_1031_1);
  zpfs(&S_zpfs_1023_1);
  zpfs(&S_zpfs_1024_1);
  newstage(&S_newstage_1013_1);
  fnapb(&S_fnapb_1505_1);
  zpfs(&S_zpfs_1497_1);
  zpfs(&S_zpfs_1496_1);
  maz(&S_maz_320_1);
  maz(&S_maz_329_1);
  rs(&S_rs_2293_1);
  orni(&S_orni_1340_1);
  rs(&S_rs_362_1);
  decatron(&S_decatron_319_1);
  noto(&S_noto_330_1);
  zpfs(&S_zpfs_1048_1);
  zpfs(&S_zpfs_1521_1);
  or2(&S_or2_315_1);
  or2(&S_or2_324_1);
  or2(&S_or2_338_1);
  or2(&S_or2_337_1);
  and2(&S_and2_341_1);
  and2(&S_and2_336_1);
  and2(&S_and2_343_1);
  and2(&S_and2_342_1);
  and3(&S_and3_322_1);
  or5(&S_or5_188_1);
  or2(&S_or2_1626_1);
  orni(&S_orni_1616_1);
  and2(&S_and2_1586_1);
  or2(&S_or2_2276_1);
  or2(&S_or2_2264_1);
  or2(&S_or2_2248_1);
  or3(&S_or3_1581_1);
  or3(&S_or3_1108_1);
  zpfs(&S_zpfs_335_1);
  and2(&S_and2_1019_1);
  and2(&S_and2_1022_1);
  and2(&S_and2_1493_1);
  and2(&S_and2_1018_1);
  and2(&S_and2_2263_1);
  and2(&S_and2_2257_1);
  and2(&S_and2_2277_1);
  ovbsb(&S_ovbsb_1042_1);
  ovbsb(&S_ovbsb_1025_1);
  ovbsb(&S_ovbsb_1035_1);
  ovbsb(&S_ovbsb_1036_1);
  ovbsb(&S_ovbsb_2262_1);
  ovbsb(&S_ovbsb_1515_1);
  ovbsb(&S_ovbsb_1511_1);
  ovbsb(&S_ovbsb_1502_1);
  ovbsb(&S_ovbsb_1503_1);
  ovbsb(&S_ovbsb_2256_1);
  noto(&S_noto_1215_1);
  zzfs(&S_zzfs_2552_1);
  zzfs(&S_zzfs_2560_1);
  zzfs(&S_zzfs_2562_1);
  rs(&S_rs_2249_1);
  noto(&S_noto_2250_1);
  noto(&S_noto_2294_1);
  equz_p(&S_equz_p_323_1);
  noto(&S_noto_1592_1);
  cntch(&S_cntch_1613_1);
  rs(&S_rs_314_1);
  and2(&S_and2_1208_1);
  and2(&S_and2_328_1);
  and2(&S_and2_705_1);
  or5(&S_or5_1017_1);
  or5(&S_or5_1492_1);
  and2(&S_and2_1183_1);
  and2(&S_and2_1617_1);
  or5(&S_or5_1618_1);
  or5(&S_or5_1587_1);
  and2(&S_and2_1589_1);
  or2(&S_or2_1590_1);
  zpfs(&S_zpfs_2271_1);
  and4(&S_and4_2139_1);
  and3(&S_and3_2140_1);
  and3(&S_and3_2141_1);
  and2(&S_and2_2102_1);
  and2(&S_and2_2066_1);
  or3(&S_or3_2075_1);
  or3(&S_or3_2270_1);
  rs(&S_rs_2265_1);
  noto(&S_noto_2266_1);
  rs(&S_rs_2108_1);
  rs(&S_rs_2076_1);
  rs(&S_rs_1176_1);
  noto(&S_noto_1179_1);
  rs(&S_rs_1202_1);
  and2(&S_and2_348_1);
  and3(&S_and3_1167_1);
  and2(&S_and2_1118_1);
  and4(&S_and4_1125_1);
  and4(&S_and4_1131_1);
  or3(&S_or3_2107_1);
  orn(&S_orn_1355_1);
  orn(&S_orn_894_1);
  or3(&S_or3_1201_1);
  ornc(&S_ornc_1364_1);
  charint(&S_charint_1356_1);
  ornc(&S_ornc_902_1);
  charint(&S_charint_895_1);
  noto(&S_noto_349_1);
  rs(&S_rs_1112_1);
  rs(&S_rs_1200_1);
  or3(&S_or3_483_1);
  and3(&S_and3_492_1);
  and2(&S_and2_1159_1);
  and2(&S_and2_528_1);
  and2(&S_and2_494_1);
  fsumz(&S_fsumz_1357_1);
  fsumz(&S_fsumz_896_1);
  samhd(&S_samhd_507_1);
  samhd(&S_samhd_513_1);
  newstage(&S_newstage_509_1);
  ma(&S_ma_903_1);
  ma(&S_ma_1365_1);
  or4(&S_or4_503_1);
  or4(&S_or4_522_1);
  andn(&S_andn_1_1);
  and2(&S_and2_518_1);
  and2(&S_and2_515_1);
  ovbsb(&S_ovbsb_499_1);
  ovbsb(&S_ovbsb_496_1);
  ovbsb(&S_ovbsb_497_1);
  ovbsb(&S_ovbsb_498_1);
  ovbsb(&S_ovbsb_521_1);
  ovbsb(&S_ovbsb_525_1);
  ovbsb(&S_ovbsb_526_1);
  ovbsb(&S_ovbsb_527_1);
  cnshd(&S_cnshd_1366_1);
  cnshd(&S_cnshd_905_1);
  and2(&S_and2_1209_1);
  and2(&S_and2_721_1);
  or2(&S_or2_922_1);
  and2(&S_and2_979_1);
  and2(&S_and2_978_1);
  or3(&S_or3_988_1);
  and2(&S_and2_1456_1);
  and2(&S_and2_1457_1);
  or3(&S_or3_1466_1);
  or2(&S_or2_1399_1);
  and2(&S_and2_1190_1);
  ovbsb(&S_ovbsb_1460_1);
  ovbsb(&S_ovbsb_1461_1);
  ovbsb(&S_ovbsb_985_1);
  ovbsb(&S_ovbsb_982_1);
  and2(&S_and2_1227_1);
  noto(&S_noto_1226_1);
  or3(&S_or3_1219_1);
  fnapb(&S_fnapb_1401_1);
  zpfs(&S_zpfs_1395_1);
  zpfs(&S_zpfs_1396_1);
  newstage(&S_newstage_1406_1);
  fnapb(&S_fnapb_923_1);
  rs(&S_rs_1186_1);
  rs(&S_rs_1205_1);
  zpfs(&S_zpfs_1411_1);
  zpfs(&S_zpfs_935_1);
  zpfs(&S_zpfs_917_1);
  zpfs(&S_zpfs_918_1);
  or5(&S_or5_1378_1);
  and2(&S_and2_1390_1);
  and2(&S_and2_1394_1);
  or5(&S_or5_2186_1);
  or3(&S_or3_1881_1);
  or3(&S_or3_1873_1);
  or2(&S_or2_1887_1);
  or2(&S_or2_1879_1);
  ovbsb(&S_ovbsb_921_1);
  ovbsb(&S_ovbsb_920_1);
  ovbsb(&S_ovbsb_930_1);
  ovbsb(&S_ovbsb_925_1);
  ovbsb(&S_ovbsb_1408_1);
  ovbsb(&S_ovbsb_1391_1);
  ovbsb(&S_ovbsb_1386_1);
  ovbsb(&S_ovbsb_1404_1);
  noto(&S_noto_1211_1);
  or3(&S_or3_1204_1);
  zzfs(&S_zzfs_2556_1);
  zzfs(&S_zzfs_2554_1);
  orni(&S_orni_140_1);
  orn(&S_orn_455_1);
  orn(&S_orn_477_1);
  rs(&S_rs_1872_1);
  rs(&S_rs_1880_1);
  rs(&S_rs_1203_1);
  or2(&S_or2_457_1);
  or2(&S_or2_479_1);
  and2(&S_and2_753_1);
  or2(&S_or2_1311_1);
  or2(&S_or2_1312_1);
  and2(&S_and2_1248_1);
  or5(&S_or5_914_1);
  and2(&S_and2_1779_1);
  or4(&S_or4_1775_1);
  and2(&S_and2_1865_1);
  and2(&S_and2_1869_1);
  or4(&S_or4_2187_1);
  ovbsb(&S_ovbsb_1788_1);
  ovbsb(&S_ovbsb_1256_1);
  ovbsb(&S_ovbsb_762_1);
  or3(&S_or3_1195_1);
  orn(&S_orn_850_1);
  orn(&S_orn_1232_1);
  rs(&S_rs_1874_1);
  rs(&S_rs_1882_1);
  rs(&S_rs_1194_1);
  or2(&S_or2_840_1);
  or2(&S_or2_841_1);
  or4(&S_or4_821_1);
  and4(&S_and4_1192_1);
  or5(&S_or5_1279_1);
  or2(&S_or2_383_1);
  or2(&S_or2_387_1);
  ovbs(&S_ovbs_2193_1);
  noto(&S_noto_2194_1);
  and2(&S_and2_2200_1);
  and2(&S_and2_2212_1);
  or3(&S_or3_2188_1);
  and2(&S_and2_2189_1);
  or3(&S_or3_2202_1);
  and2(&S_and2_2203_1);
  or5(&S_or5_1762_1);
  or2(&S_or2_2440_1);
  rs(&S_rs_820_1);
  samhd(&S_samhd_386_1);
  and2(&S_and2_808_1);
  or2(&S_or2_810_1);
  or4(&S_or4_385_1);
  or5(&S_or5_1808_1);
  or2(&S_or2_2207_1);
  or2(&S_or2_2195_1);
  ovbs(&S_ovbs_2190_1);
  ovbs(&S_ovbs_2204_1);
  rs(&S_rs_2224_1);
  rs(&S_rs_2232_1);
  noto(&S_noto_2222_1);
  noto(&S_noto_2243_1);
  zpfs(&S_zpfs_2225_1);
  zpfs(&S_zpfs_2233_1);
  noto(&S_noto_2436_1);
  ovbsb(&S_ovbsb_392_1);
  ovbsb(&S_ovbsb_393_1);
  ovbsb(&S_ovbsb_394_1);
  rs(&S_rs_814_1);
  or2(&S_or2_2226_1);
  noto(&S_noto_2191_1);
  noto(&S_noto_2205_1);
  rs(&S_rs_2208_1);
  noto(&S_noto_2209_1);
  rs(&S_rs_2196_1);
  or2(&S_or2_2234_1);
  noto(&S_noto_2227_1);
  and2(&S_and2_2228_1);
  and2(&S_and2_2223_1);
  noto(&S_noto_2235_1);
  noto(&S_noto_2215_1);
  ovbsb(&S_ovbsb_2214_1);
  noto(&S_noto_2197_1);
  and2(&S_and2_2236_1);
  and4(&S_and4_2217_1);
  ovbs(&S_ovbs_2218_1);
  and2(&S_and2_2244_1);
  noto(&S_noto_2246_1);
  or2(&S_or2_2219_1);
  ovbsb(&S_ovbsb_2247_1);
  orn(&S_orn_665_1);
  orn(&S_orn_664_1);
  noto(&S_noto_2220_1);
  and4(&S_and4_2238_1);
  ovbs(&S_ovbs_2239_1);
  or2(&S_or2_2240_1);
  newstage(&S_newstage_667_1);
  or2(&S_or2_701_1);
  ovbs(&S_ovbs_2229_1);
  noto(&S_noto_2241_1);
  and2(&S_and2_700_1);
  setData(idpsz28,&var1);
  setData(idpsz27,&var2);
  setData(idpsz26,&var3);
  setData(idpsz25,&var6);
  setData(idpsz24,&var4);
  setData(idpsz23,&var5);
  setData(idpsz22,&var7);
  setData(idpsz21,&var8);
  setData(idpsz14,&var10);
  setData(idpsz13,&var11);
  setData(idpsz12,&var12);
  setData(idpsz11,&var13);
  setData(idpsz10,&var9);
  setData(idpsz9,&var14);
  setData(idpsz8,&var15);
  setData(idpsz7,&var16);
  setData(idpsz6,&var17);
  setData(idpsz5,&var18);
  setData(idpsz4,&var19);
  setData(idpsz3,&var20);
  setData(idpsz2,&var21);
  setData(idpsz1,&var22);
  setData(idR0S01LIM,&var1271);
  setData(idR0AD16LDU,&var1266);
  setData(idR0S01LZ2,&var48);
  setData(idR0S01LZ1,&var48);
  setData(idR0S01LDU,&var49);
  setData(idR8AD21LDU,&var1270);
  setData(idR0VN15RDU,&var62);
  setData(idB3CV01RDU,&var1568);
  setData(idTestDiagnDU,&var275);
  setData(idR0DE3CLDU,&var277);
  setData(idR0DE3DLDU,&var276);
  setData(idTTLDU,&var279);
  setData(idB3AB13LDU,&var137);
  setData(idA3AB13LDU,&var223);
  setData(idR3VS01IDU,&var408);
  setData(idR3VS12LDU,&var406);
  setData(idR3VS22LDU,&var407);
  setData(idR5VS01IDU,&var405);
  setData(idR5VS12LDU,&var403);
  setData(idR5VS22LDU,&var404);
  setData(idB3AB15LDU,&var139);
  setData(idB3EE03LDU,&var1063);
  setData(idA3EE03LDU,&var1064);
  setData(idB3AB19LDU,&var138);
  setData(idA3AB19LDU,&var217);
  setData(idR0VL23LDU,&var1303);
  setData(idR0VL22LDU,&var1325);
  setData(idR0AD05LZ2,&var344);
  setData(idR0AD05LZ1,&var344);
  setData(idR0AD04LZ2,&var47);
  setData(idR0AD04LZ1,&var47);
  setData(idR0AD03LZ2,&var343);
  setData(idR0AD03LZ1,&var343);
  setData(idR0CN95LDU,&var483);
  setData(idR0CN94LDU,&var482);
  setData(idR0CN93LDU,&var481);
  setData(idR0AB19LDU,&var93);
  setData(idR0VN12RDU,&var1232);
  setData(idR0VN11RDU,&var1230);
  setData(idR0CN92LDU,&var449);
  setData(idR0AB20LDU,&var92);
  setData(idA3AB15LDU,&var221);
  setData(idA3MC03RDU,&var479);
  setData(idR0CN91LDU,&var478);
  setData(idA3MC02RDU,&var477);
  setData(idA3MC01RDU,&var476);
  setData(idR0AB18LDU,&var94);
  setData(idR0AB17LDU,&var95);
  setData(idR0AB16LDU,&var96);
  setData(idB1AB19LDU,&var168);
  setData(idA3ZAV,&var1573);
  setData(idA1ZAV,&var1636);
  setData(idB3IS12LDU,&var500);
  setData(idA3IS12LDU,&var501);
  setData(idR0AB15LDU,&var506);
  setData(idR0AB14LDU,&var504);
  setData(idA4DW,&var1413);
  setData(idA4UP,&var1414);
  setData(idR4ABL,&var1875);
  setData(idA9ZAV,&var1511);
  setData(idA8ZAV,&var1712);
  setData(idA2ZAV,&var1717);
  setData(idB8ZAV,&var1722);
  setData(idA5ZAV,&var1790);
  setData(idR2ZAV,&var1666);
  setData(idA6ZAV,&var1792);
  setData(idA4ZAV,&var1791);
  setData(idR0AB13LDU,&var573);
  setData(idR0AB12LDU,&var577);
  setData(idR0AB11LDU,&var581);
  setData(idR0AB10LDU,&var585);
  setData(idR0AB09LDU,&var589);
  setData(idR0AB08LDU,&var97);
  setData(idB6AB05LDU,&var120);
  setData(idR0VS11LDU,&var1933);
  setData(idA8VS01IDU,&var1716);
  setData(idB8VS01IDU,&var1726);
  setData(idR2AD10LDU,&var1671);
  setData(idR2AD20LDU,&var1672);
  setData(idB6VS01IDU,&var1863);
  setData(idR0AB07LDU,&var98);
  setData(idR0EE03LDU,&var658);
  setData(idR0VX02LDU,&var1069);
  setData(idR0AD21LDU,&var1067);
  setData(idB2AB15LDU,&var154);
  setData(idA2AB15LDU,&var238);
  setData(idR0AB05LDU,&var1385);
  setData(idR0AB03LDU,&var1396);
  setData(idA1AB19LDU,&var249);
  setData(idR0VZ71LDU,&var330);
  setData(idR0VL01RDU,&var1431);
  setData(idB7AZ03LDU,&var63);
  setData(idA7AZ03LDU,&var64);
  setData(idB2VS01IDU,&var1704);
  setData(idB2VS21LDU,&var1706);
  setData(idB2VS11LDU,&var1705);
  setData(idR0VP73LDU,&var745);
  setData(idR0VS18LDU,&var822);
  setData(idB3VX01LDU,&var692);
  setData(idA3VX01LDU,&var693);
  setData(idB2VS32LDU,&var619);
  setData(idA2VS32LDU,&var620);
  setData(idR0VS17LDU,&var812);
  setData(idR0VX09LDU,&var437);
  moveData(idR0VX08IDU,idR0MW12IP1);
  setData(idR0VW23LDU,&var1164);
  setData(idR0VW13LDU,&var1163);
  setData(idB7AP31LDU,&var1416);
  setData(idA7AP31LDU,&var1417);
  setData(idB3AD31LDU,&var1474);
  setData(idB3AD34LDU,&var1475);
  setData(idA3AD31LDU,&var1480);
  setData(idA3AD34LDU,&var1477);
  setData(idA3AD33LDU,&var1479);
  setData(idB2AD33LDU,&var598);
  setData(idA2AD33LDU,&var601);
  setData(idR0AB01LDU,&var1503);
  setData(idB9AB02LDU,&var99);
  setData(idB9AB01LDU,&var100);
  setData(idB9AZ03LDU,&var101);
  setData(idA9AB02LDU,&var185);
  setData(idA9AB01LDU,&var184);
  setData(idA9AZ03LDU,&var183);
  setData(idA9AD10LDU,&var1521);
  setData(idB9AD10LDU,&var1515);
  setData(idR1VS01IDU,&var1682);
  setData(idR2VS01IDU,&var1673);
  setData(idR4VS01IDU,&var1854);
  setData(idA6VS01IDU,&var1872);
  setData(idB5VS01IDU,&var1836);
  setData(idA5VS01IDU,&var1845);
  setData(idB4VS22LDU,&var1817);
  setData(idB4VS12LDU,&var1816);
  setData(idB4VS01IDU,&var1818);
  setData(idA4VS22LDU,&var1826);
  setData(idA4VS12LDU,&var1825);
  setData(idA4VS01IDU,&var1827);
  setData(idA2VS01IDU,&var1745);
  setData(idB3VS01IDU,&var1563);
  setData(idA3VS01IDU,&var1595);
  setData(idB1VS01IDU,&var1624);
  setData(idA1VS01IDU,&var1657);
  setData(idR0VS21IDU,&var1406);
  setData(idR0VX03LDU,&var1014);
  setData(idR0VL21IDU,&var1316);
  setData(idR0VL05RDU,&var679);
  setData(idR0VL03RDU,&var685);
  setData(idR0AB02LDU,&var1379);
  setData(idR0AB06LDU,&var1382);
  setData(idR0AB04LDU,&var1390);
  setData(idR0VL04RDU,&var682);
  setData(idR0VL02RDU,&var676);
  setData(idB3AD33LDU,&var1473);
  setData(idR0VL06RDU,&var689);
  setData(idR0VL11IDU,&var1527);
  setData(idR0VL01IDU,&var1528);
  setData(idR0VX01LDU,&var1071);
  setData(idB1AD32LDU,&var1481);
  setData(idA1AD32LDU,&var1483);
  setData(idB2AD32LDU,&var626);
  setData(idA2AD32LDU,&var628);
  setData(idB1AD31LDU,&var1484);
  setData(idA1AD31LDU,&var1485);
  setData(idB2AD31LDU,&var629);
  setData(idA2AD31LDU,&var630);
  setData(idB3AB20LDU,&var132);
  setData(idB3AB18LDU,&var135);
  setData(idB3AB17LDU,&var133);
  setData(idB3AB16LDU,&var134);
  setData(idB3AB14LDU,&var136);
  setData(idB3AB12LDU,&var140);
  setData(idB3AB11LDU,&var141);
  setData(idB3AB10LDU,&var142);
  setData(idB3AB09LDU,&var143);
  setData(idB3AB06LDU,&var146);
  setData(idB3AB05LDU,&var147);
  setData(idB3AB08LDU,&var144);
  setData(idB3AB07LDU,&var145);
  setData(idB3CV02RDU,&var1562);
  setData(idB3AD01LDU,&var1555);
  setData(idB3AD05LDU,&var1561);
  setData(idB3AD04LDU,&var1560);
  setData(idB3AD03LDU,&var1559);
  setData(idB3AD02LDU,&var1558);
  setData(idB3AD21LDU,&var1556);
  setData(idB3AD11LDU,&var1557);
  setData(idB3AZ03LDU,&var151);
  setData(idB3VS22LDU,&var1566);
  setData(idB3AB01LDU,&var149);
  setData(idB3AB02LDU,&var148);
  setData(idB3AB04LDU,&var150);
  setData(idB3VS12LDU,&var1567);
  setData(idA3AB20LDU,&var216);
  setData(idA3AB18LDU,&var218);
  setData(idA3AB17LDU,&var219);
  setData(idA3AB16LDU,&var220);
  setData(idA3AB14LDU,&var222);
  setData(idA3AB12LDU,&var224);
  setData(idA3AB11LDU,&var225);
  setData(idA3AB10LDU,&var226);
  setData(idA3AB09LDU,&var227);
  setData(idA3AB06LDU,&var229);
  setData(idA3AB05LDU,&var231);
  setData(idA3AB08LDU,&var228);
  setData(idA3AB07LDU,&var230);
  setData(idA3CV02RDU,&var1594);
  setData(idA3AD01LDU,&var1587);
  setData(idA3AD05LDU,&var1593);
  setData(idA3AD04LDU,&var1592);
  setData(idA3AD03LDU,&var1591);
  setData(idA3AD02LDU,&var1590);
  setData(idA3AD21LDU,&var1588);
  setData(idA3AD11LDU,&var1589);
  setData(idA3AZ03LDU,&var235);
  setData(idA3VS22LDU,&var1598);
  setData(idA3AB01LDU,&var232);
  setData(idA3AB02LDU,&var233);
  setData(idA3AB04LDU,&var234);
  setData(idA3CV01RDU,&var1600);
  setData(idA3VS12LDU,&var1599);
  setData(idB1AB18LDU,&var165);
  setData(idB1AB17LDU,&var166);
  setData(idB1AB16LDU,&var167);
  setData(idB1AB14LDU,&var169);
  setData(idB1AB13LDU,&var170);
  setData(idB1AB12LDU,&var171);
  setData(idB1AB11LDU,&var172);
  setData(idB1AB10LDU,&var173);
  setData(idB1AB09LDU,&var174);
  setData(idB1AB06LDU,&var176);
  setData(idB1AB05LDU,&var178);
  setData(idB1AB08LDU,&var175);
  setData(idB1AB07LDU,&var177);
  setData(idB1CV02RDU,&var1623);
  setData(idB1AD01LDU,&var1616);
  setData(idB1AD05LDU,&var1622);
  setData(idB1AD04LDU,&var1621);
  setData(idB1AD03LDU,&var1620);
  setData(idB1AD02LDU,&var1619);
  setData(idB1AD21LDU,&var1618);
  setData(idB1AD11LDU,&var1617);
  setData(idB1AZ03LDU,&var182);
  setData(idB1VS22LDU,&var1628);
  setData(idB1AB01LDU,&var179);
  setData(idB1AB02LDU,&var180);
  setData(idB1AB04LDU,&var181);
  setData(idB1CV01RDU,&var1629);
  setData(idB1VS12LDU,&var1627);
  setData(idA1AB18LDU,&var250);
  setData(idA1AB17LDU,&var251);
  setData(idA1AB16LDU,&var252);
  setData(idA1AB14LDU,&var253);
  setData(idA1AB13LDU,&var254);
  setData(idA1AB12LDU,&var255);
  setData(idA1AB11LDU,&var256);
  setData(idA1AB10LDU,&var257);
  setData(idA1AB09LDU,&var258);
  setData(idA1AB06LDU,&var261);
  setData(idA1AB05LDU,&var262);
  setData(idA1AB08LDU,&var259);
  setData(idA1AB07LDU,&var260);
  setData(idA1CV02RDU,&var1656);
  setData(idA1AD01LDU,&var1649);
  setData(idA1AD05LDU,&var1655);
  setData(idA1AD04LDU,&var1654);
  setData(idA1AD03LDU,&var1653);
  setData(idA1AD02LDU,&var1652);
  setData(idA1AD21LDU,&var1651);
  setData(idA1AD11LDU,&var1650);
  setData(idA1AZ03LDU,&var266);
  setData(idA1VS22LDU,&var1659);
  setData(idA1AB01LDU,&var265);
  setData(idA1AB02LDU,&var264);
  setData(idA1AB04LDU,&var263);
  setData(idA1CV01RDU,&var1660);
  setData(idA1VS12LDU,&var1658);
  setData(idR1AD20LDU,&var1681);
  setData(idR1AD10LDU,&var1680);
  setData(idR2AB04LDU,&var84);
  setData(idR1AB04LDU,&var88);
  setData(idR2AB02LDU,&var85);
  setData(idR2AB01LDU,&var86);
  setData(idR2AZ03LDU,&var87);
  setData(idR1AB02LDU,&var89);
  setData(idR1AB01LDU,&var90);
  setData(idR1AZ03LDU,&var91);
  setData(idB2AB17LDU,&var152);
  setData(idB2AB16LDU,&var153);
  setData(idB2AB14LDU,&var155);
  setData(idB2AB13LDU,&var156);
  setData(idB2AB12LDU,&var157);
  setData(idB2AB11LDU,&var158);
  setData(idB2AB10LDU,&var159);
  setData(idB2AB09LDU,&var160);
  setData(idB2AB06LDU,&var163);
  setData(idB2AB05LDU,&var164);
  setData(idB2AB08LDU,&var161);
  setData(idB2AB07LDU,&var162);
  setData(idB2CV02RDU,&var1703);
  setData(idB2AD01LDU,&var1696);
  setData(idB2AD05LDU,&var1702);
  setData(idB2AD04LDU,&var1701);
  setData(idB2AD03LDU,&var1700);
  setData(idB2AD02LDU,&var1699);
  setData(idB2AD21LDU,&var1698);
  setData(idB2AD11LDU,&var1697);
  setData(idB2AZ03LDU,&var272);
  setData(idB2AB01LDU,&var273);
  setData(idB2AB02LDU,&var274);
  setData(idB2AB04LDU,&var271);
  setData(idB2CV01RDU,&var1707);
  setData(idA2CV02RDU,&var1744);
  setData(idA2AD01LDU,&var1737);
  setData(idA2AB17LDU,&var236);
  setData(idA2AB16LDU,&var237);
  setData(idA2AB14LDU,&var239);
  setData(idA2AB13LDU,&var240);
  setData(idA2AB12LDU,&var241);
  setData(idA2AB11LDU,&var242);
  setData(idA2AB10LDU,&var243);
  setData(idA2AB09LDU,&var244);
  setData(idA2AB06LDU,&var246);
  setData(idA2AB05LDU,&var248);
  setData(idA2AB08LDU,&var245);
  setData(idA2AB07LDU,&var247);
  setData(idA2AD05LDU,&var1743);
  setData(idA2AD04LDU,&var1742);
  setData(idA2AD03LDU,&var1741);
  setData(idA2AD02LDU,&var1740);
  setData(idA2AD21LDU,&var1739);
  setData(idA2AD11LDU,&var1738);
  setData(idA2AZ03LDU,&var270);
  setData(idA2VS21LDU,&var1749);
  setData(idA2AB01LDU,&var269);
  setData(idA2AB02LDU,&var268);
  setData(idA2AB04LDU,&var267);
  setData(idA2CV01RDU,&var1750);
  setData(idA2VS11LDU,&var1748);
  setData(idA8AB01LDU,&var199);
  setData(idA8AB02LDU,&var198);
  setData(idA8AB14LDU,&var186);
  setData(idA8AB13LDU,&var187);
  setData(idA8AB12LDU,&var188);
  setData(idA8AB11LDU,&var189);
  setData(idA8AB10LDU,&var190);
  setData(idA8AB09LDU,&var191);
  setData(idA8AB08LDU,&var192);
  setData(idA8AB04LDU,&var197);
  setData(idA8AD20LDU,&var1715);
  setData(idA8AD10LDU,&var1714);
  setData(idA8AZ03LDU,&var196);
  setData(idA8VS22LDU,&var1762);
  setData(idA8AB05LDU,&var193);
  setData(idA8AB07LDU,&var194);
  setData(idA8AB06LDU,&var195);
  setData(idA8CV01RDU,&var1763);
  setData(idA8VS12LDU,&var1761);
  setData(idB8AB02LDU,&var113);
  setData(idB8AB14LDU,&var102);
  setData(idB8AB13LDU,&var103);
  setData(idB8AB12LDU,&var104);
  setData(idB8AB11LDU,&var105);
  setData(idB8AB10LDU,&var106);
  setData(idB8AB09LDU,&var107);
  setData(idB8AB08LDU,&var108);
  setData(idB8AB04LDU,&var114);
  setData(idB8AB01LDU,&var115);
  setData(idB8AD20LDU,&var1725);
  setData(idB8AD10LDU,&var1724);
  setData(idB8AZ03LDU,&var112);
  setData(idB8VS22LDU,&var1779);
  setData(idB8AB05LDU,&var109);
  setData(idB8AB07LDU,&var110);
  setData(idB8AB06LDU,&var111);
  setData(idB8CV01RDU,&var1780);
  setData(idB8VS12LDU,&var1778);
  setData(idA6AB05LDU,&var204);
  setData(idB6AB09LDU,&var116);
  setData(idB6AB08LDU,&var117);
  setData(idB6AB07LDU,&var118);
  setData(idB6AB06LDU,&var119);
  setData(idA6AB09LDU,&var200);
  setData(idA6AB08LDU,&var201);
  setData(idA6AB07LDU,&var202);
  setData(idA6AB06LDU,&var203);
  setData(idB5AB04LDU,&var125);
  setData(idA5AB04LDU,&var210);
  setData(idB4AB02LDU,&var129);
  setData(idB4AB01LDU,&var130);
  setData(idB4AZ03LDU,&var131);
  setData(idA4AB02LDU,&var214);
  setData(idA4AB01LDU,&var215);
  setData(idA4AZ03LDU,&var213);
  setData(idA4AD10LDU,&var1824);
  setData(idB4AD10LDU,&var1815);
  setData(idB5AB02LDU,&var126);
  setData(idB5AB01LDU,&var127);
  setData(idB5AZ03LDU,&var128);
  setData(idA5AB02LDU,&var211);
  setData(idA5AB01LDU,&var212);
  setData(idA5AZ03LDU,&var209);
  setData(idA5AD20LDU,&var1844);
  setData(idA5AD10LDU,&var1843);
  setData(idB5AD20LDU,&var1835);
  setData(idB5AD10LDU,&var1834);
  setData(idR4AD20LDU,&var1853);
  setData(idR4AD10LDU,&var1852);
  setData(idR4AB18LDU,&var65);
  setData(idR4AB17LDU,&var66);
  setData(idR4AB16LDU,&var67);
  setData(idR4AB15LDU,&var68);
  setData(idR4AB14LDU,&var69);
  setData(idR4AB13LDU,&var70);
  setData(idR4AB12LDU,&var71);
  setData(idR4AB11LDU,&var83);
  setData(idR4AB10LDU,&var72);
  setData(idR4AB09LDU,&var73);
  setData(idR4AB08LDU,&var74);
  setData(idR4AB07LDU,&var75);
  setData(idR4AB06LDU,&var76);
  setData(idR4AB05LDU,&var77);
  setData(idR4AB04LDU,&var78);
  setData(idR4AB03LDU,&var80);
  setData(idR4AZ03LDU,&var79);
  setData(idR4AB02LDU,&var81);
  setData(idR4AB01LDU,&var82);
  setData(idB6AB04LDU,&var121);
  setData(idA6AB04LDU,&var206);
  setData(idB6AB02LDU,&var123);
  setData(idB6AB01LDU,&var122);
  setData(idB6AZ03LDU,&var124);
  setData(idA6AB02LDU,&var207);
  setData(idA6AB01LDU,&var208);
  setData(idA6AZ03LDU,&var205);
  setData(idB6AD20LDU,&var1862);
  setData(idB6AD10LDU,&var1861);
  setData(idA6AD20LDU,&var1871);
  setData(idA6AD10LDU,&var1870);
  setData(idR0ES01LDU,&var1153);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<10;i++ )
    array_m352_rz_1[i] = &(&internal1_m352_rz)[i*1];
  for( i=0;i<10;i++ )
    array_m294_rz_1[i] = &(&internal1_m294_rz)[i*1];
  for( i=0;i<6;i++ )
    array_m1596_rz_1[i] = &(&internal1_m1596_rz)[i*1];
  for( i=0;i<60;i++ )
    array_m1505_x0_1[i] = &(&internal1_m1505_x0)[i*5];
  for( i=0;i<60;i++ )
    array_m1505_tim0_1[i] = &(&internal1_m1505_tim0)[i*5];
  for( i=0;i<60;i++ )
    array_m1031_x0_1[i] = &(&internal1_m1031_x0)[i*5];
  for( i=0;i<60;i++ )
    array_m1031_tim0_1[i] = &(&internal1_m1031_tim0)[i*5];
  for( i=0;i<150;i++ )
    array_m569_x0_1[i] = &(&internal1_m569_x0)[i*5];
  for( i=0;i<150;i++ )
    array_m569_tim0_1[i] = &(&internal1_m569_tim0)[i*5];
  for( i=0;i<150;i++ )
    array_m201_x0_1[i] = &(&internal1_m201_x0)[i*5];
  for( i=0;i<150;i++ )
    array_m201_tim0_1[i] = &(&internal1_m201_tim0)[i*5];
  for( i=0;i<80;i++ )
    array_m923_x0_1[i] = &(&internal1_m923_x0)[i*5];
  for( i=0;i<80;i++ )
    array_m923_tim0_1[i] = &(&internal1_m923_tim0)[i*5];
  for( i=0;i<80;i++ )
    array_m1401_x0_1[i] = &(&internal1_m1401_x0)[i*5];
  for( i=0;i<80;i++ )
    array_m1401_tim0_1[i] = &(&internal1_m1401_tim0)[i*5];
  for( i=0;i<20;i++ )
    array_m1822_x0_1[i] = &(&internal1_m1822_x0)[i*5];
  for( i=0;i<20;i++ )
    array_m1822_tim0_1[i] = &(&internal1_m1822_tim0)[i*5];
  for( i=0;i<20;i++ )
    array_m1296_x0_1[i] = &(&internal1_m1296_x0)[i*5];
  for( i=0;i<20;i++ )
    array_m1296_tim0_1[i] = &(&internal1_m1296_tim0)[i*5];
}

void MainCycle(void)
{
if ((getAsShort(idR0MW11IP1) == 2) || (getAsShort(idR0MW11IP1) == 3)) { 
     if(delay++ < 200) return;
     freebuff = 0;
     delay = delay > 32000 ? 32000 : delay; 
       Scheme(); 
 }
 else {
      delay = 0;
      if (freebuff)
            return;
       else{
           freebuff = 1;
           memset(BUFFER, 0, SIZE_BUFFER);
           InitSetConst();
           ZeroVar();
           if (SimulOn) {
                 if (initAllSimul(CodeSub, drivers, SimulIP, SimulPort))
           return EXIT_FAILURE;
           } else {
                 if (initAllDrivers(drivers))
                 return EXIT_FAILURE;
           }
           }
       }


}
#endif
