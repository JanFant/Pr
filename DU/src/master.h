#ifndef DU_H
#define DU_H
// Подсистема DU:DU
static char SimulOn=0;
static short CodeSub=2;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt, taktScheme=0, taktSS=0;
#define SIZE_BUFFER 12184
static char BUFFER[12184];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.50\0", 5432, "192.168.10.150\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R6IS52LDU	 BUFFER[0]	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define idR6IS52LDU	 1	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
#define R6IS51LDU	 BUFFER[2]	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define idR6IS51LDU	 2	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
#define R3IS11LDU	 BUFFER[4]	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	 3	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
#define R3IS21LDU	 BUFFER[6]	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define idR3IS21LDU	 4	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
#define R0AB03LDU	 BUFFER[8]	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define idR0AB03LDU	 5	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
#define R0AB05LDU	 BUFFER[10]	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define idR0AB05LDU	 6	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
#define R0VN11RZ1	 BUFFER[12]	//( - , MDuBz1) Средняя мощность по BAZ1
#define idR0VN11RZ1	 7	//( - , MDuBz1) Средняя мощность по BAZ1
#define R0VN11RZ2	 BUFFER[17]	//( - , MDuBz2) Средняя мощность по BAZ2
#define idR0VN11RZ2	 8	//( - , MDuBz2) Средняя мощность по BAZ2
#define A2AB15LDU	 BUFFER[22]	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idA2AB15LDU	 9	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define B2AB15LDU	 BUFFER[24]	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define idB2AB15LDU	 10	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
#define R0AD21LDU	 BUFFER[26]	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define idR0AD21LDU	 11	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
#define R0VX02LDU	 BUFFER[28]	//( - , DU) Импульс разрешен
#define idR0VX02LDU	 12	//( - , DU) Импульс разрешен
#define R0EE03LDU	 BUFFER[30]	//( - , DU) ВПИС ИС
#define idR0EE03LDU	 13	//( - , DU) ВПИС ИС
#define R0AB07LDU	 BUFFER[32]	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define idR0AB07LDU	 14	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
#define C2MD31LP1	 BUFFER[34]	//( - , DU) Кнопка СБРОС РБ
#define idC2MD31LP1	 15	//( - , DU) Кнопка СБРОС РБ
#define B6VS01IDU	 BUFFER[36]	//( - , DU) Готовность к управлению БЗ2
#define idB6VS01IDU	 16	//( - , DU) Готовность к управлению БЗ2
#define R2AD20LDU	 BUFFER[39]	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	 17	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
#define R2AD10LDU	 BUFFER[41]	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define idR2AD10LDU	 18	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
#define B8VS01IDU	 BUFFER[43]	//( - , DU) Готовность к управлению АЗ2
#define idB8VS01IDU	 19	//( - , DU) Готовность к управлению АЗ2
#define A8VS01IDU	 BUFFER[46]	//( - , DU) Готовность к управлению ДС2
#define idA8VS01IDU	 20	//( - , DU) Готовность к управлению ДС2
#define A1IE03LDU	 BUFFER[49]	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 21	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[51]	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 22	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
#define A2IE03LDU	 BUFFER[53]	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define idA2IE03LDU	 23	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
#define A2IS33LDU	 BUFFER[55]	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define idA2IS33LDU	 24	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
#define A3IS31LDU	 BUFFER[57]	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define idA3IS31LDU	 25	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
#define A3IS33LDU	 BUFFER[59]	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define idA3IS33LDU	 26	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
#define A3IS35LDU	 BUFFER[61]	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define idA3IS35LDU	 27	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
#define A4IS10LDU	 BUFFER[63]	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define idA4IS10LDU	 28	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
#define A1VN71LZ1	 BUFFER[65]	//(vds32:02 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define idA1VN71LZ1	 29	//(vds32:02 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define A1VN71LZ2	 BUFFER[67]	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define idA1VN71LZ2	 30	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
#define A1AB19LDU	 BUFFER[69]	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define idA1AB19LDU	 31	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
#define R0AD14LZ1	 BUFFER[71]	//(vds32:02 - K20VDSR, DU) Имитация срабатывания АЗ от II УР
#define idR0AD14LZ1	 32	//(vds32:02 - K20VDSR, DU) Имитация срабатывания АЗ от II УР
#define R0AD14LZ2	 BUFFER[73]	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define idR0AD14LZ2	 33	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
#define A3VZ13LZ2	 BUFFER[75]	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ2	 34	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ13LZ1	 BUFFER[77]	//(vds32:02 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define idA3VZ13LZ1	 35	//(vds32:02 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
#define A3VZ15LZ1	 BUFFER[79]	//(vds32:02 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ1	 36	//(vds32:02 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define A3VZ15LZ2	 BUFFER[81]	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define idA3VZ15LZ2	 37	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
#define B2IS33LDU	 BUFFER[83]	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define idB2IS33LDU	 38	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
#define B3IS31LDU	 BUFFER[85]	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define idB3IS31LDU	 39	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
#define B3IS33LDU	 BUFFER[87]	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define idB3IS33LDU	 40	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
#define B3IS35LDU	 BUFFER[89]	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define idB3IS35LDU	 41	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
#define B4IS10LDU	 BUFFER[91]	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define idB4IS10LDU	 42	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
#define R6IS31LDU	 BUFFER[93]	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define idR6IS31LDU	 43	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
#define R6IS32LDU	 BUFFER[95]	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define idR6IS32LDU	 44	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
#define R6IS42LDU	 BUFFER[97]	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define idR6IS42LDU	 45	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
#define R6IS41LDU	 BUFFER[99]	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define idR6IS41LDU	 46	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
#define A6ZAV	 BUFFER[101]	//( - , DU) 
#define idA6ZAV	 47	//( - , DU) 
#define R2ZAV	 BUFFER[103]	//( - , DU) 
#define idR2ZAV	 48	//( - , DU) 
#define A5ZAV	 BUFFER[105]	//( - , DU) 
#define idA5ZAV	 49	//( - , DU) 
#define B8ZAV	 BUFFER[107]	//( - , DU) 
#define idB8ZAV	 50	//( - , DU) 
#define A2ZAV	 BUFFER[109]	//( - , DU) Завершение РБ1,2
#define idA2ZAV	 51	//( - , DU) Завершение РБ1,2
#define A8ZAV	 BUFFER[111]	//( - , DU) 
#define idA8ZAV	 52	//( - , DU) 
#define A9ZAV	 BUFFER[113]	//( - , DU) Завершение НИ ДС1(2)
#define idA9ZAV	 53	//( - , DU) Завершение НИ ДС1(2)
#define R4ABL	 BUFFER[115]	//( - , DU) Блокировка тележки -
#define idR4ABL	 54	//( - , DU) Блокировка тележки -
#define A4UP	 BUFFER[117]	//( - , DU) 
#define idA4UP	 55	//( - , DU) 
#define A4DW	 BUFFER[119]	//( - , DU) 
#define idA4DW	 56	//( - , DU) 
#define R0AB14LDU	 BUFFER[121]	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define idR0AB14LDU	 57	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
#define R0AB15LDU	 BUFFER[123]	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define idR0AB15LDU	 58	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
#define A3IS12LDU	 BUFFER[125]	//( - , DU) Приход на ВУ штока ИС1
#define idA3IS12LDU	 59	//( - , DU) Приход на ВУ штока ИС1
#define B3IS12LDU	 BUFFER[127]	//( - , DU) Приход на ВУ штока ИС2
#define idB3IS12LDU	 60	//( - , DU) Приход на ВУ штока ИС2
#define A1ZAV	 BUFFER[129]	//( - , DU) 
#define idA1ZAV	 61	//( - , DU) 
#define A3ZAV	 BUFFER[131]	//( - , DU) 
#define idA3ZAV	 62	//( - , DU) 
#define B1AB19LDU	 BUFFER[133]	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define idB1AB19LDU	 63	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
#define R0AB16LDU	 BUFFER[135]	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define idR0AB16LDU	 64	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
#define R0AB17LDU	 BUFFER[137]	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define idR0AB17LDU	 65	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
#define R0AB18LDU	 BUFFER[139]	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define idR0AB18LDU	 66	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
#define A0CT01IZ1	 BUFFER[141]	//( - , MDuBz1) Температура АЗ1-1
#define idA0CT01IZ1	 67	//( - , MDuBz1) Температура АЗ1-1
#define B0CT01IZ1	 BUFFER[146]	//( - , MDuBz1) Температура АЗ2-1
#define idB0CT01IZ1	 68	//( - , MDuBz1) Температура АЗ2-1
#define A0CT01IZ2	 BUFFER[151]	//( - , MDuBz2) Температура АЗ1-2
#define idA0CT01IZ2	 69	//( - , MDuBz2) Температура АЗ1-2
#define A2IE04LDU	 BUFFER[156]	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define idA2IE04LDU	 70	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
#define A3IE03LDU	 BUFFER[158]	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define idA3IE03LDU	 71	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
#define A3IE04LDU	 BUFFER[160]	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define idA3IE04LDU	 72	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
#define B1IE03LDU	 BUFFER[162]	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 73	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
#define B1IE04LDU	 BUFFER[164]	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 74	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
#define B2IE03LDU	 BUFFER[166]	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define idB2IE03LDU	 75	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
#define B2IE04LDU	 BUFFER[168]	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define idB2IE04LDU	 76	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
#define B3IE03LDU	 BUFFER[170]	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define idB3IE03LDU	 77	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
#define B3IE04LDU	 BUFFER[172]	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define idB3IE04LDU	 78	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
#define R0VS11LDU	 BUFFER[174]	//( - , DU) РУ не готова к работе
#define idR0VS11LDU	 79	//( - , DU) РУ не готова к работе
#define B6AB05LDU	 BUFFER[176]	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define idB6AB05LDU	 80	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
#define R0AB08LDU	 BUFFER[178]	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define idR0AB08LDU	 81	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
#define A1MC01RP1	 BUFFER[180]	//( - , DU) Заданная координата положения ББ1 мм
#define idA1MC01RP1	 82	//( - , DU) Заданная координата положения ББ1 мм
#define B1MC01RP1	 BUFFER[185]	//( - , DU) Заданная координата положения ББ2  мм
#define idB1MC01RP1	 83	//( - , DU) Заданная координата положения ББ2  мм
#define A3MC01RP1	 BUFFER[190]	//( - , DU) Заданная координата положения ИС1 мм
#define idA3MC01RP1	 84	//( - , DU) Заданная координата положения ИС1 мм
#define B3MC01RP1	 BUFFER[195]	//( - , DU) Заданная координата положения ИС2 мм
#define idB3MC01RP1	 85	//( - , DU) Заданная координата положения ИС2 мм
#define B8MC01RP2	 BUFFER[200]	//( - , DU) Заданная координата АЗ2 мм
#define idB8MC01RP2	 86	//( - , DU) Заданная координата АЗ2 мм
#define R0AB09LDU	 BUFFER[205]	//( - , DU) Ошибка в заданной координате ББ1
#define idR0AB09LDU	 87	//( - , DU) Ошибка в заданной координате ББ1
#define R0AB10LDU	 BUFFER[207]	//( - , DU) Ошибка в заданной координате ББ2
#define idR0AB10LDU	 88	//( - , DU) Ошибка в заданной координате ББ2
#define R0AB11LDU	 BUFFER[209]	//( - , DU) Ошибка в заданной координате  ИС1
#define idR0AB11LDU	 89	//( - , DU) Ошибка в заданной координате  ИС1
#define R0AB12LDU	 BUFFER[211]	//( - , DU) Ошибка в заданной координате  ИС2
#define idR0AB12LDU	 90	//( - , DU) Ошибка в заданной координате  ИС2
#define R0AB13LDU	 BUFFER[213]	//( - , DU) Ошибка в заданной координате  АЗ2
#define idR0AB13LDU	 91	//( - , DU) Ошибка в заданной координате  АЗ2
#define A4ZAV	 BUFFER[215]	//( - , DU) 
#define idA4ZAV	 92	//( - , DU) 
#define A9AD10LDU	 BUFFER[217]	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define idA9AD10LDU	 93	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
#define A9AZ03LDU	 BUFFER[219]	//( - , DU) Несанкционированное перемещение НИ ДС1
#define idA9AZ03LDU	 94	//( - , DU) Несанкционированное перемещение НИ ДС1
#define A9AB01LDU	 BUFFER[221]	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define idA9AB01LDU	 95	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
#define A9AB02LDU	 BUFFER[223]	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define idA9AB02LDU	 96	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
#define B9AZ03LDU	 BUFFER[225]	//( - , DU) Несанкционированное перемещение НИ ДС2
#define idB9AZ03LDU	 97	//( - , DU) Несанкционированное перемещение НИ ДС2
#define B9AB01LDU	 BUFFER[227]	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define idB9AB01LDU	 98	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
#define B9AB02LDU	 BUFFER[229]	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define idB9AB02LDU	 99	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
#define R0AB01LDU	 BUFFER[231]	//( - , DU) Режим проверки разрешён
#define idR0AB01LDU	 100	//( - , DU) Режим проверки разрешён
#define A3IS22LDU	 BUFFER[233]	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define idA3IS22LDU	 101	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
#define B3IS22LDU	 BUFFER[235]	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define idB3IS22LDU	 102	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
#define A2AD33LDU	 BUFFER[237]	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define idA2AD33LDU	 103	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
#define B2AD33LDU	 BUFFER[239]	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define idB2AD33LDU	 104	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
#define A3AD33LDU	 BUFFER[241]	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define idA3AD33LDU	 105	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
#define A3AD34LDU	 BUFFER[243]	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define idA3AD34LDU	 106	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
#define A3AD31LDU	 BUFFER[245]	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define idA3AD31LDU	 107	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
#define B3AD34LDU	 BUFFER[247]	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define idB3AD34LDU	 108	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
#define B3AD31LDU	 BUFFER[249]	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define idB3AD31LDU	 109	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
#define A2IS11LDU	 BUFFER[251]	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define idA2IS11LDU	 110	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
#define B2IS11LDU	 BUFFER[253]	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define idB2IS11LDU	 111	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
#define A3MD12LP1	 BUFFER[255]	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define idA3MD12LP1	 112	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
#define A3MD11LP1	 BUFFER[257]	//( - , DU) Кнопка ПУСК ИС1
#define idA3MD11LP1	 113	//( - , DU) Кнопка ПУСК ИС1
#define R0MD33LP1	 BUFFER[259]	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define idR0MD33LP1	 114	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
#define A1MD12LP1	 BUFFER[261]	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define idA1MD12LP1	 115	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
#define R0VS21IDU	 BUFFER[263]	//( - , DU) Индикация ВИД ПРОВЕРКИ
#define idR0VS21IDU	 116	//( - , DU) Индикация ВИД ПРОВЕРКИ
#define A1VS01IDU	 BUFFER[266]	//( - , DU) Готовность к управлению ББ1
#define idA1VS01IDU	 117	//( - , DU) Готовность к управлению ББ1
#define B1VS01IDU	 BUFFER[269]	//( - , DU) Готовность к управлению ББ2
#define idB1VS01IDU	 118	//( - , DU) Готовность к управлению ББ2
#define A3VS01IDU	 BUFFER[272]	//( - , DU) Готовность к управлению ИС1
#define idA3VS01IDU	 119	//( - , DU) Готовность к управлению ИС1
#define B3VS01IDU	 BUFFER[275]	//( - , DU) Готовность к управлению ИС2
#define idB3VS01IDU	 120	//( - , DU) Готовность к управлению ИС2
#define A2VS01IDU	 BUFFER[278]	//( - , DU) Готовность к управлению РБ1
#define idA2VS01IDU	 121	//( - , DU) Готовность к управлению РБ1
#define A4VS01IDU	 BUFFER[281]	//( - , DU) Готовность к управлению НИ1
#define idA4VS01IDU	 122	//( - , DU) Готовность к управлению НИ1
#define A4VS12LDU	 BUFFER[284]	//( - , DU) Движение НИ1 в сторону ВУ
#define idA4VS12LDU	 123	//( - , DU) Движение НИ1 в сторону ВУ
#define A4VS22LDU	 BUFFER[286]	//( - , DU) Движение НИ1 в сторону НУ
#define idA4VS22LDU	 124	//( - , DU) Движение НИ1 в сторону НУ
#define B4VS01IDU	 BUFFER[288]	//( - , DU) Готовность к управлению НИ2
#define idB4VS01IDU	 125	//( - , DU) Готовность к управлению НИ2
#define B4VS12LDU	 BUFFER[291]	//( - , DU) Движение НИ2 в сторону ВУ
#define idB4VS12LDU	 126	//( - , DU) Движение НИ2 в сторону ВУ
#define B4VS22LDU	 BUFFER[293]	//( - , DU) Движение НИ2 в сторону НУ
#define idB4VS22LDU	 127	//( - , DU) Движение НИ2 в сторону НУ
#define A5VS01IDU	 BUFFER[295]	//( - , DU) Готовность к управлению НЛ1
#define idA5VS01IDU	 128	//( - , DU) Готовность к управлению НЛ1
#define B5VS01IDU	 BUFFER[298]	//( - , DU) Готовность к управлению НЛ2
#define idB5VS01IDU	 129	//( - , DU) Готовность к управлению НЛ2
#define A6VS01IDU	 BUFFER[301]	//( - , DU) Готовность к управлению БЗ1
#define idA6VS01IDU	 130	//( - , DU) Готовность к управлению БЗ1
#define R4VS01IDU	 BUFFER[304]	//( - , DU) Готовность к управлению тележкой реактора
#define idR4VS01IDU	 131	//( - , DU) Готовность к управлению тележкой реактора
#define R2VS01IDU	 BUFFER[307]	//( - , DU) Готовность к управлению МДЗ2
#define idR2VS01IDU	 132	//( - , DU) Готовность к управлению МДЗ2
#define R1VS01IDU	 BUFFER[310]	//( - , DU) Готовность к управлению МДЗ1
#define idR1VS01IDU	 133	//( - , DU) Готовность к управлению МДЗ1
#define A9IS11LDU	 BUFFER[313]	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 134	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
#define A9IS21LDU	 BUFFER[315]	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
#define idA9IS21LDU	 135	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
#define B9IS11LDU	 BUFFER[317]	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 136	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
#define B9IS21LDU	 BUFFER[319]	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
#define idB9IS21LDU	 137	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
#define B9AD10LDU	 BUFFER[321]	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define idB9AD10LDU	 138	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
#define R0IS01LDU	 BUFFER[323]	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define idR0IS01LDU	 139	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
#define R0IS02LDU	 BUFFER[325]	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define idR0IS02LDU	 140	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
#define R0VP73LZ1	 BUFFER[327]	//( - , MDuBz1) ПС давления для РУ
#define idR0VP73LZ1	 141	//( - , MDuBz1) ПС давления для РУ
#define R0VP73LZ2	 BUFFER[329]	//( - , MDuBz2) ПС давления для РУ
#define idR0VP73LZ2	 142	//( - , MDuBz2) ПС давления для РУ
#define R0VP73LDU	 BUFFER[331]	//( - , DU) ПС давления для РУ
#define idR0VP73LDU	 143	//( - , DU) ПС давления для РУ
#define R0MD34LP1	 BUFFER[333]	//( - , DU) Кнопка КВИТИРОВАТЬ
#define idR0MD34LP1	 144	//( - , DU) Кнопка КВИТИРОВАТЬ
#define A0VT71LZ1	 BUFFER[335]	//( - , MDuBz1) АС по температуре в АЗ1
#define idA0VT71LZ1	 145	//( - , MDuBz1) АС по температуре в АЗ1
#define B0VT71LZ1	 BUFFER[337]	//( - , MDuBz1) АС по температуре в АЗ2
#define idB0VT71LZ1	 146	//( - , MDuBz1) АС по температуре в АЗ2
#define A0VT71LZ2	 BUFFER[339]	//( - , MDuBz2) АС по температуре в АЗ1
#define idA0VT71LZ2	 147	//( - , MDuBz2) АС по температуре в АЗ1
#define B0VT71LZ2	 BUFFER[341]	//( - , MDuBz2) АС по температуре в АЗ2
#define idB0VT71LZ2	 148	//( - , MDuBz2) АС по температуре в АЗ2
#define B2VS11LDU	 BUFFER[343]	//( - , DU) Движение РБ2 в сторону ВУ
#define idB2VS11LDU	 149	//( - , DU) Движение РБ2 в сторону ВУ
#define B2VS21LDU	 BUFFER[345]	//( - , DU) Движение РБ2 в сторону НУ
#define idB2VS21LDU	 150	//( - , DU) Движение РБ2 в сторону НУ
#define B2VS01IDU	 BUFFER[347]	//( - , DU) Готовность к управлению РБ2
#define idB2VS01IDU	 151	//( - , DU) Готовность к управлению РБ2
#define A7AS31LDU	 BUFFER[350]	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define idA7AS31LDU	 152	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
#define B7AS31LDU	 BUFFER[352]	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define idB7AS31LDU	 153	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
#define A7AZ03LDU	 BUFFER[354]	//( - , DU) Несанкционированное включение обдува АЗ1
#define idA7AZ03LDU	 154	//( - , DU) Несанкционированное включение обдува АЗ1
#define B7AZ03LDU	 BUFFER[356]	//( - , DU) Несанкционированное включение обдува АЗ2
#define idB7AZ03LDU	 155	//( - , DU) Несанкционированное включение обдува АЗ2
#define B3MD12LP1	 BUFFER[358]	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define idB3MD12LP1	 156	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
#define B3MD11LP1	 BUFFER[360]	//( - , DU) Кнопка ПУСК ИС2
#define idB3MD11LP1	 157	//( - , DU) Кнопка ПУСК ИС2
#define R0VL01RDU	 BUFFER[362]	//( - , DU) Индикация Время задержки
#define idR0VL01RDU	 158	//( - , DU) Индикация Время задержки
#define R0VZ71LZ2	 BUFFER[367]	//(vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
#define idR0VZ71LZ2	 159	//(vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
#define R0VZ71LZ1	 BUFFER[369]	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define idR0VZ71LZ1	 160	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
#define R0VZ71LDU	 BUFFER[371]	//( - , DU) Обобщенный сигнал АЗ
#define idR0VZ71LDU	 161	//( - , DU) Обобщенный сигнал АЗ
#define A1MD11LP1	 BUFFER[373]	//( - , DU) Кнопка ПУСК ББ1
#define idA1MD11LP1	 162	//( - , DU) Кнопка ПУСК ББ1
#define R0MW14IP2	 BUFFER[375]	//( - , DU) Переключатель ОБДУВ
#define idR0MW14IP2	 163	//( - , DU) Переключатель ОБДУВ
#define A7AP31LDU	 BUFFER[378]	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define idA7AP31LDU	 164	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
#define B7AP31LDU	 BUFFER[380]	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define idB7AP31LDU	 165	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
#define R0MW12IP2	 BUFFER[382]	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define idR0MW12IP2	 166	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
#define R0MW17LP1	 BUFFER[385]	//( - , DU) Переключатель АВТ/Р
#define idR0MW17LP1	 167	//( - , DU) Переключатель АВТ/Р
#define R0VW13LDU	 BUFFER[387]	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define idR0VW13LDU	 168	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
#define R0VW23LDU	 BUFFER[389]	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define idR0VW23LDU	 169	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
#define R0VX08IDU	 BUFFER[391]	//( - , DU) Индикация Режим
#define idR0VX08IDU	 170	//( - , DU) Индикация Режим
#define R0VX09LDU	 BUFFER[394]	//( - , DU) Индикация регулятор мощности включен/отключен
#define idR0VX09LDU	 171	//( - , DU) Индикация регулятор мощности включен/отключен
#define R0VS17LDU	 BUFFER[396]	//( - , DU) Индикация выбора АВТОМАТ
#define idR0VS17LDU	 172	//( - , DU) Индикация выбора АВТОМАТ
#define A2VS32LDU	 BUFFER[398]	//( - , DU) Индикация  СБРОС РБ1
#define idA2VS32LDU	 173	//( - , DU) Индикация  СБРОС РБ1
#define B2VS32LDU	 BUFFER[400]	//( - , DU) Индикация  СБРОС РБ2
#define idB2VS32LDU	 174	//( - , DU) Индикация  СБРОС РБ2
#define A3VX01LDU	 BUFFER[402]	//( - , DU) Индикация Выстрел ИС1
#define idA3VX01LDU	 175	//( - , DU) Индикация Выстрел ИС1
#define B3VX01LDU	 BUFFER[404]	//( - , DU) Индикация Выстрел ИС2
#define idB3VX01LDU	 176	//( - , DU) Индикация Выстрел ИС2
#define R0VS18LDU	 BUFFER[406]	//( - , DU) Индикация  Проверка схем сброса
#define idR0VS18LDU	 177	//( - , DU) Индикация  Проверка схем сброса
#define B1MD11LP1	 BUFFER[408]	//( - , DU) Кнопка ПУСК ББ2
#define idB1MD11LP1	 178	//( - , DU) Кнопка ПУСК ББ2
#define B1MD12LP1	 BUFFER[410]	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define idB1MD12LP1	 179	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
#define B2MD11LP1	 BUFFER[412]	//( - , DU) Кнопка ПУСК РБ2
#define idB2MD11LP1	 180	//( - , DU) Кнопка ПУСК РБ2
#define B2MD12LP1	 BUFFER[414]	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define idB2MD12LP1	 181	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
#define A2MD11LP1	 BUFFER[416]	//( - , DU) Кнопка ПУСК РБ1
#define idA2MD11LP1	 182	//( - , DU) Кнопка ПУСК РБ1
#define A2MD12LP1	 BUFFER[418]	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define idA2MD12LP1	 183	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
#define B3IS11LDU	 BUFFER[420]	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define idB3IS11LDU	 184	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
#define A3IS11LDU	 BUFFER[422]	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define idA3IS11LDU	 185	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
#define B3VP52LDU	 BUFFER[424]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define idB3VP52LDU	 186	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
#define B3VP82LDU	 BUFFER[426]	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define idB3VP82LDU	 187	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
#define A3VP82LDU	 BUFFER[428]	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define idA3VP82LDU	 188	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
#define A3IP02IDU	 BUFFER[430]	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 189	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
#define B3IP02IDU	 BUFFER[433]	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define idB3IP02IDU	 190	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
#define A0VE01LDU	 BUFFER[436]	//( - , DU) Напряжение в системы АЗ1 подано
#define idA0VE01LDU	 191	//( - , DU) Напряжение в системы АЗ1 подано
#define B0VE01LDU	 BUFFER[438]	//( - , DU) Напряжение в системы АЗ2 подано
#define idB0VE01LDU	 192	//( - , DU) Напряжение в системы АЗ2 подано
#define A0VP01LDU	 BUFFER[440]	//( - , DU) Давление в системы АЗ1 подано
#define idA0VP01LDU	 193	//( - , DU) Давление в системы АЗ1 подано
#define B0VP01LDU	 BUFFER[442]	//( - , DU) Давление в системы АЗ2 подано
#define idB0VP01LDU	 194	//( - , DU) Давление в системы АЗ2 подано
#define A0EE01LZ1	 BUFFER[444]	//( - , MDuBz1) Исправность АКНП1
#define idA0EE01LZ1	 195	//( - , MDuBz1) Исправность АКНП1
#define A0EE03LZ1	 BUFFER[446]	//( - , MDuBz1) Исправность АКНП3
#define idA0EE03LZ1	 196	//( - , MDuBz1) Исправность АКНП3
#define A0EE02LZ1	 BUFFER[448]	//( - , MDuBz1) Исправность АКНП2
#define idA0EE02LZ1	 197	//( - , MDuBz1) Исправность АКНП2
#define A0EE04LZ1	 BUFFER[450]	//( - , MDuBz1) Исправность АКНП4
#define idA0EE04LZ1	 198	//( - , MDuBz1) Исправность АКНП4
#define A0VN01LDU	 BUFFER[452]	//( - , DU) Каналы АЗ1 проверены
#define idA0VN01LDU	 199	//( - , DU) Каналы АЗ1 проверены
#define B0VN01LDU	 BUFFER[454]	//( - , DU) Каналы АЗ2 проверены
#define idB0VN01LDU	 200	//( - , DU) Каналы АЗ2 проверены
#define A0EE01LZ2	 BUFFER[456]	//( - , MDuBz2) Исправность АКНП1
#define idA0EE01LZ2	 201	//( - , MDuBz2) Исправность АКНП1
#define A0EE03LZ2	 BUFFER[458]	//( - , MDuBz2) Исправность АКНП3
#define idA0EE03LZ2	 202	//( - , MDuBz2) Исправность АКНП3
#define A0EE02LZ2	 BUFFER[460]	//( - , MDuBz2) Исправность АКНП2
#define idA0EE02LZ2	 203	//( - , MDuBz2) Исправность АКНП2
#define A0EE04LZ2	 BUFFER[462]	//( - , MDuBz2) Исправность АКНП4
#define idA0EE04LZ2	 204	//( - , MDuBz2) Исправность АКНП4
#define A0VP71LZ1	 BUFFER[464]	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ1	 205	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
#define A0VP71LZ2	 BUFFER[466]	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define idA0VP71LZ2	 206	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
#define B0VP71LZ1	 BUFFER[468]	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ1	 207	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
#define B0VP71LZ2	 BUFFER[470]	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define idB0VP71LZ2	 208	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
#define A1VC01RDU	 BUFFER[472]	//( - , DU) Координата ББ1, мм
#define idA1VC01RDU	 209	//( - , DU) Координата ББ1, мм
#define A1IS11LDU	 BUFFER[477]	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define idA1IS11LDU	 210	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
#define B1MC01LC1	 BUFFER[479]	//( - , DU) Настроить энкодер ББ2
#define idB1MC01LC1	 211	//( - , DU) Настроить энкодер ББ2
#define B1MC01LC2	 BUFFER[481]	//( - , DU) Настроить энкодер ББ2
#define idB1MC01LC2	 212	//( - , DU) Настроить энкодер ББ2
#define A1MC01LC1	 BUFFER[483]	//( - , DU) Настроить энкодер ББ1
#define idA1MC01LC1	 213	//( - , DU) Настроить энкодер ББ1
#define A1MC01LC2	 BUFFER[485]	//( - , DU) Настроить энкодер ББ1
#define idA1MC01LC2	 214	//( - , DU) Настроить энкодер ББ1
#define B2MC01LC1	 BUFFER[487]	//( - , DU) Настроить энкодер РБ2
#define idB2MC01LC1	 215	//( - , DU) Настроить энкодер РБ2
#define B2MC01LC2	 BUFFER[489]	//( - , DU) Настроить энкодер РБ2
#define idB2MC01LC2	 216	//( - , DU) Настроить энкодер РБ2
#define A2MC01LC1	 BUFFER[491]	//( - , DU) Настроить энкодер РБ1
#define idA2MC01LC1	 217	//( - , DU) Настроить энкодер РБ1
#define A2MC01LC2	 BUFFER[493]	//( - , DU) Настроить энкодер РБ1
#define idA2MC01LC2	 218	//( - , DU) Настроить энкодер РБ1
#define B3MC01LC1	 BUFFER[495]	//( - , DU) Настроить энкодер ИС2
#define idB3MC01LC1	 219	//( - , DU) Настроить энкодер ИС2
#define B3MC01LC2	 BUFFER[497]	//( - , DU) Настроить энкодер ИС2
#define idB3MC01LC2	 220	//( - , DU) Настроить энкодер ИС2
#define A3MC01LC1	 BUFFER[499]	//( - , DU) Настроить энкодер ИС1
#define idA3MC01LC1	 221	//( - , DU) Настроить энкодер ИС1
#define A3MC01LC2	 BUFFER[501]	//( - , DU) Настроить энкодер ИС1
#define idA3MC01LC2	 222	//( - , DU) Настроить энкодер ИС1
#define B8MC01LC1	 BUFFER[503]	//( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC1	 223	//( - , DU) Настроить энкодер АЗ2
#define B8MC01LC2	 BUFFER[505]	//( - , DU) Настроить энкодер АЗ2
#define idB8MC01LC2	 224	//( - , DU) Настроить энкодер АЗ2
#define A8MC01LC1	 BUFFER[507]	//( - , DU) Настроить энкодер ДС2
#define idA8MC01LC1	 225	//( - , DU) Настроить энкодер ДС2
#define A8MC01LC2	 BUFFER[509]	//( - , DU) Настроить энкодер ДС2
#define idA8MC01LC2	 226	//( - , DU) Настроить энкодер ДС2
#define A3VP42LDU	 BUFFER[511]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define idA3VP42LDU	 227	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
#define A3CP02RDU	 BUFFER[513]	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define idA3CP02RDU	 228	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
#define A3VP52LDU	 BUFFER[518]	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define idA3VP52LDU	 229	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
#define B3VP42LDU	 BUFFER[520]	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define idB3VP42LDU	 230	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
#define B3CP02RDU	 BUFFER[522]	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define idB3CP02RDU	 231	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
#define R6IS61LDU	 BUFFER[527]	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define idR6IS61LDU	 232	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
#define R6IS66LZZ	 BUFFER[529]	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 233	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[531]	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 234	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[533]	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 235	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define A3VC01RDU	 BUFFER[535]	//( - , DU) Координата ИС1, мм
#define idA3VC01RDU	 236	//( - , DU) Координата ИС1, мм
#define A2VC01RDU	 BUFFER[540]	//( - , DU) Координата РБ1, мм
#define idA2VC01RDU	 237	//( - , DU) Координата РБ1, мм
#define B2VC01RDU	 BUFFER[545]	//( - , DU) Координата РБ2, мм
#define idB2VC01RDU	 238	//( - , DU) Координата РБ2, мм
#define B8VC01RDU	 BUFFER[550]	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
#define idB8VC01RDU	 239	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
#define A4VP82LDU	 BUFFER[555]	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 240	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define B4VP82LDU	 BUFFER[557]	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 241	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define A2VP82LDU	 BUFFER[559]	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 242	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define B2VP82LDU	 BUFFER[561]	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 243	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define A3VP81LDU	 BUFFER[563]	//( - , - ) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 244	//( - , - ) Давление СПУСК ИС1 в норме
#define B3VP81LDU	 BUFFER[565]	//( - , - ) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 245	//( - , - ) Давление СПУСК ИС2 в норме
#define R0EE02LDU	 BUFFER[567]	//( - , DU) Питание  АКНП  отключить
#define idR0EE02LDU	 246	//( - , DU) Питание  АКНП  отключить
#define psb1	 BUFFER[569]	//( - , DU) ру не готова
#define idpsb1	 247	//( - , DU) ру не готова
#define psb2	 BUFFER[571]	//( - , DU) движение бб
#define idpsb2	 248	//( - , DU) движение бб
#define psa1	 BUFFER[573]	//( - , DU) AZ1
#define idpsa1	 249	//( - , DU) AZ1
#define psa2	 BUFFER[575]	//( - , DU) AZ2
#define idpsa2	 250	//( - , DU) AZ2
#define psrb4	 BUFFER[577]	//( - , DU) кнопка сброс
#define idpsrb4	 251	//( - , DU) кнопка сброс
#define psrb1	 BUFFER[579]	//( - , DU) пневматика по мощности
#define idpsrb1	 252	//( - , DU) пневматика по мощности
#define psrb2	 BUFFER[581]	//( - , DU) пневматика по программам
#define idpsrb2	 253	//( - , DU) пневматика по программам
#define psrb	 BUFFER[583]	//( - , DU) ???
#define idpsrb	 254	//( - , DU) ???
#define A0VS11LDU	 BUFFER[585]	//( - , DU) АЗ1 готова к работе
#define idA0VS11LDU	 255	//( - , DU) АЗ1 готова к работе
#define B0VS11LDU	 BUFFER[587]	//( - , DU) АЗ2 готова к работе
#define idB0VS11LDU	 256	//( - , DU) АЗ2 готова к работе
#define A1IE01LDU	 BUFFER[589]	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define idA1IE01LDU	 257	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
#define A3IE01LDU	 BUFFER[591]	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define idA3IE01LDU	 258	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
#define A2IE01LDU	 BUFFER[593]	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define idA2IE01LDU	 259	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
#define A1IE02LDU	 BUFFER[595]	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define idA1IE02LDU	 260	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
#define A3IE02LDU	 BUFFER[597]	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define idA3IE02LDU	 261	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
#define A2IE02LDU	 BUFFER[599]	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define idA2IE02LDU	 262	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
#define B1IE01LDU	 BUFFER[601]	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define idB1IE01LDU	 263	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
#define B2IE01LDU	 BUFFER[603]	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define idB2IE01LDU	 264	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
#define B3IE01LDU	 BUFFER[605]	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define idB3IE01LDU	 265	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
#define B1IE02LDU	 BUFFER[607]	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define idB1IE02LDU	 266	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
#define B3IE02LDU	 BUFFER[609]	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define idB3IE02LDU	 267	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
#define B2IE02LDU	 BUFFER[611]	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define idB2IE02LDU	 268	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
#define R0IE02LDU	 BUFFER[613]	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define idR0IE02LDU	 269	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
#define R0IE01LDU	 BUFFER[615]	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define idR0IE01LDU	 270	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
#define A6IE01LDU	 BUFFER[617]	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define idA6IE01LDU	 271	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
#define B6IE01LDU	 BUFFER[619]	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define idB6IE01LDU	 272	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
#define A8IE01LDU	 BUFFER[621]	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define idA8IE01LDU	 273	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
#define B5IE01LDU	 BUFFER[623]	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define idB5IE01LDU	 274	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
#define A5IE02LDU	 BUFFER[625]	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define idA5IE02LDU	 275	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
#define R1IE01LDU	 BUFFER[627]	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define idR1IE01LDU	 276	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
#define R2IE01LDU	 BUFFER[629]	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define idR2IE01LDU	 277	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
#define A1VP41LZ2	 BUFFER[631]	//( - , MDuBz2) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ2	 278	//( - , MDuBz2) Давление СБРОС ББ1 ниже АС
#define R0VL22LDU	 BUFFER[633]	//( - , DU) Конец программы 200сек
#define idR0VL22LDU	 279	//( - , DU) Конец программы 200сек
#define R0VL23LDU	 BUFFER[635]	//( - , DU) Конец программы 20мин
#define idR0VL23LDU	 280	//( - , DU) Конец программы 20мин
#define B1VP41LZ1	 BUFFER[637]	//( - , MDuBz1) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ1	 281	//( - , MDuBz1) Давление СБРОС ББ2 ниже АС
#define B1VP41LZ2	 BUFFER[639]	//( - , MDuBz2) Давление СБРОС ББ2 ниже АС
#define idB1VP41LZ2	 282	//( - , MDuBz2) Давление СБРОС ББ2 ниже АС
#define A3AB19LDU	 BUFFER[641]	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define idA3AB19LDU	 283	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
#define B3AB19LDU	 BUFFER[643]	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define idB3AB19LDU	 284	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
#define A3EE03LDU	 BUFFER[645]	//( - , DU) ВПИС ИС1
#define idA3EE03LDU	 285	//( - , DU) ВПИС ИС1
#define B3EE03LDU	 BUFFER[647]	//( - , DU) ВПИС ИС2
#define idB3EE03LDU	 286	//( - , DU) ВПИС ИС2
#define B3AB15LDU	 BUFFER[649]	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define idB3AB15LDU	 287	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
#define R5IS21LDU	 BUFFER[651]	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 288	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
#define R5VS22LDU	 BUFFER[653]	//( - , DU) Движение ворот отстойной зоны к закрыты
#define idR5VS22LDU	 289	//( - , DU) Движение ворот отстойной зоны к закрыты
#define R5VS12LDU	 BUFFER[655]	//( - , DU) Движение ворот отстойной зоны к открыты
#define idR5VS12LDU	 290	//( - , DU) Движение ворот отстойной зоны к открыты
#define R5VS01IDU	 BUFFER[657]	//( - , DU) Готовность к управлению ворот отстойной зоны
#define idR5VS01IDU	 291	//( - , DU) Готовность к управлению ворот отстойной зоны
#define R3VS22LDU	 BUFFER[660]	//( - , DU) Движение гомогенных дверей к закрыты
#define idR3VS22LDU	 292	//( - , DU) Движение гомогенных дверей к закрыты
#define R3VS12LDU	 BUFFER[662]	//( - , DU) Движение гомогенных дверей к открыты
#define idR3VS12LDU	 293	//( - , DU) Движение гомогенных дверей к открыты
#define R3VS01IDU	 BUFFER[664]	//( - , DU) Готовность к управлению гомогенных дверей
#define idR3VS01IDU	 294	//( - , DU) Готовность к управлению гомогенных дверей
#define A3AB13LDU	 BUFFER[667]	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define idA3AB13LDU	 295	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
#define B3AB13LDU	 BUFFER[669]	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define idB3AB13LDU	 296	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
#define R0DE02LDU	 BUFFER[671]	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define idR0DE02LDU	 297	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
#define R0DE03LDU	 BUFFER[674]	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define idR0DE03LDU	 298	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
#define R0DE04LDU	 BUFFER[677]	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define idR0DE04LDU	 299	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
#define R0DE08LDU	 BUFFER[680]	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define idR0DE08LDU	 300	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
#define B0CT01IZ2	 BUFFER[683]	//( - , MDuBz2) Температура АЗ2-2
#define idB0CT01IZ2	 301	//( - , MDuBz2) Температура АЗ2-2
#define A3MC01RDU	 BUFFER[688]	//( - , DU) Заданная координата положения ИС от регулятора мм
#define idA3MC01RDU	 302	//( - , DU) Заданная координата положения ИС от регулятора мм
#define A3MC02RDU	 BUFFER[693]	//( - , DU) Температурная корректировка координаты ИМ
#define idA3MC02RDU	 303	//( - , DU) Температурная корректировка координаты ИМ
#define R0CN91LDU	 BUFFER[698]	//( - , DU) Рассчётная реактивность от регулятора
#define idR0CN91LDU	 304	//( - , DU) Рассчётная реактивность от регулятора
#define A3MC03RDU	 BUFFER[703]	//( - , DU) Координата положения ИМ 0-й реактивности
#define idA3MC03RDU	 305	//( - , DU) Координата положения ИМ 0-й реактивности
#define A3AB15LDU	 BUFFER[708]	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define idA3AB15LDU	 306	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
#define R0AB20LDU	 BUFFER[710]	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define idR0AB20LDU	 307	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
#define R0CN92LDU	 BUFFER[712]	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define idR0CN92LDU	 308	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
#define R0VN11RDU	 BUFFER[717]	//( - , DU) Текущая мощность РУ
#define idR0VN11RDU	 309	//( - , DU) Текущая мощность РУ
#define R0VN12RDU	 BUFFER[722]	//( - , DU) Заданная мощность РУ
#define idR0VN12RDU	 310	//( - , DU) Заданная мощность РУ
#define R0AB19LDU	 BUFFER[727]	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define idR0AB19LDU	 311	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
#define R0CN93LDU	 BUFFER[729]	//( - , DU) время работы на мощности более 100Вт, сек
#define idR0CN93LDU	 312	//( - , DU) время работы на мощности более 100Вт, сек
#define R0CN94LDU	 BUFFER[734]	//( - , DU) Скорость изменения мощности
#define idR0CN94LDU	 313	//( - , DU) Скорость изменения мощности
#define R0CN95LDU	 BUFFER[739]	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define idR0CN95LDU	 314	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
#define R0AD03LZ1	 BUFFER[742]	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define idR0AD03LZ1	 315	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
#define R0AD03LZ2	 BUFFER[744]	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define idR0AD03LZ2	 316	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
#define R0AD04LZ1	 BUFFER[746]	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define idR0AD04LZ1	 317	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
#define R0AD04LZ2	 BUFFER[748]	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define idR0AD04LZ2	 318	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
#define R0AD05LZ1	 BUFFER[750]	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define idR0AD05LZ1	 319	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
#define R0AD05LZ2	 BUFFER[752]	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define idR0AD05LZ2	 320	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
#define B8IS12LDU	 BUFFER[754]	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define idB8IS12LDU	 321	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
#define B8IS21LDU	 BUFFER[756]	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define idB8IS21LDU	 322	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
#define A1VP41LZ1	 BUFFER[758]	//( - , MDuBz1) Давление СБРОС ББ1 ниже АС
#define idA1VP41LZ1	 323	//( - , MDuBz1) Давление СБРОС ББ1 ниже АС
#define venc06	 BUFFER[760]	//(vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
#define idvenc06	 324	//(vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
#define venc07	 BUFFER[765]	//(vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
#define idvenc07	 325	//(vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
#define venc08	 BUFFER[770]	//(vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
#define idvenc08	 326	//(vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
#define R0VN15RDU	 BUFFER[775]	//( - , DU) Период разгона РУ
#define idR0VN15RDU	 327	//( - , DU) Период разгона РУ
#define R8AD21LDU	 BUFFER[780]	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define idR8AD21LDU	 328	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
#define R8AD22LDU	 BUFFER[782]	//(vds32:02 - K15VDSR, - ) Сигнал синхронизации с импульсом
#define idR8AD22LDU	 329	//(vds32:02 - K15VDSR, - ) Сигнал синхронизации с импульсом
#define R0S01LDU	 BUFFER[784]	//( - , - ) Отключение сетевых передач ДУ
#define idR0S01LDU	 330	//( - , - ) Отключение сетевых передач ДУ
#define R0S01LZ1	 BUFFER[786]	//(fds16:07 - K15FDSR, - ) Отключение сетевых передач в Баз1
#define idR0S01LZ1	 331	//(fds16:07 - K15FDSR, - ) Отключение сетевых передач в Баз1
#define R0S01LZ2	 BUFFER[788]	//(fds16:07 - K16FDSR, - ) Отключение сетевых передач в Баз2
#define idR0S01LZ2	 332	//(fds16:07 - K16FDSR, - ) Отключение сетевых передач в Баз2
#define R0AD16LDU	 BUFFER[790]	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define idR0AD16LDU	 333	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
#define R0S01LIM	 BUFFER[792]	//(fds16:08 - K15FDSR, - ) Отключение сетевых передач ПТИ
#define idR0S01LIM	 334	//(fds16:08 - K15FDSR, - ) Отключение сетевых передач ПТИ
#define B1IC01UDU	 BUFFER[794]	//( - , MDuS) Координата штока ББ2 (дел.энк)
#define idB1IC01UDU	 335	//( - , MDuS) Координата штока ББ2 (дел.энк)
#define B1VC01RDU	 BUFFER[799]	//( - , DU) Координата ББ2, мм
#define idB1VC01RDU	 336	//( - , DU) Координата ББ2, мм
#define B1IS11LDU	 BUFFER[804]	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define idB1IS11LDU	 337	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
#define A2IC01UDU	 BUFFER[806]	//( - , MDuS) Координата штока РБ1 (дел.энк)
#define idA2IC01UDU	 338	//( - , MDuS) Координата штока РБ1 (дел.энк)
#define B2IC01UDU	 BUFFER[811]	//( - , MDuS) Координата штока РБ2 (дел.энк)
#define idB2IC01UDU	 339	//( - , MDuS) Координата штока РБ2 (дел.энк)
#define A3IC01UDU	 BUFFER[816]	//( - , MDuS) Координата штока ИС1 (дел.энк)
#define idA3IC01UDU	 340	//( - , MDuS) Координата штока ИС1 (дел.энк)
#define B3IC01UDU	 BUFFER[821]	//( - , MDuS) Координата штока ИС2 (дел.энк)
#define idB3IC01UDU	 341	//( - , MDuS) Координата штока ИС2 (дел.энк)
#define B3VC01RDU	 BUFFER[826]	//( - , DU) Координата ИС2, мм
#define idB3VC01RDU	 342	//( - , DU) Координата ИС2, мм
#define A8IC01UDU	 BUFFER[831]	//( - , MDuS) Координата ДС2 (дел.энк)
#define idA8IC01UDU	 343	//( - , MDuS) Координата ДС2 (дел.энк)
#define A8VC01RDU	 BUFFER[836]	//( - , DU) Координата ДС2, мм
#define idA8VC01RDU	 344	//( - , DU) Координата ДС2, мм
#define B8IC01UDU	 BUFFER[841]	//( - , MDuS) Координата АЗ2 (дел.энк)
#define idB8IC01UDU	 345	//( - , MDuS) Координата АЗ2 (дел.энк)
#define A1IC01UDU	 BUFFER[846]	//( - , MDuS) Координата штока ББ1 (дел.энк)
#define idA1IC01UDU	 346	//( - , MDuS) Координата штока ББ1 (дел.энк)
#define R0DE05LDU	 BUFFER[851]	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define idR0DE05LDU	 347	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
#define R0DE09LDU	 BUFFER[854]	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define idR0DE09LDU	 348	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
#define R0DE0ALDU	 BUFFER[857]	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define idR0DE0ALDU	 349	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
#define R0DE07LDU	 BUFFER[860]	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define idR0DE07LDU	 350	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
#define R0DE0CLDU	 BUFFER[863]	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define idR0DE0CLDU	 351	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
#define R0DE0BLDU	 BUFFER[866]	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define idR0DE0BLDU	 352	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
#define R0DE0DLDU	 BUFFER[869]	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define idR0DE0DLDU	 353	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
#define R0DE0FLDU	 BUFFER[872]	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define idR0DE0FLDU	 354	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
#define TTLDU	 BUFFER[875]	//( - , DU) ttl
#define idTTLDU	 355	//( - , DU) ttl
#define R0DEB3LDU	 BUFFER[878]	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define idR0DEB3LDU	 356	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
#define R0DEB2LDU	 BUFFER[880]	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define idR0DEB2LDU	 357	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
#define R0DEB1LDU	 BUFFER[882]	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define idR0DEB1LDU	 358	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
#define R0DEB4LDU	 BUFFER[884]	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define idR0DEB4LDU	 359	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
#define R0DE3DLDU	 BUFFER[886]	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define idR0DE3DLDU	 360	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
#define R0DE3CLDU	 BUFFER[888]	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define idR0DE3CLDU	 361	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
#define TestDiagnDU	 BUFFER[890]	//( - , DU) Неисправность от
#define idTestDiagnDU	 362	//( - , DU) Неисправность от
#define B3CV01RDU	 BUFFER[892]	//( - , DU) Измеренная скорость перемещения ИС2
#define idB3CV01RDU	 363	//( - , DU) Измеренная скорость перемещения ИС2
#define R0DE01LDU	 BUFFER[897]	//(vencf8l:01 - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
#define idR0DE01LDU	 364	//(vencf8l:01 - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
#define R0DE06LDU	 BUFFER[900]	//(vencf8l:01 - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
#define idR0DE06LDU	 365	//(vencf8l:01 - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
#define venc01	 BUFFER[903]	//(vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
#define idvenc01	 366	//(vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
#define venc02	 BUFFER[908]	//(vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
#define idvenc02	 367	//(vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
#define venc03	 BUFFER[913]	//(vencf8l:01 - venc03, - ) заначение реального энкодера Ис1
#define idvenc03	 368	//(vencf8l:01 - venc03, - ) заначение реального энкодера Ис1
#define venc04	 BUFFER[918]	//(vencf8l:01 - venc04, - ) заначение реального энкодера ДС1
#define idvenc04	 369	//(vencf8l:01 - venc04, - ) заначение реального энкодера ДС1
#define venc05	 BUFFER[923]	//(vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
#define idvenc05	 370	//(vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
#define A6AB07LDU	 BUFFER[928]	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define idA6AB07LDU	 371	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
#define A6AB08LDU	 BUFFER[930]	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define idA6AB08LDU	 372	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
#define A6AB09LDU	 BUFFER[932]	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define idA6AB09LDU	 373	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
#define B6AB06LDU	 BUFFER[934]	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define idB6AB06LDU	 374	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
#define B6AB07LDU	 BUFFER[936]	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define idB6AB07LDU	 375	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
#define B6AB08LDU	 BUFFER[938]	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define idB6AB08LDU	 376	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
#define B6AB09LDU	 BUFFER[940]	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define idB6AB09LDU	 377	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
#define A6AB05LDU	 BUFFER[942]	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define idA6AB05LDU	 378	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
#define B8VS12LDU	 BUFFER[944]	//( - , DU) Движение АЗ2 в сторону ВУ
#define idB8VS12LDU	 379	//( - , DU) Движение АЗ2 в сторону ВУ
#define B8CV01RDU	 BUFFER[946]	//( - , DU) Измеренная скорость перемещения АЗ2
#define idB8CV01RDU	 380	//( - , DU) Измеренная скорость перемещения АЗ2
#define B8AB06LDU	 BUFFER[951]	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define idB8AB06LDU	 381	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
#define B8AB07LDU	 BUFFER[953]	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define idB8AB07LDU	 382	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
#define B8AB05LDU	 BUFFER[955]	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define idB8AB05LDU	 383	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
#define B8VS22LDU	 BUFFER[957]	//( - , DU) Движение АЗ2 в сторону НУ
#define idB8VS22LDU	 384	//( - , DU) Движение АЗ2 в сторону НУ
#define B8AZ03LDU	 BUFFER[959]	//( - , DU) Несанкционированное перемещение АЗ2
#define idB8AZ03LDU	 385	//( - , DU) Несанкционированное перемещение АЗ2
#define R0MD11LP1	 BUFFER[961]	//( - , DU) Кнопка ПУСК
#define idR0MD11LP1	 386	//( - , DU) Кнопка ПУСК
#define B8AD10LDU	 BUFFER[963]	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define idB8AD10LDU	 387	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
#define B8AD20LDU	 BUFFER[965]	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define idB8AD20LDU	 388	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
#define B8IS11LDU	 BUFFER[967]	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define idB8IS11LDU	 389	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
#define B8AB01LDU	 BUFFER[969]	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define idB8AB01LDU	 390	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
#define B8AB04LDU	 BUFFER[971]	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define idB8AB04LDU	 391	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
#define B8AB08LDU	 BUFFER[973]	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define idB8AB08LDU	 392	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
#define B8AB09LDU	 BUFFER[975]	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define idB8AB09LDU	 393	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
#define A5AB01LDU	 BUFFER[977]	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define idA5AB01LDU	 394	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
#define A5AB02LDU	 BUFFER[979]	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define idA5AB02LDU	 395	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
#define B5AZ03LDU	 BUFFER[981]	//( - , DU) Несанкционированное перемещение НЛ2
#define idB5AZ03LDU	 396	//( - , DU) Несанкционированное перемещение НЛ2
#define B5AB01LDU	 BUFFER[983]	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define idB5AB01LDU	 397	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
#define B5AB02LDU	 BUFFER[985]	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define idB5AB02LDU	 398	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
#define A4IS21LDU	 BUFFER[987]	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define idA4IS21LDU	 399	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
#define B4IS21LDU	 BUFFER[989]	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define idB4IS21LDU	 400	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
#define B4AD10LDU	 BUFFER[991]	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define idB4AD10LDU	 401	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
#define A4AD10LDU	 BUFFER[993]	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define idA4AD10LDU	 402	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
#define A4AZ03LDU	 BUFFER[995]	//( - , DU) Несанкционированное перемещение НИ1
#define idA4AZ03LDU	 403	//( - , DU) Несанкционированное перемещение НИ1
#define A4AB01LDU	 BUFFER[997]	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define idA4AB01LDU	 404	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
#define A4AB02LDU	 BUFFER[999]	//( - , DU) Блокировка движения НИ1 - Нет перемещения
#define idA4AB02LDU	 405	//( - , DU) Блокировка движения НИ1 - Нет перемещения
#define B4AZ03LDU	 BUFFER[1001]	//( - , DU) Несанкционированное перемещение НИ2
#define idB4AZ03LDU	 406	//( - , DU) Несанкционированное перемещение НИ2
#define B4AB01LDU	 BUFFER[1003]	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define idB4AB01LDU	 407	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
#define B4AB02LDU	 BUFFER[1005]	//( - , DU) Блокировка движения НИ2 - Нет перемещения
#define idB4AB02LDU	 408	//( - , DU) Блокировка движения НИ2 - Нет перемещения
#define A5AB04LDU	 BUFFER[1007]	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define idA5AB04LDU	 409	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
#define B5AB04LDU	 BUFFER[1009]	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define idB5AB04LDU	 410	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
#define A1IS12LDU	 BUFFER[1011]	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define idA1IS12LDU	 411	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
#define A2IS12LDU	 BUFFER[1013]	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define idA2IS12LDU	 412	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
#define B1IS12LDU	 BUFFER[1015]	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define idB1IS12LDU	 413	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
#define B2IS12LDU	 BUFFER[1017]	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define idB2IS12LDU	 414	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
#define R4IS11LDU	 BUFFER[1019]	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define idR4IS11LDU	 415	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
#define A6AB06LDU	 BUFFER[1021]	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define idA6AB06LDU	 416	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
#define A8AB12LDU	 BUFFER[1023]	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define idA8AB12LDU	 417	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
#define A8AB13LDU	 BUFFER[1025]	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define idA8AB13LDU	 418	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
#define A8AB14LDU	 BUFFER[1027]	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define idA8AB14LDU	 419	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
#define A8AB02LDU	 BUFFER[1029]	//( - , DU) Блокировка движения ДС2- АНИ не установлен
#define idA8AB02LDU	 420	//( - , DU) Блокировка движения ДС2- АНИ не установлен
#define A8AB01LDU	 BUFFER[1031]	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define idA8AB01LDU	 421	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
#define A2VS11LDU	 BUFFER[1033]	//( - , DU) Движение РБ1 в сторону ВУ
#define idA2VS11LDU	 422	//( - , DU) Движение РБ1 в сторону ВУ
#define A2CV01RDU	 BUFFER[1035]	//( - , DU) Измеренная скорость перемещения РБ1
#define idA2CV01RDU	 423	//( - , DU) Измеренная скорость перемещения РБ1
#define A2AB04LDU	 BUFFER[1040]	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define idA2AB04LDU	 424	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
#define A2AB02LDU	 BUFFER[1042]	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define idA2AB02LDU	 425	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
#define A2AB01LDU	 BUFFER[1044]	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define idA2AB01LDU	 426	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
#define A2VS21LDU	 BUFFER[1046]	//( - , DU) Движение РБ1 в сторону НУ
#define idA2VS21LDU	 427	//( - , DU) Движение РБ1 в сторону НУ
#define A2AZ03LDU	 BUFFER[1048]	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define idA2AZ03LDU	 428	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
#define A2AD11LDU	 BUFFER[1050]	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 429	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
#define A2AD21LDU	 BUFFER[1052]	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 430	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
#define A2AD02LDU	 BUFFER[1054]	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define idA2AD02LDU	 431	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[1056]	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define idA2AD03LDU	 432	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
#define A2AD04LDU	 BUFFER[1058]	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define idA2AD04LDU	 433	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
#define A2AD05LDU	 BUFFER[1060]	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define idA2AD05LDU	 434	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
#define A2AB07LDU	 BUFFER[1062]	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define idA2AB07LDU	 435	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
#define A2AB08LDU	 BUFFER[1064]	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define idA2AB08LDU	 436	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
#define A2AB05LDU	 BUFFER[1066]	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define idA2AB05LDU	 437	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
#define A2AB06LDU	 BUFFER[1068]	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA2AB06LDU	 438	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
#define A2AB09LDU	 BUFFER[1070]	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define idA2AB09LDU	 439	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
#define B8AB10LDU	 BUFFER[1072]	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define idB8AB10LDU	 440	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
#define B8AB11LDU	 BUFFER[1074]	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define idB8AB11LDU	 441	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
#define B8AB12LDU	 BUFFER[1076]	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define idB8AB12LDU	 442	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
#define B8AB13LDU	 BUFFER[1078]	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define idB8AB13LDU	 443	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
#define B8AB14LDU	 BUFFER[1080]	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define idB8AB14LDU	 444	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
#define B8AB02LDU	 BUFFER[1082]	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define idB8AB02LDU	 445	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
#define A8VS12LDU	 BUFFER[1084]	//( - , DU) Движение ДС2 в сторону ВУ
#define idA8VS12LDU	 446	//( - , DU) Движение ДС2 в сторону ВУ
#define A8CV01RDU	 BUFFER[1086]	//( - , DU) Измеренная скорость перемещения ДС2
#define idA8CV01RDU	 447	//( - , DU) Измеренная скорость перемещения ДС2
#define A8AB06LDU	 BUFFER[1091]	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define idA8AB06LDU	 448	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
#define A8AB07LDU	 BUFFER[1093]	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define idA8AB07LDU	 449	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
#define A8AB05LDU	 BUFFER[1095]	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define idA8AB05LDU	 450	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
#define A8VS22LDU	 BUFFER[1097]	//( - , DU) Движение ДС2 в сторону НУ
#define idA8VS22LDU	 451	//( - , DU) Движение ДС2 в сторону НУ
#define A8AZ03LDU	 BUFFER[1099]	//( - , DU) Несанкционированное перемещение ДС2
#define idA8AZ03LDU	 452	//( - , DU) Несанкционированное перемещение ДС2
#define A8AD10LDU	 BUFFER[1101]	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define idA8AD10LDU	 453	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
#define A8AD20LDU	 BUFFER[1103]	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define idA8AD20LDU	 454	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
#define B8IS22LDU	 BUFFER[1105]	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define idB8IS22LDU	 455	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
#define A8IS12LDU	 BUFFER[1107]	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define idA8IS12LDU	 456	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
#define A8AB04LDU	 BUFFER[1109]	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define idA8AB04LDU	 457	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
#define A8IS22LDU	 BUFFER[1111]	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define idA8IS22LDU	 458	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
#define A8AB08LDU	 BUFFER[1113]	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define idA8AB08LDU	 459	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
#define A8AB09LDU	 BUFFER[1115]	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define idA8AB09LDU	 460	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
#define A8AB10LDU	 BUFFER[1117]	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define idA8AB10LDU	 461	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
#define A8AB11LDU	 BUFFER[1119]	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define idA8AB11LDU	 462	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
#define B6IS21LDU	 BUFFER[1121]	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define idB6IS21LDU	 463	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
#define A6VS22LDU	 BUFFER[1123]	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	 464	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
#define A6VS12LDU	 BUFFER[1125]	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	 465	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
#define B6VS22LDU	 BUFFER[1127]	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define idB6VS22LDU	 466	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
#define B6VS12LDU	 BUFFER[1129]	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define idB6VS12LDU	 467	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
#define A6AD10LDU	 BUFFER[1131]	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
#define idA6AD10LDU	 468	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
#define A6AD20LDU	 BUFFER[1133]	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define idA6AD20LDU	 469	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
#define B6AD10LDU	 BUFFER[1135]	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
#define idB6AD10LDU	 470	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
#define B6AD20LDU	 BUFFER[1137]	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define idB6AD20LDU	 471	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
#define A6AZ03LDU	 BUFFER[1139]	//( - , DU) Несанкционированное перемещение БЗ1
#define idA6AZ03LDU	 472	//( - , DU) Несанкционированное перемещение БЗ1
#define A6AB01LDU	 BUFFER[1141]	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define idA6AB01LDU	 473	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
#define A6AB02LDU	 BUFFER[1143]	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define idA6AB02LDU	 474	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
#define B6AZ03LDU	 BUFFER[1145]	//( - , DU) Несанкционированное перемещение БЗ2
#define idB6AZ03LDU	 475	//( - , DU) Несанкционированное перемещение БЗ2
#define B6AB01LDU	 BUFFER[1147]	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define idB6AB01LDU	 476	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
#define B6AB02LDU	 BUFFER[1149]	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define idB6AB02LDU	 477	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
#define A6AB04LDU	 BUFFER[1151]	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define idA6AB04LDU	 478	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
#define B6AB04LDU	 BUFFER[1153]	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define idB6AB04LDU	 479	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
#define R4AB01LDU	 BUFFER[1155]	//( - , DU) Блокировка движения тележки - АНИ не установлен
#define idR4AB01LDU	 480	//( - , DU) Блокировка движения тележки - АНИ не установлен
#define R8IS11LDU	 BUFFER[1157]	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define idR8IS11LDU	 481	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
#define R6IS21LDU	 BUFFER[1159]	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	 482	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
#define A0VN71LZ2	 BUFFER[1161]	//( - , MDuBz2) АЗ по АС мощности для АЗ1
#define idA0VN71LZ2	 483	//( - , MDuBz2) АЗ по АС мощности для АЗ1
#define A0VN71LZ1	 BUFFER[1163]	//( - , MDuBz1) АЗ по АС мощности для АЗ1
#define idA0VN71LZ1	 484	//( - , MDuBz1) АЗ по АС мощности для АЗ1
#define R0NE01LDU	 BUFFER[1165]	//( - , DU) Потеря связи с БАЗ1
#define idR0NE01LDU	 485	//( - , DU) Потеря связи с БАЗ1
#define R0MW15IP1	 BUFFER[1167]	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define idR0MW15IP1	 486	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
#define R0MW14IP1	 BUFFER[1170]	//( - , DU) Переключатель ПРОГРАММЫ
#define idR0MW14IP1	 487	//( - , DU) Переключатель ПРОГРАММЫ
#define R0MW12IP1	 BUFFER[1173]	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define idR0MW12IP1	 488	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
#define R0MW13IP1	 BUFFER[1176]	//( - , DU) Переключатель ВЫБОР ЗОН
#define idR0MW13IP1	 489	//( - , DU) Переключатель ВЫБОР ЗОН
#define R0MW16IP1	 BUFFER[1179]	//( - , DU) Переключатель ВИД ПРОВЕРКИ
#define idR0MW16IP1	 490	//( - , DU) Переключатель ВИД ПРОВЕРКИ
#define R0MW11IP1	 BUFFER[1182]	//( - , DU) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 491	//( - , DU) Переключатель ВЫСТРЕЛ
#define R0MW11IP2	 BUFFER[1185]	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define idR0MW11IP2	 492	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
#define R0MW13LP2	 BUFFER[1188]	//( - , DU) Переключатель СЕТЬ
#define idR0MW13LP2	 493	//( - , DU) Переключатель СЕТЬ
#define R0MD32LP1	 BUFFER[1190]	//( - , DU) Кнопка СПУСК
#define idR0MD32LP1	 494	//( - , DU) Кнопка СПУСК
#define R0MD31LP1	 BUFFER[1192]	//( - , DU) Кнопка СТОП
#define idR0MD31LP1	 495	//( - , DU) Кнопка СТОП
#define A1IS21LDU	 BUFFER[1194]	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define idA1IS21LDU	 496	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
#define A2IS21LDU	 BUFFER[1196]	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define idA2IS21LDU	 497	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
#define A3IS21LDU	 BUFFER[1198]	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define idA3IS21LDU	 498	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
#define B1IS21LDU	 BUFFER[1200]	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define idB1IS21LDU	 499	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
#define B2IS21LDU	 BUFFER[1202]	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define idB2IS21LDU	 500	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
#define B3IS21LDU	 BUFFER[1204]	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define idB3IS21LDU	 501	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
#define R0ES01LDU	 BUFFER[1206]	//( - , DU) ОРР не в исходном состоянии
#define idR0ES01LDU	 502	//( - , DU) ОРР не в исходном состоянии
#define R4MD11LP2	 BUFFER[1208]	//( - , DU) Кнопка ВПЕРЁД  (тележки)
#define idR4MD11LP2	 503	//( - , DU) Кнопка ВПЕРЁД  (тележки)
#define R4MD31LP2	 BUFFER[1210]	//( - , DU) Кнопка СТОП  (тележки)
#define idR4MD31LP2	 504	//( - , DU) Кнопка СТОП  (тележки)
#define R4MD21LP2	 BUFFER[1212]	//( - , DU) Кнопка НАЗАД  (тележки)
#define idR4MD21LP2	 505	//( - , DU) Кнопка НАЗАД  (тележки)
#define A6IS11LDU	 BUFFER[1214]	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define idA6IS11LDU	 506	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
#define A6IS21LDU	 BUFFER[1216]	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define idA6IS21LDU	 507	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
#define B6IS11LDU	 BUFFER[1218]	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define idB6IS11LDU	 508	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
#define B4IS11LDU	 BUFFER[1220]	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define idB4IS11LDU	 509	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
#define R4AB13LDU	 BUFFER[1222]	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define idR4AB13LDU	 510	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
#define R4AB14LDU	 BUFFER[1224]	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define idR4AB14LDU	 511	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
#define R4AB15LDU	 BUFFER[1226]	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define idR4AB15LDU	 512	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
#define R5IS11LDU	 BUFFER[1228]	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 513	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
#define R4AB16LDU	 BUFFER[1230]	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define idR4AB16LDU	 514	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
#define R4AB17LDU	 BUFFER[1232]	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define idR4AB17LDU	 515	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
#define R4AB18LDU	 BUFFER[1234]	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define idR4AB18LDU	 516	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
#define R4AD10LDU	 BUFFER[1236]	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	 517	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
#define R4AD20LDU	 BUFFER[1238]	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define idR4AD20LDU	 518	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
#define A5VS22LDU	 BUFFER[1240]	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 519	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
#define A5VS12LDU	 BUFFER[1242]	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 520	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
#define B5VS22LDU	 BUFFER[1244]	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 521	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
#define B5VS12LDU	 BUFFER[1246]	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 522	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
#define B5AD10LDU	 BUFFER[1248]	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
#define idB5AD10LDU	 523	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
#define B5AD20LDU	 BUFFER[1250]	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
#define idB5AD20LDU	 524	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
#define A5AD10LDU	 BUFFER[1252]	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
#define idA5AD10LDU	 525	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
#define A5AD20LDU	 BUFFER[1254]	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
#define idA5AD20LDU	 526	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
#define A5IS11LDU	 BUFFER[1256]	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define idA5IS11LDU	 527	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
#define A5IS21LDU	 BUFFER[1258]	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define idA5IS21LDU	 528	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
#define B5IS11LDU	 BUFFER[1260]	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define idB5IS11LDU	 529	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
#define B5IS21LDU	 BUFFER[1262]	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define idB5IS21LDU	 530	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
#define A5AZ03LDU	 BUFFER[1264]	//( - , DU) Несанкционированное перемещение НЛ1
#define idA5AZ03LDU	 531	//( - , DU) Несанкционированное перемещение НЛ1
#define R0NE02LDU	 BUFFER[1266]	//( - , DU) Потеря связи с БАЗ2
#define idR0NE02LDU	 532	//( - , DU) Потеря связи с БАЗ2
#define R4AB02LDU	 BUFFER[1268]	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define idR4AB02LDU	 533	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
#define R0NE08LDU	 BUFFER[1270]	//( - , DU) Потеря связи с ОПУ
#define idR0NE08LDU	 534	//( - , DU) Потеря связи с ОПУ
#define R4IS21LDU	 BUFFER[1272]	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define idR4IS21LDU	 535	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
#define R4IS22LDU	 BUFFER[1274]	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define idR4IS22LDU	 536	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
#define R4IS12LDU	 BUFFER[1276]	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define idR4IS12LDU	 537	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
#define R4VS22LDU	 BUFFER[1278]	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define idR4VS22LDU	 538	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
#define R4VS12LDU	 BUFFER[1280]	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define idR4VS12LDU	 539	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
#define R4AZ03LDU	 BUFFER[1282]	//( - , DU) Несанкционированное перемещение тележки
#define idR4AZ03LDU	 540	//( - , DU) Несанкционированное перемещение тележки
#define R4AB03LDU	 BUFFER[1284]	//( - , DU) Блокировка движения тележки - Самоход любого механизма
#define idR4AB03LDU	 541	//( - , DU) Блокировка движения тележки - Самоход любого механизма
#define R1IS21LDU	 BUFFER[1286]	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define idR1IS21LDU	 542	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
#define R2IS21LDU	 BUFFER[1288]	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define idR2IS21LDU	 543	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
#define R4AB04LDU	 BUFFER[1290]	//( - , DU) Блокировка движения тележки - Превышение времени движения
#define idR4AB04LDU	 544	//( - , DU) Блокировка движения тележки - Превышение времени движения
#define R4AB05LDU	 BUFFER[1292]	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define idR4AB05LDU	 545	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
#define R4AB06LDU	 BUFFER[1294]	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define idR4AB06LDU	 546	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
#define R4AB07LDU	 BUFFER[1296]	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define idR4AB07LDU	 547	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
#define R4AB08LDU	 BUFFER[1298]	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define idR4AB08LDU	 548	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
#define R4AB09LDU	 BUFFER[1300]	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define idR4AB09LDU	 549	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
#define B0VN71LZ1	 BUFFER[1302]	//( - , MDuBz1) АЗ по АС мощности для АЗ2
#define idB0VN71LZ1	 550	//( - , MDuBz1) АЗ по АС мощности для АЗ2
#define B0VN71LZ2	 BUFFER[1304]	//( - , MDuBz2) АЗ по АС мощности для АЗ2
#define idB0VN71LZ2	 551	//( - , MDuBz2) АЗ по АС мощности для АЗ2
#define R4AB10LDU	 BUFFER[1306]	//( - , DU) Блокировка тележки - не открыта биологическая защита
#define idR4AB10LDU	 552	//( - , DU) Блокировка тележки - не открыта биологическая защита
#define R4AB11LDU	 BUFFER[1308]	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define idR4AB11LDU	 553	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
#define R4AB12LDU	 BUFFER[1310]	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define idR4AB12LDU	 554	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
#define A4IS11LDU	 BUFFER[1312]	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define idA4IS11LDU	 555	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
#define A3AD03LDU	 BUFFER[1314]	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define idA3AD03LDU	 556	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
#define A3AD04LDU	 BUFFER[1316]	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define idA3AD04LDU	 557	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
#define A3AD05LDU	 BUFFER[1318]	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define idA3AD05LDU	 558	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
#define A3AD01LDU	 BUFFER[1320]	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define idA3AD01LDU	 559	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
#define A3CV02RDU	 BUFFER[1322]	//( - , DU) Заданная скорость перемещения ИС1
#define idA3CV02RDU	 560	//( - , DU) Заданная скорость перемещения ИС1
#define A3AB07LDU	 BUFFER[1327]	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define idA3AB07LDU	 561	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
#define A3AB08LDU	 BUFFER[1329]	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define idA3AB08LDU	 562	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
#define A3AB05LDU	 BUFFER[1331]	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define idA3AB05LDU	 563	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
#define A3AB06LDU	 BUFFER[1333]	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define idA3AB06LDU	 564	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
#define A3AB09LDU	 BUFFER[1335]	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define idA3AB09LDU	 565	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
#define A3AB10LDU	 BUFFER[1337]	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define idA3AB10LDU	 566	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
#define A3AB11LDU	 BUFFER[1339]	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define idA3AB11LDU	 567	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
#define A3AB12LDU	 BUFFER[1341]	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA3AB12LDU	 568	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A3AB14LDU	 BUFFER[1343]	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define idA3AB14LDU	 569	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
#define A3AB16LDU	 BUFFER[1345]	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define idA3AB16LDU	 570	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
#define A3AB17LDU	 BUFFER[1347]	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define idA3AB17LDU	 571	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
#define A3AB18LDU	 BUFFER[1349]	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define idA3AB18LDU	 572	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
#define A3AB20LDU	 BUFFER[1351]	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define idA3AB20LDU	 573	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
#define B3VS12LDU	 BUFFER[1353]	//( - , DU) Движение ИС2 в сторону ВУ
#define idB3VS12LDU	 574	//( - , DU) Движение ИС2 в сторону ВУ
#define B3AB04LDU	 BUFFER[1355]	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define idB3AB04LDU	 575	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
#define B3AB02LDU	 BUFFER[1357]	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define idB3AB02LDU	 576	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
#define B3AB01LDU	 BUFFER[1359]	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define idB3AB01LDU	 577	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
#define B3VS22LDU	 BUFFER[1361]	//( - , DU) Движение ИС2 в сторону НУ
#define idB3VS22LDU	 578	//( - , DU) Движение ИС2 в сторону НУ
#define B1AB07LDU	 BUFFER[1363]	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define idB1AB07LDU	 579	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
#define B1AB08LDU	 BUFFER[1365]	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define idB1AB08LDU	 580	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
#define B1AB05LDU	 BUFFER[1367]	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define idB1AB05LDU	 581	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
#define B1AB06LDU	 BUFFER[1369]	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB1AB06LDU	 582	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
#define B1AB09LDU	 BUFFER[1371]	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define idB1AB09LDU	 583	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
#define B1AB10LDU	 BUFFER[1373]	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define idB1AB10LDU	 584	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
#define B1AB11LDU	 BUFFER[1375]	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define idB1AB11LDU	 585	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
#define B1AB12LDU	 BUFFER[1377]	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idB1AB12LDU	 586	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define B1AB13LDU	 BUFFER[1379]	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define idB1AB13LDU	 587	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
#define B1AB14LDU	 BUFFER[1381]	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define idB1AB14LDU	 588	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
#define B1AB16LDU	 BUFFER[1383]	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define idB1AB16LDU	 589	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
#define B1AB17LDU	 BUFFER[1385]	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define idB1AB17LDU	 590	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
#define B1AB18LDU	 BUFFER[1387]	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define idB1AB18LDU	 591	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
#define A3VS12LDU	 BUFFER[1389]	//( - , DU) Движение ИС1 в сторону ВУ
#define idA3VS12LDU	 592	//( - , DU) Движение ИС1 в сторону ВУ
#define A3CV01RDU	 BUFFER[1391]	//( - , DU) Измеренная скорость перемещения ИС1
#define idA3CV01RDU	 593	//( - , DU) Измеренная скорость перемещения ИС1
#define A3AB04LDU	 BUFFER[1396]	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define idA3AB04LDU	 594	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
#define A3AB02LDU	 BUFFER[1398]	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define idA3AB02LDU	 595	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
#define A3AB01LDU	 BUFFER[1400]	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define idA3AB01LDU	 596	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
#define A3VS22LDU	 BUFFER[1402]	//( - , DU) Движение ИС1 в сторону НУ
#define idA3VS22LDU	 597	//( - , DU) Движение ИС1 в сторону НУ
#define A3AZ03LDU	 BUFFER[1404]	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define idA3AZ03LDU	 598	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
#define A3AD11LDU	 BUFFER[1406]	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 599	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
#define A3AD21LDU	 BUFFER[1408]	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 600	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
#define A3AD02LDU	 BUFFER[1410]	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define idA3AD02LDU	 601	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
#define A2AD31LDU	 BUFFER[1412]	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define idA2AD31LDU	 602	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
#define B2AD31LDU	 BUFFER[1414]	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define idB2AD31LDU	 603	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
#define A1AD31LDU	 BUFFER[1416]	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define idA1AD31LDU	 604	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
#define B1AD31LDU	 BUFFER[1418]	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define idB1AD31LDU	 605	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
#define A2AD32LDU	 BUFFER[1420]	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define idA2AD32LDU	 606	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
#define B2AD32LDU	 BUFFER[1422]	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define idB2AD32LDU	 607	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
#define A1AD32LDU	 BUFFER[1424]	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define idA1AD32LDU	 608	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
#define B1AD32LDU	 BUFFER[1426]	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define idB1AD32LDU	 609	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
#define R0MD11LP2	 BUFFER[1428]	//( - , DU) Кнопка Пуск проверки схем сброса
#define idR0MD11LP2	 610	//( - , DU) Кнопка Пуск проверки схем сброса
#define R0VX01LDU	 BUFFER[1430]	//( - , DU) ДО ИМПУЛЬСА
#define idR0VX01LDU	 611	//( - , DU) ДО ИМПУЛЬСА
#define R0VL01IDU	 BUFFER[1432]	//( - , DU) До импульса минут
#define idR0VL01IDU	 612	//( - , DU) До импульса минут
#define R0VL11IDU	 BUFFER[1435]	//( - , DU) До импульса секунд
#define idR0VL11IDU	 613	//( - , DU) До импульса секунд
#define R0VL06RDU	 BUFFER[1438]	//( - , DU) Индикация (Время задержки от ВУ РБ)
#define idR0VL06RDU	 614	//( - , DU) Индикация (Время задержки от ВУ РБ)
#define B3AD33LDU	 BUFFER[1443]	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define idB3AD33LDU	 615	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define R0VL02RDU	 BUFFER[1445]	//( - , DU) Индикация (Время задержки ИНИ)
#define idR0VL02RDU	 616	//( - , DU) Индикация (Время задержки ИНИ)
#define R0VL04RDU	 BUFFER[1450]	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define idR0VL04RDU	 617	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
#define R0AB04LDU	 BUFFER[1455]	//( - , DU) Нарушение времени срабатывания верхней АС II УР
#define idR0AB04LDU	 618	//( - , DU) Нарушение времени срабатывания верхней АС II УР
#define R0AB06LDU	 BUFFER[1457]	//( - , DU) Нарушение времени задержки от ВУ РБ
#define idR0AB06LDU	 619	//( - , DU) Нарушение времени задержки от ВУ РБ
#define R0AB02LDU	 BUFFER[1459]	//( - , DU) Нарушение времени задержки ИНИ
#define idR0AB02LDU	 620	//( - , DU) Нарушение времени задержки ИНИ
#define R0VL03RDU	 BUFFER[1461]	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define idR0VL03RDU	 621	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
#define R0VL05RDU	 BUFFER[1466]	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define idR0VL05RDU	 622	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
#define R0VL21IDU	 BUFFER[1471]	//( - , DU) Декатрон
#define idR0VL21IDU	 623	//( - , DU) Декатрон
#define R0VX03LDU	 BUFFER[1474]	//( - , DU) Готовность 2 мин
#define idR0VX03LDU	 624	//( - , DU) Готовность 2 мин
#define B3AZ03LDU	 BUFFER[1476]	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define idB3AZ03LDU	 625	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
#define B3AD11LDU	 BUFFER[1478]	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 626	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
#define B3AD21LDU	 BUFFER[1480]	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 627	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
#define B3AD02LDU	 BUFFER[1482]	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define idB3AD02LDU	 628	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[1484]	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define idB3AD03LDU	 629	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
#define B3AD04LDU	 BUFFER[1486]	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define idB3AD04LDU	 630	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
#define B3AD05LDU	 BUFFER[1488]	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define idB3AD05LDU	 631	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
#define B3AD01LDU	 BUFFER[1490]	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define idB3AD01LDU	 632	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
#define B3CV02RDU	 BUFFER[1492]	//( - , DU) Заданная скорость перемещения ИС2
#define idB3CV02RDU	 633	//( - , DU) Заданная скорость перемещения ИС2
#define B3AB07LDU	 BUFFER[1497]	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define idB3AB07LDU	 634	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
#define B3AB08LDU	 BUFFER[1499]	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define idB3AB08LDU	 635	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
#define B3AB05LDU	 BUFFER[1501]	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define idB3AB05LDU	 636	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
#define B3AB06LDU	 BUFFER[1503]	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define idB3AB06LDU	 637	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
#define B3AB09LDU	 BUFFER[1505]	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define idB3AB09LDU	 638	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
#define B3AB10LDU	 BUFFER[1507]	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define idB3AB10LDU	 639	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
#define B3AB11LDU	 BUFFER[1509]	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define idB3AB11LDU	 640	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
#define B3AB12LDU	 BUFFER[1511]	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB3AB12LDU	 641	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B3AB14LDU	 BUFFER[1513]	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define idB3AB14LDU	 642	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
#define B3AB16LDU	 BUFFER[1515]	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define idB3AB16LDU	 643	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
#define B3AB17LDU	 BUFFER[1517]	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define idB3AB17LDU	 644	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
#define B3AB18LDU	 BUFFER[1519]	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define idB3AB18LDU	 645	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
#define B3AB20LDU	 BUFFER[1521]	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define idB3AB20LDU	 646	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
#define C1MD31LP1	 BUFFER[1523]	//( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP1	 647	//( - , DU) Кнопка СБРОС ББ
#define C1MD31LP2	 BUFFER[1525]	//( - , DU) Кнопка СБРОС ББ
#define idC1MD31LP2	 648	//( - , DU) Кнопка СБРОС ББ
#define B2AB08LDU	 BUFFER[1527]	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define idB2AB08LDU	 649	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
#define B2AB05LDU	 BUFFER[1529]	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define idB2AB05LDU	 650	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
#define B2AB06LDU	 BUFFER[1531]	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define idB2AB06LDU	 651	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
#define B2AB09LDU	 BUFFER[1533]	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define idB2AB09LDU	 652	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
#define B2AB10LDU	 BUFFER[1535]	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define idB2AB10LDU	 653	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
#define B2AB11LDU	 BUFFER[1537]	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define idB2AB11LDU	 654	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
#define B2AB12LDU	 BUFFER[1539]	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define idB2AB12LDU	 655	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
#define B2AB13LDU	 BUFFER[1541]	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define idB2AB13LDU	 656	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
#define B2AB14LDU	 BUFFER[1543]	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define idB2AB14LDU	 657	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
#define B2AB16LDU	 BUFFER[1545]	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define idB2AB16LDU	 658	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
#define B2AB17LDU	 BUFFER[1547]	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define idB2AB17LDU	 659	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
#define R1AZ03LDU	 BUFFER[1549]	//( - , DU) Несанкционированное перемещение МДЗ1
#define idR1AZ03LDU	 660	//( - , DU) Несанкционированное перемещение МДЗ1
#define R1AB01LDU	 BUFFER[1551]	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define idR1AB01LDU	 661	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
#define R1AB02LDU	 BUFFER[1553]	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define idR1AB02LDU	 662	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
#define R2AZ03LDU	 BUFFER[1555]	//( - , DU) Несанкционированное перемещение МДЗ2
#define idR2AZ03LDU	 663	//( - , DU) Несанкционированное перемещение МДЗ2
#define R2AB01LDU	 BUFFER[1557]	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define idR2AB01LDU	 664	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
#define R2AB02LDU	 BUFFER[1559]	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define idR2AB02LDU	 665	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
#define R1AB04LDU	 BUFFER[1561]	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define idR1AB04LDU	 666	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
#define R2AB04LDU	 BUFFER[1563]	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define idR2AB04LDU	 667	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
#define R1AD10LDU	 BUFFER[1565]	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define idR1AD10LDU	 668	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
#define R1AD20LDU	 BUFFER[1567]	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	 669	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
#define R1IS11LDU	 BUFFER[1569]	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define idR1IS11LDU	 670	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
#define R1VS22LDU	 BUFFER[1571]	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 671	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
#define A2AB10LDU	 BUFFER[1573]	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define idA2AB10LDU	 672	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
#define A2AB11LDU	 BUFFER[1575]	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define idA2AB11LDU	 673	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
#define A2AB12LDU	 BUFFER[1577]	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA2AB12LDU	 674	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A2AB13LDU	 BUFFER[1579]	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define idA2AB13LDU	 675	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
#define A2AB14LDU	 BUFFER[1581]	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define idA2AB14LDU	 676	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
#define A2AB16LDU	 BUFFER[1583]	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define idA2AB16LDU	 677	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
#define A2AB17LDU	 BUFFER[1585]	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define idA2AB17LDU	 678	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
#define A2AD01LDU	 BUFFER[1587]	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define idA2AD01LDU	 679	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
#define A2CV02RDU	 BUFFER[1589]	//( - , DU) Заданная скорость перемещения РБ1
#define idA2CV02RDU	 680	//( - , DU) Заданная скорость перемещения РБ1
#define B2CV01RDU	 BUFFER[1594]	//( - , DU) Измеренная скорость перемещения РБ2
#define idB2CV01RDU	 681	//( - , DU) Измеренная скорость перемещения РБ2
#define B2AB04LDU	 BUFFER[1599]	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define idB2AB04LDU	 682	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
#define B2AB02LDU	 BUFFER[1601]	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define idB2AB02LDU	 683	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
#define B2AB01LDU	 BUFFER[1603]	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define idB2AB01LDU	 684	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
#define B2AZ03LDU	 BUFFER[1605]	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define idB2AZ03LDU	 685	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
#define B2AD11LDU	 BUFFER[1607]	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 686	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
#define B2AD21LDU	 BUFFER[1609]	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 687	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
#define B2AD02LDU	 BUFFER[1611]	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define idB2AD02LDU	 688	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[1613]	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define idB2AD03LDU	 689	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
#define B2AD04LDU	 BUFFER[1615]	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define idB2AD04LDU	 690	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
#define B2AD05LDU	 BUFFER[1617]	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define idB2AD05LDU	 691	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
#define B2AD01LDU	 BUFFER[1619]	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define idB2AD01LDU	 692	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
#define B2CV02RDU	 BUFFER[1621]	//( - , DU) Заданная скорость перемещения РБ2
#define idB2CV02RDU	 693	//( - , DU) Заданная скорость перемещения РБ2
#define B2AB07LDU	 BUFFER[1626]	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define idB2AB07LDU	 694	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
#define A1AB10LDU	 BUFFER[1628]	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define idA1AB10LDU	 695	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
#define A1AB11LDU	 BUFFER[1630]	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define idA1AB11LDU	 696	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
#define A1AB12LDU	 BUFFER[1632]	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define idA1AB12LDU	 697	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
#define A1AB13LDU	 BUFFER[1634]	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define idA1AB13LDU	 698	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
#define A1AB14LDU	 BUFFER[1636]	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define idA1AB14LDU	 699	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
#define A1AB16LDU	 BUFFER[1638]	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define idA1AB16LDU	 700	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
#define A1AB17LDU	 BUFFER[1640]	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define idA1AB17LDU	 701	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
#define A1AB18LDU	 BUFFER[1642]	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define idA1AB18LDU	 702	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
#define B1VS12LDU	 BUFFER[1644]	//( - , DU) Движение ББ2 в сторону ВУ
#define idB1VS12LDU	 703	//( - , DU) Движение ББ2 в сторону ВУ
#define B1CV01RDU	 BUFFER[1646]	//( - , DU) Измеренная скорость перемещения ББ2
#define idB1CV01RDU	 704	//( - , DU) Измеренная скорость перемещения ББ2
#define B1AB04LDU	 BUFFER[1651]	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define idB1AB04LDU	 705	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
#define B1AB02LDU	 BUFFER[1653]	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define idB1AB02LDU	 706	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
#define B1AB01LDU	 BUFFER[1655]	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define idB1AB01LDU	 707	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
#define B1VS22LDU	 BUFFER[1657]	//( - , DU) Движение ББ2 в сторону НУ
#define idB1VS22LDU	 708	//( - , DU) Движение ББ2 в сторону НУ
#define B1AZ03LDU	 BUFFER[1659]	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define idB1AZ03LDU	 709	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
#define B1AD11LDU	 BUFFER[1661]	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 710	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
#define B1AD21LDU	 BUFFER[1663]	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 711	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
#define B1AD02LDU	 BUFFER[1665]	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define idB1AD02LDU	 712	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[1667]	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define idB1AD03LDU	 713	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
#define B1AD04LDU	 BUFFER[1669]	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define idB1AD04LDU	 714	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
#define B1AD05LDU	 BUFFER[1671]	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define idB1AD05LDU	 715	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
#define B1AD01LDU	 BUFFER[1673]	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define idB1AD01LDU	 716	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
#define B1CV02RDU	 BUFFER[1675]	//( - , DU) Заданная скорость перемещения ББ2
#define idB1CV02RDU	 717	//( - , DU) Заданная скорость перемещения ББ2
#define R2VS22LDU	 BUFFER[1680]	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 718	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
#define R2VS12LDU	 BUFFER[1682]	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 719	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
#define R1VS12LDU	 BUFFER[1684]	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 720	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
#define R2IS11LDU	 BUFFER[1686]	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define idR2IS11LDU	 721	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
#define A1VS12LDU	 BUFFER[1688]	//( - , DU) Движение ББ1 в сторону ВУ
#define idA1VS12LDU	 722	//( - , DU) Движение ББ1 в сторону ВУ
#define A1CV01RDU	 BUFFER[1690]	//( - , DU) Измеренная скорость перемещения ББ1
#define idA1CV01RDU	 723	//( - , DU) Измеренная скорость перемещения ББ1
#define A1AB04LDU	 BUFFER[1695]	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define idA1AB04LDU	 724	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
#define A1AB02LDU	 BUFFER[1697]	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define idA1AB02LDU	 725	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
#define A1AB01LDU	 BUFFER[1699]	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define idA1AB01LDU	 726	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
#define A1VS22LDU	 BUFFER[1701]	//( - , DU) Движение ББ1 в сторону НУ
#define idA1VS22LDU	 727	//( - , DU) Движение ББ1 в сторону НУ
#define A1AZ03LDU	 BUFFER[1703]	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define idA1AZ03LDU	 728	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
#define A1AD11LDU	 BUFFER[1705]	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 729	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
#define A1AD21LDU	 BUFFER[1707]	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 730	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
#define A1AD02LDU	 BUFFER[1709]	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define idA1AD02LDU	 731	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[1711]	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define idA1AD03LDU	 732	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
#define A1AD04LDU	 BUFFER[1713]	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define idA1AD04LDU	 733	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
#define A1AD05LDU	 BUFFER[1715]	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define idA1AD05LDU	 734	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
#define A1AD01LDU	 BUFFER[1717]	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define idA1AD01LDU	 735	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
#define A1CV02RDU	 BUFFER[1719]	//( - , DU) Заданная скорость перемещения ББ1
#define idA1CV02RDU	 736	//( - , DU) Заданная скорость перемещения ББ1
#define A1AB07LDU	 BUFFER[1724]	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define idA1AB07LDU	 737	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
#define A1AB08LDU	 BUFFER[1726]	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define idA1AB08LDU	 738	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
#define A1AB05LDU	 BUFFER[1728]	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define idA1AB05LDU	 739	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
#define A1AB06LDU	 BUFFER[1730]	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define idA1AB06LDU	 740	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
#define A1AB09LDU	 BUFFER[1732]	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define idA1AB09LDU	 741	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
#define fEM_A1UC03RDU	 BUFFER[1734]	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define idfEM_A1UC03RDU	 742	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
#define dEM_A1UC05UDU	 BUFFER[1739]	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC05UDU	 743	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
#define dEM_A1UC06UDU	 BUFFER[1744]	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define iddEM_A1UC06UDU	 744	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
#define dEM_A2UC06UDU	 BUFFER[1749]	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC06UDU	 745	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
#define dEM_A2UC05UDU	 BUFFER[1754]	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define iddEM_A2UC05UDU	 746	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
#define fEM_A2UC03RDU	 BUFFER[1759]	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define idfEM_A2UC03RDU	 747	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
#define dEM_A3UC06UDU	 BUFFER[1764]	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC06UDU	 748	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
#define dEM_A3UC05UDU	 BUFFER[1769]	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define iddEM_A3UC05UDU	 749	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
#define fEM_A3UC03RDU	 BUFFER[1774]	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define idfEM_A3UC03RDU	 750	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
#define dEM_A8UC06UDU	 BUFFER[1779]	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define iddEM_A8UC06UDU	 751	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
#define fEM_A8UC03RDU	 BUFFER[1784]	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define idfEM_A8UC03RDU	 752	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
#define dEM_A8UC05UDU	 BUFFER[1789]	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define iddEM_A8UC05UDU	 753	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
#define fEM_R0UV81RDU	 BUFFER[1794]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 754	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1799]	//(R0UV82RDU) 2-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 755	//(R0UV82RDU) 2-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1804]	//(R0UV83RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 756	//(R0UV83RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1809]	//(R0UV84RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 757	//(R0UV84RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1814]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 758	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1819]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 759	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV87RDU	 BUFFER[1824]	//(R0UV87RDU) 8-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 760	//(R0UV87RDU) 8-я скорость перемещения ББ (шагов/секунду)
#define fEM_A3UP03RDU	 BUFFER[1829]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 761	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1834]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 762	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP43RDU	 BUFFER[1839]	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define idfEM_A3UP43RDU	 763	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
#define fEM_A3UP44RDU	 BUFFER[1844]	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP44RDU	 764	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP53RDU	 BUFFER[1849]	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP53RDU	 765	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP85RDU	 BUFFER[1854]	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP85RDU	 766	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP88RDU	 BUFFER[1859]	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP88RDU	 767	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_A3UP86RDU	 BUFFER[1864]	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP86RDU	 768	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_B8UV01RDU	 BUFFER[1869]	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define idfEM_B8UV01RDU	 769	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
#define fEM_B8UV02RDU	 BUFFER[1874]	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define idfEM_B8UV02RDU	 770	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
#define fEM_B8UV03RDU	 BUFFER[1879]	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define idfEM_B8UV03RDU	 771	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
#define fEM_B8UL04RDU	 BUFFER[1884]	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define idfEM_B8UL04RDU	 772	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
#define iEM_A2UV03CDU	 BUFFER[1889]	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define idiEM_A2UV03CDU	 773	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
#define fEM_A2UV01RDU	 BUFFER[1892]	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define idfEM_A2UV01RDU	 774	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
#define fEM_A2UV02RDU	 BUFFER[1897]	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define idfEM_A2UV02RDU	 775	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
#define fEM_A1UV01RDU	 BUFFER[1902]	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define idfEM_A1UV01RDU	 776	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
#define fEM_A1UV02RDU	 BUFFER[1907]	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define idfEM_A1UV02RDU	 777	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
#define fEM_A1UC06RDU	 BUFFER[1912]	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define idfEM_A1UC06RDU	 778	//(A1UC06RDU) Уставка определения самохода ББ  мм
#define fEM_A1UC05RDU	 BUFFER[1917]	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A1UC05RDU	 779	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A1UL04RDU	 BUFFER[1922]	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define idfEM_A1UL04RDU	 780	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
#define fEM_A3UV01RDU	 BUFFER[1927]	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define idfEM_A3UV01RDU	 781	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
#define fEM_A3UV02RDU	 BUFFER[1932]	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define idfEM_A3UV02RDU	 782	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
#define fEM_A3UC06RDU	 BUFFER[1937]	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define idfEM_A3UC06RDU	 783	//(A3UC06RDU) Уставка определения самохода ИС1  мм
#define fEM_A3UC05RDU	 BUFFER[1942]	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A3UC05RDU	 784	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A3UL04RDU	 BUFFER[1947]	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define idfEM_A3UL04RDU	 785	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
#define fEM_A3UP54RDU	 BUFFER[1952]	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define idfEM_A3UP54RDU	 786	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
#define fEM_A3UP87RDU	 BUFFER[1957]	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define idfEM_A3UP87RDU	 787	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
#define fEM_R0UL05RDU	 BUFFER[1962]	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define idfEM_R0UL05RDU	 788	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
#define fEM_R0UL20RDU	 BUFFER[1967]	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define idfEM_R0UL20RDU	 789	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
#define fEM_B8UV04RDU	 BUFFER[1972]	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define idfEM_B8UV04RDU	 790	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
#define fEM_B8UC06RDU	 BUFFER[1977]	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define idfEM_B8UC06RDU	 791	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
#define fEM_B8UC05RDU	 BUFFER[1982]	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define idfEM_B8UC05RDU	 792	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL05RDU	 BUFFER[1987]	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define idfEM_A2UL05RDU	 793	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
#define fEM_A2UL03RDU	 BUFFER[1992]	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL03RDU	 794	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A2UC06RDU	 BUFFER[1997]	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define idfEM_A2UC06RDU	 795	//(A2UC06RDU) Уставка определения самохода РБ  мм
#define fEM_A2UC05RDU	 BUFFER[2002]	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define idfEM_A2UC05RDU	 796	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
#define fEM_A2UL04RDU	 BUFFER[2007]	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define idfEM_A2UL04RDU	 797	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
#define fEM_A1UL03RDU	 BUFFER[2012]	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define idfEM_A1UL03RDU	 798	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
#define fEM_A1UL05RDU	 BUFFER[2017]	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define idfEM_A1UL05RDU	 799	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
#define fEM_A3UL03RDU	 BUFFER[2022]	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define idfEM_A3UL03RDU	 800	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
#define fEM_A3UL05RDU	 BUFFER[2027]	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define idfEM_A3UL05RDU	 801	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
#define fEM_A1UC08RDU	 BUFFER[2032]	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define idfEM_A1UC08RDU	 802	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
#define fEM_A3UC08RDU	 BUFFER[2037]	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define idfEM_A3UC08RDU	 803	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
#define fEM_A1UC07RDU	 BUFFER[2042]	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define idfEM_A1UC07RDU	 804	//(A1UC07RDU) Зона возврата при наведении ББ мм
#define fEM_A1UL01RDU	 BUFFER[2047]	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A1UL01RDU	 805	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A3UC07RDU	 BUFFER[2052]	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define idfEM_A3UC07RDU	 806	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
#define fEM_A3UL01RDU	 BUFFER[2057]	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A3UL01RDU	 807	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_A2UC08RDU	 BUFFER[2062]	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define idfEM_A2UC08RDU	 808	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
#define fEM_A2UC07RDU	 BUFFER[2067]	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define idfEM_A2UC07RDU	 809	//(A2UC07RDU) Зона возврата при наведении РБ  мм
#define fEM_A2UL01RDU	 BUFFER[2072]	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_A2UL01RDU	 810	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UC01RDU	 BUFFER[2077]	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define idfEM_B8UC01RDU	 811	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
#define fEM_B8UL07RDU	 BUFFER[2082]	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define idfEM_B8UL07RDU	 812	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
#define fEM_B8UC02RDU	 BUFFER[2087]	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define idfEM_B8UC02RDU	 813	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
#define fEM_B8UL01RDU	 BUFFER[2092]	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define idfEM_B8UL01RDU	 814	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
#define fEM_B8UL05RDU	 BUFFER[2097]	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define idfEM_B8UL05RDU	 815	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
#define fEM_B8UL03RDU	 BUFFER[2102]	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define idfEM_B8UL03RDU	 816	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
#define fEM_B8UL06RDU	 BUFFER[2107]	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define idfEM_B8UL06RDU	 817	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
#define fEM_A9UZ03RDU	 BUFFER[2112]	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define idfEM_A9UZ03RDU	 818	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
#define fEM_A9UZ04RDU	 BUFFER[2117]	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define idfEM_A9UZ04RDU	 819	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
#define fEM_A9UZ05RDU	 BUFFER[2122]	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define idfEM_A9UZ05RDU	 820	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
#define fEM_R4UZ04RDU	 BUFFER[2127]	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define idfEM_R4UZ04RDU	 821	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
#define fEM_R4UZ03RDU	 BUFFER[2132]	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define idfEM_R4UZ03RDU	 822	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
#define fEM_R4UZ05RDU	 BUFFER[2137]	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define idfEM_R4UZ05RDU	 823	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
#define fEM_A5UZ03RDU	 BUFFER[2142]	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define idfEM_A5UZ03RDU	 824	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
#define fEM_A5UZ04RDU	 BUFFER[2147]	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define idfEM_A5UZ04RDU	 825	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
#define fEM_A5UZ05RDU	 BUFFER[2152]	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define idfEM_A5UZ05RDU	 826	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
#define fEM_A4UZ03RDU	 BUFFER[2157]	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define idfEM_A4UZ03RDU	 827	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
#define fEM_A4UZ04RDU	 BUFFER[2162]	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define idfEM_A4UZ04RDU	 828	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
#define fEM_A4UZ05RDU	 BUFFER[2167]	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define idfEM_A4UZ05RDU	 829	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
#define fEM_A6UZ03RDU	 BUFFER[2172]	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define idfEM_A6UZ03RDU	 830	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
#define fEM_A6UZ04RDU	 BUFFER[2177]	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define idfEM_A6UZ04RDU	 831	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
#define fEM_A6UZ05RDU	 BUFFER[2182]	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define idfEM_A6UZ05RDU	 832	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
#define fEM_R1UZ03RDU	 BUFFER[2187]	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define idfEM_R1UZ03RDU	 833	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
#define fEM_R1UZ04RDU	 BUFFER[2192]	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define idfEM_R1UZ04RDU	 834	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
#define fEM_R1UZ05RDU	 BUFFER[2197]	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define idfEM_R1UZ05RDU	 835	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
#define fEM_R0UL04RDU	 BUFFER[2202]	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define idfEM_R0UL04RDU	 836	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
#define fEM_R0UL06RDU	 BUFFER[2207]	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define idfEM_R0UL06RDU	 837	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
#define fEM_R0UL03RDU	 BUFFER[2212]	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define idfEM_R0UL03RDU	 838	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
#define fEM_R0UL17RDU	 BUFFER[2217]	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define idfEM_R0UL17RDU	 839	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
#define fEM_R0UL19RDU	 BUFFER[2222]	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL19RDU	 840	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define fEM_R0UL07RDU	 BUFFER[2227]	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define idfEM_R0UL07RDU	 841	//(R0UL07RDU) Время срабатывания верхней АС II УР
#define fEM_R0UL18RDU	 BUFFER[2232]	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define idfEM_R0UL18RDU	 842	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
#define fEM_R0UL16RDU	 BUFFER[2237]	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define idfEM_R0UL16RDU	 843	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
#define fEM_R0UL02RDU	 BUFFER[2242]	//(R0UL02RDU) Время задержки  ИНИ
#define idfEM_R0UL02RDU	 844	//(R0UL02RDU) Время задержки  ИНИ
#define fEM_R0UN08RDU	 BUFFER[2247]	//(R0UN08RDU) 8-я заданная мощность
#define idfEM_R0UN08RDU	 845	//(R0UN08RDU) 8-я заданная мощность
#define fEM_R0UN07RDU	 BUFFER[2252]	//(R0UN07RDU) 7-я заданная мощность
#define idfEM_R0UN07RDU	 846	//(R0UN07RDU) 7-я заданная мощность
#define fEM_R0UN06RDU	 BUFFER[2257]	//(R0UN06RDU) 6-я заданная мощность
#define idfEM_R0UN06RDU	 847	//(R0UN06RDU) 6-я заданная мощность
#define fEM_R0UN05RDU	 BUFFER[2262]	//(R0UN05RDU) 5-я заданная мощность
#define idfEM_R0UN05RDU	 848	//(R0UN05RDU) 5-я заданная мощность
#define fEM_R0UN04RDU	 BUFFER[2267]	//(R0UN04RDU) 4-я заданная мощность
#define idfEM_R0UN04RDU	 849	//(R0UN04RDU) 4-я заданная мощность
#define fEM_R0UN03RDU	 BUFFER[2272]	//(R0UN03RDU) Ограничение 3 по мощности
#define idfEM_R0UN03RDU	 850	//(R0UN03RDU) Ограничение 3 по мощности
#define fEM_R0UN02RDU	 BUFFER[2277]	//(R0UN02RDU) 2-я заданная мощность
#define idfEM_R0UN02RDU	 851	//(R0UN02RDU) 2-я заданная мощность
#define fEM_R0UN01RDU	 BUFFER[2282]	//(R0UN01RDU) 1-я заданная мощность
#define idfEM_R0UN01RDU	 852	//(R0UN01RDU) 1-я заданная мощность
#define fEM_A2UC82RDU	 BUFFER[2287]	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC82RDU	 853	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
#define fEM_A2UC83RDU	 BUFFER[2292]	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define idfEM_A2UC83RDU	 854	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
#define fEM_A1UC83RDU	 BUFFER[2297]	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define idfEM_A1UC83RDU	 855	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
#define fEM_A2UC81RDU	 BUFFER[2302]	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define idfEM_A2UC81RDU	 856	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
#define fEM_A1UC81RDU	 BUFFER[2307]	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC81RDU	 857	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
#define fEM_A1UC82RDU	 BUFFER[2312]	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define idfEM_A1UC82RDU	 858	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
#define fEM_A2UL83RDU	 BUFFER[2317]	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define idfEM_A2UL83RDU	 859	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
#define fEM_A3UC81RDU	 BUFFER[2322]	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define idfEM_A3UC81RDU	 860	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
#define fEM_A3UC82RDU	 BUFFER[2327]	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define idfEM_A3UC82RDU	 861	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
#define fEM_R0UN80RDU	 BUFFER[2332]	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define idfEM_R0UN80RDU	 862	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
#define iEM_A2UV01IDU	 BUFFER[2337]	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV01IDU	 863	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
#define iEM_A2UV02IDU	 BUFFER[2340]	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define idiEM_A2UV02IDU	 864	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
#define iEM_A1UV01IDU	 BUFFER[2343]	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV01IDU	 865	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
#define iEM_A1UV02IDU	 BUFFER[2346]	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define idiEM_A1UV02IDU	 866	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
#define iEM_A1UV03IDU	 BUFFER[2349]	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define idiEM_A1UV03IDU	 867	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
#define iEM_A3UV01IDU	 BUFFER[2352]	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define idiEM_A3UV01IDU	 868	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
#define iEM_A3UV02IDU	 BUFFER[2355]	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define idiEM_A3UV02IDU	 869	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
#define lEM_R0MD01LC1	 BUFFER[2358]	//(R0MD01LC1) Ручное управление ОРР
#define idlEM_R0MD01LC1	 870	//(R0MD01LC1) Ручное управление ОРР
#define fEM_A3UC09RDU	 BUFFER[2360]	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC09RDU	 871	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
#define fEM_A2UC02RDU	 BUFFER[2365]	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define idfEM_A2UC02RDU	 872	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
#define fEM_A1UC02RDU	 BUFFER[2370]	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define idfEM_A1UC02RDU	 873	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
#define fEM_A3UC02RDU	 BUFFER[2375]	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define idfEM_A3UC02RDU	 874	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
#define fEM_R0UL21RDU	 BUFFER[2380]	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define idfEM_R0UL21RDU	 875	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
#define fEM_R0UN09RDU	 BUFFER[2385]	//(R0UN09RDU) Минимальный период при регулировании мощности
#define idfEM_R0UN09RDU	 876	//(R0UN09RDU) Минимальный период при регулировании мощности
#define fEM_R0UN11RDU	 BUFFER[2390]	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define idfEM_R0UN11RDU	 877	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
#define fEM_R0UN12RDU	 BUFFER[2395]	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define idfEM_R0UN12RDU	 878	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
#define fEM_R0UN13RDU	 BUFFER[2400]	//(R0UN13RDU) Минимальное изменение координаты, мм
#define idfEM_R0UN13RDU	 879	//(R0UN13RDU) Минимальное изменение координаты, мм
#define fEM_R0UN14RDU	 BUFFER[2405]	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define idfEM_R0UN14RDU	 880	//(R0UN14RDU) Максимальная координата штока ИМ, мм
#define fEM_R0UN16RDU	 BUFFER[2410]	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN16RDU	 881	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN17RDU	 BUFFER[2415]	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define idfEM_R0UN17RDU	 882	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
#define fEM_R0UN18RDU	 BUFFER[2420]	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define idfEM_R0UN18RDU	 883	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
#define fEM_R0UN19RDU	 BUFFER[2425]	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define idfEM_R0UN19RDU	 884	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
#define fEM_R0UN70LDU	 BUFFER[2430]	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN70LDU	 885	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN71LDU	 BUFFER[2435]	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN71LDU	 886	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN72LDU	 BUFFER[2440]	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN72LDU	 887	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN73LDU	 BUFFER[2445]	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN73LDU	 888	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN74LDU	 BUFFER[2450]	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN74LDU	 889	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN75LDU	 BUFFER[2455]	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define idfEM_R0UN75LDU	 890	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
#define fEM_R0UN80LDU	 BUFFER[2460]	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN80LDU	 891	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
#define fEM_R0UN81LDU	 BUFFER[2465]	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN81LDU	 892	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
#define fEM_R0UN82LDU	 BUFFER[2470]	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN82LDU	 893	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
#define fEM_R0UN83LDU	 BUFFER[2475]	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN83LDU	 894	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
#define fEM_R0UN84LDU	 BUFFER[2480]	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN84LDU	 895	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
#define fEM_R0UN85LDU	 BUFFER[2485]	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define idfEM_R0UN85LDU	 896	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
#define fEM_R0UT20RDU	 BUFFER[2490]	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define idfEM_R0UT20RDU	 897	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
#define fEM_R0UN25RDU	 BUFFER[2495]	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define idfEM_R0UN25RDU	 898	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
#define fEM_R0UN15RDU	 BUFFER[2500]	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define idfEM_R0UN15RDU	 899	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
#define fEM_R0UN26RDU	 BUFFER[2505]	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN26RDU	 900	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN27RDU	 BUFFER[2510]	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define idfEM_R0UN27RDU	 901	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
#define fEM_R0UN24RDU	 BUFFER[2515]	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN24RDU	 902	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R0UL25RDU	 BUFFER[2520]	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define idfEM_R0UL25RDU	 903	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
#define fEM_R0UL01RSS	 BUFFER[2525]	//(R0UL01RSS) Шаг измерения периода (сек)
#define idfEM_R0UL01RSS	 904	//(R0UL01RSS) Шаг измерения периода (сек)
#define fEM_R0UL02RSS	 BUFFER[2530]	//(R0UL02RSS) Tф-постоянная времени, с
#define idfEM_R0UL02RSS	 905	//(R0UL02RSS) Tф-постоянная времени, с
#define fEM_R0UN03RSS	 BUFFER[2535]	//(R0UN03RSS) нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN03RSS	 906	//(R0UN03RSS) нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_R7UI76RDU	 BUFFER[2540]	//(R7UI76RDU) Время срабатывания сигнала II УР при имитации
#define idfEM_R7UI76RDU	 907	//(R7UI76RDU) Время срабатывания сигнала II УР при имитации
#define fEM_R0UL00RDU	 BUFFER[2545]	//(R0UL00RDU) Время ожидания передачи  сигнала отключения сети
#define idfEM_R0UL00RDU	 908	//(R0UL00RDU) Время ожидания передачи  сигнала отключения сети
#define bFirstEnterFlag	 BUFFER[2550]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 909	//(bFirstEnterFlag) 
#define internal2_m244_tx	 BUFFER[2552]	//(internal2_m244_tx) tx - время накопленное сек
#define idinternal2_m244_tx	 910	//(internal2_m244_tx) tx - время накопленное сек
#define internal2_m244_y0	 BUFFER[2557]	//(internal2_m244_y0) y0
#define idinternal2_m244_y0	 911	//(internal2_m244_y0) y0
#define internal2_m272_tx	 BUFFER[2558]	//(internal2_m272_tx) tx - время накопленное сек
#define idinternal2_m272_tx	 912	//(internal2_m272_tx) tx - время накопленное сек
#define internal2_m272_y0	 BUFFER[2563]	//(internal2_m272_y0) y0
#define idinternal2_m272_y0	 913	//(internal2_m272_y0) y0
#define internal2_m182_tx	 BUFFER[2564]	//(internal2_m182_tx) tx - время накопленное сек
#define idinternal2_m182_tx	 914	//(internal2_m182_tx) tx - время накопленное сек
#define internal2_m182_y0	 BUFFER[2569]	//(internal2_m182_y0) y0
#define idinternal2_m182_y0	 915	//(internal2_m182_y0) y0
#define internal2_m176_tx	 BUFFER[2570]	//(internal2_m176_tx) tx - время накопленное сек
#define idinternal2_m176_tx	 916	//(internal2_m176_tx) tx - время накопленное сек
#define internal2_m176_y0	 BUFFER[2575]	//(internal2_m176_y0) y0
#define idinternal2_m176_y0	 917	//(internal2_m176_y0) y0
#define internal2_m172_tx	 BUFFER[2576]	//(internal2_m172_tx) tx - время накопленное сек
#define idinternal2_m172_tx	 918	//(internal2_m172_tx) tx - время накопленное сек
#define internal2_m172_y0	 BUFFER[2581]	//(internal2_m172_y0) y0
#define idinternal2_m172_y0	 919	//(internal2_m172_y0) y0
#define internal2_m165_tx	 BUFFER[2582]	//(internal2_m165_tx) tx - время накопленное сек
#define idinternal2_m165_tx	 920	//(internal2_m165_tx) tx - время накопленное сек
#define internal2_m165_y0	 BUFFER[2587]	//(internal2_m165_y0) y0
#define idinternal2_m165_y0	 921	//(internal2_m165_y0) y0
#define internal2_m158_tx	 BUFFER[2588]	//(internal2_m158_tx) tx - время накопленное сек
#define idinternal2_m158_tx	 922	//(internal2_m158_tx) tx - время накопленное сек
#define internal2_m158_y0	 BUFFER[2593]	//(internal2_m158_y0) y0
#define idinternal2_m158_y0	 923	//(internal2_m158_y0) y0
#define internal2_m155_tx	 BUFFER[2594]	//(internal2_m155_tx) tx - время накопленное сек
#define idinternal2_m155_tx	 924	//(internal2_m155_tx) tx - время накопленное сек
#define internal2_m155_y0	 BUFFER[2599]	//(internal2_m155_y0) y0
#define idinternal2_m155_y0	 925	//(internal2_m155_y0) y0
#define internal2_m149_tx	 BUFFER[2600]	//(internal2_m149_tx) tx - время накопленное сек
#define idinternal2_m149_tx	 926	//(internal2_m149_tx) tx - время накопленное сек
#define internal2_m149_y0	 BUFFER[2605]	//(internal2_m149_y0) y0
#define idinternal2_m149_y0	 927	//(internal2_m149_y0) y0
#define internal2_m144_tx	 BUFFER[2606]	//(internal2_m144_tx) tx - время накопленное сек
#define idinternal2_m144_tx	 928	//(internal2_m144_tx) tx - время накопленное сек
#define internal2_m144_y0	 BUFFER[2611]	//(internal2_m144_y0) y0
#define idinternal2_m144_y0	 929	//(internal2_m144_y0) y0
#define internal2_m141_tx	 BUFFER[2612]	//(internal2_m141_tx) tx - время накопленное сек
#define idinternal2_m141_tx	 930	//(internal2_m141_tx) tx - время накопленное сек
#define internal2_m141_y0	 BUFFER[2617]	//(internal2_m141_y0) y0
#define idinternal2_m141_y0	 931	//(internal2_m141_y0) y0
#define internal2_m134_tx	 BUFFER[2618]	//(internal2_m134_tx) tx - время накопленное сек
#define idinternal2_m134_tx	 932	//(internal2_m134_tx) tx - время накопленное сек
#define internal2_m134_y0	 BUFFER[2623]	//(internal2_m134_y0) y0
#define idinternal2_m134_y0	 933	//(internal2_m134_y0) y0
#define internal2_m132_tx	 BUFFER[2624]	//(internal2_m132_tx) tx - время накопленное сек
#define idinternal2_m132_tx	 934	//(internal2_m132_tx) tx - время накопленное сек
#define internal2_m132_y0	 BUFFER[2629]	//(internal2_m132_y0) y0
#define idinternal2_m132_y0	 935	//(internal2_m132_y0) y0
#define internal2_m127_tx	 BUFFER[2630]	//(internal2_m127_tx) tx - время накопленное сек
#define idinternal2_m127_tx	 936	//(internal2_m127_tx) tx - время накопленное сек
#define internal2_m127_y0	 BUFFER[2635]	//(internal2_m127_y0) y0
#define idinternal2_m127_y0	 937	//(internal2_m127_y0) y0
#define internal2_m195_y0	 BUFFER[2636]	//(internal2_m195_y0) y0
#define idinternal2_m195_y0	 938	//(internal2_m195_y0) y0
#define internal2_m193_y0	 BUFFER[2641]	//(internal2_m193_y0) y0
#define idinternal2_m193_y0	 939	//(internal2_m193_y0) y0
#define internal2_m227_y0	 BUFFER[2646]	//(internal2_m227_y0) state
#define idinternal2_m227_y0	 940	//(internal2_m227_y0) state
#define internal2_m220_y0	 BUFFER[2648]	//(internal2_m220_y0) state
#define idinternal2_m220_y0	 941	//(internal2_m220_y0) state
#define internal2_m209_y1	 BUFFER[2650]	//(internal2_m209_y1) y1 - внутренний параметр
#define idinternal2_m209_y1	 942	//(internal2_m209_y1) y1 - внутренний параметр
#define internal2_m216_y1	 BUFFER[2652]	//(internal2_m216_y1) y1 - внутренний параметр
#define idinternal2_m216_y1	 943	//(internal2_m216_y1) y1 - внутренний параметр
#define internal2_m198_y1	 BUFFER[2654]	//(internal2_m198_y1) y1 - внутренний параметр
#define idinternal2_m198_y1	 944	//(internal2_m198_y1) y1 - внутренний параметр
#define internal2_m206_y1	 BUFFER[2656]	//(internal2_m206_y1) y1 - внутренний параметр
#define idinternal2_m206_y1	 945	//(internal2_m206_y1) y1 - внутренний параметр
#define internal2_m16_Nk0	 BUFFER[2658]	//(internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m16_Nk0	 946	//(internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m16_SetFlag	 BUFFER[2663]	//(internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m16_SetFlag	 947	//(internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m109_Nk0	 BUFFER[2665]	//(internal2_m109_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m109_Nk0	 948	//(internal2_m109_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m109_SetFlag	 BUFFER[2670]	//(internal2_m109_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m109_SetFlag	 949	//(internal2_m109_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m112_Nk0	 BUFFER[2672]	//(internal2_m112_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m112_Nk0	 950	//(internal2_m112_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m112_SetFlag	 BUFFER[2677]	//(internal2_m112_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m112_SetFlag	 951	//(internal2_m112_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m77_Nk0	 BUFFER[2679]	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m77_Nk0	 952	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m77_SetFlag	 BUFFER[2684]	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m77_SetFlag	 953	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m83_Nk0	 BUFFER[2686]	//(internal2_m83_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m83_Nk0	 954	//(internal2_m83_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m83_SetFlag	 BUFFER[2691]	//(internal2_m83_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m83_SetFlag	 955	//(internal2_m83_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m49_Nk0	 BUFFER[2693]	//(internal2_m49_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m49_Nk0	 956	//(internal2_m49_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m49_SetFlag	 BUFFER[2698]	//(internal2_m49_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m49_SetFlag	 957	//(internal2_m49_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m53_Nk0	 BUFFER[2700]	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m53_Nk0	 958	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m53_SetFlag	 BUFFER[2705]	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m53_SetFlag	 959	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal2_m21_Nk0	 BUFFER[2707]	//(internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define idinternal2_m21_Nk0	 960	//(internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
#define internal2_m21_SetFlag	 BUFFER[2712]	//(internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define idinternal2_m21_SetFlag	 961	//(internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
#define internal1_m2556_tx	 BUFFER[2714]	//(internal1_m2556_tx) tx - время накопленное сек
#define idinternal1_m2556_tx	 962	//(internal1_m2556_tx) tx - время накопленное сек
#define internal1_m2556_y0	 BUFFER[2719]	//(internal1_m2556_y0) y0
#define idinternal1_m2556_y0	 963	//(internal1_m2556_y0) y0
#define internal1_m2558_tx	 BUFFER[2720]	//(internal1_m2558_tx) tx - время накопленное сек
#define idinternal1_m2558_tx	 964	//(internal1_m2558_tx) tx - время накопленное сек
#define internal1_m2558_y0	 BUFFER[2725]	//(internal1_m2558_y0) y0
#define idinternal1_m2558_y0	 965	//(internal1_m2558_y0) y0
#define internal1_m2554_tx	 BUFFER[2726]	//(internal1_m2554_tx) tx - время накопленное сек
#define idinternal1_m2554_tx	 966	//(internal1_m2554_tx) tx - время накопленное сек
#define internal1_m2554_y0	 BUFFER[2731]	//(internal1_m2554_y0) y0
#define idinternal1_m2554_y0	 967	//(internal1_m2554_y0) y0
#define internal1_m2552_tx	 BUFFER[2732]	//(internal1_m2552_tx) tx - время накопленное сек
#define idinternal1_m2552_tx	 968	//(internal1_m2552_tx) tx - время накопленное сек
#define internal1_m2552_y0	 BUFFER[2737]	//(internal1_m2552_y0) y0
#define idinternal1_m2552_y0	 969	//(internal1_m2552_y0) y0
#define internal1_m221_tx	 BUFFER[2738]	//(internal1_m221_tx) tx - время накопленное сек
#define idinternal1_m221_tx	 970	//(internal1_m221_tx) tx - время накопленное сек
#define internal1_m221_y0	 BUFFER[2743]	//(internal1_m221_y0) y0
#define idinternal1_m221_y0	 971	//(internal1_m221_y0) y0
#define internal1_m220_tx	 BUFFER[2744]	//(internal1_m220_tx) tx - внутренний параметр
#define idinternal1_m220_tx	 972	//(internal1_m220_tx) tx - внутренний параметр
#define internal1_m2101_x0	 BUFFER[2749]	//(internal1_m2101_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m2101_x0	 973	//(internal1_m2101_x0) - значение входного параметра на предыдущем шаге
#define internal1_m2101_tim	 BUFFER[2751]	//(internal1_m2101_tim) - время задержки выходного сигнала
#define idinternal1_m2101_tim	 974	//(internal1_m2101_tim) - время задержки выходного сигнала
#define internal1_m1677_tx	 BUFFER[2756]	//(internal1_m1677_tx) tx - время накопленное сек
#define idinternal1_m1677_tx	 975	//(internal1_m1677_tx) tx - время накопленное сек
#define internal1_m1677_y0	 BUFFER[2761]	//(internal1_m1677_y0) y0
#define idinternal1_m1677_y0	 976	//(internal1_m1677_y0) y0
#define internal1_m79_flst	 BUFFER[2762]	//(internal1_m79_flst)  флаг старта измерения
#define idinternal1_m79_flst	 977	//(internal1_m79_flst)  флаг старта измерения
#define internal1_m79_chsr	 BUFFER[2765]	//(internal1_m79_chsr)  счетчик усреднения
#define idinternal1_m79_chsr	 978	//(internal1_m79_chsr)  счетчик усреднения
#define internal1_m79_chizm	 BUFFER[2768]	//(internal1_m79_chizm)  счетчик уменьшения мощности
#define idinternal1_m79_chizm	 979	//(internal1_m79_chizm)  счетчик уменьшения мощности
#define internal1_m79_sumtim	 BUFFER[2771]	//(internal1_m79_sumtim)  время измерения мощности
#define idinternal1_m79_sumtim	 980	//(internal1_m79_sumtim)  время измерения мощности
#define internal1_m79_W1	 BUFFER[2776]	//(internal1_m79_W1)  мощность на старте измерения
#define idinternal1_m79_W1	 981	//(internal1_m79_W1)  мощность на старте измерения
#define internal1_m79_W2	 BUFFER[2781]	//(internal1_m79_W2)  мощность в конце измерения
#define idinternal1_m79_W2	 982	//(internal1_m79_W2)  мощность в конце измерения
#define internal1_m79_Wmin	 BUFFER[2786]	//(internal1_m79_Wmin)  минимальное измерение в серии
#define idinternal1_m79_Wmin	 983	//(internal1_m79_Wmin)  минимальное измерение в серии
#define internal1_m79_Wmax	 BUFFER[2791]	//(internal1_m79_Wmax)  максимальное измерение в серии
#define idinternal1_m79_Wmax	 984	//(internal1_m79_Wmax)  максимальное измерение в серии
#define internal1_m79_Wlast	 BUFFER[2796]	//(internal1_m79_Wlast)  последнее растущее измерение
#define idinternal1_m79_Wlast	 985	//(internal1_m79_Wlast)  последнее растущее измерение
#define internal1_m79_y0	 BUFFER[2801]	//(internal1_m79_y0) y0 - внутренний параметр
#define idinternal1_m79_y0	 986	//(internal1_m79_y0) y0 - внутренний параметр
#define internal1_m79_MyFirstEnterFlag	 BUFFER[2806]	//(internal1_m79_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m79_MyFirstEnterFlag	 987	//(internal1_m79_MyFirstEnterFlag)  FirstEnterFlag
#define internal1_m2066_tx	 BUFFER[2808]	//(internal1_m2066_tx) tx - внутренний параметр
#define idinternal1_m2066_tx	 988	//(internal1_m2066_tx) tx - внутренний параметр
#define internal1_m2065_tx	 BUFFER[2813]	//(internal1_m2065_tx) tx - внутренний параметр
#define idinternal1_m2065_tx	 989	//(internal1_m2065_tx) tx - внутренний параметр
#define internal1_m785_tx	 BUFFER[2818]	//(internal1_m785_tx) tx - внутренний параметр
#define idinternal1_m785_tx	 990	//(internal1_m785_tx) tx - внутренний параметр
#define internal1_m742_tx	 BUFFER[2823]	//(internal1_m742_tx) tx - внутренний параметр
#define idinternal1_m742_tx	 991	//(internal1_m742_tx) tx - внутренний параметр
#define internal1_m795_tx	 BUFFER[2828]	//(internal1_m795_tx) tx - внутренний параметр
#define idinternal1_m795_tx	 992	//(internal1_m795_tx) tx - внутренний параметр
#define internal1_m797_tx	 BUFFER[2833]	//(internal1_m797_tx) tx - внутренний параметр
#define idinternal1_m797_tx	 993	//(internal1_m797_tx) tx - внутренний параметр
#define internal1_m796_tx	 BUFFER[2838]	//(internal1_m796_tx) tx - внутренний параметр
#define idinternal1_m796_tx	 994	//(internal1_m796_tx) tx - внутренний параметр
#define internal1_m750_tx	 BUFFER[2843]	//(internal1_m750_tx) tx - внутренний параметр
#define idinternal1_m750_tx	 995	//(internal1_m750_tx) tx - внутренний параметр
#define internal1_m735_tx	 BUFFER[2848]	//(internal1_m735_tx) tx - внутренний параметр
#define idinternal1_m735_tx	 996	//(internal1_m735_tx) tx - внутренний параметр
#define internal1_m746_tx	 BUFFER[2853]	//(internal1_m746_tx) tx - внутренний параметр
#define idinternal1_m746_tx	 997	//(internal1_m746_tx) tx - внутренний параметр
#define internal1_m777_tx	 BUFFER[2858]	//(internal1_m777_tx) tx - внутренний параметр
#define idinternal1_m777_tx	 998	//(internal1_m777_tx) tx - внутренний параметр
#define internal1_m794_tx	 BUFFER[2863]	//(internal1_m794_tx) tx - внутренний параметр
#define idinternal1_m794_tx	 999	//(internal1_m794_tx) tx - внутренний параметр
#define internal1_m767_tx	 BUFFER[2868]	//(internal1_m767_tx) tx - внутренний параметр
#define idinternal1_m767_tx	 1000	//(internal1_m767_tx) tx - внутренний параметр
#define internal1_m398_tx	 BUFFER[2873]	//(internal1_m398_tx) tx - внутренний параметр
#define idinternal1_m398_tx	 1001	//(internal1_m398_tx) tx - внутренний параметр
#define internal1_m397_tx	 BUFFER[2878]	//(internal1_m397_tx) tx - внутренний параметр
#define idinternal1_m397_tx	 1002	//(internal1_m397_tx) tx - внутренний параметр
#define internal1_m396_tx	 BUFFER[2883]	//(internal1_m396_tx) tx - внутренний параметр
#define idinternal1_m396_tx	 1003	//(internal1_m396_tx) tx - внутренний параметр
#define internal1_m395_tx	 BUFFER[2888]	//(internal1_m395_tx) tx - внутренний параметр
#define idinternal1_m395_tx	 1004	//(internal1_m395_tx) tx - внутренний параметр
#define internal1_m766_tx	 BUFFER[2893]	//(internal1_m766_tx) tx - внутренний параметр
#define idinternal1_m766_tx	 1005	//(internal1_m766_tx) tx - внутренний параметр
#define internal1_m761_tx	 BUFFER[2898]	//(internal1_m761_tx) tx - внутренний параметр
#define idinternal1_m761_tx	 1006	//(internal1_m761_tx) tx - внутренний параметр
#define internal1_m770_tx	 BUFFER[2903]	//(internal1_m770_tx) tx - внутренний параметр
#define idinternal1_m770_tx	 1007	//(internal1_m770_tx) tx - внутренний параметр
#define internal1_m775_tx	 BUFFER[2908]	//(internal1_m775_tx) tx - внутренний параметр
#define idinternal1_m775_tx	 1008	//(internal1_m775_tx) tx - внутренний параметр
#define internal1_m531_tx	 BUFFER[2913]	//(internal1_m531_tx) tx - внутренний параметр
#define idinternal1_m531_tx	 1009	//(internal1_m531_tx) tx - внутренний параметр
#define internal1_m530_tx	 BUFFER[2918]	//(internal1_m530_tx) tx - внутренний параметр
#define idinternal1_m530_tx	 1010	//(internal1_m530_tx) tx - внутренний параметр
#define internal1_m529_tx	 BUFFER[2923]	//(internal1_m529_tx) tx - внутренний параметр
#define idinternal1_m529_tx	 1011	//(internal1_m529_tx) tx - внутренний параметр
#define internal1_m525_tx	 BUFFER[2928]	//(internal1_m525_tx) tx - внутренний параметр
#define idinternal1_m525_tx	 1012	//(internal1_m525_tx) tx - внутренний параметр
#define internal1_m502_tx	 BUFFER[2933]	//(internal1_m502_tx) tx - внутренний параметр
#define idinternal1_m502_tx	 1013	//(internal1_m502_tx) tx - внутренний параметр
#define internal1_m501_tx	 BUFFER[2938]	//(internal1_m501_tx) tx - внутренний параметр
#define idinternal1_m501_tx	 1014	//(internal1_m501_tx) tx - внутренний параметр
#define internal1_m500_tx	 BUFFER[2943]	//(internal1_m500_tx) tx - внутренний параметр
#define idinternal1_m500_tx	 1015	//(internal1_m500_tx) tx - внутренний параметр
#define internal1_m503_tx	 BUFFER[2948]	//(internal1_m503_tx) tx - внутренний параметр
#define idinternal1_m503_tx	 1016	//(internal1_m503_tx) tx - внутренний параметр
#define internal1_m2472_tx	 BUFFER[2953]	//(internal1_m2472_tx) tx - внутренний параметр
#define idinternal1_m2472_tx	 1017	//(internal1_m2472_tx) tx - внутренний параметр
#define internal1_m2182_tx	 BUFFER[2958]	//(internal1_m2182_tx) tx - внутренний параметр
#define idinternal1_m2182_tx	 1018	//(internal1_m2182_tx) tx - внутренний параметр
#define internal1_m2471_tx	 BUFFER[2963]	//(internal1_m2471_tx) tx - внутренний параметр
#define idinternal1_m2471_tx	 1019	//(internal1_m2471_tx) tx - внутренний параметр
#define internal1_m2470_tx	 BUFFER[2968]	//(internal1_m2470_tx) tx - внутренний параметр
#define idinternal1_m2470_tx	 1020	//(internal1_m2470_tx) tx - внутренний параметр
#define internal1_m2467_tx	 BUFFER[2973]	//(internal1_m2467_tx) tx - внутренний параметр
#define idinternal1_m2467_tx	 1021	//(internal1_m2467_tx) tx - внутренний параметр
#define internal1_m108_tx	 BUFFER[2978]	//(internal1_m108_tx) tx - внутренний параметр
#define idinternal1_m108_tx	 1022	//(internal1_m108_tx) tx - внутренний параметр
#define internal1_m1148_tx	 BUFFER[2983]	//(internal1_m1148_tx) tx - внутренний параметр
#define idinternal1_m1148_tx	 1023	//(internal1_m1148_tx) tx - внутренний параметр
#define internal1_m2330_tx	 BUFFER[2988]	//(internal1_m2330_tx) tx - внутренний параметр
#define idinternal1_m2330_tx	 1024	//(internal1_m2330_tx) tx - внутренний параметр
#define internal1_m2329_tx	 BUFFER[2993]	//(internal1_m2329_tx) tx - внутренний параметр
#define idinternal1_m2329_tx	 1025	//(internal1_m2329_tx) tx - внутренний параметр
#define internal1_m2328_tx	 BUFFER[2998]	//(internal1_m2328_tx) tx - внутренний параметр
#define idinternal1_m2328_tx	 1026	//(internal1_m2328_tx) tx - внутренний параметр
#define internal1_m1260_tx	 BUFFER[3003]	//(internal1_m1260_tx) tx - внутренний параметр
#define idinternal1_m1260_tx	 1027	//(internal1_m1260_tx) tx - внутренний параметр
#define internal1_m1259_tx	 BUFFER[3008]	//(internal1_m1259_tx) tx - внутренний параметр
#define idinternal1_m1259_tx	 1028	//(internal1_m1259_tx) tx - внутренний параметр
#define internal1_m1255_tx	 BUFFER[3013]	//(internal1_m1255_tx) tx - внутренний параметр
#define idinternal1_m1255_tx	 1029	//(internal1_m1255_tx) tx - внутренний параметр
#define internal1_m1248_tx	 BUFFER[3018]	//(internal1_m1248_tx) tx - внутренний параметр
#define idinternal1_m1248_tx	 1030	//(internal1_m1248_tx) tx - внутренний параметр
#define internal1_m1246_tx	 BUFFER[3023]	//(internal1_m1246_tx) tx - внутренний параметр
#define idinternal1_m1246_tx	 1031	//(internal1_m1246_tx) tx - внутренний параметр
#define internal1_m1244_tx	 BUFFER[3028]	//(internal1_m1244_tx) tx - внутренний параметр
#define idinternal1_m1244_tx	 1032	//(internal1_m1244_tx) tx - внутренний параметр
#define internal1_m1242_tx	 BUFFER[3033]	//(internal1_m1242_tx) tx - внутренний параметр
#define idinternal1_m1242_tx	 1033	//(internal1_m1242_tx) tx - внутренний параметр
#define internal1_m1285_tx	 BUFFER[3038]	//(internal1_m1285_tx) tx - внутренний параметр
#define idinternal1_m1285_tx	 1034	//(internal1_m1285_tx) tx - внутренний параметр
#define internal1_m1292_tx	 BUFFER[3043]	//(internal1_m1292_tx) tx - внутренний параметр
#define idinternal1_m1292_tx	 1035	//(internal1_m1292_tx) tx - внутренний параметр
#define internal1_m1297_tx	 BUFFER[3048]	//(internal1_m1297_tx) tx - внутренний параметр
#define idinternal1_m1297_tx	 1036	//(internal1_m1297_tx) tx - внутренний параметр
#define internal1_m1303_tx	 BUFFER[3053]	//(internal1_m1303_tx) tx - внутренний параметр
#define idinternal1_m1303_tx	 1037	//(internal1_m1303_tx) tx - внутренний параметр
#define internal1_m1263_tx	 BUFFER[3058]	//(internal1_m1263_tx) tx - внутренний параметр
#define idinternal1_m1263_tx	 1038	//(internal1_m1263_tx) tx - внутренний параметр
#define internal1_m1284_tx	 BUFFER[3063]	//(internal1_m1284_tx) tx - внутренний параметр
#define idinternal1_m1284_tx	 1039	//(internal1_m1284_tx) tx - внутренний параметр
#define internal1_m1298_tx	 BUFFER[3068]	//(internal1_m1298_tx) tx - внутренний параметр
#define idinternal1_m1298_tx	 1040	//(internal1_m1298_tx) tx - внутренний параметр
#define internal1_m480_tx	 BUFFER[3073]	//(internal1_m480_tx) tx - внутренний параметр
#define idinternal1_m480_tx	 1041	//(internal1_m480_tx) tx - внутренний параметр
#define internal1_m474_tx	 BUFFER[3078]	//(internal1_m474_tx) tx - внутренний параметр
#define idinternal1_m474_tx	 1042	//(internal1_m474_tx) tx - внутренний параметр
#define internal1_m476_tx	 BUFFER[3083]	//(internal1_m476_tx) tx - внутренний параметр
#define idinternal1_m476_tx	 1043	//(internal1_m476_tx) tx - внутренний параметр
#define internal1_m478_tx	 BUFFER[3088]	//(internal1_m478_tx) tx - внутренний параметр
#define idinternal1_m478_tx	 1044	//(internal1_m478_tx) tx - внутренний параметр
#define internal1_m485_tx	 BUFFER[3093]	//(internal1_m485_tx) tx - внутренний параметр
#define idinternal1_m485_tx	 1045	//(internal1_m485_tx) tx - внутренний параметр
#define internal1_m439_tx	 BUFFER[3098]	//(internal1_m439_tx) tx - внутренний параметр
#define idinternal1_m439_tx	 1046	//(internal1_m439_tx) tx - внутренний параметр
#define internal1_m437_tx	 BUFFER[3103]	//(internal1_m437_tx) tx - внутренний параметр
#define idinternal1_m437_tx	 1047	//(internal1_m437_tx) tx - внутренний параметр
#define internal1_m438_tx	 BUFFER[3108]	//(internal1_m438_tx) tx - внутренний параметр
#define idinternal1_m438_tx	 1048	//(internal1_m438_tx) tx - внутренний параметр
#define internal1_m431_tx	 BUFFER[3113]	//(internal1_m431_tx) tx - внутренний параметр
#define idinternal1_m431_tx	 1049	//(internal1_m431_tx) tx - внутренний параметр
#define internal1_m893_tx	 BUFFER[3118]	//(internal1_m893_tx) tx - внутренний параметр
#define idinternal1_m893_tx	 1050	//(internal1_m893_tx) tx - внутренний параметр
#define internal1_m892_tx	 BUFFER[3123]	//(internal1_m892_tx) tx - внутренний параметр
#define idinternal1_m892_tx	 1051	//(internal1_m892_tx) tx - внутренний параметр
#define internal1_m891_tx	 BUFFER[3128]	//(internal1_m891_tx) tx - внутренний параметр
#define idinternal1_m891_tx	 1052	//(internal1_m891_tx) tx - внутренний параметр
#define internal1_m887_tx	 BUFFER[3133]	//(internal1_m887_tx) tx - внутренний параметр
#define idinternal1_m887_tx	 1053	//(internal1_m887_tx) tx - внутренний параметр
#define internal1_m1349_tx	 BUFFER[3138]	//(internal1_m1349_tx) tx - внутренний параметр
#define idinternal1_m1349_tx	 1054	//(internal1_m1349_tx) tx - внутренний параметр
#define internal1_m1348_tx	 BUFFER[3143]	//(internal1_m1348_tx) tx - внутренний параметр
#define idinternal1_m1348_tx	 1055	//(internal1_m1348_tx) tx - внутренний параметр
#define internal1_m1347_tx	 BUFFER[3148]	//(internal1_m1347_tx) tx - внутренний параметр
#define idinternal1_m1347_tx	 1056	//(internal1_m1347_tx) tx - внутренний параметр
#define internal1_m1560_tx	 BUFFER[3153]	//(internal1_m1560_tx) tx - внутренний параметр
#define idinternal1_m1560_tx	 1057	//(internal1_m1560_tx) tx - внутренний параметр
#define internal1_m1573_tx	 BUFFER[3158]	//(internal1_m1573_tx) tx - внутренний параметр
#define idinternal1_m1573_tx	 1058	//(internal1_m1573_tx) tx - внутренний параметр
#define internal1_m1572_tx	 BUFFER[3163]	//(internal1_m1572_tx) tx - внутренний параметр
#define idinternal1_m1572_tx	 1059	//(internal1_m1572_tx) tx - внутренний параметр
#define internal1_m1571_tx	 BUFFER[3168]	//(internal1_m1571_tx) tx - внутренний параметр
#define idinternal1_m1571_tx	 1060	//(internal1_m1571_tx) tx - внутренний параметр
#define internal1_m1562_tx	 BUFFER[3173]	//(internal1_m1562_tx) tx - внутренний параметр
#define idinternal1_m1562_tx	 1061	//(internal1_m1562_tx) tx - внутренний параметр
#define internal1_m2300_tx	 BUFFER[3178]	//(internal1_m2300_tx) tx - внутренний параметр
#define idinternal1_m2300_tx	 1062	//(internal1_m2300_tx) tx - внутренний параметр
#define internal1_m2283_tx	 BUFFER[3183]	//(internal1_m2283_tx) tx - внутренний параметр
#define idinternal1_m2283_tx	 1063	//(internal1_m2283_tx) tx - внутренний параметр
#define internal1_m2260_tx	 BUFFER[3188]	//(internal1_m2260_tx) tx - внутренний параметр
#define idinternal1_m2260_tx	 1064	//(internal1_m2260_tx) tx - внутренний параметр
#define internal1_m1570_tx	 BUFFER[3193]	//(internal1_m1570_tx) tx - внутренний параметр
#define idinternal1_m1570_tx	 1065	//(internal1_m1570_tx) tx - внутренний параметр
#define internal1_m1550_tx	 BUFFER[3198]	//(internal1_m1550_tx) tx - внутренний параметр
#define idinternal1_m1550_tx	 1066	//(internal1_m1550_tx) tx - внутренний параметр
#define internal1_m1549_tx	 BUFFER[3203]	//(internal1_m1549_tx) tx - внутренний параметр
#define idinternal1_m1549_tx	 1067	//(internal1_m1549_tx) tx - внутренний параметр
#define internal1_m1547_tx	 BUFFER[3208]	//(internal1_m1547_tx) tx - внутренний параметр
#define idinternal1_m1547_tx	 1068	//(internal1_m1547_tx) tx - внутренний параметр
#define internal1_m1569_tx	 BUFFER[3213]	//(internal1_m1569_tx) tx - внутренний параметр
#define idinternal1_m1569_tx	 1069	//(internal1_m1569_tx) tx - внутренний параметр
#define internal1_m1535_tx	 BUFFER[3218]	//(internal1_m1535_tx) tx - внутренний параметр
#define idinternal1_m1535_tx	 1070	//(internal1_m1535_tx) tx - внутренний параметр
#define internal1_m1537_tx	 BUFFER[3223]	//(internal1_m1537_tx) tx - внутренний параметр
#define idinternal1_m1537_tx	 1071	//(internal1_m1537_tx) tx - внутренний параметр
#define internal1_m1534_tx	 BUFFER[3228]	//(internal1_m1534_tx) tx - внутренний параметр
#define idinternal1_m1534_tx	 1072	//(internal1_m1534_tx) tx - внутренний параметр
#define internal1_m1507_tx	 BUFFER[3233]	//(internal1_m1507_tx) tx - внутренний параметр
#define idinternal1_m1507_tx	 1073	//(internal1_m1507_tx) tx - внутренний параметр
#define internal1_m1506_tx	 BUFFER[3238]	//(internal1_m1506_tx) tx - внутренний параметр
#define idinternal1_m1506_tx	 1074	//(internal1_m1506_tx) tx - внутренний параметр
#define internal1_m1516_tx	 BUFFER[3243]	//(internal1_m1516_tx) tx - внутренний параметр
#define idinternal1_m1516_tx	 1075	//(internal1_m1516_tx) tx - внутренний параметр
#define internal1_m1519_tx	 BUFFER[3248]	//(internal1_m1519_tx) tx - внутренний параметр
#define idinternal1_m1519_tx	 1076	//(internal1_m1519_tx) tx - внутренний параметр
#define internal1_m986_tx	 BUFFER[3253]	//(internal1_m986_tx) tx - внутренний параметр
#define idinternal1_m986_tx	 1077	//(internal1_m986_tx) tx - внутренний параметр
#define internal1_m989_tx	 BUFFER[3258]	//(internal1_m989_tx) tx - внутренний параметр
#define idinternal1_m989_tx	 1078	//(internal1_m989_tx) tx - внутренний параметр
#define internal1_m2251_tx	 BUFFER[3263]	//(internal1_m2251_tx) tx - внутренний параметр
#define idinternal1_m2251_tx	 1079	//(internal1_m2251_tx) tx - внутренний параметр
#define internal1_m979_tx	 BUFFER[3268]	//(internal1_m979_tx) tx - внутренний параметр
#define idinternal1_m979_tx	 1080	//(internal1_m979_tx) tx - внутренний параметр
#define internal1_m977_tx	 BUFFER[3273]	//(internal1_m977_tx) tx - внутренний параметр
#define idinternal1_m977_tx	 1081	//(internal1_m977_tx) tx - внутренний параметр
#define internal1_m985_tx	 BUFFER[3278]	//(internal1_m985_tx) tx - внутренний параметр
#define idinternal1_m985_tx	 1082	//(internal1_m985_tx) tx - внутренний параметр
#define internal1_m969_tx	 BUFFER[3283]	//(internal1_m969_tx) tx - внутренний параметр
#define idinternal1_m969_tx	 1083	//(internal1_m969_tx) tx - внутренний параметр
#define internal1_m967_tx	 BUFFER[3288]	//(internal1_m967_tx) tx - внутренний параметр
#define idinternal1_m967_tx	 1084	//(internal1_m967_tx) tx - внутренний параметр
#define internal1_m963_tx	 BUFFER[3293]	//(internal1_m963_tx) tx - внутренний параметр
#define idinternal1_m963_tx	 1085	//(internal1_m963_tx) tx - внутренний параметр
#define internal1_m984_tx	 BUFFER[3298]	//(internal1_m984_tx) tx - внутренний параметр
#define idinternal1_m984_tx	 1086	//(internal1_m984_tx) tx - внутренний параметр
#define internal1_m949_tx	 BUFFER[3303]	//(internal1_m949_tx) tx - внутренний параметр
#define idinternal1_m949_tx	 1087	//(internal1_m949_tx) tx - внутренний параметр
#define internal1_m950_tx	 BUFFER[3308]	//(internal1_m950_tx) tx - внутренний параметр
#define idinternal1_m950_tx	 1088	//(internal1_m950_tx) tx - внутренний параметр
#define internal1_m952_tx	 BUFFER[3313]	//(internal1_m952_tx) tx - внутренний параметр
#define idinternal1_m952_tx	 1089	//(internal1_m952_tx) tx - внутренний параметр
#define internal1_m637_tx	 BUFFER[3318]	//(internal1_m637_tx) tx - внутренний параметр
#define idinternal1_m637_tx	 1090	//(internal1_m637_tx) tx - внутренний параметр
#define internal1_m640_tx	 BUFFER[3323]	//(internal1_m640_tx) tx - внутренний параметр
#define idinternal1_m640_tx	 1091	//(internal1_m640_tx) tx - внутренний параметр
#define internal1_m639_tx	 BUFFER[3328]	//(internal1_m639_tx) tx - внутренний параметр
#define idinternal1_m639_tx	 1092	//(internal1_m639_tx) tx - внутренний параметр
#define internal1_m628_tx	 BUFFER[3333]	//(internal1_m628_tx) tx - внутренний параметр
#define idinternal1_m628_tx	 1093	//(internal1_m628_tx) tx - внутренний параметр
#define internal1_m626_tx	 BUFFER[3338]	//(internal1_m626_tx) tx - внутренний параметр
#define idinternal1_m626_tx	 1094	//(internal1_m626_tx) tx - внутренний параметр
#define internal1_m622_tx	 BUFFER[3343]	//(internal1_m622_tx) tx - внутренний параметр
#define idinternal1_m622_tx	 1095	//(internal1_m622_tx) tx - внутренний параметр
#define internal1_m635_tx	 BUFFER[3348]	//(internal1_m635_tx) tx - внутренний параметр
#define idinternal1_m635_tx	 1096	//(internal1_m635_tx) tx - внутренний параметр
#define internal1_m612_tx	 BUFFER[3353]	//(internal1_m612_tx) tx - внутренний параметр
#define idinternal1_m612_tx	 1097	//(internal1_m612_tx) tx - внутренний параметр
#define internal1_m611_tx	 BUFFER[3358]	//(internal1_m611_tx) tx - внутренний параметр
#define idinternal1_m611_tx	 1098	//(internal1_m611_tx) tx - внутренний параметр
#define internal1_m607_tx	 BUFFER[3363]	//(internal1_m607_tx) tx - внутренний параметр
#define idinternal1_m607_tx	 1099	//(internal1_m607_tx) tx - внутренний параметр
#define internal1_m638_tx	 BUFFER[3368]	//(internal1_m638_tx) tx - внутренний параметр
#define idinternal1_m638_tx	 1100	//(internal1_m638_tx) tx - внутренний параметр
#define internal1_m595_tx	 BUFFER[3373]	//(internal1_m595_tx) tx - внутренний параметр
#define idinternal1_m595_tx	 1101	//(internal1_m595_tx) tx - внутренний параметр
#define internal1_m594_tx	 BUFFER[3378]	//(internal1_m594_tx) tx - внутренний параметр
#define idinternal1_m594_tx	 1102	//(internal1_m594_tx) tx - внутренний параметр
#define internal1_m597_tx	 BUFFER[3383]	//(internal1_m597_tx) tx - внутренний параметр
#define idinternal1_m597_tx	 1103	//(internal1_m597_tx) tx - внутренний параметр
#define internal1_m574_tx	 BUFFER[3388]	//(internal1_m574_tx) tx - внутренний параметр
#define idinternal1_m574_tx	 1104	//(internal1_m574_tx) tx - внутренний параметр
#define internal1_m575_tx	 BUFFER[3393]	//(internal1_m575_tx) tx - внутренний параметр
#define idinternal1_m575_tx	 1105	//(internal1_m575_tx) tx - внутренний параметр
#define internal1_m576_tx	 BUFFER[3398]	//(internal1_m576_tx) tx - внутренний параметр
#define idinternal1_m576_tx	 1106	//(internal1_m576_tx) tx - внутренний параметр
#define internal1_m581_tx	 BUFFER[3403]	//(internal1_m581_tx) tx - внутренний параметр
#define idinternal1_m581_tx	 1107	//(internal1_m581_tx) tx - внутренний параметр
#define internal1_m2313_tx	 BUFFER[3408]	//(internal1_m2313_tx) tx - внутренний параметр
#define idinternal1_m2313_tx	 1108	//(internal1_m2313_tx) tx - внутренний параметр
#define internal1_m2314_tx	 BUFFER[3413]	//(internal1_m2314_tx) tx - внутренний параметр
#define idinternal1_m2314_tx	 1109	//(internal1_m2314_tx) tx - внутренний параметр
#define internal1_m2315_tx	 BUFFER[3418]	//(internal1_m2315_tx) tx - внутренний параметр
#define idinternal1_m2315_tx	 1110	//(internal1_m2315_tx) tx - внутренний параметр
#define internal1_m1792_tx	 BUFFER[3423]	//(internal1_m1792_tx) tx - внутренний параметр
#define idinternal1_m1792_tx	 1111	//(internal1_m1792_tx) tx - внутренний параметр
#define internal1_m1791_tx	 BUFFER[3428]	//(internal1_m1791_tx) tx - внутренний параметр
#define idinternal1_m1791_tx	 1112	//(internal1_m1791_tx) tx - внутренний параметр
#define internal1_m1786_tx	 BUFFER[3433]	//(internal1_m1786_tx) tx - внутренний параметр
#define idinternal1_m1786_tx	 1113	//(internal1_m1786_tx) tx - внутренний параметр
#define internal1_m1777_tx	 BUFFER[3438]	//(internal1_m1777_tx) tx - внутренний параметр
#define idinternal1_m1777_tx	 1114	//(internal1_m1777_tx) tx - внутренний параметр
#define internal1_m1775_tx	 BUFFER[3443]	//(internal1_m1775_tx) tx - внутренний параметр
#define idinternal1_m1775_tx	 1115	//(internal1_m1775_tx) tx - внутренний параметр
#define internal1_m1773_tx	 BUFFER[3448]	//(internal1_m1773_tx) tx - внутренний параметр
#define idinternal1_m1773_tx	 1116	//(internal1_m1773_tx) tx - внутренний параметр
#define internal1_m1772_tx	 BUFFER[3453]	//(internal1_m1772_tx) tx - внутренний параметр
#define idinternal1_m1772_tx	 1117	//(internal1_m1772_tx) tx - внутренний параметр
#define internal1_m1813_tx	 BUFFER[3458]	//(internal1_m1813_tx) tx - внутренний параметр
#define idinternal1_m1813_tx	 1118	//(internal1_m1813_tx) tx - внутренний параметр
#define internal1_m1821_tx	 BUFFER[3463]	//(internal1_m1821_tx) tx - внутренний параметр
#define idinternal1_m1821_tx	 1119	//(internal1_m1821_tx) tx - внутренний параметр
#define internal1_m1828_tx	 BUFFER[3468]	//(internal1_m1828_tx) tx - внутренний параметр
#define idinternal1_m1828_tx	 1120	//(internal1_m1828_tx) tx - внутренний параметр
#define internal1_m1829_tx	 BUFFER[3473]	//(internal1_m1829_tx) tx - внутренний параметр
#define idinternal1_m1829_tx	 1121	//(internal1_m1829_tx) tx - внутренний параметр
#define internal1_m1819_tx	 BUFFER[3478]	//(internal1_m1819_tx) tx - внутренний параметр
#define idinternal1_m1819_tx	 1122	//(internal1_m1819_tx) tx - внутренний параметр
#define internal1_m1794_tx	 BUFFER[3483]	//(internal1_m1794_tx) tx - внутренний параметр
#define idinternal1_m1794_tx	 1123	//(internal1_m1794_tx) tx - внутренний параметр
#define internal1_m1808_tx	 BUFFER[3488]	//(internal1_m1808_tx) tx - внутренний параметр
#define idinternal1_m1808_tx	 1124	//(internal1_m1808_tx) tx - внутренний параметр
#define internal1_m457_tx	 BUFFER[3493]	//(internal1_m457_tx) tx - внутренний параметр
#define idinternal1_m457_tx	 1125	//(internal1_m457_tx) tx - внутренний параметр
#define internal1_m448_tx	 BUFFER[3498]	//(internal1_m448_tx) tx - внутренний параметр
#define idinternal1_m448_tx	 1126	//(internal1_m448_tx) tx - внутренний параметр
#define internal1_m449_tx	 BUFFER[3503]	//(internal1_m449_tx) tx - внутренний параметр
#define idinternal1_m449_tx	 1127	//(internal1_m449_tx) tx - внутренний параметр
#define internal1_m451_tx	 BUFFER[3508]	//(internal1_m451_tx) tx - внутренний параметр
#define idinternal1_m451_tx	 1128	//(internal1_m451_tx) tx - внутренний параметр
#define internal1_m465_tx	 BUFFER[3513]	//(internal1_m465_tx) tx - внутренний параметр
#define idinternal1_m465_tx	 1129	//(internal1_m465_tx) tx - внутренний параметр
#define internal1_m415_tx	 BUFFER[3518]	//(internal1_m415_tx) tx - внутренний параметр
#define idinternal1_m415_tx	 1130	//(internal1_m415_tx) tx - внутренний параметр
#define internal1_m412_tx	 BUFFER[3523]	//(internal1_m412_tx) tx - внутренний параметр
#define idinternal1_m412_tx	 1131	//(internal1_m412_tx) tx - внутренний параметр
#define internal1_m411_tx	 BUFFER[3528]	//(internal1_m411_tx) tx - внутренний параметр
#define idinternal1_m411_tx	 1132	//(internal1_m411_tx) tx - внутренний параметр
#define internal1_m410_tx	 BUFFER[3533]	//(internal1_m410_tx) tx - внутренний параметр
#define idinternal1_m410_tx	 1133	//(internal1_m410_tx) tx - внутренний параметр
#define internal1_m870_tx	 BUFFER[3538]	//(internal1_m870_tx) tx - внутренний параметр
#define idinternal1_m870_tx	 1134	//(internal1_m870_tx) tx - внутренний параметр
#define internal1_m866_tx	 BUFFER[3543]	//(internal1_m866_tx) tx - внутренний параметр
#define idinternal1_m866_tx	 1135	//(internal1_m866_tx) tx - внутренний параметр
#define internal1_m865_tx	 BUFFER[3548]	//(internal1_m865_tx) tx - внутренний параметр
#define idinternal1_m865_tx	 1136	//(internal1_m865_tx) tx - внутренний параметр
#define internal1_m864_tx	 BUFFER[3553]	//(internal1_m864_tx) tx - внутренний параметр
#define idinternal1_m864_tx	 1137	//(internal1_m864_tx) tx - внутренний параметр
#define internal1_m1330_tx	 BUFFER[3558]	//(internal1_m1330_tx) tx - внутренний параметр
#define idinternal1_m1330_tx	 1138	//(internal1_m1330_tx) tx - внутренний параметр
#define internal1_m1327_tx	 BUFFER[3563]	//(internal1_m1327_tx) tx - внутренний параметр
#define idinternal1_m1327_tx	 1139	//(internal1_m1327_tx) tx - внутренний параметр
#define internal1_m1326_tx	 BUFFER[3568]	//(internal1_m1326_tx) tx - внутренний параметр
#define idinternal1_m1326_tx	 1140	//(internal1_m1326_tx) tx - внутренний параметр
#define internal1_m1087_tx	 BUFFER[3573]	//(internal1_m1087_tx) tx - внутренний параметр
#define idinternal1_m1087_tx	 1141	//(internal1_m1087_tx) tx - внутренний параметр
#define internal1_m2272_tx	 BUFFER[3578]	//(internal1_m2272_tx) tx - внутренний параметр
#define idinternal1_m2272_tx	 1142	//(internal1_m2272_tx) tx - внутренний параметр
#define internal1_m1098_tx	 BUFFER[3583]	//(internal1_m1098_tx) tx - внутренний параметр
#define idinternal1_m1098_tx	 1143	//(internal1_m1098_tx) tx - внутренний параметр
#define internal1_m1100_tx	 BUFFER[3588]	//(internal1_m1100_tx) tx - внутренний параметр
#define idinternal1_m1100_tx	 1144	//(internal1_m1100_tx) tx - внутренний параметр
#define internal1_m1099_tx	 BUFFER[3593]	//(internal1_m1099_tx) tx - внутренний параметр
#define idinternal1_m1099_tx	 1145	//(internal1_m1099_tx) tx - внутренний параметр
#define internal1_m2266_tx	 BUFFER[3598]	//(internal1_m2266_tx) tx - внутренний параметр
#define idinternal1_m2266_tx	 1146	//(internal1_m2266_tx) tx - внутренний параметр
#define internal1_m1089_tx	 BUFFER[3603]	//(internal1_m1089_tx) tx - внутренний параметр
#define idinternal1_m1089_tx	 1147	//(internal1_m1089_tx) tx - внутренний параметр
#define internal1_m2271_tx	 BUFFER[3608]	//(internal1_m2271_tx) tx - внутренний параметр
#define idinternal1_m2271_tx	 1148	//(internal1_m2271_tx) tx - внутренний параметр
#define internal1_m1097_tx	 BUFFER[3613]	//(internal1_m1097_tx) tx - внутренний параметр
#define idinternal1_m1097_tx	 1149	//(internal1_m1097_tx) tx - внутренний параметр
#define internal1_m1079_tx	 BUFFER[3618]	//(internal1_m1079_tx) tx - внутренний параметр
#define idinternal1_m1079_tx	 1150	//(internal1_m1079_tx) tx - внутренний параметр
#define internal1_m1078_tx	 BUFFER[3623]	//(internal1_m1078_tx) tx - внутренний параметр
#define idinternal1_m1078_tx	 1151	//(internal1_m1078_tx) tx - внутренний параметр
#define internal1_m1074_tx	 BUFFER[3628]	//(internal1_m1074_tx) tx - внутренний параметр
#define idinternal1_m1074_tx	 1152	//(internal1_m1074_tx) tx - внутренний параметр
#define internal1_m1096_tx	 BUFFER[3633]	//(internal1_m1096_tx) tx - внутренний параметр
#define idinternal1_m1096_tx	 1153	//(internal1_m1096_tx) tx - внутренний параметр
#define internal1_m1064_tx	 BUFFER[3638]	//(internal1_m1064_tx) tx - внутренний параметр
#define idinternal1_m1064_tx	 1154	//(internal1_m1064_tx) tx - внутренний параметр
#define internal1_m1062_tx	 BUFFER[3643]	//(internal1_m1062_tx) tx - внутренний параметр
#define idinternal1_m1062_tx	 1155	//(internal1_m1062_tx) tx - внутренний параметр
#define internal1_m1061_tx	 BUFFER[3648]	//(internal1_m1061_tx) tx - внутренний параметр
#define idinternal1_m1061_tx	 1156	//(internal1_m1061_tx) tx - внутренний параметр
#define internal1_m1040_tx	 BUFFER[3653]	//(internal1_m1040_tx) tx - внутренний параметр
#define idinternal1_m1040_tx	 1157	//(internal1_m1040_tx) tx - внутренний параметр
#define internal1_m1039_tx	 BUFFER[3658]	//(internal1_m1039_tx) tx - внутренний параметр
#define idinternal1_m1039_tx	 1158	//(internal1_m1039_tx) tx - внутренний параметр
#define internal1_m1029_tx	 BUFFER[3663]	//(internal1_m1029_tx) tx - внутренний параметр
#define idinternal1_m1029_tx	 1159	//(internal1_m1029_tx) tx - внутренний параметр
#define internal1_m1046_tx	 BUFFER[3668]	//(internal1_m1046_tx) tx - внутренний параметр
#define idinternal1_m1046_tx	 1160	//(internal1_m1046_tx) tx - внутренний параметр
#define internal1_m1465_tx	 BUFFER[3673]	//(internal1_m1465_tx) tx - внутренний параметр
#define idinternal1_m1465_tx	 1161	//(internal1_m1465_tx) tx - внутренний параметр
#define internal1_m1464_tx	 BUFFER[3678]	//(internal1_m1464_tx) tx - внутренний параметр
#define idinternal1_m1464_tx	 1162	//(internal1_m1464_tx) tx - внутренний параметр
#define internal1_m2218_tx	 BUFFER[3683]	//(internal1_m2218_tx) tx - внутренний параметр
#define idinternal1_m2218_tx	 1163	//(internal1_m2218_tx) tx - внутренний параметр
#define internal1_m1455_tx	 BUFFER[3688]	//(internal1_m1455_tx) tx - внутренний параметр
#define idinternal1_m1455_tx	 1164	//(internal1_m1455_tx) tx - внутренний параметр
#define internal1_m1456_tx	 BUFFER[3693]	//(internal1_m1456_tx) tx - внутренний параметр
#define idinternal1_m1456_tx	 1165	//(internal1_m1456_tx) tx - внутренний параметр
#define internal1_m1463_tx	 BUFFER[3698]	//(internal1_m1463_tx) tx - внутренний параметр
#define idinternal1_m1463_tx	 1166	//(internal1_m1463_tx) tx - внутренний параметр
#define internal1_m1446_tx	 BUFFER[3703]	//(internal1_m1446_tx) tx - внутренний параметр
#define idinternal1_m1446_tx	 1167	//(internal1_m1446_tx) tx - внутренний параметр
#define internal1_m1445_tx	 BUFFER[3708]	//(internal1_m1445_tx) tx - внутренний параметр
#define idinternal1_m1445_tx	 1168	//(internal1_m1445_tx) tx - внутренний параметр
#define internal1_m1441_tx	 BUFFER[3713]	//(internal1_m1441_tx) tx - внутренний параметр
#define idinternal1_m1441_tx	 1169	//(internal1_m1441_tx) tx - внутренний параметр
#define internal1_m1462_tx	 BUFFER[3718]	//(internal1_m1462_tx) tx - внутренний параметр
#define idinternal1_m1462_tx	 1170	//(internal1_m1462_tx) tx - внутренний параметр
#define internal1_m1428_tx	 BUFFER[3723]	//(internal1_m1428_tx) tx - внутренний параметр
#define idinternal1_m1428_tx	 1171	//(internal1_m1428_tx) tx - внутренний параметр
#define internal1_m1426_tx	 BUFFER[3728]	//(internal1_m1426_tx) tx - внутренний параметр
#define idinternal1_m1426_tx	 1172	//(internal1_m1426_tx) tx - внутренний параметр
#define internal1_m1435_tx	 BUFFER[3733]	//(internal1_m1435_tx) tx - внутренний параметр
#define idinternal1_m1435_tx	 1173	//(internal1_m1435_tx) tx - внутренний параметр
#define internal1_m255_tx	 BUFFER[3738]	//(internal1_m255_tx) tx - внутренний параметр
#define idinternal1_m255_tx	 1174	//(internal1_m255_tx) tx - внутренний параметр
#define internal1_m270_tx	 BUFFER[3743]	//(internal1_m270_tx) tx - внутренний параметр
#define idinternal1_m270_tx	 1175	//(internal1_m270_tx) tx - внутренний параметр
#define internal1_m278_tx	 BUFFER[3748]	//(internal1_m278_tx) tx - внутренний параметр
#define idinternal1_m278_tx	 1176	//(internal1_m278_tx) tx - внутренний параметр
#define internal1_m277_tx	 BUFFER[3753]	//(internal1_m277_tx) tx - внутренний параметр
#define idinternal1_m277_tx	 1177	//(internal1_m277_tx) tx - внутренний параметр
#define internal1_m261_tx	 BUFFER[3758]	//(internal1_m261_tx) tx - внутренний параметр
#define idinternal1_m261_tx	 1178	//(internal1_m261_tx) tx - внутренний параметр
#define internal1_m258_tx	 BUFFER[3763]	//(internal1_m258_tx) tx - внутренний параметр
#define idinternal1_m258_tx	 1179	//(internal1_m258_tx) tx - внутренний параметр
#define internal1_m274_tx	 BUFFER[3768]	//(internal1_m274_tx) tx - внутренний параметр
#define idinternal1_m274_tx	 1180	//(internal1_m274_tx) tx - внутренний параметр
#define internal1_m246_tx	 BUFFER[3773]	//(internal1_m246_tx) tx - внутренний параметр
#define idinternal1_m246_tx	 1181	//(internal1_m246_tx) tx - внутренний параметр
#define internal1_m245_tx	 BUFFER[3778]	//(internal1_m245_tx) tx - внутренний параметр
#define idinternal1_m245_tx	 1182	//(internal1_m245_tx) tx - внутренний параметр
#define internal1_m241_tx	 BUFFER[3783]	//(internal1_m241_tx) tx - внутренний параметр
#define idinternal1_m241_tx	 1183	//(internal1_m241_tx) tx - внутренний параметр
#define internal1_m273_tx	 BUFFER[3788]	//(internal1_m273_tx) tx - внутренний параметр
#define idinternal1_m273_tx	 1184	//(internal1_m273_tx) tx - внутренний параметр
#define internal1_m230_tx	 BUFFER[3793]	//(internal1_m230_tx) tx - внутренний параметр
#define idinternal1_m230_tx	 1185	//(internal1_m230_tx) tx - внутренний параметр
#define internal1_m232_tx	 BUFFER[3798]	//(internal1_m232_tx) tx - внутренний параметр
#define idinternal1_m232_tx	 1186	//(internal1_m232_tx) tx - внутренний параметр
#define internal1_m228_tx	 BUFFER[3803]	//(internal1_m228_tx) tx - внутренний параметр
#define idinternal1_m228_tx	 1187	//(internal1_m228_tx) tx - внутренний параметр
#define internal1_m204_tx	 BUFFER[3808]	//(internal1_m204_tx) tx - внутренний параметр
#define idinternal1_m204_tx	 1188	//(internal1_m204_tx) tx - внутренний параметр
#define internal1_m203_tx	 BUFFER[3813]	//(internal1_m203_tx) tx - внутренний параметр
#define idinternal1_m203_tx	 1189	//(internal1_m203_tx) tx - внутренний параметр
#define internal1_m202_tx	 BUFFER[3818]	//(internal1_m202_tx) tx - внутренний параметр
#define idinternal1_m202_tx	 1190	//(internal1_m202_tx) tx - внутренний параметр
#define internal1_m210_tx	 BUFFER[3823]	//(internal1_m210_tx) tx - внутренний параметр
#define idinternal1_m210_tx	 1191	//(internal1_m210_tx) tx - внутренний параметр
#define internal1_m1408_tx	 BUFFER[3828]	//(internal1_m1408_tx) tx - внутренний параметр
#define idinternal1_m1408_tx	 1192	//(internal1_m1408_tx) tx - внутренний параметр
#define internal1_m1390_tx	 BUFFER[3833]	//(internal1_m1390_tx) tx - внутренний параметр
#define idinternal1_m1390_tx	 1193	//(internal1_m1390_tx) tx - внутренний параметр
#define internal1_m1393_tx	 BUFFER[3838]	//(internal1_m1393_tx) tx - внутренний параметр
#define idinternal1_m1393_tx	 1194	//(internal1_m1393_tx) tx - внутренний параметр
#define internal1_m1412_tx	 BUFFER[3843]	//(internal1_m1412_tx) tx - внутренний параметр
#define idinternal1_m1412_tx	 1195	//(internal1_m1412_tx) tx - внутренний параметр
#define internal1_m929_tx	 BUFFER[3848]	//(internal1_m929_tx) tx - внутренний параметр
#define idinternal1_m929_tx	 1196	//(internal1_m929_tx) tx - внутренний параметр
#define internal1_m934_tx	 BUFFER[3853]	//(internal1_m934_tx) tx - внутренний параметр
#define idinternal1_m934_tx	 1197	//(internal1_m934_tx) tx - внутренний параметр
#define internal1_m924_tx	 BUFFER[3858]	//(internal1_m924_tx) tx - внутренний параметр
#define idinternal1_m924_tx	 1198	//(internal1_m924_tx) tx - внутренний параметр
#define internal1_m925_tx	 BUFFER[3863]	//(internal1_m925_tx) tx - внутренний параметр
#define idinternal1_m925_tx	 1199	//(internal1_m925_tx) tx - внутренний параметр
#define internal1_m1913_q0	 BUFFER[3868]	//(internal1_m1913_q0) q0 - внутренний параметр
#define idinternal1_m1913_q0	 1200	//(internal1_m1913_q0) q0 - внутренний параметр
#define internal1_m2355_q0	 BUFFER[3870]	//(internal1_m2355_q0) q0 - внутренний параметр
#define idinternal1_m2355_q0	 1201	//(internal1_m2355_q0) q0 - внутренний параметр
#define internal1_m2339_q0	 BUFFER[3872]	//(internal1_m2339_q0) q0 - внутренний параметр
#define idinternal1_m2339_q0	 1202	//(internal1_m2339_q0) q0 - внутренний параметр
#define internal1_m2386_q0	 BUFFER[3874]	//(internal1_m2386_q0) q0 - внутренний параметр
#define idinternal1_m2386_q0	 1203	//(internal1_m2386_q0) q0 - внутренний параметр
#define internal1_m2370_q0	 BUFFER[3876]	//(internal1_m2370_q0) q0 - внутренний параметр
#define idinternal1_m2370_q0	 1204	//(internal1_m2370_q0) q0 - внутренний параметр
#define internal1_m2361_q0	 BUFFER[3878]	//(internal1_m2361_q0) q0 - внутренний параметр
#define idinternal1_m2361_q0	 1205	//(internal1_m2361_q0) q0 - внутренний параметр
#define internal1_m2342_q0	 BUFFER[3880]	//(internal1_m2342_q0) q0 - внутренний параметр
#define idinternal1_m2342_q0	 1206	//(internal1_m2342_q0) q0 - внутренний параметр
#define internal1_m2359_q0	 BUFFER[3882]	//(internal1_m2359_q0) q0 - внутренний параметр
#define idinternal1_m2359_q0	 1207	//(internal1_m2359_q0) q0 - внутренний параметр
#define internal1_m2340_q0	 BUFFER[3884]	//(internal1_m2340_q0) q0 - внутренний параметр
#define idinternal1_m2340_q0	 1208	//(internal1_m2340_q0) q0 - внутренний параметр
#define internal1_m2338_q0	 BUFFER[3886]	//(internal1_m2338_q0) q0 - внутренний параметр
#define idinternal1_m2338_q0	 1209	//(internal1_m2338_q0) q0 - внутренний параметр
#define internal1_m2337_q0	 BUFFER[3888]	//(internal1_m2337_q0) q0 - внутренний параметр
#define idinternal1_m2337_q0	 1210	//(internal1_m2337_q0) q0 - внутренний параметр
#define internal1_m2351_q0	 BUFFER[3890]	//(internal1_m2351_q0) q0 - внутренний параметр
#define idinternal1_m2351_q0	 1211	//(internal1_m2351_q0) q0 - внутренний параметр
#define internal1_m2349_q0	 BUFFER[3892]	//(internal1_m2349_q0) q0 - внутренний параметр
#define idinternal1_m2349_q0	 1212	//(internal1_m2349_q0) q0 - внутренний параметр
#define internal1_m2357_q0	 BUFFER[3894]	//(internal1_m2357_q0) q0 - внутренний параметр
#define idinternal1_m2357_q0	 1213	//(internal1_m2357_q0) q0 - внутренний параметр
#define internal1_m2353_q0	 BUFFER[3896]	//(internal1_m2353_q0) q0 - внутренний параметр
#define idinternal1_m2353_q0	 1214	//(internal1_m2353_q0) q0 - внутренний параметр
#define internal1_m2392_q0	 BUFFER[3898]	//(internal1_m2392_q0) q0 - внутренний параметр
#define idinternal1_m2392_q0	 1215	//(internal1_m2392_q0) q0 - внутренний параметр
#define internal1_m2373_q0	 BUFFER[3900]	//(internal1_m2373_q0) q0 - внутренний параметр
#define idinternal1_m2373_q0	 1216	//(internal1_m2373_q0) q0 - внутренний параметр
#define internal1_m2390_q0	 BUFFER[3902]	//(internal1_m2390_q0) q0 - внутренний параметр
#define idinternal1_m2390_q0	 1217	//(internal1_m2390_q0) q0 - внутренний параметр
#define internal1_m2372_q0	 BUFFER[3904]	//(internal1_m2372_q0) q0 - внутренний параметр
#define idinternal1_m2372_q0	 1218	//(internal1_m2372_q0) q0 - внутренний параметр
#define internal1_m2369_q0	 BUFFER[3906]	//(internal1_m2369_q0) q0 - внутренний параметр
#define idinternal1_m2369_q0	 1219	//(internal1_m2369_q0) q0 - внутренний параметр
#define internal1_m2368_q0	 BUFFER[3908]	//(internal1_m2368_q0) q0 - внутренний параметр
#define idinternal1_m2368_q0	 1220	//(internal1_m2368_q0) q0 - внутренний параметр
#define internal1_m2382_q0	 BUFFER[3910]	//(internal1_m2382_q0) q0 - внутренний параметр
#define idinternal1_m2382_q0	 1221	//(internal1_m2382_q0) q0 - внутренний параметр
#define internal1_m2380_q0	 BUFFER[3912]	//(internal1_m2380_q0) q0 - внутренний параметр
#define idinternal1_m2380_q0	 1222	//(internal1_m2380_q0) q0 - внутренний параметр
#define internal1_m2243_tx	 BUFFER[3914]	//(internal1_m2243_tx) tx - внутренний параметр
#define idinternal1_m2243_tx	 1223	//(internal1_m2243_tx) tx - внутренний параметр
#define internal1_m2222_tx	 BUFFER[3919]	//(internal1_m2222_tx) tx - внутренний параметр
#define idinternal1_m2222_tx	 1224	//(internal1_m2222_tx) tx - внутренний параметр
#define internal1_m1937_Pv0	 BUFFER[3924]	//(internal1_m1937_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1937_Pv0	 1225	//(internal1_m1937_Pv0)  - Пер. выключатель механизма
#define internal1_m1937_Zv0	 BUFFER[3926]	//(internal1_m1937_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1937_Zv0	 1226	//(internal1_m1937_Zv0)  - Зад. выключатель механизма
#define internal1_m1937_MyFirstEnterFlag	 BUFFER[3928]	//(internal1_m1937_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1937_MyFirstEnterFlag	 1227	//(internal1_m1937_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m1934_Pv0	 BUFFER[3930]	//(internal1_m1934_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1934_Pv0	 1228	//(internal1_m1934_Pv0)  - Пер. выключатель механизма
#define internal1_m1934_Zv0	 BUFFER[3932]	//(internal1_m1934_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1934_Zv0	 1229	//(internal1_m1934_Zv0)  - Зад. выключатель механизма
#define internal1_m1934_MyFirstEnterFlag	 BUFFER[3934]	//(internal1_m1934_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1934_MyFirstEnterFlag	 1230	//(internal1_m1934_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m2410_tx	 BUFFER[3936]	//(internal1_m2410_tx) tx - время накопленное сек
#define idinternal1_m2410_tx	 1231	//(internal1_m2410_tx) tx - время накопленное сек
#define internal1_m2410_y0	 BUFFER[3941]	//(internal1_m2410_y0) y0
#define idinternal1_m2410_y0	 1232	//(internal1_m2410_y0) y0
#define internal1_m2414_tx	 BUFFER[3942]	//(internal1_m2414_tx) tx - время накопленное сек
#define idinternal1_m2414_tx	 1233	//(internal1_m2414_tx) tx - время накопленное сек
#define internal1_m2414_y0	 BUFFER[3947]	//(internal1_m2414_y0) y0
#define idinternal1_m2414_y0	 1234	//(internal1_m2414_y0) y0
#define internal1_m2413_tx	 BUFFER[3948]	//(internal1_m2413_tx) tx - время накопленное сек
#define idinternal1_m2413_tx	 1235	//(internal1_m2413_tx) tx - время накопленное сек
#define internal1_m2413_y0	 BUFFER[3953]	//(internal1_m2413_y0) y0
#define idinternal1_m2413_y0	 1236	//(internal1_m2413_y0) y0
#define internal1_m2450_tx	 BUFFER[3954]	//(internal1_m2450_tx) tx - внутренний параметр
#define idinternal1_m2450_tx	 1237	//(internal1_m2450_tx) tx - внутренний параметр
#define internal1_m2448_tx	 BUFFER[3959]	//(internal1_m2448_tx) tx - время накопленное сек
#define idinternal1_m2448_tx	 1238	//(internal1_m2448_tx) tx - время накопленное сек
#define internal1_m2448_y0	 BUFFER[3964]	//(internal1_m2448_y0) y0
#define idinternal1_m2448_y0	 1239	//(internal1_m2448_y0) y0
#define internal1_m2453_q0	 BUFFER[3965]	//(internal1_m2453_q0) q0 - внутренний параметр
#define idinternal1_m2453_q0	 1240	//(internal1_m2453_q0) q0 - внутренний параметр
#define internal1_m2420_q0	 BUFFER[3967]	//(internal1_m2420_q0) q0 - внутренний параметр
#define idinternal1_m2420_q0	 1241	//(internal1_m2420_q0) q0 - внутренний параметр
#define internal1_m2428_tx	 BUFFER[3969]	//(internal1_m2428_tx) tx - внутренний параметр
#define idinternal1_m2428_tx	 1242	//(internal1_m2428_tx) tx - внутренний параметр
#define internal1_m2426_q0	 BUFFER[3974]	//(internal1_m2426_q0) q0 - внутренний параметр
#define idinternal1_m2426_q0	 1243	//(internal1_m2426_q0) q0 - внутренний параметр
#define internal1_m2408_fVf0	 BUFFER[3976]	//(internal1_m2408_fVf0)  - скорость изменения мощности 
#define idinternal1_m2408_fVf0	 1244	//(internal1_m2408_fVf0)  - скорость изменения мощности 
#define internal1_m2408_fRsg	 BUFFER[3981]	//(internal1_m2408_fRsg)  - рассогласование между текущей и заданной мощностью 
#define idinternal1_m2408_fRsg	 1245	//(internal1_m2408_fRsg)  - рассогласование между текущей и заданной мощностью 
#define internal1_m2408_fRct	 BUFFER[3986]	//(internal1_m2408_fRct)  - стартовая реактивность регулятора 
#define idinternal1_m2408_fRct	 1246	//(internal1_m2408_fRct)  - стартовая реактивность регулятора 
#define internal1_m2408_fVfMin	 BUFFER[3991]	//(internal1_m2408_fVfMin)  - минимальная скорость 
#define idinternal1_m2408_fVfMin	 1247	//(internal1_m2408_fVfMin)  - минимальная скорость 
#define internal1_m2408_fStw0	 BUFFER[3996]	//(internal1_m2408_fStw0)  - значение стартовой мощности включения ИМ 
#define idinternal1_m2408_fStw0	 1248	//(internal1_m2408_fStw0)  - значение стартовой мощности включения ИМ 
#define internal1_m2408_fMaxDk	 BUFFER[4001]	//(internal1_m2408_fMaxDk)  - изменение координаты при смене задания 
#define idinternal1_m2408_fMaxDk	 1249	//(internal1_m2408_fMaxDk)  - изменение координаты при смене задания 
#define internal1_m2408_fkizm	 BUFFER[4006]	//(internal1_m2408_fkizm)  - стартовая координата положения ИМ 0-й реактивности 
#define idinternal1_m2408_fkizm	 1250	//(internal1_m2408_fkizm)  - стартовая координата положения ИМ 0-й реактивности 
#define internal1_m2408_fwt0	 BUFFER[4011]	//(internal1_m2408_fwt0)  - мощность на предыдущем шаге 
#define idinternal1_m2408_fwt0	 1251	//(internal1_m2408_fwt0)  - мощность на предыдущем шаге 
#define internal1_m2408_fwz0	 BUFFER[4016]	//(internal1_m2408_fwz0)  - заданная мощность на предыдущем шаге 
#define idinternal1_m2408_fwz0	 1252	//(internal1_m2408_fwz0)  - заданная мощность на предыдущем шаге 
#define internal1_m2408_ftf0	 BUFFER[4021]	//(internal1_m2408_ftf0)  - время от фиксации предыдущей мощности 
#define idinternal1_m2408_ftf0	 1253	//(internal1_m2408_ftf0)  - время от фиксации предыдущей мощности 
#define internal1_m2408_fTk0	 BUFFER[4026]	//(internal1_m2408_fTk0)  - последняя температура 
#define idinternal1_m2408_fTk0	 1254	//(internal1_m2408_fTk0)  - последняя температура 
#define internal1_m2408_FlPar	 BUFFER[4031]	//(internal1_m2408_FlPar) - стартовый этап регулирования
#define idinternal1_m2408_FlPar	 1255	//(internal1_m2408_FlPar) - стартовый этап регулирования
#define internal1_m2408_FlIzm	 BUFFER[4034]	//(internal1_m2408_FlIzm) - флаг изменения направления изменения мощности
#define idinternal1_m2408_FlIzm	 1256	//(internal1_m2408_FlIzm) - флаг изменения направления изменения мощности
#define internal1_m2408_FlCmp	 BUFFER[4037]	//(internal1_m2408_FlCmp) - текущее направление изменения мощности
#define idinternal1_m2408_FlCmp	 1257	//(internal1_m2408_FlCmp) - текущее направление изменения мощности
#define internal1_m2408_StabCoun	 BUFFER[4040]	//(internal1_m2408_StabCoun) - счётчик стабильности
#define idinternal1_m2408_StabCoun	 1258	//(internal1_m2408_StabCoun) - счётчик стабильности
#define internal1_m2408_ZerCoun	 BUFFER[4043]	//(internal1_m2408_ZerCoun) - счётчик полной остановки
#define idinternal1_m2408_ZerCoun	 1259	//(internal1_m2408_ZerCoun) - счётчик полной остановки
#define internal1_m2408_SrCoun	 BUFFER[4046]	//(internal1_m2408_SrCoun)  - счётчик усреднения
#define idinternal1_m2408_SrCoun	 1260	//(internal1_m2408_SrCoun)  - счётчик усреднения
#define internal1_m2408_LastStage	 BUFFER[4049]	//(internal1_m2408_LastStage)  - последний этап
#define idinternal1_m2408_LastStage	 1261	//(internal1_m2408_LastStage)  - последний этап
#define internal1_m2408_fef	 BUFFER[4052]	//(internal1_m2408_fef)  - первый вход
#define idinternal1_m2408_fef	 1262	//(internal1_m2408_fef)  - первый вход
#define internal1_m2237_tx	 BUFFER[4054]	//(internal1_m2237_tx) tx - время накопленное сек
#define idinternal1_m2237_tx	 1263	//(internal1_m2237_tx) tx - время накопленное сек
#define internal1_m2237_y0	 BUFFER[4059]	//(internal1_m2237_y0) y0
#define idinternal1_m2237_y0	 1264	//(internal1_m2237_y0) y0
#define internal1_m2229_tx	 BUFFER[4060]	//(internal1_m2229_tx) tx - время накопленное сек
#define idinternal1_m2229_tx	 1265	//(internal1_m2229_tx) tx - время накопленное сек
#define internal1_m2229_y0	 BUFFER[4065]	//(internal1_m2229_y0) y0
#define idinternal1_m2229_y0	 1266	//(internal1_m2229_y0) y0
#define internal1_m1923_q0	 BUFFER[4066]	//(internal1_m1923_q0) q0 - внутренний параметр
#define idinternal1_m1923_q0	 1267	//(internal1_m1923_q0) q0 - внутренний параметр
#define internal1_m1928_q0	 BUFFER[4068]	//(internal1_m1928_q0) q0 - внутренний параметр
#define idinternal1_m1928_q0	 1268	//(internal1_m1928_q0) q0 - внутренний параметр
#define internal1_m1920_q0	 BUFFER[4070]	//(internal1_m1920_q0) q0 - внутренний параметр
#define idinternal1_m1920_q0	 1269	//(internal1_m1920_q0) q0 - внутренний параметр
#define internal1_m1962_q0	 BUFFER[4072]	//(internal1_m1962_q0) q0 - внутренний параметр
#define idinternal1_m1962_q0	 1270	//(internal1_m1962_q0) q0 - внутренний параметр
#define internal1_m834_tx	 BUFFER[4074]	//(internal1_m834_tx) tx - время накопленное сек
#define idinternal1_m834_tx	 1271	//(internal1_m834_tx) tx - время накопленное сек
#define internal1_m834_y0	 BUFFER[4079]	//(internal1_m834_y0) y0
#define idinternal1_m834_y0	 1272	//(internal1_m834_y0) y0
#define internal1_m2233_tx	 BUFFER[4080]	//(internal1_m2233_tx) tx - внутренний параметр
#define idinternal1_m2233_tx	 1273	//(internal1_m2233_tx) tx - внутренний параметр
#define internal1_m2236_q0	 BUFFER[4085]	//(internal1_m2236_q0) q0 - внутренний параметр
#define idinternal1_m2236_q0	 1274	//(internal1_m2236_q0) q0 - внутренний параметр
#define internal1_m2228_q0	 BUFFER[4087]	//(internal1_m2228_q0) q0 - внутренний параметр
#define idinternal1_m2228_q0	 1275	//(internal1_m2228_q0) q0 - внутренний параметр
#define internal1_m2197_tx	 BUFFER[4089]	//(internal1_m2197_tx) tx - внутренний параметр
#define idinternal1_m2197_tx	 1276	//(internal1_m2197_tx) tx - внутренний параметр
#define internal1_m2208_tx	 BUFFER[4094]	//(internal1_m2208_tx) tx - внутренний параметр
#define idinternal1_m2208_tx	 1277	//(internal1_m2208_tx) tx - внутренний параметр
#define internal1_m2194_tx	 BUFFER[4099]	//(internal1_m2194_tx) tx - внутренний параметр
#define idinternal1_m2194_tx	 1278	//(internal1_m2194_tx) tx - внутренний параметр
#define internal1_m2200_q0	 BUFFER[4104]	//(internal1_m2200_q0) q0 - внутренний параметр
#define idinternal1_m2200_q0	 1279	//(internal1_m2200_q0) q0 - внутренний параметр
#define internal1_m2212_q0	 BUFFER[4106]	//(internal1_m2212_q0) q0 - внутренний параметр
#define idinternal1_m2212_q0	 1280	//(internal1_m2212_q0) q0 - внутренний параметр
#define internal1_m2169_tx	 BUFFER[4108]	//(internal1_m2169_tx) tx - внутренний параметр
#define idinternal1_m2169_tx	 1281	//(internal1_m2169_tx) tx - внутренний параметр
#define internal1_m52_tx	 BUFFER[4113]	//(internal1_m52_tx) tx - внутренний параметр
#define idinternal1_m52_tx	 1282	//(internal1_m52_tx) tx - внутренний параметр
#define internal1_m368_tx	 BUFFER[4118]	//(internal1_m368_tx) tx - внутренний параметр
#define idinternal1_m368_tx	 1283	//(internal1_m368_tx) tx - внутренний параметр
#define internal1_m322_tx	 BUFFER[4123]	//(internal1_m322_tx) tx - внутренний параметр
#define idinternal1_m322_tx	 1284	//(internal1_m322_tx) tx - внутренний параметр
#define internal1_m835_tx	 BUFFER[4128]	//(internal1_m835_tx) tx - внутренний параметр
#define idinternal1_m835_tx	 1285	//(internal1_m835_tx) tx - внутренний параметр
#define internal1_m1627_tx	 BUFFER[4133]	//(internal1_m1627_tx) tx - внутренний параметр
#define idinternal1_m1627_tx	 1286	//(internal1_m1627_tx) tx - внутренний параметр
#define internal1_m120_tx	 BUFFER[4138]	//(internal1_m120_tx) tx - внутренний параметр
#define idinternal1_m120_tx	 1287	//(internal1_m120_tx) tx - внутренний параметр
#define internal1_m122_tx	 BUFFER[4143]	//(internal1_m122_tx) tx - внутренний параметр
#define idinternal1_m122_tx	 1288	//(internal1_m122_tx) tx - внутренний параметр
#define internal1_m127_tx	 BUFFER[4148]	//(internal1_m127_tx) tx - внутренний параметр
#define idinternal1_m127_tx	 1289	//(internal1_m127_tx) tx - внутренний параметр
#define internal1_m21_tx	 BUFFER[4153]	//(internal1_m21_tx) tx - внутренний параметр
#define idinternal1_m21_tx	 1290	//(internal1_m21_tx) tx - внутренний параметр
#define internal1_m13_tx	 BUFFER[4158]	//(internal1_m13_tx) tx - внутренний параметр
#define idinternal1_m13_tx	 1291	//(internal1_m13_tx) tx - внутренний параметр
#define internal1_m2179_tx	 BUFFER[4163]	//(internal1_m2179_tx) tx - внутренний параметр
#define idinternal1_m2179_tx	 1292	//(internal1_m2179_tx) tx - внутренний параметр
#define internal1_m2166_tx	 BUFFER[4168]	//(internal1_m2166_tx) tx - внутренний параметр
#define idinternal1_m2166_tx	 1293	//(internal1_m2166_tx) tx - внутренний параметр
#define internal1_m2284_tx	 BUFFER[4173]	//(internal1_m2284_tx) tx - внутренний параметр
#define idinternal1_m2284_tx	 1294	//(internal1_m2284_tx) tx - внутренний параметр
#define internal1_m2286_tx	 BUFFER[4178]	//(internal1_m2286_tx) tx - внутренний параметр
#define idinternal1_m2286_tx	 1295	//(internal1_m2286_tx) tx - внутренний параметр
#define internal1_m82_tx	 BUFFER[4183]	//(internal1_m82_tx) tx - внутренний параметр
#define idinternal1_m82_tx	 1296	//(internal1_m82_tx) tx - внутренний параметр
#define internal1_m339_tx	 BUFFER[4188]	//(internal1_m339_tx) tx - время накопленное сек
#define idinternal1_m339_tx	 1297	//(internal1_m339_tx) tx - время накопленное сек
#define internal1_m339_y0	 BUFFER[4193]	//(internal1_m339_y0) y0
#define idinternal1_m339_y0	 1298	//(internal1_m339_y0) y0
#define internal1_m2077_tx	 BUFFER[4194]	//(internal1_m2077_tx) tx - время накопленное сек
#define idinternal1_m2077_tx	 1299	//(internal1_m2077_tx) tx - время накопленное сек
#define internal1_m2077_y0	 BUFFER[4199]	//(internal1_m2077_y0) y0
#define idinternal1_m2077_y0	 1300	//(internal1_m2077_y0) y0
#define internal1_m2091_q0	 BUFFER[4200]	//(internal1_m2091_q0) q0 - внутренний параметр
#define idinternal1_m2091_q0	 1301	//(internal1_m2091_q0) q0 - внутренний параметр
#define internal1_m1648_q0	 BUFFER[4205]	//(internal1_m1648_q0) q0 - внутренний параметр
#define idinternal1_m1648_q0	 1302	//(internal1_m1648_q0) q0 - внутренний параметр
#define internal1_m1686_q0	 BUFFER[4210]	//(internal1_m1686_q0) q0 - внутренний параметр
#define idinternal1_m1686_q0	 1303	//(internal1_m1686_q0) q0 - внутренний параметр
#define internal1_m1689_q0	 BUFFER[4215]	//(internal1_m1689_q0) q0 - внутренний параметр
#define idinternal1_m1689_q0	 1304	//(internal1_m1689_q0) q0 - внутренний параметр
#define internal1_m2131_q0	 BUFFER[4220]	//(internal1_m2131_q0) q0 - внутренний параметр
#define idinternal1_m2131_q0	 1305	//(internal1_m2131_q0) q0 - внутренний параметр
#define internal1_m2109_tx	 BUFFER[4225]	//(internal1_m2109_tx) tx - время накопленное сек
#define idinternal1_m2109_tx	 1306	//(internal1_m2109_tx) tx - время накопленное сек
#define internal1_m2109_y0	 BUFFER[4230]	//(internal1_m2109_y0) y0
#define idinternal1_m2109_y0	 1307	//(internal1_m2109_y0) y0
#define internal1_m2124_tx	 BUFFER[4231]	//(internal1_m2124_tx) tx - время накопленное сек
#define idinternal1_m2124_tx	 1308	//(internal1_m2124_tx) tx - время накопленное сек
#define internal1_m2124_y0	 BUFFER[4236]	//(internal1_m2124_y0) y0
#define idinternal1_m2124_y0	 1309	//(internal1_m2124_y0) y0
#define internal1_m2121_tx	 BUFFER[4237]	//(internal1_m2121_tx) tx - время накопленное сек
#define idinternal1_m2121_tx	 1310	//(internal1_m2121_tx) tx - время накопленное сек
#define internal1_m2121_y0	 BUFFER[4242]	//(internal1_m2121_y0) y0
#define idinternal1_m2121_y0	 1311	//(internal1_m2121_y0) y0
#define internal1_m2264_tx	 BUFFER[4243]	//(internal1_m2264_tx) tx - время накопленное сек
#define idinternal1_m2264_tx	 1312	//(internal1_m2264_tx) tx - время накопленное сек
#define internal1_m2264_y0	 BUFFER[4248]	//(internal1_m2264_y0) y0
#define idinternal1_m2264_y0	 1313	//(internal1_m2264_y0) y0
#define internal1_m2275_tx	 BUFFER[4249]	//(internal1_m2275_tx) tx - время накопленное сек
#define idinternal1_m2275_tx	 1314	//(internal1_m2275_tx) tx - время накопленное сек
#define internal1_m2275_y0	 BUFFER[4254]	//(internal1_m2275_y0) y0
#define idinternal1_m2275_y0	 1315	//(internal1_m2275_y0) y0
#define internal1_m2030_tx	 BUFFER[4255]	//(internal1_m2030_tx) tx - время накопленное сек
#define idinternal1_m2030_tx	 1316	//(internal1_m2030_tx) tx - время накопленное сек
#define internal1_m2030_y0	 BUFFER[4260]	//(internal1_m2030_y0) y0
#define idinternal1_m2030_y0	 1317	//(internal1_m2030_y0) y0
#define internal1_m2029_tx	 BUFFER[4261]	//(internal1_m2029_tx) tx - время накопленное сек
#define idinternal1_m2029_tx	 1318	//(internal1_m2029_tx) tx - время накопленное сек
#define internal1_m2029_y0	 BUFFER[4266]	//(internal1_m2029_y0) y0
#define idinternal1_m2029_y0	 1319	//(internal1_m2029_y0) y0
#define internal1_m2028_tx	 BUFFER[4267]	//(internal1_m2028_tx) tx - время накопленное сек
#define idinternal1_m2028_tx	 1320	//(internal1_m2028_tx) tx - время накопленное сек
#define internal1_m2028_y0	 BUFFER[4272]	//(internal1_m2028_y0) y0
#define idinternal1_m2028_y0	 1321	//(internal1_m2028_y0) y0
#define internal1_m2027_tx	 BUFFER[4273]	//(internal1_m2027_tx) tx - время накопленное сек
#define idinternal1_m2027_tx	 1322	//(internal1_m2027_tx) tx - время накопленное сек
#define internal1_m2027_y0	 BUFFER[4278]	//(internal1_m2027_y0) y0
#define idinternal1_m2027_y0	 1323	//(internal1_m2027_y0) y0
#define internal1_m1702_tx	 BUFFER[4279]	//(internal1_m1702_tx) tx - время накопленное сек
#define idinternal1_m1702_tx	 1324	//(internal1_m1702_tx) tx - время накопленное сек
#define internal1_m1702_y0	 BUFFER[4284]	//(internal1_m1702_y0) y0
#define idinternal1_m1702_y0	 1325	//(internal1_m1702_y0) y0
#define internal1_m1696_tx	 BUFFER[4285]	//(internal1_m1696_tx) tx - время накопленное сек
#define idinternal1_m1696_tx	 1326	//(internal1_m1696_tx) tx - время накопленное сек
#define internal1_m1696_y0	 BUFFER[4290]	//(internal1_m1696_y0) y0
#define idinternal1_m1696_y0	 1327	//(internal1_m1696_y0) y0
#define internal1_m1643_tx	 BUFFER[4291]	//(internal1_m1643_tx) tx - время накопленное сек
#define idinternal1_m1643_tx	 1328	//(internal1_m1643_tx) tx - время накопленное сек
#define internal1_m1643_y0	 BUFFER[4296]	//(internal1_m1643_y0) y0
#define idinternal1_m1643_y0	 1329	//(internal1_m1643_y0) y0
#define internal1_m922_tx	 BUFFER[4297]	//(internal1_m922_tx) tx - время накопленное сек
#define idinternal1_m922_tx	 1330	//(internal1_m922_tx) tx - время накопленное сек
#define internal1_m922_y0	 BUFFER[4302]	//(internal1_m922_y0) y0
#define idinternal1_m922_y0	 1331	//(internal1_m922_y0) y0
#define internal1_m921_tx	 BUFFER[4303]	//(internal1_m921_tx) tx - время накопленное сек
#define idinternal1_m921_tx	 1332	//(internal1_m921_tx) tx - время накопленное сек
#define internal1_m921_y0	 BUFFER[4308]	//(internal1_m921_y0) y0
#define idinternal1_m921_y0	 1333	//(internal1_m921_y0) y0
#define internal1_m939_tx	 BUFFER[4309]	//(internal1_m939_tx) tx - время накопленное сек
#define idinternal1_m939_tx	 1334	//(internal1_m939_tx) tx - время накопленное сек
#define internal1_m939_y0	 BUFFER[4314]	//(internal1_m939_y0) y0
#define idinternal1_m939_y0	 1335	//(internal1_m939_y0) y0
#define internal1_m194_tx	 BUFFER[4315]	//(internal1_m194_tx) tx - время накопленное сек
#define idinternal1_m194_tx	 1336	//(internal1_m194_tx) tx - время накопленное сек
#define internal1_m194_y0	 BUFFER[4320]	//(internal1_m194_y0) y0
#define idinternal1_m194_y0	 1337	//(internal1_m194_y0) y0
#define internal1_m193_tx	 BUFFER[4321]	//(internal1_m193_tx) tx - время накопленное сек
#define idinternal1_m193_tx	 1338	//(internal1_m193_tx) tx - время накопленное сек
#define internal1_m193_y0	 BUFFER[4326]	//(internal1_m193_y0) y0
#define idinternal1_m193_y0	 1339	//(internal1_m193_y0) y0
#define internal1_m215_tx	 BUFFER[4327]	//(internal1_m215_tx) tx - время накопленное сек
#define idinternal1_m215_tx	 1340	//(internal1_m215_tx) tx - время накопленное сек
#define internal1_m215_y0	 BUFFER[4332]	//(internal1_m215_y0) y0
#define idinternal1_m215_y0	 1341	//(internal1_m215_y0) y0
#define internal1_m588_tx	 BUFFER[4333]	//(internal1_m588_tx) tx - время накопленное сек
#define idinternal1_m588_tx	 1342	//(internal1_m588_tx) tx - время накопленное сек
#define internal1_m588_y0	 BUFFER[4338]	//(internal1_m588_y0) y0
#define idinternal1_m588_y0	 1343	//(internal1_m588_y0) y0
#define internal1_m2320_tx	 BUFFER[4339]	//(internal1_m2320_tx) tx - внутренний параметр
#define idinternal1_m2320_tx	 1344	//(internal1_m2320_tx) tx - внутренний параметр
#define internal1_m1341_tx	 BUFFER[4344]	//(internal1_m1341_tx) tx - внутренний параметр
#define idinternal1_m1341_tx	 1345	//(internal1_m1341_tx) tx - внутренний параметр
#define internal1_m1832_tx	 BUFFER[4349]	//(internal1_m1832_tx) tx - время накопленное сек
#define idinternal1_m1832_tx	 1346	//(internal1_m1832_tx) tx - время накопленное сек
#define internal1_m1832_y0	 BUFFER[4354]	//(internal1_m1832_y0) y0
#define idinternal1_m1832_y0	 1347	//(internal1_m1832_y0) y0
#define internal1_m1306_tx	 BUFFER[4355]	//(internal1_m1306_tx) tx - время накопленное сек
#define idinternal1_m1306_tx	 1348	//(internal1_m1306_tx) tx - время накопленное сек
#define internal1_m1306_y0	 BUFFER[4360]	//(internal1_m1306_y0) y0
#define idinternal1_m1306_y0	 1349	//(internal1_m1306_y0) y0
#define internal1_m1525_tx	 BUFFER[4361]	//(internal1_m1525_tx) tx - время накопленное сек
#define idinternal1_m1525_tx	 1350	//(internal1_m1525_tx) tx - время накопленное сек
#define internal1_m1525_y0	 BUFFER[4366]	//(internal1_m1525_y0) y0
#define idinternal1_m1525_y0	 1351	//(internal1_m1525_y0) y0
#define internal1_m1052_tx	 BUFFER[4367]	//(internal1_m1052_tx) tx - время накопленное сек
#define idinternal1_m1052_tx	 1352	//(internal1_m1052_tx) tx - время накопленное сек
#define internal1_m1052_y0	 BUFFER[4372]	//(internal1_m1052_y0) y0
#define idinternal1_m1052_y0	 1353	//(internal1_m1052_y0) y0
#define internal1_m1415_tx	 BUFFER[4373]	//(internal1_m1415_tx) tx - время накопленное сек
#define idinternal1_m1415_tx	 1354	//(internal1_m1415_tx) tx - время накопленное сек
#define internal1_m1415_y0	 BUFFER[4378]	//(internal1_m1415_y0) y0
#define idinternal1_m1415_y0	 1355	//(internal1_m1415_y0) y0
#define internal1_m1209_q0	 BUFFER[4379]	//(internal1_m1209_q0) q0 - внутренний параметр
#define idinternal1_m1209_q0	 1356	//(internal1_m1209_q0) q0 - внутренний параметр
#define internal1_m1207_q0	 BUFFER[4381]	//(internal1_m1207_q0) q0 - внутренний параметр
#define idinternal1_m1207_q0	 1357	//(internal1_m1207_q0) q0 - внутренний параметр
#define internal1_m1206_q0	 BUFFER[4383]	//(internal1_m1206_q0) q0 - внутренний параметр
#define idinternal1_m1206_q0	 1358	//(internal1_m1206_q0) q0 - внутренний параметр
#define internal1_m1204_q0	 BUFFER[4385]	//(internal1_m1204_q0) q0 - внутренний параметр
#define idinternal1_m1204_q0	 1359	//(internal1_m1204_q0) q0 - внутренний параметр
#define internal1_m1203_q0	 BUFFER[4387]	//(internal1_m1203_q0) q0 - внутренний параметр
#define idinternal1_m1203_q0	 1360	//(internal1_m1203_q0) q0 - внутренний параметр
#define internal1_m1201_q0	 BUFFER[4389]	//(internal1_m1201_q0) q0 - внутренний параметр
#define idinternal1_m1201_q0	 1361	//(internal1_m1201_q0) q0 - внутренний параметр
#define internal1_m1200_q0	 BUFFER[4391]	//(internal1_m1200_q0) q0 - внутренний параметр
#define idinternal1_m1200_q0	 1362	//(internal1_m1200_q0) q0 - внутренний параметр
#define internal1_m1198_q0	 BUFFER[4393]	//(internal1_m1198_q0) q0 - внутренний параметр
#define idinternal1_m1198_q0	 1363	//(internal1_m1198_q0) q0 - внутренний параметр
#define internal1_m1197_q0	 BUFFER[4395]	//(internal1_m1197_q0) q0 - внутренний параметр
#define idinternal1_m1197_q0	 1364	//(internal1_m1197_q0) q0 - внутренний параметр
#define internal1_m54_x0	 BUFFER[4397]	//(internal1_m54_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m54_x0	 1365	//(internal1_m54_x0) - значение входного параметра на предыдущем шаге
#define internal1_m54_tim	 BUFFER[4399]	//(internal1_m54_tim) - время задержки выходного сигнала
#define idinternal1_m54_tim	 1366	//(internal1_m54_tim) - время задержки выходного сигнала
#define internal1_m1116_q0	 BUFFER[4404]	//(internal1_m1116_q0) q0 - внутренний параметр
#define idinternal1_m1116_q0	 1367	//(internal1_m1116_q0) q0 - внутренний параметр
#define internal1_m1637_x0	 BUFFER[4406]	//(internal1_m1637_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m1637_x0	 1368	//(internal1_m1637_x0) - значение входного параметра на предыдущем шаге
#define internal1_m1637_tim	 BUFFER[4408]	//(internal1_m1637_tim) - время задержки выходного сигнала
#define idinternal1_m1637_tim	 1369	//(internal1_m1637_tim) - время задержки выходного сигнала
#define internal1_m1685_x0	 BUFFER[4413]	//(internal1_m1685_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m1685_x0	 1370	//(internal1_m1685_x0) - значение входного параметра на предыдущем шаге
#define internal1_m1685_tim	 BUFFER[4415]	//(internal1_m1685_tim) - время задержки выходного сигнала
#define idinternal1_m1685_tim	 1371	//(internal1_m1685_tim) - время задержки выходного сигнала
#define internal1_m1688_x0	 BUFFER[4420]	//(internal1_m1688_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m1688_x0	 1372	//(internal1_m1688_x0) - значение входного параметра на предыдущем шаге
#define internal1_m1688_tim	 BUFFER[4422]	//(internal1_m1688_tim) - время задержки выходного сигнала
#define idinternal1_m1688_tim	 1373	//(internal1_m1688_tim) - время задержки выходного сигнала
#define internal1_m2072_x0	 BUFFER[4427]	//(internal1_m2072_x0) - значение входного параметра на предыдущем шаге
#define idinternal1_m2072_x0	 1374	//(internal1_m2072_x0) - значение входного параметра на предыдущем шаге
#define internal1_m2072_tim	 BUFFER[4429]	//(internal1_m2072_tim) - время задержки выходного сигнала
#define idinternal1_m2072_tim	 1375	//(internal1_m2072_tim) - время задержки выходного сигнала
#define internal1_m1156_q0	 BUFFER[4434]	//(internal1_m1156_q0) q0 - внутренний параметр
#define idinternal1_m1156_q0	 1376	//(internal1_m1156_q0) q0 - внутренний параметр
#define internal1_m1162_q0	 BUFFER[4436]	//(internal1_m1162_q0) q0 - внутренний параметр
#define idinternal1_m1162_q0	 1377	//(internal1_m1162_q0) q0 - внутренний параметр
#define internal1_m1180_q0	 BUFFER[4438]	//(internal1_m1180_q0) q0 - внутренний параметр
#define idinternal1_m1180_q0	 1378	//(internal1_m1180_q0) q0 - внутренний параметр
#define internal1_m1189_q0	 BUFFER[4440]	//(internal1_m1189_q0) q0 - внутренний параметр
#define idinternal1_m1189_q0	 1379	//(internal1_m1189_q0) q0 - внутренний параметр
#define internal1_m1168_q0	 BUFFER[4442]	//(internal1_m1168_q0) q0 - внутренний параметр
#define idinternal1_m1168_q0	 1380	//(internal1_m1168_q0) q0 - внутренний параметр
#define internal1_m1182_q0	 BUFFER[4444]	//(internal1_m1182_q0) q0 - внутренний параметр
#define idinternal1_m1182_q0	 1381	//(internal1_m1182_q0) q0 - внутренний параметр
#define internal1_m2158_q0	 BUFFER[4446]	//(internal1_m2158_q0) q0 - внутренний параметр
#define idinternal1_m2158_q0	 1382	//(internal1_m2158_q0) q0 - внутренний параметр
#define internal1_m2157_q0	 BUFFER[4448]	//(internal1_m2157_q0) q0 - внутренний параметр
#define idinternal1_m2157_q0	 1383	//(internal1_m2157_q0) q0 - внутренний параметр
#define internal1_m356_Step	 BUFFER[4450]	//(internal1_m356_Step)  - текущий шаг программы
#define idinternal1_m356_Step	 1384	//(internal1_m356_Step)  - текущий шаг программы
#define internal1_m356_rz	 BUFFER[4453]	//(internal1_m356_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m356_rz	 1385	//(internal1_m356_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m356_TimS	 BUFFER[4463]	//(internal1_m356_TimS) Время от старта программы
#define idinternal1_m356_TimS	 1386	//(internal1_m356_TimS) Время от старта программы
#define internal1_m356_FinPr0	 BUFFER[4468]	//(internal1_m356_FinPr0) FinPr - конец программы
#define idinternal1_m356_FinPr0	 1387	//(internal1_m356_FinPr0) FinPr - конец программы
#define internal1_m356_ErrPr0	 BUFFER[4470]	//(internal1_m356_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m356_ErrPr0	 1388	//(internal1_m356_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m356_sbINI0	 BUFFER[4472]	//(internal1_m356_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m356_sbINI0	 1389	//(internal1_m356_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m356_sbVuIS0	 BUFFER[4474]	//(internal1_m356_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m356_sbVuIS0	 1390	//(internal1_m356_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m356_sb2UR0	 BUFFER[4476]	//(internal1_m356_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m356_sb2UR0	 1391	//(internal1_m356_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m356_sbNupIS0	 BUFFER[4478]	//(internal1_m356_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m356_sbNupIS0	 1392	//(internal1_m356_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m356_sbVuRB0	 BUFFER[4480]	//(internal1_m356_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m356_sbVuRB0	 1393	//(internal1_m356_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m356_MyFirstEnterFlag	 BUFFER[4482]	//(internal1_m356_MyFirstEnterFlag)  
#define idinternal1_m356_MyFirstEnterFlag	 1394	//(internal1_m356_MyFirstEnterFlag)  
#define internal1_m364_x0	 BUFFER[4484]	//(internal1_m364_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m364_x0	 1395	//(internal1_m364_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m321_TimS	 BUFFER[4489]	//(internal1_m321_TimS) Время до нулевого отсчета
#define idinternal1_m321_TimS	 1396	//(internal1_m321_TimS) Время до нулевого отсчета
#define internal1_m321_pusk0	 BUFFER[4494]	//(internal1_m321_pusk0) pusk - разрешение выполнения программы
#define idinternal1_m321_pusk0	 1397	//(internal1_m321_pusk0) pusk - разрешение выполнения программы
#define internal1_m298_Step	 BUFFER[4496]	//(internal1_m298_Step)  - текущий шаг программы
#define idinternal1_m298_Step	 1398	//(internal1_m298_Step)  - текущий шаг программы
#define internal1_m298_rz	 BUFFER[4499]	//(internal1_m298_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m298_rz	 1399	//(internal1_m298_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m298_TimS	 BUFFER[4509]	//(internal1_m298_TimS) Время от старта программы
#define idinternal1_m298_TimS	 1400	//(internal1_m298_TimS) Время от старта программы
#define internal1_m298_FinPr0	 BUFFER[4514]	//(internal1_m298_FinPr0) FinPr - конец программы
#define idinternal1_m298_FinPr0	 1401	//(internal1_m298_FinPr0) FinPr - конец программы
#define internal1_m298_ErrPr0	 BUFFER[4516]	//(internal1_m298_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m298_ErrPr0	 1402	//(internal1_m298_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m298_sbINI0	 BUFFER[4518]	//(internal1_m298_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m298_sbINI0	 1403	//(internal1_m298_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m298_sbVuIS0	 BUFFER[4520]	//(internal1_m298_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m298_sbVuIS0	 1404	//(internal1_m298_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m298_sb2UR0	 BUFFER[4522]	//(internal1_m298_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m298_sb2UR0	 1405	//(internal1_m298_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m298_sbNupIS0	 BUFFER[4524]	//(internal1_m298_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m298_sbNupIS0	 1406	//(internal1_m298_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m298_sbVuRB0	 BUFFER[4526]	//(internal1_m298_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m298_sbVuRB0	 1407	//(internal1_m298_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m298_MyFirstEnterFlag	 BUFFER[4528]	//(internal1_m298_MyFirstEnterFlag)  
#define idinternal1_m298_MyFirstEnterFlag	 1408	//(internal1_m298_MyFirstEnterFlag)  
#define internal1_m1599_q0	 BUFFER[4530]	//(internal1_m1599_q0) q0 - внутренний параметр
#define idinternal1_m1599_q0	 1409	//(internal1_m1599_q0) q0 - внутренний параметр
#define internal1_m1600_Step	 BUFFER[4532]	//(internal1_m1600_Step)  - текущий шаг программы
#define idinternal1_m1600_Step	 1410	//(internal1_m1600_Step)  - текущий шаг программы
#define internal1_m1600_rz	 BUFFER[4535]	//(internal1_m1600_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define idinternal1_m1600_rz	 1411	//(internal1_m1600_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
#define internal1_m1600_TimS	 BUFFER[4541]	//(internal1_m1600_TimS) Время от старта программы
#define idinternal1_m1600_TimS	 1412	//(internal1_m1600_TimS) Время от старта программы
#define internal1_m1600_FinPr0	 BUFFER[4546]	//(internal1_m1600_FinPr0) FinPr - конец программы
#define idinternal1_m1600_FinPr0	 1413	//(internal1_m1600_FinPr0) FinPr - конец программы
#define internal1_m1600_ErrPr0	 BUFFER[4548]	//(internal1_m1600_ErrPr0) ErrPr - Приостановка программы по ошибке
#define idinternal1_m1600_ErrPr0	 1414	//(internal1_m1600_ErrPr0) ErrPr - Приостановка программы по ошибке
#define internal1_m1600_sbINI0	 BUFFER[4550]	//(internal1_m1600_sbINI0) sbINI - запуск проверки ИНИ
#define idinternal1_m1600_sbINI0	 1415	//(internal1_m1600_sbINI0) sbINI - запуск проверки ИНИ
#define internal1_m1600_sbVuIS0	 BUFFER[4552]	//(internal1_m1600_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define idinternal1_m1600_sbVuIS0	 1416	//(internal1_m1600_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
#define internal1_m1600_sb2UR0	 BUFFER[4554]	//(internal1_m1600_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define idinternal1_m1600_sb2UR0	 1417	//(internal1_m1600_sb2UR0) sb2UR - запуск проверки сброса от 2УР
#define internal1_m1600_sbNupIS0	 BUFFER[4556]	//(internal1_m1600_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define idinternal1_m1600_sbNupIS0	 1418	//(internal1_m1600_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
#define internal1_m1600_sbVuRB0	 BUFFER[4558]	//(internal1_m1600_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define idinternal1_m1600_sbVuRB0	 1419	//(internal1_m1600_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
#define internal1_m1600_MyFirstEnterFlag	 BUFFER[4560]	//(internal1_m1600_MyFirstEnterFlag)  
#define idinternal1_m1600_MyFirstEnterFlag	 1420	//(internal1_m1600_MyFirstEnterFlag)  
#define internal1_m1152_q0	 BUFFER[4562]	//(internal1_m1152_q0) q0 - внутренний параметр
#define idinternal1_m1152_q0	 1421	//(internal1_m1152_q0) q0 - внутренний параметр
#define internal1_m1149_q0	 BUFFER[4564]	//(internal1_m1149_q0) q0 - внутренний параметр
#define idinternal1_m1149_q0	 1422	//(internal1_m1149_q0) q0 - внутренний параметр
#define internal1_m1151_q0	 BUFFER[4566]	//(internal1_m1151_q0) q0 - внутренний параметр
#define idinternal1_m1151_q0	 1423	//(internal1_m1151_q0) q0 - внутренний параметр
#define internal1_m1145_q0	 BUFFER[4568]	//(internal1_m1145_q0) q0 - внутренний параметр
#define idinternal1_m1145_q0	 1424	//(internal1_m1145_q0) q0 - внутренний параметр
#define internal1_m836_q0	 BUFFER[4570]	//(internal1_m836_q0) q0 - внутренний параметр
#define idinternal1_m836_q0	 1425	//(internal1_m836_q0) q0 - внутренний параметр
#define internal1_m366_q0	 BUFFER[4572]	//(internal1_m366_q0) q0 - внутренний параметр
#define idinternal1_m366_q0	 1426	//(internal1_m366_q0) q0 - внутренний параметр
#define internal1_m362_q0	 BUFFER[4574]	//(internal1_m362_q0) q0 - внутренний параметр
#define idinternal1_m362_q0	 1427	//(internal1_m362_q0) q0 - внутренний параметр
#define internal1_m318_q0	 BUFFER[4576]	//(internal1_m318_q0) q0 - внутренний параметр
#define idinternal1_m318_q0	 1428	//(internal1_m318_q0) q0 - внутренний параметр
#define internal1_m317_x0	 BUFFER[4578]	//(internal1_m317_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m317_x0	 1429	//(internal1_m317_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m2087_q0	 BUFFER[4583]	//(internal1_m2087_q0) q0 - внутренний параметр
#define idinternal1_m2087_q0	 1430	//(internal1_m2087_q0) q0 - внутренний параметр
#define internal1_m2080_q0	 BUFFER[4585]	//(internal1_m2080_q0) q0 - внутренний параметр
#define idinternal1_m2080_q0	 1431	//(internal1_m2080_q0) q0 - внутренний параметр
#define internal1_m2073_q0	 BUFFER[4587]	//(internal1_m2073_q0) q0 - внутренний параметр
#define idinternal1_m2073_q0	 1432	//(internal1_m2073_q0) q0 - внутренний параметр
#define internal1_m2141_q0	 BUFFER[4589]	//(internal1_m2141_q0) q0 - внутренний параметр
#define idinternal1_m2141_q0	 1433	//(internal1_m2141_q0) q0 - внутренний параметр
#define internal1_m2112_q0	 BUFFER[4591]	//(internal1_m2112_q0) q0 - внутренний параметр
#define idinternal1_m2112_q0	 1434	//(internal1_m2112_q0) q0 - внутренний параметр
#define internal1_m2100_q0	 BUFFER[4593]	//(internal1_m2100_q0) q0 - внутренний параметр
#define idinternal1_m2100_q0	 1435	//(internal1_m2100_q0) q0 - внутренний параметр
#define internal1_m1664_q0	 BUFFER[4595]	//(internal1_m1664_q0) q0 - внутренний параметр
#define idinternal1_m1664_q0	 1436	//(internal1_m1664_q0) q0 - внутренний параметр
#define internal1_m1651_x0	 BUFFER[4597]	//(internal1_m1651_x0) был приход сигнала x1
#define idinternal1_m1651_x0	 1437	//(internal1_m1651_x0) был приход сигнала x1
#define internal1_m1651_y0	 BUFFER[4599]	//(internal1_m1651_y0) интервал между сигналами х1 и х2
#define idinternal1_m1651_y0	 1438	//(internal1_m1651_y0) интервал между сигналами х1 и х2
#define internal1_m1651_fef	 BUFFER[4604]	//(internal1_m1651_fef) FirstEnterFlag
#define idinternal1_m1651_fef	 1439	//(internal1_m1651_fef) FirstEnterFlag
#define internal1_m1646_q0	 BUFFER[4606]	//(internal1_m1646_q0) q0 - внутренний параметр
#define idinternal1_m1646_q0	 1440	//(internal1_m1646_q0) q0 - внутренний параметр
#define internal1_m1636_q0	 BUFFER[4608]	//(internal1_m1636_q0) q0 - внутренний параметр
#define idinternal1_m1636_q0	 1441	//(internal1_m1636_q0) q0 - внутренний параметр
#define internal1_m1699_q0	 BUFFER[4610]	//(internal1_m1699_q0) q0 - внутренний параметр
#define idinternal1_m1699_q0	 1442	//(internal1_m1699_q0) q0 - внутренний параметр
#define internal1_m1720_q0	 BUFFER[4612]	//(internal1_m1720_q0) q0 - внутренний параметр
#define idinternal1_m1720_q0	 1443	//(internal1_m1720_q0) q0 - внутренний параметр
#define internal1_m1684_q0	 BUFFER[4614]	//(internal1_m1684_q0) q0 - внутренний параметр
#define idinternal1_m1684_q0	 1444	//(internal1_m1684_q0) q0 - внутренний параметр
#define internal1_m1700_x0	 BUFFER[4616]	//(internal1_m1700_x0) был приход сигнала x1
#define idinternal1_m1700_x0	 1445	//(internal1_m1700_x0) был приход сигнала x1
#define internal1_m1700_y0	 BUFFER[4618]	//(internal1_m1700_y0) интервал между сигналами х1 и х2
#define idinternal1_m1700_y0	 1446	//(internal1_m1700_y0) интервал между сигналами х1 и х2
#define internal1_m1700_fef	 BUFFER[4623]	//(internal1_m1700_fef) FirstEnterFlag
#define idinternal1_m1700_fef	 1447	//(internal1_m1700_fef) FirstEnterFlag
#define internal1_m1617_x0	 BUFFER[4625]	//(internal1_m1617_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m1617_x0	 1448	//(internal1_m1617_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m1706_q0	 BUFFER[4630]	//(internal1_m1706_q0) q0 - внутренний параметр
#define idinternal1_m1706_q0	 1449	//(internal1_m1706_q0) q0 - внутренний параметр
#define internal1_m26_q0	 BUFFER[4632]	//(internal1_m26_q0) q0 - внутренний параметр
#define idinternal1_m26_q0	 1450	//(internal1_m26_q0) q0 - внутренний параметр
#define internal1_m1721_q0	 BUFFER[4634]	//(internal1_m1721_q0) q0 - внутренний параметр
#define idinternal1_m1721_q0	 1451	//(internal1_m1721_q0) q0 - внутренний параметр
#define internal1_m711_q0	 BUFFER[4636]	//(internal1_m711_q0) q0 - внутренний параметр
#define idinternal1_m711_q0	 1452	//(internal1_m711_q0) q0 - внутренний параметр
#define internal1_m696_q0	 BUFFER[4638]	//(internal1_m696_q0) q0 - внутренний параметр
#define idinternal1_m696_q0	 1453	//(internal1_m696_q0) q0 - внутренний параметр
#define internal1_m724_q0	 BUFFER[4640]	//(internal1_m724_q0) q0 - внутренний параметр
#define idinternal1_m724_q0	 1454	//(internal1_m724_q0) q0 - внутренний параметр
#define internal1_m707_q0	 BUFFER[4642]	//(internal1_m707_q0) q0 - внутренний параметр
#define idinternal1_m707_q0	 1455	//(internal1_m707_q0) q0 - внутренний параметр
#define internal1_m691_q0	 BUFFER[4644]	//(internal1_m691_q0) q0 - внутренний параметр
#define idinternal1_m691_q0	 1456	//(internal1_m691_q0) q0 - внутренний параметр
#define internal1_m689_q0	 BUFFER[4646]	//(internal1_m689_q0) q0 - внутренний параметр
#define idinternal1_m689_q0	 1457	//(internal1_m689_q0) q0 - внутренний параметр
#define internal1_m677_q0	 BUFFER[4648]	//(internal1_m677_q0) q0 - внутренний параметр
#define idinternal1_m677_q0	 1458	//(internal1_m677_q0) q0 - внутренний параметр
#define internal1_m1602_q0	 BUFFER[4650]	//(internal1_m1602_q0) q0 - внутренний параметр
#define idinternal1_m1602_q0	 1459	//(internal1_m1602_q0) q0 - внутренний параметр
#define internal1_m687_q0	 BUFFER[4655]	//(internal1_m687_q0) q0 - внутренний параметр
#define idinternal1_m687_q0	 1460	//(internal1_m687_q0) q0 - внутренний параметр
#define internal1_m116_q0	 BUFFER[4657]	//(internal1_m116_q0) q0 - внутренний параметр
#define idinternal1_m116_q0	 1461	//(internal1_m116_q0) q0 - внутренний параметр
#define internal1_m1867_q0	 BUFFER[4659]	//(internal1_m1867_q0) q0 - внутренний параметр
#define idinternal1_m1867_q0	 1462	//(internal1_m1867_q0) q0 - внутренний параметр
#define internal1_m1866_q0	 BUFFER[4661]	//(internal1_m1866_q0) q0 - внутренний параметр
#define idinternal1_m1866_q0	 1463	//(internal1_m1866_q0) q0 - внутренний параметр
#define internal1_m1865_q0	 BUFFER[4663]	//(internal1_m1865_q0) q0 - внутренний параметр
#define idinternal1_m1865_q0	 1464	//(internal1_m1865_q0) q0 - внутренний параметр
#define internal1_m1864_q0	 BUFFER[4665]	//(internal1_m1864_q0) q0 - внутренний параметр
#define idinternal1_m1864_q0	 1465	//(internal1_m1864_q0) q0 - внутренний параметр
#define internal1_m1900_q0	 BUFFER[4667]	//(internal1_m1900_q0) q0 - внутренний параметр
#define idinternal1_m1900_q0	 1466	//(internal1_m1900_q0) q0 - внутренний параметр
#define internal1_m1899_q0	 BUFFER[4669]	//(internal1_m1899_q0) q0 - внутренний параметр
#define idinternal1_m1899_q0	 1467	//(internal1_m1899_q0) q0 - внутренний параметр
#define internal1_m1898_q0	 BUFFER[4671]	//(internal1_m1898_q0) q0 - внутренний параметр
#define idinternal1_m1898_q0	 1468	//(internal1_m1898_q0) q0 - внутренний параметр
#define internal1_m2172_q0	 BUFFER[4673]	//(internal1_m2172_q0) q0 - внутренний параметр
#define idinternal1_m2172_q0	 1469	//(internal1_m2172_q0) q0 - внутренний параметр
#define internal1_m1960_q0	 BUFFER[4675]	//(internal1_m1960_q0) q0 - внутренний параметр
#define idinternal1_m1960_q0	 1470	//(internal1_m1960_q0) q0 - внутренний параметр
#define internal1_m1950_q0	 BUFFER[4677]	//(internal1_m1950_q0) q0 - внутренний параметр
#define idinternal1_m1950_q0	 1471	//(internal1_m1950_q0) q0 - внутренний параметр
#define internal1_m1957_q0	 BUFFER[4679]	//(internal1_m1957_q0) q0 - внутренний параметр
#define idinternal1_m1957_q0	 1472	//(internal1_m1957_q0) q0 - внутренний параметр
#define internal1_m1947_q0	 BUFFER[4681]	//(internal1_m1947_q0) q0 - внутренний параметр
#define idinternal1_m1947_q0	 1473	//(internal1_m1947_q0) q0 - внутренний параметр
#define internal1_m1954_q0	 BUFFER[4683]	//(internal1_m1954_q0) q0 - внутренний параметр
#define idinternal1_m1954_q0	 1474	//(internal1_m1954_q0) q0 - внутренний параметр
#define internal1_m2388_q0	 BUFFER[4685]	//(internal1_m2388_q0) q0 - внутренний параметр
#define idinternal1_m2388_q0	 1475	//(internal1_m2388_q0) q0 - внутренний параметр
#define internal1_m2384_q0	 BUFFER[4687]	//(internal1_m2384_q0) q0 - внутренний параметр
#define idinternal1_m2384_q0	 1476	//(internal1_m2384_q0) q0 - внутренний параметр
#define internal1_m1925_q0	 BUFFER[4689]	//(internal1_m1925_q0) q0 - внутренний параметр
#define idinternal1_m1925_q0	 1477	//(internal1_m1925_q0) q0 - внутренний параметр
#define internal1_m1917_q0	 BUFFER[4691]	//(internal1_m1917_q0) q0 - внутренний параметр
#define idinternal1_m1917_q0	 1478	//(internal1_m1917_q0) q0 - внутренний параметр
#define internal1_m1915_q0	 BUFFER[4693]	//(internal1_m1915_q0) q0 - внутренний параметр
#define idinternal1_m1915_q0	 1479	//(internal1_m1915_q0) q0 - внутренний параметр
#define internal1_m1911_q0	 BUFFER[4695]	//(internal1_m1911_q0) q0 - внутренний параметр
#define idinternal1_m1911_q0	 1480	//(internal1_m1911_q0) q0 - внутренний параметр
#define internal1_m1907_q0	 BUFFER[4697]	//(internal1_m1907_q0) q0 - внутренний параметр
#define idinternal1_m1907_q0	 1481	//(internal1_m1907_q0) q0 - внутренний параметр
#define internal1_m1909_q0	 BUFFER[4699]	//(internal1_m1909_q0) q0 - внутренний параметр
#define idinternal1_m1909_q0	 1482	//(internal1_m1909_q0) q0 - внутренний параметр
#define internal1_m19_q0	 BUFFER[4701]	//(internal1_m19_q0) q0 - внутренний параметр
#define idinternal1_m19_q0	 1483	//(internal1_m19_q0) q0 - внутренний параметр
#define internal1_m1890_q0	 BUFFER[4703]	//(internal1_m1890_q0) q0 - внутренний параметр
#define idinternal1_m1890_q0	 1484	//(internal1_m1890_q0) q0 - внутренний параметр
#define internal1_m1888_q0	 BUFFER[4705]	//(internal1_m1888_q0) q0 - внутренний параметр
#define idinternal1_m1888_q0	 1485	//(internal1_m1888_q0) q0 - внутренний параметр
#define internal1_m1884_q0	 BUFFER[4707]	//(internal1_m1884_q0) q0 - внутренний параметр
#define idinternal1_m1884_q0	 1486	//(internal1_m1884_q0) q0 - внутренний параметр
#define internal1_m1886_q0	 BUFFER[4709]	//(internal1_m1886_q0) q0 - внутренний параметр
#define idinternal1_m1886_q0	 1487	//(internal1_m1886_q0) q0 - внутренний параметр
#define internal1_m1882_q0	 BUFFER[4711]	//(internal1_m1882_q0) q0 - внутренний параметр
#define idinternal1_m1882_q0	 1488	//(internal1_m1882_q0) q0 - внутренний параметр
#define internal1_m1880_q0	 BUFFER[4713]	//(internal1_m1880_q0) q0 - внутренний параметр
#define idinternal1_m1880_q0	 1489	//(internal1_m1880_q0) q0 - внутренний параметр
#define internal1_m2294_q0	 BUFFER[4715]	//(internal1_m2294_q0) q0 - внутренний параметр
#define idinternal1_m2294_q0	 1490	//(internal1_m2294_q0) q0 - внутренний параметр
#define internal1_m2292_q0	 BUFFER[4717]	//(internal1_m2292_q0) q0 - внутренний параметр
#define idinternal1_m2292_q0	 1491	//(internal1_m2292_q0) q0 - внутренний параметр
#define internal1_m2269_q0	 BUFFER[4719]	//(internal1_m2269_q0) q0 - внутренний параметр
#define idinternal1_m2269_q0	 1492	//(internal1_m2269_q0) q0 - внутренний параметр
#define internal1_m2253_q0	 BUFFER[4721]	//(internal1_m2253_q0) q0 - внутренний параметр
#define idinternal1_m2253_q0	 1493	//(internal1_m2253_q0) q0 - внутренний параметр
#define internal1_m2184_q0	 BUFFER[4723]	//(internal1_m2184_q0) q0 - внутренний параметр
#define idinternal1_m2184_q0	 1494	//(internal1_m2184_q0) q0 - внутренний параметр
#define internal1_m1876_q0	 BUFFER[4725]	//(internal1_m1876_q0) q0 - внутренний параметр
#define idinternal1_m1876_q0	 1495	//(internal1_m1876_q0) q0 - внутренний параметр
#define internal1_m1878_q0	 BUFFER[4727]	//(internal1_m1878_q0) q0 - внутренний параметр
#define idinternal1_m1878_q0	 1496	//(internal1_m1878_q0) q0 - внутренний параметр
#define internal1_m1862_q0	 BUFFER[4729]	//(internal1_m1862_q0) q0 - внутренний параметр
#define idinternal1_m1862_q0	 1497	//(internal1_m1862_q0) q0 - внутренний параметр
#define internal1_m1860_q0	 BUFFER[4731]	//(internal1_m1860_q0) q0 - внутренний параметр
#define idinternal1_m1860_q0	 1498	//(internal1_m1860_q0) q0 - внутренний параметр
#define internal1_m1858_q0	 BUFFER[4733]	//(internal1_m1858_q0) q0 - внутренний параметр
#define idinternal1_m1858_q0	 1499	//(internal1_m1858_q0) q0 - внутренний параметр
#define internal1_m1856_q0	 BUFFER[4735]	//(internal1_m1856_q0) q0 - внутренний параметр
#define idinternal1_m1856_q0	 1500	//(internal1_m1856_q0) q0 - внутренний параметр
#define internal1_m1855_q0	 BUFFER[4737]	//(internal1_m1855_q0) q0 - внутренний параметр
#define idinternal1_m1855_q0	 1501	//(internal1_m1855_q0) q0 - внутренний параметр
#define internal1_m1853_q0	 BUFFER[4739]	//(internal1_m1853_q0) q0 - внутренний параметр
#define idinternal1_m1853_q0	 1502	//(internal1_m1853_q0) q0 - внутренний параметр
#define internal1_m1852_q0	 BUFFER[4741]	//(internal1_m1852_q0) q0 - внутренний параметр
#define idinternal1_m1852_q0	 1503	//(internal1_m1852_q0) q0 - внутренний параметр
#define internal1_m1850_q0	 BUFFER[4743]	//(internal1_m1850_q0) q0 - внутренний параметр
#define idinternal1_m1850_q0	 1504	//(internal1_m1850_q0) q0 - внутренний параметр
#define internal1_m2325_DvUp0	 BUFFER[4745]	//(internal1_m2325_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2325_DvUp0	 1505	//(internal1_m2325_DvUp0) - есть команда на движение вперёд
#define internal1_m2325_DvDw0	 BUFFER[4746]	//(internal1_m2325_DvDw0) - есть команда на движение назад
#define idinternal1_m2325_DvDw0	 1506	//(internal1_m2325_DvDw0) - есть команда на движение назад
#define internal1_m2325_FDvUp0	 BUFFER[4747]	//(internal1_m2325_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2325_FDvUp0	 1507	//(internal1_m2325_FDvUp0) - есть команда на движение вперёд
#define internal1_m2325_FDvDw0	 BUFFER[4748]	//(internal1_m2325_FDvDw0) - есть команда на движение назад
#define idinternal1_m2325_FDvDw0	 1508	//(internal1_m2325_FDvDw0) - есть команда на движение назад
#define internal1_m2325_BlDv0	 BUFFER[4749]	//(internal1_m2325_BlDv0) - была блокировка
#define idinternal1_m2325_BlDv0	 1509	//(internal1_m2325_BlDv0) - была блокировка
#define internal1_m2325_Pkv0	 BUFFER[4750]	//(internal1_m2325_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2325_Pkv0	 1510	//(internal1_m2325_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2325_Pkav0	 BUFFER[4751]	//(internal1_m2325_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2325_Pkav0	 1511	//(internal1_m2325_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2325_Zkv0	 BUFFER[4752]	//(internal1_m2325_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2325_Zkv0	 1512	//(internal1_m2325_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2325_Zkav0	 BUFFER[4753]	//(internal1_m2325_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2325_Zkav0	 1513	//(internal1_m2325_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2325_txNm	 BUFFER[4754]	//(internal1_m2325_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2325_txNm	 1514	//(internal1_m2325_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2325_txSm	 BUFFER[4759]	//(internal1_m2325_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2325_txSm	 1515	//(internal1_m2325_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2325_txHr	 BUFFER[4764]	//(internal1_m2325_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2325_txHr	 1516	//(internal1_m2325_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2325_txLd	 BUFFER[4769]	//(internal1_m2325_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2325_txLd	 1517	//(internal1_m2325_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2325_fef	 BUFFER[4774]	//(internal1_m2325_fef) fef
#define idinternal1_m2325_fef	 1518	//(internal1_m2325_fef) fef
#define internal1_m2319_DvUp0	 BUFFER[4775]	//(internal1_m2319_DvUp0) - есть команда на движение вперёд
#define idinternal1_m2319_DvUp0	 1519	//(internal1_m2319_DvUp0) - есть команда на движение вперёд
#define internal1_m2319_DvDw0	 BUFFER[4776]	//(internal1_m2319_DvDw0) - есть команда на движение назад
#define idinternal1_m2319_DvDw0	 1520	//(internal1_m2319_DvDw0) - есть команда на движение назад
#define internal1_m2319_FDvUp0	 BUFFER[4777]	//(internal1_m2319_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m2319_FDvUp0	 1521	//(internal1_m2319_FDvUp0) - есть команда на движение вперёд
#define internal1_m2319_FDvDw0	 BUFFER[4778]	//(internal1_m2319_FDvDw0) - есть команда на движение назад
#define idinternal1_m2319_FDvDw0	 1522	//(internal1_m2319_FDvDw0) - есть команда на движение назад
#define internal1_m2319_BlDv0	 BUFFER[4779]	//(internal1_m2319_BlDv0) - была блокировка
#define idinternal1_m2319_BlDv0	 1523	//(internal1_m2319_BlDv0) - была блокировка
#define internal1_m2319_Pkv0	 BUFFER[4780]	//(internal1_m2319_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m2319_Pkv0	 1524	//(internal1_m2319_Pkv0) Pkv - передний конечный выключатель
#define internal1_m2319_Pkav0	 BUFFER[4781]	//(internal1_m2319_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m2319_Pkav0	 1525	//(internal1_m2319_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m2319_Zkv0	 BUFFER[4782]	//(internal1_m2319_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m2319_Zkv0	 1526	//(internal1_m2319_Zkv0) Zkv - задний конечный выключатель
#define internal1_m2319_Zkav0	 BUFFER[4783]	//(internal1_m2319_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m2319_Zkav0	 1527	//(internal1_m2319_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m2319_txNm	 BUFFER[4784]	//(internal1_m2319_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m2319_txNm	 1528	//(internal1_m2319_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m2319_txSm	 BUFFER[4789]	//(internal1_m2319_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m2319_txSm	 1529	//(internal1_m2319_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m2319_txHr	 BUFFER[4794]	//(internal1_m2319_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m2319_txHr	 1530	//(internal1_m2319_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m2319_txLd	 BUFFER[4799]	//(internal1_m2319_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m2319_txLd	 1531	//(internal1_m2319_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m2319_fef	 BUFFER[4804]	//(internal1_m2319_fef) fef
#define idinternal1_m2319_fef	 1532	//(internal1_m2319_fef) fef
#define internal1_m1679_q0	 BUFFER[4805]	//(internal1_m1679_q0) q0 - внутренний параметр
#define idinternal1_m1679_q0	 1533	//(internal1_m1679_q0) q0 - внутренний параметр
#define internal1_m1705_x0	 BUFFER[4807]	//(internal1_m1705_x0) был приход сигнала x1
#define idinternal1_m1705_x0	 1534	//(internal1_m1705_x0) был приход сигнала x1
#define internal1_m1705_y0	 BUFFER[4809]	//(internal1_m1705_y0) интервал между сигналами х1 и х2
#define idinternal1_m1705_y0	 1535	//(internal1_m1705_y0) интервал между сигналами х1 и х2
#define internal1_m1705_fef	 BUFFER[4814]	//(internal1_m1705_fef) FirstEnterFlag
#define idinternal1_m1705_fef	 1536	//(internal1_m1705_fef) FirstEnterFlag
#define internal1_m2123_x0	 BUFFER[4816]	//(internal1_m2123_x0) был приход сигнала x1
#define idinternal1_m2123_x0	 1537	//(internal1_m2123_x0) был приход сигнала x1
#define internal1_m2123_y0	 BUFFER[4818]	//(internal1_m2123_y0) интервал между сигналами х1 и х2
#define idinternal1_m2123_y0	 1538	//(internal1_m2123_y0) интервал между сигналами х1 и х2
#define internal1_m2123_fef	 BUFFER[4823]	//(internal1_m2123_fef) FirstEnterFlag
#define idinternal1_m2123_fef	 1539	//(internal1_m2123_fef) FirstEnterFlag
#define internal1_m2082_x0	 BUFFER[4825]	//(internal1_m2082_x0) был приход сигнала x1
#define idinternal1_m2082_x0	 1540	//(internal1_m2082_x0) был приход сигнала x1
#define internal1_m2082_y0	 BUFFER[4827]	//(internal1_m2082_y0) интервал между сигналами х1 и х2
#define idinternal1_m2082_y0	 1541	//(internal1_m2082_y0) интервал между сигналами х1 и х2
#define internal1_m2082_fef	 BUFFER[4832]	//(internal1_m2082_fef) FirstEnterFlag
#define idinternal1_m2082_fef	 1542	//(internal1_m2082_fef) FirstEnterFlag
#define internal1_m309_q0	 BUFFER[4834]	//(internal1_m309_q0) q0 - внутренний параметр
#define idinternal1_m309_q0	 1543	//(internal1_m309_q0) q0 - внутренний параметр
#define internal1_m1124_q0	 BUFFER[4836]	//(internal1_m1124_q0) q0 - внутренний параметр
#define idinternal1_m1124_q0	 1544	//(internal1_m1124_q0) q0 - внутренний параметр
#define internal1_m699_q0	 BUFFER[4838]	//(internal1_m699_q0) q0 - внутренний параметр
#define idinternal1_m699_q0	 1545	//(internal1_m699_q0) q0 - внутренний параметр
#define internal1_m1483_X0	 BUFFER[4840]	//(internal1_m1483_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1483_X0	 1546	//(internal1_m1483_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1483_t0	 BUFFER[4845]	//(internal1_m1483_t0) время нахождения в зоне возврата
#define idinternal1_m1483_t0	 1547	//(internal1_m1483_t0) время нахождения в зоне возврата
#define internal1_m1483_BLDv0	 BUFFER[4850]	//(internal1_m1483_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1483_BLDv0	 1548	//(internal1_m1483_BLDv0) BlDv - Блокировка движения
#define internal1_m1500_tx	 BUFFER[4851]	//(internal1_m1500_tx) tx - время накопленное сек
#define idinternal1_m1500_tx	 1549	//(internal1_m1500_tx) tx - время накопленное сек
#define internal1_m1500_y0	 BUFFER[4856]	//(internal1_m1500_y0) y0
#define idinternal1_m1500_y0	 1550	//(internal1_m1500_y0) y0
#define internal1_m1501_tx	 BUFFER[4857]	//(internal1_m1501_tx) tx - время накопленное сек
#define idinternal1_m1501_tx	 1551	//(internal1_m1501_tx) tx - время накопленное сек
#define internal1_m1501_y0	 BUFFER[4862]	//(internal1_m1501_y0) y0
#define idinternal1_m1501_y0	 1552	//(internal1_m1501_y0) y0
#define internal1_m1509_xptr	 BUFFER[4863]	//(internal1_m1509_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1509_xptr	 1553	//(internal1_m1509_xptr) указатель текущей позиции в массиве координат
#define internal1_m1509_x0	 BUFFER[4866]	//(internal1_m1509_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1509_x0	 1554	//(internal1_m1509_x0) x0 - массив мгновенных значений координат
#define internal1_m1509_tim0	 BUFFER[5166]	//(internal1_m1509_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1509_tim0	 1555	//(internal1_m1509_tim0) tim0 - массив значений времени цикла
#define internal1_m1509_sumtim	 BUFFER[5466]	//(internal1_m1509_sumtim) sumtim - время в пути
#define idinternal1_m1509_sumtim	 1556	//(internal1_m1509_sumtim) sumtim - время в пути
#define internal1_m1509_StSpeed	 BUFFER[5471]	//(internal1_m1509_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1509_StSpeed	 1557	//(internal1_m1509_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1509_Vz0	 BUFFER[5476]	//(internal1_m1509_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1509_Vz0	 1558	//(internal1_m1509_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1509_flRazg	 BUFFER[5481]	//(internal1_m1509_flRazg) признак разгона/торможения
#define idinternal1_m1509_flRazg	 1559	//(internal1_m1509_flRazg) признак разгона/торможения
#define internal1_m1509_DelSp	 BUFFER[5484]	//(internal1_m1509_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1509_DelSp	 1560	//(internal1_m1509_DelSp) DelSp - время переключения скоростей
#define internal1_m1509_z0	 BUFFER[5489]	//(internal1_m1509_z0) z0 - точка прекращения движения
#define idinternal1_m1509_z0	 1561	//(internal1_m1509_z0) z0 - точка прекращения движения
#define internal1_m1509_txZS	 BUFFER[5494]	//(internal1_m1509_txZS) txZS
#define idinternal1_m1509_txZS	 1562	//(internal1_m1509_txZS) txZS
#define internal1_m1509_tx	 BUFFER[5499]	//(internal1_m1509_tx) tx
#define idinternal1_m1509_tx	 1563	//(internal1_m1509_tx) tx
#define internal1_m1509_txd	 BUFFER[5504]	//(internal1_m1509_txd) txd
#define idinternal1_m1509_txd	 1564	//(internal1_m1509_txd) txd
#define internal1_m1509_txMBl	 BUFFER[5509]	//(internal1_m1509_txMBl) tx
#define idinternal1_m1509_txMBl	 1565	//(internal1_m1509_txMBl) tx
#define internal1_m1509_txBl	 BUFFER[5514]	//(internal1_m1509_txBl) tx
#define idinternal1_m1509_txBl	 1566	//(internal1_m1509_txBl) tx
#define internal1_m1509_Speed0	 BUFFER[5519]	//(internal1_m1509_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1509_Speed0	 1567	//(internal1_m1509_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1509_xz0	 BUFFER[5524]	//(internal1_m1509_xz0) xz0 - новое задание мм
#define idinternal1_m1509_xz0	 1568	//(internal1_m1509_xz0) xz0 - новое задание мм
#define internal1_m1509_tz0	 BUFFER[5529]	//(internal1_m1509_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1509_tz0	 1569	//(internal1_m1509_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1509_Shift0	 BUFFER[5534]	//(internal1_m1509_Shift0) Shift0 - признак самохода
#define idinternal1_m1509_Shift0	 1570	//(internal1_m1509_Shift0) Shift0 - признак самохода
#define internal1_m1509_ShCntlSp0	 BUFFER[5536]	//(internal1_m1509_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1509_ShCntlSp0	 1571	//(internal1_m1509_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1509_ShiftControl	 BUFFER[5538]	//(internal1_m1509_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1509_ShiftControl	 1572	//(internal1_m1509_ShiftControl) ShiftControl - признак самохода
#define internal1_m697_q0	 BUFFER[5540]	//(internal1_m697_q0) q0 - внутренний параметр
#define idinternal1_m697_q0	 1573	//(internal1_m697_q0) q0 - внутренний параметр
#define internal1_m1005_X0	 BUFFER[5542]	//(internal1_m1005_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1005_X0	 1574	//(internal1_m1005_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1005_t0	 BUFFER[5547]	//(internal1_m1005_t0) время нахождения в зоне возврата
#define idinternal1_m1005_t0	 1575	//(internal1_m1005_t0) время нахождения в зоне возврата
#define internal1_m1005_BLDv0	 BUFFER[5552]	//(internal1_m1005_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1005_BLDv0	 1576	//(internal1_m1005_BLDv0) BlDv - Блокировка движения
#define internal1_m1028_tx	 BUFFER[5553]	//(internal1_m1028_tx) tx - время накопленное сек
#define idinternal1_m1028_tx	 1577	//(internal1_m1028_tx) tx - время накопленное сек
#define internal1_m1028_y0	 BUFFER[5558]	//(internal1_m1028_y0) y0
#define idinternal1_m1028_y0	 1578	//(internal1_m1028_y0) y0
#define internal1_m1027_tx	 BUFFER[5559]	//(internal1_m1027_tx) tx - время накопленное сек
#define idinternal1_m1027_tx	 1579	//(internal1_m1027_tx) tx - время накопленное сек
#define internal1_m1027_y0	 BUFFER[5564]	//(internal1_m1027_y0) y0
#define idinternal1_m1027_y0	 1580	//(internal1_m1027_y0) y0
#define internal1_m1035_xptr	 BUFFER[5565]	//(internal1_m1035_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1035_xptr	 1581	//(internal1_m1035_xptr) указатель текущей позиции в массиве координат
#define internal1_m1035_x0	 BUFFER[5568]	//(internal1_m1035_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1035_x0	 1582	//(internal1_m1035_x0) x0 - массив мгновенных значений координат
#define internal1_m1035_tim0	 BUFFER[5868]	//(internal1_m1035_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1035_tim0	 1583	//(internal1_m1035_tim0) tim0 - массив значений времени цикла
#define internal1_m1035_sumtim	 BUFFER[6168]	//(internal1_m1035_sumtim) sumtim - время в пути
#define idinternal1_m1035_sumtim	 1584	//(internal1_m1035_sumtim) sumtim - время в пути
#define internal1_m1035_StSpeed	 BUFFER[6173]	//(internal1_m1035_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1035_StSpeed	 1585	//(internal1_m1035_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1035_Vz0	 BUFFER[6178]	//(internal1_m1035_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1035_Vz0	 1586	//(internal1_m1035_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1035_flRazg	 BUFFER[6183]	//(internal1_m1035_flRazg) признак разгона/торможения
#define idinternal1_m1035_flRazg	 1587	//(internal1_m1035_flRazg) признак разгона/торможения
#define internal1_m1035_DelSp	 BUFFER[6186]	//(internal1_m1035_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1035_DelSp	 1588	//(internal1_m1035_DelSp) DelSp - время переключения скоростей
#define internal1_m1035_z0	 BUFFER[6191]	//(internal1_m1035_z0) z0 - точка прекращения движения
#define idinternal1_m1035_z0	 1589	//(internal1_m1035_z0) z0 - точка прекращения движения
#define internal1_m1035_txZS	 BUFFER[6196]	//(internal1_m1035_txZS) txZS
#define idinternal1_m1035_txZS	 1590	//(internal1_m1035_txZS) txZS
#define internal1_m1035_tx	 BUFFER[6201]	//(internal1_m1035_tx) tx
#define idinternal1_m1035_tx	 1591	//(internal1_m1035_tx) tx
#define internal1_m1035_txd	 BUFFER[6206]	//(internal1_m1035_txd) txd
#define idinternal1_m1035_txd	 1592	//(internal1_m1035_txd) txd
#define internal1_m1035_txMBl	 BUFFER[6211]	//(internal1_m1035_txMBl) tx
#define idinternal1_m1035_txMBl	 1593	//(internal1_m1035_txMBl) tx
#define internal1_m1035_txBl	 BUFFER[6216]	//(internal1_m1035_txBl) tx
#define idinternal1_m1035_txBl	 1594	//(internal1_m1035_txBl) tx
#define internal1_m1035_Speed0	 BUFFER[6221]	//(internal1_m1035_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1035_Speed0	 1595	//(internal1_m1035_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1035_xz0	 BUFFER[6226]	//(internal1_m1035_xz0) xz0 - новое задание мм
#define idinternal1_m1035_xz0	 1596	//(internal1_m1035_xz0) xz0 - новое задание мм
#define internal1_m1035_tz0	 BUFFER[6231]	//(internal1_m1035_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1035_tz0	 1597	//(internal1_m1035_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1035_Shift0	 BUFFER[6236]	//(internal1_m1035_Shift0) Shift0 - признак самохода
#define idinternal1_m1035_Shift0	 1598	//(internal1_m1035_Shift0) Shift0 - признак самохода
#define internal1_m1035_ShCntlSp0	 BUFFER[6238]	//(internal1_m1035_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1035_ShCntlSp0	 1599	//(internal1_m1035_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1035_ShiftControl	 BUFFER[6240]	//(internal1_m1035_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1035_ShiftControl	 1600	//(internal1_m1035_ShiftControl) ShiftControl - признак самохода
#define internal1_m550_X0	 BUFFER[6242]	//(internal1_m550_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m550_X0	 1601	//(internal1_m550_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m550_t0	 BUFFER[6247]	//(internal1_m550_t0) время нахождения в зоне возврата
#define idinternal1_m550_t0	 1602	//(internal1_m550_t0) время нахождения в зоне возврата
#define internal1_m550_BLDv0	 BUFFER[6252]	//(internal1_m550_BLDv0) BlDv - Блокировка движения
#define idinternal1_m550_BLDv0	 1603	//(internal1_m550_BLDv0) BlDv - Блокировка движения
#define internal1_m569_tx	 BUFFER[6253]	//(internal1_m569_tx) tx - время накопленное сек
#define idinternal1_m569_tx	 1604	//(internal1_m569_tx) tx - время накопленное сек
#define internal1_m569_y0	 BUFFER[6258]	//(internal1_m569_y0) y0
#define idinternal1_m569_y0	 1605	//(internal1_m569_y0) y0
#define internal1_m568_tx	 BUFFER[6259]	//(internal1_m568_tx) tx - время накопленное сек
#define idinternal1_m568_tx	 1606	//(internal1_m568_tx) tx - время накопленное сек
#define internal1_m568_y0	 BUFFER[6264]	//(internal1_m568_y0) y0
#define idinternal1_m568_y0	 1607	//(internal1_m568_y0) y0
#define internal1_m573_xptr	 BUFFER[6265]	//(internal1_m573_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m573_xptr	 1608	//(internal1_m573_xptr) указатель текущей позиции в массиве координат
#define internal1_m573_x0	 BUFFER[6268]	//(internal1_m573_x0) x0 - массив мгновенных значений координат
#define idinternal1_m573_x0	 1609	//(internal1_m573_x0) x0 - массив мгновенных значений координат
#define internal1_m573_tim0	 BUFFER[7018]	//(internal1_m573_tim0) tim0 - массив значений времени цикла
#define idinternal1_m573_tim0	 1610	//(internal1_m573_tim0) tim0 - массив значений времени цикла
#define internal1_m573_sumtim	 BUFFER[7768]	//(internal1_m573_sumtim) sumtim - время в пути
#define idinternal1_m573_sumtim	 1611	//(internal1_m573_sumtim) sumtim - время в пути
#define internal1_m573_StSpeed	 BUFFER[7773]	//(internal1_m573_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m573_StSpeed	 1612	//(internal1_m573_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m573_Vz0	 BUFFER[7778]	//(internal1_m573_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m573_Vz0	 1613	//(internal1_m573_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m573_flRazg	 BUFFER[7783]	//(internal1_m573_flRazg) признак разгона/торможения
#define idinternal1_m573_flRazg	 1614	//(internal1_m573_flRazg) признак разгона/торможения
#define internal1_m573_DelSp	 BUFFER[7786]	//(internal1_m573_DelSp) DelSp - время переключения скоростей
#define idinternal1_m573_DelSp	 1615	//(internal1_m573_DelSp) DelSp - время переключения скоростей
#define internal1_m573_z0	 BUFFER[7791]	//(internal1_m573_z0) z0 - точка прекращения движения
#define idinternal1_m573_z0	 1616	//(internal1_m573_z0) z0 - точка прекращения движения
#define internal1_m573_txZS	 BUFFER[7796]	//(internal1_m573_txZS) txZS
#define idinternal1_m573_txZS	 1617	//(internal1_m573_txZS) txZS
#define internal1_m573_tx	 BUFFER[7801]	//(internal1_m573_tx) tx
#define idinternal1_m573_tx	 1618	//(internal1_m573_tx) tx
#define internal1_m573_txd	 BUFFER[7806]	//(internal1_m573_txd) txd
#define idinternal1_m573_txd	 1619	//(internal1_m573_txd) txd
#define internal1_m573_txMBl	 BUFFER[7811]	//(internal1_m573_txMBl) tx
#define idinternal1_m573_txMBl	 1620	//(internal1_m573_txMBl) tx
#define internal1_m573_txBl	 BUFFER[7816]	//(internal1_m573_txBl) tx
#define idinternal1_m573_txBl	 1621	//(internal1_m573_txBl) tx
#define internal1_m573_Speed0	 BUFFER[7821]	//(internal1_m573_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m573_Speed0	 1622	//(internal1_m573_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m573_xz0	 BUFFER[7826]	//(internal1_m573_xz0) xz0 - новое задание мм
#define idinternal1_m573_xz0	 1623	//(internal1_m573_xz0) xz0 - новое задание мм
#define internal1_m573_tz0	 BUFFER[7831]	//(internal1_m573_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m573_tz0	 1624	//(internal1_m573_tz0) tz0 - время защиты от нового задания сек
#define internal1_m573_Shift0	 BUFFER[7836]	//(internal1_m573_Shift0) Shift0 - признак самохода
#define idinternal1_m573_Shift0	 1625	//(internal1_m573_Shift0) Shift0 - признак самохода
#define internal1_m573_ShCntlSp0	 BUFFER[7838]	//(internal1_m573_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m573_ShCntlSp0	 1626	//(internal1_m573_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m573_ShiftControl	 BUFFER[7840]	//(internal1_m573_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m573_ShiftControl	 1627	//(internal1_m573_ShiftControl) ShiftControl - признак самохода
#define internal1_m694_q0	 BUFFER[7842]	//(internal1_m694_q0) q0 - внутренний параметр
#define idinternal1_m694_q0	 1628	//(internal1_m694_q0) q0 - внутренний параметр
#define internal1_m176_X0	 BUFFER[7844]	//(internal1_m176_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m176_X0	 1629	//(internal1_m176_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m176_t0	 BUFFER[7849]	//(internal1_m176_t0) время нахождения в зоне возврата
#define idinternal1_m176_t0	 1630	//(internal1_m176_t0) время нахождения в зоне возврата
#define internal1_m176_BLDv0	 BUFFER[7854]	//(internal1_m176_BLDv0) BlDv - Блокировка движения
#define idinternal1_m176_BLDv0	 1631	//(internal1_m176_BLDv0) BlDv - Блокировка движения
#define internal1_m201_xptr	 BUFFER[7855]	//(internal1_m201_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m201_xptr	 1632	//(internal1_m201_xptr) указатель текущей позиции в массиве координат
#define internal1_m201_x0	 BUFFER[7858]	//(internal1_m201_x0) x0 - массив мгновенных значений координат
#define idinternal1_m201_x0	 1633	//(internal1_m201_x0) x0 - массив мгновенных значений координат
#define internal1_m201_tim0	 BUFFER[8608]	//(internal1_m201_tim0) tim0 - массив значений времени цикла
#define idinternal1_m201_tim0	 1634	//(internal1_m201_tim0) tim0 - массив значений времени цикла
#define internal1_m201_sumtim	 BUFFER[9358]	//(internal1_m201_sumtim) sumtim - время в пути
#define idinternal1_m201_sumtim	 1635	//(internal1_m201_sumtim) sumtim - время в пути
#define internal1_m201_StSpeed	 BUFFER[9363]	//(internal1_m201_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m201_StSpeed	 1636	//(internal1_m201_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m201_Vz0	 BUFFER[9368]	//(internal1_m201_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m201_Vz0	 1637	//(internal1_m201_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m201_flRazg	 BUFFER[9373]	//(internal1_m201_flRazg) признак разгона/торможения
#define idinternal1_m201_flRazg	 1638	//(internal1_m201_flRazg) признак разгона/торможения
#define internal1_m201_DelSp	 BUFFER[9376]	//(internal1_m201_DelSp) DelSp - время переключения скоростей
#define idinternal1_m201_DelSp	 1639	//(internal1_m201_DelSp) DelSp - время переключения скоростей
#define internal1_m201_z0	 BUFFER[9381]	//(internal1_m201_z0) z0 - точка прекращения движения
#define idinternal1_m201_z0	 1640	//(internal1_m201_z0) z0 - точка прекращения движения
#define internal1_m201_txZS	 BUFFER[9386]	//(internal1_m201_txZS) txZS
#define idinternal1_m201_txZS	 1641	//(internal1_m201_txZS) txZS
#define internal1_m201_tx	 BUFFER[9391]	//(internal1_m201_tx) tx
#define idinternal1_m201_tx	 1642	//(internal1_m201_tx) tx
#define internal1_m201_txd	 BUFFER[9396]	//(internal1_m201_txd) txd
#define idinternal1_m201_txd	 1643	//(internal1_m201_txd) txd
#define internal1_m201_txMBl	 BUFFER[9401]	//(internal1_m201_txMBl) tx
#define idinternal1_m201_txMBl	 1644	//(internal1_m201_txMBl) tx
#define internal1_m201_txBl	 BUFFER[9406]	//(internal1_m201_txBl) tx
#define idinternal1_m201_txBl	 1645	//(internal1_m201_txBl) tx
#define internal1_m201_Speed0	 BUFFER[9411]	//(internal1_m201_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m201_Speed0	 1646	//(internal1_m201_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m201_xz0	 BUFFER[9416]	//(internal1_m201_xz0) xz0 - новое задание мм
#define idinternal1_m201_xz0	 1647	//(internal1_m201_xz0) xz0 - новое задание мм
#define internal1_m201_tz0	 BUFFER[9421]	//(internal1_m201_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m201_tz0	 1648	//(internal1_m201_tz0) tz0 - время защиты от нового задания сек
#define internal1_m201_Shift0	 BUFFER[9426]	//(internal1_m201_Shift0) Shift0 - признак самохода
#define idinternal1_m201_Shift0	 1649	//(internal1_m201_Shift0) Shift0 - признак самохода
#define internal1_m201_ShCntlSp0	 BUFFER[9428]	//(internal1_m201_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m201_ShCntlSp0	 1650	//(internal1_m201_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m201_ShiftControl	 BUFFER[9430]	//(internal1_m201_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m201_ShiftControl	 1651	//(internal1_m201_ShiftControl) ShiftControl - признак самохода
#define internal1_m720_q0	 BUFFER[9432]	//(internal1_m720_q0) q0 - внутренний параметр
#define idinternal1_m720_q0	 1652	//(internal1_m720_q0) q0 - внутренний параметр
#define internal1_m517_DvUp0	 BUFFER[9434]	//(internal1_m517_DvUp0) - есть команда на движение вперёд
#define idinternal1_m517_DvUp0	 1653	//(internal1_m517_DvUp0) - есть команда на движение вперёд
#define internal1_m517_DvDw0	 BUFFER[9435]	//(internal1_m517_DvDw0) - есть команда на движение назад
#define idinternal1_m517_DvDw0	 1654	//(internal1_m517_DvDw0) - есть команда на движение назад
#define internal1_m517_FDvUp0	 BUFFER[9436]	//(internal1_m517_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m517_FDvUp0	 1655	//(internal1_m517_FDvUp0) - есть команда на движение вперёд
#define internal1_m517_FDvDw0	 BUFFER[9437]	//(internal1_m517_FDvDw0) - есть команда на движение назад
#define idinternal1_m517_FDvDw0	 1656	//(internal1_m517_FDvDw0) - есть команда на движение назад
#define internal1_m517_BlDv0	 BUFFER[9438]	//(internal1_m517_BlDv0) - была блокировка
#define idinternal1_m517_BlDv0	 1657	//(internal1_m517_BlDv0) - была блокировка
#define internal1_m517_Pkv0	 BUFFER[9439]	//(internal1_m517_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m517_Pkv0	 1658	//(internal1_m517_Pkv0) Pkv - передний конечный выключатель
#define internal1_m517_Pkav0	 BUFFER[9440]	//(internal1_m517_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m517_Pkav0	 1659	//(internal1_m517_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m517_Zkv0	 BUFFER[9441]	//(internal1_m517_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m517_Zkv0	 1660	//(internal1_m517_Zkv0) Zkv - задний конечный выключатель
#define internal1_m517_Zkav0	 BUFFER[9442]	//(internal1_m517_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m517_Zkav0	 1661	//(internal1_m517_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m517_txNm	 BUFFER[9443]	//(internal1_m517_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m517_txNm	 1662	//(internal1_m517_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m517_txSm	 BUFFER[9448]	//(internal1_m517_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m517_txSm	 1663	//(internal1_m517_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m517_txHr	 BUFFER[9453]	//(internal1_m517_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m517_txHr	 1664	//(internal1_m517_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m517_txLd	 BUFFER[9458]	//(internal1_m517_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m517_txLd	 1665	//(internal1_m517_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m517_fef	 BUFFER[9463]	//(internal1_m517_fef) fef
#define idinternal1_m517_fef	 1666	//(internal1_m517_fef) fef
#define internal1_m511_DvUp0	 BUFFER[9464]	//(internal1_m511_DvUp0) - есть команда на движение вперёд
#define idinternal1_m511_DvUp0	 1667	//(internal1_m511_DvUp0) - есть команда на движение вперёд
#define internal1_m511_DvDw0	 BUFFER[9465]	//(internal1_m511_DvDw0) - есть команда на движение назад
#define idinternal1_m511_DvDw0	 1668	//(internal1_m511_DvDw0) - есть команда на движение назад
#define internal1_m511_FDvUp0	 BUFFER[9466]	//(internal1_m511_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m511_FDvUp0	 1669	//(internal1_m511_FDvUp0) - есть команда на движение вперёд
#define internal1_m511_FDvDw0	 BUFFER[9467]	//(internal1_m511_FDvDw0) - есть команда на движение назад
#define idinternal1_m511_FDvDw0	 1670	//(internal1_m511_FDvDw0) - есть команда на движение назад
#define internal1_m511_BlDv0	 BUFFER[9468]	//(internal1_m511_BlDv0) - была блокировка
#define idinternal1_m511_BlDv0	 1671	//(internal1_m511_BlDv0) - была блокировка
#define internal1_m511_Pkv0	 BUFFER[9469]	//(internal1_m511_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m511_Pkv0	 1672	//(internal1_m511_Pkv0) Pkv - передний конечный выключатель
#define internal1_m511_Pkav0	 BUFFER[9470]	//(internal1_m511_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m511_Pkav0	 1673	//(internal1_m511_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m511_Zkv0	 BUFFER[9471]	//(internal1_m511_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m511_Zkv0	 1674	//(internal1_m511_Zkv0) Zkv - задний конечный выключатель
#define internal1_m511_Zkav0	 BUFFER[9472]	//(internal1_m511_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m511_Zkav0	 1675	//(internal1_m511_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m511_txNm	 BUFFER[9473]	//(internal1_m511_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m511_txNm	 1676	//(internal1_m511_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m511_txSm	 BUFFER[9478]	//(internal1_m511_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m511_txSm	 1677	//(internal1_m511_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m511_txHr	 BUFFER[9483]	//(internal1_m511_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m511_txHr	 1678	//(internal1_m511_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m511_txLd	 BUFFER[9488]	//(internal1_m511_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m511_txLd	 1679	//(internal1_m511_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m511_fef	 BUFFER[9493]	//(internal1_m511_fef) fef
#define idinternal1_m511_fef	 1680	//(internal1_m511_fef) fef
#define internal1_m909_X0	 BUFFER[9494]	//(internal1_m909_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m909_X0	 1681	//(internal1_m909_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m909_t0	 BUFFER[9499]	//(internal1_m909_t0) время нахождения в зоне возврата
#define idinternal1_m909_t0	 1682	//(internal1_m909_t0) время нахождения в зоне возврата
#define internal1_m909_BLDv0	 BUFFER[9504]	//(internal1_m909_BLDv0) BlDv - Блокировка движения
#define idinternal1_m909_BLDv0	 1683	//(internal1_m909_BLDv0) BlDv - Блокировка движения
#define internal1_m927_xptr	 BUFFER[9505]	//(internal1_m927_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m927_xptr	 1684	//(internal1_m927_xptr) указатель текущей позиции в массиве координат
#define internal1_m927_x0	 BUFFER[9508]	//(internal1_m927_x0) x0 - массив мгновенных значений координат
#define idinternal1_m927_x0	 1685	//(internal1_m927_x0) x0 - массив мгновенных значений координат
#define internal1_m927_tim0	 BUFFER[9908]	//(internal1_m927_tim0) tim0 - массив значений времени цикла
#define idinternal1_m927_tim0	 1686	//(internal1_m927_tim0) tim0 - массив значений времени цикла
#define internal1_m927_sumtim	 BUFFER[10308]	//(internal1_m927_sumtim) sumtim - время в пути
#define idinternal1_m927_sumtim	 1687	//(internal1_m927_sumtim) sumtim - время в пути
#define internal1_m927_StSpeed	 BUFFER[10313]	//(internal1_m927_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m927_StSpeed	 1688	//(internal1_m927_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m927_Vz0	 BUFFER[10318]	//(internal1_m927_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m927_Vz0	 1689	//(internal1_m927_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m927_flRazg	 BUFFER[10323]	//(internal1_m927_flRazg) признак разгона/торможения
#define idinternal1_m927_flRazg	 1690	//(internal1_m927_flRazg) признак разгона/торможения
#define internal1_m927_DelSp	 BUFFER[10326]	//(internal1_m927_DelSp) DelSp - время переключения скоростей
#define idinternal1_m927_DelSp	 1691	//(internal1_m927_DelSp) DelSp - время переключения скоростей
#define internal1_m927_z0	 BUFFER[10331]	//(internal1_m927_z0) z0 - точка прекращения движения
#define idinternal1_m927_z0	 1692	//(internal1_m927_z0) z0 - точка прекращения движения
#define internal1_m927_txZS	 BUFFER[10336]	//(internal1_m927_txZS) txZS
#define idinternal1_m927_txZS	 1693	//(internal1_m927_txZS) txZS
#define internal1_m927_tx	 BUFFER[10341]	//(internal1_m927_tx) tx
#define idinternal1_m927_tx	 1694	//(internal1_m927_tx) tx
#define internal1_m927_txd	 BUFFER[10346]	//(internal1_m927_txd) txd
#define idinternal1_m927_txd	 1695	//(internal1_m927_txd) txd
#define internal1_m927_txMBl	 BUFFER[10351]	//(internal1_m927_txMBl) tx
#define idinternal1_m927_txMBl	 1696	//(internal1_m927_txMBl) tx
#define internal1_m927_txBl	 BUFFER[10356]	//(internal1_m927_txBl) tx
#define idinternal1_m927_txBl	 1697	//(internal1_m927_txBl) tx
#define internal1_m927_Speed0	 BUFFER[10361]	//(internal1_m927_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m927_Speed0	 1698	//(internal1_m927_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m927_xz0	 BUFFER[10366]	//(internal1_m927_xz0) xz0 - новое задание мм
#define idinternal1_m927_xz0	 1699	//(internal1_m927_xz0) xz0 - новое задание мм
#define internal1_m927_tz0	 BUFFER[10371]	//(internal1_m927_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m927_tz0	 1700	//(internal1_m927_tz0) tz0 - время защиты от нового задания сек
#define internal1_m927_Shift0	 BUFFER[10376]	//(internal1_m927_Shift0) Shift0 - признак самохода
#define idinternal1_m927_Shift0	 1701	//(internal1_m927_Shift0) Shift0 - признак самохода
#define internal1_m927_ShCntlSp0	 BUFFER[10378]	//(internal1_m927_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m927_ShCntlSp0	 1702	//(internal1_m927_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m927_ShiftControl	 BUFFER[10380]	//(internal1_m927_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m927_ShiftControl	 1703	//(internal1_m927_ShiftControl) ShiftControl - признак самохода
#define internal1_m1804_X0	 BUFFER[10382]	//(internal1_m1804_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1804_X0	 1704	//(internal1_m1804_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1804_t0	 BUFFER[10387]	//(internal1_m1804_t0) время нахождения в зоне возврата
#define idinternal1_m1804_t0	 1705	//(internal1_m1804_t0) время нахождения в зоне возврата
#define internal1_m1804_BLDv0	 BUFFER[10392]	//(internal1_m1804_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1804_BLDv0	 1706	//(internal1_m1804_BLDv0) BlDv - Блокировка движения
#define internal1_m1273_X0	 BUFFER[10393]	//(internal1_m1273_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1273_X0	 1707	//(internal1_m1273_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1273_t0	 BUFFER[10398]	//(internal1_m1273_t0) время нахождения в зоне возврата
#define idinternal1_m1273_t0	 1708	//(internal1_m1273_t0) время нахождения в зоне возврата
#define internal1_m1273_BLDv0	 BUFFER[10403]	//(internal1_m1273_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1273_BLDv0	 1709	//(internal1_m1273_BLDv0) BlDv - Блокировка движения
#define internal1_m692_q0	 BUFFER[10404]	//(internal1_m692_q0) q0 - внутренний параметр
#define idinternal1_m692_q0	 1710	//(internal1_m692_q0) q0 - внутренний параметр
#define internal1_m1370_X0	 BUFFER[10406]	//(internal1_m1370_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define idinternal1_m1370_X0	 1711	//(internal1_m1370_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
#define internal1_m1370_t0	 BUFFER[10411]	//(internal1_m1370_t0) время нахождения в зоне возврата
#define idinternal1_m1370_t0	 1712	//(internal1_m1370_t0) время нахождения в зоне возврата
#define internal1_m1370_BLDv0	 BUFFER[10416]	//(internal1_m1370_BLDv0) BlDv - Блокировка движения
#define idinternal1_m1370_BLDv0	 1713	//(internal1_m1370_BLDv0) BlDv - Блокировка движения
#define internal1_m1398_tx	 BUFFER[10417]	//(internal1_m1398_tx) tx - время накопленное сек
#define idinternal1_m1398_tx	 1714	//(internal1_m1398_tx) tx - время накопленное сек
#define internal1_m1398_y0	 BUFFER[10422]	//(internal1_m1398_y0) y0
#define idinternal1_m1398_y0	 1715	//(internal1_m1398_y0) y0
#define internal1_m1397_tx	 BUFFER[10423]	//(internal1_m1397_tx) tx - время накопленное сек
#define idinternal1_m1397_tx	 1716	//(internal1_m1397_tx) tx - время накопленное сек
#define internal1_m1397_y0	 BUFFER[10428]	//(internal1_m1397_y0) y0
#define idinternal1_m1397_y0	 1717	//(internal1_m1397_y0) y0
#define internal1_m1405_xptr	 BUFFER[10429]	//(internal1_m1405_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1405_xptr	 1718	//(internal1_m1405_xptr) указатель текущей позиции в массиве координат
#define internal1_m1405_x0	 BUFFER[10432]	//(internal1_m1405_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1405_x0	 1719	//(internal1_m1405_x0) x0 - массив мгновенных значений координат
#define internal1_m1405_tim0	 BUFFER[10832]	//(internal1_m1405_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1405_tim0	 1720	//(internal1_m1405_tim0) tim0 - массив значений времени цикла
#define internal1_m1405_sumtim	 BUFFER[11232]	//(internal1_m1405_sumtim) sumtim - время в пути
#define idinternal1_m1405_sumtim	 1721	//(internal1_m1405_sumtim) sumtim - время в пути
#define internal1_m1405_StSpeed	 BUFFER[11237]	//(internal1_m1405_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1405_StSpeed	 1722	//(internal1_m1405_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1405_Vz0	 BUFFER[11242]	//(internal1_m1405_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1405_Vz0	 1723	//(internal1_m1405_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1405_flRazg	 BUFFER[11247]	//(internal1_m1405_flRazg) признак разгона/торможения
#define idinternal1_m1405_flRazg	 1724	//(internal1_m1405_flRazg) признак разгона/торможения
#define internal1_m1405_DelSp	 BUFFER[11250]	//(internal1_m1405_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1405_DelSp	 1725	//(internal1_m1405_DelSp) DelSp - время переключения скоростей
#define internal1_m1405_z0	 BUFFER[11255]	//(internal1_m1405_z0) z0 - точка прекращения движения
#define idinternal1_m1405_z0	 1726	//(internal1_m1405_z0) z0 - точка прекращения движения
#define internal1_m1405_txZS	 BUFFER[11260]	//(internal1_m1405_txZS) txZS
#define idinternal1_m1405_txZS	 1727	//(internal1_m1405_txZS) txZS
#define internal1_m1405_tx	 BUFFER[11265]	//(internal1_m1405_tx) tx
#define idinternal1_m1405_tx	 1728	//(internal1_m1405_tx) tx
#define internal1_m1405_txd	 BUFFER[11270]	//(internal1_m1405_txd) txd
#define idinternal1_m1405_txd	 1729	//(internal1_m1405_txd) txd
#define internal1_m1405_txMBl	 BUFFER[11275]	//(internal1_m1405_txMBl) tx
#define idinternal1_m1405_txMBl	 1730	//(internal1_m1405_txMBl) tx
#define internal1_m1405_txBl	 BUFFER[11280]	//(internal1_m1405_txBl) tx
#define idinternal1_m1405_txBl	 1731	//(internal1_m1405_txBl) tx
#define internal1_m1405_Speed0	 BUFFER[11285]	//(internal1_m1405_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1405_Speed0	 1732	//(internal1_m1405_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1405_xz0	 BUFFER[11290]	//(internal1_m1405_xz0) xz0 - новое задание мм
#define idinternal1_m1405_xz0	 1733	//(internal1_m1405_xz0) xz0 - новое задание мм
#define internal1_m1405_tz0	 BUFFER[11295]	//(internal1_m1405_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1405_tz0	 1734	//(internal1_m1405_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1405_Shift0	 BUFFER[11300]	//(internal1_m1405_Shift0) Shift0 - признак самохода
#define idinternal1_m1405_Shift0	 1735	//(internal1_m1405_Shift0) Shift0 - признак самохода
#define internal1_m1405_ShCntlSp0	 BUFFER[11302]	//(internal1_m1405_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1405_ShCntlSp0	 1736	//(internal1_m1405_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1405_ShiftControl	 BUFFER[11304]	//(internal1_m1405_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1405_ShiftControl	 1737	//(internal1_m1405_ShiftControl) ShiftControl - признак самохода
#define internal1_m712_q0	 BUFFER[11306]	//(internal1_m712_q0) q0 - внутренний параметр
#define idinternal1_m712_q0	 1738	//(internal1_m712_q0) q0 - внутренний параметр
#define internal1_m1818_tx	 BUFFER[11308]	//(internal1_m1818_tx) tx - время накопленное сек
#define idinternal1_m1818_tx	 1739	//(internal1_m1818_tx) tx - время накопленное сек
#define internal1_m1818_y0	 BUFFER[11313]	//(internal1_m1818_y0) y0
#define idinternal1_m1818_y0	 1740	//(internal1_m1818_y0) y0
#define internal1_m1822_tx	 BUFFER[11314]	//(internal1_m1822_tx) tx - время накопленное сек
#define idinternal1_m1822_tx	 1741	//(internal1_m1822_tx) tx - время накопленное сек
#define internal1_m1822_y0	 BUFFER[11319]	//(internal1_m1822_y0) y0
#define idinternal1_m1822_y0	 1742	//(internal1_m1822_y0) y0
#define internal1_m1807_DvUp0	 BUFFER[11320]	//(internal1_m1807_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1807_DvUp0	 1743	//(internal1_m1807_DvUp0) - есть команда на движение вперёд
#define internal1_m1807_DvDw0	 BUFFER[11321]	//(internal1_m1807_DvDw0) - есть команда на движение назад
#define idinternal1_m1807_DvDw0	 1744	//(internal1_m1807_DvDw0) - есть команда на движение назад
#define internal1_m1807_FDvUp0	 BUFFER[11322]	//(internal1_m1807_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1807_FDvUp0	 1745	//(internal1_m1807_FDvUp0) - есть команда на движение вперёд
#define internal1_m1807_FDvDw0	 BUFFER[11323]	//(internal1_m1807_FDvDw0) - есть команда на движение назад
#define idinternal1_m1807_FDvDw0	 1746	//(internal1_m1807_FDvDw0) - есть команда на движение назад
#define internal1_m1807_BlDv0	 BUFFER[11324]	//(internal1_m1807_BlDv0) - была блокировка
#define idinternal1_m1807_BlDv0	 1747	//(internal1_m1807_BlDv0) - была блокировка
#define internal1_m1807_Pkv0	 BUFFER[11325]	//(internal1_m1807_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1807_Pkv0	 1748	//(internal1_m1807_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1807_Pkav0	 BUFFER[11326]	//(internal1_m1807_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1807_Pkav0	 1749	//(internal1_m1807_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1807_Zkv0	 BUFFER[11327]	//(internal1_m1807_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1807_Zkv0	 1750	//(internal1_m1807_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1807_Zkav0	 BUFFER[11328]	//(internal1_m1807_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1807_Zkav0	 1751	//(internal1_m1807_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1807_txNm	 BUFFER[11329]	//(internal1_m1807_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1807_txNm	 1752	//(internal1_m1807_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1807_txSm	 BUFFER[11334]	//(internal1_m1807_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1807_txSm	 1753	//(internal1_m1807_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1807_txHr	 BUFFER[11339]	//(internal1_m1807_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1807_txHr	 1754	//(internal1_m1807_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1807_txLd	 BUFFER[11344]	//(internal1_m1807_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1807_txLd	 1755	//(internal1_m1807_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1807_fef	 BUFFER[11349]	//(internal1_m1807_fef) fef
#define idinternal1_m1807_fef	 1756	//(internal1_m1807_fef) fef
#define internal1_m1826_xptr	 BUFFER[11350]	//(internal1_m1826_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1826_xptr	 1757	//(internal1_m1826_xptr) указатель текущей позиции в массиве координат
#define internal1_m1826_x0	 BUFFER[11353]	//(internal1_m1826_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1826_x0	 1758	//(internal1_m1826_x0) x0 - массив мгновенных значений координат
#define internal1_m1826_tim0	 BUFFER[11453]	//(internal1_m1826_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1826_tim0	 1759	//(internal1_m1826_tim0) tim0 - массив значений времени цикла
#define internal1_m1826_sumtim	 BUFFER[11553]	//(internal1_m1826_sumtim) sumtim - время в пути
#define idinternal1_m1826_sumtim	 1760	//(internal1_m1826_sumtim) sumtim - время в пути
#define internal1_m1826_StSpeed	 BUFFER[11558]	//(internal1_m1826_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1826_StSpeed	 1761	//(internal1_m1826_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1826_Vz0	 BUFFER[11563]	//(internal1_m1826_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1826_Vz0	 1762	//(internal1_m1826_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1826_flRazg	 BUFFER[11568]	//(internal1_m1826_flRazg) признак разгона/торможения
#define idinternal1_m1826_flRazg	 1763	//(internal1_m1826_flRazg) признак разгона/торможения
#define internal1_m1826_DelSp	 BUFFER[11571]	//(internal1_m1826_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1826_DelSp	 1764	//(internal1_m1826_DelSp) DelSp - время переключения скоростей
#define internal1_m1826_z0	 BUFFER[11576]	//(internal1_m1826_z0) z0 - точка прекращения движения
#define idinternal1_m1826_z0	 1765	//(internal1_m1826_z0) z0 - точка прекращения движения
#define internal1_m1826_txZS	 BUFFER[11581]	//(internal1_m1826_txZS) txZS
#define idinternal1_m1826_txZS	 1766	//(internal1_m1826_txZS) txZS
#define internal1_m1826_tx	 BUFFER[11586]	//(internal1_m1826_tx) tx
#define idinternal1_m1826_tx	 1767	//(internal1_m1826_tx) tx
#define internal1_m1826_txd	 BUFFER[11591]	//(internal1_m1826_txd) txd
#define idinternal1_m1826_txd	 1768	//(internal1_m1826_txd) txd
#define internal1_m1826_txMBl	 BUFFER[11596]	//(internal1_m1826_txMBl) tx
#define idinternal1_m1826_txMBl	 1769	//(internal1_m1826_txMBl) tx
#define internal1_m1826_txBl	 BUFFER[11601]	//(internal1_m1826_txBl) tx
#define idinternal1_m1826_txBl	 1770	//(internal1_m1826_txBl) tx
#define internal1_m1826_Speed0	 BUFFER[11606]	//(internal1_m1826_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1826_Speed0	 1771	//(internal1_m1826_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1826_xz0	 BUFFER[11611]	//(internal1_m1826_xz0) xz0 - новое задание мм
#define idinternal1_m1826_xz0	 1772	//(internal1_m1826_xz0) xz0 - новое задание мм
#define internal1_m1826_tz0	 BUFFER[11616]	//(internal1_m1826_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1826_tz0	 1773	//(internal1_m1826_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1826_Shift0	 BUFFER[11621]	//(internal1_m1826_Shift0) Shift0 - признак самохода
#define idinternal1_m1826_Shift0	 1774	//(internal1_m1826_Shift0) Shift0 - признак самохода
#define internal1_m1826_ShCntlSp0	 BUFFER[11623]	//(internal1_m1826_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1826_ShCntlSp0	 1775	//(internal1_m1826_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1826_ShiftControl	 BUFFER[11625]	//(internal1_m1826_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1826_ShiftControl	 1776	//(internal1_m1826_ShiftControl) ShiftControl - признак самохода
#define internal1_m1290_tx	 BUFFER[11627]	//(internal1_m1290_tx) tx - время накопленное сек
#define idinternal1_m1290_tx	 1777	//(internal1_m1290_tx) tx - время накопленное сек
#define internal1_m1290_y0	 BUFFER[11632]	//(internal1_m1290_y0) y0
#define idinternal1_m1290_y0	 1778	//(internal1_m1290_y0) y0
#define internal1_m1294_tx	 BUFFER[11633]	//(internal1_m1294_tx) tx - время накопленное сек
#define idinternal1_m1294_tx	 1779	//(internal1_m1294_tx) tx - время накопленное сек
#define internal1_m1294_y0	 BUFFER[11638]	//(internal1_m1294_y0) y0
#define idinternal1_m1294_y0	 1780	//(internal1_m1294_y0) y0
#define internal1_m702_q0	 BUFFER[11639]	//(internal1_m702_q0) q0 - внутренний параметр
#define idinternal1_m702_q0	 1781	//(internal1_m702_q0) q0 - внутренний параметр
#define internal1_m667_q0	 BUFFER[11641]	//(internal1_m667_q0) q0 - внутренний параметр
#define idinternal1_m667_q0	 1782	//(internal1_m667_q0) q0 - внутренний параметр
#define internal1_m1281_DvUp0	 BUFFER[11643]	//(internal1_m1281_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1281_DvUp0	 1783	//(internal1_m1281_DvUp0) - есть команда на движение вперёд
#define internal1_m1281_DvDw0	 BUFFER[11644]	//(internal1_m1281_DvDw0) - есть команда на движение назад
#define idinternal1_m1281_DvDw0	 1784	//(internal1_m1281_DvDw0) - есть команда на движение назад
#define internal1_m1281_FDvUp0	 BUFFER[11645]	//(internal1_m1281_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1281_FDvUp0	 1785	//(internal1_m1281_FDvUp0) - есть команда на движение вперёд
#define internal1_m1281_FDvDw0	 BUFFER[11646]	//(internal1_m1281_FDvDw0) - есть команда на движение назад
#define idinternal1_m1281_FDvDw0	 1786	//(internal1_m1281_FDvDw0) - есть команда на движение назад
#define internal1_m1281_BlDv0	 BUFFER[11647]	//(internal1_m1281_BlDv0) - была блокировка
#define idinternal1_m1281_BlDv0	 1787	//(internal1_m1281_BlDv0) - была блокировка
#define internal1_m1281_Pkv0	 BUFFER[11648]	//(internal1_m1281_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1281_Pkv0	 1788	//(internal1_m1281_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1281_Pkav0	 BUFFER[11649]	//(internal1_m1281_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1281_Pkav0	 1789	//(internal1_m1281_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1281_Zkv0	 BUFFER[11650]	//(internal1_m1281_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1281_Zkv0	 1790	//(internal1_m1281_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1281_Zkav0	 BUFFER[11651]	//(internal1_m1281_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1281_Zkav0	 1791	//(internal1_m1281_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1281_txNm	 BUFFER[11652]	//(internal1_m1281_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1281_txNm	 1792	//(internal1_m1281_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1281_txSm	 BUFFER[11657]	//(internal1_m1281_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1281_txSm	 1793	//(internal1_m1281_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1281_txHr	 BUFFER[11662]	//(internal1_m1281_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1281_txHr	 1794	//(internal1_m1281_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1281_txLd	 BUFFER[11667]	//(internal1_m1281_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1281_txLd	 1795	//(internal1_m1281_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1281_fef	 BUFFER[11672]	//(internal1_m1281_fef) fef
#define idinternal1_m1281_fef	 1796	//(internal1_m1281_fef) fef
#define internal1_m1300_xptr	 BUFFER[11673]	//(internal1_m1300_xptr) указатель текущей позиции в массиве координат
#define idinternal1_m1300_xptr	 1797	//(internal1_m1300_xptr) указатель текущей позиции в массиве координат
#define internal1_m1300_x0	 BUFFER[11676]	//(internal1_m1300_x0) x0 - массив мгновенных значений координат
#define idinternal1_m1300_x0	 1798	//(internal1_m1300_x0) x0 - массив мгновенных значений координат
#define internal1_m1300_tim0	 BUFFER[11776]	//(internal1_m1300_tim0) tim0 - массив значений времени цикла
#define idinternal1_m1300_tim0	 1799	//(internal1_m1300_tim0) tim0 - массив значений времени цикла
#define internal1_m1300_sumtim	 BUFFER[11876]	//(internal1_m1300_sumtim) sumtim - время в пути
#define idinternal1_m1300_sumtim	 1800	//(internal1_m1300_sumtim) sumtim - время в пути
#define internal1_m1300_StSpeed	 BUFFER[11881]	//(internal1_m1300_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define idinternal1_m1300_StSpeed	 1801	//(internal1_m1300_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
#define internal1_m1300_Vz0	 BUFFER[11886]	//(internal1_m1300_Vz0) Vz0 - предыдущая заданная скорость
#define idinternal1_m1300_Vz0	 1802	//(internal1_m1300_Vz0) Vz0 - предыдущая заданная скорость
#define internal1_m1300_flRazg	 BUFFER[11891]	//(internal1_m1300_flRazg) признак разгона/торможения
#define idinternal1_m1300_flRazg	 1803	//(internal1_m1300_flRazg) признак разгона/торможения
#define internal1_m1300_DelSp	 BUFFER[11894]	//(internal1_m1300_DelSp) DelSp - время переключения скоростей
#define idinternal1_m1300_DelSp	 1804	//(internal1_m1300_DelSp) DelSp - время переключения скоростей
#define internal1_m1300_z0	 BUFFER[11899]	//(internal1_m1300_z0) z0 - точка прекращения движения
#define idinternal1_m1300_z0	 1805	//(internal1_m1300_z0) z0 - точка прекращения движения
#define internal1_m1300_txZS	 BUFFER[11904]	//(internal1_m1300_txZS) txZS
#define idinternal1_m1300_txZS	 1806	//(internal1_m1300_txZS) txZS
#define internal1_m1300_tx	 BUFFER[11909]	//(internal1_m1300_tx) tx
#define idinternal1_m1300_tx	 1807	//(internal1_m1300_tx) tx
#define internal1_m1300_txd	 BUFFER[11914]	//(internal1_m1300_txd) txd
#define idinternal1_m1300_txd	 1808	//(internal1_m1300_txd) txd
#define internal1_m1300_txMBl	 BUFFER[11919]	//(internal1_m1300_txMBl) tx
#define idinternal1_m1300_txMBl	 1809	//(internal1_m1300_txMBl) tx
#define internal1_m1300_txBl	 BUFFER[11924]	//(internal1_m1300_txBl) tx
#define idinternal1_m1300_txBl	 1810	//(internal1_m1300_txBl) tx
#define internal1_m1300_Speed0	 BUFFER[11929]	//(internal1_m1300_Speed0) Speed0 - предыдущее значение скорости перемещения
#define idinternal1_m1300_Speed0	 1811	//(internal1_m1300_Speed0) Speed0 - предыдущее значение скорости перемещения
#define internal1_m1300_xz0	 BUFFER[11934]	//(internal1_m1300_xz0) xz0 - новое задание мм
#define idinternal1_m1300_xz0	 1812	//(internal1_m1300_xz0) xz0 - новое задание мм
#define internal1_m1300_tz0	 BUFFER[11939]	//(internal1_m1300_tz0) tz0 - время защиты от нового задания сек
#define idinternal1_m1300_tz0	 1813	//(internal1_m1300_tz0) tz0 - время защиты от нового задания сек
#define internal1_m1300_Shift0	 BUFFER[11944]	//(internal1_m1300_Shift0) Shift0 - признак самохода
#define idinternal1_m1300_Shift0	 1814	//(internal1_m1300_Shift0) Shift0 - признак самохода
#define internal1_m1300_ShCntlSp0	 BUFFER[11946]	//(internal1_m1300_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define idinternal1_m1300_ShCntlSp0	 1815	//(internal1_m1300_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
#define internal1_m1300_ShiftControl	 BUFFER[11948]	//(internal1_m1300_ShiftControl) ShiftControl - признак самохода
#define idinternal1_m1300_ShiftControl	 1816	//(internal1_m1300_ShiftControl) ShiftControl - признак самохода
#define internal1_m830_x0	 BUFFER[11950]	//(internal1_m830_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m830_x0	 1817	//(internal1_m830_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m799_x0	 BUFFER[11952]	//(internal1_m799_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m799_x0	 1818	//(internal1_m799_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m741_x0	 BUFFER[11954]	//(internal1_m741_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m741_x0	 1819	//(internal1_m741_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m855_q0	 BUFFER[11956]	//(internal1_m855_q0) q0 - внутренний параметр
#define idinternal1_m855_q0	 1820	//(internal1_m855_q0) q0 - внутренний параметр
#define internal1_m850_q0	 BUFFER[11958]	//(internal1_m850_q0) q0 - внутренний параметр
#define idinternal1_m850_q0	 1821	//(internal1_m850_q0) q0 - внутренний параметр
#define internal1_m818_q0	 BUFFER[11960]	//(internal1_m818_q0) q0 - внутренний параметр
#define idinternal1_m818_q0	 1822	//(internal1_m818_q0) q0 - внутренний параметр
#define internal1_m822_q0	 BUFFER[11962]	//(internal1_m822_q0) q0 - внутренний параметр
#define idinternal1_m822_q0	 1823	//(internal1_m822_q0) q0 - внутренний параметр
#define internal1_m831_q0	 BUFFER[11964]	//(internal1_m831_q0) q0 - внутренний параметр
#define idinternal1_m831_q0	 1824	//(internal1_m831_q0) q0 - внутренний параметр
#define internal1_m843_q0	 BUFFER[11966]	//(internal1_m843_q0) q0 - внутренний параметр
#define idinternal1_m843_q0	 1825	//(internal1_m843_q0) q0 - внутренний параметр
#define internal1_m820_q0	 BUFFER[11968]	//(internal1_m820_q0) q0 - внутренний параметр
#define idinternal1_m820_q0	 1826	//(internal1_m820_q0) q0 - внутренний параметр
#define internal1_m1343_DvUp0	 BUFFER[11970]	//(internal1_m1343_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1343_DvUp0	 1827	//(internal1_m1343_DvUp0) - есть команда на движение вперёд
#define internal1_m1343_DvDw0	 BUFFER[11971]	//(internal1_m1343_DvDw0) - есть команда на движение назад
#define idinternal1_m1343_DvDw0	 1828	//(internal1_m1343_DvDw0) - есть команда на движение назад
#define internal1_m1343_FDvUp0	 BUFFER[11972]	//(internal1_m1343_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1343_FDvUp0	 1829	//(internal1_m1343_FDvUp0) - есть команда на движение вперёд
#define internal1_m1343_FDvDw0	 BUFFER[11973]	//(internal1_m1343_FDvDw0) - есть команда на движение назад
#define idinternal1_m1343_FDvDw0	 1830	//(internal1_m1343_FDvDw0) - есть команда на движение назад
#define internal1_m1343_BlDv0	 BUFFER[11974]	//(internal1_m1343_BlDv0) - была блокировка
#define idinternal1_m1343_BlDv0	 1831	//(internal1_m1343_BlDv0) - была блокировка
#define internal1_m1343_Pkv0	 BUFFER[11975]	//(internal1_m1343_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1343_Pkv0	 1832	//(internal1_m1343_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1343_Pkav0	 BUFFER[11976]	//(internal1_m1343_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1343_Pkav0	 1833	//(internal1_m1343_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1343_Zkv0	 BUFFER[11977]	//(internal1_m1343_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1343_Zkv0	 1834	//(internal1_m1343_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1343_Zkav0	 BUFFER[11978]	//(internal1_m1343_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1343_Zkav0	 1835	//(internal1_m1343_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1343_txNm	 BUFFER[11979]	//(internal1_m1343_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1343_txNm	 1836	//(internal1_m1343_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1343_txSm	 BUFFER[11984]	//(internal1_m1343_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1343_txSm	 1837	//(internal1_m1343_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1343_txHr	 BUFFER[11989]	//(internal1_m1343_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1343_txHr	 1838	//(internal1_m1343_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1343_txLd	 BUFFER[11994]	//(internal1_m1343_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1343_txLd	 1839	//(internal1_m1343_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1343_fef	 BUFFER[11999]	//(internal1_m1343_fef) fef
#define idinternal1_m1343_fef	 1840	//(internal1_m1343_fef) fef
#define internal1_m1333_DvUp0	 BUFFER[12000]	//(internal1_m1333_DvUp0) - есть команда на движение вперёд
#define idinternal1_m1333_DvUp0	 1841	//(internal1_m1333_DvUp0) - есть команда на движение вперёд
#define internal1_m1333_DvDw0	 BUFFER[12001]	//(internal1_m1333_DvDw0) - есть команда на движение назад
#define idinternal1_m1333_DvDw0	 1842	//(internal1_m1333_DvDw0) - есть команда на движение назад
#define internal1_m1333_FDvUp0	 BUFFER[12002]	//(internal1_m1333_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m1333_FDvUp0	 1843	//(internal1_m1333_FDvUp0) - есть команда на движение вперёд
#define internal1_m1333_FDvDw0	 BUFFER[12003]	//(internal1_m1333_FDvDw0) - есть команда на движение назад
#define idinternal1_m1333_FDvDw0	 1844	//(internal1_m1333_FDvDw0) - есть команда на движение назад
#define internal1_m1333_BlDv0	 BUFFER[12004]	//(internal1_m1333_BlDv0) - была блокировка
#define idinternal1_m1333_BlDv0	 1845	//(internal1_m1333_BlDv0) - была блокировка
#define internal1_m1333_Pkv0	 BUFFER[12005]	//(internal1_m1333_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m1333_Pkv0	 1846	//(internal1_m1333_Pkv0) Pkv - передний конечный выключатель
#define internal1_m1333_Pkav0	 BUFFER[12006]	//(internal1_m1333_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m1333_Pkav0	 1847	//(internal1_m1333_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m1333_Zkv0	 BUFFER[12007]	//(internal1_m1333_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m1333_Zkv0	 1848	//(internal1_m1333_Zkv0) Zkv - задний конечный выключатель
#define internal1_m1333_Zkav0	 BUFFER[12008]	//(internal1_m1333_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m1333_Zkav0	 1849	//(internal1_m1333_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m1333_txNm	 BUFFER[12009]	//(internal1_m1333_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m1333_txNm	 1850	//(internal1_m1333_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m1333_txSm	 BUFFER[12014]	//(internal1_m1333_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m1333_txSm	 1851	//(internal1_m1333_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m1333_txHr	 BUFFER[12019]	//(internal1_m1333_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m1333_txHr	 1852	//(internal1_m1333_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m1333_txLd	 BUFFER[12024]	//(internal1_m1333_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m1333_txLd	 1853	//(internal1_m1333_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m1333_fef	 BUFFER[12029]	//(internal1_m1333_fef) fef
#define idinternal1_m1333_fef	 1854	//(internal1_m1333_fef) fef
#define internal1_m879_DvUp0	 BUFFER[12030]	//(internal1_m879_DvUp0) - есть команда на движение вперёд
#define idinternal1_m879_DvUp0	 1855	//(internal1_m879_DvUp0) - есть команда на движение вперёд
#define internal1_m879_DvDw0	 BUFFER[12031]	//(internal1_m879_DvDw0) - есть команда на движение назад
#define idinternal1_m879_DvDw0	 1856	//(internal1_m879_DvDw0) - есть команда на движение назад
#define internal1_m879_FDvUp0	 BUFFER[12032]	//(internal1_m879_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m879_FDvUp0	 1857	//(internal1_m879_FDvUp0) - есть команда на движение вперёд
#define internal1_m879_FDvDw0	 BUFFER[12033]	//(internal1_m879_FDvDw0) - есть команда на движение назад
#define idinternal1_m879_FDvDw0	 1858	//(internal1_m879_FDvDw0) - есть команда на движение назад
#define internal1_m879_BlDv0	 BUFFER[12034]	//(internal1_m879_BlDv0) - была блокировка
#define idinternal1_m879_BlDv0	 1859	//(internal1_m879_BlDv0) - была блокировка
#define internal1_m879_Pkv0	 BUFFER[12035]	//(internal1_m879_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m879_Pkv0	 1860	//(internal1_m879_Pkv0) Pkv - передний конечный выключатель
#define internal1_m879_Pkav0	 BUFFER[12036]	//(internal1_m879_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m879_Pkav0	 1861	//(internal1_m879_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m879_Zkv0	 BUFFER[12037]	//(internal1_m879_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m879_Zkv0	 1862	//(internal1_m879_Zkv0) Zkv - задний конечный выключатель
#define internal1_m879_Zkav0	 BUFFER[12038]	//(internal1_m879_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m879_Zkav0	 1863	//(internal1_m879_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m879_txNm	 BUFFER[12039]	//(internal1_m879_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m879_txNm	 1864	//(internal1_m879_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m879_txSm	 BUFFER[12044]	//(internal1_m879_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m879_txSm	 1865	//(internal1_m879_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m879_txHr	 BUFFER[12049]	//(internal1_m879_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m879_txHr	 1866	//(internal1_m879_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m879_txLd	 BUFFER[12054]	//(internal1_m879_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m879_txLd	 1867	//(internal1_m879_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m879_fef	 BUFFER[12059]	//(internal1_m879_fef) fef
#define idinternal1_m879_fef	 1868	//(internal1_m879_fef) fef
#define internal1_m875_DvUp0	 BUFFER[12060]	//(internal1_m875_DvUp0) - есть команда на движение вперёд
#define idinternal1_m875_DvUp0	 1869	//(internal1_m875_DvUp0) - есть команда на движение вперёд
#define internal1_m875_DvDw0	 BUFFER[12061]	//(internal1_m875_DvDw0) - есть команда на движение назад
#define idinternal1_m875_DvDw0	 1870	//(internal1_m875_DvDw0) - есть команда на движение назад
#define internal1_m875_FDvUp0	 BUFFER[12062]	//(internal1_m875_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m875_FDvUp0	 1871	//(internal1_m875_FDvUp0) - есть команда на движение вперёд
#define internal1_m875_FDvDw0	 BUFFER[12063]	//(internal1_m875_FDvDw0) - есть команда на движение назад
#define idinternal1_m875_FDvDw0	 1872	//(internal1_m875_FDvDw0) - есть команда на движение назад
#define internal1_m875_BlDv0	 BUFFER[12064]	//(internal1_m875_BlDv0) - была блокировка
#define idinternal1_m875_BlDv0	 1873	//(internal1_m875_BlDv0) - была блокировка
#define internal1_m875_Pkv0	 BUFFER[12065]	//(internal1_m875_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m875_Pkv0	 1874	//(internal1_m875_Pkv0) Pkv - передний конечный выключатель
#define internal1_m875_Pkav0	 BUFFER[12066]	//(internal1_m875_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m875_Pkav0	 1875	//(internal1_m875_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m875_Zkv0	 BUFFER[12067]	//(internal1_m875_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m875_Zkv0	 1876	//(internal1_m875_Zkv0) Zkv - задний конечный выключатель
#define internal1_m875_Zkav0	 BUFFER[12068]	//(internal1_m875_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m875_Zkav0	 1877	//(internal1_m875_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m875_txNm	 BUFFER[12069]	//(internal1_m875_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m875_txNm	 1878	//(internal1_m875_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m875_txSm	 BUFFER[12074]	//(internal1_m875_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m875_txSm	 1879	//(internal1_m875_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m875_txHr	 BUFFER[12079]	//(internal1_m875_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m875_txHr	 1880	//(internal1_m875_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m875_txLd	 BUFFER[12084]	//(internal1_m875_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m875_txLd	 1881	//(internal1_m875_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m875_fef	 BUFFER[12089]	//(internal1_m875_fef) fef
#define idinternal1_m875_fef	 1882	//(internal1_m875_fef) fef
#define internal1_m390_DvUp0	 BUFFER[12090]	//(internal1_m390_DvUp0) - есть команда на движение вперёд
#define idinternal1_m390_DvUp0	 1883	//(internal1_m390_DvUp0) - есть команда на движение вперёд
#define internal1_m390_DvDw0	 BUFFER[12091]	//(internal1_m390_DvDw0) - есть команда на движение назад
#define idinternal1_m390_DvDw0	 1884	//(internal1_m390_DvDw0) - есть команда на движение назад
#define internal1_m390_FDvUp0	 BUFFER[12092]	//(internal1_m390_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m390_FDvUp0	 1885	//(internal1_m390_FDvUp0) - есть команда на движение вперёд
#define internal1_m390_FDvDw0	 BUFFER[12093]	//(internal1_m390_FDvDw0) - есть команда на движение назад
#define idinternal1_m390_FDvDw0	 1886	//(internal1_m390_FDvDw0) - есть команда на движение назад
#define internal1_m390_BlDv0	 BUFFER[12094]	//(internal1_m390_BlDv0) - была блокировка
#define idinternal1_m390_BlDv0	 1887	//(internal1_m390_BlDv0) - была блокировка
#define internal1_m390_Pkv0	 BUFFER[12095]	//(internal1_m390_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m390_Pkv0	 1888	//(internal1_m390_Pkv0) Pkv - передний конечный выключатель
#define internal1_m390_Pkav0	 BUFFER[12096]	//(internal1_m390_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m390_Pkav0	 1889	//(internal1_m390_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m390_Zkv0	 BUFFER[12097]	//(internal1_m390_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m390_Zkv0	 1890	//(internal1_m390_Zkv0) Zkv - задний конечный выключатель
#define internal1_m390_Zkav0	 BUFFER[12098]	//(internal1_m390_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m390_Zkav0	 1891	//(internal1_m390_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m390_txNm	 BUFFER[12099]	//(internal1_m390_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m390_txNm	 1892	//(internal1_m390_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m390_txSm	 BUFFER[12104]	//(internal1_m390_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m390_txSm	 1893	//(internal1_m390_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m390_txHr	 BUFFER[12109]	//(internal1_m390_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m390_txHr	 1894	//(internal1_m390_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m390_txLd	 BUFFER[12114]	//(internal1_m390_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m390_txLd	 1895	//(internal1_m390_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m390_fef	 BUFFER[12119]	//(internal1_m390_fef) fef
#define idinternal1_m390_fef	 1896	//(internal1_m390_fef) fef
#define internal1_m427_DvUp0	 BUFFER[12120]	//(internal1_m427_DvUp0) - есть команда на движение вперёд
#define idinternal1_m427_DvUp0	 1897	//(internal1_m427_DvUp0) - есть команда на движение вперёд
#define internal1_m427_DvDw0	 BUFFER[12121]	//(internal1_m427_DvDw0) - есть команда на движение назад
#define idinternal1_m427_DvDw0	 1898	//(internal1_m427_DvDw0) - есть команда на движение назад
#define internal1_m427_FDvUp0	 BUFFER[12122]	//(internal1_m427_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m427_FDvUp0	 1899	//(internal1_m427_FDvUp0) - есть команда на движение вперёд
#define internal1_m427_FDvDw0	 BUFFER[12123]	//(internal1_m427_FDvDw0) - есть команда на движение назад
#define idinternal1_m427_FDvDw0	 1900	//(internal1_m427_FDvDw0) - есть команда на движение назад
#define internal1_m427_BlDv0	 BUFFER[12124]	//(internal1_m427_BlDv0) - была блокировка
#define idinternal1_m427_BlDv0	 1901	//(internal1_m427_BlDv0) - была блокировка
#define internal1_m427_Pkv0	 BUFFER[12125]	//(internal1_m427_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m427_Pkv0	 1902	//(internal1_m427_Pkv0) Pkv - передний конечный выключатель
#define internal1_m427_Pkav0	 BUFFER[12126]	//(internal1_m427_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m427_Pkav0	 1903	//(internal1_m427_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m427_Zkv0	 BUFFER[12127]	//(internal1_m427_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m427_Zkv0	 1904	//(internal1_m427_Zkv0) Zkv - задний конечный выключатель
#define internal1_m427_Zkav0	 BUFFER[12128]	//(internal1_m427_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m427_Zkav0	 1905	//(internal1_m427_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m427_txNm	 BUFFER[12129]	//(internal1_m427_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m427_txNm	 1906	//(internal1_m427_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m427_txSm	 BUFFER[12134]	//(internal1_m427_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m427_txSm	 1907	//(internal1_m427_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m427_txHr	 BUFFER[12139]	//(internal1_m427_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m427_txHr	 1908	//(internal1_m427_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m427_txLd	 BUFFER[12144]	//(internal1_m427_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m427_txLd	 1909	//(internal1_m427_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m427_fef	 BUFFER[12149]	//(internal1_m427_fef) fef
#define idinternal1_m427_fef	 1910	//(internal1_m427_fef) fef
#define internal1_m421_DvUp0	 BUFFER[12150]	//(internal1_m421_DvUp0) - есть команда на движение вперёд
#define idinternal1_m421_DvUp0	 1911	//(internal1_m421_DvUp0) - есть команда на движение вперёд
#define internal1_m421_DvDw0	 BUFFER[12151]	//(internal1_m421_DvDw0) - есть команда на движение назад
#define idinternal1_m421_DvDw0	 1912	//(internal1_m421_DvDw0) - есть команда на движение назад
#define internal1_m421_FDvUp0	 BUFFER[12152]	//(internal1_m421_FDvUp0) - есть команда на движение вперёд
#define idinternal1_m421_FDvUp0	 1913	//(internal1_m421_FDvUp0) - есть команда на движение вперёд
#define internal1_m421_FDvDw0	 BUFFER[12153]	//(internal1_m421_FDvDw0) - есть команда на движение назад
#define idinternal1_m421_FDvDw0	 1914	//(internal1_m421_FDvDw0) - есть команда на движение назад
#define internal1_m421_BlDv0	 BUFFER[12154]	//(internal1_m421_BlDv0) - была блокировка
#define idinternal1_m421_BlDv0	 1915	//(internal1_m421_BlDv0) - была блокировка
#define internal1_m421_Pkv0	 BUFFER[12155]	//(internal1_m421_Pkv0) Pkv - передний конечный выключатель
#define idinternal1_m421_Pkv0	 1916	//(internal1_m421_Pkv0) Pkv - передний конечный выключатель
#define internal1_m421_Pkav0	 BUFFER[12156]	//(internal1_m421_Pkav0) Pkav - передний конечный аварийный выключатель
#define idinternal1_m421_Pkav0	 1917	//(internal1_m421_Pkav0) Pkav - передний конечный аварийный выключатель
#define internal1_m421_Zkv0	 BUFFER[12157]	//(internal1_m421_Zkv0) Zkv - задний конечный выключатель
#define idinternal1_m421_Zkv0	 1918	//(internal1_m421_Zkv0) Zkv - задний конечный выключатель
#define internal1_m421_Zkav0	 BUFFER[12158]	//(internal1_m421_Zkav0) Zkav - задний конечный аварийный выключатель
#define idinternal1_m421_Zkav0	 1919	//(internal1_m421_Zkav0) Zkav - задний конечный аварийный выключатель
#define internal1_m421_txNm	 BUFFER[12159]	//(internal1_m421_txNm) txNm - счётчик задержки сигнализации недвижения
#define idinternal1_m421_txNm	 1920	//(internal1_m421_txNm) txNm - счётчик задержки сигнализации недвижения
#define internal1_m421_txSm	 BUFFER[12164]	//(internal1_m421_txSm) txSm - счётчик задержки сигнализации самохода
#define idinternal1_m421_txSm	 1921	//(internal1_m421_txSm) txSm - счётчик задержки сигнализации самохода
#define internal1_m421_txHr	 BUFFER[12169]	//(internal1_m421_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define idinternal1_m421_txHr	 1922	//(internal1_m421_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
#define internal1_m421_txLd	 BUFFER[12174]	//(internal1_m421_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define idinternal1_m421_txLd	 1923	//(internal1_m421_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
#define internal1_m421_fef	 BUFFER[12179]	//(internal1_m421_fef) fef
#define idinternal1_m421_fef	 1924	//(internal1_m421_fef) fef
#define internal1_m827_q0	 BUFFER[12180]	//(internal1_m827_q0) q0 - внутренний параметр
#define idinternal1_m827_q0	 1925	//(internal1_m827_q0) q0 - внутренний параметр
#define internal1_m824_q0	 BUFFER[12182]	//(internal1_m824_q0) q0 - внутренний параметр
#define idinternal1_m824_q0	 1926	//(internal1_m824_q0) q0 - внутренний параметр
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &R6IS52LDU},	//(vds32:05 - K30VDSR, - ) контроль передней двери ШПУ
	{ 2	,1	,1	, &R6IS51LDU},	//(vds32:05 - K29VDSR, - ) контроль задней двери ШПУ
	{ 3	,1	,1	, &R3IS11LDU},	//(vds32:04 - K17VDSR, DU) Приход на ВУ гомогенных дверей
	{ 4	,1	,1	, &R3IS21LDU},	//(vds32:04 - K18VDSR, DU) Приход на НУ гомогенных дверей
	{ 5	,1	,1	, &R0AB03LDU},	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
	{ 6	,1	,1	, &R0AB05LDU},	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
	{ 7	,8	,1	, &R0VN11RZ1},	//( - , MDuBz1) Средняя мощность по BAZ1
	{ 8	,8	,1	, &R0VN11RZ2},	//( - , MDuBz2) Средняя мощность по BAZ2
	{ 9	,1	,1	, &A2AB15LDU},	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 10	,1	,1	, &B2AB15LDU},	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{ 11	,1	,1	, &R0AD21LDU},	//( - , MDuBz1, MDuBz2) Подключить защиту от II УР
	{ 12	,1	,1	, &R0VX02LDU},	//( - , DU) Импульс разрешен
	{ 13	,1	,1	, &R0EE03LDU},	//( - , DU) ВПИС ИС
	{ 14	,1	,1	, &R0AB07LDU},	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{ 15	,1	,1	, &C2MD31LP1},	//( - , DU) Кнопка СБРОС РБ
	{ 16	,3	,1	, &B6VS01IDU},	//( - , DU) Готовность к управлению БЗ2
	{ 17	,1	,1	, &R2AD20LDU},	//(fds16:0a - K10FDSR, - ) Поднять МДЗ2
	{ 18	,1	,1	, &R2AD10LDU},	//(fds16:0a - K09FDSR, - ) Опустить МДЗ2
	{ 19	,3	,1	, &B8VS01IDU},	//( - , DU) Готовность к управлению АЗ2
	{ 20	,3	,1	, &A8VS01IDU},	//( - , DU) Готовность к управлению ДС2
	{ 21	,1	,1	, &A1IE03LDU},	//(vds32:05 - K03VDSR, - ) Движение ББ1 вперед (от БУШД)
	{ 22	,1	,1	, &A1IE04LDU},	//(vds32:05 - K04VDSR, - ) Движение ББ1 назад (от БУШД)
	{ 23	,1	,1	, &A2IE03LDU},	//(vds32:05 - K07VDSR, - ) Движение РБ1 вперед (от БУШД)
	{ 24	,1	,1	, &A2IS33LDU},	//(vds32:03 - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	{ 25	,1	,1	, &A3IS31LDU},	//(vds32:03 - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	{ 26	,1	,1	, &A3IS33LDU},	//(vds32:03 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	{ 27	,1	,1	, &A3IS35LDU},	//(vds32:03 - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	{ 28	,1	,1	, &A4IS10LDU},	//(vds32:03 - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	{ 29	,1	,1	, &A1VN71LZ1},	//(vds32:02 - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{ 30	,1	,1	, &A1VN71LZ2},	//(vds32:03 - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{ 31	,1	,1	, &A1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{ 32	,1	,1	, &R0AD14LZ1},	//(vds32:02 - K20VDSR, DU) Имитация срабатывания АЗ от II УР
	{ 33	,1	,1	, &R0AD14LZ2},	//(vds32:03 - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	{ 34	,1	,1	, &A3VZ13LZ2},	//(vds32:03 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{ 35	,1	,1	, &A3VZ13LZ1},	//(vds32:02 - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{ 36	,1	,1	, &A3VZ15LZ1},	//(vds32:02 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{ 37	,1	,1	, &A3VZ15LZ2},	//(vds32:03 - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{ 38	,1	,1	, &B2IS33LDU},	//(vds32:02 - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
	{ 39	,1	,1	, &B3IS31LDU},	//(vds32:02 - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
	{ 40	,1	,1	, &B3IS33LDU},	//(vds32:02 - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
	{ 41	,1	,1	, &B3IS35LDU},	//(vds32:02 - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
	{ 42	,1	,1	, &B4IS10LDU},	//(vds32:02 - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
	{ 43	,1	,1	, &R6IS31LDU},	//(vds32:05 - K25VDSR, - ) контроль задней двери ШС
	{ 44	,1	,1	, &R6IS32LDU},	//(vds32:05 - K26VDSR, - ) контроль передней двери ШС
	{ 45	,1	,1	, &R6IS42LDU},	//(vds32:05 - K28VDSR, - ) контроль передней двери ШЭП
	{ 46	,1	,1	, &R6IS41LDU},	//(vds32:05 - K27VDSR, - ) контроль задней двери ШЭП
	{ 47	,1	,1	, &A6ZAV},	//( - , DU) 
	{ 48	,1	,1	, &R2ZAV},	//( - , DU) 
	{ 49	,1	,1	, &A5ZAV},	//( - , DU) 
	{ 50	,1	,1	, &B8ZAV},	//( - , DU) 
	{ 51	,1	,1	, &A2ZAV},	//( - , DU) Завершение РБ1,2
	{ 52	,1	,1	, &A8ZAV},	//( - , DU) 
	{ 53	,1	,1	, &A9ZAV},	//( - , DU) Завершение НИ ДС1(2)
	{ 54	,1	,1	, &R4ABL},	//( - , DU) Блокировка тележки -
	{ 55	,1	,1	, &A4UP},	//( - , DU) 
	{ 56	,1	,1	, &A4DW},	//( - , DU) 
	{ 57	,1	,1	, &R0AB14LDU},	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{ 58	,1	,1	, &R0AB15LDU},	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{ 59	,1	,1	, &A3IS12LDU},	//( - , DU) Приход на ВУ штока ИС1
	{ 60	,1	,1	, &B3IS12LDU},	//( - , DU) Приход на ВУ штока ИС2
	{ 61	,1	,1	, &A1ZAV},	//( - , DU) 
	{ 62	,1	,1	, &A3ZAV},	//( - , DU) 
	{ 63	,1	,1	, &B1AB19LDU},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{ 64	,1	,1	, &R0AB16LDU},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{ 65	,1	,1	, &R0AB17LDU},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{ 66	,1	,1	, &R0AB18LDU},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{ 67	,8	,1	, &A0CT01IZ1},	//( - , MDuBz1) Температура АЗ1-1
	{ 68	,8	,1	, &B0CT01IZ1},	//( - , MDuBz1) Температура АЗ2-1
	{ 69	,8	,1	, &A0CT01IZ2},	//( - , MDuBz2) Температура АЗ1-2
	{ 70	,1	,1	, &A2IE04LDU},	//(vds32:05 - K08VDSR, - ) Движение РБ1 назад (от БУШД)
	{ 71	,1	,1	, &A3IE03LDU},	//(vds32:05 - K11VDSR, - ) Движение ИС1 вперед (от БУШД)
	{ 72	,1	,1	, &A3IE04LDU},	//(vds32:05 - K12VDSR, - ) Движение ИС1 назад (от БУШД)
	{ 73	,1	,1	, &B1IE03LDU},	//(vds32:05 - K15VDSR, - ) Движение ББ2 вперед (от БУШД)
	{ 74	,1	,1	, &B1IE04LDU},	//(vds32:05 - K16VDSR, - ) Движение ББ2 назад (от БУШД)
	{ 75	,1	,1	, &B2IE03LDU},	//(vds32:05 - K19VDSR, - ) Движение РБ2 вперед (от БУШД)
	{ 76	,1	,1	, &B2IE04LDU},	//(vds32:05 - K20VDSR, - ) Движение РБ2 назад (от БУШД)
	{ 77	,1	,1	, &B3IE03LDU},	//(vds32:05 - K23VDSR, - ) Движение ИС2 вперед (от БУШД)
	{ 78	,1	,1	, &B3IE04LDU},	//(vds32:05 - K24VDSR, - ) Движение ИС2 назад (от БУШД)
	{ 79	,1	,1	, &R0VS11LDU},	//( - , DU) РУ не готова к работе
	{ 80	,1	,1	, &B6AB05LDU},	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
	{ 81	,1	,1	, &R0AB08LDU},	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
	{ 82	,8	,1	, &A1MC01RP1},	//( - , DU) Заданная координата положения ББ1 мм
	{ 83	,8	,1	, &B1MC01RP1},	//( - , DU) Заданная координата положения ББ2  мм
	{ 84	,8	,1	, &A3MC01RP1},	//( - , DU) Заданная координата положения ИС1 мм
	{ 85	,8	,1	, &B3MC01RP1},	//( - , DU) Заданная координата положения ИС2 мм
	{ 86	,8	,1	, &B8MC01RP2},	//( - , DU) Заданная координата АЗ2 мм
	{ 87	,1	,1	, &R0AB09LDU},	//( - , DU) Ошибка в заданной координате ББ1
	{ 88	,1	,1	, &R0AB10LDU},	//( - , DU) Ошибка в заданной координате ББ2
	{ 89	,1	,1	, &R0AB11LDU},	//( - , DU) Ошибка в заданной координате  ИС1
	{ 90	,1	,1	, &R0AB12LDU},	//( - , DU) Ошибка в заданной координате  ИС2
	{ 91	,1	,1	, &R0AB13LDU},	//( - , DU) Ошибка в заданной координате  АЗ2
	{ 92	,1	,1	, &A4ZAV},	//( - , DU) 
	{ 93	,1	,1	, &A9AD10LDU},	//(fds16:0b - K15FDSR, - ) Открыть клапан Подъем НИ ДС1
	{ 94	,1	,1	, &A9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС1
	{ 95	,1	,1	, &A9AB01LDU},	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
	{ 96	,1	,1	, &A9AB02LDU},	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
	{ 97	,1	,1	, &B9AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ ДС2
	{ 98	,1	,1	, &B9AB01LDU},	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
	{ 99	,1	,1	, &B9AB02LDU},	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
	{ 100	,1	,1	, &R0AB01LDU},	//( - , DU) Режим проверки разрешён
	{ 101	,1	,1	, &A3IS22LDU},	//(vds32:04 - K02VDSR, DU) Приход на НУП ИС1
	{ 102	,1	,1	, &B3IS22LDU},	//(vds32:04 - K04VDSR, DU) Приход на НУП ИС2
	{ 103	,1	,1	, &A2AD33LDU},	//(fds16:0a - K03FDSR, - ) Клапан ПОДЪЕМ РБ1 открыть (обесточить)
	{ 104	,1	,1	, &B2AD33LDU},	//(fds16:09 - K03FDSR, - ) Клапан ПОДЪЕМ РБ2 открыть (обесточить)
	{ 105	,1	,1	, &A3AD33LDU},	//(fds16:0a - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС1 открыть (обесточить)
	{ 106	,1	,1	, &A3AD34LDU},	//(fds16:0a - K01FDSR, - ) Клапан ВПИС1  открыть (обесточить)
	{ 107	,1	,1	, &A3AD31LDU},	//(fds16:0a - K05FDSR, - ) Клапан СПУСК ИС1 открыть (обесточить)
	{ 108	,1	,1	, &B3AD34LDU},	//(fds16:09 - K01FDSR, - ) Клапан ВПИС ИС2  открыть (обесточить)
	{ 109	,1	,1	, &B3AD31LDU},	//(fds16:09 - K05FDSR, - ) Клапан СПУСК ИС2 открыть (обесточить)
	{ 110	,1	,1	, &A2IS11LDU},	//(vds32:03 - K11VDSR, DU) Приход на ВУ РБ1-СТР
	{ 111	,1	,1	, &B2IS11LDU},	//(vds32:02 - K11VDSR, DU) Приход на ВУ РБ2-СТР
	{ 112	,1	,1	, &A3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
	{ 113	,1	,1	, &A3MD11LP1},	//( - , DU) Кнопка ПУСК ИС1
	{ 114	,1	,1	, &R0MD33LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
	{ 115	,1	,1	, &A1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
	{ 116	,3	,1	, &R0VS21IDU},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	{ 117	,3	,1	, &A1VS01IDU},	//( - , DU) Готовность к управлению ББ1
	{ 118	,3	,1	, &B1VS01IDU},	//( - , DU) Готовность к управлению ББ2
	{ 119	,3	,1	, &A3VS01IDU},	//( - , DU) Готовность к управлению ИС1
	{ 120	,3	,1	, &B3VS01IDU},	//( - , DU) Готовность к управлению ИС2
	{ 121	,3	,1	, &A2VS01IDU},	//( - , DU) Готовность к управлению РБ1
	{ 122	,3	,1	, &A4VS01IDU},	//( - , DU) Готовность к управлению НИ1
	{ 123	,1	,1	, &A4VS12LDU},	//( - , DU) Движение НИ1 в сторону ВУ
	{ 124	,1	,1	, &A4VS22LDU},	//( - , DU) Движение НИ1 в сторону НУ
	{ 125	,3	,1	, &B4VS01IDU},	//( - , DU) Готовность к управлению НИ2
	{ 126	,1	,1	, &B4VS12LDU},	//( - , DU) Движение НИ2 в сторону ВУ
	{ 127	,1	,1	, &B4VS22LDU},	//( - , DU) Движение НИ2 в сторону НУ
	{ 128	,3	,1	, &A5VS01IDU},	//( - , DU) Готовность к управлению НЛ1
	{ 129	,3	,1	, &B5VS01IDU},	//( - , DU) Готовность к управлению НЛ2
	{ 130	,3	,1	, &A6VS01IDU},	//( - , DU) Готовность к управлению БЗ1
	{ 131	,3	,1	, &R4VS01IDU},	//( - , DU) Готовность к управлению тележкой реактора
	{ 132	,3	,1	, &R2VS01IDU},	//( - , DU) Готовность к управлению МДЗ2
	{ 133	,3	,1	, &R1VS01IDU},	//( - , DU) Готовность к управлению МДЗ1
	{ 134	,1	,1	, &A9IS11LDU},	//(vds32:02 - K23VDSR, DU) Приход на ВУ НИ ДС1
	{ 135	,1	,1	, &A9IS21LDU},	//(vds32:02 - K24VDSR, - ) Приход на НУ НИ ДС1
	{ 136	,1	,1	, &B9IS11LDU},	//(vds32:02 - K25VDSR, DU) Приход на ВУ НИ ДС2
	{ 137	,1	,1	, &B9IS21LDU},	//(vds32:02 - K26VDSR, - ) Приход на НУ НИ ДС2
	{ 138	,1	,1	, &B9AD10LDU},	//(fds16:0b - K16FDSR, - ) Открыть клапан Подъем НИ ДС2
	{ 139	,1	,1	, &R0IS01LDU},	//(vds32:03 - K29VDSR, DU) Признак работы с имитатором
	{ 140	,1	,1	, &R0IS02LDU},	//(vds32:03 - K30VDSR, DU) Разрешение ввода от имитатора
	{ 141	,1	,1	, &R0VP73LZ1},	//( - , MDuBz1) ПС давления для РУ
	{ 142	,1	,1	, &R0VP73LZ2},	//( - , MDuBz2) ПС давления для РУ
	{ 143	,1	,1	, &R0VP73LDU},	//( - , DU) ПС давления для РУ
	{ 144	,1	,1	, &R0MD34LP1},	//( - , DU) Кнопка КВИТИРОВАТЬ
	{ 145	,1	,1	, &A0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ1
	{ 146	,1	,1	, &B0VT71LZ1},	//( - , MDuBz1) АС по температуре в АЗ2
	{ 147	,1	,1	, &A0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ1
	{ 148	,1	,1	, &B0VT71LZ2},	//( - , MDuBz2) АС по температуре в АЗ2
	{ 149	,1	,1	, &B2VS11LDU},	//( - , DU) Движение РБ2 в сторону ВУ
	{ 150	,1	,1	, &B2VS21LDU},	//( - , DU) Движение РБ2 в сторону НУ
	{ 151	,3	,1	, &B2VS01IDU},	//( - , DU) Готовность к управлению РБ2
	{ 152	,1	,1	, &A7AS31LDU},	//(vds32:03 - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
	{ 153	,1	,1	, &B7AS31LDU},	//(vds32:02 - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
	{ 154	,1	,1	, &A7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ1
	{ 155	,1	,1	, &B7AZ03LDU},	//( - , DU) Несанкционированное включение обдува АЗ2
	{ 156	,1	,1	, &B3MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
	{ 157	,1	,1	, &B3MD11LP1},	//( - , DU) Кнопка ПУСК ИС2
	{ 158	,8	,1	, &R0VL01RDU},	//( - , DU) Индикация Время задержки
	{ 159	,1	,1	, &R0VZ71LZ2},	//(vds32:03 - K22VDSR, - ) Обобщенный сигнал АЗ 2 канала
	{ 160	,1	,1	, &R0VZ71LZ1},	//(vds32:02 - K22VDSR, - ) Обобщенный сигнал АЗ 1канала
	{ 161	,1	,1	, &R0VZ71LDU},	//( - , DU) Обобщенный сигнал АЗ
	{ 162	,1	,1	, &A1MD11LP1},	//( - , DU) Кнопка ПУСК ББ1
	{ 163	,3	,1	, &R0MW14IP2},	//( - , DU) Переключатель ОБДУВ
	{ 164	,1	,1	, &A7AP31LDU},	//(fds16:0a - K06FDSR, - ) Клапан Обдув АЗ1 открыть (обесточить)
	{ 165	,1	,1	, &B7AP31LDU},	//(fds16:09 - K06FDSR, - ) Клапан Обдув АЗ2 открыть (обесточить)
	{ 166	,3	,1	, &R0MW12IP2},	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
	{ 167	,1	,1	, &R0MW17LP1},	//( - , DU) Переключатель АВТ/Р
	{ 168	,1	,1	, &R0VW13LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
	{ 169	,1	,1	, &R0VW23LDU},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
	{ 170	,3	,1	, &R0VX08IDU},	//( - , DU) Индикация Режим
	{ 171	,1	,1	, &R0VX09LDU},	//( - , DU) Индикация регулятор мощности включен/отключен
	{ 172	,1	,1	, &R0VS17LDU},	//( - , DU) Индикация выбора АВТОМАТ
	{ 173	,1	,1	, &A2VS32LDU},	//( - , DU) Индикация  СБРОС РБ1
	{ 174	,1	,1	, &B2VS32LDU},	//( - , DU) Индикация  СБРОС РБ2
	{ 175	,1	,1	, &A3VX01LDU},	//( - , DU) Индикация Выстрел ИС1
	{ 176	,1	,1	, &B3VX01LDU},	//( - , DU) Индикация Выстрел ИС2
	{ 177	,1	,1	, &R0VS18LDU},	//( - , DU) Индикация  Проверка схем сброса
	{ 178	,1	,1	, &B1MD11LP1},	//( - , DU) Кнопка ПУСК ББ2
	{ 179	,1	,1	, &B1MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	{ 180	,1	,1	, &B2MD11LP1},	//( - , DU) Кнопка ПУСК РБ2
	{ 181	,1	,1	, &B2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	{ 182	,1	,1	, &A2MD11LP1},	//( - , DU) Кнопка ПУСК РБ1
	{ 183	,1	,1	, &A2MD12LP1},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
	{ 184	,1	,1	, &B3IS11LDU},	//(vds32:04 - K03VDSR, DU) Приход на ВУ ИС2
	{ 185	,1	,1	, &A3IS11LDU},	//(vds32:04 - K01VDSR, DU) Приход на ВУ ИС1
	{ 186	,1	,1	, &B3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{ 187	,1	,1	, &B3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
	{ 188	,1	,1	, &A3VP82LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
	{ 189	,3	,1	, &A3IP02IDU},	//(vas84:0c - K01VASR, - ) Текущее давление ВЫСТРЕЛ ИС1
	{ 190	,3	,1	, &B3IP02IDU},	//(vas84:0c - K02VASR, - ) Текущее давление ВЫСТРЕЛ ИС2
	{ 191	,1	,1	, &A0VE01LDU},	//( - , DU) Напряжение в системы АЗ1 подано
	{ 192	,1	,1	, &B0VE01LDU},	//( - , DU) Напряжение в системы АЗ2 подано
	{ 193	,1	,1	, &A0VP01LDU},	//( - , DU) Давление в системы АЗ1 подано
	{ 194	,1	,1	, &B0VP01LDU},	//( - , DU) Давление в системы АЗ2 подано
	{ 195	,1	,1	, &A0EE01LZ1},	//( - , MDuBz1) Исправность АКНП1
	{ 196	,1	,1	, &A0EE03LZ1},	//( - , MDuBz1) Исправность АКНП3
	{ 197	,1	,1	, &A0EE02LZ1},	//( - , MDuBz1) Исправность АКНП2
	{ 198	,1	,1	, &A0EE04LZ1},	//( - , MDuBz1) Исправность АКНП4
	{ 199	,1	,1	, &A0VN01LDU},	//( - , DU) Каналы АЗ1 проверены
	{ 200	,1	,1	, &B0VN01LDU},	//( - , DU) Каналы АЗ2 проверены
	{ 201	,1	,1	, &A0EE01LZ2},	//( - , MDuBz2) Исправность АКНП1
	{ 202	,1	,1	, &A0EE03LZ2},	//( - , MDuBz2) Исправность АКНП3
	{ 203	,1	,1	, &A0EE02LZ2},	//( - , MDuBz2) Исправность АКНП2
	{ 204	,1	,1	, &A0EE04LZ2},	//( - , MDuBz2) Исправность АКНП4
	{ 205	,1	,1	, &A0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ1
	{ 206	,1	,1	, &A0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ1
	{ 207	,1	,1	, &B0VP71LZ1},	//( - , MDuBz1) АЗ по АС любого давления для АЗ2
	{ 208	,1	,1	, &B0VP71LZ2},	//( - , MDuBz2) АЗ по АС любого давления для АЗ2
	{ 209	,8	,1	, &A1VC01RDU},	//( - , DU) Координата ББ1, мм
	{ 210	,1	,1	, &A1IS11LDU},	//(vds32:03 - K08VDSR, DU) Приход на ВУ ББ1
	{ 211	,1	,1	, &B1MC01LC1},	//( - , DU) Настроить энкодер ББ2
	{ 212	,1	,1	, &B1MC01LC2},	//( - , DU) Настроить энкодер ББ2
	{ 213	,1	,1	, &A1MC01LC1},	//( - , DU) Настроить энкодер ББ1
	{ 214	,1	,1	, &A1MC01LC2},	//( - , DU) Настроить энкодер ББ1
	{ 215	,1	,1	, &B2MC01LC1},	//( - , DU) Настроить энкодер РБ2
	{ 216	,1	,1	, &B2MC01LC2},	//( - , DU) Настроить энкодер РБ2
	{ 217	,1	,1	, &A2MC01LC1},	//( - , DU) Настроить энкодер РБ1
	{ 218	,1	,1	, &A2MC01LC2},	//( - , DU) Настроить энкодер РБ1
	{ 219	,1	,1	, &B3MC01LC1},	//( - , DU) Настроить энкодер ИС2
	{ 220	,1	,1	, &B3MC01LC2},	//( - , DU) Настроить энкодер ИС2
	{ 221	,1	,1	, &A3MC01LC1},	//( - , DU) Настроить энкодер ИС1
	{ 222	,1	,1	, &A3MC01LC2},	//( - , DU) Настроить энкодер ИС1
	{ 223	,1	,1	, &B8MC01LC1},	//( - , DU) Настроить энкодер АЗ2
	{ 224	,1	,1	, &B8MC01LC2},	//( - , DU) Настроить энкодер АЗ2
	{ 225	,1	,1	, &A8MC01LC1},	//( - , DU) Настроить энкодер ДС2
	{ 226	,1	,1	, &A8MC01LC2},	//( - , DU) Настроить энкодер ДС2
	{ 227	,1	,1	, &A3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
	{ 228	,8	,1	, &A3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
	{ 229	,1	,1	, &A3VP52LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{ 230	,1	,1	, &B3VP42LDU},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
	{ 231	,8	,1	, &B3CP02RDU},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
	{ 232	,1	,1	, &R6IS61LDU},	//(vds32:0d - K01VDSR, - ) Исправность 3-х  фазной сети
	{ 233	,1	,1	, &R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 234	,1	,1	, &R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 235	,1	,1	, &R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 236	,8	,1	, &A3VC01RDU},	//( - , DU) Координата ИС1, мм
	{ 237	,8	,1	, &A2VC01RDU},	//( - , DU) Координата РБ1, мм
	{ 238	,8	,1	, &B2VC01RDU},	//( - , DU) Координата РБ2, мм
	{ 239	,8	,1	, &B8VC01RDU},	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
	{ 240	,1	,1	, &A4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
	{ 241	,1	,1	, &B4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
	{ 242	,1	,1	, &A2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
	{ 243	,1	,1	, &B2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
	{ 244	,1	,1	, &A3VP81LDU},	//( - , - ) Давление СПУСК ИС1 в норме
	{ 245	,1	,1	, &B3VP81LDU},	//( - , - ) Давление СПУСК ИС2 в норме
	{ 246	,1	,1	, &R0EE02LDU},	//( - , DU) Питание  АКНП  отключить
	{ 247	,1	,1	, &psb1},	//( - , DU) ру не готова
	{ 248	,1	,1	, &psb2},	//( - , DU) движение бб
	{ 249	,1	,1	, &psa1},	//( - , DU) AZ1
	{ 250	,1	,1	, &psa2},	//( - , DU) AZ2
	{ 251	,1	,1	, &psrb4},	//( - , DU) кнопка сброс
	{ 252	,1	,1	, &psrb1},	//( - , DU) пневматика по мощности
	{ 253	,1	,1	, &psrb2},	//( - , DU) пневматика по программам
	{ 254	,1	,1	, &psrb},	//( - , DU) ???
	{ 255	,1	,1	, &A0VS11LDU},	//( - , DU) АЗ1 готова к работе
	{ 256	,1	,1	, &B0VS11LDU},	//( - , DU) АЗ2 готова к работе
	{ 257	,1	,1	, &A1IE01LDU},	//(vds32:05 - K02VDSR, - ) Исправность БУШД ББ1
	{ 258	,1	,1	, &A3IE01LDU},	//(vds32:05 - K10VDSR, - ) Исправность БУШД ИС1
	{ 259	,1	,1	, &A2IE01LDU},	//(vds32:05 - K06VDSR, - ) Исправность БУШД РБ1
	{ 260	,1	,1	, &A1IE02LDU},	//(vds32:05 - K01VDSR, - ) Исправность ИП ББ1
	{ 261	,1	,1	, &A3IE02LDU},	//(vds32:05 - K09VDSR, - ) Исправность ИП ИС1
	{ 262	,1	,1	, &A2IE02LDU},	//(vds32:05 - K05VDSR, - ) Исправность ИП РБ1
	{ 263	,1	,1	, &B1IE01LDU},	//(vds32:05 - K14VDSR, - ) Исправность БУШД ББ2
	{ 264	,1	,1	, &B2IE01LDU},	//(vds32:05 - K18VDSR, - ) Исправность БУШД РБ2
	{ 265	,1	,1	, &B3IE01LDU},	//(vds32:05 - K22VDSR, - ) Исправность БУШД ИС2
	{ 266	,1	,1	, &B1IE02LDU},	//(vds32:05 - K13VDSR, - ) Исправность ИП ББ2
	{ 267	,1	,1	, &B3IE02LDU},	//(vds32:05 - K21VDSR, - ) Исправность ИП ИС2
	{ 268	,1	,1	, &B2IE02LDU},	//(vds32:05 - K17VDSR, - ) Исправность ИП РБ2
	{ 269	,1	,1	, &R0IE02LDU},	//(vds32:0d - K23VDSR, - ) Исправность ИП 24 В-1
	{ 270	,1	,1	, &R0IE01LDU},	//(vds32:0d - K24VDSR, - ) Исправность ИП 24 В-2
	{ 271	,1	,1	, &A6IE01LDU},	//(vds32:0d - K19VDSR, - ) Исправность ИП БЗ1
	{ 272	,1	,1	, &B6IE01LDU},	//(vds32:0d - K22VDSR, - ) Исправность ИП БЗ2
	{ 273	,1	,1	, &A8IE01LDU},	//(vds32:0d - K04VDSR, - ) Исправность ИП ДС2
	{ 274	,1	,1	, &B5IE01LDU},	//(vds32:0d - K16VDSR, - ) Исправность ИП НЛ2
	{ 275	,1	,1	, &A5IE02LDU},	//(vds32:0d - K13VDSR, - ) Исправность ИП НЛ1
	{ 276	,1	,1	, &R1IE01LDU},	//(vds32:0d - K07VDSR, - ) Исправность ИП МДЗ1
	{ 277	,1	,1	, &R2IE01LDU},	//(vds32:0d - K10VDSR, - ) Исправность ИП МДЗ2
	{ 278	,1	,1	, &A1VP41LZ2},	//( - , MDuBz2) Давление СБРОС ББ1 ниже АС
	{ 279	,1	,1	, &R0VL22LDU},	//( - , DU) Конец программы 200сек
	{ 280	,1	,1	, &R0VL23LDU},	//( - , DU) Конец программы 20мин
	{ 281	,1	,1	, &B1VP41LZ1},	//( - , MDuBz1) Давление СБРОС ББ2 ниже АС
	{ 282	,1	,1	, &B1VP41LZ2},	//( - , MDuBz2) Давление СБРОС ББ2 ниже АС
	{ 283	,1	,1	, &A3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
	{ 284	,1	,1	, &B3AB19LDU},	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
	{ 285	,1	,1	, &A3EE03LDU},	//( - , DU) ВПИС ИС1
	{ 286	,1	,1	, &B3EE03LDU},	//( - , DU) ВПИС ИС2
	{ 287	,1	,1	, &B3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
	{ 288	,1	,1	, &R5IS21LDU},	//(vds32:04 - K26VDSR, DU) Приход на НУ ворот отстойной зоны
	{ 289	,1	,1	, &R5VS22LDU},	//( - , DU) Движение ворот отстойной зоны к закрыты
	{ 290	,1	,1	, &R5VS12LDU},	//( - , DU) Движение ворот отстойной зоны к открыты
	{ 291	,3	,1	, &R5VS01IDU},	//( - , DU) Готовность к управлению ворот отстойной зоны
	{ 292	,1	,1	, &R3VS22LDU},	//( - , DU) Движение гомогенных дверей к закрыты
	{ 293	,1	,1	, &R3VS12LDU},	//( - , DU) Движение гомогенных дверей к открыты
	{ 294	,3	,1	, &R3VS01IDU},	//( - , DU) Готовность к управлению гомогенных дверей
	{ 295	,1	,1	, &A3AB13LDU},	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
	{ 296	,1	,1	, &B3AB13LDU},	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{ 297	,3	,1	, &R0DE02LDU},	//(vds32:02 - Diagn, DiagnDU) диагностика модуля ДУ на 2 месте
	{ 298	,3	,1	, &R0DE03LDU},	//(vds32:03 - Diagn, DiagnDU) диагностика модуля ДУ на 3 месте
	{ 299	,3	,1	, &R0DE04LDU},	//(vds32:04 - Diagn, DiagnDU) диагностика модуля ДУ на 4 месте
	{ 300	,3	,1	, &R0DE08LDU},	//(fds16:08 - Diagn, DiagnDU) диагностика модуля ДУ на 8 месте
	{ 301	,8	,1	, &B0CT01IZ2},	//( - , MDuBz2) Температура АЗ2-2
	{ 302	,8	,1	, &A3MC01RDU},	//( - , DU) Заданная координата положения ИС от регулятора мм
	{ 303	,8	,1	, &A3MC02RDU},	//( - , DU) Температурная корректировка координаты ИМ
	{ 304	,8	,1	, &R0CN91LDU},	//( - , DU) Рассчётная реактивность от регулятора
	{ 305	,8	,1	, &A3MC03RDU},	//( - , DU) Координата положения ИМ 0-й реактивности
	{ 306	,1	,1	, &A3AB15LDU},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	{ 307	,1	,1	, &R0AB20LDU},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	{ 308	,8	,1	, &R0CN92LDU},	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
	{ 309	,8	,1	, &R0VN11RDU},	//( - , DU) Текущая мощность РУ
	{ 310	,8	,1	, &R0VN12RDU},	//( - , DU) Заданная мощность РУ
	{ 311	,1	,1	, &R0AB19LDU},	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
	{ 312	,8	,1	, &R0CN93LDU},	//( - , DU) время работы на мощности более 100Вт, сек
	{ 313	,8	,1	, &R0CN94LDU},	//( - , DU) Скорость изменения мощности
	{ 314	,3	,1	, &R0CN95LDU},	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
	{ 315	,1	,1	, &R0AD03LZ1},	//(fds16:0f - K09FDSR, - ) Имитация прихода на ВУ ИС (БАЗ1)
	{ 316	,1	,1	, &R0AD03LZ2},	//(fds16:0f - K14FDSR, - ) Имитация прихода на ВУ ИС (БАЗ2)
	{ 317	,1	,1	, &R0AD04LZ1},	//(fds16:0f - K10FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ1)
	{ 318	,1	,1	, &R0AD04LZ2},	//(fds16:0f - K15FDSR, - ) Имитация срабатывания АС II УР. РАД (БАЗ2)
	{ 319	,1	,1	, &R0AD05LZ1},	//(fds16:0f - K11FDSR, - ) Имитация ухода с НУП ИС  (БАЗ1)
	{ 320	,1	,1	, &R0AD05LZ2},	//(fds16:0f - K16FDSR, - ) Имитация ухода с НУП ИС  (БАЗ2)
	{ 321	,1	,1	, &B8IS12LDU},	//(vds32:04 - K21VDSR, DU) Приход на ВУ2 АЗ2
	{ 322	,1	,1	, &B8IS21LDU},	//(vds32:04 - K20VDSR, DU) Приход на НУ1 АЗ2
	{ 323	,1	,1	, &A1VP41LZ1},	//( - , MDuBz1) Давление СБРОС ББ1 ниже АС
	{ 324	,5	,1	, &venc06},	//(vencf8l:01 - venc06, - ) заначение реального энкодера РБ2
	{ 325	,5	,1	, &venc07},	//(vencf8l:01 - venc07, - ) заначение реального энкодера ИС2
	{ 326	,5	,1	, &venc08},	//(vencf8l:01 - venc08, - ) заначение реального энкодера АЗ2
	{ 327	,8	,1	, &R0VN15RDU},	//( - , DU) Период разгона РУ
	{ 328	,1	,1	, &R8AD21LDU},	//(fds16:0f - K12FDSR, - ) Запуск системы инициирования
	{ 329	,1	,1	, &R8AD22LDU},	//(vds32:02 - K15VDSR, - ) Сигнал синхронизации с импульсом
	{ 330	,1	,1	, &R0S01LDU},	//( - , - ) Отключение сетевых передач ДУ
	{ 331	,1	,1	, &R0S01LZ1},	//(fds16:07 - K15FDSR, - ) Отключение сетевых передач в Баз1
	{ 332	,1	,1	, &R0S01LZ2},	//(fds16:07 - K16FDSR, - ) Отключение сетевых передач в Баз2
	{ 333	,1	,1	, &R0AD16LDU},	//(fds16:0f - K13FDSR, - ) Контроль  I-II УР. РАД
	{ 334	,1	,1	, &R0S01LIM},	//(fds16:08 - K15FDSR, - ) Отключение сетевых передач ПТИ
	{ 335	,5	,1	, &B1IC01UDU},	//( - , MDuS) Координата штока ББ2 (дел.энк)
	{ 336	,8	,1	, &B1VC01RDU},	//( - , DU) Координата ББ2, мм
	{ 337	,1	,1	, &B1IS11LDU},	//(vds32:02 - K08VDSR, DU) Приход на ВУ ББ2
	{ 338	,5	,1	, &A2IC01UDU},	//( - , MDuS) Координата штока РБ1 (дел.энк)
	{ 339	,5	,1	, &B2IC01UDU},	//( - , MDuS) Координата штока РБ2 (дел.энк)
	{ 340	,5	,1	, &A3IC01UDU},	//( - , MDuS) Координата штока ИС1 (дел.энк)
	{ 341	,5	,1	, &B3IC01UDU},	//( - , MDuS) Координата штока ИС2 (дел.энк)
	{ 342	,8	,1	, &B3VC01RDU},	//( - , DU) Координата ИС2, мм
	{ 343	,5	,1	, &A8IC01UDU},	//( - , MDuS) Координата ДС2 (дел.энк)
	{ 344	,8	,1	, &A8VC01RDU},	//( - , DU) Координата ДС2, мм
	{ 345	,5	,1	, &B8IC01UDU},	//( - , MDuS) Координата АЗ2 (дел.энк)
	{ 346	,5	,1	, &A1IC01UDU},	//( - , MDuS) Координата штока ББ1 (дел.энк)
	{ 347	,3	,1	, &R0DE05LDU},	//(vds32:05 - Diagn, DiagnDU) диагностика модуля ДУ на 5 месте
	{ 348	,3	,1	, &R0DE09LDU},	//(fds16:09 - Diagn, DiagnDU) диагностика модуля ДУ на 9 месте
	{ 349	,3	,1	, &R0DE0ALDU},	//(fds16:0a - Diagn, DiagnDU) диагностика модуля ДУ на 10 месте
	{ 350	,3	,1	, &R0DE07LDU},	//(fds16:07 - Diagn, DiagnDU) диагностика модуля ДУ на 7 месте
	{ 351	,3	,1	, &R0DE0CLDU},	//(vas84:0c - Diagn, DiagnDU) диагностика модуля ДУ на 12 месте
	{ 352	,3	,1	, &R0DE0BLDU},	//(fds16:0b - Diagn, DiagnDU) диагностика модуля ДУ на 11 месте
	{ 353	,3	,1	, &R0DE0DLDU},	//(vds32:0d - Diagn, DiagnDU) диагностика модуля ДУ на 13 месте
	{ 354	,3	,1	, &R0DE0FLDU},	//(fds16:0f - Diagn, DiagnDU) диагностика модуля ДУ на 15 месте
	{ 355	,3	,1	, &TTLDU},	//( - , DU) ttl
	{ 356	,1	,1	, &R0DEB3LDU},	//(sbk:20 - S12SBK, DiagnDU) диагностика шкафа ДУ БП5 место 6
	{ 357	,1	,1	, &R0DEB2LDU},	//(sbk:20 - S11SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 5
	{ 358	,1	,1	, &R0DEB1LDU},	//(sbk:20 - S10SBK, DiagnDU) диагностика шкафа ДУ БП5 место 5
	{ 359	,1	,1	, &R0DEB4LDU},	//(sbk:20 - S13SBK, DiagnDU) диагностика шкафа ДУ БП24Д место 6
	{ 360	,1	,1	, &R0DE3DLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 6
	{ 361	,1	,1	, &R0DE3CLDU},	//( - , DiagnDU) диагностика шкафа ДУ БП5/24Д место 5
	{ 362	,1	,1	, &TestDiagnDU},	//( - , DU) Неисправность от
	{ 363	,8	,1	, &B3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС2
	{ 364	,3	,1	, &R0DE01LDU},	//(vencf8l:01 - DiagnVDS, DiagnDU) диагностика модуля ДУ на 1 месте
	{ 365	,3	,1	, &R0DE06LDU},	//(vencf8l:01 - DiagnFDS, DiagnDU) диагностика модуля ДУ на 6 месте
	{ 366	,5	,1	, &venc01},	//(vencf8l:01 - venc01, - ) заначение реального энкодера ББ1
	{ 367	,5	,1	, &venc02},	//(vencf8l:01 - venc02, - ) заначение реального энкодера РБ1
	{ 368	,5	,1	, &venc03},	//(vencf8l:01 - venc03, - ) заначение реального энкодера Ис1
	{ 369	,5	,1	, &venc04},	//(vencf8l:01 - venc04, - ) заначение реального энкодера ДС1
	{ 370	,5	,1	, &venc05},	//(vencf8l:01 - venc05, - ) заначение реального энкодера ББ2
	{ 371	,1	,1	, &A6AB07LDU},	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
	{ 372	,1	,1	, &A6AB08LDU},	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
	{ 373	,1	,1	, &A6AB09LDU},	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
	{ 374	,1	,1	, &B6AB06LDU},	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
	{ 375	,1	,1	, &B6AB07LDU},	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
	{ 376	,1	,1	, &B6AB08LDU},	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
	{ 377	,1	,1	, &B6AB09LDU},	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
	{ 378	,1	,1	, &A6AB05LDU},	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
	{ 379	,1	,1	, &B8VS12LDU},	//( - , DU) Движение АЗ2 в сторону ВУ
	{ 380	,8	,1	, &B8CV01RDU},	//( - , DU) Измеренная скорость перемещения АЗ2
	{ 381	,1	,1	, &B8AB06LDU},	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
	{ 382	,1	,1	, &B8AB07LDU},	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
	{ 383	,1	,1	, &B8AB05LDU},	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
	{ 384	,1	,1	, &B8VS22LDU},	//( - , DU) Движение АЗ2 в сторону НУ
	{ 385	,1	,1	, &B8AZ03LDU},	//( - , DU) Несанкционированное перемещение АЗ2
	{ 386	,1	,1	, &R0MD11LP1},	//( - , DU) Кнопка ПУСК
	{ 387	,1	,1	, &B8AD10LDU},	//(fds16:09 - K15FDSR, - ) Перемещение АЗ2 вперед
	{ 388	,1	,1	, &B8AD20LDU},	//(fds16:09 - K16FDSR, - ) Перемещение АЗ2 назад
	{ 389	,1	,1	, &B8IS11LDU},	//(vds32:04 - K19VDSR, DU) Приход на ВУ1 АЗ2
	{ 390	,1	,1	, &B8AB01LDU},	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
	{ 391	,1	,1	, &B8AB04LDU},	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
	{ 392	,1	,1	, &B8AB08LDU},	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
	{ 393	,1	,1	, &B8AB09LDU},	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
	{ 394	,1	,1	, &A5AB01LDU},	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
	{ 395	,1	,1	, &A5AB02LDU},	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
	{ 396	,1	,1	, &B5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ2
	{ 397	,1	,1	, &B5AB01LDU},	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
	{ 398	,1	,1	, &B5AB02LDU},	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
	{ 399	,1	,1	, &A4IS21LDU},	//(vds32:03 - K15VDSR, DU) Приход на НУ НИ1
	{ 400	,1	,1	, &B4IS21LDU},	//(vds32:02 - K32VDSR, DU) Приход на НУ НИ2
	{ 401	,1	,1	, &B4AD10LDU},	//(fds16:09 - K04FDSR, - ) Клапан Подъем НИ2 открыть (обесточить)
	{ 402	,1	,1	, &A4AD10LDU},	//(fds16:0a - K04FDSR, - ) Клапан ПОДЪЕМ НИ1 открыть (обесточить)
	{ 403	,1	,1	, &A4AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ1
	{ 404	,1	,1	, &A4AB01LDU},	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
	{ 405	,1	,1	, &A4AB02LDU},	//( - , DU) Блокировка движения НИ1 - Нет перемещения
	{ 406	,1	,1	, &B4AZ03LDU},	//( - , DU) Несанкционированное перемещение НИ2
	{ 407	,1	,1	, &B4AB01LDU},	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
	{ 408	,1	,1	, &B4AB02LDU},	//( - , DU) Блокировка движения НИ2 - Нет перемещения
	{ 409	,1	,1	, &A5AB04LDU},	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
	{ 410	,1	,1	, &B5AB04LDU},	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
	{ 411	,1	,1	, &A1IS12LDU},	//(vds32:03 - K07VDSR, DU) Магнит ББ1 зацеплен
	{ 412	,1	,1	, &A2IS12LDU},	//(vds32:03 - K10VDSR, DU) Магнит РБ1 зацеплен
	{ 413	,1	,1	, &B1IS12LDU},	//(vds32:02 - K07VDSR, DU) Магнит ББ2 зацеплен
	{ 414	,1	,1	, &B2IS12LDU},	//(vds32:02 - K10VDSR, DU) Магнит РБ2 зацеплен
	{ 415	,1	,1	, &R4IS11LDU},	//(vds32:04 - K05VDSR, DU) Приход на ВУ1 тележки
	{ 416	,1	,1	, &A6AB06LDU},	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
	{ 417	,1	,1	, &A8AB12LDU},	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
	{ 418	,1	,1	, &A8AB13LDU},	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
	{ 419	,1	,1	, &A8AB14LDU},	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
	{ 420	,1	,1	, &A8AB02LDU},	//( - , DU) Блокировка движения ДС2- АНИ не установлен
	{ 421	,1	,1	, &A8AB01LDU},	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
	{ 422	,1	,1	, &A2VS11LDU},	//( - , DU) Движение РБ1 в сторону ВУ
	{ 423	,8	,1	, &A2CV01RDU},	//( - , DU) Измеренная скорость перемещения РБ1
	{ 424	,1	,1	, &A2AB04LDU},	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
	{ 425	,1	,1	, &A2AB02LDU},	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
	{ 426	,1	,1	, &A2AB01LDU},	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
	{ 427	,1	,1	, &A2VS21LDU},	//( - , DU) Движение РБ1 в сторону НУ
	{ 428	,1	,1	, &A2AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
	{ 429	,1	,1	, &A2AD11LDU},	//(fds16:07 - K01FDSR, - ) Сигнал на перемещение РБ1 вверх
	{ 430	,1	,1	, &A2AD21LDU},	//(fds16:07 - K02FDSR, - ) Сигнал на перемещение РБ1 вниз
	{ 431	,1	,1	, &A2AD02LDU},	//(fds16:07 - K04FDSR, - ) 0-й бит скорости РБ1
	{ 432	,1	,1	, &A2AD03LDU},	//(fds16:07 - K05FDSR, - ) 1-й бит скорости РБ1
	{ 433	,1	,1	, &A2AD04LDU},	//(fds16:07 - K06FDSR, - ) 2-й бит скорости РБ1
	{ 434	,1	,1	, &A2AD05LDU},	//(fds16:07 - K07FDSR, - ) паритет команды на РБ1
	{ 435	,1	,1	, &A2AB07LDU},	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
	{ 436	,1	,1	, &A2AB08LDU},	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
	{ 437	,1	,1	, &A2AB05LDU},	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
	{ 438	,1	,1	, &A2AB06LDU},	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
	{ 439	,1	,1	, &A2AB09LDU},	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
	{ 440	,1	,1	, &B8AB10LDU},	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
	{ 441	,1	,1	, &B8AB11LDU},	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
	{ 442	,1	,1	, &B8AB12LDU},	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
	{ 443	,1	,1	, &B8AB13LDU},	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
	{ 444	,1	,1	, &B8AB14LDU},	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
	{ 445	,1	,1	, &B8AB02LDU},	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
	{ 446	,1	,1	, &A8VS12LDU},	//( - , DU) Движение ДС2 в сторону ВУ
	{ 447	,8	,1	, &A8CV01RDU},	//( - , DU) Измеренная скорость перемещения ДС2
	{ 448	,1	,1	, &A8AB06LDU},	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
	{ 449	,1	,1	, &A8AB07LDU},	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
	{ 450	,1	,1	, &A8AB05LDU},	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
	{ 451	,1	,1	, &A8VS22LDU},	//( - , DU) Движение ДС2 в сторону НУ
	{ 452	,1	,1	, &A8AZ03LDU},	//( - , DU) Несанкционированное перемещение ДС2
	{ 453	,1	,1	, &A8AD10LDU},	//(fds16:09 - K07FDSR, - ) Перемещение ДС2 вперед
	{ 454	,1	,1	, &A8AD20LDU},	//(fds16:09 - K08FDSR, - ) Перемещение ДС2 назад
	{ 455	,1	,1	, &B8IS22LDU},	//(vds32:04 - K22VDSR, DU) Приход на НУ2 АЗ2
	{ 456	,1	,1	, &A8IS12LDU},	//(vds32:04 - K30VDSR, DU) Приход на механический ВУ ДС2
	{ 457	,1	,1	, &A8AB04LDU},	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
	{ 458	,1	,1	, &A8IS22LDU},	//(vds32:04 - K31VDSR, DU) Приход на механический НУ ДС2
	{ 459	,1	,1	, &A8AB08LDU},	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{ 460	,1	,1	, &A8AB09LDU},	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
	{ 461	,1	,1	, &A8AB10LDU},	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
	{ 462	,1	,1	, &A8AB11LDU},	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	{ 463	,1	,1	, &B6IS21LDU},	//(vds32:04 - K14VDSR, DU) Приход на НУ БЗ2
	{ 464	,1	,1	, &A6VS22LDU},	//(vds32:0d - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
	{ 465	,1	,1	, &A6VS12LDU},	//(vds32:0d - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
	{ 466	,1	,1	, &B6VS22LDU},	//(vds32:0d - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
	{ 467	,1	,1	, &B6VS12LDU},	//(vds32:0d - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
	{ 468	,1	,1	, &A6AD10LDU},	//(fds16:09 - K09FDSR, - ) Открыть БЗ1
	{ 469	,1	,1	, &A6AD20LDU},	//(fds16:09 - K10FDSR, - ) Закрыть БЗ1
	{ 470	,1	,1	, &B6AD10LDU},	//(fds16:09 - K11FDSR, - ) Открыть БЗ2
	{ 471	,1	,1	, &B6AD20LDU},	//(fds16:09 - K12FDSR, - ) Закрыть БЗ2
	{ 472	,1	,1	, &A6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ1
	{ 473	,1	,1	, &A6AB01LDU},	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
	{ 474	,1	,1	, &A6AB02LDU},	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
	{ 475	,1	,1	, &B6AZ03LDU},	//( - , DU) Несанкционированное перемещение БЗ2
	{ 476	,1	,1	, &B6AB01LDU},	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
	{ 477	,1	,1	, &B6AB02LDU},	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
	{ 478	,1	,1	, &A6AB04LDU},	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
	{ 479	,1	,1	, &B6AB04LDU},	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
	{ 480	,1	,1	, &R4AB01LDU},	//( - , DU) Блокировка движения тележки - АНИ не установлен
	{ 481	,1	,1	, &R8IS11LDU},	//(vds32:02 - K14VDSR, DU) Аварийный НИ установлен
	{ 482	,1	,1	, &R6IS21LDU},	//(vds32:04 - K29VDSR, - ) Кран-балка в нерабочем положении
	{ 483	,1	,1	, &A0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ1
	{ 484	,1	,1	, &A0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ1
	{ 485	,1	,1	, &R0NE01LDU},	//( - , DU) Потеря связи с БАЗ1
	{ 486	,3	,1	, &R0MW15IP1},	//( - , DU) Переключатель МОЩНОСТЬ В СТАТИЧЕСКОМ РЕЖИМЕ
	{ 487	,3	,1	, &R0MW14IP1},	//( - , DU) Переключатель ПРОГРАММЫ
	{ 488	,3	,1	, &R0MW12IP1},	//( - , DU) Переключатель РЕЖИМ РАБОТЫ
	{ 489	,3	,1	, &R0MW13IP1},	//( - , DU) Переключатель ВЫБОР ЗОН
	{ 490	,3	,1	, &R0MW16IP1},	//( - , DU) Переключатель ВИД ПРОВЕРКИ
	{ 491	,3	,1	, &R0MW11IP1},	//( - , DU) Переключатель ВЫСТРЕЛ
	{ 492	,3	,1	, &R0MW11IP2},	//( - , DU) Переключатель ПРОВЕРКА СХЕМ СБРОСА
	{ 493	,1	,1	, &R0MW13LP2},	//( - , DU) Переключатель СЕТЬ
	{ 494	,1	,1	, &R0MD32LP1},	//( - , DU) Кнопка СПУСК
	{ 495	,1	,1	, &R0MD31LP1},	//( - , DU) Кнопка СТОП
	{ 496	,1	,1	, &A1IS21LDU},	//(vds32:03 - K09VDSR, DU) Приход на НУ ББ1
	{ 497	,1	,1	, &A2IS21LDU},	//(vds32:03 - K12VDSR, DU) Приход на НУ РБ1-СС
	{ 498	,1	,1	, &A3IS21LDU},	//(vds32:03 - K13VDSR, DU) Приход на НУ ИС1
	{ 499	,1	,1	, &B1IS21LDU},	//(vds32:02 - K09VDSR, DU) Приход на НУ ББ2
	{ 500	,1	,1	, &B2IS21LDU},	//(vds32:02 - K12VDSR, DU) Приход на НУ РБ2-СС
	{ 501	,1	,1	, &B3IS21LDU},	//(vds32:02 - K13VDSR, DU) Приход на НУ ИС2
	{ 502	,1	,1	, &R0ES01LDU},	//( - , DU) ОРР не в исходном состоянии
	{ 503	,1	,1	, &R4MD11LP2},	//( - , DU) Кнопка ВПЕРЁД  (тележки)
	{ 504	,1	,1	, &R4MD31LP2},	//( - , DU) Кнопка СТОП  (тележки)
	{ 505	,1	,1	, &R4MD21LP2},	//( - , DU) Кнопка НАЗАД  (тележки)
	{ 506	,1	,1	, &A6IS11LDU},	//(vds32:04 - K09VDSR, DU) Приход на ВУ БЗ1
	{ 507	,1	,1	, &A6IS21LDU},	//(vds32:04 - K10VDSR, DU) Приход на НУ БЗ1
	{ 508	,1	,1	, &B6IS11LDU},	//(vds32:04 - K13VDSR, DU) Приход на ВУ БЗ2
	{ 509	,1	,1	, &B4IS11LDU},	//(vds32:02 - K31VDSR, DU) Приход на ВУ НИ2
	{ 510	,1	,1	, &R4AB13LDU},	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
	{ 511	,1	,1	, &R4AB14LDU},	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
	{ 512	,1	,1	, &R4AB15LDU},	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
	{ 513	,1	,1	, &R5IS11LDU},	//(vds32:04 - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
	{ 514	,1	,1	, &R4AB16LDU},	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
	{ 515	,1	,1	, &R4AB17LDU},	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	{ 516	,1	,1	, &R4AB18LDU},	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	{ 517	,1	,1	, &R4AD10LDU},	//(fds16:09 - K13FDSR, - ) Перемещение тележки вперед
	{ 518	,1	,1	, &R4AD20LDU},	//(fds16:09 - K14FDSR, DU) Перемещение тележки назад
	{ 519	,1	,1	, &A5VS22LDU},	//(vds32:0d - K12VDSR, DU) Движение НЛ1 в сторону НУ
	{ 520	,1	,1	, &A5VS12LDU},	//(vds32:0d - K11VDSR, DU) Движение НЛ1 в сторону ВУ
	{ 521	,1	,1	, &B5VS22LDU},	//(vds32:0d - K15VDSR, DU) Движение НЛ2 в сторону НУ
	{ 522	,1	,1	, &B5VS12LDU},	//(vds32:0d - K14VDSR, DU) Движение НЛ2 в сторону ВУ
	{ 523	,1	,1	, &B5AD10LDU},	//(fds16:0a - K13FDSR, - ) Поднять НЛ2
	{ 524	,1	,1	, &B5AD20LDU},	//(fds16:0a - K14FDSR, - ) Опустить НЛ2
	{ 525	,1	,1	, &A5AD10LDU},	//(fds16:0a - K11FDSR, - ) Поднять НЛ1
	{ 526	,1	,1	, &A5AD20LDU},	//(fds16:0a - K12FDSR, - ) Опустить НЛ1
	{ 527	,1	,1	, &A5IS11LDU},	//(vds32:04 - K11VDSR, DU) Приход на ВУ НЛ1
	{ 528	,1	,1	, &A5IS21LDU},	//(vds32:04 - K12VDSR, DU) Приход на НУ НЛ1
	{ 529	,1	,1	, &B5IS11LDU},	//(vds32:04 - K15VDSR, DU) Приход на ВУ НЛ2
	{ 530	,1	,1	, &B5IS21LDU},	//(vds32:04 - K16VDSR, DU) Приход на НУ НЛ2
	{ 531	,1	,1	, &A5AZ03LDU},	//( - , DU) Несанкционированное перемещение НЛ1
	{ 532	,1	,1	, &R0NE02LDU},	//( - , DU) Потеря связи с БАЗ2
	{ 533	,1	,1	, &R4AB02LDU},	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
	{ 534	,1	,1	, &R0NE08LDU},	//( - , DU) Потеря связи с ОПУ
	{ 535	,1	,1	, &R4IS21LDU},	//(vds32:04 - K07VDSR, DU) Приход на НУ1 тележки
	{ 536	,1	,1	, &R4IS22LDU},	//(vds32:04 - K08VDSR, DU) Приход на НУ2 тележки
	{ 537	,1	,1	, &R4IS12LDU},	//(vds32:04 - K06VDSR, DU) Приход на ВУ2 тележки
	{ 538	,1	,1	, &R4VS22LDU},	//(vds32:0d - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
	{ 539	,1	,1	, &R4VS12LDU},	//(vds32:0d - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
	{ 540	,1	,1	, &R4AZ03LDU},	//( - , DU) Несанкционированное перемещение тележки
	{ 541	,1	,1	, &R4AB03LDU},	//( - , DU) Блокировка движения тележки - Самоход любого механизма
	{ 542	,1	,1	, &R1IS21LDU},	//(vds32:02 - K28VDSR, DU) Приход на НУ МДЗ1
	{ 543	,1	,1	, &R2IS21LDU},	//(vds32:02 - K30VDSR, DU) Приход на НУ МДЗ2
	{ 544	,1	,1	, &R4AB04LDU},	//( - , DU) Блокировка движения тележки - Превышение времени движения
	{ 545	,1	,1	, &R4AB05LDU},	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
	{ 546	,1	,1	, &R4AB06LDU},	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
	{ 547	,1	,1	, &R4AB07LDU},	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
	{ 548	,1	,1	, &R4AB08LDU},	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	{ 549	,1	,1	, &R4AB09LDU},	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
	{ 550	,1	,1	, &B0VN71LZ1},	//( - , MDuBz1) АЗ по АС мощности для АЗ2
	{ 551	,1	,1	, &B0VN71LZ2},	//( - , MDuBz2) АЗ по АС мощности для АЗ2
	{ 552	,1	,1	, &R4AB10LDU},	//( - , DU) Блокировка тележки - не открыта биологическая защита
	{ 553	,1	,1	, &R4AB11LDU},	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
	{ 554	,1	,1	, &R4AB12LDU},	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
	{ 555	,1	,1	, &A4IS11LDU},	//(vds32:03 - K14VDSR, DU) Приход на ВУ НИ1
	{ 556	,1	,1	, &A3AD03LDU},	//(fds16:0b - K05FDSR, - ) 1-й бит скорости ИС1
	{ 557	,1	,1	, &A3AD04LDU},	//(fds16:0b - K06FDSR, - ) 2-й бит скорости ИС1
	{ 558	,1	,1	, &A3AD05LDU},	//(fds16:0b - K07FDSR, - ) паритет команды на ИС1
	{ 559	,1	,1	, &A3AD01LDU},	//(fds16:0b - K03FDSR, - ) Разрешение движения ИС1
	{ 560	,8	,1	, &A3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС1
	{ 561	,1	,1	, &A3AB07LDU},	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	{ 562	,1	,1	, &A3AB08LDU},	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	{ 563	,1	,1	, &A3AB05LDU},	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	{ 564	,1	,1	, &A3AB06LDU},	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	{ 565	,1	,1	, &A3AB09LDU},	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
	{ 566	,1	,1	, &A3AB10LDU},	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
	{ 567	,1	,1	, &A3AB11LDU},	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	{ 568	,1	,1	, &A3AB12LDU},	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 569	,1	,1	, &A3AB14LDU},	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	{ 570	,1	,1	, &A3AB16LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
	{ 571	,1	,1	, &A3AB17LDU},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
	{ 572	,1	,1	, &A3AB18LDU},	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	{ 573	,1	,1	, &A3AB20LDU},	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
	{ 574	,1	,1	, &B3VS12LDU},	//( - , DU) Движение ИС2 в сторону ВУ
	{ 575	,1	,1	, &B3AB04LDU},	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
	{ 576	,1	,1	, &B3AB02LDU},	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
	{ 577	,1	,1	, &B3AB01LDU},	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
	{ 578	,1	,1	, &B3VS22LDU},	//( - , DU) Движение ИС2 в сторону НУ
	{ 579	,1	,1	, &B1AB07LDU},	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{ 580	,1	,1	, &B1AB08LDU},	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{ 581	,1	,1	, &B1AB05LDU},	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{ 582	,1	,1	, &B1AB06LDU},	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{ 583	,1	,1	, &B1AB09LDU},	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
	{ 584	,1	,1	, &B1AB10LDU},	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{ 585	,1	,1	, &B1AB11LDU},	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{ 586	,1	,1	, &B1AB12LDU},	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 587	,1	,1	, &B1AB13LDU},	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
	{ 588	,1	,1	, &B1AB14LDU},	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{ 589	,1	,1	, &B1AB16LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
	{ 590	,1	,1	, &B1AB17LDU},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{ 591	,1	,1	, &B1AB18LDU},	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{ 592	,1	,1	, &A3VS12LDU},	//( - , DU) Движение ИС1 в сторону ВУ
	{ 593	,8	,1	, &A3CV01RDU},	//( - , DU) Измеренная скорость перемещения ИС1
	{ 594	,1	,1	, &A3AB04LDU},	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
	{ 595	,1	,1	, &A3AB02LDU},	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
	{ 596	,1	,1	, &A3AB01LDU},	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
	{ 597	,1	,1	, &A3VS22LDU},	//( - , DU) Движение ИС1 в сторону НУ
	{ 598	,1	,1	, &A3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
	{ 599	,1	,1	, &A3AD11LDU},	//(fds16:0b - K01FDSR, - ) Сигнал на перемещение ИС1 вверх
	{ 600	,1	,1	, &A3AD21LDU},	//(fds16:0b - K02FDSR, - ) Сигнал на перемещение ИС1 вниз
	{ 601	,1	,1	, &A3AD02LDU},	//(fds16:0b - K04FDSR, - ) 0-й бит скорости ИС1
	{ 602	,1	,1	, &A2AD31LDU},	//(fds16:0f - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
	{ 603	,1	,1	, &B2AD31LDU},	//(fds16:0f - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
	{ 604	,1	,1	, &A1AD31LDU},	//(fds16:0f - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
	{ 605	,1	,1	, &B1AD31LDU},	//(fds16:0f - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
	{ 606	,1	,1	, &A2AD32LDU},	//(fds16:0f - K03FDSR, - ) Обесточить ЭМ РБ1
	{ 607	,1	,1	, &B2AD32LDU},	//(fds16:0f - K07FDSR, - ) Обесточить ЭМ РБ2
	{ 608	,1	,1	, &A1AD32LDU},	//(fds16:0f - K01FDSR, - ) Обесточить ЭМ ББ1
	{ 609	,1	,1	, &B1AD32LDU},	//(fds16:0f - K05FDSR, - ) Обесточить ЭМ ББ2
	{ 610	,1	,1	, &R0MD11LP2},	//( - , DU) Кнопка Пуск проверки схем сброса
	{ 611	,1	,1	, &R0VX01LDU},	//( - , DU) ДО ИМПУЛЬСА
	{ 612	,3	,1	, &R0VL01IDU},	//( - , DU) До импульса минут
	{ 613	,3	,1	, &R0VL11IDU},	//( - , DU) До импульса секунд
	{ 614	,8	,1	, &R0VL06RDU},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	{ 615	,1	,1	, &B3AD33LDU},	//(fds16:09 - K02FDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
	{ 616	,8	,1	, &R0VL02RDU},	//( - , DU) Индикация (Время задержки ИНИ)
	{ 617	,8	,1	, &R0VL04RDU},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	{ 618	,1	,1	, &R0AB04LDU},	//( - , DU) Нарушение времени срабатывания верхней АС II УР
	{ 619	,1	,1	, &R0AB06LDU},	//( - , DU) Нарушение времени задержки от ВУ РБ
	{ 620	,1	,1	, &R0AB02LDU},	//( - , DU) Нарушение времени задержки ИНИ
	{ 621	,8	,1	, &R0VL03RDU},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{ 622	,8	,1	, &R0VL05RDU},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	{ 623	,3	,1	, &R0VL21IDU},	//( - , DU) Декатрон
	{ 624	,1	,1	, &R0VX03LDU},	//( - , DU) Готовность 2 мин
	{ 625	,1	,1	, &B3AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
	{ 626	,1	,1	, &B3AD11LDU},	//(fds16:0b - K08FDSR, - ) Сигнал на перемещение ИС2 вверх
	{ 627	,1	,1	, &B3AD21LDU},	//(fds16:0b - K09FDSR, - ) Сигнал на перемещение ИС2 вниз
	{ 628	,1	,1	, &B3AD02LDU},	//(fds16:0b - K11FDSR, - ) 0-й бит скорости ИС2
	{ 629	,1	,1	, &B3AD03LDU},	//(fds16:0b - K12FDSR, - ) 1-й бит скорости ИС2
	{ 630	,1	,1	, &B3AD04LDU},	//(fds16:0b - K13FDSR, - ) 2-й бит скорости ИС2
	{ 631	,1	,1	, &B3AD05LDU},	//(fds16:0b - K14FDSR, - ) паритет команды на ИС2
	{ 632	,1	,1	, &B3AD01LDU},	//(fds16:0b - K10FDSR, - ) Разрешение движения ИС2
	{ 633	,8	,1	, &B3CV02RDU},	//( - , DU) Заданная скорость перемещения ИС2
	{ 634	,1	,1	, &B3AB07LDU},	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	{ 635	,1	,1	, &B3AB08LDU},	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	{ 636	,1	,1	, &B3AB05LDU},	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	{ 637	,1	,1	, &B3AB06LDU},	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	{ 638	,1	,1	, &B3AB09LDU},	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
	{ 639	,1	,1	, &B3AB10LDU},	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
	{ 640	,1	,1	, &B3AB11LDU},	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	{ 641	,1	,1	, &B3AB12LDU},	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 642	,1	,1	, &B3AB14LDU},	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	{ 643	,1	,1	, &B3AB16LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
	{ 644	,1	,1	, &B3AB17LDU},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
	{ 645	,1	,1	, &B3AB18LDU},	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	{ 646	,1	,1	, &B3AB20LDU},	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
	{ 647	,1	,1	, &C1MD31LP1},	//( - , DU) Кнопка СБРОС ББ
	{ 648	,1	,1	, &C1MD31LP2},	//( - , DU) Кнопка СБРОС ББ
	{ 649	,1	,1	, &B2AB08LDU},	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{ 650	,1	,1	, &B2AB05LDU},	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{ 651	,1	,1	, &B2AB06LDU},	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{ 652	,1	,1	, &B2AB09LDU},	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
	{ 653	,1	,1	, &B2AB10LDU},	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{ 654	,1	,1	, &B2AB11LDU},	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{ 655	,1	,1	, &B2AB12LDU},	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{ 656	,1	,1	, &B2AB13LDU},	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
	{ 657	,1	,1	, &B2AB14LDU},	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{ 658	,1	,1	, &B2AB16LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
	{ 659	,1	,1	, &B2AB17LDU},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{ 660	,1	,1	, &R1AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ1
	{ 661	,1	,1	, &R1AB01LDU},	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
	{ 662	,1	,1	, &R1AB02LDU},	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
	{ 663	,1	,1	, &R2AZ03LDU},	//( - , DU) Несанкционированное перемещение МДЗ2
	{ 664	,1	,1	, &R2AB01LDU},	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
	{ 665	,1	,1	, &R2AB02LDU},	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
	{ 666	,1	,1	, &R1AB04LDU},	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
	{ 667	,1	,1	, &R2AB04LDU},	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
	{ 668	,1	,1	, &R1AD10LDU},	//(fds16:0a - K07FDSR, - ) Опустить МДЗ1
	{ 669	,1	,1	, &R1AD20LDU},	//(fds16:0a - K08FDSR, - ) Поднять МДЗ1
	{ 670	,1	,1	, &R1IS11LDU},	//(vds32:02 - K27VDSR, DU) Приход на ВУ МДЗ1
	{ 671	,1	,1	, &R1VS22LDU},	//(vds32:0d - K06VDSR, DU) Движение МДЗ1 в сторону НУ
	{ 672	,1	,1	, &A2AB10LDU},	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
	{ 673	,1	,1	, &A2AB11LDU},	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	{ 674	,1	,1	, &A2AB12LDU},	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 675	,1	,1	, &A2AB13LDU},	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
	{ 676	,1	,1	, &A2AB14LDU},	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	{ 677	,1	,1	, &A2AB16LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
	{ 678	,1	,1	, &A2AB17LDU},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{ 679	,1	,1	, &A2AD01LDU},	//(fds16:07 - K03FDSR, - ) Разрешение движения РБ1
	{ 680	,8	,1	, &A2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ1
	{ 681	,8	,1	, &B2CV01RDU},	//( - , DU) Измеренная скорость перемещения РБ2
	{ 682	,1	,1	, &B2AB04LDU},	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
	{ 683	,1	,1	, &B2AB02LDU},	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
	{ 684	,1	,1	, &B2AB01LDU},	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
	{ 685	,1	,1	, &B2AZ03LDU},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
	{ 686	,1	,1	, &B2AD11LDU},	//(fds16:07 - K08FDSR, - ) Сигнал на перемещение РБ2 вверх
	{ 687	,1	,1	, &B2AD21LDU},	//(fds16:07 - K09FDSR, - ) Сигнал на перемещение РБ2 вниз
	{ 688	,1	,1	, &B2AD02LDU},	//(fds16:07 - K11FDSR, - ) 0-й бит скорости РБ2
	{ 689	,1	,1	, &B2AD03LDU},	//(fds16:07 - K12FDSR, - ) 1-й бит скорости РБ2
	{ 690	,1	,1	, &B2AD04LDU},	//(fds16:07 - K13FDSR, - ) 2-й бит скорости РБ2
	{ 691	,1	,1	, &B2AD05LDU},	//(fds16:07 - K14FDSR, - ) паритет команды на РБ2
	{ 692	,1	,1	, &B2AD01LDU},	//(fds16:07 - K10FDSR, - ) Разрешение движения РБ2
	{ 693	,8	,1	, &B2CV02RDU},	//( - , DU) Заданная скорость перемещения РБ2
	{ 694	,1	,1	, &B2AB07LDU},	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	{ 695	,1	,1	, &A1AB10LDU},	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
	{ 696	,1	,1	, &A1AB11LDU},	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	{ 697	,1	,1	, &A1AB12LDU},	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{ 698	,1	,1	, &A1AB13LDU},	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
	{ 699	,1	,1	, &A1AB14LDU},	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	{ 700	,1	,1	, &A1AB16LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
	{ 701	,1	,1	, &A1AB17LDU},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
	{ 702	,1	,1	, &A1AB18LDU},	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	{ 703	,1	,1	, &B1VS12LDU},	//( - , DU) Движение ББ2 в сторону ВУ
	{ 704	,8	,1	, &B1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ2
	{ 705	,1	,1	, &B1AB04LDU},	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
	{ 706	,1	,1	, &B1AB02LDU},	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
	{ 707	,1	,1	, &B1AB01LDU},	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
	{ 708	,1	,1	, &B1VS22LDU},	//( - , DU) Движение ББ2 в сторону НУ
	{ 709	,1	,1	, &B1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
	{ 710	,1	,1	, &B1AD11LDU},	//(fds16:08 - K08FDSR, - ) Сигнал на перемещение ББ2 вверх
	{ 711	,1	,1	, &B1AD21LDU},	//(fds16:08 - K09FDSR, - ) Сигнал на перемещение ББ2 вниз
	{ 712	,1	,1	, &B1AD02LDU},	//(fds16:08 - K11FDSR, - ) 0-й бит скорости ББ2
	{ 713	,1	,1	, &B1AD03LDU},	//(fds16:08 - K12FDSR, - ) 1-й бит скорости ББ2
	{ 714	,1	,1	, &B1AD04LDU},	//(fds16:08 - K13FDSR, - ) 2-й бит скорости ББ2
	{ 715	,1	,1	, &B1AD05LDU},	//(fds16:08 - K14FDSR, - ) паритет команды на ББ2
	{ 716	,1	,1	, &B1AD01LDU},	//(fds16:08 - K10FDSR, - ) Разрешение движения ББ2
	{ 717	,8	,1	, &B1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ2
	{ 718	,1	,1	, &R2VS22LDU},	//(vds32:0d - K09VDSR, DU) Движение МДЗ2 в сторону НУ
	{ 719	,1	,1	, &R2VS12LDU},	//(vds32:0d - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
	{ 720	,1	,1	, &R1VS12LDU},	//(vds32:0d - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
	{ 721	,1	,1	, &R2IS11LDU},	//(vds32:02 - K29VDSR, DU) Приход на ВУ МДЗ2
	{ 722	,1	,1	, &A1VS12LDU},	//( - , DU) Движение ББ1 в сторону ВУ
	{ 723	,8	,1	, &A1CV01RDU},	//( - , DU) Измеренная скорость перемещения ББ1
	{ 724	,1	,1	, &A1AB04LDU},	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
	{ 725	,1	,1	, &A1AB02LDU},	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
	{ 726	,1	,1	, &A1AB01LDU},	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
	{ 727	,1	,1	, &A1VS22LDU},	//( - , DU) Движение ББ1 в сторону НУ
	{ 728	,1	,1	, &A1AZ03LDU},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
	{ 729	,1	,1	, &A1AD11LDU},	//(fds16:08 - K01FDSR, - ) Сигнал на перемещение ББ1 вверх
	{ 730	,1	,1	, &A1AD21LDU},	//(fds16:08 - K02FDSR, - ) Сигнал на перемещение ББ1 вниз
	{ 731	,1	,1	, &A1AD02LDU},	//(fds16:08 - K04FDSR, - ) 0-й бит скорости ББ1
	{ 732	,1	,1	, &A1AD03LDU},	//(fds16:08 - K05FDSR, - ) 1-й бит скорости ББ1
	{ 733	,1	,1	, &A1AD04LDU},	//(fds16:08 - K06FDSR, - ) 2-й бит скорости ББ1
	{ 734	,1	,1	, &A1AD05LDU},	//(fds16:08 - K07FDSR, - ) паритет команды на ББ1
	{ 735	,1	,1	, &A1AD01LDU},	//(fds16:08 - K03FDSR, - ) Разрешение движения ББ1
	{ 736	,8	,1	, &A1CV02RDU},	//( - , DU) Заданная скорость перемещения ББ1
	{ 737	,1	,1	, &A1AB07LDU},	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	{ 738	,1	,1	, &A1AB08LDU},	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	{ 739	,1	,1	, &A1AB05LDU},	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	{ 740	,1	,1	, &A1AB06LDU},	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{ 741	,1	,1	, &A1AB09LDU},	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
	{ 742	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показаний энкодера ББ, мм/дел.энкодера
	{ 743	,5	,1	, &dEM_A1UC05UDU},	//(A1UC05UDU) Верхняя граница показания энкодера ББ, деления энкодера
	{ 744	,5	,1	, &dEM_A1UC06UDU},	//(A1UC06UDU) Нижняя граница показания энкодера ББ, деления энкодера
	{ 745	,5	,1	, &dEM_A2UC06UDU},	//(A2UC06UDU) Нижняя граница показания энкодера РБ, деления энкодера
	{ 746	,5	,1	, &dEM_A2UC05UDU},	//(A2UC05UDU) Верхняя граница показания энкодера РБ, деления энкодера
	{ 747	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показаний энкодера РБ, мм/дел.энкодера
	{ 748	,5	,1	, &dEM_A3UC06UDU},	//(A3UC06UDU) Нижняя граница показания энкодера ИС, деления энкодера
	{ 749	,5	,1	, &dEM_A3UC05UDU},	//(A3UC05UDU) Верхняя граница показания энкодера ИС, деления энкодера
	{ 750	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показаний энкодера ИС, мм/дел.энкодера
	{ 751	,5	,1	, &dEM_A8UC06UDU},	//(A8UC06UDU) Нижняя граница показания энкодера АЗ2, деления энкодера
	{ 752	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показаний энкодера АЗ2/ДС2, мм/дел.энкодера
	{ 753	,5	,1	, &dEM_A8UC05UDU},	//(A8UC05UDU) Верхняя граница показания энкодера АЗ2/ДС2, деления энкодера
	{ 754	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 755	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 2-я частота двигателя (шагов/секунду)
	{ 756	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 3-я частота двигателя (шагов/секунду)
	{ 757	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 4-я частота двигателя (шагов/секунду)
	{ 758	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 759	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 760	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 8-я скорость перемещения ББ (шагов/секунду)
	{ 761	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 762	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 763	,8	,1	, &fEM_A3UP43RDU},	//(A3UP43RDU) Уровень срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС
	{ 764	,8	,1	, &fEM_A3UP44RDU},	//(A3UP44RDU) Граница неоднозначности срабатывания аварийной сигнализации по давлению ВЫСТРЕЛ ИС (МПа)
	{ 765	,8	,1	, &fEM_A3UP53RDU},	//(A3UP53RDU) Уровень срабатывания предупредительной по давлению ВЫСТРЕЛ ИС (МПа)
	{ 766	,8	,1	, &fEM_A3UP85RDU},	//(A3UP85RDU) Нижняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 767	,8	,1	, &fEM_A3UP88RDU},	//(A3UP88RDU) Верхняя граница неоднозначности нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 768	,8	,1	, &fEM_A3UP86RDU},	//(A3UP86RDU) Нижняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 769	,8	,1	, &fEM_B8UV01RDU},	//(B8UV01RDU) Допустимое превышение заданной скорости АЗ2,ДС2 мм/с
	{ 770	,8	,1	, &fEM_B8UV02RDU},	//(B8UV02RDU) Допустимое отклонение скорости АЗ2,ДС2 от заданной в меньшую сторону, мм/с
	{ 771	,8	,1	, &fEM_B8UV03RDU},	//(B8UV03RDU) Номинальная скорость перемещения АЗ2,ДС2 мм/с
	{ 772	,8	,1	, &fEM_B8UL04RDU},	//(B8UL04RDU) Задержка определения самохода АЗ-ДС после команды на останов, сек
	{ 773	,3	,1	, &iEM_A2UV03CDU},	//(A2UV03CDU) Скорость 1-го диапазона РБ назад (вниз)
	{ 774	,8	,1	, &fEM_A2UV01RDU},	//(A2UV01RDU) Допустимое превышение заданной скорости РБ мм/с
	{ 775	,8	,1	, &fEM_A2UV02RDU},	//(A2UV02RDU) Допустимое отклонение скорости РБ от заданной в меньшую сторону, мм/сек
	{ 776	,8	,1	, &fEM_A1UV01RDU},	//(A1UV01RDU) Допустимое превышение заданной скорости ББ мм/с
	{ 777	,8	,1	, &fEM_A1UV02RDU},	//(A1UV02RDU) Допустимое отклонение скорости ББ от заданной в меньшую сторону, мм/сек
	{ 778	,8	,1	, &fEM_A1UC06RDU},	//(A1UC06RDU) Уставка определения самохода ББ  мм
	{ 779	,8	,1	, &fEM_A1UC05RDU},	//(A1UC05RDU) Минимальное перемещение для измерения скорости ББ(для блокировок по направлению и отсутствию движения), мм
	{ 780	,8	,1	, &fEM_A1UL04RDU},	//(A1UL04RDU) Задержка определения самохода ББ после команды на останов, сек
	{ 781	,8	,1	, &fEM_A3UV01RDU},	//(A3UV01RDU) Допустимое превышение заданной скорости ИС мм/с
	{ 782	,8	,1	, &fEM_A3UV02RDU},	//(A3UV02RDU) Допустимое отклонение скорости ИС от заданной в меньшую сторону, мм/сек
	{ 783	,8	,1	, &fEM_A3UC06RDU},	//(A3UC06RDU) Уставка определения самохода ИС1  мм
	{ 784	,8	,1	, &fEM_A3UC05RDU},	//(A3UC05RDU) Минимальное перемещение для измерения скорости ИС(для блокировок по направлению и отсутствию движения), мм
	{ 785	,8	,1	, &fEM_A3UL04RDU},	//(A3UL04RDU) Задержка определения самохода ИС после команды на останов, сек
	{ 786	,8	,1	, &fEM_A3UP54RDU},	//(A3UP54RDU) Граница неоднозначности срабатывания предупредительной сигнализации по давлению ВЫСТРЕЛ ИС(МПа)
	{ 787	,8	,1	, &fEM_A3UP87RDU},	//(A3UP87RDU) Верхняя граница нормализации давления ВЫСТРЕЛ ИС (МПа)
	{ 788	,8	,1	, &fEM_R0UL05RDU},	//(R0UL05RDU) Время срабатывания сброса от НУП ИС
	{ 789	,8	,1	, &fEM_R0UL20RDU},	//(R0UL20RDU) Предельное отклонение от времени задержки  сброса от II УР
	{ 790	,8	,1	, &fEM_B8UV04RDU},	//(B8UV04RDU) Время разгона механизма при переходе на новую скорость сек
	{ 791	,8	,1	, &fEM_B8UC06RDU},	//(B8UC06RDU) Уставка определения самохода АЗ-ДС,  мм
	{ 792	,8	,1	, &fEM_B8UC05RDU},	//(B8UC05RDU) Минимальное перемещение для измерения скорости АЗ-ДС(для блокировок по направлению и отсутствию движения), мм
	{ 793	,8	,1	, &fEM_A2UL05RDU},	//(A2UL05RDU) Время задержки блокировки РБ по недвижению сек
	{ 794	,8	,1	, &fEM_A2UL03RDU},	//(A2UL03RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 795	,8	,1	, &fEM_A2UC06RDU},	//(A2UC06RDU) Уставка определения самохода РБ  мм
	{ 796	,8	,1	, &fEM_A2UC05RDU},	//(A2UC05RDU) Минимальное перемещение для измерения скорости РБ(для блокировок по направлению и отсутствию движения), мм
	{ 797	,8	,1	, &fEM_A2UL04RDU},	//(A2UL04RDU) Задержка определения самохода РБ после команды на останов, с
	{ 798	,8	,1	, &fEM_A1UL03RDU},	//(A1UL03RDU) Задержка определения самохода ББ после останова (достижения скорости 0), с
	{ 799	,8	,1	, &fEM_A1UL05RDU},	//(A1UL05RDU) Время задержки блокировки ББ по недвижению с
	{ 800	,8	,1	, &fEM_A3UL03RDU},	//(A3UL03RDU) Задержка определения самохода ИС после останова (достижения скорости 0), сек
	{ 801	,8	,1	, &fEM_A3UL05RDU},	//(A3UL05RDU) Время задержки блокировки ИС по недвижению сек
	{ 802	,8	,1	, &fEM_A1UC08RDU},	//(A1UC08RDU) Зона нечувствительности при наведении ББ  мм
	{ 803	,8	,1	, &fEM_A3UC08RDU},	//(A3UC08RDU) Зона нечувствительности при наведении ИС 0.01 мм
	{ 804	,8	,1	, &fEM_A1UC07RDU},	//(A1UC07RDU) Зона возврата при наведении ББ мм
	{ 805	,8	,1	, &fEM_A1UL01RDU},	//(A1UL01RDU) Время нахождения координаты ББ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 806	,8	,1	, &fEM_A3UC07RDU},	//(A3UC07RDU) Зона возврата при наведении ИС 0.01 мм
	{ 807	,8	,1	, &fEM_A3UL01RDU},	//(A3UL01RDU) Время нахождения координаты ИС в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 808	,8	,1	, &fEM_A2UC08RDU},	//(A2UC08RDU) Зона нечувствительности при наведении РБ мм
	{ 809	,8	,1	, &fEM_A2UC07RDU},	//(A2UC07RDU) Зона возврата при наведении РБ  мм
	{ 810	,8	,1	, &fEM_A2UL01RDU},	//(A2UL01RDU) Время нахождения координаты РБ в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 811	,8	,1	, &fEM_B8UC01RDU},	//(B8UC01RDU) Зона нечувствительности при наведении АЗ2,ДС2 мм
	{ 812	,8	,1	, &fEM_B8UL07RDU},	//(B8UL07RDU) Время задержки блокировки АЗ2,ДС2 по превышению времени движения сек
	{ 813	,8	,1	, &fEM_B8UC02RDU},	//(B8UC02RDU) Зона возврата при наведении АЗ2,ДС2  мм
	{ 814	,8	,1	, &fEM_B8UL01RDU},	//(B8UL01RDU) Время нахождения координаты АЗ2,ДС2 в зоне возврата, после которого происходит расширение зоны нечувствительности, сек
	{ 815	,8	,1	, &fEM_B8UL05RDU},	//(B8UL05RDU) Время задержки сигнализации по недвижению АЗ2,ДС2 сек
	{ 816	,8	,1	, &fEM_B8UL03RDU},	//(B8UL03RDU) Задержка определения самохода АЗ2,ДС2 после останова (достижения скорости 0), сек
	{ 817	,8	,1	, &fEM_B8UL06RDU},	//(B8UL06RDU) Время задержки блокировки АЗ2,ДС2 по недвижению сек
	{ 818	,8	,1	, &fEM_A9UZ03RDU},	//(A9UZ03RDU) Время задержки блокировки НИ  ДС по самоходу сек
	{ 819	,8	,1	, &fEM_A9UZ04RDU},	//(A9UZ04RDU) Время задержки блокировки НИ ДС по превышению времени движения сек
	{ 820	,8	,1	, &fEM_A9UZ05RDU},	//(A9UZ05RDU) Время задержки блокировки НИ ДС по недвижению сек
	{ 821	,8	,1	, &fEM_R4UZ04RDU},	//(R4UZ04RDU) Время задержки блокировки тележки по превышению времени движения сек
	{ 822	,8	,1	, &fEM_R4UZ03RDU},	//(R4UZ03RDU) Время задержки блокировки тележки по самоходу сек
	{ 823	,8	,1	, &fEM_R4UZ05RDU},	//(R4UZ05RDU) Время задержки блокировки тележки по недвижению сек
	{ 824	,8	,1	, &fEM_A5UZ03RDU},	//(A5UZ03RDU) Время задержки блокировки НЛ по самоходу сек
	{ 825	,8	,1	, &fEM_A5UZ04RDU},	//(A5UZ04RDU) Время задержки блокировки НЛ по превышению времени движения сек
	{ 826	,8	,1	, &fEM_A5UZ05RDU},	//(A5UZ05RDU) Время задержки блокировки НЛ по недвижению сек
	{ 827	,8	,1	, &fEM_A4UZ03RDU},	//(A4UZ03RDU) Время задержки блокировки НИ по самоходу сек
	{ 828	,8	,1	, &fEM_A4UZ04RDU},	//(A4UZ04RDU) Время задержки блокировки НИ по превышению времени движения сек
	{ 829	,8	,1	, &fEM_A4UZ05RDU},	//(A4UZ05RDU) Время задержки блокировки НИ по недвижению сек
	{ 830	,8	,1	, &fEM_A6UZ03RDU},	//(A6UZ03RDU) Время задержки блокировки БЗ по самоходу сек
	{ 831	,8	,1	, &fEM_A6UZ04RDU},	//(A6UZ04RDU) Время задержки блокировки БЗ по превышению времени движения сек
	{ 832	,8	,1	, &fEM_A6UZ05RDU},	//(A6UZ05RDU) Время задержки блокировки БЗ по недвижению сек
	{ 833	,8	,1	, &fEM_R1UZ03RDU},	//(R1UZ03RDU) Время задержки блокировки МДЗ по самоходу сек
	{ 834	,8	,1	, &fEM_R1UZ04RDU},	//(R1UZ04RDU) Время задержки блокировки МДЗ по превышению времени движения сек
	{ 835	,8	,1	, &fEM_R1UZ05RDU},	//(R1UZ05RDU) Время задержки блокировки МДЗ по недвижению сек
	{ 836	,8	,1	, &fEM_R0UL04RDU},	//(R0UL04RDU) Предельное время ожидания срабатывания АЗ от НУП ИС
	{ 837	,8	,1	, &fEM_R0UL06RDU},	//(R0UL06RDU) Предельное время срабатывания верхней АС II УР
	{ 838	,8	,1	, &fEM_R0UL03RDU},	//(R0UL03RDU) Время срабатывания сброса от ВУ РБ
	{ 839	,8	,1	, &fEM_R0UL17RDU},	//(R0UL17RDU) Предельное отклонение от времени задержки  сброса от ВУ РБ
	{ 840	,8	,1	, &fEM_R0UL19RDU},	//(R0UL19RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 841	,8	,1	, &fEM_R0UL07RDU},	//(R0UL07RDU) Время срабатывания верхней АС II УР
	{ 842	,8	,1	, &fEM_R0UL18RDU},	//(R0UL18RDU) Предельное отклонение от времени задержки  сброса от НУП ИС
	{ 843	,8	,1	, &fEM_R0UL16RDU},	//(R0UL16RDU) Предельное отклонение от времени задержки  ИНИ
	{ 844	,8	,1	, &fEM_R0UL02RDU},	//(R0UL02RDU) Время задержки  ИНИ
	{ 845	,8	,1	, &fEM_R0UN08RDU},	//(R0UN08RDU) 8-я заданная мощность
	{ 846	,8	,1	, &fEM_R0UN07RDU},	//(R0UN07RDU) 7-я заданная мощность
	{ 847	,8	,1	, &fEM_R0UN06RDU},	//(R0UN06RDU) 6-я заданная мощность
	{ 848	,8	,1	, &fEM_R0UN05RDU},	//(R0UN05RDU) 5-я заданная мощность
	{ 849	,8	,1	, &fEM_R0UN04RDU},	//(R0UN04RDU) 4-я заданная мощность
	{ 850	,8	,1	, &fEM_R0UN03RDU},	//(R0UN03RDU) Ограничение 3 по мощности
	{ 851	,8	,1	, &fEM_R0UN02RDU},	//(R0UN02RDU) 2-я заданная мощность
	{ 852	,8	,1	, &fEM_R0UN01RDU},	//(R0UN01RDU) 1-я заданная мощность
	{ 853	,8	,1	, &fEM_A2UC82RDU},	//(A2UC82RDU) Граница 2-го диапазона РБ вперёд (вверх)
	{ 854	,8	,1	, &fEM_A2UC83RDU},	//(A2UC83RDU) Граница 1-го диапазона РБ назад (вниз)
	{ 855	,8	,1	, &fEM_A1UC83RDU},	//(A1UC83RDU) Граница 1-го диапазона ББ назад (вниз)
	{ 856	,8	,1	, &fEM_A2UC81RDU},	//(A2UC81RDU) Граница 1-го диапазона РБ вперёд (вверх)
	{ 857	,8	,1	, &fEM_A1UC81RDU},	//(A1UC81RDU) Граница 1-го диапазона ББ вперёд (вверх)
	{ 858	,8	,1	, &fEM_A1UC82RDU},	//(A1UC82RDU) Граница 2-го диапазона ББ вперёд (вверх)
	{ 859	,8	,1	, &fEM_A2UL83RDU},	//(A2UL83RDU) Задержка определения самохода РБ после останова (достижения скорости 0), с
	{ 860	,8	,1	, &fEM_A3UC81RDU},	//(A3UC81RDU) Граница 1-го диапазона ИС вперёд (вверх)
	{ 861	,8	,1	, &fEM_A3UC82RDU},	//(A3UC82RDU) Граница 1-го диапазона ИС назад (вниз)
	{ 862	,8	,1	, &fEM_R0UN80RDU},	//(R0UN80RDU) Ограничение по мощности в режиме калибровка и имульс
	{ 863	,3	,1	, &iEM_A2UV01IDU},	//(A2UV01IDU) Скорость 1-го диапазона РБ вперёд (вверх)
	{ 864	,3	,1	, &iEM_A2UV02IDU},	//(A2UV02IDU) Скорость 2-го диапазона РБ вперёд (вверх)
	{ 865	,3	,1	, &iEM_A1UV01IDU},	//(A1UV01IDU) Скорость 1-го диапазона ББ вперёд (вверх)
	{ 866	,3	,1	, &iEM_A1UV02IDU},	//(A1UV02IDU) Скорость 2-го диапазона ББ вперёд (вверх)
	{ 867	,3	,1	, &iEM_A1UV03IDU},	//(A1UV03IDU) Скорость1-го диапазона ББ назад (вниз)
	{ 868	,3	,1	, &iEM_A3UV01IDU},	//(A3UV01IDU) Скорость ИС для 1-го диапазона вперёд (вверх)
	{ 869	,3	,1	, &iEM_A3UV02IDU},	//(A3UV02IDU) Скорость ИС для 1-го диапазона назад (вниз)
	{ 870	,1	,1	, &lEM_R0MD01LC1},	//(R0MD01LC1) Ручное управление ОРР
	{ 871	,8	,1	, &fEM_A3UC09RDU},	//(A3UC09RDU) Координата переднего аварийного выключателя ИС мм
	{ 872	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частота-скорость(мм/сек)
	{ 873	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частота-скорость(мм/сек) ББ
	{ 874	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частота-скорость (мм/сек) ИС
	{ 875	,8	,1	, &fEM_R0UL21RDU},	//(R0UL21RDU) Предельное время задержки  сброса от ВУ РБ
	{ 876	,8	,1	, &fEM_R0UN09RDU},	//(R0UN09RDU) Минимальный период при регулировании мощности
	{ 877	,8	,1	, &fEM_R0UN11RDU},	//(R0UN11RDU) Допустимое превышение заданной мощности  при регулировании
	{ 878	,8	,1	, &fEM_R0UN12RDU},	//(R0UN12RDU) Зона нечувствительности при регулировании мощности %
	{ 879	,8	,1	, &fEM_R0UN13RDU},	//(R0UN13RDU) Минимальное изменение координаты, мм
	{ 880	,8	,1	, &fEM_R0UN14RDU},	//(R0UN14RDU) Максимальная координата штока ИМ, мм
	{ 881	,8	,1	, &fEM_R0UN16RDU},	//(R0UN16RDU) Коэффициент a1 ф-ции определения положения ИМ с 0-й реактивностью
	{ 882	,8	,1	, &fEM_R0UN17RDU},	//(R0UN17RDU) Коэффициент a0 ф-ции определения положения ИМ с 0-й реактивностью
	{ 883	,8	,1	, &fEM_R0UN18RDU},	//(R0UN18RDU) Коэффициент t1 ф-ции температурной корректировки ИМ
	{ 884	,8	,1	, &fEM_R0UN19RDU},	//(R0UN19RDU) Коэффициент t0 ф-ции температурной корректировки ИМ
	{ 885	,8	,1	, &fEM_R0UN70LDU},	//(R0UN70LDU) 0 - Коэффициент реактивности функции опережения старта ИМ
	{ 886	,8	,1	, &fEM_R0UN71LDU},	//(R0UN71LDU) 1 - Коэффициент реактивности функции опережения старта ИМ
	{ 887	,8	,1	, &fEM_R0UN72LDU},	//(R0UN72LDU) 2 - Коэффициент реактивности функции опережения старта ИМ
	{ 888	,8	,1	, &fEM_R0UN73LDU},	//(R0UN73LDU) 3 - Коэффициент реактивности функции опережения старта ИМ
	{ 889	,8	,1	, &fEM_R0UN74LDU},	//(R0UN74LDU) 4 - Коэффициент реактивности функции опережения старта ИМ
	{ 890	,8	,1	, &fEM_R0UN75LDU},	//(R0UN75LDU) 5 - Коэффициент реактивности функции опережения старта ИМ
	{ 891	,8	,1	, &fEM_R0UN80LDU},	//(R0UN80LDU) 0 - Коэффициент  опережения старта ИМ
	{ 892	,8	,1	, &fEM_R0UN81LDU},	//(R0UN81LDU) 1 - Коэффициент  опережения старта ИМ
	{ 893	,8	,1	, &fEM_R0UN82LDU},	//(R0UN82LDU) 2 - Коэффициент  опережения старта ИМ
	{ 894	,8	,1	, &fEM_R0UN83LDU},	//(R0UN83LDU) 3 - Коэффициент  опережения старта ИМ
	{ 895	,8	,1	, &fEM_R0UN84LDU},	//(R0UN84LDU) 4 - Коэффициент  опережения старта ИМ
	{ 896	,8	,1	, &fEM_R0UN85LDU},	//(R0UN85LDU) 5 - Коэффициент  опережения старта ИМ
	{ 897	,8	,1	, &fEM_R0UT20RDU},	//(R0UT20RDU) Предельное время работы на мощности более 100 Вт, сек
	{ 898	,8	,1	, &fEM_R0UN25RDU},	//(R0UN25RDU) Коэффициент опережения для выхода с разгонной на 0-ю реактивность
	{ 899	,8	,1	, &fEM_R0UN15RDU},	//(R0UN15RDU) коэффициент рассогласования по координате для транспортной реактивности %
	{ 900	,8	,1	, &fEM_R0UN26RDU},	//(R0UN26RDU) Коэффициент mt0 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 901	,8	,1	, &fEM_R0UN27RDU},	//(R0UN27RDU) Коэффициент mt1 ф-ции прогноза темп. корр. положения ИМ от мощности
	{ 902	,8	,1	, &fEM_R0UN24RDU},	//(R0UN24RDU) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 903	,8	,1	, &fEM_R0UL25RDU},	//(R0UL25RDU) Предельное отклонение от времени задержки  сброса от ВУ ИС
	{ 904	,8	,1	, &fEM_R0UL01RSS},	//(R0UL01RSS) Шаг измерения периода (сек)
	{ 905	,8	,1	, &fEM_R0UL02RSS},	//(R0UL02RSS) Tф-постоянная времени, с
	{ 906	,8	,1	, &fEM_R0UN03RSS},	//(R0UN03RSS) нижняя граница интервала мощности для измерения периода (ватт)
	{ 907	,8	,1	, &fEM_R7UI76RDU},	//(R7UI76RDU) Время срабатывания сигнала II УР при имитации
	{ 908	,8	,1	, &fEM_R0UL00RDU},	//(R0UL00RDU) Время ожидания передачи  сигнала отключения сети
	{ 909	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 910	,8	,1	, &internal2_m244_tx},	//(internal2_m244_tx) tx - время накопленное сек
	{ 911	,18	,1	, &internal2_m244_y0},	//(internal2_m244_y0) y0
	{ 912	,8	,1	, &internal2_m272_tx},	//(internal2_m272_tx) tx - время накопленное сек
	{ 913	,18	,1	, &internal2_m272_y0},	//(internal2_m272_y0) y0
	{ 914	,8	,1	, &internal2_m182_tx},	//(internal2_m182_tx) tx - время накопленное сек
	{ 915	,18	,1	, &internal2_m182_y0},	//(internal2_m182_y0) y0
	{ 916	,8	,1	, &internal2_m176_tx},	//(internal2_m176_tx) tx - время накопленное сек
	{ 917	,18	,1	, &internal2_m176_y0},	//(internal2_m176_y0) y0
	{ 918	,8	,1	, &internal2_m172_tx},	//(internal2_m172_tx) tx - время накопленное сек
	{ 919	,18	,1	, &internal2_m172_y0},	//(internal2_m172_y0) y0
	{ 920	,8	,1	, &internal2_m165_tx},	//(internal2_m165_tx) tx - время накопленное сек
	{ 921	,18	,1	, &internal2_m165_y0},	//(internal2_m165_y0) y0
	{ 922	,8	,1	, &internal2_m158_tx},	//(internal2_m158_tx) tx - время накопленное сек
	{ 923	,18	,1	, &internal2_m158_y0},	//(internal2_m158_y0) y0
	{ 924	,8	,1	, &internal2_m155_tx},	//(internal2_m155_tx) tx - время накопленное сек
	{ 925	,18	,1	, &internal2_m155_y0},	//(internal2_m155_y0) y0
	{ 926	,8	,1	, &internal2_m149_tx},	//(internal2_m149_tx) tx - время накопленное сек
	{ 927	,18	,1	, &internal2_m149_y0},	//(internal2_m149_y0) y0
	{ 928	,8	,1	, &internal2_m144_tx},	//(internal2_m144_tx) tx - время накопленное сек
	{ 929	,18	,1	, &internal2_m144_y0},	//(internal2_m144_y0) y0
	{ 930	,8	,1	, &internal2_m141_tx},	//(internal2_m141_tx) tx - время накопленное сек
	{ 931	,18	,1	, &internal2_m141_y0},	//(internal2_m141_y0) y0
	{ 932	,8	,1	, &internal2_m134_tx},	//(internal2_m134_tx) tx - время накопленное сек
	{ 933	,18	,1	, &internal2_m134_y0},	//(internal2_m134_y0) y0
	{ 934	,8	,1	, &internal2_m132_tx},	//(internal2_m132_tx) tx - время накопленное сек
	{ 935	,18	,1	, &internal2_m132_y0},	//(internal2_m132_y0) y0
	{ 936	,8	,1	, &internal2_m127_tx},	//(internal2_m127_tx) tx - время накопленное сек
	{ 937	,18	,1	, &internal2_m127_y0},	//(internal2_m127_y0) y0
	{ 938	,8	,1	, &internal2_m195_y0},	//(internal2_m195_y0) y0
	{ 939	,8	,1	, &internal2_m193_y0},	//(internal2_m193_y0) y0
	{ 940	,1	,1	, &internal2_m227_y0},	//(internal2_m227_y0) state
	{ 941	,1	,1	, &internal2_m220_y0},	//(internal2_m220_y0) state
	{ 942	,1	,1	, &internal2_m209_y1},	//(internal2_m209_y1) y1 - внутренний параметр
	{ 943	,1	,1	, &internal2_m216_y1},	//(internal2_m216_y1) y1 - внутренний параметр
	{ 944	,1	,1	, &internal2_m198_y1},	//(internal2_m198_y1) y1 - внутренний параметр
	{ 945	,1	,1	, &internal2_m206_y1},	//(internal2_m206_y1) y1 - внутренний параметр
	{ 946	,5	,1	, &internal2_m16_Nk0},	//(internal2_m16_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 947	,1	,1	, &internal2_m16_SetFlag},	//(internal2_m16_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 948	,5	,1	, &internal2_m109_Nk0},	//(internal2_m109_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 949	,1	,1	, &internal2_m109_SetFlag},	//(internal2_m109_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 950	,5	,1	, &internal2_m112_Nk0},	//(internal2_m112_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 951	,1	,1	, &internal2_m112_SetFlag},	//(internal2_m112_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 952	,5	,1	, &internal2_m77_Nk0},	//(internal2_m77_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 953	,1	,1	, &internal2_m77_SetFlag},	//(internal2_m77_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 954	,5	,1	, &internal2_m83_Nk0},	//(internal2_m83_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 955	,1	,1	, &internal2_m83_SetFlag},	//(internal2_m83_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 956	,5	,1	, &internal2_m49_Nk0},	//(internal2_m49_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 957	,1	,1	, &internal2_m49_SetFlag},	//(internal2_m49_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 958	,5	,1	, &internal2_m53_Nk0},	//(internal2_m53_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 959	,1	,1	, &internal2_m53_SetFlag},	//(internal2_m53_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 960	,5	,1	, &internal2_m21_Nk0},	//(internal2_m21_Nk0) Nk0 - предыдущее показание энкодера, в тиках
	{ 961	,1	,1	, &internal2_m21_SetFlag},	//(internal2_m21_SetFlag) SetFlag - признак записи смещения в ЭСППЗУ
	{ 962	,8	,1	, &internal1_m2556_tx},	//(internal1_m2556_tx) tx - время накопленное сек
	{ 963	,18	,1	, &internal1_m2556_y0},	//(internal1_m2556_y0) y0
	{ 964	,8	,1	, &internal1_m2558_tx},	//(internal1_m2558_tx) tx - время накопленное сек
	{ 965	,18	,1	, &internal1_m2558_y0},	//(internal1_m2558_y0) y0
	{ 966	,8	,1	, &internal1_m2554_tx},	//(internal1_m2554_tx) tx - время накопленное сек
	{ 967	,18	,1	, &internal1_m2554_y0},	//(internal1_m2554_y0) y0
	{ 968	,8	,1	, &internal1_m2552_tx},	//(internal1_m2552_tx) tx - время накопленное сек
	{ 969	,18	,1	, &internal1_m2552_y0},	//(internal1_m2552_y0) y0
	{ 970	,8	,1	, &internal1_m221_tx},	//(internal1_m221_tx) tx - время накопленное сек
	{ 971	,18	,1	, &internal1_m221_y0},	//(internal1_m221_y0) y0
	{ 972	,8	,1	, &internal1_m220_tx},	//(internal1_m220_tx) tx - внутренний параметр
	{ 973	,1	,1	, &internal1_m2101_x0},	//(internal1_m2101_x0) - значение входного параметра на предыдущем шаге
	{ 974	,8	,1	, &internal1_m2101_tim},	//(internal1_m2101_tim) - время задержки выходного сигнала
	{ 975	,8	,1	, &internal1_m1677_tx},	//(internal1_m1677_tx) tx - время накопленное сек
	{ 976	,18	,1	, &internal1_m1677_y0},	//(internal1_m1677_y0) y0
	{ 977	,3	,1	, &internal1_m79_flst},	//(internal1_m79_flst)  флаг старта измерения
	{ 978	,3	,1	, &internal1_m79_chsr},	//(internal1_m79_chsr)  счетчик усреднения
	{ 979	,3	,1	, &internal1_m79_chizm},	//(internal1_m79_chizm)  счетчик уменьшения мощности
	{ 980	,8	,1	, &internal1_m79_sumtim},	//(internal1_m79_sumtim)  время измерения мощности
	{ 981	,8	,1	, &internal1_m79_W1},	//(internal1_m79_W1)  мощность на старте измерения
	{ 982	,8	,1	, &internal1_m79_W2},	//(internal1_m79_W2)  мощность в конце измерения
	{ 983	,8	,1	, &internal1_m79_Wmin},	//(internal1_m79_Wmin)  минимальное измерение в серии
	{ 984	,8	,1	, &internal1_m79_Wmax},	//(internal1_m79_Wmax)  максимальное измерение в серии
	{ 985	,8	,1	, &internal1_m79_Wlast},	//(internal1_m79_Wlast)  последнее растущее измерение
	{ 986	,8	,1	, &internal1_m79_y0},	//(internal1_m79_y0) y0 - внутренний параметр
	{ 987	,1	,1	, &internal1_m79_MyFirstEnterFlag},	//(internal1_m79_MyFirstEnterFlag)  FirstEnterFlag
	{ 988	,8	,1	, &internal1_m2066_tx},	//(internal1_m2066_tx) tx - внутренний параметр
	{ 989	,8	,1	, &internal1_m2065_tx},	//(internal1_m2065_tx) tx - внутренний параметр
	{ 990	,8	,1	, &internal1_m785_tx},	//(internal1_m785_tx) tx - внутренний параметр
	{ 991	,8	,1	, &internal1_m742_tx},	//(internal1_m742_tx) tx - внутренний параметр
	{ 992	,8	,1	, &internal1_m795_tx},	//(internal1_m795_tx) tx - внутренний параметр
	{ 993	,8	,1	, &internal1_m797_tx},	//(internal1_m797_tx) tx - внутренний параметр
	{ 994	,8	,1	, &internal1_m796_tx},	//(internal1_m796_tx) tx - внутренний параметр
	{ 995	,8	,1	, &internal1_m750_tx},	//(internal1_m750_tx) tx - внутренний параметр
	{ 996	,8	,1	, &internal1_m735_tx},	//(internal1_m735_tx) tx - внутренний параметр
	{ 997	,8	,1	, &internal1_m746_tx},	//(internal1_m746_tx) tx - внутренний параметр
	{ 998	,8	,1	, &internal1_m777_tx},	//(internal1_m777_tx) tx - внутренний параметр
	{ 999	,8	,1	, &internal1_m794_tx},	//(internal1_m794_tx) tx - внутренний параметр
	{ 1000	,8	,1	, &internal1_m767_tx},	//(internal1_m767_tx) tx - внутренний параметр
	{ 1001	,8	,1	, &internal1_m398_tx},	//(internal1_m398_tx) tx - внутренний параметр
	{ 1002	,8	,1	, &internal1_m397_tx},	//(internal1_m397_tx) tx - внутренний параметр
	{ 1003	,8	,1	, &internal1_m396_tx},	//(internal1_m396_tx) tx - внутренний параметр
	{ 1004	,8	,1	, &internal1_m395_tx},	//(internal1_m395_tx) tx - внутренний параметр
	{ 1005	,8	,1	, &internal1_m766_tx},	//(internal1_m766_tx) tx - внутренний параметр
	{ 1006	,8	,1	, &internal1_m761_tx},	//(internal1_m761_tx) tx - внутренний параметр
	{ 1007	,8	,1	, &internal1_m770_tx},	//(internal1_m770_tx) tx - внутренний параметр
	{ 1008	,8	,1	, &internal1_m775_tx},	//(internal1_m775_tx) tx - внутренний параметр
	{ 1009	,8	,1	, &internal1_m531_tx},	//(internal1_m531_tx) tx - внутренний параметр
	{ 1010	,8	,1	, &internal1_m530_tx},	//(internal1_m530_tx) tx - внутренний параметр
	{ 1011	,8	,1	, &internal1_m529_tx},	//(internal1_m529_tx) tx - внутренний параметр
	{ 1012	,8	,1	, &internal1_m525_tx},	//(internal1_m525_tx) tx - внутренний параметр
	{ 1013	,8	,1	, &internal1_m502_tx},	//(internal1_m502_tx) tx - внутренний параметр
	{ 1014	,8	,1	, &internal1_m501_tx},	//(internal1_m501_tx) tx - внутренний параметр
	{ 1015	,8	,1	, &internal1_m500_tx},	//(internal1_m500_tx) tx - внутренний параметр
	{ 1016	,8	,1	, &internal1_m503_tx},	//(internal1_m503_tx) tx - внутренний параметр
	{ 1017	,8	,1	, &internal1_m2472_tx},	//(internal1_m2472_tx) tx - внутренний параметр
	{ 1018	,8	,1	, &internal1_m2182_tx},	//(internal1_m2182_tx) tx - внутренний параметр
	{ 1019	,8	,1	, &internal1_m2471_tx},	//(internal1_m2471_tx) tx - внутренний параметр
	{ 1020	,8	,1	, &internal1_m2470_tx},	//(internal1_m2470_tx) tx - внутренний параметр
	{ 1021	,8	,1	, &internal1_m2467_tx},	//(internal1_m2467_tx) tx - внутренний параметр
	{ 1022	,8	,1	, &internal1_m108_tx},	//(internal1_m108_tx) tx - внутренний параметр
	{ 1023	,8	,1	, &internal1_m1148_tx},	//(internal1_m1148_tx) tx - внутренний параметр
	{ 1024	,8	,1	, &internal1_m2330_tx},	//(internal1_m2330_tx) tx - внутренний параметр
	{ 1025	,8	,1	, &internal1_m2329_tx},	//(internal1_m2329_tx) tx - внутренний параметр
	{ 1026	,8	,1	, &internal1_m2328_tx},	//(internal1_m2328_tx) tx - внутренний параметр
	{ 1027	,8	,1	, &internal1_m1260_tx},	//(internal1_m1260_tx) tx - внутренний параметр
	{ 1028	,8	,1	, &internal1_m1259_tx},	//(internal1_m1259_tx) tx - внутренний параметр
	{ 1029	,8	,1	, &internal1_m1255_tx},	//(internal1_m1255_tx) tx - внутренний параметр
	{ 1030	,8	,1	, &internal1_m1248_tx},	//(internal1_m1248_tx) tx - внутренний параметр
	{ 1031	,8	,1	, &internal1_m1246_tx},	//(internal1_m1246_tx) tx - внутренний параметр
	{ 1032	,8	,1	, &internal1_m1244_tx},	//(internal1_m1244_tx) tx - внутренний параметр
	{ 1033	,8	,1	, &internal1_m1242_tx},	//(internal1_m1242_tx) tx - внутренний параметр
	{ 1034	,8	,1	, &internal1_m1285_tx},	//(internal1_m1285_tx) tx - внутренний параметр
	{ 1035	,8	,1	, &internal1_m1292_tx},	//(internal1_m1292_tx) tx - внутренний параметр
	{ 1036	,8	,1	, &internal1_m1297_tx},	//(internal1_m1297_tx) tx - внутренний параметр
	{ 1037	,8	,1	, &internal1_m1303_tx},	//(internal1_m1303_tx) tx - внутренний параметр
	{ 1038	,8	,1	, &internal1_m1263_tx},	//(internal1_m1263_tx) tx - внутренний параметр
	{ 1039	,8	,1	, &internal1_m1284_tx},	//(internal1_m1284_tx) tx - внутренний параметр
	{ 1040	,8	,1	, &internal1_m1298_tx},	//(internal1_m1298_tx) tx - внутренний параметр
	{ 1041	,8	,1	, &internal1_m480_tx},	//(internal1_m480_tx) tx - внутренний параметр
	{ 1042	,8	,1	, &internal1_m474_tx},	//(internal1_m474_tx) tx - внутренний параметр
	{ 1043	,8	,1	, &internal1_m476_tx},	//(internal1_m476_tx) tx - внутренний параметр
	{ 1044	,8	,1	, &internal1_m478_tx},	//(internal1_m478_tx) tx - внутренний параметр
	{ 1045	,8	,1	, &internal1_m485_tx},	//(internal1_m485_tx) tx - внутренний параметр
	{ 1046	,8	,1	, &internal1_m439_tx},	//(internal1_m439_tx) tx - внутренний параметр
	{ 1047	,8	,1	, &internal1_m437_tx},	//(internal1_m437_tx) tx - внутренний параметр
	{ 1048	,8	,1	, &internal1_m438_tx},	//(internal1_m438_tx) tx - внутренний параметр
	{ 1049	,8	,1	, &internal1_m431_tx},	//(internal1_m431_tx) tx - внутренний параметр
	{ 1050	,8	,1	, &internal1_m893_tx},	//(internal1_m893_tx) tx - внутренний параметр
	{ 1051	,8	,1	, &internal1_m892_tx},	//(internal1_m892_tx) tx - внутренний параметр
	{ 1052	,8	,1	, &internal1_m891_tx},	//(internal1_m891_tx) tx - внутренний параметр
	{ 1053	,8	,1	, &internal1_m887_tx},	//(internal1_m887_tx) tx - внутренний параметр
	{ 1054	,8	,1	, &internal1_m1349_tx},	//(internal1_m1349_tx) tx - внутренний параметр
	{ 1055	,8	,1	, &internal1_m1348_tx},	//(internal1_m1348_tx) tx - внутренний параметр
	{ 1056	,8	,1	, &internal1_m1347_tx},	//(internal1_m1347_tx) tx - внутренний параметр
	{ 1057	,8	,1	, &internal1_m1560_tx},	//(internal1_m1560_tx) tx - внутренний параметр
	{ 1058	,8	,1	, &internal1_m1573_tx},	//(internal1_m1573_tx) tx - внутренний параметр
	{ 1059	,8	,1	, &internal1_m1572_tx},	//(internal1_m1572_tx) tx - внутренний параметр
	{ 1060	,8	,1	, &internal1_m1571_tx},	//(internal1_m1571_tx) tx - внутренний параметр
	{ 1061	,8	,1	, &internal1_m1562_tx},	//(internal1_m1562_tx) tx - внутренний параметр
	{ 1062	,8	,1	, &internal1_m2300_tx},	//(internal1_m2300_tx) tx - внутренний параметр
	{ 1063	,8	,1	, &internal1_m2283_tx},	//(internal1_m2283_tx) tx - внутренний параметр
	{ 1064	,8	,1	, &internal1_m2260_tx},	//(internal1_m2260_tx) tx - внутренний параметр
	{ 1065	,8	,1	, &internal1_m1570_tx},	//(internal1_m1570_tx) tx - внутренний параметр
	{ 1066	,8	,1	, &internal1_m1550_tx},	//(internal1_m1550_tx) tx - внутренний параметр
	{ 1067	,8	,1	, &internal1_m1549_tx},	//(internal1_m1549_tx) tx - внутренний параметр
	{ 1068	,8	,1	, &internal1_m1547_tx},	//(internal1_m1547_tx) tx - внутренний параметр
	{ 1069	,8	,1	, &internal1_m1569_tx},	//(internal1_m1569_tx) tx - внутренний параметр
	{ 1070	,8	,1	, &internal1_m1535_tx},	//(internal1_m1535_tx) tx - внутренний параметр
	{ 1071	,8	,1	, &internal1_m1537_tx},	//(internal1_m1537_tx) tx - внутренний параметр
	{ 1072	,8	,1	, &internal1_m1534_tx},	//(internal1_m1534_tx) tx - внутренний параметр
	{ 1073	,8	,1	, &internal1_m1507_tx},	//(internal1_m1507_tx) tx - внутренний параметр
	{ 1074	,8	,1	, &internal1_m1506_tx},	//(internal1_m1506_tx) tx - внутренний параметр
	{ 1075	,8	,1	, &internal1_m1516_tx},	//(internal1_m1516_tx) tx - внутренний параметр
	{ 1076	,8	,1	, &internal1_m1519_tx},	//(internal1_m1519_tx) tx - внутренний параметр
	{ 1077	,8	,1	, &internal1_m986_tx},	//(internal1_m986_tx) tx - внутренний параметр
	{ 1078	,8	,1	, &internal1_m989_tx},	//(internal1_m989_tx) tx - внутренний параметр
	{ 1079	,8	,1	, &internal1_m2251_tx},	//(internal1_m2251_tx) tx - внутренний параметр
	{ 1080	,8	,1	, &internal1_m979_tx},	//(internal1_m979_tx) tx - внутренний параметр
	{ 1081	,8	,1	, &internal1_m977_tx},	//(internal1_m977_tx) tx - внутренний параметр
	{ 1082	,8	,1	, &internal1_m985_tx},	//(internal1_m985_tx) tx - внутренний параметр
	{ 1083	,8	,1	, &internal1_m969_tx},	//(internal1_m969_tx) tx - внутренний параметр
	{ 1084	,8	,1	, &internal1_m967_tx},	//(internal1_m967_tx) tx - внутренний параметр
	{ 1085	,8	,1	, &internal1_m963_tx},	//(internal1_m963_tx) tx - внутренний параметр
	{ 1086	,8	,1	, &internal1_m984_tx},	//(internal1_m984_tx) tx - внутренний параметр
	{ 1087	,8	,1	, &internal1_m949_tx},	//(internal1_m949_tx) tx - внутренний параметр
	{ 1088	,8	,1	, &internal1_m950_tx},	//(internal1_m950_tx) tx - внутренний параметр
	{ 1089	,8	,1	, &internal1_m952_tx},	//(internal1_m952_tx) tx - внутренний параметр
	{ 1090	,8	,1	, &internal1_m637_tx},	//(internal1_m637_tx) tx - внутренний параметр
	{ 1091	,8	,1	, &internal1_m640_tx},	//(internal1_m640_tx) tx - внутренний параметр
	{ 1092	,8	,1	, &internal1_m639_tx},	//(internal1_m639_tx) tx - внутренний параметр
	{ 1093	,8	,1	, &internal1_m628_tx},	//(internal1_m628_tx) tx - внутренний параметр
	{ 1094	,8	,1	, &internal1_m626_tx},	//(internal1_m626_tx) tx - внутренний параметр
	{ 1095	,8	,1	, &internal1_m622_tx},	//(internal1_m622_tx) tx - внутренний параметр
	{ 1096	,8	,1	, &internal1_m635_tx},	//(internal1_m635_tx) tx - внутренний параметр
	{ 1097	,8	,1	, &internal1_m612_tx},	//(internal1_m612_tx) tx - внутренний параметр
	{ 1098	,8	,1	, &internal1_m611_tx},	//(internal1_m611_tx) tx - внутренний параметр
	{ 1099	,8	,1	, &internal1_m607_tx},	//(internal1_m607_tx) tx - внутренний параметр
	{ 1100	,8	,1	, &internal1_m638_tx},	//(internal1_m638_tx) tx - внутренний параметр
	{ 1101	,8	,1	, &internal1_m595_tx},	//(internal1_m595_tx) tx - внутренний параметр
	{ 1102	,8	,1	, &internal1_m594_tx},	//(internal1_m594_tx) tx - внутренний параметр
	{ 1103	,8	,1	, &internal1_m597_tx},	//(internal1_m597_tx) tx - внутренний параметр
	{ 1104	,8	,1	, &internal1_m574_tx},	//(internal1_m574_tx) tx - внутренний параметр
	{ 1105	,8	,1	, &internal1_m575_tx},	//(internal1_m575_tx) tx - внутренний параметр
	{ 1106	,8	,1	, &internal1_m576_tx},	//(internal1_m576_tx) tx - внутренний параметр
	{ 1107	,8	,1	, &internal1_m581_tx},	//(internal1_m581_tx) tx - внутренний параметр
	{ 1108	,8	,1	, &internal1_m2313_tx},	//(internal1_m2313_tx) tx - внутренний параметр
	{ 1109	,8	,1	, &internal1_m2314_tx},	//(internal1_m2314_tx) tx - внутренний параметр
	{ 1110	,8	,1	, &internal1_m2315_tx},	//(internal1_m2315_tx) tx - внутренний параметр
	{ 1111	,8	,1	, &internal1_m1792_tx},	//(internal1_m1792_tx) tx - внутренний параметр
	{ 1112	,8	,1	, &internal1_m1791_tx},	//(internal1_m1791_tx) tx - внутренний параметр
	{ 1113	,8	,1	, &internal1_m1786_tx},	//(internal1_m1786_tx) tx - внутренний параметр
	{ 1114	,8	,1	, &internal1_m1777_tx},	//(internal1_m1777_tx) tx - внутренний параметр
	{ 1115	,8	,1	, &internal1_m1775_tx},	//(internal1_m1775_tx) tx - внутренний параметр
	{ 1116	,8	,1	, &internal1_m1773_tx},	//(internal1_m1773_tx) tx - внутренний параметр
	{ 1117	,8	,1	, &internal1_m1772_tx},	//(internal1_m1772_tx) tx - внутренний параметр
	{ 1118	,8	,1	, &internal1_m1813_tx},	//(internal1_m1813_tx) tx - внутренний параметр
	{ 1119	,8	,1	, &internal1_m1821_tx},	//(internal1_m1821_tx) tx - внутренний параметр
	{ 1120	,8	,1	, &internal1_m1828_tx},	//(internal1_m1828_tx) tx - внутренний параметр
	{ 1121	,8	,1	, &internal1_m1829_tx},	//(internal1_m1829_tx) tx - внутренний параметр
	{ 1122	,8	,1	, &internal1_m1819_tx},	//(internal1_m1819_tx) tx - внутренний параметр
	{ 1123	,8	,1	, &internal1_m1794_tx},	//(internal1_m1794_tx) tx - внутренний параметр
	{ 1124	,8	,1	, &internal1_m1808_tx},	//(internal1_m1808_tx) tx - внутренний параметр
	{ 1125	,8	,1	, &internal1_m457_tx},	//(internal1_m457_tx) tx - внутренний параметр
	{ 1126	,8	,1	, &internal1_m448_tx},	//(internal1_m448_tx) tx - внутренний параметр
	{ 1127	,8	,1	, &internal1_m449_tx},	//(internal1_m449_tx) tx - внутренний параметр
	{ 1128	,8	,1	, &internal1_m451_tx},	//(internal1_m451_tx) tx - внутренний параметр
	{ 1129	,8	,1	, &internal1_m465_tx},	//(internal1_m465_tx) tx - внутренний параметр
	{ 1130	,8	,1	, &internal1_m415_tx},	//(internal1_m415_tx) tx - внутренний параметр
	{ 1131	,8	,1	, &internal1_m412_tx},	//(internal1_m412_tx) tx - внутренний параметр
	{ 1132	,8	,1	, &internal1_m411_tx},	//(internal1_m411_tx) tx - внутренний параметр
	{ 1133	,8	,1	, &internal1_m410_tx},	//(internal1_m410_tx) tx - внутренний параметр
	{ 1134	,8	,1	, &internal1_m870_tx},	//(internal1_m870_tx) tx - внутренний параметр
	{ 1135	,8	,1	, &internal1_m866_tx},	//(internal1_m866_tx) tx - внутренний параметр
	{ 1136	,8	,1	, &internal1_m865_tx},	//(internal1_m865_tx) tx - внутренний параметр
	{ 1137	,8	,1	, &internal1_m864_tx},	//(internal1_m864_tx) tx - внутренний параметр
	{ 1138	,8	,1	, &internal1_m1330_tx},	//(internal1_m1330_tx) tx - внутренний параметр
	{ 1139	,8	,1	, &internal1_m1327_tx},	//(internal1_m1327_tx) tx - внутренний параметр
	{ 1140	,8	,1	, &internal1_m1326_tx},	//(internal1_m1326_tx) tx - внутренний параметр
	{ 1141	,8	,1	, &internal1_m1087_tx},	//(internal1_m1087_tx) tx - внутренний параметр
	{ 1142	,8	,1	, &internal1_m2272_tx},	//(internal1_m2272_tx) tx - внутренний параметр
	{ 1143	,8	,1	, &internal1_m1098_tx},	//(internal1_m1098_tx) tx - внутренний параметр
	{ 1144	,8	,1	, &internal1_m1100_tx},	//(internal1_m1100_tx) tx - внутренний параметр
	{ 1145	,8	,1	, &internal1_m1099_tx},	//(internal1_m1099_tx) tx - внутренний параметр
	{ 1146	,8	,1	, &internal1_m2266_tx},	//(internal1_m2266_tx) tx - внутренний параметр
	{ 1147	,8	,1	, &internal1_m1089_tx},	//(internal1_m1089_tx) tx - внутренний параметр
	{ 1148	,8	,1	, &internal1_m2271_tx},	//(internal1_m2271_tx) tx - внутренний параметр
	{ 1149	,8	,1	, &internal1_m1097_tx},	//(internal1_m1097_tx) tx - внутренний параметр
	{ 1150	,8	,1	, &internal1_m1079_tx},	//(internal1_m1079_tx) tx - внутренний параметр
	{ 1151	,8	,1	, &internal1_m1078_tx},	//(internal1_m1078_tx) tx - внутренний параметр
	{ 1152	,8	,1	, &internal1_m1074_tx},	//(internal1_m1074_tx) tx - внутренний параметр
	{ 1153	,8	,1	, &internal1_m1096_tx},	//(internal1_m1096_tx) tx - внутренний параметр
	{ 1154	,8	,1	, &internal1_m1064_tx},	//(internal1_m1064_tx) tx - внутренний параметр
	{ 1155	,8	,1	, &internal1_m1062_tx},	//(internal1_m1062_tx) tx - внутренний параметр
	{ 1156	,8	,1	, &internal1_m1061_tx},	//(internal1_m1061_tx) tx - внутренний параметр
	{ 1157	,8	,1	, &internal1_m1040_tx},	//(internal1_m1040_tx) tx - внутренний параметр
	{ 1158	,8	,1	, &internal1_m1039_tx},	//(internal1_m1039_tx) tx - внутренний параметр
	{ 1159	,8	,1	, &internal1_m1029_tx},	//(internal1_m1029_tx) tx - внутренний параметр
	{ 1160	,8	,1	, &internal1_m1046_tx},	//(internal1_m1046_tx) tx - внутренний параметр
	{ 1161	,8	,1	, &internal1_m1465_tx},	//(internal1_m1465_tx) tx - внутренний параметр
	{ 1162	,8	,1	, &internal1_m1464_tx},	//(internal1_m1464_tx) tx - внутренний параметр
	{ 1163	,8	,1	, &internal1_m2218_tx},	//(internal1_m2218_tx) tx - внутренний параметр
	{ 1164	,8	,1	, &internal1_m1455_tx},	//(internal1_m1455_tx) tx - внутренний параметр
	{ 1165	,8	,1	, &internal1_m1456_tx},	//(internal1_m1456_tx) tx - внутренний параметр
	{ 1166	,8	,1	, &internal1_m1463_tx},	//(internal1_m1463_tx) tx - внутренний параметр
	{ 1167	,8	,1	, &internal1_m1446_tx},	//(internal1_m1446_tx) tx - внутренний параметр
	{ 1168	,8	,1	, &internal1_m1445_tx},	//(internal1_m1445_tx) tx - внутренний параметр
	{ 1169	,8	,1	, &internal1_m1441_tx},	//(internal1_m1441_tx) tx - внутренний параметр
	{ 1170	,8	,1	, &internal1_m1462_tx},	//(internal1_m1462_tx) tx - внутренний параметр
	{ 1171	,8	,1	, &internal1_m1428_tx},	//(internal1_m1428_tx) tx - внутренний параметр
	{ 1172	,8	,1	, &internal1_m1426_tx},	//(internal1_m1426_tx) tx - внутренний параметр
	{ 1173	,8	,1	, &internal1_m1435_tx},	//(internal1_m1435_tx) tx - внутренний параметр
	{ 1174	,8	,1	, &internal1_m255_tx},	//(internal1_m255_tx) tx - внутренний параметр
	{ 1175	,8	,1	, &internal1_m270_tx},	//(internal1_m270_tx) tx - внутренний параметр
	{ 1176	,8	,1	, &internal1_m278_tx},	//(internal1_m278_tx) tx - внутренний параметр
	{ 1177	,8	,1	, &internal1_m277_tx},	//(internal1_m277_tx) tx - внутренний параметр
	{ 1178	,8	,1	, &internal1_m261_tx},	//(internal1_m261_tx) tx - внутренний параметр
	{ 1179	,8	,1	, &internal1_m258_tx},	//(internal1_m258_tx) tx - внутренний параметр
	{ 1180	,8	,1	, &internal1_m274_tx},	//(internal1_m274_tx) tx - внутренний параметр
	{ 1181	,8	,1	, &internal1_m246_tx},	//(internal1_m246_tx) tx - внутренний параметр
	{ 1182	,8	,1	, &internal1_m245_tx},	//(internal1_m245_tx) tx - внутренний параметр
	{ 1183	,8	,1	, &internal1_m241_tx},	//(internal1_m241_tx) tx - внутренний параметр
	{ 1184	,8	,1	, &internal1_m273_tx},	//(internal1_m273_tx) tx - внутренний параметр
	{ 1185	,8	,1	, &internal1_m230_tx},	//(internal1_m230_tx) tx - внутренний параметр
	{ 1186	,8	,1	, &internal1_m232_tx},	//(internal1_m232_tx) tx - внутренний параметр
	{ 1187	,8	,1	, &internal1_m228_tx},	//(internal1_m228_tx) tx - внутренний параметр
	{ 1188	,8	,1	, &internal1_m204_tx},	//(internal1_m204_tx) tx - внутренний параметр
	{ 1189	,8	,1	, &internal1_m203_tx},	//(internal1_m203_tx) tx - внутренний параметр
	{ 1190	,8	,1	, &internal1_m202_tx},	//(internal1_m202_tx) tx - внутренний параметр
	{ 1191	,8	,1	, &internal1_m210_tx},	//(internal1_m210_tx) tx - внутренний параметр
	{ 1192	,8	,1	, &internal1_m1408_tx},	//(internal1_m1408_tx) tx - внутренний параметр
	{ 1193	,8	,1	, &internal1_m1390_tx},	//(internal1_m1390_tx) tx - внутренний параметр
	{ 1194	,8	,1	, &internal1_m1393_tx},	//(internal1_m1393_tx) tx - внутренний параметр
	{ 1195	,8	,1	, &internal1_m1412_tx},	//(internal1_m1412_tx) tx - внутренний параметр
	{ 1196	,8	,1	, &internal1_m929_tx},	//(internal1_m929_tx) tx - внутренний параметр
	{ 1197	,8	,1	, &internal1_m934_tx},	//(internal1_m934_tx) tx - внутренний параметр
	{ 1198	,8	,1	, &internal1_m924_tx},	//(internal1_m924_tx) tx - внутренний параметр
	{ 1199	,8	,1	, &internal1_m925_tx},	//(internal1_m925_tx) tx - внутренний параметр
	{ 1200	,1	,1	, &internal1_m1913_q0},	//(internal1_m1913_q0) q0 - внутренний параметр
	{ 1201	,1	,1	, &internal1_m2355_q0},	//(internal1_m2355_q0) q0 - внутренний параметр
	{ 1202	,1	,1	, &internal1_m2339_q0},	//(internal1_m2339_q0) q0 - внутренний параметр
	{ 1203	,1	,1	, &internal1_m2386_q0},	//(internal1_m2386_q0) q0 - внутренний параметр
	{ 1204	,1	,1	, &internal1_m2370_q0},	//(internal1_m2370_q0) q0 - внутренний параметр
	{ 1205	,1	,1	, &internal1_m2361_q0},	//(internal1_m2361_q0) q0 - внутренний параметр
	{ 1206	,1	,1	, &internal1_m2342_q0},	//(internal1_m2342_q0) q0 - внутренний параметр
	{ 1207	,1	,1	, &internal1_m2359_q0},	//(internal1_m2359_q0) q0 - внутренний параметр
	{ 1208	,1	,1	, &internal1_m2340_q0},	//(internal1_m2340_q0) q0 - внутренний параметр
	{ 1209	,1	,1	, &internal1_m2338_q0},	//(internal1_m2338_q0) q0 - внутренний параметр
	{ 1210	,1	,1	, &internal1_m2337_q0},	//(internal1_m2337_q0) q0 - внутренний параметр
	{ 1211	,1	,1	, &internal1_m2351_q0},	//(internal1_m2351_q0) q0 - внутренний параметр
	{ 1212	,1	,1	, &internal1_m2349_q0},	//(internal1_m2349_q0) q0 - внутренний параметр
	{ 1213	,1	,1	, &internal1_m2357_q0},	//(internal1_m2357_q0) q0 - внутренний параметр
	{ 1214	,1	,1	, &internal1_m2353_q0},	//(internal1_m2353_q0) q0 - внутренний параметр
	{ 1215	,1	,1	, &internal1_m2392_q0},	//(internal1_m2392_q0) q0 - внутренний параметр
	{ 1216	,1	,1	, &internal1_m2373_q0},	//(internal1_m2373_q0) q0 - внутренний параметр
	{ 1217	,1	,1	, &internal1_m2390_q0},	//(internal1_m2390_q0) q0 - внутренний параметр
	{ 1218	,1	,1	, &internal1_m2372_q0},	//(internal1_m2372_q0) q0 - внутренний параметр
	{ 1219	,1	,1	, &internal1_m2369_q0},	//(internal1_m2369_q0) q0 - внутренний параметр
	{ 1220	,1	,1	, &internal1_m2368_q0},	//(internal1_m2368_q0) q0 - внутренний параметр
	{ 1221	,1	,1	, &internal1_m2382_q0},	//(internal1_m2382_q0) q0 - внутренний параметр
	{ 1222	,1	,1	, &internal1_m2380_q0},	//(internal1_m2380_q0) q0 - внутренний параметр
	{ 1223	,8	,1	, &internal1_m2243_tx},	//(internal1_m2243_tx) tx - внутренний параметр
	{ 1224	,8	,1	, &internal1_m2222_tx},	//(internal1_m2222_tx) tx - внутренний параметр
	{ 1225	,1	,1	, &internal1_m1937_Pv0},	//(internal1_m1937_Pv0)  - Пер. выключатель механизма
	{ 1226	,1	,1	, &internal1_m1937_Zv0},	//(internal1_m1937_Zv0)  - Зад. выключатель механизма
	{ 1227	,1	,1	, &internal1_m1937_MyFirstEnterFlag},	//(internal1_m1937_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1228	,1	,1	, &internal1_m1934_Pv0},	//(internal1_m1934_Pv0)  - Пер. выключатель механизма
	{ 1229	,1	,1	, &internal1_m1934_Zv0},	//(internal1_m1934_Zv0)  - Зад. выключатель механизма
	{ 1230	,1	,1	, &internal1_m1934_MyFirstEnterFlag},	//(internal1_m1934_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1231	,8	,1	, &internal1_m2410_tx},	//(internal1_m2410_tx) tx - время накопленное сек
	{ 1232	,18	,1	, &internal1_m2410_y0},	//(internal1_m2410_y0) y0
	{ 1233	,8	,1	, &internal1_m2414_tx},	//(internal1_m2414_tx) tx - время накопленное сек
	{ 1234	,18	,1	, &internal1_m2414_y0},	//(internal1_m2414_y0) y0
	{ 1235	,8	,1	, &internal1_m2413_tx},	//(internal1_m2413_tx) tx - время накопленное сек
	{ 1236	,18	,1	, &internal1_m2413_y0},	//(internal1_m2413_y0) y0
	{ 1237	,8	,1	, &internal1_m2450_tx},	//(internal1_m2450_tx) tx - внутренний параметр
	{ 1238	,8	,1	, &internal1_m2448_tx},	//(internal1_m2448_tx) tx - время накопленное сек
	{ 1239	,18	,1	, &internal1_m2448_y0},	//(internal1_m2448_y0) y0
	{ 1240	,1	,1	, &internal1_m2453_q0},	//(internal1_m2453_q0) q0 - внутренний параметр
	{ 1241	,1	,1	, &internal1_m2420_q0},	//(internal1_m2420_q0) q0 - внутренний параметр
	{ 1242	,8	,1	, &internal1_m2428_tx},	//(internal1_m2428_tx) tx - внутренний параметр
	{ 1243	,1	,1	, &internal1_m2426_q0},	//(internal1_m2426_q0) q0 - внутренний параметр
	{ 1244	,8	,1	, &internal1_m2408_fVf0},	//(internal1_m2408_fVf0)  - скорость изменения мощности 
	{ 1245	,8	,1	, &internal1_m2408_fRsg},	//(internal1_m2408_fRsg)  - рассогласование между текущей и заданной мощностью 
	{ 1246	,8	,1	, &internal1_m2408_fRct},	//(internal1_m2408_fRct)  - стартовая реактивность регулятора 
	{ 1247	,8	,1	, &internal1_m2408_fVfMin},	//(internal1_m2408_fVfMin)  - минимальная скорость 
	{ 1248	,8	,1	, &internal1_m2408_fStw0},	//(internal1_m2408_fStw0)  - значение стартовой мощности включения ИМ 
	{ 1249	,8	,1	, &internal1_m2408_fMaxDk},	//(internal1_m2408_fMaxDk)  - изменение координаты при смене задания 
	{ 1250	,8	,1	, &internal1_m2408_fkizm},	//(internal1_m2408_fkizm)  - стартовая координата положения ИМ 0-й реактивности 
	{ 1251	,8	,1	, &internal1_m2408_fwt0},	//(internal1_m2408_fwt0)  - мощность на предыдущем шаге 
	{ 1252	,8	,1	, &internal1_m2408_fwz0},	//(internal1_m2408_fwz0)  - заданная мощность на предыдущем шаге 
	{ 1253	,8	,1	, &internal1_m2408_ftf0},	//(internal1_m2408_ftf0)  - время от фиксации предыдущей мощности 
	{ 1254	,8	,1	, &internal1_m2408_fTk0},	//(internal1_m2408_fTk0)  - последняя температура 
	{ 1255	,3	,1	, &internal1_m2408_FlPar},	//(internal1_m2408_FlPar) - стартовый этап регулирования
	{ 1256	,3	,1	, &internal1_m2408_FlIzm},	//(internal1_m2408_FlIzm) - флаг изменения направления изменения мощности
	{ 1257	,3	,1	, &internal1_m2408_FlCmp},	//(internal1_m2408_FlCmp) - текущее направление изменения мощности
	{ 1258	,3	,1	, &internal1_m2408_StabCoun},	//(internal1_m2408_StabCoun) - счётчик стабильности
	{ 1259	,3	,1	, &internal1_m2408_ZerCoun},	//(internal1_m2408_ZerCoun) - счётчик полной остановки
	{ 1260	,3	,1	, &internal1_m2408_SrCoun},	//(internal1_m2408_SrCoun)  - счётчик усреднения
	{ 1261	,3	,1	, &internal1_m2408_LastStage},	//(internal1_m2408_LastStage)  - последний этап
	{ 1262	,1	,1	, &internal1_m2408_fef},	//(internal1_m2408_fef)  - первый вход
	{ 1263	,8	,1	, &internal1_m2237_tx},	//(internal1_m2237_tx) tx - время накопленное сек
	{ 1264	,18	,1	, &internal1_m2237_y0},	//(internal1_m2237_y0) y0
	{ 1265	,8	,1	, &internal1_m2229_tx},	//(internal1_m2229_tx) tx - время накопленное сек
	{ 1266	,18	,1	, &internal1_m2229_y0},	//(internal1_m2229_y0) y0
	{ 1267	,1	,1	, &internal1_m1923_q0},	//(internal1_m1923_q0) q0 - внутренний параметр
	{ 1268	,1	,1	, &internal1_m1928_q0},	//(internal1_m1928_q0) q0 - внутренний параметр
	{ 1269	,1	,1	, &internal1_m1920_q0},	//(internal1_m1920_q0) q0 - внутренний параметр
	{ 1270	,1	,1	, &internal1_m1962_q0},	//(internal1_m1962_q0) q0 - внутренний параметр
	{ 1271	,8	,1	, &internal1_m834_tx},	//(internal1_m834_tx) tx - время накопленное сек
	{ 1272	,18	,1	, &internal1_m834_y0},	//(internal1_m834_y0) y0
	{ 1273	,8	,1	, &internal1_m2233_tx},	//(internal1_m2233_tx) tx - внутренний параметр
	{ 1274	,1	,1	, &internal1_m2236_q0},	//(internal1_m2236_q0) q0 - внутренний параметр
	{ 1275	,1	,1	, &internal1_m2228_q0},	//(internal1_m2228_q0) q0 - внутренний параметр
	{ 1276	,8	,1	, &internal1_m2197_tx},	//(internal1_m2197_tx) tx - внутренний параметр
	{ 1277	,8	,1	, &internal1_m2208_tx},	//(internal1_m2208_tx) tx - внутренний параметр
	{ 1278	,8	,1	, &internal1_m2194_tx},	//(internal1_m2194_tx) tx - внутренний параметр
	{ 1279	,1	,1	, &internal1_m2200_q0},	//(internal1_m2200_q0) q0 - внутренний параметр
	{ 1280	,1	,1	, &internal1_m2212_q0},	//(internal1_m2212_q0) q0 - внутренний параметр
	{ 1281	,8	,1	, &internal1_m2169_tx},	//(internal1_m2169_tx) tx - внутренний параметр
	{ 1282	,8	,1	, &internal1_m52_tx},	//(internal1_m52_tx) tx - внутренний параметр
	{ 1283	,8	,1	, &internal1_m368_tx},	//(internal1_m368_tx) tx - внутренний параметр
	{ 1284	,8	,1	, &internal1_m322_tx},	//(internal1_m322_tx) tx - внутренний параметр
	{ 1285	,8	,1	, &internal1_m835_tx},	//(internal1_m835_tx) tx - внутренний параметр
	{ 1286	,8	,1	, &internal1_m1627_tx},	//(internal1_m1627_tx) tx - внутренний параметр
	{ 1287	,8	,1	, &internal1_m120_tx},	//(internal1_m120_tx) tx - внутренний параметр
	{ 1288	,8	,1	, &internal1_m122_tx},	//(internal1_m122_tx) tx - внутренний параметр
	{ 1289	,8	,1	, &internal1_m127_tx},	//(internal1_m127_tx) tx - внутренний параметр
	{ 1290	,8	,1	, &internal1_m21_tx},	//(internal1_m21_tx) tx - внутренний параметр
	{ 1291	,8	,1	, &internal1_m13_tx},	//(internal1_m13_tx) tx - внутренний параметр
	{ 1292	,8	,1	, &internal1_m2179_tx},	//(internal1_m2179_tx) tx - внутренний параметр
	{ 1293	,8	,1	, &internal1_m2166_tx},	//(internal1_m2166_tx) tx - внутренний параметр
	{ 1294	,8	,1	, &internal1_m2284_tx},	//(internal1_m2284_tx) tx - внутренний параметр
	{ 1295	,8	,1	, &internal1_m2286_tx},	//(internal1_m2286_tx) tx - внутренний параметр
	{ 1296	,8	,1	, &internal1_m82_tx},	//(internal1_m82_tx) tx - внутренний параметр
	{ 1297	,8	,1	, &internal1_m339_tx},	//(internal1_m339_tx) tx - время накопленное сек
	{ 1298	,18	,1	, &internal1_m339_y0},	//(internal1_m339_y0) y0
	{ 1299	,8	,1	, &internal1_m2077_tx},	//(internal1_m2077_tx) tx - время накопленное сек
	{ 1300	,18	,1	, &internal1_m2077_y0},	//(internal1_m2077_y0) y0
	{ 1301	,8	,1	, &internal1_m2091_q0},	//(internal1_m2091_q0) q0 - внутренний параметр
	{ 1302	,8	,1	, &internal1_m1648_q0},	//(internal1_m1648_q0) q0 - внутренний параметр
	{ 1303	,8	,1	, &internal1_m1686_q0},	//(internal1_m1686_q0) q0 - внутренний параметр
	{ 1304	,8	,1	, &internal1_m1689_q0},	//(internal1_m1689_q0) q0 - внутренний параметр
	{ 1305	,8	,1	, &internal1_m2131_q0},	//(internal1_m2131_q0) q0 - внутренний параметр
	{ 1306	,8	,1	, &internal1_m2109_tx},	//(internal1_m2109_tx) tx - время накопленное сек
	{ 1307	,18	,1	, &internal1_m2109_y0},	//(internal1_m2109_y0) y0
	{ 1308	,8	,1	, &internal1_m2124_tx},	//(internal1_m2124_tx) tx - время накопленное сек
	{ 1309	,18	,1	, &internal1_m2124_y0},	//(internal1_m2124_y0) y0
	{ 1310	,8	,1	, &internal1_m2121_tx},	//(internal1_m2121_tx) tx - время накопленное сек
	{ 1311	,18	,1	, &internal1_m2121_y0},	//(internal1_m2121_y0) y0
	{ 1312	,8	,1	, &internal1_m2264_tx},	//(internal1_m2264_tx) tx - время накопленное сек
	{ 1313	,18	,1	, &internal1_m2264_y0},	//(internal1_m2264_y0) y0
	{ 1314	,8	,1	, &internal1_m2275_tx},	//(internal1_m2275_tx) tx - время накопленное сек
	{ 1315	,18	,1	, &internal1_m2275_y0},	//(internal1_m2275_y0) y0
	{ 1316	,8	,1	, &internal1_m2030_tx},	//(internal1_m2030_tx) tx - время накопленное сек
	{ 1317	,18	,1	, &internal1_m2030_y0},	//(internal1_m2030_y0) y0
	{ 1318	,8	,1	, &internal1_m2029_tx},	//(internal1_m2029_tx) tx - время накопленное сек
	{ 1319	,18	,1	, &internal1_m2029_y0},	//(internal1_m2029_y0) y0
	{ 1320	,8	,1	, &internal1_m2028_tx},	//(internal1_m2028_tx) tx - время накопленное сек
	{ 1321	,18	,1	, &internal1_m2028_y0},	//(internal1_m2028_y0) y0
	{ 1322	,8	,1	, &internal1_m2027_tx},	//(internal1_m2027_tx) tx - время накопленное сек
	{ 1323	,18	,1	, &internal1_m2027_y0},	//(internal1_m2027_y0) y0
	{ 1324	,8	,1	, &internal1_m1702_tx},	//(internal1_m1702_tx) tx - время накопленное сек
	{ 1325	,18	,1	, &internal1_m1702_y0},	//(internal1_m1702_y0) y0
	{ 1326	,8	,1	, &internal1_m1696_tx},	//(internal1_m1696_tx) tx - время накопленное сек
	{ 1327	,18	,1	, &internal1_m1696_y0},	//(internal1_m1696_y0) y0
	{ 1328	,8	,1	, &internal1_m1643_tx},	//(internal1_m1643_tx) tx - время накопленное сек
	{ 1329	,18	,1	, &internal1_m1643_y0},	//(internal1_m1643_y0) y0
	{ 1330	,8	,1	, &internal1_m922_tx},	//(internal1_m922_tx) tx - время накопленное сек
	{ 1331	,18	,1	, &internal1_m922_y0},	//(internal1_m922_y0) y0
	{ 1332	,8	,1	, &internal1_m921_tx},	//(internal1_m921_tx) tx - время накопленное сек
	{ 1333	,18	,1	, &internal1_m921_y0},	//(internal1_m921_y0) y0
	{ 1334	,8	,1	, &internal1_m939_tx},	//(internal1_m939_tx) tx - время накопленное сек
	{ 1335	,18	,1	, &internal1_m939_y0},	//(internal1_m939_y0) y0
	{ 1336	,8	,1	, &internal1_m194_tx},	//(internal1_m194_tx) tx - время накопленное сек
	{ 1337	,18	,1	, &internal1_m194_y0},	//(internal1_m194_y0) y0
	{ 1338	,8	,1	, &internal1_m193_tx},	//(internal1_m193_tx) tx - время накопленное сек
	{ 1339	,18	,1	, &internal1_m193_y0},	//(internal1_m193_y0) y0
	{ 1340	,8	,1	, &internal1_m215_tx},	//(internal1_m215_tx) tx - время накопленное сек
	{ 1341	,18	,1	, &internal1_m215_y0},	//(internal1_m215_y0) y0
	{ 1342	,8	,1	, &internal1_m588_tx},	//(internal1_m588_tx) tx - время накопленное сек
	{ 1343	,18	,1	, &internal1_m588_y0},	//(internal1_m588_y0) y0
	{ 1344	,8	,1	, &internal1_m2320_tx},	//(internal1_m2320_tx) tx - внутренний параметр
	{ 1345	,8	,1	, &internal1_m1341_tx},	//(internal1_m1341_tx) tx - внутренний параметр
	{ 1346	,8	,1	, &internal1_m1832_tx},	//(internal1_m1832_tx) tx - время накопленное сек
	{ 1347	,18	,1	, &internal1_m1832_y0},	//(internal1_m1832_y0) y0
	{ 1348	,8	,1	, &internal1_m1306_tx},	//(internal1_m1306_tx) tx - время накопленное сек
	{ 1349	,18	,1	, &internal1_m1306_y0},	//(internal1_m1306_y0) y0
	{ 1350	,8	,1	, &internal1_m1525_tx},	//(internal1_m1525_tx) tx - время накопленное сек
	{ 1351	,18	,1	, &internal1_m1525_y0},	//(internal1_m1525_y0) y0
	{ 1352	,8	,1	, &internal1_m1052_tx},	//(internal1_m1052_tx) tx - время накопленное сек
	{ 1353	,18	,1	, &internal1_m1052_y0},	//(internal1_m1052_y0) y0
	{ 1354	,8	,1	, &internal1_m1415_tx},	//(internal1_m1415_tx) tx - время накопленное сек
	{ 1355	,18	,1	, &internal1_m1415_y0},	//(internal1_m1415_y0) y0
	{ 1356	,1	,1	, &internal1_m1209_q0},	//(internal1_m1209_q0) q0 - внутренний параметр
	{ 1357	,1	,1	, &internal1_m1207_q0},	//(internal1_m1207_q0) q0 - внутренний параметр
	{ 1358	,1	,1	, &internal1_m1206_q0},	//(internal1_m1206_q0) q0 - внутренний параметр
	{ 1359	,1	,1	, &internal1_m1204_q0},	//(internal1_m1204_q0) q0 - внутренний параметр
	{ 1360	,1	,1	, &internal1_m1203_q0},	//(internal1_m1203_q0) q0 - внутренний параметр
	{ 1361	,1	,1	, &internal1_m1201_q0},	//(internal1_m1201_q0) q0 - внутренний параметр
	{ 1362	,1	,1	, &internal1_m1200_q0},	//(internal1_m1200_q0) q0 - внутренний параметр
	{ 1363	,1	,1	, &internal1_m1198_q0},	//(internal1_m1198_q0) q0 - внутренний параметр
	{ 1364	,1	,1	, &internal1_m1197_q0},	//(internal1_m1197_q0) q0 - внутренний параметр
	{ 1365	,1	,1	, &internal1_m54_x0},	//(internal1_m54_x0) - значение входного параметра на предыдущем шаге
	{ 1366	,8	,1	, &internal1_m54_tim},	//(internal1_m54_tim) - время задержки выходного сигнала
	{ 1367	,1	,1	, &internal1_m1116_q0},	//(internal1_m1116_q0) q0 - внутренний параметр
	{ 1368	,1	,1	, &internal1_m1637_x0},	//(internal1_m1637_x0) - значение входного параметра на предыдущем шаге
	{ 1369	,8	,1	, &internal1_m1637_tim},	//(internal1_m1637_tim) - время задержки выходного сигнала
	{ 1370	,1	,1	, &internal1_m1685_x0},	//(internal1_m1685_x0) - значение входного параметра на предыдущем шаге
	{ 1371	,8	,1	, &internal1_m1685_tim},	//(internal1_m1685_tim) - время задержки выходного сигнала
	{ 1372	,1	,1	, &internal1_m1688_x0},	//(internal1_m1688_x0) - значение входного параметра на предыдущем шаге
	{ 1373	,8	,1	, &internal1_m1688_tim},	//(internal1_m1688_tim) - время задержки выходного сигнала
	{ 1374	,1	,1	, &internal1_m2072_x0},	//(internal1_m2072_x0) - значение входного параметра на предыдущем шаге
	{ 1375	,8	,1	, &internal1_m2072_tim},	//(internal1_m2072_tim) - время задержки выходного сигнала
	{ 1376	,1	,1	, &internal1_m1156_q0},	//(internal1_m1156_q0) q0 - внутренний параметр
	{ 1377	,1	,1	, &internal1_m1162_q0},	//(internal1_m1162_q0) q0 - внутренний параметр
	{ 1378	,1	,1	, &internal1_m1180_q0},	//(internal1_m1180_q0) q0 - внутренний параметр
	{ 1379	,1	,1	, &internal1_m1189_q0},	//(internal1_m1189_q0) q0 - внутренний параметр
	{ 1380	,1	,1	, &internal1_m1168_q0},	//(internal1_m1168_q0) q0 - внутренний параметр
	{ 1381	,1	,1	, &internal1_m1182_q0},	//(internal1_m1182_q0) q0 - внутренний параметр
	{ 1382	,1	,1	, &internal1_m2158_q0},	//(internal1_m2158_q0) q0 - внутренний параметр
	{ 1383	,1	,1	, &internal1_m2157_q0},	//(internal1_m2157_q0) q0 - внутренний параметр
	{ 1384	,3	,1	, &internal1_m356_Step},	//(internal1_m356_Step)  - текущий шаг программы
	{ 1385	,18	,10	, &internal1_m356_rz},	//(internal1_m356_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1386	,8	,1	, &internal1_m356_TimS},	//(internal1_m356_TimS) Время от старта программы
	{ 1387	,1	,1	, &internal1_m356_FinPr0},	//(internal1_m356_FinPr0) FinPr - конец программы
	{ 1388	,1	,1	, &internal1_m356_ErrPr0},	//(internal1_m356_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1389	,1	,1	, &internal1_m356_sbINI0},	//(internal1_m356_sbINI0) sbINI - запуск проверки ИНИ
	{ 1390	,1	,1	, &internal1_m356_sbVuIS0},	//(internal1_m356_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1391	,1	,1	, &internal1_m356_sb2UR0},	//(internal1_m356_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1392	,1	,1	, &internal1_m356_sbNupIS0},	//(internal1_m356_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1393	,1	,1	, &internal1_m356_sbVuRB0},	//(internal1_m356_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1394	,1	,1	, &internal1_m356_MyFirstEnterFlag},	//(internal1_m356_MyFirstEnterFlag)  
	{ 1395	,5	,1	, &internal1_m364_x0},	//(internal1_m364_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1396	,8	,1	, &internal1_m321_TimS},	//(internal1_m321_TimS) Время до нулевого отсчета
	{ 1397	,1	,1	, &internal1_m321_pusk0},	//(internal1_m321_pusk0) pusk - разрешение выполнения программы
	{ 1398	,3	,1	, &internal1_m298_Step},	//(internal1_m298_Step)  - текущий шаг программы
	{ 1399	,18	,10	, &internal1_m298_rz},	//(internal1_m298_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1400	,8	,1	, &internal1_m298_TimS},	//(internal1_m298_TimS) Время от старта программы
	{ 1401	,1	,1	, &internal1_m298_FinPr0},	//(internal1_m298_FinPr0) FinPr - конец программы
	{ 1402	,1	,1	, &internal1_m298_ErrPr0},	//(internal1_m298_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1403	,1	,1	, &internal1_m298_sbINI0},	//(internal1_m298_sbINI0) sbINI - запуск проверки ИНИ
	{ 1404	,1	,1	, &internal1_m298_sbVuIS0},	//(internal1_m298_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1405	,1	,1	, &internal1_m298_sb2UR0},	//(internal1_m298_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1406	,1	,1	, &internal1_m298_sbNupIS0},	//(internal1_m298_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1407	,1	,1	, &internal1_m298_sbVuRB0},	//(internal1_m298_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1408	,1	,1	, &internal1_m298_MyFirstEnterFlag},	//(internal1_m298_MyFirstEnterFlag)  
	{ 1409	,1	,1	, &internal1_m1599_q0},	//(internal1_m1599_q0) q0 - внутренний параметр
	{ 1410	,3	,1	, &internal1_m1600_Step},	//(internal1_m1600_Step)  - текущий шаг программы
	{ 1411	,18	,6	, &internal1_m1600_rz},	//(internal1_m1600_rz) - результат проверки 0-не запускалась, 1-запущена, 2-приостановлена, 3-успешно завершена, 4-ошибка
	{ 1412	,8	,1	, &internal1_m1600_TimS},	//(internal1_m1600_TimS) Время от старта программы
	{ 1413	,1	,1	, &internal1_m1600_FinPr0},	//(internal1_m1600_FinPr0) FinPr - конец программы
	{ 1414	,1	,1	, &internal1_m1600_ErrPr0},	//(internal1_m1600_ErrPr0) ErrPr - Приостановка программы по ошибке
	{ 1415	,1	,1	, &internal1_m1600_sbINI0},	//(internal1_m1600_sbINI0) sbINI - запуск проверки ИНИ
	{ 1416	,1	,1	, &internal1_m1600_sbVuIS0},	//(internal1_m1600_sbVuIS0) sbVuIS - запуск проверки сброса от ВУ ИС
	{ 1417	,1	,1	, &internal1_m1600_sb2UR0},	//(internal1_m1600_sb2UR0) sb2UR - запуск проверки сброса от 2УР
	{ 1418	,1	,1	, &internal1_m1600_sbNupIS0},	//(internal1_m1600_sbNupIS0) sbNupIS - запуск проверки сброса от НУП ИС
	{ 1419	,1	,1	, &internal1_m1600_sbVuRB0},	//(internal1_m1600_sbVuRB0) sbVuRB - запуск проверки сброса от ВУ РБ
	{ 1420	,1	,1	, &internal1_m1600_MyFirstEnterFlag},	//(internal1_m1600_MyFirstEnterFlag)  
	{ 1421	,1	,1	, &internal1_m1152_q0},	//(internal1_m1152_q0) q0 - внутренний параметр
	{ 1422	,1	,1	, &internal1_m1149_q0},	//(internal1_m1149_q0) q0 - внутренний параметр
	{ 1423	,1	,1	, &internal1_m1151_q0},	//(internal1_m1151_q0) q0 - внутренний параметр
	{ 1424	,1	,1	, &internal1_m1145_q0},	//(internal1_m1145_q0) q0 - внутренний параметр
	{ 1425	,1	,1	, &internal1_m836_q0},	//(internal1_m836_q0) q0 - внутренний параметр
	{ 1426	,1	,1	, &internal1_m366_q0},	//(internal1_m366_q0) q0 - внутренний параметр
	{ 1427	,1	,1	, &internal1_m362_q0},	//(internal1_m362_q0) q0 - внутренний параметр
	{ 1428	,1	,1	, &internal1_m318_q0},	//(internal1_m318_q0) q0 - внутренний параметр
	{ 1429	,5	,1	, &internal1_m317_x0},	//(internal1_m317_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1430	,1	,1	, &internal1_m2087_q0},	//(internal1_m2087_q0) q0 - внутренний параметр
	{ 1431	,1	,1	, &internal1_m2080_q0},	//(internal1_m2080_q0) q0 - внутренний параметр
	{ 1432	,1	,1	, &internal1_m2073_q0},	//(internal1_m2073_q0) q0 - внутренний параметр
	{ 1433	,1	,1	, &internal1_m2141_q0},	//(internal1_m2141_q0) q0 - внутренний параметр
	{ 1434	,1	,1	, &internal1_m2112_q0},	//(internal1_m2112_q0) q0 - внутренний параметр
	{ 1435	,1	,1	, &internal1_m2100_q0},	//(internal1_m2100_q0) q0 - внутренний параметр
	{ 1436	,1	,1	, &internal1_m1664_q0},	//(internal1_m1664_q0) q0 - внутренний параметр
	{ 1437	,1	,1	, &internal1_m1651_x0},	//(internal1_m1651_x0) был приход сигнала x1
	{ 1438	,8	,1	, &internal1_m1651_y0},	//(internal1_m1651_y0) интервал между сигналами х1 и х2
	{ 1439	,1	,1	, &internal1_m1651_fef},	//(internal1_m1651_fef) FirstEnterFlag
	{ 1440	,1	,1	, &internal1_m1646_q0},	//(internal1_m1646_q0) q0 - внутренний параметр
	{ 1441	,1	,1	, &internal1_m1636_q0},	//(internal1_m1636_q0) q0 - внутренний параметр
	{ 1442	,1	,1	, &internal1_m1699_q0},	//(internal1_m1699_q0) q0 - внутренний параметр
	{ 1443	,1	,1	, &internal1_m1720_q0},	//(internal1_m1720_q0) q0 - внутренний параметр
	{ 1444	,1	,1	, &internal1_m1684_q0},	//(internal1_m1684_q0) q0 - внутренний параметр
	{ 1445	,1	,1	, &internal1_m1700_x0},	//(internal1_m1700_x0) был приход сигнала x1
	{ 1446	,8	,1	, &internal1_m1700_y0},	//(internal1_m1700_y0) интервал между сигналами х1 и х2
	{ 1447	,1	,1	, &internal1_m1700_fef},	//(internal1_m1700_fef) FirstEnterFlag
	{ 1448	,5	,1	, &internal1_m1617_x0},	//(internal1_m1617_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1449	,1	,1	, &internal1_m1706_q0},	//(internal1_m1706_q0) q0 - внутренний параметр
	{ 1450	,1	,1	, &internal1_m26_q0},	//(internal1_m26_q0) q0 - внутренний параметр
	{ 1451	,1	,1	, &internal1_m1721_q0},	//(internal1_m1721_q0) q0 - внутренний параметр
	{ 1452	,1	,1	, &internal1_m711_q0},	//(internal1_m711_q0) q0 - внутренний параметр
	{ 1453	,1	,1	, &internal1_m696_q0},	//(internal1_m696_q0) q0 - внутренний параметр
	{ 1454	,1	,1	, &internal1_m724_q0},	//(internal1_m724_q0) q0 - внутренний параметр
	{ 1455	,1	,1	, &internal1_m707_q0},	//(internal1_m707_q0) q0 - внутренний параметр
	{ 1456	,1	,1	, &internal1_m691_q0},	//(internal1_m691_q0) q0 - внутренний параметр
	{ 1457	,1	,1	, &internal1_m689_q0},	//(internal1_m689_q0) q0 - внутренний параметр
	{ 1458	,1	,1	, &internal1_m677_q0},	//(internal1_m677_q0) q0 - внутренний параметр
	{ 1459	,5	,1	, &internal1_m1602_q0},	//(internal1_m1602_q0) q0 - внутренний параметр
	{ 1460	,1	,1	, &internal1_m687_q0},	//(internal1_m687_q0) q0 - внутренний параметр
	{ 1461	,1	,1	, &internal1_m116_q0},	//(internal1_m116_q0) q0 - внутренний параметр
	{ 1462	,1	,1	, &internal1_m1867_q0},	//(internal1_m1867_q0) q0 - внутренний параметр
	{ 1463	,1	,1	, &internal1_m1866_q0},	//(internal1_m1866_q0) q0 - внутренний параметр
	{ 1464	,1	,1	, &internal1_m1865_q0},	//(internal1_m1865_q0) q0 - внутренний параметр
	{ 1465	,1	,1	, &internal1_m1864_q0},	//(internal1_m1864_q0) q0 - внутренний параметр
	{ 1466	,1	,1	, &internal1_m1900_q0},	//(internal1_m1900_q0) q0 - внутренний параметр
	{ 1467	,1	,1	, &internal1_m1899_q0},	//(internal1_m1899_q0) q0 - внутренний параметр
	{ 1468	,1	,1	, &internal1_m1898_q0},	//(internal1_m1898_q0) q0 - внутренний параметр
	{ 1469	,1	,1	, &internal1_m2172_q0},	//(internal1_m2172_q0) q0 - внутренний параметр
	{ 1470	,1	,1	, &internal1_m1960_q0},	//(internal1_m1960_q0) q0 - внутренний параметр
	{ 1471	,1	,1	, &internal1_m1950_q0},	//(internal1_m1950_q0) q0 - внутренний параметр
	{ 1472	,1	,1	, &internal1_m1957_q0},	//(internal1_m1957_q0) q0 - внутренний параметр
	{ 1473	,1	,1	, &internal1_m1947_q0},	//(internal1_m1947_q0) q0 - внутренний параметр
	{ 1474	,1	,1	, &internal1_m1954_q0},	//(internal1_m1954_q0) q0 - внутренний параметр
	{ 1475	,1	,1	, &internal1_m2388_q0},	//(internal1_m2388_q0) q0 - внутренний параметр
	{ 1476	,1	,1	, &internal1_m2384_q0},	//(internal1_m2384_q0) q0 - внутренний параметр
	{ 1477	,1	,1	, &internal1_m1925_q0},	//(internal1_m1925_q0) q0 - внутренний параметр
	{ 1478	,1	,1	, &internal1_m1917_q0},	//(internal1_m1917_q0) q0 - внутренний параметр
	{ 1479	,1	,1	, &internal1_m1915_q0},	//(internal1_m1915_q0) q0 - внутренний параметр
	{ 1480	,1	,1	, &internal1_m1911_q0},	//(internal1_m1911_q0) q0 - внутренний параметр
	{ 1481	,1	,1	, &internal1_m1907_q0},	//(internal1_m1907_q0) q0 - внутренний параметр
	{ 1482	,1	,1	, &internal1_m1909_q0},	//(internal1_m1909_q0) q0 - внутренний параметр
	{ 1483	,1	,1	, &internal1_m19_q0},	//(internal1_m19_q0) q0 - внутренний параметр
	{ 1484	,1	,1	, &internal1_m1890_q0},	//(internal1_m1890_q0) q0 - внутренний параметр
	{ 1485	,1	,1	, &internal1_m1888_q0},	//(internal1_m1888_q0) q0 - внутренний параметр
	{ 1486	,1	,1	, &internal1_m1884_q0},	//(internal1_m1884_q0) q0 - внутренний параметр
	{ 1487	,1	,1	, &internal1_m1886_q0},	//(internal1_m1886_q0) q0 - внутренний параметр
	{ 1488	,1	,1	, &internal1_m1882_q0},	//(internal1_m1882_q0) q0 - внутренний параметр
	{ 1489	,1	,1	, &internal1_m1880_q0},	//(internal1_m1880_q0) q0 - внутренний параметр
	{ 1490	,1	,1	, &internal1_m2294_q0},	//(internal1_m2294_q0) q0 - внутренний параметр
	{ 1491	,1	,1	, &internal1_m2292_q0},	//(internal1_m2292_q0) q0 - внутренний параметр
	{ 1492	,1	,1	, &internal1_m2269_q0},	//(internal1_m2269_q0) q0 - внутренний параметр
	{ 1493	,1	,1	, &internal1_m2253_q0},	//(internal1_m2253_q0) q0 - внутренний параметр
	{ 1494	,1	,1	, &internal1_m2184_q0},	//(internal1_m2184_q0) q0 - внутренний параметр
	{ 1495	,1	,1	, &internal1_m1876_q0},	//(internal1_m1876_q0) q0 - внутренний параметр
	{ 1496	,1	,1	, &internal1_m1878_q0},	//(internal1_m1878_q0) q0 - внутренний параметр
	{ 1497	,1	,1	, &internal1_m1862_q0},	//(internal1_m1862_q0) q0 - внутренний параметр
	{ 1498	,1	,1	, &internal1_m1860_q0},	//(internal1_m1860_q0) q0 - внутренний параметр
	{ 1499	,1	,1	, &internal1_m1858_q0},	//(internal1_m1858_q0) q0 - внутренний параметр
	{ 1500	,1	,1	, &internal1_m1856_q0},	//(internal1_m1856_q0) q0 - внутренний параметр
	{ 1501	,1	,1	, &internal1_m1855_q0},	//(internal1_m1855_q0) q0 - внутренний параметр
	{ 1502	,1	,1	, &internal1_m1853_q0},	//(internal1_m1853_q0) q0 - внутренний параметр
	{ 1503	,1	,1	, &internal1_m1852_q0},	//(internal1_m1852_q0) q0 - внутренний параметр
	{ 1504	,1	,1	, &internal1_m1850_q0},	//(internal1_m1850_q0) q0 - внутренний параметр
	{ 1505	,18	,1	, &internal1_m2325_DvUp0},	//(internal1_m2325_DvUp0) - есть команда на движение вперёд
	{ 1506	,18	,1	, &internal1_m2325_DvDw0},	//(internal1_m2325_DvDw0) - есть команда на движение назад
	{ 1507	,18	,1	, &internal1_m2325_FDvUp0},	//(internal1_m2325_FDvUp0) - есть команда на движение вперёд
	{ 1508	,18	,1	, &internal1_m2325_FDvDw0},	//(internal1_m2325_FDvDw0) - есть команда на движение назад
	{ 1509	,18	,1	, &internal1_m2325_BlDv0},	//(internal1_m2325_BlDv0) - была блокировка
	{ 1510	,18	,1	, &internal1_m2325_Pkv0},	//(internal1_m2325_Pkv0) Pkv - передний конечный выключатель
	{ 1511	,18	,1	, &internal1_m2325_Pkav0},	//(internal1_m2325_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1512	,18	,1	, &internal1_m2325_Zkv0},	//(internal1_m2325_Zkv0) Zkv - задний конечный выключатель
	{ 1513	,18	,1	, &internal1_m2325_Zkav0},	//(internal1_m2325_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1514	,8	,1	, &internal1_m2325_txNm},	//(internal1_m2325_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1515	,8	,1	, &internal1_m2325_txSm},	//(internal1_m2325_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1516	,8	,1	, &internal1_m2325_txHr},	//(internal1_m2325_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1517	,8	,1	, &internal1_m2325_txLd},	//(internal1_m2325_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1518	,18	,1	, &internal1_m2325_fef},	//(internal1_m2325_fef) fef
	{ 1519	,18	,1	, &internal1_m2319_DvUp0},	//(internal1_m2319_DvUp0) - есть команда на движение вперёд
	{ 1520	,18	,1	, &internal1_m2319_DvDw0},	//(internal1_m2319_DvDw0) - есть команда на движение назад
	{ 1521	,18	,1	, &internal1_m2319_FDvUp0},	//(internal1_m2319_FDvUp0) - есть команда на движение вперёд
	{ 1522	,18	,1	, &internal1_m2319_FDvDw0},	//(internal1_m2319_FDvDw0) - есть команда на движение назад
	{ 1523	,18	,1	, &internal1_m2319_BlDv0},	//(internal1_m2319_BlDv0) - была блокировка
	{ 1524	,18	,1	, &internal1_m2319_Pkv0},	//(internal1_m2319_Pkv0) Pkv - передний конечный выключатель
	{ 1525	,18	,1	, &internal1_m2319_Pkav0},	//(internal1_m2319_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1526	,18	,1	, &internal1_m2319_Zkv0},	//(internal1_m2319_Zkv0) Zkv - задний конечный выключатель
	{ 1527	,18	,1	, &internal1_m2319_Zkav0},	//(internal1_m2319_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1528	,8	,1	, &internal1_m2319_txNm},	//(internal1_m2319_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1529	,8	,1	, &internal1_m2319_txSm},	//(internal1_m2319_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1530	,8	,1	, &internal1_m2319_txHr},	//(internal1_m2319_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1531	,8	,1	, &internal1_m2319_txLd},	//(internal1_m2319_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1532	,18	,1	, &internal1_m2319_fef},	//(internal1_m2319_fef) fef
	{ 1533	,1	,1	, &internal1_m1679_q0},	//(internal1_m1679_q0) q0 - внутренний параметр
	{ 1534	,1	,1	, &internal1_m1705_x0},	//(internal1_m1705_x0) был приход сигнала x1
	{ 1535	,8	,1	, &internal1_m1705_y0},	//(internal1_m1705_y0) интервал между сигналами х1 и х2
	{ 1536	,1	,1	, &internal1_m1705_fef},	//(internal1_m1705_fef) FirstEnterFlag
	{ 1537	,1	,1	, &internal1_m2123_x0},	//(internal1_m2123_x0) был приход сигнала x1
	{ 1538	,8	,1	, &internal1_m2123_y0},	//(internal1_m2123_y0) интервал между сигналами х1 и х2
	{ 1539	,1	,1	, &internal1_m2123_fef},	//(internal1_m2123_fef) FirstEnterFlag
	{ 1540	,1	,1	, &internal1_m2082_x0},	//(internal1_m2082_x0) был приход сигнала x1
	{ 1541	,8	,1	, &internal1_m2082_y0},	//(internal1_m2082_y0) интервал между сигналами х1 и х2
	{ 1542	,1	,1	, &internal1_m2082_fef},	//(internal1_m2082_fef) FirstEnterFlag
	{ 1543	,1	,1	, &internal1_m309_q0},	//(internal1_m309_q0) q0 - внутренний параметр
	{ 1544	,1	,1	, &internal1_m1124_q0},	//(internal1_m1124_q0) q0 - внутренний параметр
	{ 1545	,1	,1	, &internal1_m699_q0},	//(internal1_m699_q0) q0 - внутренний параметр
	{ 1546	,8	,1	, &internal1_m1483_X0},	//(internal1_m1483_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1547	,8	,1	, &internal1_m1483_t0},	//(internal1_m1483_t0) время нахождения в зоне возврата
	{ 1548	,18	,1	, &internal1_m1483_BLDv0},	//(internal1_m1483_BLDv0) BlDv - Блокировка движения
	{ 1549	,8	,1	, &internal1_m1500_tx},	//(internal1_m1500_tx) tx - время накопленное сек
	{ 1550	,18	,1	, &internal1_m1500_y0},	//(internal1_m1500_y0) y0
	{ 1551	,8	,1	, &internal1_m1501_tx},	//(internal1_m1501_tx) tx - время накопленное сек
	{ 1552	,18	,1	, &internal1_m1501_y0},	//(internal1_m1501_y0) y0
	{ 1553	,3	,1	, &internal1_m1509_xptr},	//(internal1_m1509_xptr) указатель текущей позиции в массиве координат
	{ 1554	,8	,60	, &internal1_m1509_x0},	//(internal1_m1509_x0) x0 - массив мгновенных значений координат
	{ 1555	,8	,60	, &internal1_m1509_tim0},	//(internal1_m1509_tim0) tim0 - массив значений времени цикла
	{ 1556	,8	,1	, &internal1_m1509_sumtim},	//(internal1_m1509_sumtim) sumtim - время в пути
	{ 1557	,8	,1	, &internal1_m1509_StSpeed},	//(internal1_m1509_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1558	,8	,1	, &internal1_m1509_Vz0},	//(internal1_m1509_Vz0) Vz0 - предыдущая заданная скорость
	{ 1559	,3	,1	, &internal1_m1509_flRazg},	//(internal1_m1509_flRazg) признак разгона/торможения
	{ 1560	,8	,1	, &internal1_m1509_DelSp},	//(internal1_m1509_DelSp) DelSp - время переключения скоростей
	{ 1561	,8	,1	, &internal1_m1509_z0},	//(internal1_m1509_z0) z0 - точка прекращения движения
	{ 1562	,8	,1	, &internal1_m1509_txZS},	//(internal1_m1509_txZS) txZS
	{ 1563	,8	,1	, &internal1_m1509_tx},	//(internal1_m1509_tx) tx
	{ 1564	,8	,1	, &internal1_m1509_txd},	//(internal1_m1509_txd) txd
	{ 1565	,8	,1	, &internal1_m1509_txMBl},	//(internal1_m1509_txMBl) tx
	{ 1566	,8	,1	, &internal1_m1509_txBl},	//(internal1_m1509_txBl) tx
	{ 1567	,8	,1	, &internal1_m1509_Speed0},	//(internal1_m1509_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1568	,8	,1	, &internal1_m1509_xz0},	//(internal1_m1509_xz0) xz0 - новое задание мм
	{ 1569	,8	,1	, &internal1_m1509_tz0},	//(internal1_m1509_tz0) tz0 - время защиты от нового задания сек
	{ 1570	,1	,1	, &internal1_m1509_Shift0},	//(internal1_m1509_Shift0) Shift0 - признак самохода
	{ 1571	,1	,1	, &internal1_m1509_ShCntlSp0},	//(internal1_m1509_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1572	,1	,1	, &internal1_m1509_ShiftControl},	//(internal1_m1509_ShiftControl) ShiftControl - признак самохода
	{ 1573	,1	,1	, &internal1_m697_q0},	//(internal1_m697_q0) q0 - внутренний параметр
	{ 1574	,8	,1	, &internal1_m1005_X0},	//(internal1_m1005_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1575	,8	,1	, &internal1_m1005_t0},	//(internal1_m1005_t0) время нахождения в зоне возврата
	{ 1576	,18	,1	, &internal1_m1005_BLDv0},	//(internal1_m1005_BLDv0) BlDv - Блокировка движения
	{ 1577	,8	,1	, &internal1_m1028_tx},	//(internal1_m1028_tx) tx - время накопленное сек
	{ 1578	,18	,1	, &internal1_m1028_y0},	//(internal1_m1028_y0) y0
	{ 1579	,8	,1	, &internal1_m1027_tx},	//(internal1_m1027_tx) tx - время накопленное сек
	{ 1580	,18	,1	, &internal1_m1027_y0},	//(internal1_m1027_y0) y0
	{ 1581	,3	,1	, &internal1_m1035_xptr},	//(internal1_m1035_xptr) указатель текущей позиции в массиве координат
	{ 1582	,8	,60	, &internal1_m1035_x0},	//(internal1_m1035_x0) x0 - массив мгновенных значений координат
	{ 1583	,8	,60	, &internal1_m1035_tim0},	//(internal1_m1035_tim0) tim0 - массив значений времени цикла
	{ 1584	,8	,1	, &internal1_m1035_sumtim},	//(internal1_m1035_sumtim) sumtim - время в пути
	{ 1585	,8	,1	, &internal1_m1035_StSpeed},	//(internal1_m1035_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1586	,8	,1	, &internal1_m1035_Vz0},	//(internal1_m1035_Vz0) Vz0 - предыдущая заданная скорость
	{ 1587	,3	,1	, &internal1_m1035_flRazg},	//(internal1_m1035_flRazg) признак разгона/торможения
	{ 1588	,8	,1	, &internal1_m1035_DelSp},	//(internal1_m1035_DelSp) DelSp - время переключения скоростей
	{ 1589	,8	,1	, &internal1_m1035_z0},	//(internal1_m1035_z0) z0 - точка прекращения движения
	{ 1590	,8	,1	, &internal1_m1035_txZS},	//(internal1_m1035_txZS) txZS
	{ 1591	,8	,1	, &internal1_m1035_tx},	//(internal1_m1035_tx) tx
	{ 1592	,8	,1	, &internal1_m1035_txd},	//(internal1_m1035_txd) txd
	{ 1593	,8	,1	, &internal1_m1035_txMBl},	//(internal1_m1035_txMBl) tx
	{ 1594	,8	,1	, &internal1_m1035_txBl},	//(internal1_m1035_txBl) tx
	{ 1595	,8	,1	, &internal1_m1035_Speed0},	//(internal1_m1035_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1596	,8	,1	, &internal1_m1035_xz0},	//(internal1_m1035_xz0) xz0 - новое задание мм
	{ 1597	,8	,1	, &internal1_m1035_tz0},	//(internal1_m1035_tz0) tz0 - время защиты от нового задания сек
	{ 1598	,1	,1	, &internal1_m1035_Shift0},	//(internal1_m1035_Shift0) Shift0 - признак самохода
	{ 1599	,1	,1	, &internal1_m1035_ShCntlSp0},	//(internal1_m1035_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1600	,1	,1	, &internal1_m1035_ShiftControl},	//(internal1_m1035_ShiftControl) ShiftControl - признак самохода
	{ 1601	,8	,1	, &internal1_m550_X0},	//(internal1_m550_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1602	,8	,1	, &internal1_m550_t0},	//(internal1_m550_t0) время нахождения в зоне возврата
	{ 1603	,18	,1	, &internal1_m550_BLDv0},	//(internal1_m550_BLDv0) BlDv - Блокировка движения
	{ 1604	,8	,1	, &internal1_m569_tx},	//(internal1_m569_tx) tx - время накопленное сек
	{ 1605	,18	,1	, &internal1_m569_y0},	//(internal1_m569_y0) y0
	{ 1606	,8	,1	, &internal1_m568_tx},	//(internal1_m568_tx) tx - время накопленное сек
	{ 1607	,18	,1	, &internal1_m568_y0},	//(internal1_m568_y0) y0
	{ 1608	,3	,1	, &internal1_m573_xptr},	//(internal1_m573_xptr) указатель текущей позиции в массиве координат
	{ 1609	,8	,150	, &internal1_m573_x0},	//(internal1_m573_x0) x0 - массив мгновенных значений координат
	{ 1610	,8	,150	, &internal1_m573_tim0},	//(internal1_m573_tim0) tim0 - массив значений времени цикла
	{ 1611	,8	,1	, &internal1_m573_sumtim},	//(internal1_m573_sumtim) sumtim - время в пути
	{ 1612	,8	,1	, &internal1_m573_StSpeed},	//(internal1_m573_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1613	,8	,1	, &internal1_m573_Vz0},	//(internal1_m573_Vz0) Vz0 - предыдущая заданная скорость
	{ 1614	,3	,1	, &internal1_m573_flRazg},	//(internal1_m573_flRazg) признак разгона/торможения
	{ 1615	,8	,1	, &internal1_m573_DelSp},	//(internal1_m573_DelSp) DelSp - время переключения скоростей
	{ 1616	,8	,1	, &internal1_m573_z0},	//(internal1_m573_z0) z0 - точка прекращения движения
	{ 1617	,8	,1	, &internal1_m573_txZS},	//(internal1_m573_txZS) txZS
	{ 1618	,8	,1	, &internal1_m573_tx},	//(internal1_m573_tx) tx
	{ 1619	,8	,1	, &internal1_m573_txd},	//(internal1_m573_txd) txd
	{ 1620	,8	,1	, &internal1_m573_txMBl},	//(internal1_m573_txMBl) tx
	{ 1621	,8	,1	, &internal1_m573_txBl},	//(internal1_m573_txBl) tx
	{ 1622	,8	,1	, &internal1_m573_Speed0},	//(internal1_m573_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1623	,8	,1	, &internal1_m573_xz0},	//(internal1_m573_xz0) xz0 - новое задание мм
	{ 1624	,8	,1	, &internal1_m573_tz0},	//(internal1_m573_tz0) tz0 - время защиты от нового задания сек
	{ 1625	,1	,1	, &internal1_m573_Shift0},	//(internal1_m573_Shift0) Shift0 - признак самохода
	{ 1626	,1	,1	, &internal1_m573_ShCntlSp0},	//(internal1_m573_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1627	,1	,1	, &internal1_m573_ShiftControl},	//(internal1_m573_ShiftControl) ShiftControl - признак самохода
	{ 1628	,1	,1	, &internal1_m694_q0},	//(internal1_m694_q0) q0 - внутренний параметр
	{ 1629	,8	,1	, &internal1_m176_X0},	//(internal1_m176_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1630	,8	,1	, &internal1_m176_t0},	//(internal1_m176_t0) время нахождения в зоне возврата
	{ 1631	,18	,1	, &internal1_m176_BLDv0},	//(internal1_m176_BLDv0) BlDv - Блокировка движения
	{ 1632	,3	,1	, &internal1_m201_xptr},	//(internal1_m201_xptr) указатель текущей позиции в массиве координат
	{ 1633	,8	,150	, &internal1_m201_x0},	//(internal1_m201_x0) x0 - массив мгновенных значений координат
	{ 1634	,8	,150	, &internal1_m201_tim0},	//(internal1_m201_tim0) tim0 - массив значений времени цикла
	{ 1635	,8	,1	, &internal1_m201_sumtim},	//(internal1_m201_sumtim) sumtim - время в пути
	{ 1636	,8	,1	, &internal1_m201_StSpeed},	//(internal1_m201_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1637	,8	,1	, &internal1_m201_Vz0},	//(internal1_m201_Vz0) Vz0 - предыдущая заданная скорость
	{ 1638	,3	,1	, &internal1_m201_flRazg},	//(internal1_m201_flRazg) признак разгона/торможения
	{ 1639	,8	,1	, &internal1_m201_DelSp},	//(internal1_m201_DelSp) DelSp - время переключения скоростей
	{ 1640	,8	,1	, &internal1_m201_z0},	//(internal1_m201_z0) z0 - точка прекращения движения
	{ 1641	,8	,1	, &internal1_m201_txZS},	//(internal1_m201_txZS) txZS
	{ 1642	,8	,1	, &internal1_m201_tx},	//(internal1_m201_tx) tx
	{ 1643	,8	,1	, &internal1_m201_txd},	//(internal1_m201_txd) txd
	{ 1644	,8	,1	, &internal1_m201_txMBl},	//(internal1_m201_txMBl) tx
	{ 1645	,8	,1	, &internal1_m201_txBl},	//(internal1_m201_txBl) tx
	{ 1646	,8	,1	, &internal1_m201_Speed0},	//(internal1_m201_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1647	,8	,1	, &internal1_m201_xz0},	//(internal1_m201_xz0) xz0 - новое задание мм
	{ 1648	,8	,1	, &internal1_m201_tz0},	//(internal1_m201_tz0) tz0 - время защиты от нового задания сек
	{ 1649	,1	,1	, &internal1_m201_Shift0},	//(internal1_m201_Shift0) Shift0 - признак самохода
	{ 1650	,1	,1	, &internal1_m201_ShCntlSp0},	//(internal1_m201_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1651	,1	,1	, &internal1_m201_ShiftControl},	//(internal1_m201_ShiftControl) ShiftControl - признак самохода
	{ 1652	,1	,1	, &internal1_m720_q0},	//(internal1_m720_q0) q0 - внутренний параметр
	{ 1653	,18	,1	, &internal1_m517_DvUp0},	//(internal1_m517_DvUp0) - есть команда на движение вперёд
	{ 1654	,18	,1	, &internal1_m517_DvDw0},	//(internal1_m517_DvDw0) - есть команда на движение назад
	{ 1655	,18	,1	, &internal1_m517_FDvUp0},	//(internal1_m517_FDvUp0) - есть команда на движение вперёд
	{ 1656	,18	,1	, &internal1_m517_FDvDw0},	//(internal1_m517_FDvDw0) - есть команда на движение назад
	{ 1657	,18	,1	, &internal1_m517_BlDv0},	//(internal1_m517_BlDv0) - была блокировка
	{ 1658	,18	,1	, &internal1_m517_Pkv0},	//(internal1_m517_Pkv0) Pkv - передний конечный выключатель
	{ 1659	,18	,1	, &internal1_m517_Pkav0},	//(internal1_m517_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1660	,18	,1	, &internal1_m517_Zkv0},	//(internal1_m517_Zkv0) Zkv - задний конечный выключатель
	{ 1661	,18	,1	, &internal1_m517_Zkav0},	//(internal1_m517_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1662	,8	,1	, &internal1_m517_txNm},	//(internal1_m517_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1663	,8	,1	, &internal1_m517_txSm},	//(internal1_m517_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1664	,8	,1	, &internal1_m517_txHr},	//(internal1_m517_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1665	,8	,1	, &internal1_m517_txLd},	//(internal1_m517_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1666	,18	,1	, &internal1_m517_fef},	//(internal1_m517_fef) fef
	{ 1667	,18	,1	, &internal1_m511_DvUp0},	//(internal1_m511_DvUp0) - есть команда на движение вперёд
	{ 1668	,18	,1	, &internal1_m511_DvDw0},	//(internal1_m511_DvDw0) - есть команда на движение назад
	{ 1669	,18	,1	, &internal1_m511_FDvUp0},	//(internal1_m511_FDvUp0) - есть команда на движение вперёд
	{ 1670	,18	,1	, &internal1_m511_FDvDw0},	//(internal1_m511_FDvDw0) - есть команда на движение назад
	{ 1671	,18	,1	, &internal1_m511_BlDv0},	//(internal1_m511_BlDv0) - была блокировка
	{ 1672	,18	,1	, &internal1_m511_Pkv0},	//(internal1_m511_Pkv0) Pkv - передний конечный выключатель
	{ 1673	,18	,1	, &internal1_m511_Pkav0},	//(internal1_m511_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1674	,18	,1	, &internal1_m511_Zkv0},	//(internal1_m511_Zkv0) Zkv - задний конечный выключатель
	{ 1675	,18	,1	, &internal1_m511_Zkav0},	//(internal1_m511_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1676	,8	,1	, &internal1_m511_txNm},	//(internal1_m511_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1677	,8	,1	, &internal1_m511_txSm},	//(internal1_m511_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1678	,8	,1	, &internal1_m511_txHr},	//(internal1_m511_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1679	,8	,1	, &internal1_m511_txLd},	//(internal1_m511_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1680	,18	,1	, &internal1_m511_fef},	//(internal1_m511_fef) fef
	{ 1681	,8	,1	, &internal1_m909_X0},	//(internal1_m909_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1682	,8	,1	, &internal1_m909_t0},	//(internal1_m909_t0) время нахождения в зоне возврата
	{ 1683	,18	,1	, &internal1_m909_BLDv0},	//(internal1_m909_BLDv0) BlDv - Блокировка движения
	{ 1684	,3	,1	, &internal1_m927_xptr},	//(internal1_m927_xptr) указатель текущей позиции в массиве координат
	{ 1685	,8	,80	, &internal1_m927_x0},	//(internal1_m927_x0) x0 - массив мгновенных значений координат
	{ 1686	,8	,80	, &internal1_m927_tim0},	//(internal1_m927_tim0) tim0 - массив значений времени цикла
	{ 1687	,8	,1	, &internal1_m927_sumtim},	//(internal1_m927_sumtim) sumtim - время в пути
	{ 1688	,8	,1	, &internal1_m927_StSpeed},	//(internal1_m927_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1689	,8	,1	, &internal1_m927_Vz0},	//(internal1_m927_Vz0) Vz0 - предыдущая заданная скорость
	{ 1690	,3	,1	, &internal1_m927_flRazg},	//(internal1_m927_flRazg) признак разгона/торможения
	{ 1691	,8	,1	, &internal1_m927_DelSp},	//(internal1_m927_DelSp) DelSp - время переключения скоростей
	{ 1692	,8	,1	, &internal1_m927_z0},	//(internal1_m927_z0) z0 - точка прекращения движения
	{ 1693	,8	,1	, &internal1_m927_txZS},	//(internal1_m927_txZS) txZS
	{ 1694	,8	,1	, &internal1_m927_tx},	//(internal1_m927_tx) tx
	{ 1695	,8	,1	, &internal1_m927_txd},	//(internal1_m927_txd) txd
	{ 1696	,8	,1	, &internal1_m927_txMBl},	//(internal1_m927_txMBl) tx
	{ 1697	,8	,1	, &internal1_m927_txBl},	//(internal1_m927_txBl) tx
	{ 1698	,8	,1	, &internal1_m927_Speed0},	//(internal1_m927_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1699	,8	,1	, &internal1_m927_xz0},	//(internal1_m927_xz0) xz0 - новое задание мм
	{ 1700	,8	,1	, &internal1_m927_tz0},	//(internal1_m927_tz0) tz0 - время защиты от нового задания сек
	{ 1701	,1	,1	, &internal1_m927_Shift0},	//(internal1_m927_Shift0) Shift0 - признак самохода
	{ 1702	,1	,1	, &internal1_m927_ShCntlSp0},	//(internal1_m927_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1703	,1	,1	, &internal1_m927_ShiftControl},	//(internal1_m927_ShiftControl) ShiftControl - признак самохода
	{ 1704	,8	,1	, &internal1_m1804_X0},	//(internal1_m1804_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1705	,8	,1	, &internal1_m1804_t0},	//(internal1_m1804_t0) время нахождения в зоне возврата
	{ 1706	,18	,1	, &internal1_m1804_BLDv0},	//(internal1_m1804_BLDv0) BlDv - Блокировка движения
	{ 1707	,8	,1	, &internal1_m1273_X0},	//(internal1_m1273_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1708	,8	,1	, &internal1_m1273_t0},	//(internal1_m1273_t0) время нахождения в зоне возврата
	{ 1709	,18	,1	, &internal1_m1273_BLDv0},	//(internal1_m1273_BLDv0) BlDv - Блокировка движения
	{ 1710	,1	,1	, &internal1_m692_q0},	//(internal1_m692_q0) q0 - внутренний параметр
	{ 1711	,8	,1	, &internal1_m1370_X0},	//(internal1_m1370_X0) текущая зона нечувствительности (Dlt/Du) в мм (гр.)
	{ 1712	,8	,1	, &internal1_m1370_t0},	//(internal1_m1370_t0) время нахождения в зоне возврата
	{ 1713	,18	,1	, &internal1_m1370_BLDv0},	//(internal1_m1370_BLDv0) BlDv - Блокировка движения
	{ 1714	,8	,1	, &internal1_m1398_tx},	//(internal1_m1398_tx) tx - время накопленное сек
	{ 1715	,18	,1	, &internal1_m1398_y0},	//(internal1_m1398_y0) y0
	{ 1716	,8	,1	, &internal1_m1397_tx},	//(internal1_m1397_tx) tx - время накопленное сек
	{ 1717	,18	,1	, &internal1_m1397_y0},	//(internal1_m1397_y0) y0
	{ 1718	,3	,1	, &internal1_m1405_xptr},	//(internal1_m1405_xptr) указатель текущей позиции в массиве координат
	{ 1719	,8	,80	, &internal1_m1405_x0},	//(internal1_m1405_x0) x0 - массив мгновенных значений координат
	{ 1720	,8	,80	, &internal1_m1405_tim0},	//(internal1_m1405_tim0) tim0 - массив значений времени цикла
	{ 1721	,8	,1	, &internal1_m1405_sumtim},	//(internal1_m1405_sumtim) sumtim - время в пути
	{ 1722	,8	,1	, &internal1_m1405_StSpeed},	//(internal1_m1405_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1723	,8	,1	, &internal1_m1405_Vz0},	//(internal1_m1405_Vz0) Vz0 - предыдущая заданная скорость
	{ 1724	,3	,1	, &internal1_m1405_flRazg},	//(internal1_m1405_flRazg) признак разгона/торможения
	{ 1725	,8	,1	, &internal1_m1405_DelSp},	//(internal1_m1405_DelSp) DelSp - время переключения скоростей
	{ 1726	,8	,1	, &internal1_m1405_z0},	//(internal1_m1405_z0) z0 - точка прекращения движения
	{ 1727	,8	,1	, &internal1_m1405_txZS},	//(internal1_m1405_txZS) txZS
	{ 1728	,8	,1	, &internal1_m1405_tx},	//(internal1_m1405_tx) tx
	{ 1729	,8	,1	, &internal1_m1405_txd},	//(internal1_m1405_txd) txd
	{ 1730	,8	,1	, &internal1_m1405_txMBl},	//(internal1_m1405_txMBl) tx
	{ 1731	,8	,1	, &internal1_m1405_txBl},	//(internal1_m1405_txBl) tx
	{ 1732	,8	,1	, &internal1_m1405_Speed0},	//(internal1_m1405_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1733	,8	,1	, &internal1_m1405_xz0},	//(internal1_m1405_xz0) xz0 - новое задание мм
	{ 1734	,8	,1	, &internal1_m1405_tz0},	//(internal1_m1405_tz0) tz0 - время защиты от нового задания сек
	{ 1735	,1	,1	, &internal1_m1405_Shift0},	//(internal1_m1405_Shift0) Shift0 - признак самохода
	{ 1736	,1	,1	, &internal1_m1405_ShCntlSp0},	//(internal1_m1405_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1737	,1	,1	, &internal1_m1405_ShiftControl},	//(internal1_m1405_ShiftControl) ShiftControl - признак самохода
	{ 1738	,1	,1	, &internal1_m712_q0},	//(internal1_m712_q0) q0 - внутренний параметр
	{ 1739	,8	,1	, &internal1_m1818_tx},	//(internal1_m1818_tx) tx - время накопленное сек
	{ 1740	,18	,1	, &internal1_m1818_y0},	//(internal1_m1818_y0) y0
	{ 1741	,8	,1	, &internal1_m1822_tx},	//(internal1_m1822_tx) tx - время накопленное сек
	{ 1742	,18	,1	, &internal1_m1822_y0},	//(internal1_m1822_y0) y0
	{ 1743	,18	,1	, &internal1_m1807_DvUp0},	//(internal1_m1807_DvUp0) - есть команда на движение вперёд
	{ 1744	,18	,1	, &internal1_m1807_DvDw0},	//(internal1_m1807_DvDw0) - есть команда на движение назад
	{ 1745	,18	,1	, &internal1_m1807_FDvUp0},	//(internal1_m1807_FDvUp0) - есть команда на движение вперёд
	{ 1746	,18	,1	, &internal1_m1807_FDvDw0},	//(internal1_m1807_FDvDw0) - есть команда на движение назад
	{ 1747	,18	,1	, &internal1_m1807_BlDv0},	//(internal1_m1807_BlDv0) - была блокировка
	{ 1748	,18	,1	, &internal1_m1807_Pkv0},	//(internal1_m1807_Pkv0) Pkv - передний конечный выключатель
	{ 1749	,18	,1	, &internal1_m1807_Pkav0},	//(internal1_m1807_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1750	,18	,1	, &internal1_m1807_Zkv0},	//(internal1_m1807_Zkv0) Zkv - задний конечный выключатель
	{ 1751	,18	,1	, &internal1_m1807_Zkav0},	//(internal1_m1807_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1752	,8	,1	, &internal1_m1807_txNm},	//(internal1_m1807_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1753	,8	,1	, &internal1_m1807_txSm},	//(internal1_m1807_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1754	,8	,1	, &internal1_m1807_txHr},	//(internal1_m1807_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1755	,8	,1	, &internal1_m1807_txLd},	//(internal1_m1807_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1756	,18	,1	, &internal1_m1807_fef},	//(internal1_m1807_fef) fef
	{ 1757	,3	,1	, &internal1_m1826_xptr},	//(internal1_m1826_xptr) указатель текущей позиции в массиве координат
	{ 1758	,8	,20	, &internal1_m1826_x0},	//(internal1_m1826_x0) x0 - массив мгновенных значений координат
	{ 1759	,8	,20	, &internal1_m1826_tim0},	//(internal1_m1826_tim0) tim0 - массив значений времени цикла
	{ 1760	,8	,1	, &internal1_m1826_sumtim},	//(internal1_m1826_sumtim) sumtim - время в пути
	{ 1761	,8	,1	, &internal1_m1826_StSpeed},	//(internal1_m1826_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1762	,8	,1	, &internal1_m1826_Vz0},	//(internal1_m1826_Vz0) Vz0 - предыдущая заданная скорость
	{ 1763	,3	,1	, &internal1_m1826_flRazg},	//(internal1_m1826_flRazg) признак разгона/торможения
	{ 1764	,8	,1	, &internal1_m1826_DelSp},	//(internal1_m1826_DelSp) DelSp - время переключения скоростей
	{ 1765	,8	,1	, &internal1_m1826_z0},	//(internal1_m1826_z0) z0 - точка прекращения движения
	{ 1766	,8	,1	, &internal1_m1826_txZS},	//(internal1_m1826_txZS) txZS
	{ 1767	,8	,1	, &internal1_m1826_tx},	//(internal1_m1826_tx) tx
	{ 1768	,8	,1	, &internal1_m1826_txd},	//(internal1_m1826_txd) txd
	{ 1769	,8	,1	, &internal1_m1826_txMBl},	//(internal1_m1826_txMBl) tx
	{ 1770	,8	,1	, &internal1_m1826_txBl},	//(internal1_m1826_txBl) tx
	{ 1771	,8	,1	, &internal1_m1826_Speed0},	//(internal1_m1826_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1772	,8	,1	, &internal1_m1826_xz0},	//(internal1_m1826_xz0) xz0 - новое задание мм
	{ 1773	,8	,1	, &internal1_m1826_tz0},	//(internal1_m1826_tz0) tz0 - время защиты от нового задания сек
	{ 1774	,1	,1	, &internal1_m1826_Shift0},	//(internal1_m1826_Shift0) Shift0 - признак самохода
	{ 1775	,1	,1	, &internal1_m1826_ShCntlSp0},	//(internal1_m1826_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1776	,1	,1	, &internal1_m1826_ShiftControl},	//(internal1_m1826_ShiftControl) ShiftControl - признак самохода
	{ 1777	,8	,1	, &internal1_m1290_tx},	//(internal1_m1290_tx) tx - время накопленное сек
	{ 1778	,18	,1	, &internal1_m1290_y0},	//(internal1_m1290_y0) y0
	{ 1779	,8	,1	, &internal1_m1294_tx},	//(internal1_m1294_tx) tx - время накопленное сек
	{ 1780	,18	,1	, &internal1_m1294_y0},	//(internal1_m1294_y0) y0
	{ 1781	,1	,1	, &internal1_m702_q0},	//(internal1_m702_q0) q0 - внутренний параметр
	{ 1782	,1	,1	, &internal1_m667_q0},	//(internal1_m667_q0) q0 - внутренний параметр
	{ 1783	,18	,1	, &internal1_m1281_DvUp0},	//(internal1_m1281_DvUp0) - есть команда на движение вперёд
	{ 1784	,18	,1	, &internal1_m1281_DvDw0},	//(internal1_m1281_DvDw0) - есть команда на движение назад
	{ 1785	,18	,1	, &internal1_m1281_FDvUp0},	//(internal1_m1281_FDvUp0) - есть команда на движение вперёд
	{ 1786	,18	,1	, &internal1_m1281_FDvDw0},	//(internal1_m1281_FDvDw0) - есть команда на движение назад
	{ 1787	,18	,1	, &internal1_m1281_BlDv0},	//(internal1_m1281_BlDv0) - была блокировка
	{ 1788	,18	,1	, &internal1_m1281_Pkv0},	//(internal1_m1281_Pkv0) Pkv - передний конечный выключатель
	{ 1789	,18	,1	, &internal1_m1281_Pkav0},	//(internal1_m1281_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1790	,18	,1	, &internal1_m1281_Zkv0},	//(internal1_m1281_Zkv0) Zkv - задний конечный выключатель
	{ 1791	,18	,1	, &internal1_m1281_Zkav0},	//(internal1_m1281_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1792	,8	,1	, &internal1_m1281_txNm},	//(internal1_m1281_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1793	,8	,1	, &internal1_m1281_txSm},	//(internal1_m1281_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1794	,8	,1	, &internal1_m1281_txHr},	//(internal1_m1281_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1795	,8	,1	, &internal1_m1281_txLd},	//(internal1_m1281_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1796	,18	,1	, &internal1_m1281_fef},	//(internal1_m1281_fef) fef
	{ 1797	,3	,1	, &internal1_m1300_xptr},	//(internal1_m1300_xptr) указатель текущей позиции в массиве координат
	{ 1798	,8	,20	, &internal1_m1300_x0},	//(internal1_m1300_x0) x0 - массив мгновенных значений координат
	{ 1799	,8	,20	, &internal1_m1300_tim0},	//(internal1_m1300_tim0) tim0 - массив значений времени цикла
	{ 1800	,8	,1	, &internal1_m1300_sumtim},	//(internal1_m1300_sumtim) sumtim - время в пути
	{ 1801	,8	,1	, &internal1_m1300_StSpeed},	//(internal1_m1300_StSpeed) StSpeed - стартовая скорость - с которой начинается изменение скорости
	{ 1802	,8	,1	, &internal1_m1300_Vz0},	//(internal1_m1300_Vz0) Vz0 - предыдущая заданная скорость
	{ 1803	,3	,1	, &internal1_m1300_flRazg},	//(internal1_m1300_flRazg) признак разгона/торможения
	{ 1804	,8	,1	, &internal1_m1300_DelSp},	//(internal1_m1300_DelSp) DelSp - время переключения скоростей
	{ 1805	,8	,1	, &internal1_m1300_z0},	//(internal1_m1300_z0) z0 - точка прекращения движения
	{ 1806	,8	,1	, &internal1_m1300_txZS},	//(internal1_m1300_txZS) txZS
	{ 1807	,8	,1	, &internal1_m1300_tx},	//(internal1_m1300_tx) tx
	{ 1808	,8	,1	, &internal1_m1300_txd},	//(internal1_m1300_txd) txd
	{ 1809	,8	,1	, &internal1_m1300_txMBl},	//(internal1_m1300_txMBl) tx
	{ 1810	,8	,1	, &internal1_m1300_txBl},	//(internal1_m1300_txBl) tx
	{ 1811	,8	,1	, &internal1_m1300_Speed0},	//(internal1_m1300_Speed0) Speed0 - предыдущее значение скорости перемещения
	{ 1812	,8	,1	, &internal1_m1300_xz0},	//(internal1_m1300_xz0) xz0 - новое задание мм
	{ 1813	,8	,1	, &internal1_m1300_tz0},	//(internal1_m1300_tz0) tz0 - время защиты от нового задания сек
	{ 1814	,1	,1	, &internal1_m1300_Shift0},	//(internal1_m1300_Shift0) Shift0 - признак самохода
	{ 1815	,1	,1	, &internal1_m1300_ShCntlSp0},	//(internal1_m1300_ShCntlSp0) ShCntlSp0 - признак выдержки времени после достижения 0 скорости
	{ 1816	,1	,1	, &internal1_m1300_ShiftControl},	//(internal1_m1300_ShiftControl) ShiftControl - признак самохода
	{ 1817	,1	,1	, &internal1_m830_x0},	//(internal1_m830_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1818	,1	,1	, &internal1_m799_x0},	//(internal1_m799_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1819	,1	,1	, &internal1_m741_x0},	//(internal1_m741_x0) x0 - значение входного параметра на предыдущем шаге
	{ 1820	,1	,1	, &internal1_m855_q0},	//(internal1_m855_q0) q0 - внутренний параметр
	{ 1821	,1	,1	, &internal1_m850_q0},	//(internal1_m850_q0) q0 - внутренний параметр
	{ 1822	,1	,1	, &internal1_m818_q0},	//(internal1_m818_q0) q0 - внутренний параметр
	{ 1823	,1	,1	, &internal1_m822_q0},	//(internal1_m822_q0) q0 - внутренний параметр
	{ 1824	,1	,1	, &internal1_m831_q0},	//(internal1_m831_q0) q0 - внутренний параметр
	{ 1825	,1	,1	, &internal1_m843_q0},	//(internal1_m843_q0) q0 - внутренний параметр
	{ 1826	,1	,1	, &internal1_m820_q0},	//(internal1_m820_q0) q0 - внутренний параметр
	{ 1827	,18	,1	, &internal1_m1343_DvUp0},	//(internal1_m1343_DvUp0) - есть команда на движение вперёд
	{ 1828	,18	,1	, &internal1_m1343_DvDw0},	//(internal1_m1343_DvDw0) - есть команда на движение назад
	{ 1829	,18	,1	, &internal1_m1343_FDvUp0},	//(internal1_m1343_FDvUp0) - есть команда на движение вперёд
	{ 1830	,18	,1	, &internal1_m1343_FDvDw0},	//(internal1_m1343_FDvDw0) - есть команда на движение назад
	{ 1831	,18	,1	, &internal1_m1343_BlDv0},	//(internal1_m1343_BlDv0) - была блокировка
	{ 1832	,18	,1	, &internal1_m1343_Pkv0},	//(internal1_m1343_Pkv0) Pkv - передний конечный выключатель
	{ 1833	,18	,1	, &internal1_m1343_Pkav0},	//(internal1_m1343_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1834	,18	,1	, &internal1_m1343_Zkv0},	//(internal1_m1343_Zkv0) Zkv - задний конечный выключатель
	{ 1835	,18	,1	, &internal1_m1343_Zkav0},	//(internal1_m1343_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1836	,8	,1	, &internal1_m1343_txNm},	//(internal1_m1343_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1837	,8	,1	, &internal1_m1343_txSm},	//(internal1_m1343_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1838	,8	,1	, &internal1_m1343_txHr},	//(internal1_m1343_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1839	,8	,1	, &internal1_m1343_txLd},	//(internal1_m1343_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1840	,18	,1	, &internal1_m1343_fef},	//(internal1_m1343_fef) fef
	{ 1841	,18	,1	, &internal1_m1333_DvUp0},	//(internal1_m1333_DvUp0) - есть команда на движение вперёд
	{ 1842	,18	,1	, &internal1_m1333_DvDw0},	//(internal1_m1333_DvDw0) - есть команда на движение назад
	{ 1843	,18	,1	, &internal1_m1333_FDvUp0},	//(internal1_m1333_FDvUp0) - есть команда на движение вперёд
	{ 1844	,18	,1	, &internal1_m1333_FDvDw0},	//(internal1_m1333_FDvDw0) - есть команда на движение назад
	{ 1845	,18	,1	, &internal1_m1333_BlDv0},	//(internal1_m1333_BlDv0) - была блокировка
	{ 1846	,18	,1	, &internal1_m1333_Pkv0},	//(internal1_m1333_Pkv0) Pkv - передний конечный выключатель
	{ 1847	,18	,1	, &internal1_m1333_Pkav0},	//(internal1_m1333_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1848	,18	,1	, &internal1_m1333_Zkv0},	//(internal1_m1333_Zkv0) Zkv - задний конечный выключатель
	{ 1849	,18	,1	, &internal1_m1333_Zkav0},	//(internal1_m1333_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1850	,8	,1	, &internal1_m1333_txNm},	//(internal1_m1333_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1851	,8	,1	, &internal1_m1333_txSm},	//(internal1_m1333_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1852	,8	,1	, &internal1_m1333_txHr},	//(internal1_m1333_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1853	,8	,1	, &internal1_m1333_txLd},	//(internal1_m1333_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1854	,18	,1	, &internal1_m1333_fef},	//(internal1_m1333_fef) fef
	{ 1855	,18	,1	, &internal1_m879_DvUp0},	//(internal1_m879_DvUp0) - есть команда на движение вперёд
	{ 1856	,18	,1	, &internal1_m879_DvDw0},	//(internal1_m879_DvDw0) - есть команда на движение назад
	{ 1857	,18	,1	, &internal1_m879_FDvUp0},	//(internal1_m879_FDvUp0) - есть команда на движение вперёд
	{ 1858	,18	,1	, &internal1_m879_FDvDw0},	//(internal1_m879_FDvDw0) - есть команда на движение назад
	{ 1859	,18	,1	, &internal1_m879_BlDv0},	//(internal1_m879_BlDv0) - была блокировка
	{ 1860	,18	,1	, &internal1_m879_Pkv0},	//(internal1_m879_Pkv0) Pkv - передний конечный выключатель
	{ 1861	,18	,1	, &internal1_m879_Pkav0},	//(internal1_m879_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1862	,18	,1	, &internal1_m879_Zkv0},	//(internal1_m879_Zkv0) Zkv - задний конечный выключатель
	{ 1863	,18	,1	, &internal1_m879_Zkav0},	//(internal1_m879_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1864	,8	,1	, &internal1_m879_txNm},	//(internal1_m879_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1865	,8	,1	, &internal1_m879_txSm},	//(internal1_m879_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1866	,8	,1	, &internal1_m879_txHr},	//(internal1_m879_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1867	,8	,1	, &internal1_m879_txLd},	//(internal1_m879_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1868	,18	,1	, &internal1_m879_fef},	//(internal1_m879_fef) fef
	{ 1869	,18	,1	, &internal1_m875_DvUp0},	//(internal1_m875_DvUp0) - есть команда на движение вперёд
	{ 1870	,18	,1	, &internal1_m875_DvDw0},	//(internal1_m875_DvDw0) - есть команда на движение назад
	{ 1871	,18	,1	, &internal1_m875_FDvUp0},	//(internal1_m875_FDvUp0) - есть команда на движение вперёд
	{ 1872	,18	,1	, &internal1_m875_FDvDw0},	//(internal1_m875_FDvDw0) - есть команда на движение назад
	{ 1873	,18	,1	, &internal1_m875_BlDv0},	//(internal1_m875_BlDv0) - была блокировка
	{ 1874	,18	,1	, &internal1_m875_Pkv0},	//(internal1_m875_Pkv0) Pkv - передний конечный выключатель
	{ 1875	,18	,1	, &internal1_m875_Pkav0},	//(internal1_m875_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1876	,18	,1	, &internal1_m875_Zkv0},	//(internal1_m875_Zkv0) Zkv - задний конечный выключатель
	{ 1877	,18	,1	, &internal1_m875_Zkav0},	//(internal1_m875_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1878	,8	,1	, &internal1_m875_txNm},	//(internal1_m875_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1879	,8	,1	, &internal1_m875_txSm},	//(internal1_m875_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1880	,8	,1	, &internal1_m875_txHr},	//(internal1_m875_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1881	,8	,1	, &internal1_m875_txLd},	//(internal1_m875_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1882	,18	,1	, &internal1_m875_fef},	//(internal1_m875_fef) fef
	{ 1883	,18	,1	, &internal1_m390_DvUp0},	//(internal1_m390_DvUp0) - есть команда на движение вперёд
	{ 1884	,18	,1	, &internal1_m390_DvDw0},	//(internal1_m390_DvDw0) - есть команда на движение назад
	{ 1885	,18	,1	, &internal1_m390_FDvUp0},	//(internal1_m390_FDvUp0) - есть команда на движение вперёд
	{ 1886	,18	,1	, &internal1_m390_FDvDw0},	//(internal1_m390_FDvDw0) - есть команда на движение назад
	{ 1887	,18	,1	, &internal1_m390_BlDv0},	//(internal1_m390_BlDv0) - была блокировка
	{ 1888	,18	,1	, &internal1_m390_Pkv0},	//(internal1_m390_Pkv0) Pkv - передний конечный выключатель
	{ 1889	,18	,1	, &internal1_m390_Pkav0},	//(internal1_m390_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1890	,18	,1	, &internal1_m390_Zkv0},	//(internal1_m390_Zkv0) Zkv - задний конечный выключатель
	{ 1891	,18	,1	, &internal1_m390_Zkav0},	//(internal1_m390_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1892	,8	,1	, &internal1_m390_txNm},	//(internal1_m390_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1893	,8	,1	, &internal1_m390_txSm},	//(internal1_m390_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1894	,8	,1	, &internal1_m390_txHr},	//(internal1_m390_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1895	,8	,1	, &internal1_m390_txLd},	//(internal1_m390_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1896	,18	,1	, &internal1_m390_fef},	//(internal1_m390_fef) fef
	{ 1897	,18	,1	, &internal1_m427_DvUp0},	//(internal1_m427_DvUp0) - есть команда на движение вперёд
	{ 1898	,18	,1	, &internal1_m427_DvDw0},	//(internal1_m427_DvDw0) - есть команда на движение назад
	{ 1899	,18	,1	, &internal1_m427_FDvUp0},	//(internal1_m427_FDvUp0) - есть команда на движение вперёд
	{ 1900	,18	,1	, &internal1_m427_FDvDw0},	//(internal1_m427_FDvDw0) - есть команда на движение назад
	{ 1901	,18	,1	, &internal1_m427_BlDv0},	//(internal1_m427_BlDv0) - была блокировка
	{ 1902	,18	,1	, &internal1_m427_Pkv0},	//(internal1_m427_Pkv0) Pkv - передний конечный выключатель
	{ 1903	,18	,1	, &internal1_m427_Pkav0},	//(internal1_m427_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1904	,18	,1	, &internal1_m427_Zkv0},	//(internal1_m427_Zkv0) Zkv - задний конечный выключатель
	{ 1905	,18	,1	, &internal1_m427_Zkav0},	//(internal1_m427_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1906	,8	,1	, &internal1_m427_txNm},	//(internal1_m427_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1907	,8	,1	, &internal1_m427_txSm},	//(internal1_m427_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1908	,8	,1	, &internal1_m427_txHr},	//(internal1_m427_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1909	,8	,1	, &internal1_m427_txLd},	//(internal1_m427_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1910	,18	,1	, &internal1_m427_fef},	//(internal1_m427_fef) fef
	{ 1911	,18	,1	, &internal1_m421_DvUp0},	//(internal1_m421_DvUp0) - есть команда на движение вперёд
	{ 1912	,18	,1	, &internal1_m421_DvDw0},	//(internal1_m421_DvDw0) - есть команда на движение назад
	{ 1913	,18	,1	, &internal1_m421_FDvUp0},	//(internal1_m421_FDvUp0) - есть команда на движение вперёд
	{ 1914	,18	,1	, &internal1_m421_FDvDw0},	//(internal1_m421_FDvDw0) - есть команда на движение назад
	{ 1915	,18	,1	, &internal1_m421_BlDv0},	//(internal1_m421_BlDv0) - была блокировка
	{ 1916	,18	,1	, &internal1_m421_Pkv0},	//(internal1_m421_Pkv0) Pkv - передний конечный выключатель
	{ 1917	,18	,1	, &internal1_m421_Pkav0},	//(internal1_m421_Pkav0) Pkav - передний конечный аварийный выключатель
	{ 1918	,18	,1	, &internal1_m421_Zkv0},	//(internal1_m421_Zkv0) Zkv - задний конечный выключатель
	{ 1919	,18	,1	, &internal1_m421_Zkav0},	//(internal1_m421_Zkav0) Zkav - задний конечный аварийный выключатель
	{ 1920	,8	,1	, &internal1_m421_txNm},	//(internal1_m421_txNm) txNm - счётчик задержки сигнализации недвижения
	{ 1921	,8	,1	, &internal1_m421_txSm},	//(internal1_m421_txSm) txSm - счётчик задержки сигнализации самохода
	{ 1922	,8	,1	, &internal1_m421_txHr},	//(internal1_m421_txHr) txHr - счётчик задержки сигнализации ошибки направления перемещения
	{ 1923	,8	,1	, &internal1_m421_txLd},	//(internal1_m421_txLd) txLd - счётчик задержки сигнализации превышения времени перемещения
	{ 1924	,18	,1	, &internal1_m421_fef},	//(internal1_m421_fef) fef
	{ 1925	,1	,1	, &internal1_m827_q0},	//(internal1_m827_q0) q0 - внутренний параметр
	{ 1926	,1	,1	, &internal1_m824_q0},	//(internal1_m824_q0) q0 - внутренний параметр
	{-1,0,NULL},
};
static char NameSaveFile[]="du.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{742,"fEM_A1UC03RDU\0"}, 
{743,"dEM_A1UC05UDU\0"}, 
{744,"dEM_A1UC06UDU\0"}, 
{745,"dEM_A2UC06UDU\0"}, 
{746,"dEM_A2UC05UDU\0"}, 
{747,"fEM_A2UC03RDU\0"}, 
{748,"dEM_A3UC06UDU\0"}, 
{749,"dEM_A3UC05UDU\0"}, 
{750,"fEM_A3UC03RDU\0"}, 
{751,"dEM_A8UC06UDU\0"}, 
{752,"fEM_A8UC03RDU\0"}, 
{753,"dEM_A8UC05UDU\0"}, 
{754,"fEM_R0UV81RDU\0"}, 
{755,"fEM_R0UV82RDU\0"}, 
{756,"fEM_R0UV83RDU\0"}, 
{757,"fEM_R0UV84RDU\0"}, 
{758,"fEM_R0UV86RDU\0"}, 
{759,"fEM_R0UV85RDU\0"}, 
{760,"fEM_R0UV87RDU\0"}, 
{761,"fEM_A3UP03RDU\0"}, 
{762,"fEM_A3UP04RDU\0"}, 
{763,"fEM_A3UP43RDU\0"}, 
{764,"fEM_A3UP44RDU\0"}, 
{765,"fEM_A3UP53RDU\0"}, 
{766,"fEM_A3UP85RDU\0"}, 
{767,"fEM_A3UP88RDU\0"}, 
{768,"fEM_A3UP86RDU\0"}, 
{769,"fEM_B8UV01RDU\0"}, 
{770,"fEM_B8UV02RDU\0"}, 
{771,"fEM_B8UV03RDU\0"}, 
{772,"fEM_B8UL04RDU\0"}, 
{773,"iEM_A2UV03CDU\0"}, 
{774,"fEM_A2UV01RDU\0"}, 
{775,"fEM_A2UV02RDU\0"}, 
{776,"fEM_A1UV01RDU\0"}, 
{777,"fEM_A1UV02RDU\0"}, 
{778,"fEM_A1UC06RDU\0"}, 
{779,"fEM_A1UC05RDU\0"}, 
{780,"fEM_A1UL04RDU\0"}, 
{781,"fEM_A3UV01RDU\0"}, 
{782,"fEM_A3UV02RDU\0"}, 
{783,"fEM_A3UC06RDU\0"}, 
{784,"fEM_A3UC05RDU\0"}, 
{785,"fEM_A3UL04RDU\0"}, 
{786,"fEM_A3UP54RDU\0"}, 
{787,"fEM_A3UP87RDU\0"}, 
{788,"fEM_R0UL05RDU\0"}, 
{789,"fEM_R0UL20RDU\0"}, 
{790,"fEM_B8UV04RDU\0"}, 
{791,"fEM_B8UC06RDU\0"}, 
{792,"fEM_B8UC05RDU\0"}, 
{793,"fEM_A2UL05RDU\0"}, 
{794,"fEM_A2UL03RDU\0"}, 
{795,"fEM_A2UC06RDU\0"}, 
{796,"fEM_A2UC05RDU\0"}, 
{797,"fEM_A2UL04RDU\0"}, 
{798,"fEM_A1UL03RDU\0"}, 
{799,"fEM_A1UL05RDU\0"}, 
{800,"fEM_A3UL03RDU\0"}, 
{801,"fEM_A3UL05RDU\0"}, 
{802,"fEM_A1UC08RDU\0"}, 
{803,"fEM_A3UC08RDU\0"}, 
{804,"fEM_A1UC07RDU\0"}, 
{805,"fEM_A1UL01RDU\0"}, 
{806,"fEM_A3UC07RDU\0"}, 
{807,"fEM_A3UL01RDU\0"}, 
{808,"fEM_A2UC08RDU\0"}, 
{809,"fEM_A2UC07RDU\0"}, 
{810,"fEM_A2UL01RDU\0"}, 
{811,"fEM_B8UC01RDU\0"}, 
{812,"fEM_B8UL07RDU\0"}, 
{813,"fEM_B8UC02RDU\0"}, 
{814,"fEM_B8UL01RDU\0"}, 
{815,"fEM_B8UL05RDU\0"}, 
{816,"fEM_B8UL03RDU\0"}, 
{817,"fEM_B8UL06RDU\0"}, 
{818,"fEM_A9UZ03RDU\0"}, 
{819,"fEM_A9UZ04RDU\0"}, 
{820,"fEM_A9UZ05RDU\0"}, 
{821,"fEM_R4UZ04RDU\0"}, 
{822,"fEM_R4UZ03RDU\0"}, 
{823,"fEM_R4UZ05RDU\0"}, 
{824,"fEM_A5UZ03RDU\0"}, 
{825,"fEM_A5UZ04RDU\0"}, 
{826,"fEM_A5UZ05RDU\0"}, 
{827,"fEM_A4UZ03RDU\0"}, 
{828,"fEM_A4UZ04RDU\0"}, 
{829,"fEM_A4UZ05RDU\0"}, 
{830,"fEM_A6UZ03RDU\0"}, 
{831,"fEM_A6UZ04RDU\0"}, 
{832,"fEM_A6UZ05RDU\0"}, 
{833,"fEM_R1UZ03RDU\0"}, 
{834,"fEM_R1UZ04RDU\0"}, 
{835,"fEM_R1UZ05RDU\0"}, 
{836,"fEM_R0UL04RDU\0"}, 
{837,"fEM_R0UL06RDU\0"}, 
{838,"fEM_R0UL03RDU\0"}, 
{839,"fEM_R0UL17RDU\0"}, 
{840,"fEM_R0UL19RDU\0"}, 
{841,"fEM_R0UL07RDU\0"}, 
{842,"fEM_R0UL18RDU\0"}, 
{843,"fEM_R0UL16RDU\0"}, 
{844,"fEM_R0UL02RDU\0"}, 
{845,"fEM_R0UN08RDU\0"}, 
{846,"fEM_R0UN07RDU\0"}, 
{847,"fEM_R0UN06RDU\0"}, 
{848,"fEM_R0UN05RDU\0"}, 
{849,"fEM_R0UN04RDU\0"}, 
{850,"fEM_R0UN03RDU\0"}, 
{851,"fEM_R0UN02RDU\0"}, 
{852,"fEM_R0UN01RDU\0"}, 
{853,"fEM_A2UC82RDU\0"}, 
{854,"fEM_A2UC83RDU\0"}, 
{855,"fEM_A1UC83RDU\0"}, 
{856,"fEM_A2UC81RDU\0"}, 
{857,"fEM_A1UC81RDU\0"}, 
{858,"fEM_A1UC82RDU\0"}, 
{859,"fEM_A2UL83RDU\0"}, 
{860,"fEM_A3UC81RDU\0"}, 
{861,"fEM_A3UC82RDU\0"}, 
{862,"fEM_R0UN80RDU\0"}, 
{863,"iEM_A2UV01IDU\0"}, 
{864,"iEM_A2UV02IDU\0"}, 
{865,"iEM_A1UV01IDU\0"}, 
{866,"iEM_A1UV02IDU\0"}, 
{867,"iEM_A1UV03IDU\0"}, 
{868,"iEM_A3UV01IDU\0"}, 
{869,"iEM_A3UV02IDU\0"}, 
{870,"lEM_R0MD01LC1\0"}, 
{871,"fEM_A3UC09RDU\0"}, 
{872,"fEM_A2UC02RDU\0"}, 
{873,"fEM_A1UC02RDU\0"}, 
{874,"fEM_A3UC02RDU\0"}, 
{875,"fEM_R0UL21RDU\0"}, 
{876,"fEM_R0UN09RDU\0"}, 
{877,"fEM_R0UN11RDU\0"}, 
{878,"fEM_R0UN12RDU\0"}, 
{879,"fEM_R0UN13RDU\0"}, 
{880,"fEM_R0UN14RDU\0"}, 
{881,"fEM_R0UN16RDU\0"}, 
{882,"fEM_R0UN17RDU\0"}, 
{883,"fEM_R0UN18RDU\0"}, 
{884,"fEM_R0UN19RDU\0"}, 
{885,"fEM_R0UN70LDU\0"}, 
{886,"fEM_R0UN71LDU\0"}, 
{887,"fEM_R0UN72LDU\0"}, 
{888,"fEM_R0UN73LDU\0"}, 
{889,"fEM_R0UN74LDU\0"}, 
{890,"fEM_R0UN75LDU\0"}, 
{891,"fEM_R0UN80LDU\0"}, 
{892,"fEM_R0UN81LDU\0"}, 
{893,"fEM_R0UN82LDU\0"}, 
{894,"fEM_R0UN83LDU\0"}, 
{895,"fEM_R0UN84LDU\0"}, 
{896,"fEM_R0UN85LDU\0"}, 
{897,"fEM_R0UT20RDU\0"}, 
{898,"fEM_R0UN25RDU\0"}, 
{899,"fEM_R0UN15RDU\0"}, 
{900,"fEM_R0UN26RDU\0"}, 
{901,"fEM_R0UN27RDU\0"}, 
{902,"fEM_R0UN24RDU\0"}, 
{903,"fEM_R0UL25RDU\0"}, 
{904,"fEM_R0UL01RSS\0"}, 
{905,"fEM_R0UL02RSS\0"}, 
{906,"fEM_R0UN03RSS\0"}, 
{907,"fEM_R7UI76RDU\0"}, 
{908,"fEM_R0UL00RDU\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_DU[]={  // 
	{&A2MD12LP1,1,0},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ1
	{&A2MD11LP1,1,1},	//( - , DU) Кнопка ПУСК РБ1
	{&B2MD12LP1,1,2},	//( - , DU) Переключатель РАЗРЕШИТЬ РБ2
	{&B2MD11LP1,1,3},	//( - , DU) Кнопка ПУСК РБ2
	{&B1MD12LP1,1,4},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ2
	{&B1MD11LP1,1,5},	//( - , DU) Кнопка ПУСК ББ2
	{&R0MW17LP1,1,6},	//( - , DU) Переключатель АВТ/Р
	{&A1MD11LP1,1,7},	//( - , DU) Кнопка ПУСК ББ1
	{&A1MD12LP1,1,8},	//( - , DU) Переключатель РАЗРЕШИТЬ ББ1
	{&R0MD33LP1,1,9},	//( - , DU) Переключатель РАЗРЕШИТЬ МДЗ
	{&A3MD11LP1,1,10},	//( - , DU) Кнопка ПУСК ИС1
	{&A3MD12LP1,1,11},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС1
	{&R0MD34LP1,1,12},	//( - , DU) Кнопка КВИТИРОВАТЬ
	{&B3MD12LP1,1,13},	//( - , DU) Переключатель РАЗРЕШИТЬ ИС2
	{&B3MD11LP1,1,14},	//( - , DU) Кнопка ПУСК ИС2
	{&R0MD11LP2,1,15},	//( - , DU) Кнопка Пуск проверки схем сброса
	{&C1MD31LP2,1,16},	//( - , DU) Кнопка СБРОС ББ
	{&C1MD31LP1,1,17},	//( - , DU) Кнопка СБРОС ББ
	{&A3MC01LC2,1,18},	//( - , DU) Настроить энкодер ИС1
	{&A3MC01LC1,1,19},	//( - , DU) Настроить энкодер ИС1
	{&B3MC01LC2,1,20},	//( - , DU) Настроить энкодер ИС2
	{&B3MC01LC1,1,21},	//( - , DU) Настроить энкодер ИС2
	{&A2MC01LC2,1,22},	//( - , DU) Настроить энкодер РБ1
	{&A2MC01LC1,1,23},	//( - , DU) Настроить энкодер РБ1
	{&B2MC01LC2,1,24},	//( - , DU) Настроить энкодер РБ2
	{&B2MC01LC1,1,25},	//( - , DU) Настроить энкодер РБ2
	{&A1MC01LC2,1,26},	//( - , DU) Настроить энкодер ББ1
	{&A1MC01LC1,1,27},	//( - , DU) Настроить энкодер ББ1
	{&B1MC01LC2,1,28},	//( - , DU) Настроить энкодер ББ2
	{&B1MC01LC1,1,29},	//( - , DU) Настроить энкодер ББ2
	{&B8MC01LC1,1,30},	//( - , DU) Настроить энкодер АЗ2
	{&B8MC01LC2,1,31},	//( - , DU) Настроить энкодер АЗ2
	{&A8MC01LC1,1,32},	//( - , DU) Настроить энкодер ДС2
	{&A8MC01LC2,1,33},	//( - , DU) Настроить энкодер ДС2
	{&C2MD31LP1,1,34},	//( - , DU) Кнопка СБРОС РБ
	{&R0MD11LP1,1,35},	//( - , DU) Кнопка ПУСК
	{&R4MD21LP2,1,36},	//( - , DU) Кнопка НАЗАД  (тележки)
	{&R4MD31LP2,1,37},	//( - , DU) Кнопка СТОП  (тележки)
	{&R4MD11LP2,1,38},	//( - , DU) Кнопка ВПЕРЁД  (тележки)
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
	{&R0IS02LDU,1,0},	//( - K30VDSR, DU) Разрешение ввода от имитатора
	{&R0IS01LDU,1,1},	//( - K29VDSR, DU) Признак работы с имитатором
	{&A3IS11LDU,1,2},	//( - K01VDSR, DU) Приход на ВУ ИС1
	{&B3IS11LDU,1,3},	//( - K03VDSR, DU) Приход на ВУ ИС2
	{&R0VS18LDU,1,4},	//( - , DU) Индикация  Проверка схем сброса
	{&B3VX01LDU,1,5},	//( - , DU) Индикация Выстрел ИС2
	{&A3VX01LDU,1,6},	//( - , DU) Индикация Выстрел ИС1
	{&B2VS32LDU,1,7},	//( - , DU) Индикация  СБРОС РБ2
	{&A2VS32LDU,1,8},	//( - , DU) Индикация  СБРОС РБ1
	{&R0VS17LDU,1,9},	//( - , DU) Индикация выбора АВТОМАТ
	{&R0VX09LDU,1,10},	//( - , DU) Индикация регулятор мощности включен/отключен
	{&R0VW23LDU,1,11},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ2 или АЗ1+АЗ2
	{&R0VW13LDU,1,12},	//( - , DU, MDuBz1, MDuBz2) Индикация выбора АЗ1 или АЗ1+АЗ2
	{&B2IS11LDU,1,13},	//( - K11VDSR, DU) Приход на ВУ РБ2-СТР
	{&A2IS11LDU,1,14},	//( - K11VDSR, DU) Приход на ВУ РБ1-СТР
	{&B3IS22LDU,1,15},	//( - K04VDSR, DU) Приход на НУП ИС2
	{&A3IS22LDU,1,16},	//( - K02VDSR, DU) Приход на НУП ИС1
	{&R3IS11LDU,1,17},	//( - K17VDSR, DU) Приход на ВУ гомогенных дверей
	{&B4IS10LDU,1,18},	//( - K04VDSR, DU) Клапан ПОДЪЕМ НИ2 открыт (обесточен)
	{&B3IS35LDU,1,19},	//( - K01VDSR, DU) Клапан ВПИС2 открыт (обесточен)
	{&B3IS33LDU,1,20},	//( - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС2 открыт (обесточен)
	{&B3IS31LDU,1,21},	//( - K05VDSR, DU) Клапан СПУСК ИС2 открыт (обесточен)
	{&B2IS33LDU,1,22},	//( - K03VDSR, DU) Клапан ПОДЪЕМ РБ2 открыт (обесточен)
	{&A3VZ15LZ2,1,23},	//( - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{&A3VZ15LZ1,1,24},	//( - K19VDSR, DU) Имитация срабатывания АЗ от НУП ИС
	{&A3VZ13LZ1,1,25},	//( - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{&A3VZ13LZ2,1,26},	//( - K18VDSR, DU) Имитация срабатывания АЗ от ВУ ИС
	{&R0AD14LZ2,1,27},	//( - K20VDSR, DU) Имитация срабатывания АЗ от  II УР
	{&R0AD14LZ1,1,28},	//( - K20VDSR, DU) Имитация срабатывания АЗ от II УР
	{&A1AB19LDU,1,29},	//( - , DU) Блокировка автоматического подъёма ББ1 -превышение нейтронного потока
	{&A1VN71LZ2,1,30},	//( - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{&A1VN71LZ1,1,31},	//( - K21VDSR, DU) Блокировка автоматического подъёма ББ
	{&A4IS10LDU,1,32},	//( - K04VDSR, DU) Клапан Подъём НИ1 открыт (обесточен)
	{&R0VP73LDU,1,33},	//( - , DU) ПС давления для РУ
	{&B2VS11LDU,1,34},	//( - , DU) Движение РБ2 в сторону ВУ
	{&B2VS21LDU,1,35},	//( - , DU) Движение РБ2 в сторону НУ
	{&A7AS31LDU,1,36},	//( - K06VDSR, DU) Клапан Обдув АЗ1 открыт (обесточен)
	{&B7AS31LDU,1,37},	//( - K06VDSR, DU) Клапан Обдув АЗ2 открыт (обесточен)
	{&A7AZ03LDU,1,38},	//( - , DU) Несанкционированное включение обдува АЗ1
	{&B7AZ03LDU,1,39},	//( - , DU) Несанкционированное включение обдува АЗ2
	{&R0VZ71LDU,1,40},	//( - , DU) Обобщенный сигнал АЗ
	{&A2IS33LDU,1,41},	//( - K03VDSR, DU) Клапан ПОДЪЕМ РБ1 открыт (обесточен)
	{&A3IS31LDU,1,42},	//( - K05VDSR, DU) Клапан СПУСК ИС1 открыт (обесточен)
	{&A3IS33LDU,1,43},	//( - K02VDSR, DU) Клапан ВЫСТРЕЛ ИС1 открыт (обесточен)
	{&A3IS35LDU,1,44},	//( - K01VDSR, DU) Клапан ВПИС1 открыт (обесточен)
	{&R0AB04LDU,1,45},	//( - , DU) Нарушение времени срабатывания верхней АС II УР
	{&R0VX01LDU,1,46},	//( - , DU) ДО ИМПУЛЬСА
	{&B1AD31LDU,1,47},	//( - K06FDSR, DU) Клапан СБРОС ББ2 открыть (обесточить)
	{&A1AD31LDU,1,48},	//( - K02FDSR, DU) Клапан СБРОС ББ1 открыть (обесточить)
	{&B2AD31LDU,1,49},	//( - K08FDSR, DU) Клапан Сброс РБ2 открыть (обесточить)
	{&A2AD31LDU,1,50},	//( - K04FDSR, DU) Клапан СБРОС РБ1 открыть (обесточить)
	{&B3AB20LDU,1,51},	//( - , DU) Блокировка выстрела ИС2 - клапан ВПИС2 закрыт
	{&B3AB18LDU,1,52},	//( - , DU) Блокировка подъёма ИС2- РБ-СТР ниже 80 мм
	{&B3AB04LDU,1,53},	//( - , DU) Блокировка движения ИС2 нет перемещения  ИС1
	{&B3AB02LDU,1,54},	//( - , DU) Блокировка движения ИС2: превышение заданной скорости
	{&B3AB01LDU,1,55},	//( - , DU) Блокировка движения ИС2: скорость перемещения менее заданной
	{&B3VS22LDU,1,56},	//( - , DU) Движение ИС2 в сторону НУ
	{&B3AZ03LDU,1,57},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС2
	{&B3AB07LDU,1,58},	//( - , DU) Блокировка подъёма ИС2 Гомогенные двери не закрыты
	{&B3AB08LDU,1,59},	//( - , DU) Блокировка подъёма ИС2 - реактор не на рабочем месте
	{&B3AB05LDU,1,60},	//( - , DU) Блокировка подъёма ИС2 -нет сигнала готовности СУЗ
	{&B3AB06LDU,1,61},	//( - , DU) Блокировка подъёма ИС2 - НИ не в положении ВУ,режим работы не проверочный
	{&B3AB09LDU,1,62},	//( - , DU) Блокировка подъёма ИС2- АНИ не установлен
	{&B3AB10LDU,1,63},	//( - , DU) Блокировка подъёма ИС2- есть сигнал общего сброса
	{&B3AB11LDU,1,64},	//( - , DU) Блокировка подъёма ИС2- АЗ2 или ДС2 не на заданной координате
	{&B3AB12LDU,1,65},	//( - , DU) Блокировка подъёма ИС2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{&B3AB14LDU,1,66},	//( - , DU) Блокировка подъёма ИС2- в режимах Калибровка, Статический мощность больше заданной
	{&B3AB16LDU,1,67},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 200 с
	{&B3AB17LDU,1,68},	//( - , DU) Блокировка перемещения ИС2: выполняется программа 20 мин
	{&R0AB01LDU,1,69},	//( - , DU) Режим проверки разрешён
	{&B9AB02LDU,1,70},	//( - , DU) Блокировка движения НИ ДС2 - Нет перемещения
	{&B9AB01LDU,1,71},	//( - , DU) Блокировка движения НИ ДС2 - Превышение времени движения
	{&B9AZ03LDU,1,72},	//( - , DU) Несанкционированное перемещение НИ ДС2
	{&A9AB02LDU,1,73},	//( - , DU) Блокировка НИ ДС1 - Нет перемещения
	{&A9AB01LDU,1,74},	//( - , DU) Блокировка движения НИ ДС1 - Превышение времени движения
	{&A9AZ03LDU,1,75},	//( - , DU) Несанкционированное перемещение НИ ДС1
	{&B9IS11LDU,1,76},	//( - K25VDSR, DU) Приход на ВУ НИ ДС2
	{&A9IS11LDU,1,77},	//( - K23VDSR, DU) Приход на ВУ НИ ДС1
	{&B4VS22LDU,1,78},	//( - , DU) Движение НИ2 в сторону НУ
	{&R0AB06LDU,1,79},	//( - , DU) Нарушение времени задержки от ВУ РБ
	{&R0AB02LDU,1,80},	//( - , DU) Нарушение времени задержки ИНИ
	{&R0VX03LDU,1,81},	//( - , DU) Готовность 2 мин
	{&A4VS12LDU,1,82},	//( - , DU) Движение НИ1 в сторону ВУ
	{&A4VS22LDU,1,83},	//( - , DU) Движение НИ1 в сторону НУ
	{&B4VS12LDU,1,84},	//( - , DU) Движение НИ2 в сторону ВУ
	{&A1IS11LDU,1,85},	//( - K08VDSR, DU) Приход на ВУ ББ1
	{&B3EE03LDU,1,86},	//( - , DU) ВПИС ИС2
	{&B3AB15LDU,1,87},	//( - , DU) Блокировка заполнения ресивера ИС2: работает регулятор мощности
	{&R5IS21LDU,1,88},	//( - K26VDSR, DU) Приход на НУ ворот отстойной зоны
	{&R5VS22LDU,1,89},	//( - , DU) Движение ворот отстойной зоны к закрыты
	{&R5VS12LDU,1,90},	//( - , DU) Движение ворот отстойной зоны к открыты
	{&R3VS22LDU,1,91},	//( - , DU) Движение гомогенных дверей к закрыты
	{&R3VS12LDU,1,92},	//( - , DU) Движение гомогенных дверей к открыты
	{&A3AB13LDU,1,93},	//( - , DU) Блокировка подъёма ИС1- давление в пневмосистеме ИС1 ниже ПС
	{&B3AB13LDU,1,94},	//( - , DU) Блокировка подъёма ИС2- давление в пневмосистеме ИС ниже значения заданного предупредительной уставкой
	{&TestDiagnDU,1,95},	//( - , DU) Неисправность от
	{&B1IS11LDU,1,96},	//( - K08VDSR, DU) Приход на ВУ ББ2
	{&psrb,1,97},	//( - , DU) ???
	{&psrb2,1,98},	//( - , DU) пневматика по программам
	{&psrb1,1,99},	//( - , DU) пневматика по мощности
	{&psrb4,1,100},	//( - , DU) кнопка сброс
	{&psa2,1,101},	//( - , DU) AZ2
	{&psa1,1,102},	//( - , DU) AZ1
	{&psb2,1,103},	//( - , DU) движение бб
	{&psb1,1,104},	//( - , DU) ру не готова
	{&R0EE02LDU,1,105},	//( - , DU) Питание  АКНП  отключить
	{&B0VS11LDU,1,106},	//( - , DU) АЗ2 готова к работе
	{&A0VS11LDU,1,107},	//( - , DU) АЗ1 готова к работе
	{&B0VN01LDU,1,108},	//( - , DU) Каналы АЗ2 проверены
	{&A3VP42LDU,1,109},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже АС
	{&A3VP52LDU,1,110},	//( - , DU) Давление ВЫСТРЕЛ ИС1 ниже ПС
	{&B3VP42LDU,1,111},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже АС
	{&B3VP52LDU,1,112},	//( - , DU) Давление ВЫСТРЕЛ ИС2 ниже ПС
	{&B3VP82LDU,1,113},	//( - , DU) Давление ВЫСТРЕЛ ИС2 в норме
	{&A3VP82LDU,1,114},	//( - , DU) Давление ВЫСТРЕЛ ИС1 в норме
	{&A0VE01LDU,1,115},	//( - , DU) Напряжение в системы АЗ1 подано
	{&B0VE01LDU,1,116},	//( - , DU) Напряжение в системы АЗ2 подано
	{&A0VP01LDU,1,117},	//( - , DU) Давление в системы АЗ1 подано
	{&B0VP01LDU,1,118},	//( - , DU) Давление в системы АЗ2 подано
	{&A0VN01LDU,1,119},	//( - , DU) Каналы АЗ1 проверены
	{&A9ZAV,1,120},	//( - , DU) Завершение НИ ДС1(2)
	{&A8ZAV,1,121},	//( - , DU) 
	{&A2ZAV,1,122},	//( - , DU) Завершение РБ1,2
	{&B8ZAV,1,123},	//( - , DU) 
	{&A5ZAV,1,124},	//( - , DU) 
	{&R2ZAV,1,125},	//( - , DU) 
	{&A6ZAV,1,126},	//( - , DU) 
	{&A4ZAV,1,127},	//( - , DU) 
	{&R0AB13LDU,1,128},	//( - , DU) Ошибка в заданной координате  АЗ2
	{&R0AB12LDU,1,129},	//( - , DU) Ошибка в заданной координате  ИС2
	{&R0AB11LDU,1,130},	//( - , DU) Ошибка в заданной координате  ИС1
	{&R0AB10LDU,1,131},	//( - , DU) Ошибка в заданной координате ББ2
	{&R0AB09LDU,1,132},	//( - , DU) Ошибка в заданной координате ББ1
	{&R3IS21LDU,1,133},	//( - K18VDSR, DU) Приход на НУ гомогенных дверей
	{&R0AB03LDU,1,134},	//( - , DU) Нарушение времени срабатывания АЗ от ВУ ИС
	{&R0AB05LDU,1,135},	//( - , DU) Нарушение времени срабатывания АЗ от НУП ИС
	{&A2AB15LDU,1,136},	//( - , DU) Блокировка на подъем РБ1 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{&B2AB15LDU,1,137},	//( - , DU) Блокировка на подъем РБ2 пневматикой:  после  сброса РБ прошло менее 3,5 мин
	{&R0VX02LDU,1,138},	//( - , DU) Импульс разрешен
	{&R0EE03LDU,1,139},	//( - , DU) ВПИС ИС
	{&R0AB07LDU,1,140},	//( - , DU) Блокировка программы подъёма ОРР-ошибка уставки АЗ2
	{&R0VS11LDU,1,141},	//( - , DU) РУ не готова к работе
	{&B6AB05LDU,1,142},	//( - , DU) Блокировка открытия БЗ2- АНИ не установлен
	{&R0AB08LDU,1,143},	//( - , DU) Блокировка кнопки ПУСК - тележка не у образцов
	{&A3EE03LDU,1,144},	//( - , DU) ВПИС ИС1
	{&B3AB19LDU,1,145},	//( - , DU) Блокировка пневматического подъема ИС2: режим статический
	{&A3AB19LDU,1,146},	//( - , DU) Блокировка пневматического подъема ИС1: режим статический
	{&R0VL23LDU,1,147},	//( - , DU) Конец программы 20мин
	{&R0VL22LDU,1,148},	//( - , DU) Конец программы 200сек
	{&B8IS21LDU,1,149},	//( - K20VDSR, DU) Приход на НУ1 АЗ2
	{&B8IS12LDU,1,150},	//( - K21VDSR, DU) Приход на ВУ2 АЗ2
	{&R0AB19LDU,1,151},	//( - , DU) Блокировка регулирования мощности:Нарушение исходных условий.
	{&R0AB20LDU,1,152},	//( - , DU) Блокировка изменения положения ОР: работает  регулятор мощности
	{&A3AB15LDU,1,153},	//( - , DU) Блокировка заполнения ресивера ИС1: работает регулятор мощности
	{&R4ABL,1,154},	//( - , DU) Блокировка тележки -
	{&A4UP,1,155},	//( - , DU) 
	{&A4DW,1,156},	//( - , DU) 
	{&R0AB14LDU,1,157},	//( - , DU) Режим проверки не разрешён: ИС2 ниже 55 мм
	{&R0AB15LDU,1,158},	//( - , DU) Режим проверки не разрешён: ИС1 ниже 55 мм
	{&A3IS12LDU,1,159},	//( - , DU) Приход на ВУ штока ИС1
	{&B3IS12LDU,1,160},	//( - , DU) Приход на ВУ штока ИС2
	{&A1ZAV,1,161},	//( - , DU) 
	{&A3ZAV,1,162},	//( - , DU) 
	{&B1AB19LDU,1,163},	//( - , DU) Блокировка автоматического подъёма ББ2 -превышение нейтронного потока
	{&R0AB16LDU,1,164},	//( - , DU) Блокировка регулирования мощности: Усредненный период разгона меньше допустимого
	{&R0AB17LDU,1,165},	//( - , DU) Блокировка регулирования мощности: Время работы при мощности более 100Вт больше допустимого
	{&R0AB18LDU,1,166},	//( - , DU) Блокировка регулирования мощности: Рассогласование  заданных координат ИС1,2
	{&B2IS12LDU,1,167},	//( - K10VDSR, DU) Магнит РБ2 зацеплен
	{&B1IS12LDU,1,168},	//( - K07VDSR, DU) Магнит ББ2 зацеплен
	{&A2IS12LDU,1,169},	//( - K10VDSR, DU) Магнит РБ1 зацеплен
	{&A1IS12LDU,1,170},	//( - K07VDSR, DU) Магнит ББ1 зацеплен
	{&B5AB04LDU,1,171},	//( - , DU) Блокировка движения НЛ2 -Ошибка в направлении  движения
	{&A5AB04LDU,1,172},	//( - , DU) Блокировка движения НЛ1 -Ошибка в направлении  движения
	{&B4AB02LDU,1,173},	//( - , DU) Блокировка движения НИ2 - Нет перемещения
	{&B4AB01LDU,1,174},	//( - , DU) Блокировка движения НИ2 - Превышение времени движения
	{&B4AZ03LDU,1,175},	//( - , DU) Несанкционированное перемещение НИ2
	{&A4AB02LDU,1,176},	//( - , DU) Блокировка движения НИ1 - Нет перемещения
	{&A4AB01LDU,1,177},	//( - , DU) Блокировка движения НИ1 - Превышение времени движения
	{&A4AZ03LDU,1,178},	//( - , DU) Несанкционированное перемещение НИ1
	{&B4IS21LDU,1,179},	//( - K32VDSR, DU) Приход на НУ НИ2
	{&A4IS21LDU,1,180},	//( - K15VDSR, DU) Приход на НУ НИ1
	{&B5AB02LDU,1,181},	//( - , DU) Блокировка движения НЛ2 - Нет перемещения
	{&B5AB01LDU,1,182},	//( - , DU) Блокировка движения НЛ2 - Превышение времени движения
	{&B5AZ03LDU,1,183},	//( - , DU) Несанкционированное перемещение НЛ2
	{&A5AB02LDU,1,184},	//( - , DU) Блокировка движения НЛ1 - Нет перемещения
	{&A5AB01LDU,1,185},	//( - , DU) Блокировка движения НЛ1 - Превышение времени движения
	{&A5AZ03LDU,1,186},	//( - , DU) Несанкционированное перемещение НЛ1
	{&B5IS21LDU,1,187},	//( - K16VDSR, DU) Приход на НУ НЛ2
	{&B5IS11LDU,1,188},	//( - K15VDSR, DU) Приход на ВУ НЛ2
	{&A5IS21LDU,1,189},	//( - K12VDSR, DU) Приход на НУ НЛ1
	{&A5IS11LDU,1,190},	//( - K11VDSR, DU) Приход на ВУ НЛ1
	{&B5VS12LDU,1,191},	//( - K14VDSR, DU) Движение НЛ2 в сторону ВУ
	{&B5VS22LDU,1,192},	//( - K15VDSR, DU) Движение НЛ2 в сторону НУ
	{&A5VS12LDU,1,193},	//( - K11VDSR, DU) Движение НЛ1 в сторону ВУ
	{&A5VS22LDU,1,194},	//( - K12VDSR, DU) Движение НЛ1 в сторону НУ
	{&R4AD20LDU,1,195},	//( - K14FDSR, DU) Перемещение тележки назад
	{&R4AB18LDU,1,196},	//( - , DU) Блокировка движения тележки назад - тележка на нижних механических упорах реактора
	{&R4AB17LDU,1,197},	//( - , DU) Блокировка движения тележки вперёд - тележка на верхних механических упорах реактора
	{&R4AB16LDU,1,198},	//( - , DU) Блокировка движения тележки - Гомогенные двери не в положении Закрыты
	{&A8AB07LDU,1,199},	//( - , DU) Блокировка движения ДС2: превышение заданной скорости
	{&A8AB06LDU,1,200},	//( - , DU) Блокировка движения ДС2 нет перемещения ДС2
	{&A8VS12LDU,1,201},	//( - , DU) Движение ДС2 в сторону ВУ
	{&B8AB02LDU,1,202},	//( - , DU) Блокировка движения АЗ2- АНИ не установлен
	{&B8AB14LDU,1,203},	//( - , DU) Блокировка движения АЗ2 - Самоход любого механизма
	{&B8AB13LDU,1,204},	//( - , DU) Блокировка движения АЗ2 - ОРР не в исходном состоянии
	{&B8AB12LDU,1,205},	//( - , DU) Блокировка движения АЗ2 - НИ не в положении ВУ
	{&B8AB11LDU,1,206},	//( - , DU) Блокировка движения АЗ2 -нет сигнала готовности СУЗ
	{&B8AB10LDU,1,207},	//( - , DU) Блокировка движения АЗ2 - тележка не на верхних механических упорах реактора
	{&B8AB09LDU,1,208},	//( - , DU) Блокировка  движения  АЗ2 - АС по мощности от любого канала
	{&B8AB08LDU,1,209},	//( - , DU) Блокировка движения АЗ2 Гомогенные двери не закрыты
	{&B8AB04LDU,1,210},	//( - , DU) Блокировка движения АЗ2 -Ошибка в направлении  движения
	{&B8AB01LDU,1,211},	//( - , DU) Блокировка движения АЗ2 - Превышение времени движения
	{&B8IS11LDU,1,212},	//( - K19VDSR, DU) Приход на ВУ1 АЗ2
	{&R4IS11LDU,1,213},	//( - K05VDSR, DU) Приход на ВУ1 тележки
	{&A6AB06LDU,1,214},	//( - , DU) Блокировка открытия БЗ1 - ОРР не в исходном состоянии
	{&A6AB07LDU,1,215},	//( - , DU) Блокировка открытия БЗ1 - АЗ2 находится не на упорах 1,5м
	{&A6AB08LDU,1,216},	//( - , DU) Блокировка открытия БЗ1 - ДС2 находится не на упорах 1,5м
	{&A6AB09LDU,1,217},	//( - , DU) Блокировка открытия БЗ1 -ворота отстойной зоны не открыты
	{&B6AB06LDU,1,218},	//( - , DU) Блокировка открытия БЗ2 - ОРР не в исходном состоянии
	{&B6AB07LDU,1,219},	//( - , DU) Блокировка открытия БЗ2 - АЗ2 находится не на упорах 1,5м
	{&B6AB08LDU,1,220},	//( - , DU) Блокировка открытия БЗ2 - ДС2находится не на упорах 1,5м
	{&B6AB09LDU,1,221},	//( - , DU) Блокировка открытия БЗ2 -ворота отстойной зоны не открыты
	{&A6AB05LDU,1,222},	//( - , DU) Блокировка открытия БЗ1 - АНИ не установлен
	{&B8VS12LDU,1,223},	//( - , DU) Движение АЗ2 в сторону ВУ
	{&B8AB06LDU,1,224},	//( - , DU) Блокировка движения АЗ2 нет перемещения АЗ2
	{&B8AB07LDU,1,225},	//( - , DU) Блокировка движения АЗ2: превышение заданной скорости
	{&B8AB05LDU,1,226},	//( - , DU) Блокировка движения АЗ2: скорость перемещения менее заданной
	{&B8VS22LDU,1,227},	//( - , DU) Движение АЗ2 в сторону НУ
	{&B8AZ03LDU,1,228},	//( - , DU) Несанкционированное перемещение АЗ2
	{&B6AB01LDU,1,229},	//( - , DU) Блокировка движения движения БЗ2 - Превышение времени движения
	{&B6AZ03LDU,1,230},	//( - , DU) Несанкционированное перемещение БЗ2
	{&A6AB02LDU,1,231},	//( - , DU) Блокировка движения БЗ1 - Нет перемещения
	{&A6AB01LDU,1,232},	//( - , DU) Блокировка движения БЗ1 - Превышение времени движения
	{&A6AZ03LDU,1,233},	//( - , DU) Несанкционированное перемещение БЗ1
	{&B6VS12LDU,1,234},	//( - K20VDSR, DU) Движение створок БЗ2  к  ОТКРЫТА
	{&B6VS22LDU,1,235},	//( - K21VDSR, DU) Движение створок БЗ2  к «ЗАКРЫТА»
	{&A6VS12LDU,1,236},	//( - K17VDSR, DU) Движение створок БЗ1  к  ОТКРЫТА
	{&A6VS22LDU,1,237},	//( - K18VDSR, DU) Движение створок БЗ1  к ЗАКРЫТА
	{&B6IS21LDU,1,238},	//( - K14VDSR, DU) Приход на НУ БЗ2
	{&B6IS11LDU,1,239},	//( - K13VDSR, DU) Приход на ВУ БЗ2
	{&A6IS21LDU,1,240},	//( - K10VDSR, DU) Приход на НУ БЗ1
	{&A6IS11LDU,1,241},	//( - K09VDSR, DU) Приход на ВУ БЗ1
	{&A1IS21LDU,1,242},	//( - K09VDSR, DU) Приход на НУ ББ1
	{&A2IS21LDU,1,243},	//( - K12VDSR, DU) Приход на НУ РБ1-СС
	{&A3IS21LDU,1,244},	//( - K13VDSR, DU) Приход на НУ ИС1
	{&B1IS21LDU,1,245},	//( - K09VDSR, DU) Приход на НУ ББ2
	{&B2IS21LDU,1,246},	//( - K12VDSR, DU) Приход на НУ РБ2-СС
	{&B3IS21LDU,1,247},	//( - K13VDSR, DU) Приход на НУ ИС2
	{&R0ES01LDU,1,248},	//( - , DU) ОРР не в исходном состоянии
	{&R5IS11LDU,1,249},	//( - K25VDSR, DU) Приход на ВУ ворот отстойной зоны
	{&R4AB15LDU,1,250},	//( - , DU) Блокировка движения тележки - ворота в пом. 0041 не в положении Открыты
	{&R4AB14LDU,1,251},	//( - , DU) Блокировка движения тележки - Кран - балка не в безопасном положении
	{&R4AB13LDU,1,252},	//( - , DU) Блокировка тележки - НЛ не в положении ВУ
	{&B4IS11LDU,1,253},	//( - K31VDSR, DU) Приход на ВУ НИ2
	{&A4IS11LDU,1,254},	//( - K14VDSR, DU) Приход на ВУ НИ1
	{&R4AB12LDU,1,255},	//( - , DU) Блокировка движения тележки - НИ не в положении ВУ
	{&R4AB11LDU,1,256},	//( - , DU) Блокировка движения тележки - МДЗ1,2 не находятся на НУ
	{&R4AB10LDU,1,257},	//( - , DU) Блокировка тележки - не открыта биологическая защита
	{&R4AB09LDU,1,258},	//( - , DU) Блокировка движения тележки - АЗ по мощности от любого канала  БАЗ
	{&R4AB08LDU,1,259},	//( - , DU) Блокировка движения тележки - А32 или ДС2 не на НУ(координата 1500 мм)
	{&R4AB07LDU,1,260},	//( - , DU) Блокировка движения тележки - ОРР не в исходном состоянии
	{&R4AB06LDU,1,261},	//( - , DU) Блокировка движения тележки - Ошибка в  направлении перемещения
	{&R4AB05LDU,1,262},	//( - , DU) Блокировка движения  тележки - Нет перемещения тележки
	{&R4AB04LDU,1,263},	//( - , DU) Блокировка движения тележки - Превышение времени движения
	{&R2IS21LDU,1,264},	//( - K30VDSR, DU) Приход на НУ МДЗ2
	{&B6AB02LDU,1,265},	//( - , DU) Блокировка движения БЗ2 - Нет перемещения
	{&A6AB04LDU,1,266},	//( - , DU) Блокировка движения БЗ1 -Ошибка в направлении  движения
	{&B6AB04LDU,1,267},	//( - , DU) Блокировка движения БЗ2 -Ошибка в направлении  движения
	{&R4AB01LDU,1,268},	//( - , DU) Блокировка движения тележки - АНИ не установлен
	{&R8IS11LDU,1,269},	//( - K14VDSR, DU) Аварийный НИ установлен
	{&R4AB02LDU,1,270},	//( - , DU) Блокировка движения тележки - Потеря связи с БАЗ, ОПУ
	{&R4IS21LDU,1,271},	//( - K07VDSR, DU) Приход на НУ1 тележки
	{&R4IS22LDU,1,272},	//( - K08VDSR, DU) Приход на НУ2 тележки
	{&R4IS12LDU,1,273},	//( - K06VDSR, DU) Приход на ВУ2 тележки
	{&R4VS22LDU,1,274},	//( - K03VDSR, DU) Движение реактора к У ЗАЩИТЫ
	{&R4VS12LDU,1,275},	//( - K02VDSR, DU) Движение реактора  к У ОБРАЗЦОВ
	{&R4AZ03LDU,1,276},	//( - , DU) Несанкционированное перемещение тележки
	{&R4AB03LDU,1,277},	//( - , DU) Блокировка движения тележки - Самоход любого механизма
	{&R1IS21LDU,1,278},	//( - K28VDSR, DU) Приход на НУ МДЗ1
	{&B1AB08LDU,1,279},	//( - , DU) Блокировка подъёма ББ2 - реактор не на рабочем месте
	{&B1AB07LDU,1,280},	//( - , DU) Блокировка подъёма ББ2 Гомогенные двери не закрыты
	{&B1AZ03LDU,1,281},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ2
	{&B1VS22LDU,1,282},	//( - , DU) Движение ББ2 в сторону НУ
	{&B1AB01LDU,1,283},	//( - , DU) Блокировка движения ББ2: скорость перемещения менее заданной
	{&B1AB02LDU,1,284},	//( - , DU) Блокировка движения ББ2: превышение заданной скорости
	{&B1AB04LDU,1,285},	//( - , DU) Блокировка движения ББ2 нет перемещения  ББ2
	{&B1VS12LDU,1,286},	//( - , DU) Движение ББ2 в сторону ВУ
	{&A1AB18LDU,1,287},	//( - , DU) Блокировка подъёма ББ1- РБ-СТР ниже 80 мм
	{&A1AB17LDU,1,288},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 20 мин
	{&A1AB16LDU,1,289},	//( - , DU) Блокировка перемещения ББ1: выполняется программа 200 с
	{&A1AB14LDU,1,290},	//( - , DU) Блокировка подъёма ББ1- в режимах Калибровка, Статический мощность больше заданной
	{&A1AB13LDU,1,291},	//( - , DU) Блокировка подъёма ББ1- давление в пневмосистеме сброса ББ1 ниже АС
	{&A1AB12LDU,1,292},	//( - , DU) Блокировка подъёма ББ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&R1VS12LDU,1,293},	//( - K05VDSR, DU) Движение МДЗ1 в сторону ВУ
	{&R2IS11LDU,1,294},	//( - K29VDSR, DU) Приход на ВУ МДЗ2
	{&A1VS12LDU,1,295},	//( - , DU) Движение ББ1 в сторону ВУ
	{&A1AB04LDU,1,296},	//( - , DU) Блокировка движения ББ1 нет перемещения  ББ1
	{&A1AB02LDU,1,297},	//( - , DU) Блокировка движения ББ1: превышение заданной скорости
	{&A1AB01LDU,1,298},	//( - , DU) Блокировка движения ББ1: скорость перемещения менее заданной
	{&A1VS22LDU,1,299},	//( - , DU) Движение ББ1 в сторону НУ
	{&A1AZ03LDU,1,300},	//( - , DU) Сброс ББ: Несанкционированное перемещение ББ1
	{&A1AB07LDU,1,301},	//( - , DU) Блокировка подъёма ББ1 Гомогенные двери не закрыты
	{&A1AB08LDU,1,302},	//( - , DU) Блокировка подъёма ББ1 - реактор не на рабочем месте
	{&A1AB05LDU,1,303},	//( - , DU) Блокировка подъёма ББ1 -нет сигнала готовности СУЗ
	{&A1AB06LDU,1,304},	//( - , DU) Блокировка подъёма ББ1 - НИ не в положении ВУ,режим работы не проверочный
	{&A1AB09LDU,1,305},	//( - , DU) Блокировка подъёма ББ1- АНИ не установлен
	{&A1AB10LDU,1,306},	//( - , DU) Блокировка подъёма ББ1- есть сигнал общего сброса
	{&A1AB11LDU,1,307},	//( - , DU) Блокировка подъёма ББ1- АЗ2 или ДС2 не на заданной координате
	{&B3VS12LDU,1,308},	//( - , DU) Движение ИС2 в сторону ВУ
	{&A3AB20LDU,1,309},	//( - , DU) Блокировка выстрела ИС1 - клапан ВПИС1 закрыт
	{&A3AB18LDU,1,310},	//( - , DU) Блокировка подъёма ИС1- РБ-СТР ниже 80 мм
	{&A3AB17LDU,1,311},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 20 мин
	{&A3AB16LDU,1,312},	//( - , DU) Блокировка перемещения ИС1: выполняется программа 200 с
	{&A3AB14LDU,1,313},	//( - , DU) Блокировка подъёма ИС1- в режимах Калибровка, Статический мощность больше заданной
	{&A3AB12LDU,1,314},	//( - , DU) Блокировка подъёма ИС1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A3AB11LDU,1,315},	//( - , DU) Блокировка подъёма ИС1- АЗ2 или ДС2 не на заданной координате
	{&A3AB10LDU,1,316},	//( - , DU) Блокировка подъёма ИС1- есть сигнал общего сброса
	{&A3AB09LDU,1,317},	//( - , DU) Блокировка подъёма ИС1- АНИ не установлен
	{&A3AB06LDU,1,318},	//( - , DU) Блокировка подъёма ИС1 - НИ не в положении ВУ,режим работы не проверочный
	{&A3AB05LDU,1,319},	//( - , DU) Блокировка подъёма ИС1 -нет сигнала готовности СУЗ
	{&A3AB08LDU,1,320},	//( - , DU) Блокировка подъёма ИС1 - реактор не на рабочем месте
	{&A3AB07LDU,1,321},	//( - , DU) Блокировка подъёма ИС1 Гомогенные двери не закрыты
	{&A3AZ03LDU,1,322},	//( - , DU) Сброс РБ: Несанкционированное перемещение ИС1
	{&B1AB05LDU,1,323},	//( - , DU) Блокировка подъёма ББ2 -нет сигнала готовности СУЗ
	{&B1AB06LDU,1,324},	//( - , DU) Блокировка подъёма ББ2 - НИ не в положении ВУ,режим работы не проверочный
	{&B1AB09LDU,1,325},	//( - , DU) Блокировка подъёма ББ2- АНИ не установлен
	{&B1AB10LDU,1,326},	//( - , DU) Блокировка подъёма ББ2- есть сигнал общего сброса
	{&B1AB11LDU,1,327},	//( - , DU) Блокировка подъёма ББ2- АЗ2 или ДС2 не на заданной координате
	{&B1AB12LDU,1,328},	//( - , DU) Блокировка подъёма ББ2- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&B1AB13LDU,1,329},	//( - , DU) Блокировка подъёма ББ2- давление в пневмосистеме ББ2 ниже АС
	{&B1AB14LDU,1,330},	//( - , DU) Блокировка подъёма ББ2- в режимах Калибровка, Статический мощность больше заданной
	{&B1AB16LDU,1,331},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 200 с
	{&B1AB17LDU,1,332},	//( - , DU) Блокировка перемещения ББ2: выполняется программа 20 мин
	{&B1AB18LDU,1,333},	//( - , DU) Блокировка подъёма ББ2- РБ-СТР ниже 80 мм
	{&A3VS12LDU,1,334},	//( - , DU) Движение ИС1 в сторону ВУ
	{&A3AB04LDU,1,335},	//( - , DU) Блокировка движения ИС1 нет перемещения  ИС1
	{&A3AB02LDU,1,336},	//( - , DU) Блокировка движения ИС1: превышение заданной скорости
	{&A3AB01LDU,1,337},	//( - , DU) Блокировка движения ИС1: скорость перемещения менее заданной
	{&A3VS22LDU,1,338},	//( - , DU) Движение ИС1 в сторону НУ
	{&A2AB14LDU,1,339},	//( - , DU) Блокировка подъёма РБ1- в режимах Калибровка, Статический мощность больше заданной
	{&A2AB13LDU,1,340},	//( - , DU) Блокировка подъёма РБ1- давление в пневмосистеме сброса РБ ниже ПС
	{&A2AB12LDU,1,341},	//( - , DU) Блокировка подъёма РБ1- при работе с АЗ1 органы СУЗ АЗ2 не на НУ
	{&A2AB11LDU,1,342},	//( - , DU) Блокировка подъёма РБ1- АЗ2 или ДС2 не на заданной координате
	{&A2AB10LDU,1,343},	//( - , DU) Блокировка подъёма РБ1- есть сигнал общего сброса
	{&A2AB09LDU,1,344},	//( - , DU) Блокировка подъёма РБ1- АНИ не установлен
	{&A2AB06LDU,1,345},	//( - , DU) Блокировка подъёма РБ1 - НИ не в положении ВУ,режим работы не проверочный
	{&A2AB05LDU,1,346},	//( - , DU) Блокировка подъёма РБ1 -нет сигнала готовности СУЗ
	{&A2AB08LDU,1,347},	//( - , DU) Блокировка подъёма РБ1 - реактор не на рабочем месте
	{&A2AB07LDU,1,348},	//( - , DU) Блокировка подъёма РБ1 Гомогенные двери не закрыты
	{&A2AZ03LDU,1,349},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ1
	{&A2VS21LDU,1,350},	//( - , DU) Движение РБ1 в сторону НУ
	{&A2AB01LDU,1,351},	//( - , DU) Блокировка движения РБ1: скорость перемещения менее заданной
	{&A2AB02LDU,1,352},	//( - , DU) Блокировка движения РБ1: превышение заданной скорости
	{&A2AB04LDU,1,353},	//( - , DU) Блокировка движения РБ1 нет перемещения  РБ1
	{&A8AB05LDU,1,354},	//( - , DU) Блокировка движения ДС2: скорость перемещения менее заданной
	{&A8VS22LDU,1,355},	//( - , DU) Движение ДС2 в сторону НУ
	{&A8AZ03LDU,1,356},	//( - , DU) Несанкционированное перемещение ДС2
	{&B8IS22LDU,1,357},	//( - K22VDSR, DU) Приход на НУ2 АЗ2
	{&A8IS12LDU,1,358},	//( - K30VDSR, DU) Приход на механический ВУ ДС2
	{&A8AB04LDU,1,359},	//( - , DU) Блокировка ДС2 -Ошибка в направлении  движения
	{&A8IS22LDU,1,360},	//( - K31VDSR, DU) Приход на механический НУ ДС2
	{&A8AB08LDU,1,361},	//( - , DU) Блокировка движения ДС2 Гомогенные двери не закрыты
	{&A8AB09LDU,1,362},	//( - , DU) Блокировка  движения ДС2 - АС по мощности от любого канала
	{&A8AB10LDU,1,363},	//( - , DU) Блокировка движения ДС2 - тележка не на верхних механических упорах реактора
	{&A8AB11LDU,1,364},	//( - , DU) Блокировка движения ДС2 -нет сигнала готовности СУЗ
	{&A8AB12LDU,1,365},	//( - , DU) Блокировка движения ДС2 - НИ не в положении ВУ
	{&A8AB13LDU,1,366},	//( - , DU) Блокировка движения ДС2 - ОРР не в исходном состоянии
	{&A8AB14LDU,1,367},	//( - , DU) Блокировка движения ДС2 - Самоход любого механизма
	{&A8AB02LDU,1,368},	//( - , DU) Блокировка движения ДС2- АНИ не установлен
	{&A8AB01LDU,1,369},	//( - , DU) Блокировка ДС2 -Превышение времени перемещения
	{&A2VS11LDU,1,370},	//( - , DU) Движение РБ1 в сторону ВУ
	{&R2VS12LDU,1,371},	//( - K08VDSR, DU) Движение МДЗ2 в сторону ВУ
	{&R2VS22LDU,1,372},	//( - K09VDSR, DU) Движение МДЗ2 в сторону НУ
	{&R1VS22LDU,1,373},	//( - K06VDSR, DU) Движение МДЗ1 в сторону НУ
	{&R1IS11LDU,1,374},	//( - K27VDSR, DU) Приход на ВУ МДЗ1
	{&R2AB04LDU,1,375},	//( - , DU) Блокировка движения МДЗ2 -Ошибка в направлении  движения
	{&R1AB04LDU,1,376},	//( - , DU) Блокировка движения МДЗ1 -Ошибка в направлении  движения
	{&R2AB02LDU,1,377},	//( - , DU) Блокировка движения МДЗ2 - Нет перемещения МДЗ2
	{&R2AB01LDU,1,378},	//( - , DU) Блокировка движения МДЗ2 - Превышение времени движения
	{&R2AZ03LDU,1,379},	//( - , DU) Несанкционированное перемещение МДЗ2
	{&R1AB02LDU,1,380},	//( - , DU) Блокировка движения МДЗ1 - Нет перемещения МДЗ1
	{&R1AB01LDU,1,381},	//( - , DU) Блокировка движения МДЗ1 - Превышение времени движения
	{&R1AZ03LDU,1,382},	//( - , DU) Несанкционированное перемещение МДЗ1
	{&B2AB17LDU,1,383},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 20 мин
	{&B2AB16LDU,1,384},	//( - , DU) Блокировка перемещения РБ2: выполняется программа 200 с
	{&B2AB14LDU,1,385},	//( - , DU) Блокировка подъёма РБ2- в режимах Калибровка, Статический мощность больше заданной
	{&B2AB13LDU,1,386},	//( - , DU) Блокировка подъёма РБ2- давление в пневмосистеме сброса РБ ниже ПС
	{&A2AB16LDU,1,387},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 200 с
	{&A2AB17LDU,1,388},	//( - , DU) Блокировка перемещения РБ1: выполняется программа 20 мин
	{&B2AB04LDU,1,389},	//( - , DU) Блокировка движения РБ2 нет перемещения  РБ2
	{&B2AB02LDU,1,390},	//( - , DU) Блокировка движения РБ2: превышение заданной скорости
	{&B2AB01LDU,1,391},	//( - , DU) Блокировка движения РБ2: скорость перемещения менее заданной
	{&B2AZ03LDU,1,392},	//( - , DU) Сброс РБ: Несанкционированное перемещение РБ2
	{&B2AB07LDU,1,393},	//( - , DU) Блокировка подъёма РБ2 Гомогенные двери не закрыты
	{&B2AB08LDU,1,394},	//( - , DU) Блокировка подъёма РБ2 - реактор не на рабочем месте
	{&B2AB05LDU,1,395},	//( - , DU) Блокировка подъёма РБ2 -нет сигнала готовности СУЗ
	{&B2AB06LDU,1,396},	//( - , DU) Блокировка подъёма РБ2 - НИ не в положении ВУ,режим работы не проверочный
	{&B2AB09LDU,1,397},	//( - , DU) Блокировка подъёма РБ2- АНИ не установлен
	{&B2AB10LDU,1,398},	//( - , DU) Блокировка подъёма РБ2- есть сигнал общего сброса
	{&B2AB11LDU,1,399},	//( - , DU) Блокировка подъёма РБ2- АЗ2 или ДС2 не на заданной координате
	{&B2AB12LDU,1,400},	//( - , DU) Блокировка подъёма РБ2- при работе с АЗ2 органы СУЗ АЗ1 не на НУ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_DU[]={  // 
	{&R0VX08IDU,3,0},	//( - , DU) Индикация Режим
	{&B2VS01IDU,3,1},	//( - , DU) Готовность к управлению РБ2
	{&R0VL01RDU,8,2},	//( - , DU) Индикация Время задержки
	{&R0VL04RDU,8,4},	//( - , DU) Индикация (Время срабатывания верхней АС II УР)
	{&R0VL02RDU,8,6},	//( - , DU) Индикация (Время задержки ИНИ)
	{&R0VL06RDU,8,8},	//( - , DU) Индикация (Время задержки от ВУ РБ)
	{&R0VL11IDU,3,10},	//( - , DU) До импульса секунд
	{&R0VL01IDU,3,11},	//( - , DU) До импульса минут
	{&B3CV02RDU,8,12},	//( - , DU) Заданная скорость перемещения ИС2
	{&R1VS01IDU,3,14},	//( - , DU) Готовность к управлению МДЗ1
	{&R2VS01IDU,3,15},	//( - , DU) Готовность к управлению МДЗ2
	{&R4VS01IDU,3,16},	//( - , DU) Готовность к управлению тележкой реактора
	{&A6VS01IDU,3,17},	//( - , DU) Готовность к управлению БЗ1
	{&B5VS01IDU,3,18},	//( - , DU) Готовность к управлению НЛ2
	{&A5VS01IDU,3,19},	//( - , DU) Готовность к управлению НЛ1
	{&R0VL03RDU,8,20},	//( - , DU) Индикация (Время срабатывания АЗ от ВУ ИС)
	{&R0VL05RDU,8,22},	//( - , DU) Индикация (Время срабатывания АЗ от НУП ИС)
	{&R0VL21IDU,3,24},	//( - , DU) Декатрон
	{&R0VS21IDU,3,25},	//( - , DU) Индикация ВИД ПРОВЕРКИ
	{&A1VS01IDU,3,26},	//( - , DU) Готовность к управлению ББ1
	{&B1VS01IDU,3,27},	//( - , DU) Готовность к управлению ББ2
	{&A3VS01IDU,3,28},	//( - , DU) Готовность к управлению ИС1
	{&B3VS01IDU,3,29},	//( - , DU) Готовность к управлению ИС2
	{&A2VS01IDU,3,30},	//( - , DU) Готовность к управлению РБ1
	{&A4VS01IDU,3,31},	//( - , DU) Готовность к управлению НИ1
	{&B4VS01IDU,3,32},	//( - , DU) Готовность к управлению НИ2
	{&A1VC01RDU,8,33},	//( - , DU) Координата ББ1, мм
	{&A8VC01RDU,8,35},	//( - , DU) Координата ДС2, мм
	{&B3VC01RDU,8,37},	//( - , DU) Координата ИС2, мм
	{&R5VS01IDU,3,39},	//( - , DU) Готовность к управлению ворот отстойной зоны
	{&R3VS01IDU,3,40},	//( - , DU) Готовность к управлению гомогенных дверей
	{&TTLDU,3,41},	//( - , DU) ttl
	{&B3CV01RDU,8,42},	//( - , DU) Измеренная скорость перемещения ИС2
	{&R0VN15RDU,8,44},	//( - , DU) Период разгона РУ
	{&B1VC01RDU,8,46},	//( - , DU) Координата ББ2, мм
	{&B8VC01RDU,8,48},	//( - , DU, MDuBz1, MDuBz2) Координата АЗ2, мм
	{&B2VC01RDU,8,50},	//( - , DU) Координата РБ2, мм
	{&A2VC01RDU,8,52},	//( - , DU) Координата РБ1, мм
	{&A3VC01RDU,8,54},	//( - , DU) Координата ИС1, мм
	{&A3CP02RDU,8,56},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС1
	{&B3CP02RDU,8,58},	//( - , DU) Текущее давление ВЫСТРЕЛ ИС2
	{&B6VS01IDU,3,60},	//( - , DU) Готовность к управлению БЗ2
	{&B8VS01IDU,3,61},	//( - , DU) Готовность к управлению АЗ2
	{&A8VS01IDU,3,62},	//( - , DU) Готовность к управлению ДС2
	{&R0CN95LDU,3,63},	//( - , DU) Этап 0 - не начинали, 53 - выход в 0 реакт,51-повышаем, 52 - уменьшаем, 54- на новое задание
	{&R0CN94LDU,8,64},	//( - , DU) Скорость изменения мощности
	{&R0CN93LDU,8,66},	//( - , DU) время работы на мощности более 100Вт, сек
	{&R0VN12RDU,8,68},	//( - , DU) Заданная мощность РУ
	{&R0VN11RDU,8,70},	//( - , DU) Текущая мощность РУ
	{&R0CN92LDU,8,72},	//( - , DU) Рассчётный коэффициент  опережения старта ИМ
	{&A3MC01RDU,8,74},	//( - , DU) Заданная координата положения ИС от регулятора мм
	{&A3MC02RDU,8,76},	//( - , DU) Температурная корректировка координаты ИМ
	{&R0CN91LDU,8,78},	//( - , DU) Рассчётная реактивность от регулятора
	{&A3MC03RDU,8,80},	//( - , DU) Координата положения ИМ 0-й реактивности
	{&A8CV01RDU,8,82},	//( - , DU) Измеренная скорость перемещения ДС2
	{&B8CV01RDU,8,84},	//( - , DU) Измеренная скорость перемещения АЗ2
	{&B1CV02RDU,8,86},	//( - , DU) Заданная скорость перемещения ББ2
	{&B1CV01RDU,8,88},	//( - , DU) Измеренная скорость перемещения ББ2
	{&A1CV01RDU,8,90},	//( - , DU) Измеренная скорость перемещения ББ1
	{&A1CV02RDU,8,92},	//( - , DU) Заданная скорость перемещения ББ1
	{&A3CV02RDU,8,94},	//( - , DU) Заданная скорость перемещения ИС1
	{&A3CV01RDU,8,96},	//( - , DU) Измеренная скорость перемещения ИС1
	{&A2CV01RDU,8,98},	//( - , DU) Измеренная скорость перемещения РБ1
	{&A2CV02RDU,8,100},	//( - , DU) Заданная скорость перемещения РБ1
	{&B2CV01RDU,8,102},	//( - , DU) Измеренная скорость перемещения РБ2
	{&B2CV02RDU,8,104},	//( - , DU) Заданная скорость перемещения РБ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_DU[]={  // 
	{&R0MW12IP2,3,0},	//( - , DU) Переключатель ВРЕМЯ СРАБАТЫВАНИЯ от ВУ РБ
	{&R0MW14IP2,3,1},	//( - , DU) Переключатель ОБДУВ
	{&B8MC01RP2,8,2},	//( - , DU) Заданная координата АЗ2 мм
	{&B3MC01RP1,8,4},	//( - , DU) Заданная координата положения ИС2 мм
	{&A3MC01RP1,8,6},	//( - , DU) Заданная координата положения ИС1 мм
	{&A1MC01RP1,8,8},	//( - , DU) Заданная координата положения ББ1 мм
	{&B1MC01RP1,8,10},	//( - , DU) Заданная координата положения ББ2  мм
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
	{&R0DE01LDU,3,82},
	{&R0DE06LDU,3,80},
	{&venc01,5,40},
	{&venc02,5,45},
	{&venc03,5,50},
	{&venc04,5,55},
	{&venc05,5,60},
	{&venc08,5,75},
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
	{&R2IS21LDU,1,58},
	{&R8AD22LDU,1,28},
	{&B9IS21LDU,1,50},
	{&B9IS11LDU,1,48},
	{&A9IS21LDU,1,46},
	{&A9IS11LDU,1,44},
	{&B7AS31LDU,1,10},
	{&B2IS12LDU,1,18},
	{&B1IS12LDU,1,12},
	{&B1IS11LDU,1,14},
	{&A1VN71LZ1,1,40},
	{&R1IS21LDU,1,54},
	{&B4IS21LDU,1,62},
	{&R8IS11LDU,1,26},
	{&R0AD14LZ1,1,38},
	{&R1IS11LDU,1,52},
	{&A3VZ13LZ1,1,34},
	{&A3VZ15LZ1,1,36},
	{&B4IS10LDU,1,6},
	{&B3IS35LDU,1,0},
	{&B3IS33LDU,1,2},
	{&B3IS31LDU,1,8},
	{&B2IS33LDU,1,4},
	{&R0DE02LDU,3,64},
	{&R0VZ71LZ1,1,42},
	{&B1IS21LDU,1,16},
	{&B2IS11LDU,1,20},
	{&B4IS11LDU,1,60},
	{&B3IS21LDU,1,24},
	{&R2IS11LDU,1,56},
	{&B2IS21LDU,1,22},
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
	{&A7AS31LDU,1,10},
	{&A4IS21LDU,1,28},
	{&A3VZ13LZ2,1,34},
	{&A2IS33LDU,1,4},
	{&A3IS31LDU,1,8},
	{&A3IS33LDU,1,2},
	{&A3IS35LDU,1,0},
	{&A4IS10LDU,1,6},
	{&A1VN71LZ2,1,40},
	{&R0AD14LZ2,1,38},
	{&A1IS11LDU,1,14},
	{&A3VZ15LZ2,1,36},
	{&A3IS21LDU,1,24},
	{&A2IS12LDU,1,18},
	{&A2IS21LDU,1,22},
	{&A1IS21LDU,1,16},
	{&R0VZ71LZ2,1,42},
	{&A2IS11LDU,1,20},
	{&A4IS11LDU,1,26},
	{&R0DE03LDU,3,64},
	{&A1IS12LDU,1,12},
	{&R0IS01LDU,1,56},
	{&R0IS02LDU,1,58},
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
	{&R6IS21LDU,1,56},
	{&B5IS21LDU,1,30},
	{&B8IS22LDU,1,42},
	{&B8IS11LDU,1,36},
	{&A8IS12LDU,1,58},
	{&R5IS21LDU,1,50},
	{&B5IS11LDU,1,28},
	{&A5IS21LDU,1,22},
	{&A3IS22LDU,1,2},
	{&B3IS22LDU,1,6},
	{&A5IS11LDU,1,20},
	{&B3IS11LDU,1,4},
	{&A3IS11LDU,1,0},
	{&B6IS21LDU,1,26},
	{&A8IS22LDU,1,60},
	{&R0DE04LDU,3,64},
	{&R5IS11LDU,1,48},
	{&B6IS11LDU,1,24},
	{&R4IS11LDU,1,8},
	{&A6IS21LDU,1,18},
	{&A6IS11LDU,1,16},
	{&B8IS21LDU,1,38},
	{&B8IS12LDU,1,40},
	{&R3IS21LDU,1,34},
	{&R3IS11LDU,1,32},
	{&R4IS12LDU,1,10},
	{&R4IS22LDU,1,14},
	{&R4IS21LDU,1,12},
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
	{&A2IE03LDU,1,12},
	{&A1IE04LDU,1,6},
	{&A1IE03LDU,1,4},
	{&R6IS52LDU,1,58},
	{&R6IS51LDU,1,56},
	{&B2IE01LDU,1,34},
	{&B3IE01LDU,1,42},
	{&B1IE02LDU,1,24},
	{&B1IE01LDU,1,26},
	{&B3IE02LDU,1,40},
	{&B2IE02LDU,1,32},
	{&B3IE04LDU,1,46},
	{&B3IE03LDU,1,44},
	{&B2IE04LDU,1,38},
	{&B2IE03LDU,1,36},
	{&B1IE04LDU,1,30},
	{&B1IE03LDU,1,28},
	{&A3IE04LDU,1,22},
	{&A3IE03LDU,1,20},
	{&A2IE04LDU,1,14},
	{&A2IE02LDU,1,8},
	{&R6IS31LDU,1,48},
	{&R6IS32LDU,1,50},
	{&R6IS42LDU,1,54},
	{&R6IS41LDU,1,52},
	{&R0DE05LDU,3,64},
	{&A1IE01LDU,1,2},
	{&A3IE01LDU,1,18},
	{&A2IE01LDU,1,10},
	{&A1IE02LDU,1,0},
	{&A3IE02LDU,1,16},
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
	{&A2AD11LDU,1,0},
	{&A2AD21LDU,1,2},
	{&A2AD02LDU,1,6},
	{&A2AD03LDU,1,8},
	{&A2AD04LDU,1,10},
	{&A2AD05LDU,1,12},
	{&B2AD02LDU,1,20},
	{&B2AD01LDU,1,18},
	{&B2AD05LDU,1,26},
	{&B2AD04LDU,1,24},
	{&R0DE07LDU,3,38},
	{&B2AD03LDU,1,22},
	{&B2AD21LDU,1,16},
	{&B2AD11LDU,1,14},
	{&A2AD01LDU,1,4},
	{&R0S01LZ2,1,30},
	{&R0S01LZ1,1,28},
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
	{&A1AD11LDU,1,0},
	{&A1AD21LDU,1,2},
	{&A1AD02LDU,1,6},
	{&B1AD11LDU,1,14},
	{&B1AD21LDU,1,16},
	{&B1AD02LDU,1,20},
	{&B1AD03LDU,1,22},
	{&B1AD04LDU,1,24},
	{&R0DE08LDU,3,38},
	{&B1AD05LDU,1,26},
	{&B1AD01LDU,1,18},
	{&A1AD03LDU,1,8},
	{&A1AD04LDU,1,10},
	{&A1AD01LDU,1,4},
	{&A1AD05LDU,1,12},
	{&R0S01LIM,1,28},
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
	{&B3AD31LDU,1,8},
	{&B3AD34LDU,1,0},
	{&B2AD33LDU,1,4},
	{&R0DE09LDU,3,38},
	{&B3AD33LDU,1,2},
	{&B6AD20LDU,1,22},
	{&R4AD20LDU,1,26},
	{&R4AD10LDU,1,24},
	{&B6AD10LDU,1,20},
	{&A6AD20LDU,1,18},
	{&A6AD10LDU,1,16},
	{&A8AD10LDU,1,12},
	{&B4AD10LDU,1,6},
	{&B7AP31LDU,1,10},
	{&A8AD20LDU,1,14},
	{&B8AD10LDU,1,28},
	{&B8AD20LDU,1,30},
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
	{&R0DE0ALDU,3,38},
	{&R2AD20LDU,1,18},
	{&R2AD10LDU,1,16},
	{&A2AD33LDU,1,4},
	{&A3AD33LDU,1,2},
	{&A3AD34LDU,1,0},
	{&A3AD31LDU,1,8},
	{&A5AD20LDU,1,22},
	{&A7AP31LDU,1,10},
	{&R1AD20LDU,1,14},
	{&R1AD10LDU,1,12},
	{&A5AD10LDU,1,20},
	{&B5AD20LDU,1,26},
	{&B5AD10LDU,1,24},
	{&A4AD10LDU,1,6},
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
	{&A3AD11LDU,1,0},
	{&A3AD21LDU,1,2},
	{&A3AD02LDU,1,6},
	{&A9AD10LDU,1,28},
	{&B3AD11LDU,1,14},
	{&B3AD21LDU,1,16},
	{&A3AD01LDU,1,4},
	{&A3AD05LDU,1,12},
	{&A3AD04LDU,1,10},
	{&A3AD03LDU,1,8},
	{&B9AD10LDU,1,30},
	{&B3AD01LDU,1,18},
	{&B3AD05LDU,1,26},
	{&B3AD04LDU,1,24},
	{&B3AD03LDU,1,22},
	{&B3AD02LDU,1,20},
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
	{&B3IP02IDU,3,3},
	{&A3IP02IDU,3,0},
	{&R0DE0CLDU,3,26},
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
	{&R0DE0DLDU,3,64},
	{&A5VS22LDU,1,22},
	{&A5VS12LDU,1,20},
	{&B5VS22LDU,1,28},
	{&R4VS12LDU,1,2},
	{&R4VS22LDU,1,4},
	{&R1VS12LDU,1,8},
	{&R2VS12LDU,1,14},
	{&R2VS22LDU,1,16},
	{&B5VS12LDU,1,26},
	{&R1VS22LDU,1,10},
	{&R2IE01LDU,1,18},
	{&R6IS61LDU,1,0},
	{&R1IE01LDU,1,12},
	{&A5IE02LDU,1,24},
	{&B5IE01LDU,1,30},
	{&A8IE01LDU,1,6},
	{&B6IE01LDU,1,42},
	{&A6IE01LDU,1,36},
	{&R0IE01LDU,1,46},
	{&R0IE02LDU,1,44},
	{&B6VS12LDU,1,38},
	{&B6VS22LDU,1,40},
	{&A6VS12LDU,1,32},
	{&A6VS22LDU,1,34},
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
	{&R8AD21LDU,1,22},
	{&R0AD05LZ2,1,30},
	{&R0AD05LZ1,1,20},
	{&R0AD04LZ2,1,28},
	{&R0AD04LZ1,1,18},
	{&A2AD31LDU,1,6},
	{&B2AD31LDU,1,14},
	{&A1AD31LDU,1,2},
	{&B1AD31LDU,1,10},
	{&A2AD32LDU,1,4},
	{&B2AD32LDU,1,12},
	{&A1AD32LDU,1,0},
	{&B1AD32LDU,1,8},
	{&R0AD03LZ1,1,16},
	{&R0AD16LDU,1,24},
	{&R0AD03LZ2,1,26},
	{&R0DE0FLDU,3,38},
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
	{&R0DEB1LDU,1,18},
	{&R0DEB2LDU,1,20},
	{&R0DEB3LDU,1,22},
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
	setAsFloat(742,0.00009765625);
	setAsInt(743,1024200);
	setAsInt(744,-200);
	setAsInt(745,-200);
	setAsInt(746,1024200);
	setAsFloat(747,0.00009765625);
	setAsInt(748,-200);
	setAsInt(749,1689599);
	setAsFloat(750,0.00009765625);
	setAsInt(751,-200);
	setAsFloat(752,0.0009765625);
	setAsInt(753,1536200);
	setAsFloat(754,100);
	setAsFloat(755,200);
	setAsFloat(756,300);
	setAsFloat(757,400);
	setAsFloat(758,600);
	setAsFloat(759,500);
	setAsFloat(760,750);
	setAsFloat(761,2.5);
	setAsFloat(762,0);
	setAsFloat(763,0.46);
	setAsFloat(764,0.49);
	setAsFloat(765,0.52);
	setAsFloat(766,0.53);
	setAsFloat(767,0.67);
	setAsFloat(768,0.56);
	setAsFloat(769,4);
	setAsFloat(770,4);
	setAsFloat(771,10.91);
	setAsFloat(772,3);
	setAsShort(773,4);
	setAsFloat(774,0.4);
	setAsFloat(775,0.4);
	setAsFloat(776,0.4);
	setAsFloat(777,0.4);
	setAsFloat(778,0.03);
	setAsFloat(779,0.04);
	setAsFloat(780,3);
	setAsFloat(781,0.4);
	setAsFloat(782,0.4);
	setAsFloat(783,0.07);
	setAsFloat(784,0.04);
	setAsFloat(785,3);
	setAsFloat(786,0.55);
	setAsFloat(787,0.64);
	setAsFloat(788,0.190);
	setAsFloat(789,0.045);
	setAsFloat(790,0.1);
	setAsFloat(791,2);
	setAsFloat(792,0.3);
	setAsFloat(793,3);
	setAsFloat(794,1.50);
	setAsFloat(795,0.04);
	setAsFloat(796,0.05);
	setAsFloat(797,3);
	setAsFloat(798,1.50);
	setAsFloat(799,3);
	setAsFloat(800,1.50);
	setAsFloat(801,2);
	setAsFloat(802,0.004);
	setAsFloat(803,0.006);
	setAsFloat(804,0.006);
	setAsFloat(805,1.0);
	setAsFloat(806,0.01);
	setAsFloat(807,1);
	setAsFloat(808,0.008);
	setAsFloat(809,0.01);
	setAsFloat(810,1);
	setAsFloat(811,0.4);
	setAsFloat(812,120);
	setAsFloat(813,0.6);
	setAsFloat(814,1);
	setAsFloat(815,2);
	setAsFloat(816,1.50);
	setAsFloat(817,2.0);
	setAsFloat(818,1);
	setAsFloat(819,15);
	setAsFloat(820,0.50);
	setAsFloat(821,360);
	setAsFloat(822,1);
	setAsFloat(823,2);
	setAsFloat(824,1.0);
	setAsFloat(825,6.0);
	setAsFloat(826,0.50);
	setAsFloat(827,1.0);
	setAsFloat(828,16.0);
	setAsFloat(829,3.0);
	setAsFloat(830,1.0);
	setAsFloat(831,60.0);
	setAsFloat(832,0.50);
	setAsFloat(833,1.0);
	setAsFloat(834,20.0);
	setAsFloat(835,1);
	setAsFloat(836,2.0);
	setAsFloat(837,2.0);
	setAsFloat(838,1.5);
	setAsFloat(839,0.045);
	setAsFloat(840,0.045);
	setAsFloat(841,0.150);
	setAsFloat(842,0.045);
	setAsFloat(843,0.045);
	setAsFloat(844,0.015);
	setAsFloat(845,2000.0);
	setAsFloat(846,1500.0);
	setAsFloat(847,1000.0);
	setAsFloat(848,800.0);
	setAsFloat(849,500.0);
	setAsFloat(850,200.0);
	setAsFloat(851,100.0);
	setAsFloat(852,0.001);
	setAsFloat(853,100);
	setAsFloat(854,100);
	setAsFloat(855,110.0);
	setAsFloat(856,20);
	setAsFloat(857,30.0);
	setAsFloat(858,100.0);
	setAsFloat(859,1.50);
	setAsFloat(860,170);
	setAsFloat(861,170);
	setAsFloat(862,10);
	setAsShort(863,1);
	setAsShort(864,4);
	setAsShort(865,1);
	setAsShort(866,4);
	setAsShort(867,4);
	setAsShort(868,4);
	setAsShort(869,4);
	setAsBool(870,0);
	setAsFloat(871,159.99);
	setAsFloat(872,0.002375);
	setAsFloat(873,0.000877);
	setAsFloat(874,0.001675);
	setAsFloat(875,2.5);
	setAsFloat(876,30);
	setAsFloat(877,500);
	setAsFloat(878,0.01);
	setAsFloat(879,0.05);
	setAsFloat(880,160.0);
	setAsFloat(881,-141.21);
	setAsFloat(882,71.40565);
	setAsFloat(883,0.271145);
	setAsFloat(884,24.93556615);
	setAsFloat(885,0.1268);
	setAsFloat(886,0.1567);
	setAsFloat(887,0.1858);
	setAsFloat(888,0.2066);
	setAsFloat(889,0.2646);
	setAsFloat(890,0.2995);
	setAsFloat(891,0.839554030);
	setAsFloat(892,0.78859401);
	setAsFloat(893,0.765962);
	setAsFloat(894,0.67256403);
	setAsFloat(895,0.42476001);
	setAsFloat(896,0.25501999);
	setAsFloat(897,3600.0);
	setAsFloat(898,0.935);
	setAsFloat(899,0.1);
	setAsFloat(900,0.006792308);
	setAsFloat(901,0.000418877);
	setAsFloat(902,0.001);
	setAsFloat(903,0.190);
	setAsFloat(904,0.5);
	setAsFloat(905,2.0);
	setAsFloat(906,0.005);
	setAsFloat(907,0.08);
	setAsFloat(908,0.100);
	setAsBool(242,1);
	setAsBool(244,1);
	setAsBool(240,1);
	setAsBool(243,1);
	setAsBool(245,1);
	setAsBool(241,1);
	setAsBool(233,1);
	setAsBool(234,1);
	setAsBool(235,1);
}
uspaint8 InternalBuf[9863];

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
ssfloat var45;
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
ssint var262;
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
ssbool var279;
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
ssint var388;
ssbool var389;
ssbool var390;
ssint var391;
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
ssbool var405;
ssbool var406;
ssbool var407;
ssbool var408;
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
ssfloat var432;
ssbool var433;
ssbool var434;
ssbool var435;
ssbool var436;
ssbool var437;
ssbool var438;
ssbool var439;
ssbool var440;
ssbool var441;
ssfloat var442;
ssfloat var443;
ssbool var444;
ssbool var445;
ssbool var446;
ssfloat var447;
ssbool var448;
ssbool var449;
ssfloat var450;
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
ssfloat var461;
ssfloat var462;
ssbool var463;
ssfloat var464;
ssfloat var465;
ssint var466;
ssbool var467;
ssbool var468;
ssbool var469;
ssbool var470;
ssbool var471;
ssbool var472;
ssbool var473;
ssbool var474;
ssbool var475;
ssbool var476;
ssbool var477;
ssbool var478;
ssbool var479;
ssbool var480;
ssbool var481;
ssbool var482;
ssbool var483;
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
ssfloat var557;
ssbool var558;
ssbool var559;
ssbool var560;
ssfloat var561;
ssbool var562;
ssbool var563;
ssbool var564;
ssfloat var565;
ssbool var566;
ssbool var567;
ssbool var568;
ssfloat var569;
ssbool var570;
ssbool var571;
ssbool var572;
ssfloat var573;
ssbool var574;
ssbool var575;
ssbool var576;
ssbool var577;
ssbool var578;
ssbool var579;
ssbool var580;
ssbool var581;
ssbool var582;
ssbool var583;
ssbool var584;
ssbool var585;
ssbool var586;
ssbool var587;
ssbool var588;
ssbool var589;
ssbool var590;
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
ssfloat var659;
ssfloat var660;
ssbool var661;
ssfloat var662;
ssfloat var663;
ssbool var664;
ssfloat var665;
ssfloat var666;
ssbool var667;
ssfloat var668;
ssfloat var669;
ssbool var670;
ssbool var671;
ssfloat var672;
ssfloat var673;
ssbool var674;
ssbool var675;
ssbool var676;
ssbool var677;
ssbool var678;
ssbool var679;
ssbool var680;
ssbool var681;
ssbool var682;
ssbool var683;
ssbool var684;
ssbool var685;
ssbool var686;
ssbool var687;
ssbool var688;
ssbool var689;
ssbool var690;
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
sslong var803;
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
ssbool var820;
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
ssfloat var1213;
ssbool var1214;
ssfloat var1215;
ssbool var1216;
ssfloat var1217;
ssbool var1218;
ssbool var1219;
ssbool var1220;
ssbool var1221;
ssfloat var1222;
ssfloat var1223;
ssfloat var1224;
ssfloat var1225;
ssfloat var1226;
ssfloat var1227;
ssbool var1228;
ssbool var1229;
ssbool var1230;
ssbool var1231;
ssbool var1232;
ssbool var1233;
ssbool var1234;
ssbool var1235;
ssbool var1236;
ssbool var1237;
ssbool var1238;
ssbool var1239;
ssbool var1240;
ssbool var1241;
ssbool var1242;
ssbool var1243;
ssbool var1244;
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
ssint var1287;
ssint var1288;
ssbool var1289;
ssbool var1290;
ssbool var1291;
ssbool var1292;
ssbool var1293;
ssbool var1294;
sslong var1295;
ssbool var1296;
ssbool var1297;
ssbool var1298;
ssint var1299;
ssbool var1300;
ssbool var1301;
ssbool var1302;
ssbool var1303;
ssbool var1304;
ssbool var1305;
ssbool var1306;
ssbool var1307;
ssbool var1308;
ssint var1309;
ssint var1310;
ssbool var1311;
ssbool var1312;
ssbool var1313;
ssbool var1314;
ssbool var1315;
ssbool var1316;
ssbool var1317;
ssbool var1318;
ssbool var1319;
ssbool var1320;
ssbool var1321;
ssbool var1322;
ssbool var1323;
ssbool var1324;
ssbool var1325;
ssbool var1326;
ssbool var1327;
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
sslong var1350;
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
ssbool var1367;
ssbool var1368;
ssfloat var1369;
ssbool var1370;
ssbool var1371;
ssbool var1372;
ssbool var1373;
ssbool var1374;
ssfloat var1375;
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
ssbool var1386;
ssbool var1387;
ssbool var1388;
ssint var1389;
ssbool var1390;
ssbool var1391;
ssbool var1392;
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
ssbool var1406;
ssbool var1407;
ssbool var1408;
ssbool var1409;
ssbool var1410;
ssbool var1411;
ssbool var1412;
ssbool var1413;
ssfloat var1414;
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
ssbool var1431;
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
sslong var1508;
ssbool var1509;
ssint var1510;
ssint var1511;
ssbool var1512;
ssfloat var1513;
ssfloat var1514;
ssfloat var1515;
ssbool var1516;
ssbool var1517;
ssbool var1518;
ssbool var1519;
ssbool var1520;
ssbool var1521;
ssbool var1522;
ssbool var1523;
ssbool var1524;
ssbool var1525;
ssbool var1526;
ssbool var1527;
ssbool var1528;
ssbool var1529;
ssbool var1530;
ssbool var1531;
ssint var1532;
ssbool var1533;
sschar var1534;
ssint var1535;
ssbool var1536;
ssfloat var1537;
ssbool var1538;
ssbool var1539;
ssbool var1540;
ssbool var1541;
ssbool var1542;
ssbool var1543;
ssbool var1544;
ssfloat var1545;
sschar var1546;
ssbool var1547;
ssbool var1548;
ssbool var1549;
ssbool var1550;
ssfloat var1551;
ssbool var1552;
ssbool var1553;
ssbool var1554;
ssbool var1555;
ssbool var1556;
ssbool var1557;
ssbool var1558;
ssbool var1559;
ssbool var1560;
ssbool var1561;
ssbool var1562;
ssbool var1563;
ssint var1564;
ssbool var1565;
sschar var1566;
ssint var1567;
ssbool var1568;
ssfloat var1569;
ssbool var1570;
ssbool var1571;
ssbool var1572;
ssbool var1573;
ssbool var1574;
ssbool var1575;
ssbool var1576;
ssfloat var1577;
sschar var1578;
ssbool var1579;
ssbool var1580;
ssbool var1581;
ssbool var1582;
ssfloat var1583;
ssbool var1584;
ssbool var1585;
ssbool var1586;
ssbool var1587;
ssbool var1588;
ssbool var1589;
ssbool var1590;
ssbool var1591;
ssbool var1592;
ssint var1593;
ssbool var1594;
sschar var1595;
ssint var1596;
ssbool var1597;
ssfloat var1598;
ssbool var1599;
ssbool var1600;
ssbool var1601;
ssbool var1602;
ssbool var1603;
ssbool var1604;
ssbool var1605;
ssfloat var1606;
sschar var1607;
ssbool var1608;
ssbool var1609;
ssbool var1610;
ssbool var1611;
ssfloat var1612;
ssbool var1613;
ssbool var1614;
ssbool var1615;
ssbool var1616;
ssbool var1617;
ssbool var1618;
ssbool var1619;
ssbool var1620;
ssbool var1621;
ssbool var1622;
ssbool var1623;
ssbool var1624;
ssbool var1625;
ssint var1626;
ssbool var1627;
sschar var1628;
ssint var1629;
ssbool var1630;
ssfloat var1631;
ssbool var1632;
ssbool var1633;
ssbool var1634;
ssbool var1635;
ssbool var1636;
ssbool var1637;
ssbool var1638;
ssfloat var1639;
sschar var1640;
ssbool var1641;
ssbool var1642;
ssfloat var1643;
ssbool var1644;
ssbool var1645;
ssbool var1646;
ssbool var1647;
ssbool var1648;
ssbool var1649;
ssbool var1650;
ssbool var1651;
ssbool var1652;
ssbool var1653;
ssbool var1654;
ssbool var1655;
ssint var1656;
ssbool var1657;
ssbool var1658;
ssbool var1659;
ssbool var1660;
ssbool var1661;
ssbool var1662;
ssbool var1663;
ssbool var1664;
ssint var1665;
ssbool var1666;
ssbool var1667;
ssbool var1668;
ssbool var1669;
ssbool var1670;
ssbool var1671;
ssbool var1672;
ssint var1673;
ssbool var1674;
sschar var1675;
ssint var1676;
ssbool var1677;
ssfloat var1678;
ssbool var1679;
ssbool var1680;
ssbool var1681;
ssbool var1682;
ssbool var1683;
ssbool var1684;
ssbool var1685;
ssfloat var1686;
sschar var1687;
ssbool var1688;
ssbool var1689;
ssfloat var1690;
ssbool var1691;
ssbool var1692;
ssbool var1693;
ssbool var1694;
ssbool var1695;
ssbool var1696;
ssbool var1697;
ssbool var1698;
sschar var1699;
ssbool var1700;
ssbool var1701;
ssbool var1702;
ssbool var1703;
ssbool var1704;
ssbool var1705;
ssbool var1706;
ssbool var1707;
ssbool var1708;
sschar var1709;
ssbool var1710;
ssbool var1711;
ssint var1712;
ssbool var1713;
sschar var1714;
ssbool var1715;
ssint var1716;
ssbool var1717;
ssbool var1718;
ssfloat var1719;
ssbool var1720;
ssbool var1721;
ssbool var1722;
ssbool var1723;
ssbool var1724;
ssbool var1725;
ssbool var1726;
ssfloat var1727;
sschar var1728;
ssbool var1729;
ssbool var1730;
ssbool var1731;
ssbool var1732;
ssfloat var1733;
ssbool var1734;
ssbool var1735;
ssbool var1736;
ssbool var1737;
ssbool var1738;
ssbool var1739;
ssbool var1740;
ssbool var1741;
ssbool var1742;
ssbool var1743;
ssbool var1744;
ssbool var1745;
ssfloat var1746;
ssbool var1747;
ssbool var1748;
ssbool var1749;
ssbool var1750;
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
ssbool var1780;
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
ssint var1801;
ssbool var1802;
ssbool var1803;
ssbool var1804;
ssbool var1805;
ssbool var1806;
ssbool var1807;
ssbool var1808;
ssbool var1809;
ssint var1810;
ssbool var1811;
ssbool var1812;
ssbool var1813;
ssbool var1814;
ssbool var1815;
ssbool var1816;
ssbool var1817;
ssbool var1818;
ssint var1819;
ssbool var1820;
ssbool var1821;
ssbool var1822;
ssbool var1823;
ssbool var1824;
ssbool var1825;
ssbool var1826;
ssbool var1827;
ssint var1828;
ssbool var1829;
ssbool var1830;
ssbool var1831;
ssbool var1832;
ssbool var1833;
ssbool var1834;
ssbool var1835;
ssbool var1836;
ssint var1837;
ssbool var1838;
ssbool var1839;
ssbool var1840;
ssbool var1841;
ssbool var1842;
ssbool var1843;
ssbool var1844;
ssbool var1845;
ssint var1846;
ssbool var1847;
ssbool var1848;
ssbool var1849;
ssbool var1850;
ssbool var1851;
ssbool var1852;
ssbool var1853;
ssbool var1854;
ssint var1855;
ssbool var1856;
ssbool var1857;
ssbool var1858;
ssbool var1859;
ssbool var1860;
ssbool var1861;
ssbool var1862;
ssbool var1863;
ssbool var1864;
ssbool var1865;
ssbool var1866;
ssbool var1867;
ssbool var1868;
ssbool var1869;
ssbool var1870;
ssbool var1871;
ssbool var1872;
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
ssfloat var1906;
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
ssbool var1921;
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
ssfloat var1941;
ssfloat var1942;
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
ssbool var1956;
ssbool var1957;
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
ssfloat var1969;
ssbool var1970;
ssbool var1971;
ssfloat var1972;
ssbool var1973;
ssbool var1974;
ssfloat var1975;
ssbool var1976;
ssbool var1977;
ssfloat var1978;
ssbool var1979;
ssbool var1980;
ssfloat var1981;
ssbool var1982;
ssbool var1983;
ssfloat var1984;
ssbool var1985;
ssbool var1986;
ssfloat var1987;
ssbool var1988;
ssbool var1989;
ssbool var1990;
ssfloat var1991;
ssbool var1992;
ssbool var1993;
ssbool var1994;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m179_x_2[13] = {&R0IE02LDU,&R0IE01LDU,&R1IE01LDU,&R2IE01LDU,&A5IE02LDU,&B5IE01LDU,&A6IE01LDU,&R6IS61LDU,&R6IS67LZZ,&R6IS68LZZ,&B6IE01LDU,&A8IE01LDU,&R6IS66LZZ};
psbool  array_m166_x_2[6] = {&var1888,&var1887,&var1886,&var1885,&var1884,&var1883};
psbool  array_m138_x_2[6] = {&var1894,&var1893,&var1892,&var1891,&var1890,&var1889};
psbool  array_m259_x_2[6] = {&var1953,&var1945,&var1959,&B0VT71LZ1,&B0VT71LZ2,&var1904};
psbool  array_m243_x_2[6] = {&var1954,&var1947,&var1960,&A0VT71LZ1,&A0VT71LZ2,&var1904};
psbool  array_m268_x_2[6] = {&var1938,&B0VP71LZ1,&B0VP71LZ2,&var1909,&var1908,&var1907};
psbool  array_m247_x_2[6] = {&var1939,&A0VP71LZ1,&A0VP71LZ2,&var1912,&var1911,&var1910};
psbool  array_m124_x_2[8] = {&var1971,&var1993,&var1989,&var1986,&var1983,&var1980,&var1974,&var1977};
psint  array_m2523_x_1[14] = {&R0DE0DLDU,&R0DE0FLDU,&R0DE02LDU,&R0DE03LDU,&R0DE04LDU,&R0DE05LDU,&R0DE07LDU,&R0DE08LDU,&R0DE09LDU,&R0DE0ALDU,&R0DE0BLDU,&R0DE0CLDU,&R0DE01LDU,&R0DE06LDU};
psbool  array_m898_x_1[6] = {&var833,&var1471,&var1447,&var1436,&var1238,&var338};
psbool  array_m1359_x_1[6] = {&var832,&var1451,&var265,&var1473,&var1238,&var358};
psbool  array_m666_x_1[6] = {&var1028,&var1341,&var1758,&var1302,&var1717,&var1335};
psbool  array_m665_x_1[6] = {&var1028,&var1342,&var1758,&var1302,&var1717,&var1334};
psfloat  array_m2430_a_1[6] = {&fEM_R0UN70LDU,&fEM_R0UN71LDU,&fEM_R0UN72LDU,&fEM_R0UN73LDU,&fEM_R0UN74LDU,&fEM_R0UN75LDU};
psfloat  array_m2430_b_1[6] = {&fEM_R0UN80LDU,&fEM_R0UN81LDU,&fEM_R0UN82LDU,&fEM_R0UN83LDU,&fEM_R0UN84LDU,&fEM_R0UN85LDU};
psfloat  array_m2441_x_1[4] = {&B0CT01IZ1,&A0CT01IZ1,&B0CT01IZ2,&A0CT01IZ2};
psbool  array_m2433_x_1[14] = {&var446,&var419,&var1062,&var479,&var481,&var417,&var1880,&var1460,&var1458,&var1905,&var445,&var434,&var430,&var453};
psbool  array_m1_x_1[47] = {&var1423,&var1863,&var578,&var313,&var717,&var1627,&var951,&R0MD34LP1,&var865,&R0MD34LP1,&var924,&R0MD34LP1,&var1158,&R0MD34LP1,&var978,&R0MD34LP1,&var1156,&var1654,&A2IS12LDU,&var634,&var1454,&var1349,&var1347,&var1260,&var1071,&R0MD34LP1,&var654,&var695,&var1498,&var1808,&R0MD34LP1,&var37,&var801,&var756,&B3IS35LDU,&B3IS35LDU,&var500,&var311,&var728,&var547,&var1859,&var1817,&var1844,&var1177,&var1831,&R2IS21LDU,&var420};
psfloat  array_m1669_x_1[7] = {&fRM_0_002,&fRM_0_005,&fRM_0_007,&fRM_0_01,&fRM_0_015,&fRM_0_02,&fRM_1_7};
psbool  array_m1620_x_1[5] = {&var37,&var36,&var35,&var34,&var33};
psbool  array_m616_x_1[12] = {&var976,&var982,&var983,&var974,&var975,&var1160,&var1161,&var473,&var971,&var972,&var970,&var978};
psfloat  array_m88_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m90_x_1[8] = {&fEM_R0UN01RDU,&fEM_R0UN02RDU,&fEM_R0UN03RDU,&fEM_R0UN04RDU,&fEM_R0UN05RDU,&fEM_R0UN06RDU,&fEM_R0UN07RDU,&fEM_R0UN08RDU};
psfloat  array_m1191_x_1[2] = {&R0VN11RZ2,&R0VN11RZ1};
psfloat  array_m1369_x_1[8] = {&var1719,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m906_x_1[8] = {&var1678,&fRM_20_,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m1004_x_1[8] = {&var1569,&var443,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m1482_x_1[8] = {&var1537,&var442,&fRM_160_,&fRM_160_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_};
psfloat  array_m548_x_1[8] = {&var1598,&var569,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m173_x_1[8] = {&var1631,&var573,&fRM_0_,&fRM_0_,&fRM_100_,&fRM_100_,&fRM_100_,&fRM_100_};
psfloat  array_m356_Tpr_1[10] = {&fRM_6_0,&fRM_126_0,&fRM_246_0,&fRM_366_0,&fRM_486_0,&fRM_606_0,&fRM_726_0,&fRM_846_0,&fRM_966_0,&fRM_1200_0};
pschar  array_m356_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m356_rz_1[10];
psbool  array_m360_x_1[5] = {&var1290,&var1291,&var1292,&var1293,&var1294};
psbool  array_m294_x_1[7] = {&var1062,&var475,&var1269,&var1266,&var481,&var479,&var477};
psfloat  array_m298_Tpr_1[10] = {&fRM_10_0,&fRM_30_0,&fRM_50_0,&fRM_70_0,&fRM_90_0,&fRM_110_0,&fRM_130_0,&fRM_150_0,&fRM_170_0,&fRM_200_0};
pschar  array_m298_type_1[10] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_6_};
pschar  array_m298_rz_1[10];
psfloat  array_m1600_Tpr_1[6] = {&fRM_0_5,&fRM_3_5,&fRM_6_5,&fRM_9_5,&fRM_12_5,&fRM_15_5};
pschar  array_m1600_type_1[6] = {&bRM_1_,&bRM_2_,&bRM_3_,&bRM_4_,&bRM_5_,&bRM_6_};
pschar  array_m1600_rz_1[6];
psbool  array_m314_x_1[5] = {&var1312,&var1313,&var1314,&var1315,&var1316};
psbool  array_m1340_x_1[5] = {&var1435,&var1045,&var1790,&var1440,&var491};
psbool  array_m1328_x_1[4] = {&var1346,&var1388,&var1262,&var1438};
psfloat  array_m1653_x_1[16] = {&var659,&var668,&fRM_0_,&var665,&fRM_0_,&fRM_0_,&fRM_0_,&var662,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&fRM_0_,&var672};
psbool  array_m1988_x_1[17] = {&var739,&var740,&var746,&var741,&var737,&var738,&var1195,&var742,&var743,&var1487,&var744,&var745,&var1479,&var1480,&var1489,&var485,&var486};
psbool  array_m1604_x_1[5] = {&var651,&var774,&var791,&var792,&var681};
psint  array_m333_x_1[3] = {&var1288,&iRM_0_,&var1310};
psint  array_m324_x_1[3] = {&var1287,&iRM_0_,&var1309};
psbool  array_m668_x_1[5] = {&var1011,&var1757,&var1524,&var1239,&var451};
psbool  array_m1553_x_1[8] = {&var895,&var896,&var897,&var892,&var891,&var890,&var1156,&var888};
psbool  array_m1481_x_1[3] = {&var340,&lRM_0_,&var339};
psfloat  array_m1483_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m1483_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m1483_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m1483_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m1509_x0_1[60];
psfloat  array_m1509_tim0_1[60];
psbool  array_m1082_x_1[8] = {&var910,&var912,&var913,&var905,&var911,&var907,&var1158,&var649};
psbool  array_m1003_x_1[3] = {&var366,&lRM_0_,&var361};
psfloat  array_m1005_Lt_fw_1[1] = {&fEM_A3UC81RDU};
psint  array_m1005_Vr_fw_1[1] = {&iEM_A3UV01IDU};
psfloat  array_m1005_Lt_bw_1[1] = {&fEM_A3UC82RDU};
psint  array_m1005_Vr_bw_1[1] = {&iEM_A3UV02IDU};
psfloat  array_m1035_x0_1[60];
psfloat  array_m1035_tim0_1[60];
psbool  array_m547_x_1[3] = {&var987,&lRM_0_,&var988};
psfloat  array_m550_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m550_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m550_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m550_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m573_x0_1[150];
psfloat  array_m573_tim0_1[150];
psbool  array_m250_x_1[12] = {&var956,&var958,&var957,&var954,&var952,&var951,&var950,&var1164,&var1163,&var945,&var948,&var474};
psbool  array_m172_x_1[3] = {&var1134,&lRM_0_,&var1135};
psfloat  array_m176_Lt_fw_1[2] = {&fEM_A1UC81RDU,&fEM_A1UC82RDU};
psint  array_m176_Vr_fw_1[2] = {&iEM_A1UV01IDU,&iEM_A1UV02IDU};
psfloat  array_m176_Lt_bw_1[1] = {&fEM_A1UC83RDU};
psint  array_m176_Vr_bw_1[1] = {&iEM_A1UV03IDU};
psfloat  array_m201_x0_1[150];
psfloat  array_m201_tim0_1[150];
psbool  array_m968_x_1[10] = {&var922,&var923,&var929,&var930,&var928,&var926,&var925,&var1166,&var1165,&var924};
psbool  array_m905_x_1[3] = {&var342,&var940,&var341};
psfloat  array_m909_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m909_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m909_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m909_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m927_x0_1[80];
psfloat  array_m927_tim0_1[80];
psfloat  array_m1804_Lt_fw_1[1] = {&fRM_1000_};
psint  array_m1804_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1804_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1804_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1450_x_1[10] = {&var861,&var862,&var864,&var863,&var865,&var867,&var869,&var866,&var868,&var870};
psbool  array_m154_x_1[5] = {&A1IS21LDU,&A3IS21LDU,&A2IS21LDU,&var1181,&var1180};
psfloat  array_m1273_Lt_fw_1[1] = {&fRM_2000_};
psint  array_m1273_Vr_fw_1[1] = {&iRM_1_};
psfloat  array_m1273_Lt_bw_1[1] = {&fRM_2000_};
psint  array_m1273_Vr_bw_1[1] = {&iRM_1_};
psbool  array_m1368_x_1[3] = {&var370,&var855,&var357};
psfloat  array_m1370_Lt_fw_1[2] = {&fEM_A2UC81RDU,&fEM_A2UC82RDU};
psint  array_m1370_Vr_fw_1[2] = {&iEM_A2UV01IDU,&iEM_A2UV02IDU};
psfloat  array_m1370_Lt_bw_1[1] = {&fEM_A2UC83RDU};
psint  array_m1370_Vr_bw_1[1] = {&iEM_A2UV03CDU};
psfloat  array_m1405_x0_1[80];
psfloat  array_m1405_tim0_1[80];
psfloat  array_m1826_x0_1[20];
psfloat  array_m1826_tim0_1[20];
psbool  array_m1236_x_1[8] = {&var1072,&var1069,&var1070,&var1071,&var1068,&var1067,&var1066,&var1065};
psbool  array_m669_x_1[18] = {&R0MD31LP1,&var764,&var1086,&var766,&var1084,&var856,&var991,&var939,&var966,&var986,&var915,&var880,&var1142,&var590,&var589,&var846,&var507,&var444};
psfloat  array_m1300_x0_1[20];
psfloat  array_m1300_tim0_1[20];
psbool  array_m481_x_1[7] = {&var1187,&var1186,&var1185,&var1184,&var1861,&var1176,&var618};
psbool  array_m459_x_1[7] = {&var1189,&var1861,&var1177,&var1190,&var1188,&var1175,&var394};
psbool  array_m854_x_1[17] = {&var1087,&var1132,&var1131,&var1128,&var1127,&var1124,&var1089,&var1126,&var1094,&var1123,&var1119,&var1121,&var1120,&var1091,&var1085,&var1174,&var942};
psbool  array_m140_x_1[21] = {&var965,&var985,&var1230,&var938,&var1229,&var1228,&var1795,&var1804,&var1822,&var1813,&var1849,&var1840,&var717,&var619,&var1220,&var1221,&var1501,&var1495,&var1659,&var1650,&var1831};

/* Объявление структур */
_S_zpfs  S_zpfs_244_2 = {&var1950,&fRM_1_,&var1881,&internal2_m244_tx,&internal2_m244_y0};
_S_zpfs  S_zpfs_272_2 = {&var1949,&fRM_1_,&var1882,&internal2_m272_tx,&internal2_m272_y0};
_S_zzfs  S_zzfs_182_2 = {&B2IE02LDU,&fRM_1_,&var1883,&internal2_m182_tx,&internal2_m182_y0};
_S_zzfs  S_zzfs_176_2 = {&B3IE01LDU,&fRM_1_,&var1884,&internal2_m176_tx,&internal2_m176_y0};
_S_zzfs  S_zzfs_172_2 = {&B1IE01LDU,&fRM_1_,&var1885,&internal2_m172_tx,&internal2_m172_y0};
_S_zzfs  S_zzfs_165_2 = {&B2IE01LDU,&fRM_1_,&var1886,&internal2_m165_tx,&internal2_m165_y0};
_S_zzfs  S_zzfs_158_2 = {&B1IE02LDU,&fRM_1_,&var1887,&internal2_m158_tx,&internal2_m158_y0};
_S_zzfs  S_zzfs_155_2 = {&B3IE02LDU,&fRM_1_,&var1888,&internal2_m155_tx,&internal2_m155_y0};
_S_zzfs  S_zzfs_149_2 = {&A3IE02LDU,&fRM_1_,&var1889,&internal2_m149_tx,&internal2_m149_y0};
_S_zzfs  S_zzfs_144_2 = {&A3IE01LDU,&fRM_1_,&var1890,&internal2_m144_tx,&internal2_m144_y0};
_S_zzfs  S_zzfs_141_2 = {&A2IE01LDU,&fRM_1_,&var1891,&internal2_m141_tx,&internal2_m141_y0};
_S_zzfs  S_zzfs_134_2 = {&A1IE01LDU,&fRM_1_,&var1892,&internal2_m134_tx,&internal2_m134_y0};
_S_zzfs  S_zzfs_132_2 = {&A2IE02LDU,&fRM_1_,&var1893,&internal2_m132_tx,&internal2_m132_y0};
_S_zzfs  S_zzfs_127_2 = {&A1IE02LDU,&fRM_1_,&var1894,&internal2_m127_tx,&internal2_m127_y0};
_S_and4  S_and4_107_2 = {&var1990,&var1925,&B8IS11LDU,&B8IS12LDU,&var1895};
_S_lkb  S_lkb_111_2 = {&lRM_1_,&var1923,&var1896};
_S_lkb  S_lkb_108_2 = {&lRM_1_,&var1895,&var1897};
_S_lkb  S_lkb_76_2 = {&lRM_1_,&var1926,&var1898};
_S_lkb  S_lkb_52_2 = {&lRM_1_,&var1931,&var1899};
_S_lkb  S_lkb_82_2 = {&lRM_1_,&var1929,&var1900};
_S_lkb  S_lkb_48_2 = {&lRM_1_,&var1935,&var1901};
_S_lkb  S_lkb_24_2 = {&lRM_1_,&var1933,&var1902};
_S_lkb  S_lkb_20_2 = {&lRM_1_,&var1937,&var1903};
_S_or2  S_or2_271_2 = {&var1994,&var1943,&var1904};
_S_bol  S_bol_234_2 = {&fRM_0_5,&var1906,&var1905};
_S_fsumo  S_fsumo_233_2 = {&var1942,&var1941,&var1906};
_S_noto  S_noto_264_2 = {&B3VP81LDU,&var1907};
_S_noto  S_noto_263_2 = {&B2VP82LDU,&var1908};
_S_noto  S_noto_262_2 = {&B4VP82LDU,&var1909};
_S_noto  S_noto_242_2 = {&A3VP81LDU,&var1910};
_S_noto  S_noto_241_2 = {&A2VP82LDU,&var1911};
_S_noto  S_noto_240_2 = {&A4VP82LDU,&var1912};
_S_schl24  S_schl24_151_2 = {&A0EE02LZ1,&A0EE03LZ1,&A0EE01LZ1,&A0EE04LZ1,&var1913};
_S_schl24  S_schl24_147_2 = {&A0EE03LZ2,&A0EE01LZ2,&A0EE02LZ2,&A0EE04LZ2,&var1914};
_S_or2  S_or2_208_2 = {&var1963,&var1964,&var1915};
_S_or2  S_or2_204_2 = {&var1966,&var1967,&var1916};
_S_and2  S_and2_223_2 = {&var1951,&var1962,&var1917};
_S_or2  S_or2_260_2 = {&var1958,&var1957,&var1918};
_S_and4  S_and4_162_2 = {&A0EE02LZ1,&A0EE04LZ1,&A0EE02LZ2,&A0EE04LZ2,&var1919};
_S_or3  S_or3_161_2 = {&var1919,&var1050,&var1913,&var1920};
_S_and4  S_and4_136_2 = {&A0EE03LZ1,&A0EE01LZ1,&A0EE01LZ2,&A0EE03LZ2,&var1921};
_S_or3  S_or3_135_2 = {&var1921,&var1914,&var1050,&var1922};
_S_and3  S_and3_110_2 = {&var1924,&var1990,&A8IS12LDU,&var1923};
_S_or2  S_or2_104_2 = {&A8MC01LC2,&A8MC01LC1,&var1924};
_S_or2  S_or2_103_2 = {&B8MC01LC2,&B8MC01LC1,&var1925};
_S_and3  S_and3_75_2 = {&var1990,&B3IS11LDU,&var1927,&var1926};
_S_or2  S_or2_71_2 = {&B3MC01LC2,&B3MC01LC1,&var1927};
_S_or2  S_or2_74_2 = {&A3MC01LC2,&A3MC01LC1,&var1928};
_S_and3  S_and3_81_2 = {&var1990,&var1928,&A3IS11LDU,&var1929};
_S_or2  S_or2_44_2 = {&A2MC01LC2,&A2MC01LC1,&var1930};
_S_and3  S_and3_51_2 = {&var1990,&A2IS11LDU,&var1930,&var1931};
_S_or2  S_or2_13_2 = {&A1MC01LC2,&A1MC01LC1,&var1932};
_S_and3  S_and3_23_2 = {&var1932,&var1990,&A1IS11LDU,&var1933};
_S_or2  S_or2_43_2 = {&B2MC01LC1,&B2MC01LC2,&var1934};
_S_and3  S_and3_47_2 = {&var1990,&B2IS11LDU,&var1934,&var1935};
_S_or2  S_or2_11_2 = {&B1MC01LC2,&B1MC01LC1,&var1936};
_S_and3  S_and3_19_2 = {&var1990,&B1IS11LDU,&var1936,&var1937};
_S_and2  S_and2_267_2 = {&var641,&var1915,&var1938};
_S_and2  S_and2_246_2 = {&var641,&var1916,&var1939};
_S_and2  S_and2_230_2 = {&var1952,&var1961,&var1940};
_S_scalzz  S_scalzz_195_2 = {&B3IP02IDU,&iRM_3276_,&iRM_16000_,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&var1941,&internal2_m195_y0};
_S_scalzz  S_scalzz_193_2 = {&A3IP02IDU,&iRM_3276_,&iRM_16000_,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&var1942,&internal2_m193_y0};
_S_noto  S_noto_180_2 = {&var1944,&var1943};
_S_andn  S_andn_179_2 = {array_m179_x_2,&iRM_13_,&var1944};
_S_noto  S_noto_177_2 = {&var1946,&var1945};
_S_andn  S_andn_166_2 = {array_m166_x_2,&iRM_6_,&var1946};
_S_noto  S_noto_145_2 = {&var1948,&var1947};
_S_andn  S_andn_138_2 = {array_m138_x_2,&iRM_6_,&var1948};
_S_noto  S_noto_266_2 = {&var1957,&var1949};
_S_noto  S_noto_248_2 = {&var1958,&var1950};
_S_noto  S_noto_222_2 = {&var1966,&var1951};
_S_noto  S_noto_231_2 = {&var1963,&var1952};
_S_noto  S_noto_160_2 = {&var1920,&var1953};
_S_noto  S_noto_142_2 = {&var1922,&var1954};
_S_noto  S_noto_269_2 = {&var1959,&var1955};
_S_noto  S_noto_253_2 = {&var1960,&var1956};
_S_ornc  S_ornc_259_2 = {array_m259_x_2,&iRM_6_,&var1957,&vainSChar};
_S_ornc  S_ornc_243_2 = {array_m243_x_2,&iRM_6_,&var1958,&vainSChar};
_S_ornc  S_ornc_268_2 = {array_m268_x_2,&iRM_6_,&var1959,&vainSChar};
_S_ornc  S_ornc_247_2 = {array_m247_x_2,&iRM_6_,&var1960,&vainSChar};
_S_tprg  S_tprg_227_2 = {&var1941,&fEM_A3UP85RDU,&fEM_A3UP86RDU,&fEM_A3UP87RDU,&fEM_A3UP88RDU,&var1961,&internal2_m227_y0};
_S_tprg  S_tprg_220_2 = {&var1942,&fEM_A3UP85RDU,&fEM_A3UP86RDU,&fEM_A3UP87RDU,&fEM_A3UP88RDU,&var1962,&internal2_m220_y0};
_S_geterr  S_geterr_200_2 = {&var1941,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1963};
_S_drg  S_drg_209_2 = {&var1941,&lRM_1_,&lRM_0_,&fEM_A3UP43RDU,&fEM_A3UP44RDU,&var1964,&internal2_m209_y1};
_S_drg  S_drg_216_2 = {&var1941,&lRM_1_,&lRM_0_,&fEM_A3UP53RDU,&fEM_A3UP54RDU,&var1965,&internal2_m216_y1};
_S_geterr  S_geterr_197_2 = {&var1942,&dRM_0_,&iRM_0_,&bRM_0_,&vainSChar,&vainSChar,&vainSChar,&vainSChar,&var1966};
_S_drg  S_drg_198_2 = {&var1942,&lRM_1_,&lRM_0_,&fEM_A3UP43RDU,&fEM_A3UP44RDU,&var1967,&internal2_m198_y1};
_S_drg  S_drg_206_2 = {&var1942,&lRM_1_,&lRM_0_,&fEM_A3UP53RDU,&fEM_A3UP54RDU,&var1968,&internal2_m206_y1};
_S_enctkb  S_enctkb_16_2 = {&var1902,&fRM_0_0,&A1IC01UDU,&dEM_A1UC06UDU,&dEM_A1UC05UDU,&fEM_A1UC03RDU,&fRM_100_,&dRM_0_,&var1969,&var1970,&var1971,&internal2_m16_Nk0,&internal2_m16_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_109_2 = {&var1897,&fRM_390_,&B8IC01UDU,&dEM_A8UC06UDU,&dEM_A8UC05UDU,&fEM_A8UC03RDU,&fRM_1500_0,&dRM_0_,&var1972,&var1973,&var1974,&internal2_m109_Nk0,&internal2_m109_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_112_2 = {&var1896,&fRM_390_0,&A8IC01UDU,&dEM_A8UC06UDU,&dEM_A8UC05UDU,&fEM_A8UC03RDU,&fRM_1500_0,&dRM_0_,&var1975,&var1976,&var1977,&internal2_m112_Nk0,&internal2_m112_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_77_2 = {&var1898,&fRM_0_,&B3IC01UDU,&dEM_A3UC06UDU,&dEM_A3UC05UDU,&fEM_A3UC03RDU,&fRM_0_0,&dRM_0_,&var1978,&var1979,&var1980,&internal2_m77_Nk0,&internal2_m77_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_83_2 = {&var1900,&fRM_0_0,&A3IC01UDU,&dEM_A3UC06UDU,&dEM_A3UC05UDU,&fEM_A3UC03RDU,&fRM_0_0,&dRM_0_,&var1981,&var1982,&var1983,&internal2_m83_Nk0,&internal2_m83_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_49_2 = {&var1901,&fRM_0_0,&B2IC01UDU,&dEM_A2UC06UDU,&dEM_A2UC05UDU,&fEM_A2UC03RDU,&fRM_100_,&dRM_0_,&var1984,&var1985,&var1986,&internal2_m49_Nk0,&internal2_m49_SetFlag,&bFirstEnterFlag};
_S_enctkb  S_enctkb_53_2 = {&var1899,&fRM_0_0,&A2IC01UDU,&dEM_A2UC06UDU,&dEM_A2UC05UDU,&fEM_A2UC03RDU,&fRM_100_,&dRM_0_,&var1987,&var1988,&var1989,&internal2_m53_Nk0,&internal2_m53_SetFlag,&bFirstEnterFlag};
_S_equz_p  S_equz_p_18_2 = {&R0MW12IP1,&iRM_4_,&var1990};
_S_enctkb  S_enctkb_21_2 = {&var1903,&fRM_0_0,&B1IC01UDU,&dEM_A1UC06UDU,&dEM_A1UC05UDU,&fEM_A1UC03RDU,&fRM_100_,&dRM_0_,&var1991,&var1992,&var1993,&internal2_m21_Nk0,&internal2_m21_SetFlag,&bFirstEnterFlag};
_S_ornc  S_ornc_124_2 = {array_m124_x_2,&iRM_8_,&var1994,&vainSChar};
_S_zzfs  S_zzfs_2556_1 = {&var392,&fRM_1_,&vainSBool,&internal1_m2556_tx,&internal1_m2556_y0};
_S_zzfs  S_zzfs_2558_1 = {&C2MD31LP1,&fRM_1_,&var1,&internal1_m2558_tx,&internal1_m2558_y0};
_S_zzfs  S_zzfs_2554_1 = {&var1043,&fRM_1_,&var2,&internal1_m2554_tx,&internal1_m2554_y0};
_S_zzfs  S_zzfs_2552_1 = {&var1153,&fRM_1_,&var3,&internal1_m2552_tx,&internal1_m2552_y0};
_S_zpfs  S_zpfs_221_1 = {&var1633,&fRM_1_,&var4,&internal1_m221_tx,&internal1_m221_y0};
_S_ovbsb  S_ovbsb_220_1 = {&var1918,&var5,&internal1_m220_tx};
_S_or2  S_or2_1229_1 = {&R2IS11LDU,&R1IS11LDU,&var6};
_S_or3  S_or3_1227_1 = {&A3IS21LDU,&B3IS21LDU,&var8,&var7};
_S_noto  S_noto_1234_1 = {&var9,&var8};
_S_and2  S_and2_1235_1 = {&var1568,&var1536,&var9};
_S_or3  S_or3_1225_1 = {&A1IS21LDU,&B1IS21LDU,&var11,&var10};
_S_noto  S_noto_1232_1 = {&var12,&var11};
_S_and2  S_and2_1233_1 = {&var1630,&var1597,&var12};
_S_or3  S_or3_1223_1 = {&A2IS21LDU,&B2IS21LDU,&var14,&var13};
_S_noto  S_noto_1230_1 = {&var15,&var14};
_S_and2  S_and2_1231_1 = {&var1718,&var1677,&var15};
_S_noto  S_noto_1221_1 = {&var6,&var16};
_S_or3  S_or3_1208_1 = {&R0MD34LP1,&var16,&var1231,&var17};
_S_noto  S_noto_1219_1 = {&var7,&var18};
_S_or3  S_or3_1205_1 = {&R0MD34LP1,&var18,&var1233,&var19};
_S_noto  S_noto_1217_1 = {&var10,&var20};
_S_or3  S_or3_1202_1 = {&R0MD34LP1,&var20,&var1235,&var21};
_S_noto  S_noto_1215_1 = {&var13,&var22};
_S_or3  S_or3_1199_1 = {&var1237,&var22,&R0MD34LP1,&var23};
_S_noto  S_noto_132_1 = {&var451,&var24};
_S_and2  S_and2_53_1 = {&var626,&var24,&var25};
_S_or2  S_or2_2307_1 = {&var399,&var701,&var26};
_S_or2  S_or2_2306_1 = {&var716,&var701,&var27};
_S_swtakt  S_swtakt_2101_1 = {&var1367,&var28,&fEM_R0UL00RDU,&var29,&internal1_m2101_x0,&internal1_m2101_tim};
_S_zpfs  S_zpfs_1677_1 = {&var1249,&fEM_R7UI76RDU,&var30,&internal1_m1677_tx,&internal1_m1677_y0};
_S_or4  S_or4_2546_1 = {&var1252,&var1247,&var1242,&var1250,&var31};
_S_or3  S_or3_2547_1 = {&var29,&var1254,&var31,&var32};
_S_or2  S_or2_1626_1 = {&var1862,&var1323,&var33};
_S_or2  S_or2_1619_1 = {&var1863,&var1322,&var34};
_S_or2  S_or2_1614_1 = {&var1864,&var1321,&var35};
_S_or2  S_or2_1610_1 = {&var1865,&var1320,&var36};
_S_or2  S_or2_1606_1 = {&var1866,&var1319,&var37};
_S_noto  S_noto_58_1 = {&var626,&vainSBool};
_S_and2  S_and2_1613_1 = {&var1864,&R0MD11LP2,&var38};
_S_and2  S_and2_1618_1 = {&var1863,&R0MD11LP2,&var39};
_S_and2  S_and2_1609_1 = {&var1865,&R0MD11LP2,&var40};
_S_and2  S_and2_1625_1 = {&var1862,&R0MD11LP2,&var41};
_S_and2  S_and2_1605_1 = {&var1866,&R0MD11LP2,&var42};
_S_and2  S_and2_1629_1 = {&var1317,&var1323,&var43};
_S_or2  S_or2_2088_1 = {&R8AD22LDU,&var654,&var44};
_S_period  S_period_79_1 = {&var1213,&lRM_1_,&iRM_5_,&fEM_R0UL01RSS,&fEM_R0UL02RSS,&fEM_R0UN03RSS,&var45,&internal1_m79_flst,&internal1_m79_chsr,&internal1_m79_chizm,&internal1_m79_sumtim,&internal1_m79_W1,&internal1_m79_W2,&internal1_m79_Wmin,&internal1_m79_Wmax,&internal1_m79_Wlast,&internal1_m79_y0,&internal1_m79_MyFirstEnterFlag};
_S_ovbsb  S_ovbsb_2066_1 = {&var619,&var46,&internal1_m2066_tx};
_S_ovbsb  S_ovbsb_2065_1 = {&var717,&var47,&internal1_m2065_tx};
_S_ovbsb  S_ovbsb_785_1 = {&var1118,&var48,&internal1_m785_tx};
_S_ovbsb  S_ovbsb_742_1 = {&var1117,&var49,&internal1_m742_tx};
_S_ovbsb  S_ovbsb_795_1 = {&var1120,&var50,&internal1_m795_tx};
_S_ovbsb  S_ovbsb_797_1 = {&var1119,&var51,&internal1_m797_tx};
_S_ovbsb  S_ovbsb_796_1 = {&var1121,&var52,&internal1_m796_tx};
_S_ovbsb  S_ovbsb_750_1 = {&var1089,&var53,&internal1_m750_tx};
_S_ovbsb  S_ovbsb_735_1 = {&var1094,&var54,&internal1_m735_tx};
_S_ovbsb  S_ovbsb_746_1 = {&var1091,&var55,&internal1_m746_tx};
_S_ovbsb  S_ovbsb_777_1 = {&var1124,&var56,&internal1_m777_tx};
_S_ovbsb  S_ovbsb_794_1 = {&var1123,&var57,&internal1_m794_tx};
_S_ovbsb  S_ovbsb_767_1 = {&var1127,&var58,&internal1_m767_tx};
_S_ovbsb  S_ovbsb_398_1 = {&var1833,&var59,&internal1_m398_tx};
_S_ovbsb  S_ovbsb_397_1 = {&var1832,&var60,&internal1_m397_tx};
_S_ovbsb  S_ovbsb_396_1 = {&var1834,&var61,&internal1_m396_tx};
_S_ovbsb  S_ovbsb_395_1 = {&var1831,&var62,&internal1_m395_tx};
_S_ovbsb  S_ovbsb_766_1 = {&var1128,&var63,&internal1_m766_tx};
_S_ovbsb  S_ovbsb_761_1 = {&var1131,&var64,&internal1_m761_tx};
_S_ovbsb  S_ovbsb_770_1 = {&var1132,&var65,&internal1_m770_tx};
_S_ovbsb  S_ovbsb_775_1 = {&var1126,&var66,&internal1_m775_tx};
_S_ovbsb  S_ovbsb_531_1 = {&var1652,&var67,&internal1_m531_tx};
_S_ovbsb  S_ovbsb_530_1 = {&var1651,&var68,&internal1_m530_tx};
_S_ovbsb  S_ovbsb_529_1 = {&var1653,&var69,&internal1_m529_tx};
_S_ovbsb  S_ovbsb_525_1 = {&var1650,&var70,&internal1_m525_tx};
_S_ovbsb  S_ovbsb_502_1 = {&var1661,&var71,&internal1_m502_tx};
_S_ovbsb  S_ovbsb_501_1 = {&var1660,&var72,&internal1_m501_tx};
_S_ovbsb  S_ovbsb_500_1 = {&var1662,&var73,&internal1_m500_tx};
_S_ovbsb  S_ovbsb_503_1 = {&var1659,&var74,&internal1_m503_tx};
_S_ovbsb  S_ovbsb_2472_1 = {&var444,&var75,&internal1_m2472_tx};
_S_ovbsb  S_ovbsb_2182_1 = {&var428,&var76,&internal1_m2182_tx};
_S_ovbsb  S_ovbsb_2471_1 = {&var448,&var77,&internal1_m2471_tx};
_S_ovbsb  S_ovbsb_2470_1 = {&var455,&var78,&internal1_m2470_tx};
_S_ovbsb  S_ovbsb_2467_1 = {&var456,&var79,&internal1_m2467_tx};
_S_ovbsb  S_ovbsb_108_1 = {&var576,&var80,&internal1_m108_tx};
_S_ovbsb  S_ovbsb_1148_1 = {&var846,&var81,&internal1_m1148_tx};
_S_ovbsb  S_ovbsb_2330_1 = {&var1496,&var82,&internal1_m2330_tx};
_S_ovbsb  S_ovbsb_2329_1 = {&var1497,&var83,&internal1_m2329_tx};
_S_ovbsb  S_ovbsb_2328_1 = {&var1495,&var84,&internal1_m2328_tx};
_S_ovbsb  S_ovbsb_1260_1 = {&var1066,&var85,&internal1_m1260_tx};
_S_ovbsb  S_ovbsb_1259_1 = {&var1067,&var86,&internal1_m1259_tx};
_S_ovbsb  S_ovbsb_1255_1 = {&var1068,&var87,&internal1_m1255_tx};
_S_ovbsb  S_ovbsb_1248_1 = {&var1072,&var88,&internal1_m1248_tx};
_S_ovbsb  S_ovbsb_1246_1 = {&var1069,&var89,&internal1_m1246_tx};
_S_ovbsb  S_ovbsb_1244_1 = {&var1070,&var90,&internal1_m1244_tx};
_S_ovbsb  S_ovbsb_1242_1 = {&var1071,&var91,&internal1_m1242_tx};
_S_ovbsb  S_ovbsb_1285_1 = {&var1751,&var92,&internal1_m1285_tx};
_S_ovbsb  S_ovbsb_1292_1 = {&var1752,&var93,&internal1_m1292_tx};
_S_ovbsb  S_ovbsb_1297_1 = {&var1765,&var94,&internal1_m1297_tx};
_S_ovbsb  S_ovbsb_1303_1 = {&var1221,&var95,&internal1_m1303_tx};
_S_ovbsb  S_ovbsb_1263_1 = {&var1065,&var96,&internal1_m1263_tx};
_S_ovbsb  S_ovbsb_1284_1 = {&var1759,&var97,&internal1_m1284_tx};
_S_ovbsb  S_ovbsb_1298_1 = {&var1760,&var98,&internal1_m1298_tx};
_S_ovbsb  S_ovbsb_480_1 = {&var1187,&var99,&internal1_m480_tx};
_S_ovbsb  S_ovbsb_474_1 = {&var1186,&var100,&internal1_m474_tx};
_S_ovbsb  S_ovbsb_476_1 = {&var1185,&var101,&internal1_m476_tx};
_S_ovbsb  S_ovbsb_478_1 = {&var1184,&var102,&internal1_m478_tx};
_S_ovbsb  S_ovbsb_485_1 = {&var618,&var103,&internal1_m485_tx};
_S_ovbsb  S_ovbsb_439_1 = {&var1842,&var104,&internal1_m439_tx};
_S_ovbsb  S_ovbsb_437_1 = {&var1843,&var105,&internal1_m437_tx};
_S_ovbsb  S_ovbsb_438_1 = {&var1841,&var106,&internal1_m438_tx};
_S_ovbsb  S_ovbsb_431_1 = {&var1840,&var107,&internal1_m431_tx};
_S_ovbsb  S_ovbsb_893_1 = {&var1815,&var108,&internal1_m893_tx};
_S_ovbsb  S_ovbsb_892_1 = {&var1814,&var109,&internal1_m892_tx};
_S_ovbsb  S_ovbsb_891_1 = {&var1816,&var110,&internal1_m891_tx};
_S_ovbsb  S_ovbsb_887_1 = {&var1813,&var111,&internal1_m887_tx};
_S_ovbsb  S_ovbsb_1349_1 = {&var1796,&var112,&internal1_m1349_tx};
_S_ovbsb  S_ovbsb_1348_1 = {&var1797,&var113,&internal1_m1348_tx};
_S_ovbsb  S_ovbsb_1347_1 = {&var1795,&var114,&internal1_m1347_tx};
_S_ovbsb  S_ovbsb_1560_1 = {&var888,&var115,&internal1_m1560_tx};
_S_ovbsb  S_ovbsb_1573_1 = {&var881,&var116,&internal1_m1573_tx};
_S_ovbsb  S_ovbsb_1572_1 = {&var882,&var117,&internal1_m1572_tx};
_S_ovbsb  S_ovbsb_1571_1 = {&var885,&var118,&internal1_m1571_tx};
_S_ovbsb  S_ovbsb_1562_1 = {&var1156,&var119,&internal1_m1562_tx};
_S_ovbsb  S_ovbsb_2300_1 = {&var382,&var120,&internal1_m2300_tx};
_S_ovbsb  S_ovbsb_2283_1 = {&var400,&var121,&internal1_m2283_tx};
_S_ovbsb  S_ovbsb_2260_1 = {&var395,&var122,&internal1_m2260_tx};
_S_ovbsb  S_ovbsb_1570_1 = {&var886,&var123,&internal1_m1570_tx};
_S_ovbsb  S_ovbsb_1550_1 = {&var890,&var124,&internal1_m1550_tx};
_S_ovbsb  S_ovbsb_1549_1 = {&var891,&var125,&internal1_m1549_tx};
_S_ovbsb  S_ovbsb_1547_1 = {&var892,&var126,&internal1_m1547_tx};
_S_ovbsb  S_ovbsb_1569_1 = {&var887,&var127,&internal1_m1569_tx};
_S_ovbsb  S_ovbsb_1535_1 = {&var896,&var128,&internal1_m1535_tx};
_S_ovbsb  S_ovbsb_1537_1 = {&var895,&var129,&internal1_m1537_tx};
_S_ovbsb  S_ovbsb_1534_1 = {&var897,&var130,&internal1_m1534_tx};
_S_ovbsb  S_ovbsb_1507_1 = {&var1548,&var131,&internal1_m1507_tx};
_S_ovbsb  S_ovbsb_1506_1 = {&var1547,&var132,&internal1_m1506_tx};
_S_ovbsb  S_ovbsb_1516_1 = {&var1553,&var133,&internal1_m1516_tx};
_S_ovbsb  S_ovbsb_1519_1 = {&var1228,&var134,&internal1_m1519_tx};
_S_ovbsb  S_ovbsb_986_1 = {&var921,&var135,&internal1_m986_tx};
_S_ovbsb  S_ovbsb_989_1 = {&var920,&var136,&internal1_m989_tx};
_S_ovbsb  S_ovbsb_2251_1 = {&var589,&var137,&internal1_m2251_tx};
_S_ovbsb  S_ovbsb_979_1 = {&var1165,&var138,&internal1_m979_tx};
_S_ovbsb  S_ovbsb_977_1 = {&var1166,&var139,&internal1_m977_tx};
_S_ovbsb  S_ovbsb_985_1 = {&var922,&var140,&internal1_m985_tx};
_S_ovbsb  S_ovbsb_969_1 = {&var926,&var141,&internal1_m969_tx};
_S_ovbsb  S_ovbsb_967_1 = {&var925,&var142,&internal1_m967_tx};
_S_ovbsb  S_ovbsb_963_1 = {&var924,&var143,&internal1_m963_tx};
_S_ovbsb  S_ovbsb_984_1 = {&var923,&var144,&internal1_m984_tx};
_S_ovbsb  S_ovbsb_949_1 = {&var930,&var145,&internal1_m949_tx};
_S_ovbsb  S_ovbsb_950_1 = {&var929,&var146,&internal1_m950_tx};
_S_ovbsb  S_ovbsb_952_1 = {&var928,&var147,&internal1_m952_tx};
_S_ovbsb  S_ovbsb_637_1 = {&var972,&var148,&internal1_m637_tx};
_S_ovbsb  S_ovbsb_640_1 = {&var1141,&var149,&internal1_m640_tx};
_S_ovbsb  S_ovbsb_639_1 = {&var1140,&var150,&internal1_m639_tx};
_S_ovbsb  S_ovbsb_628_1 = {&var473,&var151,&internal1_m628_tx};
_S_ovbsb  S_ovbsb_626_1 = {&var1160,&var152,&internal1_m626_tx};
_S_ovbsb  S_ovbsb_622_1 = {&var1161,&var153,&internal1_m622_tx};
_S_ovbsb  S_ovbsb_635_1 = {&var970,&var154,&internal1_m635_tx};
_S_ovbsb  S_ovbsb_612_1 = {&var974,&var155,&internal1_m612_tx};
_S_ovbsb  S_ovbsb_611_1 = {&var975,&var156,&internal1_m611_tx};
_S_ovbsb  S_ovbsb_607_1 = {&var978,&var157,&internal1_m607_tx};
_S_ovbsb  S_ovbsb_638_1 = {&var971,&var158,&internal1_m638_tx};
_S_ovbsb  S_ovbsb_595_1 = {&var976,&var159,&internal1_m595_tx};
_S_ovbsb  S_ovbsb_594_1 = {&var982,&var160,&internal1_m594_tx};
_S_ovbsb  S_ovbsb_597_1 = {&var983,&var161,&internal1_m597_tx};
_S_ovbsb  S_ovbsb_574_1 = {&var1608,&var162,&internal1_m574_tx};
_S_ovbsb  S_ovbsb_575_1 = {&var1609,&var163,&internal1_m575_tx};
_S_ovbsb  S_ovbsb_576_1 = {&var1614,&var164,&internal1_m576_tx};
_S_ovbsb  S_ovbsb_581_1 = {&var985,&var165,&internal1_m581_tx};
_S_ovbsb  S_ovbsb_2313_1 = {&var1501,&var166,&internal1_m2313_tx};
_S_ovbsb  S_ovbsb_2314_1 = {&var1503,&var167,&internal1_m2314_tx};
_S_ovbsb  S_ovbsb_2315_1 = {&var1502,&var168,&internal1_m2315_tx};
_S_ovbsb  S_ovbsb_1792_1 = {&var749,&var169,&internal1_m1792_tx};
_S_ovbsb  S_ovbsb_1791_1 = {&var750,&var170,&internal1_m1791_tx};
_S_ovbsb  S_ovbsb_1786_1 = {&var752,&var171,&internal1_m1786_tx};
_S_ovbsb  S_ovbsb_1777_1 = {&var753,&var172,&internal1_m1777_tx};
_S_ovbsb  S_ovbsb_1775_1 = {&var754,&var173,&internal1_m1775_tx};
_S_ovbsb  S_ovbsb_1773_1 = {&var755,&var174,&internal1_m1773_tx};
_S_ovbsb  S_ovbsb_1772_1 = {&var756,&var175,&internal1_m1772_tx};
_S_ovbsb  S_ovbsb_1813_1 = {&var1740,&var176,&internal1_m1813_tx};
_S_ovbsb  S_ovbsb_1821_1 = {&var1741,&var177,&internal1_m1821_tx};
_S_ovbsb  S_ovbsb_1828_1 = {&var1748,&var178,&internal1_m1828_tx};
_S_ovbsb  S_ovbsb_1829_1 = {&var1220,&var179,&internal1_m1829_tx};
_S_ovbsb  S_ovbsb_1819_1 = {&var1743,&var180,&internal1_m1819_tx};
_S_ovbsb  S_ovbsb_1794_1 = {&var748,&var181,&internal1_m1794_tx};
_S_ovbsb  S_ovbsb_1808_1 = {&var1742,&var182,&internal1_m1808_tx};
_S_ovbsb  S_ovbsb_457_1 = {&var1189,&var183,&internal1_m457_tx};
_S_ovbsb  S_ovbsb_448_1 = {&var1175,&var184,&internal1_m448_tx};
_S_ovbsb  S_ovbsb_449_1 = {&var394,&var185,&internal1_m449_tx};
_S_ovbsb  S_ovbsb_451_1 = {&var1190,&var186,&internal1_m451_tx};
_S_ovbsb  S_ovbsb_465_1 = {&var1188,&var187,&internal1_m465_tx};
_S_ovbsb  S_ovbsb_415_1 = {&var1849,&var188,&internal1_m415_tx};
_S_ovbsb  S_ovbsb_412_1 = {&var1851,&var189,&internal1_m412_tx};
_S_ovbsb  S_ovbsb_411_1 = {&var1850,&var190,&internal1_m411_tx};
_S_ovbsb  S_ovbsb_410_1 = {&var1852,&var191,&internal1_m410_tx};
_S_ovbsb  S_ovbsb_870_1 = {&var1822,&var192,&internal1_m870_tx};
_S_ovbsb  S_ovbsb_866_1 = {&var1824,&var193,&internal1_m866_tx};
_S_ovbsb  S_ovbsb_865_1 = {&var1823,&var194,&internal1_m865_tx};
_S_ovbsb  S_ovbsb_864_1 = {&var1825,&var195,&internal1_m864_tx};
_S_ovbsb  S_ovbsb_1330_1 = {&var1804,&var196,&internal1_m1330_tx};
_S_ovbsb  S_ovbsb_1327_1 = {&var1805,&var197,&internal1_m1327_tx};
_S_ovbsb  S_ovbsb_1326_1 = {&var1806,&var198,&internal1_m1326_tx};
_S_ovbsb  S_ovbsb_1087_1 = {&var649,&var199,&internal1_m1087_tx};
_S_ovbsb  S_ovbsb_2272_1 = {&var401,&var200,&internal1_m2272_tx};
_S_ovbsb  S_ovbsb_1098_1 = {&var902,&var201,&internal1_m1098_tx};
_S_ovbsb  S_ovbsb_1100_1 = {&var900,&var202,&internal1_m1100_tx};
_S_ovbsb  S_ovbsb_1099_1 = {&var899,&var203,&internal1_m1099_tx};
_S_ovbsb  S_ovbsb_2266_1 = {&var396,&var204,&internal1_m2266_tx};
_S_ovbsb  S_ovbsb_1089_1 = {&var1158,&var205,&internal1_m1089_tx};
_S_ovbsb  S_ovbsb_2271_1 = {&var385,&var206,&internal1_m2271_tx};
_S_ovbsb  S_ovbsb_1097_1 = {&var903,&var207,&internal1_m1097_tx};
_S_ovbsb  S_ovbsb_1079_1 = {&var907,&var208,&internal1_m1079_tx};
_S_ovbsb  S_ovbsb_1078_1 = {&var911,&var209,&internal1_m1078_tx};
_S_ovbsb  S_ovbsb_1074_1 = {&var905,&var210,&internal1_m1074_tx};
_S_ovbsb  S_ovbsb_1096_1 = {&var904,&var211,&internal1_m1096_tx};
_S_ovbsb  S_ovbsb_1064_1 = {&var910,&var212,&internal1_m1064_tx};
_S_ovbsb  S_ovbsb_1062_1 = {&var912,&var213,&internal1_m1062_tx};
_S_ovbsb  S_ovbsb_1061_1 = {&var913,&var214,&internal1_m1061_tx};
_S_ovbsb  S_ovbsb_1040_1 = {&var1579,&var215,&internal1_m1040_tx};
_S_ovbsb  S_ovbsb_1039_1 = {&var1580,&var216,&internal1_m1039_tx};
_S_ovbsb  S_ovbsb_1029_1 = {&var1585,&var217,&internal1_m1029_tx};
_S_ovbsb  S_ovbsb_1046_1 = {&var1229,&var218,&internal1_m1046_tx};
_S_ovbsb  S_ovbsb_1465_1 = {&var859,&var219,&internal1_m1465_tx};
_S_ovbsb  S_ovbsb_1464_1 = {&var860,&var220,&internal1_m1464_tx};
_S_ovbsb  S_ovbsb_2218_1 = {&var590,&var221,&internal1_m2218_tx};
_S_ovbsb  S_ovbsb_1455_1 = {&var863,&var222,&internal1_m1455_tx};
_S_ovbsb  S_ovbsb_1456_1 = {&var864,&var223,&internal1_m1456_tx};
_S_ovbsb  S_ovbsb_1463_1 = {&var861,&var224,&internal1_m1463_tx};
_S_ovbsb  S_ovbsb_1446_1 = {&var869,&var225,&internal1_m1446_tx};
_S_ovbsb  S_ovbsb_1445_1 = {&var867,&var226,&internal1_m1445_tx};
_S_ovbsb  S_ovbsb_1441_1 = {&var865,&var227,&internal1_m1441_tx};
_S_ovbsb  S_ovbsb_1462_1 = {&var862,&var228,&internal1_m1462_tx};
_S_ovbsb  S_ovbsb_1428_1 = {&var870,&var229,&internal1_m1428_tx};
_S_ovbsb  S_ovbsb_1426_1 = {&var868,&var230,&internal1_m1426_tx};
_S_ovbsb  S_ovbsb_1435_1 = {&var866,&var231,&internal1_m1435_tx};
_S_ovbsb  S_ovbsb_255_1 = {&var474,&var232,&internal1_m255_tx};
_S_ovbsb  S_ovbsb_270_1 = {&var948,&var233,&internal1_m270_tx};
_S_ovbsb  S_ovbsb_278_1 = {&var947,&var234,&internal1_m278_tx};
_S_ovbsb  S_ovbsb_277_1 = {&var949,&var235,&internal1_m277_tx};
_S_ovbsb  S_ovbsb_261_1 = {&var1163,&var236,&internal1_m261_tx};
_S_ovbsb  S_ovbsb_258_1 = {&var1164,&var237,&internal1_m258_tx};
_S_ovbsb  S_ovbsb_274_1 = {&var945,&var238,&internal1_m274_tx};
_S_ovbsb  S_ovbsb_246_1 = {&var954,&var239,&internal1_m246_tx};
_S_ovbsb  S_ovbsb_245_1 = {&var952,&var240,&internal1_m245_tx};
_S_ovbsb  S_ovbsb_241_1 = {&var951,&var241,&internal1_m241_tx};
_S_ovbsb  S_ovbsb_273_1 = {&var950,&var242,&internal1_m273_tx};
_S_ovbsb  S_ovbsb_230_1 = {&var958,&var243,&internal1_m230_tx};
_S_ovbsb  S_ovbsb_232_1 = {&var956,&var244,&internal1_m232_tx};
_S_ovbsb  S_ovbsb_228_1 = {&var957,&var245,&internal1_m228_tx};
_S_ovbsb  S_ovbsb_204_1 = {&var1645,&var246,&internal1_m204_tx};
_S_ovbsb  S_ovbsb_203_1 = {&var1646,&var247,&internal1_m203_tx};
_S_ovbsb  S_ovbsb_202_1 = {&var1647,&var248,&internal1_m202_tx};
_S_ovbsb  S_ovbsb_210_1 = {&var965,&var249,&internal1_m210_tx};
_S_ovbsb  S_ovbsb_1408_1 = {&var1735,&var250,&internal1_m1408_tx};
_S_ovbsb  S_ovbsb_1390_1 = {&var1730,&var251,&internal1_m1390_tx};
_S_ovbsb  S_ovbsb_1393_1 = {&var1729,&var252,&internal1_m1393_tx};
_S_ovbsb  S_ovbsb_1412_1 = {&var1230,&var253,&internal1_m1412_tx};
_S_ovbsb  S_ovbsb_929_1 = {&var1692,&var254,&internal1_m929_tx};
_S_ovbsb  S_ovbsb_934_1 = {&var938,&var255,&internal1_m934_tx};
_S_ovbsb  S_ovbsb_924_1 = {&var937,&var256,&internal1_m924_tx};
_S_ovbsb  S_ovbsb_925_1 = {&var936,&var257,&internal1_m925_tx};
_S_or3  S_or3_2531_1 = {&var261,&var260,&var259,&var258};
_S_or2  S_or2_2535_1 = {&R0DEB3LDU,&R0DEB4LDU,&var259};
_S_or2  S_or2_2529_1 = {&R0DEB1LDU,&R0DEB2LDU,&var260};
_S_diagndev  S_diagndev_2523_1 = {array_m2523_x_1,&iRM_14_,&var261,&var262};
_S_or2  S_or2_1914_1 = {&var493,&var311,&var263};
_S_and2  S_and2_1904_1 = {&var549,&var1444,&var264};
_S_rs  S_rs_1913_1 = {&var263,&var264,&var265,&vainSBool,&internal1_m1913_q0};
_S_or2  S_or2_1908_1 = {&var549,&var496,&var266};
_S_or2  S_or2_1851_1 = {&var1494,&var549,&var267};
_S_or2  S_or2_1879_1 = {&var548,&var311,&var268};
_S_or2  S_or2_1881_1 = {&var381,&var311,&var269};
_S_or2  S_or2_2362_1 = {&var493,&var307,&var270};
_S_or2  S_or2_2360_1 = {&var307,&var500,&var271};
_S_or2  S_or2_2358_1 = {&var320,&var307,&var272};
_S_and2  S_and2_2341_1 = {&var1441,&var547,&var273};
_S_or2  S_or2_2356_1 = {&var547,&var307,&var274};
_S_noto  S_noto_2364_1 = {&B3IS11LDU,&var275};
_S_or2  S_or2_2391_1 = {&var311,&var500,&var276};
_S_and2  S_and2_2371_1 = {&var1441,&var548,&var277};
_S_noto  S_noto_2395_1 = {&A3IS11LDU,&var278};
_S_or2  S_or2_2393_1 = {&var493,&var311,&var279};
_S_or2  S_or2_2389_1 = {&var311,&var321,&var280};
_S_or2  S_or2_2387_1 = {&var311,&var548,&var281};
_S_or2  S_or2_1859_1 = {&var493,&var311,&var282};
_S_or2  S_or2_1863_1 = {&var493,&var307,&var283};
_S_or2  S_or2_1854_1 = {&var549,&var1494,&var284};
_S_or2  S_or2_1889_1 = {&var307,&var380,&var285};
_S_or2  S_or2_1887_1 = {&var547,&var307,&var286};
_S_or2  S_or2_1930_1 = {&var500,&var307,&var287};
_S_or2  S_or2_1927_1 = {&var500,&var311,&var288};
_S_or2  S_or2_1959_1 = {&var506,&var307,&var289};
_S_or2  S_or2_1956_1 = {&var506,&var311,&var290};
_S_or2  S_or2_1916_1 = {&var493,&var307,&var291};
_S_or2  S_or2_1883_1 = {&var493,&var311,&var292};
_S_or2  S_or2_1891_1 = {&var493,&var307,&var293};
_S_or3  S_or3_2352_1 = {&var500,&var547,&var307,&var294};
_S_or3  S_or3_2354_1 = {&var550,&var547,&var307,&var295};
_S_or3  S_or3_2385_1 = {&var311,&var551,&var548,&var296};
_S_or3  S_or3_2383_1 = {&var500,&var311,&var548,&var297};
_S_or3  S_or3_2350_1 = {&var547,&var493,&var307,&var298};
_S_or3  S_or3_2381_1 = {&var493,&var548,&var311,&var299};
_S_or3  S_or3_1857_1 = {&var493,&var548,&var311,&var300};
_S_or3  S_or3_1861_1 = {&var547,&var493,&var307,&var301};
_S_or3  S_or3_1877_1 = {&var493,&var548,&var311,&var302};
_S_or3  S_or3_1885_1 = {&var493,&var547,&var307,&var303};
_S_or3  S_or3_1912_1 = {&var493,&var549,&var307,&var304};
_S_or3  S_or3_1910_1 = {&var493,&var311,&var549,&var305};
_S_or3  S_or3_1958_1 = {&var307,&var547,&var506,&var306};
_S_noto  S_noto_1953_1 = {&var1147,&var307};
_S_or3  S_or3_1929_1 = {&var307,&var500,&var547,&var308};
_S_or3  S_or3_1926_1 = {&var500,&var311,&var548,&var309};
_S_or3  S_or3_1955_1 = {&var506,&var311,&var548,&var310};
_S_noto  S_noto_1946_1 = {&var1146,&var311};
_S_regch  S_regch_133_1 = {&R0MW12IP1,&var1136,&var312};
_S_or2  S_or2_136_1 = {&var314,&var312,&var313};
_S_or2  S_or2_135_1 = {&R0VZ71LZ1,&R0VZ71LZ2,&var314};
_S_and3  S_and3_1595_1 = {&R0MD11LP2,&var1195,&var318,&var315};
_S_and2  S_and2_817_1 = {&R4MD21LP2,&var318,&var316};
_S_and2  S_and2_815_1 = {&R4MD11LP2,&var318,&var317};
_S_noto  S_noto_114_1 = {&var1871,&var318};
_S_and2  S_and2_112_1 = {&R0MD11LP1,&var318,&var319};
_S_noto  S_noto_2365_1 = {&B3IS22LDU,&var320};
_S_noto  S_noto_2396_1 = {&A3IS22LDU,&var321};
_S_and2  S_and2_2281_1 = {&var713,&var1423,&var322};
_S_or3  S_or3_2274_1 = {&var712,&var420,&var362,&var323};
_S_and2  S_and2_2263_1 = {&var709,&var1423,&var324};
_S_or3  S_or3_2259_1 = {&var420,&var710,&var345,&var325};
_S_or2  S_or2_1675_1 = {&var1251,&var1441,&var326};
_S_or2  S_or2_1640_1 = {&var1248,&var1441,&var327};
_S_rs  S_rs_2355_1 = {&var274,&var331,&var328,&vainSBool,&internal1_m2355_q0};
_S_rs  S_rs_2339_1 = {&var275,&var350,&var329,&vainSBool,&internal1_m2339_q0};
_S_noto  S_noto_2363_1 = {&var1965,&var330};
_S_and2  S_and2_2346_1 = {&var330,&var329,&var331};
_S_rs  S_rs_2386_1 = {&var281,&var334,&var332,&vainSBool,&internal1_m2386_q0};
_S_noto  S_noto_2394_1 = {&var1968,&var333};
_S_and2  S_and2_2377_1 = {&var335,&var333,&var334};
_S_rs  S_rs_2370_1 = {&var278,&var368,&var335,&vainSBool,&internal1_m2370_q0};
_S_and4  S_and4_1541_1 = {&var1195,&var1441,&var511,&var1486,&var336};
_S_and4  S_and4_1068_1 = {&var1195,&var1441,&var511,&var1486,&var337};
_S_rs  S_rs_2361_1 = {&var270,&var343,&var338,&vainSBool,&internal1_m2361_q0};
_S_or4  S_or4_1471_1 = {&var831,&var533,&var1234,&var345,&var339};
_S_or4  S_or4_1480_1 = {&var409,&var536,&var1007,&var351,&var340};
_S_orn  S_orn_898_1 = {array_m898_x_1,&iRM_6_,&var341};
_S_or3  S_or3_910_1 = {&var1026,&var1437,&var354,&var342};
_S_and2  S_and2_2348_1 = {&var500,&var344,&var343};
_S_rs  S_rs_2342_1 = {&var270,&var346,&var344,&vainSBool,&internal1_m2342_q0};
_S_rs  S_rs_2359_1 = {&var271,&var346,&var345,&vainSBool,&internal1_m2359_q0};
_S_and2  S_and2_2347_1 = {&var347,&var320,&var346};
_S_rs  S_rs_2340_1 = {&var271,&var273,&var347,&vainSBool,&internal1_m2340_q0};
_S_rs  S_rs_2338_1 = {&var330,&var352,&var348,&vainSBool,&internal1_m2338_q0};
_S_rs  S_rs_2337_1 = {&var294,&var353,&var349,&vainSBool,&internal1_m2337_q0};
_S_and2  S_and2_2345_1 = {&var500,&var348,&var350};
_S_rs  S_rs_2351_1 = {&var294,&var352,&var351,&vainSBool,&internal1_m2351_q0};
_S_and2  S_and2_2344_1 = {&var349,&var493,&var352};
_S_and2  S_and2_2343_1 = {&var550,&var1441,&var353};
_S_rs  S_rs_2349_1 = {&var298,&var353,&var354,&vainSBool,&internal1_m2349_q0};
_S_rs  S_rs_2357_1 = {&var272,&var273,&var355,&vainSBool,&internal1_m2357_q0};
_S_rs  S_rs_2353_1 = {&var295,&var350,&var356,&vainSBool,&internal1_m2353_q0};
_S_orn  S_orn_1359_1 = {array_m1359_x_1,&iRM_6_,&var357};
_S_rs  S_rs_2392_1 = {&var279,&var359,&var358,&vainSBool,&internal1_m2392_q0};
_S_and2  S_and2_2379_1 = {&var500,&var360,&var359};
_S_rs  S_rs_2373_1 = {&var279,&var363,&var360,&vainSBool,&internal1_m2373_q0};
_S_or4  S_or4_993_1 = {&var830,&var537,&var1234,&var362,&var361};
_S_rs  S_rs_2390_1 = {&var276,&var363,&var362,&vainSBool,&internal1_m2390_q0};
_S_and2  S_and2_2378_1 = {&var364,&var321,&var363};
_S_rs  S_rs_2372_1 = {&var276,&var277,&var364,&vainSBool,&internal1_m2372_q0};
_S_rs  S_rs_2369_1 = {&var333,&var371,&var365,&vainSBool,&internal1_m2369_q0};
_S_or4  S_or4_1002_1 = {&var1434,&var409,&var1017,&var369,&var366};
_S_rs  S_rs_2368_1 = {&var297,&var372,&var367,&vainSBool,&internal1_m2368_q0};
_S_and2  S_and2_2376_1 = {&var500,&var365,&var368};
_S_rs  S_rs_2382_1 = {&var297,&var371,&var369,&vainSBool,&internal1_m2382_q0};
_S_or3  S_or3_1371_1 = {&var1025,&var1439,&var373,&var370};
_S_and2  S_and2_2375_1 = {&var367,&var493,&var371};
_S_and2  S_and2_2374_1 = {&var551,&var1441,&var372};
_S_rs  S_rs_2380_1 = {&var299,&var372,&var373,&vainSBool,&internal1_m2380_q0};
_S_or2  S_or2_2241_1 = {&var411,&var1270,&var374};
_S_ovbs  S_ovbs_2243_1 = {&var469,&fRM_2_0,&var375,&internal1_m2243_tx};
_S_or2  S_or2_2244_1 = {&var1450,&var375,&var376};
_S_ovbs  S_ovbs_2222_1 = {&var470,&fRM_2_0,&var377,&internal1_m2222_tx};
_S_or2  S_or2_2220_1 = {&var412,&var1271,&var378};
_S_or2  S_or2_2223_1 = {&var1470,&var377,&var379};
_S_noto  S_noto_1893_1 = {&B2IS21LDU,&var380};
_S_noto  S_noto_1892_1 = {&A2IS21LDU,&var381};
_S_and2  S_and2_2301_1 = {&var1965,&var714,&var382};
_S_or5  S_or5_2304_1 = {&var888,&var1880,&var26,&var355,&var382,&var383};
_S_or5  S_or5_2303_1 = {&var649,&var1432,&var27,&var1880,&var385,&var384};
_S_and2  S_and2_2276_1 = {&var1968,&var715,&var385};
_S_nocnm  S_nocnm_1937_1 = {&R5IS21LDU,&R5IS11LDU,&var386,&var387,&var388,&internal1_m1937_Pv0,&internal1_m1937_Zv0,&internal1_m1937_MyFirstEnterFlag,&bFirstEnterFlag};
_S_nocnm  S_nocnm_1934_1 = {&R3IS11LDU,&R3IS21LDU,&var389,&var390,&var391,&internal1_m1934_Pv0,&internal1_m1934_Zv0,&internal1_m1934_MyFirstEnterFlag,&bFirstEnterFlag};
_S_or5  S_or5_2190_1 = {&var1230,&var938,&C2MD31LP1,&var1229,&var1228,&var392};
_S_or4  S_or4_2165_1 = {&C1MD31LP2,&C1MD31LP1,&var965,&var985,&var393};
_S_and3  S_and3_454_1 = {&B8IS22LDU,&B8IS21LDU,&var1853,&var394};
_S_and2  S_and2_2261_1 = {&var708,&var420,&var395};
_S_and2  S_and2_2267_1 = {&var711,&var420,&var396};
_S_or4  S_or4_1109_1 = {&var1559,&var900,&var899,&var902,&var397};
_S_or4  S_or4_1583_1 = {&var1527,&var882,&var881,&var885,&var398};
_S_and2  S_and2_2305_1 = {&var639,&var1423,&var399};
_S_and2  S_and2_2290_1 = {&var714,&var1880,&var400};
_S_and2  S_and2_2277_1 = {&var715,&var1880,&var401};
_S_or2  S_or2_618_1 = {&B1VP41LZ2,&B1VP41LZ1,&var402};
_S_or2  S_or2_252_1 = {&A1VP41LZ2,&A1VP41LZ1,&var403};
_S_or2  S_or2_1276_1 = {&B8IS22LDU,&B8IS21LDU,&var404};
_S_or2  S_or2_1270_1 = {&B8IS11LDU,&B8IS12LDU,&var405};
_S_or2  S_or2_380_1 = {&R4IS11LDU,&R4IS12LDU,&var406};
_S_or2  S_or2_393_1 = {&R4IS21LDU,&R4IS22LDU,&var407};
_S_noto  S_noto_2421_1 = {&var1880,&var408};
_S_zzfs  S_zzfs_2410_1 = {&var426,&fRM_0_5,&var409,&internal1_m2410_tx,&internal1_m2410_y0};
_S_or2  S_or2_2444_1 = {&var601,&var1239,&var410};
_S_andn  S_andn_666_1 = {array_m666_x_1,&iRM_6_,&var411};
_S_andn  S_andn_665_1 = {array_m665_x_1,&iRM_6_,&var412};
_S_or2  S_or2_2458_1 = {&var915,&var880,&var413};
_S_noto  S_noto_2406_1 = {&var1269,&var414};
_S_noto  S_noto_2405_1 = {&var1266,&var415};
_S_zpfs  S_zpfs_2414_1 = {&var414,&fRM_30_0,&var416,&internal1_m2414_tx,&internal1_m2414_y0};
_S_noto  S_noto_2419_1 = {&var416,&var417};
_S_zpfs  S_zpfs_2413_1 = {&var415,&fRM_30_0,&var418,&internal1_m2413_tx,&internal1_m2413_y0};
_S_noto  S_noto_2418_1 = {&var418,&var419};
_S_and3  S_and3_2412_1 = {&var458,&var439,&lRM_1_,&var420};
_S_and2  S_and2_1021_1 = {&var1585,&var422,&var421};
_S_noto  S_noto_1009_1 = {&var409,&var422};
_S_and2  S_and2_1497_1 = {&var1553,&var424,&var423};
_S_noto  S_noto_1494_1 = {&var409,&var424};
_S_or2  S_or2_2454_1 = {&var435,&var436,&var425};
_S_and2  S_and2_2409_1 = {&var427,&var420,&var426};
_S_abs_subf  S_abs_subf_2401_1 = {&var1981,&var459,&fEM_A3UC08RDU,&vainSFloat,&var427};
_S_and2  S_and2_2456_1 = {&var420,&var435,&var428};
_S_or4  S_or4_2191_1 = {&var392,&var1043,&var1153,&var428,&var429};
_S_noto  S_noto_2457_1 = {&var413,&var430};
_S_or2  S_or2_2435_1 = {&var452,&var463,&var431};
_S_inf  S_inf_2430_1 = {&var461,array_m2430_a_1,array_m2430_b_1,&iRM_6_,&var432,&vainSInt};
_S_or3  S_or3_2462_1 = {&var448,&var455,&var456,&var433};
_S_noto  S_noto_2461_1 = {&var433,&var434};
_S_noto  S_noto_2455_1 = {&var458,&var435};
_S_ovbs  S_ovbs_2450_1 = {&var438,&fRM_15_0,&var436,&internal1_m2450_tx};
_S_zpfs  S_zpfs_2448_1 = {&var439,&fRM_10_0,&var437,&internal1_m2448_tx,&internal1_m2448_y0};
_S_and2  S_and2_2449_1 = {&var437,&R0MW17LP1,&var438};
_S_rs  S_rs_2453_1 = {&var425,&R0MW17LP1,&var439,&vainSBool,&internal1_m2453_q0};
_S_rs  S_rs_2420_1 = {&var452,&var420,&var440,&vainSBool,&internal1_m2420_q0};
_S_and3  S_and3_2427_1 = {&var454,&var408,&var440,&var441};
_S_ml  S_ml_1477_1 = {&var459,&var561,&var409,&var442};
_S_ml  S_ml_996_1 = {&var459,&var565,&var409,&var443};
_S_and2  S_and2_2478_1 = {&var420,&var578,&var444};
_S_noto  S_noto_2440_1 = {&var410,&var445};
_S_noto  S_noto_2425_1 = {&var1524,&var446};
_S_sr  S_sr_2441_1 = {array_m2441_x_1,&iRM_4_,&var447};
_S_and2  S_and2_2479_1 = {&var449,&var420,&var448};
_S_abs_subf  S_abs_subf_2475_1 = {&B3MC01RP1,&A3MC01RP1,&fRM_0_01,&vainSFloat,&var449};
_S_fsumo  S_fsumo_86_1 = {&var1215,&fEM_R0UN11RDU,&var450};
_S_or3  S_or3_134_1 = {&var393,&var313,&var431,&var451};
_S_ovbs  S_ovbs_2428_1 = {&var441,&fRM_1_0,&var452,&internal1_m2428_tx};
_S_noto  S_noto_2434_1 = {&var431,&var453};
_S_rs  S_rs_2426_1 = {&var452,&var1880,&var454,&vainSBool,&internal1_m2426_q0};
_S_and2  S_and2_2476_1 = {&var463,&var420,&var455};
_S_and2  S_and2_2473_1 = {&var457,&var420,&var456};
_S_bol  S_bol_2465_1 = {&fEM_R0UN09RDU,&var45,&var457};
_S_andn  S_andn_2433_1 = {array_m2433_x_1,&iRM_14_,&var458};
_S_irm  S_irm_2408_1 = {&var1215,&var1213,&B3MC01RP1,&var1981,&var45,&var447,&var420,&var1239,&fEM_R0UN12RDU,&fEM_R0UN13RDU,&fEM_R0UN14RDU,&fEM_R0UT20RDU,&var432,&fEM_R0UN15RDU,&fEM_R0UN25RDU,&fEM_R0UN16RDU,&fEM_R0UN17RDU,&fEM_R0UN18RDU,&fEM_R0UN19RDU,&fEM_R0UN27RDU,&fEM_R0UN26RDU,&fEM_R0UN24RDU,&var459,&var460,&var461,&var462,&var463,&var464,&var465,&var466,&internal1_m2408_fVf0,&internal1_m2408_fRsg,&internal1_m2408_fRct,&internal1_m2408_fVfMin,&internal1_m2408_fStw0,&internal1_m2408_fMaxDk,&internal1_m2408_fkizm,&internal1_m2408_fwt0,&internal1_m2408_fwz0,&internal1_m2408_ftf0,&internal1_m2408_fTk0,&internal1_m2408_FlPar,&internal1_m2408_FlIzm,&internal1_m2408_FlCmp,&internal1_m2408_StabCoun,&internal1_m2408_ZerCoun,&internal1_m2408_SrCoun,&internal1_m2408_LastStage,&internal1_m2408_fef};
_S_noto  S_noto_2250_1 = {&var589,&var467};
_S_noto  S_noto_2219_1 = {&var590,&var468};
_S_and4  S_and4_2242_1 = {&var612,&var374,&var582,&var467,&var469};
_S_and4  S_and4_2221_1 = {&var613,&var378,&var582,&var468,&var470};
_S_zpfs  S_zpfs_2237_1 = {&var596,&fRM_210_0,&var471,&internal1_m2237_tx,&internal1_m2237_y0};
_S_zpfs  S_zpfs_2229_1 = {&var597,&fRM_210_0,&var472,&internal1_m2229_tx,&internal1_m2229_y0};
_S_and2  S_and2_621_1 = {&var1600,&var643,&var473};
_S_and2  S_and2_256_1 = {&var643,&var1633,&var474};
_S_noto  S_noto_1765_1 = {&var476,&var475};
_S_abs_subf  S_abs_subf_1755_1 = {&var1978,&var561,&fEM_A3UC07RDU,&vainSFloat,&var476};
_S_noto  S_noto_1746_1 = {&var478,&var477};
_S_abs_subf  S_abs_subf_1735_1 = {&var565,&var1981,&fEM_A3UC07RDU,&vainSFloat,&var478};
_S_noto  S_noto_1760_1 = {&var480,&var479};
_S_abs_subf  S_abs_subf_1754_1 = {&var569,&var1991,&fEM_A1UC07RDU,&vainSFloat,&var480};
_S_noto  S_noto_1740_1 = {&var482,&var481};
_S_abs_subf  S_abs_subf_1733_1 = {&var573,&var1969,&fEM_A1UC07RDU,&vainSFloat,&var482};
_S_bol  S_bol_1493_1 = {&var1978,&fEM_A3UC09RDU,&var483};
_S_bol  S_bol_1018_1 = {&var1981,&fEM_A3UC09RDU,&var484};
_S_noto  S_noto_2000_1 = {&var489,&var485};
_S_noto  S_noto_1989_1 = {&var487,&var486};
_S_and3  S_and3_1982_1 = {&var1147,&var488,&var1441,&var487};
_S_bol  S_bol_1974_1 = {&fRM_55_0,&var561,&var488};
_S_and3  S_and3_2001_1 = {&var490,&var1146,&var1441,&var489};
_S_bol  S_bol_2010_1 = {&fRM_55_0,&var565,&var490};
_S_and4  S_and4_45_1 = {&var1871,&var1145,&var1328,&var1423,&var491};
_S_noto  S_noto_1391_1 = {&var1195,&var492};
_S_and2  S_and2_1396_1 = {&var1700,&var1195,&var493};
_S_and2  S_and2_1392_1 = {&var1700,&var492,&var494};
_S_noto  S_noto_1337_1 = {&var1195,&var495};
_S_and2  S_and2_1344_1 = {&var1195,&var1774,&var496};
_S_and2  S_and2_1338_1 = {&var1774,&var495,&var497};
_S_noto  S_noto_1025_1 = {&var1195,&var498};
_S_and2  S_and2_1026_1 = {&var498,&var1556,&var499};
_S_and2  S_and2_1023_1 = {&var1556,&var1195,&var500};
_S_noto  S_noto_518_1 = {&var1195,&var501};
_S_and2  S_and2_519_1 = {&var501,&var1649,&var502};
_S_and2  S_and2_522_1 = {&var1649,&var1195,&var503};
_S_noto  S_noto_195_1 = {&var1195,&var504};
_S_and2  S_and2_196_1 = {&var504,&var1619,&var505};
_S_and2  S_and2_198_1 = {&var1195,&var1619,&var506};
_S_and2  S_and2_128_1 = {&var509,&var633,&var507};
_S_and2  S_and2_129_1 = {&var1195,&var633,&var508};
_S_noto  S_noto_123_1 = {&var1195,&var509};
_S_and2  S_and2_124_1 = {&var509,&var632,&var510};
_S_and2  S_and2_125_1 = {&var1195,&var632,&var511};
_S_and2  S_and2_1849_1 = {&var547,&var1445,&var512};
_S_and2  S_and2_1848_1 = {&var550,&var1445,&var513};
_S_and2  S_and2_1847_1 = {&var548,&var1445,&var514};
_S_and2  S_and2_1846_1 = {&var1445,&var551,&var515};
_S_and2  S_and2_1845_1 = {&var757,&var549,&var516};
_S_and2  S_and2_1844_1 = {&var757,&var552,&var517};
_S_and2  S_and2_1843_1 = {&var758,&var549,&var518};
_S_and2  S_and2_1842_1 = {&var758,&var552,&var519};
_S_and2  S_and2_1875_1 = {&var285,&var1404,&var520};
_S_and2  S_and2_1874_1 = {&var547,&var1446,&var521};
_S_and2  S_and2_1873_1 = {&var1405,&var493,&var522};
_S_and2  S_and2_1872_1 = {&var1446,&var550,&var523};
_S_and2  S_and2_1871_1 = {&var381,&var1406,&var524};
_S_and2  S_and2_1870_1 = {&var1446,&var548,&var525};
_S_and2  S_and2_1869_1 = {&var1407,&var493,&var526};
_S_and2  S_and2_1868_1 = {&var1446,&var551,&var527};
_S_and2  S_and2_1906_1 = {&var493,&var1408,&var528};
_S_and2  S_and2_1905_1 = {&var549,&var1444,&var529};
_S_and2  S_and2_1903_1 = {&var1409,&var496,&var530};
_S_and2  S_and2_1902_1 = {&var1410,&var496,&var531};
_S_and2  S_and2_1901_1 = {&var552,&var1444,&var532};
_S_rs  S_rs_1923_1 = {&var287,&var534,&var533,&vainSBool,&internal1_m1923_q0};
_S_and2  S_and2_1922_1 = {&var1442,&var547,&var534};
_S_and2  S_and2_1921_1 = {&var1442,&var550,&var535};
_S_rs  S_rs_1928_1 = {&var308,&var535,&var536,&vainSBool,&internal1_m1928_q0};
_S_rs  S_rs_1920_1 = {&var288,&var538,&var537,&vainSBool,&internal1_m1920_q0};
_S_and2  S_and2_1919_1 = {&var548,&var1442,&var538};
_S_and2  S_and2_1918_1 = {&var1442,&var551,&var539};
_S_and2  S_and2_1952_1 = {&var549,&var1873,&var540};
_S_rs  S_rs_1962_1 = {&var503,&var540,&var541,&vainSBool,&internal1_m1962_q0};
_S_and2  S_and2_1951_1 = {&var1873,&var552,&var542};
_S_and2  S_and2_1949_1 = {&var547,&var1430,&var543};
_S_and2  S_and2_1948_1 = {&var1430,&var550,&var544};
_S_and2  S_and2_1945_1 = {&var548,&var1430,&var545};
_S_and2  S_and2_1944_1 = {&var1430,&var551,&var546};
_S_and2  S_and2_1964_1 = {&var1147,&var549,&var547};
_S_and2  S_and2_1943_1 = {&var1146,&var549,&var548};
_S_and2  S_and2_1966_1 = {&var508,&var1486,&var549};
_S_and2  S_and2_1963_1 = {&var552,&var1147,&var550};
_S_and2  S_and2_1942_1 = {&var552,&var1146,&var551};
_S_and2  S_and2_1965_1 = {&var511,&var1486,&var552};
_S_zpfs  S_zpfs_834_1 = {&var1111,&fRM_3_,&var553,&internal1_m834_tx,&internal1_m834_y0};
_S_or4  S_or4_1779_1 = {&var748,&var749,&var750,&var752,&var554};
_S_or5  S_or5_1766_1 = {&var756,&var755,&var754,&var753,&var554,&var555};
_S_andn  S_andn_1_1 = {array_m1_x_1,&iRM_47_,&vainSBool};
_S_or2  S_or2_1748_1 = {&var558,&var559,&var556};
_S_ml  S_ml_1732_1 = {&fRM_1500_0,&B8MC01RP2,&var556,&var557};
_S_bol  S_bol_1744_1 = {&B8MC01RP2,&fRM_1500_0001,&var558};
_S_bol  S_bol_1749_1 = {&fRM_389_99,&B8MC01RP2,&var559};
_S_or2  S_or2_1761_1 = {&var562,&var563,&var560};
_S_ml  S_ml_1753_1 = {&fRM_0_0,&B3MC01RP1,&var560,&var561};
_S_bol  S_bol_1757_1 = {&B3MC01RP1,&fRM_160_00001,&var562};
_S_bol  S_bol_1764_1 = {&fRM_0_0001,&B3MC01RP1,&var563};
_S_or2  S_or2_1743_1 = {&var566,&var567,&var564};
_S_ml  S_ml_1731_1 = {&fRM_0_0,&A3MC01RP1,&var564,&var565};
_S_bol  S_bol_1734_1 = {&A3MC01RP1,&fRM_160_0001,&var566};
_S_bol  S_bol_1745_1 = {&fRM_0_0001,&A3MC01RP1,&var567};
_S_or2  S_or2_1759_1 = {&var570,&var571,&var568};
_S_ml  S_ml_1751_1 = {&fRM_100_0,&B1MC01RP1,&var568,&var569};
_S_bol  S_bol_1756_1 = {&B1MC01RP1,&fRM_100_0001,&var570};
_S_bol  S_bol_1762_1 = {&fRM_0_0001,&B1MC01RP1,&var571};
_S_or2  S_or2_1739_1 = {&var574,&var575,&var572};
_S_ml  S_ml_1729_1 = {&fRM_100_0,&A1MC01RP1,&var572,&var573};
_S_bol  S_bol_1737_1 = {&A1MC01RP1,&fRM_100_0001,&var574};
_S_bol  S_bol_1741_1 = {&fRM_0_0001,&A1MC01RP1,&var575};
_S_and2  S_and2_109_1 = {&var319,&var406,&var576};
_S_noto  S_noto_110_1 = {&var406,&var577};
_S_and2  S_and2_113_1 = {&var319,&var577,&var578};
_S_and2  S_and2_2207_1 = {&var580,&var581,&var579};
_S_or3  S_or3_2206_1 = {&var1448,&var701,&var429,&var580};
_S_noto  S_noto_2245_1 = {&var376,&var581};
_S_noto  S_noto_2234_1 = {&var583,&var582};
_S_ovbs  S_ovbs_2233_1 = {&var1340,&fRM_2_0,&var583,&internal1_m2233_tx};
_S_noto  S_noto_2224_1 = {&var379,&var584};
_S_and2  S_and2_2193_1 = {&var586,&var584,&var585};
_S_or3  S_or3_2192_1 = {&var429,&var1452,&var701,&var586};
_S_noto  S_noto_2239_1 = {&var594,&var587};
_S_and2  S_and2_2240_1 = {&var1423,&var587,&var588};
_S_and2  S_and2_2248_1 = {&var588,&var374,&var589};
_S_and2  S_and2_2227_1 = {&var591,&var378,&var590};
_S_and2  S_and2_2232_1 = {&var592,&var1423,&var591};
_S_noto  S_noto_2231_1 = {&var1138,&var592};
_S_noto  S_noto_2247_1 = {&var596,&var593};
_S_or2  S_or2_2238_1 = {&var471,&var593,&var594};
_S_noto  S_noto_2226_1 = {&var597,&var595};
_S_rs  S_rs_2236_1 = {&var471,&var602,&var596,&vainSBool,&internal1_m2236_q0};
_S_rs  S_rs_2228_1 = {&var472,&var603,&var597,&vainSBool,&internal1_m2228_q0};
_S_and2  S_and2_2216_1 = {&var600,&var607,&var598};
_S_and2  S_and2_2204_1 = {&var600,&var604,&var599};
_S_noto  S_noto_2198_1 = {&var601,&var600};
_S_ovbs  S_ovbs_2197_1 = {&var429,&fRM_10_0,&var601,&internal1_m2197_tx};
_S_ovbs  S_ovbs_2208_1 = {&var579,&fRM_2_0,&var602,&internal1_m2208_tx};
_S_ovbs  S_ovbs_2194_1 = {&var585,&fRM_2_0,&var603,&internal1_m2194_tx};
_S_or2  S_or2_2203_1 = {&var634,&var1200,&var604};
_S_or2  S_or2_2199_1 = {&var635,&var585,&var605};
_S_or2  S_or2_2211_1 = {&var635,&var579,&var606};
_S_or2  S_or2_2215_1 = {&var634,&var1197,&var607};
_S_rs  S_rs_2200_1 = {&var599,&var605,&var608,&vainSBool,&internal1_m2200_q0};
_S_noto  S_noto_2213_1 = {&var610,&var609};
_S_rs  S_rs_2212_1 = {&var598,&var606,&var610,&vainSBool,&internal1_m2212_q0};
_S_noto  S_noto_2201_1 = {&var608,&var611};
_S_noto  S_noto_2209_1 = {&var602,&var612};
_S_noto  S_noto_2195_1 = {&var603,&var613};
_S_and2  S_and2_2188_1 = {&var616,&var707,&var614};
_S_and2  S_and2_2177_1 = {&var616,&var704,&var615};
_S_noto  S_noto_2170_1 = {&var617,&var616};
_S_ovbs  S_ovbs_2169_1 = {&var393,&fRM_3_0,&var617,&internal1_m2169_tx};
_S_and2  S_and2_486_1 = {&var1845,&var1787,&var618};
_S_and2  S_and2_2063_1 = {&var1399,&B7AS31LDU,&var619};
_S_and2  S_and2_498_1 = {&var1146,&var992,&var620};
_S_and2  S_and2_489_1 = {&var993,&var1146,&var621};
_S_and2  S_and2_532_1 = {&var992,&var1147,&var622};
_S_and2  S_and2_527_1 = {&var993,&var1147,&var623};
_S_or2  S_or2_391_1 = {&var1858,&var1118,&var624};
_S_or2  S_or2_387_1 = {&var1858,&var1117,&var625};
_S_ovbs  S_ovbs_52_1 = {&var1870,&fRM_15_0,&var626,&internal1_m52_tx};
_S_ovbs  S_ovbs_368_1 = {&var1347,&fRM_0_02,&var627,&internal1_m368_tx};
_S_ovbs  S_ovbs_322_1 = {&var1349,&fRM_0_02,&var628,&internal1_m322_tx};
_S_ovbs  S_ovbs_835_1 = {&var553,&fRM_0_2,&var629,&internal1_m835_tx};
_S_ovbs  S_ovbs_1627_1 = {&R0MD31LP1,&fRM_10_0,&var630,&internal1_m1627_tx};
_S_ovbs  S_ovbs_120_1 = {&R0MD31LP1,&fRM_0_15,&var631,&internal1_m120_tx};
_S_ovbs  S_ovbs_122_1 = {&var578,&fRM_0_02,&var632,&internal1_m122_tx};
_S_ovbs  S_ovbs_127_1 = {&R0MD32LP1,&fRM_0_02,&var633,&internal1_m127_tx};
_S_ovbs  S_ovbs_21_1 = {&var1423,&fRM_3_0,&var634,&internal1_m21_tx};
_S_ovbs  S_ovbs_13_1 = {&var1195,&fRM_3_0,&var635,&internal1_m13_tx};
_S_ovbs  S_ovbs_2179_1 = {&var393,&fRM_2_0,&var636,&internal1_m2179_tx};
_S_ovbs  S_ovbs_2166_1 = {&var393,&fRM_2_0,&var637,&internal1_m2166_tx};
_S_ovbs  S_ovbs_2284_1 = {&var1432,&fRM_2_0,&var638,&internal1_m2284_tx};
_S_ovbs  S_ovbs_2286_1 = {&var355,&fRM_2_0,&var639,&internal1_m2286_tx};
_S_ovbs  S_ovbs_82_1 = {&R0MW13LP2,&fRM_10_0,&var640,&internal1_m82_tx};
_S_zpfs  S_zpfs_339_1 = {&var1049,&fRM_10_0,&var641,&internal1_m339_tx,&internal1_m339_y0};
_S_or2  S_or2_1158_1 = {&var1260,&var819,&var642};
_S_or2  S_or2_257_1 = {&A1VN71LZ1,&A1VN71LZ2,&var643};
_S_or2  S_or2_279_1 = {&var944,&var1212,&var644};
_S_or5  S_or5_155_1 = {&B1IS21LDU,&B3IS21LDU,&B2IS21LDU,&var1182,&var1183,&var645};
_S_and2  S_and2_1155_1 = {&var1695,&var1331,&var646};
_S_or3  S_or3_1112_1 = {&var397,&var904,&var903,&var647};
_S_or3  S_or3_1585_1 = {&var887,&var886,&var398,&var648};
_S_and2  S_and2_1086_1 = {&var1460,&var1241,&var649};
_S_and3  S_and3_2086_1 = {&var658,&var44,&var651,&var650};
_S_or2  S_or2_2074_1 = {&var1253,&var1363,&var651};
_S_or3  S_or3_2079_1 = {&var656,&var1363,&var654,&var652};
_S_and2  S_and2_2085_1 = {&var1253,&var44,&var653};
_S_and2  S_and2_2078_1 = {&var1355,&var655,&var654};
_S_zpfs  S_zpfs_2077_1 = {&var1253,&fEM_R0UL04RDU,&var655,&internal1_m2077_tx,&internal1_m2077_y0};
_S_and2  S_and2_2070_1 = {&var1358,&var804,&var656};
_S_or3  S_or3_2071_1 = {&var1312,&var810,&var1290,&var657};
_S_abs_subf  S_abs_subf_2092_1 = {&fEM_R0UL02RDU,&var659,&fEM_R0UL16RDU,&vainSFloat,&var658};
_S_rsfn  S_rsfn_2091_1 = {&var801,&var660,&var659,&internal1_m2091_q0};
_S_lk  S_lk_2089_1 = {&var1515,&var44,&var660};
_S_abs_subf  S_abs_subf_1657_1 = {&fEM_R0UL05RDU,&var662,&fEM_R0UL18RDU,&vainSFloat,&var661};
_S_rsfn  S_rsfn_1648_1 = {&var801,&var663,&var662,&internal1_m1648_q0};
_S_lk  S_lk_1652_1 = {&var1369,&var788,&var663};
_S_abs_subf  S_abs_subf_1701_1 = {&fEM_R0UL07RDU,&var665,&fEM_R0UL20RDU,&vainSFloat,&var664};
_S_rsfn  S_rsfn_1686_1 = {&var801,&var666,&var665,&internal1_m1686_q0};
_S_lk  S_lk_1693_1 = {&var1375,&var778,&var666};
_S_ma  S_ma_1669_1 = {array_m1669_x_1,&R0MW12IP2,&iRM_7_,&vainSFloat};
_S_abs_subf  S_abs_subf_1707_1 = {&fEM_R0UL25RDU,&var668,&fEM_R0UL19RDU,&vainSFloat,&var667};
_S_rsfn  S_rsfn_1689_1 = {&var801,&var669,&var668,&internal1_m1689_q0};
_S_lk  S_lk_1695_1 = {&var1513,&var769,&var669};
_S_and3  S_and3_2136_1 = {&var671,&var674,&var681,&var670};
_S_abs_subf  S_abs_subf_2133_1 = {&var672,&fEM_R0UL03RDU,&fEM_R0UL17RDU,&vainSFloat,&var671};
_S_rsfn  S_rsfn_2131_1 = {&var801,&var673,&var672,&internal1_m2131_q0};
_S_lk  S_lk_2127_1 = {&var1514,&var674,&var673};
_S_or3  S_or3_2126_1 = {&var679,&var685,&var684,&var674};
_S_and4  S_and4_2130_1 = {&var684,&var1520,&var697,&var695,&var675};
_S_and4  S_and4_2128_1 = {&var685,&var1520,&var697,&var695,&var676};
_S_and2  S_and2_2120_1 = {&var28,&var674,&var677};
_S_and2  S_and2_2106_1 = {&var804,&var1357,&var678};
_S_and2  S_and2_2110_1 = {&var682,&var1356,&var679};
_S_or3  S_or3_2111_1 = {&var679,&var678,&var1366,&var680};
_S_or2  S_or2_2102_1 = {&var28,&var1366,&var681};
_S_zpfs  S_zpfs_2109_1 = {&var28,&fEM_R0UL21RDU,&var682,&internal1_m2109_tx,&internal1_m2109_y0};
_S_or3  S_or3_2099_1 = {&var806,&var1316,&var1294,&var683};
_S_zpfs  S_zpfs_2124_1 = {&var687,&fEM_R0UL03RDU,&var684,&internal1_m2124_tx,&internal1_m2124_y0};
_S_zpfs  S_zpfs_2121_1 = {&var688,&fEM_R0UL03RDU,&var685,&internal1_m2121_tx,&internal1_m2121_y0};
_S_or2  S_or2_2118_1 = {&var688,&var687,&var686};
_S_or2  S_or2_2119_1 = {&var689,&var28,&var687};
_S_or2  S_or2_2117_1 = {&var690,&var28,&var688};
_S_and4  S_and4_2114_1 = {&var1421,&var1147,&B2IS12LDU,&var691,&var689};
_S_and4  S_and4_2108_1 = {&var1422,&A2IS12LDU,&var1146,&var691,&var690};
_S_and2  S_and2_2107_1 = {&var1169,&var695,&var691};
_S_and3  S_and3_2145_1 = {&var1147,&var1278,&var694,&var692};
_S_and3  S_and3_2144_1 = {&var1146,&var1279,&var694,&var693};
_S_and4  S_and4_2143_1 = {&var1240,&var1039,&var1041,&var695,&var694};
_S_and2  S_and2_2137_1 = {&var1052,&var1241,&var695};
_S_or2  S_or2_2139_1 = {&var1524,&var1239,&var696};
_S_or3  S_or3_2148_1 = {&var700,&var699,&var702,&var697};
_S_and2  S_and2_2138_1 = {&var1282,&A2IS12LDU,&var698};
_S_and2  S_and2_2142_1 = {&var1179,&var698,&var699};
_S_and3  S_and3_2147_1 = {&var1519,&var703,&var698,&var700};
_S_or2  S_or2_2156_1 = {&lRM_0_,&var696,&var701};
_S_and2  S_and2_2153_1 = {&var1194,&var703,&var702};
_S_and2  S_and2_2155_1 = {&var1281,&B2IS12LDU,&var703};
_S_or2  S_or2_2176_1 = {&var1199,&var634,&var704};
_S_or2  S_or2_2171_1 = {&var635,&var393,&var705};
_S_or2  S_or2_2183_1 = {&var393,&var635,&var706};
_S_or2  S_or2_2187_1 = {&var634,&var1198,&var707};
_S_or2  S_or2_2252_1 = {&var1047,&var1433,&var708};
_S_or2  S_or2_2262_1 = {&var1241,&var1454,&var709};
_S_zpfs  S_zpfs_2264_1 = {&var324,&fRM_15_0,&var710,&internal1_m2264_tx,&internal1_m2264_y0};
_S_or2  S_or2_2268_1 = {&var1046,&var356,&var711};
_S_zpfs  S_zpfs_2275_1 = {&var322,&fRM_15_0,&var712,&internal1_m2275_tx,&internal1_m2275_y0};
_S_or2  S_or2_2280_1 = {&var1241,&var1453,&var713};
_S_or2  S_or2_2298_1 = {&var328,&var675,&var714};
_S_or2  S_or2_2291_1 = {&var676,&var332,&var715};
_S_and2  S_and2_2302_1 = {&var1423,&var638,&var716};
_S_and2  S_and2_2062_1 = {&var1400,&A7AS31LDU,&var717};
_S_or3  S_or3_2035_1 = {&var722,&var726,&var724,&var718};
_S_or3  S_or3_2037_1 = {&var725,&var724,&var721,&var719};
_S_or2  S_or2_2049_1 = {&B0VT71LZ1,&B0VT71LZ2,&var720};
_S_and2  S_and2_2040_1 = {&var727,&var720,&var721};
_S_and2  S_and2_2034_1 = {&var727,&var723,&var722};
_S_or2  S_or2_2033_1 = {&A0VT71LZ1,&A0VT71LZ2,&var723};
_S_zpfs  S_zpfs_2030_1 = {&var1417,&fRM_2_5,&var724,&internal1_m2030_tx,&internal1_m2030_y0};
_S_zpfs  S_zpfs_2029_1 = {&var1418,&fRM_2_5,&var725,&internal1_m2029_tx,&internal1_m2029_y0};
_S_zpfs  S_zpfs_2028_1 = {&var1419,&fRM_2_5,&var726,&internal1_m2028_tx,&internal1_m2028_y0};
_S_zpfs  S_zpfs_2027_1 = {&var1420,&fRM_2_5,&var727,&internal1_m2027_tx,&internal1_m2027_y0};
_S_or2  S_or2_2058_1 = {&R0VP73LZ2,&R0VP73LZ1,&var728};
_S_and2  S_and2_2051_1 = {&var355,&var1401,&var729};
_S_or2  S_or2_2048_1 = {&var732,&var729,&var730};
_S_or2  S_or2_2050_1 = {&var328,&var355,&var731};
_S_and2  S_and2_2047_1 = {&var328,&var1391,&var732};
_S_and2  S_and2_2031_1 = {&var1432,&var1402,&var733};
_S_or2  S_or2_2032_1 = {&var736,&var733,&var734};
_S_or2  S_or2_2025_1 = {&var332,&var1432,&var735};
_S_and2  S_and2_2024_1 = {&var332,&var1392,&var736};
_S_or3  S_or3_1994_1 = {&var1483,&var1441,&var1442,&var737};
_S_or3  S_or3_1995_1 = {&var1481,&var1441,&var1442,&var738};
_S_or2  S_or2_1986_1 = {&var1476,&var1441,&var739};
_S_or2  S_or2_1987_1 = {&var1475,&var1441,&var740};
_S_or2  S_or2_1993_1 = {&var1485,&var1444,&var741};
_S_or4  S_or4_1991_1 = {&var1444,&var1482,&var1445,&var1446,&var742};
_S_or4  S_or4_1990_1 = {&var1444,&var1488,&var1445,&var1446,&var743};
_S_or2  S_or2_1984_1 = {&var1477,&var1446,&var744};
_S_or2  S_or2_1983_1 = {&var1478,&var1446,&var745};
_S_or2  S_or2_1992_1 = {&var1444,&var1484,&var746};
_S_or2  S_or2_1961_1 = {&var503,&var549,&var747};
_S_and2  S_and2_1784_1 = {&var1738,&var1696,&var748};
_S_and2  S_and2_1783_1 = {&var1861,&var1696,&var749};
_S_and2  S_and2_1782_1 = {&var1136,&var1696,&var750};
_S_or2  S_or2_1781_1 = {&B4IS11LDU,&A4IS11LDU,&var751};
_S_and2  S_and2_1780_1 = {&var751,&var1696,&var752};
_S_and2  S_and2_1770_1 = {&var1918,&var1696,&var753};
_S_and2  S_and2_1769_1 = {&var406,&var1696,&var754};
_S_and2  S_and2_1768_1 = {&var1125,&var1696,&var755};
_S_and2  S_and2_1767_1 = {&R3IS21LDU,&var1696,&var756};
_S_or2  S_or2_1841_1 = {&var1874,&var1875,&var757};
_S_or2  S_or2_1840_1 = {&var1876,&var1874,&var758};
_S_or2  S_or2_2321_1 = {&var1218,&R0MD34LP1,&var759};
_S_or3  S_or3_2327_1 = {&var1495,&var1497,&var1496,&var760};
_S_or3  S_or3_2318_1 = {&var1501,&var1503,&var1502,&var761};
_S_or2  S_or2_1825_1 = {&var1976,&var1696,&var762};
_S_or2  S_or2_1797_1 = {&var1739,&var1331,&var763};
_S_or5  S_or5_1283_1 = {&var1754,&var765,&var1765,&var1751,&var1752,&var764};
_S_or3  S_or3_1287_1 = {&var1759,&var1760,&var1221,&var765};
_S_or5  S_or5_1812_1 = {&var555,&var767,&var1748,&var1740,&var1741,&var766};
_S_or3  S_or3_1815_1 = {&var1220,&var1743,&var1742,&var767};
_S_and3  S_and3_1716_1 = {&var769,&var774,&var667,&var768};
_S_and2  S_and2_1719_1 = {&var770,&var1251,&var769};
_S_or3  S_or3_1718_1 = {&A3VZ13LZ2,&A3VZ13LZ1,&var773,&var770};
_S_zpfs  S_zpfs_1702_1 = {&var1251,&fRM_0_2,&var771,&internal1_m1702_tx,&internal1_m1702_y0};
_S_or3  S_or3_1704_1 = {&var1377,&var773,&var775,&var772};
_S_and2  S_and2_1703_1 = {&var1354,&var771,&var773};
_S_or2  S_or2_1694_1 = {&var1251,&var1377,&var774};
_S_and2  S_and2_1681_1 = {&var1359,&var804,&var775};
_S_or3  S_or3_1687_1 = {&var1291,&var1313,&var809,&var776};
_S_or3  S_or3_1712_1 = {&R0AD14LZ1,&R0AD14LZ2,&var780,&var777};
_S_and2  S_and2_1713_1 = {&var777,&var1249,&var778};
_S_zpfs  S_zpfs_1696_1 = {&var1249,&fEM_R0UL06RDU,&var779,&internal1_m1696_tx,&internal1_m1696_y0};
_S_and2  S_and2_1697_1 = {&var779,&var1353,&var780};
_S_or3  S_or3_1698_1 = {&var1372,&var780,&var783,&var781};
_S_or3  S_or3_1671_1 = {&var808,&var1314,&var1292,&var782};
_S_and2  S_and2_1676_1 = {&var1360,&var804,&var783};
_S_and3  S_and3_1715_1 = {&var664,&var778,&var791,&var784};
_S_zpfs  S_zpfs_1643_1 = {&var1248,&fEM_R0UL04RDU,&var785,&internal1_m1643_tx,&internal1_m1643_y0};
_S_and2  S_and2_1644_1 = {&var785,&var1352,&var786};
_S_and3  S_and3_1661_1 = {&var661,&var788,&var792,&var787};
_S_and2  S_and2_1655_1 = {&var789,&var1248,&var788};
_S_or3  S_or3_1654_1 = {&A3VZ15LZ1,&A3VZ15LZ2,&var786,&var789};
_S_or3  S_or3_1645_1 = {&var793,&var786,&var1370,&var790};
_S_or2  S_or2_1690_1 = {&var1249,&var1372,&var791};
_S_or2  S_or2_1641_1 = {&var1248,&var1370,&var792};
_S_and2  S_and2_1633_1 = {&var1361,&var804,&var793};
_S_or3  S_or3_1631_1 = {&var1293,&var1315,&var807,&var794};
_S_or2  S_or2_1594_1 = {&var1867,&var796,&var795};
_S_and2  S_and2_1593_1 = {&var797,&var1415,&var796};
_S_or2  S_or2_1592_1 = {&var1192,&var1144,&var797};
_S_or2  S_or2_1589_1 = {&var1286,&var1308,&var798};
_S_and2  S_and2_1587_1 = {&var1380,&var1381,&var799};
_S_and2  S_and2_1590_1 = {&var798,&var797,&var800};
_S_or5  S_or5_1591_1 = {&var628,&var627,&var799,&var800,&R0MD34LP1,&var801};
_S_orni  S_orni_1620_1 = {array_m1620_x_1,&iRM_5_,&var802,&var803};
_S_or5  S_or5_1622_1 = {&var1376,&var1351,&var801,&var1296,&var630,&var804};
_S_and2  S_and2_1621_1 = {&var802,&var1507,&var805};
_S_or2  S_or2_1630_1 = {&var41,&var43,&var806};
_S_or2  S_or2_1624_1 = {&var39,&var811,&var807};
_S_or2  S_or2_1616_1 = {&var38,&var812,&var808};
_S_or2  S_or2_1612_1 = {&var40,&var813,&var809};
_S_or2  S_or2_1608_1 = {&var42,&var814,&var810};
_S_and2  S_and2_1623_1 = {&var1322,&var1317,&var811};
_S_and2  S_and2_1615_1 = {&var1321,&var1317,&var812};
_S_and2  S_and2_1611_1 = {&var1317,&var1320,&var813};
_S_and2  S_and2_1607_1 = {&var1319,&var1317,&var814};
_S_and2  S_and2_1598_1 = {&var1867,&var315,&var815};
_S_and3  S_and3_1188_1 = {&var497,&var820,&var838,&var816};
_S_or2  S_or2_1153_1 = {&var1333,&var1329,&var817};
_S_or2  S_or2_1178_1 = {&var1329,&var1263,&var818};
_S_and2  S_and2_1146_1 = {&var1705,&var1330,&var819};
_S_and2  S_and2_1141_1 = {&var1524,&var840,&var820};
_S_or3  S_or3_1150_1 = {&var1329,&var1259,&var1332,&var821};
_S_and2  S_and2_1154_1 = {&var494,&var1524,&var822};
_S_and2  S_and2_1179_1 = {&var505,&var1524,&var823};
_S_and2  S_and2_1187_1 = {&var499,&var1524,&var824};
_S_and2  S_and2_1194_1 = {&var502,&var1524,&var825};
_S_and3  S_and3_1136_1 = {&var828,&var1245,&var1524,&var826};
_S_and3  S_and3_1130_1 = {&var829,&var1245,&var1524,&var827};
_S_and2  S_and2_1138_1 = {&var1146,&var1523,&var828};
_S_and2  S_and2_1128_1 = {&var1147,&var1523,&var829};
_S_and4  S_and4_1137_1 = {&var828,&var1524,&var1256,&var1243,&var830};
_S_and4  S_and4_1131_1 = {&var829,&var1524,&var1256,&var1243,&var831};
_S_and4  S_and4_1135_1 = {&var1524,&var828,&var836,&var1244,&var832};
_S_and4  S_and4_1129_1 = {&var1524,&var829,&var836,&var1244,&var833};
_S_and2  S_and2_1122_1 = {&var1257,&var1524,&var834};
_S_or4  S_or4_1125_1 = {&R0MD31LP1,&var1758,&var510,&var847,&var835};
_S_and3  S_and3_1175_1 = {&var1258,&var1257,&var1256,&var836};
_S_and2  S_and2_1159_1 = {&var838,&var642,&var837};
_S_and2  S_and2_1163_1 = {&var1255,&var836,&var838};
_S_or2  S_or2_1170_1 = {&var1325,&var1267,&var839};
_S_and2  S_and2_1181_1 = {&var841,&var839,&var840};
_S_or2  S_or2_1171_1 = {&var1266,&var1268,&var841};
_S_or2  S_or2_1172_1 = {&var1265,&var1266,&var842};
_S_or2  S_or2_1176_1 = {&var1264,&var1269,&var843};
_S_and2  S_and2_1177_1 = {&var842,&var843,&var844};
_S_or2  S_or2_1166_1 = {&var1325,&var1324,&var845};
_S_and2  S_and2_1167_1 = {&var845,&var1261,&var846};
_S_and5  S_and5_1118_1 = {&var848,&var1345,&var1266,&var1325,&var837,&var847};
_S_and2  S_and2_1119_1 = {&var1300,&var1301,&var848};
_S_and2  S_and2_1409_1 = {&var1394,&var850,&var849};
_S_or2  S_or2_1404_1 = {&A2MD12LP1,&var851,&var850};
_S_and2  S_and2_1395_1 = {&A2MD11LP1,&var1411,&var851};
_S_or2  S_or2_1385_1 = {&var854,&B2MD12LP1,&var852};
_S_and2  S_and2_1387_1 = {&var852,&var1394,&var853};
_S_and2  S_and2_1379_1 = {&B2MD11LP1,&var1412,&var854};
_S_or3  S_or3_1367_1 = {&var1474,&var1469,&var1010,&var855};
_S_or5  S_or5_1380_1 = {&var858,&var1230,&var1735,&var1730,&var1729,&var856};
_S_or2  S_or2_1403_1 = {&var1988,&var1720,&var857};
_S_or3  S_or3_1470_1 = {&var1701,&var859,&var860,&var858};
_S_and2  S_and2_1461_1 = {&var1720,&var1193,&var859};
_S_and2  S_and2_1460_1 = {&var1143,&var1720,&var860};
_S_and3  S_and3_1459_1 = {&var645,&var1179,&var875,&var861};
_S_and2  S_and2_1458_1 = {&var406,&var875,&var862};
_S_and3  S_and3_1452_1 = {&var1168,&var1214,&var875,&var863};
_S_and2  S_and2_1451_1 = {&var728,&var875,&var864};
_S_and2  S_and2_1436_1 = {&var1711,&var875,&var865};
_S_and2  S_and2_1420_1 = {&var1918,&var875,&var866};
_S_and2  S_and2_1438_1 = {&var313,&var875,&var867};
_S_and2  S_and2_1421_1 = {&R3IS21LDU,&var875,&var868};
_S_and2  S_and2_1439_1 = {&var871,&var875,&var869};
_S_and3  S_and3_1422_1 = {&var872,&var1710,&var875,&var870};
_S_or2  S_or2_1440_1 = {&var1703,&var1704,&var871};
_S_or2  S_or2_1425_1 = {&A4IS11LDU,&B4IS11LDU,&var872};
_S_and3  S_and3_1433_1 = {&var1444,&var511,&var1195,&var873};
_S_and3  S_and3_1432_1 = {&var1446,&var511,&var1195,&var874};
_S_or3  S_or3_1424_1 = {&var1721,&var874,&var873,&var875};
_S_and2  S_and2_1517_1 = {&var877,&var1394,&var876};
_S_or2  S_or2_1513_1 = {&var878,&B3MD12LP1,&var877};
_S_and2  S_and2_1503_1 = {&B3MD11LP1,&var1390,&var878};
_S_or2  S_or2_1508_1 = {&var1979,&var1538,&var879};
_S_or5  S_or5_1496_1 = {&var648,&var1547,&var1548,&var423,&var1228,&var880};
_S_and2  S_and2_1568_1 = {&var1538,&var1193,&var881};
_S_and2  S_and2_1567_1 = {&var1538,&var1143,&var882};
_S_and2  S_and2_1581_1 = {&var1209,&var1526,&var883};
_S_or2  S_or2_1574_1 = {&var883,&var1210,&var884};
_S_and3  S_and3_1566_1 = {&var1403,&var884,&var893,&var885};
_S_and3  S_and3_1565_1 = {&var645,&var1194,&var893,&var886};
_S_and2  S_and2_1564_1 = {&var406,&var893,&var887};
_S_and2  S_and2_1559_1 = {&var1458,&var1241,&var888};
_S_or2  S_or2_1546_1 = {&var1529,&var1528,&var889};
_S_and2  S_and2_1545_1 = {&var889,&var893,&var890};
_S_and2  S_and2_1544_1 = {&var313,&var893,&var891};
_S_and2  S_and2_1542_1 = {&var1531,&var893,&var892};
_S_or2  S_or2_1531_1 = {&var1540,&var336,&var893};
_S_or2  S_or2_1532_1 = {&B4IS11LDU,&A4IS11LDU,&var894};
_S_and3  S_and3_1529_1 = {&var1530,&var894,&var893,&var895};
_S_and2  S_and2_1528_1 = {&R3IS21LDU,&var893,&var896};
_S_and2  S_and2_1527_1 = {&var1918,&var893,&var897};
_S_and2  S_and2_1105_1 = {&var1207,&var1558,&var898};
_S_and2  S_and2_1094_1 = {&var1143,&var1570,&var899};
_S_and2  S_and2_1095_1 = {&var1193,&var1570,&var900};
_S_or2  S_or2_1101_1 = {&var1208,&var898,&var901};
_S_and3  S_and3_1093_1 = {&var1403,&var901,&var908,&var902};
_S_and3  S_and3_1092_1 = {&var1179,&var645,&var908,&var903};
_S_and2  S_and2_1091_1 = {&var406,&var908,&var904};
_S_and2  S_and2_1069_1 = {&var1563,&var908,&var905};
_S_or2  S_or2_1073_1 = {&var1561,&var1560,&var906};
_S_and2  S_and2_1072_1 = {&var906,&var908,&var907};
_S_or2  S_or2_1057_1 = {&var1572,&var337,&var908};
_S_or2  S_or2_1058_1 = {&B4IS11LDU,&A4IS11LDU,&var909};
_S_and3  S_and3_1056_1 = {&var909,&var1562,&var908,&var910};
_S_and2  S_and2_1071_1 = {&var313,&var908,&var911};
_S_and2  S_and2_1055_1 = {&R3IS21LDU,&var908,&var912};
_S_and2  S_and2_1054_1 = {&var1918,&var908,&var913};
_S_or2  S_or2_1034_1 = {&var1570,&var1982,&var914};
_S_or5  S_or5_1020_1 = {&var647,&var1229,&var421,&var1579,&var1580,&var915};
_S_and2  S_and2_1047_1 = {&var1394,&var917,&var916};
_S_or2  S_or2_1042_1 = {&var918,&A3MD12LP1,&var917};
_S_and2  S_and2_1031_1 = {&A3MD11LP1,&var1443,&var918};
_S_or3  S_or3_992_1 = {&var1668,&var921,&var920,&var919};
_S_and2  S_and2_982_1 = {&var1679,&var1143,&var920};
_S_and2  S_and2_983_1 = {&var1679,&var1193,&var921};
_S_and3  S_and3_981_1 = {&var1702,&var1194,&var933,&var922};
_S_and2  S_and2_980_1 = {&var406,&var933,&var923};
_S_and2  S_and2_958_1 = {&var1672,&var933,&var924};
_S_and2  S_and2_960_1 = {&var313,&var933,&var925};
_S_and2  S_and2_961_1 = {&var927,&var933,&var926};
_S_or2  S_or2_962_1 = {&var1670,&var1669,&var927};
_S_and2  S_and2_942_1 = {&var1918,&var933,&var928};
_S_and3  S_and3_944_1 = {&var1671,&var934,&var933,&var929};
_S_and2  S_and2_943_1 = {&R3IS21LDU,&var933,&var930};
_S_and3  S_and3_957_1 = {&var1444,&var511,&var1195,&var931};
_S_and3  S_and3_956_1 = {&var511,&var1446,&var1195,&var932};
_S_or3  S_or3_945_1 = {&var1680,&var931,&var932,&var933};
_S_or2  S_or2_946_1 = {&B4IS11LDU,&A4IS11LDU,&var934};
_S_or2  S_or2_926_1 = {&var1985,&var1679,&var935};
_S_zpfs  S_zpfs_922_1 = {&var1693,&fRM_3_0,&var936,&internal1_m922_tx,&internal1_m922_y0};
_S_zpfs  S_zpfs_921_1 = {&var1694,&fRM_2_0,&var937,&internal1_m921_tx,&internal1_m921_y0};
_S_zpfs  S_zpfs_939_1 = {&var1691,&fEM_A2UL83RDU,&var938,&internal1_m939_tx,&internal1_m939_y0};
_S_or5  S_or5_918_1 = {&var919,&var938,&var1692,&var937,&var936,&var939};
_S_or3  S_or3_904_1 = {&var1449,&var1472,&var1005,&var940};
_S_or4  S_or4_886_1 = {&var1815,&var1813,&var1814,&var1816,&var941};
_S_or2  S_or2_878_1 = {&var943,&var941,&var942};
_S_or4  S_or4_871_1 = {&var1824,&var1823,&var1822,&var1825,&var943};
_S_and2  S_and2_282_1 = {&var1211,&var1618,&var944};
_S_and3  S_and3_268_1 = {&var1179,&var645,&var1633,&var945};
_S_or3  S_or3_286_1 = {&var947,&var949,&var1621,&var946};
_S_and2  S_and2_272_1 = {&var1632,&var1193,&var947};
_S_and3  S_and3_269_1 = {&var644,&var1403,&var1633,&var948};
_S_and2  S_and2_271_1 = {&var1143,&var1632,&var949};
_S_and2  S_and2_267_1 = {&var406,&var1633,&var950};
_S_and2  S_and2_236_1 = {&var1625,&var1633,&var951};
_S_and2  S_and2_238_1 = {&var313,&var1633,&var952};
_S_or2  S_or2_240_1 = {&var1622,&var1623,&var953};
_S_and2  S_and2_239_1 = {&var953,&var1633,&var954};
_S_or2  S_or2_225_1 = {&B4IS11LDU,&A4IS11LDU,&var955};
_S_and3  S_and3_224_1 = {&var1624,&var955,&var1633,&var956};
_S_and2  S_and2_219_1 = {&var1918,&var1633,&var957};
_S_and2  S_and2_223_1 = {&R3IS21LDU,&var1633,&var958};
_S_and2  S_and2_191_1 = {&var1394,&var961,&var959};
_S_and2  S_and2_184_1 = {&A1MD11LP1,&var1431,&var960};
_S_or2  S_or2_190_1 = {&A1MD12LP1,&var960,&var961};
_S_or2  S_or2_200_1 = {&var1632,&var1970,&var962};
_S_zpfs  S_zpfs_194_1 = {&var1647,&fRM_2_0,&var963,&internal1_m194_tx,&internal1_m194_y0};
_S_zpfs  S_zpfs_193_1 = {&var1646,&fRM_2_0,&var964,&internal1_m193_tx,&internal1_m193_y0};
_S_zpfs  S_zpfs_215_1 = {&var1644,&fEM_A1UL03RDU,&var965,&internal1_m215_tx,&internal1_m215_y0};
_S_or5  S_or5_188_1 = {&var946,&var965,&var964,&var963,&var1645,&var966};
_S_orn  S_orn_616_1 = {array_m616_x_1,&iRM_12_,&var967};
_S_and2  S_and2_645_1 = {&var1588,&var1206,&var968};
_S_or2  S_or2_641_1 = {&var1205,&var968,&var969};
_S_and3  S_and3_631_1 = {&var1194,&var1702,&var1600,&var970};
_S_and2  S_and2_630_1 = {&var406,&var1600,&var971};
_S_and3  S_and3_632_1 = {&var1403,&var1600,&var969,&var972};
_S_or2  S_or2_606_1 = {&var1590,&var1589,&var973};
_S_and2  S_and2_605_1 = {&var973,&var1600,&var974};
_S_and2  S_and2_604_1 = {&var1600,&var313,&var975};
_S_and3  S_and3_591_1 = {&var1591,&var977,&var1600,&var976};
_S_or2  S_or2_592_1 = {&B4IS11LDU,&A4IS11LDU,&var977};
_S_and2  S_and2_602_1 = {&var1600,&var1592,&var978};
_S_or2  S_or2_565_1 = {&B1MD12LP1,&var981,&var979};
_S_and2  S_and2_567_1 = {&var1394,&var979,&var980};
_S_and2  S_and2_559_1 = {&B1MD11LP1,&var1413,&var981};
_S_and2  S_and2_590_1 = {&var1600,&R3IS21LDU,&var982};
_S_and2  S_and2_589_1 = {&var1600,&var1918,&var983};
_S_or2  S_or2_572_1 = {&var1599,&var1992,&var984};
_S_zpfs  S_zpfs_588_1 = {&var1613,&fEM_A1UL03RDU,&var985,&internal1_m588_tx,&internal1_m588_y0};
_S_or5  S_or5_561_1 = {&var1139,&var985,&var1614,&var1608,&var1609,&var986};
_S_or2  S_or2_549_1 = {&var1427,&var1006,&var987};
_S_or3  S_or3_539_1 = {&var827,&var1426,&var1236,&var988};
_S_or4  S_or4_526_1 = {&var1653,&var1650,&var1652,&var1651,&var989};
_S_or4  S_or4_507_1 = {&var1661,&var1659,&var1660,&var1662,&var990};
_S_or2  S_or2_514_1 = {&var990,&var989,&var991};
_S_and3  S_and3_496_1 = {&var994,&var1394,&R0MD33LP1,&var992};
_S_and3  S_and3_497_1 = {&var1394,&var995,&R0MD33LP1,&var993};
_S_or3  S_or3_487_1 = {&var541,&var1246,&var1232,&var994};
_S_or2  S_or2_488_1 = {&var1648,&var1425,&var995};
_S_or2  S_or2_837_1 = {&var1783,&var1784,&var996};
_S_and2  S_and2_358_1 = {&var1285,&var1347,&var997};
_S_or2  S_or2_377_1 = {&B4IS21LDU,&A4IS21LDU,&var998};
_S_or2  S_or2_372_1 = {&A2IS21LDU,&B2IS21LDU,&var999};
_S_or2  S_or2_367_1 = {&var1002,&var1289,&var1000};
_S_and3  S_and3_365_1 = {&var1348,&var1343,&var1344,&var1001};
_S_or4  S_or4_363_1 = {&var1274,&var451,&R0MD31LP1,&var1284,&var1002};
_S_and4  S_and4_359_1 = {&var1192,&var1060,&var510,&var1150,&var1003};
_S_or2  S_or2_354_1 = {&R0MD34LP1,&var1284,&var1004};
_S_and3  S_and3_676_1 = {&var1027,&var1525,&B2IS12LDU,&var1005};
_S_and2  S_and2_675_1 = {&var1027,&var1557,&var1006};
_S_and2  S_and2_674_1 = {&var1027,&var1620,&var1007};
_S_or2  S_or2_718_1 = {&A2IS12LDU,&B2IS12LDU,&var1008};
_S_or2  S_or2_695_1 = {&var1755,&var1383,&var1009};
_S_and3  S_and3_686_1 = {&A2IS12LDU,&var1525,&var1028,&var1010};
_S_and2  S_and2_717_1 = {&var1012,&var1525,&var1011};
_S_or2  S_or2_719_1 = {&var1326,&var494,&var1012};
_S_or2  S_or2_700_1 = {&var1755,&var1382,&var1013};
_S_or2  S_or2_698_1 = {&var1015,&var1755,&var1014};
_S_and2  S_and2_710_1 = {&var1557,&var505,&var1015};
_S_and2  S_and2_685_1 = {&var1028,&var1557,&var1016};
_S_and2  S_and2_684_1 = {&var1028,&var1620,&var1017};
_S_and2  S_and2_709_1 = {&var499,&var1620,&var1018};
_S_and2  S_and2_725_1 = {&var502,&var1648,&var1019};
_S_or2  S_or2_721_1 = {&var1755,&var1384,&var1020};
_S_or2  S_or2_716_1 = {&var1022,&var1019,&var1021};
_S_and2  S_and2_708_1 = {&var1030,&var1617,&var1022};
_S_and2  S_and2_714_1 = {&var1030,&R0MD33LP1,&var1023};
_S_or2  S_or2_664_1 = {&var1203,&var1204,&var1024};
_S_and4  S_and4_683_1 = {&var1203,&var1028,&var1717,&A2IS12LDU,&var1025};
_S_and4  S_and4_673_1 = {&var1027,&var1204,&var1717,&B2IS12LDU,&var1026};
_S_and2  S_and2_672_1 = {&var1147,&var1715,&var1027};
_S_and2  S_and2_682_1 = {&var1146,&var1715,&var1028};
_S_or2  S_or2_713_1 = {&var1327,&var494,&var1029};
_S_and2  S_and2_706_1 = {&var1029,&var1717,&var1030};
_S_or2  S_or2_693_1 = {&var1755,&var1385,&var1031};
_S_or2  S_or2_705_1 = {&var1695,&var1340,&var1032};
_S_and2  S_and2_704_1 = {&var1032,&var1739,&var1033};
_S_or2  S_or2_690_1 = {&var1755,&var1386,&var1034};
_S_and2  S_and2_703_1 = {&var1756,&var1705,&var1035};
_S_or2  S_or2_688_1 = {&var1755,&var1387,&var1036};
_S_and2  S_and2_701_1 = {&var497,&var1758,&var1037};
_S_or2  S_or2_680_1 = {&var1395,&var1755,&var1038};
_S_and2  S_and2_332_1 = {&var1455,&var1041,&var1039};
_S_and2  S_and2_320_1 = {&var1041,&var1272,&var1040};
_S_or2  S_or2_315_1 = {&var1286,&var1308,&var1041};
_S_and3  S_and3_311_1 = {&var1521,&var1343,&var1344,&var1042};
_S_and3  S_and3_326_1 = {&var999,&var1273,&var1044,&var1043};
_S_or2  S_or2_316_1 = {&var1521,&var1348,&var1044};
_S_and2  S_and2_325_1 = {&var998,&var1044,&var1045};
_S_and2  S_and2_346_1 = {&var1050,&var1147,&var1046};
_S_and2  S_and2_347_1 = {&var1146,&var1050,&var1047};
_S_and2  S_and2_352_1 = {&var1241,&var1039,&var1048};
_S_and2  S_and2_340_1 = {&var1050,&var1241,&var1049};
_S_and2  S_and2_345_1 = {&var1423,&var1051,&var1050};
_S_or2  S_or2_341_1 = {&var1052,&var997,&var1051};
_S_or2  S_or2_342_1 = {&var1053,&var997,&var1052};
_S_and4  S_and4_343_1 = {&var1349,&var1297,&var1298,&var1144,&var1053};
_S_or2  S_or2_328_1 = {&var1349,&var1347,&var1054};
_S_and2  S_and2_313_1 = {&var1311,&var1280,&var1055};
_S_or2  S_or2_319_1 = {&var1058,&var1055,&var1056};
_S_or2  S_or2_293_1 = {&R0MD34LP1,&var1283,&var1057};
_S_or4  S_or4_310_1 = {&var1274,&R0MD31LP1,&var451,&var1283,&var1058};
_S_and3  S_and3_303_1 = {&var1060,&var1149,&var510,&var1059};
_S_or2  S_or2_302_1 = {&var1302,&var1486,&var1060};
_S_and3  S_and3_305_1 = {&var1303,&var1305,&var1304,&var1061};
_S_or2  S_or2_295_1 = {&var1063,&var1061,&var1062};
_S_and3  S_and3_289_1 = {&R0MD33LP1,&var1307,&var1306,&var1063};
_S_or2  S_or2_1250_1 = {&B4IS11LDU,&A4IS11LDU,&var1064};
_S_and2  S_and2_1253_1 = {&var1706,&var1753,&var1065};
_S_and2  S_and2_1252_1 = {&var1706,&var1861,&var1066};
_S_and2  S_and2_1251_1 = {&var1706,&var1136,&var1067};
_S_and2  S_and2_1249_1 = {&var1706,&var1064,&var1068};
_S_and2  S_and2_1239_1 = {&var1706,&var406,&var1069};
_S_and2  S_and2_1238_1 = {&var1125,&var1706,&var1070};
_S_and2  S_and2_1237_1 = {&var1706,&R3IS21LDU,&var1071};
_S_and2  S_and2_1240_1 = {&var1706,&var1918,&var1072};
_S_and2  S_and2_1210_1 = {&var494,&var1238,&var1073};
_S_and2  S_and2_1211_1 = {&var505,&var1236,&var1074};
_S_and2  S_and2_1212_1 = {&var499,&var1234,&var1075};
_S_and2  S_and2_1213_1 = {&var502,&var1232,&var1076};
_S_or2  S_or2_1195_1 = {&R0MD31LP1,&var1078,&var1077};
_S_and4  S_and4_1196_1 = {&var17,&var21,&var19,&var23,&var1078};
_S_or2  S_or2_1299_1 = {&var1706,&var1973,&var1079};
_S_or2  S_or2_1272_1 = {&var1756,&var1330,&var1080};
_S_or2  S_or2_1346_1 = {&var1797,&var1796,&var1081};
_S_or2  S_or2_1332_1 = {&var1806,&var1805,&var1082};
_S_or2  S_or2_1342_1 = {&var1219,&R0MD34LP1,&var1083};
_S_or2  S_or2_1316_1 = {&var1081,&var1861,&var1084};
_S_or2  S_or2_1314_1 = {&var1086,&var1084,&var1085};
_S_or2  S_or2_1315_1 = {&var1082,&var1861,&var1086};
_S_or4  S_or4_389_1 = {&var1833,&var1832,&var1834,&var1831,&var1087};
_S_or2  S_or2_740_1 = {&B5IS11LDU,&A5IS11LDU,&var1088};
_S_and2  S_and2_739_1 = {&var1093,&var1088,&var1089};
_S_or2  S_or2_738_1 = {&B6IS11LDU,&A6IS11LDU,&var1090};
_S_and2  S_and2_737_1 = {&var1093,&var1090,&var1091};
_S_or2  S_or2_736_1 = {&A4IS11LDU,&B4IS11LDU,&var1092};
_S_or2  S_or2_727_1 = {&var1095,&var1096,&var1093};
_S_and2  S_and2_733_1 = {&var1093,&var1092,&var1094};
_S_and2  S_and2_730_1 = {&var406,&var1106,&var1095};
_S_and2  S_and2_726_1 = {&var407,&var1099,&var1096};
_S_and2  S_and2_857_1 = {&var1859,&var1777,&var1097};
_S_and2  S_and2_853_1 = {&var1859,&var1778,&var1098};
_S_and3  S_and3_848_1 = {&var1859,&var407,&var1784,&var1099};
_S_or2  S_or2_856_1 = {&var1779,&var1773,&var1100};
_S_or2  S_or2_851_1 = {&var1777,&var1779,&var1101};
_S_or2  S_or2_847_1 = {&var1779,&var1778,&var1102};
_S_and2  S_and2_829_1 = {&var1773,&var1859,&var1103};
_S_or2  S_or2_823_1 = {&var1780,&var1781,&var1104};
_S_or2  S_or2_814_1 = {&var1838,&var1780,&var1105};
_S_and2  S_and2_813_1 = {&var1781,&var1860,&var1106};
_S_and2  S_and2_812_1 = {&var1838,&var1860,&var1107};
_S_and2  S_and2_841_1 = {&var497,&var1859,&var1108};
_S_and2  S_and2_821_1 = {&var497,&var1790,&var1109};
_S_and2  S_and2_839_1 = {&var1860,&var497,&var1110};
_S_or2  S_or2_833_1 = {&var1860,&var1859,&var1111};
_S_or3  S_or3_826_1 = {&var317,&var1114,&var1115,&var1112};
_S_or4  S_or4_825_1 = {&var1114,&var316,&var1116,&var1769,&var1113};
_S_or3  S_or3_816_1 = {&R4MD31LP2,&var1103,&var1107,&var1114};
_S_or2  S_or2_845_1 = {&var1858,&var1118,&var1115};
_S_or2  S_or2_844_1 = {&var1858,&var1117,&var1116};
_S_and2  S_and2_752_1 = {&var317,&var1772,&var1117};
_S_and3  S_and3_788_1 = {&var1771,&var1785,&var316,&var1118};
_S_and2  S_and2_793_1 = {&R5IS11LDU,&var1133,&var1119};
_S_and3  S_and3_791_1 = {&var1423,&R3IS21LDU,&var1133,&var1120};
_S_and2  S_and2_792_1 = {&R6IS21LDU,&var1133,&var1121};
_S_or2  S_or2_790_1 = {&B8IS22LDU,&A8IS22LDU,&var1122};
_S_and2  S_and2_789_1 = {&var1122,&var1133,&var1123};
_S_and2  S_and2_772_1 = {&var1133,&var1125,&var1124};
_S_or4  S_or4_773_1 = {&A0VN71LZ1,&B0VN71LZ1,&B0VN71LZ2,&A0VN71LZ2,&var1125};
_S_and2  S_and2_771_1 = {&var1130,&var1133,&var1126};
_S_and2  S_and2_758_1 = {&var1136,&var1133,&var1127};
_S_and2  S_and2_757_1 = {&var1861,&var1133,&var1128};
_S_or3  S_or3_756_1 = {&R0NE01LDU,&R0NE02LDU,&R0NE08LDU,&var1129};
_S_or2  S_or2_769_1 = {&R1IS21LDU,&R2IS21LDU,&var1130};
_S_and2  S_and2_755_1 = {&var1133,&var1129,&var1131};
_S_and2  S_and2_753_1 = {&var1839,&var1133,&var1132};
_S_or2  S_or2_743_1 = {&var1860,&var1859,&var1133};
_S_or2  S_or2_174_1 = {&var1429,&var1016,&var1134};
_S_or3  S_or3_164_1 = {&var826,&var1428,&var1236,&var1135};
_S_or2  S_or2_157_1 = {&var1702,&var645,&var1136};
_S_or3  S_or3_115_1 = {&var1393,&var632,&var633,&var1137};
_S_or2  S_or2_2230_1 = {&var595,&var472,&var1138};
_S_or3  S_or3_649_1 = {&var1140,&var1141,&var967,&var1139};
_S_and2  S_and2_633_1 = {&var1599,&var1143,&var1140};
_S_and2  S_and2_634_1 = {&var1599,&var1193,&var1141};
_S_or2  S_or2_63_1 = {&var1193,&var1143,&var1142};
_S_and2  S_and2_66_1 = {&var1144,&var1276,&var1143};
_S_and2  S_and2_65_1 = {&var1868,&var1277,&var1144};
_S_or2  S_or2_49_1 = {&A4IS21LDU,&B4IS21LDU,&var1145};
_S_or2  S_or2_35_1 = {&var1519,&var1516,&var1146};
_S_or2  S_or2_39_1 = {&var1519,&var1518,&var1147};
_S_or2  S_or2_20_1 = {&var1423,&var1378,&var1148};
_S_or2  S_or2_8_1 = {&var1878,&var1195,&var1149};
_S_or2  S_or2_14_1 = {&var1195,&var1879,&var1150};
_S_and3  S_and3_1117_1 = {&var507,&var1872,&var1170,&var1151};
_S_and3  S_and3_662_1 = {&var1170,&var510,&var1872,&var1152};
_S_and2  S_and2_1184_1 = {&var1216,&var1154,&var1153};
_S_or2  S_or2_1190_1 = {&var1879,&var1878,&var1154};
_S_or2  S_or2_1558_1 = {&var1880,&var1878,&var1155};
_S_and3  S_and3_1557_1 = {&var1214,&var1155,&var893,&var1156};
_S_or2  S_or2_1085_1 = {&var1880,&var1878,&var1157};
_S_and3  S_and3_1084_1 = {&var1214,&var1157,&var908,&var1158};
_S_or2  S_or2_620_1 = {&var1880,&var1878,&var1159};
_S_and3  S_and3_619_1 = {&var1214,&var1159,&var1600,&var1160};
_S_and2  S_and2_617_1 = {&var402,&var1600,&var1161};
_S_or2  S_or2_254_1 = {&var1880,&var1878,&var1162};
_S_and3  S_and3_253_1 = {&var1214,&var1162,&var1633,&var1163};
_S_and2  S_and2_251_1 = {&var1633,&var403,&var1164};
_S_and3  S_and3_974_1 = {&var1214,&var1167,&var933,&var1165};
_S_and2  S_and2_973_1 = {&var728,&var933,&var1166};
_S_or2  S_or2_975_1 = {&var1880,&var1878,&var1167};
_S_or2  S_or2_1453_1 = {&var1880,&var1878,&var1168};
_S_or2  S_or2_6_1 = {&var1879,&var1878,&var1169};
_S_or3  S_or3_5_1 = {&var1880,&var1879,&var1878,&var1170};
_S_or2  S_or2_832_1 = {&var1780,&var1782,&var1171};
_S_or2  S_or2_483_1 = {&var1861,&var1176,&var1172};
_S_or2  S_or2_461_1 = {&var1861,&var1177,&var1173};
_S_or4  S_or4_462_1 = {&var1173,&var1789,&var1788,&var1172,&var1174};
_S_and2  S_and2_453_1 = {&A8IS22LDU,&var1853,&var1175};
_S_or3  S_or3_433_1 = {&var1843,&var1841,&var1842,&var1176};
_S_or3  S_or3_417_1 = {&var1851,&var1850,&var1852,&var1177};
_S_and2  S_and2_819_1 = {&var1860,&var1782,&var1178};
_S_and2  S_and2_38_1 = {&var1516,&var1517,&var1179};
_S_and2  S_and2_150_1 = {&var1792,&var1416,&var1180};
_S_and2  S_and2_158_1 = {&var1794,&var1416,&var1181};
_S_and2  S_and2_161_1 = {&var1791,&var1416,&var1182};
_S_and2  S_and2_153_1 = {&var1416,&var1793,&var1183};
_S_and2  S_and2_479_1 = {&var1136,&var1845,&var1184};
_S_and2  S_and2_477_1 = {&B8IS22LDU,&var1845,&var1185};
_S_and2  S_and2_475_1 = {&A8IS22LDU,&var1845,&var1186};
_S_and2  S_and2_473_1 = {&R5IS11LDU,&var1845,&var1187};
_S_and2  S_and2_464_1 = {&var1787,&var1853,&var1188};
_S_and2  S_and2_452_1 = {&R5IS11LDU,&var1853,&var1189};
_S_and2  S_and2_456_1 = {&var1136,&var1853,&var1190};
_S_and2  S_and2_119_1 = {&var1195,&var631,&var1191};
_S_and2  S_and2_61_1 = {&var1869,&var1277,&var1192};
_S_and2  S_and2_62_1 = {&var1192,&var1275,&var1193};
_S_and2  S_and2_42_1 = {&var1517,&var1518,&var1194};
_S_and2  S_and2_11_1 = {&var1877,&var1509,&var1195};
_S_and2  S_and2_31_1 = {&var1440,&var496,&var1196};
_S_and2  S_and2_30_1 = {&var1336,&var1423,&var1197};
_S_and2  S_and2_29_1 = {&var1337,&var1423,&var1198};
_S_and2  S_and2_28_1 = {&var1338,&var1423,&var1199};
_S_and2  S_and2_27_1 = {&var1339,&var1423,&var1200};
_S_and2  S_and2_846_1 = {&var1776,&var1784,&var1201};
_S_and2  S_and2_828_1 = {&var1783,&var1860,&var1202};
_S_bol  S_bol_663_1 = {&var1987,&fRM_20_0,&var1203};
_S_bol  S_bol_657_1 = {&var1984,&fRM_20_0,&var1204};
_S_bol  S_bol_648_1 = {&var1984,&fRM_20_03,&var1205};
_S_bol  S_bol_644_1 = {&var1987,&fRM_20_03,&var1206};
_S_bol  S_bol_1104_1 = {&var1984,&fRM_20_03,&var1207};
_S_bol  S_bol_1111_1 = {&var1987,&fRM_20_03,&var1208};
_S_bol  S_bol_1580_1 = {&var1987,&fRM_20_03,&var1209};
_S_bol  S_bol_1582_1 = {&var1984,&fRM_20_03,&var1210};
_S_bol  S_bol_281_1 = {&var1984,&fRM_20_03,&var1211};
_S_bol  S_bol_285_1 = {&var1987,&fRM_20_03,&var1212};
_S_sr  S_sr_88_1 = {array_m88_x_1,&iRM_2_,&var1213};
_S_bol  S_bol_87_1 = {&var1213,&var450,&var1214};
_S_ma  S_ma_90_1 = {array_m90_x_1,&R0MW15IP1,&iRM_8_,&var1215};
_S_bol  S_bol_1185_1 = {&var1217,&fEM_R0UN80RDU,&var1216};
_S_sr  S_sr_1191_1 = {array_m1191_x_1,&iRM_2_,&var1217};
_S_ovbs  S_ovbs_2320_1 = {&lRM_1_,&fEM_A9UZ04RDU,&var1218,&internal1_m2320_tx};
_S_ovbs  S_ovbs_1341_1 = {&lRM_1_,&fEM_A4UZ04RDU,&var1219,&internal1_m1341_tx};
_S_zpfs  S_zpfs_1832_1 = {&var1747,&fEM_B8UL03RDU,&var1220,&internal1_m1832_tx,&internal1_m1832_y0};
_S_zpfs  S_zpfs_1306_1 = {&var1764,&fEM_B8UL03RDU,&var1221,&internal1_m1306_tx,&internal1_m1306_y0};
_S_ma  S_ma_1369_1 = {array_m1369_x_1,&var1716,&iRM_8_,&var1222};
_S_ma  S_ma_906_1 = {array_m906_x_1,&var1676,&iRM_8_,&var1223};
_S_ma  S_ma_1004_1 = {array_m1004_x_1,&var1567,&iRM_8_,&var1224};
_S_ma  S_ma_1482_1 = {array_m1482_x_1,&var1535,&iRM_8_,&var1225};
_S_ma  S_ma_548_1 = {array_m548_x_1,&var1596,&iRM_8_,&var1226};
_S_ma  S_ma_173_1 = {array_m173_x_1,&var1629,&iRM_8_,&var1227};
_S_zpfs  S_zpfs_1525_1 = {&var1552,&fEM_A3UL03RDU,&var1228,&internal1_m1525_tx,&internal1_m1525_y0};
_S_zpfs  S_zpfs_1052_1 = {&var1584,&fEM_A3UL03RDU,&var1229,&internal1_m1052_tx,&internal1_m1052_y0};
_S_zpfs  S_zpfs_1415_1 = {&var1734,&fEM_A2UL03RDU,&var1230,&internal1_m1415_tx,&internal1_m1415_y0};
_S_rs  S_rs_1209_1 = {&var1077,&var1076,&var1231,&vainSBool,&internal1_m1209_q0};
_S_rs  S_rs_1207_1 = {&var17,&var1239,&var1232,&vainSBool,&internal1_m1207_q0};
_S_rs  S_rs_1206_1 = {&var1077,&var1075,&var1233,&vainSBool,&internal1_m1206_q0};
_S_rs  S_rs_1204_1 = {&var19,&var1239,&var1234,&vainSBool,&internal1_m1204_q0};
_S_rs  S_rs_1203_1 = {&var1077,&var1074,&var1235,&vainSBool,&internal1_m1203_q0};
_S_rs  S_rs_1201_1 = {&var21,&var1239,&var1236,&vainSBool,&internal1_m1201_q0};
_S_rs  S_rs_1200_1 = {&var1077,&var1073,&var1237,&vainSBool,&internal1_m1200_q0};
_S_rs  S_rs_1198_1 = {&var23,&var1239,&var1238,&vainSBool,&internal1_m1198_q0};
_S_rs  S_rs_1197_1 = {&var1077,&var451,&var1239,&vainSBool,&internal1_m1197_q0};
_S_noto  S_noto_2140_1 = {&var696,&var1240};
_S_swtakt  S_swtakt_54_1 = {&var25,&var1241,&fEM_R0UL00RDU,&var1242,&internal1_m54_x0,&internal1_m54_tim};
_S_noto  S_noto_1183_1 = {&var1257,&var1243};
_S_noto  S_noto_1157_1 = {&var1255,&var1244};
_S_noto  S_noto_1169_1 = {&var1256,&var1245};
_S_rs  S_rs_1116_1 = {&var1258,&var834,&var1246,&vainSBool,&internal1_m1116_q0};
_S_swtakt  S_swtakt_1637_1 = {&var1371,&var1247,&fEM_R0UL00RDU,&var1248,&internal1_m1637_x0,&internal1_m1637_tim};
_S_swtakt  S_swtakt_1685_1 = {&var1374,&var1249,&fEM_R0UL00RDU,&var1250,&internal1_m1685_x0,&internal1_m1685_tim};
_S_swtakt  S_swtakt_1688_1 = {&var1512,&var1251,&fEM_R0UL00RDU,&var1252,&internal1_m1688_x0,&internal1_m1688_tim};
_S_swtakt  S_swtakt_2072_1 = {&var1364,&var1253,&fEM_R0UL00RDU,&var1254,&internal1_m2072_x0,&internal1_m2072_tim};
_S_rs  S_rs_1156_1 = {&var1329,&var822,&var1255,&vainSBool,&internal1_m1156_q0};
_S_rs  S_rs_1162_1 = {&var1329,&var823,&var1256,&vainSBool,&internal1_m1162_q0};
_S_rs  S_rs_1180_1 = {&var1329,&var824,&var1257,&vainSBool,&internal1_m1180_q0};
_S_rs  S_rs_1189_1 = {&var1329,&var825,&var1258,&vainSBool,&internal1_m1189_q0};
_S_noto  S_noto_1143_1 = {&var840,&var1259};
_S_noto  S_noto_1174_1 = {&var840,&var1260};
_S_noto  S_noto_1173_1 = {&var844,&var1261};
_S_rs  S_rs_1168_1 = {&var818,&var820,&var1262,&vainSBool,&internal1_m1168_q0};
_S_rs  S_rs_1182_1 = {&var1329,&var816,&var1263,&vainSBool,&internal1_m1182_q0};
_S_bol  S_bol_1165_1 = {&var1972,&var557,&var1264};
_S_bol  S_bol_1164_1 = {&var1975,&var557,&var1265};
_S_noto  S_noto_1123_1 = {&var1324,&var1266};
_S_bol  S_bol_1161_1 = {&var557,&var1972,&var1267};
_S_bol  S_bol_1160_1 = {&var557,&var1975,&var1268};
_S_noto  S_noto_1147_1 = {&var1325,&var1269};
_S_rs  S_rs_2158_1 = {&var701,&var692,&var1270,&vainSBool,&internal1_m2158_q0};
_S_rs  S_rs_2157_1 = {&var701,&var693,&var1271,&vainSBool,&internal1_m2157_q0};
_S_noto  S_noto_353_1 = {&var1048,&var1272};
_S_noto  S_noto_336_1 = {&var1041,&var1273};
_S_noto  S_noto_304_1 = {&var1060,&var1274};
_S_noto  S_noto_59_1 = {&var1286,&var1275};
_S_noto  S_noto_70_1 = {&var1308,&var1276};
_S_noto  S_noto_69_1 = {&var1239,&var1277};
_S_noto  S_noto_2152_1 = {&B2IS11LDU,&var1278};
_S_noto  S_noto_2150_1 = {&A2IS11LDU,&var1279};
_S_noto  S_noto_312_1 = {&var510,&var1280};
_S_noto  S_noto_2159_1 = {&B2IS11LDU,&var1281};
_S_noto  S_noto_2134_1 = {&A2IS11LDU,&var1282};
_S_noto  S_noto_299_1 = {&var1144,&var1283};
_S_noto  S_noto_357_1 = {&var1192,&var1284};
_S_bolz  S_bolz_361_1 = {&iRM_2_,&var1287,&var1285};
_S_provsbr  S_provsbr_356_1 = {&var1347,&var1004,&var1362,&var1379,&var1373,&var1368,&var1365,&var1363,&var1377,&var1372,&var1370,&var1366,&iRM_10_,array_m356_Tpr_1,array_m356_type_1,&var1286,&var1287,&var1288,&var1289,&var1290,&var1291,&var1292,&var1293,&var1294,&vainSBool,&internal1_m356_Step,array_m356_rz_1,&internal1_m356_TimS,&internal1_m356_FinPr0,&internal1_m356_ErrPr0,&internal1_m356_sbINI0,&internal1_m356_sbVuIS0,&internal1_m356_sb2UR0,&internal1_m356_sbNupIS0,&internal1_m356_sbVuRB0,&internal1_m356_MyFirstEnterFlag};
_S_orni  S_orni_360_1 = {array_m360_x_1,&iRM_5_,&vainSBool,&var1295};
_S_cntch  S_cntch_364_1 = {&var1295,&var1296,&internal1_m364_x0};
_S_bolz  S_bolz_338_1 = {&iRM_20_,&var1310,&var1297};
_S_equz_p  S_equz_p_337_1 = {&var1309,&iRM_0_,&var1298};
_S_decatron  S_decatron_321_1 = {&var1040,&var1299,&internal1_m321_TimS,&internal1_m321_pusk0};
_S_noto  S_noto_1120_1 = {&R2IS21LDU,&var1300};
_S_noto  S_noto_1114_1 = {&R1IS21LDU,&var1301};
_S_andn  S_andn_294_1 = {array_m294_x_1,&iRM_7_,&var1302};
_S_noto  S_noto_296_1 = {&R0MD33LP1,&var1303};
_S_noto  S_noto_306_1 = {&R2IS21LDU,&var1304};
_S_noto  S_noto_300_1 = {&R1IS21LDU,&var1305};
_S_noto  S_noto_291_1 = {&R1IS11LDU,&var1306};
_S_noto  S_noto_288_1 = {&R2IS11LDU,&var1307};
_S_provsbr  S_provsbr_298_1 = {&var1349,&var1057,&var1362,&var1379,&var1373,&var1368,&var1365,&var1363,&var1377,&var1372,&var1370,&var1366,&iRM_10_,array_m298_Tpr_1,array_m298_type_1,&var1308,&var1309,&var1310,&var1311,&var1312,&var1313,&var1314,&var1315,&var1316,&vainSBool,&internal1_m298_Step,array_m298_rz_1,&internal1_m298_TimS,&internal1_m298_FinPr0,&internal1_m298_ErrPr0,&internal1_m298_sbINI0,&internal1_m298_sbVuIS0,&internal1_m298_sb2UR0,&internal1_m298_sbNupIS0,&internal1_m298_sbVuRB0,&internal1_m298_MyFirstEnterFlag};
_S_rs  S_rs_1599_1 = {&var1318,&var815,&var1317,&vainSBool,&internal1_m1599_q0};
_S_provsbr  S_provsbr_1600_1 = {&var1317,&R0MD34LP1,&var1362,&var1379,&var1373,&var1368,&var1365,&var1363,&var1377,&var1372,&var1370,&var1366,&iRM_6_,array_m1600_Tpr_1,array_m1600_type_1,&var1318,&vainSInt,&vainSInt,&vainSBool,&var1319,&var1320,&var1321,&var1322,&var1323,&vainSBool,&internal1_m1600_Step,array_m1600_rz_1,&internal1_m1600_TimS,&internal1_m1600_FinPr0,&internal1_m1600_ErrPr0,&internal1_m1600_sbINI0,&internal1_m1600_sbVuIS0,&internal1_m1600_sb2UR0,&internal1_m1600_sbNupIS0,&internal1_m1600_sbVuRB0,&internal1_m1600_MyFirstEnterFlag};
_S_abs_subf  S_abs_subf_1126_1 = {&var557,&var1975,&fEM_B8UC01RDU,&vainSFloat,&var1324};
_S_abs_subf  S_abs_subf_1139_1 = {&var1972,&var557,&fEM_B8UC01RDU,&vainSFloat,&var1325};
_S_noto  S_noto_723_1 = {&var1008,&var1326};
_S_noto  S_noto_670_1 = {&var1024,&var1327};
_S_noto  S_noto_50_1 = {&var553,&var1328};
_S_noto  S_noto_1144_1 = {&var1524,&var1329};
_S_rs  S_rs_1152_1 = {&var817,&var646,&var1330,&vainSBool,&internal1_m1152_q0};
_S_rs  S_rs_1149_1 = {&var821,&var816,&var1331,&vainSBool,&internal1_m1149_q0};
_S_rs  S_rs_1151_1 = {&var1329,&var646,&var1332,&vainSBool,&internal1_m1151_q0};
_S_rs  S_rs_1145_1 = {&var1329,&var819,&var1333,&vainSBool,&internal1_m1145_q0};
_S_noto  S_noto_659_1 = {&A2IS21LDU,&var1334};
_S_noto  S_noto_661_1 = {&B2IS21LDU,&var1335};
_S_noto  S_noto_25_1 = {&B2IS21LDU,&var1336};
_S_noto  S_noto_24_1 = {&B1IS21LDU,&var1337};
_S_noto  S_noto_23_1 = {&A1IS21LDU,&var1338};
_S_noto  S_noto_22_1 = {&A2IS21LDU,&var1339};
_S_newstage  S_newstage_671_1 = {&var379,&var376,&A2IS12LDU,&B2IS12LDU,&var1340};
_S_noto  S_noto_660_1 = {&B2IS12LDU,&var1341};
_S_noto  S_noto_658_1 = {&A2IS12LDU,&var1342};
_S_noto  S_noto_370_1 = {&var999,&var1343};
_S_noto  S_noto_374_1 = {&var998,&var1344};
_S_noto  S_noto_1113_1 = {&var1136,&var1345};
_S_rs  S_rs_836_1 = {&var996,&var629,&var1346,&vainSBool,&internal1_m836_q0};
_S_rs  S_rs_366_1 = {&var1000,&var1001,&var1347,&vainSBool,&internal1_m366_q0};
_S_rs  S_rs_362_1 = {&var1002,&var1003,&var1348,&vainSBool,&internal1_m362_q0};
_S_rs  S_rs_318_1 = {&var1056,&var1042,&var1349,&vainSBool,&internal1_m318_q0};
_S_orni  S_orni_314_1 = {array_m314_x_1,&iRM_5_,&vainSBool,&var1350};
_S_cntch  S_cntch_317_1 = {&var1350,&var1351,&internal1_m317_x0};
_S_noto  S_noto_1650_1 = {&var1370,&var1352};
_S_noto  S_noto_1709_1 = {&var1372,&var1353};
_S_noto  S_noto_1711_1 = {&var1377,&var1354};
_S_noto  S_noto_2084_1 = {&var1363,&var1355};
_S_noto  S_noto_2116_1 = {&var1366,&var1356};
_S_noto  S_noto_2096_1 = {&var1367,&var1357};
_S_noto  S_noto_2069_1 = {&var1364,&var1358};
_S_noto  S_noto_1680_1 = {&var1512,&var1359};
_S_noto  S_noto_1672_1 = {&var1374,&var1360};
_S_noto  S_noto_1632_1 = {&var1371,&var1361};
_S_rs  S_rs_2087_1 = {&var801,&var650,&var1362,&vainSBool,&internal1_m2087_q0};
_S_rs  S_rs_2080_1 = {&var656,&var653,&var1363,&vainSBool,&internal1_m2080_q0};
_S_rs  S_rs_2073_1 = {&var652,&var657,&var1364,&vainSBool,&internal1_m2073_q0};
_S_rs  S_rs_2141_1 = {&var801,&var670,&var1365,&vainSBool,&internal1_m2141_q0};
_S_rs  S_rs_2112_1 = {&var678,&var677,&var1366,&vainSBool,&internal1_m2112_q0};
_S_rs  S_rs_2100_1 = {&var680,&var683,&var1367,&vainSBool,&internal1_m2100_q0};
_S_rs  S_rs_1664_1 = {&var801,&var787,&var1368,&vainSBool,&internal1_m1664_q0};
_S_kvf  S_kvf_1651_1 = {&var1248,&var788,&fRM_0_0,&var1369,&vainSInt,&vainSInt,&internal1_m1651_x0,&internal1_m1651_y0,&internal1_m1651_fef};
_S_rs  S_rs_1646_1 = {&var793,&var788,&var1370,&vainSBool,&internal1_m1646_q0};
_S_rs  S_rs_1636_1 = {&var790,&var794,&var1371,&vainSBool,&internal1_m1636_q0};
_S_rs  S_rs_1699_1 = {&var783,&var778,&var1372,&vainSBool,&internal1_m1699_q0};
_S_rs  S_rs_1720_1 = {&var801,&var784,&var1373,&vainSBool,&internal1_m1720_q0};
_S_rs  S_rs_1684_1 = {&var781,&var782,&var1374,&vainSBool,&internal1_m1684_q0};
_S_kvf  S_kvf_1700_1 = {&var30,&var778,&fRM_0_0,&var1375,&vainSInt,&vainSInt,&internal1_m1700_x0,&internal1_m1700_y0,&internal1_m1700_fef};
_S_cntch  S_cntch_1617_1 = {&var803,&var1376,&internal1_m1617_x0};
_S_rs  S_rs_1706_1 = {&var775,&var769,&var1377,&vainSBool,&internal1_m1706_q0};
_S_rs  S_rs_26_1 = {&var1423,&var1196,&var1378,&vainSBool,&internal1_m26_q0};
_S_rs  S_rs_1721_1 = {&var801,&var768,&var1379,&vainSBool,&internal1_m1721_q0};
_S_noto  S_noto_1588_1 = {&var797,&var1380};
_S_noto  S_noto_1586_1 = {&var1195,&var1381};
_S_rs  S_rs_711_1 = {&var1755,&var1011,&var1382,&vainSBool,&internal1_m711_q0};
_S_rs  S_rs_696_1 = {&var1755,&var1018,&var1383,&vainSBool,&internal1_m696_q0};
_S_rs  S_rs_724_1 = {&var1755,&var1019,&var1384,&vainSBool,&internal1_m724_q0};
_S_rs  S_rs_707_1 = {&var1755,&var1030,&var1385,&vainSBool,&internal1_m707_q0};
_S_rs  S_rs_691_1 = {&var1755,&var1033,&var1386,&vainSBool,&internal1_m691_q0};
_S_rs  S_rs_689_1 = {&var1755,&var1035,&var1387,&vainSBool,&internal1_m689_q0};
_S_rs  S_rs_677_1 = {&var1038,&var1758,&var1388,&vainSBool,&internal1_m677_q0};
_S_rsun  S_rsun_1602_1 = {&var801,&var1508,&vainSLong,&var1389,&internal1_m1602_q0};
_S_noto  S_noto_1510_1 = {&B3MD12LP1,&var1390};
_S_noto  S_noto_2043_1 = {&B3IS11LDU,&var1391};
_S_noto  S_noto_2017_1 = {&A3IS11LDU,&var1392};
_S_noto  S_noto_118_1 = {&var1195,&var1393};
_S_noto  S_noto_117_1 = {&var1398,&var1394};
_S_rs  S_rs_687_1 = {&var1755,&var1037,&var1395,&vainSBool,&internal1_m687_q0};
_S_orni  S_orni_1340_1 = {array_m1340_x_1,&iRM_5_,&var1396,&vainSLong};
_S_orni  S_orni_1328_1 = {array_m1328_x_1,&iRM_4_,&var1397,&vainSLong};
_S_rs  S_rs_116_1 = {&var1137,&var1191,&var1398,&vainSBool,&internal1_m116_q0};
_S_noto  S_noto_2046_1 = {&var719,&var1399};
_S_noto  S_noto_2045_1 = {&var718,&var1400};
_S_noto  S_noto_2057_1 = {&B3IS22LDU,&var1401};
_S_noto  S_noto_2039_1 = {&A3IS22LDU,&var1402};
_S_newstage  S_newstage_2041_1 = {&var735,&var731,&var734,&var730,&vainSBool};
_S_noto  S_noto_1985_1 = {&var1486,&var1403};
_S_rs  S_rs_1867_1 = {&var293,&var521,&var1404,&vainSBool,&internal1_m1867_q0};
_S_rs  S_rs_1866_1 = {&var286,&var523,&var1405,&vainSBool,&internal1_m1866_q0};
_S_rs  S_rs_1865_1 = {&var292,&var525,&var1406,&vainSBool,&internal1_m1865_q0};
_S_rs  S_rs_1864_1 = {&var268,&var527,&var1407,&vainSBool,&internal1_m1864_q0};
_S_rs  S_rs_1900_1 = {&var496,&var529,&var1408,&vainSBool,&internal1_m1900_q0};
_S_rs  S_rs_1899_1 = {&var304,&var532,&var1409,&vainSBool,&internal1_m1899_q0};
_S_rs  S_rs_1898_1 = {&var305,&var532,&var1410,&vainSBool,&internal1_m1898_q0};
_S_noto  S_noto_1400_1 = {&A2MD12LP1,&var1411};
_S_noto  S_noto_1382_1 = {&B2MD12LP1,&var1412};
_S_noto  S_noto_563_1 = {&B1MD12LP1,&var1413};
_S_ma  S_ma_1653_1 = {array_m1653_x_1,&var1389,&iRM_16_,&var1414};
_S_noto  S_noto_1596_1 = {&var1052,&var1415};
_S_noto  S_noto_148_1 = {&var1195,&var1416};
_S_equz_p  S_equz_p_2023_1 = {&R0MW14IP2,&iRM_5_,&var1417};
_S_equz_p  S_equz_p_2022_1 = {&R0MW14IP2,&iRM_4_,&var1418};
_S_equz_p  S_equz_p_2021_1 = {&R0MW14IP2,&iRM_3_,&var1419};
_S_equz_p  S_equz_p_2019_1 = {&R0MW14IP2,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_2020_1 = {&R0MW14IP2,&iRM_2_,&var1420};
_S_noto  S_noto_2105_1 = {&B2IS11LDU,&var1421};
_S_noto  S_noto_2113_1 = {&A2IS11LDU,&var1422};
_S_noto  S_noto_12_1 = {&var1877,&var1423};
_S_rs  S_rs_2172_1 = {&var615,&var705,&var1424,&vainSBool,&internal1_m2172_q0};
_S_rs  S_rs_1960_1 = {&var747,&var542,&var1425,&vainSBool,&internal1_m1960_q0};
_S_rs  S_rs_1950_1 = {&var289,&var543,&var1426,&vainSBool,&internal1_m1950_q0};
_S_rs  S_rs_1957_1 = {&var306,&var544,&var1427,&vainSBool,&internal1_m1957_q0};
_S_rs  S_rs_1947_1 = {&var290,&var545,&var1428,&vainSBool,&internal1_m1947_q0};
_S_rs  S_rs_1954_1 = {&var310,&var546,&var1429,&vainSBool,&internal1_m1954_q0};
_S_equz_p  S_equz_p_105_1 = {&R0MW16IP1,&iRM_10_,&var1430};
_S_noto  S_noto_186_1 = {&A1MD12LP1,&var1431};
_S_rs  S_rs_2388_1 = {&var280,&var277,&var1432,&vainSBool,&internal1_m2388_q0};
_S_rs  S_rs_2384_1 = {&var296,&var368,&var1433,&vainSBool,&internal1_m2384_q0};
_S_rs  S_rs_1925_1 = {&var309,&var539,&var1434,&vainSBool,&internal1_m1925_q0};
_S_rs  S_rs_1917_1 = {&var496,&var528,&var1435,&vainSBool,&internal1_m1917_q0};
_S_rs  S_rs_1915_1 = {&var291,&var529,&var1436,&vainSBool,&internal1_m1915_q0};
_S_rs  S_rs_1911_1 = {&var304,&var530,&var1437,&vainSBool,&internal1_m1911_q0};
_S_rs  S_rs_1907_1 = {&var266,&var532,&var1438,&vainSBool,&internal1_m1907_q0};
_S_rs  S_rs_1909_1 = {&var305,&var531,&var1439,&vainSBool,&internal1_m1909_q0};
_S_rs  S_rs_19_1 = {&var1148,&var635,&var1440,&vainSBool,&internal1_m19_q0};
_S_equz_p  S_equz_p_104_1 = {&R0MW16IP1,&iRM_9_,&var1441};
_S_equz_p  S_equz_p_103_1 = {&R0MW16IP1,&iRM_8_,&var1442};
_S_noto  S_noto_1036_1 = {&A3MD12LP1,&var1443};
_S_equz_p  S_equz_p_102_1 = {&R0MW16IP1,&iRM_7_,&var1444};
_S_equz_p  S_equz_p_101_1 = {&R0MW16IP1,&iRM_6_,&var1445};
_S_equz_p  S_equz_p_100_1 = {&R0MW16IP1,&iRM_5_,&var1446};
_S_rs  S_rs_1890_1 = {&var293,&var520,&var1447,&vainSBool,&internal1_m1890_q0};
_S_rs  S_rs_1888_1 = {&var285,&var521,&var1448,&vainSBool,&internal1_m1888_q0};
_S_rs  S_rs_1884_1 = {&var303,&var523,&var1449,&vainSBool,&internal1_m1884_q0};
_S_rs  S_rs_1886_1 = {&var286,&var522,&var1450,&vainSBool,&internal1_m1886_q0};
_S_rs  S_rs_1882_1 = {&var292,&var524,&var1451,&vainSBool,&internal1_m1882_q0};
_S_rs  S_rs_1880_1 = {&var269,&var525,&var1452,&vainSBool,&internal1_m1880_q0};
_S_rs  S_rs_2294_1 = {&var383,&var714,&var1453,&vainSBool,&internal1_m2294_q0};
_S_rs  S_rs_2292_1 = {&var384,&var715,&var1454,&vainSBool,&internal1_m2292_q0};
_S_equz_p  S_equz_p_327_1 = {&var1299,&iRM_0_,&var1455};
_S_noto  S_noto_2295_1 = {&var1453,&var1456};
_S_noto  S_noto_2287_1 = {&var639,&var1457};
_S_noto  S_noto_2270_1 = {&var1459,&var1458};
_S_rs  S_rs_2269_1 = {&var323,&var711,&var1459,&vainSBool,&internal1_m2269_q0};
_S_noto  S_noto_2254_1 = {&var1461,&var1460};
_S_rs  S_rs_2253_1 = {&var325,&var708,&var1461,&vainSBool,&internal1_m2253_q0};
_S_noto  S_noto_2293_1 = {&var1454,&var1462};
_S_noto  S_noto_2285_1 = {&var638,&var1463};
_S_noto  S_noto_2185_1 = {&var1465,&var1464};
_S_rs  S_rs_2184_1 = {&var614,&var706,&var1465,&vainSBool,&internal1_m2184_q0};
_S_noto  S_noto_2173_1 = {&var1424,&var1466};
_S_noto  S_noto_2180_1 = {&var636,&var1467};
_S_noto  S_noto_2167_1 = {&var637,&var1468};
_S_rs  S_rs_1876_1 = {&var302,&var527,&var1469,&vainSBool,&internal1_m1876_q0};
_S_rs  S_rs_1878_1 = {&var268,&var526,&var1470,&vainSBool,&internal1_m1878_q0};
_S_rs  S_rs_1862_1 = {&var283,&var512,&var1471,&vainSBool,&internal1_m1862_q0};
_S_rs  S_rs_1860_1 = {&var301,&var513,&var1472,&vainSBool,&internal1_m1860_q0};
_S_rs  S_rs_1858_1 = {&var282,&var514,&var1473,&vainSBool,&internal1_m1858_q0};
_S_rs  S_rs_1856_1 = {&var300,&var515,&var1474,&vainSBool,&internal1_m1856_q0};
_S_noto  S_noto_1980_1 = {&B3IS22LDU,&var1475};
_S_noto  S_noto_1979_1 = {&A3IS22LDU,&var1476};
_S_noto  S_noto_1978_1 = {&B2IS12LDU,&var1477};
_S_noto  S_noto_1977_1 = {&A2IS12LDU,&var1478};
_S_noto  S_noto_1976_1 = {&B1IS12LDU,&var1479};
_S_noto  S_noto_1975_1 = {&A1IS12LDU,&var1480};
_S_noto  S_noto_2005_1 = {&B3IS21LDU,&var1481};
_S_noto  S_noto_1999_1 = {&B2IS21LDU,&var1482};
_S_noto  S_noto_2004_1 = {&A3IS21LDU,&var1483};
_S_noto  S_noto_2002_1 = {&B4IS21LDU,&var1484};
_S_noto  S_noto_2003_1 = {&A4IS21LDU,&var1485};
_S_andn  S_andn_1988_1 = {array_m1988_x_1,&iRM_17_,&var1486};
_S_noto  S_noto_1997_1 = {&B1IS21LDU,&var1487};
_S_noto  S_noto_1998_1 = {&A2IS21LDU,&var1488};
_S_noto  S_noto_1996_1 = {&A1IS21LDU,&var1489};
_S_rs  S_rs_1855_1 = {&var1494,&var516,&var1490,&vainSBool,&internal1_m1855_q0};
_S_rs  S_rs_1853_1 = {&var284,&var517,&var1491,&vainSBool,&internal1_m1853_q0};
_S_rs  S_rs_1852_1 = {&var1494,&var518,&var1492,&vainSBool,&internal1_m1852_q0};
_S_rs  S_rs_1850_1 = {&var267,&var519,&var1493,&vainSBool,&internal1_m1850_q0};
_S_newstage  S_newstage_2323_1 = {&var1506,&var1500,&var1505,&var1499,&var1494};
_S_samhd  S_samhd_2325_1 = {&var759,&var760,&var760,&var1491,&var1490,&var1491,&var1490,&B9IS11LDU,&B9IS11LDU,&B9IS21LDU,&B9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1495,&var1496,&var1497,&vainSBool,&var1498,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1499,&var1500,&internal1_m2325_DvUp0,&internal1_m2325_DvDw0,&internal1_m2325_FDvUp0,&internal1_m2325_FDvDw0,&internal1_m2325_BlDv0,&internal1_m2325_Pkv0,&internal1_m2325_Pkav0,&internal1_m2325_Zkv0,&internal1_m2325_Zkav0,&internal1_m2325_txNm,&internal1_m2325_txSm,&internal1_m2325_txHr,&internal1_m2325_txLd,&internal1_m2325_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_2319_1 = {&var759,&var761,&var761,&var1493,&var1492,&var1493,&var1492,&A9IS11LDU,&A9IS11LDU,&A9IS21LDU,&A9IS21LDU,&bRM_1_,&fEM_A9UZ05RDU,&fEM_A9UZ03RDU,&fEM_A9UZ04RDU,&var1501,&var1502,&var1503,&vainSBool,&var1504,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&var1505,&var1506,&internal1_m2319_DvUp0,&internal1_m2319_DvDw0,&internal1_m2319_FDvUp0,&internal1_m2319_FDvDw0,&internal1_m2319_BlDv0,&internal1_m2319_Pkv0,&internal1_m2319_Pkav0,&internal1_m2319_Zkv0,&internal1_m2319_Zkav0,&internal1_m2319_txNm,&internal1_m2319_txSm,&internal1_m2319_txHr,&internal1_m2319_txLd,&internal1_m2319_fef,&bFirstEnterFlag};
_S_orni  S_orni_1604_1 = {array_m1604_x_1,&iRM_5_,&var1507,&var1508};
_S_noto  S_noto_83_1 = {&var640,&var1509};
_S_maz  S_maz_333_1 = {array_m333_x_1,&R0MW12IP1,&iRM_3_,&var1510};
_S_maz  S_maz_324_1 = {array_m324_x_1,&R0MW12IP1,&iRM_3_,&var1511};
_S_rs  S_rs_1679_1 = {&var772,&var776,&var1512,&vainSBool,&internal1_m1679_q0};
_S_kvf  S_kvf_1705_1 = {&var1251,&var769,&fRM_0_0,&var1513,&vainSInt,&vainSInt,&internal1_m1705_x0,&internal1_m1705_y0,&internal1_m1705_fef};
_S_kvf  S_kvf_2123_1 = {&var686,&var674,&fRM_0_0,&var1514,&vainSInt,&vainSInt,&internal1_m2123_x0,&internal1_m2123_y0,&internal1_m2123_fef};
_S_kvf  S_kvf_2082_1 = {&var1253,&var44,&fRM_0_0,&var1515,&vainSInt,&vainSInt,&internal1_m2082_x0,&internal1_m2082_y0,&internal1_m2082_fef};
_S_equz_p  S_equz_p_37_1 = {&R0MW13IP1,&iRM_1_,&var1516};
_S_noto  S_noto_34_1 = {&var1519,&var1517};
_S_equz_p  S_equz_p_41_1 = {&R0MW13IP1,&iRM_2_,&var1518};
_S_equz_p  S_equz_p_32_1 = {&R0MW13IP1,&iRM_3_,&var1519};
_S_noto  S_noto_2125_1 = {&var28,&var1520};
_S_rs  S_rs_309_1 = {&var1058,&var1059,&var1521,&vainSBool,&internal1_m309_q0};
_S_orn  S_orn_668_1 = {array_m668_x_1,&iRM_5_,&var1522};
_S_noto  S_noto_1133_1 = {&lEM_R0MD01LC1,&var1523};
_S_rs  S_rs_1124_1 = {&var835,&var1151,&var1524,&vainSBool,&internal1_m1124_q0};
_S_rs  S_rs_699_1 = {&var1013,&var1015,&var1525,&vainSBool,&internal1_m699_q0};
_S_noto  S_noto_1584_1 = {&var1194,&var1526};
_S_orn  S_orn_1553_1 = {array_m1553_x_1,&iRM_8_,&var1527};
_S_noto  S_noto_1552_1 = {&var1695,&var1528};
_S_noto  S_noto_1551_1 = {&var1705,&var1529};
_S_noto  S_noto_1530_1 = {&var1195,&var1530};
_S_noto  S_noto_1543_1 = {&R8IS11LDU,&var1531};
_S_charint  S_charint_1475_1 = {&var1534,&var1532};
_S_ornc  S_ornc_1481_1 = {array_m1481_x_1,&iRM_3_,&var1533,&var1534};
_S_fsumz  S_fsumz_1476_1 = {&var1532,&iRM_1_,&var1535};
_S_cnshd  S_cnshd_1483_1 = {&R0MD34LP1,&var1978,&var1225,&var561,&var1533,&var880,&var876,&iRM_1_,array_m1483_Lt_fw_1,array_m1483_Vr_fw_1,&iRM_1_,array_m1483_Lt_bw_1,array_m1483_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1536,&vainSBool,&var1537,&var1538,&var1539,&var1540,&var1541,&var1542,&var1543,&var1544,&var1545,&var1546,&internal1_m1483_X0,&internal1_m1483_t0,&internal1_m1483_BLDv0};
_S_zpfs  S_zpfs_1500_1 = {&var1555,&fRM_2_0,&var1547,&internal1_m1500_tx,&internal1_m1500_y0};
_S_zpfs  S_zpfs_1501_1 = {&var1554,&fRM_3_0,&var1548,&internal1_m1501_tx,&internal1_m1501_y0};
_S_fnapb  S_fnapb_1509_1 = {&var1978,&var1225,&var879,&R0MD34LP1,&var1538,&var1545,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1549,&var1550,&var1551,&var1552,&var1553,&var1554,&var1555,&vainSFloat,&internal1_m1509_xptr,array_m1509_x0_1,array_m1509_tim0_1,&internal1_m1509_sumtim,&internal1_m1509_StSpeed,&internal1_m1509_Vz0,&internal1_m1509_flRazg,&internal1_m1509_DelSp,&internal1_m1509_z0,&internal1_m1509_txZS,&internal1_m1509_tx,&internal1_m1509_txd,&internal1_m1509_txMBl,&internal1_m1509_txBl,&internal1_m1509_Speed0,&internal1_m1509_xz0,&internal1_m1509_tz0,&internal1_m1509_Shift0,&internal1_m1509_ShCntlSp0,&internal1_m1509_ShiftControl,&bFirstEnterFlag};
_S_newstage  S_newstage_1017_1 = {&var1565,&var1533,&var1568,&var1536,&var1556};
_S_rs  S_rs_697_1 = {&var1014,&var1018,&var1557,&vainSBool,&internal1_m697_q0};
_S_noto  S_noto_1110_1 = {&var1179,&var1558};
_S_orn  S_orn_1082_1 = {array_m1082_x_1,&iRM_8_,&var1559};
_S_noto  S_noto_1081_1 = {&var1695,&var1560};
_S_noto  S_noto_1080_1 = {&var1705,&var1561};
_S_noto  S_noto_1059_1 = {&var1195,&var1562};
_S_noto  S_noto_1070_1 = {&R8IS11LDU,&var1563};
_S_charint  S_charint_994_1 = {&var1566,&var1564};
_S_ornc  S_ornc_1003_1 = {array_m1003_x_1,&iRM_3_,&var1565,&var1566};
_S_fsumz  S_fsumz_995_1 = {&var1564,&iRM_1_,&var1567};
_S_cnshd  S_cnshd_1005_1 = {&R0MD34LP1,&var1981,&var1224,&var565,&var1565,&var915,&var916,&iRM_1_,array_m1005_Lt_fw_1,array_m1005_Vr_fw_1,&iRM_1_,array_m1005_Lt_bw_1,array_m1005_Vr_bw_1,&fEM_A3UC08RDU,&fEM_A3UC07RDU,&fEM_A3UL01RDU,&fEM_A3UC02RDU,&var1568,&vainSBool,&var1569,&var1570,&var1571,&var1572,&var1573,&var1574,&var1575,&var1576,&var1577,&var1578,&internal1_m1005_X0,&internal1_m1005_t0,&internal1_m1005_BLDv0};
_S_zpfs  S_zpfs_1028_1 = {&var1587,&fRM_2_0,&var1579,&internal1_m1028_tx,&internal1_m1028_y0};
_S_zpfs  S_zpfs_1027_1 = {&var1586,&fRM_3_0,&var1580,&internal1_m1027_tx,&internal1_m1027_y0};
_S_fnapb  S_fnapb_1035_1 = {&var1981,&var1224,&var914,&R0MD34LP1,&var1570,&var1577,&fEM_B8UV04RDU,&fEM_A3UV01RDU,&fEM_A3UV02RDU,&fEM_A3UC06RDU,&fEM_A3UC05RDU,&iRM_60_,&fEM_A3UL04RDU,&fEM_A3UL05RDU,&fEM_A3UL03RDU,&var1581,&var1582,&var1583,&var1584,&var1585,&var1586,&var1587,&vainSFloat,&internal1_m1035_xptr,array_m1035_x0_1,array_m1035_tim0_1,&internal1_m1035_sumtim,&internal1_m1035_StSpeed,&internal1_m1035_Vz0,&internal1_m1035_flRazg,&internal1_m1035_DelSp,&internal1_m1035_z0,&internal1_m1035_txZS,&internal1_m1035_tx,&internal1_m1035_txd,&internal1_m1035_txMBl,&internal1_m1035_txBl,&internal1_m1035_Speed0,&internal1_m1035_xz0,&internal1_m1035_tz0,&internal1_m1035_Shift0,&internal1_m1035_ShCntlSp0,&internal1_m1035_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_650_1 = {&var1194,&var1588};
_S_noto  S_noto_615_1 = {&var1695,&var1589};
_S_noto  S_noto_614_1 = {&var1705,&var1590};
_S_noto  S_noto_593_1 = {&var1195,&var1591};
_S_noto  S_noto_603_1 = {&R8IS11LDU,&var1592};
_S_charint  S_charint_541_1 = {&var1595,&var1593};
_S_ornc  S_ornc_547_1 = {array_m547_x_1,&iRM_3_,&var1594,&var1595};
_S_fsumz  S_fsumz_542_1 = {&var1593,&iRM_1_,&var1596};
_S_cnshd  S_cnshd_550_1 = {&R0MD34LP1,&var1991,&var1226,&var569,&var1594,&var986,&var980,&iRM_2_,array_m550_Lt_fw_1,array_m550_Vr_fw_1,&iRM_1_,array_m550_Lt_bw_1,array_m550_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1597,&vainSBool,&var1598,&var1599,&var1600,&var1601,&var1602,&var1603,&var1604,&var1605,&var1606,&var1607,&internal1_m550_X0,&internal1_m550_t0,&internal1_m550_BLDv0};
_S_zpfs  S_zpfs_569_1 = {&var1616,&fRM_2_0,&var1608,&internal1_m569_tx,&internal1_m569_y0};
_S_zpfs  S_zpfs_568_1 = {&var1615,&fRM_3_0,&var1609,&internal1_m568_tx,&internal1_m568_y0};
_S_fnapb  S_fnapb_573_1 = {&var1991,&var1226,&var984,&R0MD34LP1,&var1599,&var1606,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1610,&var1611,&var1612,&var1613,&var1614,&var1615,&var1616,&vainSFloat,&internal1_m573_xptr,array_m573_x0_1,array_m573_tim0_1,&internal1_m573_sumtim,&internal1_m573_StSpeed,&internal1_m573_Vz0,&internal1_m573_flRazg,&internal1_m573_DelSp,&internal1_m573_z0,&internal1_m573_txZS,&internal1_m573_tx,&internal1_m573_txd,&internal1_m573_txMBl,&internal1_m573_txBl,&internal1_m573_Speed0,&internal1_m573_xz0,&internal1_m573_tz0,&internal1_m573_Shift0,&internal1_m573_ShCntlSp0,&internal1_m573_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_715_1 = {&R0MD33LP1,&var1617};
_S_noto  S_noto_287_1 = {&var1179,&var1618};
_S_newstage  S_newstage_211_1 = {&var1627,&var1594,&var1630,&var1597,&var1619};
_S_rs  S_rs_694_1 = {&var1009,&var1021,&var1620,&vainSBool,&internal1_m694_q0};
_S_orn  S_orn_250_1 = {array_m250_x_1,&iRM_12_,&var1621};
_S_noto  S_noto_249_1 = {&var1695,&var1622};
_S_noto  S_noto_248_1 = {&var1705,&var1623};
_S_noto  S_noto_226_1 = {&var1195,&var1624};
_S_noto  S_noto_237_1 = {&R8IS11LDU,&var1625};
_S_charint  S_charint_165_1 = {&var1628,&var1626};
_S_ornc  S_ornc_172_1 = {array_m172_x_1,&iRM_3_,&var1627,&var1628};
_S_fsumz  S_fsumz_166_1 = {&var1626,&iRM_1_,&var1629};
_S_cnshd  S_cnshd_176_1 = {&R0MD34LP1,&var1969,&var1227,&var573,&var1627,&var966,&var959,&iRM_2_,array_m176_Lt_fw_1,array_m176_Vr_fw_1,&iRM_1_,array_m176_Lt_bw_1,array_m176_Vr_bw_1,&fEM_A1UC08RDU,&fEM_A1UC07RDU,&fEM_A1UL01RDU,&fEM_A1UC02RDU,&var1630,&vainSBool,&var1631,&var1632,&var1633,&var1634,&var1635,&var1636,&var1637,&var1638,&var1639,&var1640,&internal1_m176_X0,&internal1_m176_t0,&internal1_m176_BLDv0};
_S_fnapb  S_fnapb_201_1 = {&var1969,&var1227,&var962,&R0MD34LP1,&var1632,&var1639,&fEM_B8UV04RDU,&fEM_A1UV01RDU,&fEM_A1UV02RDU,&fEM_A1UC06RDU,&fEM_A1UC05RDU,&iRM_150_,&fEM_A1UL04RDU,&fEM_A1UL05RDU,&fEM_A1UL03RDU,&var1641,&var1642,&var1643,&var1644,&var1645,&var1646,&var1647,&vainSFloat,&internal1_m201_xptr,array_m201_x0_1,array_m201_tim0_1,&internal1_m201_sumtim,&internal1_m201_StSpeed,&internal1_m201_Vz0,&internal1_m201_flRazg,&internal1_m201_DelSp,&internal1_m201_z0,&internal1_m201_txZS,&internal1_m201_tx,&internal1_m201_txd,&internal1_m201_txMBl,&internal1_m201_txBl,&internal1_m201_Speed0,&internal1_m201_xz0,&internal1_m201_tz0,&internal1_m201_Shift0,&internal1_m201_ShCntlSp0,&internal1_m201_ShiftControl,&bFirstEnterFlag};
_S_rs  S_rs_720_1 = {&var1020,&var1023,&var1648,&vainSBool,&internal1_m720_q0};
_S_newstage  S_newstage_513_1 = {&var1667,&var1658,&var1666,&var1657,&var1649};
_S_samhd  S_samhd_517_1 = {&R0MD34LP1,&var989,&var989,&var623,&var622,&R2VS12LDU,&R2VS22LDU,&R2IS11LDU,&R2IS11LDU,&R2IS21LDU,&R2IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1650,&var1651,&var1652,&var1653,&var1654,&var1655,&vainSBool,&vainSBool,&var1656,&var1657,&var1658,&internal1_m517_DvUp0,&internal1_m517_DvDw0,&internal1_m517_FDvUp0,&internal1_m517_FDvDw0,&internal1_m517_BlDv0,&internal1_m517_Pkv0,&internal1_m517_Pkav0,&internal1_m517_Zkv0,&internal1_m517_Zkav0,&internal1_m517_txNm,&internal1_m517_txSm,&internal1_m517_txHr,&internal1_m517_txLd,&internal1_m517_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_511_1 = {&R0MD34LP1,&var990,&var990,&var621,&var620,&R1VS12LDU,&R1VS22LDU,&R1IS11LDU,&R1IS11LDU,&R1IS21LDU,&R1IS21LDU,&bRM_0_,&fEM_R1UZ05RDU,&fEM_R1UZ03RDU,&fEM_R1UZ04RDU,&var1659,&var1660,&var1661,&var1662,&var1663,&var1664,&vainSBool,&vainSBool,&var1665,&var1666,&var1667,&internal1_m511_DvUp0,&internal1_m511_DvDw0,&internal1_m511_FDvUp0,&internal1_m511_FDvDw0,&internal1_m511_BlDv0,&internal1_m511_Pkv0,&internal1_m511_Pkav0,&internal1_m511_Zkv0,&internal1_m511_Zkav0,&internal1_m511_txNm,&internal1_m511_txSm,&internal1_m511_txHr,&internal1_m511_txLd,&internal1_m511_fef,&bFirstEnterFlag};
_S_orn  S_orn_968_1 = {array_m968_x_1,&iRM_10_,&var1668};
_S_noto  S_noto_972_1 = {&var1695,&var1669};
_S_noto  S_noto_971_1 = {&var1705,&var1670};
_S_noto  S_noto_947_1 = {&var1195,&var1671};
_S_noto  S_noto_959_1 = {&R8IS11LDU,&var1672};
_S_charint  S_charint_899_1 = {&var1675,&var1673};
_S_ornc  S_ornc_905_1 = {array_m905_x_1,&iRM_3_,&var1674,&var1675};
_S_fsumz  S_fsumz_900_1 = {&var1673,&iRM_1_,&var1676};
_S_cnshd  S_cnshd_909_1 = {&R0MD34LP1,&var1984,&var1223,&var1223,&var1674,&var939,&var853,&iRM_2_,array_m909_Lt_fw_1,array_m909_Vr_fw_1,&iRM_1_,array_m909_Lt_bw_1,array_m909_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1677,&vainSBool,&var1678,&var1679,&var1680,&var1681,&var1682,&var1683,&var1684,&var1685,&var1686,&var1687,&internal1_m909_X0,&internal1_m909_t0,&internal1_m909_BLDv0};
_S_fnapb  S_fnapb_927_1 = {&var1984,&var1223,&var935,&R0MD34LP1,&var1679,&var1686,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL83RDU,&var1688,&var1689,&var1690,&var1691,&var1692,&var1693,&var1694,&vainSFloat,&internal1_m927_xptr,array_m927_x0_1,array_m927_tim0_1,&internal1_m927_sumtim,&internal1_m927_StSpeed,&internal1_m927_Vz0,&internal1_m927_flRazg,&internal1_m927_DelSp,&internal1_m927_z0,&internal1_m927_txZS,&internal1_m927_tx,&internal1_m927_txd,&internal1_m927_txMBl,&internal1_m927_txBl,&internal1_m927_Speed0,&internal1_m927_xz0,&internal1_m927_tz0,&internal1_m927_Shift0,&internal1_m927_ShCntlSp0,&internal1_m927_ShiftControl,&bFirstEnterFlag};
_S_cnshd  S_cnshd_1804_1 = {&R0MD34LP1,&var1975,&var557,&var557,&var763,&var766,&lRM_1_,&iRM_1_,array_m1804_Lt_fw_1,array_m1804_Vr_fw_1,&iRM_1_,array_m1804_Lt_bw_1,array_m1804_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1695,&vainSBool,&vainSFloat,&var1696,&var1697,&var1698,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1699,&internal1_m1804_X0,&internal1_m1804_t0,&internal1_m1804_BLDv0};
_S_newstage  S_newstage_1410_1 = {&var1713,&var1674,&var1718,&var1677,&var1700};
_S_orn  S_orn_1450_1 = {array_m1450_x_1,&iRM_10_,&var1701};
_S_orn  S_orn_154_1 = {array_m154_x_1,&iRM_5_,&var1702};
_S_noto  S_noto_1449_1 = {&var1695,&var1703};
_S_noto  S_noto_1448_1 = {&var1705,&var1704};
_S_cnshd  S_cnshd_1273_1 = {&R0MD34LP1,&var1972,&var557,&var557,&var1080,&var764,&lRM_1_,&iRM_1_,array_m1273_Lt_fw_1,array_m1273_Vr_fw_1,&iRM_1_,array_m1273_Lt_bw_1,array_m1273_Vr_bw_1,&fEM_B8UC01RDU,&fEM_B8UC02RDU,&fEM_B8UL01RDU,&fRM_0_0,&var1705,&vainSBool,&vainSFloat,&var1706,&var1707,&var1708,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&var1709,&internal1_m1273_X0,&internal1_m1273_t0,&internal1_m1273_BLDv0};
_S_noto  S_noto_1423_1 = {&var1195,&var1710};
_S_noto  S_noto_1437_1 = {&R8IS11LDU,&var1711};
_S_charint  S_charint_1360_1 = {&var1714,&var1712};
_S_ornc  S_ornc_1368_1 = {array_m1368_x_1,&iRM_3_,&var1713,&var1714};
_S_noto  S_noto_679_1 = {&lEM_R0MD01LC1,&var1715};
_S_fsumz  S_fsumz_1361_1 = {&var1712,&iRM_1_,&var1716};
_S_rs  S_rs_692_1 = {&var1031,&var1033,&var1717,&vainSBool,&internal1_m692_q0};
_S_cnshd  S_cnshd_1370_1 = {&R0MD34LP1,&var1987,&var1222,&var1222,&var1713,&var856,&var849,&iRM_2_,array_m1370_Lt_fw_1,array_m1370_Vr_fw_1,&iRM_1_,array_m1370_Lt_bw_1,array_m1370_Vr_bw_1,&fEM_A2UC08RDU,&fEM_A2UC07RDU,&fEM_A2UL01RDU,&fEM_A2UC02RDU,&var1718,&vainSBool,&var1719,&var1720,&var1721,&var1722,&var1723,&var1724,&var1725,&var1726,&var1727,&var1728,&internal1_m1370_X0,&internal1_m1370_t0,&internal1_m1370_BLDv0};
_S_zpfs  S_zpfs_1398_1 = {&var1737,&fRM_2_0,&var1729,&internal1_m1398_tx,&internal1_m1398_y0};
_S_zpfs  S_zpfs_1397_1 = {&var1736,&fRM_3_0,&var1730,&internal1_m1397_tx,&internal1_m1397_y0};
_S_fnapb  S_fnapb_1405_1 = {&var1987,&var1222,&var857,&R0MD34LP1,&var1720,&var1727,&fEM_B8UV04RDU,&fEM_A2UV01RDU,&fEM_A2UV02RDU,&fEM_A2UC06RDU,&fEM_A2UC05RDU,&iRM_80_,&fEM_A2UL04RDU,&fEM_A2UL05RDU,&fEM_A2UL03RDU,&var1731,&var1732,&var1733,&var1734,&var1735,&var1736,&var1737,&vainSFloat,&internal1_m1405_xptr,array_m1405_x0_1,array_m1405_tim0_1,&internal1_m1405_sumtim,&internal1_m1405_StSpeed,&internal1_m1405_Vz0,&internal1_m1405_flRazg,&internal1_m1405_DelSp,&internal1_m1405_z0,&internal1_m1405_txZS,&internal1_m1405_tx,&internal1_m1405_txd,&internal1_m1405_txMBl,&internal1_m1405_txBl,&internal1_m1405_Speed0,&internal1_m1405_xz0,&internal1_m1405_tz0,&internal1_m1405_Shift0,&internal1_m1405_ShCntlSp0,&internal1_m1405_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_1785_1 = {&R8IS11LDU,&var1738};
_S_rs  S_rs_712_1 = {&var1034,&var1035,&var1739,&vainSBool,&internal1_m712_q0};
_S_zpfs  S_zpfs_1818_1 = {&var1750,&fRM_2_0,&var1740,&internal1_m1818_tx,&internal1_m1818_y0};
_S_zpfs  S_zpfs_1822_1 = {&var1749,&fRM_3_0,&var1741,&internal1_m1822_tx,&internal1_m1822_y0};
_S_samhd  S_samhd_1807_1 = {&R0MD34LP1,&var766,&var766,&var1697,&var1698,&var1744,&var1745,&A8IS12LDU,&A8IS12LDU,&A8IS22LDU,&A8IS22LDU,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&var1742,&var1743,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&internal1_m1807_DvUp0,&internal1_m1807_DvDw0,&internal1_m1807_FDvUp0,&internal1_m1807_FDvDw0,&internal1_m1807_BlDv0,&internal1_m1807_Pkv0,&internal1_m1807_Pkav0,&internal1_m1807_Zkv0,&internal1_m1807_Zkav0,&internal1_m1807_txNm,&internal1_m1807_txSm,&internal1_m1807_txHr,&internal1_m1807_txLd,&internal1_m1807_fef,&bFirstEnterFlag};
_S_fnapb  S_fnapb_1826_1 = {&var1975,&var557,&var762,&R0MD34LP1,&var1696,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&var1744,&var1745,&var1746,&var1747,&var1748,&var1749,&var1750,&vainSFloat,&internal1_m1826_xptr,array_m1826_x0_1,array_m1826_tim0_1,&internal1_m1826_sumtim,&internal1_m1826_StSpeed,&internal1_m1826_Vz0,&internal1_m1826_flRazg,&internal1_m1826_DelSp,&internal1_m1826_z0,&internal1_m1826_txZS,&internal1_m1826_tx,&internal1_m1826_txd,&internal1_m1826_txMBl,&internal1_m1826_txBl,&internal1_m1826_Speed0,&internal1_m1826_xz0,&internal1_m1826_tz0,&internal1_m1826_Shift0,&internal1_m1826_ShCntlSp0,&internal1_m1826_ShiftControl,&bFirstEnterFlag};
_S_zpfs  S_zpfs_1290_1 = {&var1767,&fRM_2_0,&var1751,&internal1_m1290_tx,&internal1_m1290_y0};
_S_zpfs  S_zpfs_1294_1 = {&var1766,&fRM_3_0,&var1752,&internal1_m1294_tx,&internal1_m1294_y0};
_S_noto  S_noto_1254_1 = {&R8IS11LDU,&var1753};
_S_orn  S_orn_1236_1 = {array_m1236_x_1,&iRM_8_,&var1754};
_S_noto  S_noto_681_1 = {&var1758,&var1755};
_S_rs  S_rs_702_1 = {&var1036,&var1037,&var1756,&vainSBool,&internal1_m702_q0};
_S_orn  S_orn_669_1 = {array_m669_x_1,&iRM_18_,&var1757};
_S_rs  S_rs_667_1 = {&var1522,&var1152,&var1758,&vainSBool,&internal1_m667_q0};
_S_samhd  S_samhd_1281_1 = {&R0MD34LP1,&var764,&var764,&var1707,&var1708,&var1761,&var1762,&var405,&var405,&var404,&var404,&bRM_3_,&fEM_B8UL05RDU,&fEM_B8UL03RDU,&fEM_B8UL07RDU,&vainSBool,&vainSBool,&var1759,&var1760,&vainSBool,&vainSBool,&vainSBool,&vainSBool,&vainSInt,&vainSBool,&vainSBool,&internal1_m1281_DvUp0,&internal1_m1281_DvDw0,&internal1_m1281_FDvUp0,&internal1_m1281_FDvDw0,&internal1_m1281_BlDv0,&internal1_m1281_Pkv0,&internal1_m1281_Pkav0,&internal1_m1281_Zkv0,&internal1_m1281_Zkav0,&internal1_m1281_txNm,&internal1_m1281_txSm,&internal1_m1281_txHr,&internal1_m1281_txLd,&internal1_m1281_fef,&bFirstEnterFlag};
_S_fnapb  S_fnapb_1300_1 = {&var1972,&var557,&var1079,&R0MD34LP1,&var1706,&fEM_B8UV03RDU,&fEM_B8UV04RDU,&fEM_B8UV01RDU,&fEM_B8UV02RDU,&fEM_B8UC06RDU,&fEM_B8UC05RDU,&iRM_20_,&fEM_B8UL04RDU,&fEM_B8UL06RDU,&fEM_B8UL03RDU,&var1761,&var1762,&var1763,&var1764,&var1765,&var1766,&var1767,&vainSFloat,&internal1_m1300_xptr,array_m1300_x0_1,array_m1300_tim0_1,&internal1_m1300_sumtim,&internal1_m1300_StSpeed,&internal1_m1300_Vz0,&internal1_m1300_flRazg,&internal1_m1300_DelSp,&internal1_m1300_z0,&internal1_m1300_txZS,&internal1_m1300_tx,&internal1_m1300_txd,&internal1_m1300_txMBl,&internal1_m1300_txBl,&internal1_m1300_Speed0,&internal1_m1300_xz0,&internal1_m1300_tz0,&internal1_m1300_Shift0,&internal1_m1300_ShCntlSp0,&internal1_m1300_ShiftControl,&bFirstEnterFlag};
_S_noto  S_noto_807_1 = {&A5IS21LDU,&var1768};
_S_vmemb  S_vmemb_830_1 = {&var1770,&var1769,&internal1_m830_x0};
_S_noto  S_noto_838_1 = {&var406,&var1770};
_S_vmemb  S_vmemb_799_1 = {&var1768,&var1771,&internal1_m799_x0};
_S_vmemb  S_vmemb_741_1 = {&var1786,&var1772,&internal1_m741_x0};
_S_newstage  S_newstage_877_1 = {&var1830,&var1821,&var1829,&var1820,&var1773};
_S_newstage  S_newstage_1336_1 = {&var1812,&var1803,&var1811,&var1802,&var1774};
_S_newstage  S_newstage_424_1 = {&var1857,&var1848,&var1856,&var1847,&var1775};
_S_noto  S_noto_849_1 = {&var407,&var1776};
_S_rs  S_rs_855_1 = {&var1100,&var1775,&var1777,&vainSBool,&internal1_m855_q0};
_S_rs  S_rs_850_1 = {&var1101,&var1201,&var1778,&vainSBool,&internal1_m850_q0};
_S_noto  S_noto_842_1 = {&var1859,&var1779};
_S_noto  S_noto_840_1 = {&var1860,&var1780};
_S_rs  S_rs_818_1 = {&var1105,&var1775,&var1781,&vainSBool,&internal1_m818_q0};
_S_rs  S_rs_822_1 = {&var1104,&var1773,&var1782,&vainSBool,&internal1_m822_q0};
_S_rs  S_rs_831_1 = {&var1171,&var1110,&var1783,&vainSBool,&internal1_m831_q0};
_S_rs  S_rs_843_1 = {&var1102,&var1108,&var1784,&vainSBool,&internal1_m843_q0};
_S_noto  S_noto_798_1 = {&var407,&var1785};
_S_noto  S_noto_734_1 = {&var406,&var1786};
_S_noto  S_noto_463_1 = {&R8IS11LDU,&var1787};
_S_orn  S_orn_481_1 = {array_m481_x_1,&iRM_7_,&var1788};
_S_orn  S_orn_459_1 = {array_m459_x_1,&iRM_7_,&var1789};
_S_rs  S_rs_820_1 = {&var1109,&var1114,&var1790,&vainSBool,&internal1_m820_q0};
_S_noto  S_noto_162_1 = {&B2IS12LDU,&var1791};
_S_noto  S_noto_151_1 = {&A2IS12LDU,&var1792};
_S_noto  S_noto_152_1 = {&B1IS12LDU,&var1793};
_S_noto  S_noto_160_1 = {&A1IS12LDU,&var1794};
_S_samhd  S_samhd_1343_1 = {&var1083,&var1084,&var1084,&var1397,&var1396,&var1397,&var1396,&B4IS11LDU,&B4IS11LDU,&B4IS21LDU,&B4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1795,&var1796,&var1797,&vainSBool,&var1798,&vainSBool,&var1799,&var1800,&var1801,&var1802,&var1803,&internal1_m1343_DvUp0,&internal1_m1343_DvDw0,&internal1_m1343_FDvUp0,&internal1_m1343_FDvDw0,&internal1_m1343_BlDv0,&internal1_m1343_Pkv0,&internal1_m1343_Pkav0,&internal1_m1343_Zkv0,&internal1_m1343_Zkav0,&internal1_m1343_txNm,&internal1_m1343_txSm,&internal1_m1343_txHr,&internal1_m1343_txLd,&internal1_m1343_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_1333_1 = {&var1083,&var1086,&var1086,&var1397,&var1396,&var1397,&var1396,&A4IS11LDU,&A4IS11LDU,&A4IS21LDU,&A4IS21LDU,&bRM_1_,&fEM_A4UZ05RDU,&fEM_A4UZ03RDU,&fEM_A4UZ04RDU,&var1804,&var1805,&var1806,&vainSBool,&var1807,&vainSBool,&var1808,&var1809,&var1810,&var1811,&var1812,&internal1_m1333_DvUp0,&internal1_m1333_DvDw0,&internal1_m1333_FDvUp0,&internal1_m1333_FDvDw0,&internal1_m1333_BlDv0,&internal1_m1333_Pkv0,&internal1_m1333_Pkav0,&internal1_m1333_Zkv0,&internal1_m1333_Zkav0,&internal1_m1333_txNm,&internal1_m1333_txSm,&internal1_m1333_txHr,&internal1_m1333_txLd,&internal1_m1333_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_879_1 = {&R0MD34LP1,&var941,&var941,&var1202,&var1097,&B5VS12LDU,&B5VS22LDU,&B5IS11LDU,&B5IS11LDU,&B5IS21LDU,&B5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1813,&var1814,&var1815,&var1816,&var1817,&var1818,&vainSBool,&vainSBool,&var1819,&var1820,&var1821,&internal1_m879_DvUp0,&internal1_m879_DvDw0,&internal1_m879_FDvUp0,&internal1_m879_FDvDw0,&internal1_m879_BlDv0,&internal1_m879_Pkv0,&internal1_m879_Pkav0,&internal1_m879_Zkv0,&internal1_m879_Zkav0,&internal1_m879_txNm,&internal1_m879_txSm,&internal1_m879_txHr,&internal1_m879_txLd,&internal1_m879_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_875_1 = {&R0MD34LP1,&var943,&var943,&var1202,&var1097,&A5VS12LDU,&A5VS22LDU,&A5IS11LDU,&A5IS11LDU,&A5IS21LDU,&A5IS21LDU,&bRM_0_,&fEM_A5UZ05RDU,&fEM_A5UZ03RDU,&fEM_A5UZ04RDU,&var1822,&var1823,&var1824,&var1825,&var1826,&var1827,&vainSBool,&vainSBool,&var1828,&var1829,&var1830,&internal1_m875_DvUp0,&internal1_m875_DvDw0,&internal1_m875_FDvUp0,&internal1_m875_FDvDw0,&internal1_m875_BlDv0,&internal1_m875_Pkv0,&internal1_m875_Pkav0,&internal1_m875_Zkv0,&internal1_m875_Zkav0,&internal1_m875_txNm,&internal1_m875_txSm,&internal1_m875_txHr,&internal1_m875_txLd,&internal1_m875_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_390_1 = {&R0MD34LP1,&var625,&var624,&var1106,&var1099,&R4VS12LDU,&R4VS22LDU,&R4IS11LDU,&R4IS12LDU,&R4IS21LDU,&R4IS22LDU,&bRM_0_,&fEM_R4UZ05RDU,&fEM_R4UZ03RDU,&fEM_R4UZ04RDU,&var1831,&var1832,&var1833,&var1834,&var1835,&var1836,&vainSBool,&vainSBool,&var1837,&var1838,&vainSBool,&internal1_m390_DvUp0,&internal1_m390_DvDw0,&internal1_m390_FDvUp0,&internal1_m390_FDvDw0,&internal1_m390_BlDv0,&internal1_m390_Pkv0,&internal1_m390_Pkav0,&internal1_m390_Zkv0,&internal1_m390_Zkav0,&internal1_m390_txNm,&internal1_m390_txSm,&internal1_m390_txHr,&internal1_m390_txLd,&internal1_m390_fef,&bFirstEnterFlag};
_S_noto  S_noto_754_1 = {&R8IS11LDU,&var1839};
_S_samhd  S_samhd_427_1 = {&R0MD34LP1,&var1788,&var1172,&var1178,&var1098,&B6VS12LDU,&B6VS22LDU,&B6IS11LDU,&B6IS11LDU,&B6IS21LDU,&B6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1840,&var1841,&var1842,&var1843,&var1844,&var1845,&vainSBool,&vainSBool,&var1846,&var1847,&var1848,&internal1_m427_DvUp0,&internal1_m427_DvDw0,&internal1_m427_FDvUp0,&internal1_m427_FDvDw0,&internal1_m427_BlDv0,&internal1_m427_Pkv0,&internal1_m427_Pkav0,&internal1_m427_Zkv0,&internal1_m427_Zkav0,&internal1_m427_txNm,&internal1_m427_txSm,&internal1_m427_txHr,&internal1_m427_txLd,&internal1_m427_fef,&bFirstEnterFlag};
_S_samhd  S_samhd_421_1 = {&R0MD34LP1,&var1789,&var1173,&var1178,&var1098,&A6VS12LDU,&A6VS22LDU,&A6IS11LDU,&A6IS11LDU,&A6IS21LDU,&A6IS21LDU,&bRM_0_,&fEM_A6UZ05RDU,&fEM_A6UZ03RDU,&fEM_A6UZ04RDU,&var1849,&var1850,&var1851,&var1852,&var1853,&var1854,&vainSBool,&vainSBool,&var1855,&var1856,&var1857,&internal1_m421_DvUp0,&internal1_m421_DvDw0,&internal1_m421_FDvUp0,&internal1_m421_FDvDw0,&internal1_m421_BlDv0,&internal1_m421_Pkv0,&internal1_m421_Pkav0,&internal1_m421_Zkv0,&internal1_m421_Zkav0,&internal1_m421_txNm,&internal1_m421_txSm,&internal1_m421_txHr,&internal1_m421_txLd,&internal1_m421_fef,&bFirstEnterFlag};
_S_orn  S_orn_854_1 = {array_m854_x_1,&iRM_17_,&var1858};
_S_rs  S_rs_827_1 = {&var1112,&var316,&var1859,&vainSBool,&internal1_m827_q0};
_S_rs  S_rs_824_1 = {&var1113,&var317,&var1860,&vainSBool,&internal1_m824_q0};
_S_orni  S_orni_140_1 = {array_m140_x_1,&iRM_21_,&var1861,&vainSLong};
_S_equz_p  S_equz_p_80_1 = {&R0MW11IP2,&iRM_6_,&var1862};
_S_equz_p  S_equz_p_77_1 = {&R0MW11IP2,&iRM_5_,&var1863};
_S_equz_p  S_equz_p_76_1 = {&R0MW11IP2,&iRM_4_,&var1864};
_S_equz_p  S_equz_p_72_1 = {&R0MW11IP2,&iRM_3_,&var1865};
_S_equz_p  S_equz_p_71_1 = {&R0MW11IP2,&iRM_2_,&var1866};
_S_equz_p  S_equz_p_68_1 = {&R0MW11IP2,&iRM_1_,&var1867};
_S_equz_p  S_equz_p_64_1 = {&R0MW14IP1,&iRM_3_,&var1868};
_S_equz_p  S_equz_p_57_1 = {&R0MW14IP1,&iRM_1_,&vainSBool};
_S_equz_p  S_equz_p_60_1 = {&R0MW14IP1,&iRM_2_,&var1869};
_S_equz_p  S_equz_p_51_1 = {&R0MW11IP1,&iRM_3_,&var1870};
_S_equz_p  S_equz_p_43_1 = {&R0MW11IP1,&iRM_1_,&var1871};
_S_equz_p  S_equz_p_46_1 = {&R0MW11IP1,&iRM_2_,&var1872};
_S_equz_p  S_equz_p_106_1 = {&R0MW16IP1,&iRM_11_,&var1873};
_S_equz_p  S_equz_p_99_1 = {&R0MW16IP1,&iRM_4_,&var1874};
_S_equz_p  S_equz_p_98_1 = {&R0MW16IP1,&iRM_3_,&var1875};
_S_equz_p  S_equz_p_97_1 = {&R0MW16IP1,&iRM_2_,&var1876};
_S_equz_p  S_equz_p_10_1 = {&R0MW12IP1,&iRM_4_,&var1877};
_S_equz_p  S_equz_p_7_1 = {&R0MW12IP1,&iRM_3_,&var1878};
_S_equz_p  S_equz_p_2_1 = {&R0MW12IP1,&iRM_1_,&var1879};
_S_equz_p  S_equz_p_4_1 = {&R0MW12IP1,&iRM_2_,&var1880};


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
   var45.f=0.0;
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
   var62.b=0;
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
   var262.i=0;
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
   var279.b=0;
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
   var388.i=0;
   var389.b=0;
   var390.b=0;
   var391.i=0;
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
   var405.b=0;
   var406.b=0;
   var407.b=0;
   var408.b=0;
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
   var432.f=0.0;
   var433.b=0;
   var434.b=0;
   var435.b=0;
   var436.b=0;
   var437.b=0;
   var438.b=0;
   var439.b=0;
   var440.b=0;
   var441.b=0;
   var442.f=0.0;
   var443.f=0.0;
   var444.b=0;
   var445.b=0;
   var446.b=0;
   var447.f=0.0;
   var448.b=0;
   var449.b=0;
   var450.f=0.0;
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
   var461.f=0.0;
   var462.f=0.0;
   var463.b=0;
   var464.f=0.0;
   var465.f=0.0;
   var466.i=0;
   var467.b=0;
   var468.b=0;
   var469.b=0;
   var470.b=0;
   var471.b=0;
   var472.b=0;
   var473.b=0;
   var474.b=0;
   var475.b=0;
   var476.b=0;
   var477.b=0;
   var478.b=0;
   var479.b=0;
   var480.b=0;
   var481.b=0;
   var482.b=0;
   var483.b=0;
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
   var557.f=0.0;
   var558.b=0;
   var559.b=0;
   var560.b=0;
   var561.f=0.0;
   var562.b=0;
   var563.b=0;
   var564.b=0;
   var565.f=0.0;
   var566.b=0;
   var567.b=0;
   var568.b=0;
   var569.f=0.0;
   var570.b=0;
   var571.b=0;
   var572.b=0;
   var573.f=0.0;
   var574.b=0;
   var575.b=0;
   var576.b=0;
   var577.b=0;
   var578.b=0;
   var579.b=0;
   var580.b=0;
   var581.b=0;
   var582.b=0;
   var583.b=0;
   var584.b=0;
   var585.b=0;
   var586.b=0;
   var587.b=0;
   var588.b=0;
   var589.b=0;
   var590.b=0;
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
   var659.f=0.0;
   var660.f=0.0;
   var661.b=0;
   var662.f=0.0;
   var663.f=0.0;
   var664.b=0;
   var665.f=0.0;
   var666.f=0.0;
   var667.b=0;
   var668.f=0.0;
   var669.f=0.0;
   var670.b=0;
   var671.b=0;
   var672.f=0.0;
   var673.f=0.0;
   var674.b=0;
   var675.b=0;
   var676.b=0;
   var677.b=0;
   var678.b=0;
   var679.b=0;
   var680.b=0;
   var681.b=0;
   var682.b=0;
   var683.b=0;
   var684.b=0;
   var685.b=0;
   var686.b=0;
   var687.b=0;
   var688.b=0;
   var689.b=0;
   var690.b=0;
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
   var803.l=0L;
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
   var820.b=0;
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
   var1213.f=0.0;
   var1214.b=0;
   var1215.f=0.0;
   var1216.b=0;
   var1217.f=0.0;
   var1218.b=0;
   var1219.b=0;
   var1220.b=0;
   var1221.b=0;
   var1222.f=0.0;
   var1223.f=0.0;
   var1224.f=0.0;
   var1225.f=0.0;
   var1226.f=0.0;
   var1227.f=0.0;
   var1228.b=0;
   var1229.b=0;
   var1230.b=0;
   var1231.b=0;
   var1232.b=0;
   var1233.b=0;
   var1234.b=0;
   var1235.b=0;
   var1236.b=0;
   var1237.b=0;
   var1238.b=0;
   var1239.b=0;
   var1240.b=0;
   var1241.b=0;
   var1242.b=0;
   var1243.b=0;
   var1244.b=0;
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
   var1287.i=0;
   var1288.i=0;
   var1289.b=0;
   var1290.b=0;
   var1291.b=0;
   var1292.b=0;
   var1293.b=0;
   var1294.b=0;
   var1295.l=0L;
   var1296.b=0;
   var1297.b=0;
   var1298.b=0;
   var1299.i=0;
   var1300.b=0;
   var1301.b=0;
   var1302.b=0;
   var1303.b=0;
   var1304.b=0;
   var1305.b=0;
   var1306.b=0;
   var1307.b=0;
   var1308.b=0;
   var1309.i=0;
   var1310.i=0;
   var1311.b=0;
   var1312.b=0;
   var1313.b=0;
   var1314.b=0;
   var1315.b=0;
   var1316.b=0;
   var1317.b=0;
   var1318.b=0;
   var1319.b=0;
   var1320.b=0;
   var1321.b=0;
   var1322.b=0;
   var1323.b=0;
   var1324.b=0;
   var1325.b=0;
   var1326.b=0;
   var1327.b=0;
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
   var1350.l=0L;
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
   var1367.b=0;
   var1368.b=0;
   var1369.f=0.0;
   var1370.b=0;
   var1371.b=0;
   var1372.b=0;
   var1373.b=0;
   var1374.b=0;
   var1375.f=0.0;
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
   var1386.b=0;
   var1387.b=0;
   var1388.b=0;
   var1389.i=0;
   var1390.b=0;
   var1391.b=0;
   var1392.b=0;
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
   var1406.b=0;
   var1407.b=0;
   var1408.b=0;
   var1409.b=0;
   var1410.b=0;
   var1411.b=0;
   var1412.b=0;
   var1413.b=0;
   var1414.f=0.0;
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
   var1431.b=0;
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
   var1508.l=0L;
   var1509.b=0;
   var1510.i=0;
   var1511.i=0;
   var1512.b=0;
   var1513.f=0.0;
   var1514.f=0.0;
   var1515.f=0.0;
   var1516.b=0;
   var1517.b=0;
   var1518.b=0;
   var1519.b=0;
   var1520.b=0;
   var1521.b=0;
   var1522.b=0;
   var1523.b=0;
   var1524.b=0;
   var1525.b=0;
   var1526.b=0;
   var1527.b=0;
   var1528.b=0;
   var1529.b=0;
   var1530.b=0;
   var1531.b=0;
   var1532.i=0;
   var1533.b=0;
   var1534.c=0;
   var1535.i=0;
   var1536.b=0;
   var1537.f=0.0;
   var1538.b=0;
   var1539.b=0;
   var1540.b=0;
   var1541.b=0;
   var1542.b=0;
   var1543.b=0;
   var1544.b=0;
   var1545.f=0.0;
   var1546.c=0;
   var1547.b=0;
   var1548.b=0;
   var1549.b=0;
   var1550.b=0;
   var1551.f=0.0;
   var1552.b=0;
   var1553.b=0;
   var1554.b=0;
   var1555.b=0;
   var1556.b=0;
   var1557.b=0;
   var1558.b=0;
   var1559.b=0;
   var1560.b=0;
   var1561.b=0;
   var1562.b=0;
   var1563.b=0;
   var1564.i=0;
   var1565.b=0;
   var1566.c=0;
   var1567.i=0;
   var1568.b=0;
   var1569.f=0.0;
   var1570.b=0;
   var1571.b=0;
   var1572.b=0;
   var1573.b=0;
   var1574.b=0;
   var1575.b=0;
   var1576.b=0;
   var1577.f=0.0;
   var1578.c=0;
   var1579.b=0;
   var1580.b=0;
   var1581.b=0;
   var1582.b=0;
   var1583.f=0.0;
   var1584.b=0;
   var1585.b=0;
   var1586.b=0;
   var1587.b=0;
   var1588.b=0;
   var1589.b=0;
   var1590.b=0;
   var1591.b=0;
   var1592.b=0;
   var1593.i=0;
   var1594.b=0;
   var1595.c=0;
   var1596.i=0;
   var1597.b=0;
   var1598.f=0.0;
   var1599.b=0;
   var1600.b=0;
   var1601.b=0;
   var1602.b=0;
   var1603.b=0;
   var1604.b=0;
   var1605.b=0;
   var1606.f=0.0;
   var1607.c=0;
   var1608.b=0;
   var1609.b=0;
   var1610.b=0;
   var1611.b=0;
   var1612.f=0.0;
   var1613.b=0;
   var1614.b=0;
   var1615.b=0;
   var1616.b=0;
   var1617.b=0;
   var1618.b=0;
   var1619.b=0;
   var1620.b=0;
   var1621.b=0;
   var1622.b=0;
   var1623.b=0;
   var1624.b=0;
   var1625.b=0;
   var1626.i=0;
   var1627.b=0;
   var1628.c=0;
   var1629.i=0;
   var1630.b=0;
   var1631.f=0.0;
   var1632.b=0;
   var1633.b=0;
   var1634.b=0;
   var1635.b=0;
   var1636.b=0;
   var1637.b=0;
   var1638.b=0;
   var1639.f=0.0;
   var1640.c=0;
   var1641.b=0;
   var1642.b=0;
   var1643.f=0.0;
   var1644.b=0;
   var1645.b=0;
   var1646.b=0;
   var1647.b=0;
   var1648.b=0;
   var1649.b=0;
   var1650.b=0;
   var1651.b=0;
   var1652.b=0;
   var1653.b=0;
   var1654.b=0;
   var1655.b=0;
   var1656.i=0;
   var1657.b=0;
   var1658.b=0;
   var1659.b=0;
   var1660.b=0;
   var1661.b=0;
   var1662.b=0;
   var1663.b=0;
   var1664.b=0;
   var1665.i=0;
   var1666.b=0;
   var1667.b=0;
   var1668.b=0;
   var1669.b=0;
   var1670.b=0;
   var1671.b=0;
   var1672.b=0;
   var1673.i=0;
   var1674.b=0;
   var1675.c=0;
   var1676.i=0;
   var1677.b=0;
   var1678.f=0.0;
   var1679.b=0;
   var1680.b=0;
   var1681.b=0;
   var1682.b=0;
   var1683.b=0;
   var1684.b=0;
   var1685.b=0;
   var1686.f=0.0;
   var1687.c=0;
   var1688.b=0;
   var1689.b=0;
   var1690.f=0.0;
   var1691.b=0;
   var1692.b=0;
   var1693.b=0;
   var1694.b=0;
   var1695.b=0;
   var1696.b=0;
   var1697.b=0;
   var1698.b=0;
   var1699.c=0;
   var1700.b=0;
   var1701.b=0;
   var1702.b=0;
   var1703.b=0;
   var1704.b=0;
   var1705.b=0;
   var1706.b=0;
   var1707.b=0;
   var1708.b=0;
   var1709.c=0;
   var1710.b=0;
   var1711.b=0;
   var1712.i=0;
   var1713.b=0;
   var1714.c=0;
   var1715.b=0;
   var1716.i=0;
   var1717.b=0;
   var1718.b=0;
   var1719.f=0.0;
   var1720.b=0;
   var1721.b=0;
   var1722.b=0;
   var1723.b=0;
   var1724.b=0;
   var1725.b=0;
   var1726.b=0;
   var1727.f=0.0;
   var1728.c=0;
   var1729.b=0;
   var1730.b=0;
   var1731.b=0;
   var1732.b=0;
   var1733.f=0.0;
   var1734.b=0;
   var1735.b=0;
   var1736.b=0;
   var1737.b=0;
   var1738.b=0;
   var1739.b=0;
   var1740.b=0;
   var1741.b=0;
   var1742.b=0;
   var1743.b=0;
   var1744.b=0;
   var1745.b=0;
   var1746.f=0.0;
   var1747.b=0;
   var1748.b=0;
   var1749.b=0;
   var1750.b=0;
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
   var1780.b=0;
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
   var1801.i=0;
   var1802.b=0;
   var1803.b=0;
   var1804.b=0;
   var1805.b=0;
   var1806.b=0;
   var1807.b=0;
   var1808.b=0;
   var1809.b=0;
   var1810.i=0;
   var1811.b=0;
   var1812.b=0;
   var1813.b=0;
   var1814.b=0;
   var1815.b=0;
   var1816.b=0;
   var1817.b=0;
   var1818.b=0;
   var1819.i=0;
   var1820.b=0;
   var1821.b=0;
   var1822.b=0;
   var1823.b=0;
   var1824.b=0;
   var1825.b=0;
   var1826.b=0;
   var1827.b=0;
   var1828.i=0;
   var1829.b=0;
   var1830.b=0;
   var1831.b=0;
   var1832.b=0;
   var1833.b=0;
   var1834.b=0;
   var1835.b=0;
   var1836.b=0;
   var1837.i=0;
   var1838.b=0;
   var1839.b=0;
   var1840.b=0;
   var1841.b=0;
   var1842.b=0;
   var1843.b=0;
   var1844.b=0;
   var1845.b=0;
   var1846.i=0;
   var1847.b=0;
   var1848.b=0;
   var1849.b=0;
   var1850.b=0;
   var1851.b=0;
   var1852.b=0;
   var1853.b=0;
   var1854.b=0;
   var1855.i=0;
   var1856.b=0;
   var1857.b=0;
   var1858.b=0;
   var1859.b=0;
   var1860.b=0;
   var1861.b=0;
   var1862.b=0;
   var1863.b=0;
   var1864.b=0;
   var1865.b=0;
   var1866.b=0;
   var1867.b=0;
   var1868.b=0;
   var1869.b=0;
   var1870.b=0;
   var1871.b=0;
   var1872.b=0;
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
   var1906.f=0.0;
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
   var1921.b=0;
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
   var1941.f=0.0;
   var1942.f=0.0;
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
   var1956.b=0;
   var1957.b=0;
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
   var1969.f=0.0;
   var1970.b=0;
   var1971.b=0;
   var1972.f=0.0;
   var1973.b=0;
   var1974.b=0;
   var1975.f=0.0;
   var1976.b=0;
   var1977.b=0;
   var1978.f=0.0;
   var1979.b=0;
   var1980.b=0;
   var1981.f=0.0;
   var1982.b=0;
   var1983.b=0;
   var1984.f=0.0;
   var1985.b=0;
   var1986.b=0;
   var1987.f=0.0;
   var1988.b=0;
   var1989.b=0;
   var1990.b=0;
   var1991.f=0.0;
   var1992.b=0;
   var1993.b=0;
   var1994.b=0;
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
  equz_p(&S_equz_p_18_2);
  scalzz(&S_scalzz_193_2);
  scalzz(&S_scalzz_195_2);
  or2(&S_or2_11_2);
  or2(&S_or2_43_2);
  or2(&S_or2_13_2);
  or2(&S_or2_44_2);
  or2(&S_or2_74_2);
  or2(&S_or2_71_2);
  and3(&S_and3_75_2);
  or2(&S_or2_103_2);
  or2(&S_or2_104_2);
  and3(&S_and3_110_2);
  and4(&S_and4_136_2);
  and4(&S_and4_162_2);
  schl24(&S_schl24_147_2);
  schl24(&S_schl24_151_2);
  noto(&S_noto_240_2);
  noto(&S_noto_241_2);
  noto(&S_noto_242_2);
  noto(&S_noto_262_2);
  noto(&S_noto_263_2);
  noto(&S_noto_264_2);
  fsumo(&S_fsumo_233_2);
  bol(&S_bol_234_2);
  lkb(&S_lkb_76_2);
  lkb(&S_lkb_111_2);
  and4(&S_and4_107_2);
  zzfs(&S_zzfs_127_2);
  zzfs(&S_zzfs_132_2);
  zzfs(&S_zzfs_134_2);
  zzfs(&S_zzfs_141_2);
  zzfs(&S_zzfs_144_2);
  zzfs(&S_zzfs_149_2);
  zzfs(&S_zzfs_155_2);
  zzfs(&S_zzfs_158_2);
  zzfs(&S_zzfs_165_2);
  zzfs(&S_zzfs_172_2);
  zzfs(&S_zzfs_176_2);
  zzfs(&S_zzfs_182_2);
  enctkb(&S_enctkb_77_2);
  enctkb(&S_enctkb_112_2);
  drg(&S_drg_206_2);
  drg(&S_drg_198_2);
  geterr(&S_geterr_197_2);
  drg(&S_drg_216_2);
  drg(&S_drg_209_2);
  geterr(&S_geterr_200_2);
  tprg(&S_tprg_220_2);
  tprg(&S_tprg_227_2);
  noto(&S_noto_231_2);
  noto(&S_noto_222_2);
  andn(&S_andn_138_2);
  noto(&S_noto_145_2);
  andn(&S_andn_166_2);
  noto(&S_noto_177_2);
  andn(&S_andn_179_2);
  noto(&S_noto_180_2);
  and2(&S_and2_230_2);
  and3(&S_and3_19_2);
  and3(&S_and3_47_2);
  and3(&S_and3_23_2);
  and3(&S_and3_51_2);
  and3(&S_and3_81_2);
  or3(&S_or3_135_2);
  or3(&S_or3_161_2);
  and2(&S_and2_223_2);
  or2(&S_or2_204_2);
  or2(&S_or2_208_2);
  lkb(&S_lkb_20_2);
  lkb(&S_lkb_24_2);
  lkb(&S_lkb_48_2);
  lkb(&S_lkb_82_2);
  lkb(&S_lkb_52_2);
  lkb(&S_lkb_108_2);
  enctkb(&S_enctkb_21_2);
  enctkb(&S_enctkb_53_2);
  enctkb(&S_enctkb_49_2);
  enctkb(&S_enctkb_83_2);
  enctkb(&S_enctkb_109_2);
  enctkb(&S_enctkb_16_2);
  noto(&S_noto_142_2);
  noto(&S_noto_160_2);
  and2(&S_and2_246_2);
  and2(&S_and2_267_2);
  ornc(&S_ornc_124_2);
  ornc(&S_ornc_247_2);
  ornc(&S_ornc_268_2);
  noto(&S_noto_253_2);
  noto(&S_noto_269_2);
  or2(&S_or2_271_2);
  ornc(&S_ornc_243_2);
  ornc(&S_ornc_259_2);
  noto(&S_noto_248_2);
  noto(&S_noto_266_2);
  or2(&S_or2_260_2);
  zpfs(&S_zpfs_272_2);
  zpfs(&S_zpfs_244_2);
  setData(idpsa2,&var1882);
  setData(idpsa1,&var1881);
  setData(idR0EE02LDU,&var1050);
  setData(idB8VC01RDU,&var1972);
  setData(idB2VC01RDU,&var1984);
  setData(idA2VC01RDU,&var1987);
  setData(idA3VC01RDU,&var1981);
  setData(idB0VS11LDU,&var1949);
  setData(idA0VS11LDU,&var1950);
  setData(idB0VN01LDU,&var1919);
  setData(idA0VN01LDU,&var1921);
  setData(idB0VP01LDU,&var1955);
  setData(idA0VP01LDU,&var1956);
  setData(idB0VE01LDU,&var1946);
  setData(idA0VE01LDU,&var1948);
  setData(idA3VP82LDU,&var1917);
  setData(idB3VP82LDU,&var1940);
  setData(idB3VP52LDU,&var1965);
  setData(idB3CP02RDU,&var1941);
  setData(idB3VP42LDU,&var1915);
  setData(idA3VP52LDU,&var1968);
  setData(idA3CP02RDU,&var1942);
  setData(idA3VP42LDU,&var1916);
  setData(idA1VC01RDU,&var1969);
  setData(idA8VC01RDU,&var1975);
  setData(idB3VC01RDU,&var1978);
  setData(idB1VC01RDU,&var1991);
  equz_p(&S_equz_p_4_1);
  equz_p(&S_equz_p_2_1);
  equz_p(&S_equz_p_7_1);
  equz_p(&S_equz_p_10_1);
  equz_p(&S_equz_p_97_1);
  equz_p(&S_equz_p_98_1);
  equz_p(&S_equz_p_99_1);
  equz_p(&S_equz_p_106_1);
  equz_p(&S_equz_p_46_1);
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
  noto(&S_noto_840_1);
  noto(&S_noto_807_1);
  noto(&S_noto_1254_1);
  noto(&S_noto_1785_1);
  noto(&S_noto_1437_1);
  noto(&S_noto_959_1);
  noto(&S_noto_237_1);
  noto(&S_noto_603_1);
  noto(&S_noto_1070_1);
  rs(&S_rs_697_1);
  noto(&S_noto_1543_1);
  equz_p(&S_equz_p_32_1);
  equz_p(&S_equz_p_41_1);
  noto(&S_noto_34_1);
  equz_p(&S_equz_p_37_1);
  noto(&S_noto_1998_1);
  noto(&S_noto_1997_1);
  noto(&S_noto_2003_1);
  noto(&S_noto_1999_1);
  noto(&S_noto_2005_1);
  noto(&S_noto_1976_1);
  noto(&S_noto_1977_1);
  noto(&S_noto_1978_1);
  noto(&S_noto_1979_1);
  noto(&S_noto_1980_1);
  noto(&S_noto_2293_1);
  equz_p(&S_equz_p_100_1);
  equz_p(&S_equz_p_101_1);
  equz_p(&S_equz_p_102_1);
  noto(&S_noto_1036_1);
  equz_p(&S_equz_p_103_1);
  equz_p(&S_equz_p_104_1);
  noto(&S_noto_186_1);
  equz_p(&S_equz_p_105_1);
  noto(&S_noto_12_1);
  equz_p(&S_equz_p_2020_1);
  equz_p(&S_equz_p_2019_1);
  equz_p(&S_equz_p_2021_1);
  equz_p(&S_equz_p_2022_1);
  equz_p(&S_equz_p_2023_1);
  noto(&S_noto_1985_1);
  noto(&S_noto_2039_1);
  noto(&S_noto_2057_1);
  rs(&S_rs_687_1);
  noto(&S_noto_2017_1);
  noto(&S_noto_2043_1);
  noto(&S_noto_1510_1);
  rsun(&S_rsun_1602_1);
  rs(&S_rs_689_1);
  rs(&S_rs_691_1);
  rs(&S_rs_707_1);
  rs(&S_rs_724_1);
  rs(&S_rs_696_1);
  rs(&S_rs_711_1);
  rs(&S_rs_26_1);
  noto(&S_noto_2116_1);
  noto(&S_noto_2084_1);
  noto(&S_noto_1709_1);
  orni(&S_orni_314_1);
  noto(&S_noto_658_1);
  noto(&S_noto_22_1);
  noto(&S_noto_23_1);
  noto(&S_noto_24_1);
  noto(&S_noto_25_1);
  noto(&S_noto_661_1);
  noto(&S_noto_659_1);
  noto(&S_noto_50_1);
  noto(&S_noto_288_1);
  noto(&S_noto_291_1);
  noto(&S_noto_300_1);
  noto(&S_noto_306_1);
  noto(&S_noto_296_1);
  noto(&S_noto_1114_1);
  noto(&S_noto_1120_1);
  orni(&S_orni_360_1);
  noto(&S_noto_2150_1);
  noto(&S_noto_2152_1);
  ovbs(&S_ovbs_1341_1);
  ovbs(&S_ovbs_2320_1);
  sr(&S_sr_1191_1);
  bol(&S_bol_1185_1);
  ma(&S_ma_90_1);
  sr(&S_sr_88_1);
  bol(&S_bol_285_1);
  bol(&S_bol_281_1);
  bol(&S_bol_1582_1);
  bol(&S_bol_1580_1);
  bol(&S_bol_1111_1);
  bol(&S_bol_1104_1);
  bol(&S_bol_644_1);
  bol(&S_bol_648_1);
  bol(&S_bol_657_1);
  bol(&S_bol_663_1);
  and2(&S_and2_828_1);
  and2(&S_and2_27_1);
  and2(&S_and2_28_1);
  and2(&S_and2_29_1);
  and2(&S_and2_30_1);
  and2(&S_and2_42_1);
  and2(&S_and2_38_1);
  and2(&S_and2_819_1);
  or4(&S_or4_462_1);
  or2(&S_or2_832_1);
  or3(&S_or3_5_1);
  or2(&S_or2_6_1);
  or2(&S_or2_1453_1);
  or2(&S_or2_975_1);
  or2(&S_or2_254_1);
  or2(&S_or2_620_1);
  or2(&S_or2_1085_1);
  or2(&S_or2_1558_1);
  or2(&S_or2_1190_1);
  and2(&S_and2_1184_1);
  or2(&S_or2_20_1);
  or2(&S_or2_39_1);
  or2(&S_or2_35_1);
  or2(&S_or2_49_1);
  or2(&S_or2_769_1);
  or3(&S_or3_756_1);
  or4(&S_or4_773_1);
  or2(&S_or2_790_1);
  or3(&S_or3_816_1);
  and2(&S_and2_839_1);
  and2(&S_and2_813_1);
  or2(&S_or2_823_1);
  or2(&S_or2_736_1);
  or2(&S_or2_738_1);
  or2(&S_or2_740_1);
  or2(&S_or2_1314_1);
  or2(&S_or2_1342_1);
  or2(&S_or2_1195_1);
  and2(&S_and2_1210_1);
  or2(&S_or2_1250_1);
  and3(&S_and3_289_1);
  and3(&S_and3_305_1);
  or2(&S_or2_680_1);
  or2(&S_or2_688_1);
  or2(&S_or2_690_1);
  or2(&S_or2_693_1);
  or2(&S_or2_664_1);
  and2(&S_and2_714_1);
  or2(&S_or2_721_1);
  and2(&S_and2_685_1);
  or2(&S_or2_700_1);
  or2(&S_or2_695_1);
  or2(&S_or2_718_1);
  and2(&S_and2_675_1);
  or2(&S_or2_372_1);
  or2(&S_or2_377_1);
  or2(&S_or2_837_1);
  or2(&S_or2_514_1);
  and2(&S_and2_589_1);
  and2(&S_and2_590_1);
  and2(&S_and2_602_1);
  or2(&S_or2_592_1);
  and2(&S_and2_184_1);
  and2(&S_and2_223_1);
  and2(&S_and2_219_1);
  or2(&S_or2_225_1);
  and2(&S_and2_236_1);
  or2(&S_or2_878_1);
  or2(&S_or2_946_1);
  and2(&S_and2_1031_1);
  or2(&S_or2_1042_1);
  or2(&S_or2_1058_1);
  or2(&S_or2_1532_1);
  and2(&S_and2_1503_1);
  or2(&S_or2_1513_1);
  or2(&S_or2_1425_1);
  and2(&S_and2_1119_1);
  or3(&S_or3_1631_1);
  or3(&S_or3_1671_1);
  or3(&S_or3_1687_1);
  or2(&S_or2_2321_1);
  or2(&S_or2_1840_1);
  or2(&S_or2_1841_1);
  or2(&S_or2_1781_1);
  or2(&S_or2_1983_1);
  or2(&S_or2_1984_1);
  or4(&S_or4_1990_1);
  or4(&S_or4_1991_1);
  or2(&S_or2_1993_1);
  or2(&S_or2_1987_1);
  or2(&S_or2_1986_1);
  or3(&S_or3_1995_1);
  and2(&S_and2_2024_1);
  or2(&S_or2_2025_1);
  and2(&S_and2_2031_1);
  and2(&S_and2_2047_1);
  or2(&S_or2_2058_1);
  zpfs(&S_zpfs_2027_1);
  zpfs(&S_zpfs_2028_1);
  zpfs(&S_zpfs_2029_1);
  zpfs(&S_zpfs_2030_1);
  or2(&S_or2_2033_1);
  and2(&S_and2_2034_1);
  or2(&S_or2_2049_1);
  or3(&S_or3_2035_1);
  or3(&S_or3_2099_1);
  ma(&S_ma_1669_1);
  or3(&S_or3_2071_1);
  or2(&S_or2_257_1);
  ovbs(&S_ovbs_82_1);
  ovbs(&S_ovbs_21_1);
  ovbs(&S_ovbs_127_1);
  ovbs(&S_ovbs_120_1);
  ovbs(&S_ovbs_1627_1);
  ovbs(&S_ovbs_835_1);
  ovbs(&S_ovbs_322_1);
  ovbs(&S_ovbs_368_1);
  ovbs(&S_ovbs_52_1);
  or2(&S_or2_2215_1);
  or2(&S_or2_2203_1);
  noto(&S_noto_2234_1);
  bol(&S_bol_1762_1);
  bol(&S_bol_1756_1);
  or2(&S_or2_1759_1);
  bol(&S_bol_1745_1);
  bol(&S_bol_1734_1);
  or2(&S_or2_1743_1);
  bol(&S_bol_1764_1);
  bol(&S_bol_1757_1);
  or2(&S_or2_1761_1);
  bol(&S_bol_1749_1);
  bol(&S_bol_1744_1);
  or2(&S_or2_1748_1);
  and4(&S_and4_45_1);
  abs_subf(&S_abs_subf_1754_1);
  noto(&S_noto_1760_1);
  and2(&S_and2_256_1);
  and2(&S_and2_621_1);
  and2(&S_and2_2476_1);
  rs(&S_rs_2426_1);
  sr(&S_sr_2441_1);
  rs(&S_rs_2420_1);
  zpfs(&S_zpfs_2448_1);
  or2(&S_or2_2435_1);
  abs_subf(&S_abs_subf_2401_1);
  and2(&S_and2_2409_1);
  noto(&S_noto_1009_1);
  or2(&S_or2_2458_1);
  zzfs(&S_zzfs_2410_1);
  noto(&S_noto_2421_1);
  or2(&S_or2_393_1);
  or2(&S_or2_380_1);
  or2(&S_or2_1270_1);
  or2(&S_or2_1276_1);
  or2(&S_or2_252_1);
  or2(&S_or2_618_1);
  nocnm(&S_nocnm_1934_1);
  nocnm(&S_nocnm_1937_1);
  noto(&S_noto_1892_1);
  noto(&S_noto_1893_1);
  noto(&S_noto_2394_1);
  noto(&S_noto_2363_1);
  noto(&S_noto_2396_1);
  noto(&S_noto_2365_1);
  noto(&S_noto_114_1);
  and2(&S_and2_815_1);
  and2(&S_and2_817_1);
  or2(&S_or2_135_1);
  noto(&S_noto_1946_1);
  noto(&S_noto_1953_1);
  or2(&S_or2_1916_1);
  or2(&S_or2_1956_1);
  or2(&S_or2_1959_1);
  or2(&S_or2_1927_1);
  or2(&S_or2_1930_1);
  or2(&S_or2_1889_1);
  or2(&S_or2_1863_1);
  or2(&S_or2_1859_1);
  or2(&S_or2_2389_1);
  or2(&S_or2_2393_1);
  or2(&S_or2_2391_1);
  or2(&S_or2_2358_1);
  or2(&S_or2_2360_1);
  or2(&S_or2_2362_1);
  or2(&S_or2_1881_1);
  or2(&S_or2_1914_1);
  or2(&S_or2_2529_1);
  or2(&S_or2_2535_1);
  ovbsb(&S_ovbsb_228_1);
  ovbsb(&S_ovbsb_230_1);
  ovbsb(&S_ovbsb_241_1);
  ovbsb(&S_ovbsb_255_1);
  ovbsb(&S_ovbsb_597_1);
  ovbsb(&S_ovbsb_594_1);
  ovbsb(&S_ovbsb_607_1);
  ovbsb(&S_ovbsb_628_1);
  ovbsb(&S_ovbsb_2470_1);
  ovbsb(&S_ovbsb_395_1);
  and2(&S_and2_1605_1);
  and2(&S_and2_1625_1);
  and2(&S_and2_1609_1);
  and2(&S_and2_1618_1);
  and2(&S_and2_1613_1);
  noto(&S_noto_58_1);
  or2(&S_or2_1229_1);
  ovbsb(&S_ovbsb_220_1);
  zpfs(&S_zpfs_221_1);
  zzfs(&S_zzfs_2552_1);
  zzfs(&S_zzfs_2558_1);
  noto(&S_noto_754_1);
  noto(&S_noto_160_1);
  rs(&S_rs_820_1);
  noto(&S_noto_463_1);
  noto(&S_noto_734_1);
  noto(&S_noto_798_1);
  rs(&S_rs_831_1);
  noto(&S_noto_849_1);
  vmemb(&S_vmemb_741_1);
  vmemb(&S_vmemb_799_1);
  noto(&S_noto_838_1);
  vmemb(&S_vmemb_830_1);
  rs(&S_rs_702_1);
  rs(&S_rs_712_1);
  rs(&S_rs_692_1);
  noto(&S_noto_679_1);
  rs(&S_rs_720_1);
  noto(&S_noto_287_1);
  noto(&S_noto_715_1);
  noto(&S_noto_650_1);
  noto(&S_noto_1110_1);
  noto(&S_noto_1584_1);
  noto(&S_noto_1133_1);
  rs(&S_rs_1679_1);
  noto(&S_noto_83_1);
  samhd(&S_samhd_2319_1);
  samhd(&S_samhd_2325_1);
  newstage(&S_newstage_2323_1);
  noto(&S_noto_1996_1);
  noto(&S_noto_2002_1);
  noto(&S_noto_2004_1);
  noto(&S_noto_1975_1);
  noto(&S_noto_2113_1);
  noto(&S_noto_2105_1);
  noto(&S_noto_563_1);
  noto(&S_noto_1382_1);
  noto(&S_noto_1400_1);
  noto(&S_noto_2045_1);
  rs(&S_rs_1684_1);
  rs(&S_rs_1636_1);
  rs(&S_rs_2100_1);
  rs(&S_rs_2073_1);
  noto(&S_noto_1632_1);
  noto(&S_noto_1672_1);
  noto(&S_noto_1680_1);
  noto(&S_noto_2069_1);
  noto(&S_noto_2096_1);
  cntch(&S_cntch_317_1);
  rs(&S_rs_836_1);
  noto(&S_noto_374_1);
  noto(&S_noto_370_1);
  noto(&S_noto_660_1);
  noto(&S_noto_670_1);
  noto(&S_noto_723_1);
  cntch(&S_cntch_364_1);
  noto(&S_noto_2134_1);
  noto(&S_noto_2159_1);
  swtakt(&S_swtakt_2072_1);
  swtakt(&S_swtakt_1688_1);
  swtakt(&S_swtakt_1685_1);
  swtakt(&S_swtakt_1637_1);
  rs(&S_rs_1200_1);
  and2(&S_and2_846_1);
  and2(&S_and2_11_1);
  and2(&S_and2_119_1);
  and2(&S_and2_251_1);
  and2(&S_and2_617_1);
  or2(&S_or2_14_1);
  or2(&S_or2_8_1);
  or2(&S_or2_174_1);
  and3(&S_and3_788_1);
  and2(&S_and2_752_1);
  or3(&S_or3_826_1);
  and2(&S_and2_821_1);
  and2(&S_and2_730_1);
  or2(&S_or2_295_1);
  and3(&S_and3_311_1);
  or2(&S_or2_713_1);
  and2(&S_and2_682_1);
  and2(&S_and2_672_1);
  and4(&S_and4_673_1);
  and4(&S_and4_683_1);
  and2(&S_and2_708_1);
  or2(&S_or2_716_1);
  or2(&S_or2_719_1);
  and3(&S_and3_365_1);
  and2(&S_and2_559_1);
  or2(&S_or2_565_1);
  and2(&S_and2_630_1);
  and2(&S_and2_645_1);
  or2(&S_or2_190_1);
  and2(&S_and2_267_1);
  and2(&S_and2_282_1);
  and2(&S_and2_1105_1);
  and2(&S_and2_1581_1);
  and2(&S_and2_1379_1);
  or2(&S_or2_1385_1);
  and2(&S_and2_1395_1);
  or2(&S_or2_1404_1);
  and2(&S_and2_1128_1);
  and2(&S_and2_1138_1);
  and2(&S_and2_1633_1);
  or2(&S_or2_1690_1);
  zpfs(&S_zpfs_1643_1);
  and2(&S_and2_1676_1);
  zpfs(&S_zpfs_1696_1);
  and2(&S_and2_1681_1);
  zpfs(&S_zpfs_1702_1);
  or3(&S_or3_2318_1);
  or3(&S_or3_2327_1);
  or2(&S_or2_1992_1);
  or3(&S_or3_1994_1);
  or2(&S_or2_2032_1);
  and2(&S_and2_2040_1);
  or3(&S_or3_2037_1);
  and2(&S_and2_2062_1);
  or2(&S_or2_2187_1);
  or2(&S_or2_2176_1);
  and2(&S_and2_2155_1);
  and2(&S_and2_2153_1);
  and2(&S_and2_2138_1);
  zpfs(&S_zpfs_2077_1);
  and2(&S_and2_2078_1);
  or2(&S_or2_2074_1);
  or2(&S_or2_279_1);
  ovbs(&S_ovbs_13_1);
  noto(&S_noto_110_1);
  bol(&S_bol_1741_1);
  bol(&S_bol_1737_1);
  or2(&S_or2_1739_1);
  ml(&S_ml_1751_1);
  ml(&S_ml_1731_1);
  ml(&S_ml_1753_1);
  ml(&S_ml_1732_1);
  and2(&S_and2_125_1);
  noto(&S_noto_123_1);
  and2(&S_and2_129_1);
  and2(&S_and2_128_1);
  noto(&S_noto_195_1);
  noto(&S_noto_518_1);
  noto(&S_noto_1025_1);
  noto(&S_noto_1337_1);
  noto(&S_noto_1391_1);
  bol(&S_bol_2010_1);
  and3(&S_and3_2001_1);
  bol(&S_bol_1974_1);
  and3(&S_and3_1982_1);
  noto(&S_noto_1989_1);
  noto(&S_noto_2000_1);
  bol(&S_bol_1018_1);
  bol(&S_bol_1493_1);
  abs_subf(&S_abs_subf_1735_1);
  noto(&S_noto_1746_1);
  abs_subf(&S_abs_subf_1755_1);
  noto(&S_noto_1765_1);
  noto(&S_noto_2434_1);
  fsumo(&S_fsumo_86_1);
  abs_subf(&S_abs_subf_2475_1);
  and2(&S_and2_2479_1);
  ml(&S_ml_996_1);
  ml(&S_ml_1477_1);
  and3(&S_and3_2427_1);
  and2(&S_and2_2449_1);
  ovbs(&S_ovbs_2450_1);
  inf(&S_inf_2430_1);
  noto(&S_noto_2457_1);
  noto(&S_noto_1494_1);
  or2(&S_or2_1640_1);
  or2(&S_or2_1675_1);
  and2(&S_and2_112_1);
  and3(&S_and3_1595_1);
  noto(&S_noto_2395_1);
  noto(&S_noto_2364_1);
  diagndev(&S_diagndev_2523_1);
  or3(&S_or3_2531_1);
  ovbsb(&S_ovbsb_273_1);
  ovbsb(&S_ovbsb_258_1);
  ovbsb(&S_ovbsb_2315_1);
  ovbsb(&S_ovbsb_2314_1);
  ovbsb(&S_ovbsb_2313_1);
  ovbsb(&S_ovbsb_638_1);
  ovbsb(&S_ovbsb_622_1);
  ovbsb(&S_ovbsb_2328_1);
  ovbsb(&S_ovbsb_2329_1);
  ovbsb(&S_ovbsb_2330_1);
  ovbsb(&S_ovbsb_2471_1);
  ovbsb(&S_ovbsb_742_1);
  ovbsb(&S_ovbsb_785_1);
  ovbsb(&S_ovbsb_2065_1);
  period(&S_period_79_1);
  or2(&S_or2_2088_1);
  zpfs(&S_zpfs_1677_1);
  swtakt(&S_swtakt_2101_1);
  noto(&S_noto_1221_1);
  rs(&S_rs_827_1);
  noto(&S_noto_842_1);
  noto(&S_noto_1423_1);
  noto(&S_noto_947_1);
  noto(&S_noto_226_1);
  rs(&S_rs_694_1);
  noto(&S_noto_593_1);
  noto(&S_noto_1059_1);
  noto(&S_noto_1530_1);
  noto(&S_noto_2125_1);
  kvf(&S_kvf_2082_1);
  andn(&S_andn_1988_1);
  rs(&S_rs_19_1);
  noto(&S_noto_148_1);
  noto(&S_noto_2046_1);
  noto(&S_noto_118_1);
  noto(&S_noto_1586_1);
  abs_subf(&S_abs_subf_1139_1);
  abs_subf(&S_abs_subf_1126_1);
  noto(&S_noto_1147_1);
  bol(&S_bol_1160_1);
  bol(&S_bol_1161_1);
  noto(&S_noto_1123_1);
  bol(&S_bol_1164_1);
  bol(&S_bol_1165_1);
  bol(&S_bol_87_1);
  and2(&S_and2_31_1);
  and2(&S_and2_153_1);
  and2(&S_and2_161_1);
  and2(&S_and2_158_1);
  and2(&S_and2_150_1);
  and3(&S_and3_253_1);
  and3(&S_and3_619_1);
  and3(&S_and3_1117_1);
  or3(&S_or3_115_1);
  or2(&S_or2_743_1);
  and2(&S_and2_753_1);
  and2(&S_and2_755_1);
  and2(&S_and2_771_1);
  and2(&S_and2_772_1);
  and2(&S_and2_789_1);
  and2(&S_and2_792_1);
  and3(&S_and3_791_1);
  and2(&S_and2_793_1);
  or2(&S_or2_833_1);
  and2(&S_and2_841_1);
  or2(&S_or2_847_1);
  or2(&S_or2_851_1);
  and3(&S_and3_848_1);
  and2(&S_and2_853_1);
  and2(&S_and2_857_1);
  and2(&S_and2_726_1);
  or2(&S_or2_727_1);
  and2(&S_and2_737_1);
  and2(&S_and2_739_1);
  and2(&S_and2_706_1);
  and2(&S_and2_684_1);
  and2(&S_and2_674_1);
  and3(&S_and3_591_1);
  or2(&S_or2_641_1);
  and3(&S_and3_224_1);
  and3(&S_and3_269_1);
  and3(&S_and3_956_1);
  and3(&S_and3_957_1);
  or2(&S_or2_1101_1);
  or2(&S_or2_1574_1);
  and3(&S_and3_1432_1);
  and3(&S_and3_1433_1);
  or2(&S_or2_1166_1);
  or2(&S_or2_1176_1);
  or2(&S_or2_1172_1);
  or2(&S_or2_1171_1);
  or2(&S_or2_1170_1);
  and2(&S_and2_1598_1);
  and2(&S_and2_1644_1);
  and2(&S_and2_1697_1);
  or3(&S_or3_1712_1);
  and2(&S_and2_1703_1);
  or3(&S_or3_1718_1);
  and2(&S_and2_1719_1);
  and3(&S_and3_2147_1);
  and2(&S_and2_2142_1);
  or3(&S_or3_2148_1);
  zpfs(&S_zpfs_2109_1);
  or2(&S_or2_2102_1);
  and2(&S_and2_2110_1);
  lk(&S_lk_2089_1);
  rsfn(&S_rsfn_2091_1);
  abs_subf(&S_abs_subf_2092_1);
  and2(&S_and2_2085_1);
  and3(&S_and3_2086_1);
  or5(&S_or5_155_1);
  and2(&S_and2_2063_1);
  and2(&S_and2_113_1);
  and2(&S_and2_109_1);
  ml(&S_ml_1729_1);
  zpfs(&S_zpfs_834_1);
  and2(&S_and2_1965_1);
  and2(&S_and2_1942_1);
  and2(&S_and2_1963_1);
  and2(&S_and2_1966_1);
  and2(&S_and2_1943_1);
  and2(&S_and2_1964_1);
  and2(&S_and2_1944_1);
  and2(&S_and2_1945_1);
  and2(&S_and2_1948_1);
  and2(&S_and2_1949_1);
  and2(&S_and2_1951_1);
  and2(&S_and2_1952_1);
  and2(&S_and2_1918_1);
  and2(&S_and2_1919_1);
  rs(&S_rs_1920_1);
  and2(&S_and2_1921_1);
  and2(&S_and2_1922_1);
  rs(&S_rs_1923_1);
  and2(&S_and2_1901_1);
  and2(&S_and2_1905_1);
  and2(&S_and2_1868_1);
  and2(&S_and2_1870_1);
  and2(&S_and2_1872_1);
  and2(&S_and2_1874_1);
  and2(&S_and2_1842_1);
  and2(&S_and2_1843_1);
  and2(&S_and2_1844_1);
  and2(&S_and2_1845_1);
  and2(&S_and2_1846_1);
  and2(&S_and2_1847_1);
  and2(&S_and2_1848_1);
  and2(&S_and2_1849_1);
  and2(&S_and2_124_1);
  abs_subf(&S_abs_subf_1733_1);
  noto(&S_noto_1740_1);
  bol(&S_bol_2465_1);
  and2(&S_and2_2473_1);
  ovbs(&S_ovbs_2428_1);
  and2(&S_and2_2478_1);
  or3(&S_or3_2462_1);
  noto(&S_noto_2405_1);
  noto(&S_noto_2406_1);
  and2(&S_and2_2374_1);
  or4(&S_or4_1002_1);
  and2(&S_and2_2343_1);
  or4(&S_or4_1480_1);
  and4(&S_and4_1068_1);
  and4(&S_and4_1541_1);
  or3(&S_or3_1955_1);
  or3(&S_or3_1926_1);
  or3(&S_or3_1929_1);
  or3(&S_or3_1958_1);
  or3(&S_or3_1910_1);
  or3(&S_or3_1912_1);
  or3(&S_or3_1861_1);
  or3(&S_or3_1857_1);
  or3(&S_or3_2381_1);
  or3(&S_or3_2350_1);
  or3(&S_or3_2383_1);
  or3(&S_or3_2385_1);
  or3(&S_or3_2354_1);
  or3(&S_or3_2352_1);
  or2(&S_or2_1887_1);
  or2(&S_or2_1854_1);
  or2(&S_or2_2387_1);
  and2(&S_and2_2371_1);
  or2(&S_or2_2356_1);
  and2(&S_and2_2341_1);
  or2(&S_or2_1879_1);
  or2(&S_or2_1851_1);
  or2(&S_or2_1908_1);
  and2(&S_and2_1904_1);
  ovbsb(&S_ovbsb_232_1);
  ovbsb(&S_ovbsb_261_1);
  ovbsb(&S_ovbsb_270_1);
  ovbsb(&S_ovbsb_595_1);
  ovbsb(&S_ovbsb_626_1);
  ovbsb(&S_ovbsb_108_1);
  ovbsb(&S_ovbsb_2467_1);
  ovbsb(&S_ovbsb_2472_1);
  ovbsb(&S_ovbsb_775_1);
  ovbsb(&S_ovbsb_770_1);
  ovbsb(&S_ovbsb_761_1);
  ovbsb(&S_ovbsb_794_1);
  ovbsb(&S_ovbsb_777_1);
  ovbsb(&S_ovbsb_746_1);
  ovbsb(&S_ovbsb_750_1);
  ovbsb(&S_ovbsb_796_1);
  ovbsb(&S_ovbsb_797_1);
  ovbsb(&S_ovbsb_795_1);
  ovbsb(&S_ovbsb_2066_1);
  samhd(&S_samhd_421_1);
  samhd(&S_samhd_427_1);
  samhd(&S_samhd_875_1);
  samhd(&S_samhd_879_1);
  rs(&S_rs_843_1);
  rs(&S_rs_850_1);
  newstage(&S_newstage_424_1);
  newstage(&S_newstage_877_1);
  orn(&S_orn_154_1);
  kvf(&S_kvf_1705_1);
  rs(&S_rs_1850_1);
  rs(&S_rs_1852_1);
  rs(&S_rs_1853_1);
  rs(&S_rs_1855_1);
  rs(&S_rs_1856_1);
  rs(&S_rs_1858_1);
  rs(&S_rs_1860_1);
  rs(&S_rs_1862_1);
  rs(&S_rs_1880_1);
  rs(&S_rs_1888_1);
  rs(&S_rs_1907_1);
  rs(&S_rs_1915_1);
  rs(&S_rs_1925_1);
  rs(&S_rs_2388_1);
  rs(&S_rs_1954_1);
  rs(&S_rs_1947_1);
  rs(&S_rs_1957_1);
  rs(&S_rs_1950_1);
  rs(&S_rs_1960_1);
  rs(&S_rs_1898_1);
  rs(&S_rs_1899_1);
  rs(&S_rs_1900_1);
  rs(&S_rs_1864_1);
  rs(&S_rs_1865_1);
  rs(&S_rs_1866_1);
  rs(&S_rs_1867_1);
  rs(&S_rs_116_1);
  noto(&S_noto_117_1);
  rs(&S_rs_1706_1);
  rs(&S_rs_2087_1);
  noto(&S_noto_1711_1);
  andn(&S_andn_294_1);
  noto(&S_noto_312_1);
  and2(&S_and2_452_1);
  and2(&S_and2_464_1);
  and2(&S_and2_473_1);
  and2(&S_and2_475_1);
  and2(&S_and2_477_1);
  or3(&S_or3_417_1);
  or3(&S_or3_433_1);
  and2(&S_and2_453_1);
  and3(&S_and3_662_1);
  or2(&S_or2_157_1);
  and2(&S_and2_758_1);
  and2(&S_and2_829_1);
  or2(&S_or2_856_1);
  and2(&S_and2_733_1);
  or2(&S_or2_302_1);
  and3(&S_and3_303_1);
  or2(&S_or2_488_1);
  and3(&S_and3_497_1);
  or2(&S_or2_549_1);
  and2(&S_and2_567_1);
  and3(&S_and3_632_1);
  and3(&S_and3_631_1);
  and2(&S_and2_191_1);
  and3(&S_and3_268_1);
  or4(&S_or4_871_1);
  or4(&S_or4_886_1);
  or3(&S_or3_945_1);
  and2(&S_and2_943_1);
  and3(&S_and3_944_1);
  and2(&S_and2_942_1);
  and2(&S_and2_958_1);
  and2(&S_and2_980_1);
  and3(&S_and3_981_1);
  and2(&S_and2_1047_1);
  or2(&S_or2_1057_1);
  and2(&S_and2_1069_1);
  and2(&S_and2_1091_1);
  and3(&S_and3_1092_1);
  and3(&S_and3_1093_1);
  or2(&S_or2_1531_1);
  and2(&S_and2_1542_1);
  and2(&S_and2_1564_1);
  and3(&S_and3_1565_1);
  and3(&S_and3_1566_1);
  and2(&S_and2_1517_1);
  or3(&S_or3_1424_1);
  and3(&S_and3_1422_1);
  and2(&S_and2_1421_1);
  and2(&S_and2_1420_1);
  and2(&S_and2_1436_1);
  and2(&S_and2_1451_1);
  and3(&S_and3_1452_1);
  and2(&S_and2_1458_1);
  and3(&S_and3_1459_1);
  and2(&S_and2_1387_1);
  and2(&S_and2_1409_1);
  and2(&S_and2_1177_1);
  and2(&S_and2_1181_1);
  or3(&S_or3_1654_1);
  and2(&S_and2_1655_1);
  or3(&S_or3_1698_1);
  and2(&S_and2_1713_1);
  or2(&S_or2_1694_1);
  or3(&S_or3_1704_1);
  or2(&S_or2_1961_1);
  lk(&S_lk_1695_1);
  rsfn(&S_rsfn_1689_1);
  abs_subf(&S_abs_subf_1707_1);
  ovbs(&S_ovbs_2284_1);
  ovbs(&S_ovbs_122_1);
  and2(&S_and2_527_1);
  and2(&S_and2_489_1);
  and2(&S_and2_486_1);
  rs(&S_rs_1962_1);
  rs(&S_rs_1928_1);
  and2(&S_and2_1902_1);
  and2(&S_and2_1903_1);
  and2(&S_and2_1906_1);
  and2(&S_and2_1871_1);
  and2(&S_and2_1875_1);
  noto(&S_noto_2461_1);
  zpfs(&S_zpfs_2413_1);
  zpfs(&S_zpfs_2414_1);
  and3(&S_and3_454_1);
  rs(&S_rs_2380_1);
  rs(&S_rs_2368_1);
  rs(&S_rs_2372_1);
  and2(&S_and2_2378_1);
  rs(&S_rs_2390_1);
  rs(&S_rs_2373_1);
  and2(&S_and2_2379_1);
  rs(&S_rs_2392_1);
  rs(&S_rs_2357_1);
  rs(&S_rs_2349_1);
  rs(&S_rs_2337_1);
  rs(&S_rs_2340_1);
  and2(&S_and2_2347_1);
  rs(&S_rs_2359_1);
  rs(&S_rs_2342_1);
  and2(&S_and2_2348_1);
  rs(&S_rs_2361_1);
  regch(&S_regch_133_1);
  rs(&S_rs_1913_1);
  ovbsb(&S_ovbsb_274_1);
  ovbsb(&S_ovbsb_1435_1);
  ovbsb(&S_ovbsb_1426_1);
  ovbsb(&S_ovbsb_1428_1);
  ovbsb(&S_ovbsb_1462_1);
  ovbsb(&S_ovbsb_1441_1);
  ovbsb(&S_ovbsb_1463_1);
  ovbsb(&S_ovbsb_1456_1);
  ovbsb(&S_ovbsb_1455_1);
  ovbsb(&S_ovbsb_1096_1);
  ovbsb(&S_ovbsb_1074_1);
  ovbsb(&S_ovbsb_1097_1);
  ovbsb(&S_ovbsb_1098_1);
  ovbsb(&S_ovbsb_864_1);
  ovbsb(&S_ovbsb_865_1);
  ovbsb(&S_ovbsb_866_1);
  ovbsb(&S_ovbsb_870_1);
  ovbsb(&S_ovbsb_410_1);
  ovbsb(&S_ovbsb_411_1);
  ovbsb(&S_ovbsb_412_1);
  ovbsb(&S_ovbsb_415_1);
  ovbsb(&S_ovbsb_465_1);
  ovbsb(&S_ovbsb_449_1);
  ovbsb(&S_ovbsb_448_1);
  ovbsb(&S_ovbsb_457_1);
  ovbsb(&S_ovbsb_635_1);
  ovbsb(&S_ovbsb_637_1);
  ovbsb(&S_ovbsb_952_1);
  ovbsb(&S_ovbsb_950_1);
  ovbsb(&S_ovbsb_949_1);
  ovbsb(&S_ovbsb_984_1);
  ovbsb(&S_ovbsb_963_1);
  ovbsb(&S_ovbsb_985_1);
  ovbsb(&S_ovbsb_1569_1);
  ovbsb(&S_ovbsb_1547_1);
  ovbsb(&S_ovbsb_1570_1);
  ovbsb(&S_ovbsb_1571_1);
  ovbsb(&S_ovbsb_887_1);
  ovbsb(&S_ovbsb_891_1);
  ovbsb(&S_ovbsb_892_1);
  ovbsb(&S_ovbsb_893_1);
  ovbsb(&S_ovbsb_431_1);
  ovbsb(&S_ovbsb_438_1);
  ovbsb(&S_ovbsb_437_1);
  ovbsb(&S_ovbsb_439_1);
  ovbsb(&S_ovbsb_485_1);
  ovbsb(&S_ovbsb_476_1);
  ovbsb(&S_ovbsb_474_1);
  ovbsb(&S_ovbsb_480_1);
  ovbsb(&S_ovbsb_767_1);
  ovbsb(&S_ovbsb_735_1);
  rs(&S_rs_822_1);
  rs(&S_rs_855_1);
  rs(&S_rs_667_1);
  noto(&S_noto_681_1);
  noto(&S_noto_2285_1);
  rs(&S_rs_1882_1);
  rs(&S_rs_1890_1);
  rs(&S_rs_1909_1);
  rs(&S_rs_1911_1);
  rs(&S_rs_1917_1);
  rs(&S_rs_677_1);
  kvf(&S_kvf_1700_1);
  rs(&S_rs_1699_1);
  rs(&S_rs_1646_1);
  kvf(&S_kvf_1651_1);
  noto(&S_noto_1650_1);
  noto(&S_noto_1113_1);
  noto(&S_noto_304_1);
  noto(&S_noto_1173_1);
  noto(&S_noto_1174_1);
  noto(&S_noto_1143_1);
  and2(&S_and2_456_1);
  and2(&S_and2_479_1);
  and2(&S_and2_973_1);
  and3(&S_and3_974_1);
  and3(&S_and3_1084_1);
  and3(&S_and3_1557_1);
  and2(&S_and2_701_1);
  and2(&S_and2_1054_1);
  and2(&S_and2_1055_1);
  and3(&S_and3_1056_1);
  and2(&S_and2_1527_1);
  and2(&S_and2_1528_1);
  and3(&S_and3_1529_1);
  and5(&S_and5_1118_1);
  and2(&S_and2_1167_1);
  or4(&S_or4_1125_1);
  or2(&S_or2_1641_1);
  or3(&S_or3_1645_1);
  and3(&S_and3_1716_1);
  or2(&S_or2_2050_1);
  and2(&S_and2_2051_1);
  and2(&S_and2_2302_1);
  lk(&S_lk_1693_1);
  rsfn(&S_rsfn_1686_1);
  abs_subf(&S_abs_subf_1701_1);
  lk(&S_lk_1652_1);
  rsfn(&S_rsfn_1648_1);
  abs_subf(&S_abs_subf_1657_1);
  ovbs(&S_ovbs_2286_1);
  noto(&S_noto_2418_1);
  noto(&S_noto_2419_1);
  andn(&S_andn_665_1);
  andn(&S_andn_666_1);
  and2(&S_and2_2305_1);
  and2(&S_and2_2375_1);
  or3(&S_or3_1371_1);
  rs(&S_rs_2382_1);
  rs(&S_rs_2369_1);
  and2(&S_and2_2344_1);
  rs(&S_rs_2351_1);
  rs(&S_rs_2338_1);
  or3(&S_or3_910_1);
  or2(&S_or2_136_1);
  ovbsb(&S_ovbsb_1061_1);
  ovbsb(&S_ovbsb_1062_1);
  ovbsb(&S_ovbsb_1064_1);
  ovbsb(&S_ovbsb_1089_1);
  ovbsb(&S_ovbsb_451_1);
  ovbsb(&S_ovbsb_977_1);
  ovbsb(&S_ovbsb_979_1);
  ovbsb(&S_ovbsb_1534_1);
  ovbsb(&S_ovbsb_1537_1);
  ovbsb(&S_ovbsb_1535_1);
  ovbsb(&S_ovbsb_1562_1);
  ovbsb(&S_ovbsb_478_1);
  ovbsb(&S_ovbsb_1148_1);
  rs(&S_rs_1124_1);
  orni(&S_orni_1604_1);
  noto(&S_noto_2287_1);
  rs(&S_rs_1721_1);
  noto(&S_noto_1144_1);
  and2(&S_and2_604_1);
  and2(&S_and2_238_1);
  and2(&S_and2_960_1);
  and2(&S_and2_1071_1);
  and2(&S_and2_1544_1);
  and2(&S_and2_1438_1);
  and3(&S_and3_1130_1);
  and3(&S_and3_1136_1);
  and2(&S_and2_1154_1);
  and2(&S_and2_1141_1);
  and3(&S_and3_1188_1);
  and3(&S_and3_1661_1);
  and3(&S_and3_1715_1);
  or2(&S_or2_2048_1);
  noto(&S_noto_2425_1);
  and2(&S_and2_2376_1);
  and2(&S_and2_2345_1);
  rs(&S_rs_2370_1);
  and2(&S_and2_2377_1);
  rs(&S_rs_2386_1);
  rs(&S_rs_2339_1);
  ovbsb(&S_ovbsb_245_1);
  ovbsb(&S_ovbsb_1445_1);
  ovbsb(&S_ovbsb_1078_1);
  ovbsb(&S_ovbsb_611_1);
  ovbsb(&S_ovbsb_967_1);
  ovbsb(&S_ovbsb_1549_1);
  rs(&S_rs_2384_1);
  newstage(&S_newstage_2041_1);
  rs(&S_rs_1720_1);
  rs(&S_rs_1664_1);
  rs(&S_rs_1149_1);
  rs(&S_rs_1182_1);
  rs(&S_rs_1156_1);
  noto(&S_noto_1157_1);
  or3(&S_or3_164_1);
  or3(&S_or3_539_1);
  or2(&S_or2_1178_1);
  or2(&S_or2_1797_1);
  andn(&S_andn_2433_1);
  noto(&S_noto_2455_1);
  and2(&S_and2_2456_1);
  or2(&S_or2_2454_1);
  and3(&S_and3_2412_1);
  rs(&S_rs_2353_1);
  and2(&S_and2_2346_1);
  rs(&S_rs_2355_1);
  ovbsb(&S_ovbsb_2182_1);
  cnshd(&S_cnshd_1804_1);
  noto(&S_noto_972_1);
  ornc(&S_ornc_172_1);
  charint(&S_charint_165_1);
  noto(&S_noto_249_1);
  ornc(&S_ornc_547_1);
  charint(&S_charint_541_1);
  noto(&S_noto_615_1);
  noto(&S_noto_1081_1);
  noto(&S_noto_1552_1);
  rs(&S_rs_1168_1);
  or2(&S_or2_1825_1);
  and2(&S_and2_1767_1);
  and2(&S_and2_1768_1);
  and2(&S_and2_1769_1);
  and2(&S_and2_1770_1);
  and2(&S_and2_1780_1);
  and2(&S_and2_1782_1);
  and2(&S_and2_1784_1);
  and2(&S_and2_1155_1);
  rs(&S_rs_2453_1);
  ovbsb(&S_ovbsb_1794_1);
  ovbsb(&S_ovbsb_1772_1);
  ovbsb(&S_ovbsb_1773_1);
  ovbsb(&S_ovbsb_1775_1);
  ovbsb(&S_ovbsb_1777_1);
  ovbsb(&S_ovbsb_1786_1);
  ovbsb(&S_ovbsb_1791_1);
  fnapb(&S_fnapb_1826_1);
  samhd(&S_samhd_1807_1);
  zpfs(&S_zpfs_1822_1);
  zpfs(&S_zpfs_1818_1);
  noto(&S_noto_1449_1);
  fsumz(&S_fsumz_166_1);
  fsumz(&S_fsumz_542_1);
  orni(&S_orni_1328_1);
  rs(&S_rs_1151_1);
  rs(&S_rs_1152_1);
  ma(&S_ma_173_1);
  ma(&S_ma_548_1);
  zpfs(&S_zpfs_1832_1);
  or2(&S_or2_1272_1);
  or3(&S_or3_1150_1);
  or3(&S_or3_1815_1);
  ovbsb(&S_ovbsb_1808_1);
  ovbsb(&S_ovbsb_1819_1);
  ovbsb(&S_ovbsb_1829_1);
  ovbsb(&S_ovbsb_1828_1);
  ovbsb(&S_ovbsb_1821_1);
  ovbsb(&S_ovbsb_1813_1);
  samhd(&S_samhd_1333_1);
  samhd(&S_samhd_1343_1);
  newstage(&S_newstage_1336_1);
  cnshd(&S_cnshd_1273_1);
  noto(&S_noto_1448_1);
  noto(&S_noto_971_1);
  cnshd(&S_cnshd_176_1);
  noto(&S_noto_248_1);
  cnshd(&S_cnshd_550_1);
  noto(&S_noto_614_1);
  noto(&S_noto_1080_1);
  noto(&S_noto_1551_1);
  or2(&S_or2_1332_1);
  or2(&S_or2_1346_1);
  or2(&S_or2_1299_1);
  and2(&S_and2_1240_1);
  and2(&S_and2_1237_1);
  and2(&S_and2_1238_1);
  and2(&S_and2_1239_1);
  and2(&S_and2_1249_1);
  and2(&S_and2_1251_1);
  and2(&S_and2_1253_1);
  and2(&S_and2_703_1);
  or2(&S_or2_572_1);
  or2(&S_or2_606_1);
  or2(&S_or2_200_1);
  or2(&S_or2_240_1);
  or2(&S_or2_962_1);
  and2(&S_and2_961_1);
  or2(&S_or2_1073_1);
  or2(&S_or2_1546_1);
  or2(&S_or2_1440_1);
  and2(&S_and2_1439_1);
  and2(&S_and2_1146_1);
  or2(&S_or2_1158_1);
  and2(&S_and2_1338_1);
  and2(&S_and2_1344_1);
  ovbsb(&S_ovbsb_1446_1);
  ovbsb(&S_ovbsb_1326_1);
  ovbsb(&S_ovbsb_1327_1);
  ovbsb(&S_ovbsb_1330_1);
  ovbsb(&S_ovbsb_969_1);
  ovbsb(&S_ovbsb_1347_1);
  ovbsb(&S_ovbsb_1348_1);
  ovbsb(&S_ovbsb_1349_1);
  ovbsb(&S_ovbsb_1263_1);
  ovbsb(&S_ovbsb_1242_1);
  ovbsb(&S_ovbsb_1244_1);
  ovbsb(&S_ovbsb_1246_1);
  ovbsb(&S_ovbsb_1248_1);
  ovbsb(&S_ovbsb_1255_1);
  ovbsb(&S_ovbsb_1259_1);
  and2(&S_and2_1233_1);
  noto(&S_noto_1232_1);
  or3(&S_or3_1225_1);
  fnapb(&S_fnapb_1300_1);
  samhd(&S_samhd_1281_1);
  zpfs(&S_zpfs_1294_1);
  zpfs(&S_zpfs_1290_1);
  orn(&S_orn_1450_1);
  orn(&S_orn_968_1);
  fnapb(&S_fnapb_201_1);
  newstage(&S_newstage_211_1);
  fnapb(&S_fnapb_573_1);
  zpfs(&S_zpfs_568_1);
  zpfs(&S_zpfs_569_1);
  rs(&S_rs_1145_1);
  zpfs(&S_zpfs_1306_1);
  zpfs(&S_zpfs_588_1);
  and2(&S_and2_605_1);
  orn(&S_orn_616_1);
  zpfs(&S_zpfs_215_1);
  zpfs(&S_zpfs_193_1);
  zpfs(&S_zpfs_194_1);
  and2(&S_and2_239_1);
  and2(&S_and2_1072_1);
  and2(&S_and2_1545_1);
  and2(&S_and2_1159_1);
  or2(&S_or2_1153_1);
  or3(&S_or3_1287_1);
  and2(&S_and2_198_1);
  and2(&S_and2_196_1);
  or4(&S_or4_2165_1);
  ovbsb(&S_ovbsb_210_1);
  ovbsb(&S_ovbsb_202_1);
  ovbsb(&S_ovbsb_203_1);
  ovbsb(&S_ovbsb_204_1);
  ovbsb(&S_ovbsb_246_1);
  ovbsb(&S_ovbsb_1079_1);
  ovbsb(&S_ovbsb_581_1);
  ovbsb(&S_ovbsb_576_1);
  ovbsb(&S_ovbsb_575_1);
  ovbsb(&S_ovbsb_574_1);
  ovbsb(&S_ovbsb_612_1);
  ovbsb(&S_ovbsb_1550_1);
  ovbsb(&S_ovbsb_1298_1);
  ovbsb(&S_ovbsb_1284_1);
  ovbsb(&S_ovbsb_1303_1);
  ovbsb(&S_ovbsb_1297_1);
  ovbsb(&S_ovbsb_1292_1);
  ovbsb(&S_ovbsb_1285_1);
  noto(&S_noto_1217_1);
  orn(&S_orn_250_1);
  and2(&S_and2_1211_1);
  and2(&S_and2_710_1);
  or2(&S_or2_698_1);
  and2(&S_and2_1179_1);
  or2(&S_or2_2183_1);
  or2(&S_or2_2171_1);
  ovbs(&S_ovbs_2166_1);
  ovbs(&S_ovbs_2179_1);
  ovbs(&S_ovbs_2169_1);
  noto(&S_noto_2170_1);
  and2(&S_and2_2177_1);
  and2(&S_and2_2188_1);
  or3(&S_or3_134_1);
  noto(&S_noto_132_1);
  rs(&S_rs_699_1);
  noto(&S_noto_2167_1);
  noto(&S_noto_2180_1);
  rs(&S_rs_2184_1);
  noto(&S_noto_2185_1);
  rs(&S_rs_2172_1);
  rs(&S_rs_1162_1);
  noto(&S_noto_1169_1);
  rs(&S_rs_1197_1);
  rs(&S_rs_1203_1);
  and2(&S_and2_717_1);
  and3(&S_and3_686_1);
  and3(&S_and3_676_1);
  or3(&S_or3_904_1);
  or3(&S_or3_1367_1);
  and4(&S_and4_1131_1);
  and4(&S_and4_1137_1);
  or2(&S_or2_2139_1);
  irm(&S_irm_2408_1);
  or4(&S_or4_993_1);
  or4(&S_or4_1471_1);
  and2(&S_and2_53_1);
  or3(&S_or3_1202_1);
  ornc(&S_ornc_1003_1);
  charint(&S_charint_994_1);
  ornc(&S_ornc_1481_1);
  charint(&S_charint_1475_1);
  noto(&S_noto_2173_1);
  noto(&S_noto_69_1);
  swtakt(&S_swtakt_54_1);
  noto(&S_noto_2140_1);
  rs(&S_rs_1201_1);
  and2(&S_and2_61_1);
  and2(&S_and2_65_1);
  and4(&S_and4_359_1);
  and2(&S_and2_1559_1);
  or2(&S_or2_1592_1);
  or2(&S_or2_2262_1);
  or2(&S_or2_2156_1);
  and2(&S_and2_2137_1);
  and2(&S_and2_2107_1);
  and4(&S_and4_2108_1);
  and4(&S_and4_2114_1);
  or2(&S_or2_2117_1);
  or2(&S_or2_2119_1);
  or2(&S_or2_2118_1);
  zpfs(&S_zpfs_2121_1);
  zpfs(&S_zpfs_2124_1);
  and4(&S_and4_2128_1);
  and4(&S_and4_2130_1);
  or3(&S_or3_2126_1);
  and2(&S_and2_1086_1);
  and2(&S_and2_2263_1);
  ovbsb(&S_ovbsb_1087_1);
  ovbsb(&S_ovbsb_1560_1);
  or4(&S_or4_2546_1);
  or2(&S_or2_2306_1);
  or2(&S_or2_2307_1);
  fsumz(&S_fsumz_995_1);
  orn(&S_orn_1082_1);
  fsumz(&S_fsumz_1476_1);
  orn(&S_orn_1553_1);
  kvf(&S_kvf_2123_1);
  noto(&S_noto_1588_1);
  rs(&S_rs_362_1);
  noto(&S_noto_357_1);
  noto(&S_noto_299_1);
  rs(&S_rs_2157_1);
  rs(&S_rs_2158_1);
  ma(&S_ma_1482_1);
  ma(&S_ma_1004_1);
  or4(&S_or4_310_1);
  or2(&S_or2_293_1);
  or2(&S_or2_316_1);
  or2(&S_or2_354_1);
  or4(&S_or4_363_1);
  and2(&S_and2_1587_1);
  or2(&S_or2_2291_1);
  or2(&S_or2_2298_1);
  zpfs(&S_zpfs_2264_1);
  and2(&S_and2_2120_1);
  lk(&S_lk_2127_1);
  rsfn(&S_rsfn_2131_1);
  abs_subf(&S_abs_subf_2133_1);
  and3(&S_and3_2136_1);
  and2(&S_and2_2277_1);
  and2(&S_and2_2290_1);
  and2(&S_and2_2276_1);
  or5(&S_or5_2303_1);
  and2(&S_and2_2301_1);
  or2(&S_or2_2220_1);
  or2(&S_or2_2241_1);
  or3(&S_or3_2259_1);
  ovbsb(&S_ovbsb_2271_1);
  ovbsb(&S_ovbsb_2272_1);
  ovbsb(&S_ovbsb_2283_1);
  ovbsb(&S_ovbsb_2300_1);
  or3(&S_or3_2547_1);
  cnshd(&S_cnshd_1005_1);
  cnshd(&S_cnshd_1483_1);
  rs(&S_rs_309_1);
  rs(&S_rs_2292_1);
  ma(&S_ma_1653_1);
  rs(&S_rs_2141_1);
  provsbr(&S_provsbr_1600_1);
  rs(&S_rs_1599_1);
  provsbr(&S_provsbr_298_1);
  equz_p(&S_equz_p_337_1);
  bolz(&S_bolz_338_1);
  provsbr(&S_provsbr_356_1);
  bolz(&S_bolz_361_1);
  noto(&S_noto_70_1);
  noto(&S_noto_59_1);
  and2(&S_and2_62_1);
  and2(&S_and2_66_1);
  or2(&S_or2_63_1);
  and2(&S_and2_634_1);
  and2(&S_and2_633_1);
  or3(&S_or3_649_1);
  and2(&S_and2_313_1);
  and4(&S_and4_343_1);
  and2(&S_and2_325_1);
  or2(&S_or2_315_1);
  and2(&S_and2_320_1);
  or2(&S_or2_367_1);
  and2(&S_and2_358_1);
  or5(&S_or5_561_1);
  and2(&S_and2_271_1);
  and2(&S_and2_272_1);
  or3(&S_or3_286_1);
  or2(&S_or2_1034_1);
  and2(&S_and2_1095_1);
  and2(&S_and2_1094_1);
  and2(&S_and2_1567_1);
  and2(&S_and2_1568_1);
  or2(&S_or2_1508_1);
  and2(&S_and2_1607_1);
  and2(&S_and2_1611_1);
  and2(&S_and2_1615_1);
  and2(&S_and2_1623_1);
  or2(&S_or2_1608_1);
  or2(&S_or2_1612_1);
  or2(&S_or2_1616_1);
  or2(&S_or2_1624_1);
  or2(&S_or2_1589_1);
  or4(&S_or4_1583_1);
  or4(&S_or4_1109_1);
  or5(&S_or5_2304_1);
  ovbsb(&S_ovbsb_277_1);
  ovbsb(&S_ovbsb_278_1);
  ovbsb(&S_ovbsb_1099_1);
  ovbsb(&S_ovbsb_1100_1);
  ovbsb(&S_ovbsb_639_1);
  ovbsb(&S_ovbsb_640_1);
  ovbsb(&S_ovbsb_1572_1);
  ovbsb(&S_ovbsb_1573_1);
  and2(&S_and2_1629_1);
  or2(&S_or2_1606_1);
  or2(&S_or2_1610_1);
  or2(&S_or2_1614_1);
  or2(&S_or2_1619_1);
  or2(&S_or2_1626_1);
  and2(&S_and2_1235_1);
  noto(&S_noto_1234_1);
  or3(&S_or3_1227_1);
  fnapb(&S_fnapb_1035_1);
  zpfs(&S_zpfs_1027_1);
  zpfs(&S_zpfs_1028_1);
  newstage(&S_newstage_1017_1);
  fnapb(&S_fnapb_1509_1);
  zpfs(&S_zpfs_1501_1);
  zpfs(&S_zpfs_1500_1);
  maz(&S_maz_324_1);
  maz(&S_maz_333_1);
  rs(&S_rs_2294_1);
  orni(&S_orni_1340_1);
  rs(&S_rs_366_1);
  decatron(&S_decatron_321_1);
  noto(&S_noto_336_1);
  zpfs(&S_zpfs_1052_1);
  zpfs(&S_zpfs_1525_1);
  or2(&S_or2_319_1);
  or2(&S_or2_328_1);
  or2(&S_or2_342_1);
  or2(&S_or2_341_1);
  and2(&S_and2_345_1);
  and2(&S_and2_340_1);
  and2(&S_and2_347_1);
  and2(&S_and2_346_1);
  and3(&S_and3_326_1);
  or5(&S_or5_188_1);
  or2(&S_or2_1630_1);
  orni(&S_orni_1620_1);
  and2(&S_and2_1590_1);
  or2(&S_or2_2280_1);
  or2(&S_or2_2268_1);
  or2(&S_or2_2252_1);
  or3(&S_or3_1585_1);
  or3(&S_or3_1112_1);
  zpfs(&S_zpfs_339_1);
  and2(&S_and2_1023_1);
  and2(&S_and2_1026_1);
  and2(&S_and2_1497_1);
  and2(&S_and2_1021_1);
  and2(&S_and2_2267_1);
  and2(&S_and2_2261_1);
  and2(&S_and2_2281_1);
  ovbsb(&S_ovbsb_1046_1);
  ovbsb(&S_ovbsb_1029_1);
  ovbsb(&S_ovbsb_1039_1);
  ovbsb(&S_ovbsb_1040_1);
  ovbsb(&S_ovbsb_2266_1);
  ovbsb(&S_ovbsb_1519_1);
  ovbsb(&S_ovbsb_1516_1);
  ovbsb(&S_ovbsb_1506_1);
  ovbsb(&S_ovbsb_1507_1);
  ovbsb(&S_ovbsb_2260_1);
  noto(&S_noto_1219_1);
  zzfs(&S_zzfs_2554_1);
  rs(&S_rs_2253_1);
  noto(&S_noto_2254_1);
  noto(&S_noto_2295_1);
  equz_p(&S_equz_p_327_1);
  noto(&S_noto_1596_1);
  cntch(&S_cntch_1617_1);
  rs(&S_rs_318_1);
  and2(&S_and2_1212_1);
  and2(&S_and2_332_1);
  and2(&S_and2_709_1);
  or5(&S_or5_1020_1);
  or5(&S_or5_1496_1);
  and2(&S_and2_1187_1);
  and2(&S_and2_1621_1);
  or5(&S_or5_1622_1);
  or5(&S_or5_1591_1);
  and2(&S_and2_1593_1);
  or2(&S_or2_1594_1);
  zpfs(&S_zpfs_2275_1);
  and4(&S_and4_2143_1);
  and3(&S_and3_2144_1);
  and3(&S_and3_2145_1);
  and2(&S_and2_2106_1);
  and2(&S_and2_2070_1);
  or3(&S_or3_2079_1);
  or3(&S_or3_2274_1);
  rs(&S_rs_2269_1);
  noto(&S_noto_2270_1);
  rs(&S_rs_2112_1);
  rs(&S_rs_2080_1);
  rs(&S_rs_1180_1);
  noto(&S_noto_1183_1);
  rs(&S_rs_1206_1);
  and2(&S_and2_352_1);
  and3(&S_and3_1175_1);
  and2(&S_and2_1122_1);
  and4(&S_and4_1129_1);
  and4(&S_and4_1135_1);
  or3(&S_or3_2111_1);
  orn(&S_orn_1359_1);
  orn(&S_orn_898_1);
  or3(&S_or3_1205_1);
  ornc(&S_ornc_1368_1);
  charint(&S_charint_1360_1);
  ornc(&S_ornc_905_1);
  charint(&S_charint_899_1);
  noto(&S_noto_353_1);
  rs(&S_rs_1116_1);
  rs(&S_rs_1204_1);
  or3(&S_or3_487_1);
  and3(&S_and3_496_1);
  and2(&S_and2_1163_1);
  and2(&S_and2_532_1);
  and2(&S_and2_498_1);
  fsumz(&S_fsumz_1361_1);
  fsumz(&S_fsumz_900_1);
  samhd(&S_samhd_511_1);
  samhd(&S_samhd_517_1);
  newstage(&S_newstage_513_1);
  ma(&S_ma_906_1);
  ma(&S_ma_1369_1);
  or4(&S_or4_507_1);
  or4(&S_or4_526_1);
  andn(&S_andn_1_1);
  and2(&S_and2_522_1);
  and2(&S_and2_519_1);
  ovbsb(&S_ovbsb_503_1);
  ovbsb(&S_ovbsb_500_1);
  ovbsb(&S_ovbsb_501_1);
  ovbsb(&S_ovbsb_502_1);
  ovbsb(&S_ovbsb_525_1);
  ovbsb(&S_ovbsb_529_1);
  ovbsb(&S_ovbsb_530_1);
  ovbsb(&S_ovbsb_531_1);
  cnshd(&S_cnshd_1370_1);
  cnshd(&S_cnshd_909_1);
  and2(&S_and2_1213_1);
  and2(&S_and2_725_1);
  or2(&S_or2_926_1);
  and2(&S_and2_983_1);
  and2(&S_and2_982_1);
  or3(&S_or3_992_1);
  and2(&S_and2_1460_1);
  and2(&S_and2_1461_1);
  or3(&S_or3_1470_1);
  or2(&S_or2_1403_1);
  and2(&S_and2_1194_1);
  ovbsb(&S_ovbsb_1464_1);
  ovbsb(&S_ovbsb_1465_1);
  ovbsb(&S_ovbsb_989_1);
  ovbsb(&S_ovbsb_986_1);
  and2(&S_and2_1231_1);
  noto(&S_noto_1230_1);
  or3(&S_or3_1223_1);
  fnapb(&S_fnapb_1405_1);
  zpfs(&S_zpfs_1397_1);
  zpfs(&S_zpfs_1398_1);
  newstage(&S_newstage_1410_1);
  fnapb(&S_fnapb_927_1);
  rs(&S_rs_1189_1);
  rs(&S_rs_1209_1);
  zpfs(&S_zpfs_1415_1);
  zpfs(&S_zpfs_939_1);
  zpfs(&S_zpfs_921_1);
  zpfs(&S_zpfs_922_1);
  or5(&S_or5_1380_1);
  and2(&S_and2_1392_1);
  and2(&S_and2_1396_1);
  or5(&S_or5_2190_1);
  or3(&S_or3_1885_1);
  or3(&S_or3_1877_1);
  or2(&S_or2_1891_1);
  or2(&S_or2_1883_1);
  ovbsb(&S_ovbsb_925_1);
  ovbsb(&S_ovbsb_924_1);
  ovbsb(&S_ovbsb_934_1);
  ovbsb(&S_ovbsb_929_1);
  ovbsb(&S_ovbsb_1412_1);
  ovbsb(&S_ovbsb_1393_1);
  ovbsb(&S_ovbsb_1390_1);
  ovbsb(&S_ovbsb_1408_1);
  noto(&S_noto_1215_1);
  or3(&S_or3_1208_1);
  zzfs(&S_zzfs_2556_1);
  orni(&S_orni_140_1);
  orn(&S_orn_459_1);
  orn(&S_orn_481_1);
  rs(&S_rs_1876_1);
  rs(&S_rs_1884_1);
  rs(&S_rs_1207_1);
  or2(&S_or2_461_1);
  or2(&S_or2_483_1);
  and2(&S_and2_757_1);
  or2(&S_or2_1315_1);
  or2(&S_or2_1316_1);
  and2(&S_and2_1252_1);
  or5(&S_or5_918_1);
  and2(&S_and2_1783_1);
  or4(&S_or4_1779_1);
  and2(&S_and2_1869_1);
  and2(&S_and2_1873_1);
  or4(&S_or4_2191_1);
  ovbsb(&S_ovbsb_1792_1);
  ovbsb(&S_ovbsb_1260_1);
  ovbsb(&S_ovbsb_766_1);
  or3(&S_or3_1199_1);
  orn(&S_orn_854_1);
  orn(&S_orn_1236_1);
  rs(&S_rs_1878_1);
  rs(&S_rs_1886_1);
  rs(&S_rs_1198_1);
  or2(&S_or2_844_1);
  or2(&S_or2_845_1);
  or4(&S_or4_825_1);
  and4(&S_and4_1196_1);
  or5(&S_or5_1283_1);
  or2(&S_or2_387_1);
  or2(&S_or2_391_1);
  ovbs(&S_ovbs_2197_1);
  noto(&S_noto_2198_1);
  and2(&S_and2_2204_1);
  and2(&S_and2_2216_1);
  or3(&S_or3_2192_1);
  and2(&S_and2_2193_1);
  or3(&S_or3_2206_1);
  and2(&S_and2_2207_1);
  or5(&S_or5_1766_1);
  or2(&S_or2_2444_1);
  rs(&S_rs_824_1);
  samhd(&S_samhd_390_1);
  and2(&S_and2_812_1);
  or2(&S_or2_814_1);
  or4(&S_or4_389_1);
  or5(&S_or5_1812_1);
  or2(&S_or2_2211_1);
  or2(&S_or2_2199_1);
  ovbs(&S_ovbs_2194_1);
  ovbs(&S_ovbs_2208_1);
  rs(&S_rs_2228_1);
  rs(&S_rs_2236_1);
  noto(&S_noto_2226_1);
  noto(&S_noto_2247_1);
  zpfs(&S_zpfs_2229_1);
  zpfs(&S_zpfs_2237_1);
  noto(&S_noto_2440_1);
  ovbsb(&S_ovbsb_396_1);
  ovbsb(&S_ovbsb_397_1);
  ovbsb(&S_ovbsb_398_1);
  rs(&S_rs_818_1);
  or2(&S_or2_2230_1);
  noto(&S_noto_2195_1);
  noto(&S_noto_2209_1);
  rs(&S_rs_2212_1);
  noto(&S_noto_2213_1);
  rs(&S_rs_2200_1);
  or2(&S_or2_2238_1);
  noto(&S_noto_2231_1);
  and2(&S_and2_2232_1);
  and2(&S_and2_2227_1);
  noto(&S_noto_2239_1);
  noto(&S_noto_2219_1);
  ovbsb(&S_ovbsb_2218_1);
  noto(&S_noto_2201_1);
  and2(&S_and2_2240_1);
  and4(&S_and4_2221_1);
  ovbs(&S_ovbs_2222_1);
  and2(&S_and2_2248_1);
  noto(&S_noto_2250_1);
  or2(&S_or2_2223_1);
  ovbsb(&S_ovbsb_2251_1);
  orn(&S_orn_669_1);
  orn(&S_orn_668_1);
  noto(&S_noto_2224_1);
  and4(&S_and4_2242_1);
  ovbs(&S_ovbs_2243_1);
  or2(&S_or2_2244_1);
  newstage(&S_newstage_671_1);
  or2(&S_or2_705_1);
  ovbs(&S_ovbs_2233_1);
  noto(&S_noto_2245_1);
  and2(&S_and2_704_1);
  setData(idpsrb2,&var2);
  setData(idpsrb1,&var3);
  setData(idpsrb4,&var1);
  setData(idpsb2,&var4);
  setData(idpsb1,&var5);
  setData(idR0S01LIM,&var1254);
  setData(idR0AD16LDU,&var1249);
  setData(idR0S01LZ2,&var31);
  setData(idR0S01LZ1,&var31);
  setData(idR0S01LDU,&var32);
  setData(idR8AD21LDU,&var1253);
  setData(idR0VN15RDU,&var45);
  setData(idB3CV01RDU,&var1551);
  setData(idTestDiagnDU,&var258);
  setData(idR0DE3CLDU,&var260);
  setData(idR0DE3DLDU,&var259);
  setData(idTTLDU,&var262);
  setData(idB3AB13LDU,&var120);
  setData(idA3AB13LDU,&var206);
  setData(idR3VS01IDU,&var391);
  setData(idR3VS12LDU,&var389);
  setData(idR3VS22LDU,&var390);
  setData(idR5VS01IDU,&var388);
  setData(idR5VS12LDU,&var386);
  setData(idR5VS22LDU,&var387);
  setData(idB3AB15LDU,&var122);
  setData(idB3EE03LDU,&var1046);
  setData(idA3EE03LDU,&var1047);
  setData(idB3AB19LDU,&var121);
  setData(idA3AB19LDU,&var200);
  setData(idR0VL23LDU,&var1286);
  setData(idR0VL22LDU,&var1308);
  setData(idR0AD05LZ2,&var327);
  setData(idR0AD05LZ1,&var327);
  setData(idR0AD04LZ2,&var30);
  setData(idR0AD04LZ1,&var30);
  setData(idR0AD03LZ2,&var326);
  setData(idR0AD03LZ1,&var326);
  setData(idR0CN95LDU,&var466);
  setData(idR0CN94LDU,&var465);
  setData(idR0CN93LDU,&var464);
  setData(idR0AB19LDU,&var76);
  setData(idR0VN12RDU,&var1215);
  setData(idR0VN11RDU,&var1213);
  setData(idR0CN92LDU,&var432);
  setData(idR0AB20LDU,&var75);
  setData(idA3AB15LDU,&var204);
  setData(idA3MC03RDU,&var462);
  setData(idR0CN91LDU,&var461);
  setData(idA3MC02RDU,&var460);
  setData(idA3MC01RDU,&var459);
  setData(idR0AB18LDU,&var77);
  setData(idR0AB17LDU,&var78);
  setData(idR0AB16LDU,&var79);
  setData(idB1AB19LDU,&var151);
  setData(idA3ZAV,&var1556);
  setData(idA1ZAV,&var1619);
  setData(idB3IS12LDU,&var483);
  setData(idA3IS12LDU,&var484);
  setData(idR0AB15LDU,&var489);
  setData(idR0AB14LDU,&var487);
  setData(idA4DW,&var1396);
  setData(idA4UP,&var1397);
  setData(idR4ABL,&var1858);
  setData(idA9ZAV,&var1494);
  setData(idA8ZAV,&var1695);
  setData(idA2ZAV,&var1700);
  setData(idB8ZAV,&var1705);
  setData(idA5ZAV,&var1773);
  setData(idR2ZAV,&var1649);
  setData(idA6ZAV,&var1775);
  setData(idA4ZAV,&var1774);
  setData(idR0AB13LDU,&var556);
  setData(idR0AB12LDU,&var560);
  setData(idR0AB11LDU,&var564);
  setData(idR0AB10LDU,&var568);
  setData(idR0AB09LDU,&var572);
  setData(idR0AB08LDU,&var80);
  setData(idB6AB05LDU,&var103);
  setData(idR0VS11LDU,&var1918);
  setData(idA8VS01IDU,&var1699);
  setData(idB8VS01IDU,&var1709);
  setData(idR2AD10LDU,&var1654);
  setData(idR2AD20LDU,&var1655);
  setData(idB6VS01IDU,&var1846);
  setData(idR0AB07LDU,&var81);
  setData(idR0EE03LDU,&var641);
  setData(idR0VX02LDU,&var1052);
  setData(idR0AD21LDU,&var1050);
  setData(idB2AB15LDU,&var137);
  setData(idA2AB15LDU,&var221);
  setData(idR0AB05LDU,&var1368);
  setData(idR0AB03LDU,&var1379);
  setData(idA1AB19LDU,&var232);
  setData(idR0VZ71LDU,&var313);
  setData(idR0VL01RDU,&var1414);
  setData(idB7AZ03LDU,&var46);
  setData(idA7AZ03LDU,&var47);
  setData(idB2VS01IDU,&var1687);
  setData(idB2VS21LDU,&var1689);
  setData(idB2VS11LDU,&var1688);
  setData(idR0VP73LDU,&var728);
  setData(idR0VS18LDU,&var805);
  setData(idB3VX01LDU,&var675);
  setData(idA3VX01LDU,&var676);
  setData(idB2VS32LDU,&var602);
  setData(idA2VS32LDU,&var603);
  setData(idR0VS17LDU,&var795);
  setData(idR0VX09LDU,&var420);
  moveData(idR0VX08IDU,idR0MW12IP1);
  setData(idR0VW23LDU,&var1147);
  setData(idR0VW13LDU,&var1146);
  setData(idB7AP31LDU,&var1399);
  setData(idA7AP31LDU,&var1400);
  setData(idB3AD31LDU,&var1457);
  setData(idB3AD34LDU,&var1458);
  setData(idA3AD31LDU,&var1463);
  setData(idA3AD34LDU,&var1460);
  setData(idA3AD33LDU,&var1462);
  setData(idB2AD33LDU,&var581);
  setData(idA2AD33LDU,&var584);
  setData(idR0AB01LDU,&var1486);
  setData(idB9AB02LDU,&var82);
  setData(idB9AB01LDU,&var83);
  setData(idB9AZ03LDU,&var84);
  setData(idA9AB02LDU,&var168);
  setData(idA9AB01LDU,&var167);
  setData(idA9AZ03LDU,&var166);
  setData(idA9AD10LDU,&var1504);
  setData(idB9AD10LDU,&var1498);
  setData(idR1VS01IDU,&var1665);
  setData(idR2VS01IDU,&var1656);
  setData(idR4VS01IDU,&var1837);
  setData(idA6VS01IDU,&var1855);
  setData(idB5VS01IDU,&var1819);
  setData(idA5VS01IDU,&var1828);
  setData(idB4VS22LDU,&var1800);
  setData(idB4VS12LDU,&var1799);
  setData(idB4VS01IDU,&var1801);
  setData(idA4VS22LDU,&var1809);
  setData(idA4VS12LDU,&var1808);
  setData(idA4VS01IDU,&var1810);
  setData(idA2VS01IDU,&var1728);
  setData(idB3VS01IDU,&var1546);
  setData(idA3VS01IDU,&var1578);
  setData(idB1VS01IDU,&var1607);
  setData(idA1VS01IDU,&var1640);
  setData(idR0VS21IDU,&var1389);
  setData(idR0VX03LDU,&var997);
  setData(idR0VL21IDU,&var1299);
  setData(idR0VL05RDU,&var662);
  setData(idR0VL03RDU,&var668);
  setData(idR0AB02LDU,&var1362);
  setData(idR0AB06LDU,&var1365);
  setData(idR0AB04LDU,&var1373);
  setData(idR0VL04RDU,&var665);
  setData(idR0VL02RDU,&var659);
  setData(idB3AD33LDU,&var1456);
  setData(idR0VL06RDU,&var672);
  setData(idR0VL11IDU,&var1510);
  setData(idR0VL01IDU,&var1511);
  setData(idR0VX01LDU,&var1054);
  setData(idB1AD32LDU,&var1464);
  setData(idA1AD32LDU,&var1466);
  setData(idB2AD32LDU,&var609);
  setData(idA2AD32LDU,&var611);
  setData(idB1AD31LDU,&var1467);
  setData(idA1AD31LDU,&var1468);
  setData(idB2AD31LDU,&var612);
  setData(idA2AD31LDU,&var613);
  setData(idB3AB20LDU,&var115);
  setData(idB3AB18LDU,&var118);
  setData(idB3AB17LDU,&var116);
  setData(idB3AB16LDU,&var117);
  setData(idB3AB14LDU,&var119);
  setData(idB3AB12LDU,&var123);
  setData(idB3AB11LDU,&var124);
  setData(idB3AB10LDU,&var125);
  setData(idB3AB09LDU,&var126);
  setData(idB3AB06LDU,&var129);
  setData(idB3AB05LDU,&var130);
  setData(idB3AB08LDU,&var127);
  setData(idB3AB07LDU,&var128);
  setData(idB3CV02RDU,&var1545);
  setData(idB3AD01LDU,&var1538);
  setData(idB3AD05LDU,&var1544);
  setData(idB3AD04LDU,&var1543);
  setData(idB3AD03LDU,&var1542);
  setData(idB3AD02LDU,&var1541);
  setData(idB3AD21LDU,&var1539);
  setData(idB3AD11LDU,&var1540);
  setData(idB3AZ03LDU,&var134);
  setData(idB3VS22LDU,&var1549);
  setData(idB3AB01LDU,&var132);
  setData(idB3AB02LDU,&var131);
  setData(idB3AB04LDU,&var133);
  setData(idB3VS12LDU,&var1550);
  setData(idA3AB20LDU,&var199);
  setData(idA3AB18LDU,&var201);
  setData(idA3AB17LDU,&var202);
  setData(idA3AB16LDU,&var203);
  setData(idA3AB14LDU,&var205);
  setData(idA3AB12LDU,&var207);
  setData(idA3AB11LDU,&var208);
  setData(idA3AB10LDU,&var209);
  setData(idA3AB09LDU,&var210);
  setData(idA3AB06LDU,&var212);
  setData(idA3AB05LDU,&var214);
  setData(idA3AB08LDU,&var211);
  setData(idA3AB07LDU,&var213);
  setData(idA3CV02RDU,&var1577);
  setData(idA3AD01LDU,&var1570);
  setData(idA3AD05LDU,&var1576);
  setData(idA3AD04LDU,&var1575);
  setData(idA3AD03LDU,&var1574);
  setData(idA3AD02LDU,&var1573);
  setData(idA3AD21LDU,&var1571);
  setData(idA3AD11LDU,&var1572);
  setData(idA3AZ03LDU,&var218);
  setData(idA3VS22LDU,&var1581);
  setData(idA3AB01LDU,&var215);
  setData(idA3AB02LDU,&var216);
  setData(idA3AB04LDU,&var217);
  setData(idA3CV01RDU,&var1583);
  setData(idA3VS12LDU,&var1582);
  setData(idB1AB18LDU,&var148);
  setData(idB1AB17LDU,&var149);
  setData(idB1AB16LDU,&var150);
  setData(idB1AB14LDU,&var152);
  setData(idB1AB13LDU,&var153);
  setData(idB1AB12LDU,&var154);
  setData(idB1AB11LDU,&var155);
  setData(idB1AB10LDU,&var156);
  setData(idB1AB09LDU,&var157);
  setData(idB1AB06LDU,&var159);
  setData(idB1AB05LDU,&var161);
  setData(idB1AB08LDU,&var158);
  setData(idB1AB07LDU,&var160);
  setData(idB1CV02RDU,&var1606);
  setData(idB1AD01LDU,&var1599);
  setData(idB1AD05LDU,&var1605);
  setData(idB1AD04LDU,&var1604);
  setData(idB1AD03LDU,&var1603);
  setData(idB1AD02LDU,&var1602);
  setData(idB1AD21LDU,&var1601);
  setData(idB1AD11LDU,&var1600);
  setData(idB1AZ03LDU,&var165);
  setData(idB1VS22LDU,&var1611);
  setData(idB1AB01LDU,&var162);
  setData(idB1AB02LDU,&var163);
  setData(idB1AB04LDU,&var164);
  setData(idB1CV01RDU,&var1612);
  setData(idB1VS12LDU,&var1610);
  setData(idA1AB18LDU,&var233);
  setData(idA1AB17LDU,&var234);
  setData(idA1AB16LDU,&var235);
  setData(idA1AB14LDU,&var236);
  setData(idA1AB13LDU,&var237);
  setData(idA1AB12LDU,&var238);
  setData(idA1AB11LDU,&var239);
  setData(idA1AB10LDU,&var240);
  setData(idA1AB09LDU,&var241);
  setData(idA1AB06LDU,&var244);
  setData(idA1AB05LDU,&var245);
  setData(idA1AB08LDU,&var242);
  setData(idA1AB07LDU,&var243);
  setData(idA1CV02RDU,&var1639);
  setData(idA1AD01LDU,&var1632);
  setData(idA1AD05LDU,&var1638);
  setData(idA1AD04LDU,&var1637);
  setData(idA1AD03LDU,&var1636);
  setData(idA1AD02LDU,&var1635);
  setData(idA1AD21LDU,&var1634);
  setData(idA1AD11LDU,&var1633);
  setData(idA1AZ03LDU,&var249);
  setData(idA1VS22LDU,&var1642);
  setData(idA1AB01LDU,&var248);
  setData(idA1AB02LDU,&var247);
  setData(idA1AB04LDU,&var246);
  setData(idA1CV01RDU,&var1643);
  setData(idA1VS12LDU,&var1641);
  setData(idR1AD20LDU,&var1664);
  setData(idR1AD10LDU,&var1663);
  setData(idR2AB04LDU,&var67);
  setData(idR1AB04LDU,&var71);
  setData(idR2AB02LDU,&var68);
  setData(idR2AB01LDU,&var69);
  setData(idR2AZ03LDU,&var70);
  setData(idR1AB02LDU,&var72);
  setData(idR1AB01LDU,&var73);
  setData(idR1AZ03LDU,&var74);
  setData(idB2AB17LDU,&var135);
  setData(idB2AB16LDU,&var136);
  setData(idB2AB14LDU,&var138);
  setData(idB2AB13LDU,&var139);
  setData(idB2AB12LDU,&var140);
  setData(idB2AB11LDU,&var141);
  setData(idB2AB10LDU,&var142);
  setData(idB2AB09LDU,&var143);
  setData(idB2AB06LDU,&var146);
  setData(idB2AB05LDU,&var147);
  setData(idB2AB08LDU,&var144);
  setData(idB2AB07LDU,&var145);
  setData(idB2CV02RDU,&var1686);
  setData(idB2AD01LDU,&var1679);
  setData(idB2AD05LDU,&var1685);
  setData(idB2AD04LDU,&var1684);
  setData(idB2AD03LDU,&var1683);
  setData(idB2AD02LDU,&var1682);
  setData(idB2AD21LDU,&var1681);
  setData(idB2AD11LDU,&var1680);
  setData(idB2AZ03LDU,&var255);
  setData(idB2AB01LDU,&var256);
  setData(idB2AB02LDU,&var257);
  setData(idB2AB04LDU,&var254);
  setData(idB2CV01RDU,&var1690);
  setData(idA2CV02RDU,&var1727);
  setData(idA2AD01LDU,&var1720);
  setData(idA2AB17LDU,&var219);
  setData(idA2AB16LDU,&var220);
  setData(idA2AB14LDU,&var222);
  setData(idA2AB13LDU,&var223);
  setData(idA2AB12LDU,&var224);
  setData(idA2AB11LDU,&var225);
  setData(idA2AB10LDU,&var226);
  setData(idA2AB09LDU,&var227);
  setData(idA2AB06LDU,&var229);
  setData(idA2AB05LDU,&var231);
  setData(idA2AB08LDU,&var228);
  setData(idA2AB07LDU,&var230);
  setData(idA2AD05LDU,&var1726);
  setData(idA2AD04LDU,&var1725);
  setData(idA2AD03LDU,&var1724);
  setData(idA2AD02LDU,&var1723);
  setData(idA2AD21LDU,&var1722);
  setData(idA2AD11LDU,&var1721);
  setData(idA2AZ03LDU,&var253);
  setData(idA2VS21LDU,&var1732);
  setData(idA2AB01LDU,&var252);
  setData(idA2AB02LDU,&var251);
  setData(idA2AB04LDU,&var250);
  setData(idA2CV01RDU,&var1733);
  setData(idA2VS11LDU,&var1731);
  setData(idA8AB01LDU,&var182);
  setData(idA8AB02LDU,&var181);
  setData(idA8AB14LDU,&var169);
  setData(idA8AB13LDU,&var170);
  setData(idA8AB12LDU,&var171);
  setData(idA8AB11LDU,&var172);
  setData(idA8AB10LDU,&var173);
  setData(idA8AB09LDU,&var174);
  setData(idA8AB08LDU,&var175);
  setData(idA8AB04LDU,&var180);
  setData(idA8AD20LDU,&var1698);
  setData(idA8AD10LDU,&var1697);
  setData(idA8AZ03LDU,&var179);
  setData(idA8VS22LDU,&var1745);
  setData(idA8AB05LDU,&var176);
  setData(idA8AB07LDU,&var177);
  setData(idA8AB06LDU,&var178);
  setData(idA8CV01RDU,&var1746);
  setData(idA8VS12LDU,&var1744);
  setData(idB8AB02LDU,&var96);
  setData(idB8AB14LDU,&var85);
  setData(idB8AB13LDU,&var86);
  setData(idB8AB12LDU,&var87);
  setData(idB8AB11LDU,&var88);
  setData(idB8AB10LDU,&var89);
  setData(idB8AB09LDU,&var90);
  setData(idB8AB08LDU,&var91);
  setData(idB8AB04LDU,&var97);
  setData(idB8AB01LDU,&var98);
  setData(idB8AD20LDU,&var1708);
  setData(idB8AD10LDU,&var1707);
  setData(idB8AZ03LDU,&var95);
  setData(idB8VS22LDU,&var1762);
  setData(idB8AB05LDU,&var92);
  setData(idB8AB07LDU,&var93);
  setData(idB8AB06LDU,&var94);
  setData(idB8CV01RDU,&var1763);
  setData(idB8VS12LDU,&var1761);
  setData(idA6AB05LDU,&var187);
  setData(idB6AB09LDU,&var99);
  setData(idB6AB08LDU,&var100);
  setData(idB6AB07LDU,&var101);
  setData(idB6AB06LDU,&var102);
  setData(idA6AB09LDU,&var183);
  setData(idA6AB08LDU,&var184);
  setData(idA6AB07LDU,&var185);
  setData(idA6AB06LDU,&var186);
  setData(idB5AB04LDU,&var108);
  setData(idA5AB04LDU,&var193);
  setData(idB4AB02LDU,&var112);
  setData(idB4AB01LDU,&var113);
  setData(idB4AZ03LDU,&var114);
  setData(idA4AB02LDU,&var197);
  setData(idA4AB01LDU,&var198);
  setData(idA4AZ03LDU,&var196);
  setData(idA4AD10LDU,&var1807);
  setData(idB4AD10LDU,&var1798);
  setData(idB5AB02LDU,&var109);
  setData(idB5AB01LDU,&var110);
  setData(idB5AZ03LDU,&var111);
  setData(idA5AB02LDU,&var194);
  setData(idA5AB01LDU,&var195);
  setData(idA5AZ03LDU,&var192);
  setData(idA5AD20LDU,&var1827);
  setData(idA5AD10LDU,&var1826);
  setData(idB5AD20LDU,&var1818);
  setData(idB5AD10LDU,&var1817);
  setData(idR4AD20LDU,&var1836);
  setData(idR4AD10LDU,&var1835);
  setData(idR4AB18LDU,&var48);
  setData(idR4AB17LDU,&var49);
  setData(idR4AB16LDU,&var50);
  setData(idR4AB15LDU,&var51);
  setData(idR4AB14LDU,&var52);
  setData(idR4AB13LDU,&var53);
  setData(idR4AB12LDU,&var54);
  setData(idR4AB11LDU,&var66);
  setData(idR4AB10LDU,&var55);
  setData(idR4AB09LDU,&var56);
  setData(idR4AB08LDU,&var57);
  setData(idR4AB07LDU,&var58);
  setData(idR4AB06LDU,&var59);
  setData(idR4AB05LDU,&var60);
  setData(idR4AB04LDU,&var61);
  setData(idR4AB03LDU,&var63);
  setData(idR4AZ03LDU,&var62);
  setData(idR4AB02LDU,&var64);
  setData(idR4AB01LDU,&var65);
  setData(idB6AB04LDU,&var104);
  setData(idA6AB04LDU,&var189);
  setData(idB6AB02LDU,&var106);
  setData(idB6AB01LDU,&var105);
  setData(idB6AZ03LDU,&var107);
  setData(idA6AB02LDU,&var190);
  setData(idA6AB01LDU,&var191);
  setData(idA6AZ03LDU,&var188);
  setData(idB6AD20LDU,&var1845);
  setData(idB6AD10LDU,&var1844);
  setData(idA6AD20LDU,&var1854);
  setData(idA6AD10LDU,&var1853);
  setData(idR0ES01LDU,&var1136);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<10;i++ )
    array_m356_rz_1[i] = &(&internal1_m356_rz)[i*1];
  for( i=0;i<10;i++ )
    array_m298_rz_1[i] = &(&internal1_m298_rz)[i*1];
  for( i=0;i<6;i++ )
    array_m1600_rz_1[i] = &(&internal1_m1600_rz)[i*1];
  for( i=0;i<60;i++ )
    array_m1509_x0_1[i] = &(&internal1_m1509_x0)[i*5];
  for( i=0;i<60;i++ )
    array_m1509_tim0_1[i] = &(&internal1_m1509_tim0)[i*5];
  for( i=0;i<60;i++ )
    array_m1035_x0_1[i] = &(&internal1_m1035_x0)[i*5];
  for( i=0;i<60;i++ )
    array_m1035_tim0_1[i] = &(&internal1_m1035_tim0)[i*5];
  for( i=0;i<150;i++ )
    array_m573_x0_1[i] = &(&internal1_m573_x0)[i*5];
  for( i=0;i<150;i++ )
    array_m573_tim0_1[i] = &(&internal1_m573_tim0)[i*5];
  for( i=0;i<150;i++ )
    array_m201_x0_1[i] = &(&internal1_m201_x0)[i*5];
  for( i=0;i<150;i++ )
    array_m201_tim0_1[i] = &(&internal1_m201_tim0)[i*5];
  for( i=0;i<80;i++ )
    array_m927_x0_1[i] = &(&internal1_m927_x0)[i*5];
  for( i=0;i<80;i++ )
    array_m927_tim0_1[i] = &(&internal1_m927_tim0)[i*5];
  for( i=0;i<80;i++ )
    array_m1405_x0_1[i] = &(&internal1_m1405_x0)[i*5];
  for( i=0;i<80;i++ )
    array_m1405_tim0_1[i] = &(&internal1_m1405_tim0)[i*5];
  for( i=0;i<20;i++ )
    array_m1826_x0_1[i] = &(&internal1_m1826_x0)[i*5];
  for( i=0;i<20;i++ )
    array_m1826_tim0_1[i] = &(&internal1_m1826_tim0)[i*5];
  for( i=0;i<20;i++ )
    array_m1300_x0_1[i] = &(&internal1_m1300_x0)[i*5];
  for( i=0;i<20;i++ )
    array_m1300_tim0_1[i] = &(&internal1_m1300_tim0)[i*5];
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
