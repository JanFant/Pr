#ifndef RPU_H
#define RPU_H
// Подсистема RPU:RPU
static char SimulOn=0;
static short CodeSub=8;
static char SimulIP[]="192.168.1.17\0";
static int SimulPort=5555;
static int StepCycle=5;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 118
static char BUFFER[118];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.31\0", 5432, "192.168.10.131\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0IN01RRP	 BUFFER[0]	//(R0IN01RRP) Частота СНМ-11 Гц (канал 5)
#define idR0IN01RRP	 1	//(R0IN01RRP) Частота СНМ-11 Гц (канал 5)
#define R0IN02RRP	 BUFFER[5]	//(R0IN02RRP) Частота КНК15-1 Гц (канал 5)
#define idR0IN02RRP	 2	//(R0IN02RRP) Частота КНК15-1 Гц (канал 5)
#define R0IN03RRP	 BUFFER[10]	//(R0IN03RRP) Частота КНК53М Гц (канал 5)
#define idR0IN03RRP	 3	//(R0IN03RRP) Частота КНК53М Гц (канал 5)
#define rpu_VCHSK4	 BUFFER[15]	//(VCHSK4)
#define idrpu_VCHSK4	 4	//(VCHSK4)
#define R0IN06RRP	 BUFFER[20]	//(R0IN06RRP) Частота СНМ-11 Гц (канал 6)
#define idR0IN06RRP	 5	//(R0IN06RRP) Частота СНМ-11 Гц (канал 6)
#define R0IN07RRP	 BUFFER[25]	//(R0IN07RRP) Частота СНМ-11 Гц (канал 7)
#define idR0IN07RRP	 6	//(R0IN07RRP) Частота СНМ-11 Гц (канал 7)
#define R0IE14LRP	 BUFFER[30]	//(R0IE14LRP) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
#define idR0IE14LRP	 7	//(R0IE14LRP) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
#define R0IE15LRP	 BUFFER[32]	//(R0IE15LRP) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
#define idR0IE15LRP	 8	//(R0IE15LRP) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
#define R0IE11LRP	 BUFFER[34]	//(R0IE11LRP) Исправность ВИП 1,6 (№20) СНМ11 5 канала
#define idR0IE11LRP	 9	//(R0IE11LRP) Исправность ВИП 1,6 (№20) СНМ11 5 канала
#define R0IE12LRP	 BUFFER[36]	//(R0IE12LRP) Исправность ВИП 0,5 -5к (№21)
#define idR0IE12LRP	 10	//(R0IE12LRP) Исправность ВИП 0,5 -5к (№21)
#define R0IE13LRP	 BUFFER[38]	//(R0IE13LRP) Исправность ВИП 0,5 -5к (№22)
#define idR0IE13LRP	 11	//(R0IE13LRP) Исправность ВИП 0,5 -5к (№22)
#define C1MD31LRP	 BUFFER[40]	//(C1MD31LRP) Кнопка ОБЩИЙ СБРОС  на РПУ
#define idC1MD31LRP	 12	//(C1MD31LRP) Кнопка ОБЩИЙ СБРОС  на РПУ
#define C1MZ31LRP	 BUFFER[42]	//(C1MZ31LRP) Кнопка ОБДУВ  на РПУ
#define idC1MZ31LRP	 13	//(C1MZ31LRP) Кнопка ОБДУВ  на РПУ
#define A3IS21LRP	 BUFFER[44]	//(A3IS21LRP) Приход на НУ ИС1
#define idA3IS21LRP	 14	//(A3IS21LRP) Приход на НУ ИС1
#define B3IS21LRP	 BUFFER[46]	//(B3IS21LRP) Приход на НУ ИС2
#define idB3IS21LRP	 15	//(B3IS21LRP) Приход на НУ ИС2
#define A1IS21LRP	 BUFFER[48]	//(A1IS21LRP) Приход на НУ ББ1
#define idA1IS21LRP	 16	//(A1IS21LRP) Приход на НУ ББ1
#define B1IS21LRP	 BUFFER[50]	//(B1IS21LRP) Приход на НУ ББ2
#define idB1IS21LRP	 17	//(B1IS21LRP) Приход на НУ ББ2
#define A2IS21LRP	 BUFFER[52]	//(A2IS21LRP) Приход на НУ РБ1-CC
#define idA2IS21LRP	 18	//(A2IS21LRP) Приход на НУ РБ1-CC
#define B2IS21LRP	 BUFFER[54]	//(B2IS21LRP) Приход на НУ РБ2-CC
#define idB2IS21LRP	 19	//(B2IS21LRP) Приход на НУ РБ2-CC
#define A6IS11LRP	 BUFFER[56]	//(A6IS11LRP) Приход на ВУ БЗ1
#define idA6IS11LRP	 20	//(A6IS11LRP) Приход на ВУ БЗ1
#define B6IS11LRP	 BUFFER[58]	//(B6IS11LRP) Приход на ВУ БЗ2
#define idB6IS11LRP	 21	//(B6IS11LRP) Приход на ВУ БЗ2
#define A0IT03IRP	 BUFFER[60]	//(A0IT03IRP) Температура АЗ1-3
#define idA0IT03IRP	 22	//(A0IT03IRP) Температура АЗ1-3
#define B0IT03IRP	 BUFFER[63]	//(B0IT03IRP) Температура АЗ2-3
#define idB0IT03IRP	 23	//(B0IT03IRP) Температура АЗ2-3
#define A1VS21LRP	 BUFFER[66]	//(A1VS21LRP) Индикация НУ ББ1
#define idA1VS21LRP	 24	//(A1VS21LRP) Индикация НУ ББ1
#define B1VS21LRP	 BUFFER[68]	//(B1VS21LRP) Индикация НУ ББ2
#define idB1VS21LRP	 25	//(B1VS21LRP) Индикация НУ ББ2
#define A2VS21LRP	 BUFFER[70]	//(A2VS21LRP) Индикация НУ РБ1-СС
#define idA2VS21LRP	 26	//(A2VS21LRP) Индикация НУ РБ1-СС
#define B2VS21LRP	 BUFFER[72]	//(B2VS21LRP) Индикация НУ РБ2-СС
#define idB2VS21LRP	 27	//(B2VS21LRP) Индикация НУ РБ2-СС
#define A3VS21LRP	 BUFFER[74]	//(A3VS21LRP) Индикация НУ ИС1
#define idA3VS21LRP	 28	//(A3VS21LRP) Индикация НУ ИС1
#define B3VS21LRP	 BUFFER[76]	//(B3VS21LRP) Индикация НУ ИС2
#define idB3VS21LRP	 29	//(B3VS21LRP) Индикация НУ ИС2
#define R0IE02LRP	 BUFFER[78]	//(R0IE02LRP) Отключить питание ПУ, ПР 5К
#define idR0IE02LRP	 30	//(R0IE02LRP) Отключить питание ПУ, ПР 5К
#define R0IE01LRP	 BUFFER[80]	//(R0IE01LRP) Отключить питание детекторов 5К
#define idR0IE01LRP	 31	//(R0IE01LRP) Отключить питание детекторов 5К
#define R0IE03LRP	 BUFFER[82]	//(R0IE03LRP) Отключить питание детекторов 6К (БЗ-1), 7 К (БЗ-2)
#define idR0IE03LRP	 32	//(R0IE03LRP) Отключить питание детекторов 6К (БЗ-1), 7 К (БЗ-2)
#define R0IE04LRP	 BUFFER[84]	//(R0IE04LRP) Отключить питание ПУ, ПР 6К (БЗ-1), 7 К (БЗ-2)
#define idR0IE04LRP	 33	//(R0IE04LRP) Отключить питание ПУ, ПР 6К (БЗ-1), 7 К (БЗ-2)
#define A1VT71LRP	 BUFFER[86]	//(A1VT71LRP) Подсветка кнопки «СБРОС» (Светодиод) 
#define idA1VT71LRP	 34	//(A1VT71LRP) Подсветка кнопки «СБРОС» (Светодиод) 
#define R0VN71LRP	 BUFFER[88]	//(R0VN71LRP) Подсветка кнопки «ОБДУВ» (Светодиод)
#define idR0VN71LRP	 35	//(R0VN71LRP) Подсветка кнопки «ОБДУВ» (Светодиод)
#define A1VN71LRP	 BUFFER[90]	//(A1VN71LRP) Сигнал тревоги на диспетчера
#define idA1VN71LRP	 36	//(A1VN71LRP) Сигнал тревоги на диспетчера
#define POWER1	 BUFFER[92]	//(POWER1 )
#define idPOWER1	 37	//(POWER1 )
#define POWER2	 BUFFER[94]	//(POWER2 )
#define idPOWER2	 38	//(POWER2 )
#define DOOR	 BUFFER[96]	//(DOOR   )
#define idDOOR	 39	//(DOOR   )
#define T43	 BUFFER[98]	//(T43    )
#define idT43	 40	//(T43    )
#define T53	 BUFFER[100]	//(T53    )
#define idT53	 41	//(T53    )
#define BP124	 BUFFER[102]	//(BP124  )
#define idBP124	 42	//(BP124  )
#define BP15	 BUFFER[104]	//(BP15   )
#define idBP15	 43	//(BP15   )
#define BP224	 BUFFER[106]	//(BP224  )
#define idBP224	 44	//(BP224  )
#define BP25	 BUFFER[108]	//(BP25   )
#define idBP25	 45	//(BP25   )
#define MPBP124	 BUFFER[110]	//(MPBP124)
#define idMPBP124	 46	//(MPBP124)
#define MPBP15	 BUFFER[112]	//(MPBP15 )
#define idMPBP15	 47	//(MPBP15 )
#define MPBP224	 BUFFER[114]	//(MPBP224)
#define idMPBP224	 48	//(MPBP224)
#define MPBP25	 BUFFER[116]	//(MPBP25 )
#define idMPBP25	 49	//(MPBP25 )
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,8	,1	, &R0IN01RRP},	//(R0IN01RRP) Частота СНМ-11 Гц (канал 5)
	{ 2	,8	,1	, &R0IN02RRP},	//(R0IN02RRP) Частота КНК15-1 Гц (канал 5)
	{ 3	,8	,1	, &R0IN03RRP},	//(R0IN03RRP) Частота КНК53М Гц (канал 5)
	{ 4	,8	,1	, &rpu_VCHSK4},	//(VCHSK4)
	{ 5	,8	,1	, &R0IN06RRP},	//(R0IN06RRP) Частота СНМ-11 Гц (канал 6)
	{ 6	,8	,1	, &R0IN07RRP},	//(R0IN07RRP) Частота СНМ-11 Гц (канал 7)
	{ 7	,1	,1	, &R0IE14LRP},	//(R0IE14LRP) Исправность ВИП 1,6 БЗ-1 - 6к(№23)
	{ 8	,1	,1	, &R0IE15LRP},	//(R0IE15LRP) Исправность ВИП 1,6 БЗ-2 - 7к(№24)
	{ 9	,1	,1	, &R0IE11LRP},	//(R0IE11LRP) Исправность ВИП 1,6 (№20) СНМ11 5 канала
	{ 10	,1	,1	, &R0IE12LRP},	//(R0IE12LRP) Исправность ВИП 0,5 -5к (№21)
	{ 11	,1	,1	, &R0IE13LRP},	//(R0IE13LRP) Исправность ВИП 0,5 -5к (№22)
	{ 12	,1	,1	, &C1MD31LRP},	//(C1MD31LRP) Кнопка ОБЩИЙ СБРОС  на РПУ
	{ 13	,1	,1	, &C1MZ31LRP},	//(C1MZ31LRP) Кнопка ОБДУВ  на РПУ
	{ 14	,1	,1	, &A3IS21LRP},	//(A3IS21LRP) Приход на НУ ИС1
	{ 15	,1	,1	, &B3IS21LRP},	//(B3IS21LRP) Приход на НУ ИС2
	{ 16	,1	,1	, &A1IS21LRP},	//(A1IS21LRP) Приход на НУ ББ1
	{ 17	,1	,1	, &B1IS21LRP},	//(B1IS21LRP) Приход на НУ ББ2
	{ 18	,1	,1	, &A2IS21LRP},	//(A2IS21LRP) Приход на НУ РБ1-CC
	{ 19	,1	,1	, &B2IS21LRP},	//(B2IS21LRP) Приход на НУ РБ2-CC
	{ 20	,1	,1	, &A6IS11LRP},	//(A6IS11LRP) Приход на ВУ БЗ1
	{ 21	,1	,1	, &B6IS11LRP},	//(B6IS11LRP) Приход на ВУ БЗ2
	{ 22	,3	,1	, &A0IT03IRP},	//(A0IT03IRP) Температура АЗ1-3
	{ 23	,3	,1	, &B0IT03IRP},	//(B0IT03IRP) Температура АЗ2-3
	{ 24	,1	,1	, &A1VS21LRP},	//(A1VS21LRP) Индикация НУ ББ1
	{ 25	,1	,1	, &B1VS21LRP},	//(B1VS21LRP) Индикация НУ ББ2
	{ 26	,1	,1	, &A2VS21LRP},	//(A2VS21LRP) Индикация НУ РБ1-СС
	{ 27	,1	,1	, &B2VS21LRP},	//(B2VS21LRP) Индикация НУ РБ2-СС
	{ 28	,1	,1	, &A3VS21LRP},	//(A3VS21LRP) Индикация НУ ИС1
	{ 29	,1	,1	, &B3VS21LRP},	//(B3VS21LRP) Индикация НУ ИС2
	{ 30	,1	,1	, &R0IE02LRP},	//(R0IE02LRP) Отключить питание ПУ, ПР 5К
	{ 31	,1	,1	, &R0IE01LRP},	//(R0IE01LRP) Отключить питание детекторов 5К
	{ 32	,1	,1	, &R0IE03LRP},	//(R0IE03LRP) Отключить питание детекторов 6К (БЗ-1), 7 К (БЗ-2)
	{ 33	,1	,1	, &R0IE04LRP},	//(R0IE04LRP) Отключить питание ПУ, ПР 6К (БЗ-1), 7 К (БЗ-2)
	{ 34	,1	,1	, &A1VT71LRP},	//(A1VT71LRP) Подсветка кнопки «СБРОС» (Светодиод) 
	{ 35	,1	,1	, &R0VN71LRP},	//(R0VN71LRP) Подсветка кнопки «ОБДУВ» (Светодиод)
	{ 36	,1	,1	, &A1VN71LRP},	//(A1VN71LRP) Сигнал тревоги на диспетчера
	{ 37	,1	,1	, &POWER1},	//(POWER1 )
	{ 38	,1	,1	, &POWER2},	//(POWER2 )
	{ 39	,1	,1	, &DOOR},	//(DOOR   )
	{ 40	,1	,1	, &T43},	//(T43    )
	{ 41	,1	,1	, &T53},	//(T53    )
	{ 42	,1	,1	, &BP124},	//(BP124  )
	{ 43	,1	,1	, &BP15},	//(BP15   )
	{ 44	,1	,1	, &BP224},	//(BP224  )
	{ 45	,1	,1	, &BP25},	//(BP25   )
	{ 46	,1	,1	, &MPBP124},	//(MPBP124)
	{ 47	,1	,1	, &MPBP15},	//(MPBP15 )
	{ 48	,1	,1	, &MPBP224},	//(MPBP224)
	{ 49	,1	,1	, &MPBP25},	//(MPBP25 )
	{-1,0,NULL},
};
static char NameSaveFile[]="RPU.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_RPU[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_RPU[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_RPU[]={  // 
	{&R0IN01RRP,8,0},	//(R0IN01RRP) R0IN01RRP
	{&R0IN02RRP,8,2},	//(R0IN02RRP) R0IN02RRP
	{&R0IN03RRP,8,4},	//(R0IN03RRP) R0IN03RRP
	{&rpu_VCHSK4,8,6},	//(rpu_VCHSK4) rpu_VCHSK4
	{&R0IN06RRP,8,8},	//(R0IN06RRP) R0IN06RRP
	{&R0IN07RRP,8,10},	//(R0IN07RRP) R0IN07RRP
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_RPU[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,502,&coil_RPU[0],&di_RPU[0],&ir_RPU[0],&hr_RPU[0],NULL,NULL,NULL,0},	 //Пустые сигналы RPU

	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS01[670];	//VCHS01
static vchs_inipar ini_VCHS01={172,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,};
#pragma pack(push,1)
static table_drv table_VCHS01={0,0,&ini_VCHS01,buf_VCHS01,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS01[]={
	{&R0IN01RRP,8,0},
	{&R0IN02RRP,8,5},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS02[670];	//VCHS02
static vchs_inipar ini_VCHS02={172,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,};
#pragma pack(push,1)
static table_drv table_VCHS02={0,0,&ini_VCHS02,buf_VCHS02,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS02[]={
	{&R0IN03RRP,8,0},
	{&rpu_VCHSK4,8,5},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS03[670];	//VCHS03
static vchs_inipar ini_VCHS03={172,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,};
#pragma pack(push,1)
static table_drv table_VCHS03={0,0,&ini_VCHS03,buf_VCHS03,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS03[]={
	{&R0IN06RRP,8,0},
	{&R0IN07RRP,8,5},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vas84r.h>
static char buf_VAS84[26];	//VAS84
static vas84r_inipar ini_VAS84={172,255,1,8,0xff,0,16,};
#pragma pack(push,1)
static table_drv table_VAS84={0,0,&ini_VAS84,buf_VAS84,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VAS84[]={
	{&A0IT03IRP,3,0},
	{&B0IT03IRP,3,3},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS32[64];	//VDS32
static vds32r_inipar ini_VDS32={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS32={0,0,&ini_VDS32,buf_VDS32,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32[]={
	{&R0IE14LRP,1,0},
	{&R0IE15LRP,1,2},
	{&R0IE11LRP,1,4},
	{&R0IE12LRP,1,6},
	{&R0IE13LRP,1,8},
	{&C1MD31LRP,1,10},
	{&C1MZ31LRP,1,12},
	{&A3IS21LRP,1,14},
	{&B3IS21LRP,1,16},
	{&A1IS21LRP,1,18},
	{&B1IS21LRP,1,20},
	{&A2IS21LRP,1,22},
	{&B2IS21LRP,1,24},
	{&A6IS11LRP,1,26},
	{&B6IS11LRP,1,28},
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
	{&A1VS21LRP,1,0},
	{&B1VS21LRP,1,2},
	{&A2VS21LRP,1,4},
	{&B2VS21LRP,1,6},
	{&A3VS21LRP,1,8},
	{&B3VS21LRP,1,10},
	{&R0IE02LRP,1,12},
	{&R0IE01LRP,1,14},
	{&R0IE03LRP,1,16},
	{&R0IE04LRP,1,18},
	{&A1VT71LRP,1,20},
	{&R0VN71LRP,1,22},
	{&A1VN71LRP,1,28},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/sbkfp7.h>
static char buf_SBKFP[26];	//SBKFP
static sbk_inipar ini_SBKFP={0xc2,0xff,8,8,};
#pragma pack(push,1)
static table_drv table_SBKFP={0,0,&ini_SBKFP,buf_SBKFP,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_SBKFP[]={
	{&POWER1,1,0},
	{&POWER2,1,2},
	{&DOOR,1,4},
	{&T43,1,6},
	{&T53,1,8},
	{&BP124,1,10},
	{&BP15,1,12},
	{&BP224,1,14},
	{&BP25,1,16},
	{&MPBP124,1,18},
	{&MPBP15,1,20},
	{&MPBP224,1,22},
	{&MPBP25,1,24},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0xc4,0x01,12,670,def_buf_VCHS01,&table_VCHS01}, //VCHS01
	{0xc4,0x02,12,670,def_buf_VCHS02,&table_VCHS02}, //VCHS02
	{0xc4,0x03,12,670,def_buf_VCHS03,&table_VCHS03}, //VCHS03
	{0xc6,0x06,7,26,def_buf_VAS84,&table_VAS84}, //VAS84
	{0xc2,0x07,15,64,def_buf_VDS32,&table_VDS32}, //VDS32
	{0x04,0x08,20,38,def_buf_FDS16,&table_FDS16}, //FDS16
	{0x01,0x20,4,26,def_buf_SBKFP,&table_SBKFP}, //SBKFP
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
}

// Р’СЃС‚Р°РІРєР° Рє VCHS
void init_dataVchs(vchs_data *vch_data) {
    int i;
    for (i = 0; i < 2; i++) {
        vch_data->takt[i] = 0.5;
        vch_data->cykl[i] = 0.5;
        vch_data->cyklS[i] = 0.5;
        vch_data->perm[i] = 0;
        vch_data->fvch[i] = 0;
        vch_data->tempI[i] = 0;
    }
}

void VCHS_post(vchs_data *vch_data) {
    float fslow = 0, ffast = 0, zer = 0.0;
    int i;
    for (i = 0; i < 2; i++) {
        if (vch_data->perm[i] <= 0) {
                if(vch_data->SVCHS[i] == 1){
                    if( vch_data->cyklS[i] == 10)
                        vch_data->cyklS[i] = 1.0;
                    else
                        vch_data->cyklS[i] = 0.01;
                    vch_data->SVCHS[i] = 0;
                    vch_data->takt[i] = 0;                    
                    vch_data->cykl[i] = vch_data->cyklS[i]; 
                    continue;
                }    
                ffast = vch_data->tempI[i] / vch_data->takt[i];
                vch_data->fvch[i] = ffast;
                vch_data->takt[i] = 0;
                if(ffast < 1.0 )
                    vch_data->cyklS[i] = 10;
                    else   
                    vch_data->cyklS[i] = 1 / ((ffast / 64000) + 1);

                vch_data->cykl[i] = vch_data->cyklS[i]; 
        }
    }
    for (i = 0; i < 2; i++)
        if (fpcomp(&vch_data->cykl[i], &zer) > 0) {
            vch_data->takt[i] += takt;
            vch_data->cykl[i] -= takt;
            vch_data->perm[i] = fpcomp(&vch_data->cykl[i], &zer);
        }
    vch_data->K01VCHS.f = vch_data->fvch[0];
    vch_data->K02VCHS.f = vch_data->fvch[1];

}

void Scheme(void)
{
}
#endif
