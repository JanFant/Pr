#ifndef SCM_H
#define SCM_H
// Подсистема scm:SCM
static char SimulOn=0;
static short CodeSub=1;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 3323
static char BUFFER[3323];
#define A1IE03LDU	 BUFFER[0]	//( - , SCM) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 1	//( - , SCM) Движение ББ1 вперед (от БУШД)
#define B1IS12LDU	 BUFFER[2]	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
#define idB1IS12LDU	 2	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
#define B1IS11LDU	 BUFFER[4]	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
#define idB1IS11LDU	 3	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
#define B1IS21LDU	 BUFFER[6]	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
#define idB1IS21LDU	 4	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
#define B1IC01UDU	 BUFFER[8]	//( - , SDu) Координата штока ББ2
#define idB1IC01UDU	 5	//( - , SDu) Координата штока ББ2
#define A1IC01UDU	 BUFFER[13]	//( - , SDu) Координата штока ББ1
#define idA1IC01UDU	 6	//( - , SDu) Координата штока ББ1
#define A1IS12LDU	 BUFFER[18]	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
#define idA1IS12LDU	 7	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
#define A1IS11LDU	 BUFFER[20]	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
#define idA1IS11LDU	 8	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
#define A1IS21LDU	 BUFFER[22]	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
#define idA1IS21LDU	 9	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
#define B6IS21LDU	 BUFFER[24]	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
#define idB6IS21LDU	 10	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
#define B6IS11LDU	 BUFFER[26]	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
#define idB6IS11LDU	 11	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
#define A6IS21LDU	 BUFFER[28]	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
#define idA6IS21LDU	 12	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
#define A6IS11LDU	 BUFFER[30]	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
#define idA6IS11LDU	 13	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
#define A8IS12LDU	 BUFFER[32]	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
#define idA8IS12LDU	 14	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
#define A8IS22LDU	 BUFFER[34]	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
#define idA8IS22LDU	 15	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
#define B8IS12LDU	 BUFFER[36]	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
#define idB8IS12LDU	 16	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
#define B8IS22LDU	 BUFFER[38]	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
#define idB8IS22LDU	 17	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
#define R4IS12LDU	 BUFFER[40]	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
#define idR4IS12LDU	 18	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
#define B1IS11LIM	 BUFFER[42]	//( - , SCM) Магнит ББ2 обесточен
#define idB1IS11LIM	 19	//( - , SCM) Магнит ББ2 обесточен
#define A1IS32LIM	 BUFFER[44]	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
#define idA1IS32LIM	 20	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
#define A1IS11LIM	 BUFFER[46]	//( - , SCM) Магнит ББ1 обесточен
#define idA1IS11LIM	 21	//( - , SCM) Магнит ББ1 обесточен
#define A3AD34LDU	 BUFFER[48]	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
#define idA3AD34LDU	 22	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
#define R0IS02LDU	 BUFFER[50]	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
#define idR0IS02LDU	 23	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
#define R0EE04LZ2	 BUFFER[52]	//( - , SBz2) Питание  АКНП4  отключить
#define idR0EE04LZ2	 24	//( - , SBz2) Питание  АКНП4  отключить
#define R0EE03LZ2	 BUFFER[54]	//( - , SBz2) Питание  АКНП3  отключить
#define idR0EE03LZ2	 25	//( - , SBz2) Питание  АКНП3  отключить
#define R0EE02LZ2	 BUFFER[56]	//( - , SBz2) Питание  АКНП  отключить
#define idR0EE02LZ2	 26	//( - , SBz2) Питание  АКНП  отключить
#define R0EE04LZ1	 BUFFER[58]	//( - , SBz1) Питание  АКНП4  отключить
#define idR0EE04LZ1	 27	//( - , SBz1) Питание  АКНП4  отключить
#define R0EE03LZ1	 BUFFER[60]	//( - , SBz1) Питание  АКНП3  отключить
#define idR0EE03LZ1	 28	//( - , SBz1) Питание  АКНП3  отключить
#define R0EE02LZ1	 BUFFER[62]	//( - , SBz1) Питание  АКНП  отключить
#define idR0EE02LZ1	 29	//( - , SBz1) Питание  АКНП  отключить
#define R0EE01LZ2	 BUFFER[64]	//( - , SBz2) Питание  АКНП1  отключить
#define idR0EE01LZ2	 30	//( - , SBz2) Питание  АКНП1  отключить
#define R0EE01LZ1	 BUFFER[66]	//( - , SBz1) Питание  АКНП1  отключить
#define idR0EE01LZ1	 31	//( - , SBz1) Питание  АКНП1  отключить
#define B4IS10LDU	 BUFFER[68]	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
#define idB4IS10LDU	 32	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
#define A4IS10LDU	 BUFFER[70]	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
#define idA4IS10LDU	 33	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
#define B1IE04LDU	 BUFFER[72]	//( - , SCM) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 34	//( - , SCM) Движение ББ2 назад (от БУШД)
#define B1IE03LDU	 BUFFER[74]	//( - , SCM) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 35	//( - , SCM) Движение ББ2 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[76]	//( - , SCM) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 36	//( - , SCM) Движение ББ1 назад (от БУШД)
#define B2VP82LDU	 BUFFER[78]	//( - , SCM) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 37	//( - , SCM) Давление ПОДЪЁМ РБ2 в норме
#define B2IP01IZ2	 BUFFER[80]	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ2	 38	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
#define B2IP01IZ1	 BUFFER[83]	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	 39	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
#define B2IC01UDU	 BUFFER[86]	//( - , SDu) Координата штока РБ2
#define idB2IC01UDU	 40	//( - , SDu) Координата штока РБ2
#define B2IS12LDU	 BUFFER[91]	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	 41	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
#define B2IS11LDU	 BUFFER[93]	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
#define idB2IS11LDU	 42	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
#define B2IS21LDU	 BUFFER[95]	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
#define idB2IS21LDU	 43	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
#define B9IS21LDU	 BUFFER[97]	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
#define idB9IS21LDU	 44	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
#define B9IS11LDU	 BUFFER[99]	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 45	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
#define A9IS21LDU	 BUFFER[101]	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
#define idA9IS21LDU	 46	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
#define A9IS11LDU	 BUFFER[103]	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 47	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
#define B5IS21LDU	 BUFFER[105]	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
#define idB5IS21LDU	 48	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
#define B5IS11LDU	 BUFFER[107]	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
#define idB5IS11LDU	 49	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
#define A5IS21LDU	 BUFFER[109]	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
#define idA5IS21LDU	 50	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
#define A5IS11LDU	 BUFFER[111]	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
#define idA5IS11LDU	 51	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
#define B0VP81LZZ	 BUFFER[113]	//(do32_pti:100 - K30DO, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	 52	//(do32_pti:100 - K30DO, - ) Давление АЗ2 в норме
#define A0VP81LZZ	 BUFFER[115]	//(do32_pti:100 - K27DO, - ) Давление АЗ1 в норме
#define idA0VP81LZZ	 53	//(do32_pti:100 - K27DO, - ) Давление АЗ1 в норме
#define B8IC01UDU	 BUFFER[117]	//( - , SDu) Координата АЗ2
#define idB8IC01UDU	 54	//( - , SDu) Координата АЗ2
#define R4IS22LDU	 BUFFER[122]	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
#define idR4IS22LDU	 55	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
#define R4IS21LDU	 BUFFER[124]	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
#define idR4IS21LDU	 56	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
#define R4IS11LDU	 BUFFER[126]	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
#define idR4IS11LDU	 57	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
#define B4VP82LDU	 BUFFER[128]	//( - , SCM) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 58	//( - , SCM) Давление ПОДЪЁМ НИ2 в норме
#define A4VP82LDU	 BUFFER[130]	//( - , SCM) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 59	//( - , SCM) Давление ПОДЪЁМ НИ1 в норме
#define R2IS21LDU	 BUFFER[132]	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
#define idR2IS21LDU	 60	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
#define R2IS11LDU	 BUFFER[134]	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
#define idR2IS11LDU	 61	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
#define R1IS21LDU	 BUFFER[136]	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
#define idR1IS21LDU	 62	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
#define R1IS11LDU	 BUFFER[138]	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
#define idR1IS11LDU	 63	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
#define B4IS21LDU	 BUFFER[140]	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
#define idB4IS21LDU	 64	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
#define B4IS11LDU	 BUFFER[142]	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
#define idB4IS11LDU	 65	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
#define R8IS11LDU	 BUFFER[144]	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
#define idR8IS11LDU	 66	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
#define A4IS21LDU	 BUFFER[146]	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
#define idA4IS21LDU	 67	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
#define A4IS11LDU	 BUFFER[148]	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
#define idA4IS11LDU	 68	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
#define R5IS21LDU	 BUFFER[150]	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 69	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
#define R5IS11LDU	 BUFFER[152]	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 70	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
#define R3IS21LDU	 BUFFER[154]	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
#define idR3IS21LDU	 71	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
#define R3IS11LDU	 BUFFER[156]	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	 72	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
#define A0SN07RIM	 BUFFER[158]	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define idA0SN07RIM	 73	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define A0SN06RIM	 BUFFER[163]	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define idA0SN06RIM	 74	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define A0SN05RIM	 BUFFER[168]	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define idA0SN05RIM	 75	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define A0SN04RIM	 BUFFER[173]	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define idA0SN04RIM	 76	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define A0SN03RIM	 BUFFER[178]	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define idA0SN03RIM	 77	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define A0SN02RIM	 BUFFER[183]	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define idA0SN02RIM	 78	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define R0IS01FI0	 BUFFER[188]	//( - , SBz1, SBz2, SDu, SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
#define idR0IS01FI0	 79	//( - , SBz1, SBz2, SDu, SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
#define A0IT03IRP	 BUFFER[191]	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
#define idA0IT03IRP	 80	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
#define B0IT03IRP	 BUFFER[194]	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
#define idB0IT03IRP	 81	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
#define R0IN03FI3	 BUFFER[197]	//( - , SA3) Выход КНК53М Гц от ПТИ
#define idR0IN03FI3	 82	//( - , SA3) Выход КНК53М Гц от ПТИ
#define R0IN02FI3	 BUFFER[202]	//( - , SA3) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI3	 83	//( - , SA3) Выход КНК15-1 Гц от ПТИ
#define R0IN03FI2	 BUFFER[207]	//( - , SA2) Выход КНК53М Гц от ПТИ
#define idR0IN03FI2	 84	//( - , SA2) Выход КНК53М Гц от ПТИ
#define R0IN07RIP	 BUFFER[212]	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
#define idR0IN07RIP	 85	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
#define R0IN06RIP	 BUFFER[217]	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
#define idR0IN06RIP	 86	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
#define TerR0IN06FRP	 BUFFER[222]	//( - , - ) Неисправности СНМ-11 -1,2
#define idTerR0IN06FRP	 87	//( - , - ) Неисправности СНМ-11 -1,2
#define R0IN03RIP	 BUFFER[225]	//( - , SRP) Выход КНК53М Гц от ПТИ
#define idR0IN03RIP	 88	//( - , SRP) Выход КНК53М Гц от ПТИ
#define R0IN02RIP	 BUFFER[230]	//( - , SRP) Выход КНК15- Гц от ПТИ
#define idR0IN02RIP	 89	//( - , SRP) Выход КНК15- Гц от ПТИ
#define R0IN01RIP	 BUFFER[235]	//( - , SRP) Выход СНМ-11 Гц от ПТИ
#define idR0IN01RIP	 90	//( - , SRP) Выход СНМ-11 Гц от ПТИ
#define A3IP02FDU	 BUFFER[240]	//( - , SDu) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02FDU	 91	//( - , SDu) Текущее давление ВЫСТРЕЛ ИС1
#define B3IP02FDU	 BUFFER[243]	//( - , SDu) Текущее давление ВЫСТРЕЛ  ИС2
#define idB3IP02FDU	 92	//( - , SDu) Текущее давление ВЫСТРЕЛ  ИС2
#define B2IP01FZ2	 BUFFER[246]	//( - , SBz2) Текущее давление СБРОС РБ2
#define idB2IP01FZ2	 93	//( - , SBz2) Текущее давление СБРОС РБ2
#define B2IP01FZ1	 BUFFER[249]	//( - , SBz1) Текущее давление СБРОС РБ2
#define idB2IP01FZ1	 94	//( - , SBz1) Текущее давление СБРОС РБ2
#define A2IP01FZ2	 BUFFER[252]	//( - , SBz2) Текущее давление СБРОС РБ1
#define idA2IP01FZ2	 95	//( - , SBz2) Текущее давление СБРОС РБ1
#define A2IP01FZ1	 BUFFER[255]	//( - , SBz1) Текущее давление СБРОС РБ1
#define idA2IP01FZ1	 96	//( - , SBz1) Текущее давление СБРОС РБ1
#define A0IT03FRP	 BUFFER[258]	//( - , SRP) Температура АЗ1-3
#define idA0IT03FRP	 97	//( - , SRP) Температура АЗ1-3
#define A0IT02FZ2	 BUFFER[261]	//( - , SBz2) Температура АЗ1-2
#define idA0IT02FZ2	 98	//( - , SBz2) Температура АЗ1-2
#define A0IT01FZ1	 BUFFER[264]	//( - , SBz1) Температура АЗ1-1
#define idA0IT01FZ1	 99	//( - , SBz1) Температура АЗ1-1
#define B0IT03FRP	 BUFFER[267]	//( - , SRP) Температура АЗ2-3
#define idB0IT03FRP	 100	//( - , SRP) Температура АЗ2-3
#define B0IT02FZ2	 BUFFER[270]	//( - , SBz2) Температура АЗ2-2
#define idB0IT02FZ2	 101	//( - , SBz2) Температура АЗ2-2
#define B0IT01FZ1	 BUFFER[273]	//( - , SBz1) Температура АЗ2-1
#define idB0IT01FZ1	 102	//( - , SBz1) Температура АЗ2-1
#define B0SN07RIM	 BUFFER[276]	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define idB0SN07RIM	 103	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define B0SN06RIM	 BUFFER[281]	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define idB0SN06RIM	 104	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define B0SN05RIM	 BUFFER[286]	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define idB0SN05RIM	 105	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define B0SN04RIM	 BUFFER[291]	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define idB0SN04RIM	 106	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define B0SN03RIM	 BUFFER[296]	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define idB0SN03RIM	 107	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define B0SN02RIM	 BUFFER[301]	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define idB0SN02RIM	 108	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define B5VS22LDU	 BUFFER[306]	//( - , SCM) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 109	//( - , SCM) Движение НЛ2 в сторону НУ
#define A5VS12LDU	 BUFFER[308]	//( - , SCM) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 110	//( - , SCM) Движение НЛ1 в сторону ВУ
#define A5VS22LDU	 BUFFER[310]	//( - , SCM) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 111	//( - , SCM) Движение НЛ1 в сторону НУ
#define B6VS12LDU	 BUFFER[312]	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
#define idB6VS12LDU	 112	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
#define B6VS22LDU	 BUFFER[314]	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
#define idB6VS22LDU	 113	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
#define A6VS12LDU	 BUFFER[316]	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	 114	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
#define A6VS22LDU	 BUFFER[318]	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	 115	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
#define B8IS21LDU	 BUFFER[320]	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
#define idB8IS21LDU	 116	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
#define B8IS11LDU	 BUFFER[322]	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
#define idB8IS11LDU	 117	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
#define A1VP81LZZ	 BUFFER[324]	//(do32_pti:100 - K28DO, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	 118	//(do32_pti:100 - K28DO, - ) Давление СБРОС ББ1 в норме
#define B1VP81LZZ	 BUFFER[326]	//(do32_pti:100 - K31DO, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	 119	//(do32_pti:100 - K31DO, - ) Давление СБРОС ББ2 в норме
#define B2IS33LDU	 BUFFER[328]	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
#define idB2IS33LDU	 120	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
#define A0VN01RIM	 BUFFER[330]	//( - , SCM) Период разгона  AЗ1
#define idA0VN01RIM	 121	//( - , SCM) Период разгона  AЗ1
#define B2IS32LIM	 BUFFER[335]	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
#define idB2IS32LIM	 122	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
#define B2IS11LIM	 BUFFER[337]	//( - , SCM) Магнит РБ2 обесточен
#define idB2IS11LIM	 123	//( - , SCM) Магнит РБ2 обесточен
#define A2IS32LIM	 BUFFER[339]	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
#define idA2IS32LIM	 124	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
#define A2IS11LIM	 BUFFER[341]	//( - , SCM) Магнит РБ1 обесточен
#define idA2IS11LIM	 125	//( - , SCM) Магнит РБ1 обесточен
#define B1IS32LIM	 BUFFER[343]	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
#define idB1IS32LIM	 126	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
#define R0IN02FI2	 BUFFER[345]	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI2	 127	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define R0IN03FI1	 BUFFER[350]	//( - , SA1) Выход КНК53М Гц от ПТИ
#define idR0IN03FI1	 128	//( - , SA1) Выход КНК53М Гц от ПТИ
#define R0IN02FI1	 BUFFER[355]	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI1	 129	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define R0IN03FI4	 BUFFER[360]	//( - , SA4) Выход КНК53М Гц от ПТИ
#define idR0IN03FI4	 130	//( - , SA4) Выход КНК53М Гц от ПТИ
#define R0IN02FI4	 BUFFER[365]	//( - , SA4) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI4	 131	//( - , SA4) Выход КНК15-1 Гц от ПТИ
#define R0IN01FI3	 BUFFER[370]	//( - , SA3) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI3	 132	//( - , SA3) Выход СНМ-11 Гц от ПТИ
#define R0IN01FI2	 BUFFER[375]	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define idR0IN01FI2	 133	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define R0IN01FI4	 BUFFER[380]	//( - , SA4) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI4	 134	//( - , SA4) Выход СНМ-11 Гц от ПТИ
#define R0IN01FI1	 BUFFER[385]	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define idR0IN01FI1	 135	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define B7AP31LDU	 BUFFER[390]	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
#define idB7AP31LDU	 136	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
#define A7AP31LDU	 BUFFER[392]	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
#define idA7AP31LDU	 137	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
#define R4VS12LDU	 BUFFER[394]	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
#define idR4VS12LDU	 138	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
#define R4VS22LDU	 BUFFER[396]	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
#define idR4VS22LDU	 139	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
#define R1VS12LDU	 BUFFER[398]	//( - , SCM) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 140	//( - , SCM) Движение МДЗ1 в сторону ВУ
#define R2VS12LDU	 BUFFER[400]	//( - , SCM) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 141	//( - , SCM) Движение МДЗ2 в сторону ВУ
#define R2VS22LDU	 BUFFER[402]	//( - , SCM) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 142	//( - , SCM) Движение МДЗ2 в сторону НУ
#define R1VS22LDU	 BUFFER[404]	//( - , SCM) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 143	//( - , SCM) Движение МДЗ1 в сторону НУ
#define B5VS12LDU	 BUFFER[406]	//( - , SCM) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 144	//( - , SCM) Движение НЛ2 в сторону ВУ
#define A8AD20LDU	 BUFFER[408]	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
#define idA8AD20LDU	 145	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
#define A8AD10LDU	 BUFFER[410]	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
#define idA8AD10LDU	 146	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
#define B8AD20LDU	 BUFFER[412]	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
#define idB8AD20LDU	 147	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
#define B8AD10LDU	 BUFFER[414]	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
#define idB8AD10LDU	 148	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
#define R4AD20LDU	 BUFFER[416]	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
#define idR4AD20LDU	 149	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
#define R4AD10LDU	 BUFFER[418]	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	 150	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
#define B0SR01RIM	 BUFFER[420]	//( - , SCM) Текущая реактивность AЗ2
#define idB0SR01RIM	 151	//( - , SCM) Текущая реактивность AЗ2
#define B3AD33LDU	 BUFFER[425]	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define idB3AD33LDU	 152	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define B3AD05LDU	 BUFFER[427]	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
#define idB3AD05LDU	 153	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
#define B3AD04LDU	 BUFFER[429]	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
#define idB3AD04LDU	 154	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[431]	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
#define idB3AD03LDU	 155	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
#define B3AD02LDU	 BUFFER[433]	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
#define idB3AD02LDU	 156	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
#define B3AD01LDU	 BUFFER[435]	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
#define idB3AD01LDU	 157	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
#define B3AD21LDU	 BUFFER[437]	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 158	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
#define B3AD11LDU	 BUFFER[439]	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 159	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
#define A3AD33LDU	 BUFFER[441]	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define idA3AD33LDU	 160	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define A3AD05LDU	 BUFFER[443]	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
#define idA3AD05LDU	 161	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
#define A3AD04LDU	 BUFFER[445]	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
#define idA3AD04LDU	 162	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
#define R0AD14LDU	 BUFFER[447]	//( - , SCM) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 163	//( - , SCM) Имитация срабатывания верхней АС II УР
#define R0SR02RIM	 BUFFER[449]	//( - , SCM) Текущая мощность РУ (ватт)
#define idR0SR02RIM	 164	//( - , SCM) Текущая мощность РУ (ватт)
#define R0CR02RIM	 BUFFER[454]	//( - , SCM) Коэффициент 11 связи АЗ1,2
#define idR0CR02RIM	 165	//( - , SCM) Коэффициент 11 связи АЗ1,2
#define R0CR01RIM	 BUFFER[459]	//( - , SCM) Коэффициент 12 связи АЗ1,2
#define idR0CR01RIM	 166	//( - , SCM) Коэффициент 12 связи АЗ1,2
#define B0SN08RIM	 BUFFER[464]	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
#define idB0SN08RIM	 167	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
#define A0SN08RIM	 BUFFER[469]	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
#define idA0SN08RIM	 168	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
#define B5AD20LDU	 BUFFER[474]	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
#define idB5AD20LDU	 169	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
#define B5AD10LDU	 BUFFER[476]	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
#define idB5AD10LDU	 170	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
#define A5AD20LDU	 BUFFER[478]	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
#define idA5AD20LDU	 171	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
#define A5AD10LDU	 BUFFER[480]	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
#define idA5AD10LDU	 172	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
#define R2AD20LDU	 BUFFER[482]	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	 173	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
#define R2AD10LDU	 BUFFER[484]	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
#define idR2AD10LDU	 174	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
#define R1AD20LDU	 BUFFER[486]	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	 175	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
#define R1AD10LDU	 BUFFER[488]	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
#define idR1AD10LDU	 176	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
#define B6AD20LDU	 BUFFER[490]	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
#define idB6AD20LDU	 177	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
#define B6AD10LDU	 BUFFER[492]	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
#define idB6AD10LDU	 178	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
#define A6AD20LDU	 BUFFER[494]	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
#define idA6AD20LDU	 179	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
#define A6AD10LDU	 BUFFER[496]	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
#define idA6AD10LDU	 180	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
#define A2AD01LDU	 BUFFER[498]	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
#define idA2AD01LDU	 181	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
#define A2AD21LDU	 BUFFER[500]	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 182	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
#define A2AD11LDU	 BUFFER[502]	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 183	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
#define B1AD05LDU	 BUFFER[504]	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
#define idB1AD05LDU	 184	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
#define B1AD04LDU	 BUFFER[506]	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
#define idB1AD04LDU	 185	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[508]	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
#define idB1AD03LDU	 186	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
#define B1AD02LDU	 BUFFER[510]	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
#define idB1AD02LDU	 187	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
#define B1AD01LDU	 BUFFER[512]	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
#define idB1AD01LDU	 188	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
#define B1AD21LDU	 BUFFER[514]	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 189	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
#define B1AD11LDU	 BUFFER[516]	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 190	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
#define A1AD05LDU	 BUFFER[518]	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
#define idA1AD05LDU	 191	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
#define A1AD04LDU	 BUFFER[520]	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
#define idA1AD04LDU	 192	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[522]	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
#define idA1AD03LDU	 193	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
#define A1AD02LDU	 BUFFER[524]	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
#define idA1AD02LDU	 194	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
#define A1AD01LDU	 BUFFER[526]	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
#define idA1AD01LDU	 195	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
#define A1AD21LDU	 BUFFER[528]	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 196	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
#define A1AD11LDU	 BUFFER[530]	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 197	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
#define A0SR01RIM	 BUFFER[532]	//( - , SCM) Текущая реактивность AЗ1
#define idA0SR01RIM	 198	//( - , SCM) Текущая реактивность AЗ1
#define A3AD03LDU	 BUFFER[537]	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
#define idA3AD03LDU	 199	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
#define A3AD02LDU	 BUFFER[539]	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
#define idA3AD02LDU	 200	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
#define A3AD01LDU	 BUFFER[541]	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
#define idA3AD01LDU	 201	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
#define A3AD21LDU	 BUFFER[543]	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 202	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
#define A3AD11LDU	 BUFFER[545]	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 203	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
#define B2AD33LDU	 BUFFER[547]	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
#define idB2AD33LDU	 204	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
#define B2AD05LDU	 BUFFER[549]	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
#define idB2AD05LDU	 205	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
#define B2AD04LDU	 BUFFER[551]	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
#define idB2AD04LDU	 206	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[553]	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
#define idB2AD03LDU	 207	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
#define B2AD02LDU	 BUFFER[555]	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
#define idB2AD02LDU	 208	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
#define B2AD01LDU	 BUFFER[557]	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
#define idB2AD01LDU	 209	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
#define B2AD21LDU	 BUFFER[559]	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 210	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
#define B2AD11LDU	 BUFFER[561]	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 211	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
#define A2AD33LDU	 BUFFER[563]	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
#define idA2AD33LDU	 212	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
#define A2AD05LDU	 BUFFER[565]	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
#define idA2AD05LDU	 213	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
#define A2AD04LDU	 BUFFER[567]	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
#define idA2AD04LDU	 214	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[569]	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
#define idA2AD03LDU	 215	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
#define A2AD02LDU	 BUFFER[571]	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
#define idA2AD02LDU	 216	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
#define B3IP02IDU	 BUFFER[573]	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
#define idB3IP02IDU	 217	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
#define A3IS33LDU	 BUFFER[576]	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define idA3IS33LDU	 218	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define A3IC01UDU	 BUFFER[578]	//( - , SDu) Координата штока ИС1
#define idA3IC01UDU	 219	//( - , SDu) Координата штока ИС1
#define A3IS31LDU	 BUFFER[583]	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
#define idA3IS31LDU	 220	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
#define A2VP82LDU	 BUFFER[585]	//( - , SCM) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 221	//( - , SCM) Давление ПОДЪЁМ РБ1 в норме
#define A2IP01IZ2	 BUFFER[587]	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ2	 222	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
#define A2IP01IZ1	 BUFFER[590]	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	 223	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
#define B3IS21LDU	 BUFFER[593]	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
#define idB3IS21LDU	 224	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
#define A3IS21LDU	 BUFFER[595]	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
#define idA3IS21LDU	 225	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
#define A2IS33LDU	 BUFFER[597]	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
#define idA2IS33LDU	 226	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
#define A2IC01UDU	 BUFFER[599]	//( - , SDu) Координата штока РБ1
#define idA2IC01UDU	 227	//( - , SDu) Координата штока РБ1
#define A2IS12LDU	 BUFFER[604]	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	 228	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
#define A2IS11LDU	 BUFFER[606]	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
#define idA2IS11LDU	 229	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
#define A2IS21LDU	 BUFFER[608]	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
#define idA2IS21LDU	 230	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
#define B0IT02IZ2	 BUFFER[610]	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
#define idB0IT02IZ2	 231	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
#define B0IT01IZ1	 BUFFER[613]	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
#define idB0IT01IZ1	 232	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
#define A0IT02IZ2	 BUFFER[616]	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
#define idA0IT02IZ2	 233	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
#define A0IT01IZ1	 BUFFER[619]	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
#define idA0IT01IZ1	 234	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
#define A8IC01UDU	 BUFFER[622]	//( - , SDu) Координата ДС2
#define idA8IC01UDU	 235	//( - , SDu) Координата ДС2
#define R6IS68LZZ	 BUFFER[627]	//(do32_pti:100 - K19DO, - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 236	//(do32_pti:100 - K19DO, - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define R6IS67LZZ	 BUFFER[629]	//(do32_pti:100 - K18DO, - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 237	//(do32_pti:100 - K18DO, - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS66LZZ	 BUFFER[631]	//(do32_pti:100 - K17DO, - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 238	//(do32_pti:100 - K17DO, - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS65LDU	 BUFFER[633]	//(do32_pti:160 - K32DO, - ) Исправность ВИП ССДИ-35 2канал
#define idR6IS65LDU	 239	//(do32_pti:160 - K32DO, - ) Исправность ВИП ССДИ-35 2канал
#define R6IS64LDU	 BUFFER[635]	//(do32_pti:160 - K31DO, - ) Исправность ВИП ССДИ-35 1канал
#define idR6IS64LDU	 240	//(do32_pti:160 - K31DO, - ) Исправность ВИП ССДИ-35 1канал
#define R6IS63LDU	 BUFFER[637]	//(do32_pti:160 - K30DO, - ) Исправность ВИП ССДИ-39 2канал
#define idR6IS63LDU	 241	//(do32_pti:160 - K30DO, - ) Исправность ВИП ССДИ-39 2канал
#define R6IS62LDU	 BUFFER[639]	//(do32_pti:160 - K29DO, - ) Исправность ВИП ССДИ-39 1канал
#define idR6IS62LDU	 242	//(do32_pti:160 - K29DO, - ) Исправность ВИП ССДИ-39 1канал
#define B3IS22LDU	 BUFFER[641]	//(do32_pti:100 - K12DO, - ) Приход на НУП ИС2
#define idB3IS22LDU	 243	//(do32_pti:100 - K12DO, - ) Приход на НУП ИС2
#define A3IS22LDU	 BUFFER[643]	//(do32_pti:100 - K06DO, - ) Приход на НУП ИС1
#define idA3IS22LDU	 244	//(do32_pti:100 - K06DO, - ) Приход на НУП ИС1
#define B3IS11LDU	 BUFFER[645]	//(do32_pti:100 - K11DO, - ) Приход на ВУ ИС2
#define idB3IS11LDU	 245	//(do32_pti:100 - K11DO, - ) Приход на ВУ ИС2
#define A3IS11LDU	 BUFFER[647]	//(do32_pti:100 - K05DO, - ) Приход на ВУ ИС1
#define idA3IS11LDU	 246	//(do32_pti:100 - K05DO, - ) Приход на ВУ ИС1
#define A3IP02IDU	 BUFFER[649]	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 247	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
#define B3VP81LDU	 BUFFER[652]	//( - , SCM) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 248	//( - , SCM) Давление СПУСК ИС2 в норме
#define A3VP81LDU	 BUFFER[654]	//( - , SCM) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 249	//( - , SCM) Давление СПУСК ИС1 в норме
#define B3IS33LDU	 BUFFER[656]	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idB3IS33LDU	 250	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define B3IC01UDU	 BUFFER[658]	//( - , SDu) Координата штока ИС2
#define idB3IC01UDU	 251	//( - , SDu) Координата штока ИС2
#define B3IS31LDU	 BUFFER[663]	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
#define idB3IS31LDU	 252	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
#define B9AD10LDU	 BUFFER[665]	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
#define idB9AD10LDU	 253	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
#define R0MW13LP2	 BUFFER[667]	//( - , SCM) Переключатель «СЕТЬ»
#define idR0MW13LP2	 254	//( - , SCM) Переключатель «СЕТЬ»
#define B3AD31LDU	 BUFFER[669]	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
#define idB3AD31LDU	 255	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
#define B2AD32LDU	 BUFFER[671]	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
#define idB2AD32LDU	 256	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
#define B2AD31LDU	 BUFFER[673]	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
#define idB2AD31LDU	 257	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
#define B1AD32LDU	 BUFFER[675]	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
#define idB1AD32LDU	 258	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
#define B1AD31LDU	 BUFFER[677]	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
#define idB1AD31LDU	 259	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
#define A3AD31LDU	 BUFFER[679]	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
#define idA3AD31LDU	 260	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
#define C1MD31LP1	 BUFFER[681]	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
#define idC1MD31LP1	 261	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
#define C1MD31LP2	 BUFFER[683]	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
#define idC1MD31LP2	 262	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
#define A1AD31LDU	 BUFFER[685]	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
#define idA1AD31LDU	 263	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
#define A1AD32LDU	 BUFFER[687]	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
#define idA1AD32LDU	 264	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
#define A2AD31LDU	 BUFFER[689]	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
#define idA2AD31LDU	 265	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
#define C2MD31LP1	 BUFFER[691]	//( - , SCM) Кнопка «СБРОС РБ»
#define idC2MD31LP1	 266	//( - , SCM) Кнопка «СБРОС РБ»
#define A2AD32LDU	 BUFFER[693]	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
#define idA2AD32LDU	 267	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
#define R0VZ71LZ2	 BUFFER[695]	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
#define idR0VZ71LZ2	 268	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
#define R0VZ71LZ1	 BUFFER[697]	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
#define idR0VZ71LZ1	 269	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
#define R8AD21LDU	 BUFFER[699]	//(vds32_pti:310 - K31VDSR, - ) Запуск системы инициирования
#define idR8AD21LDU	 270	//(vds32_pti:310 - K31VDSR, - ) Запуск системы инициирования
#define R6IS21LDU	 BUFFER[701]	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	 271	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
#define B7AS31LDU	 BUFFER[703]	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
#define idB7AS31LDU	 272	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
#define A7AS31LDU	 BUFFER[705]	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
#define idA7AS31LDU	 273	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
#define B3IS35LDU	 BUFFER[707]	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
#define idB3IS35LDU	 274	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
#define B3AD34LDU	 BUFFER[709]	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
#define idB3AD34LDU	 275	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
#define A3IS35LDU	 BUFFER[711]	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
#define idA3IS35LDU	 276	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
#define R7II73LZ2	 BUFFER[713]	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
#define idR7II73LZ2	 277	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
#define R7II71LZ2	 BUFFER[715]	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
#define idR7II71LZ2	 278	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
#define R7II72LZ2	 BUFFER[717]	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
#define idR7II72LZ2	 279	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
#define R0AD16LDU	 BUFFER[719]	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
#define idR0AD16LDU	 280	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
#define R7II72LZ1	 BUFFER[721]	//(do32_pti:100 - K25DO, - ) Сработала АС IУР (датчик 2)
#define idR7II72LZ1	 281	//(do32_pti:100 - K25DO, - ) Сработала АС IУР (датчик 2)
#define R7II71LZ1	 BUFFER[723]	//(do32_pti:100 - K24DO, - ) Сработала АС IУР (датчик 1)
#define idR7II71LZ1	 282	//(do32_pti:100 - K24DO, - ) Сработала АС IУР (датчик 1)
#define R7II73LZ1	 BUFFER[725]	//(do32_pti:100 - K26DO, - ) Сработала АС IIУР
#define idR7II73LZ1	 283	//(do32_pti:100 - K26DO, - ) Сработала АС IIУР
#define R0SR01RIM	 BUFFER[727]	//( - , SCM) Текущая реактивность PУ
#define idR0SR01RIM	 284	//( - , SCM) Текущая реактивность PУ
#define R0ST01RIM	 BUFFER[732]	//( - , SCM) Текущий период разгона РУ
#define idR0ST01RIM	 285	//( - , SCM) Текущий период разгона РУ
#define A4AD10LDU	 BUFFER[737]	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
#define idA4AD10LDU	 286	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
#define B4AD10LDU	 BUFFER[739]	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
#define idB4AD10LDU	 287	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
#define A9AD10LDU	 BUFFER[741]	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
#define idA9AD10LDU	 288	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
#define fEM_R0UL01RIM	 BUFFER[743]	//(R0UL01RIM) Среднее время генерации нейтронов
#define idfEM_R0UL01RIM	 289	//(R0UL01RIM) Среднее время генерации нейтронов
#define fEM_R0UN02RIM	 BUFFER[748]	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define idfEM_R0UN02RIM	 290	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define fEM_A1UR01RIM	 BUFFER[753]	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR01RIM	 291	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define fEM_A1UR00RIM	 BUFFER[758]	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR00RIM	 292	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define fEM_A3UR00RIM	 BUFFER[763]	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR00RIM	 293	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define fEM_A3UR01RIM	 BUFFER[768]	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR01RIM	 294	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define fEM_R0UT01RIM	 BUFFER[773]	//(R0UT01RIM) Температурный коэффициент (долл)
#define idfEM_R0UT01RIM	 295	//(R0UT01RIM) Температурный коэффициент (долл)
#define fEM_R0UT02RIM	 BUFFER[778]	//(R0UT02RIM) Масса топлива в АЗ
#define idfEM_R0UT02RIM	 296	//(R0UT02RIM) Масса топлива в АЗ
#define fEM_R0UT04RIM	 BUFFER[783]	//(R0UT04RIM) Удельная теплоёмкость топлива
#define idfEM_R0UT04RIM	 297	//(R0UT04RIM) Удельная теплоёмкость топлива
#define fEM_R0UT03RIM	 BUFFER[788]	//(R0UT03RIM) Нормальная температура АЗ град
#define idfEM_R0UT03RIM	 298	//(R0UT03RIM) Нормальная температура АЗ град
#define fEM_R0UT05RIM	 BUFFER[793]	//(R0UT05RIM) Энергия деления ядра
#define idfEM_R0UT05RIM	 299	//(R0UT05RIM) Энергия деления ядра
#define fEM_R0UT06RIM	 BUFFER[798]	//(R0UT06RIM) Конвекционное сопротивление при обдуве
#define idfEM_R0UT06RIM	 300	//(R0UT06RIM) Конвекционное сопротивление при обдуве
#define fEM_A1UC02RDU	 BUFFER[803]	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define idfEM_A1UC02RDU	 301	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define fEM_A1UC04RIM	 BUFFER[808]	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define idfEM_A1UC04RIM	 302	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define fEM_A1UC05RIM	 BUFFER[813]	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define idfEM_A1UC05RIM	 303	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define fEM_A1UC06RIM	 BUFFER[818]	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define idfEM_A1UC06RIM	 304	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define fEM_A2UC06RIM	 BUFFER[823]	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define idfEM_A2UC06RIM	 305	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define fEM_A2UC05RIM	 BUFFER[828]	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define idfEM_A2UC05RIM	 306	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define fEM_A2UC04RIM	 BUFFER[833]	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define idfEM_A2UC04RIM	 307	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define fEM_A2UC02RDU	 BUFFER[838]	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define idfEM_A2UC02RDU	 308	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define fEM_A3UC06RIM	 BUFFER[843]	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define idfEM_A3UC06RIM	 309	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define fEM_A3UC05RIM	 BUFFER[848]	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC05RIM	 310	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define fEM_A3UC04RIM	 BUFFER[853]	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define idfEM_A3UC04RIM	 311	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define fEM_A3UC02RDU	 BUFFER[858]	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define idfEM_A3UC02RDU	 312	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define fEM_R4UV80RDU	 BUFFER[863]	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
#define idfEM_R4UV80RDU	 313	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
#define fEM_R4UC10RIM	 BUFFER[868]	//(R4UC10RIM) Координата верхних механических упоров тележки мм
#define idfEM_R4UC10RIM	 314	//(R4UC10RIM) Координата верхних механических упоров тележки мм
#define fEM_R4UC20RIM	 BUFFER[873]	//(R4UC20RIM) Координата нижних механических упоров тележки мм
#define idfEM_R4UC20RIM	 315	//(R4UC20RIM) Координата нижних механических упоров тележки мм
#define fEM_B8UC21RIM	 BUFFER[878]	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define idfEM_B8UC21RIM	 316	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define fEM_B8UC20RIM	 BUFFER[883]	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define idfEM_B8UC20RIM	 317	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define fEM_B8UC11RIM	 BUFFER[888]	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define idfEM_B8UC11RIM	 318	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define fEM_B8UC10RIM	 BUFFER[893]	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define idfEM_B8UC10RIM	 319	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define fEM_B8UV80RDU	 BUFFER[898]	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define idfEM_B8UV80RDU	 320	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define fEM_A8UV80RDU	 BUFFER[903]	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define idfEM_A8UV80RDU	 321	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define fEM_A8UC10RIM	 BUFFER[908]	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define idfEM_A8UC10RIM	 322	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define fEM_A8UC11RIM	 BUFFER[913]	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define idfEM_A8UC11RIM	 323	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define fEM_A8UC20RIM	 BUFFER[918]	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define idfEM_A8UC20RIM	 324	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define fEM_A8UC21RIM	 BUFFER[923]	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define idfEM_A8UC21RIM	 325	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define fEM_A6UC10RIM	 BUFFER[928]	//(A6UC10RIM) Время полного хода БЗ (сек)
#define idfEM_A6UC10RIM	 326	//(A6UC10RIM) Время полного хода БЗ (сек)
#define fEM_R1UC10RIM	 BUFFER[933]	//(R1UC10RIM) Время полного хода МДЗ сек
#define idfEM_R1UC10RIM	 327	//(R1UC10RIM) Время полного хода МДЗ сек
#define fEM_A5UC10RIM	 BUFFER[938]	//(A5UC10RIM) Время полного хода НЛ сек
#define idfEM_A5UC10RIM	 328	//(A5UC10RIM) Время полного хода НЛ сек
#define fEM_A0UN01RIM	 BUFFER[943]	//(A0UN01RIM) Мощность источника нейтронов ИНИ
#define idfEM_A0UN01RIM	 329	//(A0UN01RIM) Мощность источника нейтронов ИНИ
#define fEM_R4UC22RIM	 BUFFER[948]	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define idfEM_R4UC22RIM	 330	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define fEM_A1UG01RDU	 BUFFER[953]	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define idfEM_A1UG01RDU	 331	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define fEM_A2UG01RDU	 BUFFER[958]	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
#define idfEM_A2UG01RDU	 332	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
#define fEM_A3UG01RDU	 BUFFER[963]	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
#define idfEM_A3UG01RDU	 333	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
#define fEM_R7UC10RIM	 BUFFER[968]	//(R7UC10RIM) X-координата КНК53М R7IN13 см
#define idfEM_R7UC10RIM	 334	//(R7UC10RIM) X-координата КНК53М R7IN13 см
#define fEM_R7UC19RIM	 BUFFER[973]	//(R7UC19RIM) Y-координата СНМ-11 (11) см
#define idfEM_R7UC19RIM	 335	//(R7UC19RIM) Y-координата СНМ-11 (11) см
#define fEM_R7UI02RIM	 BUFFER[978]	//(R7UI02RIM) Коэффициент усиления уровня радиации
#define idfEM_R7UI02RIM	 336	//(R7UI02RIM) Коэффициент усиления уровня радиации
#define fEM_R7UL01RIM	 BUFFER[983]	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define idfEM_R7UL01RIM	 337	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define fEM_A2UR00RIM	 BUFFER[988]	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define idfEM_A2UR00RIM	 338	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define fEM_A2UR01RIM	 BUFFER[993]	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define idfEM_A2UR01RIM	 339	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define fEM_A0UN02RIM	 BUFFER[998]	//(A0UN02RIM) Мощность источника нейтронов с АНИ
#define idfEM_A0UN02RIM	 340	//(A0UN02RIM) Мощность источника нейтронов с АНИ
#define fEM_R0UR30RIM	 BUFFER[1003]	//(R0UR30RIM) Реактивность вносимая образцами (долл)
#define idfEM_R0UR30RIM	 341	//(R0UR30RIM) Реактивность вносимая образцами (долл)
#define fEM_R0UR01RIM	 BUFFER[1008]	//(R0UR01RIM) Стартовая отрицательная реактивность
#define idfEM_R0UR01RIM	 342	//(R0UR01RIM) Стартовая отрицательная реактивность
#define fEM_R0UT02RDU	 BUFFER[1013]	//(R0UT02RDU) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RDU	 343	//(R0UT02RDU) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RDU	 BUFFER[1018]	//(R0UT01RDU) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RDU	 344	//(R0UT01RDU) Нижний предел шкалы датчика температуры
#define fEM_A1UC03RDU	 BUFFER[1023]	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define idfEM_A1UC03RDU	 345	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define fEM_A2UP03RDU	 BUFFER[1028]	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP03RDU	 346	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UP04RDU	 BUFFER[1033]	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP04RDU	 347	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UC03RDU	 BUFFER[1038]	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define idfEM_A2UC03RDU	 348	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define fEM_A3UP03RDU	 BUFFER[1043]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 349	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1048]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 350	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UC03RDU	 BUFFER[1053]	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define idfEM_A3UC03RDU	 351	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define fEM_R7UI74RIM	 BUFFER[1058]	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define idfEM_R7UI74RIM	 352	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define fEM_A8UC03RDU	 BUFFER[1063]	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define idfEM_A8UC03RDU	 353	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define fEM_R0UV87RDU	 BUFFER[1068]	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 354	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV81RDU	 BUFFER[1073]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 355	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1078]	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 356	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1083]	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 357	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1088]	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 358	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1093]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 359	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1098]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 360	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_A8UC08RDU	 BUFFER[1103]	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define idfEM_A8UC08RDU	 361	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define fEM_B8UC08RDU	 BUFFER[1108]	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define idfEM_B8UC08RDU	 362	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define fEM_R4UC08RDU	 BUFFER[1113]	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define idfEM_R4UC08RDU	 363	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define fEM_R0UH01RSS	 BUFFER[1118]	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
#define idfEM_R0UH01RSS	 364	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
#define fEM_A0UX00RSS	 BUFFER[1123]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 365	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_R7UX01RSS	 BUFFER[1128]	//(R7UX01RSS) X-координата камеры R7IN11
#define idfEM_R7UX01RSS	 366	//(R7UX01RSS) X-координата камеры R7IN11
#define fEM_R7UX02RSS	 BUFFER[1133]	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define idfEM_R7UX02RSS	 367	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define fEM_R7UX04RSS	 BUFFER[1138]	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define idfEM_R7UX04RSS	 368	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define fEM_R7UX05RSS	 BUFFER[1143]	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define idfEM_R7UX05RSS	 369	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define fEM_R7UX06RSS	 BUFFER[1148]	//(R7UX06RSS) X-координата камеры R7IN23 (см)
#define idfEM_R7UX06RSS	 370	//(R7UX06RSS) X-координата камеры R7IN23 (см)
#define fEM_R7UX07RSS	 BUFFER[1153]	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define idfEM_R7UX07RSS	 371	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define fEM_R7UX08RSS	 BUFFER[1158]	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define idfEM_R7UX08RSS	 372	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define fEM_R7UX09RSS	 BUFFER[1163]	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define idfEM_R7UX09RSS	 373	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define fEM_R7UY01RSS	 BUFFER[1168]	//(R7UY01RSS) Y-координата камеры R7IN11
#define idfEM_R7UY01RSS	 374	//(R7UY01RSS) Y-координата камеры R7IN11
#define fEM_R7UY02RSS	 BUFFER[1173]	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define idfEM_R7UY02RSS	 375	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define fEM_R7UY04RSS	 BUFFER[1178]	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define idfEM_R7UY04RSS	 376	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define fEM_R7UY05RSS	 BUFFER[1183]	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define idfEM_R7UY05RSS	 377	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define fEM_R7UY06RSS	 BUFFER[1188]	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define idfEM_R7UY06RSS	 378	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define fEM_R7UY07RSS	 BUFFER[1193]	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define idfEM_R7UY07RSS	 379	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define fEM_R7UY08RSS	 BUFFER[1198]	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define idfEM_R7UY08RSS	 380	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define fEM_R7UY09RSS	 BUFFER[1203]	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define idfEM_R7UY09RSS	 381	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define fEM_R7UX10RSS	 BUFFER[1208]	//(R7UX10RSS) X-координата камеры R7IN41
#define idfEM_R7UX10RSS	 382	//(R7UX10RSS) X-координата камеры R7IN41
#define fEM_R7UX11RSS	 BUFFER[1213]	//(R7UX11RSS) X-координата камеры R7IN42
#define idfEM_R7UX11RSS	 383	//(R7UX11RSS) X-координата камеры R7IN42
#define fEM_R7UX12RSS	 BUFFER[1218]	//(R7UX12RSS) X-координата камеры R7IN43
#define idfEM_R7UX12RSS	 384	//(R7UX12RSS) X-координата камеры R7IN43
#define fEM_R7UY10RSS	 BUFFER[1223]	//(R7UY10RSS) Y-координата камеры R7IN41
#define idfEM_R7UY10RSS	 385	//(R7UY10RSS) Y-координата камеры R7IN41
#define fEM_R7UY11RSS	 BUFFER[1228]	//(R7UY11RSS) Y-координата камеры R7IN42
#define idfEM_R7UY11RSS	 386	//(R7UY11RSS) Y-координата камеры R7IN42
#define fEM_R7UY12RSS	 BUFFER[1233]	//(R7UY12RSS) Y-координата камеры R7IN43
#define idfEM_R7UY12RSS	 387	//(R7UY12RSS) Y-координата камеры R7IN43
#define fEM_A0UX01RSS	 BUFFER[1238]	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define idfEM_A0UX01RSS	 388	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define fEM_A0UX02RSS	 BUFFER[1243]	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define idfEM_A0UX02RSS	 389	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define fEM_A0UX03RSS	 BUFFER[1248]	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define idfEM_A0UX03RSS	 390	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define fEM_A0UX04RSS	 BUFFER[1253]	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define idfEM_A0UX04RSS	 391	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define fEM_A0UX05RSS	 BUFFER[1258]	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define idfEM_A0UX05RSS	 392	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define fEM_A0UX06RSS	 BUFFER[1263]	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define idfEM_A0UX06RSS	 393	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define fEM_A0UX07RSS	 BUFFER[1268]	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define idfEM_A0UX07RSS	 394	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define fEM_A0UX08RSS	 BUFFER[1273]	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define idfEM_A0UX08RSS	 395	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define fEM_A0UX09RSS	 BUFFER[1278]	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define idfEM_A0UX09RSS	 396	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define fEM_A0UX10RSS	 BUFFER[1283]	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define idfEM_A0UX10RSS	 397	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define fEM_A0UX11RSS	 BUFFER[1288]	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define idfEM_A0UX11RSS	 398	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define fEM_A0UX12RSS	 BUFFER[1293]	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define idfEM_A0UX12RSS	 399	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define fEM_B0UX01RSS	 BUFFER[1298]	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define idfEM_B0UX01RSS	 400	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define fEM_B0UX02RSS	 BUFFER[1303]	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define idfEM_B0UX02RSS	 401	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define fEM_B0UX03RSS	 BUFFER[1308]	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	 402	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	 BUFFER[1313]	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
#define idfEM_B0UX04RSS	 403	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
#define fEM_B0UX05RSS	 BUFFER[1318]	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	 404	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_B0UX06RSS	 BUFFER[1323]	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define idfEM_B0UX06RSS	 405	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define fEM_B0UX07RSS	 BUFFER[1328]	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define idfEM_B0UX07RSS	 406	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define fEM_B0UX08RSS	 BUFFER[1333]	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define idfEM_B0UX08RSS	 407	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define fEM_B0UX09RSS	 BUFFER[1338]	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define idfEM_B0UX09RSS	 408	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define fEM_B0UX10RSS	 BUFFER[1343]	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define idfEM_B0UX10RSS	 409	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define fEM_B0UX11RSS	 BUFFER[1348]	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define idfEM_B0UX11RSS	 410	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define fEM_B0UX12RSS	 BUFFER[1353]	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define idfEM_B0UX12RSS	 411	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define fEM_R0UH02RSS	 BUFFER[1358]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define idfEM_R0UH02RSS	 412	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define fEM_R0UH03RSS	 BUFFER[1363]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define idfEM_R0UH03RSS	 413	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define fEM_R4US80RDU	 BUFFER[1368]	//(R4US80RDU) Тормозной путь тележки (мм)
#define idfEM_R4US80RDU	 414	//(R4US80RDU) Тормозной путь тележки (мм)
#define fEM_R7UI71RIM	 BUFFER[1373]	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define idfEM_R7UI71RIM	 415	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define fEM_R7UI72RIM	 BUFFER[1378]	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define idfEM_R7UI72RIM	 416	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define fEM_R7UI73RIM	 BUFFER[1383]	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define idfEM_R7UI73RIM	 417	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define fEM_A1UP01RIM	 BUFFER[1388]	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define idfEM_A1UP01RIM	 418	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define fEM_A2UP01RIM	 BUFFER[1393]	//(A2UP01RIM) Текущее давление на сброс РБ
#define idfEM_A2UP01RIM	 419	//(A2UP01RIM) Текущее давление на сброс РБ
#define fEM_A0UP02RIM	 BUFFER[1398]	//(A0UP02RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP02RIM	 420	//(A0UP02RIM) Текущее давление в АЗ1,2
#define fEM_A3UP01RIM	 BUFFER[1403]	//(A3UP01RIM) Текущее давление на СПУСК ИС
#define idfEM_A3UP01RIM	 421	//(A3UP01RIM) Текущее давление на СПУСК ИС
#define fEM_A1UP82RIM	 BUFFER[1408]	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define idfEM_A1UP82RIM	 422	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define fEM_A3UP02RDU	 BUFFER[1413]	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define idfEM_A3UP02RDU	 423	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define fEM_A1UV02RIM	 BUFFER[1418]	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define idfEM_A1UV02RIM	 424	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define fEM_A3UV02RIM	 BUFFER[1423]	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define idfEM_A3UV02RIM	 425	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define fEM_A2UV02RIM	 BUFFER[1428]	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define idfEM_A2UV02RIM	 426	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define fEM_B8US80RDU	 BUFFER[1433]	//(B8US80RDU) Тормозной путь АЗ2 (мм)
#define idfEM_B8US80RDU	 427	//(B8US80RDU) Тормозной путь АЗ2 (мм)
#define fEM_A8US80RDU	 BUFFER[1438]	//(A8US80RDU) Тормозной путь ДС2 (мм)
#define idfEM_A8US80RDU	 428	//(A8US80RDU) Тормозной путь ДС2 (мм)
#define fEM_A6US80RDU	 BUFFER[1443]	//(A6US80RDU) Тормозной путь БЗ (мм)
#define idfEM_A6US80RDU	 429	//(A6US80RDU) Тормозной путь БЗ (мм)
#define fEM_A1US07RDU	 BUFFER[1448]	//(A1US07RDU) Постоянная времени масляного демпфера ББ
#define idfEM_A1US07RDU	 430	//(A1US07RDU) Постоянная времени масляного демпфера ББ
#define fEM_A2US07RDU	 BUFFER[1453]	//(A2US07RDU) Постоянная времени масляного демпфера РБ
#define idfEM_A2US07RDU	 431	//(A2US07RDU) Постоянная времени масляного демпфера РБ
#define fEM_A3US07RDU	 BUFFER[1458]	//(A3US07RDU) Постоянная времени масляного демпфера ИС
#define idfEM_A3US07RDU	 432	//(A3US07RDU) Постоянная времени масляного демпфера ИС
#define fEM_R7UI75RIM	 BUFFER[1463]	//(R7UI75RIM) Множитель к уровню радиации
#define idfEM_R7UI75RIM	 433	//(R7UI75RIM) Множитель к уровню радиации
#define fEM_R0UH21RSS	 BUFFER[1468]	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	 434	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	 BUFFER[1473]	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	 435	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	 BUFFER[1478]	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	 436	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0UH05RSS	 BUFFER[1483]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 437	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_A4UL10RIM	 BUFFER[1488]	//(A4UL10RIM) Время полного перемещения НИ сек
#define idfEM_A4UL10RIM	 438	//(A4UL10RIM) Время полного перемещения НИ сек
#define fEM_A9UL10RIM	 BUFFER[1493]	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define idfEM_A9UL10RIM	 439	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define fEM_R3UL10RIM	 BUFFER[1498]	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define idfEM_R3UL10RIM	 440	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define fEM_R5UL10RIM	 BUFFER[1503]	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define idfEM_R5UL10RIM	 441	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define fEM_R6UL10RIM	 BUFFER[1508]	//(R6UL10RIM) Время полного хода кран-балки сек
#define idfEM_R6UL10RIM	 442	//(R6UL10RIM) Время полного хода кран-балки сек
#define lEM_C1AD31LRP	 BUFFER[1513]	//(C1AD31LRP) Общий сброс от РПУ
#define idlEM_C1AD31LRP	 443	//(C1AD31LRP) Общий сброс от РПУ
#define lEM_R0IE01LRP	 BUFFER[1515]	//(R0IE01LRP) Отключение питание детекторов
#define idlEM_R0IE01LRP	 444	//(R0IE01LRP) Отключение питание детекторов
#define lEM_R0IE02LRP	 BUFFER[1517]	//(R0IE02LRP) Отключить питание ПР, ПУ
#define idlEM_R0IE02LRP	 445	//(R0IE02LRP) Отключить питание ПР, ПУ
#define fEM_A2UP02RIM	 BUFFER[1519]	//(A2UP02RIM) Текущее давление на подъём РБ
#define idfEM_A2UP02RIM	 446	//(A2UP02RIM) Текущее давление на подъём РБ
#define fEM_A2UP03RIM	 BUFFER[1524]	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define idfEM_A2UP03RIM	 447	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define fEM_A0UP01RIM	 BUFFER[1529]	//(A0UP01RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP01RIM	 448	//(A0UP01RIM) Текущее давление в АЗ1,2
#define fEM_A3UP02RIM	 BUFFER[1534]	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define idfEM_A3UP02RIM	 449	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define fEM_A4UP01RIM	 BUFFER[1539]	//(A4UP01RIM) Текущее давление на подъём НИ
#define idfEM_A4UP01RIM	 450	//(A4UP01RIM) Текущее давление на подъём НИ
#define fEM_A4UP02RIM	 BUFFER[1544]	//(A4UP02RIM) Нижняя граница давления на подъём НИ
#define idfEM_A4UP02RIM	 451	//(A4UP02RIM) Нижняя граница давления на подъём НИ
#define fEM_R7UI76RIM	 BUFFER[1549]	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define idfEM_R7UI76RIM	 452	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define fEM_R7UI77RIM	 BUFFER[1554]	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define idfEM_R7UI77RIM	 453	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define iEM_TERBB1	 BUFFER[1559]	//(TERBB1) Неисправности  ББ1
#define idiEM_TERBB1	 454	//(TERBB1) Неисправности  ББ1
#define fEM_A1MC02RC1	 BUFFER[1562]	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
#define idfEM_A1MC02RC1	 455	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
#define fEM_A1MV02RC1	 BUFFER[1567]	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define idfEM_A1MV02RC1	 456	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define iEM_TERBB2	 BUFFER[1572]	//(TERBB2) Неисправности  ББ2
#define idiEM_TERBB2	 457	//(TERBB2) Неисправности  ББ2
#define fEM_B1MC02RC1	 BUFFER[1575]	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
#define idfEM_B1MC02RC1	 458	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
#define fEM_B1MV02RC1	 BUFFER[1580]	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define idfEM_B1MV02RC1	 459	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define iEM_TERRB2	 BUFFER[1585]	//(TERRB2) Неисправности  РБ2
#define idiEM_TERRB2	 460	//(TERRB2) Неисправности  РБ2
#define fEM_B2MC02RC1	 BUFFER[1588]	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
#define idfEM_B2MC02RC1	 461	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
#define fEM_B2MV02RC1	 BUFFER[1593]	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define idfEM_B2MV02RC1	 462	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define iEM_TERRB1	 BUFFER[1598]	//(TERRB1) Неисправности  РБ1
#define idiEM_TERRB1	 463	//(TERRB1) Неисправности  РБ1
#define fEM_A2MC02RC1	 BUFFER[1601]	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
#define idfEM_A2MC02RC1	 464	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
#define fEM_A2MV02RC1	 BUFFER[1606]	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define idfEM_A2MV02RC1	 465	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define iEM_TERIS2	 BUFFER[1611]	//(TERIS2) Неисправности  ИС2
#define idiEM_TERIS2	 466	//(TERIS2) Неисправности  ИС2
#define fEM_B3MC02RC1	 BUFFER[1614]	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
#define idfEM_B3MC02RC1	 467	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
#define fEM_B3MV02RC1	 BUFFER[1619]	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define idfEM_B3MV02RC1	 468	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define iEM_TERIS1	 BUFFER[1624]	//(TERIS1) Неисправности  ИС1
#define idiEM_TERIS1	 469	//(TERIS1) Неисправности  ИС1
#define fEM_A3MC02RC1	 BUFFER[1627]	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
#define idfEM_A3MC02RC1	 470	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
#define fEM_A3MV02RC1	 BUFFER[1632]	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define idfEM_A3MV02RC1	 471	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define iEM_TERA1IE04LDU	 BUFFER[1637]	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define idiEM_TERA1IE04LDU	 472	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define iEM_TERA1IE03LDU	 BUFFER[1640]	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define idiEM_TERA1IE03LDU	 473	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define fEM_A1MC01RC1	 BUFFER[1643]	//(A1MC01RC1) Заданная координата  ББ1 от ИС
#define idfEM_A1MC01RC1	 474	//(A1MC01RC1) Заданная координата  ББ1 от ИС
#define iEM_TERB1IE03LDU	 BUFFER[1648]	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define idiEM_TERB1IE03LDU	 475	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define iEM_TERB1IE04LDU	 BUFFER[1651]	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define idiEM_TERB1IE04LDU	 476	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define fEM_B1MC01RC1	 BUFFER[1654]	//(B1MC01RC1) Заданная координата ББ2 от ИС
#define idfEM_B1MC01RC1	 477	//(B1MC01RC1) Заданная координата ББ2 от ИС
#define fEM_B1MV01RC1	 BUFFER[1659]	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define idfEM_B1MV01RC1	 478	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define fEM_B2MC01RC1	 BUFFER[1664]	//(B2MC01RC1) Заданная координата РБ2 от ИС
#define idfEM_B2MC01RC1	 479	//(B2MC01RC1) Заданная координата РБ2 от ИС
#define fEM_B2MV01RC1	 BUFFER[1669]	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define idfEM_B2MV01RC1	 480	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define fEM_A3MC01RC1	 BUFFER[1674]	//(A3MC01RC1) Заданная координата ИС1 от ИС
#define idfEM_A3MC01RC1	 481	//(A3MC01RC1) Заданная координата ИС1 от ИС
#define fEM_A3MV01RC1	 BUFFER[1679]	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define idfEM_A3MV01RC1	 482	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define fEM_B3MC01RC1	 BUFFER[1684]	//(B3MC01RC1) Заданная координата ИС2 от ИС
#define idfEM_B3MC01RC1	 483	//(B3MC01RC1) Заданная координата ИС2 от ИС
#define fEM_B3MV01RC1	 BUFFER[1689]	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define idfEM_B3MV01RC1	 484	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define iEM_TERA2SS21LIM	 BUFFER[1694]	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define idiEM_TERA2SS21LIM	 485	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define iEM_TERA2SS12LIM	 BUFFER[1697]	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define idiEM_TERA2SS12LIM	 486	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define iEM_TERR6SS21LIM	 BUFFER[1700]	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define idiEM_TERR6SS21LIM	 487	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define iEM_TERA2VP82LIM	 BUFFER[1703]	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define idiEM_TERA2VP82LIM	 488	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define iEM_TERA2SS11LIM	 BUFFER[1706]	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define idiEM_TERA2SS11LIM	 489	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define iEM_TERB3SS21LIM	 BUFFER[1709]	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define idiEM_TERB3SS21LIM	 490	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define iEM_TERA0MT01RIM	 BUFFER[1712]	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define idiEM_TERA0MT01RIM	 491	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define iEM_TERB0MT01RIM	 BUFFER[1715]	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define idiEM_TERB0MT01RIM	 492	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define iEM_TERA2SP01RIM	 BUFFER[1718]	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define idiEM_TERA2SP01RIM	 493	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define iEM_TERB2SP01RIM	 BUFFER[1721]	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define idiEM_TERB2SP01RIM	 494	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define iEM_TERB3SP02RIM	 BUFFER[1724]	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define idiEM_TERB3SP02RIM	 495	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define iEM_TERA3SC01RIM	 BUFFER[1727]	//(TERA3SC01RIM) Искажение: Координата штока ИС1
#define idiEM_TERA3SC01RIM	 496	//(TERA3SC01RIM) Искажение: Координата штока ИС1
#define iEM_TERA3VP81LIM	 BUFFER[1730]	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define idiEM_TERA3VP81LIM	 497	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define iEM_TERA2SC01RIM	 BUFFER[1733]	//(TERA2SC01RIM) Искажение: Координата штока РБ1
#define idiEM_TERA2SC01RIM	 498	//(TERA2SC01RIM) Искажение: Координата штока РБ1
#define iEM_TERA2SS33LIM	 BUFFER[1736]	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define idiEM_TERA2SS33LIM	 499	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define iEM_TERA3SS21LIM	 BUFFER[1739]	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define idiEM_TERA3SS21LIM	 500	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define iEM_TERA3SS33LIM	 BUFFER[1742]	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define idiEM_TERA3SS33LIM	 501	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define iEM_TERA3SS31LIM	 BUFFER[1745]	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define idiEM_TERA3SS31LIM	 502	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define iEM_TERB3SS31LIM	 BUFFER[1748]	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define idiEM_TERB3SS31LIM	 503	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define iEM_TERB3SS33LIM	 BUFFER[1751]	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idiEM_TERB3SS33LIM	 504	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define iEM_TERB3SC01RIM	 BUFFER[1754]	//(TERB3SC01RIM) Искажение: Координата штока ИС2
#define idiEM_TERB3SC01RIM	 505	//(TERB3SC01RIM) Искажение: Координата штока ИС2
#define iEM_TERA3SS11LIM	 BUFFER[1757]	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define idiEM_TERA3SS11LIM	 506	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define iEM_TERB3SS11LIM	 BUFFER[1760]	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define idiEM_TERB3SS11LIM	 507	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define iEM_TERR6IS64LIM	 BUFFER[1763]	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define idiEM_TERR6IS64LIM	 508	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define iEM_TERB3SS22LIM	 BUFFER[1766]	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define idiEM_TERB3SS22LIM	 509	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define iEM_TERA3SS22LIM	 BUFFER[1769]	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define idiEM_TERA3SS22LIM	 510	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define iEM_TERA3SP02RIM	 BUFFER[1772]	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define idiEM_TERA3SP02RIM	 511	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define iEM_TERR6IS62LIM	 BUFFER[1775]	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define idiEM_TERR6IS62LIM	 512	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define iEM_TERR6IS66LIM	 BUFFER[1778]	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idiEM_TERR6IS66LIM	 513	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define iEM_TERR6IS67LIM	 BUFFER[1781]	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idiEM_TERR6IS67LIM	 514	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define iEM_TERA0VP81LIM	 BUFFER[1784]	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define idiEM_TERA0VP81LIM	 515	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define iEM_TERB0VP81LIM	 BUFFER[1787]	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define idiEM_TERB0VP81LIM	 516	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define iEM_TERR0VP81LIM	 BUFFER[1790]	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define idiEM_TERR0VP81LIM	 517	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define iEM_TERR6IS68LIM	 BUFFER[1793]	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define idiEM_TERR6IS68LIM	 518	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define iEM_TERR7SI74RIM	 BUFFER[1796]	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define idiEM_TERR7SI74RIM	 519	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define iEM_TERA5SS21LIM	 BUFFER[1799]	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define idiEM_TERA5SS21LIM	 520	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define iEM_TERB5SS11LIM	 BUFFER[1802]	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define idiEM_TERB5SS11LIM	 521	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define iEM_TERA5SS11LIM	 BUFFER[1805]	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define idiEM_TERA5SS11LIM	 522	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define iEM_TERA9SS11LIM	 BUFFER[1808]	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define idiEM_TERA9SS11LIM	 523	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define iEM_TERB2SS11LIM	 BUFFER[1811]	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define idiEM_TERB2SS11LIM	 524	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define iEM_TERB2SS12LIM	 BUFFER[1814]	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define idiEM_TERB2SS12LIM	 525	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define iEM_TERB2SS21LIM	 BUFFER[1817]	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define idiEM_TERB2SS21LIM	 526	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define iEM_TERR3SS11LIM	 BUFFER[1820]	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define idiEM_TERR3SS11LIM	 527	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define iEM_TERB2SC01RIM	 BUFFER[1823]	//(TERB2SC01RIM) Искажение: Координата штока РБ2
#define idiEM_TERB2SC01RIM	 528	//(TERB2SC01RIM) Искажение: Координата штока РБ2
#define iEM_TERR3SS21LIM	 BUFFER[1826]	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define idiEM_TERR3SS21LIM	 529	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define iEM_TERR5SS11LIM	 BUFFER[1829]	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define idiEM_TERR5SS11LIM	 530	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define iEM_TERA4SS11LIM	 BUFFER[1832]	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define idiEM_TERA4SS11LIM	 531	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define iEM_TERR1SS11LIM	 BUFFER[1835]	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define idiEM_TERR1SS11LIM	 532	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define iEM_TERR1SS21LIM	 BUFFER[1838]	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define idiEM_TERR1SS21LIM	 533	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define iEM_TERR2SS11LIM	 BUFFER[1841]	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define idiEM_TERR2SS11LIM	 534	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define iEM_TERR2SS21LIM	 BUFFER[1844]	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define idiEM_TERR2SS21LIM	 535	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define iEM_TERA4VP82LIM	 BUFFER[1847]	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define idiEM_TERA4VP82LIM	 536	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define iEM_TERB4SS21LIM	 BUFFER[1850]	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define idiEM_TERB4SS21LIM	 537	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define iEM_TERR5SS21LIM	 BUFFER[1853]	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define idiEM_TERR5SS21LIM	 538	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define iEM_TERB6SS21LIM	 BUFFER[1856]	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define idiEM_TERB6SS21LIM	 539	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define iEM_TERB4SS11LIM	 BUFFER[1859]	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define idiEM_TERB4SS11LIM	 540	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define iEM_TERA4SS21LIM	 BUFFER[1862]	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define idiEM_TERA4SS21LIM	 541	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define iEM_TERA6MS11LIM	 BUFFER[1865]	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define idiEM_TERA6MS11LIM	 542	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define iEM_TERA6SS21LIM	 BUFFER[1868]	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define idiEM_TERA6SS21LIM	 543	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define iEM_TERB6SS11LIM	 BUFFER[1871]	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define idiEM_TERB6SS11LIM	 544	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define iEM_TERR4SS11LIM	 BUFFER[1874]	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define idiEM_TERR4SS11LIM	 545	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define iEM_TERR4MS21LIM	 BUFFER[1877]	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
#define idiEM_TERR4MS21LIM	 546	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
#define iEM_TERR4SS12LIM	 BUFFER[1880]	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define idiEM_TERR4SS12LIM	 547	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define iEM_TERR4SS22LIM	 BUFFER[1883]	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define idiEM_TERR4SS22LIM	 548	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define iEM_TERR8SS11LIM	 BUFFER[1886]	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define idiEM_TERR8SS11LIM	 549	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define iEM_TERB8SC01RIM	 BUFFER[1889]	//(TERB8SC01RIM) Искажение: Координата АЗ2
#define idiEM_TERB8SC01RIM	 550	//(TERB8SC01RIM) Искажение: Координата АЗ2
#define iEM_TERA8SC01RIM	 BUFFER[1892]	//(TERA8SC01RIM) Искажение: Координата ДС2
#define idiEM_TERA8SC01RIM	 551	//(TERA8SC01RIM) Искажение: Координата ДС2
#define iEM_TERB8SS12LIM	 BUFFER[1895]	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define idiEM_TERB8SS12LIM	 552	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define iEM_TERA8SS12LIM	 BUFFER[1898]	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define idiEM_TERA8SS12LIM	 553	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define iEM_TERB8SS22LIM	 BUFFER[1901]	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define idiEM_TERB8SS22LIM	 554	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define iEM_TERA8SS22LIM	 BUFFER[1904]	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define idiEM_TERA8SS22LIM	 555	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define iEM_TERA9SS21LIM	 BUFFER[1907]	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define idiEM_TERA9SS21LIM	 556	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define iEM_TERB9SS21LIM	 BUFFER[1910]	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define idiEM_TERB9SS21LIM	 557	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define iEM_TERB9SS11LIM	 BUFFER[1913]	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define idiEM_TERB9SS11LIM	 558	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define iEM_TERB5SS21LIM	 BUFFER[1916]	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define idiEM_TERB5SS21LIM	 559	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define iEM_TERA1SS21LIM	 BUFFER[1919]	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define idiEM_TERA1SS21LIM	 560	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define iEM_TERA1SS11LIM	 BUFFER[1922]	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define idiEM_TERA1SS11LIM	 561	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define iEM_TERA1SC01RIM	 BUFFER[1925]	//(TERA1SC01RIM) Искажение: Координата штока ББ1
#define idiEM_TERA1SC01RIM	 562	//(TERA1SC01RIM) Искажение: Координата штока ББ1
#define iEM_TERA1SS12LIM	 BUFFER[1928]	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define idiEM_TERA1SS12LIM	 563	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define iEM_TERB1SS21LIM	 BUFFER[1931]	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define idiEM_TERB1SS21LIM	 564	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define iEM_TERB1SS11LIM	 BUFFER[1934]	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define idiEM_TERB1SS11LIM	 565	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define iEM_TERB1MC01RIM	 BUFFER[1937]	//(TERB1MC01RIM) Искажение: Координата штока ББ2
#define idiEM_TERB1MC01RIM	 566	//(TERB1MC01RIM) Искажение: Координата штока ББ2
#define iEM_TERB1SS12LIM	 BUFFER[1940]	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define idiEM_TERB1SS12LIM	 567	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define iEM_TERTLG	 BUFFER[1943]	//(TERTLG) Неисправности  тележки от ИС
#define idiEM_TERTLG	 568	//(TERTLG) Неисправности  тележки от ИС
#define fEM_R4MC01RC1	 BUFFER[1946]	//(R4MC01RC1) Заданная координата тележки от ИС
#define idfEM_R4MC01RC1	 569	//(R4MC01RC1) Заданная координата тележки от ИС
#define fEM_R4MV01RC1	 BUFFER[1951]	//(R4MV01RC1) Заданная скорость тележки от ИС
#define idfEM_R4MV01RC1	 570	//(R4MV01RC1) Заданная скорость тележки от ИС
#define iEM_TERMAZ2	 BUFFER[1956]	//(TERMAZ2) Неисправности АЗ2 от ИС
#define idiEM_TERMAZ2	 571	//(TERMAZ2) Неисправности АЗ2 от ИС
#define fEM_B8MC01RC1	 BUFFER[1959]	//(B8MC01RC1) аданная координата АЗ2 от ИС
#define idfEM_B8MC01RC1	 572	//(B8MC01RC1) аданная координата АЗ2 от ИС
#define fEM_B8MV01RC1	 BUFFER[1964]	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
#define idfEM_B8MV01RC1	 573	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
#define iEM_TERDS2	 BUFFER[1969]	//(TERDS2) Неисправности ДС2 от ИС
#define idiEM_TERDS2	 574	//(TERDS2) Неисправности ДС2 от ИС
#define fEM_A8MC01RC1	 BUFFER[1972]	//(A8MC01RC1) Заданная координата ДС2 от ИС
#define idfEM_A8MC01RC1	 575	//(A8MC01RC1) Заданная координата ДС2 от ИС
#define fEM_A8MV01RC1	 BUFFER[1977]	//(A8MV01RC1) Заданная скорость ДС2 от ИС
#define idfEM_A8MV01RC1	 576	//(A8MV01RC1) Заданная скорость ДС2 от ИС
#define iEM_TERBZ1	 BUFFER[1982]	//(TERBZ1) Неисправности БЗ1
#define idiEM_TERBZ1	 577	//(TERBZ1) Неисправности БЗ1
#define fEM_A6MC01RC1	 BUFFER[1985]	//(A6MC01RC1) Заданная координата БЗ1 от ИС
#define idfEM_A6MC01RC1	 578	//(A6MC01RC1) Заданная координата БЗ1 от ИС
#define fEM_A6MV01RC1	 BUFFER[1990]	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
#define idfEM_A6MV01RC1	 579	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
#define iEM_TERBZ2	 BUFFER[1995]	//(TERBZ2) Неисправности БЗ2
#define idiEM_TERBZ2	 580	//(TERBZ2) Неисправности БЗ2
#define fEM_B6MC01RC1	 BUFFER[1998]	//(B6MC01RC1) Заданная координата БЗ2 от ИС
#define idfEM_B6MC01RC1	 581	//(B6MC01RC1) Заданная координата БЗ2 от ИС
#define fEM_B6MV01RC1	 BUFFER[2003]	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
#define idfEM_B6MV01RC1	 582	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
#define lEM_R3AD10LC1	 BUFFER[2008]	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define idlEM_R3AD10LC1	 583	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define lEM_R3AD20LC1	 BUFFER[2010]	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define idlEM_R3AD20LC1	 584	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define lEM_R6AD10LC1	 BUFFER[2012]	//(R6AD10LC1) Выкатить кран-балку от ИС
#define idlEM_R6AD10LC1	 585	//(R6AD10LC1) Выкатить кран-балку от ИС
#define lEM_R5AD10LC1	 BUFFER[2014]	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define idlEM_R5AD10LC1	 586	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define lEM_R5AD20LC1	 BUFFER[2016]	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define idlEM_R5AD20LC1	 587	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define iEM_TERMDZ2	 BUFFER[2018]	//(TERMDZ2) Неисправности МДЗ2
#define idiEM_TERMDZ2	 588	//(TERMDZ2) Неисправности МДЗ2
#define fEM_R2MC01RC1	 BUFFER[2021]	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
#define idfEM_R2MC01RC1	 589	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
#define fEM_R2MV01RC1	 BUFFER[2026]	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define idfEM_R2MV01RC1	 590	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define iEM_TERMDZ1	 BUFFER[2031]	//(TERMDZ1) Неисправности МДЗ1
#define idiEM_TERMDZ1	 591	//(TERMDZ1) Неисправности МДЗ1
#define fEM_R1MC01RC1	 BUFFER[2034]	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
#define idfEM_R1MC01RC1	 592	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
#define fEM_R1MV01RC1	 BUFFER[2039]	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define idfEM_R1MV01RC1	 593	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define iEM_TERNL1	 BUFFER[2044]	//(TERNL1) Неисправности НЛ1
#define idiEM_TERNL1	 594	//(TERNL1) Неисправности НЛ1
#define fEM_A5MC01RC1	 BUFFER[2047]	//(A5MC01RC1) Заданная координата НЛ1 от ИС
#define idfEM_A5MC01RC1	 595	//(A5MC01RC1) Заданная координата НЛ1 от ИС
#define fEM_A5MV01RC1	 BUFFER[2052]	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
#define idfEM_A5MV01RC1	 596	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
#define iEM_TERNL2	 BUFFER[2057]	//(TERNL2) Неисправности НЛ2
#define idiEM_TERNL2	 597	//(TERNL2) Неисправности НЛ2
#define fEM_B5MC01RC1	 BUFFER[2060]	//(B5MC01RC1) Заданная координата НЛ2 от ИС
#define idfEM_B5MC01RC1	 598	//(B5MC01RC1) Заданная координата НЛ2 от ИС
#define fEM_B5MV01RC1	 BUFFER[2065]	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
#define idfEM_B5MV01RC1	 599	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
#define lEM_R8AD10LC1	 BUFFER[2070]	//(R8AD10LC1) Установить аварийный НИ от ИС
#define idlEM_R8AD10LC1	 600	//(R8AD10LC1) Установить аварийный НИ от ИС
#define fEM_A1UC08RIM	 BUFFER[2072]	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define idfEM_A1UC08RIM	 601	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define fEM_A2UC08RIM	 BUFFER[2077]	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
#define idfEM_A2UC08RIM	 602	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
#define fEM_A3UC08RIM	 BUFFER[2082]	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define idfEM_A3UC08RIM	 603	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define iEM_TERB2SS33LIM	 BUFFER[2087]	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define idiEM_TERB2SS33LIM	 604	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define iEM_TERA1VP81LIM	 BUFFER[2090]	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define idiEM_TERA1VP81LIM	 605	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define iEM_TERB1VP81LIM	 BUFFER[2093]	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define idiEM_TERB1VP81LIM	 606	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define fEM_A0UT03RSP	 BUFFER[2096]	//(A0UT03RSP) Стартовая  температура АЗ1 град
#define idfEM_A0UT03RSP	 607	//(A0UT03RSP) Стартовая  температура АЗ1 град
#define fEM_A0UR01RSP	 BUFFER[2101]	//(A0UR01RSP) Стартовая  реактивность АЗ1
#define idfEM_A0UR01RSP	 608	//(A0UR01RSP) Стартовая  реактивность АЗ1
#define fEM_A0UR02RSP	 BUFFER[2106]	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define idfEM_A0UR02RSP	 609	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define fEM_B0UT03RSP	 BUFFER[2111]	//(B0UT03RSP) Стартовая  температура АЗ2 град
#define idfEM_B0UT03RSP	 610	//(B0UT03RSP) Стартовая  температура АЗ2 град
#define fEM_A1MC01RSP	 BUFFER[2116]	//(A1MC01RSP) Стартовая координата  ББ1
#define idfEM_A1MC01RSP	 611	//(A1MC01RSP) Стартовая координата  ББ1
#define fEM_A1MC02RSP	 BUFFER[2121]	//(A1MC02RSP) Стартовая координата штока ББ1
#define idfEM_A1MC02RSP	 612	//(A1MC02RSP) Стартовая координата штока ББ1
#define fEM_A1MV01RSP	 BUFFER[2126]	//(A1MV01RSP) Стартовая скорость движения  ББ1
#define idfEM_A1MV01RSP	 613	//(A1MV01RSP) Стартовая скорость движения  ББ1
#define fEM_A1MV02RSP	 BUFFER[2131]	//(A1MV02RSP) Стартовая скорость движения  ББ1
#define idfEM_A1MV02RSP	 614	//(A1MV02RSP) Стартовая скорость движения  ББ1
#define fEM_B1MC01RSP	 BUFFER[2136]	//(B1MC01RSP) Стартовая координата  ББ2
#define idfEM_B1MC01RSP	 615	//(B1MC01RSP) Стартовая координата  ББ2
#define fEM_B1MV01RSP	 BUFFER[2141]	//(B1MV01RSP) Стартовая скорость движения  ББ2
#define idfEM_B1MV01RSP	 616	//(B1MV01RSP) Стартовая скорость движения  ББ2
#define fEM_B1MC02RSP	 BUFFER[2146]	//(B1MC02RSP) Стартовая координата штока ББ2
#define idfEM_B1MC02RSP	 617	//(B1MC02RSP) Стартовая координата штока ББ2
#define fEM_B1MV02RSP	 BUFFER[2151]	//(B1MV02RSP) Стартовая скорость движения  ББ2
#define idfEM_B1MV02RSP	 618	//(B1MV02RSP) Стартовая скорость движения  ББ2
#define fEM_A2MC01RC1	 BUFFER[2156]	//(A2MC01RC1) Заданная координата РБ1 от ИС
#define idfEM_A2MC01RC1	 619	//(A2MC01RC1) Заданная координата РБ1 от ИС
#define fEM_A2MV01RC1	 BUFFER[2161]	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define idfEM_A2MV01RC1	 620	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define fEM_A2MC01RSP	 BUFFER[2166]	//(A2MC01RSP) Стартовая координата  РБ1
#define idfEM_A2MC01RSP	 621	//(A2MC01RSP) Стартовая координата  РБ1
#define fEM_A2MV01RSP	 BUFFER[2171]	//(A2MV01RSP) Стартовая скорость движения  РБ1
#define idfEM_A2MV01RSP	 622	//(A2MV01RSP) Стартовая скорость движения  РБ1
#define fEM_A2MC02RSP	 BUFFER[2176]	//(A2MC02RSP) Стартовая координата штока РБ1
#define idfEM_A2MC02RSP	 623	//(A2MC02RSP) Стартовая координата штока РБ1
#define fEM_A2MV02RSP	 BUFFER[2181]	//(A2MV02RSP) Стартовая скорость движения  РБ1
#define idfEM_A2MV02RSP	 624	//(A2MV02RSP) Стартовая скорость движения  РБ1
#define fEM_B2MC01RSP	 BUFFER[2186]	//(B2MC01RSP) Стартовая координата  РБ2
#define idfEM_B2MC01RSP	 625	//(B2MC01RSP) Стартовая координата  РБ2
#define fEM_B2MV01RSP	 BUFFER[2191]	//(B2MV01RSP) Стартовая скорость движения  РБ2
#define idfEM_B2MV01RSP	 626	//(B2MV01RSP) Стартовая скорость движения  РБ2
#define fEM_B2MC02RSP	 BUFFER[2196]	//(B2MC02RSP) Стартовая координата штока РБ2
#define idfEM_B2MC02RSP	 627	//(B2MC02RSP) Стартовая координата штока РБ2
#define fEM_B2MV02RSP	 BUFFER[2201]	//(B2MV02RSP) Стартовая скорость движения  РБ2
#define idfEM_B2MV02RSP	 628	//(B2MV02RSP) Стартовая скорость движения  РБ2
#define fEM_A3MC01RSP	 BUFFER[2206]	//(A3MC01RSP) Стартовая координата  ИС1
#define idfEM_A3MC01RSP	 629	//(A3MC01RSP) Стартовая координата  ИС1
#define fEM_A3MV01RSP	 BUFFER[2211]	//(A3MV01RSP) Стартовая скорость движения  ИС1
#define idfEM_A3MV01RSP	 630	//(A3MV01RSP) Стартовая скорость движения  ИС1
#define fEM_A3MC02RSP	 BUFFER[2216]	//(A3MC02RSP) Стартовая координата штока ИС1
#define idfEM_A3MC02RSP	 631	//(A3MC02RSP) Стартовая координата штока ИС1
#define fEM_A3MV02RSP	 BUFFER[2221]	//(A3MV02RSP) Стартовая скорость движения  ИС1
#define idfEM_A3MV02RSP	 632	//(A3MV02RSP) Стартовая скорость движения  ИС1
#define fEM_B3MC01RSP	 BUFFER[2226]	//(B3MC01RSP) Стартовая координата  ИС2
#define idfEM_B3MC01RSP	 633	//(B3MC01RSP) Стартовая координата  ИС2
#define fEM_B3MV01RSP	 BUFFER[2231]	//(B3MV01RSP) Стартовая скорость движения  ИС2
#define idfEM_B3MV01RSP	 634	//(B3MV01RSP) Стартовая скорость движения  ИС2
#define fEM_B3MC02RSP	 BUFFER[2236]	//(B3MC02RSP) Стартовая координата штока ИС2
#define idfEM_B3MC02RSP	 635	//(B3MC02RSP) Стартовая координата штока ИС2
#define fEM_B3MV02RSP	 BUFFER[2241]	//(B3MV02RSP) Стартовая скорость движения  ИС2
#define idfEM_B3MV02RSP	 636	//(B3MV02RSP) Стартовая скорость движения  ИС2
#define fEM_B8MC01RSP	 BUFFER[2246]	//(B8MC01RSP) Стартовая координата АЗ2
#define idfEM_B8MC01RSP	 637	//(B8MC01RSP) Стартовая координата АЗ2
#define fEM_B8MV01RSP	 BUFFER[2251]	//(B8MV01RSP) Стартовая скорость АЗ2
#define idfEM_B8MV01RSP	 638	//(B8MV01RSP) Стартовая скорость АЗ2
#define fEM_A8MC01RSP	 BUFFER[2256]	//(A8MC01RSP) Стартовая координата ДС2
#define idfEM_A8MC01RSP	 639	//(A8MC01RSP) Стартовая координата ДС2
#define fEM_A8MV01RSP	 BUFFER[2261]	//(A8MV01RSP) Стартовая скорость ДС2
#define idfEM_A8MV01RSP	 640	//(A8MV01RSP) Стартовая скорость ДС2
#define fEM_A6MC01RSP	 BUFFER[2266]	//(A6MC01RSP) Стартовая координата БЗ1
#define idfEM_A6MC01RSP	 641	//(A6MC01RSP) Стартовая координата БЗ1
#define fEM_A6MV01RSP	 BUFFER[2271]	//(A6MV01RSP) Стартовая скорость БЗ1
#define idfEM_A6MV01RSP	 642	//(A6MV01RSP) Стартовая скорость БЗ1
#define fEM_B6MC01RSP	 BUFFER[2276]	//(B6MC01RSP) Стартовая координата БЗ2
#define idfEM_B6MC01RSP	 643	//(B6MC01RSP) Стартовая координата БЗ2
#define fEM_B6MV01RSP	 BUFFER[2281]	//(B6MV01RSP) Стартовая скорость БЗ2
#define idfEM_B6MV01RSP	 644	//(B6MV01RSP) Стартовая скорость БЗ2
#define fEM_R3UC01RSP	 BUFFER[2286]	//(R3UC01RSP) Стартовая координата Гомогенных дверей
#define idfEM_R3UC01RSP	 645	//(R3UC01RSP) Стартовая координата Гомогенных дверей
#define fEM_R3UV01RSP	 BUFFER[2291]	//(R3UV01RSP) Стартовая скорость Гомогенных дверей
#define idfEM_R3UV01RSP	 646	//(R3UV01RSP) Стартовая скорость Гомогенных дверей
#define fEM_R5UC01RSP	 BUFFER[2296]	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define idfEM_R5UC01RSP	 647	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define fEM_R5UV01RSP	 BUFFER[2301]	//(R5UV01RSP) Стартовая скорость Ворот отстойной зоны
#define idfEM_R5UV01RSP	 648	//(R5UV01RSP) Стартовая скорость Ворот отстойной зоны
#define fEM_R6UC01RSP	 BUFFER[2306]	//(R6UC01RSP) Стартовая координата Кран-балки
#define idfEM_R6UC01RSP	 649	//(R6UC01RSP) Стартовая координата Кран-балки
#define fEM_R6UV01RSP	 BUFFER[2311]	//(R6UV01RSP) Стартовая скорость Кран-балки
#define idfEM_R6UV01RSP	 650	//(R6UV01RSP) Стартовая скорость Кран-балки
#define fEM_R2MC01RSP	 BUFFER[2316]	//(R2MC01RSP) Стартовая координата МДЗ2
#define idfEM_R2MC01RSP	 651	//(R2MC01RSP) Стартовая координата МДЗ2
#define fEM_R2MV01RSP	 BUFFER[2321]	//(R2MV01RSP) Стартовая скорость МДЗ2
#define idfEM_R2MV01RSP	 652	//(R2MV01RSP) Стартовая скорость МДЗ2
#define fEM_R1MC01RSP	 BUFFER[2326]	//(R1MC01RSP) Стартовая координата МДЗ1
#define idfEM_R1MC01RSP	 653	//(R1MC01RSP) Стартовая координата МДЗ1
#define fEM_R1MV01RSP	 BUFFER[2331]	//(R1MV01RSP) Стартовая скорость МДЗ1
#define idfEM_R1MV01RSP	 654	//(R1MV01RSP) Стартовая скорость МДЗ1
#define fEM_A5MC01RSP	 BUFFER[2336]	//(A5MC01RSP) Стартовая координата НЛ1
#define idfEM_A5MC01RSP	 655	//(A5MC01RSP) Стартовая координата НЛ1
#define fEM_A5MV01RSP	 BUFFER[2341]	//(A5MV01RSP) Стартовая скорость НЛ1
#define idfEM_A5MV01RSP	 656	//(A5MV01RSP) Стартовая скорость НЛ1
#define fEM_B5MC01RSP	 BUFFER[2346]	//(B5MC01RSP) Стартовая координата НЛ2
#define idfEM_B5MC01RSP	 657	//(B5MC01RSP) Стартовая координата НЛ2
#define fEM_B5MV01RSP	 BUFFER[2351]	//(B5MV01RSP) Стартовая скорость НЛ2
#define idfEM_B5MV01RSP	 658	//(B5MV01RSP) Стартовая скорость НЛ2
#define fEM_A9MC01RSP	 BUFFER[2356]	//(A9MC01RSP) Стартовая координата НИ ДС1
#define idfEM_A9MC01RSP	 659	//(A9MC01RSP) Стартовая координата НИ ДС1
#define fEM_A9MV01RSP	 BUFFER[2361]	//(A9MV01RSP) Стартовая скорость НИ ДС1
#define idfEM_A9MV01RSP	 660	//(A9MV01RSP) Стартовая скорость НИ ДС1
#define fEM_B9MC01RSP	 BUFFER[2366]	//(B9MC01RSP) Стартовая координата НИ ДС2
#define idfEM_B9MC01RSP	 661	//(B9MC01RSP) Стартовая координата НИ ДС2
#define fEM_B9MV01RSP	 BUFFER[2371]	//(B9MV01RSP) Стартовая скорость НИ ДС2
#define idfEM_B9MV01RSP	 662	//(B9MV01RSP) Стартовая скорость НИ ДС2
#define fEM_A4MC01RSP	 BUFFER[2376]	//(A4MC01RSP) Стартовая координата НИ1
#define idfEM_A4MC01RSP	 663	//(A4MC01RSP) Стартовая координата НИ1
#define fEM_A4MV01RSP	 BUFFER[2381]	//(A4MV01RSP) Стартовая скорость НИ1
#define idfEM_A4MV01RSP	 664	//(A4MV01RSP) Стартовая скорость НИ1
#define fEM_B4MC01RSP	 BUFFER[2386]	//(B4MC01RSP) Стартовая координата НИ2
#define idfEM_B4MC01RSP	 665	//(B4MC01RSP) Стартовая координата НИ2
#define fEM_B4MV01RSP	 BUFFER[2391]	//(B4MV01RSP) Стартовая скорость НИ2
#define idfEM_B4MV01RSP	 666	//(B4MV01RSP) Стартовая скорость НИ2
#define fEM_R4MC01RSP	 BUFFER[2396]	//(R4MC01RSP) Стартовая координата тележки
#define idfEM_R4MC01RSP	 667	//(R4MC01RSP) Стартовая координата тележки
#define fEM_R4MV01RSP	 BUFFER[2401]	//(R4MV01RSP) Стартовая скорость тележки
#define idfEM_R4MV01RSP	 668	//(R4MV01RSP) Стартовая скорость тележки
#define fEM_A1MV01RC1	 BUFFER[2406]	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define idfEM_A1MV01RC1	 669	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define iEM_TERB7MS31LIM	 BUFFER[2411]	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define idiEM_TERB7MS31LIM	 670	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define iEM_TERA7MS31LIM	 BUFFER[2414]	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define idiEM_TERA7MS31LIM	 671	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define fEM_R7UY00RSS	 BUFFER[2417]	//(R7UY00RSS) Y-координата АЗ1 см
#define idfEM_R7UY00RSS	 672	//(R7UY00RSS) Y-координата АЗ1 см
#define iEM_TERA6VS12LIM	 BUFFER[2422]	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define idiEM_TERA6VS12LIM	 673	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define iEM_TERA6VS22LIM	 BUFFER[2425]	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define idiEM_TERA6VS22LIM	 674	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define iEM_TERB6VS12LIM	 BUFFER[2428]	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define idiEM_TERB6VS12LIM	 675	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define iEM_TERB6VS22LIM	 BUFFER[2431]	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define idiEM_TERB6VS22LIM	 676	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define iEM_TERA5VS22LIM	 BUFFER[2434]	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define idiEM_TERA5VS22LIM	 677	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define iEM_TERA5VS12LIM	 BUFFER[2437]	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define idiEM_TERA5VS12LIM	 678	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define iEM_TERB5VS12LIM	 BUFFER[2440]	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define idiEM_TERB5VS12LIM	 679	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define iEM_TERB5VS22LIM	 BUFFER[2443]	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define idiEM_TERB5VS22LIM	 680	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define iEM_TERR1VS12LIM	 BUFFER[2446]	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define idiEM_TERR1VS12LIM	 681	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define iEM_TERR1VS22LIM	 BUFFER[2449]	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define idiEM_TERR1VS22LIM	 682	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define iEM_TERR2VS12LIM	 BUFFER[2452]	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define idiEM_TERR2VS12LIM	 683	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define iEM_TERR2VS22LIM	 BUFFER[2455]	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define idiEM_TERR2VS22LIM	 684	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define iEM_TERR4VS12LDU	 BUFFER[2458]	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS12LDU	 685	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define iEM_TERR4VS22LDU	 BUFFER[2461]	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS22LDU	 686	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define fEM_R4UC23RIM	 BUFFER[2464]	//(R4UC23RIM) Y-координата АЗ1
#define idfEM_R4UC23RIM	 687	//(R4UC23RIM) Y-координата АЗ1
#define fEM_A0UX13RSS	 BUFFER[2469]	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define idfEM_A0UX13RSS	 688	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define fEM_A0UX14RSS	 BUFFER[2474]	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define idfEM_A0UX14RSS	 689	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define fEM_A0UX15RSS	 BUFFER[2479]	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define idfEM_A0UX15RSS	 690	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define fEM_R7UX13RSS	 BUFFER[2484]	//(R7UX13RSS) X-координата камеры R7IN51
#define idfEM_R7UX13RSS	 691	//(R7UX13RSS) X-координата камеры R7IN51
#define fEM_R7UX14RSS	 BUFFER[2489]	//(R7UX14RSS) X-координата камеры R7IN52
#define idfEM_R7UX14RSS	 692	//(R7UX14RSS) X-координата камеры R7IN52
#define fEM_R7UX15RSS	 BUFFER[2494]	//(R7UX15RSS) X-координата камеры R7IN53
#define idfEM_R7UX15RSS	 693	//(R7UX15RSS) X-координата камеры R7IN53
#define fEM_R7UY13RSS	 BUFFER[2499]	//(R7UY13RSS) Y-координата камеры R7IN51
#define idfEM_R7UY13RSS	 694	//(R7UY13RSS) Y-координата камеры R7IN51
#define fEM_R7UY14RSS	 BUFFER[2504]	//(R7UY14RSS) Y-координата камеры R7IN52
#define idfEM_R7UY14RSS	 695	//(R7UY14RSS) Y-координата камеры R7IN52
#define fEM_R7UY15RSS	 BUFFER[2509]	//(R7UY15RSS) Y-координата камеры R7IN53
#define idfEM_R7UY15RSS	 696	//(R7UY15RSS) Y-координата камеры R7IN53
#define fEM_R7UX16RSS	 BUFFER[2514]	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
#define idfEM_R7UX16RSS	 697	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
#define bFirstEnterFlag	 BUFFER[2519]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 698	//(bFirstEnterFlag) 
#define internal1_m906_Chim0	 BUFFER[2521]	//(internal1_m906_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m906_Chim0	 699	//(internal1_m906_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m896_Chim0	 BUFFER[2526]	//(internal1_m896_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m896_Chim0	 700	//(internal1_m896_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m888_Chim0	 BUFFER[2531]	//(internal1_m888_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m888_Chim0	 701	//(internal1_m888_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m843_Out10	 BUFFER[2536]	//(internal1_m843_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m843_Out10	 702	//(internal1_m843_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m842_Out10	 BUFFER[2538]	//(internal1_m842_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m842_Out10	 703	//(internal1_m842_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1026_Out10	 BUFFER[2540]	//(internal1_m1026_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1026_Out10	 704	//(internal1_m1026_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1025_Out10	 BUFFER[2542]	//(internal1_m1025_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1025_Out10	 705	//(internal1_m1025_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1024_Out10	 BUFFER[2544]	//(internal1_m1024_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1024_Out10	 706	//(internal1_m1024_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1023_Out10	 BUFFER[2546]	//(internal1_m1023_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1023_Out10	 707	//(internal1_m1023_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m705_Out10	 BUFFER[2548]	//(internal1_m705_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m705_Out10	 708	//(internal1_m705_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m704_Out10	 BUFFER[2550]	//(internal1_m704_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m704_Out10	 709	//(internal1_m704_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m683_Out10	 BUFFER[2552]	//(internal1_m683_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m683_Out10	 710	//(internal1_m683_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m682_Out10	 BUFFER[2554]	//(internal1_m682_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m682_Out10	 711	//(internal1_m682_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m703_Out10	 BUFFER[2556]	//(internal1_m703_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m703_Out10	 712	//(internal1_m703_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m702_Out10	 BUFFER[2558]	//(internal1_m702_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m702_Out10	 713	//(internal1_m702_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m681_Out10	 BUFFER[2560]	//(internal1_m681_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m681_Out10	 714	//(internal1_m681_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m680_Out10	 BUFFER[2562]	//(internal1_m680_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m680_Out10	 715	//(internal1_m680_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m535_Out10	 BUFFER[2564]	//(internal1_m535_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m535_Out10	 716	//(internal1_m535_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m554_Out10	 BUFFER[2566]	//(internal1_m554_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m554_Out10	 717	//(internal1_m554_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m417_Out10	 BUFFER[2568]	//(internal1_m417_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m417_Out10	 718	//(internal1_m417_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m494_q0	 BUFFER[2570]	//(internal1_m494_q0) q0 - внутренний параметр
#define idinternal1_m494_q0	 719	//(internal1_m494_q0) q0 - внутренний параметр
#define internal1_m495_q0	 BUFFER[2572]	//(internal1_m495_q0) q0 - внутренний параметр
#define idinternal1_m495_q0	 720	//(internal1_m495_q0) q0 - внутренний параметр
#define internal1_m480_q0	 BUFFER[2574]	//(internal1_m480_q0) q0 - внутренний параметр
#define idinternal1_m480_q0	 721	//(internal1_m480_q0) q0 - внутренний параметр
#define internal1_m481_q0	 BUFFER[2576]	//(internal1_m481_q0) q0 - внутренний параметр
#define idinternal1_m481_q0	 722	//(internal1_m481_q0) q0 - внутренний параметр
#define internal1_m656_tx	 BUFFER[2578]	//(internal1_m656_tx) tx - время накопленное сек
#define idinternal1_m656_tx	 723	//(internal1_m656_tx) tx - время накопленное сек
#define internal1_m656_y0	 BUFFER[2583]	//(internal1_m656_y0) y0
#define idinternal1_m656_y0	 724	//(internal1_m656_y0) y0
#define internal1_m644_tx	 BUFFER[2584]	//(internal1_m644_tx) tx - время накопленное сек
#define idinternal1_m644_tx	 725	//(internal1_m644_tx) tx - время накопленное сек
#define internal1_m644_y0	 BUFFER[2589]	//(internal1_m644_y0) y0
#define idinternal1_m644_y0	 726	//(internal1_m644_y0) y0
#define internal1_m630_tx	 BUFFER[2590]	//(internal1_m630_tx) tx - время накопленное сек
#define idinternal1_m630_tx	 727	//(internal1_m630_tx) tx - время накопленное сек
#define internal1_m630_y0	 BUFFER[2595]	//(internal1_m630_y0) y0
#define idinternal1_m630_y0	 728	//(internal1_m630_y0) y0
#define internal1_m628_tx	 BUFFER[2596]	//(internal1_m628_tx) tx - время накопленное сек
#define idinternal1_m628_tx	 729	//(internal1_m628_tx) tx - время накопленное сек
#define internal1_m628_y0	 BUFFER[2601]	//(internal1_m628_y0) y0
#define idinternal1_m628_y0	 730	//(internal1_m628_y0) y0
#define internal1_m214_Out10	 BUFFER[2602]	//(internal1_m214_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m214_Out10	 731	//(internal1_m214_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m231_Out10	 BUFFER[2604]	//(internal1_m231_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m231_Out10	 732	//(internal1_m231_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m41_Out10	 BUFFER[2606]	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m41_Out10	 733	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m56_Out10	 BUFFER[2608]	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m56_Out10	 734	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m997_Out10	 BUFFER[2610]	//(internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m997_Out10	 735	//(internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m994_Out10	 BUFFER[2612]	//(internal1_m994_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m994_Out10	 736	//(internal1_m994_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m993_Out10	 BUFFER[2614]	//(internal1_m993_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m993_Out10	 737	//(internal1_m993_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m996_Xtek0	 BUFFER[2616]	//(internal1_m996_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m996_Xtek0	 738	//(internal1_m996_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m979_Xtek0	 BUFFER[2621]	//(internal1_m979_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m979_Xtek0	 739	//(internal1_m979_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m980_Out10	 BUFFER[2626]	//(internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m980_Out10	 740	//(internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m977_Out10	 BUFFER[2628]	//(internal1_m977_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m977_Out10	 741	//(internal1_m977_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m976_Out10	 BUFFER[2630]	//(internal1_m976_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m976_Out10	 742	//(internal1_m976_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1064_Out10	 BUFFER[2632]	//(internal1_m1064_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1064_Out10	 743	//(internal1_m1064_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1045_Out10	 BUFFER[2634]	//(internal1_m1045_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1045_Out10	 744	//(internal1_m1045_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1044_Out10	 BUFFER[2636]	//(internal1_m1044_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1044_Out10	 745	//(internal1_m1044_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1043_Out10	 BUFFER[2638]	//(internal1_m1043_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1043_Out10	 746	//(internal1_m1043_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m864_Out10	 BUFFER[2640]	//(internal1_m864_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m864_Out10	 747	//(internal1_m864_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m866_Out10	 BUFFER[2642]	//(internal1_m866_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m866_Out10	 748	//(internal1_m866_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m863_Out10	 BUFFER[2644]	//(internal1_m863_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m863_Out10	 749	//(internal1_m863_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m865_Out10	 BUFFER[2646]	//(internal1_m865_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m865_Out10	 750	//(internal1_m865_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m839_Out10	 BUFFER[2648]	//(internal1_m839_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m839_Out10	 751	//(internal1_m839_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m840_Out10	 BUFFER[2650]	//(internal1_m840_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m840_Out10	 752	//(internal1_m840_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m838_Out10	 BUFFER[2652]	//(internal1_m838_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m838_Out10	 753	//(internal1_m838_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m837_Out10	 BUFFER[2654]	//(internal1_m837_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m837_Out10	 754	//(internal1_m837_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1059_Out10	 BUFFER[2656]	//(internal1_m1059_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1059_Out10	 755	//(internal1_m1059_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1011_Out10	 BUFFER[2658]	//(internal1_m1011_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1011_Out10	 756	//(internal1_m1011_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1010_Out10	 BUFFER[2660]	//(internal1_m1010_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1010_Out10	 757	//(internal1_m1010_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1009_Out10	 BUFFER[2662]	//(internal1_m1009_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1009_Out10	 758	//(internal1_m1009_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1008_Out10	 BUFFER[2664]	//(internal1_m1008_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1008_Out10	 759	//(internal1_m1008_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1060_Out10	 BUFFER[2666]	//(internal1_m1060_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1060_Out10	 760	//(internal1_m1060_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1041_Out10	 BUFFER[2668]	//(internal1_m1041_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1041_Out10	 761	//(internal1_m1041_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m841_Out10	 BUFFER[2670]	//(internal1_m841_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m841_Out10	 762	//(internal1_m841_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1042_Out10	 BUFFER[2672]	//(internal1_m1042_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1042_Out10	 763	//(internal1_m1042_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1040_Out10	 BUFFER[2674]	//(internal1_m1040_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1040_Out10	 764	//(internal1_m1040_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1061_Out10	 BUFFER[2676]	//(internal1_m1061_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1061_Out10	 765	//(internal1_m1061_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1039_Out10	 BUFFER[2678]	//(internal1_m1039_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1039_Out10	 766	//(internal1_m1039_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1022_Out10	 BUFFER[2680]	//(internal1_m1022_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1022_Out10	 767	//(internal1_m1022_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1007_Out10	 BUFFER[2682]	//(internal1_m1007_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1007_Out10	 768	//(internal1_m1007_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m553_Out10	 BUFFER[2684]	//(internal1_m553_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m553_Out10	 769	//(internal1_m553_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m427_Xtek0	 BUFFER[2686]	//(internal1_m427_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m427_Xtek0	 770	//(internal1_m427_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m418_Out10	 BUFFER[2691]	//(internal1_m418_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m418_Out10	 771	//(internal1_m418_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m420_Out10	 BUFFER[2693]	//(internal1_m420_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m420_Out10	 772	//(internal1_m420_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m419_Out10	 BUFFER[2695]	//(internal1_m419_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m419_Out10	 773	//(internal1_m419_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m879_Out10	 BUFFER[2697]	//(internal1_m879_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m879_Out10	 774	//(internal1_m879_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m880_Out10	 BUFFER[2699]	//(internal1_m880_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m880_Out10	 775	//(internal1_m880_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m878_Out10	 BUFFER[2701]	//(internal1_m878_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m878_Out10	 776	//(internal1_m878_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1063_Out10	 BUFFER[2703]	//(internal1_m1063_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1063_Out10	 777	//(internal1_m1063_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m718_Out10	 BUFFER[2705]	//(internal1_m718_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m718_Out10	 778	//(internal1_m718_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m719_Out10	 BUFFER[2707]	//(internal1_m719_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m719_Out10	 779	//(internal1_m719_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m716_Out10	 BUFFER[2709]	//(internal1_m716_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m716_Out10	 780	//(internal1_m716_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m717_Out10	 BUFFER[2711]	//(internal1_m717_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m717_Out10	 781	//(internal1_m717_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m574_Out10	 BUFFER[2713]	//(internal1_m574_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m574_Out10	 782	//(internal1_m574_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m573_Out10	 BUFFER[2715]	//(internal1_m573_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m573_Out10	 783	//(internal1_m573_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m860_Xtek0	 BUFFER[2717]	//(internal1_m860_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m860_Xtek0	 784	//(internal1_m860_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m862_Xtek0	 BUFFER[2722]	//(internal1_m862_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m862_Xtek0	 785	//(internal1_m862_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m715_Out10	 BUFFER[2727]	//(internal1_m715_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m715_Out10	 786	//(internal1_m715_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m699_Out10	 BUFFER[2729]	//(internal1_m699_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m699_Out10	 787	//(internal1_m699_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m679_Out10	 BUFFER[2731]	//(internal1_m679_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m679_Out10	 788	//(internal1_m679_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m698_Out10	 BUFFER[2733]	//(internal1_m698_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m698_Out10	 789	//(internal1_m698_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m678_Out10	 BUFFER[2735]	//(internal1_m678_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m678_Out10	 790	//(internal1_m678_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m345_Out10	 BUFFER[2737]	//(internal1_m345_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m345_Out10	 791	//(internal1_m345_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m344_Out10	 BUFFER[2739]	//(internal1_m344_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m344_Out10	 792	//(internal1_m344_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m329_Out10	 BUFFER[2741]	//(internal1_m329_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m329_Out10	 793	//(internal1_m329_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m328_Out10	 BUFFER[2743]	//(internal1_m328_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m328_Out10	 794	//(internal1_m328_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m575_Out10	 BUFFER[2745]	//(internal1_m575_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m575_Out10	 795	//(internal1_m575_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m358_Out10	 BUFFER[2747]	//(internal1_m358_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m358_Out10	 796	//(internal1_m358_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m342_Xtek0	 BUFFER[2749]	//(internal1_m342_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m342_Xtek0	 797	//(internal1_m342_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m357_Out10	 BUFFER[2754]	//(internal1_m357_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m357_Out10	 798	//(internal1_m357_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m355_Out10	 BUFFER[2756]	//(internal1_m355_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m355_Out10	 799	//(internal1_m355_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m334_Xtek0	 BUFFER[2758]	//(internal1_m334_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m334_Xtek0	 800	//(internal1_m334_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m356_Out10	 BUFFER[2763]	//(internal1_m356_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m356_Out10	 801	//(internal1_m356_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m327_Out10	 BUFFER[2765]	//(internal1_m327_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m327_Out10	 802	//(internal1_m327_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m343_Out10	 BUFFER[2767]	//(internal1_m343_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m343_Out10	 803	//(internal1_m343_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m439_Out10	 BUFFER[2769]	//(internal1_m439_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m439_Out10	 804	//(internal1_m439_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m440_Xtek0	 BUFFER[2771]	//(internal1_m440_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m440_Xtek0	 805	//(internal1_m440_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m438_Out10	 BUFFER[2776]	//(internal1_m438_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m438_Out10	 806	//(internal1_m438_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m437_Out10	 BUFFER[2778]	//(internal1_m437_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m437_Out10	 807	//(internal1_m437_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m436_Out10	 BUFFER[2780]	//(internal1_m436_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m436_Out10	 808	//(internal1_m436_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1062_Out10	 BUFFER[2782]	//(internal1_m1062_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1062_Out10	 809	//(internal1_m1062_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m150_Out10	 BUFFER[2784]	//(internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m150_Out10	 810	//(internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m149_Out10	 BUFFER[2786]	//(internal1_m149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m149_Out10	 811	//(internal1_m149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m203_tx	 BUFFER[2788]	//(internal1_m203_tx) tx - внутренний параметр
#define idinternal1_m203_tx	 812	//(internal1_m203_tx) tx - внутренний параметр
#define internal1_m25_tx	 BUFFER[2791]	//(internal1_m25_tx) tx - внутренний параметр
#define idinternal1_m25_tx	 813	//(internal1_m25_tx) tx - внутренний параметр
#define internal1_m486_Pav0	 BUFFER[2794]	//(internal1_m486_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m486_Pav0	 814	//(internal1_m486_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m486_Zav0	 BUFFER[2796]	//(internal1_m486_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m486_Zav0	 815	//(internal1_m486_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m486_Pv0	 BUFFER[2798]	//(internal1_m486_Pv0)  - Пер. выключатель механизма
#define idinternal1_m486_Pv0	 816	//(internal1_m486_Pv0)  - Пер. выключатель механизма
#define internal1_m486_Zv0	 BUFFER[2800]	//(internal1_m486_Zv0)  - Зад. выключатель механизма
#define idinternal1_m486_Zv0	 817	//(internal1_m486_Zv0)  - Зад. выключатель механизма
#define internal1_m486_RA00	 BUFFER[2802]	//(internal1_m486_RA00)  - последнее задание вперед
#define idinternal1_m486_RA00	 818	//(internal1_m486_RA00)  - последнее задание вперед
#define internal1_m486_RA10	 BUFFER[2804]	//(internal1_m486_RA10)  - последнее задание назад
#define idinternal1_m486_RA10	 819	//(internal1_m486_RA10)  - последнее задание назад
#define internal1_m486_MyFirstEnterFlag	 BUFFER[2806]	//(internal1_m486_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m486_MyFirstEnterFlag	 820	//(internal1_m486_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m498_Pav0	 BUFFER[2808]	//(internal1_m498_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m498_Pav0	 821	//(internal1_m498_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m498_Zav0	 BUFFER[2810]	//(internal1_m498_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m498_Zav0	 822	//(internal1_m498_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m498_Pv0	 BUFFER[2812]	//(internal1_m498_Pv0)  - Пер. выключатель механизма
#define idinternal1_m498_Pv0	 823	//(internal1_m498_Pv0)  - Пер. выключатель механизма
#define internal1_m498_Zv0	 BUFFER[2814]	//(internal1_m498_Zv0)  - Зад. выключатель механизма
#define idinternal1_m498_Zv0	 824	//(internal1_m498_Zv0)  - Зад. выключатель механизма
#define internal1_m498_RA00	 BUFFER[2816]	//(internal1_m498_RA00)  - последнее задание вперед
#define idinternal1_m498_RA00	 825	//(internal1_m498_RA00)  - последнее задание вперед
#define internal1_m498_RA10	 BUFFER[2818]	//(internal1_m498_RA10)  - последнее задание назад
#define idinternal1_m498_RA10	 826	//(internal1_m498_RA10)  - последнее задание назад
#define internal1_m498_MyFirstEnterFlag	 BUFFER[2820]	//(internal1_m498_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m498_MyFirstEnterFlag	 827	//(internal1_m498_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m484_Pav0	 BUFFER[2822]	//(internal1_m484_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m484_Pav0	 828	//(internal1_m484_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m484_Zav0	 BUFFER[2824]	//(internal1_m484_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m484_Zav0	 829	//(internal1_m484_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m484_Pv0	 BUFFER[2826]	//(internal1_m484_Pv0)  - Пер. выключатель механизма
#define idinternal1_m484_Pv0	 830	//(internal1_m484_Pv0)  - Пер. выключатель механизма
#define internal1_m484_Zv0	 BUFFER[2828]	//(internal1_m484_Zv0)  - Зад. выключатель механизма
#define idinternal1_m484_Zv0	 831	//(internal1_m484_Zv0)  - Зад. выключатель механизма
#define internal1_m484_RA00	 BUFFER[2830]	//(internal1_m484_RA00)  - последнее задание вперед
#define idinternal1_m484_RA00	 832	//(internal1_m484_RA00)  - последнее задание вперед
#define internal1_m484_RA10	 BUFFER[2832]	//(internal1_m484_RA10)  - последнее задание назад
#define idinternal1_m484_RA10	 833	//(internal1_m484_RA10)  - последнее задание назад
#define internal1_m484_MyFirstEnterFlag	 BUFFER[2834]	//(internal1_m484_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m484_MyFirstEnterFlag	 834	//(internal1_m484_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m634_Pav0	 BUFFER[2836]	//(internal1_m634_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m634_Pav0	 835	//(internal1_m634_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m634_Zav0	 BUFFER[2838]	//(internal1_m634_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m634_Zav0	 836	//(internal1_m634_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m634_Pv0	 BUFFER[2840]	//(internal1_m634_Pv0)  - Пер. выключатель механизма
#define idinternal1_m634_Pv0	 837	//(internal1_m634_Pv0)  - Пер. выключатель механизма
#define internal1_m634_Zv0	 BUFFER[2842]	//(internal1_m634_Zv0)  - Зад. выключатель механизма
#define idinternal1_m634_Zv0	 838	//(internal1_m634_Zv0)  - Зад. выключатель механизма
#define internal1_m634_RA00	 BUFFER[2844]	//(internal1_m634_RA00)  - последнее задание вперед
#define idinternal1_m634_RA00	 839	//(internal1_m634_RA00)  - последнее задание вперед
#define internal1_m634_RA10	 BUFFER[2846]	//(internal1_m634_RA10)  - последнее задание назад
#define idinternal1_m634_RA10	 840	//(internal1_m634_RA10)  - последнее задание назад
#define internal1_m634_MyFirstEnterFlag	 BUFFER[2848]	//(internal1_m634_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m634_MyFirstEnterFlag	 841	//(internal1_m634_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m632_Pav0	 BUFFER[2850]	//(internal1_m632_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m632_Pav0	 842	//(internal1_m632_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m632_Zav0	 BUFFER[2852]	//(internal1_m632_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m632_Zav0	 843	//(internal1_m632_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m632_Pv0	 BUFFER[2854]	//(internal1_m632_Pv0)  - Пер. выключатель механизма
#define idinternal1_m632_Pv0	 844	//(internal1_m632_Pv0)  - Пер. выключатель механизма
#define internal1_m632_Zv0	 BUFFER[2856]	//(internal1_m632_Zv0)  - Зад. выключатель механизма
#define idinternal1_m632_Zv0	 845	//(internal1_m632_Zv0)  - Зад. выключатель механизма
#define internal1_m632_RA00	 BUFFER[2858]	//(internal1_m632_RA00)  - последнее задание вперед
#define idinternal1_m632_RA00	 846	//(internal1_m632_RA00)  - последнее задание вперед
#define internal1_m632_RA10	 BUFFER[2860]	//(internal1_m632_RA10)  - последнее задание назад
#define idinternal1_m632_RA10	 847	//(internal1_m632_RA10)  - последнее задание назад
#define internal1_m632_MyFirstEnterFlag	 BUFFER[2862]	//(internal1_m632_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m632_MyFirstEnterFlag	 848	//(internal1_m632_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m618_Pav0	 BUFFER[2864]	//(internal1_m618_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m618_Pav0	 849	//(internal1_m618_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m618_Zav0	 BUFFER[2866]	//(internal1_m618_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m618_Zav0	 850	//(internal1_m618_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m618_Pv0	 BUFFER[2868]	//(internal1_m618_Pv0)  - Пер. выключатель механизма
#define idinternal1_m618_Pv0	 851	//(internal1_m618_Pv0)  - Пер. выключатель механизма
#define internal1_m618_Zv0	 BUFFER[2870]	//(internal1_m618_Zv0)  - Зад. выключатель механизма
#define idinternal1_m618_Zv0	 852	//(internal1_m618_Zv0)  - Зад. выключатель механизма
#define internal1_m618_RA00	 BUFFER[2872]	//(internal1_m618_RA00)  - последнее задание вперед
#define idinternal1_m618_RA00	 853	//(internal1_m618_RA00)  - последнее задание вперед
#define internal1_m618_RA10	 BUFFER[2874]	//(internal1_m618_RA10)  - последнее задание назад
#define idinternal1_m618_RA10	 854	//(internal1_m618_RA10)  - последнее задание назад
#define internal1_m618_MyFirstEnterFlag	 BUFFER[2876]	//(internal1_m618_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m618_MyFirstEnterFlag	 855	//(internal1_m618_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m617_Pav0	 BUFFER[2878]	//(internal1_m617_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m617_Pav0	 856	//(internal1_m617_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m617_Zav0	 BUFFER[2880]	//(internal1_m617_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m617_Zav0	 857	//(internal1_m617_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m617_Pv0	 BUFFER[2882]	//(internal1_m617_Pv0)  - Пер. выключатель механизма
#define idinternal1_m617_Pv0	 858	//(internal1_m617_Pv0)  - Пер. выключатель механизма
#define internal1_m617_Zv0	 BUFFER[2884]	//(internal1_m617_Zv0)  - Зад. выключатель механизма
#define idinternal1_m617_Zv0	 859	//(internal1_m617_Zv0)  - Зад. выключатель механизма
#define internal1_m617_RA00	 BUFFER[2886]	//(internal1_m617_RA00)  - последнее задание вперед
#define idinternal1_m617_RA00	 860	//(internal1_m617_RA00)  - последнее задание вперед
#define internal1_m617_RA10	 BUFFER[2888]	//(internal1_m617_RA10)  - последнее задание назад
#define idinternal1_m617_RA10	 861	//(internal1_m617_RA10)  - последнее задание назад
#define internal1_m617_MyFirstEnterFlag	 BUFFER[2890]	//(internal1_m617_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m617_MyFirstEnterFlag	 862	//(internal1_m617_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m664_y0	 BUFFER[2892]	//(internal1_m664_y0) y0 - внутренний параметр
#define idinternal1_m664_y0	 863	//(internal1_m664_y0) y0 - внутренний параметр
#define internal1_m825_Chim0	 BUFFER[2897]	//(internal1_m825_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m825_Chim0	 864	//(internal1_m825_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m816_Chim0	 BUFFER[2902]	//(internal1_m816_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m816_Chim0	 865	//(internal1_m816_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m808_Chim0	 BUFFER[2907]	//(internal1_m808_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m808_Chim0	 866	//(internal1_m808_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m799_Chim0	 BUFFER[2912]	//(internal1_m799_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m799_Chim0	 867	//(internal1_m799_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m790_Chim0	 BUFFER[2917]	//(internal1_m790_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m790_Chim0	 868	//(internal1_m790_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m782_Chim0	 BUFFER[2922]	//(internal1_m782_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m782_Chim0	 869	//(internal1_m782_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m773_Chim0	 BUFFER[2927]	//(internal1_m773_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m773_Chim0	 870	//(internal1_m773_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m764_Chim0	 BUFFER[2932]	//(internal1_m764_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m764_Chim0	 871	//(internal1_m764_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m756_Chim0	 BUFFER[2937]	//(internal1_m756_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m756_Chim0	 872	//(internal1_m756_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m747_Chim0	 BUFFER[2942]	//(internal1_m747_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m747_Chim0	 873	//(internal1_m747_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m738_Chim0	 BUFFER[2947]	//(internal1_m738_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m738_Chim0	 874	//(internal1_m738_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m730_Chim0	 BUFFER[2952]	//(internal1_m730_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m730_Chim0	 875	//(internal1_m730_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m604_Pav0	 BUFFER[2957]	//(internal1_m604_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m604_Pav0	 876	//(internal1_m604_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m604_Zav0	 BUFFER[2959]	//(internal1_m604_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m604_Zav0	 877	//(internal1_m604_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m604_Pv0	 BUFFER[2961]	//(internal1_m604_Pv0)  - Пер. выключатель механизма
#define idinternal1_m604_Pv0	 878	//(internal1_m604_Pv0)  - Пер. выключатель механизма
#define internal1_m604_Zv0	 BUFFER[2963]	//(internal1_m604_Zv0)  - Зад. выключатель механизма
#define idinternal1_m604_Zv0	 879	//(internal1_m604_Zv0)  - Зад. выключатель механизма
#define internal1_m604_RA00	 BUFFER[2965]	//(internal1_m604_RA00)  - последнее задание вперед
#define idinternal1_m604_RA00	 880	//(internal1_m604_RA00)  - последнее задание вперед
#define internal1_m604_RA10	 BUFFER[2967]	//(internal1_m604_RA10)  - последнее задание назад
#define idinternal1_m604_RA10	 881	//(internal1_m604_RA10)  - последнее задание назад
#define internal1_m604_MyFirstEnterFlag	 BUFFER[2969]	//(internal1_m604_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m604_MyFirstEnterFlag	 882	//(internal1_m604_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m589_Pav0	 BUFFER[2971]	//(internal1_m589_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m589_Pav0	 883	//(internal1_m589_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m589_Zav0	 BUFFER[2973]	//(internal1_m589_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m589_Zav0	 884	//(internal1_m589_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m589_Pv0	 BUFFER[2975]	//(internal1_m589_Pv0)  - Пер. выключатель механизма
#define idinternal1_m589_Pv0	 885	//(internal1_m589_Pv0)  - Пер. выключатель механизма
#define internal1_m589_Zv0	 BUFFER[2977]	//(internal1_m589_Zv0)  - Зад. выключатель механизма
#define idinternal1_m589_Zv0	 886	//(internal1_m589_Zv0)  - Зад. выключатель механизма
#define internal1_m589_RA00	 BUFFER[2979]	//(internal1_m589_RA00)  - последнее задание вперед
#define idinternal1_m589_RA00	 887	//(internal1_m589_RA00)  - последнее задание вперед
#define internal1_m589_RA10	 BUFFER[2981]	//(internal1_m589_RA10)  - последнее задание назад
#define idinternal1_m589_RA10	 888	//(internal1_m589_RA10)  - последнее задание назад
#define internal1_m589_MyFirstEnterFlag	 BUFFER[2983]	//(internal1_m589_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m589_MyFirstEnterFlag	 889	//(internal1_m589_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m469_Pav0	 BUFFER[2985]	//(internal1_m469_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m469_Pav0	 890	//(internal1_m469_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m469_Zav0	 BUFFER[2987]	//(internal1_m469_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m469_Zav0	 891	//(internal1_m469_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m469_Pv0	 BUFFER[2989]	//(internal1_m469_Pv0)  - Пер. выключатель механизма
#define idinternal1_m469_Pv0	 892	//(internal1_m469_Pv0)  - Пер. выключатель механизма
#define internal1_m469_Zv0	 BUFFER[2991]	//(internal1_m469_Zv0)  - Зад. выключатель механизма
#define idinternal1_m469_Zv0	 893	//(internal1_m469_Zv0)  - Зад. выключатель механизма
#define internal1_m469_RA00	 BUFFER[2993]	//(internal1_m469_RA00)  - последнее задание вперед
#define idinternal1_m469_RA00	 894	//(internal1_m469_RA00)  - последнее задание вперед
#define internal1_m469_RA10	 BUFFER[2995]	//(internal1_m469_RA10)  - последнее задание назад
#define idinternal1_m469_RA10	 895	//(internal1_m469_RA10)  - последнее задание назад
#define internal1_m469_MyFirstEnterFlag	 BUFFER[2997]	//(internal1_m469_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m469_MyFirstEnterFlag	 896	//(internal1_m469_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m454_Pav0	 BUFFER[2999]	//(internal1_m454_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m454_Pav0	 897	//(internal1_m454_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m454_Zav0	 BUFFER[3001]	//(internal1_m454_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m454_Zav0	 898	//(internal1_m454_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m454_Pv0	 BUFFER[3003]	//(internal1_m454_Pv0)  - Пер. выключатель механизма
#define idinternal1_m454_Pv0	 899	//(internal1_m454_Pv0)  - Пер. выключатель механизма
#define internal1_m454_Zv0	 BUFFER[3005]	//(internal1_m454_Zv0)  - Зад. выключатель механизма
#define idinternal1_m454_Zv0	 900	//(internal1_m454_Zv0)  - Зад. выключатель механизма
#define internal1_m454_RA00	 BUFFER[3007]	//(internal1_m454_RA00)  - последнее задание вперед
#define idinternal1_m454_RA00	 901	//(internal1_m454_RA00)  - последнее задание вперед
#define internal1_m454_RA10	 BUFFER[3009]	//(internal1_m454_RA10)  - последнее задание назад
#define idinternal1_m454_RA10	 902	//(internal1_m454_RA10)  - последнее задание назад
#define internal1_m454_MyFirstEnterFlag	 BUFFER[3011]	//(internal1_m454_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m454_MyFirstEnterFlag	 903	//(internal1_m454_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m510_Pav0	 BUFFER[3013]	//(internal1_m510_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m510_Pav0	 904	//(internal1_m510_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m510_Zav0	 BUFFER[3015]	//(internal1_m510_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m510_Zav0	 905	//(internal1_m510_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m510_Pv0	 BUFFER[3017]	//(internal1_m510_Pv0)  - Пер. выключатель механизма
#define idinternal1_m510_Pv0	 906	//(internal1_m510_Pv0)  - Пер. выключатель механизма
#define internal1_m510_Zv0	 BUFFER[3019]	//(internal1_m510_Zv0)  - Зад. выключатель механизма
#define idinternal1_m510_Zv0	 907	//(internal1_m510_Zv0)  - Зад. выключатель механизма
#define internal1_m510_RA00	 BUFFER[3021]	//(internal1_m510_RA00)  - последнее задание вперед
#define idinternal1_m510_RA00	 908	//(internal1_m510_RA00)  - последнее задание вперед
#define internal1_m510_RA10	 BUFFER[3023]	//(internal1_m510_RA10)  - последнее задание назад
#define idinternal1_m510_RA10	 909	//(internal1_m510_RA10)  - последнее задание назад
#define internal1_m510_MyFirstEnterFlag	 BUFFER[3025]	//(internal1_m510_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m510_MyFirstEnterFlag	 910	//(internal1_m510_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m405_Pav0	 BUFFER[3027]	//(internal1_m405_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m405_Pav0	 911	//(internal1_m405_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m405_Zav0	 BUFFER[3029]	//(internal1_m405_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m405_Zav0	 912	//(internal1_m405_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m405_Pv0	 BUFFER[3031]	//(internal1_m405_Pv0)  - Пер. выключатель механизма
#define idinternal1_m405_Pv0	 913	//(internal1_m405_Pv0)  - Пер. выключатель механизма
#define internal1_m405_Zv0	 BUFFER[3033]	//(internal1_m405_Zv0)  - Зад. выключатель механизма
#define idinternal1_m405_Zv0	 914	//(internal1_m405_Zv0)  - Зад. выключатель механизма
#define internal1_m405_RA00	 BUFFER[3035]	//(internal1_m405_RA00)  - последнее задание вперед
#define idinternal1_m405_RA00	 915	//(internal1_m405_RA00)  - последнее задание вперед
#define internal1_m405_RA10	 BUFFER[3037]	//(internal1_m405_RA10)  - последнее задание назад
#define idinternal1_m405_RA10	 916	//(internal1_m405_RA10)  - последнее задание назад
#define internal1_m405_MyFirstEnterFlag	 BUFFER[3039]	//(internal1_m405_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m405_MyFirstEnterFlag	 917	//(internal1_m405_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m389_Pav0	 BUFFER[3041]	//(internal1_m389_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m389_Pav0	 918	//(internal1_m389_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m389_Zav0	 BUFFER[3043]	//(internal1_m389_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m389_Zav0	 919	//(internal1_m389_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m389_Pv0	 BUFFER[3045]	//(internal1_m389_Pv0)  - Пер. выключатель механизма
#define idinternal1_m389_Pv0	 920	//(internal1_m389_Pv0)  - Пер. выключатель механизма
#define internal1_m389_Zv0	 BUFFER[3047]	//(internal1_m389_Zv0)  - Зад. выключатель механизма
#define idinternal1_m389_Zv0	 921	//(internal1_m389_Zv0)  - Зад. выключатель механизма
#define internal1_m389_RA00	 BUFFER[3049]	//(internal1_m389_RA00)  - последнее задание вперед
#define idinternal1_m389_RA00	 922	//(internal1_m389_RA00)  - последнее задание вперед
#define internal1_m389_RA10	 BUFFER[3051]	//(internal1_m389_RA10)  - последнее задание назад
#define idinternal1_m389_RA10	 923	//(internal1_m389_RA10)  - последнее задание назад
#define internal1_m389_MyFirstEnterFlag	 BUFFER[3053]	//(internal1_m389_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m389_MyFirstEnterFlag	 924	//(internal1_m389_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m372_Pav0	 BUFFER[3055]	//(internal1_m372_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m372_Pav0	 925	//(internal1_m372_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m372_Zav0	 BUFFER[3057]	//(internal1_m372_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m372_Zav0	 926	//(internal1_m372_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m372_Pv0	 BUFFER[3059]	//(internal1_m372_Pv0)  - Пер. выключатель механизма
#define idinternal1_m372_Pv0	 927	//(internal1_m372_Pv0)  - Пер. выключатель механизма
#define internal1_m372_Zv0	 BUFFER[3061]	//(internal1_m372_Zv0)  - Зад. выключатель механизма
#define idinternal1_m372_Zv0	 928	//(internal1_m372_Zv0)  - Зад. выключатель механизма
#define internal1_m372_RA00	 BUFFER[3063]	//(internal1_m372_RA00)  - последнее задание вперед
#define idinternal1_m372_RA00	 929	//(internal1_m372_RA00)  - последнее задание вперед
#define internal1_m372_RA10	 BUFFER[3065]	//(internal1_m372_RA10)  - последнее задание назад
#define idinternal1_m372_RA10	 930	//(internal1_m372_RA10)  - последнее задание назад
#define internal1_m372_MyFirstEnterFlag	 BUFFER[3067]	//(internal1_m372_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m372_MyFirstEnterFlag	 931	//(internal1_m372_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m918_Pav0	 BUFFER[3069]	//(internal1_m918_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m918_Pav0	 932	//(internal1_m918_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m918_Zav0	 BUFFER[3071]	//(internal1_m918_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m918_Zav0	 933	//(internal1_m918_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m918_Pv0	 BUFFER[3073]	//(internal1_m918_Pv0)  - Пер. выключатель механизма
#define idinternal1_m918_Pv0	 934	//(internal1_m918_Pv0)  - Пер. выключатель механизма
#define internal1_m918_Zv0	 BUFFER[3075]	//(internal1_m918_Zv0)  - Зад. выключатель механизма
#define idinternal1_m918_Zv0	 935	//(internal1_m918_Zv0)  - Зад. выключатель механизма
#define internal1_m918_RA00	 BUFFER[3077]	//(internal1_m918_RA00)  - последнее задание вперед
#define idinternal1_m918_RA00	 936	//(internal1_m918_RA00)  - последнее задание вперед
#define internal1_m918_RA10	 BUFFER[3079]	//(internal1_m918_RA10)  - последнее задание назад
#define idinternal1_m918_RA10	 937	//(internal1_m918_RA10)  - последнее задание назад
#define internal1_m918_MyFirstEnterFlag	 BUFFER[3081]	//(internal1_m918_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m918_MyFirstEnterFlag	 938	//(internal1_m918_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m188_C1	 BUFFER[3083]	//(internal1_m188_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m188_C1	 939	//(internal1_m188_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m188_C2	 BUFFER[3088]	//(internal1_m188_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m188_C2	 940	//(internal1_m188_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m188_C3	 BUFFER[3093]	//(internal1_m188_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m188_C3	 941	//(internal1_m188_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m188_C4	 BUFFER[3098]	//(internal1_m188_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m188_C4	 942	//(internal1_m188_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m188_C5	 BUFFER[3103]	//(internal1_m188_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m188_C5	 943	//(internal1_m188_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m188_C6	 BUFFER[3108]	//(internal1_m188_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m188_C6	 944	//(internal1_m188_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m188_N20	 BUFFER[3113]	//(internal1_m188_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m188_N20	 945	//(internal1_m188_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m188_C0	 BUFFER[3118]	//(internal1_m188_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define idinternal1_m188_C0	 946	//(internal1_m188_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define internal1_m188_ImpINI0	 BUFFER[3148]	//(internal1_m188_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m188_ImpINI0	 947	//(internal1_m188_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m188_MyFirstEnterFlag	 BUFFER[3150]	//(internal1_m188_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m188_MyFirstEnterFlag	 948	//(internal1_m188_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m307_Ppv0	 BUFFER[3152]	//(internal1_m307_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m307_Ppv0	 949	//(internal1_m307_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m307_Pav0	 BUFFER[3154]	//(internal1_m307_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m307_Pav0	 950	//(internal1_m307_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m307_Zav0	 BUFFER[3156]	//(internal1_m307_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m307_Zav0	 951	//(internal1_m307_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m307_RA00	 BUFFER[3158]	//(internal1_m307_RA00) RA00 - последнее задание вперед
#define idinternal1_m307_RA00	 952	//(internal1_m307_RA00) RA00 - последнее задание вперед
#define internal1_m307_RA10	 BUFFER[3160]	//(internal1_m307_RA10) RA10 - последнее задание назад
#define idinternal1_m307_RA10	 953	//(internal1_m307_RA10) RA10 - последнее задание назад
#define internal1_m307_RA50	 BUFFER[3162]	//(internal1_m307_RA50) Ra50 - последнее задание скорости
#define idinternal1_m307_RA50	 954	//(internal1_m307_RA50) Ra50 - последнее задание скорости
#define internal1_m307_fls	 BUFFER[3163]	//(internal1_m307_fls)  fls - флаг одношагового режима
#define idinternal1_m307_fls	 955	//(internal1_m307_fls)  fls - флаг одношагового режима
#define internal1_m307_flp	 BUFFER[3165]	//(internal1_m307_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m307_flp	 956	//(internal1_m307_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m307_MyFirstEnterFlag	 BUFFER[3167]	//(internal1_m307_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m307_MyFirstEnterFlag	 957	//(internal1_m307_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m130_Ppv0	 BUFFER[3169]	//(internal1_m130_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m130_Ppv0	 958	//(internal1_m130_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m130_Pav0	 BUFFER[3171]	//(internal1_m130_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m130_Pav0	 959	//(internal1_m130_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m130_Zav0	 BUFFER[3173]	//(internal1_m130_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m130_Zav0	 960	//(internal1_m130_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m130_RA00	 BUFFER[3175]	//(internal1_m130_RA00) RA00 - последнее задание вперед
#define idinternal1_m130_RA00	 961	//(internal1_m130_RA00) RA00 - последнее задание вперед
#define internal1_m130_RA10	 BUFFER[3177]	//(internal1_m130_RA10) RA10 - последнее задание назад
#define idinternal1_m130_RA10	 962	//(internal1_m130_RA10) RA10 - последнее задание назад
#define internal1_m130_RA50	 BUFFER[3179]	//(internal1_m130_RA50) Ra50 - последнее задание скорости
#define idinternal1_m130_RA50	 963	//(internal1_m130_RA50) Ra50 - последнее задание скорости
#define internal1_m130_fls	 BUFFER[3180]	//(internal1_m130_fls)  fls - флаг одношагового режима
#define idinternal1_m130_fls	 964	//(internal1_m130_fls)  fls - флаг одношагового режима
#define internal1_m130_flp	 BUFFER[3182]	//(internal1_m130_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m130_flp	 965	//(internal1_m130_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m130_MyFirstEnterFlag	 BUFFER[3184]	//(internal1_m130_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m130_MyFirstEnterFlag	 966	//(internal1_m130_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m272_Ppv0	 BUFFER[3186]	//(internal1_m272_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m272_Ppv0	 967	//(internal1_m272_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m272_Pav0	 BUFFER[3188]	//(internal1_m272_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m272_Pav0	 968	//(internal1_m272_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m272_Zav0	 BUFFER[3190]	//(internal1_m272_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m272_Zav0	 969	//(internal1_m272_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m272_RA00	 BUFFER[3192]	//(internal1_m272_RA00) RA00 - последнее задание вперед
#define idinternal1_m272_RA00	 970	//(internal1_m272_RA00) RA00 - последнее задание вперед
#define internal1_m272_RA10	 BUFFER[3194]	//(internal1_m272_RA10) RA10 - последнее задание назад
#define idinternal1_m272_RA10	 971	//(internal1_m272_RA10) RA10 - последнее задание назад
#define internal1_m272_RA50	 BUFFER[3196]	//(internal1_m272_RA50) Ra50 - последнее задание скорости
#define idinternal1_m272_RA50	 972	//(internal1_m272_RA50) Ra50 - последнее задание скорости
#define internal1_m272_fls	 BUFFER[3197]	//(internal1_m272_fls)  fls - флаг одношагового режима
#define idinternal1_m272_fls	 973	//(internal1_m272_fls)  fls - флаг одношагового режима
#define internal1_m272_flp	 BUFFER[3199]	//(internal1_m272_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m272_flp	 974	//(internal1_m272_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m272_MyFirstEnterFlag	 BUFFER[3201]	//(internal1_m272_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m272_MyFirstEnterFlag	 975	//(internal1_m272_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m96_Ppv0	 BUFFER[3203]	//(internal1_m96_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m96_Ppv0	 976	//(internal1_m96_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m96_Pav0	 BUFFER[3205]	//(internal1_m96_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m96_Pav0	 977	//(internal1_m96_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m96_Zav0	 BUFFER[3207]	//(internal1_m96_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m96_Zav0	 978	//(internal1_m96_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m96_RA00	 BUFFER[3209]	//(internal1_m96_RA00) RA00 - последнее задание вперед
#define idinternal1_m96_RA00	 979	//(internal1_m96_RA00) RA00 - последнее задание вперед
#define internal1_m96_RA10	 BUFFER[3211]	//(internal1_m96_RA10) RA10 - последнее задание назад
#define idinternal1_m96_RA10	 980	//(internal1_m96_RA10) RA10 - последнее задание назад
#define internal1_m96_RA50	 BUFFER[3213]	//(internal1_m96_RA50) Ra50 - последнее задание скорости
#define idinternal1_m96_RA50	 981	//(internal1_m96_RA50) Ra50 - последнее задание скорости
#define internal1_m96_fls	 BUFFER[3214]	//(internal1_m96_fls)  fls - флаг одношагового режима
#define idinternal1_m96_fls	 982	//(internal1_m96_fls)  fls - флаг одношагового режима
#define internal1_m96_flp	 BUFFER[3216]	//(internal1_m96_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m96_flp	 983	//(internal1_m96_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m96_MyFirstEnterFlag	 BUFFER[3218]	//(internal1_m96_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m96_MyFirstEnterFlag	 984	//(internal1_m96_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m236_Ppv0	 BUFFER[3220]	//(internal1_m236_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m236_Ppv0	 985	//(internal1_m236_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m236_Pav0	 BUFFER[3222]	//(internal1_m236_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m236_Pav0	 986	//(internal1_m236_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m236_Zav0	 BUFFER[3224]	//(internal1_m236_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m236_Zav0	 987	//(internal1_m236_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m236_RA00	 BUFFER[3226]	//(internal1_m236_RA00) RA00 - последнее задание вперед
#define idinternal1_m236_RA00	 988	//(internal1_m236_RA00) RA00 - последнее задание вперед
#define internal1_m236_RA10	 BUFFER[3228]	//(internal1_m236_RA10) RA10 - последнее задание назад
#define idinternal1_m236_RA10	 989	//(internal1_m236_RA10) RA10 - последнее задание назад
#define internal1_m236_RA50	 BUFFER[3230]	//(internal1_m236_RA50) Ra50 - последнее задание скорости
#define idinternal1_m236_RA50	 990	//(internal1_m236_RA50) Ra50 - последнее задание скорости
#define internal1_m236_fls	 BUFFER[3231]	//(internal1_m236_fls)  fls - флаг одношагового режима
#define idinternal1_m236_fls	 991	//(internal1_m236_fls)  fls - флаг одношагового режима
#define internal1_m236_flp	 BUFFER[3233]	//(internal1_m236_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m236_flp	 992	//(internal1_m236_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m236_MyFirstEnterFlag	 BUFFER[3235]	//(internal1_m236_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m236_MyFirstEnterFlag	 993	//(internal1_m236_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m60_Ppv0	 BUFFER[3237]	//(internal1_m60_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m60_Ppv0	 994	//(internal1_m60_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m60_Pav0	 BUFFER[3239]	//(internal1_m60_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m60_Pav0	 995	//(internal1_m60_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m60_Zav0	 BUFFER[3241]	//(internal1_m60_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m60_Zav0	 996	//(internal1_m60_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m60_RA00	 BUFFER[3243]	//(internal1_m60_RA00) RA00 - последнее задание вперед
#define idinternal1_m60_RA00	 997	//(internal1_m60_RA00) RA00 - последнее задание вперед
#define internal1_m60_RA10	 BUFFER[3245]	//(internal1_m60_RA10) RA10 - последнее задание назад
#define idinternal1_m60_RA10	 998	//(internal1_m60_RA10) RA10 - последнее задание назад
#define internal1_m60_RA50	 BUFFER[3247]	//(internal1_m60_RA50) Ra50 - последнее задание скорости
#define idinternal1_m60_RA50	 999	//(internal1_m60_RA50) Ra50 - последнее задание скорости
#define internal1_m60_fls	 BUFFER[3248]	//(internal1_m60_fls)  fls - флаг одношагового режима
#define idinternal1_m60_fls	 1000	//(internal1_m60_fls)  fls - флаг одношагового режима
#define internal1_m60_flp	 BUFFER[3250]	//(internal1_m60_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m60_flp	 1001	//(internal1_m60_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m60_MyFirstEnterFlag	 BUFFER[3252]	//(internal1_m60_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m60_MyFirstEnterFlag	 1002	//(internal1_m60_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m14_C1	 BUFFER[3254]	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m14_C1	 1003	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m14_C2	 BUFFER[3259]	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m14_C2	 1004	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m14_C3	 BUFFER[3264]	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m14_C3	 1005	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m14_C4	 BUFFER[3269]	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m14_C4	 1006	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m14_C5	 BUFFER[3274]	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m14_C5	 1007	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m14_C6	 BUFFER[3279]	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m14_C6	 1008	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m14_N20	 BUFFER[3284]	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m14_N20	 1009	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m14_C0	 BUFFER[3289]	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define idinternal1_m14_C0	 1010	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define internal1_m14_ImpINI0	 BUFFER[3319]	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m14_ImpINI0	 1011	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m14_MyFirstEnterFlag	 BUFFER[3321]	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m14_MyFirstEnterFlag	 1012	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &A1IE03LDU},	//( - , SCM) Движение ББ1 вперед (от БУШД)
	{ 2	,1	,1	, &B1IS12LDU},	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
	{ 3	,1	,1	, &B1IS11LDU},	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
	{ 4	,1	,1	, &B1IS21LDU},	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
	{ 5	,5	,1	, &B1IC01UDU},	//( - , SDu) Координата штока ББ2
	{ 6	,5	,1	, &A1IC01UDU},	//( - , SDu) Координата штока ББ1
	{ 7	,1	,1	, &A1IS12LDU},	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
	{ 8	,1	,1	, &A1IS11LDU},	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
	{ 9	,1	,1	, &A1IS21LDU},	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
	{ 10	,1	,1	, &B6IS21LDU},	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
	{ 11	,1	,1	, &B6IS11LDU},	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
	{ 12	,1	,1	, &A6IS21LDU},	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
	{ 13	,1	,1	, &A6IS11LDU},	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
	{ 14	,1	,1	, &A8IS12LDU},	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
	{ 15	,1	,1	, &A8IS22LDU},	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
	{ 16	,1	,1	, &B8IS12LDU},	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
	{ 17	,1	,1	, &B8IS22LDU},	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
	{ 18	,1	,1	, &R4IS12LDU},	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
	{ 19	,1	,1	, &B1IS11LIM},	//( - , SCM) Магнит ББ2 обесточен
	{ 20	,1	,1	, &A1IS32LIM},	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
	{ 21	,1	,1	, &A1IS11LIM},	//( - , SCM) Магнит ББ1 обесточен
	{ 22	,1	,1	, &A3AD34LDU},	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
	{ 23	,1	,1	, &R0IS02LDU},	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
	{ 24	,1	,1	, &R0EE04LZ2},	//( - , SBz2) Питание  АКНП4  отключить
	{ 25	,1	,1	, &R0EE03LZ2},	//( - , SBz2) Питание  АКНП3  отключить
	{ 26	,1	,1	, &R0EE02LZ2},	//( - , SBz2) Питание  АКНП  отключить
	{ 27	,1	,1	, &R0EE04LZ1},	//( - , SBz1) Питание  АКНП4  отключить
	{ 28	,1	,1	, &R0EE03LZ1},	//( - , SBz1) Питание  АКНП3  отключить
	{ 29	,1	,1	, &R0EE02LZ1},	//( - , SBz1) Питание  АКНП  отключить
	{ 30	,1	,1	, &R0EE01LZ2},	//( - , SBz2) Питание  АКНП1  отключить
	{ 31	,1	,1	, &R0EE01LZ1},	//( - , SBz1) Питание  АКНП1  отключить
	{ 32	,1	,1	, &B4IS10LDU},	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
	{ 33	,1	,1	, &A4IS10LDU},	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
	{ 34	,1	,1	, &B1IE04LDU},	//( - , SCM) Движение ББ2 назад (от БУШД)
	{ 35	,1	,1	, &B1IE03LDU},	//( - , SCM) Движение ББ2 вперед (от БУШД)
	{ 36	,1	,1	, &A1IE04LDU},	//( - , SCM) Движение ББ1 назад (от БУШД)
	{ 37	,1	,1	, &B2VP82LDU},	//( - , SCM) Давление ПОДЪЁМ РБ2 в норме
	{ 38	,3	,1	, &B2IP01IZ2},	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
	{ 39	,3	,1	, &B2IP01IZ1},	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
	{ 40	,5	,1	, &B2IC01UDU},	//( - , SDu) Координата штока РБ2
	{ 41	,1	,1	, &B2IS12LDU},	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
	{ 42	,1	,1	, &B2IS11LDU},	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
	{ 43	,1	,1	, &B2IS21LDU},	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
	{ 44	,1	,1	, &B9IS21LDU},	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
	{ 45	,1	,1	, &B9IS11LDU},	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
	{ 46	,1	,1	, &A9IS21LDU},	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
	{ 47	,1	,1	, &A9IS11LDU},	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
	{ 48	,1	,1	, &B5IS21LDU},	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
	{ 49	,1	,1	, &B5IS11LDU},	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
	{ 50	,1	,1	, &A5IS21LDU},	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
	{ 51	,1	,1	, &A5IS11LDU},	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
	{ 52	,1	,1	, &B0VP81LZZ},	//(do32_pti:100 - K30DO, - ) Давление АЗ2 в норме
	{ 53	,1	,1	, &A0VP81LZZ},	//(do32_pti:100 - K27DO, - ) Давление АЗ1 в норме
	{ 54	,5	,1	, &B8IC01UDU},	//( - , SDu) Координата АЗ2
	{ 55	,1	,1	, &R4IS22LDU},	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
	{ 56	,1	,1	, &R4IS21LDU},	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
	{ 57	,1	,1	, &R4IS11LDU},	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
	{ 58	,1	,1	, &B4VP82LDU},	//( - , SCM) Давление ПОДЪЁМ НИ2 в норме
	{ 59	,1	,1	, &A4VP82LDU},	//( - , SCM) Давление ПОДЪЁМ НИ1 в норме
	{ 60	,1	,1	, &R2IS21LDU},	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
	{ 61	,1	,1	, &R2IS11LDU},	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
	{ 62	,1	,1	, &R1IS21LDU},	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
	{ 63	,1	,1	, &R1IS11LDU},	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
	{ 64	,1	,1	, &B4IS21LDU},	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
	{ 65	,1	,1	, &B4IS11LDU},	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
	{ 66	,1	,1	, &R8IS11LDU},	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
	{ 67	,1	,1	, &A4IS21LDU},	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
	{ 68	,1	,1	, &A4IS11LDU},	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
	{ 69	,1	,1	, &R5IS21LDU},	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
	{ 70	,1	,1	, &R5IS11LDU},	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
	{ 71	,1	,1	, &R3IS21LDU},	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
	{ 72	,1	,1	, &R3IS11LDU},	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
	{ 73	,8	,1	, &A0SN07RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
	{ 74	,8	,1	, &A0SN06RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
	{ 75	,8	,1	, &A0SN05RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
	{ 76	,8	,1	, &A0SN04RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
	{ 77	,8	,1	, &A0SN03RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
	{ 78	,8	,1	, &A0SN02RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
	{ 79	,3	,1	, &R0IS01FI0},	//( - , SBz1, SBz2, SDu, SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{ 80	,3	,1	, &A0IT03IRP},	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
	{ 81	,3	,1	, &B0IT03IRP},	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
	{ 82	,8	,1	, &R0IN03FI3},	//( - , SA3) Выход КНК53М Гц от ПТИ
	{ 83	,8	,1	, &R0IN02FI3},	//( - , SA3) Выход КНК15-1 Гц от ПТИ
	{ 84	,8	,1	, &R0IN03FI2},	//( - , SA2) Выход КНК53М Гц от ПТИ
	{ 85	,8	,1	, &R0IN07RIP},	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
	{ 86	,8	,1	, &R0IN06RIP},	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
	{ 87	,3	,1	, &TerR0IN06FRP},	//( - , - ) Неисправности СНМ-11 -1,2
	{ 88	,8	,1	, &R0IN03RIP},	//( - , SRP) Выход КНК53М Гц от ПТИ
	{ 89	,8	,1	, &R0IN02RIP},	//( - , SRP) Выход КНК15- Гц от ПТИ
	{ 90	,8	,1	, &R0IN01RIP},	//( - , SRP) Выход СНМ-11 Гц от ПТИ
	{ 91	,3	,1	, &A3IP02FDU},	//( - , SDu) Текущее давление ВЫСТРЕЛ ИС1
	{ 92	,3	,1	, &B3IP02FDU},	//( - , SDu) Текущее давление ВЫСТРЕЛ  ИС2
	{ 93	,3	,1	, &B2IP01FZ2},	//( - , SBz2) Текущее давление СБРОС РБ2
	{ 94	,3	,1	, &B2IP01FZ1},	//( - , SBz1) Текущее давление СБРОС РБ2
	{ 95	,3	,1	, &A2IP01FZ2},	//( - , SBz2) Текущее давление СБРОС РБ1
	{ 96	,3	,1	, &A2IP01FZ1},	//( - , SBz1) Текущее давление СБРОС РБ1
	{ 97	,3	,1	, &A0IT03FRP},	//( - , SRP) Температура АЗ1-3
	{ 98	,3	,1	, &A0IT02FZ2},	//( - , SBz2) Температура АЗ1-2
	{ 99	,3	,1	, &A0IT01FZ1},	//( - , SBz1) Температура АЗ1-1
	{ 100	,3	,1	, &B0IT03FRP},	//( - , SRP) Температура АЗ2-3
	{ 101	,3	,1	, &B0IT02FZ2},	//( - , SBz2) Температура АЗ2-2
	{ 102	,3	,1	, &B0IT01FZ1},	//( - , SBz1) Температура АЗ2-1
	{ 103	,8	,1	, &B0SN07RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
	{ 104	,8	,1	, &B0SN06RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
	{ 105	,8	,1	, &B0SN05RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
	{ 106	,8	,1	, &B0SN04RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
	{ 107	,8	,1	, &B0SN03RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
	{ 108	,8	,1	, &B0SN02RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
	{ 109	,1	,1	, &B5VS22LDU},	//( - , SCM) Движение НЛ2 в сторону НУ
	{ 110	,1	,1	, &A5VS12LDU},	//( - , SCM) Движение НЛ1 в сторону ВУ
	{ 111	,1	,1	, &A5VS22LDU},	//( - , SCM) Движение НЛ1 в сторону НУ
	{ 112	,1	,1	, &B6VS12LDU},	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
	{ 113	,1	,1	, &B6VS22LDU},	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
	{ 114	,1	,1	, &A6VS12LDU},	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
	{ 115	,1	,1	, &A6VS22LDU},	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
	{ 116	,1	,1	, &B8IS21LDU},	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
	{ 117	,1	,1	, &B8IS11LDU},	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
	{ 118	,1	,1	, &A1VP81LZZ},	//(do32_pti:100 - K28DO, - ) Давление СБРОС ББ1 в норме
	{ 119	,1	,1	, &B1VP81LZZ},	//(do32_pti:100 - K31DO, - ) Давление СБРОС ББ2 в норме
	{ 120	,1	,1	, &B2IS33LDU},	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
	{ 121	,8	,1	, &A0VN01RIM},	//( - , SCM) Период разгона  AЗ1
	{ 122	,1	,1	, &B2IS32LIM},	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
	{ 123	,1	,1	, &B2IS11LIM},	//( - , SCM) Магнит РБ2 обесточен
	{ 124	,1	,1	, &A2IS32LIM},	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
	{ 125	,1	,1	, &A2IS11LIM},	//( - , SCM) Магнит РБ1 обесточен
	{ 126	,1	,1	, &B1IS32LIM},	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
	{ 127	,8	,1	, &R0IN02FI2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{ 128	,8	,1	, &R0IN03FI1},	//( - , SA1) Выход КНК53М Гц от ПТИ
	{ 129	,8	,1	, &R0IN02FI1},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{ 130	,8	,1	, &R0IN03FI4},	//( - , SA4) Выход КНК53М Гц от ПТИ
	{ 131	,8	,1	, &R0IN02FI4},	//( - , SA4) Выход КНК15-1 Гц от ПТИ
	{ 132	,8	,1	, &R0IN01FI3},	//( - , SA3) Выход СНМ-11 Гц от ПТИ
	{ 133	,8	,1	, &R0IN01FI2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{ 134	,8	,1	, &R0IN01FI4},	//( - , SA4) Выход СНМ-11 Гц от ПТИ
	{ 135	,8	,1	, &R0IN01FI1},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{ 136	,1	,1	, &B7AP31LDU},	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
	{ 137	,1	,1	, &A7AP31LDU},	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
	{ 138	,1	,1	, &R4VS12LDU},	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
	{ 139	,1	,1	, &R4VS22LDU},	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
	{ 140	,1	,1	, &R1VS12LDU},	//( - , SCM) Движение МДЗ1 в сторону ВУ
	{ 141	,1	,1	, &R2VS12LDU},	//( - , SCM) Движение МДЗ2 в сторону ВУ
	{ 142	,1	,1	, &R2VS22LDU},	//( - , SCM) Движение МДЗ2 в сторону НУ
	{ 143	,1	,1	, &R1VS22LDU},	//( - , SCM) Движение МДЗ1 в сторону НУ
	{ 144	,1	,1	, &B5VS12LDU},	//( - , SCM) Движение НЛ2 в сторону ВУ
	{ 145	,1	,1	, &A8AD20LDU},	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
	{ 146	,1	,1	, &A8AD10LDU},	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
	{ 147	,1	,1	, &B8AD20LDU},	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
	{ 148	,1	,1	, &B8AD10LDU},	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
	{ 149	,1	,1	, &R4AD20LDU},	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
	{ 150	,1	,1	, &R4AD10LDU},	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
	{ 151	,8	,1	, &B0SR01RIM},	//( - , SCM) Текущая реактивность AЗ2
	{ 152	,1	,1	, &B3AD33LDU},	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
	{ 153	,1	,1	, &B3AD05LDU},	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
	{ 154	,1	,1	, &B3AD04LDU},	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
	{ 155	,1	,1	, &B3AD03LDU},	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
	{ 156	,1	,1	, &B3AD02LDU},	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
	{ 157	,1	,1	, &B3AD01LDU},	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
	{ 158	,1	,1	, &B3AD21LDU},	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
	{ 159	,1	,1	, &B3AD11LDU},	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
	{ 160	,1	,1	, &A3AD33LDU},	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
	{ 161	,1	,1	, &A3AD05LDU},	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
	{ 162	,1	,1	, &A3AD04LDU},	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
	{ 163	,1	,1	, &R0AD14LDU},	//( - , SCM) Имитация срабатывания верхней АС II УР
	{ 164	,8	,1	, &R0SR02RIM},	//( - , SCM) Текущая мощность РУ (ватт)
	{ 165	,8	,1	, &R0CR02RIM},	//( - , SCM) Коэффициент 11 связи АЗ1,2
	{ 166	,8	,1	, &R0CR01RIM},	//( - , SCM) Коэффициент 12 связи АЗ1,2
	{ 167	,8	,1	, &B0SN08RIM},	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
	{ 168	,8	,1	, &A0SN08RIM},	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
	{ 169	,1	,1	, &B5AD20LDU},	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
	{ 170	,1	,1	, &B5AD10LDU},	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
	{ 171	,1	,1	, &A5AD20LDU},	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
	{ 172	,1	,1	, &A5AD10LDU},	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
	{ 173	,1	,1	, &R2AD20LDU},	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
	{ 174	,1	,1	, &R2AD10LDU},	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
	{ 175	,1	,1	, &R1AD20LDU},	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
	{ 176	,1	,1	, &R1AD10LDU},	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
	{ 177	,1	,1	, &B6AD20LDU},	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
	{ 178	,1	,1	, &B6AD10LDU},	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
	{ 179	,1	,1	, &A6AD20LDU},	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
	{ 180	,1	,1	, &A6AD10LDU},	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
	{ 181	,1	,1	, &A2AD01LDU},	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
	{ 182	,1	,1	, &A2AD21LDU},	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
	{ 183	,1	,1	, &A2AD11LDU},	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
	{ 184	,1	,1	, &B1AD05LDU},	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
	{ 185	,1	,1	, &B1AD04LDU},	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
	{ 186	,1	,1	, &B1AD03LDU},	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
	{ 187	,1	,1	, &B1AD02LDU},	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
	{ 188	,1	,1	, &B1AD01LDU},	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
	{ 189	,1	,1	, &B1AD21LDU},	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
	{ 190	,1	,1	, &B1AD11LDU},	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
	{ 191	,1	,1	, &A1AD05LDU},	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
	{ 192	,1	,1	, &A1AD04LDU},	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
	{ 193	,1	,1	, &A1AD03LDU},	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
	{ 194	,1	,1	, &A1AD02LDU},	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
	{ 195	,1	,1	, &A1AD01LDU},	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
	{ 196	,1	,1	, &A1AD21LDU},	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
	{ 197	,1	,1	, &A1AD11LDU},	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
	{ 198	,8	,1	, &A0SR01RIM},	//( - , SCM) Текущая реактивность AЗ1
	{ 199	,1	,1	, &A3AD03LDU},	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
	{ 200	,1	,1	, &A3AD02LDU},	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
	{ 201	,1	,1	, &A3AD01LDU},	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
	{ 202	,1	,1	, &A3AD21LDU},	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
	{ 203	,1	,1	, &A3AD11LDU},	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
	{ 204	,1	,1	, &B2AD33LDU},	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
	{ 205	,1	,1	, &B2AD05LDU},	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
	{ 206	,1	,1	, &B2AD04LDU},	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
	{ 207	,1	,1	, &B2AD03LDU},	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
	{ 208	,1	,1	, &B2AD02LDU},	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
	{ 209	,1	,1	, &B2AD01LDU},	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
	{ 210	,1	,1	, &B2AD21LDU},	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
	{ 211	,1	,1	, &B2AD11LDU},	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
	{ 212	,1	,1	, &A2AD33LDU},	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
	{ 213	,1	,1	, &A2AD05LDU},	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
	{ 214	,1	,1	, &A2AD04LDU},	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
	{ 215	,1	,1	, &A2AD03LDU},	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
	{ 216	,1	,1	, &A2AD02LDU},	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
	{ 217	,3	,1	, &B3IP02IDU},	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
	{ 218	,1	,1	, &A3IS33LDU},	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
	{ 219	,5	,1	, &A3IC01UDU},	//( - , SDu) Координата штока ИС1
	{ 220	,1	,1	, &A3IS31LDU},	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
	{ 221	,1	,1	, &A2VP82LDU},	//( - , SCM) Давление ПОДЪЁМ РБ1 в норме
	{ 222	,3	,1	, &A2IP01IZ2},	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
	{ 223	,3	,1	, &A2IP01IZ1},	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
	{ 224	,1	,1	, &B3IS21LDU},	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
	{ 225	,1	,1	, &A3IS21LDU},	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
	{ 226	,1	,1	, &A2IS33LDU},	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
	{ 227	,5	,1	, &A2IC01UDU},	//( - , SDu) Координата штока РБ1
	{ 228	,1	,1	, &A2IS12LDU},	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
	{ 229	,1	,1	, &A2IS11LDU},	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
	{ 230	,1	,1	, &A2IS21LDU},	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
	{ 231	,3	,1	, &B0IT02IZ2},	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
	{ 232	,3	,1	, &B0IT01IZ1},	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
	{ 233	,3	,1	, &A0IT02IZ2},	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
	{ 234	,3	,1	, &A0IT01IZ1},	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
	{ 235	,5	,1	, &A8IC01UDU},	//( - , SDu) Координата ДС2
	{ 236	,1	,1	, &R6IS68LZZ},	//(do32_pti:100 - K19DO, - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 237	,1	,1	, &R6IS67LZZ},	//(do32_pti:100 - K18DO, - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 238	,1	,1	, &R6IS66LZZ},	//(do32_pti:100 - K17DO, - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 239	,1	,1	, &R6IS65LDU},	//(do32_pti:160 - K32DO, - ) Исправность ВИП ССДИ-35 2канал
	{ 240	,1	,1	, &R6IS64LDU},	//(do32_pti:160 - K31DO, - ) Исправность ВИП ССДИ-35 1канал
	{ 241	,1	,1	, &R6IS63LDU},	//(do32_pti:160 - K30DO, - ) Исправность ВИП ССДИ-39 2канал
	{ 242	,1	,1	, &R6IS62LDU},	//(do32_pti:160 - K29DO, - ) Исправность ВИП ССДИ-39 1канал
	{ 243	,1	,1	, &B3IS22LDU},	//(do32_pti:100 - K12DO, - ) Приход на НУП ИС2
	{ 244	,1	,1	, &A3IS22LDU},	//(do32_pti:100 - K06DO, - ) Приход на НУП ИС1
	{ 245	,1	,1	, &B3IS11LDU},	//(do32_pti:100 - K11DO, - ) Приход на ВУ ИС2
	{ 246	,1	,1	, &A3IS11LDU},	//(do32_pti:100 - K05DO, - ) Приход на ВУ ИС1
	{ 247	,3	,1	, &A3IP02IDU},	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
	{ 248	,1	,1	, &B3VP81LDU},	//( - , SCM) Давление СПУСК ИС2 в норме
	{ 249	,1	,1	, &A3VP81LDU},	//( - , SCM) Давление СПУСК ИС1 в норме
	{ 250	,1	,1	, &B3IS33LDU},	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{ 251	,5	,1	, &B3IC01UDU},	//( - , SDu) Координата штока ИС2
	{ 252	,1	,1	, &B3IS31LDU},	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
	{ 253	,1	,1	, &B9AD10LDU},	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
	{ 254	,1	,1	, &R0MW13LP2},	//( - , SCM) Переключатель «СЕТЬ»
	{ 255	,1	,1	, &B3AD31LDU},	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
	{ 256	,1	,1	, &B2AD32LDU},	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
	{ 257	,1	,1	, &B2AD31LDU},	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
	{ 258	,1	,1	, &B1AD32LDU},	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
	{ 259	,1	,1	, &B1AD31LDU},	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
	{ 260	,1	,1	, &A3AD31LDU},	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
	{ 261	,1	,1	, &C1MD31LP1},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
	{ 262	,1	,1	, &C1MD31LP2},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
	{ 263	,1	,1	, &A1AD31LDU},	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
	{ 264	,1	,1	, &A1AD32LDU},	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
	{ 265	,1	,1	, &A2AD31LDU},	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
	{ 266	,1	,1	, &C2MD31LP1},	//( - , SCM) Кнопка «СБРОС РБ»
	{ 267	,1	,1	, &A2AD32LDU},	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
	{ 268	,1	,1	, &R0VZ71LZ2},	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
	{ 269	,1	,1	, &R0VZ71LZ1},	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
	{ 270	,1	,1	, &R8AD21LDU},	//(vds32_pti:310 - K31VDSR, - ) Запуск системы инициирования
	{ 271	,1	,1	, &R6IS21LDU},	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
	{ 272	,1	,1	, &B7AS31LDU},	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
	{ 273	,1	,1	, &A7AS31LDU},	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
	{ 274	,1	,1	, &B3IS35LDU},	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
	{ 275	,1	,1	, &B3AD34LDU},	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
	{ 276	,1	,1	, &A3IS35LDU},	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
	{ 277	,1	,1	, &R7II73LZ2},	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
	{ 278	,1	,1	, &R7II71LZ2},	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
	{ 279	,1	,1	, &R7II72LZ2},	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
	{ 280	,1	,1	, &R0AD16LDU},	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
	{ 281	,1	,1	, &R7II72LZ1},	//(do32_pti:100 - K25DO, - ) Сработала АС IУР (датчик 2)
	{ 282	,1	,1	, &R7II71LZ1},	//(do32_pti:100 - K24DO, - ) Сработала АС IУР (датчик 1)
	{ 283	,1	,1	, &R7II73LZ1},	//(do32_pti:100 - K26DO, - ) Сработала АС IIУР
	{ 284	,8	,1	, &R0SR01RIM},	//( - , SCM) Текущая реактивность PУ
	{ 285	,8	,1	, &R0ST01RIM},	//( - , SCM) Текущий период разгона РУ
	{ 286	,1	,1	, &A4AD10LDU},	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
	{ 287	,1	,1	, &B4AD10LDU},	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
	{ 288	,1	,1	, &A9AD10LDU},	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
	{ 289	,8	,1	, &fEM_R0UL01RIM},	//(R0UL01RIM) Среднее время генерации нейтронов
	{ 290	,8	,1	, &fEM_R0UN02RIM},	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{ 291	,8	,1	, &fEM_A1UR01RIM},	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{ 292	,8	,1	, &fEM_A1UR00RIM},	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{ 293	,8	,1	, &fEM_A3UR00RIM},	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{ 294	,8	,1	, &fEM_A3UR01RIM},	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{ 295	,8	,1	, &fEM_R0UT01RIM},	//(R0UT01RIM) Температурный коэффициент (долл)
	{ 296	,8	,1	, &fEM_R0UT02RIM},	//(R0UT02RIM) Масса топлива в АЗ
	{ 297	,8	,1	, &fEM_R0UT04RIM},	//(R0UT04RIM) Удельная теплоёмкость топлива
	{ 298	,8	,1	, &fEM_R0UT03RIM},	//(R0UT03RIM) Нормальная температура АЗ град
	{ 299	,8	,1	, &fEM_R0UT05RIM},	//(R0UT05RIM) Энергия деления ядра
	{ 300	,8	,1	, &fEM_R0UT06RIM},	//(R0UT06RIM) Конвекционное сопротивление при обдуве
	{ 301	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{ 302	,8	,1	, &fEM_A1UC04RIM},	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
	{ 303	,8	,1	, &fEM_A1UC05RIM},	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
	{ 304	,8	,1	, &fEM_A1UC06RIM},	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
	{ 305	,8	,1	, &fEM_A2UC06RIM},	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
	{ 306	,8	,1	, &fEM_A2UC05RIM},	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
	{ 307	,8	,1	, &fEM_A2UC04RIM},	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
	{ 308	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{ 309	,8	,1	, &fEM_A3UC06RIM},	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
	{ 310	,8	,1	, &fEM_A3UC05RIM},	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
	{ 311	,8	,1	, &fEM_A3UC04RIM},	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
	{ 312	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{ 313	,8	,1	, &fEM_R4UV80RDU},	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
	{ 314	,8	,1	, &fEM_R4UC10RIM},	//(R4UC10RIM) Координата верхних механических упоров тележки мм
	{ 315	,8	,1	, &fEM_R4UC20RIM},	//(R4UC20RIM) Координата нижних механических упоров тележки мм
	{ 316	,8	,1	, &fEM_B8UC21RIM},	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
	{ 317	,8	,1	, &fEM_B8UC20RIM},	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
	{ 318	,8	,1	, &fEM_B8UC11RIM},	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
	{ 319	,8	,1	, &fEM_B8UC10RIM},	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
	{ 320	,8	,1	, &fEM_B8UV80RDU},	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
	{ 321	,8	,1	, &fEM_A8UV80RDU},	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
	{ 322	,8	,1	, &fEM_A8UC10RIM},	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
	{ 323	,8	,1	, &fEM_A8UC11RIM},	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
	{ 324	,8	,1	, &fEM_A8UC20RIM},	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
	{ 325	,8	,1	, &fEM_A8UC21RIM},	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
	{ 326	,8	,1	, &fEM_A6UC10RIM},	//(A6UC10RIM) Время полного хода БЗ (сек)
	{ 327	,8	,1	, &fEM_R1UC10RIM},	//(R1UC10RIM) Время полного хода МДЗ сек
	{ 328	,8	,1	, &fEM_A5UC10RIM},	//(A5UC10RIM) Время полного хода НЛ сек
	{ 329	,8	,1	, &fEM_A0UN01RIM},	//(A0UN01RIM) Мощность источника нейтронов ИНИ
	{ 330	,8	,1	, &fEM_R4UC22RIM},	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
	{ 331	,8	,1	, &fEM_A1UG01RDU},	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
	{ 332	,8	,1	, &fEM_A2UG01RDU},	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
	{ 333	,8	,1	, &fEM_A3UG01RDU},	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
	{ 334	,8	,1	, &fEM_R7UC10RIM},	//(R7UC10RIM) X-координата КНК53М R7IN13 см
	{ 335	,8	,1	, &fEM_R7UC19RIM},	//(R7UC19RIM) Y-координата СНМ-11 (11) см
	{ 336	,8	,1	, &fEM_R7UI02RIM},	//(R7UI02RIM) Коэффициент усиления уровня радиации
	{ 337	,8	,1	, &fEM_R7UL01RIM},	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
	{ 338	,8	,1	, &fEM_A2UR00RIM},	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{ 339	,8	,1	, &fEM_A2UR01RIM},	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{ 340	,8	,1	, &fEM_A0UN02RIM},	//(A0UN02RIM) Мощность источника нейтронов с АНИ
	{ 341	,8	,1	, &fEM_R0UR30RIM},	//(R0UR30RIM) Реактивность вносимая образцами (долл)
	{ 342	,8	,1	, &fEM_R0UR01RIM},	//(R0UR01RIM) Стартовая отрицательная реактивность
	{ 343	,8	,1	, &fEM_R0UT02RDU},	//(R0UT02RDU) Верхний предел шкалы датчика температуры
	{ 344	,8	,1	, &fEM_R0UT01RDU},	//(R0UT01RDU) Нижний предел шкалы датчика температуры
	{ 345	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{ 346	,8	,1	, &fEM_A2UP03RDU},	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{ 347	,8	,1	, &fEM_A2UP04RDU},	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{ 348	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{ 349	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 350	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 351	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{ 352	,8	,1	, &fEM_R7UI74RIM},	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
	{ 353	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{ 354	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 355	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 356	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{ 357	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{ 358	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{ 359	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 360	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 361	,8	,1	, &fEM_A8UC08RDU},	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
	{ 362	,8	,1	, &fEM_B8UC08RDU},	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
	{ 363	,8	,1	, &fEM_R4UC08RDU},	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
	{ 364	,8	,1	, &fEM_R0UH01RSS},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
	{ 365	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 366	,8	,1	, &fEM_R7UX01RSS},	//(R7UX01RSS) X-координата камеры R7IN11
	{ 367	,8	,1	, &fEM_R7UX02RSS},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{ 368	,8	,1	, &fEM_R7UX04RSS},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{ 369	,8	,1	, &fEM_R7UX05RSS},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{ 370	,8	,1	, &fEM_R7UX06RSS},	//(R7UX06RSS) X-координата камеры R7IN23 (см)
	{ 371	,8	,1	, &fEM_R7UX07RSS},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{ 372	,8	,1	, &fEM_R7UX08RSS},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{ 373	,8	,1	, &fEM_R7UX09RSS},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{ 374	,8	,1	, &fEM_R7UY01RSS},	//(R7UY01RSS) Y-координата камеры R7IN11
	{ 375	,8	,1	, &fEM_R7UY02RSS},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{ 376	,8	,1	, &fEM_R7UY04RSS},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{ 377	,8	,1	, &fEM_R7UY05RSS},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{ 378	,8	,1	, &fEM_R7UY06RSS},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{ 379	,8	,1	, &fEM_R7UY07RSS},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{ 380	,8	,1	, &fEM_R7UY08RSS},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{ 381	,8	,1	, &fEM_R7UY09RSS},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{ 382	,8	,1	, &fEM_R7UX10RSS},	//(R7UX10RSS) X-координата камеры R7IN41
	{ 383	,8	,1	, &fEM_R7UX11RSS},	//(R7UX11RSS) X-координата камеры R7IN42
	{ 384	,8	,1	, &fEM_R7UX12RSS},	//(R7UX12RSS) X-координата камеры R7IN43
	{ 385	,8	,1	, &fEM_R7UY10RSS},	//(R7UY10RSS) Y-координата камеры R7IN41
	{ 386	,8	,1	, &fEM_R7UY11RSS},	//(R7UY11RSS) Y-координата камеры R7IN42
	{ 387	,8	,1	, &fEM_R7UY12RSS},	//(R7UY12RSS) Y-координата камеры R7IN43
	{ 388	,8	,1	, &fEM_A0UX01RSS},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{ 389	,8	,1	, &fEM_A0UX02RSS},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{ 390	,8	,1	, &fEM_A0UX03RSS},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{ 391	,8	,1	, &fEM_A0UX04RSS},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{ 392	,8	,1	, &fEM_A0UX05RSS},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{ 393	,8	,1	, &fEM_A0UX06RSS},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{ 394	,8	,1	, &fEM_A0UX07RSS},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{ 395	,8	,1	, &fEM_A0UX08RSS},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{ 396	,8	,1	, &fEM_A0UX09RSS},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{ 397	,8	,1	, &fEM_A0UX10RSS},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{ 398	,8	,1	, &fEM_A0UX11RSS},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{ 399	,8	,1	, &fEM_A0UX12RSS},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{ 400	,8	,1	, &fEM_B0UX01RSS},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{ 401	,8	,1	, &fEM_B0UX02RSS},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{ 402	,8	,1	, &fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{ 403	,8	,1	, &fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
	{ 404	,8	,1	, &fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{ 405	,8	,1	, &fEM_B0UX06RSS},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{ 406	,8	,1	, &fEM_B0UX07RSS},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{ 407	,8	,1	, &fEM_B0UX08RSS},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{ 408	,8	,1	, &fEM_B0UX09RSS},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{ 409	,8	,1	, &fEM_B0UX10RSS},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{ 410	,8	,1	, &fEM_B0UX11RSS},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{ 411	,8	,1	, &fEM_B0UX12RSS},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{ 412	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{ 413	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
	{ 414	,8	,1	, &fEM_R4US80RDU},	//(R4US80RDU) Тормозной путь тележки (мм)
	{ 415	,8	,1	, &fEM_R7UI71RIM},	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{ 416	,8	,1	, &fEM_R7UI72RIM},	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{ 417	,8	,1	, &fEM_R7UI73RIM},	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
	{ 418	,8	,1	, &fEM_A1UP01RIM},	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
	{ 419	,8	,1	, &fEM_A2UP01RIM},	//(A2UP01RIM) Текущее давление на сброс РБ
	{ 420	,8	,1	, &fEM_A0UP02RIM},	//(A0UP02RIM) Текущее давление в АЗ1,2
	{ 421	,8	,1	, &fEM_A3UP01RIM},	//(A3UP01RIM) Текущее давление на СПУСК ИС
	{ 422	,8	,1	, &fEM_A1UP82RIM},	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{ 423	,8	,1	, &fEM_A3UP02RDU},	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
	{ 424	,8	,1	, &fEM_A1UV02RIM},	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{ 425	,8	,1	, &fEM_A3UV02RIM},	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{ 426	,8	,1	, &fEM_A2UV02RIM},	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{ 427	,8	,1	, &fEM_B8US80RDU},	//(B8US80RDU) Тормозной путь АЗ2 (мм)
	{ 428	,8	,1	, &fEM_A8US80RDU},	//(A8US80RDU) Тормозной путь ДС2 (мм)
	{ 429	,8	,1	, &fEM_A6US80RDU},	//(A6US80RDU) Тормозной путь БЗ (мм)
	{ 430	,8	,1	, &fEM_A1US07RDU},	//(A1US07RDU) Постоянная времени масляного демпфера ББ
	{ 431	,8	,1	, &fEM_A2US07RDU},	//(A2US07RDU) Постоянная времени масляного демпфера РБ
	{ 432	,8	,1	, &fEM_A3US07RDU},	//(A3US07RDU) Постоянная времени масляного демпфера ИС
	{ 433	,8	,1	, &fEM_R7UI75RIM},	//(R7UI75RIM) Множитель к уровню радиации
	{ 434	,8	,1	, &fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{ 435	,8	,1	, &fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{ 436	,8	,1	, &fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{ 437	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 438	,8	,1	, &fEM_A4UL10RIM},	//(A4UL10RIM) Время полного перемещения НИ сек
	{ 439	,8	,1	, &fEM_A9UL10RIM},	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
	{ 440	,8	,1	, &fEM_R3UL10RIM},	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
	{ 441	,8	,1	, &fEM_R5UL10RIM},	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
	{ 442	,8	,1	, &fEM_R6UL10RIM},	//(R6UL10RIM) Время полного хода кран-балки сек
	{ 443	,1	,1	, &lEM_C1AD31LRP},	//(C1AD31LRP) Общий сброс от РПУ
	{ 444	,1	,1	, &lEM_R0IE01LRP},	//(R0IE01LRP) Отключение питание детекторов
	{ 445	,1	,1	, &lEM_R0IE02LRP},	//(R0IE02LRP) Отключить питание ПР, ПУ
	{ 446	,8	,1	, &fEM_A2UP02RIM},	//(A2UP02RIM) Текущее давление на подъём РБ
	{ 447	,8	,1	, &fEM_A2UP03RIM},	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
	{ 448	,8	,1	, &fEM_A0UP01RIM},	//(A0UP01RIM) Текущее давление в АЗ1,2
	{ 449	,8	,1	, &fEM_A3UP02RIM},	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
	{ 450	,8	,1	, &fEM_A4UP01RIM},	//(A4UP01RIM) Текущее давление на подъём НИ
	{ 451	,8	,1	, &fEM_A4UP02RIM},	//(A4UP02RIM) Нижняя граница давления на подъём НИ
	{ 452	,8	,1	, &fEM_R7UI76RIM},	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{ 453	,8	,1	, &fEM_R7UI77RIM},	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{ 454	,3	,1	, &iEM_TERBB1},	//(TERBB1) Неисправности  ББ1
	{ 455	,8	,1	, &fEM_A1MC02RC1},	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
	{ 456	,8	,1	, &fEM_A1MV02RC1},	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
	{ 457	,3	,1	, &iEM_TERBB2},	//(TERBB2) Неисправности  ББ2
	{ 458	,8	,1	, &fEM_B1MC02RC1},	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
	{ 459	,8	,1	, &fEM_B1MV02RC1},	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
	{ 460	,3	,1	, &iEM_TERRB2},	//(TERRB2) Неисправности  РБ2
	{ 461	,8	,1	, &fEM_B2MC02RC1},	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
	{ 462	,8	,1	, &fEM_B2MV02RC1},	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
	{ 463	,3	,1	, &iEM_TERRB1},	//(TERRB1) Неисправности  РБ1
	{ 464	,8	,1	, &fEM_A2MC02RC1},	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
	{ 465	,8	,1	, &fEM_A2MV02RC1},	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
	{ 466	,3	,1	, &iEM_TERIS2},	//(TERIS2) Неисправности  ИС2
	{ 467	,8	,1	, &fEM_B3MC02RC1},	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
	{ 468	,8	,1	, &fEM_B3MV02RC1},	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
	{ 469	,3	,1	, &iEM_TERIS1},	//(TERIS1) Неисправности  ИС1
	{ 470	,8	,1	, &fEM_A3MC02RC1},	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
	{ 471	,8	,1	, &fEM_A3MV02RC1},	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
	{ 472	,3	,1	, &iEM_TERA1IE04LDU},	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
	{ 473	,3	,1	, &iEM_TERA1IE03LDU},	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
	{ 474	,8	,1	, &fEM_A1MC01RC1},	//(A1MC01RC1) Заданная координата  ББ1 от ИС
	{ 475	,3	,1	, &iEM_TERB1IE03LDU},	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
	{ 476	,3	,1	, &iEM_TERB1IE04LDU},	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
	{ 477	,8	,1	, &fEM_B1MC01RC1},	//(B1MC01RC1) Заданная координата ББ2 от ИС
	{ 478	,8	,1	, &fEM_B1MV01RC1},	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
	{ 479	,8	,1	, &fEM_B2MC01RC1},	//(B2MC01RC1) Заданная координата РБ2 от ИС
	{ 480	,8	,1	, &fEM_B2MV01RC1},	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
	{ 481	,8	,1	, &fEM_A3MC01RC1},	//(A3MC01RC1) Заданная координата ИС1 от ИС
	{ 482	,8	,1	, &fEM_A3MV01RC1},	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
	{ 483	,8	,1	, &fEM_B3MC01RC1},	//(B3MC01RC1) Заданная координата ИС2 от ИС
	{ 484	,8	,1	, &fEM_B3MV01RC1},	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
	{ 485	,3	,1	, &iEM_TERA2SS21LIM},	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
	{ 486	,3	,1	, &iEM_TERA2SS12LIM},	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
	{ 487	,3	,1	, &iEM_TERR6SS21LIM},	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
	{ 488	,3	,1	, &iEM_TERA2VP82LIM},	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
	{ 489	,3	,1	, &iEM_TERA2SS11LIM},	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
	{ 490	,3	,1	, &iEM_TERB3SS21LIM},	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
	{ 491	,3	,1	, &iEM_TERA0MT01RIM},	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
	{ 492	,3	,1	, &iEM_TERB0MT01RIM},	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
	{ 493	,3	,1	, &iEM_TERA2SP01RIM},	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
	{ 494	,3	,1	, &iEM_TERB2SP01RIM},	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
	{ 495	,3	,1	, &iEM_TERB3SP02RIM},	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{ 496	,3	,1	, &iEM_TERA3SC01RIM},	//(TERA3SC01RIM) Искажение: Координата штока ИС1
	{ 497	,3	,1	, &iEM_TERA3VP81LIM},	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
	{ 498	,3	,1	, &iEM_TERA2SC01RIM},	//(TERA2SC01RIM) Искажение: Координата штока РБ1
	{ 499	,3	,1	, &iEM_TERA2SS33LIM},	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{ 500	,3	,1	, &iEM_TERA3SS21LIM},	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
	{ 501	,3	,1	, &iEM_TERA3SS33LIM},	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{ 502	,3	,1	, &iEM_TERA3SS31LIM},	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{ 503	,3	,1	, &iEM_TERB3SS31LIM},	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{ 504	,3	,1	, &iEM_TERB3SS33LIM},	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{ 505	,3	,1	, &iEM_TERB3SC01RIM},	//(TERB3SC01RIM) Искажение: Координата штока ИС2
	{ 506	,3	,1	, &iEM_TERA3SS11LIM},	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
	{ 507	,3	,1	, &iEM_TERB3SS11LIM},	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
	{ 508	,3	,1	, &iEM_TERR6IS64LIM},	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
	{ 509	,3	,1	, &iEM_TERB3SS22LIM},	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
	{ 510	,3	,1	, &iEM_TERA3SS22LIM},	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
	{ 511	,3	,1	, &iEM_TERA3SP02RIM},	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{ 512	,3	,1	, &iEM_TERR6IS62LIM},	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
	{ 513	,3	,1	, &iEM_TERR6IS66LIM},	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 514	,3	,1	, &iEM_TERR6IS67LIM},	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 515	,3	,1	, &iEM_TERA0VP81LIM},	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
	{ 516	,3	,1	, &iEM_TERB0VP81LIM},	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
	{ 517	,3	,1	, &iEM_TERR0VP81LIM},	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{ 518	,3	,1	, &iEM_TERR6IS68LIM},	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{ 519	,3	,1	, &iEM_TERR7SI74RIM},	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
	{ 520	,3	,1	, &iEM_TERA5SS21LIM},	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
	{ 521	,3	,1	, &iEM_TERB5SS11LIM},	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
	{ 522	,3	,1	, &iEM_TERA5SS11LIM},	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{ 523	,3	,1	, &iEM_TERA9SS11LIM},	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
	{ 524	,3	,1	, &iEM_TERB2SS11LIM},	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
	{ 525	,3	,1	, &iEM_TERB2SS12LIM},	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
	{ 526	,3	,1	, &iEM_TERB2SS21LIM},	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
	{ 527	,3	,1	, &iEM_TERR3SS11LIM},	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
	{ 528	,3	,1	, &iEM_TERB2SC01RIM},	//(TERB2SC01RIM) Искажение: Координата штока РБ2
	{ 529	,3	,1	, &iEM_TERR3SS21LIM},	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
	{ 530	,3	,1	, &iEM_TERR5SS11LIM},	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
	{ 531	,3	,1	, &iEM_TERA4SS11LIM},	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
	{ 532	,3	,1	, &iEM_TERR1SS11LIM},	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
	{ 533	,3	,1	, &iEM_TERR1SS21LIM},	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
	{ 534	,3	,1	, &iEM_TERR2SS11LIM},	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
	{ 535	,3	,1	, &iEM_TERR2SS21LIM},	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
	{ 536	,3	,1	, &iEM_TERA4VP82LIM},	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
	{ 537	,3	,1	, &iEM_TERB4SS21LIM},	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
	{ 538	,3	,1	, &iEM_TERR5SS21LIM},	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
	{ 539	,3	,1	, &iEM_TERB6SS21LIM},	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
	{ 540	,3	,1	, &iEM_TERB4SS11LIM},	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
	{ 541	,3	,1	, &iEM_TERA4SS21LIM},	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
	{ 542	,3	,1	, &iEM_TERA6MS11LIM},	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
	{ 543	,3	,1	, &iEM_TERA6SS21LIM},	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
	{ 544	,3	,1	, &iEM_TERB6SS11LIM},	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
	{ 545	,3	,1	, &iEM_TERR4SS11LIM},	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
	{ 546	,3	,1	, &iEM_TERR4MS21LIM},	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
	{ 547	,3	,1	, &iEM_TERR4SS12LIM},	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
	{ 548	,3	,1	, &iEM_TERR4SS22LIM},	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
	{ 549	,3	,1	, &iEM_TERR8SS11LIM},	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
	{ 550	,3	,1	, &iEM_TERB8SC01RIM},	//(TERB8SC01RIM) Искажение: Координата АЗ2
	{ 551	,3	,1	, &iEM_TERA8SC01RIM},	//(TERA8SC01RIM) Искажение: Координата ДС2
	{ 552	,3	,1	, &iEM_TERB8SS12LIM},	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
	{ 553	,3	,1	, &iEM_TERA8SS12LIM},	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
	{ 554	,3	,1	, &iEM_TERB8SS22LIM},	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
	{ 555	,3	,1	, &iEM_TERA8SS22LIM},	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
	{ 556	,3	,1	, &iEM_TERA9SS21LIM},	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
	{ 557	,3	,1	, &iEM_TERB9SS21LIM},	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
	{ 558	,3	,1	, &iEM_TERB9SS11LIM},	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
	{ 559	,3	,1	, &iEM_TERB5SS21LIM},	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
	{ 560	,3	,1	, &iEM_TERA1SS21LIM},	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
	{ 561	,3	,1	, &iEM_TERA1SS11LIM},	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
	{ 562	,3	,1	, &iEM_TERA1SC01RIM},	//(TERA1SC01RIM) Искажение: Координата штока ББ1
	{ 563	,3	,1	, &iEM_TERA1SS12LIM},	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
	{ 564	,3	,1	, &iEM_TERB1SS21LIM},	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
	{ 565	,3	,1	, &iEM_TERB1SS11LIM},	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
	{ 566	,3	,1	, &iEM_TERB1MC01RIM},	//(TERB1MC01RIM) Искажение: Координата штока ББ2
	{ 567	,3	,1	, &iEM_TERB1SS12LIM},	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
	{ 568	,3	,1	, &iEM_TERTLG},	//(TERTLG) Неисправности  тележки от ИС
	{ 569	,8	,1	, &fEM_R4MC01RC1},	//(R4MC01RC1) Заданная координата тележки от ИС
	{ 570	,8	,1	, &fEM_R4MV01RC1},	//(R4MV01RC1) Заданная скорость тележки от ИС
	{ 571	,3	,1	, &iEM_TERMAZ2},	//(TERMAZ2) Неисправности АЗ2 от ИС
	{ 572	,8	,1	, &fEM_B8MC01RC1},	//(B8MC01RC1) аданная координата АЗ2 от ИС
	{ 573	,8	,1	, &fEM_B8MV01RC1},	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
	{ 574	,3	,1	, &iEM_TERDS2},	//(TERDS2) Неисправности ДС2 от ИС
	{ 575	,8	,1	, &fEM_A8MC01RC1},	//(A8MC01RC1) Заданная координата ДС2 от ИС
	{ 576	,8	,1	, &fEM_A8MV01RC1},	//(A8MV01RC1) Заданная скорость ДС2 от ИС
	{ 577	,3	,1	, &iEM_TERBZ1},	//(TERBZ1) Неисправности БЗ1
	{ 578	,8	,1	, &fEM_A6MC01RC1},	//(A6MC01RC1) Заданная координата БЗ1 от ИС
	{ 579	,8	,1	, &fEM_A6MV01RC1},	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
	{ 580	,3	,1	, &iEM_TERBZ2},	//(TERBZ2) Неисправности БЗ2
	{ 581	,8	,1	, &fEM_B6MC01RC1},	//(B6MC01RC1) Заданная координата БЗ2 от ИС
	{ 582	,8	,1	, &fEM_B6MV01RC1},	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
	{ 583	,1	,1	, &lEM_R3AD10LC1},	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
	{ 584	,1	,1	, &lEM_R3AD20LC1},	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
	{ 585	,1	,1	, &lEM_R6AD10LC1},	//(R6AD10LC1) Выкатить кран-балку от ИС
	{ 586	,1	,1	, &lEM_R5AD10LC1},	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
	{ 587	,1	,1	, &lEM_R5AD20LC1},	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
	{ 588	,3	,1	, &iEM_TERMDZ2},	//(TERMDZ2) Неисправности МДЗ2
	{ 589	,8	,1	, &fEM_R2MC01RC1},	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
	{ 590	,8	,1	, &fEM_R2MV01RC1},	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
	{ 591	,3	,1	, &iEM_TERMDZ1},	//(TERMDZ1) Неисправности МДЗ1
	{ 592	,8	,1	, &fEM_R1MC01RC1},	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
	{ 593	,8	,1	, &fEM_R1MV01RC1},	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
	{ 594	,3	,1	, &iEM_TERNL1},	//(TERNL1) Неисправности НЛ1
	{ 595	,8	,1	, &fEM_A5MC01RC1},	//(A5MC01RC1) Заданная координата НЛ1 от ИС
	{ 596	,8	,1	, &fEM_A5MV01RC1},	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
	{ 597	,3	,1	, &iEM_TERNL2},	//(TERNL2) Неисправности НЛ2
	{ 598	,8	,1	, &fEM_B5MC01RC1},	//(B5MC01RC1) Заданная координата НЛ2 от ИС
	{ 599	,8	,1	, &fEM_B5MV01RC1},	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
	{ 600	,1	,1	, &lEM_R8AD10LC1},	//(R8AD10LC1) Установить аварийный НИ от ИС
	{ 601	,8	,1	, &fEM_A1UC08RIM},	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
	{ 602	,8	,1	, &fEM_A2UC08RIM},	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
	{ 603	,8	,1	, &fEM_A3UC08RIM},	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
	{ 604	,3	,1	, &iEM_TERB2SS33LIM},	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{ 605	,3	,1	, &iEM_TERA1VP81LIM},	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
	{ 606	,3	,1	, &iEM_TERB1VP81LIM},	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
	{ 607	,8	,1	, &fEM_A0UT03RSP},	//(A0UT03RSP) Стартовая  температура АЗ1 град
	{ 608	,8	,1	, &fEM_A0UR01RSP},	//(A0UR01RSP) Стартовая  реактивность АЗ1
	{ 609	,8	,1	, &fEM_A0UR02RSP},	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
	{ 610	,8	,1	, &fEM_B0UT03RSP},	//(B0UT03RSP) Стартовая  температура АЗ2 град
	{ 611	,8	,1	, &fEM_A1MC01RSP},	//(A1MC01RSP) Стартовая координата  ББ1
	{ 612	,8	,1	, &fEM_A1MC02RSP},	//(A1MC02RSP) Стартовая координата штока ББ1
	{ 613	,8	,1	, &fEM_A1MV01RSP},	//(A1MV01RSP) Стартовая скорость движения  ББ1
	{ 614	,8	,1	, &fEM_A1MV02RSP},	//(A1MV02RSP) Стартовая скорость движения  ББ1
	{ 615	,8	,1	, &fEM_B1MC01RSP},	//(B1MC01RSP) Стартовая координата  ББ2
	{ 616	,8	,1	, &fEM_B1MV01RSP},	//(B1MV01RSP) Стартовая скорость движения  ББ2
	{ 617	,8	,1	, &fEM_B1MC02RSP},	//(B1MC02RSP) Стартовая координата штока ББ2
	{ 618	,8	,1	, &fEM_B1MV02RSP},	//(B1MV02RSP) Стартовая скорость движения  ББ2
	{ 619	,8	,1	, &fEM_A2MC01RC1},	//(A2MC01RC1) Заданная координата РБ1 от ИС
	{ 620	,8	,1	, &fEM_A2MV01RC1},	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
	{ 621	,8	,1	, &fEM_A2MC01RSP},	//(A2MC01RSP) Стартовая координата  РБ1
	{ 622	,8	,1	, &fEM_A2MV01RSP},	//(A2MV01RSP) Стартовая скорость движения  РБ1
	{ 623	,8	,1	, &fEM_A2MC02RSP},	//(A2MC02RSP) Стартовая координата штока РБ1
	{ 624	,8	,1	, &fEM_A2MV02RSP},	//(A2MV02RSP) Стартовая скорость движения  РБ1
	{ 625	,8	,1	, &fEM_B2MC01RSP},	//(B2MC01RSP) Стартовая координата  РБ2
	{ 626	,8	,1	, &fEM_B2MV01RSP},	//(B2MV01RSP) Стартовая скорость движения  РБ2
	{ 627	,8	,1	, &fEM_B2MC02RSP},	//(B2MC02RSP) Стартовая координата штока РБ2
	{ 628	,8	,1	, &fEM_B2MV02RSP},	//(B2MV02RSP) Стартовая скорость движения  РБ2
	{ 629	,8	,1	, &fEM_A3MC01RSP},	//(A3MC01RSP) Стартовая координата  ИС1
	{ 630	,8	,1	, &fEM_A3MV01RSP},	//(A3MV01RSP) Стартовая скорость движения  ИС1
	{ 631	,8	,1	, &fEM_A3MC02RSP},	//(A3MC02RSP) Стартовая координата штока ИС1
	{ 632	,8	,1	, &fEM_A3MV02RSP},	//(A3MV02RSP) Стартовая скорость движения  ИС1
	{ 633	,8	,1	, &fEM_B3MC01RSP},	//(B3MC01RSP) Стартовая координата  ИС2
	{ 634	,8	,1	, &fEM_B3MV01RSP},	//(B3MV01RSP) Стартовая скорость движения  ИС2
	{ 635	,8	,1	, &fEM_B3MC02RSP},	//(B3MC02RSP) Стартовая координата штока ИС2
	{ 636	,8	,1	, &fEM_B3MV02RSP},	//(B3MV02RSP) Стартовая скорость движения  ИС2
	{ 637	,8	,1	, &fEM_B8MC01RSP},	//(B8MC01RSP) Стартовая координата АЗ2
	{ 638	,8	,1	, &fEM_B8MV01RSP},	//(B8MV01RSP) Стартовая скорость АЗ2
	{ 639	,8	,1	, &fEM_A8MC01RSP},	//(A8MC01RSP) Стартовая координата ДС2
	{ 640	,8	,1	, &fEM_A8MV01RSP},	//(A8MV01RSP) Стартовая скорость ДС2
	{ 641	,8	,1	, &fEM_A6MC01RSP},	//(A6MC01RSP) Стартовая координата БЗ1
	{ 642	,8	,1	, &fEM_A6MV01RSP},	//(A6MV01RSP) Стартовая скорость БЗ1
	{ 643	,8	,1	, &fEM_B6MC01RSP},	//(B6MC01RSP) Стартовая координата БЗ2
	{ 644	,8	,1	, &fEM_B6MV01RSP},	//(B6MV01RSP) Стартовая скорость БЗ2
	{ 645	,8	,1	, &fEM_R3UC01RSP},	//(R3UC01RSP) Стартовая координата Гомогенных дверей
	{ 646	,8	,1	, &fEM_R3UV01RSP},	//(R3UV01RSP) Стартовая скорость Гомогенных дверей
	{ 647	,8	,1	, &fEM_R5UC01RSP},	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
	{ 648	,8	,1	, &fEM_R5UV01RSP},	//(R5UV01RSP) Стартовая скорость Ворот отстойной зоны
	{ 649	,8	,1	, &fEM_R6UC01RSP},	//(R6UC01RSP) Стартовая координата Кран-балки
	{ 650	,8	,1	, &fEM_R6UV01RSP},	//(R6UV01RSP) Стартовая скорость Кран-балки
	{ 651	,8	,1	, &fEM_R2MC01RSP},	//(R2MC01RSP) Стартовая координата МДЗ2
	{ 652	,8	,1	, &fEM_R2MV01RSP},	//(R2MV01RSP) Стартовая скорость МДЗ2
	{ 653	,8	,1	, &fEM_R1MC01RSP},	//(R1MC01RSP) Стартовая координата МДЗ1
	{ 654	,8	,1	, &fEM_R1MV01RSP},	//(R1MV01RSP) Стартовая скорость МДЗ1
	{ 655	,8	,1	, &fEM_A5MC01RSP},	//(A5MC01RSP) Стартовая координата НЛ1
	{ 656	,8	,1	, &fEM_A5MV01RSP},	//(A5MV01RSP) Стартовая скорость НЛ1
	{ 657	,8	,1	, &fEM_B5MC01RSP},	//(B5MC01RSP) Стартовая координата НЛ2
	{ 658	,8	,1	, &fEM_B5MV01RSP},	//(B5MV01RSP) Стартовая скорость НЛ2
	{ 659	,8	,1	, &fEM_A9MC01RSP},	//(A9MC01RSP) Стартовая координата НИ ДС1
	{ 660	,8	,1	, &fEM_A9MV01RSP},	//(A9MV01RSP) Стартовая скорость НИ ДС1
	{ 661	,8	,1	, &fEM_B9MC01RSP},	//(B9MC01RSP) Стартовая координата НИ ДС2
	{ 662	,8	,1	, &fEM_B9MV01RSP},	//(B9MV01RSP) Стартовая скорость НИ ДС2
	{ 663	,8	,1	, &fEM_A4MC01RSP},	//(A4MC01RSP) Стартовая координата НИ1
	{ 664	,8	,1	, &fEM_A4MV01RSP},	//(A4MV01RSP) Стартовая скорость НИ1
	{ 665	,8	,1	, &fEM_B4MC01RSP},	//(B4MC01RSP) Стартовая координата НИ2
	{ 666	,8	,1	, &fEM_B4MV01RSP},	//(B4MV01RSP) Стартовая скорость НИ2
	{ 667	,8	,1	, &fEM_R4MC01RSP},	//(R4MC01RSP) Стартовая координата тележки
	{ 668	,8	,1	, &fEM_R4MV01RSP},	//(R4MV01RSP) Стартовая скорость тележки
	{ 669	,8	,1	, &fEM_A1MV01RC1},	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
	{ 670	,3	,1	, &iEM_TERB7MS31LIM},	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{ 671	,3	,1	, &iEM_TERA7MS31LIM},	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{ 672	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 см
	{ 673	,3	,1	, &iEM_TERA6VS12LIM},	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{ 674	,3	,1	, &iEM_TERA6VS22LIM},	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{ 675	,3	,1	, &iEM_TERB6VS12LIM},	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{ 676	,3	,1	, &iEM_TERB6VS22LIM},	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{ 677	,3	,1	, &iEM_TERA5VS22LIM},	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
	{ 678	,3	,1	, &iEM_TERA5VS12LIM},	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
	{ 679	,3	,1	, &iEM_TERB5VS12LIM},	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
	{ 680	,3	,1	, &iEM_TERB5VS22LIM},	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
	{ 681	,3	,1	, &iEM_TERR1VS12LIM},	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
	{ 682	,3	,1	, &iEM_TERR1VS22LIM},	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
	{ 683	,3	,1	, &iEM_TERR2VS12LIM},	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
	{ 684	,3	,1	, &iEM_TERR2VS22LIM},	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
	{ 685	,3	,1	, &iEM_TERR4VS12LDU},	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{ 686	,3	,1	, &iEM_TERR4VS22LDU},	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{ 687	,8	,1	, &fEM_R4UC23RIM},	//(R4UC23RIM) Y-координата АЗ1
	{ 688	,8	,1	, &fEM_A0UX13RSS},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{ 689	,8	,1	, &fEM_A0UX14RSS},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{ 690	,8	,1	, &fEM_A0UX15RSS},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{ 691	,8	,1	, &fEM_R7UX13RSS},	//(R7UX13RSS) X-координата камеры R7IN51
	{ 692	,8	,1	, &fEM_R7UX14RSS},	//(R7UX14RSS) X-координата камеры R7IN52
	{ 693	,8	,1	, &fEM_R7UX15RSS},	//(R7UX15RSS) X-координата камеры R7IN53
	{ 694	,8	,1	, &fEM_R7UY13RSS},	//(R7UY13RSS) Y-координата камеры R7IN51
	{ 695	,8	,1	, &fEM_R7UY14RSS},	//(R7UY14RSS) Y-координата камеры R7IN52
	{ 696	,8	,1	, &fEM_R7UY15RSS},	//(R7UY15RSS) Y-координата камеры R7IN53
	{ 697	,8	,1	, &fEM_R7UX16RSS},	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
	{ 698	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 699	,8	,1	, &internal1_m906_Chim0},	//(internal1_m906_Chim0) измеренная частота импульсов камеры Гц
	{ 700	,8	,1	, &internal1_m896_Chim0},	//(internal1_m896_Chim0) измеренная частота импульсов камеры Гц
	{ 701	,8	,1	, &internal1_m888_Chim0},	//(internal1_m888_Chim0) измеренная частота импульсов камеры Гц
	{ 702	,1	,1	, &internal1_m843_Out10},	//(internal1_m843_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 703	,1	,1	, &internal1_m842_Out10},	//(internal1_m842_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 704	,1	,1	, &internal1_m1026_Out10},	//(internal1_m1026_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 705	,1	,1	, &internal1_m1025_Out10},	//(internal1_m1025_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 706	,1	,1	, &internal1_m1024_Out10},	//(internal1_m1024_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 707	,1	,1	, &internal1_m1023_Out10},	//(internal1_m1023_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 708	,1	,1	, &internal1_m705_Out10},	//(internal1_m705_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 709	,1	,1	, &internal1_m704_Out10},	//(internal1_m704_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 710	,1	,1	, &internal1_m683_Out10},	//(internal1_m683_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 711	,1	,1	, &internal1_m682_Out10},	//(internal1_m682_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 712	,1	,1	, &internal1_m703_Out10},	//(internal1_m703_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 713	,1	,1	, &internal1_m702_Out10},	//(internal1_m702_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 714	,1	,1	, &internal1_m681_Out10},	//(internal1_m681_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 715	,1	,1	, &internal1_m680_Out10},	//(internal1_m680_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 716	,1	,1	, &internal1_m535_Out10},	//(internal1_m535_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 717	,1	,1	, &internal1_m554_Out10},	//(internal1_m554_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 718	,1	,1	, &internal1_m417_Out10},	//(internal1_m417_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 719	,1	,1	, &internal1_m494_q0},	//(internal1_m494_q0) q0 - внутренний параметр
	{ 720	,1	,1	, &internal1_m495_q0},	//(internal1_m495_q0) q0 - внутренний параметр
	{ 721	,1	,1	, &internal1_m480_q0},	//(internal1_m480_q0) q0 - внутренний параметр
	{ 722	,1	,1	, &internal1_m481_q0},	//(internal1_m481_q0) q0 - внутренний параметр
	{ 723	,8	,1	, &internal1_m656_tx},	//(internal1_m656_tx) tx - время накопленное сек
	{ 724	,18	,1	, &internal1_m656_y0},	//(internal1_m656_y0) y0
	{ 725	,8	,1	, &internal1_m644_tx},	//(internal1_m644_tx) tx - время накопленное сек
	{ 726	,18	,1	, &internal1_m644_y0},	//(internal1_m644_y0) y0
	{ 727	,8	,1	, &internal1_m630_tx},	//(internal1_m630_tx) tx - время накопленное сек
	{ 728	,18	,1	, &internal1_m630_y0},	//(internal1_m630_y0) y0
	{ 729	,8	,1	, &internal1_m628_tx},	//(internal1_m628_tx) tx - время накопленное сек
	{ 730	,18	,1	, &internal1_m628_y0},	//(internal1_m628_y0) y0
	{ 731	,1	,1	, &internal1_m214_Out10},	//(internal1_m214_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 732	,1	,1	, &internal1_m231_Out10},	//(internal1_m231_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 733	,1	,1	, &internal1_m41_Out10},	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 734	,1	,1	, &internal1_m56_Out10},	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 735	,1	,1	, &internal1_m997_Out10},	//(internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 736	,1	,1	, &internal1_m994_Out10},	//(internal1_m994_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 737	,1	,1	, &internal1_m993_Out10},	//(internal1_m993_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 738	,8	,1	, &internal1_m996_Xtek0},	//(internal1_m996_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 739	,8	,1	, &internal1_m979_Xtek0},	//(internal1_m979_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 740	,1	,1	, &internal1_m980_Out10},	//(internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 741	,1	,1	, &internal1_m977_Out10},	//(internal1_m977_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 742	,1	,1	, &internal1_m976_Out10},	//(internal1_m976_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 743	,1	,1	, &internal1_m1064_Out10},	//(internal1_m1064_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 744	,1	,1	, &internal1_m1045_Out10},	//(internal1_m1045_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 745	,1	,1	, &internal1_m1044_Out10},	//(internal1_m1044_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 746	,1	,1	, &internal1_m1043_Out10},	//(internal1_m1043_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 747	,1	,1	, &internal1_m864_Out10},	//(internal1_m864_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 748	,1	,1	, &internal1_m866_Out10},	//(internal1_m866_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 749	,1	,1	, &internal1_m863_Out10},	//(internal1_m863_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 750	,1	,1	, &internal1_m865_Out10},	//(internal1_m865_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 751	,1	,1	, &internal1_m839_Out10},	//(internal1_m839_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 752	,1	,1	, &internal1_m840_Out10},	//(internal1_m840_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 753	,1	,1	, &internal1_m838_Out10},	//(internal1_m838_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 754	,1	,1	, &internal1_m837_Out10},	//(internal1_m837_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 755	,1	,1	, &internal1_m1059_Out10},	//(internal1_m1059_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 756	,1	,1	, &internal1_m1011_Out10},	//(internal1_m1011_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 757	,1	,1	, &internal1_m1010_Out10},	//(internal1_m1010_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 758	,1	,1	, &internal1_m1009_Out10},	//(internal1_m1009_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 759	,1	,1	, &internal1_m1008_Out10},	//(internal1_m1008_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 760	,1	,1	, &internal1_m1060_Out10},	//(internal1_m1060_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 761	,1	,1	, &internal1_m1041_Out10},	//(internal1_m1041_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 762	,1	,1	, &internal1_m841_Out10},	//(internal1_m841_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 763	,1	,1	, &internal1_m1042_Out10},	//(internal1_m1042_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 764	,1	,1	, &internal1_m1040_Out10},	//(internal1_m1040_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 765	,1	,1	, &internal1_m1061_Out10},	//(internal1_m1061_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 766	,1	,1	, &internal1_m1039_Out10},	//(internal1_m1039_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 767	,1	,1	, &internal1_m1022_Out10},	//(internal1_m1022_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 768	,1	,1	, &internal1_m1007_Out10},	//(internal1_m1007_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 769	,1	,1	, &internal1_m553_Out10},	//(internal1_m553_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 770	,8	,1	, &internal1_m427_Xtek0},	//(internal1_m427_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 771	,1	,1	, &internal1_m418_Out10},	//(internal1_m418_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 772	,1	,1	, &internal1_m420_Out10},	//(internal1_m420_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 773	,1	,1	, &internal1_m419_Out10},	//(internal1_m419_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 774	,1	,1	, &internal1_m879_Out10},	//(internal1_m879_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 775	,1	,1	, &internal1_m880_Out10},	//(internal1_m880_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 776	,1	,1	, &internal1_m878_Out10},	//(internal1_m878_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 777	,1	,1	, &internal1_m1063_Out10},	//(internal1_m1063_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 778	,1	,1	, &internal1_m718_Out10},	//(internal1_m718_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 779	,1	,1	, &internal1_m719_Out10},	//(internal1_m719_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 780	,1	,1	, &internal1_m716_Out10},	//(internal1_m716_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 781	,1	,1	, &internal1_m717_Out10},	//(internal1_m717_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 782	,1	,1	, &internal1_m574_Out10},	//(internal1_m574_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 783	,1	,1	, &internal1_m573_Out10},	//(internal1_m573_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 784	,8	,1	, &internal1_m860_Xtek0},	//(internal1_m860_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 785	,8	,1	, &internal1_m862_Xtek0},	//(internal1_m862_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 786	,1	,1	, &internal1_m715_Out10},	//(internal1_m715_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 787	,1	,1	, &internal1_m699_Out10},	//(internal1_m699_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 788	,1	,1	, &internal1_m679_Out10},	//(internal1_m679_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 789	,1	,1	, &internal1_m698_Out10},	//(internal1_m698_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 790	,1	,1	, &internal1_m678_Out10},	//(internal1_m678_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 791	,1	,1	, &internal1_m345_Out10},	//(internal1_m345_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 792	,1	,1	, &internal1_m344_Out10},	//(internal1_m344_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 793	,1	,1	, &internal1_m329_Out10},	//(internal1_m329_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 794	,1	,1	, &internal1_m328_Out10},	//(internal1_m328_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 795	,1	,1	, &internal1_m575_Out10},	//(internal1_m575_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 796	,1	,1	, &internal1_m358_Out10},	//(internal1_m358_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 797	,8	,1	, &internal1_m342_Xtek0},	//(internal1_m342_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 798	,1	,1	, &internal1_m357_Out10},	//(internal1_m357_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 799	,1	,1	, &internal1_m355_Out10},	//(internal1_m355_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 800	,8	,1	, &internal1_m334_Xtek0},	//(internal1_m334_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 801	,1	,1	, &internal1_m356_Out10},	//(internal1_m356_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 802	,1	,1	, &internal1_m327_Out10},	//(internal1_m327_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 803	,1	,1	, &internal1_m343_Out10},	//(internal1_m343_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 804	,1	,1	, &internal1_m439_Out10},	//(internal1_m439_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 805	,8	,1	, &internal1_m440_Xtek0},	//(internal1_m440_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 806	,1	,1	, &internal1_m438_Out10},	//(internal1_m438_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 807	,1	,1	, &internal1_m437_Out10},	//(internal1_m437_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 808	,1	,1	, &internal1_m436_Out10},	//(internal1_m436_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 809	,1	,1	, &internal1_m1062_Out10},	//(internal1_m1062_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 810	,1	,1	, &internal1_m150_Out10},	//(internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 811	,1	,1	, &internal1_m149_Out10},	//(internal1_m149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 812	,3	,1	, &internal1_m203_tx},	//(internal1_m203_tx) tx - внутренний параметр
	{ 813	,3	,1	, &internal1_m25_tx},	//(internal1_m25_tx) tx - внутренний параметр
	{ 814	,1	,1	, &internal1_m486_Pav0},	//(internal1_m486_Pav0)  - Пер.аварийный выключатель механизма
	{ 815	,1	,1	, &internal1_m486_Zav0},	//(internal1_m486_Zav0)  - Зад.аварийный выключатель механизма
	{ 816	,1	,1	, &internal1_m486_Pv0},	//(internal1_m486_Pv0)  - Пер. выключатель механизма
	{ 817	,1	,1	, &internal1_m486_Zv0},	//(internal1_m486_Zv0)  - Зад. выключатель механизма
	{ 818	,1	,1	, &internal1_m486_RA00},	//(internal1_m486_RA00)  - последнее задание вперед
	{ 819	,1	,1	, &internal1_m486_RA10},	//(internal1_m486_RA10)  - последнее задание назад
	{ 820	,1	,1	, &internal1_m486_MyFirstEnterFlag},	//(internal1_m486_MyFirstEnterFlag) MyFirstEnterFlag
	{ 821	,1	,1	, &internal1_m498_Pav0},	//(internal1_m498_Pav0)  - Пер.аварийный выключатель механизма
	{ 822	,1	,1	, &internal1_m498_Zav0},	//(internal1_m498_Zav0)  - Зад.аварийный выключатель механизма
	{ 823	,1	,1	, &internal1_m498_Pv0},	//(internal1_m498_Pv0)  - Пер. выключатель механизма
	{ 824	,1	,1	, &internal1_m498_Zv0},	//(internal1_m498_Zv0)  - Зад. выключатель механизма
	{ 825	,1	,1	, &internal1_m498_RA00},	//(internal1_m498_RA00)  - последнее задание вперед
	{ 826	,1	,1	, &internal1_m498_RA10},	//(internal1_m498_RA10)  - последнее задание назад
	{ 827	,1	,1	, &internal1_m498_MyFirstEnterFlag},	//(internal1_m498_MyFirstEnterFlag) MyFirstEnterFlag
	{ 828	,1	,1	, &internal1_m484_Pav0},	//(internal1_m484_Pav0)  - Пер.аварийный выключатель механизма
	{ 829	,1	,1	, &internal1_m484_Zav0},	//(internal1_m484_Zav0)  - Зад.аварийный выключатель механизма
	{ 830	,1	,1	, &internal1_m484_Pv0},	//(internal1_m484_Pv0)  - Пер. выключатель механизма
	{ 831	,1	,1	, &internal1_m484_Zv0},	//(internal1_m484_Zv0)  - Зад. выключатель механизма
	{ 832	,1	,1	, &internal1_m484_RA00},	//(internal1_m484_RA00)  - последнее задание вперед
	{ 833	,1	,1	, &internal1_m484_RA10},	//(internal1_m484_RA10)  - последнее задание назад
	{ 834	,1	,1	, &internal1_m484_MyFirstEnterFlag},	//(internal1_m484_MyFirstEnterFlag) MyFirstEnterFlag
	{ 835	,1	,1	, &internal1_m634_Pav0},	//(internal1_m634_Pav0)  - Пер.аварийный выключатель механизма
	{ 836	,1	,1	, &internal1_m634_Zav0},	//(internal1_m634_Zav0)  - Зад.аварийный выключатель механизма
	{ 837	,1	,1	, &internal1_m634_Pv0},	//(internal1_m634_Pv0)  - Пер. выключатель механизма
	{ 838	,1	,1	, &internal1_m634_Zv0},	//(internal1_m634_Zv0)  - Зад. выключатель механизма
	{ 839	,1	,1	, &internal1_m634_RA00},	//(internal1_m634_RA00)  - последнее задание вперед
	{ 840	,1	,1	, &internal1_m634_RA10},	//(internal1_m634_RA10)  - последнее задание назад
	{ 841	,1	,1	, &internal1_m634_MyFirstEnterFlag},	//(internal1_m634_MyFirstEnterFlag) MyFirstEnterFlag
	{ 842	,1	,1	, &internal1_m632_Pav0},	//(internal1_m632_Pav0)  - Пер.аварийный выключатель механизма
	{ 843	,1	,1	, &internal1_m632_Zav0},	//(internal1_m632_Zav0)  - Зад.аварийный выключатель механизма
	{ 844	,1	,1	, &internal1_m632_Pv0},	//(internal1_m632_Pv0)  - Пер. выключатель механизма
	{ 845	,1	,1	, &internal1_m632_Zv0},	//(internal1_m632_Zv0)  - Зад. выключатель механизма
	{ 846	,1	,1	, &internal1_m632_RA00},	//(internal1_m632_RA00)  - последнее задание вперед
	{ 847	,1	,1	, &internal1_m632_RA10},	//(internal1_m632_RA10)  - последнее задание назад
	{ 848	,1	,1	, &internal1_m632_MyFirstEnterFlag},	//(internal1_m632_MyFirstEnterFlag) MyFirstEnterFlag
	{ 849	,1	,1	, &internal1_m618_Pav0},	//(internal1_m618_Pav0)  - Пер.аварийный выключатель механизма
	{ 850	,1	,1	, &internal1_m618_Zav0},	//(internal1_m618_Zav0)  - Зад.аварийный выключатель механизма
	{ 851	,1	,1	, &internal1_m618_Pv0},	//(internal1_m618_Pv0)  - Пер. выключатель механизма
	{ 852	,1	,1	, &internal1_m618_Zv0},	//(internal1_m618_Zv0)  - Зад. выключатель механизма
	{ 853	,1	,1	, &internal1_m618_RA00},	//(internal1_m618_RA00)  - последнее задание вперед
	{ 854	,1	,1	, &internal1_m618_RA10},	//(internal1_m618_RA10)  - последнее задание назад
	{ 855	,1	,1	, &internal1_m618_MyFirstEnterFlag},	//(internal1_m618_MyFirstEnterFlag) MyFirstEnterFlag
	{ 856	,1	,1	, &internal1_m617_Pav0},	//(internal1_m617_Pav0)  - Пер.аварийный выключатель механизма
	{ 857	,1	,1	, &internal1_m617_Zav0},	//(internal1_m617_Zav0)  - Зад.аварийный выключатель механизма
	{ 858	,1	,1	, &internal1_m617_Pv0},	//(internal1_m617_Pv0)  - Пер. выключатель механизма
	{ 859	,1	,1	, &internal1_m617_Zv0},	//(internal1_m617_Zv0)  - Зад. выключатель механизма
	{ 860	,1	,1	, &internal1_m617_RA00},	//(internal1_m617_RA00)  - последнее задание вперед
	{ 861	,1	,1	, &internal1_m617_RA10},	//(internal1_m617_RA10)  - последнее задание назад
	{ 862	,1	,1	, &internal1_m617_MyFirstEnterFlag},	//(internal1_m617_MyFirstEnterFlag) MyFirstEnterFlag
	{ 863	,8	,1	, &internal1_m664_y0},	//(internal1_m664_y0) y0 - внутренний параметр
	{ 864	,8	,1	, &internal1_m825_Chim0},	//(internal1_m825_Chim0) измеренная частота импульсов камеры Гц
	{ 865	,8	,1	, &internal1_m816_Chim0},	//(internal1_m816_Chim0) измеренная частота импульсов камеры Гц
	{ 866	,8	,1	, &internal1_m808_Chim0},	//(internal1_m808_Chim0) измеренная частота импульсов камеры Гц
	{ 867	,8	,1	, &internal1_m799_Chim0},	//(internal1_m799_Chim0) измеренная частота импульсов камеры Гц
	{ 868	,8	,1	, &internal1_m790_Chim0},	//(internal1_m790_Chim0) измеренная частота импульсов камеры Гц
	{ 869	,8	,1	, &internal1_m782_Chim0},	//(internal1_m782_Chim0) измеренная частота импульсов камеры Гц
	{ 870	,8	,1	, &internal1_m773_Chim0},	//(internal1_m773_Chim0) измеренная частота импульсов камеры Гц
	{ 871	,8	,1	, &internal1_m764_Chim0},	//(internal1_m764_Chim0) измеренная частота импульсов камеры Гц
	{ 872	,8	,1	, &internal1_m756_Chim0},	//(internal1_m756_Chim0) измеренная частота импульсов камеры Гц
	{ 873	,8	,1	, &internal1_m747_Chim0},	//(internal1_m747_Chim0) измеренная частота импульсов камеры Гц
	{ 874	,8	,1	, &internal1_m738_Chim0},	//(internal1_m738_Chim0) измеренная частота импульсов камеры Гц
	{ 875	,8	,1	, &internal1_m730_Chim0},	//(internal1_m730_Chim0) измеренная частота импульсов камеры Гц
	{ 876	,1	,1	, &internal1_m604_Pav0},	//(internal1_m604_Pav0)  - Пер.аварийный выключатель механизма
	{ 877	,1	,1	, &internal1_m604_Zav0},	//(internal1_m604_Zav0)  - Зад.аварийный выключатель механизма
	{ 878	,1	,1	, &internal1_m604_Pv0},	//(internal1_m604_Pv0)  - Пер. выключатель механизма
	{ 879	,1	,1	, &internal1_m604_Zv0},	//(internal1_m604_Zv0)  - Зад. выключатель механизма
	{ 880	,1	,1	, &internal1_m604_RA00},	//(internal1_m604_RA00)  - последнее задание вперед
	{ 881	,1	,1	, &internal1_m604_RA10},	//(internal1_m604_RA10)  - последнее задание назад
	{ 882	,1	,1	, &internal1_m604_MyFirstEnterFlag},	//(internal1_m604_MyFirstEnterFlag) MyFirstEnterFlag
	{ 883	,1	,1	, &internal1_m589_Pav0},	//(internal1_m589_Pav0)  - Пер.аварийный выключатель механизма
	{ 884	,1	,1	, &internal1_m589_Zav0},	//(internal1_m589_Zav0)  - Зад.аварийный выключатель механизма
	{ 885	,1	,1	, &internal1_m589_Pv0},	//(internal1_m589_Pv0)  - Пер. выключатель механизма
	{ 886	,1	,1	, &internal1_m589_Zv0},	//(internal1_m589_Zv0)  - Зад. выключатель механизма
	{ 887	,1	,1	, &internal1_m589_RA00},	//(internal1_m589_RA00)  - последнее задание вперед
	{ 888	,1	,1	, &internal1_m589_RA10},	//(internal1_m589_RA10)  - последнее задание назад
	{ 889	,1	,1	, &internal1_m589_MyFirstEnterFlag},	//(internal1_m589_MyFirstEnterFlag) MyFirstEnterFlag
	{ 890	,1	,1	, &internal1_m469_Pav0},	//(internal1_m469_Pav0)  - Пер.аварийный выключатель механизма
	{ 891	,1	,1	, &internal1_m469_Zav0},	//(internal1_m469_Zav0)  - Зад.аварийный выключатель механизма
	{ 892	,1	,1	, &internal1_m469_Pv0},	//(internal1_m469_Pv0)  - Пер. выключатель механизма
	{ 893	,1	,1	, &internal1_m469_Zv0},	//(internal1_m469_Zv0)  - Зад. выключатель механизма
	{ 894	,1	,1	, &internal1_m469_RA00},	//(internal1_m469_RA00)  - последнее задание вперед
	{ 895	,1	,1	, &internal1_m469_RA10},	//(internal1_m469_RA10)  - последнее задание назад
	{ 896	,1	,1	, &internal1_m469_MyFirstEnterFlag},	//(internal1_m469_MyFirstEnterFlag) MyFirstEnterFlag
	{ 897	,1	,1	, &internal1_m454_Pav0},	//(internal1_m454_Pav0)  - Пер.аварийный выключатель механизма
	{ 898	,1	,1	, &internal1_m454_Zav0},	//(internal1_m454_Zav0)  - Зад.аварийный выключатель механизма
	{ 899	,1	,1	, &internal1_m454_Pv0},	//(internal1_m454_Pv0)  - Пер. выключатель механизма
	{ 900	,1	,1	, &internal1_m454_Zv0},	//(internal1_m454_Zv0)  - Зад. выключатель механизма
	{ 901	,1	,1	, &internal1_m454_RA00},	//(internal1_m454_RA00)  - последнее задание вперед
	{ 902	,1	,1	, &internal1_m454_RA10},	//(internal1_m454_RA10)  - последнее задание назад
	{ 903	,1	,1	, &internal1_m454_MyFirstEnterFlag},	//(internal1_m454_MyFirstEnterFlag) MyFirstEnterFlag
	{ 904	,1	,1	, &internal1_m510_Pav0},	//(internal1_m510_Pav0)  - Пер.аварийный выключатель механизма
	{ 905	,1	,1	, &internal1_m510_Zav0},	//(internal1_m510_Zav0)  - Зад.аварийный выключатель механизма
	{ 906	,1	,1	, &internal1_m510_Pv0},	//(internal1_m510_Pv0)  - Пер. выключатель механизма
	{ 907	,1	,1	, &internal1_m510_Zv0},	//(internal1_m510_Zv0)  - Зад. выключатель механизма
	{ 908	,1	,1	, &internal1_m510_RA00},	//(internal1_m510_RA00)  - последнее задание вперед
	{ 909	,1	,1	, &internal1_m510_RA10},	//(internal1_m510_RA10)  - последнее задание назад
	{ 910	,1	,1	, &internal1_m510_MyFirstEnterFlag},	//(internal1_m510_MyFirstEnterFlag) MyFirstEnterFlag
	{ 911	,1	,1	, &internal1_m405_Pav0},	//(internal1_m405_Pav0)  - Пер.аварийный выключатель механизма
	{ 912	,1	,1	, &internal1_m405_Zav0},	//(internal1_m405_Zav0)  - Зад.аварийный выключатель механизма
	{ 913	,1	,1	, &internal1_m405_Pv0},	//(internal1_m405_Pv0)  - Пер. выключатель механизма
	{ 914	,1	,1	, &internal1_m405_Zv0},	//(internal1_m405_Zv0)  - Зад. выключатель механизма
	{ 915	,1	,1	, &internal1_m405_RA00},	//(internal1_m405_RA00)  - последнее задание вперед
	{ 916	,1	,1	, &internal1_m405_RA10},	//(internal1_m405_RA10)  - последнее задание назад
	{ 917	,1	,1	, &internal1_m405_MyFirstEnterFlag},	//(internal1_m405_MyFirstEnterFlag) MyFirstEnterFlag
	{ 918	,1	,1	, &internal1_m389_Pav0},	//(internal1_m389_Pav0)  - Пер.аварийный выключатель механизма
	{ 919	,1	,1	, &internal1_m389_Zav0},	//(internal1_m389_Zav0)  - Зад.аварийный выключатель механизма
	{ 920	,1	,1	, &internal1_m389_Pv0},	//(internal1_m389_Pv0)  - Пер. выключатель механизма
	{ 921	,1	,1	, &internal1_m389_Zv0},	//(internal1_m389_Zv0)  - Зад. выключатель механизма
	{ 922	,1	,1	, &internal1_m389_RA00},	//(internal1_m389_RA00)  - последнее задание вперед
	{ 923	,1	,1	, &internal1_m389_RA10},	//(internal1_m389_RA10)  - последнее задание назад
	{ 924	,1	,1	, &internal1_m389_MyFirstEnterFlag},	//(internal1_m389_MyFirstEnterFlag) MyFirstEnterFlag
	{ 925	,1	,1	, &internal1_m372_Pav0},	//(internal1_m372_Pav0)  - Пер.аварийный выключатель механизма
	{ 926	,1	,1	, &internal1_m372_Zav0},	//(internal1_m372_Zav0)  - Зад.аварийный выключатель механизма
	{ 927	,1	,1	, &internal1_m372_Pv0},	//(internal1_m372_Pv0)  - Пер. выключатель механизма
	{ 928	,1	,1	, &internal1_m372_Zv0},	//(internal1_m372_Zv0)  - Зад. выключатель механизма
	{ 929	,1	,1	, &internal1_m372_RA00},	//(internal1_m372_RA00)  - последнее задание вперед
	{ 930	,1	,1	, &internal1_m372_RA10},	//(internal1_m372_RA10)  - последнее задание назад
	{ 931	,1	,1	, &internal1_m372_MyFirstEnterFlag},	//(internal1_m372_MyFirstEnterFlag) MyFirstEnterFlag
	{ 932	,1	,1	, &internal1_m918_Pav0},	//(internal1_m918_Pav0)  - Пер.аварийный выключатель механизма
	{ 933	,1	,1	, &internal1_m918_Zav0},	//(internal1_m918_Zav0)  - Зад.аварийный выключатель механизма
	{ 934	,1	,1	, &internal1_m918_Pv0},	//(internal1_m918_Pv0)  - Пер. выключатель механизма
	{ 935	,1	,1	, &internal1_m918_Zv0},	//(internal1_m918_Zv0)  - Зад. выключатель механизма
	{ 936	,1	,1	, &internal1_m918_RA00},	//(internal1_m918_RA00)  - последнее задание вперед
	{ 937	,1	,1	, &internal1_m918_RA10},	//(internal1_m918_RA10)  - последнее задание назад
	{ 938	,1	,1	, &internal1_m918_MyFirstEnterFlag},	//(internal1_m918_MyFirstEnterFlag) MyFirstEnterFlag
	{ 939	,8	,1	, &internal1_m188_C1},	//(internal1_m188_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{ 940	,8	,1	, &internal1_m188_C2},	//(internal1_m188_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{ 941	,8	,1	, &internal1_m188_C3},	//(internal1_m188_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{ 942	,8	,1	, &internal1_m188_C4},	//(internal1_m188_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{ 943	,8	,1	, &internal1_m188_C5},	//(internal1_m188_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{ 944	,8	,1	, &internal1_m188_C6},	//(internal1_m188_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{ 945	,8	,1	, &internal1_m188_N20},	//(internal1_m188_N20) N20 - пред. концентрация нейтронов второй АЗ
	{ 946	,8	,6	, &internal1_m188_C0},	//(internal1_m188_C0) *C0 - пред. концентрация запаздывающих нейтронов
	{ 947	,1	,1	, &internal1_m188_ImpINI0},	//(internal1_m188_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{ 948	,1	,1	, &internal1_m188_MyFirstEnterFlag},	//(internal1_m188_MyFirstEnterFlag) MyFirstEnterFlag
	{ 949	,1	,1	, &internal1_m307_Ppv0},	//(internal1_m307_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 950	,1	,1	, &internal1_m307_Pav0},	//(internal1_m307_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 951	,1	,1	, &internal1_m307_Zav0},	//(internal1_m307_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 952	,1	,1	, &internal1_m307_RA00},	//(internal1_m307_RA00) RA00 - последнее задание вперед
	{ 953	,1	,1	, &internal1_m307_RA10},	//(internal1_m307_RA10) RA10 - последнее задание назад
	{ 954	,18	,1	, &internal1_m307_RA50},	//(internal1_m307_RA50) Ra50 - последнее задание скорости
	{ 955	,1	,1	, &internal1_m307_fls},	//(internal1_m307_fls)  fls - флаг одношагового режима
	{ 956	,1	,1	, &internal1_m307_flp},	//(internal1_m307_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 957	,1	,1	, &internal1_m307_MyFirstEnterFlag},	//(internal1_m307_MyFirstEnterFlag) MyFirstEnterFlag
	{ 958	,1	,1	, &internal1_m130_Ppv0},	//(internal1_m130_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 959	,1	,1	, &internal1_m130_Pav0},	//(internal1_m130_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 960	,1	,1	, &internal1_m130_Zav0},	//(internal1_m130_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 961	,1	,1	, &internal1_m130_RA00},	//(internal1_m130_RA00) RA00 - последнее задание вперед
	{ 962	,1	,1	, &internal1_m130_RA10},	//(internal1_m130_RA10) RA10 - последнее задание назад
	{ 963	,18	,1	, &internal1_m130_RA50},	//(internal1_m130_RA50) Ra50 - последнее задание скорости
	{ 964	,1	,1	, &internal1_m130_fls},	//(internal1_m130_fls)  fls - флаг одношагового режима
	{ 965	,1	,1	, &internal1_m130_flp},	//(internal1_m130_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 966	,1	,1	, &internal1_m130_MyFirstEnterFlag},	//(internal1_m130_MyFirstEnterFlag) MyFirstEnterFlag
	{ 967	,1	,1	, &internal1_m272_Ppv0},	//(internal1_m272_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 968	,1	,1	, &internal1_m272_Pav0},	//(internal1_m272_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 969	,1	,1	, &internal1_m272_Zav0},	//(internal1_m272_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 970	,1	,1	, &internal1_m272_RA00},	//(internal1_m272_RA00) RA00 - последнее задание вперед
	{ 971	,1	,1	, &internal1_m272_RA10},	//(internal1_m272_RA10) RA10 - последнее задание назад
	{ 972	,18	,1	, &internal1_m272_RA50},	//(internal1_m272_RA50) Ra50 - последнее задание скорости
	{ 973	,1	,1	, &internal1_m272_fls},	//(internal1_m272_fls)  fls - флаг одношагового режима
	{ 974	,1	,1	, &internal1_m272_flp},	//(internal1_m272_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 975	,1	,1	, &internal1_m272_MyFirstEnterFlag},	//(internal1_m272_MyFirstEnterFlag) MyFirstEnterFlag
	{ 976	,1	,1	, &internal1_m96_Ppv0},	//(internal1_m96_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 977	,1	,1	, &internal1_m96_Pav0},	//(internal1_m96_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 978	,1	,1	, &internal1_m96_Zav0},	//(internal1_m96_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 979	,1	,1	, &internal1_m96_RA00},	//(internal1_m96_RA00) RA00 - последнее задание вперед
	{ 980	,1	,1	, &internal1_m96_RA10},	//(internal1_m96_RA10) RA10 - последнее задание назад
	{ 981	,18	,1	, &internal1_m96_RA50},	//(internal1_m96_RA50) Ra50 - последнее задание скорости
	{ 982	,1	,1	, &internal1_m96_fls},	//(internal1_m96_fls)  fls - флаг одношагового режима
	{ 983	,1	,1	, &internal1_m96_flp},	//(internal1_m96_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 984	,1	,1	, &internal1_m96_MyFirstEnterFlag},	//(internal1_m96_MyFirstEnterFlag) MyFirstEnterFlag
	{ 985	,1	,1	, &internal1_m236_Ppv0},	//(internal1_m236_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 986	,1	,1	, &internal1_m236_Pav0},	//(internal1_m236_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 987	,1	,1	, &internal1_m236_Zav0},	//(internal1_m236_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 988	,1	,1	, &internal1_m236_RA00},	//(internal1_m236_RA00) RA00 - последнее задание вперед
	{ 989	,1	,1	, &internal1_m236_RA10},	//(internal1_m236_RA10) RA10 - последнее задание назад
	{ 990	,18	,1	, &internal1_m236_RA50},	//(internal1_m236_RA50) Ra50 - последнее задание скорости
	{ 991	,1	,1	, &internal1_m236_fls},	//(internal1_m236_fls)  fls - флаг одношагового режима
	{ 992	,1	,1	, &internal1_m236_flp},	//(internal1_m236_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 993	,1	,1	, &internal1_m236_MyFirstEnterFlag},	//(internal1_m236_MyFirstEnterFlag) MyFirstEnterFlag
	{ 994	,1	,1	, &internal1_m60_Ppv0},	//(internal1_m60_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 995	,1	,1	, &internal1_m60_Pav0},	//(internal1_m60_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 996	,1	,1	, &internal1_m60_Zav0},	//(internal1_m60_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 997	,1	,1	, &internal1_m60_RA00},	//(internal1_m60_RA00) RA00 - последнее задание вперед
	{ 998	,1	,1	, &internal1_m60_RA10},	//(internal1_m60_RA10) RA10 - последнее задание назад
	{ 999	,18	,1	, &internal1_m60_RA50},	//(internal1_m60_RA50) Ra50 - последнее задание скорости
	{ 1000	,1	,1	, &internal1_m60_fls},	//(internal1_m60_fls)  fls - флаг одношагового режима
	{ 1001	,1	,1	, &internal1_m60_flp},	//(internal1_m60_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1002	,1	,1	, &internal1_m60_MyFirstEnterFlag},	//(internal1_m60_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1003	,8	,1	, &internal1_m14_C1},	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{ 1004	,8	,1	, &internal1_m14_C2},	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{ 1005	,8	,1	, &internal1_m14_C3},	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{ 1006	,8	,1	, &internal1_m14_C4},	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{ 1007	,8	,1	, &internal1_m14_C5},	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{ 1008	,8	,1	, &internal1_m14_C6},	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{ 1009	,8	,1	, &internal1_m14_N20},	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
	{ 1010	,8	,6	, &internal1_m14_C0},	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
	{ 1011	,1	,1	, &internal1_m14_ImpINI0},	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{ 1012	,1	,1	, &internal1_m14_MyFirstEnterFlag},	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="scm.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{289,"fEM_R0UL01RIM\0"}, 
{290,"fEM_R0UN02RIM\0"}, 
{291,"fEM_A1UR01RIM\0"}, 
{292,"fEM_A1UR00RIM\0"}, 
{293,"fEM_A3UR00RIM\0"}, 
{294,"fEM_A3UR01RIM\0"}, 
{295,"fEM_R0UT01RIM\0"}, 
{296,"fEM_R0UT02RIM\0"}, 
{297,"fEM_R0UT04RIM\0"}, 
{298,"fEM_R0UT03RIM\0"}, 
{299,"fEM_R0UT05RIM\0"}, 
{300,"fEM_R0UT06RIM\0"}, 
{301,"fEM_A1UC02RDU\0"}, 
{302,"fEM_A1UC04RIM\0"}, 
{303,"fEM_A1UC05RIM\0"}, 
{304,"fEM_A1UC06RIM\0"}, 
{305,"fEM_A2UC06RIM\0"}, 
{306,"fEM_A2UC05RIM\0"}, 
{307,"fEM_A2UC04RIM\0"}, 
{308,"fEM_A2UC02RDU\0"}, 
{309,"fEM_A3UC06RIM\0"}, 
{310,"fEM_A3UC05RIM\0"}, 
{311,"fEM_A3UC04RIM\0"}, 
{312,"fEM_A3UC02RDU\0"}, 
{313,"fEM_R4UV80RDU\0"}, 
{314,"fEM_R4UC10RIM\0"}, 
{315,"fEM_R4UC20RIM\0"}, 
{316,"fEM_B8UC21RIM\0"}, 
{317,"fEM_B8UC20RIM\0"}, 
{318,"fEM_B8UC11RIM\0"}, 
{319,"fEM_B8UC10RIM\0"}, 
{320,"fEM_B8UV80RDU\0"}, 
{321,"fEM_A8UV80RDU\0"}, 
{322,"fEM_A8UC10RIM\0"}, 
{323,"fEM_A8UC11RIM\0"}, 
{324,"fEM_A8UC20RIM\0"}, 
{325,"fEM_A8UC21RIM\0"}, 
{326,"fEM_A6UC10RIM\0"}, 
{327,"fEM_R1UC10RIM\0"}, 
{328,"fEM_A5UC10RIM\0"}, 
{329,"fEM_A0UN01RIM\0"}, 
{330,"fEM_R4UC22RIM\0"}, 
{331,"fEM_A1UG01RDU\0"}, 
{332,"fEM_A2UG01RDU\0"}, 
{333,"fEM_A3UG01RDU\0"}, 
{334,"fEM_R7UC10RIM\0"}, 
{335,"fEM_R7UC19RIM\0"}, 
{336,"fEM_R7UI02RIM\0"}, 
{337,"fEM_R7UL01RIM\0"}, 
{338,"fEM_A2UR00RIM\0"}, 
{339,"fEM_A2UR01RIM\0"}, 
{340,"fEM_A0UN02RIM\0"}, 
{341,"fEM_R0UR30RIM\0"}, 
{342,"fEM_R0UR01RIM\0"}, 
{343,"fEM_R0UT02RDU\0"}, 
{344,"fEM_R0UT01RDU\0"}, 
{345,"fEM_A1UC03RDU\0"}, 
{346,"fEM_A2UP03RDU\0"}, 
{347,"fEM_A2UP04RDU\0"}, 
{348,"fEM_A2UC03RDU\0"}, 
{349,"fEM_A3UP03RDU\0"}, 
{350,"fEM_A3UP04RDU\0"}, 
{351,"fEM_A3UC03RDU\0"}, 
{352,"fEM_R7UI74RIM\0"}, 
{353,"fEM_A8UC03RDU\0"}, 
{354,"fEM_R0UV87RDU\0"}, 
{355,"fEM_R0UV81RDU\0"}, 
{356,"fEM_R0UV82RDU\0"}, 
{357,"fEM_R0UV83RDU\0"}, 
{358,"fEM_R0UV84RDU\0"}, 
{359,"fEM_R0UV85RDU\0"}, 
{360,"fEM_R0UV86RDU\0"}, 
{361,"fEM_A8UC08RDU\0"}, 
{362,"fEM_B8UC08RDU\0"}, 
{363,"fEM_R4UC08RDU\0"}, 
{364,"fEM_R0UH01RSS\0"}, 
{365,"fEM_A0UX00RSS\0"}, 
{366,"fEM_R7UX01RSS\0"}, 
{367,"fEM_R7UX02RSS\0"}, 
{368,"fEM_R7UX04RSS\0"}, 
{369,"fEM_R7UX05RSS\0"}, 
{370,"fEM_R7UX06RSS\0"}, 
{371,"fEM_R7UX07RSS\0"}, 
{372,"fEM_R7UX08RSS\0"}, 
{373,"fEM_R7UX09RSS\0"}, 
{374,"fEM_R7UY01RSS\0"}, 
{375,"fEM_R7UY02RSS\0"}, 
{376,"fEM_R7UY04RSS\0"}, 
{377,"fEM_R7UY05RSS\0"}, 
{378,"fEM_R7UY06RSS\0"}, 
{379,"fEM_R7UY07RSS\0"}, 
{380,"fEM_R7UY08RSS\0"}, 
{381,"fEM_R7UY09RSS\0"}, 
{382,"fEM_R7UX10RSS\0"}, 
{383,"fEM_R7UX11RSS\0"}, 
{384,"fEM_R7UX12RSS\0"}, 
{385,"fEM_R7UY10RSS\0"}, 
{386,"fEM_R7UY11RSS\0"}, 
{387,"fEM_R7UY12RSS\0"}, 
{388,"fEM_A0UX01RSS\0"}, 
{389,"fEM_A0UX02RSS\0"}, 
{390,"fEM_A0UX03RSS\0"}, 
{391,"fEM_A0UX04RSS\0"}, 
{392,"fEM_A0UX05RSS\0"}, 
{393,"fEM_A0UX06RSS\0"}, 
{394,"fEM_A0UX07RSS\0"}, 
{395,"fEM_A0UX08RSS\0"}, 
{396,"fEM_A0UX09RSS\0"}, 
{397,"fEM_A0UX10RSS\0"}, 
{398,"fEM_A0UX11RSS\0"}, 
{399,"fEM_A0UX12RSS\0"}, 
{400,"fEM_B0UX01RSS\0"}, 
{401,"fEM_B0UX02RSS\0"}, 
{402,"fEM_B0UX03RSS\0"}, 
{403,"fEM_B0UX04RSS\0"}, 
{404,"fEM_B0UX05RSS\0"}, 
{405,"fEM_B0UX06RSS\0"}, 
{406,"fEM_B0UX07RSS\0"}, 
{407,"fEM_B0UX08RSS\0"}, 
{408,"fEM_B0UX09RSS\0"}, 
{409,"fEM_B0UX10RSS\0"}, 
{410,"fEM_B0UX11RSS\0"}, 
{411,"fEM_B0UX12RSS\0"}, 
{412,"fEM_R0UH02RSS\0"}, 
{413,"fEM_R0UH03RSS\0"}, 
{414,"fEM_R4US80RDU\0"}, 
{415,"fEM_R7UI71RIM\0"}, 
{416,"fEM_R7UI72RIM\0"}, 
{417,"fEM_R7UI73RIM\0"}, 
{418,"fEM_A1UP01RIM\0"}, 
{419,"fEM_A2UP01RIM\0"}, 
{420,"fEM_A0UP02RIM\0"}, 
{421,"fEM_A3UP01RIM\0"}, 
{422,"fEM_A1UP82RIM\0"}, 
{423,"fEM_A3UP02RDU\0"}, 
{424,"fEM_A1UV02RIM\0"}, 
{425,"fEM_A3UV02RIM\0"}, 
{426,"fEM_A2UV02RIM\0"}, 
{427,"fEM_B8US80RDU\0"}, 
{428,"fEM_A8US80RDU\0"}, 
{429,"fEM_A6US80RDU\0"}, 
{430,"fEM_A1US07RDU\0"}, 
{431,"fEM_A2US07RDU\0"}, 
{432,"fEM_A3US07RDU\0"}, 
{433,"fEM_R7UI75RIM\0"}, 
{434,"fEM_R0UH21RSS\0"}, 
{435,"fEM_R0UH22RSS\0"}, 
{436,"fEM_R0UH23RSS\0"}, 
{437,"fEM_R0UH05RSS\0"}, 
{438,"fEM_A4UL10RIM\0"}, 
{439,"fEM_A9UL10RIM\0"}, 
{440,"fEM_R3UL10RIM\0"}, 
{441,"fEM_R5UL10RIM\0"}, 
{442,"fEM_R6UL10RIM\0"}, 
{443,"lEM_C1AD31LRP\0"}, 
{444,"lEM_R0IE01LRP\0"}, 
{445,"lEM_R0IE02LRP\0"}, 
{446,"fEM_A2UP02RIM\0"}, 
{447,"fEM_A2UP03RIM\0"}, 
{448,"fEM_A0UP01RIM\0"}, 
{449,"fEM_A3UP02RIM\0"}, 
{450,"fEM_A4UP01RIM\0"}, 
{451,"fEM_A4UP02RIM\0"}, 
{452,"fEM_R7UI76RIM\0"}, 
{453,"fEM_R7UI77RIM\0"}, 
{454,"iEM_TERBB1\0"}, 
{455,"fEM_A1MC02RC1\0"}, 
{456,"fEM_A1MV02RC1\0"}, 
{457,"iEM_TERBB2\0"}, 
{458,"fEM_B1MC02RC1\0"}, 
{459,"fEM_B1MV02RC1\0"}, 
{460,"iEM_TERRB2\0"}, 
{461,"fEM_B2MC02RC1\0"}, 
{462,"fEM_B2MV02RC1\0"}, 
{463,"iEM_TERRB1\0"}, 
{464,"fEM_A2MC02RC1\0"}, 
{465,"fEM_A2MV02RC1\0"}, 
{466,"iEM_TERIS2\0"}, 
{467,"fEM_B3MC02RC1\0"}, 
{468,"fEM_B3MV02RC1\0"}, 
{469,"iEM_TERIS1\0"}, 
{470,"fEM_A3MC02RC1\0"}, 
{471,"fEM_A3MV02RC1\0"}, 
{472,"iEM_TERA1IE04LDU\0"}, 
{473,"iEM_TERA1IE03LDU\0"}, 
{474,"fEM_A1MC01RC1\0"}, 
{475,"iEM_TERB1IE03LDU\0"}, 
{476,"iEM_TERB1IE04LDU\0"}, 
{477,"fEM_B1MC01RC1\0"}, 
{478,"fEM_B1MV01RC1\0"}, 
{479,"fEM_B2MC01RC1\0"}, 
{480,"fEM_B2MV01RC1\0"}, 
{481,"fEM_A3MC01RC1\0"}, 
{482,"fEM_A3MV01RC1\0"}, 
{483,"fEM_B3MC01RC1\0"}, 
{484,"fEM_B3MV01RC1\0"}, 
{485,"iEM_TERA2SS21LIM\0"}, 
{486,"iEM_TERA2SS12LIM\0"}, 
{487,"iEM_TERR6SS21LIM\0"}, 
{488,"iEM_TERA2VP82LIM\0"}, 
{489,"iEM_TERA2SS11LIM\0"}, 
{490,"iEM_TERB3SS21LIM\0"}, 
{491,"iEM_TERA0MT01RIM\0"}, 
{492,"iEM_TERB0MT01RIM\0"}, 
{493,"iEM_TERA2SP01RIM\0"}, 
{494,"iEM_TERB2SP01RIM\0"}, 
{495,"iEM_TERB3SP02RIM\0"}, 
{496,"iEM_TERA3SC01RIM\0"}, 
{497,"iEM_TERA3VP81LIM\0"}, 
{498,"iEM_TERA2SC01RIM\0"}, 
{499,"iEM_TERA2SS33LIM\0"}, 
{500,"iEM_TERA3SS21LIM\0"}, 
{501,"iEM_TERA3SS33LIM\0"}, 
{502,"iEM_TERA3SS31LIM\0"}, 
{503,"iEM_TERB3SS31LIM\0"}, 
{504,"iEM_TERB3SS33LIM\0"}, 
{505,"iEM_TERB3SC01RIM\0"}, 
{506,"iEM_TERA3SS11LIM\0"}, 
{507,"iEM_TERB3SS11LIM\0"}, 
{508,"iEM_TERR6IS64LIM\0"}, 
{509,"iEM_TERB3SS22LIM\0"}, 
{510,"iEM_TERA3SS22LIM\0"}, 
{511,"iEM_TERA3SP02RIM\0"}, 
{512,"iEM_TERR6IS62LIM\0"}, 
{513,"iEM_TERR6IS66LIM\0"}, 
{514,"iEM_TERR6IS67LIM\0"}, 
{515,"iEM_TERA0VP81LIM\0"}, 
{516,"iEM_TERB0VP81LIM\0"}, 
{517,"iEM_TERR0VP81LIM\0"}, 
{518,"iEM_TERR6IS68LIM\0"}, 
{519,"iEM_TERR7SI74RIM\0"}, 
{520,"iEM_TERA5SS21LIM\0"}, 
{521,"iEM_TERB5SS11LIM\0"}, 
{522,"iEM_TERA5SS11LIM\0"}, 
{523,"iEM_TERA9SS11LIM\0"}, 
{524,"iEM_TERB2SS11LIM\0"}, 
{525,"iEM_TERB2SS12LIM\0"}, 
{526,"iEM_TERB2SS21LIM\0"}, 
{527,"iEM_TERR3SS11LIM\0"}, 
{528,"iEM_TERB2SC01RIM\0"}, 
{529,"iEM_TERR3SS21LIM\0"}, 
{530,"iEM_TERR5SS11LIM\0"}, 
{531,"iEM_TERA4SS11LIM\0"}, 
{532,"iEM_TERR1SS11LIM\0"}, 
{533,"iEM_TERR1SS21LIM\0"}, 
{534,"iEM_TERR2SS11LIM\0"}, 
{535,"iEM_TERR2SS21LIM\0"}, 
{536,"iEM_TERA4VP82LIM\0"}, 
{537,"iEM_TERB4SS21LIM\0"}, 
{538,"iEM_TERR5SS21LIM\0"}, 
{539,"iEM_TERB6SS21LIM\0"}, 
{540,"iEM_TERB4SS11LIM\0"}, 
{541,"iEM_TERA4SS21LIM\0"}, 
{542,"iEM_TERA6MS11LIM\0"}, 
{543,"iEM_TERA6SS21LIM\0"}, 
{544,"iEM_TERB6SS11LIM\0"}, 
{545,"iEM_TERR4SS11LIM\0"}, 
{546,"iEM_TERR4MS21LIM\0"}, 
{547,"iEM_TERR4SS12LIM\0"}, 
{548,"iEM_TERR4SS22LIM\0"}, 
{549,"iEM_TERR8SS11LIM\0"}, 
{550,"iEM_TERB8SC01RIM\0"}, 
{551,"iEM_TERA8SC01RIM\0"}, 
{552,"iEM_TERB8SS12LIM\0"}, 
{553,"iEM_TERA8SS12LIM\0"}, 
{554,"iEM_TERB8SS22LIM\0"}, 
{555,"iEM_TERA8SS22LIM\0"}, 
{556,"iEM_TERA9SS21LIM\0"}, 
{557,"iEM_TERB9SS21LIM\0"}, 
{558,"iEM_TERB9SS11LIM\0"}, 
{559,"iEM_TERB5SS21LIM\0"}, 
{560,"iEM_TERA1SS21LIM\0"}, 
{561,"iEM_TERA1SS11LIM\0"}, 
{562,"iEM_TERA1SC01RIM\0"}, 
{563,"iEM_TERA1SS12LIM\0"}, 
{564,"iEM_TERB1SS21LIM\0"}, 
{565,"iEM_TERB1SS11LIM\0"}, 
{566,"iEM_TERB1MC01RIM\0"}, 
{567,"iEM_TERB1SS12LIM\0"}, 
{568,"iEM_TERTLG\0"}, 
{569,"fEM_R4MC01RC1\0"}, 
{570,"fEM_R4MV01RC1\0"}, 
{571,"iEM_TERMAZ2\0"}, 
{572,"fEM_B8MC01RC1\0"}, 
{573,"fEM_B8MV01RC1\0"}, 
{574,"iEM_TERDS2\0"}, 
{575,"fEM_A8MC01RC1\0"}, 
{576,"fEM_A8MV01RC1\0"}, 
{577,"iEM_TERBZ1\0"}, 
{578,"fEM_A6MC01RC1\0"}, 
{579,"fEM_A6MV01RC1\0"}, 
{580,"iEM_TERBZ2\0"}, 
{581,"fEM_B6MC01RC1\0"}, 
{582,"fEM_B6MV01RC1\0"}, 
{583,"lEM_R3AD10LC1\0"}, 
{584,"lEM_R3AD20LC1\0"}, 
{585,"lEM_R6AD10LC1\0"}, 
{586,"lEM_R5AD10LC1\0"}, 
{587,"lEM_R5AD20LC1\0"}, 
{588,"iEM_TERMDZ2\0"}, 
{589,"fEM_R2MC01RC1\0"}, 
{590,"fEM_R2MV01RC1\0"}, 
{591,"iEM_TERMDZ1\0"}, 
{592,"fEM_R1MC01RC1\0"}, 
{593,"fEM_R1MV01RC1\0"}, 
{594,"iEM_TERNL1\0"}, 
{595,"fEM_A5MC01RC1\0"}, 
{596,"fEM_A5MV01RC1\0"}, 
{597,"iEM_TERNL2\0"}, 
{598,"fEM_B5MC01RC1\0"}, 
{599,"fEM_B5MV01RC1\0"}, 
{600,"lEM_R8AD10LC1\0"}, 
{601,"fEM_A1UC08RIM\0"}, 
{602,"fEM_A2UC08RIM\0"}, 
{603,"fEM_A3UC08RIM\0"}, 
{604,"iEM_TERB2SS33LIM\0"}, 
{605,"iEM_TERA1VP81LIM\0"}, 
{606,"iEM_TERB1VP81LIM\0"}, 
{607,"fEM_A0UT03RSP\0"}, 
{608,"fEM_A0UR01RSP\0"}, 
{609,"fEM_A0UR02RSP\0"}, 
{610,"fEM_B0UT03RSP\0"}, 
{611,"fEM_A1MC01RSP\0"}, 
{612,"fEM_A1MC02RSP\0"}, 
{613,"fEM_A1MV01RSP\0"}, 
{614,"fEM_A1MV02RSP\0"}, 
{615,"fEM_B1MC01RSP\0"}, 
{616,"fEM_B1MV01RSP\0"}, 
{617,"fEM_B1MC02RSP\0"}, 
{618,"fEM_B1MV02RSP\0"}, 
{619,"fEM_A2MC01RC1\0"}, 
{620,"fEM_A2MV01RC1\0"}, 
{621,"fEM_A2MC01RSP\0"}, 
{622,"fEM_A2MV01RSP\0"}, 
{623,"fEM_A2MC02RSP\0"}, 
{624,"fEM_A2MV02RSP\0"}, 
{625,"fEM_B2MC01RSP\0"}, 
{626,"fEM_B2MV01RSP\0"}, 
{627,"fEM_B2MC02RSP\0"}, 
{628,"fEM_B2MV02RSP\0"}, 
{629,"fEM_A3MC01RSP\0"}, 
{630,"fEM_A3MV01RSP\0"}, 
{631,"fEM_A3MC02RSP\0"}, 
{632,"fEM_A3MV02RSP\0"}, 
{633,"fEM_B3MC01RSP\0"}, 
{634,"fEM_B3MV01RSP\0"}, 
{635,"fEM_B3MC02RSP\0"}, 
{636,"fEM_B3MV02RSP\0"}, 
{637,"fEM_B8MC01RSP\0"}, 
{638,"fEM_B8MV01RSP\0"}, 
{639,"fEM_A8MC01RSP\0"}, 
{640,"fEM_A8MV01RSP\0"}, 
{641,"fEM_A6MC01RSP\0"}, 
{642,"fEM_A6MV01RSP\0"}, 
{643,"fEM_B6MC01RSP\0"}, 
{644,"fEM_B6MV01RSP\0"}, 
{645,"fEM_R3UC01RSP\0"}, 
{646,"fEM_R3UV01RSP\0"}, 
{647,"fEM_R5UC01RSP\0"}, 
{648,"fEM_R5UV01RSP\0"}, 
{649,"fEM_R6UC01RSP\0"}, 
{650,"fEM_R6UV01RSP\0"}, 
{651,"fEM_R2MC01RSP\0"}, 
{652,"fEM_R2MV01RSP\0"}, 
{653,"fEM_R1MC01RSP\0"}, 
{654,"fEM_R1MV01RSP\0"}, 
{655,"fEM_A5MC01RSP\0"}, 
{656,"fEM_A5MV01RSP\0"}, 
{657,"fEM_B5MC01RSP\0"}, 
{658,"fEM_B5MV01RSP\0"}, 
{659,"fEM_A9MC01RSP\0"}, 
{660,"fEM_A9MV01RSP\0"}, 
{661,"fEM_B9MC01RSP\0"}, 
{662,"fEM_B9MV01RSP\0"}, 
{663,"fEM_A4MC01RSP\0"}, 
{664,"fEM_A4MV01RSP\0"}, 
{665,"fEM_B4MC01RSP\0"}, 
{666,"fEM_B4MV01RSP\0"}, 
{667,"fEM_R4MC01RSP\0"}, 
{668,"fEM_R4MV01RSP\0"}, 
{669,"fEM_A1MV01RC1\0"}, 
{670,"iEM_TERB7MS31LIM\0"}, 
{671,"iEM_TERA7MS31LIM\0"}, 
{672,"fEM_R7UY00RSS\0"}, 
{673,"iEM_TERA6VS12LIM\0"}, 
{674,"iEM_TERA6VS22LIM\0"}, 
{675,"iEM_TERB6VS12LIM\0"}, 
{676,"iEM_TERB6VS22LIM\0"}, 
{677,"iEM_TERA5VS22LIM\0"}, 
{678,"iEM_TERA5VS12LIM\0"}, 
{679,"iEM_TERB5VS12LIM\0"}, 
{680,"iEM_TERB5VS22LIM\0"}, 
{681,"iEM_TERR1VS12LIM\0"}, 
{682,"iEM_TERR1VS22LIM\0"}, 
{683,"iEM_TERR2VS12LIM\0"}, 
{684,"iEM_TERR2VS22LIM\0"}, 
{685,"iEM_TERR4VS12LDU\0"}, 
{686,"iEM_TERR4VS22LDU\0"}, 
{687,"fEM_R4UC23RIM\0"}, 
{688,"fEM_A0UX13RSS\0"}, 
{689,"fEM_A0UX14RSS\0"}, 
{690,"fEM_A0UX15RSS\0"}, 
{691,"fEM_R7UX13RSS\0"}, 
{692,"fEM_R7UX14RSS\0"}, 
{693,"fEM_R7UX15RSS\0"}, 
{694,"fEM_R7UY13RSS\0"}, 
{695,"fEM_R7UY14RSS\0"}, 
{696,"fEM_R7UY15RSS\0"}, 
{697,"fEM_R7UX16RSS\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_SCM[]={  // 
	{&R0AD14LDU,1,0},	//( - , SCM) Имитация срабатывания верхней АС II УР
	{&R0VZ71LZ1,1,1},	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
	{&R0VZ71LZ2,1,2},	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
	{&C2MD31LP1,1,3},	//( - , SCM) Кнопка «СБРОС РБ»
	{&C1MD31LP2,1,4},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
	{&C1MD31LP1,1,5},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
	{&R0MW13LP2,1,6},	//( - , SCM) Переключатель «СЕТЬ»
	{&lEM_C1AD31LRP,1,7},	//( - , SCM) Общий сброс от РПУ
	{&lEM_R0IE01LRP,1,8},	//( - , SCM) Отключение питание детекторов
	{&lEM_R0IE02LRP,1,9},	//( - , SCM) Отключить питание ПР, ПУ
	{&lEM_R3AD10LC1,1,10},	//( - , SCM) Гомогенные двери-1 открыть от ИС
	{&lEM_R3AD20LC1,1,11},	//( - , SCM) Гомогенные двери-1 закрыть от ИС
	{&lEM_R6AD10LC1,1,12},	//( - , SCM) Выкатить кран-балку от ИС
	{&lEM_R5AD10LC1,1,13},	//( - , SCM) Открыть ворота отстойной зоны от ИС
	{&lEM_R5AD20LC1,1,14},	//( - , SCM) Закрыть ворота отстойной зоны от ИС
	{&lEM_R8AD10LC1,1,15},	//( - , SCM) Установить аварийный НИ от ИС
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SCM[]={  // 
	{&A2IS11LIM,1,0},	//( - , SCM) Магнит РБ1 обесточен
	{&A2IS32LIM,1,1},	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
	{&B2IS11LIM,1,2},	//( - , SCM) Магнит РБ2 обесточен
	{&B2IS32LIM,1,3},	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
	{&A6VS22LDU,1,4},	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
	{&A6VS12LDU,1,5},	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
	{&B6VS22LDU,1,6},	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
	{&B6VS12LDU,1,7},	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
	{&A5VS22LDU,1,8},	//( - , SCM) Движение НЛ1 в сторону НУ
	{&A5VS12LDU,1,9},	//( - , SCM) Движение НЛ1 в сторону ВУ
	{&B5VS22LDU,1,10},	//( - , SCM) Движение НЛ2 в сторону НУ
	{&B5VS12LDU,1,11},	//( - , SCM) Движение НЛ2 в сторону ВУ
	{&R1VS22LDU,1,12},	//( - , SCM) Движение МДЗ1 в сторону НУ
	{&R2VS22LDU,1,13},	//( - , SCM) Движение МДЗ2 в сторону НУ
	{&R2VS12LDU,1,14},	//( - , SCM) Движение МДЗ2 в сторону ВУ
	{&R1VS12LDU,1,15},	//( - , SCM) Движение МДЗ1 в сторону ВУ
	{&R4VS22LDU,1,16},	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
	{&R4VS12LDU,1,17},	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
	{&A2VP82LDU,1,18},	//( - , SCM) Давление ПОДЪЁМ РБ1 в норме
	{&A3VP81LDU,1,19},	//( - , SCM) Давление СПУСК ИС1 в норме
	{&B3VP81LDU,1,20},	//( - , SCM) Давление СПУСК ИС2 в норме
	{&B2VP82LDU,1,21},	//( - , SCM) Давление ПОДЪЁМ РБ2 в норме
	{&B4IS21LDU,1,22},	//( - K08DO, SCM) Приход на НУ НИ2
	{&A4VP82LDU,1,23},	//( - , SCM) Давление ПОДЪЁМ НИ1 в норме
	{&B4VP82LDU,1,24},	//( - , SCM) Давление ПОДЪЁМ НИ2 в норме
	{&A1IE03LDU,1,25},	//( - , SCM) Движение ББ1 вперед (от БУШД)
	{&A1IE04LDU,1,26},	//( - , SCM) Движение ББ1 назад (от БУШД)
	{&B1IE03LDU,1,27},	//( - , SCM) Движение ББ2 вперед (от БУШД)
	{&B1IE04LDU,1,28},	//( - , SCM) Движение ББ2 назад (от БУШД)
	{&A1IS11LIM,1,29},	//( - , SCM) Магнит ББ1 обесточен
	{&A1IS32LIM,1,30},	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
	{&B1IS11LIM,1,31},	//( - , SCM) Магнит ББ2 обесточен
	{&B1IS32LIM,1,32},	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SCM[]={  // 
	{&A0VN01RIM,8,0},	//( - , SCM) Период разгона  AЗ1
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
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SCM[]={  // 
	{&fEM_R0UL01RIM,8,0},	//( - , SCM) Среднее время генерации нейтронов
	{&fEM_R0UN02RIM,8,2},	//( - , SCM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{&fEM_A1UR01RIM,8,4},	//( - , SCM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{&fEM_A1UR00RIM,8,6},	//( - , SCM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{&fEM_A3UR00RIM,8,8},	//( - , SCM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{&fEM_A3UR01RIM,8,10},	//( - , SCM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{&fEM_R0UT01RIM,8,12},	//( - , SCM) Температурный коэффициент (долл)
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
	{&fEM_R4UV80RDU,8,48},	//( - , SCM) Номинальная скорость тележки (мм/с)
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
	{&fEM_R7UX01RSS,8,150},	//( - , SCM) X-координата камеры R7IN11
	{&fEM_R7UX02RSS,8,152},	//( - , SCM) X-координата камеры R7IN12 (см)
	{&fEM_R7UX04RSS,8,154},	//( - , SCM) X-координата камеры R7IN21 (см)
	{&fEM_R7UX05RSS,8,156},	//( - , SCM) X-координата камеры R7IN22 (см)
	{&fEM_R7UX06RSS,8,158},	//( - , SCM) X-координата камеры R7IN23 (см)
	{&fEM_R7UX07RSS,8,160},	//( - , SCM) X-координата камеры R7IN31 (см)
	{&fEM_R7UX08RSS,8,162},	//( - , SCM) X-координата камеры R7IN32 (см)
	{&fEM_R7UX09RSS,8,164},	//( - , SCM) X-координата камеры R7IN33 (см)
	{&fEM_R7UY01RSS,8,166},	//( - , SCM) Y-координата камеры R7IN11
	{&fEM_R7UY02RSS,8,168},	//( - , SCM) Y-координата камеры R7IN12 (см)
	{&fEM_R7UY04RSS,8,170},	//( - , SCM) Y-координата камеры R7IN21 (см)
	{&fEM_R7UY05RSS,8,172},	//( - , SCM) Y-координата камеры R7IN22 (см)
	{&fEM_R7UY06RSS,8,174},	//( - , SCM) Y-координата камеры R7IN23 (см)
	{&fEM_R7UY07RSS,8,176},	//( - , SCM) Y-координата камеры R7IN31 (см)
	{&fEM_R7UY08RSS,8,178},	//( - , SCM) Y-координата камеры R7IN32 (см)
	{&fEM_R7UY09RSS,8,180},	//( - , SCM) Y-координата камеры R7IN33 (см)
	{&fEM_R7UX10RSS,8,182},	//( - , SCM) X-координата камеры R7IN41
	{&fEM_R7UX11RSS,8,184},	//( - , SCM) X-координата камеры R7IN42
	{&fEM_R7UX12RSS,8,186},	//( - , SCM) X-координата камеры R7IN43
	{&fEM_R7UY10RSS,8,188},	//( - , SCM) Y-координата камеры R7IN41
	{&fEM_R7UY11RSS,8,190},	//( - , SCM) Y-координата камеры R7IN42
	{&fEM_R7UY12RSS,8,192},	//( - , SCM) Y-координата камеры R7IN43
	{&fEM_A0UX01RSS,8,194},	//( - , SCM) Первый коэффициент калибровки камеры 1
	{&fEM_A0UX02RSS,8,196},	//( - , SCM) Первый коэффициент калибровки камеры 2
	{&fEM_A0UX03RSS,8,198},	//( - , SCM) Первый коэффициент калибровки камеры 3
	{&fEM_A0UX04RSS,8,200},	//( - , SCM) Первый коэффициент калибровки камеры4
	{&fEM_A0UX05RSS,8,202},	//( - , SCM) Первый коэффициент калибровки камеры 5
	{&fEM_A0UX06RSS,8,204},	//( - , SCM) Первый коэффициент калибровки камеры 6
	{&fEM_A0UX07RSS,8,206},	//( - , SCM) Первый коэффициент калибровки камеры 7
	{&fEM_A0UX08RSS,8,208},	//( - , SCM) Первый коэффициент калибровки камеры 8
	{&fEM_A0UX09RSS,8,210},	//( - , SCM) Первый коэффициент калибровки камеры 9
	{&fEM_A0UX10RSS,8,212},	//( - , SCM) Первый коэффициент калибровки камеры 10
	{&fEM_A0UX11RSS,8,214},	//( - , SCM) Первый коэффициент калибровки камеры 11
	{&fEM_A0UX12RSS,8,216},	//( - , SCM) Первый коэффициент калибровки камеры 12
	{&fEM_B0UX01RSS,8,218},	//( - , SCM) Второй коэффициент калибровки камеры 1
	{&fEM_B0UX02RSS,8,220},	//( - , SCM) Второй коэффициент калибровки камеры 2
	{&fEM_B0UX06RSS,8,222},	//( - , SCM) Второй коэффициент калибровки камеры 6
	{&fEM_B0UX07RSS,8,224},	//( - , SCM) Второй коэффициент калибровки камеры 7
	{&fEM_B0UX08RSS,8,226},	//( - , SCM) Второй коэффициент калибровки камеры 8
	{&fEM_B0UX09RSS,8,228},	//( - , SCM) Второй коэффициент калибровки камеры 9
	{&fEM_B0UX10RSS,8,230},	//( - , SCM) Второй коэффициент калибровки камеры 10
	{&fEM_B0UX11RSS,8,232},	//( - , SCM) Второй коэффициент калибровки камеры 11
	{&fEM_B0UX12RSS,8,234},	//( - , SCM) Второй коэффициент калибровки камеры 12
	{&fEM_R4US80RDU,8,236},	//( - , SCM) Тормозной путь тележки (мм)
	{&fEM_R7UI71RIM,8,238},	//( - , SCM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{&fEM_R7UI72RIM,8,240},	//( - , SCM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{&fEM_R7UI73RIM,8,242},	//( - , SCM) Уровень мощности срабатывания АС II УР  ватт
	{&fEM_A1UP01RIM,8,244},	//( - , SCM) Текущее давление на сброс ББ (МПа)
	{&fEM_A2UP01RIM,8,246},	//( - , SCM) Текущее давление на сброс РБ
	{&fEM_A0UP02RIM,8,248},	//( - , SCM) Текущее давление в АЗ1,2
	{&fEM_A3UP01RIM,8,250},	//( - , SCM) Текущее давление на СПУСК ИС
	{&fEM_A1UP82RIM,8,252},	//( - , SCM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{&fEM_A3UP02RDU,8,254},	//( - , SCM) Текущее давление ВЫСТРЕЛ ИС
	{&fEM_A1UV02RIM,8,256},	//( - , SCM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{&fEM_A3UV02RIM,8,258},	//( - , SCM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{&fEM_A2UV02RIM,8,260},	//( - , SCM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{&fEM_B8US80RDU,8,262},	//( - , SCM) Тормозной путь АЗ2 (мм)
	{&fEM_A8US80RDU,8,264},	//( - , SCM) Тормозной путь ДС2 (мм)
	{&fEM_A6US80RDU,8,266},	//( - , SCM) Тормозной путь БЗ (мм)
	{&fEM_A1US07RDU,8,268},	//( - , SCM) Постоянная времени масляного демпфера ББ
	{&fEM_A2US07RDU,8,270},	//( - , SCM) Постоянная времени масляного демпфера РБ
	{&fEM_A3US07RDU,8,272},	//( - , SCM) Постоянная времени масляного демпфера ИС
	{&fEM_R7UI75RIM,8,274},	//( - , SCM) Множитель к уровню радиации
	{&fEM_R0UH05RSS,8,276},	//( - , SCM) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_A4UL10RIM,8,278},	//( - , SCM) Время полного перемещения НИ сек
	{&fEM_A9UL10RIM,8,280},	//( - , SCM) Время полного перемещения НИ ДС1/ДС2 сек
	{&fEM_R3UL10RIM,8,282},	//( - , SCM) Время полного хода гомогенных дверей (сек)
	{&fEM_R5UL10RIM,8,284},	//( - , SCM) Время полного хода ворот отстойной зоны (дес. мс)
	{&fEM_R6UL10RIM,8,286},	//( - , SCM) Время полного хода кран-балки сек
	{&fEM_A2UP02RIM,8,288},	//( - , SCM) Текущее давление на подъём РБ
	{&fEM_A2UP03RIM,8,290},	//( - , SCM) Нижняя граница давления на ПОДЪЁМ РБ
	{&fEM_A0UP01RIM,8,292},	//( - , SCM) Текущее давление в АЗ1,2
	{&fEM_A3UP02RIM,8,294},	//( - , SCM) Нижняя граница  давления на СПУСК ИС
	{&fEM_A4UP01RIM,8,296},	//( - , SCM) Текущее давление на подъём НИ
	{&fEM_A4UP02RIM,8,298},	//( - , SCM) Нижняя граница давления на подъём НИ
	{&fEM_R7UI76RIM,8,300},	//( - , SCM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{&fEM_R7UI77RIM,8,302},	//( - , SCM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{&iEM_TERBB1,3,304},	//( - , SCM) Неисправности  ББ1
	{&fEM_A1MC02RC1,8,305},	//( - , SCM) Заданная координата штока ББ1 от ИС
	{&fEM_A1MV02RC1,8,307},	//( - , SCM) Заданная скорость движения  штока ББ1 от ИС
	{&iEM_TERBB2,3,309},	//( - , SCM) Неисправности  ББ2
	{&fEM_B1MC02RC1,8,310},	//( - , SCM) Заданная координата штока ББ2 от ИС
	{&fEM_B1MV02RC1,8,312},	//( - , SCM) Заданная скорость движения штока ББ2 от ИС
	{&iEM_TERRB2,3,314},	//( - , SCM) Неисправности  РБ2
	{&fEM_B2MC02RC1,8,315},	//( - , SCM) Заданная координата штока РБ2 от ИС
	{&fEM_B2MV02RC1,8,317},	//( - , SCM) Заданная скорость движения штока РБ2 от ИС
	{&iEM_TERRB1,3,319},	//( - , SCM) Неисправности  РБ1
	{&fEM_A2MC02RC1,8,320},	//( - , SCM) Заданная координата штока РБ1 от ИС
	{&fEM_A2MV02RC1,8,322},	//( - , SCM) Заданная скорость движения штока РБ1 от ИС
	{&iEM_TERIS2,3,324},	//( - , SCM) Неисправности  ИС2
	{&fEM_B3MC02RC1,8,325},	//( - , SCM) Заданная координата штока ИС2 от ИС
	{&fEM_B3MV02RC1,8,327},	//( - , SCM) Заданная скорость движения штока ИС2 от ИС
	{&iEM_TERIS1,3,329},	//( - , SCM) Неисправности  ИС1
	{&fEM_A3MC02RC1,8,330},	//( - , SCM) Заданная координата штока ИС1 от ИС
	{&fEM_A3MV02RC1,8,332},	//( - , SCM) Заданная скорость движения штока ИС1 от ИС
	{&iEM_TERA1IE04LDU,3,334},	//( - , SCM) Искажение Движение ББ1 назад (от БУШД)
	{&iEM_TERA1IE03LDU,3,335},	//( - , SCM) Искажение Движение ББ1 вперёд (от БУШД)
	{&fEM_A1MC01RC1,8,336},	//( - , SCM) Заданная координата  ББ1 от ИС
	{&iEM_TERB1IE03LDU,3,338},	//( - , SCM) Искажение Движение ББ2 вперёд (от БУШД)
	{&iEM_TERB1IE04LDU,3,339},	//( - , SCM) Искажение Движение ББ2 назад (от БУШД)
	{&fEM_B1MC01RC1,8,340},	//( - , SCM) Заданная координата ББ2 от ИС
	{&fEM_B1MV01RC1,8,342},	//( - , SCM) Заданная скорость движения ББ2 от ИС
	{&fEM_B2MC01RC1,8,344},	//( - , SCM) Заданная координата РБ2 от ИС
	{&fEM_B2MV01RC1,8,346},	//( - , SCM) Заданная скорость движения  РБ2 от ИС
	{&fEM_A3MC01RC1,8,348},	//( - , SCM) Заданная координата ИС1 от ИС
	{&fEM_A3MV01RC1,8,350},	//( - , SCM) Заданная скорость движения ИС1 от ИС
	{&fEM_B3MC01RC1,8,352},	//( - , SCM) Заданная координата ИС2 от ИС
	{&fEM_B3MV01RC1,8,354},	//( - , SCM) Заданная скорость движения ИС2 от ИС
	{&iEM_TERA2SS21LIM,3,356},	//( - , SCM) Искажение: Приход на НУ РБ1
	{&iEM_TERA2SS12LIM,3,357},	//( - , SCM) Искажение: Магнит РБ1 зацеплен
	{&iEM_TERR6SS21LIM,3,358},	//( - , SCM) Искажение: Кран-балка в нерабочем положении
	{&iEM_TERA2VP82LIM,3,359},	//( - , SCM) Искажение: Текущее давление на подъём РБ  в норме
	{&iEM_TERA2SS11LIM,3,360},	//( - , SCM) Искажение: Приход на ВУ РБ1
	{&iEM_TERB3SS21LIM,3,361},	//( - , SCM) Искажение: Приход на НУ ИС2
	{&iEM_TERA0MT01RIM,3,362},	//( - , SCM) Искажение: Текущая температура AЗ1
	{&iEM_TERB0MT01RIM,3,363},	//( - , SCM) Искажение: Текущая температура AЗ2
	{&iEM_TERA2SP01RIM,3,364},	//( - , SCM) Искажение: Текущее давление СБРОС РБ1
	{&iEM_TERB2SP01RIM,3,365},	//( - , SCM) Искажение: Текущее давление СБРОС РБ2
	{&iEM_TERB3SP02RIM,3,366},	//( - , SCM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{&iEM_TERA3SC01RIM,3,367},	//( - , SCM) Искажение: Координата штока ИС1
	{&iEM_TERA3VP81LIM,3,368},	//( - , SCM) Искажение: Текущее давление СПУСК ИС  в норме
	{&iEM_TERA2SC01RIM,3,369},	//( - , SCM) Искажение: Координата штока РБ1
	{&iEM_TERA2SS33LIM,3,370},	//( - , SCM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{&iEM_TERA3SS21LIM,3,371},	//( - , SCM) Искажение: Приход на НУ ИС1
	{&iEM_TERA3SS33LIM,3,372},	//( - , SCM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{&iEM_TERA3SS31LIM,3,373},	//( - , SCM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{&iEM_TERB3SS31LIM,3,374},	//( - , SCM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{&iEM_TERB3SS33LIM,3,375},	//( - , SCM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{&iEM_TERB3SC01RIM,3,376},	//( - , SCM) Искажение: Координата штока ИС2
	{&iEM_TERA3SS11LIM,3,377},	//( - , SCM) Искажение: Приход на ВУ ИС1
	{&iEM_TERB3SS11LIM,3,378},	//( - , SCM) Искажение: Приход на ВУ ИС2
	{&iEM_TERR6IS64LIM,3,379},	//( - , SCM) Искажение: Исправность ВИП ССДИ-35
	{&iEM_TERB3SS22LIM,3,380},	//( - , SCM) Искажение: Приход на НУП ИС2
	{&iEM_TERA3SS22LIM,3,381},	//( - , SCM) Искажение: Приход на НУП ИС1
	{&iEM_TERA3SP02RIM,3,382},	//( - , SCM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{&iEM_TERR6IS62LIM,3,383},	//( - , SCM) Искажение Исправность ВИП ССДИ-39
	{&iEM_TERR6IS66LIM,3,384},	//( - , SCM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{&iEM_TERR6IS67LIM,3,385},	//( - , SCM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{&iEM_TERA0VP81LIM,3,386},	//( - , SCM) Искажение: Давление  АЗ1  в норме
	{&iEM_TERB0VP81LIM,3,387},	//( - , SCM) Искажение: Давление  АЗ2 в норме
	{&iEM_TERR0VP81LIM,3,388},	//( - , SCM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{&iEM_TERR6IS68LIM,3,389},	//( - , SCM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{&iEM_TERR7SI74RIM,3,390},	//( - , SCM) Искажение: Радиация в реакторном зале
	{&iEM_TERA5SS21LIM,3,391},	//( - , SCM) Искажение: Приход на НУ НЛ1
	{&iEM_TERB5SS11LIM,3,392},	//( - , SCM) Искажение: Приход на ВУ НЛ2
	{&iEM_TERA5SS11LIM,3,393},	//( - , SCM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{&iEM_TERA9SS11LIM,3,394},	//( - , SCM) Искажение: Приход на ВУ НИ ДС1
	{&iEM_TERB2SS11LIM,3,395},	//( - , SCM) Искажение: Приход на ВУ РБ2
	{&iEM_TERB2SS12LIM,3,396},	//( - , SCM) Искажение: Магнит РБ2 зацеплен
	{&iEM_TERB2SS21LIM,3,397},	//( - , SCM) Искажение: Приход на НУ РБ2
	{&iEM_TERR3SS11LIM,3,398},	//( - , SCM) Искажение: Приход на ВУ гомогенных дверей-1
	{&iEM_TERB2SC01RIM,3,399},	//( - , SCM) Искажение: Координата штока РБ2
	{&iEM_TERR3SS21LIM,3,400},	//( - , SCM) Искажение: Приход на НУ гомогенных дверей-1
	{&iEM_TERR5SS11LIM,3,401},	//( - , SCM) Искажение: Приход на ВУ ворот отстойной зоны
	{&iEM_TERA4SS11LIM,3,402},	//( - , SCM) Искажение: Приход на ВУ НИ1
	{&iEM_TERR1SS11LIM,3,403},	//( - , SCM) Искажение: Приход на ВУ МДЗ1
	{&iEM_TERR1SS21LIM,3,404},	//( - , SCM) Искажение: Приход на НУ МДЗ1
	{&iEM_TERR2SS11LIM,3,405},	//( - , SCM) Искажение: Приход на ВУ МДЗ2
	{&iEM_TERR2SS21LIM,3,406},	//( - , SCM) Искажение: Приход на НУ МДЗ2
	{&iEM_TERA4VP82LIM,3,407},	//( - , SCM) Искажение Давление ПОДЪЁМ НИ в норме
	{&iEM_TERB4SS21LIM,3,408},	//( - , SCM) Искажение: Приход на НУ НИ2
	{&iEM_TERR5SS21LIM,3,409},	//( - , SCM) Искажение: Приход на НУ ворот отстойной зоны
	{&iEM_TERB6SS21LIM,3,410},	//( - , SCM) Искажение: Приход на НУ БЗ2
	{&iEM_TERB4SS11LIM,3,411},	//( - , SCM) Искажение: Приход на ВУ НИ2
	{&iEM_TERA4SS21LIM,3,412},	//( - , SCM) Искажение: Приход на НУ НИ1
	{&iEM_TERA6MS11LIM,3,413},	//( - , SCM) Искажение: Приход на ВУ БЗ1
	{&iEM_TERA6SS21LIM,3,414},	//( - , SCM) Искажение: Приход на НУ БЗ1
	{&iEM_TERB6SS11LIM,3,415},	//( - , SCM) Искажение: Приход на ВУ БЗ2
	{&iEM_TERR4SS11LIM,3,416},	//( - , SCM) Искажение: Приход на ВУ тележки
	{&iEM_TERR4MS21LIM,3,417},	//( - , SCM) Искажение: Приход на НУ тележки
	{&iEM_TERR4SS12LIM,3,418},	//( - , SCM) Искажение: Приход на механический ВУ тележки
	{&iEM_TERR4SS22LIM,3,419},	//( - , SCM) Искажение: Приход на механический НУ тележки
	{&iEM_TERR8SS11LIM,3,420},	//( - , SCM) Искажение: Аварийный НИ установлен
	{&iEM_TERB8SC01RIM,3,421},	//( - , SCM) Искажение: Координата АЗ2
	{&iEM_TERA8SC01RIM,3,422},	//( - , SCM) Искажение: Координата ДС2
	{&iEM_TERB8SS12LIM,3,423},	//( - , SCM) Искажение: Приход на механический ВУ АЗ2
	{&iEM_TERA8SS12LIM,3,424},	//( - , SCM) Искажение: Приход на механический ВУ ДС2
	{&iEM_TERB8SS22LIM,3,425},	//( - , SCM) Искажение: Приход на механический НУ АЗ2
	{&iEM_TERA8SS22LIM,3,426},	//( - , SCM) Искажение: Приход на механический НУ ДС2
	{&iEM_TERA9SS21LIM,3,427},	//( - , SCM) Искажение: Приход на НУ НИ ДС1
	{&iEM_TERB9SS21LIM,3,428},	//( - , SCM) Искажение: Приход на НУ НИ ДС2
	{&iEM_TERB9SS11LIM,3,429},	//( - , SCM) Искажение: Приход на ВУ НИ ДС2
	{&iEM_TERB5SS21LIM,3,430},	//( - , SCM) Искажение: Приход на НУ НЛ2
	{&iEM_TERA1SS21LIM,3,431},	//( - , SCM) Искажение: Приход на НУ ББ1
	{&iEM_TERA1SS11LIM,3,432},	//( - , SCM) Искажение: Приход на ВУ ББ1
	{&iEM_TERA1SC01RIM,3,433},	//( - , SCM) Искажение: Координата штока ББ1
	{&iEM_TERA1SS12LIM,3,434},	//( - , SCM) Искажение: Магнит ББ1 зацеплен
	{&iEM_TERB1SS21LIM,3,435},	//( - , SCM) Искажение: Приход на НУ ББ2
	{&iEM_TERB1SS11LIM,3,436},	//( - , SCM) Искажение:Приход на ВУ ББ2
	{&iEM_TERB1MC01RIM,3,437},	//( - , SCM) Искажение: Координата штока ББ2
	{&iEM_TERB1SS12LIM,3,438},	//( - , SCM) Искажение: Магнит ББ2 зацеплен
	{&iEM_TERTLG,3,439},	//( - , SCM) Неисправности  тележки от ИС
	{&fEM_R4MC01RC1,8,440},	//( - , SCM) Заданная координата тележки от ИС
	{&fEM_R4MV01RC1,8,442},	//( - , SCM) Заданная скорость тележки от ИС
	{&iEM_TERMAZ2,3,444},	//( - , SCM) Неисправности АЗ2 от ИС
	{&fEM_B8MC01RC1,8,445},	//( - , SCM) аданная координата АЗ2 от ИС
	{&fEM_B8MV01RC1,8,447},	//( - , SCM) Заданная скорость АЗ2 от ИС
	{&iEM_TERDS2,3,449},	//( - , SCM) Неисправности ДС2 от ИС
	{&fEM_A8MC01RC1,8,450},	//( - , SCM) Заданная координата ДС2 от ИС
	{&fEM_A8MV01RC1,8,452},	//( - , SCM) Заданная скорость ДС2 от ИС
	{&iEM_TERBZ1,3,454},	//( - , SCM) Неисправности БЗ1
	{&fEM_A6MC01RC1,8,455},	//( - , SCM) Заданная координата БЗ1 от ИС
	{&fEM_A6MV01RC1,8,457},	//( - , SCM) Заданная скорость БЗ1 от ИС
	{&iEM_TERBZ2,3,459},	//( - , SCM) Неисправности БЗ2
	{&fEM_B6MC01RC1,8,460},	//( - , SCM) Заданная координата БЗ2 от ИС
	{&fEM_B6MV01RC1,8,462},	//( - , SCM) Заданная скорость БЗ2 от ИС
	{&iEM_TERMDZ2,3,464},	//( - , SCM) Неисправности МДЗ2
	{&fEM_R2MC01RC1,8,465},	//( - , SCM) Заданная координата МДЗ2 от ИС
	{&fEM_R2MV01RC1,8,467},	//( - , SCM) Заданная скорость МДЗ2 от ИС
	{&iEM_TERMDZ1,3,469},	//( - , SCM) Неисправности МДЗ1
	{&fEM_R1MC01RC1,8,470},	//( - , SCM) Заданная координата МДЗ1 от ИС
	{&fEM_R1MV01RC1,8,472},	//( - , SCM) Заданная скорость МДЗ1 от ИС
	{&iEM_TERNL1,3,474},	//( - , SCM) Неисправности НЛ1
	{&fEM_A5MC01RC1,8,475},	//( - , SCM) Заданная координата НЛ1 от ИС
	{&fEM_A5MV01RC1,8,477},	//( - , SCM) Заданная скорость НЛ1 от ИС
	{&iEM_TERNL2,3,479},	//( - , SCM) Неисправности НЛ2
	{&fEM_B5MC01RC1,8,480},	//( - , SCM) Заданная координата НЛ2 от ИС
	{&fEM_B5MV01RC1,8,482},	//( - , SCM) Заданная скорость НЛ2 от ИС
	{&fEM_A1UC08RIM,8,484},	//( - , SCM) Зона срабатывания КВ ББ(мм)
	{&fEM_A2UC08RIM,8,486},	//( - , SCM) Зона срабатывания КВ  РБ мм
	{&fEM_A3UC08RIM,8,488},	//( - , SCM) Зона срабатывания КВ ИС(мм)
	{&iEM_TERB2SS33LIM,3,490},	//( - , SCM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{&iEM_TERA1VP81LIM,3,491},	//( - , SCM) Искажение: Текущее давление СБРОС ББ1  в норме
	{&iEM_TERB1VP81LIM,3,492},	//( - , SCM) Искажение: Текущее давление СБРОС ББ2  в норме
	{&fEM_A0UT03RSP,8,493},	//( - , SCM) Стартовая  температура АЗ1 град
	{&fEM_A0UR01RSP,8,495},	//( - , SCM) Стартовая  реактивность АЗ1
	{&fEM_A0UR02RSP,8,497},	//( - , SCM) Стартовый  поток нейтронов АЗ1
	{&fEM_B0UT03RSP,8,499},	//( - , SCM) Стартовая  температура АЗ2 град
	{&fEM_A1MC01RSP,8,501},	//( - , SCM) Стартовая координата  ББ1
	{&fEM_A1MC02RSP,8,503},	//( - , SCM) Стартовая координата штока ББ1
	{&fEM_A1MV01RSP,8,505},	//( - , SCM) Стартовая скорость движения  ББ1
	{&fEM_A1MV02RSP,8,507},	//( - , SCM) Стартовая скорость движения  ББ1
	{&fEM_B1MC01RSP,8,509},	//( - , SCM) Стартовая координата  ББ2
	{&fEM_B1MV01RSP,8,511},	//( - , SCM) Стартовая скорость движения  ББ2
	{&fEM_B1MC02RSP,8,513},	//( - , SCM) Стартовая координата штока ББ2
	{&fEM_B1MV02RSP,8,515},	//( - , SCM) Стартовая скорость движения  ББ2
	{&fEM_A2MC01RC1,8,517},	//( - , SCM) Заданная координата РБ1 от ИС
	{&fEM_A2MV01RC1,8,519},	//( - , SCM) Заданная скорость движения РБ1 от ИС
	{&fEM_A2MC01RSP,8,521},	//( - , SCM) Стартовая координата  РБ1
	{&fEM_A2MV01RSP,8,523},	//( - , SCM) Стартовая скорость движения  РБ1
	{&fEM_A2MC02RSP,8,525},	//( - , SCM) Стартовая координата штока РБ1
	{&fEM_A2MV02RSP,8,527},	//( - , SCM) Стартовая скорость движения  РБ1
	{&fEM_B2MC01RSP,8,529},	//( - , SCM) Стартовая координата  РБ2
	{&fEM_B2MV01RSP,8,531},	//( - , SCM) Стартовая скорость движения  РБ2
	{&fEM_B2MC02RSP,8,533},	//( - , SCM) Стартовая координата штока РБ2
	{&fEM_B2MV02RSP,8,535},	//( - , SCM) Стартовая скорость движения  РБ2
	{&fEM_A3MC01RSP,8,537},	//( - , SCM) Стартовая координата  ИС1
	{&fEM_A3MV01RSP,8,539},	//( - , SCM) Стартовая скорость движения  ИС1
	{&fEM_A3MC02RSP,8,541},	//( - , SCM) Стартовая координата штока ИС1
	{&fEM_A3MV02RSP,8,543},	//( - , SCM) Стартовая скорость движения  ИС1
	{&fEM_B3MC01RSP,8,545},	//( - , SCM) Стартовая координата  ИС2
	{&fEM_B3MV01RSP,8,547},	//( - , SCM) Стартовая скорость движения  ИС2
	{&fEM_B3MC02RSP,8,549},	//( - , SCM) Стартовая координата штока ИС2
	{&fEM_B3MV02RSP,8,551},	//( - , SCM) Стартовая скорость движения  ИС2
	{&fEM_B8MC01RSP,8,553},	//( - , SCM) Стартовая координата АЗ2
	{&fEM_B8MV01RSP,8,555},	//( - , SCM) Стартовая скорость АЗ2
	{&fEM_A8MC01RSP,8,557},	//( - , SCM) Стартовая координата ДС2
	{&fEM_A8MV01RSP,8,559},	//( - , SCM) Стартовая скорость ДС2
	{&fEM_A6MC01RSP,8,561},	//( - , SCM) Стартовая координата БЗ1
	{&fEM_A6MV01RSP,8,563},	//( - , SCM) Стартовая скорость БЗ1
	{&fEM_B6MC01RSP,8,565},	//( - , SCM) Стартовая координата БЗ2
	{&fEM_B6MV01RSP,8,567},	//( - , SCM) Стартовая скорость БЗ2
	{&fEM_R3UC01RSP,8,569},	//( - , SCM) Стартовая координата Гомогенных дверей
	{&fEM_R3UV01RSP,8,571},	//( - , SCM) Стартовая скорость Гомогенных дверей
	{&fEM_R5UC01RSP,8,573},	//( - , SCM) Стартовая координата Ворот отстойной зоны
	{&fEM_R5UV01RSP,8,575},	//( - , SCM) Стартовая скорость Ворот отстойной зоны
	{&fEM_R6UC01RSP,8,577},	//( - , SCM) Стартовая координата Кран-балки
	{&fEM_R6UV01RSP,8,579},	//( - , SCM) Стартовая скорость Кран-балки
	{&fEM_R2MC01RSP,8,581},	//( - , SCM) Стартовая координата МДЗ2
	{&fEM_R2MV01RSP,8,583},	//( - , SCM) Стартовая скорость МДЗ2
	{&fEM_R1MC01RSP,8,585},	//( - , SCM) Стартовая координата МДЗ1
	{&fEM_R1MV01RSP,8,587},	//( - , SCM) Стартовая скорость МДЗ1
	{&fEM_A5MC01RSP,8,589},	//( - , SCM) Стартовая координата НЛ1
	{&fEM_A5MV01RSP,8,591},	//( - , SCM) Стартовая скорость НЛ1
	{&fEM_B5MC01RSP,8,593},	//( - , SCM) Стартовая координата НЛ2
	{&fEM_B5MV01RSP,8,595},	//( - , SCM) Стартовая скорость НЛ2
	{&fEM_A9MC01RSP,8,597},	//( - , SCM) Стартовая координата НИ ДС1
	{&fEM_A9MV01RSP,8,599},	//( - , SCM) Стартовая скорость НИ ДС1
	{&fEM_B9MC01RSP,8,601},	//( - , SCM) Стартовая координата НИ ДС2
	{&fEM_B9MV01RSP,8,603},	//( - , SCM) Стартовая скорость НИ ДС2
	{&fEM_A4MC01RSP,8,605},	//( - , SCM) Стартовая координата НИ1
	{&fEM_A4MV01RSP,8,607},	//( - , SCM) Стартовая скорость НИ1
	{&fEM_B4MC01RSP,8,609},	//( - , SCM) Стартовая координата НИ2
	{&fEM_B4MV01RSP,8,611},	//( - , SCM) Стартовая скорость НИ2
	{&fEM_R4MC01RSP,8,613},	//( - , SCM) Стартовая координата тележки
	{&fEM_R4MV01RSP,8,615},	//( - , SCM) Стартовая скорость тележки
	{&fEM_A1MV01RC1,8,617},	//( - , SCM) Заданная скорость движения  ББ1 от ИС
	{&iEM_TERB7MS31LIM,3,619},	//( - , SCM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{&iEM_TERA7MS31LIM,3,620},	//( - , SCM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{&fEM_R7UY00RSS,8,621},	//( - , SCM) Y-координата АЗ1 см
	{&iEM_TERA6VS12LIM,3,623},	//( - , SCM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{&iEM_TERA6VS22LIM,3,624},	//( - , SCM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{&iEM_TERB6VS12LIM,3,625},	//( - , SCM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{&iEM_TERB6VS22LIM,3,626},	//( - , SCM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{&iEM_TERA5VS22LIM,3,627},	//( - , SCM) Искажение: Движение створок НЛ1 к НУ
	{&iEM_TERA5VS12LIM,3,628},	//( - , SCM) Искажение: Движение створок НЛ1 к ВУ
	{&iEM_TERB5VS12LIM,3,629},	//( - , SCM) Искажение: Движение створок НЛ2 к ВУ
	{&iEM_TERB5VS22LIM,3,630},	//( - , SCM) Искажение: Движение створок НЛ2 к НУ
	{&iEM_TERR1VS12LIM,3,631},	//( - , SCM) Искажение: Движение МДЗ1 в сторону ВУ
	{&iEM_TERR1VS22LIM,3,632},	//( - , SCM) Искажение: Движение МДЗ1 в сторону НУ
	{&iEM_TERR2VS12LIM,3,633},	//( - , SCM) Искажение: Движение МДЗ2 в сторону ВУ
	{&iEM_TERR2VS22LIM,3,634},	//( - , SCM) Искажение: Движение МДЗ2 в сторону НУ
	{&iEM_TERR4VS12LDU,3,635},	//( - , SCM) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{&iEM_TERR4VS22LDU,3,636},	//( - , SCM) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SBz1[]={  // 
	{&R0EE01LZ1,1,0},	//( - , SBz1) Питание  АКНП1  отключить
	{&R0EE02LZ1,1,1},	//( - , SBz1) Питание  АКНП  отключить
	{&R0EE03LZ1,1,2},	//( - , SBz1) Питание  АКНП3  отключить
	{&R0EE04LZ1,1,3},	//( - , SBz1) Питание  АКНП4  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SBz1[]={  // 
	{&R0IS01FI0,3,0},	//( - , SBz1, SBz2, SDu, SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{&B0IT01FZ1,3,1},	//( - , SBz1) Температура АЗ2-1
	{&A0IT01FZ1,3,2},	//( - , SBz1) Температура АЗ1-1
	{&A2IP01FZ1,3,3},	//( - , SBz1) Текущее давление СБРОС РБ1
	{&B2IP01FZ1,3,4},	//( - , SBz1) Текущее давление СБРОС РБ2
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
	{&R0EE01LZ2,1,0},	//( - , SBz2) Питание  АКНП1  отключить
	{&R0EE02LZ2,1,1},	//( - , SBz2) Питание  АКНП  отключить
	{&R0EE03LZ2,1,2},	//( - , SBz2) Питание  АКНП3  отключить
	{&R0EE04LZ2,1,3},	//( - , SBz2) Питание  АКНП4  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SBz2[]={  // 
	{&R0IS01FI0,3,0},	//( - , SBz1, SBz2, SDu, SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{&B0IT02FZ2,3,1},	//( - , SBz2) Температура АЗ2-2
	{&A0IT02FZ2,3,2},	//( - , SBz2) Температура АЗ1-2
	{&A2IP01FZ2,3,3},	//( - , SBz2) Текущее давление СБРОС РБ1
	{&B2IP01FZ2,3,4},	//( - , SBz2) Текущее давление СБРОС РБ2
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
	{&A2IC01UDU,5,0},	//( - , SDu) Координата штока РБ1
	{&A3IC01UDU,5,2},	//( - , SDu) Координата штока ИС1
	{&B3IC01UDU,5,4},	//( - , SDu) Координата штока ИС2
	{&A8IC01UDU,5,6},	//( - , SDu) Координата ДС2
	{&B8IC01UDU,5,8},	//( - , SDu) Координата АЗ2
	{&B2IC01UDU,5,10},	//( - , SDu) Координата штока РБ2
	{&A1IC01UDU,5,12},	//( - , SDu) Координата штока ББ1
	{&B1IC01UDU,5,14},	//( - , SDu) Координата штока ББ2
	{&R0IS01FI0,3,16},	//( - , SBz1, SBz2, SDu, SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{&B3IP02FDU,3,17},	//( - , SDu) Текущее давление ВЫСТРЕЛ  ИС2
	{&A3IP02FDU,3,18},	//( - , SDu) Текущее давление ВЫСТРЕЛ ИС1
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SDu[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SA1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SA1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA1[]={  // 
	{&R0IN01FI1,8,0},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{&R0IN02FI1,8,2},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI1,8,4},	//( - , SA1) Выход КНК53М Гц от ПТИ
	{&R0IS01FI0,3,6},	//( - , SBz1, SBz2, SDu, SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SA1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SA2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SA2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA2[]={  // 
	{&R0IN01FI2,8,0},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{&R0IN02FI2,8,2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI2,8,4},	//( - , SA2) Выход КНК53М Гц от ПТИ
	{&R0IS01FI0,3,6},	//( - , SBz1, SBz2, SDu, SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SA2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SA3[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SA3[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA3[]={  // 
	{&R0IN01FI3,8,0},	//( - , SA3) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI3,8,2},	//( - , SA3) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI3,8,4},	//( - , SA3) Выход КНК53М Гц от ПТИ
	{&R0IS01FI0,3,6},	//( - , SBz1, SBz2, SDu, SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SA3[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SA4[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SA4[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA4[]={  // 
	{&R0IN01FI4,8,0},	//( - , SA4) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI4,8,2},	//( - , SA4) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI4,8,4},	//( - , SA4) Выход КНК53М Гц от ПТИ
	{&R0IS01FI0,3,6},	//( - , SBz1, SBz2, SDu, SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SA4[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SRP[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SRP[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SRP[]={  // 
	{&R0IN01RIP,8,0},	//( - , SRP) Выход СНМ-11 Гц от ПТИ
	{&R0IN02RIP,8,2},	//( - , SRP) Выход КНК15- Гц от ПТИ
	{&R0IN03RIP,8,4},	//( - , SRP) Выход КНК53М Гц от ПТИ
	{&R0IN06RIP,8,6},	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
	{&R0IN07RIP,8,8},	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
	{&R0IS01FI0,3,10},	//( - , SBz1, SBz2, SDu, SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{&B0IT03FRP,3,11},	//( - , SRP) Температура АЗ2-3
	{&A0IT03FRP,3,12},	//( - , SRP) Температура АЗ1-3
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SRP[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_SCM[0],&di_SCM[0],&ir_SCM[0],&hr_SCM[0],NULL,NULL,NULL,0},	 //Общий слэйв
	{0,5003,&coil_SBz1[0],&di_SBz1[0],&ir_SBz1[0],&hr_SBz1[0],NULL,NULL,NULL,0},	 //Cлэйв Baz1
	{0,5004,&coil_SBz2[0],&di_SBz2[0],&ir_SBz2[0],&hr_SBz2[0],NULL,NULL,NULL,0},	 //Cлэйв Baz2
	{0,5005,&coil_SDu[0],&di_SDu[0],&ir_SDu[0],&hr_SDu[0],NULL,NULL,NULL,0},	 //Cлэйв DU
	{0,5006,&coil_SA1[0],&di_SA1[0],&ir_SA1[0],&hr_SA1[0],NULL,NULL,NULL,0},	 //Cлэйв AKNP1
	{0,5007,&coil_SA2[0],&di_SA2[0],&ir_SA2[0],&hr_SA2[0],NULL,NULL,NULL,0},	 //Cлэйв AKNP2
	{0,5008,&coil_SA3[0],&di_SA3[0],&ir_SA3[0],&hr_SA3[0],NULL,NULL,NULL,0},	 //Cлэйв AKNP3
	{0,5009,&coil_SA4[0],&di_SA4[0],&ir_SA4[0],&hr_SA4[0],NULL,NULL,NULL,0},	 //Cлэйв AKNP4
	{0,5010,&coil_SRP[0],&di_SRP[0],&ir_SRP[0],&hr_SRP[0],NULL,NULL,NULL,0},	 //Cлэйв RPU

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
	{&B2IP01IZ1,3,9},
	{&B2IP01IZ2,3,21},
	{&A0IT03IRP,3,30},
	{&B0IT03IRP,3,33},
	{&A3IP02IDU,3,24},
	{&A0IT01IZ1,3,0},
	{&A0IT02IZ2,3,12},
	{&B0IT01IZ1,3,6},
	{&B0IT02IZ2,3,18},
	{&B3IP02IDU,3,27},
	{&A2IP01IZ2,3,15},
	{&A2IP01IZ1,3,3},
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
	{&R7II73LZ1,1,50},
	{&B1VP81LZZ,1,60},
	{&A3IS11LDU,1,8},
	{&A0VP81LZZ,1,52},
	{&B3IS11LDU,1,20},
	{&R6IS66LZZ,1,32},
	{&A3IS22LDU,1,10},
	{&B0VP81LZZ,1,58},
	{&B3IS22LDU,1,22},
	{&R6IS67LZZ,1,34},
	{&A1VP81LZZ,1,54},
	{&R6IS68LZZ,1,36},
	{&R7II71LZ1,1,46},
	{&R7II72LZ1,1,48},
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
	{&R7II72LZ2,1,48},
	{&R7II71LZ2,1,46},
	{&R7II73LZ2,1,50},
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
	{&A1IS12LDU,1,62},
	{&R1IS11LDU,1,42},
	{&B1IS21LDU,1,16},
	{&B1IS11LDU,1,14},
	{&R1IS21LDU,1,44},
	{&R2IS11LDU,1,46},
	{&B3IS21LDU,1,24},
	{&B1IS12LDU,1,12},
	{&R2IS21LDU,1,48},
	{&B2IS11LDU,1,20},
	{&B2IS12LDU,1,18},
	{&B2IS21LDU,1,22},
	{&B9IS21LDU,1,40},
	{&R8IS11LDU,1,26},
	{&A4IS21LDU,1,32},
	{&A4IS11LDU,1,30},
	{&B9IS11LDU,1,38},
	{&A9IS21LDU,1,36},
	{&A9IS11LDU,1,34},
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
	{&R4IS22LDU,1,48},
	{&R4IS21LDU,1,46},
	{&R4IS11LDU,1,42},
	{&A2IS12LDU,1,4},
	{&A2IS11LDU,1,6},
	{&A2IS21LDU,1,8},
	{&B4IS11LDU,1,12},
	{&A1IS11LDU,1,0},
	{&B4IS21LDU,1,14},
	{&B5IS11LDU,1,62},
	{&A5IS21LDU,1,56},
	{&R0IS02LDU,1,32},
	{&A1IS21LDU,1,2},
	{&B6IS21LDU,1,60},
	{&B6IS11LDU,1,58},
	{&A6IS21LDU,1,52},
	{&A3IS21LDU,1,10},
	{&R4IS12LDU,1,44},
	{&A5IS11LDU,1,54},
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
	{&A6IS11LDU,1,34},
	{&R6IS21LDU,1,26},
	{&B8IS22LDU,1,12},
	{&B8IS12LDU,1,10},
	{&R3IS11LDU,1,2},
	{&A8IS12LDU,1,28},
	{&R3IS21LDU,1,4},
	{&R5IS11LDU,1,18},
	{&R5IS21LDU,1,20},
	{&B8IS11LDU,1,14},
	{&A8IS22LDU,1,30},
	{&B8IS21LDU,1,8},
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
	{&R6IS62LDU,1,56},
	{&R6IS63LDU,1,58},
	{&R6IS64LDU,1,60},
	{&R6IS65LDU,1,62},
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
	{&A2AD33LDU,1,26},
	{&A7AP31LDU,1,32},
	{&B7AP31LDU,1,60},
	{&R2AD20LDU,1,40},
	{&R2AD10LDU,1,38},
	{&R1AD20LDU,1,36},
	{&R1AD10LDU,1,34},
	{&A5AD10LDU,1,42},
	{&A5AD20LDU,1,44},
	{&A8AD10LDU,1,62},
	{&B4AD10LDU,1,56},
	{&A4AD10LDU,1,28},
	{&B2AD33LDU,1,54},
	{&B5AD10LDU,1,46},
	{&B5AD20LDU,1,48},
	{&B3AD33LDU,1,52},
	{&A3AD31LDU,1,30},
	{&A3AD33LDU,1,24},
	{&B3AD34LDU,1,50},
	{&A3AD34LDU,1,22},
	{&B3AD31LDU,1,58},
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
	{&A9AD10LDU,1,46},
	{&B9AD10LDU,1,48},
	{&A6AD10LDU,1,2},
	{&A6AD20LDU,1,4},
	{&B6AD10LDU,1,6},
	{&B6AD20LDU,1,8},
	{&A3AD04LDU,1,28},
	{&A3AD05LDU,1,30},
	{&B3AD11LDU,1,32},
	{&B3AD21LDU,1,34},
	{&A1AD04LDU,1,60},
	{&A1AD03LDU,1,58},
	{&A1AD02LDU,1,56},
	{&A1AD01LDU,1,54},
	{&A1AD21LDU,1,52},
	{&A1AD11LDU,1,50},
	{&A3AD03LDU,1,26},
	{&A8AD20LDU,1,0},
	{&B8AD20LDU,1,16},
	{&B8AD10LDU,1,14},
	{&R4AD20LDU,1,12},
	{&R4AD10LDU,1,10},
	{&B3AD05LDU,1,44},
	{&B3AD04LDU,1,42},
	{&B3AD03LDU,1,40},
	{&B3AD02LDU,1,38},
	{&B3AD01LDU,1,36},
	{&A3AD11LDU,1,18},
	{&A3AD21LDU,1,20},
	{&A3AD01LDU,1,22},
	{&A3AD02LDU,1,24},
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
	{&R0AD16LDU,1,62},
	{&R8AD21LDU,1,60},
	{&A2AD01LDU,1,20},
	{&A2AD32LDU,1,48},
	{&A2AD21LDU,1,18},
	{&A2AD31LDU,1,50},
	{&A1AD32LDU,1,44},
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
	{&A1AD05LDU,1,0},
	{&B1AD11LDU,1,2},
	{&B1AD21LDU,1,4},
	{&B1AD01LDU,1,6},
	{&B1AD02LDU,1,8},
	{&B1AD03LDU,1,10},
	{&B2AD32LDU,1,56},
	{&B2AD31LDU,1,58},
	{&B1AD32LDU,1,52},
	{&B1AD31LDU,1,54},
	{&B1AD04LDU,1,12},
	{&B1AD05LDU,1,14},
	{&A2AD11LDU,1,16},
	{&A1AD31LDU,1,46},
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
	setAsFloat(289,0.015);
	setAsFloat(290,0.0069);
	setAsFloat(291,0.21);
	setAsFloat(292,0);
	setAsFloat(293,0);
	setAsFloat(294,0.0096);
	setAsFloat(295,0.0026);
	setAsFloat(296,106);
	setAsFloat(297,135.227);
	setAsFloat(298,25);
	setAsFloat(299,320.435466);
	setAsFloat(300,0.0055);
	setAsFloat(301,0.000877);
	setAsFloat(302,200);
	setAsFloat(303,100);
	setAsFloat(304,0);
	setAsFloat(305,0);
	setAsFloat(306,100);
	setAsFloat(307,80);
	setAsFloat(308,0.002375);
	setAsFloat(309,0);
	setAsFloat(310,165);
	setAsFloat(311,200);
	setAsFloat(312,0.001675);
	setAsFloat(313,40);
	setAsFloat(314,15630.0);
	setAsFloat(315,1374);
	setAsFloat(316,0);
	setAsFloat(317,390.0);
	setAsFloat(318,2000.0);
	setAsFloat(319,1500.0);
	setAsFloat(320,10.91);
	setAsFloat(321,10.91);
	setAsFloat(322,1500.0);
	setAsFloat(323,2000);
	setAsFloat(324,390.0);
	setAsFloat(325,0);
	setAsFloat(326,55.0);
	setAsFloat(327,15.0);
	setAsFloat(328,5.0);
	setAsFloat(329,1E12);
	setAsFloat(330,43.6);
	setAsFloat(331,20.0);
	setAsFloat(332,20.0);
	setAsFloat(333,20.0);
	setAsFloat(334,1269.0);
	setAsFloat(335,256.0);
	setAsFloat(336,1.0);
	setAsFloat(337,2.0);
	setAsFloat(338,0);
	setAsFloat(339,0.026);
	setAsFloat(340,0.08);
	setAsFloat(341,0.0);
	setAsFloat(342,27.108);
	setAsFloat(343,600);
	setAsFloat(344,0);
	setAsFloat(345,0.00009765625);
	setAsFloat(346,1.6);
	setAsFloat(347,0);
	setAsFloat(348,0.00009765625);
	setAsFloat(349,1.6);
	setAsFloat(350,0);
	setAsFloat(351,0.00009765625);
	setAsFloat(352,10000.0);
	setAsFloat(353,0.0009765625);
	setAsFloat(354,750);
	setAsFloat(355,100);
	setAsFloat(356,200);
	setAsFloat(357,300);
	setAsFloat(358,400);
	setAsFloat(359,500);
	setAsFloat(360,600);
	setAsFloat(361,0.50);
	setAsFloat(362,0.50);
	setAsFloat(363,0.50);
	setAsFloat(364,2);
	setAsFloat(365,11.0);
	setAsFloat(366,1585.0);
	setAsFloat(367,1796.0);
	setAsFloat(368,1555.0);
	setAsFloat(369,1269.0);
	setAsFloat(370,1269.0);
	setAsFloat(371,1585.0);
	setAsFloat(372,1796.0);
	setAsFloat(373,1269.0);
	setAsFloat(374,248.0);
	setAsFloat(375,284.5);
	setAsFloat(376,248.0);
	setAsFloat(377,271.6);
	setAsFloat(378,287.2);
	setAsFloat(379,594.0);
	setAsFloat(380,559.0);
	setAsFloat(381,588.0);
	setAsFloat(382,1555.0);
	setAsFloat(383,1281.2);
	setAsFloat(384,1269.0);
	setAsFloat(385,594.0);
	setAsFloat(386,597.2);
	setAsFloat(387,556.8);
	setAsFloat(388,1.0);
	setAsFloat(389,1.0);
	setAsFloat(390,1.0);
	setAsFloat(391,1.0);
	setAsFloat(392,1.0);
	setAsFloat(393,1.0);
	setAsFloat(394,1.0);
	setAsFloat(395,1.0);
	setAsFloat(396,1.0);
	setAsFloat(397,1.0);
	setAsFloat(398,1.0);
	setAsFloat(399,1.0);
	setAsFloat(400,0);
	setAsFloat(401,0);
	setAsFloat(402,0);
	setAsFloat(403,0);
	setAsFloat(404,0.0);
	setAsFloat(405,0);
	setAsFloat(406,0.0);
	setAsFloat(407,0);
	setAsFloat(408,0.0);
	setAsFloat(409,0.0);
	setAsFloat(410,0.0);
	setAsFloat(411,0.0);
	setAsFloat(412,3703.704);
	setAsFloat(413,62500.0);
	setAsFloat(414,20);
	setAsFloat(415,18000);
	setAsFloat(416,18000);
	setAsFloat(417,18000);
	setAsFloat(418,0.76);
	setAsFloat(419,0.245);
	setAsFloat(420,2.9);
	setAsFloat(421,0.13);
	setAsFloat(422,0.73);
	setAsFloat(423,0.41);
	setAsFloat(424,9807.0);
	setAsFloat(425,22975.0);
	setAsFloat(426,12750.0);
	setAsFloat(427,20);
	setAsFloat(428,20);
	setAsFloat(429,0);
	setAsFloat(430,5.0);
	setAsFloat(431,5.0);
	setAsFloat(432,5.0);
	setAsFloat(433,100.0);
	setAsFloat(434,4000);
	setAsFloat(435,100000);
	setAsFloat(436,1000000);
	setAsFloat(437,32000.0);
	setAsFloat(438,5.0);
	setAsFloat(439,15.0);
	setAsFloat(440,15.0);
	setAsFloat(441,20.0);
	setAsFloat(442,10.0);
	setAsBool(443,0);
	setAsBool(444,0);
	setAsBool(445,0);
	setAsFloat(446,0.45);
	setAsFloat(447,0.39);
	setAsFloat(448,2.74);
	setAsFloat(449,0.07);
	setAsFloat(450,0.275);
	setAsFloat(451,0.245);
	setAsFloat(452,0.045);
	setAsFloat(453,0.05);
	setAsShort(454,0);
	setAsFloat(455,0);
	setAsFloat(456,0);
	setAsShort(457,0);
	setAsFloat(458,0);
	setAsFloat(459,0);
	setAsShort(460,0);
	setAsFloat(461,0);
	setAsFloat(462,0);
	setAsShort(463,0);
	setAsFloat(464,0);
	setAsFloat(465,0);
	setAsShort(466,0);
	setAsFloat(467,0);
	setAsFloat(468,0);
	setAsShort(469,0);
	setAsFloat(470,0);
	setAsFloat(471,0);
	setAsShort(472,0);
	setAsShort(473,0);
	setAsFloat(474,0);
	setAsShort(475,0);
	setAsShort(476,0);
	setAsFloat(477,0);
	setAsFloat(478,0);
	setAsFloat(479,0);
	setAsFloat(480,0);
	setAsFloat(481,0);
	setAsFloat(482,0);
	setAsFloat(483,0);
	setAsFloat(484,0);
	setAsShort(485,0);
	setAsShort(486,0);
	setAsShort(487,0);
	setAsShort(488,0);
	setAsShort(489,0);
	setAsShort(490,0);
	setAsShort(491,0);
	setAsShort(492,0);
	setAsShort(493,0);
	setAsShort(494,0);
	setAsShort(495,0);
	setAsShort(496,0);
	setAsShort(497,0);
	setAsShort(498,0);
	setAsShort(499,0);
	setAsShort(500,0);
	setAsShort(501,0);
	setAsShort(502,0);
	setAsShort(503,0);
	setAsShort(504,0);
	setAsShort(505,0);
	setAsShort(506,0);
	setAsShort(507,0);
	setAsShort(508,0);
	setAsShort(509,0);
	setAsShort(510,0);
	setAsShort(511,0);
	setAsShort(512,0);
	setAsShort(513,0);
	setAsShort(514,0);
	setAsShort(515,0);
	setAsShort(516,0);
	setAsShort(517,0);
	setAsShort(518,0);
	setAsShort(519,0);
	setAsShort(520,0);
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
	setAsFloat(569,0);
	setAsFloat(570,0);
	setAsShort(571,0);
	setAsFloat(572,0);
	setAsFloat(573,0);
	setAsShort(574,0);
	setAsFloat(575,0);
	setAsFloat(576,0);
	setAsShort(577,0);
	setAsFloat(578,0);
	setAsFloat(579,0);
	setAsShort(580,0);
	setAsFloat(581,0);
	setAsFloat(582,0);
	setAsBool(583,0);
	setAsBool(584,1);
	setAsBool(585,0);
	setAsBool(586,1);
	setAsBool(587,0);
	setAsShort(588,0);
	setAsFloat(589,0);
	setAsFloat(590,0);
	setAsShort(591,0);
	setAsFloat(592,0);
	setAsFloat(593,0);
	setAsShort(594,0);
	setAsFloat(595,0);
	setAsFloat(596,0);
	setAsShort(597,0);
	setAsFloat(598,0);
	setAsFloat(599,0);
	setAsBool(600,1);
	setAsFloat(601,0.01);
	setAsFloat(602,0.01);
	setAsFloat(603,0.01);
	setAsShort(604,0);
	setAsShort(605,0);
	setAsShort(606,0);
	setAsFloat(607,25.017338);
	setAsFloat(608,-0.15912805);
	setAsFloat(609,0.000000166);
	setAsFloat(610,25.017338);
	setAsFloat(611,0);
	setAsFloat(612,0.000167646);
	setAsFloat(613,0);
	setAsFloat(614,0);
	setAsFloat(615,0);
	setAsFloat(616,0);
	setAsFloat(617,0.000167646);
	setAsFloat(618,0);
	setAsFloat(619,0);
	setAsFloat(620,0);
	setAsFloat(621,0);
	setAsFloat(622,0);
	setAsFloat(623,0);
	setAsFloat(624,0);
	setAsFloat(625,0);
	setAsFloat(626,0);
	setAsFloat(627,0);
	setAsFloat(628,0);
	setAsFloat(629,0.000885839);
	setAsFloat(630,0);
	setAsFloat(631,0.000885839);
	setAsFloat(632,0);
	setAsFloat(633,0.000885839);
	setAsFloat(634,0);
	setAsFloat(635,0.000885839);
	setAsFloat(636,0);
	setAsFloat(637,390);
	setAsFloat(638,0);
	setAsFloat(639,390);
	setAsFloat(640,0);
	setAsFloat(641,55);
	setAsFloat(642,0);
	setAsFloat(643,55);
	setAsFloat(644,0);
	setAsFloat(645,0);
	setAsFloat(646,0);
	setAsFloat(647,4000.0);
	setAsFloat(648,0);
	setAsFloat(649,10);
	setAsFloat(650,0);
	setAsFloat(651,0);
	setAsFloat(652,0);
	setAsFloat(653,0);
	setAsFloat(654,0);
	setAsFloat(655,5);
	setAsFloat(656,0);
	setAsFloat(657,5);
	setAsFloat(658,0);
	setAsFloat(659,0);
	setAsFloat(660,0);
	setAsFloat(661,0);
	setAsFloat(662,0);
	setAsFloat(663,0);
	setAsFloat(664,0);
	setAsFloat(665,0);
	setAsFloat(666,0);
	setAsFloat(667,15650);
	setAsFloat(668,0);
	setAsFloat(669,0);
	setAsShort(670,0);
	setAsShort(671,0);
	setAsFloat(672,506.6);
	setAsShort(673,0);
	setAsShort(674,0);
	setAsShort(675,0);
	setAsShort(676,0);
	setAsShort(677,0);
	setAsShort(678,0);
	setAsShort(679,0);
	setAsShort(680,0);
	setAsShort(681,0);
	setAsShort(682,0);
	setAsShort(683,0);
	setAsShort(684,0);
	setAsShort(685,0);
	setAsShort(686,0);
	setAsFloat(687,5065.0);
	setAsFloat(688,1.0);
	setAsFloat(689,1.0);
	setAsFloat(690,1.0);
	setAsFloat(691,1570.0);
	setAsFloat(692,1269);
	setAsFloat(693,1281.2);
	setAsFloat(694,248.0);
	setAsFloat(695,572.4);
	setAsFloat(696,246.8);
	setAsFloat(697,1);
}
uspaint8 InternalBuf[814];

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
ssint iRM_500_ = {500,0}; /* tz - ширина импульса, 10-ки мс */ 
ssfloat fRM_3_ = {3,0}; /* m1 - величина отклонения второго сигнала от входного */ 
ssfloat fRM_2_0 = {2.0,0}; /* ampl - амплетуда синусоидального отклонения */ 
ssint iRM_719_ = {719,0}; /* min - минимальное возможное значение выходного сигнала */ 
ssint iRM_4195_ = {4195,0}; /* max - максимальное возможное значение выходного сигнала */ 
ssfloat fRM_819_ = {819,0}; /* c   - мин. значение кода ФАС */ 
ssfloat fRM_4095_ = {4095,0}; /* d - макс.  значение кода ФАС */ 
ssfloat fRM_200_ = {200,0}; /* maxs1 - макc. значение второго сигнала */ 
ssfloat fRM_0_0015 = {0.0015,0}; /* m1 - величина отклонения второго сигнала от входного */ 
ssfloat fRM_0_001 = {0.001,0}; /* ampl - амплетуда синусоидального отклонения */ 
ssfloat fRM_0_1 = {0.1,0}; /* k - коэффициент усиления */ 
ssint iRM_16_ = {16,0}; /* n - N-размерность массива входных параметров */ 
ssfloat fRM_2000_ = {2000,0}; /* maxs1 - макc. значение второго сигнала */ 
ssfloat fRM_15_ = {15,0}; /* m1 - величина отклонения второго сигнала от входного */ 

uspaint8 SpaEEPROMBuf[1776];

/* Определение переменных */
ssfloat var1;
ssfloat var2;
ssfloat var3;
ssfloat var4;
ssfloat var5;
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
sslong var51;
ssfloat var52;
sslong var53;
ssfloat var54;
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
ssint var89;
ssint var90;
ssfloat var91;
ssfloat var92;
sslong var93;
ssfloat var94;
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
ssfloat var106;
ssbool var107;
ssbool var108;
sslong var109;
ssfloat var110;
sslong var111;
ssfloat var112;
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
ssint var124;
ssfloat var125;
ssbool var126;
ssbool var127;
ssint var128;
ssfloat var129;
ssbool var130;
sslong var131;
ssfloat var132;
ssbool var133;
ssbool var134;
sslong var135;
ssfloat var136;
ssbool var137;
ssint var138;
ssint var139;
ssbool var140;
ssbool var141;
ssbool var142;
sslong var143;
ssfloat var144;
ssbool var145;
ssbool var146;
ssbool var147;
ssfloat var148;
ssfloat var149;
ssfloat var150;
ssint var151;
ssint var152;
ssint var153;
ssfloat var154;
ssfloat var155;
ssfloat var156;
ssint var157;
ssint var158;
ssbool var159;
ssbool var160;
ssint var161;
ssfloat var162;
ssfloat var163;
ssfloat var164;
ssbool var165;
ssbool var166;
ssbool var167;
ssbool var168;
ssfloat var169;
ssbool var170;
ssfloat var171;
ssbool var172;
ssbool var173;
ssbool var174;
ssbool var175;
ssbool var176;
ssbool var177;
ssbool var178;
ssfloat var179;
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
ssfloat var218;
ssfloat var219;
ssfloat var220;
ssfloat var221;
ssfloat var222;
ssfloat var223;
ssfloat var224;
ssfloat var225;
ssfloat var226;
ssbool var227;
ssbool var228;
ssbool var229;
ssfloat var230;
ssfloat var231;
ssfloat var232;
ssfloat var233;
ssfloat var234;
ssfloat var235;
ssfloat var236;
ssfloat var237;
ssfloat var238;
ssfloat var239;
ssfloat var240;
ssfloat var241;
ssfloat var242;
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
ssfloat var267;
ssbool var268;
ssbool var269;
ssfloat var270;
ssbool var271;
ssbool var272;
ssbool var273;
ssbool var274;
ssbool var275;
ssbool var276;
ssbool var277;
ssbool var278;
ssfloat var279;
ssfloat var280;
ssfloat var281;
ssfloat var282;
ssbool var283;
ssfloat var284;
ssfloat var285;
ssfloat var286;
ssfloat var287;
ssbool var288;
ssbool var289;
ssbool var290;
ssbool var291;
ssbool var292;
ssfloat var293;
ssfloat var294;
ssbool var295;
ssbool var296;
ssbool var297;
ssbool var298;
ssbool var299;
ssfloat var300;
ssfloat var301;
ssbool var302;
ssbool var303;
ssbool var304;
ssbool var305;
ssbool var306;
ssbool var307;
ssfloat var308;
ssfloat var309;
ssbool var310;
ssbool var311;
ssbool var312;
ssbool var313;
ssbool var314;
ssbool var315;
ssfloat var316;
ssfloat var317;
ssbool var318;
ssbool var319;
ssbool var320;
ssbool var321;
ssbool var322;
ssfloat var323;
ssfloat var324;
ssbool var325;
ssbool var326;
ssbool var327;
ssbool var328;
ssbool var329;
ssfloat var330;
ssfloat var331;
ssfloat var332;
ssfloat var333;
ssbool var334;
ssfloat var335;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m363_x_1[16] = {&lEM_R8AD10LC1,&lEM_R8AD10LC1,&var329,&var187,&var181,&var271,&var269,&var263,&var260,&var276,&var319,&var314,&var305,&var295,&var289,&R0MW13LP2};
psbool  array_m932_x_1[2] = {&lEM_R0IE02LRP,&lEM_R0IE01LRP};
psbool  array_m927_x_1[2] = {&var167,&R0MW13LP2};
psbool  array_m952_x_1[2] = {&var174,&R0MW13LP2};
psbool  array_m945_x_1[2] = {&var175,&R0MW13LP2};
psbool  array_m937_x_1[2] = {&var176,&R0MW13LP2};
psbool  array_m646_x_1[2] = {&var32,&var228};
psbool  array_m643_x_1[2] = {&var32,&var229};
psbool  array_m653_x_1[3] = {&lEM_C1AD31LRP,&R0VZ71LZ1,&R0VZ71LZ2};
psbool  array_m929_x_1[2] = {&var199,&R0MW13LP2};
psbool  array_m298_x_1[2] = {&var216,&B3AD31LDU};
psbool  array_m263_x_1[3] = {&B2AD31LDU,&var202,&var216};
psbool  array_m264_x_1[3] = {&B2AD32LDU,&var202,&var216};
psbool  array_m224_x_1[4] = {&B1AD32LDU,&var205,&var204,&var216};
psbool  array_m223_x_1[4] = {&var205,&B1AD31LDU,&var204,&var216};
psbool  array_m121_x_1[2] = {&A3AD31LDU,&var216};
psbool  array_m48_x_1[4] = {&A1AD32LDU,&var210,&var209,&var216};
psbool  array_m47_x_1[4] = {&var210,&A1AD31LDU,&var209,&var216};
psbool  array_m87_x_1[3] = {&A2AD31LDU,&var214,&var216};
psbool  array_m88_x_1[3] = {&A2AD32LDU,&var214,&var216};
psbool  array_m659_x_1[2] = {&var227,&var31};
psfloat  array_m7_a_1[5] = {&fRM_390_,&fRM_600_,&fRM_900_,&fRM_1200_,&fRM_1500_};
psfloat  array_m7_b_1[5] = {&fRM_0_5,&fRM_0_2,&fRM_0_088884,&fRM_0_066666667,&fRM_0_02173913};
psfloat  array_m9_a_1[7] = {&fRM_390_,&fRM_420_,&fRM_513_,&fRM_767_,&fRM_900_,&fRM_1200_,&fRM_1500_};
psfloat  array_m9_b_1[7] = {&fRM_3_546,&fRM_2_7,&fRM_2_,&fRM_0_88884,&fRM_0_6221739,&fRM_0_35555072,&fRM_0_2666666667};
psfloat  array_m188_C0_1[6];
psfloat  array_m307_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m130_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m272_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m96_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m236_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m60_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m14_C0_1[6];

/* Объявление структур */
_S_to3val  S_to3val_981_1 = {&fEM_R7UX16RSS,&fRM_900_,&fRM_15_,&fRM_0_0015,&fRM_0_,&fRM_2000_,&fRM_2000_,&TerR0IN06FRP,&var1,&var2,&vainSFloat,&bFirstEnterFlag};
_S_vchs  S_vchs_906_1 = {&var280,&var331,&var241,&fEM_R4UC23RIM,&fEM_R7UY00RSS,&fEM_R7UX15RSS,&fEM_R7UY15RSS,&bRM_5_,&fEM_A0UX15RSS,&fEM_B0UX05RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var3,&internal1_m906_Chim0};
_S_vchs  S_vchs_896_1 = {&var331,&var280,&var241,&fEM_R4UC23RIM,&fEM_R7UY00RSS,&fEM_R7UX14RSS,&fEM_R7UY14RSS,&bRM_4_,&fEM_A0UX14RSS,&fEM_B0UX04RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var4,&internal1_m896_Chim0};
_S_vchs  S_vchs_888_1 = {&var331,&var280,&var241,&fEM_R4UC23RIM,&fEM_R7UY00RSS,&fEM_R7UX13RSS,&fEM_R7UY13RSS,&bRM_2_,&fEM_A0UX13RSS,&fEM_B0UX03RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var5,&internal1_m888_Chim0};
_S_twobool  S_twobool_843_1 = {&var278,&iEM_TERR4VS22LDU,&var6,&vainSBool,&internal1_m843_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_842_1 = {&var277,&iEM_TERR4VS12LDU,&var7,&vainSBool,&internal1_m842_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1026_1 = {&var254,&iEM_TERR2VS22LIM,&var8,&vainSBool,&internal1_m1026_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1025_1 = {&var253,&iEM_TERR2VS12LIM,&var9,&vainSBool,&internal1_m1025_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1024_1 = {&var258,&iEM_TERR1VS22LIM,&var10,&vainSBool,&internal1_m1024_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1023_1 = {&var257,&iEM_TERR1VS12LIM,&var11,&vainSBool,&internal1_m1023_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_705_1 = {&var246,&iEM_TERB5VS22LIM,&var12,&vainSBool,&internal1_m705_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_704_1 = {&var245,&iEM_TERB5VS12LIM,&var13,&vainSBool,&internal1_m704_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_683_1 = {&var250,&iEM_TERA5VS22LIM,&var14,&vainSBool,&internal1_m683_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_682_1 = {&var249,&iEM_TERA5VS12LIM,&var15,&vainSBool,&internal1_m682_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_703_1 = {&var262,&iEM_TERB6VS22LIM,&var16,&vainSBool,&internal1_m703_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_702_1 = {&var261,&iEM_TERB6VS12LIM,&var17,&vainSBool,&internal1_m702_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_681_1 = {&var266,&iEM_TERA6VS22LIM,&var18,&vainSBool,&internal1_m681_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_680_1 = {&var265,&iEM_TERA6VS12LIM,&var19,&vainSBool,&internal1_m680_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_535_1 = {&var37,&iEM_TERA1VP81LIM,&var20,&vainSBool,&internal1_m535_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_554_1 = {&var37,&iEM_TERB1VP81LIM,&var21,&vainSBool,&internal1_m554_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_417_1 = {&var305,&iEM_TERB2SS33LIM,&var22,&vainSBool,&internal1_m417_Out10,&bFirstEnterFlag};
_S_noto  S_noto_496_1 = {&var183,&var23};
_S_noto  S_noto_497_1 = {&var182,&var24};
_S_noto  S_noto_487_1 = {&var184,&var25};
_S_noto  S_noto_488_1 = {&var185,&var26};
_S_rs  S_rs_494_1 = {&var24,&lEM_R5AD10LC1,&var27,&vainSBool,&internal1_m494_q0};
_S_rs  S_rs_495_1 = {&var23,&lEM_R5AD20LC1,&var28,&vainSBool,&internal1_m495_q0};
_S_rs  S_rs_480_1 = {&var25,&lEM_R3AD10LC1,&var29,&vainSBool,&internal1_m480_q0};
_S_rs  S_rs_481_1 = {&var26,&lEM_R3AD20LC1,&var30,&vainSBool,&internal1_m481_q0};
_S_andn  S_andn_363_1 = {array_m363_x_1,&iRM_16_,&vainSBool};
_S_zpfs  S_zpfs_656_1 = {&R0AD14LDU,&fEM_R7UI76RIM,&var31,&internal1_m656_tx,&internal1_m656_y0};
_S_zpfs  S_zpfs_644_1 = {&R0AD16LDU,&fEM_R7UI77RIM,&var32,&internal1_m644_tx,&internal1_m644_y0};
_S_bol  S_bol_967_1 = {&fEM_A4UP01RIM,&fEM_A4UP02RIM,&var33};
_S_bol  S_bol_964_1 = {&fEM_A3UP01RIM,&fEM_A3UP02RIM,&var34};
_S_bol  S_bol_943_1 = {&fEM_A0UP02RIM,&fEM_A0UP01RIM,&var35};
_S_bol  S_bol_965_1 = {&fEM_A2UP02RIM,&fEM_A2UP03RIM,&var36};
_S_bol  S_bol_955_1 = {&fEM_A1UP01RIM,&fEM_A1UP82RIM,&var37};
_S_ampl  S_ampl_380_1 = {&var218,&fRM_0_1,&vainSFloat};
_S_or2  S_or2_956_1 = {&R0EE04LZ1,&R0EE04LZ2,&var38};
_S_or2  S_or2_947_1 = {&R0EE03LZ1,&R0EE03LZ2,&var39};
_S_or2  S_or2_940_1 = {&R0EE02LZ1,&R0EE02LZ2,&var40};
_S_or2  S_or2_933_1 = {&R0EE01LZ1,&R0EE01LZ2,&var41};
_S_zpfs  S_zpfs_630_1 = {&var186,&fRM_1_0,&var42,&internal1_m630_tx,&internal1_m630_y0};
_S_zpfs  S_zpfs_628_1 = {&var189,&fRM_0_5,&var43,&internal1_m628_tx,&internal1_m628_y0};
_S_twobool  S_twobool_214_1 = {&B1AD21LDU,&iEM_TERB1IE04LDU,&var44,&vainSBool,&internal1_m214_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_231_1 = {&B1AD11LDU,&iEM_TERB1IE03LDU,&var45,&vainSBool,&internal1_m231_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_41_1 = {&A1AD21LDU,&iEM_TERA1IE04LDU,&var46,&vainSBool,&internal1_m41_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_56_1 = {&A1AD11LDU,&iEM_TERA1IE03LDU,&var47,&vainSBool,&internal1_m56_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_997_1 = {&var322,&iEM_TERB1SS12LIM,&var48,&vainSBool,&internal1_m997_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_994_1 = {&var318,&iEM_TERB1SS11LIM,&var49,&vainSBool,&internal1_m994_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_993_1 = {&var319,&iEM_TERB1SS21LIM,&var50,&vainSBool,&internal1_m993_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_996_1 = {&var52,&fEM_A1UC03RDU,&fRM_0_,&iRM_0_,&var51,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m996_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_991_1 = {&var221,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB1MC01RIM,&var52,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_979_1 = {&var54,&fEM_A1UC03RDU,&fRM_0_,&iRM_0_,&var53,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m979_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_972_1 = {&var222,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA1SC01RIM,&var54,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_980_1 = {&var329,&iEM_TERA1SS12LIM,&var55,&vainSBool,&internal1_m980_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_977_1 = {&var326,&iEM_TERA1SS11LIM,&var56,&vainSBool,&internal1_m977_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_976_1 = {&var327,&iEM_TERA1SS21LIM,&var57,&vainSBool,&internal1_m976_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1064_1 = {&var260,&iEM_TERB6SS21LIM,&var58,&vainSBool,&internal1_m1064_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1045_1 = {&var259,&iEM_TERB6SS11LIM,&var59,&vainSBool,&internal1_m1045_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1044_1 = {&var264,&iEM_TERA6SS21LIM,&var60,&vainSBool,&internal1_m1044_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1043_1 = {&var263,&iEM_TERA6MS11LIM,&var61,&vainSBool,&internal1_m1043_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_864_1 = {&var269,&iEM_TERA8SS12LIM,&var62,&vainSBool,&internal1_m864_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_866_1 = {&var268,&iEM_TERA8SS22LIM,&var63,&vainSBool,&internal1_m866_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_863_1 = {&var272,&iEM_TERB8SS12LIM,&var64,&var65,&internal1_m863_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_865_1 = {&var271,&iEM_TERB8SS22LIM,&var66,&var67,&internal1_m865_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_839_1 = {&var273,&iEM_TERR4SS12LIM,&var68,&vainSBool,&internal1_m839_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_840_1 = {&var274,&iEM_TERR4SS22LIM,&var69,&vainSBool,&internal1_m840_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_838_1 = {&var276,&iEM_TERR4MS21LIM,&var70,&vainSBool,&internal1_m838_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_837_1 = {&var275,&iEM_TERR4SS11LIM,&var71,&vainSBool,&internal1_m837_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1059_1 = {&var33,&iEM_TERA4VP82LIM,&var72,&var73,&internal1_m1059_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1011_1 = {&var252,&iEM_TERR2SS21LIM,&var74,&vainSBool,&internal1_m1011_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1010_1 = {&var251,&iEM_TERR2SS11LIM,&var75,&vainSBool,&internal1_m1010_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1009_1 = {&var256,&iEM_TERR1SS21LIM,&var76,&vainSBool,&internal1_m1009_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1008_1 = {&var255,&iEM_TERR1SS11LIM,&var77,&vainSBool,&internal1_m1008_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1060_1 = {&var191,&iEM_TERB4SS21LIM,&var78,&vainSBool,&internal1_m1060_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1041_1 = {&var190,&iEM_TERB4SS11LIM,&var79,&vainSBool,&internal1_m1041_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_841_1 = {&lEM_R8AD10LC1,&iEM_TERR8SS11LIM,&var80,&vainSBool,&internal1_m841_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1042_1 = {&var188,&iEM_TERA4SS21LIM,&var81,&vainSBool,&internal1_m1042_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1040_1 = {&var187,&iEM_TERA4SS11LIM,&var82,&vainSBool,&internal1_m1040_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1061_1 = {&var183,&iEM_TERR5SS21LIM,&var83,&vainSBool,&internal1_m1061_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1039_1 = {&var182,&iEM_TERR5SS11LIM,&var84,&vainSBool,&internal1_m1039_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1022_1 = {&var185,&iEM_TERR3SS21LIM,&var85,&vainSBool,&internal1_m1022_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1007_1 = {&var184,&iEM_TERR3SS11LIM,&var86,&vainSBool,&internal1_m1007_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_553_1 = {&var36,&iEM_TERA2VP82LIM,&var87,&var88,&internal1_m553_Out10,&bFirstEnterFlag};
_S_toao  S_toao_558_1 = {&var92,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var89,&bFirstEnterFlag};
_S_toao  S_toao_557_1 = {&var91,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var90,&bFirstEnterFlag};
_S_to3val  S_to3val_551_1 = {&var149,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A2UP03RDU,&fEM_A2UP03RDU,&iEM_TERB2SP01RIM,&var91,&vainSFloat,&var92,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_427_1 = {&var94,&fEM_A2UC03RDU,&fRM_0_,&iRM_0_,&var93,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m427_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_421_1 = {&var220,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB2SC01RIM,&var94,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_418_1 = {&var307,&iEM_TERB2SS12LIM,&var95,&vainSBool,&internal1_m418_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_420_1 = {&var302,&iEM_TERB2SS11LIM,&var96,&vainSBool,&internal1_m420_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_419_1 = {&var303,&iEM_TERB2SS21LIM,&var97,&vainSBool,&internal1_m419_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_879_1 = {&var197,&iEM_TERB9SS21LIM,&var98,&vainSBool,&internal1_m879_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_880_1 = {&var196,&iEM_TERB9SS11LIM,&var99,&vainSBool,&internal1_m880_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_878_1 = {&var194,&iEM_TERA9SS21LIM,&var100,&vainSBool,&internal1_m878_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1063_1 = {&var193,&iEM_TERA9SS11LIM,&var101,&vainSBool,&internal1_m1063_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_718_1 = {&var244,&iEM_TERB5SS21LIM,&var102,&vainSBool,&internal1_m718_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_719_1 = {&var243,&iEM_TERB5SS11LIM,&var103,&vainSBool,&internal1_m719_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_716_1 = {&var248,&iEM_TERA5SS21LIM,&var104,&vainSBool,&internal1_m716_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_717_1 = {&var247,&iEM_TERA5SS11LIM,&var105,&vainSBool,&internal1_m717_Out10,&bFirstEnterFlag};
_S_ampl  S_ampl_669_1 = {&var226,&fEM_R7UI75RIM,&var106};
_S_to3val  S_to3val_670_1 = {&var106,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R7UI74RIM,&fEM_R7UI74RIM,&iEM_TERR7SI74RIM,&vainSFloat,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_574_1 = {&var35,&iEM_TERB0VP81LIM,&var107,&vainSBool,&internal1_m574_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_573_1 = {&var35,&iEM_TERA0VP81LIM,&var108,&vainSBool,&internal1_m573_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_860_1 = {&var110,&fEM_A8UC03RDU,&fRM_0_,&iRM_0_,&var109,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m860_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_852_1 = {&var270,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB8SC01RIM,&var110,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_862_1 = {&var112,&fEM_A8UC03RDU,&fRM_0_,&iRM_0_,&var111,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m862_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_854_1 = {&var267,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA8SC01RIM,&var112,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_715_1 = {&R0MW13LP2,&iEM_TERR6IS68LIM,&var113,&vainSBool,&internal1_m715_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_699_1 = {&R0MW13LP2,&iEM_TERR6IS67LIM,&var114,&vainSBool,&internal1_m699_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_679_1 = {&R0MW13LP2,&iEM_TERR6IS66LIM,&var115,&vainSBool,&internal1_m679_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_698_1 = {&R0MW13LP2,&iEM_TERR6IS64LIM,&var116,&var117,&internal1_m698_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_678_1 = {&R0MW13LP2,&iEM_TERR6IS62LIM,&var118,&var119,&internal1_m678_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_345_1 = {&var288,&iEM_TERB3SS22LIM,&var120,&vainSBool,&internal1_m345_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_344_1 = {&var295,&iEM_TERA3SS22LIM,&var121,&vainSBool,&internal1_m344_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_329_1 = {&var289,&iEM_TERB3SS11LIM,&var122,&vainSBool,&internal1_m329_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_328_1 = {&var296,&iEM_TERA3SS11LIM,&var123,&vainSBool,&internal1_m328_Out10,&bFirstEnterFlag};
_S_toao  S_toao_529_1 = {&var125,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var124,&bFirstEnterFlag};
_S_to3val  S_to3val_523_1 = {&var171,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A3UP03RDU,&fEM_A3UP03RDU,&iEM_TERA3SP02RIM,&vainSFloat,&var125,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_575_1 = {&var34,&iEM_TERA3VP81LIM,&var126,&var127,&internal1_m575_Out10,&bFirstEnterFlag};
_S_toao  S_toao_533_1 = {&var129,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var128,&bFirstEnterFlag};
_S_to3val  S_to3val_526_1 = {&var169,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A3UP03RDU,&fEM_A3UP03RDU,&iEM_TERB3SP02RIM,&vainSFloat,&var129,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_358_1 = {&var292,&iEM_TERB3SS33LIM,&var130,&vainSBool,&internal1_m358_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_342_1 = {&var132,&fEM_A3UC03RDU,&fRM_0_,&iRM_0_,&var131,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m342_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_341_1 = {&var287,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB3SC01RIM,&var132,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_357_1 = {&var291,&iEM_TERB3SS31LIM,&var133,&vainSBool,&internal1_m357_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_355_1 = {&var299,&iEM_TERA3SS33LIM,&var134,&vainSBool,&internal1_m355_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_334_1 = {&var136,&fEM_A3UC03RDU,&fRM_0_,&iRM_0_,&var135,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m334_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_331_1 = {&var294,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA3SC01RIM,&var136,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_356_1 = {&var298,&iEM_TERA3SS31LIM,&var137,&vainSBool,&internal1_m356_Out10,&bFirstEnterFlag};
_S_toao  S_toao_556_1 = {&var150,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var138,&bFirstEnterFlag};
_S_toao  S_toao_555_1 = {&var148,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var139,&bFirstEnterFlag};
_S_twobool  S_twobool_327_1 = {&var290,&iEM_TERB3SS21LIM,&var140,&vainSBool,&internal1_m327_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_343_1 = {&var297,&iEM_TERA3SS21LIM,&var141,&vainSBool,&internal1_m343_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_439_1 = {&var313,&iEM_TERA2SS33LIM,&var142,&vainSBool,&internal1_m439_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_440_1 = {&var144,&fEM_A2UC03RDU,&fRM_0_,&iRM_0_,&var143,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m440_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_435_1 = {&var219,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA2SC01RIM,&var144,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_438_1 = {&var315,&iEM_TERA2SS12LIM,&var145,&vainSBool,&internal1_m438_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_437_1 = {&var310,&iEM_TERA2SS11LIM,&var146,&vainSBool,&internal1_m437_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_436_1 = {&var311,&iEM_TERA2SS21LIM,&var147,&vainSBool,&internal1_m436_Out10,&bFirstEnterFlag};
_S_to3val  S_to3val_550_1 = {&fEM_A2UP01RIM,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A2UP03RDU,&fEM_A2UP03RDU,&iEM_TERA2SP01RIM,&var148,&var149,&var150,&bFirstEnterFlag};
_S_toao  S_toao_163_1 = {&var156,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var151,&bFirstEnterFlag};
_S_toao  S_toao_162_1 = {&var155,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var152,&bFirstEnterFlag};
_S_toao  S_toao_161_1 = {&var154,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var153,&bFirstEnterFlag};
_S_to3val  S_to3val_156_1 = {&var282,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R0UT02RDU,&fEM_R0UT02RDU,&iEM_TERB0MT01RIM,&var154,&var155,&var156,&bFirstEnterFlag};
_S_toao  S_toao_166_1 = {&var164,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var157,&bFirstEnterFlag};
_S_toao  S_toao_165_1 = {&var163,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var158,&bFirstEnterFlag};
_S_twobool  S_twobool_1062_1 = {&var181,&iEM_TERR6SS21LIM,&var159,&vainSBool,&internal1_m1062_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_150_1 = {&var283,&iEM_TERB7MS31LIM,&var160,&vainSBool,&internal1_m150_Out10,&bFirstEnterFlag};
_S_toao  S_toao_164_1 = {&var162,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_819_,&fRM_4095_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var161,&bFirstEnterFlag};
_S_to3val  S_to3val_158_1 = {&var333,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R0UT02RDU,&fEM_R0UT02RDU,&iEM_TERA0MT01RIM,&var162,&var163,&var164,&bFirstEnterFlag};
_S_twobool  S_twobool_149_1 = {&var334,&iEM_TERA7MS31LIM,&var165,&vainSBool,&internal1_m149_Out10,&bFirstEnterFlag};
_S_orn  S_orn_932_1 = {array_m932_x_1,&iRM_2_,&var166};
_S_andn  S_andn_927_1 = {array_m927_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_931_1 = {&var166,&var167};
_S_noto  S_noto_521_1 = {&B3AD34LDU,&var168};
_S_lk  S_lk_525_1 = {&fEM_A3UP02RDU,&var168,&var169};
_S_noto  S_noto_519_1 = {&A3AD34LDU,&var170};
_S_lk  S_lk_524_1 = {&fEM_A3UP02RDU,&var170,&var171};
_S_ovb1  S_ovb1_203_1 = {&R8AD21LDU,&iRM_500_,&var172,&internal1_m203_tx};
_S_ovb1  S_ovb1_25_1 = {&R8AD21LDU,&iRM_500_,&var173,&internal1_m25_tx};
_S_andn  S_andn_952_1 = {array_m952_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_957_1 = {&var38,&var174};
_S_andn  S_andn_945_1 = {array_m945_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_948_1 = {&var39,&var175};
_S_andn  S_andn_937_1 = {array_m937_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_941_1 = {&var40,&var176};
_S_orn  S_orn_646_1 = {array_m646_x_1,&iRM_2_,&var177};
_S_orn  S_orn_643_1 = {array_m643_x_1,&iRM_2_,&var178};
_S_react  S_react_206_1 = {&var284,&var179};
_S_noto  S_noto_482_1 = {&lEM_R6AD10LC1,&var180};
_S_asmot  S_asmot_486_1 = {&var180,&lEM_R6AD10LC1,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R6UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R6UC01RSP,&fEM_R6UV01RSP,&vainSFloat,&var181,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m486_Pav0,&internal1_m486_Zav0,&internal1_m486_Pv0,&internal1_m486_Zv0,&internal1_m486_RA00,&internal1_m486_RA10,&internal1_m486_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_498_1 = {&var27,&var28,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R5UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R5UC01RSP,&fEM_R5UV01RSP,&vainSFloat,&var182,&var183,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m498_Pav0,&internal1_m498_Zav0,&internal1_m498_Pv0,&internal1_m498_Zv0,&internal1_m498_RA00,&internal1_m498_RA10,&internal1_m498_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_484_1 = {&var29,&var30,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R3UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R3UC01RSP,&fEM_R3UV01RSP,&vainSFloat,&var184,&var185,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m484_Pav0,&internal1_m484_Zav0,&internal1_m484_Pv0,&internal1_m484_Zv0,&internal1_m484_RA00,&internal1_m484_RA10,&internal1_m484_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_629_1 = {&A4AD10LDU,&var186};
_S_asmot  S_asmot_634_1 = {&var186,&A4AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,&fEM_A4UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_A4MC01RSP,&fEM_A4MV01RSP,&vainSFloat,&var187,&var188,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m634_Pav0,&internal1_m634_Zav0,&internal1_m634_Pv0,&internal1_m634_Zv0,&internal1_m634_RA00,&internal1_m634_RA10,&internal1_m634_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_627_1 = {&B4AD10LDU,&var189};
_S_asmot  S_asmot_632_1 = {&var189,&B4AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_A4UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_B4MC01RSP,&fEM_B4MV01RSP,&vainSFloat,&var190,&var191,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m632_Pav0,&internal1_m632_Zav0,&internal1_m632_Pv0,&internal1_m632_Zv0,&internal1_m632_RA00,&internal1_m632_RA10,&internal1_m632_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_616_1 = {&A9AD10LDU,&var192};
_S_asmot  S_asmot_618_1 = {&var192,&A9AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,&fEM_A9UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_A9MC01RSP,&fEM_A9MV01RSP,&vainSFloat,&var193,&var194,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m618_Pav0,&internal1_m618_Zav0,&internal1_m618_Pv0,&internal1_m618_Zv0,&internal1_m618_RA00,&internal1_m618_RA10,&internal1_m618_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_615_1 = {&B9AD10LDU,&var195};
_S_asmot  S_asmot_617_1 = {&var195,&B9AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_A9UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_B9MC01RSP,&fEM_B9MV01RSP,&vainSFloat,&var196,&var197,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m617_Pav0,&internal1_m617_Zav0,&internal1_m617_Pv0,&internal1_m617_Zv0,&internal1_m617_RA00,&internal1_m617_RA10,&internal1_m617_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orn  S_orn_653_1 = {array_m653_x_1,&iRM_3_,&var198};
_S_andn  S_andn_929_1 = {array_m929_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_934_1 = {&var41,&var199};
_S_andn  S_andn_298_1 = {array_m298_x_1,&iRM_2_,&var200};
_S_andn  S_andn_263_1 = {array_m263_x_1,&iRM_3_,&var201};
_S_noto  S_noto_262_1 = {&C2MD31LP1,&var202};
_S_andn  S_andn_264_1 = {array_m264_x_1,&iRM_3_,&var203};
_S_noto  S_noto_222_1 = {&C1MD31LP2,&var204};
_S_noto  S_noto_221_1 = {&C1MD31LP1,&var205};
_S_andn  S_andn_224_1 = {array_m224_x_1,&iRM_4_,&var206};
_S_andn  S_andn_223_1 = {array_m223_x_1,&iRM_4_,&var207};
_S_andn  S_andn_121_1 = {array_m121_x_1,&iRM_2_,&var208};
_S_noto  S_noto_46_1 = {&C1MD31LP2,&var209};
_S_noto  S_noto_45_1 = {&C1MD31LP1,&var210};
_S_andn  S_andn_48_1 = {array_m48_x_1,&iRM_4_,&var211};
_S_andn  S_andn_47_1 = {array_m47_x_1,&iRM_4_,&var212};
_S_andn  S_andn_87_1 = {array_m87_x_1,&iRM_3_,&var213};
_S_noto  S_noto_86_1 = {&C2MD31LP1,&var214};
_S_andn  S_andn_88_1 = {array_m88_x_1,&iRM_3_,&var215};
_S_noto  S_noto_651_1 = {&var198,&var216};
_S_orn  S_orn_659_1 = {array_m659_x_1,&iRM_2_,&var217};
_S_fsubo  S_fsubo_379_1 = {&fEM_R7UY00RSS,&var270,&var218};
_S_fsubo  S_fsubo_115_1 = {&fEM_A2UC05RIM,&var309,&var219};
_S_fsubo  S_fsubo_291_1 = {&fEM_A2UC05RIM,&var301,&var220};
_S_fsubo  S_fsubo_250_1 = {&fEM_A1UC05RIM,&var317,&var221};
_S_fsubo  S_fsubo_74_1 = {&fEM_A1UC05RIM,&var324,&var222};
_S_fsubo  S_fsubo_8_1 = {&var224,&fEM_R0UR01RIM,&var223};
_S_inf  S_inf_7_1 = {&var270,array_m7_a_1,array_m7_b_1,&iRM_5_,&var224,&vainSInt};
_S_inf  S_inf_9_1 = {&var270,array_m9_a_1,array_m9_b_1,&iRM_7_,&var225,&vainSInt};
_S_mod1  S_mod1_664_1 = {&var285,&fEM_R7UI02RIM,&fEM_R7UL01RIM,&var226,&internal1_m664_y0};
_S_bol  S_bol_658_1 = {&var285,&fEM_R7UI73RIM,&var227};
_S_bol  S_bol_648_1 = {&var285,&fEM_R7UI72RIM,&var228};
_S_bol  S_bol_642_1 = {&var285,&fEM_R7UI71RIM,&var229};
_S_vchs  S_vchs_825_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX12RSS,&fEM_R7UY12RSS,&bRM_5_,&fEM_A0UX12RSS,&fEM_B0UX12RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var230,&internal1_m825_Chim0};
_S_vchs  S_vchs_816_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX11RSS,&fEM_R7UY11RSS,&bRM_4_,&fEM_A0UX11RSS,&fEM_B0UX11RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var231,&internal1_m816_Chim0};
_S_vchs  S_vchs_808_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX10RSS,&fEM_R7UY10RSS,&bRM_1_,&fEM_A0UX10RSS,&fEM_B0UX10RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var232,&internal1_m808_Chim0};
_S_vchs  S_vchs_799_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX09RSS,&fEM_R7UY09RSS,&bRM_5_,&fEM_A0UX09RSS,&fEM_B0UX09RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var233,&internal1_m799_Chim0};
_S_vchs  S_vchs_790_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX08RSS,&fEM_R7UY08RSS,&bRM_4_,&fEM_A0UX08RSS,&fEM_B0UX08RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var234,&internal1_m790_Chim0};
_S_vchs  S_vchs_782_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX07RSS,&fEM_R7UY07RSS,&bRM_1_,&fEM_A0UX07RSS,&fEM_B0UX07RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var235,&internal1_m782_Chim0};
_S_vchs  S_vchs_773_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX06RSS,&fEM_R7UY06RSS,&bRM_5_,&fEM_A0UX06RSS,&fEM_B0UX06RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var236,&internal1_m773_Chim0};
_S_vchs  S_vchs_764_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX05RSS,&fEM_R7UY05RSS,&bRM_4_,&fEM_A0UX05RSS,&fEM_B0UX05RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var237,&internal1_m764_Chim0};
_S_vchs  S_vchs_756_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX04RSS,&fEM_R7UY04RSS,&bRM_2_,&fEM_A0UX04RSS,&fEM_B0UX04RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var238,&internal1_m756_Chim0};
_S_vchs  S_vchs_747_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UC10RIM,&fEM_R7UC19RIM,&bRM_5_,&fEM_A0UX03RSS,&fEM_B0UX03RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var239,&internal1_m747_Chim0};
_S_vchs  S_vchs_738_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX02RSS,&fEM_R7UY02RSS,&bRM_4_,&fEM_A0UX02RSS,&fEM_B0UX02RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var240,&internal1_m738_Chim0};
_S_fsumo  S_fsumo_923_1 = {&fEM_R4UC10RIM,&fEM_R4UC22RIM,&var241};
_S_vchs  S_vchs_730_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX01RSS,&fEM_R7UY01RSS,&bRM_2_,&fEM_A0UX01RSS,&fEM_B0UX01RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var242,&internal1_m730_Chim0};
_S_asmot  S_asmot_604_1 = {&B5AD10LDU,&B5AD20LDU,&fEM_B5MC01RC1,&fEM_B5MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERNL2,&fEM_A5UC10RIM,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,&fEM_B5MC01RSP,&fEM_B5MV01RSP,&vainSFloat,&var243,&var244,&vainSBool,&vainSBool,&vainSFloat,&var245,&var246,&internal1_m604_Pav0,&internal1_m604_Zav0,&internal1_m604_Pv0,&internal1_m604_Zv0,&internal1_m604_RA00,&internal1_m604_RA10,&internal1_m604_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_589_1 = {&A5AD10LDU,&A5AD20LDU,&fEM_A5MC01RC1,&fEM_A5MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERNL1,&fEM_A5UC10RIM,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,&fEM_A5MC01RSP,&fEM_A5MV01RSP,&vainSFloat,&var247,&var248,&vainSBool,&vainSBool,&vainSFloat,&var249,&var250,&internal1_m589_Pav0,&internal1_m589_Zav0,&internal1_m589_Pv0,&internal1_m589_Zv0,&internal1_m589_RA00,&internal1_m589_RA10,&internal1_m589_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_469_1 = {&R2AD10LDU,&R2AD20LDU,&fEM_R2MC01RC1,&fEM_R2MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERMDZ2,&fEM_R1UC10RIM,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,&fEM_R2MC01RSP,&fEM_R2MV01RSP,&vainSFloat,&var251,&var252,&vainSBool,&vainSBool,&vainSFloat,&var253,&var254,&internal1_m469_Pav0,&internal1_m469_Zav0,&internal1_m469_Pv0,&internal1_m469_Zv0,&internal1_m469_RA00,&internal1_m469_RA10,&internal1_m469_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_454_1 = {&R1AD10LDU,&R1AD20LDU,&fEM_R1MC01RC1,&fEM_R1MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERMDZ1,&fEM_R1UC10RIM,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,&fEM_R1MC01RSP,&fEM_R1MV01RSP,&vainSFloat,&var255,&var256,&vainSBool,&vainSBool,&vainSFloat,&var257,&var258,&internal1_m454_Pav0,&internal1_m454_Zav0,&internal1_m454_Pv0,&internal1_m454_Zv0,&internal1_m454_RA00,&internal1_m454_RA10,&internal1_m454_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_510_1 = {&B6AD10LDU,&B6AD20LDU,&fEM_B6MC01RC1,&fEM_B6MV01RC1,&fRM_1_0,&fEM_A6US80RDU,&iEM_TERBZ2,&fEM_A6UC10RIM,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,&fEM_B6MC01RSP,&fEM_B6MV01RSP,&vainSFloat,&var259,&var260,&vainSBool,&vainSBool,&vainSFloat,&var261,&var262,&internal1_m510_Pav0,&internal1_m510_Zav0,&internal1_m510_Pv0,&internal1_m510_Zv0,&internal1_m510_RA00,&internal1_m510_RA10,&internal1_m510_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_405_1 = {&A6AD10LDU,&A6AD20LDU,&fEM_A6MC01RC1,&fEM_A6MV01RC1,&fRM_1_0,&fEM_A6US80RDU,&iEM_TERBZ1,&fEM_A6UC10RIM,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,&fEM_A6MC01RSP,&fEM_A6MV01RSP,&vainSFloat,&var263,&var264,&vainSBool,&vainSBool,&vainSFloat,&var265,&var266,&internal1_m405_Pav0,&internal1_m405_Zav0,&internal1_m405_Pv0,&internal1_m405_Zv0,&internal1_m405_RA00,&internal1_m405_RA10,&internal1_m405_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_389_1 = {&A8AD20LDU,&A8AD10LDU,&fEM_A8MC01RC1,&fEM_A8MV01RC1,&fEM_A8UV80RDU,&fEM_A8US80RDU,&iEM_TERDS2,&fEM_A8UC10RIM,&fEM_A8UC20RIM,&fEM_A8UC11RIM,&fEM_A8UC21RIM,&fEM_A8UC08RDU,&fEM_A8MC01RSP,&fEM_A8MV01RSP,&var267,&var268,&var269,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m389_Pav0,&internal1_m389_Zav0,&internal1_m389_Pv0,&internal1_m389_Zv0,&internal1_m389_RA00,&internal1_m389_RA10,&internal1_m389_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_372_1 = {&B8AD20LDU,&B8AD10LDU,&fEM_B8MC01RC1,&fEM_B8MV01RC1,&fEM_B8UV80RDU,&fEM_B8US80RDU,&iEM_TERMAZ2,&fEM_B8UC10RIM,&fEM_B8UC20RIM,&fEM_B8UC11RIM,&fEM_B8UC21RIM,&fEM_B8UC08RDU,&fEM_B8MC01RSP,&fEM_B8MV01RSP,&var270,&var271,&var272,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m372_Pav0,&internal1_m372_Zav0,&internal1_m372_Pv0,&internal1_m372_Zv0,&internal1_m372_RA00,&internal1_m372_RA10,&internal1_m372_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_918_1 = {&R4AD10LDU,&R4AD20LDU,&fEM_R4MC01RC1,&fEM_R4MV01RC1,&fEM_R4UV80RDU,&fEM_R4US80RDU,&iEM_TERTLG,&fEM_R4UC10RIM,&fEM_R4UC20RIM,&fEM_R4UC10RIM,&fEM_R4UC20RIM,&fEM_R4UC08RDU,&fEM_R4MC01RSP,&fEM_R4MV01RSP,&vainSFloat,&var273,&var274,&var275,&var276,&vainSFloat,&var277,&var278,&internal1_m918_Pav0,&internal1_m918_Zav0,&internal1_m918_Pv0,&internal1_m918_Zv0,&internal1_m918_RA00,&internal1_m918_RA10,&internal1_m918_MyFirstEnterFlag,&bFirstEnterFlag};
_S_azbars  S_azbars_188_1 = {&var316,&var300,&var286,&var330,&fEM_R0UR30RIM,&B7AP31LDU,&var190,&lEM_R8AD10LC1,&var172,&fEM_R0UL01RIM,&fEM_R0UN02RIM,&fEM_R0UT01RIM,&fEM_R0UT02RIM,&fEM_R0UT04RIM,&fEM_R0UT05RIM,&fEM_R0UH05RSS,&fEM_A0UN02RIM,&fEM_A0UN01RIM,&fEM_A1UR00RIM,&fEM_A1UR01RIM,&fEM_A2UR00RIM,&fEM_A2UR01RIM,&fEM_A3UR00RIM,&fEM_A3UR01RIM,&var223,&var225,&fEM_R0UT03RIM,&fEM_R0UT06RIM,&fEM_A0UR02RSP,&fEM_A0UR01RSP,&fEM_B0UT03RSP,&var279,&var280,&var281,&var282,&var283,&var284,&var285,&internal1_m188_C1,&internal1_m188_C2,&internal1_m188_C3,&internal1_m188_C4,&internal1_m188_C5,&internal1_m188_C6,&internal1_m188_N20,array_m188_C0_1,&internal1_m188_ImpINI0,&internal1_m188_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_307_1 = {&B3AD11LDU,&B3AD21LDU,&B3AD02LDU,&B3AD01LDU,&B3AD03LDU,&B3AD04LDU,&B3AD05LDU,&var200,&B3AD33LDU,&lRM_1_,&fEM_B3MC01RC1,&fEM_B3MC02RC1,&fEM_B3MV01RC1,&fEM_B3MV02RC1,&lRM_0_,array_m307_Vr_1,&fEM_A3UC02RDU,&var169,&fEM_A3UP01RIM,&fEM_A3UG01RDU,&fEM_A3US07RDU,&fEM_A3UV02RIM,&iEM_TERIS2,&fEM_A3UC04RIM,&fEM_A3UC05RIM,&fEM_A3UC06RIM,&fEM_A3UC08RIM,&fEM_B3MC01RSP,&fEM_B3MC02RSP,&fEM_B3MV01RSP,&fEM_B3MV02RSP,&var286,&var287,&var288,&var289,&var290,&vainSFloat,&vainSFloat,&var291,&var292,&vainSBool,&vainSBool,&internal1_m307_Ppv0,&internal1_m307_Pav0,&internal1_m307_Zav0,&internal1_m307_RA00,&internal1_m307_RA10,&internal1_m307_RA50,&internal1_m307_fls,&internal1_m307_flp,&internal1_m307_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_130_1 = {&A3AD11LDU,&A3AD21LDU,&A3AD02LDU,&A3AD01LDU,&A3AD03LDU,&A3AD04LDU,&A3AD05LDU,&var208,&A3AD33LDU,&lRM_1_,&fEM_A3MC01RC1,&fEM_A3MC02RC1,&fEM_A3MV01RC1,&fEM_A3MV02RC1,&lRM_0_,array_m130_Vr_1,&fEM_A3UC02RDU,&var171,&fEM_A3UP01RIM,&fEM_A3UG01RDU,&fEM_A3US07RDU,&fEM_A3UV02RIM,&iEM_TERIS1,&fEM_A3UC04RIM,&fEM_A3UC05RIM,&fEM_A3UC06RIM,&fEM_A3UC08RIM,&fEM_A3MC01RSP,&fEM_A3MC02RSP,&fEM_A3MV01RSP,&fEM_A3MV02RSP,&var293,&var294,&var295,&var296,&var297,&vainSFloat,&vainSFloat,&var298,&var299,&vainSBool,&vainSBool,&internal1_m130_Ppv0,&internal1_m130_Pav0,&internal1_m130_Zav0,&internal1_m130_RA00,&internal1_m130_RA10,&internal1_m130_RA50,&internal1_m130_fls,&internal1_m130_flp,&internal1_m130_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_272_1 = {&B2AD11LDU,&B2AD21LDU,&B2AD02LDU,&B2AD01LDU,&B2AD03LDU,&B2AD04LDU,&B2AD05LDU,&var201,&B2AD33LDU,&var203,&fEM_B2MC01RC1,&fEM_B2MC02RC1,&fEM_B2MV01RC1,&fEM_B2MV02RC1,&lRM_1_,array_m272_Vr_1,&fEM_A2UC02RDU,&fEM_A2UP02RIM,&fEM_A2UP01RIM,&fEM_A2UG01RDU,&fEM_A2US07RDU,&fEM_A2UV02RIM,&iEM_TERRB2,&fEM_A2UC04RIM,&fEM_A2UC05RIM,&fEM_A2UC06RIM,&fEM_A2UC08RIM,&fEM_B2MC01RSP,&fEM_B2MC02RSP,&fEM_B2MV01RSP,&fEM_B2MV02RSP,&var300,&var301,&vainSBool,&var302,&var303,&vainSFloat,&vainSFloat,&var304,&var305,&var306,&var307,&internal1_m272_Ppv0,&internal1_m272_Pav0,&internal1_m272_Zav0,&internal1_m272_RA00,&internal1_m272_RA10,&internal1_m272_RA50,&internal1_m272_fls,&internal1_m272_flp,&internal1_m272_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_96_1 = {&A2AD11LDU,&A2AD21LDU,&A2AD02LDU,&A2AD01LDU,&A2AD03LDU,&A2AD04LDU,&A2AD05LDU,&var213,&A2AD33LDU,&var215,&fEM_A2MC01RC1,&fEM_A2MC02RC1,&fEM_A2MV01RC1,&fEM_A2MV02RC1,&lRM_1_,array_m96_Vr_1,&fEM_A2UC02RDU,&fEM_A2UP02RIM,&fEM_A2UP01RIM,&fEM_A2UG01RDU,&fEM_A2US07RDU,&fEM_A2UV02RIM,&iEM_TERRB1,&fEM_A2UC04RIM,&fEM_A2UC05RIM,&fEM_A2UC06RIM,&fEM_A2UC08RIM,&fEM_A2MC01RSP,&fEM_A2MC02RSP,&fEM_A2MV01RSP,&fEM_A2MV02RSP,&var308,&var309,&vainSBool,&var310,&var311,&vainSFloat,&vainSFloat,&var312,&var313,&var314,&var315,&internal1_m96_Ppv0,&internal1_m96_Pav0,&internal1_m96_Zav0,&internal1_m96_RA00,&internal1_m96_RA10,&internal1_m96_RA50,&internal1_m96_fls,&internal1_m96_flp,&internal1_m96_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_236_1 = {&B1AD11LDU,&B1AD21LDU,&B1AD02LDU,&B1AD01LDU,&B1AD03LDU,&B1AD04LDU,&B1AD05LDU,&var207,&lRM_1_,&var206,&fEM_B1MC01RC1,&fEM_B1MC02RC1,&fEM_B1MV01RC1,&fEM_B1MV02RC1,&lRM_1_,array_m236_Vr_1,&fEM_A1UC02RDU,&fRM_0_,&fEM_A1UP01RIM,&fEM_A1UG01RDU,&fEM_A1US07RDU,&fEM_A1UV02RIM,&iEM_TERBB2,&fEM_A1UC04RIM,&fEM_A1UC05RIM,&fEM_A1UC06RIM,&fEM_A1UC08RIM,&fEM_B1MC01RSP,&fEM_B1MC02RSP,&fEM_B1MV01RSP,&fEM_B1MV02RSP,&var316,&var317,&vainSBool,&var318,&var319,&vainSFloat,&vainSFloat,&var320,&vainSBool,&var321,&var322,&internal1_m236_Ppv0,&internal1_m236_Pav0,&internal1_m236_Zav0,&internal1_m236_RA00,&internal1_m236_RA10,&internal1_m236_RA50,&internal1_m236_fls,&internal1_m236_flp,&internal1_m236_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_60_1 = {&A1AD11LDU,&A1AD21LDU,&A1AD02LDU,&A1AD01LDU,&A1AD03LDU,&A1AD04LDU,&A1AD05LDU,&var212,&lRM_1_,&var211,&fEM_A1MC01RC1,&fEM_A1MC02RC1,&fEM_A1MV01RC1,&fEM_A1MV02RC1,&lRM_1_,array_m60_Vr_1,&fEM_A1UC02RDU,&fRM_0_,&fEM_A1UP01RIM,&fEM_A1UG01RDU,&fEM_A1US07RDU,&fEM_A1UV02RIM,&iEM_TERBB1,&fEM_A1UC04RIM,&fEM_A1UC05RIM,&fEM_A1UC06RIM,&fEM_A1UC08RIM,&fEM_A1MC01RSP,&fEM_A1MC02RSP,&fEM_A1MV01RSP,&fEM_A1MV02RSP,&var323,&var324,&var325,&var326,&var327,&vainSFloat,&vainSFloat,&vainSBool,&vainSBool,&var328,&var329,&internal1_m60_Ppv0,&internal1_m60_Pav0,&internal1_m60_Zav0,&internal1_m60_RA00,&internal1_m60_RA10,&internal1_m60_RA50,&internal1_m60_fls,&internal1_m60_flp,&internal1_m60_MyFirstEnterFlag,&bFirstEnterFlag};
_S_azbars  S_azbars_14_1 = {&var323,&var308,&var293,&var279,&fEM_R0UR30RIM,&A7AP31LDU,&var187,&lEM_R8AD10LC1,&var173,&fEM_R0UL01RIM,&fEM_R0UN02RIM,&fEM_R0UT01RIM,&fEM_R0UT02RIM,&fEM_R0UT04RIM,&fEM_R0UT05RIM,&fEM_R0UH05RSS,&fEM_A0UN02RIM,&fEM_A0UN01RIM,&fEM_A1UR00RIM,&fEM_A1UR01RIM,&fEM_A2UR00RIM,&fEM_A2UR01RIM,&fEM_A3UR00RIM,&fEM_A3UR01RIM,&var223,&var225,&fEM_R0UT03RIM,&fEM_R0UT06RIM,&fEM_A0UR02RSP,&fEM_A0UR01RSP,&fEM_A0UT03RSP,&var330,&var331,&var332,&var333,&var334,&var335,&vainSFloat,&internal1_m14_C1,&internal1_m14_C2,&internal1_m14_C3,&internal1_m14_C4,&internal1_m14_C5,&internal1_m14_C6,&internal1_m14_N20,array_m14_C0_1,&internal1_m14_ImpINI0,&internal1_m14_MyFirstEnterFlag,&bFirstEnterFlag};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  noto(&S_noto_86_1);
  noto(&S_noto_262_1);
  noto(&S_noto_615_1);
  noto(&S_noto_616_1);
  ovb1(&S_ovb1_25_1);
  ovb1(&S_ovb1_203_1);
  noto(&S_noto_521_1);
  bol(&S_bol_955_1);
  bol(&S_bol_965_1);
  bol(&S_bol_943_1);
  bol(&S_bol_964_1);
  bol(&S_bol_967_1);
  zpfs(&S_zpfs_644_1);
  zpfs(&S_zpfs_656_1);
  noto(&S_noto_488_1);
  noto(&S_noto_487_1);
  noto(&S_noto_497_1);
  noto(&S_noto_496_1);
  to3val(&S_to3val_981_1);
  asmot(&S_asmot_918_1);
  asmot(&S_asmot_372_1);
  asmot(&S_asmot_389_1);
  asmot(&S_asmot_405_1);
  asmot(&S_asmot_510_1);
  asmot(&S_asmot_454_1);
  asmot(&S_asmot_469_1);
  asmot(&S_asmot_589_1);
  asmot(&S_asmot_604_1);
  fsumo(&S_fsumo_923_1);
  inf(&S_inf_9_1);
  inf(&S_inf_7_1);
  fsubo(&S_fsubo_8_1);
  fsubo(&S_fsubo_379_1);
  noto(&S_noto_45_1);
  noto(&S_noto_46_1);
  noto(&S_noto_221_1);
  noto(&S_noto_222_1);
  orn(&S_orn_653_1);
  asmot(&S_asmot_617_1);
  asmot(&S_asmot_618_1);
  noto(&S_noto_627_1);
  noto(&S_noto_629_1);
  noto(&S_noto_482_1);
  noto(&S_noto_519_1);
  lk(&S_lk_525_1);
  orn(&S_orn_932_1);
  to3val(&S_to3val_550_1);
  toao(&S_toao_555_1);
  toao(&S_toao_556_1);
  to3val(&S_to3val_526_1);
  toao(&S_toao_533_1);
  twobool(&S_twobool_575_1);
  twobool(&S_twobool_678_1);
  twobool(&S_twobool_698_1);
  twobool(&S_twobool_679_1);
  twobool(&S_twobool_699_1);
  twobool(&S_twobool_715_1);
  to3val(&S_to3val_854_1);
  ktoenc(&S_ktoenc_862_1);
  to3val(&S_to3val_852_1);
  ktoenc(&S_ktoenc_860_1);
  twobool(&S_twobool_573_1);
  twobool(&S_twobool_574_1);
  twobool(&S_twobool_717_1);
  twobool(&S_twobool_716_1);
  twobool(&S_twobool_719_1);
  twobool(&S_twobool_718_1);
  twobool(&S_twobool_1063_1);
  twobool(&S_twobool_878_1);
  twobool(&S_twobool_880_1);
  twobool(&S_twobool_879_1);
  to3val(&S_to3val_551_1);
  toao(&S_toao_557_1);
  toao(&S_toao_558_1);
  twobool(&S_twobool_553_1);
  twobool(&S_twobool_1007_1);
  twobool(&S_twobool_1022_1);
  twobool(&S_twobool_1039_1);
  twobool(&S_twobool_1061_1);
  twobool(&S_twobool_841_1);
  twobool(&S_twobool_1008_1);
  twobool(&S_twobool_1009_1);
  twobool(&S_twobool_1010_1);
  twobool(&S_twobool_1011_1);
  twobool(&S_twobool_1059_1);
  twobool(&S_twobool_837_1);
  twobool(&S_twobool_838_1);
  twobool(&S_twobool_840_1);
  twobool(&S_twobool_839_1);
  twobool(&S_twobool_865_1);
  twobool(&S_twobool_863_1);
  twobool(&S_twobool_866_1);
  twobool(&S_twobool_864_1);
  twobool(&S_twobool_1043_1);
  twobool(&S_twobool_1044_1);
  twobool(&S_twobool_1045_1);
  twobool(&S_twobool_1064_1);
  twobool(&S_twobool_56_1);
  twobool(&S_twobool_41_1);
  twobool(&S_twobool_231_1);
  twobool(&S_twobool_214_1);
  zpfs(&S_zpfs_628_1);
  zpfs(&S_zpfs_630_1);
  or2(&S_or2_933_1);
  or2(&S_or2_940_1);
  or2(&S_or2_947_1);
  or2(&S_or2_956_1);
  ampl(&S_ampl_380_1);
  rs(&S_rs_481_1);
  rs(&S_rs_480_1);
  rs(&S_rs_495_1);
  rs(&S_rs_494_1);
  twobool(&S_twobool_554_1);
  twobool(&S_twobool_535_1);
  twobool(&S_twobool_680_1);
  twobool(&S_twobool_681_1);
  twobool(&S_twobool_702_1);
  twobool(&S_twobool_703_1);
  twobool(&S_twobool_682_1);
  twobool(&S_twobool_683_1);
  twobool(&S_twobool_704_1);
  twobool(&S_twobool_705_1);
  twobool(&S_twobool_1023_1);
  twobool(&S_twobool_1024_1);
  twobool(&S_twobool_1025_1);
  twobool(&S_twobool_1026_1);
  twobool(&S_twobool_842_1);
  twobool(&S_twobool_843_1);
  noto(&S_noto_651_1);
  andn(&S_andn_88_1);
  andn(&S_andn_87_1);
  andn(&S_andn_47_1);
  andn(&S_andn_48_1);
  andn(&S_andn_121_1);
  andn(&S_andn_223_1);
  andn(&S_andn_224_1);
  andn(&S_andn_264_1);
  andn(&S_andn_263_1);
  andn(&S_andn_298_1);
  noto(&S_noto_934_1);
  andn(&S_andn_929_1);
  asmot(&S_asmot_632_1);
  asmot(&S_asmot_634_1);
  asmot(&S_asmot_484_1);
  asmot(&S_asmot_498_1);
  asmot(&S_asmot_486_1);
  noto(&S_noto_941_1);
  andn(&S_andn_937_1);
  noto(&S_noto_948_1);
  andn(&S_andn_945_1);
  noto(&S_noto_957_1);
  andn(&S_andn_952_1);
  lk(&S_lk_524_1);
  noto(&S_noto_931_1);
  andn(&S_andn_927_1);
  twobool(&S_twobool_1062_1);
  to3val(&S_to3val_523_1);
  toao(&S_toao_529_1);
  twobool(&S_twobool_1040_1);
  twobool(&S_twobool_1042_1);
  twobool(&S_twobool_1041_1);
  twobool(&S_twobool_1060_1);
  orrsim(&S_orrsim_60_1);
  orrsim(&S_orrsim_236_1);
  orrsim(&S_orrsim_96_1);
  orrsim(&S_orrsim_272_1);
  orrsim(&S_orrsim_130_1);
  orrsim(&S_orrsim_307_1);
  azbars(&S_azbars_188_1);
  bol(&S_bol_642_1);
  bol(&S_bol_648_1);
  bol(&S_bol_658_1);
  mod1(&S_mod1_664_1);
  fsubo(&S_fsubo_74_1);
  fsubo(&S_fsubo_250_1);
  fsubo(&S_fsubo_291_1);
  fsubo(&S_fsubo_115_1);
  orn(&S_orn_659_1);
  react(&S_react_206_1);
  orn(&S_orn_643_1);
  orn(&S_orn_646_1);
  twobool(&S_twobool_150_1);
  to3val(&S_to3val_156_1);
  toao(&S_toao_161_1);
  toao(&S_toao_162_1);
  toao(&S_toao_163_1);
  twobool(&S_twobool_436_1);
  twobool(&S_twobool_437_1);
  twobool(&S_twobool_438_1);
  to3val(&S_to3val_435_1);
  ktoenc(&S_ktoenc_440_1);
  twobool(&S_twobool_439_1);
  twobool(&S_twobool_343_1);
  twobool(&S_twobool_327_1);
  twobool(&S_twobool_356_1);
  to3val(&S_to3val_331_1);
  ktoenc(&S_ktoenc_334_1);
  twobool(&S_twobool_355_1);
  twobool(&S_twobool_357_1);
  to3val(&S_to3val_341_1);
  ktoenc(&S_ktoenc_342_1);
  twobool(&S_twobool_358_1);
  twobool(&S_twobool_328_1);
  twobool(&S_twobool_329_1);
  twobool(&S_twobool_344_1);
  twobool(&S_twobool_345_1);
  ampl(&S_ampl_669_1);
  twobool(&S_twobool_419_1);
  twobool(&S_twobool_420_1);
  twobool(&S_twobool_418_1);
  to3val(&S_to3val_421_1);
  ktoenc(&S_ktoenc_427_1);
  twobool(&S_twobool_976_1);
  twobool(&S_twobool_977_1);
  twobool(&S_twobool_980_1);
  to3val(&S_to3val_972_1);
  ktoenc(&S_ktoenc_979_1);
  to3val(&S_to3val_991_1);
  ktoenc(&S_ktoenc_996_1);
  twobool(&S_twobool_993_1);
  twobool(&S_twobool_994_1);
  twobool(&S_twobool_997_1);
  andn(&S_andn_363_1);
  twobool(&S_twobool_417_1);
  azbars(&S_azbars_14_1);
  vchs(&S_vchs_730_1);
  vchs(&S_vchs_738_1);
  vchs(&S_vchs_747_1);
  vchs(&S_vchs_756_1);
  vchs(&S_vchs_764_1);
  vchs(&S_vchs_773_1);
  vchs(&S_vchs_782_1);
  vchs(&S_vchs_790_1);
  vchs(&S_vchs_799_1);
  vchs(&S_vchs_808_1);
  vchs(&S_vchs_816_1);
  vchs(&S_vchs_825_1);
  twobool(&S_twobool_149_1);
  to3val(&S_to3val_158_1);
  toao(&S_toao_164_1);
  toao(&S_toao_165_1);
  toao(&S_toao_166_1);
  to3val(&S_to3val_670_1);
  vchs(&S_vchs_888_1);
  vchs(&S_vchs_896_1);
  vchs(&S_vchs_906_1);
  setData(idA3IP02FDU,&var124);
  setData(idB3IP02FDU,&var128);
  setData(idB2IP01FZ2,&var89);
  setData(idB2IP01FZ1,&var90);
  setData(idA2IP01FZ2,&var138);
  setData(idA2IP01FZ1,&var139);
  setData(idA0IT03FRP,&var157);
  setData(idA0IT02FZ2,&var158);
  setData(idA0IT01FZ1,&var161);
  setData(idB0IT03FRP,&var151);
  setData(idB0IT02FZ2,&var152);
  setData(idB0IT01FZ1,&var153);
  setData(idA0IT03IRP,&var157);
  setData(idB0IT03IRP,&var151);
  setData(idR0IN03FI3,&var233);
  setData(idR0IN02FI3,&var234);
  setData(idR0IN03FI2,&var236);
  setData(idR0IN07RIP,&var2);
  setData(idR0IN06RIP,&var1);
  setData(idR0IN03RIP,&var3);
  setData(idR0IN02RIP,&var4);
  setData(idR0IN01RIP,&var5);
  setData(idR0IN02FI2,&var237);
  setData(idR0IN03FI1,&var239);
  setData(idR0IN02FI1,&var240);
  setData(idR0IN03FI4,&var230);
  setData(idR0IN02FI4,&var231);
  setData(idR0IN01FI3,&var235);
  setData(idR0IN01FI2,&var238);
  setData(idR0IN01FI4,&var232);
  setData(idR0IN01FI1,&var242);
  setData(idR4VS12LDU,&var7);
  setData(idR4VS22LDU,&var6);
  setData(idR1VS12LDU,&var11);
  setData(idR2VS12LDU,&var9);
  setData(idR2VS22LDU,&var8);
  setData(idR1VS22LDU,&var10);
  setData(idB5VS12LDU,&var13);
  setData(idB5VS22LDU,&var12);
  setData(idA5VS12LDU,&var15);
  setData(idA5VS22LDU,&var14);
  setData(idB6VS12LDU,&var17);
  setData(idB6VS22LDU,&var16);
  setData(idA6VS12LDU,&var19);
  setData(idA6VS22LDU,&var18);
  setData(idB8IS21LDU,&var66);
  setData(idB8IS11LDU,&var64);
  setData(idA1VP81LZZ,&var20);
  setData(idB1VP81LZZ,&var21);
  setData(idB2IS33LDU,&var22);
  setData(idA0VN01RIM,&var335);
  setData(idB2IS32LIM,&var304);
  setData(idB2IS11LIM,&var306);
  setData(idA2IS32LIM,&var312);
  setData(idA2IS11LIM,&var314);
  setData(idB1IS32LIM,&var320);
  setData(idB1IS11LIM,&var321);
  setData(idA1IS32LIM,&var325);
  setData(idA1IS11LIM,&var328);
  setData(idR0IS02LDU,&lEM_R0IE02LRP);
  setData(idB4IS10LDU,&var43);
  setData(idA4IS10LDU,&var42);
  setData(idB1IE04LDU,&var44);
  setData(idB1IE03LDU,&var45);
  setData(idA1IE04LDU,&var46);
  setData(idA1IE03LDU,&var47);
  setData(idB1IS12LDU,&var48);
  setData(idB1IS11LDU,&var49);
  setData(idB1IS21LDU,&var50);
  setData(idB1IC01UDU,&var51);
  setData(idA1IC01UDU,&var53);
  setData(idA1IS12LDU,&var55);
  setData(idA1IS11LDU,&var56);
  setData(idA1IS21LDU,&var57);
  setData(idB6IS21LDU,&var58);
  setData(idB6IS11LDU,&var59);
  setData(idA6IS21LDU,&var60);
  setData(idA6IS11LDU,&var61);
  setData(idA8IS12LDU,&var62);
  setData(idA8IS22LDU,&var63);
  setData(idB8IS12LDU,&var65);
  setData(idB8IS22LDU,&var67);
  setData(idR4IS12LDU,&var68);
  setData(idR4IS22LDU,&var69);
  setData(idR4IS21LDU,&var70);
  setData(idR4IS11LDU,&var71);
  setData(idB4VP82LDU,&var73);
  setData(idA4VP82LDU,&var72);
  setData(idR2IS21LDU,&var74);
  setData(idR2IS11LDU,&var75);
  setData(idR1IS21LDU,&var76);
  setData(idR1IS11LDU,&var77);
  setData(idB4IS21LDU,&var78);
  setData(idB4IS11LDU,&var79);
  setData(idR8IS11LDU,&var80);
  setData(idA4IS21LDU,&var81);
  setData(idA4IS11LDU,&var82);
  setData(idR5IS21LDU,&var83);
  setData(idR5IS11LDU,&var84);
  setData(idR3IS21LDU,&var85);
  setData(idR3IS11LDU,&var86);
  setData(idB2VP82LDU,&var87);
  setData(idB2IP01IZ2,&var89);
  setData(idB2IP01IZ1,&var90);
  setData(idB2IC01UDU,&var93);
  setData(idB2IS12LDU,&var95);
  setData(idB2IS11LDU,&var96);
  setData(idB2IS21LDU,&var97);
  setData(idB9IS21LDU,&var98);
  setData(idB9IS11LDU,&var99);
  setData(idA9IS21LDU,&var100);
  setData(idA9IS11LDU,&var101);
  setData(idB5IS21LDU,&var102);
  setData(idB5IS11LDU,&var103);
  setData(idA5IS21LDU,&var104);
  setData(idA5IS11LDU,&var105);
  setData(idB0VP81LZZ,&var107);
  setData(idA0VP81LZZ,&var108);
  setData(idB8IC01UDU,&var109);
  setData(idA8IC01UDU,&var111);
  setData(idR6IS68LZZ,&var113);
  setData(idR6IS67LZZ,&var114);
  setData(idR6IS66LZZ,&var115);
  setData(idR6IS65LDU,&var117);
  setData(idR6IS64LDU,&var116);
  setData(idR6IS63LDU,&var119);
  setData(idR6IS62LDU,&var118);
  setData(idB3IS22LDU,&var120);
  setData(idA3IS22LDU,&var121);
  setData(idB3IS11LDU,&var122);
  setData(idA3IS11LDU,&var123);
  setData(idA3IP02IDU,&var124);
  setData(idB3VP81LDU,&var127);
  setData(idA3VP81LDU,&var126);
  setData(idB3IS33LDU,&var130);
  setData(idB3IC01UDU,&var131);
  setData(idB3IS31LDU,&var133);
  setData(idB3IP02IDU,&var128);
  setData(idA3IS33LDU,&var134);
  setData(idA3IC01UDU,&var135);
  setData(idA3IS31LDU,&var137);
  setData(idA2VP82LDU,&var88);
  setData(idA2IP01IZ2,&var138);
  setData(idA2IP01IZ1,&var139);
  setData(idB3IS21LDU,&var140);
  setData(idA3IS21LDU,&var141);
  setData(idA2IS33LDU,&var142);
  setData(idA2IC01UDU,&var143);
  setData(idA2IS12LDU,&var145);
  setData(idA2IS11LDU,&var146);
  setData(idA2IS21LDU,&var147);
  setData(idB0IT02IZ2,&var152);
  setData(idB0IT01IZ1,&var153);
  setData(idA0IT02IZ2,&var158);
  setData(idA0IT01IZ1,&var161);
  setData(idR6IS21LDU,&var159);
  setData(idB7AS31LDU,&var160);
  setData(idA7AS31LDU,&var165);
  setData(idB3IS35LDU,&var168);
  setData(idA3IS35LDU,&var170);
  setData(idR7II73LZ2,&var217);
  setData(idR7II71LZ2,&var178);
  setData(idR7II72LZ2,&var177);
  setData(idR7II72LZ1,&var177);
  setData(idR7II71LZ1,&var178);
  setData(idR7II73LZ1,&var217);
  setData(idR0SR01RIM,&var179);
  setData(idR0ST01RIM,&var284);
  setData(idR0SR02RIM,&var285);
  setData(idR0CR02RIM,&var223);
  setData(idR0CR01RIM,&var225);
  setData(idB0SN08RIM,&var280);
  setData(idA0SN08RIM,&var331);
  setData(idB0SR01RIM,&var281);
  setData(idA0SR01RIM,&var332);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<6;i++ )
    array_m188_C0_1[i] = &(&internal1_m188_C0)[i*5];
  for( i=0;i<6;i++ )
    array_m14_C0_1[i] = &(&internal1_m14_C0)[i*5];
}

#endif
