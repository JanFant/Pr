#ifndef SCM_H
#define SCM_H
// Подсистема scm:SCM
static char SimulOn=0;
static short CodeSub=1;
static char SimulIP[]="192.168.10.247\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 3569
static char BUFFER[3569];
#define A0SR01RIM	 BUFFER[0]	//(A0SR01RIM) Текущая реактивность AЗ1
#define idA0SR01RIM	 1	//(A0SR01RIM) Текущая реактивность AЗ1
#define A1AD11LDU	 BUFFER[5]	//(A1AD11LDU) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 2	//(A1AD11LDU) Сигнал на перемещение ББ1 вверх
#define A1AD21LDU	 BUFFER[7]	//(A1AD21LDU) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 3	//(A1AD21LDU) Сигнал на перемещение ББ1 вниз
#define A1AD01LDU	 BUFFER[9]	//(A1AD01LDU) Разрешение движения ББ1
#define idA1AD01LDU	 4	//(A1AD01LDU) Разрешение движения ББ1
#define A1AD02LDU	 BUFFER[11]	//(A1AD02LDU) 0-й бит скорости ББ1
#define idA1AD02LDU	 5	//(A1AD02LDU) 0-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[13]	//(A1AD03LDU) 1-й бит скорости ББ1
#define idA1AD03LDU	 6	//(A1AD03LDU) 1-й бит скорости ББ1
#define A1AD04LDU	 BUFFER[15]	//(A1AD04LDU) 2-й бит скорости ББ1
#define idA1AD04LDU	 7	//(A1AD04LDU) 2-й бит скорости ББ1
#define A1AD05LDU	 BUFFER[17]	//(A1AD05LDU) паритет команды на ББ1
#define idA1AD05LDU	 8	//(A1AD05LDU) паритет команды на ББ1
#define B1AD11LDU	 BUFFER[19]	//(B1AD11LDU) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 9	//(B1AD11LDU) Сигнал на перемещение ББ2 вверх
#define B1AD21LDU	 BUFFER[21]	//(B1AD21LDU) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 10	//(B1AD21LDU) Сигнал на перемещение ББ2 вниз
#define B1AD01LDU	 BUFFER[23]	//(B1AD01LDU) Разрешение движения ББ2
#define idB1AD01LDU	 11	//(B1AD01LDU) Разрешение движения ББ2
#define B1AD02LDU	 BUFFER[25]	//(B1AD02LDU) 0-й бит скорости  ББ2
#define idB1AD02LDU	 12	//(B1AD02LDU) 0-й бит скорости  ББ2
#define B1AD03LDU	 BUFFER[27]	//(B1AD03LDU) 1-й бит скорости ББ2
#define idB1AD03LDU	 13	//(B1AD03LDU) 1-й бит скорости ББ2
#define B1AD04LDU	 BUFFER[29]	//(B1AD04LDU) 2-й бит скорости ББ2
#define idB1AD04LDU	 14	//(B1AD04LDU) 2-й бит скорости ББ2
#define B1AD05LDU	 BUFFER[31]	//(B1AD05LDU) паритет команды на ББ2
#define idB1AD05LDU	 15	//(B1AD05LDU) паритет команды на ББ2
#define A2AD11LDU	 BUFFER[33]	//(A2AD11LDU) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 16	//(A2AD11LDU) Сигнал на перемещение РБ1 вверх
#define A2AD21LDU	 BUFFER[35]	//(A2AD21LDU) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 17	//(A2AD21LDU) Сигнал на перемещение РБ1 вниз
#define A2AD01LDU	 BUFFER[37]	//(A2AD01LDU) Разрешение движения РБ1
#define idA2AD01LDU	 18	//(A2AD01LDU) Разрешение движения РБ1
#define A2AD02LDU	 BUFFER[39]	//(A2AD02LDU) 0-й бит скорости РБ1
#define idA2AD02LDU	 19	//(A2AD02LDU) 0-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[41]	//(A2AD03LDU) 1-й бит скорости РБ1
#define idA2AD03LDU	 20	//(A2AD03LDU) 1-й бит скорости РБ1
#define A2AD04LDU	 BUFFER[43]	//(A2AD04LDU) 2-й бит скорости РБ1
#define idA2AD04LDU	 21	//(A2AD04LDU) 2-й бит скорости РБ1
#define A2AD05LDU	 BUFFER[45]	//(A2AD05LDU) паритет команды на РБ1
#define idA2AD05LDU	 22	//(A2AD05LDU) паритет команды на РБ1
#define A2AD33LDU	 BUFFER[47]	//(A2AD33LDU) Клапан (Подъем РБ1) закрыть (обесточить)
#define idA2AD33LDU	 23	//(A2AD33LDU) Клапан (Подъем РБ1) закрыть (обесточить)
#define B2AD11LDU	 BUFFER[49]	//(B2AD11LDU) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 24	//(B2AD11LDU) Сигнал на перемещение РБ2 вверх
#define B2AD21LDU	 BUFFER[51]	//(B2AD21LDU) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 25	//(B2AD21LDU) Сигнал на перемещение РБ2 вниз
#define B2AD01LDU	 BUFFER[53]	//(B2AD01LDU) Разрешение движения РБ2
#define idB2AD01LDU	 26	//(B2AD01LDU) Разрешение движения РБ2
#define B2AD02LDU	 BUFFER[55]	//(B2AD02LDU) 0-й бит скорости РБ2
#define idB2AD02LDU	 27	//(B2AD02LDU) 0-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[57]	//(B2AD03LDU) 1-й бит скорости РБ2
#define idB2AD03LDU	 28	//(B2AD03LDU) 1-й бит скорости РБ2
#define B2AD04LDU	 BUFFER[59]	//(B2AD04LDU) 2-й бит скорости РБ2
#define idB2AD04LDU	 29	//(B2AD04LDU) 2-й бит скорости РБ2
#define B2AD05LDU	 BUFFER[61]	//(B2AD05LDU) паритет команды на РБ2
#define idB2AD05LDU	 30	//(B2AD05LDU) паритет команды на РБ2
#define B2AD33LDU	 BUFFER[63]	//(B2AD33LDU) Клапан (Подъем РБ2) закрыть (обесточить)
#define idB2AD33LDU	 31	//(B2AD33LDU) Клапан (Подъем РБ2) закрыть (обесточить)
#define A3AD11LDU	 BUFFER[65]	//(A3AD11LDU) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 32	//(A3AD11LDU) Сигнал на перемещение ИС1 вверх
#define A3AD21LDU	 BUFFER[67]	//(A3AD21LDU) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 33	//(A3AD21LDU) Сигнал на перемещение ИС1 вниз
#define A3AD01LDU	 BUFFER[69]	//(A3AD01LDU) Разрешение движения ИС1
#define idA3AD01LDU	 34	//(A3AD01LDU) Разрешение движения ИС1
#define A3AD02LDU	 BUFFER[71]	//(A3AD02LDU) 0-й бит скорости ИС1
#define idA3AD02LDU	 35	//(A3AD02LDU) 0-й бит скорости ИС1
#define A3AD03LDU	 BUFFER[73]	//(A3AD03LDU) 1-й бит скорости ИС1
#define idA3AD03LDU	 36	//(A3AD03LDU) 1-й бит скорости ИС1
#define A3AD04LDU	 BUFFER[75]	//(A3AD04LDU) 2-й бит скорости ИС1
#define idA3AD04LDU	 37	//(A3AD04LDU) 2-й бит скорости ИС1
#define A3AD05LDU	 BUFFER[77]	//(A3AD05LDU) паритет команды на ИС1
#define idA3AD05LDU	 38	//(A3AD05LDU) паритет команды на ИС1
#define A3AD33LDU	 BUFFER[79]	//(A3AD33LDU) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define idA3AD33LDU	 39	//(A3AD33LDU) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define B3AD11LDU	 BUFFER[81]	//(B3AD11LDU) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 40	//(B3AD11LDU) Сигнал на перемещение ИС2 вверх
#define B3AD21LDU	 BUFFER[83]	//(B3AD21LDU) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 41	//(B3AD21LDU) Сигнал на перемещение ИС2 вниз
#define B3AD01LDU	 BUFFER[85]	//(B3AD01LDU) Разрешение движения ИС2
#define idB3AD01LDU	 42	//(B3AD01LDU) Разрешение движения ИС2
#define B3AD02LDU	 BUFFER[87]	//(B3AD02LDU) 0-й бит скорости ИС2
#define idB3AD02LDU	 43	//(B3AD02LDU) 0-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[89]	//(B3AD03LDU) 1-й бит скорости ИС2
#define idB3AD03LDU	 44	//(B3AD03LDU) 1-й бит скорости ИС2
#define B3AD04LDU	 BUFFER[91]	//(B3AD04LDU) 2-й бит скорости ИС2
#define idB3AD04LDU	 45	//(B3AD04LDU) 2-й бит скорости ИС2
#define B3AD05LDU	 BUFFER[93]	//(B3AD05LDU) паритет команды на ИС2
#define idB3AD05LDU	 46	//(B3AD05LDU) паритет команды на ИС2
#define B3AD33LDU	 BUFFER[95]	//(B3AD33LDU) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define idB3AD33LDU	 47	//(B3AD33LDU) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define B0SR01RIM	 BUFFER[97]	//(B0SR01RIM) Текущая реактивность AЗ2
#define idB0SR01RIM	 48	//(B0SR01RIM) Текущая реактивность AЗ2
#define R4AD10LDU	 BUFFER[102]	//(R4AD10LDU) Перемещение тележки вперед
#define idR4AD10LDU	 49	//(R4AD10LDU) Перемещение тележки вперед
#define R4AD20LDU	 BUFFER[104]	//(R4AD20LDU) Перемещение тележки назад
#define idR4AD20LDU	 50	//(R4AD20LDU) Перемещение тележки назад
#define B8AD10LDU	 BUFFER[106]	//(B8AD10LDU) Перемещение АЗ2 вперед
#define idB8AD10LDU	 51	//(B8AD10LDU) Перемещение АЗ2 вперед
#define B8AD20LDU	 BUFFER[108]	//(B8AD20LDU) Перемещение АЗ2 назад
#define idB8AD20LDU	 52	//(B8AD20LDU) Перемещение АЗ2 назад
#define A8AD10LDU	 BUFFER[110]	//(A8AD10LDU) Перемещение ДС2 вперед
#define idA8AD10LDU	 53	//(A8AD10LDU) Перемещение ДС2 вперед
#define A8AD20LDU	 BUFFER[112]	//(A8AD20LDU) Перемещение ДС2 назад
#define idA8AD20LDU	 54	//(A8AD20LDU) Перемещение ДС2 назад
#define A6AD10LDU	 BUFFER[114]	//(A6AD10LDU) Открыть БЗ1
#define idA6AD10LDU	 55	//(A6AD10LDU) Открыть БЗ1
#define A6AD20LDU	 BUFFER[116]	//(A6AD20LDU) Закрыть БЗ1
#define idA6AD20LDU	 56	//(A6AD20LDU) Закрыть БЗ1
#define B6AD10LDU	 BUFFER[118]	//(B6AD10LDU) Открыть БЗ2
#define idB6AD10LDU	 57	//(B6AD10LDU) Открыть БЗ2
#define B6AD20LDU	 BUFFER[120]	//(B6AD20LDU) Закрыть БЗ2
#define idB6AD20LDU	 58	//(B6AD20LDU) Закрыть БЗ2
#define R1AD10LDU	 BUFFER[122]	//(R1AD10LDU) Опустить МДЗ1 в зону облучения
#define idR1AD10LDU	 59	//(R1AD10LDU) Опустить МДЗ1 в зону облучения
#define R1AD20LDU	 BUFFER[124]	//(R1AD20LDU) Поднять МДЗ1
#define idR1AD20LDU	 60	//(R1AD20LDU) Поднять МДЗ1
#define R2AD10LDU	 BUFFER[126]	//(R2AD10LDU) Опустить МДЗ2 в зону облучения
#define idR2AD10LDU	 61	//(R2AD10LDU) Опустить МДЗ2 в зону облучения
#define R2AD20LDU	 BUFFER[128]	//(R2AD20LDU) Поднять МДЗ2
#define idR2AD20LDU	 62	//(R2AD20LDU) Поднять МДЗ2
#define A5AD10LDU	 BUFFER[130]	//(A5AD10LDU) Поднять НЛ1
#define idA5AD10LDU	 63	//(A5AD10LDU) Поднять НЛ1
#define A5AD20LDU	 BUFFER[132]	//(A5AD20LDU) Опустить НЛ1
#define idA5AD20LDU	 64	//(A5AD20LDU) Опустить НЛ1
#define B5AD10LDU	 BUFFER[134]	//(B5AD10LDU) Поднять НЛ2
#define idB5AD10LDU	 65	//(B5AD10LDU) Поднять НЛ2
#define B5AD20LDU	 BUFFER[136]	//(B5AD20LDU) Опустить НЛ2
#define idB5AD20LDU	 66	//(B5AD20LDU) Опустить НЛ2
#define A0SN08RIM	 BUFFER[138]	//(A0SN08RIM) Поток нейтронов AЗ1(нейтр/с)
#define idA0SN08RIM	 67	//(A0SN08RIM) Поток нейтронов AЗ1(нейтр/с)
#define B0SN08RIM	 BUFFER[143]	//(B0SN08RIM) Поток нейтронов AЗ2(нейтр/с)
#define idB0SN08RIM	 68	//(B0SN08RIM) Поток нейтронов AЗ2(нейтр/с)
#define R0CR01RIM	 BUFFER[148]	//(R0CR01RIM) Коэффициент 12 связи АЗ1,2
#define idR0CR01RIM	 69	//(R0CR01RIM) Коэффициент 12 связи АЗ1,2
#define R0CR02RIM	 BUFFER[153]	//(R0CR02RIM) Коэффициент 11 связи АЗ1,2
#define idR0CR02RIM	 70	//(R0CR02RIM) Коэффициент 11 связи АЗ1,2
#define R0SR02RIM	 BUFFER[158]	//(R0SR02RIM) Текущая мощность РУ (ватт)
#define idR0SR02RIM	 71	//(R0SR02RIM) Текущая мощность РУ (ватт)
#define R0AD14LDU	 BUFFER[163]	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 72	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
#define R8AD21LDU	 BUFFER[165]	//(R8AD21LDU) Запуск системы инициирования
#define idR8AD21LDU	 73	//(R8AD21LDU) Запуск системы инициирования
#define R0VZ71LZ1	 BUFFER[167]	//(R0VZ71LZ1) Обобщенный сигнал по АЗ  1 канала
#define idR0VZ71LZ1	 74	//(R0VZ71LZ1) Обобщенный сигнал по АЗ  1 канала
#define R0VZ71LZ2	 BUFFER[169]	//(R0VZ71LZ2) Обобщенный сигнал по АЗ  2 канала
#define idR0VZ71LZ2	 75	//(R0VZ71LZ2) Обобщенный сигнал по АЗ  2 канала
#define A2AD32LDU	 BUFFER[171]	//(A2AD32LDU) Обесточить ЭМ РБ1
#define idA2AD32LDU	 76	//(A2AD32LDU) Обесточить ЭМ РБ1
#define C2MD31LP1	 BUFFER[173]	//(C2MD31LP1) Кнопка «СБРОС РБ»
#define idC2MD31LP1	 77	//(C2MD31LP1) Кнопка «СБРОС РБ»
#define A2AD31LDU	 BUFFER[175]	//(A2AD31LDU) Клапан (Сброс РБ1) открыть (обесточить)
#define idA2AD31LDU	 78	//(A2AD31LDU) Клапан (Сброс РБ1) открыть (обесточить)
#define A1AD32LDU	 BUFFER[177]	//(A1AD32LDU) Обесточить ЭМ ББ1
#define idA1AD32LDU	 79	//(A1AD32LDU) Обесточить ЭМ ББ1
#define A1AD31LDU	 BUFFER[179]	//(A1AD31LDU) Клапан (Сброс ББ1) открыть (обесточить)
#define idA1AD31LDU	 80	//(A1AD31LDU) Клапан (Сброс ББ1) открыть (обесточить)
#define C1MD31LP2	 BUFFER[181]	//(C1MD31LP2) Кнопка «СБРОС ББ»  на ОПУ2
#define idC1MD31LP2	 81	//(C1MD31LP2) Кнопка «СБРОС ББ»  на ОПУ2
#define C1MD31LP1	 BUFFER[183]	//(C1MD31LP1) Кнопка «СБРОС ББ»  на ОПУ1
#define idC1MD31LP1	 82	//(C1MD31LP1) Кнопка «СБРОС ББ»  на ОПУ1
#define A3AD31LDU	 BUFFER[185]	//(A3AD31LDU) Клапан (СПУСК ИС1) открыть (обесточить)
#define idA3AD31LDU	 83	//(A3AD31LDU) Клапан (СПУСК ИС1) открыть (обесточить)
#define B1AD31LDU	 BUFFER[187]	//(B1AD31LDU) Клапан (Сброс ББ2) открыть (обесточить)
#define idB1AD31LDU	 84	//(B1AD31LDU) Клапан (Сброс ББ2) открыть (обесточить)
#define B1AD32LDU	 BUFFER[189]	//(B1AD32LDU) Обесточить ЭМ ББ2
#define idB1AD32LDU	 85	//(B1AD32LDU) Обесточить ЭМ ББ2
#define B2AD31LDU	 BUFFER[191]	//(B2AD31LDU) Клапан (Сброс РБ2) открыть (обесточить)
#define idB2AD31LDU	 86	//(B2AD31LDU) Клапан (Сброс РБ2) открыть (обесточить)
#define B2AD32LDU	 BUFFER[193]	//(B2AD32LDU) Обесточить ЭМ РБ2
#define idB2AD32LDU	 87	//(B2AD32LDU) Обесточить ЭМ РБ2
#define B3AD31LDU	 BUFFER[195]	//(B3AD31LDU) Клапан (СПУСК ИС2) открыть (обесточить)
#define idB3AD31LDU	 88	//(B3AD31LDU) Клапан (СПУСК ИС2) открыть (обесточить)
#define R0MW13LP2	 BUFFER[197]	//(R0MW13LP2) Переключатель «СЕТЬ»
#define idR0MW13LP2	 89	//(R0MW13LP2) Переключатель «СЕТЬ»
#define B9AD10LDU	 BUFFER[199]	//(B9AD10LDU) Открыть клапан (Подъем НИ ДС2)
#define idB9AD10LDU	 90	//(B9AD10LDU) Открыть клапан (Подъем НИ ДС2)
#define A9AD10LDU	 BUFFER[201]	//(A9AD10LDU) Открыть клапан (Подъем НИ ДС1)
#define idA9AD10LDU	 91	//(A9AD10LDU) Открыть клапан (Подъем НИ ДС1)
#define B4AD10LDU	 BUFFER[203]	//(B4AD10LDU) Открыть клапан (Подъем НИ2)
#define idB4AD10LDU	 92	//(B4AD10LDU) Открыть клапан (Подъем НИ2)
#define A4AD10LDU	 BUFFER[205]	//(A4AD10LDU) Открыть клапан (Подъем НИ1)
#define idA4AD10LDU	 93	//(A4AD10LDU) Открыть клапан (Подъем НИ1)
#define R0ST01RIM	 BUFFER[207]	//(R0ST01RIM) Текущий период разгона РУ
#define idR0ST01RIM	 94	//(R0ST01RIM) Текущий период разгона РУ
#define R0SR01RIM	 BUFFER[212]	//(R0SR01RIM) Текущая реактивность PУ
#define idR0SR01RIM	 95	//(R0SR01RIM) Текущая реактивность PУ
#define R7II73LZ1	 BUFFER[217]	//(R7II73LZ1) Сработала АС IIУР
#define idR7II73LZ1	 96	//(R7II73LZ1) Сработала АС IIУР
#define R7II71LZ1	 BUFFER[219]	//(R7II71LZ1) Сработала АС IУР (датчик 1)
#define idR7II71LZ1	 97	//(R7II71LZ1) Сработала АС IУР (датчик 1)
#define R7II72LZ1	 BUFFER[221]	//(R7II72LZ1) Сработала АС IУР (датчик 2)
#define idR7II72LZ1	 98	//(R7II72LZ1) Сработала АС IУР (датчик 2)
#define R0AD16LDU	 BUFFER[223]	//(R0AD16LDU) Контроль  I-II УР. РАД
#define idR0AD16LDU	 99	//(R0AD16LDU) Контроль  I-II УР. РАД
#define R7II72LZ2	 BUFFER[225]	//(R7II72LZ2) Сработала АС IУР (датчик 2)
#define idR7II72LZ2	 100	//(R7II72LZ2) Сработала АС IУР (датчик 2)
#define R7II71LZ2	 BUFFER[227]	//(R7II71LZ2) Сработала АС IУР (датчик 1)
#define idR7II71LZ2	 101	//(R7II71LZ2) Сработала АС IУР (датчик 1)
#define R7II73LZ2	 BUFFER[229]	//(R7II73LZ2) Сработала АС IIУР
#define idR7II73LZ2	 102	//(R7II73LZ2) Сработала АС IIУР
#define A3IS35LDU	 BUFFER[231]	//(A3IS35LDU) Клапан (ВПИС1) открыт(обесточен)
#define idA3IS35LDU	 103	//(A3IS35LDU) Клапан (ВПИС1) открыт(обесточен)
#define B3AD34LDU	 BUFFER[233]	//(B3AD34LDU) Клапан (ВПИС2) открыть (обесточить)
#define idB3AD34LDU	 104	//(B3AD34LDU) Клапан (ВПИС2) открыть (обесточить)
#define B3IS35LDU	 BUFFER[235]	//(B3IS35LDU) Клапан «ВПИС2» открыт(обесточен)
#define idB3IS35LDU	 105	//(B3IS35LDU) Клапан «ВПИС2» открыт(обесточен)
#define R0VN02RS1	 BUFFER[237]	//(R0VN02RS1) Уровень мощности канал1
#define idR0VN02RS1	 106	//(R0VN02RS1) Уровень мощности канал1
#define R0VN61LS1	 BUFFER[242]	//(R0VN61LS1) ПС по мощности канал1
#define idR0VN61LS1	 107	//(R0VN61LS1) ПС по мощности канал1
#define R0VN71LZ1	 BUFFER[244]	//(R0VN71LZ1) АС по мощности канал1 на БАЗ1
#define idR0VN71LZ1	 108	//(R0VN71LZ1) АС по мощности канал1 на БАЗ1
#define A0VN71LS1	 BUFFER[246]	//(A0VN71LS1) Блокировка автоматического  подъёма ББ канал 1 на БАЗ1
#define idA0VN71LS1	 109	//(A0VN71LS1) Блокировка автоматического  подъёма ББ канал 1 на БАЗ1
#define R0VN15RS1	 BUFFER[248]	//(R0VN15RS1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
#define idR0VN15RS1	 110	//(R0VN15RS1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
#define R0VN71LZ2	 BUFFER[251]	//(R0VN71LZ2) АС по мощности канал 1  на БАЗ2
#define idR0VN71LZ2	 111	//(R0VN71LZ2) АС по мощности канал 1  на БАЗ2
#define A1VN71LS1	 BUFFER[253]	//(A1VN71LS1) Блокировка автоматического  подъёма ББ канал 1 на БАЗ2
#define idA1VN71LS1	 112	//(A1VN71LS1) Блокировка автоматического  подъёма ББ канал 1 на БАЗ2
#define R0VN01RS1	 BUFFER[255]	//(R0VN01RS1) Период разгона канал1
#define idR0VN01RS1	 113	//(R0VN01RS1) Период разгона канал1
#define R0VN65LS1	 BUFFER[260]	//(R0VN65LS1) ПС по периоду разгона канал1
#define idR0VN65LS1	 114	//(R0VN65LS1) ПС по периоду разгона канал1
#define R0VN75LZ1	 BUFFER[262]	//(R0VN75LZ1) АС по периоду разгонана БАЗ1
#define idR0VN75LZ1	 115	//(R0VN75LZ1) АС по периоду разгонана БАЗ1
#define A0EE01LS1	 BUFFER[264]	//(A0EE01LS1) Исправность АКНП канал1 на БАЗ1
#define idA0EE01LS1	 116	//(A0EE01LS1) Исправность АКНП канал1 на БАЗ1
#define R0VN75LZ2	 BUFFER[266]	//(R0VN75LZ2) АС по периоду разгонана БАЗ2
#define idR0VN75LZ2	 117	//(R0VN75LZ2) АС по периоду разгонана БАЗ2
#define A1EE01LS1	 BUFFER[268]	//(A1EE01LS1) Исправность АКНП на БАЗ2
#define idA1EE01LS1	 118	//(A1EE01LS1) Исправность АКНП на БАЗ2
#define R0IE11LS1	 BUFFER[270]	//(R0IE11LS1) Исправность ВИП 1,6 (№8) СНМ11 1канала
#define idR0IE11LS1	 119	//(R0IE11LS1) Исправность ВИП 1,6 (№8) СНМ11 1канала
#define R0IE12LS1	 BUFFER[272]	//(R0IE12LS1) Исправность ВИП 0,5 (№9) КНК15-1 1канала
#define idR0IE12LS1	 120	//(R0IE12LS1) Исправность ВИП 0,5 (№9) КНК15-1 1канала
#define R0IE13LS1	 BUFFER[274]	//(R0IE13LS1) Исправность ВИП 0,5 (№10) КНК53М 1канала
#define idR0IE13LS1	 121	//(R0IE13LS1) Исправность ВИП 0,5 (№10) КНК53М 1канала
#define R0VN02RS2	 BUFFER[276]	//(R0VN02RS2) Уровень мощности канал 2
#define idR0VN02RS2	 122	//(R0VN02RS2) Уровень мощности канал 2
#define R0VN61LS2	 BUFFER[281]	//(R0VN61LS2) ПС по мощности канал 2
#define idR0VN61LS2	 123	//(R0VN61LS2) ПС по мощности канал 2
#define R0VN72LZ1	 BUFFER[283]	//(R0VN72LZ1) АС по мощности канал 2 на БАЗ1
#define idR0VN72LZ1	 124	//(R0VN72LZ1) АС по мощности канал 2 на БАЗ1
#define A1VN71LS2	 BUFFER[285]	//(A1VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ2
#define idA1VN71LS2	 125	//(A1VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ2
#define R0VN15RS2	 BUFFER[287]	//(R0VN15RS2) Номер ведущей камеры канал 2
#define idR0VN15RS2	 126	//(R0VN15RS2) Номер ведущей камеры канал 2
#define R0VN72LZ2	 BUFFER[290]	//(R0VN72LZ2) АС по мощности канал 2 на БАЗ2
#define idR0VN72LZ2	 127	//(R0VN72LZ2) АС по мощности канал 2 на БАЗ2
#define A0VN71LS2	 BUFFER[292]	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ1
#define idA0VN71LS2	 128	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ1
#define R0VN01RS2	 BUFFER[294]	//(R0VN01RS2) Период разгона канал 2
#define idR0VN01RS2	 129	//(R0VN01RS2) Период разгона канал 2
#define R0VN65LS2	 BUFFER[299]	//(R0VN65LS2) ПС по периоду разгона канал 2
#define idR0VN65LS2	 130	//(R0VN65LS2) ПС по периоду разгона канал 2
#define R0VN76LZ1	 BUFFER[301]	//(R0VN76LZ1) АС по периоду разгона канал 2  на БАЗ1
#define idR0VN76LZ1	 131	//(R0VN76LZ1) АС по периоду разгона канал 2  на БАЗ1
#define A0EE01LS2	 BUFFER[303]	//(A0EE01LS2) Исправность АКНП канал 2 на БАЗ1
#define idA0EE01LS2	 132	//(A0EE01LS2) Исправность АКНП канал 2 на БАЗ1
#define R0VN76LZ2	 BUFFER[305]	//(R0VN76LZ2) АС по периоду разгона канал 2  на БАЗ2
#define idR0VN76LZ2	 133	//(R0VN76LZ2) АС по периоду разгона канал 2  на БАЗ2
#define A1EE01LS2	 BUFFER[307]	//(A1EE01LS2) Исправность АКНП канал 2 на БАЗ2
#define idA1EE01LS2	 134	//(A1EE01LS2) Исправность АКНП канал 2 на БАЗ2
#define R0IE12LS2	 BUFFER[309]	//(R0IE12LS2) Исправность ВИП 0,5 (№12) КНК15-1 2канала
#define idR0IE12LS2	 135	//(R0IE12LS2) Исправность ВИП 0,5 (№12) КНК15-1 2канала
#define R0IE13LS2	 BUFFER[311]	//(R0IE13LS2) Исправность ВИП 0,5 (№13) КНК53М 2канала
#define idR0IE13LS2	 136	//(R0IE13LS2) Исправность ВИП 0,5 (№13) КНК53М 2канала
#define R0IE11LS2	 BUFFER[313]	//(R0IE11LS2) Исправность ВИП 1,6 (№11) СНМ11 2канала
#define idR0IE11LS2	 137	//(R0IE11LS2) Исправность ВИП 1,6 (№11) СНМ11 2канала
#define R0VN02RS3	 BUFFER[315]	//(R0VN02RS3) Уровень мощности канал 3
#define idR0VN02RS3	 138	//(R0VN02RS3) Уровень мощности канал 3
#define R0VN61LS3	 BUFFER[320]	//(R0VN61LS3) ПС по мощности канал 3
#define idR0VN61LS3	 139	//(R0VN61LS3) ПС по мощности канал 3
#define R0VN73LZ1	 BUFFER[322]	//(R0VN73LZ1) АС по мощности канал 3 на БАЗ1
#define idR0VN73LZ1	 140	//(R0VN73LZ1) АС по мощности канал 3 на БАЗ1
#define A1VN71LS3	 BUFFER[324]	//(A1VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
#define idA1VN71LS3	 141	//(A1VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
#define R0VN15RS3	 BUFFER[326]	//(R0VN15RS3) Номер ведущей камеры канал 3
#define idR0VN15RS3	 142	//(R0VN15RS3) Номер ведущей камеры канал 3
#define A0VN71LS3	 BUFFER[329]	//(A0VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
#define idA0VN71LS3	 143	//(A0VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
#define R0VN73LZ2	 BUFFER[331]	//(R0VN73LZ2) АС по мощности канал 3 на БАЗ2
#define idR0VN73LZ2	 144	//(R0VN73LZ2) АС по мощности канал 3 на БАЗ2
#define R0VN01RS3	 BUFFER[333]	//(R0VN01RS3) Период разгона канал 3
#define idR0VN01RS3	 145	//(R0VN01RS3) Период разгона канал 3
#define R0VN65LS3	 BUFFER[338]	//(R0VN65LS3) ПС по периоду разгона канал 3
#define idR0VN65LS3	 146	//(R0VN65LS3) ПС по периоду разгона канал 3
#define R0VN77LZ1	 BUFFER[340]	//(R0VN77LZ1) АС по периоду разгона канал 3 на БАЗ1
#define idR0VN77LZ1	 147	//(R0VN77LZ1) АС по периоду разгона канал 3 на БАЗ1
#define A0EE01LS3	 BUFFER[342]	//(A0EE01LS3) Исправность АКНП канал 3 на БАЗ1
#define idA0EE01LS3	 148	//(A0EE01LS3) Исправность АКНП канал 3 на БАЗ1
#define R0VN77LZ2	 BUFFER[344]	//(R0VN77LZ2) АС по периоду разгона канал 3 на БАЗ2
#define idR0VN77LZ2	 149	//(R0VN77LZ2) АС по периоду разгона канал 3 на БАЗ2
#define A1EE01LS3	 BUFFER[346]	//(A1EE01LS3) Исправность АКНП канал 3 на БАЗ2
#define idA1EE01LS3	 150	//(A1EE01LS3) Исправность АКНП канал 3 на БАЗ2
#define R0IE12LS3	 BUFFER[348]	//(R0IE12LS3) Исправность ВИП 0,5 (№15) КНК15-1 3канала
#define idR0IE12LS3	 151	//(R0IE12LS3) Исправность ВИП 0,5 (№15) КНК15-1 3канала
#define R0IE13LS3	 BUFFER[350]	//(R0IE13LS3) Исправность ВИП 0,5 (№16) КНК53М 3канала
#define idR0IE13LS3	 152	//(R0IE13LS3) Исправность ВИП 0,5 (№16) КНК53М 3канала
#define R0IE11LS3	 BUFFER[352]	//(R0IE11LS3) Исправность ВИП 1,6 (№14) СНМ11 3канала
#define idR0IE11LS3	 153	//(R0IE11LS3) Исправность ВИП 1,6 (№14) СНМ11 3канала
#define R0VN02RS4	 BUFFER[354]	//(R0VN02RS4) Уровень мощности канал 4
#define idR0VN02RS4	 154	//(R0VN02RS4) Уровень мощности канал 4
#define R0VN61LS4	 BUFFER[359]	//(R0VN61LS4) ПС по мощности канал 4
#define idR0VN61LS4	 155	//(R0VN61LS4) ПС по мощности канал 4
#define R0VN74LZ1	 BUFFER[361]	//(R0VN74LZ1) АС по мощности канал 4 на БАЗ1
#define idR0VN74LZ1	 156	//(R0VN74LZ1) АС по мощности канал 4 на БАЗ1
#define A1VN71LS4	 BUFFER[363]	//(A1VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
#define idA1VN71LS4	 157	//(A1VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
#define R0VN15RS4	 BUFFER[365]	//(R0VN15RS4) Номер ведущей камеры канал 4
#define idR0VN15RS4	 158	//(R0VN15RS4) Номер ведущей камеры канал 4
#define A0VN71LS4	 BUFFER[368]	//(A0VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
#define idA0VN71LS4	 159	//(A0VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
#define R0VN74LZ2	 BUFFER[370]	//(R0VN74LZ2) АС по мощности канал 4 на БАЗ2
#define idR0VN74LZ2	 160	//(R0VN74LZ2) АС по мощности канал 4 на БАЗ2
#define R0VN01RS4	 BUFFER[372]	//(R0VN01RS4) Период разгона канал 4
#define idR0VN01RS4	 161	//(R0VN01RS4) Период разгона канал 4
#define R0VN65LS4	 BUFFER[377]	//(R0VN65LS4) ПС по периоду разгона канал 4
#define idR0VN65LS4	 162	//(R0VN65LS4) ПС по периоду разгона канал 4
#define R0VN78LZ1	 BUFFER[379]	//(R0VN78LZ1) АС по периоду разгона канал 4 на БАЗ1
#define idR0VN78LZ1	 163	//(R0VN78LZ1) АС по периоду разгона канал 4 на БАЗ1
#define A0EE01LS4	 BUFFER[381]	//(A0EE01LS4) Исправность АКНП канал 4 на БАЗ1
#define idA0EE01LS4	 164	//(A0EE01LS4) Исправность АКНП канал 4 на БАЗ1
#define R0VN78LZ2	 BUFFER[383]	//(R0VN78LZ2) АС по периоду разгона канал 4 на БАЗ2
#define idR0VN78LZ2	 165	//(R0VN78LZ2) АС по периоду разгона канал 4 на БАЗ2
#define A1EE01LS4	 BUFFER[385]	//(A1EE01LS4) Исправность АКНП канал 4 на БАЗ2
#define idA1EE01LS4	 166	//(A1EE01LS4) Исправность АКНП канал 4 на БАЗ2
#define R0IE12LS4	 BUFFER[387]	//(R0IE12LS4) Исправность ВИП 0,5 (№18) КНК15-1 4канала
#define idR0IE12LS4	 167	//(R0IE12LS4) Исправность ВИП 0,5 (№18) КНК15-1 4канала
#define R0IE13LS4	 BUFFER[389]	//(R0IE13LS4) Исправность ВИП 0,5 (№19) КНК53М 4канала
#define idR0IE13LS4	 168	//(R0IE13LS4) Исправность ВИП 0,5 (№19) КНК53М 4канала
#define R0IE11LS4	 BUFFER[391]	//(R0IE11LS4) Исправность ВИП 1,6 (№17) СНМ11 4канала
#define idR0IE11LS4	 169	//(R0IE11LS4) Исправность ВИП 1,6 (№17) СНМ11 4канала
#define A7AS31LDU	 BUFFER[393]	//(A7AS31LDU) Клапан (Обдув АЗ1) открыт (обесточен)
#define idA7AS31LDU	 170	//(A7AS31LDU) Клапан (Обдув АЗ1) открыт (обесточен)
#define B7AS31LDU	 BUFFER[395]	//(B7AS31LDU) Клапан (Обдув АЗ2) открыт (обесточен)
#define idB7AS31LDU	 171	//(B7AS31LDU) Клапан (Обдув АЗ2) открыт (обесточен)
#define R6IS21LDU	 BUFFER[397]	//(R6IS21LDU) Кран-балка в нерабочем положении
#define idR6IS21LDU	 172	//(R6IS21LDU) Кран-балка в нерабочем положении
#define A0IT01IZ1	 BUFFER[399]	//(A0IT01IZ1) Температура АЗ1-1
#define idA0IT01IZ1	 173	//(A0IT01IZ1) Температура АЗ1-1
#define A0IT02IZ2	 BUFFER[402]	//(A0IT02IZ2) Температура АЗ1-2
#define idA0IT02IZ2	 174	//(A0IT02IZ2) Температура АЗ1-2
#define B0IT01IZ1	 BUFFER[405]	//(B0IT01IZ1) Температура АЗ2-1
#define idB0IT01IZ1	 175	//(B0IT01IZ1) Температура АЗ2-1
#define B0IT02IZ2	 BUFFER[408]	//(B0IT02IZ2) Температура АЗ2-2
#define idB0IT02IZ2	 176	//(B0IT02IZ2) Температура АЗ2-2
#define A2IS21LDU	 BUFFER[411]	//(A2IS21LDU) Приход на НУ РБ1
#define idA2IS21LDU	 177	//(A2IS21LDU) Приход на НУ РБ1
#define A2IS11LDU	 BUFFER[413]	//(A2IS11LDU) Приход на ВУ РБ1
#define idA2IS11LDU	 178	//(A2IS11LDU) Приход на ВУ РБ1
#define A2IS12LDU	 BUFFER[415]	//(A2IS12LDU) Магнит РБ1 зацеплен
#define idA2IS12LDU	 179	//(A2IS12LDU) Магнит РБ1 зацеплен
#define A2IC01UDU	 BUFFER[417]	//(A2IC01UDU) Координата штока РБ1
#define idA2IC01UDU	 180	//(A2IC01UDU) Координата штока РБ1
#define A2IS33LDU	 BUFFER[422]	//(A2IS33LDU) Клапан (Подъём РБ1)  открыт (обесточен)
#define idA2IS33LDU	 181	//(A2IS33LDU) Клапан (Подъём РБ1)  открыт (обесточен)
#define A3IS21LDU	 BUFFER[424]	//(A3IS21LDU) Приход на НУ ИС1
#define idA3IS21LDU	 182	//(A3IS21LDU) Приход на НУ ИС1
#define B3IS21LDU	 BUFFER[426]	//(B3IS21LDU) Приход на НУ ИС2
#define idB3IS21LDU	 183	//(B3IS21LDU) Приход на НУ ИС2
#define A2IP01IZ1	 BUFFER[428]	//(A2IP01IZ1) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	 184	//(A2IP01IZ1) Текущее давление СБРОС РБ1
#define A2IP01IZ2	 BUFFER[431]	//(A2IP01IZ2) Текущее давление СБРОС РБ1
#define idA2IP01IZ2	 185	//(A2IP01IZ2) Текущее давление СБРОС РБ1
#define A2VP82LDU	 BUFFER[434]	//(A2VP82LDU) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 186	//(A2VP82LDU) Давление ПОДЪЁМ РБ1 в норме
#define A3IS31LDU	 BUFFER[436]	//(A3IS31LDU) Клапан (СПУСК ИС1)  открыт (обесточен)
#define idA3IS31LDU	 187	//(A3IS31LDU) Клапан (СПУСК ИС1)  открыт (обесточен)
#define A3IC01UDU	 BUFFER[438]	//(A3IC01UDU) Координата штока ИС1
#define idA3IC01UDU	 188	//(A3IC01UDU) Координата штока ИС1
#define A3IS33LDU	 BUFFER[443]	//(A3IS33LDU) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define idA3IS33LDU	 189	//(A3IS33LDU) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define B3IP02IDU	 BUFFER[445]	//(B3IP02IDU) Текущее давление ВЫСТРЕЛ  ИС2
#define idB3IP02IDU	 190	//(B3IP02IDU) Текущее давление ВЫСТРЕЛ  ИС2
#define B3IS31LDU	 BUFFER[448]	//(B3IS31LDU) Клапан (СПУСК ИС2)  открыт (обесточен)
#define idB3IS31LDU	 191	//(B3IS31LDU) Клапан (СПУСК ИС2)  открыт (обесточен)
#define B3IC01UDU	 BUFFER[450]	//(B3IC01UDU) Координата штока ИС2
#define idB3IC01UDU	 192	//(B3IC01UDU) Координата штока ИС2
#define B3IS33LDU	 BUFFER[455]	//(B3IS33LDU) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idB3IS33LDU	 193	//(B3IS33LDU) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define A3VP81LDU	 BUFFER[457]	//(A3VP81LDU) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 194	//(A3VP81LDU) Давление СПУСК ИС1 в норме
#define B3VP81LDU	 BUFFER[459]	//(B3VP81LDU) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 195	//(B3VP81LDU) Давление СПУСК ИС2 в норме
#define A3IP02IDU	 BUFFER[461]	//(A3IP02IDU) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 196	//(A3IP02IDU) Текущее давление ВЫСТРЕЛ ИС1
#define A3IS11LDU	 BUFFER[464]	//(A3IS11LDU) Приход на ВУ ИС1
#define idA3IS11LDU	 197	//(A3IS11LDU) Приход на ВУ ИС1
#define B3IS11LDU	 BUFFER[466]	//(B3IS11LDU) Приход на ВУ ИС2
#define idB3IS11LDU	 198	//(B3IS11LDU) Приход на ВУ ИС2
#define A3IS22LDU	 BUFFER[468]	//(A3IS22LDU) Приход на НУП ИС1
#define idA3IS22LDU	 199	//(A3IS22LDU) Приход на НУП ИС1
#define B3IS22LDU	 BUFFER[470]	//(B3IS22LDU) Приход на НУП ИС2
#define idB3IS22LDU	 200	//(B3IS22LDU) Приход на НУП ИС2
#define R6IS62LDU	 BUFFER[472]	//(R6IS62LDU) Исправность ВИП ССДИ-39 1канал
#define idR6IS62LDU	 201	//(R6IS62LDU) Исправность ВИП ССДИ-39 1канал
#define R6IS63LDU	 BUFFER[474]	//(R6IS63LDU) Исправность ВИП ССДИ-39 2канал
#define idR6IS63LDU	 202	//(R6IS63LDU) Исправность ВИП ССДИ-39 2канал
#define R6IS64LDU	 BUFFER[476]	//(R6IS64LDU) Исправность ВИП ССДИ-35 1канал
#define idR6IS64LDU	 203	//(R6IS64LDU) Исправность ВИП ССДИ-35 1канал
#define R6IS65LDU	 BUFFER[478]	//(R6IS65LDU) Исправность ВИП ССДИ-35 2канал
#define idR6IS65LDU	 204	//(R6IS65LDU) Исправность ВИП ССДИ-35 2канал
#define R6IS66LZZ	 BUFFER[480]	//(R6IS66LZZ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 205	//(R6IS66LZZ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	 BUFFER[482]	//(R6IS67LZZ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 206	//(R6IS67LZZ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	 BUFFER[484]	//(R6IS68LZZ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 207	//(R6IS68LZZ) Исправность ВИП 4,0 (№7) ССДИ-2
#define A8IC01UDU	 BUFFER[486]	//(A8IC01UDU) Координата ДС2
#define idA8IC01UDU	 208	//(A8IC01UDU) Координата ДС2
#define B8IC01UDU	 BUFFER[491]	//(B8IC01UDU) Координата АЗ2
#define idB8IC01UDU	 209	//(B8IC01UDU) Координата АЗ2
#define A0VP81LZZ	 BUFFER[496]	//(A0VP81LZZ) Давление АЗ1 в норме
#define idA0VP81LZZ	 210	//(A0VP81LZZ) Давление АЗ1 в норме
#define B0VP81LZZ	 BUFFER[498]	//(B0VP81LZZ) Давление АЗ2 в норме
#define idB0VP81LZZ	 211	//(B0VP81LZZ) Давление АЗ2 в норме
#define A5IS11LDU	 BUFFER[500]	//(A5IS11LDU) Приход на ВУ НЛ1
#define idA5IS11LDU	 212	//(A5IS11LDU) Приход на ВУ НЛ1
#define A5IS21LDU	 BUFFER[502]	//(A5IS21LDU) Приход на НУ НЛ1
#define idA5IS21LDU	 213	//(A5IS21LDU) Приход на НУ НЛ1
#define B5IS11LDU	 BUFFER[504]	//(B5IS11LDU) Приход на ВУ НЛ2
#define idB5IS11LDU	 214	//(B5IS11LDU) Приход на ВУ НЛ2
#define B5IS21LDU	 BUFFER[506]	//(B5IS21LDU) Приход на НУ НЛ2
#define idB5IS21LDU	 215	//(B5IS21LDU) Приход на НУ НЛ2
#define A9IS11LDU	 BUFFER[508]	//(A9IS11LDU) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 216	//(A9IS11LDU) Приход на ВУ НИ ДС1
#define A9IS21LDU	 BUFFER[510]	//(A9IS21LDU) Приход на НУ НИ ДС1
#define idA9IS21LDU	 217	//(A9IS21LDU) Приход на НУ НИ ДС1
#define B9IS11LDU	 BUFFER[512]	//(B9IS11LDU) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 218	//(B9IS11LDU) Приход на ВУ НИ ДС2
#define B9IS21LDU	 BUFFER[514]	//(B9IS21LDU) Приход на НУ НИ ДС2
#define idB9IS21LDU	 219	//(B9IS21LDU) Приход на НУ НИ ДС2
#define B2IS21LDU	 BUFFER[516]	//(B2IS21LDU) Приход на НУ РБ2
#define idB2IS21LDU	 220	//(B2IS21LDU) Приход на НУ РБ2
#define B2IS11LDU	 BUFFER[518]	//(B2IS11LDU) Приход на ВУ РБ2
#define idB2IS11LDU	 221	//(B2IS11LDU) Приход на ВУ РБ2
#define B2IS12LDU	 BUFFER[520]	//(B2IS12LDU) Магнит РБ2 зацеплен
#define idB2IS12LDU	 222	//(B2IS12LDU) Магнит РБ2 зацеплен
#define B2IC01UDU	 BUFFER[522]	//(B2IC01UDU) Координата штока РБ2
#define idB2IC01UDU	 223	//(B2IC01UDU) Координата штока РБ2
#define B2IP01IZ1	 BUFFER[527]	//(B2IP01IZ1) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	 224	//(B2IP01IZ1) Текущее давление СБРОС РБ2
#define B2IP01IZ2	 BUFFER[530]	//(B2IP01IZ2) Текущее давление СБРОС РБ2
#define idB2IP01IZ2	 225	//(B2IP01IZ2) Текущее давление СБРОС РБ2
#define B2VP82LDU	 BUFFER[533]	//(B2VP82LDU) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 226	//(B2VP82LDU) Давление ПОДЪЁМ РБ2 в норме
#define R3IS11LDU	 BUFFER[535]	//(R3IS11LDU) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	 227	//(R3IS11LDU) Приход на ВУ гомогенных дверей
#define R3IS21LDU	 BUFFER[537]	//(R3IS21LDU) Приход на НУ гомогенных дверей
#define idR3IS21LDU	 228	//(R3IS21LDU) Приход на НУ гомогенных дверей
#define R5IS11LDU	 BUFFER[539]	//(R5IS11LDU) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 229	//(R5IS11LDU) Приход на ВУ ворот отстойной зоны
#define R5IS21LDU	 BUFFER[541]	//(R5IS21LDU) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 230	//(R5IS21LDU) Приход на НУ ворот отстойной зоны
#define A4IS11LDU	 BUFFER[543]	//(A4IS11LDU) Приход на ВУ НИ1
#define idA4IS11LDU	 231	//(A4IS11LDU) Приход на ВУ НИ1
#define A4IS21LDU	 BUFFER[545]	//(A4IS21LDU) Приход на НУ НИ1
#define idA4IS21LDU	 232	//(A4IS21LDU) Приход на НУ НИ1
#define R8IS11LDU	 BUFFER[547]	//(R8IS11LDU) Аварийный НИ установлен
#define idR8IS11LDU	 233	//(R8IS11LDU) Аварийный НИ установлен
#define B4IS11LDU	 BUFFER[549]	//(B4IS11LDU) Приход на ВУ НИ2
#define idB4IS11LDU	 234	//(B4IS11LDU) Приход на ВУ НИ2
#define B4IS21LDU	 BUFFER[551]	//(B4IS21LDU) Приход на НУ НИ2
#define idB4IS21LDU	 235	//(B4IS21LDU) Приход на НУ НИ2
#define R1IS11LDU	 BUFFER[553]	//(R1IS11LDU) Приход на ВУ МДЗ1
#define idR1IS11LDU	 236	//(R1IS11LDU) Приход на ВУ МДЗ1
#define R1IS21LDU	 BUFFER[555]	//(R1IS21LDU) Приход на НУ МДЗ1
#define idR1IS21LDU	 237	//(R1IS21LDU) Приход на НУ МДЗ1
#define R2IS11LDU	 BUFFER[557]	//(R2IS11LDU) Приход на ВУ МДЗ2
#define idR2IS11LDU	 238	//(R2IS11LDU) Приход на ВУ МДЗ2
#define R2IS21LDU	 BUFFER[559]	//(R2IS21LDU) Приход на НУ МДЗ2
#define idR2IS21LDU	 239	//(R2IS21LDU) Приход на НУ МДЗ2
#define A4VP82LDU	 BUFFER[561]	//(A4VP82LDU) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 240	//(A4VP82LDU) Давление ПОДЪЁМ НИ1 в норме
#define B4VP82LDU	 BUFFER[563]	//(B4VP82LDU) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 241	//(B4VP82LDU) Давление ПОДЪЁМ НИ2 в норме
#define R4IS11LDU	 BUFFER[565]	//(R4IS11LDU) Приход на ВУ1 тележки
#define idR4IS11LDU	 242	//(R4IS11LDU) Приход на ВУ1 тележки
#define R4IS21LDU	 BUFFER[567]	//(R4IS21LDU) Приход на НУ1 тележки
#define idR4IS21LDU	 243	//(R4IS21LDU) Приход на НУ1 тележки
#define R4IS22LDU	 BUFFER[569]	//(R4IS22LDU) Приход на НУ2 тележки
#define idR4IS22LDU	 244	//(R4IS22LDU) Приход на НУ2 тележки
#define R4IS12LDU	 BUFFER[571]	//(R4IS12LDU) Приход на  ВУ2 тележки
#define idR4IS12LDU	 245	//(R4IS12LDU) Приход на  ВУ2 тележки
#define B8IS22LDU	 BUFFER[573]	//(B8IS22LDU) Приход на НУ2 АЗ2
#define idB8IS22LDU	 246	//(B8IS22LDU) Приход на НУ2 АЗ2
#define B8IS12LDU	 BUFFER[575]	//(B8IS12LDU) Приход на ВУ2 АЗ2
#define idB8IS12LDU	 247	//(B8IS12LDU) Приход на ВУ2 АЗ2
#define A8IS22LDU	 BUFFER[577]	//(A8IS22LDU) Приход на механический НУ ДС2
#define idA8IS22LDU	 248	//(A8IS22LDU) Приход на механический НУ ДС2
#define A8IS12LDU	 BUFFER[579]	//(A8IS12LDU) Приход на механический ВУ ДС2
#define idA8IS12LDU	 249	//(A8IS12LDU) Приход на механический ВУ ДС2
#define A6IS11LDU	 BUFFER[581]	//(A6IS11LDU) Приход на ВУ БЗ1
#define idA6IS11LDU	 250	//(A6IS11LDU) Приход на ВУ БЗ1
#define A6IS21LDU	 BUFFER[583]	//(A6IS21LDU) Приход на НУ БЗ1
#define idA6IS21LDU	 251	//(A6IS21LDU) Приход на НУ БЗ1
#define B6IS11LDU	 BUFFER[585]	//(B6IS11LDU) Приход на ВУ БЗ2
#define idB6IS11LDU	 252	//(B6IS11LDU) Приход на ВУ БЗ2
#define B6IS21LDU	 BUFFER[587]	//(B6IS21LDU) Приход на НУ БЗ2
#define idB6IS21LDU	 253	//(B6IS21LDU) Приход на НУ БЗ2
#define A1IS21LDU	 BUFFER[589]	//(A1IS21LDU) Приход на НУ ББ1
#define idA1IS21LDU	 254	//(A1IS21LDU) Приход на НУ ББ1
#define A1IS11LDU	 BUFFER[591]	//(A1IS11LDU) Приход на ВУ ББ1
#define idA1IS11LDU	 255	//(A1IS11LDU) Приход на ВУ ББ1
#define A1IS12LDU	 BUFFER[593]	//(A1IS12LDU) Магнит ББ1 зацеплен
#define idA1IS12LDU	 256	//(A1IS12LDU) Магнит ББ1 зацеплен
#define A1IC01UDU	 BUFFER[595]	//(A1IC01UDU) Координата штока ББ1
#define idA1IC01UDU	 257	//(A1IC01UDU) Координата штока ББ1
#define B1IC01UDU	 BUFFER[600]	//(B1IC01UDU) Координата штока ББ2
#define idB1IC01UDU	 258	//(B1IC01UDU) Координата штока ББ2
#define B1IS21LDU	 BUFFER[605]	//(B1IS21LDU) Приход на НУ ББ2
#define idB1IS21LDU	 259	//(B1IS21LDU) Приход на НУ ББ2
#define B1IS11LDU	 BUFFER[607]	//(B1IS11LDU) Приход на ВУ ББ2
#define idB1IS11LDU	 260	//(B1IS11LDU) Приход на ВУ ББ2
#define B1IS12LDU	 BUFFER[609]	//(B1IS12LDU) Магнит ББ2 зацеплен
#define idB1IS12LDU	 261	//(B1IS12LDU) Магнит ББ2 зацеплен
#define A1IE03LDU	 BUFFER[611]	//(A1IE03LDU) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 262	//(A1IE03LDU) Движение ББ1 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[613]	//(A1IE04LDU) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 263	//(A1IE04LDU) Движение ББ1 назад (от БУШД)
#define B1IE03LDU	 BUFFER[615]	//(B1IE03LDU) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 264	//(B1IE03LDU) Движение ББ2 вперед (от БУШД)
#define B1IE04LDU	 BUFFER[617]	//(B1IE04LDU) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 265	//(B1IE04LDU) Движение ББ2 назад (от БУШД)
#define A4IS10LDU	 BUFFER[619]	//(A4IS10LDU) Клапан (Подъём НИ1) открыт (обесточен)
#define idA4IS10LDU	 266	//(A4IS10LDU) Клапан (Подъём НИ1) открыт (обесточен)
#define B4IS10LDU	 BUFFER[621]	//(B4IS10LDU) Клапан (Подъём НИ2) открыт (обесточен)
#define idB4IS10LDU	 267	//(B4IS10LDU) Клапан (Подъём НИ2) открыт (обесточен)
#define R0EE01LZ1	 BUFFER[623]	//(R0EE01LZ1) Питание  АКНП1  отключить
#define idR0EE01LZ1	 268	//(R0EE01LZ1) Питание  АКНП1  отключить
#define R0EE01LZ2	 BUFFER[625]	//(R0EE01LZ2) Питание  АКНП1  отключить
#define idR0EE01LZ2	 269	//(R0EE01LZ2) Питание  АКНП1  отключить
#define R0EE02LZ1	 BUFFER[627]	//(R0EE02LZ1) Питание  АКНП  отключить
#define idR0EE02LZ1	 270	//(R0EE02LZ1) Питание  АКНП  отключить
#define R0EE03LZ1	 BUFFER[629]	//(R0EE03LZ1) Питание  АКНП3  отключить
#define idR0EE03LZ1	 271	//(R0EE03LZ1) Питание  АКНП3  отключить
#define R0EE04LZ1	 BUFFER[631]	//(R0EE04LZ1) Питание  АКНП4  отключить
#define idR0EE04LZ1	 272	//(R0EE04LZ1) Питание  АКНП4  отключить
#define R0EE02LZ2	 BUFFER[633]	//(R0EE02LZ2) Питание  АКНП  отключить
#define idR0EE02LZ2	 273	//(R0EE02LZ2) Питание  АКНП  отключить
#define R0EE03LZ2	 BUFFER[635]	//(R0EE03LZ2) Питание  АКНП3  отключить
#define idR0EE03LZ2	 274	//(R0EE03LZ2) Питание  АКНП3  отключить
#define R0EE04LZ2	 BUFFER[637]	//(R0EE04LZ2) Питание  АКНП4  отключить
#define idR0EE04LZ2	 275	//(R0EE04LZ2) Питание  АКНП4  отключить
#define R0IS02LDU	 BUFFER[639]	//(R0IS02LDU) Разрешение ввода от имитатора
#define idR0IS02LDU	 276	//(R0IS02LDU) Разрешение ввода от имитатора
#define A3AD34LDU	 BUFFER[641]	//(A3AD34LDU) Клапан (ВПИС ИС1) открыть (обесточить)
#define idA3AD34LDU	 277	//(A3AD34LDU) Клапан (ВПИС ИС1) открыть (обесточить)
#define A1IS11LIM	 BUFFER[643]	//(A1IS11LIM) Магнит ББ1 обесточен
#define idA1IS11LIM	 278	//(A1IS11LIM) Магнит ББ1 обесточен
#define A1IS32LIM	 BUFFER[645]	//(A1IS32LIM) Клапан cброса ББ1 открыт(обесточен)
#define idA1IS32LIM	 279	//(A1IS32LIM) Клапан cброса ББ1 открыт(обесточен)
#define B1IS11LIM	 BUFFER[647]	//(B1IS11LIM) Магнит ББ2 обесточен
#define idB1IS11LIM	 280	//(B1IS11LIM) Магнит ББ2 обесточен
#define B1IS32LIM	 BUFFER[649]	//(B1IS32LIM) Клапан cброса ББ2 открыт(обесточен)
#define idB1IS32LIM	 281	//(B1IS32LIM) Клапан cброса ББ2 открыт(обесточен)
#define A2IS11LIM	 BUFFER[651]	//(A2IS11LIM) Магнит РБ1 обесточен
#define idA2IS11LIM	 282	//(A2IS11LIM) Магнит РБ1 обесточен
#define A2IS32LIM	 BUFFER[653]	//(A2IS32LIM) Клапан cброса РБ1 открыт(обесточен)
#define idA2IS32LIM	 283	//(A2IS32LIM) Клапан cброса РБ1 открыт(обесточен)
#define B2IS11LIM	 BUFFER[655]	//(B2IS11LIM) Магнит РБ2 обесточен
#define idB2IS11LIM	 284	//(B2IS11LIM) Магнит РБ2 обесточен
#define B2IS32LIM	 BUFFER[657]	//(B2IS32LIM) Клапан cброса РБ2 открыт(обесточен)
#define idB2IS32LIM	 285	//(B2IS32LIM) Клапан cброса РБ2 открыт(обесточен)
#define A0VN01RIM	 BUFFER[659]	//(A0VN01RIM) Период разгона  AЗ1
#define idA0VN01RIM	 286	//(A0VN01RIM) Период разгона  AЗ1
#define B2IS33LDU	 BUFFER[664]	//(B2IS33LDU) Клапан (Подъём РБ2)  открыт (обесточен)
#define idB2IS33LDU	 287	//(B2IS33LDU) Клапан (Подъём РБ2)  открыт (обесточен)
#define B1VP81LZZ	 BUFFER[666]	//(B1VP81LZZ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	 288	//(B1VP81LZZ) Давление СБРОС ББ2 в норме
#define A1VP81LZZ	 BUFFER[668]	//(A1VP81LZZ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	 289	//(A1VP81LZZ) Давление СБРОС ББ1 в норме
#define B8IS11LDU	 BUFFER[670]	//(B8IS11LDU) Приход на ВУ1 АЗ2
#define idB8IS11LDU	 290	//(B8IS11LDU) Приход на ВУ1 АЗ2
#define B8IS21LDU	 BUFFER[672]	//(B8IS21LDU) Приход на НУ1 АЗ2
#define idB8IS21LDU	 291	//(B8IS21LDU) Приход на НУ1 АЗ2
#define A6VS22LDU	 BUFFER[674]	//(A6VS22LDU) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	 292	//(A6VS22LDU) Движение створок БЗ1  к ЗАКРЫТА
#define A6VS12LDU	 BUFFER[676]	//(A6VS12LDU) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	 293	//(A6VS12LDU) Движение створок БЗ1  к  ОТКРЫТА
#define B6VS22LDU	 BUFFER[678]	//(B6VS22LDU) Движение створок БЗ2  к ЗАКРЫТА
#define idB6VS22LDU	 294	//(B6VS22LDU) Движение створок БЗ2  к ЗАКРЫТА
#define B6VS12LDU	 BUFFER[680]	//(B6VS12LDU) Движение створок БЗ2  к ОТКРЫТА
#define idB6VS12LDU	 295	//(B6VS12LDU) Движение створок БЗ2  к ОТКРЫТА
#define A5VS22LDU	 BUFFER[682]	//(A5VS22LDU) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 296	//(A5VS22LDU) Движение НЛ1 в сторону НУ
#define A5VS12LDU	 BUFFER[684]	//(A5VS12LDU) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 297	//(A5VS12LDU) Движение НЛ1 в сторону ВУ
#define B5VS22LDU	 BUFFER[686]	//(B5VS22LDU) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 298	//(B5VS22LDU) Движение НЛ2 в сторону НУ
#define B5VS12LDU	 BUFFER[688]	//(B5VS12LDU) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 299	//(B5VS12LDU) Движение НЛ2 в сторону ВУ
#define R1VS22LDU	 BUFFER[690]	//(R1VS22LDU) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 300	//(R1VS22LDU) Движение МДЗ1 в сторону НУ
#define R2VS22LDU	 BUFFER[692]	//(R2VS22LDU) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 301	//(R2VS22LDU) Движение МДЗ2 в сторону НУ
#define R2VS12LDU	 BUFFER[694]	//(R2VS12LDU) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 302	//(R2VS12LDU) Движение МДЗ2 в сторону ВУ
#define R1VS12LDU	 BUFFER[696]	//(R1VS12LDU) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 303	//(R1VS12LDU) Движение МДЗ1 в сторону ВУ
#define R4VS22LDU	 BUFFER[698]	//(R4VS22LDU) Движение реактора к «У ЗАЩИТЫ»
#define idR4VS22LDU	 304	//(R4VS22LDU) Движение реактора к «У ЗАЩИТЫ»
#define R4VS12LDU	 BUFFER[700]	//(R4VS12LDU) Движение реактора  к «У ОБРАЗЦОВ»
#define idR4VS12LDU	 305	//(R4VS12LDU) Движение реактора  к «У ОБРАЗЦОВ»
#define A0SN02RIM	 BUFFER[702]	//(A0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define idA0SN02RIM	 306	//(A0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define A0SN03RIM	 BUFFER[707]	//(A0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define idA0SN03RIM	 307	//(A0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define A0SN04RIM	 BUFFER[712]	//(A0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define idA0SN04RIM	 308	//(A0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define A0SN05RIM	 BUFFER[717]	//(A0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define idA0SN05RIM	 309	//(A0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define A0SN06RIM	 BUFFER[722]	//(A0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define idA0SN06RIM	 310	//(A0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define A0SN07RIM	 BUFFER[727]	//(A0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define idA0SN07RIM	 311	//(A0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define A7AP31LDU	 BUFFER[732]	//(A7AP31LDU) Клапан (Обдув АЗ1) открыть (обесточить)
#define idA7AP31LDU	 312	//(A7AP31LDU) Клапан (Обдув АЗ1) открыть (обесточить)
#define B7AP31LDU	 BUFFER[734]	//(B7AP31LDU) Клапан (Обдув АЗ2) открыть (обесточить)
#define idB7AP31LDU	 313	//(B7AP31LDU) Клапан (Обдув АЗ2) открыть (обесточить)
#define B0SN02RIM	 BUFFER[736]	//(B0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define idB0SN02RIM	 314	//(B0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define B0SN03RIM	 BUFFER[741]	//(B0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define idB0SN03RIM	 315	//(B0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define B0SN04RIM	 BUFFER[746]	//(B0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define idB0SN04RIM	 316	//(B0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define B0SN05RIM	 BUFFER[751]	//(B0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define idB0SN05RIM	 317	//(B0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define B0SN06RIM	 BUFFER[756]	//(B0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define idB0SN06RIM	 318	//(B0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define B0SN07RIM	 BUFFER[761]	//(B0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define idB0SN07RIM	 319	//(B0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define fEM_R0UL01RIM	 BUFFER[766]	//(R0UL01RIM) Среднее время генерации нейтронов
#define idfEM_R0UL01RIM	 320	//(R0UL01RIM) Среднее время генерации нейтронов
#define fEM_R0UN02RIM	 BUFFER[771]	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define idfEM_R0UN02RIM	 321	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define fEM_A1UR01RIM	 BUFFER[776]	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR01RIM	 322	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define fEM_A1UR00RIM	 BUFFER[781]	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR00RIM	 323	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define fEM_A3UR00RIM	 BUFFER[786]	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR00RIM	 324	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define fEM_A3UR01RIM	 BUFFER[791]	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR01RIM	 325	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define fEM_R0UT01RIM	 BUFFER[796]	//(R0UT01RIM) Температурный коэффициент (долл)
#define idfEM_R0UT01RIM	 326	//(R0UT01RIM) Температурный коэффициент (долл)
#define fEM_R0UT02RIM	 BUFFER[801]	//(R0UT02RIM) Масса топлива в АЗ
#define idfEM_R0UT02RIM	 327	//(R0UT02RIM) Масса топлива в АЗ
#define fEM_R0UT04RIM	 BUFFER[806]	//(R0UT04RIM) Удельная теплоёмкость топлива
#define idfEM_R0UT04RIM	 328	//(R0UT04RIM) Удельная теплоёмкость топлива
#define fEM_R0UT03RIM	 BUFFER[811]	//(R0UT03RIM) Нормальная температура АЗ град
#define idfEM_R0UT03RIM	 329	//(R0UT03RIM) Нормальная температура АЗ град
#define fEM_R0UT05RIM	 BUFFER[816]	//(R0UT05RIM) Энергия деления ядра
#define idfEM_R0UT05RIM	 330	//(R0UT05RIM) Энергия деления ядра
#define fEM_R0UT06RIM	 BUFFER[821]	//(R0UT06RIM) Конвекционное сопротивление при обдуве
#define idfEM_R0UT06RIM	 331	//(R0UT06RIM) Конвекционное сопротивление при обдуве
#define fEM_A1UC02RDU	 BUFFER[826]	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define idfEM_A1UC02RDU	 332	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define fEM_A1UC04RIM	 BUFFER[831]	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define idfEM_A1UC04RIM	 333	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define fEM_A1UC05RIM	 BUFFER[836]	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define idfEM_A1UC05RIM	 334	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define fEM_A1UC06RIM	 BUFFER[841]	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define idfEM_A1UC06RIM	 335	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define fEM_A2UC06RIM	 BUFFER[846]	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define idfEM_A2UC06RIM	 336	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define fEM_A2UC05RIM	 BUFFER[851]	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define idfEM_A2UC05RIM	 337	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define fEM_A2UC04RIM	 BUFFER[856]	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define idfEM_A2UC04RIM	 338	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define fEM_A2UC02RDU	 BUFFER[861]	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define idfEM_A2UC02RDU	 339	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define fEM_A3UC06RIM	 BUFFER[866]	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define idfEM_A3UC06RIM	 340	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define fEM_A3UC05RIM	 BUFFER[871]	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC05RIM	 341	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define fEM_A3UC04RIM	 BUFFER[876]	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define idfEM_A3UC04RIM	 342	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define fEM_A3UC02RDU	 BUFFER[881]	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define idfEM_A3UC02RDU	 343	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define fEM_R4UV80RDU	 BUFFER[886]	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
#define idfEM_R4UV80RDU	 344	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
#define fEM_R4UC10RIM	 BUFFER[891]	//(R4UC10RIM) Координата верхних механических упоров тележки мм
#define idfEM_R4UC10RIM	 345	//(R4UC10RIM) Координата верхних механических упоров тележки мм
#define fEM_R4UC20RIM	 BUFFER[896]	//(R4UC20RIM) Координата нижних механических упоров тележки мм
#define idfEM_R4UC20RIM	 346	//(R4UC20RIM) Координата нижних механических упоров тележки мм
#define fEM_B8UC21RIM	 BUFFER[901]	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define idfEM_B8UC21RIM	 347	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define fEM_B8UC20RIM	 BUFFER[906]	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define idfEM_B8UC20RIM	 348	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define fEM_B8UC11RIM	 BUFFER[911]	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define idfEM_B8UC11RIM	 349	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define fEM_B8UC10RIM	 BUFFER[916]	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define idfEM_B8UC10RIM	 350	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define fEM_B8UV80RDU	 BUFFER[921]	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define idfEM_B8UV80RDU	 351	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define fEM_A8UV80RDU	 BUFFER[926]	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define idfEM_A8UV80RDU	 352	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define fEM_A8UC10RIM	 BUFFER[931]	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define idfEM_A8UC10RIM	 353	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define fEM_A8UC11RIM	 BUFFER[936]	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define idfEM_A8UC11RIM	 354	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define fEM_A8UC20RIM	 BUFFER[941]	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define idfEM_A8UC20RIM	 355	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define fEM_A8UC21RIM	 BUFFER[946]	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define idfEM_A8UC21RIM	 356	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define fEM_A6UC10RIM	 BUFFER[951]	//(A6UC10RIM) Время полного хода БЗ (сек)
#define idfEM_A6UC10RIM	 357	//(A6UC10RIM) Время полного хода БЗ (сек)
#define fEM_R1UC10RIM	 BUFFER[956]	//(R1UC10RIM) Время полного хода МДЗ сек
#define idfEM_R1UC10RIM	 358	//(R1UC10RIM) Время полного хода МДЗ сек
#define fEM_A5UC10RIM	 BUFFER[961]	//(A5UC10RIM) Время полного хода НЛ сек
#define idfEM_A5UC10RIM	 359	//(A5UC10RIM) Время полного хода НЛ сек
#define fEM_A0UN01RIM	 BUFFER[966]	//(A0UN01RIM) Мощность источника нейтронов ИНИ
#define idfEM_A0UN01RIM	 360	//(A0UN01RIM) Мощность источника нейтронов ИНИ
#define fEM_R4UC22RIM	 BUFFER[971]	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define idfEM_R4UC22RIM	 361	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define fEM_A1UG01RDU	 BUFFER[976]	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define idfEM_A1UG01RDU	 362	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define fEM_A2UG01RDU	 BUFFER[981]	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
#define idfEM_A2UG01RDU	 363	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
#define fEM_A3UG01RDU	 BUFFER[986]	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
#define idfEM_A3UG01RDU	 364	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
#define fEM_R7UC10RIM	 BUFFER[991]	//(R7UC10RIM) X-координата КНК53М R7IN13 см
#define idfEM_R7UC10RIM	 365	//(R7UC10RIM) X-координата КНК53М R7IN13 см
#define fEM_R7UC19RIM	 BUFFER[996]	//(R7UC19RIM) Y-координата СНМ-11 (11) см
#define idfEM_R7UC19RIM	 366	//(R7UC19RIM) Y-координата СНМ-11 (11) см
#define fEM_R7UI02RIM	 BUFFER[1001]	//(R7UI02RIM) Коэффициент усиления уровня радиации
#define idfEM_R7UI02RIM	 367	//(R7UI02RIM) Коэффициент усиления уровня радиации
#define fEM_R7UL01RIM	 BUFFER[1006]	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define idfEM_R7UL01RIM	 368	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define fEM_A2UR00RIM	 BUFFER[1011]	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define idfEM_A2UR00RIM	 369	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define fEM_A2UR01RIM	 BUFFER[1016]	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define idfEM_A2UR01RIM	 370	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define fEM_A0UN02RIM	 BUFFER[1021]	//(A0UN02RIM) Мощность источника нейтронов с АНИ
#define idfEM_A0UN02RIM	 371	//(A0UN02RIM) Мощность источника нейтронов с АНИ
#define fEM_R0UR30RIM	 BUFFER[1026]	//(R0UR30RIM) Реактивность вносимая образцами (долл)
#define idfEM_R0UR30RIM	 372	//(R0UR30RIM) Реактивность вносимая образцами (долл)
#define fEM_R0UR01RIM	 BUFFER[1031]	//(R0UR01RIM) Стартовая отрицательная реактивность
#define idfEM_R0UR01RIM	 373	//(R0UR01RIM) Стартовая отрицательная реактивность
#define fEM_R0UT02RDU	 BUFFER[1036]	//(R0UT02RDU) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RDU	 374	//(R0UT02RDU) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RDU	 BUFFER[1041]	//(R0UT01RDU) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RDU	 375	//(R0UT01RDU) Нижний предел шкалы датчика температуры
#define fEM_A1UC03RDU	 BUFFER[1046]	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define idfEM_A1UC03RDU	 376	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define fEM_A2UP03RDU	 BUFFER[1051]	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP03RDU	 377	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UP04RDU	 BUFFER[1056]	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP04RDU	 378	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UC03RDU	 BUFFER[1061]	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define idfEM_A2UC03RDU	 379	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define fEM_A3UP03RDU	 BUFFER[1066]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 380	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1071]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 381	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UC03RDU	 BUFFER[1076]	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define idfEM_A3UC03RDU	 382	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define fEM_R7UI74RIM	 BUFFER[1081]	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define idfEM_R7UI74RIM	 383	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define fEM_A8UC03RDU	 BUFFER[1086]	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define idfEM_A8UC03RDU	 384	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define fEM_R0UV87RDU	 BUFFER[1091]	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 385	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV81RDU	 BUFFER[1096]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 386	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1101]	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 387	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1106]	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 388	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1111]	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 389	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1116]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 390	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1121]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 391	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_A8UC08RDU	 BUFFER[1126]	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define idfEM_A8UC08RDU	 392	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define fEM_B8UC08RDU	 BUFFER[1131]	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define idfEM_B8UC08RDU	 393	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define fEM_R4UC08RDU	 BUFFER[1136]	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define idfEM_R4UC08RDU	 394	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define fEM_A0UX00RSS	 BUFFER[1141]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 395	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_R7UX01RSS	 BUFFER[1146]	//(R7UX01RSS) X-координата камеры R7IN11
#define idfEM_R7UX01RSS	 396	//(R7UX01RSS) X-координата камеры R7IN11
#define fEM_R7UX02RSS	 BUFFER[1151]	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define idfEM_R7UX02RSS	 397	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define fEM_R7UX04RSS	 BUFFER[1156]	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define idfEM_R7UX04RSS	 398	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define fEM_R7UX05RSS	 BUFFER[1161]	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define idfEM_R7UX05RSS	 399	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define fEM_R7UX06RSS	 BUFFER[1166]	//(R7UX06RSS) X-координата камеры R7IN23 (см)
#define idfEM_R7UX06RSS	 400	//(R7UX06RSS) X-координата камеры R7IN23 (см)
#define fEM_R7UX07RSS	 BUFFER[1171]	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define idfEM_R7UX07RSS	 401	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define fEM_R7UX08RSS	 BUFFER[1176]	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define idfEM_R7UX08RSS	 402	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define fEM_R7UX09RSS	 BUFFER[1181]	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define idfEM_R7UX09RSS	 403	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define fEM_R7UY01RSS	 BUFFER[1186]	//(R7UY01RSS) Y-координата камеры R7IN11
#define idfEM_R7UY01RSS	 404	//(R7UY01RSS) Y-координата камеры R7IN11
#define fEM_R7UY02RSS	 BUFFER[1191]	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define idfEM_R7UY02RSS	 405	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define fEM_R7UY04RSS	 BUFFER[1196]	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define idfEM_R7UY04RSS	 406	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define fEM_R7UY05RSS	 BUFFER[1201]	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define idfEM_R7UY05RSS	 407	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define fEM_R7UY06RSS	 BUFFER[1206]	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define idfEM_R7UY06RSS	 408	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define fEM_R7UY07RSS	 BUFFER[1211]	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define idfEM_R7UY07RSS	 409	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define fEM_R7UY08RSS	 BUFFER[1216]	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define idfEM_R7UY08RSS	 410	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define fEM_R7UY09RSS	 BUFFER[1221]	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define idfEM_R7UY09RSS	 411	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define fEM_R7UX10RSS	 BUFFER[1226]	//(R7UX10RSS) X-координата камеры R7IN41
#define idfEM_R7UX10RSS	 412	//(R7UX10RSS) X-координата камеры R7IN41
#define fEM_R7UX11RSS	 BUFFER[1231]	//(R7UX11RSS) X-координата камеры R7IN42
#define idfEM_R7UX11RSS	 413	//(R7UX11RSS) X-координата камеры R7IN42
#define fEM_R7UX12RSS	 BUFFER[1236]	//(R7UX12RSS) X-координата камеры R7IN43
#define idfEM_R7UX12RSS	 414	//(R7UX12RSS) X-координата камеры R7IN43
#define fEM_R7UY10RSS	 BUFFER[1241]	//(R7UY10RSS) Y-координата камеры R7IN41
#define idfEM_R7UY10RSS	 415	//(R7UY10RSS) Y-координата камеры R7IN41
#define fEM_R7UY11RSS	 BUFFER[1246]	//(R7UY11RSS) Y-координата камеры R7IN42
#define idfEM_R7UY11RSS	 416	//(R7UY11RSS) Y-координата камеры R7IN42
#define fEM_R7UY12RSS	 BUFFER[1251]	//(R7UY12RSS) Y-координата камеры R7IN43
#define idfEM_R7UY12RSS	 417	//(R7UY12RSS) Y-координата камеры R7IN43
#define fEM_A0UX01RSS	 BUFFER[1256]	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define idfEM_A0UX01RSS	 418	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define fEM_A0UX02RSS	 BUFFER[1261]	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define idfEM_A0UX02RSS	 419	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define fEM_A0UX03RSS	 BUFFER[1266]	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define idfEM_A0UX03RSS	 420	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define fEM_A0UX04RSS	 BUFFER[1271]	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define idfEM_A0UX04RSS	 421	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define fEM_A0UX05RSS	 BUFFER[1276]	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define idfEM_A0UX05RSS	 422	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define fEM_A0UX06RSS	 BUFFER[1281]	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define idfEM_A0UX06RSS	 423	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define fEM_A0UX07RSS	 BUFFER[1286]	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define idfEM_A0UX07RSS	 424	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define fEM_A0UX08RSS	 BUFFER[1291]	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define idfEM_A0UX08RSS	 425	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define fEM_A0UX09RSS	 BUFFER[1296]	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define idfEM_A0UX09RSS	 426	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define fEM_A0UX10RSS	 BUFFER[1301]	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define idfEM_A0UX10RSS	 427	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define fEM_A0UX11RSS	 BUFFER[1306]	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define idfEM_A0UX11RSS	 428	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define fEM_A0UX12RSS	 BUFFER[1311]	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define idfEM_A0UX12RSS	 429	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define fEM_B0UX01RSS	 BUFFER[1316]	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define idfEM_B0UX01RSS	 430	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define fEM_B0UX02RSS	 BUFFER[1321]	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define idfEM_B0UX02RSS	 431	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define fEM_B0UX03RSS	 BUFFER[1326]	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	 432	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	 BUFFER[1331]	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
#define idfEM_B0UX04RSS	 433	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
#define fEM_B0UX05RSS	 BUFFER[1336]	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	 434	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_B0UX06RSS	 BUFFER[1341]	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define idfEM_B0UX06RSS	 435	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define fEM_B0UX07RSS	 BUFFER[1346]	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define idfEM_B0UX07RSS	 436	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define fEM_B0UX08RSS	 BUFFER[1351]	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define idfEM_B0UX08RSS	 437	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define fEM_B0UX09RSS	 BUFFER[1356]	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define idfEM_B0UX09RSS	 438	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define fEM_B0UX10RSS	 BUFFER[1361]	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define idfEM_B0UX10RSS	 439	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define fEM_B0UX11RSS	 BUFFER[1366]	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define idfEM_B0UX11RSS	 440	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define fEM_B0UX12RSS	 BUFFER[1371]	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define idfEM_B0UX12RSS	 441	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define fEM_R0UH02RSS	 BUFFER[1376]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define idfEM_R0UH02RSS	 442	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define fEM_R0UH03RSS	 BUFFER[1381]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define idfEM_R0UH03RSS	 443	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define fEM_R4US80RDU	 BUFFER[1386]	//(R4US80RDU) Тормозной путь тележки (мм)
#define idfEM_R4US80RDU	 444	//(R4US80RDU) Тормозной путь тележки (мм)
#define fEM_R7UI71RIM	 BUFFER[1391]	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define idfEM_R7UI71RIM	 445	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define fEM_R7UI72RIM	 BUFFER[1396]	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define idfEM_R7UI72RIM	 446	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define fEM_R7UI73RIM	 BUFFER[1401]	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define idfEM_R7UI73RIM	 447	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define fEM_A1UP01RIM	 BUFFER[1406]	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define idfEM_A1UP01RIM	 448	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define fEM_A2UP01RIM	 BUFFER[1411]	//(A2UP01RIM) Текущее давление на сброс РБ
#define idfEM_A2UP01RIM	 449	//(A2UP01RIM) Текущее давление на сброс РБ
#define fEM_A0UP02RIM	 BUFFER[1416]	//(A0UP02RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP02RIM	 450	//(A0UP02RIM) Текущее давление в АЗ1,2
#define fEM_A3UP01RIM	 BUFFER[1421]	//(A3UP01RIM) Текущее давление на СПУСК ИС
#define idfEM_A3UP01RIM	 451	//(A3UP01RIM) Текущее давление на СПУСК ИС
#define fEM_A1UP82RIM	 BUFFER[1426]	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define idfEM_A1UP82RIM	 452	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define fEM_A3UP02RDU	 BUFFER[1431]	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define idfEM_A3UP02RDU	 453	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define fEM_A1UV02RIM	 BUFFER[1436]	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define idfEM_A1UV02RIM	 454	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define fEM_A3UV02RIM	 BUFFER[1441]	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define idfEM_A3UV02RIM	 455	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define fEM_A2UV02RIM	 BUFFER[1446]	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define idfEM_A2UV02RIM	 456	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define fEM_B8US80RDU	 BUFFER[1451]	//(B8US80RDU) Тормозной путь АЗ2 (мм)
#define idfEM_B8US80RDU	 457	//(B8US80RDU) Тормозной путь АЗ2 (мм)
#define fEM_A8US80RDU	 BUFFER[1456]	//(A8US80RDU) Тормозной путь ДС2 (мм)
#define idfEM_A8US80RDU	 458	//(A8US80RDU) Тормозной путь ДС2 (мм)
#define fEM_A6US80RDU	 BUFFER[1461]	//(A6US80RDU) Тормозной путь БЗ (мм)
#define idfEM_A6US80RDU	 459	//(A6US80RDU) Тормозной путь БЗ (мм)
#define fEM_A1US07RDU	 BUFFER[1466]	//(A1US07RDU) Постоянная времени масляного демпфера ББ
#define idfEM_A1US07RDU	 460	//(A1US07RDU) Постоянная времени масляного демпфера ББ
#define fEM_A2US07RDU	 BUFFER[1471]	//(A2US07RDU) Постоянная времени масляного демпфера РБ
#define idfEM_A2US07RDU	 461	//(A2US07RDU) Постоянная времени масляного демпфера РБ
#define fEM_A3US07RDU	 BUFFER[1476]	//(A3US07RDU) Постоянная времени масляного демпфера ИС
#define idfEM_A3US07RDU	 462	//(A3US07RDU) Постоянная времени масляного демпфера ИС
#define fEM_R7UI75RIM	 BUFFER[1481]	//(R7UI75RIM) Множитель к уровню радиации
#define idfEM_R7UI75RIM	 463	//(R7UI75RIM) Множитель к уровню радиации
#define fEM_R0UH21RSS	 BUFFER[1486]	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	 464	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	 BUFFER[1491]	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	 465	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	 BUFFER[1496]	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	 466	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0UR01RSS	 BUFFER[1501]	//(R0UR01RSS) Уровень по мощности РУ блокировки автоматического подъёма ББ
#define idfEM_R0UR01RSS	 467	//(R0UR01RSS) Уровень по мощности РУ блокировки автоматического подъёма ББ
#define fEM_R0UL52RSS	 BUFFER[1506]	//(R0UL52RSS) Уровень АС по мощности
#define idfEM_R0UL52RSS	 468	//(R0UL52RSS) Уровень АС по мощности
#define fEM_R0UL41RSS	 BUFFER[1511]	//(R0UL41RSS) Уровень ПС по периоду разгона
#define idfEM_R0UL41RSS	 469	//(R0UL41RSS) Уровень ПС по периоду разгона
#define fEM_R0UL51RSS	 BUFFER[1516]	//(R0UL51RSS) Уровень АС по периоду разгона
#define idfEM_R0UL51RSS	 470	//(R0UL51RSS) Уровень АС по периоду разгона
#define fEM_R0UL42RSS	 BUFFER[1521]	//(R0UL42RSS) Уровень ПС по мощности
#define idfEM_R0UL42RSS	 471	//(R0UL42RSS) Уровень ПС по мощности
#define fEM_R0UH05RSS	 BUFFER[1526]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 472	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UN03RSS	 BUFFER[1531]	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define idfEM_R0UN03RSS	 473	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
#define fEM_A4UL10RIM	 BUFFER[1536]	//(A4UL10RIM) Время полного перемещения НИ сек
#define idfEM_A4UL10RIM	 474	//(A4UL10RIM) Время полного перемещения НИ сек
#define fEM_A9UL10RIM	 BUFFER[1541]	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define idfEM_A9UL10RIM	 475	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define fEM_R3UL10RIM	 BUFFER[1546]	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define idfEM_R3UL10RIM	 476	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define fEM_R5UL10RIM	 BUFFER[1551]	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define idfEM_R5UL10RIM	 477	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define fEM_R6UL10RIM	 BUFFER[1556]	//(R6UL10RIM) Время полного хода кран-балки сек
#define idfEM_R6UL10RIM	 478	//(R6UL10RIM) Время полного хода кран-балки сек
#define lEM_C1AD31LRP	 BUFFER[1561]	//(C1AD31LRP) Общий сброс от РПУ
#define idlEM_C1AD31LRP	 479	//(C1AD31LRP) Общий сброс от РПУ
#define lEM_R0IE01LRP	 BUFFER[1563]	//(R0IE01LRP) Отключение питание детекторов
#define idlEM_R0IE01LRP	 480	//(R0IE01LRP) Отключение питание детекторов
#define lEM_R0IE02LRP	 BUFFER[1565]	//(R0IE02LRP) Отключить питание ПР, ПУ
#define idlEM_R0IE02LRP	 481	//(R0IE02LRP) Отключить питание ПР, ПУ
#define fEM_A2UP02RIM	 BUFFER[1567]	//(A2UP02RIM) Текущее давление на подъём РБ
#define idfEM_A2UP02RIM	 482	//(A2UP02RIM) Текущее давление на подъём РБ
#define fEM_A2UP03RIM	 BUFFER[1572]	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define idfEM_A2UP03RIM	 483	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define fEM_A0UP01RIM	 BUFFER[1577]	//(A0UP01RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP01RIM	 484	//(A0UP01RIM) Текущее давление в АЗ1,2
#define fEM_A3UP02RIM	 BUFFER[1582]	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define idfEM_A3UP02RIM	 485	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define fEM_A4UP01RIM	 BUFFER[1587]	//(A4UP01RIM) Текущее давление на подъём НИ
#define idfEM_A4UP01RIM	 486	//(A4UP01RIM) Текущее давление на подъём НИ
#define fEM_A4UP02RIM	 BUFFER[1592]	//(A4UP02RIM) Нижняя граница давления на подъём НИ
#define idfEM_A4UP02RIM	 487	//(A4UP02RIM) Нижняя граница давления на подъём НИ
#define fEM_R7UI76RIM	 BUFFER[1597]	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define idfEM_R7UI76RIM	 488	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define fEM_R7UI77RIM	 BUFFER[1602]	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define idfEM_R7UI77RIM	 489	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define iEM_TERBB1	 BUFFER[1607]	//(TERBB1) Неисправности  ББ1
#define idiEM_TERBB1	 490	//(TERBB1) Неисправности  ББ1
#define fEM_A1MC02RC1	 BUFFER[1610]	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
#define idfEM_A1MC02RC1	 491	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
#define fEM_A1MV02RC1	 BUFFER[1615]	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define idfEM_A1MV02RC1	 492	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define iEM_TERBB2	 BUFFER[1620]	//(TERBB2) Неисправности  ББ2
#define idiEM_TERBB2	 493	//(TERBB2) Неисправности  ББ2
#define fEM_B1MC02RC1	 BUFFER[1623]	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
#define idfEM_B1MC02RC1	 494	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
#define fEM_B1MV02RC1	 BUFFER[1628]	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define idfEM_B1MV02RC1	 495	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define iEM_TERRB2	 BUFFER[1633]	//(TERRB2) Неисправности  РБ2
#define idiEM_TERRB2	 496	//(TERRB2) Неисправности  РБ2
#define fEM_B2MC02RC1	 BUFFER[1636]	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
#define idfEM_B2MC02RC1	 497	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
#define fEM_B2MV02RC1	 BUFFER[1641]	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define idfEM_B2MV02RC1	 498	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define iEM_TERRB1	 BUFFER[1646]	//(TERRB1) Неисправности  РБ1
#define idiEM_TERRB1	 499	//(TERRB1) Неисправности  РБ1
#define fEM_A2MC02RC1	 BUFFER[1649]	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
#define idfEM_A2MC02RC1	 500	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
#define fEM_A2MV02RC1	 BUFFER[1654]	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define idfEM_A2MV02RC1	 501	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define iEM_TERIS2	 BUFFER[1659]	//(TERIS2) Неисправности  ИС2
#define idiEM_TERIS2	 502	//(TERIS2) Неисправности  ИС2
#define fEM_B3MC02RC1	 BUFFER[1662]	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
#define idfEM_B3MC02RC1	 503	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
#define fEM_B3MV02RC1	 BUFFER[1667]	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define idfEM_B3MV02RC1	 504	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define iEM_TERIS1	 BUFFER[1672]	//(TERIS1) Неисправности  ИС1
#define idiEM_TERIS1	 505	//(TERIS1) Неисправности  ИС1
#define fEM_A3MC02RC1	 BUFFER[1675]	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
#define idfEM_A3MC02RC1	 506	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
#define fEM_A3MV02RC1	 BUFFER[1680]	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define idfEM_A3MV02RC1	 507	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define iEM_TERA1IE04LDU	 BUFFER[1685]	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define idiEM_TERA1IE04LDU	 508	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define iEM_TERA1IE03LDU	 BUFFER[1688]	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define idiEM_TERA1IE03LDU	 509	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define fEM_A1MC01RC1	 BUFFER[1691]	//(A1MC01RC1) Заданная координата  ББ1 от ИС
#define idfEM_A1MC01RC1	 510	//(A1MC01RC1) Заданная координата  ББ1 от ИС
#define iEM_TERB1IE03LDU	 BUFFER[1696]	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define idiEM_TERB1IE03LDU	 511	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define iEM_TERB1IE04LDU	 BUFFER[1699]	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define idiEM_TERB1IE04LDU	 512	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define fEM_B1MC01RC1	 BUFFER[1702]	//(B1MC01RC1) Заданная координата ББ2 от ИС
#define idfEM_B1MC01RC1	 513	//(B1MC01RC1) Заданная координата ББ2 от ИС
#define fEM_B1MV01RC1	 BUFFER[1707]	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define idfEM_B1MV01RC1	 514	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define fEM_B2MC01RC1	 BUFFER[1712]	//(B2MC01RC1) Заданная координата РБ2 от ИС
#define idfEM_B2MC01RC1	 515	//(B2MC01RC1) Заданная координата РБ2 от ИС
#define fEM_B2MV01RC1	 BUFFER[1717]	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define idfEM_B2MV01RC1	 516	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define fEM_A3MC01RC1	 BUFFER[1722]	//(A3MC01RC1) Заданная координата ИС1 от ИС
#define idfEM_A3MC01RC1	 517	//(A3MC01RC1) Заданная координата ИС1 от ИС
#define fEM_A3MV01RC1	 BUFFER[1727]	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define idfEM_A3MV01RC1	 518	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define fEM_B3MC01RC1	 BUFFER[1732]	//(B3MC01RC1) Заданная координата ИС2 от ИС
#define idfEM_B3MC01RC1	 519	//(B3MC01RC1) Заданная координата ИС2 от ИС
#define fEM_B3MV01RC1	 BUFFER[1737]	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define idfEM_B3MV01RC1	 520	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define iEM_TERA2SS21LIM	 BUFFER[1742]	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define idiEM_TERA2SS21LIM	 521	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define iEM_TERA2SS12LIM	 BUFFER[1745]	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define idiEM_TERA2SS12LIM	 522	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define iEM_TERR6SS21LIM	 BUFFER[1748]	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define idiEM_TERR6SS21LIM	 523	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define iEM_TERA2VP82LIM	 BUFFER[1751]	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define idiEM_TERA2VP82LIM	 524	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define iEM_TERA2SS11LIM	 BUFFER[1754]	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define idiEM_TERA2SS11LIM	 525	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define iEM_TERB3SS21LIM	 BUFFER[1757]	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define idiEM_TERB3SS21LIM	 526	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define iEM_TERA0MT01RIM	 BUFFER[1760]	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define idiEM_TERA0MT01RIM	 527	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define iEM_TERB0MT01RIM	 BUFFER[1763]	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define idiEM_TERB0MT01RIM	 528	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define iEM_TERA2SP01RIM	 BUFFER[1766]	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define idiEM_TERA2SP01RIM	 529	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define iEM_TERB2SP01RIM	 BUFFER[1769]	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define idiEM_TERB2SP01RIM	 530	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define iEM_TERB3SP02RIM	 BUFFER[1772]	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define idiEM_TERB3SP02RIM	 531	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define iEM_TERA3SC01RIM	 BUFFER[1775]	//(TERA3SC01RIM) Искажение: Координата штока ИС1
#define idiEM_TERA3SC01RIM	 532	//(TERA3SC01RIM) Искажение: Координата штока ИС1
#define iEM_TERA3VP81LIM	 BUFFER[1778]	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define idiEM_TERA3VP81LIM	 533	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define iEM_TERA2SC01RIM	 BUFFER[1781]	//(TERA2SC01RIM) Искажение: Координата штока РБ1
#define idiEM_TERA2SC01RIM	 534	//(TERA2SC01RIM) Искажение: Координата штока РБ1
#define iEM_TERA2SS33LIM	 BUFFER[1784]	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define idiEM_TERA2SS33LIM	 535	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define iEM_TERA3SS21LIM	 BUFFER[1787]	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define idiEM_TERA3SS21LIM	 536	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define iEM_TERA3SS33LIM	 BUFFER[1790]	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define idiEM_TERA3SS33LIM	 537	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define iEM_TERA3SS31LIM	 BUFFER[1793]	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define idiEM_TERA3SS31LIM	 538	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define iEM_TERB3SS31LIM	 BUFFER[1796]	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define idiEM_TERB3SS31LIM	 539	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define iEM_TERB3SS33LIM	 BUFFER[1799]	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idiEM_TERB3SS33LIM	 540	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define iEM_TERB3SC01RIM	 BUFFER[1802]	//(TERB3SC01RIM) Искажение: Координата штока ИС2
#define idiEM_TERB3SC01RIM	 541	//(TERB3SC01RIM) Искажение: Координата штока ИС2
#define iEM_TERA3SS11LIM	 BUFFER[1805]	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define idiEM_TERA3SS11LIM	 542	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define iEM_TERB3SS11LIM	 BUFFER[1808]	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define idiEM_TERB3SS11LIM	 543	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define iEM_TERR6IS64LIM	 BUFFER[1811]	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define idiEM_TERR6IS64LIM	 544	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define iEM_TERB3SS22LIM	 BUFFER[1814]	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define idiEM_TERB3SS22LIM	 545	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define iEM_TERA3SS22LIM	 BUFFER[1817]	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define idiEM_TERA3SS22LIM	 546	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define iEM_TERA3SP02RIM	 BUFFER[1820]	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define idiEM_TERA3SP02RIM	 547	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define iEM_TERR6IS62LIM	 BUFFER[1823]	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define idiEM_TERR6IS62LIM	 548	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define iEM_TERR6IS66LIM	 BUFFER[1826]	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idiEM_TERR6IS66LIM	 549	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define iEM_TERR6IS67LIM	 BUFFER[1829]	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idiEM_TERR6IS67LIM	 550	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define iEM_TERA0VP81LIM	 BUFFER[1832]	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define idiEM_TERA0VP81LIM	 551	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define iEM_TERB0VP81LIM	 BUFFER[1835]	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define idiEM_TERB0VP81LIM	 552	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define iEM_TERR0VP81LIM	 BUFFER[1838]	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define idiEM_TERR0VP81LIM	 553	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define iEM_TERR6IS68LIM	 BUFFER[1841]	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define idiEM_TERR6IS68LIM	 554	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define iEM_TERR7SI74RIM	 BUFFER[1844]	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define idiEM_TERR7SI74RIM	 555	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define iEM_TERA5SS21LIM	 BUFFER[1847]	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define idiEM_TERA5SS21LIM	 556	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define iEM_TERB5SS11LIM	 BUFFER[1850]	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define idiEM_TERB5SS11LIM	 557	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define iEM_TERA5SS11LIM	 BUFFER[1853]	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define idiEM_TERA5SS11LIM	 558	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define iEM_TERA9SS11LIM	 BUFFER[1856]	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define idiEM_TERA9SS11LIM	 559	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define iEM_TERB2SS11LIM	 BUFFER[1859]	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define idiEM_TERB2SS11LIM	 560	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define iEM_TERB2SS12LIM	 BUFFER[1862]	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define idiEM_TERB2SS12LIM	 561	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define iEM_TERB2SS21LIM	 BUFFER[1865]	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define idiEM_TERB2SS21LIM	 562	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define iEM_TERR3SS11LIM	 BUFFER[1868]	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define idiEM_TERR3SS11LIM	 563	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define iEM_TERB2SC01RIM	 BUFFER[1871]	//(TERB2SC01RIM) Искажение: Координата штока РБ2
#define idiEM_TERB2SC01RIM	 564	//(TERB2SC01RIM) Искажение: Координата штока РБ2
#define iEM_TERR3SS21LIM	 BUFFER[1874]	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define idiEM_TERR3SS21LIM	 565	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define iEM_TERR5SS11LIM	 BUFFER[1877]	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define idiEM_TERR5SS11LIM	 566	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define iEM_TERA4SS11LIM	 BUFFER[1880]	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define idiEM_TERA4SS11LIM	 567	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define iEM_TERR1SS11LIM	 BUFFER[1883]	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define idiEM_TERR1SS11LIM	 568	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define iEM_TERR1SS21LIM	 BUFFER[1886]	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define idiEM_TERR1SS21LIM	 569	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define iEM_TERR2SS11LIM	 BUFFER[1889]	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define idiEM_TERR2SS11LIM	 570	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define iEM_TERR2SS21LIM	 BUFFER[1892]	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define idiEM_TERR2SS21LIM	 571	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define iEM_TERA4VP82LIM	 BUFFER[1895]	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define idiEM_TERA4VP82LIM	 572	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define iEM_TERB4SS21LIM	 BUFFER[1898]	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define idiEM_TERB4SS21LIM	 573	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define iEM_TERR5SS21LIM	 BUFFER[1901]	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define idiEM_TERR5SS21LIM	 574	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define iEM_TERB6SS21LIM	 BUFFER[1904]	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define idiEM_TERB6SS21LIM	 575	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define iEM_TERB4SS11LIM	 BUFFER[1907]	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define idiEM_TERB4SS11LIM	 576	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define iEM_TERA4SS21LIM	 BUFFER[1910]	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define idiEM_TERA4SS21LIM	 577	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define iEM_TERA6MS11LIM	 BUFFER[1913]	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define idiEM_TERA6MS11LIM	 578	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define iEM_TERA6SS21LIM	 BUFFER[1916]	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define idiEM_TERA6SS21LIM	 579	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define iEM_TERB6SS11LIM	 BUFFER[1919]	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define idiEM_TERB6SS11LIM	 580	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define iEM_TERR4SS11LIM	 BUFFER[1922]	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define idiEM_TERR4SS11LIM	 581	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define iEM_TERR4MS21LIM	 BUFFER[1925]	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
#define idiEM_TERR4MS21LIM	 582	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
#define iEM_TERR4SS12LIM	 BUFFER[1928]	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define idiEM_TERR4SS12LIM	 583	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define iEM_TERR4SS22LIM	 BUFFER[1931]	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define idiEM_TERR4SS22LIM	 584	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define iEM_TERR8SS11LIM	 BUFFER[1934]	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define idiEM_TERR8SS11LIM	 585	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define iEM_TERB8SC01RIM	 BUFFER[1937]	//(TERB8SC01RIM) Искажение: Координата АЗ2
#define idiEM_TERB8SC01RIM	 586	//(TERB8SC01RIM) Искажение: Координата АЗ2
#define iEM_TERA8SC01RIM	 BUFFER[1940]	//(TERA8SC01RIM) Искажение: Координата ДС2
#define idiEM_TERA8SC01RIM	 587	//(TERA8SC01RIM) Искажение: Координата ДС2
#define iEM_TERB8SS12LIM	 BUFFER[1943]	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define idiEM_TERB8SS12LIM	 588	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define iEM_TERA8SS12LIM	 BUFFER[1946]	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define idiEM_TERA8SS12LIM	 589	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define iEM_TERB8SS22LIM	 BUFFER[1949]	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define idiEM_TERB8SS22LIM	 590	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define iEM_TERA8SS22LIM	 BUFFER[1952]	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define idiEM_TERA8SS22LIM	 591	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define iEM_TERA9SS21LIM	 BUFFER[1955]	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define idiEM_TERA9SS21LIM	 592	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define iEM_TERB9SS21LIM	 BUFFER[1958]	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define idiEM_TERB9SS21LIM	 593	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define iEM_TERB9SS11LIM	 BUFFER[1961]	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define idiEM_TERB9SS11LIM	 594	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define iEM_TERB5SS21LIM	 BUFFER[1964]	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define idiEM_TERB5SS21LIM	 595	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define iEM_TERA1SS21LIM	 BUFFER[1967]	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define idiEM_TERA1SS21LIM	 596	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define iEM_TERA1SS11LIM	 BUFFER[1970]	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define idiEM_TERA1SS11LIM	 597	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define iEM_TERA1SC01RIM	 BUFFER[1973]	//(TERA1SC01RIM) Искажение: Координата штока ББ1
#define idiEM_TERA1SC01RIM	 598	//(TERA1SC01RIM) Искажение: Координата штока ББ1
#define iEM_TERA1SS12LIM	 BUFFER[1976]	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define idiEM_TERA1SS12LIM	 599	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define iEM_TERB1SS21LIM	 BUFFER[1979]	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define idiEM_TERB1SS21LIM	 600	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define iEM_TERB1SS11LIM	 BUFFER[1982]	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define idiEM_TERB1SS11LIM	 601	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define iEM_TERB1MC01RIM	 BUFFER[1985]	//(TERB1MC01RIM) Искажение: Координата штока ББ2
#define idiEM_TERB1MC01RIM	 602	//(TERB1MC01RIM) Искажение: Координата штока ББ2
#define iEM_TERB1SS12LIM	 BUFFER[1988]	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define idiEM_TERB1SS12LIM	 603	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define iEM_TERR0IE43LIM	 BUFFER[1991]	//(TERR0IE43LIM) Исправность ВИП 0,5 4канала
#define idiEM_TERR0IE43LIM	 604	//(TERR0IE43LIM) Исправность ВИП 0,5 4канала
#define iEM_TERR0IE41LIM	 BUFFER[1994]	//(TERR0IE41LIM) Исправность ВИП 1,6 (№17) СНМ11 4канала
#define idiEM_TERR0IE41LIM	 605	//(TERR0IE41LIM) Исправность ВИП 1,6 (№17) СНМ11 4канала
#define lEM_A0EE06LC1	 BUFFER[1997]	//(A0EE06LC1) Исправность АКНП4 от диагностики контроллера (От ИС)
#define idlEM_A0EE06LC1	 606	//(A0EE06LC1) Исправность АКНП4 от диагностики контроллера (От ИС)
#define iEM_TERR0IE33LIM	 BUFFER[1999]	//(TERR0IE33LIM) Искажение:Исправность ВИП 0,5  3канала
#define idiEM_TERR0IE33LIM	 607	//(TERR0IE33LIM) Искажение:Исправность ВИП 0,5  3канала
#define iEM_TERR0IE31LIM	 BUFFER[2002]	//(TERR0IE31LIM) Искажение: Исправность ВИП 1,6 (№14) СНМ11 3канала
#define idiEM_TERR0IE31LIM	 608	//(TERR0IE31LIM) Искажение: Исправность ВИП 1,6 (№14) СНМ11 3канала
#define lEM_A0EE05LC1	 BUFFER[2005]	//(A0EE05LC1) Исправность АКНП3 от диагностики контроллера (От ИС)
#define idlEM_A0EE05LC1	 609	//(A0EE05LC1) Исправность АКНП3 от диагностики контроллера (От ИС)
#define iEM_TERR0IE11LIM	 BUFFER[2007]	//(TERR0IE11LIM) Искажение: Исправность ВИП 1,6 (№8) СНМ11 1канала
#define idiEM_TERR0IE11LIM	 610	//(TERR0IE11LIM) Искажение: Исправность ВИП 1,6 (№8) СНМ11 1канала
#define iEM_TERR0IE13LIM	 BUFFER[2010]	//(TERR0IE13LIM) Искажение: Исправность ВИП 0,5  1канала
#define idiEM_TERR0IE13LIM	 611	//(TERR0IE13LIM) Искажение: Исправность ВИП 0,5  1канала
#define lEM_A0EE03LC1	 BUFFER[2013]	//(A0EE03LC1) Исправность АКНП1 от диагностики контроллера (От ИС)
#define idlEM_A0EE03LC1	 612	//(A0EE03LC1) Исправность АКНП1 от диагностики контроллера (От ИС)
#define iEM_TERR0IE23LIM	 BUFFER[2015]	//(TERR0IE23LIM) Искажение: Исправность ВИП 0,5 (№13) КНК53М 2канала
#define idiEM_TERR0IE23LIM	 613	//(TERR0IE23LIM) Искажение: Исправность ВИП 0,5 (№13) КНК53М 2канала
#define iEM_TERR0IE21LIM	 BUFFER[2018]	//(TERR0IE21LIM) Искажение: Исправность ВИП 1,6 (№11) СНМ11 2канала
#define idiEM_TERR0IE21LIM	 614	//(TERR0IE21LIM) Искажение: Исправность ВИП 1,6 (№11) СНМ11 2канала
#define lEM_A0EE04LC1	 BUFFER[2021]	//(A0EE04LC1) Исправность АКНП2 от диагностики контроллера (От ИС)
#define idlEM_A0EE04LC1	 615	//(A0EE04LC1) Исправность АКНП2 от диагностики контроллера (От ИС)
#define iEM_TERTLG	 BUFFER[2023]	//(TERTLG) Неисправности  тележки от ИС
#define idiEM_TERTLG	 616	//(TERTLG) Неисправности  тележки от ИС
#define fEM_R4MC01RC1	 BUFFER[2026]	//(R4MC01RC1) Заданная координата тележки от ИС
#define idfEM_R4MC01RC1	 617	//(R4MC01RC1) Заданная координата тележки от ИС
#define fEM_R4MV01RC1	 BUFFER[2031]	//(R4MV01RC1) Заданная скорость тележки от ИС
#define idfEM_R4MV01RC1	 618	//(R4MV01RC1) Заданная скорость тележки от ИС
#define iEM_TERMAZ2	 BUFFER[2036]	//(TERMAZ2) Неисправности АЗ2 от ИС
#define idiEM_TERMAZ2	 619	//(TERMAZ2) Неисправности АЗ2 от ИС
#define fEM_B8MC01RC1	 BUFFER[2039]	//(B8MC01RC1) аданная координата АЗ2 от ИС
#define idfEM_B8MC01RC1	 620	//(B8MC01RC1) аданная координата АЗ2 от ИС
#define fEM_B8MV01RC1	 BUFFER[2044]	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
#define idfEM_B8MV01RC1	 621	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
#define iEM_TERDS2	 BUFFER[2049]	//(TERDS2) Неисправности ДС2 от ИС
#define idiEM_TERDS2	 622	//(TERDS2) Неисправности ДС2 от ИС
#define fEM_A8MC01RC1	 BUFFER[2052]	//(A8MC01RC1) Заданная координата ДС2 от ИС
#define idfEM_A8MC01RC1	 623	//(A8MC01RC1) Заданная координата ДС2 от ИС
#define fEM_A8MV01RC1	 BUFFER[2057]	//(A8MV01RC1) Заданная скорость ДС2 от ИС
#define idfEM_A8MV01RC1	 624	//(A8MV01RC1) Заданная скорость ДС2 от ИС
#define iEM_TERBZ1	 BUFFER[2062]	//(TERBZ1) Неисправности БЗ1
#define idiEM_TERBZ1	 625	//(TERBZ1) Неисправности БЗ1
#define fEM_A6MC01RC1	 BUFFER[2065]	//(A6MC01RC1) Заданная координата БЗ1 от ИС
#define idfEM_A6MC01RC1	 626	//(A6MC01RC1) Заданная координата БЗ1 от ИС
#define fEM_A6MV01RC1	 BUFFER[2070]	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
#define idfEM_A6MV01RC1	 627	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
#define iEM_TERBZ2	 BUFFER[2075]	//(TERBZ2) Неисправности БЗ2
#define idiEM_TERBZ2	 628	//(TERBZ2) Неисправности БЗ2
#define fEM_B6MC01RC1	 BUFFER[2078]	//(B6MC01RC1) Заданная координата БЗ2 от ИС
#define idfEM_B6MC01RC1	 629	//(B6MC01RC1) Заданная координата БЗ2 от ИС
#define fEM_B6MV01RC1	 BUFFER[2083]	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
#define idfEM_B6MV01RC1	 630	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
#define lEM_R3AD10LC1	 BUFFER[2088]	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define idlEM_R3AD10LC1	 631	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define lEM_R3AD20LC1	 BUFFER[2090]	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define idlEM_R3AD20LC1	 632	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define lEM_R6AD10LC1	 BUFFER[2092]	//(R6AD10LC1) Выкатить кран-балку от ИС
#define idlEM_R6AD10LC1	 633	//(R6AD10LC1) Выкатить кран-балку от ИС
#define lEM_R5AD10LC1	 BUFFER[2094]	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define idlEM_R5AD10LC1	 634	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define lEM_R5AD20LC1	 BUFFER[2096]	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define idlEM_R5AD20LC1	 635	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define iEM_TERMDZ2	 BUFFER[2098]	//(TERMDZ2) Неисправности МДЗ2
#define idiEM_TERMDZ2	 636	//(TERMDZ2) Неисправности МДЗ2
#define fEM_R2MC01RC1	 BUFFER[2101]	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
#define idfEM_R2MC01RC1	 637	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
#define fEM_R2MV01RC1	 BUFFER[2106]	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define idfEM_R2MV01RC1	 638	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define iEM_TERMDZ1	 BUFFER[2111]	//(TERMDZ1) Неисправности МДЗ1
#define idiEM_TERMDZ1	 639	//(TERMDZ1) Неисправности МДЗ1
#define fEM_R1MC01RC1	 BUFFER[2114]	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
#define idfEM_R1MC01RC1	 640	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
#define fEM_R1MV01RC1	 BUFFER[2119]	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define idfEM_R1MV01RC1	 641	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define iEM_TERNL1	 BUFFER[2124]	//(TERNL1) Неисправности НЛ1
#define idiEM_TERNL1	 642	//(TERNL1) Неисправности НЛ1
#define fEM_A5MC01RC1	 BUFFER[2127]	//(A5MC01RC1) Заданная координата НЛ1 от ИС
#define idfEM_A5MC01RC1	 643	//(A5MC01RC1) Заданная координата НЛ1 от ИС
#define fEM_A5MV01RC1	 BUFFER[2132]	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
#define idfEM_A5MV01RC1	 644	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
#define iEM_TERNL2	 BUFFER[2137]	//(TERNL2) Неисправности НЛ2
#define idiEM_TERNL2	 645	//(TERNL2) Неисправности НЛ2
#define fEM_B5MC01RC1	 BUFFER[2140]	//(B5MC01RC1) Заданная координата НЛ2 от ИС
#define idfEM_B5MC01RC1	 646	//(B5MC01RC1) Заданная координата НЛ2 от ИС
#define fEM_B5MV01RC1	 BUFFER[2145]	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
#define idfEM_B5MV01RC1	 647	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
#define lEM_R8AD10LC1	 BUFFER[2150]	//(R8AD10LC1) Установить аварийный НИ от ИС
#define idlEM_R8AD10LC1	 648	//(R8AD10LC1) Установить аварийный НИ от ИС
#define fEM_A1UC08RIM	 BUFFER[2152]	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define idfEM_A1UC08RIM	 649	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define fEM_A2UC08RIM	 BUFFER[2157]	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
#define idfEM_A2UC08RIM	 650	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
#define fEM_A3UC08RIM	 BUFFER[2162]	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define idfEM_A3UC08RIM	 651	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define fEM_R0UL01RSS	 BUFFER[2167]	//(R0UL01RSS) Шаг (мс) измерения периода
#define idfEM_R0UL01RSS	 652	//(R0UL01RSS) Шаг (мс) измерения периода
#define fEM_R0UL03RSS	 BUFFER[2172]	//(R0UL03RSS) Предельное время ожидания роста потока (сек)
#define idfEM_R0UL03RSS	 653	//(R0UL03RSS) Предельное время ожидания роста потока (сек)
#define iEM_TERB2SS33LIM	 BUFFER[2177]	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define idiEM_TERB2SS33LIM	 654	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define iEM_TERA1VP81LIM	 BUFFER[2180]	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define idiEM_TERA1VP81LIM	 655	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define iEM_TERB1VP81LIM	 BUFFER[2183]	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define idiEM_TERB1VP81LIM	 656	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define fEM_A0UT03RSP	 BUFFER[2186]	//(A0UT03RSP) Стартовая  температура АЗ1 град
#define idfEM_A0UT03RSP	 657	//(A0UT03RSP) Стартовая  температура АЗ1 град
#define fEM_A0UR01RSP	 BUFFER[2191]	//(A0UR01RSP) Стартовая  реактивность АЗ1
#define idfEM_A0UR01RSP	 658	//(A0UR01RSP) Стартовая  реактивность АЗ1
#define fEM_A0UR02RSP	 BUFFER[2196]	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define idfEM_A0UR02RSP	 659	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define fEM_B0UT03RSP	 BUFFER[2201]	//(B0UT03RSP) Стартовая  температура АЗ2 град
#define idfEM_B0UT03RSP	 660	//(B0UT03RSP) Стартовая  температура АЗ2 град
#define fEM_A1MC01RSP	 BUFFER[2206]	//(A1MC01RSP) Стартовая координата  ББ1
#define idfEM_A1MC01RSP	 661	//(A1MC01RSP) Стартовая координата  ББ1
#define fEM_A1MC02RSP	 BUFFER[2211]	//(A1MC02RSP) Стартовая координата штока ББ1
#define idfEM_A1MC02RSP	 662	//(A1MC02RSP) Стартовая координата штока ББ1
#define fEM_A1MV01RSP	 BUFFER[2216]	//(A1MV01RSP) Стартовая скорость движения  ББ1
#define idfEM_A1MV01RSP	 663	//(A1MV01RSP) Стартовая скорость движения  ББ1
#define fEM_A1MV02RSP	 BUFFER[2221]	//(A1MV02RSP) Стартовая скорость движения  ББ1
#define idfEM_A1MV02RSP	 664	//(A1MV02RSP) Стартовая скорость движения  ББ1
#define fEM_B1MC01RSP	 BUFFER[2226]	//(B1MC01RSP) Стартовая координата  ББ2
#define idfEM_B1MC01RSP	 665	//(B1MC01RSP) Стартовая координата  ББ2
#define fEM_B1MV01RSP	 BUFFER[2231]	//(B1MV01RSP) Стартовая скорость движения  ББ2
#define idfEM_B1MV01RSP	 666	//(B1MV01RSP) Стартовая скорость движения  ББ2
#define fEM_B1MC02RSP	 BUFFER[2236]	//(B1MC02RSP) Стартовая координата штока ББ2
#define idfEM_B1MC02RSP	 667	//(B1MC02RSP) Стартовая координата штока ББ2
#define fEM_B1MV02RSP	 BUFFER[2241]	//(B1MV02RSP) Стартовая скорость движения  ББ2
#define idfEM_B1MV02RSP	 668	//(B1MV02RSP) Стартовая скорость движения  ББ2
#define fEM_A2MC01RC1	 BUFFER[2246]	//(A2MC01RC1) Заданная координата РБ1 от ИС
#define idfEM_A2MC01RC1	 669	//(A2MC01RC1) Заданная координата РБ1 от ИС
#define fEM_A2MV01RC1	 BUFFER[2251]	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define idfEM_A2MV01RC1	 670	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define fEM_A2MC01RSP	 BUFFER[2256]	//(A2MC01RSP) Стартовая координата  РБ1
#define idfEM_A2MC01RSP	 671	//(A2MC01RSP) Стартовая координата  РБ1
#define fEM_A2MV01RSP	 BUFFER[2261]	//(A2MV01RSP) Стартовая скорость движения  РБ1
#define idfEM_A2MV01RSP	 672	//(A2MV01RSP) Стартовая скорость движения  РБ1
#define fEM_A2MC02RSP	 BUFFER[2266]	//(A2MC02RSP) Стартовая координата штока РБ1
#define idfEM_A2MC02RSP	 673	//(A2MC02RSP) Стартовая координата штока РБ1
#define fEM_A2MV02RSP	 BUFFER[2271]	//(A2MV02RSP) Стартовая скорость движения  РБ1
#define idfEM_A2MV02RSP	 674	//(A2MV02RSP) Стартовая скорость движения  РБ1
#define fEM_B2MC01RSP	 BUFFER[2276]	//(B2MC01RSP) Стартовая координата  РБ2
#define idfEM_B2MC01RSP	 675	//(B2MC01RSP) Стартовая координата  РБ2
#define fEM_B2MV01RSP	 BUFFER[2281]	//(B2MV01RSP) Стартовая скорость движения  РБ2
#define idfEM_B2MV01RSP	 676	//(B2MV01RSP) Стартовая скорость движения  РБ2
#define fEM_B2MC02RSP	 BUFFER[2286]	//(B2MC02RSP) Стартовая координата штока РБ2
#define idfEM_B2MC02RSP	 677	//(B2MC02RSP) Стартовая координата штока РБ2
#define fEM_B2MV02RSP	 BUFFER[2291]	//(B2MV02RSP) Стартовая скорость движения  РБ2
#define idfEM_B2MV02RSP	 678	//(B2MV02RSP) Стартовая скорость движения  РБ2
#define fEM_A3MC01RSP	 BUFFER[2296]	//(A3MC01RSP) Стартовая координата  ИС1
#define idfEM_A3MC01RSP	 679	//(A3MC01RSP) Стартовая координата  ИС1
#define fEM_A3MV01RSP	 BUFFER[2301]	//(A3MV01RSP) Стартовая скорость движения  ИС1
#define idfEM_A3MV01RSP	 680	//(A3MV01RSP) Стартовая скорость движения  ИС1
#define fEM_A3MC02RSP	 BUFFER[2306]	//(A3MC02RSP) Стартовая координата штока ИС1
#define idfEM_A3MC02RSP	 681	//(A3MC02RSP) Стартовая координата штока ИС1
#define fEM_A3MV02RSP	 BUFFER[2311]	//(A3MV02RSP) Стартовая скорость движения  ИС1
#define idfEM_A3MV02RSP	 682	//(A3MV02RSP) Стартовая скорость движения  ИС1
#define fEM_B3MC01RSP	 BUFFER[2316]	//(B3MC01RSP) Стартовая координата  ИС2
#define idfEM_B3MC01RSP	 683	//(B3MC01RSP) Стартовая координата  ИС2
#define fEM_B3MV01RSP	 BUFFER[2321]	//(B3MV01RSP) Стартовая скорость движения  ИС2
#define idfEM_B3MV01RSP	 684	//(B3MV01RSP) Стартовая скорость движения  ИС2
#define fEM_B3MC02RSP	 BUFFER[2326]	//(B3MC02RSP) Стартовая координата штока ИС2
#define idfEM_B3MC02RSP	 685	//(B3MC02RSP) Стартовая координата штока ИС2
#define fEM_B3MV02RSP	 BUFFER[2331]	//(B3MV02RSP) Стартовая скорость движения  ИС2
#define idfEM_B3MV02RSP	 686	//(B3MV02RSP) Стартовая скорость движения  ИС2
#define fEM_B8MC01RSP	 BUFFER[2336]	//(B8MC01RSP) Стартовая координата АЗ2
#define idfEM_B8MC01RSP	 687	//(B8MC01RSP) Стартовая координата АЗ2
#define fEM_B8MV01RSP	 BUFFER[2341]	//(B8MV01RSP) Стартовая скорость АЗ2
#define idfEM_B8MV01RSP	 688	//(B8MV01RSP) Стартовая скорость АЗ2
#define fEM_A8MC01RSP	 BUFFER[2346]	//(A8MC01RSP) Стартовая координата ДС2
#define idfEM_A8MC01RSP	 689	//(A8MC01RSP) Стартовая координата ДС2
#define fEM_A8MV01RSP	 BUFFER[2351]	//(A8MV01RSP) Стартовая скорость ДС2
#define idfEM_A8MV01RSP	 690	//(A8MV01RSP) Стартовая скорость ДС2
#define fEM_A6MC01RSP	 BUFFER[2356]	//(A6MC01RSP) Стартовая координата БЗ1
#define idfEM_A6MC01RSP	 691	//(A6MC01RSP) Стартовая координата БЗ1
#define fEM_A6MV01RSP	 BUFFER[2361]	//(A6MV01RSP) Стартовая скорость БЗ1
#define idfEM_A6MV01RSP	 692	//(A6MV01RSP) Стартовая скорость БЗ1
#define fEM_B6MC01RSP	 BUFFER[2366]	//(B6MC01RSP) Стартовая координата БЗ2
#define idfEM_B6MC01RSP	 693	//(B6MC01RSP) Стартовая координата БЗ2
#define fEM_B6MV01RSP	 BUFFER[2371]	//(B6MV01RSP) Стартовая скорость БЗ2
#define idfEM_B6MV01RSP	 694	//(B6MV01RSP) Стартовая скорость БЗ2
#define fEM_R3UC01RSP	 BUFFER[2376]	//(R3UC01RSP) Стартовая координата Гомогенных дверей
#define idfEM_R3UC01RSP	 695	//(R3UC01RSP) Стартовая координата Гомогенных дверей
#define fEM_R3UV01RSP	 BUFFER[2381]	//(R3UV01RSP) Стартовая скорость Гомогенных дверей
#define idfEM_R3UV01RSP	 696	//(R3UV01RSP) Стартовая скорость Гомогенных дверей
#define fEM_R5UC01RSP	 BUFFER[2386]	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define idfEM_R5UC01RSP	 697	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define fEM_R5UV01RSP	 BUFFER[2391]	//(R5UV01RSP) Стартовая скорость Ворот отстойной зоны
#define idfEM_R5UV01RSP	 698	//(R5UV01RSP) Стартовая скорость Ворот отстойной зоны
#define fEM_R6UC01RSP	 BUFFER[2396]	//(R6UC01RSP) Стартовая координата Кран-балки
#define idfEM_R6UC01RSP	 699	//(R6UC01RSP) Стартовая координата Кран-балки
#define fEM_R6UV01RSP	 BUFFER[2401]	//(R6UV01RSP) Стартовая скорость Кран-балки
#define idfEM_R6UV01RSP	 700	//(R6UV01RSP) Стартовая скорость Кран-балки
#define fEM_R2MC01RSP	 BUFFER[2406]	//(R2MC01RSP) Стартовая координата МДЗ2
#define idfEM_R2MC01RSP	 701	//(R2MC01RSP) Стартовая координата МДЗ2
#define fEM_R2MV01RSP	 BUFFER[2411]	//(R2MV01RSP) Стартовая скорость МДЗ2
#define idfEM_R2MV01RSP	 702	//(R2MV01RSP) Стартовая скорость МДЗ2
#define fEM_R1MC01RSP	 BUFFER[2416]	//(R1MC01RSP) Стартовая координата МДЗ1
#define idfEM_R1MC01RSP	 703	//(R1MC01RSP) Стартовая координата МДЗ1
#define fEM_R1MV01RSP	 BUFFER[2421]	//(R1MV01RSP) Стартовая скорость МДЗ1
#define idfEM_R1MV01RSP	 704	//(R1MV01RSP) Стартовая скорость МДЗ1
#define fEM_A5MC01RSP	 BUFFER[2426]	//(A5MC01RSP) Стартовая координата НЛ1
#define idfEM_A5MC01RSP	 705	//(A5MC01RSP) Стартовая координата НЛ1
#define fEM_A5MV01RSP	 BUFFER[2431]	//(A5MV01RSP) Стартовая скорость НЛ1
#define idfEM_A5MV01RSP	 706	//(A5MV01RSP) Стартовая скорость НЛ1
#define fEM_B5MC01RSP	 BUFFER[2436]	//(B5MC01RSP) Стартовая координата НЛ2
#define idfEM_B5MC01RSP	 707	//(B5MC01RSP) Стартовая координата НЛ2
#define fEM_B5MV01RSP	 BUFFER[2441]	//(B5MV01RSP) Стартовая скорость НЛ2
#define idfEM_B5MV01RSP	 708	//(B5MV01RSP) Стартовая скорость НЛ2
#define fEM_A9MC01RSP	 BUFFER[2446]	//(A9MC01RSP) Стартовая координата НИ ДС1
#define idfEM_A9MC01RSP	 709	//(A9MC01RSP) Стартовая координата НИ ДС1
#define fEM_A9MV01RSP	 BUFFER[2451]	//(A9MV01RSP) Стартовая скорость НИ ДС1
#define idfEM_A9MV01RSP	 710	//(A9MV01RSP) Стартовая скорость НИ ДС1
#define fEM_B9MC01RSP	 BUFFER[2456]	//(B9MC01RSP) Стартовая координата НИ ДС2
#define idfEM_B9MC01RSP	 711	//(B9MC01RSP) Стартовая координата НИ ДС2
#define fEM_B9MV01RSP	 BUFFER[2461]	//(B9MV01RSP) Стартовая скорость НИ ДС2
#define idfEM_B9MV01RSP	 712	//(B9MV01RSP) Стартовая скорость НИ ДС2
#define fEM_A4MC01RSP	 BUFFER[2466]	//(A4MC01RSP) Стартовая координата НИ1
#define idfEM_A4MC01RSP	 713	//(A4MC01RSP) Стартовая координата НИ1
#define fEM_A4MV01RSP	 BUFFER[2471]	//(A4MV01RSP) Стартовая скорость НИ1
#define idfEM_A4MV01RSP	 714	//(A4MV01RSP) Стартовая скорость НИ1
#define fEM_B4MC01RSP	 BUFFER[2476]	//(B4MC01RSP) Стартовая координата НИ2
#define idfEM_B4MC01RSP	 715	//(B4MC01RSP) Стартовая координата НИ2
#define fEM_B4MV01RSP	 BUFFER[2481]	//(B4MV01RSP) Стартовая скорость НИ2
#define idfEM_B4MV01RSP	 716	//(B4MV01RSP) Стартовая скорость НИ2
#define fEM_R4MC01RSP	 BUFFER[2486]	//(R4MC01RSP) Стартовая координата тележки
#define idfEM_R4MC01RSP	 717	//(R4MC01RSP) Стартовая координата тележки
#define fEM_R4MV01RSP	 BUFFER[2491]	//(R4MV01RSP) Стартовая скорость тележки
#define idfEM_R4MV01RSP	 718	//(R4MV01RSP) Стартовая скорость тележки
#define fEM_A1MV01RC1	 BUFFER[2496]	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define idfEM_A1MV01RC1	 719	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define iEM_TERB7MS31LIM	 BUFFER[2501]	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define idiEM_TERB7MS31LIM	 720	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define iEM_TERA7MS31LIM	 BUFFER[2504]	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define idiEM_TERA7MS31LIM	 721	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define fEM_R7UX03RSS	 BUFFER[2507]	//(R7UX03RSS) X-координата камеры R7IN13 см
#define idfEM_R7UX03RSS	 722	//(R7UX03RSS) X-координата камеры R7IN13 см
#define fEM_R7UY03RSS	 BUFFER[2512]	//(R7UY03RSS) Y-координата камеры R7IN13 (см)
#define idfEM_R7UY03RSS	 723	//(R7UY03RSS) Y-координата камеры R7IN13 (см)
#define fEM_R7UY00RSS	 BUFFER[2517]	//(R7UY00RSS) Y-координата АЗ1 см
#define idfEM_R7UY00RSS	 724	//(R7UY00RSS) Y-координата АЗ1 см
#define iEM_TERA6VS12LIM	 BUFFER[2522]	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define idiEM_TERA6VS12LIM	 725	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define iEM_TERA6VS22LIM	 BUFFER[2525]	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define idiEM_TERA6VS22LIM	 726	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define iEM_TERB6VS12LIM	 BUFFER[2528]	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define idiEM_TERB6VS12LIM	 727	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define iEM_TERB6VS22LIM	 BUFFER[2531]	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define idiEM_TERB6VS22LIM	 728	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define iEM_TERA5VS22LIM	 BUFFER[2534]	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define idiEM_TERA5VS22LIM	 729	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define iEM_TERA5VS12LIM	 BUFFER[2537]	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define idiEM_TERA5VS12LIM	 730	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define iEM_TERB5VS12LIM	 BUFFER[2540]	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define idiEM_TERB5VS12LIM	 731	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define iEM_TERB5VS22LIM	 BUFFER[2543]	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define idiEM_TERB5VS22LIM	 732	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define iEM_TERR1VS12LIM	 BUFFER[2546]	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define idiEM_TERR1VS12LIM	 733	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define iEM_TERR1VS22LIM	 BUFFER[2549]	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define idiEM_TERR1VS22LIM	 734	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define iEM_TERR2VS12LIM	 BUFFER[2552]	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define idiEM_TERR2VS12LIM	 735	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define iEM_TERR2VS22LIM	 BUFFER[2555]	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define idiEM_TERR2VS22LIM	 736	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define iEM_TERR4VS12LDU	 BUFFER[2558]	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS12LDU	 737	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define iEM_TERR4VS22LDU	 BUFFER[2561]	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS22LDU	 738	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define bFirstEnterFlag	 BUFFER[2564]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 739	//(bFirstEnterFlag) 
#define internal1_m1118_Out10	 BUFFER[2566]	//(internal1_m1118_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1118_Out10	 740	//(internal1_m1118_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1117_Out10	 BUFFER[2568]	//(internal1_m1117_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1117_Out10	 741	//(internal1_m1117_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m943_Out10	 BUFFER[2570]	//(internal1_m943_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m943_Out10	 742	//(internal1_m943_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m942_Out10	 BUFFER[2572]	//(internal1_m942_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m942_Out10	 743	//(internal1_m942_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m941_Out10	 BUFFER[2574]	//(internal1_m941_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m941_Out10	 744	//(internal1_m941_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m940_Out10	 BUFFER[2576]	//(internal1_m940_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m940_Out10	 745	//(internal1_m940_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m691_Out10	 BUFFER[2578]	//(internal1_m691_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m691_Out10	 746	//(internal1_m691_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m690_Out10	 BUFFER[2580]	//(internal1_m690_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m690_Out10	 747	//(internal1_m690_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m669_Out10	 BUFFER[2582]	//(internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m669_Out10	 748	//(internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m668_Out10	 BUFFER[2584]	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m668_Out10	 749	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m689_Out10	 BUFFER[2586]	//(internal1_m689_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m689_Out10	 750	//(internal1_m689_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m688_Out10	 BUFFER[2588]	//(internal1_m688_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m688_Out10	 751	//(internal1_m688_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m667_Out10	 BUFFER[2590]	//(internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m667_Out10	 752	//(internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m666_Out10	 BUFFER[2592]	//(internal1_m666_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m666_Out10	 753	//(internal1_m666_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m527_Out10	 BUFFER[2594]	//(internal1_m527_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m527_Out10	 754	//(internal1_m527_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m545_Out10	 BUFFER[2596]	//(internal1_m545_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m545_Out10	 755	//(internal1_m545_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m409_Out10	 BUFFER[2598]	//(internal1_m409_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m409_Out10	 756	//(internal1_m409_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m486_q0	 BUFFER[2600]	//(internal1_m486_q0) q0 - внутренний параметр
#define idinternal1_m486_q0	 757	//(internal1_m486_q0) q0 - внутренний параметр
#define internal1_m487_q0	 BUFFER[2602]	//(internal1_m487_q0) q0 - внутренний параметр
#define idinternal1_m487_q0	 758	//(internal1_m487_q0) q0 - внутренний параметр
#define internal1_m472_q0	 BUFFER[2604]	//(internal1_m472_q0) q0 - внутренний параметр
#define idinternal1_m472_q0	 759	//(internal1_m472_q0) q0 - внутренний параметр
#define internal1_m473_q0	 BUFFER[2606]	//(internal1_m473_q0) q0 - внутренний параметр
#define idinternal1_m473_q0	 760	//(internal1_m473_q0) q0 - внутренний параметр
#define internal1_m642_tx	 BUFFER[2608]	//(internal1_m642_tx) tx - время накопленное сек
#define idinternal1_m642_tx	 761	//(internal1_m642_tx) tx - время накопленное сек
#define internal1_m642_y0	 BUFFER[2613]	//(internal1_m642_y0) y0
#define idinternal1_m642_y0	 762	//(internal1_m642_y0) y0
#define internal1_m630_tx	 BUFFER[2614]	//(internal1_m630_tx) tx - время накопленное сек
#define idinternal1_m630_tx	 763	//(internal1_m630_tx) tx - время накопленное сек
#define internal1_m630_y0	 BUFFER[2619]	//(internal1_m630_y0) y0
#define idinternal1_m630_y0	 764	//(internal1_m630_y0) y0
#define internal1_m616_tx	 BUFFER[2620]	//(internal1_m616_tx) tx - время накопленное сек
#define idinternal1_m616_tx	 765	//(internal1_m616_tx) tx - время накопленное сек
#define internal1_m616_y0	 BUFFER[2625]	//(internal1_m616_y0) y0
#define idinternal1_m616_y0	 766	//(internal1_m616_y0) y0
#define internal1_m614_tx	 BUFFER[2626]	//(internal1_m614_tx) tx - время накопленное сек
#define idinternal1_m614_tx	 767	//(internal1_m614_tx) tx - время накопленное сек
#define internal1_m614_y0	 BUFFER[2631]	//(internal1_m614_y0) y0
#define idinternal1_m614_y0	 768	//(internal1_m614_y0) y0
#define internal1_m206_Out10	 BUFFER[2632]	//(internal1_m206_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m206_Out10	 769	//(internal1_m206_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m224_Out10	 BUFFER[2634]	//(internal1_m224_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m224_Out10	 770	//(internal1_m224_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m41_Out10	 BUFFER[2636]	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m41_Out10	 771	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m56_Out10	 BUFFER[2638]	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m56_Out10	 772	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1241_Out10	 BUFFER[2640]	//(internal1_m1241_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1241_Out10	 773	//(internal1_m1241_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1238_Out10	 BUFFER[2642]	//(internal1_m1238_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1238_Out10	 774	//(internal1_m1238_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1237_Out10	 BUFFER[2644]	//(internal1_m1237_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1237_Out10	 775	//(internal1_m1237_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1240_Xtek0	 BUFFER[2646]	//(internal1_m1240_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m1240_Xtek0	 776	//(internal1_m1240_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m1226_Xtek0	 BUFFER[2651]	//(internal1_m1226_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m1226_Xtek0	 777	//(internal1_m1226_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m1227_Out10	 BUFFER[2656]	//(internal1_m1227_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1227_Out10	 778	//(internal1_m1227_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1224_Out10	 BUFFER[2658]	//(internal1_m1224_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1224_Out10	 779	//(internal1_m1224_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1223_Out10	 BUFFER[2660]	//(internal1_m1223_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1223_Out10	 780	//(internal1_m1223_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m981_Out10	 BUFFER[2662]	//(internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m981_Out10	 781	//(internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m962_Out10	 BUFFER[2664]	//(internal1_m962_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m962_Out10	 782	//(internal1_m962_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m961_Out10	 BUFFER[2666]	//(internal1_m961_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m961_Out10	 783	//(internal1_m961_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m960_Out10	 BUFFER[2668]	//(internal1_m960_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m960_Out10	 784	//(internal1_m960_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1139_Out10	 BUFFER[2670]	//(internal1_m1139_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1139_Out10	 785	//(internal1_m1139_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1141_Out10	 BUFFER[2672]	//(internal1_m1141_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1141_Out10	 786	//(internal1_m1141_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1138_Out10	 BUFFER[2674]	//(internal1_m1138_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1138_Out10	 787	//(internal1_m1138_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1140_Out10	 BUFFER[2676]	//(internal1_m1140_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1140_Out10	 788	//(internal1_m1140_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1114_Out10	 BUFFER[2678]	//(internal1_m1114_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1114_Out10	 789	//(internal1_m1114_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1115_Out10	 BUFFER[2680]	//(internal1_m1115_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1115_Out10	 790	//(internal1_m1115_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1113_Out10	 BUFFER[2682]	//(internal1_m1113_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1113_Out10	 791	//(internal1_m1113_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1112_Out10	 BUFFER[2684]	//(internal1_m1112_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1112_Out10	 792	//(internal1_m1112_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m976_Out10	 BUFFER[2686]	//(internal1_m976_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m976_Out10	 793	//(internal1_m976_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m928_Out10	 BUFFER[2688]	//(internal1_m928_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m928_Out10	 794	//(internal1_m928_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m927_Out10	 BUFFER[2690]	//(internal1_m927_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m927_Out10	 795	//(internal1_m927_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m926_Out10	 BUFFER[2692]	//(internal1_m926_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m926_Out10	 796	//(internal1_m926_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m925_Out10	 BUFFER[2694]	//(internal1_m925_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m925_Out10	 797	//(internal1_m925_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m977_Out10	 BUFFER[2696]	//(internal1_m977_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m977_Out10	 798	//(internal1_m977_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m958_Out10	 BUFFER[2698]	//(internal1_m958_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m958_Out10	 799	//(internal1_m958_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1116_Out10	 BUFFER[2700]	//(internal1_m1116_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1116_Out10	 800	//(internal1_m1116_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m959_Out10	 BUFFER[2702]	//(internal1_m959_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m959_Out10	 801	//(internal1_m959_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m957_Out10	 BUFFER[2704]	//(internal1_m957_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m957_Out10	 802	//(internal1_m957_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m978_Out10	 BUFFER[2706]	//(internal1_m978_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m978_Out10	 803	//(internal1_m978_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m956_Out10	 BUFFER[2708]	//(internal1_m956_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m956_Out10	 804	//(internal1_m956_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m939_Out10	 BUFFER[2710]	//(internal1_m939_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m939_Out10	 805	//(internal1_m939_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m924_Out10	 BUFFER[2712]	//(internal1_m924_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m924_Out10	 806	//(internal1_m924_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m543_Out10	 BUFFER[2714]	//(internal1_m543_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m543_Out10	 807	//(internal1_m543_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m419_Xtek0	 BUFFER[2716]	//(internal1_m419_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m419_Xtek0	 808	//(internal1_m419_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m410_Out10	 BUFFER[2721]	//(internal1_m410_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m410_Out10	 809	//(internal1_m410_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m412_Out10	 BUFFER[2723]	//(internal1_m412_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m412_Out10	 810	//(internal1_m412_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m411_Out10	 BUFFER[2725]	//(internal1_m411_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m411_Out10	 811	//(internal1_m411_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1154_Out10	 BUFFER[2727]	//(internal1_m1154_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1154_Out10	 812	//(internal1_m1154_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1155_Out10	 BUFFER[2729]	//(internal1_m1155_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1155_Out10	 813	//(internal1_m1155_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1153_Out10	 BUFFER[2731]	//(internal1_m1153_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1153_Out10	 814	//(internal1_m1153_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m980_Out10	 BUFFER[2733]	//(internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m980_Out10	 815	//(internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m704_Out10	 BUFFER[2735]	//(internal1_m704_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m704_Out10	 816	//(internal1_m704_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m705_Out10	 BUFFER[2737]	//(internal1_m705_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m705_Out10	 817	//(internal1_m705_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m702_Out10	 BUFFER[2739]	//(internal1_m702_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m702_Out10	 818	//(internal1_m702_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m703_Out10	 BUFFER[2741]	//(internal1_m703_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m703_Out10	 819	//(internal1_m703_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m561_Out10	 BUFFER[2743]	//(internal1_m561_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m561_Out10	 820	//(internal1_m561_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m560_Out10	 BUFFER[2745]	//(internal1_m560_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m560_Out10	 821	//(internal1_m560_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1135_Xtek0	 BUFFER[2747]	//(internal1_m1135_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m1135_Xtek0	 822	//(internal1_m1135_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m1137_Xtek0	 BUFFER[2752]	//(internal1_m1137_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m1137_Xtek0	 823	//(internal1_m1137_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m701_Out10	 BUFFER[2757]	//(internal1_m701_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m701_Out10	 824	//(internal1_m701_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m685_Out10	 BUFFER[2759]	//(internal1_m685_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m685_Out10	 825	//(internal1_m685_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m665_Out10	 BUFFER[2761]	//(internal1_m665_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m665_Out10	 826	//(internal1_m665_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m684_Out10	 BUFFER[2763]	//(internal1_m684_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m684_Out10	 827	//(internal1_m684_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m664_Out10	 BUFFER[2765]	//(internal1_m664_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m664_Out10	 828	//(internal1_m664_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m337_Out10	 BUFFER[2767]	//(internal1_m337_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m337_Out10	 829	//(internal1_m337_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m336_Out10	 BUFFER[2769]	//(internal1_m336_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m336_Out10	 830	//(internal1_m336_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m321_Out10	 BUFFER[2771]	//(internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m321_Out10	 831	//(internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m320_Out10	 BUFFER[2773]	//(internal1_m320_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m320_Out10	 832	//(internal1_m320_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m562_Out10	 BUFFER[2775]	//(internal1_m562_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m562_Out10	 833	//(internal1_m562_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m350_Out10	 BUFFER[2777]	//(internal1_m350_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m350_Out10	 834	//(internal1_m350_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m334_Xtek0	 BUFFER[2779]	//(internal1_m334_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m334_Xtek0	 835	//(internal1_m334_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m349_Out10	 BUFFER[2784]	//(internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m349_Out10	 836	//(internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m347_Out10	 BUFFER[2786]	//(internal1_m347_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m347_Out10	 837	//(internal1_m347_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m327_Xtek0	 BUFFER[2788]	//(internal1_m327_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m327_Xtek0	 838	//(internal1_m327_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m348_Out10	 BUFFER[2793]	//(internal1_m348_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m348_Out10	 839	//(internal1_m348_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m319_Out10	 BUFFER[2795]	//(internal1_m319_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m319_Out10	 840	//(internal1_m319_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m335_Out10	 BUFFER[2797]	//(internal1_m335_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m335_Out10	 841	//(internal1_m335_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m431_Out10	 BUFFER[2799]	//(internal1_m431_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m431_Out10	 842	//(internal1_m431_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m432_Xtek0	 BUFFER[2801]	//(internal1_m432_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m432_Xtek0	 843	//(internal1_m432_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m430_Out10	 BUFFER[2806]	//(internal1_m430_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m430_Out10	 844	//(internal1_m430_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m429_Out10	 BUFFER[2808]	//(internal1_m429_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m429_Out10	 845	//(internal1_m429_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m428_Out10	 BUFFER[2810]	//(internal1_m428_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m428_Out10	 846	//(internal1_m428_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m979_Out10	 BUFFER[2812]	//(internal1_m979_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m979_Out10	 847	//(internal1_m979_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m150_Out10	 BUFFER[2814]	//(internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m150_Out10	 848	//(internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m149_Out10	 BUFFER[2816]	//(internal1_m149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m149_Out10	 849	//(internal1_m149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1102_Out10	 BUFFER[2818]	//(internal1_m1102_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1102_Out10	 850	//(internal1_m1102_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1093_Out10	 BUFFER[2820]	//(internal1_m1093_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1093_Out10	 851	//(internal1_m1093_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1082_tst	 BUFFER[2822]	//(internal1_m1082_tst) - массив времени фиксации стартовой мощности
#define idinternal1_m1082_tst	 852	//(internal1_m1082_tst) - массив времени фиксации стартовой мощности
#define internal1_m1082_trz	 BUFFER[2832]	//(internal1_m1082_trz) - массив времени фиксации очередного периода
#define idinternal1_m1082_trz	 853	//(internal1_m1082_trz) - массив времени фиксации очередного периода
#define internal1_m1082_N1	 BUFFER[2842]	//(internal1_m1082_N1) - массив значения мощности в начале замера
#define idinternal1_m1082_N1	 854	//(internal1_m1082_N1) - массив значения мощности в начале замера
#define internal1_m1082_N2	 BUFFER[2852]	//(internal1_m1082_N2) - массив значения мощности в конце замера
#define idinternal1_m1082_N2	 855	//(internal1_m1082_N2) - массив значения мощности в конце замера
#define internal1_m1082_Period0	 BUFFER[2862]	//(internal1_m1082_Period0) Per - Период разгона РУ
#define idinternal1_m1082_Period0	 856	//(internal1_m1082_Period0) Per - Период разгона РУ
#define internal1_m1082_MyFirstEnterFlag	 BUFFER[2867]	//(internal1_m1082_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m1082_MyFirstEnterFlag	 857	//(internal1_m1082_MyFirstEnterFlag)  FirstEnterFlag
#define internal1_m1048_Nk	 BUFFER[2869]	//(internal1_m1048_Nk) Nk - ведущая камера
#define idinternal1_m1048_Nk	 858	//(internal1_m1048_Nk) Nk - ведущая камера
#define internal1_m1043_Out10	 BUFFER[2872]	//(internal1_m1043_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1043_Out10	 859	//(internal1_m1043_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1035_Out10	 BUFFER[2874]	//(internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1035_Out10	 860	//(internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1024_tst	 BUFFER[2876]	//(internal1_m1024_tst) - массив времени фиксации стартовой мощности
#define idinternal1_m1024_tst	 861	//(internal1_m1024_tst) - массив времени фиксации стартовой мощности
#define internal1_m1024_trz	 BUFFER[2886]	//(internal1_m1024_trz) - массив времени фиксации очередного периода
#define idinternal1_m1024_trz	 862	//(internal1_m1024_trz) - массив времени фиксации очередного периода
#define internal1_m1024_N1	 BUFFER[2896]	//(internal1_m1024_N1) - массив значения мощности в начале замера
#define idinternal1_m1024_N1	 863	//(internal1_m1024_N1) - массив значения мощности в начале замера
#define internal1_m1024_N2	 BUFFER[2906]	//(internal1_m1024_N2) - массив значения мощности в конце замера
#define idinternal1_m1024_N2	 864	//(internal1_m1024_N2) - массив значения мощности в конце замера
#define internal1_m1024_Period0	 BUFFER[2916]	//(internal1_m1024_Period0) Per - Период разгона РУ
#define idinternal1_m1024_Period0	 865	//(internal1_m1024_Period0) Per - Период разгона РУ
#define internal1_m1024_MyFirstEnterFlag	 BUFFER[2921]	//(internal1_m1024_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m1024_MyFirstEnterFlag	 866	//(internal1_m1024_MyFirstEnterFlag)  FirstEnterFlag
#define internal1_m994_Nk	 BUFFER[2923]	//(internal1_m994_Nk) Nk - ведущая камера
#define idinternal1_m994_Nk	 867	//(internal1_m994_Nk) Nk - ведущая камера
#define internal1_m915_Out10	 BUFFER[2926]	//(internal1_m915_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m915_Out10	 868	//(internal1_m915_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m905_Out10	 BUFFER[2928]	//(internal1_m905_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m905_Out10	 869	//(internal1_m905_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m896_tst	 BUFFER[2930]	//(internal1_m896_tst) - массив времени фиксации стартовой мощности
#define idinternal1_m896_tst	 870	//(internal1_m896_tst) - массив времени фиксации стартовой мощности
#define internal1_m896_trz	 BUFFER[2940]	//(internal1_m896_trz) - массив времени фиксации очередного периода
#define idinternal1_m896_trz	 871	//(internal1_m896_trz) - массив времени фиксации очередного периода
#define internal1_m896_N1	 BUFFER[2950]	//(internal1_m896_N1) - массив значения мощности в начале замера
#define idinternal1_m896_N1	 872	//(internal1_m896_N1) - массив значения мощности в начале замера
#define internal1_m896_N2	 BUFFER[2960]	//(internal1_m896_N2) - массив значения мощности в конце замера
#define idinternal1_m896_N2	 873	//(internal1_m896_N2) - массив значения мощности в конце замера
#define internal1_m896_Period0	 BUFFER[2970]	//(internal1_m896_Period0) Per - Период разгона РУ
#define idinternal1_m896_Period0	 874	//(internal1_m896_Period0) Per - Период разгона РУ
#define internal1_m896_MyFirstEnterFlag	 BUFFER[2975]	//(internal1_m896_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m896_MyFirstEnterFlag	 875	//(internal1_m896_MyFirstEnterFlag)  FirstEnterFlag
#define internal1_m862_Nk	 BUFFER[2977]	//(internal1_m862_Nk) Nk - ведущая камера
#define idinternal1_m862_Nk	 876	//(internal1_m862_Nk) Nk - ведущая камера
#define internal1_m849_Out10	 BUFFER[2980]	//(internal1_m849_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m849_Out10	 877	//(internal1_m849_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m838_Out10	 BUFFER[2982]	//(internal1_m838_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m838_Out10	 878	//(internal1_m838_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m841_tst	 BUFFER[2984]	//(internal1_m841_tst) - массив времени фиксации стартовой мощности
#define idinternal1_m841_tst	 879	//(internal1_m841_tst) - массив времени фиксации стартовой мощности
#define internal1_m841_trz	 BUFFER[2994]	//(internal1_m841_trz) - массив времени фиксации очередного периода
#define idinternal1_m841_trz	 880	//(internal1_m841_trz) - массив времени фиксации очередного периода
#define internal1_m841_N1	 BUFFER[3004]	//(internal1_m841_N1) - массив значения мощности в начале замера
#define idinternal1_m841_N1	 881	//(internal1_m841_N1) - массив значения мощности в начале замера
#define internal1_m841_N2	 BUFFER[3014]	//(internal1_m841_N2) - массив значения мощности в конце замера
#define idinternal1_m841_N2	 882	//(internal1_m841_N2) - массив значения мощности в конце замера
#define internal1_m841_Period0	 BUFFER[3024]	//(internal1_m841_Period0) Per - Период разгона РУ
#define idinternal1_m841_Period0	 883	//(internal1_m841_Period0) Per - Период разгона РУ
#define internal1_m841_MyFirstEnterFlag	 BUFFER[3029]	//(internal1_m841_MyFirstEnterFlag)  FirstEnterFlag
#define idinternal1_m841_MyFirstEnterFlag	 884	//(internal1_m841_MyFirstEnterFlag)  FirstEnterFlag
#define internal1_m804_Nk	 BUFFER[3031]	//(internal1_m804_Nk) Nk - ведущая камера
#define idinternal1_m804_Nk	 885	//(internal1_m804_Nk) Nk - ведущая камера
#define internal1_m195_tx	 BUFFER[3034]	//(internal1_m195_tx) tx - внутренний параметр
#define idinternal1_m195_tx	 886	//(internal1_m195_tx) tx - внутренний параметр
#define internal1_m25_tx	 BUFFER[3037]	//(internal1_m25_tx) tx - внутренний параметр
#define idinternal1_m25_tx	 887	//(internal1_m25_tx) tx - внутренний параметр
#define internal1_m476_Pav0	 BUFFER[3040]	//(internal1_m476_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m476_Pav0	 888	//(internal1_m476_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m476_Zav0	 BUFFER[3042]	//(internal1_m476_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m476_Zav0	 889	//(internal1_m476_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m476_Pv0	 BUFFER[3044]	//(internal1_m476_Pv0)  - Пер. выключатель механизма
#define idinternal1_m476_Pv0	 890	//(internal1_m476_Pv0)  - Пер. выключатель механизма
#define internal1_m476_Zv0	 BUFFER[3046]	//(internal1_m476_Zv0)  - Зад. выключатель механизма
#define idinternal1_m476_Zv0	 891	//(internal1_m476_Zv0)  - Зад. выключатель механизма
#define internal1_m476_RA00	 BUFFER[3048]	//(internal1_m476_RA00)  - последнее задание вперед
#define idinternal1_m476_RA00	 892	//(internal1_m476_RA00)  - последнее задание вперед
#define internal1_m476_RA10	 BUFFER[3050]	//(internal1_m476_RA10)  - последнее задание назад
#define idinternal1_m476_RA10	 893	//(internal1_m476_RA10)  - последнее задание назад
#define internal1_m476_MyFirstEnterFlag	 BUFFER[3052]	//(internal1_m476_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m476_MyFirstEnterFlag	 894	//(internal1_m476_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m490_Pav0	 BUFFER[3054]	//(internal1_m490_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m490_Pav0	 895	//(internal1_m490_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m490_Zav0	 BUFFER[3056]	//(internal1_m490_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m490_Zav0	 896	//(internal1_m490_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m490_Pv0	 BUFFER[3058]	//(internal1_m490_Pv0)  - Пер. выключатель механизма
#define idinternal1_m490_Pv0	 897	//(internal1_m490_Pv0)  - Пер. выключатель механизма
#define internal1_m490_Zv0	 BUFFER[3060]	//(internal1_m490_Zv0)  - Зад. выключатель механизма
#define idinternal1_m490_Zv0	 898	//(internal1_m490_Zv0)  - Зад. выключатель механизма
#define internal1_m490_RA00	 BUFFER[3062]	//(internal1_m490_RA00)  - последнее задание вперед
#define idinternal1_m490_RA00	 899	//(internal1_m490_RA00)  - последнее задание вперед
#define internal1_m490_RA10	 BUFFER[3064]	//(internal1_m490_RA10)  - последнее задание назад
#define idinternal1_m490_RA10	 900	//(internal1_m490_RA10)  - последнее задание назад
#define internal1_m490_MyFirstEnterFlag	 BUFFER[3066]	//(internal1_m490_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m490_MyFirstEnterFlag	 901	//(internal1_m490_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m478_Pav0	 BUFFER[3068]	//(internal1_m478_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m478_Pav0	 902	//(internal1_m478_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m478_Zav0	 BUFFER[3070]	//(internal1_m478_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m478_Zav0	 903	//(internal1_m478_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m478_Pv0	 BUFFER[3072]	//(internal1_m478_Pv0)  - Пер. выключатель механизма
#define idinternal1_m478_Pv0	 904	//(internal1_m478_Pv0)  - Пер. выключатель механизма
#define internal1_m478_Zv0	 BUFFER[3074]	//(internal1_m478_Zv0)  - Зад. выключатель механизма
#define idinternal1_m478_Zv0	 905	//(internal1_m478_Zv0)  - Зад. выключатель механизма
#define internal1_m478_RA00	 BUFFER[3076]	//(internal1_m478_RA00)  - последнее задание вперед
#define idinternal1_m478_RA00	 906	//(internal1_m478_RA00)  - последнее задание вперед
#define internal1_m478_RA10	 BUFFER[3078]	//(internal1_m478_RA10)  - последнее задание назад
#define idinternal1_m478_RA10	 907	//(internal1_m478_RA10)  - последнее задание назад
#define internal1_m478_MyFirstEnterFlag	 BUFFER[3080]	//(internal1_m478_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m478_MyFirstEnterFlag	 908	//(internal1_m478_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m621_Pav0	 BUFFER[3082]	//(internal1_m621_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m621_Pav0	 909	//(internal1_m621_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m621_Zav0	 BUFFER[3084]	//(internal1_m621_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m621_Zav0	 910	//(internal1_m621_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m621_Pv0	 BUFFER[3086]	//(internal1_m621_Pv0)  - Пер. выключатель механизма
#define idinternal1_m621_Pv0	 911	//(internal1_m621_Pv0)  - Пер. выключатель механизма
#define internal1_m621_Zv0	 BUFFER[3088]	//(internal1_m621_Zv0)  - Зад. выключатель механизма
#define idinternal1_m621_Zv0	 912	//(internal1_m621_Zv0)  - Зад. выключатель механизма
#define internal1_m621_RA00	 BUFFER[3090]	//(internal1_m621_RA00)  - последнее задание вперед
#define idinternal1_m621_RA00	 913	//(internal1_m621_RA00)  - последнее задание вперед
#define internal1_m621_RA10	 BUFFER[3092]	//(internal1_m621_RA10)  - последнее задание назад
#define idinternal1_m621_RA10	 914	//(internal1_m621_RA10)  - последнее задание назад
#define internal1_m621_MyFirstEnterFlag	 BUFFER[3094]	//(internal1_m621_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m621_MyFirstEnterFlag	 915	//(internal1_m621_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m618_Pav0	 BUFFER[3096]	//(internal1_m618_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m618_Pav0	 916	//(internal1_m618_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m618_Zav0	 BUFFER[3098]	//(internal1_m618_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m618_Zav0	 917	//(internal1_m618_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m618_Pv0	 BUFFER[3100]	//(internal1_m618_Pv0)  - Пер. выключатель механизма
#define idinternal1_m618_Pv0	 918	//(internal1_m618_Pv0)  - Пер. выключатель механизма
#define internal1_m618_Zv0	 BUFFER[3102]	//(internal1_m618_Zv0)  - Зад. выключатель механизма
#define idinternal1_m618_Zv0	 919	//(internal1_m618_Zv0)  - Зад. выключатель механизма
#define internal1_m618_RA00	 BUFFER[3104]	//(internal1_m618_RA00)  - последнее задание вперед
#define idinternal1_m618_RA00	 920	//(internal1_m618_RA00)  - последнее задание вперед
#define internal1_m618_RA10	 BUFFER[3106]	//(internal1_m618_RA10)  - последнее задание назад
#define idinternal1_m618_RA10	 921	//(internal1_m618_RA10)  - последнее задание назад
#define internal1_m618_MyFirstEnterFlag	 BUFFER[3108]	//(internal1_m618_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m618_MyFirstEnterFlag	 922	//(internal1_m618_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m604_Pav0	 BUFFER[3110]	//(internal1_m604_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m604_Pav0	 923	//(internal1_m604_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m604_Zav0	 BUFFER[3112]	//(internal1_m604_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m604_Zav0	 924	//(internal1_m604_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m604_Pv0	 BUFFER[3114]	//(internal1_m604_Pv0)  - Пер. выключатель механизма
#define idinternal1_m604_Pv0	 925	//(internal1_m604_Pv0)  - Пер. выключатель механизма
#define internal1_m604_Zv0	 BUFFER[3116]	//(internal1_m604_Zv0)  - Зад. выключатель механизма
#define idinternal1_m604_Zv0	 926	//(internal1_m604_Zv0)  - Зад. выключатель механизма
#define internal1_m604_RA00	 BUFFER[3118]	//(internal1_m604_RA00)  - последнее задание вперед
#define idinternal1_m604_RA00	 927	//(internal1_m604_RA00)  - последнее задание вперед
#define internal1_m604_RA10	 BUFFER[3120]	//(internal1_m604_RA10)  - последнее задание назад
#define idinternal1_m604_RA10	 928	//(internal1_m604_RA10)  - последнее задание назад
#define internal1_m604_MyFirstEnterFlag	 BUFFER[3122]	//(internal1_m604_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m604_MyFirstEnterFlag	 929	//(internal1_m604_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m603_Pav0	 BUFFER[3124]	//(internal1_m603_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m603_Pav0	 930	//(internal1_m603_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m603_Zav0	 BUFFER[3126]	//(internal1_m603_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m603_Zav0	 931	//(internal1_m603_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m603_Pv0	 BUFFER[3128]	//(internal1_m603_Pv0)  - Пер. выключатель механизма
#define idinternal1_m603_Pv0	 932	//(internal1_m603_Pv0)  - Пер. выключатель механизма
#define internal1_m603_Zv0	 BUFFER[3130]	//(internal1_m603_Zv0)  - Зад. выключатель механизма
#define idinternal1_m603_Zv0	 933	//(internal1_m603_Zv0)  - Зад. выключатель механизма
#define internal1_m603_RA00	 BUFFER[3132]	//(internal1_m603_RA00)  - последнее задание вперед
#define idinternal1_m603_RA00	 934	//(internal1_m603_RA00)  - последнее задание вперед
#define internal1_m603_RA10	 BUFFER[3134]	//(internal1_m603_RA10)  - последнее задание назад
#define idinternal1_m603_RA10	 935	//(internal1_m603_RA10)  - последнее задание назад
#define internal1_m603_MyFirstEnterFlag	 BUFFER[3136]	//(internal1_m603_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m603_MyFirstEnterFlag	 936	//(internal1_m603_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m650_y0	 BUFFER[3138]	//(internal1_m650_y0) y0 - внутренний параметр
#define idinternal1_m650_y0	 937	//(internal1_m650_y0) y0 - внутренний параметр
#define internal1_m798_Chim0	 BUFFER[3143]	//(internal1_m798_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m798_Chim0	 938	//(internal1_m798_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m790_Chim0	 BUFFER[3148]	//(internal1_m790_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m790_Chim0	 939	//(internal1_m790_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m783_Chim0	 BUFFER[3153]	//(internal1_m783_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m783_Chim0	 940	//(internal1_m783_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m775_Chim0	 BUFFER[3158]	//(internal1_m775_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m775_Chim0	 941	//(internal1_m775_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m767_Chim0	 BUFFER[3163]	//(internal1_m767_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m767_Chim0	 942	//(internal1_m767_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m760_Chim0	 BUFFER[3168]	//(internal1_m760_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m760_Chim0	 943	//(internal1_m760_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m752_Chim0	 BUFFER[3173]	//(internal1_m752_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m752_Chim0	 944	//(internal1_m752_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m744_Chim0	 BUFFER[3178]	//(internal1_m744_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m744_Chim0	 945	//(internal1_m744_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m737_Chim0	 BUFFER[3183]	//(internal1_m737_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m737_Chim0	 946	//(internal1_m737_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m729_Chim0	 BUFFER[3188]	//(internal1_m729_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m729_Chim0	 947	//(internal1_m729_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m721_Chim0	 BUFFER[3193]	//(internal1_m721_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m721_Chim0	 948	//(internal1_m721_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m714_Chim0	 BUFFER[3198]	//(internal1_m714_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m714_Chim0	 949	//(internal1_m714_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m590_Pav0	 BUFFER[3203]	//(internal1_m590_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m590_Pav0	 950	//(internal1_m590_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m590_Zav0	 BUFFER[3205]	//(internal1_m590_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m590_Zav0	 951	//(internal1_m590_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m590_Pv0	 BUFFER[3207]	//(internal1_m590_Pv0)  - Пер. выключатель механизма
#define idinternal1_m590_Pv0	 952	//(internal1_m590_Pv0)  - Пер. выключатель механизма
#define internal1_m590_Zv0	 BUFFER[3209]	//(internal1_m590_Zv0)  - Зад. выключатель механизма
#define idinternal1_m590_Zv0	 953	//(internal1_m590_Zv0)  - Зад. выключатель механизма
#define internal1_m590_RA00	 BUFFER[3211]	//(internal1_m590_RA00)  - последнее задание вперед
#define idinternal1_m590_RA00	 954	//(internal1_m590_RA00)  - последнее задание вперед
#define internal1_m590_RA10	 BUFFER[3213]	//(internal1_m590_RA10)  - последнее задание назад
#define idinternal1_m590_RA10	 955	//(internal1_m590_RA10)  - последнее задание назад
#define internal1_m590_MyFirstEnterFlag	 BUFFER[3215]	//(internal1_m590_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m590_MyFirstEnterFlag	 956	//(internal1_m590_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m575_Pav0	 BUFFER[3217]	//(internal1_m575_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m575_Pav0	 957	//(internal1_m575_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m575_Zav0	 BUFFER[3219]	//(internal1_m575_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m575_Zav0	 958	//(internal1_m575_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m575_Pv0	 BUFFER[3221]	//(internal1_m575_Pv0)  - Пер. выключатель механизма
#define idinternal1_m575_Pv0	 959	//(internal1_m575_Pv0)  - Пер. выключатель механизма
#define internal1_m575_Zv0	 BUFFER[3223]	//(internal1_m575_Zv0)  - Зад. выключатель механизма
#define idinternal1_m575_Zv0	 960	//(internal1_m575_Zv0)  - Зад. выключатель механизма
#define internal1_m575_RA00	 BUFFER[3225]	//(internal1_m575_RA00)  - последнее задание вперед
#define idinternal1_m575_RA00	 961	//(internal1_m575_RA00)  - последнее задание вперед
#define internal1_m575_RA10	 BUFFER[3227]	//(internal1_m575_RA10)  - последнее задание назад
#define idinternal1_m575_RA10	 962	//(internal1_m575_RA10)  - последнее задание назад
#define internal1_m575_MyFirstEnterFlag	 BUFFER[3229]	//(internal1_m575_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m575_MyFirstEnterFlag	 963	//(internal1_m575_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m461_Pav0	 BUFFER[3231]	//(internal1_m461_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m461_Pav0	 964	//(internal1_m461_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m461_Zav0	 BUFFER[3233]	//(internal1_m461_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m461_Zav0	 965	//(internal1_m461_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m461_Pv0	 BUFFER[3235]	//(internal1_m461_Pv0)  - Пер. выключатель механизма
#define idinternal1_m461_Pv0	 966	//(internal1_m461_Pv0)  - Пер. выключатель механизма
#define internal1_m461_Zv0	 BUFFER[3237]	//(internal1_m461_Zv0)  - Зад. выключатель механизма
#define idinternal1_m461_Zv0	 967	//(internal1_m461_Zv0)  - Зад. выключатель механизма
#define internal1_m461_RA00	 BUFFER[3239]	//(internal1_m461_RA00)  - последнее задание вперед
#define idinternal1_m461_RA00	 968	//(internal1_m461_RA00)  - последнее задание вперед
#define internal1_m461_RA10	 BUFFER[3241]	//(internal1_m461_RA10)  - последнее задание назад
#define idinternal1_m461_RA10	 969	//(internal1_m461_RA10)  - последнее задание назад
#define internal1_m461_MyFirstEnterFlag	 BUFFER[3243]	//(internal1_m461_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m461_MyFirstEnterFlag	 970	//(internal1_m461_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m446_Pav0	 BUFFER[3245]	//(internal1_m446_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m446_Pav0	 971	//(internal1_m446_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m446_Zav0	 BUFFER[3247]	//(internal1_m446_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m446_Zav0	 972	//(internal1_m446_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m446_Pv0	 BUFFER[3249]	//(internal1_m446_Pv0)  - Пер. выключатель механизма
#define idinternal1_m446_Pv0	 973	//(internal1_m446_Pv0)  - Пер. выключатель механизма
#define internal1_m446_Zv0	 BUFFER[3251]	//(internal1_m446_Zv0)  - Зад. выключатель механизма
#define idinternal1_m446_Zv0	 974	//(internal1_m446_Zv0)  - Зад. выключатель механизма
#define internal1_m446_RA00	 BUFFER[3253]	//(internal1_m446_RA00)  - последнее задание вперед
#define idinternal1_m446_RA00	 975	//(internal1_m446_RA00)  - последнее задание вперед
#define internal1_m446_RA10	 BUFFER[3255]	//(internal1_m446_RA10)  - последнее задание назад
#define idinternal1_m446_RA10	 976	//(internal1_m446_RA10)  - последнее задание назад
#define internal1_m446_MyFirstEnterFlag	 BUFFER[3257]	//(internal1_m446_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m446_MyFirstEnterFlag	 977	//(internal1_m446_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m502_Pav0	 BUFFER[3259]	//(internal1_m502_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m502_Pav0	 978	//(internal1_m502_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m502_Zav0	 BUFFER[3261]	//(internal1_m502_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m502_Zav0	 979	//(internal1_m502_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m502_Pv0	 BUFFER[3263]	//(internal1_m502_Pv0)  - Пер. выключатель механизма
#define idinternal1_m502_Pv0	 980	//(internal1_m502_Pv0)  - Пер. выключатель механизма
#define internal1_m502_Zv0	 BUFFER[3265]	//(internal1_m502_Zv0)  - Зад. выключатель механизма
#define idinternal1_m502_Zv0	 981	//(internal1_m502_Zv0)  - Зад. выключатель механизма
#define internal1_m502_RA00	 BUFFER[3267]	//(internal1_m502_RA00)  - последнее задание вперед
#define idinternal1_m502_RA00	 982	//(internal1_m502_RA00)  - последнее задание вперед
#define internal1_m502_RA10	 BUFFER[3269]	//(internal1_m502_RA10)  - последнее задание назад
#define idinternal1_m502_RA10	 983	//(internal1_m502_RA10)  - последнее задание назад
#define internal1_m502_MyFirstEnterFlag	 BUFFER[3271]	//(internal1_m502_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m502_MyFirstEnterFlag	 984	//(internal1_m502_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m397_Pav0	 BUFFER[3273]	//(internal1_m397_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m397_Pav0	 985	//(internal1_m397_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m397_Zav0	 BUFFER[3275]	//(internal1_m397_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m397_Zav0	 986	//(internal1_m397_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m397_Pv0	 BUFFER[3277]	//(internal1_m397_Pv0)  - Пер. выключатель механизма
#define idinternal1_m397_Pv0	 987	//(internal1_m397_Pv0)  - Пер. выключатель механизма
#define internal1_m397_Zv0	 BUFFER[3279]	//(internal1_m397_Zv0)  - Зад. выключатель механизма
#define idinternal1_m397_Zv0	 988	//(internal1_m397_Zv0)  - Зад. выключатель механизма
#define internal1_m397_RA00	 BUFFER[3281]	//(internal1_m397_RA00)  - последнее задание вперед
#define idinternal1_m397_RA00	 989	//(internal1_m397_RA00)  - последнее задание вперед
#define internal1_m397_RA10	 BUFFER[3283]	//(internal1_m397_RA10)  - последнее задание назад
#define idinternal1_m397_RA10	 990	//(internal1_m397_RA10)  - последнее задание назад
#define internal1_m397_MyFirstEnterFlag	 BUFFER[3285]	//(internal1_m397_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m397_MyFirstEnterFlag	 991	//(internal1_m397_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m381_Pav0	 BUFFER[3287]	//(internal1_m381_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m381_Pav0	 992	//(internal1_m381_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m381_Zav0	 BUFFER[3289]	//(internal1_m381_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m381_Zav0	 993	//(internal1_m381_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m381_Pv0	 BUFFER[3291]	//(internal1_m381_Pv0)  - Пер. выключатель механизма
#define idinternal1_m381_Pv0	 994	//(internal1_m381_Pv0)  - Пер. выключатель механизма
#define internal1_m381_Zv0	 BUFFER[3293]	//(internal1_m381_Zv0)  - Зад. выключатель механизма
#define idinternal1_m381_Zv0	 995	//(internal1_m381_Zv0)  - Зад. выключатель механизма
#define internal1_m381_RA00	 BUFFER[3295]	//(internal1_m381_RA00)  - последнее задание вперед
#define idinternal1_m381_RA00	 996	//(internal1_m381_RA00)  - последнее задание вперед
#define internal1_m381_RA10	 BUFFER[3297]	//(internal1_m381_RA10)  - последнее задание назад
#define idinternal1_m381_RA10	 997	//(internal1_m381_RA10)  - последнее задание назад
#define internal1_m381_MyFirstEnterFlag	 BUFFER[3299]	//(internal1_m381_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m381_MyFirstEnterFlag	 998	//(internal1_m381_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m364_Pav0	 BUFFER[3301]	//(internal1_m364_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m364_Pav0	 999	//(internal1_m364_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m364_Zav0	 BUFFER[3303]	//(internal1_m364_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m364_Zav0	 1000	//(internal1_m364_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m364_Pv0	 BUFFER[3305]	//(internal1_m364_Pv0)  - Пер. выключатель механизма
#define idinternal1_m364_Pv0	 1001	//(internal1_m364_Pv0)  - Пер. выключатель механизма
#define internal1_m364_Zv0	 BUFFER[3307]	//(internal1_m364_Zv0)  - Зад. выключатель механизма
#define idinternal1_m364_Zv0	 1002	//(internal1_m364_Zv0)  - Зад. выключатель механизма
#define internal1_m364_RA00	 BUFFER[3309]	//(internal1_m364_RA00)  - последнее задание вперед
#define idinternal1_m364_RA00	 1003	//(internal1_m364_RA00)  - последнее задание вперед
#define internal1_m364_RA10	 BUFFER[3311]	//(internal1_m364_RA10)  - последнее задание назад
#define idinternal1_m364_RA10	 1004	//(internal1_m364_RA10)  - последнее задание назад
#define internal1_m364_MyFirstEnterFlag	 BUFFER[3313]	//(internal1_m364_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m364_MyFirstEnterFlag	 1005	//(internal1_m364_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m1167_Pav0	 BUFFER[3315]	//(internal1_m1167_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m1167_Pav0	 1006	//(internal1_m1167_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m1167_Zav0	 BUFFER[3317]	//(internal1_m1167_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m1167_Zav0	 1007	//(internal1_m1167_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m1167_Pv0	 BUFFER[3319]	//(internal1_m1167_Pv0)  - Пер. выключатель механизма
#define idinternal1_m1167_Pv0	 1008	//(internal1_m1167_Pv0)  - Пер. выключатель механизма
#define internal1_m1167_Zv0	 BUFFER[3321]	//(internal1_m1167_Zv0)  - Зад. выключатель механизма
#define idinternal1_m1167_Zv0	 1009	//(internal1_m1167_Zv0)  - Зад. выключатель механизма
#define internal1_m1167_RA00	 BUFFER[3323]	//(internal1_m1167_RA00)  - последнее задание вперед
#define idinternal1_m1167_RA00	 1010	//(internal1_m1167_RA00)  - последнее задание вперед
#define internal1_m1167_RA10	 BUFFER[3325]	//(internal1_m1167_RA10)  - последнее задание назад
#define idinternal1_m1167_RA10	 1011	//(internal1_m1167_RA10)  - последнее задание назад
#define internal1_m1167_MyFirstEnterFlag	 BUFFER[3327]	//(internal1_m1167_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m1167_MyFirstEnterFlag	 1012	//(internal1_m1167_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m180_C1	 BUFFER[3329]	//(internal1_m180_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m180_C1	 1013	//(internal1_m180_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m180_C2	 BUFFER[3334]	//(internal1_m180_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m180_C2	 1014	//(internal1_m180_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m180_C3	 BUFFER[3339]	//(internal1_m180_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m180_C3	 1015	//(internal1_m180_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m180_C4	 BUFFER[3344]	//(internal1_m180_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m180_C4	 1016	//(internal1_m180_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m180_C5	 BUFFER[3349]	//(internal1_m180_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m180_C5	 1017	//(internal1_m180_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m180_C6	 BUFFER[3354]	//(internal1_m180_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m180_C6	 1018	//(internal1_m180_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m180_N20	 BUFFER[3359]	//(internal1_m180_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m180_N20	 1019	//(internal1_m180_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m180_C0	 BUFFER[3364]	//(internal1_m180_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define idinternal1_m180_C0	 1020	//(internal1_m180_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define internal1_m180_ImpINI0	 BUFFER[3394]	//(internal1_m180_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m180_ImpINI0	 1021	//(internal1_m180_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m180_MyFirstEnterFlag	 BUFFER[3396]	//(internal1_m180_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m180_MyFirstEnterFlag	 1022	//(internal1_m180_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m301_Ppv0	 BUFFER[3398]	//(internal1_m301_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m301_Ppv0	 1023	//(internal1_m301_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m301_Pav0	 BUFFER[3400]	//(internal1_m301_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m301_Pav0	 1024	//(internal1_m301_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m301_Zav0	 BUFFER[3402]	//(internal1_m301_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m301_Zav0	 1025	//(internal1_m301_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m301_RA00	 BUFFER[3404]	//(internal1_m301_RA00) RA00 - последнее задание вперед
#define idinternal1_m301_RA00	 1026	//(internal1_m301_RA00) RA00 - последнее задание вперед
#define internal1_m301_RA10	 BUFFER[3406]	//(internal1_m301_RA10) RA10 - последнее задание назад
#define idinternal1_m301_RA10	 1027	//(internal1_m301_RA10) RA10 - последнее задание назад
#define internal1_m301_RA50	 BUFFER[3408]	//(internal1_m301_RA50) Ra50 - последнее задание скорости
#define idinternal1_m301_RA50	 1028	//(internal1_m301_RA50) Ra50 - последнее задание скорости
#define internal1_m301_fls	 BUFFER[3409]	//(internal1_m301_fls)  fls - флаг одношагового режима
#define idinternal1_m301_fls	 1029	//(internal1_m301_fls)  fls - флаг одношагового режима
#define internal1_m301_flp	 BUFFER[3411]	//(internal1_m301_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m301_flp	 1030	//(internal1_m301_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m301_MyFirstEnterFlag	 BUFFER[3413]	//(internal1_m301_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m301_MyFirstEnterFlag	 1031	//(internal1_m301_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m130_Ppv0	 BUFFER[3415]	//(internal1_m130_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m130_Ppv0	 1032	//(internal1_m130_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m130_Pav0	 BUFFER[3417]	//(internal1_m130_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m130_Pav0	 1033	//(internal1_m130_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m130_Zav0	 BUFFER[3419]	//(internal1_m130_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m130_Zav0	 1034	//(internal1_m130_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m130_RA00	 BUFFER[3421]	//(internal1_m130_RA00) RA00 - последнее задание вперед
#define idinternal1_m130_RA00	 1035	//(internal1_m130_RA00) RA00 - последнее задание вперед
#define internal1_m130_RA10	 BUFFER[3423]	//(internal1_m130_RA10) RA10 - последнее задание назад
#define idinternal1_m130_RA10	 1036	//(internal1_m130_RA10) RA10 - последнее задание назад
#define internal1_m130_RA50	 BUFFER[3425]	//(internal1_m130_RA50) Ra50 - последнее задание скорости
#define idinternal1_m130_RA50	 1037	//(internal1_m130_RA50) Ra50 - последнее задание скорости
#define internal1_m130_fls	 BUFFER[3426]	//(internal1_m130_fls)  fls - флаг одношагового режима
#define idinternal1_m130_fls	 1038	//(internal1_m130_fls)  fls - флаг одношагового режима
#define internal1_m130_flp	 BUFFER[3428]	//(internal1_m130_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m130_flp	 1039	//(internal1_m130_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m130_MyFirstEnterFlag	 BUFFER[3430]	//(internal1_m130_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m130_MyFirstEnterFlag	 1040	//(internal1_m130_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m265_Ppv0	 BUFFER[3432]	//(internal1_m265_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m265_Ppv0	 1041	//(internal1_m265_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m265_Pav0	 BUFFER[3434]	//(internal1_m265_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m265_Pav0	 1042	//(internal1_m265_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m265_Zav0	 BUFFER[3436]	//(internal1_m265_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m265_Zav0	 1043	//(internal1_m265_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m265_RA00	 BUFFER[3438]	//(internal1_m265_RA00) RA00 - последнее задание вперед
#define idinternal1_m265_RA00	 1044	//(internal1_m265_RA00) RA00 - последнее задание вперед
#define internal1_m265_RA10	 BUFFER[3440]	//(internal1_m265_RA10) RA10 - последнее задание назад
#define idinternal1_m265_RA10	 1045	//(internal1_m265_RA10) RA10 - последнее задание назад
#define internal1_m265_RA50	 BUFFER[3442]	//(internal1_m265_RA50) Ra50 - последнее задание скорости
#define idinternal1_m265_RA50	 1046	//(internal1_m265_RA50) Ra50 - последнее задание скорости
#define internal1_m265_fls	 BUFFER[3443]	//(internal1_m265_fls)  fls - флаг одношагового режима
#define idinternal1_m265_fls	 1047	//(internal1_m265_fls)  fls - флаг одношагового режима
#define internal1_m265_flp	 BUFFER[3445]	//(internal1_m265_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m265_flp	 1048	//(internal1_m265_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m265_MyFirstEnterFlag	 BUFFER[3447]	//(internal1_m265_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m265_MyFirstEnterFlag	 1049	//(internal1_m265_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m97_Ppv0	 BUFFER[3449]	//(internal1_m97_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m97_Ppv0	 1050	//(internal1_m97_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m97_Pav0	 BUFFER[3451]	//(internal1_m97_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m97_Pav0	 1051	//(internal1_m97_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m97_Zav0	 BUFFER[3453]	//(internal1_m97_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m97_Zav0	 1052	//(internal1_m97_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m97_RA00	 BUFFER[3455]	//(internal1_m97_RA00) RA00 - последнее задание вперед
#define idinternal1_m97_RA00	 1053	//(internal1_m97_RA00) RA00 - последнее задание вперед
#define internal1_m97_RA10	 BUFFER[3457]	//(internal1_m97_RA10) RA10 - последнее задание назад
#define idinternal1_m97_RA10	 1054	//(internal1_m97_RA10) RA10 - последнее задание назад
#define internal1_m97_RA50	 BUFFER[3459]	//(internal1_m97_RA50) Ra50 - последнее задание скорости
#define idinternal1_m97_RA50	 1055	//(internal1_m97_RA50) Ra50 - последнее задание скорости
#define internal1_m97_fls	 BUFFER[3460]	//(internal1_m97_fls)  fls - флаг одношагового режима
#define idinternal1_m97_fls	 1056	//(internal1_m97_fls)  fls - флаг одношагового режима
#define internal1_m97_flp	 BUFFER[3462]	//(internal1_m97_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m97_flp	 1057	//(internal1_m97_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m97_MyFirstEnterFlag	 BUFFER[3464]	//(internal1_m97_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m97_MyFirstEnterFlag	 1058	//(internal1_m97_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m227_Ppv0	 BUFFER[3466]	//(internal1_m227_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m227_Ppv0	 1059	//(internal1_m227_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m227_Pav0	 BUFFER[3468]	//(internal1_m227_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m227_Pav0	 1060	//(internal1_m227_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m227_Zav0	 BUFFER[3470]	//(internal1_m227_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m227_Zav0	 1061	//(internal1_m227_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m227_RA00	 BUFFER[3472]	//(internal1_m227_RA00) RA00 - последнее задание вперед
#define idinternal1_m227_RA00	 1062	//(internal1_m227_RA00) RA00 - последнее задание вперед
#define internal1_m227_RA10	 BUFFER[3474]	//(internal1_m227_RA10) RA10 - последнее задание назад
#define idinternal1_m227_RA10	 1063	//(internal1_m227_RA10) RA10 - последнее задание назад
#define internal1_m227_RA50	 BUFFER[3476]	//(internal1_m227_RA50) Ra50 - последнее задание скорости
#define idinternal1_m227_RA50	 1064	//(internal1_m227_RA50) Ra50 - последнее задание скорости
#define internal1_m227_fls	 BUFFER[3477]	//(internal1_m227_fls)  fls - флаг одношагового режима
#define idinternal1_m227_fls	 1065	//(internal1_m227_fls)  fls - флаг одношагового режима
#define internal1_m227_flp	 BUFFER[3479]	//(internal1_m227_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m227_flp	 1066	//(internal1_m227_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m227_MyFirstEnterFlag	 BUFFER[3481]	//(internal1_m227_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m227_MyFirstEnterFlag	 1067	//(internal1_m227_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m59_Ppv0	 BUFFER[3483]	//(internal1_m59_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m59_Ppv0	 1068	//(internal1_m59_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m59_Pav0	 BUFFER[3485]	//(internal1_m59_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m59_Pav0	 1069	//(internal1_m59_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m59_Zav0	 BUFFER[3487]	//(internal1_m59_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m59_Zav0	 1070	//(internal1_m59_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m59_RA00	 BUFFER[3489]	//(internal1_m59_RA00) RA00 - последнее задание вперед
#define idinternal1_m59_RA00	 1071	//(internal1_m59_RA00) RA00 - последнее задание вперед
#define internal1_m59_RA10	 BUFFER[3491]	//(internal1_m59_RA10) RA10 - последнее задание назад
#define idinternal1_m59_RA10	 1072	//(internal1_m59_RA10) RA10 - последнее задание назад
#define internal1_m59_RA50	 BUFFER[3493]	//(internal1_m59_RA50) Ra50 - последнее задание скорости
#define idinternal1_m59_RA50	 1073	//(internal1_m59_RA50) Ra50 - последнее задание скорости
#define internal1_m59_fls	 BUFFER[3494]	//(internal1_m59_fls)  fls - флаг одношагового режима
#define idinternal1_m59_fls	 1074	//(internal1_m59_fls)  fls - флаг одношагового режима
#define internal1_m59_flp	 BUFFER[3496]	//(internal1_m59_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m59_flp	 1075	//(internal1_m59_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m59_MyFirstEnterFlag	 BUFFER[3498]	//(internal1_m59_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m59_MyFirstEnterFlag	 1076	//(internal1_m59_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m14_C1	 BUFFER[3500]	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m14_C1	 1077	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m14_C2	 BUFFER[3505]	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m14_C2	 1078	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m14_C3	 BUFFER[3510]	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m14_C3	 1079	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m14_C4	 BUFFER[3515]	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m14_C4	 1080	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m14_C5	 BUFFER[3520]	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m14_C5	 1081	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m14_C6	 BUFFER[3525]	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m14_C6	 1082	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m14_N20	 BUFFER[3530]	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m14_N20	 1083	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m14_C0	 BUFFER[3535]	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define idinternal1_m14_C0	 1084	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define internal1_m14_ImpINI0	 BUFFER[3565]	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m14_ImpINI0	 1085	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m14_MyFirstEnterFlag	 BUFFER[3567]	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m14_MyFirstEnterFlag	 1086	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,8	,1	, &A0SR01RIM},	//(A0SR01RIM) Текущая реактивность AЗ1
	{ 2	,1	,1	, &A1AD11LDU},	//(A1AD11LDU) Сигнал на перемещение ББ1 вверх
	{ 3	,1	,1	, &A1AD21LDU},	//(A1AD21LDU) Сигнал на перемещение ББ1 вниз
	{ 4	,1	,1	, &A1AD01LDU},	//(A1AD01LDU) Разрешение движения ББ1
	{ 5	,1	,1	, &A1AD02LDU},	//(A1AD02LDU) 0-й бит скорости ББ1
	{ 6	,1	,1	, &A1AD03LDU},	//(A1AD03LDU) 1-й бит скорости ББ1
	{ 7	,1	,1	, &A1AD04LDU},	//(A1AD04LDU) 2-й бит скорости ББ1
	{ 8	,1	,1	, &A1AD05LDU},	//(A1AD05LDU) паритет команды на ББ1
	{ 9	,1	,1	, &B1AD11LDU},	//(B1AD11LDU) Сигнал на перемещение ББ2 вверх
	{ 10	,1	,1	, &B1AD21LDU},	//(B1AD21LDU) Сигнал на перемещение ББ2 вниз
	{ 11	,1	,1	, &B1AD01LDU},	//(B1AD01LDU) Разрешение движения ББ2
	{ 12	,1	,1	, &B1AD02LDU},	//(B1AD02LDU) 0-й бит скорости  ББ2
	{ 13	,1	,1	, &B1AD03LDU},	//(B1AD03LDU) 1-й бит скорости ББ2
	{ 14	,1	,1	, &B1AD04LDU},	//(B1AD04LDU) 2-й бит скорости ББ2
	{ 15	,1	,1	, &B1AD05LDU},	//(B1AD05LDU) паритет команды на ББ2
	{ 16	,1	,1	, &A2AD11LDU},	//(A2AD11LDU) Сигнал на перемещение РБ1 вверх
	{ 17	,1	,1	, &A2AD21LDU},	//(A2AD21LDU) Сигнал на перемещение РБ1 вниз
	{ 18	,1	,1	, &A2AD01LDU},	//(A2AD01LDU) Разрешение движения РБ1
	{ 19	,1	,1	, &A2AD02LDU},	//(A2AD02LDU) 0-й бит скорости РБ1
	{ 20	,1	,1	, &A2AD03LDU},	//(A2AD03LDU) 1-й бит скорости РБ1
	{ 21	,1	,1	, &A2AD04LDU},	//(A2AD04LDU) 2-й бит скорости РБ1
	{ 22	,1	,1	, &A2AD05LDU},	//(A2AD05LDU) паритет команды на РБ1
	{ 23	,1	,1	, &A2AD33LDU},	//(A2AD33LDU) Клапан (Подъем РБ1) закрыть (обесточить)
	{ 24	,1	,1	, &B2AD11LDU},	//(B2AD11LDU) Сигнал на перемещение РБ2 вверх
	{ 25	,1	,1	, &B2AD21LDU},	//(B2AD21LDU) Сигнал на перемещение РБ2 вниз
	{ 26	,1	,1	, &B2AD01LDU},	//(B2AD01LDU) Разрешение движения РБ2
	{ 27	,1	,1	, &B2AD02LDU},	//(B2AD02LDU) 0-й бит скорости РБ2
	{ 28	,1	,1	, &B2AD03LDU},	//(B2AD03LDU) 1-й бит скорости РБ2
	{ 29	,1	,1	, &B2AD04LDU},	//(B2AD04LDU) 2-й бит скорости РБ2
	{ 30	,1	,1	, &B2AD05LDU},	//(B2AD05LDU) паритет команды на РБ2
	{ 31	,1	,1	, &B2AD33LDU},	//(B2AD33LDU) Клапан (Подъем РБ2) закрыть (обесточить)
	{ 32	,1	,1	, &A3AD11LDU},	//(A3AD11LDU) Сигнал на перемещение ИС1 вверх
	{ 33	,1	,1	, &A3AD21LDU},	//(A3AD21LDU) Сигнал на перемещение ИС1 вниз
	{ 34	,1	,1	, &A3AD01LDU},	//(A3AD01LDU) Разрешение движения ИС1
	{ 35	,1	,1	, &A3AD02LDU},	//(A3AD02LDU) 0-й бит скорости ИС1
	{ 36	,1	,1	, &A3AD03LDU},	//(A3AD03LDU) 1-й бит скорости ИС1
	{ 37	,1	,1	, &A3AD04LDU},	//(A3AD04LDU) 2-й бит скорости ИС1
	{ 38	,1	,1	, &A3AD05LDU},	//(A3AD05LDU) паритет команды на ИС1
	{ 39	,1	,1	, &A3AD33LDU},	//(A3AD33LDU) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
	{ 40	,1	,1	, &B3AD11LDU},	//(B3AD11LDU) Сигнал на перемещение ИС2 вверх
	{ 41	,1	,1	, &B3AD21LDU},	//(B3AD21LDU) Сигнал на перемещение ИС2 вниз
	{ 42	,1	,1	, &B3AD01LDU},	//(B3AD01LDU) Разрешение движения ИС2
	{ 43	,1	,1	, &B3AD02LDU},	//(B3AD02LDU) 0-й бит скорости ИС2
	{ 44	,1	,1	, &B3AD03LDU},	//(B3AD03LDU) 1-й бит скорости ИС2
	{ 45	,1	,1	, &B3AD04LDU},	//(B3AD04LDU) 2-й бит скорости ИС2
	{ 46	,1	,1	, &B3AD05LDU},	//(B3AD05LDU) паритет команды на ИС2
	{ 47	,1	,1	, &B3AD33LDU},	//(B3AD33LDU) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
	{ 48	,8	,1	, &B0SR01RIM},	//(B0SR01RIM) Текущая реактивность AЗ2
	{ 49	,1	,1	, &R4AD10LDU},	//(R4AD10LDU) Перемещение тележки вперед
	{ 50	,1	,1	, &R4AD20LDU},	//(R4AD20LDU) Перемещение тележки назад
	{ 51	,1	,1	, &B8AD10LDU},	//(B8AD10LDU) Перемещение АЗ2 вперед
	{ 52	,1	,1	, &B8AD20LDU},	//(B8AD20LDU) Перемещение АЗ2 назад
	{ 53	,1	,1	, &A8AD10LDU},	//(A8AD10LDU) Перемещение ДС2 вперед
	{ 54	,1	,1	, &A8AD20LDU},	//(A8AD20LDU) Перемещение ДС2 назад
	{ 55	,1	,1	, &A6AD10LDU},	//(A6AD10LDU) Открыть БЗ1
	{ 56	,1	,1	, &A6AD20LDU},	//(A6AD20LDU) Закрыть БЗ1
	{ 57	,1	,1	, &B6AD10LDU},	//(B6AD10LDU) Открыть БЗ2
	{ 58	,1	,1	, &B6AD20LDU},	//(B6AD20LDU) Закрыть БЗ2
	{ 59	,1	,1	, &R1AD10LDU},	//(R1AD10LDU) Опустить МДЗ1 в зону облучения
	{ 60	,1	,1	, &R1AD20LDU},	//(R1AD20LDU) Поднять МДЗ1
	{ 61	,1	,1	, &R2AD10LDU},	//(R2AD10LDU) Опустить МДЗ2 в зону облучения
	{ 62	,1	,1	, &R2AD20LDU},	//(R2AD20LDU) Поднять МДЗ2
	{ 63	,1	,1	, &A5AD10LDU},	//(A5AD10LDU) Поднять НЛ1
	{ 64	,1	,1	, &A5AD20LDU},	//(A5AD20LDU) Опустить НЛ1
	{ 65	,1	,1	, &B5AD10LDU},	//(B5AD10LDU) Поднять НЛ2
	{ 66	,1	,1	, &B5AD20LDU},	//(B5AD20LDU) Опустить НЛ2
	{ 67	,8	,1	, &A0SN08RIM},	//(A0SN08RIM) Поток нейтронов AЗ1(нейтр/с)
	{ 68	,8	,1	, &B0SN08RIM},	//(B0SN08RIM) Поток нейтронов AЗ2(нейтр/с)
	{ 69	,8	,1	, &R0CR01RIM},	//(R0CR01RIM) Коэффициент 12 связи АЗ1,2
	{ 70	,8	,1	, &R0CR02RIM},	//(R0CR02RIM) Коэффициент 11 связи АЗ1,2
	{ 71	,8	,1	, &R0SR02RIM},	//(R0SR02RIM) Текущая мощность РУ (ватт)
	{ 72	,1	,1	, &R0AD14LDU},	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
	{ 73	,1	,1	, &R8AD21LDU},	//(R8AD21LDU) Запуск системы инициирования
	{ 74	,1	,1	, &R0VZ71LZ1},	//(R0VZ71LZ1) Обобщенный сигнал по АЗ  1 канала
	{ 75	,1	,1	, &R0VZ71LZ2},	//(R0VZ71LZ2) Обобщенный сигнал по АЗ  2 канала
	{ 76	,1	,1	, &A2AD32LDU},	//(A2AD32LDU) Обесточить ЭМ РБ1
	{ 77	,1	,1	, &C2MD31LP1},	//(C2MD31LP1) Кнопка «СБРОС РБ»
	{ 78	,1	,1	, &A2AD31LDU},	//(A2AD31LDU) Клапан (Сброс РБ1) открыть (обесточить)
	{ 79	,1	,1	, &A1AD32LDU},	//(A1AD32LDU) Обесточить ЭМ ББ1
	{ 80	,1	,1	, &A1AD31LDU},	//(A1AD31LDU) Клапан (Сброс ББ1) открыть (обесточить)
	{ 81	,1	,1	, &C1MD31LP2},	//(C1MD31LP2) Кнопка «СБРОС ББ»  на ОПУ2
	{ 82	,1	,1	, &C1MD31LP1},	//(C1MD31LP1) Кнопка «СБРОС ББ»  на ОПУ1
	{ 83	,1	,1	, &A3AD31LDU},	//(A3AD31LDU) Клапан (СПУСК ИС1) открыть (обесточить)
	{ 84	,1	,1	, &B1AD31LDU},	//(B1AD31LDU) Клапан (Сброс ББ2) открыть (обесточить)
	{ 85	,1	,1	, &B1AD32LDU},	//(B1AD32LDU) Обесточить ЭМ ББ2
	{ 86	,1	,1	, &B2AD31LDU},	//(B2AD31LDU) Клапан (Сброс РБ2) открыть (обесточить)
	{ 87	,1	,1	, &B2AD32LDU},	//(B2AD32LDU) Обесточить ЭМ РБ2
	{ 88	,1	,1	, &B3AD31LDU},	//(B3AD31LDU) Клапан (СПУСК ИС2) открыть (обесточить)
	{ 89	,1	,1	, &R0MW13LP2},	//(R0MW13LP2) Переключатель «СЕТЬ»
	{ 90	,1	,1	, &B9AD10LDU},	//(B9AD10LDU) Открыть клапан (Подъем НИ ДС2)
	{ 91	,1	,1	, &A9AD10LDU},	//(A9AD10LDU) Открыть клапан (Подъем НИ ДС1)
	{ 92	,1	,1	, &B4AD10LDU},	//(B4AD10LDU) Открыть клапан (Подъем НИ2)
	{ 93	,1	,1	, &A4AD10LDU},	//(A4AD10LDU) Открыть клапан (Подъем НИ1)
	{ 94	,8	,1	, &R0ST01RIM},	//(R0ST01RIM) Текущий период разгона РУ
	{ 95	,8	,1	, &R0SR01RIM},	//(R0SR01RIM) Текущая реактивность PУ
	{ 96	,1	,1	, &R7II73LZ1},	//(R7II73LZ1) Сработала АС IIУР
	{ 97	,1	,1	, &R7II71LZ1},	//(R7II71LZ1) Сработала АС IУР (датчик 1)
	{ 98	,1	,1	, &R7II72LZ1},	//(R7II72LZ1) Сработала АС IУР (датчик 2)
	{ 99	,1	,1	, &R0AD16LDU},	//(R0AD16LDU) Контроль  I-II УР. РАД
	{ 100	,1	,1	, &R7II72LZ2},	//(R7II72LZ2) Сработала АС IУР (датчик 2)
	{ 101	,1	,1	, &R7II71LZ2},	//(R7II71LZ2) Сработала АС IУР (датчик 1)
	{ 102	,1	,1	, &R7II73LZ2},	//(R7II73LZ2) Сработала АС IIУР
	{ 103	,1	,1	, &A3IS35LDU},	//(A3IS35LDU) Клапан (ВПИС1) открыт(обесточен)
	{ 104	,1	,1	, &B3AD34LDU},	//(B3AD34LDU) Клапан (ВПИС2) открыть (обесточить)
	{ 105	,1	,1	, &B3IS35LDU},	//(B3IS35LDU) Клапан «ВПИС2» открыт(обесточен)
	{ 106	,8	,1	, &R0VN02RS1},	//(R0VN02RS1) Уровень мощности канал1
	{ 107	,1	,1	, &R0VN61LS1},	//(R0VN61LS1) ПС по мощности канал1
	{ 108	,1	,1	, &R0VN71LZ1},	//(R0VN71LZ1) АС по мощности канал1 на БАЗ1
	{ 109	,1	,1	, &A0VN71LS1},	//(A0VN71LS1) Блокировка автоматического  подъёма ББ канал 1 на БАЗ1
	{ 110	,3	,1	, &R0VN15RS1},	//(R0VN15RS1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
	{ 111	,1	,1	, &R0VN71LZ2},	//(R0VN71LZ2) АС по мощности канал 1  на БАЗ2
	{ 112	,1	,1	, &A1VN71LS1},	//(A1VN71LS1) Блокировка автоматического  подъёма ББ канал 1 на БАЗ2
	{ 113	,8	,1	, &R0VN01RS1},	//(R0VN01RS1) Период разгона канал1
	{ 114	,1	,1	, &R0VN65LS1},	//(R0VN65LS1) ПС по периоду разгона канал1
	{ 115	,1	,1	, &R0VN75LZ1},	//(R0VN75LZ1) АС по периоду разгонана БАЗ1
	{ 116	,1	,1	, &A0EE01LS1},	//(A0EE01LS1) Исправность АКНП канал1 на БАЗ1
	{ 117	,1	,1	, &R0VN75LZ2},	//(R0VN75LZ2) АС по периоду разгонана БАЗ2
	{ 118	,1	,1	, &A1EE01LS1},	//(A1EE01LS1) Исправность АКНП на БАЗ2
	{ 119	,1	,1	, &R0IE11LS1},	//(R0IE11LS1) Исправность ВИП 1,6 (№8) СНМ11 1канала
	{ 120	,1	,1	, &R0IE12LS1},	//(R0IE12LS1) Исправность ВИП 0,5 (№9) КНК15-1 1канала
	{ 121	,1	,1	, &R0IE13LS1},	//(R0IE13LS1) Исправность ВИП 0,5 (№10) КНК53М 1канала
	{ 122	,8	,1	, &R0VN02RS2},	//(R0VN02RS2) Уровень мощности канал 2
	{ 123	,1	,1	, &R0VN61LS2},	//(R0VN61LS2) ПС по мощности канал 2
	{ 124	,1	,1	, &R0VN72LZ1},	//(R0VN72LZ1) АС по мощности канал 2 на БАЗ1
	{ 125	,1	,1	, &A1VN71LS2},	//(A1VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ2
	{ 126	,3	,1	, &R0VN15RS2},	//(R0VN15RS2) Номер ведущей камеры канал 2
	{ 127	,1	,1	, &R0VN72LZ2},	//(R0VN72LZ2) АС по мощности канал 2 на БАЗ2
	{ 128	,1	,1	, &A0VN71LS2},	//(A0VN71LS2) Блокировка автоматического подъёма ББ канал 2 на БАЗ1
	{ 129	,8	,1	, &R0VN01RS2},	//(R0VN01RS2) Период разгона канал 2
	{ 130	,1	,1	, &R0VN65LS2},	//(R0VN65LS2) ПС по периоду разгона канал 2
	{ 131	,1	,1	, &R0VN76LZ1},	//(R0VN76LZ1) АС по периоду разгона канал 2  на БАЗ1
	{ 132	,1	,1	, &A0EE01LS2},	//(A0EE01LS2) Исправность АКНП канал 2 на БАЗ1
	{ 133	,1	,1	, &R0VN76LZ2},	//(R0VN76LZ2) АС по периоду разгона канал 2  на БАЗ2
	{ 134	,1	,1	, &A1EE01LS2},	//(A1EE01LS2) Исправность АКНП канал 2 на БАЗ2
	{ 135	,1	,1	, &R0IE12LS2},	//(R0IE12LS2) Исправность ВИП 0,5 (№12) КНК15-1 2канала
	{ 136	,1	,1	, &R0IE13LS2},	//(R0IE13LS2) Исправность ВИП 0,5 (№13) КНК53М 2канала
	{ 137	,1	,1	, &R0IE11LS2},	//(R0IE11LS2) Исправность ВИП 1,6 (№11) СНМ11 2канала
	{ 138	,8	,1	, &R0VN02RS3},	//(R0VN02RS3) Уровень мощности канал 3
	{ 139	,1	,1	, &R0VN61LS3},	//(R0VN61LS3) ПС по мощности канал 3
	{ 140	,1	,1	, &R0VN73LZ1},	//(R0VN73LZ1) АС по мощности канал 3 на БАЗ1
	{ 141	,1	,1	, &A1VN71LS3},	//(A1VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ2
	{ 142	,3	,1	, &R0VN15RS3},	//(R0VN15RS3) Номер ведущей камеры канал 3
	{ 143	,1	,1	, &A0VN71LS3},	//(A0VN71LS3) Блокировка автоматического  подъёма ББ канал 3 на БАЗ1
	{ 144	,1	,1	, &R0VN73LZ2},	//(R0VN73LZ2) АС по мощности канал 3 на БАЗ2
	{ 145	,8	,1	, &R0VN01RS3},	//(R0VN01RS3) Период разгона канал 3
	{ 146	,1	,1	, &R0VN65LS3},	//(R0VN65LS3) ПС по периоду разгона канал 3
	{ 147	,1	,1	, &R0VN77LZ1},	//(R0VN77LZ1) АС по периоду разгона канал 3 на БАЗ1
	{ 148	,1	,1	, &A0EE01LS3},	//(A0EE01LS3) Исправность АКНП канал 3 на БАЗ1
	{ 149	,1	,1	, &R0VN77LZ2},	//(R0VN77LZ2) АС по периоду разгона канал 3 на БАЗ2
	{ 150	,1	,1	, &A1EE01LS3},	//(A1EE01LS3) Исправность АКНП канал 3 на БАЗ2
	{ 151	,1	,1	, &R0IE12LS3},	//(R0IE12LS3) Исправность ВИП 0,5 (№15) КНК15-1 3канала
	{ 152	,1	,1	, &R0IE13LS3},	//(R0IE13LS3) Исправность ВИП 0,5 (№16) КНК53М 3канала
	{ 153	,1	,1	, &R0IE11LS3},	//(R0IE11LS3) Исправность ВИП 1,6 (№14) СНМ11 3канала
	{ 154	,8	,1	, &R0VN02RS4},	//(R0VN02RS4) Уровень мощности канал 4
	{ 155	,1	,1	, &R0VN61LS4},	//(R0VN61LS4) ПС по мощности канал 4
	{ 156	,1	,1	, &R0VN74LZ1},	//(R0VN74LZ1) АС по мощности канал 4 на БАЗ1
	{ 157	,1	,1	, &A1VN71LS4},	//(A1VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ2
	{ 158	,3	,1	, &R0VN15RS4},	//(R0VN15RS4) Номер ведущей камеры канал 4
	{ 159	,1	,1	, &A0VN71LS4},	//(A0VN71LS4) Блокировка автоматического  подъёма ББ канал 4 на БАЗ1
	{ 160	,1	,1	, &R0VN74LZ2},	//(R0VN74LZ2) АС по мощности канал 4 на БАЗ2
	{ 161	,8	,1	, &R0VN01RS4},	//(R0VN01RS4) Период разгона канал 4
	{ 162	,1	,1	, &R0VN65LS4},	//(R0VN65LS4) ПС по периоду разгона канал 4
	{ 163	,1	,1	, &R0VN78LZ1},	//(R0VN78LZ1) АС по периоду разгона канал 4 на БАЗ1
	{ 164	,1	,1	, &A0EE01LS4},	//(A0EE01LS4) Исправность АКНП канал 4 на БАЗ1
	{ 165	,1	,1	, &R0VN78LZ2},	//(R0VN78LZ2) АС по периоду разгона канал 4 на БАЗ2
	{ 166	,1	,1	, &A1EE01LS4},	//(A1EE01LS4) Исправность АКНП канал 4 на БАЗ2
	{ 167	,1	,1	, &R0IE12LS4},	//(R0IE12LS4) Исправность ВИП 0,5 (№18) КНК15-1 4канала
	{ 168	,1	,1	, &R0IE13LS4},	//(R0IE13LS4) Исправность ВИП 0,5 (№19) КНК53М 4канала
	{ 169	,1	,1	, &R0IE11LS4},	//(R0IE11LS4) Исправность ВИП 1,6 (№17) СНМ11 4канала
	{ 170	,1	,1	, &A7AS31LDU},	//(A7AS31LDU) Клапан (Обдув АЗ1) открыт (обесточен)
	{ 171	,1	,1	, &B7AS31LDU},	//(B7AS31LDU) Клапан (Обдув АЗ2) открыт (обесточен)
	{ 172	,1	,1	, &R6IS21LDU},	//(R6IS21LDU) Кран-балка в нерабочем положении
	{ 173	,3	,1	, &A0IT01IZ1},	//(A0IT01IZ1) Температура АЗ1-1
	{ 174	,3	,1	, &A0IT02IZ2},	//(A0IT02IZ2) Температура АЗ1-2
	{ 175	,3	,1	, &B0IT01IZ1},	//(B0IT01IZ1) Температура АЗ2-1
	{ 176	,3	,1	, &B0IT02IZ2},	//(B0IT02IZ2) Температура АЗ2-2
	{ 177	,1	,1	, &A2IS21LDU},	//(A2IS21LDU) Приход на НУ РБ1
	{ 178	,1	,1	, &A2IS11LDU},	//(A2IS11LDU) Приход на ВУ РБ1
	{ 179	,1	,1	, &A2IS12LDU},	//(A2IS12LDU) Магнит РБ1 зацеплен
	{ 180	,5	,1	, &A2IC01UDU},	//(A2IC01UDU) Координата штока РБ1
	{ 181	,1	,1	, &A2IS33LDU},	//(A2IS33LDU) Клапан (Подъём РБ1)  открыт (обесточен)
	{ 182	,1	,1	, &A3IS21LDU},	//(A3IS21LDU) Приход на НУ ИС1
	{ 183	,1	,1	, &B3IS21LDU},	//(B3IS21LDU) Приход на НУ ИС2
	{ 184	,3	,1	, &A2IP01IZ1},	//(A2IP01IZ1) Текущее давление СБРОС РБ1
	{ 185	,3	,1	, &A2IP01IZ2},	//(A2IP01IZ2) Текущее давление СБРОС РБ1
	{ 186	,1	,1	, &A2VP82LDU},	//(A2VP82LDU) Давление ПОДЪЁМ РБ1 в норме
	{ 187	,1	,1	, &A3IS31LDU},	//(A3IS31LDU) Клапан (СПУСК ИС1)  открыт (обесточен)
	{ 188	,5	,1	, &A3IC01UDU},	//(A3IC01UDU) Координата штока ИС1
	{ 189	,1	,1	, &A3IS33LDU},	//(A3IS33LDU) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
	{ 190	,3	,1	, &B3IP02IDU},	//(B3IP02IDU) Текущее давление ВЫСТРЕЛ  ИС2
	{ 191	,1	,1	, &B3IS31LDU},	//(B3IS31LDU) Клапан (СПУСК ИС2)  открыт (обесточен)
	{ 192	,5	,1	, &B3IC01UDU},	//(B3IC01UDU) Координата штока ИС2
	{ 193	,1	,1	, &B3IS33LDU},	//(B3IS33LDU) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{ 194	,1	,1	, &A3VP81LDU},	//(A3VP81LDU) Давление СПУСК ИС1 в норме
	{ 195	,1	,1	, &B3VP81LDU},	//(B3VP81LDU) Давление СПУСК ИС2 в норме
	{ 196	,3	,1	, &A3IP02IDU},	//(A3IP02IDU) Текущее давление ВЫСТРЕЛ ИС1
	{ 197	,1	,1	, &A3IS11LDU},	//(A3IS11LDU) Приход на ВУ ИС1
	{ 198	,1	,1	, &B3IS11LDU},	//(B3IS11LDU) Приход на ВУ ИС2
	{ 199	,1	,1	, &A3IS22LDU},	//(A3IS22LDU) Приход на НУП ИС1
	{ 200	,1	,1	, &B3IS22LDU},	//(B3IS22LDU) Приход на НУП ИС2
	{ 201	,1	,1	, &R6IS62LDU},	//(R6IS62LDU) Исправность ВИП ССДИ-39 1канал
	{ 202	,1	,1	, &R6IS63LDU},	//(R6IS63LDU) Исправность ВИП ССДИ-39 2канал
	{ 203	,1	,1	, &R6IS64LDU},	//(R6IS64LDU) Исправность ВИП ССДИ-35 1канал
	{ 204	,1	,1	, &R6IS65LDU},	//(R6IS65LDU) Исправность ВИП ССДИ-35 2канал
	{ 205	,1	,1	, &R6IS66LZZ},	//(R6IS66LZZ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 206	,1	,1	, &R6IS67LZZ},	//(R6IS67LZZ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 207	,1	,1	, &R6IS68LZZ},	//(R6IS68LZZ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 208	,5	,1	, &A8IC01UDU},	//(A8IC01UDU) Координата ДС2
	{ 209	,5	,1	, &B8IC01UDU},	//(B8IC01UDU) Координата АЗ2
	{ 210	,1	,1	, &A0VP81LZZ},	//(A0VP81LZZ) Давление АЗ1 в норме
	{ 211	,1	,1	, &B0VP81LZZ},	//(B0VP81LZZ) Давление АЗ2 в норме
	{ 212	,1	,1	, &A5IS11LDU},	//(A5IS11LDU) Приход на ВУ НЛ1
	{ 213	,1	,1	, &A5IS21LDU},	//(A5IS21LDU) Приход на НУ НЛ1
	{ 214	,1	,1	, &B5IS11LDU},	//(B5IS11LDU) Приход на ВУ НЛ2
	{ 215	,1	,1	, &B5IS21LDU},	//(B5IS21LDU) Приход на НУ НЛ2
	{ 216	,1	,1	, &A9IS11LDU},	//(A9IS11LDU) Приход на ВУ НИ ДС1
	{ 217	,1	,1	, &A9IS21LDU},	//(A9IS21LDU) Приход на НУ НИ ДС1
	{ 218	,1	,1	, &B9IS11LDU},	//(B9IS11LDU) Приход на ВУ НИ ДС2
	{ 219	,1	,1	, &B9IS21LDU},	//(B9IS21LDU) Приход на НУ НИ ДС2
	{ 220	,1	,1	, &B2IS21LDU},	//(B2IS21LDU) Приход на НУ РБ2
	{ 221	,1	,1	, &B2IS11LDU},	//(B2IS11LDU) Приход на ВУ РБ2
	{ 222	,1	,1	, &B2IS12LDU},	//(B2IS12LDU) Магнит РБ2 зацеплен
	{ 223	,5	,1	, &B2IC01UDU},	//(B2IC01UDU) Координата штока РБ2
	{ 224	,3	,1	, &B2IP01IZ1},	//(B2IP01IZ1) Текущее давление СБРОС РБ2
	{ 225	,3	,1	, &B2IP01IZ2},	//(B2IP01IZ2) Текущее давление СБРОС РБ2
	{ 226	,1	,1	, &B2VP82LDU},	//(B2VP82LDU) Давление ПОДЪЁМ РБ2 в норме
	{ 227	,1	,1	, &R3IS11LDU},	//(R3IS11LDU) Приход на ВУ гомогенных дверей
	{ 228	,1	,1	, &R3IS21LDU},	//(R3IS21LDU) Приход на НУ гомогенных дверей
	{ 229	,1	,1	, &R5IS11LDU},	//(R5IS11LDU) Приход на ВУ ворот отстойной зоны
	{ 230	,1	,1	, &R5IS21LDU},	//(R5IS21LDU) Приход на НУ ворот отстойной зоны
	{ 231	,1	,1	, &A4IS11LDU},	//(A4IS11LDU) Приход на ВУ НИ1
	{ 232	,1	,1	, &A4IS21LDU},	//(A4IS21LDU) Приход на НУ НИ1
	{ 233	,1	,1	, &R8IS11LDU},	//(R8IS11LDU) Аварийный НИ установлен
	{ 234	,1	,1	, &B4IS11LDU},	//(B4IS11LDU) Приход на ВУ НИ2
	{ 235	,1	,1	, &B4IS21LDU},	//(B4IS21LDU) Приход на НУ НИ2
	{ 236	,1	,1	, &R1IS11LDU},	//(R1IS11LDU) Приход на ВУ МДЗ1
	{ 237	,1	,1	, &R1IS21LDU},	//(R1IS21LDU) Приход на НУ МДЗ1
	{ 238	,1	,1	, &R2IS11LDU},	//(R2IS11LDU) Приход на ВУ МДЗ2
	{ 239	,1	,1	, &R2IS21LDU},	//(R2IS21LDU) Приход на НУ МДЗ2
	{ 240	,1	,1	, &A4VP82LDU},	//(A4VP82LDU) Давление ПОДЪЁМ НИ1 в норме
	{ 241	,1	,1	, &B4VP82LDU},	//(B4VP82LDU) Давление ПОДЪЁМ НИ2 в норме
	{ 242	,1	,1	, &R4IS11LDU},	//(R4IS11LDU) Приход на ВУ1 тележки
	{ 243	,1	,1	, &R4IS21LDU},	//(R4IS21LDU) Приход на НУ1 тележки
	{ 244	,1	,1	, &R4IS22LDU},	//(R4IS22LDU) Приход на НУ2 тележки
	{ 245	,1	,1	, &R4IS12LDU},	//(R4IS12LDU) Приход на  ВУ2 тележки
	{ 246	,1	,1	, &B8IS22LDU},	//(B8IS22LDU) Приход на НУ2 АЗ2
	{ 247	,1	,1	, &B8IS12LDU},	//(B8IS12LDU) Приход на ВУ2 АЗ2
	{ 248	,1	,1	, &A8IS22LDU},	//(A8IS22LDU) Приход на механический НУ ДС2
	{ 249	,1	,1	, &A8IS12LDU},	//(A8IS12LDU) Приход на механический ВУ ДС2
	{ 250	,1	,1	, &A6IS11LDU},	//(A6IS11LDU) Приход на ВУ БЗ1
	{ 251	,1	,1	, &A6IS21LDU},	//(A6IS21LDU) Приход на НУ БЗ1
	{ 252	,1	,1	, &B6IS11LDU},	//(B6IS11LDU) Приход на ВУ БЗ2
	{ 253	,1	,1	, &B6IS21LDU},	//(B6IS21LDU) Приход на НУ БЗ2
	{ 254	,1	,1	, &A1IS21LDU},	//(A1IS21LDU) Приход на НУ ББ1
	{ 255	,1	,1	, &A1IS11LDU},	//(A1IS11LDU) Приход на ВУ ББ1
	{ 256	,1	,1	, &A1IS12LDU},	//(A1IS12LDU) Магнит ББ1 зацеплен
	{ 257	,5	,1	, &A1IC01UDU},	//(A1IC01UDU) Координата штока ББ1
	{ 258	,5	,1	, &B1IC01UDU},	//(B1IC01UDU) Координата штока ББ2
	{ 259	,1	,1	, &B1IS21LDU},	//(B1IS21LDU) Приход на НУ ББ2
	{ 260	,1	,1	, &B1IS11LDU},	//(B1IS11LDU) Приход на ВУ ББ2
	{ 261	,1	,1	, &B1IS12LDU},	//(B1IS12LDU) Магнит ББ2 зацеплен
	{ 262	,1	,1	, &A1IE03LDU},	//(A1IE03LDU) Движение ББ1 вперед (от БУШД)
	{ 263	,1	,1	, &A1IE04LDU},	//(A1IE04LDU) Движение ББ1 назад (от БУШД)
	{ 264	,1	,1	, &B1IE03LDU},	//(B1IE03LDU) Движение ББ2 вперед (от БУШД)
	{ 265	,1	,1	, &B1IE04LDU},	//(B1IE04LDU) Движение ББ2 назад (от БУШД)
	{ 266	,1	,1	, &A4IS10LDU},	//(A4IS10LDU) Клапан (Подъём НИ1) открыт (обесточен)
	{ 267	,1	,1	, &B4IS10LDU},	//(B4IS10LDU) Клапан (Подъём НИ2) открыт (обесточен)
	{ 268	,1	,1	, &R0EE01LZ1},	//(R0EE01LZ1) Питание  АКНП1  отключить
	{ 269	,1	,1	, &R0EE01LZ2},	//(R0EE01LZ2) Питание  АКНП1  отключить
	{ 270	,1	,1	, &R0EE02LZ1},	//(R0EE02LZ1) Питание  АКНП  отключить
	{ 271	,1	,1	, &R0EE03LZ1},	//(R0EE03LZ1) Питание  АКНП3  отключить
	{ 272	,1	,1	, &R0EE04LZ1},	//(R0EE04LZ1) Питание  АКНП4  отключить
	{ 273	,1	,1	, &R0EE02LZ2},	//(R0EE02LZ2) Питание  АКНП  отключить
	{ 274	,1	,1	, &R0EE03LZ2},	//(R0EE03LZ2) Питание  АКНП3  отключить
	{ 275	,1	,1	, &R0EE04LZ2},	//(R0EE04LZ2) Питание  АКНП4  отключить
	{ 276	,1	,1	, &R0IS02LDU},	//(R0IS02LDU) Разрешение ввода от имитатора
	{ 277	,1	,1	, &A3AD34LDU},	//(A3AD34LDU) Клапан (ВПИС ИС1) открыть (обесточить)
	{ 278	,1	,1	, &A1IS11LIM},	//(A1IS11LIM) Магнит ББ1 обесточен
	{ 279	,1	,1	, &A1IS32LIM},	//(A1IS32LIM) Клапан cброса ББ1 открыт(обесточен)
	{ 280	,1	,1	, &B1IS11LIM},	//(B1IS11LIM) Магнит ББ2 обесточен
	{ 281	,1	,1	, &B1IS32LIM},	//(B1IS32LIM) Клапан cброса ББ2 открыт(обесточен)
	{ 282	,1	,1	, &A2IS11LIM},	//(A2IS11LIM) Магнит РБ1 обесточен
	{ 283	,1	,1	, &A2IS32LIM},	//(A2IS32LIM) Клапан cброса РБ1 открыт(обесточен)
	{ 284	,1	,1	, &B2IS11LIM},	//(B2IS11LIM) Магнит РБ2 обесточен
	{ 285	,1	,1	, &B2IS32LIM},	//(B2IS32LIM) Клапан cброса РБ2 открыт(обесточен)
	{ 286	,8	,1	, &A0VN01RIM},	//(A0VN01RIM) Период разгона  AЗ1
	{ 287	,1	,1	, &B2IS33LDU},	//(B2IS33LDU) Клапан (Подъём РБ2)  открыт (обесточен)
	{ 288	,1	,1	, &B1VP81LZZ},	//(B1VP81LZZ) Давление СБРОС ББ2 в норме
	{ 289	,1	,1	, &A1VP81LZZ},	//(A1VP81LZZ) Давление СБРОС ББ1 в норме
	{ 290	,1	,1	, &B8IS11LDU},	//(B8IS11LDU) Приход на ВУ1 АЗ2
	{ 291	,1	,1	, &B8IS21LDU},	//(B8IS21LDU) Приход на НУ1 АЗ2
	{ 292	,1	,1	, &A6VS22LDU},	//(A6VS22LDU) Движение створок БЗ1  к ЗАКРЫТА
	{ 293	,1	,1	, &A6VS12LDU},	//(A6VS12LDU) Движение створок БЗ1  к  ОТКРЫТА
	{ 294	,1	,1	, &B6VS22LDU},	//(B6VS22LDU) Движение створок БЗ2  к ЗАКРЫТА
	{ 295	,1	,1	, &B6VS12LDU},	//(B6VS12LDU) Движение створок БЗ2  к ОТКРЫТА
	{ 296	,1	,1	, &A5VS22LDU},	//(A5VS22LDU) Движение НЛ1 в сторону НУ
	{ 297	,1	,1	, &A5VS12LDU},	//(A5VS12LDU) Движение НЛ1 в сторону ВУ
	{ 298	,1	,1	, &B5VS22LDU},	//(B5VS22LDU) Движение НЛ2 в сторону НУ
	{ 299	,1	,1	, &B5VS12LDU},	//(B5VS12LDU) Движение НЛ2 в сторону ВУ
	{ 300	,1	,1	, &R1VS22LDU},	//(R1VS22LDU) Движение МДЗ1 в сторону НУ
	{ 301	,1	,1	, &R2VS22LDU},	//(R2VS22LDU) Движение МДЗ2 в сторону НУ
	{ 302	,1	,1	, &R2VS12LDU},	//(R2VS12LDU) Движение МДЗ2 в сторону ВУ
	{ 303	,1	,1	, &R1VS12LDU},	//(R1VS12LDU) Движение МДЗ1 в сторону ВУ
	{ 304	,1	,1	, &R4VS22LDU},	//(R4VS22LDU) Движение реактора к «У ЗАЩИТЫ»
	{ 305	,1	,1	, &R4VS12LDU},	//(R4VS12LDU) Движение реактора  к «У ОБРАЗЦОВ»
	{ 306	,8	,1	, &A0SN02RIM},	//(A0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
	{ 307	,8	,1	, &A0SN03RIM},	//(A0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
	{ 308	,8	,1	, &A0SN04RIM},	//(A0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
	{ 309	,8	,1	, &A0SN05RIM},	//(A0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
	{ 310	,8	,1	, &A0SN06RIM},	//(A0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
	{ 311	,8	,1	, &A0SN07RIM},	//(A0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
	{ 312	,1	,1	, &A7AP31LDU},	//(A7AP31LDU) Клапан (Обдув АЗ1) открыть (обесточить)
	{ 313	,1	,1	, &B7AP31LDU},	//(B7AP31LDU) Клапан (Обдув АЗ2) открыть (обесточить)
	{ 314	,8	,1	, &B0SN02RIM},	//(B0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
	{ 315	,8	,1	, &B0SN03RIM},	//(B0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
	{ 316	,8	,1	, &B0SN04RIM},	//(B0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
	{ 317	,8	,1	, &B0SN05RIM},	//(B0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
	{ 318	,8	,1	, &B0SN06RIM},	//(B0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
	{ 319	,8	,1	, &B0SN07RIM},	//(B0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
	{ 320	,8	,1	, &fEM_R0UL01RIM},	//(R0UL01RIM) Среднее время генерации нейтронов
	{ 321	,8	,1	, &fEM_R0UN02RIM},	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{ 322	,8	,1	, &fEM_A1UR01RIM},	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{ 323	,8	,1	, &fEM_A1UR00RIM},	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{ 324	,8	,1	, &fEM_A3UR00RIM},	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{ 325	,8	,1	, &fEM_A3UR01RIM},	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{ 326	,8	,1	, &fEM_R0UT01RIM},	//(R0UT01RIM) Температурный коэффициент (долл)
	{ 327	,8	,1	, &fEM_R0UT02RIM},	//(R0UT02RIM) Масса топлива в АЗ
	{ 328	,8	,1	, &fEM_R0UT04RIM},	//(R0UT04RIM) Удельная теплоёмкость топлива
	{ 329	,8	,1	, &fEM_R0UT03RIM},	//(R0UT03RIM) Нормальная температура АЗ град
	{ 330	,8	,1	, &fEM_R0UT05RIM},	//(R0UT05RIM) Энергия деления ядра
	{ 331	,8	,1	, &fEM_R0UT06RIM},	//(R0UT06RIM) Конвекционное сопротивление при обдуве
	{ 332	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{ 333	,8	,1	, &fEM_A1UC04RIM},	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
	{ 334	,8	,1	, &fEM_A1UC05RIM},	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
	{ 335	,8	,1	, &fEM_A1UC06RIM},	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
	{ 336	,8	,1	, &fEM_A2UC06RIM},	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
	{ 337	,8	,1	, &fEM_A2UC05RIM},	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
	{ 338	,8	,1	, &fEM_A2UC04RIM},	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
	{ 339	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{ 340	,8	,1	, &fEM_A3UC06RIM},	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
	{ 341	,8	,1	, &fEM_A3UC05RIM},	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
	{ 342	,8	,1	, &fEM_A3UC04RIM},	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
	{ 343	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{ 344	,8	,1	, &fEM_R4UV80RDU},	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
	{ 345	,8	,1	, &fEM_R4UC10RIM},	//(R4UC10RIM) Координата верхних механических упоров тележки мм
	{ 346	,8	,1	, &fEM_R4UC20RIM},	//(R4UC20RIM) Координата нижних механических упоров тележки мм
	{ 347	,8	,1	, &fEM_B8UC21RIM},	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
	{ 348	,8	,1	, &fEM_B8UC20RIM},	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
	{ 349	,8	,1	, &fEM_B8UC11RIM},	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
	{ 350	,8	,1	, &fEM_B8UC10RIM},	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
	{ 351	,8	,1	, &fEM_B8UV80RDU},	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
	{ 352	,8	,1	, &fEM_A8UV80RDU},	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
	{ 353	,8	,1	, &fEM_A8UC10RIM},	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
	{ 354	,8	,1	, &fEM_A8UC11RIM},	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
	{ 355	,8	,1	, &fEM_A8UC20RIM},	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
	{ 356	,8	,1	, &fEM_A8UC21RIM},	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
	{ 357	,8	,1	, &fEM_A6UC10RIM},	//(A6UC10RIM) Время полного хода БЗ (сек)
	{ 358	,8	,1	, &fEM_R1UC10RIM},	//(R1UC10RIM) Время полного хода МДЗ сек
	{ 359	,8	,1	, &fEM_A5UC10RIM},	//(A5UC10RIM) Время полного хода НЛ сек
	{ 360	,8	,1	, &fEM_A0UN01RIM},	//(A0UN01RIM) Мощность источника нейтронов ИНИ
	{ 361	,8	,1	, &fEM_R4UC22RIM},	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
	{ 362	,8	,1	, &fEM_A1UG01RDU},	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
	{ 363	,8	,1	, &fEM_A2UG01RDU},	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
	{ 364	,8	,1	, &fEM_A3UG01RDU},	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
	{ 365	,8	,1	, &fEM_R7UC10RIM},	//(R7UC10RIM) X-координата КНК53М R7IN13 см
	{ 366	,8	,1	, &fEM_R7UC19RIM},	//(R7UC19RIM) Y-координата СНМ-11 (11) см
	{ 367	,8	,1	, &fEM_R7UI02RIM},	//(R7UI02RIM) Коэффициент усиления уровня радиации
	{ 368	,8	,1	, &fEM_R7UL01RIM},	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
	{ 369	,8	,1	, &fEM_A2UR00RIM},	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{ 370	,8	,1	, &fEM_A2UR01RIM},	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{ 371	,8	,1	, &fEM_A0UN02RIM},	//(A0UN02RIM) Мощность источника нейтронов с АНИ
	{ 372	,8	,1	, &fEM_R0UR30RIM},	//(R0UR30RIM) Реактивность вносимая образцами (долл)
	{ 373	,8	,1	, &fEM_R0UR01RIM},	//(R0UR01RIM) Стартовая отрицательная реактивность
	{ 374	,8	,1	, &fEM_R0UT02RDU},	//(R0UT02RDU) Верхний предел шкалы датчика температуры
	{ 375	,8	,1	, &fEM_R0UT01RDU},	//(R0UT01RDU) Нижний предел шкалы датчика температуры
	{ 376	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{ 377	,8	,1	, &fEM_A2UP03RDU},	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{ 378	,8	,1	, &fEM_A2UP04RDU},	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{ 379	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{ 380	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 381	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 382	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{ 383	,8	,1	, &fEM_R7UI74RIM},	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
	{ 384	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{ 385	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 386	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 387	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{ 388	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{ 389	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{ 390	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 391	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 392	,8	,1	, &fEM_A8UC08RDU},	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
	{ 393	,8	,1	, &fEM_B8UC08RDU},	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
	{ 394	,8	,1	, &fEM_R4UC08RDU},	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
	{ 395	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 396	,8	,1	, &fEM_R7UX01RSS},	//(R7UX01RSS) X-координата камеры R7IN11
	{ 397	,8	,1	, &fEM_R7UX02RSS},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{ 398	,8	,1	, &fEM_R7UX04RSS},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{ 399	,8	,1	, &fEM_R7UX05RSS},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{ 400	,8	,1	, &fEM_R7UX06RSS},	//(R7UX06RSS) X-координата камеры R7IN23 (см)
	{ 401	,8	,1	, &fEM_R7UX07RSS},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{ 402	,8	,1	, &fEM_R7UX08RSS},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{ 403	,8	,1	, &fEM_R7UX09RSS},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{ 404	,8	,1	, &fEM_R7UY01RSS},	//(R7UY01RSS) Y-координата камеры R7IN11
	{ 405	,8	,1	, &fEM_R7UY02RSS},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{ 406	,8	,1	, &fEM_R7UY04RSS},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{ 407	,8	,1	, &fEM_R7UY05RSS},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{ 408	,8	,1	, &fEM_R7UY06RSS},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{ 409	,8	,1	, &fEM_R7UY07RSS},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{ 410	,8	,1	, &fEM_R7UY08RSS},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{ 411	,8	,1	, &fEM_R7UY09RSS},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{ 412	,8	,1	, &fEM_R7UX10RSS},	//(R7UX10RSS) X-координата камеры R7IN41
	{ 413	,8	,1	, &fEM_R7UX11RSS},	//(R7UX11RSS) X-координата камеры R7IN42
	{ 414	,8	,1	, &fEM_R7UX12RSS},	//(R7UX12RSS) X-координата камеры R7IN43
	{ 415	,8	,1	, &fEM_R7UY10RSS},	//(R7UY10RSS) Y-координата камеры R7IN41
	{ 416	,8	,1	, &fEM_R7UY11RSS},	//(R7UY11RSS) Y-координата камеры R7IN42
	{ 417	,8	,1	, &fEM_R7UY12RSS},	//(R7UY12RSS) Y-координата камеры R7IN43
	{ 418	,8	,1	, &fEM_A0UX01RSS},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{ 419	,8	,1	, &fEM_A0UX02RSS},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{ 420	,8	,1	, &fEM_A0UX03RSS},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{ 421	,8	,1	, &fEM_A0UX04RSS},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{ 422	,8	,1	, &fEM_A0UX05RSS},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{ 423	,8	,1	, &fEM_A0UX06RSS},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{ 424	,8	,1	, &fEM_A0UX07RSS},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{ 425	,8	,1	, &fEM_A0UX08RSS},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{ 426	,8	,1	, &fEM_A0UX09RSS},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{ 427	,8	,1	, &fEM_A0UX10RSS},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{ 428	,8	,1	, &fEM_A0UX11RSS},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{ 429	,8	,1	, &fEM_A0UX12RSS},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{ 430	,8	,1	, &fEM_B0UX01RSS},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{ 431	,8	,1	, &fEM_B0UX02RSS},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{ 432	,8	,1	, &fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{ 433	,8	,1	, &fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
	{ 434	,8	,1	, &fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{ 435	,8	,1	, &fEM_B0UX06RSS},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{ 436	,8	,1	, &fEM_B0UX07RSS},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{ 437	,8	,1	, &fEM_B0UX08RSS},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{ 438	,8	,1	, &fEM_B0UX09RSS},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{ 439	,8	,1	, &fEM_B0UX10RSS},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{ 440	,8	,1	, &fEM_B0UX11RSS},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{ 441	,8	,1	, &fEM_B0UX12RSS},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{ 442	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{ 443	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
	{ 444	,8	,1	, &fEM_R4US80RDU},	//(R4US80RDU) Тормозной путь тележки (мм)
	{ 445	,8	,1	, &fEM_R7UI71RIM},	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{ 446	,8	,1	, &fEM_R7UI72RIM},	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{ 447	,8	,1	, &fEM_R7UI73RIM},	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
	{ 448	,8	,1	, &fEM_A1UP01RIM},	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
	{ 449	,8	,1	, &fEM_A2UP01RIM},	//(A2UP01RIM) Текущее давление на сброс РБ
	{ 450	,8	,1	, &fEM_A0UP02RIM},	//(A0UP02RIM) Текущее давление в АЗ1,2
	{ 451	,8	,1	, &fEM_A3UP01RIM},	//(A3UP01RIM) Текущее давление на СПУСК ИС
	{ 452	,8	,1	, &fEM_A1UP82RIM},	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{ 453	,8	,1	, &fEM_A3UP02RDU},	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
	{ 454	,8	,1	, &fEM_A1UV02RIM},	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{ 455	,8	,1	, &fEM_A3UV02RIM},	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{ 456	,8	,1	, &fEM_A2UV02RIM},	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{ 457	,8	,1	, &fEM_B8US80RDU},	//(B8US80RDU) Тормозной путь АЗ2 (мм)
	{ 458	,8	,1	, &fEM_A8US80RDU},	//(A8US80RDU) Тормозной путь ДС2 (мм)
	{ 459	,8	,1	, &fEM_A6US80RDU},	//(A6US80RDU) Тормозной путь БЗ (мм)
	{ 460	,8	,1	, &fEM_A1US07RDU},	//(A1US07RDU) Постоянная времени масляного демпфера ББ
	{ 461	,8	,1	, &fEM_A2US07RDU},	//(A2US07RDU) Постоянная времени масляного демпфера РБ
	{ 462	,8	,1	, &fEM_A3US07RDU},	//(A3US07RDU) Постоянная времени масляного демпфера ИС
	{ 463	,8	,1	, &fEM_R7UI75RIM},	//(R7UI75RIM) Множитель к уровню радиации
	{ 464	,8	,1	, &fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{ 465	,8	,1	, &fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{ 466	,8	,1	, &fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{ 467	,8	,1	, &fEM_R0UR01RSS},	//(R0UR01RSS) Уровень по мощности РУ блокировки автоматического подъёма ББ
	{ 468	,8	,1	, &fEM_R0UL52RSS},	//(R0UL52RSS) Уровень АС по мощности
	{ 469	,8	,1	, &fEM_R0UL41RSS},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{ 470	,8	,1	, &fEM_R0UL51RSS},	//(R0UL51RSS) Уровень АС по периоду разгона
	{ 471	,8	,1	, &fEM_R0UL42RSS},	//(R0UL42RSS) Уровень ПС по мощности
	{ 472	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 473	,8	,1	, &fEM_R0UN03RSS},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{ 474	,8	,1	, &fEM_A4UL10RIM},	//(A4UL10RIM) Время полного перемещения НИ сек
	{ 475	,8	,1	, &fEM_A9UL10RIM},	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
	{ 476	,8	,1	, &fEM_R3UL10RIM},	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
	{ 477	,8	,1	, &fEM_R5UL10RIM},	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
	{ 478	,8	,1	, &fEM_R6UL10RIM},	//(R6UL10RIM) Время полного хода кран-балки сек
	{ 479	,1	,1	, &lEM_C1AD31LRP},	//(C1AD31LRP) Общий сброс от РПУ
	{ 480	,1	,1	, &lEM_R0IE01LRP},	//(R0IE01LRP) Отключение питание детекторов
	{ 481	,1	,1	, &lEM_R0IE02LRP},	//(R0IE02LRP) Отключить питание ПР, ПУ
	{ 482	,8	,1	, &fEM_A2UP02RIM},	//(A2UP02RIM) Текущее давление на подъём РБ
	{ 483	,8	,1	, &fEM_A2UP03RIM},	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
	{ 484	,8	,1	, &fEM_A0UP01RIM},	//(A0UP01RIM) Текущее давление в АЗ1,2
	{ 485	,8	,1	, &fEM_A3UP02RIM},	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
	{ 486	,8	,1	, &fEM_A4UP01RIM},	//(A4UP01RIM) Текущее давление на подъём НИ
	{ 487	,8	,1	, &fEM_A4UP02RIM},	//(A4UP02RIM) Нижняя граница давления на подъём НИ
	{ 488	,8	,1	, &fEM_R7UI76RIM},	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{ 489	,8	,1	, &fEM_R7UI77RIM},	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{ 490	,3	,1	, &iEM_TERBB1},	//(TERBB1) Неисправности  ББ1
	{ 491	,8	,1	, &fEM_A1MC02RC1},	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
	{ 492	,8	,1	, &fEM_A1MV02RC1},	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
	{ 493	,3	,1	, &iEM_TERBB2},	//(TERBB2) Неисправности  ББ2
	{ 494	,8	,1	, &fEM_B1MC02RC1},	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
	{ 495	,8	,1	, &fEM_B1MV02RC1},	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
	{ 496	,3	,1	, &iEM_TERRB2},	//(TERRB2) Неисправности  РБ2
	{ 497	,8	,1	, &fEM_B2MC02RC1},	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
	{ 498	,8	,1	, &fEM_B2MV02RC1},	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
	{ 499	,3	,1	, &iEM_TERRB1},	//(TERRB1) Неисправности  РБ1
	{ 500	,8	,1	, &fEM_A2MC02RC1},	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
	{ 501	,8	,1	, &fEM_A2MV02RC1},	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
	{ 502	,3	,1	, &iEM_TERIS2},	//(TERIS2) Неисправности  ИС2
	{ 503	,8	,1	, &fEM_B3MC02RC1},	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
	{ 504	,8	,1	, &fEM_B3MV02RC1},	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
	{ 505	,3	,1	, &iEM_TERIS1},	//(TERIS1) Неисправности  ИС1
	{ 506	,8	,1	, &fEM_A3MC02RC1},	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
	{ 507	,8	,1	, &fEM_A3MV02RC1},	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
	{ 508	,3	,1	, &iEM_TERA1IE04LDU},	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
	{ 509	,3	,1	, &iEM_TERA1IE03LDU},	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
	{ 510	,8	,1	, &fEM_A1MC01RC1},	//(A1MC01RC1) Заданная координата  ББ1 от ИС
	{ 511	,3	,1	, &iEM_TERB1IE03LDU},	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
	{ 512	,3	,1	, &iEM_TERB1IE04LDU},	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
	{ 513	,8	,1	, &fEM_B1MC01RC1},	//(B1MC01RC1) Заданная координата ББ2 от ИС
	{ 514	,8	,1	, &fEM_B1MV01RC1},	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
	{ 515	,8	,1	, &fEM_B2MC01RC1},	//(B2MC01RC1) Заданная координата РБ2 от ИС
	{ 516	,8	,1	, &fEM_B2MV01RC1},	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
	{ 517	,8	,1	, &fEM_A3MC01RC1},	//(A3MC01RC1) Заданная координата ИС1 от ИС
	{ 518	,8	,1	, &fEM_A3MV01RC1},	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
	{ 519	,8	,1	, &fEM_B3MC01RC1},	//(B3MC01RC1) Заданная координата ИС2 от ИС
	{ 520	,8	,1	, &fEM_B3MV01RC1},	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
	{ 521	,3	,1	, &iEM_TERA2SS21LIM},	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
	{ 522	,3	,1	, &iEM_TERA2SS12LIM},	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
	{ 523	,3	,1	, &iEM_TERR6SS21LIM},	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
	{ 524	,3	,1	, &iEM_TERA2VP82LIM},	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
	{ 525	,3	,1	, &iEM_TERA2SS11LIM},	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
	{ 526	,3	,1	, &iEM_TERB3SS21LIM},	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
	{ 527	,3	,1	, &iEM_TERA0MT01RIM},	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
	{ 528	,3	,1	, &iEM_TERB0MT01RIM},	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
	{ 529	,3	,1	, &iEM_TERA2SP01RIM},	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
	{ 530	,3	,1	, &iEM_TERB2SP01RIM},	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
	{ 531	,3	,1	, &iEM_TERB3SP02RIM},	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{ 532	,3	,1	, &iEM_TERA3SC01RIM},	//(TERA3SC01RIM) Искажение: Координата штока ИС1
	{ 533	,3	,1	, &iEM_TERA3VP81LIM},	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
	{ 534	,3	,1	, &iEM_TERA2SC01RIM},	//(TERA2SC01RIM) Искажение: Координата штока РБ1
	{ 535	,3	,1	, &iEM_TERA2SS33LIM},	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{ 536	,3	,1	, &iEM_TERA3SS21LIM},	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
	{ 537	,3	,1	, &iEM_TERA3SS33LIM},	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{ 538	,3	,1	, &iEM_TERA3SS31LIM},	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{ 539	,3	,1	, &iEM_TERB3SS31LIM},	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{ 540	,3	,1	, &iEM_TERB3SS33LIM},	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{ 541	,3	,1	, &iEM_TERB3SC01RIM},	//(TERB3SC01RIM) Искажение: Координата штока ИС2
	{ 542	,3	,1	, &iEM_TERA3SS11LIM},	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
	{ 543	,3	,1	, &iEM_TERB3SS11LIM},	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
	{ 544	,3	,1	, &iEM_TERR6IS64LIM},	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
	{ 545	,3	,1	, &iEM_TERB3SS22LIM},	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
	{ 546	,3	,1	, &iEM_TERA3SS22LIM},	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
	{ 547	,3	,1	, &iEM_TERA3SP02RIM},	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{ 548	,3	,1	, &iEM_TERR6IS62LIM},	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
	{ 549	,3	,1	, &iEM_TERR6IS66LIM},	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 550	,3	,1	, &iEM_TERR6IS67LIM},	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 551	,3	,1	, &iEM_TERA0VP81LIM},	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
	{ 552	,3	,1	, &iEM_TERB0VP81LIM},	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
	{ 553	,3	,1	, &iEM_TERR0VP81LIM},	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{ 554	,3	,1	, &iEM_TERR6IS68LIM},	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{ 555	,3	,1	, &iEM_TERR7SI74RIM},	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
	{ 556	,3	,1	, &iEM_TERA5SS21LIM},	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
	{ 557	,3	,1	, &iEM_TERB5SS11LIM},	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
	{ 558	,3	,1	, &iEM_TERA5SS11LIM},	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{ 559	,3	,1	, &iEM_TERA9SS11LIM},	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
	{ 560	,3	,1	, &iEM_TERB2SS11LIM},	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
	{ 561	,3	,1	, &iEM_TERB2SS12LIM},	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
	{ 562	,3	,1	, &iEM_TERB2SS21LIM},	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
	{ 563	,3	,1	, &iEM_TERR3SS11LIM},	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
	{ 564	,3	,1	, &iEM_TERB2SC01RIM},	//(TERB2SC01RIM) Искажение: Координата штока РБ2
	{ 565	,3	,1	, &iEM_TERR3SS21LIM},	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
	{ 566	,3	,1	, &iEM_TERR5SS11LIM},	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
	{ 567	,3	,1	, &iEM_TERA4SS11LIM},	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
	{ 568	,3	,1	, &iEM_TERR1SS11LIM},	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
	{ 569	,3	,1	, &iEM_TERR1SS21LIM},	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
	{ 570	,3	,1	, &iEM_TERR2SS11LIM},	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
	{ 571	,3	,1	, &iEM_TERR2SS21LIM},	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
	{ 572	,3	,1	, &iEM_TERA4VP82LIM},	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
	{ 573	,3	,1	, &iEM_TERB4SS21LIM},	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
	{ 574	,3	,1	, &iEM_TERR5SS21LIM},	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
	{ 575	,3	,1	, &iEM_TERB6SS21LIM},	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
	{ 576	,3	,1	, &iEM_TERB4SS11LIM},	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
	{ 577	,3	,1	, &iEM_TERA4SS21LIM},	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
	{ 578	,3	,1	, &iEM_TERA6MS11LIM},	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
	{ 579	,3	,1	, &iEM_TERA6SS21LIM},	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
	{ 580	,3	,1	, &iEM_TERB6SS11LIM},	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
	{ 581	,3	,1	, &iEM_TERR4SS11LIM},	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
	{ 582	,3	,1	, &iEM_TERR4MS21LIM},	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
	{ 583	,3	,1	, &iEM_TERR4SS12LIM},	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
	{ 584	,3	,1	, &iEM_TERR4SS22LIM},	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
	{ 585	,3	,1	, &iEM_TERR8SS11LIM},	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
	{ 586	,3	,1	, &iEM_TERB8SC01RIM},	//(TERB8SC01RIM) Искажение: Координата АЗ2
	{ 587	,3	,1	, &iEM_TERA8SC01RIM},	//(TERA8SC01RIM) Искажение: Координата ДС2
	{ 588	,3	,1	, &iEM_TERB8SS12LIM},	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
	{ 589	,3	,1	, &iEM_TERA8SS12LIM},	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
	{ 590	,3	,1	, &iEM_TERB8SS22LIM},	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
	{ 591	,3	,1	, &iEM_TERA8SS22LIM},	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
	{ 592	,3	,1	, &iEM_TERA9SS21LIM},	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
	{ 593	,3	,1	, &iEM_TERB9SS21LIM},	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
	{ 594	,3	,1	, &iEM_TERB9SS11LIM},	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
	{ 595	,3	,1	, &iEM_TERB5SS21LIM},	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
	{ 596	,3	,1	, &iEM_TERA1SS21LIM},	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
	{ 597	,3	,1	, &iEM_TERA1SS11LIM},	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
	{ 598	,3	,1	, &iEM_TERA1SC01RIM},	//(TERA1SC01RIM) Искажение: Координата штока ББ1
	{ 599	,3	,1	, &iEM_TERA1SS12LIM},	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
	{ 600	,3	,1	, &iEM_TERB1SS21LIM},	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
	{ 601	,3	,1	, &iEM_TERB1SS11LIM},	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
	{ 602	,3	,1	, &iEM_TERB1MC01RIM},	//(TERB1MC01RIM) Искажение: Координата штока ББ2
	{ 603	,3	,1	, &iEM_TERB1SS12LIM},	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
	{ 604	,3	,1	, &iEM_TERR0IE43LIM},	//(TERR0IE43LIM) Исправность ВИП 0,5 4канала
	{ 605	,3	,1	, &iEM_TERR0IE41LIM},	//(TERR0IE41LIM) Исправность ВИП 1,6 (№17) СНМ11 4канала
	{ 606	,1	,1	, &lEM_A0EE06LC1},	//(A0EE06LC1) Исправность АКНП4 от диагностики контроллера (От ИС)
	{ 607	,3	,1	, &iEM_TERR0IE33LIM},	//(TERR0IE33LIM) Искажение:Исправность ВИП 0,5  3канала
	{ 608	,3	,1	, &iEM_TERR0IE31LIM},	//(TERR0IE31LIM) Искажение: Исправность ВИП 1,6 (№14) СНМ11 3канала
	{ 609	,1	,1	, &lEM_A0EE05LC1},	//(A0EE05LC1) Исправность АКНП3 от диагностики контроллера (От ИС)
	{ 610	,3	,1	, &iEM_TERR0IE11LIM},	//(TERR0IE11LIM) Искажение: Исправность ВИП 1,6 (№8) СНМ11 1канала
	{ 611	,3	,1	, &iEM_TERR0IE13LIM},	//(TERR0IE13LIM) Искажение: Исправность ВИП 0,5  1канала
	{ 612	,1	,1	, &lEM_A0EE03LC1},	//(A0EE03LC1) Исправность АКНП1 от диагностики контроллера (От ИС)
	{ 613	,3	,1	, &iEM_TERR0IE23LIM},	//(TERR0IE23LIM) Искажение: Исправность ВИП 0,5 (№13) КНК53М 2канала
	{ 614	,3	,1	, &iEM_TERR0IE21LIM},	//(TERR0IE21LIM) Искажение: Исправность ВИП 1,6 (№11) СНМ11 2канала
	{ 615	,1	,1	, &lEM_A0EE04LC1},	//(A0EE04LC1) Исправность АКНП2 от диагностики контроллера (От ИС)
	{ 616	,3	,1	, &iEM_TERTLG},	//(TERTLG) Неисправности  тележки от ИС
	{ 617	,8	,1	, &fEM_R4MC01RC1},	//(R4MC01RC1) Заданная координата тележки от ИС
	{ 618	,8	,1	, &fEM_R4MV01RC1},	//(R4MV01RC1) Заданная скорость тележки от ИС
	{ 619	,3	,1	, &iEM_TERMAZ2},	//(TERMAZ2) Неисправности АЗ2 от ИС
	{ 620	,8	,1	, &fEM_B8MC01RC1},	//(B8MC01RC1) аданная координата АЗ2 от ИС
	{ 621	,8	,1	, &fEM_B8MV01RC1},	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
	{ 622	,3	,1	, &iEM_TERDS2},	//(TERDS2) Неисправности ДС2 от ИС
	{ 623	,8	,1	, &fEM_A8MC01RC1},	//(A8MC01RC1) Заданная координата ДС2 от ИС
	{ 624	,8	,1	, &fEM_A8MV01RC1},	//(A8MV01RC1) Заданная скорость ДС2 от ИС
	{ 625	,3	,1	, &iEM_TERBZ1},	//(TERBZ1) Неисправности БЗ1
	{ 626	,8	,1	, &fEM_A6MC01RC1},	//(A6MC01RC1) Заданная координата БЗ1 от ИС
	{ 627	,8	,1	, &fEM_A6MV01RC1},	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
	{ 628	,3	,1	, &iEM_TERBZ2},	//(TERBZ2) Неисправности БЗ2
	{ 629	,8	,1	, &fEM_B6MC01RC1},	//(B6MC01RC1) Заданная координата БЗ2 от ИС
	{ 630	,8	,1	, &fEM_B6MV01RC1},	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
	{ 631	,1	,1	, &lEM_R3AD10LC1},	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
	{ 632	,1	,1	, &lEM_R3AD20LC1},	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
	{ 633	,1	,1	, &lEM_R6AD10LC1},	//(R6AD10LC1) Выкатить кран-балку от ИС
	{ 634	,1	,1	, &lEM_R5AD10LC1},	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
	{ 635	,1	,1	, &lEM_R5AD20LC1},	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
	{ 636	,3	,1	, &iEM_TERMDZ2},	//(TERMDZ2) Неисправности МДЗ2
	{ 637	,8	,1	, &fEM_R2MC01RC1},	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
	{ 638	,8	,1	, &fEM_R2MV01RC1},	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
	{ 639	,3	,1	, &iEM_TERMDZ1},	//(TERMDZ1) Неисправности МДЗ1
	{ 640	,8	,1	, &fEM_R1MC01RC1},	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
	{ 641	,8	,1	, &fEM_R1MV01RC1},	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
	{ 642	,3	,1	, &iEM_TERNL1},	//(TERNL1) Неисправности НЛ1
	{ 643	,8	,1	, &fEM_A5MC01RC1},	//(A5MC01RC1) Заданная координата НЛ1 от ИС
	{ 644	,8	,1	, &fEM_A5MV01RC1},	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
	{ 645	,3	,1	, &iEM_TERNL2},	//(TERNL2) Неисправности НЛ2
	{ 646	,8	,1	, &fEM_B5MC01RC1},	//(B5MC01RC1) Заданная координата НЛ2 от ИС
	{ 647	,8	,1	, &fEM_B5MV01RC1},	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
	{ 648	,1	,1	, &lEM_R8AD10LC1},	//(R8AD10LC1) Установить аварийный НИ от ИС
	{ 649	,8	,1	, &fEM_A1UC08RIM},	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
	{ 650	,8	,1	, &fEM_A2UC08RIM},	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
	{ 651	,8	,1	, &fEM_A3UC08RIM},	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
	{ 652	,8	,1	, &fEM_R0UL01RSS},	//(R0UL01RSS) Шаг (мс) измерения периода
	{ 653	,8	,1	, &fEM_R0UL03RSS},	//(R0UL03RSS) Предельное время ожидания роста потока (сек)
	{ 654	,3	,1	, &iEM_TERB2SS33LIM},	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{ 655	,3	,1	, &iEM_TERA1VP81LIM},	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
	{ 656	,3	,1	, &iEM_TERB1VP81LIM},	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
	{ 657	,8	,1	, &fEM_A0UT03RSP},	//(A0UT03RSP) Стартовая  температура АЗ1 град
	{ 658	,8	,1	, &fEM_A0UR01RSP},	//(A0UR01RSP) Стартовая  реактивность АЗ1
	{ 659	,8	,1	, &fEM_A0UR02RSP},	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
	{ 660	,8	,1	, &fEM_B0UT03RSP},	//(B0UT03RSP) Стартовая  температура АЗ2 град
	{ 661	,8	,1	, &fEM_A1MC01RSP},	//(A1MC01RSP) Стартовая координата  ББ1
	{ 662	,8	,1	, &fEM_A1MC02RSP},	//(A1MC02RSP) Стартовая координата штока ББ1
	{ 663	,8	,1	, &fEM_A1MV01RSP},	//(A1MV01RSP) Стартовая скорость движения  ББ1
	{ 664	,8	,1	, &fEM_A1MV02RSP},	//(A1MV02RSP) Стартовая скорость движения  ББ1
	{ 665	,8	,1	, &fEM_B1MC01RSP},	//(B1MC01RSP) Стартовая координата  ББ2
	{ 666	,8	,1	, &fEM_B1MV01RSP},	//(B1MV01RSP) Стартовая скорость движения  ББ2
	{ 667	,8	,1	, &fEM_B1MC02RSP},	//(B1MC02RSP) Стартовая координата штока ББ2
	{ 668	,8	,1	, &fEM_B1MV02RSP},	//(B1MV02RSP) Стартовая скорость движения  ББ2
	{ 669	,8	,1	, &fEM_A2MC01RC1},	//(A2MC01RC1) Заданная координата РБ1 от ИС
	{ 670	,8	,1	, &fEM_A2MV01RC1},	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
	{ 671	,8	,1	, &fEM_A2MC01RSP},	//(A2MC01RSP) Стартовая координата  РБ1
	{ 672	,8	,1	, &fEM_A2MV01RSP},	//(A2MV01RSP) Стартовая скорость движения  РБ1
	{ 673	,8	,1	, &fEM_A2MC02RSP},	//(A2MC02RSP) Стартовая координата штока РБ1
	{ 674	,8	,1	, &fEM_A2MV02RSP},	//(A2MV02RSP) Стартовая скорость движения  РБ1
	{ 675	,8	,1	, &fEM_B2MC01RSP},	//(B2MC01RSP) Стартовая координата  РБ2
	{ 676	,8	,1	, &fEM_B2MV01RSP},	//(B2MV01RSP) Стартовая скорость движения  РБ2
	{ 677	,8	,1	, &fEM_B2MC02RSP},	//(B2MC02RSP) Стартовая координата штока РБ2
	{ 678	,8	,1	, &fEM_B2MV02RSP},	//(B2MV02RSP) Стартовая скорость движения  РБ2
	{ 679	,8	,1	, &fEM_A3MC01RSP},	//(A3MC01RSP) Стартовая координата  ИС1
	{ 680	,8	,1	, &fEM_A3MV01RSP},	//(A3MV01RSP) Стартовая скорость движения  ИС1
	{ 681	,8	,1	, &fEM_A3MC02RSP},	//(A3MC02RSP) Стартовая координата штока ИС1
	{ 682	,8	,1	, &fEM_A3MV02RSP},	//(A3MV02RSP) Стартовая скорость движения  ИС1
	{ 683	,8	,1	, &fEM_B3MC01RSP},	//(B3MC01RSP) Стартовая координата  ИС2
	{ 684	,8	,1	, &fEM_B3MV01RSP},	//(B3MV01RSP) Стартовая скорость движения  ИС2
	{ 685	,8	,1	, &fEM_B3MC02RSP},	//(B3MC02RSP) Стартовая координата штока ИС2
	{ 686	,8	,1	, &fEM_B3MV02RSP},	//(B3MV02RSP) Стартовая скорость движения  ИС2
	{ 687	,8	,1	, &fEM_B8MC01RSP},	//(B8MC01RSP) Стартовая координата АЗ2
	{ 688	,8	,1	, &fEM_B8MV01RSP},	//(B8MV01RSP) Стартовая скорость АЗ2
	{ 689	,8	,1	, &fEM_A8MC01RSP},	//(A8MC01RSP) Стартовая координата ДС2
	{ 690	,8	,1	, &fEM_A8MV01RSP},	//(A8MV01RSP) Стартовая скорость ДС2
	{ 691	,8	,1	, &fEM_A6MC01RSP},	//(A6MC01RSP) Стартовая координата БЗ1
	{ 692	,8	,1	, &fEM_A6MV01RSP},	//(A6MV01RSP) Стартовая скорость БЗ1
	{ 693	,8	,1	, &fEM_B6MC01RSP},	//(B6MC01RSP) Стартовая координата БЗ2
	{ 694	,8	,1	, &fEM_B6MV01RSP},	//(B6MV01RSP) Стартовая скорость БЗ2
	{ 695	,8	,1	, &fEM_R3UC01RSP},	//(R3UC01RSP) Стартовая координата Гомогенных дверей
	{ 696	,8	,1	, &fEM_R3UV01RSP},	//(R3UV01RSP) Стартовая скорость Гомогенных дверей
	{ 697	,8	,1	, &fEM_R5UC01RSP},	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
	{ 698	,8	,1	, &fEM_R5UV01RSP},	//(R5UV01RSP) Стартовая скорость Ворот отстойной зоны
	{ 699	,8	,1	, &fEM_R6UC01RSP},	//(R6UC01RSP) Стартовая координата Кран-балки
	{ 700	,8	,1	, &fEM_R6UV01RSP},	//(R6UV01RSP) Стартовая скорость Кран-балки
	{ 701	,8	,1	, &fEM_R2MC01RSP},	//(R2MC01RSP) Стартовая координата МДЗ2
	{ 702	,8	,1	, &fEM_R2MV01RSP},	//(R2MV01RSP) Стартовая скорость МДЗ2
	{ 703	,8	,1	, &fEM_R1MC01RSP},	//(R1MC01RSP) Стартовая координата МДЗ1
	{ 704	,8	,1	, &fEM_R1MV01RSP},	//(R1MV01RSP) Стартовая скорость МДЗ1
	{ 705	,8	,1	, &fEM_A5MC01RSP},	//(A5MC01RSP) Стартовая координата НЛ1
	{ 706	,8	,1	, &fEM_A5MV01RSP},	//(A5MV01RSP) Стартовая скорость НЛ1
	{ 707	,8	,1	, &fEM_B5MC01RSP},	//(B5MC01RSP) Стартовая координата НЛ2
	{ 708	,8	,1	, &fEM_B5MV01RSP},	//(B5MV01RSP) Стартовая скорость НЛ2
	{ 709	,8	,1	, &fEM_A9MC01RSP},	//(A9MC01RSP) Стартовая координата НИ ДС1
	{ 710	,8	,1	, &fEM_A9MV01RSP},	//(A9MV01RSP) Стартовая скорость НИ ДС1
	{ 711	,8	,1	, &fEM_B9MC01RSP},	//(B9MC01RSP) Стартовая координата НИ ДС2
	{ 712	,8	,1	, &fEM_B9MV01RSP},	//(B9MV01RSP) Стартовая скорость НИ ДС2
	{ 713	,8	,1	, &fEM_A4MC01RSP},	//(A4MC01RSP) Стартовая координата НИ1
	{ 714	,8	,1	, &fEM_A4MV01RSP},	//(A4MV01RSP) Стартовая скорость НИ1
	{ 715	,8	,1	, &fEM_B4MC01RSP},	//(B4MC01RSP) Стартовая координата НИ2
	{ 716	,8	,1	, &fEM_B4MV01RSP},	//(B4MV01RSP) Стартовая скорость НИ2
	{ 717	,8	,1	, &fEM_R4MC01RSP},	//(R4MC01RSP) Стартовая координата тележки
	{ 718	,8	,1	, &fEM_R4MV01RSP},	//(R4MV01RSP) Стартовая скорость тележки
	{ 719	,8	,1	, &fEM_A1MV01RC1},	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
	{ 720	,3	,1	, &iEM_TERB7MS31LIM},	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{ 721	,3	,1	, &iEM_TERA7MS31LIM},	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{ 722	,8	,1	, &fEM_R7UX03RSS},	//(R7UX03RSS) X-координата камеры R7IN13 см
	{ 723	,8	,1	, &fEM_R7UY03RSS},	//(R7UY03RSS) Y-координата камеры R7IN13 (см)
	{ 724	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 см
	{ 725	,3	,1	, &iEM_TERA6VS12LIM},	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{ 726	,3	,1	, &iEM_TERA6VS22LIM},	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{ 727	,3	,1	, &iEM_TERB6VS12LIM},	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{ 728	,3	,1	, &iEM_TERB6VS22LIM},	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{ 729	,3	,1	, &iEM_TERA5VS22LIM},	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
	{ 730	,3	,1	, &iEM_TERA5VS12LIM},	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
	{ 731	,3	,1	, &iEM_TERB5VS12LIM},	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
	{ 732	,3	,1	, &iEM_TERB5VS22LIM},	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
	{ 733	,3	,1	, &iEM_TERR1VS12LIM},	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
	{ 734	,3	,1	, &iEM_TERR1VS22LIM},	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
	{ 735	,3	,1	, &iEM_TERR2VS12LIM},	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
	{ 736	,3	,1	, &iEM_TERR2VS22LIM},	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
	{ 737	,3	,1	, &iEM_TERR4VS12LDU},	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{ 738	,3	,1	, &iEM_TERR4VS22LDU},	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{ 739	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 740	,1	,1	, &internal1_m1118_Out10},	//(internal1_m1118_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 741	,1	,1	, &internal1_m1117_Out10},	//(internal1_m1117_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 742	,1	,1	, &internal1_m943_Out10},	//(internal1_m943_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 743	,1	,1	, &internal1_m942_Out10},	//(internal1_m942_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 744	,1	,1	, &internal1_m941_Out10},	//(internal1_m941_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 745	,1	,1	, &internal1_m940_Out10},	//(internal1_m940_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 746	,1	,1	, &internal1_m691_Out10},	//(internal1_m691_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 747	,1	,1	, &internal1_m690_Out10},	//(internal1_m690_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 748	,1	,1	, &internal1_m669_Out10},	//(internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 749	,1	,1	, &internal1_m668_Out10},	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 750	,1	,1	, &internal1_m689_Out10},	//(internal1_m689_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 751	,1	,1	, &internal1_m688_Out10},	//(internal1_m688_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 752	,1	,1	, &internal1_m667_Out10},	//(internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 753	,1	,1	, &internal1_m666_Out10},	//(internal1_m666_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 754	,1	,1	, &internal1_m527_Out10},	//(internal1_m527_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 755	,1	,1	, &internal1_m545_Out10},	//(internal1_m545_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 756	,1	,1	, &internal1_m409_Out10},	//(internal1_m409_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 757	,1	,1	, &internal1_m486_q0},	//(internal1_m486_q0) q0 - внутренний параметр
	{ 758	,1	,1	, &internal1_m487_q0},	//(internal1_m487_q0) q0 - внутренний параметр
	{ 759	,1	,1	, &internal1_m472_q0},	//(internal1_m472_q0) q0 - внутренний параметр
	{ 760	,1	,1	, &internal1_m473_q0},	//(internal1_m473_q0) q0 - внутренний параметр
	{ 761	,8	,1	, &internal1_m642_tx},	//(internal1_m642_tx) tx - время накопленное сек
	{ 762	,18	,1	, &internal1_m642_y0},	//(internal1_m642_y0) y0
	{ 763	,8	,1	, &internal1_m630_tx},	//(internal1_m630_tx) tx - время накопленное сек
	{ 764	,18	,1	, &internal1_m630_y0},	//(internal1_m630_y0) y0
	{ 765	,8	,1	, &internal1_m616_tx},	//(internal1_m616_tx) tx - время накопленное сек
	{ 766	,18	,1	, &internal1_m616_y0},	//(internal1_m616_y0) y0
	{ 767	,8	,1	, &internal1_m614_tx},	//(internal1_m614_tx) tx - время накопленное сек
	{ 768	,18	,1	, &internal1_m614_y0},	//(internal1_m614_y0) y0
	{ 769	,1	,1	, &internal1_m206_Out10},	//(internal1_m206_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 770	,1	,1	, &internal1_m224_Out10},	//(internal1_m224_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 771	,1	,1	, &internal1_m41_Out10},	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 772	,1	,1	, &internal1_m56_Out10},	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 773	,1	,1	, &internal1_m1241_Out10},	//(internal1_m1241_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 774	,1	,1	, &internal1_m1238_Out10},	//(internal1_m1238_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 775	,1	,1	, &internal1_m1237_Out10},	//(internal1_m1237_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 776	,8	,1	, &internal1_m1240_Xtek0},	//(internal1_m1240_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 777	,8	,1	, &internal1_m1226_Xtek0},	//(internal1_m1226_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 778	,1	,1	, &internal1_m1227_Out10},	//(internal1_m1227_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 779	,1	,1	, &internal1_m1224_Out10},	//(internal1_m1224_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 780	,1	,1	, &internal1_m1223_Out10},	//(internal1_m1223_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 781	,1	,1	, &internal1_m981_Out10},	//(internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 782	,1	,1	, &internal1_m962_Out10},	//(internal1_m962_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 783	,1	,1	, &internal1_m961_Out10},	//(internal1_m961_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 784	,1	,1	, &internal1_m960_Out10},	//(internal1_m960_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 785	,1	,1	, &internal1_m1139_Out10},	//(internal1_m1139_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 786	,1	,1	, &internal1_m1141_Out10},	//(internal1_m1141_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 787	,1	,1	, &internal1_m1138_Out10},	//(internal1_m1138_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 788	,1	,1	, &internal1_m1140_Out10},	//(internal1_m1140_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 789	,1	,1	, &internal1_m1114_Out10},	//(internal1_m1114_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 790	,1	,1	, &internal1_m1115_Out10},	//(internal1_m1115_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 791	,1	,1	, &internal1_m1113_Out10},	//(internal1_m1113_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 792	,1	,1	, &internal1_m1112_Out10},	//(internal1_m1112_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 793	,1	,1	, &internal1_m976_Out10},	//(internal1_m976_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 794	,1	,1	, &internal1_m928_Out10},	//(internal1_m928_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 795	,1	,1	, &internal1_m927_Out10},	//(internal1_m927_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 796	,1	,1	, &internal1_m926_Out10},	//(internal1_m926_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 797	,1	,1	, &internal1_m925_Out10},	//(internal1_m925_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 798	,1	,1	, &internal1_m977_Out10},	//(internal1_m977_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 799	,1	,1	, &internal1_m958_Out10},	//(internal1_m958_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 800	,1	,1	, &internal1_m1116_Out10},	//(internal1_m1116_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 801	,1	,1	, &internal1_m959_Out10},	//(internal1_m959_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 802	,1	,1	, &internal1_m957_Out10},	//(internal1_m957_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 803	,1	,1	, &internal1_m978_Out10},	//(internal1_m978_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 804	,1	,1	, &internal1_m956_Out10},	//(internal1_m956_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 805	,1	,1	, &internal1_m939_Out10},	//(internal1_m939_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 806	,1	,1	, &internal1_m924_Out10},	//(internal1_m924_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 807	,1	,1	, &internal1_m543_Out10},	//(internal1_m543_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 808	,8	,1	, &internal1_m419_Xtek0},	//(internal1_m419_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 809	,1	,1	, &internal1_m410_Out10},	//(internal1_m410_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 810	,1	,1	, &internal1_m412_Out10},	//(internal1_m412_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 811	,1	,1	, &internal1_m411_Out10},	//(internal1_m411_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 812	,1	,1	, &internal1_m1154_Out10},	//(internal1_m1154_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 813	,1	,1	, &internal1_m1155_Out10},	//(internal1_m1155_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 814	,1	,1	, &internal1_m1153_Out10},	//(internal1_m1153_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 815	,1	,1	, &internal1_m980_Out10},	//(internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 816	,1	,1	, &internal1_m704_Out10},	//(internal1_m704_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 817	,1	,1	, &internal1_m705_Out10},	//(internal1_m705_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 818	,1	,1	, &internal1_m702_Out10},	//(internal1_m702_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 819	,1	,1	, &internal1_m703_Out10},	//(internal1_m703_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 820	,1	,1	, &internal1_m561_Out10},	//(internal1_m561_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 821	,1	,1	, &internal1_m560_Out10},	//(internal1_m560_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 822	,8	,1	, &internal1_m1135_Xtek0},	//(internal1_m1135_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 823	,8	,1	, &internal1_m1137_Xtek0},	//(internal1_m1137_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 824	,1	,1	, &internal1_m701_Out10},	//(internal1_m701_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 825	,1	,1	, &internal1_m685_Out10},	//(internal1_m685_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 826	,1	,1	, &internal1_m665_Out10},	//(internal1_m665_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 827	,1	,1	, &internal1_m684_Out10},	//(internal1_m684_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 828	,1	,1	, &internal1_m664_Out10},	//(internal1_m664_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 829	,1	,1	, &internal1_m337_Out10},	//(internal1_m337_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 830	,1	,1	, &internal1_m336_Out10},	//(internal1_m336_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 831	,1	,1	, &internal1_m321_Out10},	//(internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 832	,1	,1	, &internal1_m320_Out10},	//(internal1_m320_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 833	,1	,1	, &internal1_m562_Out10},	//(internal1_m562_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 834	,1	,1	, &internal1_m350_Out10},	//(internal1_m350_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 835	,8	,1	, &internal1_m334_Xtek0},	//(internal1_m334_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 836	,1	,1	, &internal1_m349_Out10},	//(internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 837	,1	,1	, &internal1_m347_Out10},	//(internal1_m347_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 838	,8	,1	, &internal1_m327_Xtek0},	//(internal1_m327_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 839	,1	,1	, &internal1_m348_Out10},	//(internal1_m348_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 840	,1	,1	, &internal1_m319_Out10},	//(internal1_m319_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 841	,1	,1	, &internal1_m335_Out10},	//(internal1_m335_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 842	,1	,1	, &internal1_m431_Out10},	//(internal1_m431_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 843	,8	,1	, &internal1_m432_Xtek0},	//(internal1_m432_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 844	,1	,1	, &internal1_m430_Out10},	//(internal1_m430_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 845	,1	,1	, &internal1_m429_Out10},	//(internal1_m429_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 846	,1	,1	, &internal1_m428_Out10},	//(internal1_m428_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 847	,1	,1	, &internal1_m979_Out10},	//(internal1_m979_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 848	,1	,1	, &internal1_m150_Out10},	//(internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 849	,1	,1	, &internal1_m149_Out10},	//(internal1_m149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 850	,1	,1	, &internal1_m1102_Out10},	//(internal1_m1102_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 851	,1	,1	, &internal1_m1093_Out10},	//(internal1_m1093_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 852	,8	,2	, &internal1_m1082_tst},	//(internal1_m1082_tst) - массив времени фиксации стартовой мощности
	{ 853	,8	,2	, &internal1_m1082_trz},	//(internal1_m1082_trz) - массив времени фиксации очередного периода
	{ 854	,8	,2	, &internal1_m1082_N1},	//(internal1_m1082_N1) - массив значения мощности в начале замера
	{ 855	,8	,2	, &internal1_m1082_N2},	//(internal1_m1082_N2) - массив значения мощности в конце замера
	{ 856	,8	,1	, &internal1_m1082_Period0},	//(internal1_m1082_Period0) Per - Период разгона РУ
	{ 857	,1	,1	, &internal1_m1082_MyFirstEnterFlag},	//(internal1_m1082_MyFirstEnterFlag)  FirstEnterFlag
	{ 858	,3	,1	, &internal1_m1048_Nk},	//(internal1_m1048_Nk) Nk - ведущая камера
	{ 859	,1	,1	, &internal1_m1043_Out10},	//(internal1_m1043_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 860	,1	,1	, &internal1_m1035_Out10},	//(internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 861	,8	,2	, &internal1_m1024_tst},	//(internal1_m1024_tst) - массив времени фиксации стартовой мощности
	{ 862	,8	,2	, &internal1_m1024_trz},	//(internal1_m1024_trz) - массив времени фиксации очередного периода
	{ 863	,8	,2	, &internal1_m1024_N1},	//(internal1_m1024_N1) - массив значения мощности в начале замера
	{ 864	,8	,2	, &internal1_m1024_N2},	//(internal1_m1024_N2) - массив значения мощности в конце замера
	{ 865	,8	,1	, &internal1_m1024_Period0},	//(internal1_m1024_Period0) Per - Период разгона РУ
	{ 866	,1	,1	, &internal1_m1024_MyFirstEnterFlag},	//(internal1_m1024_MyFirstEnterFlag)  FirstEnterFlag
	{ 867	,3	,1	, &internal1_m994_Nk},	//(internal1_m994_Nk) Nk - ведущая камера
	{ 868	,1	,1	, &internal1_m915_Out10},	//(internal1_m915_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 869	,1	,1	, &internal1_m905_Out10},	//(internal1_m905_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 870	,8	,2	, &internal1_m896_tst},	//(internal1_m896_tst) - массив времени фиксации стартовой мощности
	{ 871	,8	,2	, &internal1_m896_trz},	//(internal1_m896_trz) - массив времени фиксации очередного периода
	{ 872	,8	,2	, &internal1_m896_N1},	//(internal1_m896_N1) - массив значения мощности в начале замера
	{ 873	,8	,2	, &internal1_m896_N2},	//(internal1_m896_N2) - массив значения мощности в конце замера
	{ 874	,8	,1	, &internal1_m896_Period0},	//(internal1_m896_Period0) Per - Период разгона РУ
	{ 875	,1	,1	, &internal1_m896_MyFirstEnterFlag},	//(internal1_m896_MyFirstEnterFlag)  FirstEnterFlag
	{ 876	,3	,1	, &internal1_m862_Nk},	//(internal1_m862_Nk) Nk - ведущая камера
	{ 877	,1	,1	, &internal1_m849_Out10},	//(internal1_m849_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 878	,1	,1	, &internal1_m838_Out10},	//(internal1_m838_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 879	,8	,2	, &internal1_m841_tst},	//(internal1_m841_tst) - массив времени фиксации стартовой мощности
	{ 880	,8	,2	, &internal1_m841_trz},	//(internal1_m841_trz) - массив времени фиксации очередного периода
	{ 881	,8	,2	, &internal1_m841_N1},	//(internal1_m841_N1) - массив значения мощности в начале замера
	{ 882	,8	,2	, &internal1_m841_N2},	//(internal1_m841_N2) - массив значения мощности в конце замера
	{ 883	,8	,1	, &internal1_m841_Period0},	//(internal1_m841_Period0) Per - Период разгона РУ
	{ 884	,1	,1	, &internal1_m841_MyFirstEnterFlag},	//(internal1_m841_MyFirstEnterFlag)  FirstEnterFlag
	{ 885	,3	,1	, &internal1_m804_Nk},	//(internal1_m804_Nk) Nk - ведущая камера
	{ 886	,3	,1	, &internal1_m195_tx},	//(internal1_m195_tx) tx - внутренний параметр
	{ 887	,3	,1	, &internal1_m25_tx},	//(internal1_m25_tx) tx - внутренний параметр
	{ 888	,1	,1	, &internal1_m476_Pav0},	//(internal1_m476_Pav0)  - Пер.аварийный выключатель механизма
	{ 889	,1	,1	, &internal1_m476_Zav0},	//(internal1_m476_Zav0)  - Зад.аварийный выключатель механизма
	{ 890	,1	,1	, &internal1_m476_Pv0},	//(internal1_m476_Pv0)  - Пер. выключатель механизма
	{ 891	,1	,1	, &internal1_m476_Zv0},	//(internal1_m476_Zv0)  - Зад. выключатель механизма
	{ 892	,1	,1	, &internal1_m476_RA00},	//(internal1_m476_RA00)  - последнее задание вперед
	{ 893	,1	,1	, &internal1_m476_RA10},	//(internal1_m476_RA10)  - последнее задание назад
	{ 894	,1	,1	, &internal1_m476_MyFirstEnterFlag},	//(internal1_m476_MyFirstEnterFlag) MyFirstEnterFlag
	{ 895	,1	,1	, &internal1_m490_Pav0},	//(internal1_m490_Pav0)  - Пер.аварийный выключатель механизма
	{ 896	,1	,1	, &internal1_m490_Zav0},	//(internal1_m490_Zav0)  - Зад.аварийный выключатель механизма
	{ 897	,1	,1	, &internal1_m490_Pv0},	//(internal1_m490_Pv0)  - Пер. выключатель механизма
	{ 898	,1	,1	, &internal1_m490_Zv0},	//(internal1_m490_Zv0)  - Зад. выключатель механизма
	{ 899	,1	,1	, &internal1_m490_RA00},	//(internal1_m490_RA00)  - последнее задание вперед
	{ 900	,1	,1	, &internal1_m490_RA10},	//(internal1_m490_RA10)  - последнее задание назад
	{ 901	,1	,1	, &internal1_m490_MyFirstEnterFlag},	//(internal1_m490_MyFirstEnterFlag) MyFirstEnterFlag
	{ 902	,1	,1	, &internal1_m478_Pav0},	//(internal1_m478_Pav0)  - Пер.аварийный выключатель механизма
	{ 903	,1	,1	, &internal1_m478_Zav0},	//(internal1_m478_Zav0)  - Зад.аварийный выключатель механизма
	{ 904	,1	,1	, &internal1_m478_Pv0},	//(internal1_m478_Pv0)  - Пер. выключатель механизма
	{ 905	,1	,1	, &internal1_m478_Zv0},	//(internal1_m478_Zv0)  - Зад. выключатель механизма
	{ 906	,1	,1	, &internal1_m478_RA00},	//(internal1_m478_RA00)  - последнее задание вперед
	{ 907	,1	,1	, &internal1_m478_RA10},	//(internal1_m478_RA10)  - последнее задание назад
	{ 908	,1	,1	, &internal1_m478_MyFirstEnterFlag},	//(internal1_m478_MyFirstEnterFlag) MyFirstEnterFlag
	{ 909	,1	,1	, &internal1_m621_Pav0},	//(internal1_m621_Pav0)  - Пер.аварийный выключатель механизма
	{ 910	,1	,1	, &internal1_m621_Zav0},	//(internal1_m621_Zav0)  - Зад.аварийный выключатель механизма
	{ 911	,1	,1	, &internal1_m621_Pv0},	//(internal1_m621_Pv0)  - Пер. выключатель механизма
	{ 912	,1	,1	, &internal1_m621_Zv0},	//(internal1_m621_Zv0)  - Зад. выключатель механизма
	{ 913	,1	,1	, &internal1_m621_RA00},	//(internal1_m621_RA00)  - последнее задание вперед
	{ 914	,1	,1	, &internal1_m621_RA10},	//(internal1_m621_RA10)  - последнее задание назад
	{ 915	,1	,1	, &internal1_m621_MyFirstEnterFlag},	//(internal1_m621_MyFirstEnterFlag) MyFirstEnterFlag
	{ 916	,1	,1	, &internal1_m618_Pav0},	//(internal1_m618_Pav0)  - Пер.аварийный выключатель механизма
	{ 917	,1	,1	, &internal1_m618_Zav0},	//(internal1_m618_Zav0)  - Зад.аварийный выключатель механизма
	{ 918	,1	,1	, &internal1_m618_Pv0},	//(internal1_m618_Pv0)  - Пер. выключатель механизма
	{ 919	,1	,1	, &internal1_m618_Zv0},	//(internal1_m618_Zv0)  - Зад. выключатель механизма
	{ 920	,1	,1	, &internal1_m618_RA00},	//(internal1_m618_RA00)  - последнее задание вперед
	{ 921	,1	,1	, &internal1_m618_RA10},	//(internal1_m618_RA10)  - последнее задание назад
	{ 922	,1	,1	, &internal1_m618_MyFirstEnterFlag},	//(internal1_m618_MyFirstEnterFlag) MyFirstEnterFlag
	{ 923	,1	,1	, &internal1_m604_Pav0},	//(internal1_m604_Pav0)  - Пер.аварийный выключатель механизма
	{ 924	,1	,1	, &internal1_m604_Zav0},	//(internal1_m604_Zav0)  - Зад.аварийный выключатель механизма
	{ 925	,1	,1	, &internal1_m604_Pv0},	//(internal1_m604_Pv0)  - Пер. выключатель механизма
	{ 926	,1	,1	, &internal1_m604_Zv0},	//(internal1_m604_Zv0)  - Зад. выключатель механизма
	{ 927	,1	,1	, &internal1_m604_RA00},	//(internal1_m604_RA00)  - последнее задание вперед
	{ 928	,1	,1	, &internal1_m604_RA10},	//(internal1_m604_RA10)  - последнее задание назад
	{ 929	,1	,1	, &internal1_m604_MyFirstEnterFlag},	//(internal1_m604_MyFirstEnterFlag) MyFirstEnterFlag
	{ 930	,1	,1	, &internal1_m603_Pav0},	//(internal1_m603_Pav0)  - Пер.аварийный выключатель механизма
	{ 931	,1	,1	, &internal1_m603_Zav0},	//(internal1_m603_Zav0)  - Зад.аварийный выключатель механизма
	{ 932	,1	,1	, &internal1_m603_Pv0},	//(internal1_m603_Pv0)  - Пер. выключатель механизма
	{ 933	,1	,1	, &internal1_m603_Zv0},	//(internal1_m603_Zv0)  - Зад. выключатель механизма
	{ 934	,1	,1	, &internal1_m603_RA00},	//(internal1_m603_RA00)  - последнее задание вперед
	{ 935	,1	,1	, &internal1_m603_RA10},	//(internal1_m603_RA10)  - последнее задание назад
	{ 936	,1	,1	, &internal1_m603_MyFirstEnterFlag},	//(internal1_m603_MyFirstEnterFlag) MyFirstEnterFlag
	{ 937	,8	,1	, &internal1_m650_y0},	//(internal1_m650_y0) y0 - внутренний параметр
	{ 938	,8	,1	, &internal1_m798_Chim0},	//(internal1_m798_Chim0) измеренная частота импульсов камеры Гц
	{ 939	,8	,1	, &internal1_m790_Chim0},	//(internal1_m790_Chim0) измеренная частота импульсов камеры Гц
	{ 940	,8	,1	, &internal1_m783_Chim0},	//(internal1_m783_Chim0) измеренная частота импульсов камеры Гц
	{ 941	,8	,1	, &internal1_m775_Chim0},	//(internal1_m775_Chim0) измеренная частота импульсов камеры Гц
	{ 942	,8	,1	, &internal1_m767_Chim0},	//(internal1_m767_Chim0) измеренная частота импульсов камеры Гц
	{ 943	,8	,1	, &internal1_m760_Chim0},	//(internal1_m760_Chim0) измеренная частота импульсов камеры Гц
	{ 944	,8	,1	, &internal1_m752_Chim0},	//(internal1_m752_Chim0) измеренная частота импульсов камеры Гц
	{ 945	,8	,1	, &internal1_m744_Chim0},	//(internal1_m744_Chim0) измеренная частота импульсов камеры Гц
	{ 946	,8	,1	, &internal1_m737_Chim0},	//(internal1_m737_Chim0) измеренная частота импульсов камеры Гц
	{ 947	,8	,1	, &internal1_m729_Chim0},	//(internal1_m729_Chim0) измеренная частота импульсов камеры Гц
	{ 948	,8	,1	, &internal1_m721_Chim0},	//(internal1_m721_Chim0) измеренная частота импульсов камеры Гц
	{ 949	,8	,1	, &internal1_m714_Chim0},	//(internal1_m714_Chim0) измеренная частота импульсов камеры Гц
	{ 950	,1	,1	, &internal1_m590_Pav0},	//(internal1_m590_Pav0)  - Пер.аварийный выключатель механизма
	{ 951	,1	,1	, &internal1_m590_Zav0},	//(internal1_m590_Zav0)  - Зад.аварийный выключатель механизма
	{ 952	,1	,1	, &internal1_m590_Pv0},	//(internal1_m590_Pv0)  - Пер. выключатель механизма
	{ 953	,1	,1	, &internal1_m590_Zv0},	//(internal1_m590_Zv0)  - Зад. выключатель механизма
	{ 954	,1	,1	, &internal1_m590_RA00},	//(internal1_m590_RA00)  - последнее задание вперед
	{ 955	,1	,1	, &internal1_m590_RA10},	//(internal1_m590_RA10)  - последнее задание назад
	{ 956	,1	,1	, &internal1_m590_MyFirstEnterFlag},	//(internal1_m590_MyFirstEnterFlag) MyFirstEnterFlag
	{ 957	,1	,1	, &internal1_m575_Pav0},	//(internal1_m575_Pav0)  - Пер.аварийный выключатель механизма
	{ 958	,1	,1	, &internal1_m575_Zav0},	//(internal1_m575_Zav0)  - Зад.аварийный выключатель механизма
	{ 959	,1	,1	, &internal1_m575_Pv0},	//(internal1_m575_Pv0)  - Пер. выключатель механизма
	{ 960	,1	,1	, &internal1_m575_Zv0},	//(internal1_m575_Zv0)  - Зад. выключатель механизма
	{ 961	,1	,1	, &internal1_m575_RA00},	//(internal1_m575_RA00)  - последнее задание вперед
	{ 962	,1	,1	, &internal1_m575_RA10},	//(internal1_m575_RA10)  - последнее задание назад
	{ 963	,1	,1	, &internal1_m575_MyFirstEnterFlag},	//(internal1_m575_MyFirstEnterFlag) MyFirstEnterFlag
	{ 964	,1	,1	, &internal1_m461_Pav0},	//(internal1_m461_Pav0)  - Пер.аварийный выключатель механизма
	{ 965	,1	,1	, &internal1_m461_Zav0},	//(internal1_m461_Zav0)  - Зад.аварийный выключатель механизма
	{ 966	,1	,1	, &internal1_m461_Pv0},	//(internal1_m461_Pv0)  - Пер. выключатель механизма
	{ 967	,1	,1	, &internal1_m461_Zv0},	//(internal1_m461_Zv0)  - Зад. выключатель механизма
	{ 968	,1	,1	, &internal1_m461_RA00},	//(internal1_m461_RA00)  - последнее задание вперед
	{ 969	,1	,1	, &internal1_m461_RA10},	//(internal1_m461_RA10)  - последнее задание назад
	{ 970	,1	,1	, &internal1_m461_MyFirstEnterFlag},	//(internal1_m461_MyFirstEnterFlag) MyFirstEnterFlag
	{ 971	,1	,1	, &internal1_m446_Pav0},	//(internal1_m446_Pav0)  - Пер.аварийный выключатель механизма
	{ 972	,1	,1	, &internal1_m446_Zav0},	//(internal1_m446_Zav0)  - Зад.аварийный выключатель механизма
	{ 973	,1	,1	, &internal1_m446_Pv0},	//(internal1_m446_Pv0)  - Пер. выключатель механизма
	{ 974	,1	,1	, &internal1_m446_Zv0},	//(internal1_m446_Zv0)  - Зад. выключатель механизма
	{ 975	,1	,1	, &internal1_m446_RA00},	//(internal1_m446_RA00)  - последнее задание вперед
	{ 976	,1	,1	, &internal1_m446_RA10},	//(internal1_m446_RA10)  - последнее задание назад
	{ 977	,1	,1	, &internal1_m446_MyFirstEnterFlag},	//(internal1_m446_MyFirstEnterFlag) MyFirstEnterFlag
	{ 978	,1	,1	, &internal1_m502_Pav0},	//(internal1_m502_Pav0)  - Пер.аварийный выключатель механизма
	{ 979	,1	,1	, &internal1_m502_Zav0},	//(internal1_m502_Zav0)  - Зад.аварийный выключатель механизма
	{ 980	,1	,1	, &internal1_m502_Pv0},	//(internal1_m502_Pv0)  - Пер. выключатель механизма
	{ 981	,1	,1	, &internal1_m502_Zv0},	//(internal1_m502_Zv0)  - Зад. выключатель механизма
	{ 982	,1	,1	, &internal1_m502_RA00},	//(internal1_m502_RA00)  - последнее задание вперед
	{ 983	,1	,1	, &internal1_m502_RA10},	//(internal1_m502_RA10)  - последнее задание назад
	{ 984	,1	,1	, &internal1_m502_MyFirstEnterFlag},	//(internal1_m502_MyFirstEnterFlag) MyFirstEnterFlag
	{ 985	,1	,1	, &internal1_m397_Pav0},	//(internal1_m397_Pav0)  - Пер.аварийный выключатель механизма
	{ 986	,1	,1	, &internal1_m397_Zav0},	//(internal1_m397_Zav0)  - Зад.аварийный выключатель механизма
	{ 987	,1	,1	, &internal1_m397_Pv0},	//(internal1_m397_Pv0)  - Пер. выключатель механизма
	{ 988	,1	,1	, &internal1_m397_Zv0},	//(internal1_m397_Zv0)  - Зад. выключатель механизма
	{ 989	,1	,1	, &internal1_m397_RA00},	//(internal1_m397_RA00)  - последнее задание вперед
	{ 990	,1	,1	, &internal1_m397_RA10},	//(internal1_m397_RA10)  - последнее задание назад
	{ 991	,1	,1	, &internal1_m397_MyFirstEnterFlag},	//(internal1_m397_MyFirstEnterFlag) MyFirstEnterFlag
	{ 992	,1	,1	, &internal1_m381_Pav0},	//(internal1_m381_Pav0)  - Пер.аварийный выключатель механизма
	{ 993	,1	,1	, &internal1_m381_Zav0},	//(internal1_m381_Zav0)  - Зад.аварийный выключатель механизма
	{ 994	,1	,1	, &internal1_m381_Pv0},	//(internal1_m381_Pv0)  - Пер. выключатель механизма
	{ 995	,1	,1	, &internal1_m381_Zv0},	//(internal1_m381_Zv0)  - Зад. выключатель механизма
	{ 996	,1	,1	, &internal1_m381_RA00},	//(internal1_m381_RA00)  - последнее задание вперед
	{ 997	,1	,1	, &internal1_m381_RA10},	//(internal1_m381_RA10)  - последнее задание назад
	{ 998	,1	,1	, &internal1_m381_MyFirstEnterFlag},	//(internal1_m381_MyFirstEnterFlag) MyFirstEnterFlag
	{ 999	,1	,1	, &internal1_m364_Pav0},	//(internal1_m364_Pav0)  - Пер.аварийный выключатель механизма
	{ 1000	,1	,1	, &internal1_m364_Zav0},	//(internal1_m364_Zav0)  - Зад.аварийный выключатель механизма
	{ 1001	,1	,1	, &internal1_m364_Pv0},	//(internal1_m364_Pv0)  - Пер. выключатель механизма
	{ 1002	,1	,1	, &internal1_m364_Zv0},	//(internal1_m364_Zv0)  - Зад. выключатель механизма
	{ 1003	,1	,1	, &internal1_m364_RA00},	//(internal1_m364_RA00)  - последнее задание вперед
	{ 1004	,1	,1	, &internal1_m364_RA10},	//(internal1_m364_RA10)  - последнее задание назад
	{ 1005	,1	,1	, &internal1_m364_MyFirstEnterFlag},	//(internal1_m364_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1006	,1	,1	, &internal1_m1167_Pav0},	//(internal1_m1167_Pav0)  - Пер.аварийный выключатель механизма
	{ 1007	,1	,1	, &internal1_m1167_Zav0},	//(internal1_m1167_Zav0)  - Зад.аварийный выключатель механизма
	{ 1008	,1	,1	, &internal1_m1167_Pv0},	//(internal1_m1167_Pv0)  - Пер. выключатель механизма
	{ 1009	,1	,1	, &internal1_m1167_Zv0},	//(internal1_m1167_Zv0)  - Зад. выключатель механизма
	{ 1010	,1	,1	, &internal1_m1167_RA00},	//(internal1_m1167_RA00)  - последнее задание вперед
	{ 1011	,1	,1	, &internal1_m1167_RA10},	//(internal1_m1167_RA10)  - последнее задание назад
	{ 1012	,1	,1	, &internal1_m1167_MyFirstEnterFlag},	//(internal1_m1167_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1013	,8	,1	, &internal1_m180_C1},	//(internal1_m180_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{ 1014	,8	,1	, &internal1_m180_C2},	//(internal1_m180_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{ 1015	,8	,1	, &internal1_m180_C3},	//(internal1_m180_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{ 1016	,8	,1	, &internal1_m180_C4},	//(internal1_m180_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{ 1017	,8	,1	, &internal1_m180_C5},	//(internal1_m180_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{ 1018	,8	,1	, &internal1_m180_C6},	//(internal1_m180_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{ 1019	,8	,1	, &internal1_m180_N20},	//(internal1_m180_N20) N20 - пред. концентрация нейтронов второй АЗ
	{ 1020	,8	,6	, &internal1_m180_C0},	//(internal1_m180_C0) *C0 - пред. концентрация запаздывающих нейтронов
	{ 1021	,1	,1	, &internal1_m180_ImpINI0},	//(internal1_m180_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{ 1022	,1	,1	, &internal1_m180_MyFirstEnterFlag},	//(internal1_m180_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1023	,1	,1	, &internal1_m301_Ppv0},	//(internal1_m301_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1024	,1	,1	, &internal1_m301_Pav0},	//(internal1_m301_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1025	,1	,1	, &internal1_m301_Zav0},	//(internal1_m301_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1026	,1	,1	, &internal1_m301_RA00},	//(internal1_m301_RA00) RA00 - последнее задание вперед
	{ 1027	,1	,1	, &internal1_m301_RA10},	//(internal1_m301_RA10) RA10 - последнее задание назад
	{ 1028	,18	,1	, &internal1_m301_RA50},	//(internal1_m301_RA50) Ra50 - последнее задание скорости
	{ 1029	,1	,1	, &internal1_m301_fls},	//(internal1_m301_fls)  fls - флаг одношагового режима
	{ 1030	,1	,1	, &internal1_m301_flp},	//(internal1_m301_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1031	,1	,1	, &internal1_m301_MyFirstEnterFlag},	//(internal1_m301_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1032	,1	,1	, &internal1_m130_Ppv0},	//(internal1_m130_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1033	,1	,1	, &internal1_m130_Pav0},	//(internal1_m130_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1034	,1	,1	, &internal1_m130_Zav0},	//(internal1_m130_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1035	,1	,1	, &internal1_m130_RA00},	//(internal1_m130_RA00) RA00 - последнее задание вперед
	{ 1036	,1	,1	, &internal1_m130_RA10},	//(internal1_m130_RA10) RA10 - последнее задание назад
	{ 1037	,18	,1	, &internal1_m130_RA50},	//(internal1_m130_RA50) Ra50 - последнее задание скорости
	{ 1038	,1	,1	, &internal1_m130_fls},	//(internal1_m130_fls)  fls - флаг одношагового режима
	{ 1039	,1	,1	, &internal1_m130_flp},	//(internal1_m130_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1040	,1	,1	, &internal1_m130_MyFirstEnterFlag},	//(internal1_m130_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1041	,1	,1	, &internal1_m265_Ppv0},	//(internal1_m265_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1042	,1	,1	, &internal1_m265_Pav0},	//(internal1_m265_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1043	,1	,1	, &internal1_m265_Zav0},	//(internal1_m265_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1044	,1	,1	, &internal1_m265_RA00},	//(internal1_m265_RA00) RA00 - последнее задание вперед
	{ 1045	,1	,1	, &internal1_m265_RA10},	//(internal1_m265_RA10) RA10 - последнее задание назад
	{ 1046	,18	,1	, &internal1_m265_RA50},	//(internal1_m265_RA50) Ra50 - последнее задание скорости
	{ 1047	,1	,1	, &internal1_m265_fls},	//(internal1_m265_fls)  fls - флаг одношагового режима
	{ 1048	,1	,1	, &internal1_m265_flp},	//(internal1_m265_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1049	,1	,1	, &internal1_m265_MyFirstEnterFlag},	//(internal1_m265_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1050	,1	,1	, &internal1_m97_Ppv0},	//(internal1_m97_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1051	,1	,1	, &internal1_m97_Pav0},	//(internal1_m97_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1052	,1	,1	, &internal1_m97_Zav0},	//(internal1_m97_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1053	,1	,1	, &internal1_m97_RA00},	//(internal1_m97_RA00) RA00 - последнее задание вперед
	{ 1054	,1	,1	, &internal1_m97_RA10},	//(internal1_m97_RA10) RA10 - последнее задание назад
	{ 1055	,18	,1	, &internal1_m97_RA50},	//(internal1_m97_RA50) Ra50 - последнее задание скорости
	{ 1056	,1	,1	, &internal1_m97_fls},	//(internal1_m97_fls)  fls - флаг одношагового режима
	{ 1057	,1	,1	, &internal1_m97_flp},	//(internal1_m97_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1058	,1	,1	, &internal1_m97_MyFirstEnterFlag},	//(internal1_m97_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1059	,1	,1	, &internal1_m227_Ppv0},	//(internal1_m227_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1060	,1	,1	, &internal1_m227_Pav0},	//(internal1_m227_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1061	,1	,1	, &internal1_m227_Zav0},	//(internal1_m227_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1062	,1	,1	, &internal1_m227_RA00},	//(internal1_m227_RA00) RA00 - последнее задание вперед
	{ 1063	,1	,1	, &internal1_m227_RA10},	//(internal1_m227_RA10) RA10 - последнее задание назад
	{ 1064	,18	,1	, &internal1_m227_RA50},	//(internal1_m227_RA50) Ra50 - последнее задание скорости
	{ 1065	,1	,1	, &internal1_m227_fls},	//(internal1_m227_fls)  fls - флаг одношагового режима
	{ 1066	,1	,1	, &internal1_m227_flp},	//(internal1_m227_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1067	,1	,1	, &internal1_m227_MyFirstEnterFlag},	//(internal1_m227_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1068	,1	,1	, &internal1_m59_Ppv0},	//(internal1_m59_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1069	,1	,1	, &internal1_m59_Pav0},	//(internal1_m59_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1070	,1	,1	, &internal1_m59_Zav0},	//(internal1_m59_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1071	,1	,1	, &internal1_m59_RA00},	//(internal1_m59_RA00) RA00 - последнее задание вперед
	{ 1072	,1	,1	, &internal1_m59_RA10},	//(internal1_m59_RA10) RA10 - последнее задание назад
	{ 1073	,18	,1	, &internal1_m59_RA50},	//(internal1_m59_RA50) Ra50 - последнее задание скорости
	{ 1074	,1	,1	, &internal1_m59_fls},	//(internal1_m59_fls)  fls - флаг одношагового режима
	{ 1075	,1	,1	, &internal1_m59_flp},	//(internal1_m59_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1076	,1	,1	, &internal1_m59_MyFirstEnterFlag},	//(internal1_m59_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1077	,8	,1	, &internal1_m14_C1},	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{ 1078	,8	,1	, &internal1_m14_C2},	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{ 1079	,8	,1	, &internal1_m14_C3},	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{ 1080	,8	,1	, &internal1_m14_C4},	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{ 1081	,8	,1	, &internal1_m14_C5},	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{ 1082	,8	,1	, &internal1_m14_C6},	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{ 1083	,8	,1	, &internal1_m14_N20},	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
	{ 1084	,8	,6	, &internal1_m14_C0},	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
	{ 1085	,1	,1	, &internal1_m14_ImpINI0},	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{ 1086	,1	,1	, &internal1_m14_MyFirstEnterFlag},	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="scm.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{320,"fEM_R0UL01RIM\0"}, 
{321,"fEM_R0UN02RIM\0"}, 
{322,"fEM_A1UR01RIM\0"}, 
{323,"fEM_A1UR00RIM\0"}, 
{324,"fEM_A3UR00RIM\0"}, 
{325,"fEM_A3UR01RIM\0"}, 
{326,"fEM_R0UT01RIM\0"}, 
{327,"fEM_R0UT02RIM\0"}, 
{328,"fEM_R0UT04RIM\0"}, 
{329,"fEM_R0UT03RIM\0"}, 
{330,"fEM_R0UT05RIM\0"}, 
{331,"fEM_R0UT06RIM\0"}, 
{332,"fEM_A1UC02RDU\0"}, 
{333,"fEM_A1UC04RIM\0"}, 
{334,"fEM_A1UC05RIM\0"}, 
{335,"fEM_A1UC06RIM\0"}, 
{336,"fEM_A2UC06RIM\0"}, 
{337,"fEM_A2UC05RIM\0"}, 
{338,"fEM_A2UC04RIM\0"}, 
{339,"fEM_A2UC02RDU\0"}, 
{340,"fEM_A3UC06RIM\0"}, 
{341,"fEM_A3UC05RIM\0"}, 
{342,"fEM_A3UC04RIM\0"}, 
{343,"fEM_A3UC02RDU\0"}, 
{344,"fEM_R4UV80RDU\0"}, 
{345,"fEM_R4UC10RIM\0"}, 
{346,"fEM_R4UC20RIM\0"}, 
{347,"fEM_B8UC21RIM\0"}, 
{348,"fEM_B8UC20RIM\0"}, 
{349,"fEM_B8UC11RIM\0"}, 
{350,"fEM_B8UC10RIM\0"}, 
{351,"fEM_B8UV80RDU\0"}, 
{352,"fEM_A8UV80RDU\0"}, 
{353,"fEM_A8UC10RIM\0"}, 
{354,"fEM_A8UC11RIM\0"}, 
{355,"fEM_A8UC20RIM\0"}, 
{356,"fEM_A8UC21RIM\0"}, 
{357,"fEM_A6UC10RIM\0"}, 
{358,"fEM_R1UC10RIM\0"}, 
{359,"fEM_A5UC10RIM\0"}, 
{360,"fEM_A0UN01RIM\0"}, 
{361,"fEM_R4UC22RIM\0"}, 
{362,"fEM_A1UG01RDU\0"}, 
{363,"fEM_A2UG01RDU\0"}, 
{364,"fEM_A3UG01RDU\0"}, 
{365,"fEM_R7UC10RIM\0"}, 
{366,"fEM_R7UC19RIM\0"}, 
{367,"fEM_R7UI02RIM\0"}, 
{368,"fEM_R7UL01RIM\0"}, 
{369,"fEM_A2UR00RIM\0"}, 
{370,"fEM_A2UR01RIM\0"}, 
{371,"fEM_A0UN02RIM\0"}, 
{372,"fEM_R0UR30RIM\0"}, 
{373,"fEM_R0UR01RIM\0"}, 
{374,"fEM_R0UT02RDU\0"}, 
{375,"fEM_R0UT01RDU\0"}, 
{376,"fEM_A1UC03RDU\0"}, 
{377,"fEM_A2UP03RDU\0"}, 
{378,"fEM_A2UP04RDU\0"}, 
{379,"fEM_A2UC03RDU\0"}, 
{380,"fEM_A3UP03RDU\0"}, 
{381,"fEM_A3UP04RDU\0"}, 
{382,"fEM_A3UC03RDU\0"}, 
{383,"fEM_R7UI74RIM\0"}, 
{384,"fEM_A8UC03RDU\0"}, 
{385,"fEM_R0UV87RDU\0"}, 
{386,"fEM_R0UV81RDU\0"}, 
{387,"fEM_R0UV82RDU\0"}, 
{388,"fEM_R0UV83RDU\0"}, 
{389,"fEM_R0UV84RDU\0"}, 
{390,"fEM_R0UV85RDU\0"}, 
{391,"fEM_R0UV86RDU\0"}, 
{392,"fEM_A8UC08RDU\0"}, 
{393,"fEM_B8UC08RDU\0"}, 
{394,"fEM_R4UC08RDU\0"}, 
{395,"fEM_A0UX00RSS\0"}, 
{396,"fEM_R7UX01RSS\0"}, 
{397,"fEM_R7UX02RSS\0"}, 
{398,"fEM_R7UX04RSS\0"}, 
{399,"fEM_R7UX05RSS\0"}, 
{400,"fEM_R7UX06RSS\0"}, 
{401,"fEM_R7UX07RSS\0"}, 
{402,"fEM_R7UX08RSS\0"}, 
{403,"fEM_R7UX09RSS\0"}, 
{404,"fEM_R7UY01RSS\0"}, 
{405,"fEM_R7UY02RSS\0"}, 
{406,"fEM_R7UY04RSS\0"}, 
{407,"fEM_R7UY05RSS\0"}, 
{408,"fEM_R7UY06RSS\0"}, 
{409,"fEM_R7UY07RSS\0"}, 
{410,"fEM_R7UY08RSS\0"}, 
{411,"fEM_R7UY09RSS\0"}, 
{412,"fEM_R7UX10RSS\0"}, 
{413,"fEM_R7UX11RSS\0"}, 
{414,"fEM_R7UX12RSS\0"}, 
{415,"fEM_R7UY10RSS\0"}, 
{416,"fEM_R7UY11RSS\0"}, 
{417,"fEM_R7UY12RSS\0"}, 
{418,"fEM_A0UX01RSS\0"}, 
{419,"fEM_A0UX02RSS\0"}, 
{420,"fEM_A0UX03RSS\0"}, 
{421,"fEM_A0UX04RSS\0"}, 
{422,"fEM_A0UX05RSS\0"}, 
{423,"fEM_A0UX06RSS\0"}, 
{424,"fEM_A0UX07RSS\0"}, 
{425,"fEM_A0UX08RSS\0"}, 
{426,"fEM_A0UX09RSS\0"}, 
{427,"fEM_A0UX10RSS\0"}, 
{428,"fEM_A0UX11RSS\0"}, 
{429,"fEM_A0UX12RSS\0"}, 
{430,"fEM_B0UX01RSS\0"}, 
{431,"fEM_B0UX02RSS\0"}, 
{432,"fEM_B0UX03RSS\0"}, 
{433,"fEM_B0UX04RSS\0"}, 
{434,"fEM_B0UX05RSS\0"}, 
{435,"fEM_B0UX06RSS\0"}, 
{436,"fEM_B0UX07RSS\0"}, 
{437,"fEM_B0UX08RSS\0"}, 
{438,"fEM_B0UX09RSS\0"}, 
{439,"fEM_B0UX10RSS\0"}, 
{440,"fEM_B0UX11RSS\0"}, 
{441,"fEM_B0UX12RSS\0"}, 
{442,"fEM_R0UH02RSS\0"}, 
{443,"fEM_R0UH03RSS\0"}, 
{444,"fEM_R4US80RDU\0"}, 
{445,"fEM_R7UI71RIM\0"}, 
{446,"fEM_R7UI72RIM\0"}, 
{447,"fEM_R7UI73RIM\0"}, 
{448,"fEM_A1UP01RIM\0"}, 
{449,"fEM_A2UP01RIM\0"}, 
{450,"fEM_A0UP02RIM\0"}, 
{451,"fEM_A3UP01RIM\0"}, 
{452,"fEM_A1UP82RIM\0"}, 
{453,"fEM_A3UP02RDU\0"}, 
{454,"fEM_A1UV02RIM\0"}, 
{455,"fEM_A3UV02RIM\0"}, 
{456,"fEM_A2UV02RIM\0"}, 
{457,"fEM_B8US80RDU\0"}, 
{458,"fEM_A8US80RDU\0"}, 
{459,"fEM_A6US80RDU\0"}, 
{460,"fEM_A1US07RDU\0"}, 
{461,"fEM_A2US07RDU\0"}, 
{462,"fEM_A3US07RDU\0"}, 
{463,"fEM_R7UI75RIM\0"}, 
{464,"fEM_R0UH21RSS\0"}, 
{465,"fEM_R0UH22RSS\0"}, 
{466,"fEM_R0UH23RSS\0"}, 
{467,"fEM_R0UR01RSS\0"}, 
{468,"fEM_R0UL52RSS\0"}, 
{469,"fEM_R0UL41RSS\0"}, 
{470,"fEM_R0UL51RSS\0"}, 
{471,"fEM_R0UL42RSS\0"}, 
{472,"fEM_R0UH05RSS\0"}, 
{473,"fEM_R0UN03RSS\0"}, 
{474,"fEM_A4UL10RIM\0"}, 
{475,"fEM_A9UL10RIM\0"}, 
{476,"fEM_R3UL10RIM\0"}, 
{477,"fEM_R5UL10RIM\0"}, 
{478,"fEM_R6UL10RIM\0"}, 
{479,"lEM_C1AD31LRP\0"}, 
{480,"lEM_R0IE01LRP\0"}, 
{481,"lEM_R0IE02LRP\0"}, 
{482,"fEM_A2UP02RIM\0"}, 
{483,"fEM_A2UP03RIM\0"}, 
{484,"fEM_A0UP01RIM\0"}, 
{485,"fEM_A3UP02RIM\0"}, 
{486,"fEM_A4UP01RIM\0"}, 
{487,"fEM_A4UP02RIM\0"}, 
{488,"fEM_R7UI76RIM\0"}, 
{489,"fEM_R7UI77RIM\0"}, 
{490,"iEM_TERBB1\0"}, 
{491,"fEM_A1MC02RC1\0"}, 
{492,"fEM_A1MV02RC1\0"}, 
{493,"iEM_TERBB2\0"}, 
{494,"fEM_B1MC02RC1\0"}, 
{495,"fEM_B1MV02RC1\0"}, 
{496,"iEM_TERRB2\0"}, 
{497,"fEM_B2MC02RC1\0"}, 
{498,"fEM_B2MV02RC1\0"}, 
{499,"iEM_TERRB1\0"}, 
{500,"fEM_A2MC02RC1\0"}, 
{501,"fEM_A2MV02RC1\0"}, 
{502,"iEM_TERIS2\0"}, 
{503,"fEM_B3MC02RC1\0"}, 
{504,"fEM_B3MV02RC1\0"}, 
{505,"iEM_TERIS1\0"}, 
{506,"fEM_A3MC02RC1\0"}, 
{507,"fEM_A3MV02RC1\0"}, 
{508,"iEM_TERA1IE04LDU\0"}, 
{509,"iEM_TERA1IE03LDU\0"}, 
{510,"fEM_A1MC01RC1\0"}, 
{511,"iEM_TERB1IE03LDU\0"}, 
{512,"iEM_TERB1IE04LDU\0"}, 
{513,"fEM_B1MC01RC1\0"}, 
{514,"fEM_B1MV01RC1\0"}, 
{515,"fEM_B2MC01RC1\0"}, 
{516,"fEM_B2MV01RC1\0"}, 
{517,"fEM_A3MC01RC1\0"}, 
{518,"fEM_A3MV01RC1\0"}, 
{519,"fEM_B3MC01RC1\0"}, 
{520,"fEM_B3MV01RC1\0"}, 
{521,"iEM_TERA2SS21LIM\0"}, 
{522,"iEM_TERA2SS12LIM\0"}, 
{523,"iEM_TERR6SS21LIM\0"}, 
{524,"iEM_TERA2VP82LIM\0"}, 
{525,"iEM_TERA2SS11LIM\0"}, 
{526,"iEM_TERB3SS21LIM\0"}, 
{527,"iEM_TERA0MT01RIM\0"}, 
{528,"iEM_TERB0MT01RIM\0"}, 
{529,"iEM_TERA2SP01RIM\0"}, 
{530,"iEM_TERB2SP01RIM\0"}, 
{531,"iEM_TERB3SP02RIM\0"}, 
{532,"iEM_TERA3SC01RIM\0"}, 
{533,"iEM_TERA3VP81LIM\0"}, 
{534,"iEM_TERA2SC01RIM\0"}, 
{535,"iEM_TERA2SS33LIM\0"}, 
{536,"iEM_TERA3SS21LIM\0"}, 
{537,"iEM_TERA3SS33LIM\0"}, 
{538,"iEM_TERA3SS31LIM\0"}, 
{539,"iEM_TERB3SS31LIM\0"}, 
{540,"iEM_TERB3SS33LIM\0"}, 
{541,"iEM_TERB3SC01RIM\0"}, 
{542,"iEM_TERA3SS11LIM\0"}, 
{543,"iEM_TERB3SS11LIM\0"}, 
{544,"iEM_TERR6IS64LIM\0"}, 
{545,"iEM_TERB3SS22LIM\0"}, 
{546,"iEM_TERA3SS22LIM\0"}, 
{547,"iEM_TERA3SP02RIM\0"}, 
{548,"iEM_TERR6IS62LIM\0"}, 
{549,"iEM_TERR6IS66LIM\0"}, 
{550,"iEM_TERR6IS67LIM\0"}, 
{551,"iEM_TERA0VP81LIM\0"}, 
{552,"iEM_TERB0VP81LIM\0"}, 
{553,"iEM_TERR0VP81LIM\0"}, 
{554,"iEM_TERR6IS68LIM\0"}, 
{555,"iEM_TERR7SI74RIM\0"}, 
{556,"iEM_TERA5SS21LIM\0"}, 
{557,"iEM_TERB5SS11LIM\0"}, 
{558,"iEM_TERA5SS11LIM\0"}, 
{559,"iEM_TERA9SS11LIM\0"}, 
{560,"iEM_TERB2SS11LIM\0"}, 
{561,"iEM_TERB2SS12LIM\0"}, 
{562,"iEM_TERB2SS21LIM\0"}, 
{563,"iEM_TERR3SS11LIM\0"}, 
{564,"iEM_TERB2SC01RIM\0"}, 
{565,"iEM_TERR3SS21LIM\0"}, 
{566,"iEM_TERR5SS11LIM\0"}, 
{567,"iEM_TERA4SS11LIM\0"}, 
{568,"iEM_TERR1SS11LIM\0"}, 
{569,"iEM_TERR1SS21LIM\0"}, 
{570,"iEM_TERR2SS11LIM\0"}, 
{571,"iEM_TERR2SS21LIM\0"}, 
{572,"iEM_TERA4VP82LIM\0"}, 
{573,"iEM_TERB4SS21LIM\0"}, 
{574,"iEM_TERR5SS21LIM\0"}, 
{575,"iEM_TERB6SS21LIM\0"}, 
{576,"iEM_TERB4SS11LIM\0"}, 
{577,"iEM_TERA4SS21LIM\0"}, 
{578,"iEM_TERA6MS11LIM\0"}, 
{579,"iEM_TERA6SS21LIM\0"}, 
{580,"iEM_TERB6SS11LIM\0"}, 
{581,"iEM_TERR4SS11LIM\0"}, 
{582,"iEM_TERR4MS21LIM\0"}, 
{583,"iEM_TERR4SS12LIM\0"}, 
{584,"iEM_TERR4SS22LIM\0"}, 
{585,"iEM_TERR8SS11LIM\0"}, 
{586,"iEM_TERB8SC01RIM\0"}, 
{587,"iEM_TERA8SC01RIM\0"}, 
{588,"iEM_TERB8SS12LIM\0"}, 
{589,"iEM_TERA8SS12LIM\0"}, 
{590,"iEM_TERB8SS22LIM\0"}, 
{591,"iEM_TERA8SS22LIM\0"}, 
{592,"iEM_TERA9SS21LIM\0"}, 
{593,"iEM_TERB9SS21LIM\0"}, 
{594,"iEM_TERB9SS11LIM\0"}, 
{595,"iEM_TERB5SS21LIM\0"}, 
{596,"iEM_TERA1SS21LIM\0"}, 
{597,"iEM_TERA1SS11LIM\0"}, 
{598,"iEM_TERA1SC01RIM\0"}, 
{599,"iEM_TERA1SS12LIM\0"}, 
{600,"iEM_TERB1SS21LIM\0"}, 
{601,"iEM_TERB1SS11LIM\0"}, 
{602,"iEM_TERB1MC01RIM\0"}, 
{603,"iEM_TERB1SS12LIM\0"}, 
{604,"iEM_TERR0IE43LIM\0"}, 
{605,"iEM_TERR0IE41LIM\0"}, 
{606,"lEM_A0EE06LC1\0"}, 
{607,"iEM_TERR0IE33LIM\0"}, 
{608,"iEM_TERR0IE31LIM\0"}, 
{609,"lEM_A0EE05LC1\0"}, 
{610,"iEM_TERR0IE11LIM\0"}, 
{611,"iEM_TERR0IE13LIM\0"}, 
{612,"lEM_A0EE03LC1\0"}, 
{613,"iEM_TERR0IE23LIM\0"}, 
{614,"iEM_TERR0IE21LIM\0"}, 
{615,"lEM_A0EE04LC1\0"}, 
{616,"iEM_TERTLG\0"}, 
{617,"fEM_R4MC01RC1\0"}, 
{618,"fEM_R4MV01RC1\0"}, 
{619,"iEM_TERMAZ2\0"}, 
{620,"fEM_B8MC01RC1\0"}, 
{621,"fEM_B8MV01RC1\0"}, 
{622,"iEM_TERDS2\0"}, 
{623,"fEM_A8MC01RC1\0"}, 
{624,"fEM_A8MV01RC1\0"}, 
{625,"iEM_TERBZ1\0"}, 
{626,"fEM_A6MC01RC1\0"}, 
{627,"fEM_A6MV01RC1\0"}, 
{628,"iEM_TERBZ2\0"}, 
{629,"fEM_B6MC01RC1\0"}, 
{630,"fEM_B6MV01RC1\0"}, 
{631,"lEM_R3AD10LC1\0"}, 
{632,"lEM_R3AD20LC1\0"}, 
{633,"lEM_R6AD10LC1\0"}, 
{634,"lEM_R5AD10LC1\0"}, 
{635,"lEM_R5AD20LC1\0"}, 
{636,"iEM_TERMDZ2\0"}, 
{637,"fEM_R2MC01RC1\0"}, 
{638,"fEM_R2MV01RC1\0"}, 
{639,"iEM_TERMDZ1\0"}, 
{640,"fEM_R1MC01RC1\0"}, 
{641,"fEM_R1MV01RC1\0"}, 
{642,"iEM_TERNL1\0"}, 
{643,"fEM_A5MC01RC1\0"}, 
{644,"fEM_A5MV01RC1\0"}, 
{645,"iEM_TERNL2\0"}, 
{646,"fEM_B5MC01RC1\0"}, 
{647,"fEM_B5MV01RC1\0"}, 
{648,"lEM_R8AD10LC1\0"}, 
{649,"fEM_A1UC08RIM\0"}, 
{650,"fEM_A2UC08RIM\0"}, 
{651,"fEM_A3UC08RIM\0"}, 
{652,"fEM_R0UL01RSS\0"}, 
{653,"fEM_R0UL03RSS\0"}, 
{654,"iEM_TERB2SS33LIM\0"}, 
{655,"iEM_TERA1VP81LIM\0"}, 
{656,"iEM_TERB1VP81LIM\0"}, 
{657,"fEM_A0UT03RSP\0"}, 
{658,"fEM_A0UR01RSP\0"}, 
{659,"fEM_A0UR02RSP\0"}, 
{660,"fEM_B0UT03RSP\0"}, 
{661,"fEM_A1MC01RSP\0"}, 
{662,"fEM_A1MC02RSP\0"}, 
{663,"fEM_A1MV01RSP\0"}, 
{664,"fEM_A1MV02RSP\0"}, 
{665,"fEM_B1MC01RSP\0"}, 
{666,"fEM_B1MV01RSP\0"}, 
{667,"fEM_B1MC02RSP\0"}, 
{668,"fEM_B1MV02RSP\0"}, 
{669,"fEM_A2MC01RC1\0"}, 
{670,"fEM_A2MV01RC1\0"}, 
{671,"fEM_A2MC01RSP\0"}, 
{672,"fEM_A2MV01RSP\0"}, 
{673,"fEM_A2MC02RSP\0"}, 
{674,"fEM_A2MV02RSP\0"}, 
{675,"fEM_B2MC01RSP\0"}, 
{676,"fEM_B2MV01RSP\0"}, 
{677,"fEM_B2MC02RSP\0"}, 
{678,"fEM_B2MV02RSP\0"}, 
{679,"fEM_A3MC01RSP\0"}, 
{680,"fEM_A3MV01RSP\0"}, 
{681,"fEM_A3MC02RSP\0"}, 
{682,"fEM_A3MV02RSP\0"}, 
{683,"fEM_B3MC01RSP\0"}, 
{684,"fEM_B3MV01RSP\0"}, 
{685,"fEM_B3MC02RSP\0"}, 
{686,"fEM_B3MV02RSP\0"}, 
{687,"fEM_B8MC01RSP\0"}, 
{688,"fEM_B8MV01RSP\0"}, 
{689,"fEM_A8MC01RSP\0"}, 
{690,"fEM_A8MV01RSP\0"}, 
{691,"fEM_A6MC01RSP\0"}, 
{692,"fEM_A6MV01RSP\0"}, 
{693,"fEM_B6MC01RSP\0"}, 
{694,"fEM_B6MV01RSP\0"}, 
{695,"fEM_R3UC01RSP\0"}, 
{696,"fEM_R3UV01RSP\0"}, 
{697,"fEM_R5UC01RSP\0"}, 
{698,"fEM_R5UV01RSP\0"}, 
{699,"fEM_R6UC01RSP\0"}, 
{700,"fEM_R6UV01RSP\0"}, 
{701,"fEM_R2MC01RSP\0"}, 
{702,"fEM_R2MV01RSP\0"}, 
{703,"fEM_R1MC01RSP\0"}, 
{704,"fEM_R1MV01RSP\0"}, 
{705,"fEM_A5MC01RSP\0"}, 
{706,"fEM_A5MV01RSP\0"}, 
{707,"fEM_B5MC01RSP\0"}, 
{708,"fEM_B5MV01RSP\0"}, 
{709,"fEM_A9MC01RSP\0"}, 
{710,"fEM_A9MV01RSP\0"}, 
{711,"fEM_B9MC01RSP\0"}, 
{712,"fEM_B9MV01RSP\0"}, 
{713,"fEM_A4MC01RSP\0"}, 
{714,"fEM_A4MV01RSP\0"}, 
{715,"fEM_B4MC01RSP\0"}, 
{716,"fEM_B4MV01RSP\0"}, 
{717,"fEM_R4MC01RSP\0"}, 
{718,"fEM_R4MV01RSP\0"}, 
{719,"fEM_A1MV01RC1\0"}, 
{720,"iEM_TERB7MS31LIM\0"}, 
{721,"iEM_TERA7MS31LIM\0"}, 
{722,"fEM_R7UX03RSS\0"}, 
{723,"fEM_R7UY03RSS\0"}, 
{724,"fEM_R7UY00RSS\0"}, 
{725,"iEM_TERA6VS12LIM\0"}, 
{726,"iEM_TERA6VS22LIM\0"}, 
{727,"iEM_TERB6VS12LIM\0"}, 
{728,"iEM_TERB6VS22LIM\0"}, 
{729,"iEM_TERA5VS22LIM\0"}, 
{730,"iEM_TERA5VS12LIM\0"}, 
{731,"iEM_TERB5VS12LIM\0"}, 
{732,"iEM_TERB5VS22LIM\0"}, 
{733,"iEM_TERR1VS12LIM\0"}, 
{734,"iEM_TERR1VS22LIM\0"}, 
{735,"iEM_TERR2VS12LIM\0"}, 
{736,"iEM_TERR2VS22LIM\0"}, 
{737,"iEM_TERR4VS12LDU\0"}, 
{738,"iEM_TERR4VS22LDU\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_SCM[]={  // 
	{&R0AD14LDU,1,0},	//(R0AD14LDU) Имитация срабатывания верхней АС II УР
	{&R0VZ71LZ1,1,1},	//(R0VZ71LZ1) Обобщенный сигнал по АЗ  1 канала
	{&R0VZ71LZ2,1,2},	//(R0VZ71LZ2) Обобщенный сигнал по АЗ  2 канала
	{&C2MD31LP1,1,3},	//(C2MD31LP1) Кнопка «СБРОС РБ»
	{&C1MD31LP2,1,4},	//(C1MD31LP2) Кнопка «СБРОС ББ»  на ОПУ2
	{&C1MD31LP1,1,5},	//(C1MD31LP1) Кнопка «СБРОС ББ»  на ОПУ1
	{&R0MW13LP2,1,6},	//(R0MW13LP2) Переключатель «СЕТЬ»
	{&lEM_C1AD31LRP,1,7},	//(C1AD31LRP) Общий сброс от РПУ
	{&lEM_R0IE01LRP,1,8},	//(R0IE01LRP) Отключение питание детекторов
	{&lEM_R0IE02LRP,1,9},	//(R0IE02LRP) Отключить питание ПР, ПУ
	{&lEM_A0EE06LC1,1,10},	//(A0EE06LC1) Исправность АКНП4 от диагностики контроллера (От ИС)
	{&lEM_A0EE05LC1,1,11},	//(A0EE05LC1) Исправность АКНП3 от диагностики контроллера (От ИС)
	{&lEM_A0EE03LC1,1,12},	//(A0EE03LC1) Исправность АКНП1 от диагностики контроллера (От ИС)
	{&lEM_A0EE04LC1,1,13},	//(A0EE04LC1) Исправность АКНП2 от диагностики контроллера (От ИС)
	{&lEM_R3AD10LC1,1,14},	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
	{&lEM_R3AD20LC1,1,15},	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
	{&lEM_R6AD10LC1,1,16},	//(R6AD10LC1) Выкатить кран-балку от ИС
	{&lEM_R5AD10LC1,1,17},	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
	{&lEM_R5AD20LC1,1,18},	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
	{&lEM_R8AD10LC1,1,19},	//(R8AD10LC1) Установить аварийный НИ от ИС
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SCM[]={  // 
	{&R0IE11LS1,1,0},	//(R0IE11LS1) Исправность ВИП 1,6 (№8) СНМ11 1канала
	{&R0IE12LS1,1,1},	//(R0IE12LS1) Исправность ВИП 0,5 (№9) КНК15-1 1канала
	{&R0IE13LS1,1,2},	//(R0IE13LS1) Исправность ВИП 0,5 (№10) КНК53М 1канала
	{&R0IE12LS2,1,3},	//(R0IE12LS2) Исправность ВИП 0,5 (№12) КНК15-1 2канала
	{&R0IE13LS2,1,4},	//(R0IE13LS2) Исправность ВИП 0,5 (№13) КНК53М 2канала
	{&R0IE11LS2,1,5},	//(R0IE11LS2) Исправность ВИП 1,6 (№11) СНМ11 2канала
	{&R0IE12LS3,1,6},	//(R0IE12LS3) Исправность ВИП 0,5 (№15) КНК15-1 3канала
	{&R0IE13LS3,1,7},	//(R0IE13LS3) Исправность ВИП 0,5 (№16) КНК53М 3канала
	{&R0IE11LS3,1,8},	//(R0IE11LS3) Исправность ВИП 1,6 (№14) СНМ11 3канала
	{&R0IE12LS4,1,9},	//(R0IE12LS4) Исправность ВИП 0,5 (№18) КНК15-1 4канала
	{&R0IE13LS4,1,10},	//(R0IE13LS4) Исправность ВИП 0,5 (№19) КНК53М 4канала
	{&R0IE11LS4,1,11},	//(R0IE11LS4) Исправность ВИП 1,6 (№17) СНМ11 4канала
	{&A2VP82LDU,1,12},	//(A2VP82LDU) Давление ПОДЪЁМ РБ1 в норме
	{&A3VP81LDU,1,13},	//(A3VP81LDU) Давление СПУСК ИС1 в норме
	{&B3VP81LDU,1,14},	//(B3VP81LDU) Давление СПУСК ИС2 в норме
	{&B2VP82LDU,1,15},	//(B2VP82LDU) Давление ПОДЪЁМ РБ2 в норме
	{&B4IS21LDU,1,16},	//(B4IS21LDU) Приход на НУ НИ2
	{&A4VP82LDU,1,17},	//(A4VP82LDU) Давление ПОДЪЁМ НИ1 в норме
	{&B4VP82LDU,1,18},	//(B4VP82LDU) Давление ПОДЪЁМ НИ2 в норме
	{&A1IE03LDU,1,19},	//(A1IE03LDU) Движение ББ1 вперед (от БУШД)
	{&A1IE04LDU,1,20},	//(A1IE04LDU) Движение ББ1 назад (от БУШД)
	{&B1IE03LDU,1,21},	//(B1IE03LDU) Движение ББ2 вперед (от БУШД)
	{&B1IE04LDU,1,22},	//(B1IE04LDU) Движение ББ2 назад (от БУШД)
	{&A1IS11LIM,1,23},	//(A1IS11LIM) Магнит ББ1 обесточен
	{&A1IS32LIM,1,24},	//(A1IS32LIM) Клапан cброса ББ1 открыт(обесточен)
	{&B1IS11LIM,1,25},	//(B1IS11LIM) Магнит ББ2 обесточен
	{&B1IS32LIM,1,26},	//(B1IS32LIM) Клапан cброса ББ2 открыт(обесточен)
	{&A2IS11LIM,1,27},	//(A2IS11LIM) Магнит РБ1 обесточен
	{&A2IS32LIM,1,28},	//(A2IS32LIM) Клапан cброса РБ1 открыт(обесточен)
	{&B2IS11LIM,1,29},	//(B2IS11LIM) Магнит РБ2 обесточен
	{&B2IS32LIM,1,30},	//(B2IS32LIM) Клапан cброса РБ2 открыт(обесточен)
	{&B8IS11LDU,1,31},	//(B8IS11LDU) Приход на ВУ1 АЗ2
	{&B8IS21LDU,1,32},	//(B8IS21LDU) Приход на НУ1 АЗ2
	{&A6VS22LDU,1,33},	//(A6VS22LDU) Движение створок БЗ1  к ЗАКРЫТА
	{&A6VS12LDU,1,34},	//(A6VS12LDU) Движение створок БЗ1  к  ОТКРЫТА
	{&B6VS22LDU,1,35},	//(B6VS22LDU) Движение створок БЗ2  к ЗАКРЫТА
	{&B6VS12LDU,1,36},	//(B6VS12LDU) Движение створок БЗ2  к ОТКРЫТА
	{&A5VS22LDU,1,37},	//(A5VS22LDU) Движение НЛ1 в сторону НУ
	{&A5VS12LDU,1,38},	//(A5VS12LDU) Движение НЛ1 в сторону ВУ
	{&B5VS22LDU,1,39},	//(B5VS22LDU) Движение НЛ2 в сторону НУ
	{&B5VS12LDU,1,40},	//(B5VS12LDU) Движение НЛ2 в сторону ВУ
	{&R1VS22LDU,1,41},	//(R1VS22LDU) Движение МДЗ1 в сторону НУ
	{&R2VS22LDU,1,42},	//(R2VS22LDU) Движение МДЗ2 в сторону НУ
	{&R2VS12LDU,1,43},	//(R2VS12LDU) Движение МДЗ2 в сторону ВУ
	{&R1VS12LDU,1,44},	//(R1VS12LDU) Движение МДЗ1 в сторону ВУ
	{&R4VS22LDU,1,45},	//(R4VS22LDU) Движение реактора к «У ЗАЩИТЫ»
	{&R4VS12LDU,1,46},	//(R4VS12LDU) Движение реактора  к «У ОБРАЗЦОВ»
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SCM[]={  // 
	{&A0SR01RIM,8,0},	//(A0SR01RIM) Текущая реактивность AЗ1
	{&B0SR01RIM,8,2},	//(B0SR01RIM) Текущая реактивность AЗ2
	{&A0SN08RIM,8,4},	//(A0SN08RIM) Поток нейтронов AЗ1(нейтр/с)
	{&B0SN08RIM,8,6},	//(B0SN08RIM) Поток нейтронов AЗ2(нейтр/с)
	{&R0CR01RIM,8,8},	//(R0CR01RIM) Коэффициент 12 связи АЗ1,2
	{&R0CR02RIM,8,10},	//(R0CR02RIM) Коэффициент 11 связи АЗ1,2
	{&R0SR02RIM,8,12},	//(R0SR02RIM) Текущая мощность РУ (ватт)
	{&R0ST01RIM,8,14},	//(R0ST01RIM) Текущий период разгона РУ
	{&R0SR01RIM,8,16},	//(R0SR01RIM) Текущая реактивность PУ
	{&R0VN15RS1,3,18},	//(R0VN15RS1) Номер ведущей камеры 1-СНМ-11,2-КНК-15М-1,3-КНК-53М,0-нет ведущей
	{&R0VN15RS2,3,19},	//(R0VN15RS2) Номер ведущей камеры канал 2
	{&R0VN15RS3,3,20},	//(R0VN15RS3) Номер ведущей камеры канал 3
	{&R0VN15RS4,3,21},	//(R0VN15RS4) Номер ведущей камеры канал 4
	{&A0VN01RIM,8,22},	//(A0VN01RIM) Период разгона  AЗ1
	{&A0SN02RIM,8,24},	//(A0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
	{&A0SN03RIM,8,26},	//(A0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
	{&A0SN04RIM,8,28},	//(A0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
	{&A0SN05RIM,8,30},	//(A0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
	{&A0SN06RIM,8,32},	//(A0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
	{&A0SN07RIM,8,34},	//(A0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
	{&B0SN02RIM,8,36},	//(B0SN02RIM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
	{&B0SN03RIM,8,38},	//(B0SN03RIM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
	{&B0SN04RIM,8,40},	//(B0SN04RIM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
	{&B0SN05RIM,8,42},	//(B0SN05RIM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
	{&B0SN06RIM,8,44},	//(B0SN06RIM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
	{&B0SN07RIM,8,46},	//(B0SN07RIM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SCM[]={  // 
	{&fEM_R0UL01RIM,8,0},	//(R0UL01RIM) Среднее время генерации нейтронов
	{&fEM_R0UN02RIM,8,2},	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{&fEM_A1UR01RIM,8,4},	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{&fEM_A1UR00RIM,8,6},	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{&fEM_A3UR00RIM,8,8},	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{&fEM_A3UR01RIM,8,10},	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{&fEM_R0UT01RIM,8,12},	//(R0UT01RIM) Температурный коэффициент (долл)
	{&fEM_R0UT02RIM,8,14},	//(R0UT02RIM) Масса топлива в АЗ
	{&fEM_R0UT04RIM,8,16},	//(R0UT04RIM) Удельная теплоёмкость топлива
	{&fEM_R0UT03RIM,8,18},	//(R0UT03RIM) Нормальная температура АЗ град
	{&fEM_R0UT05RIM,8,20},	//(R0UT05RIM) Энергия деления ядра
	{&fEM_R0UT06RIM,8,22},	//(R0UT06RIM) Конвекционное сопротивление при обдуве
	{&fEM_A1UC02RDU,8,24},	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{&fEM_A1UC04RIM,8,26},	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
	{&fEM_A1UC05RIM,8,28},	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
	{&fEM_A1UC06RIM,8,30},	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
	{&fEM_A2UC06RIM,8,32},	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
	{&fEM_A2UC05RIM,8,34},	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
	{&fEM_A2UC04RIM,8,36},	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
	{&fEM_A2UC02RDU,8,38},	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{&fEM_A3UC06RIM,8,40},	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
	{&fEM_A3UC05RIM,8,42},	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
	{&fEM_A3UC04RIM,8,44},	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
	{&fEM_A3UC02RDU,8,46},	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{&fEM_R4UV80RDU,8,48},	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
	{&fEM_R4UC10RIM,8,50},	//(R4UC10RIM) Координата верхних механических упоров тележки мм
	{&fEM_R4UC20RIM,8,52},	//(R4UC20RIM) Координата нижних механических упоров тележки мм
	{&fEM_B8UC21RIM,8,54},	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
	{&fEM_B8UC20RIM,8,56},	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
	{&fEM_B8UC11RIM,8,58},	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
	{&fEM_B8UC10RIM,8,60},	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
	{&fEM_B8UV80RDU,8,62},	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
	{&fEM_A8UV80RDU,8,64},	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
	{&fEM_A8UC10RIM,8,66},	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
	{&fEM_A8UC11RIM,8,68},	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
	{&fEM_A8UC20RIM,8,70},	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
	{&fEM_A8UC21RIM,8,72},	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
	{&fEM_A6UC10RIM,8,74},	//(A6UC10RIM) Время полного хода БЗ (сек)
	{&fEM_R1UC10RIM,8,76},	//(R1UC10RIM) Время полного хода МДЗ сек
	{&fEM_A5UC10RIM,8,78},	//(A5UC10RIM) Время полного хода НЛ сек
	{&fEM_A0UN01RIM,8,80},	//(A0UN01RIM) Мощность источника нейтронов ИНИ
	{&fEM_R4UC22RIM,8,82},	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
	{&fEM_A1UG01RDU,8,84},	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
	{&fEM_A2UG01RDU,8,86},	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
	{&fEM_A3UG01RDU,8,88},	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
	{&fEM_R7UC10RIM,8,90},	//(R7UC10RIM) X-координата КНК53М R7IN13 см
	{&fEM_R7UC19RIM,8,92},	//(R7UC19RIM) Y-координата СНМ-11 (11) см
	{&fEM_R7UI02RIM,8,94},	//(R7UI02RIM) Коэффициент усиления уровня радиации
	{&fEM_R7UL01RIM,8,96},	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
	{&fEM_A2UR00RIM,8,98},	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{&fEM_A2UR01RIM,8,100},	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{&fEM_A0UN02RIM,8,102},	//(A0UN02RIM) Мощность источника нейтронов с АНИ
	{&fEM_R0UR30RIM,8,104},	//(R0UR30RIM) Реактивность вносимая образцами (долл)
	{&fEM_R0UR01RIM,8,106},	//(R0UR01RIM) Стартовая отрицательная реактивность
	{&fEM_R0UT02RDU,8,108},	//(R0UT02RDU) Верхний предел шкалы датчика температуры
	{&fEM_R0UT01RDU,8,110},	//(R0UT01RDU) Нижний предел шкалы датчика температуры
	{&fEM_A1UC03RDU,8,112},	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{&fEM_A2UP03RDU,8,114},	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{&fEM_A2UP04RDU,8,116},	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{&fEM_A2UC03RDU,8,118},	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{&fEM_A3UP03RDU,8,120},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A3UP04RDU,8,122},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A3UC03RDU,8,124},	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{&fEM_R7UI74RIM,8,126},	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
	{&fEM_A8UC03RDU,8,128},	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{&fEM_R0UV87RDU,8,130},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV81RDU,8,132},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{&fEM_R0UV82RDU,8,134},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{&fEM_R0UV83RDU,8,136},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{&fEM_R0UV84RDU,8,138},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{&fEM_R0UV85RDU,8,140},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV86RDU,8,142},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_A8UC08RDU,8,144},	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
	{&fEM_B8UC08RDU,8,146},	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
	{&fEM_R4UC08RDU,8,148},	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
	{&fEM_A0UX00RSS,8,150},	//(A0UX00RSS) Эффективный радиус АЗ
	{&fEM_R7UX01RSS,8,152},	//(R7UX01RSS) X-координата камеры R7IN11
	{&fEM_R7UX02RSS,8,154},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{&fEM_R7UX04RSS,8,156},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{&fEM_R7UX05RSS,8,158},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{&fEM_R7UX06RSS,8,160},	//(R7UX06RSS) X-координата камеры R7IN23 (см)
	{&fEM_R7UX07RSS,8,162},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{&fEM_R7UX08RSS,8,164},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{&fEM_R7UX09RSS,8,166},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{&fEM_R7UY01RSS,8,168},	//(R7UY01RSS) Y-координата камеры R7IN11
	{&fEM_R7UY02RSS,8,170},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{&fEM_R7UY04RSS,8,172},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{&fEM_R7UY05RSS,8,174},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{&fEM_R7UY06RSS,8,176},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{&fEM_R7UY07RSS,8,178},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{&fEM_R7UY08RSS,8,180},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{&fEM_R7UY09RSS,8,182},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{&fEM_R7UX10RSS,8,184},	//(R7UX10RSS) X-координата камеры R7IN41
	{&fEM_R7UX11RSS,8,186},	//(R7UX11RSS) X-координата камеры R7IN42
	{&fEM_R7UX12RSS,8,188},	//(R7UX12RSS) X-координата камеры R7IN43
	{&fEM_R7UY10RSS,8,190},	//(R7UY10RSS) Y-координата камеры R7IN41
	{&fEM_R7UY11RSS,8,192},	//(R7UY11RSS) Y-координата камеры R7IN42
	{&fEM_R7UY12RSS,8,194},	//(R7UY12RSS) Y-координата камеры R7IN43
	{&fEM_A0UX01RSS,8,196},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{&fEM_A0UX02RSS,8,198},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{&fEM_A0UX03RSS,8,200},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{&fEM_A0UX04RSS,8,202},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{&fEM_A0UX05RSS,8,204},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{&fEM_A0UX06RSS,8,206},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{&fEM_A0UX07RSS,8,208},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{&fEM_A0UX08RSS,8,210},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{&fEM_A0UX09RSS,8,212},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{&fEM_A0UX10RSS,8,214},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{&fEM_A0UX11RSS,8,216},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{&fEM_A0UX12RSS,8,218},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{&fEM_B0UX01RSS,8,220},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{&fEM_B0UX02RSS,8,222},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{&fEM_B0UX03RSS,8,224},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{&fEM_B0UX04RSS,8,226},	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
	{&fEM_B0UX05RSS,8,228},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{&fEM_B0UX06RSS,8,230},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{&fEM_B0UX07RSS,8,232},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{&fEM_B0UX08RSS,8,234},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{&fEM_B0UX09RSS,8,236},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{&fEM_B0UX10RSS,8,238},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{&fEM_B0UX11RSS,8,240},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{&fEM_B0UX12RSS,8,242},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{&fEM_R0UH02RSS,8,244},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{&fEM_R0UH03RSS,8,246},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
	{&fEM_R4US80RDU,8,248},	//(R4US80RDU) Тормозной путь тележки (мм)
	{&fEM_R7UI71RIM,8,250},	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{&fEM_R7UI72RIM,8,252},	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{&fEM_R7UI73RIM,8,254},	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
	{&fEM_A1UP01RIM,8,256},	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
	{&fEM_A2UP01RIM,8,258},	//(A2UP01RIM) Текущее давление на сброс РБ
	{&fEM_A0UP02RIM,8,260},	//(A0UP02RIM) Текущее давление в АЗ1,2
	{&fEM_A3UP01RIM,8,262},	//(A3UP01RIM) Текущее давление на СПУСК ИС
	{&fEM_A1UP82RIM,8,264},	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{&fEM_A3UP02RDU,8,266},	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
	{&fEM_A1UV02RIM,8,268},	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{&fEM_A3UV02RIM,8,270},	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{&fEM_A2UV02RIM,8,272},	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{&fEM_B8US80RDU,8,274},	//(B8US80RDU) Тормозной путь АЗ2 (мм)
	{&fEM_A8US80RDU,8,276},	//(A8US80RDU) Тормозной путь ДС2 (мм)
	{&fEM_A6US80RDU,8,278},	//(A6US80RDU) Тормозной путь БЗ (мм)
	{&fEM_A1US07RDU,8,280},	//(A1US07RDU) Постоянная времени масляного демпфера ББ
	{&fEM_A2US07RDU,8,282},	//(A2US07RDU) Постоянная времени масляного демпфера РБ
	{&fEM_A3US07RDU,8,284},	//(A3US07RDU) Постоянная времени масляного демпфера ИС
	{&fEM_R7UI75RIM,8,286},	//(R7UI75RIM) Множитель к уровню радиации
	{&fEM_R0UH21RSS,8,288},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{&fEM_R0UH22RSS,8,290},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{&fEM_R0UH23RSS,8,292},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{&fEM_R0UR01RSS,8,294},	//(R0UR01RSS) Уровень по мощности РУ блокировки автоматического подъёма ББ
	{&fEM_R0UL52RSS,8,296},	//(R0UL52RSS) Уровень АС по мощности
	{&fEM_R0UL41RSS,8,298},	//(R0UL41RSS) Уровень ПС по периоду разгона
	{&fEM_R0UL51RSS,8,300},	//(R0UL51RSS) Уровень АС по периоду разгона
	{&fEM_R0UL42RSS,8,302},	//(R0UL42RSS) Уровень ПС по мощности
	{&fEM_R0UH05RSS,8,304},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_R0UN03RSS,8,306},	//(R0UN03RSS) Нижняя граница интервала мощности для измерения периода (ватт)
	{&fEM_A4UL10RIM,8,308},	//(A4UL10RIM) Время полного перемещения НИ сек
	{&fEM_A9UL10RIM,8,310},	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
	{&fEM_R3UL10RIM,8,312},	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
	{&fEM_R5UL10RIM,8,314},	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
	{&fEM_R6UL10RIM,8,316},	//(R6UL10RIM) Время полного хода кран-балки сек
	{&fEM_A2UP02RIM,8,318},	//(A2UP02RIM) Текущее давление на подъём РБ
	{&fEM_A2UP03RIM,8,320},	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
	{&fEM_A0UP01RIM,8,322},	//(A0UP01RIM) Текущее давление в АЗ1,2
	{&fEM_A3UP02RIM,8,324},	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
	{&fEM_A4UP01RIM,8,326},	//(A4UP01RIM) Текущее давление на подъём НИ
	{&fEM_A4UP02RIM,8,328},	//(A4UP02RIM) Нижняя граница давления на подъём НИ
	{&fEM_R7UI76RIM,8,330},	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{&fEM_R7UI77RIM,8,332},	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{&iEM_TERBB1,3,334},	//(TERBB1) Неисправности  ББ1
	{&fEM_A1MC02RC1,8,335},	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
	{&fEM_A1MV02RC1,8,337},	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
	{&iEM_TERBB2,3,339},	//(TERBB2) Неисправности  ББ2
	{&fEM_B1MC02RC1,8,340},	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
	{&fEM_B1MV02RC1,8,342},	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
	{&iEM_TERRB2,3,344},	//(TERRB2) Неисправности  РБ2
	{&fEM_B2MC02RC1,8,345},	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
	{&fEM_B2MV02RC1,8,347},	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
	{&iEM_TERRB1,3,349},	//(TERRB1) Неисправности  РБ1
	{&fEM_A2MC02RC1,8,350},	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
	{&fEM_A2MV02RC1,8,352},	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
	{&iEM_TERIS2,3,354},	//(TERIS2) Неисправности  ИС2
	{&fEM_B3MC02RC1,8,355},	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
	{&fEM_B3MV02RC1,8,357},	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
	{&iEM_TERIS1,3,359},	//(TERIS1) Неисправности  ИС1
	{&fEM_A3MC02RC1,8,360},	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
	{&fEM_A3MV02RC1,8,362},	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
	{&iEM_TERA1IE04LDU,3,364},	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
	{&iEM_TERA1IE03LDU,3,365},	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
	{&fEM_A1MC01RC1,8,366},	//(A1MC01RC1) Заданная координата  ББ1 от ИС
	{&iEM_TERB1IE03LDU,3,368},	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
	{&iEM_TERB1IE04LDU,3,369},	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
	{&fEM_B1MC01RC1,8,370},	//(B1MC01RC1) Заданная координата ББ2 от ИС
	{&fEM_B1MV01RC1,8,372},	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
	{&fEM_B2MC01RC1,8,374},	//(B2MC01RC1) Заданная координата РБ2 от ИС
	{&fEM_B2MV01RC1,8,376},	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
	{&fEM_A3MC01RC1,8,378},	//(A3MC01RC1) Заданная координата ИС1 от ИС
	{&fEM_A3MV01RC1,8,380},	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
	{&fEM_B3MC01RC1,8,382},	//(B3MC01RC1) Заданная координата ИС2 от ИС
	{&fEM_B3MV01RC1,8,384},	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
	{&iEM_TERA2SS21LIM,3,386},	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
	{&iEM_TERA2SS12LIM,3,387},	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
	{&iEM_TERR6SS21LIM,3,388},	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
	{&iEM_TERA2VP82LIM,3,389},	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
	{&iEM_TERA2SS11LIM,3,390},	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
	{&iEM_TERB3SS21LIM,3,391},	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
	{&iEM_TERA0MT01RIM,3,392},	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
	{&iEM_TERB0MT01RIM,3,393},	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
	{&iEM_TERA2SP01RIM,3,394},	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
	{&iEM_TERB2SP01RIM,3,395},	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
	{&iEM_TERB3SP02RIM,3,396},	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{&iEM_TERA3SC01RIM,3,397},	//(TERA3SC01RIM) Искажение: Координата штока ИС1
	{&iEM_TERA3VP81LIM,3,398},	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
	{&iEM_TERA2SC01RIM,3,399},	//(TERA2SC01RIM) Искажение: Координата штока РБ1
	{&iEM_TERA2SS33LIM,3,400},	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{&iEM_TERA3SS21LIM,3,401},	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
	{&iEM_TERA3SS33LIM,3,402},	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{&iEM_TERA3SS31LIM,3,403},	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{&iEM_TERB3SS31LIM,3,404},	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{&iEM_TERB3SS33LIM,3,405},	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{&iEM_TERB3SC01RIM,3,406},	//(TERB3SC01RIM) Искажение: Координата штока ИС2
	{&iEM_TERA3SS11LIM,3,407},	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
	{&iEM_TERB3SS11LIM,3,408},	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
	{&iEM_TERR6IS64LIM,3,409},	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
	{&iEM_TERB3SS22LIM,3,410},	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
	{&iEM_TERA3SS22LIM,3,411},	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
	{&iEM_TERA3SP02RIM,3,412},	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{&iEM_TERR6IS62LIM,3,413},	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
	{&iEM_TERR6IS66LIM,3,414},	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{&iEM_TERR6IS67LIM,3,415},	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{&iEM_TERA0VP81LIM,3,416},	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
	{&iEM_TERB0VP81LIM,3,417},	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
	{&iEM_TERR0VP81LIM,3,418},	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{&iEM_TERR6IS68LIM,3,419},	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{&iEM_TERR7SI74RIM,3,420},	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
	{&iEM_TERA5SS21LIM,3,421},	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
	{&iEM_TERB5SS11LIM,3,422},	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
	{&iEM_TERA5SS11LIM,3,423},	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{&iEM_TERA9SS11LIM,3,424},	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
	{&iEM_TERB2SS11LIM,3,425},	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
	{&iEM_TERB2SS12LIM,3,426},	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
	{&iEM_TERB2SS21LIM,3,427},	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
	{&iEM_TERR3SS11LIM,3,428},	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
	{&iEM_TERB2SC01RIM,3,429},	//(TERB2SC01RIM) Искажение: Координата штока РБ2
	{&iEM_TERR3SS21LIM,3,430},	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
	{&iEM_TERR5SS11LIM,3,431},	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
	{&iEM_TERA4SS11LIM,3,432},	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
	{&iEM_TERR1SS11LIM,3,433},	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
	{&iEM_TERR1SS21LIM,3,434},	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
	{&iEM_TERR2SS11LIM,3,435},	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
	{&iEM_TERR2SS21LIM,3,436},	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
	{&iEM_TERA4VP82LIM,3,437},	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
	{&iEM_TERB4SS21LIM,3,438},	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
	{&iEM_TERR5SS21LIM,3,439},	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
	{&iEM_TERB6SS21LIM,3,440},	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
	{&iEM_TERB4SS11LIM,3,441},	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
	{&iEM_TERA4SS21LIM,3,442},	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
	{&iEM_TERA6MS11LIM,3,443},	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
	{&iEM_TERA6SS21LIM,3,444},	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
	{&iEM_TERB6SS11LIM,3,445},	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
	{&iEM_TERR4SS11LIM,3,446},	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
	{&iEM_TERR4MS21LIM,3,447},	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
	{&iEM_TERR4SS12LIM,3,448},	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
	{&iEM_TERR4SS22LIM,3,449},	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
	{&iEM_TERR8SS11LIM,3,450},	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
	{&iEM_TERB8SC01RIM,3,451},	//(TERB8SC01RIM) Искажение: Координата АЗ2
	{&iEM_TERA8SC01RIM,3,452},	//(TERA8SC01RIM) Искажение: Координата ДС2
	{&iEM_TERB8SS12LIM,3,453},	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
	{&iEM_TERA8SS12LIM,3,454},	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
	{&iEM_TERB8SS22LIM,3,455},	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
	{&iEM_TERA8SS22LIM,3,456},	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
	{&iEM_TERA9SS21LIM,3,457},	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
	{&iEM_TERB9SS21LIM,3,458},	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
	{&iEM_TERB9SS11LIM,3,459},	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
	{&iEM_TERB5SS21LIM,3,460},	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
	{&iEM_TERA1SS21LIM,3,461},	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
	{&iEM_TERA1SS11LIM,3,462},	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
	{&iEM_TERA1SC01RIM,3,463},	//(TERA1SC01RIM) Искажение: Координата штока ББ1
	{&iEM_TERA1SS12LIM,3,464},	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
	{&iEM_TERB1SS21LIM,3,465},	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
	{&iEM_TERB1SS11LIM,3,466},	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
	{&iEM_TERB1MC01RIM,3,467},	//(TERB1MC01RIM) Искажение: Координата штока ББ2
	{&iEM_TERB1SS12LIM,3,468},	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
	{&iEM_TERR0IE43LIM,3,469},	//(TERR0IE43LIM) Исправность ВИП 0,5 4канала
	{&iEM_TERR0IE41LIM,3,470},	//(TERR0IE41LIM) Исправность ВИП 1,6 (№17) СНМ11 4канала
	{&iEM_TERR0IE33LIM,3,471},	//(TERR0IE33LIM) Искажение:Исправность ВИП 0,5  3канала
	{&iEM_TERR0IE31LIM,3,472},	//(TERR0IE31LIM) Искажение: Исправность ВИП 1,6 (№14) СНМ11 3канала
	{&iEM_TERR0IE11LIM,3,473},	//(TERR0IE11LIM) Искажение: Исправность ВИП 1,6 (№8) СНМ11 1канала
	{&iEM_TERR0IE13LIM,3,474},	//(TERR0IE13LIM) Искажение: Исправность ВИП 0,5  1канала
	{&iEM_TERR0IE23LIM,3,475},	//(TERR0IE23LIM) Искажение: Исправность ВИП 0,5 (№13) КНК53М 2канала
	{&iEM_TERR0IE21LIM,3,476},	//(TERR0IE21LIM) Искажение: Исправность ВИП 1,6 (№11) СНМ11 2канала
	{&iEM_TERTLG,3,477},	//(TERTLG) Неисправности  тележки от ИС
	{&fEM_R4MC01RC1,8,478},	//(R4MC01RC1) Заданная координата тележки от ИС
	{&fEM_R4MV01RC1,8,480},	//(R4MV01RC1) Заданная скорость тележки от ИС
	{&iEM_TERMAZ2,3,482},	//(TERMAZ2) Неисправности АЗ2 от ИС
	{&fEM_B8MC01RC1,8,483},	//(B8MC01RC1) аданная координата АЗ2 от ИС
	{&fEM_B8MV01RC1,8,485},	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
	{&iEM_TERDS2,3,487},	//(TERDS2) Неисправности ДС2 от ИС
	{&fEM_A8MC01RC1,8,488},	//(A8MC01RC1) Заданная координата ДС2 от ИС
	{&fEM_A8MV01RC1,8,490},	//(A8MV01RC1) Заданная скорость ДС2 от ИС
	{&iEM_TERBZ1,3,492},	//(TERBZ1) Неисправности БЗ1
	{&fEM_A6MC01RC1,8,493},	//(A6MC01RC1) Заданная координата БЗ1 от ИС
	{&fEM_A6MV01RC1,8,495},	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
	{&iEM_TERBZ2,3,497},	//(TERBZ2) Неисправности БЗ2
	{&fEM_B6MC01RC1,8,498},	//(B6MC01RC1) Заданная координата БЗ2 от ИС
	{&fEM_B6MV01RC1,8,500},	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
	{&iEM_TERMDZ2,3,502},	//(TERMDZ2) Неисправности МДЗ2
	{&fEM_R2MC01RC1,8,503},	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
	{&fEM_R2MV01RC1,8,505},	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
	{&iEM_TERMDZ1,3,507},	//(TERMDZ1) Неисправности МДЗ1
	{&fEM_R1MC01RC1,8,508},	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
	{&fEM_R1MV01RC1,8,510},	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
	{&iEM_TERNL1,3,512},	//(TERNL1) Неисправности НЛ1
	{&fEM_A5MC01RC1,8,513},	//(A5MC01RC1) Заданная координата НЛ1 от ИС
	{&fEM_A5MV01RC1,8,515},	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
	{&iEM_TERNL2,3,517},	//(TERNL2) Неисправности НЛ2
	{&fEM_B5MC01RC1,8,518},	//(B5MC01RC1) Заданная координата НЛ2 от ИС
	{&fEM_B5MV01RC1,8,520},	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
	{&fEM_A1UC08RIM,8,522},	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
	{&fEM_A2UC08RIM,8,524},	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
	{&fEM_A3UC08RIM,8,526},	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
	{&fEM_R0UL01RSS,8,528},	//(R0UL01RSS) Шаг (мс) измерения периода
	{&fEM_R0UL03RSS,8,530},	//(R0UL03RSS) Предельное время ожидания роста потока (сек)
	{&iEM_TERB2SS33LIM,3,532},	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{&iEM_TERA1VP81LIM,3,533},	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
	{&iEM_TERB1VP81LIM,3,534},	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
	{&fEM_A0UT03RSP,8,535},	//(A0UT03RSP) Стартовая  температура АЗ1 град
	{&fEM_A0UR01RSP,8,537},	//(A0UR01RSP) Стартовая  реактивность АЗ1
	{&fEM_A0UR02RSP,8,539},	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
	{&fEM_B0UT03RSP,8,541},	//(B0UT03RSP) Стартовая  температура АЗ2 град
	{&fEM_A1MC01RSP,8,543},	//(A1MC01RSP) Стартовая координата  ББ1
	{&fEM_A1MC02RSP,8,545},	//(A1MC02RSP) Стартовая координата штока ББ1
	{&fEM_A1MV01RSP,8,547},	//(A1MV01RSP) Стартовая скорость движения  ББ1
	{&fEM_A1MV02RSP,8,549},	//(A1MV02RSP) Стартовая скорость движения  ББ1
	{&fEM_B1MC01RSP,8,551},	//(B1MC01RSP) Стартовая координата  ББ2
	{&fEM_B1MV01RSP,8,553},	//(B1MV01RSP) Стартовая скорость движения  ББ2
	{&fEM_B1MC02RSP,8,555},	//(B1MC02RSP) Стартовая координата штока ББ2
	{&fEM_B1MV02RSP,8,557},	//(B1MV02RSP) Стартовая скорость движения  ББ2
	{&fEM_A2MC01RC1,8,559},	//(A2MC01RC1) Заданная координата РБ1 от ИС
	{&fEM_A2MV01RC1,8,561},	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
	{&fEM_A2MC01RSP,8,563},	//(A2MC01RSP) Стартовая координата  РБ1
	{&fEM_A2MV01RSP,8,565},	//(A2MV01RSP) Стартовая скорость движения  РБ1
	{&fEM_A2MC02RSP,8,567},	//(A2MC02RSP) Стартовая координата штока РБ1
	{&fEM_A2MV02RSP,8,569},	//(A2MV02RSP) Стартовая скорость движения  РБ1
	{&fEM_B2MC01RSP,8,571},	//(B2MC01RSP) Стартовая координата  РБ2
	{&fEM_B2MV01RSP,8,573},	//(B2MV01RSP) Стартовая скорость движения  РБ2
	{&fEM_B2MC02RSP,8,575},	//(B2MC02RSP) Стартовая координата штока РБ2
	{&fEM_B2MV02RSP,8,577},	//(B2MV02RSP) Стартовая скорость движения  РБ2
	{&fEM_A3MC01RSP,8,579},	//(A3MC01RSP) Стартовая координата  ИС1
	{&fEM_A3MV01RSP,8,581},	//(A3MV01RSP) Стартовая скорость движения  ИС1
	{&fEM_A3MC02RSP,8,583},	//(A3MC02RSP) Стартовая координата штока ИС1
	{&fEM_A3MV02RSP,8,585},	//(A3MV02RSP) Стартовая скорость движения  ИС1
	{&fEM_B3MC01RSP,8,587},	//(B3MC01RSP) Стартовая координата  ИС2
	{&fEM_B3MV01RSP,8,589},	//(B3MV01RSP) Стартовая скорость движения  ИС2
	{&fEM_B3MC02RSP,8,591},	//(B3MC02RSP) Стартовая координата штока ИС2
	{&fEM_B3MV02RSP,8,593},	//(B3MV02RSP) Стартовая скорость движения  ИС2
	{&fEM_B8MC01RSP,8,595},	//(B8MC01RSP) Стартовая координата АЗ2
	{&fEM_B8MV01RSP,8,597},	//(B8MV01RSP) Стартовая скорость АЗ2
	{&fEM_A8MC01RSP,8,599},	//(A8MC01RSP) Стартовая координата ДС2
	{&fEM_A8MV01RSP,8,601},	//(A8MV01RSP) Стартовая скорость ДС2
	{&fEM_A6MC01RSP,8,603},	//(A6MC01RSP) Стартовая координата БЗ1
	{&fEM_A6MV01RSP,8,605},	//(A6MV01RSP) Стартовая скорость БЗ1
	{&fEM_B6MC01RSP,8,607},	//(B6MC01RSP) Стартовая координата БЗ2
	{&fEM_B6MV01RSP,8,609},	//(B6MV01RSP) Стартовая скорость БЗ2
	{&fEM_R3UC01RSP,8,611},	//(R3UC01RSP) Стартовая координата Гомогенных дверей
	{&fEM_R3UV01RSP,8,613},	//(R3UV01RSP) Стартовая скорость Гомогенных дверей
	{&fEM_R5UC01RSP,8,615},	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
	{&fEM_R5UV01RSP,8,617},	//(R5UV01RSP) Стартовая скорость Ворот отстойной зоны
	{&fEM_R6UC01RSP,8,619},	//(R6UC01RSP) Стартовая координата Кран-балки
	{&fEM_R6UV01RSP,8,621},	//(R6UV01RSP) Стартовая скорость Кран-балки
	{&fEM_R2MC01RSP,8,623},	//(R2MC01RSP) Стартовая координата МДЗ2
	{&fEM_R2MV01RSP,8,625},	//(R2MV01RSP) Стартовая скорость МДЗ2
	{&fEM_R1MC01RSP,8,627},	//(R1MC01RSP) Стартовая координата МДЗ1
	{&fEM_R1MV01RSP,8,629},	//(R1MV01RSP) Стартовая скорость МДЗ1
	{&fEM_A5MC01RSP,8,631},	//(A5MC01RSP) Стартовая координата НЛ1
	{&fEM_A5MV01RSP,8,633},	//(A5MV01RSP) Стартовая скорость НЛ1
	{&fEM_B5MC01RSP,8,635},	//(B5MC01RSP) Стартовая координата НЛ2
	{&fEM_B5MV01RSP,8,637},	//(B5MV01RSP) Стартовая скорость НЛ2
	{&fEM_A9MC01RSP,8,639},	//(A9MC01RSP) Стартовая координата НИ ДС1
	{&fEM_A9MV01RSP,8,641},	//(A9MV01RSP) Стартовая скорость НИ ДС1
	{&fEM_B9MC01RSP,8,643},	//(B9MC01RSP) Стартовая координата НИ ДС2
	{&fEM_B9MV01RSP,8,645},	//(B9MV01RSP) Стартовая скорость НИ ДС2
	{&fEM_A4MC01RSP,8,647},	//(A4MC01RSP) Стартовая координата НИ1
	{&fEM_A4MV01RSP,8,649},	//(A4MV01RSP) Стартовая скорость НИ1
	{&fEM_B4MC01RSP,8,651},	//(B4MC01RSP) Стартовая координата НИ2
	{&fEM_B4MV01RSP,8,653},	//(B4MV01RSP) Стартовая скорость НИ2
	{&fEM_R4MC01RSP,8,655},	//(R4MC01RSP) Стартовая координата тележки
	{&fEM_R4MV01RSP,8,657},	//(R4MV01RSP) Стартовая скорость тележки
	{&fEM_A1MV01RC1,8,659},	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
	{&iEM_TERB7MS31LIM,3,661},	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{&iEM_TERA7MS31LIM,3,662},	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{&fEM_R7UX03RSS,8,663},	//(R7UX03RSS) X-координата камеры R7IN13 см
	{&fEM_R7UY03RSS,8,665},	//(R7UY03RSS) Y-координата камеры R7IN13 (см)
	{&fEM_R7UY00RSS,8,667},	//(R7UY00RSS) Y-координата АЗ1 см
	{&iEM_TERA6VS12LIM,3,669},	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{&iEM_TERA6VS22LIM,3,670},	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{&iEM_TERB6VS12LIM,3,671},	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{&iEM_TERB6VS22LIM,3,672},	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{&iEM_TERA5VS22LIM,3,673},	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
	{&iEM_TERA5VS12LIM,3,674},	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
	{&iEM_TERB5VS12LIM,3,675},	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
	{&iEM_TERB5VS22LIM,3,676},	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
	{&iEM_TERR1VS12LIM,3,677},	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
	{&iEM_TERR1VS22LIM,3,678},	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
	{&iEM_TERR2VS12LIM,3,679},	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
	{&iEM_TERR2VS22LIM,3,680},	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
	{&iEM_TERR4VS12LDU,3,681},	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{&iEM_TERR4VS22LDU,3,682},	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SBz1[]={  // 
	{&R0EE01LZ1,1,0},	//(R0EE01LZ1) Питание  АКНП1  отключить
	{&R0EE02LZ1,1,1},	//(R0EE02LZ1) Питание  АКНП  отключить
	{&R0EE03LZ1,1,2},	//(R0EE03LZ1) Питание  АКНП3  отключить
	{&R0EE04LZ1,1,3},	//(R0EE04LZ1) Питание  АКНП4  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz1[]={  // 
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
static ModbusRegister ir_SBz1[]={  // 
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
static ModbusRegister hr_SBz1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SBz2[]={  // 
	{&R0EE01LZ2,1,0},	//(R0EE01LZ2) Питание  АКНП1  отключить
	{&R0EE02LZ2,1,1},	//(R0EE02LZ2) Питание  АКНП  отключить
	{&R0EE03LZ2,1,2},	//(R0EE03LZ2) Питание  АКНП3  отключить
	{&R0EE04LZ2,1,3},	//(R0EE04LZ2) Питание  АКНП4  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz2[]={  // 
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
static ModbusRegister ir_SBz2[]={  // 
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
static ModbusRegister hr_SBz2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SDu[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SDu[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SDu[]={  // 
	{&A2IC01UDU,5,0},	//(A2IC01UDU) Координата штока РБ1
	{&A3IC01UDU,5,2},	//(A3IC01UDU) Координата штока ИС1
	{&B3IC01UDU,5,4},	//(B3IC01UDU) Координата штока ИС2
	{&A8IC01UDU,5,6},	//(A8IC01UDU) Координата ДС2
	{&B8IC01UDU,5,8},	//(B8IC01UDU) Координата АЗ2
	{&B2IC01UDU,5,10},	//(B2IC01UDU) Координата штока РБ2
	{&A1IC01UDU,5,12},	//(A1IC01UDU) Координата штока ББ1
	{&B1IC01UDU,5,14},	//(B1IC01UDU) Координата штока ББ2
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SDu[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_SCM[0],&di_SCM[0],&ir_SCM[0],&hr_SCM[0],NULL,NULL,NULL,0},	 //Общий слэйв
	{0,5003,&coil_SBz1[0],&di_SBz1[0],&ir_SBz1[0],&hr_SBz1[0],NULL,NULL,NULL,0},	 //Cлэйв Baz1
	{0,5004,&coil_SBz2[0],&di_SBz2[0],&ir_SBz2[0],&hr_SBz2[0],NULL,NULL,NULL,0},	 //Cлэйв Baz2
	{0,5005,&coil_SDu[0],&di_SDu[0],&ir_SDu[0],&hr_SDu[0],NULL,NULL,NULL,0},	 //Cлэйв DU

	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},};
#pragma pop
#include "drivers/ao16.h"
static char buf_AO1601[127];	//AO16
static ao16_inimod ini_AO1601={0xffff,120,0x43,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_AO1601={0,0,&ini_AO1601,buf_AO1601,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_AO1601[]={
	{&A0IT01IZ1,3,0},
	{&A0IT02IZ2,3,12},
	{&B0IT01IZ1,3,6},
	{&B0IT02IZ2,3,18},
	{&A2IP01IZ1,3,3},
	{&A2IP01IZ2,3,15},
	{&B3IP02IDU,3,27},
	{&A3IP02IDU,3,24},
	{&B2IP01IZ2,3,21},
	{&B2IP01IZ1,3,9},
	{NULL,0,0},
};
#pragma pop
#include "drivers/do32_pti.h"
static char buf_DO32_5F01[137];	//do32_5f(0x100)
static do32_pti_inipar ini_DO32_5F01={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F01={0,0,&ini_DO32_5F01,buf_DO32_5F01,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F01[]={
	{&R0VN75LZ1,1,2},
	{&A1VP81LZZ,1,54},
	{&R0VN74LZ1,1,24},
	{&A0VN71LS4,1,30},
	{&R0VN78LZ1,1,26},
	{&A0EE01LS4,1,28},
	{&B0VP81LZZ,1,58},
	{&A0VP81LZZ,1,52},
	{&A0VN71LS1,1,6},
	{&R0VN71LZ1,1,0},
	{&R6IS68LZZ,1,36},
	{&R6IS67LZZ,1,34},
	{&R6IS66LZZ,1,32},
	{&B3IS22LDU,1,22},
	{&A3IS22LDU,1,10},
	{&B3IS11LDU,1,20},
	{&A3IS11LDU,1,8},
	{&R7II72LZ1,1,48},
	{&R0VN72LZ1,1,12},
	{&A0VN71LS3,1,44},
	{&R0VN73LZ1,1,38},
	{&B1VP81LZZ,1,60},
	{&A0VN71LS2,1,18},
	{&R7II73LZ1,1,50},
	{&R0VN76LZ1,1,14},
	{&R7II71LZ1,1,46},
	{&A0EE01LS2,1,16},
	{&R0VN77LZ1,1,40},
	{&A0EE01LS3,1,42},
	{&A0EE01LS1,1,4},
	{NULL,0,0},
};
#pragma pop
#include "drivers/do32_pti.h"
static char buf_DO32_5F02[137];	//do32_5f(0x110)
static do32_pti_inipar ini_DO32_5F02={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F02={0,0,&ini_DO32_5F02,buf_DO32_5F02,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F02[]={
	{&R0VN75LZ2,1,2},
	{&R0VN76LZ2,1,14},
	{&R0VN72LZ2,1,12},
	{&A1EE01LS2,1,16},
	{&A1VN71LS3,1,44},
	{&A1VN71LS2,1,18},
	{&A1EE01LS1,1,4},
	{&R7II73LZ2,1,50},
	{&R7II71LZ2,1,46},
	{&R0VN71LZ2,1,0},
	{&A1EE01LS4,1,28},
	{&R0VN78LZ2,1,26},
	{&R0VN73LZ2,1,38},
	{&A1VN71LS1,1,6},
	{&R0VN74LZ2,1,24},
	{&R7II72LZ2,1,48},
	{&A1VN71LS4,1,30},
	{&A1EE01LS3,1,42},
	{&R0VN77LZ2,1,40},
	{NULL,0,0},
};
#pragma pop
#include "drivers/do32_pti.h"
static char buf_DO32_5F08[137];	//do32_5f(0x130)
static do32_pti_inipar ini_DO32_5F08={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F08={0,0,&ini_DO32_5F08,buf_DO32_5F08,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F08[]={
	{&B7AS31LDU,1,10},
	{&A7AS31LDU,1,60},
	{&R8IS11LDU,1,26},
	{&A4IS21LDU,1,32},
	{&A4IS11LDU,1,30},
	{&A9IS11LDU,1,34},
	{&A9IS21LDU,1,36},
	{&B9IS11LDU,1,38},
	{&B9IS21LDU,1,40},
	{&B2IS21LDU,1,22},
	{&B2IS11LDU,1,20},
	{&B2IS12LDU,1,18},
	{&A1IS12LDU,1,62},
	{&B1IS12LDU,1,12},
	{&B3IS21LDU,1,24},
	{&B1IS21LDU,1,16},
	{&R1IS11LDU,1,42},
	{&R1IS21LDU,1,44},
	{&R2IS11LDU,1,46},
	{&R2IS21LDU,1,48},
	{&B1IS11LDU,1,14},
	{NULL,0,0},
};
#pragma pop
#include "drivers/do32_pti.h"
static char buf_DO32_5F09[137];	//do32_5f(0x140)
static do32_pti_inipar ini_DO32_5F09={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F09={0,0,&ini_DO32_5F09,buf_DO32_5F09,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F09[]={
	{&B6IS11LDU,1,58},
	{&A6IS21LDU,1,52},
	{&B6IS21LDU,1,60},
	{&A1IS21LDU,1,2},
	{&R4IS22LDU,1,48},
	{&R4IS21LDU,1,46},
	{&R4IS11LDU,1,42},
	{&R4IS12LDU,1,44},
	{&R0IS02LDU,1,32},
	{&B8IS22LDU,1,18},
	{&B8IS12LDU,1,16},
	{&B4IS11LDU,1,12},
	{&B4IS21LDU,1,14},
	{&A1IS11LDU,1,0},
	{&A2IS21LDU,1,8},
	{&A2IS11LDU,1,6},
	{&B5IS11LDU,1,62},
	{&A5IS21LDU,1,56},
	{&A5IS11LDU,1,54},
	{&A2IS12LDU,1,4},
	{&A3IS21LDU,1,10},
	{NULL,0,0},
};
#pragma pop
#include "drivers/do32_pti.h"
static char buf_DO32_5F05[137];	//do32_5f(0x150)
static do32_pti_inipar ini_DO32_5F05={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F05={0,0,&ini_DO32_5F05,buf_DO32_5F05,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F05[]={
	{&B5IS21LDU,1,0},
	{&R5IS21LDU,1,20},
	{&R5IS11LDU,1,18},
	{&R3IS11LDU,1,2},
	{&R3IS21LDU,1,4},
	{&R6IS21LDU,1,26},
	{&A8IS22LDU,1,30},
	{&A6IS11LDU,1,34},
	{&A8IS12LDU,1,28},
	{NULL,0,0},
};
#pragma pop
#include "drivers/do32_pti.h"
static char buf_DO32_5F06[137];	//do32_5f(0x160)
static do32_pti_inipar ini_DO32_5F06={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F06={0,0,&ini_DO32_5F06,buf_DO32_5F06,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F06[]={
	{&R6IS65LDU,1,62},
	{&R6IS64LDU,1,60},
	{&R6IS63LDU,1,58},
	{&R6IS62LDU,1,56},
	{NULL,0,0},
};
#pragma pop
#include "drivers/emul8enc.h"
static char buf_em8enc120[40];	//em8enc(0x120)
static em8encpti_inimod ini_em8enc120={0x340,0x4,};
#pragma pack(push,1)
static table_drv table_em8enc120={0,0,&ini_em8enc120,buf_em8enc120,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_em8enc120[]={
	{NULL,0,0},
};
#pragma pop
#include "drivers/vds32_pti.h"
static char buf_VDS32F07[66];	//vds32f2(0x340)
static vds32pti_inimod ini_VDS32F07={0,};
#pragma pack(push,1)
static table_drv table_VDS32F07={0,0,&ini_VDS32F07,buf_VDS32F07,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F07[]={
	{&B7AP31LDU,1,60},
	{&A7AP31LDU,1,32},
	{&A3AD31LDU,1,30},
	{&A2AD33LDU,1,26},
	{&A4AD10LDU,1,28},
	{&B2AD33LDU,1,54},
	{&A8AD10LDU,1,62},
	{&B3AD31LDU,1,58},
	{&A3AD34LDU,1,22},
	{&B3AD33LDU,1,52},
	{&B4AD10LDU,1,56},
	{&A3AD33LDU,1,24},
	{&B5AD20LDU,1,48},
	{&B5AD10LDU,1,46},
	{&B3AD34LDU,1,50},
	{&R1AD10LDU,1,34},
	{&A5AD20LDU,1,44},
	{&A5AD10LDU,1,42},
	{&R1AD20LDU,1,36},
	{&R2AD20LDU,1,40},
	{&R2AD10LDU,1,38},
	{NULL,0,0},
};
#pragma pop
#include "drivers/vds32_pti.h"
static char buf_VDS32F10[66];	//vds32f2(0x360)
static vds32pti_inimod ini_VDS32F10={0,};
#pragma pack(push,1)
static table_drv table_VDS32F10={0,0,&ini_VDS32F10,buf_VDS32F10,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F10[]={
	{&B3AD21LDU,1,34},
	{&B3AD11LDU,1,32},
	{&A1AD11LDU,1,50},
	{&A3AD05LDU,1,30},
	{&A3AD04LDU,1,28},
	{&A3AD03LDU,1,26},
	{&A3AD02LDU,1,24},
	{&A3AD01LDU,1,22},
	{&A3AD21LDU,1,20},
	{&A3AD11LDU,1,18},
	{&A1AD21LDU,1,52},
	{&A1AD01LDU,1,54},
	{&A1AD04LDU,1,60},
	{&A1AD03LDU,1,58},
	{&A1AD02LDU,1,56},
	{&B6AD10LDU,1,6},
	{&B6AD20LDU,1,8},
	{&A6AD20LDU,1,4},
	{&A6AD10LDU,1,2},
	{&A8AD20LDU,1,0},
	{&B9AD10LDU,1,48},
	{&B8AD20LDU,1,16},
	{&B8AD10LDU,1,14},
	{&B3AD01LDU,1,36},
	{&B3AD02LDU,1,38},
	{&B3AD03LDU,1,40},
	{&B3AD04LDU,1,42},
	{&R4AD20LDU,1,12},
	{&R4AD10LDU,1,10},
	{&A9AD10LDU,1,46},
	{&B3AD05LDU,1,44},
	{NULL,0,0},
};
#pragma pop
#include "drivers/vds32_pti.h"
static char buf_VDS32F11[66];	//vds32f2(0x310)
static vds32pti_inimod ini_VDS32F11={0,};
#pragma pack(push,1)
static table_drv table_VDS32F11={0,0,&ini_VDS32F11,buf_VDS32F11,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F11[]={
	{&B2AD31LDU,1,58},
	{&B2AD05LDU,1,42},
	{&B2AD32LDU,1,56},
	{&R8AD21LDU,1,60},
	{&A2AD32LDU,1,48},
	{&A2AD31LDU,1,50},
	{&A1AD32LDU,1,44},
	{&A1AD31LDU,1,46},
	{&A1AD05LDU,1,0},
	{&B1AD11LDU,1,2},
	{&B1AD21LDU,1,4},
	{&B1AD01LDU,1,6},
	{&B1AD02LDU,1,8},
	{&B1AD03LDU,1,10},
	{&B1AD04LDU,1,12},
	{&B2AD04LDU,1,40},
	{&B1AD32LDU,1,52},
	{&R0AD16LDU,1,62},
	{&B2AD03LDU,1,38},
	{&B2AD02LDU,1,36},
	{&B2AD01LDU,1,34},
	{&B2AD21LDU,1,32},
	{&B2AD11LDU,1,30},
	{&B1AD31LDU,1,54},
	{&A2AD05LDU,1,28},
	{&A2AD04LDU,1,26},
	{&A2AD03LDU,1,24},
	{&A2AD02LDU,1,22},
	{&A2AD01LDU,1,20},
	{&A2AD21LDU,1,18},
	{&A2AD11LDU,1,16},
	{&B1AD05LDU,1,14},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0x04,0x320,20,127,def_buf_AO1601,&table_AO1601}, //AO16
	{0x02,0x100,1,137,def_buf_DO32_5F01,&table_DO32_5F01}, //do32_5f(0x100)
	{0x02,0x110,1,137,def_buf_DO32_5F02,&table_DO32_5F02}, //do32_5f(0x110)
	{0x02,0x130,1,137,def_buf_DO32_5F08,&table_DO32_5F08}, //do32_5f(0x130)
	{0x02,0x140,1,137,def_buf_DO32_5F09,&table_DO32_5F09}, //do32_5f(0x140)
	{0x02,0x150,1,137,def_buf_DO32_5F05,&table_DO32_5F05}, //do32_5f(0x150)
	{0x02,0x160,1,137,def_buf_DO32_5F06,&table_DO32_5F06}, //do32_5f(0x160)
	{0x05,0x120,2,40,def_buf_em8enc120,&table_em8enc120}, //em8enc(0x120)
	{0x03,0x340,1,66,def_buf_VDS32F07,&table_VDS32F07}, //vds32f2(0x340)
	{0x03,0x360,1,66,def_buf_VDS32F10,&table_VDS32F10}, //vds32f2(0x360)
	{0x03,0x310,1,66,def_buf_VDS32F11,&table_VDS32F11}, //vds32f2(0x310)
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
	setAsFloat(320,0.015);
	setAsFloat(321,0.0069);
	setAsFloat(322,0.21);
	setAsFloat(323,0);
	setAsFloat(324,0);
	setAsFloat(325,0.0096);
	setAsFloat(326,0.0026);
	setAsFloat(327,106);
	setAsFloat(328,135.227);
	setAsFloat(329,25);
	setAsFloat(330,320.435466);
	setAsFloat(331,0.0055);
	setAsFloat(332,0.000877);
	setAsFloat(333,200);
	setAsFloat(334,100);
	setAsFloat(335,0);
	setAsFloat(336,0);
	setAsFloat(337,100);
	setAsFloat(338,80);
	setAsFloat(339,0.002375);
	setAsFloat(340,0);
	setAsFloat(341,165);
	setAsFloat(342,200);
	setAsFloat(343,0.001667);
	setAsFloat(344,40);
	setAsFloat(345,15630.0);
	setAsFloat(346,1374);
	setAsFloat(347,0);
	setAsFloat(348,390.0);
	setAsFloat(349,2000.0);
	setAsFloat(350,1500.0);
	setAsFloat(351,10.91);
	setAsFloat(352,10.91);
	setAsFloat(353,1500.0);
	setAsFloat(354,2000);
	setAsFloat(355,390.0);
	setAsFloat(356,0);
	setAsFloat(357,55.0);
	setAsFloat(358,15.0);
	setAsFloat(359,5.0);
	setAsFloat(360,1E12);
	setAsFloat(361,43.6);
	setAsFloat(362,20.0);
	setAsFloat(363,20.0);
	setAsFloat(364,20.0);
	setAsFloat(365,1269.0);
	setAsFloat(366,256.0);
	setAsFloat(367,1.0);
	setAsFloat(368,2.0);
	setAsFloat(369,0);
	setAsFloat(370,0.026);
	setAsFloat(371,0.08);
	setAsFloat(372,0.0);
	setAsFloat(373,27.108);
	setAsFloat(374,600);
	setAsFloat(375,0);
	setAsFloat(376,0.00009765625);
	setAsFloat(377,1.6);
	setAsFloat(378,0);
	setAsFloat(379,0.00009765625);
	setAsFloat(380,2.5);
	setAsFloat(381,0);
	setAsFloat(382,0.00009765625);
	setAsFloat(383,10000.0);
	setAsFloat(384,0.0009765625);
	setAsFloat(385,750);
	setAsFloat(386,100);
	setAsFloat(387,200);
	setAsFloat(388,300);
	setAsFloat(389,400);
	setAsFloat(390,500);
	setAsFloat(391,600);
	setAsFloat(392,0.50);
	setAsFloat(393,0.50);
	setAsFloat(394,0.50);
	setAsFloat(395,11.0);
	setAsFloat(396,1585.0);
	setAsFloat(397,1796.0);
	setAsFloat(398,1555.0);
	setAsFloat(399,1269.0);
	setAsFloat(400,1269.0);
	setAsFloat(401,1585.0);
	setAsFloat(402,1796.0);
	setAsFloat(403,1269.0);
	setAsFloat(404,248.0);
	setAsFloat(405,284.5);
	setAsFloat(406,248.0);
	setAsFloat(407,271.6);
	setAsFloat(408,287.2);
	setAsFloat(409,594.0);
	setAsFloat(410,559.0);
	setAsFloat(411,588.0);
	setAsFloat(412,1555.0);
	setAsFloat(413,1281.2);
	setAsFloat(414,1269.0);
	setAsFloat(415,594.0);
	setAsFloat(416,597.2);
	setAsFloat(417,556.8);
	setAsFloat(418,1.0);
	setAsFloat(419,1.0);
	setAsFloat(420,1.0);
	setAsFloat(421,1.0);
	setAsFloat(422,1.0);
	setAsFloat(423,1.0);
	setAsFloat(424,1.0);
	setAsFloat(425,1.0);
	setAsFloat(426,1.0);
	setAsFloat(427,1.0);
	setAsFloat(428,1.0);
	setAsFloat(429,1.0);
	setAsFloat(430,0);
	setAsFloat(431,0);
	setAsFloat(432,0);
	setAsFloat(433,0);
	setAsFloat(434,0.0);
	setAsFloat(435,0);
	setAsFloat(436,0.0);
	setAsFloat(437,0);
	setAsFloat(438,0.0);
	setAsFloat(439,0.0);
	setAsFloat(440,0.0);
	setAsFloat(441,0.0);
	setAsFloat(442,3703.704);
	setAsFloat(443,62500.0);
	setAsFloat(444,20);
	setAsFloat(445,10000);
	setAsFloat(446,10000);
	setAsFloat(447,5000);
	setAsFloat(448,0.76);
	setAsFloat(449,0.245);
	setAsFloat(450,2.9);
	setAsFloat(451,0.13);
	setAsFloat(452,0.73);
	setAsFloat(453,0.41);
	setAsFloat(454,9807.0);
	setAsFloat(455,22975.0);
	setAsFloat(456,12750.0);
	setAsFloat(457,20);
	setAsFloat(458,20);
	setAsFloat(459,0);
	setAsFloat(460,5.0);
	setAsFloat(461,5.0);
	setAsFloat(462,5.0);
	setAsFloat(463,100.0);
	setAsFloat(464,4000);
	setAsFloat(465,100000);
	setAsFloat(466,1000000);
	setAsFloat(467,10.0);
	setAsFloat(468,5100);
	setAsFloat(469,20);
	setAsFloat(470,13.0);
	setAsFloat(471,5000);
	setAsFloat(472,32000.0);
	setAsFloat(473,0.005);
	setAsFloat(474,5.0);
	setAsFloat(475,15.0);
	setAsFloat(476,15.0);
	setAsFloat(477,20.0);
	setAsFloat(478,10.0);
	setAsBool(479,0);
	setAsBool(480,0);
	setAsBool(481,0);
	setAsFloat(482,0.45);
	setAsFloat(483,0.39);
	setAsFloat(484,2.74);
	setAsFloat(485,0.07);
	setAsFloat(486,0.275);
	setAsFloat(487,0.245);
	setAsFloat(488,0.045);
	setAsFloat(489,0.05);
	setAsShort(490,0);
	setAsFloat(491,0);
	setAsFloat(492,0);
	setAsShort(493,0);
	setAsFloat(494,0);
	setAsFloat(495,0);
	setAsShort(496,0);
	setAsFloat(497,0);
	setAsFloat(498,0);
	setAsShort(499,0);
	setAsFloat(500,0);
	setAsFloat(501,0);
	setAsShort(502,0);
	setAsFloat(503,0);
	setAsFloat(504,0);
	setAsShort(505,0);
	setAsFloat(506,0);
	setAsFloat(507,0);
	setAsShort(508,0);
	setAsShort(509,0);
	setAsFloat(510,0);
	setAsShort(511,0);
	setAsShort(512,0);
	setAsFloat(513,0);
	setAsFloat(514,0);
	setAsFloat(515,0);
	setAsFloat(516,0);
	setAsFloat(517,0);
	setAsFloat(518,0);
	setAsFloat(519,0);
	setAsFloat(520,0);
	setAsShort(521,0);
	setAsShort(522,0);
	setAsShort(523,0);
	setAsShort(524,0);
	setAsShort(525,0);
	setAsShort(526,0);
	setAsShort(527,0);
	setAsShort(528,0);
	setAsShort(529,0);
	setAsShort(530,0);
	setAsShort(531,0);
	setAsShort(532,0);
	setAsShort(533,0);
	setAsShort(534,0);
	setAsShort(535,0);
	setAsShort(536,0);
	setAsShort(537,0);
	setAsShort(538,0);
	setAsShort(539,0);
	setAsShort(540,0);
	setAsShort(541,0);
	setAsShort(542,0);
	setAsShort(543,0);
	setAsShort(544,0);
	setAsShort(545,0);
	setAsShort(546,0);
	setAsShort(547,0);
	setAsShort(548,0);
	setAsShort(549,0);
	setAsShort(550,0);
	setAsShor