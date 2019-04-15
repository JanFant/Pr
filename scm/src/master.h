#ifndef SCM_H
#define SCM_H
// Подсистема scm:SCM
static char SimulOn=0;
static short CodeSub=1;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 3293
static char BUFFER[3293];

#define A1IS11LDU	 BUFFER[0]	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
#define idA1IS11LDU	 1	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
#define A1IS21LDU	 BUFFER[2]	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
#define idA1IS21LDU	 2	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
#define B6IS21LDU	 BUFFER[4]	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
#define idB6IS21LDU	 3	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
#define B6IS11LDU	 BUFFER[6]	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
#define idB6IS11LDU	 4	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
#define A6IS21LDU	 BUFFER[8]	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
#define idA6IS21LDU	 5	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
#define A6IS11LDU	 BUFFER[10]	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
#define idA6IS11LDU	 6	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
#define A8IS12LDU	 BUFFER[12]	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
#define idA8IS12LDU	 7	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
#define A8IS22LDU	 BUFFER[14]	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
#define idA8IS22LDU	 8	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
#define B8IS12LDU	 BUFFER[16]	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
#define idB8IS12LDU	 9	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
#define B8IS22LDU	 BUFFER[18]	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
#define idB8IS22LDU	 10	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
#define R4IS12LDU	 BUFFER[20]	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
#define idR4IS12LDU	 11	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
#define R4IS22LDU	 BUFFER[22]	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
#define idR4IS22LDU	 12	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
#define R4IS21LDU	 BUFFER[24]	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
#define idR4IS21LDU	 13	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
#define R4IS11LDU	 BUFFER[26]	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
#define idR4IS11LDU	 14	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
#define B4VP82LDU	 BUFFER[28]	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 15	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define A4VP82LDU	 BUFFER[30]	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 16	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define R2IS21LDU	 BUFFER[32]	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
#define idR2IS21LDU	 17	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
#define R0EE04LZ1	 BUFFER[34]	//( - , SBz1) Питание  АКНП4  отключить
#define idR0EE04LZ1	 18	//( - , SBz1) Питание  АКНП4  отключить
#define R0EE03LZ1	 BUFFER[36]	//( - , SBz1) Питание  АКНП3  отключить
#define idR0EE03LZ1	 19	//( - , SBz1) Питание  АКНП3  отключить
#define R0EE02LZ1	 BUFFER[38]	//( - , SBz1) Питание  АКНП  отключить
#define idR0EE02LZ1	 20	//( - , SBz1) Питание  АКНП  отключить
#define R0EE01LZ2	 BUFFER[40]	//( - , SBz2) Питание  АКНП1  отключить
#define idR0EE01LZ2	 21	//( - , SBz2) Питание  АКНП1  отключить
#define R0EE01LZ1	 BUFFER[42]	//( - , SBz1) Питание  АКНП1  отключить
#define idR0EE01LZ1	 22	//( - , SBz1) Питание  АКНП1  отключить
#define B4IS10LDU	 BUFFER[44]	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
#define idB4IS10LDU	 23	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
#define A4IS10LDU	 BUFFER[46]	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
#define idA4IS10LDU	 24	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
#define B1IE04LDU	 BUFFER[48]	//( - , SCM) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 25	//( - , SCM) Движение ББ2 назад (от БУШД)
#define B1IE03LDU	 BUFFER[50]	//( - , SCM) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 26	//( - , SCM) Движение ББ2 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[52]	//( - , SCM) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 27	//( - , SCM) Движение ББ1 назад (от БУШД)
#define A1IE03LDU	 BUFFER[54]	//( - , SCM) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 28	//( - , SCM) Движение ББ1 вперед (от БУШД)
#define B1IS12LDU	 BUFFER[56]	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
#define idB1IS12LDU	 29	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
#define B1IS11LDU	 BUFFER[58]	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
#define idB1IS11LDU	 30	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
#define B1IS21LDU	 BUFFER[60]	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
#define idB1IS21LDU	 31	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
#define B1IC01UDU	 BUFFER[62]	//( - , SDu) Координата штока ББ2
#define idB1IC01UDU	 32	//( - , SDu) Координата штока ББ2
#define A1IC01UDU	 BUFFER[67]	//( - , SDu) Координата штока ББ1
#define idA1IC01UDU	 33	//( - , SDu) Координата штока ББ1
#define A1IS12LDU	 BUFFER[72]	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
#define idA1IS12LDU	 34	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
#define B2IS21LDU	 BUFFER[74]	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
#define idB2IS21LDU	 35	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
#define B9IS21LDU	 BUFFER[76]	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
#define idB9IS21LDU	 36	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
#define B9IS11LDU	 BUFFER[78]	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 37	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
#define A9IS21LDU	 BUFFER[80]	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
#define idA9IS21LDU	 38	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
#define A9IS11LDU	 BUFFER[82]	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 39	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
#define B5IS21LDU	 BUFFER[84]	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
#define idB5IS21LDU	 40	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
#define B5IS11LDU	 BUFFER[86]	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
#define idB5IS11LDU	 41	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
#define A5IS21LDU	 BUFFER[88]	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
#define idA5IS21LDU	 42	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
#define A5IS11LDU	 BUFFER[90]	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
#define idA5IS11LDU	 43	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
#define B0VP81LZZ	 BUFFER[92]	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	 44	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
#define A0VP81LZZ	 BUFFER[94]	//(do32_pti:100 - K27DO, - ) Давление АЗ1 в норме
#define idA0VP81LZZ	 45	//(do32_pti:100 - K27DO, - ) Давление АЗ1 в норме
#define B8IC01UDU	 BUFFER[96]	//( - , SDu) Координата АЗ2
#define idB8IC01UDU	 46	//( - , SDu) Координата АЗ2
#define A8IC01UDU	 BUFFER[101]	//( - , SDu) Координата ДС2
#define idA8IC01UDU	 47	//( - , SDu) Координата ДС2
#define R6IS68LZZ	 BUFFER[106]	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 48	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define R6IS67LZZ	 BUFFER[108]	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 49	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS66LZZ	 BUFFER[110]	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 50	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS65LDU	 BUFFER[112]	//( - , - ) Исправность ВИП ССДИ-35 2канал
#define idR6IS65LDU	 51	//( - , - ) Исправность ВИП ССДИ-35 2канал
#define R2IS11LDU	 BUFFER[114]	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
#define idR2IS11LDU	 52	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
#define R1IS21LDU	 BUFFER[116]	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
#define idR1IS21LDU	 53	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
#define R1IS11LDU	 BUFFER[118]	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
#define idR1IS11LDU	 54	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
#define B4IS21LDU	 BUFFER[120]	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
#define idB4IS21LDU	 55	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
#define B4IS11LDU	 BUFFER[122]	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
#define idB4IS11LDU	 56	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
#define R8IS11LDU	 BUFFER[124]	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
#define idR8IS11LDU	 57	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
#define A4IS21LDU	 BUFFER[126]	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
#define idA4IS21LDU	 58	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
#define A4IS11LDU	 BUFFER[128]	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
#define idA4IS11LDU	 59	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
#define R5IS21LDU	 BUFFER[130]	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 60	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
#define R5IS11LDU	 BUFFER[132]	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 61	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
#define R3IS21LDU	 BUFFER[134]	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
#define idR3IS21LDU	 62	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
#define R3IS11LDU	 BUFFER[136]	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	 63	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
#define B2VP82LDU	 BUFFER[138]	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 64	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define B2IP01IZ2	 BUFFER[140]	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ2	 65	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
#define B2IP01IZ1	 BUFFER[143]	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	 66	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
#define B2IC01UDU	 BUFFER[146]	//( - , SDu) Координата штока РБ2
#define idB2IC01UDU	 67	//( - , SDu) Координата штока РБ2
#define B2IS12LDU	 BUFFER[151]	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	 68	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
#define B2IS11LDU	 BUFFER[153]	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
#define idB2IS11LDU	 69	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
#define R0IN02FI3	 BUFFER[155]	//( - , SA3) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI3	 70	//( - , SA3) Выход КНК15-1 Гц от ПТИ
#define R0IN03FI2	 BUFFER[160]	//( - , SA2) Выход КНК53М Гц от ПТИ
#define idR0IN03FI2	 71	//( - , SA2) Выход КНК53М Гц от ПТИ
#define R0IN07RIP	 BUFFER[165]	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
#define idR0IN07RIP	 72	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
#define R0IN06RIP	 BUFFER[170]	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
#define idR0IN06RIP	 73	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
#define TerR0IN06FRP	 BUFFER[175]	//( - , - ) Неисправности СНМ-11 -1,2
#define idTerR0IN06FRP	 74	//( - , - ) Неисправности СНМ-11 -1,2
#define R0IN03RIP	 BUFFER[178]	//( - , SRP) Выход КНК53М Гц от ПТИ
#define idR0IN03RIP	 75	//( - , SRP) Выход КНК53М Гц от ПТИ
#define R0IN02RIP	 BUFFER[183]	//( - , SRP) Выход КНК15- Гц от ПТИ
#define idR0IN02RIP	 76	//( - , SRP) Выход КНК15- Гц от ПТИ
#define R0IN01RIP	 BUFFER[188]	//( - , SRP) Выход СНМ-11 Гц от ПТИ
#define idR0IN01RIP	 77	//( - , SRP) Выход СНМ-11 Гц от ПТИ
#define R0IN02FI2	 BUFFER[193]	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI2	 78	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define R0IN03FI1	 BUFFER[198]	//( - , SA1) Выход КНК53М Гц от ПТИ
#define idR0IN03FI1	 79	//( - , SA1) Выход КНК53М Гц от ПТИ
#define R0IN02FI1	 BUFFER[203]	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI1	 80	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define R0IN03FI4	 BUFFER[208]	//( - , SA4) Выход КНК53М Гц от ПТИ
#define idR0IN03FI4	 81	//( - , SA4) Выход КНК53М Гц от ПТИ
#define R0IN02FI4	 BUFFER[213]	//( - , SA4) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI4	 82	//( - , SA4) Выход КНК15-1 Гц от ПТИ
#define R0IN01FI3	 BUFFER[218]	//( - , SA3) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI3	 83	//( - , SA3) Выход СНМ-11 Гц от ПТИ
#define R0IN01FI2	 BUFFER[223]	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define idR0IN01FI2	 84	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define R0IN01FI4	 BUFFER[228]	//( - , SA4) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI4	 85	//( - , SA4) Выход СНМ-11 Гц от ПТИ
#define R0IN01FI1	 BUFFER[233]	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define idR0IN01FI1	 86	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define B0SN07RIM	 BUFFER[238]	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define idB0SN07RIM	 87	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define B0SN06RIM	 BUFFER[243]	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define idB0SN06RIM	 88	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define B0SN05RIM	 BUFFER[248]	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define idB0SN05RIM	 89	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define B0SN04RIM	 BUFFER[253]	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define idB0SN04RIM	 90	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define B0SN03RIM	 BUFFER[258]	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define idB0SN03RIM	 91	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define B0SN02RIM	 BUFFER[263]	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define idB0SN02RIM	 92	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define A0SN07RIM	 BUFFER[268]	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define idA0SN07RIM	 93	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define A0SN06RIM	 BUFFER[273]	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define idA0SN06RIM	 94	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define A0SN05RIM	 BUFFER[278]	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define idA0SN05RIM	 95	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define A0SN04RIM	 BUFFER[283]	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define idA0SN04RIM	 96	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define A0SN03RIM	 BUFFER[288]	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define idA0SN03RIM	 97	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define A0SN02RIM	 BUFFER[293]	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define idA0SN02RIM	 98	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define R0DEUMLSS	 BUFFER[298]	//( - , SCM) Сигнал управления моделью
#define idR0DEUMLSS	 99	//( - , SCM) Сигнал управления моделью
#define R0MW11IP1	 BUFFER[301]	//( - , SCM) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 100	//( - , SCM) Переключатель ВЫСТРЕЛ
#define R0IS01FI0	 BUFFER[304]	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
#define idR0IS01FI0	 101	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
#define A0IT03IRP	 BUFFER[307]	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
#define idA0IT03IRP	 102	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
#define B0IT03IRP	 BUFFER[310]	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
#define idB0IT03IRP	 103	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
#define R0IN03FI3	 BUFFER[313]	//( - , SA3) Выход КНК53М Гц от ПТИ
#define idR0IN03FI3	 104	//( - , SA3) Выход КНК53М Гц от ПТИ
#define A1VP81LZZ	 BUFFER[318]	//(do32_pti:100 - K28DO, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	 105	//(do32_pti:100 - K28DO, - ) Давление СБРОС ББ1 в норме
#define B1VP81LZZ	 BUFFER[320]	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	 106	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
#define B2IS33LDU	 BUFFER[322]	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
#define idB2IS33LDU	 107	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
#define A0VN01RIM	 BUFFER[324]	//( - , SCM) Период разгона  AЗ1
#define idA0VN01RIM	 108	//( - , SCM) Период разгона  AЗ1
#define B2IS32LIM	 BUFFER[329]	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
#define idB2IS32LIM	 109	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
#define B2IS11LIM	 BUFFER[331]	//( - , SCM) Магнит РБ2 обесточен
#define idB2IS11LIM	 110	//( - , SCM) Магнит РБ2 обесточен
#define A2IS32LIM	 BUFFER[333]	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
#define idA2IS32LIM	 111	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
#define A2IS11LIM	 BUFFER[335]	//( - , SCM) Магнит РБ1 обесточен
#define idA2IS11LIM	 112	//( - , SCM) Магнит РБ1 обесточен
#define B1IS32LIM	 BUFFER[337]	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
#define idB1IS32LIM	 113	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
#define B1IS11LIM	 BUFFER[339]	//( - , SCM) Магнит ББ2 обесточен
#define idB1IS11LIM	 114	//( - , SCM) Магнит ББ2 обесточен
#define A1IS32LIM	 BUFFER[341]	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
#define idA1IS32LIM	 115	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
#define A1IS11LIM	 BUFFER[343]	//( - , SCM) Магнит ББ1 обесточен
#define idA1IS11LIM	 116	//( - , SCM) Магнит ББ1 обесточен
#define A3AD34LDU	 BUFFER[345]	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
#define idA3AD34LDU	 117	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
#define R0IS02LDU	 BUFFER[347]	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
#define idR0IS02LDU	 118	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
#define R0EE04LZ2	 BUFFER[349]	//( - , SBz2) Питание  АКНП4  отключить
#define idR0EE04LZ2	 119	//( - , SBz2) Питание  АКНП4  отключить
#define R0EE03LZ2	 BUFFER[351]	//( - , SBz2) Питание  АКНП3  отключить
#define idR0EE03LZ2	 120	//( - , SBz2) Питание  АКНП3  отключить
#define R0EE02LZ2	 BUFFER[353]	//( - , SBz2) Питание  АКНП  отключить
#define idR0EE02LZ2	 121	//( - , SBz2) Питание  АКНП  отключить
#define B7AP31LDU	 BUFFER[355]	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
#define idB7AP31LDU	 122	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
#define A7AP31LDU	 BUFFER[357]	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
#define idA7AP31LDU	 123	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
#define R4VS12LDU	 BUFFER[359]	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
#define idR4VS12LDU	 124	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
#define R4VS22LDU	 BUFFER[361]	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
#define idR4VS22LDU	 125	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
#define R1VS12LDU	 BUFFER[363]	//( - , SCM) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 126	//( - , SCM) Движение МДЗ1 в сторону ВУ
#define R2VS12LDU	 BUFFER[365]	//( - , SCM) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 127	//( - , SCM) Движение МДЗ2 в сторону ВУ
#define R2VS22LDU	 BUFFER[367]	//( - , SCM) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 128	//( - , SCM) Движение МДЗ2 в сторону НУ
#define R1VS22LDU	 BUFFER[369]	//( - , SCM) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 129	//( - , SCM) Движение МДЗ1 в сторону НУ
#define B5VS12LDU	 BUFFER[371]	//( - , SCM) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 130	//( - , SCM) Движение НЛ2 в сторону ВУ
#define B5VS22LDU	 BUFFER[373]	//( - , SCM) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 131	//( - , SCM) Движение НЛ2 в сторону НУ
#define A5VS12LDU	 BUFFER[375]	//( - , SCM) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 132	//( - , SCM) Движение НЛ1 в сторону ВУ
#define A5VS22LDU	 BUFFER[377]	//( - , SCM) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 133	//( - , SCM) Движение НЛ1 в сторону НУ
#define B6VS12LDU	 BUFFER[379]	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
#define idB6VS12LDU	 134	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
#define B6VS22LDU	 BUFFER[381]	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
#define idB6VS22LDU	 135	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
#define A6VS12LDU	 BUFFER[383]	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	 136	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
#define A6VS22LDU	 BUFFER[385]	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	 137	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
#define B8IS21LDU	 BUFFER[387]	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
#define idB8IS21LDU	 138	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
#define B8IS11LDU	 BUFFER[389]	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
#define idB8IS11LDU	 139	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
#define B8AD20LDU	 BUFFER[391]	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
#define idB8AD20LDU	 140	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
#define B8AD10LDU	 BUFFER[393]	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
#define idB8AD10LDU	 141	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
#define R4AD20LDU	 BUFFER[395]	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
#define idR4AD20LDU	 142	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
#define R4AD10LDU	 BUFFER[397]	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	 143	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
#define B0SR01RIM	 BUFFER[399]	//( - , SCM) Текущая реактивность AЗ2
#define idB0SR01RIM	 144	//( - , SCM) Текущая реактивность AЗ2
#define B3AD33LDU	 BUFFER[404]	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define idB3AD33LDU	 145	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define B3AD05LDU	 BUFFER[406]	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
#define idB3AD05LDU	 146	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
#define B3AD04LDU	 BUFFER[408]	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
#define idB3AD04LDU	 147	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[410]	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
#define idB3AD03LDU	 148	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
#define B3AD02LDU	 BUFFER[412]	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
#define idB3AD02LDU	 149	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
#define B3AD01LDU	 BUFFER[414]	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
#define idB3AD01LDU	 150	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
#define B3AD21LDU	 BUFFER[416]	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 151	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
#define B3AD11LDU	 BUFFER[418]	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 152	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
#define A3AD33LDU	 BUFFER[420]	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define idA3AD33LDU	 153	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define A3AD05LDU	 BUFFER[422]	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
#define idA3AD05LDU	 154	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
#define A3AD04LDU	 BUFFER[424]	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
#define idA3AD04LDU	 155	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
#define A3AD03LDU	 BUFFER[426]	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
#define idA3AD03LDU	 156	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
#define R0CR01RIM	 BUFFER[428]	//( - , SCM) Коэффициент 12 связи АЗ1,2
#define idR0CR01RIM	 157	//( - , SCM) Коэффициент 12 связи АЗ1,2
#define B0SN08RIM	 BUFFER[433]	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
#define idB0SN08RIM	 158	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
#define A0SN08RIM	 BUFFER[438]	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
#define idA0SN08RIM	 159	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
#define B5AD20LDU	 BUFFER[443]	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
#define idB5AD20LDU	 160	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
#define B5AD10LDU	 BUFFER[445]	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
#define idB5AD10LDU	 161	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
#define A5AD20LDU	 BUFFER[447]	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
#define idA5AD20LDU	 162	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
#define A5AD10LDU	 BUFFER[449]	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
#define idA5AD10LDU	 163	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
#define R2AD20LDU	 BUFFER[451]	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	 164	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
#define R2AD10LDU	 BUFFER[453]	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
#define idR2AD10LDU	 165	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
#define R1AD20LDU	 BUFFER[455]	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	 166	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
#define R1AD10LDU	 BUFFER[457]	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
#define idR1AD10LDU	 167	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
#define B6AD20LDU	 BUFFER[459]	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
#define idB6AD20LDU	 168	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
#define B6AD10LDU	 BUFFER[461]	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
#define idB6AD10LDU	 169	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
#define A6AD20LDU	 BUFFER[463]	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
#define idA6AD20LDU	 170	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
#define A6AD10LDU	 BUFFER[465]	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
#define idA6AD10LDU	 171	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
#define A8AD20LDU	 BUFFER[467]	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
#define idA8AD20LDU	 172	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
#define A8AD10LDU	 BUFFER[469]	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
#define idA8AD10LDU	 173	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
#define A2AD21LDU	 BUFFER[471]	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 174	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
#define A2AD11LDU	 BUFFER[473]	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 175	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
#define B1AD05LDU	 BUFFER[475]	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
#define idB1AD05LDU	 176	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
#define B1AD04LDU	 BUFFER[477]	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
#define idB1AD04LDU	 177	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[479]	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
#define idB1AD03LDU	 178	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
#define B1AD02LDU	 BUFFER[481]	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
#define idB1AD02LDU	 179	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
#define B1AD01LDU	 BUFFER[483]	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
#define idB1AD01LDU	 180	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
#define B1AD21LDU	 BUFFER[485]	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 181	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
#define B1AD11LDU	 BUFFER[487]	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 182	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
#define A1AD05LDU	 BUFFER[489]	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
#define idA1AD05LDU	 183	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
#define A1AD04LDU	 BUFFER[491]	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
#define idA1AD04LDU	 184	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[493]	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
#define idA1AD03LDU	 185	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
#define A1AD02LDU	 BUFFER[495]	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
#define idA1AD02LDU	 186	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
#define A1AD01LDU	 BUFFER[497]	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
#define idA1AD01LDU	 187	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
#define A1AD21LDU	 BUFFER[499]	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 188	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
#define A1AD11LDU	 BUFFER[501]	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 189	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
#define A0SR01RIM	 BUFFER[503]	//( - , SCM) Текущая реактивность AЗ1
#define idA0SR01RIM	 190	//( - , SCM) Текущая реактивность AЗ1
#define A3AD02LDU	 BUFFER[508]	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
#define idA3AD02LDU	 191	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
#define A3AD01LDU	 BUFFER[510]	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
#define idA3AD01LDU	 192	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
#define A3AD21LDU	 BUFFER[512]	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 193	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
#define A3AD11LDU	 BUFFER[514]	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 194	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
#define B2AD33LDU	 BUFFER[516]	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
#define idB2AD33LDU	 195	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
#define B2AD05LDU	 BUFFER[518]	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
#define idB2AD05LDU	 196	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
#define B2AD04LDU	 BUFFER[520]	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
#define idB2AD04LDU	 197	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[522]	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
#define idB2AD03LDU	 198	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
#define B2AD02LDU	 BUFFER[524]	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
#define idB2AD02LDU	 199	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
#define B2AD01LDU	 BUFFER[526]	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
#define idB2AD01LDU	 200	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
#define B2AD21LDU	 BUFFER[528]	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 201	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
#define B2AD11LDU	 BUFFER[530]	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 202	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
#define A2AD33LDU	 BUFFER[532]	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
#define idA2AD33LDU	 203	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
#define A2AD05LDU	 BUFFER[534]	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
#define idA2AD05LDU	 204	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
#define A2AD04LDU	 BUFFER[536]	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
#define idA2AD04LDU	 205	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[538]	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
#define idA2AD03LDU	 206	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
#define A2AD02LDU	 BUFFER[540]	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
#define idA2AD02LDU	 207	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
#define A2AD01LDU	 BUFFER[542]	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
#define idA2AD01LDU	 208	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
#define A2IP01IZ2	 BUFFER[544]	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ2	 209	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
#define A2IP01IZ1	 BUFFER[547]	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	 210	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
#define B3IS21LDU	 BUFFER[550]	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
#define idB3IS21LDU	 211	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
#define A3IS21LDU	 BUFFER[552]	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
#define idA3IS21LDU	 212	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
#define A2IS33LDU	 BUFFER[554]	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
#define idA2IS33LDU	 213	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
#define A2IC01UDU	 BUFFER[556]	//( - , SDu) Координата штока РБ1
#define idA2IC01UDU	 214	//( - , SDu) Координата штока РБ1
#define A2IS12LDU	 BUFFER[561]	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	 215	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
#define A2IS11LDU	 BUFFER[563]	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
#define idA2IS11LDU	 216	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
#define A2IS21LDU	 BUFFER[565]	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
#define idA2IS21LDU	 217	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
#define B0IT02IZ2	 BUFFER[567]	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
#define idB0IT02IZ2	 218	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
#define B0IT01IZ1	 BUFFER[570]	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
#define idB0IT01IZ1	 219	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
#define A0IT02IZ2	 BUFFER[573]	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
#define idA0IT02IZ2	 220	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
#define A0IT01IZ1	 BUFFER[576]	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
#define idA0IT01IZ1	 221	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
#define R6IS21LDU	 BUFFER[579]	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	 222	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
#define B7AS31LDU	 BUFFER[581]	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
#define idB7AS31LDU	 223	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
#define A7AS31LDU	 BUFFER[583]	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
#define idA7AS31LDU	 224	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
#define B3IS35LDU	 BUFFER[585]	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
#define idB3IS35LDU	 225	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
#define R6IS64LDU	 BUFFER[587]	//( - , - ) Исправность ВИП ССДИ-35 1канал
#define idR6IS64LDU	 226	//( - , - ) Исправность ВИП ССДИ-35 1канал
#define R6IS63LDU	 BUFFER[589]	//( - , - ) Исправность ВИП ССДИ-39 2канал
#define idR6IS63LDU	 227	//( - , - ) Исправность ВИП ССДИ-39 2канал
#define R6IS62LDU	 BUFFER[591]	//( - , - ) Исправность ВИП ССДИ-39 1канал
#define idR6IS62LDU	 228	//( - , - ) Исправность ВИП ССДИ-39 1канал
#define B3IS22LDU	 BUFFER[593]	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
#define idB3IS22LDU	 229	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
#define A3IS22LDU	 BUFFER[595]	//(do32_pti:100 - K06DO, - ) Приход на НУП ИС1
#define idA3IS22LDU	 230	//(do32_pti:100 - K06DO, - ) Приход на НУП ИС1
#define B3IS11LDU	 BUFFER[597]	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
#define idB3IS11LDU	 231	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
#define A3IS11LDU	 BUFFER[599]	//(do32_pti:100 - K05DO, - ) Приход на ВУ ИС1
#define idA3IS11LDU	 232	//(do32_pti:100 - K05DO, - ) Приход на ВУ ИС1
#define A3IP02IDU	 BUFFER[601]	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 233	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
#define B3VP81LDU	 BUFFER[604]	//( - , - ) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 234	//( - , - ) Давление СПУСК ИС2 в норме
#define A3VP81LDU	 BUFFER[606]	//( - , - ) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 235	//( - , - ) Давление СПУСК ИС1 в норме
#define B3IS33LDU	 BUFFER[608]	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idB3IS33LDU	 236	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define B3IC01UDU	 BUFFER[610]	//( - , SDu) Координата штока ИС2
#define idB3IC01UDU	 237	//( - , SDu) Координата штока ИС2
#define B3IS31LDU	 BUFFER[615]	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
#define idB3IS31LDU	 238	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
#define B3IP02IDU	 BUFFER[617]	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
#define idB3IP02IDU	 239	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
#define A3IS33LDU	 BUFFER[620]	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define idA3IS33LDU	 240	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define A3IC01UDU	 BUFFER[622]	//( - , SDu) Координата штока ИС1
#define idA3IC01UDU	 241	//( - , SDu) Координата штока ИС1
#define A3IS31LDU	 BUFFER[627]	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
#define idA3IS31LDU	 242	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
#define A2VP82LDU	 BUFFER[629]	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 243	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define B2AD31LDU	 BUFFER[631]	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
#define idB2AD31LDU	 244	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
#define B1AD32LDU	 BUFFER[633]	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
#define idB1AD32LDU	 245	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
#define B1AD31LDU	 BUFFER[635]	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
#define idB1AD31LDU	 246	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
#define A3AD31LDU	 BUFFER[637]	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
#define idA3AD31LDU	 247	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
#define C1MD31LP1	 BUFFER[639]	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
#define idC1MD31LP1	 248	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
#define C1MD31LP2	 BUFFER[641]	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
#define idC1MD31LP2	 249	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
#define A1AD31LDU	 BUFFER[643]	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
#define idA1AD31LDU	 250	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
#define A1AD32LDU	 BUFFER[645]	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
#define idA1AD32LDU	 251	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
#define A2AD31LDU	 BUFFER[647]	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
#define idA2AD31LDU	 252	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
#define C2MD31LP1	 BUFFER[649]	//( - , SCM) Кнопка «СБРОС РБ»
#define idC2MD31LP1	 253	//( - , SCM) Кнопка «СБРОС РБ»
#define A2AD32LDU	 BUFFER[651]	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
#define idA2AD32LDU	 254	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
#define R0VZ71LZ2	 BUFFER[653]	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
#define idR0VZ71LZ2	 255	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
#define R0VZ71LZ1	 BUFFER[655]	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
#define idR0VZ71LZ1	 256	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
#define R8AD21LDU	 BUFFER[657]	//(vds32_pti:310 - K31VDSR, - ) Запуск системы инициирования
#define idR8AD21LDU	 257	//(vds32_pti:310 - K31VDSR, - ) Запуск системы инициирования
#define R0AD14LDU	 BUFFER[659]	//( - , SCM) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 258	//( - , SCM) Имитация срабатывания верхней АС II УР
#define R0SR02RIM	 BUFFER[661]	//( - , SCM) Текущая мощность РУ (ватт)
#define idR0SR02RIM	 259	//( - , SCM) Текущая мощность РУ (ватт)
#define R0CR02RIM	 BUFFER[666]	//( - , SCM) Коэффициент 11 связи АЗ1,2
#define idR0CR02RIM	 260	//( - , SCM) Коэффициент 11 связи АЗ1,2
#define B3AD34LDU	 BUFFER[671]	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
#define idB3AD34LDU	 261	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
#define A3IS35LDU	 BUFFER[673]	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
#define idA3IS35LDU	 262	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
#define R7II73LZ2	 BUFFER[675]	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
#define idR7II73LZ2	 263	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
#define R7II71LZ2	 BUFFER[677]	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
#define idR7II71LZ2	 264	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
#define R7II72LZ2	 BUFFER[679]	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
#define idR7II72LZ2	 265	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
#define R0AD16LDU	 BUFFER[681]	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
#define idR0AD16LDU	 266	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
#define R7II72LZ1	 BUFFER[683]	//(do32_pti:100 - K25DO, - ) Сработала АС IУР (датчик 2)
#define idR7II72LZ1	 267	//(do32_pti:100 - K25DO, - ) Сработала АС IУР (датчик 2)
#define R7II71LZ1	 BUFFER[685]	//(do32_pti:100 - K24DO, - ) Сработала АС IУР (датчик 1)
#define idR7II71LZ1	 268	//(do32_pti:100 - K24DO, - ) Сработала АС IУР (датчик 1)
#define R7II73LZ1	 BUFFER[687]	//(do32_pti:100 - K26DO, - ) Сработала АС IIУР
#define idR7II73LZ1	 269	//(do32_pti:100 - K26DO, - ) Сработала АС IIУР
#define R0SR01RIM	 BUFFER[689]	//( - , SCM) Текущая реактивность PУ
#define idR0SR01RIM	 270	//( - , SCM) Текущая реактивность PУ
#define R0ST01RIM	 BUFFER[694]	//( - , SCM) Текущий период разгона РУ
#define idR0ST01RIM	 271	//( - , SCM) Текущий период разгона РУ
#define A4AD10LDU	 BUFFER[699]	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
#define idA4AD10LDU	 272	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
#define B4AD10LDU	 BUFFER[701]	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
#define idB4AD10LDU	 273	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
#define A9AD10LDU	 BUFFER[703]	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
#define idA9AD10LDU	 274	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
#define B9AD10LDU	 BUFFER[705]	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
#define idB9AD10LDU	 275	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
#define R0MW13LP2	 BUFFER[707]	//( - , SCM) Переключатель «СЕТЬ»
#define idR0MW13LP2	 276	//( - , SCM) Переключатель «СЕТЬ»
#define B3AD31LDU	 BUFFER[709]	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
#define idB3AD31LDU	 277	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
#define B2AD32LDU	 BUFFER[711]	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
#define idB2AD32LDU	 278	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
#define fEM_R0UL01RIM	 BUFFER[713]	//(R0UL01RIM) Среднее время генерации нейтронов
#define idfEM_R0UL01RIM	 279	//(R0UL01RIM) Среднее время генерации нейтронов
#define fEM_R0UN02RIM	 BUFFER[718]	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define idfEM_R0UN02RIM	 280	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define fEM_A1UR01RIM	 BUFFER[723]	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR01RIM	 281	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define fEM_A1UR00RIM	 BUFFER[728]	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR00RIM	 282	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define fEM_A3UR00RIM	 BUFFER[733]	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR00RIM	 283	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define fEM_A3UR01RIM	 BUFFER[738]	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR01RIM	 284	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define fEM_R0UT01RIM	 BUFFER[743]	//(R0UT01RIM) Температурный коэффициент (долл)
#define idfEM_R0UT01RIM	 285	//(R0UT01RIM) Температурный коэффициент (долл)
#define fEM_R0UT02RIM	 BUFFER[748]	//(R0UT02RIM) Масса топлива в АЗ
#define idfEM_R0UT02RIM	 286	//(R0UT02RIM) Масса топлива в АЗ
#define fEM_R0UT04RIM	 BUFFER[753]	//(R0UT04RIM) Удельная теплоёмкость топлива
#define idfEM_R0UT04RIM	 287	//(R0UT04RIM) Удельная теплоёмкость топлива
#define fEM_R0UT03RIM	 BUFFER[758]	//(R0UT03RIM) Нормальная температура АЗ град
#define idfEM_R0UT03RIM	 288	//(R0UT03RIM) Нормальная температура АЗ град
#define fEM_R0UT05RIM	 BUFFER[763]	//(R0UT05RIM) Энергия деления ядра
#define idfEM_R0UT05RIM	 289	//(R0UT05RIM) Энергия деления ядра
#define fEM_R0UT06RIM	 BUFFER[768]	//(R0UT06RIM) Конвекционное сопротивление при обдуве
#define idfEM_R0UT06RIM	 290	//(R0UT06RIM) Конвекционное сопротивление при обдуве
#define fEM_A1UC02RDU	 BUFFER[773]	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define idfEM_A1UC02RDU	 291	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define fEM_A1UC04RIM	 BUFFER[778]	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define idfEM_A1UC04RIM	 292	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define fEM_A1UC05RIM	 BUFFER[783]	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define idfEM_A1UC05RIM	 293	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define fEM_A1UC06RIM	 BUFFER[788]	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define idfEM_A1UC06RIM	 294	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define fEM_A2UC06RIM	 BUFFER[793]	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define idfEM_A2UC06RIM	 295	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define fEM_A2UC05RIM	 BUFFER[798]	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define idfEM_A2UC05RIM	 296	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define fEM_A2UC04RIM	 BUFFER[803]	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define idfEM_A2UC04RIM	 297	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define fEM_A2UC02RDU	 BUFFER[808]	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define idfEM_A2UC02RDU	 298	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define fEM_A3UC06RIM	 BUFFER[813]	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define idfEM_A3UC06RIM	 299	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define fEM_A3UC05RIM	 BUFFER[818]	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC05RIM	 300	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define fEM_A3UC04RIM	 BUFFER[823]	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define idfEM_A3UC04RIM	 301	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define fEM_A3UC02RDU	 BUFFER[828]	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define idfEM_A3UC02RDU	 302	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define fEM_R4UV80RDU	 BUFFER[833]	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
#define idfEM_R4UV80RDU	 303	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
#define fEM_R4UC10RIM	 BUFFER[838]	//(R4UC10RIM) Координата верхних механических упоров тележки мм
#define idfEM_R4UC10RIM	 304	//(R4UC10RIM) Координата верхних механических упоров тележки мм
#define fEM_R4UC20RIM	 BUFFER[843]	//(R4UC20RIM) Координата нижних механических упоров тележки мм
#define idfEM_R4UC20RIM	 305	//(R4UC20RIM) Координата нижних механических упоров тележки мм
#define fEM_B8UC21RIM	 BUFFER[848]	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define idfEM_B8UC21RIM	 306	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define fEM_B8UC20RIM	 BUFFER[853]	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define idfEM_B8UC20RIM	 307	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define fEM_B8UC11RIM	 BUFFER[858]	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define idfEM_B8UC11RIM	 308	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define fEM_B8UC10RIM	 BUFFER[863]	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define idfEM_B8UC10RIM	 309	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define fEM_B8UV80RDU	 BUFFER[868]	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define idfEM_B8UV80RDU	 310	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define fEM_A8UV80RDU	 BUFFER[873]	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define idfEM_A8UV80RDU	 311	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define fEM_A8UC10RIM	 BUFFER[878]	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define idfEM_A8UC10RIM	 312	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define fEM_A8UC11RIM	 BUFFER[883]	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define idfEM_A8UC11RIM	 313	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define fEM_A8UC20RIM	 BUFFER[888]	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define idfEM_A8UC20RIM	 314	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define fEM_A8UC21RIM	 BUFFER[893]	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define idfEM_A8UC21RIM	 315	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define fEM_A6UC10RIM	 BUFFER[898]	//(A6UC10RIM) Время полного хода БЗ (сек)
#define idfEM_A6UC10RIM	 316	//(A6UC10RIM) Время полного хода БЗ (сек)
#define fEM_R1UC10RIM	 BUFFER[903]	//(R1UC10RIM) Время полного хода МДЗ сек
#define idfEM_R1UC10RIM	 317	//(R1UC10RIM) Время полного хода МДЗ сек
#define fEM_A5UC10RIM	 BUFFER[908]	//(A5UC10RIM) Время полного хода НЛ сек
#define idfEM_A5UC10RIM	 318	//(A5UC10RIM) Время полного хода НЛ сек
#define fEM_A0UN01RIM	 BUFFER[913]	//(A0UN01RIM) Мощность источника нейтронов ИНИ
#define idfEM_A0UN01RIM	 319	//(A0UN01RIM) Мощность источника нейтронов ИНИ
#define fEM_R4UC22RIM	 BUFFER[918]	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define idfEM_R4UC22RIM	 320	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define fEM_A1UG01RDU	 BUFFER[923]	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define idfEM_A1UG01RDU	 321	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define fEM_A2UG01RDU	 BUFFER[928]	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
#define idfEM_A2UG01RDU	 322	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
#define fEM_A3UG01RDU	 BUFFER[933]	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
#define idfEM_A3UG01RDU	 323	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
#define fEM_R7UC10RIM	 BUFFER[938]	//(R7UC10RIM) X-координата КНК53М R7IN13 см
#define idfEM_R7UC10RIM	 324	//(R7UC10RIM) X-координата КНК53М R7IN13 см
#define fEM_R7UC19RIM	 BUFFER[943]	//(R7UC19RIM) Y-координата СНМ-11 (11) см
#define idfEM_R7UC19RIM	 325	//(R7UC19RIM) Y-координата СНМ-11 (11) см
#define fEM_R7UI02RIM	 BUFFER[948]	//(R7UI02RIM) Коэффициент усиления уровня радиации
#define idfEM_R7UI02RIM	 326	//(R7UI02RIM) Коэффициент усиления уровня радиации
#define fEM_R7UL01RIM	 BUFFER[953]	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define idfEM_R7UL01RIM	 327	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define fEM_A2UR00RIM	 BUFFER[958]	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define idfEM_A2UR00RIM	 328	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define fEM_A2UR01RIM	 BUFFER[963]	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define idfEM_A2UR01RIM	 329	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define fEM_A0UN02RIM	 BUFFER[968]	//(A0UN02RIM) Мощность источника нейтронов с АНИ
#define idfEM_A0UN02RIM	 330	//(A0UN02RIM) Мощность источника нейтронов с АНИ
#define fEM_R0UR30RIM	 BUFFER[973]	//(R0UR30RIM) Реактивность вносимая образцами (долл)
#define idfEM_R0UR30RIM	 331	//(R0UR30RIM) Реактивность вносимая образцами (долл)
#define fEM_R0UR01RIM	 BUFFER[978]	//(R0UR01RIM) Стартовая отрицательная реактивность
#define idfEM_R0UR01RIM	 332	//(R0UR01RIM) Стартовая отрицательная реактивность
#define fEM_R0UT02RDU	 BUFFER[983]	//(R0UT02RDU) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RDU	 333	//(R0UT02RDU) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RDU	 BUFFER[988]	//(R0UT01RDU) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RDU	 334	//(R0UT01RDU) Нижний предел шкалы датчика температуры
#define fEM_A1UC03RDU	 BUFFER[993]	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define idfEM_A1UC03RDU	 335	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define fEM_A2UP03RDU	 BUFFER[998]	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP03RDU	 336	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UP04RDU	 BUFFER[1003]	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP04RDU	 337	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UC03RDU	 BUFFER[1008]	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define idfEM_A2UC03RDU	 338	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define fEM_A3UP03RDU	 BUFFER[1013]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 339	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1018]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 340	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UC03RDU	 BUFFER[1023]	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define idfEM_A3UC03RDU	 341	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define fEM_R7UI74RIM	 BUFFER[1028]	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define idfEM_R7UI74RIM	 342	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define fEM_A8UC03RDU	 BUFFER[1033]	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define idfEM_A8UC03RDU	 343	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define fEM_R0UV87RDU	 BUFFER[1038]	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 344	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV81RDU	 BUFFER[1043]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 345	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1048]	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 346	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1053]	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 347	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1058]	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 348	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1063]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 349	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1068]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 350	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_A8UC08RDU	 BUFFER[1073]	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define idfEM_A8UC08RDU	 351	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define fEM_B8UC08RDU	 BUFFER[1078]	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define idfEM_B8UC08RDU	 352	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define fEM_R4UC08RDU	 BUFFER[1083]	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define idfEM_R4UC08RDU	 353	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define fEM_R0UH01RSS	 BUFFER[1088]	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
#define idfEM_R0UH01RSS	 354	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
#define fEM_A0UX00RSS	 BUFFER[1093]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 355	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_R7UX01RSS	 BUFFER[1098]	//(R7UX01RSS) X-координата камеры R7IN11
#define idfEM_R7UX01RSS	 356	//(R7UX01RSS) X-координата камеры R7IN11
#define fEM_R7UX02RSS	 BUFFER[1103]	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define idfEM_R7UX02RSS	 357	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define fEM_R7UX04RSS	 BUFFER[1108]	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define idfEM_R7UX04RSS	 358	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define fEM_R7UX05RSS	 BUFFER[1113]	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define idfEM_R7UX05RSS	 359	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define fEM_R7UX06RSS	 BUFFER[1118]	//(R7UX06RSS) X-координата камеры R7IN23 (см)
#define idfEM_R7UX06RSS	 360	//(R7UX06RSS) X-координата камеры R7IN23 (см)
#define fEM_R7UX07RSS	 BUFFER[1123]	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define idfEM_R7UX07RSS	 361	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define fEM_R7UX08RSS	 BUFFER[1128]	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define idfEM_R7UX08RSS	 362	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define fEM_R7UX09RSS	 BUFFER[1133]	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define idfEM_R7UX09RSS	 363	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define fEM_R7UY01RSS	 BUFFER[1138]	//(R7UY01RSS) Y-координата камеры R7IN11
#define idfEM_R7UY01RSS	 364	//(R7UY01RSS) Y-координата камеры R7IN11
#define fEM_R7UY02RSS	 BUFFER[1143]	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define idfEM_R7UY02RSS	 365	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define fEM_R7UY04RSS	 BUFFER[1148]	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define idfEM_R7UY04RSS	 366	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define fEM_R7UY05RSS	 BUFFER[1153]	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define idfEM_R7UY05RSS	 367	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define fEM_R7UY06RSS	 BUFFER[1158]	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define idfEM_R7UY06RSS	 368	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define fEM_R7UY07RSS	 BUFFER[1163]	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define idfEM_R7UY07RSS	 369	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define fEM_R7UY08RSS	 BUFFER[1168]	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define idfEM_R7UY08RSS	 370	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define fEM_R7UY09RSS	 BUFFER[1173]	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define idfEM_R7UY09RSS	 371	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define fEM_R7UX10RSS	 BUFFER[1178]	//(R7UX10RSS) X-координата камеры R7IN41
#define idfEM_R7UX10RSS	 372	//(R7UX10RSS) X-координата камеры R7IN41
#define fEM_R7UX11RSS	 BUFFER[1183]	//(R7UX11RSS) X-координата камеры R7IN42
#define idfEM_R7UX11RSS	 373	//(R7UX11RSS) X-координата камеры R7IN42
#define fEM_R7UX12RSS	 BUFFER[1188]	//(R7UX12RSS) X-координата камеры R7IN43
#define idfEM_R7UX12RSS	 374	//(R7UX12RSS) X-координата камеры R7IN43
#define fEM_R7UY10RSS	 BUFFER[1193]	//(R7UY10RSS) Y-координата камеры R7IN41
#define idfEM_R7UY10RSS	 375	//(R7UY10RSS) Y-координата камеры R7IN41
#define fEM_R7UY11RSS	 BUFFER[1198]	//(R7UY11RSS) Y-координата камеры R7IN42
#define idfEM_R7UY11RSS	 376	//(R7UY11RSS) Y-координата камеры R7IN42
#define fEM_R7UY12RSS	 BUFFER[1203]	//(R7UY12RSS) Y-координата камеры R7IN43
#define idfEM_R7UY12RSS	 377	//(R7UY12RSS) Y-координата камеры R7IN43
#define fEM_A0UX01RSS	 BUFFER[1208]	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define idfEM_A0UX01RSS	 378	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define fEM_A0UX02RSS	 BUFFER[1213]	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define idfEM_A0UX02RSS	 379	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define fEM_A0UX03RSS	 BUFFER[1218]	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define idfEM_A0UX03RSS	 380	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define fEM_A0UX04RSS	 BUFFER[1223]	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define idfEM_A0UX04RSS	 381	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define fEM_A0UX05RSS	 BUFFER[1228]	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define idfEM_A0UX05RSS	 382	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define fEM_A0UX06RSS	 BUFFER[1233]	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define idfEM_A0UX06RSS	 383	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define fEM_A0UX07RSS	 BUFFER[1238]	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define idfEM_A0UX07RSS	 384	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define fEM_A0UX08RSS	 BUFFER[1243]	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define idfEM_A0UX08RSS	 385	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define fEM_A0UX09RSS	 BUFFER[1248]	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define idfEM_A0UX09RSS	 386	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define fEM_A0UX10RSS	 BUFFER[1253]	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define idfEM_A0UX10RSS	 387	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define fEM_A0UX11RSS	 BUFFER[1258]	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define idfEM_A0UX11RSS	 388	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define fEM_A0UX12RSS	 BUFFER[1263]	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define idfEM_A0UX12RSS	 389	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define fEM_B0UX01RSS	 BUFFER[1268]	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define idfEM_B0UX01RSS	 390	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define fEM_B0UX02RSS	 BUFFER[1273]	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define idfEM_B0UX02RSS	 391	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define fEM_B0UX03RSS	 BUFFER[1278]	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	 392	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	 BUFFER[1283]	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
#define idfEM_B0UX04RSS	 393	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
#define fEM_B0UX05RSS	 BUFFER[1288]	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	 394	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_B0UX06RSS	 BUFFER[1293]	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define idfEM_B0UX06RSS	 395	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define fEM_B0UX07RSS	 BUFFER[1298]	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define idfEM_B0UX07RSS	 396	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define fEM_B0UX08RSS	 BUFFER[1303]	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define idfEM_B0UX08RSS	 397	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define fEM_B0UX09RSS	 BUFFER[1308]	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define idfEM_B0UX09RSS	 398	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define fEM_B0UX10RSS	 BUFFER[1313]	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define idfEM_B0UX10RSS	 399	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define fEM_B0UX11RSS	 BUFFER[1318]	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define idfEM_B0UX11RSS	 400	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define fEM_B0UX12RSS	 BUFFER[1323]	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define idfEM_B0UX12RSS	 401	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define fEM_R0UH02RSS	 BUFFER[1328]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define idfEM_R0UH02RSS	 402	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define fEM_R0UH03RSS	 BUFFER[1333]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define idfEM_R0UH03RSS	 403	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define fEM_R4US80RDU	 BUFFER[1338]	//(R4US80RDU) Тормозной путь тележки (мм)
#define idfEM_R4US80RDU	 404	//(R4US80RDU) Тормозной путь тележки (мм)
#define fEM_R7UI71RIM	 BUFFER[1343]	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define idfEM_R7UI71RIM	 405	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define fEM_R7UI72RIM	 BUFFER[1348]	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define idfEM_R7UI72RIM	 406	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define fEM_R7UI73RIM	 BUFFER[1353]	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define idfEM_R7UI73RIM	 407	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define fEM_A1UP01RIM	 BUFFER[1358]	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define idfEM_A1UP01RIM	 408	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define fEM_A2UP01RIM	 BUFFER[1363]	//(A2UP01RIM) Текущее давление на сброс РБ
#define idfEM_A2UP01RIM	 409	//(A2UP01RIM) Текущее давление на сброс РБ
#define fEM_A0UP02RIM	 BUFFER[1368]	//(A0UP02RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP02RIM	 410	//(A0UP02RIM) Текущее давление в АЗ1,2
#define fEM_A3UP01RIM	 BUFFER[1373]	//(A3UP01RIM) Текущее давление на СПУСК ИС
#define idfEM_A3UP01RIM	 411	//(A3UP01RIM) Текущее давление на СПУСК ИС
#define fEM_A1UP82RIM	 BUFFER[1378]	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define idfEM_A1UP82RIM	 412	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define fEM_A3UP02RDU	 BUFFER[1383]	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define idfEM_A3UP02RDU	 413	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define fEM_A1UV02RIM	 BUFFER[1388]	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define idfEM_A1UV02RIM	 414	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define fEM_A3UV02RIM	 BUFFER[1393]	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define idfEM_A3UV02RIM	 415	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define fEM_A2UV02RIM	 BUFFER[1398]	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define idfEM_A2UV02RIM	 416	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define fEM_B8US80RDU	 BUFFER[1403]	//(B8US80RDU) Тормозной путь АЗ2 (мм)
#define idfEM_B8US80RDU	 417	//(B8US80RDU) Тормозной путь АЗ2 (мм)
#define fEM_A8US80RDU	 BUFFER[1408]	//(A8US80RDU) Тормозной путь ДС2 (мм)
#define idfEM_A8US80RDU	 418	//(A8US80RDU) Тормозной путь ДС2 (мм)
#define fEM_A6US80RDU	 BUFFER[1413]	//(A6US80RDU) Тормозной путь БЗ (мм)
#define idfEM_A6US80RDU	 419	//(A6US80RDU) Тормозной путь БЗ (мм)
#define fEM_A1US07RDU	 BUFFER[1418]	//(A1US07RDU) Постоянная времени масляного демпфера ББ
#define idfEM_A1US07RDU	 420	//(A1US07RDU) Постоянная времени масляного демпфера ББ
#define fEM_A2US07RDU	 BUFFER[1423]	//(A2US07RDU) Постоянная времени масляного демпфера РБ
#define idfEM_A2US07RDU	 421	//(A2US07RDU) Постоянная времени масляного демпфера РБ
#define fEM_A3US07RDU	 BUFFER[1428]	//(A3US07RDU) Постоянная времени масляного демпфера ИС
#define idfEM_A3US07RDU	 422	//(A3US07RDU) Постоянная времени масляного демпфера ИС
#define fEM_R7UI75RIM	 BUFFER[1433]	//(R7UI75RIM) Множитель к уровню радиации
#define idfEM_R7UI75RIM	 423	//(R7UI75RIM) Множитель к уровню радиации
#define fEM_R0UH21RSS	 BUFFER[1438]	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	 424	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	 BUFFER[1443]	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	 425	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	 BUFFER[1448]	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	 426	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0UH05RSS	 BUFFER[1453]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 427	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_A4UL10RIM	 BUFFER[1458]	//(A4UL10RIM) Время полного перемещения НИ сек
#define idfEM_A4UL10RIM	 428	//(A4UL10RIM) Время полного перемещения НИ сек
#define fEM_A9UL10RIM	 BUFFER[1463]	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define idfEM_A9UL10RIM	 429	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define fEM_R3UL10RIM	 BUFFER[1468]	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define idfEM_R3UL10RIM	 430	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define fEM_R5UL10RIM	 BUFFER[1473]	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define idfEM_R5UL10RIM	 431	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define fEM_R6UL10RIM	 BUFFER[1478]	//(R6UL10RIM) Время полного хода кран-балки сек
#define idfEM_R6UL10RIM	 432	//(R6UL10RIM) Время полного хода кран-балки сек
#define lEM_C1AD31LRP	 BUFFER[1483]	//(C1AD31LRP) Общий сброс от РПУ
#define idlEM_C1AD31LRP	 433	//(C1AD31LRP) Общий сброс от РПУ
#define lEM_R0IE01LRP	 BUFFER[1485]	//(R0IE01LRP) Отключение питание детекторов
#define idlEM_R0IE01LRP	 434	//(R0IE01LRP) Отключение питание детекторов
#define lEM_R0IE02LRP	 BUFFER[1487]	//(R0IE02LRP) Отключить питание ПР, ПУ
#define idlEM_R0IE02LRP	 435	//(R0IE02LRP) Отключить питание ПР, ПУ
#define fEM_A2UP02RIM	 BUFFER[1489]	//(A2UP02RIM) Текущее давление на подъём РБ
#define idfEM_A2UP02RIM	 436	//(A2UP02RIM) Текущее давление на подъём РБ
#define fEM_A2UP03RIM	 BUFFER[1494]	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define idfEM_A2UP03RIM	 437	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define fEM_A0UP01RIM	 BUFFER[1499]	//(A0UP01RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP01RIM	 438	//(A0UP01RIM) Текущее давление в АЗ1,2
#define fEM_A3UP02RIM	 BUFFER[1504]	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define idfEM_A3UP02RIM	 439	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define fEM_A4UP01RIM	 BUFFER[1509]	//(A4UP01RIM) Текущее давление на подъём НИ
#define idfEM_A4UP01RIM	 440	//(A4UP01RIM) Текущее давление на подъём НИ
#define fEM_A4UP02RIM	 BUFFER[1514]	//(A4UP02RIM) Нижняя граница давления на подъём НИ
#define idfEM_A4UP02RIM	 441	//(A4UP02RIM) Нижняя граница давления на подъём НИ
#define fEM_R7UI76RIM	 BUFFER[1519]	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define idfEM_R7UI76RIM	 442	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define fEM_R7UI77RIM	 BUFFER[1524]	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define idfEM_R7UI77RIM	 443	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define iEM_TERBB1	 BUFFER[1529]	//(TERBB1) Неисправности  ББ1
#define idiEM_TERBB1	 444	//(TERBB1) Неисправности  ББ1
#define fEM_A1MC02RC1	 BUFFER[1532]	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
#define idfEM_A1MC02RC1	 445	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
#define fEM_A1MV02RC1	 BUFFER[1537]	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define idfEM_A1MV02RC1	 446	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define iEM_TERBB2	 BUFFER[1542]	//(TERBB2) Неисправности  ББ2
#define idiEM_TERBB2	 447	//(TERBB2) Неисправности  ББ2
#define fEM_B1MC02RC1	 BUFFER[1545]	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
#define idfEM_B1MC02RC1	 448	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
#define fEM_B1MV02RC1	 BUFFER[1550]	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define idfEM_B1MV02RC1	 449	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define iEM_TERRB2	 BUFFER[1555]	//(TERRB2) Неисправности  РБ2
#define idiEM_TERRB2	 450	//(TERRB2) Неисправности  РБ2
#define fEM_B2MC02RC1	 BUFFER[1558]	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
#define idfEM_B2MC02RC1	 451	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
#define fEM_B2MV02RC1	 BUFFER[1563]	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define idfEM_B2MV02RC1	 452	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define iEM_TERRB1	 BUFFER[1568]	//(TERRB1) Неисправности  РБ1
#define idiEM_TERRB1	 453	//(TERRB1) Неисправности  РБ1
#define fEM_A2MC02RC1	 BUFFER[1571]	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
#define idfEM_A2MC02RC1	 454	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
#define fEM_A2MV02RC1	 BUFFER[1576]	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define idfEM_A2MV02RC1	 455	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define iEM_TERIS2	 BUFFER[1581]	//(TERIS2) Неисправности  ИС2
#define idiEM_TERIS2	 456	//(TERIS2) Неисправности  ИС2
#define fEM_B3MC02RC1	 BUFFER[1584]	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
#define idfEM_B3MC02RC1	 457	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
#define fEM_B3MV02RC1	 BUFFER[1589]	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define idfEM_B3MV02RC1	 458	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define iEM_TERIS1	 BUFFER[1594]	//(TERIS1) Неисправности  ИС1
#define idiEM_TERIS1	 459	//(TERIS1) Неисправности  ИС1
#define fEM_A3MC02RC1	 BUFFER[1597]	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
#define idfEM_A3MC02RC1	 460	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
#define fEM_A3MV02RC1	 BUFFER[1602]	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define idfEM_A3MV02RC1	 461	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define iEM_TERA1IE04LDU	 BUFFER[1607]	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define idiEM_TERA1IE04LDU	 462	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define iEM_TERA1IE03LDU	 BUFFER[1610]	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define idiEM_TERA1IE03LDU	 463	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define fEM_A1MC01RC1	 BUFFER[1613]	//(A1MC01RC1) Заданная координата  ББ1 от ИС
#define idfEM_A1MC01RC1	 464	//(A1MC01RC1) Заданная координата  ББ1 от ИС
#define iEM_TERB1IE03LDU	 BUFFER[1618]	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define idiEM_TERB1IE03LDU	 465	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define iEM_TERB1IE04LDU	 BUFFER[1621]	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define idiEM_TERB1IE04LDU	 466	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define fEM_B1MC01RC1	 BUFFER[1624]	//(B1MC01RC1) Заданная координата ББ2 от ИС
#define idfEM_B1MC01RC1	 467	//(B1MC01RC1) Заданная координата ББ2 от ИС
#define fEM_B1MV01RC1	 BUFFER[1629]	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define idfEM_B1MV01RC1	 468	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define fEM_B2MC01RC1	 BUFFER[1634]	//(B2MC01RC1) Заданная координата РБ2 от ИС
#define idfEM_B2MC01RC1	 469	//(B2MC01RC1) Заданная координата РБ2 от ИС
#define fEM_B2MV01RC1	 BUFFER[1639]	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define idfEM_B2MV01RC1	 470	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define fEM_A3MC01RC1	 BUFFER[1644]	//(A3MC01RC1) Заданная координата ИС1 от ИС
#define idfEM_A3MC01RC1	 471	//(A3MC01RC1) Заданная координата ИС1 от ИС
#define fEM_A3MV01RC1	 BUFFER[1649]	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define idfEM_A3MV01RC1	 472	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define fEM_B3MC01RC1	 BUFFER[1654]	//(B3MC01RC1) Заданная координата ИС2 от ИС
#define idfEM_B3MC01RC1	 473	//(B3MC01RC1) Заданная координата ИС2 от ИС
#define fEM_B3MV01RC1	 BUFFER[1659]	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define idfEM_B3MV01RC1	 474	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define iEM_TERA2SS21LIM	 BUFFER[1664]	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define idiEM_TERA2SS21LIM	 475	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define iEM_TERA2SS12LIM	 BUFFER[1667]	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define idiEM_TERA2SS12LIM	 476	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define iEM_TERR6SS21LIM	 BUFFER[1670]	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define idiEM_TERR6SS21LIM	 477	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define iEM_TERA2VP82LIM	 BUFFER[1673]	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define idiEM_TERA2VP82LIM	 478	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define iEM_TERA2SS11LIM	 BUFFER[1676]	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define idiEM_TERA2SS11LIM	 479	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define iEM_TERB3SS21LIM	 BUFFER[1679]	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define idiEM_TERB3SS21LIM	 480	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define iEM_TERA0MT01RIM	 BUFFER[1682]	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define idiEM_TERA0MT01RIM	 481	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define iEM_TERB0MT01RIM	 BUFFER[1685]	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define idiEM_TERB0MT01RIM	 482	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define iEM_TERA2SP01RIM	 BUFFER[1688]	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define idiEM_TERA2SP01RIM	 483	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define iEM_TERB2SP01RIM	 BUFFER[1691]	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define idiEM_TERB2SP01RIM	 484	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define iEM_TERB3SP02RIM	 BUFFER[1694]	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define idiEM_TERB3SP02RIM	 485	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define iEM_TERA3SC01RIM	 BUFFER[1697]	//(TERA3SC01RIM) Искажение: Координата штока ИС1
#define idiEM_TERA3SC01RIM	 486	//(TERA3SC01RIM) Искажение: Координата штока ИС1
#define iEM_TERA3VP81LIM	 BUFFER[1700]	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define idiEM_TERA3VP81LIM	 487	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define iEM_TERA2SC01RIM	 BUFFER[1703]	//(TERA2SC01RIM) Искажение: Координата штока РБ1
#define idiEM_TERA2SC01RIM	 488	//(TERA2SC01RIM) Искажение: Координата штока РБ1
#define iEM_TERA2SS33LIM	 BUFFER[1706]	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define idiEM_TERA2SS33LIM	 489	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define iEM_TERA3SS21LIM	 BUFFER[1709]	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define idiEM_TERA3SS21LIM	 490	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define iEM_TERA3SS33LIM	 BUFFER[1712]	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define idiEM_TERA3SS33LIM	 491	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define iEM_TERA3SS31LIM	 BUFFER[1715]	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define idiEM_TERA3SS31LIM	 492	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define iEM_TERB3SS31LIM	 BUFFER[1718]	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define idiEM_TERB3SS31LIM	 493	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define iEM_TERB3SS33LIM	 BUFFER[1721]	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idiEM_TERB3SS33LIM	 494	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define iEM_TERB3SC01RIM	 BUFFER[1724]	//(TERB3SC01RIM) Искажение: Координата штока ИС2
#define idiEM_TERB3SC01RIM	 495	//(TERB3SC01RIM) Искажение: Координата штока ИС2
#define iEM_TERA3SS11LIM	 BUFFER[1727]	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define idiEM_TERA3SS11LIM	 496	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define iEM_TERB3SS11LIM	 BUFFER[1730]	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define idiEM_TERB3SS11LIM	 497	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define iEM_TERR6IS64LIM	 BUFFER[1733]	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define idiEM_TERR6IS64LIM	 498	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define iEM_TERB3SS22LIM	 BUFFER[1736]	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define idiEM_TERB3SS22LIM	 499	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define iEM_TERA3SS22LIM	 BUFFER[1739]	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define idiEM_TERA3SS22LIM	 500	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define iEM_TERA3SP02RIM	 BUFFER[1742]	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define idiEM_TERA3SP02RIM	 501	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define iEM_TERR6IS62LIM	 BUFFER[1745]	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define idiEM_TERR6IS62LIM	 502	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define iEM_TERR6IS66LIM	 BUFFER[1748]	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idiEM_TERR6IS66LIM	 503	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define iEM_TERR6IS67LIM	 BUFFER[1751]	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idiEM_TERR6IS67LIM	 504	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define iEM_TERA0VP81LIM	 BUFFER[1754]	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define idiEM_TERA0VP81LIM	 505	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define iEM_TERB0VP81LIM	 BUFFER[1757]	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define idiEM_TERB0VP81LIM	 506	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define iEM_TERR0VP81LIM	 BUFFER[1760]	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define idiEM_TERR0VP81LIM	 507	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define iEM_TERR6IS68LIM	 BUFFER[1763]	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define idiEM_TERR6IS68LIM	 508	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define iEM_TERR7SI74RIM	 BUFFER[1766]	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define idiEM_TERR7SI74RIM	 509	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define iEM_TERA5SS21LIM	 BUFFER[1769]	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define idiEM_TERA5SS21LIM	 510	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define iEM_TERB5SS11LIM	 BUFFER[1772]	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define idiEM_TERB5SS11LIM	 511	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define iEM_TERA5SS11LIM	 BUFFER[1775]	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define idiEM_TERA5SS11LIM	 512	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define iEM_TERA9SS11LIM	 BUFFER[1778]	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define idiEM_TERA9SS11LIM	 513	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define iEM_TERB2SS11LIM	 BUFFER[1781]	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define idiEM_TERB2SS11LIM	 514	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define iEM_TERB2SS12LIM	 BUFFER[1784]	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define idiEM_TERB2SS12LIM	 515	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define iEM_TERB2SS21LIM	 BUFFER[1787]	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define idiEM_TERB2SS21LIM	 516	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define iEM_TERR3SS11LIM	 BUFFER[1790]	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define idiEM_TERR3SS11LIM	 517	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define iEM_TERB2SC01RIM	 BUFFER[1793]	//(TERB2SC01RIM) Искажение: Координата штока РБ2
#define idiEM_TERB2SC01RIM	 518	//(TERB2SC01RIM) Искажение: Координата штока РБ2
#define iEM_TERR3SS21LIM	 BUFFER[1796]	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define idiEM_TERR3SS21LIM	 519	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define iEM_TERR5SS11LIM	 BUFFER[1799]	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define idiEM_TERR5SS11LIM	 520	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define iEM_TERA4SS11LIM	 BUFFER[1802]	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define idiEM_TERA4SS11LIM	 521	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define iEM_TERR1SS11LIM	 BUFFER[1805]	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define idiEM_TERR1SS11LIM	 522	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define iEM_TERR1SS21LIM	 BUFFER[1808]	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define idiEM_TERR1SS21LIM	 523	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define iEM_TERR2SS11LIM	 BUFFER[1811]	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define idiEM_TERR2SS11LIM	 524	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define iEM_TERR2SS21LIM	 BUFFER[1814]	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define idiEM_TERR2SS21LIM	 525	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define iEM_TERA4VP82LIM	 BUFFER[1817]	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define idiEM_TERA4VP82LIM	 526	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define iEM_TERB4SS21LIM	 BUFFER[1820]	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define idiEM_TERB4SS21LIM	 527	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define iEM_TERR5SS21LIM	 BUFFER[1823]	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define idiEM_TERR5SS21LIM	 528	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define iEM_TERB6SS21LIM	 BUFFER[1826]	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define idiEM_TERB6SS21LIM	 529	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define iEM_TERB4SS11LIM	 BUFFER[1829]	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define idiEM_TERB4SS11LIM	 530	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define iEM_TERA4SS21LIM	 BUFFER[1832]	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define idiEM_TERA4SS21LIM	 531	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define iEM_TERA6MS11LIM	 BUFFER[1835]	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define idiEM_TERA6MS11LIM	 532	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define iEM_TERA6SS21LIM	 BUFFER[1838]	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define idiEM_TERA6SS21LIM	 533	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define iEM_TERB6SS11LIM	 BUFFER[1841]	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define idiEM_TERB6SS11LIM	 534	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define iEM_TERR4SS11LIM	 BUFFER[1844]	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define idiEM_TERR4SS11LIM	 535	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define iEM_TERR4MS21LIM	 BUFFER[1847]	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
#define idiEM_TERR4MS21LIM	 536	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
#define iEM_TERR4SS12LIM	 BUFFER[1850]	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define idiEM_TERR4SS12LIM	 537	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define iEM_TERR4SS22LIM	 BUFFER[1853]	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define idiEM_TERR4SS22LIM	 538	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define iEM_TERR8SS11LIM	 BUFFER[1856]	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define idiEM_TERR8SS11LIM	 539	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define iEM_TERB8SC01RIM	 BUFFER[1859]	//(TERB8SC01RIM) Искажение: Координата АЗ2
#define idiEM_TERB8SC01RIM	 540	//(TERB8SC01RIM) Искажение: Координата АЗ2
#define iEM_TERA8SC01RIM	 BUFFER[1862]	//(TERA8SC01RIM) Искажение: Координата ДС2
#define idiEM_TERA8SC01RIM	 541	//(TERA8SC01RIM) Искажение: Координата ДС2
#define iEM_TERB8SS12LIM	 BUFFER[1865]	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define idiEM_TERB8SS12LIM	 542	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define iEM_TERA8SS12LIM	 BUFFER[1868]	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define idiEM_TERA8SS12LIM	 543	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define iEM_TERB8SS22LIM	 BUFFER[1871]	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define idiEM_TERB8SS22LIM	 544	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define iEM_TERA8SS22LIM	 BUFFER[1874]	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define idiEM_TERA8SS22LIM	 545	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define iEM_TERA9SS21LIM	 BUFFER[1877]	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define idiEM_TERA9SS21LIM	 546	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define iEM_TERB9SS21LIM	 BUFFER[1880]	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define idiEM_TERB9SS21LIM	 547	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define iEM_TERB9SS11LIM	 BUFFER[1883]	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define idiEM_TERB9SS11LIM	 548	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define iEM_TERB5SS21LIM	 BUFFER[1886]	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define idiEM_TERB5SS21LIM	 549	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define iEM_TERA1SS21LIM	 BUFFER[1889]	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define idiEM_TERA1SS21LIM	 550	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define iEM_TERA1SS11LIM	 BUFFER[1892]	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define idiEM_TERA1SS11LIM	 551	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define iEM_TERA1SC01RIM	 BUFFER[1895]	//(TERA1SC01RIM) Искажение: Координата штока ББ1
#define idiEM_TERA1SC01RIM	 552	//(TERA1SC01RIM) Искажение: Координата штока ББ1
#define iEM_TERA1SS12LIM	 BUFFER[1898]	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define idiEM_TERA1SS12LIM	 553	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define iEM_TERB1SS21LIM	 BUFFER[1901]	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define idiEM_TERB1SS21LIM	 554	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define iEM_TERB1SS11LIM	 BUFFER[1904]	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define idiEM_TERB1SS11LIM	 555	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define iEM_TERB1MC01RIM	 BUFFER[1907]	//(TERB1MC01RIM) Искажение: Координата штока ББ2
#define idiEM_TERB1MC01RIM	 556	//(TERB1MC01RIM) Искажение: Координата штока ББ2
#define iEM_TERB1SS12LIM	 BUFFER[1910]	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define idiEM_TERB1SS12LIM	 557	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define iEM_TERTLG	 BUFFER[1913]	//(TERTLG) Неисправности  тележки от ИС
#define idiEM_TERTLG	 558	//(TERTLG) Неисправности  тележки от ИС
#define fEM_R4MC01RC1	 BUFFER[1916]	//(R4MC01RC1) Заданная координата тележки от ИС
#define idfEM_R4MC01RC1	 559	//(R4MC01RC1) Заданная координата тележки от ИС
#define fEM_R4MV01RC1	 BUFFER[1921]	//(R4MV01RC1) Заданная скорость тележки от ИС
#define idfEM_R4MV01RC1	 560	//(R4MV01RC1) Заданная скорость тележки от ИС
#define iEM_TERMAZ2	 BUFFER[1926]	//(TERMAZ2) Неисправности АЗ2 от ИС
#define idiEM_TERMAZ2	 561	//(TERMAZ2) Неисправности АЗ2 от ИС
#define fEM_B8MC01RC1	 BUFFER[1929]	//(B8MC01RC1) Заданная координата АЗ2 от ИС
#define idfEM_B8MC01RC1	 562	//(B8MC01RC1) Заданная координата АЗ2 от ИС
#define fEM_B8MV01RC1	 BUFFER[1934]	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
#define idfEM_B8MV01RC1	 563	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
#define iEM_TERDS2	 BUFFER[1939]	//(TERDS2) Неисправности ДС2 от ИС
#define idiEM_TERDS2	 564	//(TERDS2) Неисправности ДС2 от ИС
#define fEM_A8MC01RC1	 BUFFER[1942]	//(A8MC01RC1) Заданная координата ДС2 от ИС
#define idfEM_A8MC01RC1	 565	//(A8MC01RC1) Заданная координата ДС2 от ИС
#define fEM_A8MV01RC1	 BUFFER[1947]	//(A8MV01RC1) Заданная скорость ДС2 от ИС
#define idfEM_A8MV01RC1	 566	//(A8MV01RC1) Заданная скорость ДС2 от ИС
#define iEM_TERBZ1	 BUFFER[1952]	//(TERBZ1) Неисправности БЗ1
#define idiEM_TERBZ1	 567	//(TERBZ1) Неисправности БЗ1
#define fEM_A6MC01RC1	 BUFFER[1955]	//(A6MC01RC1) Заданная координата БЗ1 от ИС
#define idfEM_A6MC01RC1	 568	//(A6MC01RC1) Заданная координата БЗ1 от ИС
#define fEM_A6MV01RC1	 BUFFER[1960]	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
#define idfEM_A6MV01RC1	 569	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
#define iEM_TERBZ2	 BUFFER[1965]	//(TERBZ2) Неисправности БЗ2
#define idiEM_TERBZ2	 570	//(TERBZ2) Неисправности БЗ2
#define fEM_B6MC01RC1	 BUFFER[1968]	//(B6MC01RC1) Заданная координата БЗ2 от ИС
#define idfEM_B6MC01RC1	 571	//(B6MC01RC1) Заданная координата БЗ2 от ИС
#define fEM_B6MV01RC1	 BUFFER[1973]	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
#define idfEM_B6MV01RC1	 572	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
#define lEM_R3AD10LC1	 BUFFER[1978]	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define idlEM_R3AD10LC1	 573	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define lEM_R3AD20LC1	 BUFFER[1980]	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define idlEM_R3AD20LC1	 574	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define lEM_R6AD10LC1	 BUFFER[1982]	//(R6AD10LC1) Выкатить кран-балку от ИС
#define idlEM_R6AD10LC1	 575	//(R6AD10LC1) Выкатить кран-балку от ИС
#define lEM_R5AD10LC1	 BUFFER[1984]	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define idlEM_R5AD10LC1	 576	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define lEM_R5AD20LC1	 BUFFER[1986]	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define idlEM_R5AD20LC1	 577	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define iEM_TERMDZ2	 BUFFER[1988]	//(TERMDZ2) Неисправности МДЗ2
#define idiEM_TERMDZ2	 578	//(TERMDZ2) Неисправности МДЗ2
#define fEM_R2MC01RC1	 BUFFER[1991]	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
#define idfEM_R2MC01RC1	 579	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
#define fEM_R2MV01RC1	 BUFFER[1996]	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define idfEM_R2MV01RC1	 580	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define iEM_TERMDZ1	 BUFFER[2001]	//(TERMDZ1) Неисправности МДЗ1
#define idiEM_TERMDZ1	 581	//(TERMDZ1) Неисправности МДЗ1
#define fEM_R1MC01RC1	 BUFFER[2004]	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
#define idfEM_R1MC01RC1	 582	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
#define fEM_R1MV01RC1	 BUFFER[2009]	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define idfEM_R1MV01RC1	 583	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define iEM_TERNL1	 BUFFER[2014]	//(TERNL1) Неисправности НЛ1
#define idiEM_TERNL1	 584	//(TERNL1) Неисправности НЛ1
#define fEM_A5MC01RC1	 BUFFER[2017]	//(A5MC01RC1) Заданная координата НЛ1 от ИС
#define idfEM_A5MC01RC1	 585	//(A5MC01RC1) Заданная координата НЛ1 от ИС
#define fEM_A5MV01RC1	 BUFFER[2022]	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
#define idfEM_A5MV01RC1	 586	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
#define iEM_TERNL2	 BUFFER[2027]	//(TERNL2) Неисправности НЛ2
#define idiEM_TERNL2	 587	//(TERNL2) Неисправности НЛ2
#define fEM_B5MC01RC1	 BUFFER[2030]	//(B5MC01RC1) Заданная координата НЛ2 от ИС
#define idfEM_B5MC01RC1	 588	//(B5MC01RC1) Заданная координата НЛ2 от ИС
#define fEM_B5MV01RC1	 BUFFER[2035]	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
#define idfEM_B5MV01RC1	 589	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
#define lEM_R8AD10LC1	 BUFFER[2040]	//(R8AD10LC1) Установить аварийный НИ от ИС
#define idlEM_R8AD10LC1	 590	//(R8AD10LC1) Установить аварийный НИ от ИС
#define fEM_A1UC08RIM	 BUFFER[2042]	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define idfEM_A1UC08RIM	 591	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define fEM_A2UC08RIM	 BUFFER[2047]	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
#define idfEM_A2UC08RIM	 592	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
#define fEM_A3UC08RIM	 BUFFER[2052]	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define idfEM_A3UC08RIM	 593	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define iEM_TERB2SS33LIM	 BUFFER[2057]	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define idiEM_TERB2SS33LIM	 594	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define iEM_TERA1VP81LIM	 BUFFER[2060]	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define idiEM_TERA1VP81LIM	 595	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define iEM_TERB1VP81LIM	 BUFFER[2063]	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define idiEM_TERB1VP81LIM	 596	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define fEM_A0UT03RSP	 BUFFER[2066]	//(A0UT03RSP) Стартовая  температура АЗ1 град
#define idfEM_A0UT03RSP	 597	//(A0UT03RSP) Стартовая  температура АЗ1 град
#define fEM_A0UR01RSP	 BUFFER[2071]	//(A0UR01RSP) Стартовая  реактивность АЗ1
#define idfEM_A0UR01RSP	 598	//(A0UR01RSP) Стартовая  реактивность АЗ1
#define fEM_A0UR02RSP	 BUFFER[2076]	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define idfEM_A0UR02RSP	 599	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define fEM_B0UT03RSP	 BUFFER[2081]	//(B0UT03RSP) Стартовая  температура АЗ2 град
#define idfEM_B0UT03RSP	 600	//(B0UT03RSP) Стартовая  температура АЗ2 град
#define fEM_A1MC01RSP	 BUFFER[2086]	//(A1MC01RSP) Стартовая координата  ББ1
#define idfEM_A1MC01RSP	 601	//(A1MC01RSP) Стартовая координата  ББ1
#define fEM_A1MC02RSP	 BUFFER[2091]	//(A1MC02RSP) Стартовая координата штока ББ1
#define idfEM_A1MC02RSP	 602	//(A1MC02RSP) Стартовая координата штока ББ1
#define fEM_A1MV01RSP	 BUFFER[2096]	//(A1MV01RSP) Стартовая скорость движения  ББ1
#define idfEM_A1MV01RSP	 603	//(A1MV01RSP) Стартовая скорость движения  ББ1
#define fEM_A1MV02RSP	 BUFFER[2101]	//(A1MV02RSP) Стартовая скорость движения  ББ1
#define idfEM_A1MV02RSP	 604	//(A1MV02RSP) Стартовая скорость движения  ББ1
#define fEM_B1MC01RSP	 BUFFER[2106]	//(B1MC01RSP) Стартовая координата  ББ2
#define idfEM_B1MC01RSP	 605	//(B1MC01RSP) Стартовая координата  ББ2
#define fEM_B1MV01RSP	 BUFFER[2111]	//(B1MV01RSP) Стартовая скорость движения  ББ2
#define idfEM_B1MV01RSP	 606	//(B1MV01RSP) Стартовая скорость движения  ББ2
#define fEM_B1MC02RSP	 BUFFER[2116]	//(B1MC02RSP) Стартовая координата штока ББ2
#define idfEM_B1MC02RSP	 607	//(B1MC02RSP) Стартовая координата штока ББ2
#define fEM_B1MV02RSP	 BUFFER[2121]	//(B1MV02RSP) Стартовая скорость движения  ББ2
#define idfEM_B1MV02RSP	 608	//(B1MV02RSP) Стартовая скорость движения  ББ2
#define fEM_A2MC01RC1	 BUFFER[2126]	//(A2MC01RC1) Заданная координата РБ1 от ИС
#define idfEM_A2MC01RC1	 609	//(A2MC01RC1) Заданная координата РБ1 от ИС
#define fEM_A2MV01RC1	 BUFFER[2131]	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define idfEM_A2MV01RC1	 610	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define fEM_A2MC01RSP	 BUFFER[2136]	//(A2MC01RSP) Стартовая координата  РБ1
#define idfEM_A2MC01RSP	 611	//(A2MC01RSP) Стартовая координата  РБ1
#define fEM_A2MV01RSP	 BUFFER[2141]	//(A2MV01RSP) Стартовая скорость движения  РБ1
#define idfEM_A2MV01RSP	 612	//(A2MV01RSP) Стартовая скорость движения  РБ1
#define fEM_A2MC02RSP	 BUFFER[2146]	//(A2MC02RSP) Стартовая координата штока РБ1
#define idfEM_A2MC02RSP	 613	//(A2MC02RSP) Стартовая координата штока РБ1
#define fEM_A2MV02RSP	 BUFFER[2151]	//(A2MV02RSP) Стартовая скорость движения  РБ1
#define idfEM_A2MV02RSP	 614	//(A2MV02RSP) Стартовая скорость движения  РБ1
#define fEM_B2MC01RSP	 BUFFER[2156]	//(B2MC01RSP) Стартовая координата  РБ2
#define idfEM_B2MC01RSP	 615	//(B2MC01RSP) Стартовая координата  РБ2
#define fEM_B2MV01RSP	 BUFFER[2161]	//(B2MV01RSP) Стартовая скорость движения  РБ2
#define idfEM_B2MV01RSP	 616	//(B2MV01RSP) Стартовая скорость движения  РБ2
#define fEM_B2MC02RSP	 BUFFER[2166]	//(B2MC02RSP) Стартовая координата штока РБ2
#define idfEM_B2MC02RSP	 617	//(B2MC02RSP) Стартовая координата штока РБ2
#define fEM_B2MV02RSP	 BUFFER[2171]	//(B2MV02RSP) Стартовая скорость движения  РБ2
#define idfEM_B2MV02RSP	 618	//(B2MV02RSP) Стартовая скорость движения  РБ2
#define fEM_A3MC01RSP	 BUFFER[2176]	//(A3MC01RSP) Стартовая координата  ИС1
#define idfEM_A3MC01RSP	 619	//(A3MC01RSP) Стартовая координата  ИС1
#define fEM_A3MV01RSP	 BUFFER[2181]	//(A3MV01RSP) Стартовая скорость движения  ИС1
#define idfEM_A3MV01RSP	 620	//(A3MV01RSP) Стартовая скорость движения  ИС1
#define fEM_A3MC02RSP	 BUFFER[2186]	//(A3MC02RSP) Стартовая координата штока ИС1
#define idfEM_A3MC02RSP	 621	//(A3MC02RSP) Стартовая координата штока ИС1
#define fEM_A3MV02RSP	 BUFFER[2191]	//(A3MV02RSP) Стартовая скорость движения  ИС1
#define idfEM_A3MV02RSP	 622	//(A3MV02RSP) Стартовая скорость движения  ИС1
#define fEM_B3MC01RSP	 BUFFER[2196]	//(B3MC01RSP) Стартовая координата  ИС2
#define idfEM_B3MC01RSP	 623	//(B3MC01RSP) Стартовая координата  ИС2
#define fEM_B3MV01RSP	 BUFFER[2201]	//(B3MV01RSP) Стартовая скорость движения  ИС2
#define idfEM_B3MV01RSP	 624	//(B3MV01RSP) Стартовая скорость движения  ИС2
#define fEM_B3MC02RSP	 BUFFER[2206]	//(B3MC02RSP) Стартовая координата штока ИС2
#define idfEM_B3MC02RSP	 625	//(B3MC02RSP) Стартовая координата штока ИС2
#define fEM_B3MV02RSP	 BUFFER[2211]	//(B3MV02RSP) Стартовая скорость движения  ИС2
#define idfEM_B3MV02RSP	 626	//(B3MV02RSP) Стартовая скорость движения  ИС2
#define fEM_B8MC01RSP	 BUFFER[2216]	//(B8MC01RSP) Стартовая координата АЗ2
#define idfEM_B8MC01RSP	 627	//(B8MC01RSP) Стартовая координата АЗ2
#define fEM_B8MV01RSP	 BUFFER[2221]	//(B8MV01RSP) Стартовая скорость АЗ2
#define idfEM_B8MV01RSP	 628	//(B8MV01RSP) Стартовая скорость АЗ2
#define fEM_A8MC01RSP	 BUFFER[2226]	//(A8MC01RSP) Стартовая координата ДС2
#define idfEM_A8MC01RSP	 629	//(A8MC01RSP) Стартовая координата ДС2
#define fEM_A8MV01RSP	 BUFFER[2231]	//(A8MV01RSP) Стартовая скорость ДС2
#define idfEM_A8MV01RSP	 630	//(A8MV01RSP) Стартовая скорость ДС2
#define fEM_A6MC01RSP	 BUFFER[2236]	//(A6MC01RSP) Стартовая координата БЗ1
#define idfEM_A6MC01RSP	 631	//(A6MC01RSP) Стартовая координата БЗ1
#define fEM_A6MV01RSP	 BUFFER[2241]	//(A6MV01RSP) Стартовая скорость БЗ1
#define idfEM_A6MV01RSP	 632	//(A6MV01RSP) Стартовая скорость БЗ1
#define fEM_B6MC01RSP	 BUFFER[2246]	//(B6MC01RSP) Стартовая координата БЗ2
#define idfEM_B6MC01RSP	 633	//(B6MC01RSP) Стартовая координата БЗ2
#define fEM_B6MV01RSP	 BUFFER[2251]	//(B6MV01RSP) Стартовая скорость БЗ2
#define idfEM_B6MV01RSP	 634	//(B6MV01RSP) Стартовая скорость БЗ2
#define fEM_R3UC01RSP	 BUFFER[2256]	//(R3UC01RSP) Стартовая координата Гомогенных дверей
#define idfEM_R3UC01RSP	 635	//(R3UC01RSP) Стартовая координата Гомогенных дверей
#define fEM_R3UV01RSP	 BUFFER[2261]	//(R3UV01RSP) Стартовая скорость Гомогенных дверей
#define idfEM_R3UV01RSP	 636	//(R3UV01RSP) Стартовая скорость Гомогенных дверей
#define fEM_R5UC01RSP	 BUFFER[2266]	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define idfEM_R5UC01RSP	 637	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define fEM_R5UV01RSP	 BUFFER[2271]	//(R5UV01RSP) Стартовая скорость Ворот отстойной зоны
#define idfEM_R5UV01RSP	 638	//(R5UV01RSP) Стартовая скорость Ворот отстойной зоны
#define fEM_R6UC01RSP	 BUFFER[2276]	//(R6UC01RSP) Стартовая координата Кран-балки
#define idfEM_R6UC01RSP	 639	//(R6UC01RSP) Стартовая координата Кран-балки
#define fEM_R6UV01RSP	 BUFFER[2281]	//(R6UV01RSP) Стартовая скорость Кран-балки
#define idfEM_R6UV01RSP	 640	//(R6UV01RSP) Стартовая скорость Кран-балки
#define fEM_R2MC01RSP	 BUFFER[2286]	//(R2MC01RSP) Стартовая координата МДЗ2
#define idfEM_R2MC01RSP	 641	//(R2MC01RSP) Стартовая координата МДЗ2
#define fEM_R2MV01RSP	 BUFFER[2291]	//(R2MV01RSP) Стартовая скорость МДЗ2
#define idfEM_R2MV01RSP	 642	//(R2MV01RSP) Стартовая скорость МДЗ2
#define fEM_R1MC01RSP	 BUFFER[2296]	//(R1MC01RSP) Стартовая координата МДЗ1
#define idfEM_R1MC01RSP	 643	//(R1MC01RSP) Стартовая координата МДЗ1
#define fEM_R1MV01RSP	 BUFFER[2301]	//(R1MV01RSP) Стартовая скорость МДЗ1
#define idfEM_R1MV01RSP	 644	//(R1MV01RSP) Стартовая скорость МДЗ1
#define fEM_A5MC01RSP	 BUFFER[2306]	//(A5MC01RSP) Стартовая координата НЛ1
#define idfEM_A5MC01RSP	 645	//(A5MC01RSP) Стартовая координата НЛ1
#define fEM_A5MV01RSP	 BUFFER[2311]	//(A5MV01RSP) Стартовая скорость НЛ1
#define idfEM_A5MV01RSP	 646	//(A5MV01RSP) Стартовая скорость НЛ1
#define fEM_B5MC01RSP	 BUFFER[2316]	//(B5MC01RSP) Стартовая координата НЛ2
#define idfEM_B5MC01RSP	 647	//(B5MC01RSP) Стартовая координата НЛ2
#define fEM_B5MV01RSP	 BUFFER[2321]	//(B5MV01RSP) Стартовая скорость НЛ2
#define idfEM_B5MV01RSP	 648	//(B5MV01RSP) Стартовая скорость НЛ2
#define fEM_A9MC01RSP	 BUFFER[2326]	//(A9MC01RSP) Стартовая координата НИ ДС1
#define idfEM_A9MC01RSP	 649	//(A9MC01RSP) Стартовая координата НИ ДС1
#define fEM_A9MV01RSP	 BUFFER[2331]	//(A9MV01RSP) Стартовая скорость НИ ДС1
#define idfEM_A9MV01RSP	 650	//(A9MV01RSP) Стартовая скорость НИ ДС1
#define fEM_B9MC01RSP	 BUFFER[2336]	//(B9MC01RSP) Стартовая координата НИ ДС2
#define idfEM_B9MC01RSP	 651	//(B9MC01RSP) Стартовая координата НИ ДС2
#define fEM_B9MV01RSP	 BUFFER[2341]	//(B9MV01RSP) Стартовая скорость НИ ДС2
#define idfEM_B9MV01RSP	 652	//(B9MV01RSP) Стартовая скорость НИ ДС2
#define fEM_A4MC01RSP	 BUFFER[2346]	//(A4MC01RSP) Стартовая координата НИ1
#define idfEM_A4MC01RSP	 653	//(A4MC01RSP) Стартовая координата НИ1
#define fEM_A4MV01RSP	 BUFFER[2351]	//(A4MV01RSP) Стартовая скорость НИ1
#define idfEM_A4MV01RSP	 654	//(A4MV01RSP) Стартовая скорость НИ1
#define fEM_B4MC01RSP	 BUFFER[2356]	//(B4MC01RSP) Стартовая координата НИ2
#define idfEM_B4MC01RSP	 655	//(B4MC01RSP) Стартовая координата НИ2
#define fEM_B4MV01RSP	 BUFFER[2361]	//(B4MV01RSP) Стартовая скорость НИ2
#define idfEM_B4MV01RSP	 656	//(B4MV01RSP) Стартовая скорость НИ2
#define fEM_R4MC01RSP	 BUFFER[2366]	//(R4MC01RSP) Стартовая координата тележки
#define idfEM_R4MC01RSP	 657	//(R4MC01RSP) Стартовая координата тележки
#define fEM_R4MV01RSP	 BUFFER[2371]	//(R4MV01RSP) Стартовая скорость тележки
#define idfEM_R4MV01RSP	 658	//(R4MV01RSP) Стартовая скорость тележки
#define fEM_A1MV01RC1	 BUFFER[2376]	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define idfEM_A1MV01RC1	 659	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define iEM_TERB7MS31LIM	 BUFFER[2381]	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define idiEM_TERB7MS31LIM	 660	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define iEM_TERA7MS31LIM	 BUFFER[2384]	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define idiEM_TERA7MS31LIM	 661	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define fEM_R7UY00RSS	 BUFFER[2387]	//(R7UY00RSS) Y-координата АЗ1 см
#define idfEM_R7UY00RSS	 662	//(R7UY00RSS) Y-координата АЗ1 см
#define iEM_TERA6VS12LIM	 BUFFER[2392]	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define idiEM_TERA6VS12LIM	 663	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define iEM_TERA6VS22LIM	 BUFFER[2395]	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define idiEM_TERA6VS22LIM	 664	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define iEM_TERB6VS12LIM	 BUFFER[2398]	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define idiEM_TERB6VS12LIM	 665	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define iEM_TERB6VS22LIM	 BUFFER[2401]	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define idiEM_TERB6VS22LIM	 666	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define iEM_TERA5VS22LIM	 BUFFER[2404]	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define idiEM_TERA5VS22LIM	 667	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define iEM_TERA5VS12LIM	 BUFFER[2407]	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define idiEM_TERA5VS12LIM	 668	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define iEM_TERB5VS12LIM	 BUFFER[2410]	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define idiEM_TERB5VS12LIM	 669	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define iEM_TERB5VS22LIM	 BUFFER[2413]	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define idiEM_TERB5VS22LIM	 670	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define iEM_TERR1VS12LIM	 BUFFER[2416]	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define idiEM_TERR1VS12LIM	 671	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define iEM_TERR1VS22LIM	 BUFFER[2419]	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define idiEM_TERR1VS22LIM	 672	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define iEM_TERR2VS12LIM	 BUFFER[2422]	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define idiEM_TERR2VS12LIM	 673	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define iEM_TERR2VS22LIM	 BUFFER[2425]	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define idiEM_TERR2VS22LIM	 674	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define iEM_TERR4VS12LDU	 BUFFER[2428]	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS12LDU	 675	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define iEM_TERR4VS22LDU	 BUFFER[2431]	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS22LDU	 676	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define fEM_R4UC23RIM	 BUFFER[2434]	//(R4UC23RIM) Y-координата АЗ1
#define idfEM_R4UC23RIM	 677	//(R4UC23RIM) Y-координата АЗ1
#define fEM_A0UX13RSS	 BUFFER[2439]	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define idfEM_A0UX13RSS	 678	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define fEM_A0UX14RSS	 BUFFER[2444]	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define idfEM_A0UX14RSS	 679	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define fEM_A0UX15RSS	 BUFFER[2449]	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define idfEM_A0UX15RSS	 680	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define fEM_R7UX13RSS	 BUFFER[2454]	//(R7UX13RSS) X-координата камеры R7IN51
#define idfEM_R7UX13RSS	 681	//(R7UX13RSS) X-координата камеры R7IN51
#define fEM_R7UX14RSS	 BUFFER[2459]	//(R7UX14RSS) X-координата камеры R7IN52
#define idfEM_R7UX14RSS	 682	//(R7UX14RSS) X-координата камеры R7IN52
#define fEM_R7UX15RSS	 BUFFER[2464]	//(R7UX15RSS) X-координата камеры R7IN53
#define idfEM_R7UX15RSS	 683	//(R7UX15RSS) X-координата камеры R7IN53
#define fEM_R7UY13RSS	 BUFFER[2469]	//(R7UY13RSS) Y-координата камеры R7IN51
#define idfEM_R7UY13RSS	 684	//(R7UY13RSS) Y-координата камеры R7IN51
#define fEM_R7UY14RSS	 BUFFER[2474]	//(R7UY14RSS) Y-координата камеры R7IN52
#define idfEM_R7UY14RSS	 685	//(R7UY14RSS) Y-координата камеры R7IN52
#define fEM_R7UY15RSS	 BUFFER[2479]	//(R7UY15RSS) Y-координата камеры R7IN53
#define idfEM_R7UY15RSS	 686	//(R7UY15RSS) Y-координата камеры R7IN53
#define fEM_R7UX16RSS	 BUFFER[2484]	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
#define idfEM_R7UX16RSS	 687	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
#define bFirstEnterFlag	 BUFFER[2489]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 688	//(bFirstEnterFlag) 
#define internal1_m897_Chim0	 BUFFER[2491]	//(internal1_m897_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m897_Chim0	 689	//(internal1_m897_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m887_Chim0	 BUFFER[2496]	//(internal1_m887_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m887_Chim0	 690	//(internal1_m887_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m879_Chim0	 BUFFER[2501]	//(internal1_m879_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m879_Chim0	 691	//(internal1_m879_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m834_Out10	 BUFFER[2506]	//(internal1_m834_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m834_Out10	 692	//(internal1_m834_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m833_Out10	 BUFFER[2508]	//(internal1_m833_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m833_Out10	 693	//(internal1_m833_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1017_Out10	 BUFFER[2510]	//(internal1_m1017_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1017_Out10	 694	//(internal1_m1017_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1016_Out10	 BUFFER[2512]	//(internal1_m1016_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1016_Out10	 695	//(internal1_m1016_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1015_Out10	 BUFFER[2514]	//(internal1_m1015_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1015_Out10	 696	//(internal1_m1015_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1014_Out10	 BUFFER[2516]	//(internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1014_Out10	 697	//(internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m693_Out10	 BUFFER[2518]	//(internal1_m693_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m693_Out10	 698	//(internal1_m693_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m692_Out10	 BUFFER[2520]	//(internal1_m692_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m692_Out10	 699	//(internal1_m692_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m671_Out10	 BUFFER[2522]	//(internal1_m671_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m671_Out10	 700	//(internal1_m671_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m670_Out10	 BUFFER[2524]	//(internal1_m670_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m670_Out10	 701	//(internal1_m670_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m691_Out10	 BUFFER[2526]	//(internal1_m691_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m691_Out10	 702	//(internal1_m691_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m690_Out10	 BUFFER[2528]	//(internal1_m690_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m690_Out10	 703	//(internal1_m690_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m669_Out10	 BUFFER[2530]	//(internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m669_Out10	 704	//(internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m668_Out10	 BUFFER[2532]	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m668_Out10	 705	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m529_Out10	 BUFFER[2534]	//(internal1_m529_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m529_Out10	 706	//(internal1_m529_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m545_Out10	 BUFFER[2536]	//(internal1_m545_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m545_Out10	 707	//(internal1_m545_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m411_Out10	 BUFFER[2538]	//(internal1_m411_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m411_Out10	 708	//(internal1_m411_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m488_q0	 BUFFER[2540]	//(internal1_m488_q0) q0 - внутренний параметр
#define idinternal1_m488_q0	 709	//(internal1_m488_q0) q0 - внутренний параметр
#define internal1_m489_q0	 BUFFER[2542]	//(internal1_m489_q0) q0 - внутренний параметр
#define idinternal1_m489_q0	 710	//(internal1_m489_q0) q0 - внутренний параметр
#define internal1_m474_q0	 BUFFER[2544]	//(internal1_m474_q0) q0 - внутренний параметр
#define idinternal1_m474_q0	 711	//(internal1_m474_q0) q0 - внутренний параметр
#define internal1_m475_q0	 BUFFER[2546]	//(internal1_m475_q0) q0 - внутренний параметр
#define idinternal1_m475_q0	 712	//(internal1_m475_q0) q0 - внутренний параметр
#define internal1_m644_tx	 BUFFER[2548]	//(internal1_m644_tx) tx - время накопленное сек
#define idinternal1_m644_tx	 713	//(internal1_m644_tx) tx - время накопленное сек
#define internal1_m644_y0	 BUFFER[2553]	//(internal1_m644_y0) y0
#define idinternal1_m644_y0	 714	//(internal1_m644_y0) y0
#define internal1_m632_tx	 BUFFER[2554]	//(internal1_m632_tx) tx - время накопленное сек
#define idinternal1_m632_tx	 715	//(internal1_m632_tx) tx - время накопленное сек
#define internal1_m632_y0	 BUFFER[2559]	//(internal1_m632_y0) y0
#define idinternal1_m632_y0	 716	//(internal1_m632_y0) y0
#define internal1_m618_tx	 BUFFER[2560]	//(internal1_m618_tx) tx - время накопленное сек
#define idinternal1_m618_tx	 717	//(internal1_m618_tx) tx - время накопленное сек
#define internal1_m618_y0	 BUFFER[2565]	//(internal1_m618_y0) y0
#define idinternal1_m618_y0	 718	//(internal1_m618_y0) y0
#define internal1_m616_tx	 BUFFER[2566]	//(internal1_m616_tx) tx - время накопленное сек
#define idinternal1_m616_tx	 719	//(internal1_m616_tx) tx - время накопленное сек
#define internal1_m616_y0	 BUFFER[2571]	//(internal1_m616_y0) y0
#define idinternal1_m616_y0	 720	//(internal1_m616_y0) y0
#define internal1_m208_Out10	 BUFFER[2572]	//(internal1_m208_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m208_Out10	 721	//(internal1_m208_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m226_Out10	 BUFFER[2574]	//(internal1_m226_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m226_Out10	 722	//(internal1_m226_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m41_Out10	 BUFFER[2576]	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m41_Out10	 723	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m56_Out10	 BUFFER[2578]	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m56_Out10	 724	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m988_Out10	 BUFFER[2580]	//(internal1_m988_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m988_Out10	 725	//(internal1_m988_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m985_Out10	 BUFFER[2582]	//(internal1_m985_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m985_Out10	 726	//(internal1_m985_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m984_Out10	 BUFFER[2584]	//(internal1_m984_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m984_Out10	 727	//(internal1_m984_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m987_Xtek0	 BUFFER[2586]	//(internal1_m987_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m987_Xtek0	 728	//(internal1_m987_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m970_Xtek0	 BUFFER[2591]	//(internal1_m970_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m970_Xtek0	 729	//(internal1_m970_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m971_Out10	 BUFFER[2596]	//(internal1_m971_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m971_Out10	 730	//(internal1_m971_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m968_Out10	 BUFFER[2598]	//(internal1_m968_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m968_Out10	 731	//(internal1_m968_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m967_Out10	 BUFFER[2600]	//(internal1_m967_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m967_Out10	 732	//(internal1_m967_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1055_Out10	 BUFFER[2602]	//(internal1_m1055_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1055_Out10	 733	//(internal1_m1055_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1036_Out10	 BUFFER[2604]	//(internal1_m1036_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1036_Out10	 734	//(internal1_m1036_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1035_Out10	 BUFFER[2606]	//(internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1035_Out10	 735	//(internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1034_Out10	 BUFFER[2608]	//(internal1_m1034_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1034_Out10	 736	//(internal1_m1034_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m855_Out10	 BUFFER[2610]	//(internal1_m855_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m855_Out10	 737	//(internal1_m855_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m857_Out10	 BUFFER[2612]	//(internal1_m857_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m857_Out10	 738	//(internal1_m857_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m854_Out10	 BUFFER[2614]	//(internal1_m854_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m854_Out10	 739	//(internal1_m854_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m856_Out10	 BUFFER[2616]	//(internal1_m856_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m856_Out10	 740	//(internal1_m856_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m830_Out10	 BUFFER[2618]	//(internal1_m830_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m830_Out10	 741	//(internal1_m830_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m831_Out10	 BUFFER[2620]	//(internal1_m831_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m831_Out10	 742	//(internal1_m831_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m829_Out10	 BUFFER[2622]	//(internal1_m829_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m829_Out10	 743	//(internal1_m829_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m828_Out10	 BUFFER[2624]	//(internal1_m828_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m828_Out10	 744	//(internal1_m828_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1050_Out10	 BUFFER[2626]	//(internal1_m1050_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1050_Out10	 745	//(internal1_m1050_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1002_Out10	 BUFFER[2628]	//(internal1_m1002_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1002_Out10	 746	//(internal1_m1002_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1001_Out10	 BUFFER[2630]	//(internal1_m1001_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1001_Out10	 747	//(internal1_m1001_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1000_Out10	 BUFFER[2632]	//(internal1_m1000_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1000_Out10	 748	//(internal1_m1000_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m999_Out10	 BUFFER[2634]	//(internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m999_Out10	 749	//(internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1051_Out10	 BUFFER[2636]	//(internal1_m1051_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1051_Out10	 750	//(internal1_m1051_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1032_Out10	 BUFFER[2638]	//(internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1032_Out10	 751	//(internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m832_Out10	 BUFFER[2640]	//(internal1_m832_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m832_Out10	 752	//(internal1_m832_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1033_Out10	 BUFFER[2642]	//(internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1033_Out10	 753	//(internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1031_Out10	 BUFFER[2644]	//(internal1_m1031_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1031_Out10	 754	//(internal1_m1031_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1052_Out10	 BUFFER[2646]	//(internal1_m1052_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1052_Out10	 755	//(internal1_m1052_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1030_Out10	 BUFFER[2648]	//(internal1_m1030_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1030_Out10	 756	//(internal1_m1030_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1013_Out10	 BUFFER[2650]	//(internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1013_Out10	 757	//(internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m998_Out10	 BUFFER[2652]	//(internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m998_Out10	 758	//(internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m546_Out10	 BUFFER[2654]	//(internal1_m546_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m546_Out10	 759	//(internal1_m546_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m421_Xtek0	 BUFFER[2656]	//(internal1_m421_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m421_Xtek0	 760	//(internal1_m421_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m412_Out10	 BUFFER[2661]	//(internal1_m412_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m412_Out10	 761	//(internal1_m412_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m414_Out10	 BUFFER[2663]	//(internal1_m414_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m414_Out10	 762	//(internal1_m414_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m413_Out10	 BUFFER[2665]	//(internal1_m413_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m413_Out10	 763	//(internal1_m413_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m870_Out10	 BUFFER[2667]	//(internal1_m870_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m870_Out10	 764	//(internal1_m870_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m871_Out10	 BUFFER[2669]	//(internal1_m871_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m871_Out10	 765	//(internal1_m871_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m869_Out10	 BUFFER[2671]	//(internal1_m869_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m869_Out10	 766	//(internal1_m869_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1054_Out10	 BUFFER[2673]	//(internal1_m1054_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1054_Out10	 767	//(internal1_m1054_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m706_Out10	 BUFFER[2675]	//(internal1_m706_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m706_Out10	 768	//(internal1_m706_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m707_Out10	 BUFFER[2677]	//(internal1_m707_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m707_Out10	 769	//(internal1_m707_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m704_Out10	 BUFFER[2679]	//(internal1_m704_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m704_Out10	 770	//(internal1_m704_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m705_Out10	 BUFFER[2681]	//(internal1_m705_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m705_Out10	 771	//(internal1_m705_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m562_Out10	 BUFFER[2683]	//(internal1_m562_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m562_Out10	 772	//(internal1_m562_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m561_Out10	 BUFFER[2685]	//(internal1_m561_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m561_Out10	 773	//(internal1_m561_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m851_Xtek0	 BUFFER[2687]	//(internal1_m851_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m851_Xtek0	 774	//(internal1_m851_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m853_Xtek0	 BUFFER[2692]	//(internal1_m853_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m853_Xtek0	 775	//(internal1_m853_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m703_Out10	 BUFFER[2697]	//(internal1_m703_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m703_Out10	 776	//(internal1_m703_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m687_Out10	 BUFFER[2699]	//(internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m687_Out10	 777	//(internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m667_Out10	 BUFFER[2701]	//(internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m667_Out10	 778	//(internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m686_Out10	 BUFFER[2703]	//(internal1_m686_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m686_Out10	 779	//(internal1_m686_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m666_Out10	 BUFFER[2705]	//(internal1_m666_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m666_Out10	 780	//(internal1_m666_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m339_Out10	 BUFFER[2707]	//(internal1_m339_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m339_Out10	 781	//(internal1_m339_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m338_Out10	 BUFFER[2709]	//(internal1_m338_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m338_Out10	 782	//(internal1_m338_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m323_Out10	 BUFFER[2711]	//(internal1_m323_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m323_Out10	 783	//(internal1_m323_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m322_Out10	 BUFFER[2713]	//(internal1_m322_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m322_Out10	 784	//(internal1_m322_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m563_Out10	 BUFFER[2715]	//(internal1_m563_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m563_Out10	 785	//(internal1_m563_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m352_Out10	 BUFFER[2717]	//(internal1_m352_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m352_Out10	 786	//(internal1_m352_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m336_Xtek0	 BUFFER[2719]	//(internal1_m336_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m336_Xtek0	 787	//(internal1_m336_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m351_Out10	 BUFFER[2724]	//(internal1_m351_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m351_Out10	 788	//(internal1_m351_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m349_Out10	 BUFFER[2726]	//(internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m349_Out10	 789	//(internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m329_Xtek0	 BUFFER[2728]	//(internal1_m329_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m329_Xtek0	 790	//(internal1_m329_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m350_Out10	 BUFFER[2733]	//(internal1_m350_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m350_Out10	 791	//(internal1_m350_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m321_Out10	 BUFFER[2735]	//(internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m321_Out10	 792	//(internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m337_Out10	 BUFFER[2737]	//(internal1_m337_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m337_Out10	 793	//(internal1_m337_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m433_Out10	 BUFFER[2739]	//(internal1_m433_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m433_Out10	 794	//(internal1_m433_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m434_Xtek0	 BUFFER[2741]	//(internal1_m434_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m434_Xtek0	 795	//(internal1_m434_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m432_Out10	 BUFFER[2746]	//(internal1_m432_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m432_Out10	 796	//(internal1_m432_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m431_Out10	 BUFFER[2748]	//(internal1_m431_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m431_Out10	 797	//(internal1_m431_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m430_Out10	 BUFFER[2750]	//(internal1_m430_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m430_Out10	 798	//(internal1_m430_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1053_Out10	 BUFFER[2752]	//(internal1_m1053_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1053_Out10	 799	//(internal1_m1053_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m150_Out10	 BUFFER[2754]	//(internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m150_Out10	 800	//(internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m149_Out10	 BUFFER[2756]	//(internal1_m149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m149_Out10	 801	//(internal1_m149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m197_tx	 BUFFER[2758]	//(internal1_m197_tx) tx - внутренний параметр
#define idinternal1_m197_tx	 802	//(internal1_m197_tx) tx - внутренний параметр
#define internal1_m25_tx	 BUFFER[2761]	//(internal1_m25_tx) tx - внутренний параметр
#define idinternal1_m25_tx	 803	//(internal1_m25_tx) tx - внутренний параметр
#define internal1_m480_Pav0	 BUFFER[2764]	//(internal1_m480_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m480_Pav0	 804	//(internal1_m480_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m480_Zav0	 BUFFER[2766]	//(internal1_m480_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m480_Zav0	 805	//(internal1_m480_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m480_Pv0	 BUFFER[2768]	//(internal1_m480_Pv0)  - Пер. выключатель механизма
#define idinternal1_m480_Pv0	 806	//(internal1_m480_Pv0)  - Пер. выключатель механизма
#define internal1_m480_Zv0	 BUFFER[2770]	//(internal1_m480_Zv0)  - Зад. выключатель механизма
#define idinternal1_m480_Zv0	 807	//(internal1_m480_Zv0)  - Зад. выключатель механизма
#define internal1_m480_RA00	 BUFFER[2772]	//(internal1_m480_RA00)  - последнее задание вперед
#define idinternal1_m480_RA00	 808	//(internal1_m480_RA00)  - последнее задание вперед
#define internal1_m480_RA10	 BUFFER[2774]	//(internal1_m480_RA10)  - последнее задание назад
#define idinternal1_m480_RA10	 809	//(internal1_m480_RA10)  - последнее задание назад
#define internal1_m480_MyFirstEnterFlag	 BUFFER[2776]	//(internal1_m480_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m480_MyFirstEnterFlag	 810	//(internal1_m480_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m492_Pav0	 BUFFER[2778]	//(internal1_m492_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m492_Pav0	 811	//(internal1_m492_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m492_Zav0	 BUFFER[2780]	//(internal1_m492_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m492_Zav0	 812	//(internal1_m492_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m492_Pv0	 BUFFER[2782]	//(internal1_m492_Pv0)  - Пер. выключатель механизма
#define idinternal1_m492_Pv0	 813	//(internal1_m492_Pv0)  - Пер. выключатель механизма
#define internal1_m492_Zv0	 BUFFER[2784]	//(internal1_m492_Zv0)  - Зад. выключатель механизма
#define idinternal1_m492_Zv0	 814	//(internal1_m492_Zv0)  - Зад. выключатель механизма
#define internal1_m492_RA00	 BUFFER[2786]	//(internal1_m492_RA00)  - последнее задание вперед
#define idinternal1_m492_RA00	 815	//(internal1_m492_RA00)  - последнее задание вперед
#define internal1_m492_RA10	 BUFFER[2788]	//(internal1_m492_RA10)  - последнее задание назад
#define idinternal1_m492_RA10	 816	//(internal1_m492_RA10)  - последнее задание назад
#define internal1_m492_MyFirstEnterFlag	 BUFFER[2790]	//(internal1_m492_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m492_MyFirstEnterFlag	 817	//(internal1_m492_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m479_Pav0	 BUFFER[2792]	//(internal1_m479_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m479_Pav0	 818	//(internal1_m479_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m479_Zav0	 BUFFER[2794]	//(internal1_m479_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m479_Zav0	 819	//(internal1_m479_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m479_Pv0	 BUFFER[2796]	//(internal1_m479_Pv0)  - Пер. выключатель механизма
#define idinternal1_m479_Pv0	 820	//(internal1_m479_Pv0)  - Пер. выключатель механизма
#define internal1_m479_Zv0	 BUFFER[2798]	//(internal1_m479_Zv0)  - Зад. выключатель механизма
#define idinternal1_m479_Zv0	 821	//(internal1_m479_Zv0)  - Зад. выключатель механизма
#define internal1_m479_RA00	 BUFFER[2800]	//(internal1_m479_RA00)  - последнее задание вперед
#define idinternal1_m479_RA00	 822	//(internal1_m479_RA00)  - последнее задание вперед
#define internal1_m479_RA10	 BUFFER[2802]	//(internal1_m479_RA10)  - последнее задание назад
#define idinternal1_m479_RA10	 823	//(internal1_m479_RA10)  - последнее задание назад
#define internal1_m479_MyFirstEnterFlag	 BUFFER[2804]	//(internal1_m479_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m479_MyFirstEnterFlag	 824	//(internal1_m479_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m623_Pav0	 BUFFER[2806]	//(internal1_m623_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m623_Pav0	 825	//(internal1_m623_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m623_Zav0	 BUFFER[2808]	//(internal1_m623_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m623_Zav0	 826	//(internal1_m623_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m623_Pv0	 BUFFER[2810]	//(internal1_m623_Pv0)  - Пер. выключатель механизма
#define idinternal1_m623_Pv0	 827	//(internal1_m623_Pv0)  - Пер. выключатель механизма
#define internal1_m623_Zv0	 BUFFER[2812]	//(internal1_m623_Zv0)  - Зад. выключатель механизма
#define idinternal1_m623_Zv0	 828	//(internal1_m623_Zv0)  - Зад. выключатель механизма
#define internal1_m623_RA00	 BUFFER[2814]	//(internal1_m623_RA00)  - последнее задание вперед
#define idinternal1_m623_RA00	 829	//(internal1_m623_RA00)  - последнее задание вперед
#define internal1_m623_RA10	 BUFFER[2816]	//(internal1_m623_RA10)  - последнее задание назад
#define idinternal1_m623_RA10	 830	//(internal1_m623_RA10)  - последнее задание назад
#define internal1_m623_MyFirstEnterFlag	 BUFFER[2818]	//(internal1_m623_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m623_MyFirstEnterFlag	 831	//(internal1_m623_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m620_Pav0	 BUFFER[2820]	//(internal1_m620_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m620_Pav0	 832	//(internal1_m620_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m620_Zav0	 BUFFER[2822]	//(internal1_m620_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m620_Zav0	 833	//(internal1_m620_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m620_Pv0	 BUFFER[2824]	//(internal1_m620_Pv0)  - Пер. выключатель механизма
#define idinternal1_m620_Pv0	 834	//(internal1_m620_Pv0)  - Пер. выключатель механизма
#define internal1_m620_Zv0	 BUFFER[2826]	//(internal1_m620_Zv0)  - Зад. выключатель механизма
#define idinternal1_m620_Zv0	 835	//(internal1_m620_Zv0)  - Зад. выключатель механизма
#define internal1_m620_RA00	 BUFFER[2828]	//(internal1_m620_RA00)  - последнее задание вперед
#define idinternal1_m620_RA00	 836	//(internal1_m620_RA00)  - последнее задание вперед
#define internal1_m620_RA10	 BUFFER[2830]	//(internal1_m620_RA10)  - последнее задание назад
#define idinternal1_m620_RA10	 837	//(internal1_m620_RA10)  - последнее задание назад
#define internal1_m620_MyFirstEnterFlag	 BUFFER[2832]	//(internal1_m620_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m620_MyFirstEnterFlag	 838	//(internal1_m620_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m606_Pav0	 BUFFER[2834]	//(internal1_m606_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m606_Pav0	 839	//(internal1_m606_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m606_Zav0	 BUFFER[2836]	//(internal1_m606_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m606_Zav0	 840	//(internal1_m606_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m606_Pv0	 BUFFER[2838]	//(internal1_m606_Pv0)  - Пер. выключатель механизма
#define idinternal1_m606_Pv0	 841	//(internal1_m606_Pv0)  - Пер. выключатель механизма
#define internal1_m606_Zv0	 BUFFER[2840]	//(internal1_m606_Zv0)  - Зад. выключатель механизма
#define idinternal1_m606_Zv0	 842	//(internal1_m606_Zv0)  - Зад. выключатель механизма
#define internal1_m606_RA00	 BUFFER[2842]	//(internal1_m606_RA00)  - последнее задание вперед
#define idinternal1_m606_RA00	 843	//(internal1_m606_RA00)  - последнее задание вперед
#define internal1_m606_RA10	 BUFFER[2844]	//(internal1_m606_RA10)  - последнее задание назад
#define idinternal1_m606_RA10	 844	//(internal1_m606_RA10)  - последнее задание назад
#define internal1_m606_MyFirstEnterFlag	 BUFFER[2846]	//(internal1_m606_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m606_MyFirstEnterFlag	 845	//(internal1_m606_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m605_Pav0	 BUFFER[2848]	//(internal1_m605_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m605_Pav0	 846	//(internal1_m605_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m605_Zav0	 BUFFER[2850]	//(internal1_m605_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m605_Zav0	 847	//(internal1_m605_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m605_Pv0	 BUFFER[2852]	//(internal1_m605_Pv0)  - Пер. выключатель механизма
#define idinternal1_m605_Pv0	 848	//(internal1_m605_Pv0)  - Пер. выключатель механизма
#define internal1_m605_Zv0	 BUFFER[2854]	//(internal1_m605_Zv0)  - Зад. выключатель механизма
#define idinternal1_m605_Zv0	 849	//(internal1_m605_Zv0)  - Зад. выключатель механизма
#define internal1_m605_RA00	 BUFFER[2856]	//(internal1_m605_RA00)  - последнее задание вперед
#define idinternal1_m605_RA00	 850	//(internal1_m605_RA00)  - последнее задание вперед
#define internal1_m605_RA10	 BUFFER[2858]	//(internal1_m605_RA10)  - последнее задание назад
#define idinternal1_m605_RA10	 851	//(internal1_m605_RA10)  - последнее задание назад
#define internal1_m605_MyFirstEnterFlag	 BUFFER[2860]	//(internal1_m605_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m605_MyFirstEnterFlag	 852	//(internal1_m605_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m652_y0	 BUFFER[2862]	//(internal1_m652_y0) y0 - внутренний параметр
#define idinternal1_m652_y0	 853	//(internal1_m652_y0) y0 - внутренний параметр
#define internal1_m816_Chim0	 BUFFER[2867]	//(internal1_m816_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m816_Chim0	 854	//(internal1_m816_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m807_Chim0	 BUFFER[2872]	//(internal1_m807_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m807_Chim0	 855	//(internal1_m807_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m799_Chim0	 BUFFER[2877]	//(internal1_m799_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m799_Chim0	 856	//(internal1_m799_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m790_Chim0	 BUFFER[2882]	//(internal1_m790_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m790_Chim0	 857	//(internal1_m790_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m781_Chim0	 BUFFER[2887]	//(internal1_m781_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m781_Chim0	 858	//(internal1_m781_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m773_Chim0	 BUFFER[2892]	//(internal1_m773_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m773_Chim0	 859	//(internal1_m773_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m764_Chim0	 BUFFER[2897]	//(internal1_m764_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m764_Chim0	 860	//(internal1_m764_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m755_Chim0	 BUFFER[2902]	//(internal1_m755_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m755_Chim0	 861	//(internal1_m755_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m747_Chim0	 BUFFER[2907]	//(internal1_m747_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m747_Chim0	 862	//(internal1_m747_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m738_Chim0	 BUFFER[2912]	//(internal1_m738_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m738_Chim0	 863	//(internal1_m738_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m729_Chim0	 BUFFER[2917]	//(internal1_m729_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m729_Chim0	 864	//(internal1_m729_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m719_Chim0	 BUFFER[2922]	//(internal1_m719_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m719_Chim0	 865	//(internal1_m719_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m592_Pav0	 BUFFER[2927]	//(internal1_m592_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m592_Pav0	 866	//(internal1_m592_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m592_Zav0	 BUFFER[2929]	//(internal1_m592_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m592_Zav0	 867	//(internal1_m592_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m592_Pv0	 BUFFER[2931]	//(internal1_m592_Pv0)  - Пер. выключатель механизма
#define idinternal1_m592_Pv0	 868	//(internal1_m592_Pv0)  - Пер. выключатель механизма
#define internal1_m592_Zv0	 BUFFER[2933]	//(internal1_m592_Zv0)  - Зад. выключатель механизма
#define idinternal1_m592_Zv0	 869	//(internal1_m592_Zv0)  - Зад. выключатель механизма
#define internal1_m592_RA00	 BUFFER[2935]	//(internal1_m592_RA00)  - последнее задание вперед
#define idinternal1_m592_RA00	 870	//(internal1_m592_RA00)  - последнее задание вперед
#define internal1_m592_RA10	 BUFFER[2937]	//(internal1_m592_RA10)  - последнее задание назад
#define idinternal1_m592_RA10	 871	//(internal1_m592_RA10)  - последнее задание назад
#define internal1_m592_MyFirstEnterFlag	 BUFFER[2939]	//(internal1_m592_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m592_MyFirstEnterFlag	 872	//(internal1_m592_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m577_Pav0	 BUFFER[2941]	//(internal1_m577_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m577_Pav0	 873	//(internal1_m577_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m577_Zav0	 BUFFER[2943]	//(internal1_m577_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m577_Zav0	 874	//(internal1_m577_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m577_Pv0	 BUFFER[2945]	//(internal1_m577_Pv0)  - Пер. выключатель механизма
#define idinternal1_m577_Pv0	 875	//(internal1_m577_Pv0)  - Пер. выключатель механизма
#define internal1_m577_Zv0	 BUFFER[2947]	//(internal1_m577_Zv0)  - Зад. выключатель механизма
#define idinternal1_m577_Zv0	 876	//(internal1_m577_Zv0)  - Зад. выключатель механизма
#define internal1_m577_RA00	 BUFFER[2949]	//(internal1_m577_RA00)  - последнее задание вперед
#define idinternal1_m577_RA00	 877	//(internal1_m577_RA00)  - последнее задание вперед
#define internal1_m577_RA10	 BUFFER[2951]	//(internal1_m577_RA10)  - последнее задание назад
#define idinternal1_m577_RA10	 878	//(internal1_m577_RA10)  - последнее задание назад
#define internal1_m577_MyFirstEnterFlag	 BUFFER[2953]	//(internal1_m577_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m577_MyFirstEnterFlag	 879	//(internal1_m577_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m463_Pav0	 BUFFER[2955]	//(internal1_m463_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m463_Pav0	 880	//(internal1_m463_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m463_Zav0	 BUFFER[2957]	//(internal1_m463_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m463_Zav0	 881	//(internal1_m463_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m463_Pv0	 BUFFER[2959]	//(internal1_m463_Pv0)  - Пер. выключатель механизма
#define idinternal1_m463_Pv0	 882	//(internal1_m463_Pv0)  - Пер. выключатель механизма
#define internal1_m463_Zv0	 BUFFER[2961]	//(internal1_m463_Zv0)  - Зад. выключатель механизма
#define idinternal1_m463_Zv0	 883	//(internal1_m463_Zv0)  - Зад. выключатель механизма
#define internal1_m463_RA00	 BUFFER[2963]	//(internal1_m463_RA00)  - последнее задание вперед
#define idinternal1_m463_RA00	 884	//(internal1_m463_RA00)  - последнее задание вперед
#define internal1_m463_RA10	 BUFFER[2965]	//(internal1_m463_RA10)  - последнее задание назад
#define idinternal1_m463_RA10	 885	//(internal1_m463_RA10)  - последнее задание назад
#define internal1_m463_MyFirstEnterFlag	 BUFFER[2967]	//(internal1_m463_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m463_MyFirstEnterFlag	 886	//(internal1_m463_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m448_Pav0	 BUFFER[2969]	//(internal1_m448_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m448_Pav0	 887	//(internal1_m448_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m448_Zav0	 BUFFER[2971]	//(internal1_m448_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m448_Zav0	 888	//(internal1_m448_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m448_Pv0	 BUFFER[2973]	//(internal1_m448_Pv0)  - Пер. выключатель механизма
#define idinternal1_m448_Pv0	 889	//(internal1_m448_Pv0)  - Пер. выключатель механизма
#define internal1_m448_Zv0	 BUFFER[2975]	//(internal1_m448_Zv0)  - Зад. выключатель механизма
#define idinternal1_m448_Zv0	 890	//(internal1_m448_Zv0)  - Зад. выключатель механизма
#define internal1_m448_RA00	 BUFFER[2977]	//(internal1_m448_RA00)  - последнее задание вперед
#define idinternal1_m448_RA00	 891	//(internal1_m448_RA00)  - последнее задание вперед
#define internal1_m448_RA10	 BUFFER[2979]	//(internal1_m448_RA10)  - последнее задание назад
#define idinternal1_m448_RA10	 892	//(internal1_m448_RA10)  - последнее задание назад
#define internal1_m448_MyFirstEnterFlag	 BUFFER[2981]	//(internal1_m448_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m448_MyFirstEnterFlag	 893	//(internal1_m448_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m504_Pav0	 BUFFER[2983]	//(internal1_m504_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m504_Pav0	 894	//(internal1_m504_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m504_Zav0	 BUFFER[2985]	//(internal1_m504_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m504_Zav0	 895	//(internal1_m504_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m504_Pv0	 BUFFER[2987]	//(internal1_m504_Pv0)  - Пер. выключатель механизма
#define idinternal1_m504_Pv0	 896	//(internal1_m504_Pv0)  - Пер. выключатель механизма
#define internal1_m504_Zv0	 BUFFER[2989]	//(internal1_m504_Zv0)  - Зад. выключатель механизма
#define idinternal1_m504_Zv0	 897	//(internal1_m504_Zv0)  - Зад. выключатель механизма
#define internal1_m504_RA00	 BUFFER[2991]	//(internal1_m504_RA00)  - последнее задание вперед
#define idinternal1_m504_RA00	 898	//(internal1_m504_RA00)  - последнее задание вперед
#define internal1_m504_RA10	 BUFFER[2993]	//(internal1_m504_RA10)  - последнее задание назад
#define idinternal1_m504_RA10	 899	//(internal1_m504_RA10)  - последнее задание назад
#define internal1_m504_MyFirstEnterFlag	 BUFFER[2995]	//(internal1_m504_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m504_MyFirstEnterFlag	 900	//(internal1_m504_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m399_Pav0	 BUFFER[2997]	//(internal1_m399_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m399_Pav0	 901	//(internal1_m399_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m399_Zav0	 BUFFER[2999]	//(internal1_m399_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m399_Zav0	 902	//(internal1_m399_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m399_Pv0	 BUFFER[3001]	//(internal1_m399_Pv0)  - Пер. выключатель механизма
#define idinternal1_m399_Pv0	 903	//(internal1_m399_Pv0)  - Пер. выключатель механизма
#define internal1_m399_Zv0	 BUFFER[3003]	//(internal1_m399_Zv0)  - Зад. выключатель механизма
#define idinternal1_m399_Zv0	 904	//(internal1_m399_Zv0)  - Зад. выключатель механизма
#define internal1_m399_RA00	 BUFFER[3005]	//(internal1_m399_RA00)  - последнее задание вперед
#define idinternal1_m399_RA00	 905	//(internal1_m399_RA00)  - последнее задание вперед
#define internal1_m399_RA10	 BUFFER[3007]	//(internal1_m399_RA10)  - последнее задание назад
#define idinternal1_m399_RA10	 906	//(internal1_m399_RA10)  - последнее задание назад
#define internal1_m399_MyFirstEnterFlag	 BUFFER[3009]	//(internal1_m399_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m399_MyFirstEnterFlag	 907	//(internal1_m399_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m383_Pav0	 BUFFER[3011]	//(internal1_m383_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m383_Pav0	 908	//(internal1_m383_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m383_Zav0	 BUFFER[3013]	//(internal1_m383_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m383_Zav0	 909	//(internal1_m383_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m383_Pv0	 BUFFER[3015]	//(internal1_m383_Pv0)  - Пер. выключатель механизма
#define idinternal1_m383_Pv0	 910	//(internal1_m383_Pv0)  - Пер. выключатель механизма
#define internal1_m383_Zv0	 BUFFER[3017]	//(internal1_m383_Zv0)  - Зад. выключатель механизма
#define idinternal1_m383_Zv0	 911	//(internal1_m383_Zv0)  - Зад. выключатель механизма
#define internal1_m383_RA00	 BUFFER[3019]	//(internal1_m383_RA00)  - последнее задание вперед
#define idinternal1_m383_RA00	 912	//(internal1_m383_RA00)  - последнее задание вперед
#define internal1_m383_RA10	 BUFFER[3021]	//(internal1_m383_RA10)  - последнее задание назад
#define idinternal1_m383_RA10	 913	//(internal1_m383_RA10)  - последнее задание назад
#define internal1_m383_MyFirstEnterFlag	 BUFFER[3023]	//(internal1_m383_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m383_MyFirstEnterFlag	 914	//(internal1_m383_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m366_Pav0	 BUFFER[3025]	//(internal1_m366_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m366_Pav0	 915	//(internal1_m366_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m366_Zav0	 BUFFER[3027]	//(internal1_m366_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m366_Zav0	 916	//(internal1_m366_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m366_Pv0	 BUFFER[3029]	//(internal1_m366_Pv0)  - Пер. выключатель механизма
#define idinternal1_m366_Pv0	 917	//(internal1_m366_Pv0)  - Пер. выключатель механизма
#define internal1_m366_Zv0	 BUFFER[3031]	//(internal1_m366_Zv0)  - Зад. выключатель механизма
#define idinternal1_m366_Zv0	 918	//(internal1_m366_Zv0)  - Зад. выключатель механизма
#define internal1_m366_RA00	 BUFFER[3033]	//(internal1_m366_RA00)  - последнее задание вперед
#define idinternal1_m366_RA00	 919	//(internal1_m366_RA00)  - последнее задание вперед
#define internal1_m366_RA10	 BUFFER[3035]	//(internal1_m366_RA10)  - последнее задание назад
#define idinternal1_m366_RA10	 920	//(internal1_m366_RA10)  - последнее задание назад
#define internal1_m366_MyFirstEnterFlag	 BUFFER[3037]	//(internal1_m366_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m366_MyFirstEnterFlag	 921	//(internal1_m366_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m909_Pav0	 BUFFER[3039]	//(internal1_m909_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m909_Pav0	 922	//(internal1_m909_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m909_Zav0	 BUFFER[3041]	//(internal1_m909_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m909_Zav0	 923	//(internal1_m909_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m909_Pv0	 BUFFER[3043]	//(internal1_m909_Pv0)  - Пер. выключатель механизма
#define idinternal1_m909_Pv0	 924	//(internal1_m909_Pv0)  - Пер. выключатель механизма
#define internal1_m909_Zv0	 BUFFER[3045]	//(internal1_m909_Zv0)  - Зад. выключатель механизма
#define idinternal1_m909_Zv0	 925	//(internal1_m909_Zv0)  - Зад. выключатель механизма
#define internal1_m909_RA00	 BUFFER[3047]	//(internal1_m909_RA00)  - последнее задание вперед
#define idinternal1_m909_RA00	 926	//(internal1_m909_RA00)  - последнее задание вперед
#define internal1_m909_RA10	 BUFFER[3049]	//(internal1_m909_RA10)  - последнее задание назад
#define idinternal1_m909_RA10	 927	//(internal1_m909_RA10)  - последнее задание назад
#define internal1_m909_MyFirstEnterFlag	 BUFFER[3051]	//(internal1_m909_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m909_MyFirstEnterFlag	 928	//(internal1_m909_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m182_C1	 BUFFER[3053]	//(internal1_m182_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m182_C1	 929	//(internal1_m182_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m182_C2	 BUFFER[3058]	//(internal1_m182_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m182_C2	 930	//(internal1_m182_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m182_C3	 BUFFER[3063]	//(internal1_m182_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m182_C3	 931	//(internal1_m182_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m182_C4	 BUFFER[3068]	//(internal1_m182_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m182_C4	 932	//(internal1_m182_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m182_C5	 BUFFER[3073]	//(internal1_m182_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m182_C5	 933	//(internal1_m182_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m182_C6	 BUFFER[3078]	//(internal1_m182_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m182_C6	 934	//(internal1_m182_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m182_N20	 BUFFER[3083]	//(internal1_m182_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m182_N20	 935	//(internal1_m182_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m182_C0	 BUFFER[3088]	//(internal1_m182_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define idinternal1_m182_C0	 936	//(internal1_m182_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define internal1_m182_ImpINI0	 BUFFER[3118]	//(internal1_m182_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m182_ImpINI0	 937	//(internal1_m182_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m182_MyFirstEnterFlag	 BUFFER[3120]	//(internal1_m182_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m182_MyFirstEnterFlag	 938	//(internal1_m182_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m300_Ppv0	 BUFFER[3122]	//(internal1_m300_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m300_Ppv0	 939	//(internal1_m300_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m300_Pav0	 BUFFER[3124]	//(internal1_m300_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m300_Pav0	 940	//(internal1_m300_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m300_Zav0	 BUFFER[3126]	//(internal1_m300_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m300_Zav0	 941	//(internal1_m300_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m300_RA00	 BUFFER[3128]	//(internal1_m300_RA00) RA00 - последнее задание вперед
#define idinternal1_m300_RA00	 942	//(internal1_m300_RA00) RA00 - последнее задание вперед
#define internal1_m300_RA10	 BUFFER[3130]	//(internal1_m300_RA10) RA10 - последнее задание назад
#define idinternal1_m300_RA10	 943	//(internal1_m300_RA10) RA10 - последнее задание назад
#define internal1_m300_RA50	 BUFFER[3132]	//(internal1_m300_RA50) Ra50 - последнее задание скорости
#define idinternal1_m300_RA50	 944	//(internal1_m300_RA50) Ra50 - последнее задание скорости
#define internal1_m300_fls	 BUFFER[3133]	//(internal1_m300_fls)  fls - флаг одношагового режима
#define idinternal1_m300_fls	 945	//(internal1_m300_fls)  fls - флаг одношагового режима
#define internal1_m300_flp	 BUFFER[3135]	//(internal1_m300_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m300_flp	 946	//(internal1_m300_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m300_MyFirstEnterFlag	 BUFFER[3137]	//(internal1_m300_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m300_MyFirstEnterFlag	 947	//(internal1_m300_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m130_Ppv0	 BUFFER[3139]	//(internal1_m130_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m130_Ppv0	 948	//(internal1_m130_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m130_Pav0	 BUFFER[3141]	//(internal1_m130_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m130_Pav0	 949	//(internal1_m130_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m130_Zav0	 BUFFER[3143]	//(internal1_m130_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m130_Zav0	 950	//(internal1_m130_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m130_RA00	 BUFFER[3145]	//(internal1_m130_RA00) RA00 - последнее задание вперед
#define idinternal1_m130_RA00	 951	//(internal1_m130_RA00) RA00 - последнее задание вперед
#define internal1_m130_RA10	 BUFFER[3147]	//(internal1_m130_RA10) RA10 - последнее задание назад
#define idinternal1_m130_RA10	 952	//(internal1_m130_RA10) RA10 - последнее задание назад
#define internal1_m130_RA50	 BUFFER[3149]	//(internal1_m130_RA50) Ra50 - последнее задание скорости
#define idinternal1_m130_RA50	 953	//(internal1_m130_RA50) Ra50 - последнее задание скорости
#define internal1_m130_fls	 BUFFER[3150]	//(internal1_m130_fls)  fls - флаг одношагового режима
#define idinternal1_m130_fls	 954	//(internal1_m130_fls)  fls - флаг одношагового режима
#define internal1_m130_flp	 BUFFER[3152]	//(internal1_m130_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m130_flp	 955	//(internal1_m130_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m130_MyFirstEnterFlag	 BUFFER[3154]	//(internal1_m130_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m130_MyFirstEnterFlag	 956	//(internal1_m130_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m267_Ppv0	 BUFFER[3156]	//(internal1_m267_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m267_Ppv0	 957	//(internal1_m267_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m267_Pav0	 BUFFER[3158]	//(internal1_m267_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m267_Pav0	 958	//(internal1_m267_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m267_Zav0	 BUFFER[3160]	//(internal1_m267_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m267_Zav0	 959	//(internal1_m267_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m267_RA00	 BUFFER[3162]	//(internal1_m267_RA00) RA00 - последнее задание вперед
#define idinternal1_m267_RA00	 960	//(internal1_m267_RA00) RA00 - последнее задание вперед
#define internal1_m267_RA10	 BUFFER[3164]	//(internal1_m267_RA10) RA10 - последнее задание назад
#define idinternal1_m267_RA10	 961	//(internal1_m267_RA10) RA10 - последнее задание назад
#define internal1_m267_RA50	 BUFFER[3166]	//(internal1_m267_RA50) Ra50 - последнее задание скорости
#define idinternal1_m267_RA50	 962	//(internal1_m267_RA50) Ra50 - последнее задание скорости
#define internal1_m267_fls	 BUFFER[3167]	//(internal1_m267_fls)  fls - флаг одношагового режима
#define idinternal1_m267_fls	 963	//(internal1_m267_fls)  fls - флаг одношагового режима
#define internal1_m267_flp	 BUFFER[3169]	//(internal1_m267_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m267_flp	 964	//(internal1_m267_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m267_MyFirstEnterFlag	 BUFFER[3171]	//(internal1_m267_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m267_MyFirstEnterFlag	 965	//(internal1_m267_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m96_Ppv0	 BUFFER[3173]	//(internal1_m96_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m96_Ppv0	 966	//(internal1_m96_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m96_Pav0	 BUFFER[3175]	//(internal1_m96_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m96_Pav0	 967	//(internal1_m96_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m96_Zav0	 BUFFER[3177]	//(internal1_m96_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m96_Zav0	 968	//(internal1_m96_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m96_RA00	 BUFFER[3179]	//(internal1_m96_RA00) RA00 - последнее задание вперед
#define idinternal1_m96_RA00	 969	//(internal1_m96_RA00) RA00 - последнее задание вперед
#define internal1_m96_RA10	 BUFFER[3181]	//(internal1_m96_RA10) RA10 - последнее задание назад
#define idinternal1_m96_RA10	 970	//(internal1_m96_RA10) RA10 - последнее задание назад
#define internal1_m96_RA50	 BUFFER[3183]	//(internal1_m96_RA50) Ra50 - последнее задание скорости
#define idinternal1_m96_RA50	 971	//(internal1_m96_RA50) Ra50 - последнее задание скорости
#define internal1_m96_fls	 BUFFER[3184]	//(internal1_m96_fls)  fls - флаг одношагового режима
#define idinternal1_m96_fls	 972	//(internal1_m96_fls)  fls - флаг одношагового режима
#define internal1_m96_flp	 BUFFER[3186]	//(internal1_m96_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m96_flp	 973	//(internal1_m96_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m96_MyFirstEnterFlag	 BUFFER[3188]	//(internal1_m96_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m96_MyFirstEnterFlag	 974	//(internal1_m96_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m229_Ppv0	 BUFFER[3190]	//(internal1_m229_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m229_Ppv0	 975	//(internal1_m229_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m229_Pav0	 BUFFER[3192]	//(internal1_m229_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m229_Pav0	 976	//(internal1_m229_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m229_Zav0	 BUFFER[3194]	//(internal1_m229_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m229_Zav0	 977	//(internal1_m229_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m229_RA00	 BUFFER[3196]	//(internal1_m229_RA00) RA00 - последнее задание вперед
#define idinternal1_m229_RA00	 978	//(internal1_m229_RA00) RA00 - последнее задание вперед
#define internal1_m229_RA10	 BUFFER[3198]	//(internal1_m229_RA10) RA10 - последнее задание назад
#define idinternal1_m229_RA10	 979	//(internal1_m229_RA10) RA10 - последнее задание назад
#define internal1_m229_RA50	 BUFFER[3200]	//(internal1_m229_RA50) Ra50 - последнее задание скорости
#define idinternal1_m229_RA50	 980	//(internal1_m229_RA50) Ra50 - последнее задание скорости
#define internal1_m229_fls	 BUFFER[3201]	//(internal1_m229_fls)  fls - флаг одношагового режима
#define idinternal1_m229_fls	 981	//(internal1_m229_fls)  fls - флаг одношагового режима
#define internal1_m229_flp	 BUFFER[3203]	//(internal1_m229_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m229_flp	 982	//(internal1_m229_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m229_MyFirstEnterFlag	 BUFFER[3205]	//(internal1_m229_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m229_MyFirstEnterFlag	 983	//(internal1_m229_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m60_Ppv0	 BUFFER[3207]	//(internal1_m60_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m60_Ppv0	 984	//(internal1_m60_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m60_Pav0	 BUFFER[3209]	//(internal1_m60_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m60_Pav0	 985	//(internal1_m60_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m60_Zav0	 BUFFER[3211]	//(internal1_m60_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m60_Zav0	 986	//(internal1_m60_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m60_RA00	 BUFFER[3213]	//(internal1_m60_RA00) RA00 - последнее задание вперед
#define idinternal1_m60_RA00	 987	//(internal1_m60_RA00) RA00 - последнее задание вперед
#define internal1_m60_RA10	 BUFFER[3215]	//(internal1_m60_RA10) RA10 - последнее задание назад
#define idinternal1_m60_RA10	 988	//(internal1_m60_RA10) RA10 - последнее задание назад
#define internal1_m60_RA50	 BUFFER[3217]	//(internal1_m60_RA50) Ra50 - последнее задание скорости
#define idinternal1_m60_RA50	 989	//(internal1_m60_RA50) Ra50 - последнее задание скорости
#define internal1_m60_fls	 BUFFER[3218]	//(internal1_m60_fls)  fls - флаг одношагового режима
#define idinternal1_m60_fls	 990	//(internal1_m60_fls)  fls - флаг одношагового режима
#define internal1_m60_flp	 BUFFER[3220]	//(internal1_m60_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m60_flp	 991	//(internal1_m60_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m60_MyFirstEnterFlag	 BUFFER[3222]	//(internal1_m60_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m60_MyFirstEnterFlag	 992	//(internal1_m60_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m14_C1	 BUFFER[3224]	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m14_C1	 993	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m14_C2	 BUFFER[3229]	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m14_C2	 994	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m14_C3	 BUFFER[3234]	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m14_C3	 995	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m14_C4	 BUFFER[3239]	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m14_C4	 996	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m14_C5	 BUFFER[3244]	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m14_C5	 997	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m14_C6	 BUFFER[3249]	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m14_C6	 998	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m14_N20	 BUFFER[3254]	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m14_N20	 999	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m14_C0	 BUFFER[3259]	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define idinternal1_m14_C0	 1000	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define internal1_m14_ImpINI0	 BUFFER[3289]	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m14_ImpINI0	 1001	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m14_MyFirstEnterFlag	 BUFFER[3291]	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m14_MyFirstEnterFlag	 1002	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &A1IS11LDU},	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
	{ 2	,1	,1	, &A1IS21LDU},	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
	{ 3	,1	,1	, &B6IS21LDU},	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
	{ 4	,1	,1	, &B6IS11LDU},	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
	{ 5	,1	,1	, &A6IS21LDU},	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
	{ 6	,1	,1	, &A6IS11LDU},	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
	{ 7	,1	,1	, &A8IS12LDU},	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
	{ 8	,1	,1	, &A8IS22LDU},	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
	{ 9	,1	,1	, &B8IS12LDU},	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
	{ 10	,1	,1	, &B8IS22LDU},	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
	{ 11	,1	,1	, &R4IS12LDU},	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
	{ 12	,1	,1	, &R4IS22LDU},	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
	{ 13	,1	,1	, &R4IS21LDU},	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
	{ 14	,1	,1	, &R4IS11LDU},	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
	{ 15	,1	,1	, &B4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
	{ 16	,1	,1	, &A4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
	{ 17	,1	,1	, &R2IS21LDU},	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
	{ 18	,1	,1	, &R0EE04LZ1},	//( - , SBz1) Питание  АКНП4  отключить
	{ 19	,1	,1	, &R0EE03LZ1},	//( - , SBz1) Питание  АКНП3  отключить
	{ 20	,1	,1	, &R0EE02LZ1},	//( - , SBz1) Питание  АКНП  отключить
	{ 21	,1	,1	, &R0EE01LZ2},	//( - , SBz2) Питание  АКНП1  отключить
	{ 22	,1	,1	, &R0EE01LZ1},	//( - , SBz1) Питание  АКНП1  отключить
	{ 23	,1	,1	, &B4IS10LDU},	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
	{ 24	,1	,1	, &A4IS10LDU},	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
	{ 25	,1	,1	, &B1IE04LDU},	//( - , SCM) Движение ББ2 назад (от БУШД)
	{ 26	,1	,1	, &B1IE03LDU},	//( - , SCM) Движение ББ2 вперед (от БУШД)
	{ 27	,1	,1	, &A1IE04LDU},	//( - , SCM) Движение ББ1 назад (от БУШД)
	{ 28	,1	,1	, &A1IE03LDU},	//( - , SCM) Движение ББ1 вперед (от БУШД)
	{ 29	,1	,1	, &B1IS12LDU},	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
	{ 30	,1	,1	, &B1IS11LDU},	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
	{ 31	,1	,1	, &B1IS21LDU},	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
	{ 32	,5	,1	, &B1IC01UDU},	//( - , SDu) Координата штока ББ2
	{ 33	,5	,1	, &A1IC01UDU},	//( - , SDu) Координата штока ББ1
	{ 34	,1	,1	, &A1IS12LDU},	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
	{ 35	,1	,1	, &B2IS21LDU},	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
	{ 36	,1	,1	, &B9IS21LDU},	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
	{ 37	,1	,1	, &B9IS11LDU},	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
	{ 38	,1	,1	, &A9IS21LDU},	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
	{ 39	,1	,1	, &A9IS11LDU},	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
	{ 40	,1	,1	, &B5IS21LDU},	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
	{ 41	,1	,1	, &B5IS11LDU},	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
	{ 42	,1	,1	, &A5IS21LDU},	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
	{ 43	,1	,1	, &A5IS11LDU},	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
	{ 44	,1	,1	, &B0VP81LZZ},	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
	{ 45	,1	,1	, &A0VP81LZZ},	//(do32_pti:100 - K27DO, - ) Давление АЗ1 в норме
	{ 46	,5	,1	, &B8IC01UDU},	//( - , SDu) Координата АЗ2
	{ 47	,5	,1	, &A8IC01UDU},	//( - , SDu) Координата ДС2
	{ 48	,1	,1	, &R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 49	,1	,1	, &R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 50	,1	,1	, &R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 51	,1	,1	, &R6IS65LDU},	//( - , - ) Исправность ВИП ССДИ-35 2канал
	{ 52	,1	,1	, &R2IS11LDU},	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
	{ 53	,1	,1	, &R1IS21LDU},	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
	{ 54	,1	,1	, &R1IS11LDU},	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
	{ 55	,1	,1	, &B4IS21LDU},	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
	{ 56	,1	,1	, &B4IS11LDU},	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
	{ 57	,1	,1	, &R8IS11LDU},	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
	{ 58	,1	,1	, &A4IS21LDU},	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
	{ 59	,1	,1	, &A4IS11LDU},	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
	{ 60	,1	,1	, &R5IS21LDU},	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
	{ 61	,1	,1	, &R5IS11LDU},	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
	{ 62	,1	,1	, &R3IS21LDU},	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
	{ 63	,1	,1	, &R3IS11LDU},	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
	{ 64	,1	,1	, &B2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
	{ 65	,3	,1	, &B2IP01IZ2},	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
	{ 66	,3	,1	, &B2IP01IZ1},	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
	{ 67	,5	,1	, &B2IC01UDU},	//( - , SDu) Координата штока РБ2
	{ 68	,1	,1	, &B2IS12LDU},	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
	{ 69	,1	,1	, &B2IS11LDU},	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
	{ 70	,8	,1	, &R0IN02FI3},	//( - , SA3) Выход КНК15-1 Гц от ПТИ
	{ 71	,8	,1	, &R0IN03FI2},	//( - , SA2) Выход КНК53М Гц от ПТИ
	{ 72	,8	,1	, &R0IN07RIP},	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
	{ 73	,8	,1	, &R0IN06RIP},	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
	{ 74	,3	,1	, &TerR0IN06FRP},	//( - , - ) Неисправности СНМ-11 -1,2
	{ 75	,8	,1	, &R0IN03RIP},	//( - , SRP) Выход КНК53М Гц от ПТИ
	{ 76	,8	,1	, &R0IN02RIP},	//( - , SRP) Выход КНК15- Гц от ПТИ
	{ 77	,8	,1	, &R0IN01RIP},	//( - , SRP) Выход СНМ-11 Гц от ПТИ
	{ 78	,8	,1	, &R0IN02FI2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{ 79	,8	,1	, &R0IN03FI1},	//( - , SA1) Выход КНК53М Гц от ПТИ
	{ 80	,8	,1	, &R0IN02FI1},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{ 81	,8	,1	, &R0IN03FI4},	//( - , SA4) Выход КНК53М Гц от ПТИ
	{ 82	,8	,1	, &R0IN02FI4},	//( - , SA4) Выход КНК15-1 Гц от ПТИ
	{ 83	,8	,1	, &R0IN01FI3},	//( - , SA3) Выход СНМ-11 Гц от ПТИ
	{ 84	,8	,1	, &R0IN01FI2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{ 85	,8	,1	, &R0IN01FI4},	//( - , SA4) Выход СНМ-11 Гц от ПТИ
	{ 86	,8	,1	, &R0IN01FI1},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{ 87	,8	,1	, &B0SN07RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
	{ 88	,8	,1	, &B0SN06RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
	{ 89	,8	,1	, &B0SN05RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
	{ 90	,8	,1	, &B0SN04RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
	{ 91	,8	,1	, &B0SN03RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
	{ 92	,8	,1	, &B0SN02RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
	{ 93	,8	,1	, &A0SN07RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
	{ 94	,8	,1	, &A0SN06RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
	{ 95	,8	,1	, &A0SN05RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
	{ 96	,8	,1	, &A0SN04RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
	{ 97	,8	,1	, &A0SN03RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
	{ 98	,8	,1	, &A0SN02RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
	{ 99	,3	,1	, &R0DEUMLSS},	//( - , SCM) Сигнал управления моделью
	{ 100	,3	,1	, &R0MW11IP1},	//( - , SCM) Переключатель ВЫСТРЕЛ
	{ 101	,3	,1	, &R0IS01FI0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{ 102	,3	,1	, &A0IT03IRP},	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
	{ 103	,3	,1	, &B0IT03IRP},	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
	{ 104	,8	,1	, &R0IN03FI3},	//( - , SA3) Выход КНК53М Гц от ПТИ
	{ 105	,1	,1	, &A1VP81LZZ},	//(do32_pti:100 - K28DO, - ) Давление СБРОС ББ1 в норме
	{ 106	,1	,1	, &B1VP81LZZ},	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
	{ 107	,1	,1	, &B2IS33LDU},	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
	{ 108	,8	,1	, &A0VN01RIM},	//( - , SCM) Период разгона  AЗ1
	{ 109	,1	,1	, &B2IS32LIM},	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
	{ 110	,1	,1	, &B2IS11LIM},	//( - , SCM) Магнит РБ2 обесточен
	{ 111	,1	,1	, &A2IS32LIM},	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
	{ 112	,1	,1	, &A2IS11LIM},	//( - , SCM) Магнит РБ1 обесточен
	{ 113	,1	,1	, &B1IS32LIM},	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
	{ 114	,1	,1	, &B1IS11LIM},	//( - , SCM) Магнит ББ2 обесточен
	{ 115	,1	,1	, &A1IS32LIM},	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
	{ 116	,1	,1	, &A1IS11LIM},	//( - , SCM) Магнит ББ1 обесточен
	{ 117	,1	,1	, &A3AD34LDU},	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
	{ 118	,1	,1	, &R0IS02LDU},	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
	{ 119	,1	,1	, &R0EE04LZ2},	//( - , SBz2) Питание  АКНП4  отключить
	{ 120	,1	,1	, &R0EE03LZ2},	//( - , SBz2) Питание  АКНП3  отключить
	{ 121	,1	,1	, &R0EE02LZ2},	//( - , SBz2) Питание  АКНП  отключить
	{ 122	,1	,1	, &B7AP31LDU},	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
	{ 123	,1	,1	, &A7AP31LDU},	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
	{ 124	,1	,1	, &R4VS12LDU},	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
	{ 125	,1	,1	, &R4VS22LDU},	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
	{ 126	,1	,1	, &R1VS12LDU},	//( - , SCM) Движение МДЗ1 в сторону ВУ
	{ 127	,1	,1	, &R2VS12LDU},	//( - , SCM) Движение МДЗ2 в сторону ВУ
	{ 128	,1	,1	, &R2VS22LDU},	//( - , SCM) Движение МДЗ2 в сторону НУ
	{ 129	,1	,1	, &R1VS22LDU},	//( - , SCM) Движение МДЗ1 в сторону НУ
	{ 130	,1	,1	, &B5VS12LDU},	//( - , SCM) Движение НЛ2 в сторону ВУ
	{ 131	,1	,1	, &B5VS22LDU},	//( - , SCM) Движение НЛ2 в сторону НУ
	{ 132	,1	,1	, &A5VS12LDU},	//( - , SCM) Движение НЛ1 в сторону ВУ
	{ 133	,1	,1	, &A5VS22LDU},	//( - , SCM) Движение НЛ1 в сторону НУ
	{ 134	,1	,1	, &B6VS12LDU},	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
	{ 135	,1	,1	, &B6VS22LDU},	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
	{ 136	,1	,1	, &A6VS12LDU},	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
	{ 137	,1	,1	, &A6VS22LDU},	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
	{ 138	,1	,1	, &B8IS21LDU},	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
	{ 139	,1	,1	, &B8IS11LDU},	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
	{ 140	,1	,1	, &B8AD20LDU},	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
	{ 141	,1	,1	, &B8AD10LDU},	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
	{ 142	,1	,1	, &R4AD20LDU},	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
	{ 143	,1	,1	, &R4AD10LDU},	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
	{ 144	,8	,1	, &B0SR01RIM},	//( - , SCM) Текущая реактивность AЗ2
	{ 145	,1	,1	, &B3AD33LDU},	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
	{ 146	,1	,1	, &B3AD05LDU},	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
	{ 147	,1	,1	, &B3AD04LDU},	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
	{ 148	,1	,1	, &B3AD03LDU},	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
	{ 149	,1	,1	, &B3AD02LDU},	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
	{ 150	,1	,1	, &B3AD01LDU},	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
	{ 151	,1	,1	, &B3AD21LDU},	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
	{ 152	,1	,1	, &B3AD11LDU},	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
	{ 153	,1	,1	, &A3AD33LDU},	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
	{ 154	,1	,1	, &A3AD05LDU},	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
	{ 155	,1	,1	, &A3AD04LDU},	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
	{ 156	,1	,1	, &A3AD03LDU},	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
	{ 157	,8	,1	, &R0CR01RIM},	//( - , SCM) Коэффициент 12 связи АЗ1,2
	{ 158	,8	,1	, &B0SN08RIM},	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
	{ 159	,8	,1	, &A0SN08RIM},	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
	{ 160	,1	,1	, &B5AD20LDU},	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
	{ 161	,1	,1	, &B5AD10LDU},	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
	{ 162	,1	,1	, &A5AD20LDU},	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
	{ 163	,1	,1	, &A5AD10LDU},	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
	{ 164	,1	,1	, &R2AD20LDU},	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
	{ 165	,1	,1	, &R2AD10LDU},	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
	{ 166	,1	,1	, &R1AD20LDU},	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
	{ 167	,1	,1	, &R1AD10LDU},	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
	{ 168	,1	,1	, &B6AD20LDU},	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
	{ 169	,1	,1	, &B6AD10LDU},	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
	{ 170	,1	,1	, &A6AD20LDU},	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
	{ 171	,1	,1	, &A6AD10LDU},	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
	{ 172	,1	,1	, &A8AD20LDU},	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
	{ 173	,1	,1	, &A8AD10LDU},	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
	{ 174	,1	,1	, &A2AD21LDU},	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
	{ 175	,1	,1	, &A2AD11LDU},	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
	{ 176	,1	,1	, &B1AD05LDU},	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
	{ 177	,1	,1	, &B1AD04LDU},	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
	{ 178	,1	,1	, &B1AD03LDU},	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
	{ 179	,1	,1	, &B1AD02LDU},	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
	{ 180	,1	,1	, &B1AD01LDU},	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
	{ 181	,1	,1	, &B1AD21LDU},	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
	{ 182	,1	,1	, &B1AD11LDU},	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
	{ 183	,1	,1	, &A1AD05LDU},	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
	{ 184	,1	,1	, &A1AD04LDU},	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
	{ 185	,1	,1	, &A1AD03LDU},	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
	{ 186	,1	,1	, &A1AD02LDU},	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
	{ 187	,1	,1	, &A1AD01LDU},	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
	{ 188	,1	,1	, &A1AD21LDU},	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
	{ 189	,1	,1	, &A1AD11LDU},	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
	{ 190	,8	,1	, &A0SR01RIM},	//( - , SCM) Текущая реактивность AЗ1
	{ 191	,1	,1	, &A3AD02LDU},	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
	{ 192	,1	,1	, &A3AD01LDU},	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
	{ 193	,1	,1	, &A3AD21LDU},	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
	{ 194	,1	,1	, &A3AD11LDU},	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
	{ 195	,1	,1	, &B2AD33LDU},	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
	{ 196	,1	,1	, &B2AD05LDU},	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
	{ 197	,1	,1	, &B2AD04LDU},	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
	{ 198	,1	,1	, &B2AD03LDU},	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
	{ 199	,1	,1	, &B2AD02LDU},	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
	{ 200	,1	,1	, &B2AD01LDU},	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
	{ 201	,1	,1	, &B2AD21LDU},	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
	{ 202	,1	,1	, &B2AD11LDU},	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
	{ 203	,1	,1	, &A2AD33LDU},	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
	{ 204	,1	,1	, &A2AD05LDU},	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
	{ 205	,1	,1	, &A2AD04LDU},	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
	{ 206	,1	,1	, &A2AD03LDU},	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
	{ 207	,1	,1	, &A2AD02LDU},	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
	{ 208	,1	,1	, &A2AD01LDU},	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
	{ 209	,3	,1	, &A2IP01IZ2},	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
	{ 210	,3	,1	, &A2IP01IZ1},	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
	{ 211	,1	,1	, &B3IS21LDU},	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
	{ 212	,1	,1	, &A3IS21LDU},	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
	{ 213	,1	,1	, &A2IS33LDU},	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
	{ 214	,5	,1	, &A2IC01UDU},	//( - , SDu) Координата штока РБ1
	{ 215	,1	,1	, &A2IS12LDU},	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
	{ 216	,1	,1	, &A2IS11LDU},	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
	{ 217	,1	,1	, &A2IS21LDU},	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
	{ 218	,3	,1	, &B0IT02IZ2},	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
	{ 219	,3	,1	, &B0IT01IZ1},	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
	{ 220	,3	,1	, &A0IT02IZ2},	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
	{ 221	,3	,1	, &A0IT01IZ1},	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
	{ 222	,1	,1	, &R6IS21LDU},	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
	{ 223	,1	,1	, &B7AS31LDU},	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
	{ 224	,1	,1	, &A7AS31LDU},	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
	{ 225	,1	,1	, &B3IS35LDU},	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
	{ 226	,1	,1	, &R6IS64LDU},	//( - , - ) Исправность ВИП ССДИ-35 1канал
	{ 227	,1	,1	, &R6IS63LDU},	//( - , - ) Исправность ВИП ССДИ-39 2канал
	{ 228	,1	,1	, &R6IS62LDU},	//( - , - ) Исправность ВИП ССДИ-39 1канал
	{ 229	,1	,1	, &B3IS22LDU},	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
	{ 230	,1	,1	, &A3IS22LDU},	//(do32_pti:100 - K06DO, - ) Приход на НУП ИС1
	{ 231	,1	,1	, &B3IS11LDU},	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
	{ 232	,1	,1	, &A3IS11LDU},	//(do32_pti:100 - K05DO, - ) Приход на ВУ ИС1
	{ 233	,3	,1	, &A3IP02IDU},	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
	{ 234	,1	,1	, &B3VP81LDU},	//( - , - ) Давление СПУСК ИС2 в норме
	{ 235	,1	,1	, &A3VP81LDU},	//( - , - ) Давление СПУСК ИС1 в норме
	{ 236	,1	,1	, &B3IS33LDU},	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{ 237	,5	,1	, &B3IC01UDU},	//( - , SDu) Координата штока ИС2
	{ 238	,1	,1	, &B3IS31LDU},	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
	{ 239	,3	,1	, &B3IP02IDU},	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
	{ 240	,1	,1	, &A3IS33LDU},	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
	{ 241	,5	,1	, &A3IC01UDU},	//( - , SDu) Координата штока ИС1
	{ 242	,1	,1	, &A3IS31LDU},	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
	{ 243	,1	,1	, &A2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
	{ 244	,1	,1	, &B2AD31LDU},	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
	{ 245	,1	,1	, &B1AD32LDU},	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
	{ 246	,1	,1	, &B1AD31LDU},	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
	{ 247	,1	,1	, &A3AD31LDU},	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
	{ 248	,1	,1	, &C1MD31LP1},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
	{ 249	,1	,1	, &C1MD31LP2},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
	{ 250	,1	,1	, &A1AD31LDU},	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
	{ 251	,1	,1	, &A1AD32LDU},	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
	{ 252	,1	,1	, &A2AD31LDU},	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
	{ 253	,1	,1	, &C2MD31LP1},	//( - , SCM) Кнопка «СБРОС РБ»
	{ 254	,1	,1	, &A2AD32LDU},	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
	{ 255	,1	,1	, &R0VZ71LZ2},	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
	{ 256	,1	,1	, &R0VZ71LZ1},	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
	{ 257	,1	,1	, &R8AD21LDU},	//(vds32_pti:310 - K31VDSR, - ) Запуск системы инициирования
	{ 258	,1	,1	, &R0AD14LDU},	//( - , SCM) Имитация срабатывания верхней АС II УР
	{ 259	,8	,1	, &R0SR02RIM},	//( - , SCM) Текущая мощность РУ (ватт)
	{ 260	,8	,1	, &R0CR02RIM},	//( - , SCM) Коэффициент 11 связи АЗ1,2
	{ 261	,1	,1	, &B3AD34LDU},	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
	{ 262	,1	,1	, &A3IS35LDU},	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
	{ 263	,1	,1	, &R7II73LZ2},	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
	{ 264	,1	,1	, &R7II71LZ2},	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
	{ 265	,1	,1	, &R7II72LZ2},	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
	{ 266	,1	,1	, &R0AD16LDU},	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
	{ 267	,1	,1	, &R7II72LZ1},	//(do32_pti:100 - K25DO, - ) Сработала АС IУР (датчик 2)
	{ 268	,1	,1	, &R7II71LZ1},	//(do32_pti:100 - K24DO, - ) Сработала АС IУР (датчик 1)
	{ 269	,1	,1	, &R7II73LZ1},	//(do32_pti:100 - K26DO, - ) Сработала АС IIУР
	{ 270	,8	,1	, &R0SR01RIM},	//( - , SCM) Текущая реактивность PУ
	{ 271	,8	,1	, &R0ST01RIM},	//( - , SCM) Текущий период разгона РУ
	{ 272	,1	,1	, &A4AD10LDU},	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
	{ 273	,1	,1	, &B4AD10LDU},	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
	{ 274	,1	,1	, &A9AD10LDU},	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
	{ 275	,1	,1	, &B9AD10LDU},	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
	{ 276	,1	,1	, &R0MW13LP2},	//( - , SCM) Переключатель «СЕТЬ»
	{ 277	,1	,1	, &B3AD31LDU},	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
	{ 278	,1	,1	, &B2AD32LDU},	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
	{ 279	,8	,1	, &fEM_R0UL01RIM},	//(R0UL01RIM) Среднее время генерации нейтронов
	{ 280	,8	,1	, &fEM_R0UN02RIM},	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{ 281	,8	,1	, &fEM_A1UR01RIM},	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{ 282	,8	,1	, &fEM_A1UR00RIM},	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{ 283	,8	,1	, &fEM_A3UR00RIM},	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{ 284	,8	,1	, &fEM_A3UR01RIM},	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{ 285	,8	,1	, &fEM_R0UT01RIM},	//(R0UT01RIM) Температурный коэффициент (долл)
	{ 286	,8	,1	, &fEM_R0UT02RIM},	//(R0UT02RIM) Масса топлива в АЗ
	{ 287	,8	,1	, &fEM_R0UT04RIM},	//(R0UT04RIM) Удельная теплоёмкость топлива
	{ 288	,8	,1	, &fEM_R0UT03RIM},	//(R0UT03RIM) Нормальная температура АЗ град
	{ 289	,8	,1	, &fEM_R0UT05RIM},	//(R0UT05RIM) Энергия деления ядра
	{ 290	,8	,1	, &fEM_R0UT06RIM},	//(R0UT06RIM) Конвекционное сопротивление при обдуве
	{ 291	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{ 292	,8	,1	, &fEM_A1UC04RIM},	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
	{ 293	,8	,1	, &fEM_A1UC05RIM},	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
	{ 294	,8	,1	, &fEM_A1UC06RIM},	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
	{ 295	,8	,1	, &fEM_A2UC06RIM},	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
	{ 296	,8	,1	, &fEM_A2UC05RIM},	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
	{ 297	,8	,1	, &fEM_A2UC04RIM},	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
	{ 298	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{ 299	,8	,1	, &fEM_A3UC06RIM},	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
	{ 300	,8	,1	, &fEM_A3UC05RIM},	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
	{ 301	,8	,1	, &fEM_A3UC04RIM},	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
	{ 302	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{ 303	,8	,1	, &fEM_R4UV80RDU},	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
	{ 304	,8	,1	, &fEM_R4UC10RIM},	//(R4UC10RIM) Координата верхних механических упоров тележки мм
	{ 305	,8	,1	, &fEM_R4UC20RIM},	//(R4UC20RIM) Координата нижних механических упоров тележки мм
	{ 306	,8	,1	, &fEM_B8UC21RIM},	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
	{ 307	,8	,1	, &fEM_B8UC20RIM},	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
	{ 308	,8	,1	, &fEM_B8UC11RIM},	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
	{ 309	,8	,1	, &fEM_B8UC10RIM},	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
	{ 310	,8	,1	, &fEM_B8UV80RDU},	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
	{ 311	,8	,1	, &fEM_A8UV80RDU},	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
	{ 312	,8	,1	, &fEM_A8UC10RIM},	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
	{ 313	,8	,1	, &fEM_A8UC11RIM},	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
	{ 314	,8	,1	, &fEM_A8UC20RIM},	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
	{ 315	,8	,1	, &fEM_A8UC21RIM},	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
	{ 316	,8	,1	, &fEM_A6UC10RIM},	//(A6UC10RIM) Время полного хода БЗ (сек)
	{ 317	,8	,1	, &fEM_R1UC10RIM},	//(R1UC10RIM) Время полного хода МДЗ сек
	{ 318	,8	,1	, &fEM_A5UC10RIM},	//(A5UC10RIM) Время полного хода НЛ сек
	{ 319	,8	,1	, &fEM_A0UN01RIM},	//(A0UN01RIM) Мощность источника нейтронов ИНИ
	{ 320	,8	,1	, &fEM_R4UC22RIM},	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
	{ 321	,8	,1	, &fEM_A1UG01RDU},	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
	{ 322	,8	,1	, &fEM_A2UG01RDU},	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
	{ 323	,8	,1	, &fEM_A3UG01RDU},	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
	{ 324	,8	,1	, &fEM_R7UC10RIM},	//(R7UC10RIM) X-координата КНК53М R7IN13 см
	{ 325	,8	,1	, &fEM_R7UC19RIM},	//(R7UC19RIM) Y-координата СНМ-11 (11) см
	{ 326	,8	,1	, &fEM_R7UI02RIM},	//(R7UI02RIM) Коэффициент усиления уровня радиации
	{ 327	,8	,1	, &fEM_R7UL01RIM},	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
	{ 328	,8	,1	, &fEM_A2UR00RIM},	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{ 329	,8	,1	, &fEM_A2UR01RIM},	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{ 330	,8	,1	, &fEM_A0UN02RIM},	//(A0UN02RIM) Мощность источника нейтронов с АНИ
	{ 331	,8	,1	, &fEM_R0UR30RIM},	//(R0UR30RIM) Реактивность вносимая образцами (долл)
	{ 332	,8	,1	, &fEM_R0UR01RIM},	//(R0UR01RIM) Стартовая отрицательная реактивность
	{ 333	,8	,1	, &fEM_R0UT02RDU},	//(R0UT02RDU) Верхний предел шкалы датчика температуры
	{ 334	,8	,1	, &fEM_R0UT01RDU},	//(R0UT01RDU) Нижний предел шкалы датчика температуры
	{ 335	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{ 336	,8	,1	, &fEM_A2UP03RDU},	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{ 337	,8	,1	, &fEM_A2UP04RDU},	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{ 338	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{ 339	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 340	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 341	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{ 342	,8	,1	, &fEM_R7UI74RIM},	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
	{ 343	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{ 344	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 345	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 346	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{ 347	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{ 348	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{ 349	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 350	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 351	,8	,1	, &fEM_A8UC08RDU},	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
	{ 352	,8	,1	, &fEM_B8UC08RDU},	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
	{ 353	,8	,1	, &fEM_R4UC08RDU},	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
	{ 354	,8	,1	, &fEM_R0UH01RSS},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
	{ 355	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 356	,8	,1	, &fEM_R7UX01RSS},	//(R7UX01RSS) X-координата камеры R7IN11
	{ 357	,8	,1	, &fEM_R7UX02RSS},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{ 358	,8	,1	, &fEM_R7UX04RSS},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{ 359	,8	,1	, &fEM_R7UX05RSS},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{ 360	,8	,1	, &fEM_R7UX06RSS},	//(R7UX06RSS) X-координата камеры R7IN23 (см)
	{ 361	,8	,1	, &fEM_R7UX07RSS},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{ 362	,8	,1	, &fEM_R7UX08RSS},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{ 363	,8	,1	, &fEM_R7UX09RSS},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{ 364	,8	,1	, &fEM_R7UY01RSS},	//(R7UY01RSS) Y-координата камеры R7IN11
	{ 365	,8	,1	, &fEM_R7UY02RSS},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{ 366	,8	,1	, &fEM_R7UY04RSS},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{ 367	,8	,1	, &fEM_R7UY05RSS},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{ 368	,8	,1	, &fEM_R7UY06RSS},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{ 369	,8	,1	, &fEM_R7UY07RSS},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{ 370	,8	,1	, &fEM_R7UY08RSS},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{ 371	,8	,1	, &fEM_R7UY09RSS},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{ 372	,8	,1	, &fEM_R7UX10RSS},	//(R7UX10RSS) X-координата камеры R7IN41
	{ 373	,8	,1	, &fEM_R7UX11RSS},	//(R7UX11RSS) X-координата камеры R7IN42
	{ 374	,8	,1	, &fEM_R7UX12RSS},	//(R7UX12RSS) X-координата камеры R7IN43
	{ 375	,8	,1	, &fEM_R7UY10RSS},	//(R7UY10RSS) Y-координата камеры R7IN41
	{ 376	,8	,1	, &fEM_R7UY11RSS},	//(R7UY11RSS) Y-координата камеры R7IN42
	{ 377	,8	,1	, &fEM_R7UY12RSS},	//(R7UY12RSS) Y-координата камеры R7IN43
	{ 378	,8	,1	, &fEM_A0UX01RSS},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{ 379	,8	,1	, &fEM_A0UX02RSS},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{ 380	,8	,1	, &fEM_A0UX03RSS},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{ 381	,8	,1	, &fEM_A0UX04RSS},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{ 382	,8	,1	, &fEM_A0UX05RSS},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{ 383	,8	,1	, &fEM_A0UX06RSS},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{ 384	,8	,1	, &fEM_A0UX07RSS},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{ 385	,8	,1	, &fEM_A0UX08RSS},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{ 386	,8	,1	, &fEM_A0UX09RSS},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{ 387	,8	,1	, &fEM_A0UX10RSS},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{ 388	,8	,1	, &fEM_A0UX11RSS},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{ 389	,8	,1	, &fEM_A0UX12RSS},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{ 390	,8	,1	, &fEM_B0UX01RSS},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{ 391	,8	,1	, &fEM_B0UX02RSS},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{ 392	,8	,1	, &fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{ 393	,8	,1	, &fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
	{ 394	,8	,1	, &fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{ 395	,8	,1	, &fEM_B0UX06RSS},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{ 396	,8	,1	, &fEM_B0UX07RSS},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{ 397	,8	,1	, &fEM_B0UX08RSS},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{ 398	,8	,1	, &fEM_B0UX09RSS},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{ 399	,8	,1	, &fEM_B0UX10RSS},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{ 400	,8	,1	, &fEM_B0UX11RSS},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{ 401	,8	,1	, &fEM_B0UX12RSS},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{ 402	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{ 403	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
	{ 404	,8	,1	, &fEM_R4US80RDU},	//(R4US80RDU) Тормозной путь тележки (мм)
	{ 405	,8	,1	, &fEM_R7UI71RIM},	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{ 406	,8	,1	, &fEM_R7UI72RIM},	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{ 407	,8	,1	, &fEM_R7UI73RIM},	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
	{ 408	,8	,1	, &fEM_A1UP01RIM},	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
	{ 409	,8	,1	, &fEM_A2UP01RIM},	//(A2UP01RIM) Текущее давление на сброс РБ
	{ 410	,8	,1	, &fEM_A0UP02RIM},	//(A0UP02RIM) Текущее давление в АЗ1,2
	{ 411	,8	,1	, &fEM_A3UP01RIM},	//(A3UP01RIM) Текущее давление на СПУСК ИС
	{ 412	,8	,1	, &fEM_A1UP82RIM},	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{ 413	,8	,1	, &fEM_A3UP02RDU},	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
	{ 414	,8	,1	, &fEM_A1UV02RIM},	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{ 415	,8	,1	, &fEM_A3UV02RIM},	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{ 416	,8	,1	, &fEM_A2UV02RIM},	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{ 417	,8	,1	, &fEM_B8US80RDU},	//(B8US80RDU) Тормозной путь АЗ2 (мм)
	{ 418	,8	,1	, &fEM_A8US80RDU},	//(A8US80RDU) Тормозной путь ДС2 (мм)
	{ 419	,8	,1	, &fEM_A6US80RDU},	//(A6US80RDU) Тормозной путь БЗ (мм)
	{ 420	,8	,1	, &fEM_A1US07RDU},	//(A1US07RDU) Постоянная времени масляного демпфера ББ
	{ 421	,8	,1	, &fEM_A2US07RDU},	//(A2US07RDU) Постоянная времени масляного демпфера РБ
	{ 422	,8	,1	, &fEM_A3US07RDU},	//(A3US07RDU) Постоянная времени масляного демпфера ИС
	{ 423	,8	,1	, &fEM_R7UI75RIM},	//(R7UI75RIM) Множитель к уровню радиации
	{ 424	,8	,1	, &fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{ 425	,8	,1	, &fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{ 426	,8	,1	, &fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{ 427	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 428	,8	,1	, &fEM_A4UL10RIM},	//(A4UL10RIM) Время полного перемещения НИ сек
	{ 429	,8	,1	, &fEM_A9UL10RIM},	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
	{ 430	,8	,1	, &fEM_R3UL10RIM},	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
	{ 431	,8	,1	, &fEM_R5UL10RIM},	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
	{ 432	,8	,1	, &fEM_R6UL10RIM},	//(R6UL10RIM) Время полного хода кран-балки сек
	{ 433	,1	,1	, &lEM_C1AD31LRP},	//(C1AD31LRP) Общий сброс от РПУ
	{ 434	,1	,1	, &lEM_R0IE01LRP},	//(R0IE01LRP) Отключение питание детекторов
	{ 435	,1	,1	, &lEM_R0IE02LRP},	//(R0IE02LRP) Отключить питание ПР, ПУ
	{ 436	,8	,1	, &fEM_A2UP02RIM},	//(A2UP02RIM) Текущее давление на подъём РБ
	{ 437	,8	,1	, &fEM_A2UP03RIM},	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
	{ 438	,8	,1	, &fEM_A0UP01RIM},	//(A0UP01RIM) Текущее давление в АЗ1,2
	{ 439	,8	,1	, &fEM_A3UP02RIM},	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
	{ 440	,8	,1	, &fEM_A4UP01RIM},	//(A4UP01RIM) Текущее давление на подъём НИ
	{ 441	,8	,1	, &fEM_A4UP02RIM},	//(A4UP02RIM) Нижняя граница давления на подъём НИ
	{ 442	,8	,1	, &fEM_R7UI76RIM},	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{ 443	,8	,1	, &fEM_R7UI77RIM},	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{ 444	,3	,1	, &iEM_TERBB1},	//(TERBB1) Неисправности  ББ1
	{ 445	,8	,1	, &fEM_A1MC02RC1},	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
	{ 446	,8	,1	, &fEM_A1MV02RC1},	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
	{ 447	,3	,1	, &iEM_TERBB2},	//(TERBB2) Неисправности  ББ2
	{ 448	,8	,1	, &fEM_B1MC02RC1},	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
	{ 449	,8	,1	, &fEM_B1MV02RC1},	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
	{ 450	,3	,1	, &iEM_TERRB2},	//(TERRB2) Неисправности  РБ2
	{ 451	,8	,1	, &fEM_B2MC02RC1},	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
	{ 452	,8	,1	, &fEM_B2MV02RC1},	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
	{ 453	,3	,1	, &iEM_TERRB1},	//(TERRB1) Неисправности  РБ1
	{ 454	,8	,1	, &fEM_A2MC02RC1},	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
	{ 455	,8	,1	, &fEM_A2MV02RC1},	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
	{ 456	,3	,1	, &iEM_TERIS2},	//(TERIS2) Неисправности  ИС2
	{ 457	,8	,1	, &fEM_B3MC02RC1},	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
	{ 458	,8	,1	, &fEM_B3MV02RC1},	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
	{ 459	,3	,1	, &iEM_TERIS1},	//(TERIS1) Неисправности  ИС1
	{ 460	,8	,1	, &fEM_A3MC02RC1},	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
	{ 461	,8	,1	, &fEM_A3MV02RC1},	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
	{ 462	,3	,1	, &iEM_TERA1IE04LDU},	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
	{ 463	,3	,1	, &iEM_TERA1IE03LDU},	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
	{ 464	,8	,1	, &fEM_A1MC01RC1},	//(A1MC01RC1) Заданная координата  ББ1 от ИС
	{ 465	,3	,1	, &iEM_TERB1IE03LDU},	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
	{ 466	,3	,1	, &iEM_TERB1IE04LDU},	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
	{ 467	,8	,1	, &fEM_B1MC01RC1},	//(B1MC01RC1) Заданная координата ББ2 от ИС
	{ 468	,8	,1	, &fEM_B1MV01RC1},	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
	{ 469	,8	,1	, &fEM_B2MC01RC1},	//(B2MC01RC1) Заданная координата РБ2 от ИС
	{ 470	,8	,1	, &fEM_B2MV01RC1},	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
	{ 471	,8	,1	, &fEM_A3MC01RC1},	//(A3MC01RC1) Заданная координата ИС1 от ИС
	{ 472	,8	,1	, &fEM_A3MV01RC1},	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
	{ 473	,8	,1	, &fEM_B3MC01RC1},	//(B3MC01RC1) Заданная координата ИС2 от ИС
	{ 474	,8	,1	, &fEM_B3MV01RC1},	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
	{ 475	,3	,1	, &iEM_TERA2SS21LIM},	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
	{ 476	,3	,1	, &iEM_TERA2SS12LIM},	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
	{ 477	,3	,1	, &iEM_TERR6SS21LIM},	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
	{ 478	,3	,1	, &iEM_TERA2VP82LIM},	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
	{ 479	,3	,1	, &iEM_TERA2SS11LIM},	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
	{ 480	,3	,1	, &iEM_TERB3SS21LIM},	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
	{ 481	,3	,1	, &iEM_TERA0MT01RIM},	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
	{ 482	,3	,1	, &iEM_TERB0MT01RIM},	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
	{ 483	,3	,1	, &iEM_TERA2SP01RIM},	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
	{ 484	,3	,1	, &iEM_TERB2SP01RIM},	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
	{ 485	,3	,1	, &iEM_TERB3SP02RIM},	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{ 486	,3	,1	, &iEM_TERA3SC01RIM},	//(TERA3SC01RIM) Искажение: Координата штока ИС1
	{ 487	,3	,1	, &iEM_TERA3VP81LIM},	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
	{ 488	,3	,1	, &iEM_TERA2SC01RIM},	//(TERA2SC01RIM) Искажение: Координата штока РБ1
	{ 489	,3	,1	, &iEM_TERA2SS33LIM},	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{ 490	,3	,1	, &iEM_TERA3SS21LIM},	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
	{ 491	,3	,1	, &iEM_TERA3SS33LIM},	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{ 492	,3	,1	, &iEM_TERA3SS31LIM},	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{ 493	,3	,1	, &iEM_TERB3SS31LIM},	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{ 494	,3	,1	, &iEM_TERB3SS33LIM},	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{ 495	,3	,1	, &iEM_TERB3SC01RIM},	//(TERB3SC01RIM) Искажение: Координата штока ИС2
	{ 496	,3	,1	, &iEM_TERA3SS11LIM},	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
	{ 497	,3	,1	, &iEM_TERB3SS11LIM},	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
	{ 498	,3	,1	, &iEM_TERR6IS64LIM},	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
	{ 499	,3	,1	, &iEM_TERB3SS22LIM},	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
	{ 500	,3	,1	, &iEM_TERA3SS22LIM},	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
	{ 501	,3	,1	, &iEM_TERA3SP02RIM},	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{ 502	,3	,1	, &iEM_TERR6IS62LIM},	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
	{ 503	,3	,1	, &iEM_TERR6IS66LIM},	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 504	,3	,1	, &iEM_TERR6IS67LIM},	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 505	,3	,1	, &iEM_TERA0VP81LIM},	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
	{ 506	,3	,1	, &iEM_TERB0VP81LIM},	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
	{ 507	,3	,1	, &iEM_TERR0VP81LIM},	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{ 508	,3	,1	, &iEM_TERR6IS68LIM},	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{ 509	,3	,1	, &iEM_TERR7SI74RIM},	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
	{ 510	,3	,1	, &iEM_TERA5SS21LIM},	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
	{ 511	,3	,1	, &iEM_TERB5SS11LIM},	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
	{ 512	,3	,1	, &iEM_TERA5SS11LIM},	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{ 513	,3	,1	, &iEM_TERA9SS11LIM},	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
	{ 514	,3	,1	, &iEM_TERB2SS11LIM},	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
	{ 515	,3	,1	, &iEM_TERB2SS12LIM},	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
	{ 516	,3	,1	, &iEM_TERB2SS21LIM},	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
	{ 517	,3	,1	, &iEM_TERR3SS11LIM},	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
	{ 518	,3	,1	, &iEM_TERB2SC01RIM},	//(TERB2SC01RIM) Искажение: Координата штока РБ2
	{ 519	,3	,1	, &iEM_TERR3SS21LIM},	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
	{ 520	,3	,1	, &iEM_TERR5SS11LIM},	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
	{ 521	,3	,1	, &iEM_TERA4SS11LIM},	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
	{ 522	,3	,1	, &iEM_TERR1SS11LIM},	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
	{ 523	,3	,1	, &iEM_TERR1SS21LIM},	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
	{ 524	,3	,1	, &iEM_TERR2SS11LIM},	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
	{ 525	,3	,1	, &iEM_TERR2SS21LIM},	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
	{ 526	,3	,1	, &iEM_TERA4VP82LIM},	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
	{ 527	,3	,1	, &iEM_TERB4SS21LIM},	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
	{ 528	,3	,1	, &iEM_TERR5SS21LIM},	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
	{ 529	,3	,1	, &iEM_TERB6SS21LIM},	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
	{ 530	,3	,1	, &iEM_TERB4SS11LIM},	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
	{ 531	,3	,1	, &iEM_TERA4SS21LIM},	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
	{ 532	,3	,1	, &iEM_TERA6MS11LIM},	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
	{ 533	,3	,1	, &iEM_TERA6SS21LIM},	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
	{ 534	,3	,1	, &iEM_TERB6SS11LIM},	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
	{ 535	,3	,1	, &iEM_TERR4SS11LIM},	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
	{ 536	,3	,1	, &iEM_TERR4MS21LIM},	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
	{ 537	,3	,1	, &iEM_TERR4SS12LIM},	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
	{ 538	,3	,1	, &iEM_TERR4SS22LIM},	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
	{ 539	,3	,1	, &iEM_TERR8SS11LIM},	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
	{ 540	,3	,1	, &iEM_TERB8SC01RIM},	//(TERB8SC01RIM) Искажение: Координата АЗ2
	{ 541	,3	,1	, &iEM_TERA8SC01RIM},	//(TERA8SC01RIM) Искажение: Координата ДС2
	{ 542	,3	,1	, &iEM_TERB8SS12LIM},	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
	{ 543	,3	,1	, &iEM_TERA8SS12LIM},	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
	{ 544	,3	,1	, &iEM_TERB8SS22LIM},	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
	{ 545	,3	,1	, &iEM_TERA8SS22LIM},	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
	{ 546	,3	,1	, &iEM_TERA9SS21LIM},	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
	{ 547	,3	,1	, &iEM_TERB9SS21LIM},	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
	{ 548	,3	,1	, &iEM_TERB9SS11LIM},	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
	{ 549	,3	,1	, &iEM_TERB5SS21LIM},	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
	{ 550	,3	,1	, &iEM_TERA1SS21LIM},	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
	{ 551	,3	,1	, &iEM_TERA1SS11LIM},	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
	{ 552	,3	,1	, &iEM_TERA1SC01RIM},	//(TERA1SC01RIM) Искажение: Координата штока ББ1
	{ 553	,3	,1	, &iEM_TERA1SS12LIM},	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
	{ 554	,3	,1	, &iEM_TERB1SS21LIM},	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
	{ 555	,3	,1	, &iEM_TERB1SS11LIM},	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
	{ 556	,3	,1	, &iEM_TERB1MC01RIM},	//(TERB1MC01RIM) Искажение: Координата штока ББ2
	{ 557	,3	,1	, &iEM_TERB1SS12LIM},	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
	{ 558	,3	,1	, &iEM_TERTLG},	//(TERTLG) Неисправности  тележки от ИС
	{ 559	,8	,1	, &fEM_R4MC01RC1},	//(R4MC01RC1) Заданная координата тележки от ИС
	{ 560	,8	,1	, &fEM_R4MV01RC1},	//(R4MV01RC1) Заданная скорость тележки от ИС
	{ 561	,3	,1	, &iEM_TERMAZ2},	//(TERMAZ2) Неисправности АЗ2 от ИС
	{ 562	,8	,1	, &fEM_B8MC01RC1},	//(B8MC01RC1) Заданная координата АЗ2 от ИС
	{ 563	,8	,1	, &fEM_B8MV01RC1},	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
	{ 564	,3	,1	, &iEM_TERDS2},	//(TERDS2) Неисправности ДС2 от ИС
	{ 565	,8	,1	, &fEM_A8MC01RC1},	//(A8MC01RC1) Заданная координата ДС2 от ИС
	{ 566	,8	,1	, &fEM_A8MV01RC1},	//(A8MV01RC1) Заданная скорость ДС2 от ИС
	{ 567	,3	,1	, &iEM_TERBZ1},	//(TERBZ1) Неисправности БЗ1
	{ 568	,8	,1	, &fEM_A6MC01RC1},	//(A6MC01RC1) Заданная координата БЗ1 от ИС
	{ 569	,8	,1	, &fEM_A6MV01RC1},	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
	{ 570	,3	,1	, &iEM_TERBZ2},	//(TERBZ2) Неисправности БЗ2
	{ 571	,8	,1	, &fEM_B6MC01RC1},	//(B6MC01RC1) Заданная координата БЗ2 от ИС
	{ 572	,8	,1	, &fEM_B6MV01RC1},	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
	{ 573	,1	,1	, &lEM_R3AD10LC1},	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
	{ 574	,1	,1	, &lEM_R3AD20LC1},	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
	{ 575	,1	,1	, &lEM_R6AD10LC1},	//(R6AD10LC1) Выкатить кран-балку от ИС
	{ 576	,1	,1	, &lEM_R5AD10LC1},	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
	{ 577	,1	,1	, &lEM_R5AD20LC1},	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
	{ 578	,3	,1	, &iEM_TERMDZ2},	//(TERMDZ2) Неисправности МДЗ2
	{ 579	,8	,1	, &fEM_R2MC01RC1},	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
	{ 580	,8	,1	, &fEM_R2MV01RC1},	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
	{ 581	,3	,1	, &iEM_TERMDZ1},	//(TERMDZ1) Неисправности МДЗ1
	{ 582	,8	,1	, &fEM_R1MC01RC1},	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
	{ 583	,8	,1	, &fEM_R1MV01RC1},	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
	{ 584	,3	,1	, &iEM_TERNL1},	//(TERNL1) Неисправности НЛ1
	{ 585	,8	,1	, &fEM_A5MC01RC1},	//(A5MC01RC1) Заданная координата НЛ1 от ИС
	{ 586	,8	,1	, &fEM_A5MV01RC1},	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
	{ 587	,3	,1	, &iEM_TERNL2},	//(TERNL2) Неисправности НЛ2
	{ 588	,8	,1	, &fEM_B5MC01RC1},	//(B5MC01RC1) Заданная координата НЛ2 от ИС
	{ 589	,8	,1	, &fEM_B5MV01RC1},	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
	{ 590	,1	,1	, &lEM_R8AD10LC1},	//(R8AD10LC1) Установить аварийный НИ от ИС
	{ 591	,8	,1	, &fEM_A1UC08RIM},	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
	{ 592	,8	,1	, &fEM_A2UC08RIM},	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
	{ 593	,8	,1	, &fEM_A3UC08RIM},	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
	{ 594	,3	,1	, &iEM_TERB2SS33LIM},	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{ 595	,3	,1	, &iEM_TERA1VP81LIM},	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
	{ 596	,3	,1	, &iEM_TERB1VP81LIM},	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
	{ 597	,8	,1	, &fEM_A0UT03RSP},	//(A0UT03RSP) Стартовая  температура АЗ1 град
	{ 598	,8	,1	, &fEM_A0UR01RSP},	//(A0UR01RSP) Стартовая  реактивность АЗ1
	{ 599	,8	,1	, &fEM_A0UR02RSP},	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
	{ 600	,8	,1	, &fEM_B0UT03RSP},	//(B0UT03RSP) Стартовая  температура АЗ2 град
	{ 601	,8	,1	, &fEM_A1MC01RSP},	//(A1MC01RSP) Стартовая координата  ББ1
	{ 602	,8	,1	, &fEM_A1MC02RSP},	//(A1MC02RSP) Стартовая координата штока ББ1
	{ 603	,8	,1	, &fEM_A1MV01RSP},	//(A1MV01RSP) Стартовая скорость движения  ББ1
	{ 604	,8	,1	, &fEM_A1MV02RSP},	//(A1MV02RSP) Стартовая скорость движения  ББ1
	{ 605	,8	,1	, &fEM_B1MC01RSP},	//(B1MC01RSP) Стартовая координата  ББ2
	{ 606	,8	,1	, &fEM_B1MV01RSP},	//(B1MV01RSP) Стартовая скорость движения  ББ2
	{ 607	,8	,1	, &fEM_B1MC02RSP},	//(B1MC02RSP) Стартовая координата штока ББ2
	{ 608	,8	,1	, &fEM_B1MV02RSP},	//(B1MV02RSP) Стартовая скорость движения  ББ2
	{ 609	,8	,1	, &fEM_A2MC01RC1},	//(A2MC01RC1) Заданная координата РБ1 от ИС
	{ 610	,8	,1	, &fEM_A2MV01RC1},	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
	{ 611	,8	,1	, &fEM_A2MC01RSP},	//(A2MC01RSP) Стартовая координата  РБ1
	{ 612	,8	,1	, &fEM_A2MV01RSP},	//(A2MV01RSP) Стартовая скорость движения  РБ1
	{ 613	,8	,1	, &fEM_A2MC02RSP},	//(A2MC02RSP) Стартовая координата штока РБ1
	{ 614	,8	,1	, &fEM_A2MV02RSP},	//(A2MV02RSP) Стартовая скорость движения  РБ1
	{ 615	,8	,1	, &fEM_B2MC01RSP},	//(B2MC01RSP) Стартовая координата  РБ2
	{ 616	,8	,1	, &fEM_B2MV01RSP},	//(B2MV01RSP) Стартовая скорость движения  РБ2
	{ 617	,8	,1	, &fEM_B2MC02RSP},	//(B2MC02RSP) Стартовая координата штока РБ2
	{ 618	,8	,1	, &fEM_B2MV02RSP},	//(B2MV02RSP) Стартовая скорость движения  РБ2
	{ 619	,8	,1	, &fEM_A3MC01RSP},	//(A3MC01RSP) Стартовая координата  ИС1
	{ 620	,8	,1	, &fEM_A3MV01RSP},	//(A3MV01RSP) Стартовая скорость движения  ИС1
	{ 621	,8	,1	, &fEM_A3MC02RSP},	//(A3MC02RSP) Стартовая координата штока ИС1
	{ 622	,8	,1	, &fEM_A3MV02RSP},	//(A3MV02RSP) Стартовая скорость движения  ИС1
	{ 623	,8	,1	, &fEM_B3MC01RSP},	//(B3MC01RSP) Стартовая координата  ИС2
	{ 624	,8	,1	, &fEM_B3MV01RSP},	//(B3MV01RSP) Стартовая скорость движения  ИС2
	{ 625	,8	,1	, &fEM_B3MC02RSP},	//(B3MC02RSP) Стартовая координата штока ИС2
	{ 626	,8	,1	, &fEM_B3MV02RSP},	//(B3MV02RSP) Стартовая скорость движения  ИС2
	{ 627	,8	,1	, &fEM_B8MC01RSP},	//(B8MC01RSP) Стартовая координата АЗ2
	{ 628	,8	,1	, &fEM_B8MV01RSP},	//(B8MV01RSP) Стартовая скорость АЗ2
	{ 629	,8	,1	, &fEM_A8MC01RSP},	//(A8MC01RSP) Стартовая координата ДС2
	{ 630	,8	,1	, &fEM_A8MV01RSP},	//(A8MV01RSP) Стартовая скорость ДС2
	{ 631	,8	,1	, &fEM_A6MC01RSP},	//(A6MC01RSP) Стартовая координата БЗ1
	{ 632	,8	,1	, &fEM_A6MV01RSP},	//(A6MV01RSP) Стартовая скорость БЗ1
	{ 633	,8	,1	, &fEM_B6MC01RSP},	//(B6MC01RSP) Стартовая координата БЗ2
	{ 634	,8	,1	, &fEM_B6MV01RSP},	//(B6MV01RSP) Стартовая скорость БЗ2
	{ 635	,8	,1	, &fEM_R3UC01RSP},	//(R3UC01RSP) Стартовая координата Гомогенных дверей
	{ 636	,8	,1	, &fEM_R3UV01RSP},	//(R3UV01RSP) Стартовая скорость Гомогенных дверей
	{ 637	,8	,1	, &fEM_R5UC01RSP},	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
	{ 638	,8	,1	, &fEM_R5UV01RSP},	//(R5UV01RSP) Стартовая скорость Ворот отстойной зоны
	{ 639	,8	,1	, &fEM_R6UC01RSP},	//(R6UC01RSP) Стартовая координата Кран-балки
	{ 640	,8	,1	, &fEM_R6UV01RSP},	//(R6UV01RSP) Стартовая скорость Кран-балки
	{ 641	,8	,1	, &fEM_R2MC01RSP},	//(R2MC01RSP) Стартовая координата МДЗ2
	{ 642	,8	,1	, &fEM_R2MV01RSP},	//(R2MV01RSP) Стартовая скорость МДЗ2
	{ 643	,8	,1	, &fEM_R1MC01RSP},	//(R1MC01RSP) Стартовая координата МДЗ1
	{ 644	,8	,1	, &fEM_R1MV01RSP},	//(R1MV01RSP) Стартовая скорость МДЗ1
	{ 645	,8	,1	, &fEM_A5MC01RSP},	//(A5MC01RSP) Стартовая координата НЛ1
	{ 646	,8	,1	, &fEM_A5MV01RSP},	//(A5MV01RSP) Стартовая скорость НЛ1
	{ 647	,8	,1	, &fEM_B5MC01RSP},	//(B5MC01RSP) Стартовая координата НЛ2
	{ 648	,8	,1	, &fEM_B5MV01RSP},	//(B5MV01RSP) Стартовая скорость НЛ2
	{ 649	,8	,1	, &fEM_A9MC01RSP},	//(A9MC01RSP) Стартовая координата НИ ДС1
	{ 650	,8	,1	, &fEM_A9MV01RSP},	//(A9MV01RSP) Стартовая скорость НИ ДС1
	{ 651	,8	,1	, &fEM_B9MC01RSP},	//(B9MC01RSP) Стартовая координата НИ ДС2
	{ 652	,8	,1	, &fEM_B9MV01RSP},	//(B9MV01RSP) Стартовая скорость НИ ДС2
	{ 653	,8	,1	, &fEM_A4MC01RSP},	//(A4MC01RSP) Стартовая координата НИ1
	{ 654	,8	,1	, &fEM_A4MV01RSP},	//(A4MV01RSP) Стартовая скорость НИ1
	{ 655	,8	,1	, &fEM_B4MC01RSP},	//(B4MC01RSP) Стартовая координата НИ2
	{ 656	,8	,1	, &fEM_B4MV01RSP},	//(B4MV01RSP) Стартовая скорость НИ2
	{ 657	,8	,1	, &fEM_R4MC01RSP},	//(R4MC01RSP) Стартовая координата тележки
	{ 658	,8	,1	, &fEM_R4MV01RSP},	//(R4MV01RSP) Стартовая скорость тележки
	{ 659	,8	,1	, &fEM_A1MV01RC1},	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
	{ 660	,3	,1	, &iEM_TERB7MS31LIM},	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{ 661	,3	,1	, &iEM_TERA7MS31LIM},	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{ 662	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 см
	{ 663	,3	,1	, &iEM_TERA6VS12LIM},	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{ 664	,3	,1	, &iEM_TERA6VS22LIM},	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{ 665	,3	,1	, &iEM_TERB6VS12LIM},	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{ 666	,3	,1	, &iEM_TERB6VS22LIM},	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{ 667	,3	,1	, &iEM_TERA5VS22LIM},	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
	{ 668	,3	,1	, &iEM_TERA5VS12LIM},	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
	{ 669	,3	,1	, &iEM_TERB5VS12LIM},	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
	{ 670	,3	,1	, &iEM_TERB5VS22LIM},	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
	{ 671	,3	,1	, &iEM_TERR1VS12LIM},	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
	{ 672	,3	,1	, &iEM_TERR1VS22LIM},	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
	{ 673	,3	,1	, &iEM_TERR2VS12LIM},	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
	{ 674	,3	,1	, &iEM_TERR2VS22LIM},	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
	{ 675	,3	,1	, &iEM_TERR4VS12LDU},	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{ 676	,3	,1	, &iEM_TERR4VS22LDU},	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{ 677	,8	,1	, &fEM_R4UC23RIM},	//(R4UC23RIM) Y-координата АЗ1
	{ 678	,8	,1	, &fEM_A0UX13RSS},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{ 679	,8	,1	, &fEM_A0UX14RSS},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{ 680	,8	,1	, &fEM_A0UX15RSS},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{ 681	,8	,1	, &fEM_R7UX13RSS},	//(R7UX13RSS) X-координата камеры R7IN51
	{ 682	,8	,1	, &fEM_R7UX14RSS},	//(R7UX14RSS) X-координата камеры R7IN52
	{ 683	,8	,1	, &fEM_R7UX15RSS},	//(R7UX15RSS) X-координата камеры R7IN53
	{ 684	,8	,1	, &fEM_R7UY13RSS},	//(R7UY13RSS) Y-координата камеры R7IN51
	{ 685	,8	,1	, &fEM_R7UY14RSS},	//(R7UY14RSS) Y-координата камеры R7IN52
	{ 686	,8	,1	, &fEM_R7UY15RSS},	//(R7UY15RSS) Y-координата камеры R7IN53
	{ 687	,8	,1	, &fEM_R7UX16RSS},	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
	{ 688	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 689	,8	,1	, &internal1_m897_Chim0},	//(internal1_m897_Chim0) измеренная частота импульсов камеры Гц
	{ 690	,8	,1	, &internal1_m887_Chim0},	//(internal1_m887_Chim0) измеренная частота импульсов камеры Гц
	{ 691	,8	,1	, &internal1_m879_Chim0},	//(internal1_m879_Chim0) измеренная частота импульсов камеры Гц
	{ 692	,1	,1	, &internal1_m834_Out10},	//(internal1_m834_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 693	,1	,1	, &internal1_m833_Out10},	//(internal1_m833_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 694	,1	,1	, &internal1_m1017_Out10},	//(internal1_m1017_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 695	,1	,1	, &internal1_m1016_Out10},	//(internal1_m1016_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 696	,1	,1	, &internal1_m1015_Out10},	//(internal1_m1015_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 697	,1	,1	, &internal1_m1014_Out10},	//(internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 698	,1	,1	, &internal1_m693_Out10},	//(internal1_m693_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 699	,1	,1	, &internal1_m692_Out10},	//(internal1_m692_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 700	,1	,1	, &internal1_m671_Out10},	//(internal1_m671_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 701	,1	,1	, &internal1_m670_Out10},	//(internal1_m670_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 702	,1	,1	, &internal1_m691_Out10},	//(internal1_m691_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 703	,1	,1	, &internal1_m690_Out10},	//(internal1_m690_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 704	,1	,1	, &internal1_m669_Out10},	//(internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 705	,1	,1	, &internal1_m668_Out10},	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 706	,1	,1	, &internal1_m529_Out10},	//(internal1_m529_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 707	,1	,1	, &internal1_m545_Out10},	//(internal1_m545_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 708	,1	,1	, &internal1_m411_Out10},	//(internal1_m411_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 709	,1	,1	, &internal1_m488_q0},	//(internal1_m488_q0) q0 - внутренний параметр
	{ 710	,1	,1	, &internal1_m489_q0},	//(internal1_m489_q0) q0 - внутренний параметр
	{ 711	,1	,1	, &internal1_m474_q0},	//(internal1_m474_q0) q0 - внутренний параметр
	{ 712	,1	,1	, &internal1_m475_q0},	//(internal1_m475_q0) q0 - внутренний параметр
	{ 713	,8	,1	, &internal1_m644_tx},	//(internal1_m644_tx) tx - время накопленное сек
	{ 714	,18	,1	, &internal1_m644_y0},	//(internal1_m644_y0) y0
	{ 715	,8	,1	, &internal1_m632_tx},	//(internal1_m632_tx) tx - время накопленное сек
	{ 716	,18	,1	, &internal1_m632_y0},	//(internal1_m632_y0) y0
	{ 717	,8	,1	, &internal1_m618_tx},	//(internal1_m618_tx) tx - время накопленное сек
	{ 718	,18	,1	, &internal1_m618_y0},	//(internal1_m618_y0) y0
	{ 719	,8	,1	, &internal1_m616_tx},	//(internal1_m616_tx) tx - время накопленное сек
	{ 720	,18	,1	, &internal1_m616_y0},	//(internal1_m616_y0) y0
	{ 721	,1	,1	, &internal1_m208_Out10},	//(internal1_m208_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 722	,1	,1	, &internal1_m226_Out10},	//(internal1_m226_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 723	,1	,1	, &internal1_m41_Out10},	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 724	,1	,1	, &internal1_m56_Out10},	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 725	,1	,1	, &internal1_m988_Out10},	//(internal1_m988_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 726	,1	,1	, &internal1_m985_Out10},	//(internal1_m985_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 727	,1	,1	, &internal1_m984_Out10},	//(internal1_m984_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 728	,8	,1	, &internal1_m987_Xtek0},	//(internal1_m987_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 729	,8	,1	, &internal1_m970_Xtek0},	//(internal1_m970_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 730	,1	,1	, &internal1_m971_Out10},	//(internal1_m971_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 731	,1	,1	, &internal1_m968_Out10},	//(internal1_m968_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 732	,1	,1	, &internal1_m967_Out10},	//(internal1_m967_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 733	,1	,1	, &internal1_m1055_Out10},	//(internal1_m1055_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 734	,1	,1	, &internal1_m1036_Out10},	//(internal1_m1036_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 735	,1	,1	, &internal1_m1035_Out10},	//(internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 736	,1	,1	, &internal1_m1034_Out10},	//(internal1_m1034_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 737	,1	,1	, &internal1_m855_Out10},	//(internal1_m855_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 738	,1	,1	, &internal1_m857_Out10},	//(internal1_m857_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 739	,1	,1	, &internal1_m854_Out10},	//(internal1_m854_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 740	,1	,1	, &internal1_m856_Out10},	//(internal1_m856_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 741	,1	,1	, &internal1_m830_Out10},	//(internal1_m830_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 742	,1	,1	, &internal1_m831_Out10},	//(internal1_m831_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 743	,1	,1	, &internal1_m829_Out10},	//(internal1_m829_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 744	,1	,1	, &internal1_m828_Out10},	//(internal1_m828_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 745	,1	,1	, &internal1_m1050_Out10},	//(internal1_m1050_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 746	,1	,1	, &internal1_m1002_Out10},	//(internal1_m1002_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 747	,1	,1	, &internal1_m1001_Out10},	//(internal1_m1001_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 748	,1	,1	, &internal1_m1000_Out10},	//(internal1_m1000_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 749	,1	,1	, &internal1_m999_Out10},	//(internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 750	,1	,1	, &internal1_m1051_Out10},	//(internal1_m1051_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 751	,1	,1	, &internal1_m1032_Out10},	//(internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 752	,1	,1	, &internal1_m832_Out10},	//(internal1_m832_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 753	,1	,1	, &internal1_m1033_Out10},	//(internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 754	,1	,1	, &internal1_m1031_Out10},	//(internal1_m1031_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 755	,1	,1	, &internal1_m1052_Out10},	//(internal1_m1052_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 756	,1	,1	, &internal1_m1030_Out10},	//(internal1_m1030_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 757	,1	,1	, &internal1_m1013_Out10},	//(internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 758	,1	,1	, &internal1_m998_Out10},	//(internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 759	,1	,1	, &internal1_m546_Out10},	//(internal1_m546_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 760	,8	,1	, &internal1_m421_Xtek0},	//(internal1_m421_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 761	,1	,1	, &internal1_m412_Out10},	//(internal1_m412_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 762	,1	,1	, &internal1_m414_Out10},	//(internal1_m414_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 763	,1	,1	, &internal1_m413_Out10},	//(internal1_m413_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 764	,1	,1	, &internal1_m870_Out10},	//(internal1_m870_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 765	,1	,1	, &internal1_m871_Out10},	//(internal1_m871_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 766	,1	,1	, &internal1_m869_Out10},	//(internal1_m869_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 767	,1	,1	, &internal1_m1054_Out10},	//(internal1_m1054_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 768	,1	,1	, &internal1_m706_Out10},	//(internal1_m706_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 769	,1	,1	, &internal1_m707_Out10},	//(internal1_m707_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 770	,1	,1	, &internal1_m704_Out10},	//(internal1_m704_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 771	,1	,1	, &internal1_m705_Out10},	//(internal1_m705_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 772	,1	,1	, &internal1_m562_Out10},	//(internal1_m562_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 773	,1	,1	, &internal1_m561_Out10},	//(internal1_m561_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 774	,8	,1	, &internal1_m851_Xtek0},	//(internal1_m851_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 775	,8	,1	, &internal1_m853_Xtek0},	//(internal1_m853_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 776	,1	,1	, &internal1_m703_Out10},	//(internal1_m703_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 777	,1	,1	, &internal1_m687_Out10},	//(internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 778	,1	,1	, &internal1_m667_Out10},	//(internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 779	,1	,1	, &internal1_m686_Out10},	//(internal1_m686_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 780	,1	,1	, &internal1_m666_Out10},	//(internal1_m666_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 781	,1	,1	, &internal1_m339_Out10},	//(internal1_m339_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 782	,1	,1	, &internal1_m338_Out10},	//(internal1_m338_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 783	,1	,1	, &internal1_m323_Out10},	//(internal1_m323_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 784	,1	,1	, &internal1_m322_Out10},	//(internal1_m322_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 785	,1	,1	, &internal1_m563_Out10},	//(internal1_m563_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 786	,1	,1	, &internal1_m352_Out10},	//(internal1_m352_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 787	,8	,1	, &internal1_m336_Xtek0},	//(internal1_m336_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 788	,1	,1	, &internal1_m351_Out10},	//(internal1_m351_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 789	,1	,1	, &internal1_m349_Out10},	//(internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 790	,8	,1	, &internal1_m329_Xtek0},	//(internal1_m329_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 791	,1	,1	, &internal1_m350_Out10},	//(internal1_m350_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 792	,1	,1	, &internal1_m321_Out10},	//(internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 793	,1	,1	, &internal1_m337_Out10},	//(internal1_m337_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 794	,1	,1	, &internal1_m433_Out10},	//(internal1_m433_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 795	,8	,1	, &internal1_m434_Xtek0},	//(internal1_m434_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 796	,1	,1	, &internal1_m432_Out10},	//(internal1_m432_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 797	,1	,1	, &internal1_m431_Out10},	//(internal1_m431_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 798	,1	,1	, &internal1_m430_Out10},	//(internal1_m430_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 799	,1	,1	, &internal1_m1053_Out10},	//(internal1_m1053_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 800	,1	,1	, &internal1_m150_Out10},	//(internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 801	,1	,1	, &internal1_m149_Out10},	//(internal1_m149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 802	,3	,1	, &internal1_m197_tx},	//(internal1_m197_tx) tx - внутренний параметр
	{ 803	,3	,1	, &internal1_m25_tx},	//(internal1_m25_tx) tx - внутренний параметр
	{ 804	,1	,1	, &internal1_m480_Pav0},	//(internal1_m480_Pav0)  - Пер.аварийный выключатель механизма
	{ 805	,1	,1	, &internal1_m480_Zav0},	//(internal1_m480_Zav0)  - Зад.аварийный выключатель механизма
	{ 806	,1	,1	, &internal1_m480_Pv0},	//(internal1_m480_Pv0)  - Пер. выключатель механизма
	{ 807	,1	,1	, &internal1_m480_Zv0},	//(internal1_m480_Zv0)  - Зад. выключатель механизма
	{ 808	,1	,1	, &internal1_m480_RA00},	//(internal1_m480_RA00)  - последнее задание вперед
	{ 809	,1	,1	, &internal1_m480_RA10},	//(internal1_m480_RA10)  - последнее задание назад
	{ 810	,1	,1	, &internal1_m480_MyFirstEnterFlag},	//(internal1_m480_MyFirstEnterFlag) MyFirstEnterFlag
	{ 811	,1	,1	, &internal1_m492_Pav0},	//(internal1_m492_Pav0)  - Пер.аварийный выключатель механизма
	{ 812	,1	,1	, &internal1_m492_Zav0},	//(internal1_m492_Zav0)  - Зад.аварийный выключатель механизма
	{ 813	,1	,1	, &internal1_m492_Pv0},	//(internal1_m492_Pv0)  - Пер. выключатель механизма
	{ 814	,1	,1	, &internal1_m492_Zv0},	//(internal1_m492_Zv0)  - Зад. выключатель механизма
	{ 815	,1	,1	, &internal1_m492_RA00},	//(internal1_m492_RA00)  - последнее задание вперед
	{ 816	,1	,1	, &internal1_m492_RA10},	//(internal1_m492_RA10)  - последнее задание назад
	{ 817	,1	,1	, &internal1_m492_MyFirstEnterFlag},	//(internal1_m492_MyFirstEnterFlag) MyFirstEnterFlag
	{ 818	,1	,1	, &internal1_m479_Pav0},	//(internal1_m479_Pav0)  - Пер.аварийный выключатель механизма
	{ 819	,1	,1	, &internal1_m479_Zav0},	//(internal1_m479_Zav0)  - Зад.аварийный выключатель механизма
	{ 820	,1	,1	, &internal1_m479_Pv0},	//(internal1_m479_Pv0)  - Пер. выключатель механизма
	{ 821	,1	,1	, &internal1_m479_Zv0},	//(internal1_m479_Zv0)  - Зад. выключатель механизма
	{ 822	,1	,1	, &internal1_m479_RA00},	//(internal1_m479_RA00)  - последнее задание вперед
	{ 823	,1	,1	, &internal1_m479_RA10},	//(internal1_m479_RA10)  - последнее задание назад
	{ 824	,1	,1	, &internal1_m479_MyFirstEnterFlag},	//(internal1_m479_MyFirstEnterFlag) MyFirstEnterFlag
	{ 825	,1	,1	, &internal1_m623_Pav0},	//(internal1_m623_Pav0)  - Пер.аварийный выключатель механизма
	{ 826	,1	,1	, &internal1_m623_Zav0},	//(internal1_m623_Zav0)  - Зад.аварийный выключатель механизма
	{ 827	,1	,1	, &internal1_m623_Pv0},	//(internal1_m623_Pv0)  - Пер. выключатель механизма
	{ 828	,1	,1	, &internal1_m623_Zv0},	//(internal1_m623_Zv0)  - Зад. выключатель механизма
	{ 829	,1	,1	, &internal1_m623_RA00},	//(internal1_m623_RA00)  - последнее задание вперед
	{ 830	,1	,1	, &internal1_m623_RA10},	//(internal1_m623_RA10)  - последнее задание назад
	{ 831	,1	,1	, &internal1_m623_MyFirstEnterFlag},	//(internal1_m623_MyFirstEnterFlag) MyFirstEnterFlag
	{ 832	,1	,1	, &internal1_m620_Pav0},	//(internal1_m620_Pav0)  - Пер.аварийный выключатель механизма
	{ 833	,1	,1	, &internal1_m620_Zav0},	//(internal1_m620_Zav0)  - Зад.аварийный выключатель механизма
	{ 834	,1	,1	, &internal1_m620_Pv0},	//(internal1_m620_Pv0)  - Пер. выключатель механизма
	{ 835	,1	,1	, &internal1_m620_Zv0},	//(internal1_m620_Zv0)  - Зад. выключатель механизма
	{ 836	,1	,1	, &internal1_m620_RA00},	//(internal1_m620_RA00)  - последнее задание вперед
	{ 837	,1	,1	, &internal1_m620_RA10},	//(internal1_m620_RA10)  - последнее задание назад
	{ 838	,1	,1	, &internal1_m620_MyFirstEnterFlag},	//(internal1_m620_MyFirstEnterFlag) MyFirstEnterFlag
	{ 839	,1	,1	, &internal1_m606_Pav0},	//(internal1_m606_Pav0)  - Пер.аварийный выключатель механизма
	{ 840	,1	,1	, &internal1_m606_Zav0},	//(internal1_m606_Zav0)  - Зад.аварийный выключатель механизма
	{ 841	,1	,1	, &internal1_m606_Pv0},	//(internal1_m606_Pv0)  - Пер. выключатель механизма
	{ 842	,1	,1	, &internal1_m606_Zv0},	//(internal1_m606_Zv0)  - Зад. выключатель механизма
	{ 843	,1	,1	, &internal1_m606_RA00},	//(internal1_m606_RA00)  - последнее задание вперед
	{ 844	,1	,1	, &internal1_m606_RA10},	//(internal1_m606_RA10)  - последнее задание назад
	{ 845	,1	,1	, &internal1_m606_MyFirstEnterFlag},	//(internal1_m606_MyFirstEnterFlag) MyFirstEnterFlag
	{ 846	,1	,1	, &internal1_m605_Pav0},	//(internal1_m605_Pav0)  - Пер.аварийный выключатель механизма
	{ 847	,1	,1	, &internal1_m605_Zav0},	//(internal1_m605_Zav0)  - Зад.аварийный выключатель механизма
	{ 848	,1	,1	, &internal1_m605_Pv0},	//(internal1_m605_Pv0)  - Пер. выключатель механизма
	{ 849	,1	,1	, &internal1_m605_Zv0},	//(internal1_m605_Zv0)  - Зад. выключатель механизма
	{ 850	,1	,1	, &internal1_m605_RA00},	//(internal1_m605_RA00)  - последнее задание вперед
	{ 851	,1	,1	, &internal1_m605_RA10},	//(internal1_m605_RA10)  - последнее задание назад
	{ 852	,1	,1	, &internal1_m605_MyFirstEnterFlag},	//(internal1_m605_MyFirstEnterFlag) MyFirstEnterFlag
	{ 853	,8	,1	, &internal1_m652_y0},	//(internal1_m652_y0) y0 - внутренний параметр
	{ 854	,8	,1	, &internal1_m816_Chim0},	//(internal1_m816_Chim0) измеренная частота импульсов камеры Гц
	{ 855	,8	,1	, &internal1_m807_Chim0},	//(internal1_m807_Chim0) измеренная частота импульсов камеры Гц
	{ 856	,8	,1	, &internal1_m799_Chim0},	//(internal1_m799_Chim0) измеренная частота импульсов камеры Гц
	{ 857	,8	,1	, &internal1_m790_Chim0},	//(internal1_m790_Chim0) измеренная частота импульсов камеры Гц
	{ 858	,8	,1	, &internal1_m781_Chim0},	//(internal1_m781_Chim0) измеренная частота импульсов камеры Гц
	{ 859	,8	,1	, &internal1_m773_Chim0},	//(internal1_m773_Chim0) измеренная частота импульсов камеры Гц
	{ 860	,8	,1	, &internal1_m764_Chim0},	//(internal1_m764_Chim0) измеренная частота импульсов камеры Гц
	{ 861	,8	,1	, &internal1_m755_Chim0},	//(internal1_m755_Chim0) измеренная частота импульсов камеры Гц
	{ 862	,8	,1	, &internal1_m747_Chim0},	//(internal1_m747_Chim0) измеренная частота импульсов камеры Гц
	{ 863	,8	,1	, &internal1_m738_Chim0},	//(internal1_m738_Chim0) измеренная частота импульсов камеры Гц
	{ 864	,8	,1	, &internal1_m729_Chim0},	//(internal1_m729_Chim0) измеренная частота импульсов камеры Гц
	{ 865	,8	,1	, &internal1_m719_Chim0},	//(internal1_m719_Chim0) измеренная частота импульсов камеры Гц
	{ 866	,1	,1	, &internal1_m592_Pav0},	//(internal1_m592_Pav0)  - Пер.аварийный выключатель механизма
	{ 867	,1	,1	, &internal1_m592_Zav0},	//(internal1_m592_Zav0)  - Зад.аварийный выключатель механизма
	{ 868	,1	,1	, &internal1_m592_Pv0},	//(internal1_m592_Pv0)  - Пер. выключатель механизма
	{ 869	,1	,1	, &internal1_m592_Zv0},	//(internal1_m592_Zv0)  - Зад. выключатель механизма
	{ 870	,1	,1	, &internal1_m592_RA00},	//(internal1_m592_RA00)  - последнее задание вперед
	{ 871	,1	,1	, &internal1_m592_RA10},	//(internal1_m592_RA10)  - последнее задание назад
	{ 872	,1	,1	, &internal1_m592_MyFirstEnterFlag},	//(internal1_m592_MyFirstEnterFlag) MyFirstEnterFlag
	{ 873	,1	,1	, &internal1_m577_Pav0},	//(internal1_m577_Pav0)  - Пер.аварийный выключатель механизма
	{ 874	,1	,1	, &internal1_m577_Zav0},	//(internal1_m577_Zav0)  - Зад.аварийный выключатель механизма
	{ 875	,1	,1	, &internal1_m577_Pv0},	//(internal1_m577_Pv0)  - Пер. выключатель механизма
	{ 876	,1	,1	, &internal1_m577_Zv0},	//(internal1_m577_Zv0)  - Зад. выключатель механизма
	{ 877	,1	,1	, &internal1_m577_RA00},	//(internal1_m577_RA00)  - последнее задание вперед
	{ 878	,1	,1	, &internal1_m577_RA10},	//(internal1_m577_RA10)  - последнее задание назад
	{ 879	,1	,1	, &internal1_m577_MyFirstEnterFlag},	//(internal1_m577_MyFirstEnterFlag) MyFirstEnterFlag
	{ 880	,1	,1	, &internal1_m463_Pav0},	//(internal1_m463_Pav0)  - Пер.аварийный выключатель механизма
	{ 881	,1	,1	, &internal1_m463_Zav0},	//(internal1_m463_Zav0)  - Зад.аварийный выключатель механизма
	{ 882	,1	,1	, &internal1_m463_Pv0},	//(internal1_m463_Pv0)  - Пер. выключатель механизма
	{ 883	,1	,1	, &internal1_m463_Zv0},	//(internal1_m463_Zv0)  - Зад. выключатель механизма
	{ 884	,1	,1	, &internal1_m463_RA00},	//(internal1_m463_RA00)  - последнее задание вперед
	{ 885	,1	,1	, &internal1_m463_RA10},	//(internal1_m463_RA10)  - последнее задание назад
	{ 886	,1	,1	, &internal1_m463_MyFirstEnterFlag},	//(internal1_m463_MyFirstEnterFlag) MyFirstEnterFlag
	{ 887	,1	,1	, &internal1_m448_Pav0},	//(internal1_m448_Pav0)  - Пер.аварийный выключатель механизма
	{ 888	,1	,1	, &internal1_m448_Zav0},	//(internal1_m448_Zav0)  - Зад.аварийный выключатель механизма
	{ 889	,1	,1	, &internal1_m448_Pv0},	//(internal1_m448_Pv0)  - Пер. выключатель механизма
	{ 890	,1	,1	, &internal1_m448_Zv0},	//(internal1_m448_Zv0)  - Зад. выключатель механизма
	{ 891	,1	,1	, &internal1_m448_RA00},	//(internal1_m448_RA00)  - последнее задание вперед
	{ 892	,1	,1	, &internal1_m448_RA10},	//(internal1_m448_RA10)  - последнее задание назад
	{ 893	,1	,1	, &internal1_m448_MyFirstEnterFlag},	//(internal1_m448_MyFirstEnterFlag) MyFirstEnterFlag
	{ 894	,1	,1	, &internal1_m504_Pav0},	//(internal1_m504_Pav0)  - Пер.аварийный выключатель механизма
	{ 895	,1	,1	, &internal1_m504_Zav0},	//(internal1_m504_Zav0)  - Зад.аварийный выключатель механизма
	{ 896	,1	,1	, &internal1_m504_Pv0},	//(internal1_m504_Pv0)  - Пер. выключатель механизма
	{ 897	,1	,1	, &internal1_m504_Zv0},	//(internal1_m504_Zv0)  - Зад. выключатель механизма
	{ 898	,1	,1	, &internal1_m504_RA00},	//(internal1_m504_RA00)  - последнее задание вперед
	{ 899	,1	,1	, &internal1_m504_RA10},	//(internal1_m504_RA10)  - последнее задание назад
	{ 900	,1	,1	, &internal1_m504_MyFirstEnterFlag},	//(internal1_m504_MyFirstEnterFlag) MyFirstEnterFlag
	{ 901	,1	,1	, &internal1_m399_Pav0},	//(internal1_m399_Pav0)  - Пер.аварийный выключатель механизма
	{ 902	,1	,1	, &internal1_m399_Zav0},	//(internal1_m399_Zav0)  - Зад.аварийный выключатель механизма
	{ 903	,1	,1	, &internal1_m399_Pv0},	//(internal1_m399_Pv0)  - Пер. выключатель механизма
	{ 904	,1	,1	, &internal1_m399_Zv0},	//(internal1_m399_Zv0)  - Зад. выключатель механизма
	{ 905	,1	,1	, &internal1_m399_RA00},	//(internal1_m399_RA00)  - последнее задание вперед
	{ 906	,1	,1	, &internal1_m399_RA10},	//(internal1_m399_RA10)  - последнее задание назад
	{ 907	,1	,1	, &internal1_m399_MyFirstEnterFlag},	//(internal1_m399_MyFirstEnterFlag) MyFirstEnterFlag
	{ 908	,1	,1	, &internal1_m383_Pav0},	//(internal1_m383_Pav0)  - Пер.аварийный выключатель механизма
	{ 909	,1	,1	, &internal1_m383_Zav0},	//(internal1_m383_Zav0)  - Зад.аварийный выключатель механизма
	{ 910	,1	,1	, &internal1_m383_Pv0},	//(internal1_m383_Pv0)  - Пер. выключатель механизма
	{ 911	,1	,1	, &internal1_m383_Zv0},	//(internal1_m383_Zv0)  - Зад. выключатель механизма
	{ 912	,1	,1	, &internal1_m383_RA00},	//(internal1_m383_RA00)  - последнее задание вперед
	{ 913	,1	,1	, &internal1_m383_RA10},	//(internal1_m383_RA10)  - последнее задание назад
	{ 914	,1	,1	, &internal1_m383_MyFirstEnterFlag},	//(internal1_m383_MyFirstEnterFlag) MyFirstEnterFlag
	{ 915	,1	,1	, &internal1_m366_Pav0},	//(internal1_m366_Pav0)  - Пер.аварийный выключатель механизма
	{ 916	,1	,1	, &internal1_m366_Zav0},	//(internal1_m366_Zav0)  - Зад.аварийный выключатель механизма
	{ 917	,1	,1	, &internal1_m366_Pv0},	//(internal1_m366_Pv0)  - Пер. выключатель механизма
	{ 918	,1	,1	, &internal1_m366_Zv0},	//(internal1_m366_Zv0)  - Зад. выключатель механизма
	{ 919	,1	,1	, &internal1_m366_RA00},	//(internal1_m366_RA00)  - последнее задание вперед
	{ 920	,1	,1	, &internal1_m366_RA10},	//(internal1_m366_RA10)  - последнее задание назад
	{ 921	,1	,1	, &internal1_m366_MyFirstEnterFlag},	//(internal1_m366_MyFirstEnterFlag) MyFirstEnterFlag
	{ 922	,1	,1	, &internal1_m909_Pav0},	//(internal1_m909_Pav0)  - Пер.аварийный выключатель механизма
	{ 923	,1	,1	, &internal1_m909_Zav0},	//(internal1_m909_Zav0)  - Зад.аварийный выключатель механизма
	{ 924	,1	,1	, &internal1_m909_Pv0},	//(internal1_m909_Pv0)  - Пер. выключатель механизма
	{ 925	,1	,1	, &internal1_m909_Zv0},	//(internal1_m909_Zv0)  - Зад. выключатель механизма
	{ 926	,1	,1	, &internal1_m909_RA00},	//(internal1_m909_RA00)  - последнее задание вперед
	{ 927	,1	,1	, &internal1_m909_RA10},	//(internal1_m909_RA10)  - последнее задание назад
	{ 928	,1	,1	, &internal1_m909_MyFirstEnterFlag},	//(internal1_m909_MyFirstEnterFlag) MyFirstEnterFlag
	{ 929	,8	,1	, &internal1_m182_C1},	//(internal1_m182_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{ 930	,8	,1	, &internal1_m182_C2},	//(internal1_m182_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{ 931	,8	,1	, &internal1_m182_C3},	//(internal1_m182_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{ 932	,8	,1	, &internal1_m182_C4},	//(internal1_m182_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{ 933	,8	,1	, &internal1_m182_C5},	//(internal1_m182_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{ 934	,8	,1	, &internal1_m182_C6},	//(internal1_m182_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{ 935	,8	,1	, &internal1_m182_N20},	//(internal1_m182_N20) N20 - пред. концентрация нейтронов второй АЗ
	{ 936	,8	,6	, &internal1_m182_C0},	//(internal1_m182_C0) *C0 - пред. концентрация запаздывающих нейтронов
	{ 937	,1	,1	, &internal1_m182_ImpINI0},	//(internal1_m182_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{ 938	,1	,1	, &internal1_m182_MyFirstEnterFlag},	//(internal1_m182_MyFirstEnterFlag) MyFirstEnterFlag
	{ 939	,1	,1	, &internal1_m300_Ppv0},	//(internal1_m300_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 940	,1	,1	, &internal1_m300_Pav0},	//(internal1_m300_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 941	,1	,1	, &internal1_m300_Zav0},	//(internal1_m300_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 942	,1	,1	, &internal1_m300_RA00},	//(internal1_m300_RA00) RA00 - последнее задание вперед
	{ 943	,1	,1	, &internal1_m300_RA10},	//(internal1_m300_RA10) RA10 - последнее задание назад
	{ 944	,18	,1	, &internal1_m300_RA50},	//(internal1_m300_RA50) Ra50 - последнее задание скорости
	{ 945	,1	,1	, &internal1_m300_fls},	//(internal1_m300_fls)  fls - флаг одношагового режима
	{ 946	,1	,1	, &internal1_m300_flp},	//(internal1_m300_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 947	,1	,1	, &internal1_m300_MyFirstEnterFlag},	//(internal1_m300_MyFirstEnterFlag) MyFirstEnterFlag
	{ 948	,1	,1	, &internal1_m130_Ppv0},	//(internal1_m130_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 949	,1	,1	, &internal1_m130_Pav0},	//(internal1_m130_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 950	,1	,1	, &internal1_m130_Zav0},	//(internal1_m130_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 951	,1	,1	, &internal1_m130_RA00},	//(internal1_m130_RA00) RA00 - последнее задание вперед
	{ 952	,1	,1	, &internal1_m130_RA10},	//(internal1_m130_RA10) RA10 - последнее задание назад
	{ 953	,18	,1	, &internal1_m130_RA50},	//(internal1_m130_RA50) Ra50 - последнее задание скорости
	{ 954	,1	,1	, &internal1_m130_fls},	//(internal1_m130_fls)  fls - флаг одношагового режима
	{ 955	,1	,1	, &internal1_m130_flp},	//(internal1_m130_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 956	,1	,1	, &internal1_m130_MyFirstEnterFlag},	//(internal1_m130_MyFirstEnterFlag) MyFirstEnterFlag
	{ 957	,1	,1	, &internal1_m267_Ppv0},	//(internal1_m267_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 958	,1	,1	, &internal1_m267_Pav0},	//(internal1_m267_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 959	,1	,1	, &internal1_m267_Zav0},	//(internal1_m267_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 960	,1	,1	, &internal1_m267_RA00},	//(internal1_m267_RA00) RA00 - последнее задание вперед
	{ 961	,1	,1	, &internal1_m267_RA10},	//(internal1_m267_RA10) RA10 - последнее задание назад
	{ 962	,18	,1	, &internal1_m267_RA50},	//(internal1_m267_RA50) Ra50 - последнее задание скорости
	{ 963	,1	,1	, &internal1_m267_fls},	//(internal1_m267_fls)  fls - флаг одношагового режима
	{ 964	,1	,1	, &internal1_m267_flp},	//(internal1_m267_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 965	,1	,1	, &internal1_m267_MyFirstEnterFlag},	//(internal1_m267_MyFirstEnterFlag) MyFirstEnterFlag
	{ 966	,1	,1	, &internal1_m96_Ppv0},	//(internal1_m96_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 967	,1	,1	, &internal1_m96_Pav0},	//(internal1_m96_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 968	,1	,1	, &internal1_m96_Zav0},	//(internal1_m96_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 969	,1	,1	, &internal1_m96_RA00},	//(internal1_m96_RA00) RA00 - последнее задание вперед
	{ 970	,1	,1	, &internal1_m96_RA10},	//(internal1_m96_RA10) RA10 - последнее задание назад
	{ 971	,18	,1	, &internal1_m96_RA50},	//(internal1_m96_RA50) Ra50 - последнее задание скорости
	{ 972	,1	,1	, &internal1_m96_fls},	//(internal1_m96_fls)  fls - флаг одношагового режима
	{ 973	,1	,1	, &internal1_m96_flp},	//(internal1_m96_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 974	,1	,1	, &internal1_m96_MyFirstEnterFlag},	//(internal1_m96_MyFirstEnterFlag) MyFirstEnterFlag
	{ 975	,1	,1	, &internal1_m229_Ppv0},	//(internal1_m229_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 976	,1	,1	, &internal1_m229_Pav0},	//(internal1_m229_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 977	,1	,1	, &internal1_m229_Zav0},	//(internal1_m229_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 978	,1	,1	, &internal1_m229_RA00},	//(internal1_m229_RA00) RA00 - последнее задание вперед
	{ 979	,1	,1	, &internal1_m229_RA10},	//(internal1_m229_RA10) RA10 - последнее задание назад
	{ 980	,18	,1	, &internal1_m229_RA50},	//(internal1_m229_RA50) Ra50 - последнее задание скорости
	{ 981	,1	,1	, &internal1_m229_fls},	//(internal1_m229_fls)  fls - флаг одношагового режима
	{ 982	,1	,1	, &internal1_m229_flp},	//(internal1_m229_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 983	,1	,1	, &internal1_m229_MyFirstEnterFlag},	//(internal1_m229_MyFirstEnterFlag) MyFirstEnterFlag
	{ 984	,1	,1	, &internal1_m60_Ppv0},	//(internal1_m60_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 985	,1	,1	, &internal1_m60_Pav0},	//(internal1_m60_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 986	,1	,1	, &internal1_m60_Zav0},	//(internal1_m60_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 987	,1	,1	, &internal1_m60_RA00},	//(internal1_m60_RA00) RA00 - последнее задание вперед
	{ 988	,1	,1	, &internal1_m60_RA10},	//(internal1_m60_RA10) RA10 - последнее задание назад
	{ 989	,18	,1	, &internal1_m60_RA50},	//(internal1_m60_RA50) Ra50 - последнее задание скорости
	{ 990	,1	,1	, &internal1_m60_fls},	//(internal1_m60_fls)  fls - флаг одношагового режима
	{ 991	,1	,1	, &internal1_m60_flp},	//(internal1_m60_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 992	,1	,1	, &internal1_m60_MyFirstEnterFlag},	//(internal1_m60_MyFirstEnterFlag) MyFirstEnterFlag
	{ 993	,8	,1	, &internal1_m14_C1},	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{ 994	,8	,1	, &internal1_m14_C2},	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{ 995	,8	,1	, &internal1_m14_C3},	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{ 996	,8	,1	, &internal1_m14_C4},	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{ 997	,8	,1	, &internal1_m14_C5},	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{ 998	,8	,1	, &internal1_m14_C6},	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{ 999	,8	,1	, &internal1_m14_N20},	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
	{ 1000	,8	,6	, &internal1_m14_C0},	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
	{ 1001	,1	,1	, &internal1_m14_ImpINI0},	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{ 1002	,1	,1	, &internal1_m14_MyFirstEnterFlag},	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="scm.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{279,"fEM_R0UL01RIM\0"}, 
{280,"fEM_R0UN02RIM\0"}, 
{281,"fEM_A1UR01RIM\0"}, 
{282,"fEM_A1UR00RIM\0"}, 
{283,"fEM_A3UR00RIM\0"}, 
{284,"fEM_A3UR01RIM\0"}, 
{285,"fEM_R0UT01RIM\0"}, 
{286,"fEM_R0UT02RIM\0"}, 
{287,"fEM_R0UT04RIM\0"}, 
{288,"fEM_R0UT03RIM\0"}, 
{289,"fEM_R0UT05RIM\0"}, 
{290,"fEM_R0UT06RIM\0"}, 
{291,"fEM_A1UC02RDU\0"}, 
{292,"fEM_A1UC04RIM\0"}, 
{293,"fEM_A1UC05RIM\0"}, 
{294,"fEM_A1UC06RIM\0"}, 
{295,"fEM_A2UC06RIM\0"}, 
{296,"fEM_A2UC05RIM\0"}, 
{297,"fEM_A2UC04RIM\0"}, 
{298,"fEM_A2UC02RDU\0"}, 
{299,"fEM_A3UC06RIM\0"}, 
{300,"fEM_A3UC05RIM\0"}, 
{301,"fEM_A3UC04RIM\0"}, 
{302,"fEM_A3UC02RDU\0"}, 
{303,"fEM_R4UV80RDU\0"}, 
{304,"fEM_R4UC10RIM\0"}, 
{305,"fEM_R4UC20RIM\0"}, 
{306,"fEM_B8UC21RIM\0"}, 
{307,"fEM_B8UC20RIM\0"}, 
{308,"fEM_B8UC11RIM\0"}, 
{309,"fEM_B8UC10RIM\0"}, 
{310,"fEM_B8UV80RDU\0"}, 
{311,"fEM_A8UV80RDU\0"}, 
{312,"fEM_A8UC10RIM\0"}, 
{313,"fEM_A8UC11RIM\0"}, 
{314,"fEM_A8UC20RIM\0"}, 
{315,"fEM_A8UC21RIM\0"}, 
{316,"fEM_A6UC10RIM\0"}, 
{317,"fEM_R1UC10RIM\0"}, 
{318,"fEM_A5UC10RIM\0"}, 
{319,"fEM_A0UN01RIM\0"}, 
{320,"fEM_R4UC22RIM\0"}, 
{321,"fEM_A1UG01RDU\0"}, 
{322,"fEM_A2UG01RDU\0"}, 
{323,"fEM_A3UG01RDU\0"}, 
{324,"fEM_R7UC10RIM\0"}, 
{325,"fEM_R7UC19RIM\0"}, 
{326,"fEM_R7UI02RIM\0"}, 
{327,"fEM_R7UL01RIM\0"}, 
{328,"fEM_A2UR00RIM\0"}, 
{329,"fEM_A2UR01RIM\0"}, 
{330,"fEM_A0UN02RIM\0"}, 
{331,"fEM_R0UR30RIM\0"}, 
{332,"fEM_R0UR01RIM\0"}, 
{333,"fEM_R0UT02RDU\0"}, 
{334,"fEM_R0UT01RDU\0"}, 
{335,"fEM_A1UC03RDU\0"}, 
{336,"fEM_A2UP03RDU\0"}, 
{337,"fEM_A2UP04RDU\0"}, 
{338,"fEM_A2UC03RDU\0"}, 
{339,"fEM_A3UP03RDU\0"}, 
{340,"fEM_A3UP04RDU\0"}, 
{341,"fEM_A3UC03RDU\0"}, 
{342,"fEM_R7UI74RIM\0"}, 
{343,"fEM_A8UC03RDU\0"}, 
{344,"fEM_R0UV87RDU\0"}, 
{345,"fEM_R0UV81RDU\0"}, 
{346,"fEM_R0UV82RDU\0"}, 
{347,"fEM_R0UV83RDU\0"}, 
{348,"fEM_R0UV84RDU\0"}, 
{349,"fEM_R0UV85RDU\0"}, 
{350,"fEM_R0UV86RDU\0"}, 
{351,"fEM_A8UC08RDU\0"}, 
{352,"fEM_B8UC08RDU\0"}, 
{353,"fEM_R4UC08RDU\0"}, 
{354,"fEM_R0UH01RSS\0"}, 
{355,"fEM_A0UX00RSS\0"}, 
{356,"fEM_R7UX01RSS\0"}, 
{357,"fEM_R7UX02RSS\0"}, 
{358,"fEM_R7UX04RSS\0"}, 
{359,"fEM_R7UX05RSS\0"}, 
{360,"fEM_R7UX06RSS\0"}, 
{361,"fEM_R7UX07RSS\0"}, 
{362,"fEM_R7UX08RSS\0"}, 
{363,"fEM_R7UX09RSS\0"}, 
{364,"fEM_R7UY01RSS\0"}, 
{365,"fEM_R7UY02RSS\0"}, 
{366,"fEM_R7UY04RSS\0"}, 
{367,"fEM_R7UY05RSS\0"}, 
{368,"fEM_R7UY06RSS\0"}, 
{369,"fEM_R7UY07RSS\0"}, 
{370,"fEM_R7UY08RSS\0"}, 
{371,"fEM_R7UY09RSS\0"}, 
{372,"fEM_R7UX10RSS\0"}, 
{373,"fEM_R7UX11RSS\0"}, 
{374,"fEM_R7UX12RSS\0"}, 
{375,"fEM_R7UY10RSS\0"}, 
{376,"fEM_R7UY11RSS\0"}, 
{377,"fEM_R7UY12RSS\0"}, 
{378,"fEM_A0UX01RSS\0"}, 
{379,"fEM_A0UX02RSS\0"}, 
{380,"fEM_A0UX03RSS\0"}, 
{381,"fEM_A0UX04RSS\0"}, 
{382,"fEM_A0UX05RSS\0"}, 
{383,"fEM_A0UX06RSS\0"}, 
{384,"fEM_A0UX07RSS\0"}, 
{385,"fEM_A0UX08RSS\0"}, 
{386,"fEM_A0UX09RSS\0"}, 
{387,"fEM_A0UX10RSS\0"}, 
{388,"fEM_A0UX11RSS\0"}, 
{389,"fEM_A0UX12RSS\0"}, 
{390,"fEM_B0UX01RSS\0"}, 
{391,"fEM_B0UX02RSS\0"}, 
{392,"fEM_B0UX03RSS\0"}, 
{393,"fEM_B0UX04RSS\0"}, 
{394,"fEM_B0UX05RSS\0"}, 
{395,"fEM_B0UX06RSS\0"}, 
{396,"fEM_B0UX07RSS\0"}, 
{397,"fEM_B0UX08RSS\0"}, 
{398,"fEM_B0UX09RSS\0"}, 
{399,"fEM_B0UX10RSS\0"}, 
{400,"fEM_B0UX11RSS\0"}, 
{401,"fEM_B0UX12RSS\0"}, 
{402,"fEM_R0UH02RSS\0"}, 
{403,"fEM_R0UH03RSS\0"}, 
{404,"fEM_R4US80RDU\0"}, 
{405,"fEM_R7UI71RIM\0"}, 
{406,"fEM_R7UI72RIM\0"}, 
{407,"fEM_R7UI73RIM\0"}, 
{408,"fEM_A1UP01RIM\0"}, 
{409,"fEM_A2UP01RIM\0"}, 
{410,"fEM_A0UP02RIM\0"}, 
{411,"fEM_A3UP01RIM\0"}, 
{412,"fEM_A1UP82RIM\0"}, 
{413,"fEM_A3UP02RDU\0"}, 
{414,"fEM_A1UV02RIM\0"}, 
{415,"fEM_A3UV02RIM\0"}, 
{416,"fEM_A2UV02RIM\0"}, 
{417,"fEM_B8US80RDU\0"}, 
{418,"fEM_A8US80RDU\0"}, 
{419,"fEM_A6US80RDU\0"}, 
{420,"fEM_A1US07RDU\0"}, 
{421,"fEM_A2US07RDU\0"}, 
{422,"fEM_A3US07RDU\0"}, 
{423,"fEM_R7UI75RIM\0"}, 
{424,"fEM_R0UH21RSS\0"}, 
{425,"fEM_R0UH22RSS\0"}, 
{426,"fEM_R0UH23RSS\0"}, 
{427,"fEM_R0UH05RSS\0"}, 
{428,"fEM_A4UL10RIM\0"}, 
{429,"fEM_A9UL10RIM\0"}, 
{430,"fEM_R3UL10RIM\0"}, 
{431,"fEM_R5UL10RIM\0"}, 
{432,"fEM_R6UL10RIM\0"}, 
{433,"lEM_C1AD31LRP\0"}, 
{434,"lEM_R0IE01LRP\0"}, 
{435,"lEM_R0IE02LRP\0"}, 
{436,"fEM_A2UP02RIM\0"}, 
{437,"fEM_A2UP03RIM\0"}, 
{438,"fEM_A0UP01RIM\0"}, 
{439,"fEM_A3UP02RIM\0"}, 
{440,"fEM_A4UP01RIM\0"}, 
{441,"fEM_A4UP02RIM\0"}, 
{442,"fEM_R7UI76RIM\0"}, 
{443,"fEM_R7UI77RIM\0"}, 
{444,"iEM_TERBB1\0"}, 
{445,"fEM_A1MC02RC1\0"}, 
{446,"fEM_A1MV02RC1\0"}, 
{447,"iEM_TERBB2\0"}, 
{448,"fEM_B1MC02RC1\0"}, 
{449,"fEM_B1MV02RC1\0"}, 
{450,"iEM_TERRB2\0"}, 
{451,"fEM_B2MC02RC1\0"}, 
{452,"fEM_B2MV02RC1\0"}, 
{453,"iEM_TERRB1\0"}, 
{454,"fEM_A2MC02RC1\0"}, 
{455,"fEM_A2MV02RC1\0"}, 
{456,"iEM_TERIS2\0"}, 
{457,"fEM_B3MC02RC1\0"}, 
{458,"fEM_B3MV02RC1\0"}, 
{459,"iEM_TERIS1\0"}, 
{460,"fEM_A3MC02RC1\0"}, 
{461,"fEM_A3MV02RC1\0"}, 
{462,"iEM_TERA1IE04LDU\0"}, 
{463,"iEM_TERA1IE03LDU\0"}, 
{464,"fEM_A1MC01RC1\0"}, 
{465,"iEM_TERB1IE03LDU\0"}, 
{466,"iEM_TERB1IE04LDU\0"}, 
{467,"fEM_B1MC01RC1\0"}, 
{468,"fEM_B1MV01RC1\0"}, 
{469,"fEM_B2MC01RC1\0"}, 
{470,"fEM_B2MV01RC1\0"}, 
{471,"fEM_A3MC01RC1\0"}, 
{472,"fEM_A3MV01RC1\0"}, 
{473,"fEM_B3MC01RC1\0"}, 
{474,"fEM_B3MV01RC1\0"}, 
{475,"iEM_TERA2SS21LIM\0"}, 
{476,"iEM_TERA2SS12LIM\0"}, 
{477,"iEM_TERR6SS21LIM\0"}, 
{478,"iEM_TERA2VP82LIM\0"}, 
{479,"iEM_TERA2SS11LIM\0"}, 
{480,"iEM_TERB3SS21LIM\0"}, 
{481,"iEM_TERA0MT01RIM\0"}, 
{482,"iEM_TERB0MT01RIM\0"}, 
{483,"iEM_TERA2SP01RIM\0"}, 
{484,"iEM_TERB2SP01RIM\0"}, 
{485,"iEM_TERB3SP02RIM\0"}, 
{486,"iEM_TERA3SC01RIM\0"}, 
{487,"iEM_TERA3VP81LIM\0"}, 
{488,"iEM_TERA2SC01RIM\0"}, 
{489,"iEM_TERA2SS33LIM\0"}, 
{490,"iEM_TERA3SS21LIM\0"}, 
{491,"iEM_TERA3SS33LIM\0"}, 
{492,"iEM_TERA3SS31LIM\0"}, 
{493,"iEM_TERB3SS31LIM\0"}, 
{494,"iEM_TERB3SS33LIM\0"}, 
{495,"iEM_TERB3SC01RIM\0"}, 
{496,"iEM_TERA3SS11LIM\0"}, 
{497,"iEM_TERB3SS11LIM\0"}, 
{498,"iEM_TERR6IS64LIM\0"}, 
{499,"iEM_TERB3SS22LIM\0"}, 
{500,"iEM_TERA3SS22LIM\0"}, 
{501,"iEM_TERA3SP02RIM\0"}, 
{502,"iEM_TERR6IS62LIM\0"}, 
{503,"iEM_TERR6IS66LIM\0"}, 
{504,"iEM_TERR6IS67LIM\0"}, 
{505,"iEM_TERA0VP81LIM\0"}, 
{506,"iEM_TERB0VP81LIM\0"}, 
{507,"iEM_TERR0VP81LIM\0"}, 
{508,"iEM_TERR6IS68LIM\0"}, 
{509,"iEM_TERR7SI74RIM\0"}, 
{510,"iEM_TERA5SS21LIM\0"}, 
{511,"iEM_TERB5SS11LIM\0"}, 
{512,"iEM_TERA5SS11LIM\0"}, 
{513,"iEM_TERA9SS11LIM\0"}, 
{514,"iEM_TERB2SS11LIM\0"}, 
{515,"iEM_TERB2SS12LIM\0"}, 
{516,"iEM_TERB2SS21LIM\0"}, 
{517,"iEM_TERR3SS11LIM\0"}, 
{518,"iEM_TERB2SC01RIM\0"}, 
{519,"iEM_TERR3SS21LIM\0"}, 
{520,"iEM_TERR5SS11LIM\0"}, 
{521,"iEM_TERA4SS11LIM\0"}, 
{522,"iEM_TERR1SS11LIM\0"}, 
{523,"iEM_TERR1SS21LIM\0"}, 
{524,"iEM_TERR2SS11LIM\0"}, 
{525,"iEM_TERR2SS21LIM\0"}, 
{526,"iEM_TERA4VP82LIM\0"}, 
{527,"iEM_TERB4SS21LIM\0"}, 
{528,"iEM_TERR5SS21LIM\0"}, 
{529,"iEM_TERB6SS21LIM\0"}, 
{530,"iEM_TERB4SS11LIM\0"}, 
{531,"iEM_TERA4SS21LIM\0"}, 
{532,"iEM_TERA6MS11LIM\0"}, 
{533,"iEM_TERA6SS21LIM\0"}, 
{534,"iEM_TERB6SS11LIM\0"}, 
{535,"iEM_TERR4SS11LIM\0"}, 
{536,"iEM_TERR4MS21LIM\0"}, 
{537,"iEM_TERR4SS12LIM\0"}, 
{538,"iEM_TERR4SS22LIM\0"}, 
{539,"iEM_TERR8SS11LIM\0"}, 
{540,"iEM_TERB8SC01RIM\0"}, 
{541,"iEM_TERA8SC01RIM\0"}, 
{542,"iEM_TERB8SS12LIM\0"}, 
{543,"iEM_TERA8SS12LIM\0"}, 
{544,"iEM_TERB8SS22LIM\0"}, 
{545,"iEM_TERA8SS22LIM\0"}, 
{546,"iEM_TERA9SS21LIM\0"}, 
{547,"iEM_TERB9SS21LIM\0"}, 
{548,"iEM_TERB9SS11LIM\0"}, 
{549,"iEM_TERB5SS21LIM\0"}, 
{550,"iEM_TERA1SS21LIM\0"}, 
{551,"iEM_TERA1SS11LIM\0"}, 
{552,"iEM_TERA1SC01RIM\0"}, 
{553,"iEM_TERA1SS12LIM\0"}, 
{554,"iEM_TERB1SS21LIM\0"}, 
{555,"iEM_TERB1SS11LIM\0"}, 
{556,"iEM_TERB1MC01RIM\0"}, 
{557,"iEM_TERB1SS12LIM\0"}, 
{558,"iEM_TERTLG\0"}, 
{559,"fEM_R4MC01RC1\0"}, 
{560,"fEM_R4MV01RC1\0"}, 
{561,"iEM_TERMAZ2\0"}, 
{562,"fEM_B8MC01RC1\0"}, 
{563,"fEM_B8MV01RC1\0"}, 
{564,"iEM_TERDS2\0"}, 
{565,"fEM_A8MC01RC1\0"}, 
{566,"fEM_A8MV01RC1\0"}, 
{567,"iEM_TERBZ1\0"}, 
{568,"fEM_A6MC01RC1\0"}, 
{569,"fEM_A6MV01RC1\0"}, 
{570,"iEM_TERBZ2\0"}, 
{571,"fEM_B6MC01RC1\0"}, 
{572,"fEM_B6MV01RC1\0"}, 
{573,"lEM_R3AD10LC1\0"}, 
{574,"lEM_R3AD20LC1\0"}, 
{575,"lEM_R6AD10LC1\0"}, 
{576,"lEM_R5AD10LC1\0"}, 
{577,"lEM_R5AD20LC1\0"}, 
{578,"iEM_TERMDZ2\0"}, 
{579,"fEM_R2MC01RC1\0"}, 
{580,"fEM_R2MV01RC1\0"}, 
{581,"iEM_TERMDZ1\0"}, 
{582,"fEM_R1MC01RC1\0"}, 
{583,"fEM_R1MV01RC1\0"}, 
{584,"iEM_TERNL1\0"}, 
{585,"fEM_A5MC01RC1\0"}, 
{586,"fEM_A5MV01RC1\0"}, 
{587,"iEM_TERNL2\0"}, 
{588,"fEM_B5MC01RC1\0"}, 
{589,"fEM_B5MV01RC1\0"}, 
{590,"lEM_R8AD10LC1\0"}, 
{591,"fEM_A1UC08RIM\0"}, 
{592,"fEM_A2UC08RIM\0"}, 
{593,"fEM_A3UC08RIM\0"}, 
{594,"iEM_TERB2SS33LIM\0"}, 
{595,"iEM_TERA1VP81LIM\0"}, 
{596,"iEM_TERB1VP81LIM\0"}, 
{597,"fEM_A0UT03RSP\0"}, 
{598,"fEM_A0UR01RSP\0"}, 
{599,"fEM_A0UR02RSP\0"}, 
{600,"fEM_B0UT03RSP\0"}, 
{601,"fEM_A1MC01RSP\0"}, 
{602,"fEM_A1MC02RSP\0"}, 
{603,"fEM_A1MV01RSP\0"}, 
{604,"fEM_A1MV02RSP\0"}, 
{605,"fEM_B1MC01RSP\0"}, 
{606,"fEM_B1MV01RSP\0"}, 
{607,"fEM_B1MC02RSP\0"}, 
{608,"fEM_B1MV02RSP\0"}, 
{609,"fEM_A2MC01RC1\0"}, 
{610,"fEM_A2MV01RC1\0"}, 
{611,"fEM_A2MC01RSP\0"}, 
{612,"fEM_A2MV01RSP\0"}, 
{613,"fEM_A2MC02RSP\0"}, 
{614,"fEM_A2MV02RSP\0"}, 
{615,"fEM_B2MC01RSP\0"}, 
{616,"fEM_B2MV01RSP\0"}, 
{617,"fEM_B2MC02RSP\0"}, 
{618,"fEM_B2MV02RSP\0"}, 
{619,"fEM_A3MC01RSP\0"}, 
{620,"fEM_A3MV01RSP\0"}, 
{621,"fEM_A3MC02RSP\0"}, 
{622,"fEM_A3MV02RSP\0"}, 
{623,"fEM_B3MC01RSP\0"}, 
{624,"fEM_B3MV01RSP\0"}, 
{625,"fEM_B3MC02RSP\0"}, 
{626,"fEM_B3MV02RSP\0"}, 
{627,"fEM_B8MC01RSP\0"}, 
{628,"fEM_B8MV01RSP\0"}, 
{629,"fEM_A8MC01RSP\0"}, 
{630,"fEM_A8MV01RSP\0"}, 
{631,"fEM_A6MC01RSP\0"}, 
{632,"fEM_A6MV01RSP\0"}, 
{633,"fEM_B6MC01RSP\0"}, 
{634,"fEM_B6MV01RSP\0"}, 
{635,"fEM_R3UC01RSP\0"}, 
{636,"fEM_R3UV01RSP\0"}, 
{637,"fEM_R5UC01RSP\0"}, 
{638,"fEM_R5UV01RSP\0"}, 
{639,"fEM_R6UC01RSP\0"}, 
{640,"fEM_R6UV01RSP\0"}, 
{641,"fEM_R2MC01RSP\0"}, 
{642,"fEM_R2MV01RSP\0"}, 
{643,"fEM_R1MC01RSP\0"}, 
{644,"fEM_R1MV01RSP\0"}, 
{645,"fEM_A5MC01RSP\0"}, 
{646,"fEM_A5MV01RSP\0"}, 
{647,"fEM_B5MC01RSP\0"}, 
{648,"fEM_B5MV01RSP\0"}, 
{649,"fEM_A9MC01RSP\0"}, 
{650,"fEM_A9MV01RSP\0"}, 
{651,"fEM_B9MC01RSP\0"}, 
{652,"fEM_B9MV01RSP\0"}, 
{653,"fEM_A4MC01RSP\0"}, 
{654,"fEM_A4MV01RSP\0"}, 
{655,"fEM_B4MC01RSP\0"}, 
{656,"fEM_B4MV01RSP\0"}, 
{657,"fEM_R4MC01RSP\0"}, 
{658,"fEM_R4MV01RSP\0"}, 
{659,"fEM_A1MV01RC1\0"}, 
{660,"iEM_TERB7MS31LIM\0"}, 
{661,"iEM_TERA7MS31LIM\0"}, 
{662,"fEM_R7UY00RSS\0"}, 
{663,"iEM_TERA6VS12LIM\0"}, 
{664,"iEM_TERA6VS22LIM\0"}, 
{665,"iEM_TERB6VS12LIM\0"}, 
{666,"iEM_TERB6VS22LIM\0"}, 
{667,"iEM_TERA5VS22LIM\0"}, 
{668,"iEM_TERA5VS12LIM\0"}, 
{669,"iEM_TERB5VS12LIM\0"}, 
{670,"iEM_TERB5VS22LIM\0"}, 
{671,"iEM_TERR1VS12LIM\0"}, 
{672,"iEM_TERR1VS22LIM\0"}, 
{673,"iEM_TERR2VS12LIM\0"}, 
{674,"iEM_TERR2VS22LIM\0"}, 
{675,"iEM_TERR4VS12LDU\0"}, 
{676,"iEM_TERR4VS22LDU\0"}, 
{677,"fEM_R4UC23RIM\0"}, 
{678,"fEM_A0UX13RSS\0"}, 
{679,"fEM_A0UX14RSS\0"}, 
{680,"fEM_A0UX15RSS\0"}, 
{681,"fEM_R7UX13RSS\0"}, 
{682,"fEM_R7UX14RSS\0"}, 
{683,"fEM_R7UX15RSS\0"}, 
{684,"fEM_R7UY13RSS\0"}, 
{685,"fEM_R7UY14RSS\0"}, 
{686,"fEM_R7UY15RSS\0"}, 
{687,"fEM_R7UX16RSS\0"}, 
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
	{&B0IT02IZ2,3,18},
	{&A3IP02IDU,3,24},
	{&B0IT01IZ1,3,6},
	{&A0IT02IZ2,3,12},
	{&A0IT03IRP,3,30},
	{&B3IP02IDU,3,27},
	{&A2IP01IZ1,3,3},
	{&B0IT03IRP,3,33},
	{&B2IP01IZ1,3,9},
	{&A0IT01IZ1,3,0},
	{&B2IP01IZ2,3,21},
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
	{&A3IS22LDU,1,10},
	{&A1VP81LZZ,1,54},
	{&A3IS11LDU,1,8},
	{&R7II73LZ1,1,50},
	{&R7II71LZ1,1,46},
	{&R7II72LZ1,1,48},
	{&A0VP81LZZ,1,52},
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
	{&R7II72LZ2,1,48},
	{&B3IS11LDU,1,20},
	{&R7II71LZ2,1,46},
	{&R7II73LZ2,1,50},
	{&B3IS22LDU,1,22},
	{&B0VP81LZZ,1,58},
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
	{&R2IS21LDU,1,48},
	{&B3IS21LDU,1,24},
	{&B2IS11LDU,1,20},
	{&B2IS12LDU,1,18},
	{&A4IS11LDU,1,30},
	{&A4IS21LDU,1,32},
	{&R8IS11LDU,1,26},
	{&R1IS11LDU,1,42},
	{&R1IS21LDU,1,44},
	{&R2IS11LDU,1,46},
	{&B7AS31LDU,1,10},
	{&A7AS31LDU,1,60},
	{&A9IS11LDU,1,34},
	{&A9IS21LDU,1,36},
	{&B9IS11LDU,1,38},
	{&B9IS21LDU,1,40},
	{&B2IS21LDU,1,22},
	{&A1IS12LDU,1,62},
	{&B1IS21LDU,1,16},
	{&B1IS11LDU,1,14},
	{&B1IS12LDU,1,12},
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
	{&A3IS21LDU,1,10},
	{&A2IS12LDU,1,4},
	{&A2IS11LDU,1,6},
	{&A2IS21LDU,1,8},
	{&R0IS02LDU,1,32},
	{&B4IS11LDU,1,12},
	{&B4IS21LDU,1,14},
	{&A5IS11LDU,1,54},
	{&A5IS21LDU,1,56},
	{&B5IS11LDU,1,62},
	{&R4IS11LDU,1,42},
	{&R4IS21LDU,1,46},
	{&R4IS22LDU,1,48},
	{&R4IS12LDU,1,44},
	{&A6IS21LDU,1,52},
	{&B6IS11LDU,1,58},
	{&B6IS21LDU,1,60},
	{&A1IS21LDU,1,2},
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
	{&B5IS21LDU,1,0},
	{&B8IS22LDU,1,12},
	{&B8IS12LDU,1,10},
	{&R6IS21LDU,1,26},
	{&A8IS22LDU,1,30},
	{&R3IS11LDU,1,2},
	{&A8IS12LDU,1,28},
	{&B8IS21LDU,1,8},
	{&R3IS21LDU,1,4},
	{&B8IS11LDU,1,14},
	{&R5IS11LDU,1,18},
	{&R5IS21LDU,1,20},
	{&A6IS11LDU,1,34},
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
	{&A3AD34LDU,1,22},
	{&B7AP31LDU,1,60},
	{&A7AP31LDU,1,32},
	{&A3AD31LDU,1,30},
	{&A8AD10LDU,1,62},
	{&B3AD34LDU,1,50},
	{&R1AD10LDU,1,34},
	{&R1AD20LDU,1,36},
	{&R2AD10LDU,1,38},
	{&R2AD20LDU,1,40},
	{&A5AD10LDU,1,42},
	{&A5AD20LDU,1,44},
	{&B5AD10LDU,1,46},
	{&B5AD20LDU,1,48},
	{&A3AD33LDU,1,24},
	{&A4AD10LDU,1,28},
	{&B4AD10LDU,1,56},
	{&B3AD33LDU,1,52},
	{&B2AD33LDU,1,54},
	{&B3AD31LDU,1,58},
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
	{&A9AD10LDU,1,46},
	{&B9AD10LDU,1,48},
	{&A6AD10LDU,1,2},
	{&A6AD20LDU,1,4},
	{&B6AD10LDU,1,6},
	{&B6AD20LDU,1,8},
	{&A3AD03LDU,1,26},
	{&A3AD04LDU,1,28},
	{&A3AD05LDU,1,30},
	{&A8AD20LDU,1,0},
	{&A1AD04LDU,1,60},
	{&A1AD03LDU,1,58},
	{&A1AD02LDU,1,56},
	{&A1AD01LDU,1,54},
	{&A1AD21LDU,1,52},
	{&A1AD11LDU,1,50},
	{&A3AD02LDU,1,24},
	{&A3AD01LDU,1,22},
	{&A3AD21LDU,1,20},
	{&A3AD11LDU,1,18},
	{&B3AD11LDU,1,32},
	{&B3AD21LDU,1,34},
	{&B3AD01LDU,1,36},
	{&B3AD02LDU,1,38},
	{&B3AD03LDU,1,40},
	{&B3AD04LDU,1,42},
	{&B3AD05LDU,1,44},
	{&R4AD10LDU,1,10},
	{&R4AD20LDU,1,12},
	{&B8AD10LDU,1,14},
	{&B8AD20LDU,1,16},
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
	{&A2AD21LDU,1,18},
	{&A2AD11LDU,1,16},
	{&A2AD32LDU,1,48},
	{&R8AD21LDU,1,60},
	{&R0AD16LDU,1,62},
	{&B2AD32LDU,1,56},
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
	{&A1AD05LDU,1,0},
	{&B1AD11LDU,1,2},
	{&B1AD21LDU,1,4},
	{&B1AD01LDU,1,6},
	{&B2AD31LDU,1,58},
	{&B1AD32LDU,1,52},
	{&B1AD31LDU,1,54},
	{&B1AD02LDU,1,8},
	{&B1AD03LDU,1,10},
	{&B1AD04LDU,1,12},
	{&A1AD31LDU,1,46},
	{&A1AD32LDU,1,44},
	{&A2AD31LDU,1,50},
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
	setAsFloat(279,0.015);
	setAsFloat(280,0.0069);
	setAsFloat(281,0.21);
	setAsFloat(282,0);
	setAsFloat(283,0);
	setAsFloat(284,0.0096);
	setAsFloat(285,0.0026);
	setAsFloat(286,106);
	setAsFloat(287,135.227);
	setAsFloat(288,25);
	setAsFloat(289,320.435466);
	setAsFloat(290,0.0055);
	setAsFloat(291,0.000877);
	setAsFloat(292,200);
	setAsFloat(293,100);
	setAsFloat(294,0);
	setAsFloat(295,0);
	setAsFloat(296,100);
	setAsFloat(297,80);
	setAsFloat(298,0.002375);
	setAsFloat(299,0);
	setAsFloat(300,165);
	setAsFloat(301,200);
	setAsFloat(302,0.001675);
	setAsFloat(303,40);
	setAsFloat(304,15630.0);
	setAsFloat(305,1374);
	setAsFloat(306,0);
	setAsFloat(307,390.0);
	setAsFloat(308,2000.0);
	setAsFloat(309,1500.0);
	setAsFloat(310,10.91);
	setAsFloat(311,10.91);
	setAsFloat(312,1500.0);
	setAsFloat(313,2000);
	setAsFloat(314,390.0);
	setAsFloat(315,0);
	setAsFloat(316,55.0);
	setAsFloat(317,15.0);
	setAsFloat(318,5.0);
	setAsFloat(319,1E12);
	setAsFloat(320,43.6);
	setAsFloat(321,20.0);
	setAsFloat(322,20.0);
	setAsFloat(323,20.0);
	setAsFloat(324,1269.0);
	setAsFloat(325,256.0);
	setAsFloat(326,1.0);
	setAsFloat(327,2.0);
	setAsFloat(328,0);
	setAsFloat(329,0.026);
	setAsFloat(330,0.08);
	setAsFloat(331,0.0);
	setAsFloat(332,27.108);
	setAsFloat(333,600);
	setAsFloat(334,0);
	setAsFloat(335,0.00009765625);
	setAsFloat(336,1.6);
	setAsFloat(337,0);
	setAsFloat(338,0.00009765625);
	setAsFloat(339,1.6);
	setAsFloat(340,0);
	setAsFloat(341,0.00009765625);
	setAsFloat(342,10000.0);
	setAsFloat(343,0.0009765625);
	setAsFloat(344,750);
	setAsFloat(345,100);
	setAsFloat(346,200);
	setAsFloat(347,300);
	setAsFloat(348,400);
	setAsFloat(349,500);
	setAsFloat(350,600);
	setAsFloat(351,0.50);
	setAsFloat(352,0.50);
	setAsFloat(353,0.50);
	setAsFloat(354,2);
	setAsFloat(355,11.0);
	setAsFloat(356,1585.0);
	setAsFloat(357,1796.0);
	setAsFloat(358,1555.0);
	setAsFloat(359,1269.0);
	setAsFloat(360,1269.0);
	setAsFloat(361,1585.0);
	setAsFloat(362,1796.0);
	setAsFloat(363,1269.0);
	setAsFloat(364,248.0);
	setAsFloat(365,284.5);
	setAsFloat(366,248.0);
	setAsFloat(367,271.6);
	setAsFloat(368,287.2);
	setAsFloat(369,594.0);
	setAsFloat(370,559.0);
	setAsFloat(371,588.0);
	setAsFloat(372,1555.0);
	setAsFloat(373,1281.2);
	setAsFloat(374,1269.0);
	setAsFloat(375,594.0);
	setAsFloat(376,597.2);
	setAsFloat(377,556.8);
	setAsFloat(378,1.0);
	setAsFloat(379,1.0);
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
	setAsFloat(390,0);
	setAsFloat(391,0);
	setAsFloat(392,0);
	setAsFloat(393,0);
	setAsFloat(394,0.0);
	setAsFloat(395,0);
	setAsFloat(396,0.0);
	setAsFloat(397,0);
	setAsFloat(398,0.0);
	setAsFloat(399,0.0);
	setAsFloat(400,0.0);
	setAsFloat(401,0.0);
	setAsFloat(402,3703.704);
	setAsFloat(403,62500.0);
	setAsFloat(404,20);
	setAsFloat(405,18000);
	setAsFloat(406,18000);
	setAsFloat(407,18000);
	setAsFloat(408,0.76);
	setAsFloat(409,0.245);
	setAsFloat(410,2.9);
	setAsFloat(411,0.13);
	setAsFloat(412,0.73);
	setAsFloat(413,0.41);
	setAsFloat(414,9807.0);
	setAsFloat(415,22975.0);
	setAsFloat(416,12750.0);
	setAsFloat(417,20);
	setAsFloat(418,20);
	setAsFloat(419,0);
	setAsFloat(420,5.0);
	setAsFloat(421,5.0);
	setAsFloat(422,5.0);
	setAsFloat(423,100.0);
	setAsFloat(424,4000);
	setAsFloat(425,100000);
	setAsFloat(426,1000000);
	setAsFloat(427,32000.0);
	setAsFloat(428,5.0);
	setAsFloat(429,15.0);
	setAsFloat(430,15.0);
	setAsFloat(431,20.0);
	setAsFloat(432,10.0);
	setAsBool(433,0);
	setAsBool(434,0);
	setAsBool(435,0);
	setAsFloat(436,0.45);
	setAsFloat(437,0.39);
	setAsFloat(438,2.74);
	setAsFloat(439,0.07);
	setAsFloat(440,0.275);
	setAsFloat(441,0.245);
	setAsFloat(442,0.045);
	setAsFloat(443,0.05);
	setAsShort(444,0);
	setAsFloat(445,0);
	setAsFloat(446,0);
	setAsShort(447,0);
	setAsFloat(448,0);
	setAsFloat(449,0);
	setAsShort(450,0);
	setAsFloat(451,0);
	setAsFloat(452,0);
	setAsShort(453,0);
	setAsFloat(454,0);
	setAsFloat(455,0);
	setAsShort(456,0);
	setAsFloat(457,0);
	setAsFloat(458,0);
	setAsShort(459,0);
	setAsFloat(460,0);
	setAsFloat(461,0);
	setAsShort(462,0);
	setAsShort(463,0);
	setAsFloat(464,0);
	setAsShort(465,0);
	setAsShort(466,0);
	setAsFloat(467,0);
	setAsFloat(468,0);
	setAsFloat(469,0);
	setAsFloat(470,0);
	setAsFloat(471,0);
	setAsFloat(472,0);
	setAsFloat(473,0);
	setAsFloat(474,0);
	setAsShort(475,0);
	setAsShort(476,0);
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
	setAsFloat(559,0);
	setAsFloat(560,0);
	setAsShort(561,0);
	setAsFloat(562,0);
	setAsFloat(563,0);
	setAsShort(564,0);
	setAsFloat(565,0);
	setAsFloat(566,0);
	setAsShort(567,0);
	setAsFloat(568,0);
	setAsFloat(569,0);
	setAsShort(570,0);
	setAsFloat(571,0);
	setAsFloat(572,0);
	setAsBool(573,0);
	setAsBool(574,1);
	setAsBool(575,0);
	setAsBool(576,1);
	setAsBool(577,0);
	setAsShort(578,0);
	setAsFloat(579,0);
	setAsFloat(580,0);
	setAsShort(581,0);
	setAsFloat(582,0);
	setAsFloat(583,0);
	setAsShort(584,0);
	setAsFloat(585,0);
	setAsFloat(586,0);
	setAsShort(587,0);
	setAsFloat(588,0);
	setAsFloat(589,0);
	setAsBool(590,1);
	setAsFloat(591,0.01);
	setAsFloat(592,0.01);
	setAsFloat(593,0.01);
	setAsShort(594,0);
	setAsShort(595,0);
	setAsShort(596,0);
	setAsFloat(597,25.017338);
	setAsFloat(598,-0.15912805);
	setAsFloat(599,0.000000166);
	setAsFloat(600,25.017338);
	setAsFloat(601,0);
	setAsFloat(602,0.000167646);
	setAsFloat(603,0);
	setAsFloat(604,0);
	setAsFloat(605,0);
	setAsFloat(606,0);
	setAsFloat(607,0.000167676);
	setAsFloat(608,0);
	setAsFloat(609,0);
	setAsFloat(610,0);
	setAsFloat(611,0);
	setAsFloat(612,0);
	setAsFloat(613,0);
	setAsFloat(614,0);
	setAsFloat(615,0);
	setAsFloat(616,0);
	setAsFloat(617,0);
	setAsFloat(618,0);
	setAsFloat(619,0.000885839);
	setAsFloat(620,0);
	setAsFloat(621,0.000885839);
	setAsFloat(622,0);
	setAsFloat(623,0.000885839);
	setAsFloat(624,0);
	setAsFloat(625,0.000885839);
	setAsFloat(626,0);
	setAsFloat(627,390);
	setAsFloat(628,0);
	setAsFloat(629,390);
	setAsFloat(630,0);
	setAsFloat(631,55);
	setAsFloat(632,0);
	setAsFloat(633,55);
	setAsFloat(634,0);
	setAsFloat(635,0);
	setAsFloat(636,0);
	setAsFloat(637,4000.0);
	setAsFloat(638,0);
	setAsFloat(639,10);
	setAsFloat(640,0);
	setAsFloat(641,0);
	setAsFloat(642,0);
	setAsFloat(643,0);
	setAsFloat(644,0);
	setAsFloat(645,5);
	setAsFloat(646,0);
	setAsFloat(647,5);
	setAsFloat(648,0);
	setAsFloat(649,0);
	setAsFloat(650,0);
	setAsFloat(651,0);
	setAsFloat(652,0);
	setAsFloat(653,0);
	setAsFloat(654,0);
	setAsFloat(655,0);
	setAsFloat(656,0);
	setAsFloat(657,15650);
	setAsFloat(658,0);
	setAsFloat(659,0);
	setAsShort(660,0);
	setAsShort(661,0);
	setAsFloat(662,506.6);
	setAsShort(663,0);
	setAsShort(664,0);
	setAsShort(665,0);
	setAsShort(666,0);
	setAsShort(667,0);
	setAsShort(668,0);
	setAsShort(669,0);
	setAsShort(670,0);
	setAsShort(671,0);
	setAsShort(672,0);
	setAsShort(673,0);
	setAsShort(674,0);
	setAsShort(675,0);
	setAsShort(676,0);
	setAsFloat(677,5065.0);
	setAsFloat(678,1.0);
	setAsFloat(679,1.0);
	setAsFloat(680,1.0);
	setAsFloat(681,1570.0);
	setAsFloat(682,1269);
	setAsFloat(683,1281.2);
	setAsFloat(684,248.0);
	setAsFloat(685,572.4);
	setAsFloat(686,246.8);
	setAsFloat(687,1);
}
uspaint8 InternalBuf[814];

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
ssint iRM_719_ = {719,0}; /* min - ����������� ��������� �������� ��������� ������� */ 
ssint iRM_4195_ = {4195,0}; /* max - ������������ ��������� �������� ��������� ������� */ 
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

uspaint8 SpaEEPROMBuf[1776];

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
psbool  array_m357_x_1[16] = {&lEM_R8AD10LC1,&lEM_R8AD10LC1,&var329,&var187,&var181,&var271,&var269,&var263,&var260,&var276,&var319,&var314,&var305,&var295,&var289,&R0MW13LP2};
psbool  array_m923_x_1[2] = {&lEM_R0IE02LRP,&lEM_R0IE01LRP};
psbool  array_m918_x_1[2] = {&var167,&R0MW13LP2};
psbool  array_m943_x_1[2] = {&var174,&R0MW13LP2};
psbool  array_m936_x_1[2] = {&var175,&R0MW13LP2};
psbool  array_m928_x_1[2] = {&var176,&R0MW13LP2};
psbool  array_m634_x_1[2] = {&var32,&var228};
psbool  array_m631_x_1[2] = {&var32,&var229};
psbool  array_m641_x_1[3] = {&lEM_C1AD31LRP,&R0VZ71LZ1,&R0VZ71LZ2};
psbool  array_m920_x_1[2] = {&var199,&R0MW13LP2};
psbool  array_m292_x_1[2] = {&var216,&B3AD31LDU};
psbool  array_m257_x_1[3] = {&B2AD31LDU,&var202,&var216};
psbool  array_m258_x_1[3] = {&B2AD32LDU,&var202,&var216};
psbool  array_m218_x_1[4] = {&B1AD32LDU,&var205,&var204,&var216};
psbool  array_m217_x_1[4] = {&var205,&B1AD31LDU,&var204,&var216};
psbool  array_m121_x_1[2] = {&A3AD31LDU,&var216};
psbool  array_m48_x_1[4] = {&A1AD32LDU,&var210,&var209,&var216};
psbool  array_m47_x_1[4] = {&var210,&A1AD31LDU,&var209,&var216};
psbool  array_m87_x_1[3] = {&A2AD31LDU,&var214,&var216};
psbool  array_m88_x_1[3] = {&A2AD32LDU,&var214,&var216};
psbool  array_m647_x_1[2] = {&var227,&var31};
psfloat  array_m7_a_1[5] = {&fRM_390_,&fRM_600_,&fRM_900_,&fRM_1200_,&fRM_1500_};
psfloat  array_m7_b_1[5] = {&fRM_0_5,&fRM_0_2,&fRM_0_088884,&fRM_0_066666667,&fRM_0_02173913};
psfloat  array_m9_a_1[7] = {&fRM_390_,&fRM_420_,&fRM_513_,&fRM_767_,&fRM_900_,&fRM_1200_,&fRM_1500_};
psfloat  array_m9_b_1[7] = {&fRM_3_546,&fRM_2_7,&fRM_2_,&fRM_0_88884,&fRM_0_6221739,&fRM_0_35555072,&fRM_0_2666666667};
psfloat  array_m182_C0_1[6];
psfloat  array_m300_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m130_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m267_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m96_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m229_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m60_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m14_C0_1[6];

/* ���������� �������� */
_S_to3val  S_to3val_972_1 = {&fEM_R7UX16RSS,&fRM_900_,&fRM_15_,&fRM_0_0015,&fRM_0_,&fRM_2000_,&fRM_2000_,&TerR0IN06FRP,&var1,&var2,&vainSFloat,&bFirstEnterFlag};
_S_vchs  S_vchs_897_1 = {&var280,&var331,&var241,&fEM_R4UC23RIM,&fEM_R7UY00RSS,&fEM_R7UX15RSS,&fEM_R7UY15RSS,&bRM_5_,&fEM_A0UX15RSS,&fEM_B0UX05RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var3,&internal1_m897_Chim0};
_S_vchs  S_vchs_887_1 = {&var331,&var280,&var241,&fEM_R4UC23RIM,&fEM_R7UY00RSS,&fEM_R7UX14RSS,&fEM_R7UY14RSS,&bRM_4_,&fEM_A0UX14RSS,&fEM_B0UX04RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var4,&internal1_m887_Chim0};
_S_vchs  S_vchs_879_1 = {&var331,&var280,&var241,&fEM_R4UC23RIM,&fEM_R7UY00RSS,&fEM_R7UX13RSS,&fEM_R7UY13RSS,&bRM_2_,&fEM_A0UX13RSS,&fEM_B0UX03RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var5,&internal1_m879_Chim0};
_S_twobool  S_twobool_834_1 = {&var278,&iEM_TERR4VS22LDU,&var6,&vainSBool,&internal1_m834_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_833_1 = {&var277,&iEM_TERR4VS12LDU,&var7,&vainSBool,&internal1_m833_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1017_1 = {&var254,&iEM_TERR2VS22LIM,&var8,&vainSBool,&internal1_m1017_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1016_1 = {&var253,&iEM_TERR2VS12LIM,&var9,&vainSBool,&internal1_m1016_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1015_1 = {&var258,&iEM_TERR1VS22LIM,&var10,&vainSBool,&internal1_m1015_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1014_1 = {&var257,&iEM_TERR1VS12LIM,&var11,&vainSBool,&internal1_m1014_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_693_1 = {&var246,&iEM_TERB5VS22LIM,&var12,&vainSBool,&internal1_m693_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_692_1 = {&var245,&iEM_TERB5VS12LIM,&var13,&vainSBool,&internal1_m692_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_671_1 = {&var250,&iEM_TERA5VS22LIM,&var14,&vainSBool,&internal1_m671_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_670_1 = {&var249,&iEM_TERA5VS12LIM,&var15,&vainSBool,&internal1_m670_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_691_1 = {&var262,&iEM_TERB6VS22LIM,&var16,&vainSBool,&internal1_m691_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_690_1 = {&var261,&iEM_TERB6VS12LIM,&var17,&vainSBool,&internal1_m690_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_669_1 = {&var266,&iEM_TERA6VS22LIM,&var18,&vainSBool,&internal1_m669_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_668_1 = {&var265,&iEM_TERA6VS12LIM,&var19,&vainSBool,&internal1_m668_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_529_1 = {&var37,&iEM_TERA1VP81LIM,&var20,&vainSBool,&internal1_m529_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_545_1 = {&var37,&iEM_TERB1VP81LIM,&var21,&vainSBool,&internal1_m545_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_411_1 = {&var305,&iEM_TERB2SS33LIM,&var22,&vainSBool,&internal1_m411_Out10,&bFirstEnterFlag};
_S_noto  S_noto_490_1 = {&var183,&var23};
_S_noto  S_noto_491_1 = {&var182,&var24};
_S_noto  S_noto_478_1 = {&var184,&var25};
_S_noto  S_noto_481_1 = {&var185,&var26};
_S_rs  S_rs_488_1 = {&var24,&lEM_R5AD10LC1,&var27,&vainSBool,&internal1_m488_q0};
_S_rs  S_rs_489_1 = {&var23,&lEM_R5AD20LC1,&var28,&vainSBool,&internal1_m489_q0};
_S_rs  S_rs_474_1 = {&var25,&lEM_R3AD10LC1,&var29,&vainSBool,&internal1_m474_q0};
_S_rs  S_rs_475_1 = {&var26,&lEM_R3AD20LC1,&var30,&vainSBool,&internal1_m475_q0};
_S_andn  S_andn_357_1 = {array_m357_x_1,&iRM_16_,&vainSBool};
_S_zpfs  S_zpfs_644_1 = {&R0AD14LDU,&fEM_R7UI76RIM,&var31,&internal1_m644_tx,&internal1_m644_y0};
_S_zpfs  S_zpfs_632_1 = {&R0AD16LDU,&fEM_R7UI77RIM,&var32,&internal1_m632_tx,&internal1_m632_y0};
_S_bol  S_bol_958_1 = {&fEM_A4UP01RIM,&fEM_A4UP02RIM,&var33};
_S_bol  S_bol_955_1 = {&fEM_A3UP01RIM,&fEM_A3UP02RIM,&var34};
_S_bol  S_bol_934_1 = {&fEM_A0UP02RIM,&fEM_A0UP01RIM,&var35};
_S_bol  S_bol_956_1 = {&fEM_A2UP02RIM,&fEM_A2UP03RIM,&var36};
_S_bol  S_bol_946_1 = {&fEM_A1UP01RIM,&fEM_A1UP82RIM,&var37};
_S_ampl  S_ampl_374_1 = {&var218,&fRM_0_1,&vainSFloat};
_S_or2  S_or2_947_1 = {&R0EE04LZ1,&R0EE04LZ2,&var38};
_S_or2  S_or2_938_1 = {&R0EE03LZ1,&R0EE03LZ2,&var39};
_S_or2  S_or2_931_1 = {&R0EE02LZ1,&R0EE02LZ2,&var40};
_S_or2  S_or2_924_1 = {&R0EE01LZ1,&R0EE01LZ2,&var41};
_S_zpfs  S_zpfs_618_1 = {&var186,&fRM_1_0,&var42,&internal1_m618_tx,&internal1_m618_y0};
_S_zpfs  S_zpfs_616_1 = {&var189,&fRM_0_5,&var43,&internal1_m616_tx,&internal1_m616_y0};
_S_twobool  S_twobool_208_1 = {&B1AD21LDU,&iEM_TERB1IE04LDU,&var44,&vainSBool,&internal1_m208_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_226_1 = {&B1AD11LDU,&iEM_TERB1IE03LDU,&var45,&vainSBool,&internal1_m226_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_41_1 = {&A1AD21LDU,&iEM_TERA1IE04LDU,&var46,&vainSBool,&internal1_m41_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_56_1 = {&A1AD11LDU,&iEM_TERA1IE03LDU,&var47,&vainSBool,&internal1_m56_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_988_1 = {&var322,&iEM_TERB1SS12LIM,&var48,&vainSBool,&internal1_m988_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_985_1 = {&var318,&iEM_TERB1SS11LIM,&var49,&vainSBool,&internal1_m985_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_984_1 = {&var319,&iEM_TERB1SS21LIM,&var50,&vainSBool,&internal1_m984_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_987_1 = {&var52,&fEM_A1UC03RDU,&fRM_0_,&iRM_0_,&var51,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m987_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_982_1 = {&var221,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB1MC01RIM,&var52,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_970_1 = {&var54,&fEM_A1UC03RDU,&fRM_0_,&iRM_0_,&var53,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m970_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_963_1 = {&var222,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA1SC01RIM,&var54,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_971_1 = {&var329,&iEM_TERA1SS12LIM,&var55,&vainSBool,&internal1_m971_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_968_1 = {&var326,&iEM_TERA1SS11LIM,&var56,&vainSBool,&internal1_m968_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_967_1 = {&var327,&iEM_TERA1SS21LIM,&var57,&vainSBool,&internal1_m967_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1055_1 = {&var260,&iEM_TERB6SS21LIM,&var58,&vainSBool,&internal1_m1055_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1036_1 = {&var259,&iEM_TERB6SS11LIM,&var59,&vainSBool,&internal1_m1036_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1035_1 = {&var264,&iEM_TERA6SS21LIM,&var60,&vainSBool,&internal1_m1035_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1034_1 = {&var263,&iEM_TERA6MS11LIM,&var61,&vainSBool,&internal1_m1034_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_855_1 = {&var269,&iEM_TERA8SS12LIM,&var62,&vainSBool,&internal1_m855_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_857_1 = {&var268,&iEM_TERA8SS22LIM,&var63,&vainSBool,&internal1_m857_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_854_1 = {&var272,&iEM_TERB8SS12LIM,&var64,&var65,&internal1_m854_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_856_1 = {&var271,&iEM_TERB8SS22LIM,&var66,&var67,&internal1_m856_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_830_1 = {&var273,&iEM_TERR4SS12LIM,&var68,&vainSBool,&internal1_m830_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_831_1 = {&var274,&iEM_TERR4SS22LIM,&var69,&vainSBool,&internal1_m831_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_829_1 = {&var276,&iEM_TERR4MS21LIM,&var70,&vainSBool,&internal1_m829_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_828_1 = {&var275,&iEM_TERR4SS11LIM,&var71,&vainSBool,&internal1_m828_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1050_1 = {&var33,&iEM_TERA4VP82LIM,&var72,&var73,&internal1_m1050_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1002_1 = {&var252,&iEM_TERR2SS21LIM,&var74,&vainSBool,&internal1_m1002_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1001_1 = {&var251,&iEM_TERR2SS11LIM,&var75,&vainSBool,&internal1_m1001_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1000_1 = {&var256,&iEM_TERR1SS21LIM,&var76,&vainSBool,&internal1_m1000_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_999_1 = {&var255,&iEM_TERR1SS11LIM,&var77,&vainSBool,&internal1_m999_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1051_1 = {&var191,&iEM_TERB4SS21LIM,&var78,&vainSBool,&internal1_m1051_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1032_1 = {&var190,&iEM_TERB4SS11LIM,&var79,&vainSBool,&internal1_m1032_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_832_1 = {&lEM_R8AD10LC1,&iEM_TERR8SS11LIM,&var80,&vainSBool,&internal1_m832_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1033_1 = {&var188,&iEM_TERA4SS21LIM,&var81,&vainSBool,&internal1_m1033_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1031_1 = {&var187,&iEM_TERA4SS11LIM,&var82,&vainSBool,&internal1_m1031_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1052_1 = {&var183,&iEM_TERR5SS21LIM,&var83,&vainSBool,&internal1_m1052_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1030_1 = {&var182,&iEM_TERR5SS11LIM,&var84,&vainSBool,&internal1_m1030_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1013_1 = {&var185,&iEM_TERR3SS21LIM,&var85,&vainSBool,&internal1_m1013_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_998_1 = {&var184,&iEM_TERR3SS11LIM,&var86,&vainSBool,&internal1_m998_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_546_1 = {&var36,&iEM_TERA2VP82LIM,&var87,&var88,&internal1_m546_Out10,&bFirstEnterFlag};
_S_toao  S_toao_550_1 = {&var92,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var89,&bFirstEnterFlag};
_S_toao  S_toao_549_1 = {&var91,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var90,&bFirstEnterFlag};
_S_to3val  S_to3val_543_1 = {&var149,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A2UP03RDU,&fEM_A2UP03RDU,&iEM_TERB2SP01RIM,&var91,&vainSFloat,&var92,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_421_1 = {&var94,&fEM_A2UC03RDU,&fRM_0_,&iRM_0_,&var93,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m421_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_415_1 = {&var220,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB2SC01RIM,&var94,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_412_1 = {&var307,&iEM_TERB2SS12LIM,&var95,&vainSBool,&internal1_m412_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_414_1 = {&var302,&iEM_TERB2SS11LIM,&var96,&vainSBool,&internal1_m414_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_413_1 = {&var303,&iEM_TERB2SS21LIM,&var97,&vainSBool,&internal1_m413_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_870_1 = {&var197,&iEM_TERB9SS21LIM,&var98,&vainSBool,&internal1_m870_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_871_1 = {&var196,&iEM_TERB9SS11LIM,&var99,&vainSBool,&internal1_m871_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_869_1 = {&var194,&iEM_TERA9SS21LIM,&var100,&vainSBool,&internal1_m869_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1054_1 = {&var193,&iEM_TERA9SS11LIM,&var101,&vainSBool,&internal1_m1054_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_706_1 = {&var244,&iEM_TERB5SS21LIM,&var102,&vainSBool,&internal1_m706_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_707_1 = {&var243,&iEM_TERB5SS11LIM,&var103,&vainSBool,&internal1_m707_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_704_1 = {&var248,&iEM_TERA5SS21LIM,&var104,&vainSBool,&internal1_m704_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_705_1 = {&var247,&iEM_TERA5SS11LIM,&var105,&vainSBool,&internal1_m705_Out10,&bFirstEnterFlag};
_S_ampl  S_ampl_657_1 = {&var226,&fEM_R7UI75RIM,&var106};
_S_to3val  S_to3val_658_1 = {&var106,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R7UI74RIM,&fEM_R7UI74RIM,&iEM_TERR7SI74RIM,&vainSFloat,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_562_1 = {&var35,&iEM_TERB0VP81LIM,&var107,&vainSBool,&internal1_m562_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_561_1 = {&var35,&iEM_TERA0VP81LIM,&var108,&vainSBool,&internal1_m561_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_851_1 = {&var110,&fEM_A8UC03RDU,&fRM_0_,&iRM_0_,&var109,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m851_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_843_1 = {&var270,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB8SC01RIM,&var110,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_853_1 = {&var112,&fEM_A8UC03RDU,&fRM_0_,&iRM_0_,&var111,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m853_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_845_1 = {&var267,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA8SC01RIM,&var112,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_703_1 = {&R0MW13LP2,&iEM_TERR6IS68LIM,&var113,&vainSBool,&internal1_m703_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_687_1 = {&R0MW13LP2,&iEM_TERR6IS67LIM,&var114,&vainSBool,&internal1_m687_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_667_1 = {&R0MW13LP2,&iEM_TERR6IS66LIM,&var115,&vainSBool,&internal1_m667_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_686_1 = {&R0MW13LP2,&iEM_TERR6IS64LIM,&var116,&var117,&internal1_m686_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_666_1 = {&R0MW13LP2,&iEM_TERR6IS62LIM,&var118,&var119,&internal1_m666_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_339_1 = {&var288,&iEM_TERB3SS22LIM,&var120,&vainSBool,&internal1_m339_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_338_1 = {&var295,&iEM_TERA3SS22LIM,&var121,&vainSBool,&internal1_m338_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_323_1 = {&var289,&iEM_TERB3SS11LIM,&var122,&vainSBool,&internal1_m323_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_322_1 = {&var296,&iEM_TERA3SS11LIM,&var123,&vainSBool,&internal1_m322_Out10,&bFirstEnterFlag};
_S_toao  S_toao_524_1 = {&var125,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var124,&bFirstEnterFlag};
_S_to3val  S_to3val_517_1 = {&var171,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A3UP03RDU,&fEM_A3UP03RDU,&iEM_TERA3SP02RIM,&vainSFloat,&var125,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_563_1 = {&var34,&iEM_TERA3VP81LIM,&var126,&var127,&internal1_m563_Out10,&bFirstEnterFlag};
_S_toao  S_toao_528_1 = {&var129,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var128,&bFirstEnterFlag};
_S_to3val  S_to3val_520_1 = {&var169,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A3UP03RDU,&fEM_A3UP03RDU,&iEM_TERB3SP02RIM,&vainSFloat,&var129,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_352_1 = {&var292,&iEM_TERB3SS33LIM,&var130,&vainSBool,&internal1_m352_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_336_1 = {&var132,&fEM_A3UC03RDU,&fRM_0_,&iRM_0_,&var131,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m336_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_335_1 = {&var287,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB3SC01RIM,&var132,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_351_1 = {&var291,&iEM_TERB3SS31LIM,&var133,&vainSBool,&internal1_m351_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_349_1 = {&var299,&iEM_TERA3SS33LIM,&var134,&vainSBool,&internal1_m349_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_329_1 = {&var136,&fEM_A3UC03RDU,&fRM_0_,&iRM_0_,&var135,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m329_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_325_1 = {&var294,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA3SC01RIM,&var136,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_350_1 = {&var298,&iEM_TERA3SS31LIM,&var137,&vainSBool,&internal1_m350_Out10,&bFirstEnterFlag};
_S_toao  S_toao_548_1 = {&var150,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var138,&bFirstEnterFlag};
_S_toao  S_toao_547_1 = {&var148,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var139,&bFirstEnterFlag};
_S_twobool  S_twobool_321_1 = {&var290,&iEM_TERB3SS21LIM,&var140,&vainSBool,&internal1_m321_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_337_1 = {&var297,&iEM_TERA3SS21LIM,&var141,&vainSBool,&internal1_m337_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_433_1 = {&var313,&iEM_TERA2SS33LIM,&var142,&vainSBool,&internal1_m433_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_434_1 = {&var144,&fEM_A2UC03RDU,&fRM_0_,&iRM_0_,&var143,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m434_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_429_1 = {&var219,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA2SC01RIM,&var144,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_432_1 = {&var315,&iEM_TERA2SS12LIM,&var145,&vainSBool,&internal1_m432_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_431_1 = {&var310,&iEM_TERA2SS11LIM,&var146,&vainSBool,&internal1_m431_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_430_1 = {&var311,&iEM_TERA2SS21LIM,&var147,&vainSBool,&internal1_m430_Out10,&bFirstEnterFlag};
_S_to3val  S_to3val_542_1 = {&fEM_A2UP01RIM,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A2UP03RDU,&fEM_A2UP03RDU,&iEM_TERA2SP01RIM,&var148,&var149,&var150,&bFirstEnterFlag};
_S_toao  S_toao_163_1 = {&var156,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var151,&bFirstEnterFlag};
_S_toao  S_toao_162_1 = {&var155,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var152,&bFirstEnterFlag};
_S_toao  S_toao_161_1 = {&var154,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var153,&bFirstEnterFlag};
_S_to3val  S_to3val_156_1 = {&var282,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R0UT02RDU,&fEM_R0UT02RDU,&iEM_TERB0MT01RIM,&var154,&var155,&var156,&bFirstEnterFlag};
_S_toao  S_toao_166_1 = {&var164,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var157,&bFirstEnterFlag};
_S_toao  S_toao_165_1 = {&var163,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var158,&bFirstEnterFlag};
_S_twobool  S_twobool_1053_1 = {&var181,&iEM_TERR6SS21LIM,&var159,&vainSBool,&internal1_m1053_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_150_1 = {&var283,&iEM_TERB7MS31LIM,&var160,&vainSBool,&internal1_m150_Out10,&bFirstEnterFlag};
_S_toao  S_toao_164_1 = {&var162,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var161,&bFirstEnterFlag};
_S_to3val  S_to3val_158_1 = {&var333,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R0UT02RDU,&fEM_R0UT02RDU,&iEM_TERA0MT01RIM,&var162,&var163,&var164,&bFirstEnterFlag};
_S_twobool  S_twobool_149_1 = {&var334,&iEM_TERA7MS31LIM,&var165,&vainSBool,&internal1_m149_Out10,&bFirstEnterFlag};
_S_orn  S_orn_923_1 = {array_m923_x_1,&iRM_2_,&var166};
_S_andn  S_andn_918_1 = {array_m918_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_922_1 = {&var166,&var167};
_S_noto  S_noto_515_1 = {&B3AD34LDU,&var168};
_S_lk  S_lk_519_1 = {&fEM_A3UP02RDU,&var168,&var169};
_S_noto  S_noto_513_1 = {&A3AD34LDU,&var170};
_S_lk  S_lk_518_1 = {&fEM_A3UP02RDU,&var170,&var171};
_S_ovb1  S_ovb1_197_1 = {&R8AD21LDU,&iRM_500_,&var172,&internal1_m197_tx};
_S_ovb1  S_ovb1_25_1 = {&R8AD21LDU,&iRM_500_,&var173,&internal1_m25_tx};
_S_andn  S_andn_943_1 = {array_m943_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_948_1 = {&var38,&var174};
_S_andn  S_andn_936_1 = {array_m936_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_939_1 = {&var39,&var175};
_S_andn  S_andn_928_1 = {array_m928_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_932_1 = {&var40,&var176};
_S_orn  S_orn_634_1 = {array_m634_x_1,&iRM_2_,&var177};
_S_orn  S_orn_631_1 = {array_m631_x_1,&iRM_2_,&var178};
_S_react  S_react_200_1 = {&var284,&var179};
_S_noto  S_noto_476_1 = {&lEM_R6AD10LC1,&var180};
_S_asmot  S_asmot_480_1 = {&var180,&lEM_R6AD10LC1,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R6UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R6UC01RSP,&fEM_R6UV01RSP,&vainSFloat,&var181,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m480_Pav0,&internal1_m480_Zav0,&internal1_m480_Pv0,&internal1_m480_Zv0,&internal1_m480_RA00,&internal1_m480_RA10,&internal1_m480_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_492_1 = {&var27,&var28,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R5UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R5UC01RSP,&fEM_R5UV01RSP,&vainSFloat,&var182,&var183,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m492_Pav0,&internal1_m492_Zav0,&internal1_m492_Pv0,&internal1_m492_Zv0,&internal1_m492_RA00,&internal1_m492_RA10,&internal1_m492_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_479_1 = {&var29,&var30,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R3UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R3UC01RSP,&fEM_R3UV01RSP,&vainSFloat,&var184,&var185,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m479_Pav0,&internal1_m479_Zav0,&internal1_m479_Pv0,&internal1_m479_Zv0,&internal1_m479_RA00,&internal1_m479_RA10,&internal1_m479_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_617_1 = {&A4AD10LDU,&var186};
_S_asmot  S_asmot_623_1 = {&var186,&A4AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,&fEM_A4UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_A4MC01RSP,&fEM_A4MV01RSP,&vainSFloat,&var187,&var188,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m623_Pav0,&internal1_m623_Zav0,&internal1_m623_Pv0,&internal1_m623_Zv0,&internal1_m623_RA00,&internal1_m623_RA10,&internal1_m623_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_615_1 = {&B4AD10LDU,&var189};
_S_asmot  S_asmot_620_1 = {&var189,&B4AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_A4UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_B4MC01RSP,&fEM_B4MV01RSP,&vainSFloat,&var190,&var191,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m620_Pav0,&internal1_m620_Zav0,&internal1_m620_Pv0,&internal1_m620_Zv0,&internal1_m620_RA00,&internal1_m620_RA10,&internal1_m620_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_604_1 = {&A9AD10LDU,&var192};
_S_asmot  S_asmot_606_1 = {&var192,&A9AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,&fEM_A9UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_A9MC01RSP,&fEM_A9MV01RSP,&vainSFloat,&var193,&var194,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m606_Pav0,&internal1_m606_Zav0,&internal1_m606_Pv0,&internal1_m606_Zv0,&internal1_m606_RA00,&internal1_m606_RA10,&internal1_m606_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_603_1 = {&B9AD10LDU,&var195};
_S_asmot  S_asmot_605_1 = {&var195,&B9AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_A9UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_B9MC01RSP,&fEM_B9MV01RSP,&vainSFloat,&var196,&var197,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m605_Pav0,&internal1_m605_Zav0,&internal1_m605_Pv0,&internal1_m605_Zv0,&internal1_m605_RA00,&internal1_m605_RA10,&internal1_m605_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orn  S_orn_641_1 = {array_m641_x_1,&iRM_3_,&var198};
_S_andn  S_andn_920_1 = {array_m920_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_925_1 = {&var41,&var199};
_S_andn  S_andn_292_1 = {array_m292_x_1,&iRM_2_,&var200};
_S_andn  S_andn_257_1 = {array_m257_x_1,&iRM_3_,&var201};
_S_noto  S_noto_256_1 = {&C2MD31LP1,&var202};
_S_andn  S_andn_258_1 = {array_m258_x_1,&iRM_3_,&var203};
_S_noto  S_noto_216_1 = {&C1MD31LP2,&var204};
_S_noto  S_noto_215_1 = {&C1MD31LP1,&var205};
_S_andn  S_andn_218_1 = {array_m218_x_1,&iRM_4_,&var206};
_S_andn  S_andn_217_1 = {array_m217_x_1,&iRM_4_,&var207};
_S_andn  S_andn_121_1 = {array_m121_x_1,&iRM_2_,&var208};
_S_noto  S_noto_46_1 = {&C1MD31LP2,&var209};
_S_noto  S_noto_45_1 = {&C1MD31LP1,&var210};
_S_andn  S_andn_48_1 = {array_m48_x_1,&iRM_4_,&var211};
_S_andn  S_andn_47_1 = {array_m47_x_1,&iRM_4_,&var212};
_S_andn  S_andn_87_1 = {array_m87_x_1,&iRM_3_,&var213};
_S_noto  S_noto_86_1 = {&C2MD31LP1,&var214};
_S_andn  S_andn_88_1 = {array_m88_x_1,&iRM_3_,&var215};
_S_noto  S_noto_639_1 = {&var198,&var216};
_S_orn  S_orn_647_1 = {array_m647_x_1,&iRM_2_,&var217};
_S_fsubo  S_fsubo_373_1 = {&fEM_R7UY00RSS,&var270,&var218};
_S_fsubo  S_fsubo_115_1 = {&fEM_A2UC05RIM,&var309,&var219};
_S_fsubo  S_fsubo_285_1 = {&fEM_A2UC05RIM,&var301,&var220};
_S_fsubo  S_fsubo_244_1 = {&fEM_A1UC05RIM,&var317,&var221};
_S_fsubo  S_fsubo_74_1 = {&fEM_A1UC05RIM,&var324,&var222};
_S_fsubo  S_fsubo_8_1 = {&var224,&fEM_R0UR01RIM,&var223};
_S_inf  S_inf_7_1 = {&var270,array_m7_a_1,array_m7_b_1,&iRM_5_,&var224,&vainSInt};
_S_inf  S_inf_9_1 = {&var270,array_m9_a_1,array_m9_b_1,&iRM_7_,&var225,&vainSInt};
_S_mod1  S_mod1_652_1 = {&var285,&fEM_R7UI02RIM,&fEM_R7UL01RIM,&var226,&internal1_m652_y0};
_S_bol  S_bol_646_1 = {&var285,&fEM_R7UI73RIM,&var227};
_S_bol  S_bol_636_1 = {&var285,&fEM_R7UI72RIM,&var228};
_S_bol  S_bol_630_1 = {&var285,&fEM_R7UI71RIM,&var229};
_S_vchs  S_vchs_816_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX12RSS,&fEM_R7UY12RSS,&bRM_5_,&fEM_A0UX12RSS,&fEM_B0UX12RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var230,&internal1_m816_Chim0};
_S_vchs  S_vchs_807_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX11RSS,&fEM_R7UY11RSS,&bRM_4_,&fEM_A0UX11RSS,&fEM_B0UX11RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var231,&internal1_m807_Chim0};
_S_vchs  S_vchs_799_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX10RSS,&fEM_R7UY10RSS,&bRM_1_,&fEM_A0UX10RSS,&fEM_B0UX10RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var232,&internal1_m799_Chim0};
_S_vchs  S_vchs_790_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX09RSS,&fEM_R7UY09RSS,&bRM_5_,&fEM_A0UX09RSS,&fEM_B0UX09RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var233,&internal1_m790_Chim0};
_S_vchs  S_vchs_781_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX08RSS,&fEM_R7UY08RSS,&bRM_4_,&fEM_A0UX08RSS,&fEM_B0UX08RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var234,&internal1_m781_Chim0};
_S_vchs  S_vchs_773_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX07RSS,&fEM_R7UY07RSS,&bRM_1_,&fEM_A0UX07RSS,&fEM_B0UX07RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var235,&internal1_m773_Chim0};
_S_vchs  S_vchs_764_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX06RSS,&fEM_R7UY06RSS,&bRM_5_,&fEM_A0UX06RSS,&fEM_B0UX06RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var236,&internal1_m764_Chim0};
_S_vchs  S_vchs_755_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX05RSS,&fEM_R7UY05RSS,&bRM_4_,&fEM_A0UX05RSS,&fEM_B0UX05RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var237,&internal1_m755_Chim0};
_S_vchs  S_vchs_747_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX04RSS,&fEM_R7UY04RSS,&bRM_2_,&fEM_A0UX04RSS,&fEM_B0UX04RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var238,&internal1_m747_Chim0};
_S_vchs  S_vchs_738_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UC10RIM,&fEM_R7UC19RIM,&bRM_5_,&fEM_A0UX03RSS,&fEM_B0UX03RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var239,&internal1_m738_Chim0};
_S_vchs  S_vchs_729_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX02RSS,&fEM_R7UY02RSS,&bRM_4_,&fEM_A0UX02RSS,&fEM_B0UX02RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var240,&internal1_m729_Chim0};
_S_fsumo  S_fsumo_914_1 = {&fEM_R4UC10RIM,&fEM_R4UC22RIM,&var241};
_S_vchs  S_vchs_719_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX01RSS,&fEM_R7UY01RSS,&bRM_2_,&fEM_A0UX01RSS,&fEM_B0UX01RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var242,&internal1_m719_Chim0};
_S_asmot  S_asmot_592_1 = {&B5AD10LDU,&B5AD20LDU,&fEM_B5MC01RC1,&fEM_B5MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERNL2,&fEM_A5UC10RIM,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,&fEM_B5MC01RSP,&fEM_B5MV01RSP,&vainSFloat,&var243,&var244,&vainSBool,&vainSBool,&vainSFloat,&var245,&var246,&internal1_m592_Pav0,&internal1_m592_Zav0,&internal1_m592_Pv0,&internal1_m592_Zv0,&internal1_m592_RA00,&internal1_m592_RA10,&internal1_m592_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_577_1 = {&A5AD10LDU,&A5AD20LDU,&fEM_A5MC01RC1,&fEM_A5MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERNL1,&fEM_A5UC10RIM,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,&fEM_A5MC01RSP,&fEM_A5MV01RSP,&vainSFloat,&var247,&var248,&vainSBool,&vainSBool,&vainSFloat,&var249,&var250,&internal1_m577_Pav0,&internal1_m577_Zav0,&internal1_m577_Pv0,&internal1_m577_Zv0,&internal1_m577_RA00,&internal1_m577_RA10,&internal1_m577_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_463_1 = {&R2AD10LDU,&R2AD20LDU,&fEM_R2MC01RC1,&fEM_R2MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERMDZ2,&fEM_R1UC10RIM,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,&fEM_R2MC01RSP,&fEM_R2MV01RSP,&vainSFloat,&var251,&var252,&vainSBool,&vainSBool,&vainSFloat,&var253,&var254,&internal1_m463_Pav0,&internal1_m463_Zav0,&internal1_m463_Pv0,&internal1_m463_Zv0,&internal1_m463_RA00,&internal1_m463_RA10,&internal1_m463_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_448_1 = {&R1AD10LDU,&R1AD20LDU,&fEM_R1MC01RC1,&fEM_R1MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERMDZ1,&fEM_R1UC10RIM,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,&fEM_R1MC01RSP,&fEM_R1MV01RSP,&vainSFloat,&var255,&var256,&vainSBool,&vainSBool,&vainSFloat,&var257,&var258,&internal1_m448_Pav0,&internal1_m448_Zav0,&internal1_m448_Pv0,&internal1_m448_Zv0,&internal1_m448_RA00,&internal1_m448_RA10,&internal1_m448_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_504_1 = {&B6AD10LDU,&B6AD20LDU,&fEM_B6MC01RC1,&fEM_B6MV01RC1,&fRM_1_0,&fEM_A6US80RDU,&iEM_TERBZ2,&fEM_A6UC10RIM,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,&fEM_B6MC01RSP,&fEM_B6MV01RSP,&vainSFloat,&var259,&var260,&vainSBool,&vainSBool,&vainSFloat,&var261,&var262,&internal1_m504_Pav0,&internal1_m504_Zav0,&internal1_m504_Pv0,&internal1_m504_Zv0,&internal1_m504_RA00,&internal1_m504_RA10,&internal1_m504_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_399_1 = {&A6AD10LDU,&A6AD20LDU,&fEM_A6MC01RC1,&fEM_A6MV01RC1,&fRM_1_0,&fEM_A6US80RDU,&iEM_TERBZ1,&fEM_A6UC10RIM,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,&fEM_A6MC01RSP,&fEM_A6MV01RSP,&vainSFloat,&var263,&var264,&vainSBool,&vainSBool,&vainSFloat,&var265,&var266,&internal1_m399_Pav0,&internal1_m399_Zav0,&internal1_m399_Pv0,&internal1_m399_Zv0,&internal1_m399_RA00,&internal1_m399_RA10,&internal1_m399_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_383_1 = {&A8AD20LDU,&A8AD10LDU,&fEM_A8MC01RC1,&fEM_A8MV01RC1,&fEM_A8UV80RDU,&fEM_A8US80RDU,&iEM_TERDS2,&fEM_A8UC10RIM,&fEM_A8UC20RIM,&fEM_A8UC11RIM,&fEM_A8UC21RIM,&fEM_A8UC08RDU,&fEM_A8MC01RSP,&fEM_A8MV01RSP,&var267,&var268,&var269,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m383_Pav0,&internal1_m383_Zav0,&internal1_m383_Pv0,&internal1_m383_Zv0,&internal1_m383_RA00,&internal1_m383_RA10,&internal1_m383_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_366_1 = {&B8AD20LDU,&B8AD10LDU,&fEM_B8MC01RC1,&fEM_B8MV01RC1,&fEM_B8UV80RDU,&fEM_B8US80RDU,&iEM_TERMAZ2,&fEM_B8UC10RIM,&fEM_B8UC20RIM,&fEM_B8UC11RIM,&fEM_B8UC21RIM,&fEM_B8UC08RDU,&fEM_B8MC01RSP,&fEM_B8MV01RSP,&var270,&var271,&var272,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m366_Pav0,&internal1_m366_Zav0,&internal1_m366_Pv0,&internal1_m366_Zv0,&internal1_m366_RA00,&internal1_m366_RA10,&internal1_m366_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_909_1 = {&R4AD10LDU,&R4AD20LDU,&fEM_R4MC01RC1,&fEM_R4MV01RC1,&fEM_R4UV80RDU,&fEM_R4US80RDU,&iEM_TERTLG,&fEM_R4UC10RIM,&fEM_R4UC20RIM,&fEM_R4UC10RIM,&fEM_R4UC20RIM,&fEM_R4UC08RDU,&fEM_R4MC01RSP,&fEM_R4MV01RSP,&vainSFloat,&var273,&var274,&var275,&var276,&vainSFloat,&var277,&var278,&internal1_m909_Pav0,&internal1_m909_Zav0,&internal1_m909_Pv0,&internal1_m909_Zv0,&internal1_m909_RA00,&internal1_m909_RA10,&internal1_m909_MyFirstEnterFlag,&bFirstEnterFlag};
_S_azbars  S_azbars_182_1 = {&var316,&var300,&var286,&var330,&fEM_R0UR30RIM,&B7AP31LDU,&var190,&lEM_R8AD10LC1,&var172,&fEM_R0UL01RIM,&fEM_R0UN02RIM,&fEM_R0UT01RIM,&fEM_R0UT02RIM,&fEM_R0UT04RIM,&fEM_R0UT05RIM,&fEM_R0UH05RSS,&fEM_A0UN02RIM,&fEM_A0UN01RIM,&fEM_A1UR00RIM,&fEM_A1UR01RIM,&fEM_A2UR00RIM,&fEM_A2UR01RIM,&fEM_A3UR00RIM,&fEM_A3UR01RIM,&var223,&var225,&fEM_R0UT03RIM,&fEM_R0UT06RIM,&fEM_A0UR02RSP,&fEM_A0UR01RSP,&fEM_B0UT03RSP,&var279,&var280,&var281,&var282,&var283,&var284,&var285,&internal1_m182_C1,&internal1_m182_C2,&internal1_m182_C3,&internal1_m182_C4,&internal1_m182_C5,&internal1_m182_C6,&internal1_m182_N20,array_m182_C0_1,&internal1_m182_ImpINI0,&internal1_m182_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_300_1 = {&B3AD11LDU,&B3AD21LDU,&B3AD02LDU,&B3AD01LDU,&B3AD03LDU,&B3AD04LDU,&B3AD05LDU,&var200,&B3AD33LDU,&lRM_1_,&fEM_B3MC01RC1,&fEM_B3MC02RC1,&fEM_B3MV01RC1,&fEM_B3MV02RC1,&lRM_0_,array_m300_Vr_1,&fEM_A3UC02RDU,&var169,&fEM_A3UP01RIM,&fEM_A3UG01RDU,&fEM_A3US07RDU,&fEM_A3UV02RIM,&iEM_TERIS2,&fEM_A3UC04RIM,&fEM_A3UC05RIM,&fEM_A3UC06RIM,&fEM_A3UC08RIM,&fEM_B3MC01RSP,&fEM_B3MC02RSP,&fEM_B3MV01RSP,&fEM_B3MV02RSP,&var286,&var287,&var288,&var289,&var290,&vainSFloat,&vainSFloat,&var291,&var292,&vainSBool,&vainSBool,&internal1_m300_Ppv0,&internal1_m300_Pav0,&internal1_m300_Zav0,&internal1_m300_RA00,&internal1_m300_RA10,&internal1_m300_RA50,&internal1_m300_fls,&internal1_m300_flp,&internal1_m300_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_130_1 = {&A3AD11LDU,&A3AD21LDU,&A3AD02LDU,&A3AD01LDU,&A3AD03LDU,&A3AD04LDU,&A3AD05LDU,&var208,&A3AD33LDU,&lRM_1_,&fEM_A3MC01RC1,&fEM_A3MC02RC1,&fEM_A3MV01RC1,&fEM_A3MV02RC1,&lRM_0_,array_m130_Vr_1,&fEM_A3UC02RDU,&var171,&fEM_A3UP01RIM,&fEM_A3UG01RDU,&fEM_A3US07RDU,&fEM_A3UV02RIM,&iEM_TERIS1,&fEM_A3UC04RIM,&fEM_A3UC05RIM,&fEM_A3UC06RIM,&fEM_A3UC08RIM,&fEM_A3MC01RSP,&fEM_A3MC02RSP,&fEM_A3MV01RSP,&fEM_A3MV02RSP,&var293,&var294,&var295,&var296,&var297,&vainSFloat,&vainSFloat,&var298,&var299,&vainSBool,&vainSBool,&internal1_m130_Ppv0,&internal1_m130_Pav0,&internal1_m130_Zav0,&internal1_m130_RA00,&internal1_m130_RA10,&internal1_m130_RA50,&internal1_m130_fls,&internal1_m130_flp,&internal1_m130_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_267_1 = {&B2AD11LDU,&B2AD21LDU,&B2AD02LDU,&B2AD01LDU,&B2AD03LDU,&B2AD04LDU,&B2AD05LDU,&var201,&B2AD33LDU,&var203,&fEM_B2MC01RC1,&fEM_B2MC02RC1,&fEM_B2MV01RC1,&fEM_B2MV02RC1,&lRM_1_,array_m267_Vr_1,&fEM_A2UC02RDU,&fEM_A2UP02RIM,&fEM_A2UP01RIM,&fEM_A2UG01RDU,&fEM_A2US07RDU,&fEM_A2UV02RIM,&iEM_TERRB2,&fEM_A2UC04RIM,&fEM_A2UC05RIM,&fEM_A2UC06RIM,&fEM_A2UC08RIM,&fEM_B2MC01RSP,&fEM_B2MC02RSP,&fEM_B2MV01RSP,&fEM_B2MV02RSP,&var300,&var301,&vainSBool,&var302,&var303,&vainSFloat,&vainSFloat,&var304,&var305,&var306,&var307,&internal1_m267_Ppv0,&internal1_m267_Pav0,&internal1_m267_Zav0,&internal1_m267_RA00,&internal1_m267_RA10,&internal1_m267_RA50,&internal1_m267_fls,&internal1_m267_flp,&internal1_m267_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_96_1 = {&A2AD11LDU,&A2AD21LDU,&A2AD02LDU,&A2AD01LDU,&A2AD03LDU,&A2AD04LDU,&A2AD05LDU,&var213,&A2AD33LDU,&var215,&fEM_A2MC01RC1,&fEM_A2MC02RC1,&fEM_A2MV01RC1,&fEM_A2MV02RC1,&lRM_1_,array_m96_Vr_1,&fEM_A2UC02RDU,&fEM_A2UP02RIM,&fEM_A2UP01RIM,&fEM_A2UG01RDU,&fEM_A2US07RDU,&fEM_A2UV02RIM,&iEM_TERRB1,&fEM_A2UC04RIM,&fEM_A2UC05RIM,&fEM_A2UC06RIM,&fEM_A2UC08RIM,&fEM_A2MC01RSP,&fEM_A2MC02RSP,&fEM_A2MV01RSP,&fEM_A2MV02RSP,&var308,&var309,&vainSBool,&var310,&var311,&vainSFloat,&vainSFloat,&var312,&var313,&var314,&var315,&internal1_m96_Ppv0,&internal1_m96_Pav0,&internal1_m96_Zav0,&internal1_m96_RA00,&internal1_m96_RA10,&internal1_m96_RA50,&internal1_m96_fls,&internal1_m96_flp,&internal1_m96_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_229_1 = {&B1AD11LDU,&B1AD21LDU,&B1AD02LDU,&B1AD01LDU,&B1AD03LDU,&B1AD04LDU,&B1AD05LDU,&var207,&lRM_1_,&var206,&fEM_B1MC01RC1,&fEM_B1MC02RC1,&fEM_B1MV01RC1,&fEM_B1MV02RC1,&lRM_1_,array_m229_Vr_1,&fEM_A1UC02RDU,&fRM_0_,&fEM_A1UP01RIM,&fEM_A1UG01RDU,&fEM_A1US07RDU,&fEM_A1UV02RIM,&iEM_TERBB2,&fEM_A1UC04RIM,&fEM_A1UC05RIM,&fEM_A1UC06RIM,&fEM_A1UC08RIM,&fEM_B1MC01RSP,&fEM_B1MC02RSP,&fEM_B1MV01RSP,&fEM_B1MV02RSP,&var316,&var317,&vainSBool,&var318,&var319,&vainSFloat,&vainSFloat,&var320,&vainSBool,&var321,&var322,&internal1_m229_Ppv0,&internal1_m229_Pav0,&internal1_m229_Zav0,&internal1_m229_RA00,&internal1_m229_RA10,&internal1_m229_RA50,&internal1_m229_fls,&internal1_m229_flp,&internal1_m229_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_60_1 = {&A1AD11LDU,&A1AD21LDU,&A1AD02LDU,&A1AD01LDU,&A1AD03LDU,&A1AD04LDU,&A1AD05LDU,&var212,&lRM_1_,&var211,&fEM_A1MC01RC1,&fEM_A1MC02RC1,&fEM_A1MV01RC1,&fEM_A1MV02RC1,&lRM_1_,array_m60_Vr_1,&fEM_A1UC02RDU,&fRM_0_,&fEM_A1UP01RIM,&fEM_A1UG01RDU,&fEM_A1US07RDU,&fEM_A1UV02RIM,&iEM_TERBB1,&fEM_A1UC04RIM,&fEM_A1UC05RIM,&fEM_A1UC06RIM,&fEM_A1UC08RIM,&fEM_A1MC01RSP,&fEM_A1MC02RSP,&fEM_A1MV01RSP,&fEM_A1MV02RSP,&var323,&var324,&var325,&var326,&var327,&vainSFloat,&vainSFloat,&vainSBool,&vainSBool,&var328,&var329,&internal1_m60_Ppv0,&internal1_m60_Pav0,&internal1_m60_Zav0,&internal1_m60_RA00,&internal1_m60_RA10,&internal1_m60_RA50,&internal1_m60_fls,&internal1_m60_flp,&internal1_m60_MyFirstEnterFlag,&bFirstEnterFlag};
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
if ((getAsShort(idR0MW11IP1) == 2) || (getAsShort(idR0MW11IP1) == 3)) { 
     freebuff = 0;
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  noto(&S_noto_86_1);
  noto(&S_noto_256_1);
  noto(&S_noto_603_1);
  noto(&S_noto_604_1);
  ovb1(&S_ovb1_25_1);
  ovb1(&S_ovb1_197_1);
  noto(&S_noto_515_1);
  bol(&S_bol_946_1);
  bol(&S_bol_956_1);
  bol(&S_bol_934_1);
  bol(&S_bol_955_1);
  bol(&S_bol_958_1);
  zpfs(&S_zpfs_632_1);
  zpfs(&S_zpfs_644_1);
  noto(&S_noto_481_1);
  noto(&S_noto_478_1);
  noto(&S_noto_491_1);
  noto(&S_noto_490_1);
  to3val(&S_to3val_972_1);
  asmot(&S_asmot_909_1);
  asmot(&S_asmot_366_1);
  asmot(&S_asmot_383_1);
  asmot(&S_asmot_399_1);
  asmot(&S_asmot_504_1);
  asmot(&S_asmot_448_1);
  asmot(&S_asmot_463_1);
  asmot(&S_asmot_577_1);
  asmot(&S_asmot_592_1);
  fsumo(&S_fsumo_914_1);
  inf(&S_inf_9_1);
  inf(&S_inf_7_1);
  fsubo(&S_fsubo_8_1);
  fsubo(&S_fsubo_373_1);
  noto(&S_noto_45_1);
  noto(&S_noto_46_1);
  noto(&S_noto_215_1);
  noto(&S_noto_216_1);
  orn(&S_orn_641_1);
  asmot(&S_asmot_605_1);
  asmot(&S_asmot_606_1);
  noto(&S_noto_615_1);
  noto(&S_noto_617_1);
  noto(&S_noto_476_1);
  noto(&S_noto_513_1);
  lk(&S_lk_519_1);
  orn(&S_orn_923_1);
  to3val(&S_to3val_542_1);
  toao(&S_toao_547_1);
  toao(&S_toao_548_1);
  to3val(&S_to3val_520_1);
  toao(&S_toao_528_1);
  twobool(&S_twobool_563_1);
  twobool(&S_twobool_666_1);
  twobool(&S_twobool_686_1);
  twobool(&S_twobool_667_1);
  twobool(&S_twobool_687_1);
  twobool(&S_twobool_703_1);
  to3val(&S_to3val_845_1);
  ktoenc(&S_ktoenc_853_1);
  to3val(&S_to3val_843_1);
  ktoenc(&S_ktoenc_851_1);
  twobool(&S_twobool_561_1);
  twobool(&S_twobool_562_1);
  twobool(&S_twobool_705_1);
  twobool(&S_twobool_704_1);
  twobool(&S_twobool_707_1);
  twobool(&S_twobool_706_1);
  twobool(&S_twobool_1054_1);
  twobool(&S_twobool_869_1);
  twobool(&S_twobool_871_1);
  twobool(&S_twobool_870_1);
  to3val(&S_to3val_543_1);
  toao(&S_toao_549_1);
  toao(&S_toao_550_1);
  twobool(&S_twobool_546_1);
  twobool(&S_twobool_998_1);
  twobool(&S_twobool_1013_1);
  twobool(&S_twobool_1030_1);
  twobool(&S_twobool_1052_1);
  twobool(&S_twobool_832_1);
  twobool(&S_twobool_999_1);
  twobool(&S_twobool_1000_1);
  twobool(&S_twobool_1001_1);
  twobool(&S_twobool_1002_1);
  twobool(&S_twobool_1050_1);
  twobool(&S_twobool_828_1);
  twobool(&S_twobool_829_1);
  twobool(&S_twobool_831_1);
  twobool(&S_twobool_830_1);
  twobool(&S_twobool_856_1);
  twobool(&S_twobool_854_1);
  twobool(&S_twobool_857_1);
  twobool(&S_twobool_855_1);
  twobool(&S_twobool_1034_1);
  twobool(&S_twobool_1035_1);
  twobool(&S_twobool_1036_1);
  twobool(&S_twobool_1055_1);
  twobool(&S_twobool_56_1);
  twobool(&S_twobool_41_1);
  twobool(&S_twobool_226_1);
  twobool(&S_twobool_208_1);
  zpfs(&S_zpfs_616_1);
  zpfs(&S_zpfs_618_1);
  or2(&S_or2_924_1);
  or2(&S_or2_931_1);
  or2(&S_or2_938_1);
  or2(&S_or2_947_1);
  ampl(&S_ampl_374_1);
  rs(&S_rs_475_1);
  rs(&S_rs_474_1);
  rs(&S_rs_489_1);
  rs(&S_rs_488_1);
  twobool(&S_twobool_545_1);
  twobool(&S_twobool_529_1);
  twobool(&S_twobool_668_1);
  twobool(&S_twobool_669_1);
  twobool(&S_twobool_690_1);
  twobool(&S_twobool_691_1);
  twobool(&S_twobool_670_1);
  twobool(&S_twobool_671_1);
  twobool(&S_twobool_692_1);
  twobool(&S_twobool_693_1);
  twobool(&S_twobool_1014_1);
  twobool(&S_twobool_1015_1);
  twobool(&S_twobool_1016_1);
  twobool(&S_twobool_1017_1);
  twobool(&S_twobool_833_1);
  twobool(&S_twobool_834_1);
  noto(&S_noto_639_1);
  andn(&S_andn_88_1);
  andn(&S_andn_87_1);
  andn(&S_andn_47_1);
  andn(&S_andn_48_1);
  andn(&S_andn_121_1);
  andn(&S_andn_217_1);
  andn(&S_andn_218_1);
  andn(&S_andn_258_1);
  andn(&S_andn_257_1);
  andn(&S_andn_292_1);
  noto(&S_noto_925_1);
  andn(&S_andn_920_1);
  asmot(&S_asmot_620_1);
  asmot(&S_asmot_623_1);
  asmot(&S_asmot_479_1);
  asmot(&S_asmot_492_1);
  asmot(&S_asmot_480_1);
  noto(&S_noto_932_1);
  andn(&S_andn_928_1);
  noto(&S_noto_939_1);
  andn(&S_andn_936_1);
  noto(&S_noto_948_1);
  andn(&S_andn_943_1);
  lk(&S_lk_518_1);
  noto(&S_noto_922_1);
  andn(&S_andn_918_1);
  twobool(&S_twobool_1053_1);
  to3val(&S_to3val_517_1);
  toao(&S_toao_524_1);
  twobool(&S_twobool_1031_1);
  twobool(&S_twobool_1033_1);
  twobool(&S_twobool_1032_1);
  twobool(&S_twobool_1051_1);
  orrsim(&S_orrsim_60_1);
  orrsim(&S_orrsim_229_1);
  orrsim(&S_orrsim_96_1);
  orrsim(&S_orrsim_267_1);
  orrsim(&S_orrsim_130_1);
  orrsim(&S_orrsim_300_1);
  azbars(&S_azbars_182_1);
  bol(&S_bol_630_1);
  bol(&S_bol_636_1);
  bol(&S_bol_646_1);
  mod1(&S_mod1_652_1);
  fsubo(&S_fsubo_74_1);
  fsubo(&S_fsubo_244_1);
  fsubo(&S_fsubo_285_1);
  fsubo(&S_fsubo_115_1);
  orn(&S_orn_647_1);
  react(&S_react_200_1);
  orn(&S_orn_631_1);
  orn(&S_orn_634_1);
  twobool(&S_twobool_150_1);
  to3val(&S_to3val_156_1);
  toao(&S_toao_161_1);
  toao(&S_toao_162_1);
  toao(&S_toao_163_1);
  twobool(&S_twobool_430_1);
  twobool(&S_twobool_431_1);
  twobool(&S_twobool_432_1);
  to3val(&S_to3val_429_1);
  ktoenc(&S_ktoenc_434_1);
  twobool(&S_twobool_433_1);
  twobool(&S_twobool_337_1);
  twobool(&S_twobool_321_1);
  twobool(&S_twobool_350_1);
  to3val(&S_to3val_325_1);
  ktoenc(&S_ktoenc_329_1);
  twobool(&S_twobool_349_1);
  twobool(&S_twobool_351_1);
  to3val(&S_to3val_335_1);
  ktoenc(&S_ktoenc_336_1);
  twobool(&S_twobool_352_1);
  twobool(&S_twobool_322_1);
  twobool(&S_twobool_323_1);
  twobool(&S_twobool_338_1);
  twobool(&S_twobool_339_1);
  ampl(&S_ampl_657_1);
  twobool(&S_twobool_413_1);
  twobool(&S_twobool_414_1);
  twobool(&S_twobool_412_1);
  to3val(&S_to3val_415_1);
  ktoenc(&S_ktoenc_421_1);
  twobool(&S_twobool_967_1);
  twobool(&S_twobool_968_1);
  twobool(&S_twobool_971_1);
  to3val(&S_to3val_963_1);
  ktoenc(&S_ktoenc_970_1);
  to3val(&S_to3val_982_1);
  ktoenc(&S_ktoenc_987_1);
  twobool(&S_twobool_984_1);
  twobool(&S_twobool_985_1);
  twobool(&S_twobool_988_1);
  andn(&S_andn_357_1);
  twobool(&S_twobool_411_1);
  azbars(&S_azbars_14_1);
  vchs(&S_vchs_719_1);
  vchs(&S_vchs_729_1);
  vchs(&S_vchs_738_1);
  vchs(&S_vchs_747_1);
  vchs(&S_vchs_755_1);
  vchs(&S_vchs_764_1);
  vchs(&S_vchs_773_1);
  vchs(&S_vchs_781_1);
  vchs(&S_vchs_790_1);
  vchs(&S_vchs_799_1);
  vchs(&S_vchs_807_1);
  vchs(&S_vchs_816_1);
  twobool(&S_twobool_149_1);
  to3val(&S_to3val_158_1);
  toao(&S_toao_164_1);
  toao(&S_toao_165_1);
  toao(&S_toao_166_1);
  to3val(&S_to3val_658_1);
  vchs(&S_vchs_879_1);
  vchs(&S_vchs_887_1);
  vchs(&S_vchs_897_1);
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
 else {
      if (freebuff)
            return;
       else{
           freebuff = 1;
           memset(BUFFER, 0, SIZE_BUFFER);
           InitSetConst();
           initAllDriversPTI(drivers);
           ZeroVar();
           }
       }

}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<6;i++ )
    array_m182_C0_1[i] = &(&internal1_m182_C0)[i*5];
  for( i=0;i<6;i++ )
    array_m14_C0_1[i] = &(&internal1_m14_C0)[i*5];
}

#endif
