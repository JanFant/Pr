#ifndef SCM_H
#define SCM_H
// Подсистема scm:SCM
static char SimulOn=0;
static short CodeSub=1;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 3461
static char BUFFER[3461];

#define A1IS12LDU	 BUFFER[0]	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
#define idA1IS12LDU	 1	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
#define A1IS11LDU	 BUFFER[2]	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
#define idA1IS11LDU	 2	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
#define A1IS21LDU	 BUFFER[4]	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
#define idA1IS21LDU	 3	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
#define B6IS21LDU	 BUFFER[6]	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
#define idB6IS21LDU	 4	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
#define B6IS11LDU	 BUFFER[8]	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
#define idB6IS11LDU	 5	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
#define A6IS21LDU	 BUFFER[10]	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
#define idA6IS21LDU	 6	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
#define A6IS11LDU	 BUFFER[12]	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
#define idA6IS11LDU	 7	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
#define A8IS12LDU	 BUFFER[14]	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
#define idA8IS12LDU	 8	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
#define A8IS22LDU	 BUFFER[16]	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
#define idA8IS22LDU	 9	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
#define B8IS12LDU	 BUFFER[18]	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
#define idB8IS12LDU	 10	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
#define B8IS22LDU	 BUFFER[20]	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
#define idB8IS22LDU	 11	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
#define R4IS12LDU	 BUFFER[22]	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
#define idR4IS12LDU	 12	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
#define R4IS22LDU	 BUFFER[24]	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
#define idR4IS22LDU	 13	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
#define R4IS21LDU	 BUFFER[26]	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
#define idR4IS21LDU	 14	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
#define R4IS11LDU	 BUFFER[28]	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
#define idR4IS11LDU	 15	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
#define B4VP82LDU	 BUFFER[30]	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 16	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define A4VP82LDU	 BUFFER[32]	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 17	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define R0EE03LZ2	 BUFFER[34]	//( - , SBz2) Питание  АКНП3  отключить
#define idR0EE03LZ2	 18	//( - , SBz2) Питание  АКНП3  отключить
#define R0EE02LZ2	 BUFFER[36]	//( - , SBz2) Питание  АКНП  отключить
#define idR0EE02LZ2	 19	//( - , SBz2) Питание  АКНП  отключить
#define R0EE04LZ1	 BUFFER[38]	//( - , SBz1) Питание  АКНП4  отключить
#define idR0EE04LZ1	 20	//( - , SBz1) Питание  АКНП4  отключить
#define R0EE03LZ1	 BUFFER[40]	//( - , SBz1) Питание  АКНП3  отключить
#define idR0EE03LZ1	 21	//( - , SBz1) Питание  АКНП3  отключить
#define R0EE02LZ1	 BUFFER[42]	//( - , SBz1) Питание  АКНП  отключить
#define idR0EE02LZ1	 22	//( - , SBz1) Питание  АКНП  отключить
#define R0EE01LZ2	 BUFFER[44]	//( - , SBz2) Питание  АКНП1  отключить
#define idR0EE01LZ2	 23	//( - , SBz2) Питание  АКНП1  отключить
#define R0EE01LZ1	 BUFFER[46]	//( - , SBz1) Питание  АКНП1  отключить
#define idR0EE01LZ1	 24	//( - , SBz1) Питание  АКНП1  отключить
#define B4IS10LDU	 BUFFER[48]	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
#define idB4IS10LDU	 25	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
#define A4IS10LDU	 BUFFER[50]	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
#define idA4IS10LDU	 26	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
#define B1IE04LDU	 BUFFER[52]	//( - , SCM) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 27	//( - , SCM) Движение ББ2 назад (от БУШД)
#define B1IE03LDU	 BUFFER[54]	//( - , SCM) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 28	//( - , SCM) Движение ББ2 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[56]	//( - , SCM) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 29	//( - , SCM) Движение ББ1 назад (от БУШД)
#define A1IE03LDU	 BUFFER[58]	//( - , SCM) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 30	//( - , SCM) Движение ББ1 вперед (от БУШД)
#define B1IS12LDU	 BUFFER[60]	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
#define idB1IS12LDU	 31	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
#define B1IS11LDU	 BUFFER[62]	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
#define idB1IS11LDU	 32	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
#define B1IS21LDU	 BUFFER[64]	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
#define idB1IS21LDU	 33	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
#define B1IC01UDU	 BUFFER[66]	//( - , SDu) Координата штока ББ2
#define idB1IC01UDU	 34	//( - , SDu) Координата штока ББ2
#define A1IC01UDU	 BUFFER[71]	//( - , SDu) Координата штока ББ1
#define idA1IC01UDU	 35	//( - , SDu) Координата штока ББ1
#define B2IS11LDU	 BUFFER[76]	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
#define idB2IS11LDU	 36	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
#define B2IS21LDU	 BUFFER[78]	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
#define idB2IS21LDU	 37	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
#define B9IS21LDU	 BUFFER[80]	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
#define idB9IS21LDU	 38	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
#define B9IS11LDU	 BUFFER[82]	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 39	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
#define A9IS21LDU	 BUFFER[84]	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
#define idA9IS21LDU	 40	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
#define A9IS11LDU	 BUFFER[86]	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 41	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
#define B5IS21LDU	 BUFFER[88]	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
#define idB5IS21LDU	 42	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
#define B5IS11LDU	 BUFFER[90]	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
#define idB5IS11LDU	 43	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
#define A5IS21LDU	 BUFFER[92]	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
#define idA5IS21LDU	 44	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
#define A5IS11LDU	 BUFFER[94]	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
#define idA5IS11LDU	 45	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
#define B0VP81LZZ	 BUFFER[96]	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	 46	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
#define A0VP81LZZ	 BUFFER[98]	//(do32_pti:100 - K27DO, - ) Давление АЗ1 в норме
#define idA0VP81LZZ	 47	//(do32_pti:100 - K27DO, - ) Давление АЗ1 в норме
#define B8IC01UDU	 BUFFER[100]	//( - , SDu) Координата АЗ2
#define idB8IC01UDU	 48	//( - , SDu) Координата АЗ2
#define A8IC01UDU	 BUFFER[105]	//( - , SDu) Координата ДС2
#define idA8IC01UDU	 49	//( - , SDu) Координата ДС2
#define R6IS68LZZ	 BUFFER[110]	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 50	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define R6IS67LZZ	 BUFFER[112]	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 51	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS66LZZ	 BUFFER[114]	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 52	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R2IS21LDU	 BUFFER[116]	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
#define idR2IS21LDU	 53	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
#define R2IS11LDU	 BUFFER[118]	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
#define idR2IS11LDU	 54	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
#define R1IS21LDU	 BUFFER[120]	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
#define idR1IS21LDU	 55	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
#define R1IS11LDU	 BUFFER[122]	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
#define idR1IS11LDU	 56	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
#define B4IS21LDU	 BUFFER[124]	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
#define idB4IS21LDU	 57	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
#define B4IS11LDU	 BUFFER[126]	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
#define idB4IS11LDU	 58	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
#define R8IS11LDU	 BUFFER[128]	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
#define idR8IS11LDU	 59	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
#define A4IS21LDU	 BUFFER[130]	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
#define idA4IS21LDU	 60	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
#define A4IS11LDU	 BUFFER[132]	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
#define idA4IS11LDU	 61	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
#define R5IS21LDU	 BUFFER[134]	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 62	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
#define R5IS11LDU	 BUFFER[136]	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 63	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
#define R3IS21LDU	 BUFFER[138]	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
#define idR3IS21LDU	 64	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
#define R3IS11LDU	 BUFFER[140]	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	 65	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
#define B2VP82LDU	 BUFFER[142]	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 66	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define B2IP01IZ2	 BUFFER[144]	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ2	 67	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
#define B2IP01IZ1	 BUFFER[147]	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	 68	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
#define B2IC01UDU	 BUFFER[150]	//( - , SDu) Координата штока РБ2
#define idB2IC01UDU	 69	//( - , SDu) Координата штока РБ2
#define B2IS12LDU	 BUFFER[155]	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	 70	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
#define B0IT03IRP	 BUFFER[157]	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
#define idB0IT03IRP	 71	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
#define R0IN03FI3	 BUFFER[160]	//( - , SA3) Выход КНК53М Гц от ПТИ
#define idR0IN03FI3	 72	//( - , SA3) Выход КНК53М Гц от ПТИ
#define R0IN02FI3	 BUFFER[165]	//( - , SA3) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI3	 73	//( - , SA3) Выход КНК15-1 Гц от ПТИ
#define R0IN03FI2	 BUFFER[170]	//( - , SA2) Выход КНК53М Гц от ПТИ
#define idR0IN03FI2	 74	//( - , SA2) Выход КНК53М Гц от ПТИ
#define R0IN07RIP	 BUFFER[175]	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
#define idR0IN07RIP	 75	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
#define R0IN06RIP	 BUFFER[180]	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
#define idR0IN06RIP	 76	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
#define TerR0IN06FRP	 BUFFER[185]	//( - , - ) Неисправности СНМ-11 -1,2
#define idTerR0IN06FRP	 77	//( - , - ) Неисправности СНМ-11 -1,2
#define R0IN03RIP	 BUFFER[188]	//( - , SRP) Выход КНК53М Гц от ПТИ
#define idR0IN03RIP	 78	//( - , SRP) Выход КНК53М Гц от ПТИ
#define R0IN02RIP	 BUFFER[193]	//( - , SRP) Выход КНК15- Гц от ПТИ
#define idR0IN02RIP	 79	//( - , SRP) Выход КНК15- Гц от ПТИ
#define R0IN01RIP	 BUFFER[198]	//( - , SRP) Выход СНМ-11 Гц от ПТИ
#define idR0IN01RIP	 80	//( - , SRP) Выход СНМ-11 Гц от ПТИ
#define R0IN02FI2	 BUFFER[203]	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI2	 81	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define R0IN03FI1	 BUFFER[208]	//( - , SA1) Выход КНК53М Гц от ПТИ
#define idR0IN03FI1	 82	//( - , SA1) Выход КНК53М Гц от ПТИ
#define R0IN02FI1	 BUFFER[213]	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI1	 83	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define R0IN03FI4	 BUFFER[218]	//( - , SA4) Выход КНК53М Гц от ПТИ
#define idR0IN03FI4	 84	//( - , SA4) Выход КНК53М Гц от ПТИ
#define R0IN02FI4	 BUFFER[223]	//( - , SA4) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI4	 85	//( - , SA4) Выход КНК15-1 Гц от ПТИ
#define R0IN01FI3	 BUFFER[228]	//( - , SA3) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI3	 86	//( - , SA3) Выход СНМ-11 Гц от ПТИ
#define R0IN01FI2	 BUFFER[233]	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define idR0IN01FI2	 87	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define B0SN07RIM	 BUFFER[238]	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define idB0SN07RIM	 88	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define B0SN06RIM	 BUFFER[243]	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define idB0SN06RIM	 89	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define B0SN05RIM	 BUFFER[248]	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define idB0SN05RIM	 90	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define B0SN04RIM	 BUFFER[253]	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define idB0SN04RIM	 91	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define B0SN03RIM	 BUFFER[258]	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define idB0SN03RIM	 92	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define B0SN02RIM	 BUFFER[263]	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define idB0SN02RIM	 93	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define A0SN07RIM	 BUFFER[268]	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define idA0SN07RIM	 94	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define A0SN06RIM	 BUFFER[273]	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define idA0SN06RIM	 95	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define A0SN05RIM	 BUFFER[278]	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define idA0SN05RIM	 96	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define A0SN04RIM	 BUFFER[283]	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define idA0SN04RIM	 97	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define A0SN03RIM	 BUFFER[288]	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define idA0SN03RIM	 98	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define A0SN02RIM	 BUFFER[293]	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define idA0SN02RIM	 99	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define krb2	 BUFFER[298]	//( - , - ) 
#define idkrb2	 100	//( - , - ) 
#define krb1	 BUFFER[303]	//( - , - ) 
#define idkrb1	 101	//( - , - ) 
#define R0DEUMLSS	 BUFFER[308]	//( - , SCM) Сигнал управления моделью
#define idR0DEUMLSS	 102	//( - , SCM) Сигнал управления моделью
#define R0MW11IP1	 BUFFER[311]	//( - , SCM) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 103	//( - , SCM) Переключатель ВЫСТРЕЛ
#define R0IS01FI0	 BUFFER[314]	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
#define idR0IS01FI0	 104	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
#define A0IT03IRP	 BUFFER[317]	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
#define idA0IT03IRP	 105	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
#define B8IS21LDU	 BUFFER[320]	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
#define idB8IS21LDU	 106	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
#define B8IS11LDU	 BUFFER[322]	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
#define idB8IS11LDU	 107	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
#define A1VP81LZZ	 BUFFER[324]	//(do32_pti:100 - K28DO, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	 108	//(do32_pti:100 - K28DO, - ) Давление СБРОС ББ1 в норме
#define B1VP81LZZ	 BUFFER[326]	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	 109	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
#define B2IS33LDU	 BUFFER[328]	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
#define idB2IS33LDU	 110	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
#define A0VN01RIM	 BUFFER[330]	//( - , SCM) Период разгона  AЗ1
#define idA0VN01RIM	 111	//( - , SCM) Период разгона  AЗ1
#define B2IS32LIM	 BUFFER[335]	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
#define idB2IS32LIM	 112	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
#define B2IS11LIM	 BUFFER[337]	//( - , SCM) Магнит РБ2 обесточен
#define idB2IS11LIM	 113	//( - , SCM) Магнит РБ2 обесточен
#define A2IS32LIM	 BUFFER[339]	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
#define idA2IS32LIM	 114	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
#define A2IS11LIM	 BUFFER[341]	//( - , SCM) Магнит РБ1 обесточен
#define idA2IS11LIM	 115	//( - , SCM) Магнит РБ1 обесточен
#define B1IS32LIM	 BUFFER[343]	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
#define idB1IS32LIM	 116	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
#define B1IS11LIM	 BUFFER[345]	//( - , SCM) Магнит ББ2 обесточен
#define idB1IS11LIM	 117	//( - , SCM) Магнит ББ2 обесточен
#define A1IS32LIM	 BUFFER[347]	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
#define idA1IS32LIM	 118	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
#define A1IS11LIM	 BUFFER[349]	//( - , SCM) Магнит ББ1 обесточен
#define idA1IS11LIM	 119	//( - , SCM) Магнит ББ1 обесточен
#define A3AD34LDU	 BUFFER[351]	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
#define idA3AD34LDU	 120	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
#define R0IS02LDU	 BUFFER[353]	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
#define idR0IS02LDU	 121	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
#define R0EE04LZ2	 BUFFER[355]	//( - , SBz2) Питание  АКНП4  отключить
#define idR0EE04LZ2	 122	//( - , SBz2) Питание  АКНП4  отключить
#define R0IN01FI4	 BUFFER[357]	//( - , SA4) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI4	 123	//( - , SA4) Выход СНМ-11 Гц от ПТИ
#define R0IN01FI1	 BUFFER[362]	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define idR0IN01FI1	 124	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define B7AP31LDU	 BUFFER[367]	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
#define idB7AP31LDU	 125	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
#define A7AP31LDU	 BUFFER[369]	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
#define idA7AP31LDU	 126	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
#define R4VS12LDU	 BUFFER[371]	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
#define idR4VS12LDU	 127	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
#define R4VS22LDU	 BUFFER[373]	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
#define idR4VS22LDU	 128	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
#define R1VS12LDU	 BUFFER[375]	//( - , SCM) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 129	//( - , SCM) Движение МДЗ1 в сторону ВУ
#define R2VS12LDU	 BUFFER[377]	//( - , SCM) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 130	//( - , SCM) Движение МДЗ2 в сторону ВУ
#define R2VS22LDU	 BUFFER[379]	//( - , SCM) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 131	//( - , SCM) Движение МДЗ2 в сторону НУ
#define R1VS22LDU	 BUFFER[381]	//( - , SCM) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 132	//( - , SCM) Движение МДЗ1 в сторону НУ
#define B5VS12LDU	 BUFFER[383]	//( - , SCM) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 133	//( - , SCM) Движение НЛ2 в сторону ВУ
#define B5VS22LDU	 BUFFER[385]	//( - , SCM) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 134	//( - , SCM) Движение НЛ2 в сторону НУ
#define A5VS12LDU	 BUFFER[387]	//( - , SCM) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 135	//( - , SCM) Движение НЛ1 в сторону ВУ
#define A5VS22LDU	 BUFFER[389]	//( - , SCM) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 136	//( - , SCM) Движение НЛ1 в сторону НУ
#define B6VS12LDU	 BUFFER[391]	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
#define idB6VS12LDU	 137	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
#define B6VS22LDU	 BUFFER[393]	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
#define idB6VS22LDU	 138	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
#define A6VS12LDU	 BUFFER[395]	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	 139	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
#define A6VS22LDU	 BUFFER[397]	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	 140	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
#define B8AD20LDU	 BUFFER[399]	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
#define idB8AD20LDU	 141	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
#define B8AD10LDU	 BUFFER[401]	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
#define idB8AD10LDU	 142	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
#define R4AD20LDU	 BUFFER[403]	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
#define idR4AD20LDU	 143	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
#define R4AD10LDU	 BUFFER[405]	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	 144	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
#define B0SR01RIM	 BUFFER[407]	//( - , SCM) Текущая реактивность AЗ2
#define idB0SR01RIM	 145	//( - , SCM) Текущая реактивность AЗ2
#define B3AD33LDU	 BUFFER[412]	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define idB3AD33LDU	 146	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define B3AD05LDU	 BUFFER[414]	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
#define idB3AD05LDU	 147	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
#define B3AD04LDU	 BUFFER[416]	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
#define idB3AD04LDU	 148	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[418]	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
#define idB3AD03LDU	 149	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
#define B3AD02LDU	 BUFFER[420]	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
#define idB3AD02LDU	 150	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
#define B3AD01LDU	 BUFFER[422]	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
#define idB3AD01LDU	 151	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
#define B3AD21LDU	 BUFFER[424]	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 152	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
#define B3AD11LDU	 BUFFER[426]	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 153	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
#define A3AD33LDU	 BUFFER[428]	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define idA3AD33LDU	 154	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define A3AD05LDU	 BUFFER[430]	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
#define idA3AD05LDU	 155	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
#define A3AD04LDU	 BUFFER[432]	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
#define idA3AD04LDU	 156	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
#define A3AD03LDU	 BUFFER[434]	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
#define idA3AD03LDU	 157	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
#define R0CR02RIM	 BUFFER[436]	//( - , SCM) Коэффициент 11 связи АЗ1,2
#define idR0CR02RIM	 158	//( - , SCM) Коэффициент 11 связи АЗ1,2
#define R0CR01RIM	 BUFFER[441]	//( - , SCM) Коэффициент 12 связи АЗ1,2
#define idR0CR01RIM	 159	//( - , SCM) Коэффициент 12 связи АЗ1,2
#define B0SN08RIM	 BUFFER[446]	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
#define idB0SN08RIM	 160	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
#define A0SN08RIM	 BUFFER[451]	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
#define idA0SN08RIM	 161	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
#define B5AD20LDU	 BUFFER[456]	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
#define idB5AD20LDU	 162	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
#define B5AD10LDU	 BUFFER[458]	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
#define idB5AD10LDU	 163	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
#define A5AD20LDU	 BUFFER[460]	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
#define idA5AD20LDU	 164	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
#define A5AD10LDU	 BUFFER[462]	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
#define idA5AD10LDU	 165	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
#define R2AD20LDU	 BUFFER[464]	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	 166	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
#define R2AD10LDU	 BUFFER[466]	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
#define idR2AD10LDU	 167	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
#define R1AD20LDU	 BUFFER[468]	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	 168	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
#define R1AD10LDU	 BUFFER[470]	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
#define idR1AD10LDU	 169	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
#define B6AD20LDU	 BUFFER[472]	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
#define idB6AD20LDU	 170	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
#define B6AD10LDU	 BUFFER[474]	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
#define idB6AD10LDU	 171	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
#define A6AD20LDU	 BUFFER[476]	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
#define idA6AD20LDU	 172	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
#define A6AD10LDU	 BUFFER[478]	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
#define idA6AD10LDU	 173	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
#define A8AD20LDU	 BUFFER[480]	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
#define idA8AD20LDU	 174	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
#define A8AD10LDU	 BUFFER[482]	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
#define idA8AD10LDU	 175	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
#define A2AD21LDU	 BUFFER[484]	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 176	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
#define A2AD11LDU	 BUFFER[486]	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 177	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
#define B1AD05LDU	 BUFFER[488]	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
#define idB1AD05LDU	 178	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
#define B1AD04LDU	 BUFFER[490]	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
#define idB1AD04LDU	 179	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[492]	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
#define idB1AD03LDU	 180	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
#define B1AD02LDU	 BUFFER[494]	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
#define idB1AD02LDU	 181	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
#define B1AD01LDU	 BUFFER[496]	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
#define idB1AD01LDU	 182	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
#define B1AD21LDU	 BUFFER[498]	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 183	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
#define B1AD11LDU	 BUFFER[500]	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 184	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
#define A1AD05LDU	 BUFFER[502]	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
#define idA1AD05LDU	 185	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
#define A1AD04LDU	 BUFFER[504]	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
#define idA1AD04LDU	 186	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[506]	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
#define idA1AD03LDU	 187	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
#define A1AD02LDU	 BUFFER[508]	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
#define idA1AD02LDU	 188	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
#define A1AD01LDU	 BUFFER[510]	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
#define idA1AD01LDU	 189	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
#define A1AD21LDU	 BUFFER[512]	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 190	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
#define A1AD11LDU	 BUFFER[514]	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 191	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
#define A0SR01RIM	 BUFFER[516]	//( - , SCM) Текущая реактивность AЗ1
#define idA0SR01RIM	 192	//( - , SCM) Текущая реактивность AЗ1
#define A3AD02LDU	 BUFFER[521]	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
#define idA3AD02LDU	 193	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
#define A3AD01LDU	 BUFFER[523]	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
#define idA3AD01LDU	 194	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
#define A3AD21LDU	 BUFFER[525]	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 195	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
#define A3AD11LDU	 BUFFER[527]	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 196	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
#define B2AD33LDU	 BUFFER[529]	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
#define idB2AD33LDU	 197	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
#define B2AD05LDU	 BUFFER[531]	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
#define idB2AD05LDU	 198	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
#define B2AD04LDU	 BUFFER[533]	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
#define idB2AD04LDU	 199	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[535]	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
#define idB2AD03LDU	 200	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
#define B2AD02LDU	 BUFFER[537]	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
#define idB2AD02LDU	 201	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
#define B2AD01LDU	 BUFFER[539]	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
#define idB2AD01LDU	 202	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
#define B2AD21LDU	 BUFFER[541]	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 203	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
#define B2AD11LDU	 BUFFER[543]	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 204	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
#define A2AD33LDU	 BUFFER[545]	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
#define idA2AD33LDU	 205	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
#define A2AD05LDU	 BUFFER[547]	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
#define idA2AD05LDU	 206	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
#define A2AD04LDU	 BUFFER[549]	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
#define idA2AD04LDU	 207	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[551]	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
#define idA2AD03LDU	 208	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
#define A2AD02LDU	 BUFFER[553]	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
#define idA2AD02LDU	 209	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
#define A2AD01LDU	 BUFFER[555]	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
#define idA2AD01LDU	 210	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
#define A2VP82LDU	 BUFFER[557]	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 211	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define A2IP01IZ2	 BUFFER[559]	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ2	 212	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
#define A2IP01IZ1	 BUFFER[562]	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	 213	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
#define B3IS21LDU	 BUFFER[565]	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
#define idB3IS21LDU	 214	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
#define A3IS21LDU	 BUFFER[567]	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
#define idA3IS21LDU	 215	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
#define A2IS33LDU	 BUFFER[569]	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
#define idA2IS33LDU	 216	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
#define A2IC01UDU	 BUFFER[571]	//( - , SDu) Координата штока РБ1
#define idA2IC01UDU	 217	//( - , SDu) Координата штока РБ1
#define A2IS12LDU	 BUFFER[576]	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	 218	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
#define A2IS11LDU	 BUFFER[578]	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
#define idA2IS11LDU	 219	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
#define A2IS21LDU	 BUFFER[580]	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
#define idA2IS21LDU	 220	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
#define B0IT02IZ2	 BUFFER[582]	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
#define idB0IT02IZ2	 221	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
#define B0IT01IZ1	 BUFFER[585]	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
#define idB0IT01IZ1	 222	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
#define A0IT02IZ2	 BUFFER[588]	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
#define idA0IT02IZ2	 223	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
#define A0IT01IZ1	 BUFFER[591]	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
#define idA0IT01IZ1	 224	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
#define R6IS21LDU	 BUFFER[594]	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	 225	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
#define B7AS31LDU	 BUFFER[596]	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
#define idB7AS31LDU	 226	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
#define A7AS31LDU	 BUFFER[598]	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
#define idA7AS31LDU	 227	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
#define R6IS65LDU	 BUFFER[600]	//( - , - ) Исправность ВИП ССДИ-35 2канал
#define idR6IS65LDU	 228	//( - , - ) Исправность ВИП ССДИ-35 2канал
#define R6IS64LDU	 BUFFER[602]	//( - , - ) Исправность ВИП ССДИ-35 1канал
#define idR6IS64LDU	 229	//( - , - ) Исправность ВИП ССДИ-35 1канал
#define R6IS63LDU	 BUFFER[604]	//( - , - ) Исправность ВИП ССДИ-39 2канал
#define idR6IS63LDU	 230	//( - , - ) Исправность ВИП ССДИ-39 2канал
#define R6IS62LDU	 BUFFER[606]	//( - , - ) Исправность ВИП ССДИ-39 1канал
#define idR6IS62LDU	 231	//( - , - ) Исправность ВИП ССДИ-39 1канал
#define B3IS22LDU	 BUFFER[608]	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
#define idB3IS22LDU	 232	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
#define A3IS22LDU	 BUFFER[610]	//(do32_pti:100 - K06DO, - ) Приход на НУП ИС1
#define idA3IS22LDU	 233	//(do32_pti:100 - K06DO, - ) Приход на НУП ИС1
#define B3IS11LDU	 BUFFER[612]	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
#define idB3IS11LDU	 234	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
#define A3IS11LDU	 BUFFER[614]	//(do32_pti:100 - K05DO, - ) Приход на ВУ ИС1
#define idA3IS11LDU	 235	//(do32_pti:100 - K05DO, - ) Приход на ВУ ИС1
#define A3IP02IDU	 BUFFER[616]	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 236	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
#define B3VP81LDU	 BUFFER[619]	//( - , - ) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 237	//( - , - ) Давление СПУСК ИС2 в норме
#define A3VP81LDU	 BUFFER[621]	//( - , - ) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 238	//( - , - ) Давление СПУСК ИС1 в норме
#define B3IS33LDU	 BUFFER[623]	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idB3IS33LDU	 239	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define B3IC01UDU	 BUFFER[625]	//( - , SDu) Координата штока ИС2
#define idB3IC01UDU	 240	//( - , SDu) Координата штока ИС2
#define B3IS31LDU	 BUFFER[630]	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
#define idB3IS31LDU	 241	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
#define B3IP02IDU	 BUFFER[632]	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
#define idB3IP02IDU	 242	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
#define A3IS33LDU	 BUFFER[635]	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define idA3IS33LDU	 243	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define A3IC01UDU	 BUFFER[637]	//( - , SDu) Координата штока ИС1
#define idA3IC01UDU	 244	//( - , SDu) Координата штока ИС1
#define A3IS31LDU	 BUFFER[642]	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
#define idA3IS31LDU	 245	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
#define B2AD32LDU	 BUFFER[644]	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
#define idB2AD32LDU	 246	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
#define B2AD31LDU	 BUFFER[646]	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
#define idB2AD31LDU	 247	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
#define B1AD32LDU	 BUFFER[648]	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
#define idB1AD32LDU	 248	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
#define B1AD31LDU	 BUFFER[650]	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
#define idB1AD31LDU	 249	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
#define A3AD31LDU	 BUFFER[652]	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
#define idA3AD31LDU	 250	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
#define C1MD31LP1	 BUFFER[654]	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
#define idC1MD31LP1	 251	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
#define C1MD31LP2	 BUFFER[656]	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
#define idC1MD31LP2	 252	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
#define A1AD31LDU	 BUFFER[658]	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
#define idA1AD31LDU	 253	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
#define A1AD32LDU	 BUFFER[660]	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
#define idA1AD32LDU	 254	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
#define A2AD31LDU	 BUFFER[662]	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
#define idA2AD31LDU	 255	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
#define C2MD31LP1	 BUFFER[664]	//( - , SCM) Кнопка «СБРОС РБ»
#define idC2MD31LP1	 256	//( - , SCM) Кнопка «СБРОС РБ»
#define A2AD32LDU	 BUFFER[666]	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
#define idA2AD32LDU	 257	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
#define R0VZ71LZ2	 BUFFER[668]	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
#define idR0VZ71LZ2	 258	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
#define R0VZ71LZ1	 BUFFER[670]	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
#define idR0VZ71LZ1	 259	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
#define R8AD21LDU	 BUFFER[672]	//(vds32_pti:310 - K31VDSR, - ) Запуск системы инициирования
#define idR8AD21LDU	 260	//(vds32_pti:310 - K31VDSR, - ) Запуск системы инициирования
#define R0AD14LDU	 BUFFER[674]	//( - , SCM) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 261	//( - , SCM) Имитация срабатывания верхней АС II УР
#define R0SR02RIM	 BUFFER[676]	//( - , SCM) Текущая мощность РУ (ватт)
#define idR0SR02RIM	 262	//( - , SCM) Текущая мощность РУ (ватт)
#define B3IS35LDU	 BUFFER[681]	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
#define idB3IS35LDU	 263	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
#define B3AD34LDU	 BUFFER[683]	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
#define idB3AD34LDU	 264	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
#define A3IS35LDU	 BUFFER[685]	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
#define idA3IS35LDU	 265	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
#define R7II73LZ2	 BUFFER[687]	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
#define idR7II73LZ2	 266	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
#define R7II71LZ2	 BUFFER[689]	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
#define idR7II71LZ2	 267	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
#define R7II72LZ2	 BUFFER[691]	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
#define idR7II72LZ2	 268	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
#define R0AD16LDU	 BUFFER[693]	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
#define idR0AD16LDU	 269	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
#define R7II72LZ1	 BUFFER[695]	//(do32_pti:100 - K25DO, - ) Сработала АС IУР (датчик 2)
#define idR7II72LZ1	 270	//(do32_pti:100 - K25DO, - ) Сработала АС IУР (датчик 2)
#define R7II71LZ1	 BUFFER[697]	//(do32_pti:100 - K24DO, - ) Сработала АС IУР (датчик 1)
#define idR7II71LZ1	 271	//(do32_pti:100 - K24DO, - ) Сработала АС IУР (датчик 1)
#define R7II73LZ1	 BUFFER[699]	//(do32_pti:100 - K26DO, - ) Сработала АС IIУР
#define idR7II73LZ1	 272	//(do32_pti:100 - K26DO, - ) Сработала АС IIУР
#define R0SR01RIM	 BUFFER[701]	//( - , SCM) Текущая реактивность PУ
#define idR0SR01RIM	 273	//( - , SCM) Текущая реактивность PУ
#define R0ST01RIM	 BUFFER[706]	//( - , SCM) Текущий период разгона РУ
#define idR0ST01RIM	 274	//( - , SCM) Текущий период разгона РУ
#define A4AD10LDU	 BUFFER[711]	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
#define idA4AD10LDU	 275	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
#define B4AD10LDU	 BUFFER[713]	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
#define idB4AD10LDU	 276	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
#define A9AD10LDU	 BUFFER[715]	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
#define idA9AD10LDU	 277	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
#define B9AD10LDU	 BUFFER[717]	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
#define idB9AD10LDU	 278	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
#define R0MW13LP2	 BUFFER[719]	//( - , SCM) Переключатель «СЕТЬ»
#define idR0MW13LP2	 279	//( - , SCM) Переключатель «СЕТЬ»
#define B3AD31LDU	 BUFFER[721]	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
#define idB3AD31LDU	 280	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
#define fEM_R0UL01RIM	 BUFFER[723]	//(R0UL01RIM) Среднее время генерации нейтронов
#define idfEM_R0UL01RIM	 281	//(R0UL01RIM) Среднее время генерации нейтронов
#define fEM_R0UN02RIM	 BUFFER[728]	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define idfEM_R0UN02RIM	 282	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define fEM_A1UR01RIM	 BUFFER[733]	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR01RIM	 283	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define fEM_A1UR00RIM	 BUFFER[738]	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR00RIM	 284	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define fEM_A3UR00RIM	 BUFFER[743]	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR00RIM	 285	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define fEM_A3UR01RIM	 BUFFER[748]	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR01RIM	 286	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define fEM_R0UT01RIM	 BUFFER[753]	//(R0UT01RIM) Температурный коэффициент (долл)
#define idfEM_R0UT01RIM	 287	//(R0UT01RIM) Температурный коэффициент (долл)
#define fEM_R0UT02RIM	 BUFFER[758]	//(R0UT02RIM) Масса топлива в АЗ
#define idfEM_R0UT02RIM	 288	//(R0UT02RIM) Масса топлива в АЗ
#define fEM_R0UT04RIM	 BUFFER[763]	//(R0UT04RIM) Удельная теплоёмкость топлива
#define idfEM_R0UT04RIM	 289	//(R0UT04RIM) Удельная теплоёмкость топлива
#define fEM_R0UT03RIM	 BUFFER[768]	//(R0UT03RIM) Нормальная температура АЗ град
#define idfEM_R0UT03RIM	 290	//(R0UT03RIM) Нормальная температура АЗ град
#define fEM_R0UT05RIM	 BUFFER[773]	//(R0UT05RIM) Энергия деления ядра
#define idfEM_R0UT05RIM	 291	//(R0UT05RIM) Энергия деления ядра
#define fEM_R0UT06RIM	 BUFFER[778]	//(R0UT06RIM) Конвекционное сопротивление при обдуве
#define idfEM_R0UT06RIM	 292	//(R0UT06RIM) Конвекционное сопротивление при обдуве
#define fEM_A1UC02RDU	 BUFFER[783]	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define idfEM_A1UC02RDU	 293	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define fEM_A1UC04RIM	 BUFFER[788]	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define idfEM_A1UC04RIM	 294	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define fEM_A1UC05RIM	 BUFFER[793]	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define idfEM_A1UC05RIM	 295	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define fEM_A1UC06RIM	 BUFFER[798]	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define idfEM_A1UC06RIM	 296	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define fEM_A2UC06RIM	 BUFFER[803]	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define idfEM_A2UC06RIM	 297	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define fEM_A2UC05RIM	 BUFFER[808]	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define idfEM_A2UC05RIM	 298	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define fEM_A2UC04RIM	 BUFFER[813]	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define idfEM_A2UC04RIM	 299	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define fEM_A2UC02RDU	 BUFFER[818]	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define idfEM_A2UC02RDU	 300	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define fEM_A3UC06RIM	 BUFFER[823]	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define idfEM_A3UC06RIM	 301	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define fEM_A3UC05RIM	 BUFFER[828]	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC05RIM	 302	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define fEM_A3UC04RIM	 BUFFER[833]	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define idfEM_A3UC04RIM	 303	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define fEM_A3UC02RDU	 BUFFER[838]	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define idfEM_A3UC02RDU	 304	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define fEM_R4UV80RDU	 BUFFER[843]	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
#define idfEM_R4UV80RDU	 305	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
#define fEM_R4UC10RIM	 BUFFER[848]	//(R4UC10RIM) Координата верхних механических упоров тележки мм
#define idfEM_R4UC10RIM	 306	//(R4UC10RIM) Координата верхних механических упоров тележки мм
#define fEM_R4UC20RIM	 BUFFER[853]	//(R4UC20RIM) Координата нижних механических упоров тележки мм
#define idfEM_R4UC20RIM	 307	//(R4UC20RIM) Координата нижних механических упоров тележки мм
#define fEM_B8UC21RIM	 BUFFER[858]	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define idfEM_B8UC21RIM	 308	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define fEM_B8UC20RIM	 BUFFER[863]	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define idfEM_B8UC20RIM	 309	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define fEM_B8UC11RIM	 BUFFER[868]	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define idfEM_B8UC11RIM	 310	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define fEM_B8UC10RIM	 BUFFER[873]	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define idfEM_B8UC10RIM	 311	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define fEM_B8UV80RDU	 BUFFER[878]	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define idfEM_B8UV80RDU	 312	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define fEM_A8UV80RDU	 BUFFER[883]	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define idfEM_A8UV80RDU	 313	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define fEM_A8UC10RIM	 BUFFER[888]	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define idfEM_A8UC10RIM	 314	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define fEM_A8UC11RIM	 BUFFER[893]	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define idfEM_A8UC11RIM	 315	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define fEM_A8UC20RIM	 BUFFER[898]	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define idfEM_A8UC20RIM	 316	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define fEM_A8UC21RIM	 BUFFER[903]	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define idfEM_A8UC21RIM	 317	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define fEM_A6UC10RIM	 BUFFER[908]	//(A6UC10RIM) Время полного хода БЗ (сек)
#define idfEM_A6UC10RIM	 318	//(A6UC10RIM) Время полного хода БЗ (сек)
#define fEM_R1UC10RIM	 BUFFER[913]	//(R1UC10RIM) Время полного хода МДЗ сек
#define idfEM_R1UC10RIM	 319	//(R1UC10RIM) Время полного хода МДЗ сек
#define fEM_A5UC10RIM	 BUFFER[918]	//(A5UC10RIM) Время полного хода НЛ сек
#define idfEM_A5UC10RIM	 320	//(A5UC10RIM) Время полного хода НЛ сек
#define fEM_A0UN01RIM	 BUFFER[923]	//(A0UN01RIM) Мощность источника нейтронов ИНИ
#define idfEM_A0UN01RIM	 321	//(A0UN01RIM) Мощность источника нейтронов ИНИ
#define fEM_R4UC22RIM	 BUFFER[928]	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define idfEM_R4UC22RIM	 322	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define fEM_A1UG01RDU	 BUFFER[933]	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define idfEM_A1UG01RDU	 323	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define fEM_A2UG01RDU	 BUFFER[938]	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
#define idfEM_A2UG01RDU	 324	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
#define fEM_A3UG01RDU	 BUFFER[943]	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
#define idfEM_A3UG01RDU	 325	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
#define fEM_R7UC10RIM	 BUFFER[948]	//(R7UC10RIM) X-координата КНК53М R7IN13 см
#define idfEM_R7UC10RIM	 326	//(R7UC10RIM) X-координата КНК53М R7IN13 см
#define fEM_R7UC19RIM	 BUFFER[953]	//(R7UC19RIM) Y-координата СНМ-11 (11) см
#define idfEM_R7UC19RIM	 327	//(R7UC19RIM) Y-координата СНМ-11 (11) см
#define fEM_R7UI02RIM	 BUFFER[958]	//(R7UI02RIM) Коэффициент усиления уровня радиации
#define idfEM_R7UI02RIM	 328	//(R7UI02RIM) Коэффициент усиления уровня радиации
#define fEM_R7UL01RIM	 BUFFER[963]	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define idfEM_R7UL01RIM	 329	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define fEM_A2UR00RIM	 BUFFER[968]	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define idfEM_A2UR00RIM	 330	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define fEM_A2UR01RIM	 BUFFER[973]	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define idfEM_A2UR01RIM	 331	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define fEM_A0UN02RIM	 BUFFER[978]	//(A0UN02RIM) Мощность источника нейтронов с АНИ
#define idfEM_A0UN02RIM	 332	//(A0UN02RIM) Мощность источника нейтронов с АНИ
#define fEM_R0UR30RIM	 BUFFER[983]	//(R0UR30RIM) Реактивность вносимая образцами (долл)
#define idfEM_R0UR30RIM	 333	//(R0UR30RIM) Реактивность вносимая образцами (долл)
#define fEM_R0UR01RIM	 BUFFER[988]	//(R0UR01RIM) Стартовая отрицательная реактивность
#define idfEM_R0UR01RIM	 334	//(R0UR01RIM) Стартовая отрицательная реактивность
#define fEM_R0UT02RDU	 BUFFER[993]	//(R0UT02RDU) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RDU	 335	//(R0UT02RDU) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RDU	 BUFFER[998]	//(R0UT01RDU) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RDU	 336	//(R0UT01RDU) Нижний предел шкалы датчика температуры
#define fEM_A1UC03RDU	 BUFFER[1003]	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define idfEM_A1UC03RDU	 337	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define fEM_A2UP03RDU	 BUFFER[1008]	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP03RDU	 338	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UP04RDU	 BUFFER[1013]	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP04RDU	 339	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UC03RDU	 BUFFER[1018]	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define idfEM_A2UC03RDU	 340	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define fEM_A3UP03RDU	 BUFFER[1023]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 341	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1028]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 342	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UC03RDU	 BUFFER[1033]	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define idfEM_A3UC03RDU	 343	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define fEM_R7UI74RIM	 BUFFER[1038]	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define idfEM_R7UI74RIM	 344	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define fEM_A8UC03RDU	 BUFFER[1043]	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define idfEM_A8UC03RDU	 345	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define fEM_R0UV87RDU	 BUFFER[1048]	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 346	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV81RDU	 BUFFER[1053]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 347	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1058]	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 348	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1063]	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 349	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1068]	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 350	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1073]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 351	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1078]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 352	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_A8UC08RDU	 BUFFER[1083]	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define idfEM_A8UC08RDU	 353	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define fEM_B8UC08RDU	 BUFFER[1088]	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define idfEM_B8UC08RDU	 354	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define fEM_R4UC08RDU	 BUFFER[1093]	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define idfEM_R4UC08RDU	 355	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define fEM_R0UH01RSS	 BUFFER[1098]	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
#define idfEM_R0UH01RSS	 356	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
#define fEM_A0UX00RSS	 BUFFER[1103]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 357	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_R7UX01RSS	 BUFFER[1108]	//(R7UX01RSS) X-координата камеры R7IN11
#define idfEM_R7UX01RSS	 358	//(R7UX01RSS) X-координата камеры R7IN11
#define fEM_R7UX02RSS	 BUFFER[1113]	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define idfEM_R7UX02RSS	 359	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define fEM_R7UX04RSS	 BUFFER[1118]	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define idfEM_R7UX04RSS	 360	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define fEM_R7UX05RSS	 BUFFER[1123]	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define idfEM_R7UX05RSS	 361	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define fEM_R7UX06RSS	 BUFFER[1128]	//(R7UX06RSS) X-координата камеры R7IN23 (см)
#define idfEM_R7UX06RSS	 362	//(R7UX06RSS) X-координата камеры R7IN23 (см)
#define fEM_R7UX07RSS	 BUFFER[1133]	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define idfEM_R7UX07RSS	 363	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define fEM_R7UX08RSS	 BUFFER[1138]	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define idfEM_R7UX08RSS	 364	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define fEM_R7UX09RSS	 BUFFER[1143]	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define idfEM_R7UX09RSS	 365	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define fEM_R7UY01RSS	 BUFFER[1148]	//(R7UY01RSS) Y-координата камеры R7IN11
#define idfEM_R7UY01RSS	 366	//(R7UY01RSS) Y-координата камеры R7IN11
#define fEM_R7UY02RSS	 BUFFER[1153]	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define idfEM_R7UY02RSS	 367	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define fEM_R7UY04RSS	 BUFFER[1158]	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define idfEM_R7UY04RSS	 368	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define fEM_R7UY05RSS	 BUFFER[1163]	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define idfEM_R7UY05RSS	 369	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define fEM_R7UY06RSS	 BUFFER[1168]	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define idfEM_R7UY06RSS	 370	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define fEM_R7UY07RSS	 BUFFER[1173]	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define idfEM_R7UY07RSS	 371	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define fEM_R7UY08RSS	 BUFFER[1178]	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define idfEM_R7UY08RSS	 372	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define fEM_R7UY09RSS	 BUFFER[1183]	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define idfEM_R7UY09RSS	 373	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define fEM_R7UX10RSS	 BUFFER[1188]	//(R7UX10RSS) X-координата камеры R7IN41
#define idfEM_R7UX10RSS	 374	//(R7UX10RSS) X-координата камеры R7IN41
#define fEM_R7UX11RSS	 BUFFER[1193]	//(R7UX11RSS) X-координата камеры R7IN42
#define idfEM_R7UX11RSS	 375	//(R7UX11RSS) X-координата камеры R7IN42
#define fEM_R7UX12RSS	 BUFFER[1198]	//(R7UX12RSS) X-координата камеры R7IN43
#define idfEM_R7UX12RSS	 376	//(R7UX12RSS) X-координата камеры R7IN43
#define fEM_R7UY10RSS	 BUFFER[1203]	//(R7UY10RSS) Y-координата камеры R7IN41
#define idfEM_R7UY10RSS	 377	//(R7UY10RSS) Y-координата камеры R7IN41
#define fEM_R7UY11RSS	 BUFFER[1208]	//(R7UY11RSS) Y-координата камеры R7IN42
#define idfEM_R7UY11RSS	 378	//(R7UY11RSS) Y-координата камеры R7IN42
#define fEM_R7UY12RSS	 BUFFER[1213]	//(R7UY12RSS) Y-координата камеры R7IN43
#define idfEM_R7UY12RSS	 379	//(R7UY12RSS) Y-координата камеры R7IN43
#define fEM_A0UX01RSS	 BUFFER[1218]	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define idfEM_A0UX01RSS	 380	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define fEM_A0UX02RSS	 BUFFER[1223]	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define idfEM_A0UX02RSS	 381	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define fEM_A0UX03RSS	 BUFFER[1228]	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define idfEM_A0UX03RSS	 382	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define fEM_A0UX04RSS	 BUFFER[1233]	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define idfEM_A0UX04RSS	 383	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define fEM_A0UX05RSS	 BUFFER[1238]	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define idfEM_A0UX05RSS	 384	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define fEM_A0UX06RSS	 BUFFER[1243]	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define idfEM_A0UX06RSS	 385	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define fEM_A0UX07RSS	 BUFFER[1248]	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define idfEM_A0UX07RSS	 386	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define fEM_A0UX08RSS	 BUFFER[1253]	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define idfEM_A0UX08RSS	 387	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define fEM_A0UX09RSS	 BUFFER[1258]	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define idfEM_A0UX09RSS	 388	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define fEM_A0UX10RSS	 BUFFER[1263]	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define idfEM_A0UX10RSS	 389	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define fEM_A0UX11RSS	 BUFFER[1268]	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define idfEM_A0UX11RSS	 390	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define fEM_A0UX12RSS	 BUFFER[1273]	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define idfEM_A0UX12RSS	 391	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define fEM_B0UX01RSS	 BUFFER[1278]	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define idfEM_B0UX01RSS	 392	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define fEM_B0UX02RSS	 BUFFER[1283]	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define idfEM_B0UX02RSS	 393	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define fEM_B0UX03RSS	 BUFFER[1288]	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	 394	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	 BUFFER[1293]	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
#define idfEM_B0UX04RSS	 395	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
#define fEM_B0UX05RSS	 BUFFER[1298]	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	 396	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_B0UX06RSS	 BUFFER[1303]	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define idfEM_B0UX06RSS	 397	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define fEM_B0UX07RSS	 BUFFER[1308]	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define idfEM_B0UX07RSS	 398	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define fEM_B0UX08RSS	 BUFFER[1313]	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define idfEM_B0UX08RSS	 399	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define fEM_B0UX09RSS	 BUFFER[1318]	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define idfEM_B0UX09RSS	 400	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define fEM_B0UX10RSS	 BUFFER[1323]	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define idfEM_B0UX10RSS	 401	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define fEM_B0UX11RSS	 BUFFER[1328]	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define idfEM_B0UX11RSS	 402	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define fEM_B0UX12RSS	 BUFFER[1333]	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define idfEM_B0UX12RSS	 403	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define fEM_R0UH02RSS	 BUFFER[1338]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define idfEM_R0UH02RSS	 404	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define fEM_R0UH03RSS	 BUFFER[1343]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define idfEM_R0UH03RSS	 405	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define fEM_R4US80RDU	 BUFFER[1348]	//(R4US80RDU) Тормозной путь тележки (мм)
#define idfEM_R4US80RDU	 406	//(R4US80RDU) Тормозной путь тележки (мм)
#define fEM_R7UI71RIM	 BUFFER[1353]	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define idfEM_R7UI71RIM	 407	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define fEM_R7UI72RIM	 BUFFER[1358]	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define idfEM_R7UI72RIM	 408	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define fEM_R7UI73RIM	 BUFFER[1363]	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define idfEM_R7UI73RIM	 409	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define fEM_A1UP01RIM	 BUFFER[1368]	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define idfEM_A1UP01RIM	 410	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define fEM_A2UP01RIM	 BUFFER[1373]	//(A2UP01RIM) Текущее давление на сброс РБ
#define idfEM_A2UP01RIM	 411	//(A2UP01RIM) Текущее давление на сброс РБ
#define fEM_A0UP02RIM	 BUFFER[1378]	//(A0UP02RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP02RIM	 412	//(A0UP02RIM) Текущее давление в АЗ1,2
#define fEM_A3UP01RIM	 BUFFER[1383]	//(A3UP01RIM) Текущее давление на СПУСК ИС
#define idfEM_A3UP01RIM	 413	//(A3UP01RIM) Текущее давление на СПУСК ИС
#define fEM_A1UP82RIM	 BUFFER[1388]	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define idfEM_A1UP82RIM	 414	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define fEM_A3UP02RDU	 BUFFER[1393]	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define idfEM_A3UP02RDU	 415	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define fEM_A1UV02RIM	 BUFFER[1398]	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define idfEM_A1UV02RIM	 416	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define fEM_A3UV02RIM	 BUFFER[1403]	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define idfEM_A3UV02RIM	 417	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define fEM_A2UV02RIM	 BUFFER[1408]	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define idfEM_A2UV02RIM	 418	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define fEM_B8US80RDU	 BUFFER[1413]	//(B8US80RDU) Тормозной путь АЗ2 (мм)
#define idfEM_B8US80RDU	 419	//(B8US80RDU) Тормозной путь АЗ2 (мм)
#define fEM_A8US80RDU	 BUFFER[1418]	//(A8US80RDU) Тормозной путь ДС2 (мм)
#define idfEM_A8US80RDU	 420	//(A8US80RDU) Тормозной путь ДС2 (мм)
#define fEM_A6US80RDU	 BUFFER[1423]	//(A6US80RDU) Тормозной путь БЗ (мм)
#define idfEM_A6US80RDU	 421	//(A6US80RDU) Тормозной путь БЗ (мм)
#define fEM_A1US07RDU	 BUFFER[1428]	//(A1US07RDU) Постоянная времени масляного демпфера ББ
#define idfEM_A1US07RDU	 422	//(A1US07RDU) Постоянная времени масляного демпфера ББ
#define fEM_A2US07RDU	 BUFFER[1433]	//(A2US07RDU) Постоянная времени масляного демпфера РБ
#define idfEM_A2US07RDU	 423	//(A2US07RDU) Постоянная времени масляного демпфера РБ
#define fEM_A3US07RDU	 BUFFER[1438]	//(A3US07RDU) Постоянная времени масляного демпфера ИС
#define idfEM_A3US07RDU	 424	//(A3US07RDU) Постоянная времени масляного демпфера ИС
#define fEM_R7UI75RIM	 BUFFER[1443]	//(R7UI75RIM) Множитель к уровню радиации
#define idfEM_R7UI75RIM	 425	//(R7UI75RIM) Множитель к уровню радиации
#define fEM_R0UH21RSS	 BUFFER[1448]	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	 426	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	 BUFFER[1453]	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	 427	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	 BUFFER[1458]	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	 428	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0UH05RSS	 BUFFER[1463]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 429	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_A4UL10RIM	 BUFFER[1468]	//(A4UL10RIM) Время полного перемещения НИ сек
#define idfEM_A4UL10RIM	 430	//(A4UL10RIM) Время полного перемещения НИ сек
#define fEM_A9UL10RIM	 BUFFER[1473]	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define idfEM_A9UL10RIM	 431	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define fEM_R3UL10RIM	 BUFFER[1478]	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define idfEM_R3UL10RIM	 432	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define fEM_R5UL10RIM	 BUFFER[1483]	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define idfEM_R5UL10RIM	 433	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define fEM_R6UL10RIM	 BUFFER[1488]	//(R6UL10RIM) Время полного хода кран-балки сек
#define idfEM_R6UL10RIM	 434	//(R6UL10RIM) Время полного хода кран-балки сек
#define lEM_C1AD31LRP	 BUFFER[1493]	//(C1AD31LRP) Общий сброс от РПУ
#define idlEM_C1AD31LRP	 435	//(C1AD31LRP) Общий сброс от РПУ
#define lEM_R0IE01LRP	 BUFFER[1495]	//(R0IE01LRP) Отключение питание детекторов
#define idlEM_R0IE01LRP	 436	//(R0IE01LRP) Отключение питание детекторов
#define lEM_R0IE02LRP	 BUFFER[1497]	//(R0IE02LRP) Отключить питание ПР, ПУ
#define idlEM_R0IE02LRP	 437	//(R0IE02LRP) Отключить питание ПР, ПУ
#define fEM_A2UP02RIM	 BUFFER[1499]	//(A2UP02RIM) Текущее давление на подъём РБ
#define idfEM_A2UP02RIM	 438	//(A2UP02RIM) Текущее давление на подъём РБ
#define fEM_A2UP03RIM	 BUFFER[1504]	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define idfEM_A2UP03RIM	 439	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define fEM_A0UP01RIM	 BUFFER[1509]	//(A0UP01RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP01RIM	 440	//(A0UP01RIM) Текущее давление в АЗ1,2
#define fEM_A3UP02RIM	 BUFFER[1514]	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define idfEM_A3UP02RIM	 441	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define fEM_A4UP01RIM	 BUFFER[1519]	//(A4UP01RIM) Текущее давление на подъём НИ
#define idfEM_A4UP01RIM	 442	//(A4UP01RIM) Текущее давление на подъём НИ
#define fEM_A4UP02RIM	 BUFFER[1524]	//(A4UP02RIM) Нижняя граница давления на подъём НИ
#define idfEM_A4UP02RIM	 443	//(A4UP02RIM) Нижняя граница давления на подъём НИ
#define fEM_R7UI76RIM	 BUFFER[1529]	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define idfEM_R7UI76RIM	 444	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define fEM_R7UI77RIM	 BUFFER[1534]	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define idfEM_R7UI77RIM	 445	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define iEM_TERBB1	 BUFFER[1539]	//(TERBB1) Неисправности  ББ1
#define idiEM_TERBB1	 446	//(TERBB1) Неисправности  ББ1
#define fEM_A1MC02RC1	 BUFFER[1542]	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
#define idfEM_A1MC02RC1	 447	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
#define fEM_A1MV02RC1	 BUFFER[1547]	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define idfEM_A1MV02RC1	 448	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define iEM_TERBB2	 BUFFER[1552]	//(TERBB2) Неисправности  ББ2
#define idiEM_TERBB2	 449	//(TERBB2) Неисправности  ББ2
#define fEM_B1MC02RC1	 BUFFER[1555]	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
#define idfEM_B1MC02RC1	 450	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
#define fEM_B1MV02RC1	 BUFFER[1560]	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define idfEM_B1MV02RC1	 451	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define iEM_TERRB2	 BUFFER[1565]	//(TERRB2) Неисправности  РБ2
#define idiEM_TERRB2	 452	//(TERRB2) Неисправности  РБ2
#define fEM_B2MC02RC1	 BUFFER[1568]	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
#define idfEM_B2MC02RC1	 453	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
#define fEM_B2MV02RC1	 BUFFER[1573]	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define idfEM_B2MV02RC1	 454	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define iEM_TERRB1	 BUFFER[1578]	//(TERRB1) Неисправности  РБ1
#define idiEM_TERRB1	 455	//(TERRB1) Неисправности  РБ1
#define fEM_A2MC02RC1	 BUFFER[1581]	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
#define idfEM_A2MC02RC1	 456	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
#define fEM_A2MV02RC1	 BUFFER[1586]	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define idfEM_A2MV02RC1	 457	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define iEM_TERIS2	 BUFFER[1591]	//(TERIS2) Неисправности  ИС2
#define idiEM_TERIS2	 458	//(TERIS2) Неисправности  ИС2
#define fEM_B3MC02RC1	 BUFFER[1594]	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
#define idfEM_B3MC02RC1	 459	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
#define fEM_B3MV02RC1	 BUFFER[1599]	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define idfEM_B3MV02RC1	 460	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define iEM_TERIS1	 BUFFER[1604]	//(TERIS1) Неисправности  ИС1
#define idiEM_TERIS1	 461	//(TERIS1) Неисправности  ИС1
#define fEM_A3MC02RC1	 BUFFER[1607]	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
#define idfEM_A3MC02RC1	 462	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
#define fEM_A3MV02RC1	 BUFFER[1612]	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define idfEM_A3MV02RC1	 463	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define iEM_TERA1IE04LDU	 BUFFER[1617]	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define idiEM_TERA1IE04LDU	 464	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define iEM_TERA1IE03LDU	 BUFFER[1620]	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define idiEM_TERA1IE03LDU	 465	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define fEM_A1MC01RC1	 BUFFER[1623]	//(A1MC01RC1) Заданная координата  ББ1 от ИС
#define idfEM_A1MC01RC1	 466	//(A1MC01RC1) Заданная координата  ББ1 от ИС
#define iEM_TERB1IE03LDU	 BUFFER[1628]	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define idiEM_TERB1IE03LDU	 467	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define iEM_TERB1IE04LDU	 BUFFER[1631]	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define idiEM_TERB1IE04LDU	 468	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define fEM_B1MC01RC1	 BUFFER[1634]	//(B1MC01RC1) Заданная координата ББ2 от ИС
#define idfEM_B1MC01RC1	 469	//(B1MC01RC1) Заданная координата ББ2 от ИС
#define fEM_B1MV01RC1	 BUFFER[1639]	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define idfEM_B1MV01RC1	 470	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define fEM_B2MC01RC1	 BUFFER[1644]	//(B2MC01RC1) Заданная координата РБ2 от ИС
#define idfEM_B2MC01RC1	 471	//(B2MC01RC1) Заданная координата РБ2 от ИС
#define fEM_B2MV01RC1	 BUFFER[1649]	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define idfEM_B2MV01RC1	 472	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define fEM_A3MC01RC1	 BUFFER[1654]	//(A3MC01RC1) Заданная координата ИС1 от ИС
#define idfEM_A3MC01RC1	 473	//(A3MC01RC1) Заданная координата ИС1 от ИС
#define fEM_A3MV01RC1	 BUFFER[1659]	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define idfEM_A3MV01RC1	 474	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define fEM_B3MC01RC1	 BUFFER[1664]	//(B3MC01RC1) Заданная координата ИС2 от ИС
#define idfEM_B3MC01RC1	 475	//(B3MC01RC1) Заданная координата ИС2 от ИС
#define fEM_B3MV01RC1	 BUFFER[1669]	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define idfEM_B3MV01RC1	 476	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define iEM_TERA2SS21LIM	 BUFFER[1674]	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define idiEM_TERA2SS21LIM	 477	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define iEM_TERA2SS12LIM	 BUFFER[1677]	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define idiEM_TERA2SS12LIM	 478	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define iEM_TERR6SS21LIM	 BUFFER[1680]	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define idiEM_TERR6SS21LIM	 479	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define iEM_TERA2VP82LIM	 BUFFER[1683]	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define idiEM_TERA2VP82LIM	 480	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define iEM_TERA2SS11LIM	 BUFFER[1686]	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define idiEM_TERA2SS11LIM	 481	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define iEM_TERB3SS21LIM	 BUFFER[1689]	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define idiEM_TERB3SS21LIM	 482	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define iEM_TERA0MT01RIM	 BUFFER[1692]	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define idiEM_TERA0MT01RIM	 483	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define iEM_TERB0MT01RIM	 BUFFER[1695]	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define idiEM_TERB0MT01RIM	 484	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define iEM_TERA2SP01RIM	 BUFFER[1698]	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define idiEM_TERA2SP01RIM	 485	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define iEM_TERB2SP01RIM	 BUFFER[1701]	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define idiEM_TERB2SP01RIM	 486	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define iEM_TERB3SP02RIM	 BUFFER[1704]	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define idiEM_TERB3SP02RIM	 487	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define iEM_TERA3SC01RIM	 BUFFER[1707]	//(TERA3SC01RIM) Искажение: Координата штока ИС1
#define idiEM_TERA3SC01RIM	 488	//(TERA3SC01RIM) Искажение: Координата штока ИС1
#define iEM_TERA3VP81LIM	 BUFFER[1710]	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define idiEM_TERA3VP81LIM	 489	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define iEM_TERA2SC01RIM	 BUFFER[1713]	//(TERA2SC01RIM) Искажение: Координата штока РБ1
#define idiEM_TERA2SC01RIM	 490	//(TERA2SC01RIM) Искажение: Координата штока РБ1
#define iEM_TERA2SS33LIM	 BUFFER[1716]	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define idiEM_TERA2SS33LIM	 491	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define iEM_TERA3SS21LIM	 BUFFER[1719]	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define idiEM_TERA3SS21LIM	 492	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define iEM_TERA3SS33LIM	 BUFFER[1722]	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define idiEM_TERA3SS33LIM	 493	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define iEM_TERA3SS31LIM	 BUFFER[1725]	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define idiEM_TERA3SS31LIM	 494	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define iEM_TERB3SS31LIM	 BUFFER[1728]	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define idiEM_TERB3SS31LIM	 495	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define iEM_TERB3SS33LIM	 BUFFER[1731]	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idiEM_TERB3SS33LIM	 496	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define iEM_TERB3SC01RIM	 BUFFER[1734]	//(TERB3SC01RIM) Искажение: Координата штока ИС2
#define idiEM_TERB3SC01RIM	 497	//(TERB3SC01RIM) Искажение: Координата штока ИС2
#define iEM_TERA3SS11LIM	 BUFFER[1737]	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define idiEM_TERA3SS11LIM	 498	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define iEM_TERB3SS11LIM	 BUFFER[1740]	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define idiEM_TERB3SS11LIM	 499	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define iEM_TERR6IS64LIM	 BUFFER[1743]	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define idiEM_TERR6IS64LIM	 500	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define iEM_TERB3SS22LIM	 BUFFER[1746]	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define idiEM_TERB3SS22LIM	 501	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define iEM_TERA3SS22LIM	 BUFFER[1749]	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define idiEM_TERA3SS22LIM	 502	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define iEM_TERA3SP02RIM	 BUFFER[1752]	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define idiEM_TERA3SP02RIM	 503	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define iEM_TERR6IS62LIM	 BUFFER[1755]	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define idiEM_TERR6IS62LIM	 504	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define iEM_TERR6IS66LIM	 BUFFER[1758]	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idiEM_TERR6IS66LIM	 505	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define iEM_TERR6IS67LIM	 BUFFER[1761]	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idiEM_TERR6IS67LIM	 506	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define iEM_TERA0VP81LIM	 BUFFER[1764]	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define idiEM_TERA0VP81LIM	 507	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define iEM_TERB0VP81LIM	 BUFFER[1767]	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define idiEM_TERB0VP81LIM	 508	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define iEM_TERR0VP81LIM	 BUFFER[1770]	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define idiEM_TERR0VP81LIM	 509	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define iEM_TERR6IS68LIM	 BUFFER[1773]	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define idiEM_TERR6IS68LIM	 510	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define iEM_TERR7SI74RIM	 BUFFER[1776]	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define idiEM_TERR7SI74RIM	 511	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define iEM_TERA5SS21LIM	 BUFFER[1779]	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define idiEM_TERA5SS21LIM	 512	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define iEM_TERB5SS11LIM	 BUFFER[1782]	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define idiEM_TERB5SS11LIM	 513	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define iEM_TERA5SS11LIM	 BUFFER[1785]	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define idiEM_TERA5SS11LIM	 514	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define iEM_TERA9SS11LIM	 BUFFER[1788]	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define idiEM_TERA9SS11LIM	 515	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define iEM_TERB2SS11LIM	 BUFFER[1791]	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define idiEM_TERB2SS11LIM	 516	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define iEM_TERB2SS12LIM	 BUFFER[1794]	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define idiEM_TERB2SS12LIM	 517	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define iEM_TERB2SS21LIM	 BUFFER[1797]	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define idiEM_TERB2SS21LIM	 518	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define iEM_TERR3SS11LIM	 BUFFER[1800]	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define idiEM_TERR3SS11LIM	 519	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define iEM_TERB2SC01RIM	 BUFFER[1803]	//(TERB2SC01RIM) Искажение: Координата штока РБ2
#define idiEM_TERB2SC01RIM	 520	//(TERB2SC01RIM) Искажение: Координата штока РБ2
#define iEM_TERR3SS21LIM	 BUFFER[1806]	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define idiEM_TERR3SS21LIM	 521	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define iEM_TERR5SS11LIM	 BUFFER[1809]	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define idiEM_TERR5SS11LIM	 522	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define iEM_TERA4SS11LIM	 BUFFER[1812]	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define idiEM_TERA4SS11LIM	 523	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define iEM_TERR1SS11LIM	 BUFFER[1815]	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define idiEM_TERR1SS11LIM	 524	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define iEM_TERR1SS21LIM	 BUFFER[1818]	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define idiEM_TERR1SS21LIM	 525	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define iEM_TERR2SS11LIM	 BUFFER[1821]	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define idiEM_TERR2SS11LIM	 526	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define iEM_TERR2SS21LIM	 BUFFER[1824]	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define idiEM_TERR2SS21LIM	 527	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define iEM_TERA4VP82LIM	 BUFFER[1827]	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define idiEM_TERA4VP82LIM	 528	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define iEM_TERB4SS21LIM	 BUFFER[1830]	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define idiEM_TERB4SS21LIM	 529	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define iEM_TERR5SS21LIM	 BUFFER[1833]	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define idiEM_TERR5SS21LIM	 530	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define iEM_TERB6SS21LIM	 BUFFER[1836]	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define idiEM_TERB6SS21LIM	 531	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define iEM_TERB4SS11LIM	 BUFFER[1839]	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define idiEM_TERB4SS11LIM	 532	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define iEM_TERA4SS21LIM	 BUFFER[1842]	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define idiEM_TERA4SS21LIM	 533	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define iEM_TERA6MS11LIM	 BUFFER[1845]	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define idiEM_TERA6MS11LIM	 534	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define iEM_TERA6SS21LIM	 BUFFER[1848]	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define idiEM_TERA6SS21LIM	 535	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define iEM_TERB6SS11LIM	 BUFFER[1851]	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define idiEM_TERB6SS11LIM	 536	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define iEM_TERR4SS11LIM	 BUFFER[1854]	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define idiEM_TERR4SS11LIM	 537	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define iEM_TERR4MS21LIM	 BUFFER[1857]	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
#define idiEM_TERR4MS21LIM	 538	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
#define iEM_TERR4SS12LIM	 BUFFER[1860]	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define idiEM_TERR4SS12LIM	 539	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define iEM_TERR4SS22LIM	 BUFFER[1863]	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define idiEM_TERR4SS22LIM	 540	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define iEM_TERR8SS11LIM	 BUFFER[1866]	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define idiEM_TERR8SS11LIM	 541	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define iEM_TERB8SC01RIM	 BUFFER[1869]	//(TERB8SC01RIM) Искажение: Координата АЗ2
#define idiEM_TERB8SC01RIM	 542	//(TERB8SC01RIM) Искажение: Координата АЗ2
#define iEM_TERA8SC01RIM	 BUFFER[1872]	//(TERA8SC01RIM) Искажение: Координата ДС2
#define idiEM_TERA8SC01RIM	 543	//(TERA8SC01RIM) Искажение: Координата ДС2
#define iEM_TERB8SS12LIM	 BUFFER[1875]	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define idiEM_TERB8SS12LIM	 544	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define iEM_TERA8SS12LIM	 BUFFER[1878]	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define idiEM_TERA8SS12LIM	 545	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define iEM_TERB8SS22LIM	 BUFFER[1881]	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define idiEM_TERB8SS22LIM	 546	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define iEM_TERA8SS22LIM	 BUFFER[1884]	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define idiEM_TERA8SS22LIM	 547	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define iEM_TERA9SS21LIM	 BUFFER[1887]	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define idiEM_TERA9SS21LIM	 548	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define iEM_TERB9SS21LIM	 BUFFER[1890]	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define idiEM_TERB9SS21LIM	 549	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define iEM_TERB9SS11LIM	 BUFFER[1893]	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define idiEM_TERB9SS11LIM	 550	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define iEM_TERB5SS21LIM	 BUFFER[1896]	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define idiEM_TERB5SS21LIM	 551	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define iEM_TERA1SS21LIM	 BUFFER[1899]	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define idiEM_TERA1SS21LIM	 552	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define iEM_TERA1SS11LIM	 BUFFER[1902]	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define idiEM_TERA1SS11LIM	 553	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define iEM_TERA1SC01RIM	 BUFFER[1905]	//(TERA1SC01RIM) Искажение: Координата штока ББ1
#define idiEM_TERA1SC01RIM	 554	//(TERA1SC01RIM) Искажение: Координата штока ББ1
#define iEM_TERA1SS12LIM	 BUFFER[1908]	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define idiEM_TERA1SS12LIM	 555	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define iEM_TERB1SS21LIM	 BUFFER[1911]	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define idiEM_TERB1SS21LIM	 556	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define iEM_TERB1SS11LIM	 BUFFER[1914]	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define idiEM_TERB1SS11LIM	 557	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define iEM_TERB1MC01RIM	 BUFFER[1917]	//(TERB1MC01RIM) Искажение: Координата штока ББ2
#define idiEM_TERB1MC01RIM	 558	//(TERB1MC01RIM) Искажение: Координата штока ББ2
#define iEM_TERB1SS12LIM	 BUFFER[1920]	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define idiEM_TERB1SS12LIM	 559	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define iEM_TERTLG	 BUFFER[1923]	//(TERTLG) Неисправности  тележки от ИС
#define idiEM_TERTLG	 560	//(TERTLG) Неисправности  тележки от ИС
#define fEM_R4MC01RC1	 BUFFER[1926]	//(R4MC01RC1) Заданная координата тележки от ИС
#define idfEM_R4MC01RC1	 561	//(R4MC01RC1) Заданная координата тележки от ИС
#define fEM_R4MV01RC1	 BUFFER[1931]	//(R4MV01RC1) Заданная скорость тележки от ИС
#define idfEM_R4MV01RC1	 562	//(R4MV01RC1) Заданная скорость тележки от ИС
#define iEM_TERMAZ2	 BUFFER[1936]	//(TERMAZ2) Неисправности АЗ2 от ИС
#define idiEM_TERMAZ2	 563	//(TERMAZ2) Неисправности АЗ2 от ИС
#define fEM_B8MC01RC1	 BUFFER[1939]	//(B8MC01RC1) Заданная координата АЗ2 от ИС
#define idfEM_B8MC01RC1	 564	//(B8MC01RC1) Заданная координата АЗ2 от ИС
#define fEM_B8MV01RC1	 BUFFER[1944]	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
#define idfEM_B8MV01RC1	 565	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
#define iEM_TERDS2	 BUFFER[1949]	//(TERDS2) Неисправности ДС2 от ИС
#define idiEM_TERDS2	 566	//(TERDS2) Неисправности ДС2 от ИС
#define fEM_A8MC01RC1	 BUFFER[1952]	//(A8MC01RC1) Заданная координата ДС2 от ИС
#define idfEM_A8MC01RC1	 567	//(A8MC01RC1) Заданная координата ДС2 от ИС
#define fEM_A8MV01RC1	 BUFFER[1957]	//(A8MV01RC1) Заданная скорость ДС2 от ИС
#define idfEM_A8MV01RC1	 568	//(A8MV01RC1) Заданная скорость ДС2 от ИС
#define iEM_TERBZ1	 BUFFER[1962]	//(TERBZ1) Неисправности БЗ1
#define idiEM_TERBZ1	 569	//(TERBZ1) Неисправности БЗ1
#define fEM_A6MC01RC1	 BUFFER[1965]	//(A6MC01RC1) Заданная координата БЗ1 от ИС
#define idfEM_A6MC01RC1	 570	//(A6MC01RC1) Заданная координата БЗ1 от ИС
#define fEM_A6MV01RC1	 BUFFER[1970]	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
#define idfEM_A6MV01RC1	 571	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
#define iEM_TERBZ2	 BUFFER[1975]	//(TERBZ2) Неисправности БЗ2
#define idiEM_TERBZ2	 572	//(TERBZ2) Неисправности БЗ2
#define fEM_B6MC01RC1	 BUFFER[1978]	//(B6MC01RC1) Заданная координата БЗ2 от ИС
#define idfEM_B6MC01RC1	 573	//(B6MC01RC1) Заданная координата БЗ2 от ИС
#define fEM_B6MV01RC1	 BUFFER[1983]	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
#define idfEM_B6MV01RC1	 574	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
#define lEM_R3AD10LC1	 BUFFER[1988]	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define idlEM_R3AD10LC1	 575	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define lEM_R3AD20LC1	 BUFFER[1990]	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define idlEM_R3AD20LC1	 576	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define lEM_R6AD10LC1	 BUFFER[1992]	//(R6AD10LC1) Выкатить кран-балку от ИС
#define idlEM_R6AD10LC1	 577	//(R6AD10LC1) Выкатить кран-балку от ИС
#define lEM_R5AD10LC1	 BUFFER[1994]	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define idlEM_R5AD10LC1	 578	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define lEM_R5AD20LC1	 BUFFER[1996]	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define idlEM_R5AD20LC1	 579	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define iEM_TERMDZ2	 BUFFER[1998]	//(TERMDZ2) Неисправности МДЗ2
#define idiEM_TERMDZ2	 580	//(TERMDZ2) Неисправности МДЗ2
#define fEM_R2MC01RC1	 BUFFER[2001]	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
#define idfEM_R2MC01RC1	 581	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
#define fEM_R2MV01RC1	 BUFFER[2006]	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define idfEM_R2MV01RC1	 582	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define iEM_TERMDZ1	 BUFFER[2011]	//(TERMDZ1) Неисправности МДЗ1
#define idiEM_TERMDZ1	 583	//(TERMDZ1) Неисправности МДЗ1
#define fEM_R1MC01RC1	 BUFFER[2014]	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
#define idfEM_R1MC01RC1	 584	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
#define fEM_R1MV01RC1	 BUFFER[2019]	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define idfEM_R1MV01RC1	 585	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define iEM_TERNL1	 BUFFER[2024]	//(TERNL1) Неисправности НЛ1
#define idiEM_TERNL1	 586	//(TERNL1) Неисправности НЛ1
#define fEM_A5MC01RC1	 BUFFER[2027]	//(A5MC01RC1) Заданная координата НЛ1 от ИС
#define idfEM_A5MC01RC1	 587	//(A5MC01RC1) Заданная координата НЛ1 от ИС
#define fEM_A5MV01RC1	 BUFFER[2032]	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
#define idfEM_A5MV01RC1	 588	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
#define iEM_TERNL2	 BUFFER[2037]	//(TERNL2) Неисправности НЛ2
#define idiEM_TERNL2	 589	//(TERNL2) Неисправности НЛ2
#define fEM_B5MC01RC1	 BUFFER[2040]	//(B5MC01RC1) Заданная координата НЛ2 от ИС
#define idfEM_B5MC01RC1	 590	//(B5MC01RC1) Заданная координата НЛ2 от ИС
#define fEM_B5MV01RC1	 BUFFER[2045]	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
#define idfEM_B5MV01RC1	 591	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
#define lEM_R8AD10LC1	 BUFFER[2050]	//(R8AD10LC1) Установить аварийный НИ от ИС
#define idlEM_R8AD10LC1	 592	//(R8AD10LC1) Установить аварийный НИ от ИС
#define fEM_A1UC08RIM	 BUFFER[2052]	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define idfEM_A1UC08RIM	 593	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define fEM_A2UC08RIM	 BUFFER[2057]	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
#define idfEM_A2UC08RIM	 594	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
#define fEM_A3UC08RIM	 BUFFER[2062]	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define idfEM_A3UC08RIM	 595	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define iEM_TERB2SS33LIM	 BUFFER[2067]	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define idiEM_TERB2SS33LIM	 596	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define iEM_TERA1VP81LIM	 BUFFER[2070]	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define idiEM_TERA1VP81LIM	 597	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define iEM_TERB1VP81LIM	 BUFFER[2073]	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define idiEM_TERB1VP81LIM	 598	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define fEM_A0UT03RSP	 BUFFER[2076]	//(A0UT03RSP) Стартовая  температура АЗ1 град
#define idfEM_A0UT03RSP	 599	//(A0UT03RSP) Стартовая  температура АЗ1 град
#define fEM_A0UR01RSP	 BUFFER[2081]	//(A0UR01RSP) Стартовая  реактивность АЗ1
#define idfEM_A0UR01RSP	 600	//(A0UR01RSP) Стартовая  реактивность АЗ1
#define fEM_A0UR02RSP	 BUFFER[2086]	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define idfEM_A0UR02RSP	 601	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define fEM_B0UT03RSP	 BUFFER[2091]	//(B0UT03RSP) Стартовая  температура АЗ2 град
#define idfEM_B0UT03RSP	 602	//(B0UT03RSP) Стартовая  температура АЗ2 град
#define fEM_A1MC01RSP	 BUFFER[2096]	//(A1MC01RSP) Стартовая координата  ББ1
#define idfEM_A1MC01RSP	 603	//(A1MC01RSP) Стартовая координата  ББ1
#define fEM_A1MC02RSP	 BUFFER[2101]	//(A1MC02RSP) Стартовая координата штока ББ1
#define idfEM_A1MC02RSP	 604	//(A1MC02RSP) Стартовая координата штока ББ1
#define fEM_B1MC01RSP	 BUFFER[2106]	//(B1MC01RSP) Стартовая координата  ББ2
#define idfEM_B1MC01RSP	 605	//(B1MC01RSP) Стартовая координата  ББ2
#define fEM_B1MC02RSP	 BUFFER[2111]	//(B1MC02RSP) Стартовая координата штока ББ2
#define idfEM_B1MC02RSP	 606	//(B1MC02RSP) Стартовая координата штока ББ2
#define fEM_A2MC01RC1	 BUFFER[2116]	//(A2MC01RC1) Заданная координата РБ1 от ИС
#define idfEM_A2MC01RC1	 607	//(A2MC01RC1) Заданная координата РБ1 от ИС
#define fEM_A2MV01RC1	 BUFFER[2121]	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define idfEM_A2MV01RC1	 608	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define fEM_A2MC01RSP	 BUFFER[2126]	//(A2MC01RSP) Стартовая координата  РБ1
#define idfEM_A2MC01RSP	 609	//(A2MC01RSP) Стартовая координата  РБ1
#define fEM_A2MC02RSP	 BUFFER[2131]	//(A2MC02RSP) Стартовая координата штока РБ1
#define idfEM_A2MC02RSP	 610	//(A2MC02RSP) Стартовая координата штока РБ1
#define fEM_B2MC01RSP	 BUFFER[2136]	//(B2MC01RSP) Стартовая координата  РБ2
#define idfEM_B2MC01RSP	 611	//(B2MC01RSP) Стартовая координата  РБ2
#define fEM_B2MC02RSP	 BUFFER[2141]	//(B2MC02RSP) Стартовая координата штока РБ2
#define idfEM_B2MC02RSP	 612	//(B2MC02RSP) Стартовая координата штока РБ2
#define fEM_A3MC01RSP	 BUFFER[2146]	//(A3MC01RSP) Стартовая координата  ИС1
#define idfEM_A3MC01RSP	 613	//(A3MC01RSP) Стартовая координата  ИС1
#define fEM_A3MC02RSP	 BUFFER[2151]	//(A3MC02RSP) Стартовая координата штока ИС1
#define idfEM_A3MC02RSP	 614	//(A3MC02RSP) Стартовая координата штока ИС1
#define fEM_B3MC01RSP	 BUFFER[2156]	//(B3MC01RSP) Стартовая координата  ИС2
#define idfEM_B3MC01RSP	 615	//(B3MC01RSP) Стартовая координата  ИС2
#define fEM_B3MC02RSP	 BUFFER[2161]	//(B3MC02RSP) Стартовая координата штока ИС2
#define idfEM_B3MC02RSP	 616	//(B3MC02RSP) Стартовая координата штока ИС2
#define fEM_B8MC01RSP	 BUFFER[2166]	//(B8MC01RSP) Стартовая координата АЗ2
#define idfEM_B8MC01RSP	 617	//(B8MC01RSP) Стартовая координата АЗ2
#define fEM_A8MC01RSP	 BUFFER[2171]	//(A8MC01RSP) Стартовая координата ДС2
#define idfEM_A8MC01RSP	 618	//(A8MC01RSP) Стартовая координата ДС2
#define fEM_A6MC01RSP	 BUFFER[2176]	//(A6MC01RSP) Стартовая координата БЗ1
#define idfEM_A6MC01RSP	 619	//(A6MC01RSP) Стартовая координата БЗ1
#define fEM_B6MC01RSP	 BUFFER[2181]	//(B6MC01RSP) Стартовая координата БЗ2
#define idfEM_B6MC01RSP	 620	//(B6MC01RSP) Стартовая координата БЗ2
#define fEM_R3UC01RSP	 BUFFER[2186]	//(R3UC01RSP) Стартовая координата Гомогенных дверей
#define idfEM_R3UC01RSP	 621	//(R3UC01RSP) Стартовая координата Гомогенных дверей
#define fEM_R5UC01RSP	 BUFFER[2191]	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define idfEM_R5UC01RSP	 622	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define fEM_R6UC01RSP	 BUFFER[2196]	//(R6UC01RSP) Стартовая координата Кран-балки
#define idfEM_R6UC01RSP	 623	//(R6UC01RSP) Стартовая координата Кран-балки
#define fEM_R2MC01RSP	 BUFFER[2201]	//(R2MC01RSP) Стартовая координата МДЗ2
#define idfEM_R2MC01RSP	 624	//(R2MC01RSP) Стартовая координата МДЗ2
#define fEM_R1MC01RSP	 BUFFER[2206]	//(R1MC01RSP) Стартовая координата МДЗ1
#define idfEM_R1MC01RSP	 625	//(R1MC01RSP) Стартовая координата МДЗ1
#define fEM_A5MC01RSP	 BUFFER[2211]	//(A5MC01RSP) Стартовая координата НЛ1
#define idfEM_A5MC01RSP	 626	//(A5MC01RSP) Стартовая координата НЛ1
#define fEM_B5MC01RSP	 BUFFER[2216]	//(B5MC01RSP) Стартовая координата НЛ2
#define idfEM_B5MC01RSP	 627	//(B5MC01RSP) Стартовая координата НЛ2
#define fEM_A9MC01RSP	 BUFFER[2221]	//(A9MC01RSP) Стартовая координата НИ ДС1
#define idfEM_A9MC01RSP	 628	//(A9MC01RSP) Стартовая координата НИ ДС1
#define fEM_B9MC01RSP	 BUFFER[2226]	//(B9MC01RSP) Стартовая координата НИ ДС2
#define idfEM_B9MC01RSP	 629	//(B9MC01RSP) Стартовая координата НИ ДС2
#define fEM_A4MC01RSP	 BUFFER[2231]	//(A4MC01RSP) Стартовая координата НИ1
#define idfEM_A4MC01RSP	 630	//(A4MC01RSP) Стартовая координата НИ1
#define fEM_B4MC01RSP	 BUFFER[2236]	//(B4MC01RSP) Стартовая координата НИ2
#define idfEM_B4MC01RSP	 631	//(B4MC01RSP) Стартовая координата НИ2
#define fEM_R4MC01RSP	 BUFFER[2241]	//(R4MC01RSP) Стартовая координата тележки
#define idfEM_R4MC01RSP	 632	//(R4MC01RSP) Стартовая координата тележки
#define fEM_A1MV01RC1	 BUFFER[2246]	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define idfEM_A1MV01RC1	 633	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define iEM_TERB7MS31LIM	 BUFFER[2251]	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define idiEM_TERB7MS31LIM	 634	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define iEM_TERA7MS31LIM	 BUFFER[2254]	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define idiEM_TERA7MS31LIM	 635	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define fEM_R7UY00RSS	 BUFFER[2257]	//(R7UY00RSS) Y-координата АЗ1 см
#define idfEM_R7UY00RSS	 636	//(R7UY00RSS) Y-координата АЗ1 см
#define iEM_TERA6VS12LIM	 BUFFER[2262]	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define idiEM_TERA6VS12LIM	 637	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define iEM_TERA6VS22LIM	 BUFFER[2265]	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define idiEM_TERA6VS22LIM	 638	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define iEM_TERB6VS12LIM	 BUFFER[2268]	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define idiEM_TERB6VS12LIM	 639	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define iEM_TERB6VS22LIM	 BUFFER[2271]	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define idiEM_TERB6VS22LIM	 640	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define iEM_TERA5VS22LIM	 BUFFER[2274]	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define idiEM_TERA5VS22LIM	 641	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define iEM_TERA5VS12LIM	 BUFFER[2277]	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define idiEM_TERA5VS12LIM	 642	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define iEM_TERB5VS12LIM	 BUFFER[2280]	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define idiEM_TERB5VS12LIM	 643	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define iEM_TERB5VS22LIM	 BUFFER[2283]	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define idiEM_TERB5VS22LIM	 644	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define iEM_TERR1VS12LIM	 BUFFER[2286]	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define idiEM_TERR1VS12LIM	 645	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define iEM_TERR1VS22LIM	 BUFFER[2289]	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define idiEM_TERR1VS22LIM	 646	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define iEM_TERR2VS12LIM	 BUFFER[2292]	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define idiEM_TERR2VS12LIM	 647	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define iEM_TERR2VS22LIM	 BUFFER[2295]	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define idiEM_TERR2VS22LIM	 648	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define iEM_TERR4VS12LDU	 BUFFER[2298]	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS12LDU	 649	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define iEM_TERR4VS22LDU	 BUFFER[2301]	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS22LDU	 650	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define fEM_R4UC23RIM	 BUFFER[2304]	//(R4UC23RIM) Y-координата АЗ1
#define idfEM_R4UC23RIM	 651	//(R4UC23RIM) Y-координата АЗ1
#define fEM_A0UX13RSS	 BUFFER[2309]	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define idfEM_A0UX13RSS	 652	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define fEM_A0UX14RSS	 BUFFER[2314]	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define idfEM_A0UX14RSS	 653	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define fEM_A0UX15RSS	 BUFFER[2319]	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define idfEM_A0UX15RSS	 654	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define fEM_R7UX13RSS	 BUFFER[2324]	//(R7UX13RSS) X-координата камеры R7IN51
#define idfEM_R7UX13RSS	 655	//(R7UX13RSS) X-координата камеры R7IN51
#define fEM_R7UX14RSS	 BUFFER[2329]	//(R7UX14RSS) X-координата камеры R7IN52
#define idfEM_R7UX14RSS	 656	//(R7UX14RSS) X-координата камеры R7IN52
#define fEM_R7UX15RSS	 BUFFER[2334]	//(R7UX15RSS) X-координата камеры R7IN53
#define idfEM_R7UX15RSS	 657	//(R7UX15RSS) X-координата камеры R7IN53
#define fEM_R7UY13RSS	 BUFFER[2339]	//(R7UY13RSS) Y-координата камеры R7IN51
#define idfEM_R7UY13RSS	 658	//(R7UY13RSS) Y-координата камеры R7IN51
#define fEM_R7UY14RSS	 BUFFER[2344]	//(R7UY14RSS) Y-координата камеры R7IN52
#define idfEM_R7UY14RSS	 659	//(R7UY14RSS) Y-координата камеры R7IN52
#define fEM_R7UY15RSS	 BUFFER[2349]	//(R7UY15RSS) Y-координата камеры R7IN53
#define idfEM_R7UY15RSS	 660	//(R7UY15RSS) Y-координата камеры R7IN53
#define fEM_R7UX16RSS	 BUFFER[2354]	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
#define idfEM_R7UX16RSS	 661	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
#define bFirstEnterFlag	 BUFFER[2359]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 662	//(bFirstEnterFlag) 
#define internal1_m872_Chim0	 BUFFER[2361]	//(internal1_m872_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m872_Chim0	 663	//(internal1_m872_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m862_Chim0	 BUFFER[2366]	//(internal1_m862_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m862_Chim0	 664	//(internal1_m862_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m854_Chim0	 BUFFER[2371]	//(internal1_m854_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m854_Chim0	 665	//(internal1_m854_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m809_Out10	 BUFFER[2376]	//(internal1_m809_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m809_Out10	 666	//(internal1_m809_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m808_Out10	 BUFFER[2378]	//(internal1_m808_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m808_Out10	 667	//(internal1_m808_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m991_Out10	 BUFFER[2380]	//(internal1_m991_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m991_Out10	 668	//(internal1_m991_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m990_Out10	 BUFFER[2382]	//(internal1_m990_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m990_Out10	 669	//(internal1_m990_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m989_Out10	 BUFFER[2384]	//(internal1_m989_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m989_Out10	 670	//(internal1_m989_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m988_Out10	 BUFFER[2386]	//(internal1_m988_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m988_Out10	 671	//(internal1_m988_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m668_Out10	 BUFFER[2388]	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m668_Out10	 672	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m667_Out10	 BUFFER[2390]	//(internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m667_Out10	 673	//(internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m646_Out10	 BUFFER[2392]	//(internal1_m646_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m646_Out10	 674	//(internal1_m646_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m645_Out10	 BUFFER[2394]	//(internal1_m645_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m645_Out10	 675	//(internal1_m645_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m666_Out10	 BUFFER[2396]	//(internal1_m666_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m666_Out10	 676	//(internal1_m666_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m665_Out10	 BUFFER[2398]	//(internal1_m665_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m665_Out10	 677	//(internal1_m665_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m644_Out10	 BUFFER[2400]	//(internal1_m644_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m644_Out10	 678	//(internal1_m644_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m643_Out10	 BUFFER[2402]	//(internal1_m643_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m643_Out10	 679	//(internal1_m643_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m510_Out10	 BUFFER[2404]	//(internal1_m510_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m510_Out10	 680	//(internal1_m510_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m526_Out10	 BUFFER[2406]	//(internal1_m526_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m526_Out10	 681	//(internal1_m526_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m398_Out10	 BUFFER[2408]	//(internal1_m398_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m398_Out10	 682	//(internal1_m398_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m471_q0	 BUFFER[2410]	//(internal1_m471_q0) q0 - внутренний параметр
#define idinternal1_m471_q0	 683	//(internal1_m471_q0) q0 - внутренний параметр
#define internal1_m472_q0	 BUFFER[2412]	//(internal1_m472_q0) q0 - внутренний параметр
#define idinternal1_m472_q0	 684	//(internal1_m472_q0) q0 - внутренний параметр
#define internal1_m459_q0	 BUFFER[2414]	//(internal1_m459_q0) q0 - внутренний параметр
#define idinternal1_m459_q0	 685	//(internal1_m459_q0) q0 - внутренний параметр
#define internal1_m460_q0	 BUFFER[2416]	//(internal1_m460_q0) q0 - внутренний параметр
#define idinternal1_m460_q0	 686	//(internal1_m460_q0) q0 - внутренний параметр
#define internal1_m619_tx	 BUFFER[2418]	//(internal1_m619_tx) tx - время накопленное сек
#define idinternal1_m619_tx	 687	//(internal1_m619_tx) tx - время накопленное сек
#define internal1_m619_y0	 BUFFER[2423]	//(internal1_m619_y0) y0
#define idinternal1_m619_y0	 688	//(internal1_m619_y0) y0
#define internal1_m607_tx	 BUFFER[2424]	//(internal1_m607_tx) tx - время накопленное сек
#define idinternal1_m607_tx	 689	//(internal1_m607_tx) tx - время накопленное сек
#define internal1_m607_y0	 BUFFER[2429]	//(internal1_m607_y0) y0
#define idinternal1_m607_y0	 690	//(internal1_m607_y0) y0
#define internal1_m595_tx	 BUFFER[2430]	//(internal1_m595_tx) tx - время накопленное сек
#define idinternal1_m595_tx	 691	//(internal1_m595_tx) tx - время накопленное сек
#define internal1_m595_y0	 BUFFER[2435]	//(internal1_m595_y0) y0
#define idinternal1_m595_y0	 692	//(internal1_m595_y0) y0
#define internal1_m593_tx	 BUFFER[2436]	//(internal1_m593_tx) tx - время накопленное сек
#define idinternal1_m593_tx	 693	//(internal1_m593_tx) tx - время накопленное сек
#define internal1_m593_y0	 BUFFER[2441]	//(internal1_m593_y0) y0
#define idinternal1_m593_y0	 694	//(internal1_m593_y0) y0
#define internal1_m203_Out10	 BUFFER[2442]	//(internal1_m203_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m203_Out10	 695	//(internal1_m203_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m221_Out10	 BUFFER[2444]	//(internal1_m221_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m221_Out10	 696	//(internal1_m221_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m41_Out10	 BUFFER[2446]	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m41_Out10	 697	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m56_Out10	 BUFFER[2448]	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m56_Out10	 698	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m962_Out10	 BUFFER[2450]	//(internal1_m962_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m962_Out10	 699	//(internal1_m962_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m959_Out10	 BUFFER[2452]	//(internal1_m959_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m959_Out10	 700	//(internal1_m959_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m958_Out10	 BUFFER[2454]	//(internal1_m958_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m958_Out10	 701	//(internal1_m958_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m961_Xtek0	 BUFFER[2456]	//(internal1_m961_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m961_Xtek0	 702	//(internal1_m961_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m944_Xtek0	 BUFFER[2461]	//(internal1_m944_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m944_Xtek0	 703	//(internal1_m944_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m945_Out10	 BUFFER[2466]	//(internal1_m945_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m945_Out10	 704	//(internal1_m945_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m942_Out10	 BUFFER[2468]	//(internal1_m942_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m942_Out10	 705	//(internal1_m942_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m941_Out10	 BUFFER[2470]	//(internal1_m941_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m941_Out10	 706	//(internal1_m941_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1029_Out10	 BUFFER[2472]	//(internal1_m1029_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1029_Out10	 707	//(internal1_m1029_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1010_Out10	 BUFFER[2474]	//(internal1_m1010_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1010_Out10	 708	//(internal1_m1010_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1009_Out10	 BUFFER[2476]	//(internal1_m1009_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1009_Out10	 709	//(internal1_m1009_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1008_Out10	 BUFFER[2478]	//(internal1_m1008_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1008_Out10	 710	//(internal1_m1008_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m830_Out10	 BUFFER[2480]	//(internal1_m830_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m830_Out10	 711	//(internal1_m830_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m832_Out10	 BUFFER[2482]	//(internal1_m832_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m832_Out10	 712	//(internal1_m832_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m829_Out10	 BUFFER[2484]	//(internal1_m829_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m829_Out10	 713	//(internal1_m829_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m831_Out10	 BUFFER[2486]	//(internal1_m831_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m831_Out10	 714	//(internal1_m831_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m805_Out10	 BUFFER[2488]	//(internal1_m805_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m805_Out10	 715	//(internal1_m805_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m806_Out10	 BUFFER[2490]	//(internal1_m806_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m806_Out10	 716	//(internal1_m806_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m804_Out10	 BUFFER[2492]	//(internal1_m804_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m804_Out10	 717	//(internal1_m804_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m803_Out10	 BUFFER[2494]	//(internal1_m803_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m803_Out10	 718	//(internal1_m803_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1024_Out10	 BUFFER[2496]	//(internal1_m1024_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1024_Out10	 719	//(internal1_m1024_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m976_Out10	 BUFFER[2498]	//(internal1_m976_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m976_Out10	 720	//(internal1_m976_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m975_Out10	 BUFFER[2500]	//(internal1_m975_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m975_Out10	 721	//(internal1_m975_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m974_Out10	 BUFFER[2502]	//(internal1_m974_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m974_Out10	 722	//(internal1_m974_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m973_Out10	 BUFFER[2504]	//(internal1_m973_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m973_Out10	 723	//(internal1_m973_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1025_Out10	 BUFFER[2506]	//(internal1_m1025_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1025_Out10	 724	//(internal1_m1025_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1006_Out10	 BUFFER[2508]	//(internal1_m1006_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1006_Out10	 725	//(internal1_m1006_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m807_Out10	 BUFFER[2510]	//(internal1_m807_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m807_Out10	 726	//(internal1_m807_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1007_Out10	 BUFFER[2512]	//(internal1_m1007_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1007_Out10	 727	//(internal1_m1007_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1005_Out10	 BUFFER[2514]	//(internal1_m1005_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1005_Out10	 728	//(internal1_m1005_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1026_Out10	 BUFFER[2516]	//(internal1_m1026_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1026_Out10	 729	//(internal1_m1026_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1004_Out10	 BUFFER[2518]	//(internal1_m1004_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1004_Out10	 730	//(internal1_m1004_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m987_Out10	 BUFFER[2520]	//(internal1_m987_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m987_Out10	 731	//(internal1_m987_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m972_Out10	 BUFFER[2522]	//(internal1_m972_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m972_Out10	 732	//(internal1_m972_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m527_Out10	 BUFFER[2524]	//(internal1_m527_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m527_Out10	 733	//(internal1_m527_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m408_Xtek0	 BUFFER[2526]	//(internal1_m408_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m408_Xtek0	 734	//(internal1_m408_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m399_Out10	 BUFFER[2531]	//(internal1_m399_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m399_Out10	 735	//(internal1_m399_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m401_Out10	 BUFFER[2533]	//(internal1_m401_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m401_Out10	 736	//(internal1_m401_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m400_Out10	 BUFFER[2535]	//(internal1_m400_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m400_Out10	 737	//(internal1_m400_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m845_Out10	 BUFFER[2537]	//(internal1_m845_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m845_Out10	 738	//(internal1_m845_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m846_Out10	 BUFFER[2539]	//(internal1_m846_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m846_Out10	 739	//(internal1_m846_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m844_Out10	 BUFFER[2541]	//(internal1_m844_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m844_Out10	 740	//(internal1_m844_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1028_Out10	 BUFFER[2543]	//(internal1_m1028_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1028_Out10	 741	//(internal1_m1028_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m681_Out10	 BUFFER[2545]	//(internal1_m681_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m681_Out10	 742	//(internal1_m681_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m682_Out10	 BUFFER[2547]	//(internal1_m682_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m682_Out10	 743	//(internal1_m682_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m679_Out10	 BUFFER[2549]	//(internal1_m679_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m679_Out10	 744	//(internal1_m679_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m680_Out10	 BUFFER[2551]	//(internal1_m680_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m680_Out10	 745	//(internal1_m680_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m543_Out10	 BUFFER[2553]	//(internal1_m543_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m543_Out10	 746	//(internal1_m543_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m542_Out10	 BUFFER[2555]	//(internal1_m542_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m542_Out10	 747	//(internal1_m542_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m826_Xtek0	 BUFFER[2557]	//(internal1_m826_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m826_Xtek0	 748	//(internal1_m826_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m828_Xtek0	 BUFFER[2562]	//(internal1_m828_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m828_Xtek0	 749	//(internal1_m828_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m678_Out10	 BUFFER[2567]	//(internal1_m678_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m678_Out10	 750	//(internal1_m678_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m662_Out10	 BUFFER[2569]	//(internal1_m662_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m662_Out10	 751	//(internal1_m662_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m642_Out10	 BUFFER[2571]	//(internal1_m642_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m642_Out10	 752	//(internal1_m642_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m661_Out10	 BUFFER[2573]	//(internal1_m661_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m661_Out10	 753	//(internal1_m661_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m641_Out10	 BUFFER[2575]	//(internal1_m641_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m641_Out10	 754	//(internal1_m641_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m329_Out10	 BUFFER[2577]	//(internal1_m329_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m329_Out10	 755	//(internal1_m329_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m328_Out10	 BUFFER[2579]	//(internal1_m328_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m328_Out10	 756	//(internal1_m328_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m313_Out10	 BUFFER[2581]	//(internal1_m313_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m313_Out10	 757	//(internal1_m313_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m312_Out10	 BUFFER[2583]	//(internal1_m312_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m312_Out10	 758	//(internal1_m312_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m544_Out10	 BUFFER[2585]	//(internal1_m544_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m544_Out10	 759	//(internal1_m544_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m342_Out10	 BUFFER[2587]	//(internal1_m342_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m342_Out10	 760	//(internal1_m342_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m326_Xtek0	 BUFFER[2589]	//(internal1_m326_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m326_Xtek0	 761	//(internal1_m326_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m341_Out10	 BUFFER[2594]	//(internal1_m341_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m341_Out10	 762	//(internal1_m341_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m339_Out10	 BUFFER[2596]	//(internal1_m339_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m339_Out10	 763	//(internal1_m339_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m319_Xtek0	 BUFFER[2598]	//(internal1_m319_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m319_Xtek0	 764	//(internal1_m319_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m340_Out10	 BUFFER[2603]	//(internal1_m340_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m340_Out10	 765	//(internal1_m340_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m311_Out10	 BUFFER[2605]	//(internal1_m311_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m311_Out10	 766	//(internal1_m311_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m327_Out10	 BUFFER[2607]	//(internal1_m327_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m327_Out10	 767	//(internal1_m327_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m420_Out10	 BUFFER[2609]	//(internal1_m420_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m420_Out10	 768	//(internal1_m420_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m421_Xtek0	 BUFFER[2611]	//(internal1_m421_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m421_Xtek0	 769	//(internal1_m421_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m419_Out10	 BUFFER[2616]	//(internal1_m419_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m419_Out10	 770	//(internal1_m419_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m418_Out10	 BUFFER[2618]	//(internal1_m418_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m418_Out10	 771	//(internal1_m418_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m417_Out10	 BUFFER[2620]	//(internal1_m417_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m417_Out10	 772	//(internal1_m417_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1027_Out10	 BUFFER[2622]	//(internal1_m1027_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1027_Out10	 773	//(internal1_m1027_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m145_Out10	 BUFFER[2624]	//(internal1_m145_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m145_Out10	 774	//(internal1_m145_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m144_Out10	 BUFFER[2626]	//(internal1_m144_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m144_Out10	 775	//(internal1_m144_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m192_tx	 BUFFER[2628]	//(internal1_m192_tx) tx - внутренний параметр
#define idinternal1_m192_tx	 776	//(internal1_m192_tx) tx - внутренний параметр
#define internal1_m25_tx	 BUFFER[2631]	//(internal1_m25_tx) tx - внутренний параметр
#define idinternal1_m25_tx	 777	//(internal1_m25_tx) tx - внутренний параметр
#define internal1_m465_X00	 BUFFER[2634]	//(internal1_m465_X00)  X00 - текущая координата механизма
#define idinternal1_m465_X00	 778	//(internal1_m465_X00)  X00 - текущая координата механизма
#define internal1_m465_V00	 BUFFER[2639]	//(internal1_m465_V00)  V00 - текущая скорость механизма
#define idinternal1_m465_V00	 779	//(internal1_m465_V00)  V00 - текущая скорость механизма
#define internal1_m465_Pav0	 BUFFER[2644]	//(internal1_m465_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m465_Pav0	 780	//(internal1_m465_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m465_Zav0	 BUFFER[2646]	//(internal1_m465_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m465_Zav0	 781	//(internal1_m465_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m465_Pv0	 BUFFER[2648]	//(internal1_m465_Pv0)  - Пер. выключатель механизма
#define idinternal1_m465_Pv0	 782	//(internal1_m465_Pv0)  - Пер. выключатель механизма
#define internal1_m465_Zv0	 BUFFER[2650]	//(internal1_m465_Zv0)  - Зад. выключатель механизма
#define idinternal1_m465_Zv0	 783	//(internal1_m465_Zv0)  - Зад. выключатель механизма
#define internal1_m465_RA00	 BUFFER[2652]	//(internal1_m465_RA00)  - последнее задание вперед
#define idinternal1_m465_RA00	 784	//(internal1_m465_RA00)  - последнее задание вперед
#define internal1_m465_RA10	 BUFFER[2654]	//(internal1_m465_RA10)  - последнее задание назад
#define idinternal1_m465_RA10	 785	//(internal1_m465_RA10)  - последнее задание назад
#define internal1_m465_MyFirstEnterFlag	 BUFFER[2656]	//(internal1_m465_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m465_MyFirstEnterFlag	 786	//(internal1_m465_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m475_X00	 BUFFER[2658]	//(internal1_m475_X00)  X00 - текущая координата механизма
#define idinternal1_m475_X00	 787	//(internal1_m475_X00)  X00 - текущая координата механизма
#define internal1_m475_V00	 BUFFER[2663]	//(internal1_m475_V00)  V00 - текущая скорость механизма
#define idinternal1_m475_V00	 788	//(internal1_m475_V00)  V00 - текущая скорость механизма
#define internal1_m475_Pav0	 BUFFER[2668]	//(internal1_m475_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m475_Pav0	 789	//(internal1_m475_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m475_Zav0	 BUFFER[2670]	//(internal1_m475_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m475_Zav0	 790	//(internal1_m475_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m475_Pv0	 BUFFER[2672]	//(internal1_m475_Pv0)  - Пер. выключатель механизма
#define idinternal1_m475_Pv0	 791	//(internal1_m475_Pv0)  - Пер. выключатель механизма
#define internal1_m475_Zv0	 BUFFER[2674]	//(internal1_m475_Zv0)  - Зад. выключатель механизма
#define idinternal1_m475_Zv0	 792	//(internal1_m475_Zv0)  - Зад. выключатель механизма
#define internal1_m475_RA00	 BUFFER[2676]	//(internal1_m475_RA00)  - последнее задание вперед
#define idinternal1_m475_RA00	 793	//(internal1_m475_RA00)  - последнее задание вперед
#define internal1_m475_RA10	 BUFFER[2678]	//(internal1_m475_RA10)  - последнее задание назад
#define idinternal1_m475_RA10	 794	//(internal1_m475_RA10)  - последнее задание назад
#define internal1_m475_MyFirstEnterFlag	 BUFFER[2680]	//(internal1_m475_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m475_MyFirstEnterFlag	 795	//(internal1_m475_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m464_X00	 BUFFER[2682]	//(internal1_m464_X00)  X00 - текущая координата механизма
#define idinternal1_m464_X00	 796	//(internal1_m464_X00)  X00 - текущая координата механизма
#define internal1_m464_V00	 BUFFER[2687]	//(internal1_m464_V00)  V00 - текущая скорость механизма
#define idinternal1_m464_V00	 797	//(internal1_m464_V00)  V00 - текущая скорость механизма
#define internal1_m464_Pav0	 BUFFER[2692]	//(internal1_m464_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m464_Pav0	 798	//(internal1_m464_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m464_Zav0	 BUFFER[2694]	//(internal1_m464_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m464_Zav0	 799	//(internal1_m464_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m464_Pv0	 BUFFER[2696]	//(internal1_m464_Pv0)  - Пер. выключатель механизма
#define idinternal1_m464_Pv0	 800	//(internal1_m464_Pv0)  - Пер. выключатель механизма
#define internal1_m464_Zv0	 BUFFER[2698]	//(internal1_m464_Zv0)  - Зад. выключатель механизма
#define idinternal1_m464_Zv0	 801	//(internal1_m464_Zv0)  - Зад. выключатель механизма
#define internal1_m464_RA00	 BUFFER[2700]	//(internal1_m464_RA00)  - последнее задание вперед
#define idinternal1_m464_RA00	 802	//(internal1_m464_RA00)  - последнее задание вперед
#define internal1_m464_RA10	 BUFFER[2702]	//(internal1_m464_RA10)  - последнее задание назад
#define idinternal1_m464_RA10	 803	//(internal1_m464_RA10)  - последнее задание назад
#define internal1_m464_MyFirstEnterFlag	 BUFFER[2704]	//(internal1_m464_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m464_MyFirstEnterFlag	 804	//(internal1_m464_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m598_X00	 BUFFER[2706]	//(internal1_m598_X00)  X00 - текущая координата механизма
#define idinternal1_m598_X00	 805	//(internal1_m598_X00)  X00 - текущая координата механизма
#define internal1_m598_V00	 BUFFER[2711]	//(internal1_m598_V00)  V00 - текущая скорость механизма
#define idinternal1_m598_V00	 806	//(internal1_m598_V00)  V00 - текущая скорость механизма
#define internal1_m598_Pav0	 BUFFER[2716]	//(internal1_m598_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m598_Pav0	 807	//(internal1_m598_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m598_Zav0	 BUFFER[2718]	//(internal1_m598_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m598_Zav0	 808	//(internal1_m598_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m598_Pv0	 BUFFER[2720]	//(internal1_m598_Pv0)  - Пер. выключатель механизма
#define idinternal1_m598_Pv0	 809	//(internal1_m598_Pv0)  - Пер. выключатель механизма
#define internal1_m598_Zv0	 BUFFER[2722]	//(internal1_m598_Zv0)  - Зад. выключатель механизма
#define idinternal1_m598_Zv0	 810	//(internal1_m598_Zv0)  - Зад. выключатель механизма
#define internal1_m598_RA00	 BUFFER[2724]	//(internal1_m598_RA00)  - последнее задание вперед
#define idinternal1_m598_RA00	 811	//(internal1_m598_RA00)  - последнее задание вперед
#define internal1_m598_RA10	 BUFFER[2726]	//(internal1_m598_RA10)  - последнее задание назад
#define idinternal1_m598_RA10	 812	//(internal1_m598_RA10)  - последнее задание назад
#define internal1_m598_MyFirstEnterFlag	 BUFFER[2728]	//(internal1_m598_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m598_MyFirstEnterFlag	 813	//(internal1_m598_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m597_X00	 BUFFER[2730]	//(internal1_m597_X00)  X00 - текущая координата механизма
#define idinternal1_m597_X00	 814	//(internal1_m597_X00)  X00 - текущая координата механизма
#define internal1_m597_V00	 BUFFER[2735]	//(internal1_m597_V00)  V00 - текущая скорость механизма
#define idinternal1_m597_V00	 815	//(internal1_m597_V00)  V00 - текущая скорость механизма
#define internal1_m597_Pav0	 BUFFER[2740]	//(internal1_m597_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m597_Pav0	 816	//(internal1_m597_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m597_Zav0	 BUFFER[2742]	//(internal1_m597_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m597_Zav0	 817	//(internal1_m597_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m597_Pv0	 BUFFER[2744]	//(internal1_m597_Pv0)  - Пер. выключатель механизма
#define idinternal1_m597_Pv0	 818	//(internal1_m597_Pv0)  - Пер. выключатель механизма
#define internal1_m597_Zv0	 BUFFER[2746]	//(internal1_m597_Zv0)  - Зад. выключатель механизма
#define idinternal1_m597_Zv0	 819	//(internal1_m597_Zv0)  - Зад. выключатель механизма
#define internal1_m597_RA00	 BUFFER[2748]	//(internal1_m597_RA00)  - последнее задание вперед
#define idinternal1_m597_RA00	 820	//(internal1_m597_RA00)  - последнее задание вперед
#define internal1_m597_RA10	 BUFFER[2750]	//(internal1_m597_RA10)  - последнее задание назад
#define idinternal1_m597_RA10	 821	//(internal1_m597_RA10)  - последнее задание назад
#define internal1_m597_MyFirstEnterFlag	 BUFFER[2752]	//(internal1_m597_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m597_MyFirstEnterFlag	 822	//(internal1_m597_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m585_X00	 BUFFER[2754]	//(internal1_m585_X00)  X00 - текущая координата механизма
#define idinternal1_m585_X00	 823	//(internal1_m585_X00)  X00 - текущая координата механизма
#define internal1_m585_V00	 BUFFER[2759]	//(internal1_m585_V00)  V00 - текущая скорость механизма
#define idinternal1_m585_V00	 824	//(internal1_m585_V00)  V00 - текущая скорость механизма
#define internal1_m585_Pav0	 BUFFER[2764]	//(internal1_m585_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m585_Pav0	 825	//(internal1_m585_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m585_Zav0	 BUFFER[2766]	//(internal1_m585_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m585_Zav0	 826	//(internal1_m585_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m585_Pv0	 BUFFER[2768]	//(internal1_m585_Pv0)  - Пер. выключатель механизма
#define idinternal1_m585_Pv0	 827	//(internal1_m585_Pv0)  - Пер. выключатель механизма
#define internal1_m585_Zv0	 BUFFER[2770]	//(internal1_m585_Zv0)  - Зад. выключатель механизма
#define idinternal1_m585_Zv0	 828	//(internal1_m585_Zv0)  - Зад. выключатель механизма
#define internal1_m585_RA00	 BUFFER[2772]	//(internal1_m585_RA00)  - последнее задание вперед
#define idinternal1_m585_RA00	 829	//(internal1_m585_RA00)  - последнее задание вперед
#define internal1_m585_RA10	 BUFFER[2774]	//(internal1_m585_RA10)  - последнее задание назад
#define idinternal1_m585_RA10	 830	//(internal1_m585_RA10)  - последнее задание назад
#define internal1_m585_MyFirstEnterFlag	 BUFFER[2776]	//(internal1_m585_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m585_MyFirstEnterFlag	 831	//(internal1_m585_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m584_X00	 BUFFER[2778]	//(internal1_m584_X00)  X00 - текущая координата механизма
#define idinternal1_m584_X00	 832	//(internal1_m584_X00)  X00 - текущая координата механизма
#define internal1_m584_V00	 BUFFER[2783]	//(internal1_m584_V00)  V00 - текущая скорость механизма
#define idinternal1_m584_V00	 833	//(internal1_m584_V00)  V00 - текущая скорость механизма
#define internal1_m584_Pav0	 BUFFER[2788]	//(internal1_m584_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m584_Pav0	 834	//(internal1_m584_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m584_Zav0	 BUFFER[2790]	//(internal1_m584_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m584_Zav0	 835	//(internal1_m584_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m584_Pv0	 BUFFER[2792]	//(internal1_m584_Pv0)  - Пер. выключатель механизма
#define idinternal1_m584_Pv0	 836	//(internal1_m584_Pv0)  - Пер. выключатель механизма
#define internal1_m584_Zv0	 BUFFER[2794]	//(internal1_m584_Zv0)  - Зад. выключатель механизма
#define idinternal1_m584_Zv0	 837	//(internal1_m584_Zv0)  - Зад. выключатель механизма
#define internal1_m584_RA00	 BUFFER[2796]	//(internal1_m584_RA00)  - последнее задание вперед
#define idinternal1_m584_RA00	 838	//(internal1_m584_RA00)  - последнее задание вперед
#define internal1_m584_RA10	 BUFFER[2798]	//(internal1_m584_RA10)  - последнее задание назад
#define idinternal1_m584_RA10	 839	//(internal1_m584_RA10)  - последнее задание назад
#define internal1_m584_MyFirstEnterFlag	 BUFFER[2800]	//(internal1_m584_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m584_MyFirstEnterFlag	 840	//(internal1_m584_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m627_y0	 BUFFER[2802]	//(internal1_m627_y0) y0 - внутренний параметр
#define idinternal1_m627_y0	 841	//(internal1_m627_y0) y0 - внутренний параметр
#define internal1_m791_Chim0	 BUFFER[2807]	//(internal1_m791_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m791_Chim0	 842	//(internal1_m791_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m782_Chim0	 BUFFER[2812]	//(internal1_m782_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m782_Chim0	 843	//(internal1_m782_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m774_Chim0	 BUFFER[2817]	//(internal1_m774_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m774_Chim0	 844	//(internal1_m774_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m765_Chim0	 BUFFER[2822]	//(internal1_m765_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m765_Chim0	 845	//(internal1_m765_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m756_Chim0	 BUFFER[2827]	//(internal1_m756_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m756_Chim0	 846	//(internal1_m756_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m748_Chim0	 BUFFER[2832]	//(internal1_m748_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m748_Chim0	 847	//(internal1_m748_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m739_Chim0	 BUFFER[2837]	//(internal1_m739_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m739_Chim0	 848	//(internal1_m739_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m730_Chim0	 BUFFER[2842]	//(internal1_m730_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m730_Chim0	 849	//(internal1_m730_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m722_Chim0	 BUFFER[2847]	//(internal1_m722_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m722_Chim0	 850	//(internal1_m722_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m713_Chim0	 BUFFER[2852]	//(internal1_m713_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m713_Chim0	 851	//(internal1_m713_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m704_Chim0	 BUFFER[2857]	//(internal1_m704_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m704_Chim0	 852	//(internal1_m704_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m694_Chim0	 BUFFER[2862]	//(internal1_m694_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m694_Chim0	 853	//(internal1_m694_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m572_X00	 BUFFER[2867]	//(internal1_m572_X00)  X00 - текущая координата механизма
#define idinternal1_m572_X00	 854	//(internal1_m572_X00)  X00 - текущая координата механизма
#define internal1_m572_V00	 BUFFER[2872]	//(internal1_m572_V00)  V00 - текущая скорость механизма
#define idinternal1_m572_V00	 855	//(internal1_m572_V00)  V00 - текущая скорость механизма
#define internal1_m572_Pav0	 BUFFER[2877]	//(internal1_m572_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m572_Pav0	 856	//(internal1_m572_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m572_Zav0	 BUFFER[2879]	//(internal1_m572_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m572_Zav0	 857	//(internal1_m572_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m572_Pv0	 BUFFER[2881]	//(internal1_m572_Pv0)  - Пер. выключатель механизма
#define idinternal1_m572_Pv0	 858	//(internal1_m572_Pv0)  - Пер. выключатель механизма
#define internal1_m572_Zv0	 BUFFER[2883]	//(internal1_m572_Zv0)  - Зад. выключатель механизма
#define idinternal1_m572_Zv0	 859	//(internal1_m572_Zv0)  - Зад. выключатель механизма
#define internal1_m572_RA00	 BUFFER[2885]	//(internal1_m572_RA00)  - последнее задание вперед
#define idinternal1_m572_RA00	 860	//(internal1_m572_RA00)  - последнее задание вперед
#define internal1_m572_RA10	 BUFFER[2887]	//(internal1_m572_RA10)  - последнее задание назад
#define idinternal1_m572_RA10	 861	//(internal1_m572_RA10)  - последнее задание назад
#define internal1_m572_MyFirstEnterFlag	 BUFFER[2889]	//(internal1_m572_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m572_MyFirstEnterFlag	 862	//(internal1_m572_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m558_X00	 BUFFER[2891]	//(internal1_m558_X00)  X00 - текущая координата механизма
#define idinternal1_m558_X00	 863	//(internal1_m558_X00)  X00 - текущая координата механизма
#define internal1_m558_V00	 BUFFER[2896]	//(internal1_m558_V00)  V00 - текущая скорость механизма
#define idinternal1_m558_V00	 864	//(internal1_m558_V00)  V00 - текущая скорость механизма
#define internal1_m558_Pav0	 BUFFER[2901]	//(internal1_m558_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m558_Pav0	 865	//(internal1_m558_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m558_Zav0	 BUFFER[2903]	//(internal1_m558_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m558_Zav0	 866	//(internal1_m558_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m558_Pv0	 BUFFER[2905]	//(internal1_m558_Pv0)  - Пер. выключатель механизма
#define idinternal1_m558_Pv0	 867	//(internal1_m558_Pv0)  - Пер. выключатель механизма
#define internal1_m558_Zv0	 BUFFER[2907]	//(internal1_m558_Zv0)  - Зад. выключатель механизма
#define idinternal1_m558_Zv0	 868	//(internal1_m558_Zv0)  - Зад. выключатель механизма
#define internal1_m558_RA00	 BUFFER[2909]	//(internal1_m558_RA00)  - последнее задание вперед
#define idinternal1_m558_RA00	 869	//(internal1_m558_RA00)  - последнее задание вперед
#define internal1_m558_RA10	 BUFFER[2911]	//(internal1_m558_RA10)  - последнее задание назад
#define idinternal1_m558_RA10	 870	//(internal1_m558_RA10)  - последнее задание назад
#define internal1_m558_MyFirstEnterFlag	 BUFFER[2913]	//(internal1_m558_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m558_MyFirstEnterFlag	 871	//(internal1_m558_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m449_X00	 BUFFER[2915]	//(internal1_m449_X00)  X00 - текущая координата механизма
#define idinternal1_m449_X00	 872	//(internal1_m449_X00)  X00 - текущая координата механизма
#define internal1_m449_V00	 BUFFER[2920]	//(internal1_m449_V00)  V00 - текущая скорость механизма
#define idinternal1_m449_V00	 873	//(internal1_m449_V00)  V00 - текущая скорость механизма
#define internal1_m449_Pav0	 BUFFER[2925]	//(internal1_m449_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m449_Pav0	 874	//(internal1_m449_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m449_Zav0	 BUFFER[2927]	//(internal1_m449_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m449_Zav0	 875	//(internal1_m449_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m449_Pv0	 BUFFER[2929]	//(internal1_m449_Pv0)  - Пер. выключатель механизма
#define idinternal1_m449_Pv0	 876	//(internal1_m449_Pv0)  - Пер. выключатель механизма
#define internal1_m449_Zv0	 BUFFER[2931]	//(internal1_m449_Zv0)  - Зад. выключатель механизма
#define idinternal1_m449_Zv0	 877	//(internal1_m449_Zv0)  - Зад. выключатель механизма
#define internal1_m449_RA00	 BUFFER[2933]	//(internal1_m449_RA00)  - последнее задание вперед
#define idinternal1_m449_RA00	 878	//(internal1_m449_RA00)  - последнее задание вперед
#define internal1_m449_RA10	 BUFFER[2935]	//(internal1_m449_RA10)  - последнее задание назад
#define idinternal1_m449_RA10	 879	//(internal1_m449_RA10)  - последнее задание назад
#define internal1_m449_MyFirstEnterFlag	 BUFFER[2937]	//(internal1_m449_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m449_MyFirstEnterFlag	 880	//(internal1_m449_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m435_X00	 BUFFER[2939]	//(internal1_m435_X00)  X00 - текущая координата механизма
#define idinternal1_m435_X00	 881	//(internal1_m435_X00)  X00 - текущая координата механизма
#define internal1_m435_V00	 BUFFER[2944]	//(internal1_m435_V00)  V00 - текущая скорость механизма
#define idinternal1_m435_V00	 882	//(internal1_m435_V00)  V00 - текущая скорость механизма
#define internal1_m435_Pav0	 BUFFER[2949]	//(internal1_m435_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m435_Pav0	 883	//(internal1_m435_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m435_Zav0	 BUFFER[2951]	//(internal1_m435_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m435_Zav0	 884	//(internal1_m435_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m435_Pv0	 BUFFER[2953]	//(internal1_m435_Pv0)  - Пер. выключатель механизма
#define idinternal1_m435_Pv0	 885	//(internal1_m435_Pv0)  - Пер. выключатель механизма
#define internal1_m435_Zv0	 BUFFER[2955]	//(internal1_m435_Zv0)  - Зад. выключатель механизма
#define idinternal1_m435_Zv0	 886	//(internal1_m435_Zv0)  - Зад. выключатель механизма
#define internal1_m435_RA00	 BUFFER[2957]	//(internal1_m435_RA00)  - последнее задание вперед
#define idinternal1_m435_RA00	 887	//(internal1_m435_RA00)  - последнее задание вперед
#define internal1_m435_RA10	 BUFFER[2959]	//(internal1_m435_RA10)  - последнее задание назад
#define idinternal1_m435_RA10	 888	//(internal1_m435_RA10)  - последнее задание назад
#define internal1_m435_MyFirstEnterFlag	 BUFFER[2961]	//(internal1_m435_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m435_MyFirstEnterFlag	 889	//(internal1_m435_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m486_X00	 BUFFER[2963]	//(internal1_m486_X00)  X00 - текущая координата механизма
#define idinternal1_m486_X00	 890	//(internal1_m486_X00)  X00 - текущая координата механизма
#define internal1_m486_V00	 BUFFER[2968]	//(internal1_m486_V00)  V00 - текущая скорость механизма
#define idinternal1_m486_V00	 891	//(internal1_m486_V00)  V00 - текущая скорость механизма
#define internal1_m486_Pav0	 BUFFER[2973]	//(internal1_m486_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m486_Pav0	 892	//(internal1_m486_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m486_Zav0	 BUFFER[2975]	//(internal1_m486_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m486_Zav0	 893	//(internal1_m486_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m486_Pv0	 BUFFER[2977]	//(internal1_m486_Pv0)  - Пер. выключатель механизма
#define idinternal1_m486_Pv0	 894	//(internal1_m486_Pv0)  - Пер. выключатель механизма
#define internal1_m486_Zv0	 BUFFER[2979]	//(internal1_m486_Zv0)  - Зад. выключатель механизма
#define idinternal1_m486_Zv0	 895	//(internal1_m486_Zv0)  - Зад. выключатель механизма
#define internal1_m486_RA00	 BUFFER[2981]	//(internal1_m486_RA00)  - последнее задание вперед
#define idinternal1_m486_RA00	 896	//(internal1_m486_RA00)  - последнее задание вперед
#define internal1_m486_RA10	 BUFFER[2983]	//(internal1_m486_RA10)  - последнее задание назад
#define idinternal1_m486_RA10	 897	//(internal1_m486_RA10)  - последнее задание назад
#define internal1_m486_MyFirstEnterFlag	 BUFFER[2985]	//(internal1_m486_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m486_MyFirstEnterFlag	 898	//(internal1_m486_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m387_X00	 BUFFER[2987]	//(internal1_m387_X00)  X00 - текущая координата механизма
#define idinternal1_m387_X00	 899	//(internal1_m387_X00)  X00 - текущая координата механизма
#define internal1_m387_V00	 BUFFER[2992]	//(internal1_m387_V00)  V00 - текущая скорость механизма
#define idinternal1_m387_V00	 900	//(internal1_m387_V00)  V00 - текущая скорость механизма
#define internal1_m387_Pav0	 BUFFER[2997]	//(internal1_m387_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m387_Pav0	 901	//(internal1_m387_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m387_Zav0	 BUFFER[2999]	//(internal1_m387_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m387_Zav0	 902	//(internal1_m387_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m387_Pv0	 BUFFER[3001]	//(internal1_m387_Pv0)  - Пер. выключатель механизма
#define idinternal1_m387_Pv0	 903	//(internal1_m387_Pv0)  - Пер. выключатель механизма
#define internal1_m387_Zv0	 BUFFER[3003]	//(internal1_m387_Zv0)  - Зад. выключатель механизма
#define idinternal1_m387_Zv0	 904	//(internal1_m387_Zv0)  - Зад. выключатель механизма
#define internal1_m387_RA00	 BUFFER[3005]	//(internal1_m387_RA00)  - последнее задание вперед
#define idinternal1_m387_RA00	 905	//(internal1_m387_RA00)  - последнее задание вперед
#define internal1_m387_RA10	 BUFFER[3007]	//(internal1_m387_RA10)  - последнее задание назад
#define idinternal1_m387_RA10	 906	//(internal1_m387_RA10)  - последнее задание назад
#define internal1_m387_MyFirstEnterFlag	 BUFFER[3009]	//(internal1_m387_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m387_MyFirstEnterFlag	 907	//(internal1_m387_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m372_X00	 BUFFER[3011]	//(internal1_m372_X00)  X00 - текущая координата механизма
#define idinternal1_m372_X00	 908	//(internal1_m372_X00)  X00 - текущая координата механизма
#define internal1_m372_V00	 BUFFER[3016]	//(internal1_m372_V00)  V00 - текущая скорость механизма
#define idinternal1_m372_V00	 909	//(internal1_m372_V00)  V00 - текущая скорость механизма
#define internal1_m372_Pav0	 BUFFER[3021]	//(internal1_m372_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m372_Pav0	 910	//(internal1_m372_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m372_Zav0	 BUFFER[3023]	//(internal1_m372_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m372_Zav0	 911	//(internal1_m372_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m372_Pv0	 BUFFER[3025]	//(internal1_m372_Pv0)  - Пер. выключатель механизма
#define idinternal1_m372_Pv0	 912	//(internal1_m372_Pv0)  - Пер. выключатель механизма
#define internal1_m372_Zv0	 BUFFER[3027]	//(internal1_m372_Zv0)  - Зад. выключатель механизма
#define idinternal1_m372_Zv0	 913	//(internal1_m372_Zv0)  - Зад. выключатель механизма
#define internal1_m372_RA00	 BUFFER[3029]	//(internal1_m372_RA00)  - последнее задание вперед
#define idinternal1_m372_RA00	 914	//(internal1_m372_RA00)  - последнее задание вперед
#define internal1_m372_RA10	 BUFFER[3031]	//(internal1_m372_RA10)  - последнее задание назад
#define idinternal1_m372_RA10	 915	//(internal1_m372_RA10)  - последнее задание назад
#define internal1_m372_MyFirstEnterFlag	 BUFFER[3033]	//(internal1_m372_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m372_MyFirstEnterFlag	 916	//(internal1_m372_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m356_X00	 BUFFER[3035]	//(internal1_m356_X00)  X00 - текущая координата механизма
#define idinternal1_m356_X00	 917	//(internal1_m356_X00)  X00 - текущая координата механизма
#define internal1_m356_V00	 BUFFER[3040]	//(internal1_m356_V00)  V00 - текущая скорость механизма
#define idinternal1_m356_V00	 918	//(internal1_m356_V00)  V00 - текущая скорость механизма
#define internal1_m356_Pav0	 BUFFER[3045]	//(internal1_m356_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m356_Pav0	 919	//(internal1_m356_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m356_Zav0	 BUFFER[3047]	//(internal1_m356_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m356_Zav0	 920	//(internal1_m356_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m356_Pv0	 BUFFER[3049]	//(internal1_m356_Pv0)  - Пер. выключатель механизма
#define idinternal1_m356_Pv0	 921	//(internal1_m356_Pv0)  - Пер. выключатель механизма
#define internal1_m356_Zv0	 BUFFER[3051]	//(internal1_m356_Zv0)  - Зад. выключатель механизма
#define idinternal1_m356_Zv0	 922	//(internal1_m356_Zv0)  - Зад. выключатель механизма
#define internal1_m356_RA00	 BUFFER[3053]	//(internal1_m356_RA00)  - последнее задание вперед
#define idinternal1_m356_RA00	 923	//(internal1_m356_RA00)  - последнее задание вперед
#define internal1_m356_RA10	 BUFFER[3055]	//(internal1_m356_RA10)  - последнее задание назад
#define idinternal1_m356_RA10	 924	//(internal1_m356_RA10)  - последнее задание назад
#define internal1_m356_MyFirstEnterFlag	 BUFFER[3057]	//(internal1_m356_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m356_MyFirstEnterFlag	 925	//(internal1_m356_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m884_X00	 BUFFER[3059]	//(internal1_m884_X00)  X00 - текущая координата механизма
#define idinternal1_m884_X00	 926	//(internal1_m884_X00)  X00 - текущая координата механизма
#define internal1_m884_V00	 BUFFER[3064]	//(internal1_m884_V00)  V00 - текущая скорость механизма
#define idinternal1_m884_V00	 927	//(internal1_m884_V00)  V00 - текущая скорость механизма
#define internal1_m884_Pav0	 BUFFER[3069]	//(internal1_m884_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m884_Pav0	 928	//(internal1_m884_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m884_Zav0	 BUFFER[3071]	//(internal1_m884_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m884_Zav0	 929	//(internal1_m884_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m884_Pv0	 BUFFER[3073]	//(internal1_m884_Pv0)  - Пер. выключатель механизма
#define idinternal1_m884_Pv0	 930	//(internal1_m884_Pv0)  - Пер. выключатель механизма
#define internal1_m884_Zv0	 BUFFER[3075]	//(internal1_m884_Zv0)  - Зад. выключатель механизма
#define idinternal1_m884_Zv0	 931	//(internal1_m884_Zv0)  - Зад. выключатель механизма
#define internal1_m884_RA00	 BUFFER[3077]	//(internal1_m884_RA00)  - последнее задание вперед
#define idinternal1_m884_RA00	 932	//(internal1_m884_RA00)  - последнее задание вперед
#define internal1_m884_RA10	 BUFFER[3079]	//(internal1_m884_RA10)  - последнее задание назад
#define idinternal1_m884_RA10	 933	//(internal1_m884_RA10)  - последнее задание назад
#define internal1_m884_MyFirstEnterFlag	 BUFFER[3081]	//(internal1_m884_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m884_MyFirstEnterFlag	 934	//(internal1_m884_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m177_C1	 BUFFER[3083]	//(internal1_m177_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m177_C1	 935	//(internal1_m177_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m177_C2	 BUFFER[3088]	//(internal1_m177_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m177_C2	 936	//(internal1_m177_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m177_C3	 BUFFER[3093]	//(internal1_m177_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m177_C3	 937	//(internal1_m177_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m177_C4	 BUFFER[3098]	//(internal1_m177_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m177_C4	 938	//(internal1_m177_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m177_C5	 BUFFER[3103]	//(internal1_m177_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m177_C5	 939	//(internal1_m177_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m177_C6	 BUFFER[3108]	//(internal1_m177_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m177_C6	 940	//(internal1_m177_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m177_N20	 BUFFER[3113]	//(internal1_m177_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m177_N20	 941	//(internal1_m177_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m177_C0	 BUFFER[3118]	//(internal1_m177_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define idinternal1_m177_C0	 942	//(internal1_m177_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define internal1_m177_ImpINI0	 BUFFER[3148]	//(internal1_m177_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m177_ImpINI0	 943	//(internal1_m177_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m177_MyFirstEnterFlag	 BUFFER[3150]	//(internal1_m177_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m177_MyFirstEnterFlag	 944	//(internal1_m177_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m295_X00	 BUFFER[3152]	//(internal1_m295_X00) X0 - текущая координата ОРР
#define idinternal1_m295_X00	 945	//(internal1_m295_X00) X0 - текущая координата ОРР
#define internal1_m295_Sh00	 BUFFER[3157]	//(internal1_m295_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m295_Sh00	 946	//(internal1_m295_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m295_RV00	 BUFFER[3162]	//(internal1_m295_RV00) V0 - текущая скорость ОРР
#define idinternal1_m295_RV00	 947	//(internal1_m295_RV00) V0 - текущая скорость ОРР
#define internal1_m295_ShV00	 BUFFER[3167]	//(internal1_m295_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m295_ShV00	 948	//(internal1_m295_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m295_Ppv0	 BUFFER[3172]	//(internal1_m295_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m295_Ppv0	 949	//(internal1_m295_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m295_Pav0	 BUFFER[3174]	//(internal1_m295_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m295_Pav0	 950	//(internal1_m295_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m295_Zav0	 BUFFER[3176]	//(internal1_m295_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m295_Zav0	 951	//(internal1_m295_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m295_RA00	 BUFFER[3178]	//(internal1_m295_RA00) RA00 - последнее задание вперед
#define idinternal1_m295_RA00	 952	//(internal1_m295_RA00) RA00 - последнее задание вперед
#define internal1_m295_RA10	 BUFFER[3180]	//(internal1_m295_RA10) RA10 - последнее задание назад
#define idinternal1_m295_RA10	 953	//(internal1_m295_RA10) RA10 - последнее задание назад
#define internal1_m295_RA30	 BUFFER[3182]	//(internal1_m295_RA30)  RA30 - разрешение движения
#define idinternal1_m295_RA30	 954	//(internal1_m295_RA30)  RA30 - разрешение движения
#define internal1_m295_RA50	 BUFFER[3184]	//(internal1_m295_RA50) Ra50 - последнее задание скорости
#define idinternal1_m295_RA50	 955	//(internal1_m295_RA50) Ra50 - последнее задание скорости
#define internal1_m295_fls	 BUFFER[3186]	//(internal1_m295_fls)  fls - флаг одношагового режима
#define idinternal1_m295_fls	 956	//(internal1_m295_fls)  fls - флаг одношагового режима
#define internal1_m295_flp	 BUFFER[3188]	//(internal1_m295_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m295_flp	 957	//(internal1_m295_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m295_MyFirstEnterFlag	 BUFFER[3190]	//(internal1_m295_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m295_MyFirstEnterFlag	 958	//(internal1_m295_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m130_X00	 BUFFER[3192]	//(internal1_m130_X00) X0 - текущая координата ОРР
#define idinternal1_m130_X00	 959	//(internal1_m130_X00) X0 - текущая координата ОРР
#define internal1_m130_Sh00	 BUFFER[3197]	//(internal1_m130_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m130_Sh00	 960	//(internal1_m130_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m130_RV00	 BUFFER[3202]	//(internal1_m130_RV00) V0 - текущая скорость ОРР
#define idinternal1_m130_RV00	 961	//(internal1_m130_RV00) V0 - текущая скорость ОРР
#define internal1_m130_ShV00	 BUFFER[3207]	//(internal1_m130_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m130_ShV00	 962	//(internal1_m130_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m130_Ppv0	 BUFFER[3212]	//(internal1_m130_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m130_Ppv0	 963	//(internal1_m130_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m130_Pav0	 BUFFER[3214]	//(internal1_m130_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m130_Pav0	 964	//(internal1_m130_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m130_Zav0	 BUFFER[3216]	//(internal1_m130_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m130_Zav0	 965	//(internal1_m130_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m130_RA00	 BUFFER[3218]	//(internal1_m130_RA00) RA00 - последнее задание вперед
#define idinternal1_m130_RA00	 966	//(internal1_m130_RA00) RA00 - последнее задание вперед
#define internal1_m130_RA10	 BUFFER[3220]	//(internal1_m130_RA10) RA10 - последнее задание назад
#define idinternal1_m130_RA10	 967	//(internal1_m130_RA10) RA10 - последнее задание назад
#define internal1_m130_RA30	 BUFFER[3222]	//(internal1_m130_RA30)  RA30 - разрешение движения
#define idinternal1_m130_RA30	 968	//(internal1_m130_RA30)  RA30 - разрешение движения
#define internal1_m130_RA50	 BUFFER[3224]	//(internal1_m130_RA50) Ra50 - последнее задание скорости
#define idinternal1_m130_RA50	 969	//(internal1_m130_RA50) Ra50 - последнее задание скорости
#define internal1_m130_fls	 BUFFER[3226]	//(internal1_m130_fls)  fls - флаг одношагового режима
#define idinternal1_m130_fls	 970	//(internal1_m130_fls)  fls - флаг одношагового режима
#define internal1_m130_flp	 BUFFER[3228]	//(internal1_m130_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m130_flp	 971	//(internal1_m130_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m130_MyFirstEnterFlag	 BUFFER[3230]	//(internal1_m130_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m130_MyFirstEnterFlag	 972	//(internal1_m130_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m259_X00	 BUFFER[3232]	//(internal1_m259_X00) X0 - текущая координата ОРР
#define idinternal1_m259_X00	 973	//(internal1_m259_X00) X0 - текущая координата ОРР
#define internal1_m259_Sh00	 BUFFER[3237]	//(internal1_m259_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m259_Sh00	 974	//(internal1_m259_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m259_RV00	 BUFFER[3242]	//(internal1_m259_RV00) V0 - текущая скорость ОРР
#define idinternal1_m259_RV00	 975	//(internal1_m259_RV00) V0 - текущая скорость ОРР
#define internal1_m259_ShV00	 BUFFER[3247]	//(internal1_m259_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m259_ShV00	 976	//(internal1_m259_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m259_Ppv0	 BUFFER[3252]	//(internal1_m259_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m259_Ppv0	 977	//(internal1_m259_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m259_Pav0	 BUFFER[3254]	//(internal1_m259_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m259_Pav0	 978	//(internal1_m259_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m259_Zav0	 BUFFER[3256]	//(internal1_m259_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m259_Zav0	 979	//(internal1_m259_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m259_RA00	 BUFFER[3258]	//(internal1_m259_RA00) RA00 - последнее задание вперед
#define idinternal1_m259_RA00	 980	//(internal1_m259_RA00) RA00 - последнее задание вперед
#define internal1_m259_RA10	 BUFFER[3260]	//(internal1_m259_RA10) RA10 - последнее задание назад
#define idinternal1_m259_RA10	 981	//(internal1_m259_RA10) RA10 - последнее задание назад
#define internal1_m259_RA30	 BUFFER[3262]	//(internal1_m259_RA30)  RA30 - разрешение движения
#define idinternal1_m259_RA30	 982	//(internal1_m259_RA30)  RA30 - разрешение движения
#define internal1_m259_RA50	 BUFFER[3264]	//(internal1_m259_RA50) Ra50 - последнее задание скорости
#define idinternal1_m259_RA50	 983	//(internal1_m259_RA50) Ra50 - последнее задание скорости
#define internal1_m259_fls	 BUFFER[3266]	//(internal1_m259_fls)  fls - флаг одношагового режима
#define idinternal1_m259_fls	 984	//(internal1_m259_fls)  fls - флаг одношагового режима
#define internal1_m259_flp	 BUFFER[3268]	//(internal1_m259_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m259_flp	 985	//(internal1_m259_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m259_MyFirstEnterFlag	 BUFFER[3270]	//(internal1_m259_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m259_MyFirstEnterFlag	 986	//(internal1_m259_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m94_X00	 BUFFER[3272]	//(internal1_m94_X00) X0 - текущая координата ОРР
#define idinternal1_m94_X00	 987	//(internal1_m94_X00) X0 - текущая координата ОРР
#define internal1_m94_Sh00	 BUFFER[3277]	//(internal1_m94_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m94_Sh00	 988	//(internal1_m94_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m94_RV00	 BUFFER[3282]	//(internal1_m94_RV00) V0 - текущая скорость ОРР
#define idinternal1_m94_RV00	 989	//(internal1_m94_RV00) V0 - текущая скорость ОРР
#define internal1_m94_ShV00	 BUFFER[3287]	//(internal1_m94_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m94_ShV00	 990	//(internal1_m94_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m94_Ppv0	 BUFFER[3292]	//(internal1_m94_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m94_Ppv0	 991	//(internal1_m94_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m94_Pav0	 BUFFER[3294]	//(internal1_m94_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m94_Pav0	 992	//(internal1_m94_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m94_Zav0	 BUFFER[3296]	//(internal1_m94_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m94_Zav0	 993	//(internal1_m94_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m94_RA00	 BUFFER[3298]	//(internal1_m94_RA00) RA00 - последнее задание вперед
#define idinternal1_m94_RA00	 994	//(internal1_m94_RA00) RA00 - последнее задание вперед
#define internal1_m94_RA10	 BUFFER[3300]	//(internal1_m94_RA10) RA10 - последнее задание назад
#define idinternal1_m94_RA10	 995	//(internal1_m94_RA10) RA10 - последнее задание назад
#define internal1_m94_RA30	 BUFFER[3302]	//(internal1_m94_RA30)  RA30 - разрешение движения
#define idinternal1_m94_RA30	 996	//(internal1_m94_RA30)  RA30 - разрешение движения
#define internal1_m94_RA50	 BUFFER[3304]	//(internal1_m94_RA50) Ra50 - последнее задание скорости
#define idinternal1_m94_RA50	 997	//(internal1_m94_RA50) Ra50 - последнее задание скорости
#define internal1_m94_fls	 BUFFER[3306]	//(internal1_m94_fls)  fls - флаг одношагового режима
#define idinternal1_m94_fls	 998	//(internal1_m94_fls)  fls - флаг одношагового режима
#define internal1_m94_flp	 BUFFER[3308]	//(internal1_m94_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m94_flp	 999	//(internal1_m94_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m94_MyFirstEnterFlag	 BUFFER[3310]	//(internal1_m94_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m94_MyFirstEnterFlag	 1000	//(internal1_m94_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m224_X00	 BUFFER[3312]	//(internal1_m224_X00) X0 - текущая координата ОРР
#define idinternal1_m224_X00	 1001	//(internal1_m224_X00) X0 - текущая координата ОРР
#define internal1_m224_Sh00	 BUFFER[3317]	//(internal1_m224_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m224_Sh00	 1002	//(internal1_m224_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m224_RV00	 BUFFER[3322]	//(internal1_m224_RV00) V0 - текущая скорость ОРР
#define idinternal1_m224_RV00	 1003	//(internal1_m224_RV00) V0 - текущая скорость ОРР
#define internal1_m224_ShV00	 BUFFER[3327]	//(internal1_m224_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m224_ShV00	 1004	//(internal1_m224_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m224_Ppv0	 BUFFER[3332]	//(internal1_m224_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m224_Ppv0	 1005	//(internal1_m224_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m224_Pav0	 BUFFER[3334]	//(internal1_m224_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m224_Pav0	 1006	//(internal1_m224_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m224_Zav0	 BUFFER[3336]	//(internal1_m224_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m224_Zav0	 1007	//(internal1_m224_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m224_RA00	 BUFFER[3338]	//(internal1_m224_RA00) RA00 - последнее задание вперед
#define idinternal1_m224_RA00	 1008	//(internal1_m224_RA00) RA00 - последнее задание вперед
#define internal1_m224_RA10	 BUFFER[3340]	//(internal1_m224_RA10) RA10 - последнее задание назад
#define idinternal1_m224_RA10	 1009	//(internal1_m224_RA10) RA10 - последнее задание назад
#define internal1_m224_RA30	 BUFFER[3342]	//(internal1_m224_RA30)  RA30 - разрешение движения
#define idinternal1_m224_RA30	 1010	//(internal1_m224_RA30)  RA30 - разрешение движения
#define internal1_m224_RA50	 BUFFER[3344]	//(internal1_m224_RA50) Ra50 - последнее задание скорости
#define idinternal1_m224_RA50	 1011	//(internal1_m224_RA50) Ra50 - последнее задание скорости
#define internal1_m224_fls	 BUFFER[3346]	//(internal1_m224_fls)  fls - флаг одношагового режима
#define idinternal1_m224_fls	 1012	//(internal1_m224_fls)  fls - флаг одношагового режима
#define internal1_m224_flp	 BUFFER[3348]	//(internal1_m224_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m224_flp	 1013	//(internal1_m224_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m224_MyFirstEnterFlag	 BUFFER[3350]	//(internal1_m224_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m224_MyFirstEnterFlag	 1014	//(internal1_m224_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m59_X00	 BUFFER[3352]	//(internal1_m59_X00) X0 - текущая координата ОРР
#define idinternal1_m59_X00	 1015	//(internal1_m59_X00) X0 - текущая координата ОРР
#define internal1_m59_Sh00	 BUFFER[3357]	//(internal1_m59_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m59_Sh00	 1016	//(internal1_m59_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m59_RV00	 BUFFER[3362]	//(internal1_m59_RV00) V0 - текущая скорость ОРР
#define idinternal1_m59_RV00	 1017	//(internal1_m59_RV00) V0 - текущая скорость ОРР
#define internal1_m59_ShV00	 BUFFER[3367]	//(internal1_m59_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m59_ShV00	 1018	//(internal1_m59_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m59_Ppv0	 BUFFER[3372]	//(internal1_m59_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m59_Ppv0	 1019	//(internal1_m59_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m59_Pav0	 BUFFER[3374]	//(internal1_m59_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m59_Pav0	 1020	//(internal1_m59_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m59_Zav0	 BUFFER[3376]	//(internal1_m59_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m59_Zav0	 1021	//(internal1_m59_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m59_RA00	 BUFFER[3378]	//(internal1_m59_RA00) RA00 - последнее задание вперед
#define idinternal1_m59_RA00	 1022	//(internal1_m59_RA00) RA00 - последнее задание вперед
#define internal1_m59_RA10	 BUFFER[3380]	//(internal1_m59_RA10) RA10 - последнее задание назад
#define idinternal1_m59_RA10	 1023	//(internal1_m59_RA10) RA10 - последнее задание назад
#define internal1_m59_RA30	 BUFFER[3382]	//(internal1_m59_RA30)  RA30 - разрешение движения
#define idinternal1_m59_RA30	 1024	//(internal1_m59_RA30)  RA30 - разрешение движения
#define internal1_m59_RA50	 BUFFER[3384]	//(internal1_m59_RA50) Ra50 - последнее задание скорости
#define idinternal1_m59_RA50	 1025	//(internal1_m59_RA50) Ra50 - последнее задание скорости
#define internal1_m59_fls	 BUFFER[3386]	//(internal1_m59_fls)  fls - флаг одношагового режима
#define idinternal1_m59_fls	 1026	//(internal1_m59_fls)  fls - флаг одношагового режима
#define internal1_m59_flp	 BUFFER[3388]	//(internal1_m59_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m59_flp	 1027	//(internal1_m59_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m59_MyFirstEnterFlag	 BUFFER[3390]	//(internal1_m59_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m59_MyFirstEnterFlag	 1028	//(internal1_m59_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m14_C1	 BUFFER[3392]	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m14_C1	 1029	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m14_C2	 BUFFER[3397]	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m14_C2	 1030	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m14_C3	 BUFFER[3402]	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m14_C3	 1031	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m14_C4	 BUFFER[3407]	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m14_C4	 1032	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m14_C5	 BUFFER[3412]	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m14_C5	 1033	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m14_C6	 BUFFER[3417]	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m14_C6	 1034	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m14_N20	 BUFFER[3422]	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m14_N20	 1035	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m14_C0	 BUFFER[3427]	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define idinternal1_m14_C0	 1036	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define internal1_m14_ImpINI0	 BUFFER[3457]	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m14_ImpINI0	 1037	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m14_MyFirstEnterFlag	 BUFFER[3459]	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m14_MyFirstEnterFlag	 1038	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &A1IS12LDU},	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
	{ 2	,1	,1	, &A1IS11LDU},	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
	{ 3	,1	,1	, &A1IS21LDU},	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
	{ 4	,1	,1	, &B6IS21LDU},	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
	{ 5	,1	,1	, &B6IS11LDU},	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
	{ 6	,1	,1	, &A6IS21LDU},	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
	{ 7	,1	,1	, &A6IS11LDU},	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
	{ 8	,1	,1	, &A8IS12LDU},	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
	{ 9	,1	,1	, &A8IS22LDU},	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
	{ 10	,1	,1	, &B8IS12LDU},	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
	{ 11	,1	,1	, &B8IS22LDU},	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
	{ 12	,1	,1	, &R4IS12LDU},	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
	{ 13	,1	,1	, &R4IS22LDU},	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
	{ 14	,1	,1	, &R4IS21LDU},	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
	{ 15	,1	,1	, &R4IS11LDU},	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
	{ 16	,1	,1	, &B4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
	{ 17	,1	,1	, &A4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
	{ 18	,1	,1	, &R0EE03LZ2},	//( - , SBz2) Питание  АКНП3  отключить
	{ 19	,1	,1	, &R0EE02LZ2},	//( - , SBz2) Питание  АКНП  отключить
	{ 20	,1	,1	, &R0EE04LZ1},	//( - , SBz1) Питание  АКНП4  отключить
	{ 21	,1	,1	, &R0EE03LZ1},	//( - , SBz1) Питание  АКНП3  отключить
	{ 22	,1	,1	, &R0EE02LZ1},	//( - , SBz1) Питание  АКНП  отключить
	{ 23	,1	,1	, &R0EE01LZ2},	//( - , SBz2) Питание  АКНП1  отключить
	{ 24	,1	,1	, &R0EE01LZ1},	//( - , SBz1) Питание  АКНП1  отключить
	{ 25	,1	,1	, &B4IS10LDU},	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
	{ 26	,1	,1	, &A4IS10LDU},	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
	{ 27	,1	,1	, &B1IE04LDU},	//( - , SCM) Движение ББ2 назад (от БУШД)
	{ 28	,1	,1	, &B1IE03LDU},	//( - , SCM) Движение ББ2 вперед (от БУШД)
	{ 29	,1	,1	, &A1IE04LDU},	//( - , SCM) Движение ББ1 назад (от БУШД)
	{ 30	,1	,1	, &A1IE03LDU},	//( - , SCM) Движение ББ1 вперед (от БУШД)
	{ 31	,1	,1	, &B1IS12LDU},	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
	{ 32	,1	,1	, &B1IS11LDU},	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
	{ 33	,1	,1	, &B1IS21LDU},	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
	{ 34	,5	,1	, &B1IC01UDU},	//( - , SDu) Координата штока ББ2
	{ 35	,5	,1	, &A1IC01UDU},	//( - , SDu) Координата штока ББ1
	{ 36	,1	,1	, &B2IS11LDU},	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
	{ 37	,1	,1	, &B2IS21LDU},	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
	{ 38	,1	,1	, &B9IS21LDU},	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
	{ 39	,1	,1	, &B9IS11LDU},	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
	{ 40	,1	,1	, &A9IS21LDU},	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
	{ 41	,1	,1	, &A9IS11LDU},	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
	{ 42	,1	,1	, &B5IS21LDU},	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
	{ 43	,1	,1	, &B5IS11LDU},	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
	{ 44	,1	,1	, &A5IS21LDU},	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
	{ 45	,1	,1	, &A5IS11LDU},	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
	{ 46	,1	,1	, &B0VP81LZZ},	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
	{ 47	,1	,1	, &A0VP81LZZ},	//(do32_pti:100 - K27DO, - ) Давление АЗ1 в норме
	{ 48	,5	,1	, &B8IC01UDU},	//( - , SDu) Координата АЗ2
	{ 49	,5	,1	, &A8IC01UDU},	//( - , SDu) Координата ДС2
	{ 50	,1	,1	, &R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 51	,1	,1	, &R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 52	,1	,1	, &R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 53	,1	,1	, &R2IS21LDU},	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
	{ 54	,1	,1	, &R2IS11LDU},	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
	{ 55	,1	,1	, &R1IS21LDU},	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
	{ 56	,1	,1	, &R1IS11LDU},	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
	{ 57	,1	,1	, &B4IS21LDU},	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
	{ 58	,1	,1	, &B4IS11LDU},	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
	{ 59	,1	,1	, &R8IS11LDU},	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
	{ 60	,1	,1	, &A4IS21LDU},	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
	{ 61	,1	,1	, &A4IS11LDU},	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
	{ 62	,1	,1	, &R5IS21LDU},	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
	{ 63	,1	,1	, &R5IS11LDU},	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
	{ 64	,1	,1	, &R3IS21LDU},	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
	{ 65	,1	,1	, &R3IS11LDU},	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
	{ 66	,1	,1	, &B2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
	{ 67	,3	,1	, &B2IP01IZ2},	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
	{ 68	,3	,1	, &B2IP01IZ1},	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
	{ 69	,5	,1	, &B2IC01UDU},	//( - , SDu) Координата штока РБ2
	{ 70	,1	,1	, &B2IS12LDU},	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
	{ 71	,3	,1	, &B0IT03IRP},	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
	{ 72	,8	,1	, &R0IN03FI3},	//( - , SA3) Выход КНК53М Гц от ПТИ
	{ 73	,8	,1	, &R0IN02FI3},	//( - , SA3) Выход КНК15-1 Гц от ПТИ
	{ 74	,8	,1	, &R0IN03FI2},	//( - , SA2) Выход КНК53М Гц от ПТИ
	{ 75	,8	,1	, &R0IN07RIP},	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
	{ 76	,8	,1	, &R0IN06RIP},	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
	{ 77	,3	,1	, &TerR0IN06FRP},	//( - , - ) Неисправности СНМ-11 -1,2
	{ 78	,8	,1	, &R0IN03RIP},	//( - , SRP) Выход КНК53М Гц от ПТИ
	{ 79	,8	,1	, &R0IN02RIP},	//( - , SRP) Выход КНК15- Гц от ПТИ
	{ 80	,8	,1	, &R0IN01RIP},	//( - , SRP) Выход СНМ-11 Гц от ПТИ
	{ 81	,8	,1	, &R0IN02FI2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{ 82	,8	,1	, &R0IN03FI1},	//( - , SA1) Выход КНК53М Гц от ПТИ
	{ 83	,8	,1	, &R0IN02FI1},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{ 84	,8	,1	, &R0IN03FI4},	//( - , SA4) Выход КНК53М Гц от ПТИ
	{ 85	,8	,1	, &R0IN02FI4},	//( - , SA4) Выход КНК15-1 Гц от ПТИ
	{ 86	,8	,1	, &R0IN01FI3},	//( - , SA3) Выход СНМ-11 Гц от ПТИ
	{ 87	,8	,1	, &R0IN01FI2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{ 88	,8	,1	, &B0SN07RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
	{ 89	,8	,1	, &B0SN06RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
	{ 90	,8	,1	, &B0SN05RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
	{ 91	,8	,1	, &B0SN04RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
	{ 92	,8	,1	, &B0SN03RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
	{ 93	,8	,1	, &B0SN02RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
	{ 94	,8	,1	, &A0SN07RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
	{ 95	,8	,1	, &A0SN06RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
	{ 96	,8	,1	, &A0SN05RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
	{ 97	,8	,1	, &A0SN04RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
	{ 98	,8	,1	, &A0SN03RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
	{ 99	,8	,1	, &A0SN02RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
	{ 100	,8	,1	, &krb2},	//( - , - ) 
	{ 101	,8	,1	, &krb1},	//( - , - ) 
	{ 102	,3	,1	, &R0DEUMLSS},	//( - , SCM) Сигнал управления моделью
	{ 103	,3	,1	, &R0MW11IP1},	//( - , SCM) Переключатель ВЫСТРЕЛ
	{ 104	,3	,1	, &R0IS01FI0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{ 105	,3	,1	, &A0IT03IRP},	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
	{ 106	,1	,1	, &B8IS21LDU},	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
	{ 107	,1	,1	, &B8IS11LDU},	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
	{ 108	,1	,1	, &A1VP81LZZ},	//(do32_pti:100 - K28DO, - ) Давление СБРОС ББ1 в норме
	{ 109	,1	,1	, &B1VP81LZZ},	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
	{ 110	,1	,1	, &B2IS33LDU},	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
	{ 111	,8	,1	, &A0VN01RIM},	//( - , SCM) Период разгона  AЗ1
	{ 112	,1	,1	, &B2IS32LIM},	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
	{ 113	,1	,1	, &B2IS11LIM},	//( - , SCM) Магнит РБ2 обесточен
	{ 114	,1	,1	, &A2IS32LIM},	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
	{ 115	,1	,1	, &A2IS11LIM},	//( - , SCM) Магнит РБ1 обесточен
	{ 116	,1	,1	, &B1IS32LIM},	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
	{ 117	,1	,1	, &B1IS11LIM},	//( - , SCM) Магнит ББ2 обесточен
	{ 118	,1	,1	, &A1IS32LIM},	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
	{ 119	,1	,1	, &A1IS11LIM},	//( - , SCM) Магнит ББ1 обесточен
	{ 120	,1	,1	, &A3AD34LDU},	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
	{ 121	,1	,1	, &R0IS02LDU},	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
	{ 122	,1	,1	, &R0EE04LZ2},	//( - , SBz2) Питание  АКНП4  отключить
	{ 123	,8	,1	, &R0IN01FI4},	//( - , SA4) Выход СНМ-11 Гц от ПТИ
	{ 124	,8	,1	, &R0IN01FI1},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{ 125	,1	,1	, &B7AP31LDU},	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
	{ 126	,1	,1	, &A7AP31LDU},	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
	{ 127	,1	,1	, &R4VS12LDU},	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
	{ 128	,1	,1	, &R4VS22LDU},	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
	{ 129	,1	,1	, &R1VS12LDU},	//( - , SCM) Движение МДЗ1 в сторону ВУ
	{ 130	,1	,1	, &R2VS12LDU},	//( - , SCM) Движение МДЗ2 в сторону ВУ
	{ 131	,1	,1	, &R2VS22LDU},	//( - , SCM) Движение МДЗ2 в сторону НУ
	{ 132	,1	,1	, &R1VS22LDU},	//( - , SCM) Движение МДЗ1 в сторону НУ
	{ 133	,1	,1	, &B5VS12LDU},	//( - , SCM) Движение НЛ2 в сторону ВУ
	{ 134	,1	,1	, &B5VS22LDU},	//( - , SCM) Движение НЛ2 в сторону НУ
	{ 135	,1	,1	, &A5VS12LDU},	//( - , SCM) Движение НЛ1 в сторону ВУ
	{ 136	,1	,1	, &A5VS22LDU},	//( - , SCM) Движение НЛ1 в сторону НУ
	{ 137	,1	,1	, &B6VS12LDU},	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
	{ 138	,1	,1	, &B6VS22LDU},	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
	{ 139	,1	,1	, &A6VS12LDU},	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
	{ 140	,1	,1	, &A6VS22LDU},	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
	{ 141	,1	,1	, &B8AD20LDU},	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
	{ 142	,1	,1	, &B8AD10LDU},	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
	{ 143	,1	,1	, &R4AD20LDU},	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
	{ 144	,1	,1	, &R4AD10LDU},	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
	{ 145	,8	,1	, &B0SR01RIM},	//( - , SCM) Текущая реактивность AЗ2
	{ 146	,1	,1	, &B3AD33LDU},	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
	{ 147	,1	,1	, &B3AD05LDU},	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
	{ 148	,1	,1	, &B3AD04LDU},	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
	{ 149	,1	,1	, &B3AD03LDU},	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
	{ 150	,1	,1	, &B3AD02LDU},	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
	{ 151	,1	,1	, &B3AD01LDU},	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
	{ 152	,1	,1	, &B3AD21LDU},	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
	{ 153	,1	,1	, &B3AD11LDU},	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
	{ 154	,1	,1	, &A3AD33LDU},	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
	{ 155	,1	,1	, &A3AD05LDU},	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
	{ 156	,1	,1	, &A3AD04LDU},	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
	{ 157	,1	,1	, &A3AD03LDU},	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
	{ 158	,8	,1	, &R0CR02RIM},	//( - , SCM) Коэффициент 11 связи АЗ1,2
	{ 159	,8	,1	, &R0CR01RIM},	//( - , SCM) Коэффициент 12 связи АЗ1,2
	{ 160	,8	,1	, &B0SN08RIM},	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
	{ 161	,8	,1	, &A0SN08RIM},	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
	{ 162	,1	,1	, &B5AD20LDU},	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
	{ 163	,1	,1	, &B5AD10LDU},	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
	{ 164	,1	,1	, &A5AD20LDU},	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
	{ 165	,1	,1	, &A5AD10LDU},	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
	{ 166	,1	,1	, &R2AD20LDU},	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
	{ 167	,1	,1	, &R2AD10LDU},	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
	{ 168	,1	,1	, &R1AD20LDU},	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
	{ 169	,1	,1	, &R1AD10LDU},	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
	{ 170	,1	,1	, &B6AD20LDU},	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
	{ 171	,1	,1	, &B6AD10LDU},	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
	{ 172	,1	,1	, &A6AD20LDU},	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
	{ 173	,1	,1	, &A6AD10LDU},	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
	{ 174	,1	,1	, &A8AD20LDU},	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
	{ 175	,1	,1	, &A8AD10LDU},	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
	{ 176	,1	,1	, &A2AD21LDU},	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
	{ 177	,1	,1	, &A2AD11LDU},	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
	{ 178	,1	,1	, &B1AD05LDU},	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
	{ 179	,1	,1	, &B1AD04LDU},	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
	{ 180	,1	,1	, &B1AD03LDU},	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
	{ 181	,1	,1	, &B1AD02LDU},	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
	{ 182	,1	,1	, &B1AD01LDU},	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
	{ 183	,1	,1	, &B1AD21LDU},	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
	{ 184	,1	,1	, &B1AD11LDU},	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
	{ 185	,1	,1	, &A1AD05LDU},	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
	{ 186	,1	,1	, &A1AD04LDU},	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
	{ 187	,1	,1	, &A1AD03LDU},	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
	{ 188	,1	,1	, &A1AD02LDU},	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
	{ 189	,1	,1	, &A1AD01LDU},	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
	{ 190	,1	,1	, &A1AD21LDU},	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
	{ 191	,1	,1	, &A1AD11LDU},	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
	{ 192	,8	,1	, &A0SR01RIM},	//( - , SCM) Текущая реактивность AЗ1
	{ 193	,1	,1	, &A3AD02LDU},	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
	{ 194	,1	,1	, &A3AD01LDU},	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
	{ 195	,1	,1	, &A3AD21LDU},	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
	{ 196	,1	,1	, &A3AD11LDU},	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
	{ 197	,1	,1	, &B2AD33LDU},	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
	{ 198	,1	,1	, &B2AD05LDU},	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
	{ 199	,1	,1	, &B2AD04LDU},	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
	{ 200	,1	,1	, &B2AD03LDU},	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
	{ 201	,1	,1	, &B2AD02LDU},	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
	{ 202	,1	,1	, &B2AD01LDU},	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
	{ 203	,1	,1	, &B2AD21LDU},	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
	{ 204	,1	,1	, &B2AD11LDU},	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
	{ 205	,1	,1	, &A2AD33LDU},	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
	{ 206	,1	,1	, &A2AD05LDU},	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
	{ 207	,1	,1	, &A2AD04LDU},	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
	{ 208	,1	,1	, &A2AD03LDU},	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
	{ 209	,1	,1	, &A2AD02LDU},	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
	{ 210	,1	,1	, &A2AD01LDU},	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
	{ 211	,1	,1	, &A2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
	{ 212	,3	,1	, &A2IP01IZ2},	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
	{ 213	,3	,1	, &A2IP01IZ1},	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
	{ 214	,1	,1	, &B3IS21LDU},	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
	{ 215	,1	,1	, &A3IS21LDU},	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
	{ 216	,1	,1	, &A2IS33LDU},	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
	{ 217	,5	,1	, &A2IC01UDU},	//( - , SDu) Координата штока РБ1
	{ 218	,1	,1	, &A2IS12LDU},	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
	{ 219	,1	,1	, &A2IS11LDU},	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
	{ 220	,1	,1	, &A2IS21LDU},	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
	{ 221	,3	,1	, &B0IT02IZ2},	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
	{ 222	,3	,1	, &B0IT01IZ1},	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
	{ 223	,3	,1	, &A0IT02IZ2},	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
	{ 224	,3	,1	, &A0IT01IZ1},	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
	{ 225	,1	,1	, &R6IS21LDU},	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
	{ 226	,1	,1	, &B7AS31LDU},	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
	{ 227	,1	,1	, &A7AS31LDU},	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
	{ 228	,1	,1	, &R6IS65LDU},	//( - , - ) Исправность ВИП ССДИ-35 2канал
	{ 229	,1	,1	, &R6IS64LDU},	//( - , - ) Исправность ВИП ССДИ-35 1канал
	{ 230	,1	,1	, &R6IS63LDU},	//( - , - ) Исправность ВИП ССДИ-39 2канал
	{ 231	,1	,1	, &R6IS62LDU},	//( - , - ) Исправность ВИП ССДИ-39 1канал
	{ 232	,1	,1	, &B3IS22LDU},	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
	{ 233	,1	,1	, &A3IS22LDU},	//(do32_pti:100 - K06DO, - ) Приход на НУП ИС1
	{ 234	,1	,1	, &B3IS11LDU},	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
	{ 235	,1	,1	, &A3IS11LDU},	//(do32_pti:100 - K05DO, - ) Приход на ВУ ИС1
	{ 236	,3	,1	, &A3IP02IDU},	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
	{ 237	,1	,1	, &B3VP81LDU},	//( - , - ) Давление СПУСК ИС2 в норме
	{ 238	,1	,1	, &A3VP81LDU},	//( - , - ) Давление СПУСК ИС1 в норме
	{ 239	,1	,1	, &B3IS33LDU},	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{ 240	,5	,1	, &B3IC01UDU},	//( - , SDu) Координата штока ИС2
	{ 241	,1	,1	, &B3IS31LDU},	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
	{ 242	,3	,1	, &B3IP02IDU},	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
	{ 243	,1	,1	, &A3IS33LDU},	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
	{ 244	,5	,1	, &A3IC01UDU},	//( - , SDu) Координата штока ИС1
	{ 245	,1	,1	, &A3IS31LDU},	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
	{ 246	,1	,1	, &B2AD32LDU},	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
	{ 247	,1	,1	, &B2AD31LDU},	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
	{ 248	,1	,1	, &B1AD32LDU},	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
	{ 249	,1	,1	, &B1AD31LDU},	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
	{ 250	,1	,1	, &A3AD31LDU},	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
	{ 251	,1	,1	, &C1MD31LP1},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
	{ 252	,1	,1	, &C1MD31LP2},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
	{ 253	,1	,1	, &A1AD31LDU},	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
	{ 254	,1	,1	, &A1AD32LDU},	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
	{ 255	,1	,1	, &A2AD31LDU},	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
	{ 256	,1	,1	, &C2MD31LP1},	//( - , SCM) Кнопка «СБРОС РБ»
	{ 257	,1	,1	, &A2AD32LDU},	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
	{ 258	,1	,1	, &R0VZ71LZ2},	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
	{ 259	,1	,1	, &R0VZ71LZ1},	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
	{ 260	,1	,1	, &R8AD21LDU},	//(vds32_pti:310 - K31VDSR, - ) Запуск системы инициирования
	{ 261	,1	,1	, &R0AD14LDU},	//( - , SCM) Имитация срабатывания верхней АС II УР
	{ 262	,8	,1	, &R0SR02RIM},	//( - , SCM) Текущая мощность РУ (ватт)
	{ 263	,1	,1	, &B3IS35LDU},	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
	{ 264	,1	,1	, &B3AD34LDU},	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
	{ 265	,1	,1	, &A3IS35LDU},	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
	{ 266	,1	,1	, &R7II73LZ2},	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
	{ 267	,1	,1	, &R7II71LZ2},	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
	{ 268	,1	,1	, &R7II72LZ2},	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
	{ 269	,1	,1	, &R0AD16LDU},	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
	{ 270	,1	,1	, &R7II72LZ1},	//(do32_pti:100 - K25DO, - ) Сработала АС IУР (датчик 2)
	{ 271	,1	,1	, &R7II71LZ1},	//(do32_pti:100 - K24DO, - ) Сработала АС IУР (датчик 1)
	{ 272	,1	,1	, &R7II73LZ1},	//(do32_pti:100 - K26DO, - ) Сработала АС IIУР
	{ 273	,8	,1	, &R0SR01RIM},	//( - , SCM) Текущая реактивность PУ
	{ 274	,8	,1	, &R0ST01RIM},	//( - , SCM) Текущий период разгона РУ
	{ 275	,1	,1	, &A4AD10LDU},	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
	{ 276	,1	,1	, &B4AD10LDU},	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
	{ 277	,1	,1	, &A9AD10LDU},	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
	{ 278	,1	,1	, &B9AD10LDU},	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
	{ 279	,1	,1	, &R0MW13LP2},	//( - , SCM) Переключатель «СЕТЬ»
	{ 280	,1	,1	, &B3AD31LDU},	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
	{ 281	,8	,1	, &fEM_R0UL01RIM},	//(R0UL01RIM) Среднее время генерации нейтронов
	{ 282	,8	,1	, &fEM_R0UN02RIM},	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{ 283	,8	,1	, &fEM_A1UR01RIM},	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{ 284	,8	,1	, &fEM_A1UR00RIM},	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{ 285	,8	,1	, &fEM_A3UR00RIM},	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{ 286	,8	,1	, &fEM_A3UR01RIM},	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{ 287	,8	,1	, &fEM_R0UT01RIM},	//(R0UT01RIM) Температурный коэффициент (долл)
	{ 288	,8	,1	, &fEM_R0UT02RIM},	//(R0UT02RIM) Масса топлива в АЗ
	{ 289	,8	,1	, &fEM_R0UT04RIM},	//(R0UT04RIM) Удельная теплоёмкость топлива
	{ 290	,8	,1	, &fEM_R0UT03RIM},	//(R0UT03RIM) Нормальная температура АЗ град
	{ 291	,8	,1	, &fEM_R0UT05RIM},	//(R0UT05RIM) Энергия деления ядра
	{ 292	,8	,1	, &fEM_R0UT06RIM},	//(R0UT06RIM) Конвекционное сопротивление при обдуве
	{ 293	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{ 294	,8	,1	, &fEM_A1UC04RIM},	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
	{ 295	,8	,1	, &fEM_A1UC05RIM},	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
	{ 296	,8	,1	, &fEM_A1UC06RIM},	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
	{ 297	,8	,1	, &fEM_A2UC06RIM},	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
	{ 298	,8	,1	, &fEM_A2UC05RIM},	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
	{ 299	,8	,1	, &fEM_A2UC04RIM},	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
	{ 300	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{ 301	,8	,1	, &fEM_A3UC06RIM},	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
	{ 302	,8	,1	, &fEM_A3UC05RIM},	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
	{ 303	,8	,1	, &fEM_A3UC04RIM},	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
	{ 304	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{ 305	,8	,1	, &fEM_R4UV80RDU},	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
	{ 306	,8	,1	, &fEM_R4UC10RIM},	//(R4UC10RIM) Координата верхних механических упоров тележки мм
	{ 307	,8	,1	, &fEM_R4UC20RIM},	//(R4UC20RIM) Координата нижних механических упоров тележки мм
	{ 308	,8	,1	, &fEM_B8UC21RIM},	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
	{ 309	,8	,1	, &fEM_B8UC20RIM},	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
	{ 310	,8	,1	, &fEM_B8UC11RIM},	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
	{ 311	,8	,1	, &fEM_B8UC10RIM},	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
	{ 312	,8	,1	, &fEM_B8UV80RDU},	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
	{ 313	,8	,1	, &fEM_A8UV80RDU},	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
	{ 314	,8	,1	, &fEM_A8UC10RIM},	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
	{ 315	,8	,1	, &fEM_A8UC11RIM},	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
	{ 316	,8	,1	, &fEM_A8UC20RIM},	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
	{ 317	,8	,1	, &fEM_A8UC21RIM},	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
	{ 318	,8	,1	, &fEM_A6UC10RIM},	//(A6UC10RIM) Время полного хода БЗ (сек)
	{ 319	,8	,1	, &fEM_R1UC10RIM},	//(R1UC10RIM) Время полного хода МДЗ сек
	{ 320	,8	,1	, &fEM_A5UC10RIM},	//(A5UC10RIM) Время полного хода НЛ сек
	{ 321	,8	,1	, &fEM_A0UN01RIM},	//(A0UN01RIM) Мощность источника нейтронов ИНИ
	{ 322	,8	,1	, &fEM_R4UC22RIM},	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
	{ 323	,8	,1	, &fEM_A1UG01RDU},	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
	{ 324	,8	,1	, &fEM_A2UG01RDU},	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
	{ 325	,8	,1	, &fEM_A3UG01RDU},	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
	{ 326	,8	,1	, &fEM_R7UC10RIM},	//(R7UC10RIM) X-координата КНК53М R7IN13 см
	{ 327	,8	,1	, &fEM_R7UC19RIM},	//(R7UC19RIM) Y-координата СНМ-11 (11) см
	{ 328	,8	,1	, &fEM_R7UI02RIM},	//(R7UI02RIM) Коэффициент усиления уровня радиации
	{ 329	,8	,1	, &fEM_R7UL01RIM},	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
	{ 330	,8	,1	, &fEM_A2UR00RIM},	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{ 331	,8	,1	, &fEM_A2UR01RIM},	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{ 332	,8	,1	, &fEM_A0UN02RIM},	//(A0UN02RIM) Мощность источника нейтронов с АНИ
	{ 333	,8	,1	, &fEM_R0UR30RIM},	//(R0UR30RIM) Реактивность вносимая образцами (долл)
	{ 334	,8	,1	, &fEM_R0UR01RIM},	//(R0UR01RIM) Стартовая отрицательная реактивность
	{ 335	,8	,1	, &fEM_R0UT02RDU},	//(R0UT02RDU) Верхний предел шкалы датчика температуры
	{ 336	,8	,1	, &fEM_R0UT01RDU},	//(R0UT01RDU) Нижний предел шкалы датчика температуры
	{ 337	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{ 338	,8	,1	, &fEM_A2UP03RDU},	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{ 339	,8	,1	, &fEM_A2UP04RDU},	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{ 340	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{ 341	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 342	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 343	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{ 344	,8	,1	, &fEM_R7UI74RIM},	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
	{ 345	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{ 346	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 347	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 348	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{ 349	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{ 350	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{ 351	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 352	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 353	,8	,1	, &fEM_A8UC08RDU},	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
	{ 354	,8	,1	, &fEM_B8UC08RDU},	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
	{ 355	,8	,1	, &fEM_R4UC08RDU},	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
	{ 356	,8	,1	, &fEM_R0UH01RSS},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
	{ 357	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 358	,8	,1	, &fEM_R7UX01RSS},	//(R7UX01RSS) X-координата камеры R7IN11
	{ 359	,8	,1	, &fEM_R7UX02RSS},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{ 360	,8	,1	, &fEM_R7UX04RSS},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{ 361	,8	,1	, &fEM_R7UX05RSS},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{ 362	,8	,1	, &fEM_R7UX06RSS},	//(R7UX06RSS) X-координата камеры R7IN23 (см)
	{ 363	,8	,1	, &fEM_R7UX07RSS},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{ 364	,8	,1	, &fEM_R7UX08RSS},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{ 365	,8	,1	, &fEM_R7UX09RSS},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{ 366	,8	,1	, &fEM_R7UY01RSS},	//(R7UY01RSS) Y-координата камеры R7IN11
	{ 367	,8	,1	, &fEM_R7UY02RSS},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{ 368	,8	,1	, &fEM_R7UY04RSS},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{ 369	,8	,1	, &fEM_R7UY05RSS},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{ 370	,8	,1	, &fEM_R7UY06RSS},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{ 371	,8	,1	, &fEM_R7UY07RSS},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{ 372	,8	,1	, &fEM_R7UY08RSS},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{ 373	,8	,1	, &fEM_R7UY09RSS},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{ 374	,8	,1	, &fEM_R7UX10RSS},	//(R7UX10RSS) X-координата камеры R7IN41
	{ 375	,8	,1	, &fEM_R7UX11RSS},	//(R7UX11RSS) X-координата камеры R7IN42
	{ 376	,8	,1	, &fEM_R7UX12RSS},	//(R7UX12RSS) X-координата камеры R7IN43
	{ 377	,8	,1	, &fEM_R7UY10RSS},	//(R7UY10RSS) Y-координата камеры R7IN41
	{ 378	,8	,1	, &fEM_R7UY11RSS},	//(R7UY11RSS) Y-координата камеры R7IN42
	{ 379	,8	,1	, &fEM_R7UY12RSS},	//(R7UY12RSS) Y-координата камеры R7IN43
	{ 380	,8	,1	, &fEM_A0UX01RSS},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{ 381	,8	,1	, &fEM_A0UX02RSS},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{ 382	,8	,1	, &fEM_A0UX03RSS},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{ 383	,8	,1	, &fEM_A0UX04RSS},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{ 384	,8	,1	, &fEM_A0UX05RSS},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{ 385	,8	,1	, &fEM_A0UX06RSS},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{ 386	,8	,1	, &fEM_A0UX07RSS},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{ 387	,8	,1	, &fEM_A0UX08RSS},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{ 388	,8	,1	, &fEM_A0UX09RSS},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{ 389	,8	,1	, &fEM_A0UX10RSS},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{ 390	,8	,1	, &fEM_A0UX11RSS},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{ 391	,8	,1	, &fEM_A0UX12RSS},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{ 392	,8	,1	, &fEM_B0UX01RSS},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{ 393	,8	,1	, &fEM_B0UX02RSS},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{ 394	,8	,1	, &fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{ 395	,8	,1	, &fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
	{ 396	,8	,1	, &fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{ 397	,8	,1	, &fEM_B0UX06RSS},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{ 398	,8	,1	, &fEM_B0UX07RSS},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{ 399	,8	,1	, &fEM_B0UX08RSS},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{ 400	,8	,1	, &fEM_B0UX09RSS},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{ 401	,8	,1	, &fEM_B0UX10RSS},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{ 402	,8	,1	, &fEM_B0UX11RSS},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{ 403	,8	,1	, &fEM_B0UX12RSS},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{ 404	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{ 405	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
	{ 406	,8	,1	, &fEM_R4US80RDU},	//(R4US80RDU) Тормозной путь тележки (мм)
	{ 407	,8	,1	, &fEM_R7UI71RIM},	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{ 408	,8	,1	, &fEM_R7UI72RIM},	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{ 409	,8	,1	, &fEM_R7UI73RIM},	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
	{ 410	,8	,1	, &fEM_A1UP01RIM},	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
	{ 411	,8	,1	, &fEM_A2UP01RIM},	//(A2UP01RIM) Текущее давление на сброс РБ
	{ 412	,8	,1	, &fEM_A0UP02RIM},	//(A0UP02RIM) Текущее давление в АЗ1,2
	{ 413	,8	,1	, &fEM_A3UP01RIM},	//(A3UP01RIM) Текущее давление на СПУСК ИС
	{ 414	,8	,1	, &fEM_A1UP82RIM},	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{ 415	,8	,1	, &fEM_A3UP02RDU},	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
	{ 416	,8	,1	, &fEM_A1UV02RIM},	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{ 417	,8	,1	, &fEM_A3UV02RIM},	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{ 418	,8	,1	, &fEM_A2UV02RIM},	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{ 419	,8	,1	, &fEM_B8US80RDU},	//(B8US80RDU) Тормозной путь АЗ2 (мм)
	{ 420	,8	,1	, &fEM_A8US80RDU},	//(A8US80RDU) Тормозной путь ДС2 (мм)
	{ 421	,8	,1	, &fEM_A6US80RDU},	//(A6US80RDU) Тормозной путь БЗ (мм)
	{ 422	,8	,1	, &fEM_A1US07RDU},	//(A1US07RDU) Постоянная времени масляного демпфера ББ
	{ 423	,8	,1	, &fEM_A2US07RDU},	//(A2US07RDU) Постоянная времени масляного демпфера РБ
	{ 424	,8	,1	, &fEM_A3US07RDU},	//(A3US07RDU) Постоянная времени масляного демпфера ИС
	{ 425	,8	,1	, &fEM_R7UI75RIM},	//(R7UI75RIM) Множитель к уровню радиации
	{ 426	,8	,1	, &fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{ 427	,8	,1	, &fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{ 428	,8	,1	, &fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{ 429	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 430	,8	,1	, &fEM_A4UL10RIM},	//(A4UL10RIM) Время полного перемещения НИ сек
	{ 431	,8	,1	, &fEM_A9UL10RIM},	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
	{ 432	,8	,1	, &fEM_R3UL10RIM},	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
	{ 433	,8	,1	, &fEM_R5UL10RIM},	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
	{ 434	,8	,1	, &fEM_R6UL10RIM},	//(R6UL10RIM) Время полного хода кран-балки сек
	{ 435	,1	,1	, &lEM_C1AD31LRP},	//(C1AD31LRP) Общий сброс от РПУ
	{ 436	,1	,1	, &lEM_R0IE01LRP},	//(R0IE01LRP) Отключение питание детекторов
	{ 437	,1	,1	, &lEM_R0IE02LRP},	//(R0IE02LRP) Отключить питание ПР, ПУ
	{ 438	,8	,1	, &fEM_A2UP02RIM},	//(A2UP02RIM) Текущее давление на подъём РБ
	{ 439	,8	,1	, &fEM_A2UP03RIM},	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
	{ 440	,8	,1	, &fEM_A0UP01RIM},	//(A0UP01RIM) Текущее давление в АЗ1,2
	{ 441	,8	,1	, &fEM_A3UP02RIM},	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
	{ 442	,8	,1	, &fEM_A4UP01RIM},	//(A4UP01RIM) Текущее давление на подъём НИ
	{ 443	,8	,1	, &fEM_A4UP02RIM},	//(A4UP02RIM) Нижняя граница давления на подъём НИ
	{ 444	,8	,1	, &fEM_R7UI76RIM},	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{ 445	,8	,1	, &fEM_R7UI77RIM},	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{ 446	,3	,1	, &iEM_TERBB1},	//(TERBB1) Неисправности  ББ1
	{ 447	,8	,1	, &fEM_A1MC02RC1},	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
	{ 448	,8	,1	, &fEM_A1MV02RC1},	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
	{ 449	,3	,1	, &iEM_TERBB2},	//(TERBB2) Неисправности  ББ2
	{ 450	,8	,1	, &fEM_B1MC02RC1},	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
	{ 451	,8	,1	, &fEM_B1MV02RC1},	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
	{ 452	,3	,1	, &iEM_TERRB2},	//(TERRB2) Неисправности  РБ2
	{ 453	,8	,1	, &fEM_B2MC02RC1},	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
	{ 454	,8	,1	, &fEM_B2MV02RC1},	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
	{ 455	,3	,1	, &iEM_TERRB1},	//(TERRB1) Неисправности  РБ1
	{ 456	,8	,1	, &fEM_A2MC02RC1},	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
	{ 457	,8	,1	, &fEM_A2MV02RC1},	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
	{ 458	,3	,1	, &iEM_TERIS2},	//(TERIS2) Неисправности  ИС2
	{ 459	,8	,1	, &fEM_B3MC02RC1},	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
	{ 460	,8	,1	, &fEM_B3MV02RC1},	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
	{ 461	,3	,1	, &iEM_TERIS1},	//(TERIS1) Неисправности  ИС1
	{ 462	,8	,1	, &fEM_A3MC02RC1},	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
	{ 463	,8	,1	, &fEM_A3MV02RC1},	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
	{ 464	,3	,1	, &iEM_TERA1IE04LDU},	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
	{ 465	,3	,1	, &iEM_TERA1IE03LDU},	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
	{ 466	,8	,1	, &fEM_A1MC01RC1},	//(A1MC01RC1) Заданная координата  ББ1 от ИС
	{ 467	,3	,1	, &iEM_TERB1IE03LDU},	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
	{ 468	,3	,1	, &iEM_TERB1IE04LDU},	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
	{ 469	,8	,1	, &fEM_B1MC01RC1},	//(B1MC01RC1) Заданная координата ББ2 от ИС
	{ 470	,8	,1	, &fEM_B1MV01RC1},	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
	{ 471	,8	,1	, &fEM_B2MC01RC1},	//(B2MC01RC1) Заданная координата РБ2 от ИС
	{ 472	,8	,1	, &fEM_B2MV01RC1},	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
	{ 473	,8	,1	, &fEM_A3MC01RC1},	//(A3MC01RC1) Заданная координата ИС1 от ИС
	{ 474	,8	,1	, &fEM_A3MV01RC1},	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
	{ 475	,8	,1	, &fEM_B3MC01RC1},	//(B3MC01RC1) Заданная координата ИС2 от ИС
	{ 476	,8	,1	, &fEM_B3MV01RC1},	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
	{ 477	,3	,1	, &iEM_TERA2SS21LIM},	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
	{ 478	,3	,1	, &iEM_TERA2SS12LIM},	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
	{ 479	,3	,1	, &iEM_TERR6SS21LIM},	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
	{ 480	,3	,1	, &iEM_TERA2VP82LIM},	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
	{ 481	,3	,1	, &iEM_TERA2SS11LIM},	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
	{ 482	,3	,1	, &iEM_TERB3SS21LIM},	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
	{ 483	,3	,1	, &iEM_TERA0MT01RIM},	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
	{ 484	,3	,1	, &iEM_TERB0MT01RIM},	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
	{ 485	,3	,1	, &iEM_TERA2SP01RIM},	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
	{ 486	,3	,1	, &iEM_TERB2SP01RIM},	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
	{ 487	,3	,1	, &iEM_TERB3SP02RIM},	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{ 488	,3	,1	, &iEM_TERA3SC01RIM},	//(TERA3SC01RIM) Искажение: Координата штока ИС1
	{ 489	,3	,1	, &iEM_TERA3VP81LIM},	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
	{ 490	,3	,1	, &iEM_TERA2SC01RIM},	//(TERA2SC01RIM) Искажение: Координата штока РБ1
	{ 491	,3	,1	, &iEM_TERA2SS33LIM},	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{ 492	,3	,1	, &iEM_TERA3SS21LIM},	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
	{ 493	,3	,1	, &iEM_TERA3SS33LIM},	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{ 494	,3	,1	, &iEM_TERA3SS31LIM},	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{ 495	,3	,1	, &iEM_TERB3SS31LIM},	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{ 496	,3	,1	, &iEM_TERB3SS33LIM},	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{ 497	,3	,1	, &iEM_TERB3SC01RIM},	//(TERB3SC01RIM) Искажение: Координата штока ИС2
	{ 498	,3	,1	, &iEM_TERA3SS11LIM},	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
	{ 499	,3	,1	, &iEM_TERB3SS11LIM},	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
	{ 500	,3	,1	, &iEM_TERR6IS64LIM},	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
	{ 501	,3	,1	, &iEM_TERB3SS22LIM},	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
	{ 502	,3	,1	, &iEM_TERA3SS22LIM},	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
	{ 503	,3	,1	, &iEM_TERA3SP02RIM},	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{ 504	,3	,1	, &iEM_TERR6IS62LIM},	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
	{ 505	,3	,1	, &iEM_TERR6IS66LIM},	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 506	,3	,1	, &iEM_TERR6IS67LIM},	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 507	,3	,1	, &iEM_TERA0VP81LIM},	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
	{ 508	,3	,1	, &iEM_TERB0VP81LIM},	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
	{ 509	,3	,1	, &iEM_TERR0VP81LIM},	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{ 510	,3	,1	, &iEM_TERR6IS68LIM},	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{ 511	,3	,1	, &iEM_TERR7SI74RIM},	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
	{ 512	,3	,1	, &iEM_TERA5SS21LIM},	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
	{ 513	,3	,1	, &iEM_TERB5SS11LIM},	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
	{ 514	,3	,1	, &iEM_TERA5SS11LIM},	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{ 515	,3	,1	, &iEM_TERA9SS11LIM},	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
	{ 516	,3	,1	, &iEM_TERB2SS11LIM},	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
	{ 517	,3	,1	, &iEM_TERB2SS12LIM},	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
	{ 518	,3	,1	, &iEM_TERB2SS21LIM},	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
	{ 519	,3	,1	, &iEM_TERR3SS11LIM},	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
	{ 520	,3	,1	, &iEM_TERB2SC01RIM},	//(TERB2SC01RIM) Искажение: Координата штока РБ2
	{ 521	,3	,1	, &iEM_TERR3SS21LIM},	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
	{ 522	,3	,1	, &iEM_TERR5SS11LIM},	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
	{ 523	,3	,1	, &iEM_TERA4SS11LIM},	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
	{ 524	,3	,1	, &iEM_TERR1SS11LIM},	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
	{ 525	,3	,1	, &iEM_TERR1SS21LIM},	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
	{ 526	,3	,1	, &iEM_TERR2SS11LIM},	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
	{ 527	,3	,1	, &iEM_TERR2SS21LIM},	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
	{ 528	,3	,1	, &iEM_TERA4VP82LIM},	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
	{ 529	,3	,1	, &iEM_TERB4SS21LIM},	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
	{ 530	,3	,1	, &iEM_TERR5SS21LIM},	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
	{ 531	,3	,1	, &iEM_TERB6SS21LIM},	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
	{ 532	,3	,1	, &iEM_TERB4SS11LIM},	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
	{ 533	,3	,1	, &iEM_TERA4SS21LIM},	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
	{ 534	,3	,1	, &iEM_TERA6MS11LIM},	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
	{ 535	,3	,1	, &iEM_TERA6SS21LIM},	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
	{ 536	,3	,1	, &iEM_TERB6SS11LIM},	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
	{ 537	,3	,1	, &iEM_TERR4SS11LIM},	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
	{ 538	,3	,1	, &iEM_TERR4MS21LIM},	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
	{ 539	,3	,1	, &iEM_TERR4SS12LIM},	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
	{ 540	,3	,1	, &iEM_TERR4SS22LIM},	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
	{ 541	,3	,1	, &iEM_TERR8SS11LIM},	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
	{ 542	,3	,1	, &iEM_TERB8SC01RIM},	//(TERB8SC01RIM) Искажение: Координата АЗ2
	{ 543	,3	,1	, &iEM_TERA8SC01RIM},	//(TERA8SC01RIM) Искажение: Координата ДС2
	{ 544	,3	,1	, &iEM_TERB8SS12LIM},	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
	{ 545	,3	,1	, &iEM_TERA8SS12LIM},	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
	{ 546	,3	,1	, &iEM_TERB8SS22LIM},	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
	{ 547	,3	,1	, &iEM_TERA8SS22LIM},	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
	{ 548	,3	,1	, &iEM_TERA9SS21LIM},	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
	{ 549	,3	,1	, &iEM_TERB9SS21LIM},	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
	{ 550	,3	,1	, &iEM_TERB9SS11LIM},	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
	{ 551	,3	,1	, &iEM_TERB5SS21LIM},	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
	{ 552	,3	,1	, &iEM_TERA1SS21LIM},	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
	{ 553	,3	,1	, &iEM_TERA1SS11LIM},	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
	{ 554	,3	,1	, &iEM_TERA1SC01RIM},	//(TERA1SC01RIM) Искажение: Координата штока ББ1
	{ 555	,3	,1	, &iEM_TERA1SS12LIM},	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
	{ 556	,3	,1	, &iEM_TERB1SS21LIM},	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
	{ 557	,3	,1	, &iEM_TERB1SS11LIM},	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
	{ 558	,3	,1	, &iEM_TERB1MC01RIM},	//(TERB1MC01RIM) Искажение: Координата штока ББ2
	{ 559	,3	,1	, &iEM_TERB1SS12LIM},	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
	{ 560	,3	,1	, &iEM_TERTLG},	//(TERTLG) Неисправности  тележки от ИС
	{ 561	,8	,1	, &fEM_R4MC01RC1},	//(R4MC01RC1) Заданная координата тележки от ИС
	{ 562	,8	,1	, &fEM_R4MV01RC1},	//(R4MV01RC1) Заданная скорость тележки от ИС
	{ 563	,3	,1	, &iEM_TERMAZ2},	//(TERMAZ2) Неисправности АЗ2 от ИС
	{ 564	,8	,1	, &fEM_B8MC01RC1},	//(B8MC01RC1) Заданная координата АЗ2 от ИС
	{ 565	,8	,1	, &fEM_B8MV01RC1},	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
	{ 566	,3	,1	, &iEM_TERDS2},	//(TERDS2) Неисправности ДС2 от ИС
	{ 567	,8	,1	, &fEM_A8MC01RC1},	//(A8MC01RC1) Заданная координата ДС2 от ИС
	{ 568	,8	,1	, &fEM_A8MV01RC1},	//(A8MV01RC1) Заданная скорость ДС2 от ИС
	{ 569	,3	,1	, &iEM_TERBZ1},	//(TERBZ1) Неисправности БЗ1
	{ 570	,8	,1	, &fEM_A6MC01RC1},	//(A6MC01RC1) Заданная координата БЗ1 от ИС
	{ 571	,8	,1	, &fEM_A6MV01RC1},	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
	{ 572	,3	,1	, &iEM_TERBZ2},	//(TERBZ2) Неисправности БЗ2
	{ 573	,8	,1	, &fEM_B6MC01RC1},	//(B6MC01RC1) Заданная координата БЗ2 от ИС
	{ 574	,8	,1	, &fEM_B6MV01RC1},	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
	{ 575	,1	,1	, &lEM_R3AD10LC1},	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
	{ 576	,1	,1	, &lEM_R3AD20LC1},	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
	{ 577	,1	,1	, &lEM_R6AD10LC1},	//(R6AD10LC1) Выкатить кран-балку от ИС
	{ 578	,1	,1	, &lEM_R5AD10LC1},	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
	{ 579	,1	,1	, &lEM_R5AD20LC1},	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
	{ 580	,3	,1	, &iEM_TERMDZ2},	//(TERMDZ2) Неисправности МДЗ2
	{ 581	,8	,1	, &fEM_R2MC01RC1},	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
	{ 582	,8	,1	, &fEM_R2MV01RC1},	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
	{ 583	,3	,1	, &iEM_TERMDZ1},	//(TERMDZ1) Неисправности МДЗ1
	{ 584	,8	,1	, &fEM_R1MC01RC1},	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
	{ 585	,8	,1	, &fEM_R1MV01RC1},	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
	{ 586	,3	,1	, &iEM_TERNL1},	//(TERNL1) Неисправности НЛ1
	{ 587	,8	,1	, &fEM_A5MC01RC1},	//(A5MC01RC1) Заданная координата НЛ1 от ИС
	{ 588	,8	,1	, &fEM_A5MV01RC1},	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
	{ 589	,3	,1	, &iEM_TERNL2},	//(TERNL2) Неисправности НЛ2
	{ 590	,8	,1	, &fEM_B5MC01RC1},	//(B5MC01RC1) Заданная координата НЛ2 от ИС
	{ 591	,8	,1	, &fEM_B5MV01RC1},	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
	{ 592	,1	,1	, &lEM_R8AD10LC1},	//(R8AD10LC1) Установить аварийный НИ от ИС
	{ 593	,8	,1	, &fEM_A1UC08RIM},	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
	{ 594	,8	,1	, &fEM_A2UC08RIM},	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
	{ 595	,8	,1	, &fEM_A3UC08RIM},	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
	{ 596	,3	,1	, &iEM_TERB2SS33LIM},	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{ 597	,3	,1	, &iEM_TERA1VP81LIM},	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
	{ 598	,3	,1	, &iEM_TERB1VP81LIM},	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
	{ 599	,8	,1	, &fEM_A0UT03RSP},	//(A0UT03RSP) Стартовая  температура АЗ1 град
	{ 600	,8	,1	, &fEM_A0UR01RSP},	//(A0UR01RSP) Стартовая  реактивность АЗ1
	{ 601	,8	,1	, &fEM_A0UR02RSP},	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
	{ 602	,8	,1	, &fEM_B0UT03RSP},	//(B0UT03RSP) Стартовая  температура АЗ2 град
	{ 603	,8	,1	, &fEM_A1MC01RSP},	//(A1MC01RSP) Стартовая координата  ББ1
	{ 604	,8	,1	, &fEM_A1MC02RSP},	//(A1MC02RSP) Стартовая координата штока ББ1
	{ 605	,8	,1	, &fEM_B1MC01RSP},	//(B1MC01RSP) Стартовая координата  ББ2
	{ 606	,8	,1	, &fEM_B1MC02RSP},	//(B1MC02RSP) Стартовая координата штока ББ2
	{ 607	,8	,1	, &fEM_A2MC01RC1},	//(A2MC01RC1) Заданная координата РБ1 от ИС
	{ 608	,8	,1	, &fEM_A2MV01RC1},	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
	{ 609	,8	,1	, &fEM_A2MC01RSP},	//(A2MC01RSP) Стартовая координата  РБ1
	{ 610	,8	,1	, &fEM_A2MC02RSP},	//(A2MC02RSP) Стартовая координата штока РБ1
	{ 611	,8	,1	, &fEM_B2MC01RSP},	//(B2MC01RSP) Стартовая координата  РБ2
	{ 612	,8	,1	, &fEM_B2MC02RSP},	//(B2MC02RSP) Стартовая координата штока РБ2
	{ 613	,8	,1	, &fEM_A3MC01RSP},	//(A3MC01RSP) Стартовая координата  ИС1
	{ 614	,8	,1	, &fEM_A3MC02RSP},	//(A3MC02RSP) Стартовая координата штока ИС1
	{ 615	,8	,1	, &fEM_B3MC01RSP},	//(B3MC01RSP) Стартовая координата  ИС2
	{ 616	,8	,1	, &fEM_B3MC02RSP},	//(B3MC02RSP) Стартовая координата штока ИС2
	{ 617	,8	,1	, &fEM_B8MC01RSP},	//(B8MC01RSP) Стартовая координата АЗ2
	{ 618	,8	,1	, &fEM_A8MC01RSP},	//(A8MC01RSP) Стартовая координата ДС2
	{ 619	,8	,1	, &fEM_A6MC01RSP},	//(A6MC01RSP) Стартовая координата БЗ1
	{ 620	,8	,1	, &fEM_B6MC01RSP},	//(B6MC01RSP) Стартовая координата БЗ2
	{ 621	,8	,1	, &fEM_R3UC01RSP},	//(R3UC01RSP) Стартовая координата Гомогенных дверей
	{ 622	,8	,1	, &fEM_R5UC01RSP},	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
	{ 623	,8	,1	, &fEM_R6UC01RSP},	//(R6UC01RSP) Стартовая координата Кран-балки
	{ 624	,8	,1	, &fEM_R2MC01RSP},	//(R2MC01RSP) Стартовая координата МДЗ2
	{ 625	,8	,1	, &fEM_R1MC01RSP},	//(R1MC01RSP) Стартовая координата МДЗ1
	{ 626	,8	,1	, &fEM_A5MC01RSP},	//(A5MC01RSP) Стартовая координата НЛ1
	{ 627	,8	,1	, &fEM_B5MC01RSP},	//(B5MC01RSP) Стартовая координата НЛ2
	{ 628	,8	,1	, &fEM_A9MC01RSP},	//(A9MC01RSP) Стартовая координата НИ ДС1
	{ 629	,8	,1	, &fEM_B9MC01RSP},	//(B9MC01RSP) Стартовая координата НИ ДС2
	{ 630	,8	,1	, &fEM_A4MC01RSP},	//(A4MC01RSP) Стартовая координата НИ1
	{ 631	,8	,1	, &fEM_B4MC01RSP},	//(B4MC01RSP) Стартовая координата НИ2
	{ 632	,8	,1	, &fEM_R4MC01RSP},	//(R4MC01RSP) Стартовая координата тележки
	{ 633	,8	,1	, &fEM_A1MV01RC1},	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
	{ 634	,3	,1	, &iEM_TERB7MS31LIM},	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{ 635	,3	,1	, &iEM_TERA7MS31LIM},	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{ 636	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 см
	{ 637	,3	,1	, &iEM_TERA6VS12LIM},	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{ 638	,3	,1	, &iEM_TERA6VS22LIM},	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{ 639	,3	,1	, &iEM_TERB6VS12LIM},	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{ 640	,3	,1	, &iEM_TERB6VS22LIM},	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{ 641	,3	,1	, &iEM_TERA5VS22LIM},	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
	{ 642	,3	,1	, &iEM_TERA5VS12LIM},	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
	{ 643	,3	,1	, &iEM_TERB5VS12LIM},	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
	{ 644	,3	,1	, &iEM_TERB5VS22LIM},	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
	{ 645	,3	,1	, &iEM_TERR1VS12LIM},	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
	{ 646	,3	,1	, &iEM_TERR1VS22LIM},	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
	{ 647	,3	,1	, &iEM_TERR2VS12LIM},	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
	{ 648	,3	,1	, &iEM_TERR2VS22LIM},	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
	{ 649	,3	,1	, &iEM_TERR4VS12LDU},	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{ 650	,3	,1	, &iEM_TERR4VS22LDU},	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{ 651	,8	,1	, &fEM_R4UC23RIM},	//(R4UC23RIM) Y-координата АЗ1
	{ 652	,8	,1	, &fEM_A0UX13RSS},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{ 653	,8	,1	, &fEM_A0UX14RSS},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{ 654	,8	,1	, &fEM_A0UX15RSS},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{ 655	,8	,1	, &fEM_R7UX13RSS},	//(R7UX13RSS) X-координата камеры R7IN51
	{ 656	,8	,1	, &fEM_R7UX14RSS},	//(R7UX14RSS) X-координата камеры R7IN52
	{ 657	,8	,1	, &fEM_R7UX15RSS},	//(R7UX15RSS) X-координата камеры R7IN53
	{ 658	,8	,1	, &fEM_R7UY13RSS},	//(R7UY13RSS) Y-координата камеры R7IN51
	{ 659	,8	,1	, &fEM_R7UY14RSS},	//(R7UY14RSS) Y-координата камеры R7IN52
	{ 660	,8	,1	, &fEM_R7UY15RSS},	//(R7UY15RSS) Y-координата камеры R7IN53
	{ 661	,8	,1	, &fEM_R7UX16RSS},	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
	{ 662	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 663	,8	,1	, &internal1_m872_Chim0},	//(internal1_m872_Chim0) измеренная частота импульсов камеры Гц
	{ 664	,8	,1	, &internal1_m862_Chim0},	//(internal1_m862_Chim0) измеренная частота импульсов камеры Гц
	{ 665	,8	,1	, &internal1_m854_Chim0},	//(internal1_m854_Chim0) измеренная частота импульсов камеры Гц
	{ 666	,1	,1	, &internal1_m809_Out10},	//(internal1_m809_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 667	,1	,1	, &internal1_m808_Out10},	//(internal1_m808_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 668	,1	,1	, &internal1_m991_Out10},	//(internal1_m991_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 669	,1	,1	, &internal1_m990_Out10},	//(internal1_m990_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 670	,1	,1	, &internal1_m989_Out10},	//(internal1_m989_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 671	,1	,1	, &internal1_m988_Out10},	//(internal1_m988_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 672	,1	,1	, &internal1_m668_Out10},	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 673	,1	,1	, &internal1_m667_Out10},	//(internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 674	,1	,1	, &internal1_m646_Out10},	//(internal1_m646_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 675	,1	,1	, &internal1_m645_Out10},	//(internal1_m645_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 676	,1	,1	, &internal1_m666_Out10},	//(internal1_m666_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 677	,1	,1	, &internal1_m665_Out10},	//(internal1_m665_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 678	,1	,1	, &internal1_m644_Out10},	//(internal1_m644_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 679	,1	,1	, &internal1_m643_Out10},	//(internal1_m643_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 680	,1	,1	, &internal1_m510_Out10},	//(internal1_m510_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 681	,1	,1	, &internal1_m526_Out10},	//(internal1_m526_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 682	,1	,1	, &internal1_m398_Out10},	//(internal1_m398_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 683	,1	,1	, &internal1_m471_q0},	//(internal1_m471_q0) q0 - внутренний параметр
	{ 684	,1	,1	, &internal1_m472_q0},	//(internal1_m472_q0) q0 - внутренний параметр
	{ 685	,1	,1	, &internal1_m459_q0},	//(internal1_m459_q0) q0 - внутренний параметр
	{ 686	,1	,1	, &internal1_m460_q0},	//(internal1_m460_q0) q0 - внутренний параметр
	{ 687	,8	,1	, &internal1_m619_tx},	//(internal1_m619_tx) tx - время накопленное сек
	{ 688	,18	,1	, &internal1_m619_y0},	//(internal1_m619_y0) y0
	{ 689	,8	,1	, &internal1_m607_tx},	//(internal1_m607_tx) tx - время накопленное сек
	{ 690	,18	,1	, &internal1_m607_y0},	//(internal1_m607_y0) y0
	{ 691	,8	,1	, &internal1_m595_tx},	//(internal1_m595_tx) tx - время накопленное сек
	{ 692	,18	,1	, &internal1_m595_y0},	//(internal1_m595_y0) y0
	{ 693	,8	,1	, &internal1_m593_tx},	//(internal1_m593_tx) tx - время накопленное сек
	{ 694	,18	,1	, &internal1_m593_y0},	//(internal1_m593_y0) y0
	{ 695	,1	,1	, &internal1_m203_Out10},	//(internal1_m203_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 696	,1	,1	, &internal1_m221_Out10},	//(internal1_m221_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 697	,1	,1	, &internal1_m41_Out10},	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 698	,1	,1	, &internal1_m56_Out10},	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 699	,1	,1	, &internal1_m962_Out10},	//(internal1_m962_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 700	,1	,1	, &internal1_m959_Out10},	//(internal1_m959_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 701	,1	,1	, &internal1_m958_Out10},	//(internal1_m958_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 702	,8	,1	, &internal1_m961_Xtek0},	//(internal1_m961_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 703	,8	,1	, &internal1_m944_Xtek0},	//(internal1_m944_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 704	,1	,1	, &internal1_m945_Out10},	//(internal1_m945_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 705	,1	,1	, &internal1_m942_Out10},	//(internal1_m942_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 706	,1	,1	, &internal1_m941_Out10},	//(internal1_m941_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 707	,1	,1	, &internal1_m1029_Out10},	//(internal1_m1029_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 708	,1	,1	, &internal1_m1010_Out10},	//(internal1_m1010_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 709	,1	,1	, &internal1_m1009_Out10},	//(internal1_m1009_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 710	,1	,1	, &internal1_m1008_Out10},	//(internal1_m1008_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 711	,1	,1	, &internal1_m830_Out10},	//(internal1_m830_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 712	,1	,1	, &internal1_m832_Out10},	//(internal1_m832_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 713	,1	,1	, &internal1_m829_Out10},	//(internal1_m829_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 714	,1	,1	, &internal1_m831_Out10},	//(internal1_m831_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 715	,1	,1	, &internal1_m805_Out10},	//(internal1_m805_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 716	,1	,1	, &internal1_m806_Out10},	//(internal1_m806_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 717	,1	,1	, &internal1_m804_Out10},	//(internal1_m804_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 718	,1	,1	, &internal1_m803_Out10},	//(internal1_m803_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 719	,1	,1	, &internal1_m1024_Out10},	//(internal1_m1024_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 720	,1	,1	, &internal1_m976_Out10},	//(internal1_m976_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 721	,1	,1	, &internal1_m975_Out10},	//(internal1_m975_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 722	,1	,1	, &internal1_m974_Out10},	//(internal1_m974_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 723	,1	,1	, &internal1_m973_Out10},	//(internal1_m973_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 724	,1	,1	, &internal1_m1025_Out10},	//(internal1_m1025_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 725	,1	,1	, &internal1_m1006_Out10},	//(internal1_m1006_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 726	,1	,1	, &internal1_m807_Out10},	//(internal1_m807_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 727	,1	,1	, &internal1_m1007_Out10},	//(internal1_m1007_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 728	,1	,1	, &internal1_m1005_Out10},	//(internal1_m1005_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 729	,1	,1	, &internal1_m1026_Out10},	//(internal1_m1026_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 730	,1	,1	, &internal1_m1004_Out10},	//(internal1_m1004_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 731	,1	,1	, &internal1_m987_Out10},	//(internal1_m987_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 732	,1	,1	, &internal1_m972_Out10},	//(internal1_m972_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 733	,1	,1	, &internal1_m527_Out10},	//(internal1_m527_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 734	,8	,1	, &internal1_m408_Xtek0},	//(internal1_m408_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 735	,1	,1	, &internal1_m399_Out10},	//(internal1_m399_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 736	,1	,1	, &internal1_m401_Out10},	//(internal1_m401_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 737	,1	,1	, &internal1_m400_Out10},	//(internal1_m400_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 738	,1	,1	, &internal1_m845_Out10},	//(internal1_m845_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 739	,1	,1	, &internal1_m846_Out10},	//(internal1_m846_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 740	,1	,1	, &internal1_m844_Out10},	//(internal1_m844_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 741	,1	,1	, &internal1_m1028_Out10},	//(internal1_m1028_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 742	,1	,1	, &internal1_m681_Out10},	//(internal1_m681_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 743	,1	,1	, &internal1_m682_Out10},	//(internal1_m682_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 744	,1	,1	, &internal1_m679_Out10},	//(internal1_m679_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 745	,1	,1	, &internal1_m680_Out10},	//(internal1_m680_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 746	,1	,1	, &internal1_m543_Out10},	//(internal1_m543_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 747	,1	,1	, &internal1_m542_Out10},	//(internal1_m542_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 748	,8	,1	, &internal1_m826_Xtek0},	//(internal1_m826_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 749	,8	,1	, &internal1_m828_Xtek0},	//(internal1_m828_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 750	,1	,1	, &internal1_m678_Out10},	//(internal1_m678_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 751	,1	,1	, &internal1_m662_Out10},	//(internal1_m662_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 752	,1	,1	, &internal1_m642_Out10},	//(internal1_m642_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 753	,1	,1	, &internal1_m661_Out10},	//(internal1_m661_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 754	,1	,1	, &internal1_m641_Out10},	//(internal1_m641_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 755	,1	,1	, &internal1_m329_Out10},	//(internal1_m329_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 756	,1	,1	, &internal1_m328_Out10},	//(internal1_m328_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 757	,1	,1	, &internal1_m313_Out10},	//(internal1_m313_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 758	,1	,1	, &internal1_m312_Out10},	//(internal1_m312_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 759	,1	,1	, &internal1_m544_Out10},	//(internal1_m544_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 760	,1	,1	, &internal1_m342_Out10},	//(internal1_m342_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 761	,8	,1	, &internal1_m326_Xtek0},	//(internal1_m326_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 762	,1	,1	, &internal1_m341_Out10},	//(internal1_m341_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 763	,1	,1	, &internal1_m339_Out10},	//(internal1_m339_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 764	,8	,1	, &internal1_m319_Xtek0},	//(internal1_m319_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 765	,1	,1	, &internal1_m340_Out10},	//(internal1_m340_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 766	,1	,1	, &internal1_m311_Out10},	//(internal1_m311_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 767	,1	,1	, &internal1_m327_Out10},	//(internal1_m327_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 768	,1	,1	, &internal1_m420_Out10},	//(internal1_m420_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 769	,8	,1	, &internal1_m421_Xtek0},	//(internal1_m421_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 770	,1	,1	, &internal1_m419_Out10},	//(internal1_m419_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 771	,1	,1	, &internal1_m418_Out10},	//(internal1_m418_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 772	,1	,1	, &internal1_m417_Out10},	//(internal1_m417_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 773	,1	,1	, &internal1_m1027_Out10},	//(internal1_m1027_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 774	,1	,1	, &internal1_m145_Out10},	//(internal1_m145_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 775	,1	,1	, &internal1_m144_Out10},	//(internal1_m144_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 776	,3	,1	, &internal1_m192_tx},	//(internal1_m192_tx) tx - внутренний параметр
	{ 777	,3	,1	, &internal1_m25_tx},	//(internal1_m25_tx) tx - внутренний параметр
	{ 778	,8	,1	, &internal1_m465_X00},	//(internal1_m465_X00)  X00 - текущая координата механизма
	{ 779	,8	,1	, &internal1_m465_V00},	//(internal1_m465_V00)  V00 - текущая скорость механизма
	{ 780	,1	,1	, &internal1_m465_Pav0},	//(internal1_m465_Pav0)  - Пер.аварийный выключатель механизма
	{ 781	,1	,1	, &internal1_m465_Zav0},	//(internal1_m465_Zav0)  - Зад.аварийный выключатель механизма
	{ 782	,1	,1	, &internal1_m465_Pv0},	//(internal1_m465_Pv0)  - Пер. выключатель механизма
	{ 783	,1	,1	, &internal1_m465_Zv0},	//(internal1_m465_Zv0)  - Зад. выключатель механизма
	{ 784	,1	,1	, &internal1_m465_RA00},	//(internal1_m465_RA00)  - последнее задание вперед
	{ 785	,1	,1	, &internal1_m465_RA10},	//(internal1_m465_RA10)  - последнее задание назад
	{ 786	,1	,1	, &internal1_m465_MyFirstEnterFlag},	//(internal1_m465_MyFirstEnterFlag) MyFirstEnterFlag
	{ 787	,8	,1	, &internal1_m475_X00},	//(internal1_m475_X00)  X00 - текущая координата механизма
	{ 788	,8	,1	, &internal1_m475_V00},	//(internal1_m475_V00)  V00 - текущая скорость механизма
	{ 789	,1	,1	, &internal1_m475_Pav0},	//(internal1_m475_Pav0)  - Пер.аварийный выключатель механизма
	{ 790	,1	,1	, &internal1_m475_Zav0},	//(internal1_m475_Zav0)  - Зад.аварийный выключатель механизма
	{ 791	,1	,1	, &internal1_m475_Pv0},	//(internal1_m475_Pv0)  - Пер. выключатель механизма
	{ 792	,1	,1	, &internal1_m475_Zv0},	//(internal1_m475_Zv0)  - Зад. выключатель механизма
	{ 793	,1	,1	, &internal1_m475_RA00},	//(internal1_m475_RA00)  - последнее задание вперед
	{ 794	,1	,1	, &internal1_m475_RA10},	//(internal1_m475_RA10)  - последнее задание назад
	{ 795	,1	,1	, &internal1_m475_MyFirstEnterFlag},	//(internal1_m475_MyFirstEnterFlag) MyFirstEnterFlag
	{ 796	,8	,1	, &internal1_m464_X00},	//(internal1_m464_X00)  X00 - текущая координата механизма
	{ 797	,8	,1	, &internal1_m464_V00},	//(internal1_m464_V00)  V00 - текущая скорость механизма
	{ 798	,1	,1	, &internal1_m464_Pav0},	//(internal1_m464_Pav0)  - Пер.аварийный выключатель механизма
	{ 799	,1	,1	, &internal1_m464_Zav0},	//(internal1_m464_Zav0)  - Зад.аварийный выключатель механизма
	{ 800	,1	,1	, &internal1_m464_Pv0},	//(internal1_m464_Pv0)  - Пер. выключатель механизма
	{ 801	,1	,1	, &internal1_m464_Zv0},	//(internal1_m464_Zv0)  - Зад. выключатель механизма
	{ 802	,1	,1	, &internal1_m464_RA00},	//(internal1_m464_RA00)  - последнее задание вперед
	{ 803	,1	,1	, &internal1_m464_RA10},	//(internal1_m464_RA10)  - последнее задание назад
	{ 804	,1	,1	, &internal1_m464_MyFirstEnterFlag},	//(internal1_m464_MyFirstEnterFlag) MyFirstEnterFlag
	{ 805	,8	,1	, &internal1_m598_X00},	//(internal1_m598_X00)  X00 - текущая координата механизма
	{ 806	,8	,1	, &internal1_m598_V00},	//(internal1_m598_V00)  V00 - текущая скорость механизма
	{ 807	,1	,1	, &internal1_m598_Pav0},	//(internal1_m598_Pav0)  - Пер.аварийный выключатель механизма
	{ 808	,1	,1	, &internal1_m598_Zav0},	//(internal1_m598_Zav0)  - Зад.аварийный выключатель механизма
	{ 809	,1	,1	, &internal1_m598_Pv0},	//(internal1_m598_Pv0)  - Пер. выключатель механизма
	{ 810	,1	,1	, &internal1_m598_Zv0},	//(internal1_m598_Zv0)  - Зад. выключатель механизма
	{ 811	,1	,1	, &internal1_m598_RA00},	//(internal1_m598_RA00)  - последнее задание вперед
	{ 812	,1	,1	, &internal1_m598_RA10},	//(internal1_m598_RA10)  - последнее задание назад
	{ 813	,1	,1	, &internal1_m598_MyFirstEnterFlag},	//(internal1_m598_MyFirstEnterFlag) MyFirstEnterFlag
	{ 814	,8	,1	, &internal1_m597_X00},	//(internal1_m597_X00)  X00 - текущая координата механизма
	{ 815	,8	,1	, &internal1_m597_V00},	//(internal1_m597_V00)  V00 - текущая скорость механизма
	{ 816	,1	,1	, &internal1_m597_Pav0},	//(internal1_m597_Pav0)  - Пер.аварийный выключатель механизма
	{ 817	,1	,1	, &internal1_m597_Zav0},	//(internal1_m597_Zav0)  - Зад.аварийный выключатель механизма
	{ 818	,1	,1	, &internal1_m597_Pv0},	//(internal1_m597_Pv0)  - Пер. выключатель механизма
	{ 819	,1	,1	, &internal1_m597_Zv0},	//(internal1_m597_Zv0)  - Зад. выключатель механизма
	{ 820	,1	,1	, &internal1_m597_RA00},	//(internal1_m597_RA00)  - последнее задание вперед
	{ 821	,1	,1	, &internal1_m597_RA10},	//(internal1_m597_RA10)  - последнее задание назад
	{ 822	,1	,1	, &internal1_m597_MyFirstEnterFlag},	//(internal1_m597_MyFirstEnterFlag) MyFirstEnterFlag
	{ 823	,8	,1	, &internal1_m585_X00},	//(internal1_m585_X00)  X00 - текущая координата механизма
	{ 824	,8	,1	, &internal1_m585_V00},	//(internal1_m585_V00)  V00 - текущая скорость механизма
	{ 825	,1	,1	, &internal1_m585_Pav0},	//(internal1_m585_Pav0)  - Пер.аварийный выключатель механизма
	{ 826	,1	,1	, &internal1_m585_Zav0},	//(internal1_m585_Zav0)  - Зад.аварийный выключатель механизма
	{ 827	,1	,1	, &internal1_m585_Pv0},	//(internal1_m585_Pv0)  - Пер. выключатель механизма
	{ 828	,1	,1	, &internal1_m585_Zv0},	//(internal1_m585_Zv0)  - Зад. выключатель механизма
	{ 829	,1	,1	, &internal1_m585_RA00},	//(internal1_m585_RA00)  - последнее задание вперед
	{ 830	,1	,1	, &internal1_m585_RA10},	//(internal1_m585_RA10)  - последнее задание назад
	{ 831	,1	,1	, &internal1_m585_MyFirstEnterFlag},	//(internal1_m585_MyFirstEnterFlag) MyFirstEnterFlag
	{ 832	,8	,1	, &internal1_m584_X00},	//(internal1_m584_X00)  X00 - текущая координата механизма
	{ 833	,8	,1	, &internal1_m584_V00},	//(internal1_m584_V00)  V00 - текущая скорость механизма
	{ 834	,1	,1	, &internal1_m584_Pav0},	//(internal1_m584_Pav0)  - Пер.аварийный выключатель механизма
	{ 835	,1	,1	, &internal1_m584_Zav0},	//(internal1_m584_Zav0)  - Зад.аварийный выключатель механизма
	{ 836	,1	,1	, &internal1_m584_Pv0},	//(internal1_m584_Pv0)  - Пер. выключатель механизма
	{ 837	,1	,1	, &internal1_m584_Zv0},	//(internal1_m584_Zv0)  - Зад. выключатель механизма
	{ 838	,1	,1	, &internal1_m584_RA00},	//(internal1_m584_RA00)  - последнее задание вперед
	{ 839	,1	,1	, &internal1_m584_RA10},	//(internal1_m584_RA10)  - последнее задание назад
	{ 840	,1	,1	, &internal1_m584_MyFirstEnterFlag},	//(internal1_m584_MyFirstEnterFlag) MyFirstEnterFlag
	{ 841	,8	,1	, &internal1_m627_y0},	//(internal1_m627_y0) y0 - внутренний параметр
	{ 842	,8	,1	, &internal1_m791_Chim0},	//(internal1_m791_Chim0) измеренная частота импульсов камеры Гц
	{ 843	,8	,1	, &internal1_m782_Chim0},	//(internal1_m782_Chim0) измеренная частота импульсов камеры Гц
	{ 844	,8	,1	, &internal1_m774_Chim0},	//(internal1_m774_Chim0) измеренная частота импульсов камеры Гц
	{ 845	,8	,1	, &internal1_m765_Chim0},	//(internal1_m765_Chim0) измеренная частота импульсов камеры Гц
	{ 846	,8	,1	, &internal1_m756_Chim0},	//(internal1_m756_Chim0) измеренная частота импульсов камеры Гц
	{ 847	,8	,1	, &internal1_m748_Chim0},	//(internal1_m748_Chim0) измеренная частота импульсов камеры Гц
	{ 848	,8	,1	, &internal1_m739_Chim0},	//(internal1_m739_Chim0) измеренная частота импульсов камеры Гц
	{ 849	,8	,1	, &internal1_m730_Chim0},	//(internal1_m730_Chim0) измеренная частота импульсов камеры Гц
	{ 850	,8	,1	, &internal1_m722_Chim0},	//(internal1_m722_Chim0) измеренная частота импульсов камеры Гц
	{ 851	,8	,1	, &internal1_m713_Chim0},	//(internal1_m713_Chim0) измеренная частота импульсов камеры Гц
	{ 852	,8	,1	, &internal1_m704_Chim0},	//(internal1_m704_Chim0) измеренная частота импульсов камеры Гц
	{ 853	,8	,1	, &internal1_m694_Chim0},	//(internal1_m694_Chim0) измеренная частота импульсов камеры Гц
	{ 854	,8	,1	, &internal1_m572_X00},	//(internal1_m572_X00)  X00 - текущая координата механизма
	{ 855	,8	,1	, &internal1_m572_V00},	//(internal1_m572_V00)  V00 - текущая скорость механизма
	{ 856	,1	,1	, &internal1_m572_Pav0},	//(internal1_m572_Pav0)  - Пер.аварийный выключатель механизма
	{ 857	,1	,1	, &internal1_m572_Zav0},	//(internal1_m572_Zav0)  - Зад.аварийный выключатель механизма
	{ 858	,1	,1	, &internal1_m572_Pv0},	//(internal1_m572_Pv0)  - Пер. выключатель механизма
	{ 859	,1	,1	, &internal1_m572_Zv0},	//(internal1_m572_Zv0)  - Зад. выключатель механизма
	{ 860	,1	,1	, &internal1_m572_RA00},	//(internal1_m572_RA00)  - последнее задание вперед
	{ 861	,1	,1	, &internal1_m572_RA10},	//(internal1_m572_RA10)  - последнее задание назад
	{ 862	,1	,1	, &internal1_m572_MyFirstEnterFlag},	//(internal1_m572_MyFirstEnterFlag) MyFirstEnterFlag
	{ 863	,8	,1	, &internal1_m558_X00},	//(internal1_m558_X00)  X00 - текущая координата механизма
	{ 864	,8	,1	, &internal1_m558_V00},	//(internal1_m558_V00)  V00 - текущая скорость механизма
	{ 865	,1	,1	, &internal1_m558_Pav0},	//(internal1_m558_Pav0)  - Пер.аварийный выключатель механизма
	{ 866	,1	,1	, &internal1_m558_Zav0},	//(internal1_m558_Zav0)  - Зад.аварийный выключатель механизма
	{ 867	,1	,1	, &internal1_m558_Pv0},	//(internal1_m558_Pv0)  - Пер. выключатель механизма
	{ 868	,1	,1	, &internal1_m558_Zv0},	//(internal1_m558_Zv0)  - Зад. выключатель механизма
	{ 869	,1	,1	, &internal1_m558_RA00},	//(internal1_m558_RA00)  - последнее задание вперед
	{ 870	,1	,1	, &internal1_m558_RA10},	//(internal1_m558_RA10)  - последнее задание назад
	{ 871	,1	,1	, &internal1_m558_MyFirstEnterFlag},	//(internal1_m558_MyFirstEnterFlag) MyFirstEnterFlag
	{ 872	,8	,1	, &internal1_m449_X00},	//(internal1_m449_X00)  X00 - текущая координата механизма
	{ 873	,8	,1	, &internal1_m449_V00},	//(internal1_m449_V00)  V00 - текущая скорость механизма
	{ 874	,1	,1	, &internal1_m449_Pav0},	//(internal1_m449_Pav0)  - Пер.аварийный выключатель механизма
	{ 875	,1	,1	, &internal1_m449_Zav0},	//(internal1_m449_Zav0)  - Зад.аварийный выключатель механизма
	{ 876	,1	,1	, &internal1_m449_Pv0},	//(internal1_m449_Pv0)  - Пер. выключатель механизма
	{ 877	,1	,1	, &internal1_m449_Zv0},	//(internal1_m449_Zv0)  - Зад. выключатель механизма
	{ 878	,1	,1	, &internal1_m449_RA00},	//(internal1_m449_RA00)  - последнее задание вперед
	{ 879	,1	,1	, &internal1_m449_RA10},	//(internal1_m449_RA10)  - последнее задание назад
	{ 880	,1	,1	, &internal1_m449_MyFirstEnterFlag},	//(internal1_m449_MyFirstEnterFlag) MyFirstEnterFlag
	{ 881	,8	,1	, &internal1_m435_X00},	//(internal1_m435_X00)  X00 - текущая координата механизма
	{ 882	,8	,1	, &internal1_m435_V00},	//(internal1_m435_V00)  V00 - текущая скорость механизма
	{ 883	,1	,1	, &internal1_m435_Pav0},	//(internal1_m435_Pav0)  - Пер.аварийный выключатель механизма
	{ 884	,1	,1	, &internal1_m435_Zav0},	//(internal1_m435_Zav0)  - Зад.аварийный выключатель механизма
	{ 885	,1	,1	, &internal1_m435_Pv0},	//(internal1_m435_Pv0)  - Пер. выключатель механизма
	{ 886	,1	,1	, &internal1_m435_Zv0},	//(internal1_m435_Zv0)  - Зад. выключатель механизма
	{ 887	,1	,1	, &internal1_m435_RA00},	//(internal1_m435_RA00)  - последнее задание вперед
	{ 888	,1	,1	, &internal1_m435_RA10},	//(internal1_m435_RA10)  - последнее задание назад
	{ 889	,1	,1	, &internal1_m435_MyFirstEnterFlag},	//(internal1_m435_MyFirstEnterFlag) MyFirstEnterFlag
	{ 890	,8	,1	, &internal1_m486_X00},	//(internal1_m486_X00)  X00 - текущая координата механизма
	{ 891	,8	,1	, &internal1_m486_V00},	//(internal1_m486_V00)  V00 - текущая скорость механизма
	{ 892	,1	,1	, &internal1_m486_Pav0},	//(internal1_m486_Pav0)  - Пер.аварийный выключатель механизма
	{ 893	,1	,1	, &internal1_m486_Zav0},	//(internal1_m486_Zav0)  - Зад.аварийный выключатель механизма
	{ 894	,1	,1	, &internal1_m486_Pv0},	//(internal1_m486_Pv0)  - Пер. выключатель механизма
	{ 895	,1	,1	, &internal1_m486_Zv0},	//(internal1_m486_Zv0)  - Зад. выключатель механизма
	{ 896	,1	,1	, &internal1_m486_RA00},	//(internal1_m486_RA00)  - последнее задание вперед
	{ 897	,1	,1	, &internal1_m486_RA10},	//(internal1_m486_RA10)  - последнее задание назад
	{ 898	,1	,1	, &internal1_m486_MyFirstEnterFlag},	//(internal1_m486_MyFirstEnterFlag) MyFirstEnterFlag
	{ 899	,8	,1	, &internal1_m387_X00},	//(internal1_m387_X00)  X00 - текущая координата механизма
	{ 900	,8	,1	, &internal1_m387_V00},	//(internal1_m387_V00)  V00 - текущая скорость механизма
	{ 901	,1	,1	, &internal1_m387_Pav0},	//(internal1_m387_Pav0)  - Пер.аварийный выключатель механизма
	{ 902	,1	,1	, &internal1_m387_Zav0},	//(internal1_m387_Zav0)  - Зад.аварийный выключатель механизма
	{ 903	,1	,1	, &internal1_m387_Pv0},	//(internal1_m387_Pv0)  - Пер. выключатель механизма
	{ 904	,1	,1	, &internal1_m387_Zv0},	//(internal1_m387_Zv0)  - Зад. выключатель механизма
	{ 905	,1	,1	, &internal1_m387_RA00},	//(internal1_m387_RA00)  - последнее задание вперед
	{ 906	,1	,1	, &internal1_m387_RA10},	//(internal1_m387_RA10)  - последнее задание назад
	{ 907	,1	,1	, &internal1_m387_MyFirstEnterFlag},	//(internal1_m387_MyFirstEnterFlag) MyFirstEnterFlag
	{ 908	,8	,1	, &internal1_m372_X00},	//(internal1_m372_X00)  X00 - текущая координата механизма
	{ 909	,8	,1	, &internal1_m372_V00},	//(internal1_m372_V00)  V00 - текущая скорость механизма
	{ 910	,1	,1	, &internal1_m372_Pav0},	//(internal1_m372_Pav0)  - Пер.аварийный выключатель механизма
	{ 911	,1	,1	, &internal1_m372_Zav0},	//(internal1_m372_Zav0)  - Зад.аварийный выключатель механизма
	{ 912	,1	,1	, &internal1_m372_Pv0},	//(internal1_m372_Pv0)  - Пер. выключатель механизма
	{ 913	,1	,1	, &internal1_m372_Zv0},	//(internal1_m372_Zv0)  - Зад. выключатель механизма
	{ 914	,1	,1	, &internal1_m372_RA00},	//(internal1_m372_RA00)  - последнее задание вперед
	{ 915	,1	,1	, &internal1_m372_RA10},	//(internal1_m372_RA10)  - последнее задание назад
	{ 916	,1	,1	, &internal1_m372_MyFirstEnterFlag},	//(internal1_m372_MyFirstEnterFlag) MyFirstEnterFlag
	{ 917	,8	,1	, &internal1_m356_X00},	//(internal1_m356_X00)  X00 - текущая координата механизма
	{ 918	,8	,1	, &internal1_m356_V00},	//(internal1_m356_V00)  V00 - текущая скорость механизма
	{ 919	,1	,1	, &internal1_m356_Pav0},	//(internal1_m356_Pav0)  - Пер.аварийный выключатель механизма
	{ 920	,1	,1	, &internal1_m356_Zav0},	//(internal1_m356_Zav0)  - Зад.аварийный выключатель механизма
	{ 921	,1	,1	, &internal1_m356_Pv0},	//(internal1_m356_Pv0)  - Пер. выключатель механизма
	{ 922	,1	,1	, &internal1_m356_Zv0},	//(internal1_m356_Zv0)  - Зад. выключатель механизма
	{ 923	,1	,1	, &internal1_m356_RA00},	//(internal1_m356_RA00)  - последнее задание вперед
	{ 924	,1	,1	, &internal1_m356_RA10},	//(internal1_m356_RA10)  - последнее задание назад
	{ 925	,1	,1	, &internal1_m356_MyFirstEnterFlag},	//(internal1_m356_MyFirstEnterFlag) MyFirstEnterFlag
	{ 926	,8	,1	, &internal1_m884_X00},	//(internal1_m884_X00)  X00 - текущая координата механизма
	{ 927	,8	,1	, &internal1_m884_V00},	//(internal1_m884_V00)  V00 - текущая скорость механизма
	{ 928	,1	,1	, &internal1_m884_Pav0},	//(internal1_m884_Pav0)  - Пер.аварийный выключатель механизма
	{ 929	,1	,1	, &internal1_m884_Zav0},	//(internal1_m884_Zav0)  - Зад.аварийный выключатель механизма
	{ 930	,1	,1	, &internal1_m884_Pv0},	//(internal1_m884_Pv0)  - Пер. выключатель механизма
	{ 931	,1	,1	, &internal1_m884_Zv0},	//(internal1_m884_Zv0)  - Зад. выключатель механизма
	{ 932	,1	,1	, &internal1_m884_RA00},	//(internal1_m884_RA00)  - последнее задание вперед
	{ 933	,1	,1	, &internal1_m884_RA10},	//(internal1_m884_RA10)  - последнее задание назад
	{ 934	,1	,1	, &internal1_m884_MyFirstEnterFlag},	//(internal1_m884_MyFirstEnterFlag) MyFirstEnterFlag
	{ 935	,8	,1	, &internal1_m177_C1},	//(internal1_m177_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{ 936	,8	,1	, &internal1_m177_C2},	//(internal1_m177_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{ 937	,8	,1	, &internal1_m177_C3},	//(internal1_m177_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{ 938	,8	,1	, &internal1_m177_C4},	//(internal1_m177_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{ 939	,8	,1	, &internal1_m177_C5},	//(internal1_m177_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{ 940	,8	,1	, &internal1_m177_C6},	//(internal1_m177_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{ 941	,8	,1	, &internal1_m177_N20},	//(internal1_m177_N20) N20 - пред. концентрация нейтронов второй АЗ
	{ 942	,8	,6	, &internal1_m177_C0},	//(internal1_m177_C0) *C0 - пред. концентрация запаздывающих нейтронов
	{ 943	,1	,1	, &internal1_m177_ImpINI0},	//(internal1_m177_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{ 944	,1	,1	, &internal1_m177_MyFirstEnterFlag},	//(internal1_m177_MyFirstEnterFlag) MyFirstEnterFlag
	{ 945	,8	,1	, &internal1_m295_X00},	//(internal1_m295_X00) X0 - текущая координата ОРР
	{ 946	,8	,1	, &internal1_m295_Sh00},	//(internal1_m295_Sh00) Sh0 - текущая координата штока ОРР
	{ 947	,8	,1	, &internal1_m295_RV00},	//(internal1_m295_RV00) V0 - текущая скорость ОРР
	{ 948	,8	,1	, &internal1_m295_ShV00},	//(internal1_m295_ShV00) V0 - текущая скорость штока ОРР
	{ 949	,1	,1	, &internal1_m295_Ppv0},	//(internal1_m295_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 950	,1	,1	, &internal1_m295_Pav0},	//(internal1_m295_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 951	,1	,1	, &internal1_m295_Zav0},	//(internal1_m295_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 952	,1	,1	, &internal1_m295_RA00},	//(internal1_m295_RA00) RA00 - последнее задание вперед
	{ 953	,1	,1	, &internal1_m295_RA10},	//(internal1_m295_RA10) RA10 - последнее задание назад
	{ 954	,1	,1	, &internal1_m295_RA30},	//(internal1_m295_RA30)  RA30 - разрешение движения
	{ 955	,1	,1	, &internal1_m295_RA50},	//(internal1_m295_RA50) Ra50 - последнее задание скорости
	{ 956	,1	,1	, &internal1_m295_fls},	//(internal1_m295_fls)  fls - флаг одношагового режима
	{ 957	,1	,1	, &internal1_m295_flp},	//(internal1_m295_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 958	,1	,1	, &internal1_m295_MyFirstEnterFlag},	//(internal1_m295_MyFirstEnterFlag) MyFirstEnterFlag
	{ 959	,8	,1	, &internal1_m130_X00},	//(internal1_m130_X00) X0 - текущая координата ОРР
	{ 960	,8	,1	, &internal1_m130_Sh00},	//(internal1_m130_Sh00) Sh0 - текущая координата штока ОРР
	{ 961	,8	,1	, &internal1_m130_RV00},	//(internal1_m130_RV00) V0 - текущая скорость ОРР
	{ 962	,8	,1	, &internal1_m130_ShV00},	//(internal1_m130_ShV00) V0 - текущая скорость штока ОРР
	{ 963	,1	,1	, &internal1_m130_Ppv0},	//(internal1_m130_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 964	,1	,1	, &internal1_m130_Pav0},	//(internal1_m130_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 965	,1	,1	, &internal1_m130_Zav0},	//(internal1_m130_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 966	,1	,1	, &internal1_m130_RA00},	//(internal1_m130_RA00) RA00 - последнее задание вперед
	{ 967	,1	,1	, &internal1_m130_RA10},	//(internal1_m130_RA10) RA10 - последнее задание назад
	{ 968	,1	,1	, &internal1_m130_RA30},	//(internal1_m130_RA30)  RA30 - разрешение движения
	{ 969	,1	,1	, &internal1_m130_RA50},	//(internal1_m130_RA50) Ra50 - последнее задание скорости
	{ 970	,1	,1	, &internal1_m130_fls},	//(internal1_m130_fls)  fls - флаг одношагового режима
	{ 971	,1	,1	, &internal1_m130_flp},	//(internal1_m130_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 972	,1	,1	, &internal1_m130_MyFirstEnterFlag},	//(internal1_m130_MyFirstEnterFlag) MyFirstEnterFlag
	{ 973	,8	,1	, &internal1_m259_X00},	//(internal1_m259_X00) X0 - текущая координата ОРР
	{ 974	,8	,1	, &internal1_m259_Sh00},	//(internal1_m259_Sh00) Sh0 - текущая координата штока ОРР
	{ 975	,8	,1	, &internal1_m259_RV00},	//(internal1_m259_RV00) V0 - текущая скорость ОРР
	{ 976	,8	,1	, &internal1_m259_ShV00},	//(internal1_m259_ShV00) V0 - текущая скорость штока ОРР
	{ 977	,1	,1	, &internal1_m259_Ppv0},	//(internal1_m259_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 978	,1	,1	, &internal1_m259_Pav0},	//(internal1_m259_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 979	,1	,1	, &internal1_m259_Zav0},	//(internal1_m259_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 980	,1	,1	, &internal1_m259_RA00},	//(internal1_m259_RA00) RA00 - последнее задание вперед
	{ 981	,1	,1	, &internal1_m259_RA10},	//(internal1_m259_RA10) RA10 - последнее задание назад
	{ 982	,1	,1	, &internal1_m259_RA30},	//(internal1_m259_RA30)  RA30 - разрешение движения
	{ 983	,1	,1	, &internal1_m259_RA50},	//(internal1_m259_RA50) Ra50 - последнее задание скорости
	{ 984	,1	,1	, &internal1_m259_fls},	//(internal1_m259_fls)  fls - флаг одношагового режима
	{ 985	,1	,1	, &internal1_m259_flp},	//(internal1_m259_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 986	,1	,1	, &internal1_m259_MyFirstEnterFlag},	//(internal1_m259_MyFirstEnterFlag) MyFirstEnterFlag
	{ 987	,8	,1	, &internal1_m94_X00},	//(internal1_m94_X00) X0 - текущая координата ОРР
	{ 988	,8	,1	, &internal1_m94_Sh00},	//(internal1_m94_Sh00) Sh0 - текущая координата штока ОРР
	{ 989	,8	,1	, &internal1_m94_RV00},	//(internal1_m94_RV00) V0 - текущая скорость ОРР
	{ 990	,8	,1	, &internal1_m94_ShV00},	//(internal1_m94_ShV00) V0 - текущая скорость штока ОРР
	{ 991	,1	,1	, &internal1_m94_Ppv0},	//(internal1_m94_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 992	,1	,1	, &internal1_m94_Pav0},	//(internal1_m94_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 993	,1	,1	, &internal1_m94_Zav0},	//(internal1_m94_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 994	,1	,1	, &internal1_m94_RA00},	//(internal1_m94_RA00) RA00 - последнее задание вперед
	{ 995	,1	,1	, &internal1_m94_RA10},	//(internal1_m94_RA10) RA10 - последнее задание назад
	{ 996	,1	,1	, &internal1_m94_RA30},	//(internal1_m94_RA30)  RA30 - разрешение движения
	{ 997	,1	,1	, &internal1_m94_RA50},	//(internal1_m94_RA50) Ra50 - последнее задание скорости
	{ 998	,1	,1	, &internal1_m94_fls},	//(internal1_m94_fls)  fls - флаг одношагового режима
	{ 999	,1	,1	, &internal1_m94_flp},	//(internal1_m94_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1000	,1	,1	, &internal1_m94_MyFirstEnterFlag},	//(internal1_m94_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1001	,8	,1	, &internal1_m224_X00},	//(internal1_m224_X00) X0 - текущая координата ОРР
	{ 1002	,8	,1	, &internal1_m224_Sh00},	//(internal1_m224_Sh00) Sh0 - текущая координата штока ОРР
	{ 1003	,8	,1	, &internal1_m224_RV00},	//(internal1_m224_RV00) V0 - текущая скорость ОРР
	{ 1004	,8	,1	, &internal1_m224_ShV00},	//(internal1_m224_ShV00) V0 - текущая скорость штока ОРР
	{ 1005	,1	,1	, &internal1_m224_Ppv0},	//(internal1_m224_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1006	,1	,1	, &internal1_m224_Pav0},	//(internal1_m224_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1007	,1	,1	, &internal1_m224_Zav0},	//(internal1_m224_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1008	,1	,1	, &internal1_m224_RA00},	//(internal1_m224_RA00) RA00 - последнее задание вперед
	{ 1009	,1	,1	, &internal1_m224_RA10},	//(internal1_m224_RA10) RA10 - последнее задание назад
	{ 1010	,1	,1	, &internal1_m224_RA30},	//(internal1_m224_RA30)  RA30 - разрешение движения
	{ 1011	,1	,1	, &internal1_m224_RA50},	//(internal1_m224_RA50) Ra50 - последнее задание скорости
	{ 1012	,1	,1	, &internal1_m224_fls},	//(internal1_m224_fls)  fls - флаг одношагового режима
	{ 1013	,1	,1	, &internal1_m224_flp},	//(internal1_m224_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1014	,1	,1	, &internal1_m224_MyFirstEnterFlag},	//(internal1_m224_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1015	,8	,1	, &internal1_m59_X00},	//(internal1_m59_X00) X0 - текущая координата ОРР
	{ 1016	,8	,1	, &internal1_m59_Sh00},	//(internal1_m59_Sh00) Sh0 - текущая координата штока ОРР
	{ 1017	,8	,1	, &internal1_m59_RV00},	//(internal1_m59_RV00) V0 - текущая скорость ОРР
	{ 1018	,8	,1	, &internal1_m59_ShV00},	//(internal1_m59_ShV00) V0 - текущая скорость штока ОРР
	{ 1019	,1	,1	, &internal1_m59_Ppv0},	//(internal1_m59_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1020	,1	,1	, &internal1_m59_Pav0},	//(internal1_m59_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1021	,1	,1	, &internal1_m59_Zav0},	//(internal1_m59_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1022	,1	,1	, &internal1_m59_RA00},	//(internal1_m59_RA00) RA00 - последнее задание вперед
	{ 1023	,1	,1	, &internal1_m59_RA10},	//(internal1_m59_RA10) RA10 - последнее задание назад
	{ 1024	,1	,1	, &internal1_m59_RA30},	//(internal1_m59_RA30)  RA30 - разрешение движения
	{ 1025	,1	,1	, &internal1_m59_RA50},	//(internal1_m59_RA50) Ra50 - последнее задание скорости
	{ 1026	,1	,1	, &internal1_m59_fls},	//(internal1_m59_fls)  fls - флаг одношагового режима
	{ 1027	,1	,1	, &internal1_m59_flp},	//(internal1_m59_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1028	,1	,1	, &internal1_m59_MyFirstEnterFlag},	//(internal1_m59_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1029	,8	,1	, &internal1_m14_C1},	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{ 1030	,8	,1	, &internal1_m14_C2},	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{ 1031	,8	,1	, &internal1_m14_C3},	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{ 1032	,8	,1	, &internal1_m14_C4},	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{ 1033	,8	,1	, &internal1_m14_C5},	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{ 1034	,8	,1	, &internal1_m14_C6},	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{ 1035	,8	,1	, &internal1_m14_N20},	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
	{ 1036	,8	,6	, &internal1_m14_C0},	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
	{ 1037	,1	,1	, &internal1_m14_ImpINI0},	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{ 1038	,1	,1	, &internal1_m14_MyFirstEnterFlag},	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="scm.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{281,"fEM_R0UL01RIM\0"}, 
{282,"fEM_R0UN02RIM\0"}, 
{283,"fEM_A1UR01RIM\0"}, 
{284,"fEM_A1UR00RIM\0"}, 
{285,"fEM_A3UR00RIM\0"}, 
{286,"fEM_A3UR01RIM\0"}, 
{287,"fEM_R0UT01RIM\0"}, 
{288,"fEM_R0UT02RIM\0"}, 
{289,"fEM_R0UT04RIM\0"}, 
{290,"fEM_R0UT03RIM\0"}, 
{291,"fEM_R0UT05RIM\0"}, 
{292,"fEM_R0UT06RIM\0"}, 
{293,"fEM_A1UC02RDU\0"}, 
{294,"fEM_A1UC04RIM\0"}, 
{295,"fEM_A1UC05RIM\0"}, 
{296,"fEM_A1UC06RIM\0"}, 
{297,"fEM_A2UC06RIM\0"}, 
{298,"fEM_A2UC05RIM\0"}, 
{299,"fEM_A2UC04RIM\0"}, 
{300,"fEM_A2UC02RDU\0"}, 
{301,"fEM_A3UC06RIM\0"}, 
{302,"fEM_A3UC05RIM\0"}, 
{303,"fEM_A3UC04RIM\0"}, 
{304,"fEM_A3UC02RDU\0"}, 
{305,"fEM_R4UV80RDU\0"}, 
{306,"fEM_R4UC10RIM\0"}, 
{307,"fEM_R4UC20RIM\0"}, 
{308,"fEM_B8UC21RIM\0"}, 
{309,"fEM_B8UC20RIM\0"}, 
{310,"fEM_B8UC11RIM\0"}, 
{311,"fEM_B8UC10RIM\0"}, 
{312,"fEM_B8UV80RDU\0"}, 
{313,"fEM_A8UV80RDU\0"}, 
{314,"fEM_A8UC10RIM\0"}, 
{315,"fEM_A8UC11RIM\0"}, 
{316,"fEM_A8UC20RIM\0"}, 
{317,"fEM_A8UC21RIM\0"}, 
{318,"fEM_A6UC10RIM\0"}, 
{319,"fEM_R1UC10RIM\0"}, 
{320,"fEM_A5UC10RIM\0"}, 
{321,"fEM_A0UN01RIM\0"}, 
{322,"fEM_R4UC22RIM\0"}, 
{323,"fEM_A1UG01RDU\0"}, 
{324,"fEM_A2UG01RDU\0"}, 
{325,"fEM_A3UG01RDU\0"}, 
{326,"fEM_R7UC10RIM\0"}, 
{327,"fEM_R7UC19RIM\0"}, 
{328,"fEM_R7UI02RIM\0"}, 
{329,"fEM_R7UL01RIM\0"}, 
{330,"fEM_A2UR00RIM\0"}, 
{331,"fEM_A2UR01RIM\0"}, 
{332,"fEM_A0UN02RIM\0"}, 
{333,"fEM_R0UR30RIM\0"}, 
{334,"fEM_R0UR01RIM\0"}, 
{335,"fEM_R0UT02RDU\0"}, 
{336,"fEM_R0UT01RDU\0"}, 
{337,"fEM_A1UC03RDU\0"}, 
{338,"fEM_A2UP03RDU\0"}, 
{339,"fEM_A2UP04RDU\0"}, 
{340,"fEM_A2UC03RDU\0"}, 
{341,"fEM_A3UP03RDU\0"}, 
{342,"fEM_A3UP04RDU\0"}, 
{343,"fEM_A3UC03RDU\0"}, 
{344,"fEM_R7UI74RIM\0"}, 
{345,"fEM_A8UC03RDU\0"}, 
{346,"fEM_R0UV87RDU\0"}, 
{347,"fEM_R0UV81RDU\0"}, 
{348,"fEM_R0UV82RDU\0"}, 
{349,"fEM_R0UV83RDU\0"}, 
{350,"fEM_R0UV84RDU\0"}, 
{351,"fEM_R0UV85RDU\0"}, 
{352,"fEM_R0UV86RDU\0"}, 
{353,"fEM_A8UC08RDU\0"}, 
{354,"fEM_B8UC08RDU\0"}, 
{355,"fEM_R4UC08RDU\0"}, 
{356,"fEM_R0UH01RSS\0"}, 
{357,"fEM_A0UX00RSS\0"}, 
{358,"fEM_R7UX01RSS\0"}, 
{359,"fEM_R7UX02RSS\0"}, 
{360,"fEM_R7UX04RSS\0"}, 
{361,"fEM_R7UX05RSS\0"}, 
{362,"fEM_R7UX06RSS\0"}, 
{363,"fEM_R7UX07RSS\0"}, 
{364,"fEM_R7UX08RSS\0"}, 
{365,"fEM_R7UX09RSS\0"}, 
{366,"fEM_R7UY01RSS\0"}, 
{367,"fEM_R7UY02RSS\0"}, 
{368,"fEM_R7UY04RSS\0"}, 
{369,"fEM_R7UY05RSS\0"}, 
{370,"fEM_R7UY06RSS\0"}, 
{371,"fEM_R7UY07RSS\0"}, 
{372,"fEM_R7UY08RSS\0"}, 
{373,"fEM_R7UY09RSS\0"}, 
{374,"fEM_R7UX10RSS\0"}, 
{375,"fEM_R7UX11RSS\0"}, 
{376,"fEM_R7UX12RSS\0"}, 
{377,"fEM_R7UY10RSS\0"}, 
{378,"fEM_R7UY11RSS\0"}, 
{379,"fEM_R7UY12RSS\0"}, 
{380,"fEM_A0UX01RSS\0"}, 
{381,"fEM_A0UX02RSS\0"}, 
{382,"fEM_A0UX03RSS\0"}, 
{383,"fEM_A0UX04RSS\0"}, 
{384,"fEM_A0UX05RSS\0"}, 
{385,"fEM_A0UX06RSS\0"}, 
{386,"fEM_A0UX07RSS\0"}, 
{387,"fEM_A0UX08RSS\0"}, 
{388,"fEM_A0UX09RSS\0"}, 
{389,"fEM_A0UX10RSS\0"}, 
{390,"fEM_A0UX11RSS\0"}, 
{391,"fEM_A0UX12RSS\0"}, 
{392,"fEM_B0UX01RSS\0"}, 
{393,"fEM_B0UX02RSS\0"}, 
{394,"fEM_B0UX03RSS\0"}, 
{395,"fEM_B0UX04RSS\0"}, 
{396,"fEM_B0UX05RSS\0"}, 
{397,"fEM_B0UX06RSS\0"}, 
{398,"fEM_B0UX07RSS\0"}, 
{399,"fEM_B0UX08RSS\0"}, 
{400,"fEM_B0UX09RSS\0"}, 
{401,"fEM_B0UX10RSS\0"}, 
{402,"fEM_B0UX11RSS\0"}, 
{403,"fEM_B0UX12RSS\0"}, 
{404,"fEM_R0UH02RSS\0"}, 
{405,"fEM_R0UH03RSS\0"}, 
{406,"fEM_R4US80RDU\0"}, 
{407,"fEM_R7UI71RIM\0"}, 
{408,"fEM_R7UI72RIM\0"}, 
{409,"fEM_R7UI73RIM\0"}, 
{410,"fEM_A1UP01RIM\0"}, 
{411,"fEM_A2UP01RIM\0"}, 
{412,"fEM_A0UP02RIM\0"}, 
{413,"fEM_A3UP01RIM\0"}, 
{414,"fEM_A1UP82RIM\0"}, 
{415,"fEM_A3UP02RDU\0"}, 
{416,"fEM_A1UV02RIM\0"}, 
{417,"fEM_A3UV02RIM\0"}, 
{418,"fEM_A2UV02RIM\0"}, 
{419,"fEM_B8US80RDU\0"}, 
{420,"fEM_A8US80RDU\0"}, 
{421,"fEM_A6US80RDU\0"}, 
{422,"fEM_A1US07RDU\0"}, 
{423,"fEM_A2US07RDU\0"}, 
{424,"fEM_A3US07RDU\0"}, 
{425,"fEM_R7UI75RIM\0"}, 
{426,"fEM_R0UH21RSS\0"}, 
{427,"fEM_R0UH22RSS\0"}, 
{428,"fEM_R0UH23RSS\0"}, 
{429,"fEM_R0UH05RSS\0"}, 
{430,"fEM_A4UL10RIM\0"}, 
{431,"fEM_A9UL10RIM\0"}, 
{432,"fEM_R3UL10RIM\0"}, 
{433,"fEM_R5UL10RIM\0"}, 
{434,"fEM_R6UL10RIM\0"}, 
{435,"lEM_C1AD31LRP\0"}, 
{436,"lEM_R0IE01LRP\0"}, 
{437,"lEM_R0IE02LRP\0"}, 
{438,"fEM_A2UP02RIM\0"}, 
{439,"fEM_A2UP03RIM\0"}, 
{440,"fEM_A0UP01RIM\0"}, 
{441,"fEM_A3UP02RIM\0"}, 
{442,"fEM_A4UP01RIM\0"}, 
{443,"fEM_A4UP02RIM\0"}, 
{444,"fEM_R7UI76RIM\0"}, 
{445,"fEM_R7UI77RIM\0"}, 
{446,"iEM_TERBB1\0"}, 
{447,"fEM_A1MC02RC1\0"}, 
{448,"fEM_A1MV02RC1\0"}, 
{449,"iEM_TERBB2\0"}, 
{450,"fEM_B1MC02RC1\0"}, 
{451,"fEM_B1MV02RC1\0"}, 
{452,"iEM_TERRB2\0"}, 
{453,"fEM_B2MC02RC1\0"}, 
{454,"fEM_B2MV02RC1\0"}, 
{455,"iEM_TERRB1\0"}, 
{456,"fEM_A2MC02RC1\0"}, 
{457,"fEM_A2MV02RC1\0"}, 
{458,"iEM_TERIS2\0"}, 
{459,"fEM_B3MC02RC1\0"}, 
{460,"fEM_B3MV02RC1\0"}, 
{461,"iEM_TERIS1\0"}, 
{462,"fEM_A3MC02RC1\0"}, 
{463,"fEM_A3MV02RC1\0"}, 
{464,"iEM_TERA1IE04LDU\0"}, 
{465,"iEM_TERA1IE03LDU\0"}, 
{466,"fEM_A1MC01RC1\0"}, 
{467,"iEM_TERB1IE03LDU\0"}, 
{468,"iEM_TERB1IE04LDU\0"}, 
{469,"fEM_B1MC01RC1\0"}, 
{470,"fEM_B1MV01RC1\0"}, 
{471,"fEM_B2MC01RC1\0"}, 
{472,"fEM_B2MV01RC1\0"}, 
{473,"fEM_A3MC01RC1\0"}, 
{474,"fEM_A3MV01RC1\0"}, 
{475,"fEM_B3MC01RC1\0"}, 
{476,"fEM_B3MV01RC1\0"}, 
{477,"iEM_TERA2SS21LIM\0"}, 
{478,"iEM_TERA2SS12LIM\0"}, 
{479,"iEM_TERR6SS21LIM\0"}, 
{480,"iEM_TERA2VP82LIM\0"}, 
{481,"iEM_TERA2SS11LIM\0"}, 
{482,"iEM_TERB3SS21LIM\0"}, 
{483,"iEM_TERA0MT01RIM\0"}, 
{484,"iEM_TERB0MT01RIM\0"}, 
{485,"iEM_TERA2SP01RIM\0"}, 
{486,"iEM_TERB2SP01RIM\0"}, 
{487,"iEM_TERB3SP02RIM\0"}, 
{488,"iEM_TERA3SC01RIM\0"}, 
{489,"iEM_TERA3VP81LIM\0"}, 
{490,"iEM_TERA2SC01RIM\0"}, 
{491,"iEM_TERA2SS33LIM\0"}, 
{492,"iEM_TERA3SS21LIM\0"}, 
{493,"iEM_TERA3SS33LIM\0"}, 
{494,"iEM_TERA3SS31LIM\0"}, 
{495,"iEM_TERB3SS31LIM\0"}, 
{496,"iEM_TERB3SS33LIM\0"}, 
{497,"iEM_TERB3SC01RIM\0"}, 
{498,"iEM_TERA3SS11LIM\0"}, 
{499,"iEM_TERB3SS11LIM\0"}, 
{500,"iEM_TERR6IS64LIM\0"}, 
{501,"iEM_TERB3SS22LIM\0"}, 
{502,"iEM_TERA3SS22LIM\0"}, 
{503,"iEM_TERA3SP02RIM\0"}, 
{504,"iEM_TERR6IS62LIM\0"}, 
{505,"iEM_TERR6IS66LIM\0"}, 
{506,"iEM_TERR6IS67LIM\0"}, 
{507,"iEM_TERA0VP81LIM\0"}, 
{508,"iEM_TERB0VP81LIM\0"}, 
{509,"iEM_TERR0VP81LIM\0"}, 
{510,"iEM_TERR6IS68LIM\0"}, 
{511,"iEM_TERR7SI74RIM\0"}, 
{512,"iEM_TERA5SS21LIM\0"}, 
{513,"iEM_TERB5SS11LIM\0"}, 
{514,"iEM_TERA5SS11LIM\0"}, 
{515,"iEM_TERA9SS11LIM\0"}, 
{516,"iEM_TERB2SS11LIM\0"}, 
{517,"iEM_TERB2SS12LIM\0"}, 
{518,"iEM_TERB2SS21LIM\0"}, 
{519,"iEM_TERR3SS11LIM\0"}, 
{520,"iEM_TERB2SC01RIM\0"}, 
{521,"iEM_TERR3SS21LIM\0"}, 
{522,"iEM_TERR5SS11LIM\0"}, 
{523,"iEM_TERA4SS11LIM\0"}, 
{524,"iEM_TERR1SS11LIM\0"}, 
{525,"iEM_TERR1SS21LIM\0"}, 
{526,"iEM_TERR2SS11LIM\0"}, 
{527,"iEM_TERR2SS21LIM\0"}, 
{528,"iEM_TERA4VP82LIM\0"}, 
{529,"iEM_TERB4SS21LIM\0"}, 
{530,"iEM_TERR5SS21LIM\0"}, 
{531,"iEM_TERB6SS21LIM\0"}, 
{532,"iEM_TERB4SS11LIM\0"}, 
{533,"iEM_TERA4SS21LIM\0"}, 
{534,"iEM_TERA6MS11LIM\0"}, 
{535,"iEM_TERA6SS21LIM\0"}, 
{536,"iEM_TERB6SS11LIM\0"}, 
{537,"iEM_TERR4SS11LIM\0"}, 
{538,"iEM_TERR4MS21LIM\0"}, 
{539,"iEM_TERR4SS12LIM\0"}, 
{540,"iEM_TERR4SS22LIM\0"}, 
{541,"iEM_TERR8SS11LIM\0"}, 
{542,"iEM_TERB8SC01RIM\0"}, 
{543,"iEM_TERA8SC01RIM\0"}, 
{544,"iEM_TERB8SS12LIM\0"}, 
{545,"iEM_TERA8SS12LIM\0"}, 
{546,"iEM_TERB8SS22LIM\0"}, 
{547,"iEM_TERA8SS22LIM\0"}, 
{548,"iEM_TERA9SS21LIM\0"}, 
{549,"iEM_TERB9SS21LIM\0"}, 
{550,"iEM_TERB9SS11LIM\0"}, 
{551,"iEM_TERB5SS21LIM\0"}, 
{552,"iEM_TERA1SS21LIM\0"}, 
{553,"iEM_TERA1SS11LIM\0"}, 
{554,"iEM_TERA1SC01RIM\0"}, 
{555,"iEM_TERA1SS12LIM\0"}, 
{556,"iEM_TERB1SS21LIM\0"}, 
{557,"iEM_TERB1SS11LIM\0"}, 
{558,"iEM_TERB1MC01RIM\0"}, 
{559,"iEM_TERB1SS12LIM\0"}, 
{560,"iEM_TERTLG\0"}, 
{561,"fEM_R4MC01RC1\0"}, 
{562,"fEM_R4MV01RC1\0"}, 
{563,"iEM_TERMAZ2\0"}, 
{564,"fEM_B8MC01RC1\0"}, 
{565,"fEM_B8MV01RC1\0"}, 
{566,"iEM_TERDS2\0"}, 
{567,"fEM_A8MC01RC1\0"}, 
{568,"fEM_A8MV01RC1\0"}, 
{569,"iEM_TERBZ1\0"}, 
{570,"fEM_A6MC01RC1\0"}, 
{571,"fEM_A6MV01RC1\0"}, 
{572,"iEM_TERBZ2\0"}, 
{573,"fEM_B6MC01RC1\0"}, 
{574,"fEM_B6MV01RC1\0"}, 
{575,"lEM_R3AD10LC1\0"}, 
{576,"lEM_R3AD20LC1\0"}, 
{577,"lEM_R6AD10LC1\0"}, 
{578,"lEM_R5AD10LC1\0"}, 
{579,"lEM_R5AD20LC1\0"}, 
{580,"iEM_TERMDZ2\0"}, 
{581,"fEM_R2MC01RC1\0"}, 
{582,"fEM_R2MV01RC1\0"}, 
{583,"iEM_TERMDZ1\0"}, 
{584,"fEM_R1MC01RC1\0"}, 
{585,"fEM_R1MV01RC1\0"}, 
{586,"iEM_TERNL1\0"}, 
{587,"fEM_A5MC01RC1\0"}, 
{588,"fEM_A5MV01RC1\0"}, 
{589,"iEM_TERNL2\0"}, 
{590,"fEM_B5MC01RC1\0"}, 
{591,"fEM_B5MV01RC1\0"}, 
{592,"lEM_R8AD10LC1\0"}, 
{593,"fEM_A1UC08RIM\0"}, 
{594,"fEM_A2UC08RIM\0"}, 
{595,"fEM_A3UC08RIM\0"}, 
{596,"iEM_TERB2SS33LIM\0"}, 
{597,"iEM_TERA1VP81LIM\0"}, 
{598,"iEM_TERB1VP81LIM\0"}, 
{599,"fEM_A0UT03RSP\0"}, 
{600,"fEM_A0UR01RSP\0"}, 
{601,"fEM_A0UR02RSP\0"}, 
{602,"fEM_B0UT03RSP\0"}, 
{603,"fEM_A1MC01RSP\0"}, 
{604,"fEM_A1MC02RSP\0"}, 
{605,"fEM_B1MC01RSP\0"}, 
{606,"fEM_B1MC02RSP\0"}, 
{607,"fEM_A2MC01RC1\0"}, 
{608,"fEM_A2MV01RC1\0"}, 
{609,"fEM_A2MC01RSP\0"}, 
{610,"fEM_A2MC02RSP\0"}, 
{611,"fEM_B2MC01RSP\0"}, 
{612,"fEM_B2MC02RSP\0"}, 
{613,"fEM_A3MC01RSP\0"}, 
{614,"fEM_A3MC02RSP\0"}, 
{615,"fEM_B3MC01RSP\0"}, 
{616,"fEM_B3MC02RSP\0"}, 
{617,"fEM_B8MC01RSP\0"}, 
{618,"fEM_A8MC01RSP\0"}, 
{619,"fEM_A6MC01RSP\0"}, 
{620,"fEM_B6MC01RSP\0"}, 
{621,"fEM_R3UC01RSP\0"}, 
{622,"fEM_R5UC01RSP\0"}, 
{623,"fEM_R6UC01RSP\0"}, 
{624,"fEM_R2MC01RSP\0"}, 
{625,"fEM_R1MC01RSP\0"}, 
{626,"fEM_A5MC01RSP\0"}, 
{627,"fEM_B5MC01RSP\0"}, 
{628,"fEM_A9MC01RSP\0"}, 
{629,"fEM_B9MC01RSP\0"}, 
{630,"fEM_A4MC01RSP\0"}, 
{631,"fEM_B4MC01RSP\0"}, 
{632,"fEM_R4MC01RSP\0"}, 
{633,"fEM_A1MV01RC1\0"}, 
{634,"iEM_TERB7MS31LIM\0"}, 
{635,"iEM_TERA7MS31LIM\0"}, 
{636,"fEM_R7UY00RSS\0"}, 
{637,"iEM_TERA6VS12LIM\0"}, 
{638,"iEM_TERA6VS22LIM\0"}, 
{639,"iEM_TERB6VS12LIM\0"}, 
{640,"iEM_TERB6VS22LIM\0"}, 
{641,"iEM_TERA5VS22LIM\0"}, 
{642,"iEM_TERA5VS12LIM\0"}, 
{643,"iEM_TERB5VS12LIM\0"}, 
{644,"iEM_TERB5VS22LIM\0"}, 
{645,"iEM_TERR1VS12LIM\0"}, 
{646,"iEM_TERR1VS22LIM\0"}, 
{647,"iEM_TERR2VS12LIM\0"}, 
{648,"iEM_TERR2VS22LIM\0"}, 
{649,"iEM_TERR4VS12LDU\0"}, 
{650,"iEM_TERR4VS22LDU\0"}, 
{651,"fEM_R4UC23RIM\0"}, 
{652,"fEM_A0UX13RSS\0"}, 
{653,"fEM_A0UX14RSS\0"}, 
{654,"fEM_A0UX15RSS\0"}, 
{655,"fEM_R7UX13RSS\0"}, 
{656,"fEM_R7UX14RSS\0"}, 
{657,"fEM_R7UX15RSS\0"}, 
{658,"fEM_R7UY13RSS\0"}, 
{659,"fEM_R7UY14RSS\0"}, 
{660,"fEM_R7UY15RSS\0"}, 
{661,"fEM_R7UX16RSS\0"}, 
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
	{&R0MW11IP1,3,0},	//( - , SCM) Переключатель ВЫСТРЕЛ
	{&R0DEUMLSS,3,1},	//( - , SCM) Сигнал управления моделью
	{&fEM_R0UL01RIM,8,2},	//( - , SCM) Среднее время генерации нейтронов
	{&fEM_R0UN02RIM,8,4},	//( - , SCM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{&fEM_A1UR01RIM,8,6},	//( - , SCM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{&fEM_A1UR00RIM,8,8},	//( - , SCM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{&fEM_A3UR00RIM,8,10},	//( - , SCM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{&fEM_A3UR01RIM,8,12},	//( - , SCM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{&fEM_R0UT01RIM,8,14},	//( - , SCM) Температурный коэффициент (долл)
	{&fEM_R0UT02RIM,8,16},	//( - , SCM) Масса топлива в АЗ
	{&fEM_R0UT04RIM,8,18},	//( - , SCM) Удельная теплоёмкость топлива
	{&fEM_R0UT03RIM,8,20},	//( - , SCM) Нормальная температура АЗ град
	{&fEM_R0UT05RIM,8,22},	//( - , SCM) Энергия деления ядра
	{&fEM_R0UT06RIM,8,24},	//( - , SCM) Конвекционное сопротивление при обдуве
	{&fEM_A1UC02RDU,8,26},	//( - , SCM) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{&fEM_A1UC04RIM,8,28},	//( - , SCM) Координата промежуточного путевого выключателя ББ мм
	{&fEM_A1UC05RIM,8,30},	//( - , SCM) Координата переднего аварийного выключателя ББ мм
	{&fEM_A1UC06RIM,8,32},	//( - , SCM) Координата заднего аварийного выключателя ББ мм
	{&fEM_A2UC06RIM,8,34},	//( - , SCM) Координата заднего аварийного выключателя РБ мм
	{&fEM_A2UC05RIM,8,36},	//( - , SCM) Координата переднего аварийного выключателя РБ мм
	{&fEM_A2UC04RIM,8,38},	//( - , SCM) Координата промежуточного путевого выключателя РБ мм
	{&fEM_A2UC02RDU,8,40},	//( - , SCM) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{&fEM_A3UC06RIM,8,42},	//( - , SCM) Координата заднего аварийного выключателя ИС мм
	{&fEM_A3UC05RIM,8,44},	//( - , SCM) Координата переднего аварийного выключателя ИС мм
	{&fEM_A3UC04RIM,8,46},	//( - , SCM) Координата промежуточного путевого выключателя ИС мм
	{&fEM_A3UC02RDU,8,48},	//( - , SCM) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{&fEM_R4UV80RDU,8,50},	//( - , SCM) Номинальная скорость тележки (мм/с)
	{&fEM_R4UC10RIM,8,52},	//( - , SCM) Координата верхних механических упоров тележки мм
	{&fEM_R4UC20RIM,8,54},	//( - , SCM) Координата нижних механических упоров тележки мм
	{&fEM_B8UC21RIM,8,56},	//( - , SCM) Координата верхнего путевого выключателя АЗ2 мм
	{&fEM_B8UC20RIM,8,58},	//( - , SCM) Координата верхних механических упоров АЗ2 мм
	{&fEM_B8UC11RIM,8,60},	//( - , SCM) Координата нижнего путевого выключателя АЗ2 мм
	{&fEM_B8UC10RIM,8,62},	//( - , SCM) Координата нижних механических упоров АЗ2 мм
	{&fEM_B8UV80RDU,8,64},	//( - , SCM) Номинальная скорость АЗ2 (мм/с)
	{&fEM_A8UV80RDU,8,66},	//( - , SCM) Номинальная скорость ДС2 (мм/с)
	{&fEM_A8UC10RIM,8,68},	//( - , SCM) Координата нижних механических упоров ДС2 мм
	{&fEM_A8UC11RIM,8,70},	//( - , SCM) Координата нижнего путевого выключателя ДС2 мм
	{&fEM_A8UC20RIM,8,72},	//( - , SCM) Координата верхних механических упоров ДС2 мм
	{&fEM_A8UC21RIM,8,74},	//( - , SCM) Координата верхнего путевого выключателя ДС2 мм
	{&fEM_A6UC10RIM,8,76},	//( - , SCM) Время полного хода БЗ (сек)
	{&fEM_R1UC10RIM,8,78},	//( - , SCM) Время полного хода МДЗ сек
	{&fEM_A5UC10RIM,8,80},	//( - , SCM) Время полного хода НЛ сек
	{&fEM_A0UN01RIM,8,82},	//( - , SCM) Мощность источника нейтронов ИНИ
	{&fEM_R4UC22RIM,8,84},	//( - , SCM) Смещение координаты АЗ от координаты тележки
	{&fEM_A1UG01RDU,8,86},	//( - , SCM) Расстояние включения масляного демпфера ББ(мм)
	{&fEM_A2UG01RDU,8,88},	//( - , SCM) Расстояние включения масляного демпфера РБ
	{&fEM_A3UG01RDU,8,90},	//( - , SCM) Расстояние включения масляного демпфера ИС
	{&fEM_R7UC10RIM,8,92},	//( - , SCM) X-координата КНК53М R7IN13 см
	{&fEM_R7UC19RIM,8,94},	//( - , SCM) Y-координата СНМ-11 (11) см
	{&fEM_R7UI02RIM,8,96},	//( - , SCM) Коэффициент усиления уровня радиации
	{&fEM_R7UL01RIM,8,98},	//( - , SCM) Постоянная времени изменения уровня радиации в зале
	{&fEM_A2UR00RIM,8,100},	//( - , SCM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{&fEM_A2UR01RIM,8,102},	//( - , SCM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{&fEM_A0UN02RIM,8,104},	//( - , SCM) Мощность источника нейтронов с АНИ
	{&fEM_R0UR30RIM,8,106},	//( - , SCM) Реактивность вносимая образцами (долл)
	{&fEM_R0UR01RIM,8,108},	//( - , SCM) Стартовая отрицательная реактивность
	{&fEM_R0UT02RDU,8,110},	//( - , SCM) Верхний предел шкалы датчика температуры
	{&fEM_R0UT01RDU,8,112},	//( - , SCM) Нижний предел шкалы датчика температуры
	{&fEM_A1UC03RDU,8,114},	//( - , SCM) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{&fEM_A2UP03RDU,8,116},	//( - , SCM) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{&fEM_A2UP04RDU,8,118},	//( - , SCM) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{&fEM_A2UC03RDU,8,120},	//( - , SCM) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{&fEM_A3UP03RDU,8,122},	//( - , SCM) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A3UP04RDU,8,124},	//( - , SCM) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A3UC03RDU,8,126},	//( - , SCM) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{&fEM_R7UI74RIM,8,128},	//( - , SCM) Верхняя граница измерения уровня радиации в зале
	{&fEM_A8UC03RDU,8,130},	//( - , SCM) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{&fEM_R0UV87RDU,8,132},	//( - , SCM) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV81RDU,8,134},	//( - , SCM) 1-я частота двигателя (шагов/секунду)
	{&fEM_R0UV82RDU,8,136},	//( - , SCM) 3-я частота двигателя (шагов/секунду)
	{&fEM_R0UV83RDU,8,138},	//( - , SCM) 4-я частота двигателя (шагов/секунду)
	{&fEM_R0UV84RDU,8,140},	//( - , SCM) 5-я частота двигателя (шагов/секунду)
	{&fEM_R0UV85RDU,8,142},	//( - , SCM) 6-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV86RDU,8,144},	//( - , SCM) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_A8UC08RDU,8,146},	//( - , SCM) Зона срабатывания КВ ДС2(мм)
	{&fEM_B8UC08RDU,8,148},	//( - , SCM) Зона срабатывания КВ АЗ2(мм)
	{&fEM_R4UC08RDU,8,150},	//( - , SCM) Зона срабатывания КВ тележки РУ(мм)
	{&fEM_R7UX01RSS,8,152},	//( - , SCM) X-координата камеры R7IN11
	{&fEM_R7UX02RSS,8,154},	//( - , SCM) X-координата камеры R7IN12 (см)
	{&fEM_R7UX04RSS,8,156},	//( - , SCM) X-координата камеры R7IN21 (см)
	{&fEM_R7UX05RSS,8,158},	//( - , SCM) X-координата камеры R7IN22 (см)
	{&fEM_R7UX06RSS,8,160},	//( - , SCM) X-координата камеры R7IN23 (см)
	{&fEM_R7UX07RSS,8,162},	//( - , SCM) X-координата камеры R7IN31 (см)
	{&fEM_R7UX08RSS,8,164},	//( - , SCM) X-координата камеры R7IN32 (см)
	{&fEM_R7UX09RSS,8,166},	//( - , SCM) X-координата камеры R7IN33 (см)
	{&fEM_R7UY01RSS,8,168},	//( - , SCM) Y-координата камеры R7IN11
	{&fEM_R7UY02RSS,8,170},	//( - , SCM) Y-координата камеры R7IN12 (см)
	{&fEM_R7UY04RSS,8,172},	//( - , SCM) Y-координата камеры R7IN21 (см)
	{&fEM_R7UY05RSS,8,174},	//( - , SCM) Y-координата камеры R7IN22 (см)
	{&fEM_R7UY06RSS,8,176},	//( - , SCM) Y-координата камеры R7IN23 (см)
	{&fEM_R7UY07RSS,8,178},	//( - , SCM) Y-координата камеры R7IN31 (см)
	{&fEM_R7UY08RSS,8,180},	//( - , SCM) Y-координата камеры R7IN32 (см)
	{&fEM_R7UY09RSS,8,182},	//( - , SCM) Y-координата камеры R7IN33 (см)
	{&fEM_R7UX10RSS,8,184},	//( - , SCM) X-координата камеры R7IN41
	{&fEM_R7UX11RSS,8,186},	//( - , SCM) X-координата камеры R7IN42
	{&fEM_R7UX12RSS,8,188},	//( - , SCM) X-координата камеры R7IN43
	{&fEM_R7UY10RSS,8,190},	//( - , SCM) Y-координата камеры R7IN41
	{&fEM_R7UY11RSS,8,192},	//( - , SCM) Y-координата камеры R7IN42
	{&fEM_R7UY12RSS,8,194},	//( - , SCM) Y-координата камеры R7IN43
	{&fEM_A0UX01RSS,8,196},	//( - , SCM) Первый коэффициент калибровки камеры 1
	{&fEM_A0UX02RSS,8,198},	//( - , SCM) Первый коэффициент калибровки камеры 2
	{&fEM_A0UX03RSS,8,200},	//( - , SCM) Первый коэффициент калибровки камеры 3
	{&fEM_A0UX04RSS,8,202},	//( - , SCM) Первый коэффициент калибровки камеры4
	{&fEM_A0UX05RSS,8,204},	//( - , SCM) Первый коэффициент калибровки камеры 5
	{&fEM_A0UX06RSS,8,206},	//( - , SCM) Первый коэффициент калибровки камеры 6
	{&fEM_A0UX07RSS,8,208},	//( - , SCM) Первый коэффициент калибровки камеры 7
	{&fEM_A0UX08RSS,8,210},	//( - , SCM) Первый коэффициент калибровки камеры 8
	{&fEM_A0UX09RSS,8,212},	//( - , SCM) Первый коэффициент калибровки камеры 9
	{&fEM_A0UX10RSS,8,214},	//( - , SCM) Первый коэффициент калибровки камеры 10
	{&fEM_A0UX11RSS,8,216},	//( - , SCM) Первый коэффициент калибровки камеры 11
	{&fEM_A0UX12RSS,8,218},	//( - , SCM) Первый коэффициент калибровки камеры 12
	{&fEM_B0UX01RSS,8,220},	//( - , SCM) Второй коэффициент калибровки камеры 1
	{&fEM_B0UX02RSS,8,222},	//( - , SCM) Второй коэффициент калибровки камеры 2
	{&fEM_B0UX06RSS,8,224},	//( - , SCM) Второй коэффициент калибровки камеры 6
	{&fEM_B0UX07RSS,8,226},	//( - , SCM) Второй коэффициент калибровки камеры 7
	{&fEM_B0UX08RSS,8,228},	//( - , SCM) Второй коэффициент калибровки камеры 8
	{&fEM_B0UX09RSS,8,230},	//( - , SCM) Второй коэффициент калибровки камеры 9
	{&fEM_B0UX10RSS,8,232},	//( - , SCM) Второй коэффициент калибровки камеры 10
	{&fEM_B0UX11RSS,8,234},	//( - , SCM) Второй коэффициент калибровки камеры 11
	{&fEM_B0UX12RSS,8,236},	//( - , SCM) Второй коэффициент калибровки камеры 12
	{&fEM_R4US80RDU,8,238},	//( - , SCM) Тормозной путь тележки (мм)
	{&fEM_R7UI71RIM,8,240},	//( - , SCM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{&fEM_R7UI72RIM,8,242},	//( - , SCM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{&fEM_R7UI73RIM,8,244},	//( - , SCM) Уровень мощности срабатывания АС II УР  ватт
	{&fEM_A1UP01RIM,8,246},	//( - , SCM) Текущее давление на сброс ББ (МПа)
	{&fEM_A2UP01RIM,8,248},	//( - , SCM) Текущее давление на сброс РБ
	{&fEM_A0UP02RIM,8,250},	//( - , SCM) Текущее давление в АЗ1,2
	{&fEM_A3UP01RIM,8,252},	//( - , SCM) Текущее давление на СПУСК ИС
	{&fEM_A1UP82RIM,8,254},	//( - , SCM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{&fEM_A3UP02RDU,8,256},	//( - , SCM) Текущее давление ВЫСТРЕЛ ИС
	{&fEM_A1UV02RIM,8,258},	//( - , SCM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{&fEM_A3UV02RIM,8,260},	//( - , SCM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{&fEM_A2UV02RIM,8,262},	//( - , SCM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{&fEM_B8US80RDU,8,264},	//( - , SCM) Тормозной путь АЗ2 (мм)
	{&fEM_A8US80RDU,8,266},	//( - , SCM) Тормозной путь ДС2 (мм)
	{&fEM_A6US80RDU,8,268},	//( - , SCM) Тормозной путь БЗ (мм)
	{&fEM_A1US07RDU,8,270},	//( - , SCM) Постоянная времени масляного демпфера ББ
	{&fEM_A2US07RDU,8,272},	//( - , SCM) Постоянная времени масляного демпфера РБ
	{&fEM_A3US07RDU,8,274},	//( - , SCM) Постоянная времени масляного демпфера ИС
	{&fEM_R7UI75RIM,8,276},	//( - , SCM) Множитель к уровню радиации
	{&fEM_R0UH05RSS,8,278},	//( - , SCM) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_A4UL10RIM,8,280},	//( - , SCM) Время полного перемещения НИ сек
	{&fEM_A9UL10RIM,8,282},	//( - , SCM) Время полного перемещения НИ ДС1/ДС2 сек
	{&fEM_R3UL10RIM,8,284},	//( - , SCM) Время полного хода гомогенных дверей (сек)
	{&fEM_R5UL10RIM,8,286},	//( - , SCM) Время полного хода ворот отстойной зоны (дес. мс)
	{&fEM_R6UL10RIM,8,288},	//( - , SCM) Время полного хода кран-балки сек
	{&fEM_A2UP02RIM,8,290},	//( - , SCM) Текущее давление на подъём РБ
	{&fEM_A2UP03RIM,8,292},	//( - , SCM) Нижняя граница давления на ПОДЪЁМ РБ
	{&fEM_A0UP01RIM,8,294},	//( - , SCM) Текущее давление в АЗ1,2
	{&fEM_A3UP02RIM,8,296},	//( - , SCM) Нижняя граница  давления на СПУСК ИС
	{&fEM_A4UP01RIM,8,298},	//( - , SCM) Текущее давление на подъём НИ
	{&fEM_A4UP02RIM,8,300},	//( - , SCM) Нижняя граница давления на подъём НИ
	{&fEM_R7UI76RIM,8,302},	//( - , SCM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{&fEM_R7UI77RIM,8,304},	//( - , SCM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{&iEM_TERBB1,3,306},	//( - , SCM) Неисправности  ББ1
	{&fEM_A1MC02RC1,8,307},	//( - , SCM) Заданная координата штока ББ1 от ИС
	{&fEM_A1MV02RC1,8,309},	//( - , SCM) Заданная скорость движения  штока ББ1 от ИС
	{&iEM_TERBB2,3,311},	//( - , SCM) Неисправности  ББ2
	{&fEM_B1MC02RC1,8,312},	//( - , SCM) Заданная координата штока ББ2 от ИС
	{&fEM_B1MV02RC1,8,314},	//( - , SCM) Заданная скорость движения штока ББ2 от ИС
	{&iEM_TERRB2,3,316},	//( - , SCM) Неисправности  РБ2
	{&fEM_B2MC02RC1,8,317},	//( - , SCM) Заданная координата штока РБ2 от ИС
	{&fEM_B2MV02RC1,8,319},	//( - , SCM) Заданная скорость движения штока РБ2 от ИС
	{&iEM_TERRB1,3,321},	//( - , SCM) Неисправности  РБ1
	{&fEM_A2MC02RC1,8,322},	//( - , SCM) Заданная координата штока РБ1 от ИС
	{&fEM_A2MV02RC1,8,324},	//( - , SCM) Заданная скорость движения штока РБ1 от ИС
	{&iEM_TERIS2,3,326},	//( - , SCM) Неисправности  ИС2
	{&fEM_B3MC02RC1,8,327},	//( - , SCM) Заданная координата штока ИС2 от ИС
	{&fEM_B3MV02RC1,8,329},	//( - , SCM) Заданная скорость движения штока ИС2 от ИС
	{&iEM_TERIS1,3,331},	//( - , SCM) Неисправности  ИС1
	{&fEM_A3MC02RC1,8,332},	//( - , SCM) Заданная координата штока ИС1 от ИС
	{&fEM_A3MV02RC1,8,334},	//( - , SCM) Заданная скорость движения штока ИС1 от ИС
	{&iEM_TERA1IE04LDU,3,336},	//( - , SCM) Искажение Движение ББ1 назад (от БУШД)
	{&iEM_TERA1IE03LDU,3,337},	//( - , SCM) Искажение Движение ББ1 вперёд (от БУШД)
	{&fEM_A1MC01RC1,8,338},	//( - , SCM) Заданная координата  ББ1 от ИС
	{&iEM_TERB1IE03LDU,3,340},	//( - , SCM) Искажение Движение ББ2 вперёд (от БУШД)
	{&iEM_TERB1IE04LDU,3,341},	//( - , SCM) Искажение Движение ББ2 назад (от БУШД)
	{&fEM_B1MC01RC1,8,342},	//( - , SCM) Заданная координата ББ2 от ИС
	{&fEM_B1MV01RC1,8,344},	//( - , SCM) Заданная скорость движения ББ2 от ИС
	{&fEM_B2MC01RC1,8,346},	//( - , SCM) Заданная координата РБ2 от ИС
	{&fEM_B2MV01RC1,8,348},	//( - , SCM) Заданная скорость движения  РБ2 от ИС
	{&fEM_A3MC01RC1,8,350},	//( - , SCM) Заданная координата ИС1 от ИС
	{&fEM_A3MV01RC1,8,352},	//( - , SCM) Заданная скорость движения ИС1 от ИС
	{&fEM_B3MC01RC1,8,354},	//( - , SCM) Заданная координата ИС2 от ИС
	{&fEM_B3MV01RC1,8,356},	//( - , SCM) Заданная скорость движения ИС2 от ИС
	{&iEM_TERA2SS21LIM,3,358},	//( - , SCM) Искажение: Приход на НУ РБ1
	{&iEM_TERA2SS12LIM,3,359},	//( - , SCM) Искажение: Магнит РБ1 зацеплен
	{&iEM_TERR6SS21LIM,3,360},	//( - , SCM) Искажение: Кран-балка в нерабочем положении
	{&iEM_TERA2VP82LIM,3,361},	//( - , SCM) Искажение: Текущее давление на подъём РБ  в норме
	{&iEM_TERA2SS11LIM,3,362},	//( - , SCM) Искажение: Приход на ВУ РБ1
	{&iEM_TERB3SS21LIM,3,363},	//( - , SCM) Искажение: Приход на НУ ИС2
	{&iEM_TERA0MT01RIM,3,364},	//( - , SCM) Искажение: Текущая температура AЗ1
	{&iEM_TERB0MT01RIM,3,365},	//( - , SCM) Искажение: Текущая температура AЗ2
	{&iEM_TERA2SP01RIM,3,366},	//( - , SCM) Искажение: Текущее давление СБРОС РБ1
	{&iEM_TERB2SP01RIM,3,367},	//( - , SCM) Искажение: Текущее давление СБРОС РБ2
	{&iEM_TERB3SP02RIM,3,368},	//( - , SCM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{&iEM_TERA3SC01RIM,3,369},	//( - , SCM) Искажение: Координата штока ИС1
	{&iEM_TERA3VP81LIM,3,370},	//( - , SCM) Искажение: Текущее давление СПУСК ИС  в норме
	{&iEM_TERA2SC01RIM,3,371},	//( - , SCM) Искажение: Координата штока РБ1
	{&iEM_TERA2SS33LIM,3,372},	//( - , SCM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{&iEM_TERA3SS21LIM,3,373},	//( - , SCM) Искажение: Приход на НУ ИС1
	{&iEM_TERA3SS33LIM,3,374},	//( - , SCM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{&iEM_TERA3SS31LIM,3,375},	//( - , SCM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{&iEM_TERB3SS31LIM,3,376},	//( - , SCM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{&iEM_TERB3SS33LIM,3,377},	//( - , SCM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{&iEM_TERB3SC01RIM,3,378},	//( - , SCM) Искажение: Координата штока ИС2
	{&iEM_TERA3SS11LIM,3,379},	//( - , SCM) Искажение: Приход на ВУ ИС1
	{&iEM_TERB3SS11LIM,3,380},	//( - , SCM) Искажение: Приход на ВУ ИС2
	{&iEM_TERR6IS64LIM,3,381},	//( - , SCM) Искажение: Исправность ВИП ССДИ-35
	{&iEM_TERB3SS22LIM,3,382},	//( - , SCM) Искажение: Приход на НУП ИС2
	{&iEM_TERA3SS22LIM,3,383},	//( - , SCM) Искажение: Приход на НУП ИС1
	{&iEM_TERA3SP02RIM,3,384},	//( - , SCM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{&iEM_TERR6IS62LIM,3,385},	//( - , SCM) Искажение Исправность ВИП ССДИ-39
	{&iEM_TERR6IS66LIM,3,386},	//( - , SCM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{&iEM_TERR6IS67LIM,3,387},	//( - , SCM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{&iEM_TERA0VP81LIM,3,388},	//( - , SCM) Искажение: Давление  АЗ1  в норме
	{&iEM_TERB0VP81LIM,3,389},	//( - , SCM) Искажение: Давление  АЗ2 в норме
	{&iEM_TERR0VP81LIM,3,390},	//( - , SCM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{&iEM_TERR6IS68LIM,3,391},	//( - , SCM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{&iEM_TERR7SI74RIM,3,392},	//( - , SCM) Искажение: Радиация в реакторном зале
	{&iEM_TERA5SS21LIM,3,393},	//( - , SCM) Искажение: Приход на НУ НЛ1
	{&iEM_TERB5SS11LIM,3,394},	//( - , SCM) Искажение: Приход на ВУ НЛ2
	{&iEM_TERA5SS11LIM,3,395},	//( - , SCM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{&iEM_TERA9SS11LIM,3,396},	//( - , SCM) Искажение: Приход на ВУ НИ ДС1
	{&iEM_TERB2SS11LIM,3,397},	//( - , SCM) Искажение: Приход на ВУ РБ2
	{&iEM_TERB2SS12LIM,3,398},	//( - , SCM) Искажение: Магнит РБ2 зацеплен
	{&iEM_TERB2SS21LIM,3,399},	//( - , SCM) Искажение: Приход на НУ РБ2
	{&iEM_TERR3SS11LIM,3,400},	//( - , SCM) Искажение: Приход на ВУ гомогенных дверей-1
	{&iEM_TERB2SC01RIM,3,401},	//( - , SCM) Искажение: Координата штока РБ2
	{&iEM_TERR3SS21LIM,3,402},	//( - , SCM) Искажение: Приход на НУ гомогенных дверей-1
	{&iEM_TERR5SS11LIM,3,403},	//( - , SCM) Искажение: Приход на ВУ ворот отстойной зоны
	{&iEM_TERA4SS11LIM,3,404},	//( - , SCM) Искажение: Приход на ВУ НИ1
	{&iEM_TERR1SS11LIM,3,405},	//( - , SCM) Искажение: Приход на ВУ МДЗ1
	{&iEM_TERR1SS21LIM,3,406},	//( - , SCM) Искажение: Приход на НУ МДЗ1
	{&iEM_TERR2SS11LIM,3,407},	//( - , SCM) Искажение: Приход на ВУ МДЗ2
	{&iEM_TERR2SS21LIM,3,408},	//( - , SCM) Искажение: Приход на НУ МДЗ2
	{&iEM_TERA4VP82LIM,3,409},	//( - , SCM) Искажение Давление ПОДЪЁМ НИ в норме
	{&iEM_TERB4SS21LIM,3,410},	//( - , SCM) Искажение: Приход на НУ НИ2
	{&iEM_TERR5SS21LIM,3,411},	//( - , SCM) Искажение: Приход на НУ ворот отстойной зоны
	{&iEM_TERB6SS21LIM,3,412},	//( - , SCM) Искажение: Приход на НУ БЗ2
	{&iEM_TERB4SS11LIM,3,413},	//( - , SCM) Искажение: Приход на ВУ НИ2
	{&iEM_TERA4SS21LIM,3,414},	//( - , SCM) Искажение: Приход на НУ НИ1
	{&iEM_TERA6MS11LIM,3,415},	//( - , SCM) Искажение: Приход на ВУ БЗ1
	{&iEM_TERA6SS21LIM,3,416},	//( - , SCM) Искажение: Приход на НУ БЗ1
	{&iEM_TERB6SS11LIM,3,417},	//( - , SCM) Искажение: Приход на ВУ БЗ2
	{&iEM_TERR4SS11LIM,3,418},	//( - , SCM) Искажение: Приход на ВУ тележки
	{&iEM_TERR4MS21LIM,3,419},	//( - , SCM) Искажение: Приход на НУ тележки
	{&iEM_TERR4SS12LIM,3,420},	//( - , SCM) Искажение: Приход на механический ВУ тележки
	{&iEM_TERR4SS22LIM,3,421},	//( - , SCM) Искажение: Приход на механический НУ тележки
	{&iEM_TERR8SS11LIM,3,422},	//( - , SCM) Искажение: Аварийный НИ установлен
	{&iEM_TERB8SC01RIM,3,423},	//( - , SCM) Искажение: Координата АЗ2
	{&iEM_TERA8SC01RIM,3,424},	//( - , SCM) Искажение: Координата ДС2
	{&iEM_TERB8SS12LIM,3,425},	//( - , SCM) Искажение: Приход на механический ВУ АЗ2
	{&iEM_TERA8SS12LIM,3,426},	//( - , SCM) Искажение: Приход на механический ВУ ДС2
	{&iEM_TERB8SS22LIM,3,427},	//( - , SCM) Искажение: Приход на механический НУ АЗ2
	{&iEM_TERA8SS22LIM,3,428},	//( - , SCM) Искажение: Приход на механический НУ ДС2
	{&iEM_TERA9SS21LIM,3,429},	//( - , SCM) Искажение: Приход на НУ НИ ДС1
	{&iEM_TERB9SS21LIM,3,430},	//( - , SCM) Искажение: Приход на НУ НИ ДС2
	{&iEM_TERB9SS11LIM,3,431},	//( - , SCM) Искажение: Приход на ВУ НИ ДС2
	{&iEM_TERB5SS21LIM,3,432},	//( - , SCM) Искажение: Приход на НУ НЛ2
	{&iEM_TERA1SS21LIM,3,433},	//( - , SCM) Искажение: Приход на НУ ББ1
	{&iEM_TERA1SS11LIM,3,434},	//( - , SCM) Искажение: Приход на ВУ ББ1
	{&iEM_TERA1SC01RIM,3,435},	//( - , SCM) Искажение: Координата штока ББ1
	{&iEM_TERA1SS12LIM,3,436},	//( - , SCM) Искажение: Магнит ББ1 зацеплен
	{&iEM_TERB1SS21LIM,3,437},	//( - , SCM) Искажение: Приход на НУ ББ2
	{&iEM_TERB1SS11LIM,3,438},	//( - , SCM) Искажение:Приход на ВУ ББ2
	{&iEM_TERB1MC01RIM,3,439},	//( - , SCM) Искажение: Координата штока ББ2
	{&iEM_TERB1SS12LIM,3,440},	//( - , SCM) Искажение: Магнит ББ2 зацеплен
	{&iEM_TERTLG,3,441},	//( - , SCM) Неисправности  тележки от ИС
	{&fEM_R4MC01RC1,8,442},	//( - , SCM) Заданная координата тележки от ИС
	{&fEM_R4MV01RC1,8,444},	//( - , SCM) Заданная скорость тележки от ИС
	{&iEM_TERMAZ2,3,446},	//( - , SCM) Неисправности АЗ2 от ИС
	{&fEM_B8MC01RC1,8,447},	//( - , SCM) Заданная координата АЗ2 от ИС
	{&fEM_B8MV01RC1,8,449},	//( - , SCM) Заданная скорость АЗ2 от ИС
	{&iEM_TERDS2,3,451},	//( - , SCM) Неисправности ДС2 от ИС
	{&fEM_A8MC01RC1,8,452},	//( - , SCM) Заданная координата ДС2 от ИС
	{&fEM_A8MV01RC1,8,454},	//( - , SCM) Заданная скорость ДС2 от ИС
	{&iEM_TERBZ1,3,456},	//( - , SCM) Неисправности БЗ1
	{&fEM_A6MC01RC1,8,457},	//( - , SCM) Заданная координата БЗ1 от ИС
	{&fEM_A6MV01RC1,8,459},	//( - , SCM) Заданная скорость БЗ1 от ИС
	{&iEM_TERBZ2,3,461},	//( - , SCM) Неисправности БЗ2
	{&fEM_B6MC01RC1,8,462},	//( - , SCM) Заданная координата БЗ2 от ИС
	{&fEM_B6MV01RC1,8,464},	//( - , SCM) Заданная скорость БЗ2 от ИС
	{&iEM_TERMDZ2,3,466},	//( - , SCM) Неисправности МДЗ2
	{&fEM_R2MC01RC1,8,467},	//( - , SCM) Заданная координата МДЗ2 от ИС
	{&fEM_R2MV01RC1,8,469},	//( - , SCM) Заданная скорость МДЗ2 от ИС
	{&iEM_TERMDZ1,3,471},	//( - , SCM) Неисправности МДЗ1
	{&fEM_R1MC01RC1,8,472},	//( - , SCM) Заданная координата МДЗ1 от ИС
	{&fEM_R1MV01RC1,8,474},	//( - , SCM) Заданная скорость МДЗ1 от ИС
	{&iEM_TERNL1,3,476},	//( - , SCM) Неисправности НЛ1
	{&fEM_A5MC01RC1,8,477},	//( - , SCM) Заданная координата НЛ1 от ИС
	{&fEM_A5MV01RC1,8,479},	//( - , SCM) Заданная скорость НЛ1 от ИС
	{&iEM_TERNL2,3,481},	//( - , SCM) Неисправности НЛ2
	{&fEM_B5MC01RC1,8,482},	//( - , SCM) Заданная координата НЛ2 от ИС
	{&fEM_B5MV01RC1,8,484},	//( - , SCM) Заданная скорость НЛ2 от ИС
	{&fEM_A1UC08RIM,8,486},	//( - , SCM) Зона срабатывания КВ ББ(мм)
	{&fEM_A2UC08RIM,8,488},	//( - , SCM) Зона срабатывания КВ  РБ мм
	{&fEM_A3UC08RIM,8,490},	//( - , SCM) Зона срабатывания КВ ИС(мм)
	{&iEM_TERB2SS33LIM,3,492},	//( - , SCM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{&iEM_TERA1VP81LIM,3,493},	//( - , SCM) Искажение: Текущее давление СБРОС ББ1  в норме
	{&iEM_TERB1VP81LIM,3,494},	//( - , SCM) Искажение: Текущее давление СБРОС ББ2  в норме
	{&fEM_A0UT03RSP,8,495},	//( - , SCM) Стартовая  температура АЗ1 град
	{&fEM_A0UR01RSP,8,497},	//( - , SCM) Стартовая  реактивность АЗ1
	{&fEM_A0UR02RSP,8,499},	//( - , SCM) Стартовый  поток нейтронов АЗ1
	{&fEM_B0UT03RSP,8,501},	//( - , SCM) Стартовая  температура АЗ2 град
	{&fEM_A1MC01RSP,8,503},	//( - , SCM) Стартовая координата  ББ1
	{&fEM_A1MC02RSP,8,505},	//( - , SCM) Стартовая координата штока ББ1
	{&fEM_B1MC01RSP,8,507},	//( - , SCM) Стартовая координата  ББ2
	{&fEM_B1MC02RSP,8,509},	//( - , SCM) Стартовая координата штока ББ2
	{&fEM_A2MC01RC1,8,511},	//( - , SCM) Заданная координата РБ1 от ИС
	{&fEM_A2MV01RC1,8,513},	//( - , SCM) Заданная скорость движения РБ1 от ИС
	{&fEM_A2MC01RSP,8,515},	//( - , SCM) Стартовая координата  РБ1
	{&fEM_A2MC02RSP,8,517},	//( - , SCM) Стартовая координата штока РБ1
	{&fEM_B2MC01RSP,8,519},	//( - , SCM) Стартовая координата  РБ2
	{&fEM_B2MC02RSP,8,521},	//( - , SCM) Стартовая координата штока РБ2
	{&fEM_A3MC01RSP,8,523},	//( - , SCM) Стартовая координата  ИС1
	{&fEM_A3MC02RSP,8,525},	//( - , SCM) Стартовая координата штока ИС1
	{&fEM_B3MC01RSP,8,527},	//( - , SCM) Стартовая координата  ИС2
	{&fEM_B3MC02RSP,8,529},	//( - , SCM) Стартовая координата штока ИС2
	{&fEM_B8MC01RSP,8,531},	//( - , SCM) Стартовая координата АЗ2
	{&fEM_A8MC01RSP,8,533},	//( - , SCM) Стартовая координата ДС2
	{&fEM_A6MC01RSP,8,535},	//( - , SCM) Стартовая координата БЗ1
	{&fEM_B6MC01RSP,8,537},	//( - , SCM) Стартовая координата БЗ2
	{&fEM_R3UC01RSP,8,539},	//( - , SCM) Стартовая координата Гомогенных дверей
	{&fEM_R5UC01RSP,8,541},	//( - , SCM) Стартовая координата Ворот отстойной зоны
	{&fEM_R6UC01RSP,8,543},	//( - , SCM) Стартовая координата Кран-балки
	{&fEM_R2MC01RSP,8,545},	//( - , SCM) Стартовая координата МДЗ2
	{&fEM_R1MC01RSP,8,547},	//( - , SCM) Стартовая координата МДЗ1
	{&fEM_A5MC01RSP,8,549},	//( - , SCM) Стартовая координата НЛ1
	{&fEM_B5MC01RSP,8,551},	//( - , SCM) Стартовая координата НЛ2
	{&fEM_A9MC01RSP,8,553},	//( - , SCM) Стартовая координата НИ ДС1
	{&fEM_B9MC01RSP,8,555},	//( - , SCM) Стартовая координата НИ ДС2
	{&fEM_A4MC01RSP,8,557},	//( - , SCM) Стартовая координата НИ1
	{&fEM_B4MC01RSP,8,559},	//( - , SCM) Стартовая координата НИ2
	{&fEM_R4MC01RSP,8,561},	//( - , SCM) Стартовая координата тележки
	{&fEM_A1MV01RC1,8,563},	//( - , SCM) Заданная скорость движения  ББ1 от ИС
	{&iEM_TERB7MS31LIM,3,565},	//( - , SCM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{&iEM_TERA7MS31LIM,3,566},	//( - , SCM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{&fEM_R7UY00RSS,8,567},	//( - , SCM) Y-координата АЗ1 см
	{&iEM_TERA6VS12LIM,3,569},	//( - , SCM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{&iEM_TERA6VS22LIM,3,570},	//( - , SCM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{&iEM_TERB6VS12LIM,3,571},	//( - , SCM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{&iEM_TERB6VS22LIM,3,572},	//( - , SCM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{&iEM_TERA5VS22LIM,3,573},	//( - , SCM) Искажение: Движение створок НЛ1 к НУ
	{&iEM_TERA5VS12LIM,3,574},	//( - , SCM) Искажение: Движение створок НЛ1 к ВУ
	{&iEM_TERB5VS12LIM,3,575},	//( - , SCM) Искажение: Движение створок НЛ2 к ВУ
	{&iEM_TERB5VS22LIM,3,576},	//( - , SCM) Искажение: Движение створок НЛ2 к НУ
	{&iEM_TERR1VS12LIM,3,577},	//( - , SCM) Искажение: Движение МДЗ1 в сторону ВУ
	{&iEM_TERR1VS22LIM,3,578},	//( - , SCM) Искажение: Движение МДЗ1 в сторону НУ
	{&iEM_TERR2VS12LIM,3,579},	//( - , SCM) Искажение: Движение МДЗ2 в сторону ВУ
	{&iEM_TERR2VS22LIM,3,580},	//( - , SCM) Искажение: Движение МДЗ2 в сторону НУ
	{&iEM_TERR4VS12LDU,3,581},	//( - , SCM) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{&iEM_TERR4VS22LDU,3,582},	//( - , SCM) Искажение: Движение реактора к «У ЗАЩИТЫ»
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
	{&R0IS01FI0,3,6},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
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
	{&R0IS01FI0,3,6},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
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
	{&R0IS01FI0,3,6},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
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
	{&R0IS01FI0,3,6},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
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
	{&R0IS01FI0,3,10},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
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
#include <drivers/ao16.h>
static char buf_AO1601[127];	//AO16
static ao16_inimod ini_AO1601={0xffff,120,0x43,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_AO1601={0,0,&ini_AO1601,buf_AO1601,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_AO1601[]={
	{&A2IP01IZ2,3,15},
	{&A2IP01IZ1,3,3},
	{&B0IT03IRP,3,33},
	{&B0IT02IZ2,3,18},
	{&B0IT01IZ1,3,6},
	{&A0IT02IZ2,3,12},
	{&A0IT03IRP,3,30},
	{&B2IP01IZ1,3,9},
	{&B2IP01IZ2,3,21},
	{&A3IP02IDU,3,24},
	{&A0IT01IZ1,3,0},
	{&B3IP02IDU,3,27},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F01[137];	//do32_5f(0x100)
static do32_pti_inipar ini_DO32_5F01={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F01={0,0,&ini_DO32_5F01,buf_DO32_5F01,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F01[]={
	{&A0VP81LZZ,1,52},
	{&R7II72LZ1,1,48},
	{&R7II71LZ1,1,46},
	{&R7II73LZ1,1,50},
	{&A1VP81LZZ,1,54},
	{&A3IS11LDU,1,8},
	{&A3IS22LDU,1,10},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F02[137];	//do32_5f(0x110)
static do32_pti_inipar ini_DO32_5F02={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F02={0,0,&ini_DO32_5F02,buf_DO32_5F02,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F02[]={
	{&B3IS22LDU,1,22},
	{&B0VP81LZZ,1,58},
	{&R7II73LZ2,1,50},
	{&R7II71LZ2,1,46},
	{&R7II72LZ2,1,48},
	{&B3IS11LDU,1,20},
	{&B1VP81LZZ,1,60},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F08[137];	//do32_5f(0x130)
static do32_pti_inipar ini_DO32_5F08={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F08={0,0,&ini_DO32_5F08,buf_DO32_5F08,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F08[]={
	{&B7AS31LDU,1,10},
	{&B3IS21LDU,1,24},
	{&A7AS31LDU,1,60},
	{&B1IS12LDU,1,12},
	{&B1IS11LDU,1,14},
	{&B1IS21LDU,1,16},
	{&B2IS11LDU,1,20},
	{&B2IS21LDU,1,22},
	{&B9IS21LDU,1,40},
	{&B9IS11LDU,1,38},
	{&A9IS21LDU,1,36},
	{&A9IS11LDU,1,34},
	{&R2IS21LDU,1,48},
	{&R2IS11LDU,1,46},
	{&R1IS21LDU,1,44},
	{&R1IS11LDU,1,42},
	{&R8IS11LDU,1,26},
	{&A4IS21LDU,1,32},
	{&A4IS11LDU,1,30},
	{&B2IS12LDU,1,18},
	{&A1IS12LDU,1,62},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F09[137];	//do32_5f(0x140)
static do32_pti_inipar ini_DO32_5F09={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F09={0,0,&ini_DO32_5F09,buf_DO32_5F09,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F09[]={
	{&A2IS21LDU,1,8},
	{&R4IS12LDU,1,44},
	{&R4IS22LDU,1,48},
	{&R4IS21LDU,1,46},
	{&R4IS11LDU,1,42},
	{&A2IS11LDU,1,6},
	{&A2IS12LDU,1,4},
	{&A6IS21LDU,1,52},
	{&B6IS11LDU,1,58},
	{&A3IS21LDU,1,10},
	{&B5IS11LDU,1,62},
	{&A5IS21LDU,1,56},
	{&A5IS11LDU,1,54},
	{&B4IS21LDU,1,14},
	{&B4IS11LDU,1,12},
	{&B6IS21LDU,1,60},
	{&A1IS21LDU,1,2},
	{&R0IS02LDU,1,32},
	{&A1IS11LDU,1,0},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F05[137];	//do32_5f(0x150)
static do32_pti_inipar ini_DO32_5F05={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F05={0,0,&ini_DO32_5F05,buf_DO32_5F05,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F05[]={
	{&B8IS11LDU,1,14},
	{&R5IS21LDU,1,20},
	{&A6IS11LDU,1,34},
	{&A8IS12LDU,1,28},
	{&A8IS22LDU,1,30},
	{&B8IS21LDU,1,8},
	{&R6IS21LDU,1,26},
	{&R5IS11LDU,1,18},
	{&R3IS21LDU,1,4},
	{&B8IS12LDU,1,10},
	{&R3IS11LDU,1,2},
	{&B8IS22LDU,1,12},
	{&B5IS21LDU,1,0},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F06[137];	//do32_5f(0x160)
static do32_pti_inipar ini_DO32_5F06={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F06={0,0,&ini_DO32_5F06,buf_DO32_5F06,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F06[]={
	{NULL,0,0},
};
#pragma pop
#include <drivers/emul8enc.h>
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
#include <drivers/vds32_pti.h>
static char buf_VDS32F07[66];	//vds32f2(0x340)
static vds32pti_inimod ini_VDS32F07={0,};
#pragma pack(push,1)
static table_drv table_VDS32F07={0,0,&ini_VDS32F07,buf_VDS32F07,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F07[]={
	{&A2AD33LDU,1,26},
	{&A3AD31LDU,1,30},
	{&B3AD31LDU,1,58},
	{&B4AD10LDU,1,56},
	{&A4AD10LDU,1,28},
	{&B3AD34LDU,1,50},
	{&A3AD34LDU,1,22},
	{&B7AP31LDU,1,60},
	{&A7AP31LDU,1,32},
	{&B3AD33LDU,1,52},
	{&A3AD33LDU,1,24},
	{&B5AD20LDU,1,48},
	{&B5AD10LDU,1,46},
	{&A5AD20LDU,1,44},
	{&A5AD10LDU,1,42},
	{&R2AD20LDU,1,40},
	{&R2AD10LDU,1,38},
	{&R1AD20LDU,1,36},
	{&R1AD10LDU,1,34},
	{&A8AD10LDU,1,62},
	{&B2AD33LDU,1,54},
	{NULL,0,0},
};
#pragma pop
#include <drivers/vds32_pti.h>
static char buf_VDS32F10[66];	//vds32f2(0x360)
static vds32pti_inimod ini_VDS32F10={0,};
#pragma pack(push,1)
static table_drv table_VDS32F10={0,0,&ini_VDS32F10,buf_VDS32F10,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F10[]={
	{&A3AD11LDU,1,18},
	{&A8AD20LDU,1,0},
	{&A6AD10LDU,1,2},
	{&A6AD20LDU,1,4},
	{&B6AD10LDU,1,6},
	{&B6AD20LDU,1,8},
	{&B3AD05LDU,1,44},
	{&B3AD04LDU,1,42},
	{&B3AD03LDU,1,40},
	{&B3AD02LDU,1,38},
	{&B3AD01LDU,1,36},
	{&B3AD21LDU,1,34},
	{&B3AD11LDU,1,32},
	{&A3AD05LDU,1,30},
	{&A3AD04LDU,1,28},
	{&A3AD03LDU,1,26},
	{&A3AD21LDU,1,20},
	{&A3AD01LDU,1,22},
	{&A3AD02LDU,1,24},
	{&A1AD11LDU,1,50},
	{&A1AD21LDU,1,52},
	{&A1AD01LDU,1,54},
	{&A1AD02LDU,1,56},
	{&A1AD03LDU,1,58},
	{&A1AD04LDU,1,60},
	{&B9AD10LDU,1,48},
	{&A9AD10LDU,1,46},
	{&B8AD20LDU,1,16},
	{&B8AD10LDU,1,14},
	{&R4AD20LDU,1,12},
	{&R4AD10LDU,1,10},
	{NULL,0,0},
};
#pragma pop
#include <drivers/vds32_pti.h>
static char buf_VDS32F11[66];	//vds32f2(0x310)
static vds32pti_inimod ini_VDS32F11={0,};
#pragma pack(push,1)
static table_drv table_VDS32F11={0,0,&ini_VDS32F11,buf_VDS32F11,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F11[]={
	{&B2AD21LDU,1,32},
	{&R0AD16LDU,1,62},
	{&B2AD11LDU,1,30},
	{&B2AD01LDU,1,34},
	{&A2AD04LDU,1,26},
	{&R8AD21LDU,1,60},
	{&A2AD05LDU,1,28},
	{&A2AD32LDU,1,48},
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
	{&B2AD05LDU,1,42},
	{&B2AD04LDU,1,40},
	{&B2AD03LDU,1,38},
	{&B2AD32LDU,1,56},
	{&B2AD31LDU,1,58},
	{&B1AD32LDU,1,52},
	{&B1AD31LDU,1,54},
	{&B2AD02LDU,1,36},
	{&A2AD01LDU,1,20},
	{&A2AD02LDU,1,22},
	{&A1AD31LDU,1,46},
	{&A1AD32LDU,1,44},
	{&A2AD31LDU,1,50},
	{&A2AD03LDU,1,24},
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
	setAsFloat(281,0.015);
	setAsFloat(282,0.0069);
	setAsFloat(283,0.21);
	setAsFloat(284,0);
	setAsFloat(285,0);
	setAsFloat(286,0.0096);
	setAsFloat(287,0.0026);
	setAsFloat(288,106);
	setAsFloat(289,135.227);
	setAsFloat(290,25);
	setAsFloat(291,320.435466);
	setAsFloat(292,0.0055);
	setAsFloat(293,0.000877);
	setAsFloat(294,200);
	setAsFloat(295,100);
	setAsFloat(296,0);
	setAsFloat(297,0);
	setAsFloat(298,100);
	setAsFloat(299,80);
	setAsFloat(300,0.002375);
	setAsFloat(301,0);
	setAsFloat(302,165);
	setAsFloat(303,200);
	setAsFloat(304,0.001675);
	setAsFloat(305,40);
	setAsFloat(306,15630.0);
	setAsFloat(307,1374);
	setAsFloat(308,0);
	setAsFloat(309,390.0);
	setAsFloat(310,2000.0);
	setAsFloat(311,1500.0);
	setAsFloat(312,10.91);
	setAsFloat(313,10.91);
	setAsFloat(314,1500.0);
	setAsFloat(315,2000);
	setAsFloat(316,390.0);
	setAsFloat(317,0);
	setAsFloat(318,55.0);
	setAsFloat(319,15.0);
	setAsFloat(320,5.0);
	setAsFloat(321,1E12);
	setAsFloat(322,43.6);
	setAsFloat(323,20.0);
	setAsFloat(324,20.0);
	setAsFloat(325,20.0);
	setAsFloat(326,1269.0);
	setAsFloat(327,256.0);
	setAsFloat(328,1.0);
	setAsFloat(329,2.0);
	setAsFloat(330,0);
	setAsFloat(331,0.026);
	setAsFloat(332,0.08);
	setAsFloat(333,0.0);
	setAsFloat(334,27.108);
	setAsFloat(335,600);
	setAsFloat(336,0);
	setAsFloat(337,0.00009765625);
	setAsFloat(338,1.6);
	setAsFloat(339,0);
	setAsFloat(340,0.00009765625);
	setAsFloat(341,2.5);
	setAsFloat(342,0);
	setAsFloat(343,0.00009765625);
	setAsFloat(344,10000.0);
	setAsFloat(345,0.0009765625);
	setAsFloat(346,750);
	setAsFloat(347,100);
	setAsFloat(348,200);
	setAsFloat(349,300);
	setAsFloat(350,400);
	setAsFloat(351,500);
	setAsFloat(352,600);
	setAsFloat(353,0.50);
	setAsFloat(354,0.50);
	setAsFloat(355,0.50);
	setAsFloat(356,2);
	setAsFloat(357,11.0);
	setAsFloat(358,1585.0);
	setAsFloat(359,1796.0);
	setAsFloat(360,1555.0);
	setAsFloat(361,1269.0);
	setAsFloat(362,1269.0);
	setAsFloat(363,1585.0);
	setAsFloat(364,1796.0);
	setAsFloat(365,1269.0);
	setAsFloat(366,248.0);
	setAsFloat(367,284.5);
	setAsFloat(368,248.0);
	setAsFloat(369,271.6);
	setAsFloat(370,287.2);
	setAsFloat(371,594.0);
	setAsFloat(372,559.0);
	setAsFloat(373,588.0);
	setAsFloat(374,1555.0);
	setAsFloat(375,1281.2);
	setAsFloat(376,1269.0);
	setAsFloat(377,594.0);
	setAsFloat(378,597.2);
	setAsFloat(379,556.8);
	setAsFloat(380,1.0);
	setAsFloat(381,1.0);
	setAsFloat(382,1.0);
	setAsFloat(383,1.0);
	setAsFloat(384,1.0);
	setAsFloat(385,1.0);
	setAsFloat(386,1.0);
	setAsFloat(387,1.0);
	setAsFloat(388,1.0);
	setAsFloat(389,1.0);
	setAsFloat(390,1.0);
	setAsFloat(391,1.0);
	setAsFloat(392,0);
	setAsFloat(393,0);
	setAsFloat(394,0);
	setAsFloat(395,0);
	setAsFloat(396,0.0);
	setAsFloat(397,0);
	setAsFloat(398,0.0);
	setAsFloat(399,0);
	setAsFloat(400,0.0);
	setAsFloat(401,0.0);
	setAsFloat(402,0.0);
	setAsFloat(403,0.0);
	setAsFloat(404,3703.704);
	setAsFloat(405,62500.0);
	setAsFloat(406,20);
	setAsFloat(407,18000);
	setAsFloat(408,18000);
	setAsFloat(409,18000);
	setAsFloat(410,0.76);
	setAsFloat(411,0.245);
	setAsFloat(412,2.9);
	setAsFloat(413,0.13);
	setAsFloat(414,0.73);
	setAsFloat(415,0.6);
	setAsFloat(416,9807.0);
	setAsFloat(417,22975.0);
	setAsFloat(418,12750.0);
	setAsFloat(419,20);
	setAsFloat(420,20);
	setAsFloat(421,0);
	setAsFloat(422,5.0);
	setAsFloat(423,5.0);
	setAsFloat(424,5.0);
	setAsFloat(425,100.0);
	setAsFloat(426,4000);
	setAsFloat(427,100000);
	setAsFloat(428,1000000);
	setAsFloat(429,32000.0);
	setAsFloat(430,5.0);
	setAsFloat(431,15.0);
	setAsFloat(432,15.0);
	setAsFloat(433,20.0);
	setAsFloat(434,10.0);
	setAsBool(435,0);
	setAsBool(436,0);
	setAsBool(437,0);
	setAsFloat(438,0.45);
	setAsFloat(439,0.39);
	setAsFloat(440,2.74);
	setAsFloat(441,0.07);
	setAsFloat(442,0.275);
	setAsFloat(443,0.245);
	setAsFloat(444,0.045);
	setAsFloat(445,0.05);
	setAsShort(446,0);
	setAsFloat(447,0);
	setAsFloat(448,0);
	setAsShort(449,0);
	setAsFloat(450,0);
	setAsFloat(451,0);
	setAsShort(452,0);
	setAsFloat(453,0);
	setAsFloat(454,0);
	setAsShort(455,0);
	setAsFloat(456,0);
	setAsFloat(457,0);
	setAsShort(458,0);
	setAsFloat(459,0);
	setAsFloat(460,0);
	setAsShort(461,0);
	setAsFloat(462,0);
	setAsFloat(463,0);
	setAsShort(464,0);
	setAsShort(465,0);
	setAsFloat(466,0);
	setAsShort(467,0);
	setAsShort(468,0);
	setAsFloat(469,0);
	setAsFloat(470,0);
	setAsFloat(471,0);
	setAsFloat(472,0);
	setAsFloat(473,0);
	setAsFloat(474,0);
	setAsFloat(475,0);
	setAsFloat(476,0);
	setAsShort(477,0);
	setAsShort(478,0);
	setAsShort(479,0);
	setAsShort(480,0);
	setAsShort(481,0);
	setAsShort(482,0);
	setAsShort(483,0);
	setAsShort(484,0);
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
	setAsFloat(561,0);
	setAsFloat(562,0);
	setAsShort(563,0);
	setAsFloat(564,0);
	setAsFloat(565,0);
	setAsShort(566,0);
	setAsFloat(567,0);
	setAsFloat(568,0);
	setAsShort(569,0);
	setAsFloat(570,0);
	setAsFloat(571,0);
	setAsShort(572,0);
	setAsFloat(573,0);
	setAsFloat(574,0);
	setAsBool(575,0);
	setAsBool(576,1);
	setAsBool(577,0);
	setAsBool(578,1);
	setAsBool(579,0);
	setAsShort(580,0);
	setAsFloat(581,0);
	setAsFloat(582,0);
	setAsShort(583,0);
	setAsFloat(584,0);
	setAsFloat(585,0);
	setAsShort(586,0);
	setAsFloat(587,0);
	setAsFloat(588,0);
	setAsShort(589,0);
	setAsFloat(590,0);
	setAsFloat(591,0);
	setAsBool(592,1);
	setAsFloat(593,0.01);
	setAsFloat(594,0.01);
	setAsFloat(595,0.01);
	setAsShort(596,0);
	setAsShort(597,0);
	setAsShort(598,0);
	setAsFloat(599,25.017338);
	setAsFloat(600,-0.15912805);
	setAsFloat(601,0.000000166);
	setAsFloat(602,25.017338);
	setAsFloat(603,0);
	setAsFloat(604,0.000167646);
	setAsFloat(605,0);
	setAsFloat(606,0.000167676);
	setAsFloat(607,0);
	setAsFloat(608,0);
	setAsFloat(609,0);
	setAsFloat(610,0);
	setAsFloat(611,0);
	setAsFloat(612,0);
	setAsFloat(613,0.000885839);
	setAsFloat(614,0.000885839);
	setAsFloat(615,0.000885839);
	setAsFloat(616,0.000885839);
	setAsFloat(617,390);
	setAsFloat(618,390);
	setAsFloat(619,55);
	setAsFloat(620,55);
	setAsFloat(621,0);
	setAsFloat(622,4000.0);
	setAsFloat(623,10);
	setAsFloat(624,0);
	setAsFloat(625,0);
	setAsFloat(626,5);
	setAsFloat(627,5);
	setAsFloat(628,0);
	setAsFloat(629,0);
	setAsFloat(630,0);
	setAsFloat(631,0);
	setAsFloat(632,15650);
	setAsFloat(633,0);
	setAsShort(634,0);
	setAsShort(635,0);
	setAsFloat(636,506.6);
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
	setAsFloat(651,5065.0);
	setAsFloat(652,1.0);
	setAsFloat(653,1.0);
	setAsFloat(654,1.0);
	setAsFloat(655,1570.0);
	setAsFloat(656,1269);
	setAsFloat(657,1281.2);
	setAsFloat(658,248.0);
	setAsFloat(659,572.4);
	setAsFloat(660,246.8);
	setAsFloat(661,1);
	setAsShort(102,2);
}
uspaint8 InternalBuf[1106];

/* ����������� �������� ��� � ������*/
ssbool lRM_1_ = {1,0}; /* ���� ������� ������� �� ����� ��� */ 
ssfloat fRM_0_ = {0,0}; /* �������� �������� �� ������ ��1 */ 
ssfloat fRM_1_ = {1,0}; /* *Vm - ������ ��������� �������� (����� � �������) */ 
ssbool lRM_0_ = {0,0}; /* ���� ������� ������� �� ����� ��� */ 
ssfloat fRM_1_0 = {1.0,0}; /* ����������� �������� �� (����/�) */ 
ssfloat fRM_180_0 = {180.0,0}; /* ���������� �������� �������� ����������� �� ���� */ 
ssfloat fRM_0_0 = {0.0,0}; /* ���������� ������ ������ �� ���� */ 
ssfloat fRM_n50_ = {-50,0}; /* ���������� ������� �������� ����������� �� ���� */ 
ssfloat fRM_2000_0 = {2000.0,0}; /* ���������� �������� �������� ����������� ��� �� */ 
ssfloat fRM_n150_ = {-150,0}; /* ���������� ������� �������� ����������� ��� �� */ 
ssfloat fRM_1500_0 = {1500.0,0}; /* ���������� �������� ������������� ����������� �� �� */ 
ssint iRM_7_ = {7,0}; /* N */ 
ssfloat fRM_390_ = {390,0}; /* Ai, i=1..N -�������� ������� ����� */ 
ssfloat fRM_420_ = {420,0}; /* Ai, i=1..N -�������� ������� ����� */ 
ssfloat fRM_513_ = {513,0}; /* Ai, i=1..N -�������� ������� ����� */ 
ssfloat fRM_767_ = {767,0}; /* Ai, i=1..N -�������� ������� ����� */ 
ssfloat fRM_900_ = {900,0}; /* Ai, i=1..N -�������� ������� ����� */ 
ssfloat fRM_1200_ = {1200,0}; /* Ai, i=1..N -�������� ������� ����� */ 
ssfloat fRM_1500_ = {1500,0}; /* Ai, i=1..N -�������� ������� ����� */ 
ssfloat fRM_3_546 = {3.546,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_2_7 = {2.7,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_2_ = {2,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_88884 = {0.88884,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_6221739 = {0.6221739,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_35555072 = {0.35555072,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_2666666667 = {0.2666666667,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssint iRM_5_ = {5,0}; /* N */ 
ssfloat fRM_600_ = {600,0}; /* Ai, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_5 = {0.5,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_2 = {0.2,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_088884 = {0.088884,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_066666667 = {0.066666667,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_02173913 = {0.02173913,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_002453 = {0.002453,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_00184 = {0.00184,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_10 = {0.10,0}; /* ���� ������������ �� ��(��) */ 
ssfloat fRM_0_50 = {0.50,0}; /* ���� ������������ �� ��� (��) */ 
ssint iRM_2_ = {2,0}; /* n - N-����������� ������� x */ 
ssint iRM_3_ = {3,0}; /* N-����� ������ */ 
ssint iRM_4_ = {4,0}; /* N-����� ������ */ 
ssint iRM_0_ = {0,0}; /* Ter - ������������� ��������� */ 
ssfloat fRM_100000_ = {100000,0}; /* KPv - ���������� ���. ����������� ��������� �� */ 
ssfloat fRM_n100_ = {-100,0}; /* KZv - ���������� ���. ����������� ��������� �� */ 
ssfloat fRM_20_ = {20,0}; /* Tp - ��������� ���� �� */ 
sschar bRM_2_ = {2,0}; /* type - ��� ������ */ 
sschar bRM_4_ = {4,0}; /* type - ��� ������ */ 
sschar bRM_5_ = {5,0}; /* type - ��� ������ */ 
sschar bRM_1_ = {1,0}; /* type - ��� ������ */ 
ssint iRM_500_ = {500,0}; /* tz - ������ ��������, 10-�� �� */ 
ssfloat fRM_3_ = {3,0}; /* m1 - �������� ���������� ������� ������� �� �������� */ 
ssfloat fRM_2_0 = {2.0,0}; /* ampl - ��������� ��������������� ���������� */ 
ssint iRM_3276_ = {3276,0}; /* min - ����������� ��������� �������� ��������� ������� */ 
ssint iRM_16383_ = {16383,0}; /* max - ������������ ��������� �������� ��������� ������� */ 
ssfloat fRM_3276_ = {3276,0}; /* c   - ���. �������� ���� ��� */ 
ssfloat fRM_16383_ = {16383,0}; /* d - ����.  �������� ���� ��� */ 
ssfloat fRM_200_ = {200,0}; /* maxs1 - ���c. �������� ������� ������� */ 
ssfloat fRM_0_0015 = {0.0015,0}; /* m1 - �������� ���������� ������� ������� �� �������� */ 
ssfloat fRM_0_001 = {0.001,0}; /* ampl - ��������� ��������������� ���������� */ 
ssfloat fRM_0_1 = {0.1,0}; /* k - ����������� �������� */ 
ssint iRM_16_ = {16,0}; /* n - N-����������� ������� ������� ���������� */ 
ssfloat fRM_2000_ = {2000,0}; /* maxs1 - ���c. �������� ������� ������� */ 
ssfloat fRM_15_ = {15,0}; /* m1 - �������� ���������� ������� ������� �� �������� */ 
ssint iRM_1_ = {1,0}; /* ������� ��������� */ 

uspaint8 SpaEEPROMBuf[1636];

/* ����������� ���������� */
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

/* ���������� �������� */
psbool  array_m347_x_1[16] = {&lEM_R8AD10LC1,&lEM_R8AD10LC1,&var329,&var187,&var181,&var271,&var269,&var263,&var260,&var276,&var319,&var314,&var305,&var295,&var289,&R0MW13LP2};
psbool  array_m897_x_1[2] = {&lEM_R0IE02LRP,&lEM_R0IE01LRP};
psbool  array_m892_x_1[2] = {&var167,&R0MW13LP2};
psbool  array_m917_x_1[2] = {&var174,&R0MW13LP2};
psbool  array_m910_x_1[2] = {&var175,&R0MW13LP2};
psbool  array_m902_x_1[2] = {&var176,&R0MW13LP2};
psbool  array_m609_x_1[2] = {&var32,&var228};
psbool  array_m606_x_1[2] = {&var32,&var229};
psbool  array_m615_x_1[3] = {&lEM_C1AD31LRP,&R0VZ71LZ1,&R0VZ71LZ2};
psbool  array_m894_x_1[2] = {&var199,&R0MW13LP2};
psbool  array_m284_x_1[2] = {&var216,&B3AD31LDU};
psbool  array_m250_x_1[3] = {&B2AD31LDU,&var202,&var216};
psbool  array_m251_x_1[3] = {&B2AD32LDU,&var202,&var216};
psbool  array_m213_x_1[4] = {&B1AD32LDU,&var205,&var204,&var216};
psbool  array_m212_x_1[4] = {&var205,&B1AD31LDU,&var204,&var216};
psbool  array_m118_x_1[2] = {&A3AD31LDU,&var216};
psbool  array_m48_x_1[4] = {&A1AD32LDU,&var210,&var209,&var216};
psbool  array_m47_x_1[4] = {&var210,&A1AD31LDU,&var209,&var216};
psbool  array_m85_x_1[3] = {&A2AD31LDU,&var214,&var216};
psbool  array_m86_x_1[3] = {&A2AD32LDU,&var214,&var216};
psbool  array_m622_x_1[2] = {&var227,&var31};
psfloat  array_m7_a_1[5] = {&fRM_390_,&fRM_600_,&fRM_900_,&fRM_1200_,&fRM_1500_};
psfloat  array_m7_b_1[5] = {&fRM_0_5,&fRM_0_2,&fRM_0_088884,&fRM_0_066666667,&fRM_0_02173913};
psfloat  array_m9_a_1[7] = {&fRM_390_,&fRM_420_,&fRM_513_,&fRM_767_,&fRM_900_,&fRM_1200_,&fRM_1500_};
psfloat  array_m9_b_1[7] = {&fRM_3_546,&fRM_2_7,&fRM_2_,&fRM_0_88884,&fRM_0_6221739,&fRM_0_35555072,&fRM_0_2666666667};
psfloat  array_m177_C0_1[6];
psfloat  array_m295_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m130_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m259_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m94_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m224_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m59_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m14_C0_1[6];

/* ���������� �������� */
_S_to3val  S_to3val_946_1 = {&fEM_R7UX16RSS,&fRM_900_,&fRM_15_,&fRM_0_0015,&fRM_0_,&fRM_2000_,&fRM_2000_,&TerR0IN06FRP,&var1,&var2,&vainSFloat,&bFirstEnterFlag};
_S_vchs  S_vchs_872_1 = {&var280,&var331,&var241,&fEM_R4UC23RIM,&fEM_R7UY00RSS,&fEM_R7UX15RSS,&fEM_R7UY15RSS,&bRM_5_,&fEM_A0UX15RSS,&fEM_B0UX05RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var3,&internal1_m872_Chim0};
_S_vchs  S_vchs_862_1 = {&var331,&var280,&var241,&fEM_R4UC23RIM,&fEM_R7UY00RSS,&fEM_R7UX14RSS,&fEM_R7UY14RSS,&bRM_4_,&fEM_A0UX14RSS,&fEM_B0UX04RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var4,&internal1_m862_Chim0};
_S_vchs  S_vchs_854_1 = {&var331,&var280,&var241,&fEM_R4UC23RIM,&fEM_R7UY00RSS,&fEM_R7UX13RSS,&fEM_R7UY13RSS,&bRM_2_,&fEM_A0UX13RSS,&fEM_B0UX03RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var5,&internal1_m854_Chim0};
_S_twobool  S_twobool_809_1 = {&var278,&iEM_TERR4VS22LDU,&var6,&vainSBool,&internal1_m809_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_808_1 = {&var277,&iEM_TERR4VS12LDU,&var7,&vainSBool,&internal1_m808_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_991_1 = {&var254,&iEM_TERR2VS22LIM,&var8,&vainSBool,&internal1_m991_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_990_1 = {&var253,&iEM_TERR2VS12LIM,&var9,&vainSBool,&internal1_m990_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_989_1 = {&var258,&iEM_TERR1VS22LIM,&var10,&vainSBool,&internal1_m989_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_988_1 = {&var257,&iEM_TERR1VS12LIM,&var11,&vainSBool,&internal1_m988_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_668_1 = {&var246,&iEM_TERB5VS22LIM,&var12,&vainSBool,&internal1_m668_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_667_1 = {&var245,&iEM_TERB5VS12LIM,&var13,&vainSBool,&internal1_m667_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_646_1 = {&var250,&iEM_TERA5VS22LIM,&var14,&vainSBool,&internal1_m646_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_645_1 = {&var249,&iEM_TERA5VS12LIM,&var15,&vainSBool,&internal1_m645_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_666_1 = {&var262,&iEM_TERB6VS22LIM,&var16,&vainSBool,&internal1_m666_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_665_1 = {&var261,&iEM_TERB6VS12LIM,&var17,&vainSBool,&internal1_m665_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_644_1 = {&var266,&iEM_TERA6VS22LIM,&var18,&vainSBool,&internal1_m644_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_643_1 = {&var265,&iEM_TERA6VS12LIM,&var19,&vainSBool,&internal1_m643_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_510_1 = {&var37,&iEM_TERA1VP81LIM,&var20,&vainSBool,&internal1_m510_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_526_1 = {&var37,&iEM_TERB1VP81LIM,&var21,&vainSBool,&internal1_m526_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_398_1 = {&var305,&iEM_TERB2SS33LIM,&var22,&vainSBool,&internal1_m398_Out10,&bFirstEnterFlag};
_S_noto  S_noto_473_1 = {&var183,&var23};
_S_noto  S_noto_474_1 = {&var182,&var24};
_S_noto  S_noto_463_1 = {&var184,&var25};
_S_noto  S_noto_466_1 = {&var185,&var26};
_S_rs  S_rs_471_1 = {&var24,&lEM_R5AD10LC1,&var27,&vainSBool,&internal1_m471_q0};
_S_rs  S_rs_472_1 = {&var23,&lEM_R5AD20LC1,&var28,&vainSBool,&internal1_m472_q0};
_S_rs  S_rs_459_1 = {&var25,&lEM_R3AD10LC1,&var29,&vainSBool,&internal1_m459_q0};
_S_rs  S_rs_460_1 = {&var26,&lEM_R3AD20LC1,&var30,&vainSBool,&internal1_m460_q0};
_S_andn  S_andn_347_1 = {array_m347_x_1,&iRM_16_,&vainSBool};
_S_zpfs  S_zpfs_619_1 = {&R0AD14LDU,&fEM_R7UI76RIM,&var31,&internal1_m619_tx,&internal1_m619_y0};
_S_zpfs  S_zpfs_607_1 = {&R0AD16LDU,&fEM_R7UI77RIM,&var32,&internal1_m607_tx,&internal1_m607_y0};
_S_bol  S_bol_932_1 = {&fEM_A4UP01RIM,&fEM_A4UP02RIM,&var33};
_S_bol  S_bol_929_1 = {&fEM_A3UP01RIM,&fEM_A3UP02RIM,&var34};
_S_bol  S_bol_908_1 = {&fEM_A0UP02RIM,&fEM_A0UP01RIM,&var35};
_S_bol  S_bol_930_1 = {&fEM_A2UP02RIM,&fEM_A2UP03RIM,&var36};
_S_bol  S_bol_920_1 = {&fEM_A1UP01RIM,&fEM_A1UP82RIM,&var37};
_S_ampl  S_ampl_363_1 = {&var218,&fRM_0_1,&vainSFloat};
_S_or2  S_or2_921_1 = {&R0EE04LZ1,&R0EE04LZ2,&var38};
_S_or2  S_or2_912_1 = {&R0EE03LZ1,&R0EE03LZ2,&var39};
_S_or2  S_or2_905_1 = {&R0EE02LZ1,&R0EE02LZ2,&var40};
_S_or2  S_or2_898_1 = {&R0EE01LZ1,&R0EE01LZ2,&var41};
_S_zpfs  S_zpfs_595_1 = {&var186,&fRM_1_0,&var42,&internal1_m595_tx,&internal1_m595_y0};
_S_zpfs  S_zpfs_593_1 = {&var189,&fRM_0_5,&var43,&internal1_m593_tx,&internal1_m593_y0};
_S_twobool  S_twobool_203_1 = {&B1AD21LDU,&iEM_TERB1IE04LDU,&var44,&vainSBool,&internal1_m203_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_221_1 = {&B1AD11LDU,&iEM_TERB1IE03LDU,&var45,&vainSBool,&internal1_m221_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_41_1 = {&A1AD21LDU,&iEM_TERA1IE04LDU,&var46,&vainSBool,&internal1_m41_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_56_1 = {&A1AD11LDU,&iEM_TERA1IE03LDU,&var47,&vainSBool,&internal1_m56_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_962_1 = {&var322,&iEM_TERB1SS12LIM,&var48,&vainSBool,&internal1_m962_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_959_1 = {&var318,&iEM_TERB1SS11LIM,&var49,&vainSBool,&internal1_m959_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_958_1 = {&var319,&iEM_TERB1SS21LIM,&var50,&vainSBool,&internal1_m958_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_961_1 = {&var52,&fEM_A1UC03RDU,&fRM_0_,&iRM_0_,&var51,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m961_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_956_1 = {&var221,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB1MC01RIM,&var52,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_944_1 = {&var54,&fEM_A1UC03RDU,&fRM_0_,&iRM_0_,&var53,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m944_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_937_1 = {&var222,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA1SC01RIM,&var54,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_945_1 = {&var329,&iEM_TERA1SS12LIM,&var55,&vainSBool,&internal1_m945_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_942_1 = {&var326,&iEM_TERA1SS11LIM,&var56,&vainSBool,&internal1_m942_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_941_1 = {&var327,&iEM_TERA1SS21LIM,&var57,&vainSBool,&internal1_m941_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1029_1 = {&var260,&iEM_TERB6SS21LIM,&var58,&vainSBool,&internal1_m1029_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1010_1 = {&var259,&iEM_TERB6SS11LIM,&var59,&vainSBool,&internal1_m1010_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1009_1 = {&var264,&iEM_TERA6SS21LIM,&var60,&vainSBool,&internal1_m1009_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1008_1 = {&var263,&iEM_TERA6MS11LIM,&var61,&vainSBool,&internal1_m1008_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_830_1 = {&var269,&iEM_TERA8SS12LIM,&var62,&vainSBool,&internal1_m830_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_832_1 = {&var268,&iEM_TERA8SS22LIM,&var63,&vainSBool,&internal1_m832_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_829_1 = {&var272,&iEM_TERB8SS12LIM,&var64,&var65,&internal1_m829_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_831_1 = {&var271,&iEM_TERB8SS22LIM,&var66,&var67,&internal1_m831_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_805_1 = {&var273,&iEM_TERR4SS12LIM,&var68,&vainSBool,&internal1_m805_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_806_1 = {&var274,&iEM_TERR4SS22LIM,&var69,&vainSBool,&internal1_m806_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_804_1 = {&var276,&iEM_TERR4MS21LIM,&var70,&vainSBool,&internal1_m804_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_803_1 = {&var275,&iEM_TERR4SS11LIM,&var71,&vainSBool,&internal1_m803_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1024_1 = {&var33,&iEM_TERA4VP82LIM,&var72,&var73,&internal1_m1024_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_976_1 = {&var252,&iEM_TERR2SS21LIM,&var74,&vainSBool,&internal1_m976_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_975_1 = {&var251,&iEM_TERR2SS11LIM,&var75,&vainSBool,&internal1_m975_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_974_1 = {&var256,&iEM_TERR1SS21LIM,&var76,&vainSBool,&internal1_m974_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_973_1 = {&var255,&iEM_TERR1SS11LIM,&var77,&vainSBool,&internal1_m973_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1025_1 = {&var191,&iEM_TERB4SS21LIM,&var78,&vainSBool,&internal1_m1025_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1006_1 = {&var190,&iEM_TERB4SS11LIM,&var79,&vainSBool,&internal1_m1006_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_807_1 = {&lEM_R8AD10LC1,&iEM_TERR8SS11LIM,&var80,&vainSBool,&internal1_m807_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1007_1 = {&var188,&iEM_TERA4SS21LIM,&var81,&vainSBool,&internal1_m1007_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1005_1 = {&var187,&iEM_TERA4SS11LIM,&var82,&vainSBool,&internal1_m1005_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1026_1 = {&var183,&iEM_TERR5SS21LIM,&var83,&vainSBool,&internal1_m1026_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1004_1 = {&var182,&iEM_TERR5SS11LIM,&var84,&vainSBool,&internal1_m1004_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_987_1 = {&var185,&iEM_TERR3SS21LIM,&var85,&vainSBool,&internal1_m987_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_972_1 = {&var184,&iEM_TERR3SS11LIM,&var86,&vainSBool,&internal1_m972_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_527_1 = {&var36,&iEM_TERA2VP82LIM,&var87,&var88,&internal1_m527_Out10,&bFirstEnterFlag};
_S_toao  S_toao_531_1 = {&var92,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var89,&bFirstEnterFlag};
_S_toao  S_toao_530_1 = {&var91,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var90,&bFirstEnterFlag};
_S_to3val  S_to3val_524_1 = {&var149,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A2UP03RDU,&fEM_A2UP03RDU,&iEM_TERB2SP01RIM,&var91,&vainSFloat,&var92,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_408_1 = {&var94,&fEM_A2UC03RDU,&fRM_0_,&iRM_0_,&var93,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m408_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_402_1 = {&var220,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB2SC01RIM,&var94,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_399_1 = {&var307,&iEM_TERB2SS12LIM,&var95,&vainSBool,&internal1_m399_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_401_1 = {&var302,&iEM_TERB2SS11LIM,&var96,&vainSBool,&internal1_m401_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_400_1 = {&var303,&iEM_TERB2SS21LIM,&var97,&vainSBool,&internal1_m400_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_845_1 = {&var197,&iEM_TERB9SS21LIM,&var98,&vainSBool,&internal1_m845_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_846_1 = {&var196,&iEM_TERB9SS11LIM,&var99,&vainSBool,&internal1_m846_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_844_1 = {&var194,&iEM_TERA9SS21LIM,&var100,&vainSBool,&internal1_m844_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1028_1 = {&var193,&iEM_TERA9SS11LIM,&var101,&vainSBool,&internal1_m1028_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_681_1 = {&var244,&iEM_TERB5SS21LIM,&var102,&vainSBool,&internal1_m681_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_682_1 = {&var243,&iEM_TERB5SS11LIM,&var103,&vainSBool,&internal1_m682_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_679_1 = {&var248,&iEM_TERA5SS21LIM,&var104,&vainSBool,&internal1_m679_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_680_1 = {&var247,&iEM_TERA5SS11LIM,&var105,&vainSBool,&internal1_m680_Out10,&bFirstEnterFlag};
_S_ampl  S_ampl_632_1 = {&var226,&fEM_R7UI75RIM,&var106};
_S_to3val  S_to3val_633_1 = {&var106,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R7UI74RIM,&fEM_R7UI74RIM,&iEM_TERR7SI74RIM,&vainSFloat,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_543_1 = {&var35,&iEM_TERB0VP81LIM,&var107,&vainSBool,&internal1_m543_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_542_1 = {&var35,&iEM_TERA0VP81LIM,&var108,&vainSBool,&internal1_m542_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_826_1 = {&var110,&fEM_A8UC03RDU,&fRM_0_,&iRM_0_,&var109,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m826_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_818_1 = {&var270,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB8SC01RIM,&var110,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_828_1 = {&var112,&fEM_A8UC03RDU,&fRM_0_,&iRM_0_,&var111,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m828_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_820_1 = {&var267,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA8SC01RIM,&var112,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_678_1 = {&R0MW13LP2,&iEM_TERR6IS68LIM,&var113,&vainSBool,&internal1_m678_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_662_1 = {&R0MW13LP2,&iEM_TERR6IS67LIM,&var114,&vainSBool,&internal1_m662_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_642_1 = {&R0MW13LP2,&iEM_TERR6IS66LIM,&var115,&vainSBool,&internal1_m642_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_661_1 = {&R0MW13LP2,&iEM_TERR6IS64LIM,&var116,&var117,&internal1_m661_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_641_1 = {&R0MW13LP2,&iEM_TERR6IS62LIM,&var118,&var119,&internal1_m641_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_329_1 = {&var288,&iEM_TERB3SS22LIM,&var120,&vainSBool,&internal1_m329_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_328_1 = {&var295,&iEM_TERA3SS22LIM,&var121,&vainSBool,&internal1_m328_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_313_1 = {&var289,&iEM_TERB3SS11LIM,&var122,&vainSBool,&internal1_m313_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_312_1 = {&var296,&iEM_TERA3SS11LIM,&var123,&vainSBool,&internal1_m312_Out10,&bFirstEnterFlag};
_S_toao  S_toao_505_1 = {&var125,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var124,&bFirstEnterFlag};
_S_to3val  S_to3val_498_1 = {&var171,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A3UP03RDU,&fEM_A3UP03RDU,&iEM_TERA3SP02RIM,&vainSFloat,&var125,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_544_1 = {&var34,&iEM_TERA3VP81LIM,&var126,&var127,&internal1_m544_Out10,&bFirstEnterFlag};
_S_toao  S_toao_509_1 = {&var129,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var128,&bFirstEnterFlag};
_S_to3val  S_to3val_501_1 = {&var169,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A3UP03RDU,&fEM_A3UP03RDU,&iEM_TERB3SP02RIM,&vainSFloat,&var129,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_342_1 = {&var292,&iEM_TERB3SS33LIM,&var130,&vainSBool,&internal1_m342_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_326_1 = {&var132,&fEM_A3UC03RDU,&fRM_0_,&iRM_0_,&var131,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m326_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_325_1 = {&var287,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB3SC01RIM,&var132,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_341_1 = {&var291,&iEM_TERB3SS31LIM,&var133,&vainSBool,&internal1_m341_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_339_1 = {&var299,&iEM_TERA3SS33LIM,&var134,&vainSBool,&internal1_m339_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_319_1 = {&var136,&fEM_A3UC03RDU,&fRM_0_,&iRM_0_,&var135,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m319_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_315_1 = {&var294,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA3SC01RIM,&var136,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_340_1 = {&var298,&iEM_TERA3SS31LIM,&var137,&vainSBool,&internal1_m340_Out10,&bFirstEnterFlag};
_S_toao  S_toao_529_1 = {&var150,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var138,&bFirstEnterFlag};
_S_toao  S_toao_528_1 = {&var148,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var139,&bFirstEnterFlag};
_S_twobool  S_twobool_311_1 = {&var290,&iEM_TERB3SS21LIM,&var140,&vainSBool,&internal1_m311_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_327_1 = {&var297,&iEM_TERA3SS21LIM,&var141,&vainSBool,&internal1_m327_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_420_1 = {&var313,&iEM_TERA2SS33LIM,&var142,&vainSBool,&internal1_m420_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_421_1 = {&var144,&fEM_A2UC03RDU,&fRM_0_,&iRM_0_,&var143,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m421_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_416_1 = {&var219,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA2SC01RIM,&var144,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_419_1 = {&var315,&iEM_TERA2SS12LIM,&var145,&vainSBool,&internal1_m419_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_418_1 = {&var310,&iEM_TERA2SS11LIM,&var146,&vainSBool,&internal1_m418_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_417_1 = {&var311,&iEM_TERA2SS21LIM,&var147,&vainSBool,&internal1_m417_Out10,&bFirstEnterFlag};
_S_to3val  S_to3val_523_1 = {&fEM_A2UP01RIM,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A2UP03RDU,&fEM_A2UP03RDU,&iEM_TERA2SP01RIM,&var148,&var149,&var150,&bFirstEnterFlag};
_S_toao  S_toao_158_1 = {&var156,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var151,&bFirstEnterFlag};
_S_toao  S_toao_157_1 = {&var155,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var152,&bFirstEnterFlag};
_S_toao  S_toao_156_1 = {&var154,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var153,&bFirstEnterFlag};
_S_to3val  S_to3val_151_1 = {&var282,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R0UT02RDU,&fEM_R0UT02RDU,&iEM_TERB0MT01RIM,&var154,&var155,&var156,&bFirstEnterFlag};
_S_toao  S_toao_161_1 = {&var164,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var157,&bFirstEnterFlag};
_S_toao  S_toao_160_1 = {&var163,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var158,&bFirstEnterFlag};
_S_twobool  S_twobool_1027_1 = {&var181,&iEM_TERR6SS21LIM,&var159,&vainSBool,&internal1_m1027_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_145_1 = {&var283,&iEM_TERB7MS31LIM,&var160,&vainSBool,&internal1_m145_Out10,&bFirstEnterFlag};
_S_toao  S_toao_159_1 = {&var162,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var161,&bFirstEnterFlag};
_S_to3val  S_to3val_153_1 = {&var333,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R0UT02RDU,&fEM_R0UT02RDU,&iEM_TERA0MT01RIM,&var162,&var163,&var164,&bFirstEnterFlag};
_S_twobool  S_twobool_144_1 = {&var334,&iEM_TERA7MS31LIM,&var165,&vainSBool,&internal1_m144_Out10,&bFirstEnterFlag};
_S_orn  S_orn_897_1 = {array_m897_x_1,&iRM_2_,&var166};
_S_andn  S_andn_892_1 = {array_m892_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_896_1 = {&var166,&var167};
_S_noto  S_noto_496_1 = {&B3AD34LDU,&var168};
_S_lk  S_lk_500_1 = {&fEM_A3UP02RDU,&var168,&var169};
_S_noto  S_noto_494_1 = {&A3AD34LDU,&var170};
_S_lk  S_lk_499_1 = {&fEM_A3UP02RDU,&var170,&var171};
_S_ovb1  S_ovb1_192_1 = {&R8AD21LDU,&iRM_500_,&var172,&internal1_m192_tx};
_S_ovb1  S_ovb1_25_1 = {&R8AD21LDU,&iRM_500_,&var173,&internal1_m25_tx};
_S_andn  S_andn_917_1 = {array_m917_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_922_1 = {&var38,&var174};
_S_andn  S_andn_910_1 = {array_m910_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_913_1 = {&var39,&var175};
_S_andn  S_andn_902_1 = {array_m902_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_906_1 = {&var40,&var176};
_S_orn  S_orn_609_1 = {array_m609_x_1,&iRM_2_,&var177};
_S_orn  S_orn_606_1 = {array_m606_x_1,&iRM_2_,&var178};
_S_react  S_react_195_1 = {&var284,&var179};
_S_noto  S_noto_461_1 = {&lEM_R6AD10LC1,&var180};
_S_asmot  S_asmot_465_1 = {&var180,&lEM_R6AD10LC1,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R6UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R6UC01RSP,&vainSFloat,&var181,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m465_X00,&internal1_m465_V00,&internal1_m465_Pav0,&internal1_m465_Zav0,&internal1_m465_Pv0,&internal1_m465_Zv0,&internal1_m465_RA00,&internal1_m465_RA10,&internal1_m465_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_475_1 = {&var27,&var28,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R5UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R5UC01RSP,&vainSFloat,&var182,&var183,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m475_X00,&internal1_m475_V00,&internal1_m475_Pav0,&internal1_m475_Zav0,&internal1_m475_Pv0,&internal1_m475_Zv0,&internal1_m475_RA00,&internal1_m475_RA10,&internal1_m475_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_464_1 = {&var29,&var30,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R3UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R3UC01RSP,&vainSFloat,&var184,&var185,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m464_X00,&internal1_m464_V00,&internal1_m464_Pav0,&internal1_m464_Zav0,&internal1_m464_Pv0,&internal1_m464_Zv0,&internal1_m464_RA00,&internal1_m464_RA10,&internal1_m464_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_594_1 = {&A4AD10LDU,&var186};
_S_asmot  S_asmot_598_1 = {&var186,&A4AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,&fEM_A4UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_A4MC01RSP,&vainSFloat,&var187,&var188,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m598_X00,&internal1_m598_V00,&internal1_m598_Pav0,&internal1_m598_Zav0,&internal1_m598_Pv0,&internal1_m598_Zv0,&internal1_m598_RA00,&internal1_m598_RA10,&internal1_m598_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_592_1 = {&B4AD10LDU,&var189};
_S_asmot  S_asmot_597_1 = {&var189,&B4AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_A4UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_B4MC01RSP,&vainSFloat,&var190,&var191,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m597_X00,&internal1_m597_V00,&internal1_m597_Pav0,&internal1_m597_Zav0,&internal1_m597_Pv0,&internal1_m597_Zv0,&internal1_m597_RA00,&internal1_m597_RA10,&internal1_m597_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_583_1 = {&A9AD10LDU,&var192};
_S_asmot  S_asmot_585_1 = {&var192,&A9AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,&fEM_A9UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_A9MC01RSP,&vainSFloat,&var193,&var194,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m585_X00,&internal1_m585_V00,&internal1_m585_Pav0,&internal1_m585_Zav0,&internal1_m585_Pv0,&internal1_m585_Zv0,&internal1_m585_RA00,&internal1_m585_RA10,&internal1_m585_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_582_1 = {&B9AD10LDU,&var195};
_S_asmot  S_asmot_584_1 = {&var195,&B9AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_A9UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_B9MC01RSP,&vainSFloat,&var196,&var197,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m584_X00,&internal1_m584_V00,&internal1_m584_Pav0,&internal1_m584_Zav0,&internal1_m584_Pv0,&internal1_m584_Zv0,&internal1_m584_RA00,&internal1_m584_RA10,&internal1_m584_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orn  S_orn_615_1 = {array_m615_x_1,&iRM_3_,&var198};
_S_andn  S_andn_894_1 = {array_m894_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_899_1 = {&var41,&var199};
_S_andn  S_andn_284_1 = {array_m284_x_1,&iRM_2_,&var200};
_S_andn  S_andn_250_1 = {array_m250_x_1,&iRM_3_,&var201};
_S_noto  S_noto_249_1 = {&C2MD31LP1,&var202};
_S_andn  S_andn_251_1 = {array_m251_x_1,&iRM_3_,&var203};
_S_noto  S_noto_211_1 = {&C1MD31LP2,&var204};
_S_noto  S_noto_210_1 = {&C1MD31LP1,&var205};
_S_andn  S_andn_213_1 = {array_m213_x_1,&iRM_4_,&var206};
_S_andn  S_andn_212_1 = {array_m212_x_1,&iRM_4_,&var207};
_S_andn  S_andn_118_1 = {array_m118_x_1,&iRM_2_,&var208};
_S_noto  S_noto_46_1 = {&C1MD31LP2,&var209};
_S_noto  S_noto_45_1 = {&C1MD31LP1,&var210};
_S_andn  S_andn_48_1 = {array_m48_x_1,&iRM_4_,&var211};
_S_andn  S_andn_47_1 = {array_m47_x_1,&iRM_4_,&var212};
_S_andn  S_andn_85_1 = {array_m85_x_1,&iRM_3_,&var213};
_S_noto  S_noto_84_1 = {&C2MD31LP1,&var214};
_S_andn  S_andn_86_1 = {array_m86_x_1,&iRM_3_,&var215};
_S_noto  S_noto_614_1 = {&var198,&var216};
_S_orn  S_orn_622_1 = {array_m622_x_1,&iRM_2_,&var217};
_S_fsubo  S_fsubo_362_1 = {&fEM_R7UY00RSS,&var270,&var218};
_S_fsubo  S_fsubo_112_1 = {&fEM_A2UC05RIM,&var309,&var219};
_S_fsubo  S_fsubo_277_1 = {&fEM_A2UC05RIM,&var301,&var220};
_S_fsubo  S_fsubo_239_1 = {&fEM_A1UC05RIM,&var317,&var221};
_S_fsubo  S_fsubo_74_1 = {&fEM_A1UC05RIM,&var324,&var222};
_S_fsubo  S_fsubo_8_1 = {&var224,&fEM_R0UR01RIM,&var223};
_S_inf  S_inf_7_1 = {&var270,array_m7_a_1,array_m7_b_1,&iRM_5_,&var224,&vainSInt};
_S_inf  S_inf_9_1 = {&var270,array_m9_a_1,array_m9_b_1,&iRM_7_,&var225,&vainSInt};
_S_mod1  S_mod1_627_1 = {&var285,&fEM_R7UI02RIM,&fEM_R7UL01RIM,&var226,&internal1_m627_y0};
_S_bol  S_bol_621_1 = {&var285,&fEM_R7UI73RIM,&var227};
_S_bol  S_bol_611_1 = {&var285,&fEM_R7UI72RIM,&var228};
_S_bol  S_bol_605_1 = {&var285,&fEM_R7UI71RIM,&var229};
_S_vchs  S_vchs_791_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX12RSS,&fEM_R7UY12RSS,&bRM_5_,&fEM_A0UX12RSS,&fEM_B0UX12RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var230,&internal1_m791_Chim0};
_S_vchs  S_vchs_782_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX11RSS,&fEM_R7UY11RSS,&bRM_4_,&fEM_A0UX11RSS,&fEM_B0UX11RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var231,&internal1_m782_Chim0};
_S_vchs  S_vchs_774_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX10RSS,&fEM_R7UY10RSS,&bRM_1_,&fEM_A0UX10RSS,&fEM_B0UX10RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var232,&internal1_m774_Chim0};
_S_vchs  S_vchs_765_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX09RSS,&fEM_R7UY09RSS,&bRM_5_,&fEM_A0UX09RSS,&fEM_B0UX09RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var233,&internal1_m765_Chim0};
_S_vchs  S_vchs_756_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX08RSS,&fEM_R7UY08RSS,&bRM_4_,&fEM_A0UX08RSS,&fEM_B0UX08RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var234,&internal1_m756_Chim0};
_S_vchs  S_vchs_748_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX07RSS,&fEM_R7UY07RSS,&bRM_1_,&fEM_A0UX07RSS,&fEM_B0UX07RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var235,&internal1_m748_Chim0};
_S_vchs  S_vchs_739_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX06RSS,&fEM_R7UY06RSS,&bRM_5_,&fEM_A0UX06RSS,&fEM_B0UX06RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var236,&internal1_m739_Chim0};
_S_vchs  S_vchs_730_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX05RSS,&fEM_R7UY05RSS,&bRM_4_,&fEM_A0UX05RSS,&fEM_B0UX05RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var237,&internal1_m730_Chim0};
_S_vchs  S_vchs_722_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX04RSS,&fEM_R7UY04RSS,&bRM_2_,&fEM_A0UX04RSS,&fEM_B0UX04RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var238,&internal1_m722_Chim0};
_S_vchs  S_vchs_713_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UC10RIM,&fEM_R7UC19RIM,&bRM_5_,&fEM_A0UX03RSS,&fEM_B0UX03RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var239,&internal1_m713_Chim0};
_S_vchs  S_vchs_704_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX02RSS,&fEM_R7UY02RSS,&bRM_4_,&fEM_A0UX02RSS,&fEM_B0UX02RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var240,&internal1_m704_Chim0};
_S_fsumo  S_fsumo_888_1 = {&fEM_R4UC10RIM,&fEM_R4UC22RIM,&var241};
_S_vchs  S_vchs_694_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX01RSS,&fEM_R7UY01RSS,&bRM_2_,&fEM_A0UX01RSS,&fEM_B0UX01RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var242,&internal1_m694_Chim0};
_S_asmot  S_asmot_572_1 = {&B5AD10LDU,&B5AD20LDU,&fEM_B5MC01RC1,&fEM_B5MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERNL2,&fEM_A5UC10RIM,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,&fEM_B5MC01RSP,&vainSFloat,&var243,&var244,&vainSBool,&vainSBool,&vainSFloat,&var245,&var246,&internal1_m572_X00,&internal1_m572_V00,&internal1_m572_Pav0,&internal1_m572_Zav0,&internal1_m572_Pv0,&internal1_m572_Zv0,&internal1_m572_RA00,&internal1_m572_RA10,&internal1_m572_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_558_1 = {&A5AD10LDU,&A5AD20LDU,&fEM_A5MC01RC1,&fEM_A5MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERNL1,&fEM_A5UC10RIM,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,&fEM_A5MC01RSP,&vainSFloat,&var247,&var248,&vainSBool,&vainSBool,&vainSFloat,&var249,&var250,&internal1_m558_X00,&internal1_m558_V00,&internal1_m558_Pav0,&internal1_m558_Zav0,&internal1_m558_Pv0,&internal1_m558_Zv0,&internal1_m558_RA00,&internal1_m558_RA10,&internal1_m558_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_449_1 = {&R2AD10LDU,&R2AD20LDU,&fEM_R2MC01RC1,&fEM_R2MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERMDZ2,&fEM_R1UC10RIM,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,&fEM_R2MC01RSP,&vainSFloat,&var251,&var252,&vainSBool,&vainSBool,&vainSFloat,&var253,&var254,&internal1_m449_X00,&internal1_m449_V00,&internal1_m449_Pav0,&internal1_m449_Zav0,&internal1_m449_Pv0,&internal1_m449_Zv0,&internal1_m449_RA00,&internal1_m449_RA10,&internal1_m449_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_435_1 = {&R1AD10LDU,&R1AD20LDU,&fEM_R1MC01RC1,&fEM_R1MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERMDZ1,&fEM_R1UC10RIM,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,&fEM_R1MC01RSP,&vainSFloat,&var255,&var256,&vainSBool,&vainSBool,&vainSFloat,&var257,&var258,&internal1_m435_X00,&internal1_m435_V00,&internal1_m435_Pav0,&internal1_m435_Zav0,&internal1_m435_Pv0,&internal1_m435_Zv0,&internal1_m435_RA00,&internal1_m435_RA10,&internal1_m435_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_486_1 = {&B6AD10LDU,&B6AD20LDU,&fEM_B6MC01RC1,&fEM_B6MV01RC1,&fRM_1_0,&fEM_A6US80RDU,&iEM_TERBZ2,&fEM_A6UC10RIM,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,&fEM_B6MC01RSP,&vainSFloat,&var259,&var260,&vainSBool,&vainSBool,&vainSFloat,&var261,&var262,&internal1_m486_X00,&internal1_m486_V00,&internal1_m486_Pav0,&internal1_m486_Zav0,&internal1_m486_Pv0,&internal1_m486_Zv0,&internal1_m486_RA00,&internal1_m486_RA10,&internal1_m486_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_387_1 = {&A6AD10LDU,&A6AD20LDU,&fEM_A6MC01RC1,&fEM_A6MV01RC1,&fRM_1_0,&fEM_A6US80RDU,&iEM_TERBZ1,&fEM_A6UC10RIM,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,&fEM_A6MC01RSP,&vainSFloat,&var263,&var264,&vainSBool,&vainSBool,&vainSFloat,&var265,&var266,&internal1_m387_X00,&internal1_m387_V00,&internal1_m387_Pav0,&internal1_m387_Zav0,&internal1_m387_Pv0,&internal1_m387_Zv0,&internal1_m387_RA00,&internal1_m387_RA10,&internal1_m387_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_372_1 = {&A8AD20LDU,&A8AD10LDU,&fEM_A8MC01RC1,&fEM_A8MV01RC1,&fEM_A8UV80RDU,&fEM_A8US80RDU,&iEM_TERDS2,&fEM_A8UC10RIM,&fEM_A8UC20RIM,&fEM_A8UC11RIM,&fEM_A8UC21RIM,&fEM_A8UC08RDU,&fEM_A8MC01RSP,&var267,&var268,&var269,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m372_X00,&internal1_m372_V00,&internal1_m372_Pav0,&internal1_m372_Zav0,&internal1_m372_Pv0,&internal1_m372_Zv0,&internal1_m372_RA00,&internal1_m372_RA10,&internal1_m372_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_356_1 = {&B8AD20LDU,&B8AD10LDU,&fEM_B8MC01RC1,&fEM_B8MV01RC1,&fEM_B8UV80RDU,&fEM_B8US80RDU,&iEM_TERMAZ2,&fEM_B8UC10RIM,&fEM_B8UC20RIM,&fEM_B8UC11RIM,&fEM_B8UC21RIM,&fEM_B8UC08RDU,&fEM_B8MC01RSP,&var270,&var271,&var272,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m356_X00,&internal1_m356_V00,&internal1_m356_Pav0,&internal1_m356_Zav0,&internal1_m356_Pv0,&internal1_m356_Zv0,&internal1_m356_RA00,&internal1_m356_RA10,&internal1_m356_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_884_1 = {&R4AD10LDU,&R4AD20LDU,&fEM_R4MC01RC1,&fEM_R4MV01RC1,&fEM_R4UV80RDU,&fEM_R4US80RDU,&iEM_TERTLG,&fEM_R4UC10RIM,&fEM_R4UC20RIM,&fEM_R4UC10RIM,&fEM_R4UC20RIM,&fEM_R4UC08RDU,&fEM_R4MC01RSP,&vainSFloat,&var273,&var274,&var275,&var276,&vainSFloat,&var277,&var278,&internal1_m884_X00,&internal1_m884_V00,&internal1_m884_Pav0,&internal1_m884_Zav0,&internal1_m884_Pv0,&internal1_m884_Zv0,&internal1_m884_RA00,&internal1_m884_RA10,&internal1_m884_MyFirstEnterFlag,&bFirstEnterFlag};
_S_azbars  S_azbars_177_1 = {&var316,&var300,&var286,&var330,&fEM_R0UR30RIM,&B7AP31LDU,&var190,&lEM_R8AD10LC1,&var172,&fEM_R0UL01RIM,&fEM_R0UN02RIM,&fEM_R0UT01RIM,&fEM_R0UT02RIM,&fEM_R0UT04RIM,&fEM_R0UT05RIM,&fEM_R0UH05RSS,&fEM_A0UN02RIM,&fEM_A0UN01RIM,&fEM_A1UR00RIM,&fEM_A1UR01RIM,&fEM_A2UR00RIM,&fEM_A2UR01RIM,&fEM_A3UR00RIM,&fEM_A3UR01RIM,&var223,&var225,&fEM_R0UT03RIM,&fEM_R0UT06RIM,&fEM_A0UR02RSP,&fEM_A0UR01RSP,&fEM_B0UT03RSP,&var279,&var280,&var281,&var282,&var283,&var284,&var285,&internal1_m177_C1,&internal1_m177_C2,&internal1_m177_C3,&internal1_m177_C4,&internal1_m177_C5,&internal1_m177_C6,&internal1_m177_N20,array_m177_C0_1,&internal1_m177_ImpINI0,&internal1_m177_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_295_1 = {&B3AD11LDU,&B3AD21LDU,&B3AD02LDU,&B3AD01LDU,&B3AD03LDU,&B3AD04LDU,&B3AD05LDU,&var200,&B3AD33LDU,&lRM_1_,&fEM_B3MC01RC1,&fEM_B3MC02RC1,&fEM_B3MV01RC1,&fEM_B3MV02RC1,&lRM_0_,array_m295_Vr_1,&fEM_A3UC02RDU,&var169,&fEM_A3UP01RIM,&fEM_A3UG01RDU,&fEM_A3US07RDU,&fEM_A3UV02RIM,&iEM_TERIS2,&fEM_A3UC04RIM,&fEM_A3UC05RIM,&fEM_A3UC06RIM,&fEM_A3UC08RIM,&fEM_B3MC01RSP,&fEM_B3MC02RSP,&var286,&var287,&var288,&var289,&var290,&vainSFloat,&vainSFloat,&var291,&var292,&vainSBool,&vainSBool,&internal1_m295_X00,&internal1_m295_Sh00,&internal1_m295_RV00,&internal1_m295_ShV00,&internal1_m295_Ppv0,&internal1_m295_Pav0,&internal1_m295_Zav0,&internal1_m295_RA00,&internal1_m295_RA10,&internal1_m295_RA30,&internal1_m295_RA50,&internal1_m295_fls,&internal1_m295_flp,&internal1_m295_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_130_1 = {&A3AD11LDU,&A3AD21LDU,&A3AD02LDU,&A3AD01LDU,&A3AD03LDU,&A3AD04LDU,&A3AD05LDU,&var208,&A3AD33LDU,&lRM_1_,&fEM_A3MC01RC1,&fEM_A3MC02RC1,&fEM_A3MV01RC1,&fEM_A3MV02RC1,&lRM_0_,array_m130_Vr_1,&fEM_A3UC02RDU,&var171,&fEM_A3UP01RIM,&fEM_A3UG01RDU,&fEM_A3US07RDU,&fEM_A3UV02RIM,&iEM_TERIS1,&fEM_A3UC04RIM,&fEM_A3UC05RIM,&fEM_A3UC06RIM,&fEM_A3UC08RIM,&fEM_A3MC01RSP,&fEM_A3MC02RSP,&var293,&var294,&var295,&var296,&var297,&vainSFloat,&vainSFloat,&var298,&var299,&vainSBool,&vainSBool,&internal1_m130_X00,&internal1_m130_Sh00,&internal1_m130_RV00,&internal1_m130_ShV00,&internal1_m130_Ppv0,&internal1_m130_Pav0,&internal1_m130_Zav0,&internal1_m130_RA00,&internal1_m130_RA10,&internal1_m130_RA30,&internal1_m130_RA50,&internal1_m130_fls,&internal1_m130_flp,&internal1_m130_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_259_1 = {&B2AD11LDU,&B2AD21LDU,&B2AD02LDU,&B2AD01LDU,&B2AD03LDU,&B2AD04LDU,&B2AD05LDU,&var201,&B2AD33LDU,&var203,&fEM_B2MC01RC1,&fEM_B2MC02RC1,&fEM_B2MV01RC1,&fEM_B2MV02RC1,&lRM_1_,array_m259_Vr_1,&fEM_A2UC02RDU,&fEM_A2UP02RIM,&fEM_A2UP01RIM,&fEM_A2UG01RDU,&fEM_A2US07RDU,&fEM_A2UV02RIM,&iEM_TERRB2,&fEM_A2UC04RIM,&fEM_A2UC05RIM,&fEM_A2UC06RIM,&fEM_A2UC08RIM,&fEM_B2MC01RSP,&fEM_B2MC02RSP,&var300,&var301,&vainSBool,&var302,&var303,&vainSFloat,&vainSFloat,&var304,&var305,&var306,&var307,&internal1_m259_X00,&internal1_m259_Sh00,&internal1_m259_RV00,&internal1_m259_ShV00,&internal1_m259_Ppv0,&internal1_m259_Pav0,&internal1_m259_Zav0,&internal1_m259_RA00,&internal1_m259_RA10,&internal1_m259_RA30,&internal1_m259_RA50,&internal1_m259_fls,&internal1_m259_flp,&internal1_m259_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_94_1 = {&A2AD11LDU,&A2AD21LDU,&A2AD02LDU,&A2AD01LDU,&A2AD03LDU,&A2AD04LDU,&A2AD05LDU,&var213,&A2AD33LDU,&var215,&fEM_A2MC01RC1,&fEM_A2MC02RC1,&fEM_A2MV01RC1,&fEM_A2MV02RC1,&lRM_1_,array_m94_Vr_1,&fEM_A2UC02RDU,&fEM_A2UP02RIM,&fEM_A2UP01RIM,&fEM_A2UG01RDU,&fEM_A2US07RDU,&fEM_A2UV02RIM,&iEM_TERRB1,&fEM_A2UC04RIM,&fEM_A2UC05RIM,&fEM_A2UC06RIM,&fEM_A2UC08RIM,&fEM_A2MC01RSP,&fEM_A2MC02RSP,&var308,&var309,&vainSBool,&var310,&var311,&vainSFloat,&vainSFloat,&var312,&var313,&var314,&var315,&internal1_m94_X00,&internal1_m94_Sh00,&internal1_m94_RV00,&internal1_m94_ShV00,&internal1_m94_Ppv0,&internal1_m94_Pav0,&internal1_m94_Zav0,&internal1_m94_RA00,&internal1_m94_RA10,&internal1_m94_RA30,&internal1_m94_RA50,&internal1_m94_fls,&internal1_m94_flp,&internal1_m94_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_224_1 = {&B1AD11LDU,&B1AD21LDU,&B1AD02LDU,&B1AD01LDU,&B1AD03LDU,&B1AD04LDU,&B1AD05LDU,&var207,&lRM_1_,&var206,&fEM_B1MC01RC1,&fEM_B1MC02RC1,&fEM_B1MV01RC1,&fEM_B1MV02RC1,&lRM_1_,array_m224_Vr_1,&fEM_A1UC02RDU,&fRM_0_,&fEM_A1UP01RIM,&fEM_A1UG01RDU,&fEM_A1US07RDU,&fEM_A1UV02RIM,&iEM_TERBB2,&fEM_A1UC04RIM,&fEM_A1UC05RIM,&fEM_A1UC06RIM,&fEM_A1UC08RIM,&fEM_B1MC01RSP,&fEM_B1MC02RSP,&var316,&var317,&vainSBool,&var318,&var319,&vainSFloat,&vainSFloat,&var320,&vainSBool,&var321,&var322,&internal1_m224_X00,&internal1_m224_Sh00,&internal1_m224_RV00,&internal1_m224_ShV00,&internal1_m224_Ppv0,&internal1_m224_Pav0,&internal1_m224_Zav0,&internal1_m224_RA00,&internal1_m224_RA10,&internal1_m224_RA30,&internal1_m224_RA50,&internal1_m224_fls,&internal1_m224_flp,&internal1_m224_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_59_1 = {&A1AD11LDU,&A1AD21LDU,&A1AD02LDU,&A1AD01LDU,&A1AD03LDU,&A1AD04LDU,&A1AD05LDU,&var212,&lRM_1_,&var211,&fEM_A1MC01RC1,&fEM_A1MC02RC1,&fEM_A1MV01RC1,&fEM_A1MV02RC1,&lRM_1_,array_m59_Vr_1,&fEM_A1UC02RDU,&fRM_0_,&fEM_A1UP01RIM,&fEM_A1UG01RDU,&fEM_A1US07RDU,&fEM_A1UV02RIM,&iEM_TERBB1,&fEM_A1UC04RIM,&fEM_A1UC05RIM,&fEM_A1UC06RIM,&fEM_A1UC08RIM,&fEM_A1MC01RSP,&fEM_A1MC02RSP,&var323,&var324,&var325,&var326,&var327,&vainSFloat,&vainSFloat,&vainSBool,&vainSBool,&var328,&var329,&internal1_m59_X00,&internal1_m59_Sh00,&internal1_m59_RV00,&internal1_m59_ShV00,&internal1_m59_Ppv0,&internal1_m59_Pav0,&internal1_m59_Zav0,&internal1_m59_RA00,&internal1_m59_RA10,&internal1_m59_RA30,&internal1_m59_RA50,&internal1_m59_fls,&internal1_m59_flp,&internal1_m59_MyFirstEnterFlag,&bFirstEnterFlag};
_S_azbars  S_azbars_14_1 = {&var323,&var308,&var293,&var279,&fEM_R0UR30RIM,&A7AP31LDU,&var187,&lEM_R8AD10LC1,&var173,&fEM_R0UL01RIM,&fEM_R0UN02RIM,&fEM_R0UT01RIM,&fEM_R0UT02RIM,&fEM_R0UT04RIM,&fEM_R0UT05RIM,&fEM_R0UH05RSS,&fEM_A0UN02RIM,&fEM_A0UN01RIM,&fEM_A1UR00RIM,&fEM_A1UR01RIM,&fEM_A2UR00RIM,&fEM_A2UR01RIM,&fEM_A3UR00RIM,&fEM_A3UR01RIM,&var223,&var225,&fEM_R0UT03RIM,&fEM_R0UT06RIM,&fEM_A0UR02RSP,&fEM_A0UR01RSP,&fEM_A0UT03RSP,&var330,&var331,&var332,&var333,&var334,&var335,&vainSFloat,&internal1_m14_C1,&internal1_m14_C2,&internal1_m14_C3,&internal1_m14_C4,&internal1_m14_C5,&internal1_m14_C6,&internal1_m14_N20,array_m14_C0_1,&internal1_m14_ImpINI0,&internal1_m14_MyFirstEnterFlag,&bFirstEnterFlag};


void ZeroVar()
{
   var1.f=0.0;
   var2.f=0.0;
   var3.f=0.0;
   var4.f=0.0;
   var5.f=0.0;
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
   var51.l=0L;
   var52.f=0.0;
   var53.l=0L;
   var54.f=0.0;
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
   var89.i=0;
   var90.i=0;
   var91.f=0.0;
   var92.f=0.0;
   var93.l=0L;
   var94.f=0.0;
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
   var106.f=0.0;
   var107.b=0;
   var108.b=0;
   var109.l=0L;
   var110.f=0.0;
   var111.l=0L;
   var112.f=0.0;
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
   var124.i=0;
   var125.f=0.0;
   var126.b=0;
   var127.b=0;
   var128.i=0;
   var129.f=0.0;
   var130.b=0;
   var131.l=0L;
   var132.f=0.0;
   var133.b=0;
   var134.b=0;
   var135.l=0L;
   var136.f=0.0;
   var137.b=0;
   var138.i=0;
   var139.i=0;
   var140.b=0;
   var141.b=0;
   var142.b=0;
   var143.l=0L;
   var144.f=0.0;
   var145.b=0;
   var146.b=0;
   var147.b=0;
   var148.f=0.0;
   var149.f=0.0;
   var150.f=0.0;
   var151.i=0;
   var152.i=0;
   var153.i=0;
   var154.f=0.0;
   var155.f=0.0;
   var156.f=0.0;
   var157.i=0;
   var158.i=0;
   var159.b=0;
   var160.b=0;
   var161.i=0;
   var162.f=0.0;
   var163.f=0.0;
   var164.f=0.0;
   var165.b=0;
   var166.b=0;
   var167.b=0;
   var168.b=0;
   var169.f=0.0;
   var170.b=0;
   var171.f=0.0;
   var172.b=0;
   var173.b=0;
   var174.b=0;
   var175.b=0;
   var176.b=0;
   var177.b=0;
   var178.b=0;
   var179.f=0.0;
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
   var218.f=0.0;
   var219.f=0.0;
   var220.f=0.0;
   var221.f=0.0;
   var222.f=0.0;
   var223.f=0.0;
   var224.f=0.0;
   var225.f=0.0;
   var226.f=0.0;
   var227.b=0;
   var228.b=0;
   var229.b=0;
   var230.f=0.0;
   var231.f=0.0;
   var232.f=0.0;
   var233.f=0.0;
   var234.f=0.0;
   var235.f=0.0;
   var236.f=0.0;
   var237.f=0.0;
   var238.f=0.0;
   var239.f=0.0;
   var240.f=0.0;
   var241.f=0.0;
   var242.f=0.0;
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
   var267.f=0.0;
   var268.b=0;
   var269.b=0;
   var270.f=0.0;
   var271.b=0;
   var272.b=0;
   var273.b=0;
   var274.b=0;
   var275.b=0;
   var276.b=0;
   var277.b=0;
   var278.b=0;
   var279.f=0.0;
   var280.f=0.0;
   var281.f=0.0;
   var282.f=0.0;
   var283.b=0;
   var284.f=0.0;
   var285.f=0.0;
   var286.f=0.0;
   var287.f=0.0;
   var288.b=0;
   var289.b=0;
   var290.b=0;
   var291.b=0;
   var292.b=0;
   var293.f=0.0;
   var294.f=0.0;
   var295.b=0;
   var296.b=0;
   var297.b=0;
   var298.b=0;
   var299.b=0;
   var300.f=0.0;
   var301.f=0.0;
   var302.b=0;
   var303.b=0;
   var304.b=0;
   var305.b=0;
   var306.b=0;
   var307.b=0;
   var308.f=0.0;
   var309.f=0.0;
   var310.b=0;
   var311.b=0;
   var312.b=0;
   var313.b=0;
   var314.b=0;
   var315.b=0;
   var316.f=0.0;
   var317.f=0.0;
   var318.b=0;
   var319.b=0;
   var320.b=0;
   var321.b=0;
   var322.b=0;
   var323.f=0.0;
   var324.f=0.0;
   var325.b=0;
   var326.b=0;
   var327.b=0;
   var328.b=0;
   var329.b=0;
   var330.f=0.0;
   var331.f=0.0;
   var332.f=0.0;
   var333.f=0.0;
   var334.b=0;
   var335.f=0.0;
   vainSLong.l=0L;
   vainSFloat.f=0.0;
   vainSInt.i=0;
   vainSBool.b=0;
   vainSChar.c=0;

}
int freebuff = 0;
void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  noto(&S_noto_84_1);
  noto(&S_noto_249_1);
  noto(&S_noto_582_1);
  noto(&S_noto_583_1);
  ovb1(&S_ovb1_25_1);
  ovb1(&S_ovb1_192_1);
  noto(&S_noto_496_1);
  bol(&S_bol_920_1);
  bol(&S_bol_930_1);
  bol(&S_bol_908_1);
  bol(&S_bol_929_1);
  bol(&S_bol_932_1);
  zpfs(&S_zpfs_607_1);
  zpfs(&S_zpfs_619_1);
  noto(&S_noto_466_1);
  noto(&S_noto_463_1);
  noto(&S_noto_474_1);
  noto(&S_noto_473_1);
  to3val(&S_to3val_946_1);
  asmot(&S_asmot_884_1);
  asmot(&S_asmot_356_1);
  asmot(&S_asmot_372_1);
  asmot(&S_asmot_387_1);
  asmot(&S_asmot_486_1);
  asmot(&S_asmot_435_1);
  asmot(&S_asmot_449_1);
  asmot(&S_asmot_558_1);
  asmot(&S_asmot_572_1);
  fsumo(&S_fsumo_888_1);
  inf(&S_inf_9_1);
  inf(&S_inf_7_1);
  fsubo(&S_fsubo_8_1);
  fsubo(&S_fsubo_362_1);
  noto(&S_noto_45_1);
  noto(&S_noto_46_1);
  noto(&S_noto_210_1);
  noto(&S_noto_211_1);
  orn(&S_orn_615_1);
  asmot(&S_asmot_584_1);
  asmot(&S_asmot_585_1);
  noto(&S_noto_592_1);
  noto(&S_noto_594_1);
  noto(&S_noto_461_1);
  noto(&S_noto_494_1);
  lk(&S_lk_500_1);
  orn(&S_orn_897_1);
  to3val(&S_to3val_523_1);
  toao(&S_toao_528_1);
  toao(&S_toao_529_1);
  to3val(&S_to3val_501_1);
  toao(&S_toao_509_1);
  twobool(&S_twobool_544_1);
  twobool(&S_twobool_641_1);
  twobool(&S_twobool_661_1);
  twobool(&S_twobool_642_1);
  twobool(&S_twobool_662_1);
  twobool(&S_twobool_678_1);
  to3val(&S_to3val_820_1);
  ktoenc(&S_ktoenc_828_1);
  to3val(&S_to3val_818_1);
  ktoenc(&S_ktoenc_826_1);
  twobool(&S_twobool_542_1);
  twobool(&S_twobool_543_1);
  twobool(&S_twobool_680_1);
  twobool(&S_twobool_679_1);
  twobool(&S_twobool_682_1);
  twobool(&S_twobool_681_1);
  twobool(&S_twobool_1028_1);
  twobool(&S_twobool_844_1);
  twobool(&S_twobool_846_1);
  twobool(&S_twobool_845_1);
  to3val(&S_to3val_524_1);
  toao(&S_toao_530_1);
  toao(&S_toao_531_1);
  twobool(&S_twobool_527_1);
  twobool(&S_twobool_972_1);
  twobool(&S_twobool_987_1);
  twobool(&S_twobool_1004_1);
  twobool(&S_twobool_1026_1);
  twobool(&S_twobool_807_1);
  twobool(&S_twobool_973_1);
  twobool(&S_twobool_974_1);
  twobool(&S_twobool_975_1);
  twobool(&S_twobool_976_1);
  twobool(&S_twobool_1024_1);
  twobool(&S_twobool_803_1);
  twobool(&S_twobool_804_1);
  twobool(&S_twobool_806_1);
  twobool(&S_twobool_805_1);
  twobool(&S_twobool_831_1);
  twobool(&S_twobool_829_1);
  twobool(&S_twobool_832_1);
  twobool(&S_twobool_830_1);
  twobool(&S_twobool_1008_1);
  twobool(&S_twobool_1009_1);
  twobool(&S_twobool_1010_1);
  twobool(&S_twobool_1029_1);
  twobool(&S_twobool_56_1);
  twobool(&S_twobool_41_1);
  twobool(&S_twobool_221_1);
  twobool(&S_twobool_203_1);
  zpfs(&S_zpfs_593_1);
  zpfs(&S_zpfs_595_1);
  or2(&S_or2_898_1);
  or2(&S_or2_905_1);
  or2(&S_or2_912_1);
  or2(&S_or2_921_1);
  ampl(&S_ampl_363_1);
  rs(&S_rs_460_1);
  rs(&S_rs_459_1);
  rs(&S_rs_472_1);
  rs(&S_rs_471_1);
  twobool(&S_twobool_526_1);
  twobool(&S_twobool_510_1);
  twobool(&S_twobool_643_1);
  twobool(&S_twobool_644_1);
  twobool(&S_twobool_665_1);
  twobool(&S_twobool_666_1);
  twobool(&S_twobool_645_1);
  twobool(&S_twobool_646_1);
  twobool(&S_twobool_667_1);
  twobool(&S_twobool_668_1);
  twobool(&S_twobool_988_1);
  twobool(&S_twobool_989_1);
  twobool(&S_twobool_990_1);
  twobool(&S_twobool_991_1);
  twobool(&S_twobool_808_1);
  twobool(&S_twobool_809_1);
  noto(&S_noto_614_1);
  andn(&S_andn_86_1);
  andn(&S_andn_85_1);
  andn(&S_andn_47_1);
  andn(&S_andn_48_1);
  andn(&S_andn_118_1);
  andn(&S_andn_212_1);
  andn(&S_andn_213_1);
  andn(&S_andn_251_1);
  andn(&S_andn_250_1);
  andn(&S_andn_284_1);
  noto(&S_noto_899_1);
  andn(&S_andn_894_1);
  asmot(&S_asmot_597_1);
  asmot(&S_asmot_598_1);
  asmot(&S_asmot_464_1);
  asmot(&S_asmot_475_1);
  asmot(&S_asmot_465_1);
  noto(&S_noto_906_1);
  andn(&S_andn_902_1);
  noto(&S_noto_913_1);
  andn(&S_andn_910_1);
  noto(&S_noto_922_1);
  andn(&S_andn_917_1);
  lk(&S_lk_499_1);
  noto(&S_noto_896_1);
  andn(&S_andn_892_1);
  twobool(&S_twobool_1027_1);
  to3val(&S_to3val_498_1);
  toao(&S_toao_505_1);
  twobool(&S_twobool_1005_1);
  twobool(&S_twobool_1007_1);
  twobool(&S_twobool_1006_1);
  twobool(&S_twobool_1025_1);
  orrsim(&S_orrsim_59_1);
  orrsim(&S_orrsim_224_1);
  orrsim(&S_orrsim_94_1);
  orrsim(&S_orrsim_259_1);
  orrsim(&S_orrsim_130_1);
  orrsim(&S_orrsim_295_1);
  azbars(&S_azbars_177_1);
  bol(&S_bol_605_1);
  bol(&S_bol_611_1);
  bol(&S_bol_621_1);
  mod1(&S_mod1_627_1);
  fsubo(&S_fsubo_74_1);
  fsubo(&S_fsubo_239_1);
  fsubo(&S_fsubo_277_1);
  fsubo(&S_fsubo_112_1);
  orn(&S_orn_622_1);
  react(&S_react_195_1);
  orn(&S_orn_606_1);
  orn(&S_orn_609_1);
  twobool(&S_twobool_145_1);
  to3val(&S_to3val_151_1);
  toao(&S_toao_156_1);
  toao(&S_toao_157_1);
  toao(&S_toao_158_1);
  twobool(&S_twobool_417_1);
  twobool(&S_twobool_418_1);
  twobool(&S_twobool_419_1);
  to3val(&S_to3val_416_1);
  ktoenc(&S_ktoenc_421_1);
  twobool(&S_twobool_420_1);
  twobool(&S_twobool_327_1);
  twobool(&S_twobool_311_1);
  twobool(&S_twobool_340_1);
  to3val(&S_to3val_315_1);
  ktoenc(&S_ktoenc_319_1);
  twobool(&S_twobool_339_1);
  twobool(&S_twobool_341_1);
  to3val(&S_to3val_325_1);
  ktoenc(&S_ktoenc_326_1);
  twobool(&S_twobool_342_1);
  twobool(&S_twobool_312_1);
  twobool(&S_twobool_313_1);
  twobool(&S_twobool_328_1);
  twobool(&S_twobool_329_1);
  ampl(&S_ampl_632_1);
  twobool(&S_twobool_400_1);
  twobool(&S_twobool_401_1);
  twobool(&S_twobool_399_1);
  to3val(&S_to3val_402_1);
  ktoenc(&S_ktoenc_408_1);
  twobool(&S_twobool_941_1);
  twobool(&S_twobool_942_1);
  twobool(&S_twobool_945_1);
  to3val(&S_to3val_937_1);
  ktoenc(&S_ktoenc_944_1);
  to3val(&S_to3val_956_1);
  ktoenc(&S_ktoenc_961_1);
  twobool(&S_twobool_958_1);
  twobool(&S_twobool_959_1);
  twobool(&S_twobool_962_1);
  andn(&S_andn_347_1);
  twobool(&S_twobool_398_1);
  azbars(&S_azbars_14_1);
  vchs(&S_vchs_694_1);
  vchs(&S_vchs_704_1);
  vchs(&S_vchs_713_1);
  vchs(&S_vchs_722_1);
  vchs(&S_vchs_730_1);
  vchs(&S_vchs_739_1);
  vchs(&S_vchs_748_1);
  vchs(&S_vchs_756_1);
  vchs(&S_vchs_765_1);
  vchs(&S_vchs_774_1);
  vchs(&S_vchs_782_1);
  vchs(&S_vchs_791_1);
  twobool(&S_twobool_144_1);
  to3val(&S_to3val_153_1);
  toao(&S_toao_159_1);
  toao(&S_toao_160_1);
  toao(&S_toao_161_1);
  to3val(&S_to3val_633_1);
  vchs(&S_vchs_854_1);
  vchs(&S_vchs_862_1);
  vchs(&S_vchs_872_1);
  setData(idkrb2,&var300);
  setData(idkrb1,&var308);
  setData(idR0IS01FI0,&iRM_1_);
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
    array_m177_C0_1[i] = &(&internal1_m177_C0)[i*5];
  for( i=0;i<6;i++ )
    array_m14_C0_1[i] = &(&internal1_m14_C0)[i*5];
}

void MainCycle(void)
{
if ((getAsShort(idR0DEUMLSS) == 2) || (getAsShort(idR0DEUMLSS) == 3)) { 
     freebuff = 0;
       Scheme(); 
 }
 else {
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
                 if (initAllDriversPTI(drivers))
                 return EXIT_FAILURE;
           }
           }
       }


}
#endif
