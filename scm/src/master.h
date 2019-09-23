#ifndef SCM_H
#define SCM_H
// Подсистема  scm:SCM
static char SimulOn=0;
static short CodeSub=1;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 //Время цикла мс
float takt,taktScheme=0,taktSS=0;
#define SIZE_BUFFER 4507
static char BUFFER[SIZE_BUFFER];
#define A0IT01IZ1	BUFFER[0]	// (ao16_pti:320 - K01AO, - ) Температура АЗ1-1
#define idA0IT01IZ1	1	// (ao16_pti:320 - K01AO, - ) Температура АЗ1-1
#define A0IT02IZ2	BUFFER[3]	// (ao16_pti:320 - K05AO, - ) Температура АЗ1-2
#define idA0IT02IZ2	2	// (ao16_pti:320 - K05AO, - ) Температура АЗ1-2
#define A0IT03IRP	BUFFER[6]	// (ao16_pti:320 - K11AO, - ) Температура АЗ1-3
#define idA0IT03IRP	3	// (ao16_pti:320 - K11AO, - ) Температура АЗ1-3
#define A0SN02RIM	BUFFER[9]	// ( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define idA0SN02RIM	4	// ( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define A0SN03RIM	BUFFER[14]	// ( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define idA0SN03RIM	5	// ( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define A0SN04RIM	BUFFER[19]	// ( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define idA0SN04RIM	6	// ( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define A0SN05RIM	BUFFER[24]	// ( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define idA0SN05RIM	7	// ( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define A0SN06RIM	BUFFER[29]	// ( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define idA0SN06RIM	8	// ( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define A0SN07RIM	BUFFER[34]	// ( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define idA0SN07RIM	9	// ( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define A0SN08RIM	BUFFER[39]	// ( - , SCM) Поток нейтронов AЗ1(нейтр/с)
#define idA0SN08RIM	10	// ( - , SCM) Поток нейтронов AЗ1(нейтр/с)
#define A0SR01RIM	BUFFER[44]	// ( - , SCM) Текущая реактивность AЗ1
#define idA0SR01RIM	11	// ( - , SCM) Текущая реактивность AЗ1
#define A0VN01RIM	BUFFER[49]	// ( - , SCM) Период разгона  AЗ1
#define idA0VN01RIM	12	// ( - , SCM) Период разгона  AЗ1
#define A0VP81LZZ	BUFFER[54]	// (do32_pti:110 - K03DO, - ) Давление АЗ1 в норме
#define idA0VP81LZZ	13	// (do32_pti:110 - K03DO, - ) Давление АЗ1 в норме
#define A1AD01LDU	BUFFER[56]	// (vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
#define idA1AD01LDU	14	// (vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
#define A1AD02LDU	BUFFER[58]	// (vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
#define idA1AD02LDU	15	// (vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
#define A1AD03LDU	BUFFER[60]	// (vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
#define idA1AD03LDU	16	// (vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
#define A1AD04LDU	BUFFER[62]	// (vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
#define idA1AD04LDU	17	// (vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
#define A1AD05LDU	BUFFER[64]	// (vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
#define idA1AD05LDU	18	// (vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
#define A1AD11LDU	BUFFER[66]	// (vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	19	// (vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
#define A1AD21LDU	BUFFER[68]	// (vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	20	// (vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
#define A1AD31LDU	BUFFER[70]	// (vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
#define idA1AD31LDU	21	// (vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
#define A1AD32LDU	BUFFER[72]	// (vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
#define idA1AD32LDU	22	// (vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
#define A1IC01UDU	BUFFER[74]	// ( - , SDu) Координата штока ББ1
#define idA1IC01UDU	23	// ( - , SDu) Координата штока ББ1
#define A1IE03LDU	BUFFER[79]	// ( - , SCM) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	24	// ( - , SCM) Движение ББ1 вперед (от БУШД)
#define A1IE04LDU	BUFFER[81]	// ( - , SCM) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	25	// ( - , SCM) Движение ББ1 назад (от БУШД)
#define A1IS11LDU	BUFFER[83]	// (do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
#define idA1IS11LDU	26	// (do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
#define A1IS11LIM	BUFFER[85]	// ( - , SCM) Магнит ББ1 обесточен
#define idA1IS11LIM	27	// ( - , SCM) Магнит ББ1 обесточен
#define A1IS12LDU	BUFFER[87]	// (do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
#define idA1IS12LDU	28	// (do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
#define A1IS21LDU	BUFFER[89]	// (do32_pti:140 - K02DO, - ) Приход на НУ ББ1
#define idA1IS21LDU	29	// (do32_pti:140 - K02DO, - ) Приход на НУ ББ1
#define A1IS32LIM	BUFFER[91]	// ( - , SCM) Клапан cброса ББ1 открыт(обесточен)
#define idA1IS32LIM	30	// ( - , SCM) Клапан cброса ББ1 открыт(обесточен)
#define A1VP81LZZ	BUFFER[93]	// (do32_pti:110 - K01DO, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	31	// (do32_pti:110 - K01DO, - ) Давление СБРОС ББ1 в норме
#define A2AD01LDU	BUFFER[95]	// (vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
#define idA2AD01LDU	32	// (vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
#define A2AD02LDU	BUFFER[97]	// (vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
#define idA2AD02LDU	33	// (vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
#define A2AD03LDU	BUFFER[99]	// (vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
#define idA2AD03LDU	34	// (vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
#define A2AD04LDU	BUFFER[101]	// (vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
#define idA2AD04LDU	35	// (vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
#define A2AD05LDU	BUFFER[103]	// (vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
#define idA2AD05LDU	36	// (vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
#define A2AD11LDU	BUFFER[105]	// (vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	37	// (vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
#define A2AD21LDU	BUFFER[107]	// (vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	38	// (vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
#define A2AD31LDU	BUFFER[109]	// (vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
#define idA2AD31LDU	39	// (vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
#define A2AD32LDU	BUFFER[111]	// (vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
#define idA2AD32LDU	40	// (vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
#define A2AD33LDU	BUFFER[113]	// (vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
#define idA2AD33LDU	41	// (vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
#define A2IC01UDU	BUFFER[115]	// ( - , SDu) Координата штока РБ1
#define idA2IC01UDU	42	// ( - , SDu) Координата штока РБ1
#define A2IP01IZ1	BUFFER[120]	// (ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	43	// (ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
#define A2IP01IZ2	BUFFER[123]	// (ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ2	44	// (ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
#define A2IS11LDU	BUFFER[126]	// (do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
#define idA2IS11LDU	45	// (do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
#define A2IS11LIM	BUFFER[128]	// ( - , SCM) Магнит РБ1 обесточен
#define idA2IS11LIM	46	// ( - , SCM) Магнит РБ1 обесточен
#define A2IS12LDU	BUFFER[130]	// (do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	47	// (do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
#define A2IS21LDU	BUFFER[132]	// (do32_pti:140 - K05DO, - ) Приход на НУ РБ1
#define idA2IS21LDU	48	// (do32_pti:140 - K05DO, - ) Приход на НУ РБ1
#define A2IS32LIM	BUFFER[134]	// ( - , SCM) Клапан cброса РБ1 открыт(обесточен)
#define idA2IS32LIM	49	// ( - , SCM) Клапан cброса РБ1 открыт(обесточен)
#define A2IS33LDU	BUFFER[136]	// ( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
#define idA2IS33LDU	50	// ( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
#define A2VP82LDU	BUFFER[138]	// ( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	51	// ( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define A3AD01LDU	BUFFER[140]	// (vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
#define idA3AD01LDU	52	// (vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
#define A3AD02LDU	BUFFER[142]	// (vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
#define idA3AD02LDU	53	// (vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
#define A3AD03LDU	BUFFER[144]	// (vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
#define idA3AD03LDU	54	// (vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
#define A3AD04LDU	BUFFER[146]	// (vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
#define idA3AD04LDU	55	// (vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
#define A3AD05LDU	BUFFER[148]	// (vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
#define idA3AD05LDU	56	// (vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
#define A3AD11LDU	BUFFER[150]	// (vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	57	// (vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
#define A3AD21LDU	BUFFER[152]	// (vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	58	// (vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
#define A3AD31LDU	BUFFER[154]	// (vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
#define idA3AD31LDU	59	// (vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
#define A3AD33LDU	BUFFER[156]	// (vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define idA3AD33LDU	60	// (vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define A3AD34LDU	BUFFER[158]	// (vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
#define idA3AD34LDU	61	// (vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
#define A3IC01UDU	BUFFER[160]	// ( - , SDu) Координата штока ИС1
#define idA3IC01UDU	62	// ( - , SDu) Координата штока ИС1
#define A3IP02IDU	BUFFER[165]	// (ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	63	// (ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
#define A3IS11LDU	BUFFER[168]	// (do32_pti:110 - K04DO, - ) Приход на ВУ ИС1
#define idA3IS11LDU	64	// (do32_pti:110 - K04DO, - ) Приход на ВУ ИС1
#define A3IS21LDU	BUFFER[170]	// (do32_pti:140 - K06DO, - ) Приход на НУ ИС1
#define idA3IS21LDU	65	// (do32_pti:140 - K06DO, - ) Приход на НУ ИС1
#define A3IS22LDU	BUFFER[172]	// (do32_pti:110 - K02DO, - ) Приход на НУП ИС1
#define idA3IS22LDU	66	// (do32_pti:110 - K02DO, - ) Приход на НУП ИС1
#define A3IS31LDU	BUFFER[174]	// ( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
#define idA3IS31LDU	67	// ( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
#define A3IS33LDU	BUFFER[176]	// ( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define idA3IS33LDU	68	// ( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define A3IS35LDU	BUFFER[178]	// ( - , - ) Клапан (ВПИС1) открыт(обесточен)
#define idA3IS35LDU	69	// ( - , - ) Клапан (ВПИС1) открыт(обесточен)
#define A3VP81LDU	BUFFER[180]	// ( - , - ) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	70	// ( - , - ) Давление СПУСК ИС1 в норме
#define A4AD10LDU	BUFFER[182]	// (vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
#define idA4AD10LDU	71	// (vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
#define A4IS10LDU	BUFFER[184]	// ( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
#define idA4IS10LDU	72	// ( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
#define A4IS11LDU	BUFFER[186]	// (do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
#define idA4IS11LDU	73	// (do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
#define A4IS21LDU	BUFFER[188]	// (do32_pti:130 - K17DO, - ) Приход на НУ НИ1
#define idA4IS21LDU	74	// (do32_pti:130 - K17DO, - ) Приход на НУ НИ1
#define A4VP82LDU	BUFFER[190]	// ( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	75	// ( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define A5AD10LDU	BUFFER[192]	// (vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
#define idA5AD10LDU	76	// (vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
#define A5AD20LDU	BUFFER[194]	// (vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
#define idA5AD20LDU	77	// (vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
#define A5IS11LDU	BUFFER[196]	// (do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
#define idA5IS11LDU	78	// (do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
#define A5IS21LDU	BUFFER[198]	// (do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
#define idA5IS21LDU	79	// (do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
#define A5VS12LDU	BUFFER[200]	// ( - , SCM) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	80	// ( - , SCM) Движение НЛ1 в сторону ВУ
#define A5VS22LDU	BUFFER[202]	// ( - , SCM) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	81	// ( - , SCM) Движение НЛ1 в сторону НУ
#define A6AD10LDU	BUFFER[204]	// (vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
#define idA6AD10LDU	82	// (vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
#define A6AD20LDU	BUFFER[206]	// (vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
#define idA6AD20LDU	83	// (vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
#define A6IS11LDU	BUFFER[208]	// (do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
#define idA6IS11LDU	84	// (do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
#define A6IS21LDU	BUFFER[210]	// (do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
#define idA6IS21LDU	85	// (do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
#define A6VS12LDU	BUFFER[212]	// ( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	86	// ( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
#define A6VS22LDU	BUFFER[214]	// ( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	87	// ( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
#define A7AP31LDU	BUFFER[216]	// (vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
#define idA7AP31LDU	88	// (vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
#define A7AS31LDU	BUFFER[218]	// (do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
#define idA7AS31LDU	89	// (do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
#define A8AD10LDU	BUFFER[220]	// (vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
#define idA8AD10LDU	90	// (vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
#define A8AD20LDU	BUFFER[222]	// (vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
#define idA8AD20LDU	91	// (vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
#define A8IC01UDU	BUFFER[224]	// ( - , SDu) Координата ДС2
#define idA8IC01UDU	92	// ( - , SDu) Координата ДС2
#define A8IS12LDU	BUFFER[229]	// (do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
#define idA8IS12LDU	93	// (do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
#define A8IS22LDU	BUFFER[231]	// (do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
#define idA8IS22LDU	94	// (do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
#define A9AD10LDU	BUFFER[233]	// (vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
#define idA9AD10LDU	95	// (vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
#define A9IS11LDU	BUFFER[235]	// (do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
#define idA9IS11LDU	96	// (do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
#define A9IS21LDU	BUFFER[237]	// (do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
#define idA9IS21LDU	97	// (do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
#define B0IT01IZ1	BUFFER[239]	// (ao16_pti:320 - K03AO, - ) Температура АЗ2-1
#define idB0IT01IZ1	98	// (ao16_pti:320 - K03AO, - ) Температура АЗ2-1
#define B0IT02IZ2	BUFFER[242]	// (ao16_pti:320 - K07AO, - ) Температура АЗ2-2
#define idB0IT02IZ2	99	// (ao16_pti:320 - K07AO, - ) Температура АЗ2-2
#define B0IT03IRP	BUFFER[245]	// (ao16_pti:320 - K12AO, - ) Температура АЗ2-3
#define idB0IT03IRP	100	// (ao16_pti:320 - K12AO, - ) Температура АЗ2-3
#define B0SN02RIM	BUFFER[248]	// ( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define idB0SN02RIM	101	// ( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define B0SN03RIM	BUFFER[253]	// ( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define idB0SN03RIM	102	// ( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define B0SN04RIM	BUFFER[258]	// ( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define idB0SN04RIM	103	// ( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define B0SN05RIM	BUFFER[263]	// ( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define idB0SN05RIM	104	// ( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define B0SN06RIM	BUFFER[268]	// ( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define idB0SN06RIM	105	// ( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define B0SN07RIM	BUFFER[273]	// ( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define idB0SN07RIM	106	// ( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define B0SN08RIM	BUFFER[278]	// ( - , SCM) Поток нейтронов AЗ2(нейтр/с)
#define idB0SN08RIM	107	// ( - , SCM) Поток нейтронов AЗ2(нейтр/с)
#define B0SR01RIM	BUFFER[283]	// ( - , SCM) Текущая реактивность AЗ2
#define idB0SR01RIM	108	// ( - , SCM) Текущая реактивность AЗ2
#define B0VP81LZZ	BUFFER[288]	// (do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	109	// (do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
#define B1AD01LDU	BUFFER[290]	// (vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
#define idB1AD01LDU	110	// (vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
#define B1AD02LDU	BUFFER[292]	// (vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
#define idB1AD02LDU	111	// (vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
#define B1AD03LDU	BUFFER[294]	// (vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
#define idB1AD03LDU	112	// (vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
#define B1AD04LDU	BUFFER[296]	// (vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
#define idB1AD04LDU	113	// (vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
#define B1AD05LDU	BUFFER[298]	// (vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
#define idB1AD05LDU	114	// (vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
#define B1AD11LDU	BUFFER[300]	// (vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	115	// (vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
#define B1AD21LDU	BUFFER[302]	// (vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	116	// (vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
#define B1AD31LDU	BUFFER[304]	// (vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
#define idB1AD31LDU	117	// (vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
#define B1AD32LDU	BUFFER[306]	// (vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
#define idB1AD32LDU	118	// (vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
#define B1IC01UDU	BUFFER[308]	// ( - , SDu) Координата штока ББ2
#define idB1IC01UDU	119	// ( - , SDu) Координата штока ББ2
#define B1IE03LDU	BUFFER[313]	// ( - , SCM) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	120	// ( - , SCM) Движение ББ2 вперед (от БУШД)
#define B1IE04LDU	BUFFER[315]	// ( - , SCM) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	121	// ( - , SCM) Движение ББ2 назад (от БУШД)
#define B1IS11LDU	BUFFER[317]	// (do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
#define idB1IS11LDU	122	// (do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
#define B1IS11LIM	BUFFER[319]	// ( - , SCM) Магнит ББ2 обесточен
#define idB1IS11LIM	123	// ( - , SCM) Магнит ББ2 обесточен
#define B1IS12LDU	BUFFER[321]	// (do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
#define idB1IS12LDU	124	// (do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
#define B1IS21LDU	BUFFER[323]	// (do32_pti:130 - K09DO, - ) Приход на НУ ББ2
#define idB1IS21LDU	125	// (do32_pti:130 - K09DO, - ) Приход на НУ ББ2
#define B1IS32LIM	BUFFER[325]	// ( - , SCM) Клапан cброса ББ2 открыт(обесточен)
#define idB1IS32LIM	126	// ( - , SCM) Клапан cброса ББ2 открыт(обесточен)
#define B1VP81LZZ	BUFFER[327]	// (do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	127	// (do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
#define B2AD01LDU	BUFFER[329]	// (vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
#define idB2AD01LDU	128	// (vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
#define B2AD02LDU	BUFFER[331]	// (vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
#define idB2AD02LDU	129	// (vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
#define B2AD03LDU	BUFFER[333]	// (vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
#define idB2AD03LDU	130	// (vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
#define B2AD04LDU	BUFFER[335]	// (vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
#define idB2AD04LDU	131	// (vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
#define B2AD05LDU	BUFFER[337]	// (vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
#define idB2AD05LDU	132	// (vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
#define B2AD11LDU	BUFFER[339]	// (vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	133	// (vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
#define B2AD21LDU	BUFFER[341]	// (vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	134	// (vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
#define B2AD31LDU	BUFFER[343]	// (vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
#define idB2AD31LDU	135	// (vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
#define B2AD32LDU	BUFFER[345]	// (vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
#define idB2AD32LDU	136	// (vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
#define B2AD33LDU	BUFFER[347]	// (vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
#define idB2AD33LDU	137	// (vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
#define B2IC01UDU	BUFFER[349]	// ( - , SDu) Координата штока РБ2
#define idB2IC01UDU	138	// ( - , SDu) Координата штока РБ2
#define B2IP01IZ1	BUFFER[354]	// (ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	139	// (ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
#define B2IP01IZ2	BUFFER[357]	// (ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ2	140	// (ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
#define B2IS11LDU	BUFFER[360]	// (do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
#define idB2IS11LDU	141	// (do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
#define B2IS11LIM	BUFFER[362]	// ( - , SCM) Магнит РБ2 обесточен
#define idB2IS11LIM	142	// ( - , SCM) Магнит РБ2 обесточен
#define B2IS12LDU	BUFFER[364]	// (do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	143	// (do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
#define B2IS21LDU	BUFFER[366]	// (do32_pti:130 - K12DO, - ) Приход на НУ РБ2
#define idB2IS21LDU	144	// (do32_pti:130 - K12DO, - ) Приход на НУ РБ2
#define B2IS32LIM	BUFFER[368]	// ( - , SCM) Клапан cброса РБ2 открыт(обесточен)
#define idB2IS32LIM	145	// ( - , SCM) Клапан cброса РБ2 открыт(обесточен)
#define B2IS33LDU	BUFFER[370]	// ( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
#define idB2IS33LDU	146	// ( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
#define B2VP82LDU	BUFFER[372]	// ( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	147	// ( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define B3AD01LDU	BUFFER[374]	// (vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
#define idB3AD01LDU	148	// (vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
#define B3AD02LDU	BUFFER[376]	// (vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
#define idB3AD02LDU	149	// (vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
#define B3AD03LDU	BUFFER[378]	// (vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
#define idB3AD03LDU	150	// (vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
#define B3AD04LDU	BUFFER[380]	// (vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
#define idB3AD04LDU	151	// (vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
#define B3AD05LDU	BUFFER[382]	// (vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
#define idB3AD05LDU	152	// (vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
#define B3AD11LDU	BUFFER[384]	// (vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	153	// (vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
#define B3AD21LDU	BUFFER[386]	// (vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	154	// (vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
#define B3AD31LDU	BUFFER[388]	// (vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
#define idB3AD31LDU	155	// (vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
#define B3AD33LDU	BUFFER[390]	// (vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define idB3AD33LDU	156	// (vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define B3AD34LDU	BUFFER[392]	// (vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
#define idB3AD34LDU	157	// (vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
#define B3IC01UDU	BUFFER[394]	// ( - , SDu) Координата штока ИС2
#define idB3IC01UDU	158	// ( - , SDu) Координата штока ИС2
#define B3IP02IDU	BUFFER[399]	// (ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
#define idB3IP02IDU	159	// (ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
#define B3IS11LDU	BUFFER[402]	// (do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
#define idB3IS11LDU	160	// (do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
#define B3IS21LDU	BUFFER[404]	// (do32_pti:130 - K13DO, - ) Приход на НУ ИС2
#define idB3IS21LDU	161	// (do32_pti:130 - K13DO, - ) Приход на НУ ИС2
#define B3IS22LDU	BUFFER[406]	// (do32_pti:110 - K12DO, - ) Приход на НУП ИС2
#define idB3IS22LDU	162	// (do32_pti:110 - K12DO, - ) Приход на НУП ИС2
#define B3IS31LDU	BUFFER[408]	// ( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
#define idB3IS31LDU	163	// ( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
#define B3IS33LDU	BUFFER[410]	// ( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idB3IS33LDU	164	// ( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define B3IS35LDU	BUFFER[412]	// ( - , - ) Клапан «ВПИС2» открыт(обесточен)
#define idB3IS35LDU	165	// ( - , - ) Клапан «ВПИС2» открыт(обесточен)
#define B3VP81LDU	BUFFER[414]	// ( - , - ) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	166	// ( - , - ) Давление СПУСК ИС2 в норме
#define B4AD10LDU	BUFFER[416]	// (vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
#define idB4AD10LDU	167	// (vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
#define B4IS10LDU	BUFFER[418]	// ( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
#define idB4IS10LDU	168	// ( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
#define B4IS11LDU	BUFFER[420]	// (do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
#define idB4IS11LDU	169	// (do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
#define B4IS21LDU	BUFFER[422]	// (do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
#define idB4IS21LDU	170	// (do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
#define B4VP82LDU	BUFFER[424]	// ( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	171	// ( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define B5AD10LDU	BUFFER[426]	// (vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
#define idB5AD10LDU	172	// (vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
#define B5AD20LDU	BUFFER[428]	// (vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
#define idB5AD20LDU	173	// (vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
#define B5IS11LDU	BUFFER[430]	// (do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
#define idB5IS11LDU	174	// (do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
#define B5IS21LDU	BUFFER[432]	// (do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
#define idB5IS21LDU	175	// (do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
#define B5VS12LDU	BUFFER[434]	// ( - , SCM) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	176	// ( - , SCM) Движение НЛ2 в сторону ВУ
#define B5VS22LDU	BUFFER[436]	// ( - , SCM) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	177	// ( - , SCM) Движение НЛ2 в сторону НУ
#define B6AD10LDU	BUFFER[438]	// (vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
#define idB6AD10LDU	178	// (vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
#define B6AD20LDU	BUFFER[440]	// (vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
#define idB6AD20LDU	179	// (vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
#define B6IS11LDU	BUFFER[442]	// (do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
#define idB6IS11LDU	180	// (do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
#define B6IS21LDU	BUFFER[444]	// (do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
#define idB6IS21LDU	181	// (do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
#define B6VS12LDU	BUFFER[446]	// ( - , SCM) Движение створок БЗ2  к ОТКРЫТА
#define idB6VS12LDU	182	// ( - , SCM) Движение створок БЗ2  к ОТКРЫТА
#define B6VS22LDU	BUFFER[448]	// ( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
#define idB6VS22LDU	183	// ( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
#define B7AP31LDU	BUFFER[450]	// (vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
#define idB7AP31LDU	184	// (vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
#define B7AS31LDU	BUFFER[452]	// (do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
#define idB7AS31LDU	185	// (do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
#define B8AD10LDU	BUFFER[454]	// (vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
#define idB8AD10LDU	186	// (vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
#define B8AD20LDU	BUFFER[456]	// (vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
#define idB8AD20LDU	187	// (vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
#define B8IC01UDU	BUFFER[458]	// ( - , SDu) Координата АЗ2, мм
#define idB8IC01UDU	188	// ( - , SDu) Координата АЗ2, мм
#define B8IS11LDU	BUFFER[463]	// (do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
#define idB8IS11LDU	189	// (do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
#define B8IS12LDU	BUFFER[465]	// (do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
#define idB8IS12LDU	190	// (do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
#define B8IS21LDU	BUFFER[467]	// (do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
#define idB8IS21LDU	191	// (do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
#define B8IS22LDU	BUFFER[469]	// (do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
#define idB8IS22LDU	192	// (do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
#define B9AD10LDU	BUFFER[471]	// (vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
#define idB9AD10LDU	193	// (vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
#define B9IS11LDU	BUFFER[473]	// (do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
#define idB9IS11LDU	194	// (do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
#define B9IS21LDU	BUFFER[475]	// (do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
#define idB9IS21LDU	195	// (do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
#define C1MD31LP1	BUFFER[477]	// ( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
#define idC1MD31LP1	196	// ( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
#define C1MD31LP2	BUFFER[479]	// ( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
#define idC1MD31LP2	197	// ( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
#define C2MD31LP1	BUFFER[481]	// ( - , SCM) Кнопка «СБРОС РБ»
#define idC2MD31LP1	198	// ( - , SCM) Кнопка «СБРОС РБ»
#define LTAKTS	BUFFER[483]	// ( - , - ) takt scm
#define idLTAKTS	199	// ( - , - ) takt scm
#define R0AD16LDU	BUFFER[488]	// (vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
#define idR0AD16LDU	200	// (vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
#define R0CR01RIM	BUFFER[490]	// ( - , SCM) Коэффициент 12 связи АЗ1,2
#define idR0CR01RIM	201	// ( - , SCM) Коэффициент 12 связи АЗ1,2
#define R0CR02RIM	BUFFER[495]	// ( - , SCM) Коэффициент 11 связи АЗ1,2
#define idR0CR02RIM	202	// ( - , SCM) Коэффициент 11 связи АЗ1,2
#define R0DEUMLSS	BUFFER[500]	// ( - , SCM) Сигнал управления моделью
#define idR0DEUMLSS	203	// ( - , SCM) Сигнал управления моделью
#define R0EE01LZ1	BUFFER[503]	// ( - , SBz1) Питание  АКНП1  отключить
#define idR0EE01LZ1	204	// ( - , SBz1) Питание  АКНП1  отключить
#define R0EE01LZ2	BUFFER[505]	// ( - , SBz2) Питание  АКНП1  отключить
#define idR0EE01LZ2	205	// ( - , SBz2) Питание  АКНП1  отключить
#define R0EE02LZ1	BUFFER[507]	// ( - , SBz1) Питание  АКНП  отключить
#define idR0EE02LZ1	206	// ( - , SBz1) Питание  АКНП  отключить
#define R0EE02LZ2	BUFFER[509]	// ( - , SBz2) Питание  АКНП  отключить
#define idR0EE02LZ2	207	// ( - , SBz2) Питание  АКНП  отключить
#define R0EE03LZ1	BUFFER[511]	// ( - , SBz1) Питание  АКНП3  отключить
#define idR0EE03LZ1	208	// ( - , SBz1) Питание  АКНП3  отключить
#define R0EE03LZ2	BUFFER[513]	// ( - , SBz2) Питание  АКНП3  отключить
#define idR0EE03LZ2	209	// ( - , SBz2) Питание  АКНП3  отключить
#define R0EE04LZ1	BUFFER[515]	// ( - , SBz1) Питание  АКНП4  отключить
#define idR0EE04LZ1	210	// ( - , SBz1) Питание  АКНП4  отключить
#define R0EE04LZ2	BUFFER[517]	// ( - , SBz2) Питание  АКНП4  отключить
#define idR0EE04LZ2	211	// ( - , SBz2) Питание  АКНП4  отключить
#define R0IN01FI1	BUFFER[519]	// ( - , SA1) Выход СНМ11 Гц от ПТИ
#define idR0IN01FI1	212	// ( - , SA1) Выход СНМ11 Гц от ПТИ
#define R0IN01FI2	BUFFER[524]	// ( - , SA2) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI2	213	// ( - , SA2) Выход СНМ-11 Гц от ПТИ
#define R0IN01FI3	BUFFER[529]	// ( - , SA3) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI3	214	// ( - , SA3) Выход СНМ-11 Гц от ПТИ
#define R0IN01FI4	BUFFER[534]	// ( - , SA4) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI4	215	// ( - , SA4) Выход СНМ-11 Гц от ПТИ
#define R0IN01RIP	BUFFER[539]	// ( - , SRP) Выход СНМ-11 Гц от ПТИ
#define idR0IN01RIP	216	// ( - , SRP) Выход СНМ-11 Гц от ПТИ
#define R0IN02FI1	BUFFER[544]	// ( - , SA1) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI1	217	// ( - , SA1) Выход КНК15-1 Гц от ПТИ
#define R0IN02FI2	BUFFER[549]	// ( - , SA2) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI2	218	// ( - , SA2) Выход КНК15-1 Гц от ПТИ
#define R0IN02FI3	BUFFER[554]	// ( - , SA3) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI3	219	// ( - , SA3) Выход КНК15-1 Гц от ПТИ
#define R0IN02FI4	BUFFER[559]	// ( - , SA4) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI4	220	// ( - , SA4) Выход КНК15-1 Гц от ПТИ
#define R0IN02RIP	BUFFER[564]	// ( - , SRP) Выход КНК15- Гц от ПТИ
#define idR0IN02RIP	221	// ( - , SRP) Выход КНК15- Гц от ПТИ
#define R0IN03FI1	BUFFER[569]	// ( - , SA1) Выход КНК53М Гц от ПТИ
#define idR0IN03FI1	222	// ( - , SA1) Выход КНК53М Гц от ПТИ
#define R0IN03FI2	BUFFER[574]	// ( - , SA2) Выход КНК53М Гц от ПТИ
#define idR0IN03FI2	223	// ( - , SA2) Выход КНК53М Гц от ПТИ
#define R0IN03FI3	BUFFER[579]	// ( - , SA3) Выход КНК53М Гц от ПТИ
#define idR0IN03FI3	224	// ( - , SA3) Выход КНК53М Гц от ПТИ
#define R0IN03FI4	BUFFER[584]	// ( - , SA4) Выход КНК53М Гц от ПТИ
#define idR0IN03FI4	225	// ( - , SA4) Выход КНК53М Гц от ПТИ
#define R0IN03RIP	BUFFER[589]	// ( - , SRP) Выход КНК53М Гц от ПТИ
#define idR0IN03RIP	226	// ( - , SRP) Выход КНК53М Гц от ПТИ
#define R0IN06RIP	BUFFER[594]	// ( - , SRP) Выход СНМ-11-1 Гц от ПТИ
#define idR0IN06RIP	227	// ( - , SRP) Выход СНМ-11-1 Гц от ПТИ
#define R0IN07RIP	BUFFER[599]	// ( - , SRP) Выход СНМ-11-2 Гц от ПТИ
#define idR0IN07RIP	228	// ( - , SRP) Выход СНМ-11-2 Гц от ПТИ
#define R0IS01FI0	BUFFER[604]	// ( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
#define idR0IS01FI0	229	// ( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
#define R0IS02LDU	BUFFER[606]	// (do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
#define idR0IS02LDU	230	// (do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
#define R0MW11IP1	BUFFER[608]	// ( - , SCM) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	231	// ( - , SCM) Переключатель ВЫСТРЕЛ
#define R0MW13LP2	BUFFER[611]	// ( - , SCM) Переключатель «СЕТЬ»
#define idR0MW13LP2	232	// ( - , SCM) Переключатель «СЕТЬ»
#define R0S01LIM	BUFFER[613]	// (vds32_pti:360 - K32VDSR, - ) Отключение сетевых передач ПТИ
#define idR0S01LIM	233	// (vds32_pti:360 - K32VDSR, - ) Отключение сетевых передач ПТИ
#define R0SR01RIM	BUFFER[615]	// ( - , SCM) Текущая реактивность PУ
#define idR0SR01RIM	234	// ( - , SCM) Текущая реактивность PУ
#define R0SR02RIM	BUFFER[620]	// ( - , SCM) Текущая мощность РУ (ватт)
#define idR0SR02RIM	235	// ( - , SCM) Текущая мощность РУ (ватт)
#define R0SR03RIM	BUFFER[625]	// ( - , SCM) Текущая мощность РУ аз1  (ватт)
#define idR0SR03RIM	236	// ( - , SCM) Текущая мощность РУ аз1  (ватт)
#define R0ST01RIM	BUFFER[630]	// ( - , SCM) Текущий период разгона РУ
#define idR0ST01RIM	237	// ( - , SCM) Текущий период разгона РУ
#define R0VZ71LZ1	BUFFER[635]	// ( - , SCM, SBz1) Обобщенный сигнал по АЗ  1 канала
#define idR0VZ71LZ1	238	// ( - , SCM, SBz1) Обобщенный сигнал по АЗ  1 канала
#define R0VZ71LZ2	BUFFER[637]	// ( - , SCM, SBz2) Обобщенный сигнал по АЗ  2 канала
#define idR0VZ71LZ2	239	// ( - , SCM, SBz2) Обобщенный сигнал по АЗ  2 канала
#define R1AD10LDU	BUFFER[639]	// (vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
#define idR1AD10LDU	240	// (vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
#define R1AD20LDU	BUFFER[641]	// (vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	241	// (vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
#define R1IS11LDU	BUFFER[643]	// (do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
#define idR1IS11LDU	242	// (do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
#define R1IS21LDU	BUFFER[645]	// (do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
#define idR1IS21LDU	243	// (do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
#define R1VS12LDU	BUFFER[647]	// ( - , SCM) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	244	// ( - , SCM) Движение МДЗ1 в сторону ВУ
#define R1VS22LDU	BUFFER[649]	// ( - , SCM) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	245	// ( - , SCM) Движение МДЗ1 в сторону НУ
#define R2AD10LDU	BUFFER[651]	// (vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
#define idR2AD10LDU	246	// (vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
#define R2AD20LDU	BUFFER[653]	// (vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	247	// (vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
#define R2IS11LDU	BUFFER[655]	// (do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
#define idR2IS11LDU	248	// (do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
#define R2IS21LDU	BUFFER[657]	// (do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
#define idR2IS21LDU	249	// (do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
#define R2VS12LDU	BUFFER[659]	// ( - , SCM) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	250	// ( - , SCM) Движение МДЗ2 в сторону ВУ
#define R2VS22LDU	BUFFER[661]	// ( - , SCM) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	251	// ( - , SCM) Движение МДЗ2 в сторону НУ
#define R3IS11LDU	BUFFER[663]	// (do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	252	// (do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
#define R3IS21LDU	BUFFER[665]	// (do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
#define idR3IS21LDU	253	// (do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
#define R4AD10LDU	BUFFER[667]	// (vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	254	// (vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
#define R4AD20LDU	BUFFER[669]	// (vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
#define idR4AD20LDU	255	// (vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
#define R4IS11LDU	BUFFER[671]	// (do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
#define idR4IS11LDU	256	// (do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
#define R4IS12LDU	BUFFER[673]	// (do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
#define idR4IS12LDU	257	// (do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
#define R4IS21LDU	BUFFER[675]	// (do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
#define idR4IS21LDU	258	// (do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
#define R4IS22LDU	BUFFER[677]	// (do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
#define idR4IS22LDU	259	// (do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
#define R4VS12LDU	BUFFER[679]	// ( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
#define idR4VS12LDU	260	// ( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
#define R4VS22LDU	BUFFER[681]	// ( - , SCM) Движение реактора к «У ЗАЩИТЫ»
#define idR4VS22LDU	261	// ( - , SCM) Движение реактора к «У ЗАЩИТЫ»
#define R5IS11LDU	BUFFER[683]	// (do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	262	// (do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
#define R5IS21LDU	BUFFER[685]	// (do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	263	// (do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
#define R6IS21LDU	BUFFER[687]	// (do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	264	// (do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
#define R6IS62LDU	BUFFER[689]	// ( - , - ) Исправность ВИП ССДИ-39 1канал
#define idR6IS62LDU	265	// ( - , - ) Исправность ВИП ССДИ-39 1канал
#define R6IS63LDU	BUFFER[691]	// ( - , - ) Исправность ВИП ССДИ-39 2канал
#define idR6IS63LDU	266	// ( - , - ) Исправность ВИП ССДИ-39 2канал
#define R6IS64LDU	BUFFER[693]	// ( - , - ) Исправность ВИП ССДИ-35 1канал
#define idR6IS64LDU	267	// ( - , - ) Исправность ВИП ССДИ-35 1канал
#define R6IS65LDU	BUFFER[695]	// ( - , - ) Исправность ВИП ССДИ-35 2канал
#define idR6IS65LDU	268	// ( - , - ) Исправность ВИП ССДИ-35 2канал
#define R6IS66LZ1	BUFFER[697]	// (do32_pti:100 - K17DO, - ) Исправность БОС
#define idR6IS66LZ1	269	// (do32_pti:100 - K17DO, - ) Исправность БОС
#define R6IS66LZ2	BUFFER[699]	// (do32_pti:110 - K17DO, - ) Исправность БОС
#define idR6IS66LZ2	270	// (do32_pti:110 - K17DO, - ) Исправность БОС
#define R7II71LZ1	BUFFER[701]	// (do32_pti:100 - K01DO, - ) Сработала АС 1К IУР
#define idR7II71LZ1	271	// (do32_pti:100 - K01DO, - ) Сработала АС 1К IУР
#define R7II71LZ2	BUFFER[703]	// (do32_pti:110 - K22DO, - ) Сработала АС 1К IУР
#define idR7II71LZ2	272	// (do32_pti:110 - K22DO, - ) Сработала АС 1К IУР
#define R7II72LZ1	BUFFER[705]	// (do32_pti:100 - K05DO, - ) Сработала АС 2К IУР
#define idR7II72LZ1	273	// (do32_pti:100 - K05DO, - ) Сработала АС 2К IУР
#define R7II72LZ2	BUFFER[707]	// (do32_pti:110 - K18DO, - ) Сработала АС 2К IУР
#define idR7II72LZ2	274	// (do32_pti:110 - K18DO, - ) Сработала АС 2К IУР
#define R7II73LZ1	BUFFER[709]	// (do32_pti:110 - K08DO, - ) Сработала АС 3К IУР
#define idR7II73LZ1	275	// (do32_pti:110 - K08DO, - ) Сработала АС 3К IУР
#define R7II73LZ2	BUFFER[711]	// (do32_pti:110 - K24DO, - ) Сработала АС 3К IУР
#define idR7II73LZ2	276	// (do32_pti:110 - K24DO, - ) Сработала АС 3К IУР
#define R7II74LZ1	BUFFER[713]	// (do32_pti:100 - K04DO, - ) Сработала АС 1К IIУР
#define idR7II74LZ1	277	// (do32_pti:100 - K04DO, - ) Сработала АС 1К IIУР
#define R7II74LZ2	BUFFER[715]	// (do32_pti:110 - K20DO, - ) Сработала АС 1К IIУР
#define idR7II74LZ2	278	// (do32_pti:110 - K20DO, - ) Сработала АС 1К IIУР
#define R7II75LZ1	BUFFER[717]	// (do32_pti:100 - K02DO, - ) Сработала АС 2К IIУР
#define idR7II75LZ1	279	// (do32_pti:100 - K02DO, - ) Сработала АС 2К IIУР
#define R7II75LZ2	BUFFER[719]	// (do32_pti:110 - K19DO, - ) Сработала АС 2К IIУР
#define idR7II75LZ2	280	// (do32_pti:110 - K19DO, - ) Сработала АС 2К IIУР
#define R7II76LZ1	BUFFER[721]	// (do32_pti:100 - K03DO, - ) Сработала АС 3К IIУР
#define idR7II76LZ1	281	// (do32_pti:100 - K03DO, - ) Сработала АС 3К IIУР
#define R7II76LZ2	BUFFER[723]	// (do32_pti:110 - K25DO, - ) Сработала АС 3К IIУР
#define idR7II76LZ2	282	// (do32_pti:110 - K25DO, - ) Сработала АС 3К IIУР
#define R8AD21LDU	BUFFER[725]	// (vds32_pti:310 - K31VDSR, - ) Имитация прихода на ВУ ИС для КВДС
#define idR8AD21LDU	283	// (vds32_pti:310 - K31VDSR, - ) Имитация прихода на ВУ ИС для КВДС
#define R8AD22LDU	BUFFER[727]	// (do32_pti:140 - K09DO, - ) Сигнал синхронизации с импульсом
#define idR8AD22LDU	284	// (do32_pti:140 - K09DO, - ) Сигнал синхронизации с импульсом
#define R8IS11LDU	BUFFER[729]	// (do32_pti:130 - K14DO, - ) Аварийный НИ установлен
#define idR8IS11LDU	285	// (do32_pti:130 - K14DO, - ) Аварийный НИ установлен
#define TerR0IN06FRP	BUFFER[731]	// ( - , - ) Неисправности СНМ-11 -1,2
#define idTerR0IN06FRP	286	// ( - , - ) Неисправности СНМ-11 -1,2
#define bFirstEnterFlag	BUFFER[734]	// (bFirstEnterFlag) 
#define idbFirstEnterFlag	287	// (bFirstEnterFlag) 
#define fEM_A0UN01RIM	BUFFER[736]	// (A0UN01RIM) Мощность источника нейтронов ИНИ
#define idfEM_A0UN01RIM	288	// (A0UN01RIM) Мощность источника нейтронов ИНИ
#define fEM_A0UN02RIM	BUFFER[741]	// (A0UN02RIM) Мощность источника нейтронов с АНИ
#define idfEM_A0UN02RIM	289	// (A0UN02RIM) Мощность источника нейтронов с АНИ
#define fEM_A0UN07RIM	BUFFER[746]	// (A0UN07RIM) Доля запаздывающих нейтронов
#define idfEM_A0UN07RIM	290	// (A0UN07RIM) Доля запаздывающих нейтронов
#define fEM_A0UP01RIM	BUFFER[751]	// (A0UP01RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP01RIM	291	// (A0UP01RIM) Текущее давление в АЗ1,2
#define fEM_A0UP02RIM	BUFFER[756]	// (A0UP02RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP02RIM	292	// (A0UP02RIM) Текущее давление в АЗ1,2
#define fEM_A0UR01RSP	BUFFER[761]	// (A0UR01RSP) Стартовая  реактивность АЗ1
#define idfEM_A0UR01RSP	293	// (A0UR01RSP) Стартовая  реактивность АЗ1
#define fEM_A0UR02RSP	BUFFER[766]	// (A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define idfEM_A0UR02RSP	294	// (A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define fEM_A0UT03RSP	BUFFER[771]	// (A0UT03RSP) Стартовая  температура АЗ1 град
#define idfEM_A0UT03RSP	295	// (A0UT03RSP) Стартовая  температура АЗ1 град
#define fEM_A0UX00RSS	BUFFER[776]	// (A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	296	// (A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX01RSS	BUFFER[781]	// (A0UX01RSS) Первый коэффициент калибровки камеры 1
#define idfEM_A0UX01RSS	297	// (A0UX01RSS) Первый коэффициент калибровки камеры 1
#define fEM_A0UX02RSS	BUFFER[786]	// (A0UX02RSS) Первый коэффициент калибровки камеры 2
#define idfEM_A0UX02RSS	298	// (A0UX02RSS) Первый коэффициент калибровки камеры 2
#define fEM_A0UX03RSS	BUFFER[791]	// (A0UX03RSS) Первый коэффициент калибровки камеры 3
#define idfEM_A0UX03RSS	299	// (A0UX03RSS) Первый коэффициент калибровки камеры 3
#define fEM_A0UX04RSS	BUFFER[796]	// (A0UX04RSS) Первый коэффициент калибровки камеры4
#define idfEM_A0UX04RSS	300	// (A0UX04RSS) Первый коэффициент калибровки камеры4
#define fEM_A0UX05RSS	BUFFER[801]	// (A0UX05RSS) Первый коэффициент калибровки камеры 5
#define idfEM_A0UX05RSS	301	// (A0UX05RSS) Первый коэффициент калибровки камеры 5
#define fEM_A0UX06RSS	BUFFER[806]	// (A0UX06RSS) Первый коэффициент калибровки камеры 6
#define idfEM_A0UX06RSS	302	// (A0UX06RSS) Первый коэффициент калибровки камеры 6
#define fEM_A0UX07RSS	BUFFER[811]	// (A0UX07RSS) Первый коэффициент калибровки камеры 7
#define idfEM_A0UX07RSS	303	// (A0UX07RSS) Первый коэффициент калибровки камеры 7
#define fEM_A0UX08RSS	BUFFER[816]	// (A0UX08RSS) Первый коэффициент калибровки камеры 8
#define idfEM_A0UX08RSS	304	// (A0UX08RSS) Первый коэффициент калибровки камеры 8
#define fEM_A0UX09RSS	BUFFER[821]	// (A0UX09RSS) Первый коэффициент калибровки камеры 9
#define idfEM_A0UX09RSS	305	// (A0UX09RSS) Первый коэффициент калибровки камеры 9
#define fEM_A0UX10RSS	BUFFER[826]	// (A0UX10RSS) Первый коэффициент калибровки камеры 10
#define idfEM_A0UX10RSS	306	// (A0UX10RSS) Первый коэффициент калибровки камеры 10
#define fEM_A0UX11RSS	BUFFER[831]	// (A0UX11RSS) Первый коэффициент калибровки камеры 11
#define idfEM_A0UX11RSS	307	// (A0UX11RSS) Первый коэффициент калибровки камеры 11
#define fEM_A0UX12RSS	BUFFER[836]	// (A0UX12RSS) Первый коэффициент калибровки камеры 12
#define idfEM_A0UX12RSS	308	// (A0UX12RSS) Первый коэффициент калибровки камеры 12
#define fEM_A0UX13RSS	BUFFER[841]	// (A0UX13RSS) Первый коэффициент калибровки камеры 13
#define idfEM_A0UX13RSS	309	// (A0UX13RSS) Первый коэффициент калибровки камеры 13
#define fEM_A0UX14RSS	BUFFER[846]	// (A0UX14RSS) Первый коэффициент калибровки камеры 14
#define idfEM_A0UX14RSS	310	// (A0UX14RSS) Первый коэффициент калибровки камеры 14
#define fEM_A0UX15RSS	BUFFER[851]	// (A0UX15RSS) Первый коэффициент калибровки камеры 15
#define idfEM_A0UX15RSS	311	// (A0UX15RSS) Первый коэффициент калибровки камеры 15
#define fEM_A1MC01RC1	BUFFER[856]	// (A1MC01RC1) Заданная координата  ББ1 от ИС
#define idfEM_A1MC01RC1	312	// (A1MC01RC1) Заданная координата  ББ1 от ИС
#define fEM_A1MC01RSP	BUFFER[861]	// (A1MC01RSP) Стартовая координата  ББ1
#define idfEM_A1MC01RSP	313	// (A1MC01RSP) Стартовая координата  ББ1
#define fEM_A1MC02RC1	BUFFER[866]	// (A1MC02RC1) Заданная координата штока ББ1 от ИС
#define idfEM_A1MC02RC1	314	// (A1MC02RC1) Заданная координата штока ББ1 от ИС
#define fEM_A1MC02RSP	BUFFER[871]	// (A1MC02RSP) Стартовая координата штока ББ1
#define idfEM_A1MC02RSP	315	// (A1MC02RSP) Стартовая координата штока ББ1
#define fEM_A1MV01RC1	BUFFER[876]	// (A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define idfEM_A1MV01RC1	316	// (A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define fEM_A1MV02RC1	BUFFER[881]	// (A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define idfEM_A1MV02RC1	317	// (A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define fEM_A1UC02RDU	BUFFER[886]	// (A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define idfEM_A1UC02RDU	318	// (A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define fEM_A1UC03RDU	BUFFER[891]	// (A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define idfEM_A1UC03RDU	319	// (A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define fEM_A1UC04RIM	BUFFER[896]	// (A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define idfEM_A1UC04RIM	320	// (A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define fEM_A1UC05RIM	BUFFER[901]	// (A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define idfEM_A1UC05RIM	321	// (A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define fEM_A1UC06RIM	BUFFER[906]	// (A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define idfEM_A1UC06RIM	322	// (A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define fEM_A1UC08RIM	BUFFER[911]	// (A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define idfEM_A1UC08RIM	323	// (A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define fEM_A1UG01RDU	BUFFER[916]	// (A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define idfEM_A1UG01RDU	324	// (A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define fEM_A1UP01RIM	BUFFER[921]	// (A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define idfEM_A1UP01RIM	325	// (A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define fEM_A1UP82RIM	BUFFER[926]	// (A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define idfEM_A1UP82RIM	326	// (A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define fEM_A1UR00RIM	BUFFER[931]	// (A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR00RIM	327	// (A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define fEM_A1UR01RIM	BUFFER[936]	// (A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR01RIM	328	// (A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define fEM_A1US07RDU	BUFFER[941]	// (A1US07RDU) Постоянная времени масляного демпфера ББ
#define idfEM_A1US07RDU	329	// (A1US07RDU) Постоянная времени масляного демпфера ББ
#define fEM_A1UV02RIM	BUFFER[946]	// (A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define idfEM_A1UV02RIM	330	// (A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define fEM_A2MC01RC1	BUFFER[951]	// (A2MC01RC1) Заданная координата РБ1 от ИС
#define idfEM_A2MC01RC1	331	// (A2MC01RC1) Заданная координата РБ1 от ИС
#define fEM_A2MC01RSP	BUFFER[956]	// (A2MC01RSP) Стартовая координата  РБ1
#define idfEM_A2MC01RSP	332	// (A2MC01RSP) Стартовая координата  РБ1
#define fEM_A2MC02RC1	BUFFER[961]	// (A2MC02RC1) Заданная координата штока РБ1 от ИС
#define idfEM_A2MC02RC1	333	// (A2MC02RC1) Заданная координата штока РБ1 от ИС
#define fEM_A2MC02RSP	BUFFER[966]	// (A2MC02RSP) Стартовая координата штока РБ1
#define idfEM_A2MC02RSP	334	// (A2MC02RSP) Стартовая координата штока РБ1
#define fEM_A2MV01RC1	BUFFER[971]	// (A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define idfEM_A2MV01RC1	335	// (A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define fEM_A2MV02RC1	BUFFER[976]	// (A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define idfEM_A2MV02RC1	336	// (A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define fEM_A2UC02RDU	BUFFER[981]	// (A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define idfEM_A2UC02RDU	337	// (A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define fEM_A2UC03RDU	BUFFER[986]	// (A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define idfEM_A2UC03RDU	338	// (A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define fEM_A2UC04RIM	BUFFER[991]	// (A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define idfEM_A2UC04RIM	339	// (A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define fEM_A2UC05RIM	BUFFER[996]	// (A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define idfEM_A2UC05RIM	340	// (A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define fEM_A2UC06RIM	BUFFER[1001]	// (A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define idfEM_A2UC06RIM	341	// (A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define fEM_A2UC08RIM	BUFFER[1006]	// (A2UC08RIM) Зона срабатывания КВ  РБ мм
#define idfEM_A2UC08RIM	342	// (A2UC08RIM) Зона срабатывания КВ  РБ мм
#define fEM_A2UG01RDU	BUFFER[1011]	// (A2UG01RDU) Расстояние включения масляного демпфера РБ
#define idfEM_A2UG01RDU	343	// (A2UG01RDU) Расстояние включения масляного демпфера РБ
#define fEM_A2UP01RIM	BUFFER[1016]	// (A2UP01RIM) Текущее давление на сброс РБ
#define idfEM_A2UP01RIM	344	// (A2UP01RIM) Текущее давление на сброс РБ
#define fEM_A2UP02RIM	BUFFER[1021]	// (A2UP02RIM) Текущее давление на подъём РБ
#define idfEM_A2UP02RIM	345	// (A2UP02RIM) Текущее давление на подъём РБ
#define fEM_A2UP03RDU	BUFFER[1026]	// (A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP03RDU	346	// (A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UP03RIM	BUFFER[1031]	// (A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define idfEM_A2UP03RIM	347	// (A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define fEM_A2UP04RDU	BUFFER[1036]	// (A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP04RDU	348	// (A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UR00RIM	BUFFER[1041]	// (A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define idfEM_A2UR00RIM	349	// (A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define fEM_A2UR01RIM	BUFFER[1046]	// (A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define idfEM_A2UR01RIM	350	// (A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define fEM_A2US07RDU	BUFFER[1051]	// (A2US07RDU) Постоянная времени масляного демпфера РБ
#define idfEM_A2US07RDU	351	// (A2US07RDU) Постоянная времени масляного демпфера РБ
#define fEM_A2UV02RIM	BUFFER[1056]	// (A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define idfEM_A2UV02RIM	352	// (A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define fEM_A3MC01RC1	BUFFER[1061]	// (A3MC01RC1) Заданная координата ИС1 от ИС
#define idfEM_A3MC01RC1	353	// (A3MC01RC1) Заданная координата ИС1 от ИС
#define fEM_A3MC01RSP	BUFFER[1066]	// (A3MC01RSP) Стартовая координата  ИС1
#define idfEM_A3MC01RSP	354	// (A3MC01RSP) Стартовая координата  ИС1
#define fEM_A3MC02RC1	BUFFER[1071]	// (A3MC02RC1) Заданная координата штока ИС1 от ИС
#define idfEM_A3MC02RC1	355	// (A3MC02RC1) Заданная координата штока ИС1 от ИС
#define fEM_A3MC02RSP	BUFFER[1076]	// (A3MC02RSP) Стартовая координата штока ИС1
#define idfEM_A3MC02RSP	356	// (A3MC02RSP) Стартовая координата штока ИС1
#define fEM_A3MV01RC1	BUFFER[1081]	// (A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define idfEM_A3MV01RC1	357	// (A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define fEM_A3MV02RC1	BUFFER[1086]	// (A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define idfEM_A3MV02RC1	358	// (A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define fEM_A3UC02RDU	BUFFER[1091]	// (A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define idfEM_A3UC02RDU	359	// (A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define fEM_A3UC03RDU	BUFFER[1096]	// (A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define idfEM_A3UC03RDU	360	// (A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define fEM_A3UC04RIM	BUFFER[1101]	// (A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define idfEM_A3UC04RIM	361	// (A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define fEM_A3UC05RIM	BUFFER[1106]	// (A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC05RIM	362	// (A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define fEM_A3UC06RIM	BUFFER[1111]	// (A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define idfEM_A3UC06RIM	363	// (A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define fEM_A3UC08RIM	BUFFER[1116]	// (A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define idfEM_A3UC08RIM	364	// (A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define fEM_A3UG01RDU	BUFFER[1121]	// (A3UG01RDU) Расстояние включения масляного демпфера ИС
#define idfEM_A3UG01RDU	365	// (A3UG01RDU) Расстояние включения масляного демпфера ИС
#define fEM_A3UP01RIM	BUFFER[1126]	// (A3UP01RIM) Текущее давление на СПУСК ИС
#define idfEM_A3UP01RIM	366	// (A3UP01RIM) Текущее давление на СПУСК ИС
#define fEM_A3UP02RDU	BUFFER[1131]	// (A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define idfEM_A3UP02RDU	367	// (A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define fEM_A3UP02RIM	BUFFER[1136]	// (A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define idfEM_A3UP02RIM	368	// (A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define fEM_A3UP03RDU	BUFFER[1141]	// (A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	369	// (A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	BUFFER[1146]	// (A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	370	// (A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UR00RIM	BUFFER[1151]	// (A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR00RIM	371	// (A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define fEM_A3UR01RIM	BUFFER[1156]	// (A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR01RIM	372	// (A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define fEM_A3US07RDU	BUFFER[1161]	// (A3US07RDU) Постоянная времени масляного демпфера ИС
#define idfEM_A3US07RDU	373	// (A3US07RDU) Постоянная времени масляного демпфера ИС
#define fEM_A3UV02RIM	BUFFER[1166]	// (A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define idfEM_A3UV02RIM	374	// (A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define fEM_A4MC01RSP	BUFFER[1171]	// (A4MC01RSP) Стартовая координата НИ1
#define idfEM_A4MC01RSP	375	// (A4MC01RSP) Стартовая координата НИ1
#define fEM_A4UL10RIM	BUFFER[1176]	// (A4UL10RIM) Время полного перемещения НИ сек
#define idfEM_A4UL10RIM	376	// (A4UL10RIM) Время полного перемещения НИ сек
#define fEM_A4UP01RIM	BUFFER[1181]	// (A4UP01RIM) Текущее давление на подъём НИ
#define idfEM_A4UP01RIM	377	// (A4UP01RIM) Текущее давление на подъём НИ
#define fEM_A4UP02RIM	BUFFER[1186]	// (A4UP02RIM) Нижняя граница давления на подъём НИ
#define idfEM_A4UP02RIM	378	// (A4UP02RIM) Нижняя граница давления на подъём НИ
#define fEM_A5MC01RC1	BUFFER[1191]	// (A5MC01RC1) Заданная координата НЛ1 от ИС
#define idfEM_A5MC01RC1	379	// (A5MC01RC1) Заданная координата НЛ1 от ИС
#define fEM_A5MC01RSP	BUFFER[1196]	// (A5MC01RSP) Стартовая координата НЛ1
#define idfEM_A5MC01RSP	380	// (A5MC01RSP) Стартовая координата НЛ1
#define fEM_A5MV01RC1	BUFFER[1201]	// (A5MV01RC1) Заданная скорость НЛ1 от ИС
#define idfEM_A5MV01RC1	381	// (A5MV01RC1) Заданная скорость НЛ1 от ИС
#define fEM_A5UC10RIM	BUFFER[1206]	// (A5UC10RIM) Время полного хода НЛ сек
#define idfEM_A5UC10RIM	382	// (A5UC10RIM) Время полного хода НЛ сек
#define fEM_A6MC01RC1	BUFFER[1211]	// (A6MC01RC1) Заданная координата БЗ1 от ИС
#define idfEM_A6MC01RC1	383	// (A6MC01RC1) Заданная координата БЗ1 от ИС
#define fEM_A6MC01RSP	BUFFER[1216]	// (A6MC01RSP) Стартовая координата БЗ1
#define idfEM_A6MC01RSP	384	// (A6MC01RSP) Стартовая координата БЗ1
#define fEM_A6MV01RC1	BUFFER[1221]	// (A6MV01RC1) Заданная скорость БЗ1 от ИС
#define idfEM_A6MV01RC1	385	// (A6MV01RC1) Заданная скорость БЗ1 от ИС
#define fEM_A6UC10RIM	BUFFER[1226]	// (A6UC10RIM) Время полного хода БЗ (сек)
#define idfEM_A6UC10RIM	386	// (A6UC10RIM) Время полного хода БЗ (сек)
#define fEM_A6US80RDU	BUFFER[1231]	// (A6US80RDU) Тормозной путь БЗ (мм)
#define idfEM_A6US80RDU	387	// (A6US80RDU) Тормозной путь БЗ (мм)
#define fEM_A8MC01RC1	BUFFER[1236]	// (A8MC01RC1) Заданная координата ДС2 от ИС
#define idfEM_A8MC01RC1	388	// (A8MC01RC1) Заданная координата ДС2 от ИС
#define fEM_A8MC01RSP	BUFFER[1241]	// (A8MC01RSP) Стартовая координата ДС2
#define idfEM_A8MC01RSP	389	// (A8MC01RSP) Стартовая координата ДС2
#define fEM_A8MV01RC1	BUFFER[1246]	// (A8MV01RC1) Заданная скорость ДС2 от ИС
#define idfEM_A8MV01RC1	390	// (A8MV01RC1) Заданная скорость ДС2 от ИС
#define fEM_A8UC03RDU	BUFFER[1251]	// (A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define idfEM_A8UC03RDU	391	// (A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define fEM_A8UC08RDU	BUFFER[1256]	// (A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define idfEM_A8UC08RDU	392	// (A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define fEM_A8UC10RIM	BUFFER[1261]	// (A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define idfEM_A8UC10RIM	393	// (A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define fEM_A8UC11RIM	BUFFER[1266]	// (A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define idfEM_A8UC11RIM	394	// (A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define fEM_A8UC20RIM	BUFFER[1271]	// (A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define idfEM_A8UC20RIM	395	// (A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define fEM_A8UC21RIM	BUFFER[1276]	// (A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define idfEM_A8UC21RIM	396	// (A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define fEM_A8US80RDU	BUFFER[1281]	// (A8US80RDU) Тормозной путь ДС2 (мм)
#define idfEM_A8US80RDU	397	// (A8US80RDU) Тормозной путь ДС2 (мм)
#define fEM_A8UV80RDU	BUFFER[1286]	// (A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define idfEM_A8UV80RDU	398	// (A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define fEM_A9MC01RSP	BUFFER[1291]	// (A9MC01RSP) Стартовая координата НИ ДС1
#define idfEM_A9MC01RSP	399	// (A9MC01RSP) Стартовая координата НИ ДС1
#define fEM_A9UL10RIM	BUFFER[1296]	// (A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define idfEM_A9UL10RIM	400	// (A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define fEM_B0UT03RSP	BUFFER[1301]	// (B0UT03RSP) Стартовая  температура АЗ2 град
#define idfEM_B0UT03RSP	401	// (B0UT03RSP) Стартовая  температура АЗ2 град
#define fEM_B0UX01RSS	BUFFER[1306]	// (B0UX01RSS) Второй коэффициент калибровки камеры 1
#define idfEM_B0UX01RSS	402	// (B0UX01RSS) Второй коэффициент калибровки камеры 1
#define fEM_B0UX02RSS	BUFFER[1311]	// (B0UX02RSS) Второй коэффициент калибровки камеры 2
#define idfEM_B0UX02RSS	403	// (B0UX02RSS) Второй коэффициент калибровки камеры 2
#define fEM_B0UX03RSS	BUFFER[1316]	// (B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	404	// (B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	BUFFER[1321]	// (B0UX04RSS) Второй коэффициент калибровки камеры 4
#define idfEM_B0UX04RSS	405	// (B0UX04RSS) Второй коэффициент калибровки камеры 4
#define fEM_B0UX05RSS	BUFFER[1326]	// (B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	406	// (B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_B0UX06RSS	BUFFER[1331]	// (B0UX06RSS) Второй коэффициент калибровки камеры 6
#define idfEM_B0UX06RSS	407	// (B0UX06RSS) Второй коэффициент калибровки камеры 6
#define fEM_B0UX07RSS	BUFFER[1336]	// (B0UX07RSS) Второй коэффициент калибровки камеры 7
#define idfEM_B0UX07RSS	408	// (B0UX07RSS) Второй коэффициент калибровки камеры 7
#define fEM_B0UX08RSS	BUFFER[1341]	// (B0UX08RSS) Второй коэффициент калибровки камеры 8
#define idfEM_B0UX08RSS	409	// (B0UX08RSS) Второй коэффициент калибровки камеры 8
#define fEM_B0UX09RSS	BUFFER[1346]	// (B0UX09RSS) Второй коэффициент калибровки камеры 9
#define idfEM_B0UX09RSS	410	// (B0UX09RSS) Второй коэффициент калибровки камеры 9
#define fEM_B0UX10RSS	BUFFER[1351]	// (B0UX10RSS) Второй коэффициент калибровки камеры 10
#define idfEM_B0UX10RSS	411	// (B0UX10RSS) Второй коэффициент калибровки камеры 10
#define fEM_B0UX11RSS	BUFFER[1356]	// (B0UX11RSS) Второй коэффициент калибровки камеры 11
#define idfEM_B0UX11RSS	412	// (B0UX11RSS) Второй коэффициент калибровки камеры 11
#define fEM_B0UX12RSS	BUFFER[1361]	// (B0UX12RSS) Второй коэффициент калибровки камеры 12
#define idfEM_B0UX12RSS	413	// (B0UX12RSS) Второй коэффициент калибровки камеры 12
#define fEM_B1MC01RC1	BUFFER[1366]	// (B1MC01RC1) Заданная координата ББ2 от ИС
#define idfEM_B1MC01RC1	414	// (B1MC01RC1) Заданная координата ББ2 от ИС
#define fEM_B1MC01RSP	BUFFER[1371]	// (B1MC01RSP) Стартовая координата  ББ2
#define idfEM_B1MC01RSP	415	// (B1MC01RSP) Стартовая координата  ББ2
#define fEM_B1MC02RC1	BUFFER[1376]	// (B1MC02RC1) Заданная координата штока ББ2 от ИС
#define idfEM_B1MC02RC1	416	// (B1MC02RC1) Заданная координата штока ББ2 от ИС
#define fEM_B1MC02RSP	BUFFER[1381]	// (B1MC02RSP) Стартовая координата штока ББ2
#define idfEM_B1MC02RSP	417	// (B1MC02RSP) Стартовая координата штока ББ2
#define fEM_B1MV01RC1	BUFFER[1386]	// (B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define idfEM_B1MV01RC1	418	// (B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define fEM_B1MV02RC1	BUFFER[1391]	// (B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define idfEM_B1MV02RC1	419	// (B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define fEM_B2MC01RC1	BUFFER[1396]	// (B2MC01RC1) Заданная координата РБ2 от ИС
#define idfEM_B2MC01RC1	420	// (B2MC01RC1) Заданная координата РБ2 от ИС
#define fEM_B2MC01RSP	BUFFER[1401]	// (B2MC01RSP) Стартовая координата  РБ2
#define idfEM_B2MC01RSP	421	// (B2MC01RSP) Стартовая координата  РБ2
#define fEM_B2MC02RC1	BUFFER[1406]	// (B2MC02RC1) Заданная координата штока РБ2 от ИС
#define idfEM_B2MC02RC1	422	// (B2MC02RC1) Заданная координата штока РБ2 от ИС
#define fEM_B2MC02RSP	BUFFER[1411]	// (B2MC02RSP) Стартовая координата штока РБ2
#define idfEM_B2MC02RSP	423	// (B2MC02RSP) Стартовая координата штока РБ2
#define fEM_B2MV01RC1	BUFFER[1416]	// (B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define idfEM_B2MV01RC1	424	// (B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define fEM_B2MV02RC1	BUFFER[1421]	// (B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define idfEM_B2MV02RC1	425	// (B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define fEM_B3MC01RC1	BUFFER[1426]	// (B3MC01RC1) Заданная координата ИС2 от ИС
#define idfEM_B3MC01RC1	426	// (B3MC01RC1) Заданная координата ИС2 от ИС
#define fEM_B3MC01RSP	BUFFER[1431]	// (B3MC01RSP) Стартовая координата  ИС2
#define idfEM_B3MC01RSP	427	// (B3MC01RSP) Стартовая координата  ИС2
#define fEM_B3MC02RC1	BUFFER[1436]	// (B3MC02RC1) Заданная координата штока ИС2 от ИС
#define idfEM_B3MC02RC1	428	// (B3MC02RC1) Заданная координата штока ИС2 от ИС
#define fEM_B3MC02RSP	BUFFER[1441]	// (B3MC02RSP) Стартовая координата штока ИС2
#define idfEM_B3MC02RSP	429	// (B3MC02RSP) Стартовая координата штока ИС2
#define fEM_B3MV01RC1	BUFFER[1446]	// (B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define idfEM_B3MV01RC1	430	// (B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define fEM_B3MV02RC1	BUFFER[1451]	// (B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define idfEM_B3MV02RC1	431	// (B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define fEM_B4MC01RSP	BUFFER[1456]	// (B4MC01RSP) Стартовая координата НИ2
#define idfEM_B4MC01RSP	432	// (B4MC01RSP) Стартовая координата НИ2
#define fEM_B5MC01RC1	BUFFER[1461]	// (B5MC01RC1) Заданная координата НЛ2 от ИС
#define idfEM_B5MC01RC1	433	// (B5MC01RC1) Заданная координата НЛ2 от ИС
#define fEM_B5MC01RSP	BUFFER[1466]	// (B5MC01RSP) Стартовая координата НЛ2
#define idfEM_B5MC01RSP	434	// (B5MC01RSP) Стартовая координата НЛ2
#define fEM_B5MV01RC1	BUFFER[1471]	// (B5MV01RC1) Заданная скорость НЛ2 от ИС
#define idfEM_B5MV01RC1	435	// (B5MV01RC1) Заданная скорость НЛ2 от ИС
#define fEM_B6MC01RC1	BUFFER[1476]	// (B6MC01RC1) Заданная координата БЗ2 от ИС
#define idfEM_B6MC01RC1	436	// (B6MC01RC1) Заданная координата БЗ2 от ИС
#define fEM_B6MC01RSP	BUFFER[1481]	// (B6MC01RSP) Стартовая координата БЗ2
#define idfEM_B6MC01RSP	437	// (B6MC01RSP) Стартовая координата БЗ2
#define fEM_B6MV01RC1	BUFFER[1486]	// (B6MV01RC1) Заданная скорость БЗ2 от ИС
#define idfEM_B6MV01RC1	438	// (B6MV01RC1) Заданная скорость БЗ2 от ИС
#define fEM_B8MC01RC1	BUFFER[1491]	// (B8MC01RC1) Заданная координата АЗ2 от ИС
#define idfEM_B8MC01RC1	439	// (B8MC01RC1) Заданная координата АЗ2 от ИС
#define fEM_B8MC01RSP	BUFFER[1496]	// (B8MC01RSP) Стартовая координата АЗ2
#define idfEM_B8MC01RSP	440	// (B8MC01RSP) Стартовая координата АЗ2
#define fEM_B8MV01RC1	BUFFER[1501]	// (B8MV01RC1) Заданная скорость АЗ2 от ИС
#define idfEM_B8MV01RC1	441	// (B8MV01RC1) Заданная скорость АЗ2 от ИС
#define fEM_B8UC08RDU	BUFFER[1506]	// (B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define idfEM_B8UC08RDU	442	// (B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define fEM_B8UC10RIM	BUFFER[1511]	// (B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define idfEM_B8UC10RIM	443	// (B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define fEM_B8UC11RIM	BUFFER[1516]	// (B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define idfEM_B8UC11RIM	444	// (B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define fEM_B8UC20RIM	BUFFER[1521]	// (B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define idfEM_B8UC20RIM	445	// (B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define fEM_B8UC21RIM	BUFFER[1526]	// (B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define idfEM_B8UC21RIM	446	// (B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define fEM_B8US80RDU	BUFFER[1531]	// (B8US80RDU) Тормозной путь АЗ2 (мм)
#define idfEM_B8US80RDU	447	// (B8US80RDU) Тормозной путь АЗ2 (мм)
#define fEM_B8UV80RDU	BUFFER[1536]	// (B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define idfEM_B8UV80RDU	448	// (B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define fEM_B9MC01RSP	BUFFER[1541]	// (B9MC01RSP) Стартовая координата НИ ДС2
#define idfEM_B9MC01RSP	449	// (B9MC01RSP) Стартовая координата НИ ДС2
#define fEM_R0UH01RSS	BUFFER[1546]	// (R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
#define idfEM_R0UH01RSS	450	// (R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
#define fEM_R0UH02RSS	BUFFER[1551]	// (R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define idfEM_R0UH02RSS	451	// (R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define fEM_R0UH03RSS	BUFFER[1556]	// (R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define idfEM_R0UH03RSS	452	// (R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define fEM_R0UH05RSS	BUFFER[1561]	// (R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	453	// (R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UH21RSS	BUFFER[1566]	// (R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	454	// (R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	BUFFER[1571]	// (R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	455	// (R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	BUFFER[1576]	// (R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	456	// (R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0UL01RIM	BUFFER[1581]	// (R0UL01RIM) Среднее время генерации нейтронов
#define idfEM_R0UL01RIM	457	// (R0UL01RIM) Среднее время генерации нейтронов
#define fEM_R0UL02RDU	BUFFER[1586]	// (R0UL02RDU) Время задержки  ИНИ
#define idfEM_R0UL02RDU	458	// (R0UL02RDU) Время задержки  ИНИ
#define fEM_R0UL02RIM	BUFFER[1591]	// (R0UL02RIM) Время удержания синхроимпульса
#define idfEM_R0UL02RIM	459	// (R0UL02RIM) Время удержания синхроимпульса
#define fEM_R0UL04RIM	BUFFER[1596]	// (R0UL04RIM) Время блокировки повторной генерации импульса
#define idfEM_R0UL04RIM	460	// (R0UL04RIM) Время блокировки повторной генерации импульса
#define fEM_R0UN02RIM	BUFFER[1601]	// (R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define idfEM_R0UN02RIM	461	// (R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define fEM_R0UN18RDU	BUFFER[1606]	// (R0UN18RDU) Коэффициент температурной корректировки реактивности(долл)
#define idfEM_R0UN18RDU	462	// (R0UN18RDU) Коэффициент температурной корректировки реактивности(долл)
#define fEM_R0UR01RIM	BUFFER[1611]	// (R0UR01RIM) Стартовая отрицательная реактивность
#define idfEM_R0UR01RIM	463	// (R0UR01RIM) Стартовая отрицательная реактивность
#define fEM_R0UR30RIM	BUFFER[1616]	// (R0UR30RIM) Реактивность вносимая образцами (долл)
#define idfEM_R0UR30RIM	464	// (R0UR30RIM) Реактивность вносимая образцами (долл)
#define fEM_R0UT01RDU	BUFFER[1621]	// (R0UT01RDU) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RDU	465	// (R0UT01RDU) Нижний предел шкалы датчика температуры
#define fEM_R0UT02RDU	BUFFER[1626]	// (R0UT02RDU) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RDU	466	// (R0UT02RDU) Верхний предел шкалы датчика температуры
#define fEM_R0UT02RIM	BUFFER[1631]	// (R0UT02RIM) Масса топлива в АЗ
#define idfEM_R0UT02RIM	467	// (R0UT02RIM) Масса топлива в АЗ
#define fEM_R0UT03RIM	BUFFER[1636]	// (R0UT03RIM) Нормальная температура АЗ град
#define idfEM_R0UT03RIM	468	// (R0UT03RIM) Нормальная температура АЗ град
#define fEM_R0UT04RIM	BUFFER[1641]	// (R0UT04RIM) Удельная теплоёмкость топлива
#define idfEM_R0UT04RIM	469	// (R0UT04RIM) Удельная теплоёмкость топлива
#define fEM_R0UT05RIM	BUFFER[1646]	// (R0UT05RIM) Энергия деления ядра
#define idfEM_R0UT05RIM	470	// (R0UT05RIM) Энергия деления ядра
#define fEM_R0UT06RIM	BUFFER[1651]	// (R0UT06RIM) Конвекционное сопротивление при обдуве
#define idfEM_R0UT06RIM	471	// (R0UT06RIM) Конвекционное сопротивление при обдуве
#define fEM_R0UV81RDU	BUFFER[1656]	// (R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	472	// (R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	BUFFER[1661]	// (R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	473	// (R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	BUFFER[1666]	// (R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	474	// (R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	BUFFER[1671]	// (R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	475	// (R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define fEM_R0UV85RDU	BUFFER[1676]	// (R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	476	// (R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV86RDU	BUFFER[1681]	// (R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	477	// (R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV87RDU	BUFFER[1686]	// (R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	478	// (R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R1MC01RC1	BUFFER[1691]	// (R1MC01RC1) Заданная координата МДЗ1 от ИС
#define idfEM_R1MC01RC1	479	// (R1MC01RC1) Заданная координата МДЗ1 от ИС
#define fEM_R1MC01RSP	BUFFER[1696]	// (R1MC01RSP) Стартовая координата МДЗ1
#define idfEM_R1MC01RSP	480	// (R1MC01RSP) Стартовая координата МДЗ1
#define fEM_R1MV01RC1	BUFFER[1701]	// (R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define idfEM_R1MV01RC1	481	// (R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define fEM_R1UC10RIM	BUFFER[1706]	// (R1UC10RIM) Время полного хода МДЗ сек
#define idfEM_R1UC10RIM	482	// (R1UC10RIM) Время полного хода МДЗ сек
#define fEM_R2MC01RC1	BUFFER[1711]	// (R2MC01RC1) Заданная координата МДЗ2 от ИС
#define idfEM_R2MC01RC1	483	// (R2MC01RC1) Заданная координата МДЗ2 от ИС
#define fEM_R2MC01RSP	BUFFER[1716]	// (R2MC01RSP) Стартовая координата МДЗ2
#define idfEM_R2MC01RSP	484	// (R2MC01RSP) Стартовая координата МДЗ2
#define fEM_R2MV01RC1	BUFFER[1721]	// (R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define idfEM_R2MV01RC1	485	// (R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define fEM_R3UC01RSP	BUFFER[1726]	// (R3UC01RSP) Стартовая координата Гомогенных дверей
#define idfEM_R3UC01RSP	486	// (R3UC01RSP) Стартовая координата Гомогенных дверей
#define fEM_R3UL10RIM	BUFFER[1731]	// (R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define idfEM_R3UL10RIM	487	// (R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define fEM_R4MC01RC1	BUFFER[1736]	// (R4MC01RC1) Заданная координата тележки от ИС
#define idfEM_R4MC01RC1	488	// (R4MC01RC1) Заданная координата тележки от ИС
#define fEM_R4MC01RSP	BUFFER[1741]	// (R4MC01RSP) Стартовая координата тележки
#define idfEM_R4MC01RSP	489	// (R4MC01RSP) Стартовая координата тележки
#define fEM_R4MV01RC1	BUFFER[1746]	// (R4MV01RC1) Заданная скорость тележки от ИС
#define idfEM_R4MV01RC1	490	// (R4MV01RC1) Заданная скорость тележки от ИС
#define fEM_R4UC08RDU	BUFFER[1751]	// (R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define idfEM_R4UC08RDU	491	// (R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define fEM_R4UC10RIM	BUFFER[1756]	// (R4UC10RIM) Координата верхних механических упоров тележки мм
#define idfEM_R4UC10RIM	492	// (R4UC10RIM) Координата верхних механических упоров тележки мм
#define fEM_R4UC20RIM	BUFFER[1761]	// (R4UC20RIM) Координата нижних механических упоров тележки мм
#define idfEM_R4UC20RIM	493	// (R4UC20RIM) Координата нижних механических упоров тележки мм
#define fEM_R4UC22RIM	BUFFER[1766]	// (R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define idfEM_R4UC22RIM	494	// (R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define fEM_R4US80RDU	BUFFER[1771]	// (R4US80RDU) Тормозной путь тележки (мм)
#define idfEM_R4US80RDU	495	// (R4US80RDU) Тормозной путь тележки (мм)
#define fEM_R4UV80RDU	BUFFER[1776]	// (R4UV80RDU) Номинальная скорость тележки (см/с)
#define idfEM_R4UV80RDU	496	// (R4UV80RDU) Номинальная скорость тележки (см/с)
#define fEM_R5UC01RSP	BUFFER[1781]	// (R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define idfEM_R5UC01RSP	497	// (R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define fEM_R5UL10RIM	BUFFER[1786]	// (R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define idfEM_R5UL10RIM	498	// (R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define fEM_R6UC01RSP	BUFFER[1791]	// (R6UC01RSP) Стартовая координата Кран-балки
#define idfEM_R6UC01RSP	499	// (R6UC01RSP) Стартовая координата Кран-балки
#define fEM_R6UL10RIM	BUFFER[1796]	// (R6UL10RIM) Время полного хода кран-балки сек
#define idfEM_R6UL10RIM	500	// (R6UL10RIM) Время полного хода кран-балки сек
#define fEM_R7UC10RIM	BUFFER[1801]	// (R7UC10RIM) X-координата КНК53М R7IN13 см
#define idfEM_R7UC10RIM	501	// (R7UC10RIM) X-координата КНК53М R7IN13 см
#define fEM_R7UC19RIM	BUFFER[1806]	// (R7UC19RIM) Y-координата СНМ-11 (11) см
#define idfEM_R7UC19RIM	502	// (R7UC19RIM) Y-координата СНМ-11 (11) см
#define fEM_R7UI02RIM	BUFFER[1811]	// (R7UI02RIM) Коэффициент усиления уровня радиации
#define idfEM_R7UI02RIM	503	// (R7UI02RIM) Коэффициент усиления уровня радиации
#define fEM_R7UI71RIM	BUFFER[1816]	// (R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define idfEM_R7UI71RIM	504	// (R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define fEM_R7UI73RIM	BUFFER[1821]	// (R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define idfEM_R7UI73RIM	505	// (R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define fEM_R7UI74RIM	BUFFER[1826]	// (R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define idfEM_R7UI74RIM	506	// (R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define fEM_R7UI75RIM	BUFFER[1831]	// (R7UI75RIM) Множитель к уровню радиации
#define idfEM_R7UI75RIM	507	// (R7UI75RIM) Множитель к уровню радиации
#define fEM_R7UI76RIM	BUFFER[1836]	// (R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define idfEM_R7UI76RIM	508	// (R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define fEM_R7UI77RIM	BUFFER[1841]	// (R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define idfEM_R7UI77RIM	509	// (R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define fEM_R7UL01RIM	BUFFER[1846]	// (R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define idfEM_R7UL01RIM	510	// (R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define fEM_R7UX01RSS	BUFFER[1851]	// (R7UX01RSS) X-координата камеры R7IN11
#define idfEM_R7UX01RSS	511	// (R7UX01RSS) X-координата камеры R7IN11
#define fEM_R7UX02RSS	BUFFER[1856]	// (R7UX02RSS) X-координата камеры R7IN12 (см)
#define idfEM_R7UX02RSS	512	// (R7UX02RSS) X-координата камеры R7IN12 (см)
#define fEM_R7UX04RSS	BUFFER[1861]	// (R7UX04RSS) X-координата камеры R7IN21 (см)
#define idfEM_R7UX04RSS	513	// (R7UX04RSS) X-координата камеры R7IN21 (см)
#define fEM_R7UX05RSS	BUFFER[1866]	// (R7UX05RSS) X-координата камеры R7IN22 (см)
#define idfEM_R7UX05RSS	514	// (R7UX05RSS) X-координата камеры R7IN22 (см)
#define fEM_R7UX06RSS	BUFFER[1871]	// (R7UX06RSS) X-координата камеры R7IN23 (см)
#define idfEM_R7UX06RSS	515	// (R7UX06RSS) X-координата камеры R7IN23 (см)
#define fEM_R7UX07RSS	BUFFER[1876]	// (R7UX07RSS) X-координата камеры R7IN31 (см)
#define idfEM_R7UX07RSS	516	// (R7UX07RSS) X-координата камеры R7IN31 (см)
#define fEM_R7UX08RSS	BUFFER[1881]	// (R7UX08RSS) X-координата камеры R7IN32 (см)
#define idfEM_R7UX08RSS	517	// (R7UX08RSS) X-координата камеры R7IN32 (см)
#define fEM_R7UX09RSS	BUFFER[1886]	// (R7UX09RSS) X-координата камеры R7IN33 (см)
#define idfEM_R7UX09RSS	518	// (R7UX09RSS) X-координата камеры R7IN33 (см)
#define fEM_R7UX10RSS	BUFFER[1891]	// (R7UX10RSS) X-координата камеры R7IN41
#define idfEM_R7UX10RSS	519	// (R7UX10RSS) X-координата камеры R7IN41
#define fEM_R7UX11RSS	BUFFER[1896]	// (R7UX11RSS) X-координата камеры R7IN42
#define idfEM_R7UX11RSS	520	// (R7UX11RSS) X-координата камеры R7IN42
#define fEM_R7UX12RSS	BUFFER[1901]	// (R7UX12RSS) X-координата камеры R7IN43
#define idfEM_R7UX12RSS	521	// (R7UX12RSS) X-координата камеры R7IN43
#define fEM_R7UX13RSS	BUFFER[1906]	// (R7UX13RSS) X-координата камеры R7IN51
#define idfEM_R7UX13RSS	522	// (R7UX13RSS) X-координата камеры R7IN51
#define fEM_R7UX14RSS	BUFFER[1911]	// (R7UX14RSS) X-координата камеры R7IN52
#define idfEM_R7UX14RSS	523	// (R7UX14RSS) X-координата камеры R7IN52
#define fEM_R7UX15RSS	BUFFER[1916]	// (R7UX15RSS) X-координата камеры R7IN53
#define idfEM_R7UX15RSS	524	// (R7UX15RSS) X-координата камеры R7IN53
#define fEM_R7UX16RSS	BUFFER[1921]	// (R7UX16RSS) Величина сигнала СНМ11 в БЗ
#define idfEM_R7UX16RSS	525	// (R7UX16RSS) Величина сигнала СНМ11 в БЗ
#define fEM_R7UY00RSS	BUFFER[1926]	// (R7UY00RSS) Y-координата АЗ1 см
#define idfEM_R7UY00RSS	526	// (R7UY00RSS) Y-координата АЗ1 см
#define fEM_R7UY01RSS	BUFFER[1931]	// (R7UY01RSS) Y-координата камеры R7IN11
#define idfEM_R7UY01RSS	527	// (R7UY01RSS) Y-координата камеры R7IN11
#define fEM_R7UY02RSS	BUFFER[1936]	// (R7UY02RSS) Y-координата камеры R7IN12 (см)
#define idfEM_R7UY02RSS	528	// (R7UY02RSS) Y-координата камеры R7IN12 (см)
#define fEM_R7UY04RSS	BUFFER[1941]	// (R7UY04RSS) Y-координата камеры R7IN21 (см)
#define idfEM_R7UY04RSS	529	// (R7UY04RSS) Y-координата камеры R7IN21 (см)
#define fEM_R7UY05RSS	BUFFER[1946]	// (R7UY05RSS) Y-координата камеры R7IN22 (см)
#define idfEM_R7UY05RSS	530	// (R7UY05RSS) Y-координата камеры R7IN22 (см)
#define fEM_R7UY06RSS	BUFFER[1951]	// (R7UY06RSS) Y-координата камеры R7IN23 (см)
#define idfEM_R7UY06RSS	531	// (R7UY06RSS) Y-координата камеры R7IN23 (см)
#define fEM_R7UY07RSS	BUFFER[1956]	// (R7UY07RSS) Y-координата камеры R7IN31 (см)
#define idfEM_R7UY07RSS	532	// (R7UY07RSS) Y-координата камеры R7IN31 (см)
#define fEM_R7UY08RSS	BUFFER[1961]	// (R7UY08RSS) Y-координата камеры R7IN32 (см)
#define idfEM_R7UY08RSS	533	// (R7UY08RSS) Y-координата камеры R7IN32 (см)
#define fEM_R7UY09RSS	BUFFER[1966]	// (R7UY09RSS) Y-координата камеры R7IN33 (см)
#define idfEM_R7UY09RSS	534	// (R7UY09RSS) Y-координата камеры R7IN33 (см)
#define fEM_R7UY10RSS	BUFFER[1971]	// (R7UY10RSS) Y-координата камеры R7IN41
#define idfEM_R7UY10RSS	535	// (R7UY10RSS) Y-координата камеры R7IN41
#define fEM_R7UY11RSS	BUFFER[1976]	// (R7UY11RSS) Y-координата камеры R7IN42
#define idfEM_R7UY11RSS	536	// (R7UY11RSS) Y-координата камеры R7IN42
#define fEM_R7UY12RSS	BUFFER[1981]	// (R7UY12RSS) Y-координата камеры R7IN43
#define idfEM_R7UY12RSS	537	// (R7UY12RSS) Y-координата камеры R7IN43
#define fEM_R7UY13RSS	BUFFER[1986]	// (R7UY13RSS) Y-координата камеры R7IN51
#define idfEM_R7UY13RSS	538	// (R7UY13RSS) Y-координата камеры R7IN51
#define fEM_R7UY14RSS	BUFFER[1991]	// (R7UY14RSS) Y-координата камеры R7IN52
#define idfEM_R7UY14RSS	539	// (R7UY14RSS) Y-координата камеры R7IN52
#define fEM_R7UY15RSS	BUFFER[1996]	// (R7UY15RSS) Y-координата камеры R7IN53
#define idfEM_R7UY15RSS	540	// (R7UY15RSS) Y-координата камеры R7IN53
#define iEM_TERA0MT01RIM	BUFFER[2001]	// (TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define idiEM_TERA0MT01RIM	541	// (TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define iEM_TERA0VP81LIM	BUFFER[2004]	// (TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define idiEM_TERA0VP81LIM	542	// (TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define iEM_TERA1IE03LDU	BUFFER[2007]	// (TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define idiEM_TERA1IE03LDU	543	// (TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define iEM_TERA1IE04LDU	BUFFER[2010]	// (TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define idiEM_TERA1IE04LDU	544	// (TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define iEM_TERA1SC01RIM	BUFFER[2013]	// (TERA1SC01RIM) Искажение: Координата штока ББ1
#define idiEM_TERA1SC01RIM	545	// (TERA1SC01RIM) Искажение: Координата штока ББ1
#define iEM_TERA1SS11LIM	BUFFER[2016]	// (TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define idiEM_TERA1SS11LIM	546	// (TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define iEM_TERA1SS12LIM	BUFFER[2019]	// (TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define idiEM_TERA1SS12LIM	547	// (TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define iEM_TERA1SS21LIM	BUFFER[2022]	// (TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define idiEM_TERA1SS21LIM	548	// (TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define iEM_TERA1VP81LIM	BUFFER[2025]	// (TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define idiEM_TERA1VP81LIM	549	// (TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define iEM_TERA2SC01RIM	BUFFER[2028]	// (TERA2SC01RIM) Искажение: Координата штока РБ1
#define idiEM_TERA2SC01RIM	550	// (TERA2SC01RIM) Искажение: Координата штока РБ1
#define iEM_TERA2SP01RIM	BUFFER[2031]	// (TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define idiEM_TERA2SP01RIM	551	// (TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define iEM_TERA2SS11LIM	BUFFER[2034]	// (TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define idiEM_TERA2SS11LIM	552	// (TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define iEM_TERA2SS12LIM	BUFFER[2037]	// (TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define idiEM_TERA2SS12LIM	553	// (TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define iEM_TERA2SS21LIM	BUFFER[2040]	// (TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define idiEM_TERA2SS21LIM	554	// (TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define iEM_TERA2SS33LIM	BUFFER[2043]	// (TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define idiEM_TERA2SS33LIM	555	// (TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define iEM_TERA2VP82LIM	BUFFER[2046]	// (TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define idiEM_TERA2VP82LIM	556	// (TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define iEM_TERA3SC01RIM	BUFFER[2049]	// (TERA3SC01RIM) Искажение: Координата штока ИС1
#define idiEM_TERA3SC01RIM	557	// (TERA3SC01RIM) Искажение: Координата штока ИС1
#define iEM_TERA3SP02RIM	BUFFER[2052]	// (TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define idiEM_TERA3SP02RIM	558	// (TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define iEM_TERA3SS11LIM	BUFFER[2055]	// (TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define idiEM_TERA3SS11LIM	559	// (TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define iEM_TERA3SS21LIM	BUFFER[2058]	// (TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define idiEM_TERA3SS21LIM	560	// (TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define iEM_TERA3SS22LIM	BUFFER[2061]	// (TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define idiEM_TERA3SS22LIM	561	// (TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define iEM_TERA3SS31LIM	BUFFER[2064]	// (TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define idiEM_TERA3SS31LIM	562	// (TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define iEM_TERA3SS33LIM	BUFFER[2067]	// (TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define idiEM_TERA3SS33LIM	563	// (TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define iEM_TERA3VP81LIM	BUFFER[2070]	// (TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define idiEM_TERA3VP81LIM	564	// (TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define iEM_TERA4SS11LIM	BUFFER[2073]	// (TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define idiEM_TERA4SS11LIM	565	// (TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define iEM_TERA4SS21LIM	BUFFER[2076]	// (TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define idiEM_TERA4SS21LIM	566	// (TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define iEM_TERA4VP82LIM	BUFFER[2079]	// (TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define idiEM_TERA4VP82LIM	567	// (TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define iEM_TERA5SS11LIM	BUFFER[2082]	// (TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define idiEM_TERA5SS11LIM	568	// (TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define iEM_TERA5SS21LIM	BUFFER[2085]	// (TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define idiEM_TERA5SS21LIM	569	// (TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define iEM_TERA5VS12LIM	BUFFER[2088]	// (TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define idiEM_TERA5VS12LIM	570	// (TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define iEM_TERA5VS22LIM	BUFFER[2091]	// (TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define idiEM_TERA5VS22LIM	571	// (TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define iEM_TERA6MS11LIM	BUFFER[2094]	// (TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define idiEM_TERA6MS11LIM	572	// (TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define iEM_TERA6SS21LIM	BUFFER[2097]	// (TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define idiEM_TERA6SS21LIM	573	// (TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define iEM_TERA6VS12LIM	BUFFER[2100]	// (TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define idiEM_TERA6VS12LIM	574	// (TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define iEM_TERA6VS22LIM	BUFFER[2103]	// (TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define idiEM_TERA6VS22LIM	575	// (TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define iEM_TERA7MS31LIM	BUFFER[2106]	// (TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define idiEM_TERA7MS31LIM	576	// (TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define iEM_TERA8SC01RIM	BUFFER[2109]	// (TERA8SC01RIM) Искажение: Координата ДС2
#define idiEM_TERA8SC01RIM	577	// (TERA8SC01RIM) Искажение: Координата ДС2
#define iEM_TERA8SS12LIM	BUFFER[2112]	// (TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define idiEM_TERA8SS12LIM	578	// (TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define iEM_TERA8SS22LIM	BUFFER[2115]	// (TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define idiEM_TERA8SS22LIM	579	// (TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define iEM_TERA9SS11LIM	BUFFER[2118]	// (TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define idiEM_TERA9SS11LIM	580	// (TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define iEM_TERA9SS21LIM	BUFFER[2121]	// (TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define idiEM_TERA9SS21LIM	581	// (TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define iEM_TERB0MT01RIM	BUFFER[2124]	// (TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define idiEM_TERB0MT01RIM	582	// (TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define iEM_TERB0VP81LIM	BUFFER[2127]	// (TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define idiEM_TERB0VP81LIM	583	// (TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define iEM_TERB1IE03LDU	BUFFER[2130]	// (TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define idiEM_TERB1IE03LDU	584	// (TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define iEM_TERB1IE04LDU	BUFFER[2133]	// (TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define idiEM_TERB1IE04LDU	585	// (TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define iEM_TERB1MC01RIM	BUFFER[2136]	// (TERB1MC01RIM) Искажение: Координата штока ББ2
#define idiEM_TERB1MC01RIM	586	// (TERB1MC01RIM) Искажение: Координата штока ББ2
#define iEM_TERB1SS11LIM	BUFFER[2139]	// (TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define idiEM_TERB1SS11LIM	587	// (TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define iEM_TERB1SS12LIM	BUFFER[2142]	// (TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define idiEM_TERB1SS12LIM	588	// (TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define iEM_TERB1SS21LIM	BUFFER[2145]	// (TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define idiEM_TERB1SS21LIM	589	// (TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define iEM_TERB1VP81LIM	BUFFER[2148]	// (TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define idiEM_TERB1VP81LIM	590	// (TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define iEM_TERB2SC01RIM	BUFFER[2151]	// (TERB2SC01RIM) Искажение: Координата штока РБ2
#define idiEM_TERB2SC01RIM	591	// (TERB2SC01RIM) Искажение: Координата штока РБ2
#define iEM_TERB2SP01RIM	BUFFER[2154]	// (TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define idiEM_TERB2SP01RIM	592	// (TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define iEM_TERB2SS11LIM	BUFFER[2157]	// (TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define idiEM_TERB2SS11LIM	593	// (TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define iEM_TERB2SS12LIM	BUFFER[2160]	// (TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define idiEM_TERB2SS12LIM	594	// (TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define iEM_TERB2SS21LIM	BUFFER[2163]	// (TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define idiEM_TERB2SS21LIM	595	// (TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define iEM_TERB2SS33LIM	BUFFER[2166]	// (TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define idiEM_TERB2SS33LIM	596	// (TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define iEM_TERB3SC01RIM	BUFFER[2169]	// (TERB3SC01RIM) Искажение: Координата штока ИС2
#define idiEM_TERB3SC01RIM	597	// (TERB3SC01RIM) Искажение: Координата штока ИС2
#define iEM_TERB3SP02RIM	BUFFER[2172]	// (TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define idiEM_TERB3SP02RIM	598	// (TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define iEM_TERB3SS11LIM	BUFFER[2175]	// (TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define idiEM_TERB3SS11LIM	599	// (TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define iEM_TERB3SS21LIM	BUFFER[2178]	// (TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define idiEM_TERB3SS21LIM	600	// (TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define iEM_TERB3SS22LIM	BUFFER[2181]	// (TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define idiEM_TERB3SS22LIM	601	// (TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define iEM_TERB3SS31LIM	BUFFER[2184]	// (TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define idiEM_TERB3SS31LIM	602	// (TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define iEM_TERB3SS33LIM	BUFFER[2187]	// (TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idiEM_TERB3SS33LIM	603	// (TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define iEM_TERB4SS11LIM	BUFFER[2190]	// (TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define idiEM_TERB4SS11LIM	604	// (TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define iEM_TERB4SS21LIM	BUFFER[2193]	// (TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define idiEM_TERB4SS21LIM	605	// (TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define iEM_TERB5SS11LIM	BUFFER[2196]	// (TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define idiEM_TERB5SS11LIM	606	// (TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define iEM_TERB5SS21LIM	BUFFER[2199]	// (TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define idiEM_TERB5SS21LIM	607	// (TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define iEM_TERB5VS12LIM	BUFFER[2202]	// (TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define idiEM_TERB5VS12LIM	608	// (TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define iEM_TERB5VS22LIM	BUFFER[2205]	// (TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define idiEM_TERB5VS22LIM	609	// (TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define iEM_TERB6SS11LIM	BUFFER[2208]	// (TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define idiEM_TERB6SS11LIM	610	// (TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define iEM_TERB6SS21LIM	BUFFER[2211]	// (TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define idiEM_TERB6SS21LIM	611	// (TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define iEM_TERB6VS12LIM	BUFFER[2214]	// (TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define idiEM_TERB6VS12LIM	612	// (TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define iEM_TERB6VS22LIM	BUFFER[2217]	// (TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define idiEM_TERB6VS22LIM	613	// (TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define iEM_TERB7MS31LIM	BUFFER[2220]	// (TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define idiEM_TERB7MS31LIM	614	// (TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define iEM_TERB8SC01RIM	BUFFER[2223]	// (TERB8SC01RIM) Искажение: Координата АЗ2
#define idiEM_TERB8SC01RIM	615	// (TERB8SC01RIM) Искажение: Координата АЗ2
#define iEM_TERB8SS12LIM	BUFFER[2226]	// (TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define idiEM_TERB8SS12LIM	616	// (TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define iEM_TERB8SS22LIM	BUFFER[2229]	// (TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define idiEM_TERB8SS22LIM	617	// (TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define iEM_TERB9SS11LIM	BUFFER[2232]	// (TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define idiEM_TERB9SS11LIM	618	// (TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define iEM_TERB9SS21LIM	BUFFER[2235]	// (TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define idiEM_TERB9SS21LIM	619	// (TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define iEM_TERBB1	BUFFER[2238]	// (TERBB1) Неисправности  ББ1
#define idiEM_TERBB1	620	// (TERBB1) Неисправности  ББ1
#define iEM_TERBB2	BUFFER[2241]	// (TERBB2) Неисправности  ББ2
#define idiEM_TERBB2	621	// (TERBB2) Неисправности  ББ2
#define iEM_TERBZ1	BUFFER[2244]	// (TERBZ1) Неисправности БЗ1
#define idiEM_TERBZ1	622	// (TERBZ1) Неисправности БЗ1
#define iEM_TERBZ2	BUFFER[2247]	// (TERBZ2) Неисправности БЗ2
#define idiEM_TERBZ2	623	// (TERBZ2) Неисправности БЗ2
#define iEM_TERDS2	BUFFER[2250]	// (TERDS2) Неисправности ДС2 от ИС
#define idiEM_TERDS2	624	// (TERDS2) Неисправности ДС2 от ИС
#define iEM_TERIS1	BUFFER[2253]	// (TERIS1) Неисправности  ИС1
#define idiEM_TERIS1	625	// (TERIS1) Неисправности  ИС1
#define iEM_TERIS2	BUFFER[2256]	// (TERIS2) Неисправности  ИС2
#define idiEM_TERIS2	626	// (TERIS2) Неисправности  ИС2
#define iEM_TERMAZ2	BUFFER[2259]	// (TERMAZ2) Неисправности АЗ2 от ИС
#define idiEM_TERMAZ2	627	// (TERMAZ2) Неисправности АЗ2 от ИС
#define iEM_TERMDZ1	BUFFER[2262]	// (TERMDZ1) Неисправности МДЗ1
#define idiEM_TERMDZ1	628	// (TERMDZ1) Неисправности МДЗ1
#define iEM_TERMDZ2	BUFFER[2265]	// (TERMDZ2) Неисправности МДЗ2
#define idiEM_TERMDZ2	629	// (TERMDZ2) Неисправности МДЗ2
#define iEM_TERNL1	BUFFER[2268]	// (TERNL1) Неисправности НЛ1
#define idiEM_TERNL1	630	// (TERNL1) Неисправности НЛ1
#define iEM_TERNL2	BUFFER[2271]	// (TERNL2) Неисправности НЛ2
#define idiEM_TERNL2	631	// (TERNL2) Неисправности НЛ2
#define iEM_TERR0VP81LIM	BUFFER[2274]	// (TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define idiEM_TERR0VP81LIM	632	// (TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define iEM_TERR1SS11LIM	BUFFER[2277]	// (TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define idiEM_TERR1SS11LIM	633	// (TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define iEM_TERR1SS21LIM	BUFFER[2280]	// (TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define idiEM_TERR1SS21LIM	634	// (TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define iEM_TERR1VS12LIM	BUFFER[2283]	// (TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define idiEM_TERR1VS12LIM	635	// (TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define iEM_TERR1VS22LIM	BUFFER[2286]	// (TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define idiEM_TERR1VS22LIM	636	// (TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define iEM_TERR2SS11LIM	BUFFER[2289]	// (TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define idiEM_TERR2SS11LIM	637	// (TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define iEM_TERR2SS21LIM	BUFFER[2292]	// (TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define idiEM_TERR2SS21LIM	638	// (TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define iEM_TERR2VS12LIM	BUFFER[2295]	// (TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define idiEM_TERR2VS12LIM	639	// (TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define iEM_TERR2VS22LIM	BUFFER[2298]	// (TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define idiEM_TERR2VS22LIM	640	// (TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define iEM_TERR3SS11LIM	BUFFER[2301]	// (TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define idiEM_TERR3SS11LIM	641	// (TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define iEM_TERR3SS21LIM	BUFFER[2304]	// (TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define idiEM_TERR3SS21LIM	642	// (TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define iEM_TERR4MS21LIM	BUFFER[2307]	// (TERR4MS21LIM) Искажение: Приход на НУ тележки
#define idiEM_TERR4MS21LIM	643	// (TERR4MS21LIM) Искажение: Приход на НУ тележки
#define iEM_TERR4SS11LIM	BUFFER[2310]	// (TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define idiEM_TERR4SS11LIM	644	// (TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define iEM_TERR4SS12LIM	BUFFER[2313]	// (TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define idiEM_TERR4SS12LIM	645	// (TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define iEM_TERR4SS22LIM	BUFFER[2316]	// (TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define idiEM_TERR4SS22LIM	646	// (TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define iEM_TERR4VS12LDU	BUFFER[2319]	// (TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS12LDU	647	// (TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define iEM_TERR4VS22LDU	BUFFER[2322]	// (TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS22LDU	648	// (TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define iEM_TERR5SS11LIM	BUFFER[2325]	// (TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define idiEM_TERR5SS11LIM	649	// (TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define iEM_TERR5SS21LIM	BUFFER[2328]	// (TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define idiEM_TERR5SS21LIM	650	// (TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define iEM_TERR6IS62LIM	BUFFER[2331]	// (TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define idiEM_TERR6IS62LIM	651	// (TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define iEM_TERR6IS64LIM	BUFFER[2334]	// (TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define idiEM_TERR6IS64LIM	652	// (TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define iEM_TERR6IS66LIM	BUFFER[2337]	// (TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idiEM_TERR6IS66LIM	653	// (TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define iEM_TERR6SS21LIM	BUFFER[2340]	// (TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define idiEM_TERR6SS21LIM	654	// (TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define iEM_TERR7SI74RIM	BUFFER[2343]	// (TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define idiEM_TERR7SI74RIM	655	// (TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define iEM_TERR8SS11LIM	BUFFER[2346]	// (TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define idiEM_TERR8SS11LIM	656	// (TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define iEM_TERRB1	BUFFER[2349]	// (TERRB1) Неисправности  РБ1
#define idiEM_TERRB1	657	// (TERRB1) Неисправности  РБ1
#define iEM_TERRB2	BUFFER[2352]	// (TERRB2) Неисправности  РБ2
#define idiEM_TERRB2	658	// (TERRB2) Неисправности  РБ2
#define iEM_TERTLG	BUFFER[2355]	// (TERTLG) Неисправности  тележки от ИС
#define idiEM_TERTLG	659	// (TERTLG) Неисправности  тележки от ИС
#define internal1_m1012_Out10	BUFFER[2358]	// (internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1012_Out10	660	// (internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1013_Out10	BUFFER[2360]	// (internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1013_Out10	661	// (internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1014_Out10	BUFFER[2362]	// (internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1014_Out10	662	// (internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1015_Out10	BUFFER[2364]	// (internal1_m1015_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1015_Out10	663	// (internal1_m1015_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1016_Out10	BUFFER[2366]	// (internal1_m1016_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1016_Out10	664	// (internal1_m1016_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1017_Out10	BUFFER[2368]	// (internal1_m1017_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1017_Out10	665	// (internal1_m1017_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1018_Out10	BUFFER[2370]	// (internal1_m1018_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1018_Out10	666	// (internal1_m1018_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1032_Out10	BUFFER[2372]	// (internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1032_Out10	667	// (internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1033_Out10	BUFFER[2374]	// (internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1033_Out10	668	// (internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1034_Out10	BUFFER[2376]	// (internal1_m1034_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1034_Out10	669	// (internal1_m1034_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1035_Out10	BUFFER[2378]	// (internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1035_Out10	670	// (internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1036_Out10	BUFFER[2380]	// (internal1_m1036_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1036_Out10	671	// (internal1_m1036_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1037_Out10	BUFFER[2382]	// (internal1_m1037_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1037_Out10	672	// (internal1_m1037_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m103_MyFirstEnterFlag	BUFFER[2384]	// (internal1_m103_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m103_MyFirstEnterFlag	673	// (internal1_m103_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m103_Pav0	BUFFER[2386]	// (internal1_m103_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m103_Pav0	674	// (internal1_m103_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m103_Ppv0	BUFFER[2388]	// (internal1_m103_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m103_Ppv0	675	// (internal1_m103_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m103_RA00	BUFFER[2390]	// (internal1_m103_RA00) RA00 - последнее задание вперед
#define idinternal1_m103_RA00	676	// (internal1_m103_RA00) RA00 - последнее задание вперед
#define internal1_m103_RA10	BUFFER[2392]	// (internal1_m103_RA10) RA10 - последнее задание назад
#define idinternal1_m103_RA10	677	// (internal1_m103_RA10) RA10 - последнее задание назад
#define internal1_m103_RA30	BUFFER[2394]	// (internal1_m103_RA30)  RA30 - разрешение движения
#define idinternal1_m103_RA30	678	// (internal1_m103_RA30)  RA30 - разрешение движения
#define internal1_m103_RA50	BUFFER[2396]	// (internal1_m103_RA50) Ra50 - последнее задание скорости
#define idinternal1_m103_RA50	679	// (internal1_m103_RA50) Ra50 - последнее задание скорости
#define internal1_m103_RV00	BUFFER[2398]	// (internal1_m103_RV00) V0 - текущая скорость ОРР
#define idinternal1_m103_RV00	680	// (internal1_m103_RV00) V0 - текущая скорость ОРР
#define internal1_m103_Sh00	BUFFER[2403]	// (internal1_m103_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m103_Sh00	681	// (internal1_m103_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m103_ShV00	BUFFER[2408]	// (internal1_m103_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m103_ShV00	682	// (internal1_m103_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m103_X00	BUFFER[2413]	// (internal1_m103_X00) X0 - текущая координата ОРР
#define idinternal1_m103_X00	683	// (internal1_m103_X00) X0 - текущая координата ОРР
#define internal1_m103_Zav0	BUFFER[2418]	// (internal1_m103_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m103_Zav0	684	// (internal1_m103_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m103_flp	BUFFER[2420]	// (internal1_m103_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m103_flp	685	// (internal1_m103_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m103_fls	BUFFER[2422]	// (internal1_m103_fls)  fls - флаг одношагового режима
#define idinternal1_m103_fls	686	// (internal1_m103_fls)  fls - флаг одношагового режима
#define internal1_m134_MyFirstEnterFlag	BUFFER[2424]	// (internal1_m134_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m134_MyFirstEnterFlag	687	// (internal1_m134_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m134_Pav0	BUFFER[2426]	// (internal1_m134_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m134_Pav0	688	// (internal1_m134_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m134_Ppv0	BUFFER[2428]	// (internal1_m134_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m134_Ppv0	689	// (internal1_m134_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m134_RA00	BUFFER[2430]	// (internal1_m134_RA00) RA00 - последнее задание вперед
#define idinternal1_m134_RA00	690	// (internal1_m134_RA00) RA00 - последнее задание вперед
#define internal1_m134_RA10	BUFFER[2432]	// (internal1_m134_RA10) RA10 - последнее задание назад
#define idinternal1_m134_RA10	691	// (internal1_m134_RA10) RA10 - последнее задание назад
#define internal1_m134_RA30	BUFFER[2434]	// (internal1_m134_RA30)  RA30 - разрешение движения
#define idinternal1_m134_RA30	692	// (internal1_m134_RA30)  RA30 - разрешение движения
#define internal1_m134_RA50	BUFFER[2436]	// (internal1_m134_RA50) Ra50 - последнее задание скорости
#define idinternal1_m134_RA50	693	// (internal1_m134_RA50) Ra50 - последнее задание скорости
#define internal1_m134_RV00	BUFFER[2438]	// (internal1_m134_RV00) V0 - текущая скорость ОРР
#define idinternal1_m134_RV00	694	// (internal1_m134_RV00) V0 - текущая скорость ОРР
#define internal1_m134_Sh00	BUFFER[2443]	// (internal1_m134_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m134_Sh00	695	// (internal1_m134_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m134_ShV00	BUFFER[2448]	// (internal1_m134_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m134_ShV00	696	// (internal1_m134_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m134_X00	BUFFER[2453]	// (internal1_m134_X00) X0 - текущая координата ОРР
#define idinternal1_m134_X00	697	// (internal1_m134_X00) X0 - текущая координата ОРР
#define internal1_m134_Zav0	BUFFER[2458]	// (internal1_m134_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m134_Zav0	698	// (internal1_m134_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m134_flp	BUFFER[2460]	// (internal1_m134_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m134_flp	699	// (internal1_m134_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m134_fls	BUFFER[2462]	// (internal1_m134_fls)  fls - флаг одношагового режима
#define idinternal1_m134_fls	700	// (internal1_m134_fls)  fls - флаг одношагового режима
#define internal1_m14_C1	BUFFER[2464]	// (internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m14_C1	701	// (internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m14_C2	BUFFER[2469]	// (internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m14_C2	702	// (internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m14_C3	BUFFER[2474]	// (internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m14_C3	703	// (internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m14_C4	BUFFER[2479]	// (internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m14_C4	704	// (internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m14_C5	BUFFER[2484]	// (internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m14_C5	705	// (internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m14_C6	BUFFER[2489]	// (internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m14_C6	706	// (internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m14_ImpINI0	BUFFER[2494]	// (internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m14_ImpINI0	707	// (internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m14_MyFirstEnterFlag	BUFFER[2496]	// (internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m14_MyFirstEnterFlag	708	// (internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m14_N00	BUFFER[2498]	// (internal1_m14_N00) N00 - Текущая концентрация нейтронов
#define idinternal1_m14_N00	709	// (internal1_m14_N00) N00 - Текущая концентрация нейтронов
#define internal1_m14_N20	BUFFER[2503]	// (internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m14_N20	710	// (internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m14_R00	BUFFER[2508]	// (internal1_m14_R00) R00 - Текущая реактивность
#define idinternal1_m14_R00	711	// (internal1_m14_R00) R00 - Текущая реактивность
#define internal1_m14_T00	BUFFER[2513]	// (internal1_m14_T00) T00 - Текущая температура
#define idinternal1_m14_T00	712	// (internal1_m14_T00) T00 - Текущая температура
#define internal1_m151_Out10	BUFFER[2518]	// (internal1_m151_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m151_Out10	713	// (internal1_m151_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m152_Out10	BUFFER[2520]	// (internal1_m152_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m152_Out10	714	// (internal1_m152_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m176_x0	BUFFER[2522]	// (internal1_m176_x0) x0 - значение входного параметра на предыдущем шаге
#define idinternal1_m176_x0	715	// (internal1_m176_x0) x0 - значение входного параметра на предыдущем шаге
#define internal1_m186_C1	BUFFER[2527]	// (internal1_m186_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m186_C1	716	// (internal1_m186_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m186_C2	BUFFER[2532]	// (internal1_m186_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m186_C2	717	// (internal1_m186_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m186_C3	BUFFER[2537]	// (internal1_m186_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m186_C3	718	// (internal1_m186_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m186_C4	BUFFER[2542]	// (internal1_m186_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m186_C4	719	// (internal1_m186_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m186_C5	BUFFER[2547]	// (internal1_m186_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m186_C5	720	// (internal1_m186_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m186_C6	BUFFER[2552]	// (internal1_m186_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m186_C6	721	// (internal1_m186_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m186_ImpINI0	BUFFER[2557]	// (internal1_m186_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m186_ImpINI0	722	// (internal1_m186_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m186_MyFirstEnterFlag	BUFFER[2559]	// (internal1_m186_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m186_MyFirstEnterFlag	723	// (internal1_m186_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m186_N00	BUFFER[2561]	// (internal1_m186_N00) N00 - Текущая концентрация нейтронов
#define idinternal1_m186_N00	724	// (internal1_m186_N00) N00 - Текущая концентрация нейтронов
#define internal1_m186_N20	BUFFER[2566]	// (internal1_m186_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m186_N20	725	// (internal1_m186_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m186_R00	BUFFER[2571]	// (internal1_m186_R00) R00 - Текущая реактивность
#define idinternal1_m186_R00	726	// (internal1_m186_R00) R00 - Текущая реактивность
#define internal1_m186_T00	BUFFER[2576]	// (internal1_m186_T00) T00 - Текущая температура
#define idinternal1_m186_T00	727	// (internal1_m186_T00) T00 - Текущая температура
#define internal1_m211_Out10	BUFFER[2581]	// (internal1_m211_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m211_Out10	728	// (internal1_m211_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m228_Out10	BUFFER[2583]	// (internal1_m228_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m228_Out10	729	// (internal1_m228_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m232_MyFirstEnterFlag	BUFFER[2585]	// (internal1_m232_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m232_MyFirstEnterFlag	730	// (internal1_m232_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m232_Pav0	BUFFER[2587]	// (internal1_m232_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m232_Pav0	731	// (internal1_m232_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m232_Ppv0	BUFFER[2589]	// (internal1_m232_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m232_Ppv0	732	// (internal1_m232_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m232_RA00	BUFFER[2591]	// (internal1_m232_RA00) RA00 - последнее задание вперед
#define idinternal1_m232_RA00	733	// (internal1_m232_RA00) RA00 - последнее задание вперед
#define internal1_m232_RA10	BUFFER[2593]	// (internal1_m232_RA10) RA10 - последнее задание назад
#define idinternal1_m232_RA10	734	// (internal1_m232_RA10) RA10 - последнее задание назад
#define internal1_m232_RA30	BUFFER[2595]	// (internal1_m232_RA30)  RA30 - разрешение движения
#define idinternal1_m232_RA30	735	// (internal1_m232_RA30)  RA30 - разрешение движения
#define internal1_m232_RA50	BUFFER[2597]	// (internal1_m232_RA50) Ra50 - последнее задание скорости
#define idinternal1_m232_RA50	736	// (internal1_m232_RA50) Ra50 - последнее задание скорости
#define internal1_m232_RV00	BUFFER[2599]	// (internal1_m232_RV00) V0 - текущая скорость ОРР
#define idinternal1_m232_RV00	737	// (internal1_m232_RV00) V0 - текущая скорость ОРР
#define internal1_m232_Sh00	BUFFER[2604]	// (internal1_m232_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m232_Sh00	738	// (internal1_m232_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m232_ShV00	BUFFER[2609]	// (internal1_m232_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m232_ShV00	739	// (internal1_m232_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m232_X00	BUFFER[2614]	// (internal1_m232_X00) X0 - текущая координата ОРР
#define idinternal1_m232_X00	740	// (internal1_m232_X00) X0 - текущая координата ОРР
#define internal1_m232_Zav0	BUFFER[2619]	// (internal1_m232_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m232_Zav0	741	// (internal1_m232_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m232_flp	BUFFER[2621]	// (internal1_m232_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m232_flp	742	// (internal1_m232_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m232_fls	BUFFER[2623]	// (internal1_m232_fls)  fls - флаг одношагового режима
#define idinternal1_m232_fls	743	// (internal1_m232_fls)  fls - флаг одношагового режима
#define internal1_m267_MyFirstEnterFlag	BUFFER[2625]	// (internal1_m267_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m267_MyFirstEnterFlag	744	// (internal1_m267_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m267_Pav0	BUFFER[2627]	// (internal1_m267_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m267_Pav0	745	// (internal1_m267_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m267_Ppv0	BUFFER[2629]	// (internal1_m267_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m267_Ppv0	746	// (internal1_m267_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m267_RA00	BUFFER[2631]	// (internal1_m267_RA00) RA00 - последнее задание вперед
#define idinternal1_m267_RA00	747	// (internal1_m267_RA00) RA00 - последнее задание вперед
#define internal1_m267_RA10	BUFFER[2633]	// (internal1_m267_RA10) RA10 - последнее задание назад
#define idinternal1_m267_RA10	748	// (internal1_m267_RA10) RA10 - последнее задание назад
#define internal1_m267_RA30	BUFFER[2635]	// (internal1_m267_RA30)  RA30 - разрешение движения
#define idinternal1_m267_RA30	749	// (internal1_m267_RA30)  RA30 - разрешение движения
#define internal1_m267_RA50	BUFFER[2637]	// (internal1_m267_RA50) Ra50 - последнее задание скорости
#define idinternal1_m267_RA50	750	// (internal1_m267_RA50) Ra50 - последнее задание скорости
#define internal1_m267_RV00	BUFFER[2639]	// (internal1_m267_RV00) V0 - текущая скорость ОРР
#define idinternal1_m267_RV00	751	// (internal1_m267_RV00) V0 - текущая скорость ОРР
#define internal1_m267_Sh00	BUFFER[2644]	// (internal1_m267_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m267_Sh00	752	// (internal1_m267_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m267_ShV00	BUFFER[2649]	// (internal1_m267_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m267_ShV00	753	// (internal1_m267_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m267_X00	BUFFER[2654]	// (internal1_m267_X00) X0 - текущая координата ОРР
#define idinternal1_m267_X00	754	// (internal1_m267_X00) X0 - текущая координата ОРР
#define internal1_m267_Zav0	BUFFER[2659]	// (internal1_m267_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m267_Zav0	755	// (internal1_m267_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m267_flp	BUFFER[2661]	// (internal1_m267_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m267_flp	756	// (internal1_m267_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m267_fls	BUFFER[2663]	// (internal1_m267_fls)  fls - флаг одношагового режима
#define idinternal1_m267_fls	757	// (internal1_m267_fls)  fls - флаг одношагового режима
#define internal1_m300_MyFirstEnterFlag	BUFFER[2665]	// (internal1_m300_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m300_MyFirstEnterFlag	758	// (internal1_m300_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m300_Pav0	BUFFER[2667]	// (internal1_m300_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m300_Pav0	759	// (internal1_m300_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m300_Ppv0	BUFFER[2669]	// (internal1_m300_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m300_Ppv0	760	// (internal1_m300_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m300_RA00	BUFFER[2671]	// (internal1_m300_RA00) RA00 - последнее задание вперед
#define idinternal1_m300_RA00	761	// (internal1_m300_RA00) RA00 - последнее задание вперед
#define internal1_m300_RA10	BUFFER[2673]	// (internal1_m300_RA10) RA10 - последнее задание назад
#define idinternal1_m300_RA10	762	// (internal1_m300_RA10) RA10 - последнее задание назад
#define internal1_m300_RA30	BUFFER[2675]	// (internal1_m300_RA30)  RA30 - разрешение движения
#define idinternal1_m300_RA30	763	// (internal1_m300_RA30)  RA30 - разрешение движения
#define internal1_m300_RA50	BUFFER[2677]	// (internal1_m300_RA50) Ra50 - последнее задание скорости
#define idinternal1_m300_RA50	764	// (internal1_m300_RA50) Ra50 - последнее задание скорости
#define internal1_m300_RV00	BUFFER[2679]	// (internal1_m300_RV00) V0 - текущая скорость ОРР
#define idinternal1_m300_RV00	765	// (internal1_m300_RV00) V0 - текущая скорость ОРР
#define internal1_m300_Sh00	BUFFER[2684]	// (internal1_m300_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m300_Sh00	766	// (internal1_m300_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m300_ShV00	BUFFER[2689]	// (internal1_m300_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m300_ShV00	767	// (internal1_m300_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m300_X00	BUFFER[2694]	// (internal1_m300_X00) X0 - текущая координата ОРР
#define idinternal1_m300_X00	768	// (internal1_m300_X00) X0 - текущая координата ОРР
#define internal1_m300_Zav0	BUFFER[2699]	// (internal1_m300_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m300_Zav0	769	// (internal1_m300_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m300_flp	BUFFER[2701]	// (internal1_m300_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m300_flp	770	// (internal1_m300_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m300_fls	BUFFER[2703]	// (internal1_m300_fls)  fls - флаг одношагового режима
#define idinternal1_m300_fls	771	// (internal1_m300_fls)  fls - флаг одношагового режима
#define internal1_m319_Out10	BUFFER[2705]	// (internal1_m319_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m319_Out10	772	// (internal1_m319_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m320_Out10	BUFFER[2707]	// (internal1_m320_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m320_Out10	773	// (internal1_m320_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m321_Out10	BUFFER[2709]	// (internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m321_Out10	774	// (internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m324_Xtek0	BUFFER[2711]	// (internal1_m324_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m324_Xtek0	775	// (internal1_m324_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m334_Xtek0	BUFFER[2716]	// (internal1_m334_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m334_Xtek0	776	// (internal1_m334_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m335_Out10	BUFFER[2721]	// (internal1_m335_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m335_Out10	777	// (internal1_m335_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m336_Out10	BUFFER[2723]	// (internal1_m336_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m336_Out10	778	// (internal1_m336_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m337_Out10	BUFFER[2725]	// (internal1_m337_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m337_Out10	779	// (internal1_m337_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m347_Out10	BUFFER[2727]	// (internal1_m347_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m347_Out10	780	// (internal1_m347_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m348_Out10	BUFFER[2729]	// (internal1_m348_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m348_Out10	781	// (internal1_m348_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m349_Out10	BUFFER[2731]	// (internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m349_Out10	782	// (internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m350_Out10	BUFFER[2733]	// (internal1_m350_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m350_Out10	783	// (internal1_m350_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m364_MyFirstEnterFlag	BUFFER[2735]	// (internal1_m364_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m364_MyFirstEnterFlag	784	// (internal1_m364_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m364_Pav0	BUFFER[2737]	// (internal1_m364_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m364_Pav0	785	// (internal1_m364_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m364_Pv0	BUFFER[2739]	// (internal1_m364_Pv0)  - Пер. выключатель механизма
#define idinternal1_m364_Pv0	786	// (internal1_m364_Pv0)  - Пер. выключатель механизма
#define internal1_m364_RA00	BUFFER[2741]	// (internal1_m364_RA00)  - последнее задание вперед
#define idinternal1_m364_RA00	787	// (internal1_m364_RA00)  - последнее задание вперед
#define internal1_m364_RA10	BUFFER[2743]	// (internal1_m364_RA10)  - последнее задание назад
#define idinternal1_m364_RA10	788	// (internal1_m364_RA10)  - последнее задание назад
#define internal1_m364_V00	BUFFER[2745]	// (internal1_m364_V00)  V00 - текущая скорость механизма
#define idinternal1_m364_V00	789	// (internal1_m364_V00)  V00 - текущая скорость механизма
#define internal1_m364_X00	BUFFER[2750]	// (internal1_m364_X00)  X00 - текущая координата механизма
#define idinternal1_m364_X00	790	// (internal1_m364_X00)  X00 - текущая координата механизма
#define internal1_m364_Zav0	BUFFER[2755]	// (internal1_m364_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m364_Zav0	791	// (internal1_m364_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m364_Zv0	BUFFER[2757]	// (internal1_m364_Zv0)  - Зад. выключатель механизма
#define idinternal1_m364_Zv0	792	// (internal1_m364_Zv0)  - Зад. выключатель механизма
#define internal1_m380_MyFirstEnterFlag	BUFFER[2759]	// (internal1_m380_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m380_MyFirstEnterFlag	793	// (internal1_m380_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m380_Pav0	BUFFER[2761]	// (internal1_m380_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m380_Pav0	794	// (internal1_m380_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m380_Pv0	BUFFER[2763]	// (internal1_m380_Pv0)  - Пер. выключатель механизма
#define idinternal1_m380_Pv0	795	// (internal1_m380_Pv0)  - Пер. выключатель механизма
#define internal1_m380_RA00	BUFFER[2765]	// (internal1_m380_RA00)  - последнее задание вперед
#define idinternal1_m380_RA00	796	// (internal1_m380_RA00)  - последнее задание вперед
#define internal1_m380_RA10	BUFFER[2767]	// (internal1_m380_RA10)  - последнее задание назад
#define idinternal1_m380_RA10	797	// (internal1_m380_RA10)  - последнее задание назад
#define internal1_m380_V00	BUFFER[2769]	// (internal1_m380_V00)  V00 - текущая скорость механизма
#define idinternal1_m380_V00	798	// (internal1_m380_V00)  V00 - текущая скорость механизма
#define internal1_m380_X00	BUFFER[2774]	// (internal1_m380_X00)  X00 - текущая координата механизма
#define idinternal1_m380_X00	799	// (internal1_m380_X00)  X00 - текущая координата механизма
#define internal1_m380_Zav0	BUFFER[2779]	// (internal1_m380_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m380_Zav0	800	// (internal1_m380_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m380_Zv0	BUFFER[2781]	// (internal1_m380_Zv0)  - Зад. выключатель механизма
#define idinternal1_m380_Zv0	801	// (internal1_m380_Zv0)  - Зад. выключатель механизма
#define internal1_m395_MyFirstEnterFlag	BUFFER[2783]	// (internal1_m395_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m395_MyFirstEnterFlag	802	// (internal1_m395_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m395_Pav0	BUFFER[2785]	// (internal1_m395_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m395_Pav0	803	// (internal1_m395_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m395_Pv0	BUFFER[2787]	// (internal1_m395_Pv0)  - Пер. выключатель механизма
#define idinternal1_m395_Pv0	804	// (internal1_m395_Pv0)  - Пер. выключатель механизма
#define internal1_m395_RA00	BUFFER[2789]	// (internal1_m395_RA00)  - последнее задание вперед
#define idinternal1_m395_RA00	805	// (internal1_m395_RA00)  - последнее задание вперед
#define internal1_m395_RA10	BUFFER[2791]	// (internal1_m395_RA10)  - последнее задание назад
#define idinternal1_m395_RA10	806	// (internal1_m395_RA10)  - последнее задание назад
#define internal1_m395_V00	BUFFER[2793]	// (internal1_m395_V00)  V00 - текущая скорость механизма
#define idinternal1_m395_V00	807	// (internal1_m395_V00)  V00 - текущая скорость механизма
#define internal1_m395_X00	BUFFER[2798]	// (internal1_m395_X00)  X00 - текущая координата механизма
#define idinternal1_m395_X00	808	// (internal1_m395_X00)  X00 - текущая координата механизма
#define internal1_m395_Zav0	BUFFER[2803]	// (internal1_m395_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m395_Zav0	809	// (internal1_m395_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m395_Zv0	BUFFER[2805]	// (internal1_m395_Zv0)  - Зад. выключатель механизма
#define idinternal1_m395_Zv0	810	// (internal1_m395_Zv0)  - Зад. выключатель механизма
#define internal1_m39_fef	BUFFER[2807]	// (internal1_m39_fef) fef
#define idinternal1_m39_fef	811	// (internal1_m39_fef) fef
#define internal1_m39_reg	BUFFER[2809]	// (internal1_m39_reg) режим работы квдс 0 - ожидание сигнала 1- выдан импульс 2 отсчет удержания синхроимпульса 3 -блокировка
#define idinternal1_m39_reg	812	// (internal1_m39_reg) режим работы квдс 0 - ожидание сигнала 1- выдан импульс 2 отсчет удержания синхроимпульса 3 -блокировка
#define internal1_m39_tgen	BUFFER[2812]	// (internal1_m39_tgen) задержки срабатывания генератора импульса
#define idinternal1_m39_tgen	813	// (internal1_m39_tgen) задержки срабатывания генератора импульса
#define internal1_m39_tlock	BUFFER[2817]	// (internal1_m39_tlock) время до конца блокировки
#define idinternal1_m39_tlock	814	// (internal1_m39_tlock) время до конца блокировки
#define internal1_m39_tsin	BUFFER[2822]	// (internal1_m39_tsin) время до конца удержания синхроимпульса
#define idinternal1_m39_tsin	815	// (internal1_m39_tsin) время до конца удержания синхроимпульса
#define internal1_m406_Out10	BUFFER[2827]	// (internal1_m406_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m406_Out10	816	// (internal1_m406_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m407_Out10	BUFFER[2829]	// (internal1_m407_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m407_Out10	817	// (internal1_m407_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m408_Out10	BUFFER[2831]	// (internal1_m408_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m408_Out10	818	// (internal1_m408_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m409_Out10	BUFFER[2833]	// (internal1_m409_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m409_Out10	819	// (internal1_m409_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m416_Xtek0	BUFFER[2835]	// (internal1_m416_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m416_Xtek0	820	// (internal1_m416_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m425_Out10	BUFFER[2840]	// (internal1_m425_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m425_Out10	821	// (internal1_m425_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m426_Out10	BUFFER[2842]	// (internal1_m426_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m426_Out10	822	// (internal1_m426_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m427_Out10	BUFFER[2844]	// (internal1_m427_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m427_Out10	823	// (internal1_m427_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m428_Out10	BUFFER[2846]	// (internal1_m428_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m428_Out10	824	// (internal1_m428_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m429_Xtek0	BUFFER[2848]	// (internal1_m429_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m429_Xtek0	825	// (internal1_m429_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m443_MyFirstEnterFlag	BUFFER[2853]	// (internal1_m443_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m443_MyFirstEnterFlag	826	// (internal1_m443_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m443_Pav0	BUFFER[2855]	// (internal1_m443_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m443_Pav0	827	// (internal1_m443_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m443_Pv0	BUFFER[2857]	// (internal1_m443_Pv0)  - Пер. выключатель механизма
#define idinternal1_m443_Pv0	828	// (internal1_m443_Pv0)  - Пер. выключатель механизма
#define internal1_m443_RA00	BUFFER[2859]	// (internal1_m443_RA00)  - последнее задание вперед
#define idinternal1_m443_RA00	829	// (internal1_m443_RA00)  - последнее задание вперед
#define internal1_m443_RA10	BUFFER[2861]	// (internal1_m443_RA10)  - последнее задание назад
#define idinternal1_m443_RA10	830	// (internal1_m443_RA10)  - последнее задание назад
#define internal1_m443_V00	BUFFER[2863]	// (internal1_m443_V00)  V00 - текущая скорость механизма
#define idinternal1_m443_V00	831	// (internal1_m443_V00)  V00 - текущая скорость механизма
#define internal1_m443_X00	BUFFER[2868]	// (internal1_m443_X00)  X00 - текущая координата механизма
#define idinternal1_m443_X00	832	// (internal1_m443_X00)  X00 - текущая координата механизма
#define internal1_m443_Zav0	BUFFER[2873]	// (internal1_m443_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m443_Zav0	833	// (internal1_m443_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m443_Zv0	BUFFER[2875]	// (internal1_m443_Zv0)  - Зад. выключатель механизма
#define idinternal1_m443_Zv0	834	// (internal1_m443_Zv0)  - Зад. выключатель механизма
#define internal1_m457_MyFirstEnterFlag	BUFFER[2877]	// (internal1_m457_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m457_MyFirstEnterFlag	835	// (internal1_m457_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m457_Pav0	BUFFER[2879]	// (internal1_m457_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m457_Pav0	836	// (internal1_m457_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m457_Pv0	BUFFER[2881]	// (internal1_m457_Pv0)  - Пер. выключатель механизма
#define idinternal1_m457_Pv0	837	// (internal1_m457_Pv0)  - Пер. выключатель механизма
#define internal1_m457_RA00	BUFFER[2883]	// (internal1_m457_RA00)  - последнее задание вперед
#define idinternal1_m457_RA00	838	// (internal1_m457_RA00)  - последнее задание вперед
#define internal1_m457_RA10	BUFFER[2885]	// (internal1_m457_RA10)  - последнее задание назад
#define idinternal1_m457_RA10	839	// (internal1_m457_RA10)  - последнее задание назад
#define internal1_m457_V00	BUFFER[2887]	// (internal1_m457_V00)  V00 - текущая скорость механизма
#define idinternal1_m457_V00	840	// (internal1_m457_V00)  V00 - текущая скорость механизма
#define internal1_m457_X00	BUFFER[2892]	// (internal1_m457_X00)  X00 - текущая координата механизма
#define idinternal1_m457_X00	841	// (internal1_m457_X00)  X00 - текущая координата механизма
#define internal1_m457_Zav0	BUFFER[2897]	// (internal1_m457_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m457_Zav0	842	// (internal1_m457_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m457_Zv0	BUFFER[2899]	// (internal1_m457_Zv0)  - Зад. выключатель механизма
#define idinternal1_m457_Zv0	843	// (internal1_m457_Zv0)  - Зад. выключатель механизма
#define internal1_m467_q0	BUFFER[2901]	// (internal1_m467_q0) q0 - внутренний параметр
#define idinternal1_m467_q0	844	// (internal1_m467_q0) q0 - внутренний параметр
#define internal1_m468_q0	BUFFER[2903]	// (internal1_m468_q0) q0 - внутренний параметр
#define idinternal1_m468_q0	845	// (internal1_m468_q0) q0 - внутренний параметр
#define internal1_m471_MyFirstEnterFlag	BUFFER[2905]	// (internal1_m471_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m471_MyFirstEnterFlag	846	// (internal1_m471_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m471_Pav0	BUFFER[2907]	// (internal1_m471_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m471_Pav0	847	// (internal1_m471_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m471_Pv0	BUFFER[2909]	// (internal1_m471_Pv0)  - Пер. выключатель механизма
#define idinternal1_m471_Pv0	848	// (internal1_m471_Pv0)  - Пер. выключатель механизма
#define internal1_m471_RA00	BUFFER[2911]	// (internal1_m471_RA00)  - последнее задание вперед
#define idinternal1_m471_RA00	849	// (internal1_m471_RA00)  - последнее задание вперед
#define internal1_m471_RA10	BUFFER[2913]	// (internal1_m471_RA10)  - последнее задание назад
#define idinternal1_m471_RA10	850	// (internal1_m471_RA10)  - последнее задание назад
#define internal1_m471_V00	BUFFER[2915]	// (internal1_m471_V00)  V00 - текущая скорость механизма
#define idinternal1_m471_V00	851	// (internal1_m471_V00)  V00 - текущая скорость механизма
#define internal1_m471_X00	BUFFER[2920]	// (internal1_m471_X00)  X00 - текущая координата механизма
#define idinternal1_m471_X00	852	// (internal1_m471_X00)  X00 - текущая координата механизма
#define internal1_m471_Zav0	BUFFER[2925]	// (internal1_m471_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m471_Zav0	853	// (internal1_m471_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m471_Zv0	BUFFER[2927]	// (internal1_m471_Zv0)  - Зад. выключатель механизма
#define idinternal1_m471_Zv0	854	// (internal1_m471_Zv0)  - Зад. выключатель механизма
#define internal1_m473_MyFirstEnterFlag	BUFFER[2929]	// (internal1_m473_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m473_MyFirstEnterFlag	855	// (internal1_m473_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m473_Pav0	BUFFER[2931]	// (internal1_m473_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m473_Pav0	856	// (internal1_m473_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m473_Pv0	BUFFER[2933]	// (internal1_m473_Pv0)  - Пер. выключатель механизма
#define idinternal1_m473_Pv0	857	// (internal1_m473_Pv0)  - Пер. выключатель механизма
#define internal1_m473_RA00	BUFFER[2935]	// (internal1_m473_RA00)  - последнее задание вперед
#define idinternal1_m473_RA00	858	// (internal1_m473_RA00)  - последнее задание вперед
#define internal1_m473_RA10	BUFFER[2937]	// (internal1_m473_RA10)  - последнее задание назад
#define idinternal1_m473_RA10	859	// (internal1_m473_RA10)  - последнее задание назад
#define internal1_m473_V00	BUFFER[2939]	// (internal1_m473_V00)  V00 - текущая скорость механизма
#define idinternal1_m473_V00	860	// (internal1_m473_V00)  V00 - текущая скорость механизма
#define internal1_m473_X00	BUFFER[2944]	// (internal1_m473_X00)  X00 - текущая координата механизма
#define idinternal1_m473_X00	861	// (internal1_m473_X00)  X00 - текущая координата механизма
#define internal1_m473_Zav0	BUFFER[2949]	// (internal1_m473_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m473_Zav0	862	// (internal1_m473_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m473_Zv0	BUFFER[2951]	// (internal1_m473_Zv0)  - Зад. выключатель механизма
#define idinternal1_m473_Zv0	863	// (internal1_m473_Zv0)  - Зад. выключатель механизма
#define internal1_m479_q0	BUFFER[2953]	// (internal1_m479_q0) q0 - внутренний параметр
#define idinternal1_m479_q0	864	// (internal1_m479_q0) q0 - внутренний параметр
#define internal1_m47_Out10	BUFFER[2955]	// (internal1_m47_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m47_Out10	865	// (internal1_m47_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m480_q0	BUFFER[2957]	// (internal1_m480_q0) q0 - внутренний параметр
#define idinternal1_m480_q0	866	// (internal1_m480_q0) q0 - внутренний параметр
#define internal1_m483_MyFirstEnterFlag	BUFFER[2959]	// (internal1_m483_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m483_MyFirstEnterFlag	867	// (internal1_m483_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m483_Pav0	BUFFER[2961]	// (internal1_m483_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m483_Pav0	868	// (internal1_m483_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m483_Pv0	BUFFER[2963]	// (internal1_m483_Pv0)  - Пер. выключатель механизма
#define idinternal1_m483_Pv0	869	// (internal1_m483_Pv0)  - Пер. выключатель механизма
#define internal1_m483_RA00	BUFFER[2965]	// (internal1_m483_RA00)  - последнее задание вперед
#define idinternal1_m483_RA00	870	// (internal1_m483_RA00)  - последнее задание вперед
#define internal1_m483_RA10	BUFFER[2967]	// (internal1_m483_RA10)  - последнее задание назад
#define idinternal1_m483_RA10	871	// (internal1_m483_RA10)  - последнее задание назад
#define internal1_m483_V00	BUFFER[2969]	// (internal1_m483_V00)  V00 - текущая скорость механизма
#define idinternal1_m483_V00	872	// (internal1_m483_V00)  V00 - текущая скорость механизма
#define internal1_m483_X00	BUFFER[2974]	// (internal1_m483_X00)  X00 - текущая координата механизма
#define idinternal1_m483_X00	873	// (internal1_m483_X00)  X00 - текущая координата механизма
#define internal1_m483_Zav0	BUFFER[2979]	// (internal1_m483_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m483_Zav0	874	// (internal1_m483_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m483_Zv0	BUFFER[2981]	// (internal1_m483_Zv0)  - Зад. выключатель механизма
#define idinternal1_m483_Zv0	875	// (internal1_m483_Zv0)  - Зад. выключатель механизма
#define internal1_m494_MyFirstEnterFlag	BUFFER[2983]	// (internal1_m494_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m494_MyFirstEnterFlag	876	// (internal1_m494_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m494_Pav0	BUFFER[2985]	// (internal1_m494_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m494_Pav0	877	// (internal1_m494_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m494_Pv0	BUFFER[2987]	// (internal1_m494_Pv0)  - Пер. выключатель механизма
#define idinternal1_m494_Pv0	878	// (internal1_m494_Pv0)  - Пер. выключатель механизма
#define internal1_m494_RA00	BUFFER[2989]	// (internal1_m494_RA00)  - последнее задание вперед
#define idinternal1_m494_RA00	879	// (internal1_m494_RA00)  - последнее задание вперед
#define internal1_m494_RA10	BUFFER[2991]	// (internal1_m494_RA10)  - последнее задание назад
#define idinternal1_m494_RA10	880	// (internal1_m494_RA10)  - последнее задание назад
#define internal1_m494_V00	BUFFER[2993]	// (internal1_m494_V00)  V00 - текущая скорость механизма
#define idinternal1_m494_V00	881	// (internal1_m494_V00)  V00 - текущая скорость механизма
#define internal1_m494_X00	BUFFER[2998]	// (internal1_m494_X00)  X00 - текущая координата механизма
#define idinternal1_m494_X00	882	// (internal1_m494_X00)  X00 - текущая координата механизма
#define internal1_m494_Zav0	BUFFER[3003]	// (internal1_m494_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m494_Zav0	883	// (internal1_m494_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m494_Zv0	BUFFER[3005]	// (internal1_m494_Zv0)  - Зад. выключатель механизма
#define idinternal1_m494_Zv0	884	// (internal1_m494_Zv0)  - Зад. выключатель механизма
#define internal1_m518_Out10	BUFFER[3007]	// (internal1_m518_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m518_Out10	885	// (internal1_m518_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m534_Out10	BUFFER[3009]	// (internal1_m534_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m534_Out10	886	// (internal1_m534_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m535_Out10	BUFFER[3011]	// (internal1_m535_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m535_Out10	887	// (internal1_m535_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m550_Out10	BUFFER[3013]	// (internal1_m550_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m550_Out10	888	// (internal1_m550_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m551_Out10	BUFFER[3015]	// (internal1_m551_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m551_Out10	889	// (internal1_m551_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m552_Out10	BUFFER[3017]	// (internal1_m552_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m552_Out10	890	// (internal1_m552_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m566_MyFirstEnterFlag	BUFFER[3019]	// (internal1_m566_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m566_MyFirstEnterFlag	891	// (internal1_m566_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m566_Pav0	BUFFER[3021]	// (internal1_m566_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m566_Pav0	892	// (internal1_m566_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m566_Pv0	BUFFER[3023]	// (internal1_m566_Pv0)  - Пер. выключатель механизма
#define idinternal1_m566_Pv0	893	// (internal1_m566_Pv0)  - Пер. выключатель механизма
#define internal1_m566_RA00	BUFFER[3025]	// (internal1_m566_RA00)  - последнее задание вперед
#define idinternal1_m566_RA00	894	// (internal1_m566_RA00)  - последнее задание вперед
#define internal1_m566_RA10	BUFFER[3027]	// (internal1_m566_RA10)  - последнее задание назад
#define idinternal1_m566_RA10	895	// (internal1_m566_RA10)  - последнее задание назад
#define internal1_m566_V00	BUFFER[3029]	// (internal1_m566_V00)  V00 - текущая скорость механизма
#define idinternal1_m566_V00	896	// (internal1_m566_V00)  V00 - текущая скорость механизма
#define internal1_m566_X00	BUFFER[3034]	// (internal1_m566_X00)  X00 - текущая координата механизма
#define idinternal1_m566_X00	897	// (internal1_m566_X00)  X00 - текущая координата механизма
#define internal1_m566_Zav0	BUFFER[3039]	// (internal1_m566_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m566_Zav0	898	// (internal1_m566_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m566_Zv0	BUFFER[3041]	// (internal1_m566_Zv0)  - Зад. выключатель механизма
#define idinternal1_m566_Zv0	899	// (internal1_m566_Zv0)  - Зад. выключатель механизма
#define internal1_m580_MyFirstEnterFlag	BUFFER[3043]	// (internal1_m580_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m580_MyFirstEnterFlag	900	// (internal1_m580_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m580_Pav0	BUFFER[3045]	// (internal1_m580_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m580_Pav0	901	// (internal1_m580_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m580_Pv0	BUFFER[3047]	// (internal1_m580_Pv0)  - Пер. выключатель механизма
#define idinternal1_m580_Pv0	902	// (internal1_m580_Pv0)  - Пер. выключатель механизма
#define internal1_m580_RA00	BUFFER[3049]	// (internal1_m580_RA00)  - последнее задание вперед
#define idinternal1_m580_RA00	903	// (internal1_m580_RA00)  - последнее задание вперед
#define internal1_m580_RA10	BUFFER[3051]	// (internal1_m580_RA10)  - последнее задание назад
#define idinternal1_m580_RA10	904	// (internal1_m580_RA10)  - последнее задание назад
#define internal1_m580_V00	BUFFER[3053]	// (internal1_m580_V00)  V00 - текущая скорость механизма
#define idinternal1_m580_V00	905	// (internal1_m580_V00)  V00 - текущая скорость механизма
#define internal1_m580_X00	BUFFER[3058]	// (internal1_m580_X00)  X00 - текущая координата механизма
#define idinternal1_m580_X00	906	// (internal1_m580_X00)  X00 - текущая координата механизма
#define internal1_m580_Zav0	BUFFER[3063]	// (internal1_m580_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m580_Zav0	907	// (internal1_m580_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m580_Zv0	BUFFER[3065]	// (internal1_m580_Zv0)  - Зад. выключатель механизма
#define idinternal1_m580_Zv0	908	// (internal1_m580_Zv0)  - Зад. выключатель механизма
#define internal1_m592_MyFirstEnterFlag	BUFFER[3067]	// (internal1_m592_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m592_MyFirstEnterFlag	909	// (internal1_m592_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m592_Pav0	BUFFER[3069]	// (internal1_m592_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m592_Pav0	910	// (internal1_m592_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m592_Pv0	BUFFER[3071]	// (internal1_m592_Pv0)  - Пер. выключатель механизма
#define idinternal1_m592_Pv0	911	// (internal1_m592_Pv0)  - Пер. выключатель механизма
#define internal1_m592_RA00	BUFFER[3073]	// (internal1_m592_RA00)  - последнее задание вперед
#define idinternal1_m592_RA00	912	// (internal1_m592_RA00)  - последнее задание вперед
#define internal1_m592_RA10	BUFFER[3075]	// (internal1_m592_RA10)  - последнее задание назад
#define idinternal1_m592_RA10	913	// (internal1_m592_RA10)  - последнее задание назад
#define internal1_m592_V00	BUFFER[3077]	// (internal1_m592_V00)  V00 - текущая скорость механизма
#define idinternal1_m592_V00	914	// (internal1_m592_V00)  V00 - текущая скорость механизма
#define internal1_m592_X00	BUFFER[3082]	// (internal1_m592_X00)  X00 - текущая координата механизма
#define idinternal1_m592_X00	915	// (internal1_m592_X00)  X00 - текущая координата механизма
#define internal1_m592_Zav0	BUFFER[3087]	// (internal1_m592_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m592_Zav0	916	// (internal1_m592_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m592_Zv0	BUFFER[3089]	// (internal1_m592_Zv0)  - Зад. выключатель механизма
#define idinternal1_m592_Zv0	917	// (internal1_m592_Zv0)  - Зад. выключатель механизма
#define internal1_m593_MyFirstEnterFlag	BUFFER[3091]	// (internal1_m593_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m593_MyFirstEnterFlag	918	// (internal1_m593_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m593_Pav0	BUFFER[3093]	// (internal1_m593_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m593_Pav0	919	// (internal1_m593_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m593_Pv0	BUFFER[3095]	// (internal1_m593_Pv0)  - Пер. выключатель механизма
#define idinternal1_m593_Pv0	920	// (internal1_m593_Pv0)  - Пер. выключатель механизма
#define internal1_m593_RA00	BUFFER[3097]	// (internal1_m593_RA00)  - последнее задание вперед
#define idinternal1_m593_RA00	921	// (internal1_m593_RA00)  - последнее задание вперед
#define internal1_m593_RA10	BUFFER[3099]	// (internal1_m593_RA10)  - последнее задание назад
#define idinternal1_m593_RA10	922	// (internal1_m593_RA10)  - последнее задание назад
#define internal1_m593_V00	BUFFER[3101]	// (internal1_m593_V00)  V00 - текущая скорость механизма
#define idinternal1_m593_V00	923	// (internal1_m593_V00)  V00 - текущая скорость механизма
#define internal1_m593_X00	BUFFER[3106]	// (internal1_m593_X00)  X00 - текущая координата механизма
#define idinternal1_m593_X00	924	// (internal1_m593_X00)  X00 - текущая координата механизма
#define internal1_m593_Zav0	BUFFER[3111]	// (internal1_m593_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m593_Zav0	925	// (internal1_m593_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m593_Zv0	BUFFER[3113]	// (internal1_m593_Zv0)  - Зад. выключатель механизма
#define idinternal1_m593_Zv0	926	// (internal1_m593_Zv0)  - Зад. выключатель механизма
#define internal1_m601_tx	BUFFER[3115]	// (internal1_m601_tx) tx - время накопленное сек
#define idinternal1_m601_tx	927	// (internal1_m601_tx) tx - время накопленное сек
#define internal1_m601_y0	BUFFER[3120]	// (internal1_m601_y0) y0
#define idinternal1_m601_y0	928	// (internal1_m601_y0) y0
#define internal1_m603_tx	BUFFER[3122]	// (internal1_m603_tx) tx - время накопленное сек
#define idinternal1_m603_tx	929	// (internal1_m603_tx) tx - время накопленное сек
#define internal1_m603_y0	BUFFER[3127]	// (internal1_m603_y0) y0
#define idinternal1_m603_y0	930	// (internal1_m603_y0) y0
#define internal1_m605_MyFirstEnterFlag	BUFFER[3129]	// (internal1_m605_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m605_MyFirstEnterFlag	931	// (internal1_m605_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m605_Pav0	BUFFER[3131]	// (internal1_m605_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m605_Pav0	932	// (internal1_m605_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m605_Pv0	BUFFER[3133]	// (internal1_m605_Pv0)  - Пер. выключатель механизма
#define idinternal1_m605_Pv0	933	// (internal1_m605_Pv0)  - Пер. выключатель механизма
#define internal1_m605_RA00	BUFFER[3135]	// (internal1_m605_RA00)  - последнее задание вперед
#define idinternal1_m605_RA00	934	// (internal1_m605_RA00)  - последнее задание вперед
#define internal1_m605_RA10	BUFFER[3137]	// (internal1_m605_RA10)  - последнее задание назад
#define idinternal1_m605_RA10	935	// (internal1_m605_RA10)  - последнее задание назад
#define internal1_m605_V00	BUFFER[3139]	// (internal1_m605_V00)  V00 - текущая скорость механизма
#define idinternal1_m605_V00	936	// (internal1_m605_V00)  V00 - текущая скорость механизма
#define internal1_m605_X00	BUFFER[3144]	// (internal1_m605_X00)  X00 - текущая координата механизма
#define idinternal1_m605_X00	937	// (internal1_m605_X00)  X00 - текущая координата механизма
#define internal1_m605_Zav0	BUFFER[3149]	// (internal1_m605_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m605_Zav0	938	// (internal1_m605_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m605_Zv0	BUFFER[3151]	// (internal1_m605_Zv0)  - Зад. выключатель механизма
#define idinternal1_m605_Zv0	939	// (internal1_m605_Zv0)  - Зад. выключатель механизма
#define internal1_m606_MyFirstEnterFlag	BUFFER[3153]	// (internal1_m606_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m606_MyFirstEnterFlag	940	// (internal1_m606_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m606_Pav0	BUFFER[3155]	// (internal1_m606_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m606_Pav0	941	// (internal1_m606_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m606_Pv0	BUFFER[3157]	// (internal1_m606_Pv0)  - Пер. выключатель механизма
#define idinternal1_m606_Pv0	942	// (internal1_m606_Pv0)  - Пер. выключатель механизма
#define internal1_m606_RA00	BUFFER[3159]	// (internal1_m606_RA00)  - последнее задание вперед
#define idinternal1_m606_RA00	943	// (internal1_m606_RA00)  - последнее задание вперед
#define internal1_m606_RA10	BUFFER[3161]	// (internal1_m606_RA10)  - последнее задание назад
#define idinternal1_m606_RA10	944	// (internal1_m606_RA10)  - последнее задание назад
#define internal1_m606_V00	BUFFER[3163]	// (internal1_m606_V00)  V00 - текущая скорость механизма
#define idinternal1_m606_V00	945	// (internal1_m606_V00)  V00 - текущая скорость механизма
#define internal1_m606_X00	BUFFER[3168]	// (internal1_m606_X00)  X00 - текущая координата механизма
#define idinternal1_m606_X00	946	// (internal1_m606_X00)  X00 - текущая координата механизма
#define internal1_m606_Zav0	BUFFER[3173]	// (internal1_m606_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m606_Zav0	947	// (internal1_m606_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m606_Zv0	BUFFER[3175]	// (internal1_m606_Zv0)  - Зад. выключатель механизма
#define idinternal1_m606_Zv0	948	// (internal1_m606_Zv0)  - Зад. выключатель механизма
#define internal1_m613_tx	BUFFER[3177]	// (internal1_m613_tx) tx - время накопленное сек
#define idinternal1_m613_tx	949	// (internal1_m613_tx) tx - время накопленное сек
#define internal1_m613_y0	BUFFER[3182]	// (internal1_m613_y0) y0
#define idinternal1_m613_y0	950	// (internal1_m613_y0) y0
#define internal1_m626_tx	BUFFER[3184]	// (internal1_m626_tx) tx - время накопленное сек
#define idinternal1_m626_tx	951	// (internal1_m626_tx) tx - время накопленное сек
#define internal1_m626_y0	BUFFER[3189]	// (internal1_m626_y0) y0
#define idinternal1_m626_y0	952	// (internal1_m626_y0) y0
#define internal1_m62_Out10	BUFFER[3191]	// (internal1_m62_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m62_Out10	953	// (internal1_m62_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m637_y0	BUFFER[3193]	// (internal1_m637_y0) y0 - внутренний параметр
#define idinternal1_m637_y0	954	// (internal1_m637_y0) y0 - внутренний параметр
#define internal1_m653_Out10	BUFFER[3198]	// (internal1_m653_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m653_Out10	955	// (internal1_m653_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m654_Out10	BUFFER[3200]	// (internal1_m654_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m654_Out10	956	// (internal1_m654_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m655_Out10	BUFFER[3202]	// (internal1_m655_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m655_Out10	957	// (internal1_m655_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m656_Out10	BUFFER[3204]	// (internal1_m656_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m656_Out10	958	// (internal1_m656_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m657_Out10	BUFFER[3206]	// (internal1_m657_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m657_Out10	959	// (internal1_m657_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m658_Out10	BUFFER[3208]	// (internal1_m658_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m658_Out10	960	// (internal1_m658_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m66_MyFirstEnterFlag	BUFFER[3210]	// (internal1_m66_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m66_MyFirstEnterFlag	961	// (internal1_m66_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m66_Pav0	BUFFER[3212]	// (internal1_m66_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m66_Pav0	962	// (internal1_m66_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m66_Ppv0	BUFFER[3214]	// (internal1_m66_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m66_Ppv0	963	// (internal1_m66_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m66_RA00	BUFFER[3216]	// (internal1_m66_RA00) RA00 - последнее задание вперед
#define idinternal1_m66_RA00	964	// (internal1_m66_RA00) RA00 - последнее задание вперед
#define internal1_m66_RA10	BUFFER[3218]	// (internal1_m66_RA10) RA10 - последнее задание назад
#define idinternal1_m66_RA10	965	// (internal1_m66_RA10) RA10 - последнее задание назад
#define internal1_m66_RA30	BUFFER[3220]	// (internal1_m66_RA30)  RA30 - разрешение движения
#define idinternal1_m66_RA30	966	// (internal1_m66_RA30)  RA30 - разрешение движения
#define internal1_m66_RA50	BUFFER[3222]	// (internal1_m66_RA50) Ra50 - последнее задание скорости
#define idinternal1_m66_RA50	967	// (internal1_m66_RA50) Ra50 - последнее задание скорости
#define internal1_m66_RV00	BUFFER[3224]	// (internal1_m66_RV00) V0 - текущая скорость ОРР
#define idinternal1_m66_RV00	968	// (internal1_m66_RV00) V0 - текущая скорость ОРР
#define internal1_m66_Sh00	BUFFER[3229]	// (internal1_m66_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m66_Sh00	969	// (internal1_m66_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m66_ShV00	BUFFER[3234]	// (internal1_m66_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m66_ShV00	970	// (internal1_m66_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m66_X00	BUFFER[3239]	// (internal1_m66_X00) X0 - текущая координата ОРР
#define idinternal1_m66_X00	971	// (internal1_m66_X00) X0 - текущая координата ОРР
#define internal1_m66_Zav0	BUFFER[3244]	// (internal1_m66_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m66_Zav0	972	// (internal1_m66_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m66_flp	BUFFER[3246]	// (internal1_m66_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m66_flp	973	// (internal1_m66_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m66_fls	BUFFER[3248]	// (internal1_m66_fls)  fls - флаг одношагового режима
#define idinternal1_m66_fls	974	// (internal1_m66_fls)  fls - флаг одношагового режима
#define internal1_m673_Out10	BUFFER[3250]	// (internal1_m673_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m673_Out10	975	// (internal1_m673_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m675_Out10	BUFFER[3252]	// (internal1_m675_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m675_Out10	976	// (internal1_m675_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m676_Out10	BUFFER[3254]	// (internal1_m676_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m676_Out10	977	// (internal1_m676_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m677_Out10	BUFFER[3256]	// (internal1_m677_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m677_Out10	978	// (internal1_m677_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m678_Out10	BUFFER[3258]	// (internal1_m678_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m678_Out10	979	// (internal1_m678_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m687_Out10	BUFFER[3260]	// (internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m687_Out10	980	// (internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m688_Out10	BUFFER[3262]	// (internal1_m688_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m688_Out10	981	// (internal1_m688_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m689_Out10	BUFFER[3264]	// (internal1_m689_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m689_Out10	982	// (internal1_m689_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m690_Out10	BUFFER[3266]	// (internal1_m690_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m690_Out10	983	// (internal1_m690_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m702_Chim0	BUFFER[3268]	// (internal1_m702_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m702_Chim0	984	// (internal1_m702_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m712_Chim0	BUFFER[3273]	// (internal1_m712_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m712_Chim0	985	// (internal1_m712_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m721_Chim0	BUFFER[3278]	// (internal1_m721_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m721_Chim0	986	// (internal1_m721_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m730_Chim0	BUFFER[3283]	// (internal1_m730_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m730_Chim0	987	// (internal1_m730_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m738_Chim0	BUFFER[3288]	// (internal1_m738_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m738_Chim0	988	// (internal1_m738_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m747_Chim0	BUFFER[3293]	// (internal1_m747_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m747_Chim0	989	// (internal1_m747_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m756_Chim0	BUFFER[3298]	// (internal1_m756_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m756_Chim0	990	// (internal1_m756_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m764_Chim0	BUFFER[3303]	// (internal1_m764_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m764_Chim0	991	// (internal1_m764_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m773_Chim0	BUFFER[3308]	// (internal1_m773_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m773_Chim0	992	// (internal1_m773_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m782_Chim0	BUFFER[3313]	// (internal1_m782_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m782_Chim0	993	// (internal1_m782_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m790_Chim0	BUFFER[3318]	// (internal1_m790_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m790_Chim0	994	// (internal1_m790_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m799_Chim0	BUFFER[3323]	// (internal1_m799_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m799_Chim0	995	// (internal1_m799_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m811_Out10	BUFFER[3328]	// (internal1_m811_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m811_Out10	996	// (internal1_m811_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m812_Out10	BUFFER[3330]	// (internal1_m812_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m812_Out10	997	// (internal1_m812_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m813_Out10	BUFFER[3332]	// (internal1_m813_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m813_Out10	998	// (internal1_m813_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m814_Out10	BUFFER[3334]	// (internal1_m814_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m814_Out10	999	// (internal1_m814_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m815_Out10	BUFFER[3336]	// (internal1_m815_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m815_Out10	1000	// (internal1_m815_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m816_Out10	BUFFER[3338]	// (internal1_m816_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m816_Out10	1001	// (internal1_m816_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m817_Out10	BUFFER[3340]	// (internal1_m817_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m817_Out10	1002	// (internal1_m817_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m834_Xtek0	BUFFER[3342]	// (internal1_m834_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m834_Xtek0	1003	// (internal1_m834_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m836_Xtek0	BUFFER[3347]	// (internal1_m836_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m836_Xtek0	1004	// (internal1_m836_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m837_Out10	BUFFER[3352]	// (internal1_m837_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m837_Out10	1005	// (internal1_m837_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m838_Out10	BUFFER[3354]	// (internal1_m838_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m838_Out10	1006	// (internal1_m838_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m839_Out10	BUFFER[3356]	// (internal1_m839_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m839_Out10	1007	// (internal1_m839_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m840_Out10	BUFFER[3358]	// (internal1_m840_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m840_Out10	1008	// (internal1_m840_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m852_Out10	BUFFER[3360]	// (internal1_m852_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m852_Out10	1009	// (internal1_m852_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m853_Out10	BUFFER[3362]	// (internal1_m853_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m853_Out10	1010	// (internal1_m853_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m854_Out10	BUFFER[3364]	// (internal1_m854_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m854_Out10	1011	// (internal1_m854_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m862_Chim0	BUFFER[3366]	// (internal1_m862_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m862_Chim0	1012	// (internal1_m862_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m870_Chim0	BUFFER[3371]	// (internal1_m870_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m870_Chim0	1013	// (internal1_m870_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m880_Chim0	BUFFER[3376]	// (internal1_m880_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m880_Chim0	1014	// (internal1_m880_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m892_MyFirstEnterFlag	BUFFER[3381]	// (internal1_m892_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m892_MyFirstEnterFlag	1015	// (internal1_m892_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m892_Pav0	BUFFER[3383]	// (internal1_m892_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m892_Pav0	1016	// (internal1_m892_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m892_Pv0	BUFFER[3385]	// (internal1_m892_Pv0)  - Пер. выключатель механизма
#define idinternal1_m892_Pv0	1017	// (internal1_m892_Pv0)  - Пер. выключатель механизма
#define internal1_m892_RA00	BUFFER[3387]	// (internal1_m892_RA00)  - последнее задание вперед
#define idinternal1_m892_RA00	1018	// (internal1_m892_RA00)  - последнее задание вперед
#define internal1_m892_RA10	BUFFER[3389]	// (internal1_m892_RA10)  - последнее задание назад
#define idinternal1_m892_RA10	1019	// (internal1_m892_RA10)  - последнее задание назад
#define internal1_m892_V00	BUFFER[3391]	// (internal1_m892_V00)  V00 - текущая скорость механизма
#define idinternal1_m892_V00	1020	// (internal1_m892_V00)  V00 - текущая скорость механизма
#define internal1_m892_X00	BUFFER[3396]	// (internal1_m892_X00)  X00 - текущая координата механизма
#define idinternal1_m892_X00	1021	// (internal1_m892_X00)  X00 - текущая координата механизма
#define internal1_m892_Zav0	BUFFER[3401]	// (internal1_m892_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m892_Zav0	1022	// (internal1_m892_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m892_Zv0	BUFFER[3403]	// (internal1_m892_Zv0)  - Зад. выключатель механизма
#define idinternal1_m892_Zv0	1023	// (internal1_m892_Zv0)  - Зад. выключатель механизма
#define internal1_m949_Out10	BUFFER[3405]	// (internal1_m949_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m949_Out10	1024	// (internal1_m949_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m950_Out10	BUFFER[3407]	// (internal1_m950_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m950_Out10	1025	// (internal1_m950_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m952_Xtek0	BUFFER[3409]	// (internal1_m952_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m952_Xtek0	1026	// (internal1_m952_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m953_Out10	BUFFER[3414]	// (internal1_m953_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m953_Out10	1027	// (internal1_m953_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m966_Out10	BUFFER[3416]	// (internal1_m966_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m966_Out10	1028	// (internal1_m966_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m967_Out10	BUFFER[3418]	// (internal1_m967_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m967_Out10	1029	// (internal1_m967_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m969_Xtek0	BUFFER[3420]	// (internal1_m969_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m969_Xtek0	1030	// (internal1_m969_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m970_Out10	BUFFER[3425]	// (internal1_m970_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m970_Out10	1031	// (internal1_m970_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m980_Out10	BUFFER[3427]	// (internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m980_Out10	1032	// (internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m981_Out10	BUFFER[3429]	// (internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m981_Out10	1033	// (internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m982_Out10	BUFFER[3431]	// (internal1_m982_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m982_Out10	1034	// (internal1_m982_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m983_Out10	BUFFER[3433]	// (internal1_m983_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m983_Out10	1035	// (internal1_m983_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m984_Out10	BUFFER[3435]	// (internal1_m984_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m984_Out10	1036	// (internal1_m984_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m995_Out10	BUFFER[3437]	// (internal1_m995_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m995_Out10	1037	// (internal1_m995_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m996_Out10	BUFFER[3439]	// (internal1_m996_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m996_Out10	1038	// (internal1_m996_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m997_Out10	BUFFER[3441]	// (internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m997_Out10	1039	// (internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m998_Out10	BUFFER[3443]	// (internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m998_Out10	1040	// (internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m999_Out10	BUFFER[3445]	// (internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m999_Out10	1041	// (internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define krb1	BUFFER[3447]	// ( - , - ) 
#define idkrb1	1042	// ( - , - ) 
#define krb2	BUFFER[3452]	// ( - , - ) 
#define idkrb2	1043	// ( - , - ) 
#define lEM_C1AD31LRP	BUFFER[3457]	// (C1AD31LRP) Общий сброс от РПУ
#define idlEM_C1AD31LRP	1044	// (C1AD31LRP) Общий сброс от РПУ
#define lEM_R0IE01LRP	BUFFER[3459]	// (R0IE01LRP) Отключение питание детекторов
#define idlEM_R0IE01LRP	1045	// (R0IE01LRP) Отключение питание детекторов
#define lEM_R0IE02LRP	BUFFER[3461]	// (R0IE02LRP) Отключить питание ПР, ПУ
#define idlEM_R0IE02LRP	1046	// (R0IE02LRP) Отключить питание ПР, ПУ
#define lEM_R3AD10LC1	BUFFER[3463]	// (R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define idlEM_R3AD10LC1	1047	// (R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define lEM_R3AD20LC1	BUFFER[3465]	// (R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define idlEM_R3AD20LC1	1048	// (R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define lEM_R5AD10LC1	BUFFER[3467]	// (R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define idlEM_R5AD10LC1	1049	// (R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define lEM_R5AD20LC1	BUFFER[3469]	// (R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define idlEM_R5AD20LC1	1050	// (R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define lEM_R6AD10LC1	BUFFER[3471]	// (R6AD10LC1) Выкатить кран-балку от ИС
#define idlEM_R6AD10LC1	1051	// (R6AD10LC1) Выкатить кран-балку от ИС
#define lEM_R8AD10LC1	BUFFER[3473]	// (R8AD10LC1) Установить аварийный НИ от ИС
#define idlEM_R8AD10LC1	1052	// (R8AD10LC1) Установить аварийный НИ от ИС
#define vainSBool	BUFFER[3475]	// Внутренняя переменная vainSBool
#define idvainSBool	1053	// Внутренняя переменная vainSBool
#define vainSFloat	BUFFER[3477]	// Внутренняя переменная vainSFloat
#define idvainSFloat	1054	// Внутренняя переменная vainSFloat
#define vainSInt	BUFFER[3482]	// Внутренняя переменная vainSInt
#define idvainSInt	1055	// Внутренняя переменная vainSInt
#define vainSLong	BUFFER[3487]	// Внутренняя переменная vainSLong
#define idvainSLong	1056	// Внутренняя переменная vainSLong
#define var1	BUFFER[3496]	// Внутренняя переменная var1
#define idvar1	1057	// Внутренняя переменная var1
#define var10	BUFFER[3498]	// Внутренняя переменная var10
#define idvar10	1058	// Внутренняя переменная var10
#define var100	BUFFER[3503]	// Внутренняя переменная var100
#define idvar100	1059	// Внутренняя переменная var100
#define var101	BUFFER[3512]	// Внутренняя переменная var101
#define idvar101	1060	// Внутренняя переменная var101
#define var102	BUFFER[3517]	// Внутренняя переменная var102
#define idvar102	1061	// Внутренняя переменная var102
#define var103	BUFFER[3519]	// Внутренняя переменная var103
#define idvar103	1062	// Внутренняя переменная var103
#define var104	BUFFER[3521]	// Внутренняя переменная var104
#define idvar104	1063	// Внутренняя переменная var104
#define var105	BUFFER[3523]	// Внутренняя переменная var105
#define idvar105	1064	// Внутренняя переменная var105
#define var106	BUFFER[3525]	// Внутренняя переменная var106
#define idvar106	1065	// Внутренняя переменная var106
#define var107	BUFFER[3527]	// Внутренняя переменная var107
#define idvar107	1066	// Внутренняя переменная var107
#define var108	BUFFER[3529]	// Внутренняя переменная var108
#define idvar108	1067	// Внутренняя переменная var108
#define var109	BUFFER[3531]	// Внутренняя переменная var109
#define idvar109	1068	// Внутренняя переменная var109
#define var11	BUFFER[3533]	// Внутренняя переменная var11
#define idvar11	1069	// Внутренняя переменная var11
#define var110	BUFFER[3538]	// Внутренняя переменная var110
#define idvar110	1070	// Внутренняя переменная var110
#define var111	BUFFER[3540]	// Внутренняя переменная var111
#define idvar111	1071	// Внутренняя переменная var111
#define var112	BUFFER[3542]	// Внутренняя переменная var112
#define idvar112	1072	// Внутренняя переменная var112
#define var113	BUFFER[3544]	// Внутренняя переменная var113
#define idvar113	1073	// Внутренняя переменная var113
#define var114	BUFFER[3549]	// Внутренняя переменная var114
#define idvar114	1074	// Внутренняя переменная var114
#define var115	BUFFER[3551]	// Внутренняя переменная var115
#define idvar115	1075	// Внутренняя переменная var115
#define var116	BUFFER[3553]	// Внутренняя переменная var116
#define idvar116	1076	// Внутренняя переменная var116
#define var117	BUFFER[3562]	// Внутренняя переменная var117
#define idvar117	1077	// Внутренняя переменная var117
#define var118	BUFFER[3567]	// Внутренняя переменная var118
#define idvar118	1078	// Внутренняя переменная var118
#define var119	BUFFER[3576]	// Внутренняя переменная var119
#define idvar119	1079	// Внутренняя переменная var119
#define var12	BUFFER[3581]	// Внутренняя переменная var12
#define idvar12	1080	// Внутренняя переменная var12
#define var120	BUFFER[3583]	// Внутренняя переменная var120
#define idvar120	1081	// Внутренняя переменная var120
#define var121	BUFFER[3585]	// Внутренняя переменная var121
#define idvar121	1082	// Внутренняя переменная var121
#define var122	BUFFER[3587]	// Внутренняя переменная var122
#define idvar122	1083	// Внутренняя переменная var122
#define var123	BUFFER[3589]	// Внутренняя переменная var123
#define idvar123	1084	// Внутренняя переменная var123
#define var124	BUFFER[3591]	// Внутренняя переменная var124
#define idvar124	1085	// Внутренняя переменная var124
#define var125	BUFFER[3593]	// Внутренняя переменная var125
#define idvar125	1086	// Внутренняя переменная var125
#define var126	BUFFER[3595]	// Внутренняя переменная var126
#define idvar126	1087	// Внутренняя переменная var126
#define var127	BUFFER[3597]	// Внутренняя переменная var127
#define idvar127	1088	// Внутренняя переменная var127
#define var128	BUFFER[3599]	// Внутренняя переменная var128
#define idvar128	1089	// Внутренняя переменная var128
#define var129	BUFFER[3601]	// Внутренняя переменная var129
#define idvar129	1090	// Внутренняя переменная var129
#define var13	BUFFER[3603]	// Внутренняя переменная var13
#define idvar13	1091	// Внутренняя переменная var13
#define var130	BUFFER[3605]	// Внутренняя переменная var130
#define idvar130	1092	// Внутренняя переменная var130
#define var131	BUFFER[3610]	// Внутренняя переменная var131
#define idvar131	1093	// Внутренняя переменная var131
#define var132	BUFFER[3615]	// Внутренняя переменная var132
#define idvar132	1094	// Внутренняя переменная var132
#define var133	BUFFER[3617]	// Внутренняя переменная var133
#define idvar133	1095	// Внутренняя переменная var133
#define var134	BUFFER[3619]	// Внутренняя переменная var134
#define idvar134	1096	// Внутренняя переменная var134
#define var135	BUFFER[3624]	// Внутренняя переменная var135
#define idvar135	1097	// Внутренняя переменная var135
#define var136	BUFFER[3629]	// Внутренняя переменная var136
#define idvar136	1098	// Внутренняя переменная var136
#define var137	BUFFER[3631]	// Внутренняя переменная var137
#define idvar137	1099	// Внутренняя переменная var137
#define var138	BUFFER[3640]	// Внутренняя переменная var138
#define idvar138	1100	// Внутренняя переменная var138
#define var139	BUFFER[3645]	// Внутренняя переменная var139
#define idvar139	1101	// Внутренняя переменная var139
#define var14	BUFFER[3647]	// Внутренняя переменная var14
#define idvar14	1102	// Внутренняя переменная var14
#define var140	BUFFER[3649]	// Внутренняя переменная var140
#define idvar140	1103	// Внутренняя переменная var140
#define var141	BUFFER[3651]	// Внутренняя переменная var141
#define idvar141	1104	// Внутренняя переменная var141
#define var142	BUFFER[3660]	// Внутренняя переменная var142
#define idvar142	1105	// Внутренняя переменная var142
#define var143	BUFFER[3665]	// Внутренняя переменная var143
#define idvar143	1106	// Внутренняя переменная var143
#define var144	BUFFER[3667]	// Внутренняя переменная var144
#define idvar144	1107	// Внутренняя переменная var144
#define var145	BUFFER[3672]	// Внутренняя переменная var145
#define idvar145	1108	// Внутренняя переменная var145
#define var146	BUFFER[3677]	// Внутренняя переменная var146
#define idvar146	1109	// Внутренняя переменная var146
#define var147	BUFFER[3679]	// Внутренняя переменная var147
#define idvar147	1110	// Внутренняя переменная var147
#define var148	BUFFER[3681]	// Внутренняя переменная var148
#define idvar148	1111	// Внутренняя переменная var148
#define var149	BUFFER[3683]	// Внутренняя переменная var149
#define idvar149	1112	// Внутренняя переменная var149
#define var15	BUFFER[3692]	// Внутренняя переменная var15
#define idvar15	1113	// Внутренняя переменная var15
#define var150	BUFFER[3694]	// Внутренняя переменная var150
#define idvar150	1114	// Внутренняя переменная var150
#define var151	BUFFER[3699]	// Внутренняя переменная var151
#define idvar151	1115	// Внутренняя переменная var151
#define var152	BUFFER[3701]	// Внутренняя переменная var152
#define idvar152	1116	// Внутренняя переменная var152
#define var153	BUFFER[3703]	// Внутренняя переменная var153
#define idvar153	1117	// Внутренняя переменная var153
#define var154	BUFFER[3705]	// Внутренняя переменная var154
#define idvar154	1118	// Внутренняя переменная var154
#define var155	BUFFER[3710]	// Внутренняя переменная var155
#define idvar155	1119	// Внутренняя переменная var155
#define var156	BUFFER[3715]	// Внутренняя переменная var156
#define idvar156	1120	// Внутренняя переменная var156
#define var157	BUFFER[3720]	// Внутренняя переменная var157
#define idvar157	1121	// Внутренняя переменная var157
#define var158	BUFFER[3725]	// Внутренняя переменная var158
#define idvar158	1122	// Внутренняя переменная var158
#define var159	BUFFER[3730]	// Внутренняя переменная var159
#define idvar159	1123	// Внутренняя переменная var159
#define var16	BUFFER[3735]	// Внутренняя переменная var16
#define idvar16	1124	// Внутренняя переменная var16
#define var160	BUFFER[3737]	// Внутренняя переменная var160
#define idvar160	1125	// Внутренняя переменная var160
#define var161	BUFFER[3742]	// Внутренняя переменная var161
#define idvar161	1126	// Внутренняя переменная var161
#define var162	BUFFER[3747]	// Внутренняя переменная var162
#define idvar162	1127	// Внутренняя переменная var162
#define var163	BUFFER[3752]	// Внутренняя переменная var163
#define idvar163	1128	// Внутренняя переменная var163
#define var164	BUFFER[3757]	// Внутренняя переменная var164
#define idvar164	1129	// Внутренняя переменная var164
#define var165	BUFFER[3762]	// Внутренняя переменная var165
#define idvar165	1130	// Внутренняя переменная var165
#define var166	BUFFER[3764]	// Внутренняя переменная var166
#define idvar166	1131	// Внутренняя переменная var166
#define var167	BUFFER[3766]	// Внутренняя переменная var167
#define idvar167	1132	// Внутренняя переменная var167
#define var168	BUFFER[3771]	// Внутренняя переменная var168
#define idvar168	1133	// Внутренняя переменная var168
#define var169	BUFFER[3776]	// Внутренняя переменная var169
#define idvar169	1134	// Внутренняя переменная var169
#define var17	BUFFER[3781]	// Внутренняя переменная var17
#define idvar17	1135	// Внутренняя переменная var17
#define var170	BUFFER[3783]	// Внутренняя переменная var170
#define idvar170	1136	// Внутренняя переменная var170
#define var171	BUFFER[3788]	// Внутренняя переменная var171
#define idvar171	1137	// Внутренняя переменная var171
#define var172	BUFFER[3790]	// Внутренняя переменная var172
#define idvar172	1138	// Внутренняя переменная var172
#define var173	BUFFER[3792]	// Внутренняя переменная var173
#define idvar173	1139	// Внутренняя переменная var173
#define var174	BUFFER[3794]	// Внутренняя переменная var174
#define idvar174	1140	// Внутренняя переменная var174
#define var175	BUFFER[3796]	// Внутренняя переменная var175
#define idvar175	1141	// Внутренняя переменная var175
#define var176	BUFFER[3801]	// Внутренняя переменная var176
#define idvar176	1142	// Внутренняя переменная var176
#define var177	BUFFER[3803]	// Внутренняя переменная var177
#define idvar177	1143	// Внутренняя переменная var177
#define var178	BUFFER[3808]	// Внутренняя переменная var178
#define idvar178	1144	// Внутренняя переменная var178
#define var179	BUFFER[3810]	// Внутренняя переменная var179
#define idvar179	1145	// Внутренняя переменная var179
#define var18	BUFFER[3812]	// Внутренняя переменная var18
#define idvar18	1146	// Внутренняя переменная var18
#define var180	BUFFER[3814]	// Внутренняя переменная var180
#define idvar180	1147	// Внутренняя переменная var180
#define var181	BUFFER[3816]	// Внутренняя переменная var181
#define idvar181	1148	// Внутренняя переменная var181
#define var182	BUFFER[3818]	// Внутренняя переменная var182
#define idvar182	1149	// Внутренняя переменная var182
#define var183	BUFFER[3823]	// Внутренняя переменная var183
#define idvar183	1150	// Внутренняя переменная var183
#define var184	BUFFER[3825]	// Внутренняя переменная var184
#define idvar184	1151	// Внутренняя переменная var184
#define var185	BUFFER[3827]	// Внутренняя переменная var185
#define idvar185	1152	// Внутренняя переменная var185
#define var186	BUFFER[3829]	// Внутренняя переменная var186
#define idvar186	1153	// Внутренняя переменная var186
#define var187	BUFFER[3831]	// Внутренняя переменная var187
#define idvar187	1154	// Внутренняя переменная var187
#define var188	BUFFER[3833]	// Внутренняя переменная var188
#define idvar188	1155	// Внутренняя переменная var188
#define var189	BUFFER[3835]	// Внутренняя переменная var189
#define idvar189	1156	// Внутренняя переменная var189
#define var19	BUFFER[3837]	// Внутренняя переменная var19
#define idvar19	1157	// Внутренняя переменная var19
#define var190	BUFFER[3839]	// Внутренняя переменная var190
#define idvar190	1158	// Внутренняя переменная var190
#define var191	BUFFER[3841]	// Внутренняя переменная var191
#define idvar191	1159	// Внутренняя переменная var191
#define var192	BUFFER[3843]	// Внутренняя переменная var192
#define idvar192	1160	// Внутренняя переменная var192
#define var193	BUFFER[3845]	// Внутренняя переменная var193
#define idvar193	1161	// Внутренняя переменная var193
#define var194	BUFFER[3847]	// Внутренняя переменная var194
#define idvar194	1162	// Внутренняя переменная var194
#define var195	BUFFER[3849]	// Внутренняя переменная var195
#define idvar195	1163	// Внутренняя переменная var195
#define var196	BUFFER[3851]	// Внутренняя переменная var196
#define idvar196	1164	// Внутренняя переменная var196
#define var197	BUFFER[3853]	// Внутренняя переменная var197
#define idvar197	1165	// Внутренняя переменная var197
#define var198	BUFFER[3855]	// Внутренняя переменная var198
#define idvar198	1166	// Внутренняя переменная var198
#define var199	BUFFER[3857]	// Внутренняя переменная var199
#define idvar199	1167	// Внутренняя переменная var199
#define var2	BUFFER[3859]	// Внутренняя переменная var2
#define idvar2	1168	// Внутренняя переменная var2
#define var20	BUFFER[3861]	// Внутренняя переменная var20
#define idvar20	1169	// Внутренняя переменная var20
#define var200	BUFFER[3863]	// Внутренняя переменная var200
#define idvar200	1170	// Внутренняя переменная var200
#define var201	BUFFER[3865]	// Внутренняя переменная var201
#define idvar201	1171	// Внутренняя переменная var201
#define var202	BUFFER[3867]	// Внутренняя переменная var202
#define idvar202	1172	// Внутренняя переменная var202
#define var203	BUFFER[3869]	// Внутренняя переменная var203
#define idvar203	1173	// Внутренняя переменная var203
#define var204	BUFFER[3871]	// Внутренняя переменная var204
#define idvar204	1174	// Внутренняя переменная var204
#define var205	BUFFER[3873]	// Внутренняя переменная var205
#define idvar205	1175	// Внутренняя переменная var205
#define var206	BUFFER[3875]	// Внутренняя переменная var206
#define idvar206	1176	// Внутренняя переменная var206
#define var207	BUFFER[3877]	// Внутренняя переменная var207
#define idvar207	1177	// Внутренняя переменная var207
#define var208	BUFFER[3879]	// Внутренняя переменная var208
#define idvar208	1178	// Внутренняя переменная var208
#define var209	BUFFER[3881]	// Внутренняя переменная var209
#define idvar209	1179	// Внутренняя переменная var209
#define var21	BUFFER[3883]	// Внутренняя переменная var21
#define idvar21	1180	// Внутренняя переменная var21
#define var210	BUFFER[3885]	// Внутренняя переменная var210
#define idvar210	1181	// Внутренняя переменная var210
#define var211	BUFFER[3887]	// Внутренняя переменная var211
#define idvar211	1182	// Внутренняя переменная var211
#define var212	BUFFER[3889]	// Внутренняя переменная var212
#define idvar212	1183	// Внутренняя переменная var212
#define var213	BUFFER[3891]	// Внутренняя переменная var213
#define idvar213	1184	// Внутренняя переменная var213
#define var214	BUFFER[3893]	// Внутренняя переменная var214
#define idvar214	1185	// Внутренняя переменная var214
#define var215	BUFFER[3895]	// Внутренняя переменная var215
#define idvar215	1186	// Внутренняя переменная var215
#define var216	BUFFER[3897]	// Внутренняя переменная var216
#define idvar216	1187	// Внутренняя переменная var216
#define var217	BUFFER[3899]	// Внутренняя переменная var217
#define idvar217	1188	// Внутренняя переменная var217
#define var218	BUFFER[3901]	// Внутренняя переменная var218
#define idvar218	1189	// Внутренняя переменная var218
#define var219	BUFFER[3903]	// Внутренняя переменная var219
#define idvar219	1190	// Внутренняя переменная var219
#define var22	BUFFER[3905]	// Внутренняя переменная var22
#define idvar22	1191	// Внутренняя переменная var22
#define var220	BUFFER[3907]	// Внутренняя переменная var220
#define idvar220	1192	// Внутренняя переменная var220
#define var221	BUFFER[3909]	// Внутренняя переменная var221
#define idvar221	1193	// Внутренняя переменная var221
#define var222	BUFFER[3914]	// Внутренняя переменная var222
#define idvar222	1194	// Внутренняя переменная var222
#define var223	BUFFER[3919]	// Внутренняя переменная var223
#define idvar223	1195	// Внутренняя переменная var223
#define var224	BUFFER[3924]	// Внутренняя переменная var224
#define idvar224	1196	// Внутренняя переменная var224
#define var225	BUFFER[3929]	// Внутренняя переменная var225
#define idvar225	1197	// Внутренняя переменная var225
#define var226	BUFFER[3934]	// Внутренняя переменная var226
#define idvar226	1198	// Внутренняя переменная var226
#define var227	BUFFER[3939]	// Внутренняя переменная var227
#define idvar227	1199	// Внутренняя переменная var227
#define var228	BUFFER[3944]	// Внутренняя переменная var228
#define idvar228	1200	// Внутренняя переменная var228
#define var229	BUFFER[3949]	// Внутренняя переменная var229
#define idvar229	1201	// Внутренняя переменная var229
#define var23	BUFFER[3954]	// Внутренняя переменная var23
#define idvar23	1202	// Внутренняя переменная var23
#define var230	BUFFER[3956]	// Внутренняя переменная var230
#define idvar230	1203	// Внутренняя переменная var230
#define var231	BUFFER[3958]	// Внутренняя переменная var231
#define idvar231	1204	// Внутренняя переменная var231
#define var232	BUFFER[3960]	// Внутренняя переменная var232
#define idvar232	1205	// Внутренняя переменная var232
#define var233	BUFFER[3965]	// Внутренняя переменная var233
#define idvar233	1206	// Внутренняя переменная var233
#define var234	BUFFER[3970]	// Внутренняя переменная var234
#define idvar234	1207	// Внутренняя переменная var234
#define var235	BUFFER[3975]	// Внутренняя переменная var235
#define idvar235	1208	// Внутренняя переменная var235
#define var236	BUFFER[3980]	// Внутренняя переменная var236
#define idvar236	1209	// Внутренняя переменная var236
#define var237	BUFFER[3985]	// Внутренняя переменная var237
#define idvar237	1210	// Внутренняя переменная var237
#define var238	BUFFER[3990]	// Внутренняя переменная var238
#define idvar238	1211	// Внутренняя переменная var238
#define var239	BUFFER[3995]	// Внутренняя переменная var239
#define idvar239	1212	// Внутренняя переменная var239
#define var24	BUFFER[4000]	// Внутренняя переменная var24
#define idvar24	1213	// Внутренняя переменная var24
#define var240	BUFFER[4002]	// Внутренняя переменная var240
#define idvar240	1214	// Внутренняя переменная var240
#define var241	BUFFER[4007]	// Внутренняя переменная var241
#define idvar241	1215	// Внутренняя переменная var241
#define var242	BUFFER[4012]	// Внутренняя переменная var242
#define idvar242	1216	// Внутренняя переменная var242
#define var243	BUFFER[4017]	// Внутренняя переменная var243
#define idvar243	1217	// Внутренняя переменная var243
#define var244	BUFFER[4022]	// Внутренняя переменная var244
#define idvar244	1218	// Внутренняя переменная var244
#define var245	BUFFER[4027]	// Внутренняя переменная var245
#define idvar245	1219	// Внутренняя переменная var245
#define var246	BUFFER[4029]	// Внутренняя переменная var246
#define idvar246	1220	// Внутренняя переменная var246
#define var247	BUFFER[4031]	// Внутренняя переменная var247
#define idvar247	1221	// Внутренняя переменная var247
#define var248	BUFFER[4033]	// Внутренняя переменная var248
#define idvar248	1222	// Внутренняя переменная var248
#define var249	BUFFER[4035]	// Внутренняя переменная var249
#define idvar249	1223	// Внутренняя переменная var249
#define var25	BUFFER[4037]	// Внутренняя переменная var25
#define idvar25	1224	// Внутренняя переменная var25
#define var250	BUFFER[4039]	// Внутренняя переменная var250
#define idvar250	1225	// Внутренняя переменная var250
#define var251	BUFFER[4041]	// Внутренняя переменная var251
#define idvar251	1226	// Внутренняя переменная var251
#define var252	BUFFER[4043]	// Внутренняя переменная var252
#define idvar252	1227	// Внутренняя переменная var252
#define var253	BUFFER[4045]	// Внутренняя переменная var253
#define idvar253	1228	// Внутренняя переменная var253
#define var254	BUFFER[4047]	// Внутренняя переменная var254
#define idvar254	1229	// Внутренняя переменная var254
#define var255	BUFFER[4049]	// Внутренняя переменная var255
#define idvar255	1230	// Внутренняя переменная var255
#define var256	BUFFER[4051]	// Внутренняя переменная var256
#define idvar256	1231	// Внутренняя переменная var256
#define var257	BUFFER[4053]	// Внутренняя переменная var257
#define idvar257	1232	// Внутренняя переменная var257
#define var258	BUFFER[4055]	// Внутренняя переменная var258
#define idvar258	1233	// Внутренняя переменная var258
#define var259	BUFFER[4057]	// Внутренняя переменная var259
#define idvar259	1234	// Внутренняя переменная var259
#define var26	BUFFER[4059]	// Внутренняя переменная var26
#define idvar26	1235	// Внутренняя переменная var26
#define var260	BUFFER[4061]	// Внутренняя переменная var260
#define idvar260	1236	// Внутренняя переменная var260
#define var261	BUFFER[4063]	// Внутренняя переменная var261
#define idvar261	1237	// Внутренняя переменная var261
#define var262	BUFFER[4065]	// Внутренняя переменная var262
#define idvar262	1238	// Внутренняя переменная var262
#define var263	BUFFER[4067]	// Внутренняя переменная var263
#define idvar263	1239	// Внутренняя переменная var263
#define var264	BUFFER[4069]	// Внутренняя переменная var264
#define idvar264	1240	// Внутренняя переменная var264
#define var265	BUFFER[4071]	// Внутренняя переменная var265
#define idvar265	1241	// Внутренняя переменная var265
#define var266	BUFFER[4073]	// Внутренняя переменная var266
#define idvar266	1242	// Внутренняя переменная var266
#define var267	BUFFER[4075]	// Внутренняя переменная var267
#define idvar267	1243	// Внутренняя переменная var267
#define var268	BUFFER[4077]	// Внутренняя переменная var268
#define idvar268	1244	// Внутренняя переменная var268
#define var269	BUFFER[4079]	// Внутренняя переменная var269
#define idvar269	1245	// Внутренняя переменная var269
#define var27	BUFFER[4084]	// Внутренняя переменная var27
#define idvar27	1246	// Внутренняя переменная var27
#define var270	BUFFER[4086]	// Внутренняя переменная var270
#define idvar270	1247	// Внутренняя переменная var270
#define var271	BUFFER[4088]	// Внутренняя переменная var271
#define idvar271	1248	// Внутренняя переменная var271
#define var272	BUFFER[4090]	// Внутренняя переменная var272
#define idvar272	1249	// Внутренняя переменная var272
#define var273	BUFFER[4095]	// Внутренняя переменная var273
#define idvar273	1250	// Внутренняя переменная var273
#define var274	BUFFER[4097]	// Внутренняя переменная var274
#define idvar274	1251	// Внутренняя переменная var274
#define var275	BUFFER[4099]	// Внутренняя переменная var275
#define idvar275	1252	// Внутренняя переменная var275
#define var276	BUFFER[4101]	// Внутренняя переменная var276
#define idvar276	1253	// Внутренняя переменная var276
#define var277	BUFFER[4103]	// Внутренняя переменная var277
#define idvar277	1254	// Внутренняя переменная var277
#define var278	BUFFER[4105]	// Внутренняя переменная var278
#define idvar278	1255	// Внутренняя переменная var278
#define var279	BUFFER[4107]	// Внутренняя переменная var279
#define idvar279	1256	// Внутренняя переменная var279
#define var28	BUFFER[4109]	// Внутренняя переменная var28
#define idvar28	1257	// Внутренняя переменная var28
#define var280	BUFFER[4111]	// Внутренняя переменная var280
#define idvar280	1258	// Внутренняя переменная var280
#define var281	BUFFER[4113]	// Внутренняя переменная var281
#define idvar281	1259	// Внутренняя переменная var281
#define var282	BUFFER[4118]	// Внутренняя переменная var282
#define idvar282	1260	// Внутренняя переменная var282
#define var283	BUFFER[4123]	// Внутренняя переменная var283
#define idvar283	1261	// Внутренняя переменная var283
#define var284	BUFFER[4128]	// Внутренняя переменная var284
#define idvar284	1262	// Внутренняя переменная var284
#define var285	BUFFER[4133]	// Внутренняя переменная var285
#define idvar285	1263	// Внутренняя переменная var285
#define var286	BUFFER[4135]	// Внутренняя переменная var286
#define idvar286	1264	// Внутренняя переменная var286
#define var287	BUFFER[4140]	// Внутренняя переменная var287
#define idvar287	1265	// Внутренняя переменная var287
#define var288	BUFFER[4145]	// Внутренняя переменная var288
#define idvar288	1266	// Внутренняя переменная var288
#define var289	BUFFER[4150]	// Внутренняя переменная var289
#define idvar289	1267	// Внутренняя переменная var289
#define var29	BUFFER[4155]	// Внутренняя переменная var29
#define idvar29	1268	// Внутренняя переменная var29
#define var290	BUFFER[4157]	// Внутренняя переменная var290
#define idvar290	1269	// Внутренняя переменная var290
#define var291	BUFFER[4159]	// Внутренняя переменная var291
#define idvar291	1270	// Внутренняя переменная var291
#define var292	BUFFER[4161]	// Внутренняя переменная var292
#define idvar292	1271	// Внутренняя переменная var292
#define var293	BUFFER[4163]	// Внутренняя переменная var293
#define idvar293	1272	// Внутренняя переменная var293
#define var294	BUFFER[4165]	// Внутренняя переменная var294
#define idvar294	1273	// Внутренняя переменная var294
#define var295	BUFFER[4167]	// Внутренняя переменная var295
#define idvar295	1274	// Внутренняя переменная var295
#define var296	BUFFER[4172]	// Внутренняя переменная var296
#define idvar296	1275	// Внутренняя переменная var296
#define var297	BUFFER[4177]	// Внутренняя переменная var297
#define idvar297	1276	// Внутренняя переменная var297
#define var298	BUFFER[4179]	// Внутренняя переменная var298
#define idvar298	1277	// Внутренняя переменная var298
#define var299	BUFFER[4181]	// Внутренняя переменная var299
#define idvar299	1278	// Внутренняя переменная var299
#define var3	BUFFER[4183]	// Внутренняя переменная var3
#define idvar3	1279	// Внутренняя переменная var3
#define var30	BUFFER[4188]	// Внутренняя переменная var30
#define idvar30	1280	// Внутренняя переменная var30
#define var300	BUFFER[4190]	// Внутренняя переменная var300
#define idvar300	1281	// Внутренняя переменная var300
#define var301	BUFFER[4192]	// Внутренняя переменная var301
#define idvar301	1282	// Внутренняя переменная var301
#define var302	BUFFER[4194]	// Внутренняя переменная var302
#define idvar302	1283	// Внутренняя переменная var302
#define var303	BUFFER[4199]	// Внутренняя переменная var303
#define idvar303	1284	// Внутренняя переменная var303
#define var304	BUFFER[4204]	// Внутренняя переменная var304
#define idvar304	1285	// Внутренняя переменная var304
#define var305	BUFFER[4206]	// Внутренняя переменная var305
#define idvar305	1286	// Внутренняя переменная var305
#define var306	BUFFER[4208]	// Внутренняя переменная var306
#define idvar306	1287	// Внутренняя переменная var306
#define var307	BUFFER[4210]	// Внутренняя переменная var307
#define idvar307	1288	// Внутренняя переменная var307
#define var308	BUFFER[4212]	// Внутренняя переменная var308
#define idvar308	1289	// Внутренняя переменная var308
#define var309	BUFFER[4214]	// Внутренняя переменная var309
#define idvar309	1290	// Внутренняя переменная var309
#define var31	BUFFER[4216]	// Внутренняя переменная var31
#define idvar31	1291	// Внутренняя переменная var31
#define var310	BUFFER[4218]	// Внутренняя переменная var310
#define idvar310	1292	// Внутренняя переменная var310
#define var311	BUFFER[4223]	// Внутренняя переменная var311
#define idvar311	1293	// Внутренняя переменная var311
#define var312	BUFFER[4228]	// Внутренняя переменная var312
#define idvar312	1294	// Внутренняя переменная var312
#define var313	BUFFER[4230]	// Внутренняя переменная var313
#define idvar313	1295	// Внутренняя переменная var313
#define var314	BUFFER[4232]	// Внутренняя переменная var314
#define idvar314	1296	// Внутренняя переменная var314
#define var315	BUFFER[4234]	// Внутренняя переменная var315
#define idvar315	1297	// Внутренняя переменная var315
#define var316	BUFFER[4236]	// Внутренняя переменная var316
#define idvar316	1298	// Внутренняя переменная var316
#define var317	BUFFER[4238]	// Внутренняя переменная var317
#define idvar317	1299	// Внутренняя переменная var317
#define var318	BUFFER[4240]	// Внутренняя переменная var318
#define idvar318	1300	// Внутренняя переменная var318
#define var319	BUFFER[4245]	// Внутренняя переменная var319
#define idvar319	1301	// Внутренняя переменная var319
#define var32	BUFFER[4250]	// Внутренняя переменная var32
#define idvar32	1302	// Внутренняя переменная var32
#define var320	BUFFER[4252]	// Внутренняя переменная var320
#define idvar320	1303	// Внутренняя переменная var320
#define var321	BUFFER[4254]	// Внутренняя переменная var321
#define idvar321	1304	// Внутренняя переменная var321
#define var322	BUFFER[4256]	// Внутренняя переменная var322
#define idvar322	1305	// Внутренняя переменная var322
#define var323	BUFFER[4258]	// Внутренняя переменная var323
#define idvar323	1306	// Внутренняя переменная var323
#define var324	BUFFER[4260]	// Внутренняя переменная var324
#define idvar324	1307	// Внутренняя переменная var324
#define var325	BUFFER[4262]	// Внутренняя переменная var325
#define idvar325	1308	// Внутренняя переменная var325
#define var326	BUFFER[4267]	// Внутренняя переменная var326
#define idvar326	1309	// Внутренняя переменная var326
#define var327	BUFFER[4272]	// Внутренняя переменная var327
#define idvar327	1310	// Внутренняя переменная var327
#define var328	BUFFER[4274]	// Внутренняя переменная var328
#define idvar328	1311	// Внутренняя переменная var328
#define var329	BUFFER[4276]	// Внутренняя переменная var329
#define idvar329	1312	// Внутренняя переменная var329
#define var33	BUFFER[4278]	// Внутренняя переменная var33
#define idvar33	1313	// Внутренняя переменная var33
#define var330	BUFFER[4280]	// Внутренняя переменная var330
#define idvar330	1314	// Внутренняя переменная var330
#define var331	BUFFER[4282]	// Внутренняя переменная var331
#define idvar331	1315	// Внутренняя переменная var331
#define var332	BUFFER[4284]	// Внутренняя переменная var332
#define idvar332	1316	// Внутренняя переменная var332
#define var333	BUFFER[4289]	// Внутренняя переменная var333
#define idvar333	1317	// Внутренняя переменная var333
#define var334	BUFFER[4294]	// Внутренняя переменная var334
#define idvar334	1318	// Внутренняя переменная var334
#define var335	BUFFER[4299]	// Внутренняя переменная var335
#define idvar335	1319	// Внутренняя переменная var335
#define var336	BUFFER[4304]	// Внутренняя переменная var336
#define idvar336	1320	// Внутренняя переменная var336
#define var337	BUFFER[4306]	// Внутренняя переменная var337
#define idvar337	1321	// Внутренняя переменная var337
#define var338	BUFFER[4311]	// Внутренняя переменная var338
#define idvar338	1322	// Внутренняя переменная var338
#define var34	BUFFER[4316]	// Внутренняя переменная var34
#define idvar34	1323	// Внутренняя переменная var34
#define var35	BUFFER[4318]	// Внутренняя переменная var35
#define idvar35	1324	// Внутренняя переменная var35
#define var36	BUFFER[4320]	// Внутренняя переменная var36
#define idvar36	1325	// Внутренняя переменная var36
#define var37	BUFFER[4322]	// Внутренняя переменная var37
#define idvar37	1326	// Внутренняя переменная var37
#define var38	BUFFER[4324]	// Внутренняя переменная var38
#define idvar38	1327	// Внутренняя переменная var38
#define var39	BUFFER[4326]	// Внутренняя переменная var39
#define idvar39	1328	// Внутренняя переменная var39
#define var4	BUFFER[4328]	// Внутренняя переменная var4
#define idvar4	1329	// Внутренняя переменная var4
#define var40	BUFFER[4330]	// Внутренняя переменная var40
#define idvar40	1330	// Внутренняя переменная var40
#define var41	BUFFER[4332]	// Внутренняя переменная var41
#define idvar41	1331	// Внутренняя переменная var41
#define var42	BUFFER[4334]	// Внутренняя переменная var42
#define idvar42	1332	// Внутренняя переменная var42
#define var43	BUFFER[4336]	// Внутренняя переменная var43
#define idvar43	1333	// Внутренняя переменная var43
#define var44	BUFFER[4338]	// Внутренняя переменная var44
#define idvar44	1334	// Внутренняя переменная var44
#define var45	BUFFER[4343]	// Внутренняя переменная var45
#define idvar45	1335	// Внутренняя переменная var45
#define var46	BUFFER[4345]	// Внутренняя переменная var46
#define idvar46	1336	// Внутренняя переменная var46
#define var47	BUFFER[4347]	// Внутренняя переменная var47
#define idvar47	1337	// Внутренняя переменная var47
#define var48	BUFFER[4349]	// Внутренняя переменная var48
#define idvar48	1338	// Внутренняя переменная var48
#define var49	BUFFER[4351]	// Внутренняя переменная var49
#define idvar49	1339	// Внутренняя переменная var49
#define var5	BUFFER[4353]	// Внутренняя переменная var5
#define idvar5	1340	// Внутренняя переменная var5
#define var50	BUFFER[4355]	// Внутренняя переменная var50
#define idvar50	1341	// Внутренняя переменная var50
#define var51	BUFFER[4357]	// Внутренняя переменная var51
#define idvar51	1342	// Внутренняя переменная var51
#define var52	BUFFER[4359]	// Внутренняя переменная var52
#define idvar52	1343	// Внутренняя переменная var52
#define var53	BUFFER[4361]	// Внутренняя переменная var53
#define idvar53	1344	// Внутренняя переменная var53
#define var54	BUFFER[4363]	// Внутренняя переменная var54
#define idvar54	1345	// Внутренняя переменная var54
#define var55	BUFFER[4365]	// Внутренняя переменная var55
#define idvar55	1346	// Внутренняя переменная var55
#define var56	BUFFER[4367]	// Внутренняя переменная var56
#define idvar56	1347	// Внутренняя переменная var56
#define var57	BUFFER[4369]	// Внутренняя переменная var57
#define idvar57	1348	// Внутренняя переменная var57
#define var58	BUFFER[4371]	// Внутренняя переменная var58
#define idvar58	1349	// Внутренняя переменная var58
#define var59	BUFFER[4380]	// Внутренняя переменная var59
#define idvar59	1350	// Внутренняя переменная var59
#define var6	BUFFER[4385]	// Внутренняя переменная var6
#define idvar6	1351	// Внутренняя переменная var6
#define var60	BUFFER[4390]	// Внутренняя переменная var60
#define idvar60	1352	// Внутренняя переменная var60
#define var61	BUFFER[4399]	// Внутренняя переменная var61
#define idvar61	1353	// Внутренняя переменная var61
#define var62	BUFFER[4404]	// Внутренняя переменная var62
#define idvar62	1354	// Внутренняя переменная var62
#define var63	BUFFER[4406]	// Внутренняя переменная var63
#define idvar63	1355	// Внутренняя переменная var63
#define var64	BUFFER[4408]	// Внутренняя переменная var64
#define idvar64	1356	// Внутренняя переменная var64
#define var65	BUFFER[4410]	// Внутренняя переменная var65
#define idvar65	1357	// Внутренняя переменная var65
#define var66	BUFFER[4412]	// Внутренняя переменная var66
#define idvar66	1358	// Внутренняя переменная var66
#define var67	BUFFER[4414]	// Внутренняя переменная var67
#define idvar67	1359	// Внутренняя переменная var67
#define var68	BUFFER[4416]	// Внутренняя переменная var68
#define idvar68	1360	// Внутренняя переменная var68
#define var69	BUFFER[4418]	// Внутренняя переменная var69
#define idvar69	1361	// Внутренняя переменная var69
#define var7	BUFFER[4420]	// Внутренняя переменная var7
#define idvar7	1362	// Внутренняя переменная var7
#define var70	BUFFER[4425]	// Внутренняя переменная var70
#define idvar70	1363	// Внутренняя переменная var70
#define var71	BUFFER[4427]	// Внутренняя переменная var71
#define idvar71	1364	// Внутренняя переменная var71
#define var72	BUFFER[4429]	// Внутренняя переменная var72
#define idvar72	1365	// Внутренняя переменная var72
#define var73	BUFFER[4431]	// Внутренняя переменная var73
#define idvar73	1366	// Внутренняя переменная var73
#define var74	BUFFER[4433]	// Внутренняя переменная var74
#define idvar74	1367	// Внутренняя переменная var74
#define var75	BUFFER[4435]	// Внутренняя переменная var75
#define idvar75	1368	// Внутренняя переменная var75
#define var76	BUFFER[4437]	// Внутренняя переменная var76
#define idvar76	1369	// Внутренняя переменная var76
#define var77	BUFFER[4439]	// Внутренняя переменная var77
#define idvar77	1370	// Внутренняя переменная var77
#define var78	BUFFER[4441]	// Внутренняя переменная var78
#define idvar78	1371	// Внутренняя переменная var78
#define var79	BUFFER[4443]	// Внутренняя переменная var79
#define idvar79	1372	// Внутренняя переменная var79
#define var8	BUFFER[4445]	// Внутренняя переменная var8
#define idvar8	1373	// Внутренняя переменная var8
#define var80	BUFFER[4450]	// Внутренняя переменная var80
#define idvar80	1374	// Внутренняя переменная var80
#define var81	BUFFER[4452]	// Внутренняя переменная var81
#define idvar81	1375	// Внутренняя переменная var81
#define var82	BUFFER[4454]	// Внутренняя переменная var82
#define idvar82	1376	// Внутренняя переменная var82
#define var83	BUFFER[4456]	// Внутренняя переменная var83
#define idvar83	1377	// Внутренняя переменная var83
#define var84	BUFFER[4458]	// Внутренняя переменная var84
#define idvar84	1378	// Внутренняя переменная var84
#define var85	BUFFER[4460]	// Внутренняя переменная var85
#define idvar85	1379	// Внутренняя переменная var85
#define var86	BUFFER[4462]	// Внутренняя переменная var86
#define idvar86	1380	// Внутренняя переменная var86
#define var87	BUFFER[4464]	// Внутренняя переменная var87
#define idvar87	1381	// Внутренняя переменная var87
#define var88	BUFFER[4466]	// Внутренняя переменная var88
#define idvar88	1382	// Внутренняя переменная var88
#define var89	BUFFER[4468]	// Внутренняя переменная var89
#define idvar89	1383	// Внутренняя переменная var89
#define var9	BUFFER[4470]	// Внутренняя переменная var9
#define idvar9	1384	// Внутренняя переменная var9
#define var90	BUFFER[4475]	// Внутренняя переменная var90
#define idvar90	1385	// Внутренняя переменная var90
#define var91	BUFFER[4477]	// Внутренняя переменная var91
#define idvar91	1386	// Внутренняя переменная var91
#define var92	BUFFER[4479]	// Внутренняя переменная var92
#define idvar92	1387	// Внутренняя переменная var92
#define var93	BUFFER[4481]	// Внутренняя переменная var93
#define idvar93	1388	// Внутренняя переменная var93
#define var94	BUFFER[4483]	// Внутренняя переменная var94
#define idvar94	1389	// Внутренняя переменная var94
#define var95	BUFFER[4485]	// Внутренняя переменная var95
#define idvar95	1390	// Внутренняя переменная var95
#define var96	BUFFER[4487]	// Внутренняя переменная var96
#define idvar96	1391	// Внутренняя переменная var96
#define var97	BUFFER[4492]	// Внутренняя переменная var97
#define idvar97	1392	// Внутренняя переменная var97
#define var98	BUFFER[4497]	// Внутренняя переменная var98
#define idvar98	1393	// Внутренняя переменная var98
#define var99	BUFFER[4502]	// Внутренняя переменная var99
#define idvar99	1394	// Внутренняя переменная var99
#pragma pack(push,1)
static VarCtrl allVariables[]={ 			 //Описание всех переменных
	{1	,3	,1	,&A0IT01IZ1},	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
	{2	,3	,1	,&A0IT02IZ2},	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
	{3	,3	,1	,&A0IT03IRP},	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
	{4	,8	,1	,&A0SN02RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
	{5	,8	,1	,&A0SN03RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
	{6	,8	,1	,&A0SN04RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
	{7	,8	,1	,&A0SN05RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
	{8	,8	,1	,&A0SN06RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
	{9	,8	,1	,&A0SN07RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
	{10	,8	,1	,&A0SN08RIM},	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
	{11	,8	,1	,&A0SR01RIM},	//( - , SCM) Текущая реактивность AЗ1
	{12	,8	,1	,&A0VN01RIM},	//( - , SCM) Период разгона  AЗ1
	{13	,1	,1	,&A0VP81LZZ},	//(do32_pti:110 - K03DO, - ) Давление АЗ1 в норме
	{14	,1	,1	,&A1AD01LDU},	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
	{15	,1	,1	,&A1AD02LDU},	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
	{16	,1	,1	,&A1AD03LDU},	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
	{17	,1	,1	,&A1AD04LDU},	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
	{18	,1	,1	,&A1AD05LDU},	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
	{19	,1	,1	,&A1AD11LDU},	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
	{20	,1	,1	,&A1AD21LDU},	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
	{21	,1	,1	,&A1AD31LDU},	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
	{22	,1	,1	,&A1AD32LDU},	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
	{23	,5	,1	,&A1IC01UDU},	//( - , SDu) Координата штока ББ1
	{24	,1	,1	,&A1IE03LDU},	//( - , SCM) Движение ББ1 вперед (от БУШД)
	{25	,1	,1	,&A1IE04LDU},	//( - , SCM) Движение ББ1 назад (от БУШД)
	{26	,1	,1	,&A1IS11LDU},	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
	{27	,1	,1	,&A1IS11LIM},	//( - , SCM) Магнит ББ1 обесточен
	{28	,1	,1	,&A1IS12LDU},	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
	{29	,1	,1	,&A1IS21LDU},	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
	{30	,1	,1	,&A1IS32LIM},	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
	{31	,1	,1	,&A1VP81LZZ},	//(do32_pti:110 - K01DO, - ) Давление СБРОС ББ1 в норме
	{32	,1	,1	,&A2AD01LDU},	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
	{33	,1	,1	,&A2AD02LDU},	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
	{34	,1	,1	,&A2AD03LDU},	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
	{35	,1	,1	,&A2AD04LDU},	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
	{36	,1	,1	,&A2AD05LDU},	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
	{37	,1	,1	,&A2AD11LDU},	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
	{38	,1	,1	,&A2AD21LDU},	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
	{39	,1	,1	,&A2AD31LDU},	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
	{40	,1	,1	,&A2AD32LDU},	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
	{41	,1	,1	,&A2AD33LDU},	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
	{42	,5	,1	,&A2IC01UDU},	//( - , SDu) Координата штока РБ1
	{43	,3	,1	,&A2IP01IZ1},	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
	{44	,3	,1	,&A2IP01IZ2},	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
	{45	,1	,1	,&A2IS11LDU},	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
	{46	,1	,1	,&A2IS11LIM},	//( - , SCM) Магнит РБ1 обесточен
	{47	,1	,1	,&A2IS12LDU},	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
	{48	,1	,1	,&A2IS21LDU},	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
	{49	,1	,1	,&A2IS32LIM},	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
	{50	,1	,1	,&A2IS33LDU},	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
	{51	,1	,1	,&A2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
	{52	,1	,1	,&A3AD01LDU},	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
	{53	,1	,1	,&A3AD02LDU},	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
	{54	,1	,1	,&A3AD03LDU},	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
	{55	,1	,1	,&A3AD04LDU},	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
	{56	,1	,1	,&A3AD05LDU},	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
	{57	,1	,1	,&A3AD11LDU},	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
	{58	,1	,1	,&A3AD21LDU},	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
	{59	,1	,1	,&A3AD31LDU},	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
	{60	,1	,1	,&A3AD33LDU},	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
	{61	,1	,1	,&A3AD34LDU},	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
	{62	,5	,1	,&A3IC01UDU},	//( - , SDu) Координата штока ИС1
	{63	,3	,1	,&A3IP02IDU},	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
	{64	,1	,1	,&A3IS11LDU},	//(do32_pti:110 - K04DO, - ) Приход на ВУ ИС1
	{65	,1	,1	,&A3IS21LDU},	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
	{66	,1	,1	,&A3IS22LDU},	//(do32_pti:110 - K02DO, - ) Приход на НУП ИС1
	{67	,1	,1	,&A3IS31LDU},	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
	{68	,1	,1	,&A3IS33LDU},	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
	{69	,1	,1	,&A3IS35LDU},	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
	{70	,1	,1	,&A3VP81LDU},	//( - , - ) Давление СПУСК ИС1 в норме
	{71	,1	,1	,&A4AD10LDU},	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
	{72	,1	,1	,&A4IS10LDU},	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
	{73	,1	,1	,&A4IS11LDU},	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
	{74	,1	,1	,&A4IS21LDU},	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
	{75	,1	,1	,&A4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
	{76	,1	,1	,&A5AD10LDU},	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
	{77	,1	,1	,&A5AD20LDU},	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
	{78	,1	,1	,&A5IS11LDU},	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
	{79	,1	,1	,&A5IS21LDU},	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
	{80	,1	,1	,&A5VS12LDU},	//( - , SCM) Движение НЛ1 в сторону ВУ
	{81	,1	,1	,&A5VS22LDU},	//( - , SCM) Движение НЛ1 в сторону НУ
	{82	,1	,1	,&A6AD10LDU},	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
	{83	,1	,1	,&A6AD20LDU},	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
	{84	,1	,1	,&A6IS11LDU},	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
	{85	,1	,1	,&A6IS21LDU},	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
	{86	,1	,1	,&A6VS12LDU},	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
	{87	,1	,1	,&A6VS22LDU},	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
	{88	,1	,1	,&A7AP31LDU},	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
	{89	,1	,1	,&A7AS31LDU},	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
	{90	,1	,1	,&A8AD10LDU},	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
	{91	,1	,1	,&A8AD20LDU},	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
	{92	,5	,1	,&A8IC01UDU},	//( - , SDu) Координата ДС2
	{93	,1	,1	,&A8IS12LDU},	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
	{94	,1	,1	,&A8IS22LDU},	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
	{95	,1	,1	,&A9AD10LDU},	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
	{96	,1	,1	,&A9IS11LDU},	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
	{97	,1	,1	,&A9IS21LDU},	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
	{98	,3	,1	,&B0IT01IZ1},	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
	{99	,3	,1	,&B0IT02IZ2},	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
	{100	,3	,1	,&B0IT03IRP},	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
	{101	,8	,1	,&B0SN02RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
	{102	,8	,1	,&B0SN03RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
	{103	,8	,1	,&B0SN04RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
	{104	,8	,1	,&B0SN05RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
	{105	,8	,1	,&B0SN06RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
	{106	,8	,1	,&B0SN07RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
	{107	,8	,1	,&B0SN08RIM},	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
	{108	,8	,1	,&B0SR01RIM},	//( - , SCM) Текущая реактивность AЗ2
	{109	,1	,1	,&B0VP81LZZ},	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
	{110	,1	,1	,&B1AD01LDU},	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
	{111	,1	,1	,&B1AD02LDU},	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
	{112	,1	,1	,&B1AD03LDU},	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
	{113	,1	,1	,&B1AD04LDU},	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
	{114	,1	,1	,&B1AD05LDU},	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
	{115	,1	,1	,&B1AD11LDU},	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
	{116	,1	,1	,&B1AD21LDU},	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
	{117	,1	,1	,&B1AD31LDU},	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
	{118	,1	,1	,&B1AD32LDU},	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
	{119	,5	,1	,&B1IC01UDU},	//( - , SDu) Координата штока ББ2
	{120	,1	,1	,&B1IE03LDU},	//( - , SCM) Движение ББ2 вперед (от БУШД)
	{121	,1	,1	,&B1IE04LDU},	//( - , SCM) Движение ББ2 назад (от БУШД)
	{122	,1	,1	,&B1IS11LDU},	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
	{123	,1	,1	,&B1IS11LIM},	//( - , SCM) Магнит ББ2 обесточен
	{124	,1	,1	,&B1IS12LDU},	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
	{125	,1	,1	,&B1IS21LDU},	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
	{126	,1	,1	,&B1IS32LIM},	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
	{127	,1	,1	,&B1VP81LZZ},	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
	{128	,1	,1	,&B2AD01LDU},	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
	{129	,1	,1	,&B2AD02LDU},	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
	{130	,1	,1	,&B2AD03LDU},	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
	{131	,1	,1	,&B2AD04LDU},	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
	{132	,1	,1	,&B2AD05LDU},	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
	{133	,1	,1	,&B2AD11LDU},	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
	{134	,1	,1	,&B2AD21LDU},	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
	{135	,1	,1	,&B2AD31LDU},	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
	{136	,1	,1	,&B2AD32LDU},	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
	{137	,1	,1	,&B2AD33LDU},	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
	{138	,5	,1	,&B2IC01UDU},	//( - , SDu) Координата штока РБ2
	{139	,3	,1	,&B2IP01IZ1},	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
	{140	,3	,1	,&B2IP01IZ2},	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
	{141	,1	,1	,&B2IS11LDU},	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
	{142	,1	,1	,&B2IS11LIM},	//( - , SCM) Магнит РБ2 обесточен
	{143	,1	,1	,&B2IS12LDU},	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
	{144	,1	,1	,&B2IS21LDU},	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
	{145	,1	,1	,&B2IS32LIM},	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
	{146	,1	,1	,&B2IS33LDU},	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
	{147	,1	,1	,&B2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
	{148	,1	,1	,&B3AD01LDU},	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
	{149	,1	,1	,&B3AD02LDU},	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
	{150	,1	,1	,&B3AD03LDU},	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
	{151	,1	,1	,&B3AD04LDU},	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
	{152	,1	,1	,&B3AD05LDU},	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
	{153	,1	,1	,&B3AD11LDU},	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
	{154	,1	,1	,&B3AD21LDU},	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
	{155	,1	,1	,&B3AD31LDU},	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
	{156	,1	,1	,&B3AD33LDU},	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
	{157	,1	,1	,&B3AD34LDU},	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
	{158	,5	,1	,&B3IC01UDU},	//( - , SDu) Координата штока ИС2
	{159	,3	,1	,&B3IP02IDU},	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
	{160	,1	,1	,&B3IS11LDU},	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
	{161	,1	,1	,&B3IS21LDU},	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
	{162	,1	,1	,&B3IS22LDU},	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
	{163	,1	,1	,&B3IS31LDU},	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
	{164	,1	,1	,&B3IS33LDU},	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{165	,1	,1	,&B3IS35LDU},	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
	{166	,1	,1	,&B3VP81LDU},	//( - , - ) Давление СПУСК ИС2 в норме
	{167	,1	,1	,&B4AD10LDU},	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
	{168	,1	,1	,&B4IS10LDU},	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
	{169	,1	,1	,&B4IS11LDU},	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
	{170	,1	,1	,&B4IS21LDU},	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
	{171	,1	,1	,&B4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
	{172	,1	,1	,&B5AD10LDU},	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
	{173	,1	,1	,&B5AD20LDU},	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
	{174	,1	,1	,&B5IS11LDU},	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
	{175	,1	,1	,&B5IS21LDU},	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
	{176	,1	,1	,&B5VS12LDU},	//( - , SCM) Движение НЛ2 в сторону ВУ
	{177	,1	,1	,&B5VS22LDU},	//( - , SCM) Движение НЛ2 в сторону НУ
	{178	,1	,1	,&B6AD10LDU},	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
	{179	,1	,1	,&B6AD20LDU},	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
	{180	,1	,1	,&B6IS11LDU},	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
	{181	,1	,1	,&B6IS21LDU},	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
	{182	,1	,1	,&B6VS12LDU},	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
	{183	,1	,1	,&B6VS22LDU},	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
	{184	,1	,1	,&B7AP31LDU},	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
	{185	,1	,1	,&B7AS31LDU},	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
	{186	,1	,1	,&B8AD10LDU},	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
	{187	,1	,1	,&B8AD20LDU},	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
	{188	,5	,1	,&B8IC01UDU},	//( - , SDu) Координата АЗ2, мм
	{189	,1	,1	,&B8IS11LDU},	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
	{190	,1	,1	,&B8IS12LDU},	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
	{191	,1	,1	,&B8IS21LDU},	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
	{192	,1	,1	,&B8IS22LDU},	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
	{193	,1	,1	,&B9AD10LDU},	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
	{194	,1	,1	,&B9IS11LDU},	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
	{195	,1	,1	,&B9IS21LDU},	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
	{196	,1	,1	,&C1MD31LP1},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
	{197	,1	,1	,&C1MD31LP2},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
	{198	,1	,1	,&C2MD31LP1},	//( - , SCM) Кнопка «СБРОС РБ»
	{199	,8	,1	,&LTAKTS},	//( - , - ) takt scm
	{200	,1	,1	,&R0AD16LDU},	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
	{201	,8	,1	,&R0CR01RIM},	//( - , SCM) Коэффициент 12 связи АЗ1,2
	{202	,8	,1	,&R0CR02RIM},	//( - , SCM) Коэффициент 11 связи АЗ1,2
	{203	,3	,1	,&R0DEUMLSS},	//( - , SCM) Сигнал управления моделью
	{204	,1	,1	,&R0EE01LZ1},	//( - , SBz1) Питание  АКНП1  отключить
	{205	,1	,1	,&R0EE01LZ2},	//( - , SBz2) Питание  АКНП1  отключить
	{206	,1	,1	,&R0EE02LZ1},	//( - , SBz1) Питание  АКНП  отключить
	{207	,1	,1	,&R0EE02LZ2},	//( - , SBz2) Питание  АКНП  отключить
	{208	,1	,1	,&R0EE03LZ1},	//( - , SBz1) Питание  АКНП3  отключить
	{209	,1	,1	,&R0EE03LZ2},	//( - , SBz2) Питание  АКНП3  отключить
	{210	,1	,1	,&R0EE04LZ1},	//( - , SBz1) Питание  АКНП4  отключить
	{211	,1	,1	,&R0EE04LZ2},	//( - , SBz2) Питание  АКНП4  отключить
	{212	,8	,1	,&R0IN01FI1},	//( - , SA1) Выход СНМ11 Гц от ПТИ
	{213	,8	,1	,&R0IN01FI2},	//( - , SA2) Выход СНМ-11 Гц от ПТИ
	{214	,8	,1	,&R0IN01FI3},	//( - , SA3) Выход СНМ-11 Гц от ПТИ
	{215	,8	,1	,&R0IN01FI4},	//( - , SA4) Выход СНМ-11 Гц от ПТИ
	{216	,8	,1	,&R0IN01RIP},	//( - , SRP) Выход СНМ-11 Гц от ПТИ
	{217	,8	,1	,&R0IN02FI1},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{218	,8	,1	,&R0IN02FI2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{219	,8	,1	,&R0IN02FI3},	//( - , SA3) Выход КНК15-1 Гц от ПТИ
	{220	,8	,1	,&R0IN02FI4},	//( - , SA4) Выход КНК15-1 Гц от ПТИ
	{221	,8	,1	,&R0IN02RIP},	//( - , SRP) Выход КНК15- Гц от ПТИ
	{222	,8	,1	,&R0IN03FI1},	//( - , SA1) Выход КНК53М Гц от ПТИ
	{223	,8	,1	,&R0IN03FI2},	//( - , SA2) Выход КНК53М Гц от ПТИ
	{224	,8	,1	,&R0IN03FI3},	//( - , SA3) Выход КНК53М Гц от ПТИ
	{225	,8	,1	,&R0IN03FI4},	//( - , SA4) Выход КНК53М Гц от ПТИ
	{226	,8	,1	,&R0IN03RIP},	//( - , SRP) Выход КНК53М Гц от ПТИ
	{227	,8	,1	,&R0IN06RIP},	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
	{228	,8	,1	,&R0IN07RIP},	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
	{229	,1	,1	,&R0IS01FI0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{230	,1	,1	,&R0IS02LDU},	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
	{231	,3	,1	,&R0MW11IP1},	//( - , SCM) Переключатель ВЫСТРЕЛ
	{232	,1	,1	,&R0MW13LP2},	//( - , SCM) Переключатель «СЕТЬ»
	{233	,1	,1	,&R0S01LIM},	//(vds32_pti:360 - K32VDSR, - ) Отключение сетевых передач ПТИ
	{234	,8	,1	,&R0SR01RIM},	//( - , SCM) Текущая реактивность PУ
	{235	,8	,1	,&R0SR02RIM},	//( - , SCM) Текущая мощность РУ (ватт)
	{236	,8	,1	,&R0SR03RIM},	//( - , SCM) Текущая мощность РУ аз1  (ватт)
	{237	,8	,1	,&R0ST01RIM},	//( - , SCM) Текущий период разгона РУ
	{238	,1	,1	,&R0VZ71LZ1},	//( - , SCM, SBz1) Обобщенный сигнал по АЗ  1 канала
	{239	,1	,1	,&R0VZ71LZ2},	//( - , SCM, SBz2) Обобщенный сигнал по АЗ  2 канала
	{240	,1	,1	,&R1AD10LDU},	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
	{241	,1	,1	,&R1AD20LDU},	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
	{242	,1	,1	,&R1IS11LDU},	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
	{243	,1	,1	,&R1IS21LDU},	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
	{244	,1	,1	,&R1VS12LDU},	//( - , SCM) Движение МДЗ1 в сторону ВУ
	{245	,1	,1	,&R1VS22LDU},	//( - , SCM) Движение МДЗ1 в сторону НУ
	{246	,1	,1	,&R2AD10LDU},	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
	{247	,1	,1	,&R2AD20LDU},	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
	{248	,1	,1	,&R2IS11LDU},	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
	{249	,1	,1	,&R2IS21LDU},	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
	{250	,1	,1	,&R2VS12LDU},	//( - , SCM) Движение МДЗ2 в сторону ВУ
	{251	,1	,1	,&R2VS22LDU},	//( - , SCM) Движение МДЗ2 в сторону НУ
	{252	,1	,1	,&R3IS11LDU},	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
	{253	,1	,1	,&R3IS21LDU},	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
	{254	,1	,1	,&R4AD10LDU},	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
	{255	,1	,1	,&R4AD20LDU},	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
	{256	,1	,1	,&R4IS11LDU},	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
	{257	,1	,1	,&R4IS12LDU},	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
	{258	,1	,1	,&R4IS21LDU},	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
	{259	,1	,1	,&R4IS22LDU},	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
	{260	,1	,1	,&R4VS12LDU},	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
	{261	,1	,1	,&R4VS22LDU},	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
	{262	,1	,1	,&R5IS11LDU},	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
	{263	,1	,1	,&R5IS21LDU},	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
	{264	,1	,1	,&R6IS21LDU},	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
	{265	,1	,1	,&R6IS62LDU},	//( - , - ) Исправность ВИП ССДИ-39 1канал
	{266	,1	,1	,&R6IS63LDU},	//( - , - ) Исправность ВИП ССДИ-39 2канал
	{267	,1	,1	,&R6IS64LDU},	//( - , - ) Исправность ВИП ССДИ-35 1канал
	{268	,1	,1	,&R6IS65LDU},	//( - , - ) Исправность ВИП ССДИ-35 2канал
	{269	,1	,1	,&R6IS66LZ1},	//(do32_pti:100 - K17DO, - ) Исправность БОС
	{270	,1	,1	,&R6IS66LZ2},	//(do32_pti:110 - K17DO, - ) Исправность БОС
	{271	,1	,1	,&R7II71LZ1},	//(do32_pti:100 - K01DO, - ) Сработала АС 1К IУР
	{272	,1	,1	,&R7II71LZ2},	//(do32_pti:110 - K22DO, - ) Сработала АС 1К IУР
	{273	,1	,1	,&R7II72LZ1},	//(do32_pti:100 - K05DO, - ) Сработала АС 2К IУР
	{274	,1	,1	,&R7II72LZ2},	//(do32_pti:110 - K18DO, - ) Сработала АС 2К IУР
	{275	,1	,1	,&R7II73LZ1},	//(do32_pti:110 - K08DO, - ) Сработала АС 3К IУР
	{276	,1	,1	,&R7II73LZ2},	//(do32_pti:110 - K24DO, - ) Сработала АС 3К IУР
	{277	,1	,1	,&R7II74LZ1},	//(do32_pti:100 - K04DO, - ) Сработала АС 1К IIУР
	{278	,1	,1	,&R7II74LZ2},	//(do32_pti:110 - K20DO, - ) Сработала АС 1К IIУР
	{279	,1	,1	,&R7II75LZ1},	//(do32_pti:100 - K02DO, - ) Сработала АС 2К IIУР
	{280	,1	,1	,&R7II75LZ2},	//(do32_pti:110 - K19DO, - ) Сработала АС 2К IIУР
	{281	,1	,1	,&R7II76LZ1},	//(do32_pti:100 - K03DO, - ) Сработала АС 3К IIУР
	{282	,1	,1	,&R7II76LZ2},	//(do32_pti:110 - K25DO, - ) Сработала АС 3К IIУР
	{283	,1	,1	,&R8AD21LDU},	//(vds32_pti:310 - K31VDSR, - ) Имитация прихода на ВУ ИС для КВДС
	{284	,1	,1	,&R8AD22LDU},	//(do32_pti:140 - K09DO, - ) Сигнал синхронизации с импульсом
	{285	,1	,1	,&R8IS11LDU},	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
	{286	,3	,1	,&TerR0IN06FRP},	//( - , - ) Неисправности СНМ-11 -1,2
	{287	,1	,1	,&bFirstEnterFlag},	//(bFirstEnterFlag) 
	{288	,8	,1	,&fEM_A0UN01RIM},	//(A0UN01RIM) Мощность источника нейтронов ИНИ
	{289	,8	,1	,&fEM_A0UN02RIM},	//(A0UN02RIM) Мощность источника нейтронов с АНИ
	{290	,8	,1	,&fEM_A0UN07RIM},	//(A0UN07RIM) Доля запаздывающих нейтронов
	{291	,8	,1	,&fEM_A0UP01RIM},	//(A0UP01RIM) Текущее давление в АЗ1,2
	{292	,8	,1	,&fEM_A0UP02RIM},	//(A0UP02RIM) Текущее давление в АЗ1,2
	{293	,8	,1	,&fEM_A0UR01RSP},	//(A0UR01RSP) Стартовая  реактивность АЗ1
	{294	,8	,1	,&fEM_A0UR02RSP},	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
	{295	,8	,1	,&fEM_A0UT03RSP},	//(A0UT03RSP) Стартовая  температура АЗ1 град
	{296	,8	,1	,&fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{297	,8	,1	,&fEM_A0UX01RSS},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{298	,8	,1	,&fEM_A0UX02RSS},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{299	,8	,1	,&fEM_A0UX03RSS},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{300	,8	,1	,&fEM_A0UX04RSS},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{301	,8	,1	,&fEM_A0UX05RSS},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{302	,8	,1	,&fEM_A0UX06RSS},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{303	,8	,1	,&fEM_A0UX07RSS},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{304	,8	,1	,&fEM_A0UX08RSS},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{305	,8	,1	,&fEM_A0UX09RSS},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{306	,8	,1	,&fEM_A0UX10RSS},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{307	,8	,1	,&fEM_A0UX11RSS},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{308	,8	,1	,&fEM_A0UX12RSS},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{309	,8	,1	,&fEM_A0UX13RSS},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{310	,8	,1	,&fEM_A0UX14RSS},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{311	,8	,1	,&fEM_A0UX15RSS},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{312	,8	,1	,&fEM_A1MC01RC1},	//(A1MC01RC1) Заданная координата  ББ1 от ИС
	{313	,8	,1	,&fEM_A1MC01RSP},	//(A1MC01RSP) Стартовая координата  ББ1
	{314	,8	,1	,&fEM_A1MC02RC1},	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
	{315	,8	,1	,&fEM_A1MC02RSP},	//(A1MC02RSP) Стартовая координата штока ББ1
	{316	,8	,1	,&fEM_A1MV01RC1},	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
	{317	,8	,1	,&fEM_A1MV02RC1},	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
	{318	,8	,1	,&fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{319	,8	,1	,&fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{320	,8	,1	,&fEM_A1UC04RIM},	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
	{321	,8	,1	,&fEM_A1UC05RIM},	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
	{322	,8	,1	,&fEM_A1UC06RIM},	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
	{323	,8	,1	,&fEM_A1UC08RIM},	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
	{324	,8	,1	,&fEM_A1UG01RDU},	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
	{325	,8	,1	,&fEM_A1UP01RIM},	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
	{326	,8	,1	,&fEM_A1UP82RIM},	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{327	,8	,1	,&fEM_A1UR00RIM},	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{328	,8	,1	,&fEM_A1UR01RIM},	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{329	,8	,1	,&fEM_A1US07RDU},	//(A1US07RDU) Постоянная времени масляного демпфера ББ
	{330	,8	,1	,&fEM_A1UV02RIM},	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{331	,8	,1	,&fEM_A2MC01RC1},	//(A2MC01RC1) Заданная координата РБ1 от ИС
	{332	,8	,1	,&fEM_A2MC01RSP},	//(A2MC01RSP) Стартовая координата  РБ1
	{333	,8	,1	,&fEM_A2MC02RC1},	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
	{334	,8	,1	,&fEM_A2MC02RSP},	//(A2MC02RSP) Стартовая координата штока РБ1
	{335	,8	,1	,&fEM_A2MV01RC1},	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
	{336	,8	,1	,&fEM_A2MV02RC1},	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
	{337	,8	,1	,&fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{338	,8	,1	,&fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{339	,8	,1	,&fEM_A2UC04RIM},	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
	{340	,8	,1	,&fEM_A2UC05RIM},	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
	{341	,8	,1	,&fEM_A2UC06RIM},	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
	{342	,8	,1	,&fEM_A2UC08RIM},	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
	{343	,8	,1	,&fEM_A2UG01RDU},	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
	{344	,8	,1	,&fEM_A2UP01RIM},	//(A2UP01RIM) Текущее давление на сброс РБ
	{345	,8	,1	,&fEM_A2UP02RIM},	//(A2UP02RIM) Текущее давление на подъём РБ
	{346	,8	,1	,&fEM_A2UP03RDU},	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{347	,8	,1	,&fEM_A2UP03RIM},	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
	{348	,8	,1	,&fEM_A2UP04RDU},	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{349	,8	,1	,&fEM_A2UR00RIM},	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{350	,8	,1	,&fEM_A2UR01RIM},	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{351	,8	,1	,&fEM_A2US07RDU},	//(A2US07RDU) Постоянная времени масляного демпфера РБ
	{352	,8	,1	,&fEM_A2UV02RIM},	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{353	,8	,1	,&fEM_A3MC01RC1},	//(A3MC01RC1) Заданная координата ИС1 от ИС
	{354	,8	,1	,&fEM_A3MC01RSP},	//(A3MC01RSP) Стартовая координата  ИС1
	{355	,8	,1	,&fEM_A3MC02RC1},	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
	{356	,8	,1	,&fEM_A3MC02RSP},	//(A3MC02RSP) Стартовая координата штока ИС1
	{357	,8	,1	,&fEM_A3MV01RC1},	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
	{358	,8	,1	,&fEM_A3MV02RC1},	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
	{359	,8	,1	,&fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{360	,8	,1	,&fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{361	,8	,1	,&fEM_A3UC04RIM},	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
	{362	,8	,1	,&fEM_A3UC05RIM},	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
	{363	,8	,1	,&fEM_A3UC06RIM},	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
	{364	,8	,1	,&fEM_A3UC08RIM},	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
	{365	,8	,1	,&fEM_A3UG01RDU},	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
	{366	,8	,1	,&fEM_A3UP01RIM},	//(A3UP01RIM) Текущее давление на СПУСК ИС
	{367	,8	,1	,&fEM_A3UP02RDU},	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
	{368	,8	,1	,&fEM_A3UP02RIM},	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
	{369	,8	,1	,&fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{370	,8	,1	,&fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{371	,8	,1	,&fEM_A3UR00RIM},	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{372	,8	,1	,&fEM_A3UR01RIM},	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{373	,8	,1	,&fEM_A3US07RDU},	//(A3US07RDU) Постоянная времени масляного демпфера ИС
	{374	,8	,1	,&fEM_A3UV02RIM},	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{375	,8	,1	,&fEM_A4MC01RSP},	//(A4MC01RSP) Стартовая координата НИ1
	{376	,8	,1	,&fEM_A4UL10RIM},	//(A4UL10RIM) Время полного перемещения НИ сек
	{377	,8	,1	,&fEM_A4UP01RIM},	//(A4UP01RIM) Текущее давление на подъём НИ
	{378	,8	,1	,&fEM_A4UP02RIM},	//(A4UP02RIM) Нижняя граница давления на подъём НИ
	{379	,8	,1	,&fEM_A5MC01RC1},	//(A5MC01RC1) Заданная координата НЛ1 от ИС
	{380	,8	,1	,&fEM_A5MC01RSP},	//(A5MC01RSP) Стартовая координата НЛ1
	{381	,8	,1	,&fEM_A5MV01RC1},	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
	{382	,8	,1	,&fEM_A5UC10RIM},	//(A5UC10RIM) Время полного хода НЛ сек
	{383	,8	,1	,&fEM_A6MC01RC1},	//(A6MC01RC1) Заданная координата БЗ1 от ИС
	{384	,8	,1	,&fEM_A6MC01RSP},	//(A6MC01RSP) Стартовая координата БЗ1
	{385	,8	,1	,&fEM_A6MV01RC1},	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
	{386	,8	,1	,&fEM_A6UC10RIM},	//(A6UC10RIM) Время полного хода БЗ (сек)
	{387	,8	,1	,&fEM_A6US80RDU},	//(A6US80RDU) Тормозной путь БЗ (мм)
	{388	,8	,1	,&fEM_A8MC01RC1},	//(A8MC01RC1) Заданная координата ДС2 от ИС
	{389	,8	,1	,&fEM_A8MC01RSP},	//(A8MC01RSP) Стартовая координата ДС2
	{390	,8	,1	,&fEM_A8MV01RC1},	//(A8MV01RC1) Заданная скорость ДС2 от ИС
	{391	,8	,1	,&fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{392	,8	,1	,&fEM_A8UC08RDU},	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
	{393	,8	,1	,&fEM_A8UC10RIM},	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
	{394	,8	,1	,&fEM_A8UC11RIM},	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
	{395	,8	,1	,&fEM_A8UC20RIM},	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
	{396	,8	,1	,&fEM_A8UC21RIM},	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
	{397	,8	,1	,&fEM_A8US80RDU},	//(A8US80RDU) Тормозной путь ДС2 (мм)
	{398	,8	,1	,&fEM_A8UV80RDU},	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
	{399	,8	,1	,&fEM_A9MC01RSP},	//(A9MC01RSP) Стартовая координата НИ ДС1
	{400	,8	,1	,&fEM_A9UL10RIM},	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
	{401	,8	,1	,&fEM_B0UT03RSP},	//(B0UT03RSP) Стартовая  температура АЗ2 град
	{402	,8	,1	,&fEM_B0UX01RSS},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{403	,8	,1	,&fEM_B0UX02RSS},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{404	,8	,1	,&fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{405	,8	,1	,&fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
	{406	,8	,1	,&fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{407	,8	,1	,&fEM_B0UX06RSS},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{408	,8	,1	,&fEM_B0UX07RSS},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{409	,8	,1	,&fEM_B0UX08RSS},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{410	,8	,1	,&fEM_B0UX09RSS},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{411	,8	,1	,&fEM_B0UX10RSS},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{412	,8	,1	,&fEM_B0UX11RSS},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{413	,8	,1	,&fEM_B0UX12RSS},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{414	,8	,1	,&fEM_B1MC01RC1},	//(B1MC01RC1) Заданная координата ББ2 от ИС
	{415	,8	,1	,&fEM_B1MC01RSP},	//(B1MC01RSP) Стартовая координата  ББ2
	{416	,8	,1	,&fEM_B1MC02RC1},	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
	{417	,8	,1	,&fEM_B1MC02RSP},	//(B1MC02RSP) Стартовая координата штока ББ2
	{418	,8	,1	,&fEM_B1MV01RC1},	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
	{419	,8	,1	,&fEM_B1MV02RC1},	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
	{420	,8	,1	,&fEM_B2MC01RC1},	//(B2MC01RC1) Заданная координата РБ2 от ИС
	{421	,8	,1	,&fEM_B2MC01RSP},	//(B2MC01RSP) Стартовая координата  РБ2
	{422	,8	,1	,&fEM_B2MC02RC1},	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
	{423	,8	,1	,&fEM_B2MC02RSP},	//(B2MC02RSP) Стартовая координата штока РБ2
	{424	,8	,1	,&fEM_B2MV01RC1},	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
	{425	,8	,1	,&fEM_B2MV02RC1},	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
	{426	,8	,1	,&fEM_B3MC01RC1},	//(B3MC01RC1) Заданная координата ИС2 от ИС
	{427	,8	,1	,&fEM_B3MC01RSP},	//(B3MC01RSP) Стартовая координата  ИС2
	{428	,8	,1	,&fEM_B3MC02RC1},	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
	{429	,8	,1	,&fEM_B3MC02RSP},	//(B3MC02RSP) Стартовая координата штока ИС2
	{430	,8	,1	,&fEM_B3MV01RC1},	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
	{431	,8	,1	,&fEM_B3MV02RC1},	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
	{432	,8	,1	,&fEM_B4MC01RSP},	//(B4MC01RSP) Стартовая координата НИ2
	{433	,8	,1	,&fEM_B5MC01RC1},	//(B5MC01RC1) Заданная координата НЛ2 от ИС
	{434	,8	,1	,&fEM_B5MC01RSP},	//(B5MC01RSP) Стартовая координата НЛ2
	{435	,8	,1	,&fEM_B5MV01RC1},	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
	{436	,8	,1	,&fEM_B6MC01RC1},	//(B6MC01RC1) Заданная координата БЗ2 от ИС
	{437	,8	,1	,&fEM_B6MC01RSP},	//(B6MC01RSP) Стартовая координата БЗ2
	{438	,8	,1	,&fEM_B6MV01RC1},	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
	{439	,8	,1	,&fEM_B8MC01RC1},	//(B8MC01RC1) Заданная координата АЗ2 от ИС
	{440	,8	,1	,&fEM_B8MC01RSP},	//(B8MC01RSP) Стартовая координата АЗ2
	{441	,8	,1	,&fEM_B8MV01RC1},	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
	{442	,8	,1	,&fEM_B8UC08RDU},	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
	{443	,8	,1	,&fEM_B8UC10RIM},	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
	{444	,8	,1	,&fEM_B8UC11RIM},	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
	{445	,8	,1	,&fEM_B8UC20RIM},	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
	{446	,8	,1	,&fEM_B8UC21RIM},	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
	{447	,8	,1	,&fEM_B8US80RDU},	//(B8US80RDU) Тормозной путь АЗ2 (мм)
	{448	,8	,1	,&fEM_B8UV80RDU},	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
	{449	,8	,1	,&fEM_B9MC01RSP},	//(B9MC01RSP) Стартовая координата НИ ДС2
	{450	,8	,1	,&fEM_R0UH01RSS},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
	{451	,8	,1	,&fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{452	,8	,1	,&fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
	{453	,8	,1	,&fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{454	,8	,1	,&fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{455	,8	,1	,&fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{456	,8	,1	,&fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{457	,8	,1	,&fEM_R0UL01RIM},	//(R0UL01RIM) Среднее время генерации нейтронов
	{458	,8	,1	,&fEM_R0UL02RDU},	//(R0UL02RDU) Время задержки  ИНИ
	{459	,8	,1	,&fEM_R0UL02RIM},	//(R0UL02RIM) Время удержания синхроимпульса
	{460	,8	,1	,&fEM_R0UL04RIM},	//(R0UL04RIM) Время блокировки повторной генерации импульса
	{461	,8	,1	,&fEM_R0UN02RIM},	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{462	,8	,1	,&fEM_R0UN18RDU},	//(R0UN18RDU) Коэффициент температурной корректировки реактивности(долл)
	{463	,8	,1	,&fEM_R0UR01RIM},	//(R0UR01RIM) Стартовая отрицательная реактивность
	{464	,8	,1	,&fEM_R0UR30RIM},	//(R0UR30RIM) Реактивность вносимая образцами (долл)
	{465	,8	,1	,&fEM_R0UT01RDU},	//(R0UT01RDU) Нижний предел шкалы датчика температуры
	{466	,8	,1	,&fEM_R0UT02RDU},	//(R0UT02RDU) Верхний предел шкалы датчика температуры
	{467	,8	,1	,&fEM_R0UT02RIM},	//(R0UT02RIM) Масса топлива в АЗ
	{468	,8	,1	,&fEM_R0UT03RIM},	//(R0UT03RIM) Нормальная температура АЗ град
	{469	,8	,1	,&fEM_R0UT04RIM},	//(R0UT04RIM) Удельная теплоёмкость топлива
	{470	,8	,1	,&fEM_R0UT05RIM},	//(R0UT05RIM) Энергия деления ядра
	{471	,8	,1	,&fEM_R0UT06RIM},	//(R0UT06RIM) Конвекционное сопротивление при обдуве
	{472	,8	,1	,&fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{473	,8	,1	,&fEM_R0UV82RDU},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{474	,8	,1	,&fEM_R0UV83RDU},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{475	,8	,1	,&fEM_R0UV84RDU},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{476	,8	,1	,&fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{477	,8	,1	,&fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{478	,8	,1	,&fEM_R0UV87RDU},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{479	,8	,1	,&fEM_R1MC01RC1},	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
	{480	,8	,1	,&fEM_R1MC01RSP},	//(R1MC01RSP) Стартовая координата МДЗ1
	{481	,8	,1	,&fEM_R1MV01RC1},	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
	{482	,8	,1	,&fEM_R1UC10RIM},	//(R1UC10RIM) Время полного хода МДЗ сек
	{483	,8	,1	,&fEM_R2MC01RC1},	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
	{484	,8	,1	,&fEM_R2MC01RSP},	//(R2MC01RSP) Стартовая координата МДЗ2
	{485	,8	,1	,&fEM_R2MV01RC1},	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
	{486	,8	,1	,&fEM_R3UC01RSP},	//(R3UC01RSP) Стартовая координата Гомогенных дверей
	{487	,8	,1	,&fEM_R3UL10RIM},	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
	{488	,8	,1	,&fEM_R4MC01RC1},	//(R4MC01RC1) Заданная координата тележки от ИС
	{489	,8	,1	,&fEM_R4MC01RSP},	//(R4MC01RSP) Стартовая координата тележки
	{490	,8	,1	,&fEM_R4MV01RC1},	//(R4MV01RC1) Заданная скорость тележки от ИС
	{491	,8	,1	,&fEM_R4UC08RDU},	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
	{492	,8	,1	,&fEM_R4UC10RIM},	//(R4UC10RIM) Координата верхних механических упоров тележки мм
	{493	,8	,1	,&fEM_R4UC20RIM},	//(R4UC20RIM) Координата нижних механических упоров тележки мм
	{494	,8	,1	,&fEM_R4UC22RIM},	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
	{495	,8	,1	,&fEM_R4US80RDU},	//(R4US80RDU) Тормозной путь тележки (мм)
	{496	,8	,1	,&fEM_R4UV80RDU},	//(R4UV80RDU) Номинальная скорость тележки (см/с)
	{497	,8	,1	,&fEM_R5UC01RSP},	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
	{498	,8	,1	,&fEM_R5UL10RIM},	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
	{499	,8	,1	,&fEM_R6UC01RSP},	//(R6UC01RSP) Стартовая координата Кран-балки
	{500	,8	,1	,&fEM_R6UL10RIM},	//(R6UL10RIM) Время полного хода кран-балки сек
	{501	,8	,1	,&fEM_R7UC10RIM},	//(R7UC10RIM) X-координата КНК53М R7IN13 см
	{502	,8	,1	,&fEM_R7UC19RIM},	//(R7UC19RIM) Y-координата СНМ-11 (11) см
	{503	,8	,1	,&fEM_R7UI02RIM},	//(R7UI02RIM) Коэффициент усиления уровня радиации
	{504	,8	,1	,&fEM_R7UI71RIM},	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{505	,8	,1	,&fEM_R7UI73RIM},	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
	{506	,8	,1	,&fEM_R7UI74RIM},	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
	{507	,8	,1	,&fEM_R7UI75RIM},	//(R7UI75RIM) Множитель к уровню радиации
	{508	,8	,1	,&fEM_R7UI76RIM},	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{509	,8	,1	,&fEM_R7UI77RIM},	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{510	,8	,1	,&fEM_R7UL01RIM},	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
	{511	,8	,1	,&fEM_R7UX01RSS},	//(R7UX01RSS) X-координата камеры R7IN11
	{512	,8	,1	,&fEM_R7UX02RSS},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{513	,8	,1	,&fEM_R7UX04RSS},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{514	,8	,1	,&fEM_R7UX05RSS},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{515	,8	,1	,&fEM_R7UX06RSS},	//(R7UX06RSS) X-координата камеры R7IN23 (см)
	{516	,8	,1	,&fEM_R7UX07RSS},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{517	,8	,1	,&fEM_R7UX08RSS},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{518	,8	,1	,&fEM_R7UX09RSS},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{519	,8	,1	,&fEM_R7UX10RSS},	//(R7UX10RSS) X-координата камеры R7IN41
	{520	,8	,1	,&fEM_R7UX11RSS},	//(R7UX11RSS) X-координата камеры R7IN42
	{521	,8	,1	,&fEM_R7UX12RSS},	//(R7UX12RSS) X-координата камеры R7IN43
	{522	,8	,1	,&fEM_R7UX13RSS},	//(R7UX13RSS) X-координата камеры R7IN51
	{523	,8	,1	,&fEM_R7UX14RSS},	//(R7UX14RSS) X-координата камеры R7IN52
	{524	,8	,1	,&fEM_R7UX15RSS},	//(R7UX15RSS) X-координата камеры R7IN53
	{525	,8	,1	,&fEM_R7UX16RSS},	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
	{526	,8	,1	,&fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 см
	{527	,8	,1	,&fEM_R7UY01RSS},	//(R7UY01RSS) Y-координата камеры R7IN11
	{528	,8	,1	,&fEM_R7UY02RSS},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{529	,8	,1	,&fEM_R7UY04RSS},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{530	,8	,1	,&fEM_R7UY05RSS},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{531	,8	,1	,&fEM_R7UY06RSS},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{532	,8	,1	,&fEM_R7UY07RSS},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{533	,8	,1	,&fEM_R7UY08RSS},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{534	,8	,1	,&fEM_R7UY09RSS},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{535	,8	,1	,&fEM_R7UY10RSS},	//(R7UY10RSS) Y-координата камеры R7IN41
	{536	,8	,1	,&fEM_R7UY11RSS},	//(R7UY11RSS) Y-координата камеры R7IN42
	{537	,8	,1	,&fEM_R7UY12RSS},	//(R7UY12RSS) Y-координата камеры R7IN43
	{538	,8	,1	,&fEM_R7UY13RSS},	//(R7UY13RSS) Y-координата камеры R7IN51
	{539	,8	,1	,&fEM_R7UY14RSS},	//(R7UY14RSS) Y-координата камеры R7IN52
	{540	,8	,1	,&fEM_R7UY15RSS},	//(R7UY15RSS) Y-координата камеры R7IN53
	{541	,3	,1	,&iEM_TERA0MT01RIM},	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
	{542	,3	,1	,&iEM_TERA0VP81LIM},	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
	{543	,3	,1	,&iEM_TERA1IE03LDU},	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
	{544	,3	,1	,&iEM_TERA1IE04LDU},	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
	{545	,3	,1	,&iEM_TERA1SC01RIM},	//(TERA1SC01RIM) Искажение: Координата штока ББ1
	{546	,3	,1	,&iEM_TERA1SS11LIM},	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
	{547	,3	,1	,&iEM_TERA1SS12LIM},	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
	{548	,3	,1	,&iEM_TERA1SS21LIM},	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
	{549	,3	,1	,&iEM_TERA1VP81LIM},	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
	{550	,3	,1	,&iEM_TERA2SC01RIM},	//(TERA2SC01RIM) Искажение: Координата штока РБ1
	{551	,3	,1	,&iEM_TERA2SP01RIM},	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
	{552	,3	,1	,&iEM_TERA2SS11LIM},	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
	{553	,3	,1	,&iEM_TERA2SS12LIM},	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
	{554	,3	,1	,&iEM_TERA2SS21LIM},	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
	{555	,3	,1	,&iEM_TERA2SS33LIM},	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{556	,3	,1	,&iEM_TERA2VP82LIM},	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
	{557	,3	,1	,&iEM_TERA3SC01RIM},	//(TERA3SC01RIM) Искажение: Координата штока ИС1
	{558	,3	,1	,&iEM_TERA3SP02RIM},	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{559	,3	,1	,&iEM_TERA3SS11LIM},	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
	{560	,3	,1	,&iEM_TERA3SS21LIM},	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
	{561	,3	,1	,&iEM_TERA3SS22LIM},	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
	{562	,3	,1	,&iEM_TERA3SS31LIM},	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{563	,3	,1	,&iEM_TERA3SS33LIM},	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{564	,3	,1	,&iEM_TERA3VP81LIM},	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
	{565	,3	,1	,&iEM_TERA4SS11LIM},	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
	{566	,3	,1	,&iEM_TERA4SS21LIM},	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
	{567	,3	,1	,&iEM_TERA4VP82LIM},	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
	{568	,3	,1	,&iEM_TERA5SS11LIM},	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{569	,3	,1	,&iEM_TERA5SS21LIM},	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
	{570	,3	,1	,&iEM_TERA5VS12LIM},	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
	{571	,3	,1	,&iEM_TERA5VS22LIM},	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
	{572	,3	,1	,&iEM_TERA6MS11LIM},	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
	{573	,3	,1	,&iEM_TERA6SS21LIM},	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
	{574	,3	,1	,&iEM_TERA6VS12LIM},	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{575	,3	,1	,&iEM_TERA6VS22LIM},	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{576	,3	,1	,&iEM_TERA7MS31LIM},	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{577	,3	,1	,&iEM_TERA8SC01RIM},	//(TERA8SC01RIM) Искажение: Координата ДС2
	{578	,3	,1	,&iEM_TERA8SS12LIM},	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
	{579	,3	,1	,&iEM_TERA8SS22LIM},	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
	{580	,3	,1	,&iEM_TERA9SS11LIM},	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
	{581	,3	,1	,&iEM_TERA9SS21LIM},	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
	{582	,3	,1	,&iEM_TERB0MT01RIM},	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
	{583	,3	,1	,&iEM_TERB0VP81LIM},	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
	{584	,3	,1	,&iEM_TERB1IE03LDU},	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
	{585	,3	,1	,&iEM_TERB1IE04LDU},	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
	{586	,3	,1	,&iEM_TERB1MC01RIM},	//(TERB1MC01RIM) Искажение: Координата штока ББ2
	{587	,3	,1	,&iEM_TERB1SS11LIM},	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
	{588	,3	,1	,&iEM_TERB1SS12LIM},	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
	{589	,3	,1	,&iEM_TERB1SS21LIM},	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
	{590	,3	,1	,&iEM_TERB1VP81LIM},	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
	{591	,3	,1	,&iEM_TERB2SC01RIM},	//(TERB2SC01RIM) Искажение: Координата штока РБ2
	{592	,3	,1	,&iEM_TERB2SP01RIM},	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
	{593	,3	,1	,&iEM_TERB2SS11LIM},	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
	{594	,3	,1	,&iEM_TERB2SS12LIM},	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
	{595	,3	,1	,&iEM_TERB2SS21LIM},	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
	{596	,3	,1	,&iEM_TERB2SS33LIM},	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{597	,3	,1	,&iEM_TERB3SC01RIM},	//(TERB3SC01RIM) Искажение: Координата штока ИС2
	{598	,3	,1	,&iEM_TERB3SP02RIM},	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{599	,3	,1	,&iEM_TERB3SS11LIM},	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
	{600	,3	,1	,&iEM_TERB3SS21LIM},	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
	{601	,3	,1	,&iEM_TERB3SS22LIM},	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
	{602	,3	,1	,&iEM_TERB3SS31LIM},	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{603	,3	,1	,&iEM_TERB3SS33LIM},	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{604	,3	,1	,&iEM_TERB4SS11LIM},	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
	{605	,3	,1	,&iEM_TERB4SS21LIM},	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
	{606	,3	,1	,&iEM_TERB5SS11LIM},	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
	{607	,3	,1	,&iEM_TERB5SS21LIM},	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
	{608	,3	,1	,&iEM_TERB5VS12LIM},	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
	{609	,3	,1	,&iEM_TERB5VS22LIM},	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
	{610	,3	,1	,&iEM_TERB6SS11LIM},	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
	{611	,3	,1	,&iEM_TERB6SS21LIM},	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
	{612	,3	,1	,&iEM_TERB6VS12LIM},	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{613	,3	,1	,&iEM_TERB6VS22LIM},	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{614	,3	,1	,&iEM_TERB7MS31LIM},	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{615	,3	,1	,&iEM_TERB8SC01RIM},	//(TERB8SC01RIM) Искажение: Координата АЗ2
	{616	,3	,1	,&iEM_TERB8SS12LIM},	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
	{617	,3	,1	,&iEM_TERB8SS22LIM},	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
	{618	,3	,1	,&iEM_TERB9SS11LIM},	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
	{619	,3	,1	,&iEM_TERB9SS21LIM},	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
	{620	,3	,1	,&iEM_TERBB1},	//(TERBB1) Неисправности  ББ1
	{621	,3	,1	,&iEM_TERBB2},	//(TERBB2) Неисправности  ББ2
	{622	,3	,1	,&iEM_TERBZ1},	//(TERBZ1) Неисправности БЗ1
	{623	,3	,1	,&iEM_TERBZ2},	//(TERBZ2) Неисправности БЗ2
	{624	,3	,1	,&iEM_TERDS2},	//(TERDS2) Неисправности ДС2 от ИС
	{625	,3	,1	,&iEM_TERIS1},	//(TERIS1) Неисправности  ИС1
	{626	,3	,1	,&iEM_TERIS2},	//(TERIS2) Неисправности  ИС2
	{627	,3	,1	,&iEM_TERMAZ2},	//(TERMAZ2) Неисправности АЗ2 от ИС
	{628	,3	,1	,&iEM_TERMDZ1},	//(TERMDZ1) Неисправности МДЗ1
	{629	,3	,1	,&iEM_TERMDZ2},	//(TERMDZ2) Неисправности МДЗ2
	{630	,3	,1	,&iEM_TERNL1},	//(TERNL1) Неисправности НЛ1
	{631	,3	,1	,&iEM_TERNL2},	//(TERNL2) Неисправности НЛ2
	{632	,3	,1	,&iEM_TERR0VP81LIM},	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{633	,3	,1	,&iEM_TERR1SS11LIM},	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
	{634	,3	,1	,&iEM_TERR1SS21LIM},	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
	{635	,3	,1	,&iEM_TERR1VS12LIM},	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
	{636	,3	,1	,&iEM_TERR1VS22LIM},	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
	{637	,3	,1	,&iEM_TERR2SS11LIM},	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
	{638	,3	,1	,&iEM_TERR2SS21LIM},	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
	{639	,3	,1	,&iEM_TERR2VS12LIM},	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
	{640	,3	,1	,&iEM_TERR2VS22LIM},	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
	{641	,3	,1	,&iEM_TERR3SS11LIM},	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
	{642	,3	,1	,&iEM_TERR3SS21LIM},	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
	{643	,3	,1	,&iEM_TERR4MS21LIM},	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
	{644	,3	,1	,&iEM_TERR4SS11LIM},	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
	{645	,3	,1	,&iEM_TERR4SS12LIM},	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
	{646	,3	,1	,&iEM_TERR4SS22LIM},	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
	{647	,3	,1	,&iEM_TERR4VS12LDU},	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{648	,3	,1	,&iEM_TERR4VS22LDU},	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{649	,3	,1	,&iEM_TERR5SS11LIM},	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
	{650	,3	,1	,&iEM_TERR5SS21LIM},	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
	{651	,3	,1	,&iEM_TERR6IS62LIM},	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
	{652	,3	,1	,&iEM_TERR6IS64LIM},	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
	{653	,3	,1	,&iEM_TERR6IS66LIM},	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{654	,3	,1	,&iEM_TERR6SS21LIM},	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
	{655	,3	,1	,&iEM_TERR7SI74RIM},	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
	{656	,3	,1	,&iEM_TERR8SS11LIM},	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
	{657	,3	,1	,&iEM_TERRB1},	//(TERRB1) Неисправности  РБ1
	{658	,3	,1	,&iEM_TERRB2},	//(TERRB2) Неисправности  РБ2
	{659	,3	,1	,&iEM_TERTLG},	//(TERTLG) Неисправности  тележки от ИС
	{660	,1	,1	,&internal1_m1012_Out10},	//(internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{661	,1	,1	,&internal1_m1013_Out10},	//(internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{662	,1	,1	,&internal1_m1014_Out10},	//(internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{663	,1	,1	,&internal1_m1015_Out10},	//(internal1_m1015_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{664	,1	,1	,&internal1_m1016_Out10},	//(internal1_m1016_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{665	,1	,1	,&internal1_m1017_Out10},	//(internal1_m1017_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{666	,1	,1	,&internal1_m1018_Out10},	//(internal1_m1018_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{667	,1	,1	,&internal1_m1032_Out10},	//(internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{668	,1	,1	,&internal1_m1033_Out10},	//(internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{669	,1	,1	,&internal1_m1034_Out10},	//(internal1_m1034_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{670	,1	,1	,&internal1_m1035_Out10},	//(internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{671	,1	,1	,&internal1_m1036_Out10},	//(internal1_m1036_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{672	,1	,1	,&internal1_m1037_Out10},	//(internal1_m1037_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{673	,1	,1	,&internal1_m103_MyFirstEnterFlag},	//(internal1_m103_MyFirstEnterFlag) MyFirstEnterFlag
	{674	,1	,1	,&internal1_m103_Pav0},	//(internal1_m103_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{675	,1	,1	,&internal1_m103_Ppv0},	//(internal1_m103_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{676	,1	,1	,&internal1_m103_RA00},	//(internal1_m103_RA00) RA00 - последнее задание вперед
	{677	,1	,1	,&internal1_m103_RA10},	//(internal1_m103_RA10) RA10 - последнее задание назад
	{678	,1	,1	,&internal1_m103_RA30},	//(internal1_m103_RA30)  RA30 - разрешение движения
	{679	,1	,1	,&internal1_m103_RA50},	//(internal1_m103_RA50) Ra50 - последнее задание скорости
	{680	,8	,1	,&internal1_m103_RV00},	//(internal1_m103_RV00) V0 - текущая скорость ОРР
	{681	,8	,1	,&internal1_m103_Sh00},	//(internal1_m103_Sh00) Sh0 - текущая координата штока ОРР
	{682	,8	,1	,&internal1_m103_ShV00},	//(internal1_m103_ShV00) V0 - текущая скорость штока ОРР
	{683	,8	,1	,&internal1_m103_X00},	//(internal1_m103_X00) X0 - текущая координата ОРР
	{684	,1	,1	,&internal1_m103_Zav0},	//(internal1_m103_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{685	,1	,1	,&internal1_m103_flp},	//(internal1_m103_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{686	,1	,1	,&internal1_m103_fls},	//(internal1_m103_fls)  fls - флаг одношагового режима
	{687	,1	,1	,&internal1_m134_MyFirstEnterFlag},	//(internal1_m134_MyFirstEnterFlag) MyFirstEnterFlag
	{688	,1	,1	,&internal1_m134_Pav0},	//(internal1_m134_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{689	,1	,1	,&internal1_m134_Ppv0},	//(internal1_m134_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{690	,1	,1	,&internal1_m134_RA00},	//(internal1_m134_RA00) RA00 - последнее задание вперед
	{691	,1	,1	,&internal1_m134_RA10},	//(internal1_m134_RA10) RA10 - последнее задание назад
	{692	,1	,1	,&internal1_m134_RA30},	//(internal1_m134_RA30)  RA30 - разрешение движения
	{693	,1	,1	,&internal1_m134_RA50},	//(internal1_m134_RA50) Ra50 - последнее задание скорости
	{694	,8	,1	,&internal1_m134_RV00},	//(internal1_m134_RV00) V0 - текущая скорость ОРР
	{695	,8	,1	,&internal1_m134_Sh00},	//(internal1_m134_Sh00) Sh0 - текущая координата штока ОРР
	{696	,8	,1	,&internal1_m134_ShV00},	//(internal1_m134_ShV00) V0 - текущая скорость штока ОРР
	{697	,8	,1	,&internal1_m134_X00},	//(internal1_m134_X00) X0 - текущая координата ОРР
	{698	,1	,1	,&internal1_m134_Zav0},	//(internal1_m134_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{699	,1	,1	,&internal1_m134_flp},	//(internal1_m134_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{700	,1	,1	,&internal1_m134_fls},	//(internal1_m134_fls)  fls - флаг одношагового режима
	{701	,8	,1	,&internal1_m14_C1},	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{702	,8	,1	,&internal1_m14_C2},	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{703	,8	,1	,&internal1_m14_C3},	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{704	,8	,1	,&internal1_m14_C4},	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{705	,8	,1	,&internal1_m14_C5},	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{706	,8	,1	,&internal1_m14_C6},	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{707	,1	,1	,&internal1_m14_ImpINI0},	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{708	,1	,1	,&internal1_m14_MyFirstEnterFlag},	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
	{709	,8	,1	,&internal1_m14_N00},	//(internal1_m14_N00) N00 - Текущая концентрация нейтронов
	{710	,8	,1	,&internal1_m14_N20},	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
	{711	,8	,1	,&internal1_m14_R00},	//(internal1_m14_R00) R00 - Текущая реактивность
	{712	,8	,1	,&internal1_m14_T00},	//(internal1_m14_T00) T00 - Текущая температура
	{713	,1	,1	,&internal1_m151_Out10},	//(internal1_m151_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{714	,1	,1	,&internal1_m152_Out10},	//(internal1_m152_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{715	,8	,1	,&internal1_m176_x0},	//(internal1_m176_x0) x0 - значение входного параметра на предыдущем шаге
	{716	,8	,1	,&internal1_m186_C1},	//(internal1_m186_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{717	,8	,1	,&internal1_m186_C2},	//(internal1_m186_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{718	,8	,1	,&internal1_m186_C3},	//(internal1_m186_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{719	,8	,1	,&internal1_m186_C4},	//(internal1_m186_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{720	,8	,1	,&internal1_m186_C5},	//(internal1_m186_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{721	,8	,1	,&internal1_m186_C6},	//(internal1_m186_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{722	,1	,1	,&internal1_m186_ImpINI0},	//(internal1_m186_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{723	,1	,1	,&internal1_m186_MyFirstEnterFlag},	//(internal1_m186_MyFirstEnterFlag) MyFirstEnterFlag
	{724	,8	,1	,&internal1_m186_N00},	//(internal1_m186_N00) N00 - Текущая концентрация нейтронов
	{725	,8	,1	,&internal1_m186_N20},	//(internal1_m186_N20) N20 - пред. концентрация нейтронов второй АЗ
	{726	,8	,1	,&internal1_m186_R00},	//(internal1_m186_R00) R00 - Текущая реактивность
	{727	,8	,1	,&internal1_m186_T00},	//(internal1_m186_T00) T00 - Текущая температура
	{728	,1	,1	,&internal1_m211_Out10},	//(internal1_m211_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{729	,1	,1	,&internal1_m228_Out10},	//(internal1_m228_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{730	,1	,1	,&internal1_m232_MyFirstEnterFlag},	//(internal1_m232_MyFirstEnterFlag) MyFirstEnterFlag
	{731	,1	,1	,&internal1_m232_Pav0},	//(internal1_m232_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{732	,1	,1	,&internal1_m232_Ppv0},	//(internal1_m232_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{733	,1	,1	,&internal1_m232_RA00},	//(internal1_m232_RA00) RA00 - последнее задание вперед
	{734	,1	,1	,&internal1_m232_RA10},	//(internal1_m232_RA10) RA10 - последнее задание назад
	{735	,1	,1	,&internal1_m232_RA30},	//(internal1_m232_RA30)  RA30 - разрешение движения
	{736	,1	,1	,&internal1_m232_RA50},	//(internal1_m232_RA50) Ra50 - последнее задание скорости
	{737	,8	,1	,&internal1_m232_RV00},	//(internal1_m232_RV00) V0 - текущая скорость ОРР
	{738	,8	,1	,&internal1_m232_Sh00},	//(internal1_m232_Sh00) Sh0 - текущая координата штока ОРР
	{739	,8	,1	,&internal1_m232_ShV00},	//(internal1_m232_ShV00) V0 - текущая скорость штока ОРР
	{740	,8	,1	,&internal1_m232_X00},	//(internal1_m232_X00) X0 - текущая координата ОРР
	{741	,1	,1	,&internal1_m232_Zav0},	//(internal1_m232_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{742	,1	,1	,&internal1_m232_flp},	//(internal1_m232_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{743	,1	,1	,&internal1_m232_fls},	//(internal1_m232_fls)  fls - флаг одношагового режима
	{744	,1	,1	,&internal1_m267_MyFirstEnterFlag},	//(internal1_m267_MyFirstEnterFlag) MyFirstEnterFlag
	{745	,1	,1	,&internal1_m267_Pav0},	//(internal1_m267_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{746	,1	,1	,&internal1_m267_Ppv0},	//(internal1_m267_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{747	,1	,1	,&internal1_m267_RA00},	//(internal1_m267_RA00) RA00 - последнее задание вперед
	{748	,1	,1	,&internal1_m267_RA10},	//(internal1_m267_RA10) RA10 - последнее задание назад
	{749	,1	,1	,&internal1_m267_RA30},	//(internal1_m267_RA30)  RA30 - разрешение движения
	{750	,1	,1	,&internal1_m267_RA50},	//(internal1_m267_RA50) Ra50 - последнее задание скорости
	{751	,8	,1	,&internal1_m267_RV00},	//(internal1_m267_RV00) V0 - текущая скорость ОРР
	{752	,8	,1	,&internal1_m267_Sh00},	//(internal1_m267_Sh00) Sh0 - текущая координата штока ОРР
	{753	,8	,1	,&internal1_m267_ShV00},	//(internal1_m267_ShV00) V0 - текущая скорость штока ОРР
	{754	,8	,1	,&internal1_m267_X00},	//(internal1_m267_X00) X0 - текущая координата ОРР
	{755	,1	,1	,&internal1_m267_Zav0},	//(internal1_m267_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{756	,1	,1	,&internal1_m267_flp},	//(internal1_m267_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{757	,1	,1	,&internal1_m267_fls},	//(internal1_m267_fls)  fls - флаг одношагового режима
	{758	,1	,1	,&internal1_m300_MyFirstEnterFlag},	//(internal1_m300_MyFirstEnterFlag) MyFirstEnterFlag
	{759	,1	,1	,&internal1_m300_Pav0},	//(internal1_m300_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{760	,1	,1	,&internal1_m300_Ppv0},	//(internal1_m300_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{761	,1	,1	,&internal1_m300_RA00},	//(internal1_m300_RA00) RA00 - последнее задание вперед
	{762	,1	,1	,&internal1_m300_RA10},	//(internal1_m300_RA10) RA10 - последнее задание назад
	{763	,1	,1	,&internal1_m300_RA30},	//(internal1_m300_RA30)  RA30 - разрешение движения
	{764	,1	,1	,&internal1_m300_RA50},	//(internal1_m300_RA50) Ra50 - последнее задание скорости
	{765	,8	,1	,&internal1_m300_RV00},	//(internal1_m300_RV00) V0 - текущая скорость ОРР
	{766	,8	,1	,&internal1_m300_Sh00},	//(internal1_m300_Sh00) Sh0 - текущая координата штока ОРР
	{767	,8	,1	,&internal1_m300_ShV00},	//(internal1_m300_ShV00) V0 - текущая скорость штока ОРР
	{768	,8	,1	,&internal1_m300_X00},	//(internal1_m300_X00) X0 - текущая координата ОРР
	{769	,1	,1	,&internal1_m300_Zav0},	//(internal1_m300_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{770	,1	,1	,&internal1_m300_flp},	//(internal1_m300_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{771	,1	,1	,&internal1_m300_fls},	//(internal1_m300_fls)  fls - флаг одношагового режима
	{772	,1	,1	,&internal1_m319_Out10},	//(internal1_m319_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{773	,1	,1	,&internal1_m320_Out10},	//(internal1_m320_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{774	,1	,1	,&internal1_m321_Out10},	//(internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{775	,8	,1	,&internal1_m324_Xtek0},	//(internal1_m324_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{776	,8	,1	,&internal1_m334_Xtek0},	//(internal1_m334_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{777	,1	,1	,&internal1_m335_Out10},	//(internal1_m335_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{778	,1	,1	,&internal1_m336_Out10},	//(internal1_m336_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{779	,1	,1	,&internal1_m337_Out10},	//(internal1_m337_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{780	,1	,1	,&internal1_m347_Out10},	//(internal1_m347_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{781	,1	,1	,&internal1_m348_Out10},	//(internal1_m348_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{782	,1	,1	,&internal1_m349_Out10},	//(internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{783	,1	,1	,&internal1_m350_Out10},	//(internal1_m350_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{784	,1	,1	,&internal1_m364_MyFirstEnterFlag},	//(internal1_m364_MyFirstEnterFlag) MyFirstEnterFlag
	{785	,1	,1	,&internal1_m364_Pav0},	//(internal1_m364_Pav0)  - Пер.аварийный выключатель механизма
	{786	,1	,1	,&internal1_m364_Pv0},	//(internal1_m364_Pv0)  - Пер. выключатель механизма
	{787	,1	,1	,&internal1_m364_RA00},	//(internal1_m364_RA00)  - последнее задание вперед
	{788	,1	,1	,&internal1_m364_RA10},	//(internal1_m364_RA10)  - последнее задание назад
	{789	,8	,1	,&internal1_m364_V00},	//(internal1_m364_V00)  V00 - текущая скорость механизма
	{790	,8	,1	,&internal1_m364_X00},	//(internal1_m364_X00)  X00 - текущая координата механизма
	{791	,1	,1	,&internal1_m364_Zav0},	//(internal1_m364_Zav0)  - Зад.аварийный выключатель механизма
	{792	,1	,1	,&internal1_m364_Zv0},	//(internal1_m364_Zv0)  - Зад. выключатель механизма
	{793	,1	,1	,&internal1_m380_MyFirstEnterFlag},	//(internal1_m380_MyFirstEnterFlag) MyFirstEnterFlag
	{794	,1	,1	,&internal1_m380_Pav0},	//(internal1_m380_Pav0)  - Пер.аварийный выключатель механизма
	{795	,1	,1	,&internal1_m380_Pv0},	//(internal1_m380_Pv0)  - Пер. выключатель механизма
	{796	,1	,1	,&internal1_m380_RA00},	//(internal1_m380_RA00)  - последнее задание вперед
	{797	,1	,1	,&internal1_m380_RA10},	//(internal1_m380_RA10)  - последнее задание назад
	{798	,8	,1	,&internal1_m380_V00},	//(internal1_m380_V00)  V00 - текущая скорость механизма
	{799	,8	,1	,&internal1_m380_X00},	//(internal1_m380_X00)  X00 - текущая координата механизма
	{800	,1	,1	,&internal1_m380_Zav0},	//(internal1_m380_Zav0)  - Зад.аварийный выключатель механизма
	{801	,1	,1	,&internal1_m380_Zv0},	//(internal1_m380_Zv0)  - Зад. выключатель механизма
	{802	,1	,1	,&internal1_m395_MyFirstEnterFlag},	//(internal1_m395_MyFirstEnterFlag) MyFirstEnterFlag
	{803	,1	,1	,&internal1_m395_Pav0},	//(internal1_m395_Pav0)  - Пер.аварийный выключатель механизма
	{804	,1	,1	,&internal1_m395_Pv0},	//(internal1_m395_Pv0)  - Пер. выключатель механизма
	{805	,1	,1	,&internal1_m395_RA00},	//(internal1_m395_RA00)  - последнее задание вперед
	{806	,1	,1	,&internal1_m395_RA10},	//(internal1_m395_RA10)  - последнее задание назад
	{807	,8	,1	,&internal1_m395_V00},	//(internal1_m395_V00)  V00 - текущая скорость механизма
	{808	,8	,1	,&internal1_m395_X00},	//(internal1_m395_X00)  X00 - текущая координата механизма
	{809	,1	,1	,&internal1_m395_Zav0},	//(internal1_m395_Zav0)  - Зад.аварийный выключатель механизма
	{810	,1	,1	,&internal1_m395_Zv0},	//(internal1_m395_Zv0)  - Зад. выключатель механизма
	{811	,1	,1	,&internal1_m39_fef},	//(internal1_m39_fef) fef
	{812	,3	,1	,&internal1_m39_reg},	//(internal1_m39_reg) режим работы квдс 0 - ожидание сигнала 1- выдан импульс 2 отсчет удержания синхроимпульса 3 -блокировка
	{813	,8	,1	,&internal1_m39_tgen},	//(internal1_m39_tgen) задержки срабатывания генератора импульса
	{814	,8	,1	,&internal1_m39_tlock},	//(internal1_m39_tlock) время до конца блокировки
	{815	,8	,1	,&internal1_m39_tsin},	//(internal1_m39_tsin) время до конца удержания синхроимпульса
	{816	,1	,1	,&internal1_m406_Out10},	//(internal1_m406_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{817	,1	,1	,&internal1_m407_Out10},	//(internal1_m407_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{818	,1	,1	,&internal1_m408_Out10},	//(internal1_m408_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{819	,1	,1	,&internal1_m409_Out10},	//(internal1_m409_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{820	,8	,1	,&internal1_m416_Xtek0},	//(internal1_m416_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{821	,1	,1	,&internal1_m425_Out10},	//(internal1_m425_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{822	,1	,1	,&internal1_m426_Out10},	//(internal1_m426_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{823	,1	,1	,&internal1_m427_Out10},	//(internal1_m427_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{824	,1	,1	,&internal1_m428_Out10},	//(internal1_m428_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{825	,8	,1	,&internal1_m429_Xtek0},	//(internal1_m429_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{826	,1	,1	,&internal1_m443_MyFirstEnterFlag},	//(internal1_m443_MyFirstEnterFlag) MyFirstEnterFlag
	{827	,1	,1	,&internal1_m443_Pav0},	//(internal1_m443_Pav0)  - Пер.аварийный выключатель механизма
	{828	,1	,1	,&internal1_m443_Pv0},	//(internal1_m443_Pv0)  - Пер. выключатель механизма
	{829	,1	,1	,&internal1_m443_RA00},	//(internal1_m443_RA00)  - последнее задание вперед
	{830	,1	,1	,&internal1_m443_RA10},	//(internal1_m443_RA10)  - последнее задание назад
	{831	,8	,1	,&internal1_m443_V00},	//(internal1_m443_V00)  V00 - текущая скорость механизма
	{832	,8	,1	,&internal1_m443_X00},	//(internal1_m443_X00)  X00 - текущая координата механизма
	{833	,1	,1	,&internal1_m443_Zav0},	//(internal1_m443_Zav0)  - Зад.аварийный выключатель механизма
	{834	,1	,1	,&internal1_m443_Zv0},	//(internal1_m443_Zv0)  - Зад. выключатель механизма
	{835	,1	,1	,&internal1_m457_MyFirstEnterFlag},	//(internal1_m457_MyFirstEnterFlag) MyFirstEnterFlag
	{836	,1	,1	,&internal1_m457_Pav0},	//(internal1_m457_Pav0)  - Пер.аварийный выключатель механизма
	{837	,1	,1	,&internal1_m457_Pv0},	//(internal1_m457_Pv0)  - Пер. выключатель механизма
	{838	,1	,1	,&internal1_m457_RA00},	//(internal1_m457_RA00)  - последнее задание вперед
	{839	,1	,1	,&internal1_m457_RA10},	//(internal1_m457_RA10)  - последнее задание назад
	{840	,8	,1	,&internal1_m457_V00},	//(internal1_m457_V00)  V00 - текущая скорость механизма
	{841	,8	,1	,&internal1_m457_X00},	//(internal1_m457_X00)  X00 - текущая координата механизма
	{842	,1	,1	,&internal1_m457_Zav0},	//(internal1_m457_Zav0)  - Зад.аварийный выключатель механизма
	{843	,1	,1	,&internal1_m457_Zv0},	//(internal1_m457_Zv0)  - Зад. выключатель механизма
	{844	,1	,1	,&internal1_m467_q0},	//(internal1_m467_q0) q0 - внутренний параметр
	{845	,1	,1	,&internal1_m468_q0},	//(internal1_m468_q0) q0 - внутренний параметр
	{846	,1	,1	,&internal1_m471_MyFirstEnterFlag},	//(internal1_m471_MyFirstEnterFlag) MyFirstEnterFlag
	{847	,1	,1	,&internal1_m471_Pav0},	//(internal1_m471_Pav0)  - Пер.аварийный выключатель механизма
	{848	,1	,1	,&internal1_m471_Pv0},	//(internal1_m471_Pv0)  - Пер. выключатель механизма
	{849	,1	,1	,&internal1_m471_RA00},	//(internal1_m471_RA00)  - последнее задание вперед
	{850	,1	,1	,&internal1_m471_RA10},	//(internal1_m471_RA10)  - последнее задание назад
	{851	,8	,1	,&internal1_m471_V00},	//(internal1_m471_V00)  V00 - текущая скорость механизма
	{852	,8	,1	,&internal1_m471_X00},	//(internal1_m471_X00)  X00 - текущая координата механизма
	{853	,1	,1	,&internal1_m471_Zav0},	//(internal1_m471_Zav0)  - Зад.аварийный выключатель механизма
	{854	,1	,1	,&internal1_m471_Zv0},	//(internal1_m471_Zv0)  - Зад. выключатель механизма
	{855	,1	,1	,&internal1_m473_MyFirstEnterFlag},	//(internal1_m473_MyFirstEnterFlag) MyFirstEnterFlag
	{856	,1	,1	,&internal1_m473_Pav0},	//(internal1_m473_Pav0)  - Пер.аварийный выключатель механизма
	{857	,1	,1	,&internal1_m473_Pv0},	//(internal1_m473_Pv0)  - Пер. выключатель механизма
	{858	,1	,1	,&internal1_m473_RA00},	//(internal1_m473_RA00)  - последнее задание вперед
	{859	,1	,1	,&internal1_m473_RA10},	//(internal1_m473_RA10)  - последнее задание назад
	{860	,8	,1	,&internal1_m473_V00},	//(internal1_m473_V00)  V00 - текущая скорость механизма
	{861	,8	,1	,&internal1_m473_X00},	//(internal1_m473_X00)  X00 - текущая координата механизма
	{862	,1	,1	,&internal1_m473_Zav0},	//(internal1_m473_Zav0)  - Зад.аварийный выключатель механизма
	{863	,1	,1	,&internal1_m473_Zv0},	//(internal1_m473_Zv0)  - Зад. выключатель механизма
	{864	,1	,1	,&internal1_m479_q0},	//(internal1_m479_q0) q0 - внутренний параметр
	{865	,1	,1	,&internal1_m47_Out10},	//(internal1_m47_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{866	,1	,1	,&internal1_m480_q0},	//(internal1_m480_q0) q0 - внутренний параметр
	{867	,1	,1	,&internal1_m483_MyFirstEnterFlag},	//(internal1_m483_MyFirstEnterFlag) MyFirstEnterFlag
	{868	,1	,1	,&internal1_m483_Pav0},	//(internal1_m483_Pav0)  - Пер.аварийный выключатель механизма
	{869	,1	,1	,&internal1_m483_Pv0},	//(internal1_m483_Pv0)  - Пер. выключатель механизма
	{870	,1	,1	,&internal1_m483_RA00},	//(internal1_m483_RA00)  - последнее задание вперед
	{871	,1	,1	,&internal1_m483_RA10},	//(internal1_m483_RA10)  - последнее задание назад
	{872	,8	,1	,&internal1_m483_V00},	//(internal1_m483_V00)  V00 - текущая скорость механизма
	{873	,8	,1	,&internal1_m483_X00},	//(internal1_m483_X00)  X00 - текущая координата механизма
	{874	,1	,1	,&internal1_m483_Zav0},	//(internal1_m483_Zav0)  - Зад.аварийный выключатель механизма
	{875	,1	,1	,&internal1_m483_Zv0},	//(internal1_m483_Zv0)  - Зад. выключатель механизма
	{876	,1	,1	,&internal1_m494_MyFirstEnterFlag},	//(internal1_m494_MyFirstEnterFlag) MyFirstEnterFlag
	{877	,1	,1	,&internal1_m494_Pav0},	//(internal1_m494_Pav0)  - Пер.аварийный выключатель механизма
	{878	,1	,1	,&internal1_m494_Pv0},	//(internal1_m494_Pv0)  - Пер. выключатель механизма
	{879	,1	,1	,&internal1_m494_RA00},	//(internal1_m494_RA00)  - последнее задание вперед
	{880	,1	,1	,&internal1_m494_RA10},	//(internal1_m494_RA10)  - последнее задание назад
	{881	,8	,1	,&internal1_m494_V00},	//(internal1_m494_V00)  V00 - текущая скорость механизма
	{882	,8	,1	,&internal1_m494_X00},	//(internal1_m494_X00)  X00 - текущая координата механизма
	{883	,1	,1	,&internal1_m494_Zav0},	//(internal1_m494_Zav0)  - Зад.аварийный выключатель механизма
	{884	,1	,1	,&internal1_m494_Zv0},	//(internal1_m494_Zv0)  - Зад. выключатель механизма
	{885	,1	,1	,&internal1_m518_Out10},	//(internal1_m518_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{886	,1	,1	,&internal1_m534_Out10},	//(internal1_m534_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{887	,1	,1	,&internal1_m535_Out10},	//(internal1_m535_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{888	,1	,1	,&internal1_m550_Out10},	//(internal1_m550_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{889	,1	,1	,&internal1_m551_Out10},	//(internal1_m551_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{890	,1	,1	,&internal1_m552_Out10},	//(internal1_m552_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{891	,1	,1	,&internal1_m566_MyFirstEnterFlag},	//(internal1_m566_MyFirstEnterFlag) MyFirstEnterFlag
	{892	,1	,1	,&internal1_m566_Pav0},	//(internal1_m566_Pav0)  - Пер.аварийный выключатель механизма
	{893	,1	,1	,&internal1_m566_Pv0},	//(internal1_m566_Pv0)  - Пер. выключатель механизма
	{894	,1	,1	,&internal1_m566_RA00},	//(internal1_m566_RA00)  - последнее задание вперед
	{895	,1	,1	,&internal1_m566_RA10},	//(internal1_m566_RA10)  - последнее задание назад
	{896	,8	,1	,&internal1_m566_V00},	//(internal1_m566_V00)  V00 - текущая скорость механизма
	{897	,8	,1	,&internal1_m566_X00},	//(internal1_m566_X00)  X00 - текущая координата механизма
	{898	,1	,1	,&internal1_m566_Zav0},	//(internal1_m566_Zav0)  - Зад.аварийный выключатель механизма
	{899	,1	,1	,&internal1_m566_Zv0},	//(internal1_m566_Zv0)  - Зад. выключатель механизма
	{900	,1	,1	,&internal1_m580_MyFirstEnterFlag},	//(internal1_m580_MyFirstEnterFlag) MyFirstEnterFlag
	{901	,1	,1	,&internal1_m580_Pav0},	//(internal1_m580_Pav0)  - Пер.аварийный выключатель механизма
	{902	,1	,1	,&internal1_m580_Pv0},	//(internal1_m580_Pv0)  - Пер. выключатель механизма
	{903	,1	,1	,&internal1_m580_RA00},	//(internal1_m580_RA00)  - последнее задание вперед
	{904	,1	,1	,&internal1_m580_RA10},	//(internal1_m580_RA10)  - последнее задание назад
	{905	,8	,1	,&internal1_m580_V00},	//(internal1_m580_V00)  V00 - текущая скорость механизма
	{906	,8	,1	,&internal1_m580_X00},	//(internal1_m580_X00)  X00 - текущая координата механизма
	{907	,1	,1	,&internal1_m580_Zav0},	//(internal1_m580_Zav0)  - Зад.аварийный выключатель механизма
	{908	,1	,1	,&internal1_m580_Zv0},	//(internal1_m580_Zv0)  - Зад. выключатель механизма
	{909	,1	,1	,&internal1_m592_MyFirstEnterFlag},	//(internal1_m592_MyFirstEnterFlag) MyFirstEnterFlag
	{910	,1	,1	,&internal1_m592_Pav0},	//(internal1_m592_Pav0)  - Пер.аварийный выключатель механизма
	{911	,1	,1	,&internal1_m592_Pv0},	//(internal1_m592_Pv0)  - Пер. выключатель механизма
	{912	,1	,1	,&internal1_m592_RA00},	//(internal1_m592_RA00)  - последнее задание вперед
	{913	,1	,1	,&internal1_m592_RA10},	//(internal1_m592_RA10)  - последнее задание назад
	{914	,8	,1	,&internal1_m592_V00},	//(internal1_m592_V00)  V00 - текущая скорость механизма
	{915	,8	,1	,&internal1_m592_X00},	//(internal1_m592_X00)  X00 - текущая координата механизма
	{916	,1	,1	,&internal1_m592_Zav0},	//(internal1_m592_Zav0)  - Зад.аварийный выключатель механизма
	{917	,1	,1	,&internal1_m592_Zv0},	//(internal1_m592_Zv0)  - Зад. выключатель механизма
	{918	,1	,1	,&internal1_m593_MyFirstEnterFlag},	//(internal1_m593_MyFirstEnterFlag) MyFirstEnterFlag
	{919	,1	,1	,&internal1_m593_Pav0},	//(internal1_m593_Pav0)  - Пер.аварийный выключатель механизма
	{920	,1	,1	,&internal1_m593_Pv0},	//(internal1_m593_Pv0)  - Пер. выключатель механизма
	{921	,1	,1	,&internal1_m593_RA00},	//(internal1_m593_RA00)  - последнее задание вперед
	{922	,1	,1	,&internal1_m593_RA10},	//(internal1_m593_RA10)  - последнее задание назад
	{923	,8	,1	,&internal1_m593_V00},	//(internal1_m593_V00)  V00 - текущая скорость механизма
	{924	,8	,1	,&internal1_m593_X00},	//(internal1_m593_X00)  X00 - текущая координата механизма
	{925	,1	,1	,&internal1_m593_Zav0},	//(internal1_m593_Zav0)  - Зад.аварийный выключатель механизма
	{926	,1	,1	,&internal1_m593_Zv0},	//(internal1_m593_Zv0)  - Зад. выключатель механизма
	{927	,8	,1	,&internal1_m601_tx},	//(internal1_m601_tx) tx - время накопленное сек
	{928	,18	,1	,&internal1_m601_y0},	//(internal1_m601_y0) y0
	{929	,8	,1	,&internal1_m603_tx},	//(internal1_m603_tx) tx - время накопленное сек
	{930	,18	,1	,&internal1_m603_y0},	//(internal1_m603_y0) y0
	{931	,1	,1	,&internal1_m605_MyFirstEnterFlag},	//(internal1_m605_MyFirstEnterFlag) MyFirstEnterFlag
	{932	,1	,1	,&internal1_m605_Pav0},	//(internal1_m605_Pav0)  - Пер.аварийный выключатель механизма
	{933	,1	,1	,&internal1_m605_Pv0},	//(internal1_m605_Pv0)  - Пер. выключатель механизма
	{934	,1	,1	,&internal1_m605_RA00},	//(internal1_m605_RA00)  - последнее задание вперед
	{935	,1	,1	,&internal1_m605_RA10},	//(internal1_m605_RA10)  - последнее задание назад
	{936	,8	,1	,&internal1_m605_V00},	//(internal1_m605_V00)  V00 - текущая скорость механизма
	{937	,8	,1	,&internal1_m605_X00},	//(internal1_m605_X00)  X00 - текущая координата механизма
	{938	,1	,1	,&internal1_m605_Zav0},	//(internal1_m605_Zav0)  - Зад.аварийный выключатель механизма
	{939	,1	,1	,&internal1_m605_Zv0},	//(internal1_m605_Zv0)  - Зад. выключатель механизма
	{940	,1	,1	,&internal1_m606_MyFirstEnterFlag},	//(internal1_m606_MyFirstEnterFlag) MyFirstEnterFlag
	{941	,1	,1	,&internal1_m606_Pav0},	//(internal1_m606_Pav0)  - Пер.аварийный выключатель механизма
	{942	,1	,1	,&internal1_m606_Pv0},	//(internal1_m606_Pv0)  - Пер. выключатель механизма
	{943	,1	,1	,&internal1_m606_RA00},	//(internal1_m606_RA00)  - последнее задание вперед
	{944	,1	,1	,&internal1_m606_RA10},	//(internal1_m606_RA10)  - последнее задание назад
	{945	,8	,1	,&internal1_m606_V00},	//(internal1_m606_V00)  V00 - текущая скорость механизма
	{946	,8	,1	,&internal1_m606_X00},	//(internal1_m606_X00)  X00 - текущая координата механизма
	{947	,1	,1	,&internal1_m606_Zav0},	//(internal1_m606_Zav0)  - Зад.аварийный выключатель механизма
	{948	,1	,1	,&internal1_m606_Zv0},	//(internal1_m606_Zv0)  - Зад. выключатель механизма
	{949	,8	,1	,&internal1_m613_tx},	//(internal1_m613_tx) tx - время накопленное сек
	{950	,18	,1	,&internal1_m613_y0},	//(internal1_m613_y0) y0
	{951	,8	,1	,&internal1_m626_tx},	//(internal1_m626_tx) tx - время накопленное сек
	{952	,18	,1	,&internal1_m626_y0},	//(internal1_m626_y0) y0
	{953	,1	,1	,&internal1_m62_Out10},	//(internal1_m62_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{954	,8	,1	,&internal1_m637_y0},	//(internal1_m637_y0) y0 - внутренний параметр
	{955	,1	,1	,&internal1_m653_Out10},	//(internal1_m653_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{956	,1	,1	,&internal1_m654_Out10},	//(internal1_m654_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{957	,1	,1	,&internal1_m655_Out10},	//(internal1_m655_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{958	,1	,1	,&internal1_m656_Out10},	//(internal1_m656_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{959	,1	,1	,&internal1_m657_Out10},	//(internal1_m657_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{960	,1	,1	,&internal1_m658_Out10},	//(internal1_m658_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{961	,1	,1	,&internal1_m66_MyFirstEnterFlag},	//(internal1_m66_MyFirstEnterFlag) MyFirstEnterFlag
	{962	,1	,1	,&internal1_m66_Pav0},	//(internal1_m66_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{963	,1	,1	,&internal1_m66_Ppv0},	//(internal1_m66_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{964	,1	,1	,&internal1_m66_RA00},	//(internal1_m66_RA00) RA00 - последнее задание вперед
	{965	,1	,1	,&internal1_m66_RA10},	//(internal1_m66_RA10) RA10 - последнее задание назад
	{966	,1	,1	,&internal1_m66_RA30},	//(internal1_m66_RA30)  RA30 - разрешение движения
	{967	,1	,1	,&internal1_m66_RA50},	//(internal1_m66_RA50) Ra50 - последнее задание скорости
	{968	,8	,1	,&internal1_m66_RV00},	//(internal1_m66_RV00) V0 - текущая скорость ОРР
	{969	,8	,1	,&internal1_m66_Sh00},	//(internal1_m66_Sh00) Sh0 - текущая координата штока ОРР
	{970	,8	,1	,&internal1_m66_ShV00},	//(internal1_m66_ShV00) V0 - текущая скорость штока ОРР
	{971	,8	,1	,&internal1_m66_X00},	//(internal1_m66_X00) X0 - текущая координата ОРР
	{972	,1	,1	,&internal1_m66_Zav0},	//(internal1_m66_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{973	,1	,1	,&internal1_m66_flp},	//(internal1_m66_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{974	,1	,1	,&internal1_m66_fls},	//(internal1_m66_fls)  fls - флаг одношагового режима
	{975	,1	,1	,&internal1_m673_Out10},	//(internal1_m673_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{976	,1	,1	,&internal1_m675_Out10},	//(internal1_m675_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{977	,1	,1	,&internal1_m676_Out10},	//(internal1_m676_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{978	,1	,1	,&internal1_m677_Out10},	//(internal1_m677_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{979	,1	,1	,&internal1_m678_Out10},	//(internal1_m678_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{980	,1	,1	,&internal1_m687_Out10},	//(internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{981	,1	,1	,&internal1_m688_Out10},	//(internal1_m688_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{982	,1	,1	,&internal1_m689_Out10},	//(internal1_m689_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{983	,1	,1	,&internal1_m690_Out10},	//(internal1_m690_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{984	,8	,1	,&internal1_m702_Chim0},	//(internal1_m702_Chim0) измеренная частота импульсов камеры Гц
	{985	,8	,1	,&internal1_m712_Chim0},	//(internal1_m712_Chim0) измеренная частота импульсов камеры Гц
	{986	,8	,1	,&internal1_m721_Chim0},	//(internal1_m721_Chim0) измеренная частота импульсов камеры Гц
	{987	,8	,1	,&internal1_m730_Chim0},	//(internal1_m730_Chim0) измеренная частота импульсов камеры Гц
	{988	,8	,1	,&internal1_m738_Chim0},	//(internal1_m738_Chim0) измеренная частота импульсов камеры Гц
	{989	,8	,1	,&internal1_m747_Chim0},	//(internal1_m747_Chim0) измеренная частота импульсов камеры Гц
	{990	,8	,1	,&internal1_m756_Chim0},	//(internal1_m756_Chim0) измеренная частота импульсов камеры Гц
	{991	,8	,1	,&internal1_m764_Chim0},	//(internal1_m764_Chim0) измеренная частота импульсов камеры Гц
	{992	,8	,1	,&internal1_m773_Chim0},	//(internal1_m773_Chim0) измеренная частота импульсов камеры Гц
	{993	,8	,1	,&internal1_m782_Chim0},	//(internal1_m782_Chim0) измеренная частота импульсов камеры Гц
	{994	,8	,1	,&internal1_m790_Chim0},	//(internal1_m790_Chim0) измеренная частота импульсов камеры Гц
	{995	,8	,1	,&internal1_m799_Chim0},	//(internal1_m799_Chim0) измеренная частота импульсов камеры Гц
	{996	,1	,1	,&internal1_m811_Out10},	//(internal1_m811_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{997	,1	,1	,&internal1_m812_Out10},	//(internal1_m812_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{998	,1	,1	,&internal1_m813_Out10},	//(internal1_m813_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{999	,1	,1	,&internal1_m814_Out10},	//(internal1_m814_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1000	,1	,1	,&internal1_m815_Out10},	//(internal1_m815_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1001	,1	,1	,&internal1_m816_Out10},	//(internal1_m816_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1002	,1	,1	,&internal1_m817_Out10},	//(internal1_m817_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1003	,8	,1	,&internal1_m834_Xtek0},	//(internal1_m834_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{1004	,8	,1	,&internal1_m836_Xtek0},	//(internal1_m836_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{1005	,1	,1	,&internal1_m837_Out10},	//(internal1_m837_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1006	,1	,1	,&internal1_m838_Out10},	//(internal1_m838_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1007	,1	,1	,&internal1_m839_Out10},	//(internal1_m839_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1008	,1	,1	,&internal1_m840_Out10},	//(internal1_m840_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1009	,1	,1	,&internal1_m852_Out10},	//(internal1_m852_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1010	,1	,1	,&internal1_m853_Out10},	//(internal1_m853_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1011	,1	,1	,&internal1_m854_Out10},	//(internal1_m854_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1012	,8	,1	,&internal1_m862_Chim0},	//(internal1_m862_Chim0) измеренная частота импульсов камеры Гц
	{1013	,8	,1	,&internal1_m870_Chim0},	//(internal1_m870_Chim0) измеренная частота импульсов камеры Гц
	{1014	,8	,1	,&internal1_m880_Chim0},	//(internal1_m880_Chim0) измеренная частота импульсов камеры Гц
	{1015	,1	,1	,&internal1_m892_MyFirstEnterFlag},	//(internal1_m892_MyFirstEnterFlag) MyFirstEnterFlag
	{1016	,1	,1	,&internal1_m892_Pav0},	//(internal1_m892_Pav0)  - Пер.аварийный выключатель механизма
	{1017	,1	,1	,&internal1_m892_Pv0},	//(internal1_m892_Pv0)  - Пер. выключатель механизма
	{1018	,1	,1	,&internal1_m892_RA00},	//(internal1_m892_RA00)  - последнее задание вперед
	{1019	,1	,1	,&internal1_m892_RA10},	//(internal1_m892_RA10)  - последнее задание назад
	{1020	,8	,1	,&internal1_m892_V00},	//(internal1_m892_V00)  V00 - текущая скорость механизма
	{1021	,8	,1	,&internal1_m892_X00},	//(internal1_m892_X00)  X00 - текущая координата механизма
	{1022	,1	,1	,&internal1_m892_Zav0},	//(internal1_m892_Zav0)  - Зад.аварийный выключатель механизма
	{1023	,1	,1	,&internal1_m892_Zv0},	//(internal1_m892_Zv0)  - Зад. выключатель механизма
	{1024	,1	,1	,&internal1_m949_Out10},	//(internal1_m949_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1025	,1	,1	,&internal1_m950_Out10},	//(internal1_m950_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1026	,8	,1	,&internal1_m952_Xtek0},	//(internal1_m952_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{1027	,1	,1	,&internal1_m953_Out10},	//(internal1_m953_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1028	,1	,1	,&internal1_m966_Out10},	//(internal1_m966_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1029	,1	,1	,&internal1_m967_Out10},	//(internal1_m967_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1030	,8	,1	,&internal1_m969_Xtek0},	//(internal1_m969_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{1031	,1	,1	,&internal1_m970_Out10},	//(internal1_m970_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1032	,1	,1	,&internal1_m980_Out10},	//(internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1033	,1	,1	,&internal1_m981_Out10},	//(internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1034	,1	,1	,&internal1_m982_Out10},	//(internal1_m982_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1035	,1	,1	,&internal1_m983_Out10},	//(internal1_m983_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1036	,1	,1	,&internal1_m984_Out10},	//(internal1_m984_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1037	,1	,1	,&internal1_m995_Out10},	//(internal1_m995_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1038	,1	,1	,&internal1_m996_Out10},	//(internal1_m996_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1039	,1	,1	,&internal1_m997_Out10},	//(internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1040	,1	,1	,&internal1_m998_Out10},	//(internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1041	,1	,1	,&internal1_m999_Out10},	//(internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{1042	,8	,1	,&krb1},	//( - , - ) 
	{1043	,8	,1	,&krb2},	//( - , - ) 
	{1044	,1	,1	,&lEM_C1AD31LRP},	//(C1AD31LRP) Общий сброс от РПУ
	{1045	,1	,1	,&lEM_R0IE01LRP},	//(R0IE01LRP) Отключение питание детекторов
	{1046	,1	,1	,&lEM_R0IE02LRP},	//(R0IE02LRP) Отключить питание ПР, ПУ
	{1047	,1	,1	,&lEM_R3AD10LC1},	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
	{1048	,1	,1	,&lEM_R3AD20LC1},	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
	{1049	,1	,1	,&lEM_R5AD10LC1},	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
	{1050	,1	,1	,&lEM_R5AD20LC1},	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
	{1051	,1	,1	,&lEM_R6AD10LC1},	//(R6AD10LC1) Выкатить кран-балку от ИС
	{1052	,1	,1	,&lEM_R8AD10LC1},	//(R8AD10LC1) Установить аварийный НИ от ИС
	{1053	,1	,1	,&vainSBool},	//Внутренняя переменная vainSBool
	{1054	,8	,1	,&vainSFloat},	//Внутренняя переменная vainSFloat
	{1055	,5	,1	,&vainSInt},	//Внутренняя переменная vainSInt
	{1056	,11	,1	,&vainSLong},	//Внутренняя переменная vainSLong
	{1057	,1	,1	,&var1},	//Внутренняя переменная var1
	{1058	,8	,1	,&var10},	//Внутренняя переменная var10
	{1059	,11	,1	,&var100},	//Внутренняя переменная var100
	{1060	,8	,1	,&var101},	//Внутренняя переменная var101
	{1061	,1	,1	,&var102},	//Внутренняя переменная var102
	{1062	,1	,1	,&var103},	//Внутренняя переменная var103
	{1063	,1	,1	,&var104},	//Внутренняя переменная var104
	{1064	,1	,1	,&var105},	//Внутренняя переменная var105
	{1065	,1	,1	,&var106},	//Внутренняя переменная var106
	{1066	,1	,1	,&var107},	//Внутренняя переменная var107
	{1067	,1	,1	,&var108},	//Внутренняя переменная var108
	{1068	,1	,1	,&var109},	//Внутренняя переменная var109
	{1069	,8	,1	,&var11},	//Внутренняя переменная var11
	{1070	,1	,1	,&var110},	//Внутренняя переменная var110
	{1071	,1	,1	,&var111},	//Внутренняя переменная var111
	{1072	,1	,1	,&var112},	//Внутренняя переменная var112
	{1073	,8	,1	,&var113},	//Внутренняя переменная var113
	{1074	,1	,1	,&var114},	//Внутренняя переменная var114
	{1075	,1	,1	,&var115},	//Внутренняя переменная var115
	{1076	,11	,1	,&var116},	//Внутренняя переменная var116
	{1077	,8	,1	,&var117},	//Внутренняя переменная var117
	{1078	,11	,1	,&var118},	//Внутренняя переменная var118
	{1079	,8	,1	,&var119},	//Внутренняя переменная var119
	{1080	,1	,1	,&var12},	//Внутренняя переменная var12
	{1081	,1	,1	,&var120},	//Внутренняя переменная var120
	{1082	,1	,1	,&var121},	//Внутренняя переменная var121
	{1083	,1	,1	,&var122},	//Внутренняя переменная var122
	{1084	,1	,1	,&var123},	//Внутренняя переменная var123
	{1085	,1	,1	,&var124},	//Внутренняя переменная var124
	{1086	,1	,1	,&var125},	//Внутренняя переменная var125
	{1087	,1	,1	,&var126},	//Внутренняя переменная var126
	{1088	,1	,1	,&var127},	//Внутренняя переменная var127
	{1089	,1	,1	,&var128},	//Внутренняя переменная var128
	{1090	,1	,1	,&var129},	//Внутренняя переменная var129
	{1091	,1	,1	,&var13},	//Внутренняя переменная var13
	{1092	,5	,1	,&var130},	//Внутренняя переменная var130
	{1093	,8	,1	,&var131},	//Внутренняя переменная var131
	{1094	,1	,1	,&var132},	//Внутренняя переменная var132
	{1095	,1	,1	,&var133},	//Внутренняя переменная var133
	{1096	,5	,1	,&var134},	//Внутренняя переменная var134
	{1097	,8	,1	,&var135},	//Внутренняя переменная var135
	{1098	,1	,1	,&var136},	//Внутренняя переменная var136
	{1099	,11	,1	,&var137},	//Внутренняя переменная var137
	{1100	,8	,1	,&var138},	//Внутренняя переменная var138
	{1101	,1	,1	,&var139},	//Внутренняя переменная var139
	{1102	,1	,1	,&var14},	//Внутренняя переменная var14
	{1103	,1	,1	,&var140},	//Внутренняя переменная var140
	{1104	,11	,1	,&var141},	//Внутренняя переменная var141
	{1105	,8	,1	,&var142},	//Внутренняя переменная var142
	{1106	,1	,1	,&var143},	//Внутренняя переменная var143
	{1107	,5	,1	,&var144},	//Внутренняя переменная var144
	{1108	,5	,1	,&var145},	//Внутренняя переменная var145
	{1109	,1	,1	,&var146},	//Внутренняя переменная var146
	{1110	,1	,1	,&var147},	//Внутренняя переменная var147
	{1111	,1	,1	,&var148},	//Внутренняя переменная var148
	{1112	,11	,1	,&var149},	//Внутренняя переменная var149
	{1113	,1	,1	,&var15},	//Внутренняя переменная var15
	{1114	,8	,1	,&var150},	//Внутренняя переменная var150
	{1115	,1	,1	,&var151},	//Внутренняя переменная var151
	{1116	,1	,1	,&var152},	//Внутренняя переменная var152
	{1117	,1	,1	,&var153},	//Внутренняя переменная var153
	{1118	,8	,1	,&var154},	//Внутренняя переменная var154
	{1119	,8	,1	,&var155},	//Внутренняя переменная var155
	{1120	,8	,1	,&var156},	//Внутренняя переменная var156
	{1121	,5	,1	,&var157},	//Внутренняя переменная var157
	{1122	,5	,1	,&var158},	//Внутренняя переменная var158
	{1123	,5	,1	,&var159},	//Внутренняя переменная var159
	{1124	,1	,1	,&var16},	//Внутренняя переменная var16
	{1125	,8	,1	,&var160},	//Внутренняя переменная var160
	{1126	,8	,1	,&var161},	//Внутренняя переменная var161
	{1127	,8	,1	,&var162},	//Внутренняя переменная var162
	{1128	,5	,1	,&var163},	//Внутренняя переменная var163
	{1129	,5	,1	,&var164},	//Внутренняя переменная var164
	{1130	,1	,1	,&var165},	//Внутренняя переменная var165
	{1131	,1	,1	,&var166},	//Внутренняя переменная var166
	{1132	,5	,1	,&var167},	//Внутренняя переменная var167
	{1133	,8	,1	,&var168},	//Внутренняя переменная var168
	{1134	,8	,1	,&var169},	//Внутренняя переменная var169
	{1135	,1	,1	,&var17},	//Внутренняя переменная var17
	{1136	,8	,1	,&var170},	//Внутренняя переменная var170
	{1137	,1	,1	,&var171},	//Внутренняя переменная var171
	{1138	,1	,1	,&var172},	//Внутренняя переменная var172
	{1139	,1	,1	,&var173},	//Внутренняя переменная var173
	{1140	,1	,1	,&var174},	//Внутренняя переменная var174
	{1141	,8	,1	,&var175},	//Внутренняя переменная var175
	{1142	,1	,1	,&var176},	//Внутренняя переменная var176
	{1143	,8	,1	,&var177},	//Внутренняя переменная var177
	{1144	,1	,1	,&var178},	//Внутренняя переменная var178
	{1145	,1	,1	,&var179},	//Внутренняя переменная var179
	{1146	,1	,1	,&var18},	//Внутренняя переменная var18
	{1147	,1	,1	,&var180},	//Внутренняя переменная var180
	{1148	,1	,1	,&var181},	//Внутренняя переменная var181
	{1149	,8	,1	,&var182},	//Внутренняя переменная var182
	{1150	,1	,1	,&var183},	//Внутренняя переменная var183
	{1151	,1	,1	,&var184},	//Внутренняя переменная var184
	{1152	,1	,1	,&var185},	//Внутренняя переменная var185
	{1153	,1	,1	,&var186},	//Внутренняя переменная var186
	{1154	,1	,1	,&var187},	//Внутренняя переменная var187
	{1155	,1	,1	,&var188},	//Внутренняя переменная var188
	{1156	,1	,1	,&var189},	//Внутренняя переменная var189
	{1157	,1	,1	,&var19},	//Внутренняя переменная var19
	{1158	,1	,1	,&var190},	//Внутренняя переменная var190
	{1159	,1	,1	,&var191},	//Внутренняя переменная var191
	{1160	,1	,1	,&var192},	//Внутренняя переменная var192
	{1161	,1	,1	,&var193},	//Внутренняя переменная var193
	{1162	,1	,1	,&var194},	//Внутренняя переменная var194
	{1163	,1	,1	,&var195},	//Внутренняя переменная var195
	{1164	,1	,1	,&var196},	//Внутренняя переменная var196
	{1165	,1	,1	,&var197},	//Внутренняя переменная var197
	{1166	,1	,1	,&var198},	//Внутренняя переменная var198
	{1167	,1	,1	,&var199},	//Внутренняя переменная var199
	{1168	,1	,1	,&var2},	//Внутренняя переменная var2
	{1169	,1	,1	,&var20},	//Внутренняя переменная var20
	{1170	,1	,1	,&var200},	//Внутренняя переменная var200
	{1171	,1	,1	,&var201},	//Внутренняя переменная var201
	{1172	,1	,1	,&var202},	//Внутренняя переменная var202
	{1173	,1	,1	,&var203},	//Внутренняя переменная var203
	{1174	,1	,1	,&var204},	//Внутренняя переменная var204
	{1175	,1	,1	,&var205},	//Внутренняя переменная var205
	{1176	,1	,1	,&var206},	//Внутренняя переменная var206
	{1177	,1	,1	,&var207},	//Внутренняя переменная var207
	{1178	,1	,1	,&var208},	//Внутренняя переменная var208
	{1179	,1	,1	,&var209},	//Внутренняя переменная var209
	{1180	,1	,1	,&var21},	//Внутренняя переменная var21
	{1181	,1	,1	,&var210},	//Внутренняя переменная var210
	{1182	,1	,1	,&var211},	//Внутренняя переменная var211
	{1183	,1	,1	,&var212},	//Внутренняя переменная var212
	{1184	,1	,1	,&var213},	//Внутренняя переменная var213
	{1185	,1	,1	,&var214},	//Внутренняя переменная var214
	{1186	,1	,1	,&var215},	//Внутренняя переменная var215
	{1187	,1	,1	,&var216},	//Внутренняя переменная var216
	{1188	,1	,1	,&var217},	//Внутренняя переменная var217
	{1189	,1	,1	,&var218},	//Внутренняя переменная var218
	{1190	,1	,1	,&var219},	//Внутренняя переменная var219
	{1191	,1	,1	,&var22},	//Внутренняя переменная var22
	{1192	,1	,1	,&var220},	//Внутренняя переменная var220
	{1193	,8	,1	,&var221},	//Внутренняя переменная var221
	{1194	,8	,1	,&var222},	//Внутренняя переменная var222
	{1195	,8	,1	,&var223},	//Внутренняя переменная var223
	{1196	,8	,1	,&var224},	//Внутренняя переменная var224
	{1197	,8	,1	,&var225},	//Внутренняя переменная var225
	{1198	,8	,1	,&var226},	//Внутренняя переменная var226
	{1199	,8	,1	,&var227},	//Внутренняя переменная var227
	{1200	,8	,1	,&var228},	//Внутренняя переменная var228
	{1201	,8	,1	,&var229},	//Внутренняя переменная var229
	{1202	,1	,1	,&var23},	//Внутренняя переменная var23
	{1203	,1	,1	,&var230},	//Внутренняя переменная var230
	{1204	,1	,1	,&var231},	//Внутренняя переменная var231
	{1205	,8	,1	,&var232},	//Внутренняя переменная var232
	{1206	,8	,1	,&var233},	//Внутренняя переменная var233
	{1207	,8	,1	,&var234},	//Внутренняя переменная var234
	{1208	,8	,1	,&var235},	//Внутренняя переменная var235
	{1209	,8	,1	,&var236},	//Внутренняя переменная var236
	{1210	,8	,1	,&var237},	//Внутренняя переменная var237
	{1211	,8	,1	,&var238},	//Внутренняя переменная var238
	{1212	,8	,1	,&var239},	//Внутренняя переменная var239
	{1213	,1	,1	,&var24},	//Внутренняя переменная var24
	{1214	,8	,1	,&var240},	//Внутренняя переменная var240
	{1215	,8	,1	,&var241},	//Внутренняя переменная var241
	{1216	,8	,1	,&var242},	//Внутренняя переменная var242
	{1217	,8	,1	,&var243},	//Внутренняя переменная var243
	{1218	,8	,1	,&var244},	//Внутренняя переменная var244
	{1219	,1	,1	,&var245},	//Внутренняя переменная var245
	{1220	,1	,1	,&var246},	//Внутренняя переменная var246
	{1221	,1	,1	,&var247},	//Внутренняя переменная var247
	{1222	,1	,1	,&var248},	//Внутренняя переменная var248
	{1223	,1	,1	,&var249},	//Внутренняя переменная var249
	{1224	,1	,1	,&var25},	//Внутренняя переменная var25
	{1225	,1	,1	,&var250},	//Внутренняя переменная var250
	{1226	,1	,1	,&var251},	//Внутренняя переменная var251
	{1227	,1	,1	,&var252},	//Внутренняя переменная var252
	{1228	,1	,1	,&var253},	//Внутренняя переменная var253
	{1229	,1	,1	,&var254},	//Внутренняя переменная var254
	{1230	,1	,1	,&var255},	//Внутренняя переменная var255
	{1231	,1	,1	,&var256},	//Внутренняя переменная var256
	{1232	,1	,1	,&var257},	//Внутренняя переменная var257
	{1233	,1	,1	,&var258},	//Внутренняя переменная var258
	{1234	,1	,1	,&var259},	//Внутренняя переменная var259
	{1235	,1	,1	,&var26},	//Внутренняя переменная var26
	{1236	,1	,1	,&var260},	//Внутренняя переменная var260
	{1237	,1	,1	,&var261},	//Внутренняя переменная var261
	{1238	,1	,1	,&var262},	//Внутренняя переменная var262
	{1239	,1	,1	,&var263},	//Внутренняя переменная var263
	{1240	,1	,1	,&var264},	//Внутренняя переменная var264
	{1241	,1	,1	,&var265},	//Внутренняя переменная var265
	{1242	,1	,1	,&var266},	//Внутренняя переменная var266
	{1243	,1	,1	,&var267},	//Внутренняя переменная var267
	{1244	,1	,1	,&var268},	//Внутренняя переменная var268
	{1245	,8	,1	,&var269},	//Внутренняя переменная var269
	{1246	,1	,1	,&var27},	//Внутренняя переменная var27
	{1247	,1	,1	,&var270},	//Внутренняя переменная var270
	{1248	,1	,1	,&var271},	//Внутренняя переменная var271
	{1249	,8	,1	,&var272},	//Внутренняя переменная var272
	{1250	,1	,1	,&var273},	//Внутренняя переменная var273
	{1251	,1	,1	,&var274},	//Внутренняя переменная var274
	{1252	,1	,1	,&var275},	//Внутренняя переменная var275
	{1253	,1	,1	,&var276},	//Внутренняя переменная var276
	{1254	,1	,1	,&var277},	//Внутренняя переменная var277
	{1255	,1	,1	,&var278},	//Внутренняя переменная var278
	{1256	,1	,1	,&var279},	//Внутренняя переменная var279
	{1257	,1	,1	,&var28},	//Внутренняя переменная var28
	{1258	,1	,1	,&var280},	//Внутренняя переменная var280
	{1259	,8	,1	,&var281},	//Внутренняя переменная var281
	{1260	,8	,1	,&var282},	//Внутренняя переменная var282
	{1261	,8	,1	,&var283},	//Внутренняя переменная var283
	{1262	,8	,1	,&var284},	//Внутренняя переменная var284
	{1263	,1	,1	,&var285},	//Внутренняя переменная var285
	{1264	,8	,1	,&var286},	//Внутренняя переменная var286
	{1265	,8	,1	,&var287},	//Внутренняя переменная var287
	{1266	,8	,1	,&var288},	//Внутренняя переменная var288
	{1267	,8	,1	,&var289},	//Внутренняя переменная var289
	{1268	,1	,1	,&var29},	//Внутренняя переменная var29
	{1269	,1	,1	,&var290},	//Внутренняя переменная var290
	{1270	,1	,1	,&var291},	//Внутренняя переменная var291
	{1271	,1	,1	,&var292},	//Внутренняя переменная var292
	{1272	,1	,1	,&var293},	//Внутренняя переменная var293
	{1273	,1	,1	,&var294},	//Внутренняя переменная var294
	{1274	,8	,1	,&var295},	//Внутренняя переменная var295
	{1275	,8	,1	,&var296},	//Внутренняя переменная var296
	{1276	,1	,1	,&var297},	//Внутренняя переменная var297
	{1277	,1	,1	,&var298},	//Внутренняя переменная var298
	{1278	,1	,1	,&var299},	//Внутренняя переменная var299
	{1279	,8	,1	,&var3},	//Внутренняя переменная var3
	{1280	,1	,1	,&var30},	//Внутренняя переменная var30
	{1281	,1	,1	,&var300},	//Внутренняя переменная var300
	{1282	,1	,1	,&var301},	//Внутренняя переменная var301
	{1283	,8	,1	,&var302},	//Внутренняя переменная var302
	{1284	,8	,1	,&var303},	//Внутренняя переменная var303
	{1285	,1	,1	,&var304},	//Внутренняя переменная var304
	{1286	,1	,1	,&var305},	//Внутренняя переменная var305
	{1287	,1	,1	,&var306},	//Внутренняя переменная var306
	{1288	,1	,1	,&var307},	//Внутренняя переменная var307
	{1289	,1	,1	,&var308},	//Внутренняя переменная var308
	{1290	,1	,1	,&var309},	//Внутренняя переменная var309
	{1291	,1	,1	,&var31},	//Внутренняя переменная var31
	{1292	,8	,1	,&var310},	//Внутренняя переменная var310
	{1293	,8	,1	,&var311},	//Внутренняя переменная var311
	{1294	,1	,1	,&var312},	//Внутренняя переменная var312
	{1295	,1	,1	,&var313},	//Внутренняя переменная var313
	{1296	,1	,1	,&var314},	//Внутренняя переменная var314
	{1297	,1	,1	,&var315},	//Внутренняя переменная var315
	{1298	,1	,1	,&var316},	//Внутренняя переменная var316
	{1299	,1	,1	,&var317},	//Внутренняя переменная var317
	{1300	,8	,1	,&var318},	//Внутренняя переменная var318
	{1301	,8	,1	,&var319},	//Внутренняя переменная var319
	{1302	,1	,1	,&var32},	//Внутренняя переменная var32
	{1303	,1	,1	,&var320},	//Внутренняя переменная var320
	{1304	,1	,1	,&var321},	//Внутренняя переменная var321
	{1305	,1	,1	,&var322},	//Внутренняя переменная var322
	{1306	,1	,1	,&var323},	//Внутренняя переменная var323
	{1307	,1	,1	,&var324},	//Внутренняя переменная var324
	{1308	,8	,1	,&var325},	//Внутренняя переменная var325
	{1309	,8	,1	,&var326},	//Внутренняя переменная var326
	{1310	,1	,1	,&var327},	//Внутренняя переменная var327
	{1311	,1	,1	,&var328},	//Внутренняя переменная var328
	{1312	,1	,1	,&var329},	//Внутренняя переменная var329
	{1313	,1	,1	,&var33},	//Внутренняя переменная var33
	{1314	,1	,1	,&var330},	//Внутренняя переменная var330
	{1315	,1	,1	,&var331},	//Внутренняя переменная var331
	{1316	,8	,1	,&var332},	//Внутренняя переменная var332
	{1317	,8	,1	,&var333},	//Внутренняя переменная var333
	{1318	,8	,1	,&var334},	//Внутренняя переменная var334
	{1319	,8	,1	,&var335},	//Внутренняя переменная var335
	{1320	,1	,1	,&var336},	//Внутренняя переменная var336
	{1321	,8	,1	,&var337},	//Внутренняя переменная var337
	{1322	,8	,1	,&var338},	//Внутренняя переменная var338
	{1323	,1	,1	,&var34},	//Внутренняя переменная var34
	{1324	,1	,1	,&var35},	//Внутренняя переменная var35
	{1325	,1	,1	,&var36},	//Внутренняя переменная var36
	{1326	,1	,1	,&var37},	//Внутренняя переменная var37
	{1327	,1	,1	,&var38},	//Внутренняя переменная var38
	{1328	,1	,1	,&var39},	//Внутренняя переменная var39
	{1329	,1	,1	,&var4},	//Внутренняя переменная var4
	{1330	,1	,1	,&var40},	//Внутренняя переменная var40
	{1331	,1	,1	,&var41},	//Внутренняя переменная var41
	{1332	,1	,1	,&var42},	//Внутренняя переменная var42
	{1333	,1	,1	,&var43},	//Внутренняя переменная var43
	{1334	,8	,1	,&var44},	//Внутренняя переменная var44
	{1335	,1	,1	,&var45},	//Внутренняя переменная var45
	{1336	,1	,1	,&var46},	//Внутренняя переменная var46
	{1337	,1	,1	,&var47},	//Внутренняя переменная var47
	{1338	,1	,1	,&var48},	//Внутренняя переменная var48
	{1339	,1	,1	,&var49},	//Внутренняя переменная var49
	{1340	,1	,1	,&var5},	//Внутренняя переменная var5
	{1341	,1	,1	,&var50},	//Внутренняя переменная var50
	{1342	,1	,1	,&var51},	//Внутренняя переменная var51
	{1343	,1	,1	,&var52},	//Внутренняя переменная var52
	{1344	,1	,1	,&var53},	//Внутренняя переменная var53
	{1345	,1	,1	,&var54},	//Внутренняя переменная var54
	{1346	,1	,1	,&var55},	//Внутренняя переменная var55
	{1347	,1	,1	,&var56},	//Внутренняя переменная var56
	{1348	,1	,1	,&var57},	//Внутренняя переменная var57
	{1349	,11	,1	,&var58},	//Внутренняя переменная var58
	{1350	,8	,1	,&var59},	//Внутренняя переменная var59
	{1351	,8	,1	,&var6},	//Внутренняя переменная var6
	{1352	,11	,1	,&var60},	//Внутренняя переменная var60
	{1353	,8	,1	,&var61},	//Внутренняя переменная var61
	{1354	,1	,1	,&var62},	//Внутренняя переменная var62
	{1355	,1	,1	,&var63},	//Внутренняя переменная var63
	{1356	,1	,1	,&var64},	//Внутренняя переменная var64
	{1357	,1	,1	,&var65},	//Внутренняя переменная var65
	{1358	,1	,1	,&var66},	//Внутренняя переменная var66
	{1359	,1	,1	,&var67},	//Внутренняя переменная var67
	{1360	,1	,1	,&var68},	//Внутренняя переменная var68
	{1361	,1	,1	,&var69},	//Внутренняя переменная var69
	{1362	,8	,1	,&var7},	//Внутренняя переменная var7
	{1363	,1	,1	,&var70},	//Внутренняя переменная var70
	{1364	,1	,1	,&var71},	//Внутренняя переменная var71
	{1365	,1	,1	,&var72},	//Внутренняя переменная var72
	{1366	,1	,1	,&var73},	//Внутренняя переменная var73
	{1367	,1	,1	,&var74},	//Внутренняя переменная var74
	{1368	,1	,1	,&var75},	//Внутренняя переменная var75
	{1369	,1	,1	,&var76},	//Внутренняя переменная var76
	{1370	,1	,1	,&var77},	//Внутренняя переменная var77
	{1371	,1	,1	,&var78},	//Внутренняя переменная var78
	{1372	,1	,1	,&var79},	//Внутренняя переменная var79
	{1373	,8	,1	,&var8},	//Внутренняя переменная var8
	{1374	,1	,1	,&var80},	//Внутренняя переменная var80
	{1375	,1	,1	,&var81},	//Внутренняя переменная var81
	{1376	,1	,1	,&var82},	//Внутренняя переменная var82
	{1377	,1	,1	,&var83},	//Внутренняя переменная var83
	{1378	,1	,1	,&var84},	//Внутренняя переменная var84
	{1379	,1	,1	,&var85},	//Внутренняя переменная var85
	{1380	,1	,1	,&var86},	//Внутренняя переменная var86
	{1381	,1	,1	,&var87},	//Внутренняя переменная var87
	{1382	,1	,1	,&var88},	//Внутренняя переменная var88
	{1383	,1	,1	,&var89},	//Внутренняя переменная var89
	{1384	,8	,1	,&var9},	//Внутренняя переменная var9
	{1385	,1	,1	,&var90},	//Внутренняя переменная var90
	{1386	,1	,1	,&var91},	//Внутренняя переменная var91
	{1387	,1	,1	,&var92},	//Внутренняя переменная var92
	{1388	,1	,1	,&var93},	//Внутренняя переменная var93
	{1389	,1	,1	,&var94},	//Внутренняя переменная var94
	{1390	,1	,1	,&var95},	//Внутренняя переменная var95
	{1391	,5	,1	,&var96},	//Внутренняя переменная var96
	{1392	,5	,1	,&var97},	//Внутренняя переменная var97
	{1393	,8	,1	,&var98},	//Внутренняя переменная var98
	{1394	,8	,1	,&var99},	//Внутренняя переменная var99
	{-1,0,NULL},
};
static char NameSaveFile[]="scm.bin\0"; //Имя файла сохранения переменных
#pragma pop
static VarSaveCtrl saveVariables[]={	//Id переменных для сохранения
	{288,"fEM_A0UN01RIM\0"},	//(A0UN01RIM) Мощность источника нейтронов ИНИ
	{289,"fEM_A0UN02RIM\0"},	//(A0UN02RIM) Мощность источника нейтронов с АНИ
	{290,"fEM_A0UN07RIM\0"},	//(A0UN07RIM) Доля запаздывающих нейтронов
	{291,"fEM_A0UP01RIM\0"},	//(A0UP01RIM) Текущее давление в АЗ1,2
	{292,"fEM_A0UP02RIM\0"},	//(A0UP02RIM) Текущее давление в АЗ1,2
	{293,"fEM_A0UR01RSP\0"},	//(A0UR01RSP) Стартовая  реактивность АЗ1
	{294,"fEM_A0UR02RSP\0"},	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
	{295,"fEM_A0UT03RSP\0"},	//(A0UT03RSP) Стартовая  температура АЗ1 град
	{296,"fEM_A0UX00RSS\0"},	//(A0UX00RSS) Эффективный радиус АЗ
	{297,"fEM_A0UX01RSS\0"},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{298,"fEM_A0UX02RSS\0"},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{299,"fEM_A0UX03RSS\0"},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{300,"fEM_A0UX04RSS\0"},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{301,"fEM_A0UX05RSS\0"},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{302,"fEM_A0UX06RSS\0"},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{303,"fEM_A0UX07RSS\0"},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{304,"fEM_A0UX08RSS\0"},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{305,"fEM_A0UX09RSS\0"},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{306,"fEM_A0UX10RSS\0"},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{307,"fEM_A0UX11RSS\0"},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{308,"fEM_A0UX12RSS\0"},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{309,"fEM_A0UX13RSS\0"},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{310,"fEM_A0UX14RSS\0"},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{311,"fEM_A0UX15RSS\0"},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{312,"fEM_A1MC01RC1\0"},	//(A1MC01RC1) Заданная координата  ББ1 от ИС
	{313,"fEM_A1MC01RSP\0"},	//(A1MC01RSP) Стартовая координата  ББ1
	{314,"fEM_A1MC02RC1\0"},	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
	{315,"fEM_A1MC02RSP\0"},	//(A1MC02RSP) Стартовая координата штока ББ1
	{316,"fEM_A1MV01RC1\0"},	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
	{317,"fEM_A1MV02RC1\0"},	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
	{318,"fEM_A1UC02RDU\0"},	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{319,"fEM_A1UC03RDU\0"},	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{320,"fEM_A1UC04RIM\0"},	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
	{321,"fEM_A1UC05RIM\0"},	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
	{322,"fEM_A1UC06RIM\0"},	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
	{323,"fEM_A1UC08RIM\0"},	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
	{324,"fEM_A1UG01RDU\0"},	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
	{325,"fEM_A1UP01RIM\0"},	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
	{326,"fEM_A1UP82RIM\0"},	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{327,"fEM_A1UR00RIM\0"},	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{328,"fEM_A1UR01RIM\0"},	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{329,"fEM_A1US07RDU\0"},	//(A1US07RDU) Постоянная времени масляного демпфера ББ
	{330,"fEM_A1UV02RIM\0"},	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{331,"fEM_A2MC01RC1\0"},	//(A2MC01RC1) Заданная координата РБ1 от ИС
	{332,"fEM_A2MC01RSP\0"},	//(A2MC01RSP) Стартовая координата  РБ1
	{333,"fEM_A2MC02RC1\0"},	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
	{334,"fEM_A2MC02RSP\0"},	//(A2MC02RSP) Стартовая координата штока РБ1
	{335,"fEM_A2MV01RC1\0"},	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
	{336,"fEM_A2MV02RC1\0"},	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
	{337,"fEM_A2UC02RDU\0"},	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{338,"fEM_A2UC03RDU\0"},	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{339,"fEM_A2UC04RIM\0"},	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
	{340,"fEM_A2UC05RIM\0"},	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
	{341,"fEM_A2UC06RIM\0"},	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
	{342,"fEM_A2UC08RIM\0"},	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
	{343,"fEM_A2UG01RDU\0"},	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
	{344,"fEM_A2UP01RIM\0"},	//(A2UP01RIM) Текущее давление на сброс РБ
	{345,"fEM_A2UP02RIM\0"},	//(A2UP02RIM) Текущее давление на подъём РБ
	{346,"fEM_A2UP03RDU\0"},	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{347,"fEM_A2UP03RIM\0"},	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
	{348,"fEM_A2UP04RDU\0"},	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{349,"fEM_A2UR00RIM\0"},	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{350,"fEM_A2UR01RIM\0"},	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{351,"fEM_A2US07RDU\0"},	//(A2US07RDU) Постоянная времени масляного демпфера РБ
	{352,"fEM_A2UV02RIM\0"},	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{353,"fEM_A3MC01RC1\0"},	//(A3MC01RC1) Заданная координата ИС1 от ИС
	{354,"fEM_A3MC01RSP\0"},	//(A3MC01RSP) Стартовая координата  ИС1
	{355,"fEM_A3MC02RC1\0"},	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
	{356,"fEM_A3MC02RSP\0"},	//(A3MC02RSP) Стартовая координата штока ИС1
	{357,"fEM_A3MV01RC1\0"},	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
	{358,"fEM_A3MV02RC1\0"},	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
	{359,"fEM_A3UC02RDU\0"},	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{360,"fEM_A3UC03RDU\0"},	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{361,"fEM_A3UC04RIM\0"},	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
	{362,"fEM_A3UC05RIM\0"},	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
	{363,"fEM_A3UC06RIM\0"},	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
	{364,"fEM_A3UC08RIM\0"},	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
	{365,"fEM_A3UG01RDU\0"},	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
	{366,"fEM_A3UP01RIM\0"},	//(A3UP01RIM) Текущее давление на СПУСК ИС
	{367,"fEM_A3UP02RDU\0"},	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
	{368,"fEM_A3UP02RIM\0"},	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
	{369,"fEM_A3UP03RDU\0"},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{370,"fEM_A3UP04RDU\0"},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{371,"fEM_A3UR00RIM\0"},	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{372,"fEM_A3UR01RIM\0"},	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{373,"fEM_A3US07RDU\0"},	//(A3US07RDU) Постоянная времени масляного демпфера ИС
	{374,"fEM_A3UV02RIM\0"},	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{375,"fEM_A4MC01RSP\0"},	//(A4MC01RSP) Стартовая координата НИ1
	{376,"fEM_A4UL10RIM\0"},	//(A4UL10RIM) Время полного перемещения НИ сек
	{377,"fEM_A4UP01RIM\0"},	//(A4UP01RIM) Текущее давление на подъём НИ
	{378,"fEM_A4UP02RIM\0"},	//(A4UP02RIM) Нижняя граница давления на подъём НИ
	{379,"fEM_A5MC01RC1\0"},	//(A5MC01RC1) Заданная координата НЛ1 от ИС
	{380,"fEM_A5MC01RSP\0"},	//(A5MC01RSP) Стартовая координата НЛ1
	{381,"fEM_A5MV01RC1\0"},	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
	{382,"fEM_A5UC10RIM\0"},	//(A5UC10RIM) Время полного хода НЛ сек
	{383,"fEM_A6MC01RC1\0"},	//(A6MC01RC1) Заданная координата БЗ1 от ИС
	{384,"fEM_A6MC01RSP\0"},	//(A6MC01RSP) Стартовая координата БЗ1
	{385,"fEM_A6MV01RC1\0"},	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
	{386,"fEM_A6UC10RIM\0"},	//(A6UC10RIM) Время полного хода БЗ (сек)
	{387,"fEM_A6US80RDU\0"},	//(A6US80RDU) Тормозной путь БЗ (мм)
	{388,"fEM_A8MC01RC1\0"},	//(A8MC01RC1) Заданная координата ДС2 от ИС
	{389,"fEM_A8MC01RSP\0"},	//(A8MC01RSP) Стартовая координата ДС2
	{390,"fEM_A8MV01RC1\0"},	//(A8MV01RC1) Заданная скорость ДС2 от ИС
	{391,"fEM_A8UC03RDU\0"},	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{392,"fEM_A8UC08RDU\0"},	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
	{393,"fEM_A8UC10RIM\0"},	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
	{394,"fEM_A8UC11RIM\0"},	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
	{395,"fEM_A8UC20RIM\0"},	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
	{396,"fEM_A8UC21RIM\0"},	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
	{397,"fEM_A8US80RDU\0"},	//(A8US80RDU) Тормозной путь ДС2 (мм)
	{398,"fEM_A8UV80RDU\0"},	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
	{399,"fEM_A9MC01RSP\0"},	//(A9MC01RSP) Стартовая координата НИ ДС1
	{400,"fEM_A9UL10RIM\0"},	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
	{401,"fEM_B0UT03RSP\0"},	//(B0UT03RSP) Стартовая  температура АЗ2 град
	{402,"fEM_B0UX01RSS\0"},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{403,"fEM_B0UX02RSS\0"},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{404,"fEM_B0UX03RSS\0"},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{405,"fEM_B0UX04RSS\0"},	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
	{406,"fEM_B0UX05RSS\0"},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{407,"fEM_B0UX06RSS\0"},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{408,"fEM_B0UX07RSS\0"},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{409,"fEM_B0UX08RSS\0"},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{410,"fEM_B0UX09RSS\0"},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{411,"fEM_B0UX10RSS\0"},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{412,"fEM_B0UX11RSS\0"},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{413,"fEM_B0UX12RSS\0"},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{414,"fEM_B1MC01RC1\0"},	//(B1MC01RC1) Заданная координата ББ2 от ИС
	{415,"fEM_B1MC01RSP\0"},	//(B1MC01RSP) Стартовая координата  ББ2
	{416,"fEM_B1MC02RC1\0"},	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
	{417,"fEM_B1MC02RSP\0"},	//(B1MC02RSP) Стартовая координата штока ББ2
	{418,"fEM_B1MV01RC1\0"},	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
	{419,"fEM_B1MV02RC1\0"},	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
	{420,"fEM_B2MC01RC1\0"},	//(B2MC01RC1) Заданная координата РБ2 от ИС
	{421,"fEM_B2MC01RSP\0"},	//(B2MC01RSP) Стартовая координата  РБ2
	{422,"fEM_B2MC02RC1\0"},	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
	{423,"fEM_B2MC02RSP\0"},	//(B2MC02RSP) Стартовая координата штока РБ2
	{424,"fEM_B2MV01RC1\0"},	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
	{425,"fEM_B2MV02RC1\0"},	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
	{426,"fEM_B3MC01RC1\0"},	//(B3MC01RC1) Заданная координата ИС2 от ИС
	{427,"fEM_B3MC01RSP\0"},	//(B3MC01RSP) Стартовая координата  ИС2
	{428,"fEM_B3MC02RC1\0"},	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
	{429,"fEM_B3MC02RSP\0"},	//(B3MC02RSP) Стартовая координата штока ИС2
	{430,"fEM_B3MV01RC1\0"},	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
	{431,"fEM_B3MV02RC1\0"},	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
	{432,"fEM_B4MC01RSP\0"},	//(B4MC01RSP) Стартовая координата НИ2
	{433,"fEM_B5MC01RC1\0"},	//(B5MC01RC1) Заданная координата НЛ2 от ИС
	{434,"fEM_B5MC01RSP\0"},	//(B5MC01RSP) Стартовая координата НЛ2
	{435,"fEM_B5MV01RC1\0"},	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
	{436,"fEM_B6MC01RC1\0"},	//(B6MC01RC1) Заданная координата БЗ2 от ИС
	{437,"fEM_B6MC01RSP\0"},	//(B6MC01RSP) Стартовая координата БЗ2
	{438,"fEM_B6MV01RC1\0"},	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
	{439,"fEM_B8MC01RC1\0"},	//(B8MC01RC1) Заданная координата АЗ2 от ИС
	{440,"fEM_B8MC01RSP\0"},	//(B8MC01RSP) Стартовая координата АЗ2
	{441,"fEM_B8MV01RC1\0"},	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
	{442,"fEM_B8UC08RDU\0"},	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
	{443,"fEM_B8UC10RIM\0"},	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
	{444,"fEM_B8UC11RIM\0"},	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
	{445,"fEM_B8UC20RIM\0"},	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
	{446,"fEM_B8UC21RIM\0"},	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
	{447,"fEM_B8US80RDU\0"},	//(B8US80RDU) Тормозной путь АЗ2 (мм)
	{448,"fEM_B8UV80RDU\0"},	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
	{449,"fEM_B9MC01RSP\0"},	//(B9MC01RSP) Стартовая координата НИ ДС2
	{450,"fEM_R0UH01RSS\0"},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
	{451,"fEM_R0UH02RSS\0"},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{452,"fEM_R0UH03RSS\0"},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
	{453,"fEM_R0UH05RSS\0"},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{454,"fEM_R0UH21RSS\0"},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{455,"fEM_R0UH22RSS\0"},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{456,"fEM_R0UH23RSS\0"},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{457,"fEM_R0UL01RIM\0"},	//(R0UL01RIM) Среднее время генерации нейтронов
	{458,"fEM_R0UL02RDU\0"},	//(R0UL02RDU) Время задержки  ИНИ
	{459,"fEM_R0UL02RIM\0"},	//(R0UL02RIM) Время удержания синхроимпульса
	{460,"fEM_R0UL04RIM\0"},	//(R0UL04RIM) Время блокировки повторной генерации импульса
	{461,"fEM_R0UN02RIM\0"},	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{462,"fEM_R0UN18RDU\0"},	//(R0UN18RDU) Коэффициент температурной корректировки реактивности(долл)
	{463,"fEM_R0UR01RIM\0"},	//(R0UR01RIM) Стартовая отрицательная реактивность
	{464,"fEM_R0UR30RIM\0"},	//(R0UR30RIM) Реактивность вносимая образцами (долл)
	{465,"fEM_R0UT01RDU\0"},	//(R0UT01RDU) Нижний предел шкалы датчика температуры
	{466,"fEM_R0UT02RDU\0"},	//(R0UT02RDU) Верхний предел шкалы датчика температуры
	{467,"fEM_R0UT02RIM\0"},	//(R0UT02RIM) Масса топлива в АЗ
	{468,"fEM_R0UT03RIM\0"},	//(R0UT03RIM) Нормальная температура АЗ град
	{469,"fEM_R0UT04RIM\0"},	//(R0UT04RIM) Удельная теплоёмкость топлива
	{470,"fEM_R0UT05RIM\0"},	//(R0UT05RIM) Энергия деления ядра
	{471,"fEM_R0UT06RIM\0"},	//(R0UT06RIM) Конвекционное сопротивление при обдуве
	{472,"fEM_R0UV81RDU\0"},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{473,"fEM_R0UV82RDU\0"},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{474,"fEM_R0UV83RDU\0"},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{475,"fEM_R0UV84RDU\0"},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{476,"fEM_R0UV85RDU\0"},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{477,"fEM_R0UV86RDU\0"},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{478,"fEM_R0UV87RDU\0"},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{479,"fEM_R1MC01RC1\0"},	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
	{480,"fEM_R1MC01RSP\0"},	//(R1MC01RSP) Стартовая координата МДЗ1
	{481,"fEM_R1MV01RC1\0"},	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
	{482,"fEM_R1UC10RIM\0"},	//(R1UC10RIM) Время полного хода МДЗ сек
	{483,"fEM_R2MC01RC1\0"},	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
	{484,"fEM_R2MC01RSP\0"},	//(R2MC01RSP) Стартовая координата МДЗ2
	{485,"fEM_R2MV01RC1\0"},	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
	{486,"fEM_R3UC01RSP\0"},	//(R3UC01RSP) Стартовая координата Гомогенных дверей
	{487,"fEM_R3UL10RIM\0"},	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
	{488,"fEM_R4MC01RC1\0"},	//(R4MC01RC1) Заданная координата тележки от ИС
	{489,"fEM_R4MC01RSP\0"},	//(R4MC01RSP) Стартовая координата тележки
	{490,"fEM_R4MV01RC1\0"},	//(R4MV01RC1) Заданная скорость тележки от ИС
	{491,"fEM_R4UC08RDU\0"},	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
	{492,"fEM_R4UC10RIM\0"},	//(R4UC10RIM) Координата верхних механических упоров тележки мм
	{493,"fEM_R4UC20RIM\0"},	//(R4UC20RIM) Координата нижних механических упоров тележки мм
	{494,"fEM_R4UC22RIM\0"},	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
	{495,"fEM_R4US80RDU\0"},	//(R4US80RDU) Тормозной путь тележки (мм)
	{496,"fEM_R4UV80RDU\0"},	//(R4UV80RDU) Номинальная скорость тележки (см/с)
	{497,"fEM_R5UC01RSP\0"},	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
	{498,"fEM_R5UL10RIM\0"},	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
	{499,"fEM_R6UC01RSP\0"},	//(R6UC01RSP) Стартовая координата Кран-балки
	{500,"fEM_R6UL10RIM\0"},	//(R6UL10RIM) Время полного хода кран-балки сек
	{501,"fEM_R7UC10RIM\0"},	//(R7UC10RIM) X-координата КНК53М R7IN13 см
	{502,"fEM_R7UC19RIM\0"},	//(R7UC19RIM) Y-координата СНМ-11 (11) см
	{503,"fEM_R7UI02RIM\0"},	//(R7UI02RIM) Коэффициент усиления уровня радиации
	{504,"fEM_R7UI71RIM\0"},	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{505,"fEM_R7UI73RIM\0"},	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
	{506,"fEM_R7UI74RIM\0"},	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
	{507,"fEM_R7UI75RIM\0"},	//(R7UI75RIM) Множитель к уровню радиации
	{508,"fEM_R7UI76RIM\0"},	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{509,"fEM_R7UI77RIM\0"},	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{510,"fEM_R7UL01RIM\0"},	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
	{511,"fEM_R7UX01RSS\0"},	//(R7UX01RSS) X-координата камеры R7IN11
	{512,"fEM_R7UX02RSS\0"},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{513,"fEM_R7UX04RSS\0"},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{514,"fEM_R7UX05RSS\0"},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{515,"fEM_R7UX06RSS\0"},	//(R7UX06RSS) X-координата камеры R7IN23 (см)
	{516,"fEM_R7UX07RSS\0"},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{517,"fEM_R7UX08RSS\0"},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{518,"fEM_R7UX09RSS\0"},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{519,"fEM_R7UX10RSS\0"},	//(R7UX10RSS) X-координата камеры R7IN41
	{520,"fEM_R7UX11RSS\0"},	//(R7UX11RSS) X-координата камеры R7IN42
	{521,"fEM_R7UX12RSS\0"},	//(R7UX12RSS) X-координата камеры R7IN43
	{522,"fEM_R7UX13RSS\0"},	//(R7UX13RSS) X-координата камеры R7IN51
	{523,"fEM_R7UX14RSS\0"},	//(R7UX14RSS) X-координата камеры R7IN52
	{524,"fEM_R7UX15RSS\0"},	//(R7UX15RSS) X-координата камеры R7IN53
	{525,"fEM_R7UX16RSS\0"},	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
	{526,"fEM_R7UY00RSS\0"},	//(R7UY00RSS) Y-координата АЗ1 см
	{527,"fEM_R7UY01RSS\0"},	//(R7UY01RSS) Y-координата камеры R7IN11
	{528,"fEM_R7UY02RSS\0"},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{529,"fEM_R7UY04RSS\0"},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{530,"fEM_R7UY05RSS\0"},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{531,"fEM_R7UY06RSS\0"},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{532,"fEM_R7UY07RSS\0"},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{533,"fEM_R7UY08RSS\0"},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{534,"fEM_R7UY09RSS\0"},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{535,"fEM_R7UY10RSS\0"},	//(R7UY10RSS) Y-координата камеры R7IN41
	{536,"fEM_R7UY11RSS\0"},	//(R7UY11RSS) Y-координата камеры R7IN42
	{537,"fEM_R7UY12RSS\0"},	//(R7UY12RSS) Y-координата камеры R7IN43
	{538,"fEM_R7UY13RSS\0"},	//(R7UY13RSS) Y-координата камеры R7IN51
	{539,"fEM_R7UY14RSS\0"},	//(R7UY14RSS) Y-координата камеры R7IN52
	{540,"fEM_R7UY15RSS\0"},	//(R7UY15RSS) Y-координата камеры R7IN53
	{541,"iEM_TERA0MT01RIM\0"},	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
	{542,"iEM_TERA0VP81LIM\0"},	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
	{543,"iEM_TERA1IE03LDU\0"},	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
	{544,"iEM_TERA1IE04LDU\0"},	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
	{545,"iEM_TERA1SC01RIM\0"},	//(TERA1SC01RIM) Искажение: Координата штока ББ1
	{546,"iEM_TERA1SS11LIM\0"},	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
	{547,"iEM_TERA1SS12LIM\0"},	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
	{548,"iEM_TERA1SS21LIM\0"},	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
	{549,"iEM_TERA1VP81LIM\0"},	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
	{550,"iEM_TERA2SC01RIM\0"},	//(TERA2SC01RIM) Искажение: Координата штока РБ1
	{551,"iEM_TERA2SP01RIM\0"},	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
	{552,"iEM_TERA2SS11LIM\0"},	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
	{553,"iEM_TERA2SS12LIM\0"},	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
	{554,"iEM_TERA2SS21LIM\0"},	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
	{555,"iEM_TERA2SS33LIM\0"},	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{556,"iEM_TERA2VP82LIM\0"},	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
	{557,"iEM_TERA3SC01RIM\0"},	//(TERA3SC01RIM) Искажение: Координата штока ИС1
	{558,"iEM_TERA3SP02RIM\0"},	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{559,"iEM_TERA3SS11LIM\0"},	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
	{560,"iEM_TERA3SS21LIM\0"},	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
	{561,"iEM_TERA3SS22LIM\0"},	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
	{562,"iEM_TERA3SS31LIM\0"},	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{563,"iEM_TERA3SS33LIM\0"},	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{564,"iEM_TERA3VP81LIM\0"},	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
	{565,"iEM_TERA4SS11LIM\0"},	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
	{566,"iEM_TERA4SS21LIM\0"},	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
	{567,"iEM_TERA4VP82LIM\0"},	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
	{568,"iEM_TERA5SS11LIM\0"},	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{569,"iEM_TERA5SS21LIM\0"},	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
	{570,"iEM_TERA5VS12LIM\0"},	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
	{571,"iEM_TERA5VS22LIM\0"},	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
	{572,"iEM_TERA6MS11LIM\0"},	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
	{573,"iEM_TERA6SS21LIM\0"},	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
	{574,"iEM_TERA6VS12LIM\0"},	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{575,"iEM_TERA6VS22LIM\0"},	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{576,"iEM_TERA7MS31LIM\0"},	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{577,"iEM_TERA8SC01RIM\0"},	//(TERA8SC01RIM) Искажение: Координата ДС2
	{578,"iEM_TERA8SS12LIM\0"},	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
	{579,"iEM_TERA8SS22LIM\0"},	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
	{580,"iEM_TERA9SS11LIM\0"},	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
	{581,"iEM_TERA9SS21LIM\0"},	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
	{582,"iEM_TERB0MT01RIM\0"},	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
	{583,"iEM_TERB0VP81LIM\0"},	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
	{584,"iEM_TERB1IE03LDU\0"},	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
	{585,"iEM_TERB1IE04LDU\0"},	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
	{586,"iEM_TERB1MC01RIM\0"},	//(TERB1MC01RIM) Искажение: Координата штока ББ2
	{587,"iEM_TERB1SS11LIM\0"},	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
	{588,"iEM_TERB1SS12LIM\0"},	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
	{589,"iEM_TERB1SS21LIM\0"},	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
	{590,"iEM_TERB1VP81LIM\0"},	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
	{591,"iEM_TERB2SC01RIM\0"},	//(TERB2SC01RIM) Искажение: Координата штока РБ2
	{592,"iEM_TERB2SP01RIM\0"},	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
	{593,"iEM_TERB2SS11LIM\0"},	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
	{594,"iEM_TERB2SS12LIM\0"},	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
	{595,"iEM_TERB2SS21LIM\0"},	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
	{596,"iEM_TERB2SS33LIM\0"},	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{597,"iEM_TERB3SC01RIM\0"},	//(TERB3SC01RIM) Искажение: Координата штока ИС2
	{598,"iEM_TERB3SP02RIM\0"},	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{599,"iEM_TERB3SS11LIM\0"},	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
	{600,"iEM_TERB3SS21LIM\0"},	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
	{601,"iEM_TERB3SS22LIM\0"},	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
	{602,"iEM_TERB3SS31LIM\0"},	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{603,"iEM_TERB3SS33LIM\0"},	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{604,"iEM_TERB4SS11LIM\0"},	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
	{605,"iEM_TERB4SS21LIM\0"},	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
	{606,"iEM_TERB5SS11LIM\0"},	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
	{607,"iEM_TERB5SS21LIM\0"},	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
	{608,"iEM_TERB5VS12LIM\0"},	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
	{609,"iEM_TERB5VS22LIM\0"},	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
	{610,"iEM_TERB6SS11LIM\0"},	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
	{611,"iEM_TERB6SS21LIM\0"},	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
	{612,"iEM_TERB6VS12LIM\0"},	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{613,"iEM_TERB6VS22LIM\0"},	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{614,"iEM_TERB7MS31LIM\0"},	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{615,"iEM_TERB8SC01RIM\0"},	//(TERB8SC01RIM) Искажение: Координата АЗ2
	{616,"iEM_TERB8SS12LIM\0"},	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
	{617,"iEM_TERB8SS22LIM\0"},	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
	{618,"iEM_TERB9SS11LIM\0"},	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
	{619,"iEM_TERB9SS21LIM\0"},	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
	{620,"iEM_TERBB1\0"},	//(TERBB1) Неисправности  ББ1
	{621,"iEM_TERBB2\0"},	//(TERBB2) Неисправности  ББ2
	{622,"iEM_TERBZ1\0"},	//(TERBZ1) Неисправности БЗ1
	{623,"iEM_TERBZ2\0"},	//(TERBZ2) Неисправности БЗ2
	{624,"iEM_TERDS2\0"},	//(TERDS2) Неисправности ДС2 от ИС
	{625,"iEM_TERIS1\0"},	//(TERIS1) Неисправности  ИС1
	{626,"iEM_TERIS2\0"},	//(TERIS2) Неисправности  ИС2
	{627,"iEM_TERMAZ2\0"},	//(TERMAZ2) Неисправности АЗ2 от ИС
	{628,"iEM_TERMDZ1\0"},	//(TERMDZ1) Неисправности МДЗ1
	{629,"iEM_TERMDZ2\0"},	//(TERMDZ2) Неисправности МДЗ2
	{630,"iEM_TERNL1\0"},	//(TERNL1) Неисправности НЛ1
	{631,"iEM_TERNL2\0"},	//(TERNL2) Неисправности НЛ2
	{632,"iEM_TERR0VP81LIM\0"},	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{633,"iEM_TERR1SS11LIM\0"},	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
	{634,"iEM_TERR1SS21LIM\0"},	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
	{635,"iEM_TERR1VS12LIM\0"},	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
	{636,"iEM_TERR1VS22LIM\0"},	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
	{637,"iEM_TERR2SS11LIM\0"},	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
	{638,"iEM_TERR2SS21LIM\0"},	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
	{639,"iEM_TERR2VS12LIM\0"},	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
	{640,"iEM_TERR2VS22LIM\0"},	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
	{641,"iEM_TERR3SS11LIM\0"},	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
	{642,"iEM_TERR3SS21LIM\0"},	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
	{643,"iEM_TERR4MS21LIM\0"},	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
	{644,"iEM_TERR4SS11LIM\0"},	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
	{645,"iEM_TERR4SS12LIM\0"},	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
	{646,"iEM_TERR4SS22LIM\0"},	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
	{647,"iEM_TERR4VS12LDU\0"},	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{648,"iEM_TERR4VS22LDU\0"},	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{649,"iEM_TERR5SS11LIM\0"},	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
	{650,"iEM_TERR5SS21LIM\0"},	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
	{651,"iEM_TERR6IS62LIM\0"},	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
	{652,"iEM_TERR6IS64LIM\0"},	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
	{653,"iEM_TERR6IS66LIM\0"},	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{654,"iEM_TERR6SS21LIM\0"},	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
	{655,"iEM_TERR7SI74RIM\0"},	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
	{656,"iEM_TERR8SS11LIM\0"},	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
	{657,"iEM_TERRB1\0"},	//(TERRB1) Неисправности  РБ1
	{658,"iEM_TERRB2\0"},	//(TERRB2) Неисправности  РБ2
	{659,"iEM_TERTLG\0"},	//(TERTLG) Неисправности  тележки от ИС
	{1044,"lEM_C1AD31LRP\0"},	//(C1AD31LRP) Общий сброс от РПУ
	{1045,"lEM_R0IE01LRP\0"},	//(R0IE01LRP) Отключение питание детекторов
	{1046,"lEM_R0IE02LRP\0"},	//(R0IE02LRP) Отключить питание ПР, ПУ
	{1047,"lEM_R3AD10LC1\0"},	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
	{1048,"lEM_R3AD20LC1\0"},	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
	{1049,"lEM_R5AD10LC1\0"},	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
	{1050,"lEM_R5AD20LC1\0"},	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
	{1051,"lEM_R6AD10LC1\0"},	//(R6AD10LC1) Выкатить кран-балку от ИС
	{1052,"lEM_R8AD10LC1\0"},	//(R8AD10LC1) Установить аварийный НИ от ИС
	{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_SCM[]={
	{&R0VZ71LZ1,1,0},	//( - , SCM, SBz1) Обобщенный сигнал по АЗ  1 канала
	{&R0VZ71LZ2,1,1},	//( - , SCM, SBz2) Обобщенный сигнал по АЗ  2 канала
	{&C2MD31LP1,1,2},	//( - , SCM) Кнопка «СБРОС РБ»
	{&C1MD31LP2,1,3},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
	{&C1MD31LP1,1,4},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
	{&R0MW13LP2,1,5},	//( - , SCM) Переключатель «СЕТЬ»
	{&lEM_C1AD31LRP,1,6},	//( - , SCM) Общий сброс от РПУ
	{&lEM_R0IE01LRP,1,7},	//( - , SCM) Отключение питание детекторов
	{&lEM_R0IE02LRP,1,8},	//( - , SCM) Отключить питание ПР, ПУ
	{&lEM_R3AD10LC1,1,9},	//( - , SCM) Гомогенные двери-1 открыть от ИС
	{&lEM_R3AD20LC1,1,10},	//( - , SCM) Гомогенные двери-1 закрыть от ИС
	{&lEM_R6AD10LC1,1,11},	//( - , SCM) Выкатить кран-балку от ИС
	{&lEM_R5AD10LC1,1,12},	//( - , SCM) Открыть ворота отстойной зоны от ИС
	{&lEM_R5AD20LC1,1,13},	//( - , SCM) Закрыть ворота отстойной зоны от ИС
	{&lEM_R8AD10LC1,1,14},	//( - , SCM) Установить аварийный НИ от ИС
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SCM[]={
	{&A6VS22LDU,1,0},	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
	{&A6VS12LDU,1,1},	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
	{&B6VS22LDU,1,2},	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
	{&B6VS12LDU,1,3},	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
	{&A5VS22LDU,1,4},	//( - , SCM) Движение НЛ1 в сторону НУ
	{&A5VS12LDU,1,5},	//( - , SCM) Движение НЛ1 в сторону ВУ
	{&B5VS22LDU,1,6},	//( - , SCM) Движение НЛ2 в сторону НУ
	{&B5VS12LDU,1,7},	//( - , SCM) Движение НЛ2 в сторону ВУ
	{&R1VS22LDU,1,8},	//( - , SCM) Движение МДЗ1 в сторону НУ
	{&R2VS22LDU,1,9},	//( - , SCM) Движение МДЗ2 в сторону НУ
	{&R2VS12LDU,1,10},	//( - , SCM) Движение МДЗ2 в сторону ВУ
	{&R1VS12LDU,1,11},	//( - , SCM) Движение МДЗ1 в сторону ВУ
	{&R4VS22LDU,1,12},	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
	{&R4VS12LDU,1,13},	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
	{&B4IS21LDU,1,14},	//( - K08DO, SCM) Приход на НУ НИ2
	{&A1IE03LDU,1,15},	//( - , SCM) Движение ББ1 вперед (от БУШД)
	{&A1IE04LDU,1,16},	//( - , SCM) Движение ББ1 назад (от БУШД)
	{&B1IE03LDU,1,17},	//( - , SCM) Движение ББ2 вперед (от БУШД)
	{&B1IE04LDU,1,18},	//( - , SCM) Движение ББ2 назад (от БУШД)
	{&A1IS11LIM,1,19},	//( - , SCM) Магнит ББ1 обесточен
	{&A1IS32LIM,1,20},	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
	{&B1IS11LIM,1,21},	//( - , SCM) Магнит ББ2 обесточен
	{&B1IS32LIM,1,22},	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
	{&A2IS11LIM,1,23},	//( - , SCM) Магнит РБ1 обесточен
	{&A2IS32LIM,1,24},	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
	{&B2IS11LIM,1,25},	//( - , SCM) Магнит РБ2 обесточен
	{&B2IS32LIM,1,26},	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SCM[]={
	{&R0SR03RIM,8,0},	//( - , SCM) Текущая мощность РУ аз1  (ватт)
	{&A0SN02RIM,8,2},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
	{&A0SN03RIM,8,4},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
	{&A0SN04RIM,8,6},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
	{&A0SN05RIM,8,8},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
	{&A0SN06RIM,8,10},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
	{&A0SN07RIM,8,12},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
	{&B0SN02RIM,8,14},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
	{&B0SN03RIM,8,16},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
	{&B0SN04RIM,8,18},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
	{&B0SN05RIM,8,20},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
	{&B0SN06RIM,8,22},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
	{&B0SN07RIM,8,24},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
	{&A0SR01RIM,8,26},	//( - , SCM) Текущая реактивность AЗ1
	{&B0SR01RIM,8,28},	//( - , SCM) Текущая реактивность AЗ2
	{&A0SN08RIM,8,30},	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
	{&B0SN08RIM,8,32},	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
	{&R0CR01RIM,8,34},	//( - , SCM) Коэффициент 12 связи АЗ1,2
	{&R0CR02RIM,8,36},	//( - , SCM) Коэффициент 11 связи АЗ1,2
	{&R0SR02RIM,8,38},	//( - , SCM) Текущая мощность РУ (ватт)
	{&R0ST01RIM,8,40},	//( - , SCM) Текущий период разгона РУ
	{&R0SR01RIM,8,42},	//( - , SCM) Текущая реактивность PУ
	{&A0VN01RIM,8,44},	//( - , SCM) Период разгона  AЗ1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SCM[]={
	{&R0MW11IP1,3,0},	//( - , SCM) Переключатель ВЫСТРЕЛ
	{&R0DEUMLSS,3,1},	//( - , SCM) Сигнал управления моделью
	{&fEM_R0UL01RIM,8,2},	//( - , SCM) Среднее время генерации нейтронов
	{&fEM_R0UN02RIM,8,4},	//( - , SCM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{&fEM_A1UR01RIM,8,6},	//( - , SCM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{&fEM_A1UR00RIM,8,8},	//( - , SCM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{&fEM_A3UR00RIM,8,10},	//( - , SCM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{&fEM_A3UR01RIM,8,12},	//( - , SCM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{&fEM_R0UT02RIM,8,14},	//( - , SCM) Масса топлива в АЗ
	{&fEM_R0UT04RIM,8,16},	//( - , SCM) Удельная теплоёмкость топлива
	{&fEM_R0UT03RIM,8,18},	//( - , SCM) Нормальная температура АЗ град
	{&fEM_R0UT05RIM,8,20},	//( - , SCM) Энергия деления ядра
	{&fEM_R0UT06RIM,8,22},	//( - , SCM) Конвекционное сопротивление при обдуве
	{&fEM_A1UC02RDU,8,24},	//( - , SCM) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{&fEM_A1UC04RIM,8,26},	//( - , SCM) Координата промежуточного путевого выключателя ББ мм
	{&fEM_A1UC05RIM,8,28},	//( - , SCM) Координата переднего аварийного выключателя ББ мм
	{&fEM_A1UC06RIM,8,30},	//( - , SCM) Координата заднего аварийного выключателя ББ мм
	{&fEM_A2UC06RIM,8,32},	//( - , SCM) Координата заднего аварийного выключателя РБ мм
	{&fEM_A2UC05RIM,8,34},	//( - , SCM) Координата переднего аварийного выключателя РБ мм
	{&fEM_A2UC04RIM,8,36},	//( - , SCM) Координата промежуточного путевого выключателя РБ мм
	{&fEM_A2UC02RDU,8,38},	//( - , SCM) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{&fEM_A3UC06RIM,8,40},	//( - , SCM) Координата заднего аварийного выключателя ИС мм
	{&fEM_A3UC05RIM,8,42},	//( - , SCM) Координата переднего аварийного выключателя ИС мм
	{&fEM_A3UC04RIM,8,44},	//( - , SCM) Координата промежуточного путевого выключателя ИС мм
	{&fEM_A3UC02RDU,8,46},	//( - , SCM) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{&fEM_R4UV80RDU,8,48},	//( - , SCM) Номинальная скорость тележки (см/с)
	{&fEM_R4UC10RIM,8,50},	//( - , SCM) Координата верхних механических упоров тележки мм
	{&fEM_R4UC20RIM,8,52},	//( - , SCM) Координата нижних механических упоров тележки мм
	{&fEM_B8UC21RIM,8,54},	//( - , SCM) Координата верхнего путевого выключателя АЗ2 мм
	{&fEM_B8UC20RIM,8,56},	//( - , SCM) Координата верхних механических упоров АЗ2 мм
	{&fEM_B8UC11RIM,8,58},	//( - , SCM) Координата нижнего путевого выключателя АЗ2 мм
	{&fEM_B8UC10RIM,8,60},	//( - , SCM) Координата нижних механических упоров АЗ2 мм
	{&fEM_B8UV80RDU,8,62},	//( - , SCM) Номинальная скорость АЗ2 (мм/с)
	{&fEM_A8UV80RDU,8,64},	//( - , SCM) Номинальная скорость ДС2 (мм/с)
	{&fEM_A8UC10RIM,8,66},	//( - , SCM) Координата нижних механических упоров ДС2 мм
	{&fEM_A8UC11RIM,8,68},	//( - , SCM) Координата нижнего путевого выключателя ДС2 мм
	{&fEM_A8UC20RIM,8,70},	//( - , SCM) Координата верхних механических упоров ДС2 мм
	{&fEM_A8UC21RIM,8,72},	//( - , SCM) Координата верхнего путевого выключателя ДС2 мм
	{&fEM_A6UC10RIM,8,74},	//( - , SCM) Время полного хода БЗ (сек)
	{&fEM_R1UC10RIM,8,76},	//( - , SCM) Время полного хода МДЗ сек
	{&fEM_A5UC10RIM,8,78},	//( - , SCM) Время полного хода НЛ сек
	{&fEM_A0UN01RIM,8,80},	//( - , SCM) Мощность источника нейтронов ИНИ
	{&fEM_R4UC22RIM,8,82},	//( - , SCM) Смещение координаты АЗ от координаты тележки
	{&fEM_A1UG01RDU,8,84},	//( - , SCM) Расстояние включения масляного демпфера ББ(мм)
	{&fEM_A2UG01RDU,8,86},	//( - , SCM) Расстояние включения масляного демпфера РБ
	{&fEM_A3UG01RDU,8,88},	//( - , SCM) Расстояние включения масляного демпфера ИС
	{&fEM_R7UC10RIM,8,90},	//( - , SCM) X-координата КНК53М R7IN13 см
	{&fEM_R7UC19RIM,8,92},	//( - , SCM) Y-координата СНМ-11 (11) см
	{&fEM_R7UI02RIM,8,94},	//( - , SCM) Коэффициент усиления уровня радиации
	{&fEM_R7UL01RIM,8,96},	//( - , SCM) Постоянная времени изменения уровня радиации в зале
	{&fEM_A2UR00RIM,8,98},	//( - , SCM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{&fEM_A2UR01RIM,8,100},	//( - , SCM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{&fEM_A0UN02RIM,8,102},	//( - , SCM) Мощность источника нейтронов с АНИ
	{&fEM_R0UR30RIM,8,104},	//( - , SCM) Реактивность вносимая образцами (долл)
	{&fEM_R0UR01RIM,8,106},	//( - , SCM) Стартовая отрицательная реактивность
	{&fEM_R0UT02RDU,8,108},	//( - , SCM) Верхний предел шкалы датчика температуры
	{&fEM_R0UT01RDU,8,110},	//( - , SCM) Нижний предел шкалы датчика температуры
	{&fEM_A1UC03RDU,8,112},	//( - , SCM) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{&fEM_A2UP03RDU,8,114},	//( - , SCM) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{&fEM_A2UP04RDU,8,116},	//( - , SCM) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{&fEM_A2UC03RDU,8,118},	//( - , SCM) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{&fEM_A3UP03RDU,8,120},	//( - , SCM) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A3UP04RDU,8,122},	//( - , SCM) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A3UC03RDU,8,124},	//( - , SCM) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{&fEM_R7UI74RIM,8,126},	//( - , SCM) Верхняя граница измерения уровня радиации в зале
	{&fEM_A8UC03RDU,8,128},	//( - , SCM) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{&fEM_R0UV87RDU,8,130},	//( - , SCM) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV81RDU,8,132},	//( - , SCM) 1-я частота двигателя (шагов/секунду)
	{&fEM_R0UV82RDU,8,134},	//( - , SCM) 3-я частота двигателя (шагов/секунду)
	{&fEM_R0UV83RDU,8,136},	//( - , SCM) 4-я частота двигателя (шагов/секунду)
	{&fEM_R0UV84RDU,8,138},	//( - , SCM) 5-я частота двигателя (шагов/секунду)
	{&fEM_R0UV85RDU,8,140},	//( - , SCM) 6-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV86RDU,8,142},	//( - , SCM) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_A8UC08RDU,8,144},	//( - , SCM) Зона срабатывания КВ ДС2(мм)
	{&fEM_B8UC08RDU,8,146},	//( - , SCM) Зона срабатывания КВ АЗ2(мм)
	{&fEM_R4UC08RDU,8,148},	//( - , SCM) Зона срабатывания КВ тележки РУ(мм)
	{&fEM_R0UH01RSS,8,150},	//( - , SCM) Коэфф. преобразования частота->нейтр/с  СНМ11
	{&fEM_A0UX00RSS,8,152},	//( - , SCM) Эффективный радиус АЗ
	{&fEM_R7UX01RSS,8,154},	//( - , SCM) X-координата камеры R7IN11
	{&fEM_R7UX02RSS,8,156},	//( - , SCM) X-координата камеры R7IN12 (см)
	{&fEM_R7UX04RSS,8,158},	//( - , SCM) X-координата камеры R7IN21 (см)
	{&fEM_R7UX05RSS,8,160},	//( - , SCM) X-координата камеры R7IN22 (см)
	{&fEM_R7UX06RSS,8,162},	//( - , SCM) X-координата камеры R7IN23 (см)
	{&fEM_R7UX07RSS,8,164},	//( - , SCM) X-координата камеры R7IN31 (см)
	{&fEM_R7UX08RSS,8,166},	//( - , SCM) X-координата камеры R7IN32 (см)
	{&fEM_R7UX09RSS,8,168},	//( - , SCM) X-координата камеры R7IN33 (см)
	{&fEM_R7UY01RSS,8,170},	//( - , SCM) Y-координата камеры R7IN11
	{&fEM_R7UY02RSS,8,172},	//( - , SCM) Y-координата камеры R7IN12 (см)
	{&fEM_R7UY04RSS,8,174},	//( - , SCM) Y-координата камеры R7IN21 (см)
	{&fEM_R7UY05RSS,8,176},	//( - , SCM) Y-координата камеры R7IN22 (см)
	{&fEM_R7UY06RSS,8,178},	//( - , SCM) Y-координата камеры R7IN23 (см)
	{&fEM_R7UY07RSS,8,180},	//( - , SCM) Y-координата камеры R7IN31 (см)
	{&fEM_R7UY08RSS,8,182},	//( - , SCM) Y-координата камеры R7IN32 (см)
	{&fEM_R7UY09RSS,8,184},	//( - , SCM) Y-координата камеры R7IN33 (см)
	{&fEM_R7UX10RSS,8,186},	//( - , SCM) X-координата камеры R7IN41
	{&fEM_R7UX11RSS,8,188},	//( - , SCM) X-координата камеры R7IN42
	{&fEM_R7UX12RSS,8,190},	//( - , SCM) X-координата камеры R7IN43
	{&fEM_R7UY10RSS,8,192},	//( - , SCM) Y-координата камеры R7IN41
	{&fEM_R7UY11RSS,8,194},	//( - , SCM) Y-координата камеры R7IN42
	{&fEM_R7UY12RSS,8,196},	//( - , SCM) Y-координата камеры R7IN43
	{&fEM_A0UX01RSS,8,198},	//( - , SCM) Первый коэффициент калибровки камеры 1
	{&fEM_A0UX02RSS,8,200},	//( - , SCM) Первый коэффициент калибровки камеры 2
	{&fEM_A0UX03RSS,8,202},	//( - , SCM) Первый коэффициент калибровки камеры 3
	{&fEM_A0UX04RSS,8,204},	//( - , SCM) Первый коэффициент калибровки камеры4
	{&fEM_A0UX05RSS,8,206},	//( - , SCM) Первый коэффициент калибровки камеры 5
	{&fEM_A0UX06RSS,8,208},	//( - , SCM) Первый коэффициент калибровки камеры 6
	{&fEM_A0UX07RSS,8,210},	//( - , SCM) Первый коэффициент калибровки камеры 7
	{&fEM_A0UX08RSS,8,212},	//( - , SCM) Первый коэффициент калибровки камеры 8
	{&fEM_A0UX09RSS,8,214},	//( - , SCM) Первый коэффициент калибровки камеры 9
	{&fEM_A0UX10RSS,8,216},	//( - , SCM) Первый коэффициент калибровки камеры 10
	{&fEM_A0UX11RSS,8,218},	//( - , SCM) Первый коэффициент калибровки камеры 11
	{&fEM_A0UX12RSS,8,220},	//( - , SCM) Первый коэффициент калибровки камеры 12
	{&fEM_B0UX01RSS,8,222},	//( - , SCM) Второй коэффициент калибровки камеры 1
	{&fEM_B0UX02RSS,8,224},	//( - , SCM) Второй коэффициент калибровки камеры 2
	{&fEM_B0UX03RSS,8,226},	//( - , SCM) Второй коэффициент калибровки камеры 3
	{&fEM_B0UX04RSS,8,228},	//( - , SCM) Второй коэффициент калибровки камеры 4
	{&fEM_B0UX05RSS,8,230},	//( - , SCM) Второй коэффициент калибровки камеры 5
	{&fEM_B0UX06RSS,8,232},	//( - , SCM) Второй коэффициент калибровки камеры 6
	{&fEM_B0UX07RSS,8,234},	//( - , SCM) Второй коэффициент калибровки камеры 7
	{&fEM_B0UX08RSS,8,236},	//( - , SCM) Второй коэффициент калибровки камеры 8
	{&fEM_B0UX09RSS,8,238},	//( - , SCM) Второй коэффициент калибровки камеры 9
	{&fEM_B0UX10RSS,8,240},	//( - , SCM) Второй коэффициент калибровки камеры 10
	{&fEM_B0UX11RSS,8,242},	//( - , SCM) Второй коэффициент калибровки камеры 11
	{&fEM_B0UX12RSS,8,244},	//( - , SCM) Второй коэффициент калибровки камеры 12
	{&fEM_R0UH02RSS,8,246},	//( - , SCM) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{&fEM_R0UH03RSS,8,248},	//( - , SCM) Коэфф. преобразования частота->нейтр/с  КНК53М
	{&fEM_R4US80RDU,8,250},	//( - , SCM) Тормозной путь тележки (мм)
	{&fEM_R7UI71RIM,8,252},	//( - , SCM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{&fEM_R7UI73RIM,8,254},	//( - , SCM) Уровень мощности срабатывания АС II УР  ватт
	{&fEM_A1UP01RIM,8,256},	//( - , SCM) Текущее давление на сброс ББ (МПа)
	{&fEM_A2UP01RIM,8,258},	//( - , SCM) Текущее давление на сброс РБ
	{&fEM_A0UP02RIM,8,260},	//( - , SCM) Текущее давление в АЗ1,2
	{&fEM_A3UP01RIM,8,262},	//( - , SCM) Текущее давление на СПУСК ИС
	{&fEM_A1UP82RIM,8,264},	//( - , SCM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{&fEM_A3UP02RDU,8,266},	//( - , SCM) Текущее давление ВЫСТРЕЛ ИС
	{&fEM_A1UV02RIM,8,268},	//( - , SCM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{&fEM_A3UV02RIM,8,270},	//( - , SCM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{&fEM_A2UV02RIM,8,272},	//( - , SCM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{&fEM_B8US80RDU,8,274},	//( - , SCM) Тормозной путь АЗ2 (мм)
	{&fEM_A8US80RDU,8,276},	//( - , SCM) Тормозной путь ДС2 (мм)
	{&fEM_A6US80RDU,8,278},	//( - , SCM) Тормозной путь БЗ (мм)
	{&fEM_A1US07RDU,8,280},	//( - , SCM) Постоянная времени масляного демпфера ББ
	{&fEM_A2US07RDU,8,282},	//( - , SCM) Постоянная времени масляного демпфера РБ
	{&fEM_A3US07RDU,8,284},	//( - , SCM) Постоянная времени масляного демпфера ИС
	{&fEM_R7UI75RIM,8,286},	//( - , SCM) Множитель к уровню радиации
	{&fEM_R0UH21RSS,8,288},	//( - , SCM) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{&fEM_R0UH22RSS,8,290},	//( - , SCM) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{&fEM_R0UH23RSS,8,292},	//( - , SCM) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{&fEM_R0UH05RSS,8,294},	//( - , SCM) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_A4UL10RIM,8,296},	//( - , SCM) Время полного перемещения НИ сек
	{&fEM_A9UL10RIM,8,298},	//( - , SCM) Время полного перемещения НИ ДС1/ДС2 сек
	{&fEM_R3UL10RIM,8,300},	//( - , SCM) Время полного хода гомогенных дверей (сек)
	{&fEM_R5UL10RIM,8,302},	//( - , SCM) Время полного хода ворот отстойной зоны (дес. мс)
	{&fEM_R6UL10RIM,8,304},	//( - , SCM) Время полного хода кран-балки сек
	{&fEM_A2UP02RIM,8,306},	//( - , SCM) Текущее давление на подъём РБ
	{&fEM_A2UP03RIM,8,308},	//( - , SCM) Нижняя граница давления на ПОДЪЁМ РБ
	{&fEM_A0UP01RIM,8,310},	//( - , SCM) Текущее давление в АЗ1,2
	{&fEM_A3UP02RIM,8,312},	//( - , SCM) Нижняя граница  давления на СПУСК ИС
	{&fEM_A4UP01RIM,8,314},	//( - , SCM) Текущее давление на подъём НИ
	{&fEM_A4UP02RIM,8,316},	//( - , SCM) Нижняя граница давления на подъём НИ
	{&fEM_R7UI76RIM,8,318},	//( - , SCM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{&fEM_R7UI77RIM,8,320},	//( - , SCM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{&iEM_TERBB1,3,322},	//( - , SCM) Неисправности  ББ1
	{&fEM_A1MC02RC1,8,323},	//( - , SCM) Заданная координата штока ББ1 от ИС
	{&fEM_A1MV02RC1,8,325},	//( - , SCM) Заданная скорость движения  штока ББ1 от ИС
	{&iEM_TERBB2,3,327},	//( - , SCM) Неисправности  ББ2
	{&fEM_B1MC02RC1,8,328},	//( - , SCM) Заданная координата штока ББ2 от ИС
	{&fEM_B1MV02RC1,8,330},	//( - , SCM) Заданная скорость движения штока ББ2 от ИС
	{&iEM_TERRB2,3,332},	//( - , SCM) Неисправности  РБ2
	{&fEM_B2MC02RC1,8,333},	//( - , SCM) Заданная координата штока РБ2 от ИС
	{&fEM_B2MV02RC1,8,335},	//( - , SCM) Заданная скорость движения штока РБ2 от ИС
	{&iEM_TERRB1,3,337},	//( - , SCM) Неисправности  РБ1
	{&fEM_A2MC02RC1,8,338},	//( - , SCM) Заданная координата штока РБ1 от ИС
	{&fEM_A2MV02RC1,8,340},	//( - , SCM) Заданная скорость движения штока РБ1 от ИС
	{&iEM_TERIS2,3,342},	//( - , SCM) Неисправности  ИС2
	{&fEM_B3MC02RC1,8,343},	//( - , SCM) Заданная координата штока ИС2 от ИС
	{&fEM_B3MV02RC1,8,345},	//( - , SCM) Заданная скорость движения штока ИС2 от ИС
	{&iEM_TERIS1,3,347},	//( - , SCM) Неисправности  ИС1
	{&fEM_A3MC02RC1,8,348},	//( - , SCM) Заданная координата штока ИС1 от ИС
	{&fEM_A3MV02RC1,8,350},	//( - , SCM) Заданная скорость движения штока ИС1 от ИС
	{&iEM_TERA1IE04LDU,3,352},	//( - , SCM) Искажение Движение ББ1 назад (от БУШД)
	{&iEM_TERA1IE03LDU,3,353},	//( - , SCM) Искажение Движение ББ1 вперёд (от БУШД)
	{&fEM_A1MC01RC1,8,354},	//( - , SCM) Заданная координата  ББ1 от ИС
	{&iEM_TERB1IE03LDU,3,356},	//( - , SCM) Искажение Движение ББ2 вперёд (от БУШД)
	{&iEM_TERB1IE04LDU,3,357},	//( - , SCM) Искажение Движение ББ2 назад (от БУШД)
	{&fEM_B1MC01RC1,8,358},	//( - , SCM) Заданная координата ББ2 от ИС
	{&fEM_B1MV01RC1,8,360},	//( - , SCM) Заданная скорость движения ББ2 от ИС
	{&fEM_B2MC01RC1,8,362},	//( - , SCM) Заданная координата РБ2 от ИС
	{&fEM_B2MV01RC1,8,364},	//( - , SCM) Заданная скорость движения  РБ2 от ИС
	{&fEM_A3MC01RC1,8,366},	//( - , SCM) Заданная координата ИС1 от ИС
	{&fEM_A3MV01RC1,8,368},	//( - , SCM) Заданная скорость движения ИС1 от ИС
	{&fEM_B3MC01RC1,8,370},	//( - , SCM) Заданная координата ИС2 от ИС
	{&fEM_B3MV01RC1,8,372},	//( - , SCM) Заданная скорость движения ИС2 от ИС
	{&iEM_TERA2SS21LIM,3,374},	//( - , SCM) Искажение: Приход на НУ РБ1
	{&iEM_TERA2SS12LIM,3,375},	//( - , SCM) Искажение: Магнит РБ1 зацеплен
	{&iEM_TERR6SS21LIM,3,376},	//( - , SCM) Искажение: Кран-балка в нерабочем положении
	{&iEM_TERA2VP82LIM,3,377},	//( - , SCM) Искажение: Текущее давление на подъём РБ  в норме
	{&iEM_TERA2SS11LIM,3,378},	//( - , SCM) Искажение: Приход на ВУ РБ1
	{&iEM_TERB3SS21LIM,3,379},	//( - , SCM) Искажение: Приход на НУ ИС2
	{&iEM_TERA0MT01RIM,3,380},	//( - , SCM) Искажение: Текущая температура AЗ1
	{&iEM_TERB0MT01RIM,3,381},	//( - , SCM) Искажение: Текущая температура AЗ2
	{&iEM_TERA2SP01RIM,3,382},	//( - , SCM) Искажение: Текущее давление СБРОС РБ1
	{&iEM_TERB2SP01RIM,3,383},	//( - , SCM) Искажение: Текущее давление СБРОС РБ2
	{&iEM_TERB3SP02RIM,3,384},	//( - , SCM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{&iEM_TERA3SC01RIM,3,385},	//( - , SCM) Искажение: Координата штока ИС1
	{&iEM_TERA3VP81LIM,3,386},	//( - , SCM) Искажение: Текущее давление СПУСК ИС  в норме
	{&iEM_TERA2SC01RIM,3,387},	//( - , SCM) Искажение: Координата штока РБ1
	{&iEM_TERA2SS33LIM,3,388},	//( - , SCM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{&iEM_TERA3SS21LIM,3,389},	//( - , SCM) Искажение: Приход на НУ ИС1
	{&iEM_TERA3SS33LIM,3,390},	//( - , SCM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{&iEM_TERA3SS31LIM,3,391},	//( - , SCM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{&iEM_TERB3SS31LIM,3,392},	//( - , SCM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{&iEM_TERB3SS33LIM,3,393},	//( - , SCM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{&iEM_TERB3SC01RIM,3,394},	//( - , SCM) Искажение: Координата штока ИС2
	{&iEM_TERA3SS11LIM,3,395},	//( - , SCM) Искажение: Приход на ВУ ИС1
	{&iEM_TERB3SS11LIM,3,396},	//( - , SCM) Искажение: Приход на ВУ ИС2
	{&iEM_TERR6IS64LIM,3,397},	//( - , SCM) Искажение: Исправность ВИП ССДИ-35
	{&iEM_TERB3SS22LIM,3,398},	//( - , SCM) Искажение: Приход на НУП ИС2
	{&iEM_TERA3SS22LIM,3,399},	//( - , SCM) Искажение: Приход на НУП ИС1
	{&iEM_TERA3SP02RIM,3,400},	//( - , SCM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{&iEM_TERR6IS62LIM,3,401},	//( - , SCM) Искажение Исправность ВИП ССДИ-39
	{&iEM_TERR6IS66LIM,3,402},	//( - , SCM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{&iEM_TERA0VP81LIM,3,403},	//( - , SCM) Искажение: Давление  АЗ1  в норме
	{&iEM_TERB0VP81LIM,3,404},	//( - , SCM) Искажение: Давление  АЗ2 в норме
	{&iEM_TERR0VP81LIM,3,405},	//( - , SCM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{&iEM_TERR7SI74RIM,3,406},	//( - , SCM) Искажение: Радиация в реакторном зале
	{&iEM_TERA5SS21LIM,3,407},	//( - , SCM) Искажение: Приход на НУ НЛ1
	{&iEM_TERB5SS11LIM,3,408},	//( - , SCM) Искажение: Приход на ВУ НЛ2
	{&iEM_TERA5SS11LIM,3,409},	//( - , SCM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{&iEM_TERA9SS11LIM,3,410},	//( - , SCM) Искажение: Приход на ВУ НИ ДС1
	{&iEM_TERB2SS11LIM,3,411},	//( - , SCM) Искажение: Приход на ВУ РБ2
	{&iEM_TERB2SS12LIM,3,412},	//( - , SCM) Искажение: Магнит РБ2 зацеплен
	{&iEM_TERB2SS21LIM,3,413},	//( - , SCM) Искажение: Приход на НУ РБ2
	{&iEM_TERR3SS11LIM,3,414},	//( - , SCM) Искажение: Приход на ВУ гомогенных дверей-1
	{&iEM_TERB2SC01RIM,3,415},	//( - , SCM) Искажение: Координата штока РБ2
	{&iEM_TERR3SS21LIM,3,416},	//( - , SCM) Искажение: Приход на НУ гомогенных дверей-1
	{&iEM_TERR5SS11LIM,3,417},	//( - , SCM) Искажение: Приход на ВУ ворот отстойной зоны
	{&iEM_TERA4SS11LIM,3,418},	//( - , SCM) Искажение: Приход на ВУ НИ1
	{&iEM_TERR1SS11LIM,3,419},	//( - , SCM) Искажение: Приход на ВУ МДЗ1
	{&iEM_TERR1SS21LIM,3,420},	//( - , SCM) Искажение: Приход на НУ МДЗ1
	{&iEM_TERR2SS11LIM,3,421},	//( - , SCM) Искажение: Приход на ВУ МДЗ2
	{&iEM_TERR2SS21LIM,3,422},	//( - , SCM) Искажение: Приход на НУ МДЗ2
	{&iEM_TERA4VP82LIM,3,423},	//( - , SCM) Искажение Давление ПОДЪЁМ НИ в норме
	{&iEM_TERB4SS21LIM,3,424},	//( - , SCM) Искажение: Приход на НУ НИ2
	{&iEM_TERR5SS21LIM,3,425},	//( - , SCM) Искажение: Приход на НУ ворот отстойной зоны
	{&iEM_TERB6SS21LIM,3,426},	//( - , SCM) Искажение: Приход на НУ БЗ2
	{&iEM_TERB4SS11LIM,3,427},	//( - , SCM) Искажение: Приход на ВУ НИ2
	{&iEM_TERA4SS21LIM,3,428},	//( - , SCM) Искажение: Приход на НУ НИ1
	{&iEM_TERA6MS11LIM,3,429},	//( - , SCM) Искажение: Приход на ВУ БЗ1
	{&iEM_TERA6SS21LIM,3,430},	//( - , SCM) Искажение: Приход на НУ БЗ1
	{&iEM_TERB6SS11LIM,3,431},	//( - , SCM) Искажение: Приход на ВУ БЗ2
	{&iEM_TERR4SS11LIM,3,432},	//( - , SCM) Искажение: Приход на ВУ тележки
	{&iEM_TERR4MS21LIM,3,433},	//( - , SCM) Искажение: Приход на НУ тележки
	{&iEM_TERR4SS12LIM,3,434},	//( - , SCM) Искажение: Приход на механический ВУ тележки
	{&iEM_TERR4SS22LIM,3,435},	//( - , SCM) Искажение: Приход на механический НУ тележки
	{&iEM_TERR8SS11LIM,3,436},	//( - , SCM) Искажение: Аварийный НИ установлен
	{&iEM_TERB8SC01RIM,3,437},	//( - , SCM) Искажение: Координата АЗ2
	{&iEM_TERA8SC01RIM,3,438},	//( - , SCM) Искажение: Координата ДС2
	{&iEM_TERB8SS12LIM,3,439},	//( - , SCM) Искажение: Приход на механический ВУ АЗ2
	{&iEM_TERA8SS12LIM,3,440},	//( - , SCM) Искажение: Приход на механический ВУ ДС2
	{&iEM_TERB8SS22LIM,3,441},	//( - , SCM) Искажение: Приход на механический НУ АЗ2
	{&iEM_TERA8SS22LIM,3,442},	//( - , SCM) Искажение: Приход на механический НУ ДС2
	{&iEM_TERA9SS21LIM,3,443},	//( - , SCM) Искажение: Приход на НУ НИ ДС1
	{&iEM_TERB9SS21LIM,3,444},	//( - , SCM) Искажение: Приход на НУ НИ ДС2
	{&iEM_TERB9SS11LIM,3,445},	//( - , SCM) Искажение: Приход на ВУ НИ ДС2
	{&iEM_TERB5SS21LIM,3,446},	//( - , SCM) Искажение: Приход на НУ НЛ2
	{&iEM_TERA1SS21LIM,3,447},	//( - , SCM) Искажение: Приход на НУ ББ1
	{&iEM_TERA1SS11LIM,3,448},	//( - , SCM) Искажение: Приход на ВУ ББ1
	{&iEM_TERA1SC01RIM,3,449},	//( - , SCM) Искажение: Координата штока ББ1
	{&iEM_TERA1SS12LIM,3,450},	//( - , SCM) Искажение: Магнит ББ1 зацеплен
	{&iEM_TERB1SS21LIM,3,451},	//( - , SCM) Искажение: Приход на НУ ББ2
	{&iEM_TERB1SS11LIM,3,452},	//( - , SCM) Искажение:Приход на ВУ ББ2
	{&iEM_TERB1MC01RIM,3,453},	//( - , SCM) Искажение: Координата штока ББ2
	{&iEM_TERB1SS12LIM,3,454},	//( - , SCM) Искажение: Магнит ББ2 зацеплен
	{&iEM_TERTLG,3,455},	//( - , SCM) Неисправности  тележки от ИС
	{&fEM_R4MC01RC1,8,456},	//( - , SCM) Заданная координата тележки от ИС
	{&fEM_R4MV01RC1,8,458},	//( - , SCM) Заданная скорость тележки от ИС
	{&iEM_TERMAZ2,3,460},	//( - , SCM) Неисправности АЗ2 от ИС
	{&fEM_B8MV01RC1,8,461},	//( - , SCM) Заданная скорость АЗ2 от ИС
	{&iEM_TERDS2,3,463},	//( - , SCM) Неисправности ДС2 от ИС
	{&fEM_A8MC01RC1,8,464},	//( - , SCM) Заданная координата ДС2 от ИС
	{&fEM_A8MV01RC1,8,466},	//( - , SCM) Заданная скорость ДС2 от ИС
	{&iEM_TERBZ1,3,468},	//( - , SCM) Неисправности БЗ1
	{&fEM_A6MC01RC1,8,469},	//( - , SCM) Заданная координата БЗ1 от ИС
	{&fEM_A6MV01RC1,8,471},	//( - , SCM) Заданная скорость БЗ1 от ИС
	{&iEM_TERBZ2,3,473},	//( - , SCM) Неисправности БЗ2
	{&fEM_B6MC01RC1,8,474},	//( - , SCM) Заданная координата БЗ2 от ИС
	{&fEM_B6MV01RC1,8,476},	//( - , SCM) Заданная скорость БЗ2 от ИС
	{&iEM_TERMDZ2,3,478},	//( - , SCM) Неисправности МДЗ2
	{&fEM_R2MC01RC1,8,479},	//( - , SCM) Заданная координата МДЗ2 от ИС
	{&fEM_R2MV01RC1,8,481},	//( - , SCM) Заданная скорость МДЗ2 от ИС
	{&iEM_TERMDZ1,3,483},	//( - , SCM) Неисправности МДЗ1
	{&fEM_R1MC01RC1,8,484},	//( - , SCM) Заданная координата МДЗ1 от ИС
	{&fEM_R1MV01RC1,8,486},	//( - , SCM) Заданная скорость МДЗ1 от ИС
	{&iEM_TERNL1,3,488},	//( - , SCM) Неисправности НЛ1
	{&fEM_A5MC01RC1,8,489},	//( - , SCM) Заданная координата НЛ1 от ИС
	{&fEM_A5MV01RC1,8,491},	//( - , SCM) Заданная скорость НЛ1 от ИС
	{&iEM_TERNL2,3,493},	//( - , SCM) Неисправности НЛ2
	{&fEM_B5MC01RC1,8,494},	//( - , SCM) Заданная координата НЛ2 от ИС
	{&fEM_B5MV01RC1,8,496},	//( - , SCM) Заданная скорость НЛ2 от ИС
	{&fEM_A1UC08RIM,8,498},	//( - , SCM) Зона срабатывания КВ ББ(мм)
	{&fEM_A2UC08RIM,8,500},	//( - , SCM) Зона срабатывания КВ  РБ мм
	{&fEM_A3UC08RIM,8,502},	//( - , SCM) Зона срабатывания КВ ИС(мм)
	{&iEM_TERB2SS33LIM,3,504},	//( - , SCM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{&iEM_TERA1VP81LIM,3,505},	//( - , SCM) Искажение: Текущее давление СБРОС ББ1  в норме
	{&iEM_TERB1VP81LIM,3,506},	//( - , SCM) Искажение: Текущее давление СБРОС ББ2  в норме
	{&fEM_A0UT03RSP,8,507},	//( - , SCM) Стартовая  температура АЗ1 град
	{&fEM_A0UR01RSP,8,509},	//( - , SCM) Стартовая  реактивность АЗ1
	{&fEM_A0UR02RSP,8,511},	//( - , SCM) Стартовый  поток нейтронов АЗ1
	{&fEM_B0UT03RSP,8,513},	//( - , SCM) Стартовая  температура АЗ2 град
	{&fEM_A1MC01RSP,8,515},	//( - , SCM) Стартовая координата  ББ1
	{&fEM_A1MC02RSP,8,517},	//( - , SCM) Стартовая координата штока ББ1
	{&fEM_B1MC01RSP,8,519},	//( - , SCM) Стартовая координата  ББ2
	{&fEM_B1MC02RSP,8,521},	//( - , SCM) Стартовая координата штока ББ2
	{&fEM_A2MC01RC1,8,523},	//( - , SCM) Заданная координата РБ1 от ИС
	{&fEM_A2MV01RC1,8,525},	//( - , SCM) Заданная скорость движения РБ1 от ИС
	{&fEM_A2MC01RSP,8,527},	//( - , SCM) Стартовая координата  РБ1
	{&fEM_A2MC02RSP,8,529},	//( - , SCM) Стартовая координата штока РБ1
	{&fEM_B2MC01RSP,8,531},	//( - , SCM) Стартовая координата  РБ2
	{&fEM_B2MC02RSP,8,533},	//( - , SCM) Стартовая координата штока РБ2
	{&fEM_A3MC01RSP,8,535},	//( - , SCM) Стартовая координата  ИС1
	{&fEM_A3MC02RSP,8,537},	//( - , SCM) Стартовая координата штока ИС1
	{&fEM_B3MC01RSP,8,539},	//( - , SCM) Стартовая координата  ИС2
	{&fEM_B3MC02RSP,8,541},	//( - , SCM) Стартовая координата штока ИС2
	{&fEM_B8MC01RSP,8,543},	//( - , SCM) Стартовая координата АЗ2
	{&fEM_A8MC01RSP,8,545},	//( - , SCM) Стартовая координата ДС2
	{&fEM_A6MC01RSP,8,547},	//( - , SCM) Стартовая координата БЗ1
	{&fEM_B6MC01RSP,8,549},	//( - , SCM) Стартовая координата БЗ2
	{&fEM_R3UC01RSP,8,551},	//( - , SCM) Стартовая координата Гомогенных дверей
	{&fEM_R5UC01RSP,8,553},	//( - , SCM) Стартовая координата Ворот отстойной зоны
	{&fEM_R6UC01RSP,8,555},	//( - , SCM) Стартовая координата Кран-балки
	{&fEM_R2MC01RSP,8,557},	//( - , SCM) Стартовая координата МДЗ2
	{&fEM_R1MC01RSP,8,559},	//( - , SCM) Стартовая координата МДЗ1
	{&fEM_A5MC01RSP,8,561},	//( - , SCM) Стартовая координата НЛ1
	{&fEM_B5MC01RSP,8,563},	//( - , SCM) Стартовая координата НЛ2
	{&fEM_A9MC01RSP,8,565},	//( - , SCM) Стартовая координата НИ ДС1
	{&fEM_B9MC01RSP,8,567},	//( - , SCM) Стартовая координата НИ ДС2
	{&fEM_A4MC01RSP,8,569},	//( - , SCM) Стартовая координата НИ1
	{&fEM_B4MC01RSP,8,571},	//( - , SCM) Стартовая координата НИ2
	{&fEM_R4MC01RSP,8,573},	//( - , SCM) Стартовая координата тележки
	{&fEM_A1MV01RC1,8,575},	//( - , SCM) Заданная скорость движения  ББ1 от ИС
	{&iEM_TERB7MS31LIM,3,577},	//( - , SCM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{&iEM_TERA7MS31LIM,3,578},	//( - , SCM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{&fEM_R7UY00RSS,8,579},	//( - , SCM) Y-координата АЗ1 см
	{&iEM_TERA6VS12LIM,3,581},	//( - , SCM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{&iEM_TERA6VS22LIM,3,582},	//( - , SCM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{&iEM_TERB6VS12LIM,3,583},	//( - , SCM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{&iEM_TERB6VS22LIM,3,584},	//( - , SCM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{&iEM_TERA5VS22LIM,3,585},	//( - , SCM) Искажение: Движение створок НЛ1 к НУ
	{&iEM_TERA5VS12LIM,3,586},	//( - , SCM) Искажение: Движение створок НЛ1 к ВУ
	{&iEM_TERB5VS12LIM,3,587},	//( - , SCM) Искажение: Движение створок НЛ2 к ВУ
	{&iEM_TERB5VS22LIM,3,588},	//( - , SCM) Искажение: Движение створок НЛ2 к НУ
	{&iEM_TERR1VS12LIM,3,589},	//( - , SCM) Искажение: Движение МДЗ1 в сторону ВУ
	{&iEM_TERR1VS22LIM,3,590},	//( - , SCM) Искажение: Движение МДЗ1 в сторону НУ
	{&iEM_TERR2VS12LIM,3,591},	//( - , SCM) Искажение: Движение МДЗ2 в сторону ВУ
	{&iEM_TERR2VS22LIM,3,592},	//( - , SCM) Искажение: Движение МДЗ2 в сторону НУ
	{&iEM_TERR4VS12LDU,3,593},	//( - , SCM) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{&iEM_TERR4VS22LDU,3,594},	//( - , SCM) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{&fEM_A0UX13RSS,8,595},	//( - , SCM) Первый коэффициент калибровки камеры 13
	{&fEM_A0UX14RSS,8,597},	//( - , SCM) Первый коэффициент калибровки камеры 14
	{&fEM_A0UX15RSS,8,599},	//( - , SCM) Первый коэффициент калибровки камеры 15
	{&fEM_R7UX13RSS,8,601},	//( - , SCM) X-координата камеры R7IN51
	{&fEM_R7UX14RSS,8,603},	//( - , SCM) X-координата камеры R7IN52
	{&fEM_R7UX15RSS,8,605},	//( - , SCM) X-координата камеры R7IN53
	{&fEM_R7UY13RSS,8,607},	//( - , SCM) Y-координата камеры R7IN51
	{&fEM_R7UY14RSS,8,609},	//( - , SCM) Y-координата камеры R7IN52
	{&fEM_R7UY15RSS,8,611},	//( - , SCM) Y-координата камеры R7IN53
	{&fEM_R7UX16RSS,8,613},	//( - , SCM) Величина сигнала СНМ11 в БЗ
	{&fEM_B8MC01RC1,8,615},	//( - , SCM) Заданная координата АЗ2 от ИС
	{&fEM_A0UN07RIM,8,617},	//( - , SCM) Доля запаздывающих нейтронов
	{&fEM_R0UL02RIM,8,619},	//( - , SCM) Время удержания синхроимпульса
	{&fEM_R0UL02RDU,8,621},	//( - , SCM) Время задержки  ИНИ
	{&fEM_R0UL04RIM,8,623},	//( - , SCM) Время блокировки повторной генерации импульса
	{&fEM_R0UN18RDU,8,625},	//( - , SCM) Коэффициент температурной корректировки реактивности(долл)
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SBz1[]={
	{&R0VZ71LZ1,1,0},	//( - , SCM, SBz1) Обобщенный сигнал по АЗ  1 канала
	{&R0EE01LZ1,1,1},	//( - , SBz1) Питание  АКНП1  отключить
	{&R0EE02LZ1,1,2},	//( - , SBz1) Питание  АКНП  отключить
	{&R0EE03LZ1,1,3},	//( - , SBz1) Питание  АКНП3  отключить
	{&R0EE04LZ1,1,4},	//( - , SBz1) Питание  АКНП4  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz1[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SBz1[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SBz1[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SBz2[]={
	{&R0VZ71LZ2,1,0},	//( - , SCM, SBz2) Обобщенный сигнал по АЗ  2 канала
	{&R0EE01LZ2,1,1},	//( - , SBz2) Питание  АКНП1  отключить
	{&R0EE02LZ2,1,2},	//( - , SBz2) Питание  АКНП  отключить
	{&R0EE03LZ2,1,3},	//( - , SBz2) Питание  АКНП3  отключить
	{&R0EE04LZ2,1,4},	//( - , SBz2) Питание  АКНП4  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz2[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SBz2[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SBz2[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SDu[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SDu[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SDu[]={
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
static ModbusRegister hr_SDu[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SA1[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SA1[]={
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA1[]={
	{&R0IN01FI1,8,0},	//( - , SA1) Выход СНМ11 Гц от ПТИ
	{&R0IN02FI1,8,2},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI1,8,4},	//( - , SA1) Выход КНК53М Гц от ПТИ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SA1[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SA2[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SA2[]={
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA2[]={
	{&R0IN01FI2,8,0},	//( - , SA2) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI2,8,2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI2,8,4},	//( - , SA2) Выход КНК53М Гц от ПТИ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SA2[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SA3[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SA3[]={
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA3[]={
	{&R0IN01FI3,8,0},	//( - , SA3) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI3,8,2},	//( - , SA3) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI3,8,4},	//( - , SA3) Выход КНК53М Гц от ПТИ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SA3[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SA4[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SA4[]={
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA4[]={
	{&R0IN01FI4,8,0},	//( - , SA4) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI4,8,2},	//( - , SA4) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI4,8,4},	//( - , SA4) Выход КНК53М Гц от ПТИ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SA4[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SRP[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SRP[]={
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SRP[]={
	{&R0IN01RIP,8,0},	//( - , SRP) Выход СНМ-11 Гц от ПТИ
	{&R0IN02RIP,8,2},	//( - , SRP) Выход КНК15- Гц от ПТИ
	{&R0IN03RIP,8,4},	//( - , SRP) Выход КНК53М Гц от ПТИ
	{&R0IN06RIP,8,6},	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
	{&R0IN07RIP,8,8},	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SRP[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_SCM[0],&di_SCM[0],&ir_SCM[0],&hr_SCM[0],NULL,NULL,NULL,0},	//Общий слэйв
	{0,5003,&coil_SBz1[0],&di_SBz1[0],&ir_SBz1[0],&hr_SBz1[0],NULL,NULL,NULL,0},	//Cлэйв Baz1
	{0,5004,&coil_SBz2[0],&di_SBz2[0],&ir_SBz2[0],&hr_SBz2[0],NULL,NULL,NULL,0},	//Cлэйв Baz2
	{0,5005,&coil_SDu[0],&di_SDu[0],&ir_SDu[0],&hr_SDu[0],NULL,NULL,NULL,0},	//Cлэйв DU
	{0,5006,&coil_SA1[0],&di_SA1[0],&ir_SA1[0],&hr_SA1[0],NULL,NULL,NULL,0},	//Cлэйв AKNP1
	{0,5007,&coil_SA2[0],&di_SA2[0],&ir_SA2[0],&hr_SA2[0],NULL,NULL,NULL,0},	//Cлэйв AKNP2
	{0,5008,&coil_SA3[0],&di_SA3[0],&ir_SA3[0],&hr_SA3[0],NULL,NULL,NULL,0},	//Cлэйв AKNP3
	{0,5009,&coil_SA4[0],&di_SA4[0],&ir_SA4[0],&hr_SA4[0],NULL,NULL,NULL,0},	//Cлэйв AKNP4
	{0,5010,&coil_SRP[0],&di_SRP[0],&ir_SRP[0],&hr_SRP[0],NULL,NULL,NULL,0},	//Cлэйв RPU
	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},
};
#pragma pop
#include <drivers/ao16.h>
static char buf_AO1601[176];	//AO1601
static ao16_inimod ini_AO1601={0xffff,120,0x43,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_AO1601={0,0,&ini_AO1601,buf_AO1601,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_AO1601[]={
	{&A0IT01IZ1,3,0},
	{&A2IP01IZ1,3,3},
	{&B0IT01IZ1,3,6},
	{&B2IP01IZ1,3,9},
	{&A0IT02IZ2,3,12},
	{&A2IP01IZ2,3,15},
	{&B0IT02IZ2,3,18},
	{&B2IP01IZ2,3,21},
	{&A3IP02IDU,3,24},
	{&B3IP02IDU,3,27},
	{&A0IT03IRP,3,30},
	{&B0IT03IRP,3,33},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F01[197];	//DO32_5F01
static do32_pti_inipar ini_DO32_5F01={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F01={0,0,&ini_DO32_5F01,buf_DO32_5F01,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F01[]={
	{&R7II71LZ1,1,0},
	{&R7II75LZ1,1,2},
	{&R7II76LZ1,1,4},
	{&R7II74LZ1,1,6},
	{&R7II72LZ1,1,8},
	{&R6IS66LZ1,1,32},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F02[197];	//DO32_5F02
static do32_pti_inipar ini_DO32_5F02={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F02={0,0,&ini_DO32_5F02,buf_DO32_5F02,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F02[]={
	{&A1VP81LZZ,1,0},
	{&A3IS22LDU,1,2},
	{&A0VP81LZZ,1,4},
	{&A3IS11LDU,1,6},
	{&R7II73LZ1,1,14},
	{&B3IS11LDU,1,20},
	{&B3IS22LDU,1,22},
	{&R6IS66LZ2,1,32},
	{&R7II72LZ2,1,34},
	{&R7II75LZ2,1,36},
	{&R7II74LZ2,1,38},
	{&R7II71LZ2,1,42},
	{&R7II73LZ2,1,46},
	{&R7II76LZ2,1,48},
	{&B0VP81LZZ,1,58},
	{&B1VP81LZZ,1,60},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F05[197];	//DO32_5F05
static do32_pti_inipar ini_DO32_5F05={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F05={0,0,&ini_DO32_5F05,buf_DO32_5F05,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F05[]={
	{&B5IS21LDU,1,0},
	{&R3IS11LDU,1,2},
	{&R3IS21LDU,1,4},
	{&B8IS21LDU,1,8},
	{&B8IS12LDU,1,10},
	{&B8IS22LDU,1,12},
	{&B8IS11LDU,1,14},
	{&R5IS11LDU,1,18},
	{&R5IS21LDU,1,20},
	{&R6IS21LDU,1,26},
	{&A8IS12LDU,1,28},
	{&A8IS22LDU,1,30},
	{&A6IS11LDU,1,34},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F06[197];	//DO32_5F06
static do32_pti_inipar ini_DO32_5F06={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F06={0,0,&ini_DO32_5F06,buf_DO32_5F06,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F06[]={
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F08[197];	//DO32_5F08
static do32_pti_inipar ini_DO32_5F08={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F08={0,0,&ini_DO32_5F08,buf_DO32_5F08,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F08[]={
	{&B7AS31LDU,1,10},
	{&B1IS12LDU,1,12},
	{&B1IS11LDU,1,14},
	{&B1IS21LDU,1,16},
	{&B2IS12LDU,1,18},
	{&B2IS11LDU,1,20},
	{&B2IS21LDU,1,22},
	{&B3IS21LDU,1,24},
	{&R8IS11LDU,1,26},
	{&A4IS11LDU,1,30},
	{&A4IS21LDU,1,32},
	{&A9IS11LDU,1,34},
	{&A9IS21LDU,1,36},
	{&B9IS11LDU,1,38},
	{&B9IS21LDU,1,40},
	{&R1IS11LDU,1,42},
	{&R1IS21LDU,1,44},
	{&R2IS11LDU,1,46},
	{&R2IS21LDU,1,48},
	{&A7AS31LDU,1,60},
	{&A1IS12LDU,1,62},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F09[197];	//DO32_5F09
static do32_pti_inipar ini_DO32_5F09={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F09={0,0,&ini_DO32_5F09,buf_DO32_5F09,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F09[]={
	{&A1IS11LDU,1,0},
	{&A1IS21LDU,1,2},
	{&A2IS12LDU,1,4},
	{&A2IS11LDU,1,6},
	{&A2IS21LDU,1,8},
	{&A3IS21LDU,1,10},
	{&B4IS11LDU,1,12},
	{&B4IS21LDU,1,14},
	{&R8AD22LDU,1,16},
	{&R0IS02LDU,1,32},
	{&R4IS11LDU,1,42},
	{&R4IS12LDU,1,44},
	{&R4IS21LDU,1,46},
	{&R4IS22LDU,1,48},
	{&A6IS21LDU,1,52},
	{&A5IS11LDU,1,54},
	{&A5IS21LDU,1,56},
	{&B6IS11LDU,1,58},
	{&B6IS21LDU,1,60},
	{&B5IS11LDU,1,62},
	{NULL,0,0},
};
#pragma pop
#include <drivers/vds32_pti.h>
static char buf_VDS32F07[129];	//VDS32F07
static vds32pti_inimod ini_VDS32F07={0,};
#pragma pack(push,1)
static table_drv table_VDS32F07={0,0,&ini_VDS32F07,buf_VDS32F07,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F07[]={
	{&A3AD34LDU,1,22},
	{&A3AD33LDU,1,24},
	{&A2AD33LDU,1,26},
	{&A4AD10LDU,1,28},
	{&A3AD31LDU,1,30},
	{&A7AP31LDU,1,32},
	{&R1AD10LDU,1,34},
	{&R1AD20LDU,1,36},
	{&R2AD10LDU,1,38},
	{&R2AD20LDU,1,40},
	{&A5AD10LDU,1,42},
	{&A5AD20LDU,1,44},
	{&B5AD10LDU,1,46},
	{&B5AD20LDU,1,48},
	{&B3AD34LDU,1,50},
	{&B3AD33LDU,1,52},
	{&B2AD33LDU,1,54},
	{&B4AD10LDU,1,56},
	{&B3AD31LDU,1,58},
	{&B7AP31LDU,1,60},
	{&A8AD10LDU,1,62},
	{NULL,0,0},
};
#pragma pop
#include <drivers/vds32_pti.h>
static char buf_VDS32F10[129];	//VDS32F10
static vds32pti_inimod ini_VDS32F10={0,};
#pragma pack(push,1)
static table_drv table_VDS32F10={0,0,&ini_VDS32F10,buf_VDS32F10,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F10[]={
	{&A8AD20LDU,1,0},
	{&A6AD10LDU,1,2},
	{&A6AD20LDU,1,4},
	{&B6AD10LDU,1,6},
	{&B6AD20LDU,1,8},
	{&R4AD10LDU,1,10},
	{&R4AD20LDU,1,12},
	{&B8AD10LDU,1,14},
	{&B8AD20LDU,1,16},
	{&A3AD11LDU,1,18},
	{&A3AD21LDU,1,20},
	{&A3AD01LDU,1,22},
	{&A3AD02LDU,1,24},
	{&A3AD03LDU,1,26},
	{&A3AD04LDU,1,28},
	{&A3AD05LDU,1,30},
	{&B3AD11LDU,1,32},
	{&B3AD21LDU,1,34},
	{&B3AD01LDU,1,36},
	{&B3AD02LDU,1,38},
	{&B3AD03LDU,1,40},
	{&B3AD04LDU,1,42},
	{&B3AD05LDU,1,44},
	{&A9AD10LDU,1,46},
	{&B9AD10LDU,1,48},
	{&A1AD11LDU,1,50},
	{&A1AD21LDU,1,52},
	{&A1AD01LDU,1,54},
	{&A1AD02LDU,1,56},
	{&A1AD03LDU,1,58},
	{&A1AD04LDU,1,60},
	{&R0S01LIM,1,62},
	{NULL,0,0},
};
#pragma pop
#include <drivers/vds32_pti.h>
static char buf_VDS32F11[129];	//VDS32F11
static vds32pti_inimod ini_VDS32F11={0,};
#pragma pack(push,1)
static table_drv table_VDS32F11={0,0,&ini_VDS32F11,buf_VDS32F11,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F11[]={
	{&A1AD05LDU,1,0},
	{&B1AD11LDU,1,2},
	{&B1AD21LDU,1,4},
	{&B1AD01LDU,1,6},
	{&B1AD02LDU,1,8},
	{&B1AD03LDU,1,10},
	{&B1AD04LDU,1,12},
	{&B1AD05LDU,1,14},
	{&A2AD11LDU,1,16},
	{&A2AD21LDU,1,18},
	{&A2AD01LDU,1,20},
	{&A2AD02LDU,1,22},
	{&A2AD03LDU,1,24},
	{&A2AD04LDU,1,26},
	{&A2AD05LDU,1,28},
	{&B2AD11LDU,1,30},
	{&B2AD21LDU,1,32},
	{&B2AD01LDU,1,34},
	{&B2AD02LDU,1,36},
	{&B2AD03LDU,1,38},
	{&B2AD04LDU,1,40},
	{&B2AD05LDU,1,42},
	{&A1AD32LDU,1,44},
	{&A1AD31LDU,1,46},
	{&A2AD32LDU,1,48},
	{&A2AD31LDU,1,50},
	{&B1AD32LDU,1,52},
	{&B1AD31LDU,1,54},
	{&B2AD32LDU,1,56},
	{&B2AD31LDU,1,58},
	{&R8AD21LDU,1,60},
	{&R0AD16LDU,1,62},
	{NULL,0,0},
};
#pragma pop
#include <drivers/emul8enc.h>
static char buf_em8enc120[96];	//em8enc120
static em8encpti_inimod ini_em8enc120={0x340,0x4,};
#pragma pack(push,1)
static table_drv table_em8enc120={0,0,&ini_em8enc120,buf_em8enc120,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_em8enc120[]={
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0x04,0x320,37,176,def_buf_AO1601,&table_AO1601},	//AO16
	{0x02,0x100,1,197,def_buf_DO32_5F01,&table_DO32_5F01},	//do32_5f(0x100)
	{0x02,0x110,1,197,def_buf_DO32_5F02,&table_DO32_5F02},	//do32_5f(0x110)
	{0x02,0x150,1,197,def_buf_DO32_5F05,&table_DO32_5F05},	//do32_5f(0x150)
	{0x02,0x160,1,197,def_buf_DO32_5F06,&table_DO32_5F06},	//do32_5f(0x160)
	{0x02,0x130,1,197,def_buf_DO32_5F08,&table_DO32_5F08},	//do32_5f(0x130)
	{0x02,0x140,1,197,def_buf_DO32_5F09,&table_DO32_5F09},	//do32_5f(0x140)
	{0x03,0x340,1,129,def_buf_VDS32F07,&table_VDS32F07},	//vds32f2(0x340)
	{0x03,0x360,1,129,def_buf_VDS32F10,&table_VDS32F10},	//vds32f2(0x360)
	{0x03,0x310,1,129,def_buf_VDS32F11,&table_VDS32F11},	//vds32f2(0x310)
	{0x05,0x120,2,96,def_buf_em8enc120,&table_em8enc120},	//em8enc(0x120)
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){	//Инициализация переменных для хранения
	setAsFloat(288,1E12);
	setAsFloat(289,0.008);
	setAsFloat(290,0.0069);
	setAsFloat(291,2.74);
	setAsFloat(292,2.9);
	setAsFloat(293,-0.15912805);
	setAsFloat(294,0.000000166);
	setAsFloat(295,25.017338);
	setAsFloat(296,11.0);
	setAsFloat(297,1.0);
	setAsFloat(298,1.0);
	setAsFloat(299,1.0);
	setAsFloat(300,1.0);
	setAsFloat(301,1.0);
	setAsFloat(302,1.0);
	setAsFloat(303,1.0);
	setAsFloat(304,1.0);
	setAsFloat(305,1.0);
	setAsFloat(306,1.0);
	setAsFloat(307,1.0);
	setAsFloat(308,1.0);
	setAsFloat(309,1.0);
	setAsFloat(310,1.0);
	setAsFloat(311,1.0);
	setAsFloat(312,0);
	setAsFloat(313,0);
	setAsFloat(314,0);
	setAsFloat(315,0);
	setAsFloat(316,0);
	setAsFloat(317,0);
	setAsFloat(318,0.000877);
	setAsFloat(319,0.00009765625);
	setAsFloat(320,200);
	setAsFloat(321,100);
	setAsFloat(322,0);
	setAsFloat(323,0.01);
	setAsFloat(324,20.0);
	setAsFloat(325,0.76);
	setAsFloat(326,0.73);
	setAsFloat(327,0);
	setAsFloat(328,0.21);
	setAsFloat(329,5.0);
	setAsFloat(330,9807.0);
	setAsFloat(331,0);
	setAsFloat(332,0);
	setAsFloat(333,0);
	setAsFloat(334,0);
	setAsFloat(335,0);
	setAsFloat(336,0);
	setAsFloat(337,0.002375);
	setAsFloat(338,0.00009765625);
	setAsFloat(339,80);
	setAsFloat(340,100);
	setAsFloat(341,0);
	setAsFloat(342,0.01);
	setAsFloat(343,20.0);
	setAsFloat(344,0.245);
	setAsFloat(345,0.45);
	setAsFloat(346,1.6);
	setAsFloat(347,0.39);
	setAsFloat(348,0);
	setAsFloat(349,0);
	setAsFloat(350,0.026);
	setAsFloat(351,5.0);
	setAsFloat(352,12750.0);
	setAsFloat(353,0);
	setAsFloat(354,0.000885839);
	setAsFloat(355,0);
	setAsFloat(356,0.000885839);
	setAsFloat(357,0);
	setAsFloat(358,0);
	setAsFloat(359,0.001675);
	setAsFloat(360,0.00009765625);
	setAsFloat(361,200);
	setAsFloat(362,160);
	setAsFloat(363,0);
	setAsFloat(364,0.01);
	setAsFloat(365,20.0);
	setAsFloat(366,0.13);
	setAsFloat(367,0.6);
	setAsFloat(368,0.07);
	setAsFloat(369,2.5);
	setAsFloat(370,0);
	setAsFloat(371,0);
	setAsFloat(372,0.0096);
	setAsFloat(373,5.0);
	setAsFloat(374,22975.0);
	setAsFloat(375,0);
	setAsFloat(376,5.0);
	setAsFloat(377,0.275);
	setAsFloat(378,0.245);
	setAsFloat(379,0);
	setAsFloat(380,5);
	setAsFloat(381,0);
	setAsFloat(382,5.0);
	setAsFloat(383,0);
	setAsFloat(384,55);
	setAsFloat(385,0);
	setAsFloat(386,55.0);
	setAsFloat(387,0);
	setAsFloat(388,0);
	setAsFloat(389,390);
	setAsFloat(390,0);
	setAsFloat(391,0.0009765625);
	setAsFloat(392,0.50);
	setAsFloat(393,1500.0);
	setAsFloat(394,2000);
	setAsFloat(395,390.0);
	setAsFloat(396,0);
	setAsFloat(397,20);
	setAsFloat(398,10.91);
	setAsFloat(399,0);
	setAsFloat(400,15.0);
	setAsFloat(401,25.017338);
	setAsFloat(402,0);
	setAsFloat(403,0);
	setAsFloat(404,0);
	setAsFloat(405,0);
	setAsFloat(406,0.0);
	setAsFloat(407,0);
	setAsFloat(408,0.0);
	setAsFloat(409,0);
	setAsFloat(410,0.0);
	setAsFloat(411,0.0);
	setAsFloat(412,0.0);
	setAsFloat(413,0.0);
	setAsFloat(414,0);
	setAsFloat(415,0);
	setAsFloat(416,0);
	setAsFloat(417,0);
	setAsFloat(418,0);
	setAsFloat(419,0);
	setAsFloat(420,0);
	setAsFloat(421,0);
	setAsFloat(422,0);
	setAsFloat(423,0);
	setAsFloat(424,0);
	setAsFloat(425,0);
	setAsFloat(426,0);
	setAsFloat(427,0.000885839);
	setAsFloat(428,0);
	setAsFloat(429,0.000885839);
	setAsFloat(430,0);
	setAsFloat(431,0);
	setAsFloat(432,0);
	setAsFloat(433,0);
	setAsFloat(434,5);
	setAsFloat(435,0);
	setAsFloat(436,0);
	setAsFloat(437,55);
	setAsFloat(438,0);
	setAsFloat(439,0);
	setAsFloat(440,390);
	setAsFloat(441,0);
	setAsFloat(442,0.50);
	setAsFloat(443,1500.0);
	setAsFloat(444,2000.0);
	setAsFloat(445,390.0);
	setAsFloat(446,0);
	setAsFloat(447,20);
	setAsFloat(448,10.91);
	setAsFloat(449,0);
	setAsFloat(450,20);
	setAsFloat(451,37037.04);
	setAsFloat(452,975000.0);
	setAsFloat(453,32000.0);
	setAsFloat(454,4000);
	setAsFloat(455,100000);
	setAsFloat(456,1000000);
	setAsFloat(457,0.015);
	setAsFloat(458,0.015);
	setAsFloat(459,0.5);
	setAsFloat(460,600);
	setAsFloat(461,0.0069);
	setAsFloat(462,0.00097);
	setAsFloat(463,27.108);
	setAsFloat(464,0.0);
	setAsFloat(465,0);
	setAsFloat(466,600);
	setAsFloat(467,120);
	setAsFloat(468,25);
	setAsFloat(469,200);
	setAsFloat(470,320.435466);
	setAsFloat(471,0.0055);
	setAsFloat(472,100);
	setAsFloat(473,200);
	setAsFloat(474,300);
	setAsFloat(475,400);
	setAsFloat(476,500);
	setAsFloat(477,600);
	setAsFloat(478,750);
	setAsFloat(479,0);
	setAsFloat(480,0);
	setAsFloat(481,0);
	setAsFloat(482,15.0);
	setAsFloat(483,0);
	setAsFloat(484,0);
	setAsFloat(485,0);
	setAsFloat(486,0);
	setAsFloat(487,15.0);
	setAsFloat(488,0);
	setAsFloat(489,1530.0);
	setAsFloat(490,0);
	setAsFloat(491,0.50);
	setAsFloat(492,1530.0);
	setAsFloat(493,137.4);
	setAsFloat(494,40.0);
	setAsFloat(495,20);
	setAsFloat(496,4);
	setAsFloat(497,4000.0);
	setAsFloat(498,20.0);
	setAsFloat(499,10);
	setAsFloat(500,10.0);
	setAsFloat(501,1269.0);
	setAsFloat(502,256.0);
	setAsFloat(503,1.0);
	setAsFloat(504,18000);
	setAsFloat(505,18000);
	setAsFloat(506,10000.0);
	setAsFloat(507,100.0);
	setAsFloat(508,0.035);
	setAsFloat(509,0.035);
	setAsFloat(510,2.0);
	setAsFloat(511,1585.0);
	setAsFloat(512,1796.0);
	setAsFloat(513,1555.0);
	setAsFloat(514,1269.0);
	setAsFloat(515,1269.0);
	setAsFloat(516,1585.0);
	setAsFloat(517,1796.0);
	setAsFloat(518,1269.0);
	setAsFloat(519,1555.0);
	setAsFloat(520,1281.2);
	setAsFloat(521,1269.0);
	setAsFloat(522,1570.0);
	setAsFloat(523,1269);
	setAsFloat(524,1281.2);
	setAsFloat(525,1);
	setAsFloat(526,506.5);
	setAsFloat(527,248.0);
	setAsFloat(528,284.5);
	setAsFloat(529,248.0);
	setAsFloat(530,271.6);
	setAsFloat(531,287.2);
	setAsFloat(532,594.0);
	setAsFloat(533,559.0);
	setAsFloat(534,588.0);
	setAsFloat(535,594.0);
	setAsFloat(536,597.2);
	setAsFloat(537,556.8);
	setAsFloat(538,248.0);
	setAsFloat(539,572.4);
	setAsFloat(540,246.8);
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
	setAsShort(551,0);
	setAsShort(552,0);
	setAsShort(553,0);
	setAsShort(554,0);
	setAsShort(555,0);
	setAsShort(556,0);
	setAsShort(557,0);
	setAsShort(558,0);
	setAsShort(559,0);
	setAsShort(560,0);
	setAsShort(561,0);
	setAsShort(562,0);
	setAsShort(563,0);
	setAsShort(564,0);
	setAsShort(565,0);
	setAsShort(566,0);
	setAsShort(567,0);
	setAsShort(568,0);
	setAsShort(569,0);
	setAsShort(570,0);
	setAsShort(571,0);
	setAsShort(572,0);
	setAsShort(573,0);
	setAsShort(574,0);
	setAsShort(575,0);
	setAsShort(576,0);
	setAsShort(577,0);
	setAsShort(578,0);
	setAsShort(579,0);
	setAsShort(580,0);
	setAsShort(581,0);
	setAsShort(582,0);
	setAsShort(583,0);
	setAsShort(584,0);
	setAsShort(585,0);
	setAsShort(586,0);
	setAsShort(587,0);
	setAsShort(588,0);
	setAsShort(589,0);
	setAsShort(590,0);
	setAsShort(591,0);
	setAsShort(592,0);
	setAsShort(593,0);
	setAsShort(594,0);
	setAsShort(595,0);
	setAsShort(596,0);
	setAsShort(597,0);
	setAsShort(598,0);
	setAsShort(599,0);
	setAsShort(600,0);
	setAsShort(601,0);
	setAsShort(602,0);
	setAsShort(603,0);
	setAsShort(604,0);
	setAsShort(605,0);
	setAsShort(606,0);
	setAsShort(607,0);
	setAsShort(608,0);
	setAsShort(609,0);
	setAsShort(610,0);
	setAsShort(611,0);
	setAsShort(612,0);
	setAsShort(613,0);
	setAsShort(614,0);
	setAsShort(615,0);
	setAsShort(616,0);
	setAsShort(617,0);
	setAsShort(618,0);
	setAsShort(619,0);
	setAsShort(620,0);
	setAsShort(621,0);
	setAsShort(622,0);
	setAsShort(623,0);
	setAsShort(624,0);
	setAsShort(625,0);
	setAsShort(626,0);
	setAsShort(627,0);
	setAsShort(628,0);
	setAsShort(629,0);
	setAsShort(630,0);
	setAsShort(631,0);
	setAsShort(632,0);
	setAsShort(633,0);
	setAsShort(634,0);
	setAsShort(635,0);
	setAsShort(636,0);
	setAsShort(637,0);
	setAsShort(638,0);
	setAsShort(639,0);
	setAsShort(640,0);
	setAsShort(641,0);
	setAsShort(642,0);
	setAsShort(643,0);
	setAsShort(644,0);
	setAsShort(645,0);
	setAsShort(646,0);
	setAsShort(647,0);
	setAsShort(648,0);
	setAsShort(649,0);
	setAsShort(650,0);
	setAsShort(651,0);
	setAsShort(652,0);
	setAsShort(653,0);
	setAsShort(654,0);
	setAsShort(655,0);
	setAsShort(656,0);
	setAsShort(657,0);
	setAsShort(658,0);
	setAsShort(659,0);
	setAsBool(1044,0);
	setAsBool(1045,0);
	setAsBool(1046,0);
	setAsBool(1047,0);
	setAsBool(1048,1);
	setAsBool(1049,1);
	setAsBool(1050,0);
	setAsBool(1051,0);
	setAsBool(1052,1);
	setAsShort(203,2);
}
int freebuff=0;
/* Определение внутренних параметров */

/* Определение констант ПЗУ и ЭСППЗУ*/
ssbool lRM_1_ = {1,0}; /* Флаг наличия магнита на штоке ОРР */ 
ssfloat fRM_0_ = {0,0}; /* Заглушка давления на подъём ББ1 */ 
ssfloat fRM_1_ = {1,0}; /* *Vm - массив скоростей движения (шагов в секунду) */ 
ssbool lRM_0_ = {0,0}; /* Флаг наличия магнита на штоке ОРР */ 
ssfloat fRM_1_0 = {1.0,0}; /* Номинальная скорость БЗ (град/с) */ 
ssfloat fRM_180_0 = {180.0,0}; /* Координата верхнего путевого выключателя БЗ град */ 
ssfloat fRM_0_0 = {0.0,0}; /* Координата нижних упоров БЗ град */ 
ssfloat fRM_n50_ = {-50,0}; /* Координата нижнего путевого выключателя БЗ град */ 
ssfloat fRM_2000_0 = {2000.0,0}; /* Координата верхнего путевого выключателя МДЗ мм */ 
ssfloat fRM_n150_ = {-150,0}; /* Координата нижнего путевого выключателя МДЗ мм */ 
ssfloat fRM_1500_0 = {1500.0,0}; /* Координата верхнего механического выключателя НЛ мм */ 
ssint iRM_7_ = {7,0}; /* N */ 
ssfloat fRM_390_ = {390,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_420_ = {420,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_513_ = {513,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_767_ = {767,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_900_ = {900,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_1200_ = {1200,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_1500_ = {1500,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_3_546 = {3.546,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_2_7 = {2.7,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_2_ = {2,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_88884 = {0.88884,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_6221739 = {0.6221739,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_35555072 = {0.35555072,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_2666666667 = {0.2666666667,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssint iRM_5_ = {5,0}; /* N */ 
ssfloat fRM_600_ = {600,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_0_5 = {0.5,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_2 = {0.2,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_088884 = {0.088884,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_066666667 = {0.066666667,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_02173913 = {0.02173913,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_002453 = {0.002453,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_00184 = {0.00184,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_10 = {0.10,0}; /* Зона срабатывания КВ БЗ(мм) */ 
ssfloat fRM_0_50 = {0.50,0}; /* Зона срабатывания КВ МДЗ (мм) */ 
ssint iRM_2_ = {2,0}; /* n - N-размерность массива x */ 
ssint iRM_3_ = {3,0}; /* N-число входов */ 
ssint iRM_4_ = {4,0}; /* N-число входов */ 
ssint iRM_0_ = {0,0}; /* Ter - Неисправности механизма */ 
ssfloat fRM_100000_ = {100000,0}; /* KPv - координата пер. выключателя механизма мм */ 
ssfloat fRM_n100_ = {-100,0}; /* KZv - координата зад. выключателя механизма мм */ 
ssfloat fRM_20_ = {20,0}; /* Tp - Тормозной путь мм */ 
sschar bRM_2_ = {2,0}; /* type - тип камеры */ 
sschar bRM_4_ = {4,0}; /* type - тип камеры */ 
sschar bRM_5_ = {5,0}; /* type - тип камеры */ 
sschar bRM_1_ = {1,0}; /* type - тип камеры */ 
ssfloat fRM_3_ = {3,0}; /* m1 - величина отклонения второго сигнала от входного */ 
ssfloat fRM_2_0 = {2.0,0}; /* ampl - амплетуда синусоидального отклонения */ 
ssint iRM_3276_ = {3276,0}; /* min - минимальное возможное значение выходного сигнала */ 
ssint iRM_16000_ = {16000,0}; /* max - максимальное возможное значение выходного сигнала */ 
ssfloat fRM_3276_ = {3276,0}; /* c   - мин. значение кода ФАС */ 
ssfloat fRM_16000_ = {16000,0}; /* d - макс.  значение кода ФАС */ 
ssfloat fRM_200_ = {200,0}; /* maxs1 - макc. значение второго сигнала */ 
ssfloat fRM_0_0015 = {0.0015,0}; /* m1 - величина отклонения второго сигнала от входного */ 
ssfloat fRM_0_001 = {0.001,0}; /* ampl - амплетуда синусоидального отклонения */ 
ssfloat fRM_0_1 = {0.1,0}; /* k - коэффициент усиления */ 
ssint iRM_16_ = {16,0}; /* n - N-размерность массива входных параметров */ 
ssfloat fRM_2000_ = {2000,0}; /* maxs1 - макc. значение второго сигнала */ 
ssfloat fRM_15_ = {15,0}; /* m1 - величина отклонения второго сигнала от входного */ 


/* Определение переменных */
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m355_x_1[16] = {&lEM_R8AD10LC1,&lEM_R8AD10LC1,&var331,&var190,&var184,&var273,&var271,&var265,&var262,&var278,&var321,&var316,&var307,&var297,&var291,&R0MW13LP2};
psbool  array_m905_x_1[2] = {&lEM_R0IE02LRP,&lEM_R0IE01LRP};
psbool  array_m900_x_1[2] = {&var173,&R0MW13LP2};
psbool  array_m925_x_1[2] = {&var178,&R0MW13LP2};
psbool  array_m918_x_1[2] = {&var179,&R0MW13LP2};
psbool  array_m910_x_1[2] = {&var180,&R0MW13LP2};
psbool  array_m612_x_1[2] = {&var38,&var231};
psbool  array_m623_x_1[3] = {&lEM_C1AD31LRP,&var2,&var1};
psbool  array_m902_x_1[2] = {&var202,&R0MW13LP2};
psbool  array_m292_x_1[2] = {&var219,&B3AD31LDU};
psbool  array_m258_x_1[3] = {&B2AD31LDU,&var205,&var219};
psbool  array_m259_x_1[3] = {&B2AD32LDU,&var205,&var219};
psbool  array_m221_x_1[4] = {&B1AD32LDU,&var208,&var207,&var219};
psbool  array_m220_x_1[4] = {&var208,&B1AD31LDU,&var207,&var219};
psbool  array_m124_x_1[2] = {&A3AD31LDU,&var219};
psbool  array_m54_x_1[4] = {&A1AD32LDU,&var213,&var212,&var219};
psbool  array_m53_x_1[4] = {&var213,&A1AD31LDU,&var212,&var219};
psbool  array_m91_x_1[3] = {&A2AD31LDU,&var217,&var219};
psbool  array_m92_x_1[3] = {&A2AD32LDU,&var217,&var219};
psbool  array_m631_x_1[2] = {&var230,&var37};
psfloat  array_m7_a_1[5] = {&fRM_390_,&fRM_600_,&fRM_900_,&fRM_1200_,&fRM_1500_};
psfloat  array_m7_b_1[5] = {&fRM_0_5,&fRM_0_2,&fRM_0_088884,&fRM_0_066666667,&fRM_0_02173913};
psfloat  array_m9_a_1[7] = {&fRM_390_,&fRM_420_,&fRM_513_,&fRM_767_,&fRM_900_,&fRM_1200_,&fRM_1500_};
psfloat  array_m9_b_1[7] = {&fRM_3_546,&fRM_2_7,&fRM_2_,&fRM_0_88884,&fRM_0_6221739,&fRM_0_35555072,&fRM_0_2666666667};
psfloat  array_m300_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m134_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m267_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m103_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m232_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m66_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};

/* Объявление структур */
_S_noto  S_noto_635_1 = {&R0VZ71LZ2,&var1};
_S_noto  S_noto_634_1 = {&R0VZ71LZ1,&var2};
_S_vmemf  S_vmemf_176_1 = {&var332,&var3,&internal1_m176_x0};
_S_kvds  S_kvds_39_1 = {&var298,&var291,&R8AD21LDU,&fEM_R0UL02RDU,&fEM_R0UL04RIM,&fEM_R0UL02RIM,&var4,&var5,&internal1_m39_reg,&internal1_m39_tgen,&internal1_m39_tsin,&internal1_m39_tlock,&internal1_m39_fef};
_S_looktakt  S_looktakt_150_1 = {&var6};
_S_to3val  S_to3val_954_1 = {&fEM_R7UX16RSS,&fRM_900_,&fRM_15_,&fRM_0_0015,&fRM_0_,&fRM_2000_,&fRM_2000_,&TerR0IN06FRP,&var7,&var8,&vainSFloat,&bFirstEnterFlag};
_S_vchs  S_vchs_880_1 = {&var282,&var333,&var243,&fEM_R7UY00RSS,&var221,&fEM_R7UX15RSS,&fEM_R7UY15RSS,&bRM_5_,&fEM_A0UX15RSS,&fEM_B0UX05RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var9,&internal1_m880_Chim0};
_S_vchs  S_vchs_870_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var221,&fEM_R7UX14RSS,&fEM_R7UY14RSS,&bRM_4_,&fEM_A0UX14RSS,&fEM_B0UX04RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var10,&internal1_m870_Chim0};
_S_vchs  S_vchs_862_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var221,&fEM_R7UX13RSS,&fEM_R7UY13RSS,&bRM_2_,&fEM_A0UX13RSS,&fEM_B0UX03RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var11,&internal1_m862_Chim0};
_S_twobool  S_twobool_817_1 = {&var280,&iEM_TERR4VS22LDU,&var12,&vainSBool,&internal1_m817_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_816_1 = {&var279,&iEM_TERR4VS12LDU,&var13,&vainSBool,&internal1_m816_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_999_1 = {&var256,&iEM_TERR2VS22LIM,&var14,&vainSBool,&internal1_m999_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_998_1 = {&var255,&iEM_TERR2VS12LIM,&var15,&vainSBool,&internal1_m998_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_997_1 = {&var260,&iEM_TERR1VS22LIM,&var16,&vainSBool,&internal1_m997_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_996_1 = {&var259,&iEM_TERR1VS12LIM,&var17,&vainSBool,&internal1_m996_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_678_1 = {&var248,&iEM_TERB5VS22LIM,&var18,&vainSBool,&internal1_m678_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_677_1 = {&var247,&iEM_TERB5VS12LIM,&var19,&vainSBool,&internal1_m677_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_658_1 = {&var252,&iEM_TERA5VS22LIM,&var20,&vainSBool,&internal1_m658_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_657_1 = {&var251,&iEM_TERA5VS12LIM,&var21,&vainSBool,&internal1_m657_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_676_1 = {&var264,&iEM_TERB6VS22LIM,&var22,&vainSBool,&internal1_m676_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_675_1 = {&var263,&iEM_TERB6VS12LIM,&var23,&vainSBool,&internal1_m675_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_656_1 = {&var268,&iEM_TERA6VS22LIM,&var24,&vainSBool,&internal1_m656_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_655_1 = {&var267,&iEM_TERA6VS12LIM,&var25,&vainSBool,&internal1_m655_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_518_1 = {&var43,&iEM_TERA1VP81LIM,&var26,&vainSBool,&internal1_m518_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_534_1 = {&var43,&iEM_TERB1VP81LIM,&var27,&vainSBool,&internal1_m534_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_406_1 = {&var307,&iEM_TERB2SS33LIM,&var28,&vainSBool,&internal1_m406_Out10,&bFirstEnterFlag};
_S_noto  S_noto_481_1 = {&var186,&var29};
_S_noto  S_noto_482_1 = {&var185,&var30};
_S_noto  S_noto_472_1 = {&var187,&var31};
_S_noto  S_noto_474_1 = {&var188,&var32};
_S_rs  S_rs_479_1 = {&var30,&lEM_R5AD10LC1,&var33,&vainSBool,&internal1_m479_q0};
_S_rs  S_rs_480_1 = {&var29,&lEM_R5AD20LC1,&var34,&vainSBool,&internal1_m480_q0};
_S_rs  S_rs_467_1 = {&var31,&lEM_R3AD10LC1,&var35,&vainSBool,&internal1_m467_q0};
_S_rs  S_rs_468_1 = {&var32,&lEM_R3AD20LC1,&var36,&vainSBool,&internal1_m468_q0};
_S_andn  S_andn_355_1 = {array_m355_x_1,&iRM_16_,&vainSBool};
_S_zpfs  S_zpfs_626_1 = {&R0AD16LDU,&fEM_R7UI76RIM,&var37,&internal1_m626_tx,&internal1_m626_y0};
_S_zpfs  S_zpfs_613_1 = {&R0AD16LDU,&fEM_R7UI77RIM,&var38,&internal1_m613_tx,&internal1_m613_y0};
_S_bol  S_bol_940_1 = {&fEM_A4UP01RIM,&fEM_A4UP02RIM,&var39};
_S_bol  S_bol_937_1 = {&fEM_A3UP01RIM,&fEM_A3UP02RIM,&var40};
_S_bol  S_bol_916_1 = {&fEM_A0UP02RIM,&fEM_A0UP01RIM,&var41};
_S_bol  S_bol_938_1 = {&fEM_A2UP02RIM,&fEM_A2UP03RIM,&var42};
_S_bol  S_bol_928_1 = {&fEM_A1UP01RIM,&fEM_A1UP82RIM,&var43};
_S_ampl  S_ampl_369_1 = {&var272,&fRM_0_1,&var44};
_S_or2  S_or2_929_1 = {&R0EE04LZ1,&R0EE04LZ2,&var45};
_S_or2  S_or2_920_1 = {&R0EE03LZ1,&R0EE03LZ2,&var46};
_S_or2  S_or2_913_1 = {&R0EE02LZ1,&R0EE02LZ2,&var47};
_S_or2  S_or2_906_1 = {&R0EE01LZ1,&R0EE01LZ2,&var48};
_S_zpfs  S_zpfs_603_1 = {&var189,&fRM_1_0,&var49,&internal1_m603_tx,&internal1_m603_y0};
_S_zpfs  S_zpfs_601_1 = {&var192,&fRM_0_5,&var50,&internal1_m601_tx,&internal1_m601_y0};
_S_twobool  S_twobool_211_1 = {&B1AD21LDU,&iEM_TERB1IE04LDU,&var51,&vainSBool,&internal1_m211_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_228_1 = {&B1AD11LDU,&iEM_TERB1IE03LDU,&var52,&vainSBool,&internal1_m228_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_47_1 = {&A1AD21LDU,&iEM_TERA1IE04LDU,&var53,&vainSBool,&internal1_m47_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_62_1 = {&A1AD11LDU,&iEM_TERA1IE03LDU,&var54,&vainSBool,&internal1_m62_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_970_1 = {&var324,&iEM_TERB1SS12LIM,&var55,&vainSBool,&internal1_m970_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_967_1 = {&var320,&iEM_TERB1SS11LIM,&var56,&vainSBool,&internal1_m967_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_966_1 = {&var321,&iEM_TERB1SS21LIM,&var57,&vainSBool,&internal1_m966_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_969_1 = {&var59,&fEM_A1UC03RDU,&fRM_0_,&iRM_0_,&var58,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m969_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_964_1 = {&var224,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB1MC01RIM,&var59,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_952_1 = {&var61,&fEM_A1UC03RDU,&fRM_0_,&iRM_0_,&var60,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m952_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_945_1 = {&var225,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA1SC01RIM,&var61,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_953_1 = {&var331,&iEM_TERA1SS12LIM,&var62,&vainSBool,&internal1_m953_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_950_1 = {&var328,&iEM_TERA1SS11LIM,&var63,&vainSBool,&internal1_m950_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_949_1 = {&var329,&iEM_TERA1SS21LIM,&var64,&vainSBool,&internal1_m949_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1037_1 = {&var262,&iEM_TERB6SS21LIM,&var65,&vainSBool,&internal1_m1037_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1018_1 = {&var261,&iEM_TERB6SS11LIM,&var66,&vainSBool,&internal1_m1018_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1017_1 = {&var266,&iEM_TERA6SS21LIM,&var67,&vainSBool,&internal1_m1017_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1016_1 = {&var265,&iEM_TERA6MS11LIM,&var68,&vainSBool,&internal1_m1016_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_838_1 = {&var271,&iEM_TERA8SS12LIM,&var69,&vainSBool,&internal1_m838_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_840_1 = {&var270,&iEM_TERA8SS22LIM,&var70,&vainSBool,&internal1_m840_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_837_1 = {&var274,&iEM_TERB8SS12LIM,&var71,&var72,&internal1_m837_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_839_1 = {&var273,&iEM_TERB8SS22LIM,&var73,&var74,&internal1_m839_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_813_1 = {&var275,&iEM_TERR4SS12LIM,&var75,&vainSBool,&internal1_m813_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_814_1 = {&var276,&iEM_TERR4SS22LIM,&var76,&vainSBool,&internal1_m814_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_812_1 = {&var278,&iEM_TERR4MS21LIM,&var77,&vainSBool,&internal1_m812_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_811_1 = {&var277,&iEM_TERR4SS11LIM,&var78,&vainSBool,&internal1_m811_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1032_1 = {&var39,&iEM_TERA4VP82LIM,&var79,&var80,&internal1_m1032_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_984_1 = {&var254,&iEM_TERR2SS21LIM,&var81,&vainSBool,&internal1_m984_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_983_1 = {&var253,&iEM_TERR2SS11LIM,&var82,&vainSBool,&internal1_m983_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_982_1 = {&var258,&iEM_TERR1SS21LIM,&var83,&vainSBool,&internal1_m982_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_981_1 = {&var257,&iEM_TERR1SS11LIM,&var84,&vainSBool,&internal1_m981_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1033_1 = {&var194,&iEM_TERB4SS21LIM,&var85,&vainSBool,&internal1_m1033_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1014_1 = {&var193,&iEM_TERB4SS11LIM,&var86,&vainSBool,&internal1_m1014_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_815_1 = {&lEM_R8AD10LC1,&iEM_TERR8SS11LIM,&var87,&vainSBool,&internal1_m815_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1015_1 = {&var191,&iEM_TERA4SS21LIM,&var88,&vainSBool,&internal1_m1015_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1013_1 = {&var190,&iEM_TERA4SS11LIM,&var89,&vainSBool,&internal1_m1013_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1034_1 = {&var186,&iEM_TERR5SS21LIM,&var90,&vainSBool,&internal1_m1034_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1012_1 = {&var185,&iEM_TERR5SS11LIM,&var91,&vainSBool,&internal1_m1012_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_995_1 = {&var188,&iEM_TERR3SS21LIM,&var92,&vainSBool,&internal1_m995_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_980_1 = {&var187,&iEM_TERR3SS11LIM,&var93,&vainSBool,&internal1_m980_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_535_1 = {&var42,&iEM_TERA2VP82LIM,&var94,&var95,&internal1_m535_Out10,&bFirstEnterFlag};
_S_toao  S_toao_539_1 = {&var99,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16000_,&iRM_0_,&iRM_3276_,&iRM_16000_,&fRM_1_,&var96,&bFirstEnterFlag};
_S_toao  S_toao_538_1 = {&var98,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16000_,&iRM_0_,&iRM_3276_,&iRM_16000_,&fRM_1_,&var97,&bFirstEnterFlag};
_S_to3val  S_to3val_532_1 = {&var155,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A2UP03RDU,&fEM_A2UP03RDU,&iEM_TERB2SP01RIM,&var98,&vainSFloat,&var99,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_416_1 = {&var101,&fEM_A2UC03RDU,&fRM_0_,&iRM_0_,&var100,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m416_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_410_1 = {&var223,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB2SC01RIM,&var101,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_407_1 = {&var309,&iEM_TERB2SS12LIM,&var102,&vainSBool,&internal1_m407_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_409_1 = {&var304,&iEM_TERB2SS11LIM,&var103,&vainSBool,&internal1_m409_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_408_1 = {&var305,&iEM_TERB2SS21LIM,&var104,&vainSBool,&internal1_m408_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_853_1 = {&var200,&iEM_TERB9SS21LIM,&var105,&vainSBool,&internal1_m853_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_854_1 = {&var199,&iEM_TERB9SS11LIM,&var106,&vainSBool,&internal1_m854_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_852_1 = {&var197,&iEM_TERA9SS21LIM,&var107,&vainSBool,&internal1_m852_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1036_1 = {&var196,&iEM_TERA9SS11LIM,&var108,&vainSBool,&internal1_m1036_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_689_1 = {&var246,&iEM_TERB5SS21LIM,&var109,&vainSBool,&internal1_m689_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_690_1 = {&var245,&iEM_TERB5SS11LIM,&var110,&vainSBool,&internal1_m690_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_687_1 = {&var250,&iEM_TERA5SS21LIM,&var111,&vainSBool,&internal1_m687_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_688_1 = {&var249,&iEM_TERA5SS11LIM,&var112,&vainSBool,&internal1_m688_Out10,&bFirstEnterFlag};
_S_ampl  S_ampl_644_1 = {&var229,&fEM_R7UI75RIM,&var113};
_S_to3val  S_to3val_645_1 = {&var113,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R7UI74RIM,&fEM_R7UI74RIM,&iEM_TERR7SI74RIM,&vainSFloat,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_551_1 = {&var41,&iEM_TERB0VP81LIM,&var114,&vainSBool,&internal1_m551_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_550_1 = {&var41,&iEM_TERA0VP81LIM,&var115,&vainSBool,&internal1_m550_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_834_1 = {&var117,&fEM_A8UC03RDU,&fRM_0_,&iRM_0_,&var116,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m834_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_826_1 = {&var272,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB8SC01RIM,&var117,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_836_1 = {&var119,&fEM_A8UC03RDU,&fRM_0_,&iRM_0_,&var118,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m836_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_828_1 = {&var269,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA8SC01RIM,&var119,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_654_1 = {&R0MW13LP2,&iEM_TERR6IS66LIM,&var120,&var121,&internal1_m654_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_673_1 = {&R0MW13LP2,&iEM_TERR6IS64LIM,&var122,&var123,&internal1_m673_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_653_1 = {&R0MW13LP2,&iEM_TERR6IS62LIM,&var124,&var125,&internal1_m653_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_337_1 = {&var290,&iEM_TERB3SS22LIM,&var126,&vainSBool,&internal1_m337_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_336_1 = {&var297,&iEM_TERA3SS22LIM,&var127,&vainSBool,&internal1_m336_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_321_1 = {&var291,&iEM_TERB3SS11LIM,&var128,&vainSBool,&internal1_m321_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_320_1 = {&var298,&iEM_TERA3SS11LIM,&var129,&vainSBool,&internal1_m320_Out10,&bFirstEnterFlag};
_S_toao  S_toao_517_1 = {&var131,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&fRM_3276_,&fRM_16000_,&iRM_0_,&iRM_3276_,&iRM_16000_,&fRM_1_,&var130,&bFirstEnterFlag};
_S_to3val  S_to3val_506_1 = {&var177,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A3UP03RDU,&fEM_A3UP03RDU,&iEM_TERA3SP02RIM,&vainSFloat,&var131,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_552_1 = {&var40,&iEM_TERA3VP81LIM,&var132,&var133,&internal1_m552_Out10,&bFirstEnterFlag};
_S_toao  S_toao_515_1 = {&var135,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&fRM_3276_,&fRM_16000_,&iRM_0_,&iRM_3276_,&iRM_16000_,&fRM_1_,&var134,&bFirstEnterFlag};
_S_to3val  S_to3val_509_1 = {&var175,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A3UP03RDU,&fEM_A3UP03RDU,&iEM_TERB3SP02RIM,&vainSFloat,&var135,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_350_1 = {&var294,&iEM_TERB3SS33LIM,&var136,&vainSBool,&internal1_m350_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_334_1 = {&var138,&fEM_A3UC03RDU,&fRM_0_,&iRM_0_,&var137,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m334_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_333_1 = {&var289,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB3SC01RIM,&var138,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_349_1 = {&var293,&iEM_TERB3SS31LIM,&var139,&vainSBool,&internal1_m349_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_347_1 = {&var301,&iEM_TERA3SS33LIM,&var140,&vainSBool,&internal1_m347_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_324_1 = {&var142,&fEM_A3UC03RDU,&fRM_0_,&iRM_0_,&var141,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m324_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_323_1 = {&var296,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA3SC01RIM,&var142,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_348_1 = {&var300,&iEM_TERA3SS31LIM,&var143,&vainSBool,&internal1_m348_Out10,&bFirstEnterFlag};
_S_toao  S_toao_537_1 = {&var156,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16000_,&iRM_0_,&iRM_3276_,&iRM_16000_,&fRM_1_,&var144,&bFirstEnterFlag};
_S_toao  S_toao_536_1 = {&var154,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16000_,&iRM_0_,&iRM_3276_,&iRM_16000_,&fRM_1_,&var145,&bFirstEnterFlag};
_S_twobool  S_twobool_319_1 = {&var292,&iEM_TERB3SS21LIM,&var146,&vainSBool,&internal1_m319_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_335_1 = {&var299,&iEM_TERA3SS21LIM,&var147,&vainSBool,&internal1_m335_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_428_1 = {&var315,&iEM_TERA2SS33LIM,&var148,&vainSBool,&internal1_m428_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_429_1 = {&var150,&fEM_A2UC03RDU,&fRM_0_,&iRM_0_,&var149,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m429_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_424_1 = {&var222,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA2SC01RIM,&var150,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_427_1 = {&var317,&iEM_TERA2SS12LIM,&var151,&vainSBool,&internal1_m427_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_426_1 = {&var312,&iEM_TERA2SS11LIM,&var152,&vainSBool,&internal1_m426_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_425_1 = {&var313,&iEM_TERA2SS21LIM,&var153,&vainSBool,&internal1_m425_Out10,&bFirstEnterFlag};
_S_to3val  S_to3val_531_1 = {&fEM_A2UP01RIM,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A2UP03RDU,&fEM_A2UP03RDU,&iEM_TERA2SP01RIM,&var154,&var155,&var156,&bFirstEnterFlag};
_S_toao  S_toao_166_1 = {&var162,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16000_,&iRM_0_,&iRM_3276_,&iRM_16000_,&fRM_1_,&var157,&bFirstEnterFlag};
_S_toao  S_toao_165_1 = {&var161,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16000_,&iRM_0_,&iRM_3276_,&iRM_16000_,&fRM_1_,&var158,&bFirstEnterFlag};
_S_toao  S_toao_164_1 = {&var160,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16000_,&iRM_0_,&iRM_3276_,&iRM_16000_,&fRM_1_,&var159,&bFirstEnterFlag};
_S_to3val  S_to3val_159_1 = {&var284,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R0UT02RDU,&fEM_R0UT02RDU,&iEM_TERB0MT01RIM,&var160,&var161,&var162,&bFirstEnterFlag};
_S_toao  S_toao_169_1 = {&var170,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16000_,&iRM_0_,&iRM_3276_,&iRM_16000_,&fRM_1_,&var163,&bFirstEnterFlag};
_S_toao  S_toao_168_1 = {&var169,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16000_,&iRM_0_,&iRM_3276_,&iRM_16000_,&fRM_1_,&var164,&bFirstEnterFlag};
_S_twobool  S_twobool_1035_1 = {&var184,&iEM_TERR6SS21LIM,&var165,&vainSBool,&internal1_m1035_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_152_1 = {&var285,&iEM_TERB7MS31LIM,&var166,&vainSBool,&internal1_m152_Out10,&bFirstEnterFlag};
_S_toao  S_toao_167_1 = {&var168,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16000_,&iRM_0_,&iRM_3276_,&iRM_16000_,&fRM_1_,&var167,&bFirstEnterFlag};
_S_to3val  S_to3val_161_1 = {&var335,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R0UT02RDU,&fEM_R0UT02RDU,&iEM_TERA0MT01RIM,&var168,&var169,&var170,&bFirstEnterFlag};
_S_twobool  S_twobool_151_1 = {&var336,&iEM_TERA7MS31LIM,&var171,&vainSBool,&internal1_m151_Out10,&bFirstEnterFlag};
_S_orn  S_orn_905_1 = {array_m905_x_1,&iRM_2_,&var172};
_S_andn  S_andn_900_1 = {array_m900_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_904_1 = {&var172,&var173};
_S_noto  S_noto_504_1 = {&B3AD34LDU,&var174};
_S_lk  S_lk_508_1 = {&fEM_A3UP02RDU,&var174,&var175};
_S_noto  S_noto_502_1 = {&A3AD34LDU,&var176};
_S_lk  S_lk_507_1 = {&fEM_A3UP02RDU,&var176,&var177};
_S_andn  S_andn_925_1 = {array_m925_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_930_1 = {&var45,&var178};
_S_andn  S_andn_918_1 = {array_m918_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_921_1 = {&var46,&var179};
_S_andn  S_andn_910_1 = {array_m910_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_914_1 = {&var47,&var180};
_S_orn  S_orn_612_1 = {array_m612_x_1,&iRM_2_,&var181};
_S_react  S_react_204_1 = {&var286,&var182};
_S_noto  S_noto_469_1 = {&lEM_R6AD10LC1,&var183};
_S_asmot  S_asmot_471_1 = {&var183,&lEM_R6AD10LC1,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R6UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R6UC01RSP,&vainSFloat,&var184,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m471_X00,&internal1_m471_V00,&internal1_m471_Pav0,&internal1_m471_Zav0,&internal1_m471_Pv0,&internal1_m471_Zv0,&internal1_m471_RA00,&internal1_m471_RA10,&internal1_m471_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_483_1 = {&var33,&var34,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R5UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R5UC01RSP,&vainSFloat,&var185,&var186,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m483_X00,&internal1_m483_V00,&internal1_m483_Pav0,&internal1_m483_Zav0,&internal1_m483_Pv0,&internal1_m483_Zv0,&internal1_m483_RA00,&internal1_m483_RA10,&internal1_m483_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_473_1 = {&var35,&var36,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R3UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R3UC01RSP,&vainSFloat,&var187,&var188,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m473_X00,&internal1_m473_V00,&internal1_m473_Pav0,&internal1_m473_Zav0,&internal1_m473_Pv0,&internal1_m473_Zv0,&internal1_m473_RA00,&internal1_m473_RA10,&internal1_m473_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_602_1 = {&A4AD10LDU,&var189};
_S_asmot  S_asmot_606_1 = {&var189,&A4AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,&fEM_A4UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_A4MC01RSP,&vainSFloat,&var190,&var191,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m606_X00,&internal1_m606_V00,&internal1_m606_Pav0,&internal1_m606_Zav0,&internal1_m606_Pv0,&internal1_m606_Zv0,&internal1_m606_RA00,&internal1_m606_RA10,&internal1_m606_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_600_1 = {&B4AD10LDU,&var192};
_S_asmot  S_asmot_605_1 = {&var192,&B4AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_A4UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_B4MC01RSP,&vainSFloat,&var193,&var194,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m605_X00,&internal1_m605_V00,&internal1_m605_Pav0,&internal1_m605_Zav0,&internal1_m605_Pv0,&internal1_m605_Zv0,&internal1_m605_RA00,&internal1_m605_RA10,&internal1_m605_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_591_1 = {&A9AD10LDU,&var195};
_S_asmot  S_asmot_593_1 = {&var195,&A9AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,&fEM_A9UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_A9MC01RSP,&vainSFloat,&var196,&var197,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m593_X00,&internal1_m593_V00,&internal1_m593_Pav0,&internal1_m593_Zav0,&internal1_m593_Pv0,&internal1_m593_Zv0,&internal1_m593_RA00,&internal1_m593_RA10,&internal1_m593_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_590_1 = {&B9AD10LDU,&var198};
_S_asmot  S_asmot_592_1 = {&var198,&B9AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_A9UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_B9MC01RSP,&vainSFloat,&var199,&var200,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m592_X00,&internal1_m592_V00,&internal1_m592_Pav0,&internal1_m592_Zav0,&internal1_m592_Pv0,&internal1_m592_Zv0,&internal1_m592_RA00,&internal1_m592_RA10,&internal1_m592_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orn  S_orn_623_1 = {array_m623_x_1,&iRM_3_,&var201};
_S_andn  S_andn_902_1 = {array_m902_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_907_1 = {&var48,&var202};
_S_andn  S_andn_292_1 = {array_m292_x_1,&iRM_2_,&var203};
_S_andn  S_andn_258_1 = {array_m258_x_1,&iRM_3_,&var204};
_S_noto  S_noto_257_1 = {&C2MD31LP1,&var205};
_S_andn  S_andn_259_1 = {array_m259_x_1,&iRM_3_,&var206};
_S_noto  S_noto_219_1 = {&C1MD31LP2,&var207};
_S_noto  S_noto_218_1 = {&C1MD31LP1,&var208};
_S_andn  S_andn_221_1 = {array_m221_x_1,&iRM_4_,&var209};
_S_andn  S_andn_220_1 = {array_m220_x_1,&iRM_4_,&var210};
_S_andn  S_andn_124_1 = {array_m124_x_1,&iRM_2_,&var211};
_S_noto  S_noto_52_1 = {&C1MD31LP2,&var212};
_S_noto  S_noto_51_1 = {&C1MD31LP1,&var213};
_S_andn  S_andn_54_1 = {array_m54_x_1,&iRM_4_,&var214};
_S_andn  S_andn_53_1 = {array_m53_x_1,&iRM_4_,&var215};
_S_andn  S_andn_91_1 = {array_m91_x_1,&iRM_3_,&var216};
_S_noto  S_noto_90_1 = {&C2MD31LP1,&var217};
_S_andn  S_andn_92_1 = {array_m92_x_1,&iRM_3_,&var218};
_S_noto  S_noto_622_1 = {&var201,&var219};
_S_orn  S_orn_631_1 = {array_m631_x_1,&iRM_2_,&var220};
_S_fsubo  S_fsubo_371_1 = {&fEM_R7UY00RSS,&var44,&var221};
_S_fsubo  S_fsubo_118_1 = {&fEM_A2UC05RIM,&var311,&var222};
_S_fsubo  S_fsubo_285_1 = {&fEM_A2UC05RIM,&var303,&var223};
_S_fsubo  S_fsubo_247_1 = {&fEM_A1UC05RIM,&var319,&var224};
_S_fsubo  S_fsubo_80_1 = {&fEM_A1UC05RIM,&var326,&var225};
_S_fsubo  S_fsubo_8_1 = {&var227,&fEM_R0UR01RIM,&var226};
_S_inf  S_inf_7_1 = {&var272,array_m7_a_1,array_m7_b_1,&iRM_5_,&var227,&vainSInt};
_S_inf  S_inf_9_1 = {&var272,array_m9_a_1,array_m9_b_1,&iRM_7_,&var228,&vainSInt};
_S_mod1  S_mod1_637_1 = {&var287,&fEM_R7UI02RIM,&fEM_R7UL01RIM,&var229,&internal1_m637_y0};
_S_bol  S_bol_630_1 = {&var287,&fEM_R7UI73RIM,&var230};
_S_bol  S_bol_611_1 = {&var287,&fEM_R7UI71RIM,&var231};
_S_vchs  S_vchs_799_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var221,&fEM_R7UX12RSS,&fEM_R7UY12RSS,&bRM_5_,&fEM_A0UX12RSS,&fEM_B0UX12RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var232,&internal1_m799_Chim0};
_S_vchs  S_vchs_790_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var221,&fEM_R7UX11RSS,&fEM_R7UY11RSS,&bRM_4_,&fEM_A0UX11RSS,&fEM_B0UX11RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var233,&internal1_m790_Chim0};
_S_vchs  S_vchs_782_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var221,&fEM_R7UX10RSS,&fEM_R7UY10RSS,&bRM_1_,&fEM_A0UX10RSS,&fEM_B0UX10RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var234,&internal1_m782_Chim0};
_S_vchs  S_vchs_773_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var221,&fEM_R7UX09RSS,&fEM_R7UY09RSS,&bRM_5_,&fEM_A0UX09RSS,&fEM_B0UX09RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var235,&internal1_m773_Chim0};
_S_vchs  S_vchs_764_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var221,&fEM_R7UX08RSS,&fEM_R7UY08RSS,&bRM_4_,&fEM_A0UX08RSS,&fEM_B0UX08RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var236,&internal1_m764_Chim0};
_S_vchs  S_vchs_756_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var221,&fEM_R7UX07RSS,&fEM_R7UY07RSS,&bRM_1_,&fEM_A0UX07RSS,&fEM_B0UX07RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var237,&internal1_m756_Chim0};
_S_vchs  S_vchs_747_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var221,&fEM_R7UX06RSS,&fEM_R7UY06RSS,&bRM_5_,&fEM_A0UX06RSS,&fEM_B0UX06RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var238,&internal1_m747_Chim0};
_S_vchs  S_vchs_738_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var221,&fEM_R7UX05RSS,&fEM_R7UY05RSS,&bRM_4_,&fEM_A0UX05RSS,&fEM_B0UX05RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var239,&internal1_m738_Chim0};
_S_vchs  S_vchs_730_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var221,&fEM_R7UX04RSS,&fEM_R7UY04RSS,&bRM_2_,&fEM_A0UX04RSS,&fEM_B0UX04RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var240,&internal1_m730_Chim0};
_S_vchs  S_vchs_721_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var221,&fEM_R7UC10RIM,&fEM_R7UC19RIM,&bRM_5_,&fEM_A0UX03RSS,&fEM_B0UX03RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var241,&internal1_m721_Chim0};
_S_vchs  S_vchs_712_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var221,&fEM_R7UX02RSS,&fEM_R7UY02RSS,&bRM_4_,&fEM_A0UX02RSS,&fEM_B0UX02RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var242,&internal1_m712_Chim0};
_S_fsumo  S_fsumo_896_1 = {&fEM_R4UC10RIM,&fEM_R4UC22RIM,&var243};
_S_vchs  S_vchs_702_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var221,&fEM_R7UX01RSS,&fEM_R7UY01RSS,&bRM_2_,&fEM_A0UX01RSS,&fEM_B0UX01RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var244,&internal1_m702_Chim0};
_S_asmot  S_asmot_580_1 = {&B5AD10LDU,&B5AD20LDU,&fEM_B5MC01RC1,&fEM_B5MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERNL2,&fEM_A5UC10RIM,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,&fEM_B5MC01RSP,&vainSFloat,&var245,&var246,&vainSBool,&vainSBool,&vainSFloat,&var247,&var248,&internal1_m580_X00,&internal1_m580_V00,&internal1_m580_Pav0,&internal1_m580_Zav0,&internal1_m580_Pv0,&internal1_m580_Zv0,&internal1_m580_RA00,&internal1_m580_RA10,&internal1_m580_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_566_1 = {&A5AD10LDU,&A5AD20LDU,&fEM_A5MC01RC1,&fEM_A5MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERNL1,&fEM_A5UC10RIM,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,&fEM_A5MC01RSP,&vainSFloat,&var249,&var250,&vainSBool,&vainSBool,&vainSFloat,&var251,&var252,&internal1_m566_X00,&internal1_m566_V00,&internal1_m566_Pav0,&internal1_m566_Zav0,&internal1_m566_Pv0,&internal1_m566_Zv0,&internal1_m566_RA00,&internal1_m566_RA10,&internal1_m566_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_457_1 = {&R2AD10LDU,&R2AD20LDU,&fEM_R2MC01RC1,&fEM_R2MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERMDZ2,&fEM_R1UC10RIM,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,&fEM_R2MC01RSP,&vainSFloat,&var253,&var254,&vainSBool,&vainSBool,&vainSFloat,&var255,&var256,&internal1_m457_X00,&internal1_m457_V00,&internal1_m457_Pav0,&internal1_m457_Zav0,&internal1_m457_Pv0,&internal1_m457_Zv0,&internal1_m457_RA00,&internal1_m457_RA10,&internal1_m457_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_443_1 = {&R1AD10LDU,&R1AD20LDU,&fEM_R1MC01RC1,&fEM_R1MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERMDZ1,&fEM_R1UC10RIM,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,&fEM_R1MC01RSP,&vainSFloat,&var257,&var258,&vainSBool,&vainSBool,&vainSFloat,&var259,&var260,&internal1_m443_X00,&internal1_m443_V00,&internal1_m443_Pav0,&internal1_m443_Zav0,&internal1_m443_Pv0,&internal1_m443_Zv0,&internal1_m443_RA00,&internal1_m443_RA10,&internal1_m443_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_494_1 = {&B6AD10LDU,&B6AD20LDU,&fEM_B6MC01RC1,&fEM_B6MV01RC1,&fRM_1_0,&fEM_A6US80RDU,&iEM_TERBZ2,&fEM_A6UC10RIM,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,&fEM_B6MC01RSP,&vainSFloat,&var261,&var262,&vainSBool,&vainSBool,&vainSFloat,&var263,&var264,&internal1_m494_X00,&internal1_m494_V00,&internal1_m494_Pav0,&internal1_m494_Zav0,&internal1_m494_Pv0,&internal1_m494_Zv0,&internal1_m494_RA00,&internal1_m494_RA10,&internal1_m494_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_395_1 = {&A6AD10LDU,&A6AD20LDU,&fEM_A6MC01RC1,&fEM_A6MV01RC1,&fRM_1_0,&fEM_A6US80RDU,&iEM_TERBZ1,&fEM_A6UC10RIM,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,&fEM_A6MC01RSP,&vainSFloat,&var265,&var266,&vainSBool,&vainSBool,&vainSFloat,&var267,&var268,&internal1_m395_X00,&internal1_m395_V00,&internal1_m395_Pav0,&internal1_m395_Zav0,&internal1_m395_Pv0,&internal1_m395_Zv0,&internal1_m395_RA00,&internal1_m395_RA10,&internal1_m395_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_380_1 = {&A8AD20LDU,&A8AD10LDU,&fEM_A8MC01RC1,&fEM_A8MV01RC1,&fEM_A8UV80RDU,&fEM_A8US80RDU,&iEM_TERDS2,&fEM_A8UC10RIM,&fEM_A8UC20RIM,&fEM_A8UC11RIM,&fEM_A8UC21RIM,&fEM_A8UC08RDU,&fEM_A8MC01RSP,&var269,&var270,&var271,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m380_X00,&internal1_m380_V00,&internal1_m380_Pav0,&internal1_m380_Zav0,&internal1_m380_Pv0,&internal1_m380_Zv0,&internal1_m380_RA00,&internal1_m380_RA10,&internal1_m380_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_364_1 = {&B8AD20LDU,&B8AD10LDU,&fEM_B8MC01RC1,&fEM_B8MV01RC1,&fEM_B8UV80RDU,&fEM_B8US80RDU,&iEM_TERMAZ2,&fEM_B8UC10RIM,&fEM_B8UC20RIM,&fEM_B8UC11RIM,&fEM_B8UC21RIM,&fEM_B8UC08RDU,&fEM_B8MC01RSP,&var272,&var273,&var274,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m364_X00,&internal1_m364_V00,&internal1_m364_Pav0,&internal1_m364_Zav0,&internal1_m364_Pv0,&internal1_m364_Zv0,&internal1_m364_RA00,&internal1_m364_RA10,&internal1_m364_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_892_1 = {&R4AD10LDU,&R4AD20LDU,&fEM_R4MC01RC1,&fEM_R4MV01RC1,&fEM_R4UV80RDU,&fEM_R4US80RDU,&iEM_TERTLG,&fEM_R4UC10RIM,&fEM_R4UC20RIM,&fEM_R4UC10RIM,&fEM_R4UC20RIM,&fEM_R4UC08RDU,&fEM_R4MC01RSP,&vainSFloat,&var275,&var276,&var277,&var278,&vainSFloat,&var279,&var280,&internal1_m892_X00,&internal1_m892_V00,&internal1_m892_Pav0,&internal1_m892_Zav0,&internal1_m892_Pv0,&internal1_m892_Zv0,&internal1_m892_RA00,&internal1_m892_RA10,&internal1_m892_MyFirstEnterFlag,&bFirstEnterFlag};
_S_azbars  S_azbars_186_1 = {&var318,&var302,&var288,&var3,&fEM_R0UR30RIM,&B7AP31LDU,&var193,&lEM_R8AD10LC1,&var4,&fEM_R0UL01RIM,&fEM_R0UN02RIM,&fEM_A0UN07RIM,&fEM_R0UN18RDU,&fEM_R0UT02RIM,&fEM_R0UT04RIM,&fEM_R0UT05RIM,&fEM_R0UH05RSS,&fEM_A0UN02RIM,&fEM_A0UN01RIM,&fEM_A1UR00RIM,&fEM_A1UR01RIM,&fEM_A2UR00RIM,&fEM_A2UR01RIM,&fEM_A3UR00RIM,&fEM_A3UR01RIM,&var226,&var228,&fEM_R0UT03RIM,&fEM_R0UT06RIM,&fEM_A0UR02RSP,&fEM_A0UR01RSP,&fEM_B0UT03RSP,&var281,&var282,&var283,&var284,&var285,&var286,&var287,&internal1_m186_C1,&internal1_m186_C2,&internal1_m186_C3,&internal1_m186_C4,&internal1_m186_C5,&internal1_m186_C6,&internal1_m186_N20,&internal1_m186_N00,&internal1_m186_R00,&internal1_m186_T00,&internal1_m186_ImpINI0,&internal1_m186_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_300_1 = {&B3AD11LDU,&B3AD21LDU,&B3AD02LDU,&B3AD01LDU,&B3AD03LDU,&B3AD04LDU,&B3AD05LDU,&var203,&B3AD33LDU,&lRM_1_,&fEM_B3MC01RC1,&fEM_B3MC02RC1,&fEM_B3MV01RC1,&fEM_B3MV02RC1,&lRM_0_,array_m300_Vr_1,&fEM_A3UC02RDU,&var175,&fEM_A3UP01RIM,&fEM_A3UG01RDU,&fEM_A3US07RDU,&fEM_A3UV02RIM,&iEM_TERIS2,&fEM_A3UC04RIM,&fEM_A3UC05RIM,&fEM_A3UC06RIM,&fEM_A3UC08RIM,&fEM_B3MC01RSP,&fEM_B3MC02RSP,&var288,&var289,&var290,&var291,&var292,&vainSFloat,&vainSFloat,&var293,&var294,&vainSBool,&vainSBool,&internal1_m300_X00,&internal1_m300_Sh00,&internal1_m300_RV00,&internal1_m300_ShV00,&internal1_m300_Ppv0,&internal1_m300_Pav0,&internal1_m300_Zav0,&internal1_m300_RA00,&internal1_m300_RA10,&internal1_m300_RA30,&internal1_m300_RA50,&internal1_m300_fls,&internal1_m300_flp,&internal1_m300_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_134_1 = {&A3AD11LDU,&A3AD21LDU,&A3AD02LDU,&A3AD01LDU,&A3AD03LDU,&A3AD04LDU,&A3AD05LDU,&var211,&A3AD33LDU,&lRM_1_,&fEM_A3MC01RC1,&fEM_A3MC02RC1,&fEM_A3MV01RC1,&fEM_A3MV02RC1,&lRM_0_,array_m134_Vr_1,&fEM_A3UC02RDU,&var177,&fEM_A3UP01RIM,&fEM_A3UG01RDU,&fEM_A3US07RDU,&fEM_A3UV02RIM,&iEM_TERIS1,&fEM_A3UC04RIM,&fEM_A3UC05RIM,&fEM_A3UC06RIM,&fEM_A3UC08RIM,&fEM_A3MC01RSP,&fEM_A3MC02RSP,&var295,&var296,&var297,&var298,&var299,&vainSFloat,&vainSFloat,&var300,&var301,&vainSBool,&vainSBool,&internal1_m134_X00,&internal1_m134_Sh00,&internal1_m134_RV00,&internal1_m134_ShV00,&internal1_m134_Ppv0,&internal1_m134_Pav0,&internal1_m134_Zav0,&internal1_m134_RA00,&internal1_m134_RA10,&internal1_m134_RA30,&internal1_m134_RA50,&internal1_m134_fls,&internal1_m134_flp,&internal1_m134_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_267_1 = {&B2AD11LDU,&B2AD21LDU,&B2AD02LDU,&B2AD01LDU,&B2AD03LDU,&B2AD04LDU,&B2AD05LDU,&var204,&B2AD33LDU,&var206,&fEM_B2MC01RC1,&fEM_B2MC02RC1,&fEM_B2MV01RC1,&fEM_B2MV02RC1,&lRM_1_,array_m267_Vr_1,&fEM_A2UC02RDU,&fEM_A2UP02RIM,&fEM_A2UP01RIM,&fEM_A2UG01RDU,&fEM_A2US07RDU,&fEM_A2UV02RIM,&iEM_TERRB2,&fEM_A2UC04RIM,&fEM_A2UC05RIM,&fEM_A2UC06RIM,&fEM_A2UC08RIM,&fEM_B2MC01RSP,&fEM_B2MC02RSP,&var302,&var303,&vainSBool,&var304,&var305,&vainSFloat,&vainSFloat,&var306,&var307,&var308,&var309,&internal1_m267_X00,&internal1_m267_Sh00,&internal1_m267_RV00,&internal1_m267_ShV00,&internal1_m267_Ppv0,&internal1_m267_Pav0,&internal1_m267_Zav0,&internal1_m267_RA00,&internal1_m267_RA10,&internal1_m267_RA30,&internal1_m267_RA50,&internal1_m267_fls,&internal1_m267_flp,&internal1_m267_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_103_1 = {&A2AD11LDU,&A2AD21LDU,&A2AD02LDU,&A2AD01LDU,&A2AD03LDU,&A2AD04LDU,&A2AD05LDU,&var216,&A2AD33LDU,&var218,&fEM_A2MC01RC1,&fEM_A2MC02RC1,&fEM_A2MV01RC1,&fEM_A2MV02RC1,&lRM_1_,array_m103_Vr_1,&fEM_A2UC02RDU,&fEM_A2UP02RIM,&fEM_A2UP01RIM,&fEM_A2UG01RDU,&fEM_A2US07RDU,&fEM_A2UV02RIM,&iEM_TERRB1,&fEM_A2UC04RIM,&fEM_A2UC05RIM,&fEM_A2UC06RIM,&fEM_A2UC08RIM,&fEM_A2MC01RSP,&fEM_A2MC02RSP,&var310,&var311,&vainSBool,&var312,&var313,&vainSFloat,&vainSFloat,&var314,&var315,&var316,&var317,&internal1_m103_X00,&internal1_m103_Sh00,&internal1_m103_RV00,&internal1_m103_ShV00,&internal1_m103_Ppv0,&internal1_m103_Pav0,&internal1_m103_Zav0,&internal1_m103_RA00,&internal1_m103_RA10,&internal1_m103_RA30,&internal1_m103_RA50,&internal1_m103_fls,&internal1_m103_flp,&internal1_m103_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_232_1 = {&B1AD11LDU,&B1AD21LDU,&B1AD02LDU,&B1AD01LDU,&B1AD03LDU,&B1AD04LDU,&B1AD05LDU,&var210,&lRM_1_,&var209,&fEM_B1MC01RC1,&fEM_B1MC02RC1,&fEM_B1MV01RC1,&fEM_B1MV02RC1,&lRM_1_,array_m232_Vr_1,&fEM_A1UC02RDU,&fRM_0_,&fEM_A1UP01RIM,&fEM_A1UG01RDU,&fEM_A1US07RDU,&fEM_A1UV02RIM,&iEM_TERBB2,&fEM_A1UC04RIM,&fEM_A1UC05RIM,&fEM_A1UC06RIM,&fEM_A1UC08RIM,&fEM_B1MC01RSP,&fEM_B1MC02RSP,&var318,&var319,&vainSBool,&var320,&var321,&vainSFloat,&vainSFloat,&var322,&vainSBool,&var323,&var324,&internal1_m232_X00,&internal1_m232_Sh00,&internal1_m232_RV00,&internal1_m232_ShV00,&internal1_m232_Ppv0,&internal1_m232_Pav0,&internal1_m232_Zav0,&internal1_m232_RA00,&internal1_m232_RA10,&internal1_m232_RA30,&internal1_m232_RA50,&internal1_m232_fls,&internal1_m232_flp,&internal1_m232_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_66_1 = {&A1AD11LDU,&A1AD21LDU,&A1AD02LDU,&A1AD01LDU,&A1AD03LDU,&A1AD04LDU,&A1AD05LDU,&var215,&lRM_1_,&var214,&fEM_A1MC01RC1,&fEM_A1MC02RC1,&fEM_A1MV01RC1,&fEM_A1MV02RC1,&lRM_1_,array_m66_Vr_1,&fEM_A1UC02RDU,&fRM_0_,&fEM_A1UP01RIM,&fEM_A1UG01RDU,&fEM_A1US07RDU,&fEM_A1UV02RIM,&iEM_TERBB1,&fEM_A1UC04RIM,&fEM_A1UC05RIM,&fEM_A1UC06RIM,&fEM_A1UC08RIM,&fEM_A1MC01RSP,&fEM_A1MC02RSP,&var325,&var326,&var327,&var328,&var329,&vainSFloat,&vainSFloat,&vainSBool,&vainSBool,&var330,&var331,&internal1_m66_X00,&internal1_m66_Sh00,&internal1_m66_RV00,&internal1_m66_ShV00,&internal1_m66_Ppv0,&internal1_m66_Pav0,&internal1_m66_Zav0,&internal1_m66_RA00,&internal1_m66_RA10,&internal1_m66_RA30,&internal1_m66_RA50,&internal1_m66_fls,&internal1_m66_flp,&internal1_m66_MyFirstEnterFlag,&bFirstEnterFlag};
_S_azbars  S_azbars_14_1 = {&var325,&var310,&var295,&var281,&fEM_R0UR30RIM,&A7AP31LDU,&var190,&lEM_R8AD10LC1,&var4,&fEM_R0UL01RIM,&fEM_R0UN02RIM,&fEM_A0UN07RIM,&fEM_R0UN18RDU,&fEM_R0UT02RIM,&fEM_R0UT04RIM,&fEM_R0UT05RIM,&fEM_R0UH05RSS,&fEM_A0UN02RIM,&fEM_A0UN01RIM,&fEM_A1UR00RIM,&fEM_A1UR01RIM,&fEM_A2UR00RIM,&fEM_A2UR01RIM,&fEM_A3UR00RIM,&fEM_A3UR01RIM,&var226,&var228,&fEM_R0UT03RIM,&fEM_R0UT06RIM,&fEM_A0UR02RSP,&fEM_A0UR01RSP,&fEM_A0UT03RSP,&var332,&var333,&var334,&var335,&var336,&var337,&var338,&internal1_m14_C1,&internal1_m14_C2,&internal1_m14_C3,&internal1_m14_C4,&internal1_m14_C5,&internal1_m14_C6,&internal1_m14_N20,&internal1_m14_N00,&internal1_m14_R00,&internal1_m14_T00,&internal1_m14_ImpINI0,&internal1_m14_MyFirstEnterFlag,&bFirstEnterFlag};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  noto(&S_noto_90_1);
  noto(&S_noto_257_1);
  noto(&S_noto_590_1);
  noto(&S_noto_591_1);
  noto(&S_noto_504_1);
  bol(&S_bol_928_1);
  bol(&S_bol_938_1);
  bol(&S_bol_916_1);
  bol(&S_bol_937_1);
  bol(&S_bol_940_1);
  zpfs(&S_zpfs_613_1);
  zpfs(&S_zpfs_626_1);
  noto(&S_noto_474_1);
  noto(&S_noto_472_1);
  noto(&S_noto_482_1);
  noto(&S_noto_481_1);
  to3val(&S_to3val_954_1);
  looktakt(&S_looktakt_150_1);
  noto(&S_noto_634_1);
  noto(&S_noto_635_1);
  asmot(&S_asmot_892_1);
  asmot(&S_asmot_364_1);
  asmot(&S_asmot_380_1);
  asmot(&S_asmot_395_1);
  asmot(&S_asmot_494_1);
  asmot(&S_asmot_443_1);
  asmot(&S_asmot_457_1);
  asmot(&S_asmot_566_1);
  asmot(&S_asmot_580_1);
  fsumo(&S_fsumo_896_1);
  inf(&S_inf_9_1);
  inf(&S_inf_7_1);
  fsubo(&S_fsubo_8_1);
  noto(&S_noto_51_1);
  noto(&S_noto_52_1);
  noto(&S_noto_218_1);
  noto(&S_noto_219_1);
  orn(&S_orn_623_1);
  asmot(&S_asmot_592_1);
  asmot(&S_asmot_593_1);
  noto(&S_noto_600_1);
  noto(&S_noto_602_1);
  noto(&S_noto_469_1);
  noto(&S_noto_502_1);
  lk(&S_lk_508_1);
  orn(&S_orn_905_1);
  to3val(&S_to3val_531_1);
  toao(&S_toao_536_1);
  toao(&S_toao_537_1);
  to3val(&S_to3val_509_1);
  toao(&S_toao_515_1);
  twobool(&S_twobool_552_1);
  twobool(&S_twobool_653_1);
  twobool(&S_twobool_673_1);
  twobool(&S_twobool_654_1);
  to3val(&S_to3val_828_1);
  ktoenc(&S_ktoenc_836_1);
  to3val(&S_to3val_826_1);
  ktoenc(&S_ktoenc_834_1);
  twobool(&S_twobool_550_1);
  twobool(&S_twobool_551_1);
  twobool(&S_twobool_688_1);
  twobool(&S_twobool_687_1);
  twobool(&S_twobool_690_1);
  twobool(&S_twobool_689_1);
  twobool(&S_twobool_1036_1);
  twobool(&S_twobool_852_1);
  twobool(&S_twobool_854_1);
  twobool(&S_twobool_853_1);
  to3val(&S_to3val_532_1);
  toao(&S_toao_538_1);
  toao(&S_toao_539_1);
  twobool(&S_twobool_535_1);
  twobool(&S_twobool_980_1);
  twobool(&S_twobool_995_1);
  twobool(&S_twobool_1012_1);
  twobool(&S_twobool_1034_1);
  twobool(&S_twobool_815_1);
  twobool(&S_twobool_981_1);
  twobool(&S_twobool_982_1);
  twobool(&S_twobool_983_1);
  twobool(&S_twobool_984_1);
  twobool(&S_twobool_1032_1);
  twobool(&S_twobool_811_1);
  twobool(&S_twobool_812_1);
  twobool(&S_twobool_814_1);
  twobool(&S_twobool_813_1);
  twobool(&S_twobool_839_1);
  twobool(&S_twobool_837_1);
  twobool(&S_twobool_840_1);
  twobool(&S_twobool_838_1);
  twobool(&S_twobool_1016_1);
  twobool(&S_twobool_1017_1);
  twobool(&S_twobool_1018_1);
  twobool(&S_twobool_1037_1);
  twobool(&S_twobool_62_1);
  twobool(&S_twobool_47_1);
  twobool(&S_twobool_228_1);
  twobool(&S_twobool_211_1);
  zpfs(&S_zpfs_601_1);
  zpfs(&S_zpfs_603_1);
  or2(&S_or2_906_1);
  or2(&S_or2_913_1);
  or2(&S_or2_920_1);
  or2(&S_or2_929_1);
  ampl(&S_ampl_369_1);
  rs(&S_rs_468_1);
  rs(&S_rs_467_1);
  rs(&S_rs_480_1);
  rs(&S_rs_479_1);
  twobool(&S_twobool_534_1);
  twobool(&S_twobool_518_1);
  twobool(&S_twobool_655_1);
  twobool(&S_twobool_656_1);
  twobool(&S_twobool_675_1);
  twobool(&S_twobool_676_1);
  twobool(&S_twobool_657_1);
  twobool(&S_twobool_658_1);
  twobool(&S_twobool_677_1);
  twobool(&S_twobool_678_1);
  twobool(&S_twobool_996_1);
  twobool(&S_twobool_997_1);
  twobool(&S_twobool_998_1);
  twobool(&S_twobool_999_1);
  twobool(&S_twobool_816_1);
  twobool(&S_twobool_817_1);
  fsubo(&S_fsubo_371_1);
  noto(&S_noto_622_1);
  andn(&S_andn_92_1);
  andn(&S_andn_91_1);
  andn(&S_andn_53_1);
  andn(&S_andn_54_1);
  andn(&S_andn_124_1);
  andn(&S_andn_220_1);
  andn(&S_andn_221_1);
  andn(&S_andn_259_1);
  andn(&S_andn_258_1);
  andn(&S_andn_292_1);
  noto(&S_noto_907_1);
  andn(&S_andn_902_1);
  asmot(&S_asmot_605_1);
  asmot(&S_asmot_606_1);
  asmot(&S_asmot_473_1);
  asmot(&S_asmot_483_1);
  asmot(&S_asmot_471_1);
  noto(&S_noto_914_1);
  andn(&S_andn_910_1);
  noto(&S_noto_921_1);
  andn(&S_andn_918_1);
  noto(&S_noto_930_1);
  andn(&S_andn_925_1);
  lk(&S_lk_507_1);
  noto(&S_noto_904_1);
  andn(&S_andn_900_1);
  twobool(&S_twobool_1035_1);
  to3val(&S_to3val_506_1);
  toao(&S_toao_517_1);
  twobool(&S_twobool_1013_1);
  twobool(&S_twobool_1015_1);
  twobool(&S_twobool_1014_1);
  twobool(&S_twobool_1033_1);
  orrsim(&S_orrsim_66_1);
  orrsim(&S_orrsim_232_1);
  orrsim(&S_orrsim_103_1);
  orrsim(&S_orrsim_267_1);
  orrsim(&S_orrsim_134_1);
  orrsim(&S_orrsim_300_1);
  fsubo(&S_fsubo_80_1);
  fsubo(&S_fsubo_247_1);
  fsubo(&S_fsubo_285_1);
  fsubo(&S_fsubo_118_1);
  twobool(&S_twobool_425_1);
  twobool(&S_twobool_426_1);
  twobool(&S_twobool_427_1);
  to3val(&S_to3val_424_1);
  ktoenc(&S_ktoenc_429_1);
  twobool(&S_twobool_428_1);
  twobool(&S_twobool_335_1);
  twobool(&S_twobool_319_1);
  twobool(&S_twobool_348_1);
  to3val(&S_to3val_323_1);
  ktoenc(&S_ktoenc_324_1);
  twobool(&S_twobool_347_1);
  twobool(&S_twobool_349_1);
  to3val(&S_to3val_333_1);
  ktoenc(&S_ktoenc_334_1);
  twobool(&S_twobool_350_1);
  twobool(&S_twobool_320_1);
  twobool(&S_twobool_321_1);
  twobool(&S_twobool_336_1);
  twobool(&S_twobool_337_1);
  twobool(&S_twobool_408_1);
  twobool(&S_twobool_409_1);
  twobool(&S_twobool_407_1);
  to3val(&S_to3val_410_1);
  ktoenc(&S_ktoenc_416_1);
  twobool(&S_twobool_949_1);
  twobool(&S_twobool_950_1);
  twobool(&S_twobool_953_1);
  to3val(&S_to3val_945_1);
  ktoenc(&S_ktoenc_952_1);
  to3val(&S_to3val_964_1);
  ktoenc(&S_ktoenc_969_1);
  twobool(&S_twobool_966_1);
  twobool(&S_twobool_967_1);
  twobool(&S_twobool_970_1);
  andn(&S_andn_355_1);
  twobool(&S_twobool_406_1);
  kvds(&S_kvds_39_1);
  azbars(&S_azbars_14_1);
  twobool(&S_twobool_151_1);
  to3val(&S_to3val_161_1);
  toao(&S_toao_167_1);
  toao(&S_toao_168_1);
  toao(&S_toao_169_1);
  vmemf(&S_vmemf_176_1);
  azbars(&S_azbars_186_1);
  vchs(&S_vchs_702_1);
  vchs(&S_vchs_712_1);
  vchs(&S_vchs_721_1);
  vchs(&S_vchs_730_1);
  vchs(&S_vchs_738_1);
  vchs(&S_vchs_747_1);
  vchs(&S_vchs_756_1);
  vchs(&S_vchs_764_1);
  vchs(&S_vchs_773_1);
  vchs(&S_vchs_782_1);
  vchs(&S_vchs_790_1);
  vchs(&S_vchs_799_1);
  bol(&S_bol_611_1);
  bol(&S_bol_630_1);
  mod1(&S_mod1_637_1);
  orn(&S_orn_631_1);
  react(&S_react_204_1);
  orn(&S_orn_612_1);
  twobool(&S_twobool_152_1);
  to3val(&S_to3val_159_1);
  toao(&S_toao_164_1);
  toao(&S_toao_165_1);
  toao(&S_toao_166_1);
  ampl(&S_ampl_644_1);
  vchs(&S_vchs_862_1);
  vchs(&S_vchs_870_1);
  vchs(&S_vchs_880_1);
  to3val(&S_to3val_645_1);
  setData(idR6IS66LZ2,&var121);
  setData(idR7II73LZ2,&var181);
  setData(idR7II72LZ2,&var181);
  setData(idR7II73LZ1,&var181);
  setData(idR7II72LZ1,&var181);
  setData(idR7II71LZ2,&var181);
  setData(idR7II76LZ2,&var220);
  setData(idR7II76LZ1,&var220);
  setData(idR7II75LZ2,&var220);
  setData(idR7II75LZ1,&var220);
  setData(idR7II74LZ2,&var220);
  setData(idR0SR03RIM,&var338);
  setData(idR8AD22LDU,&var5);
  setData(idLTAKTS,&var6);
  setData(idkrb2,&var302);
  setData(idkrb1,&var310);
  setData(idR0IS01FI0,&lRM_1_);
  setData(idA0IT03IRP,&var163);
  setData(idB0IT03IRP,&var157);
  setData(idR0IN03FI3,&var235);
  setData(idR0IN02FI3,&var236);
  setData(idR0IN03FI2,&var238);
  setData(idR0IN07RIP,&var8);
  setData(idR0IN06RIP,&var7);
  setData(idR0IN03RIP,&var9);
  setData(idR0IN02RIP,&var10);
  setData(idR0IN01RIP,&var11);
  setData(idR0IN02FI2,&var239);
  setData(idR0IN03FI1,&var241);
  setData(idR0IN02FI1,&var242);
  setData(idR0IN03FI4,&var232);
  setData(idR0IN02FI4,&var233);
  setData(idR0IN01FI3,&var237);
  setData(idR0IN01FI2,&var240);
  setData(idR0IN01FI4,&var234);
  setData(idR0IN01FI1,&var244);
  setData(idR4VS12LDU,&var13);
  setData(idR4VS22LDU,&var12);
  setData(idR1VS12LDU,&var17);
  setData(idR2VS12LDU,&var15);
  setData(idR2VS22LDU,&var14);
  setData(idR1VS22LDU,&var16);
  setData(idB5VS12LDU,&var19);
  setData(idB5VS22LDU,&var18);
  setData(idA5VS12LDU,&var21);
  setData(idA5VS22LDU,&var20);
  setData(idB6VS12LDU,&var23);
  setData(idB6VS22LDU,&var22);
  setData(idA6VS12LDU,&var25);
  setData(idA6VS22LDU,&var24);
  setData(idB8IS21LDU,&var73);
  setData(idB8IS11LDU,&var71);
  setData(idA1VP81LZZ,&var26);
  setData(idB1VP81LZZ,&var27);
  setData(idB2IS33LDU,&var28);
  setData(idA0VN01RIM,&var337);
  setData(idB2IS32LIM,&var306);
  setData(idB2IS11LIM,&var308);
  setData(idA2IS32LIM,&var314);
  setData(idA2IS11LIM,&var316);
  setData(idB1IS32LIM,&var322);
  setData(idB1IS11LIM,&var323);
  setData(idA1IS32LIM,&var327);
  setData(idA1IS11LIM,&var330);
  setData(idR0IS02LDU,&lEM_R0IE02LRP);
  setData(idB4IS10LDU,&var50);
  setData(idA4IS10LDU,&var49);
  setData(idB1IE04LDU,&var51);
  setData(idB1IE03LDU,&var52);
  setData(idA1IE04LDU,&var53);
  setData(idA1IE03LDU,&var54);
  setData(idB1IS12LDU,&var55);
  setData(idB1IS11LDU,&var56);
  setData(idB1IS21LDU,&var57);
  setData(idB1IC01UDU,&var58);
  setData(idA1IC01UDU,&var60);
  setData(idA1IS12LDU,&var62);
  setData(idA1IS11LDU,&var63);
  setData(idA1IS21LDU,&var64);
  setData(idB6IS21LDU,&var65);
  setData(idB6IS11LDU,&var66);
  setData(idA6IS21LDU,&var67);
  setData(idA6IS11LDU,&var68);
  setData(idA8IS12LDU,&var69);
  setData(idA8IS22LDU,&var70);
  setData(idB8IS12LDU,&var72);
  setData(idB8IS22LDU,&var74);
  setData(idR4IS12LDU,&var75);
  setData(idR4IS22LDU,&var76);
  setData(idR4IS21LDU,&var77);
  setData(idR4IS11LDU,&var78);
  setData(idB4VP82LDU,&var80);
  setData(idA4VP82LDU,&var79);
  setData(idR2IS21LDU,&var81);
  setData(idR2IS11LDU,&var82);
  setData(idR1IS21LDU,&var83);
  setData(idR1IS11LDU,&var84);
  setData(idB4IS21LDU,&var85);
  setData(idB4IS11LDU,&var86);
  setData(idR8IS11LDU,&var87);
  setData(idA4IS21LDU,&var88);
  setData(idA4IS11LDU,&var89);
  setData(idR5IS21LDU,&var90);
  setData(idR5IS11LDU,&var91);
  setData(idR3IS21LDU,&var92);
  setData(idR3IS11LDU,&var93);
  setData(idB2VP82LDU,&var94);
  setData(idB2IP01IZ2,&var96);
  setData(idB2IP01IZ1,&var97);
  setData(idB2IC01UDU,&var100);
  setData(idB2IS12LDU,&var102);
  setData(idB2IS11LDU,&var103);
  setData(idB2IS21LDU,&var104);
  setData(idB9IS21LDU,&var105);
  setData(idB9IS11LDU,&var106);
  setData(idA9IS21LDU,&var107);
  setData(idA9IS11LDU,&var108);
  setData(idB5IS21LDU,&var109);
  setData(idB5IS11LDU,&var110);
  setData(idA5IS21LDU,&var111);
  setData(idA5IS11LDU,&var112);
  setData(idB0VP81LZZ,&var114);
  setData(idA0VP81LZZ,&var115);
  setData(idB8IC01UDU,&var116);
  setData(idA8IC01UDU,&var118);
  setData(idR6IS66LZ1,&var120);
  setData(idR6IS65LDU,&var123);
  setData(idR6IS64LDU,&var122);
  setData(idR6IS63LDU,&var125);
  setData(idR6IS62LDU,&var124);
  setData(idB3IS22LDU,&var126);
  setData(idA3IS22LDU,&var127);
  setData(idB3IS11LDU,&var128);
  setData(idA3IS11LDU,&var129);
  setData(idA3IP02IDU,&var130);
  setData(idB3VP81LDU,&var133);
  setData(idA3VP81LDU,&var132);
  setData(idB3IS33LDU,&var136);
  setData(idB3IC01UDU,&var137);
  setData(idB3IS31LDU,&var139);
  setData(idB3IP02IDU,&var134);
  setData(idA3IS33LDU,&var140);
  setData(idA3IC01UDU,&var141);
  setData(idA3IS31LDU,&var143);
  setData(idA2VP82LDU,&var95);
  setData(idA2IP01IZ2,&var144);
  setData(idA2IP01IZ1,&var145);
  setData(idB3IS21LDU,&var146);
  setData(idA3IS21LDU,&var147);
  setData(idA2IS33LDU,&var148);
  setData(idA2IC01UDU,&var149);
  setData(idA2IS12LDU,&var151);
  setData(idA2IS11LDU,&var152);
  setData(idA2IS21LDU,&var153);
  setData(idB0IT02IZ2,&var158);
  setData(idB0IT01IZ1,&var159);
  setData(idA0IT02IZ2,&var164);
  setData(idA0IT01IZ1,&var167);
  setData(idR6IS21LDU,&var165);
  setData(idB7AS31LDU,&var166);
  setData(idA7AS31LDU,&var171);
  setData(idB3IS35LDU,&var174);
  setData(idA3IS35LDU,&var176);
  setData(idR7II71LZ1,&var181);
  setData(idR7II74LZ1,&var220);
  setData(idR0SR01RIM,&var182);
  setData(idR0ST01RIM,&var286);
  setData(idR0SR02RIM,&var287);
  setData(idR0CR02RIM,&var226);
  setData(idR0CR01RIM,&var228);
  setData(idB0SN08RIM,&var282);
  setData(idA0SN08RIM,&var333);
  setData(idB0SR01RIM,&var283);
  setData(idA0SR01RIM,&var334);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}
void MainCycle(void){
	if ((getAsShort(idR0DEUMLSS) == 2) || (getAsShort(idR0DEUMLSS) == 3)) {
		freebuff = 0;
		Scheme();
	} else {
		if (freebuff) return;
		freebuff = 1;
		memset(BUFFER, 0, SIZE_BUFFER);
		InitSetConst();
		if (SimulOn) initAllSimul(CodeSub, drivers, SimulIP, SimulPort);
		else initAllDriversPTI(drivers);
	}
}
#endif