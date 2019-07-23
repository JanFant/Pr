#ifndef SCM_H
#defile SCM_H
// Подсистема  scm:SCM
static char SimulOn=0;
static short CodeSub=1;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 //Время цикла мс
float takt,taktScheme=0,taktSS=0;
#define SIZE_BUFFER 4471
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
#define R0ST01RIM	BUFFER[625]	// ( - , SCM) Текущий период разгона РУ
#define idR0ST01RIM	236	// ( - , SCM) Текущий период разгона РУ
#define R0VZ71LZ1	BUFFER[630]	// ( - , SCM) Обобщенный сигнал по АЗ  1 канала
#define idR0VZ71LZ1	237	// ( - , SCM) Обобщенный сигнал по АЗ  1 канала
#define R0VZ71LZ2	BUFFER[632]	// ( - , SCM) Обобщенный сигнал по АЗ  2 канала
#define idR0VZ71LZ2	238	// ( - , SCM) Обобщенный сигнал по АЗ  2 канала
#define R1AD10LDU	BUFFER[634]	// (vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
#define idR1AD10LDU	239	// (vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
#define R1AD20LDU	BUFFER[636]	// (vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	240	// (vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
#define R1IS11LDU	BUFFER[638]	// (do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
#define idR1IS11LDU	241	// (do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
#define R1IS21LDU	BUFFER[640]	// (do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
#define idR1IS21LDU	242	// (do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
#define R1VS12LDU	BUFFER[642]	// ( - , SCM) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	243	// ( - , SCM) Движение МДЗ1 в сторону ВУ
#define R1VS22LDU	BUFFER[644]	// ( - , SCM) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	244	// ( - , SCM) Движение МДЗ1 в сторону НУ
#define R2AD10LDU	BUFFER[646]	// (vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
#define idR2AD10LDU	245	// (vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
#define R2AD20LDU	BUFFER[648]	// (vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	246	// (vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
#define R2IS11LDU	BUFFER[650]	// (do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
#define idR2IS11LDU	247	// (do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
#define R2IS21LDU	BUFFER[652]	// (do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
#define idR2IS21LDU	248	// (do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
#define R2VS12LDU	BUFFER[654]	// ( - , SCM) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	249	// ( - , SCM) Движение МДЗ2 в сторону ВУ
#define R2VS22LDU	BUFFER[656]	// ( - , SCM) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	250	// ( - , SCM) Движение МДЗ2 в сторону НУ
#define R3IS11LDU	BUFFER[658]	// (do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	251	// (do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
#define R3IS21LDU	BUFFER[660]	// (do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
#define idR3IS21LDU	252	// (do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
#define R4AD10LDU	BUFFER[662]	// (vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	253	// (vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
#define R4AD20LDU	BUFFER[664]	// (vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
#define idR4AD20LDU	254	// (vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
#define R4IS11LDU	BUFFER[666]	// (do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
#define idR4IS11LDU	255	// (do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
#define R4IS12LDU	BUFFER[668]	// (do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
#define idR4IS12LDU	256	// (do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
#define R4IS21LDU	BUFFER[670]	// (do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
#define idR4IS21LDU	257	// (do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
#define R4IS22LDU	BUFFER[672]	// (do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
#define idR4IS22LDU	258	// (do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
#define R4VS12LDU	BUFFER[674]	// ( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
#define idR4VS12LDU	259	// ( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
#define R4VS22LDU	BUFFER[676]	// ( - , SCM) Движение реактора к «У ЗАЩИТЫ»
#define idR4VS22LDU	260	// ( - , SCM) Движение реактора к «У ЗАЩИТЫ»
#define R5IS11LDU	BUFFER[678]	// (do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	261	// (do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
#define R5IS21LDU	BUFFER[680]	// (do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	262	// (do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
#define R6IS21LDU	BUFFER[682]	// (do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	263	// (do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
#define R6IS62LDU	BUFFER[684]	// ( - , - ) Исправность ВИП ССДИ-39 1канал
#define idR6IS62LDU	264	// ( - , - ) Исправность ВИП ССДИ-39 1канал
#define R6IS63LDU	BUFFER[686]	// ( - , - ) Исправность ВИП ССДИ-39 2канал
#define idR6IS63LDU	265	// ( - , - ) Исправность ВИП ССДИ-39 2канал
#define R6IS64LDU	BUFFER[688]	// ( - , - ) Исправность ВИП ССДИ-35 1канал
#define idR6IS64LDU	266	// ( - , - ) Исправность ВИП ССДИ-35 1канал
#define R6IS65LDU	BUFFER[690]	// ( - , - ) Исправность ВИП ССДИ-35 2канал
#define idR6IS65LDU	267	// ( - , - ) Исправность ВИП ССДИ-35 2канал
#define R6IS66LZZ	BUFFER[692]	// ( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	268	// ( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS67LZZ	BUFFER[694]	// ( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	269	// ( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS68LZZ	BUFFER[696]	// ( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	270	// ( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define R7II71LZ1	BUFFER[698]	// (do32_pti:110 - K08DO, - ) Сработала АС IУР (датчик 1)
#define idR7II71LZ1	271	// (do32_pti:110 - K08DO, - ) Сработала АС IУР (датчик 1)
#define R7II71LZ2	BUFFER[700]	// (do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
#define idR7II71LZ2	272	// (do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
#define R7II72LZ1	BUFFER[702]	// (do32_pti:110 - K07DO, - ) Сработала АС IУР (датчик 2)
#define idR7II72LZ1	273	// (do32_pti:110 - K07DO, - ) Сработала АС IУР (датчик 2)
#define R7II72LZ2	BUFFER[704]	// (do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
#define idR7II72LZ2	274	// (do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
#define R7II73LZ1	BUFFER[706]	// (do32_pti:110 - K09DO, - ) Сработала АС IIУР
#define idR7II73LZ1	275	// (do32_pti:110 - K09DO, - ) Сработала АС IIУР
#define R7II73LZ2	BUFFER[708]	// (do32_pti:110 - K26DO, - ) Сработала АС IIУР
#define idR7II73LZ2	276	// (do32_pti:110 - K26DO, - ) Сработала АС IIУР
#define R8AD21LDU	BUFFER[710]	// (vds32_pti:310 - K31VDSR, - ) Имитация прихода на ВУ ИС для КВДС
#define idR8AD21LDU	277	// (vds32_pti:310 - K31VDSR, - ) Имитация прихода на ВУ ИС для КВДС
#define R8AD22LDU	BUFFER[712]	// (do32_pti:140 - K09DO, - ) Сигнал синхронизации с импульсом
#define idR8AD22LDU	278	// (do32_pti:140 - K09DO, - ) Сигнал синхронизации с импульсом
#define R8IS11LDU	BUFFER[714]	// (do32_pti:130 - K14DO, - ) Аварийный НИ установлен
#define idR8IS11LDU	279	// (do32_pti:130 - K14DO, - ) Аварийный НИ установлен
#define TerR0IN06FRP	BUFFER[716]	// ( - , - ) Неисправности СНМ-11 -1,2
#define idTerR0IN06FRP	280	// ( - , - ) Неисправности СНМ-11 -1,2
#define bFirstEnterFlag	BUFFER[719]	// (bFirstEnterFlag) 
#define idbFirstEnterFlag	281	// (bFirstEnterFlag) 
#define fEM_A0UN01RIM	BUFFER[721]	// (A0UN01RIM) Мощность источника нейтронов ИНИ
#define idfEM_A0UN01RIM	282	// (A0UN01RIM) Мощность источника нейтронов ИНИ
#define fEM_A0UN02RIM	BUFFER[726]	// (A0UN02RIM) Мощность источника нейтронов с АНИ
#define idfEM_A0UN02RIM	283	// (A0UN02RIM) Мощность источника нейтронов с АНИ
#define fEM_A0UN07RIM	BUFFER[731]	// (A0UN07RIM) Доля запаздывающих нейтронов
#define idfEM_A0UN07RIM	284	// (A0UN07RIM) Доля запаздывающих нейтронов
#define fEM_A0UP01RIM	BUFFER[736]	// (A0UP01RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP01RIM	285	// (A0UP01RIM) Текущее давление в АЗ1,2
#define fEM_A0UP02RIM	BUFFER[741]	// (A0UP02RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP02RIM	286	// (A0UP02RIM) Текущее давление в АЗ1,2
#define fEM_A0UR01RSP	BUFFER[746]	// (A0UR01RSP) Стартовая  реактивность АЗ1
#define idfEM_A0UR01RSP	287	// (A0UR01RSP) Стартовая  реактивность АЗ1
#define fEM_A0UR02RSP	BUFFER[751]	// (A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define idfEM_A0UR02RSP	288	// (A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define fEM_A0UT03RSP	BUFFER[756]	// (A0UT03RSP) Стартовая  температура АЗ1 град
#define idfEM_A0UT03RSP	289	// (A0UT03RSP) Стартовая  температура АЗ1 град
#define fEM_A0UX00RSS	BUFFER[761]	// (A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	290	// (A0UX00RSS) Эффективный радиус АЗ
#define fEM_A0UX01RSS	BUFFER[766]	// (A0UX01RSS) Первый коэффициент калибровки камеры 1
#define idfEM_A0UX01RSS	291	// (A0UX01RSS) Первый коэффициент калибровки камеры 1
#define fEM_A0UX02RSS	BUFFER[771]	// (A0UX02RSS) Первый коэффициент калибровки камеры 2
#define idfEM_A0UX02RSS	292	// (A0UX02RSS) Первый коэффициент калибровки камеры 2
#define fEM_A0UX03RSS	BUFFER[776]	// (A0UX03RSS) Первый коэффициент калибровки камеры 3
#define idfEM_A0UX03RSS	293	// (A0UX03RSS) Первый коэффициент калибровки камеры 3
#define fEM_A0UX04RSS	BUFFER[781]	// (A0UX04RSS) Первый коэффициент калибровки камеры4
#define idfEM_A0UX04RSS	294	// (A0UX04RSS) Первый коэффициент калибровки камеры4
#define fEM_A0UX05RSS	BUFFER[786]	// (A0UX05RSS) Первый коэффициент калибровки камеры 5
#define idfEM_A0UX05RSS	295	// (A0UX05RSS) Первый коэффициент калибровки камеры 5
#define fEM_A0UX06RSS	BUFFER[791]	// (A0UX06RSS) Первый коэффициент калибровки камеры 6
#define idfEM_A0UX06RSS	296	// (A0UX06RSS) Первый коэффициент калибровки камеры 6
#define fEM_A0UX07RSS	BUFFER[796]	// (A0UX07RSS) Первый коэффициент калибровки камеры 7
#define idfEM_A0UX07RSS	297	// (A0UX07RSS) Первый коэффициент калибровки камеры 7
#define fEM_A0UX08RSS	BUFFER[801]	// (A0UX08RSS) Первый коэффициент калибровки камеры 8
#define idfEM_A0UX08RSS	298	// (A0UX08RSS) Первый коэффициент калибровки камеры 8
#define fEM_A0UX09RSS	BUFFER[806]	// (A0UX09RSS) Первый коэффициент калибровки камеры 9
#define idfEM_A0UX09RSS	299	// (A0UX09RSS) Первый коэффициент калибровки камеры 9
#define fEM_A0UX10RSS	BUFFER[811]	// (A0UX10RSS) Первый коэффициент калибровки камеры 10
#define idfEM_A0UX10RSS	300	// (A0UX10RSS) Первый коэффициент калибровки камеры 10
#define fEM_A0UX11RSS	BUFFER[816]	// (A0UX11RSS) Первый коэффициент калибровки камеры 11
#define idfEM_A0UX11RSS	301	// (A0UX11RSS) Первый коэффициент калибровки камеры 11
#define fEM_A0UX12RSS	BUFFER[821]	// (A0UX12RSS) Первый коэффициент калибровки камеры 12
#define idfEM_A0UX12RSS	302	// (A0UX12RSS) Первый коэффициент калибровки камеры 12
#define fEM_A0UX13RSS	BUFFER[826]	// (A0UX13RSS) Первый коэффициент калибровки камеры 13
#define idfEM_A0UX13RSS	303	// (A0UX13RSS) Первый коэффициент калибровки камеры 13
#define fEM_A0UX14RSS	BUFFER[831]	// (A0UX14RSS) Первый коэффициент калибровки камеры 14
#define idfEM_A0UX14RSS	304	// (A0UX14RSS) Первый коэффициент калибровки камеры 14
#define fEM_A0UX15RSS	BUFFER[836]	// (A0UX15RSS) Первый коэффициент калибровки камеры 15
#define idfEM_A0UX15RSS	305	// (A0UX15RSS) Первый коэффициент калибровки камеры 15
#define fEM_A1MC01RC1	BUFFER[841]	// (A1MC01RC1) Заданная координата  ББ1 от ИС
#define idfEM_A1MC01RC1	306	// (A1MC01RC1) Заданная координата  ББ1 от ИС
#define fEM_A1MC01RSP	BUFFER[846]	// (A1MC01RSP) Стартовая координата  ББ1
#define idfEM_A1MC01RSP	307	// (A1MC01RSP) Стартовая координата  ББ1
#define fEM_A1MC02RC1	BUFFER[851]	// (A1MC02RC1) Заданная координата штока ББ1 от ИС
#define idfEM_A1MC02RC1	308	// (A1MC02RC1) Заданная координата штока ББ1 от ИС
#define fEM_A1MC02RSP	BUFFER[856]	// (A1MC02RSP) Стартовая координата штока ББ1
#define idfEM_A1MC02RSP	309	// (A1MC02RSP) Стартовая координата штока ББ1
#define fEM_A1MV01RC1	BUFFER[861]	// (A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define idfEM_A1MV01RC1	310	// (A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define fEM_A1MV02RC1	BUFFER[866]	// (A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define idfEM_A1MV02RC1	311	// (A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define fEM_A1UC02RDU	BUFFER[871]	// (A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define idfEM_A1UC02RDU	312	// (A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define fEM_A1UC03RDU	BUFFER[876]	// (A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define idfEM_A1UC03RDU	313	// (A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define fEM_A1UC04RIM	BUFFER[881]	// (A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define idfEM_A1UC04RIM	314	// (A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define fEM_A1UC05RIM	BUFFER[886]	// (A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define idfEM_A1UC05RIM	315	// (A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define fEM_A1UC06RIM	BUFFER[891]	// (A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define idfEM_A1UC06RIM	316	// (A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define fEM_A1UC08RIM	BUFFER[896]	// (A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define idfEM_A1UC08RIM	317	// (A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define fEM_A1UG01RDU	BUFFER[901]	// (A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define idfEM_A1UG01RDU	318	// (A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define fEM_A1UP01RIM	BUFFER[906]	// (A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define idfEM_A1UP01RIM	319	// (A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define fEM_A1UP82RIM	BUFFER[911]	// (A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define idfEM_A1UP82RIM	320	// (A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define fEM_A1UR00RIM	BUFFER[916]	// (A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR00RIM	321	// (A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define fEM_A1UR01RIM	BUFFER[921]	// (A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR01RIM	322	// (A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define fEM_A1US07RDU	BUFFER[926]	// (A1US07RDU) Постоянная времени масляного демпфера ББ
#define idfEM_A1US07RDU	323	// (A1US07RDU) Постоянная времени масляного демпфера ББ
#define fEM_A1UV02RIM	BUFFER[931]	// (A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define idfEM_A1UV02RIM	324	// (A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define fEM_A2MC01RC1	BUFFER[936]	// (A2MC01RC1) Заданная координата РБ1 от ИС
#define idfEM_A2MC01RC1	325	// (A2MC01RC1) Заданная координата РБ1 от ИС
#define fEM_A2MC01RSP	BUFFER[941]	// (A2MC01RSP) Стартовая координата  РБ1
#define idfEM_A2MC01RSP	326	// (A2MC01RSP) Стартовая координата  РБ1
#define fEM_A2MC02RC1	BUFFER[946]	// (A2MC02RC1) Заданная координата штока РБ1 от ИС
#define idfEM_A2MC02RC1	327	// (A2MC02RC1) Заданная координата штока РБ1 от ИС
#define fEM_A2MC02RSP	BUFFER[951]	// (A2MC02RSP) Стартовая координата штока РБ1
#define idfEM_A2MC02RSP	328	// (A2MC02RSP) Стартовая координата штока РБ1
#define fEM_A2MV01RC1	BUFFER[956]	// (A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define idfEM_A2MV01RC1	329	// (A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define fEM_A2MV02RC1	BUFFER[961]	// (A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define idfEM_A2MV02RC1	330	// (A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define fEM_A2UC02RDU	BUFFER[966]	// (A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define idfEM_A2UC02RDU	331	// (A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define fEM_A2UC03RDU	BUFFER[971]	// (A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define idfEM_A2UC03RDU	332	// (A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define fEM_A2UC04RIM	BUFFER[976]	// (A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define idfEM_A2UC04RIM	333	// (A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define fEM_A2UC05RIM	BUFFER[981]	// (A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define idfEM_A2UC05RIM	334	// (A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define fEM_A2UC06RIM	BUFFER[986]	// (A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define idfEM_A2UC06RIM	335	// (A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define fEM_A2UC08RIM	BUFFER[991]	// (A2UC08RIM) Зона срабатывания КВ  РБ мм
#define idfEM_A2UC08RIM	336	// (A2UC08RIM) Зона срабатывания КВ  РБ мм
#define fEM_A2UG01RDU	BUFFER[996]	// (A2UG01RDU) Расстояние включения масляного демпфера РБ
#define idfEM_A2UG01RDU	337	// (A2UG01RDU) Расстояние включения масляного демпфера РБ
#define fEM_A2UP01RIM	BUFFER[1001]	// (A2UP01RIM) Текущее давление на сброс РБ
#define idfEM_A2UP01RIM	338	// (A2UP01RIM) Текущее давление на сброс РБ
#define fEM_A2UP02RIM	BUFFER[1006]	// (A2UP02RIM) Текущее давление на подъём РБ
#define idfEM_A2UP02RIM	339	// (A2UP02RIM) Текущее давление на подъём РБ
#define fEM_A2UP03RDU	BUFFER[1011]	// (A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP03RDU	340	// (A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UP03RIM	BUFFER[1016]	// (A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define idfEM_A2UP03RIM	341	// (A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define fEM_A2UP04RDU	BUFFER[1021]	// (A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP04RDU	342	// (A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UR00RIM	BUFFER[1026]	// (A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define idfEM_A2UR00RIM	343	// (A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define fEM_A2UR01RIM	BUFFER[1031]	// (A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define idfEM_A2UR01RIM	344	// (A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define fEM_A2US07RDU	BUFFER[1036]	// (A2US07RDU) Постоянная времени масляного демпфера РБ
#define idfEM_A2US07RDU	345	// (A2US07RDU) Постоянная времени масляного демпфера РБ
#define fEM_A2UV02RIM	BUFFER[1041]	// (A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define idfEM_A2UV02RIM	346	// (A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define fEM_A3MC01RC1	BUFFER[1046]	// (A3MC01RC1) Заданная координата ИС1 от ИС
#define idfEM_A3MC01RC1	347	// (A3MC01RC1) Заданная координата ИС1 от ИС
#define fEM_A3MC01RSP	BUFFER[1051]	// (A3MC01RSP) Стартовая координата  ИС1
#define idfEM_A3MC01RSP	348	// (A3MC01RSP) Стартовая координата  ИС1
#define fEM_A3MC02RC1	BUFFER[1056]	// (A3MC02RC1) Заданная координата штока ИС1 от ИС
#define idfEM_A3MC02RC1	349	// (A3MC02RC1) Заданная координата штока ИС1 от ИС
#define fEM_A3MC02RSP	BUFFER[1061]	// (A3MC02RSP) Стартовая координата штока ИС1
#define idfEM_A3MC02RSP	350	// (A3MC02RSP) Стартовая координата штока ИС1
#define fEM_A3MV01RC1	BUFFER[1066]	// (A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define idfEM_A3MV01RC1	351	// (A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define fEM_A3MV02RC1	BUFFER[1071]	// (A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define idfEM_A3MV02RC1	352	// (A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define fEM_A3UC02RDU	BUFFER[1076]	// (A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define idfEM_A3UC02RDU	353	// (A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define fEM_A3UC03RDU	BUFFER[1081]	// (A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define idfEM_A3UC03RDU	354	// (A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define fEM_A3UC04RIM	BUFFER[1086]	// (A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define idfEM_A3UC04RIM	355	// (A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define fEM_A3UC05RIM	BUFFER[1091]	// (A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC05RIM	356	// (A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define fEM_A3UC06RIM	BUFFER[1096]	// (A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define idfEM_A3UC06RIM	357	// (A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define fEM_A3UC08RIM	BUFFER[1101]	// (A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define idfEM_A3UC08RIM	358	// (A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define fEM_A3UG01RDU	BUFFER[1106]	// (A3UG01RDU) Расстояние включения масляного демпфера ИС
#define idfEM_A3UG01RDU	359	// (A3UG01RDU) Расстояние включения масляного демпфера ИС
#define fEM_A3UP01RIM	BUFFER[1111]	// (A3UP01RIM) Текущее давление на СПУСК ИС
#define idfEM_A3UP01RIM	360	// (A3UP01RIM) Текущее давление на СПУСК ИС
#define fEM_A3UP02RDU	BUFFER[1116]	// (A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define idfEM_A3UP02RDU	361	// (A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define fEM_A3UP02RIM	BUFFER[1121]	// (A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define idfEM_A3UP02RIM	362	// (A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define fEM_A3UP03RDU	BUFFER[1126]	// (A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	363	// (A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	BUFFER[1131]	// (A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	364	// (A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UR00RIM	BUFFER[1136]	// (A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR00RIM	365	// (A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define fEM_A3UR01RIM	BUFFER[1141]	// (A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR01RIM	366	// (A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define fEM_A3US07RDU	BUFFER[1146]	// (A3US07RDU) Постоянная времени масляного демпфера ИС
#define idfEM_A3US07RDU	367	// (A3US07RDU) Постоянная времени масляного демпфера ИС
#define fEM_A3UV02RIM	BUFFER[1151]	// (A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define idfEM_A3UV02RIM	368	// (A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define fEM_A4MC01RSP	BUFFER[1156]	// (A4MC01RSP) Стартовая координата НИ1
#define idfEM_A4MC01RSP	369	// (A4MC01RSP) Стартовая координата НИ1
#define fEM_A4UL10RIM	BUFFER[1161]	// (A4UL10RIM) Время полного перемещения НИ сек
#define idfEM_A4UL10RIM	370	// (A4UL10RIM) Время полного перемещения НИ сек
#define fEM_A4UP01RIM	BUFFER[1166]	// (A4UP01RIM) Текущее давление на подъём НИ
#define idfEM_A4UP01RIM	371	// (A4UP01RIM) Текущее давление на подъём НИ
#define fEM_A4UP02RIM	BUFFER[1171]	// (A4UP02RIM) Нижняя граница давления на подъём НИ
#define idfEM_A4UP02RIM	372	// (A4UP02RIM) Нижняя граница давления на подъём НИ
#define fEM_A5MC01RC1	BUFFER[1176]	// (A5MC01RC1) Заданная координата НЛ1 от ИС
#define idfEM_A5MC01RC1	373	// (A5MC01RC1) Заданная координата НЛ1 от ИС
#define fEM_A5MC01RSP	BUFFER[1181]	// (A5MC01RSP) Стартовая координата НЛ1
#define idfEM_A5MC01RSP	374	// (A5MC01RSP) Стартовая координата НЛ1
#define fEM_A5MV01RC1	BUFFER[1186]	// (A5MV01RC1) Заданная скорость НЛ1 от ИС
#define idfEM_A5MV01RC1	375	// (A5MV01RC1) Заданная скорость НЛ1 от ИС
#define fEM_A5UC10RIM	BUFFER[1191]	// (A5UC10RIM) Время полного хода НЛ сек
#define idfEM_A5UC10RIM	376	// (A5UC10RIM) Время полного хода НЛ сек
#define fEM_A6MC01RC1	BUFFER[1196]	// (A6MC01RC1) Заданная координата БЗ1 от ИС
#define idfEM_A6MC01RC1	377	// (A6MC01RC1) Заданная координата БЗ1 от ИС
#define fEM_A6MC01RSP	BUFFER[1201]	// (A6MC01RSP) Стартовая координата БЗ1
#define idfEM_A6MC01RSP	378	// (A6MC01RSP) Стартовая координата БЗ1
#define fEM_A6MV01RC1	BUFFER[1206]	// (A6MV01RC1) Заданная скорость БЗ1 от ИС
#define idfEM_A6MV01RC1	379	// (A6MV01RC1) Заданная скорость БЗ1 от ИС
#define fEM_A6UC10RIM	BUFFER[1211]	// (A6UC10RIM) Время полного хода БЗ (сек)
#define idfEM_A6UC10RIM	380	// (A6UC10RIM) Время полного хода БЗ (сек)
#define fEM_A6US80RDU	BUFFER[1216]	// (A6US80RDU) Тормозной путь БЗ (мм)
#define idfEM_A6US80RDU	381	// (A6US80RDU) Тормозной путь БЗ (мм)
#define fEM_A8MC01RC1	BUFFER[1221]	// (A8MC01RC1) Заданная координата ДС2 от ИС
#define idfEM_A8MC01RC1	382	// (A8MC01RC1) Заданная координата ДС2 от ИС
#define fEM_A8MC01RSP	BUFFER[1226]	// (A8MC01RSP) Стартовая координата ДС2
#define idfEM_A8MC01RSP	383	// (A8MC01RSP) Стартовая координата ДС2
#define fEM_A8MV01RC1	BUFFER[1231]	// (A8MV01RC1) Заданная скорость ДС2 от ИС
#define idfEM_A8MV01RC1	384	// (A8MV01RC1) Заданная скорость ДС2 от ИС
#define fEM_A8UC03RDU	BUFFER[1236]	// (A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define idfEM_A8UC03RDU	385	// (A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define fEM_A8UC08RDU	BUFFER[1241]	// (A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define idfEM_A8UC08RDU	386	// (A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define fEM_A8UC10RIM	BUFFER[1246]	// (A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define idfEM_A8UC10RIM	387	// (A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define fEM_A8UC11RIM	BUFFER[1251]	// (A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define idfEM_A8UC11RIM	388	// (A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define fEM_A8UC20RIM	BUFFER[1256]	// (A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define idfEM_A8UC20RIM	389	// (A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define fEM_A8UC21RIM	BUFFER[1261]	// (A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define idfEM_A8UC21RIM	390	// (A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define fEM_A8US80RDU	BUFFER[1266]	// (A8US80RDU) Тормозной путь ДС2 (мм)
#define idfEM_A8US80RDU	391	// (A8US80RDU) Тормозной путь ДС2 (мм)
#define fEM_A8UV80RDU	BUFFER[1271]	// (A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define idfEM_A8UV80RDU	392	// (A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define fEM_A9MC01RSP	BUFFER[1276]	// (A9MC01RSP) Стартовая координата НИ ДС1
#define idfEM_A9MC01RSP	393	// (A9MC01RSP) Стартовая координата НИ ДС1
#define fEM_A9UL10RIM	BUFFER[1281]	// (A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define idfEM_A9UL10RIM	394	// (A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define fEM_B0UT03RSP	BUFFER[1286]	// (B0UT03RSP) Стартовая  температура АЗ2 град
#define idfEM_B0UT03RSP	395	// (B0UT03RSP) Стартовая  температура АЗ2 град
#define fEM_B0UX01RSS	BUFFER[1291]	// (B0UX01RSS) Второй коэффициент калибровки камеры 1
#define idfEM_B0UX01RSS	396	// (B0UX01RSS) Второй коэффициент калибровки камеры 1
#define fEM_B0UX02RSS	BUFFER[1296]	// (B0UX02RSS) Второй коэффициент калибровки камеры 2
#define idfEM_B0UX02RSS	397	// (B0UX02RSS) Второй коэффициент калибровки камеры 2
#define fEM_B0UX03RSS	BUFFER[1301]	// (B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	398	// (B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	BUFFER[1306]	// (B0UX04RSS) Второй коэффициент калибровки камеры 4
#define idfEM_B0UX04RSS	399	// (B0UX04RSS) Второй коэффициент калибровки камеры 4
#define fEM_B0UX05RSS	BUFFER[1311]	// (B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	400	// (B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_B0UX06RSS	BUFFER[1316]	// (B0UX06RSS) Второй коэффициент калибровки камеры 6
#define idfEM_B0UX06RSS	401	// (B0UX06RSS) Второй коэффициент калибровки камеры 6
#define fEM_B0UX07RSS	BUFFER[1321]	// (B0UX07RSS) Второй коэффициент калибровки камеры 7
#define idfEM_B0UX07RSS	402	// (B0UX07RSS) Второй коэффициент калибровки камеры 7
#define fEM_B0UX08RSS	BUFFER[1326]	// (B0UX08RSS) Второй коэффициент калибровки камеры 8
#define idfEM_B0UX08RSS	403	// (B0UX08RSS) Второй коэффициент калибровки камеры 8
#define fEM_B0UX09RSS	BUFFER[1331]	// (B0UX09RSS) Второй коэффициент калибровки камеры 9
#define idfEM_B0UX09RSS	404	// (B0UX09RSS) Второй коэффициент калибровки камеры 9
#define fEM_B0UX10RSS	BUFFER[1336]	// (B0UX10RSS) Второй коэффициент калибровки камеры 10
#define idfEM_B0UX10RSS	405	// (B0UX10RSS) Второй коэффициент калибровки камеры 10
#define fEM_B0UX11RSS	BUFFER[1341]	// (B0UX11RSS) Второй коэффициент калибровки камеры 11
#define idfEM_B0UX11RSS	406	// (B0UX11RSS) Второй коэффициент калибровки камеры 11
#define fEM_B0UX12RSS	BUFFER[1346]	// (B0UX12RSS) Второй коэффициент калибровки камеры 12
#define idfEM_B0UX12RSS	407	// (B0UX12RSS) Второй коэффициент калибровки камеры 12
#define fEM_B1MC01RC1	BUFFER[1351]	// (B1MC01RC1) Заданная координата ББ2 от ИС
#define idfEM_B1MC01RC1	408	// (B1MC01RC1) Заданная координата ББ2 от ИС
#define fEM_B1MC01RSP	BUFFER[1356]	// (B1MC01RSP) Стартовая координата  ББ2
#define idfEM_B1MC01RSP	409	// (B1MC01RSP) Стартовая координата  ББ2
#define fEM_B1MC02RC1	BUFFER[1361]	// (B1MC02RC1) Заданная координата штока ББ2 от ИС
#define idfEM_B1MC02RC1	410	// (B1MC02RC1) Заданная координата штока ББ2 от ИС
#define fEM_B1MC02RSP	BUFFER[1366]	// (B1MC02RSP) Стартовая координата штока ББ2
#define idfEM_B1MC02RSP	411	// (B1MC02RSP) Стартовая координата штока ББ2
#define fEM_B1MV01RC1	BUFFER[1371]	// (B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define idfEM_B1MV01RC1	412	// (B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define fEM_B1MV02RC1	BUFFER[1376]	// (B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define idfEM_B1MV02RC1	413	// (B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define fEM_B2MC01RC1	BUFFER[1381]	// (B2MC01RC1) Заданная координата РБ2 от ИС
#define idfEM_B2MC01RC1	414	// (B2MC01RC1) Заданная координата РБ2 от ИС
#define fEM_B2MC01RSP	BUFFER[1386]	// (B2MC01RSP) Стартовая координата  РБ2
#define idfEM_B2MC01RSP	415	// (B2MC01RSP) Стартовая координата  РБ2
#define fEM_B2MC02RC1	BUFFER[1391]	// (B2MC02RC1) Заданная координата штока РБ2 от ИС
#define idfEM_B2MC02RC1	416	// (B2MC02RC1) Заданная координата штока РБ2 от ИС
#define fEM_B2MC02RSP	BUFFER[1396]	// (B2MC02RSP) Стартовая координата штока РБ2
#define idfEM_B2MC02RSP	417	// (B2MC02RSP) Стартовая координата штока РБ2
#define fEM_B2MV01RC1	BUFFER[1401]	// (B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define idfEM_B2MV01RC1	418	// (B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define fEM_B2MV02RC1	BUFFER[1406]	// (B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define idfEM_B2MV02RC1	419	// (B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define fEM_B3MC01RC1	BUFFER[1411]	// (B3MC01RC1) Заданная координата ИС2 от ИС
#define idfEM_B3MC01RC1	420	// (B3MC01RC1) Заданная координата ИС2 от ИС
#define fEM_B3MC01RSP	BUFFER[1416]	// (B3MC01RSP) Стартовая координата  ИС2
#define idfEM_B3MC01RSP	421	// (B3MC01RSP) Стартовая координата  ИС2
#define fEM_B3MC02RC1	BUFFER[1421]	// (B3MC02RC1) Заданная координата штока ИС2 от ИС
#define idfEM_B3MC02RC1	422	// (B3MC02RC1) Заданная координата штока ИС2 от ИС
#define fEM_B3MC02RSP	BUFFER[1426]	// (B3MC02RSP) Стартовая координата штока ИС2
#define idfEM_B3MC02RSP	423	// (B3MC02RSP) Стартовая координата штока ИС2
#define fEM_B3MV01RC1	BUFFER[1431]	// (B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define idfEM_B3MV01RC1	424	// (B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define fEM_B3MV02RC1	BUFFER[1436]	// (B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define idfEM_B3MV02RC1	425	// (B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define fEM_B4MC01RSP	BUFFER[1441]	// (B4MC01RSP) Стартовая координата НИ2
#define idfEM_B4MC01RSP	426	// (B4MC01RSP) Стартовая координата НИ2
#define fEM_B5MC01RC1	BUFFER[1446]	// (B5MC01RC1) Заданная координата НЛ2 от ИС
#define idfEM_B5MC01RC1	427	// (B5MC01RC1) Заданная координата НЛ2 от ИС
#define fEM_B5MC01RSP	BUFFER[1451]	// (B5MC01RSP) Стартовая координата НЛ2
#define idfEM_B5MC01RSP	428	// (B5MC01RSP) Стартовая координата НЛ2
#define fEM_B5MV01RC1	BUFFER[1456]	// (B5MV01RC1) Заданная скорость НЛ2 от ИС
#define idfEM_B5MV01RC1	429	// (B5MV01RC1) Заданная скорость НЛ2 от ИС
#define fEM_B6MC01RC1	BUFFER[1461]	// (B6MC01RC1) Заданная координата БЗ2 от ИС
#define idfEM_B6MC01RC1	430	// (B6MC01RC1) Заданная координата БЗ2 от ИС
#define fEM_B6MC01RSP	BUFFER[1466]	// (B6MC01RSP) Стартовая координата БЗ2
#define idfEM_B6MC01RSP	431	// (B6MC01RSP) Стартовая координата БЗ2
#define fEM_B6MV01RC1	BUFFER[1471]	// (B6MV01RC1) Заданная скорость БЗ2 от ИС
#define idfEM_B6MV01RC1	432	// (B6MV01RC1) Заданная скорость БЗ2 от ИС
#define fEM_B8MC01RC1	BUFFER[1476]	// (B8MC01RC1) Заданная координата АЗ2 от ИС
#define idfEM_B8MC01RC1	433	// (B8MC01RC1) Заданная координата АЗ2 от ИС
#define fEM_B8MC01RSP	BUFFER[1481]	// (B8MC01RSP) Стартовая координата АЗ2
#define idfEM_B8MC01RSP	434	// (B8MC01RSP) Стартовая координата АЗ2
#define fEM_B8MV01RC1	BUFFER[1486]	// (B8MV01RC1) Заданная скорость АЗ2 от ИС
#define idfEM_B8MV01RC1	435	// (B8MV01RC1) Заданная скорость АЗ2 от ИС
#define fEM_B8UC08RDU	BUFFER[1491]	// (B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define idfEM_B8UC08RDU	436	// (B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define fEM_B8UC10RIM	BUFFER[1496]	// (B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define idfEM_B8UC10RIM	437	// (B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define fEM_B8UC11RIM	BUFFER[1501]	// (B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define idfEM_B8UC11RIM	438	// (B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define fEM_B8UC20RIM	BUFFER[1506]	// (B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define idfEM_B8UC20RIM	439	// (B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define fEM_B8UC21RIM	BUFFER[1511]	// (B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define idfEM_B8UC21RIM	440	// (B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define fEM_B8US80RDU	BUFFER[1516]	// (B8US80RDU) Тормозной путь АЗ2 (мм)
#define idfEM_B8US80RDU	441	// (B8US80RDU) Тормозной путь АЗ2 (мм)
#define fEM_B8UV80RDU	BUFFER[1521]	// (B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define idfEM_B8UV80RDU	442	// (B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define fEM_B9MC01RSP	BUFFER[1526]	// (B9MC01RSP) Стартовая координата НИ ДС2
#define idfEM_B9MC01RSP	443	// (B9MC01RSP) Стартовая координата НИ ДС2
#define fEM_R0UH01RSS	BUFFER[1531]	// (R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
#define idfEM_R0UH01RSS	444	// (R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
#define fEM_R0UH02RSS	BUFFER[1536]	// (R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define idfEM_R0UH02RSS	445	// (R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define fEM_R0UH03RSS	BUFFER[1541]	// (R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define idfEM_R0UH03RSS	446	// (R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define fEM_R0UH05RSS	BUFFER[1546]	// (R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	447	// (R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_R0UH21RSS	BUFFER[1551]	// (R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	448	// (R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	BUFFER[1556]	// (R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	449	// (R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	BUFFER[1561]	// (R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	450	// (R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0UL01RIM	BUFFER[1566]	// (R0UL01RIM) Среднее время генерации нейтронов
#define idfEM_R0UL01RIM	451	// (R0UL01RIM) Среднее время генерации нейтронов
#define fEM_R0UL02RDU	BUFFER[1571]	// (R0UL02RDU) Время задержки  ИНИ
#define idfEM_R0UL02RDU	452	// (R0UL02RDU) Время задержки  ИНИ
#define fEM_R0UL02RIM	BUFFER[1576]	// (R0UL02RIM) Время удержания синхроимпульса
#define idfEM_R0UL02RIM	453	// (R0UL02RIM) Время удержания синхроимпульса
#define fEM_R0UL04RIM	BUFFER[1581]	// (R0UL04RIM) Время блокировки повторной генерации импульса
#define idfEM_R0UL04RIM	454	// (R0UL04RIM) Время блокировки повторной генерации импульса
#define fEM_R0UN02RIM	BUFFER[1586]	// (R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define idfEM_R0UN02RIM	455	// (R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define fEM_R0UR01RIM	BUFFER[1591]	// (R0UR01RIM) Стартовая отрицательная реактивность
#define idfEM_R0UR01RIM	456	// (R0UR01RIM) Стартовая отрицательная реактивность
#define fEM_R0UR30RIM	BUFFER[1596]	// (R0UR30RIM) Реактивность вносимая образцами (долл)
#define idfEM_R0UR30RIM	457	// (R0UR30RIM) Реактивность вносимая образцами (долл)
#define fEM_R0UT01RDU	BUFFER[1601]	// (R0UT01RDU) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RDU	458	// (R0UT01RDU) Нижний предел шкалы датчика температуры
#define fEM_R0UT01RIM	BUFFER[1606]	// (R0UT01RIM) Температурный коэффициент (долл)
#define idfEM_R0UT01RIM	459	// (R0UT01RIM) Температурный коэффициент (долл)
#define fEM_R0UT02RDU	BUFFER[1611]	// (R0UT02RDU) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RDU	460	// (R0UT02RDU) Верхний предел шкалы датчика температуры
#define fEM_R0UT02RIM	BUFFER[1616]	// (R0UT02RIM) Масса топлива в АЗ
#define idfEM_R0UT02RIM	461	// (R0UT02RIM) Масса топлива в АЗ
#define fEM_R0UT03RIM	BUFFER[1621]	// (R0UT03RIM) Нормальная температура АЗ град
#define idfEM_R0UT03RIM	462	// (R0UT03RIM) Нормальная температура АЗ град
#define fEM_R0UT04RIM	BUFFER[1626]	// (R0UT04RIM) Удельная теплоёмкость топлива
#define idfEM_R0UT04RIM	463	// (R0UT04RIM) Удельная теплоёмкость топлива
#define fEM_R0UT05RIM	BUFFER[1631]	// (R0UT05RIM) Энергия деления ядра
#define idfEM_R0UT05RIM	464	// (R0UT05RIM) Энергия деления ядра
#define fEM_R0UT06RIM	BUFFER[1636]	// (R0UT06RIM) Конвекционное сопротивление при обдуве
#define idfEM_R0UT06RIM	465	// (R0UT06RIM) Конвекционное сопротивление при обдуве
#define fEM_R0UV81RDU	BUFFER[1641]	// (R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	466	// (R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	BUFFER[1646]	// (R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	467	// (R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	BUFFER[1651]	// (R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	468	// (R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	BUFFER[1656]	// (R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	469	// (R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define fEM_R0UV85RDU	BUFFER[1661]	// (R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	470	// (R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV86RDU	BUFFER[1666]	// (R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	471	// (R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV87RDU	BUFFER[1671]	// (R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	472	// (R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R1MC01RC1	BUFFER[1676]	// (R1MC01RC1) Заданная координата МДЗ1 от ИС
#define idfEM_R1MC01RC1	473	// (R1MC01RC1) Заданная координата МДЗ1 от ИС
#define fEM_R1MC01RSP	BUFFER[1681]	// (R1MC01RSP) Стартовая координата МДЗ1
#define idfEM_R1MC01RSP	474	// (R1MC01RSP) Стартовая координата МДЗ1
#define fEM_R1MV01RC1	BUFFER[1686]	// (R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define idfEM_R1MV01RC1	475	// (R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define fEM_R1UC10RIM	BUFFER[1691]	// (R1UC10RIM) Время полного хода МДЗ сек
#define idfEM_R1UC10RIM	476	// (R1UC10RIM) Время полного хода МДЗ сек
#define fEM_R2MC01RC1	BUFFER[1696]	// (R2MC01RC1) Заданная координата МДЗ2 от ИС
#define idfEM_R2MC01RC1	477	// (R2MC01RC1) Заданная координата МДЗ2 от ИС
#define fEM_R2MC01RSP	BUFFER[1701]	// (R2MC01RSP) Стартовая координата МДЗ2
#define idfEM_R2MC01RSP	478	// (R2MC01RSP) Стартовая координата МДЗ2
#define fEM_R2MV01RC1	BUFFER[1706]	// (R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define idfEM_R2MV01RC1	479	// (R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define fEM_R3UC01RSP	BUFFER[1711]	// (R3UC01RSP) Стартовая координата Гомогенных дверей
#define idfEM_R3UC01RSP	480	// (R3UC01RSP) Стартовая координата Гомогенных дверей
#define fEM_R3UL10RIM	BUFFER[1716]	// (R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define idfEM_R3UL10RIM	481	// (R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define fEM_R4MC01RC1	BUFFER[1721]	// (R4MC01RC1) Заданная координата тележки от ИС
#define idfEM_R4MC01RC1	482	// (R4MC01RC1) Заданная координата тележки от ИС
#define fEM_R4MC01RSP	BUFFER[1726]	// (R4MC01RSP) Стартовая координата тележки
#define idfEM_R4MC01RSP	483	// (R4MC01RSP) Стартовая координата тележки
#define fEM_R4MV01RC1	BUFFER[1731]	// (R4MV01RC1) Заданная скорость тележки от ИС
#define idfEM_R4MV01RC1	484	// (R4MV01RC1) Заданная скорость тележки от ИС
#define fEM_R4UC08RDU	BUFFER[1736]	// (R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define idfEM_R4UC08RDU	485	// (R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define fEM_R4UC10RIM	BUFFER[1741]	// (R4UC10RIM) Координата верхних механических упоров тележки мм
#define idfEM_R4UC10RIM	486	// (R4UC10RIM) Координата верхних механических упоров тележки мм
#define fEM_R4UC20RIM	BUFFER[1746]	// (R4UC20RIM) Координата нижних механических упоров тележки мм
#define idfEM_R4UC20RIM	487	// (R4UC20RIM) Координата нижних механических упоров тележки мм
#define fEM_R4UC22RIM	BUFFER[1751]	// (R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define idfEM_R4UC22RIM	488	// (R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define fEM_R4US80RDU	BUFFER[1756]	// (R4US80RDU) Тормозной путь тележки (мм)
#define idfEM_R4US80RDU	489	// (R4US80RDU) Тормозной путь тележки (мм)
#define fEM_R4UV80RDU	BUFFER[1761]	// (R4UV80RDU) Номинальная скорость тележки (см/с)
#define idfEM_R4UV80RDU	490	// (R4UV80RDU) Номинальная скорость тележки (см/с)
#define fEM_R5UC01RSP	BUFFER[1766]	// (R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define idfEM_R5UC01RSP	491	// (R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define fEM_R5UL10RIM	BUFFER[1771]	// (R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define idfEM_R5UL10RIM	492	// (R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define fEM_R6UC01RSP	BUFFER[1776]	// (R6UC01RSP) Стартовая координата Кран-балки
#define idfEM_R6UC01RSP	493	// (R6UC01RSP) Стартовая координата Кран-балки
#define fEM_R6UL10RIM	BUFFER[1781]	// (R6UL10RIM) Время полного хода кран-балки сек
#define idfEM_R6UL10RIM	494	// (R6UL10RIM) Время полного хода кран-балки сек
#define fEM_R7UC10RIM	BUFFER[1786]	// (R7UC10RIM) X-координата КНК53М R7IN13 см
#define idfEM_R7UC10RIM	495	// (R7UC10RIM) X-координата КНК53М R7IN13 см
#define fEM_R7UC19RIM	BUFFER[1791]	// (R7UC19RIM) Y-координата СНМ-11 (11) см
#define idfEM_R7UC19RIM	496	// (R7UC19RIM) Y-координата СНМ-11 (11) см
#define fEM_R7UI02RIM	BUFFER[1796]	// (R7UI02RIM) Коэффициент усиления уровня радиации
#define idfEM_R7UI02RIM	497	// (R7UI02RIM) Коэффициент усиления уровня радиации
#define fEM_R7UI71RIM	BUFFER[1801]	// (R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define idfEM_R7UI71RIM	498	// (R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define fEM_R7UI72RIM	BUFFER[1806]	// (R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define idfEM_R7UI72RIM	499	// (R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define fEM_R7UI73RIM	BUFFER[1811]	// (R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define idfEM_R7UI73RIM	500	// (R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define fEM_R7UI74RIM	BUFFER[1816]	// (R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define idfEM_R7UI74RIM	501	// (R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define fEM_R7UI75RIM	BUFFER[1821]	// (R7UI75RIM) Множитель к уровню радиации
#define idfEM_R7UI75RIM	502	// (R7UI75RIM) Множитель к уровню радиации
#define fEM_R7UI76RIM	BUFFER[1826]	// (R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define idfEM_R7UI76RIM	503	// (R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define fEM_R7UI77RIM	BUFFER[1831]	// (R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define idfEM_R7UI77RIM	504	// (R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define fEM_R7UL01RIM	BUFFER[1836]	// (R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define idfEM_R7UL01RIM	505	// (R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define fEM_R7UX01RSS	BUFFER[1841]	// (R7UX01RSS) X-координата камеры R7IN11
#define idfEM_R7UX01RSS	506	// (R7UX01RSS) X-координата камеры R7IN11
#define fEM_R7UX02RSS	BUFFER[1846]	// (R7UX02RSS) X-координата камеры R7IN12 (см)
#define idfEM_R7UX02RSS	507	// (R7UX02RSS) X-координата камеры R7IN12 (см)
#define fEM_R7UX04RSS	BUFFER[1851]	// (R7UX04RSS) X-координата камеры R7IN21 (см)
#define idfEM_R7UX04RSS	508	// (R7UX04RSS) X-координата камеры R7IN21 (см)
#define fEM_R7UX05RSS	BUFFER[1856]	// (R7UX05RSS) X-координата камеры R7IN22 (см)
#define idfEM_R7UX05RSS	509	// (R7UX05RSS) X-координата камеры R7IN22 (см)
#define fEM_R7UX06RSS	BUFFER[1861]	// (R7UX06RSS) X-координата камеры R7IN23 (см)
#define idfEM_R7UX06RSS	510	// (R7UX06RSS) X-координата камеры R7IN23 (см)
#define fEM_R7UX07RSS	BUFFER[1866]	// (R7UX07RSS) X-координата камеры R7IN31 (см)
#define idfEM_R7UX07RSS	511	// (R7UX07RSS) X-координата камеры R7IN31 (см)
#define fEM_R7UX08RSS	BUFFER[1871]	// (R7UX08RSS) X-координата камеры R7IN32 (см)
#define idfEM_R7UX08RSS	512	// (R7UX08RSS) X-координата камеры R7IN32 (см)
#define fEM_R7UX09RSS	BUFFER[1876]	// (R7UX09RSS) X-координата камеры R7IN33 (см)
#define idfEM_R7UX09RSS	513	// (R7UX09RSS) X-координата камеры R7IN33 (см)
#define fEM_R7UX10RSS	BUFFER[1881]	// (R7UX10RSS) X-координата камеры R7IN41
#define idfEM_R7UX10RSS	514	// (R7UX10RSS) X-координата камеры R7IN41
#define fEM_R7UX11RSS	BUFFER[1886]	// (R7UX11RSS) X-координата камеры R7IN42
#define idfEM_R7UX11RSS	515	// (R7UX11RSS) X-координата камеры R7IN42
#define fEM_R7UX12RSS	BUFFER[1891]	// (R7UX12RSS) X-координата камеры R7IN43
#define idfEM_R7UX12RSS	516	// (R7UX12RSS) X-координата камеры R7IN43
#define fEM_R7UX13RSS	BUFFER[1896]	// (R7UX13RSS) X-координата камеры R7IN51
#define idfEM_R7UX13RSS	517	// (R7UX13RSS) X-координата камеры R7IN51
#define fEM_R7UX14RSS	BUFFER[1901]	// (R7UX14RSS) X-координата камеры R7IN52
#define idfEM_R7UX14RSS	518	// (R7UX14RSS) X-координата камеры R7IN52
#define fEM_R7UX15RSS	BUFFER[1906]	// (R7UX15RSS) X-координата камеры R7IN53
#define idfEM_R7UX15RSS	519	// (R7UX15RSS) X-координата камеры R7IN53
#define fEM_R7UX16RSS	BUFFER[1911]	// (R7UX16RSS) Величина сигнала СНМ11 в БЗ
#define idfEM_R7UX16RSS	520	// (R7UX16RSS) Величина сигнала СНМ11 в БЗ
#define fEM_R7UY00RSS	BUFFER[1916]	// (R7UY00RSS) Y-координата АЗ1 см
#define idfEM_R7UY00RSS	521	// (R7UY00RSS) Y-координата АЗ1 см
#define fEM_R7UY01RSS	BUFFER[1921]	// (R7UY01RSS) Y-координата камеры R7IN11
#define idfEM_R7UY01RSS	522	// (R7UY01RSS) Y-координата камеры R7IN11
#define fEM_R7UY02RSS	BUFFER[1926]	// (R7UY02RSS) Y-координата камеры R7IN12 (см)
#define idfEM_R7UY02RSS	523	// (R7UY02RSS) Y-координата камеры R7IN12 (см)
#define fEM_R7UY04RSS	BUFFER[1931]	// (R7UY04RSS) Y-координата камеры R7IN21 (см)
#define idfEM_R7UY04RSS	524	// (R7UY04RSS) Y-координата камеры R7IN21 (см)
#define fEM_R7UY05RSS	BUFFER[1936]	// (R7UY05RSS) Y-координата камеры R7IN22 (см)
#define idfEM_R7UY05RSS	525	// (R7UY05RSS) Y-координата камеры R7IN22 (см)
#define fEM_R7UY06RSS	BUFFER[1941]	// (R7UY06RSS) Y-координата камеры R7IN23 (см)
#define idfEM_R7UY06RSS	526	// (R7UY06RSS) Y-координата камеры R7IN23 (см)
#define fEM_R7UY07RSS	BUFFER[1946]	// (R7UY07RSS) Y-координата камеры R7IN31 (см)
#define idfEM_R7UY07RSS	527	// (R7UY07RSS) Y-координата камеры R7IN31 (см)
#define fEM_R7UY08RSS	BUFFER[1951]	// (R7UY08RSS) Y-координата камеры R7IN32 (см)
#define idfEM_R7UY08RSS	528	// (R7UY08RSS) Y-координата камеры R7IN32 (см)
#define fEM_R7UY09RSS	BUFFER[1956]	// (R7UY09RSS) Y-координата камеры R7IN33 (см)
#define idfEM_R7UY09RSS	529	// (R7UY09RSS) Y-координата камеры R7IN33 (см)
#define fEM_R7UY10RSS	BUFFER[1961]	// (R7UY10RSS) Y-координата камеры R7IN41
#define idfEM_R7UY10RSS	530	// (R7UY10RSS) Y-координата камеры R7IN41
#define fEM_R7UY11RSS	BUFFER[1966]	// (R7UY11RSS) Y-координата камеры R7IN42
#define idfEM_R7UY11RSS	531	// (R7UY11RSS) Y-координата камеры R7IN42
#define fEM_R7UY12RSS	BUFFER[1971]	// (R7UY12RSS) Y-координата камеры R7IN43
#define idfEM_R7UY12RSS	532	// (R7UY12RSS) Y-координата камеры R7IN43
#define fEM_R7UY13RSS	BUFFER[1976]	// (R7UY13RSS) Y-координата камеры R7IN51
#define idfEM_R7UY13RSS	533	// (R7UY13RSS) Y-координата камеры R7IN51
#define fEM_R7UY14RSS	BUFFER[1981]	// (R7UY14RSS) Y-координата камеры R7IN52
#define idfEM_R7UY14RSS	534	// (R7UY14RSS) Y-координата камеры R7IN52
#define fEM_R7UY15RSS	BUFFER[1986]	// (R7UY15RSS) Y-координата камеры R7IN53
#define idfEM_R7UY15RSS	535	// (R7UY15RSS) Y-координата камеры R7IN53
#define iEM_TERA0MT01RIM	BUFFER[1991]	// (TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define idiEM_TERA0MT01RIM	536	// (TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define iEM_TERA0VP81LIM	BUFFER[1994]	// (TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define idiEM_TERA0VP81LIM	537	// (TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define iEM_TERA1IE03LDU	BUFFER[1997]	// (TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define idiEM_TERA1IE03LDU	538	// (TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define iEM_TERA1IE04LDU	BUFFER[2000]	// (TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define idiEM_TERA1IE04LDU	539	// (TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define iEM_TERA1SC01RIM	BUFFER[2003]	// (TERA1SC01RIM) Искажение: Координата штока ББ1
#define idiEM_TERA1SC01RIM	540	// (TERA1SC01RIM) Искажение: Координата штока ББ1
#define iEM_TERA1SS11LIM	BUFFER[2006]	// (TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define idiEM_TERA1SS11LIM	541	// (TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define iEM_TERA1SS12LIM	BUFFER[2009]	// (TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define idiEM_TERA1SS12LIM	542	// (TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define iEM_TERA1SS21LIM	BUFFER[2012]	// (TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define idiEM_TERA1SS21LIM	543	// (TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define iEM_TERA1VP81LIM	BUFFER[2015]	// (TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define idiEM_TERA1VP81LIM	544	// (TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define iEM_TERA2SC01RIM	BUFFER[2018]	// (TERA2SC01RIM) Искажение: Координата штока РБ1
#define idiEM_TERA2SC01RIM	545	// (TERA2SC01RIM) Искажение: Координата штока РБ1
#define iEM_TERA2SP01RIM	BUFFER[2021]	// (TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define idiEM_TERA2SP01RIM	546	// (TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define iEM_TERA2SS11LIM	BUFFER[2024]	// (TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define idiEM_TERA2SS11LIM	547	// (TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define iEM_TERA2SS12LIM	BUFFER[2027]	// (TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define idiEM_TERA2SS12LIM	548	// (TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define iEM_TERA2SS21LIM	BUFFER[2030]	// (TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define idiEM_TERA2SS21LIM	549	// (TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define iEM_TERA2SS33LIM	BUFFER[2033]	// (TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define idiEM_TERA2SS33LIM	550	// (TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define iEM_TERA2VP82LIM	BUFFER[2036]	// (TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define idiEM_TERA2VP82LIM	551	// (TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define iEM_TERA3SC01RIM	BUFFER[2039]	// (TERA3SC01RIM) Искажение: Координата штока ИС1
#define idiEM_TERA3SC01RIM	552	// (TERA3SC01RIM) Искажение: Координата штока ИС1
#define iEM_TERA3SP02RIM	BUFFER[2042]	// (TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define idiEM_TERA3SP02RIM	553	// (TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define iEM_TERA3SS11LIM	BUFFER[2045]	// (TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define idiEM_TERA3SS11LIM	554	// (TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define iEM_TERA3SS21LIM	BUFFER[2048]	// (TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define idiEM_TERA3SS21LIM	555	// (TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define iEM_TERA3SS22LIM	BUFFER[2051]	// (TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define idiEM_TERA3SS22LIM	556	// (TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define iEM_TERA3SS31LIM	BUFFER[2054]	// (TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define idiEM_TERA3SS31LIM	557	// (TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define iEM_TERA3SS33LIM	BUFFER[2057]	// (TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define idiEM_TERA3SS33LIM	558	// (TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define iEM_TERA3VP81LIM	BUFFER[2060]	// (TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define idiEM_TERA3VP81LIM	559	// (TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define iEM_TERA4SS11LIM	BUFFER[2063]	// (TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define idiEM_TERA4SS11LIM	560	// (TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define iEM_TERA4SS21LIM	BUFFER[2066]	// (TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define idiEM_TERA4SS21LIM	561	// (TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define iEM_TERA4VP82LIM	BUFFER[2069]	// (TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define idiEM_TERA4VP82LIM	562	// (TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define iEM_TERA5SS11LIM	BUFFER[2072]	// (TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define idiEM_TERA5SS11LIM	563	// (TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define iEM_TERA5SS21LIM	BUFFER[2075]	// (TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define idiEM_TERA5SS21LIM	564	// (TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define iEM_TERA5VS12LIM	BUFFER[2078]	// (TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define idiEM_TERA5VS12LIM	565	// (TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define iEM_TERA5VS22LIM	BUFFER[2081]	// (TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define idiEM_TERA5VS22LIM	566	// (TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define iEM_TERA6MS11LIM	BUFFER[2084]	// (TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define idiEM_TERA6MS11LIM	567	// (TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define iEM_TERA6SS21LIM	BUFFER[2087]	// (TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define idiEM_TERA6SS21LIM	568	// (TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define iEM_TERA6VS12LIM	BUFFER[2090]	// (TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define idiEM_TERA6VS12LIM	569	// (TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define iEM_TERA6VS22LIM	BUFFER[2093]	// (TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define idiEM_TERA6VS22LIM	570	// (TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define iEM_TERA7MS31LIM	BUFFER[2096]	// (TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define idiEM_TERA7MS31LIM	571	// (TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define iEM_TERA8SC01RIM	BUFFER[2099]	// (TERA8SC01RIM) Искажение: Координата ДС2
#define idiEM_TERA8SC01RIM	572	// (TERA8SC01RIM) Искажение: Координата ДС2
#define iEM_TERA8SS12LIM	BUFFER[2102]	// (TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define idiEM_TERA8SS12LIM	573	// (TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define iEM_TERA8SS22LIM	BUFFER[2105]	// (TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define idiEM_TERA8SS22LIM	574	// (TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define iEM_TERA9SS11LIM	BUFFER[2108]	// (TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define idiEM_TERA9SS11LIM	575	// (TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define iEM_TERA9SS21LIM	BUFFER[2111]	// (TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define idiEM_TERA9SS21LIM	576	// (TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define iEM_TERB0MT01RIM	BUFFER[2114]	// (TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define idiEM_TERB0MT01RIM	577	// (TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define iEM_TERB0VP81LIM	BUFFER[2117]	// (TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define idiEM_TERB0VP81LIM	578	// (TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define iEM_TERB1IE03LDU	BUFFER[2120]	// (TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define idiEM_TERB1IE03LDU	579	// (TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define iEM_TERB1IE04LDU	BUFFER[2123]	// (TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define idiEM_TERB1IE04LDU	580	// (TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define iEM_TERB1MC01RIM	BUFFER[2126]	// (TERB1MC01RIM) Искажение: Координата штока ББ2
#define idiEM_TERB1MC01RIM	581	// (TERB1MC01RIM) Искажение: Координата штока ББ2
#define iEM_TERB1SS11LIM	BUFFER[2129]	// (TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define idiEM_TERB1SS11LIM	582	// (TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define iEM_TERB1SS12LIM	BUFFER[2132]	// (TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define idiEM_TERB1SS12LIM	583	// (TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define iEM_TERB1SS21LIM	BUFFER[2135]	// (TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define idiEM_TERB1SS21LIM	584	// (TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define iEM_TERB1VP81LIM	BUFFER[2138]	// (TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define idiEM_TERB1VP81LIM	585	// (TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define iEM_TERB2SC01RIM	BUFFER[2141]	// (TERB2SC01RIM) Искажение: Координата штока РБ2
#define idiEM_TERB2SC01RIM	586	// (TERB2SC01RIM) Искажение: Координата штока РБ2
#define iEM_TERB2SP01RIM	BUFFER[2144]	// (TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define idiEM_TERB2SP01RIM	587	// (TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define iEM_TERB2SS11LIM	BUFFER[2147]	// (TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define idiEM_TERB2SS11LIM	588	// (TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define iEM_TERB2SS12LIM	BUFFER[2150]	// (TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define idiEM_TERB2SS12LIM	589	// (TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define iEM_TERB2SS21LIM	BUFFER[2153]	// (TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define idiEM_TERB2SS21LIM	590	// (TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define iEM_TERB2SS33LIM	BUFFER[2156]	// (TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define idiEM_TERB2SS33LIM	591	// (TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define iEM_TERB3SC01RIM	BUFFER[2159]	// (TERB3SC01RIM) Искажение: Координата штока ИС2
#define idiEM_TERB3SC01RIM	592	// (TERB3SC01RIM) Искажение: Координата штока ИС2
#define iEM_TERB3SP02RIM	BUFFER[2162]	// (TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define idiEM_TERB3SP02RIM	593	// (TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define iEM_TERB3SS11LIM	BUFFER[2165]	// (TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define idiEM_TERB3SS11LIM	594	// (TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define iEM_TERB3SS21LIM	BUFFER[2168]	// (TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define idiEM_TERB3SS21LIM	595	// (TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define iEM_TERB3SS22LIM	BUFFER[2171]	// (TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define idiEM_TERB3SS22LIM	596	// (TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define iEM_TERB3SS31LIM	BUFFER[2174]	// (TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define idiEM_TERB3SS31LIM	597	// (TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define iEM_TERB3SS33LIM	BUFFER[2177]	// (TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idiEM_TERB3SS33LIM	598	// (TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define iEM_TERB4SS11LIM	BUFFER[2180]	// (TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define idiEM_TERB4SS11LIM	599	// (TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define iEM_TERB4SS21LIM	BUFFER[2183]	// (TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define idiEM_TERB4SS21LIM	600	// (TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define iEM_TERB5SS11LIM	BUFFER[2186]	// (TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define idiEM_TERB5SS11LIM	601	// (TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define iEM_TERB5SS21LIM	BUFFER[2189]	// (TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define idiEM_TERB5SS21LIM	602	// (TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define iEM_TERB5VS12LIM	BUFFER[2192]	// (TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define idiEM_TERB5VS12LIM	603	// (TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define iEM_TERB5VS22LIM	BUFFER[2195]	// (TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define idiEM_TERB5VS22LIM	604	// (TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define iEM_TERB6SS11LIM	BUFFER[2198]	// (TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define idiEM_TERB6SS11LIM	605	// (TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define iEM_TERB6SS21LIM	BUFFER[2201]	// (TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define idiEM_TERB6SS21LIM	606	// (TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define iEM_TERB6VS12LIM	BUFFER[2204]	// (TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define idiEM_TERB6VS12LIM	607	// (TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define iEM_TERB6VS22LIM	BUFFER[2207]	// (TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define idiEM_TERB6VS22LIM	608	// (TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define iEM_TERB7MS31LIM	BUFFER[2210]	// (TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define idiEM_TERB7MS31LIM	609	// (TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define iEM_TERB8SC01RIM	BUFFER[2213]	// (TERB8SC01RIM) Искажение: Координата АЗ2
#define idiEM_TERB8SC01RIM	610	// (TERB8SC01RIM) Искажение: Координата АЗ2
#define iEM_TERB8SS12LIM	BUFFER[2216]	// (TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define idiEM_TERB8SS12LIM	611	// (TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define iEM_TERB8SS22LIM	BUFFER[2219]	// (TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define idiEM_TERB8SS22LIM	612	// (TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define iEM_TERB9SS11LIM	BUFFER[2222]	// (TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define idiEM_TERB9SS11LIM	613	// (TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define iEM_TERB9SS21LIM	BUFFER[2225]	// (TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define idiEM_TERB9SS21LIM	614	// (TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define iEM_TERBB1	BUFFER[2228]	// (TERBB1) Неисправности  ББ1
#define idiEM_TERBB1	615	// (TERBB1) Неисправности  ББ1
#define iEM_TERBB2	BUFFER[2231]	// (TERBB2) Неисправности  ББ2
#define idiEM_TERBB2	616	// (TERBB2) Неисправности  ББ2
#define iEM_TERBZ1	BUFFER[2234]	// (TERBZ1) Неисправности БЗ1
#define idiEM_TERBZ1	617	// (TERBZ1) Неисправности БЗ1
#define iEM_TERBZ2	BUFFER[2237]	// (TERBZ2) Неисправности БЗ2
#define idiEM_TERBZ2	618	// (TERBZ2) Неисправности БЗ2
#define iEM_TERDS2	BUFFER[2240]	// (TERDS2) Неисправности ДС2 от ИС
#define idiEM_TERDS2	619	// (TERDS2) Неисправности ДС2 от ИС
#define iEM_TERIS1	BUFFER[2243]	// (TERIS1) Неисправности  ИС1
#define idiEM_TERIS1	620	// (TERIS1) Неисправности  ИС1
#define iEM_TERIS2	BUFFER[2246]	// (TERIS2) Неисправности  ИС2
#define idiEM_TERIS2	621	// (TERIS2) Неисправности  ИС2
#define iEM_TERMAZ2	BUFFER[2249]	// (TERMAZ2) Неисправности АЗ2 от ИС
#define idiEM_TERMAZ2	622	// (TERMAZ2) Неисправности АЗ2 от ИС
#define iEM_TERMDZ1	BUFFER[2252]	// (TERMDZ1) Неисправности МДЗ1
#define idiEM_TERMDZ1	623	// (TERMDZ1) Неисправности МДЗ1
#define iEM_TERMDZ2	BUFFER[2255]	// (TERMDZ2) Неисправности МДЗ2
#define idiEM_TERMDZ2	624	// (TERMDZ2) Неисправности МДЗ2
#define iEM_TERNL1	BUFFER[2258]	// (TERNL1) Неисправности НЛ1
#define idiEM_TERNL1	625	// (TERNL1) Неисправности НЛ1
#define iEM_TERNL2	BUFFER[2261]	// (TERNL2) Неисправности НЛ2
#define idiEM_TERNL2	626	// (TERNL2) Неисправности НЛ2
#define iEM_TERR0VP81LIM	BUFFER[2264]	// (TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define idiEM_TERR0VP81LIM	627	// (TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define iEM_TERR1SS11LIM	BUFFER[2267]	// (TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define idiEM_TERR1SS11LIM	628	// (TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define iEM_TERR1SS21LIM	BUFFER[2270]	// (TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define idiEM_TERR1SS21LIM	629	// (TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define iEM_TERR1VS12LIM	BUFFER[2273]	// (TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define idiEM_TERR1VS12LIM	630	// (TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define iEM_TERR1VS22LIM	BUFFER[2276]	// (TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define idiEM_TERR1VS22LIM	631	// (TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define iEM_TERR2SS11LIM	BUFFER[2279]	// (TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define idiEM_TERR2SS11LIM	632	// (TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define iEM_TERR2SS21LIM	BUFFER[2282]	// (TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define idiEM_TERR2SS21LIM	633	// (TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define iEM_TERR2VS12LIM	BUFFER[2285]	// (TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define idiEM_TERR2VS12LIM	634	// (TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define iEM_TERR2VS22LIM	BUFFER[2288]	// (TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define idiEM_TERR2VS22LIM	635	// (TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define iEM_TERR3SS11LIM	BUFFER[2291]	// (TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define idiEM_TERR3SS11LIM	636	// (TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define iEM_TERR3SS21LIM	BUFFER[2294]	// (TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define idiEM_TERR3SS21LIM	637	// (TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define iEM_TERR4MS21LIM	BUFFER[2297]	// (TERR4MS21LIM) Искажение: Приход на НУ тележки
#define idiEM_TERR4MS21LIM	638	// (TERR4MS21LIM) Искажение: Приход на НУ тележки
#define iEM_TERR4SS11LIM	BUFFER[2300]	// (TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define idiEM_TERR4SS11LIM	639	// (TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define iEM_TERR4SS12LIM	BUFFER[2303]	// (TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define idiEM_TERR4SS12LIM	640	// (TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define iEM_TERR4SS22LIM	BUFFER[2306]	// (TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define idiEM_TERR4SS22LIM	641	// (TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define iEM_TERR4VS12LDU	BUFFER[2309]	// (TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS12LDU	642	// (TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define iEM_TERR4VS22LDU	BUFFER[2312]	// (TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS22LDU	643	// (TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define iEM_TERR5SS11LIM	BUFFER[2315]	// (TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define idiEM_TERR5SS11LIM	644	// (TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define iEM_TERR5SS21LIM	BUFFER[2318]	// (TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define idiEM_TERR5SS21LIM	645	// (TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define iEM_TERR6IS62LIM	BUFFER[2321]	// (TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define idiEM_TERR6IS62LIM	646	// (TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define iEM_TERR6IS64LIM	BUFFER[2324]	// (TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define idiEM_TERR6IS64LIM	647	// (TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define iEM_TERR6IS66LIM	BUFFER[2327]	// (TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idiEM_TERR6IS66LIM	648	// (TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define iEM_TERR6IS67LIM	BUFFER[2330]	// (TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idiEM_TERR6IS67LIM	649	// (TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define iEM_TERR6IS68LIM	BUFFER[2333]	// (TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define idiEM_TERR6IS68LIM	650	// (TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define iEM_TERR6SS21LIM	BUFFER[2336]	// (TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define idiEM_TERR6SS21LIM	651	// (TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define iEM_TERR7SI74RIM	BUFFER[2339]	// (TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define idiEM_TERR7SI74RIM	652	// (TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define iEM_TERR8SS11LIM	BUFFER[2342]	// (TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define idiEM_TERR8SS11LIM	653	// (TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define iEM_TERRB1	BUFFER[2345]	// (TERRB1) Неисправности  РБ1
#define idiEM_TERRB1	654	// (TERRB1) Неисправности  РБ1
#define iEM_TERRB2	BUFFER[2348]	// (TERRB2) Неисправности  РБ2
#define idiEM_TERRB2	655	// (TERRB2) Неисправности  РБ2
#define iEM_TERTLG	BUFFER[2351]	// (TERTLG) Неисправности  тележки от ИС
#define idiEM_TERTLG	656	// (TERTLG) Неисправности  тележки от ИС
#define internal1_m1010_Out10	BUFFER[2354]	// (internal1_m1010_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1010_Out10	657	// (internal1_m1010_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1011_Out10	BUFFER[2356]	// (internal1_m1011_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1011_Out10	658	// (internal1_m1011_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1012_Out10	BUFFER[2358]	// (internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1012_Out10	659	// (internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1013_Out10	BUFFER[2360]	// (internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1013_Out10	660	// (internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1014_Out10	BUFFER[2362]	// (internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1014_Out10	661	// (internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1015_Out10	BUFFER[2364]	// (internal1_m1015_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1015_Out10	662	// (internal1_m1015_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1016_Out10	BUFFER[2366]	// (internal1_m1016_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1016_Out10	663	// (internal1_m1016_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1030_Out10	BUFFER[2368]	// (internal1_m1030_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1030_Out10	664	// (internal1_m1030_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1031_Out10	BUFFER[2370]	// (internal1_m1031_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1031_Out10	665	// (internal1_m1031_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1032_Out10	BUFFER[2372]	// (internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1032_Out10	666	// (internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1033_Out10	BUFFER[2374]	// (internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1033_Out10	667	// (internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1034_Out10	BUFFER[2376]	// (internal1_m1034_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1034_Out10	668	// (internal1_m1034_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1035_Out10	BUFFER[2378]	// (internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1035_Out10	669	// (internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m132_MyFirstEnterFlag	BUFFER[2380]	// (internal1_m132_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m132_MyFirstEnterFlag	670	// (internal1_m132_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m132_Pav0	BUFFER[2382]	// (internal1_m132_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m132_Pav0	671	// (internal1_m132_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m132_Ppv0	BUFFER[2384]	// (internal1_m132_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m132_Ppv0	672	// (internal1_m132_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m132_RA00	BUFFER[2386]	// (internal1_m132_RA00) RA00 - последнее задание вперед
#define idinternal1_m132_RA00	673	// (internal1_m132_RA00) RA00 - последнее задание вперед
#define internal1_m132_RA10	BUFFER[2388]	// (internal1_m132_RA10) RA10 - последнее задание назад
#define idinternal1_m132_RA10	674	// (internal1_m132_RA10) RA10 - последнее задание назад
#define internal1_m132_RA30	BUFFER[2390]	// (internal1_m132_RA30)  RA30 - разрешение движения
#define idinternal1_m132_RA30	675	// (internal1_m132_RA30)  RA30 - разрешение движения
#define internal1_m132_RA50	BUFFER[2392]	// (internal1_m132_RA50) Ra50 - последнее задание скорости
#define idinternal1_m132_RA50	676	// (internal1_m132_RA50) Ra50 - последнее задание скорости
#define internal1_m132_RV00	BUFFER[2394]	// (internal1_m132_RV00) V0 - текущая скорость ОРР
#define idinternal1_m132_RV00	677	// (internal1_m132_RV00) V0 - текущая скорость ОРР
#define internal1_m132_Sh00	BUFFER[2399]	// (internal1_m132_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m132_Sh00	678	// (internal1_m132_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m132_ShV00	BUFFER[2404]	// (internal1_m132_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m132_ShV00	679	// (internal1_m132_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m132_X00	BUFFER[2409]	// (internal1_m132_X00) X0 - текущая координата ОРР
#define idinternal1_m132_X00	680	// (internal1_m132_X00) X0 - текущая координата ОРР
#define internal1_m132_Zav0	BUFFER[2414]	// (internal1_m132_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m132_Zav0	681	// (internal1_m132_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m132_flp	BUFFER[2416]	// (internal1_m132_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m132_flp	682	// (internal1_m132_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m132_fls	BUFFER[2418]	// (internal1_m132_fls)  fls - флаг одношагового режима
#define idinternal1_m132_fls	683	// (internal1_m132_fls)  fls - флаг одношагового режима
#define internal1_m14_C1	BUFFER[2420]	// (internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m14_C1	684	// (internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m14_C2	BUFFER[2425]	// (internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m14_C2	685	// (internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m14_C3	BUFFER[2430]	// (internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m14_C3	686	// (internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m14_C4	BUFFER[2435]	// (internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m14_C4	687	// (internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m14_C5	BUFFER[2440]	// (internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m14_C5	688	// (internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m14_C6	BUFFER[2445]	// (internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m14_C6	689	// (internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m14_ImpINI0	BUFFER[2450]	// (internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m14_ImpINI0	690	// (internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m14_MyFirstEnterFlag	BUFFER[2452]	// (internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m14_MyFirstEnterFlag	691	// (internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m14_N00	BUFFER[2454]	// (internal1_m14_N00) N00 - Текущая концентрация нейтронов
#define idinternal1_m14_N00	692	// (internal1_m14_N00) N00 - Текущая концентрация нейтронов
#define internal1_m14_N20	BUFFER[2459]	// (internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m14_N20	693	// (internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m14_R00	BUFFER[2464]	// (internal1_m14_R00) R00 - Текущая реактивность
#define idinternal1_m14_R00	694	// (internal1_m14_R00) R00 - Текущая реактивность
#define internal1_m14_T00	BUFFER[2469]	// (internal1_m14_T00) T00 - Текущая температура
#define idinternal1_m14_T00	695	// (internal1_m14_T00) T00 - Текущая температура
#define internal1_m150_Out10	BUFFER[2474]	// (internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m150_Out10	696	// (internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m151_Out10	BUFFER[2476]	// (internal1_m151_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m151_Out10	697	// (internal1_m151_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m184_C1	BUFFER[2478]	// (internal1_m184_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m184_C1	698	// (internal1_m184_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m184_C2	BUFFER[2483]	// (internal1_m184_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m184_C2	699	// (internal1_m184_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m184_C3	BUFFER[2488]	// (internal1_m184_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m184_C3	700	// (internal1_m184_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m184_C4	BUFFER[2493]	// (internal1_m184_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m184_C4	701	// (internal1_m184_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m184_C5	BUFFER[2498]	// (internal1_m184_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m184_C5	702	// (internal1_m184_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m184_C6	BUFFER[2503]	// (internal1_m184_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m184_C6	703	// (internal1_m184_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m184_ImpINI0	BUFFER[2508]	// (internal1_m184_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m184_ImpINI0	704	// (internal1_m184_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m184_MyFirstEnterFlag	BUFFER[2510]	// (internal1_m184_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m184_MyFirstEnterFlag	705	// (internal1_m184_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m184_N00	BUFFER[2512]	// (internal1_m184_N00) N00 - Текущая концентрация нейтронов
#define idinternal1_m184_N00	706	// (internal1_m184_N00) N00 - Текущая концентрация нейтронов
#define internal1_m184_N20	BUFFER[2517]	// (internal1_m184_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m184_N20	707	// (internal1_m184_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m184_R00	BUFFER[2522]	// (internal1_m184_R00) R00 - Текущая реактивность
#define idinternal1_m184_R00	708	// (internal1_m184_R00) R00 - Текущая реактивность
#define internal1_m184_T00	BUFFER[2527]	// (internal1_m184_T00) T00 - Текущая температура
#define idinternal1_m184_T00	709	// (internal1_m184_T00) T00 - Текущая температура
#define internal1_m209_Out10	BUFFER[2532]	// (internal1_m209_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m209_Out10	710	// (internal1_m209_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m227_Out10	BUFFER[2534]	// (internal1_m227_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m227_Out10	711	// (internal1_m227_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m230_MyFirstEnterFlag	BUFFER[2536]	// (internal1_m230_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m230_MyFirstEnterFlag	712	// (internal1_m230_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m230_Pav0	BUFFER[2538]	// (internal1_m230_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m230_Pav0	713	// (internal1_m230_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m230_Ppv0	BUFFER[2540]	// (internal1_m230_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m230_Ppv0	714	// (internal1_m230_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m230_RA00	BUFFER[2542]	// (internal1_m230_RA00) RA00 - последнее задание вперед
#define idinternal1_m230_RA00	715	// (internal1_m230_RA00) RA00 - последнее задание вперед
#define internal1_m230_RA10	BUFFER[2544]	// (internal1_m230_RA10) RA10 - последнее задание назад
#define idinternal1_m230_RA10	716	// (internal1_m230_RA10) RA10 - последнее задание назад
#define internal1_m230_RA30	BUFFER[2546]	// (internal1_m230_RA30)  RA30 - разрешение движения
#define idinternal1_m230_RA30	717	// (internal1_m230_RA30)  RA30 - разрешение движения
#define internal1_m230_RA50	BUFFER[2548]	// (internal1_m230_RA50) Ra50 - последнее задание скорости
#define idinternal1_m230_RA50	718	// (internal1_m230_RA50) Ra50 - последнее задание скорости
#define internal1_m230_RV00	BUFFER[2550]	// (internal1_m230_RV00) V0 - текущая скорость ОРР
#define idinternal1_m230_RV00	719	// (internal1_m230_RV00) V0 - текущая скорость ОРР
#define internal1_m230_Sh00	BUFFER[2555]	// (internal1_m230_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m230_Sh00	720	// (internal1_m230_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m230_ShV00	BUFFER[2560]	// (internal1_m230_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m230_ShV00	721	// (internal1_m230_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m230_X00	BUFFER[2565]	// (internal1_m230_X00) X0 - текущая координата ОРР
#define idinternal1_m230_X00	722	// (internal1_m230_X00) X0 - текущая координата ОРР
#define internal1_m230_Zav0	BUFFER[2570]	// (internal1_m230_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m230_Zav0	723	// (internal1_m230_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m230_flp	BUFFER[2572]	// (internal1_m230_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m230_flp	724	// (internal1_m230_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m230_fls	BUFFER[2574]	// (internal1_m230_fls)  fls - флаг одношагового режима
#define idinternal1_m230_fls	725	// (internal1_m230_fls)  fls - флаг одношагового режима
#define internal1_m265_MyFirstEnterFlag	BUFFER[2576]	// (internal1_m265_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m265_MyFirstEnterFlag	726	// (internal1_m265_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m265_Pav0	BUFFER[2578]	// (internal1_m265_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m265_Pav0	727	// (internal1_m265_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m265_Ppv0	BUFFER[2580]	// (internal1_m265_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m265_Ppv0	728	// (internal1_m265_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m265_RA00	BUFFER[2582]	// (internal1_m265_RA00) RA00 - последнее задание вперед
#define idinternal1_m265_RA00	729	// (internal1_m265_RA00) RA00 - последнее задание вперед
#define internal1_m265_RA10	BUFFER[2584]	// (internal1_m265_RA10) RA10 - последнее задание назад
#define idinternal1_m265_RA10	730	// (internal1_m265_RA10) RA10 - последнее задание назад
#define internal1_m265_RA30	BUFFER[2586]	// (internal1_m265_RA30)  RA30 - разрешение движения
#define idinternal1_m265_RA30	731	// (internal1_m265_RA30)  RA30 - разрешение движения
#define internal1_m265_RA50	BUFFER[2588]	// (internal1_m265_RA50) Ra50 - последнее задание скорости
#define idinternal1_m265_RA50	732	// (internal1_m265_RA50) Ra50 - последнее задание скорости
#define internal1_m265_RV00	BUFFER[2590]	// (internal1_m265_RV00) V0 - текущая скорость ОРР
#define idinternal1_m265_RV00	733	// (internal1_m265_RV00) V0 - текущая скорость ОРР
#define internal1_m265_Sh00	BUFFER[2595]	// (internal1_m265_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m265_Sh00	734	// (internal1_m265_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m265_ShV00	BUFFER[2600]	// (internal1_m265_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m265_ShV00	735	// (internal1_m265_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m265_X00	BUFFER[2605]	// (internal1_m265_X00) X0 - текущая координата ОРР
#define idinternal1_m265_X00	736	// (internal1_m265_X00) X0 - текущая координата ОРР
#define internal1_m265_Zav0	BUFFER[2610]	// (internal1_m265_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m265_Zav0	737	// (internal1_m265_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m265_flp	BUFFER[2612]	// (internal1_m265_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m265_flp	738	// (internal1_m265_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m265_fls	BUFFER[2614]	// (internal1_m265_fls)  fls - флаг одношагового режима
#define idinternal1_m265_fls	739	// (internal1_m265_fls)  fls - флаг одношагового режима
#define internal1_m301_MyFirstEnterFlag	BUFFER[2616]	// (internal1_m301_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m301_MyFirstEnterFlag	740	// (internal1_m301_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m301_Pav0	BUFFER[2618]	// (internal1_m301_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m301_Pav0	741	// (internal1_m301_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m301_Ppv0	BUFFER[2620]	// (internal1_m301_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m301_Ppv0	742	// (internal1_m301_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m301_RA00	BUFFER[2622]	// (internal1_m301_RA00) RA00 - последнее задание вперед
#define idinternal1_m301_RA00	743	// (internal1_m301_RA00) RA00 - последнее задание вперед
#define internal1_m301_RA10	BUFFER[2624]	// (internal1_m301_RA10) RA10 - последнее задание назад
#define idinternal1_m301_RA10	744	// (internal1_m301_RA10) RA10 - последнее задание назад
#define internal1_m301_RA30	BUFFER[2626]	// (internal1_m301_RA30)  RA30 - разрешение движения
#define idinternal1_m301_RA30	745	// (internal1_m301_RA30)  RA30 - разрешение движения
#define internal1_m301_RA50	BUFFER[2628]	// (internal1_m301_RA50) Ra50 - последнее задание скорости
#define idinternal1_m301_RA50	746	// (internal1_m301_RA50) Ra50 - последнее задание скорости
#define internal1_m301_RV00	BUFFER[2630]	// (internal1_m301_RV00) V0 - текущая скорость ОРР
#define idinternal1_m301_RV00	747	// (internal1_m301_RV00) V0 - текущая скорость ОРР
#define internal1_m301_Sh00	BUFFER[2635]	// (internal1_m301_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m301_Sh00	748	// (internal1_m301_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m301_ShV00	BUFFER[2640]	// (internal1_m301_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m301_ShV00	749	// (internal1_m301_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m301_X00	BUFFER[2645]	// (internal1_m301_X00) X0 - текущая координата ОРР
#define idinternal1_m301_X00	750	// (internal1_m301_X00) X0 - текущая координата ОРР
#define internal1_m301_Zav0	BUFFER[2650]	// (internal1_m301_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m301_Zav0	751	// (internal1_m301_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m301_flp	BUFFER[2652]	// (internal1_m301_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m301_flp	752	// (internal1_m301_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m301_fls	BUFFER[2654]	// (internal1_m301_fls)  fls - флаг одношагового режима
#define idinternal1_m301_fls	753	// (internal1_m301_fls)  fls - флаг одношагового режима
#define internal1_m317_Out10	BUFFER[2656]	// (internal1_m317_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m317_Out10	754	// (internal1_m317_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m318_Out10	BUFFER[2658]	// (internal1_m318_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m318_Out10	755	// (internal1_m318_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m319_Out10	BUFFER[2660]	// (internal1_m319_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m319_Out10	756	// (internal1_m319_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m325_Xtek0	BUFFER[2662]	// (internal1_m325_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m325_Xtek0	757	// (internal1_m325_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m332_Xtek0	BUFFER[2667]	// (internal1_m332_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m332_Xtek0	758	// (internal1_m332_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m333_Out10	BUFFER[2672]	// (internal1_m333_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m333_Out10	759	// (internal1_m333_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m334_Out10	BUFFER[2674]	// (internal1_m334_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m334_Out10	760	// (internal1_m334_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m335_Out10	BUFFER[2676]	// (internal1_m335_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m335_Out10	761	// (internal1_m335_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m345_Out10	BUFFER[2678]	// (internal1_m345_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m345_Out10	762	// (internal1_m345_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m346_Out10	BUFFER[2680]	// (internal1_m346_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m346_Out10	763	// (internal1_m346_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m347_Out10	BUFFER[2682]	// (internal1_m347_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m347_Out10	764	// (internal1_m347_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m348_Out10	BUFFER[2684]	// (internal1_m348_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m348_Out10	765	// (internal1_m348_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m362_MyFirstEnterFlag	BUFFER[2686]	// (internal1_m362_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m362_MyFirstEnterFlag	766	// (internal1_m362_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m362_Pav0	BUFFER[2688]	// (internal1_m362_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m362_Pav0	767	// (internal1_m362_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m362_Pv0	BUFFER[2690]	// (internal1_m362_Pv0)  - Пер. выключатель механизма
#define idinternal1_m362_Pv0	768	// (internal1_m362_Pv0)  - Пер. выключатель механизма
#define internal1_m362_RA00	BUFFER[2692]	// (internal1_m362_RA00)  - последнее задание вперед
#define idinternal1_m362_RA00	769	// (internal1_m362_RA00)  - последнее задание вперед
#define internal1_m362_RA10	BUFFER[2694]	// (internal1_m362_RA10)  - последнее задание назад
#define idinternal1_m362_RA10	770	// (internal1_m362_RA10)  - последнее задание назад
#define internal1_m362_V00	BUFFER[2696]	// (internal1_m362_V00)  V00 - текущая скорость механизма
#define idinternal1_m362_V00	771	// (internal1_m362_V00)  V00 - текущая скорость механизма
#define internal1_m362_X00	BUFFER[2701]	// (internal1_m362_X00)  X00 - текущая координата механизма
#define idinternal1_m362_X00	772	// (internal1_m362_X00)  X00 - текущая координата механизма
#define internal1_m362_Zav0	BUFFER[2706]	// (internal1_m362_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m362_Zav0	773	// (internal1_m362_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m362_Zv0	BUFFER[2708]	// (internal1_m362_Zv0)  - Зад. выключатель механизма
#define idinternal1_m362_Zv0	774	// (internal1_m362_Zv0)  - Зад. выключатель механизма
#define internal1_m378_MyFirstEnterFlag	BUFFER[2710]	// (internal1_m378_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m378_MyFirstEnterFlag	775	// (internal1_m378_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m378_Pav0	BUFFER[2712]	// (internal1_m378_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m378_Pav0	776	// (internal1_m378_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m378_Pv0	BUFFER[2714]	// (internal1_m378_Pv0)  - Пер. выключатель механизма
#define idinternal1_m378_Pv0	777	// (internal1_m378_Pv0)  - Пер. выключатель механизма
#define internal1_m378_RA00	BUFFER[2716]	// (internal1_m378_RA00)  - последнее задание вперед
#define idinternal1_m378_RA00	778	// (internal1_m378_RA00)  - последнее задание вперед
#define internal1_m378_RA10	BUFFER[2718]	// (internal1_m378_RA10)  - последнее задание назад
#define idinternal1_m378_RA10	779	// (internal1_m378_RA10)  - последнее задание назад
#define internal1_m378_V00	BUFFER[2720]	// (internal1_m378_V00)  V00 - текущая скорость механизма
#define idinternal1_m378_V00	780	// (internal1_m378_V00)  V00 - текущая скорость механизма
#define internal1_m378_X00	BUFFER[2725]	// (internal1_m378_X00)  X00 - текущая координата механизма
#define idinternal1_m378_X00	781	// (internal1_m378_X00)  X00 - текущая координата механизма
#define internal1_m378_Zav0	BUFFER[2730]	// (internal1_m378_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m378_Zav0	782	// (internal1_m378_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m378_Zv0	BUFFER[2732]	// (internal1_m378_Zv0)  - Зад. выключатель механизма
#define idinternal1_m378_Zv0	783	// (internal1_m378_Zv0)  - Зад. выключатель механизма
#define internal1_m38_fef	BUFFER[2734]	// (internal1_m38_fef) fef
#define idinternal1_m38_fef	784	// (internal1_m38_fef) fef
#define internal1_m38_reg	BUFFER[2736]	// (internal1_m38_reg) режим работы квдс 0 - ожидание сигнала 1- выдан импульс 2 отсчет удержания синхроимпульса 3 -блокировка
#define idinternal1_m38_reg	785	// (internal1_m38_reg) режим работы квдс 0 - ожидание сигнала 1- выдан импульс 2 отсчет удержания синхроимпульса 3 -блокировка
#define internal1_m38_tgen	BUFFER[2739]	// (internal1_m38_tgen) задержки срабатывания генератора импульса
#define idinternal1_m38_tgen	786	// (internal1_m38_tgen) задержки срабатывания генератора импульса
#define internal1_m38_tlock	BUFFER[2744]	// (internal1_m38_tlock) время до конца блокировки
#define idinternal1_m38_tlock	787	// (internal1_m38_tlock) время до конца блокировки
#define internal1_m38_tsin	BUFFER[2749]	// (internal1_m38_tsin) время до конца удержания синхроимпульса
#define idinternal1_m38_tsin	788	// (internal1_m38_tsin) время до конца удержания синхроимпульса
#define internal1_m393_MyFirstEnterFlag	BUFFER[2754]	// (internal1_m393_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m393_MyFirstEnterFlag	789	// (internal1_m393_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m393_Pav0	BUFFER[2756]	// (internal1_m393_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m393_Pav0	790	// (internal1_m393_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m393_Pv0	BUFFER[2758]	// (internal1_m393_Pv0)  - Пер. выключатель механизма
#define idinternal1_m393_Pv0	791	// (internal1_m393_Pv0)  - Пер. выключатель механизма
#define internal1_m393_RA00	BUFFER[2760]	// (internal1_m393_RA00)  - последнее задание вперед
#define idinternal1_m393_RA00	792	// (internal1_m393_RA00)  - последнее задание вперед
#define internal1_m393_RA10	BUFFER[2762]	// (internal1_m393_RA10)  - последнее задание назад
#define idinternal1_m393_RA10	793	// (internal1_m393_RA10)  - последнее задание назад
#define internal1_m393_V00	BUFFER[2764]	// (internal1_m393_V00)  V00 - текущая скорость механизма
#define idinternal1_m393_V00	794	// (internal1_m393_V00)  V00 - текущая скорость механизма
#define internal1_m393_X00	BUFFER[2769]	// (internal1_m393_X00)  X00 - текущая координата механизма
#define idinternal1_m393_X00	795	// (internal1_m393_X00)  X00 - текущая координата механизма
#define internal1_m393_Zav0	BUFFER[2774]	// (internal1_m393_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m393_Zav0	796	// (internal1_m393_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m393_Zv0	BUFFER[2776]	// (internal1_m393_Zv0)  - Зад. выключатель механизма
#define idinternal1_m393_Zv0	797	// (internal1_m393_Zv0)  - Зад. выключатель механизма
#define internal1_m404_Out10	BUFFER[2778]	// (internal1_m404_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m404_Out10	798	// (internal1_m404_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m405_Out10	BUFFER[2780]	// (internal1_m405_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m405_Out10	799	// (internal1_m405_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m406_Out10	BUFFER[2782]	// (internal1_m406_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m406_Out10	800	// (internal1_m406_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m407_Out10	BUFFER[2784]	// (internal1_m407_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m407_Out10	801	// (internal1_m407_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m414_Xtek0	BUFFER[2786]	// (internal1_m414_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m414_Xtek0	802	// (internal1_m414_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m423_Out10	BUFFER[2791]	// (internal1_m423_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m423_Out10	803	// (internal1_m423_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m424_Out10	BUFFER[2793]	// (internal1_m424_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m424_Out10	804	// (internal1_m424_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m425_Out10	BUFFER[2795]	// (internal1_m425_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m425_Out10	805	// (internal1_m425_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m426_Out10	BUFFER[2797]	// (internal1_m426_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m426_Out10	806	// (internal1_m426_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m427_Xtek0	BUFFER[2799]	// (internal1_m427_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m427_Xtek0	807	// (internal1_m427_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m441_MyFirstEnterFlag	BUFFER[2804]	// (internal1_m441_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m441_MyFirstEnterFlag	808	// (internal1_m441_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m441_Pav0	BUFFER[2806]	// (internal1_m441_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m441_Pav0	809	// (internal1_m441_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m441_Pv0	BUFFER[2808]	// (internal1_m441_Pv0)  - Пер. выключатель механизма
#define idinternal1_m441_Pv0	810	// (internal1_m441_Pv0)  - Пер. выключатель механизма
#define internal1_m441_RA00	BUFFER[2810]	// (internal1_m441_RA00)  - последнее задание вперед
#define idinternal1_m441_RA00	811	// (internal1_m441_RA00)  - последнее задание вперед
#define internal1_m441_RA10	BUFFER[2812]	// (internal1_m441_RA10)  - последнее задание назад
#define idinternal1_m441_RA10	812	// (internal1_m441_RA10)  - последнее задание назад
#define internal1_m441_V00	BUFFER[2814]	// (internal1_m441_V00)  V00 - текущая скорость механизма
#define idinternal1_m441_V00	813	// (internal1_m441_V00)  V00 - текущая скорость механизма
#define internal1_m441_X00	BUFFER[2819]	// (internal1_m441_X00)  X00 - текущая координата механизма
#define idinternal1_m441_X00	814	// (internal1_m441_X00)  X00 - текущая координата механизма
#define internal1_m441_Zav0	BUFFER[2824]	// (internal1_m441_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m441_Zav0	815	// (internal1_m441_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m441_Zv0	BUFFER[2826]	// (internal1_m441_Zv0)  - Зад. выключатель механизма
#define idinternal1_m441_Zv0	816	// (internal1_m441_Zv0)  - Зад. выключатель механизма
#define internal1_m455_MyFirstEnterFlag	BUFFER[2828]	// (internal1_m455_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m455_MyFirstEnterFlag	817	// (internal1_m455_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m455_Pav0	BUFFER[2830]	// (internal1_m455_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m455_Pav0	818	// (internal1_m455_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m455_Pv0	BUFFER[2832]	// (internal1_m455_Pv0)  - Пер. выключатель механизма
#define idinternal1_m455_Pv0	819	// (internal1_m455_Pv0)  - Пер. выключатель механизма
#define internal1_m455_RA00	BUFFER[2834]	// (internal1_m455_RA00)  - последнее задание вперед
#define idinternal1_m455_RA00	820	// (internal1_m455_RA00)  - последнее задание вперед
#define internal1_m455_RA10	BUFFER[2836]	// (internal1_m455_RA10)  - последнее задание назад
#define idinternal1_m455_RA10	821	// (internal1_m455_RA10)  - последнее задание назад
#define internal1_m455_V00	BUFFER[2838]	// (internal1_m455_V00)  V00 - текущая скорость механизма
#define idinternal1_m455_V00	822	// (internal1_m455_V00)  V00 - текущая скорость механизма
#define internal1_m455_X00	BUFFER[2843]	// (internal1_m455_X00)  X00 - текущая координата механизма
#define idinternal1_m455_X00	823	// (internal1_m455_X00)  X00 - текущая координата механизма
#define internal1_m455_Zav0	BUFFER[2848]	// (internal1_m455_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m455_Zav0	824	// (internal1_m455_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m455_Zv0	BUFFER[2850]	// (internal1_m455_Zv0)  - Зад. выключатель механизма
#define idinternal1_m455_Zv0	825	// (internal1_m455_Zv0)  - Зад. выключатель механизма
#define internal1_m465_q0	BUFFER[2852]	// (internal1_m465_q0) q0 - внутренний параметр
#define idinternal1_m465_q0	826	// (internal1_m465_q0) q0 - внутренний параметр
#define internal1_m466_q0	BUFFER[2854]	// (internal1_m466_q0) q0 - внутренний параметр
#define idinternal1_m466_q0	827	// (internal1_m466_q0) q0 - внутренний параметр
#define internal1_m46_Out10	BUFFER[2856]	// (internal1_m46_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m46_Out10	828	// (internal1_m46_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m470_MyFirstEnterFlag	BUFFER[2858]	// (internal1_m470_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m470_MyFirstEnterFlag	829	// (internal1_m470_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m470_Pav0	BUFFER[2860]	// (internal1_m470_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m470_Pav0	830	// (internal1_m470_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m470_Pv0	BUFFER[2862]	// (internal1_m470_Pv0)  - Пер. выключатель механизма
#define idinternal1_m470_Pv0	831	// (internal1_m470_Pv0)  - Пер. выключатель механизма
#define internal1_m470_RA00	BUFFER[2864]	// (internal1_m470_RA00)  - последнее задание вперед
#define idinternal1_m470_RA00	832	// (internal1_m470_RA00)  - последнее задание вперед
#define internal1_m470_RA10	BUFFER[2866]	// (internal1_m470_RA10)  - последнее задание назад
#define idinternal1_m470_RA10	833	// (internal1_m470_RA10)  - последнее задание назад
#define internal1_m470_V00	BUFFER[2868]	// (internal1_m470_V00)  V00 - текущая скорость механизма
#define idinternal1_m470_V00	834	// (internal1_m470_V00)  V00 - текущая скорость механизма
#define internal1_m470_X00	BUFFER[2873]	// (internal1_m470_X00)  X00 - текущая координата механизма
#define idinternal1_m470_X00	835	// (internal1_m470_X00)  X00 - текущая координата механизма
#define internal1_m470_Zav0	BUFFER[2878]	// (internal1_m470_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m470_Zav0	836	// (internal1_m470_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m470_Zv0	BUFFER[2880]	// (internal1_m470_Zv0)  - Зад. выключатель механизма
#define idinternal1_m470_Zv0	837	// (internal1_m470_Zv0)  - Зад. выключатель механизма
#define internal1_m471_MyFirstEnterFlag	BUFFER[2882]	// (internal1_m471_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m471_MyFirstEnterFlag	838	// (internal1_m471_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m471_Pav0	BUFFER[2884]	// (internal1_m471_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m471_Pav0	839	// (internal1_m471_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m471_Pv0	BUFFER[2886]	// (internal1_m471_Pv0)  - Пер. выключатель механизма
#define idinternal1_m471_Pv0	840	// (internal1_m471_Pv0)  - Пер. выключатель механизма
#define internal1_m471_RA00	BUFFER[2888]	// (internal1_m471_RA00)  - последнее задание вперед
#define idinternal1_m471_RA00	841	// (internal1_m471_RA00)  - последнее задание вперед
#define internal1_m471_RA10	BUFFER[2890]	// (internal1_m471_RA10)  - последнее задание назад
#define idinternal1_m471_RA10	842	// (internal1_m471_RA10)  - последнее задание назад
#define internal1_m471_V00	BUFFER[2892]	// (internal1_m471_V00)  V00 - текущая скорость механизма
#define idinternal1_m471_V00	843	// (internal1_m471_V00)  V00 - текущая скорость механизма
#define internal1_m471_X00	BUFFER[2897]	// (internal1_m471_X00)  X00 - текущая координата механизма
#define idinternal1_m471_X00	844	// (internal1_m471_X00)  X00 - текущая координата механизма
#define internal1_m471_Zav0	BUFFER[2902]	// (internal1_m471_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m471_Zav0	845	// (internal1_m471_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m471_Zv0	BUFFER[2904]	// (internal1_m471_Zv0)  - Зад. выключатель механизма
#define idinternal1_m471_Zv0	846	// (internal1_m471_Zv0)  - Зад. выключатель механизма
#define internal1_m477_q0	BUFFER[2906]	// (internal1_m477_q0) q0 - внутренний параметр
#define idinternal1_m477_q0	847	// (internal1_m477_q0) q0 - внутренний параметр
#define internal1_m478_q0	BUFFER[2908]	// (internal1_m478_q0) q0 - внутренний параметр
#define idinternal1_m478_q0	848	// (internal1_m478_q0) q0 - внутренний параметр
#define internal1_m481_MyFirstEnterFlag	BUFFER[2910]	// (internal1_m481_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m481_MyFirstEnterFlag	849	// (internal1_m481_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m481_Pav0	BUFFER[2912]	// (internal1_m481_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m481_Pav0	850	// (internal1_m481_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m481_Pv0	BUFFER[2914]	// (internal1_m481_Pv0)  - Пер. выключатель механизма
#define idinternal1_m481_Pv0	851	// (internal1_m481_Pv0)  - Пер. выключатель механизма
#define internal1_m481_RA00	BUFFER[2916]	// (internal1_m481_RA00)  - последнее задание вперед
#define idinternal1_m481_RA00	852	// (internal1_m481_RA00)  - последнее задание вперед
#define internal1_m481_RA10	BUFFER[2918]	// (internal1_m481_RA10)  - последнее задание назад
#define idinternal1_m481_RA10	853	// (internal1_m481_RA10)  - последнее задание назад
#define internal1_m481_V00	BUFFER[2920]	// (internal1_m481_V00)  V00 - текущая скорость механизма
#define idinternal1_m481_V00	854	// (internal1_m481_V00)  V00 - текущая скорость механизма
#define internal1_m481_X00	BUFFER[2925]	// (internal1_m481_X00)  X00 - текущая координата механизма
#define idinternal1_m481_X00	855	// (internal1_m481_X00)  X00 - текущая координата механизма
#define internal1_m481_Zav0	BUFFER[2930]	// (internal1_m481_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m481_Zav0	856	// (internal1_m481_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m481_Zv0	BUFFER[2932]	// (internal1_m481_Zv0)  - Зад. выключатель механизма
#define idinternal1_m481_Zv0	857	// (internal1_m481_Zv0)  - Зад. выключатель механизма
#define internal1_m492_MyFirstEnterFlag	BUFFER[2934]	// (internal1_m492_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m492_MyFirstEnterFlag	858	// (internal1_m492_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m492_Pav0	BUFFER[2936]	// (internal1_m492_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m492_Pav0	859	// (internal1_m492_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m492_Pv0	BUFFER[2938]	// (internal1_m492_Pv0)  - Пер. выключатель механизма
#define idinternal1_m492_Pv0	860	// (internal1_m492_Pv0)  - Пер. выключатель механизма
#define internal1_m492_RA00	BUFFER[2940]	// (internal1_m492_RA00)  - последнее задание вперед
#define idinternal1_m492_RA00	861	// (internal1_m492_RA00)  - последнее задание вперед
#define internal1_m492_RA10	BUFFER[2942]	// (internal1_m492_RA10)  - последнее задание назад
#define idinternal1_m492_RA10	862	// (internal1_m492_RA10)  - последнее задание назад
#define internal1_m492_V00	BUFFER[2944]	// (internal1_m492_V00)  V00 - текущая скорость механизма
#define idinternal1_m492_V00	863	// (internal1_m492_V00)  V00 - текущая скорость механизма
#define internal1_m492_X00	BUFFER[2949]	// (internal1_m492_X00)  X00 - текущая координата механизма
#define idinternal1_m492_X00	864	// (internal1_m492_X00)  X00 - текущая координата механизма
#define internal1_m492_Zav0	BUFFER[2954]	// (internal1_m492_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m492_Zav0	865	// (internal1_m492_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m492_Zv0	BUFFER[2956]	// (internal1_m492_Zv0)  - Зад. выключатель механизма
#define idinternal1_m492_Zv0	866	// (internal1_m492_Zv0)  - Зад. выключатель механизма
#define internal1_m516_Out10	BUFFER[2958]	// (internal1_m516_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m516_Out10	867	// (internal1_m516_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m532_Out10	BUFFER[2960]	// (internal1_m532_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m532_Out10	868	// (internal1_m532_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m533_Out10	BUFFER[2962]	// (internal1_m533_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m533_Out10	869	// (internal1_m533_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m548_Out10	BUFFER[2964]	// (internal1_m548_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m548_Out10	870	// (internal1_m548_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m549_Out10	BUFFER[2966]	// (internal1_m549_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m549_Out10	871	// (internal1_m549_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m550_Out10	BUFFER[2968]	// (internal1_m550_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m550_Out10	872	// (internal1_m550_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m564_MyFirstEnterFlag	BUFFER[2970]	// (internal1_m564_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m564_MyFirstEnterFlag	873	// (internal1_m564_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m564_Pav0	BUFFER[2972]	// (internal1_m564_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m564_Pav0	874	// (internal1_m564_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m564_Pv0	BUFFER[2974]	// (internal1_m564_Pv0)  - Пер. выключатель механизма
#define idinternal1_m564_Pv0	875	// (internal1_m564_Pv0)  - Пер. выключатель механизма
#define internal1_m564_RA00	BUFFER[2976]	// (internal1_m564_RA00)  - последнее задание вперед
#define idinternal1_m564_RA00	876	// (internal1_m564_RA00)  - последнее задание вперед
#define internal1_m564_RA10	BUFFER[2978]	// (internal1_m564_RA10)  - последнее задание назад
#define idinternal1_m564_RA10	877	// (internal1_m564_RA10)  - последнее задание назад
#define internal1_m564_V00	BUFFER[2980]	// (internal1_m564_V00)  V00 - текущая скорость механизма
#define idinternal1_m564_V00	878	// (internal1_m564_V00)  V00 - текущая скорость механизма
#define internal1_m564_X00	BUFFER[2985]	// (internal1_m564_X00)  X00 - текущая координата механизма
#define idinternal1_m564_X00	879	// (internal1_m564_X00)  X00 - текущая координата механизма
#define internal1_m564_Zav0	BUFFER[2990]	// (internal1_m564_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m564_Zav0	880	// (internal1_m564_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m564_Zv0	BUFFER[2992]	// (internal1_m564_Zv0)  - Зад. выключатель механизма
#define idinternal1_m564_Zv0	881	// (internal1_m564_Zv0)  - Зад. выключатель механизма
#define internal1_m578_MyFirstEnterFlag	BUFFER[2994]	// (internal1_m578_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m578_MyFirstEnterFlag	882	// (internal1_m578_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m578_Pav0	BUFFER[2996]	// (internal1_m578_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m578_Pav0	883	// (internal1_m578_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m578_Pv0	BUFFER[2998]	// (internal1_m578_Pv0)  - Пер. выключатель механизма
#define idinternal1_m578_Pv0	884	// (internal1_m578_Pv0)  - Пер. выключатель механизма
#define internal1_m578_RA00	BUFFER[3000]	// (internal1_m578_RA00)  - последнее задание вперед
#define idinternal1_m578_RA00	885	// (internal1_m578_RA00)  - последнее задание вперед
#define internal1_m578_RA10	BUFFER[3002]	// (internal1_m578_RA10)  - последнее задание назад
#define idinternal1_m578_RA10	886	// (internal1_m578_RA10)  - последнее задание назад
#define internal1_m578_V00	BUFFER[3004]	// (internal1_m578_V00)  V00 - текущая скорость механизма
#define idinternal1_m578_V00	887	// (internal1_m578_V00)  V00 - текущая скорость механизма
#define internal1_m578_X00	BUFFER[3009]	// (internal1_m578_X00)  X00 - текущая координата механизма
#define idinternal1_m578_X00	888	// (internal1_m578_X00)  X00 - текущая координата механизма
#define internal1_m578_Zav0	BUFFER[3014]	// (internal1_m578_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m578_Zav0	889	// (internal1_m578_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m578_Zv0	BUFFER[3016]	// (internal1_m578_Zv0)  - Зад. выключатель механизма
#define idinternal1_m578_Zv0	890	// (internal1_m578_Zv0)  - Зад. выключатель механизма
#define internal1_m590_MyFirstEnterFlag	BUFFER[3018]	// (internal1_m590_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m590_MyFirstEnterFlag	891	// (internal1_m590_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m590_Pav0	BUFFER[3020]	// (internal1_m590_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m590_Pav0	892	// (internal1_m590_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m590_Pv0	BUFFER[3022]	// (internal1_m590_Pv0)  - Пер. выключатель механизма
#define idinternal1_m590_Pv0	893	// (internal1_m590_Pv0)  - Пер. выключатель механизма
#define internal1_m590_RA00	BUFFER[3024]	// (internal1_m590_RA00)  - последнее задание вперед
#define idinternal1_m590_RA00	894	// (internal1_m590_RA00)  - последнее задание вперед
#define internal1_m590_RA10	BUFFER[3026]	// (internal1_m590_RA10)  - последнее задание назад
#define idinternal1_m590_RA10	895	// (internal1_m590_RA10)  - последнее задание назад
#define internal1_m590_V00	BUFFER[3028]	// (internal1_m590_V00)  V00 - текущая скорость механизма
#define idinternal1_m590_V00	896	// (internal1_m590_V00)  V00 - текущая скорость механизма
#define internal1_m590_X00	BUFFER[3033]	// (internal1_m590_X00)  X00 - текущая координата механизма
#define idinternal1_m590_X00	897	// (internal1_m590_X00)  X00 - текущая координата механизма
#define internal1_m590_Zav0	BUFFER[3038]	// (internal1_m590_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m590_Zav0	898	// (internal1_m590_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m590_Zv0	BUFFER[3040]	// (internal1_m590_Zv0)  - Зад. выключатель механизма
#define idinternal1_m590_Zv0	899	// (internal1_m590_Zv0)  - Зад. выключатель механизма
#define internal1_m591_MyFirstEnterFlag	BUFFER[3042]	// (internal1_m591_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m591_MyFirstEnterFlag	900	// (internal1_m591_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m591_Pav0	BUFFER[3044]	// (internal1_m591_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m591_Pav0	901	// (internal1_m591_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m591_Pv0	BUFFER[3046]	// (internal1_m591_Pv0)  - Пер. выключатель механизма
#define idinternal1_m591_Pv0	902	// (internal1_m591_Pv0)  - Пер. выключатель механизма
#define internal1_m591_RA00	BUFFER[3048]	// (internal1_m591_RA00)  - последнее задание вперед
#define idinternal1_m591_RA00	903	// (internal1_m591_RA00)  - последнее задание вперед
#define internal1_m591_RA10	BUFFER[3050]	// (internal1_m591_RA10)  - последнее задание назад
#define idinternal1_m591_RA10	904	// (internal1_m591_RA10)  - последнее задание назад
#define internal1_m591_V00	BUFFER[3052]	// (internal1_m591_V00)  V00 - текущая скорость механизма
#define idinternal1_m591_V00	905	// (internal1_m591_V00)  V00 - текущая скорость механизма
#define internal1_m591_X00	BUFFER[3057]	// (internal1_m591_X00)  X00 - текущая координата механизма
#define idinternal1_m591_X00	906	// (internal1_m591_X00)  X00 - текущая координата механизма
#define internal1_m591_Zav0	BUFFER[3062]	// (internal1_m591_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m591_Zav0	907	// (internal1_m591_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m591_Zv0	BUFFER[3064]	// (internal1_m591_Zv0)  - Зад. выключатель механизма
#define idinternal1_m591_Zv0	908	// (internal1_m591_Zv0)  - Зад. выключатель механизма
#define internal1_m599_tx	BUFFER[3066]	// (internal1_m599_tx) tx - время накопленное сек
#define idinternal1_m599_tx	909	// (internal1_m599_tx) tx - время накопленное сек
#define internal1_m599_y0	BUFFER[3071]	// (internal1_m599_y0) y0
#define idinternal1_m599_y0	910	// (internal1_m599_y0) y0
#define internal1_m601_tx	BUFFER[3073]	// (internal1_m601_tx) tx - время накопленное сек
#define idinternal1_m601_tx	911	// (internal1_m601_tx) tx - время накопленное сек
#define internal1_m601_y0	BUFFER[3078]	// (internal1_m601_y0) y0
#define idinternal1_m601_y0	912	// (internal1_m601_y0) y0
#define internal1_m603_MyFirstEnterFlag	BUFFER[3080]	// (internal1_m603_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m603_MyFirstEnterFlag	913	// (internal1_m603_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m603_Pav0	BUFFER[3082]	// (internal1_m603_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m603_Pav0	914	// (internal1_m603_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m603_Pv0	BUFFER[3084]	// (internal1_m603_Pv0)  - Пер. выключатель механизма
#define idinternal1_m603_Pv0	915	// (internal1_m603_Pv0)  - Пер. выключатель механизма
#define internal1_m603_RA00	BUFFER[3086]	// (internal1_m603_RA00)  - последнее задание вперед
#define idinternal1_m603_RA00	916	// (internal1_m603_RA00)  - последнее задание вперед
#define internal1_m603_RA10	BUFFER[3088]	// (internal1_m603_RA10)  - последнее задание назад
#define idinternal1_m603_RA10	917	// (internal1_m603_RA10)  - последнее задание назад
#define internal1_m603_V00	BUFFER[3090]	// (internal1_m603_V00)  V00 - текущая скорость механизма
#define idinternal1_m603_V00	918	// (internal1_m603_V00)  V00 - текущая скорость механизма
#define internal1_m603_X00	BUFFER[3095]	// (internal1_m603_X00)  X00 - текущая координата механизма
#define idinternal1_m603_X00	919	// (internal1_m603_X00)  X00 - текущая координата механизма
#define internal1_m603_Zav0	BUFFER[3100]	// (internal1_m603_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m603_Zav0	920	// (internal1_m603_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m603_Zv0	BUFFER[3102]	// (internal1_m603_Zv0)  - Зад. выключатель механизма
#define idinternal1_m603_Zv0	921	// (internal1_m603_Zv0)  - Зад. выключатель механизма
#define internal1_m604_MyFirstEnterFlag	BUFFER[3104]	// (internal1_m604_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m604_MyFirstEnterFlag	922	// (internal1_m604_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m604_Pav0	BUFFER[3106]	// (internal1_m604_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m604_Pav0	923	// (internal1_m604_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m604_Pv0	BUFFER[3108]	// (internal1_m604_Pv0)  - Пер. выключатель механизма
#define idinternal1_m604_Pv0	924	// (internal1_m604_Pv0)  - Пер. выключатель механизма
#define internal1_m604_RA00	BUFFER[3110]	// (internal1_m604_RA00)  - последнее задание вперед
#define idinternal1_m604_RA00	925	// (internal1_m604_RA00)  - последнее задание вперед
#define internal1_m604_RA10	BUFFER[3112]	// (internal1_m604_RA10)  - последнее задание назад
#define idinternal1_m604_RA10	926	// (internal1_m604_RA10)  - последнее задание назад
#define internal1_m604_V00	BUFFER[3114]	// (internal1_m604_V00)  V00 - текущая скорость механизма
#define idinternal1_m604_V00	927	// (internal1_m604_V00)  V00 - текущая скорость механизма
#define internal1_m604_X00	BUFFER[3119]	// (internal1_m604_X00)  X00 - текущая координата механизма
#define idinternal1_m604_X00	928	// (internal1_m604_X00)  X00 - текущая координата механизма
#define internal1_m604_Zav0	BUFFER[3124]	// (internal1_m604_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m604_Zav0	929	// (internal1_m604_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m604_Zv0	BUFFER[3126]	// (internal1_m604_Zv0)  - Зад. выключатель механизма
#define idinternal1_m604_Zv0	930	// (internal1_m604_Zv0)  - Зад. выключатель механизма
#define internal1_m613_tx	BUFFER[3128]	// (internal1_m613_tx) tx - время накопленное сек
#define idinternal1_m613_tx	931	// (internal1_m613_tx) tx - время накопленное сек
#define internal1_m613_y0	BUFFER[3133]	// (internal1_m613_y0) y0
#define idinternal1_m613_y0	932	// (internal1_m613_y0) y0
#define internal1_m61_Out10	BUFFER[3135]	// (internal1_m61_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m61_Out10	933	// (internal1_m61_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m625_tx	BUFFER[3137]	// (internal1_m625_tx) tx - время накопленное сек
#define idinternal1_m625_tx	934	// (internal1_m625_tx) tx - время накопленное сек
#define internal1_m625_y0	BUFFER[3142]	// (internal1_m625_y0) y0
#define idinternal1_m625_y0	935	// (internal1_m625_y0) y0
#define internal1_m632_y0	BUFFER[3144]	// (internal1_m632_y0) y0 - внутренний параметр
#define idinternal1_m632_y0	936	// (internal1_m632_y0) y0 - внутренний параметр
#define internal1_m646_Out10	BUFFER[3149]	// (internal1_m646_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m646_Out10	937	// (internal1_m646_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m647_Out10	BUFFER[3151]	// (internal1_m647_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m647_Out10	938	// (internal1_m647_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m648_Out10	BUFFER[3153]	// (internal1_m648_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m648_Out10	939	// (internal1_m648_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m649_Out10	BUFFER[3155]	// (internal1_m649_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m649_Out10	940	// (internal1_m649_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m64_MyFirstEnterFlag	BUFFER[3157]	// (internal1_m64_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m64_MyFirstEnterFlag	941	// (internal1_m64_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m64_Pav0	BUFFER[3159]	// (internal1_m64_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m64_Pav0	942	// (internal1_m64_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m64_Ppv0	BUFFER[3161]	// (internal1_m64_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m64_Ppv0	943	// (internal1_m64_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m64_RA00	BUFFER[3163]	// (internal1_m64_RA00) RA00 - последнее задание вперед
#define idinternal1_m64_RA00	944	// (internal1_m64_RA00) RA00 - последнее задание вперед
#define internal1_m64_RA10	BUFFER[3165]	// (internal1_m64_RA10) RA10 - последнее задание назад
#define idinternal1_m64_RA10	945	// (internal1_m64_RA10) RA10 - последнее задание назад
#define internal1_m64_RA30	BUFFER[3167]	// (internal1_m64_RA30)  RA30 - разрешение движения
#define idinternal1_m64_RA30	946	// (internal1_m64_RA30)  RA30 - разрешение движения
#define internal1_m64_RA50	BUFFER[3169]	// (internal1_m64_RA50) Ra50 - последнее задание скорости
#define idinternal1_m64_RA50	947	// (internal1_m64_RA50) Ra50 - последнее задание скорости
#define internal1_m64_RV00	BUFFER[3171]	// (internal1_m64_RV00) V0 - текущая скорость ОРР
#define idinternal1_m64_RV00	948	// (internal1_m64_RV00) V0 - текущая скорость ОРР
#define internal1_m64_Sh00	BUFFER[3176]	// (internal1_m64_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m64_Sh00	949	// (internal1_m64_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m64_ShV00	BUFFER[3181]	// (internal1_m64_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m64_ShV00	950	// (internal1_m64_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m64_X00	BUFFER[3186]	// (internal1_m64_X00) X0 - текущая координата ОРР
#define idinternal1_m64_X00	951	// (internal1_m64_X00) X0 - текущая координата ОРР
#define internal1_m64_Zav0	BUFFER[3191]	// (internal1_m64_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m64_Zav0	952	// (internal1_m64_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m64_flp	BUFFER[3193]	// (internal1_m64_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m64_flp	953	// (internal1_m64_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m64_fls	BUFFER[3195]	// (internal1_m64_fls)  fls - флаг одношагового режима
#define idinternal1_m64_fls	954	// (internal1_m64_fls)  fls - флаг одношагового режима
#define internal1_m650_Out10	BUFFER[3197]	// (internal1_m650_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m650_Out10	955	// (internal1_m650_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m651_Out10	BUFFER[3199]	// (internal1_m651_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m651_Out10	956	// (internal1_m651_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m666_Out10	BUFFER[3201]	// (internal1_m666_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m666_Out10	957	// (internal1_m666_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m667_Out10	BUFFER[3203]	// (internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m667_Out10	958	// (internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m670_Out10	BUFFER[3205]	// (internal1_m670_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m670_Out10	959	// (internal1_m670_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m671_Out10	BUFFER[3207]	// (internal1_m671_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m671_Out10	960	// (internal1_m671_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m672_Out10	BUFFER[3209]	// (internal1_m672_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m672_Out10	961	// (internal1_m672_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m673_Out10	BUFFER[3211]	// (internal1_m673_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m673_Out10	962	// (internal1_m673_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m683_Out10	BUFFER[3213]	// (internal1_m683_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m683_Out10	963	// (internal1_m683_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m684_Out10	BUFFER[3215]	// (internal1_m684_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m684_Out10	964	// (internal1_m684_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m685_Out10	BUFFER[3217]	// (internal1_m685_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m685_Out10	965	// (internal1_m685_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m686_Out10	BUFFER[3219]	// (internal1_m686_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m686_Out10	966	// (internal1_m686_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m687_Out10	BUFFER[3221]	// (internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m687_Out10	967	// (internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m700_Chim0	BUFFER[3223]	// (internal1_m700_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m700_Chim0	968	// (internal1_m700_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m710_Chim0	BUFFER[3228]	// (internal1_m710_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m710_Chim0	969	// (internal1_m710_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m719_Chim0	BUFFER[3233]	// (internal1_m719_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m719_Chim0	970	// (internal1_m719_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m728_Chim0	BUFFER[3238]	// (internal1_m728_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m728_Chim0	971	// (internal1_m728_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m736_Chim0	BUFFER[3243]	// (internal1_m736_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m736_Chim0	972	// (internal1_m736_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m745_Chim0	BUFFER[3248]	// (internal1_m745_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m745_Chim0	973	// (internal1_m745_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m754_Chim0	BUFFER[3253]	// (internal1_m754_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m754_Chim0	974	// (internal1_m754_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m762_Chim0	BUFFER[3258]	// (internal1_m762_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m762_Chim0	975	// (internal1_m762_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m771_Chim0	BUFFER[3263]	// (internal1_m771_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m771_Chim0	976	// (internal1_m771_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m780_Chim0	BUFFER[3268]	// (internal1_m780_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m780_Chim0	977	// (internal1_m780_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m788_Chim0	BUFFER[3273]	// (internal1_m788_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m788_Chim0	978	// (internal1_m788_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m797_Chim0	BUFFER[3278]	// (internal1_m797_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m797_Chim0	979	// (internal1_m797_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m809_Out10	BUFFER[3283]	// (internal1_m809_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m809_Out10	980	// (internal1_m809_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m810_Out10	BUFFER[3285]	// (internal1_m810_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m810_Out10	981	// (internal1_m810_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m811_Out10	BUFFER[3287]	// (internal1_m811_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m811_Out10	982	// (internal1_m811_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m812_Out10	BUFFER[3289]	// (internal1_m812_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m812_Out10	983	// (internal1_m812_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m813_Out10	BUFFER[3291]	// (internal1_m813_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m813_Out10	984	// (internal1_m813_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m814_Out10	BUFFER[3293]	// (internal1_m814_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m814_Out10	985	// (internal1_m814_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m815_Out10	BUFFER[3295]	// (internal1_m815_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m815_Out10	986	// (internal1_m815_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m832_Xtek0	BUFFER[3297]	// (internal1_m832_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m832_Xtek0	987	// (internal1_m832_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m834_Xtek0	BUFFER[3302]	// (internal1_m834_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m834_Xtek0	988	// (internal1_m834_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m835_Out10	BUFFER[3307]	// (internal1_m835_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m835_Out10	989	// (internal1_m835_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m836_Out10	BUFFER[3309]	// (internal1_m836_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m836_Out10	990	// (internal1_m836_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m837_Out10	BUFFER[3311]	// (internal1_m837_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m837_Out10	991	// (internal1_m837_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m838_Out10	BUFFER[3313]	// (internal1_m838_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m838_Out10	992	// (internal1_m838_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m850_Out10	BUFFER[3315]	// (internal1_m850_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m850_Out10	993	// (internal1_m850_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m851_Out10	BUFFER[3317]	// (internal1_m851_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m851_Out10	994	// (internal1_m851_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m852_Out10	BUFFER[3319]	// (internal1_m852_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m852_Out10	995	// (internal1_m852_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m860_Chim0	BUFFER[3321]	// (internal1_m860_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m860_Chim0	996	// (internal1_m860_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m868_Chim0	BUFFER[3326]	// (internal1_m868_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m868_Chim0	997	// (internal1_m868_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m878_Chim0	BUFFER[3331]	// (internal1_m878_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m878_Chim0	998	// (internal1_m878_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m890_MyFirstEnterFlag	BUFFER[3336]	// (internal1_m890_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m890_MyFirstEnterFlag	999	// (internal1_m890_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m890_Pav0	BUFFER[3338]	// (internal1_m890_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m890_Pav0	1000	// (internal1_m890_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m890_Pv0	BUFFER[3340]	// (internal1_m890_Pv0)  - Пер. выключатель механизма
#define idinternal1_m890_Pv0	1001	// (internal1_m890_Pv0)  - Пер. выключатель механизма
#define internal1_m890_RA00	BUFFER[3342]	// (internal1_m890_RA00)  - последнее задание вперед
#define idinternal1_m890_RA00	1002	// (internal1_m890_RA00)  - последнее задание вперед
#define internal1_m890_RA10	BUFFER[3344]	// (internal1_m890_RA10)  - последнее задание назад
#define idinternal1_m890_RA10	1003	// (internal1_m890_RA10)  - последнее задание назад
#define internal1_m890_V00	BUFFER[3346]	// (internal1_m890_V00)  V00 - текущая скорость механизма
#define idinternal1_m890_V00	1004	// (internal1_m890_V00)  V00 - текущая скорость механизма
#define internal1_m890_X00	BUFFER[3351]	// (internal1_m890_X00)  X00 - текущая координата механизма
#define idinternal1_m890_X00	1005	// (internal1_m890_X00)  X00 - текущая координата механизма
#define internal1_m890_Zav0	BUFFER[3356]	// (internal1_m890_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m890_Zav0	1006	// (internal1_m890_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m890_Zv0	BUFFER[3358]	// (internal1_m890_Zv0)  - Зад. выключатель механизма
#define idinternal1_m890_Zv0	1007	// (internal1_m890_Zv0)  - Зад. выключатель механизма
#define internal1_m947_Out10	BUFFER[3360]	// (internal1_m947_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m947_Out10	1008	// (internal1_m947_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m948_Out10	BUFFER[3362]	// (internal1_m948_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m948_Out10	1009	// (internal1_m948_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m950_Xtek0	BUFFER[3364]	// (internal1_m950_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m950_Xtek0	1010	// (internal1_m950_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m951_Out10	BUFFER[3369]	// (internal1_m951_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m951_Out10	1011	// (internal1_m951_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m964_Out10	BUFFER[3371]	// (internal1_m964_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m964_Out10	1012	// (internal1_m964_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m965_Out10	BUFFER[3373]	// (internal1_m965_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m965_Out10	1013	// (internal1_m965_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m967_Xtek0	BUFFER[3375]	// (internal1_m967_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m967_Xtek0	1014	// (internal1_m967_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m968_Out10	BUFFER[3380]	// (internal1_m968_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m968_Out10	1015	// (internal1_m968_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m978_Out10	BUFFER[3382]	// (internal1_m978_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m978_Out10	1016	// (internal1_m978_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m979_Out10	BUFFER[3384]	// (internal1_m979_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m979_Out10	1017	// (internal1_m979_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m980_Out10	BUFFER[3386]	// (internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m980_Out10	1018	// (internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m981_Out10	BUFFER[3388]	// (internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m981_Out10	1019	// (internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m982_Out10	BUFFER[3390]	// (internal1_m982_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m982_Out10	1020	// (internal1_m982_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m993_Out10	BUFFER[3392]	// (internal1_m993_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m993_Out10	1021	// (internal1_m993_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m994_Out10	BUFFER[3394]	// (internal1_m994_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m994_Out10	1022	// (internal1_m994_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m995_Out10	BUFFER[3396]	// (internal1_m995_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m995_Out10	1023	// (internal1_m995_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m996_Out10	BUFFER[3398]	// (internal1_m996_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m996_Out10	1024	// (internal1_m996_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m997_Out10	BUFFER[3400]	// (internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m997_Out10	1025	// (internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m99_MyFirstEnterFlag	BUFFER[3402]	// (internal1_m99_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m99_MyFirstEnterFlag	1026	// (internal1_m99_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m99_Pav0	BUFFER[3404]	// (internal1_m99_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m99_Pav0	1027	// (internal1_m99_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m99_Ppv0	BUFFER[3406]	// (internal1_m99_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m99_Ppv0	1028	// (internal1_m99_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m99_RA00	BUFFER[3408]	// (internal1_m99_RA00) RA00 - последнее задание вперед
#define idinternal1_m99_RA00	1029	// (internal1_m99_RA00) RA00 - последнее задание вперед
#define internal1_m99_RA10	BUFFER[3410]	// (internal1_m99_RA10) RA10 - последнее задание назад
#define idinternal1_m99_RA10	1030	// (internal1_m99_RA10) RA10 - последнее задание назад
#define internal1_m99_RA30	BUFFER[3412]	// (internal1_m99_RA30)  RA30 - разрешение движения
#define idinternal1_m99_RA30	1031	// (internal1_m99_RA30)  RA30 - разрешение движения
#define internal1_m99_RA50	BUFFER[3414]	// (internal1_m99_RA50) Ra50 - последнее задание скорости
#define idinternal1_m99_RA50	1032	// (internal1_m99_RA50) Ra50 - последнее задание скорости
#define internal1_m99_RV00	BUFFER[3416]	// (internal1_m99_RV00) V0 - текущая скорость ОРР
#define idinternal1_m99_RV00	1033	// (internal1_m99_RV00) V0 - текущая скорость ОРР
#define internal1_m99_Sh00	BUFFER[3421]	// (internal1_m99_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m99_Sh00	1034	// (internal1_m99_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m99_ShV00	BUFFER[3426]	// (internal1_m99_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m99_ShV00	1035	// (internal1_m99_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m99_X00	BUFFER[3431]	// (internal1_m99_X00) X0 - текущая координата ОРР
#define idinternal1_m99_X00	1036	// (internal1_m99_X00) X0 - текущая координата ОРР
#define internal1_m99_Zav0	BUFFER[3436]	// (internal1_m99_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m99_Zav0	1037	// (internal1_m99_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m99_flp	BUFFER[3438]	// (internal1_m99_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m99_flp	1038	// (internal1_m99_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m99_fls	BUFFER[3440]	// (internal1_m99_fls)  fls - флаг одношагового режима
#define idinternal1_m99_fls	1039	// (internal1_m99_fls)  fls - флаг одношагового режима
#define krb1	BUFFER[3442]	// ( - , - ) 
#define idkrb1	1040	// ( - , - ) 
#define krb2	BUFFER[3447]	// ( - , - ) 
#define idkrb2	1041	// ( - , - ) 
#define lEM_C1AD31LRP	BUFFER[3452]	// (C1AD31LRP) Общий сброс от РПУ
#define idlEM_C1AD31LRP	1042	// (C1AD31LRP) Общий сброс от РПУ
#define lEM_R0IE01LRP	BUFFER[3454]	// (R0IE01LRP) Отключение питание детекторов
#define idlEM_R0IE01LRP	1043	// (R0IE01LRP) Отключение питание детекторов
#define lEM_R0IE02LRP	BUFFER[3456]	// (R0IE02LRP) Отключить питание ПР, ПУ
#define idlEM_R0IE02LRP	1044	// (R0IE02LRP) Отключить питание ПР, ПУ
#define lEM_R3AD10LC1	BUFFER[3458]	// (R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define idlEM_R3AD10LC1	1045	// (R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define lEM_R3AD20LC1	BUFFER[3460]	// (R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define idlEM_R3AD20LC1	1046	// (R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define lEM_R5AD10LC1	BUFFER[3462]	// (R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define idlEM_R5AD10LC1	1047	// (R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define lEM_R5AD20LC1	BUFFER[3464]	// (R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define idlEM_R5AD20LC1	1048	// (R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define lEM_R6AD10LC1	BUFFER[3466]	// (R6AD10LC1) Выкатить кран-балку от ИС
#define idlEM_R6AD10LC1	1049	// (R6AD10LC1) Выкатить кран-балку от ИС
#define lEM_R8AD10LC1	BUFFER[3468]	// (R8AD10LC1) Установить аварийный НИ от ИС
#define idlEM_R8AD10LC1	1050	// (R8AD10LC1) Установить аварийный НИ от ИС
#define var267	BUFFER[3470]	// Внутренняя переменная var267
#define idvar267	30000	// Внутренняя переменная var267
#define var215	BUFFER[3472]	// Внутренняя переменная var215
#define idvar215	30001	// Внутренняя переменная var215
#define var243	BUFFER[3474]	// Внутренняя переменная var243
#define idvar243	30002	// Внутренняя переменная var243
#define var170	BUFFER[3479]	// Внутренняя переменная var170
#define idvar170	30003	// Внутренняя переменная var170
#define var269	BUFFER[3481]	// Внутренняя переменная var269
#define idvar269	30004	// Внутренняя переменная var269
#define var322	BUFFER[3486]	// Внутренняя переменная var322
#define idvar322	30005	// Внутренняя переменная var322
#define var332	BUFFER[3488]	// Внутренняя переменная var332
#define idvar332	30006	// Внутренняя переменная var332
#define var150	BUFFER[3493]	// Внутренняя переменная var150
#define idvar150	30007	// Внутренняя переменная var150
#define var167	BUFFER[3495]	// Внутренняя переменная var167
#define idvar167	30008	// Внутренняя переменная var167
#define var136	BUFFER[3500]	// Внутренняя переменная var136
#define idvar136	30009	// Внутренняя переменная var136
#define var137	BUFFER[3505]	// Внутренняя переменная var137
#define idvar137	30010	// Внутренняя переменная var137
#define var187	BUFFER[3507]	// Внутренняя переменная var187
#define idvar187	30011	// Внутренняя переменная var187
#define var198	BUFFER[3509]	// Внутренняя переменная var198
#define idvar198	30012	// Внутренняя переменная var198
#define var288	BUFFER[3511]	// Внутренняя переменная var288
#define idvar288	30013	// Внутренняя переменная var288
#define var7	BUFFER[3516]	// Внутренняя переменная var7
#define idvar7	30014	// Внутренняя переменная var7
#define var61	BUFFER[3521]	// Внутренняя переменная var61
#define idvar61	30015	// Внутренняя переменная var61
#define var119	BUFFER[3523]	// Внутренняя переменная var119
#define idvar119	30016	// Внутренняя переменная var119
#define var184	BUFFER[3525]	// Внутренняя переменная var184
#define idvar184	30017	// Внутренняя переменная var184
#define var264	BUFFER[3527]	// Внутренняя переменная var264
#define idvar264	30018	// Внутренняя переменная var264
#define var35	BUFFER[3529]	// Внутренняя переменная var35
#define idvar35	30019	// Внутренняя переменная var35
#define var47	BUFFER[3531]	// Внутренняя переменная var47
#define idvar47	30020	// Внутренняя переменная var47
#define var214	BUFFER[3533]	// Внутренняя переменная var214
#define idvar214	30021	// Внутренняя переменная var214
#define var12	BUFFER[3535]	// Внутренняя переменная var12
#define idvar12	30022	// Внутренняя переменная var12
#define var38	BUFFER[3537]	// Внутренняя переменная var38
#define idvar38	30023	// Внутренняя переменная var38
#define var222	BUFFER[3539]	// Внутренняя переменная var222
#define idvar222	30024	// Внутренняя переменная var222
#define var246	BUFFER[3544]	// Внутренняя переменная var246
#define idvar246	30025	// Внутренняя переменная var246
#define var158	BUFFER[3546]	// Внутренняя переменная var158
#define idvar158	30026	// Внутренняя переменная var158
#define var179	BUFFER[3551]	// Внутренняя переменная var179
#define idvar179	30027	// Внутренняя переменная var179
#define var80	BUFFER[3553]	// Внутренняя переменная var80
#define idvar80	30028	// Внутренняя переменная var80
#define var144	BUFFER[3555]	// Внутренняя переменная var144
#define idvar144	30029	// Внутренняя переменная var144
#define var276	BUFFER[3557]	// Внутренняя переменная var276
#define idvar276	30030	// Внутренняя переменная var276
#define var25	BUFFER[3559]	// Внутренняя переменная var25
#define idvar25	30031	// Внутренняя переменная var25
#define var55	BUFFER[3561]	// Внутренняя переменная var55
#define idvar55	30032	// Внутренняя переменная var55
#define var134	BUFFER[3570]	// Внутренняя переменная var134
#define idvar134	30033	// Внутренняя переменная var134
#define var320	BUFFER[3572]	// Внутренняя переменная var320
#define idvar320	30034	// Внутренняя переменная var320
#define var36	BUFFER[3574]	// Внутренняя переменная var36
#define idvar36	30035	// Внутренняя переменная var36
#define var85	BUFFER[3576]	// Внутренняя переменная var85
#define idvar85	30036	// Внутренняя переменная var85
#define var142	BUFFER[3578]	// Внутренняя переменная var142
#define idvar142	30037	// Внутренняя переменная var142
#define var183	BUFFER[3581]	// Внутренняя переменная var183
#define idvar183	30038	// Внутренняя переменная var183
#define var219	BUFFER[3583]	// Внутренняя переменная var219
#define idvar219	30039	// Внутренняя переменная var219
#define var226	BUFFER[3585]	// Внутренняя переменная var226
#define idvar226	30040	// Внутренняя переменная var226
#define var259	BUFFER[3590]	// Внутренняя переменная var259
#define idvar259	30041	// Внутренняя переменная var259
#define var311	BUFFER[3592]	// Внутренняя переменная var311
#define idvar311	30042	// Внутренняя переменная var311
#define var46	BUFFER[3597]	// Внутренняя переменная var46
#define idvar46	30043	// Внутренняя переменная var46
#define var67	BUFFER[3599]	// Внутренняя переменная var67
#define idvar67	30044	// Внутренняя переменная var67
#define var108	BUFFER[3601]	// Внутренняя переменная var108
#define idvar108	30045	// Внутренняя переменная var108
#define var313	BUFFER[3603]	// Внутренняя переменная var313
#define idvar313	30046	// Внутренняя переменная var313
#define var146	BUFFER[3605]	// Внутренняя переменная var146
#define idvar146	30047	// Внутренняя переменная var146
#define var171	BUFFER[3607]	// Внутренняя переменная var171
#define idvar171	30048	// Внутренняя переменная var171
#define var275	BUFFER[3609]	// Внутренняя переменная var275
#define idvar275	30049	// Внутренняя переменная var275
#define var307	BUFFER[3611]	// Внутренняя переменная var307
#define idvar307	30050	// Внутренняя переменная var307
#define var199	BUFFER[3613]	// Внутренняя переменная var199
#define idvar199	30051	// Внутренняя переменная var199
#define var231	BUFFER[3615]	// Внутренняя переменная var231
#define idvar231	30052	// Внутренняя переменная var231
#define var15	BUFFER[3617]	// Внутренняя переменная var15
#define idvar15	30053	// Внутренняя переменная var15
#define var103	BUFFER[3619]	// Внутренняя переменная var103
#define idvar103	30054	// Внутренняя переменная var103
#define var197	BUFFER[3621]	// Внутренняя переменная var197
#define idvar197	30055	// Внутренняя переменная var197
#define var225	BUFFER[3623]	// Внутренняя переменная var225
#define idvar225	30056	// Внутренняя переменная var225
#define var228	BUFFER[3628]	// Внутренняя переменная var228
#define idvar228	30057	// Внутренняя переменная var228
#define var237	BUFFER[3633]	// Внутренняя переменная var237
#define idvar237	30058	// Внутренняя переменная var237
#define var44	BUFFER[3638]	// Внутренняя переменная var44
#define idvar44	30059	// Внутренняя переменная var44
#define var49	BUFFER[3640]	// Внутренняя переменная var49
#define idvar49	30060	// Внутренняя переменная var49
#define var141	BUFFER[3642]	// Внутренняя переменная var141
#define idvar141	30061	// Внутренняя переменная var141
#define var282	BUFFER[3644]	// Внутренняя переменная var282
#define idvar282	30062	// Внутренняя переменная var282
#define var45	BUFFER[3649]	// Внутренняя переменная var45
#define idvar45	30063	// Внутренняя переменная var45
#define var102	BUFFER[3651]	// Внутренняя переменная var102
#define idvar102	30064	// Внутренняя переменная var102
#define var303	BUFFER[3653]	// Внутренняя переменная var303
#define idvar303	30065	// Внутренняя переменная var303
#define var326	BUFFER[3658]	// Внутренняя переменная var326
#define idvar326	30066	// Внутренняя переменная var326
#define var62	BUFFER[3663]	// Внутренняя переменная var62
#define idvar62	30067	// Внутренняя переменная var62
#define var185	BUFFER[3665]	// Внутренняя переменная var185
#define idvar185	30068	// Внутренняя переменная var185
#define var194	BUFFER[3667]	// Внутренняя переменная var194
#define idvar194	30069	// Внутренняя переменная var194
#define var210	BUFFER[3669]	// Внутренняя переменная var210
#define idvar210	30070	// Внутренняя переменная var210
#define var298	BUFFER[3671]	// Внутренняя переменная var298
#define idvar298	30071	// Внутренняя переменная var298
#define vainSInt	BUFFER[3673]	// Внутренняя переменная vainSInt
#define idvainSInt	30072	// Внутренняя переменная vainSInt
#define var14	BUFFER[3676]	// Внутренняя переменная var14
#define idvar14	30073	// Внутренняя переменная var14
#define var159	BUFFER[3678]	// Внутренняя переменная var159
#define idvar159	30074	// Внутренняя переменная var159
#define var190	BUFFER[3683]	// Внутренняя переменная var190
#define idvar190	30075	// Внутренняя переменная var190
#define var233	BUFFER[3685]	// Внутренняя переменная var233
#define idvar233	30076	// Внутренняя переменная var233
#define var262	BUFFER[3690]	// Внутренняя переменная var262
#define idvar262	30077	// Внутренняя переменная var262
#define var60	BUFFER[3692]	// Внутренняя переменная var60
#define idvar60	30078	// Внутренняя переменная var60
#define var77	BUFFER[3694]	// Внутренняя переменная var77
#define idvar77	30079	// Внутренняя переменная var77
#define var125	BUFFER[3696]	// Внутренняя переменная var125
#define idvar125	30080	// Внутренняя переменная var125
#define var200	BUFFER[3698]	// Внутренняя переменная var200
#define idvar200	30081	// Внутренняя переменная var200
#define var240	BUFFER[3700]	// Внутренняя переменная var240
#define idvar240	30082	// Внутренняя переменная var240
#define var272	BUFFER[3705]	// Внутренняя переменная var272
#define idvar272	30083	// Внутренняя переменная var272
#define var309	BUFFER[3710]	// Внутренняя переменная var309
#define idvar309	30084	// Внутренняя переменная var309
#define var328	BUFFER[3712]	// Внутренняя переменная var328
#define idvar328	30085	// Внутренняя переменная var328
#define var3	BUFFER[3714]	// Внутренняя переменная var3
#define idvar3	30086	// Внутренняя переменная var3
#define var34	BUFFER[3719]	// Внутренняя переменная var34
#define idvar34	30087	// Внутренняя переменная var34
#define var75	BUFFER[3721]	// Внутренняя переменная var75
#define idvar75	30088	// Внутренняя переменная var75
#define vainSFloat	BUFFER[3723]	// Внутренняя переменная vainSFloat
#define idvainSFloat	30089	// Внутренняя переменная vainSFloat
#define var92	BUFFER[3728]	// Внутренняя переменная var92
#define idvar92	30090	// Внутренняя переменная var92
#define var111	BUFFER[3730]	// Внутренняя переменная var111
#define idvar111	30091	// Внутренняя переменная var111
#define var117	BUFFER[3732]	// Внутренняя переменная var117
#define idvar117	30092	// Внутренняя переменная var117
#define var160	BUFFER[3734]	// Внутренняя переменная var160
#define idvar160	30093	// Внутренняя переменная var160
#define var182	BUFFER[3739]	// Внутренняя переменная var182
#define idvar182	30094	// Внутренняя переменная var182
#define var292	BUFFER[3741]	// Внутренняя переменная var292
#define idvar292	30095	// Внутренняя переменная var292
#define var50	BUFFER[3743]	// Внутренняя переменная var50
#define idvar50	30096	// Внутренняя переменная var50
#define var74	BUFFER[3745]	// Внутренняя переменная var74
#define idvar74	30097	// Внутренняя переменная var74
#define var178	BUFFER[3747]	// Внутренняя переменная var178
#define idvar178	30098	// Внутренняя переменная var178
#define var236	BUFFER[3749]	// Внутренняя переменная var236
#define idvar236	30099	// Внутренняя переменная var236
#define var89	BUFFER[3754]	// Внутренняя переменная var89
#define idvar89	30100	// Внутренняя переменная var89
#define var128	BUFFER[3756]	// Внутренняя переменная var128
#define idvar128	30101	// Внутренняя переменная var128
#define var188	BUFFER[3759]	// Внутренняя переменная var188
#define idvar188	30102	// Внутренняя переменная var188
#define var27	BUFFER[3761]	// Внутренняя переменная var27
#define idvar27	30103	// Внутренняя переменная var27
#define var43	BUFFER[3763]	// Внутренняя переменная var43
#define idvar43	30104	// Внутренняя переменная var43
#define var297	BUFFER[3765]	// Внутренняя переменная var297
#define idvar297	30105	// Внутренняя переменная var297
#define var5	BUFFER[3767]	// Внутренняя переменная var5
#define idvar5	30106	// Внутренняя переменная var5
#define var242	BUFFER[3772]	// Внутренняя переменная var242
#define idvar242	30107	// Внутренняя переменная var242
#define var132	BUFFER[3777]	// Внутренняя переменная var132
#define idvar132	30108	// Внутренняя переменная var132
#define var280	BUFFER[3780]	// Внутренняя переменная var280
#define idvar280	30109	// Внутренняя переменная var280
#define var302	BUFFER[3782]	// Внутренняя переменная var302
#define idvar302	30110	// Внутренняя переменная var302
#define var91	BUFFER[3787]	// Внутренняя переменная var91
#define idvar91	30111	// Внутренняя переменная var91
#define var115	BUFFER[3789]	// Внутренняя переменная var115
#define idvar115	30112	// Внутренняя переменная var115
#define var241	BUFFER[3798]	// Внутренняя переменная var241
#define idvar241	30113	// Внутренняя переменная var241
#define var245	BUFFER[3803]	// Внутренняя переменная var245
#define idvar245	30114	// Внутренняя переменная var245
#define var256	BUFFER[3805]	// Внутренняя переменная var256
#define idvar256	30115	// Внутренняя переменная var256
#define var42	BUFFER[3807]	// Внутренняя переменная var42
#define idvar42	30116	// Внутренняя переменная var42
#define var189	BUFFER[3809]	// Внутренняя переменная var189
#define idvar189	30117	// Внутренняя переменная var189
#define var229	BUFFER[3811]	// Внутренняя переменная var229
#define idvar229	30118	// Внутренняя переменная var229
#define var318	BUFFER[3813]	// Внутренняя переменная var318
#define idvar318	30119	// Внутренняя переменная var318
#define var113	BUFFER[3818]	// Внутренняя переменная var113
#define idvar113	30120	// Внутренняя переменная var113
#define var172	BUFFER[3827]	// Внутренняя переменная var172
#define idvar172	30121	// Внутренняя переменная var172
#define var295	BUFFER[3829]	// Внутренняя переменная var295
#define idvar295	30122	// Внутренняя переменная var295
#define var63	BUFFER[3834]	// Внутренняя переменная var63
#define idvar63	30123	// Внутренняя переменная var63
#define var105	BUFFER[3836]	// Внутренняя переменная var105
#define idvar105	30124	// Внутренняя переменная var105
#define var154	BUFFER[3838]	// Внутренняя переменная var154
#define idvar154	30125	// Внутренняя переменная var154
#define var157	BUFFER[3843]	// Внутренняя переменная var157
#define idvar157	30126	// Внутренняя переменная var157
#define var211	BUFFER[3846]	// Внутренняя переменная var211
#define idvar211	30127	// Внутренняя переменная var211
#define var212	BUFFER[3848]	// Внутренняя переменная var212
#define idvar212	30128	// Внутренняя переменная var212
#define var57	BUFFER[3850]	// Внутренняя переменная var57
#define idvar57	30129	// Внутренняя переменная var57
#define var127	BUFFER[3859]	// Внутренняя переменная var127
#define idvar127	30130	// Внутренняя переменная var127
#define var65	BUFFER[3861]	// Внутренняя переменная var65
#define idvar65	30131	// Внутренняя переменная var65
#define var104	BUFFER[3863]	// Внутренняя переменная var104
#define idvar104	30132	// Внутренняя переменная var104
#define var265	BUFFER[3865]	// Внутренняя переменная var265
#define idvar265	30133	// Внутренняя переменная var265
#define var273	BUFFER[3867]	// Внутренняя переменная var273
#define idvar273	30134	// Внутренняя переменная var273
#define var23	BUFFER[3869]	// Внутренняя переменная var23
#define idvar23	30135	// Внутренняя переменная var23
#define var54	BUFFER[3871]	// Внутренняя переменная var54
#define idvar54	30136	// Внутренняя переменная var54
#define var213	BUFFER[3873]	// Внутренняя переменная var213
#define idvar213	30137	// Внутренняя переменная var213
#define var216	BUFFER[3875]	// Внутренняя переменная var216
#define idvar216	30138	// Внутренняя переменная var216
#define var253	BUFFER[3877]	// Внутренняя переменная var253
#define idvar253	30139	// Внутренняя переменная var253
#define var274	BUFFER[3879]	// Внутренняя переменная var274
#define idvar274	30140	// Внутренняя переменная var274
#define var278	BUFFER[3881]	// Внутренняя переменная var278
#define idvar278	30141	// Внутренняя переменная var278
#define var286	BUFFER[3883]	// Внутренняя переменная var286
#define idvar286	30142	// Внутренняя переменная var286
#define var124	BUFFER[3888]	// Внутренняя переменная var124
#define idvar124	30143	// Внутренняя переменная var124
#define var133	BUFFER[3890]	// Внутренняя переменная var133
#define idvar133	30144	// Внутренняя переменная var133
#define var324	BUFFER[3895]	// Внутренняя переменная var324
#define idvar324	30145	// Внутренняя переменная var324
#define var191	BUFFER[3897]	// Внутренняя переменная var191
#define idvar191	30146	// Внутренняя переменная var191
#define var314	BUFFER[3899]	// Внутренняя переменная var314
#define idvar314	30147	// Внутренняя переменная var314
#define var337	BUFFER[3901]	// Внутренняя переменная var337
#define idvar337	30148	// Внутренняя переменная var337
#define var116	BUFFER[3906]	// Внутренняя переменная var116
#define idvar116	30149	// Внутренняя переменная var116
#define var145	BUFFER[3911]	// Внутренняя переменная var145
#define idvar145	30150	// Внутренняя переменная var145
#define var300	BUFFER[3913]	// Внутренняя переменная var300
#define idvar300	30151	// Внутренняя переменная var300
#define var315	BUFFER[3915]	// Внутренняя переменная var315
#define idvar315	30152	// Внутренняя переменная var315
#define var21	BUFFER[3917]	// Внутренняя переменная var21
#define idvar21	30153	// Внутренняя переменная var21
#define var151	BUFFER[3919]	// Внутренняя переменная var151
#define idvar151	30154	// Внутренняя переменная var151
#define var290	BUFFER[3921]	// Внутренняя переменная var290
#define idvar290	30155	// Внутренняя переменная var290
#define var293	BUFFER[3923]	// Внутренняя переменная var293
#define idvar293	30156	// Внутренняя переменная var293
#define var329	BUFFER[3925]	// Внутренняя переменная var329
#define idvar329	30157	// Внутренняя переменная var329
#define var30	BUFFER[3927]	// Внутренняя переменная var30
#define idvar30	30158	// Внутренняя переменная var30
#define var59	BUFFER[3929]	// Внутренняя переменная var59
#define idvar59	30159	// Внутренняя переменная var59
#define var130	BUFFER[3931]	// Внутренняя переменная var130
#define idvar130	30160	// Внутренняя переменная var130
#define var208	BUFFER[3933]	// Внутренняя переменная var208
#define idvar208	30161	// Внутренняя переменная var208
#define var255	BUFFER[3935]	// Внутренняя переменная var255
#define idvar255	30162	// Внутренняя переменная var255
#define var258	BUFFER[3937]	// Внутренняя переменная var258
#define idvar258	30163	// Внутренняя переменная var258
#define var53	BUFFER[3939]	// Внутренняя переменная var53
#define idvar53	30164	// Внутренняя переменная var53
#define var66	BUFFER[3941]	// Внутренняя переменная var66
#define idvar66	30165	// Внутренняя переменная var66
#define var26	BUFFER[3943]	// Внутренняя переменная var26
#define idvar26	30166	// Внутренняя переменная var26
#define var93	BUFFER[3945]	// Внутренняя переменная var93
#define idvar93	30167	// Внутренняя переменная var93
#define var114	BUFFER[3948]	// Внутренняя переменная var114
#define idvar114	30168	// Внутренняя переменная var114
#define var166	BUFFER[3953]	// Внутренняя переменная var166
#define idvar166	30169	// Внутренняя переменная var166
#define var204	BUFFER[3958]	// Внутренняя переменная var204
#define idvar204	30170	// Внутренняя переменная var204
#define var238	BUFFER[3960]	// Внутренняя переменная var238
#define idvar238	30171	// Внутренняя переменная var238
#define var17	BUFFER[3965]	// Внутренняя переменная var17
#define idvar17	30172	// Внутренняя переменная var17
#define var18	BUFFER[3967]	// Внутренняя переменная var18
#define idvar18	30173	// Внутренняя переменная var18
#define var289	BUFFER[3969]	// Внутренняя переменная var289
#define idvar289	30174	// Внутренняя переменная var289
#define var149	BUFFER[3974]	// Внутренняя переменная var149
#define idvar149	30175	// Внутренняя переменная var149
#define var161	BUFFER[3976]	// Внутренняя переменная var161
#define idvar161	30176	// Внутренняя переменная var161
#define var168	BUFFER[3979]	// Внутренняя переменная var168
#define idvar168	30177	// Внутренняя переменная var168
#define var195	BUFFER[3984]	// Внутренняя переменная var195
#define idvar195	30178	// Внутренняя переменная var195
#define var223	BUFFER[3986]	// Внутренняя переменная var223
#define idvar223	30179	// Внутренняя переменная var223
#define var232	BUFFER[3991]	// Внутренняя переменная var232
#define idvar232	30180	// Внутренняя переменная var232
#define var1	BUFFER[3996]	// Внутренняя переменная var1
#define idvar1	30181	// Внутренняя переменная var1
#define var139	BUFFER[3998]	// Внутренняя переменная var139
#define idvar139	30182	// Внутренняя переменная var139
#define var249	BUFFER[4007]	// Внутренняя переменная var249
#define idvar249	30183	// Внутренняя переменная var249
#define var281	BUFFER[4009]	// Внутренняя переменная var281
#define idvar281	30184	// Внутренняя переменная var281
#define var101	BUFFER[4014]	// Внутренняя переменная var101
#define idvar101	30185	// Внутренняя переменная var101
#define var270	BUFFER[4016]	// Внутренняя переменная var270
#define idvar270	30186	// Внутренняя переменная var270
#define var32	BUFFER[4018]	// Внутренняя переменная var32
#define idvar32	30187	// Внутренняя переменная var32
#define var41	BUFFER[4020]	// Внутренняя переменная var41
#define idvar41	30188	// Внутренняя переменная var41
#define var97	BUFFER[4025]	// Внутренняя переменная var97
#define idvar97	30189	// Внутренняя переменная var97
#define var177	BUFFER[4034]	// Внутренняя переменная var177
#define idvar177	30190	// Внутренняя переменная var177
#define var227	BUFFER[4036]	// Внутренняя переменная var227
#define idvar227	30191	// Внутренняя переменная var227
#define var244	BUFFER[4041]	// Внутренняя переменная var244
#define idvar244	30192	// Внутренняя переменная var244
#define var9	BUFFER[4046]	// Внутренняя переменная var9
#define idvar9	30193	// Внутренняя переменная var9
#define var16	BUFFER[4048]	// Внутренняя переменная var16
#define idvar16	30194	// Внутренняя переменная var16
#define var79	BUFFER[4050]	// Внутренняя переменная var79
#define idvar79	30195	// Внутренняя переменная var79
#define var106	BUFFER[4052]	// Внутренняя переменная var106
#define idvar106	30196	// Внутренняя переменная var106
#define var122	BUFFER[4054]	// Внутренняя переменная var122
#define idvar122	30197	// Внутренняя переменная var122
#define var287	BUFFER[4056]	// Внутренняя переменная var287
#define idvar287	30198	// Внутренняя переменная var287
#define var319	BUFFER[4061]	// Внутренняя переменная var319
#define idvar319	30199	// Внутренняя переменная var319
#define var40	BUFFER[4066]	// Внутренняя переменная var40
#define idvar40	30200	// Внутренняя переменная var40
#define var58	BUFFER[4068]	// Внутренняя переменная var58
#define idvar58	30201	// Внутренняя переменная var58
#define var252	BUFFER[4073]	// Внутренняя переменная var252
#define idvar252	30202	// Внутренняя переменная var252
#define var304	BUFFER[4075]	// Внутренняя переменная var304
#define idvar304	30203	// Внутренняя переменная var304
#define var323	BUFFER[4077]	// Внутренняя переменная var323
#define idvar323	30204	// Внутренняя переменная var323
#define var336	BUFFER[4079]	// Внутренняя переменная var336
#define idvar336	30205	// Внутренняя переменная var336
#define var123	BUFFER[4081]	// Внутренняя переменная var123
#define idvar123	30206	// Внутренняя переменная var123
#define var152	BUFFER[4083]	// Внутренняя переменная var152
#define idvar152	30207	// Внутренняя переменная var152
#define var95	BUFFER[4088]	// Внутренняя переменная var95
#define idvar95	30208	// Внутренняя переменная var95
#define var131	BUFFER[4093]	// Внутренняя переменная var131
#define idvar131	30209	// Внутренняя переменная var131
#define var112	BUFFER[4095]	// Внутренняя переменная var112
#define idvar112	30210	// Внутренняя переменная var112
#define var121	BUFFER[4097]	// Внутренняя переменная var121
#define idvar121	30211	// Внутренняя переменная var121
#define var155	BUFFER[4099]	// Внутренняя переменная var155
#define idvar155	30212	// Внутренняя переменная var155
#define var234	BUFFER[4102]	// Внутренняя переменная var234
#define idvar234	30213	// Внутренняя переменная var234
#define var239	BUFFER[4107]	// Внутренняя переменная var239
#define idvar239	30214	// Внутренняя переменная var239
#define var250	BUFFER[4112]	// Внутренняя переменная var250
#define idvar250	30215	// Внутренняя переменная var250
#define var29	BUFFER[4114]	// Внутренняя переменная var29
#define idvar29	30216	// Внутренняя переменная var29
#define var94	BUFFER[4116]	// Внутренняя переменная var94
#define idvar94	30217	// Внутренняя переменная var94
#define vainSBool	BUFFER[4119]	// Внутренняя переменная vainSBool
#define idvainSBool	30218	// Внутренняя переменная vainSBool
#define var260	BUFFER[4121]	// Внутренняя переменная var260
#define idvar260	30219	// Внутренняя переменная var260
#define var266	BUFFER[4123]	// Внутренняя переменная var266
#define idvar266	30220	// Внутренняя переменная var266
#define var87	BUFFER[4125]	// Внутренняя переменная var87
#define idvar87	30221	// Внутренняя переменная var87
#define var109	BUFFER[4127]	// Внутренняя переменная var109
#define idvar109	30222	// Внутренняя переменная var109
#define var175	BUFFER[4129]	// Внутренняя переменная var175
#define idvar175	30223	// Внутренняя переменная var175
#define var202	BUFFER[4134]	// Внутренняя переменная var202
#define idvar202	30224	// Внутренняя переменная var202
#define var261	BUFFER[4136]	// Внутренняя переменная var261
#define idvar261	30225	// Внутренняя переменная var261
#define var308	BUFFER[4138]	// Внутренняя переменная var308
#define idvar308	30226	// Внутренняя переменная var308
#define var6	BUFFER[4140]	// Внутренняя переменная var6
#define idvar6	30227	// Внутренняя переменная var6
#define var78	BUFFER[4145]	// Внутренняя переменная var78
#define idvar78	30228	// Внутренняя переменная var78
#define var247	BUFFER[4147]	// Внутренняя переменная var247
#define idvar247	30229	// Внутренняя переменная var247
#define var284	BUFFER[4149]	// Внутренняя переменная var284
#define idvar284	30230	// Внутренняя переменная var284
#define var301	BUFFER[4154]	// Внутренняя переменная var301
#define idvar301	30231	// Внутренняя переменная var301
#define var335	BUFFER[4156]	// Внутренняя переменная var335
#define idvar335	30232	// Внутренняя переменная var335
#define var138	BUFFER[4161]	// Внутренняя переменная var138
#define idvar138	30233	// Внутренняя переменная var138
#define var224	BUFFER[4163]	// Внутренняя переменная var224
#define idvar224	30234	// Внутренняя переменная var224
#define var118	BUFFER[4168]	// Внутренняя переменная var118
#define idvar118	30235	// Внутренняя переменная var118
#define var135	BUFFER[4170]	// Внутренняя переменная var135
#define idvar135	30236	// Внутренняя переменная var135
#define var173	BUFFER[4179]	// Внутренняя переменная var173
#define idvar173	30237	// Внутренняя переменная var173
#define var176	BUFFER[4184]	// Внутренняя переменная var176
#define idvar176	30238	// Внутренняя переменная var176
#define var310	BUFFER[4186]	// Внутренняя переменная var310
#define idvar310	30239	// Внутренняя переменная var310
#define var333	BUFFER[4191]	// Внутренняя переменная var333
#define idvar333	30240	// Внутренняя переменная var333
#define var71	BUFFER[4196]	// Внутренняя переменная var71
#define idvar71	30241	// Внутренняя переменная var71
#define var72	BUFFER[4198]	// Внутренняя переменная var72
#define idvar72	30242	// Внутренняя переменная var72
#define var48	BUFFER[4200]	// Внутренняя переменная var48
#define idvar48	30243	// Внутренняя переменная var48
#define var192	BUFFER[4202]	// Внутренняя переменная var192
#define idvar192	30244	// Внутренняя переменная var192
#define var193	BUFFER[4204]	// Внутренняя переменная var193
#define idvar193	30245	// Внутренняя переменная var193
#define var283	BUFFER[4206]	// Внутренняя переменная var283
#define idvar283	30246	// Внутренняя переменная var283
#define var294	BUFFER[4211]	// Внутренняя переменная var294
#define idvar294	30247	// Внутренняя переменная var294
#define var299	BUFFER[4213]	// Внутренняя переменная var299
#define idvar299	30248	// Внутренняя переменная var299
#define var4	BUFFER[4215]	// Внутренняя переменная var4
#define idvar4	30249	// Внутренняя переменная var4
#define var13	BUFFER[4220]	// Внутренняя переменная var13
#define idvar13	30250	// Внутренняя переменная var13
#define var316	BUFFER[4222]	// Внутренняя переменная var316
#define idvar316	30251	// Внутренняя переменная var316
#define var98	BUFFER[4224]	// Внутренняя переменная var98
#define idvar98	30252	// Внутренняя переменная var98
#define var201	BUFFER[4229]	// Внутренняя переменная var201
#define idvar201	30253	// Внутренняя переменная var201
#define var306	BUFFER[4231]	// Внутренняя переменная var306
#define idvar306	30254	// Внутренняя переменная var306
#define var331	BUFFER[4233]	// Внутренняя переменная var331
#define idvar331	30255	// Внутренняя переменная var331
#define var31	BUFFER[4235]	// Внутренняя переменная var31
#define idvar31	30256	// Внутренняя переменная var31
#define var56	BUFFER[4237]	// Внутренняя переменная var56
#define idvar56	30257	// Внутренняя переменная var56
#define var90	BUFFER[4242]	// Внутренняя переменная var90
#define idvar90	30258	// Внутренняя переменная var90
#define var88	BUFFER[4244]	// Внутренняя переменная var88
#define idvar88	30259	// Внутренняя переменная var88
#define var143	BUFFER[4246]	// Внутренняя переменная var143
#define idvar143	30260	// Внутренняя переменная var143
#define var2	BUFFER[4249]	// Внутренняя переменная var2
#define idvar2	30261	// Внутренняя переменная var2
#define var83	BUFFER[4251]	// Внутренняя переменная var83
#define idvar83	30262	// Внутренняя переменная var83
#define var153	BUFFER[4253]	// Внутренняя переменная var153
#define idvar153	30263	// Внутренняя переменная var153
#define var37	BUFFER[4258]	// Внутренняя переменная var37
#define idvar37	30264	// Внутренняя переменная var37
#define var140	BUFFER[4260]	// Внутренняя переменная var140
#define idvar140	30265	// Внутренняя переменная var140
#define var251	BUFFER[4265]	// Внутренняя переменная var251
#define idvar251	30266	// Внутренняя переменная var251
#define var312	BUFFER[4267]	// Внутренняя переменная var312
#define idvar312	30267	// Внутренняя переменная var312
#define var181	BUFFER[4269]	// Внутренняя переменная var181
#define idvar181	30268	// Внутренняя переменная var181
#define var186	BUFFER[4274]	// Внутренняя переменная var186
#define idvar186	30269	// Внутренняя переменная var186
#define var271	BUFFER[4276]	// Внутренняя переменная var271
#define idvar271	30270	// Внутренняя переменная var271
#define var296	BUFFER[4278]	// Внутренняя переменная var296
#define idvar296	30271	// Внутренняя переменная var296
#define var209	BUFFER[4283]	// Внутренняя переменная var209
#define idvar209	30272	// Внутренняя переменная var209
#define var317	BUFFER[4285]	// Внутренняя переменная var317
#define idvar317	30273	// Внутренняя переменная var317
#define var330	BUFFER[4287]	// Внутренняя переменная var330
#define idvar330	30274	// Внутренняя переменная var330
#define var70	BUFFER[4289]	// Внутренняя переменная var70
#define idvar70	30275	// Внутренняя переменная var70
#define var163	BUFFER[4291]	// Внутренняя переменная var163
#define idvar163	30276	// Внутренняя переменная var163
#define var169	BUFFER[4293]	// Внутренняя переменная var169
#define idvar169	30277	// Внутренняя переменная var169
#define var174	BUFFER[4295]	// Внутренняя переменная var174
#define idvar174	30278	// Внутренняя переменная var174
#define var221	BUFFER[4297]	// Внутренняя переменная var221
#define idvar221	30279	// Внутренняя переменная var221
#define var254	BUFFER[4302]	// Внутренняя переменная var254
#define idvar254	30280	// Внутренняя переменная var254
#define var110	BUFFER[4304]	// Внутренняя переменная var110
#define idvar110	30281	// Внутренняя переменная var110
#define var165	BUFFER[4309]	// Внутренняя переменная var165
#define idvar165	30282	// Внутренняя переменная var165
#define var76	BUFFER[4312]	// Внутренняя переменная var76
#define idvar76	30283	// Внутренняя переменная var76
#define var82	BUFFER[4314]	// Внутренняя переменная var82
#define idvar82	30284	// Внутренняя переменная var82
#define var148	BUFFER[4316]	// Внутренняя переменная var148
#define idvar148	30285	// Внутренняя переменная var148
#define var218	BUFFER[4321]	// Внутренняя переменная var218
#define idvar218	30286	// Внутренняя переменная var218
#define var220	BUFFER[4323]	// Внутренняя переменная var220
#define idvar220	30287	// Внутренняя переменная var220
#define var248	BUFFER[4328]	// Внутренняя переменная var248
#define idvar248	30288	// Внутренняя переменная var248
#define var64	BUFFER[4330]	// Внутренняя переменная var64
#define idvar64	30289	// Внутренняя переменная var64
#define var69	BUFFER[4332]	// Внутренняя переменная var69
#define idvar69	30290	// Внутренняя переменная var69
#define var24	BUFFER[4334]	// Внутренняя переменная var24
#define idvar24	30291	// Внутренняя переменная var24
#define var39	BUFFER[4336]	// Внутренняя переменная var39
#define idvar39	30292	// Внутренняя переменная var39
#define var126	BUFFER[4338]	// Внутренняя переменная var126
#define idvar126	30293	// Внутренняя переменная var126
#define var11	BUFFER[4340]	// Внутренняя переменная var11
#define idvar11	30294	// Внутренняя переменная var11
#define var22	BUFFER[4342]	// Внутренняя переменная var22
#define idvar22	30295	// Внутренняя переменная var22
#define var147	BUFFER[4344]	// Внутренняя переменная var147
#define idvar147	30296	// Внутренняя переменная var147
#define var257	BUFFER[4353]	// Внутренняя переменная var257
#define idvar257	30297	// Внутренняя переменная var257
#define var263	BUFFER[4355]	// Внутренняя переменная var263
#define idvar263	30298	// Внутренняя переменная var263
#define var99	BUFFER[4357]	// Внутренняя переменная var99
#define idvar99	30299	// Внутренняя переменная var99
#define var120	BUFFER[4359]	// Внутренняя переменная var120
#define idvar120	30300	// Внутренняя переменная var120
#define var129	BUFFER[4361]	// Внутренняя переменная var129
#define idvar129	30301	// Внутренняя переменная var129
#define var156	BUFFER[4366]	// Внутренняя переменная var156
#define idvar156	30302	// Внутренняя переменная var156
#define var207	BUFFER[4369]	// Внутренняя переменная var207
#define idvar207	30303	// Внутренняя переменная var207
#define var285	BUFFER[4371]	// Внутренняя переменная var285
#define idvar285	30304	// Внутренняя переменная var285
#define var325	BUFFER[4373]	// Внутренняя переменная var325
#define idvar325	30305	// Внутренняя переменная var325
#define var327	BUFFER[4378]	// Внутренняя переменная var327
#define idvar327	30306	// Внутренняя переменная var327
#define var8	BUFFER[4380]	// Внутренняя переменная var8
#define idvar8	30307	// Внутренняя переменная var8
#define var73	BUFFER[4385]	// Внутренняя переменная var73
#define idvar73	30308	// Внутренняя переменная var73
#define var100	BUFFER[4387]	// Внутренняя переменная var100
#define idvar100	30309	// Внутренняя переменная var100
#define var196	BUFFER[4389]	// Внутренняя переменная var196
#define idvar196	30310	// Внутренняя переменная var196
#define var203	BUFFER[4391]	// Внутренняя переменная var203
#define idvar203	30311	// Внутренняя переменная var203
#define var205	BUFFER[4393]	// Внутренняя переменная var205
#define idvar205	30312	// Внутренняя переменная var205
#define var230	BUFFER[4395]	// Внутренняя переменная var230
#define idvar230	30313	// Внутренняя переменная var230
#define var291	BUFFER[4397]	// Внутренняя переменная var291
#define idvar291	30314	// Внутренняя переменная var291
#define var33	BUFFER[4399]	// Внутренняя переменная var33
#define idvar33	30315	// Внутренняя переменная var33
#define var86	BUFFER[4401]	// Внутренняя переменная var86
#define idvar86	30316	// Внутренняя переменная var86
#define var52	BUFFER[4403]	// Внутренняя переменная var52
#define idvar52	30317	// Внутренняя переменная var52
#define var164	BUFFER[4405]	// Внутренняя переменная var164
#define idvar164	30318	// Внутренняя переменная var164
#define var180	BUFFER[4407]	// Внутренняя переменная var180
#define idvar180	30319	// Внутренняя переменная var180
#define var217	BUFFER[4409]	// Внутренняя переменная var217
#define idvar217	30320	// Внутренняя переменная var217
#define var235	BUFFER[4411]	// Внутренняя переменная var235
#define idvar235	30321	// Внутренняя переменная var235
#define var277	BUFFER[4416]	// Внутренняя переменная var277
#define idvar277	30322	// Внутренняя переменная var277
#define var10	BUFFER[4418]	// Внутренняя переменная var10
#define idvar10	30323	// Внутренняя переменная var10
#define var28	BUFFER[4420]	// Внутренняя переменная var28
#define idvar28	30324	// Внутренняя переменная var28
#define var334	BUFFER[4422]	// Внутренняя переменная var334
#define idvar334	30325	// Внутренняя переменная var334
#define var81	BUFFER[4427]	// Внутренняя переменная var81
#define idvar81	30326	// Внутренняя переменная var81
#define var84	BUFFER[4429]	// Внутренняя переменная var84
#define idvar84	30327	// Внутренняя переменная var84
#define var305	BUFFER[4431]	// Внутренняя переменная var305
#define idvar305	30328	// Внутренняя переменная var305
#define vainSLong	BUFFER[4433]	// Внутренняя переменная vainSLong
#define idvainSLong	30329	// Внутренняя переменная vainSLong
#define vainSChar	BUFFER[4442]	// Внутренняя переменная vainSChar
#define idvainSChar	30330	// Внутренняя переменная vainSChar
#define var19	BUFFER[4445]	// Внутренняя переменная var19
#define idvar19	30331	// Внутренняя переменная var19
#define var68	BUFFER[4447]	// Внутренняя переменная var68
#define idvar68	30332	// Внутренняя переменная var68
#define var268	BUFFER[4449]	// Внутренняя переменная var268
#define idvar268	30333	// Внутренняя переменная var268
#define var20	BUFFER[4451]	// Внутренняя переменная var20
#define idvar20	30334	// Внутренняя переменная var20
#define var107	BUFFER[4453]	// Внутренняя переменная var107
#define idvar107	30335	// Внутренняя переменная var107
#define var162	BUFFER[4455]	// Внутренняя переменная var162
#define idvar162	30336	// Внутренняя переменная var162
#define var206	BUFFER[4458]	// Внутренняя переменная var206
#define idvar206	30337	// Внутренняя переменная var206
#define var279	BUFFER[4460]	// Внутренняя переменная var279
#define idvar279	30338	// Внутренняя переменная var279
#define var321	BUFFER[4462]	// Внутренняя переменная var321
#define idvar321	30339	// Внутренняя переменная var321
#define var51	BUFFER[4464]	// Внутренняя переменная var51
#define idvar51	30340	// Внутренняя переменная var51
#define var96	BUFFER[4466]	// Внутренняя переменная var96
#define idvar96	30341	// Внутренняя переменная var96
#pragma pack(push,1)
static VarCtrl allVariables[]={ 			 //Описание всех переменных
	 1	,3	,1	,&A0IT01IZ1},	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
	 2	,3	,1	,&A0IT02IZ2},	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
	 3	,3	,1	,&A0IT03IRP},	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
	 4	,8	,1	,&A0SN02RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
	 5	,8	,1	,&A0SN03RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
	 6	,8	,1	,&A0SN04RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
	 7	,8	,1	,&A0SN05RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
	 8	,8	,1	,&A0SN06RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
	 9	,8	,1	,&A0SN07RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
	 10	,8	,1	,&A0SN08RIM},	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
	 11	,8	,1	,&A0SR01RIM},	//( - , SCM) Текущая реактивность AЗ1
	 12	,8	,1	,&A0VN01RIM},	//( - , SCM) Период разгона  AЗ1
	 13	,1	,1	,&A0VP81LZZ},	//(do32_pti:110 - K03DO, - ) Давление АЗ1 в норме
	 14	,1	,1	,&A1AD01LDU},	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
	 15	,1	,1	,&A1AD02LDU},	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
	 16	,1	,1	,&A1AD03LDU},	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
	 17	,1	,1	,&A1AD04LDU},	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
	 18	,1	,1	,&A1AD05LDU},	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
	 19	,1	,1	,&A1AD11LDU},	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
	 20	,1	,1	,&A1AD21LDU},	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
	 21	,1	,1	,&A1AD31LDU},	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
	 22	,1	,1	,&A1AD32LDU},	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
	 23	,5	,1	,&A1IC01UDU},	//( - , SDu) Координата штока ББ1
	 24	,1	,1	,&A1IE03LDU},	//( - , SCM) Движение ББ1 вперед (от БУШД)
	 25	,1	,1	,&A1IE04LDU},	//( - , SCM) Движение ББ1 назад (от БУШД)
	 26	,1	,1	,&A1IS11LDU},	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
	 27	,1	,1	,&A1IS11LIM},	//( - , SCM) Магнит ББ1 обесточен
	 28	,1	,1	,&A1IS12LDU},	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
	 29	,1	,1	,&A1IS21LDU},	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
	 30	,1	,1	,&A1IS32LIM},	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
	 31	,1	,1	,&A1VP81LZZ},	//(do32_pti:110 - K01DO, - ) Давление СБРОС ББ1 в норме
	 32	,1	,1	,&A2AD01LDU},	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
	 33	,1	,1	,&A2AD02LDU},	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
	 34	,1	,1	,&A2AD03LDU},	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
	 35	,1	,1	,&A2AD04LDU},	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
	 36	,1	,1	,&A2AD05LDU},	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
	 37	,1	,1	,&A2AD11LDU},	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
	 38	,1	,1	,&A2AD21LDU},	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
	 39	,1	,1	,&A2AD31LDU},	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
	 40	,1	,1	,&A2AD32LDU},	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
	 41	,1	,1	,&A2AD33LDU},	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
	 42	,5	,1	,&A2IC01UDU},	//( - , SDu) Координата штока РБ1
	 43	,3	,1	,&A2IP01IZ1},	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
	 44	,3	,1	,&A2IP01IZ2},	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
	 45	,1	,1	,&A2IS11LDU},	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
	 46	,1	,1	,&A2IS11LIM},	//( - , SCM) Магнит РБ1 обесточен
	 47	,1	,1	,&A2IS12LDU},	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
	 48	,1	,1	,&A2IS21LDU},	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
	 49	,1	,1	,&A2IS32LIM},	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
	 50	,1	,1	,&A2IS33LDU},	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
	 51	,1	,1	,&A2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
	 52	,1	,1	,&A3AD01LDU},	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
	 53	,1	,1	,&A3AD02LDU},	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
	 54	,1	,1	,&A3AD03LDU},	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
	 55	,1	,1	,&A3AD04LDU},	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
	 56	,1	,1	,&A3AD05LDU},	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
	 57	,1	,1	,&A3AD11LDU},	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
	 58	,1	,1	,&A3AD21LDU},	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
	 59	,1	,1	,&A3AD31LDU},	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
	 60	,1	,1	,&A3AD33LDU},	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
	 61	,1	,1	,&A3AD34LDU},	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
	 62	,5	,1	,&A3IC01UDU},	//( - , SDu) Координата штока ИС1
	 63	,3	,1	,&A3IP02IDU},	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
	 64	,1	,1	,&A3IS11LDU},	//(do32_pti:110 - K04DO, - ) Приход на ВУ ИС1
	 65	,1	,1	,&A3IS21LDU},	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
	 66	,1	,1	,&A3IS22LDU},	//(do32_pti:110 - K02DO, - ) Приход на НУП ИС1
	 67	,1	,1	,&A3IS31LDU},	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
	 68	,1	,1	,&A3IS33LDU},	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
	 69	,1	,1	,&A3IS35LDU},	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
	 70	,1	,1	,&A3VP81LDU},	//( - , - ) Давление СПУСК ИС1 в норме
	 71	,1	,1	,&A4AD10LDU},	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
	 72	,1	,1	,&A4IS10LDU},	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
	 73	,1	,1	,&A4IS11LDU},	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
	 74	,1	,1	,&A4IS21LDU},	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
	 75	,1	,1	,&A4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
	 76	,1	,1	,&A5AD10LDU},	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
	 77	,1	,1	,&A5AD20LDU},	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
	 78	,1	,1	,&A5IS11LDU},	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
	 79	,1	,1	,&A5IS21LDU},	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
	 80	,1	,1	,&A5VS12LDU},	//( - , SCM) Движение НЛ1 в сторону ВУ
	 81	,1	,1	,&A5VS22LDU},	//( - , SCM) Движение НЛ1 в сторону НУ
	 82	,1	,1	,&A6AD10LDU},	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
	 83	,1	,1	,&A6AD20LDU},	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
	 84	,1	,1	,&A6IS11LDU},	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
	 85	,1	,1	,&A6IS21LDU},	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
	 86	,1	,1	,&A6VS12LDU},	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
	 87	,1	,1	,&A6VS22LDU},	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
	 88	,1	,1	,&A7AP31LDU},	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
	 89	,1	,1	,&A7AS31LDU},	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
	 90	,1	,1	,&A8AD10LDU},	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
	 91	,1	,1	,&A8AD20LDU},	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
	 92	,5	,1	,&A8IC01UDU},	//( - , SDu) Координата ДС2
	 93	,1	,1	,&A8IS12LDU},	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
	 94	,1	,1	,&A8IS22LDU},	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
	 95	,1	,1	,&A9AD10LDU},	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
	 96	,1	,1	,&A9IS11LDU},	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
	 97	,1	,1	,&A9IS21LDU},	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
	 98	,3	,1	,&B0IT01IZ1},	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
	 99	,3	,1	,&B0IT02IZ2},	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
	 100	,3	,1	,&B0IT03IRP},	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
	 101	,8	,1	,&B0SN02RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
	 102	,8	,1	,&B0SN03RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
	 103	,8	,1	,&B0SN04RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
	 104	,8	,1	,&B0SN05RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
	 105	,8	,1	,&B0SN06RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
	 106	,8	,1	,&B0SN07RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
	 107	,8	,1	,&B0SN08RIM},	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
	 108	,8	,1	,&B0SR01RIM},	//( - , SCM) Текущая реактивность AЗ2
	 109	,1	,1	,&B0VP81LZZ},	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
	 110	,1	,1	,&B1AD01LDU},	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
	 111	,1	,1	,&B1AD02LDU},	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
	 112	,1	,1	,&B1AD03LDU},	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
	 113	,1	,1	,&B1AD04LDU},	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
	 114	,1	,1	,&B1AD05LDU},	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
	 115	,1	,1	,&B1AD11LDU},	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
	 116	,1	,1	,&B1AD21LDU},	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
	 117	,1	,1	,&B1AD31LDU},	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
	 118	,1	,1	,&B1AD32LDU},	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
	 119	,5	,1	,&B1IC01UDU},	//( - , SDu) Координата штока ББ2
	 120	,1	,1	,&B1IE03LDU},	//( - , SCM) Движение ББ2 вперед (от БУШД)
	 121	,1	,1	,&B1IE04LDU},	//( - , SCM) Движение ББ2 назад (от БУШД)
	 122	,1	,1	,&B1IS11LDU},	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
	 123	,1	,1	,&B1IS11LIM},	//( - , SCM) Магнит ББ2 обесточен
	 124	,1	,1	,&B1IS12LDU},	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
	 125	,1	,1	,&B1IS21LDU},	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
	 126	,1	,1	,&B1IS32LIM},	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
	 127	,1	,1	,&B1VP81LZZ},	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
	 128	,1	,1	,&B2AD01LDU},	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
	 129	,1	,1	,&B2AD02LDU},	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
	 130	,1	,1	,&B2AD03LDU},	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
	 131	,1	,1	,&B2AD04LDU},	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
	 132	,1	,1	,&B2AD05LDU},	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
	 133	,1	,1	,&B2AD11LDU},	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
	 134	,1	,1	,&B2AD21LDU},	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
	 135	,1	,1	,&B2AD31LDU},	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
	 136	,1	,1	,&B2AD32LDU},	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
	 137	,1	,1	,&B2AD33LDU},	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
	 138	,5	,1	,&B2IC01UDU},	//( - , SDu) Координата штока РБ2
	 139	,3	,1	,&B2IP01IZ1},	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
	 140	,3	,1	,&B2IP01IZ2},	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
	 141	,1	,1	,&B2IS11LDU},	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
	 142	,1	,1	,&B2IS11LIM},	//( - , SCM) Магнит РБ2 обесточен
	 143	,1	,1	,&B2IS12LDU},	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
	 144	,1	,1	,&B2IS21LDU},	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
	 145	,1	,1	,&B2IS32LIM},	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
	 146	,1	,1	,&B2IS33LDU},	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
	 147	,1	,1	,&B2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
	 148	,1	,1	,&B3AD01LDU},	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
	 149	,1	,1	,&B3AD02LDU},	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
	 150	,1	,1	,&B3AD03LDU},	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
	 151	,1	,1	,&B3AD04LDU},	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
	 152	,1	,1	,&B3AD05LDU},	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
	 153	,1	,1	,&B3AD11LDU},	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
	 154	,1	,1	,&B3AD21LDU},	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
	 155	,1	,1	,&B3AD31LDU},	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
	 156	,1	,1	,&B3AD33LDU},	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
	 157	,1	,1	,&B3AD34LDU},	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
	 158	,5	,1	,&B3IC01UDU},	//( - , SDu) Координата штока ИС2
	 159	,3	,1	,&B3IP02IDU},	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
	 160	,1	,1	,&B3IS11LDU},	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
	 161	,1	,1	,&B3IS21LDU},	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
	 162	,1	,1	,&B3IS22LDU},	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
	 163	,1	,1	,&B3IS31LDU},	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
	 164	,1	,1	,&B3IS33LDU},	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	 165	,1	,1	,&B3IS35LDU},	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
	 166	,1	,1	,&B3VP81LDU},	//( - , - ) Давление СПУСК ИС2 в норме
	 167	,1	,1	,&B4AD10LDU},	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
	 168	,1	,1	,&B4IS10LDU},	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
	 169	,1	,1	,&B4IS11LDU},	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
	 170	,1	,1	,&B4IS21LDU},	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
	 171	,1	,1	,&B4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
	 172	,1	,1	,&B5AD10LDU},	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
	 173	,1	,1	,&B5AD20LDU},	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
	 174	,1	,1	,&B5IS11LDU},	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
	 175	,1	,1	,&B5IS21LDU},	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
	 176	,1	,1	,&B5VS12LDU},	//( - , SCM) Движение НЛ2 в сторону ВУ
	 177	,1	,1	,&B5VS22LDU},	//( - , SCM) Движение НЛ2 в сторону НУ
	 178	,1	,1	,&B6AD10LDU},	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
	 179	,1	,1	,&B6AD20LDU},	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
	 180	,1	,1	,&B6IS11LDU},	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
	 181	,1	,1	,&B6IS21LDU},	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
	 182	,1	,1	,&B6VS12LDU},	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
	 183	,1	,1	,&B6VS22LDU},	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
	 184	,1	,1	,&B7AP31LDU},	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
	 185	,1	,1	,&B7AS31LDU},	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
	 186	,1	,1	,&B8AD10LDU},	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
	 187	,1	,1	,&B8AD20LDU},	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
	 188	,5	,1	,&B8IC01UDU},	//( - , SDu) Координата АЗ2, мм
	 189	,1	,1	,&B8IS11LDU},	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
	 190	,1	,1	,&B8IS12LDU},	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
	 191	,1	,1	,&B8IS21LDU},	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
	 192	,1	,1	,&B8IS22LDU},	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
	 193	,1	,1	,&B9AD10LDU},	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
	 194	,1	,1	,&B9IS11LDU},	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
	 195	,1	,1	,&B9IS21LDU},	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
	 196	,1	,1	,&C1MD31LP1},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
	 197	,1	,1	,&C1MD31LP2},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
	 198	,1	,1	,&C2MD31LP1},	//( - , SCM) Кнопка «СБРОС РБ»
	 199	,8	,1	,&LTAKTS},	//( - , - ) takt scm
	 200	,1	,1	,&R0AD16LDU},	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
	 201	,8	,1	,&R0CR01RIM},	//( - , SCM) Коэффициент 12 связи АЗ1,2
	 202	,8	,1	,&R0CR02RIM},	//( - , SCM) Коэффициент 11 связи АЗ1,2
	 203	,3	,1	,&R0DEUMLSS},	//( - , SCM) Сигнал управления моделью
	 204	,1	,1	,&R0EE01LZ1},	//( - , SBz1) Питание  АКНП1  отключить
	 205	,1	,1	,&R0EE01LZ2},	//( - , SBz2) Питание  АКНП1  отключить
	 206	,1	,1	,&R0EE02LZ1},	//( - , SBz1) Питание  АКНП  отключить
	 207	,1	,1	,&R0EE02LZ2},	//( - , SBz2) Питание  АКНП  отключить
	 208	,1	,1	,&R0EE03LZ1},	//( - , SBz1) Питание  АКНП3  отключить
	 209	,1	,1	,&R0EE03LZ2},	//( - , SBz2) Питание  АКНП3  отключить
	 210	,1	,1	,&R0EE04LZ1},	//( - , SBz1) Питание  АКНП4  отключить
	 211	,1	,1	,&R0EE04LZ2},	//( - , SBz2) Питание  АКНП4  отключить
	 212	,8	,1	,&R0IN01FI1},	//( - , SA1) Выход СНМ11 Гц от ПТИ
	 213	,8	,1	,&R0IN01FI2},	//( - , SA2) Выход СНМ-11 Гц от ПТИ
	 214	,8	,1	,&R0IN01FI3},	//( - , SA3) Выход СНМ-11 Гц от ПТИ
	 215	,8	,1	,&R0IN01FI4},	//( - , SA4) Выход СНМ-11 Гц от ПТИ
	 216	,8	,1	,&R0IN01RIP},	//( - , SRP) Выход СНМ-11 Гц от ПТИ
	 217	,8	,1	,&R0IN02FI1},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	 218	,8	,1	,&R0IN02FI2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	 219	,8	,1	,&R0IN02FI3},	//( - , SA3) Выход КНК15-1 Гц от ПТИ
	 220	,8	,1	,&R0IN02FI4},	//( - , SA4) Выход КНК15-1 Гц от ПТИ
	 221	,8	,1	,&R0IN02RIP},	//( - , SRP) Выход КНК15- Гц от ПТИ
	 222	,8	,1	,&R0IN03FI1},	//( - , SA1) Выход КНК53М Гц от ПТИ
	 223	,8	,1	,&R0IN03FI2},	//( - , SA2) Выход КНК53М Гц от ПТИ
	 224	,8	,1	,&R0IN03FI3},	//( - , SA3) Выход КНК53М Гц от ПТИ
	 225	,8	,1	,&R0IN03FI4},	//( - , SA4) Выход КНК53М Гц от ПТИ
	 226	,8	,1	,&R0IN03RIP},	//( - , SRP) Выход КНК53М Гц от ПТИ
	 227	,8	,1	,&R0IN06RIP},	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
	 228	,8	,1	,&R0IN07RIP},	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
	 229	,1	,1	,&R0IS01FI0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	 230	,1	,1	,&R0IS02LDU},	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
	 231	,3	,1	,&R0MW11IP1},	//( - , SCM) Переключатель ВЫСТРЕЛ
	 232	,1	,1	,&R0MW13LP2},	//( - , SCM) Переключатель «СЕТЬ»
	 233	,1	,1	,&R0S01LIM},	//(vds32_pti:360 - K32VDSR, - ) Отключение сетевых передач ПТИ
	 234	,8	,1	,&R0SR01RIM},	//( - , SCM) Текущая реактивность PУ
	 235	,8	,1	,&R0SR02RIM},	//( - , SCM) Текущая мощность РУ (ватт)
	 236	,8	,1	,&R0ST01RIM},	//( - , SCM) Текущий период разгона РУ
	 237	,1	,1	,&R0VZ71LZ1},	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
	 238	,1	,1	,&R0VZ71LZ2},	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
	 239	,1	,1	,&R1AD10LDU},	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
	 240	,1	,1	,&R1AD20LDU},	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
	 241	,1	,1	,&R1IS11LDU},	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
	 242	,1	,1	,&R1IS21LDU},	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
	 243	,1	,1	,&R1VS12LDU},	//( - , SCM) Движение МДЗ1 в сторону ВУ
	 244	,1	,1	,&R1VS22LDU},	//( - , SCM) Движение МДЗ1 в сторону НУ
	 245	,1	,1	,&R2AD10LDU},	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
	 246	,1	,1	,&R2AD20LDU},	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
	 247	,1	,1	,&R2IS11LDU},	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
	 248	,1	,1	,&R2IS21LDU},	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
	 249	,1	,1	,&R2VS12LDU},	//( - , SCM) Движение МДЗ2 в сторону ВУ
	 250	,1	,1	,&R2VS22LDU},	//( - , SCM) Движение МДЗ2 в сторону НУ
	 251	,1	,1	,&R3IS11LDU},	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
	 252	,1	,1	,&R3IS21LDU},	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
	 253	,1	,1	,&R4AD10LDU},	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
	 254	,1	,1	,&R4AD20LDU},	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
	 255	,1	,1	,&R4IS11LDU},	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
	 256	,1	,1	,&R4IS12LDU},	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
	 257	,1	,1	,&R4IS21LDU},	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
	 258	,1	,1	,&R4IS22LDU},	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
	 259	,1	,1	,&R4VS12LDU},	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
	 260	,1	,1	,&R4VS22LDU},	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
	 261	,1	,1	,&R5IS11LDU},	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
	 262	,1	,1	,&R5IS21LDU},	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
	 263	,1	,1	,&R6IS21LDU},	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
	 264	,1	,1	,&R6IS62LDU},	//( - , - ) Исправность ВИП ССДИ-39 1канал
	 265	,1	,1	,&R6IS63LDU},	//( - , - ) Исправность ВИП ССДИ-39 2канал
	 266	,1	,1	,&R6IS64LDU},	//( - , - ) Исправность ВИП ССДИ-35 1канал
	 267	,1	,1	,&R6IS65LDU},	//( - , - ) Исправность ВИП ССДИ-35 2канал
	 268	,1	,1	,&R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	 269	,1	,1	,&R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	 270	,1	,1	,&R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
	 271	,1	,1	,&R7II71LZ1},	//(do32_pti:110 - K08DO, - ) Сработала АС IУР (датчик 1)
	 272	,1	,1	,&R7II71LZ2},	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
	 273	,1	,1	,&R7II72LZ1},	//(do32_pti:110 - K07DO, - ) Сработала АС IУР (датчик 2)
	 274	,1	,1	,&R7II72LZ2},	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
	 275	,1	,1	,&R7II73LZ1},	//(do32_pti:110 - K09DO, - ) Сработала АС IIУР
	 276	,1	,1	,&R7II73LZ2},	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
	 277	,1	,1	,&R8AD21LDU},	//(vds32_pti:310 - K31VDSR, - ) Имитация прихода на ВУ ИС для КВДС
	 278	,1	,1	,&R8AD22LDU},	//(do32_pti:140 - K09DO, - ) Сигнал синхронизации с импульсом
	 279	,1	,1	,&R8IS11LDU},	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
	 280	,3	,1	,&TerR0IN06FRP},	//( - , - ) Неисправности СНМ-11 -1,2
	 281	,1	,1	,&bFirstEnterFlag},	//(bFirstEnterFlag) 
	 282	,8	,1	,&fEM_A0UN01RIM},	//(A0UN01RIM) Мощность источника нейтронов ИНИ
	 283	,8	,1	,&fEM_A0UN02RIM},	//(A0UN02RIM) Мощность источника нейтронов с АНИ
	 284	,8	,1	,&fEM_A0UN07RIM},	//(A0UN07RIM) Доля запаздывающих нейтронов
	 285	,8	,1	,&fEM_A0UP01RIM},	//(A0UP01RIM) Текущее давление в АЗ1,2
	 286	,8	,1	,&fEM_A0UP02RIM},	//(A0UP02RIM) Текущее давление в АЗ1,2
	 287	,8	,1	,&fEM_A0UR01RSP},	//(A0UR01RSP) Стартовая  реактивность АЗ1
	 288	,8	,1	,&fEM_A0UR02RSP},	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
	 289	,8	,1	,&fEM_A0UT03RSP},	//(A0UT03RSP) Стартовая  температура АЗ1 град
	 290	,8	,1	,&fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	 291	,8	,1	,&fEM_A0UX01RSS},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	 292	,8	,1	,&fEM_A0UX02RSS},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	 293	,8	,1	,&fEM_A0UX03RSS},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	 294	,8	,1	,&fEM_A0UX04RSS},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	 295	,8	,1	,&fEM_A0UX05RSS},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	 296	,8	,1	,&fEM_A0UX06RSS},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	 297	,8	,1	,&fEM_A0UX07RSS},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	 298	,8	,1	,&fEM_A0UX08RSS},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	 299	,8	,1	,&fEM_A0UX09RSS},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	 300	,8	,1	,&fEM_A0UX10RSS},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	 301	,8	,1	,&fEM_A0UX11RSS},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	 302	,8	,1	,&fEM_A0UX12RSS},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	 303	,8	,1	,&fEM_A0UX13RSS},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	 304	,8	,1	,&fEM_A0UX14RSS},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	 305	,8	,1	,&fEM_A0UX15RSS},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	 306	,8	,1	,&fEM_A1MC01RC1},	//(A1MC01RC1) Заданная координата  ББ1 от ИС
	 307	,8	,1	,&fEM_A1MC01RSP},	//(A1MC01RSP) Стартовая координата  ББ1
	 308	,8	,1	,&fEM_A1MC02RC1},	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
	 309	,8	,1	,&fEM_A1MC02RSP},	//(A1MC02RSP) Стартовая координата штока ББ1
	 310	,8	,1	,&fEM_A1MV01RC1},	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
	 311	,8	,1	,&fEM_A1MV02RC1},	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
	 312	,8	,1	,&fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	 313	,8	,1	,&fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	 314	,8	,1	,&fEM_A1UC04RIM},	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
	 315	,8	,1	,&fEM_A1UC05RIM},	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
	 316	,8	,1	,&fEM_A1UC06RIM},	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
	 317	,8	,1	,&fEM_A1UC08RIM},	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
	 318	,8	,1	,&fEM_A1UG01RDU},	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
	 319	,8	,1	,&fEM_A1UP01RIM},	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
	 320	,8	,1	,&fEM_A1UP82RIM},	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	 321	,8	,1	,&fEM_A1UR00RIM},	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	 322	,8	,1	,&fEM_A1UR01RIM},	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	 323	,8	,1	,&fEM_A1US07RDU},	//(A1US07RDU) Постоянная времени масляного демпфера ББ
	 324	,8	,1	,&fEM_A1UV02RIM},	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	 325	,8	,1	,&fEM_A2MC01RC1},	//(A2MC01RC1) Заданная координата РБ1 от ИС
	 326	,8	,1	,&fEM_A2MC01RSP},	//(A2MC01RSP) Стартовая координата  РБ1
	 327	,8	,1	,&fEM_A2MC02RC1},	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
	 328	,8	,1	,&fEM_A2MC02RSP},	//(A2MC02RSP) Стартовая координата штока РБ1
	 329	,8	,1	,&fEM_A2MV01RC1},	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
	 330	,8	,1	,&fEM_A2MV02RC1},	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
	 331	,8	,1	,&fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	 332	,8	,1	,&fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	 333	,8	,1	,&fEM_A2UC04RIM},	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
	 334	,8	,1	,&fEM_A2UC05RIM},	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
	 335	,8	,1	,&fEM_A2UC06RIM},	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
	 336	,8	,1	,&fEM_A2UC08RIM},	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
	 337	,8	,1	,&fEM_A2UG01RDU},	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
	 338	,8	,1	,&fEM_A2UP01RIM},	//(A2UP01RIM) Текущее давление на сброс РБ
	 339	,8	,1	,&fEM_A2UP02RIM},	//(A2UP02RIM) Текущее давление на подъём РБ
	 340	,8	,1	,&fEM_A2UP03RDU},	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
	 341	,8	,1	,&fEM_A2UP03RIM},	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
	 342	,8	,1	,&fEM_A2UP04RDU},	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
	 343	,8	,1	,&fEM_A2UR00RIM},	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	 344	,8	,1	,&fEM_A2UR01RIM},	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	 345	,8	,1	,&fEM_A2US07RDU},	//(A2US07RDU) Постоянная времени масляного демпфера РБ
	 346	,8	,1	,&fEM_A2UV02RIM},	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	 347	,8	,1	,&fEM_A3MC01RC1},	//(A3MC01RC1) Заданная координата ИС1 от ИС
	 348	,8	,1	,&fEM_A3MC01RSP},	//(A3MC01RSP) Стартовая координата  ИС1
	 349	,8	,1	,&fEM_A3MC02RC1},	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
	 350	,8	,1	,&fEM_A3MC02RSP},	//(A3MC02RSP) Стартовая координата штока ИС1
	 351	,8	,1	,&fEM_A3MV01RC1},	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
	 352	,8	,1	,&fEM_A3MV02RC1},	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
	 353	,8	,1	,&fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	 354	,8	,1	,&fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	 355	,8	,1	,&fEM_A3UC04RIM},	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
	 356	,8	,1	,&fEM_A3UC05RIM},	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
	 357	,8	,1	,&fEM_A3UC06RIM},	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
	 358	,8	,1	,&fEM_A3UC08RIM},	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
	 359	,8	,1	,&fEM_A3UG01RDU},	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
	 360	,8	,1	,&fEM_A3UP01RIM},	//(A3UP01RIM) Текущее давление на СПУСК ИС
	 361	,8	,1	,&fEM_A3UP02RDU},	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
	 362	,8	,1	,&fEM_A3UP02RIM},	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
	 363	,8	,1	,&fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	 364	,8	,1	,&fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	 365	,8	,1	,&fEM_A3UR00RIM},	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	 366	,8	,1	,&fEM_A3UR01RIM},	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	 367	,8	,1	,&fEM_A3US07RDU},	//(A3US07RDU) Постоянная времени масляного демпфера ИС
	 368	,8	,1	,&fEM_A3UV02RIM},	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	 369	,8	,1	,&fEM_A4MC01RSP},	//(A4MC01RSP) Стартовая координата НИ1
	 370	,8	,1	,&fEM_A4UL10RIM},	//(A4UL10RIM) Время полного перемещения НИ сек
	 371	,8	,1	,&fEM_A4UP01RIM},	//(A4UP01RIM) Текущее давление на подъём НИ
	 372	,8	,1	,&fEM_A4UP02RIM},	//(A4UP02RIM) Нижняя граница давления на подъём НИ
	 373	,8	,1	,&fEM_A5MC01RC1},	//(A5MC01RC1) Заданная координата НЛ1 от ИС
	 374	,8	,1	,&fEM_A5MC01RSP},	//(A5MC01RSP) Стартовая координата НЛ1
	 375	,8	,1	,&fEM_A5MV01RC1},	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
	 376	,8	,1	,&fEM_A5UC10RIM},	//(A5UC10RIM) Время полного хода НЛ сек
	 377	,8	,1	,&fEM_A6MC01RC1},	//(A6MC01RC1) Заданная координата БЗ1 от ИС
	 378	,8	,1	,&fEM_A6MC01RSP},	//(A6MC01RSP) Стартовая координата БЗ1
	 379	,8	,1	,&fEM_A6MV01RC1},	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
	 380	,8	,1	,&fEM_A6UC10RIM},	//(A6UC10RIM) Время полного хода БЗ (сек)
	 381	,8	,1	,&fEM_A6US80RDU},	//(A6US80RDU) Тормозной путь БЗ (мм)
	 382	,8	,1	,&fEM_A8MC01RC1},	//(A8MC01RC1) Заданная координата ДС2 от ИС
	 383	,8	,1	,&fEM_A8MC01RSP},	//(A8MC01RSP) Стартовая координата ДС2
	 384	,8	,1	,&fEM_A8MV01RC1},	//(A8MV01RC1) Заданная скорость ДС2 от ИС
	 385	,8	,1	,&fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	 386	,8	,1	,&fEM_A8UC08RDU},	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
	 387	,8	,1	,&fEM_A8UC10RIM},	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
	 388	,8	,1	,&fEM_A8UC11RIM},	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
	 389	,8	,1	,&fEM_A8UC20RIM},	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
	 390	,8	,1	,&fEM_A8UC21RIM},	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
	 391	,8	,1	,&fEM_A8US80RDU},	//(A8US80RDU) Тормозной путь ДС2 (мм)
	 392	,8	,1	,&fEM_A8UV80RDU},	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
	 393	,8	,1	,&fEM_A9MC01RSP},	//(A9MC01RSP) Стартовая координата НИ ДС1
	 394	,8	,1	,&fEM_A9UL10RIM},	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
	 395	,8	,1	,&fEM_B0UT03RSP},	//(B0UT03RSP) Стартовая  температура АЗ2 град
	 396	,8	,1	,&fEM_B0UX01RSS},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	 397	,8	,1	,&fEM_B0UX02RSS},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	 398	,8	,1	,&fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	 399	,8	,1	,&fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
	 400	,8	,1	,&fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	 401	,8	,1	,&fEM_B0UX06RSS},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	 402	,8	,1	,&fEM_B0UX07RSS},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	 403	,8	,1	,&fEM_B0UX08RSS},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	 404	,8	,1	,&fEM_B0UX09RSS},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	 405	,8	,1	,&fEM_B0UX10RSS},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	 406	,8	,1	,&fEM_B0UX11RSS},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	 407	,8	,1	,&fEM_B0UX12RSS},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	 408	,8	,1	,&fEM_B1MC01RC1},	//(B1MC01RC1) Заданная координата ББ2 от ИС
	 409	,8	,1	,&fEM_B1MC01RSP},	//(B1MC01RSP) Стартовая координата  ББ2
	 410	,8	,1	,&fEM_B1MC02RC1},	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
	 411	,8	,1	,&fEM_B1MC02RSP},	//(B1MC02RSP) Стартовая координата штока ББ2
	 412	,8	,1	,&fEM_B1MV01RC1},	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
	 413	,8	,1	,&fEM_B1MV02RC1},	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
	 414	,8	,1	,&fEM_B2MC01RC1},	//(B2MC01RC1) Заданная координата РБ2 от ИС
	 415	,8	,1	,&fEM_B2MC01RSP},	//(B2MC01RSP) Стартовая координата  РБ2
	 416	,8	,1	,&fEM_B2MC02RC1},	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
	 417	,8	,1	,&fEM_B2MC02RSP},	//(B2MC02RSP) Стартовая координата штока РБ2
	 418	,8	,1	,&fEM_B2MV01RC1},	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
	 419	,8	,1	,&fEM_B2MV02RC1},	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
	 420	,8	,1	,&fEM_B3MC01RC1},	//(B3MC01RC1) Заданная координата ИС2 от ИС
	 421	,8	,1	,&fEM_B3MC01RSP},	//(B3MC01RSP) Стартовая координата  ИС2
	 422	,8	,1	,&fEM_B3MC02RC1},	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
	 423	,8	,1	,&fEM_B3MC02RSP},	//(B3MC02RSP) Стартовая координата штока ИС2
	 424	,8	,1	,&fEM_B3MV01RC1},	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
	 425	,8	,1	,&fEM_B3MV02RC1},	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
	 426	,8	,1	,&fEM_B4MC01RSP},	//(B4MC01RSP) Стартовая координата НИ2
	 427	,8	,1	,&fEM_B5MC01RC1},	//(B5MC01RC1) Заданная координата НЛ2 от ИС
	 428	,8	,1	,&fEM_B5MC01RSP},	//(B5MC01RSP) Стартовая координата НЛ2
	 429	,8	,1	,&fEM_B5MV01RC1},	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
	 430	,8	,1	,&fEM_B6MC01RC1},	//(B6MC01RC1) Заданная координата БЗ2 от ИС
	 431	,8	,1	,&fEM_B6MC01RSP},	//(B6MC01RSP) Стартовая координата БЗ2
	 432	,8	,1	,&fEM_B6MV01RC1},	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
	 433	,8	,1	,&fEM_B8MC01RC1},	//(B8MC01RC1) Заданная координата АЗ2 от ИС
	 434	,8	,1	,&fEM_B8MC01RSP},	//(B8MC01RSP) Стартовая координата АЗ2
	 435	,8	,1	,&fEM_B8MV01RC1},	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
	 436	,8	,1	,&fEM_B8UC08RDU},	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
	 437	,8	,1	,&fEM_B8UC10RIM},	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
	 438	,8	,1	,&fEM_B8UC11RIM},	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
	 439	,8	,1	,&fEM_B8UC20RIM},	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
	 440	,8	,1	,&fEM_B8UC21RIM},	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
	 441	,8	,1	,&fEM_B8US80RDU},	//(B8US80RDU) Тормозной путь АЗ2 (мм)
	 442	,8	,1	,&fEM_B8UV80RDU},	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
	 443	,8	,1	,&fEM_B9MC01RSP},	//(B9MC01RSP) Стартовая координата НИ ДС2
	 444	,8	,1	,&fEM_R0UH01RSS},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
	 445	,8	,1	,&fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
	 446	,8	,1	,&fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
	 447	,8	,1	,&fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	 448	,8	,1	,&fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	 449	,8	,1	,&fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	 450	,8	,1	,&fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	 451	,8	,1	,&fEM_R0UL01RIM},	//(R0UL01RIM) Среднее время генерации нейтронов
	 452	,8	,1	,&fEM_R0UL02RDU},	//(R0UL02RDU) Время задержки  ИНИ
	 453	,8	,1	,&fEM_R0UL02RIM},	//(R0UL02RIM) Время удержания синхроимпульса
	 454	,8	,1	,&fEM_R0UL04RIM},	//(R0UL04RIM) Время блокировки повторной генерации импульса
	 455	,8	,1	,&fEM_R0UN02RIM},	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
	 456	,8	,1	,&fEM_R0UR01RIM},	//(R0UR01RIM) Стартовая отрицательная реактивность
	 457	,8	,1	,&fEM_R0UR30RIM},	//(R0UR30RIM) Реактивность вносимая образцами (долл)
	 458	,8	,1	,&fEM_R0UT01RDU},	//(R0UT01RDU) Нижний предел шкалы датчика температуры
	 459	,8	,1	,&fEM_R0UT01RIM},	//(R0UT01RIM) Температурный коэффициент (долл)
	 460	,8	,1	,&fEM_R0UT02RDU},	//(R0UT02RDU) Верхний предел шкалы датчика температуры
	 461	,8	,1	,&fEM_R0UT02RIM},	//(R0UT02RIM) Масса топлива в АЗ
	 462	,8	,1	,&fEM_R0UT03RIM},	//(R0UT03RIM) Нормальная температура АЗ град
	 463	,8	,1	,&fEM_R0UT04RIM},	//(R0UT04RIM) Удельная теплоёмкость топлива
	 464	,8	,1	,&fEM_R0UT05RIM},	//(R0UT05RIM) Энергия деления ядра
	 465	,8	,1	,&fEM_R0UT06RIM},	//(R0UT06RIM) Конвекционное сопротивление при обдуве
	 466	,8	,1	,&fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	 467	,8	,1	,&fEM_R0UV82RDU},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	 468	,8	,1	,&fEM_R0UV83RDU},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	 469	,8	,1	,&fEM_R0UV84RDU},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	 470	,8	,1	,&fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	 471	,8	,1	,&fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	 472	,8	,1	,&fEM_R0UV87RDU},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	 473	,8	,1	,&fEM_R1MC01RC1},	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
	 474	,8	,1	,&fEM_R1MC01RSP},	//(R1MC01RSP) Стартовая координата МДЗ1
	 475	,8	,1	,&fEM_R1MV01RC1},	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
	 476	,8	,1	,&fEM_R1UC10RIM},	//(R1UC10RIM) Время полного хода МДЗ сек
	 477	,8	,1	,&fEM_R2MC01RC1},	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
	 478	,8	,1	,&fEM_R2MC01RSP},	//(R2MC01RSP) Стартовая координата МДЗ2
	 479	,8	,1	,&fEM_R2MV01RC1},	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
	 480	,8	,1	,&fEM_R3UC01RSP},	//(R3UC01RSP) Стартовая координата Гомогенных дверей
	 481	,8	,1	,&fEM_R3UL10RIM},	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
	 482	,8	,1	,&fEM_R4MC01RC1},	//(R4MC01RC1) Заданная координата тележки от ИС
	 483	,8	,1	,&fEM_R4MC01RSP},	//(R4MC01RSP) Стартовая координата тележки
	 484	,8	,1	,&fEM_R4MV01RC1},	//(R4MV01RC1) Заданная скорость тележки от ИС
	 485	,8	,1	,&fEM_R4UC08RDU},	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
	 486	,8	,1	,&fEM_R4UC10RIM},	//(R4UC10RIM) Координата верхних механических упоров тележки мм
	 487	,8	,1	,&fEM_R4UC20RIM},	//(R4UC20RIM) Координата нижних механических упоров тележки мм
	 488	,8	,1	,&fEM_R4UC22RIM},	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
	 489	,8	,1	,&fEM_R4US80RDU},	//(R4US80RDU) Тормозной путь тележки (мм)
	 490	,8	,1	,&fEM_R4UV80RDU},	//(R4UV80RDU) Номинальная скорость тележки (см/с)
	 491	,8	,1	,&fEM_R5UC01RSP},	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
	 492	,8	,1	,&fEM_R5UL10RIM},	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
	 493	,8	,1	,&fEM_R6UC01RSP},	//(R6UC01RSP) Стартовая координата Кран-балки
	 494	,8	,1	,&fEM_R6UL10RIM},	//(R6UL10RIM) Время полного хода кран-балки сек
	 495	,8	,1	,&fEM_R7UC10RIM},	//(R7UC10RIM) X-координата КНК53М R7IN13 см
	 496	,8	,1	,&fEM_R7UC19RIM},	//(R7UC19RIM) Y-координата СНМ-11 (11) см
	 497	,8	,1	,&fEM_R7UI02RIM},	//(R7UI02RIM) Коэффициент усиления уровня радиации
	 498	,8	,1	,&fEM_R7UI71RIM},	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	 499	,8	,1	,&fEM_R7UI72RIM},	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	 500	,8	,1	,&fEM_R7UI73RIM},	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
	 501	,8	,1	,&fEM_R7UI74RIM},	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
	 502	,8	,1	,&fEM_R7UI75RIM},	//(R7UI75RIM) Множитель к уровню радиации
	 503	,8	,1	,&fEM_R7UI76RIM},	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	 504	,8	,1	,&fEM_R7UI77RIM},	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	 505	,8	,1	,&fEM_R7UL01RIM},	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
	 506	,8	,1	,&fEM_R7UX01RSS},	//(R7UX01RSS) X-координата камеры R7IN11
	 507	,8	,1	,&fEM_R7UX02RSS},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	 508	,8	,1	,&fEM_R7UX04RSS},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	 509	,8	,1	,&fEM_R7UX05RSS},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	 510	,8	,1	,&fEM_R7UX06RSS},	//(R7UX06RSS) X-координата камеры R7IN23 (см)
	 511	,8	,1	,&fEM_R7UX07RSS},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	 512	,8	,1	,&fEM_R7UX08RSS},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	 513	,8	,1	,&fEM_R7UX09RSS},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	 514	,8	,1	,&fEM_R7UX10RSS},	//(R7UX10RSS) X-координата камеры R7IN41
	 515	,8	,1	,&fEM_R7UX11RSS},	//(R7UX11RSS) X-координата камеры R7IN42
	 516	,8	,1	,&fEM_R7UX12RSS},	//(R7UX12RSS) X-координата камеры R7IN43
	 517	,8	,1	,&fEM_R7UX13RSS},	//(R7UX13RSS) X-координата камеры R7IN51
	 518	,8	,1	,&fEM_R7UX14RSS},	//(R7UX14RSS) X-координата камеры R7IN52
	 519	,8	,1	,&fEM_R7UX15RSS},	//(R7UX15RSS) X-координата камеры R7IN53
	 520	,8	,1	,&fEM_R7UX16RSS},	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
	 521	,8	,1	,&fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 см
	 522	,8	,1	,&fEM_R7UY01RSS},	//(R7UY01RSS) Y-координата камеры R7IN11
	 523	,8	,1	,&fEM_R7UY02RSS},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	 524	,8	,1	,&fEM_R7UY04RSS},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	 525	,8	,1	,&fEM_R7UY05RSS},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	 526	,8	,1	,&fEM_R7UY06RSS},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	 527	,8	,1	,&fEM_R7UY07RSS},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	 528	,8	,1	,&fEM_R7UY08RSS},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	 529	,8	,1	,&fEM_R7UY09RSS},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	 530	,8	,1	,&fEM_R7UY10RSS},	//(R7UY10RSS) Y-координата камеры R7IN41
	 531	,8	,1	,&fEM_R7UY11RSS},	//(R7UY11RSS) Y-координата камеры R7IN42
	 532	,8	,1	,&fEM_R7UY12RSS},	//(R7UY12RSS) Y-координата камеры R7IN43
	 533	,8	,1	,&fEM_R7UY13RSS},	//(R7UY13RSS) Y-координата камеры R7IN51
	 534	,8	,1	,&fEM_R7UY14RSS},	//(R7UY14RSS) Y-координата камеры R7IN52
	 535	,8	,1	,&fEM_R7UY15RSS},	//(R7UY15RSS) Y-координата камеры R7IN53
	 536	,3	,1	,&iEM_TERA0MT01RIM},	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
	 537	,3	,1	,&iEM_TERA0VP81LIM},	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
	 538	,3	,1	,&iEM_TERA1IE03LDU},	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
	 539	,3	,1	,&iEM_TERA1IE04LDU},	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
	 540	,3	,1	,&iEM_TERA1SC01RIM},	//(TERA1SC01RIM) Искажение: Координата штока ББ1
	 541	,3	,1	,&iEM_TERA1SS11LIM},	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
	 542	,3	,1	,&iEM_TERA1SS12LIM},	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
	 543	,3	,1	,&iEM_TERA1SS21LIM},	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
	 544	,3	,1	,&iEM_TERA1VP81LIM},	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
	 545	,3	,1	,&iEM_TERA2SC01RIM},	//(TERA2SC01RIM) Искажение: Координата штока РБ1
	 546	,3	,1	,&iEM_TERA2SP01RIM},	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
	 547	,3	,1	,&iEM_TERA2SS11LIM},	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
	 548	,3	,1	,&iEM_TERA2SS12LIM},	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
	 549	,3	,1	,&iEM_TERA2SS21LIM},	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
	 550	,3	,1	,&iEM_TERA2SS33LIM},	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	 551	,3	,1	,&iEM_TERA2VP82LIM},	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
	 552	,3	,1	,&iEM_TERA3SC01RIM},	//(TERA3SC01RIM) Искажение: Координата штока ИС1
	 553	,3	,1	,&iEM_TERA3SP02RIM},	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	 554	,3	,1	,&iEM_TERA3SS11LIM},	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
	 555	,3	,1	,&iEM_TERA3SS21LIM},	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
	 556	,3	,1	,&iEM_TERA3SS22LIM},	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
	 557	,3	,1	,&iEM_TERA3SS31LIM},	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	 558	,3	,1	,&iEM_TERA3SS33LIM},	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	 559	,3	,1	,&iEM_TERA3VP81LIM},	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
	 560	,3	,1	,&iEM_TERA4SS11LIM},	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
	 561	,3	,1	,&iEM_TERA4SS21LIM},	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
	 562	,3	,1	,&iEM_TERA4VP82LIM},	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
	 563	,3	,1	,&iEM_TERA5SS11LIM},	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	 564	,3	,1	,&iEM_TERA5SS21LIM},	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
	 565	,3	,1	,&iEM_TERA5VS12LIM},	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
	 566	,3	,1	,&iEM_TERA5VS22LIM},	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
	 567	,3	,1	,&iEM_TERA6MS11LIM},	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
	 568	,3	,1	,&iEM_TERA6SS21LIM},	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
	 569	,3	,1	,&iEM_TERA6VS12LIM},	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	 570	,3	,1	,&iEM_TERA6VS22LIM},	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	 571	,3	,1	,&iEM_TERA7MS31LIM},	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	 572	,3	,1	,&iEM_TERA8SC01RIM},	//(TERA8SC01RIM) Искажение: Координата ДС2
	 573	,3	,1	,&iEM_TERA8SS12LIM},	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
	 574	,3	,1	,&iEM_TERA8SS22LIM},	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
	 575	,3	,1	,&iEM_TERA9SS11LIM},	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
	 576	,3	,1	,&iEM_TERA9SS21LIM},	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
	 577	,3	,1	,&iEM_TERB0MT01RIM},	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
	 578	,3	,1	,&iEM_TERB0VP81LIM},	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
	 579	,3	,1	,&iEM_TERB1IE03LDU},	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
	 580	,3	,1	,&iEM_TERB1IE04LDU},	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
	 581	,3	,1	,&iEM_TERB1MC01RIM},	//(TERB1MC01RIM) Искажение: Координата штока ББ2
	 582	,3	,1	,&iEM_TERB1SS11LIM},	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
	 583	,3	,1	,&iEM_TERB1SS12LIM},	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
	 584	,3	,1	,&iEM_TERB1SS21LIM},	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
	 585	,3	,1	,&iEM_TERB1VP81LIM},	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
	 586	,3	,1	,&iEM_TERB2SC01RIM},	//(TERB2SC01RIM) Искажение: Координата штока РБ2
	 587	,3	,1	,&iEM_TERB2SP01RIM},	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
	 588	,3	,1	,&iEM_TERB2SS11LIM},	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
	 589	,3	,1	,&iEM_TERB2SS12LIM},	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
	 590	,3	,1	,&iEM_TERB2SS21LIM},	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
	 591	,3	,1	,&iEM_TERB2SS33LIM},	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	 592	,3	,1	,&iEM_TERB3SC01RIM},	//(TERB3SC01RIM) Искажение: Координата штока ИС2
	 593	,3	,1	,&iEM_TERB3SP02RIM},	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	 594	,3	,1	,&iEM_TERB3SS11LIM},	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
	 595	,3	,1	,&iEM_TERB3SS21LIM},	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
	 596	,3	,1	,&iEM_TERB3SS22LIM},	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
	 597	,3	,1	,&iEM_TERB3SS31LIM},	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	 598	,3	,1	,&iEM_TERB3SS33LIM},	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	 599	,3	,1	,&iEM_TERB4SS11LIM},	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
	 600	,3	,1	,&iEM_TERB4SS21LIM},	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
	 601	,3	,1	,&iEM_TERB5SS11LIM},	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
	 602	,3	,1	,&iEM_TERB5SS21LIM},	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
	 603	,3	,1	,&iEM_TERB5VS12LIM},	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
	 604	,3	,1	,&iEM_TERB5VS22LIM},	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
	 605	,3	,1	,&iEM_TERB6SS11LIM},	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
	 606	,3	,1	,&iEM_TERB6SS21LIM},	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
	 607	,3	,1	,&iEM_TERB6VS12LIM},	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	 608	,3	,1	,&iEM_TERB6VS22LIM},	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	 609	,3	,1	,&iEM_TERB7MS31LIM},	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	 610	,3	,1	,&iEM_TERB8SC01RIM},	//(TERB8SC01RIM) Искажение: Координата АЗ2
	 611	,3	,1	,&iEM_TERB8SS12LIM},	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
	 612	,3	,1	,&iEM_TERB8SS22LIM},	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
	 613	,3	,1	,&iEM_TERB9SS11LIM},	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
	 614	,3	,1	,&iEM_TERB9SS21LIM},	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
	 615	,3	,1	,&iEM_TERBB1},	//(TERBB1) Неисправности  ББ1
	 616	,3	,1	,&iEM_TERBB2},	//(TERBB2) Неисправности  ББ2
	 617	,3	,1	,&iEM_TERBZ1},	//(TERBZ1) Неисправности БЗ1
	 618	,3	,1	,&iEM_TERBZ2},	//(TERBZ2) Неисправности БЗ2
	 619	,3	,1	,&iEM_TERDS2},	//(TERDS2) Неисправности ДС2 от ИС
	 620	,3	,1	,&iEM_TERIS1},	//(TERIS1) Неисправности  ИС1
	 621	,3	,1	,&iEM_TERIS2},	//(TERIS2) Неисправности  ИС2
	 622	,3	,1	,&iEM_TERMAZ2},	//(TERMAZ2) Неисправности АЗ2 от ИС
	 623	,3	,1	,&iEM_TERMDZ1},	//(TERMDZ1) Неисправности МДЗ1
	 624	,3	,1	,&iEM_TERMDZ2},	//(TERMDZ2) Неисправности МДЗ2
	 625	,3	,1	,&iEM_TERNL1},	//(TERNL1) Неисправности НЛ1
	 626	,3	,1	,&iEM_TERNL2},	//(TERNL2) Неисправности НЛ2
	 627	,3	,1	,&iEM_TERR0VP81LIM},	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	 628	,3	,1	,&iEM_TERR1SS11LIM},	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
	 629	,3	,1	,&iEM_TERR1SS21LIM},	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
	 630	,3	,1	,&iEM_TERR1VS12LIM},	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
	 631	,3	,1	,&iEM_TERR1VS22LIM},	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
	 632	,3	,1	,&iEM_TERR2SS11LIM},	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
	 633	,3	,1	,&iEM_TERR2SS21LIM},	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
	 634	,3	,1	,&iEM_TERR2VS12LIM},	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
	 635	,3	,1	,&iEM_TERR2VS22LIM},	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
	 636	,3	,1	,&iEM_TERR3SS11LIM},	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
	 637	,3	,1	,&iEM_TERR3SS21LIM},	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
	 638	,3	,1	,&iEM_TERR4MS21LIM},	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
	 639	,3	,1	,&iEM_TERR4SS11LIM},	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
	 640	,3	,1	,&iEM_TERR4SS12LIM},	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
	 641	,3	,1	,&iEM_TERR4SS22LIM},	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
	 642	,3	,1	,&iEM_TERR4VS12LDU},	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	 643	,3	,1	,&iEM_TERR4VS22LDU},	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	 644	,3	,1	,&iEM_TERR5SS11LIM},	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
	 645	,3	,1	,&iEM_TERR5SS21LIM},	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
	 646	,3	,1	,&iEM_TERR6IS62LIM},	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
	 647	,3	,1	,&iEM_TERR6IS64LIM},	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
	 648	,3	,1	,&iEM_TERR6IS66LIM},	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	 649	,3	,1	,&iEM_TERR6IS67LIM},	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	 650	,3	,1	,&iEM_TERR6IS68LIM},	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	 651	,3	,1	,&iEM_TERR6SS21LIM},	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
	 652	,3	,1	,&iEM_TERR7SI74RIM},	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
	 653	,3	,1	,&iEM_TERR8SS11LIM},	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
	 654	,3	,1	,&iEM_TERRB1},	//(TERRB1) Неисправности  РБ1
	 655	,3	,1	,&iEM_TERRB2},	//(TERRB2) Неисправности  РБ2
	 656	,3	,1	,&iEM_TERTLG},	//(TERTLG) Неисправности  тележки от ИС
	 657	,1	,1	,&internal1_m1010_Out10},	//(internal1_m1010_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 658	,1	,1	,&internal1_m1011_Out10},	//(internal1_m1011_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 659	,1	,1	,&internal1_m1012_Out10},	//(internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 660	,1	,1	,&internal1_m1013_Out10},	//(internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 661	,1	,1	,&internal1_m1014_Out10},	//(internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 662	,1	,1	,&internal1_m1015_Out10},	//(internal1_m1015_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 663	,1	,1	,&internal1_m1016_Out10},	//(internal1_m1016_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 664	,1	,1	,&internal1_m1030_Out10},	//(internal1_m1030_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 665	,1	,1	,&internal1_m1031_Out10},	//(internal1_m1031_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 666	,1	,1	,&internal1_m1032_Out10},	//(internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 667	,1	,1	,&internal1_m1033_Out10},	//(internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 668	,1	,1	,&internal1_m1034_Out10},	//(internal1_m1034_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 669	,1	,1	,&internal1_m1035_Out10},	//(internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 670	,1	,1	,&internal1_m132_MyFirstEnterFlag},	//(internal1_m132_MyFirstEnterFlag) MyFirstEnterFlag
	 671	,1	,1	,&internal1_m132_Pav0},	//(internal1_m132_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	 672	,1	,1	,&internal1_m132_Ppv0},	//(internal1_m132_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	 673	,1	,1	,&internal1_m132_RA00},	//(internal1_m132_RA00) RA00 - последнее задание вперед
	 674	,1	,1	,&internal1_m132_RA10},	//(internal1_m132_RA10) RA10 - последнее задание назад
	 675	,1	,1	,&internal1_m132_RA30},	//(internal1_m132_RA30)  RA30 - разрешение движения
	 676	,1	,1	,&internal1_m132_RA50},	//(internal1_m132_RA50) Ra50 - последнее задание скорости
	 677	,8	,1	,&internal1_m132_RV00},	//(internal1_m132_RV00) V0 - текущая скорость ОРР
	 678	,8	,1	,&internal1_m132_Sh00},	//(internal1_m132_Sh00) Sh0 - текущая координата штока ОРР
	 679	,8	,1	,&internal1_m132_ShV00},	//(internal1_m132_ShV00) V0 - текущая скорость штока ОРР
	 680	,8	,1	,&internal1_m132_X00},	//(internal1_m132_X00) X0 - текущая координата ОРР
	 681	,1	,1	,&internal1_m132_Zav0},	//(internal1_m132_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	 682	,1	,1	,&internal1_m132_flp},	//(internal1_m132_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	 683	,1	,1	,&internal1_m132_fls},	//(internal1_m132_fls)  fls - флаг одношагового режима
	 684	,8	,1	,&internal1_m14_C1},	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	 685	,8	,1	,&internal1_m14_C2},	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	 686	,8	,1	,&internal1_m14_C3},	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	 687	,8	,1	,&internal1_m14_C4},	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	 688	,8	,1	,&internal1_m14_C5},	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	 689	,8	,1	,&internal1_m14_C6},	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	 690	,1	,1	,&internal1_m14_ImpINI0},	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	 691	,1	,1	,&internal1_m14_MyFirstEnterFlag},	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
	 692	,8	,1	,&internal1_m14_N00},	//(internal1_m14_N00) N00 - Текущая концентрация нейтронов
	 693	,8	,1	,&internal1_m14_N20},	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
	 694	,8	,1	,&internal1_m14_R00},	//(internal1_m14_R00) R00 - Текущая реактивность
	 695	,8	,1	,&internal1_m14_T00},	//(internal1_m14_T00) T00 - Текущая температура
	 696	,1	,1	,&internal1_m150_Out10},	//(internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 697	,1	,1	,&internal1_m151_Out10},	//(internal1_m151_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 698	,8	,1	,&internal1_m184_C1},	//(internal1_m184_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	 699	,8	,1	,&internal1_m184_C2},	//(internal1_m184_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	 700	,8	,1	,&internal1_m184_C3},	//(internal1_m184_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	 701	,8	,1	,&internal1_m184_C4},	//(internal1_m184_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	 702	,8	,1	,&internal1_m184_C5},	//(internal1_m184_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	 703	,8	,1	,&internal1_m184_C6},	//(internal1_m184_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	 704	,1	,1	,&internal1_m184_ImpINI0},	//(internal1_m184_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	 705	,1	,1	,&internal1_m184_MyFirstEnterFlag},	//(internal1_m184_MyFirstEnterFlag) MyFirstEnterFlag
	 706	,8	,1	,&internal1_m184_N00},	//(internal1_m184_N00) N00 - Текущая концентрация нейтронов
	 707	,8	,1	,&internal1_m184_N20},	//(internal1_m184_N20) N20 - пред. концентрация нейтронов второй АЗ
	 708	,8	,1	,&internal1_m184_R00},	//(internal1_m184_R00) R00 - Текущая реактивность
	 709	,8	,1	,&internal1_m184_T00},	//(internal1_m184_T00) T00 - Текущая температура
	 710	,1	,1	,&internal1_m209_Out10},	//(internal1_m209_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 711	,1	,1	,&internal1_m227_Out10},	//(internal1_m227_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 712	,1	,1	,&internal1_m230_MyFirstEnterFlag},	//(internal1_m230_MyFirstEnterFlag) MyFirstEnterFlag
	 713	,1	,1	,&internal1_m230_Pav0},	//(internal1_m230_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	 714	,1	,1	,&internal1_m230_Ppv0},	//(internal1_m230_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	 715	,1	,1	,&internal1_m230_RA00},	//(internal1_m230_RA00) RA00 - последнее задание вперед
	 716	,1	,1	,&internal1_m230_RA10},	//(internal1_m230_RA10) RA10 - последнее задание назад
	 717	,1	,1	,&internal1_m230_RA30},	//(internal1_m230_RA30)  RA30 - разрешение движения
	 718	,1	,1	,&internal1_m230_RA50},	//(internal1_m230_RA50) Ra50 - последнее задание скорости
	 719	,8	,1	,&internal1_m230_RV00},	//(internal1_m230_RV00) V0 - текущая скорость ОРР
	 720	,8	,1	,&internal1_m230_Sh00},	//(internal1_m230_Sh00) Sh0 - текущая координата штока ОРР
	 721	,8	,1	,&internal1_m230_ShV00},	//(internal1_m230_ShV00) V0 - текущая скорость штока ОРР
	 722	,8	,1	,&internal1_m230_X00},	//(internal1_m230_X00) X0 - текущая координата ОРР
	 723	,1	,1	,&internal1_m230_Zav0},	//(internal1_m230_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	 724	,1	,1	,&internal1_m230_flp},	//(internal1_m230_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	 725	,1	,1	,&internal1_m230_fls},	//(internal1_m230_fls)  fls - флаг одношагового режима
	 726	,1	,1	,&internal1_m265_MyFirstEnterFlag},	//(internal1_m265_MyFirstEnterFlag) MyFirstEnterFlag
	 727	,1	,1	,&internal1_m265_Pav0},	//(internal1_m265_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	 728	,1	,1	,&internal1_m265_Ppv0},	//(internal1_m265_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	 729	,1	,1	,&internal1_m265_RA00},	//(internal1_m265_RA00) RA00 - последнее задание вперед
	 730	,1	,1	,&internal1_m265_RA10},	//(internal1_m265_RA10) RA10 - последнее задание назад
	 731	,1	,1	,&internal1_m265_RA30},	//(internal1_m265_RA30)  RA30 - разрешение движения
	 732	,1	,1	,&internal1_m265_RA50},	//(internal1_m265_RA50) Ra50 - последнее задание скорости
	 733	,8	,1	,&internal1_m265_RV00},	//(internal1_m265_RV00) V0 - текущая скорость ОРР
	 734	,8	,1	,&internal1_m265_Sh00},	//(internal1_m265_Sh00) Sh0 - текущая координата штока ОРР
	 735	,8	,1	,&internal1_m265_ShV00},	//(internal1_m265_ShV00) V0 - текущая скорость штока ОРР
	 736	,8	,1	,&internal1_m265_X00},	//(internal1_m265_X00) X0 - текущая координата ОРР
	 737	,1	,1	,&internal1_m265_Zav0},	//(internal1_m265_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	 738	,1	,1	,&internal1_m265_flp},	//(internal1_m265_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	 739	,1	,1	,&internal1_m265_fls},	//(internal1_m265_fls)  fls - флаг одношагового режима
	 740	,1	,1	,&internal1_m301_MyFirstEnterFlag},	//(internal1_m301_MyFirstEnterFlag) MyFirstEnterFlag
	 741	,1	,1	,&internal1_m301_Pav0},	//(internal1_m301_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	 742	,1	,1	,&internal1_m301_Ppv0},	//(internal1_m301_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	 743	,1	,1	,&internal1_m301_RA00},	//(internal1_m301_RA00) RA00 - последнее задание вперед
	 744	,1	,1	,&internal1_m301_RA10},	//(internal1_m301_RA10) RA10 - последнее задание назад
	 745	,1	,1	,&internal1_m301_RA30},	//(internal1_m301_RA30)  RA30 - разрешение движения
	 746	,1	,1	,&internal1_m301_RA50},	//(internal1_m301_RA50) Ra50 - последнее задание скорости
	 747	,8	,1	,&internal1_m301_RV00},	//(internal1_m301_RV00) V0 - текущая скорость ОРР
	 748	,8	,1	,&internal1_m301_Sh00},	//(internal1_m301_Sh00) Sh0 - текущая координата штока ОРР
	 749	,8	,1	,&internal1_m301_ShV00},	//(internal1_m301_ShV00) V0 - текущая скорость штока ОРР
	 750	,8	,1	,&internal1_m301_X00},	//(internal1_m301_X00) X0 - текущая координата ОРР
	 751	,1	,1	,&internal1_m301_Zav0},	//(internal1_m301_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	 752	,1	,1	,&internal1_m301_flp},	//(internal1_m301_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	 753	,1	,1	,&internal1_m301_fls},	//(internal1_m301_fls)  fls - флаг одношагового режима
	 754	,1	,1	,&internal1_m317_Out10},	//(internal1_m317_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 755	,1	,1	,&internal1_m318_Out10},	//(internal1_m318_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 756	,1	,1	,&internal1_m319_Out10},	//(internal1_m319_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 757	,8	,1	,&internal1_m325_Xtek0},	//(internal1_m325_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	 758	,8	,1	,&internal1_m332_Xtek0},	//(internal1_m332_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	 759	,1	,1	,&internal1_m333_Out10},	//(internal1_m333_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 760	,1	,1	,&internal1_m334_Out10},	//(internal1_m334_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 761	,1	,1	,&internal1_m335_Out10},	//(internal1_m335_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 762	,1	,1	,&internal1_m345_Out10},	//(internal1_m345_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 763	,1	,1	,&internal1_m346_Out10},	//(internal1_m346_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 764	,1	,1	,&internal1_m347_Out10},	//(internal1_m347_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 765	,1	,1	,&internal1_m348_Out10},	//(internal1_m348_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 766	,1	,1	,&internal1_m362_MyFirstEnterFlag},	//(internal1_m362_MyFirstEnterFlag) MyFirstEnterFlag
	 767	,1	,1	,&internal1_m362_Pav0},	//(internal1_m362_Pav0)  - Пер.аварийный выключатель механизма
	 768	,1	,1	,&internal1_m362_Pv0},	//(internal1_m362_Pv0)  - Пер. выключатель механизма
	 769	,1	,1	,&internal1_m362_RA00},	//(internal1_m362_RA00)  - последнее задание вперед
	 770	,1	,1	,&internal1_m362_RA10},	//(internal1_m362_RA10)  - последнее задание назад
	 771	,8	,1	,&internal1_m362_V00},	//(internal1_m362_V00)  V00 - текущая скорость механизма
	 772	,8	,1	,&internal1_m362_X00},	//(internal1_m362_X00)  X00 - текущая координата механизма
	 773	,1	,1	,&internal1_m362_Zav0},	//(internal1_m362_Zav0)  - Зад.аварийный выключатель механизма
	 774	,1	,1	,&internal1_m362_Zv0},	//(internal1_m362_Zv0)  - Зад. выключатель механизма
	 775	,1	,1	,&internal1_m378_MyFirstEnterFlag},	//(internal1_m378_MyFirstEnterFlag) MyFirstEnterFlag
	 776	,1	,1	,&internal1_m378_Pav0},	//(internal1_m378_Pav0)  - Пер.аварийный выключатель механизма
	 777	,1	,1	,&internal1_m378_Pv0},	//(internal1_m378_Pv0)  - Пер. выключатель механизма
	 778	,1	,1	,&internal1_m378_RA00},	//(internal1_m378_RA00)  - последнее задание вперед
	 779	,1	,1	,&internal1_m378_RA10},	//(internal1_m378_RA10)  - последнее задание назад
	 780	,8	,1	,&internal1_m378_V00},	//(internal1_m378_V00)  V00 - текущая скорость механизма
	 781	,8	,1	,&internal1_m378_X00},	//(internal1_m378_X00)  X00 - текущая координата механизма
	 782	,1	,1	,&internal1_m378_Zav0},	//(internal1_m378_Zav0)  - Зад.аварийный выключатель механизма
	 783	,1	,1	,&internal1_m378_Zv0},	//(internal1_m378_Zv0)  - Зад. выключатель механизма
	 784	,1	,1	,&internal1_m38_fef},	//(internal1_m38_fef) fef
	 785	,3	,1	,&internal1_m38_reg},	//(internal1_m38_reg) режим работы квдс 0 - ожидание сигнала 1- выдан импульс 2 отсчет удержания синхроимпульса 3 -блокировка
	 786	,8	,1	,&internal1_m38_tgen},	//(internal1_m38_tgen) задержки срабатывания генератора импульса
	 787	,8	,1	,&internal1_m38_tlock},	//(internal1_m38_tlock) время до конца блокировки
	 788	,8	,1	,&internal1_m38_tsin},	//(internal1_m38_tsin) время до конца удержания синхроимпульса
	 789	,1	,1	,&internal1_m393_MyFirstEnterFlag},	//(internal1_m393_MyFirstEnterFlag) MyFirstEnterFlag
	 790	,1	,1	,&internal1_m393_Pav0},	//(internal1_m393_Pav0)  - Пер.аварийный выключатель механизма
	 791	,1	,1	,&internal1_m393_Pv0},	//(internal1_m393_Pv0)  - Пер. выключатель механизма
	 792	,1	,1	,&internal1_m393_RA00},	//(internal1_m393_RA00)  - последнее задание вперед
	 793	,1	,1	,&internal1_m393_RA10},	//(internal1_m393_RA10)  - последнее задание назад
	 794	,8	,1	,&internal1_m393_V00},	//(internal1_m393_V00)  V00 - текущая скорость механизма
	 795	,8	,1	,&internal1_m393_X00},	//(internal1_m393_X00)  X00 - текущая координата механизма
	 796	,1	,1	,&internal1_m393_Zav0},	//(internal1_m393_Zav0)  - Зад.аварийный выключатель механизма
	 797	,1	,1	,&internal1_m393_Zv0},	//(internal1_m393_Zv0)  - Зад. выключатель механизма
	 798	,1	,1	,&internal1_m404_Out10},	//(internal1_m404_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 799	,1	,1	,&internal1_m405_Out10},	//(internal1_m405_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 800	,1	,1	,&internal1_m406_Out10},	//(internal1_m406_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 801	,1	,1	,&internal1_m407_Out10},	//(internal1_m407_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 802	,8	,1	,&internal1_m414_Xtek0},	//(internal1_m414_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	 803	,1	,1	,&internal1_m423_Out10},	//(internal1_m423_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 804	,1	,1	,&internal1_m424_Out10},	//(internal1_m424_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 805	,1	,1	,&internal1_m425_Out10},	//(internal1_m425_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 806	,1	,1	,&internal1_m426_Out10},	//(internal1_m426_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 807	,8	,1	,&internal1_m427_Xtek0},	//(internal1_m427_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	 808	,1	,1	,&internal1_m441_MyFirstEnterFlag},	//(internal1_m441_MyFirstEnterFlag) MyFirstEnterFlag
	 809	,1	,1	,&internal1_m441_Pav0},	//(internal1_m441_Pav0)  - Пер.аварийный выключатель механизма
	 810	,1	,1	,&internal1_m441_Pv0},	//(internal1_m441_Pv0)  - Пер. выключатель механизма
	 811	,1	,1	,&internal1_m441_RA00},	//(internal1_m441_RA00)  - последнее задание вперед
	 812	,1	,1	,&internal1_m441_RA10},	//(internal1_m441_RA10)  - последнее задание назад
	 813	,8	,1	,&internal1_m441_V00},	//(internal1_m441_V00)  V00 - текущая скорость механизма
	 814	,8	,1	,&internal1_m441_X00},	//(internal1_m441_X00)  X00 - текущая координата механизма
	 815	,1	,1	,&internal1_m441_Zav0},	//(internal1_m441_Zav0)  - Зад.аварийный выключатель механизма
	 816	,1	,1	,&internal1_m441_Zv0},	//(internal1_m441_Zv0)  - Зад. выключатель механизма
	 817	,1	,1	,&internal1_m455_MyFirstEnterFlag},	//(internal1_m455_MyFirstEnterFlag) MyFirstEnterFlag
	 818	,1	,1	,&internal1_m455_Pav0},	//(internal1_m455_Pav0)  - Пер.аварийный выключатель механизма
	 819	,1	,1	,&internal1_m455_Pv0},	//(internal1_m455_Pv0)  - Пер. выключатель механизма
	 820	,1	,1	,&internal1_m455_RA00},	//(internal1_m455_RA00)  - последнее задание вперед
	 821	,1	,1	,&internal1_m455_RA10},	//(internal1_m455_RA10)  - последнее задание назад
	 822	,8	,1	,&internal1_m455_V00},	//(internal1_m455_V00)  V00 - текущая скорость механизма
	 823	,8	,1	,&internal1_m455_X00},	//(internal1_m455_X00)  X00 - текущая координата механизма
	 824	,1	,1	,&internal1_m455_Zav0},	//(internal1_m455_Zav0)  - Зад.аварийный выключатель механизма
	 825	,1	,1	,&internal1_m455_Zv0},	//(internal1_m455_Zv0)  - Зад. выключатель механизма
	 826	,1	,1	,&internal1_m465_q0},	//(internal1_m465_q0) q0 - внутренний параметр
	 827	,1	,1	,&internal1_m466_q0},	//(internal1_m466_q0) q0 - внутренний параметр
	 828	,1	,1	,&internal1_m46_Out10},	//(internal1_m46_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 829	,1	,1	,&internal1_m470_MyFirstEnterFlag},	//(internal1_m470_MyFirstEnterFlag) MyFirstEnterFlag
	 830	,1	,1	,&internal1_m470_Pav0},	//(internal1_m470_Pav0)  - Пер.аварийный выключатель механизма
	 831	,1	,1	,&internal1_m470_Pv0},	//(internal1_m470_Pv0)  - Пер. выключатель механизма
	 832	,1	,1	,&internal1_m470_RA00},	//(internal1_m470_RA00)  - последнее задание вперед
	 833	,1	,1	,&internal1_m470_RA10},	//(internal1_m470_RA10)  - последнее задание назад
	 834	,8	,1	,&internal1_m470_V00},	//(internal1_m470_V00)  V00 - текущая скорость механизма
	 835	,8	,1	,&internal1_m470_X00},	//(internal1_m470_X00)  X00 - текущая координата механизма
	 836	,1	,1	,&internal1_m470_Zav0},	//(internal1_m470_Zav0)  - Зад.аварийный выключатель механизма
	 837	,1	,1	,&internal1_m470_Zv0},	//(internal1_m470_Zv0)  - Зад. выключатель механизма
	 838	,1	,1	,&internal1_m471_MyFirstEnterFlag},	//(internal1_m471_MyFirstEnterFlag) MyFirstEnterFlag
	 839	,1	,1	,&internal1_m471_Pav0},	//(internal1_m471_Pav0)  - Пер.аварийный выключатель механизма
	 840	,1	,1	,&internal1_m471_Pv0},	//(internal1_m471_Pv0)  - Пер. выключатель механизма
	 841	,1	,1	,&internal1_m471_RA00},	//(internal1_m471_RA00)  - последнее задание вперед
	 842	,1	,1	,&internal1_m471_RA10},	//(internal1_m471_RA10)  - последнее задание назад
	 843	,8	,1	,&internal1_m471_V00},	//(internal1_m471_V00)  V00 - текущая скорость механизма
	 844	,8	,1	,&internal1_m471_X00},	//(internal1_m471_X00)  X00 - текущая координата механизма
	 845	,1	,1	,&internal1_m471_Zav0},	//(internal1_m471_Zav0)  - Зад.аварийный выключатель механизма
	 846	,1	,1	,&internal1_m471_Zv0},	//(internal1_m471_Zv0)  - Зад. выключатель механизма
	 847	,1	,1	,&internal1_m477_q0},	//(internal1_m477_q0) q0 - внутренний параметр
	 848	,1	,1	,&internal1_m478_q0},	//(internal1_m478_q0) q0 - внутренний параметр
	 849	,1	,1	,&internal1_m481_MyFirstEnterFlag},	//(internal1_m481_MyFirstEnterFlag) MyFirstEnterFlag
	 850	,1	,1	,&internal1_m481_Pav0},	//(internal1_m481_Pav0)  - Пер.аварийный выключатель механизма
	 851	,1	,1	,&internal1_m481_Pv0},	//(internal1_m481_Pv0)  - Пер. выключатель механизма
	 852	,1	,1	,&internal1_m481_RA00},	//(internal1_m481_RA00)  - последнее задание вперед
	 853	,1	,1	,&internal1_m481_RA10},	//(internal1_m481_RA10)  - последнее задание назад
	 854	,8	,1	,&internal1_m481_V00},	//(internal1_m481_V00)  V00 - текущая скорость механизма
	 855	,8	,1	,&internal1_m481_X00},	//(internal1_m481_X00)  X00 - текущая координата механизма
	 856	,1	,1	,&internal1_m481_Zav0},	//(internal1_m481_Zav0)  - Зад.аварийный выключатель механизма
	 857	,1	,1	,&internal1_m481_Zv0},	//(internal1_m481_Zv0)  - Зад. выключатель механизма
	 858	,1	,1	,&internal1_m492_MyFirstEnterFlag},	//(internal1_m492_MyFirstEnterFlag) MyFirstEnterFlag
	 859	,1	,1	,&internal1_m492_Pav0},	//(internal1_m492_Pav0)  - Пер.аварийный выключатель механизма
	 860	,1	,1	,&internal1_m492_Pv0},	//(internal1_m492_Pv0)  - Пер. выключатель механизма
	 861	,1	,1	,&internal1_m492_RA00},	//(internal1_m492_RA00)  - последнее задание вперед
	 862	,1	,1	,&internal1_m492_RA10},	//(internal1_m492_RA10)  - последнее задание назад
	 863	,8	,1	,&internal1_m492_V00},	//(internal1_m492_V00)  V00 - текущая скорость механизма
	 864	,8	,1	,&internal1_m492_X00},	//(internal1_m492_X00)  X00 - текущая координата механизма
	 865	,1	,1	,&internal1_m492_Zav0},	//(internal1_m492_Zav0)  - Зад.аварийный выключатель механизма
	 866	,1	,1	,&internal1_m492_Zv0},	//(internal1_m492_Zv0)  - Зад. выключатель механизма
	 867	,1	,1	,&internal1_m516_Out10},	//(internal1_m516_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 868	,1	,1	,&internal1_m532_Out10},	//(internal1_m532_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 869	,1	,1	,&internal1_m533_Out10},	//(internal1_m533_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 870	,1	,1	,&internal1_m548_Out10},	//(internal1_m548_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 871	,1	,1	,&internal1_m549_Out10},	//(internal1_m549_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 872	,1	,1	,&internal1_m550_Out10},	//(internal1_m550_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 873	,1	,1	,&internal1_m564_MyFirstEnterFlag},	//(internal1_m564_MyFirstEnterFlag) MyFirstEnterFlag
	 874	,1	,1	,&internal1_m564_Pav0},	//(internal1_m564_Pav0)  - Пер.аварийный выключатель механизма
	 875	,1	,1	,&internal1_m564_Pv0},	//(internal1_m564_Pv0)  - Пер. выключатель механизма
	 876	,1	,1	,&internal1_m564_RA00},	//(internal1_m564_RA00)  - последнее задание вперед
	 877	,1	,1	,&internal1_m564_RA10},	//(internal1_m564_RA10)  - последнее задание назад
	 878	,8	,1	,&internal1_m564_V00},	//(internal1_m564_V00)  V00 - текущая скорость механизма
	 879	,8	,1	,&internal1_m564_X00},	//(internal1_m564_X00)  X00 - текущая координата механизма
	 880	,1	,1	,&internal1_m564_Zav0},	//(internal1_m564_Zav0)  - Зад.аварийный выключатель механизма
	 881	,1	,1	,&internal1_m564_Zv0},	//(internal1_m564_Zv0)  - Зад. выключатель механизма
	 882	,1	,1	,&internal1_m578_MyFirstEnterFlag},	//(internal1_m578_MyFirstEnterFlag) MyFirstEnterFlag
	 883	,1	,1	,&internal1_m578_Pav0},	//(internal1_m578_Pav0)  - Пер.аварийный выключатель механизма
	 884	,1	,1	,&internal1_m578_Pv0},	//(internal1_m578_Pv0)  - Пер. выключатель механизма
	 885	,1	,1	,&internal1_m578_RA00},	//(internal1_m578_RA00)  - последнее задание вперед
	 886	,1	,1	,&internal1_m578_RA10},	//(internal1_m578_RA10)  - последнее задание назад
	 887	,8	,1	,&internal1_m578_V00},	//(internal1_m578_V00)  V00 - текущая скорость механизма
	 888	,8	,1	,&internal1_m578_X00},	//(internal1_m578_X00)  X00 - текущая координата механизма
	 889	,1	,1	,&internal1_m578_Zav0},	//(internal1_m578_Zav0)  - Зад.аварийный выключатель механизма
	 890	,1	,1	,&internal1_m578_Zv0},	//(internal1_m578_Zv0)  - Зад. выключатель механизма
	 891	,1	,1	,&internal1_m590_MyFirstEnterFlag},	//(internal1_m590_MyFirstEnterFlag) MyFirstEnterFlag
	 892	,1	,1	,&internal1_m590_Pav0},	//(internal1_m590_Pav0)  - Пер.аварийный выключатель механизма
	 893	,1	,1	,&internal1_m590_Pv0},	//(internal1_m590_Pv0)  - Пер. выключатель механизма
	 894	,1	,1	,&internal1_m590_RA00},	//(internal1_m590_RA00)  - последнее задание вперед
	 895	,1	,1	,&internal1_m590_RA10},	//(internal1_m590_RA10)  - последнее задание назад
	 896	,8	,1	,&internal1_m590_V00},	//(internal1_m590_V00)  V00 - текущая скорость механизма
	 897	,8	,1	,&internal1_m590_X00},	//(internal1_m590_X00)  X00 - текущая координата механизма
	 898	,1	,1	,&internal1_m590_Zav0},	//(internal1_m590_Zav0)  - Зад.аварийный выключатель механизма
	 899	,1	,1	,&internal1_m590_Zv0},	//(internal1_m590_Zv0)  - Зад. выключатель механизма
	 900	,1	,1	,&internal1_m591_MyFirstEnterFlag},	//(internal1_m591_MyFirstEnterFlag) MyFirstEnterFlag
	 901	,1	,1	,&internal1_m591_Pav0},	//(internal1_m591_Pav0)  - Пер.аварийный выключатель механизма
	 902	,1	,1	,&internal1_m591_Pv0},	//(internal1_m591_Pv0)  - Пер. выключатель механизма
	 903	,1	,1	,&internal1_m591_RA00},	//(internal1_m591_RA00)  - последнее задание вперед
	 904	,1	,1	,&internal1_m591_RA10},	//(internal1_m591_RA10)  - последнее задание назад
	 905	,8	,1	,&internal1_m591_V00},	//(internal1_m591_V00)  V00 - текущая скорость механизма
	 906	,8	,1	,&internal1_m591_X00},	//(internal1_m591_X00)  X00 - текущая координата механизма
	 907	,1	,1	,&internal1_m591_Zav0},	//(internal1_m591_Zav0)  - Зад.аварийный выключатель механизма
	 908	,1	,1	,&internal1_m591_Zv0},	//(internal1_m591_Zv0)  - Зад. выключатель механизма
	 909	,8	,1	,&internal1_m599_tx},	//(internal1_m599_tx) tx - время накопленное сек
	 910	,18	,1	,&internal1_m599_y0},	//(internal1_m599_y0) y0
	 911	,8	,1	,&internal1_m601_tx},	//(internal1_m601_tx) tx - время накопленное сек
	 912	,18	,1	,&internal1_m601_y0},	//(internal1_m601_y0) y0
	 913	,1	,1	,&internal1_m603_MyFirstEnterFlag},	//(internal1_m603_MyFirstEnterFlag) MyFirstEnterFlag
	 914	,1	,1	,&internal1_m603_Pav0},	//(internal1_m603_Pav0)  - Пер.аварийный выключатель механизма
	 915	,1	,1	,&internal1_m603_Pv0},	//(internal1_m603_Pv0)  - Пер. выключатель механизма
	 916	,1	,1	,&internal1_m603_RA00},	//(internal1_m603_RA00)  - последнее задание вперед
	 917	,1	,1	,&internal1_m603_RA10},	//(internal1_m603_RA10)  - последнее задание назад
	 918	,8	,1	,&internal1_m603_V00},	//(internal1_m603_V00)  V00 - текущая скорость механизма
	 919	,8	,1	,&internal1_m603_X00},	//(internal1_m603_X00)  X00 - текущая координата механизма
	 920	,1	,1	,&internal1_m603_Zav0},	//(internal1_m603_Zav0)  - Зад.аварийный выключатель механизма
	 921	,1	,1	,&internal1_m603_Zv0},	//(internal1_m603_Zv0)  - Зад. выключатель механизма
	 922	,1	,1	,&internal1_m604_MyFirstEnterFlag},	//(internal1_m604_MyFirstEnterFlag) MyFirstEnterFlag
	 923	,1	,1	,&internal1_m604_Pav0},	//(internal1_m604_Pav0)  - Пер.аварийный выключатель механизма
	 924	,1	,1	,&internal1_m604_Pv0},	//(internal1_m604_Pv0)  - Пер. выключатель механизма
	 925	,1	,1	,&internal1_m604_RA00},	//(internal1_m604_RA00)  - последнее задание вперед
	 926	,1	,1	,&internal1_m604_RA10},	//(internal1_m604_RA10)  - последнее задание назад
	 927	,8	,1	,&internal1_m604_V00},	//(internal1_m604_V00)  V00 - текущая скорость механизма
	 928	,8	,1	,&internal1_m604_X00},	//(internal1_m604_X00)  X00 - текущая координата механизма
	 929	,1	,1	,&internal1_m604_Zav0},	//(internal1_m604_Zav0)  - Зад.аварийный выключатель механизма
	 930	,1	,1	,&internal1_m604_Zv0},	//(internal1_m604_Zv0)  - Зад. выключатель механизма
	 931	,8	,1	,&internal1_m613_tx},	//(internal1_m613_tx) tx - время накопленное сек
	 932	,18	,1	,&internal1_m613_y0},	//(internal1_m613_y0) y0
	 933	,1	,1	,&internal1_m61_Out10},	//(internal1_m61_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 934	,8	,1	,&internal1_m625_tx},	//(internal1_m625_tx) tx - время накопленное сек
	 935	,18	,1	,&internal1_m625_y0},	//(internal1_m625_y0) y0
	 936	,8	,1	,&internal1_m632_y0},	//(internal1_m632_y0) y0 - внутренний параметр
	 937	,1	,1	,&internal1_m646_Out10},	//(internal1_m646_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 938	,1	,1	,&internal1_m647_Out10},	//(internal1_m647_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 939	,1	,1	,&internal1_m648_Out10},	//(internal1_m648_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 940	,1	,1	,&internal1_m649_Out10},	//(internal1_m649_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 941	,1	,1	,&internal1_m64_MyFirstEnterFlag},	//(internal1_m64_MyFirstEnterFlag) MyFirstEnterFlag
	 942	,1	,1	,&internal1_m64_Pav0},	//(internal1_m64_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	 943	,1	,1	,&internal1_m64_Ppv0},	//(internal1_m64_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	 944	,1	,1	,&internal1_m64_RA00},	//(internal1_m64_RA00) RA00 - последнее задание вперед
	 945	,1	,1	,&internal1_m64_RA10},	//(internal1_m64_RA10) RA10 - последнее задание назад
	 946	,1	,1	,&internal1_m64_RA30},	//(internal1_m64_RA30)  RA30 - разрешение движения
	 947	,1	,1	,&internal1_m64_RA50},	//(internal1_m64_RA50) Ra50 - последнее задание скорости
	 948	,8	,1	,&internal1_m64_RV00},	//(internal1_m64_RV00) V0 - текущая скорость ОРР
	 949	,8	,1	,&internal1_m64_Sh00},	//(internal1_m64_Sh00) Sh0 - текущая координата штока ОРР
	 950	,8	,1	,&internal1_m64_ShV00},	//(internal1_m64_ShV00) V0 - текущая скорость штока ОРР
	 951	,8	,1	,&internal1_m64_X00},	//(internal1_m64_X00) X0 - текущая координата ОРР
	 952	,1	,1	,&internal1_m64_Zav0},	//(internal1_m64_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	 953	,1	,1	,&internal1_m64_flp},	//(internal1_m64_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	 954	,1	,1	,&internal1_m64_fls},	//(internal1_m64_fls)  fls - флаг одношагового режима
	 955	,1	,1	,&internal1_m650_Out10},	//(internal1_m650_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 956	,1	,1	,&internal1_m651_Out10},	//(internal1_m651_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 957	,1	,1	,&internal1_m666_Out10},	//(internal1_m666_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 958	,1	,1	,&internal1_m667_Out10},	//(internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 959	,1	,1	,&internal1_m670_Out10},	//(internal1_m670_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 960	,1	,1	,&internal1_m671_Out10},	//(internal1_m671_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 961	,1	,1	,&internal1_m672_Out10},	//(internal1_m672_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 962	,1	,1	,&internal1_m673_Out10},	//(internal1_m673_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 963	,1	,1	,&internal1_m683_Out10},	//(internal1_m683_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 964	,1	,1	,&internal1_m684_Out10},	//(internal1_m684_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 965	,1	,1	,&internal1_m685_Out10},	//(internal1_m685_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 966	,1	,1	,&internal1_m686_Out10},	//(internal1_m686_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 967	,1	,1	,&internal1_m687_Out10},	//(internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 968	,8	,1	,&internal1_m700_Chim0},	//(internal1_m700_Chim0) измеренная частота импульсов камеры Гц
	 969	,8	,1	,&internal1_m710_Chim0},	//(internal1_m710_Chim0) измеренная частота импульсов камеры Гц
	 970	,8	,1	,&internal1_m719_Chim0},	//(internal1_m719_Chim0) измеренная частота импульсов камеры Гц
	 971	,8	,1	,&internal1_m728_Chim0},	//(internal1_m728_Chim0) измеренная частота импульсов камеры Гц
	 972	,8	,1	,&internal1_m736_Chim0},	//(internal1_m736_Chim0) измеренная частота импульсов камеры Гц
	 973	,8	,1	,&internal1_m745_Chim0},	//(internal1_m745_Chim0) измеренная частота импульсов камеры Гц
	 974	,8	,1	,&internal1_m754_Chim0},	//(internal1_m754_Chim0) измеренная частота импульсов камеры Гц
	 975	,8	,1	,&internal1_m762_Chim0},	//(internal1_m762_Chim0) измеренная частота импульсов камеры Гц
	 976	,8	,1	,&internal1_m771_Chim0},	//(internal1_m771_Chim0) измеренная частота импульсов камеры Гц
	 977	,8	,1	,&internal1_m780_Chim0},	//(internal1_m780_Chim0) измеренная частота импульсов камеры Гц
	 978	,8	,1	,&internal1_m788_Chim0},	//(internal1_m788_Chim0) измеренная частота импульсов камеры Гц
	 979	,8	,1	,&internal1_m797_Chim0},	//(internal1_m797_Chim0) измеренная частота импульсов камеры Гц
	 980	,1	,1	,&internal1_m809_Out10},	//(internal1_m809_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 981	,1	,1	,&internal1_m810_Out10},	//(internal1_m810_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 982	,1	,1	,&internal1_m811_Out10},	//(internal1_m811_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 983	,1	,1	,&internal1_m812_Out10},	//(internal1_m812_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 984	,1	,1	,&internal1_m813_Out10},	//(internal1_m813_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 985	,1	,1	,&internal1_m814_Out10},	//(internal1_m814_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 986	,1	,1	,&internal1_m815_Out10},	//(internal1_m815_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 987	,8	,1	,&internal1_m832_Xtek0},	//(internal1_m832_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	 988	,8	,1	,&internal1_m834_Xtek0},	//(internal1_m834_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	 989	,1	,1	,&internal1_m835_Out10},	//(internal1_m835_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 990	,1	,1	,&internal1_m836_Out10},	//(internal1_m836_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 991	,1	,1	,&internal1_m837_Out10},	//(internal1_m837_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 992	,1	,1	,&internal1_m838_Out10},	//(internal1_m838_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 993	,1	,1	,&internal1_m850_Out10},	//(internal1_m850_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 994	,1	,1	,&internal1_m851_Out10},	//(internal1_m851_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 995	,1	,1	,&internal1_m852_Out10},	//(internal1_m852_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 996	,8	,1	,&internal1_m860_Chim0},	//(internal1_m860_Chim0) измеренная частота импульсов камеры Гц
	 997	,8	,1	,&internal1_m868_Chim0},	//(internal1_m868_Chim0) измеренная частота импульсов камеры Гц
	 998	,8	,1	,&internal1_m878_Chim0},	//(internal1_m878_Chim0) измеренная частота импульсов камеры Гц
	 999	,1	,1	,&internal1_m890_MyFirstEnterFlag},	//(internal1_m890_MyFirstEnterFlag) MyFirstEnterFlag
	 1000	,1	,1	,&internal1_m890_Pav0},	//(internal1_m890_Pav0)  - Пер.аварийный выключатель механизма
	 1001	,1	,1	,&internal1_m890_Pv0},	//(internal1_m890_Pv0)  - Пер. выключатель механизма
	 1002	,1	,1	,&internal1_m890_RA00},	//(internal1_m890_RA00)  - последнее задание вперед
	 1003	,1	,1	,&internal1_m890_RA10},	//(internal1_m890_RA10)  - последнее задание назад
	 1004	,8	,1	,&internal1_m890_V00},	//(internal1_m890_V00)  V00 - текущая скорость механизма
	 1005	,8	,1	,&internal1_m890_X00},	//(internal1_m890_X00)  X00 - текущая координата механизма
	 1006	,1	,1	,&internal1_m890_Zav0},	//(internal1_m890_Zav0)  - Зад.аварийный выключатель механизма
	 1007	,1	,1	,&internal1_m890_Zv0},	//(internal1_m890_Zv0)  - Зад. выключатель механизма
	 1008	,1	,1	,&internal1_m947_Out10},	//(internal1_m947_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 1009	,1	,1	,&internal1_m948_Out10},	//(internal1_m948_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 1010	,8	,1	,&internal1_m950_Xtek0},	//(internal1_m950_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	 1011	,1	,1	,&internal1_m951_Out10},	//(internal1_m951_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 1012	,1	,1	,&internal1_m964_Out10},	//(internal1_m964_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 1013	,1	,1	,&internal1_m965_Out10},	//(internal1_m965_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 1014	,8	,1	,&internal1_m967_Xtek0},	//(internal1_m967_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	 1015	,1	,1	,&internal1_m968_Out10},	//(internal1_m968_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 1016	,1	,1	,&internal1_m978_Out10},	//(internal1_m978_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 1017	,1	,1	,&internal1_m979_Out10},	//(internal1_m979_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 1018	,1	,1	,&internal1_m980_Out10},	//(internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 1019	,1	,1	,&internal1_m981_Out10},	//(internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 1020	,1	,1	,&internal1_m982_Out10},	//(internal1_m982_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 1021	,1	,1	,&internal1_m993_Out10},	//(internal1_m993_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 1022	,1	,1	,&internal1_m994_Out10},	//(internal1_m994_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 1023	,1	,1	,&internal1_m995_Out10},	//(internal1_m995_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 1024	,1	,1	,&internal1_m996_Out10},	//(internal1_m996_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 1025	,1	,1	,&internal1_m997_Out10},	//(internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	 1026	,1	,1	,&internal1_m99_MyFirstEnterFlag},	//(internal1_m99_MyFirstEnterFlag) MyFirstEnterFlag
	 1027	,1	,1	,&internal1_m99_Pav0},	//(internal1_m99_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	 1028	,1	,1	,&internal1_m99_Ppv0},	//(internal1_m99_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	 1029	,1	,1	,&internal1_m99_RA00},	//(internal1_m99_RA00) RA00 - последнее задание вперед
	 1030	,1	,1	,&internal1_m99_RA10},	//(internal1_m99_RA10) RA10 - последнее задание назад
	 1031	,1	,1	,&internal1_m99_RA30},	//(internal1_m99_RA30)  RA30 - разрешение движения
	 1032	,1	,1	,&internal1_m99_RA50},	//(internal1_m99_RA50) Ra50 - последнее задание скорости
	 1033	,8	,1	,&internal1_m99_RV00},	//(internal1_m99_RV00) V0 - текущая скорость ОРР
	 1034	,8	,1	,&internal1_m99_Sh00},	//(internal1_m99_Sh00) Sh0 - текущая координата штока ОРР
	 1035	,8	,1	,&internal1_m99_ShV00},	//(internal1_m99_ShV00) V0 - текущая скорость штока ОРР
	 1036	,8	,1	,&internal1_m99_X00},	//(internal1_m99_X00) X0 - текущая координата ОРР
	 1037	,1	,1	,&internal1_m99_Zav0},	//(internal1_m99_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	 1038	,1	,1	,&internal1_m99_flp},	//(internal1_m99_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	 1039	,1	,1	,&internal1_m99_fls},	//(internal1_m99_fls)  fls - флаг одношагового режима
	 1040	,8	,1	,&krb1},	//( - , - ) 
	 1041	,8	,1	,&krb2},	//( - , - ) 
	 1042	,1	,1	,&lEM_C1AD31LRP},	//(C1AD31LRP) Общий сброс от РПУ
	 1043	,1	,1	,&lEM_R0IE01LRP},	//(R0IE01LRP) Отключение питание детекторов
	 1044	,1	,1	,&lEM_R0IE02LRP},	//(R0IE02LRP) Отключить питание ПР, ПУ
	 1045	,1	,1	,&lEM_R3AD10LC1},	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
	 1046	,1	,1	,&lEM_R3AD20LC1},	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
	 1047	,1	,1	,&lEM_R5AD10LC1},	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
	 1048	,1	,1	,&lEM_R5AD20LC1},	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
	 1049	,1	,1	,&lEM_R6AD10LC1},	//(R6AD10LC1) Выкатить кран-балку от ИС
	 1050	,1	,1	,&lEM_R8AD10LC1},	//(R8AD10LC1) Установить аварийный НИ от ИС
	 30000	,1	,1	,&var267},	//Внутренняя переменная var267
	 30001	,1	,1	,&var215},	//Внутренняя переменная var215
	 30002	,8	,1	,&var243},	//Внутренняя переменная var243
	 30003	,1	,1	,&var170},	//Внутренняя переменная var170
	 30004	,8	,1	,&var269},	//Внутренняя переменная var269
	 30005	,1	,1	,&var322},	//Внутренняя переменная var322
	 30006	,8	,1	,&var332},	//Внутренняя переменная var332
	 30007	,1	,1	,&var150},	//Внутренняя переменная var150
	 30008	,8	,1	,&var167},	//Внутренняя переменная var167
	 30009	,8	,1	,&var136},	//Внутренняя переменная var136
	 30010	,1	,1	,&var137},	//Внутренняя переменная var137
	 30011	,1	,1	,&var187},	//Внутренняя переменная var187
	 30012	,1	,1	,&var198},	//Внутренняя переменная var198
	 30013	,8	,1	,&var288},	//Внутренняя переменная var288
	 30014	,8	,1	,&var7},	//Внутренняя переменная var7
	 30015	,1	,1	,&var61},	//Внутренняя переменная var61
	 30016	,1	,1	,&var119},	//Внутренняя переменная var119
	 30017	,1	,1	,&var184},	//Внутренняя переменная var184
	 30018	,1	,1	,&var264},	//Внутренняя переменная var264
	 30019	,1	,1	,&var35},	//Внутренняя переменная var35
	 30020	,1	,1	,&var47},	//Внутренняя переменная var47
	 30021	,1	,1	,&var214},	//Внутренняя переменная var214
	 30022	,1	,1	,&var12},	//Внутренняя переменная var12
	 30023	,1	,1	,&var38},	//Внутренняя переменная var38
	 30024	,8	,1	,&var222},	//Внутренняя переменная var222
	 30025	,1	,1	,&var246},	//Внутренняя переменная var246
	 30026	,8	,1	,&var158},	//Внутренняя переменная var158
	 30027	,1	,1	,&var179},	//Внутренняя переменная var179
	 30028	,1	,1	,&var80},	//Внутренняя переменная var80
	 30029	,1	,1	,&var144},	//Внутренняя переменная var144
	 30030	,1	,1	,&var276},	//Внутренняя переменная var276
	 30031	,1	,1	,&var25},	//Внутренняя переменная var25
	 30032	,11	,1	,&var55},	//Внутренняя переменная var55
	 30033	,1	,1	,&var134},	//Внутренняя переменная var134
	 30034	,1	,1	,&var320},	//Внутренняя переменная var320
	 30035	,1	,1	,&var36},	//Внутренняя переменная var36
	 30036	,1	,1	,&var85},	//Внутренняя переменная var85
	 30037	,3	,1	,&var142},	//Внутренняя переменная var142
	 30038	,1	,1	,&var183},	//Внутренняя переменная var183
	 30039	,1	,1	,&var219},	//Внутренняя переменная var219
	 30040	,8	,1	,&var226},	//Внутренняя переменная var226
	 30041	,1	,1	,&var259},	//Внутренняя переменная var259
	 30042	,8	,1	,&var311},	//Внутренняя переменная var311
	 30043	,1	,1	,&var46},	//Внутренняя переменная var46
	 30044	,1	,1	,&var67},	//Внутренняя переменная var67
	 30045	,1	,1	,&var108},	//Внутренняя переменная var108
	 30046	,1	,1	,&var313},	//Внутренняя переменная var313
	 30047	,1	,1	,&var146},	//Внутренняя переменная var146
	 30048	,1	,1	,&var171},	//Внутренняя переменная var171
	 30049	,1	,1	,&var275},	//Внутренняя переменная var275
	 30050	,1	,1	,&var307},	//Внутренняя переменная var307
	 30051	,1	,1	,&var199},	//Внутренняя переменная var199
	 30052	,1	,1	,&var231},	//Внутренняя переменная var231
	 30053	,1	,1	,&var15},	//Внутренняя переменная var15
	 30054	,1	,1	,&var103},	//Внутренняя переменная var103
	 30055	,1	,1	,&var197},	//Внутренняя переменная var197
	 30056	,8	,1	,&var225},	//Внутренняя переменная var225
	 30057	,8	,1	,&var228},	//Внутренняя переменная var228
	 30058	,8	,1	,&var237},	//Внутренняя переменная var237
	 30059	,1	,1	,&var44},	//Внутренняя переменная var44
	 30060	,1	,1	,&var49},	//Внутренняя переменная var49
	 30061	,1	,1	,&var141},	//Внутренняя переменная var141
	 30062	,8	,1	,&var282},	//Внутренняя переменная var282
	 30063	,1	,1	,&var45},	//Внутренняя переменная var45
	 30064	,1	,1	,&var102},	//Внутренняя переменная var102
	 30065	,8	,1	,&var303},	//Внутренняя переменная var303
	 30066	,8	,1	,&var326},	//Внутренняя переменная var326
	 30067	,1	,1	,&var62},	//Внутренняя переменная var62
	 30068	,1	,1	,&var185},	//Внутренняя переменная var185
	 30069	,1	,1	,&var194},	//Внутренняя переменная var194
	 30070	,1	,1	,&var210},	//Внутренняя переменная var210
	 30071	,1	,1	,&var298},	//Внутренняя переменная var298
	 30072	,3	,1	,&vainSInt},	//Внутренняя переменная vainSInt
	 30073	,1	,1	,&var14},	//Внутренняя переменная var14
	 30074	,8	,1	,&var159},	//Внутренняя переменная var159
	 30075	,1	,1	,&var190},	//Внутренняя переменная var190
	 30076	,8	,1	,&var233},	//Внутренняя переменная var233
	 30077	,1	,1	,&var262},	//Внутренняя переменная var262
	 30078	,1	,1	,&var60},	//Внутренняя переменная var60
	 30079	,1	,1	,&var77},	//Внутренняя переменная var77
	 30080	,1	,1	,&var125},	//Внутренняя переменная var125
	 30081	,1	,1	,&var200},	//Внутренняя переменная var200
	 30082	,8	,1	,&var240},	//Внутренняя переменная var240
	 30083	,8	,1	,&var272},	//Внутренняя переменная var272
	 30084	,1	,1	,&var309},	//Внутренняя переменная var309
	 30085	,1	,1	,&var328},	//Внутренняя переменная var328
	 30086	,8	,1	,&var3},	//Внутренняя переменная var3
	 30087	,1	,1	,&var34},	//Внутренняя переменная var34
	 30088	,1	,1	,&var75},	//Внутренняя переменная var75
	 30089	,8	,1	,&vainSFloat},	//Внутренняя переменная vainSFloat
	 30090	,1	,1	,&var92},	//Внутренняя переменная var92
	 30091	,1	,1	,&var111},	//Внутренняя переменная var111
	 30092	,1	,1	,&var117},	//Внутренняя переменная var117
	 30093	,8	,1	,&var160},	//Внутренняя переменная var160
	 30094	,1	,1	,&var182},	//Внутренняя переменная var182
	 30095	,1	,1	,&var292},	//Внутренняя переменная var292
	 30096	,1	,1	,&var50},	//Внутренняя переменная var50
	 30097	,1	,1	,&var74},	//Внутренняя переменная var74
	 30098	,1	,1	,&var178},	//Внутренняя переменная var178
	 30099	,8	,1	,&var236},	//Внутренняя переменная var236
	 30100	,1	,1	,&var89},	//Внутренняя переменная var89
	 30101	,3	,1	,&var128},	//Внутренняя переменная var128
	 30102	,1	,1	,&var188},	//Внутренняя переменная var188
	 30103	,1	,1	,&var27},	//Внутренняя переменная var27
	 30104	,1	,1	,&var43},	//Внутренняя переменная var43
	 30105	,1	,1	,&var297},	//Внутренняя переменная var297
	 30106	,8	,1	,&var5},	//Внутренняя переменная var5
	 30107	,8	,1	,&var242},	//Внутренняя переменная var242
	 30108	,3	,1	,&var132},	//Внутренняя переменная var132
	 30109	,1	,1	,&var280},	//Внутренняя переменная var280
	 30110	,8	,1	,&var302},	//Внутренняя переменная var302
	 30111	,1	,1	,&var91},	//Внутренняя переменная var91
	 30112	,11	,1	,&var115},	//Внутренняя переменная var115
	 30113	,8	,1	,&var241},	//Внутренняя переменная var241
	 30114	,1	,1	,&var245},	//Внутренняя переменная var245
	 30115	,1	,1	,&var256},	//Внутренняя переменная var256
	 30116	,1	,1	,&var42},	//Внутренняя переменная var42
	 30117	,1	,1	,&var189},	//Внутренняя переменная var189
	 30118	,1	,1	,&var229},	//Внутренняя переменная var229
	 30119	,8	,1	,&var318},	//Внутренняя переменная var318
	 30120	,11	,1	,&var113},	//Внутренняя переменная var113
	 30121	,1	,1	,&var172},	//Внутренняя переменная var172
	 30122	,8	,1	,&var295},	//Внутренняя переменная var295
	 30123	,1	,1	,&var63},	//Внутренняя переменная var63
	 30124	,1	,1	,&var105},	//Внутренняя переменная var105
	 30125	,8	,1	,&var154},	//Внутренняя переменная var154
	 30126	,3	,1	,&var157},	//Внутренняя переменная var157
	 30127	,1	,1	,&var211},	//Внутренняя переменная var211
	 30128	,1	,1	,&var212},	//Внутренняя переменная var212
	 30129	,11	,1	,&var57},	//Внутренняя переменная var57
	 30130	,1	,1	,&var127},	//Внутренняя переменная var127
	 30131	,1	,1	,&var65},	//Внутренняя переменная var65
	 30132	,1	,1	,&var104},	//Внутренняя переменная var104
	 30133	,1	,1	,&var265},	//Внутренняя переменная var265
	 30134	,1	,1	,&var273},	//Внутренняя переменная var273
	 30135	,1	,1	,&var23},	//Внутренняя переменная var23
	 30136	,1	,1	,&var54},	//Внутренняя переменная var54
	 30137	,1	,1	,&var213},	//Внутренняя переменная var213
	 30138	,1	,1	,&var216},	//Внутренняя переменная var216
	 30139	,1	,1	,&var253},	//Внутренняя переменная var253
	 30140	,1	,1	,&var274},	//Внутренняя переменная var274
	 30141	,1	,1	,&var278},	//Внутренняя переменная var278
	 30142	,8	,1	,&var286},	//Внутренняя переменная var286
	 30143	,1	,1	,&var124},	//Внутренняя переменная var124
	 30144	,8	,1	,&var133},	//Внутренняя переменная var133
	 30145	,1	,1	,&var324},	//Внутренняя переменная var324
	 30146	,1	,1	,&var191},	//Внутренняя переменная var191
	 30147	,1	,1	,&var314},	//Внутренняя переменная var314
	 30148	,8	,1	,&var337},	//Внутренняя переменная var337
	 30149	,8	,1	,&var116},	//Внутренняя переменная var116
	 30150	,1	,1	,&var145},	//Внутренняя переменная var145
	 30151	,1	,1	,&var300},	//Внутренняя переменная var300
	 30152	,1	,1	,&var315},	//Внутренняя переменная var315
	 30153	,1	,1	,&var21},	//Внутренняя переменная var21
	 30154	,1	,1	,&var151},	//Внутренняя переменная var151
	 30155	,1	,1	,&var290},	//Внутренняя переменная var290
	 30156	,1	,1	,&var293},	//Внутренняя переменная var293
	 30157	,1	,1	,&var329},	//Внутренняя переменная var329
	 30158	,1	,1	,&var30},	//Внутренняя переменная var30
	 30159	,1	,1	,&var59},	//Внутренняя переменная var59
	 30160	,1	,1	,&var130},	//Внутренняя переменная var130
	 30161	,1	,1	,&var208},	//Внутренняя переменная var208
	 30162	,1	,1	,&var255},	//Внутренняя переменная var255
	 30163	,1	,1	,&var258},	//Внутренняя переменная var258
	 30164	,1	,1	,&var53},	//Внутренняя переменная var53
	 30165	,1	,1	,&var66},	//Внутренняя переменная var66
	 30166	,1	,1	,&var26},	//Внутренняя переменная var26
	 30167	,3	,1	,&var93},	//Внутренняя переменная var93
	 30168	,8	,1	,&var114},	//Внутренняя переменная var114
	 30169	,8	,1	,&var166},	//Внутренняя переменная var166
	 30170	,1	,1	,&var204},	//Внутренняя переменная var204
	 30171	,8	,1	,&var238},	//Внутренняя переменная var238
	 30172	,1	,1	,&var17},	//Внутренняя переменная var17
	 30173	,1	,1	,&var18},	//Внутренняя переменная var18
	 30174	,8	,1	,&var289},	//Внутренняя переменная var289
	 30175	,1	,1	,&var149},	//Внутренняя переменная var149
	 30176	,3	,1	,&var161},	//Внутренняя переменная var161
	 30177	,8	,1	,&var168},	//Внутренняя переменная var168
	 30178	,1	,1	,&var195},	//Внутренняя переменная var195
	 30179	,8	,1	,&var223},	//Внутренняя переменная var223
	 30180	,8	,1	,&var232},	//Внутренняя переменная var232
	 30181	,1	,1	,&var1},	//Внутренняя переменная var1
	 30182	,11	,1	,&var139},	//Внутренняя переменная var139
	 30183	,1	,1	,&var249},	//Внутренняя переменная var249
	 30184	,8	,1	,&var281},	//Внутренняя переменная var281
	 30185	,1	,1	,&var101},	//Внутренняя переменная var101
	 30186	,1	,1	,&var270},	//Внутренняя переменная var270
	 30187	,1	,1	,&var32},	//Внутренняя переменная var32
	 30188	,8	,1	,&var41},	//Внутренняя переменная var41
	 30189	,11	,1	,&var97},	//Внутренняя переменная var97
	 30190	,1	,1	,&var177},	//Внутренняя переменная var177
	 30191	,8	,1	,&var227},	//Внутренняя переменная var227
	 30192	,8	,1	,&var244},	//Внутренняя переменная var244
	 30193	,1	,1	,&var9},	//Внутренняя переменная var9
	 30194	,1	,1	,&var16},	//Внутренняя переменная var16
	 30195	,1	,1	,&var79},	//Внутренняя переменная var79
	 30196	,1	,1	,&var106},	//Внутренняя переменная var106
	 30197	,1	,1	,&var122},	//Внутренняя переменная var122
	 30198	,8	,1	,&var287},	//Внутренняя переменная var287
	 30199	,8	,1	,&var319},	//Внутренняя переменная var319
	 30200	,1	,1	,&var40},	//Внутренняя переменная var40
	 30201	,8	,1	,&var58},	//Внутренняя переменная var58
	 30202	,1	,1	,&var252},	//Внутренняя переменная var252
	 30203	,1	,1	,&var304},	//Внутренняя переменная var304
	 30204	,1	,1	,&var323},	//Внутренняя переменная var323
	 30205	,1	,1	,&var336},	//Внутренняя переменная var336
	 30206	,1	,1	,&var123},	//Внутренняя переменная var123
	 30207	,8	,1	,&var152},	//Внутренняя переменная var152
	 30208	,8	,1	,&var95},	//Внутренняя переменная var95
	 30209	,1	,1	,&var131},	//Внутренняя переменная var131
	 30210	,1	,1	,&var112},	//Внутренняя переменная var112
	 30211	,1	,1	,&var121},	//Внутренняя переменная var121
	 30212	,3	,1	,&var155},	//Внутренняя переменная var155
	 30213	,8	,1	,&var234},	//Внутренняя переменная var234
	 30214	,8	,1	,&var239},	//Внутренняя переменная var239
	 30215	,1	,1	,&var250},	//Внутренняя переменная var250
	 30216	,1	,1	,&var29},	//Внутренняя переменная var29
	 30217	,3	,1	,&var94},	//Внутренняя переменная var94
	 30218	,1	,1	,&vainSBool},	//Внутренняя переменная vainSBool
	 30219	,1	,1	,&var260},	//Внутренняя переменная var260
	 30220	,1	,1	,&var266},	//Внутренняя переменная var266
	 30221	,1	,1	,&var87},	//Внутренняя переменная var87
	 30222	,1	,1	,&var109},	//Внутренняя переменная var109
	 30223	,8	,1	,&var175},	//Внутренняя переменная var175
	 30224	,1	,1	,&var202},	//Внутренняя переменная var202
	 30225	,1	,1	,&var261},	//Внутренняя переменная var261
	 30226	,1	,1	,&var308},	//Внутренняя переменная var308
	 30227	,8	,1	,&var6},	//Внутренняя переменная var6
	 30228	,1	,1	,&var78},	//Внутренняя переменная var78
	 30229	,1	,1	,&var247},	//Внутренняя переменная var247
	 30230	,8	,1	,&var284},	//Внутренняя переменная var284
	 30231	,1	,1	,&var301},	//Внутренняя переменная var301
	 30232	,8	,1	,&var335},	//Внутренняя переменная var335
	 30233	,1	,1	,&var138},	//Внутренняя переменная var138
	 30234	,8	,1	,&var224},	//Внутренняя переменная var224
	 30235	,1	,1	,&var118},	//Внутренняя переменная var118
	 30236	,11	,1	,&var135},	//Внутренняя переменная var135
	 30237	,8	,1	,&var173},	//Внутренняя переменная var173
	 30238	,1	,1	,&var176},	//Внутренняя переменная var176
	 30239	,8	,1	,&var310},	//Внутренняя переменная var310
	 30240	,8	,1	,&var333},	//Внутренняя переменная var333
	 30241	,1	,1	,&var71},	//Внутренняя переменная var71
	 30242	,1	,1	,&var72},	//Внутренняя переменная var72
	 30243	,1	,1	,&var48},	//Внутренняя переменная var48
	 30244	,1	,1	,&var192},	//Внутренняя переменная var192
	 30245	,1	,1	,&var193},	//Внутренняя переменная var193
	 30246	,8	,1	,&var283},	//Внутренняя переменная var283
	 30247	,1	,1	,&var294},	//Внутренняя переменная var294
	 30248	,1	,1	,&var299},	//Внутренняя переменная var299
	 30249	,8	,1	,&var4},	//Внутренняя переменная var4
	 30250	,1	,1	,&var13},	//Внутренняя переменная var13
	 30251	,1	,1	,&var316},	//Внутренняя переменная var316
	 30252	,8	,1	,&var98},	//Внутренняя переменная var98
	 30253	,1	,1	,&var201},	//Внутренняя переменная var201
	 30254	,1	,1	,&var306},	//Внутренняя переменная var306
	 30255	,1	,1	,&var331},	//Внутренняя переменная var331
	 30256	,1	,1	,&var31},	//Внутренняя переменная var31
	 30257	,8	,1	,&var56},	//Внутренняя переменная var56
	 30258	,1	,1	,&var90},	//Внутренняя переменная var90
	 30259	,1	,1	,&var88},	//Внутренняя переменная var88
	 30260	,3	,1	,&var143},	//Внутренняя переменная var143
	 30261	,1	,1	,&var2},	//Внутренняя переменная var2
	 30262	,1	,1	,&var83},	//Внутренняя переменная var83
	 30263	,8	,1	,&var153},	//Внутренняя переменная var153
	 30264	,1	,1	,&var37},	//Внутренняя переменная var37
	 30265	,8	,1	,&var140},	//Внутренняя переменная var140
	 30266	,1	,1	,&var251},	//Внутренняя переменная var251
	 30267	,1	,1	,&var312},	//Внутренняя переменная var312
	 30268	,8	,1	,&var181},	//Внутренняя переменная var181
	 30269	,1	,1	,&var186},	//Внутренняя переменная var186
	 30270	,1	,1	,&var271},	//Внутренняя переменная var271
	 30271	,8	,1	,&var296},	//Внутренняя переменная var296
	 30272	,1	,1	,&var209},	//Внутренняя переменная var209
	 30273	,1	,1	,&var317},	//Внутренняя переменная var317
	 30274	,1	,1	,&var330},	//Внутренняя переменная var330
	 30275	,1	,1	,&var70},	//Внутренняя переменная var70
	 30276	,1	,1	,&var163},	//Внутренняя переменная var163
	 30277	,1	,1	,&var169},	//Внутренняя переменная var169
	 30278	,1	,1	,&var174},	//Внутренняя переменная var174
	 30279	,8	,1	,&var221},	//Внутренняя переменная var221
	 30280	,1	,1	,&var254},	//Внутренняя переменная var254
	 30281	,8	,1	,&var110},	//Внутренняя переменная var110
	 30282	,3	,1	,&var165},	//Внутренняя переменная var165
	 30283	,1	,1	,&var76},	//Внутренняя переменная var76
	 30284	,1	,1	,&var82},	//Внутренняя переменная var82
	 30285	,8	,1	,&var148},	//Внутренняя переменная var148
	 30286	,1	,1	,&var218},	//Внутренняя переменная var218
	 30287	,8	,1	,&var220},	//Внутренняя переменная var220
	 30288	,1	,1	,&var248},	//Внутренняя переменная var248
	 30289	,1	,1	,&var64},	//Внутренняя переменная var64
	 30290	,1	,1	,&var69},	//Внутренняя переменная var69
	 30291	,1	,1	,&var24},	//Внутренняя переменная var24
	 30292	,1	,1	,&var39},	//Внутренняя переменная var39
	 30293	,1	,1	,&var126},	//Внутренняя переменная var126
	 30294	,1	,1	,&var11},	//Внутренняя переменная var11
	 30295	,1	,1	,&var22},	//Внутренняя переменная var22
	 30296	,11	,1	,&var147},	//Внутренняя переменная var147
	 30297	,1	,1	,&var257},	//Внутренняя переменная var257
	 30298	,1	,1	,&var263},	//Внутренняя переменная var263
	 30299	,1	,1	,&var99},	//Внутренняя переменная var99
	 30300	,1	,1	,&var120},	//Внутренняя переменная var120
	 30301	,8	,1	,&var129},	//Внутренняя переменная var129
	 30302	,3	,1	,&var156},	//Внутренняя переменная var156
	 30303	,1	,1	,&var207},	//Внутренняя переменная var207
	 30304	,1	,1	,&var285},	//Внутренняя переменная var285
	 30305	,8	,1	,&var325},	//Внутренняя переменная var325
	 30306	,1	,1	,&var327},	//Внутренняя переменная var327
	 30307	,8	,1	,&var8},	//Внутренняя переменная var8
	 30308	,1	,1	,&var73},	//Внутренняя переменная var73
	 30309	,1	,1	,&var100},	//Внутренняя переменная var100
	 30310	,1	,1	,&var196},	//Внутренняя переменная var196
	 30311	,1	,1	,&var203},	//Внутренняя переменная var203
	 30312	,1	,1	,&var205},	//Внутренняя переменная var205
	 30313	,1	,1	,&var230},	//Внутренняя переменная var230
	 30314	,1	,1	,&var291},	//Внутренняя переменная var291
	 30315	,1	,1	,&var33},	//Внутренняя переменная var33
	 30316	,1	,1	,&var86},	//Внутренняя переменная var86
	 30317	,1	,1	,&var52},	//Внутренняя переменная var52
	 30318	,1	,1	,&var164},	//Внутренняя переменная var164
	 30319	,1	,1	,&var180},	//Внутренняя переменная var180
	 30320	,1	,1	,&var217},	//Внутренняя переменная var217
	 30321	,8	,1	,&var235},	//Внутренняя переменная var235
	 30322	,1	,1	,&var277},	//Внутренняя переменная var277
	 30323	,1	,1	,&var10},	//Внутренняя переменная var10
	 30324	,1	,1	,&var28},	//Внутренняя переменная var28
	 30325	,8	,1	,&var334},	//Внутренняя переменная var334
	 30326	,1	,1	,&var81},	//Внутренняя переменная var81
	 30327	,1	,1	,&var84},	//Внутренняя переменная var84
	 30328	,1	,1	,&var305},	//Внутренняя переменная var305
	 30329	,11	,1	,&vainSLong},	//Внутренняя переменная vainSLong
	 30330	,	,1	,&vainSChar},	//Внутренняя переменная vainSChar
	 30331	,1	,1	,&var19},	//Внутренняя переменная var19
	 30332	,1	,1	,&var68},	//Внутренняя переменная var68
	 30333	,1	,1	,&var268},	//Внутренняя переменная var268
	 30334	,1	,1	,&var20},	//Внутренняя переменная var20
	 30335	,1	,1	,&var107},	//Внутренняя переменная var107
	 30336	,3	,1	,&var162},	//Внутренняя переменная var162
	 30337	,1	,1	,&var206},	//Внутренняя переменная var206
	 30338	,1	,1	,&var279},	//Внутренняя переменная var279
	 30339	,1	,1	,&var321},	//Внутренняя переменная var321
	 30340	,1	,1	,&var51},	//Внутренняя переменная var51
	 30341	,8	,1	,&var96},	//Внутренняя переменная var96
	{-1,0,NULL},
}
static char NameSaveFile[]="scm.bin\0"; //Имя файла сохранения переменных
#pragma pop
static VarSaveCtrl saveVariables[]={	//Id переменных для сохранения
	{513,"fEM_R7UX09RSS\0"},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{296,"fEM_A0UX06RSS\0"},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{537,"iEM_TERA0VP81LIM\0"},	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
	{541,"iEM_TERA1SS11LIM\0"},	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
	{1045,"lEM_R3AD10LC1\0"},	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
	{591,"iEM_TERB2SS33LIM\0"},	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{507,"fEM_R7UX02RSS\0"},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{297,"fEM_A0UX07RSS\0"},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{300,"fEM_A0UX10RSS\0"},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{370,"fEM_A4UL10RIM\0"},	//(A4UL10RIM) Время полного перемещения НИ сек
	{554,"iEM_TERA3SS11LIM\0"},	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
	{628,"iEM_TERR1SS11LIM\0"},	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
	{626,"iEM_TERNL2\0"},	//(TERNL2) Неисправности НЛ2
	{631,"iEM_TERR1VS22LIM\0"},	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
	{316,"fEM_A1UC06RIM\0"},	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
	{331,"fEM_A2UC02RDU\0"},	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{446,"fEM_R0UH03RSS\0"},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
	{306,"fEM_A1MC01RC1\0"},	//(A1MC01RC1) Заданная координата  ББ1 от ИС
	{648,"iEM_TERR6IS66LIM\0"},	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{623,"iEM_TERMDZ1\0"},	//(TERMDZ1) Неисправности МДЗ1
	{566,"iEM_TERA5VS22LIM\0"},	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
	{441,"fEM_B8US80RDU\0"},	//(B8US80RDU) Тормозной путь АЗ2 (мм)
	{503,"fEM_R7UI76RIM\0"},	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{561,"iEM_TERA4SS21LIM\0"},	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
	{622,"iEM_TERMAZ2\0"},	//(TERMAZ2) Неисправности АЗ2 от ИС
	{625,"iEM_TERNL1\0"},	//(TERNL1) Неисправности НЛ1
	{474,"fEM_R1MC01RSP\0"},	//(R1MC01RSP) Стартовая координата МДЗ1
	{454,"fEM_R0UL04RIM\0"},	//(R0UL04RIM) Время блокировки повторной генерации импульса
	{542,"iEM_TERA1SS12LIM\0"},	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
	{459,"fEM_R0UT01RIM\0"},	//(R0UT01RIM) Температурный коэффициент (долл)
	{497,"fEM_R7UI02RIM\0"},	//(R7UI02RIM) Коэффициент усиления уровня радиации
	{508,"fEM_R7UX04RSS\0"},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{539,"iEM_TERA1IE04LDU\0"},	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
	{536,"iEM_TERA0MT01RIM\0"},	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
	{606,"iEM_TERB6SS21LIM\0"},	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
	{602,"iEM_TERB5SS21LIM\0"},	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
	{307,"fEM_A1MC01RSP\0"},	//(A1MC01RSP) Стартовая координата  ББ1
	{604,"iEM_TERB5VS22LIM\0"},	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
	{534,"fEM_R7UY14RSS\0"},	//(R7UY14RSS) Y-координата камеры R7IN52
	{365,"fEM_A3UR00RIM\0"},	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{472,"fEM_R0UV87RDU\0"},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{381,"fEM_A6US80RDU\0"},	//(A6US80RDU) Тормозной путь БЗ (мм)
	{533,"fEM_R7UY13RSS\0"},	//(R7UY13RSS) Y-координата камеры R7IN51
	{315,"fEM_A1UC05RIM\0"},	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
	{364,"fEM_A3UP04RDU\0"},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{522,"fEM_R7UY01RSS\0"},	//(R7UY01RSS) Y-координата камеры R7IN11
	{418,"fEM_B2MV01RC1\0"},	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
	{382,"fEM_A8MC01RC1\0"},	//(A8MC01RC1) Заданная координата ДС2 от ИС
	{304,"fEM_A0UX14RSS\0"},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{327,"fEM_A2MC02RC1\0"},	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
	{352,"fEM_A3MV02RC1\0"},	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
	{598,"iEM_TERB3SS33LIM\0"},	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{641,"iEM_TERR4SS22LIM\0"},	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
	{325,"fEM_A2MC01RC1\0"},	//(A2MC01RC1) Заданная координата РБ1 от ИС
	{485,"fEM_R4UC08RDU\0"},	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
	{308,"fEM_A1MC02RC1\0"},	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
	{555,"iEM_TERA3SS21LIM\0"},	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
	{378,"fEM_A6MC01RSP\0"},	//(A6MC01RSP) Стартовая координата БЗ1
	{1042,"lEM_C1AD31LRP\0"},	//(C1AD31LRP) Общий сброс от РПУ
	{589,"iEM_TERB2SS12LIM\0"},	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
	{653,"iEM_TERR8SS11LIM\0"},	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
	{451,"fEM_R0UL01RIM\0"},	//(R0UL01RIM) Среднее время генерации нейтронов
	{486,"fEM_R4UC10RIM\0"},	//(R4UC10RIM) Координата верхних механических упоров тележки мм
	{282,"fEM_A0UN01RIM\0"},	//(A0UN01RIM) Мощность источника нейтронов ИНИ
	{340,"fEM_A2UP03RDU\0"},	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{320,"fEM_A1UP82RIM\0"},	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{448,"fEM_R0UH21RSS\0"},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{605,"iEM_TERB6SS11LIM\0"},	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
	{457,"fEM_R0UR30RIM\0"},	//(R0UR30RIM) Реактивность вносимая образцами (долл)
	{512,"fEM_R7UX08RSS\0"},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{514,"fEM_R7UX10RSS\0"},	//(R7UX10RSS) X-координата камеры R7IN41
	{292,"fEM_A0UX02RSS\0"},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{293,"fEM_A0UX03RSS\0"},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{550,"iEM_TERA2SS33LIM\0"},	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{629,"iEM_TERR1SS21LIM\0"},	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
	{573,"iEM_TERA8SS12LIM\0"},	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
	{642,"iEM_TERR4VS12LDU\0"},	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{461,"fEM_R0UT02RIM\0"},	//(R0UT02RIM) Масса топлива в АЗ
	{437,"fEM_B8UC10RIM\0"},	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
	{389,"fEM_A8UC20RIM\0"},	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
	{532,"fEM_R7UY12RSS\0"},	//(R7UY12RSS) Y-координата камеры R7IN43
	{391,"fEM_A8US80RDU\0"},	//(A8US80RDU) Тормозной путь ДС2 (мм)
	{420,"fEM_B3MC01RC1\0"},	//(B3MC01RC1) Заданная координата ИС2 от ИС
	{455,"fEM_R0UN02RIM\0"},	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{438,"fEM_B8UC11RIM\0"},	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
	{332,"fEM_A2UC03RDU\0"},	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{399,"fEM_B0UX04RSS\0"},	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
	{593,"iEM_TERB3SP02RIM\0"},	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{565,"iEM_TERA5VS12LIM\0"},	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
	{314,"fEM_A1UC04RIM\0"},	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
	{509,"fEM_R7UX05RSS\0"},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{498,"fEM_R7UI71RIM\0"},	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{556,"iEM_TERA3SS22LIM\0"},	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
	{373,"fEM_A5MC01RC1\0"},	//(A5MC01RC1) Заданная координата НЛ1 от ИС
	{288,"fEM_A0UR02RSP\0"},	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
	{359,"fEM_A3UG01RDU\0"},	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
	{311,"fEM_A1MV02RC1\0"},	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
	{599,"iEM_TERB4SS11LIM\0"},	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
	{612,"iEM_TERB8SS22LIM\0"},	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
	{430,"fEM_B6MC01RC1\0"},	//(B6MC01RC1) Заданная координата БЗ2 от ИС
	{491,"fEM_R5UC01RSP\0"},	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
	{353,"fEM_A3UC02RDU\0"},	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{580,"iEM_TERB1IE04LDU\0"},	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
	{646,"iEM_TERR6IS62LIM\0"},	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
	{562,"iEM_TERA4VP82LIM\0"},	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
	{484,"fEM_R4MV01RC1\0"},	//(R4MV01RC1) Заданная скорость тележки от ИС
	{603,"iEM_TERB5VS12LIM\0"},	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
	{643,"iEM_TERR4VS22LDU\0"},	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{371,"fEM_A4UP01RIM\0"},	//(A4UP01RIM) Текущее давление на подъём НИ
	{422,"fEM_B3MC02RC1\0"},	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
	{408,"fEM_B1MC01RC1\0"},	//(B1MC01RC1) Заданная координата ББ2 от ИС
	{634,"iEM_TERR2VS12LIM\0"},	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
	{635,"iEM_TERR2VS22LIM\0"},	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
	{510,"fEM_R7UX06RSS\0"},	//(R7UX06RSS) X-координата камеры R7IN23 (см)
	{652,"iEM_TERR7SI74RIM\0"},	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
	{644,"iEM_TERR5SS11LIM\0"},	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
	{1046,"lEM_R3AD20LC1\0"},	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
	{519,"fEM_R7UX15RSS\0"},	//(R7UX15RSS) X-координата камеры R7IN53
	{462,"fEM_R0UT03RIM\0"},	//(R0UT03RIM) Нормальная температура АЗ град
	{499,"fEM_R7UI72RIM\0"},	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{615,"iEM_TERBB1\0"},	//(TERBB1) Неисправности  ББ1
	{414,"fEM_B2MC01RC1\0"},	//(B2MC01RC1) Заданная координата РБ2 от ИС
	{1049,"lEM_R6AD10LC1\0"},	//(R6AD10LC1) Выкатить кран-балку от ИС
	{312,"fEM_A1UC02RDU\0"},	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{324,"fEM_A1UV02RIM\0"},	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{552,"iEM_TERA3SC01RIM\0"},	//(TERA3SC01RIM) Искажение: Координата штока ИС1
	{335,"fEM_A2UC06RIM\0"},	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
	{528,"fEM_R7UY08RSS\0"},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{419,"fEM_B2MV02RC1\0"},	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
	{349,"fEM_A3MC02RC1\0"},	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
	{576,"iEM_TERA9SS21LIM\0"},	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
	{581,"iEM_TERB1MC01RIM\0"},	//(TERB1MC01RIM) Искажение: Координата штока ББ2
	{329,"fEM_A2MV01RC1\0"},	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
	{449,"fEM_R0UH22RSS\0"},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{407,"fEM_B0UX12RSS\0"},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{655,"iEM_TERRB2\0"},	//(TERRB2) Неисправности  РБ2
	{613,"iEM_TERB9SS11LIM\0"},	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
	{421,"fEM_B3MC01RSP\0"},	//(B3MC01RSP) Стартовая координата  ИС2
	{489,"fEM_R4US80RDU\0"},	//(R4US80RDU) Тормозной путь тележки (мм)
	{429,"fEM_B5MV01RC1\0"},	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
	{358,"fEM_A3UC08RIM\0"},	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
	{350,"fEM_A3MC02RSP\0"},	//(A3MC02RSP) Стартовая координата штока ИС1
	{608,"iEM_TERB6VS22LIM\0"},	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{343,"fEM_A2UR00RIM\0"},	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{500,"fEM_R7UI73RIM\0"},	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
	{632,"iEM_TERR2SS11LIM\0"},	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
	{571,"iEM_TERA7MS31LIM\0"},	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{582,"iEM_TERB1SS11LIM\0"},	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
	{387,"fEM_A8UC10RIM\0"},	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
	{344,"fEM_A2UR01RIM\0"},	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{460,"fEM_R0UT02RDU\0"},	//(R0UT02RDU) Верхний предел шкалы датчика температуры
	{295,"fEM_A0UX05RSS\0"},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{286,"fEM_A0UP02RIM\0"},	//(A0UP02RIM) Текущее давление в АЗ1,2
	{412,"fEM_B1MV01RC1\0"},	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
	{640,"iEM_TERR4SS12LIM\0"},	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
	{601,"iEM_TERB5SS11LIM\0"},	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
	{469,"fEM_R0UV84RDU\0"},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{404,"fEM_B0UX09RSS\0"},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{319,"fEM_A1UP01RIM\0"},	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
	{361,"fEM_A3UP02RDU\0"},	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
	{416,"fEM_B2MC02RC1\0"},	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
	{548,"iEM_TERA2SS12LIM\0"},	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
	{564,"iEM_TERA5SS21LIM\0"},	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
	{636,"iEM_TERR3SS11LIM\0"},	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
	{543,"iEM_TERA1SS21LIM\0"},	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
	{375,"fEM_A5MV01RC1\0"},	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
	{445,"fEM_R0UH02RSS\0"},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{372,"fEM_A4UP02RIM\0"},	//(A4UP02RIM) Нижняя граница давления на подъём НИ
	{547,"iEM_TERA2SS11LIM\0"},	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
	{578,"iEM_TERB0VP81LIM\0"},	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
	{338,"fEM_A2UP01RIM\0"},	//(A2UP01RIM) Текущее давление на сброс РБ
	{328,"fEM_A2MC02RSP\0"},	//(A2MC02RSP) Стартовая координата штока РБ1
	{415,"fEM_B2MC01RSP\0"},	//(B2MC01RSP) Стартовая координата  РБ2
	{317,"fEM_A1UC08RIM\0"},	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
	{463,"fEM_R0UT04RIM\0"},	//(R0UT04RIM) Удельная теплоёмкость топлива
	{283,"fEM_A0UN02RIM\0"},	//(A0UN02RIM) Мощность источника нейтронов с АНИ
	{515,"fEM_R7UX11RSS\0"},	//(R7UX11RSS) X-координата камеры R7IN42
	{502,"fEM_R7UI75RIM\0"},	//(R7UI75RIM) Множитель к уровню радиации
	{351,"fEM_A3MV01RC1\0"},	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
	{586,"iEM_TERB2SC01RIM\0"},	//(TERB2SC01RIM) Искажение: Координата штока РБ2
	{610,"iEM_TERB8SC01RIM\0"},	//(TERB8SC01RIM) Искажение: Координата АЗ2
	{478,"fEM_R2MC01RSP\0"},	//(R2MC01RSP) Стартовая координата МДЗ2
	{356,"fEM_A3UC05RIM\0"},	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
	{400,"fEM_B0UX05RSS\0"},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{546,"iEM_TERA2SP01RIM\0"},	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
	{545,"iEM_TERA2SC01RIM\0"},	//(TERA2SC01RIM) Искажение: Координата штока РБ1
	{357,"fEM_A3UC06RIM\0"},	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
	{360,"fEM_A3UP01RIM\0"},	//(A3UP01RIM) Текущее давление на СПУСК ИС
	{367,"fEM_A3US07RDU\0"},	//(A3US07RDU) Постоянная времени масляного демпфера ИС
	{341,"fEM_A2UP03RIM\0"},	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
	{473,"fEM_R1MC01RC1\0"},	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
	{630,"iEM_TERR1VS12LIM\0"},	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
	{321,"fEM_A1UR00RIM\0"},	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{406,"fEM_B0UX11RSS\0"},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{614,"iEM_TERB9SS21LIM\0"},	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
	{379,"fEM_A6MV01RC1\0"},	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
	{305,"fEM_A0UX15RSS\0"},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{354,"fEM_A3UC03RDU\0"},	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{285,"fEM_A0UP01RIM\0"},	//(A0UP01RIM) Текущее давление в АЗ1,2
	{568,"iEM_TERA6SS21LIM\0"},	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
	{310,"fEM_A1MV01RC1\0"},	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
	{334,"fEM_A2UC05RIM\0"},	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
	{488,"fEM_R4UC22RIM\0"},	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
	{435,"fEM_B8MV01RC1\0"},	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
	{284,"fEM_A0UN07RIM\0"},	//(A0UN07RIM) Доля запаздывающих нейтронов
	{442,"fEM_B8UV80RDU\0"},	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
	{385,"fEM_A8UC03RDU\0"},	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{529,"fEM_R7UY09RSS\0"},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{345,"fEM_A2US07RDU\0"},	//(A2US07RDU) Постоянная времени масляного демпфера РБ
	{450,"fEM_R0UH23RSS\0"},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{551,"iEM_TERA2VP82LIM\0"},	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
	{574,"iEM_TERA8SS22LIM\0"},	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
	{426,"fEM_B4MC01RSP\0"},	//(B4MC01RSP) Стартовая координата НИ2
	{380,"fEM_A6UC10RIM\0"},	//(A6UC10RIM) Время полного хода БЗ (сек)
	{516,"fEM_R7UX12RSS\0"},	//(R7UX12RSS) X-координата камеры R7IN43
	{405,"fEM_B0UX10RSS\0"},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{1044,"lEM_R0IE02LRP\0"},	//(R0IE02LRP) Отключить питание ПР, ПУ
	{1050,"lEM_R8AD10LC1\0"},	//(R8AD10LC1) Установить аварийный НИ от ИС
	{585,"iEM_TERB1VP81LIM\0"},	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
	{393,"fEM_A9MC01RSP\0"},	//(A9MC01RSP) Стартовая координата НИ ДС1
	{563,"iEM_TERA5SS11LIM\0"},	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{567,"iEM_TERA6MS11LIM\0"},	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
	{493,"fEM_R6UC01RSP\0"},	//(R6UC01RSP) Стартовая координата Кран-балки
	{464,"fEM_R0UT05RIM\0"},	//(R0UT05RIM) Энергия деления ядра
	{337,"fEM_A2UG01RDU\0"},	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
	{496,"fEM_R7UC19RIM\0"},	//(R7UC19RIM) Y-координата СНМ-11 (11) см
	{313,"fEM_A1UC03RDU\0"},	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{396,"fEM_B0UX01RSS\0"},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{425,"fEM_B3MV02RC1\0"},	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
	{627,"iEM_TERR0VP81LIM\0"},	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{390,"fEM_A8UC21RIM\0"},	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
	{506,"fEM_R7UX01RSS\0"},	//(R7UX01RSS) X-координата камеры R7IN11
	{526,"fEM_R7UY06RSS\0"},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{397,"fEM_B0UX02RSS\0"},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{594,"iEM_TERB3SS11LIM\0"},	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
	{559,"iEM_TERA3VP81LIM\0"},	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
	{355,"fEM_A3UC04RIM\0"},	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
	{439,"fEM_B8UC20RIM\0"},	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
	{318,"fEM_A1UG01RDU\0"},	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
	{456,"fEM_R0UR01RIM\0"},	//(R0UR01RIM) Стартовая отрицательная реактивность
	{471,"fEM_R0UV86RDU\0"},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{1043,"lEM_R0IE01LRP\0"},	//(R0IE01LRP) Отключение питание детекторов
	{330,"fEM_A2MV02RC1\0"},	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
	{592,"iEM_TERB3SC01RIM\0"},	//(TERB3SC01RIM) Искажение: Координата штока ИС2
	{588,"iEM_TERB2SS11LIM\0"},	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
	{336,"fEM_A2UC08RIM\0"},	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
	{480,"fEM_R3UC01RSP\0"},	//(R3UC01RSP) Стартовая координата Гомогенных дверей
	{535,"fEM_R7UY15RSS\0"},	//(R7UY15RSS) Y-координата камеры R7IN53
	{619,"iEM_TERDS2\0"},	//(TERDS2) Неисправности ДС2 от ИС
	{531,"fEM_R7UY11RSS\0"},	//(R7UY11RSS) Y-координата камеры R7IN42
	{291,"fEM_A0UX01RSS\0"},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{294,"fEM_A0UX04RSS\0"},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{339,"fEM_A2UP02RIM\0"},	//(A2UP02RIM) Текущее давление на подъём РБ
	{557,"iEM_TERA3SS31LIM\0"},	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{649,"iEM_TERR6IS67LIM\0"},	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{590,"iEM_TERB2SS21LIM\0"},	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
	{1047,"lEM_R5AD10LC1\0"},	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
	{409,"fEM_B1MC01RSP\0"},	//(B1MC01RSP) Стартовая координата  ББ2
	{383,"fEM_A8MC01RSP\0"},	//(A8MC01RSP) Стартовая координата ДС2
	{369,"fEM_A4MC01RSP\0"},	//(A4MC01RSP) Стартовая координата НИ1
	{569,"iEM_TERA6VS12LIM\0"},	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{333,"fEM_A2UC04RIM\0"},	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
	{476,"fEM_R1UC10RIM\0"},	//(R1UC10RIM) Время полного хода МДЗ сек
	{495,"fEM_R7UC10RIM\0"},	//(R7UC10RIM) X-координата КНК53М R7IN13 см
	{525,"fEM_R7UY05RSS\0"},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{346,"fEM_A2UV02RIM\0"},	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{618,"iEM_TERBZ2\0"},	//(TERBZ2) Неисправности БЗ2
	{309,"fEM_A1MC02RSP\0"},	//(A1MC02RSP) Стартовая координата штока ББ1
	{388,"fEM_A8UC11RIM\0"},	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
	{413,"fEM_B1MV02RC1\0"},	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
	{637,"iEM_TERR3SS21LIM\0"},	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
	{444,"fEM_R0UH01RSS\0"},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
	{527,"fEM_R7UY07RSS\0"},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{299,"fEM_A0UX09RSS\0"},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{402,"fEM_B0UX07RSS\0"},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{620,"iEM_TERIS1\0"},	//(TERIS1) Неисправности  ИС1
	{424,"fEM_B3MV01RC1\0"},	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
	{624,"iEM_TERMDZ2\0"},	//(TERMDZ2) Неисправности МДЗ2
	{505,"fEM_R7UL01RIM\0"},	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
	{386,"fEM_A8UC08RDU\0"},	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
	{524,"fEM_R7UY04RSS\0"},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{301,"fEM_A0UX11RSS\0"},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{347,"fEM_A3MC01RC1\0"},	//(A3MC01RC1) Заданная координата ИС1 от ИС
	{575,"iEM_TERA9SS11LIM\0"},	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
	{656,"iEM_TERTLG\0"},	//(TERTLG) Неисправности  тележки от ИС
	{544,"iEM_TERA1VP81LIM\0"},	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
	{326,"fEM_A2MC01RSP\0"},	//(A2MC01RSP) Стартовая координата  РБ1
	{517,"fEM_R7UX13RSS\0"},	//(R7UX13RSS) X-координата камеры R7IN51
	{290,"fEM_A0UX00RSS\0"},	//(A0UX00RSS) Эффективный радиус АЗ
	{523,"fEM_R7UY02RSS\0"},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{394,"fEM_A9UL10RIM\0"},	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
	{651,"iEM_TERR6SS21LIM\0"},	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
	{639,"iEM_TERR4SS11LIM\0"},	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
	{572,"iEM_TERA8SC01RIM\0"},	//(TERA8SC01RIM) Искажение: Координата ДС2
	{443,"fEM_B9MC01RSP\0"},	//(B9MC01RSP) Стартовая координата НИ ДС2
	{376,"fEM_A5UC10RIM\0"},	//(A5UC10RIM) Время полного хода НЛ сек
	{595,"iEM_TERB3SS21LIM\0"},	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
	{645,"iEM_TERR5SS21LIM\0"},	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
	{611,"iEM_TERB8SS12LIM\0"},	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
	{481,"fEM_R3UL10RIM\0"},	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
	{384,"fEM_A8MV01RC1\0"},	//(A8MV01RC1) Заданная скорость ДС2 от ИС
	{432,"fEM_B6MV01RC1\0"},	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
	{411,"fEM_B1MC02RSP\0"},	//(B1MC02RSP) Стартовая координата штока ББ2
	{431,"fEM_B6MC01RSP\0"},	//(B6MC01RSP) Стартовая координата БЗ2
	{607,"iEM_TERB6VS12LIM\0"},	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{433,"fEM_B8MC01RC1\0"},	//(B8MC01RC1) Заданная координата АЗ2 от ИС
	{322,"fEM_A1UR01RIM\0"},	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{458,"fEM_R0UT01RDU\0"},	//(R0UT01RDU) Нижний предел шкалы датчика температуры
	{436,"fEM_B8UC08RDU\0"},	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
	{492,"fEM_R5UL10RIM\0"},	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
	{579,"iEM_TERB1IE03LDU\0"},	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
	{638,"iEM_TERR4MS21LIM\0"},	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
	{303,"fEM_A0UX13RSS\0"},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{392,"fEM_A8UV80RDU\0"},	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
	{466,"fEM_R0UV81RDU\0"},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{494,"fEM_R6UL10RIM\0"},	//(R6UL10RIM) Время полного хода кран-балки сек
	{597,"iEM_TERB3SS31LIM\0"},	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{377,"fEM_A6MC01RC1\0"},	//(A6MC01RC1) Заданная координата БЗ1 от ИС
	{520,"fEM_R7UX16RSS\0"},	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
	{577,"iEM_TERB0MT01RIM\0"},	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
	{647,"iEM_TERR6IS64LIM\0"},	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
	{584,"iEM_TERB1SS21LIM\0"},	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
	{617,"iEM_TERBZ1\0"},	//(TERBZ1) Неисправности БЗ1
	{417,"fEM_B2MC02RSP\0"},	//(B2MC02RSP) Стартовая координата штока РБ2
	{483,"fEM_R4MC01RSP\0"},	//(R4MC01RSP) Стартовая координата тележки
	{452,"fEM_R0UL02RDU\0"},	//(R0UL02RDU) Время задержки  ИНИ
	{465,"fEM_R0UT06RIM\0"},	//(R0UT06RIM) Конвекционное сопротивление при обдуве
	{501,"fEM_R7UI74RIM\0"},	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
	{467,"fEM_R0UV82RDU\0"},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{398,"fEM_B0UX03RSS\0"},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{348,"fEM_A3MC01RSP\0"},	//(A3MC01RSP) Стартовая координата  ИС1
	{410,"fEM_B1MC02RC1\0"},	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
	{654,"iEM_TERRB1\0"},	//(TERRB1) Неисправности  РБ1
	{600,"iEM_TERB4SS21LIM\0"},	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
	{477,"fEM_R2MC01RC1\0"},	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
	{434,"fEM_B8MC01RSP\0"},	//(B8MC01RSP) Стартовая координата АЗ2
	{453,"fEM_R0UL02RIM\0"},	//(R0UL02RIM) Время удержания синхроимпульса
	{487,"fEM_R4UC20RIM\0"},	//(R4UC20RIM) Координата нижних механических упоров тележки мм
	{368,"fEM_A3UV02RIM\0"},	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{616,"iEM_TERBB2\0"},	//(TERBB2) Неисправности  ББ2
	{475,"fEM_R1MV01RC1\0"},	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
	{427,"fEM_B5MC01RC1\0"},	//(B5MC01RC1) Заданная координата НЛ2 от ИС
	{287,"fEM_A0UR01RSP\0"},	//(A0UR01RSP) Стартовая  реактивность АЗ1
	{374,"fEM_A5MC01RSP\0"},	//(A5MC01RSP) Стартовая координата НЛ1
	{511,"fEM_R7UX07RSS\0"},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{447,"fEM_R0UH05RSS\0"},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{540,"iEM_TERA1SC01RIM\0"},	//(TERA1SC01RIM) Искажение: Координата штока ББ1
	{583,"iEM_TERB1SS12LIM\0"},	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
	{289,"fEM_A0UT03RSP\0"},	//(A0UT03RSP) Стартовая  температура АЗ1 град
	{570,"iEM_TERA6VS22LIM\0"},	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{366,"fEM_A3UR01RIM\0"},	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{298,"fEM_A0UX08RSS\0"},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{621,"iEM_TERIS2\0"},	//(TERIS2) Неисправности  ИС2
	{538,"iEM_TERA1IE03LDU\0"},	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
	{596,"iEM_TERB3SS22LIM\0"},	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
	{482,"fEM_R4MC01RC1\0"},	//(R4MC01RC1) Заданная координата тележки от ИС
	{440,"fEM_B8UC21RIM\0"},	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
	{342,"fEM_A2UP04RDU\0"},	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{470,"fEM_R0UV85RDU\0"},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{401,"fEM_B0UX06RSS\0"},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{587,"iEM_TERB2SP01RIM\0"},	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
	{560,"iEM_TERA4SS11LIM\0"},	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
	{479,"fEM_R2MV01RC1\0"},	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
	{490,"fEM_R4UV80RDU\0"},	//(R4UV80RDU) Номинальная скорость тележки (см/с)
	{302,"fEM_A0UX12RSS\0"},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{395,"fEM_B0UT03RSP\0"},	//(B0UT03RSP) Стартовая  температура АЗ2 град
	{609,"iEM_TERB7MS31LIM\0"},	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{521,"fEM_R7UY00RSS\0"},	//(R7UY00RSS) Y-координата АЗ1 см
	{323,"fEM_A1US07RDU\0"},	//(A1US07RDU) Постоянная времени масляного демпфера ББ
	{549,"iEM_TERA2SS21LIM\0"},	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
	{558,"iEM_TERA3SS33LIM\0"},	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{423,"fEM_B3MC02RSP\0"},	//(B3MC02RSP) Стартовая координата штока ИС2
	{363,"fEM_A3UP03RDU\0"},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{468,"fEM_R0UV83RDU\0"},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{530,"fEM_R7UY10RSS\0"},	//(R7UY10RSS) Y-координата камеры R7IN41
	{650,"iEM_TERR6IS68LIM\0"},	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{1048,"lEM_R5AD20LC1\0"},	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
	{403,"fEM_B0UX08RSS\0"},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{362,"fEM_A3UP02RIM\0"},	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
	{504,"fEM_R7UI77RIM\0"},	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{553,"iEM_TERA3SP02RIM\0"},	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{633,"iEM_TERR2SS21LIM\0"},	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
	{428,"fEM_B5MC01RSP\0"},	//(B5MC01RSP) Стартовая координата НЛ2
	{518,"fEM_R7UX14RSS\0"},	//(R7UX14RSS) X-координата камеры R7IN52
	{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_SCM[]={
	{&R0MW13LP2,2,5},	//( - , SCM) Переключатель «СЕТЬ»
	{&lEM_R8AD10LC1,2,14},	//( - , SCM) Установить аварийный НИ от ИС
	{&lEM_R0IE01LRP,2,7},	//( - , SCM) Отключение питание детекторов
	{&C2MD31LP1,2,2},	//( - , SCM) Кнопка «СБРОС РБ»
	{&lEM_R3AD20LC1,2,10},	//( - , SCM) Гомогенные двери-1 закрыть от ИС
	{&lEM_R0IE02LRP,2,8},	//( - , SCM) Отключить питание ПР, ПУ
	{&lEM_R6AD10LC1,2,11},	//( - , SCM) Выкатить кран-балку от ИС
	{&lEM_R3AD10LC1,2,9},	//( - , SCM) Гомогенные двери-1 открыть от ИС
	{&R0VZ71LZ2,2,1},	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
	{&lEM_C1AD31LRP,2,6},	//( - , SCM) Общий сброс от РПУ
	{&C1MD31LP1,2,4},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
	{&lEM_R5AD10LC1,2,12},	//( - , SCM) Открыть ворота отстойной зоны от ИС
	{&C1MD31LP2,2,3},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
	{&R0VZ71LZ1,2,0},	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
	{&lEM_R5AD20LC1,2,13},	//( - , SCM) Закрыть ворота отстойной зоны от ИС
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SCM[]={
	{&A6VS12LDU,2,1},	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
	{&A1IS32LIM,2,20},	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
	{&B1IS32LIM,2,22},	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
	{&B2IS32LIM,2,26},	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
	{&R4VS22LDU,2,12},	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
	{&B4IS21LDU,2,14},	//( - K08DO, SCM) Приход на НУ НИ2
	{&B5VS12LDU,2,7},	//( - , SCM) Движение НЛ2 в сторону ВУ
	{&A1IE04LDU,2,16},	//( - , SCM) Движение ББ1 назад (от БУШД)
	{&A1IE03LDU,2,15},	//( - , SCM) Движение ББ1 вперед (от БУШД)
	{&B1IE04LDU,2,18},	//( - , SCM) Движение ББ2 назад (от БУШД)
	{&A2IS32LIM,2,24},	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
	{&B2IS11LIM,2,25},	//( - , SCM) Магнит РБ2 обесточен
	{&R2VS22LDU,2,9},	//( - , SCM) Движение МДЗ2 в сторону НУ
	{&A2IS11LIM,2,23},	//( - , SCM) Магнит РБ1 обесточен
	{&B6VS22LDU,2,2},	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
	{&R4VS12LDU,2,13},	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
	{&A5VS12LDU,2,5},	//( - , SCM) Движение НЛ1 в сторону ВУ
	{&A6VS22LDU,2,0},	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
	{&B1IS11LIM,2,21},	//( - , SCM) Магнит ББ2 обесточен
	{&A5VS22LDU,2,4},	//( - , SCM) Движение НЛ1 в сторону НУ
	{&B5VS22LDU,2,6},	//( - , SCM) Движение НЛ2 в сторону НУ
	{&R1VS22LDU,2,8},	//( - , SCM) Движение МДЗ1 в сторону НУ
	{&B6VS12LDU,2,3},	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
	{&R2VS12LDU,2,10},	//( - , SCM) Движение МДЗ2 в сторону ВУ
	{&A1IS11LIM,2,19},	//( - , SCM) Магнит ББ1 обесточен
	{&R1VS12LDU,2,11},	//( - , SCM) Движение МДЗ1 в сторону ВУ
	{&B1IE03LDU,2,17},	//( - , SCM) Движение ББ2 вперед (от БУШД)
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SCM[]={
	{&R0SR02RIM,8,36},	//( - , SCM) Текущая мощность РУ (ватт)
	{&A0SN06RIM,8,8},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
	{&A0SN04RIM,8,4},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
	{&A0SN03RIM,8,2},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
	{&A0SN05RIM,8,6},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
	{&B0SR01RIM,8,26},	//( - , SCM) Текущая реактивность AЗ2
	{&A0VN01RIM,8,42},	//( - , SCM) Период разгона  AЗ1
	{&A0SN02RIM,8,0},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
	{&B0SN08RIM,8,30},	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
	{&B0SN04RIM,8,16},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
	{&B0SN05RIM,8,18},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
	{&B0SN06RIM,8,20},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
	{&A0SN08RIM,8,28},	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
	{&R0CR01RIM,8,32},	//( - , SCM) Коэффициент 12 связи АЗ1,2
	{&R0CR02RIM,8,34},	//( - , SCM) Коэффициент 11 связи АЗ1,2
	{&A0SN07RIM,8,10},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
	{&B0SN07RIM,8,22},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
	{&R0SR01RIM,8,40},	//( - , SCM) Текущая реактивность PУ
	{&A0SR01RIM,8,24},	//( - , SCM) Текущая реактивность AЗ1
	{&B0SN03RIM,8,14},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
	{&R0ST01RIM,8,38},	//( - , SCM) Текущий период разгона РУ
	{&B0SN02RIM,8,12},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SCM[]={
	{&fEM_A2UC02RDU,8,40},	//( - , SCM) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{&fEM_R1MV01RC1,8,492},	//( - , SCM) Заданная скорость МДЗ1 от ИС
	{&iEM_TERR1SS11LIM,3,425},	//( - , SCM) Искажение: Приход на ВУ МДЗ1
	{&fEM_R0UV87RDU,8,132},	//( - , SCM) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_B0UX03RSS,8,228},	//( - , SCM) Второй коэффициент калибровки камеры 3
	{&iEM_TERB2SS21LIM,3,419},	//( - , SCM) Искажение: Приход на НУ РБ2
	{&fEM_A0UN02RIM,8,104},	//( - , SCM) Мощность источника нейтронов с АНИ
	{&fEM_A2UP04RDU,8,118},	//( - , SCM) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{&fEM_R0UH02RSS,8,248},	//( - , SCM) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{&fEM_A4UP02RIM,8,320},	//( - , SCM) Нижняя граница давления на подъём НИ
	{&iEM_TERR7SI74RIM,3,412},	//( - , SCM) Искажение: Радиация в реакторном зале
	{&fEM_B1MC01RSP,8,525},	//( - , SCM) Стартовая координата  ББ2
	{&iEM_TERA3SP02RIM,3,404},	//( - , SCM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{&iEM_TERR6IS67LIM,3,407},	//( - , SCM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{&fEM_R0UT01RIM,8,14},	//( - , SCM) Температурный коэффициент (долл)
	{&fEM_R0UV85RDU,8,142},	//( - , SCM) 6-я скорость перемещения ББ (шагов/секунду)
	{&fEM_A1UP82RIM,8,268},	//( - , SCM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{&iEM_TERMDZ2,3,484},	//( - , SCM) Неисправности МДЗ2
	{&fEM_A1MC01RSP,8,521},	//( - , SCM) Стартовая координата  ББ1
	{&fEM_R0UT02RIM,8,16},	//( - , SCM) Масса топлива в АЗ
	{&fEM_A8UC10RIM,8,68},	//( - , SCM) Координата нижних механических упоров ДС2 мм
	{&fEM_R7UX09RSS,8,170},	//( - , SCM) X-координата камеры R7IN33 (см)
	{&fEM_R5UL10RIM,8,306},	//( - , SCM) Время полного хода ворот отстойной зоны (дес. мс)
	{&iEM_TERB8SC01RIM,3,443},	//( - , SCM) Искажение: Координата АЗ2
	{&iEM_TERB1SS21LIM,3,457},	//( - , SCM) Искажение: Приход на НУ ББ2
	{&iEM_TERBZ1,3,474},	//( - , SCM) Неисправности БЗ1
	{&fEM_R7UL01RIM,8,98},	//( - , SCM) Постоянная времени изменения уровня радиации в зале
	{&fEM_B0UX01RSS,8,224},	//( - , SCM) Второй коэффициент калибровки камеры 1
	{&fEM_A3UC08RIM,8,508},	//( - , SCM) Зона срабатывания КВ ИС(мм)
	{&fEM_A9MC01RSP,8,571},	//( - , SCM) Стартовая координата НИ ДС1
	{&iEM_TERBB1,3,326},	//( - , SCM) Неисправности  ББ1
	{&iEM_TERR3SS21LIM,3,422},	//( - , SCM) Искажение: Приход на НУ гомогенных дверей-1
	{&fEM_A0UX08RSS,8,214},	//( - , SCM) Первый коэффициент калибровки камеры 8
	{&iEM_TERA8SC01RIM,3,444},	//( - , SCM) Искажение: Координата ДС2
	{&fEM_A8US80RDU,8,280},	//( - , SCM) Тормозной путь ДС2 (мм)
	{&fEM_R4MV01RC1,8,464},	//( - , SCM) Заданная скорость тележки от ИС
	{&fEM_B1MC02RSP,8,527},	//( - , SCM) Стартовая координата штока ББ2
	{&fEM_A0UX13RSS,8,601},	//( - , SCM) Первый коэффициент калибровки камеры 13
	{&fEM_R7UY05RSS,8,178},	//( - , SCM) Y-координата камеры R7IN22 (см)
	{&fEM_A2MV02RC1,8,344},	//( - , SCM) Заданная скорость движения штока РБ1 от ИС
	{&R0MW11IP1,3,0},	//( - , SCM) Переключатель ВЫСТРЕЛ
	{&fEM_R0UT05RIM,8,22},	//( - , SCM) Энергия деления ядра
	{&fEM_A2UP03RDU,8,116},	//( - , SCM) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{&fEM_R7UX08RSS,8,168},	//( - , SCM) X-координата камеры R7IN32 (см)
	{&iEM_TERA6VS12LIM,3,587},	//( - , SCM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{&fEM_A0UX14RSS,8,603},	//( - , SCM) Первый коэффициент калибровки камеры 14
	{&fEM_B0UX12RSS,8,246},	//( - , SCM) Второй коэффициент калибровки камеры 12
	{&fEM_A1UR01RIM,8,6},	//( - , SCM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{&fEM_A2UC04RIM,8,38},	//( - , SCM) Координата промежуточного путевого выключателя РБ мм
	{&iEM_TERA0MT01RIM,3,384},	//( - , SCM) Искажение: Текущая температура AЗ1
	{&fEM_B6MV01RC1,8,482},	//( - , SCM) Заданная скорость БЗ2 от ИС
	{&iEM_TERA7MS31LIM,3,584},	//( - , SCM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{&iEM_TERR2SS21LIM,3,428},	//( - , SCM) Искажение: Приход на НУ МДЗ2
	{&fEM_R7UY09RSS,8,186},	//( - , SCM) Y-координата камеры R7IN33 (см)
	{&fEM_R7UI76RIM,8,322},	//( - , SCM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{&iEM_TERA3SS33LIM,3,394},	//( - , SCM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{&iEM_TERR6IS64LIM,3,401},	//( - , SCM) Искажение: Исправность ВИП ССДИ-35
	{&iEM_TERR3SS11LIM,3,420},	//( - , SCM) Искажение: Приход на ВУ гомогенных дверей-1
	{&iEM_TERR4VS12LDU,3,599},	//( - , SCM) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{&fEM_R0UH03RSS,8,250},	//( - , SCM) Коэфф. преобразования частота->нейтр/с  КНК53М
	{&fEM_A1UV02RIM,8,272},	//( - , SCM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{&fEM_R7UC10RIM,8,92},	//( - , SCM) X-координата КНК53М R7IN13 см
	{&fEM_A0UX06RSS,8,210},	//( - , SCM) Первый коэффициент калибровки камеры 6
	{&fEM_R0UH22RSS,8,294},	//( - , SCM) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{&fEM_B1MC02RC1,8,332},	//( - , SCM) Заданная координата штока ББ2 от ИС
	{&iEM_TERRB2,3,336},	//( - , SCM) Неисправности  РБ2
	{&iEM_TERA1IE04LDU,3,356},	//( - , SCM) Искажение Движение ББ1 назад (от БУШД)
	{&fEM_A8UC20RIM,8,72},	//( - , SCM) Координата верхних механических упоров ДС2 мм
	{&fEM_A2UC03RDU,8,120},	//( - , SCM) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{&fEM_R0UV83RDU,8,138},	//( - , SCM) 4-я частота двигателя (шагов/секунду)
	{&iEM_TERA4SS21LIM,3,434},	//( - , SCM) Искажение: Приход на НУ НИ1
	{&iEM_TERB6SS11LIM,3,437},	//( - , SCM) Искажение: Приход на ВУ БЗ2
	{&fEM_A0UX00RSS,8,154},	//( - , SCM) Эффективный радиус АЗ
	{&fEM_A0UX15RSS,8,605},	//( - , SCM) Первый коэффициент калибровки камеры 15
	{&fEM_R2MV01RC1,8,487},	//( - , SCM) Заданная скорость МДЗ2 от ИС
	{&iEM_TERR2VS22LIM,3,598},	//( - , SCM) Искажение: Движение МДЗ2 в сторону НУ
	{&fEM_A3UR01RIM,8,12},	//( - , SCM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{&iEM_TERB3SC01RIM,3,398},	//( - , SCM) Искажение: Координата штока ИС2
	{&iEM_TERB5SS21LIM,3,452},	//( - , SCM) Искажение: Приход на НУ НЛ2
	{&fEM_A2MC02RSP,8,535},	//( - , SCM) Стартовая координата штока РБ1
	{&fEM_R7UX13RSS,8,607},	//( - , SCM) X-координата камеры R7IN51
	{&fEM_A1UC05RIM,8,30},	//( - , SCM) Координата переднего аварийного выключателя ББ мм
	{&fEM_R7UY08RSS,8,184},	//( - , SCM) Y-координата камеры R7IN32 (см)
	{&fEM_A3MC02RC1,8,352},	//( - , SCM) Заданная координата штока ИС1 от ИС
	{&fEM_A0UN07RIM,8,623},	//( - , SCM) Доля запаздывающих нейтронов
	{&fEM_A3UP03RDU,8,122},	//( - , SCM) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{&iEM_TERB2SS33LIM,3,510},	//( - , SCM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{&fEM_A2MC01RC1,8,529},	//( - , SCM) Заданная координата РБ1 от ИС
	{&fEM_R4UC22RIM,8,84},	//( - , SCM) Смещение координаты АЗ от координаты тележки
	{&fEM_R0UV81RDU,8,134},	//( - , SCM) 1-я частота двигателя (шагов/секунду)
	{&fEM_A0UX07RSS,8,212},	//( - , SCM) Первый коэффициент калибровки камеры 7
	{&iEM_TERR0VP81LIM,3,410},	//( - , SCM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{&fEM_R7UY01RSS,8,172},	//( - , SCM) Y-координата камеры R7IN11
	{&fEM_B0UX10RSS,8,242},	//( - , SCM) Второй коэффициент калибровки камеры 10
	{&iEM_TERR5SS21LIM,3,431},	//( - , SCM) Искажение: Приход на НУ ворот отстойной зоны
	{&fEM_R4MC01RSP,8,579},	//( - , SCM) Стартовая координата тележки
	{&fEM_R4UV80RDU,8,50},	//( - , SCM) Номинальная скорость тележки (см/с)
	{&fEM_R0UV84RDU,8,140},	//( - , SCM) 5-я частота двигателя (шагов/секунду)
	{&iEM_TERB0MT01RIM,3,385},	//( - , SCM) Искажение: Текущая температура AЗ2
	{&fEM_A0UR01RSP,8,515},	//( - , SCM) Стартовая  реактивность АЗ1
	{&fEM_B5MC01RSP,8,569},	//( - , SCM) Стартовая координата НЛ2
	{&fEM_R7UY15RSS,8,617},	//( - , SCM) Y-координата камеры R7IN53
	{&fEM_B2MC02RC1,8,337},	//( - , SCM) Заданная координата штока РБ2 от ИС
	{&fEM_B1MV01RC1,8,364},	//( - , SCM) Заданная скорость движения ББ2 от ИС
	{&iEM_TERA3SS31LIM,3,395},	//( - , SCM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{&fEM_R1MC01RSP,8,565},	//( - , SCM) Стартовая координата МДЗ1
	{&iEM_TERA3SC01RIM,3,389},	//( - , SCM) Искажение: Координата штока ИС1
	{&iEM_TERA4SS11LIM,3,424},	//( - , SCM) Искажение: Приход на ВУ НИ1
	{&fEM_A3MC01RSP,8,541},	//( - , SCM) Стартовая координата  ИС1
	{&fEM_B3MV02RC1,8,349},	//( - , SCM) Заданная скорость движения штока ИС2 от ИС
	{&iEM_TERA2SC01RIM,3,391},	//( - , SCM) Искажение: Координата штока РБ1
	{&iEM_TERB2SC01RIM,3,421},	//( - , SCM) Искажение: Координата штока РБ2
	{&iEM_TERA4VP82LIM,3,429},	//( - , SCM) Искажение Давление ПОДЪЁМ НИ в норме
	{&fEM_A8MV01RC1,8,472},	//( - , SCM) Заданная скорость ДС2 от ИС
	{&iEM_TERR2VS12LIM,3,597},	//( - , SCM) Искажение: Движение МДЗ2 в сторону ВУ
	{&iEM_TERB1IE03LDU,3,360},	//( - , SCM) Искажение Движение ББ2 вперёд (от БУШД)
	{&iEM_TERA8SS22LIM,3,448},	//( - , SCM) Искажение: Приход на механический НУ ДС2
	{&fEM_A1MV01RC1,8,581},	//( - , SCM) Заданная скорость движения  ББ1 от ИС
	{&iEM_TERR1VS12LIM,3,595},	//( - , SCM) Искажение: Движение МДЗ1 в сторону ВУ
	{&fEM_R7UX07RSS,8,166},	//( - , SCM) X-координата камеры R7IN31 (см)
	{&fEM_A2UP01RIM,8,262},	//( - , SCM) Текущее давление на сброс РБ
	{&fEM_A2UV02RIM,8,276},	//( - , SCM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{&iEM_TERR4SS22LIM,3,441},	//( - , SCM) Искажение: Приход на механический НУ тележки
	{&fEM_R7UI02RIM,8,96},	//( - , SCM) Коэффициент усиления уровня радиации
	{&fEM_A0UX03RSS,8,204},	//( - , SCM) Первый коэффициент калибровки камеры 3
	{&iEM_TERR6IS62LIM,3,405},	//( - , SCM) Искажение Исправность ВИП ССДИ-39
	{&fEM_A0UN01RIM,8,82},	//( - , SCM) Мощность источника нейтронов ИНИ
	{&iEM_TERA3SS11LIM,3,399},	//( - , SCM) Искажение: Приход на ВУ ИС1
	{&iEM_TERMDZ1,3,489},	//( - , SCM) Неисправности МДЗ1
	{&fEM_A8UC03RDU,8,130},	//( - , SCM) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{&fEM_R0UT01RDU,8,112},	//( - , SCM) Нижний предел шкалы датчика температуры
	{&iEM_TERIS2,3,346},	//( - , SCM) Неисправности  ИС2
	{&fEM_R0UN02RIM,8,4},	//( - , SCM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{&fEM_R0UT06RIM,8,24},	//( - , SCM) Конвекционное сопротивление при обдуве
	{&fEM_R0UT02RDU,8,110},	//( - , SCM) Верхний предел шкалы датчика температуры
	{&iEM_TERR4MS21LIM,3,439},	//( - , SCM) Искажение: Приход на НУ тележки
	{&iEM_TERIS1,3,351},	//( - , SCM) Неисправности  ИС1
	{&iEM_TERB6SS21LIM,3,432},	//( - , SCM) Искажение: Приход на НУ БЗ2
	{&iEM_TERR4SS11LIM,3,438},	//( - , SCM) Искажение: Приход на ВУ тележки
	{&iEM_TERB2SS11LIM,3,417},	//( - , SCM) Искажение: Приход на ВУ РБ2
	{&iEM_TERNL1,3,494},	//( - , SCM) Неисправности НЛ1
	{&fEM_A1UC08RIM,8,504},	//( - , SCM) Зона срабатывания КВ ББ(мм)
	{&fEM_R7UY02RSS,8,174},	//( - , SCM) Y-координата камеры R7IN12 (см)
	{&iEM_TERR8SS11LIM,3,442},	//( - , SCM) Искажение: Аварийный НИ установлен
	{&fEM_B3MC02RSP,8,547},	//( - , SCM) Стартовая координата штока ИС2
	{&iEM_TERA1VP81LIM,3,511},	//( - , SCM) Искажение: Текущее давление СБРОС ББ1  в норме
	{&fEM_B8MV01RC1,8,467},	//( - , SCM) Заданная скорость АЗ2 от ИС
	{&fEM_R0UL01RIM,8,2},	//( - , SCM) Среднее время генерации нейтронов
	{&fEM_B0UX02RSS,8,226},	//( - , SCM) Второй коэффициент калибровки камеры 2
	{&fEM_A2UR00RIM,8,100},	//( - , SCM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{&fEM_A1UC03RDU,8,114},	//( - , SCM) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{&fEM_A3US07RDU,8,288},	//( - , SCM) Постоянная времени масляного демпфера ИС
	{&fEM_R7UY13RSS,8,613},	//( - , SCM) Y-координата камеры R7IN51
	{&fEM_B8MC01RC1,8,621},	//( - , SCM) Заданная координата АЗ2 от ИС
	{&fEM_A9UL10RIM,8,302},	//( - , SCM) Время полного перемещения НИ ДС1/ДС2 сек
	{&iEM_TERA2SS21LIM,3,378},	//( - , SCM) Искажение: Приход на НУ РБ1
	{&iEM_TERR6IS68LIM,3,411},	//( - , SCM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{&iEM_TERB9SS11LIM,3,451},	//( - , SCM) Искажение: Приход на ВУ НИ ДС2
	{&iEM_TERMAZ2,3,466},	//( - , SCM) Неисправности АЗ2 от ИС
	{&fEM_A3MC02RSP,8,543},	//( - , SCM) Стартовая координата штока ИС1
	{&fEM_R7UX12RSS,8,192},	//( - , SCM) X-координата камеры R7IN43
	{&fEM_A2MC02RC1,8,342},	//( - , SCM) Заданная координата штока РБ1 от ИС
	{&fEM_B2MV01RC1,8,368},	//( - , SCM) Заданная скорость движения  РБ2 от ИС
	{&fEM_R4MC01RC1,8,462},	//( - , SCM) Заданная координата тележки от ИС
	{&fEM_B8UC20RIM,8,58},	//( - , SCM) Координата верхних механических упоров АЗ2 мм
	{&iEM_TERA5VS12LIM,3,592},	//( - , SCM) Искажение: Движение створок НЛ1 к ВУ
	{&fEM_R0UV82RDU,8,136},	//( - , SCM) 3-я частота двигателя (шагов/секунду)
	{&fEM_A0UX12RSS,8,222},	//( - , SCM) Первый коэффициент калибровки камеры 12
	{&fEM_A3UP01RIM,8,266},	//( - , SCM) Текущее давление на СПУСК ИС
	{&iEM_TERB8SS12LIM,3,445},	//( - , SCM) Искажение: Приход на механический ВУ АЗ2
	{&fEM_B8UC11RIM,8,60},	//( - , SCM) Координата нижнего путевого выключателя АЗ2 мм
	{&iEM_TERB5VS22LIM,3,594},	//( - , SCM) Искажение: Движение створок НЛ2 к НУ
	{&fEM_R7UX14RSS,8,609},	//( - , SCM) X-координата камеры R7IN52
	{&fEM_B9MC01RSP,8,573},	//( - , SCM) Стартовая координата НИ ДС2
	{&fEM_B1MV02RC1,8,334},	//( - , SCM) Заданная скорость движения штока ББ2 от ИС
	{&iEM_TERB3SS22LIM,3,402},	//( - , SCM) Искажение: Приход на НУП ИС2
	{&fEM_A5MC01RSP,8,567},	//( - , SCM) Стартовая координата НЛ1
	{&iEM_TERR4SS12LIM,3,440},	//( - , SCM) Искажение: Приход на механический ВУ тележки
	{&fEM_A8UC11RIM,8,70},	//( - , SCM) Координата нижнего путевого выключателя ДС2 мм
	{&fEM_B3MV01RC1,8,376},	//( - , SCM) Заданная скорость движения ИС2 от ИС
	{&iEM_TERA3SS21LIM,3,393},	//( - , SCM) Искажение: Приход на НУ ИС1
	{&fEM_A6UC10RIM,8,76},	//( - , SCM) Время полного хода БЗ (сек)
	{&fEM_A0UX09RSS,8,216},	//( - , SCM) Первый коэффициент калибровки камеры 9
	{&fEM_R4US80RDU,8,252},	//( - , SCM) Тормозной путь тележки (мм)
	{&fEM_A2UP03RIM,8,312},	//( - , SCM) Нижняя граница давления на ПОДЪЁМ РБ
	{&iEM_TERA5VS22LIM,3,591},	//( - , SCM) Искажение: Движение створок НЛ1 к НУ
	{&fEM_A3UP02RDU,8,270},	//( - , SCM) Текущее давление ВЫСТРЕЛ ИС
	{&iEM_TERDS2,3,469},	//( - , SCM) Неисправности ДС2 от ИС
	{&fEM_R7UX11RSS,8,190},	//( - , SCM) X-координата камеры R7IN42
	{&fEM_A1US07RDU,8,284},	//( - , SCM) Постоянная времени масляного демпфера ББ
	{&iEM_TERB2SP01RIM,3,387},	//( - , SCM) Искажение: Текущее давление СБРОС РБ2
	{&fEM_R7UI73RIM,8,258},	//( - , SCM) Уровень мощности срабатывания АС II УР  ватт
	{&iEM_TERA3SS22LIM,3,403},	//( - , SCM) Искажение: Приход на НУП ИС1
	{&iEM_TERB1SS12LIM,3,460},	//( - , SCM) Искажение: Магнит ББ2 зацеплен
	{&fEM_B5MC01RC1,8,500},	//( - , SCM) Заданная координата НЛ2 от ИС
	{&iEM_TERB1MC01RIM,3,459},	//( - , SCM) Искажение: Координата штока ББ2
	{&fEM_B3MC01RC1,8,374},	//( - , SCM) Заданная координата ИС2 от ИС
	{&iEM_TERA2SS33LIM,3,392},	//( - , SCM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{&fEM_A2MC01RSP,8,533},	//( - , SCM) Стартовая координата  РБ1
	{&fEM_R7UX04RSS,8,160},	//( - , SCM) X-координата камеры R7IN21 (см)
	{&fEM_A0UX05RSS,8,208},	//( - , SCM) Первый коэффициент калибровки камеры 5
	{&iEM_TERA1IE03LDU,3,357},	//( - , SCM) Искажение Движение ББ1 вперёд (от БУШД)
	{&iEM_TERB5VS12LIM,3,593},	//( - , SCM) Искажение: Движение створок НЛ2 к ВУ
	{&fEM_A1UC02RDU,8,26},	//( - , SCM) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{&fEM_A3MV02RC1,8,354},	//( - , SCM) Заданная скорость движения штока ИС1 от ИС
	{&fEM_A0UT03RSP,8,513},	//( - , SCM) Стартовая  температура АЗ1 град
	{&fEM_A2UC08RIM,8,506},	//( - , SCM) Зона срабатывания КВ  РБ мм
	{&fEM_R7UY11RSS,8,196},	//( - , SCM) Y-координата камеры R7IN42
	{&iEM_TERR5SS11LIM,3,423},	//( - , SCM) Искажение: Приход на ВУ ворот отстойной зоны
	{&fEM_B5MV01RC1,8,502},	//( - , SCM) Заданная скорость НЛ2 от ИС
	{&fEM_R7UY10RSS,8,194},	//( - , SCM) Y-координата камеры R7IN41
	{&fEM_R7UI72RIM,8,256},	//( - , SCM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{&fEM_A0UR02RSP,8,517},	//( - , SCM) Стартовый  поток нейтронов АЗ1
	{&fEM_R0UL04RIM,8,629},	//( - , SCM) Время блокировки повторной генерации импульса
	{&fEM_R0UR30RIM,8,106},	//( - , SCM) Реактивность вносимая образцами (долл)
	{&fEM_A5MV01RC1,8,497},	//( - , SCM) Заданная скорость НЛ1 от ИС
	{&fEM_R7UX05RSS,8,162},	//( - , SCM) X-координата камеры R7IN22 (см)
	{&iEM_TERB3SP02RIM,3,388},	//( - , SCM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{&fEM_A8UC08RDU,8,146},	//( - , SCM) Зона срабатывания КВ ДС2(мм)
	{&fEM_A2UC05RIM,8,36},	//( - , SCM) Координата переднего аварийного выключателя РБ мм
	{&fEM_B2MV02RC1,8,339},	//( - , SCM) Заданная скорость движения штока РБ2 от ИС
	{&iEM_TERRB1,3,341},	//( - , SCM) Неисправности  РБ1
	{&iEM_TERR2SS11LIM,3,427},	//( - , SCM) Искажение: Приход на ВУ МДЗ2
	{&fEM_A3UC03RDU,8,126},	//( - , SCM) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{&iEM_TERB1IE04LDU,3,361},	//( - , SCM) Искажение Движение ББ2 назад (от БУШД)
	{&fEM_A6MV01RC1,8,477},	//( - , SCM) Заданная скорость БЗ1 от ИС
	{&fEM_R7UC19RIM,8,94},	//( - , SCM) Y-координата СНМ-11 (11) см
	{&fEM_A1UC04RIM,8,28},	//( - , SCM) Координата промежуточного путевого выключателя ББ мм
	{&fEM_A0UP02RIM,8,264},	//( - , SCM) Текущее давление в АЗ1,2
	{&fEM_R6UL10RIM,8,308},	//( - , SCM) Время полного хода кран-балки сек
	{&fEM_A5MC01RC1,8,495},	//( - , SCM) Заданная координата НЛ1 от ИС
	{&iEM_TERB7MS31LIM,3,583},	//( - , SCM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{&fEM_R6UC01RSP,8,561},	//( - , SCM) Стартовая координата Кран-балки
	{&fEM_R1UC10RIM,8,78},	//( - , SCM) Время полного хода МДЗ сек
	{&iEM_TERA2SP01RIM,3,386},	//( - , SCM) Искажение: Текущее давление СБРОС РБ1
	{&iEM_TERB6VS12LIM,3,589},	//( - , SCM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{&iEM_TERB0VP81LIM,3,409},	//( - , SCM) Искажение: Давление  АЗ2 в норме
	{&fEM_A1UG01RDU,8,86},	//( - , SCM) Расстояние включения масляного демпфера ББ(мм)
	{&fEM_R7UY12RSS,8,198},	//( - , SCM) Y-координата камеры R7IN43
	{&fEM_A0UX01RSS,8,200},	//( - , SCM) Первый коэффициент калибровки камеры 1
	{&fEM_A1MC01RC1,8,358},	//( - , SCM) Заданная координата  ББ1 от ИС
	{&fEM_A3MC01RC1,8,370},	//( - , SCM) Заданная координата ИС1 от ИС
	{&fEM_R0UR01RIM,8,108},	//( - , SCM) Стартовая отрицательная реактивность
	{&iEM_TERA1SC01RIM,3,455},	//( - , SCM) Искажение: Координата штока ББ1
	{&fEM_R7UX01RSS,8,156},	//( - , SCM) X-координата камеры R7IN11
	{&fEM_R7UX10RSS,8,188},	//( - , SCM) X-координата камеры R7IN41
	{&fEM_A0UX11RSS,8,220},	//( - , SCM) Первый коэффициент калибровки камеры 11
	{&iEM_TERA2SS12LIM,3,379},	//( - , SCM) Искажение: Магнит РБ1 зацеплен
	{&fEM_R7UX02RSS,8,158},	//( - , SCM) X-координата камеры R7IN12 (см)
	{&fEM_B0UX09RSS,8,240},	//( - , SCM) Второй коэффициент калибровки камеры 9
	{&iEM_TERR6IS66LIM,3,406},	//( - , SCM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{&fEM_B2MC01RSP,8,537},	//( - , SCM) Стартовая координата  РБ2
	{&fEM_R7UY07RSS,8,182},	//( - , SCM) Y-координата камеры R7IN31 (см)
	{&fEM_B0UX07RSS,8,236},	//( - , SCM) Второй коэффициент калибровки камеры 7
	{&fEM_B4MC01RSP,8,577},	//( - , SCM) Стартовая координата НИ2
	{&fEM_R7UY00RSS,8,585},	//( - , SCM) Y-координата АЗ1 см
	{&fEM_B8UC10RIM,8,62},	//( - , SCM) Координата нижних механических упоров АЗ2 мм
	{&fEM_A0UX02RSS,8,202},	//( - , SCM) Первый коэффициент калибровки камеры 2
	{&fEM_B8US80RDU,8,278},	//( - , SCM) Тормозной путь АЗ2 (мм)
	{&fEM_A0UP01RIM,8,314},	//( - , SCM) Текущее давление в АЗ1,2
	{&iEM_TERA3VP81LIM,3,390},	//( - , SCM) Искажение: Текущее давление СПУСК ИС  в норме
	{&fEM_A2UC06RIM,8,34},	//( - , SCM) Координата заднего аварийного выключателя РБ мм
	{&fEM_R7UY04RSS,8,176},	//( - , SCM) Y-координата камеры R7IN21 (см)
	{&fEM_B0UT03RSP,8,519},	//( - , SCM) Стартовая  температура АЗ2 град
	{&fEM_B2MC02RSP,8,539},	//( - , SCM) Стартовая координата штока РБ2
	{&fEM_A3UG01RDU,8,90},	//( - , SCM) Расстояние включения масляного демпфера ИС
	{&iEM_TERA9SS11LIM,3,416},	//( - , SCM) Искажение: Приход на ВУ НИ ДС1
	{&fEM_R0UL02RDU,8,627},	//( - , SCM) Время задержки  ИНИ
	{&fEM_A3UC05RIM,8,44},	//( - , SCM) Координата переднего аварийного выключателя ИС мм
	{&fEM_B0UX08RSS,8,238},	//( - , SCM) Второй коэффициент калибровки камеры 8
	{&fEM_A6MC01RC1,8,475},	//( - , SCM) Заданная координата БЗ1 от ИС
	{&iEM_TERB6VS22LIM,3,590},	//( - , SCM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{&iEM_TERR1SS21LIM,3,426},	//( - , SCM) Искажение: Приход на НУ МДЗ1
	{&iEM_TERB9SS21LIM,3,450},	//( - , SCM) Искажение: Приход на НУ НИ ДС2
	{&fEM_A5UC10RIM,8,80},	//( - , SCM) Время полного хода НЛ сек
	{&fEM_R7UI71RIM,8,254},	//( - , SCM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{&iEM_TERB2SS12LIM,3,418},	//( - , SCM) Искажение: Магнит РБ2 зацеплен
	{&fEM_R0UH01RSS,8,152},	//( - , SCM) Коэфф. преобразования частота->нейтр/с  СНМ11
	{&iEM_TERB5SS11LIM,3,414},	//( - , SCM) Искажение: Приход на ВУ НЛ2
	{&iEM_TERB8SS22LIM,3,447},	//( - , SCM) Искажение: Приход на механический НУ АЗ2
	{&iEM_TERA9SS21LIM,3,449},	//( - , SCM) Искажение: Приход на НУ НИ ДС1
	{&R0DEUMLSS,3,1},	//( - , SCM) Сигнал управления моделью
	{&iEM_TERA6SS21LIM,3,436},	//( - , SCM) Искажение: Приход на НУ БЗ1
	{&fEM_R3UC01RSP,8,557},	//( - , SCM) Стартовая координата Гомогенных дверей
	{&fEM_A6US80RDU,8,282},	//( - , SCM) Тормозной путь БЗ (мм)
	{&fEM_R0UH23RSS,8,296},	//( - , SCM) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{&iEM_TERB3SS11LIM,3,400},	//( - , SCM) Искажение: Приход на ВУ ИС2
	{&iEM_TERB1VP81LIM,3,512},	//( - , SCM) Искажение: Текущее давление СБРОС ББ2  в норме
	{&fEM_A3UR00RIM,8,10},	//( - , SCM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{&fEM_A2MV01RC1,8,531},	//( - , SCM) Заданная скорость движения РБ1 от ИС
	{&fEM_R5UC01RSP,8,559},	//( - , SCM) Стартовая координата Ворот отстойной зоны
	{&fEM_A2UG01RDU,8,88},	//( - , SCM) Расстояние включения масляного демпфера РБ
	{&fEM_R3UL10RIM,8,304},	//( - , SCM) Время полного хода гомогенных дверей (сек)
	{&fEM_B8UC21RIM,8,56},	//( - , SCM) Координата верхнего путевого выключателя АЗ2 мм
	{&fEM_A3UV02RIM,8,274},	//( - , SCM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{&fEM_A0UX10RSS,8,218},	//( - , SCM) Первый коэффициент калибровки камеры 10
	{&fEM_A2US07RDU,8,286},	//( - , SCM) Постоянная времени масляного демпфера РБ
	{&iEM_TERA5SS21LIM,3,413},	//( - , SCM) Искажение: Приход на НУ НЛ1
	{&fEM_B6MC01RC1,8,480},	//( - , SCM) Заданная координата БЗ2 от ИС
	{&fEM_A8UV80RDU,8,66},	//( - , SCM) Номинальная скорость ДС2 (мм/с)
	{&fEM_B8UC08RDU,8,148},	//( - , SCM) Зона срабатывания КВ АЗ2(мм)
	{&fEM_A1MC02RSP,8,523},	//( - , SCM) Стартовая координата штока ББ1
	{&fEM_A6MC01RSP,8,553},	//( - , SCM) Стартовая координата БЗ1
	{&fEM_A4UL10RIM,8,300},	//( - , SCM) Время полного перемещения НИ сек
	{&iEM_TERBB2,3,331},	//( - , SCM) Неисправности  ББ2
	{&iEM_TERB4SS21LIM,3,430},	//( - , SCM) Искажение: Приход на НУ НИ2
	{&iEM_TERB4SS11LIM,3,433},	//( - , SCM) Искажение: Приход на ВУ НИ2
	{&fEM_R0UT03RIM,8,20},	//( - , SCM) Нормальная температура АЗ град
	{&fEM_R7UY06RSS,8,180},	//( - , SCM) Y-координата камеры R7IN23 (см)
	{&fEM_A0UX04RSS,8,206},	//( - , SCM) Первый коэффициент калибровки камеры4
	{&iEM_TERB3SS21LIM,3,383},	//( - , SCM) Искажение: Приход на НУ ИС2
	{&iEM_TERTLG,3,461},	//( - , SCM) Неисправности  тележки от ИС
	{&iEM_TERR1VS22LIM,3,596},	//( - , SCM) Искажение: Движение МДЗ1 в сторону НУ
	{&fEM_R4UC08RDU,8,150},	//( - , SCM) Зона срабатывания КВ тележки РУ(мм)
	{&fEM_R7UX06RSS,8,164},	//( - , SCM) X-координата камеры R7IN23 (см)
	{&iEM_TERA2VP82LIM,3,381},	//( - , SCM) Искажение: Текущее давление на подъём РБ  в норме
	{&fEM_R1MC01RC1,8,490},	//( - , SCM) Заданная координата МДЗ1 от ИС
	{&fEM_R4UC10RIM,8,52},	//( - , SCM) Координата верхних механических упоров тележки мм
	{&fEM_A1UP01RIM,8,260},	//( - , SCM) Текущее давление на сброс ББ (МПа)
	{&fEM_R0UH05RSS,8,298},	//( - , SCM) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_R0UL02RIM,8,625},	//( - , SCM) Время удержания синхроимпульса
	{&fEM_B0UX11RSS,8,244},	//( - , SCM) Второй коэффициент калибровки камеры 11
	{&fEM_A2UP02RIM,8,310},	//( - , SCM) Текущее давление на подъём РБ
	{&iEM_TERR4VS22LDU,3,600},	//( - , SCM) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{&fEM_B0UX06RSS,8,234},	//( - , SCM) Второй коэффициент калибровки камеры 6
	{&fEM_A3UP02RIM,8,316},	//( - , SCM) Нижняя граница  давления на СПУСК ИС
	{&fEM_A1MV02RC1,8,329},	//( - , SCM) Заданная скорость движения  штока ББ1 от ИС
	{&fEM_B3MC02RC1,8,347},	//( - , SCM) Заданная координата штока ИС2 от ИС
	{&fEM_B8UV80RDU,8,64},	//( - , SCM) Номинальная скорость АЗ2 (мм/с)
	{&fEM_B0UX05RSS,8,232},	//( - , SCM) Второй коэффициент калибровки камеры 5
	{&iEM_TERB3SS33LIM,3,397},	//( - , SCM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{&iEM_TERA5SS11LIM,3,415},	//( - , SCM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{&fEM_A8MC01RSP,8,551},	//( - , SCM) Стартовая координата ДС2
	{&fEM_R7UX16RSS,8,619},	//( - , SCM) Величина сигнала СНМ11 в БЗ
	{&fEM_R0UV86RDU,8,144},	//( - , SCM) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R7UI77RIM,8,324},	//( - , SCM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{&fEM_B2MC01RC1,8,366},	//( - , SCM) Заданная координата РБ2 от ИС
	{&fEM_A8MC01RC1,8,470},	//( - , SCM) Заданная координата ДС2 от ИС
	{&fEM_B3MC01RSP,8,545},	//( - , SCM) Стартовая координата  ИС2
	{&fEM_A3UP04RDU,8,124},	//( - , SCM) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{&iEM_TERR6SS21LIM,3,380},	//( - , SCM) Искажение: Кран-балка в нерабочем положении
	{&iEM_TERA6MS11LIM,3,435},	//( - , SCM) Искажение: Приход на ВУ БЗ1
	{&fEM_A8UC21RIM,8,74},	//( - , SCM) Координата верхнего путевого выключателя ДС2 мм
	{&fEM_R2MC01RSP,8,563},	//( - , SCM) Стартовая координата МДЗ2
	{&iEM_TERA6VS22LIM,3,588},	//( - , SCM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{&fEM_A1UR00RIM,8,8},	//( - , SCM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{&iEM_TERBZ2,3,479},	//( - , SCM) Неисправности БЗ2
	{&fEM_B8MC01RSP,8,549},	//( - , SCM) Стартовая координата АЗ2
	{&fEM_B0UX04RSS,8,230},	//( - , SCM) Второй коэффициент калибровки камеры 4
	{&iEM_TERA1SS21LIM,3,453},	//( - , SCM) Искажение: Приход на НУ ББ1
	{&fEM_B6MC01RSP,8,555},	//( - , SCM) Стартовая координата БЗ2
	{&fEM_R4UC20RIM,8,54},	//( - , SCM) Координата нижних механических упоров тележки мм
	{&fEM_R0UH21RSS,8,292},	//( - , SCM) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{&fEM_B1MC01RC1,8,362},	//( - , SCM) Заданная координата ББ2 от ИС
	{&fEM_R0UT04RIM,8,18},	//( - , SCM) Удельная теплоёмкость топлива
	{&fEM_A1MC02RC1,8,327},	//( - , SCM) Заданная координата штока ББ1 от ИС
	{&iEM_TERA0VP81LIM,3,408},	//( - , SCM) Искажение: Давление  АЗ1  в норме
	{&fEM_A4UP01RIM,8,318},	//( - , SCM) Текущее давление на подъём НИ
	{&iEM_TERA8SS12LIM,3,446},	//( - , SCM) Искажение: Приход на механический ВУ ДС2
	{&fEM_R7UY14RSS,8,615},	//( - , SCM) Y-координата камеры R7IN52
	{&fEM_A1UC06RIM,8,32},	//( - , SCM) Координата заднего аварийного выключателя ББ мм
	{&fEM_A3UC06RIM,8,42},	//( - , SCM) Координата заднего аварийного выключателя ИС мм
	{&fEM_A2UR01RIM,8,102},	//( - , SCM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{&fEM_A4MC01RSP,8,575},	//( - , SCM) Стартовая координата НИ1
	{&fEM_A3MV01RC1,8,372},	//( - , SCM) Заданная скорость движения ИС1 от ИС
	{&iEM_TERB1SS11LIM,3,458},	//( - , SCM) Искажение:Приход на ВУ ББ2
	{&iEM_TERA1SS12LIM,3,456},	//( - , SCM) Искажение: Магнит ББ1 зацеплен
	{&fEM_A3UC04RIM,8,46},	//( - , SCM) Координата промежуточного путевого выключателя ИС мм
	{&fEM_R7UI74RIM,8,128},	//( - , SCM) Верхняя граница измерения уровня радиации в зале
	{&iEM_TERA2SS11LIM,3,382},	//( - , SCM) Искажение: Приход на ВУ РБ1
	{&fEM_R2MC01RC1,8,485},	//( - , SCM) Заданная координата МДЗ2 от ИС
	{&fEM_R7UX15RSS,8,611},	//( - , SCM) X-координата камеры R7IN53
	{&fEM_R7UI75RIM,8,290},	//( - , SCM) Множитель к уровню радиации
	{&iEM_TERA1SS11LIM,3,454},	//( - , SCM) Искажение: Приход на ВУ ББ1
	{&iEM_TERNL2,3,499},	//( - , SCM) Неисправности НЛ2
	{&fEM_A3UC02RDU,8,48},	//( - , SCM) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{&iEM_TERB3SS31LIM,3,396},	//( - , SCM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SBz1[]={
	{&R0EE04LZ1,2,3},	//( - , SBz1) Питание  АКНП4  отключить
	{&R0EE01LZ1,2,0},	//( - , SBz1) Питание  АКНП1  отключить
	{&R0EE02LZ1,2,1},	//( - , SBz1) Питание  АКНП  отключить
	{&R0EE03LZ1,2,2},	//( - , SBz1) Питание  АКНП3  отключить
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz1[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SBz1[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SBz1[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SBz2[]={
	{&R0EE01LZ2,2,0},	//( - , SBz2) Питание  АКНП1  отключить
	{&R0EE02LZ2,2,1},	//( - , SBz2) Питание  АКНП  отключить
	{&R0EE03LZ2,2,2},	//( - , SBz2) Питание  АКНП3  отключить
	{&R0EE04LZ2,2,3},	//( - , SBz2) Питание  АКНП4  отключить
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz2[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SBz2[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SBz2[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SDu[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SDu[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SDu[]={
	{&B8IC01UDU,5,8},	//( - , SDu) Координата АЗ2, мм
	{&B2IC01UDU,5,10},	//( - , SDu) Координата штока РБ2
	{&A1IC01UDU,5,12},	//( - , SDu) Координата штока ББ1
	{&B1IC01UDU,5,14},	//( - , SDu) Координата штока ББ2
	{&A2IC01UDU,5,0},	//( - , SDu) Координата штока РБ1
	{&A3IC01UDU,5,2},	//( - , SDu) Координата штока ИС1
	{&B3IC01UDU,5,4},	//( - , SDu) Координата штока ИС2
	{&A8IC01UDU,5,6},	//( - , SDu) Координата ДС2
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SDu[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SA1[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SA1[]={
	{&R0IS01FI0,2,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA1[]={
	{&R0IN01FI1,8,0},	//( - , SA1) Выход СНМ11 Гц от ПТИ
	{&R0IN02FI1,8,2},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI1,8,4},	//( - , SA1) Выход КНК53М Гц от ПТИ
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SA1[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SA2[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SA2[]={
	{&R0IS01FI0,2,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA2[]={
	{&R0IN01FI2,8,0},	//( - , SA2) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI2,8,2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI2,8,4},	//( - , SA2) Выход КНК53М Гц от ПТИ
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SA2[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SA3[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SA3[]={
	{&R0IS01FI0,2,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA3[]={
	{&R0IN01FI3,8,0},	//( - , SA3) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI3,8,2},	//( - , SA3) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI3,8,4},	//( - , SA3) Выход КНК53М Гц от ПТИ
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SA3[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SA4[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SA4[]={
	{&R0IS01FI0,2,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA4[]={
	{&R0IN01FI4,8,0},	//( - , SA4) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI4,8,2},	//( - , SA4) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI4,8,4},	//( - , SA4) Выход КНК53М Гц от ПТИ
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SA4[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SRP[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SRP[]={
	{&R0IS01FI0,2,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SRP[]={
	{&R0IN01RIP,8,0},	//( - , SRP) Выход СНМ-11 Гц от ПТИ
	{&R0IN02RIP,8,2},	//( - , SRP) Выход КНК15- Гц от ПТИ
	{&R0IN03RIP,8,4},	//( - , SRP) Выход КНК53М Гц от ПТИ
	{&R0IN06RIP,8,6},	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
	{&R0IN07RIP,8,8},	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SRP[]={
	{NULL,0,0},
}
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_SCM[0],&di_SCM[0],&di_SCM[0],&hr_SCM[0],NULL,NULL,NULL,0},	//Общий слэйв
	{0,5003,&coil_SBz1[0],&di_SBz1[0],&di_SBz1[0],&hr_SBz1[0],NULL,NULL,NULL,0},	//Cлэйв Baz1
	{0,5004,&coil_SBz2[0],&di_SBz2[0],&di_SBz2[0],&hr_SBz2[0],NULL,NULL,NULL,0},	//Cлэйв Baz2
	{0,5005,&coil_SDu[0],&di_SDu[0],&di_SDu[0],&hr_SDu[0],NULL,NULL,NULL,0},	//Cлэйв DU
	{0,5006,&coil_SA1[0],&di_SA1[0],&di_SA1[0],&hr_SA1[0],NULL,NULL,NULL,0},	//Cлэйв AKNP1
	{0,5007,&coil_SA2[0],&di_SA2[0],&di_SA2[0],&hr_SA2[0],NULL,NULL,NULL,0},	//Cлэйв AKNP2
	{0,5008,&coil_SA3[0],&di_SA3[0],&di_SA3[0],&hr_SA3[0],NULL,NULL,NULL,0},	//Cлэйв AKNP3
	{0,5009,&coil_SA4[0],&di_SA4[0],&di_SA4[0],&hr_SA4[0],NULL,NULL,NULL,0},	//Cлэйв AKNP4
	{0,5010,&coil_SRP[0],&di_SRP[0],&di_SRP[0],&hr_SRP[0],NULL,NULL,NULL,0},	//Cлэйв RPU
	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},
};
#pragma pop
#include <drivers/emul8enc.h>/nstatic char buf_em8enc120[40];	//em8enc120
static em8encpti_inimod ini_em8enc120={0x340,0x4,};
#pragma pack(push,1)
static table_drv table_em8enc120={0,0,&ini_em8enc120,buf_em8enc120,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_em8enc120[]={
	{NULL,0,0},
};
#pragma pop
#include <drivers/vds32_pti.h>/nstatic char buf_VDS32F11[66];	//VDS32F11
static vds32pti_inimod ini_VDS32F11={0,};
#pragma pack(push,1)
static table_drv table_VDS32F11={0,0,&ini_VDS32F11,buf_VDS32F11,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F11[]={
	{(&R0AD16LDU,1,62},
	{(&R8AD21LDU,1,60},
	{(&A2AD32LDU,1,48},
	{(&A2AD21LDU,1,18},
	{(&A2AD31LDU,1,50},
	{(&A1AD32LDU,1,44},
	{(&A2AD01LDU,1,20},
	{(&A2AD02LDU,1,22},
	{(&A2AD03LDU,1,24},
	{(&A2AD04LDU,1,26},
	{(&A2AD05LDU,1,28},
	{(&B2AD11LDU,1,30},
	{(&B2AD21LDU,1,32},
	{(&B2AD01LDU,1,34},
	{(&B2AD02LDU,1,36},
	{(&B2AD03LDU,1,38},
	{(&B2AD04LDU,1,40},
	{(&B2AD05LDU,1,42},
	{(&A1AD05LDU,1,0},
	{(&B1AD11LDU,1,2},
	{(&B1AD21LDU,1,4},
	{(&B1AD01LDU,1,6},
	{(&B1AD02LDU,1,8},
	{(&B1AD03LDU,1,10},
	{(&B2AD32LDU,1,56},
	{(&B2AD31LDU,1,58},
	{(&B1AD32LDU,1,52},
	{(&B1AD31LDU,1,54},
	{(&B1AD04LDU,1,12},
	{(&B1AD05LDU,1,14},
	{(&A2AD11LDU,1,16},
	{(&A1AD31LDU,1,46},
	{NULL,0,0},
};
#pragma pop
#include <drivers/ao16.h>/nstatic char buf_AO1601[127];	//AO1601
static ao16_inimod ini_AO1601={0xffff,120,0x43,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_AO1601={0,0,&ini_AO1601,buf_AO1601,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_AO1601[]={
	{(&B2IP01IZ1,3,9},
	{(&A0IT03IRP,3,30},
	{(&B2IP01IZ2,3,21},
	{(&B0IT03IRP,3,33},
	{(&A2IP01IZ1,3,3},
	{(&A2IP01IZ2,3,15},
	{(&B3IP02IDU,3,27},
	{(&A3IP02IDU,3,24},
	{(&B0IT02IZ2,3,18},
	{(&B0IT01IZ1,3,6},
	{(&A0IT02IZ2,3,12},
	{(&A0IT01IZ1,3,0},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>/nstatic char buf_DO32_5F01[137];	//DO32_5F01
static do32_pti_inipar ini_DO32_5F01={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F01={0,0,&ini_DO32_5F01,buf_DO32_5F01,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F01[]={
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>/nstatic char buf_DO32_5F09[137];	//DO32_5F09
static do32_pti_inipar ini_DO32_5F09={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F09={0,0,&ini_DO32_5F09,buf_DO32_5F09,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F09[]={
	{(&A5IS11LDU,1,54},
	{(&A5IS21LDU,1,56},
	{(&A6IS21LDU,1,52},
	{(&A2IS21LDU,1,8},
	{(&B5IS11LDU,1,62},
	{(&A2IS11LDU,1,6},
	{(&A2IS12LDU,1,4},
	{(&A1IS21LDU,1,2},
	{(&A1IS11LDU,1,0},
	{(&R4IS12LDU,1,44},
	{(&R4IS22LDU,1,48},
	{(&R4IS21LDU,1,46},
	{(&R4IS11LDU,1,42},
	{(&R0IS02LDU,1,32},
	{(&B6IS11LDU,1,58},
	{(&B4IS21LDU,1,14},
	{(&B4IS11LDU,1,12},
	{(&B6IS21LDU,1,60},
	{(&A3IS21LDU,1,10},
	{(&R8AD22LDU,1,16},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>/nstatic char buf_DO32_5F05[137];	//DO32_5F05
static do32_pti_inipar ini_DO32_5F05={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F05={0,0,&ini_DO32_5F05,buf_DO32_5F05,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F05[]={
	{(&R6IS21LDU,1,26},
	{(&A6IS11LDU,1,34},
	{(&A8IS12LDU,1,28},
	{(&R5IS21LDU,1,20},
	{(&R5IS11LDU,1,18},
	{(&R3IS21LDU,1,4},
	{(&A8IS22LDU,1,30},
	{(&B8IS22LDU,1,12},
	{(&B5IS21LDU,1,0},
	{(&B8IS12LDU,1,10},
	{(&R3IS11LDU,1,2},
	{(&B8IS21LDU,1,8},
	{(&B8IS11LDU,1,14},
	{NULL,0,0},
};
#pragma pop
#include <drivers/vds32_pti.h>/nstatic char buf_VDS32F10[66];	//VDS32F10
static vds32pti_inimod ini_VDS32F10={0,};
#pragma pack(push,1)
static table_drv table_VDS32F10={0,0,&ini_VDS32F10,buf_VDS32F10,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F10[]={
	{(&B9AD10LDU,1,48},
	{(&A9AD10LDU,1,46},
	{(&A8AD20LDU,1,0},
	{(&A6AD10LDU,1,2},
	{(&A6AD20LDU,1,4},
	{(&B6AD10LDU,1,6},
	{(&B6AD20LDU,1,8},
	{(&A3AD03LDU,1,26},
	{(&A3AD04LDU,1,28},
	{(&A3AD05LDU,1,30},
	{(&B3AD11LDU,1,32},
	{(&A1AD04LDU,1,60},
	{(&A1AD03LDU,1,58},
	{(&A1AD02LDU,1,56},
	{(&A1AD01LDU,1,54},
	{(&A1AD21LDU,1,52},
	{(&A1AD11LDU,1,50},
	{(&R0S01LIM,1,62},
	{(&B8AD20LDU,1,16},
	{(&B8AD10LDU,1,14},
	{(&R4AD20LDU,1,12},
	{(&R4AD10LDU,1,10},
	{(&B3AD05LDU,1,44},
	{(&B3AD04LDU,1,42},
	{(&B3AD03LDU,1,40},
	{(&B3AD02LDU,1,38},
	{(&B3AD01LDU,1,36},
	{(&B3AD21LDU,1,34},
	{(&A3AD11LDU,1,18},
	{(&A3AD21LDU,1,20},
	{(&A3AD01LDU,1,22},
	{(&A3AD02LDU,1,24},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>/nstatic char buf_DO32_5F02[137];	//DO32_5F02
static do32_pti_inipar ini_DO32_5F02={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F02={0,0,&ini_DO32_5F02,buf_DO32_5F02,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F02[]={
	{(&R7II73LZ2,1,50},
	{(&R7II71LZ2,1,46},
	{(&R7II72LZ2,1,48},
	{(&R7II72LZ1,1,12},
	{(&R7II71LZ1,1,14},
	{(&R7II73LZ1,1,16},
	{(&A1VP81LZZ,1,0},
	{(&B1VP81LZZ,1,60},
	{(&B0VP81LZZ,1,58},
	{(&B3IS22LDU,1,22},
	{(&A3IS22LDU,1,2},
	{(&B3IS11LDU,1,20},
	{(&A3IS11LDU,1,6},
	{(&A0VP81LZZ,1,4},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>/nstatic char buf_DO32_5F08[137];	//DO32_5F08
static do32_pti_inipar ini_DO32_5F08={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F08={0,0,&ini_DO32_5F08,buf_DO32_5F08,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F08[]={
	{(&A1IS12LDU,1,62},
	{(&B3IS21LDU,1,24},
	{(&A7AS31LDU,1,60},
	{(&B7AS31LDU,1,10},
	{(&A4IS11LDU,1,30},
	{(&A4IS21LDU,1,32},
	{(&R8IS11LDU,1,26},
	{(&R1IS11LDU,1,42},
	{(&R1IS21LDU,1,44},
	{(&R2IS11LDU,1,46},
	{(&R2IS21LDU,1,48},
	{(&A9IS11LDU,1,34},
	{(&A9IS21LDU,1,36},
	{(&B9IS11LDU,1,38},
	{(&B9IS21LDU,1,40},
	{(&B2IS21LDU,1,22},
	{(&B2IS11LDU,1,20},
	{(&B2IS12LDU,1,18},
	{(&B1IS21LDU,1,16},
	{(&B1IS11LDU,1,14},
	{(&B1IS12LDU,1,12},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>/nstatic char buf_DO32_5F06[137];	//DO32_5F06
static do32_pti_inipar ini_DO32_5F06={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F06={0,0,&ini_DO32_5F06,buf_DO32_5F06,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F06[]={
	{NULL,0,0},
};
#pragma pop
#include <drivers/vds32_pti.h>/nstatic char buf_VDS32F07[66];	//VDS32F07
static vds32pti_inimod ini_VDS32F07={0,};
#pragma pack(push,1)
static table_drv table_VDS32F07={0,0,&ini_VDS32F07,buf_VDS32F07,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F07[]={
	{(&A2AD33LDU,1,26},
	{(&A5AD10LDU,1,42},
	{(&A5AD20LDU,1,44},
	{(&B5AD10LDU,1,46},
	{(&B5AD20LDU,1,48},
	{(&A3AD33LDU,1,24},
	{(&B3AD34LDU,1,50},
	{(&R2AD20LDU,1,40},
	{(&A3AD34LDU,1,22},
	{(&B2AD33LDU,1,54},
	{(&B7AP31LDU,1,60},
	{(&A7AP31LDU,1,32},
	{(&R2AD10LDU,1,38},
	{(&R1AD20LDU,1,36},
	{(&R1AD10LDU,1,34},
	{(&B3AD33LDU,1,52},
	{(&A4AD10LDU,1,28},
	{(&B3AD31LDU,1,58},
	{(&A3AD31LDU,1,30},
	{(&B4AD10LDU,1,56},
	{(&A8AD10LDU,1,62},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Drive drivers[]={
	{0x02,0x110,137,def_buf_DO32_5F02,&table_DO32_5F02},	//do32_5f(0x110)
	{0x02,0x130,137,def_buf_DO32_5F08,&table_DO32_5F08},	//do32_5f(0x130)
	{0x02,0x160,137,def_buf_DO32_5F06,&table_DO32_5F06},	//do32_5f(0x160)
	{0x03,0x340,66,def_buf_VDS32F07,&table_VDS32F07},	//vds32f2(0x340)
	{0x03,0x360,66,def_buf_VDS32F10,&table_VDS32F10},	//vds32f2(0x360)
	{0x03,0x310,66,def_buf_VDS32F11,&table_VDS32F11},	//vds32f2(0x310)
	{0x04,0x320,127,def_buf_AO1601,&table_AO1601},	//AO16
	{0x02,0x100,137,def_buf_DO32_5F01,&table_DO32_5F01},	//do32_5f(0x100)
	{0x02,0x140,137,def_buf_DO32_5F09,&table_DO32_5F09},	//do32_5f(0x140)
	{0x02,0x150,137,def_buf_DO32_5F05,&table_DO32_5F05},	//do32_5f(0x150)
	{0x05,0x120,40,def_buf_em8enc120,&table_em8enc120},	//em8enc(0x120)
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){	//Инициализация переменных для хранения
	setAsFloat(492,20.0);
	setAsShort(579,0);
	setAsShort(638,0);
	setAsFloat(303,1.0);
	setAsFloat(322,0.21);
	setAsFloat(458,0);
	setAsFloat(436,0.50);
	setAsShort(597,0);
	setAsFloat(377,0);
	setAsFloat(520,1);
	setAsFloat(392,10.91);
	setAsFloat(466,100);
	setAsFloat(494,10.0);
	setAsShort(617,0);
	setAsFloat(417,0);
	setAsFloat(483,1530.0);
	setAsFloat(452,0.015);
	setAsShort(577,0);
	setAsShort(647,0);
	setAsShort(584,0);
	setAsFloat(398,0);
	setAsFloat(348,0.000885839);
	setAsFloat(465,0.0055);
	setAsFloat(501,10000.0);
	setAsFloat(467,200);
	setAsFloat(477,0);
	setAsFloat(434,390);
	setAsFloat(410,0);
	setAsShort(654,0);
	setAsShort(600,0);
	setAsFloat(475,0);
	setAsFloat(427,0);
	setAsFloat(287,-0.15912805);
	setAsFloat(374,5);
	setAsFloat(453,0.5);
	setAsFloat(487,137.4);
	setAsFloat(368,22975.0);
	setAsShort(616,0);
	setAsShort(583,0);
	setAsFloat(289,25.017338);
	setAsShort(570,0);
	setAsFloat(511,1585.0);
	setAsFloat(447,32000.0);
	setAsShort(540,0);
	setAsShort(538,0);
	setAsShort(596,0);
	setAsFloat(482,0);
	setAsFloat(366,0.0096);
	setAsFloat(298,1.0);
	setAsShort(621,0);
	setAsFloat(401,0);
	setAsShort(587,0);
	setAsShort(560,0);
	setAsFloat(479,0);
	setAsFloat(440,0);
	setAsFloat(342,0);
	setAsFloat(470,500);
	setAsShort(609,0);
	setAsFloat(521,506.5);
	setAsFloat(490,4);
	setAsFloat(302,1.0);
	setAsFloat(395,25.017338);
	setAsFloat(423,0.000885839);
	setAsFloat(323,5.0);
	setAsShort(549,0);
	setAsShort(558,0);
	setAsShort(650,0);
	setAsBool(1048,0);
	setAsFloat(363,2.5);
	setAsFloat(468,300);
	setAsFloat(530,594.0);
	setAsShort(553,0);
	setAsShort(633,0);
	setAsFloat(428,5);
	setAsFloat(518,1269);
	setAsFloat(403,0);
	setAsFloat(362,0.07);
	setAsFloat(504,0.035);
	setAsShort(541,0);
	setAsBool(1045,0);
	setAsShort(591,0);
	setAsFloat(513,1269.0);
	setAsFloat(296,1.0);
	setAsShort(537,0);
	setAsFloat(370,5.0);
	setAsShort(554,0);
	setAsShort(628,0);
	setAsShort(626,0);
	setAsFloat(507,1796.0);
	setAsFloat(297,1.0);
	setAsFloat(300,1.0);
	setAsFloat(306,0);
	setAsShort(648,0);
	setAsShort(623,0);
	setAsShort(566,0);
	setAsShort(631,0);
	setAsFloat(316,0);
	setAsFloat(331,0.002375);
	setAsFloat(446,975000.0);
	setAsShort(622,0);
	setAsShort(625,0);
	setAsFloat(474,0);
	setAsFloat(454,600);
	setAsFloat(441,20);
	setAsFloat(503,0.035);
	setAsShort(561,0);
	setAsShort(539,0);
	setAsShort(536,0);
	setAsShort(606,0);
	setAsShort(602,0);
	setAsShort(542,0);
	setAsFloat(459,0.0026);
	setAsFloat(497,1.0);
	setAsFloat(508,1555.0);
	setAsFloat(307,0);
	setAsShort(604,0);
	setAsFloat(534,572.4);
	setAsFloat(533,248.0);
	setAsFloat(365,0);
	setAsFloat(472,750);
	setAsFloat(381,0);
	setAsFloat(418,0);
	setAsFloat(382,0);
	setAsFloat(304,1.0);
	setAsFloat(315,100);
	setAsFloat(364,0);
	setAsFloat(522,248.0);
	setAsShort(641,0);
	setAsFloat(325,0);
	setAsFloat(327,0);
	setAsFloat(352,0);
	setAsShort(598,0);
	setAsFloat(378,55);
	setAsFloat(485,0.50);
	setAsFloat(308,0);
	setAsShort(555,0);
	setAsBool(1042,0);
	setAsShort(589,0);
	setAsShort(653,0);
	setAsFloat(340,1.6);
	setAsFloat(320,0.73);
	setAsFloat(448,4000);
	setAsFloat(451,0.015);
	setAsFloat(486,1530.0);
	setAsFloat(282,1E12);
	setAsFloat(292,1.0);
	setAsFloat(293,1.0);
	setAsShort(550,0);
	setAsShort(629,0);
	setAsShort(605,0);
	setAsFloat(457,0.0);
	setAsFloat(512,1796.0);
	setAsFloat(514,1555.0);
	setAsShort(573,0);
	setAsShort(642,0);
	setAsFloat(532,556.8);
	setAsFloat(391,20);
	setAsFloat(420,0);
	setAsFloat(461,106);
	setAsFloat(437,1500.0);
	setAsFloat(389,390.0);
	setAsFloat(399,0);
	setAsShort(593,0);
	setAsShort(565,0);
	setAsFloat(455,0.0069);
	setAsFloat(438,2000.0);
	setAsFloat(332,0.00009765625);
	setAsShort(556,0);
	setAsFloat(373,0);
	setAsFloat(288,0.000000166);
	setAsFloat(314,200);
	setAsFloat(509,1269.0);
	setAsFloat(498,18000);
	setAsShort(612,0);
	setAsFloat(430,0);
	setAsFloat(491,4000.0);
	setAsFloat(359,20.0);
	setAsFloat(311,0);
	setAsShort(599,0);
	setAsShort(562,0);
	setAsFloat(484,0);
	setAsShort(603,0);
	setAsShort(643,0);
	setAsFloat(353,0.001675);
	setAsShort(580,0);
	setAsShort(646,0);
	setAsShort(634,0);
	setAsShort(635,0);
	setAsFloat(371,0.275);
	setAsFloat(422,0);
	setAsFloat(408,0);
	setAsBool(1046,1);
	setAsFloat(519,1281.2);
	setAsFloat(510,1269.0);
	setAsShort(652,0);
	setAsShort(644,0);
	setAsFloat(414,0);
	setAsBool(1049,0);
	setAsFloat(462,25);
	setAsFloat(499,18000);
	setAsShort(615,0);
	setAsFloat(312,0.000877);
	setAsFloat(324,9807.0);
	setAsShort(552,0);
	setAsFloat(349,0);
	setAsShort(576,0);
	setAsShort(581,0);
	setAsFloat(329,0);
	setAsFloat(335,0);
	setAsFloat(528,559.0);
	setAsFloat(419,0);
	setAsFloat(449,100000);
	setAsFloat(421,0.000885839);
	setAsFloat(407,0.0);
	setAsShort(655,0);
	setAsShort(613,0);
	setAsFloat(350,0.000885839);
	setAsShort(608,0);
	setAsFloat(489,20);
	setAsFloat(429,0);
	setAsFloat(358,0.01);
	setAsShort(571,0);
	setAsFloat(343,0);
	setAsFloat(500,18000);
	setAsShort(632,0);
	setAsFloat(295,1.0);
	setAsFloat(286,2.9);
	setAsFloat(412,0);
	setAsShort(640,0);
	setAsShort(582,0);
	setAsFloat(387,1500.0);
	setAsFloat(344,0.026);
	setAsFloat(460,600);
	setAsFloat(361,0.6);
	setAsFloat(416,0);
	setAsShort(548,0);
	setAsShort(564,0);
	setAsShort(601,0);
	setAsFloat(469,400);
	setAsFloat(404,0.0);
	setAsFloat(319,0.76);
	setAsShort(636,0);
	setAsShort(543,0);
	setAsFloat(375,0);
	setAsShort(578,0);
	setAsFloat(445,37037.04);
	setAsFloat(372,0.245);
	setAsShort(547,0);
	setAsFloat(338,0.245);
	setAsFloat(328,0);
	setAsFloat(415,0);
	setAsFloat(502,100.0);
	setAsFloat(351,0);
	setAsShort(586,0);
	setAsShort(610,0);
	setAsFloat(317,0.01);
	setAsFloat(463,135.227);
	setAsFloat(283,0.8);
	setAsFloat(515,1281.2);
	setAsFloat(478,0);
	setAsShort(545,0);
	setAsFloat(356,165);
	setAsFloat(400,0.0);
	setAsShort(546,0);
	setAsFloat(341,0.39);
	setAsFloat(473,0);
	setAsShort(630,0);
	setAsFloat(357,0);
	setAsFloat(360,0.13);
	setAsFloat(367,5.0);
	setAsFloat(379,0);
	setAsFloat(305,1.0);
	setAsFloat(321,0);
	setAsFloat(406,0.0);
	setAsShort(614,0);
	setAsFloat(310,0);
	setAsFloat(354,0.00009765625);
	setAsFloat(285,2.74);
	setAsShort(568,0);
	setAsFloat(284,0.0069);
	setAsFloat(334,100);
	setAsFloat(488,40.0);
	setAsFloat(435,0);
	setAsFloat(345,5.0);
	setAsFloat(450,1000000);
	setAsShort(551,0);
	setAsShort(574,0);
	setAsFloat(442,10.91);
	setAsFloat(385,0.0009765625);
	setAsFloat(529,588.0);
	setAsBool(1044,0);
	setAsBool(1050,1);
	setAsShort(585,0);
	setAsFloat(393,0);
	setAsFloat(426,0);
	setAsFloat(380,55.0);
	setAsFloat(516,1269.0);
	setAsFloat(405,0.0);
	setAsShort(563,0);
	setAsShort(567,0);
	setAsFloat(313,0.00009765625);
	setAsFloat(396,0);
	setAsFloat(425,0);
	setAsShort(627,0);
	setAsFloat(493,10);
	setAsFloat(464,320.435466);
	setAsFloat(337,20.0);
	setAsFloat(496,256.0);
	setAsFloat(397,0);
	setAsShort(594,0);
	setAsFloat(390,0);
	setAsFloat(506,1585.0);
	setAsFloat(526,287.2);
	setAsFloat(456,27.108);
	setAsFloat(471,600);
	setAsBool(1043,0);
	setAsFloat(330,0);
	setAsShort(559,0);
	setAsFloat(355,200);
	setAsFloat(439,390.0);
	setAsFloat(318,20.0);
	setAsFloat(480,0);
	setAsFloat(535,246.8);
	setAsShort(592,0);
	setAsShort(588,0);
	setAsFloat(336,0.01);
	setAsFloat(339,0.45);
	setAsShort(557,0);
	setAsShort(649,0);
	setAsShort(590,0);
	setAsShort(619,0);
	setAsFloat(531,597.2);
	setAsFloat(291,1.0);
	setAsFloat(294,1.0);
	setAsFloat(369,0);
	setAsShort(569,0);
	setAsBool(1047,1);
	setAsFloat(409,0);
	setAsFloat(383,390);
	setAsFloat(525,271.6);
	setAsFloat(346,12750.0);
	setAsShort(618,0);
	setAsFloat(309,0);
	setAsFloat(333,80);
	setAsFloat(476,15.0);
	setAsFloat(495,1269.0);
	setAsFloat(388,2000);
	setAsFloat(413,0);
	setAsShort(637,0);
	setAsFloat(402,0.0);
	setAsShort(620,0);
	setAsFloat(424,0);
	setAsFloat(444,20);
	setAsFloat(527,594.0);
	setAsFloat(299,1.0);
	setAsFloat(301,1.0);
	setAsFloat(347,0);
	setAsShort(575,0);
	setAsShort(656,0);
	setAsShort(624,0);
	setAsFloat(505,2.0);
	setAsFloat(386,0.50);
	setAsFloat(524,248.0);
	setAsShort(544,0);
	setAsFloat(326,0);
	setAsFloat(517,1570.0);
	setAsShort(651,0);
	setAsShort(639,0);
	setAsShort(572,0);
	setAsFloat(443,0);
	setAsFloat(290,11.0);
	setAsFloat(523,284.5);
	setAsFloat(394,15.0);
	setAsShort(611,0);
	setAsFloat(376,5.0);
	setAsShort(595,0);
	setAsShort(645,0);
	setAsFloat(411,0);
	setAsFloat(431,55);
	setAsShort(607,0);
	setAsFloat(433,0);
	setAsFloat(481,15.0);
	setAsFloat(384,0);
	setAsFloat(432,0);
}
int freebuf=0;
uspaint8 InternalBuf[1090];
uspaint8 SpaEEPROMBuf[1651];
void Scheme()
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
void InitInternalParametr(void)
void MainCycle(void){
	if ((getAsShort(R0S01LIM) == 2) || (getAsShort(R0S01LIM) == 3)) {
		freebuff = 0;
		Scheme();
	} else {
		if (freebuff) return;
		freebuff = 1;
		memset(BUFFER, 0, SIZE_BUFFER);
		InitSetConst();
		ZeroVar();
		if (SimulOn) initAllSimul(CodeSub, drivers, SimulIP, SimulPort);
		else initAllDriversPTI(drivers);
	}
}
#endif